int F_1 ( unsigned V_1 )
{
int V_2 = F_2 ( V_3 , & V_1 , NULL ) ;
if ( V_2 < 0 )
return V_2 ;
else
return ( int ) V_1 < 0 ? - V_4 : 0 ;
}
void F_3 ( unsigned V_1 )
{
F_2 ( V_5 , & V_1 , NULL ) ;
}
int F_4 ( unsigned V_1 , enum V_6 V_7 )
{
int V_2 ;
if ( V_7 == V_8 )
V_2 = F_2 ( V_9 , & V_1 , NULL ) ;
else
V_2 = F_2 ( V_10 , & V_1 , NULL ) ;
if ( V_2 < 0 )
return V_2 ;
else
return ( int ) V_1 < 0 ? - V_4 : 0 ;
}
int F_5 ( unsigned V_1 , unsigned V_11 )
{
int V_2 = F_2 ( V_12 , & V_1 , & V_11 ) ;
if ( V_2 < 0 )
return V_2 ;
else
return ( int ) V_1 < 0 ? - V_4 : 0 ;
}
int F_6 ( unsigned V_1 , unsigned V_11 )
{
int V_2 = F_2 ( V_13 , & V_1 , & V_11 ) ;
if ( V_2 < 0 )
return V_2 ;
else
return ( int ) V_1 < 0 ? - V_4 : 0 ;
}
int F_7 ( unsigned V_1 , unsigned V_11 )
{
int V_2 = F_2 ( V_14 , & V_1 , & V_11 ) ;
if ( V_2 < 0 )
return V_2 ;
else
return ( int ) V_1 < 0 ? - V_4 : 0 ;
}
int F_8 ( unsigned V_1 , unsigned V_15 )
{
int V_2 = F_2 ( V_16 , & V_1 , & V_15 ) ;
if ( V_2 < 0 )
return V_2 ;
else
return ( int ) V_1 < 0 ? - V_4 : 0 ;
}
unsigned F_9 ( unsigned V_1 )
{
if ( F_2 ( V_17 , & V_1 , NULL ) )
return 0 ;
else
return V_1 ;
}
unsigned F_10 ( unsigned V_1 )
{
if ( F_2 ( V_18 , & V_1 , NULL ) )
return 0 ;
else
return V_1 ;
}
long F_11 ( unsigned V_1 , unsigned V_11 )
{
return V_11 ;
}
static bool F_12 ( unsigned V_1 )
{
return false ;
}
