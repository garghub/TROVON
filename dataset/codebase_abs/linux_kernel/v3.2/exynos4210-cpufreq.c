static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static unsigned int F_3 ( unsigned int V_4 )
{
return F_4 ( V_5 ) / 1000 ;
}
static void F_5 ( unsigned int V_6 )
{
unsigned int V_7 ;
V_7 = F_6 ( V_8 ) ;
V_7 &= ~ ( V_9 | V_10 |
V_11 | V_12 |
V_13 | V_14 |
V_15 ) ;
V_7 |= ( ( V_16 [ V_6 ] [ 0 ] << V_17 ) |
( V_16 [ V_6 ] [ 1 ] << V_18 ) |
( V_16 [ V_6 ] [ 2 ] << V_19 ) |
( V_16 [ V_6 ] [ 3 ] << V_20 ) |
( V_16 [ V_6 ] [ 4 ] << V_21 ) |
( V_16 [ V_6 ] [ 5 ] << V_22 ) |
( V_16 [ V_6 ] [ 6 ] << V_23 ) ) ;
F_7 ( V_7 , V_8 ) ;
do {
V_7 = F_6 ( V_24 ) ;
} while ( V_7 & 0x1111111 );
V_7 = F_6 ( V_25 ) ;
V_7 &= ~ ( ( 0x7 << 4 ) | 0x7 ) ;
V_7 |= ( ( V_26 [ V_6 ] [ 0 ] << 4 ) |
( V_26 [ V_6 ] [ 1 ] << 0 ) ) ;
F_7 ( V_7 , V_25 ) ;
do {
V_7 = F_6 ( V_27 ) ;
} while ( V_7 & 0x11 );
V_7 = F_6 ( V_28 ) ;
V_7 &= ~ ( V_29 | V_30 |
V_31 | V_32 |
V_33 | V_34 |
V_35 | V_36 ) ;
V_7 |= ( ( V_37 [ V_6 ] [ 0 ] << V_38 ) |
( V_37 [ V_6 ] [ 1 ] << V_39 ) |
( V_37 [ V_6 ] [ 2 ] << V_40 ) |
( V_37 [ V_6 ] [ 3 ] << V_41 ) |
( V_37 [ V_6 ] [ 4 ] << V_42 ) |
( V_37 [ V_6 ] [ 5 ] << V_43 ) |
( V_37 [ V_6 ] [ 6 ] << V_44 ) |
( V_37 [ V_6 ] [ 7 ] << V_45 ) ) ;
F_7 ( V_7 , V_28 ) ;
do {
V_7 = F_6 ( V_46 ) ;
} while ( V_7 & 0x11111111 );
V_7 = F_6 ( V_47 ) ;
V_7 &= ~ ( V_48 | V_49 |
V_50 | V_51 |
V_52 ) ;
V_7 |= ( ( V_53 [ V_6 ] [ 0 ] << V_54 ) |
( V_53 [ V_6 ] [ 1 ] << V_55 ) |
( V_53 [ V_6 ] [ 2 ] << V_56 ) |
( V_53 [ V_6 ] [ 3 ] << V_57 ) |
( V_53 [ V_6 ] [ 4 ] << V_58 ) ) ;
F_7 ( V_7 , V_47 ) ;
do {
V_7 = F_6 ( V_59 ) ;
} while ( V_7 & 0x11111 );
V_7 = F_6 ( V_60 ) ;
V_7 &= ~ ( V_61 | V_62 ) ;
V_7 |= ( ( V_63 [ V_6 ] [ 0 ] << V_64 ) |
( V_63 [ V_6 ] [ 1 ] << V_65 ) ) ;
F_7 ( V_7 , V_60 ) ;
do {
V_7 = F_6 ( V_66 ) ;
} while ( V_7 & 0x11 );
V_7 = F_6 ( V_67 ) ;
V_7 &= ~ ( V_61 | V_62 ) ;
V_7 |= ( ( V_63 [ V_6 ] [ 0 ] << V_64 ) |
( V_63 [ V_6 ] [ 1 ] << V_65 ) ) ;
F_7 ( V_7 , V_67 ) ;
do {
V_7 = F_6 ( V_68 ) ;
} while ( V_7 & 0x11 );
}
static void F_8 ( unsigned int V_69 )
{
unsigned int V_7 ;
F_9 ( V_70 , V_71 ) ;
do {
V_7 = ( F_6 ( V_72 )
>> V_73 ) ;
V_7 &= 0x7 ;
} while ( V_7 != 0x2 );
F_7 ( V_74 , V_75 ) ;
V_7 = F_6 ( V_76 ) ;
V_7 &= ~ ( ( 0x3ff << 16 ) | ( 0x3f << 8 ) | ( 0x7 << 0 ) ) ;
V_7 |= V_77 [ V_69 ] ;
F_7 ( V_7 , V_76 ) ;
do {
V_7 = F_6 ( V_76 ) ;
} while ( ! ( V_7 & ( 0x1 << V_78 ) ) );
F_9 ( V_70 , V_79 ) ;
do {
V_7 = F_6 ( V_72 ) ;
V_7 &= V_80 ;
} while ( V_7 != ( 0x1 << V_73 ) );
}
static void F_10 ( unsigned int V_81 , unsigned int V_82 )
{
unsigned int V_7 ;
if ( V_81 > V_82 ) {
if ( V_83 . V_84 == V_3 [ V_85 ] . V_86 ) {
F_5 ( V_82 ) ;
F_8 ( V_82 ) ;
} else {
F_5 ( V_82 ) ;
V_7 = F_6 ( V_76 ) ;
V_7 &= ~ ( 0x7 << 0 ) ;
V_7 |= ( V_77 [ V_82 ] & 0x7 ) ;
F_7 ( V_7 , V_76 ) ;
}
}
else if ( V_81 < V_82 ) {
if ( V_83 . V_87 == V_3 [ V_85 ] . V_86 ) {
F_8 ( V_82 ) ;
F_5 ( V_82 ) ;
} else {
V_7 = F_6 ( V_76 ) ;
V_7 &= ~ ( 0x7 << 0 ) ;
V_7 |= ( V_77 [ V_82 ] & 0x7 ) ;
F_7 ( V_7 , V_76 ) ;
F_5 ( V_82 ) ;
}
}
}
static int F_11 ( struct V_1 * V_2 ,
unsigned int V_88 ,
unsigned int V_89 )
{
unsigned int V_69 , V_81 ;
unsigned int V_90 , V_91 ;
int V_92 = - V_93 ;
V_83 . V_87 = F_3 ( V_2 -> V_4 ) ;
F_12 ( & V_94 ) ;
if ( V_95 && V_88 != V_96 ) {
V_92 = - V_97 ;
goto V_98;
}
if ( F_13 ( V_2 , V_3 ,
V_83 . V_87 , V_89 , & V_81 ) )
goto V_98;
if ( F_13 ( V_2 , V_3 ,
V_88 , V_89 , & V_69 ) )
goto V_98;
V_92 = 0 ;
V_83 . V_84 = V_3 [ V_69 ] . V_86 ;
V_83 . V_4 = V_2 -> V_4 ;
if ( V_83 . V_84 == V_83 . V_87 )
goto V_98;
V_90 = V_99 [ V_69 ] . V_90 ;
V_91 = V_99 [ V_69 ] . V_91 ;
F_14 ( & V_83 , V_100 ) ;
if ( V_83 . V_84 > V_83 . V_87 ) {
F_15 ( V_101 , V_90 , V_90 ) ;
F_15 ( V_102 , V_91 , V_91 ) ;
}
F_10 ( V_81 , V_69 ) ;
if ( V_83 . V_84 < V_83 . V_87 ) {
F_15 ( V_101 , V_90 , V_90 ) ;
F_15 ( V_102 , V_91 , V_91 ) ;
}
F_14 ( & V_83 , V_103 ) ;
V_98:
F_16 ( & V_94 ) ;
return V_92 ;
}
static int F_17 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_19 ( struct V_104 * V_105 ,
unsigned long V_106 , void * V_107 )
{
struct V_1 * V_2 = F_20 ( 0 ) ;
static unsigned int V_108 ;
unsigned int V_109 ;
F_12 ( & V_94 ) ;
switch ( V_106 ) {
case V_110 :
if ( V_95 )
goto V_98;
V_95 = true ;
if ( V_96 ) {
V_108 = F_3 ( 0 ) ;
F_16 ( & V_94 ) ;
F_11 ( V_2 , V_96 ,
V_111 ) ;
F_12 ( & V_94 ) ;
}
break;
case V_112 :
if ( V_108 ) {
V_109 = V_96 ;
V_96 = V_108 ;
F_16 ( & V_94 ) ;
F_11 ( V_2 , V_96 ,
V_111 ) ;
F_12 ( & V_94 ) ;
V_96 = V_109 ;
}
V_95 = false ;
break;
}
V_98:
F_16 ( & V_94 ) ;
return V_113 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_114 ;
V_2 -> V_115 = V_2 -> V_116 = V_2 -> V_117 = F_3 ( V_2 -> V_4 ) ;
F_22 ( V_3 , V_2 -> V_4 ) ;
V_2 -> V_118 . V_119 = 100000 ;
F_23 ( V_2 -> V_120 ) ;
V_114 = F_24 ( V_2 , V_3 ) ;
if ( V_114 )
return V_114 ;
F_22 ( V_3 , V_2 -> V_4 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
F_26 ( V_2 -> V_4 ) ;
return 0 ;
}
static int T_1 F_27 ( void )
{
V_5 = F_28 ( NULL , L_1 ) ;
if ( F_29 ( V_5 ) )
return F_30 ( V_5 ) ;
V_96 = F_3 ( 0 ) ;
V_70 = F_28 ( NULL , L_2 ) ;
if ( F_29 ( V_70 ) )
goto V_98;
V_71 = F_28 ( NULL , L_3 ) ;
if ( F_29 ( V_71 ) )
goto V_98;
V_79 = F_28 ( NULL , L_4 ) ;
if ( F_29 ( V_79 ) )
goto V_98;
V_101 = F_31 ( NULL , L_5 ) ;
if ( F_29 ( V_101 ) ) {
F_32 ( V_121 L_6 , L_5 ) ;
goto V_98;
}
V_102 = F_31 ( NULL , L_7 ) ;
if ( F_29 ( V_102 ) ) {
F_32 ( V_121 L_6 , L_7 ) ;
goto V_98;
}
V_122 = F_6 ( V_123 + V_124 ) ;
V_122 = ( V_122 >> V_125 ) ;
V_122 &= V_126 ;
if ( ( V_122 < V_127 ) && ( V_122 > V_128 ) ) {
F_32 ( V_121 L_8 , V_129 , V_122 ) ;
goto V_98;
} else {
F_32 ( V_130 L_9 , V_129 , V_122 ) ;
}
F_33 ( & V_131 ) ;
return F_34 ( & V_132 ) ;
V_98:
if ( ! F_29 ( V_5 ) )
F_35 ( V_5 ) ;
if ( ! F_29 ( V_70 ) )
F_35 ( V_70 ) ;
if ( ! F_29 ( V_71 ) )
F_35 ( V_71 ) ;
if ( ! F_29 ( V_79 ) )
F_35 ( V_79 ) ;
if ( ! F_29 ( V_101 ) )
F_36 ( V_101 ) ;
if ( ! F_29 ( V_102 ) )
F_36 ( V_102 ) ;
F_32 ( V_121 L_10 , V_129 ) ;
return - V_93 ;
}
