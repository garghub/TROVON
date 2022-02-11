static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 = F_2 ( V_2 ) ;
F_3 ( V_4 , V_5 , F_4 ( V_2 -> V_6 ) ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_3 ( V_4 , V_2 -> V_7 ,
F_6 ( V_2 -> V_6 ) ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
V_2 -> V_7 =
F_8 ( V_4 , F_6 ( V_2 -> V_6 ) ) ;
}
static T_1 F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_8 , V_9 ;
do {
V_8 = F_2 ( V_2 ) ;
V_9 = F_8 ( V_4 , F_4 ( V_2 -> V_6 ) ) ;
} while ( ( T_1 ) F_10 ( & V_2 -> V_10 , V_8 , V_9 ) != V_8 );
if ( ! F_11 ( V_2 , V_9 ) )
F_12 ( V_4 -> V_11 , L_1 ,
V_12 , V_2 -> V_6 , F_2 ( V_2 ) ,
F_13 ( V_2 ) ) ;
return V_9 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_13 = V_2 -> V_6 / 32 ;
if ( ! F_15 ( V_2 ) &&
F_16 ( V_2 ) ) {
F_12 ( V_4 -> V_11 , L_2 ,
V_2 -> V_6 ) ;
F_17 ( V_2 -> V_4 ) ;
return;
}
F_3 ( V_4 , F_18 ( V_2 -> V_6 ) ,
F_19 ( V_13 ) ) ;
F_20 () ;
}
static int F_21 ( struct V_1 * V_2 , void * V_14 )
{
T_1 V_15 = F_22 (
V_16 , 0 ) ;
* ( ( T_1 * ) V_14 ) = V_15 ;
return 0 ;
}
