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
V_4 = F_8 ( V_8 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_9 ( V_8 , & V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
V_7 = F_10 ( V_2 ) ;
V_7 -> V_10 = V_4 ;
V_7 -> V_11 = V_4 + V_3 ;
if ( V_4 && V_3 && V_4 == V_3 )
return - V_12 ;
V_8 -> V_13 = F_11 ( V_8 ) ;
V_8 -> V_14 = F_12 ( V_8 ) ;
V_8 -> V_15 = F_13 ( V_8 ) ;
if ( V_3 == 0 )
return 0 ;
F_14 ( V_2 , L_3 ,
V_3 , V_3 == 1 ? L_4 : L_5 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , void * V_16 )
{
F_16 ( V_2 , V_17 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
F_18 ( V_2 , NULL , F_15 ) ;
F_19 ( V_2 ) ;
V_8 -> V_18 = NULL ;
V_8 -> V_13 = NULL ;
V_8 -> V_14 = NULL ;
V_8 -> V_15 = NULL ;
F_20 ( V_2 , NULL ) ;
F_21 ( V_2 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , void * V_16 )
{
F_23 ( V_2 , * (enum V_19 * ) V_16 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 , enum V_19 V_20 )
{
F_18 ( V_2 , & V_20 , F_22 ) ;
}
int T_1 F_25 ( void )
{
return F_26 ( & V_21 ) ;
}
void F_27 ( void )
{
F_28 ( & V_21 . V_22 ) ;
}
