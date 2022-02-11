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
unsigned long V_13 )
{
T_1 V_4 = F_6 ( V_9 ) + V_10 ;
F_7 ( V_5 == 0 ) ;
if ( ! F_1 ( L_2 , V_8 , V_4 , V_5 ) )
return V_14 ;
F_8 () ;
return V_4 ;
}
static int F_9 ( struct V_2 * V_3 , struct V_15 * V_16 ,
int V_17 , enum V_11 V_12 ,
unsigned long V_13 )
{
struct V_15 * V_18 ;
int V_19 ;
F_7 ( V_17 == 0 || V_16 [ 0 ] . V_20 == 0 ) ;
F_10 (sg, s, nents, i) {
F_11 ( ! F_12 ( V_18 ) ) ;
V_18 -> V_21 = F_13 ( V_18 ) ;
if ( ! F_1 ( L_3 , V_3 , V_18 -> V_21 , V_18 -> V_20 ) )
return 0 ;
V_18 -> V_22 = V_18 -> V_20 ;
}
F_8 () ;
return V_17 ;
}
static void F_14 ( struct V_2 * V_8 ,
T_1 V_23 , T_2 V_5 ,
enum V_11 V_12 )
{
F_8 () ;
}
static void F_15 ( struct V_2 * V_8 ,
struct V_15 * V_16 , int V_24 ,
enum V_11 V_12 )
{
F_8 () ;
}
