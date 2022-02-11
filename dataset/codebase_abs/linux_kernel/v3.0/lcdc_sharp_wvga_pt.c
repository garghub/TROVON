static void F_1 ( T_1 V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < 8 ; V_2 ++ ) {
if ( V_1 & V_3 [ V_2 ] )
F_2 ( V_4 , 1 ) ;
else
F_2 ( V_4 , 0 ) ;
F_2 ( V_5 , 1 ) ;
F_2 ( V_5 , 0 ) ;
}
}
static void F_3 ( T_1 V_6 , T_1 V_7 )
{
F_2 ( V_8 , 0 ) ;
F_4 ( 1 ) ;
F_1 ( V_6 ) ;
F_2 ( V_4 , 0 ) ;
F_4 ( 1 ) ;
F_1 ( V_7 ) ;
F_2 ( V_4 , 0 ) ;
F_2 ( V_8 , 1 ) ;
}
static void F_5 ( void )
{
V_5 = * ( V_9 -> V_10 ) ;
V_8 = * ( V_9 -> V_10 + 1 ) ;
V_4 = * ( V_9 -> V_10 + 2 ) ;
V_11 = * ( V_9 -> V_10 + 3 ) ;
F_2 ( V_5 , 0 ) ;
F_2 ( V_4 , 0 ) ;
F_2 ( V_8 , 1 ) ;
}
static void F_6 ( void )
{
if ( ! V_12 . V_13 && ! V_12 . V_14 )
V_12 . V_13 = TRUE ;
}
static void F_7 ( void )
{
int V_2 ;
if ( V_12 . V_13 && ! V_12 . V_14 ) {
for ( V_2 = 0 ; V_2 < F_8 ( V_15 ) ; V_2 ++ ) {
F_3 ( V_15 [ V_2 ] . V_16 ,
V_15 [ V_2 ] . V_7 ) ;
}
F_9 ( 10 ) ;
F_3 ( 31 , 0xC1 ) ;
F_9 ( 10 ) ;
F_3 ( 31 , 0xD9 ) ;
F_3 ( 31 , 0xDF ) ;
V_12 . V_14 = TRUE ;
}
}
static int F_10 ( struct V_17 * V_18 )
{
if ( ! V_12 . V_19 ) {
V_9 -> V_20 ( 1 ) ;
F_5 () ;
F_6 () ;
F_7 () ;
V_12 . V_19 = TRUE ;
}
return 0 ;
}
static int F_11 ( struct V_17 * V_18 )
{
if ( V_12 . V_13 && V_12 . V_14 ) {
F_3 ( 4 , 0x00 ) ;
F_9 ( 40 ) ;
F_3 ( 31 , 0xC1 ) ;
F_9 ( 40 ) ;
F_3 ( 31 , 0x00 ) ;
F_9 ( 100 ) ;
V_12 . V_14 = FALSE ;
V_12 . V_19 = FALSE ;
}
return 0 ;
}
static int T_2 F_12 ( struct V_17 * V_18 )
{
if ( V_18 -> V_21 == 0 ) {
V_9 = V_18 -> V_22 . V_23 ;
return 0 ;
}
F_13 ( V_18 ) ;
return 0 ;
}
static int T_2 F_14 ( void )
{
int V_24 ;
struct V_25 * V_26 ;
#ifdef F_15
if ( F_16 ( L_1 ) )
return 0 ;
#endif
V_24 = F_17 ( & V_27 ) ;
if ( V_24 )
return V_24 ;
V_26 = & V_28 . V_29 ;
V_26 -> V_30 = 480 ;
V_26 -> V_31 = 800 ;
V_26 -> type = V_32 ;
V_26 -> V_33 = V_34 ;
V_26 -> V_35 = 0 ;
V_26 -> V_36 = 18 ;
V_26 -> V_37 = 2 ;
V_26 -> V_38 = 24500000 ;
V_26 -> V_39 = 4 ;
V_26 -> V_40 = 1 ;
V_26 -> V_41 . V_42 = 20 ;
V_26 -> V_41 . V_43 = 10 ;
V_26 -> V_41 . V_44 = 10 ;
V_26 -> V_41 . V_45 = 2 ;
V_26 -> V_41 . V_46 = 2 ;
V_26 -> V_41 . V_47 = 2 ;
V_26 -> V_41 . V_48 = 0 ;
V_26 -> V_41 . V_49 = 0xff ;
V_26 -> V_41 . V_50 = 0 ;
V_24 = F_18 ( & V_51 ) ;
if ( V_24 )
F_19 ( & V_27 ) ;
return V_24 ;
}
