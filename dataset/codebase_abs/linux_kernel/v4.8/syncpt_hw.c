static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
F_3 ( V_5 , V_3 , F_4 ( V_2 -> V_6 ) ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
F_3 ( V_5 , V_2 -> V_7 ,
F_6 ( V_2 -> V_6 ) ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
V_2 -> V_7 =
F_8 ( V_5 , F_6 ( V_2 -> V_6 ) ) ;
}
static T_1 F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_8 , V_9 ;
do {
V_8 = F_2 ( V_2 ) ;
V_9 = F_8 ( V_5 , F_4 ( V_2 -> V_6 ) ) ;
} while ( ( T_1 ) F_10 ( & V_2 -> V_10 , V_8 , V_9 ) != V_8 );
if ( ! F_11 ( V_2 , V_9 ) )
F_12 ( V_5 -> V_11 , L_1 ,
V_12 , V_2 -> V_6 , F_2 ( V_2 ) ,
F_13 ( V_2 ) ) ;
return V_9 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_13 = V_2 -> V_6 / 32 ;
if ( ! F_15 ( V_2 ) &&
F_16 ( V_2 ) )
return - V_14 ;
F_3 ( V_5 , F_17 ( V_2 -> V_6 ) ,
F_18 ( V_13 ) ) ;
F_19 () ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , void * V_15 )
{
T_1 V_16 = F_21 ( V_17 , 0 ) ;
* ( ( T_1 * ) V_15 ) = V_16 ;
return 0 ;
}
