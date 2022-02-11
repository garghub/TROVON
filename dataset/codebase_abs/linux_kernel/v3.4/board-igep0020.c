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
static void T_1 F_10 ( void )
{
T_2 V_9 = 0 ;
T_2 V_10 = V_11 + 1 ;
for ( V_9 = 0 ; V_9 < V_11 ; V_9 ++ ) {
T_3 V_1 ;
V_1 = F_11 ( V_9 , V_12 ) ;
if ( ( V_1 & 0xC00 ) == 0x800 )
F_6 ( L_6 ) ;
else {
V_1 = F_11 ( V_9 , V_13 ) ;
if ( ( V_1 & 0x3F ) == ( V_14 >> 24 ) )
V_10 = V_9 ;
}
}
if ( V_10 > V_11 ) {
F_6 ( L_7 ) ;
return;
}
V_15 . V_9 = V_10 ;
if ( F_12 ( & V_16 ) < 0 )
F_6 ( L_8 ) ;
}
static void T_1 F_10 ( void ) {}
static inline void T_1 F_13 ( void )
{
F_14 ( & V_17 ) ;
}
static inline void T_1 F_13 ( void ) { }
static void T_1 F_15 ( void )
{
if ( F_16 () ) {
V_18 [ 0 ] . V_19 = V_20 ;
V_18 [ 1 ] . V_19 = V_21 ;
V_18 [ 2 ] . V_19 = V_4 ;
} else {
V_18 [ 0 ] . V_19 = V_22 ;
V_18 [ 1 ] . V_19 = V_23 ;
V_18 [ 2 ] . V_19 = V_24 ;
}
F_12 ( & V_25 ) ;
}
static inline void F_15 ( void )
{
int V_26 ;
if ( F_16 () ) {
V_18 [ 0 ] . V_19 = V_20 ;
V_18 [ 1 ] . V_19 = V_21 ;
V_18 [ 2 ] . V_19 = V_4 ;
} else {
V_18 [ 0 ] . V_19 = V_22 ;
V_18 [ 1 ] . V_19 = V_23 ;
V_18 [ 2 ] . V_19 = V_24 ;
}
if ( F_17 ( V_18 , F_18 ( V_18 ) ) ) {
F_5 ( L_9 ) ;
return;
}
for ( V_26 = 0 ; V_26 < F_18 ( V_18 ) ; V_26 ++ )
F_19 ( V_18 [ V_26 ] . V_19 , 0 ) ;
}
static int F_20 ( struct V_27 * V_28 ,
unsigned V_19 , unsigned V_29 )
{
int V_1 ;
V_30 [ 0 ] . V_31 = V_19 + 0 ;
F_21 ( V_30 ) ;
#if ! F_22 ( V_32 ) && ! F_22 ( V_33 )
V_1 = F_4 ( V_19 + V_34 + 1 , V_35 ,
L_10 ) ;
if ( V_1 == 0 )
F_19 ( V_19 + V_34 + 1 , 0 ) ;
else
F_5 ( L_11 ) ;
#else
V_18 [ 3 ] . V_19 = V_19 + V_34 + 1 ;
#endif
if ( F_2 () )
return 0 ;
V_36 [ 0 ] . V_19 = V_19 + 1 ;
V_36 [ 1 ] . V_19 = V_19 + V_34 ;
V_1 = F_17 ( V_36 , F_18 ( V_36 ) ) ;
if ( V_1 < 0 )
F_6 ( L_12 ) ;
return 0 ;
}
static int F_23 ( struct V_37 * V_38 )
{
F_24 ( V_39 , 1 ) ;
return 0 ;
}
static void F_25 ( struct V_37 * V_38 )
{
F_24 ( V_39 , 0 ) ;
}
static void T_1 F_26 ( void )
{
int V_40 = F_4 ( V_39 , V_35 ,
L_13 ) ;
if ( V_40 )
F_6 ( L_14 ) ;
}
static void T_1 F_27 ( void )
{
int V_1 ;
F_28 ( & V_41 , V_42 , 0 ) ;
if ( F_16 () ) {
V_1 = F_29 ( 3 , 100 , V_43 ,
F_18 ( V_43 ) ) ;
if ( V_1 )
F_5 ( L_15 , V_1 ) ;
V_41 . V_44 = & V_45 ;
F_28 ( & V_41 , V_46 ,
V_47 ) ;
V_41 . V_48 -> V_49 . V_50 = true ;
V_41 . V_48 -> V_49 . V_51 = L_16 ;
}
F_30 ( L_17 , & V_41 ) ;
}
static void T_1 F_31 ( void )
{
int V_40 ;
if ( V_2 == V_8 ) {
V_52 [ 0 ] . V_19 = V_53 ;
V_52 [ 1 ] . V_19 = V_54 ;
V_52 [ 2 ] . V_19 = V_55 ;
} else if ( V_2 == V_7 || F_2 () ) {
V_52 [ 0 ] . V_19 = V_56 ;
V_52 [ 1 ] . V_19 = V_57 ;
V_52 [ 2 ] . V_19 = V_58 ;
} else
return;
V_40 = F_17 ( V_52 ,
F_18 ( V_52 ) ) ;
if ( V_40 ) {
F_5 ( L_18 ) ;
return;
}
F_19 ( V_52 [ 0 ] . V_19 , 0 ) ;
F_19 ( V_52 [ 1 ] . V_19 , 0 ) ;
F_19 ( V_52 [ 2 ] . V_19 , 0 ) ;
F_32 ( V_52 [ 1 ] . V_19 , 0 ) ;
F_33 ( 10 ) ;
F_32 ( V_52 [ 1 ] . V_19 , 1 ) ;
}
static inline void T_1 F_31 ( void ) { }
static void T_1 F_34 ( void )
{
F_35 ( 1 , V_59 , F_18 ( V_59 ) ) ;
F_36 ( V_60 , V_61 ) ;
F_1 () ;
F_37 ( V_30 ) ;
F_27 () ;
F_38 ( V_62 , F_18 ( V_62 ) ) ;
F_39 () ;
F_40 ( V_63 ,
V_63 ) ;
F_41 ( NULL ) ;
F_10 () ;
F_15 () ;
F_31 () ;
if ( F_16 () ) {
F_42 ( & V_64 ) ;
F_26 () ;
F_13 () ;
F_43 ( & V_65 ) ;
} else {
F_43 ( & V_66 ) ;
}
}
