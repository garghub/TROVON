static int F_1 ( struct V_1 * V_2 )
{
int V_3 = F_2 ( V_2 , V_4 ,
( ( V_5 == V_2 -> V_6 )
? V_7
: 0 ) ) ;
return V_3 < 0 ? V_3 : 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_3 = F_4 ( V_2 , V_8 ) ;
return V_3 < 0 ? V_3 : 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_3 = F_4 ( V_2 , V_9 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_2 , V_9 ,
V_3 | V_10 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_3 ( V_2 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_3 = F_4 ( V_2 , V_9 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 &= ~ V_10 ;
V_3 = F_2 ( V_2 , V_9 , V_3 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_3 ( V_2 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
return F_3 ( V_2 ) ;
}
static int T_1 F_8 ( void )
{
return F_9 ( V_11 ,
F_10 ( V_11 ) ) ;
}
static void T_2 F_11 ( void )
{
return F_12 ( V_11 ,
F_10 ( V_11 ) ) ;
}
