static void F_1 ( void )
{
struct V_1 * V_2 ;
struct V_1 * V_3 ;
struct V_4 * V_5 ;
struct V_4 * V_6 ;
V_5 = V_7 ;
while ( V_5 ) {
V_2 = V_5 -> V_8 ;
while ( V_2 ) {
V_3 = V_2 -> V_9 ;
F_2 ( V_2 -> V_10 ) ;
F_2 ( V_2 -> V_11 ) ;
F_2 ( V_2 ) ;
V_2 = V_3 ;
}
V_6 = V_5 -> V_9 ;
F_2 ( V_5 ) ;
V_5 = V_6 ;
}
}
T_1 F_3 ( void )
{
T_1 V_12 ;
T_2 V_13 ;
F_4 ( V_14 ) ;
V_12 = F_5 () ;
if ( F_6 ( V_12 ) ) {
F_7 ( V_12 ) ;
}
for ( V_13 = 0 ; V_13 < V_15 ; V_13 ++ ) {
V_16 [ V_13 ] = NULL ;
}
for ( V_13 = 0 ; V_13 < V_17 ; V_13 ++ ) {
V_18 [ V_13 ] . V_19 = NULL ;
V_18 [ V_13 ] . V_20 = V_21 ;
V_18 [ V_13 ] . V_22 = 0 ;
}
for ( V_13 = 0 ; V_13 < V_23 ; V_13 ++ ) {
V_24 [ V_13 ] = 0 ;
}
V_24 [ V_23 - 1 ] = 0x80000000 ;
V_25 = 0 ;
V_26 = 0 ;
V_27 = 0 ;
for ( V_13 = 0 ; V_13 < V_28 ; V_13 ++ ) {
V_29 [ V_13 ] = 0 ;
}
#if ( ! V_30 )
V_31 = FALSE ;
V_7 = NULL ;
V_32 [ 0 ] = NULL ;
V_32 [ 1 ] = NULL ;
V_33 = 0 ;
V_34 = NULL ;
V_35 = NULL ;
#endif
V_36 [ 0 ] . V_37 = NULL ;
V_36 [ 1 ] . V_37 = NULL ;
V_38 = NULL ;
V_39 = NULL ;
V_40 = NULL ;
V_41 = NULL ;
V_42 = NULL ;
V_43 = NULL ;
V_44 = FALSE ;
V_45 = 0 ;
V_46 = FALSE ;
V_47 = NULL ;
V_48 = FALSE ;
V_49 = FALSE ;
V_50 = 0 ;
V_51 = 0 ;
V_52 = TRUE ;
V_53 = 0 ;
V_54 = 0 ;
V_55 = V_56 ;
V_57 = NULL ;
V_58 = 0xFFFF ;
V_59 = FALSE ;
V_60 = TRUE ;
V_61 = NULL ;
V_62 = NULL ;
V_63 . V_64 . integer = V_65 ;
V_63 . V_66 = V_67 ;
V_63 . type = V_68 ;
V_63 . V_69 = NULL ;
V_63 . V_70 = NULL ;
V_63 . V_71 = NULL ;
V_63 . V_72 = NULL ;
#ifdef F_8
V_73 = NULL ;
V_74 = 0 ;
V_75 = 0 ;
#endif
#ifdef F_9
V_76 = F_10 ( V_77 , V_78 ) ;
#endif
#ifdef F_11
V_79 = FALSE ;
V_80 = FALSE ;
#endif
F_7 ( V_81 ) ;
}
static void F_12 ( void )
{
F_4 ( V_82 ) ;
F_1 () ;
F_13 () ;
V_83 ;
}
void F_14 ( void )
{
F_4 ( V_84 ) ;
if ( V_49 ) {
F_15 ( ( V_85 , L_1 ) ) ;
V_83 ;
}
V_49 = TRUE ;
V_86 = 0 ;
F_16 ( ( V_87 , L_2 ) ) ;
#ifndef F_17
F_18 () ;
F_19 () ;
#endif
F_20 () ;
F_21 () ;
F_12 () ;
( void ) F_22 () ;
V_83 ;
}
