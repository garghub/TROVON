static void * F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_4 , T_3 V_5 ,
unsigned long V_6 )
{
void * V_7 ;
V_7 = ( void * ) F_2 ( V_5 , F_3 ( V_3 ) ) ;
if ( V_7 )
* V_4 = ( V_8 ) V_7 ;
return V_7 ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_9 , T_2 V_10 ,
unsigned long V_6 )
{
F_5 ( ( unsigned long ) V_9 , F_3 ( V_3 ) ) ;
}
static T_2 F_6 ( struct V_1 * V_2 , struct V_11 * V_11 ,
unsigned long V_12 , T_1 V_3 ,
enum V_13 V_14 ,
unsigned long V_6 )
{
return ( V_8 ) ( F_7 ( V_11 ) + V_12 ) ;
}
static int F_8 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_17 , enum V_13 V_14 ,
unsigned long V_6 )
{
int V_18 ;
struct V_15 * V_19 ;
F_9 (sgl, sg, nents, i) {
F_10 ( ! F_11 ( V_19 ) ) ;
F_12 ( V_19 ) = ( V_8 ) F_13 ( V_19 ) ;
F_14 ( V_19 ) = V_19 -> V_20 ;
}
return V_17 ;
}
static int F_15 ( struct V_1 * V_2 , T_2 V_10 )
{
return false ;
}
static int F_16 ( struct V_1 * V_2 , T_4 V_21 )
{
return true ;
}
