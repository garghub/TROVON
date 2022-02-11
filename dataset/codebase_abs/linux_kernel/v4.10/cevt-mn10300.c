static int F_1 ( unsigned long V_1 ,
struct V_2 * V_3 )
{
unsigned int V_4 = F_2 () ;
if ( V_4 == 0 ) {
F_3 () ;
F_4 ( V_1 - 1 ) ;
} else {
F_5 () ;
F_6 ( V_1 - 1 ) ;
}
return 0 ;
}
static T_1 F_7 ( int V_5 , void * V_6 )
{
struct V_2 * V_7 ;
unsigned int V_4 = F_2 () ;
if ( V_4 == 0 )
F_3 () ;
else
F_5 () ;
V_7 = & F_8 ( V_8 , V_4 ) ;
V_7 -> V_9 ( V_7 ) ;
return V_10 ;
}
static void V_9 ( struct V_2 * V_11 )
{
}
static inline void F_9 ( int V_5 ,
struct V_12 * V_13 )
{
T_2 V_14 ;
F_10 ( V_5 , V_13 ) ;
F_11 ( V_5 , F_12 ( V_15 ) ) ;
F_13 ( V_5 ) |= V_16 | V_17 | V_18 ;
V_14 = F_13 ( V_5 ) ;
}
int T_3 F_14 ( void )
{
struct V_2 * V_7 ;
struct V_12 * V_19 ;
unsigned int V_4 = F_2 () ;
V_7 = & F_8 ( V_8 , V_4 ) ;
if ( V_4 == 0 ) {
F_3 () ;
V_7 -> V_5 = V_20 ;
} else {
F_5 () ;
V_7 -> V_5 = V_21 ;
}
V_7 -> V_22 = L_1 ;
V_7 -> V_23 = V_24 ;
F_15 ( V_7 , V_25 , 1 ) ;
V_7 -> V_26 = F_16 ( V_27 , V_7 ) ;
V_7 -> V_28 = F_16 ( 100 , V_7 ) ;
V_7 -> V_29 = 200 ;
V_7 -> V_30 = F_17 ( F_2 () ) ;
V_7 -> V_9 = V_9 ;
V_7 -> V_31 = F_1 ;
V_19 = & F_8 ( V_32 , V_4 ) ;
V_19 -> V_33 = V_34 | V_35 ;
V_19 -> V_36 = F_7 ;
F_18 ( V_7 ) ;
#if F_19 ( V_37 ) && ! F_19 ( V_38 )
{
struct V_39 * V_40 ;
V_40 = F_20 ( V_7 -> V_5 ) ;
F_21 ( F_22 ( V_40 ) , F_17 ( V_4 ) ) ;
V_19 -> V_33 |= V_41 ;
}
#endif
if ( V_4 == 0 ) {
F_4 ( V_42 - 1 ) ;
V_19 -> V_22 = L_2 ;
} else {
F_6 ( V_42 - 1 ) ;
V_19 -> V_22 = L_3 ;
}
F_9 ( V_7 -> V_5 , V_19 ) ;
return 0 ;
}
