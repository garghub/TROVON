void F_1 ( void )
{
unsigned int V_1 , V_2 ;
struct V_3 {
#ifdef F_2
unsigned int V_4 : 3 , V_5 : 1 , V_6 : 4 , V_7 : 8 , V_8 : 8 , V_9 : 8 ;
#else
unsigned int V_9 : 8 , V_8 : 8 , V_7 : 8 , V_6 : 4 , V_5 : 1 , V_4 : 3 ;
#endif
} V_10 ;
struct V_11 {
#ifdef F_2
unsigned int V_12 : 18 , V_13 : 1 , V_14 : 1 ,
V_15 : 1 , V_16 : 1 , V_17 : 1 ,
V_18 : 4 , V_19 : 5 ;
#else
unsigned int V_19 : 5 , V_18 : 4 ,
V_17 : 1 , V_16 : 1 , V_15 : 1 ,
V_14 : 1 , V_13 : 1 , V_12 : 18 ;
#endif
} V_20 ;
* ( unsigned int * ) & V_20 = 0 ;
V_20 . V_19 = 6 ;
V_20 . V_17 = 1 ;
V_20 . V_16 = 1 ;
V_20 . V_15 = 0 ;
V_20 . V_13 = 1 ;
F_3 ( V_21 , V_20 ) ;
F_4 ( V_22 , V_10 ) ;
V_2 = V_10 . V_6 ;
F_5 ( L_1 ,
V_2 + 1 , V_23 ,
V_10 . V_5 ? L_2 : L_3 ) ;
V_1 = F_6 ( 0xa ) ;
V_1 |= V_24 | ( V_23 << 1 ) ;
V_1 &= ~ V_25 ;
asm volatile("kflag %0 \n"::"r"(tmp));
}
static void F_7 ( struct V_26 * V_27 )
{
F_8 ( V_28 , V_27 -> V_29 ) ;
F_8 ( V_30 , 0 ) ;
}
static void F_9 ( struct V_26 * V_27 )
{
F_8 ( V_28 , V_27 -> V_29 ) ;
F_8 ( V_30 , 1 ) ;
}
void F_10 ( struct V_26 * V_27 )
{
F_8 ( V_28 , V_27 -> V_29 ) ;
F_8 ( V_31 , V_23 ) ;
F_8 ( V_30 , 1 ) ;
}
static int F_11 ( struct V_32 * V_33 , unsigned int V_34 ,
T_1 V_35 )
{
if ( V_35 < 24 ) {
F_12 ( V_34 ) ;
F_13 ( V_34 , & V_36 , V_37 ) ;
} else {
F_13 ( V_34 , & V_36 , V_38 ) ;
}
return 0 ;
}
static int T_2
F_14 ( struct V_39 * V_40 , struct V_39 * V_41 )
{
struct V_32 * V_42 ;
if ( V_41 )
F_15 ( L_4 ) ;
V_42 = F_16 ( V_40 , V_43 , & V_44 , NULL ) ;
if ( ! V_42 )
F_15 ( L_5 ) ;
F_17 ( V_42 ) ;
#ifdef F_18
F_19 ( V_42 , V_45 ) ;
#endif
F_19 ( V_42 , V_46 ) ;
return 0 ;
}
