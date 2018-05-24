#include "map.h"

int map[25][17][17]=
{{},
	{                                       //第一层地图
  {7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7},
  {7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7},
  {7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7},
  {7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7},
  {7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7},
  {7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7},
  {7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {100,1,1,1,1,1,104,1,1,1,1,1,1,1,1,1,8},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7},
  {7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7},
  {7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7},
  {7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7},
  {7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7},
  {7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7},
  {7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7}
	},
	{                                       //第二层地图
		{211,302,207,301,200,300,0  ,1  ,1  ,1  ,0  ,1  ,1  ,1  ,1  ,1  ,201},
		{302,208,301,200,300,1  ,0  ,1  ,1  ,1  ,0  ,322,1  ,1  ,1  ,211,200},
		{207,301,201,300,1  ,1  ,0  ,1  ,1  ,1  ,0  ,321,322,1  ,1  ,1  ,1  },
		{301,201,300,1  ,1  ,1  ,0  ,1  ,1  ,1  ,2  ,320,321,322,1  ,1  ,202},
		{1  ,300,1  ,1  ,1  ,1  ,0  ,1  ,1  ,1  ,0  ,321,322,1  ,1  ,1  ,1  },
		{300,1  ,1  ,1  ,1  ,1  ,0  ,1  ,1  ,1  ,0  ,322,1  ,1  ,1  ,1  ,1  },
		{0  ,0  ,0  ,3  ,0  ,0  ,0  ,1  ,1  ,1  ,0  ,0  ,0  ,0  ,0  ,0  ,0  },
		{1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  },
		{8  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,209,1  ,1  ,1  ,1  ,1  ,1  ,1  ,9  }, 
		{1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  },
		{0  ,0  ,0  ,3  ,0  ,0  ,0  ,1  ,1  ,1  ,0  ,0  ,0  ,0  ,0  ,0  ,0  },
		{300,1  ,1  ,1  ,1  ,1  ,0  ,1  ,1  ,1  ,0  ,312,1  ,1  ,1  ,1  ,203},
		{301,300,1  ,1  ,1  ,1  ,0  ,1  ,1  ,1  ,0  ,311,312,1  ,1  ,1  ,204},
		{1  ,301,300,1  ,1  ,1  ,0  ,1  ,1  ,1  ,2  ,310,311,312,1  ,205,203},
		{210,1  ,301,300,1  ,1  ,0  ,11 ,1  ,1  ,0  ,311,312,1  ,1  ,205,204},
		{204,204,1  ,301,300,1  ,0  ,-1 ,1  ,1  ,0,  312,1  ,1  ,1  ,205,203},
		{205,203,203,1  ,301,1  ,0  ,-1 ,1  ,1  ,0  ,1  ,1  ,1  ,1  ,211,204},
	},
	{ 		                                     //第三层地图
		{9  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,8  },
		{0  ,0  ,0  ,2  ,0  ,0  ,0  ,1  ,1  ,1  ,7  ,7  ,7  ,5  ,7  ,7  ,7  },
		{1  ,1  ,1  ,320,1  ,1  ,0  ,1  ,1  ,1  ,7  ,7  ,7  ,1  ,7  ,7  ,7  },
		{1  ,1  ,1  ,200,1  ,1  ,0  ,1  ,1  ,1  ,7  ,7  ,7  ,1  ,7  ,7  ,7  },
		{321,1  ,1  ,1  ,1  ,320,0  ,1  ,1  ,1  ,7  ,7  ,7  ,1  ,7  ,7  ,7  },
		{203,321,1  ,1  ,320,201,0  ,1  ,1  ,1  ,7  ,7  ,7  ,1  ,7  ,7  ,7  },
		{0  ,0  ,0  ,2  ,0  ,0  ,0  ,300,300,300,7  ,7  ,7  ,1  ,7  ,7  ,7  },
		{208,1  ,321,320,321,1  ,0  ,301,301,301,7  ,7  ,7  ,1  ,7  ,7  ,7  },
		{200,1  ,321,320,321,1  ,0  ,1  ,1  ,1  ,7  ,7  ,7  ,1  ,7  ,7  ,7  },
		{200,1  ,321,320,321,1  ,0  ,1  ,1  ,1,  7,  7  ,7  ,1  ,7  ,7  ,7  },
		{211,1  ,1  ,321,1  ,1  ,0  ,1  ,1  ,1  ,7  ,7  ,7  ,1  ,7  ,7  ,7  },
		{0  ,0  ,0  ,0  ,0  ,0  ,0  ,1  ,1  ,1  ,7  ,7  ,7  ,1  ,7  ,7  ,7  },
		{1  ,1  ,1  ,1  ,1  ,1  ,0  ,1  ,1  ,1  ,7  ,7  ,7  ,1  ,7  ,7  ,7  },
		{200,1  ,1  ,1  ,300,300,0  ,1  ,1  ,1  ,7  ,7  ,7  ,1  ,7  ,7  ,7  },
		{200,1  ,1  ,1  ,300,302,3  ,302,200,10 ,7  ,7  ,7  ,1  ,7  ,7  ,7  },
		{200,1  ,205,1  ,300,300,0  ,1  ,201,-1 ,7  ,7  ,7  ,403,7  ,7  ,7  },
		{203,204,1  ,1  ,1  ,1  ,0  ,1  ,1  ,-1 ,7  ,7  ,7  ,106,7  ,7  ,7  },
	},
	{                                          //第四层地图
		{205,1  ,1  ,1  ,1  ,1  ,332,330,331,330,1  ,1  ,1  ,1  ,1  ,331,203},
		{204,7  ,7  ,7  ,7  ,7  ,7  ,7  ,330,7  ,7  ,7  ,7  ,7  ,7  ,7  ,331},
		{204,7  ,7  ,7  ,7  ,7  ,7  ,7  ,330,7  ,7  ,7  ,7  ,7  ,7  ,7  ,1  },
		{1  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,1  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,1  },
		{1  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,1  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,207},
		{1  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,1  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,1  },
		{1  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,1  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,1  },
		{1  ,7  ,7  ,7  ,7  ,7  ,7  ,1  ,1  ,1  ,7  ,7  ,7  ,7  ,7  ,7  ,330},
		{1  ,2  ,3  ,1  ,1  ,1  ,1  ,1  ,9  ,1  ,1  ,1  ,1  ,1  ,1  ,330,332},
		{1  ,7  ,7  ,7  ,7  ,7  ,7  ,1  ,1  ,1  ,7  ,7  ,7  ,7  ,7  ,7  ,330},
		{1  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,1  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,1  },
		{1  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,1  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,1  },
		{1  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,1  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,1  },
		{1  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,1  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,208},
		{203,7  ,7  ,7  ,7  ,7  ,7  ,7  ,330,7  ,7  ,7  ,7  ,7  ,7  ,7  ,207},
		{206,7  ,7  ,7  ,7  ,7  ,7  ,7  ,331,7  ,7  ,7  ,7  ,7  ,7  ,7  ,1  },
		{206,1  ,1  ,1  ,1  ,1  ,1  ,332,331,331,1  ,1  ,207,1  ,1  ,1  ,8  },
	},
	{                                         //第五层地图
		{9  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,340,340,1  ,1  ,1  ,1  ,1  ,1  ,8  },
		{1  ,1  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,2  ,0  ,0  ,0  ,0  ,0  ,0  ,0  },
		{1  ,0  ,1  ,206,206,1  ,1  ,1  ,0  ,1  ,0  ,1  ,1  ,1  ,1  ,1  ,1  },
		{1  ,0  ,1  ,205,203,1  ,1  ,1  ,0  ,1  ,0  ,205,205,1  ,1  ,1  ,1  },
		{1  ,0  ,1  ,1  ,1  ,1  ,1  ,1  ,0  ,1  ,0  ,1  ,1  ,1  ,1  ,1  ,1  },
		{1  ,0  ,1  ,1  ,1  ,1  ,1  ,1  ,0  ,1  ,0  ,1  ,1  ,1  ,1  ,1  ,1  },
		{1  ,0  ,1  ,1  ,341,1  ,1  ,1  ,0  ,1  ,0  ,1  ,1  ,342,1  ,1  ,1  },
		{1  ,0  ,1  ,341,340,341,1  ,1  ,0  ,1  ,0  ,1  ,342,340,342,1  ,1  },
		{1  ,0  ,0  ,0  ,2  ,0  ,0  ,0  ,0  ,1  ,0  ,0  ,0  ,2  ,0  ,0  ,0  },
		{1  ,0  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,340,1  ,1  ,1  ,1  ,1  ,1  ,1  },
		{1  ,0  ,0  ,0  ,2  ,0  ,0  ,0  ,0  ,1  ,0  ,0  ,0  ,2  ,0  ,0  ,0  },
		{1  ,0  ,1  ,341,340,341,1  ,1  ,0  ,1  ,0  ,341,340,341,1  ,1  ,1  },
		{370,0  ,1  ,1  ,341,1  ,1  ,1  ,0  ,1  ,0  ,1  ,1  ,1  ,341,1  ,1  },
		{341,0  ,1  ,1  ,1  ,1  ,1  ,1  ,0  ,1  ,0  ,1  ,1  ,1  ,1  ,1  ,1  },
		{342,0  ,1  ,1  ,1  ,1  ,1  ,1  ,0  ,1  ,0  ,1  ,1  ,1  ,1  ,1  ,1  },
		{371,0  ,203,203,1  ,1  ,1  ,1  ,0  ,1  ,0  ,1  ,203,200,1  ,1  ,1  },
		{8  ,0  ,204,204,1  ,1  ,1  ,1  ,0  ,1  ,0  ,1  ,200,201,1  ,1  ,1  },
	},
	{                                           //第六层地图
		{1  ,1  ,1  ,1  ,1  ,1  ,0  ,1  ,1  ,1  ,1  ,0  ,1  ,1  ,1  ,0  ,9  },
		{1  ,200,1  ,1  ,351,350,3  ,1  ,1  ,1  ,1  ,3  ,350,1  ,1  ,0  ,1  },
		{1  ,201,1  ,351,351,351,0  ,1  ,1  ,1  ,1  ,0  ,1  ,1  ,1  ,0  ,1  },
		{204,1  ,1  ,1  ,1  ,1  ,0  ,0  ,0  ,0  ,0  ,0  ,1  ,1  ,1  ,2  ,1  },
		{1  ,1  ,1  ,1  ,1  ,1  ,0  ,1  ,1  ,1  ,1  ,0  ,1  ,1  ,1  ,0  ,1  },
		{1  ,1  ,1  ,1  ,1  ,1  ,0  ,202,1  ,351,351,4  ,350,1  ,1  ,0  ,1  },
		{1  ,1  ,1  ,1  ,1  ,1  ,0  ,1  ,1  ,1  ,1  ,0  ,1  ,1  ,1  ,0  ,1  },
		{0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,1  },
		{1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,350,351,351,1  ,1  },
		{8  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  },
		{1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,350,351,351,1  ,1  },
		{0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,1  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  },
		{1  ,1  ,1  ,1  ,1  ,351,351,0  ,1  ,0  ,1  ,1  ,1  ,1  ,1  ,1  ,1  },
		{1  ,1  ,1  ,1  ,303,351,350,0  ,1  ,0  ,351,351,1  ,1  ,1  ,1  ,1  },
		{1  ,203,207,1  ,303,351,350,2  ,1  ,2  ,351,351,1  ,206,1  ,1  ,1  },
		{1  ,204,200,1  ,303,351,350,0  ,1  ,0  ,351,351,1  ,206,1  ,1  ,1  },
		{1  ,1  ,1  ,1  ,1  ,351,351,0  ,8  ,0 , 1  ,1  ,1  ,204,1  ,1  ,1  },
	},
	{                                            //第七层地图
		{7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,1  ,1  ,9  },
		{7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,1  ,1  ,1  },
		{7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,400,400,400},
		{7  ,7  ,7  ,0  ,0  ,0  ,1  ,1  ,1  ,1  ,1  ,1  ,7  ,7  ,1  ,1  ,1  },
		{7  ,7  ,7  ,0  ,0  ,0  ,1  ,1  ,1  ,341,1  ,1  ,7  ,7  ,1  ,1  ,1  },
		{7  ,7  ,7  ,0  ,0  ,0  ,1  ,1  ,341,340,341,1  ,7  ,7  ,1  ,1  ,1  },
		{7  ,7  ,7  ,0  ,0  ,0  ,0  ,0  ,0  ,2  ,0  ,0  ,7  ,7  ,1  ,1  ,1  },
		{7  ,7  ,211,402,401,1  ,1  ,1  ,1  ,341,1  ,1  ,7  ,7  ,1  ,1  ,1  },
		{7  ,7  ,211,403,402,401,1  ,1  ,1  ,342,1  ,1  ,1  ,1  ,1  ,1  ,1  },
		{7  ,7  ,211,402,401,1  ,1  ,1  ,1  ,341,1  ,1  ,7  ,7  ,1  ,1  ,1  },
		{7  ,7  ,7  ,0  ,0  ,0  ,0  ,0  ,0  ,2  ,0  ,0  ,7  ,7  ,1  ,1  ,1  },
		{7  ,7  ,7  ,0  ,0  ,0  ,1  ,341,1  ,340,341,1  ,7  ,7  ,1  ,1  ,1  },
		{7  ,7  ,7  ,0  ,0  ,0  ,1  ,1  ,1  ,341,1  ,1  ,7  ,7  ,1  ,1  ,1  },
		{7  ,7  ,7  ,0  ,0  ,0  ,1  ,1  ,1  ,1  ,1  ,1  ,7  ,7  ,1  ,1  ,1  },
		{7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,1  ,1  ,1  },
		{7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,1  ,1  ,1  },
		{7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,1  ,1  ,8  },
	},
	{                                            //第八层地图
		{9  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,0  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  },
		{1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,0  ,1  ,391,1  ,1  ,1  ,207,1  ,1  },
		{0  ,0  ,0  ,0  ,0  ,0  ,1  ,1  ,0  ,392,391,391,207,1  ,1  ,1  ,1  },
		{1  ,1  ,1  ,1  ,1  ,0  ,1  ,1  ,2  ,390,392,1  ,1  ,1  ,1  ,1  ,1  },
		{1  ,1  ,1  ,1  ,1  ,0  ,1  ,1  ,0  ,392,391,1  ,1  ,1  ,1  ,1  ,1  },
		{1  ,1  ,1  ,1  ,1  ,0  ,1  ,1  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  },
		{1  ,1  ,1  ,392,391,0  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  },
		{393,1  ,1  ,392,391,3  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  },
		{1  ,1  ,1  ,392,391,0  ,1  ,1  ,1  ,1  ,0  ,0  ,0  ,0  ,0  ,0  ,0  },
		{1  ,1  ,1  ,1  ,1  ,0  ,1  ,1  ,1  ,1  ,3  ,391,1  ,1  ,1  ,1  ,1  },
		{1  ,1  ,1  ,1  ,1  ,0  ,1  ,1  ,1  ,1  ,0  ,1  ,1  ,1  ,1  ,1  ,1  },
		{1  ,1  ,1  ,1  ,1  ,0  ,1  ,1  ,1  ,1  ,0  ,1  ,1  ,208,211,1  ,1  },
		{0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,1  ,1  ,1  ,1  ,1  ,1  },
		{0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,1  ,1  ,0  ,0  },
		{7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,7  ,4  ,4  ,7  ,7  },
		{0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,1  ,392,0  ,0  },
		{0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,8  ,104,0  ,0  },
	},
	{											//第九层地图
		{1  ,1  ,1  ,1  ,380,1  ,1  ,1  ,1  ,7  ,7  ,7  ,7  ,7  ,7  ,1  ,9  },
		{1  ,1  ,1  ,1  ,380,1  ,1  ,1  ,1  ,7  ,7  ,7  ,7  ,7  ,7  ,1  ,1  },
		{1  ,1  ,7  ,7  ,7  ,7  ,7  ,1  ,1  ,7  ,7  ,7  ,7  ,7  ,7  ,1  ,1  },
		{1  ,1  ,7  ,7  ,7  ,7  ,7  ,381,381,7  ,7  ,7  ,7  ,7  ,7  ,1  ,1  },
		{1  ,1  ,7  ,7  ,7  ,7  ,7  ,2  ,2  ,7  ,7  ,7  ,7  ,7  ,7  ,1  ,1  },
		{1  ,1  ,7  ,7  ,7  ,7  ,7  ,1  ,1  ,7  ,7  ,7  ,7  ,7  ,7  ,1  ,1  },
		{1  ,1  ,7  ,7  ,7  ,7  ,7  ,1  ,1  ,7  ,7  ,7  ,7  ,7  ,7  ,1  ,1  },
		{1  ,1  ,7  ,7  ,7  ,7  ,7  ,1  ,1  ,7  ,7  ,7  ,7  ,7  ,7  ,1  ,1  },
		{1  ,1  ,7  ,7  ,7  ,7  ,7  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  },
		{1  ,1  ,7  ,7  ,7  ,7  ,7  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  },
		{1  ,1  ,7  ,7  ,7  ,7  ,7  ,1  ,1  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  },
		{1  ,1  ,7  ,7  ,7  ,7  ,7  ,380,380,0  ,1  ,1  ,1  ,1  ,1  ,1  ,1  },
		{1  ,1  ,7  ,7  ,7  ,7  ,7  ,380,380,0  ,380,1  ,1  ,1  ,1  ,1  ,1  },
		{1  ,1  ,7  ,7  ,7  ,7  ,7  ,1  ,1  ,2  ,381,380,1  ,1  ,1  ,204,1  },
		{1  ,1  ,7  ,7  ,7  ,7  ,7  ,1  ,1  ,0  ,380,380,1  ,207,203,1  ,1  },
		{1  ,1  ,7  ,7  ,7  ,7  ,7  ,1  ,1  ,0  ,380,1  ,1  ,1  ,200,201,1  },
		{8  ,1  ,7  ,7  ,7  ,7  ,7  ,1  ,1  ,0  ,1  ,1  ,1  ,1  ,200,201,1  },
	},
		{                                    //第十层地图
		{8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{2,2,0,0,2,2,0,0,0,0,4,3,0,0,0,1,1},
		{200,201,0,0,1,1,0,0,0,0,2,3,0,0,0,1,1},
		{1,1,0,0,1,1,0,0,0,410,410,410,410,0,0,1,1},
		{1,1,0,0,1,1,0,0,0,1,411,411,1,0,0,1,1},
		{1,411,0,0,1,1,0,0,0,1,1,1,1,0,0,1,1},
		{411,411,0,0,1,1,0,0,0,1,1,1,1,0,0,1,1},
		{411,410,2,2,1,1,0,0,0,1,1,1,1,0,0,1,1},
		{411,411,0,0,1,1,0,0,0,1,1,1,1,0,0,1,1},
		{1,411,0,0,1,1,0,0,0,1,1,1,1,0,0,1,1},
		{1,1,0,0,1,1,0,0,0,0,2,3,0,0,0,1,1},
		{1,1,0,0,1,1,0,0,0,1,1,1,1,0,0,1,1},
		{1,1,0,0,1,1,0,0,0,1,1,1,1,0,0,1,1},
		{207,207,0,0,1,1,0,0,0,1,1,1,1,0,0,1,1},
		{1,203,0,0,1,1,0,0,0,1,1,1,1,0,0,1,1},
		{1,202,0,0,1,1,0,0,0,1,412,411,1,0,0,1,9},            //杀死龙王后魔法门打开
	},

	{                                            //第十一层地图
		{8,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1},
		{1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1},
		{1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1},
		{1,370,1,1,0,0,1,1,0,0,1,1,1,1,1,1,1},
		{1,370,1,1,0,0,1,1,0,0,1,1,1,1,1,1,1},
		{0,0,1,1,0,0,1,1,0,0,1,1,1,0,0,0,0},
		{0,0,1,1,0,0,1,1,0,0,1,1,1,0,0,0,0},
		{1,0,0,1,1,0,1,1,0,0,1,1,1,0,1,1,1},
		{1,1,0,1,1,0,0,0,0,0,1,1,1,0,1,1,1},
		{1,1,0,1,1,0,0,0,0,0,1,1,1,0,1,1,1},
		{1,1,0,1,1,0,0,0,0,0,1,1,1,2,370,1,1},
		{1,1,0,1,1,0,0,0,0,0,1,1,1,0,1,1,1},
		{1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1},
		{1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1},
		{1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,371},
		{1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,9},
	},
	{                                           //第十二层地图
		{1,1  ,0,0  ,1,1,1,1  ,0,0,0,1,1,1,1,1,1},
		{1,1  ,0,0  ,1,1,1,1  ,0,0,0,1,1,1,1,1,1},
		{1,1  ,0,0  ,0,0,1,1  ,0,0,0,0,0,1,1,1,1},
		{1,1  ,0,0  ,0,0,1,1  ,0,0,0,0,0,1,1,1,1},
		{1,341,1,0  ,0,1,1,0  ,0,1,1,1,1,1,1,1,1},
		{1,341,1,0  ,0,1,1,0  ,0,1,1,1,1,1,1,1,1},
		{1,0  ,1,340,0,1,1,0  ,1,1,1,0,0,1,1,1,1},
		{1,0  ,0,3  ,0,0,1,1  ,0,0,1,1,1,0,0,1,1},
		{1,0  ,0,1  ,1,2,1,1  ,0,0,1,1,1,0,0,1,1},
		{1,0  ,0,1  ,1,0,0,0  ,0,0,1,1,1,0,0,1,1},
		{1,0  ,0,1  ,1,0,0,0  ,0,0,1,1,1,0,0,1,1},
		{1,0  ,0,1  ,1,0,0,0  ,0,0,1,1,1,0,0,1,1},
		{1,0  ,0,1  ,1,0,0,0  ,0,0,1,1,1,0,0,1,1},
		{1,0  ,0,1  ,1,7,7,0  ,7,7,1,1,1,0,0,1,1},
		{1,0  ,0,1  ,1,7,7,0  ,7,7,1,1,1,0,0,1,1},
		{1,0  ,0,1  ,1,7,7,0  ,7,7,1,1,1,0,0,1,1},
		{9,0  ,0,1  ,1,1,1,340,1,1,1,1,0,0,0,1,8},
	},
	{                                            //第十三层地图
		{1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1},
		{1,1,0,0,0,1,1,1,0,1,1,1,1,0,0,1,1},
		{1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1},
		{1,0,1,1,0,0,3,0,0,0,0,0,1,1,1,1,1},
		{1,0,1,1,0,1,1,1,1,0,0,0,1,1,1,1,1},
		{1,0,1,1,0,1,1,1,1,0,0,0,1,1,0,0,0},
		{1,0,1,1,0,1,1,1,1,0,0,0,1,1,0,0,0},
		{1,0,0,1,0,0,1,1,0,0,1,1,1,1,0,1,1},
		{1,1,0,1,1,0,0,0,0,0,1,1,1,1,0,1,1},
		{1,1,0,1,1,0,0,0,0,0,1,1,1,1,0,1,1},
		{1,1,0,1,1,0,0,0,0,0,1,1,1,1,0,2,0},
		{1,1,0,1,1,0,0,0,0,0,1,1,1,1,1,1,1},
		{1,1,0,1,1,2,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,8},
		{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9},
	},
	{                                            //第十四层地图
		{1,1,0,0,1,1,1,9,1,1,1,1,1,1,0,1,1},
		{1,1,1,3,1,1,1,1,1,1,1,1,1,1,0,1,1},
		{1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1},
		{1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1},
		{1,1,1,1,0,0,1,1,0,0,1,1,3,1,1,1,1},
		{1,1,1,1,0,0,1,1,0,0,0,0,0,1,1,1,1},
		{1,1,1,1,0,0,1,1,0,0,1,1,1,1,1,1,1},
		{0,0,1,1,0,0,1,1,0,0,1,1,1,0,0,3,0},
		{0,0,1,1,1,0,1,1,0,0,1,1,1,0,1,1,1},
		{0,0,1,1,1,0,0,2,0,0,1,1,1,0,1,1,1},
		{0,0,0,0,0,0,0,2,0,0,1,1,1,0,1,1,1},
		{1,1,1,1,1,0,0,2,0,0,0,0,0,0,1,1,1},
		{1,1,1,1,1,0,0,2,0,1,1,1,1,0,1,1,1},
		{1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1},
		{1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1},
		{1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1},
		{1,1,1,1,1,4,1,8,1,1,1,1,1,3,1,1,1},
	},
};