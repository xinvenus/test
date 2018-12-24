#include <vector>

vector<int> oldsc1;
vector<int> oldsc2;
vector<int> oldsc3;
vector<int> oldsc4;

vector<int> newsc1;
vector<int> newsc2;
vector<int> newsc3;
vector<int> newsc4;

#defind MAX_GROUP 1024

typedef struct
{
	int dwGroupId;
	int dwCommId;
} T_Group;

T_Group tGroup[MAX_GROUP];

void findRepeatOld()
{
	for(int i = 0; i < MAX_GROUP; i++)
	{
		if(tGroup[i].dwCommId == 88880001)
		{
			oldsc1.push_back(i);
			continue;
		}
		
		if(tGroup[i].dwCommId == 88880002)
		{
			oldsc2.push_back(i);
			continue;
		}
		
		if(tGroup[i].dwCommId == 88880003)
		{
			oldsc3.push_back(i);
			continue;
		}
		
		if(tGroup[i].dwCommId == 88880004)
		{
			oldsc4.push_back(i);
			continue;
		}		
	}
}

void findRepeatNew()
{
	for(int i = 0; i < MAX_GROUP; i++)
	{
		if(tGroup[i].dwCommId == 88880001)
		{
			newsc1.push_back(i);
			continue;
		}
		
		if(tGroup[i].dwCommId == 88880002)
		{
			newsc2.push_back(i);
			continue;
		}
		
		if(tGroup[i].dwCommId == 88880003)
		{
			newsc3.push_back(i);
			continue;
		}
		
		if(tGroup[i].dwCommId == 88880004)
		{
			newsc4.push_back(i);
			continue;
		}		
	}
}

