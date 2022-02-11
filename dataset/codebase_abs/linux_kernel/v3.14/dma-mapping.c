static void * F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_4 , T_3 V_5 ,
struct V_6 * V_7 )
{
if ( V_2 == NULL ) {
F_2 ( 1 , L_1 ) ;
return NULL ;
}
if ( F_3 ( V_8 ) &&
V_2 -> V_9 <= F_4 ( 32 ) )
V_5 |= V_10 ;
if ( F_3 ( V_11 ) ) {
struct V_12 * V_12 ;
V_3 = F_5 ( V_3 ) ;
V_12 = F_6 ( V_2 , V_3 >> V_13 ,
F_7 ( V_3 ) ) ;
if ( ! V_12 )
return NULL ;
* V_4 = F_8 ( V_2 , F_9 ( V_12 ) ) ;
return F_10 ( V_12 ) ;
} else {
return F_11 ( V_2 , V_3 , V_4 , V_5 ) ;
}
}
static void F_12 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_14 , T_2 V_4 ,
struct V_6 * V_7 )
{
if ( V_2 == NULL ) {
F_2 ( 1 , L_1 ) ;
return;
}
if ( F_3 ( V_11 ) ) {
T_4 V_15 = F_13 ( V_2 , V_4 ) ;
F_14 ( V_2 ,
F_15 ( V_15 ) ,
V_3 >> V_13 ) ;
} else {
F_16 ( V_2 , V_3 , V_14 , V_4 ) ;
}
}
void T_5 F_17 ( void )
{
V_16 = & V_17 ;
F_18 ( 1 ) ;
}
static int T_5 F_19 ( void )
{
F_20 ( V_18 ) ;
return 0 ;
}
