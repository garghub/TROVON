static void * F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_4 , T_3 V_5 ,
unsigned long V_6 )
{
void * V_7 ;
V_7 = ( void * ) F_2 ( V_5 , F_3 ( V_3 ) ) ;
if ( V_7 )
* V_4 = F_4 ( V_7 ) ;
return V_7 ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_8 , T_2 V_9 ,
unsigned long V_6 )
{
F_6 ( ( unsigned long ) V_8 , F_3 ( V_3 ) ) ;
}
static T_2 F_7 ( struct V_1 * V_2 , struct V_10 * V_10 ,
unsigned long V_11 , T_1 V_3 ,
enum V_12 V_13 ,
unsigned long V_6 )
{
return F_8 ( V_10 ) + V_11 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_14 * V_15 , int V_16 ,
enum V_12 V_13 ,
unsigned long V_6 )
{
int V_17 ;
struct V_14 * V_18 ;
F_10 (sgl, sg, nents, i) {
void * V_19 ;
F_11 ( ! F_12 ( V_18 ) ) ;
V_19 = F_13 ( V_18 ) ;
F_14 ( V_18 ) = ( T_2 ) F_4 ( V_19 ) ;
F_15 ( V_18 ) = V_18 -> V_20 ;
}
return V_16 ;
}
static int F_16 ( struct V_1 * V_2 , T_2 V_9 )
{
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , T_4 V_21 )
{
return 1 ;
}
