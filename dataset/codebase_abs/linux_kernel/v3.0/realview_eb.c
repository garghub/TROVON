static void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
if ( F_4 () || F_5 () )
F_2 ( V_2 , F_3 ( V_2 ) ) ;
}
static int F_6 ( void )
{
void T_2 * V_3 = F_7 ( V_4 , V_5 ) ;
const char * V_6 = NULL ;
T_3 V_7 ;
if ( ! V_3 )
return - V_8 ;
V_7 = F_8 ( V_3 + 0x50 ) ;
if ( ( V_7 & 0xFFFF0000 ) != 0x01180000 )
V_6 = L_1 ;
F_9 ( V_3 ) ;
return F_10 ( V_6 , V_9 ) ;
}
static void T_1 F_11 ( void )
{
if ( F_4 () || F_5 () ) {
unsigned int V_10 ;
F_12 ( 0x0000a05f , F_13 ( V_11 ) ) ;
V_10 = F_8 ( F_13 ( V_12 ) + V_13 ) ;
V_10 |= 0x00800000 ;
F_12 ( V_10 , F_13 ( V_12 ) + V_13 ) ;
F_12 ( 0x00000000 , F_13 ( V_11 ) ) ;
F_14 ( 0 , 29 , F_13 ( V_14 ) ,
F_13 ( V_15 ) ) ;
#ifndef F_15
F_14 ( 1 , 96 , F_13 ( V_16 ) ,
F_13 ( V_17 ) ) ;
F_16 ( 1 , V_18 ) ;
#endif
} else {
F_14 ( 0 , 29 , F_13 ( V_16 ) ,
F_13 ( V_17 ) ) ;
}
}
static void F_17 ( void )
{
V_19 . V_20 [ 0 ] = V_21 ;
V_22 . V_20 [ 0 ] = V_23 ;
V_24 . V_20 [ 0 ] = V_25 ;
V_26 . V_20 [ 0 ] = V_27 ;
V_28 . V_20 [ 0 ] = V_29 ;
V_30 . V_20 [ 0 ] = V_31 ;
V_32 . V_20 [ 0 ] = V_33 ;
V_34 . V_20 [ 0 ] = V_35 ;
V_36 . V_20 [ 0 ] = V_37 ;
V_38 . V_20 [ 0 ] = V_39 ;
V_40 . V_20 [ 0 ] = V_41 ;
V_42 . V_20 [ 0 ] = V_43 ;
V_44 . V_20 [ 0 ] = V_45 ;
V_46 . V_20 [ 0 ] = V_47 ;
V_48 . V_20 [ 0 ] = V_49 ;
V_48 . V_20 [ 1 ] = V_50 ;
V_51 . V_20 [ 0 ] = V_52 ;
V_53 . V_20 [ 0 ] = V_54 ;
V_9 [ 1 ] . V_55 = V_56 ;
V_9 [ 1 ] . V_57 = V_56 ;
V_58 [ 1 ] . V_55 = V_59 ;
V_58 [ 1 ] . V_57 = V_59 ;
}
static void T_1 F_18 ( void )
{
unsigned int V_60 ;
V_61 = F_13 ( V_62 ) ;
V_63 = F_13 ( V_62 ) + 0x20 ;
V_64 = F_13 ( V_65 ) ;
V_66 = F_13 ( V_65 ) + 0x20 ;
if ( F_4 () || F_5 () ) {
#ifdef F_19
V_67 = F_13 ( V_68 ) ;
#endif
V_60 = V_69 ;
} else
V_60 = V_70 ;
F_20 ( V_60 ) ;
}
static void F_21 ( char V_71 )
{
void T_2 * V_72 = F_13 ( V_73 ) ;
void T_2 * V_74 = F_13 ( V_11 ) ;
F_22 ( V_75 , V_74 ) ;
if ( F_4 () )
F_22 ( 0x0008 , V_72 ) ;
}
static void T_1 F_23 ( void )
{
int V_76 ;
if ( F_4 () || F_5 () ) {
F_17 () ;
#ifdef F_24
F_25 ( F_13 ( V_77 ) , 0x00790000 , 0xfe000fff ) ;
#endif
F_26 ( & V_78 ) ;
}
F_27 ( & V_79 , 1 ) ;
F_26 ( & V_80 ) ;
F_26 ( & V_81 ) ;
F_6 () ;
F_28 ( V_58 ) ;
for ( V_76 = 0 ; V_76 < F_3 ( V_82 ) ; V_76 ++ ) {
struct V_83 * V_84 = V_82 [ V_76 ] ;
F_29 ( V_84 , & V_85 ) ;
}
#ifdef F_30
V_86 = V_87 ;
#endif
V_88 = F_21 ;
}
