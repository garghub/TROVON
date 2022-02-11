static int
F_1 ( char * V_1 , struct V_2 * V_3 , T_1 V_4 , T_2 V_5 )
{
if ( V_3 && ! F_2 ( V_3 , V_4 , V_5 ) ) {
if ( * V_3 -> V_6 >= F_3 ( 32 ) )
F_4 ( V_7
L_1 ,
V_1 , ( long long ) V_4 , V_5 ,
( long long ) * V_3 -> V_6 ) ;
return 0 ;
}
return 1 ;
}
static T_1 F_5 ( struct V_2 * V_8 , struct V_9 * V_9 ,
unsigned long V_10 , T_2 V_5 ,
enum V_11 V_12 ,
struct V_13 * V_14 )
{
T_1 V_4 = F_6 ( V_9 ) + V_10 ;
F_7 ( V_5 == 0 ) ;
if ( ! F_1 ( L_2 , V_8 , V_4 , V_5 ) )
return V_15 ;
F_8 () ;
return V_4 ;
}
static int F_9 ( struct V_2 * V_3 , struct V_16 * V_17 ,
int V_18 , enum V_11 V_12 ,
struct V_13 * V_14 )
{
struct V_16 * V_19 ;
int V_20 ;
F_7 ( V_18 == 0 || V_17 [ 0 ] . V_21 == 0 ) ;
F_10 (sg, s, nents, i) {
F_11 ( ! F_12 ( V_19 ) ) ;
V_19 -> V_22 = F_13 ( V_19 ) ;
if ( ! F_1 ( L_3 , V_3 , V_19 -> V_22 , V_19 -> V_21 ) )
return 0 ;
V_19 -> V_23 = V_19 -> V_21 ;
}
F_8 () ;
return V_18 ;
}
static void F_14 ( struct V_2 * V_8 , T_2 V_5 , void * V_24 ,
T_1 V_25 )
{
F_15 ( ( unsigned long ) V_24 , F_16 ( V_5 ) ) ;
}
static void F_17 ( struct V_2 * V_8 ,
T_1 V_26 , T_2 V_5 ,
enum V_11 V_12 )
{
F_8 () ;
}
static void F_18 ( struct V_2 * V_8 ,
struct V_16 * V_17 , int V_27 ,
enum V_11 V_12 )
{
F_8 () ;
}
