static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
if ( V_2 -> V_4 )
V_3 = 0 ;
else
V_3 = F_2 ( V_2 -> V_5 ) ;
F_3 ( V_6 , V_2 -> V_7 + V_8 ) ;
F_3 ( V_3 & 0xffff , V_2 -> V_7 + V_9 ) ;
F_3 ( V_10 , V_2 -> V_7 + V_8 ) ;
F_3 ( V_3 >> 16 , V_2 -> V_7 + V_9 ) ;
F_3 ( V_11 , V_2 -> V_7 + V_8 ) ;
F_3 ( V_2 -> V_12 , V_2 -> V_7 + V_9 ) ;
F_3 ( V_13 , V_2 -> V_7 + V_8 ) ;
}
static void F_4 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_5 ( V_15 ) ;
struct V_16 * V_17 = V_2 -> V_18 ;
T_2 V_19 = V_2 -> V_5 ;
T_3 V_3 ;
int V_20 ;
F_6 ( V_15 ) ;
V_2 -> V_21 = V_2 -> V_22 = 0 ;
V_2 -> V_23 = V_2 -> V_24 = 0 ;
V_17 -> V_25 [ 0 ] = V_15 -> V_26 [ 1 ] ;
V_17 -> V_25 [ 1 ] = V_15 -> V_26 [ 0 ] ;
V_17 -> V_25 [ 2 ] = V_15 -> V_26 [ 3 ] ;
V_17 -> V_25 [ 3 ] = V_15 -> V_26 [ 2 ] ;
V_17 -> V_25 [ 4 ] = V_15 -> V_26 [ 5 ] ;
V_17 -> V_25 [ 5 ] = V_15 -> V_26 [ 4 ] ;
for ( V_20 = 0 ; V_20 < V_27 ; V_20 ++ ) {
V_3 = F_2 ( V_19 + F_7 ( V_28 , V_20 ) ) ;
V_17 -> V_29 [ V_20 ] . V_30 = V_3 ;
V_17 -> V_29 [ V_20 ] . V_31 = V_3 >> 16 ;
V_17 -> V_29 [ V_20 ] . V_32 = 0 ;
V_17 -> V_29 [ V_20 ] . V_33 = 0xf000 ;
V_17 -> V_29 [ V_20 ] . V_34 = 0 ;
}
for ( V_20 = 0 ; V_20 < V_35 ; V_20 ++ ) {
V_3 = F_2 ( V_19 + F_7 ( V_36 , V_20 ) ) ;
V_17 -> V_37 [ V_20 ] . V_38 = V_3 ;
V_17 -> V_37 [ V_20 ] . V_39 = V_3 >> 16 ;
V_17 -> V_37 [ V_20 ] . V_40 = V_41 ;
V_17 -> V_37 [ V_20 ] . V_33 = - V_42 | 0xf000 ;
V_17 -> V_37 [ V_20 ] . V_43 = 0 ;
}
V_3 = F_2 ( V_19 + F_8 ( V_37 , 0 ) ) ;
V_17 -> V_44 = ( V_45 << 13 ) | ( V_3 >> 16 ) ;
V_17 -> V_46 = V_3 ;
V_3 = F_2 ( V_19 + F_8 ( V_29 , 0 ) ) ;
V_17 -> V_47 = ( V_48 << 13 ) | ( V_3 >> 16 ) ;
V_17 -> V_49 = V_3 ;
}
static void F_9 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_5 ( V_15 ) ;
struct V_16 T_4 * V_17 = V_2 -> V_50 ;
T_1 V_3 ;
int V_20 ;
F_6 ( V_15 ) ;
V_2 -> V_21 = V_2 -> V_22 = 0 ;
V_2 -> V_23 = V_2 -> V_24 = 0 ;
F_10 ( V_15 -> V_26 [ 1 ] , & V_17 -> V_25 [ 0 ] ) ;
F_10 ( V_15 -> V_26 [ 0 ] , & V_17 -> V_25 [ 1 ] ) ;
F_10 ( V_15 -> V_26 [ 3 ] , & V_17 -> V_25 [ 2 ] ) ;
F_10 ( V_15 -> V_26 [ 2 ] , & V_17 -> V_25 [ 3 ] ) ;
F_10 ( V_15 -> V_26 [ 5 ] , & V_17 -> V_25 [ 4 ] ) ;
F_10 ( V_15 -> V_26 [ 4 ] , & V_17 -> V_25 [ 5 ] ) ;
for ( V_20 = 0 ; V_20 < V_27 ; V_20 ++ ) {
V_3 = F_7 ( V_28 , V_20 ) ;
F_3 ( V_3 , & V_17 -> V_29 [ V_20 ] . V_30 ) ;
F_10 ( V_3 >> 16 , & V_17 -> V_29 [ V_20 ] . V_31 ) ;
F_10 ( 0 , & V_17 -> V_29 [ V_20 ] . V_32 ) ;
F_3 ( 0xf000 , & V_17 -> V_29 [ V_20 ] . V_33 ) ;
F_3 ( 0 , & V_17 -> V_29 [ V_20 ] . V_34 ) ;
}
for ( V_20 = 0 ; V_20 < V_35 ; V_20 ++ ) {
V_3 = F_7 ( V_36 , V_20 ) ;
F_3 ( V_3 , & V_17 -> V_37 [ V_20 ] . V_38 ) ;
F_10 ( V_3 >> 16 , & V_17 -> V_37 [ V_20 ] . V_39 ) ;
F_10 ( V_41 , & V_17 -> V_37 [ V_20 ] . V_40 ) ;
F_3 ( - V_42 | 0xf000 ,
& V_17 -> V_37 [ V_20 ] . V_33 ) ;
F_3 ( 0 , & V_17 -> V_37 [ V_20 ] . V_43 ) ;
}
V_3 = F_8 ( V_37 , 0 ) ;
F_3 ( ( V_45 << 13 ) | ( V_3 >> 16 ) ,
& V_17 -> V_44 ) ;
F_3 ( V_3 , & V_17 -> V_46 ) ;
V_3 = F_8 ( V_29 , 0 ) ;
F_3 ( ( V_48 << 13 ) | ( V_3 >> 16 ) ,
& V_17 -> V_47 ) ;
F_3 ( V_3 , & V_17 -> V_49 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
T_1 V_51 = F_12 ( V_2 -> V_52 + V_53 ) ;
if ( ! ( V_51 & V_54 ) ) {
while ( F_12 ( V_2 -> V_52 + V_53 ) & V_55 )
F_13 () ;
}
V_51 = F_12 ( V_2 -> V_52 + V_53 ) ;
V_51 &= ~ V_56 ;
if ( V_2 -> V_57 & V_58 )
V_51 |= V_59 ;
else
V_51 |= V_60 ;
V_51 |= ( V_61 | V_62 | V_63 ) ;
if ( V_2 -> V_64 )
V_51 |= V_65 ;
else
V_51 &= ~ V_65 ;
F_14 ( 20 ) ;
F_15 ( V_51 , V_2 -> V_52 + V_53 ) ;
F_14 ( 200 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_5 V_66 = 0 ;
int V_20 ;
if ( V_2 -> V_52 )
F_11 ( V_2 ) ;
F_3 ( V_13 , V_2 -> V_7 + V_8 ) ;
F_3 ( V_67 , V_2 -> V_7 + V_9 ) ;
for ( V_20 = 0 ; V_20 < 100 ; V_20 ++ ) {
V_66 = F_17 ( V_2 -> V_7 + V_9 ) ;
if ( V_66 & ( V_68 | V_69 ) )
break;
F_13 () ;
}
if ( V_20 == 100 || ( V_66 & V_68 ) ) {
F_18 ( V_70 L_1 ,
V_20 , V_66 ) ;
if ( V_2 -> V_52 )
F_18 ( L_2 , F_12 ( V_2 -> V_52 + V_53 ) ) ;
return - 1 ;
}
F_3 ( V_69 , V_2 -> V_7 + V_9 ) ;
F_3 ( V_71 | V_72 , V_2 -> V_7 + V_9 ) ;
if ( V_2 -> V_52 ) {
T_1 V_51 = F_12 ( V_2 -> V_52 + V_53 ) ;
V_51 |= V_73 ;
F_15 ( V_51 , V_2 -> V_52 + V_53 ) ;
}
return 0 ;
}
static void F_19 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_5 ( V_15 ) ;
struct V_16 * V_17 = V_2 -> V_18 ;
struct V_74 * V_75 ;
T_6 V_76 ;
int V_77 , V_78 = V_2 -> V_21 ;
struct V_79 * V_80 ;
for ( V_75 = & V_17 -> V_37 [ V_78 ] ;
! ( ( V_76 = V_75 -> V_40 ) & V_41 ) ;
V_75 = & V_17 -> V_37 [ V_78 ] ) {
if ( ( V_76 & V_81 ) != V_81 ) {
V_15 -> V_82 . V_83 ++ ;
V_15 -> V_82 . V_84 ++ ;
} else if ( V_76 & V_85 ) {
if ( V_76 & V_86 ) V_15 -> V_82 . V_87 ++ ;
if ( V_76 & V_88 ) V_15 -> V_82 . V_89 ++ ;
if ( V_76 & V_90 ) V_15 -> V_82 . V_83 ++ ;
if ( V_76 & V_91 ) V_15 -> V_82 . V_92 ++ ;
if ( V_76 & V_93 ) V_15 -> V_82 . V_84 ++ ;
} else {
V_77 = ( V_75 -> V_43 & 0xfff ) - 4 ;
V_80 = F_20 ( V_15 , V_77 + 2 ) ;
if ( V_80 == NULL ) {
V_15 -> V_82 . V_94 ++ ;
V_75 -> V_43 = 0 ;
V_75 -> V_40 = V_41 ;
V_2 -> V_21 = F_21 ( V_78 ) ;
return;
}
V_15 -> V_82 . V_95 += V_77 ;
F_22 ( V_80 , 2 ) ;
F_23 ( V_80 , V_77 ) ;
F_24 ( V_80 ,
( unsigned char * ) & ( V_17 -> V_36 [ V_78 ] [ 0 ] ) ,
V_77 ) ;
V_80 -> V_96 = F_25 ( V_80 , V_15 ) ;
F_26 ( V_80 ) ;
V_15 -> V_82 . V_97 ++ ;
}
V_75 -> V_43 = 0 ;
V_75 -> V_40 = V_41 ;
V_78 = F_21 ( V_78 ) ;
}
V_2 -> V_21 = V_78 ;
}
static void F_27 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_5 ( V_15 ) ;
struct V_16 * V_17 = V_2 -> V_18 ;
int V_20 , V_98 ;
F_28 ( & V_2 -> V_99 ) ;
V_98 = V_2 -> V_24 ;
for ( V_20 = V_98 ; V_20 != V_2 -> V_22 ; V_20 = V_98 ) {
struct V_100 * V_101 = & V_17 -> V_29 [ V_20 ] ;
T_6 V_76 = V_101 -> V_32 ;
if ( V_76 & V_102 )
break;
if ( V_76 & V_103 ) {
T_5 V_104 = V_101 -> V_34 ;
V_15 -> V_82 . V_105 ++ ;
if ( V_104 & V_106 ) V_15 -> V_82 . V_107 ++ ;
if ( V_104 & V_108 ) V_15 -> V_82 . V_109 ++ ;
if ( V_104 & V_110 ) {
V_15 -> V_82 . V_111 ++ ;
if ( V_2 -> V_112 ) {
V_2 -> V_64 = 1 - V_2 -> V_64 ;
F_18 ( V_113 L_3 ,
V_15 -> V_114 , V_2 -> V_64 ? L_4 : L_5 ) ;
F_29 ( V_2 ) ;
V_2 -> V_115 ( V_15 ) ;
F_1 ( V_2 ) ;
F_16 ( V_2 ) ;
goto V_116;
}
}
if ( V_104 & ( V_117 | V_118 ) ) {
V_15 -> V_82 . V_119 ++ ;
F_18 ( V_70 L_6 ,
V_15 -> V_114 ) ;
F_29 ( V_2 ) ;
V_2 -> V_115 ( V_15 ) ;
F_1 ( V_2 ) ;
F_16 ( V_2 ) ;
goto V_116;
}
} else if ( ( V_76 & V_120 ) == V_120 ) {
V_101 -> V_32 = V_76 & ~ ( V_120 ) ;
if ( V_76 & V_121 )
V_15 -> V_82 . V_122 ++ ;
if ( V_76 & V_123 )
V_15 -> V_82 . V_122 += 2 ;
V_15 -> V_82 . V_124 ++ ;
}
V_98 = F_30 ( V_98 ) ;
}
V_2 -> V_24 = V_98 ;
V_116:
if ( F_31 ( V_15 ) &&
V_125 > 0 )
F_32 ( V_15 ) ;
F_33 ( & V_2 -> V_99 ) ;
}
static void F_34 ( struct V_79 * V_80 , void T_4 * V_126 , int V_77 )
{
T_5 * V_127 = ( T_5 * ) V_80 -> V_128 ;
T_1 * V_129 ;
T_6 * V_130 ;
void T_4 * V_131 = V_126 ;
* V_127 ++ = F_17 ( V_131 ) ;
V_129 = ( T_1 * ) V_127 ;
V_131 += 2 ;
V_77 -= 2 ;
while ( V_77 >= 4 ) {
* V_129 ++ = F_12 ( V_131 ) ;
V_131 += 4 ;
V_77 -= 4 ;
}
V_130 = ( T_6 * ) V_129 ;
if ( V_77 >= 2 ) {
V_127 = ( T_5 * ) V_129 ;
* V_127 ++ = F_17 ( V_131 ) ;
V_131 += 2 ;
V_77 -= 2 ;
V_130 = ( T_6 * ) V_127 ;
}
if ( V_77 >= 1 )
* V_130 = F_35 ( V_131 ) ;
}
static void F_36 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_5 ( V_15 ) ;
struct V_16 T_4 * V_17 = V_2 -> V_50 ;
struct V_74 T_4 * V_75 ;
unsigned char V_76 ;
int V_77 , V_78 ;
struct V_79 * V_80 ;
V_78 = V_2 -> V_21 ;
for ( V_75 = & V_17 -> V_37 [ V_78 ] ;
! ( ( V_76 = F_35 ( & V_75 -> V_40 ) ) & V_41 ) ;
V_75 = & V_17 -> V_37 [ V_78 ] ) {
if ( ( V_76 & V_81 ) != V_81 ) {
V_15 -> V_82 . V_83 ++ ;
V_15 -> V_82 . V_84 ++ ;
} else if ( V_76 & V_85 ) {
if ( V_76 & V_86 ) V_15 -> V_82 . V_87 ++ ;
if ( V_76 & V_88 ) V_15 -> V_82 . V_89 ++ ;
if ( V_76 & V_90 ) V_15 -> V_82 . V_83 ++ ;
if ( V_76 & V_91 ) V_15 -> V_82 . V_92 ++ ;
if ( V_76 & V_93 ) V_15 -> V_82 . V_84 ++ ;
} else {
V_77 = ( F_17 ( & V_75 -> V_43 ) & 0xfff ) - 4 ;
V_80 = F_20 ( V_15 , V_77 + 2 ) ;
if ( V_80 == NULL ) {
V_15 -> V_82 . V_94 ++ ;
F_3 ( 0 , & V_75 -> V_43 ) ;
F_10 ( V_41 , & V_75 -> V_40 ) ;
V_2 -> V_21 = F_21 ( V_78 ) ;
return;
}
V_15 -> V_82 . V_95 += V_77 ;
F_22 ( V_80 , 2 ) ;
F_23 ( V_80 , V_77 ) ;
F_34 ( V_80 , & ( V_17 -> V_36 [ V_78 ] [ 0 ] ) , V_77 ) ;
V_80 -> V_96 = F_25 ( V_80 , V_15 ) ;
F_26 ( V_80 ) ;
V_15 -> V_82 . V_97 ++ ;
}
F_3 ( 0 , & V_75 -> V_43 ) ;
F_10 ( V_41 , & V_75 -> V_40 ) ;
V_78 = F_21 ( V_78 ) ;
}
V_2 -> V_21 = V_78 ;
}
static void F_37 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_5 ( V_15 ) ;
struct V_16 T_4 * V_17 = V_2 -> V_50 ;
int V_20 , V_98 ;
F_28 ( & V_2 -> V_99 ) ;
V_98 = V_2 -> V_24 ;
for ( V_20 = V_98 ; V_20 != V_2 -> V_22 ; V_20 = V_98 ) {
struct V_100 T_4 * V_101 = & V_17 -> V_29 [ V_20 ] ;
T_6 V_76 = F_35 ( & V_101 -> V_32 ) ;
if ( V_76 & V_102 )
break;
if ( V_76 & V_103 ) {
T_5 V_104 = F_17 ( & V_101 -> V_34 ) ;
V_15 -> V_82 . V_105 ++ ;
if ( V_104 & V_106 ) V_15 -> V_82 . V_107 ++ ;
if ( V_104 & V_108 ) V_15 -> V_82 . V_109 ++ ;
if ( V_104 & V_110 ) {
V_15 -> V_82 . V_111 ++ ;
if ( V_2 -> V_112 ) {
V_2 -> V_64 = 1 - V_2 -> V_64 ;
F_18 ( V_113 L_3 ,
V_15 -> V_114 , V_2 -> V_64 ? L_4 : L_5 ) ;
F_29 ( V_2 ) ;
V_2 -> V_115 ( V_15 ) ;
F_1 ( V_2 ) ;
F_16 ( V_2 ) ;
goto V_116;
}
}
if ( V_104 & ( V_117 | V_118 ) ) {
V_15 -> V_82 . V_119 ++ ;
F_18 ( V_70 L_6 ,
V_15 -> V_114 ) ;
F_29 ( V_2 ) ;
V_2 -> V_115 ( V_15 ) ;
F_1 ( V_2 ) ;
F_16 ( V_2 ) ;
goto V_116;
}
} else if ( ( V_76 & V_120 ) == V_120 ) {
F_10 ( V_76 & ~ ( V_120 ) , & V_101 -> V_32 ) ;
if ( V_76 & V_121 )
V_15 -> V_82 . V_122 ++ ;
if ( V_76 & V_123 )
V_15 -> V_82 . V_122 += 2 ;
V_15 -> V_82 . V_124 ++ ;
}
V_98 = F_30 ( V_98 ) ;
}
V_2 -> V_24 = V_98 ;
if ( F_31 ( V_15 ) &&
V_125 > 0 )
F_32 ( V_15 ) ;
V_116:
F_33 ( & V_2 -> V_99 ) ;
}
static T_7 F_38 ( int V_132 , void * V_133 )
{
struct V_14 * V_15 = V_133 ;
struct V_1 * V_2 = F_5 ( V_15 ) ;
int V_134 ;
F_3 ( V_13 , V_2 -> V_7 + V_8 ) ;
V_134 = F_17 ( V_2 -> V_7 + V_9 ) ;
F_3 ( V_134 & ( V_135 | V_136 | V_137 ) ,
V_2 -> V_7 + V_9 ) ;
if ( ( V_134 & V_68 ) != 0 ) {
F_3 ( ( V_138 | V_68 | V_139 |
V_140 | V_141 ) ,
V_2 -> V_7 + V_9 ) ;
}
if ( V_134 & V_137 )
V_2 -> V_142 ( V_15 ) ;
if ( V_134 & V_136 )
V_2 -> V_143 ( V_15 ) ;
if ( V_134 & V_138 )
V_15 -> V_82 . V_105 ++ ;
if ( V_134 & V_139 )
V_15 -> V_82 . V_84 ++ ;
if ( V_134 & V_141 ) {
if ( V_2 -> V_52 ) {
T_1 V_144 = F_12 ( V_2 -> V_52 + V_145 ) ;
F_18 ( V_70 L_7 ,
V_15 -> V_114 , V_134 , V_144 & 0xffffff ) ;
} else {
F_18 ( V_70 L_8 ,
V_15 -> V_114 , V_134 ) ;
}
F_3 ( V_146 , V_2 -> V_7 + V_9 ) ;
if ( V_2 -> V_52 ) {
T_1 V_147 = F_12 ( V_2 -> V_52 + V_53 ) ;
V_147 |= V_63 ;
F_15 ( V_147 , V_2 -> V_52 + V_53 ) ;
}
V_2 -> V_115 ( V_15 ) ;
F_1 ( V_2 ) ;
F_16 ( V_2 ) ;
F_32 ( V_15 ) ;
}
F_3 ( V_71 , V_2 -> V_7 + V_9 ) ;
return V_148 ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
int V_20 , V_78 ;
V_78 = V_2 -> V_22 & V_149 ;
if ( V_2 -> V_4 ) {
struct V_16 T_4 * V_17 = V_2 -> V_50 ;
T_5 T_4 * V_150 = ( T_5 T_4 * ) & ( V_17 -> V_28 [ V_78 ] [ 0 ] ) ;
struct V_151 T_4 * V_152 = (struct V_151 T_4 * ) V_150 ;
for ( V_20 = 0 ; V_20 < ( V_153 / sizeof( T_5 ) ) ; V_20 ++ )
F_3 ( 0 , & V_150 [ V_20 ] ) ;
for ( V_20 = 0 ; V_20 < 6 ; V_20 ++ ) {
F_10 ( V_15 -> V_26 [ V_20 ] , & V_152 -> V_154 [ V_20 ] ) ;
F_10 ( V_15 -> V_26 [ V_20 ] , & V_152 -> V_155 [ V_20 ] ) ;
}
F_3 ( ( - V_153 ) | 0xf000 , & V_17 -> V_29 [ V_78 ] . V_33 ) ;
F_3 ( 0 , & V_17 -> V_29 [ V_78 ] . V_34 ) ;
F_10 ( V_120 | V_102 , & V_17 -> V_29 [ V_78 ] . V_32 ) ;
} else {
struct V_16 * V_17 = V_2 -> V_18 ;
T_5 * V_150 = ( T_5 * ) & ( V_17 -> V_28 [ V_78 ] [ 0 ] ) ;
struct V_151 * V_152 = (struct V_151 * ) V_150 ;
memset ( V_150 , 0 , V_153 ) ;
for ( V_20 = 0 ; V_20 < 6 ; V_20 ++ ) {
V_152 -> V_154 [ V_20 ] = V_15 -> V_26 [ V_20 ] ;
V_152 -> V_155 [ V_20 ] = V_15 -> V_26 [ V_20 ] ;
}
V_17 -> V_29 [ V_78 ] . V_33 = ( - V_153 ) | 0xf000 ;
V_17 -> V_29 [ V_78 ] . V_34 = 0 ;
V_17 -> V_29 [ V_78 ] . V_32 = ( V_120 | V_102 ) ;
}
V_2 -> V_22 = F_30 ( V_78 ) ;
}
static int F_40 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_5 ( V_15 ) ;
int V_104 = 0 ;
F_29 ( V_2 ) ;
if ( F_41 ( V_15 -> V_132 , F_38 , V_156 ,
V_157 , ( void * ) V_15 ) ) {
F_18 ( V_70 L_9 , V_15 -> V_132 ) ;
return - V_158 ;
}
if ( V_2 -> V_52 ) {
T_1 V_66 = V_2 -> V_5 & 0xff000000 ;
F_15 ( V_66 , V_2 -> V_52 + V_159 ) ;
}
if ( V_2 -> V_4 ) {
struct V_16 T_4 * V_17 = V_2 -> V_50 ;
F_3 ( 0 , & V_17 -> V_160 ) ;
F_15 ( 0 , & V_17 -> V_161 [ 0 ] ) ;
F_15 ( 0 , & V_17 -> V_161 [ 1 ] ) ;
} else {
struct V_16 * V_17 = V_2 -> V_18 ;
V_17 -> V_160 = 0 ;
V_17 -> V_161 [ 0 ] = 0 ;
V_17 -> V_161 [ 1 ] = 0 ;
}
V_2 -> V_115 ( V_15 ) ;
F_1 ( V_2 ) ;
F_42 ( V_15 ) ;
V_104 = F_16 ( V_2 ) ;
if ( ! V_104 && V_2 -> V_112 ) {
F_39 ( V_2 ) ;
F_3 ( V_71 | V_162 , V_2 -> V_7 + V_9 ) ;
}
return V_104 ;
}
static int F_43 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_5 ( V_15 ) ;
F_6 ( V_15 ) ;
F_44 ( & V_2 -> V_163 ) ;
F_29 ( V_2 ) ;
F_45 ( V_15 -> V_132 , ( void * ) V_15 ) ;
return 0 ;
}
static int F_46 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_5 ( V_15 ) ;
int V_104 ;
F_29 ( V_2 ) ;
if ( V_2 -> V_52 ) {
T_1 V_51 , V_144 ;
F_18 ( V_70 L_10 ) ;
V_51 = F_12 ( V_2 -> V_52 + V_53 ) ;
F_15 ( V_51 | V_164 , V_2 -> V_52 + V_53 ) ;
F_14 ( 200 ) ;
F_15 ( V_51 & ~ V_164 , V_2 -> V_52 + V_53 ) ;
V_144 = V_2 -> V_5 & 0xff000000 ;
F_15 ( V_144 , V_2 -> V_52 + V_159 ) ;
}
V_2 -> V_115 ( V_15 ) ;
F_1 ( V_2 ) ;
V_15 -> V_165 = V_166 ;
V_104 = F_16 ( V_2 ) ;
return V_104 ;
}
static void F_47 ( void T_4 * V_167 , unsigned char * V_168 , int V_77 )
{
void T_4 * V_126 = V_167 ;
T_1 * V_129 ;
T_5 * V_127 ;
T_6 * V_130 ;
switch ( ( unsigned long ) V_168 & 0x3 ) {
case 0 :
V_129 = ( T_1 * ) V_168 ;
while ( V_77 >= 4 ) {
F_15 ( * V_129 , V_126 ) ;
V_129 ++ ;
V_126 += 4 ;
V_77 -= 4 ;
}
V_168 = ( char * ) V_129 ;
break;
case 1 :
case 3 :
V_130 = ( T_6 * ) V_168 ;
while ( V_77 >= 4 ) {
T_1 V_169 ;
V_169 = V_130 [ 0 ] << 24 ;
V_169 |= V_130 [ 1 ] << 16 ;
V_169 |= V_130 [ 2 ] << 8 ;
V_169 |= V_130 [ 3 ] ;
F_15 ( V_169 , V_126 ) ;
V_130 += 4 ;
V_126 += 4 ;
V_77 -= 4 ;
}
V_168 = ( char * ) V_130 ;
break;
case 2 :
V_127 = ( T_5 * ) V_168 ;
while ( V_77 >= 4 ) {
T_1 V_169 = V_127 [ 0 ] << 16 | V_127 [ 1 ] ;
F_15 ( V_169 , V_126 ) ;
V_127 += 2 ;
V_126 += 4 ;
V_77 -= 4 ;
}
V_168 = ( char * ) V_127 ;
break;
}
if ( V_77 >= 2 ) {
T_5 V_169 = V_168 [ 0 ] << 8 | V_168 [ 1 ] ;
F_3 ( V_169 , V_126 ) ;
V_168 += 2 ;
V_126 += 2 ;
V_77 -= 2 ;
}
if ( V_77 >= 1 )
F_10 ( V_168 [ 0 ] , V_126 ) ;
}
static void F_48 ( void T_4 * V_167 , int V_77 )
{
void T_4 * V_126 = V_167 ;
if ( ( unsigned long ) V_126 & 1 ) {
F_10 ( 0 , V_126 ) ;
V_126 += 1 ;
V_77 -= 1 ;
if ( V_77 == 0 )
return;
}
if ( V_77 == 1 ) {
F_10 ( 0 , V_126 ) ;
return;
}
if ( ( unsigned long ) V_126 & 2 ) {
F_3 ( 0 , V_126 ) ;
V_126 += 2 ;
V_77 -= 2 ;
if ( V_77 == 0 )
return;
}
while ( V_77 >= 4 ) {
F_15 ( 0 , V_126 ) ;
V_126 += 4 ;
V_77 -= 4 ;
}
if ( V_77 >= 2 ) {
F_3 ( 0 , V_126 ) ;
V_126 += 2 ;
V_77 -= 2 ;
}
if ( V_77 >= 1 )
F_10 ( 0 , V_126 ) ;
}
static void F_49 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_5 ( V_15 ) ;
F_18 ( V_70 L_11 ,
V_15 -> V_114 , F_17 ( V_2 -> V_7 + V_9 ) ) ;
F_46 ( V_15 ) ;
F_32 ( V_15 ) ;
}
static int F_50 ( struct V_79 * V_80 , struct V_14 * V_15 )
{
struct V_1 * V_2 = F_5 ( V_15 ) ;
int V_78 , V_170 , V_77 ;
V_170 = V_80 -> V_77 ;
V_77 = ( V_170 <= V_153 ) ? V_153 : V_170 ;
F_51 ( & V_2 -> V_99 ) ;
V_15 -> V_82 . V_171 += V_77 ;
V_78 = V_2 -> V_22 & V_149 ;
if ( V_2 -> V_4 ) {
struct V_16 T_4 * V_17 = V_2 -> V_50 ;
F_3 ( ( - V_77 ) | 0xf000 , & V_17 -> V_29 [ V_78 ] . V_33 ) ;
F_3 ( 0 , & V_17 -> V_29 [ V_78 ] . V_34 ) ;
F_47 ( & V_17 -> V_28 [ V_78 ] [ 0 ] , V_80 -> V_128 , V_170 ) ;
if ( V_77 != V_170 )
F_48 ( & V_17 -> V_28 [ V_78 ] [ V_170 ] , V_77 - V_170 ) ;
F_10 ( V_120 | V_102 , & V_17 -> V_29 [ V_78 ] . V_32 ) ;
} else {
struct V_16 * V_17 = V_2 -> V_18 ;
V_17 -> V_29 [ V_78 ] . V_33 = ( - V_77 ) | 0xf000 ;
V_17 -> V_29 [ V_78 ] . V_34 = 0 ;
F_52 ( V_80 , & V_17 -> V_28 [ V_78 ] [ 0 ] , V_170 ) ;
if ( V_77 != V_170 )
memset ( ( char * ) & V_17 -> V_28 [ V_78 ] [ V_170 ] , 0 , V_77 - V_170 ) ;
V_17 -> V_29 [ V_78 ] . V_32 = ( V_120 | V_102 ) ;
}
V_2 -> V_22 = F_30 ( V_78 ) ;
if ( V_125 <= 0 )
F_6 ( V_15 ) ;
F_3 ( V_71 | V_162 , V_2 -> V_7 + V_9 ) ;
if ( V_2 -> V_52 )
F_17 ( V_2 -> V_7 + V_9 ) ;
F_53 ( & V_2 -> V_99 ) ;
F_54 ( V_80 ) ;
return V_172 ;
}
static void F_55 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_5 ( V_15 ) ;
struct V_173 * V_174 ;
T_1 V_175 ;
T_1 V_169 ;
if ( V_15 -> V_176 & V_177 )
V_169 = ~ 0 ;
else
V_169 = 0 ;
if ( V_2 -> V_4 ) {
struct V_16 T_4 * V_17 = V_2 -> V_50 ;
F_15 ( V_169 , & V_17 -> V_161 [ 0 ] ) ;
F_15 ( V_169 , & V_17 -> V_161 [ 1 ] ) ;
} else {
struct V_16 * V_17 = V_2 -> V_18 ;
V_17 -> V_161 [ 0 ] = V_169 ;
V_17 -> V_161 [ 1 ] = V_169 ;
}
if ( V_15 -> V_176 & V_177 )
return;
F_56 (ha, dev) {
V_175 = F_57 ( 6 , V_174 -> V_144 ) ;
V_175 = V_175 >> 26 ;
if ( V_2 -> V_4 ) {
struct V_16 T_4 * V_17 = V_2 -> V_50 ;
T_5 T_4 * V_178 = ( T_5 T_4 * ) & V_17 -> V_161 ;
T_5 V_179 = F_17 ( & V_178 [ V_175 >> 4 ] ) ;
V_179 |= 1 << ( V_175 & 0xf ) ;
F_3 ( V_179 , & V_178 [ V_175 >> 4 ] ) ;
} else {
struct V_16 * V_17 = V_2 -> V_18 ;
T_5 * V_178 = ( T_5 * ) & V_17 -> V_161 ;
V_178 [ V_175 >> 4 ] |= 1 << ( V_175 & 0xf ) ;
}
}
}
static void F_58 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_5 ( V_15 ) ;
struct V_16 * V_180 = V_2 -> V_18 ;
struct V_16 T_4 * V_181 = V_2 -> V_50 ;
T_5 V_160 ;
if ( ! F_59 ( V_15 ) )
return;
if ( V_2 -> V_24 != V_2 -> V_22 ) {
F_60 ( & V_2 -> V_163 , V_166 + 4 ) ;
F_32 ( V_15 ) ;
return;
}
F_6 ( V_15 ) ;
F_29 ( V_2 ) ;
V_2 -> V_115 ( V_15 ) ;
if ( V_2 -> V_4 )
V_160 = F_17 ( & V_181 -> V_160 ) ;
else
V_160 = V_180 -> V_160 ;
if ( V_15 -> V_176 & V_182 ) {
V_160 |= V_183 ;
if ( V_2 -> V_4 )
F_3 ( V_160 , & V_181 -> V_160 ) ;
else
V_180 -> V_160 = V_160 ;
} else {
V_160 &= ~ V_183 ;
if ( V_2 -> V_4 )
F_3 ( V_160 , & V_181 -> V_160 ) ;
else
V_180 -> V_160 = V_160 ;
F_55 ( V_15 ) ;
}
F_1 ( V_2 ) ;
F_16 ( V_2 ) ;
F_32 ( V_15 ) ;
}
static void F_61 ( unsigned long V_184 )
{
struct V_14 * V_15 = (struct V_14 * ) V_184 ;
F_58 ( V_15 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 )
F_63 ( & V_2 -> V_185 -> V_186 [ 0 ] , V_2 -> V_7 , V_187 ) ;
if ( V_2 -> V_52 ) {
struct V_188 * V_189 = V_2 -> V_189 ;
F_63 ( & V_189 -> V_186 [ 0 ] , V_2 -> V_52 ,
F_64 ( & V_189 -> V_186 [ 0 ] ) ) ;
}
if ( V_2 -> V_50 ) {
F_63 ( & V_2 -> V_190 -> V_186 [ 0 ] , V_2 -> V_50 ,
sizeof( struct V_16 ) ) ;
} else if ( V_2 -> V_18 ) {
F_65 ( & V_2 -> V_185 -> V_15 ,
sizeof( struct V_16 ) ,
V_2 -> V_18 ,
V_2 -> V_5 ) ;
}
}
static void F_66 ( struct V_14 * V_15 , struct V_191 * V_192 )
{
F_67 ( V_192 -> V_193 , L_12 , sizeof( V_192 -> V_193 ) ) ;
F_67 ( V_192 -> V_194 , L_13 , sizeof( V_192 -> V_194 ) ) ;
}
static int F_68 ( struct V_188 * V_185 ,
struct V_188 * V_189 ,
struct V_188 * V_190 )
{
struct V_195 * V_196 = V_185 -> V_15 . V_197 ;
static unsigned V_198 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
int V_20 ;
V_15 = F_69 ( sizeof( struct V_1 ) + 8 ) ;
if ( ! V_15 )
return - V_199 ;
V_2 = F_5 ( V_15 ) ;
if ( V_200 && V_198 ++ == 0 )
F_18 ( V_201 L_14 , V_194 ) ;
F_70 ( & V_2 -> V_99 ) ;
for ( V_20 = 0 ; V_20 < 6 ; V_20 ++ )
V_15 -> V_26 [ V_20 ] = V_202 -> V_203 [ V_20 ] ;
V_2 -> V_7 = F_71 ( & V_185 -> V_186 [ 0 ] , 0 ,
V_187 , V_157 ) ;
if ( ! V_2 -> V_7 ) {
F_18 ( V_70 L_15 ) ;
goto V_204;
}
V_2 -> V_189 = V_189 ;
if ( V_2 -> V_189 ) {
V_2 -> V_52 = F_71 ( & V_189 -> V_186 [ 0 ] , 0 ,
F_64 ( & V_189 -> V_186 [ 0 ] ) ,
L_16 ) ;
if ( ! V_2 -> V_52 ) {
F_18 ( V_70 L_17
L_18 ) ;
goto V_204;
}
}
V_2 -> V_185 = V_185 ;
V_2 -> V_190 = V_190 ;
if ( V_190 ) {
if ( V_190 -> V_186 [ 0 ] . V_205 & 7 ) {
F_18 ( V_70 L_19 ) ;
goto V_204;
}
V_2 -> V_50 =
F_71 ( & V_190 -> V_186 [ 0 ] , 0 ,
sizeof( struct V_16 ) , L_20 ) ;
if ( ! V_2 -> V_50 ) {
F_18 ( V_70 L_21 ) ;
goto V_204;
}
V_2 -> V_5 = 0 ;
V_2 -> V_4 = 1 ;
V_2 -> V_115 = F_9 ;
V_2 -> V_142 = F_36 ;
V_2 -> V_143 = F_37 ;
} else {
V_2 -> V_18 =
F_72 ( & V_185 -> V_15 ,
sizeof( struct V_16 ) ,
& V_2 -> V_5 , V_206 ) ;
if ( ! V_2 -> V_18 )
goto V_204;
V_2 -> V_4 = 0 ;
V_2 -> V_115 = F_4 ;
V_2 -> V_142 = F_19 ;
V_2 -> V_143 = F_27 ;
}
V_2 -> V_12 = F_73 ( V_196 , L_22 ,
( V_207 |
V_208 |
V_209 ) ) ;
V_2 -> V_114 = V_157 ;
V_2 -> V_57 = 0 ;
if ( V_2 -> V_189 ) {
struct V_195 * V_210 = V_189 -> V_15 . V_197 ;
struct V_195 * V_211 ;
unsigned int V_212 ;
const char * V_213 ;
T_1 V_51 ;
V_2 -> V_57 = F_73 ( V_210 ,
L_23 , 0 ) ;
V_211 = V_210 -> V_214 ;
V_212 = F_73 ( V_211 , L_23 ,
V_215 ) ;
V_2 -> V_57 &= V_212 ;
V_213 = F_74 ( V_210 , L_24 , NULL ) ;
if ( ! V_213 || V_213 [ 0 ] == '\0' ) {
struct V_195 * V_216 ;
F_18 ( V_201 L_25
L_26 ) ;
V_216 = F_75 ( L_27 ) ;
if ( ! V_216 )
goto V_217;
V_213 = F_74 ( V_216 , L_28 , NULL ) ;
if ( ! V_213 )
goto V_217;
if ( strcmp ( V_213 , L_29 ) ) {
F_18 ( V_113 L_30
L_31 ) ;
F_18 ( V_113 L_32
L_33 ) ;
F_76 ( V_218 ) ;
}
V_217:
V_2 -> V_112 = 1 ;
V_2 -> V_64 = 0 ;
} else if ( ! strcmp ( V_213 , L_34 ) ) {
V_2 -> V_112 = 0 ;
V_2 -> V_64 = 0 ;
} else {
V_2 -> V_112 = 0 ;
V_2 -> V_64 = 1 ;
}
V_51 = F_12 ( V_2 -> V_52 + V_53 ) ;
F_15 ( V_51 | V_164 , V_2 -> V_52 + V_53 ) ;
F_14 ( 200 ) ;
F_15 ( V_51 & ~ V_164 , V_2 -> V_52 + V_53 ) ;
} else
V_2 -> V_52 = NULL ;
V_2 -> V_15 = V_15 ;
F_77 ( V_15 , & V_185 -> V_15 ) ;
V_15 -> V_219 = 5 * V_220 ;
V_15 -> V_221 = & V_222 ;
V_15 -> V_223 = & V_224 ;
V_15 -> V_132 = V_185 -> V_225 . V_226 [ 0 ] ;
F_78 ( & V_2 -> V_163 ) ;
V_2 -> V_163 . V_128 = ( unsigned long ) V_15 ;
V_2 -> V_163 . V_227 = F_61 ;
if ( F_79 ( V_15 ) ) {
F_18 ( V_70 L_35 ) ;
goto V_204;
}
F_80 ( & V_185 -> V_15 , V_2 ) ;
F_18 ( V_201 L_36 ,
V_15 -> V_114 , V_15 -> V_26 ) ;
return 0 ;
V_204:
F_62 ( V_2 ) ;
F_81 ( V_15 ) ;
return - V_228 ;
}
static int F_82 ( struct V_188 * V_185 )
{
struct V_188 * V_214 = F_83 ( V_185 -> V_15 . V_214 ) ;
struct V_195 * V_229 = V_214 -> V_15 . V_197 ;
int V_230 ;
if ( ! strcmp ( V_229 -> V_114 , L_16 ) ) {
V_230 = F_68 ( V_185 , V_214 , NULL ) ;
} else if ( ! strcmp ( V_229 -> V_114 , L_20 ) ) {
V_230 = F_68 ( V_185 , NULL , V_214 ) ;
} else
V_230 = F_68 ( V_185 , NULL , NULL ) ;
return V_230 ;
}
static int F_84 ( struct V_188 * V_185 )
{
struct V_1 * V_2 = F_85 ( & V_185 -> V_15 ) ;
struct V_14 * V_231 = V_2 -> V_15 ;
F_86 ( V_231 ) ;
F_62 ( V_2 ) ;
F_81 ( V_231 ) ;
F_80 ( & V_185 -> V_15 , NULL ) ;
return 0 ;
}
