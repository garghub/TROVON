static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
if ( V_6 > 2 )
F_3 ( L_1 ) ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
struct V_8 * V_9 = F_4 ( V_2 , V_10 + 2 ) ;
if ( V_9 == NULL ) {
while( V_5 > 0 ) {
V_5 -- ;
F_5 ( V_4 -> V_11 [ V_5 ] ) ;
V_4 -> V_11 [ V_5 ] = NULL ;
}
F_3 ( V_12 L_2 ,
V_2 -> V_13 ) ;
return - V_14 ;
}
if ( F_6 ( V_4 -> V_15 ) == 2 )
F_7 ( V_9 , 2 ) ;
V_4 -> V_11 [ V_5 ] = V_9 ;
}
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
T_1 V_16 = F_8 ( V_4 -> V_17 , F_9 ( V_4 -> V_11 [ V_5 ] , V_10 ) ,
V_10 , V_18 ) ;
if ( ! V_16 ) {
while( V_5 > 0 ) {
V_5 -- ;
F_10 ( V_4 -> V_17 , V_4 -> V_19 [ V_5 ] , V_10 , V_18 ) ;
V_4 -> V_19 [ V_5 ] = ( T_1 ) 0 ;
}
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
F_5 ( V_4 -> V_11 [ V_5 ] ) ;
V_4 -> V_11 [ V_5 ] = NULL ;
}
F_3 ( V_12 L_3 ,
V_2 -> V_13 ) ;
return - V_14 ;
}
V_4 -> V_19 [ V_5 ] = V_16 ;
}
F_11 ( V_2 ) ;
F_12 ( V_2 ) ;
if ( V_6 > 2 )
F_3 ( L_4 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
if ( V_6 > 2 )
F_3 ( L_5 ) ;
F_14 ( V_2 ) ;
F_15 ( V_20 , 0 ) ;
F_15 ( V_21 , 0x7fff ) ;
F_15 ( V_22 , V_23 ) ;
for ( V_5 = 0 ; V_5 < V_24 ; V_5 ++ ) {
if( V_4 -> V_25 [ V_5 ] ) {
F_10 ( V_4 -> V_17 , V_4 -> V_25 [ V_5 ] , V_4 -> V_26 [ V_5 ] , V_27 ) ;
V_4 -> V_25 [ V_5 ] = ( T_1 ) 0 ;
}
if( V_4 -> V_28 [ V_5 ] ) {
F_5 ( V_4 -> V_28 [ V_5 ] ) ;
V_4 -> V_28 [ V_5 ] = NULL ;
}
}
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
if( V_4 -> V_19 [ V_5 ] ) {
F_10 ( V_4 -> V_17 , V_4 -> V_19 [ V_5 ] , V_10 , V_18 ) ;
V_4 -> V_19 [ V_5 ] = ( T_1 ) 0 ;
}
if( V_4 -> V_11 [ V_5 ] ) {
F_5 ( V_4 -> V_11 [ V_5 ] ) ;
V_4 -> V_11 [ V_5 ] = NULL ;
}
}
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
F_15 ( V_20 , 0 ) ;
F_15 ( V_21 , 0x7fff ) ;
F_15 ( V_22 , V_23 ) ;
for ( V_5 = 0 ; V_5 < V_24 ; V_5 ++ ) {
if( V_4 -> V_25 [ V_5 ] ) {
F_10 ( V_4 -> V_17 , V_4 -> V_25 [ V_5 ] , V_4 -> V_26 [ V_5 ] , V_27 ) ;
V_4 -> V_25 [ V_5 ] = ( T_1 ) 0 ;
}
if( V_4 -> V_28 [ V_5 ] ) {
F_5 ( V_4 -> V_28 [ V_5 ] ) ;
V_4 -> V_28 [ V_5 ] = NULL ;
}
}
F_11 ( V_2 ) ;
V_4 -> V_29 . V_30 ++ ;
V_2 -> V_31 = V_32 ;
F_17 ( V_2 ) ;
}
static int F_18 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_16 ;
int V_33 ;
int V_34 = V_4 -> V_35 ;
if ( V_6 > 2 )
F_3 ( L_6 , V_9 , V_2 ) ;
V_33 = V_9 -> V_36 ;
if ( V_33 < V_37 ) {
if ( F_19 ( V_9 , V_37 ) )
return V_38 ;
V_33 = V_37 ;
}
V_16 = F_8 ( V_4 -> V_17 , V_9 -> V_39 , V_33 , V_27 ) ;
if ( ! V_16 ) {
F_3 ( V_12 L_7 , V_2 -> V_13 ) ;
F_5 ( V_9 ) ;
return V_40 ;
}
F_20 ( V_2 , V_34 , V_41 , 0 ) ;
F_20 ( V_2 , V_34 , V_42 , 1 ) ;
F_20 ( V_2 , V_34 , V_43 , V_33 ) ;
F_20 ( V_2 , V_34 , V_44 , V_16 & 0xffff ) ;
F_20 ( V_2 , V_34 , V_45 , V_16 >> 16 ) ;
F_20 ( V_2 , V_34 , V_46 , V_33 ) ;
F_20 ( V_2 , V_34 , V_47 ,
F_21 ( V_2 , V_34 , V_47 ) | V_48 ) ;
F_22 () ;
V_4 -> V_26 [ V_34 ] = V_33 ;
V_4 -> V_25 [ V_34 ] = V_16 ;
V_4 -> V_28 [ V_34 ] = V_9 ;
F_22 () ;
F_20 ( V_2 , V_4 -> V_49 , V_47 ,
F_21 ( V_2 , V_4 -> V_49 , V_47 ) & ~ V_48 ) ;
V_4 -> V_49 = V_34 ;
V_4 -> V_35 = ( V_34 + 1 ) & V_50 ;
if ( V_4 -> V_28 [ V_4 -> V_35 ] != NULL ) {
if ( V_6 > 3 )
F_3 ( L_8 , V_2 -> V_13 ) ;
F_14 ( V_2 ) ;
} else F_12 ( V_2 ) ;
if ( V_6 > 2 )
F_3 ( L_9 ) ;
F_15 ( V_22 , V_51 ) ;
return V_38 ;
}
static T_2 F_23 ( int V_52 , void * V_53 )
{
struct V_1 * V_2 = V_53 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_54 ;
if ( ! ( V_54 = F_24 ( V_21 ) & V_55 ) )
return V_56 ;
do {
if ( V_54 & V_57 ) {
if ( V_6 > 2 )
F_3 ( L_10 , V_2 -> V_13 ) ;
F_25 ( V_2 ) ;
F_15 ( V_21 , V_57 ) ;
}
if ( V_54 & V_58 ) {
int V_34 = V_4 -> V_59 ;
int V_60 ;
int V_61 = 0 ;
if ( V_6 > 2 )
F_3 ( L_11 , V_2 -> V_13 ) ;
while ( V_4 -> V_28 [ V_34 ] != NULL ) {
if ( ( V_60 = F_21 ( V_2 , V_34 , V_41 ) ) == 0 )
break;
if ( V_60 & 0x0001 ) {
V_4 -> V_29 . V_62 ++ ;
V_4 -> V_29 . V_63 += F_21 ( V_2 , V_34 , V_43 ) ;
} else {
V_4 -> V_29 . V_30 ++ ;
if ( V_60 & 0x0642 )
V_4 -> V_29 . V_64 ++ ;
if ( V_60 & 0x0180 )
V_4 -> V_29 . V_65 ++ ;
if ( V_60 & 0x0020 )
V_4 -> V_29 . V_66 ++ ;
if ( V_60 & 0x0004 )
V_4 -> V_29 . V_67 ++ ;
}
F_26 ( V_4 -> V_28 [ V_34 ] ) ;
V_4 -> V_28 [ V_34 ] = NULL ;
F_10 ( V_4 -> V_17 , V_4 -> V_25 [ V_34 ] , V_4 -> V_26 [ V_34 ] , V_27 ) ;
V_4 -> V_25 [ V_34 ] = ( T_1 ) 0 ;
V_61 = 1 ;
if ( F_21 ( V_2 , V_34 , V_47 ) & V_48 ) {
V_34 = ( V_34 + 1 ) & V_50 ;
break;
}
V_34 = ( V_34 + 1 ) & V_50 ;
}
if ( V_61 || V_4 -> V_28 [ V_34 ] == NULL )
F_17 ( V_2 ) ;
V_4 -> V_59 = V_34 ;
F_15 ( V_21 , V_58 ) ;
}
if ( V_54 & V_68 ) {
if ( V_6 > 1 )
F_3 ( L_12 , V_2 -> V_13 ) ;
V_4 -> V_29 . V_69 ++ ;
F_15 ( V_21 , V_68 ) ;
}
if ( V_54 & V_70 ) {
if ( V_6 > 1 )
F_3 ( L_13 , V_2 -> V_13 ) ;
V_4 -> V_29 . V_71 ++ ;
F_15 ( V_21 , V_70 ) ;
}
if ( V_54 & V_72 ) {
if ( V_6 > 1 )
F_3 ( L_14 , V_2 -> V_13 ) ;
V_4 -> V_29 . V_71 ++ ;
F_15 ( V_21 , V_72 ) ;
}
if ( V_54 & V_73 ) {
V_4 -> V_29 . V_74 += 65536 ;
F_15 ( V_21 , V_73 ) ;
}
if ( V_54 & V_75 ) {
V_4 -> V_29 . V_76 += 65536 ;
F_15 ( V_21 , V_75 ) ;
}
if ( V_54 & V_77 ) {
V_4 -> V_29 . V_78 += 65536 ;
F_15 ( V_21 , V_77 ) ;
}
if ( V_54 & V_79 ) {
if ( ( F_24 ( V_80 ) & V_81 ) && ( V_6 > 2 ) )
F_3 ( V_12 L_15 , V_2 -> V_13 ) ;
F_15 ( V_21 , V_79 ) ;
}
if ( V_54 & V_82 ) {
F_3 ( V_12 L_16 ,
V_2 -> V_13 ) ;
F_15 ( V_20 , 0 ) ;
F_15 ( V_21 , V_82 ) ;
}
if ( V_54 & V_83 )
F_15 ( V_21 , V_83 ) ;
} while( ( V_54 = F_24 ( V_21 ) & V_55 ) );
return V_84 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_54 ;
int V_34 = V_4 -> V_85 ;
while ( F_27 ( V_2 , V_34 , V_86 ) == 0 ) {
struct V_8 * V_87 ;
struct V_8 * V_88 ;
T_1 V_89 ;
T_3 V_90 ;
T_3 V_91 ;
int V_92 ;
V_54 = F_27 ( V_2 , V_34 , V_93 ) ;
if ( V_54 & V_94 ) {
V_88 = F_4 ( V_2 , V_10 + 2 ) ;
if ( V_88 == NULL ) {
V_4 -> V_29 . V_71 ++ ;
break;
}
if( F_6 ( V_4 -> V_15 ) == 2 )
F_7 ( V_88 , 2 ) ;
V_89 = F_8 ( V_4 -> V_17 , F_9 ( V_88 , V_10 ) ,
V_10 , V_18 ) ;
if ( ! V_89 ) {
F_5 ( V_88 ) ;
F_3 ( V_12 L_17 , V_2 -> V_13 ) ;
V_4 -> V_29 . V_71 ++ ;
break;
}
F_10 ( V_4 -> V_17 , V_4 -> V_19 [ V_34 ] , V_10 , V_18 ) ;
V_87 = V_4 -> V_11 [ V_34 ] ;
V_92 = F_27 ( V_2 , V_34 , V_95 ) ;
F_28 ( V_87 , V_92 ) ;
V_87 -> V_96 = F_29 ( V_87 , V_2 ) ;
F_30 ( V_87 ) ;
V_4 -> V_29 . V_97 ++ ;
V_4 -> V_29 . V_98 += V_92 ;
V_4 -> V_19 [ V_34 ] = V_89 ;
V_4 -> V_11 [ V_34 ] = V_88 ;
V_90 = ( unsigned long ) V_89 & 0xffff ;
V_91 = ( unsigned long ) V_89 >> 16 ;
F_31 ( V_2 , V_34 , V_99 , V_90 ) ;
F_31 ( V_2 , V_34 , V_100 , V_91 ) ;
} else {
V_4 -> V_29 . V_101 ++ ;
if ( V_54 & V_102 )
V_4 -> V_29 . V_74 ++ ;
if ( V_54 & V_103 )
V_4 -> V_29 . V_76 ++ ;
}
if ( V_54 & V_104 ) {
V_4 -> V_105 += V_106 * F_6 ( V_4 -> V_15 ) ;
if ( V_4 -> V_105 >= V_4 -> V_107 ) V_4 -> V_105 = V_4 -> V_108 & 0xffff ;
F_15 ( V_109 , V_4 -> V_105 ) ;
if ( F_24 ( V_21 ) & V_110 ) {
if ( V_6 > 2 )
F_3 ( L_18 , V_2 -> V_13 ) ;
F_15 ( V_21 , V_110 ) ;
}
} else
F_3 ( V_12 L_19 ,
V_2 -> V_13 ) ;
F_32 ( V_2 , V_34 , V_111 ,
F_27 ( V_2 , V_34 , V_111 ) | V_48 ) ;
F_32 ( V_2 , V_34 , V_86 , 1 ) ;
F_32 ( V_2 , V_4 -> V_112 , V_111 ,
F_27 ( V_2 , V_4 -> V_112 , V_111 ) & ~ V_48 ) ;
V_4 -> V_112 = V_34 ;
V_4 -> V_85 = V_34 = ( V_34 + 1 ) & V_113 ;
}
}
static struct V_114 * F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_29 . V_76 += F_24 ( V_115 ) ;
F_15 ( V_115 , 0xffff ) ;
V_4 -> V_29 . V_74 += F_24 ( V_116 ) ;
F_15 ( V_116 , 0xffff ) ;
V_4 -> V_29 . V_78 += F_24 ( V_117 ) ;
F_15 ( V_117 , 0xffff ) ;
return & V_4 -> V_29 ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_118 ;
struct V_119 * V_120 ;
unsigned char * V_121 ;
int V_5 ;
V_118 = F_24 ( V_122 ) & ~ ( V_123 | V_124 ) ;
V_118 |= V_125 ;
if ( V_2 -> V_126 & V_127 ) {
V_118 |= V_123 ;
} else {
if ( ( V_2 -> V_126 & V_128 ) ||
( F_35 ( V_2 ) > 15 ) ) {
V_118 |= V_124 ;
} else {
if ( V_6 > 2 )
F_3 ( L_20 ,
F_35 ( V_2 ) ) ;
F_36 ( V_2 , 1 ) ;
V_5 = 1 ;
F_37 (ha, dev) {
V_121 = V_120 -> V_121 ;
F_38 ( V_2 , V_5 , V_129 , V_121 [ 1 ] << 8 | V_121 [ 0 ] ) ;
F_38 ( V_2 , V_5 , V_130 , V_121 [ 3 ] << 8 | V_121 [ 2 ] ) ;
F_38 ( V_2 , V_5 , V_131 , V_121 [ 5 ] << 8 | V_121 [ 4 ] ) ;
F_36 ( V_2 , F_39 ( V_2 ) | ( 1 << V_5 ) ) ;
V_5 ++ ;
}
F_15 ( V_132 , 16 ) ;
F_15 ( V_133 , V_4 -> V_134 & 0xffff ) ;
F_15 ( V_22 , V_135 ) ;
}
}
if ( V_6 > 2 )
F_3 ( L_21 , V_118 ) ;
F_15 ( V_122 , V_118 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
unsigned int V_136 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
F_15 ( V_20 , 0 ) ;
F_15 ( V_21 , 0x7fff ) ;
F_15 ( V_22 , V_23 ) ;
F_15 ( V_22 , 0 ) ;
F_15 ( V_22 , V_137 ) ;
if ( V_6 > 2 )
F_3 ( L_22 ) ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
T_3 V_90 = ( unsigned long ) V_4 -> V_19 [ V_5 ] & 0xffff ;
T_3 V_91 = ( unsigned long ) V_4 -> V_19 [ V_5 ] >> 16 ;
F_31 ( V_2 , V_5 , V_99 , V_90 ) ;
F_31 ( V_2 , V_5 , V_100 , V_91 ) ;
F_31 ( V_2 , V_5 , V_138 , V_10 >> 1 ) ;
F_31 ( V_2 , V_5 , V_139 , 0 ) ;
}
V_4 -> V_107 = ( V_4 -> V_108 + V_7 * V_106 *
F_6 ( V_4 -> V_15 ) ) & 0xffff ;
V_4 -> V_105 = ( V_4 -> V_108 + ( V_7 - 1 ) * V_106 *
F_6 ( V_4 -> V_15 ) ) & 0xffff ;
F_15 ( V_140 , V_4 -> V_108 & 0xffff ) ;
F_15 ( V_141 , V_4 -> V_107 ) ;
F_15 ( V_142 , V_4 -> V_108 & 0xffff ) ;
F_15 ( V_109 , V_4 -> V_105 ) ;
F_15 ( V_143 , V_4 -> V_108 >> 16 ) ;
F_15 ( V_144 , ( V_10 >> 1 ) - ( V_4 -> V_15 ? 2 : 1 ) ) ;
if ( V_6 > 3 )
F_3 ( L_23 ) ;
F_15 ( V_22 , V_145 ) ;
V_5 = 0 ;
while ( V_5 ++ < 100 ) {
if ( F_24 ( V_22 ) & V_145 )
break;
}
if ( V_6 > 2 )
F_3 ( L_24 , F_24 ( V_22 ) , V_5 ) ;
if ( V_6 > 2 )
F_3 ( L_25 ) ;
for ( V_5 = 0 ; V_5 < V_146 ; V_5 ++ ) {
F_32 ( V_2 , V_5 , V_93 , 0 ) ;
F_32 ( V_2 , V_5 , V_95 , 0 ) ;
F_32 ( V_2 , V_5 , V_147 , 0 ) ;
F_32 ( V_2 , V_5 , V_148 , 0 ) ;
F_32 ( V_2 , V_5 , V_149 , 0 ) ;
F_32 ( V_2 , V_5 , V_86 , 1 ) ;
F_32 ( V_2 , V_5 , V_111 ,
V_4 -> V_150 +
( ( V_5 + 1 ) * V_151 * F_6 ( V_4 -> V_15 ) ) ) ;
}
F_32 ( V_2 , V_146 - 1 , V_111 ,
( V_4 -> V_150 & 0xffff ) | V_48 ) ;
V_4 -> V_112 = V_146 - 1 ;
V_4 -> V_85 = 0 ;
F_15 ( V_152 , V_4 -> V_150 >> 16 ) ;
F_15 ( V_153 , V_4 -> V_150 & 0xffff ) ;
if ( V_6 > 2 )
F_3 ( L_26 ) ;
for ( V_5 = 0 ; V_5 < V_24 ; V_5 ++ ) {
F_20 ( V_2 , V_5 , V_41 , 0 ) ;
F_20 ( V_2 , V_5 , V_154 , 0 ) ;
F_20 ( V_2 , V_5 , V_43 , 0 ) ;
F_20 ( V_2 , V_5 , V_42 , 0 ) ;
F_20 ( V_2 , V_5 , V_47 ,
( V_4 -> V_155 & 0xffff ) +
( V_5 + 1 ) * V_156 * F_6 ( V_4 -> V_15 ) ) ;
V_4 -> V_28 [ V_5 ] = NULL ;
}
F_20 ( V_2 , V_24 - 1 , V_47 ,
( V_4 -> V_155 & 0xffff ) ) ;
F_15 ( V_157 , V_4 -> V_155 >> 16 ) ;
F_15 ( V_158 , V_4 -> V_155 & 0xffff ) ;
V_4 -> V_59 = V_4 -> V_35 = 0 ;
V_4 -> V_49 = V_24 - 1 ;
F_38 ( V_2 , 0 , V_129 , V_2 -> V_159 [ 1 ] << 8 | V_2 -> V_159 [ 0 ] ) ;
F_38 ( V_2 , 0 , V_130 , V_2 -> V_159 [ 3 ] << 8 | V_2 -> V_159 [ 2 ] ) ;
F_38 ( V_2 , 0 , V_131 , V_2 -> V_159 [ 5 ] << 8 | V_2 -> V_159 [ 4 ] ) ;
F_36 ( V_2 , 1 ) ;
for ( V_5 = 0 ; V_5 < 16 ; V_5 ++ )
F_38 ( V_2 , V_5 , V_160 , V_5 ) ;
F_15 ( V_133 , V_4 -> V_134 & 0xffff ) ;
F_15 ( V_132 , 16 ) ;
F_15 ( V_22 , V_135 ) ;
V_5 = 0 ;
while ( V_5 ++ < 100 ) {
if ( F_24 ( V_21 ) & V_83 )
break;
}
if ( V_6 > 2 ) {
F_3 ( L_27 ,
F_24 ( V_22 ) , F_24 ( V_21 ) , V_5 ) ;
}
F_15 ( V_22 , V_161 | V_162 ) ;
F_15 ( V_122 , V_163 ) ;
F_15 ( V_80 , V_164 ) ;
F_15 ( V_21 , 0x7fff ) ;
F_15 ( V_20 , V_55 ) ;
V_136 = F_24 ( V_22 ) ;
if ( ( V_136 & V_161 ) == 0 || ( V_136 & V_162 ) == 0 )
F_3 ( V_12 L_28 , V_136 ) ;
if ( V_6 > 2 )
F_3 ( L_29 ,
F_24 ( V_22 ) ) ;
return 0 ;
}
