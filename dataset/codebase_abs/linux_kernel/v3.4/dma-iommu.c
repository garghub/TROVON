static void * F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_4 , T_3 V_5 ,
struct V_6 * V_7 )
{
return F_2 ( V_2 , F_3 ( V_2 ) , V_3 ,
V_4 , V_2 -> V_8 , V_5 ,
F_4 ( V_2 ) ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_9 , T_2 V_4 ,
struct V_6 * V_7 )
{
F_6 ( F_3 ( V_2 ) , V_3 , V_9 , V_4 ) ;
}
static T_2 F_7 ( struct V_1 * V_2 , struct V_10 * V_10 ,
unsigned long V_11 , T_1 V_3 ,
enum V_12 V_13 ,
struct V_6 * V_7 )
{
return F_8 ( V_2 , F_3 ( V_2 ) , V_10 , V_11 ,
V_3 , F_9 ( V_2 ) , V_13 , V_7 ) ;
}
static void F_10 ( struct V_1 * V_2 , T_2 V_4 ,
T_1 V_3 , enum V_12 V_13 ,
struct V_6 * V_7 )
{
F_11 ( F_3 ( V_2 ) , V_4 , V_3 , V_13 ,
V_7 ) ;
}
static int F_12 ( struct V_1 * V_2 , struct V_14 * V_15 ,
int V_16 , enum V_12 V_13 ,
struct V_6 * V_7 )
{
return F_13 ( V_2 , F_3 ( V_2 ) , V_15 , V_16 ,
F_9 ( V_2 ) , V_13 , V_7 ) ;
}
static void F_14 ( struct V_1 * V_2 , struct V_14 * V_15 ,
int V_16 , enum V_12 V_13 ,
struct V_6 * V_7 )
{
F_15 ( F_3 ( V_2 ) , V_15 , V_16 , V_13 ,
V_7 ) ;
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
static T_4 F_18 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_3 ( V_2 ) ;
T_4 V_17 ;
if ( ! V_19 )
return 0 ;
V_17 = 1ULL < ( F_19 ( V_19 -> V_20 + V_19 -> V_21 ) - 1 ) ;
V_17 += V_17 - 1 ;
return V_17 ;
}
