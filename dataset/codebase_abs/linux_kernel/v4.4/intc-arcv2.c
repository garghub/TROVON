void F_1 ( void )
{
unsigned int V_1 ;
struct V_2 {
#ifdef F_2
unsigned int V_3 : 18 , V_4 : 1 , V_5 : 1 ,
V_6 : 1 , V_7 : 1 , V_8 : 1 ,
V_9 : 4 , V_10 : 5 ;
#else
unsigned int V_10 : 5 , V_9 : 4 ,
V_8 : 1 , V_7 : 1 , V_6 : 1 ,
V_5 : 1 , V_4 : 1 , V_3 : 18 ;
#endif
} V_11 ;
* ( unsigned int * ) & V_11 = 0 ;
V_11 . V_10 = 6 ;
V_11 . V_8 = 1 ;
V_11 . V_7 = 1 ;
V_11 . V_6 = 0 ;
V_11 . V_4 = 1 ;
F_3 ( V_12 , V_11 ) ;
V_1 = F_4 ( 0xa ) ;
V_1 |= V_13 ;
V_1 &= ~ V_14 ;
asm volatile("flag %0 \n"::"r"(tmp));
V_1 = ( F_4 ( V_15 ) >> 24 ) & 0xF ;
if ( V_16 > V_1 )
F_5 ( L_1 ) ;
}
static void F_6 ( struct V_17 * V_18 )
{
F_7 ( V_19 , V_18 -> V_20 ) ;
F_7 ( V_21 , 0 ) ;
}
static void F_8 ( struct V_17 * V_18 )
{
F_7 ( V_19 , V_18 -> V_20 ) ;
F_7 ( V_21 , 1 ) ;
}
void F_9 ( struct V_17 * V_18 )
{
F_7 ( V_19 , V_18 -> V_20 ) ;
F_7 ( V_22 , V_16 ) ;
F_7 ( V_21 , 1 ) ;
}
static int F_10 ( struct V_23 * V_24 , unsigned int V_20 ,
T_1 V_25 )
{
if ( V_25 < 24 ) {
F_11 ( V_20 ) ;
F_12 ( V_20 , & V_26 , V_27 ) ;
} else {
F_12 ( V_20 , & V_26 , V_28 ) ;
}
return 0 ;
}
static int T_2
F_13 ( struct V_29 * V_30 , struct V_29 * V_31 )
{
if ( V_31 )
F_5 ( L_2 ) ;
V_32 = F_14 ( V_30 , V_33 , 0 , 0 ,
& V_34 , NULL ) ;
if ( ! V_32 )
F_5 ( L_3 ) ;
F_15 ( V_32 ) ;
return 0 ;
}
