static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_3 ,
unsigned long V_4 , T_2 V_5 ,
enum V_6 V_7 ,
unsigned long V_8 )
{
T_1 V_9 = F_2 ( V_3 ) + V_4 ;
F_3 ( V_5 == 0 ) ;
F_4 ( V_2 , F_5 ( V_3 ) + V_4 , V_5 , V_7 ) ;
return V_9 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_10 * V_11 ,
int V_12 , enum V_6 V_7 ,
unsigned long V_8 )
{
struct V_10 * V_13 ;
int V_14 ;
F_3 ( V_12 == 0 || V_11 [ 0 ] . V_15 == 0 ) ;
F_7 (sg, s, nents, i) {
F_8 ( ! F_9 ( V_13 ) ) ;
F_4 ( V_2 , F_10 ( V_13 ) , V_13 -> V_15 , V_7 ) ;
V_13 -> V_16 = F_11 ( V_13 ) ;
V_13 -> V_17 = V_13 -> V_15 ;
}
return V_12 ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_9 ,
T_2 V_5 , enum V_6 V_7 )
{
F_4 ( V_2 , F_13 ( V_9 ) , V_5 , V_7 ) ;
}
static void F_14 ( struct V_1 * V_2 , struct V_10 * V_11 ,
int V_18 , enum V_6 V_7 )
{
struct V_10 * V_13 ;
int V_14 ;
F_7 (sg, s, nelems, i)
F_4 ( V_2 , F_10 ( V_13 ) , V_13 -> V_15 , V_7 ) ;
}
void T_3 F_15 ( void )
{
if ( V_19 )
return;
V_19 = & V_20 ;
}
