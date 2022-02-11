static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_3 ,
unsigned long V_4 , T_2 V_5 ,
enum V_6 V_7 ,
struct V_8 * V_9 )
{
T_1 V_10 = F_2 ( V_3 ) + V_4 ;
F_3 ( V_5 == 0 ) ;
F_4 ( V_2 , F_5 ( V_3 ) + V_4 , V_5 , V_7 ) ;
return V_10 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_11 * V_12 ,
int V_13 , enum V_6 V_7 ,
struct V_8 * V_9 )
{
struct V_11 * V_14 ;
int V_15 ;
F_3 ( V_13 == 0 || V_12 [ 0 ] . V_16 == 0 ) ;
F_7 (sg, s, nents, i) {
F_8 ( ! F_9 ( V_14 ) ) ;
F_4 ( V_2 , F_10 ( V_14 ) , V_14 -> V_16 , V_7 ) ;
V_14 -> V_17 = F_11 ( V_14 ) ;
V_14 -> V_18 = V_14 -> V_16 ;
}
return V_13 ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_10 ,
T_2 V_5 , enum V_6 V_7 )
{
F_4 ( V_2 , F_13 ( V_10 ) , V_5 , V_7 ) ;
}
static void F_14 ( struct V_1 * V_2 , struct V_11 * V_12 ,
int V_19 , enum V_6 V_7 )
{
struct V_11 * V_14 ;
int V_15 ;
F_7 (sg, s, nelems, i)
F_4 ( V_2 , F_10 ( V_14 ) , V_14 -> V_16 , V_7 ) ;
}
void T_3 F_15 ( void )
{
if ( V_20 )
return;
V_20 = & V_21 ;
}
