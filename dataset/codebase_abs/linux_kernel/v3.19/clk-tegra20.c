static unsigned long F_1 ( void )
{
T_1 V_1 = F_2 ( V_2 + V_3 ) ;
T_1 V_4 = V_1 & V_5 ;
T_1 V_6 = V_1 & V_7 ;
unsigned long V_8 ;
switch ( V_4 ) {
case V_9 :
F_3 ( V_6 != V_10 ) ;
V_8 = 12000000 ;
break;
case V_11 :
F_3 ( V_6 != V_10 ) ;
V_8 = 13000000 ;
break;
case V_12 :
F_3 ( V_6 != V_10 ) ;
V_8 = 19200000 ;
break;
case V_13 :
F_3 ( V_6 != V_10 ) ;
V_8 = 26000000 ;
break;
default:
F_4 ( L_1 ,
V_4 ) ;
F_5 () ;
return 0 ;
}
return V_8 ;
}
static unsigned int F_6 ( void )
{
T_1 V_6 = F_2 ( V_2 + V_3 ) &
V_7 ;
switch ( V_6 ) {
case V_10 :
return 1 ;
case V_14 :
return 2 ;
case V_15 :
return 4 ;
default:
F_4 ( L_2 , V_6 ) ;
F_5 () ;
}
return 0 ;
}
static void F_7 ( void )
{
struct V_16 * V_16 ;
V_16 = F_8 ( L_3 , L_4 , V_2 , NULL , 0 ,
& V_17 , NULL ) ;
V_18 [ V_19 ] = V_16 ;
V_16 = F_9 ( L_5 , L_3 ,
V_2 + V_20 , 0 , V_21 ,
8 , 8 , 1 , NULL ) ;
V_16 = F_10 ( L_6 , L_5 ,
V_2 + V_20 , 1 , 0 , V_22 ,
0 , NULL ) ;
V_18 [ V_23 ] = V_16 ;
V_16 = F_8 ( L_7 , L_4 , V_2 , NULL ,
V_24 | V_25 ,
& V_26 , NULL ) ;
V_18 [ V_27 ] = V_16 ;
V_16 = F_9 ( L_8 , L_7 ,
V_2 + V_28 , 0 , V_21 ,
8 , 8 , 1 , NULL ) ;
V_16 = F_10 ( L_9 , L_8 ,
V_2 + V_28 , 1 , 0 , V_24 |
V_22 , 0 , NULL ) ;
V_18 [ V_29 ] = V_16 ;
V_16 = F_8 ( L_10 , L_4 , V_2 , NULL , 0 ,
& V_30 , NULL ) ;
V_18 [ V_31 ] = V_16 ;
V_16 = F_8 ( L_11 , L_4 , V_2 , NULL , 0 ,
& V_32 , NULL ) ;
V_18 [ V_33 ] = V_16 ;
V_16 = F_8 ( L_12 , L_4 , V_2 , NULL , 0 ,
& V_34 , NULL ) ;
V_18 [ V_35 ] = V_16 ;
V_16 = F_11 ( NULL , L_13 , L_12 ,
V_22 , 1 , 2 ) ;
V_18 [ V_36 ] = V_16 ;
V_16 = F_8 ( L_14 , L_15 , V_2 , NULL , 0 ,
& V_37 , NULL ) ;
V_18 [ V_38 ] = V_16 ;
V_16 = F_9 ( L_16 , L_14 ,
V_2 + V_39 , 0 , V_21 ,
8 , 8 , 1 , NULL ) ;
V_16 = F_10 ( L_17 , L_16 ,
V_2 + V_39 , 1 , 0 , V_24 |
V_22 , 0 , NULL ) ;
V_18 [ V_40 ] = V_16 ;
V_16 = F_12 ( L_18 , L_4 , V_2 , V_41 ,
0 , & V_42 , NULL ) ;
V_18 [ V_43 ] = V_16 ;
}
static void F_13 ( void )
{
struct V_16 * V_16 ;
V_16 = F_14 ( L_19 , V_44 ,
F_15 ( V_44 ) , V_22 ,
V_2 + V_45 , 0 , 4 , 0 , 0 , NULL ) ;
V_18 [ V_46 ] = V_16 ;
V_16 = F_14 ( L_20 , V_47 ,
F_15 ( V_47 ) , V_22 ,
V_2 + V_48 , 0 , 4 , 0 , 0 , NULL ) ;
V_18 [ V_49 ] = V_16 ;
V_16 = F_11 ( NULL , L_21 , L_19 , 0 , 1 , 4 ) ;
V_18 [ V_50 ] = V_16 ;
}
static void T_2 F_16 ( void )
{
struct V_16 * V_16 ;
V_16 = F_17 ( NULL , L_22 , V_51 ,
F_15 ( V_51 ) ,
V_52 ,
V_2 + V_53 , 0 , 3 , 0 , NULL ) ;
V_16 = F_18 ( NULL , L_23 , L_22 , 0 ,
V_2 + V_53 , 4 ,
V_54 , NULL ) ;
V_18 [ V_55 ] = V_16 ;
V_16 = F_11 ( NULL , L_24 , L_23 ,
V_22 , 2 , 1 ) ;
V_16 = F_19 ( L_25 , L_24 ,
V_56 , V_2 ,
V_22 , 89 ,
V_57 ) ;
V_18 [ V_58 ] = V_16 ;
}
static void T_2 F_20 ( void )
{
struct V_59 * V_60 ;
struct V_16 * V_16 ;
int V_61 ;
V_16 = F_19 ( L_26 , L_17 ,
V_62 ,
V_2 , 0 , 3 , V_57 ) ;
V_18 [ V_63 ] = V_16 ;
V_16 = F_19 ( L_27 , L_28 , 0 , V_2 ,
0 , 34 , V_57 ) ;
V_18 [ V_64 ] = V_16 ;
V_16 = F_17 ( NULL , L_29 , V_65 ,
F_15 ( V_65 ) ,
V_52 ,
V_2 + V_66 ,
30 , 2 , 0 , & V_67 ) ;
V_16 = F_19 ( L_30 , L_29 , 0 , V_2 , 0 ,
57 , V_57 ) ;
V_18 [ V_68 ] = V_16 ;
V_16 = F_21 ( L_31 , L_29 , V_2 + V_66 ,
& V_67 ) ;
V_18 [ V_69 ] = V_16 ;
V_16 = F_19 ( L_32 , L_12 , 0 , V_2 , 0 ,
48 , V_57 ) ;
F_22 ( V_16 , NULL , L_32 ) ;
V_18 [ V_70 ] = V_16 ;
V_16 = F_19 ( L_33 , L_34 , 0 , V_2 , 0 , 70 ,
V_57 ) ;
V_18 [ V_71 ] = V_16 ;
V_16 = F_23 ( NULL , L_35 , NULL , V_72 ,
26000000 ) ;
V_16 = F_19 ( L_36 , L_35 , 0 ,
V_2 , 0 , 94 , V_57 ) ;
V_18 [ V_73 ] = V_16 ;
V_16 = F_23 ( NULL , L_37 , NULL , V_72 ,
26000000 ) ;
V_16 = F_19 ( L_38 , L_37 , 0 ,
V_2 , 0 , 93 , V_57 ) ;
V_18 [ V_74 ] = V_16 ;
for ( V_61 = 0 ; V_61 < F_15 ( V_75 ) ; V_61 ++ ) {
V_60 = & V_75 [ V_61 ] ;
V_16 = F_24 ( V_60 -> V_76 , V_60 -> V_77 . V_78 ,
V_60 -> V_79 , & V_60 -> V_80 ,
V_2 , V_60 -> V_81 , V_60 -> V_82 ) ;
V_18 [ V_60 -> V_83 ] = V_16 ;
}
for ( V_61 = 0 ; V_61 < F_15 ( V_84 ) ; V_61 ++ ) {
V_60 = & V_84 [ V_61 ] ;
V_16 = F_25 ( V_60 -> V_76 ,
V_60 -> V_77 . V_78 ,
V_60 -> V_79 , & V_60 -> V_80 ,
V_2 , V_60 -> V_81 ) ;
V_18 [ V_60 -> V_83 ] = V_16 ;
}
F_26 ( V_2 , V_41 , V_85 , & V_86 ) ;
}
static void T_2 F_27 ( void )
{
struct V_16 * V_16 ;
unsigned long V_8 ;
unsigned int V_6 ;
V_8 = F_1 () ;
V_16 = F_23 ( NULL , L_34 , NULL , V_72 |
V_24 , V_8 ) ;
V_18 [ V_87 ] = V_16 ;
V_6 = F_6 () ;
V_16 = F_11 ( NULL , L_4 , L_34 ,
V_22 , 1 , V_6 ) ;
V_18 [ V_88 ] = V_16 ;
}
static void F_28 ( T_1 V_89 )
{
unsigned int V_90 ;
do {
V_90 = F_29 ( V_2 +
V_91 ) ;
F_30 () ;
} while ( ! ( V_90 & ( 1 << V_89 ) ) );
return;
}
static void F_31 ( T_1 V_89 )
{
F_32 ( F_33 ( V_89 ) ,
V_2 + V_91 ) ;
F_34 () ;
}
static void F_35 ( T_1 V_89 )
{
F_32 ( F_33 ( V_89 ) ,
V_2 + V_92 ) ;
F_36 () ;
}
static void F_37 ( T_1 V_89 )
{
unsigned int V_90 ;
V_90 = F_29 ( V_2 + V_93 ) ;
F_32 ( V_90 & ~ F_38 ( V_89 ) ,
V_2 + V_93 ) ;
F_39 () ;
V_90 = F_29 ( V_2 + V_93 ) ;
}
static void F_40 ( T_1 V_89 )
{
unsigned int V_90 ;
V_90 = F_29 ( V_2 + V_93 ) ;
F_32 ( V_90 | F_38 ( V_89 ) ,
V_2 + V_93 ) ;
}
static bool F_41 ( void )
{
unsigned int V_94 ;
V_94 = F_29 ( V_2 +
V_91 ) ;
return ! ! ( V_94 & 0x2 ) ;
}
static void F_42 ( void )
{
V_95 . V_96 =
F_29 ( V_2 + V_97 ) ;
F_32 ( 3 << 30 , V_2 + V_97 ) ;
V_95 . V_98 =
F_29 ( V_2 + V_45 ) ;
V_95 . V_99 =
F_29 ( V_2 + V_100 ) ;
V_95 . V_101 =
F_29 ( V_2 + V_102 ) ;
V_95 . V_103 =
F_29 ( V_2 + V_104 ) ;
}
static void F_43 ( void )
{
unsigned int V_90 , V_105 ;
V_90 = F_29 ( V_2 + V_45 ) ;
V_105 = ( V_90 >> V_106 ) & 0xF ;
if ( V_105 == V_107 )
V_90 = ( V_90 >> V_108 ) & 0xF ;
else if ( V_105 == V_109 )
V_90 = ( V_90 >> V_110 ) & 0xF ;
else
F_5 () ;
if ( V_90 != V_111 ) {
F_32 ( V_95 . V_101 ,
V_2 + V_102 ) ;
F_32 ( V_95 . V_99 ,
V_2 + V_100 ) ;
if ( V_95 . V_99 & ( 1 << 30 ) )
F_44 ( 300 ) ;
}
F_32 ( V_95 . V_103 ,
V_2 + V_104 ) ;
F_32 ( V_95 . V_98 ,
V_2 + V_45 ) ;
F_32 ( V_95 . V_96 ,
V_2 + V_97 ) ;
}
static void T_2 F_45 ( void )
{
F_46 ( V_112 , V_18 , V_113 ) ;
}
static void T_2 F_47 ( struct V_114 * V_115 )
{
struct V_114 * V_116 ;
V_2 = F_48 ( V_115 , 0 ) ;
if ( ! V_2 ) {
F_4 ( L_39 ) ;
F_5 () ;
}
V_116 = F_49 ( NULL , V_117 ) ;
if ( ! V_116 ) {
F_4 ( L_40 ) ;
F_5 () ;
}
V_41 = F_48 ( V_116 , 0 ) ;
if ( ! V_41 ) {
F_4 ( L_41 ) ;
F_5 () ;
}
V_18 = F_50 ( V_2 , V_113 ,
V_118 ) ;
if ( ! V_18 )
return;
F_27 () ;
F_51 ( V_85 ) ;
F_7 () ;
F_13 () ;
F_52 ( V_2 , V_41 , V_85 , NULL ) ;
F_20 () ;
F_16 () ;
F_53 ( V_41 , V_85 ) ;
F_54 ( V_119 , V_18 , V_113 ) ;
F_55 ( V_115 ) ;
F_56 ( V_120 , F_15 ( V_120 ) ) ;
V_121 = F_45 ;
V_122 = & V_123 ;
}
