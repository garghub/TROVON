static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_2 -> V_5 > 800 || V_2 -> V_6 > 600
|| V_2 -> V_7 > 800 || V_2 -> V_8 > 600
|| ( V_2 -> V_9 != 8 && V_2 -> V_9 != 16 )
|| V_2 -> V_10
|| ( V_2 -> V_11 & V_12 ) != V_13 )
return - V_14 ;
V_2 -> V_5 = V_2 -> V_7 = 800 ;
V_2 -> V_6 = V_2 -> V_8 = 600 ;
return 0 ;
}
static int F_2 ( struct V_3 * V_4 )
{
if ( V_4 -> V_2 . V_9 == 16 ) {
F_3 ( 0x13 , 200 ) ;
F_4 ( 0x81 , 0x14 ) ;
F_4 ( 0x82 , 0x00 ) ;
F_4 ( 0x20 , 0x10 ) ;
V_4 -> V_15 . V_16 = 800 * 2 ;
V_4 -> V_15 . V_17 = V_18 ;
V_4 -> V_2 . V_19 . V_20 = 10 ;
V_4 -> V_2 . V_21 . V_20 = 5 ;
V_4 -> V_2 . V_22 . V_20 = 0 ;
V_4 -> V_2 . V_19 . V_23 = V_4 -> V_2 . V_21 . V_23 =
V_4 -> V_2 . V_22 . V_23 = 5 ;
} else {
F_3 ( 0x13 , 100 ) ;
F_4 ( 0x81 , 0x12 ) ;
F_4 ( 0x82 , 0x08 ) ;
F_4 ( 0x20 , 0x00 ) ;
V_4 -> V_15 . V_16 = 800 ;
V_4 -> V_15 . V_17 = V_24 ;
V_4 -> V_2 . V_19 . V_20 = V_4 -> V_2 . V_21 . V_20 =
V_4 -> V_2 . V_22 . V_20 = 0 ;
V_4 -> V_2 . V_19 . V_23 = V_4 -> V_2 . V_21 . V_23 =
V_4 -> V_2 . V_22 . V_23 = 8 ;
}
return 0 ;
}
static int F_5 ( int V_25 , struct V_3 * V_4 )
{
return 1 ;
}
static int F_6 ( T_1 V_26 , T_1 V_19 , T_1 V_21 , T_1 V_22 ,
T_1 V_27 , struct V_3 * V_4 )
{
if ( V_26 > 255 )
return 1 ;
V_19 >>= 8 ;
V_21 >>= 8 ;
V_22 >>= 8 ;
F_7 ( V_26 , 0x3c8 ) ;
F_8 ( 1 ) ;
F_7 ( V_19 , 0x3c9 ) ;
F_7 ( V_21 , 0x3c9 ) ;
F_7 ( V_22 , 0x3c9 ) ;
return 0 ;
}
static void F_9 ( void )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < F_10 ( V_29 ) ; ++ V_28 )
F_4 ( V_29 [ V_28 ] . V_30 , V_29 [ V_28 ] . V_31 ) ;
F_7 ( 0x29 , 0x3c2 ) ;
for ( V_28 = 0 ; V_28 < F_10 ( V_32 ) ; ++ V_28 )
F_11 ( V_32 [ V_28 ] . V_30 , V_32 [ V_28 ] . V_31 ) ;
for ( V_28 = 0 ; V_28 < F_10 ( V_33 ) ; ++ V_28 )
F_12 ( V_33 [ V_28 ] . V_30 , V_33 [ V_28 ] . V_31 ) ;
for ( V_28 = 0 ; V_28 < F_10 ( V_34 ) ; ++ V_28 )
F_13 ( V_34 [ V_28 ] . V_30 , V_34 [ V_28 ] . V_31 ) ;
for ( V_28 = 0 ; V_28 < F_10 ( V_35 ) ; ++ V_28 )
F_3 ( V_35 [ V_28 ] . V_30 , V_35 [ V_28 ] . V_31 ) ;
for ( V_28 = 0 ; V_28 < F_10 ( V_36 ) ; ++ V_28 )
F_14 ( V_36 [ V_28 ] . V_30 , V_36 [ V_28 ] . V_31 ) ;
}
static void F_15 ( struct V_3 * V_37 , unsigned long V_30 )
{
memset ( V_37 -> V_38 , 0 , 0x100000 ) ;
V_37 -> V_15 = V_39 ;
V_37 -> V_15 . V_40 = V_30 ;
V_37 -> V_2 = V_41 ;
V_37 -> V_42 = & V_43 ;
V_37 -> V_44 = V_45 ;
F_16 ( & V_37 -> V_46 , 256 , 0 ) ;
F_9 () ;
}
static int F_17 ( struct V_47 * V_48 , const struct V_49 * V_50 )
{
struct V_3 * V_37 ;
unsigned long V_30 , V_51 ;
unsigned short V_52 ;
int V_53 = - V_54 ;
if ( F_18 ( V_48 ) < 0 ) {
F_19 ( & V_48 -> V_55 , L_1 ) ;
goto V_56;
}
if ( ( V_48 -> V_57 [ 0 ] . V_44 & V_58 ) == 0 )
goto V_59;
V_30 = F_20 ( V_48 , 0 ) ;
V_51 = F_21 ( V_48 , 0 ) ;
if ( V_30 == 0 )
goto V_59;
V_37 = F_22 ( 0 , & V_48 -> V_55 ) ;
if ( V_37 == NULL ) {
F_19 ( & V_48 -> V_55 , L_2 ) ;
V_53 = - V_60 ;
goto V_59;
}
if ( F_23 ( V_48 , 0 , L_3 ) != 0 ) {
F_19 ( & V_48 -> V_55 , L_4 ) ;
V_53 = - V_61 ;
goto V_62;
}
#ifdef F_24
V_30 += 0x800000 ;
#endif
F_25 ( V_48 , V_63 , & V_52 ) ;
V_52 |= 3 ;
F_26 ( V_48 , V_63 , V_52 ) ;
#ifdef F_27
F_28 ( & V_64 ) ;
if ( V_65 ) {
V_65 -> V_66 . V_67 = V_68 ;
F_29 ( V_65 ) ;
}
F_30 ( & V_64 ) ;
#endif
#ifdef F_31
V_37 -> V_38 = F_32 ( V_30 , 0x200000 , V_69 ) ;
#else
V_37 -> V_38 = F_33 ( V_30 , 0x200000 ) ;
#endif
if ( V_37 -> V_38 == NULL ) {
F_19 ( & V_48 -> V_55 , L_5 ) ;
V_53 = - V_60 ;
goto V_70;
}
F_34 ( V_48 , V_37 ) ;
F_15 ( V_37 , V_30 ) ;
if ( F_35 ( V_37 ) < 0 ) {
F_19 ( & V_48 -> V_55 , L_6 ) ;
goto V_71;
}
F_36 ( & V_48 -> V_55 , L_7
L_8 ,
V_37 -> V_72 , V_37 -> V_15 . V_73 / 1024 ) ;
return 0 ;
V_71:
F_37 ( V_37 -> V_38 ) ;
V_70:
F_38 ( V_48 , 0 ) ;
V_62:
F_39 ( V_37 ) ;
V_59:
V_56:
return V_53 ;
}
static void F_40 ( struct V_47 * V_48 )
{
struct V_3 * V_37 = F_41 ( V_48 ) ;
if ( V_37 -> V_38 == NULL )
return;
F_42 ( V_37 ) ;
F_37 ( V_37 -> V_38 ) ;
V_37 -> V_38 = NULL ;
F_38 ( V_48 , 0 ) ;
}
static int F_43 ( struct V_47 * V_74 , T_2 V_75 )
{
struct V_3 * V_37 = F_41 ( V_74 ) ;
if ( V_75 . V_76 == V_74 -> V_55 . V_67 . V_77 . V_76 )
return 0 ;
if ( ! ( V_75 . V_76 & V_78 ) )
goto V_79;
F_44 () ;
F_5 ( 1 , V_37 ) ;
F_45 ( V_37 , 1 ) ;
F_46 () ;
V_79:
V_74 -> V_55 . V_67 . V_77 = V_75 ;
return 0 ;
}
static int F_47 ( struct V_47 * V_74 )
{
struct V_3 * V_37 = F_41 ( V_74 ) ;
F_44 () ;
F_45 ( V_37 , 0 ) ;
F_5 ( 0 , V_37 ) ;
F_46 () ;
V_74 -> V_55 . V_67 . V_77 = V_80 ;
return 0 ;
}
int T_3 F_48 ( void )
{
if ( F_49 ( L_3 , NULL ) )
return - V_54 ;
return F_50 ( & V_81 ) ;
}
static void T_4 F_51 ( void )
{
F_52 ( & V_81 ) ;
}
