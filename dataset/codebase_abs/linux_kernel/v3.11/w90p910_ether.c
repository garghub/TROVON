static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_7 ;
V_7 = F_3 ( V_6 -> V_8 + V_9 ) ;
if ( V_3 == V_10 ) {
if ( V_4 == V_11 ) {
V_7 |= ( V_12 | V_13 ) ;
} else {
V_7 |= V_12 ;
V_7 &= ~ V_13 ;
}
} else {
if ( V_4 == V_11 ) {
V_7 |= V_13 ;
V_7 &= ~ V_12 ;
} else {
V_7 &= ~ ( V_13 | V_12 ) ;
}
}
F_4 ( V_7 , V_6 -> V_8 + V_9 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_14 * V_15 ;
unsigned int V_16 , V_17 , V_18 , V_3 , V_4 ;
V_15 = V_6 -> V_15 ;
if ( ! F_6 ( & V_6 -> V_19 ) ) {
V_6 -> V_20 = 0x0 ;
F_7 ( V_2 ) ;
F_8 ( & V_15 -> V_2 , L_1 , V_2 -> V_21 ) ;
return;
}
if ( V_6 -> V_20 == 1 )
return;
V_16 = F_9 ( V_2 , V_6 -> V_19 . V_22 , V_23 ) ;
V_17 = F_9 ( V_2 , V_6 -> V_19 . V_22 , V_24 ) ;
if ( V_17 & V_25 ) {
if ( ! ( V_16 & V_26 ) )
return;
V_18 = F_9 ( V_2 , V_6 -> V_19 . V_22 , V_27 ) ;
if ( ( V_18 & V_28 ) || ( V_18 & V_29 ) )
V_3 = V_10 ;
else
V_3 = V_30 ;
if ( ( V_18 & V_28 ) || ( V_18 & V_31 ) )
V_4 = V_11 ;
else
V_4 = V_32 ;
} else {
V_3 = ( V_17 & V_33 ) ? V_10 : V_30 ;
V_4 = ( V_17 & V_34 ) ? V_11 : V_32 ;
}
F_1 ( V_2 , V_3 , V_4 ) ;
F_10 ( & V_15 -> V_2 , L_2 , V_2 -> V_21 , V_3 ,
( V_4 == V_11 ) ? L_3 : L_4 ) ;
V_6 -> V_20 = 0x01 ;
F_11 ( V_2 ) ;
}
static void F_12 ( unsigned long V_35 )
{
struct V_1 * V_2 = (struct V_1 * ) V_35 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_5 ( V_2 ) ;
F_13 ( & V_6 -> V_36 , V_37 + F_14 ( 1000 ) ) ;
}
static void F_15 ( struct V_1 * V_2 ,
unsigned int V_38 , unsigned char * V_39 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_40 , V_41 ;
V_40 = ( V_39 [ 0 ] << 24 ) | ( V_39 [ 1 ] << 16 ) | ( V_39 [ 2 ] << 8 ) | V_39 [ 3 ] ;
V_41 = ( V_39 [ 4 ] << 24 ) | ( V_39 [ 5 ] << 16 ) ;
F_4 ( V_41 , V_6 -> V_8 + V_42 + V_38 * V_43 ) ;
F_4 ( V_40 , V_6 -> V_8 + V_44 + V_38 * V_43 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
struct V_14 * V_15 ;
unsigned int V_49 ;
V_6 = F_2 ( V_2 ) ;
V_15 = V_6 -> V_15 ;
V_6 -> V_46 = F_17 ( & V_15 -> V_2 , sizeof( struct V_50 ) ,
& V_6 -> V_51 , V_52 ) ;
if ( ! V_6 -> V_46 )
return - V_53 ;
V_6 -> V_48 = F_17 ( & V_15 -> V_2 , sizeof( struct V_54 ) ,
& V_6 -> V_55 , V_52 ) ;
if ( ! V_6 -> V_48 ) {
F_18 ( & V_15 -> V_2 , sizeof( struct V_50 ) ,
V_6 -> V_46 , V_6 -> V_51 ) ;
return - V_53 ;
}
for ( V_49 = 0 ; V_49 < V_56 ; V_49 ++ ) {
unsigned int V_57 ;
V_46 = & ( V_6 -> V_46 -> V_58 [ V_49 ] ) ;
if ( V_49 == V_56 - 1 )
V_57 = F_19 ( struct V_50 , V_58 [ 0 ] ) ;
else
V_57 = F_19 ( struct V_50 , V_58 [ V_49 + 1 ] ) ;
V_46 -> V_59 = V_6 -> V_51 + V_57 ;
V_46 -> V_60 = V_6 -> V_51 +
F_19 ( struct V_50 , V_61 [ V_49 ] ) ;
V_46 -> V_62 = 0 ;
V_46 -> V_63 = 0 ;
}
V_6 -> V_64 = V_6 -> V_51 ;
for ( V_49 = 0 ; V_49 < V_65 ; V_49 ++ ) {
unsigned int V_57 ;
V_48 = & ( V_6 -> V_48 -> V_58 [ V_49 ] ) ;
if ( V_49 == V_65 - 1 )
V_57 = F_19 ( struct V_54 , V_58 [ 0 ] ) ;
else
V_57 = F_19 ( struct V_54 , V_58 [ V_49 + 1 ] ) ;
V_48 -> V_59 = V_6 -> V_55 + V_57 ;
V_48 -> V_62 = V_66 ;
V_48 -> V_60 = V_6 -> V_55 +
F_19 ( struct V_54 , V_67 [ V_49 ] ) ;
}
V_6 -> V_68 = V_6 -> V_55 ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_7 ;
V_7 = V_69 | V_70 ;
F_4 ( V_7 , V_6 -> V_8 + V_71 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_7 ;
V_7 = F_3 ( V_6 -> V_8 + V_9 ) ;
V_7 |= V_72 ;
F_4 ( V_7 , V_6 -> V_8 + V_9 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_4 ( V_73 , V_6 -> V_8 + V_74 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_4 ( V_73 , V_6 -> V_8 + V_75 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_7 ;
V_7 = V_76 | V_77 | V_78 | V_79 ;
V_7 |= V_80 | V_81 | V_82 ;
F_4 ( V_7 , V_6 -> V_8 + V_83 ) ;
}
static void F_25 ( struct V_1 * V_2 ,
unsigned int * V_7 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
* V_7 = F_3 ( V_6 -> V_8 + V_84 ) ;
F_4 ( * V_7 , V_6 -> V_8 + V_84 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_7 ;
V_7 = F_3 ( V_6 -> V_8 + V_9 ) ;
V_7 |= V_85 | V_86 | V_87 | V_88 ;
F_4 ( V_7 , V_6 -> V_8 + V_9 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_7 ;
F_15 ( V_2 , V_89 , V_2 -> V_90 ) ;
V_7 = F_3 ( V_6 -> V_8 + V_91 ) ;
V_7 |= V_92 ;
F_4 ( V_7 , V_6 -> V_8 + V_91 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_7 ;
V_7 = V_93 | V_94 | V_95 ;
F_4 ( V_7 , V_6 -> V_8 + V_96 ) ;
}
static void F_29 ( struct V_1 * V_2 , unsigned int V_97 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_7 ;
V_7 = F_3 ( V_6 -> V_8 + V_9 ) ;
if ( V_97 )
V_7 |= V_98 ;
else
V_7 &= ~ V_98 ;
F_4 ( V_7 , V_6 -> V_8 + V_9 ) ;
}
static void F_30 ( struct V_1 * V_2 , unsigned int V_97 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_7 ;
V_7 = F_3 ( V_6 -> V_8 + V_9 ) ;
if ( V_97 )
V_7 |= V_99 ;
else
V_7 &= ~ V_99 ;
F_4 ( V_7 , V_6 -> V_8 + V_9 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_4 ( V_6 -> V_68 , V_6 -> V_8 + V_100 ) ;
F_4 ( V_6 -> V_64 , V_6 -> V_8 + V_101 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_29 ( V_2 , 0 ) ;
F_30 ( V_2 , 0 ) ;
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
if ( ! F_33 ( V_2 ) )
F_34 ( V_2 ) ;
F_16 ( V_2 ) ;
V_2 -> V_102 = V_37 ;
V_6 -> V_103 = 0x0 ;
V_6 -> V_104 = 0x0 ;
V_6 -> V_105 = 0x0 ;
F_31 ( V_2 ) ;
F_27 ( V_2 ) ;
F_28 ( V_2 ) ;
F_24 ( V_2 ) ;
F_29 ( V_2 , 1 ) ;
F_30 ( V_2 , 1 ) ;
F_23 ( V_2 ) ;
F_22 ( V_2 ) ;
V_2 -> V_102 = V_37 ;
if ( F_33 ( V_2 ) )
F_35 ( V_2 ) ;
}
static void F_36 ( struct V_1 * V_2 ,
int V_22 , int V_8 , int V_106 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_14 * V_15 ;
unsigned int V_7 , V_49 ;
V_15 = V_6 -> V_15 ;
F_4 ( V_106 , V_6 -> V_8 + V_107 ) ;
V_7 = ( V_22 << 0x08 ) | V_8 ;
V_7 |= V_108 | V_109 | V_110 ;
F_4 ( V_7 , V_6 -> V_8 + V_111 ) ;
for ( V_49 = 0 ; V_49 < V_112 ; V_49 ++ ) {
if ( ( F_3 ( V_6 -> V_8 + V_111 ) & V_108 ) == 0 )
break;
}
if ( V_49 == V_112 )
F_8 ( & V_15 -> V_2 , L_5 ) ;
}
static int F_9 ( struct V_1 * V_2 , int V_22 , int V_8 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_14 * V_15 ;
unsigned int V_7 , V_49 , V_106 ;
V_15 = V_6 -> V_15 ;
V_7 = ( V_22 << 0x08 ) | V_8 ;
V_7 |= V_108 | V_110 ;
F_4 ( V_7 , V_6 -> V_8 + V_111 ) ;
for ( V_49 = 0 ; V_49 < V_112 ; V_49 ++ ) {
if ( ( F_3 ( V_6 -> V_8 + V_111 ) & V_108 ) == 0 )
break;
}
if ( V_49 == V_112 ) {
F_8 ( & V_15 -> V_2 , L_6 ) ;
V_106 = 0xffff ;
} else {
V_106 = F_3 ( V_6 -> V_8 + V_107 ) ;
}
return V_106 ;
}
static int F_37 ( struct V_1 * V_2 , void * V_113 )
{
struct V_114 * V_115 = V_113 ;
if ( ! F_38 ( V_115 -> V_116 ) )
return - V_117 ;
memcpy ( V_2 -> V_90 , V_115 -> V_116 , V_2 -> V_118 ) ;
F_15 ( V_2 , V_89 , V_2 -> V_90 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_14 * V_15 ;
V_15 = V_6 -> V_15 ;
F_18 ( & V_15 -> V_2 , sizeof( struct V_54 ) ,
V_6 -> V_48 , V_6 -> V_55 ) ;
F_18 ( & V_15 -> V_2 , sizeof( struct V_50 ) ,
V_6 -> V_46 , V_6 -> V_51 ) ;
F_34 ( V_2 ) ;
F_40 ( & V_6 -> V_36 ) ;
F_41 ( V_6 -> V_119 ) ;
F_41 ( V_6 -> V_120 ) ;
F_42 ( V_6 -> V_121 , V_2 ) ;
F_42 ( V_6 -> V_122 , V_2 ) ;
return 0 ;
}
static struct V_123 * F_43 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 ) ;
return & V_6 -> V_124 ;
}
static int F_44 ( struct V_1 * V_2 ,
unsigned char * V_106 , int V_125 )
{
struct V_5 * V_6 ;
struct V_45 * V_126 ;
struct V_14 * V_15 ;
unsigned char * V_60 ;
V_6 = F_2 ( V_2 ) ;
V_15 = V_6 -> V_15 ;
V_126 = & V_6 -> V_46 -> V_58 [ V_6 -> V_103 ] ;
V_60 = V_6 -> V_46 -> V_61 [ V_6 -> V_103 ] ;
if ( V_125 > 1514 ) {
F_45 ( & V_15 -> V_2 , L_7 , V_125 ) ;
V_125 = 1514 ;
}
V_126 -> V_62 = V_125 & 0xFFFF ;
memcpy ( V_60 , V_106 , V_125 ) ;
V_126 -> V_63 = V_127 | V_128 | V_129 | V_130 ;
F_29 ( V_2 , 1 ) ;
F_23 ( V_2 ) ;
if ( ++ V_6 -> V_103 >= V_56 )
V_6 -> V_103 = 0 ;
V_126 = & V_6 -> V_46 -> V_58 [ V_6 -> V_103 ] ;
if ( V_126 -> V_63 & V_127 )
F_34 ( V_2 ) ;
return 0 ;
}
static int F_46 ( struct V_131 * V_132 , struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! ( F_44 ( V_2 , V_132 -> V_106 , V_132 -> V_133 ) ) ) {
V_6 -> V_132 = V_132 ;
F_47 ( V_132 ) ;
return 0 ;
}
return - V_134 ;
}
static T_1 F_48 ( int V_135 , void * V_35 )
{
struct V_5 * V_6 ;
struct V_45 * V_126 ;
struct V_14 * V_15 ;
struct V_1 * V_2 ;
unsigned int V_136 , V_137 , V_138 ;
V_2 = V_35 ;
V_6 = F_2 ( V_2 ) ;
V_15 = V_6 -> V_15 ;
F_25 ( V_2 , & V_138 ) ;
V_136 = F_3 ( V_6 -> V_8 + V_139 ) ;
V_137 = V_6 -> V_51 +
F_19 ( struct V_50 , V_58 [ V_6 -> V_104 ] ) ;
while ( V_137 != V_136 ) {
V_126 = & V_6 -> V_46 -> V_58 [ V_6 -> V_104 ] ;
if ( ++ V_6 -> V_104 >= V_56 )
V_6 -> V_104 = 0 ;
if ( V_126 -> V_62 & V_140 ) {
V_6 -> V_124 . V_141 ++ ;
V_6 -> V_124 . V_142 += V_126 -> V_62 & 0xFFFF ;
} else {
V_6 -> V_124 . V_143 ++ ;
}
V_126 -> V_62 = 0x0 ;
V_126 -> V_63 = 0x0 ;
if ( F_33 ( V_2 ) )
F_35 ( V_2 ) ;
V_137 = V_6 -> V_51 +
F_19 ( struct V_50 , V_58 [ V_6 -> V_104 ] ) ;
}
if ( V_138 & V_144 ) {
F_45 ( & V_15 -> V_2 , L_8 ) ;
} else if ( V_138 & V_145 ) {
F_45 ( & V_15 -> V_2 , L_9 ) ;
F_32 ( V_2 ) ;
} else if ( V_138 & V_146 ) {
if ( F_33 ( V_2 ) )
F_35 ( V_2 ) ;
}
return V_147 ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_47 * V_148 ;
struct V_14 * V_15 ;
struct V_131 * V_132 ;
unsigned char * V_106 ;
unsigned int V_125 , V_138 , V_7 , V_137 ;
V_6 = F_2 ( V_2 ) ;
V_15 = V_6 -> V_15 ;
V_148 = & V_6 -> V_48 -> V_58 [ V_6 -> V_105 ] ;
do {
V_7 = F_3 ( V_6 -> V_8 + V_149 ) ;
V_137 = V_6 -> V_55 +
F_19 ( struct V_54 , V_58 [ V_6 -> V_105 ] ) ;
if ( V_7 == V_137 )
break;
V_138 = V_148 -> V_62 ;
V_125 = V_138 & 0xFFFF ;
if ( V_138 & V_150 ) {
V_106 = V_6 -> V_48 -> V_67 [ V_6 -> V_105 ] ;
V_132 = F_50 ( V_2 , V_125 + 2 ) ;
if ( ! V_132 ) {
V_6 -> V_124 . V_151 ++ ;
return;
}
F_51 ( V_132 , 2 ) ;
F_52 ( V_132 , V_125 ) ;
F_53 ( V_132 , V_106 , V_125 ) ;
V_132 -> V_152 = F_54 ( V_132 , V_2 ) ;
V_6 -> V_124 . V_153 ++ ;
V_6 -> V_124 . V_154 += V_125 ;
F_55 ( V_132 ) ;
} else {
V_6 -> V_124 . V_155 ++ ;
if ( V_138 & V_156 ) {
F_45 ( & V_15 -> V_2 , L_10 ) ;
V_6 -> V_124 . V_157 ++ ;
} else if ( V_138 & V_158 ) {
F_45 ( & V_15 -> V_2 , L_11 ) ;
V_6 -> V_124 . V_159 ++ ;
} else if ( V_138 & V_160 ) {
F_45 ( & V_15 -> V_2 , L_12 ) ;
V_6 -> V_124 . V_161 ++ ;
} else if ( V_138 & V_162 ) {
F_45 ( & V_15 -> V_2 , L_13 ) ;
V_6 -> V_124 . V_163 ++ ;
}
}
V_148 -> V_62 = V_66 ;
V_148 -> V_164 = 0x0 ;
if ( ++ V_6 -> V_105 >= V_65 )
V_6 -> V_105 = 0 ;
V_148 = & V_6 -> V_48 -> V_58 [ V_6 -> V_105 ] ;
} while ( 1 );
}
static T_1 F_56 ( int V_135 , void * V_35 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
struct V_14 * V_15 ;
unsigned int V_138 ;
V_2 = V_35 ;
V_6 = F_2 ( V_2 ) ;
V_15 = V_6 -> V_15 ;
F_25 ( V_2 , & V_138 ) ;
if ( V_138 & V_165 ) {
F_49 ( V_2 ) ;
F_22 ( V_2 ) ;
return V_147 ;
} else if ( V_138 & V_166 ) {
F_45 ( & V_15 -> V_2 , L_14 ) ;
F_32 ( V_2 ) ;
}
F_49 ( V_2 ) ;
return V_147 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_14 * V_15 ;
V_6 = F_2 ( V_2 ) ;
V_15 = V_6 -> V_15 ;
F_32 ( V_2 ) ;
F_20 ( V_2 ) ;
F_31 ( V_2 ) ;
F_27 ( V_2 ) ;
F_28 ( V_2 ) ;
F_24 ( V_2 ) ;
F_26 ( V_2 ) ;
F_30 ( V_2 , 1 ) ;
F_58 ( V_6 -> V_119 ) ;
F_58 ( V_6 -> V_120 ) ;
V_6 -> V_153 = 0x0 ;
V_6 -> V_154 = 0x0 ;
if ( F_59 ( V_6 -> V_121 , F_48 ,
0x0 , V_15 -> V_21 , V_2 ) ) {
F_45 ( & V_15 -> V_2 , L_15 ) ;
return - V_134 ;
}
if ( F_59 ( V_6 -> V_122 , F_56 ,
0x0 , V_15 -> V_21 , V_2 ) ) {
F_45 ( & V_15 -> V_2 , L_16 ) ;
F_42 ( V_6 -> V_121 , V_2 ) ;
return - V_134 ;
}
F_13 ( & V_6 -> V_36 , V_37 + F_14 ( 1000 ) ) ;
F_60 ( V_2 ) ;
F_22 ( V_2 ) ;
F_10 ( & V_15 -> V_2 , L_17 , V_2 -> V_21 ) ;
return 0 ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
unsigned int V_167 ;
V_6 = F_2 ( V_2 ) ;
if ( V_2 -> V_168 & V_169 )
V_167 = V_170 | V_95 | V_94 | V_93 ;
else if ( ( V_2 -> V_168 & V_171 ) || ! F_62 ( V_2 ) )
V_167 = V_95 | V_94 | V_93 ;
else
V_167 = V_93 | V_94 ;
F_4 ( V_167 , V_6 -> V_8 + V_96 ) ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_172 * V_173 , int V_174 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_175 * V_106 = F_64 ( V_173 ) ;
return F_65 ( & V_6 -> V_19 , V_106 , V_174 , NULL ) ;
}
static void F_66 ( struct V_1 * V_2 ,
struct V_176 * V_177 )
{
F_67 ( V_177 -> V_178 , V_179 , sizeof( V_177 -> V_178 ) ) ;
F_67 ( V_177 -> V_180 , V_181 , sizeof( V_177 -> V_180 ) ) ;
}
static int F_68 ( struct V_1 * V_2 , struct V_182 * V_174 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_69 ( & V_6 -> V_19 , V_174 ) ;
}
static int F_70 ( struct V_1 * V_2 , struct V_182 * V_174 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_71 ( & V_6 -> V_19 , V_174 ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_73 ( & V_6 -> V_19 ) ;
}
static T_2 F_74 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_6 ( & V_6 -> V_19 ) ;
}
static void T_3 F_75 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_14 * V_15 ;
char V_113 [ 6 ] ;
V_15 = V_6 -> V_15 ;
V_113 [ 0 ] = 0x00 ;
V_113 [ 1 ] = 0x02 ;
V_113 [ 2 ] = 0xac ;
V_113 [ 3 ] = 0x55 ;
V_113 [ 4 ] = 0x88 ;
V_113 [ 5 ] = 0xa8 ;
if ( F_38 ( V_113 ) )
memcpy ( V_2 -> V_90 , & V_113 , 0x06 ) ;
else
F_45 ( & V_15 -> V_2 , L_18 ) ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_77 ( V_2 ) ;
V_2 -> V_183 = & V_184 ;
V_2 -> V_185 = & V_186 ;
V_2 -> V_187 = 16 ;
V_2 -> V_188 = 0x0 ;
V_2 -> V_189 = V_190 ;
F_75 ( V_2 ) ;
V_6 -> V_103 = 0x0 ;
V_6 -> V_105 = 0x0 ;
V_6 -> V_104 = 0x0 ;
V_6 -> V_20 = 0x0 ;
V_6 -> V_19 . V_22 = 0x01 ;
V_6 -> V_19 . V_191 = 0x1f ;
V_6 -> V_19 . V_192 = 0x1f ;
V_6 -> V_19 . V_2 = V_2 ;
V_6 -> V_19 . V_193 = F_9 ;
V_6 -> V_19 . V_194 = F_36 ;
F_78 ( & V_6 -> V_36 , F_12 ,
( unsigned long ) V_2 ) ;
return 0 ;
}
static int F_79 ( struct V_14 * V_15 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
int error ;
V_2 = F_80 ( sizeof( struct V_5 ) ) ;
if ( ! V_2 )
return - V_53 ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_195 = F_81 ( V_15 , V_196 , 0 ) ;
if ( V_6 -> V_195 == NULL ) {
F_45 ( & V_15 -> V_2 , L_19 ) ;
error = - V_197 ;
goto V_198;
}
if ( ! F_82 ( V_6 -> V_195 -> V_199 ,
F_83 ( V_6 -> V_195 ) , V_15 -> V_21 ) ) {
F_45 ( & V_15 -> V_2 , L_20 ) ;
error = - V_200 ;
goto V_198;
}
V_6 -> V_8 = F_84 ( V_6 -> V_195 -> V_199 , F_83 ( V_6 -> V_195 ) ) ;
if ( V_6 -> V_8 == NULL ) {
F_45 ( & V_15 -> V_2 , L_21 ) ;
error = - V_197 ;
goto V_201;
}
V_6 -> V_121 = F_85 ( V_15 , 0 ) ;
if ( V_6 -> V_121 < 0 ) {
F_45 ( & V_15 -> V_2 , L_22 ) ;
error = - V_197 ;
goto V_202;
}
V_6 -> V_122 = F_85 ( V_15 , 1 ) ;
if ( V_6 -> V_122 < 0 ) {
F_45 ( & V_15 -> V_2 , L_23 ) ;
error = - V_197 ;
goto V_203;
}
F_86 ( V_15 , V_2 ) ;
V_6 -> V_120 = F_87 ( & V_15 -> V_2 , NULL ) ;
if ( F_88 ( V_6 -> V_120 ) ) {
F_45 ( & V_15 -> V_2 , L_24 ) ;
error = F_89 ( V_6 -> V_120 ) ;
goto V_204;
}
V_6 -> V_119 = F_87 ( & V_15 -> V_2 , L_25 ) ;
if ( F_88 ( V_6 -> V_119 ) ) {
F_45 ( & V_15 -> V_2 , L_24 ) ;
error = F_89 ( V_6 -> V_119 ) ;
goto V_205;
}
V_6 -> V_15 = V_15 ;
F_76 ( V_2 ) ;
error = F_90 ( V_2 ) ;
if ( error != 0 ) {
F_45 ( & V_15 -> V_2 , L_26 ) ;
error = - V_206 ;
goto V_207;
}
return 0 ;
V_207:
F_91 ( V_6 -> V_119 ) ;
V_205:
F_91 ( V_6 -> V_120 ) ;
V_204:
F_42 ( V_6 -> V_122 , V_15 ) ;
V_203:
F_42 ( V_6 -> V_121 , V_15 ) ;
V_202:
F_92 ( V_6 -> V_8 ) ;
V_201:
F_93 ( V_6 -> V_195 -> V_199 , F_83 ( V_6 -> V_195 ) ) ;
V_198:
F_94 ( V_2 ) ;
return error ;
}
static int F_95 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_96 ( V_15 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_97 ( V_2 ) ;
F_91 ( V_6 -> V_119 ) ;
F_91 ( V_6 -> V_120 ) ;
F_92 ( V_6 -> V_8 ) ;
F_93 ( V_6 -> V_195 -> V_199 , F_83 ( V_6 -> V_195 ) ) ;
F_42 ( V_6 -> V_121 , V_2 ) ;
F_42 ( V_6 -> V_122 , V_2 ) ;
F_40 ( & V_6 -> V_36 ) ;
F_94 ( V_2 ) ;
return 0 ;
}
