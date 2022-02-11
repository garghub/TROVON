static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
static unsigned long V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_9 > F_3 ()
&& V_8 -> V_9 < F_4 ()
&& ! F_5 ( 0 , & V_5 ) ) {
F_6 ( V_2 , L_1 ,
F_3 () , V_8 -> V_9 ,
F_4 () ) ;
F_6 ( V_2 , L_2 ,
V_8 -> V_9 ) ;
}
V_4 = F_7 ( V_8 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_8 ( V_8 , & V_3 ) ;
V_7 = F_9 ( V_2 , sizeof( * V_7 ) , V_10 ) ;
if ( ! V_7 )
return - V_11 ;
if ( V_4 < 0 )
return V_4 ;
V_7 -> V_12 = V_4 ;
V_7 -> V_13 = V_4 + V_3 ;
F_10 ( V_2 , V_7 ) ;
if ( V_4 && V_3 && V_4 == V_3 )
return - V_14 ;
V_8 -> V_15 = F_11 ( V_8 ) ;
V_8 -> V_16 = F_12 ( V_8 ) ;
if ( V_3 == 0 )
return 0 ;
F_13 ( V_2 , L_3 ,
V_3 , V_3 == 1 ? L_4 : L_5 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , void * V_17 )
{
F_15 ( V_2 , V_18 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
F_17 ( V_2 ) ;
V_8 -> V_19 = NULL ;
V_8 -> V_15 = NULL ;
V_8 -> V_16 = NULL ;
F_10 ( V_2 , NULL ) ;
F_18 ( V_2 ) ;
F_19 ( V_2 , NULL , F_14 ) ;
return 0 ;
}
int T_1 F_20 ( void )
{
return F_21 ( & V_20 ) ;
}
void F_22 ( void )
{
F_23 ( & V_20 . V_21 ) ;
}
