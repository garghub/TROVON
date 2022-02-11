static void * F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_4 , T_3 V_5 )
{
return F_2 ( V_2 , F_3 ( V_2 ) , V_3 ,
V_4 , V_2 -> V_6 , V_5 ,
F_4 ( V_2 ) ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_7 , T_2 V_4 )
{
F_6 ( F_3 ( V_2 ) , V_3 , V_7 , V_4 ) ;
}
static T_2 F_7 ( struct V_1 * V_2 , struct V_8 * V_8 ,
unsigned long V_9 , T_1 V_3 ,
enum V_10 V_11 ,
struct V_12 * V_13 )
{
return F_8 ( V_2 , F_3 ( V_2 ) , V_8 , V_9 ,
V_3 , F_9 ( V_2 ) , V_11 , V_13 ) ;
}
static void F_10 ( struct V_1 * V_2 , T_2 V_4 ,
T_1 V_3 , enum V_10 V_11 ,
struct V_12 * V_13 )
{
F_11 ( F_3 ( V_2 ) , V_4 , V_3 , V_11 ,
V_13 ) ;
}
static int F_12 ( struct V_1 * V_2 , struct V_14 * V_15 ,
int V_16 , enum V_10 V_11 ,
struct V_12 * V_13 )
{
return F_13 ( V_2 , F_3 ( V_2 ) , V_15 , V_16 ,
F_9 ( V_2 ) , V_11 , V_13 ) ;
}
static void F_14 ( struct V_1 * V_2 , struct V_14 * V_15 ,
int V_16 , enum V_10 V_11 ,
struct V_12 * V_13 )
{
F_15 ( F_3 ( V_2 ) , V_15 , V_16 , V_11 ,
V_13 ) ;
}
static int F_16 ( struct V_1 * V_2 , T_4 V_17 )
{
struct V_18 * V_19 = F_3 ( V_2 ) ;
if ( ! V_19 ) {
F_17 ( V_2 , L_1
L_2 , V_17 ) ;
return 0 ;
}
if ( ( V_19 -> V_20 + V_19 -> V_21 ) > ( V_17 >> V_22 ) ) {
F_17 ( V_2 , L_3 ) ;
F_17 ( V_2 , L_4 ,
V_17 , ( V_19 -> V_20 + V_19 -> V_21 ) <<
V_22 ) ;
return 0 ;
} else
return 1 ;
}
