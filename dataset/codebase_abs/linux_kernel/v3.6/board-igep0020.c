static void T_1 F_1 ( void )
{
T_2 V_1 ;
if ( F_2 () ) {
V_2 = V_3 ;
return;
}
F_3 ( V_4 , V_5 ) ;
if ( F_4 ( V_4 , V_6 , L_1 ) ) {
F_5 ( L_2 ) ;
F_6 ( L_3 ) ;
return;
}
V_1 = F_7 ( V_4 ) ;
if ( V_1 == 0 ) {
F_8 ( L_4 ) ;
V_2 = V_7 ;
} else if ( V_1 == 1 ) {
F_8 ( L_5 ) ;
V_2 = V_8 ;
} else {
F_6 ( L_3 ) ;
V_2 = - 1 ;
}
F_9 ( V_4 ) ;
}
static inline T_3 F_10 ( void )
{
return F_11 ( V_9 ) & V_10 ;
}
static void T_1 F_12 ( void )
{
T_3 V_11 ;
V_11 = F_10 () ;
if ( V_11 == V_12 ) {
F_8 ( L_6 ) ;
F_13 ( V_13 ,
F_14 ( V_13 ) ,
0 , V_14 ) ;
} else if ( V_11 == V_15 ) {
F_8 ( L_7 ) ;
F_15 ( V_13 ,
F_14 ( V_13 ) , 0 ) ;
} else {
F_6 ( L_8 ) ;
}
}
static void T_1 F_12 ( void ) {}
static inline void T_1 F_16 ( void )
{
F_17 ( & V_16 ) ;
}
static inline void T_1 F_16 ( void ) { }
static void T_1 F_18 ( void )
{
if ( F_19 () ) {
V_17 [ 0 ] . V_18 = V_19 ;
V_17 [ 1 ] . V_18 = V_20 ;
V_17 [ 2 ] . V_18 = V_4 ;
} else {
V_17 [ 0 ] . V_18 = V_21 ;
V_17 [ 1 ] . V_18 = V_22 ;
V_17 [ 2 ] . V_18 = V_23 ;
}
F_20 ( & V_24 ) ;
}
static inline void F_18 ( void )
{
int V_25 ;
if ( F_19 () ) {
V_17 [ 0 ] . V_18 = V_19 ;
V_17 [ 1 ] . V_18 = V_20 ;
V_17 [ 2 ] . V_18 = V_4 ;
} else {
V_17 [ 0 ] . V_18 = V_21 ;
V_17 [ 1 ] . V_18 = V_22 ;
V_17 [ 2 ] . V_18 = V_23 ;
}
if ( F_21 ( V_17 , F_14 ( V_17 ) ) ) {
F_5 ( L_9 ) ;
return;
}
for ( V_25 = 0 ; V_25 < F_14 ( V_17 ) ; V_25 ++ )
F_22 ( V_17 [ V_25 ] . V_18 , 0 ) ;
}
static int F_23 ( struct V_26 * V_27 ,
unsigned V_18 , unsigned V_28 )
{
int V_1 ;
V_29 [ 0 ] . V_30 = V_18 + 0 ;
F_24 ( V_29 ) ;
#if ! F_25 ( V_31 ) && ! F_25 ( V_32 )
V_1 = F_4 ( V_18 + V_33 + 1 , V_34 ,
L_10 ) ;
if ( V_1 == 0 )
F_22 ( V_18 + V_33 + 1 , 0 ) ;
else
F_5 ( L_11 ) ;
#else
V_17 [ 3 ] . V_18 = V_18 + V_33 + 1 ;
#endif
if ( F_2 () )
return 0 ;
V_35 [ 0 ] . V_18 = V_18 + 1 ;
V_35 [ 1 ] . V_18 = V_18 + V_33 ;
V_1 = F_21 ( V_35 , F_14 ( V_35 ) ) ;
if ( V_1 < 0 )
F_6 ( L_12 ) ;
return 0 ;
}
static void T_1 F_26 ( void )
{
int V_1 ;
F_27 ( & V_36 , V_37 ,
V_38 ) ;
V_36 . V_39 -> V_40 . V_41 = true ;
V_36 . V_39 -> V_40 . V_42 = L_13 ;
if ( F_19 () ) {
V_1 = F_28 ( 3 , 100 , V_43 ,
F_14 ( V_43 ) ) ;
if ( V_1 )
F_5 ( L_14 , V_1 ) ;
V_36 . V_44 = & V_45 ;
F_27 ( & V_36 , V_46 , 0 ) ;
}
F_29 ( L_15 , & V_36 ) ;
}
static void T_1 F_30 ( void )
{
int V_47 ;
if ( V_2 == V_8 ) {
V_48 [ 0 ] . V_18 = V_49 ;
V_48 [ 1 ] . V_18 = V_50 ;
V_48 [ 2 ] . V_18 = V_51 ;
} else if ( V_2 == V_7 || F_2 () ) {
V_48 [ 0 ] . V_18 = V_52 ;
V_48 [ 1 ] . V_18 = V_53 ;
V_48 [ 2 ] . V_18 = V_54 ;
} else
return;
V_47 = F_21 ( V_48 ,
F_14 ( V_48 ) ) ;
if ( V_47 ) {
F_5 ( L_16 ) ;
return;
}
F_22 ( V_48 [ 0 ] . V_18 , 0 ) ;
F_22 ( V_48 [ 1 ] . V_18 , 0 ) ;
F_22 ( V_48 [ 2 ] . V_18 , 0 ) ;
F_31 ( V_48 [ 1 ] . V_18 , 0 ) ;
F_32 ( 10 ) ;
F_31 ( V_48 [ 1 ] . V_18 , 1 ) ;
}
static inline void T_1 F_30 ( void ) { }
static void T_1 F_33 ( void )
{
F_34 ( 1 , V_55 , F_14 ( V_55 ) ) ;
F_35 ( V_56 , V_57 ) ;
F_1 () ;
F_36 ( V_29 ) ;
F_26 () ;
F_37 ( V_58 , F_14 ( V_58 ) ) ;
F_38 () ;
F_39 ( V_59 ,
V_59 ) ;
F_40 ( NULL ) ;
F_12 () ;
F_18 () ;
F_30 () ;
if ( F_19 () ) {
F_41 ( & V_60 ) ;
F_16 () ;
F_42 ( & V_61 ) ;
} else {
F_42 ( & V_62 ) ;
}
}
