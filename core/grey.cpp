#include <vector>

#define DOMAIN_LEN 8
typedef struct
{
	int dwCommID;
	char domain[DOMAIN_LEN];
} T_R_SC;


typedef struct
{
	int dwCommID;
	char domain[DOMAIN_LEN];
} T_GREY_INFO;

vector<T_R_SC> r_sc; 
vector<T_R_SC> r_sc_a; 
vector<T_R_SC> r_sc_b; 

/** 群信息 **/
typedef struct
{
	int dwGroupID;
	int dwDstCommID;
} T_R_GROUP;

vector<T_R_GROUP> r_group; 
vector<i> r_group_cur; 


/** SC MAP **/
typedef struct
{
	int dwCommID;
	int CurNum;
	int ExpNum;
} T_SC_MAP;

vector<T_SC_MAP> r_ScMap;

int main()
{
	char domain_A[DOMAIN_LEN] = "A";
	char domain_B[DOMAIN_LEN] = "B";
	T_GREY_INFO tGreyInfo;
	memset(&tGreyInfo, 0, sizeof(tGreyInfo));
	
	/** the sc info for grey update **/
	tGreyInfo.dwCommID = 3;
	strcpy(tGreyInfo.domain, "B");
	
	/** find the group on the grey sc 当前要灰度的SC上的群个数 **/
	for(int i = 0; i < r_group.size(); i++)
	{
		if(r_group[i].dwDstCommID == tGreyInfo.dwDstCommID)
		{
			r_group_cur.push_back(i); /** 记录下来群号 **/
		}
	}
	
	
	/** find the old domain sc **/
	for(int i = 0; i < r_sc.size(); i++)
	{
		if(memcmp(r_sc[i].domain, tGreyInfo.domain, DOMAIN_LEN) != 0)
		{
			r_sc_a.push_back(r_sc[i]);
		}
	}	
	
	/* 新域SC数目为0，则在老域内均分 */
    if(dwNewScNum == 0)
	{
		AllocatInOldSC();
	}
	else  /** 新域内均分 **/
	{
		AllocatInNewSC();
	}
#if 0	
	/** 将找出来的群均分到SC实例上 **/
	int dwr_sc_aNum  = r_sc_a.size();
	int dwr_group_curNum  = r_group_cur.size();
	int dwAvGroup = dwr_group_curNum/dwr_sc_aNum;
	
	/** todo:每个SC上原来有的群数，要考虑进去 **/
	T_SC_MAP tSCMap;
	for(int i = 0; i < r_sc_a.size(); i++)
	{
		memset(&tSCMap, 0, sizeof(tSCMap));
		tSCMap.dwCommID = r_sc_a[i].dwCommID;
		tSCMap.ExpNum   = dwAvGroup;
		r_ScMap.push_back(tSCMap); 
	}	
	
	/** 根据期望值和目前SC上的群数进行均衡 **/
#endif		
	
	
	

	/** find the new domain sc **/
	for(int i = 0; i < r_sc.size(); i++)
	{
		if(memcmp(r_sc[i].domain, tGreyInfo.domain, DOMAIN_LEN) == 0)
		{
			r_sc_b.push_back(r_sc[i]);
		}
	}
	
}

/***************************老域的处理************************************************/

void AllocatInOldSC()
{
	UsergroupOfOldScToScMap();
	
	/* 老域在线SC信息插入SCMAP */
	for(idx = 0; idx < oldScNum && idx < MAX_SC_NUM; idx++)
	{
		dwCommId = OldSCTable[idx].dwCommId;
		dwLogicNo = OldSCTable[idx].dwLogicNo;
		GetMapPosByCommId();
	}
	
	if(dwSCMapUsedNum > (oldScNum + 1))
	{
		/** 清除老域中离线的SC，包括清除当前正在灰度升级的SC **/
		ClearOffLineOldSC();
	}
	
	/* 降序排列 和 计算期望值 */
	/* 当前值大于期望值，则迁出 */
	/* 执行迁移操作 */
	
}

/* 老域SC的群插入SCMAP（包括老域的和当前正在灰度的SC）*/
void UsergroupOfOldScToScMap()
{
	for(idx = 0; idx < Policy.dwUsergroupNum && idx < MAX_USRGROUP_NUM; idx++)
	{
		dwCommId = UserTuple[idx].dwCommIDDst;
		
		/* 获取R_SC by commid *//* todo:新老域的标志位保存到群表中 */
		
		/* 新域的群不用插入SC MAP*/
		if(ptR_SC->domain == newDomain)
		{
			continue;
		}

		dwlogicNo = UserTuple[idx].dwlogicNoDst;
		
		/* 其余同原来 */
		/* 记录当前SC和SC实例有多少群 */
	}
}

void ClearOffLineOldSC()
{
	WORD32 i = 1;
	dwMaxSC = dwUserGroupSCMapUsedNum; /* SC MAP表的最大记录数 */
	
	/* 依次取出老域SC的记录*/
	while(i < dwMaxSC && i < MAX_SC_NUM)
	{
		dwCommID = UserGroupMapSc[i].dwCommID;
		
		for(j = 0; j < OldSCNum; j++)
		{
			if(dwCommID == OldSCTable[j].dwCommID)
			{
				break;
			}
		}
		
		if(j > OldSCNum)
		{
			/* 交换位置 */
		}
		else
		{
			i++;
		}
	}	
}



/***************************新域的处理************************************************/
void AllocatInNewSC()
{
	UsergroupOfNewAndGreyScToScMap();
	
	/* 新域在线SC信息插入SCMAP---不包括正在灰度的SC */
	for(idx = 0; idx < NewScNum && idx < MAX_SC_NUM; idx++)
	{
		dwCommId = NewSCTable[idx].dwCommId;
		dwLogicNo = NewSCTable[idx].dwLogicNo;
		GetMapPosByCommId();
	}
	
	if(dwSCMapUsedNum > (NewScNum + 1))
	{
		/** 清除老域中离线的SC，包括清除当前正在灰度升级的SC **/
		ClearOffLineNewSC();
	}
}


void ClearOffLineNewSC() /* todo:待与另外一个函数一起封装 */
{
	WORD32 i = 1;
	dwMaxSC = dwUserGroupSCMapUsedNum; /* SC MAP表的最大记录数 */
	
	/* 依次取出老域SC的记录*/
	while(i < dwMaxSC && i < MAX_SC_NUM)
	{
		dwCommID = UserGroupMapSc[i].dwCommID;
		
		for(j = 0; j < NewSCNum; j++)
		{
			if(dwCommID == NewSCTable[j].dwCommID)
			{
				break;
			}
		}
		
		if(j > OldSCNum)
		{
			/* 交换位置 */
		}
		else
		{
			i++;
		}
	}	
}




/* 新域SC的群插入SCMAP（包括新域的和当前正在灰度的SC）*/
void UsergroupOfNewAndGreyScToScMap()
{
	for(idx = 0; idx < Policy.dwUsergroupNum && idx < MAX_USRGROUP_NUM; idx++)
	{
		dwCommId = UserTuple[idx].dwCommIDDst;
		
		/* 获取R_SC by commid */ /* todo:新老域的标志位保存到群表中 */
		
		/* 老域并且不是当前灰度升级的SC的群不用插入SC MAP*/
		if(ptR_SC->domain == oldDomain) && (ptR_SC->RA != GREY)
		{
			continue;
		}

		dwlogicNo = UserTuple[idx].dwlogicNoDst;
		
		/* 其余同原来 */
		/* 记录当前SC和SC实例有多少群 */
	}
}



















