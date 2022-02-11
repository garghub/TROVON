static void F_1 ( void * V_1 )
{
int V_2 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
unsigned long V_7 , V_8 , V_9 , V_10 , V_11 ,
V_12 , V_13 , V_14 , V_15 ;
V_4 = V_1 ;
V_4 -> V_16 ++ ;
V_2 = 0 ;
V_7 = 0 ;
V_8 = 0 ;
V_9 = 0 ;
V_10 = 0 ;
V_11 = 0 ;
V_12 = 0 ;
V_13 = 0 ;
V_14 = 0 ;
V_15 = 0 ;
F_2 () ;
F_3 (&init_net, dev) {
const struct V_17 * V_18 ;
struct V_17 V_19 ;
V_18 = F_4 ( V_6 , & V_19 ) ;
V_7 += V_18 -> V_7 ;
V_8 += V_18 -> V_8 ;
V_9 += V_18 -> V_9 ;
V_10 += V_18 -> V_10 ;
V_11 += V_18 -> V_11 ;
V_12 += V_18 -> V_12 ;
V_13 += V_18 -> V_13 ;
V_14 += V_18 -> V_14 ;
V_15 += V_18 -> V_15 ;
V_2 ++ ;
}
F_5 () ;
V_4 -> V_20 = V_2 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_9 = V_9 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_11 = V_11 ;
V_4 -> V_12 = V_12 ;
V_4 -> V_13 = V_13 ;
V_4 -> V_14 = V_14 ;
V_4 -> V_15 = V_15 ;
V_4 -> V_21 = F_6 () ;
V_4 -> V_22 ++ ;
}
static int T_1 F_7 ( void )
{
return F_8 ( & V_23 ) ;
}
static void T_2 F_9 ( void )
{
F_10 ( & V_23 ) ;
}
