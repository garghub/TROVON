static void * F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_4 , T_3 V_5 ,
unsigned long V_6 )
{
return F_2 ( V_2 , F_3 ( V_2 ) , V_3 ,
V_4 , V_2 -> V_7 , V_5 ,
F_4 ( V_2 ) ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_8 , T_2 V_4 ,
unsigned long V_6 )
{
F_6 ( F_3 ( V_2 ) , V_3 , V_8 , V_4 ) ;
}
static T_2 F_7 ( struct V_1 * V_2 , struct V_9 * V_9 ,
unsigned long V_10 , T_1 V_3 ,
enum V_11 V_12 ,
unsigned long V_6 )
{
return F_8 ( V_2 , F_3 ( V_2 ) , V_9 , V_10 ,
V_3 , F_9 ( V_2 ) , V_12 , V_6 ) ;
}
static void F_10 ( struct V_1 * V_2 , T_2 V_4 ,
T_1 V_3 , enum V_11 V_12 ,
unsigned long V_6 )
{
F_11 ( F_3 ( V_2 ) , V_4 , V_3 , V_12 ,
V_6 ) ;
}
static int F_12 ( struct V_1 * V_2 , struct V_13 * V_14 ,
int V_15 , enum V_11 V_12 ,
unsigned long V_6 )
{
return F_13 ( V_2 , F_3 ( V_2 ) , V_14 , V_15 ,
F_9 ( V_2 ) , V_12 , V_6 ) ;
}
static void F_14 ( struct V_1 * V_2 , struct V_13 * V_14 ,
int V_15 , enum V_11 V_12 ,
unsigned long V_6 )
{
F_15 ( F_3 ( V_2 ) , V_14 , V_15 ,
V_12 , V_6 ) ;
}
int F_16 ( struct V_1 * V_2 , T_4 V_16 )
{
struct V_17 * V_18 = F_3 ( V_2 ) ;
if ( ! V_18 ) {
F_17 ( V_2 , L_1
L_2 , V_16 ) ;
return 0 ;
}
if ( V_18 -> V_19 > ( V_16 >> V_18 -> V_20 ) ) {
F_17 ( V_2 , L_3 ) ;
F_17 ( V_2 , L_4 ,
V_16 , V_18 -> V_19 << V_18 -> V_20 ) ;
return 0 ;
} else
return 1 ;
}
static T_4 F_18 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_3 ( V_2 ) ;
T_4 V_16 ;
if ( ! V_18 )
return 0 ;
V_16 = 1ULL < ( F_19 ( V_18 -> V_19 + V_18 -> V_21 ) - 1 ) ;
V_16 += V_16 - 1 ;
return V_16 ;
}
int F_20 ( struct V_1 * V_2 , T_2 V_22 )
{
return V_22 == V_23 ;
}
