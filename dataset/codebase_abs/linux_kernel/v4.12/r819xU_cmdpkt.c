T_1 F_1 ( struct V_1 * V_2 , void * V_3 , T_2 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
unsigned char * V_11 ;
V_8 = F_3 ( V_12 + V_4 + 4 ) ;
if ( ! V_8 )
return V_13 ;
memcpy ( ( unsigned char * ) ( V_8 -> V_14 ) , & V_2 , sizeof( V_2 ) ) ;
V_10 = (struct V_9 * ) ( V_8 -> V_14 + V_15 ) ;
V_10 -> V_16 = V_17 ;
V_10 -> V_18 = V_19 ;
V_10 -> V_20 = 0 ;
F_4 ( V_8 , V_12 ) ;
V_11 = F_5 ( V_8 , V_4 ) ;
memcpy ( V_11 , V_3 , V_4 ) ;
V_10 -> V_21 = ( V_22 ) V_4 ;
if ( ! V_6 -> V_23 -> V_24 ( V_2 , V_10 -> V_16 ) ||
( ! F_6 ( & V_6 -> V_23 -> V_25 [ V_10 -> V_16 ] ) ) ||
( V_6 -> V_23 -> V_26 ) ) {
F_7 ( V_27 , L_1 ) ;
F_8 ( & V_6 -> V_23 -> V_25 [ V_10 -> V_16 ] , V_8 ) ;
} else {
V_6 -> V_23 -> V_28 ( V_8 , V_2 ) ;
}
return V_29 ;
}
static void F_9 ( struct V_1 * V_2 , T_3 * V_30 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
#ifdef F_10
T_4 V_31 ;
V_32 -> V_33 . V_34 ( V_32 , V_35 ,
( V_36 ) ( & V_31 ) ) ;
if ( V_31 == V_37 )
return;
#endif
#ifdef F_11
if ( V_32 -> V_38 )
return;
#endif
if ( V_30 -> V_39 ) {
V_6 -> V_40 . V_41 ++ ;
V_6 -> V_40 . V_42 ++ ;
V_6 -> V_40 . V_43 += V_30 -> V_44 ;
V_6 -> V_40 . V_45 ++ ;
if ( V_30 -> V_46 == V_47 ) {
V_6 -> V_40 . V_48 ++ ;
V_6 -> V_40 . V_49 += V_30 -> V_44 ;
} else if ( V_30 -> V_46 == V_50 ) {
V_6 -> V_40 . V_51 ++ ;
V_6 -> V_40 . V_52 += V_30 -> V_44 ;
} else {
V_6 -> V_40 . V_53 ++ ;
V_6 -> V_40 . V_54 += V_30 -> V_44 ;
}
} else {
V_6 -> V_40 . V_55 ++ ;
V_6 -> V_40 . V_56 ++ ;
V_6 -> V_40 . V_57 += V_30 -> V_44 ;
if ( V_30 -> V_46 == V_47 )
V_6 -> V_40 . V_58 ++ ;
else if ( V_30 -> V_46 == V_50 )
V_6 -> V_40 . V_59 ++ ;
else
V_6 -> V_40 . V_60 ++ ;
}
V_6 -> V_40 . V_61 += V_30 -> V_62 ;
V_6 -> V_40 . V_63 += V_30 -> V_62 ;
}
static void F_12 ( struct V_1 * V_2 , T_5 * V_64 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_3 V_65 ;
V_6 -> V_40 . V_66 ++ ;
memcpy ( ( T_5 * ) & V_65 , V_64 , sizeof( T_3 ) ) ;
F_9 ( V_2 , & V_65 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_22 V_67 ;
if ( V_6 -> V_23 -> V_68 . V_69 == V_70 ||
V_6 -> V_23 -> V_68 . V_69 == V_71 ||
( V_6 -> V_23 -> V_68 . V_69 == V_72 &&
( ! V_6 -> V_23 -> V_73 -> V_74 ) ) ) {
V_67 = 60 ;
F_14 ( L_2 ) ;
} else {
V_67 = 10 ;
F_14 ( L_3 ) ;
}
F_15 ( V_2 , V_67 ) ;
}
static void F_16 ( struct V_1 * V_2 , T_5 * V_64 )
{
T_6 V_75 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_14 ( L_4 ) ;
V_75 . V_76 = V_64 [ 1 ] ;
if ( V_75 . V_76 != ( sizeof( T_6 ) - 2 ) ) {
F_14 ( L_5 ) ;
return;
}
if ( V_6 -> V_23 -> V_77 == V_78 ) {
V_75 . V_79 = * ( ( T_2 * ) ( V_64 + 4 ) ) ;
F_14 ( L_6 ,
V_75 . V_79 ) ;
if ( V_75 . V_79 & V_80 ) {
V_6 -> V_23 -> V_81 = true ;
V_6 -> V_40 . V_82 ++ ;
} else if ( V_75 . V_79 & V_83 ) {
V_6 -> V_23 -> V_81 = false ;
V_6 -> V_40 . V_84 ++ ;
}
if ( V_75 . V_79 & V_85 )
F_13 ( V_2 ) ;
}
F_14 ( L_7 ) ;
}
static void F_17 ( struct V_1 * V_2 , T_5 * V_64 )
{
T_7 V_86 ;
V_86 . V_87 = ( V_64 [ 4 ] & 0x80000000 ) >> 31 ;
V_86 . V_88 = ( V_64 [ 4 ] & 0x60 ) >> 5 ;
V_86 . V_89 = ( V_64 [ 4 ] & 0x18 ) >> 3 ;
V_86 . V_90 = ( V_64 [ 6 ] & 0x0F ) >> 0 ;
V_86 . V_91 = V_64 [ 7 ] ;
V_86 . V_92 = ( V_64 [ 8 ] << 24 ) | ( V_64 [ 9 ] << 16 ) |
( V_64 [ 10 ] << 8 ) | ( V_64 [ 11 ] << 0 ) ;
V_86 . V_93 = ( V_64 [ 12 ] << 24 ) | ( V_64 [ 13 ] << 16 ) |
( V_64 [ 14 ] << 8 ) | ( V_64 [ 15 ] << 0 ) ;
}
static void F_18 ( struct V_1 * V_2 ,
T_8 * V_94 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
#ifdef F_10
T_4 V_95 ;
V_32 -> V_33 . V_34 ( V_32 , V_35 ,
( V_36 ) ( & V_31 ) ) ;
if ( V_31 == V_37 )
return;
#endif
V_6 -> V_40 . V_41 += V_94 -> V_96 ;
V_6 -> V_40 . V_42 += V_94 -> V_96 ;
V_6 -> V_40 . V_55 += V_94 -> V_97 ;
V_6 -> V_40 . V_56 += V_94 -> V_97 ;
V_6 -> V_40 . V_61 += V_94 -> V_98 ;
V_6 -> V_40 . V_63 += V_94 -> V_98 ;
V_6 -> V_40 . V_48 += V_94 -> V_99 ;
V_6 -> V_40 . V_51 += V_94 -> V_100 ;
V_6 -> V_40 . V_53 += V_94 -> V_101 ;
V_6 -> V_40 . V_58 += V_94 -> V_102 ;
V_6 -> V_40 . V_59 += V_94 -> V_103 ;
V_6 -> V_40 . V_60 += V_94 -> V_104 ;
V_6 -> V_40 . V_49 += V_94 -> V_105 ;
V_6 -> V_40 . V_52 += V_94 -> V_106 ;
V_6 -> V_40 . V_54 += V_94 -> V_107 ;
V_6 -> V_40 . V_108 = V_94 -> V_109 ;
}
static void F_19 ( struct V_1 * V_2 , T_5 * V_64 )
{
T_8 V_110 ;
memcpy ( ( void * ) & V_110 , ( void * ) V_64 , sizeof( T_8 ) ) ;
F_18 ( V_2 , & V_110 ) ;
}
static void F_20 ( struct V_1 * V_2 , T_5 * V_64 )
{
T_9 * V_111 ;
T_5 V_112 , V_113 ;
V_22 V_76 = sizeof( T_9 ) ;
T_2 * V_114 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
#ifdef F_10
V_32 -> V_33 . V_34 ( V_32 , V_35 ,
( V_36 ) ( & V_31 ) ) ;
if ( V_31 == V_37 )
return;
#endif
V_114 = ( T_2 * ) V_64 ;
for ( V_112 = 0 ; V_112 < ( V_76 / 4 ) ; V_112 ++ ) {
V_22 V_115 , V_116 ;
V_115 = V_114 [ V_112 ] & 0x0000FFFF ;
V_116 = V_114 [ V_112 ] >> 16 ;
V_114 [ V_112 ] = ( V_115 << 16 ) | V_116 ;
}
V_111 = ( T_9 * ) V_64 ;
if ( V_111 == NULL )
return;
for ( V_112 = 0 ; V_112 < 16 ; V_112 ++ ) {
if ( V_112 < 4 )
V_6 -> V_40 . V_117 . V_118 [ V_112 ] += V_111 -> V_118 [ V_112 ] ;
if ( V_112 < 8 )
V_6 -> V_40 . V_117 . V_119 [ V_112 ] += V_111 -> V_119 [ V_112 ] ;
for ( V_113 = 0 ; V_113 < 4 ; V_113 ++ )
V_6 -> V_40 . V_117 . V_120 [ V_113 ] [ V_112 ] += V_111 -> V_120 [ V_113 ] [ V_112 ] ;
}
}
T_2 F_21 ( struct V_1 * V_2 ,
struct V_121 * V_122 )
{
int V_123 ;
T_5 V_124 , V_125 = 0 ;
T_5 V_126 ;
T_5 * V_127 ;
if ( V_122 == NULL )
return 0 ;
V_123 = V_122 -> V_128 ;
V_127 = V_122 -> V_129 ;
V_126 = V_127 [ 0 ] ;
while ( V_123 > 0 && V_125 ++ < 100 ) {
V_126 = V_127 [ 0 ] ;
switch ( V_126 ) {
case V_130 :
F_12 ( V_2 , V_127 ) ;
V_124 = V_131 ;
break;
case V_132 :
F_16 ( V_2 , V_127 ) ;
V_124 = sizeof( T_6 ) ;
break;
case V_133 :
F_17 ( V_2 , V_127 ) ;
V_124 = V_134 ;
break;
case V_135 :
F_19 ( V_2 , V_127 ) ;
V_124 = V_136 ;
break;
case V_137 :
V_124 = V_131 ;
break;
case V_138 :
F_20 ( V_2 , V_127 ) ;
V_124 = V_139 ;
break;
default:
F_7 ( V_140 , L_8 ,
V_141 ) ;
return 1 ;
}
V_123 -= V_124 ;
V_127 += V_124 ;
}
return 1 ;
}
