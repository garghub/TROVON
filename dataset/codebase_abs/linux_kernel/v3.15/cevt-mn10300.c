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
static void F_7 ( enum V_5 V_6 ,
struct V_2 * V_3 )
{
}
static T_1 F_8 ( int V_7 , void * V_8 )
{
struct V_2 * V_9 ;
unsigned int V_4 = F_2 () ;
if ( V_4 == 0 )
F_3 () ;
else
F_5 () ;
V_9 = & F_9 ( V_10 , V_4 ) ;
V_9 -> V_11 ( V_9 ) ;
return V_12 ;
}
static void V_11 ( struct V_2 * V_13 )
{
}
static inline void F_10 ( int V_7 ,
struct V_14 * V_15 )
{
T_2 V_16 ;
F_11 ( V_7 , V_15 ) ;
F_12 ( V_7 , F_13 ( V_17 ) ) ;
F_14 ( V_7 ) |= V_18 | V_19 | V_20 ;
V_16 = F_14 ( V_7 ) ;
}
int T_3 F_15 ( void )
{
struct V_2 * V_9 ;
struct V_14 * V_21 ;
unsigned int V_4 = F_2 () ;
V_9 = & F_9 ( V_10 , V_4 ) ;
if ( V_4 == 0 ) {
F_3 () ;
V_9 -> V_7 = V_22 ;
} else {
F_5 () ;
V_9 -> V_7 = V_23 ;
}
V_9 -> V_24 = L_1 ;
V_9 -> V_25 = V_26 ;
F_16 ( V_9 , V_27 , 1 ) ;
V_9 -> V_28 = F_17 ( V_29 , V_9 ) ;
V_9 -> V_30 = F_17 ( 100 , V_9 ) ;
V_9 -> V_31 = 200 ;
V_9 -> V_32 = F_18 ( F_2 () ) ;
V_9 -> V_33 = F_7 ;
V_9 -> V_11 = V_11 ;
V_9 -> V_34 = F_1 ;
V_21 = & F_9 ( V_35 , V_4 ) ;
V_21 -> V_36 = V_37 | V_38 ;
V_21 -> V_39 = F_8 ;
F_19 ( V_9 ) ;
#if F_20 ( V_40 ) && ! F_20 ( V_41 )
{
struct V_42 * V_43 ;
V_43 = F_21 ( V_9 -> V_7 ) ;
F_22 ( V_43 -> V_44 , F_18 ( V_4 ) ) ;
V_21 -> V_36 |= V_45 ;
}
#endif
if ( V_4 == 0 ) {
F_4 ( V_46 - 1 ) ;
V_21 -> V_24 = L_2 ;
} else {
F_6 ( V_46 - 1 ) ;
V_21 -> V_24 = L_3 ;
}
F_10 ( V_9 -> V_7 , V_21 ) ;
return 0 ;
}
