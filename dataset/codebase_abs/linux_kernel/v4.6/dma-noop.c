static void * F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_4 , T_3 V_5 ,
struct V_6 * V_7 )
{
void * V_8 ;
V_8 = ( void * ) F_2 ( V_5 , F_3 ( V_3 ) ) ;
if ( V_8 )
* V_4 = F_4 ( V_8 ) ;
return V_8 ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_9 , T_2 V_10 ,
struct V_6 * V_7 )
{
F_6 ( ( unsigned long ) V_9 , F_3 ( V_3 ) ) ;
}
static T_2 F_7 ( struct V_1 * V_2 , struct V_11 * V_11 ,
unsigned long V_12 , T_1 V_3 ,
enum V_13 V_14 ,
struct V_6 * V_7 )
{
return F_8 ( V_11 ) + V_12 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_15 * V_16 , int V_17 ,
enum V_13 V_14 , struct V_6 * V_7 )
{
int V_18 ;
struct V_15 * V_19 ;
F_10 (sgl, sg, nents, i) {
void * V_20 ;
F_11 ( ! F_12 ( V_19 ) ) ;
V_20 = F_13 ( V_19 ) ;
F_14 ( V_19 ) = ( T_2 ) F_4 ( V_20 ) ;
F_15 ( V_19 ) = V_19 -> V_21 ;
}
return V_17 ;
}
static int F_16 ( struct V_1 * V_2 , T_2 V_10 )
{
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , T_4 V_22 )
{
return 1 ;
}
