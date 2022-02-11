static void F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
void T_2 * V_3 = V_1 -> V_4 ;
V_1 -> V_5 += V_2 ;
if ( V_1 -> V_5 >= V_1 -> V_6 )
V_1 -> V_5 -= V_1 -> V_6 ;
if ( V_1 -> V_5 < 8 )
V_1 -> V_5 = 8 ;
F_2 ( V_1 -> V_5 & 0xffff , V_3 + V_7 + 2 ) ;
}
static void F_3 ( struct V_1 * V_1 )
{
if ( V_1 -> V_8 & V_9 ) {
F_1 ( V_1 , V_1 -> V_10 ) ;
} else if ( V_1 -> V_8 & V_11 ) {
int V_12 ;
if ( V_1 -> V_13 > V_1 -> V_10 ) {
V_1 -> V_13 -= V_1 -> V_10 ;
if ( V_1 -> V_13 < V_1 -> V_10 )
F_1 ( V_1 , V_1 -> V_13 ) ;
else
F_1 ( V_1 , V_1 -> V_10 ) ;
return;
}
V_12 = V_1 -> V_14 ;
V_12 -= F_4 ( V_1 -> V_15 + V_16 ) ;
if ( V_12 > ( V_1 -> V_17 / 2 ) )
V_12 -= V_1 -> V_17 ;
if ( V_12 > 0 ) {
if ( V_12 < 16 )
V_12 = 16 ;
F_1 ( V_1 , V_12 ) ;
return;
}
if ( V_12 > - 9 )
V_1 -> V_13 = V_1 -> V_18 + 1 ;
else
V_1 -> V_13 = V_1 -> V_18 + V_12 + 10 ;
if ( V_1 -> V_13 < V_1 -> V_6 ) {
F_1 ( V_1 , V_1 -> V_13 ) ;
V_1 -> V_13 = 0 ;
} else
F_1 ( V_1 , V_1 -> V_10 ) ;
V_12 = V_1 -> V_14 + V_1 -> V_18 ;
if ( V_12 >= V_1 -> V_17 )
V_12 -= V_1 -> V_17 ;
V_1 -> V_14 = V_12 ;
}
F_5 ( V_1 -> V_19 ) ;
}
static void F_6 ( T_3 V_20 , struct V_1 * V_1 )
{
int V_21 ;
while ( V_20 ) {
V_21 = F_7 ( V_20 ) ;
V_20 >>= V_21 + 1 ;
V_1 += V_21 ;
F_3 ( V_1 ) ;
V_1 ++ ;
}
}
static T_4 F_8 ( int V_22 , void * V_23 )
{
struct V_24 * V_25 = V_23 ;
unsigned long V_26 = V_25 -> V_27 ;
struct V_1 * V_1 ;
T_3 V_28 , V_20 ;
V_28 = F_9 ( V_26 + V_29 ) ;
V_28 &= V_30 |
V_31 ;
if ( ! V_28 )
return V_32 ;
do {
V_20 = F_9 ( V_26 + V_33 ) ;
if ( V_20 ) {
F_6 ( V_20 , V_25 -> V_34 ) ;
F_10 ( V_20 , V_26 + V_33 ) ;
}
V_20 = F_9 ( V_26 + V_35 ) ;
if ( V_20 ) {
F_6 ( V_20 , & V_25 -> V_34 [ 32 ] ) ;
F_10 ( V_20 , V_26 + V_35 ) ;
}
V_20 = F_9 ( V_26 + V_36 ) ;
if ( V_20 ) {
V_1 = & V_25 -> V_37 ;
if ( ! V_1 -> V_38 )
F_5 ( V_1 -> V_19 ) ;
F_10 ( V_20 , V_26 + V_36 ) ;
}
F_10 ( V_28 , V_26 + V_29 ) ;
V_28 = F_9 ( V_26 + V_29 ) ;
V_28 &= V_30 |
V_31 ;
} while ( V_28 );
return V_39 ;
}
static T_3 F_11 ( unsigned int V_40 )
{
T_3 V_41 ;
if ( V_40 == 44100 )
V_41 = 0xeb3 ;
else if ( V_40 == 8000 )
V_41 = 0x2ab ;
else if ( V_40 == 48000 )
V_41 = 0x1000 ;
else
V_41 = ( ( ( V_40 << 12 ) + 24000 ) / 48000 ) & 0x0000ffff ;
return V_41 ;
}
static void F_12 ( struct V_24 * V_25 )
{
if ( ! V_25 -> V_42 )
V_25 -> V_43 = F_13 ( V_25 -> V_44 ,
V_25 -> V_45 [ 0 ] ,
4096 , V_46 ) ;
V_25 -> V_42 ++ ;
}
static void F_14 ( struct V_24 * V_25 )
{
V_25 -> V_42 -- ;
if ( ! V_25 -> V_42 )
F_15 ( V_25 -> V_44 , V_25 -> V_43 , 4096 ,
V_46 ) ;
}
static void F_16 ( struct V_24 * V_25 , struct V_1 * V_1 )
{
unsigned long V_8 ;
F_17 ( & V_25 -> V_47 , V_8 ) ;
if ( V_1 -> V_38 ) {
F_14 ( V_25 ) ;
V_1 -> V_38 -> V_8 &= ~ ( V_48 | V_9 |
V_11 ) ;
V_1 -> V_38 = NULL ;
}
V_1 -> V_8 &= ~ ( V_48 | V_9 | V_11 ) ;
F_18 ( & V_25 -> V_47 , V_8 ) ;
}
static struct V_1 * F_19 ( struct V_24 * V_25 )
{
struct V_1 * V_1 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ ) {
V_1 = & V_25 -> V_34 [ V_49 ] ;
if ( V_1 -> V_8 & V_48 )
continue;
V_1 -> V_8 |= V_48 ;
goto V_50;
}
V_1 = NULL ;
V_50:
return V_1 ;
}
static struct V_1 * F_20 ( struct V_24 * V_25 )
{
struct V_1 * V_1 ;
unsigned long V_8 ;
F_17 ( & V_25 -> V_47 , V_8 ) ;
V_1 = F_19 ( V_25 ) ;
F_18 ( & V_25 -> V_47 , V_8 ) ;
return V_1 ;
}
static int F_21 ( struct V_51 * V_19 ,
struct V_52 * V_53 )
{
struct V_24 * V_25 = F_22 ( V_19 ) ;
struct V_54 * V_55 = V_19 -> V_55 ;
struct V_1 * V_1 = V_55 -> V_56 ;
unsigned int V_10 , V_6 ;
unsigned long V_8 ;
int V_57 ;
V_10 = F_23 ( V_53 ) ;
V_6 = F_24 ( V_53 ) ;
V_57 = ( V_10 != V_6 &&
V_10 != ( V_6 / 2 ) ) ;
if ( V_57 && ! V_1 -> V_38 ) {
F_17 ( & V_25 -> V_47 , V_8 ) ;
V_1 -> V_38 = F_19 ( V_25 ) ;
if ( V_1 -> V_38 )
F_12 ( V_25 ) ;
F_18 ( & V_25 -> V_47 , V_8 ) ;
if ( ! V_1 -> V_38 )
return - V_58 ;
V_1 -> V_38 -> V_19 = V_19 ;
} else if ( ! V_57 && V_1 -> V_38 ) {
F_16 ( V_25 , V_1 ) ;
V_1 -> V_38 = NULL ;
}
return 0 ;
}
static int F_25 ( struct V_51 * V_19 )
{
struct V_24 * V_25 = F_22 ( V_19 ) ;
struct V_54 * V_55 = V_19 -> V_55 ;
struct V_1 * V_1 ;
V_1 = F_20 ( V_25 ) ;
if ( ! V_1 )
return - V_59 ;
V_1 -> V_19 = V_19 ;
V_55 -> V_56 = V_1 ;
V_55 -> V_60 = V_61 ;
F_26 ( V_55 , V_62 ,
9 , 0xfff9 ) ;
F_26 ( V_55 , V_63 ,
9 , 0xfff9 ) ;
F_27 ( V_19 ) ;
return 0 ;
}
static int F_28 ( struct V_51 * V_19 )
{
struct V_24 * V_25 = F_22 ( V_19 ) ;
struct V_54 * V_55 = V_19 -> V_55 ;
struct V_1 * V_1 = V_55 -> V_56 ;
F_16 ( V_25 , V_1 ) ;
return 0 ;
}
static int F_29 ( struct V_51 * V_19 ,
struct V_52 * V_53 )
{
return F_30 ( V_19 ,
F_31 ( V_53 ) ) ;
}
static int F_32 ( struct V_51 * V_19 )
{
return F_33 ( V_19 ) ;
}
static int F_34 ( struct V_51 * V_19 )
{
struct V_54 * V_55 = V_19 -> V_55 ;
struct V_1 * V_1 = V_55 -> V_56 ;
void T_2 * V_4 = V_1 -> V_4 ;
void T_2 * V_64 = V_1 -> V_64 ;
T_3 V_65 , V_66 , V_67 , V_68 , V_41 , V_69 ;
T_1 V_70 ;
V_65 = 0 ;
if ( F_35 ( V_55 -> V_65 ) == 8 )
V_65 |= V_71 ;
if ( ! F_36 ( V_55 -> V_65 ) )
V_65 |= V_72 ;
if ( V_55 -> V_73 == 1 )
V_65 |= V_74 ;
V_66 = V_55 -> V_66 ;
V_70 = V_55 -> V_6 - 1 ;
V_67 = V_70 | V_75 | V_76 ;
V_68 = V_70 ;
if ( V_55 -> V_10 == ( V_55 -> V_6 / 2 ) ) {
V_67 |= V_77 ;
} else if ( V_55 -> V_10 != V_55 -> V_6 ) {
V_1 -> V_8 |= V_9 ;
V_1 -> V_5 = V_55 -> V_10 - 1 ;
V_1 -> V_10 = V_55 -> V_10 ;
V_1 -> V_6 = V_55 -> V_6 ;
V_67 &= ~ V_76 ;
V_67 |= V_78 ;
V_68 |= ( V_55 -> V_10 - 1 ) << 16 ;
}
V_41 = F_11 ( V_55 -> V_40 ) ;
F_37 ( V_65 , V_4 + V_79 ) ;
F_37 ( V_66 , V_4 + V_80 ) ;
F_37 ( V_67 , V_4 + V_81 ) ;
F_37 ( V_68 , V_4 + V_7 ) ;
for ( V_69 = 0 ; V_69 < V_82 ; V_69 += 4 )
F_37 ( 0 , V_64 + V_69 ) ;
F_37 ( V_83 , V_64 + V_84 ) ;
F_37 ( V_41 << 16 , V_64 + V_85 ) ;
F_37 ( V_86 |
V_87 |
V_88 ,
V_64 + V_89 ) ;
F_38 ( V_4 ) ;
return 0 ;
}
static int F_39 ( struct V_51 * V_19 , int V_90 )
{
struct V_24 * V_25 = F_22 ( V_19 ) ;
unsigned long V_26 = V_25 -> V_27 ;
struct V_51 * V_91 ;
struct V_1 * V_1 ;
void * V_92 ;
int V_93 ;
T_3 V_94 = 0 ;
T_3 V_95 [ 2 ] = { 0 , 0 } ;
switch ( V_90 ) {
case V_96 :
case V_97 :
case V_98 :
V_93 = 1 ;
break;
case V_99 :
case V_100 :
case V_101 :
V_93 = 0 ;
break;
default:
return - V_102 ;
}
F_40 (s, substream) {
V_92 = F_22 ( V_91 ) ;
if ( V_92 != V_25 )
continue;
V_1 = V_91 -> V_55 -> V_56 ;
if ( V_1 -> V_8 & V_103 ) {
V_94 |= 1 << V_1 -> V_104 ;
V_1 = V_1 -> V_38 ;
}
if ( V_1 )
V_95 [ V_1 -> V_104 / 32 ] |= 1 << ( V_1 -> V_104 & 0x1f ) ;
F_41 ( V_91 , V_19 ) ;
}
if ( V_93 ) {
if ( V_94 )
F_10 ( V_94 , V_26 + V_105 ) ;
if ( V_95 [ 0 ] )
F_10 ( V_95 [ 0 ] , V_26 + V_106 ) ;
if ( V_95 [ 1 ] )
F_10 ( V_95 [ 1 ] , V_26 + V_107 ) ;
} else {
if ( V_94 )
F_10 ( V_94 , V_26 + V_108 ) ;
if ( V_95 [ 0 ] )
F_10 ( V_95 [ 0 ] , V_26 + V_109 ) ;
if ( V_95 [ 1 ] )
F_10 ( V_95 [ 1 ] , V_26 + V_110 ) ;
}
return 0 ;
}
static T_5 F_42 ( struct V_51 * V_19 )
{
struct V_54 * V_55 = V_19 -> V_55 ;
struct V_1 * V_1 = V_55 -> V_56 ;
T_3 V_111 ;
V_111 = F_38 ( V_1 -> V_4 + V_79 ) ;
V_111 &= 0xffff ;
return V_111 ;
}
static int F_43 ( struct V_51 * V_19 )
{
struct V_24 * V_25 = F_22 ( V_19 ) ;
struct V_54 * V_55 = V_19 -> V_55 ;
struct V_1 * V_1 = & V_25 -> V_37 ;
unsigned long V_8 ;
F_17 ( & V_25 -> V_47 , V_8 ) ;
if ( V_1 -> V_8 & V_48 )
V_1 = NULL ;
else
V_1 -> V_8 |= V_48 ;
F_18 ( & V_25 -> V_47 , V_8 ) ;
if ( ! V_1 )
return - V_59 ;
V_1 -> V_19 = V_19 ;
V_55 -> V_56 = V_1 ;
V_55 -> V_60 = V_112 ;
V_55 -> V_60 . V_113 = V_25 -> V_114 [ 0 ] -> V_113 [ V_115 ] ;
F_44 ( V_55 ) ;
F_26 ( V_55 , V_62 ,
9 , 0xfff9 ) ;
F_26 ( V_55 , V_63 ,
9 , 0xfff9 ) ;
F_27 ( V_19 ) ;
return 0 ;
}
static int F_45 ( struct V_51 * V_19 ,
struct V_52 * V_53 )
{
struct V_24 * V_25 = F_22 ( V_19 ) ;
int V_116 ;
V_116 = F_46 ( V_25 -> V_114 [ 0 ] , V_117 ,
F_47 ( V_53 ) ) ;
if ( V_116 )
goto V_118;
V_116 = F_30 ( V_19 ,
F_31 ( V_53 ) ) ;
if ( V_116 < 0 )
goto V_118;
V_116 = F_21 ( V_19 , V_53 ) ;
V_118:
return V_116 ;
}
static void F_48 ( struct V_1 * V_1 ,
struct V_51 * V_19 )
{
struct V_24 * V_25 = F_22 ( V_19 ) ;
struct V_54 * V_55 = V_19 -> V_55 ;
struct V_1 * V_38 = V_1 -> V_38 ;
void T_2 * V_119 = V_38 -> V_4 ;
void T_2 * V_64 = V_38 -> V_64 ;
T_1 V_6 , V_10 ;
T_3 V_65 , V_67 , V_68 , V_41 ;
T_3 V_13 , V_5 , V_69 ;
V_6 = 4096 / V_55 -> V_73 ;
V_6 /= F_49 ( V_55 -> V_65 , 1 ) ;
V_10 = V_6 ;
V_13 = V_55 -> V_10 + 12 ;
if ( V_13 > V_10 ) {
T_1 V_120 = V_13 % V_10 ;
T_1 V_121 = V_10 / 4 ;
if ( V_120 && V_120 < V_121 ) {
T_1 V_122 = V_13 / V_10 ;
V_120 = V_121 - V_120 ;
V_120 += V_122 - 1 ;
V_120 /= V_122 ;
V_10 -= V_120 ;
}
V_5 = V_10 - 1 ;
} else {
V_10 = V_55 -> V_10 ;
V_5 = V_13 - 1 ;
V_13 = 0 ;
}
V_38 -> V_8 |= V_11 ;
V_38 -> V_15 = V_1 -> V_4 ;
V_38 -> V_14 = V_55 -> V_10 ;
V_38 -> V_18 = V_55 -> V_10 ;
V_38 -> V_17 = V_55 -> V_6 ;
V_38 -> V_10 = V_10 ;
V_38 -> V_6 = V_6 ;
V_38 -> V_5 = V_5 ;
V_38 -> V_13 = V_13 ;
V_65 = 0 ;
if ( F_35 ( V_55 -> V_65 ) == 8 )
V_65 = V_123 ;
if ( V_55 -> V_73 == 1 )
V_65 |= V_124 ;
V_67 = V_38 -> V_6 - 1 ;
V_67 |= V_75 | V_78 ;
V_68 = V_38 -> V_6 - 1 ;
V_68 |= V_38 -> V_5 << 16 ;
V_41 = F_11 ( V_55 -> V_40 ) ;
F_37 ( V_65 , V_119 + V_79 ) ;
F_37 ( V_25 -> V_43 , V_119 + V_80 ) ;
F_37 ( V_67 , V_119 + V_81 ) ;
F_37 ( V_68 , V_119 + V_7 ) ;
for ( V_69 = 0 ; V_69 < V_82 ; V_69 += 4 )
F_37 ( 0 , V_64 + V_69 ) ;
F_37 ( V_83 , V_64 + V_84 ) ;
F_37 ( V_41 << 16 , V_64 + V_85 ) ;
F_37 ( V_86 |
V_87 |
V_88 ,
V_64 + V_89 ) ;
}
static int F_50 ( struct V_51 * V_19 )
{
struct V_54 * V_55 = V_19 -> V_55 ;
struct V_1 * V_1 = V_55 -> V_56 ;
void T_2 * V_125 = V_1 -> V_4 ;
T_3 V_65 , V_66 , V_67 ;
T_1 V_70 ;
V_65 = 0 ;
if ( F_35 ( V_55 -> V_65 ) == 8 )
V_65 = V_123 ;
if ( ! F_36 ( V_55 -> V_65 ) )
V_65 |= V_126 ;
if ( V_55 -> V_73 == 1 )
V_65 |= V_124 ;
V_66 = V_55 -> V_66 ;
V_70 = V_55 -> V_6 - 1 ;
V_67 = V_70 | V_127 ;
if ( V_1 -> V_38 ) {
F_48 ( V_1 , V_19 ) ;
} else {
V_67 |= V_128 ;
if ( V_55 -> V_10 != V_55 -> V_6 )
V_67 |= V_129 ;
}
F_37 ( V_65 , V_125 + V_16 ) ;
F_37 ( V_66 , V_125 + V_130 ) ;
F_37 ( V_67 , V_125 + V_131 ) ;
F_38 ( V_125 ) ;
return 0 ;
}
static int T_6 F_51 ( struct V_24 * V_25 )
{
struct V_132 * V_133 ;
int V_116 ;
V_116 = F_52 ( V_25 -> V_134 , L_1 , 0 , 64 , 1 , & V_133 ) ;
if ( V_116 )
return V_116 ;
V_133 -> V_56 = V_25 ;
strcpy ( V_133 -> V_135 , L_1 ) ;
V_25 -> V_133 = V_133 ;
F_53 ( V_133 , V_136 , & V_137 ) ;
F_53 ( V_133 , V_138 , & V_139 ) ;
F_54 ( V_133 , V_140 ,
F_55 ( V_25 -> V_44 ) , 64 * 1024 , 128 * 1024 ) ;
return 0 ;
}
static unsigned short F_56 ( struct V_24 * V_25 , int V_141 , T_3 V_90 )
{
unsigned long V_26 = V_25 -> V_27 ;
unsigned short V_142 = 0xffff ;
T_1 V_20 ;
T_1 V_143 ;
int V_144 ;
static const T_1 V_145 [ 3 ] = {
V_146 ,
V_147 ,
V_148 ,
} ;
V_143 = V_145 [ V_141 ] ;
F_57 ( & V_25 -> V_149 ) ;
V_144 = 0xffff ;
while ( ( F_58 ( V_26 + V_150 ) & V_151 ) && -- V_144 )
F_59 ( 1 ) ;
if ( ! V_144 )
goto V_152;
V_144 = 0xffff ;
do {
V_20 = F_58 ( V_26 + V_153 ) ;
if ( ( V_20 & V_143 ) && ! ( V_20 & V_154 ) )
break;
F_59 ( 1 ) ;
} while ( -- V_144 );
if ( ! V_144 )
goto V_155;
F_10 ( V_90 , V_26 + V_156 ) ;
F_59 ( 10 ) ;
V_144 = 0xffff ;
while ( ( F_58 ( V_26 + V_153 ) & V_154 ) && -- V_144 )
F_59 ( 1 ) ;
V_142 = F_9 ( V_26 + V_156 ) >> 16 ;
V_155:
F_10 ( V_157 , V_26 + V_150 ) ;
V_152:
F_60 ( & V_25 -> V_149 ) ;
if ( ! V_144 ) {
F_61 ( & V_25 -> V_44 -> V_23 , L_2 ,
V_141 , V_90 ) ;
}
return V_142 ;
}
static void F_62 ( struct V_158 * V_114 , unsigned short V_69 ,
unsigned short V_142 )
{
static const T_3 V_90 [ 3 ] = {
V_159 ,
V_160 ,
V_161 ,
} ;
F_56 ( V_114 -> V_56 , V_114 -> V_104 ,
( V_142 << 16 ) | ( V_69 << 8 ) | V_90 [ V_114 -> V_104 ] ) ;
}
static unsigned short F_63 ( struct V_158 * V_114 , unsigned short V_69 )
{
static const T_3 V_90 [ 3 ] = {
V_162 ,
V_163 ,
V_164 ,
} ;
return F_56 ( V_114 -> V_56 , V_114 -> V_104 ,
( V_69 << 8 ) | V_90 [ V_114 -> V_104 ] ) ;
}
static int T_6 F_64 ( struct V_24 * V_25 )
{
struct V_165 * V_166 ;
struct V_167 V_114 ;
static struct V_168 V_169 = {
. V_170 = F_62 ,
. V_171 = F_63 ,
} ;
int V_116 ;
memset ( & V_114 , 0 , sizeof( V_114 ) ) ;
V_114 . V_56 = V_25 ;
V_116 = V_165 ( V_25 -> V_134 , 0 , & V_169 , NULL , & V_166 ) ;
if ( ! V_116 && V_25 -> V_172 & V_173 )
V_116 = F_65 ( V_166 , & V_114 , & V_25 -> V_114 [ 0 ] ) ;
V_114 . V_104 = 1 ;
if ( ! V_116 && ( V_25 -> V_172 & V_174 ) )
V_116 = F_65 ( V_166 , & V_114 , & V_25 -> V_114 [ 1 ] ) ;
V_114 . V_104 = 2 ;
if ( ! V_116 && ( V_25 -> V_172 & V_175 ) )
V_116 = F_65 ( V_166 , & V_114 , & V_25 -> V_114 [ 2 ] ) ;
return V_116 ;
}
static void F_66 ( struct V_24 * V_25 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_176 ; V_49 ++ )
F_67 ( V_25 -> V_45 [ V_49 ] ) ;
}
static int F_68 ( struct V_24 * V_25 )
{
F_10 ( V_177 , V_25 -> V_27 + V_178 ) ;
F_59 ( 25 ) ;
F_10 ( 0 , V_25 -> V_27 + V_178 ) ;
F_10 ( 0 , V_25 -> V_27 + V_179 ) ;
if ( V_25 -> V_22 >= 0 )
F_69 ( V_25 -> V_22 , V_25 ) ;
if ( V_25 -> V_180 )
F_70 ( V_25 -> V_180 ) ;
F_71 ( V_25 -> V_44 ) ;
F_72 ( V_25 -> V_44 ) ;
F_66 ( V_25 ) ;
return 0 ;
}
static int F_73 ( struct V_181 * V_23 )
{
struct V_24 * V_25 = V_23 -> V_182 ;
return F_68 ( V_25 ) ;
}
static int F_74 ( struct V_24 * V_25 )
{
unsigned long V_26 = V_25 -> V_27 ;
void T_2 * V_180 = V_25 -> V_180 ;
unsigned long V_152 ;
T_1 V_20 ;
int V_144 ;
int V_49 ;
F_10 ( V_177 , V_26 + V_178 ) ;
F_59 ( 25 ) ;
F_10 ( 0 , V_26 + V_178 ) ;
V_144 = 0xffff ;
while ( ( F_58 ( V_26 + V_150 ) & V_151 ) && -- V_144 )
F_59 ( 1 ) ;
if ( ! V_144 )
return - V_183 ;
F_10 ( V_184 , V_26 + V_156 ) ;
F_59 ( 250 ) ;
V_144 = 0xffff ;
while ( ( F_58 ( V_26 + V_153 ) & V_154 ) && -- V_144 )
F_59 ( 1 ) ;
F_10 ( V_157 , V_26 + V_150 ) ;
if ( ! V_144 )
return - V_183 ;
V_25 -> V_172 = 0 ;
V_152 = F_75 ( 500 ) + V_185 ;
while ( F_76 ( V_185 , V_152 ) ) {
V_20 = F_9 ( V_26 + V_153 ) ;
if ( V_20 & V_146 )
V_25 -> V_172 |= V_173 ;
if ( V_20 & V_147 )
V_25 -> V_172 |= V_174 ;
if ( V_20 & V_148 )
V_25 -> V_172 |= V_175 ;
if ( V_25 -> V_172 == V_186 )
break;
F_77 ( 1 ) ;
}
if ( ! V_25 -> V_172 ) {
F_61 ( & V_25 -> V_44 -> V_23 , L_3 ) ;
return - V_183 ;
}
if ( V_25 -> V_172 != V_186 ) {
F_78 ( & V_25 -> V_44 -> V_23 , L_4 ,
V_25 -> V_172 , V_186 ) ;
}
F_10 ( V_187 , V_26 + V_188 ) ;
F_10 ( V_187 | V_189 |
V_190 |
V_191 |
V_192 , V_26 + V_188 ) ;
F_10 ( 0 , V_26 + V_193 ) ;
F_10 ( V_194 , V_26 + V_195 ) ;
F_10 ( 0 , V_26 + V_196 ) ;
F_10 ( 0 , V_26 + V_197 ) ;
F_10 ( 0 , V_26 + V_198 ) ;
F_10 ( 0 , V_26 + V_199 ) ;
F_10 ( 0 , V_26 + V_200 ) ;
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ ) {
F_37 ( V_49 , F_79 ( V_180 , V_49 ) ) ;
F_37 ( V_201 | V_202 |
V_203 , F_80 ( V_180 , V_49 ) ) ;
}
F_10 ( 0xffff0000 , V_26 + V_204 ) ;
F_10 ( 0 , V_26 + V_205 ) ;
F_10 ( V_206 |
V_207 , V_26 + V_179 ) ;
return 0 ;
}
static int F_81 ( struct V_208 * V_23 )
{
struct V_209 * V_44 = F_82 ( V_23 ) ;
struct V_210 * V_134 = F_83 ( V_23 ) ;
struct V_24 * V_25 = V_134 -> V_56 ;
void T_2 * V_180 = V_25 -> V_180 ;
int V_49 ;
F_84 ( V_134 , V_211 ) ;
F_85 ( V_25 -> V_133 ) ;
if ( V_25 -> V_172 & V_173 )
F_86 ( V_25 -> V_114 [ 0 ] ) ;
if ( V_25 -> V_172 & V_174 )
F_86 ( V_25 -> V_114 [ 1 ] ) ;
if ( V_25 -> V_172 & V_175 )
F_86 ( V_25 -> V_114 [ 2 ] ) ;
if ( V_25 -> V_22 >= 0 ) {
F_69 ( V_25 -> V_22 , V_25 ) ;
V_25 -> V_22 = - 1 ;
}
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
F_87 ( V_25 -> V_45 [ V_49 ] , V_180 , 4096 ) ;
V_180 += 4096 ;
}
F_72 ( V_44 ) ;
F_88 ( V_44 ) ;
F_89 ( V_44 , V_212 ) ;
return 0 ;
}
static int F_90 ( struct V_208 * V_23 )
{
struct V_209 * V_44 = F_82 ( V_23 ) ;
struct V_210 * V_134 = F_83 ( V_23 ) ;
struct V_24 * V_25 = V_134 -> V_56 ;
void T_2 * V_180 = V_25 -> V_180 ;
int V_49 ;
F_89 ( V_44 , V_213 ) ;
F_91 ( V_44 ) ;
if ( F_92 ( V_44 ) < 0 ) {
F_61 ( & V_44 -> V_23 , L_5 ) ;
goto error;
}
if ( F_74 ( V_25 ) ) {
F_61 ( & V_44 -> V_23 , L_6 ) ;
goto error;
}
if ( F_93 ( V_44 -> V_22 , F_8 , V_214 ,
V_215 , V_25 ) ) {
F_61 ( & V_44 -> V_23 , L_7 , V_44 -> V_22 ) ;
goto error;
}
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
F_94 ( V_180 , V_25 -> V_45 [ V_49 ] , 4096 ) ;
V_180 += 4096 ;
}
memset ( V_25 -> V_45 [ 0 ] , 0 , 4096 ) ;
V_25 -> V_22 = V_44 -> V_22 ;
F_95 ( V_44 ) ;
if ( V_25 -> V_172 & V_173 )
F_96 ( V_25 -> V_114 [ 0 ] ) ;
if ( V_25 -> V_172 & V_174 )
F_96 ( V_25 -> V_114 [ 1 ] ) ;
if ( V_25 -> V_172 & V_175 )
F_96 ( V_25 -> V_114 [ 2 ] ) ;
F_84 ( V_134 , V_216 ) ;
return 0 ;
error:
F_97 ( V_134 ) ;
return - V_183 ;
}
static int F_98 ( struct V_24 * V_25 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_176 ; V_49 ++ ) {
V_25 -> V_45 [ V_49 ] = F_99 ( 4096 , V_217 ) ;
if ( ! V_25 -> V_45 [ V_49 ] )
return - V_58 ;
}
memset ( V_25 -> V_45 [ 0 ] , 0 , 4096 ) ;
return 0 ;
}
static int T_6 F_100 ( struct V_210 * V_134 ,
struct V_209 * V_44 )
{
struct V_24 * V_25 = V_134 -> V_56 ;
struct V_1 * V_1 ;
static struct V_218 V_169 = {
. V_219 = F_73 ,
} ;
int V_116 ;
int V_49 ;
V_116 = F_92 ( V_44 ) ;
if ( V_116 )
goto V_220;
if ( F_101 ( V_44 , F_102 ( 30 ) ) < 0 ) {
F_61 ( & V_44 -> V_23 , L_8 ) ;
goto V_221;
}
memset ( V_25 , 0 , sizeof( * V_25 ) ) ;
F_103 ( & V_25 -> V_149 ) ;
F_104 ( & V_25 -> V_47 ) ;
V_25 -> V_134 = V_134 ;
V_25 -> V_44 = V_44 ;
V_25 -> V_22 = - 1 ;
V_25 -> V_27 = F_105 ( V_44 , 0 ) ;
V_116 = F_106 ( V_44 , L_1 ) ;
if ( V_116 ) {
F_61 ( & V_44 -> V_23 , L_9 ) ;
goto V_221;
}
V_116 = - V_183 ;
V_25 -> V_180 = F_107 ( F_105 ( V_44 , 1 ) , 0x4000 ) ;
if ( ! V_25 -> V_180 ) {
F_61 ( & V_44 -> V_23 , L_10 ) ;
goto V_222;
}
V_116 = F_98 ( V_25 ) ;
if ( V_116 < 0 ) {
F_61 ( & V_44 -> V_23 , L_11 ) ;
goto V_222;
}
V_116 = F_74 ( V_25 ) ;
if ( V_116 )
goto V_222;
V_116 = F_93 ( V_44 -> V_22 , F_8 , V_214 , V_215 ,
V_25 ) ;
if ( V_116 ) {
F_61 ( & V_44 -> V_23 , L_12 , V_25 -> V_22 ) ;
goto V_222;
}
V_25 -> V_22 = V_44 -> V_22 ;
F_95 ( V_44 ) ;
for ( V_49 = 0 ; V_49 < 64 ; V_49 ++ ) {
V_1 = & V_25 -> V_34 [ V_49 ] ;
V_1 -> V_104 = V_49 ;
V_1 -> V_4 = F_108 ( V_25 -> V_180 , V_49 ) ;
V_1 -> V_64 = F_109 ( V_25 -> V_180 , V_49 ) ;
}
V_1 = & V_25 -> V_37 ;
V_1 -> V_8 = V_103 ;
V_1 -> V_104 = V_223 ;
V_1 -> V_4 = F_110 ( V_25 -> V_180 , V_1 -> V_104 ) ;
V_116 = F_111 ( V_134 , V_224 , V_25 , & V_169 ) ;
if ( V_116 )
goto V_222;
F_112 ( V_134 , & V_44 -> V_23 ) ;
return 0 ;
V_222:
F_68 ( V_25 ) ;
V_221:
F_72 ( V_44 ) ;
V_220:
return V_116 ;
}
static int T_6 F_113 ( struct V_209 * V_44 ,
const struct V_225 * V_226 )
{
struct V_210 * V_134 ;
struct V_24 * V_25 ;
int V_116 ;
V_116 = - V_227 ;
if ( ! V_228 )
goto V_220;
V_186 &= V_173 | V_174 |
V_175 ;
if ( ! V_186 )
V_186 = V_173 ;
V_116 = F_114 ( V_229 , V_230 , V_231 , sizeof( * V_25 ) , & V_134 ) ;
if ( V_116 < 0 )
goto V_220;
strcpy ( V_134 -> V_232 , L_1 ) ;
strcpy ( V_134 -> V_233 , L_1 ) ;
V_116 = F_100 ( V_134 , V_44 ) ;
if ( V_116 )
goto V_234;
V_25 = V_134 -> V_56 ;
V_116 = F_64 ( V_25 ) ;
if ( V_116 )
goto V_234;
V_116 = F_51 ( V_25 ) ;
if ( V_116 )
goto V_234;
snprintf ( V_134 -> V_235 , sizeof( V_134 -> V_235 ) ,
L_13 ,
V_134 -> V_233 , F_115 ( V_25 -> V_114 [ 0 ] ) ,
V_25 -> V_27 , V_25 -> V_22 ) ;
V_116 = F_116 ( V_134 ) ;
if ( V_116 )
goto V_234;
F_117 ( V_44 , V_134 ) ;
return 0 ;
V_234:
F_118 ( V_134 ) ;
V_220:
return V_116 ;
}
static void T_7 F_119 ( struct V_209 * V_44 )
{
F_118 ( F_120 ( V_44 ) ) ;
F_117 ( V_44 , NULL ) ;
}
