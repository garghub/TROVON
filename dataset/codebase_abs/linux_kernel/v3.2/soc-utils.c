int F_1 ( int V_1 , int V_2 , int V_3 )
{
return V_1 * V_2 * V_3 ;
}
int F_2 ( struct V_4 * V_5 )
{
int V_1 ;
V_1 = F_3 ( F_4 ( V_5 ) ) ;
if ( V_1 < 0 )
return V_1 ;
return F_1 ( V_1 , F_5 ( V_5 ) ,
1 ) ;
}
int F_6 ( int V_6 , int V_1 , int V_2 , int V_3 )
{
return V_6 * F_1 ( V_1 , V_2 , V_3 ) ;
}
int F_7 ( struct V_4 * V_5 )
{
int V_7 ;
V_7 = F_2 ( V_5 ) ;
if ( V_7 > 0 )
return V_7 * F_8 ( V_5 ) ;
else
return V_7 ;
}
static int F_9 ( struct V_8 * V_9 )
{
F_10 ( V_9 , & V_10 ) ;
return 0 ;
}
static T_1 int F_11 ( struct V_11 * V_12 )
{
return F_12 ( & V_12 -> V_13 , & V_14 ) ;
}
static T_2 int F_13 ( struct V_11 * V_12 )
{
F_14 ( & V_12 -> V_13 ) ;
return 0 ;
}
int T_3 F_15 ( void )
{
int V_7 ;
V_15 = F_16 ( L_1 , - 1 ) ;
if ( ! V_15 )
return - V_16 ;
V_7 = F_17 ( V_15 ) ;
if ( V_7 != 0 ) {
F_18 ( V_15 ) ;
return V_7 ;
}
V_7 = F_19 ( & V_17 ) ;
if ( V_7 != 0 )
F_20 ( V_15 ) ;
return V_7 ;
}
void T_4 F_21 ( void )
{
F_20 ( V_15 ) ;
F_22 ( & V_17 ) ;
}
