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
struct V_10 * V_11 = V_9 -> V_12 ;
if ( ! V_11 -> V_13 -> V_14 )
F_10 ( V_9 , & V_15 ) ;
return 0 ;
}
int F_11 ( struct V_16 * V_17 )
{
if ( V_17 -> V_18 == & V_19 )
return 1 ;
return 0 ;
}
static int F_12 ( struct V_20 * V_21 )
{
int V_7 ;
V_7 = F_13 ( & V_21 -> V_22 , & V_23 , & V_19 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_14 ( & V_21 -> V_22 , & V_24 ) ;
if ( V_7 < 0 ) {
F_15 ( & V_21 -> V_22 ) ;
return V_7 ;
}
return V_7 ;
}
static int F_16 ( struct V_20 * V_21 )
{
F_17 ( & V_21 -> V_22 ) ;
F_15 ( & V_21 -> V_22 ) ;
return 0 ;
}
int T_1 F_18 ( void )
{
int V_7 ;
V_25 =
F_19 ( L_1 , - 1 , NULL , 0 ) ;
if ( F_20 ( V_25 ) )
return F_21 ( V_25 ) ;
V_7 = F_22 ( & V_26 ) ;
if ( V_7 != 0 )
F_23 ( V_25 ) ;
return V_7 ;
}
void T_2 F_24 ( void )
{
F_23 ( V_25 ) ;
F_25 ( & V_26 ) ;
}
