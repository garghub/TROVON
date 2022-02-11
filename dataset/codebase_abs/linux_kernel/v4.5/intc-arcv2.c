void F_1 ( void )
{
unsigned int V_1 ;
struct V_2 {
#ifdef F_2
unsigned int V_3 : 3 , V_4 : 1 , V_5 : 4 , V_6 : 8 , V_7 : 8 , V_8 : 8 ;
#else
unsigned int V_8 : 8 , V_7 : 8 , V_6 : 8 , V_5 : 4 , V_4 : 1 , V_3 : 3 ;
#endif
} V_9 ;
struct V_10 {
#ifdef F_2
unsigned int V_11 : 18 , V_12 : 1 , V_13 : 1 ,
V_14 : 1 , V_15 : 1 , V_16 : 1 ,
V_17 : 4 , V_18 : 5 ;
#else
unsigned int V_18 : 5 , V_17 : 4 ,
V_16 : 1 , V_15 : 1 , V_14 : 1 ,
V_13 : 1 , V_12 : 1 , V_11 : 18 ;
#endif
} V_19 ;
* ( unsigned int * ) & V_19 = 0 ;
V_19 . V_18 = 6 ;
V_19 . V_16 = 1 ;
V_19 . V_15 = 1 ;
V_19 . V_14 = 0 ;
V_19 . V_12 = 1 ;
F_3 ( V_20 , V_19 ) ;
F_4 ( V_21 , V_9 ) ;
V_22 = V_9 . V_5 ;
F_5 ( L_1 ,
V_22 + 1 , V_22 ,
V_9 . V_4 ? L_2 : L_3 ) ;
V_1 = F_6 ( 0xa ) ;
V_1 |= V_23 | ( V_22 << 1 ) ;
V_1 &= ~ V_24 ;
asm volatile("flag %0 \n"::"r"(tmp));
}
static void F_7 ( struct V_25 * V_26 )
{
F_8 ( V_27 , V_26 -> V_28 ) ;
F_8 ( V_29 , 0 ) ;
}
static void F_9 ( struct V_25 * V_26 )
{
F_8 ( V_27 , V_26 -> V_28 ) ;
F_8 ( V_29 , 1 ) ;
}
void F_10 ( struct V_25 * V_26 )
{
F_8 ( V_27 , V_26 -> V_28 ) ;
F_8 ( V_30 , V_22 ) ;
F_8 ( V_29 , 1 ) ;
}
static int F_11 ( struct V_31 * V_32 , unsigned int V_28 ,
T_1 V_33 )
{
if ( V_33 < 24 ) {
F_12 ( V_28 ) ;
F_13 ( V_28 , & V_34 , V_35 ) ;
} else {
F_13 ( V_28 , & V_34 , V_36 ) ;
}
return 0 ;
}
static int T_2
F_14 ( struct V_37 * V_38 , struct V_37 * V_39 )
{
if ( V_39 )
F_15 ( L_4 ) ;
V_40 = F_16 ( V_38 , V_41 , 0 , 0 ,
& V_42 , NULL ) ;
if ( ! V_40 )
F_15 ( L_5 ) ;
F_17 ( V_40 ) ;
return 0 ;
}
