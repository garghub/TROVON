void F_1 ( void )
{
unsigned int V_1 , V_2 , V_3 ;
struct V_4 V_5 ;
struct V_6 {
#ifdef F_2
unsigned int V_7 : 18 , V_8 : 1 , V_9 : 1 ,
V_10 : 1 , V_11 : 1 , V_12 : 1 ,
V_13 : 4 , V_14 : 5 ;
#else
unsigned int V_14 : 5 , V_13 : 4 ,
V_12 : 1 , V_11 : 1 , V_10 : 1 ,
V_9 : 1 , V_8 : 1 , V_7 : 18 ;
#endif
} V_15 ;
* ( unsigned int * ) & V_15 = 0 ;
V_15 . V_14 = 6 ;
V_15 . V_12 = 1 ;
V_15 . V_11 = 1 ;
V_15 . V_10 = 0 ;
V_15 . V_8 = 1 ;
F_3 ( V_16 , V_15 ) ;
F_4 ( V_17 , V_5 ) ;
V_2 = V_5 . V_18 ;
F_5 ( L_1 ,
V_2 + 1 , V_19 ,
V_5 . V_20 ? L_2 : L_3 ) ;
for ( V_3 = V_21 ; V_3 < V_5 . V_22 + V_21 ; V_3 ++ ) {
F_6 ( V_23 , V_3 ) ;
F_6 ( V_24 , V_19 ) ;
if ( V_3 < V_25 )
F_6 ( V_26 , 0 ) ;
}
V_1 = F_7 ( V_27 ) ;
V_1 |= V_28 | ( V_19 << 1 ) ;
V_1 &= ~ V_29 ;
asm volatile("kflag %0 \n"::"r"(tmp));
}
static void F_8 ( struct V_30 * V_31 )
{
F_6 ( V_23 , V_31 -> V_32 ) ;
F_6 ( V_26 , 0 ) ;
}
static void F_9 ( struct V_30 * V_31 )
{
F_6 ( V_23 , V_31 -> V_32 ) ;
F_6 ( V_26 , 1 ) ;
}
void F_10 ( struct V_30 * V_31 )
{
F_6 ( V_23 , V_31 -> V_32 ) ;
F_6 ( V_24 , V_19 ) ;
F_6 ( V_26 , 1 ) ;
}
static int F_11 ( struct V_33 * V_34 , unsigned int V_35 ,
T_1 V_36 )
{
if ( V_36 < V_25 ) {
F_12 ( V_35 ) ;
F_13 ( V_35 , & V_37 , V_38 ) ;
} else {
F_13 ( V_35 , & V_37 , V_39 ) ;
}
return 0 ;
}
static int T_2
F_14 ( struct V_40 * V_41 , struct V_40 * V_42 )
{
struct V_33 * V_43 ;
struct V_4 V_5 ;
unsigned int V_44 ;
F_4 ( V_17 , V_5 ) ;
V_44 = V_5 . V_22 + V_21 ;
if ( V_42 )
F_15 ( L_4 ) ;
V_43 = F_16 ( V_41 , V_44 , & V_45 , NULL ) ;
if ( ! V_43 )
F_15 ( L_5 ) ;
F_17 ( V_43 ) ;
#ifdef F_18
F_19 ( V_43 , V_46 ) ;
#endif
F_19 ( V_43 , V_47 ) ;
return 0 ;
}
