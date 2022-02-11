static void F_1 ( struct V_1 * V_2 , int V_3 )
{
unsigned long V_4 ;
V_4 = F_2 ( V_5 ) ;
if ( V_3 ) {
V_4 |= 1 ;
} else {
V_4 &= ~ 1 ;
}
F_3 ( V_4 , V_5 ) ;
}
static int T_1 F_4 ( void )
{
struct V_6 * V_7 , * V_8 ;
struct V_9 * V_10 ;
T_2 V_11 ;
V_7 = F_5 ( V_12 ,
V_13 , NULL ) ;
V_8 = F_5 ( V_12 ,
V_14 , NULL ) ;
F_6 ( V_7 ) ;
if ( ! V_7 || ! V_8 ) {
F_7 ( V_15 L_1 ) ;
F_6 ( V_8 ) ;
return - V_16 ;
}
V_17 . V_18 = F_8 ( V_19 , V_20 ) ;
if ( ! V_17 . V_18 ) {
F_7 ( V_21 L_2 ) ;
F_6 ( V_8 ) ;
return - V_22 ;
}
F_9 ( & V_17 ) ;
F_7 ( V_15 L_3 , ( unsigned long ) V_17 . V_18 ) ;
V_10 = & V_8 -> V_9 [ V_23 ] ;
if ( ! ( V_10 -> V_24 & V_25 ) ) {
V_10 -> V_26 = L_4 ;
V_10 -> V_27 = 0 ;
V_10 -> V_28 = 63 ;
V_10 -> V_24 = V_25 ;
F_10 ( V_8 , 0x40 , & V_29 ) ;
V_29 &= ~ 1 ;
V_10 -> V_27 += V_29 & ~ 1 ;
V_10 -> V_28 += V_29 & ~ 1 ;
F_6 ( V_8 ) ;
if ( F_11 ( V_8 , V_23 ) != 0 ) {
F_6 ( V_7 ) ;
F_6 ( V_8 ) ;
F_7 ( V_21 L_5 ) ;
F_12 ( V_17 . V_18 ) ;
return - V_30 ;
}
}
V_29 = V_10 -> V_27 ;
F_13 ( V_8 , 0x40 , V_29 | 1 ) ;
F_14 ( V_7 , 0x4e , & V_11 ) ;
V_11 |= 0x4 ;
F_15 ( V_7 , 0x4e , V_11 ) ;
F_1 ( & V_17 , 1 ) ;
F_16 ( F_17 ( V_31 ) & ~ 1 , V_31 ) ;
F_7 ( V_15 L_6 ) ;
V_32 = F_18 ( L_7 , & V_17 ) ;
if ( ! V_32 ) {
F_7 ( V_15 L_8 ) ;
V_32 = F_18 ( L_9 , & V_17 ) ;
}
if ( V_32 ) {
V_32 -> V_33 = V_34 ;
F_19 ( V_32 , NULL , 0 ) ;
return 0 ;
}
F_12 ( V_17 . V_18 ) ;
return - V_30 ;
}
static void T_3 F_20 ( void )
{
F_21 ( V_32 ) ;
F_22 ( V_32 ) ;
F_12 ( V_17 . V_18 ) ;
}
