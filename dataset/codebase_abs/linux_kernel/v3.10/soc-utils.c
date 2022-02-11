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
static int F_11 ( struct V_11 * V_12 )
{
int V_7 ;
V_7 = F_12 ( & V_12 -> V_13 , & V_14 , & V_15 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_13 ( & V_12 -> V_13 , & V_16 ) ;
if ( V_7 < 0 ) {
F_14 ( & V_12 -> V_13 ) ;
return V_7 ;
}
return V_7 ;
}
static int F_15 ( struct V_11 * V_12 )
{
F_16 ( & V_12 -> V_13 ) ;
F_14 ( & V_12 -> V_13 ) ;
return 0 ;
}
int T_1 F_17 ( void )
{
int V_7 ;
V_17 = F_18 ( L_1 , - 1 ) ;
if ( ! V_17 )
return - V_18 ;
V_7 = F_19 ( V_17 ) ;
if ( V_7 != 0 ) {
F_20 ( V_17 ) ;
return V_7 ;
}
V_7 = F_21 ( & V_19 ) ;
if ( V_7 != 0 )
F_22 ( V_17 ) ;
return V_7 ;
}
void T_2 F_23 ( void )
{
F_22 ( V_17 ) ;
F_24 ( & V_19 ) ;
}
