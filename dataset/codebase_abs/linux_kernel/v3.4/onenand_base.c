static unsigned short F_1 ( void T_1 * V_1 )
{
return F_2 ( V_1 ) ;
}
static void F_3 ( unsigned short V_2 , void T_1 * V_1 )
{
F_4 ( V_2 , V_1 ) ;
}
static int F_5 ( struct V_3 * V_4 , int V_5 )
{
if ( V_5 & V_4 -> V_6 )
return V_7 | ( V_5 ^ V_4 -> V_6 ) ;
return V_5 ;
}
static int F_6 ( struct V_3 * V_4 , int V_5 )
{
if ( V_5 & V_4 -> V_6 )
return V_7 ;
return V_8 ;
}
static int F_7 ( int V_9 , int V_10 )
{
int V_11 , V_12 ;
V_11 = V_9 & V_13 ;
V_12 = V_10 & V_14 ;
return ( ( V_11 << V_15 ) | V_12 ) ;
}
static int F_8 ( int V_16 , int V_17 , int V_18 )
{
int V_19 , V_20 ;
V_19 = V_17 & V_21 ;
if ( V_16 )
V_19 |= V_22 ;
else
V_19 |= V_23 ;
V_20 = V_18 & V_24 ;
return ( ( V_19 << V_25 ) | V_20 ) ;
}
static unsigned F_9 ( struct V_3 * V_4 , T_2 V_1 )
{
unsigned V_26 , V_27 , V_28 = 0 ;
if ( F_10 ( V_4 ) && V_1 >= V_4 -> V_29 [ 0 ] ) {
V_28 = 1 ;
V_1 -= V_4 -> V_29 [ 0 ] ;
}
V_26 = V_4 -> V_26 [ V_28 ] ;
V_27 = V_1 >> ( V_4 -> V_30 - 1 ) ;
if ( V_27 > V_26 )
V_27 = ( V_27 + V_26 + 1 ) >> 1 ;
V_27 += V_28 ? V_4 -> V_6 : 0 ;
return V_27 ;
}
inline unsigned F_11 ( struct V_3 * V_4 , T_2 V_1 )
{
if ( ! F_12 ( V_4 ) )
return V_1 >> V_4 -> V_30 ;
return F_9 ( V_4 , V_1 ) ;
}
static T_2 F_13 ( struct V_3 * V_4 , int V_5 )
{
T_2 V_31 = 0 ;
int V_28 = 0 , V_26 ;
if ( F_10 ( V_4 ) && V_5 >= V_4 -> V_6 ) {
V_5 -= V_4 -> V_6 ;
V_28 = 1 ;
V_31 = V_4 -> V_29 [ 0 ] ;
}
V_26 = V_4 -> V_26 [ V_28 ] ;
V_31 += ( T_2 ) V_5 << ( V_4 -> V_30 - 1 ) ;
if ( V_5 > ( V_26 + 1 ) )
V_31 += ( T_2 ) ( V_5 - V_26 - 1 ) << ( V_4 -> V_30 - 1 ) ;
return V_31 ;
}
T_2 F_14 ( struct V_3 * V_4 , int V_5 )
{
if ( ! F_12 ( V_4 ) )
return ( T_2 ) V_5 << V_4 -> V_30 ;
return F_13 ( V_4 , V_5 ) ;
}
static inline int F_15 ( int V_32 )
{
int V_33 = V_32 >> V_34 ;
return ( V_33 & V_35 ) ;
}
int F_16 ( struct V_36 * V_37 , T_2 V_1 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_37 -> V_39 ; V_38 ++ )
if ( V_1 < V_37 -> V_40 [ V_38 ] . V_41 )
break;
return V_38 - 1 ;
}
static int F_17 ( struct V_36 * V_37 , int V_42 , T_2 V_1 , T_3 V_43 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
int V_2 , V_5 , V_9 ;
switch ( V_42 ) {
case V_45 :
case V_46 :
case V_47 :
case V_48 :
V_5 = - 1 ;
V_9 = - 1 ;
break;
case V_49 :
V_5 = V_1 * V_4 -> V_6 ;
V_9 = - 1 ;
break;
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
V_5 = F_11 ( V_4 , V_1 ) ;
V_9 = - 1 ;
break;
case V_55 :
V_42 = V_56 ;
V_5 = V_1 * V_4 -> V_6 ;
V_9 = 0 ;
break;
default:
V_5 = F_11 ( V_4 , V_1 ) ;
if ( F_12 ( V_4 ) )
V_9 = ( int ) ( V_1 - F_14 ( V_4 , V_5 ) ) >>\
V_4 -> V_57 ;
else
V_9 = ( int ) ( V_1 >> V_4 -> V_57 ) ;
if ( F_18 ( V_4 ) ) {
V_5 &= ~ 1 ;
if ( V_1 & V_4 -> V_58 )
V_5 ++ ;
V_9 >>= 1 ;
}
V_9 &= V_4 -> V_59 ;
break;
}
if ( V_42 == V_53 ) {
V_2 = F_6 ( V_4 , V_5 ) ;
V_4 -> V_60 ( V_2 , V_4 -> V_61 + V_62 ) ;
if ( F_18 ( V_4 ) || F_19 ( V_4 ) )
F_20 ( V_4 ) ;
else
F_21 ( V_4 ) ;
return 0 ;
}
if ( V_5 != - 1 ) {
V_2 = F_5 ( V_4 , V_5 ) ;
V_4 -> V_60 ( V_2 , V_4 -> V_61 + V_63 ) ;
V_2 = F_6 ( V_4 , V_5 ) ;
V_4 -> V_60 ( V_2 , V_4 -> V_61 + V_62 ) ;
}
if ( V_9 != - 1 ) {
int V_17 = 0 , V_18 = 0 ;
int V_64 ;
switch ( V_42 ) {
case V_65 :
case V_56 :
case V_66 :
if ( F_19 ( V_4 ) )
V_64 = F_20 ( V_4 ) ;
else
V_64 = F_21 ( V_4 ) ;
break;
default:
if ( F_18 ( V_4 ) && V_42 == V_67 )
V_42 = V_68 ;
V_64 = F_22 ( V_4 ) ;
break;
}
V_2 = F_7 ( V_9 , V_17 ) ;
V_4 -> V_60 ( V_2 , V_4 -> V_61 + V_69 ) ;
V_2 = F_8 ( V_64 , V_17 , V_18 ) ;
V_4 -> V_60 ( V_2 , V_4 -> V_61 + V_70 ) ;
}
V_4 -> V_60 ( V_71 , V_4 -> V_61 + V_72 ) ;
V_4 -> V_60 ( V_42 , V_4 -> V_61 + V_73 ) ;
return 0 ;
}
static inline int F_23 ( struct V_3 * V_4 )
{
int V_74 , V_38 , V_75 = 0 ;
if ( ! F_12 ( V_4 ) && ! F_19 ( V_4 ) )
return V_4 -> V_76 ( V_4 -> V_61 + V_77 ) ;
for ( V_38 = 0 ; V_38 < 4 ; V_38 ++ ) {
V_74 = V_4 -> V_76 ( V_4 -> V_61 + V_77 + V_38 * 2 ) ;
if ( F_24 ( ! V_74 ) )
continue;
if ( V_74 & V_78 )
return V_79 ;
else
V_75 = V_80 ;
}
return V_75 ;
}
static int F_25 ( struct V_36 * V_37 , int V_81 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
unsigned long V_82 ;
unsigned int V_83 = V_84 ;
unsigned int V_85 = 0 ;
unsigned int V_86 ;
V_82 = V_87 + F_26 ( 20 ) ;
while ( F_27 ( V_87 , V_82 ) ) {
V_85 = V_4 -> V_76 ( V_4 -> V_61 + V_72 ) ;
if ( V_85 & V_83 )
break;
if ( V_81 != V_88 && V_81 != V_89 )
F_28 () ;
}
V_85 = V_4 -> V_76 ( V_4 -> V_61 + V_72 ) ;
V_86 = V_4 -> V_76 ( V_4 -> V_61 + V_90 ) ;
if ( V_85 & V_91 ) {
int V_74 = F_23 ( V_4 ) ;
if ( V_74 ) {
if ( V_74 & V_79 ) {
F_29 ( V_92 L_1 ,
V_93 , V_74 ) ;
V_37 -> V_94 . V_95 ++ ;
return - V_96 ;
} else if ( V_74 & V_80 ) {
F_29 ( V_97 L_2 ,
V_93 , V_74 ) ;
V_37 -> V_94 . V_98 ++ ;
}
}
} else if ( V_81 == V_88 ) {
F_29 ( V_92 L_3 ,
V_93 , V_86 , V_85 ) ;
return - V_99 ;
}
if ( V_81 == V_89 && ! ( V_85 & V_100 ) ) {
F_29 ( V_92 L_4 ,
V_93 , V_86 , V_85 ) ;
return - V_99 ;
}
if ( ! ( V_85 & V_84 ) ) {
F_29 ( V_92 L_5 ,
V_93 , V_86 , V_85 ) ;
return - V_99 ;
}
if ( V_86 & V_101 ) {
F_29 ( V_92 L_6 ,
V_93 , V_86 ) ;
if ( V_86 & V_102 )
F_29 ( V_92 L_7 , V_93 ) ;
return - V_99 ;
}
return 0 ;
}
static T_4 F_30 ( int V_103 , void * V_104 )
{
struct V_3 * V_4 = V_104 ;
if ( ! V_4 -> V_105 . V_106 )
V_105 ( & V_4 -> V_105 ) ;
return V_107 ;
}
static int F_31 ( struct V_36 * V_37 , int V_81 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
F_32 ( & V_4 -> V_105 ) ;
return F_25 ( V_37 , V_81 ) ;
}
static int F_33 ( struct V_36 * V_37 , int V_81 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
unsigned long V_108 , V_82 ;
V_4 -> V_109 = F_31 ;
V_82 = F_26 ( 100 ) ;
V_108 = F_34 ( & V_4 -> V_105 , V_82 ) ;
if ( ! V_108 ) {
F_29 ( V_110 L_8
L_9 ) ;
F_35 ( V_4 -> V_103 , V_4 ) ;
V_4 -> V_109 = F_25 ;
}
return F_25 ( V_37 , V_81 ) ;
}
static void F_36 ( struct V_36 * V_37 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
int V_111 ;
F_37 ( & V_4 -> V_105 ) ;
if ( V_4 -> V_103 <= 0 ) {
V_4 -> V_109 = F_25 ;
return;
}
if ( F_38 ( V_4 -> V_103 , & F_30 ,
V_112 , L_10 , V_4 ) ) {
V_4 -> V_109 = F_25 ;
return;
}
V_111 = V_4 -> V_76 ( V_4 -> V_61 + V_113 ) ;
V_111 |= V_114 ;
V_4 -> V_60 ( V_111 , V_4 -> V_61 + V_113 ) ;
V_4 -> V_109 = F_33 ;
}
static inline int F_39 ( struct V_36 * V_37 , int V_115 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
if ( F_22 ( V_4 ) ) {
if ( V_115 == V_116 )
return V_4 -> V_58 ;
if ( V_115 == V_117 )
return V_37 -> V_118 ;
}
return 0 ;
}
static int F_40 ( struct V_36 * V_37 , int V_115 ,
unsigned char * V_119 , int V_41 , T_3 V_18 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
void T_1 * V_120 ;
V_120 = V_4 -> V_61 + V_115 ;
V_120 += F_39 ( V_37 , V_115 ) ;
if ( F_41 ( V_18 ) ) {
unsigned short V_121 ;
V_18 -- ;
V_121 = V_4 -> V_76 ( V_120 + V_41 + V_18 ) ;
V_119 [ V_18 ] = ( V_121 & 0xff ) ;
}
memcpy ( V_119 , V_120 + V_41 , V_18 ) ;
return 0 ;
}
static int F_42 ( struct V_36 * V_37 , int V_115 ,
unsigned char * V_119 , int V_41 , T_3 V_18 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
void T_1 * V_120 ;
V_120 = V_4 -> V_61 + V_115 ;
V_120 += F_39 ( V_37 , V_115 ) ;
V_4 -> V_122 ( V_37 , V_123 ) ;
if ( F_41 ( V_18 ) ) {
unsigned short V_121 ;
V_18 -- ;
V_121 = V_4 -> V_76 ( V_120 + V_41 + V_18 ) ;
V_119 [ V_18 ] = ( V_121 & 0xff ) ;
}
memcpy ( V_119 , V_120 + V_41 , V_18 ) ;
V_4 -> V_122 ( V_37 , 0 ) ;
return 0 ;
}
static int F_43 ( struct V_36 * V_37 , int V_115 ,
const unsigned char * V_119 , int V_41 , T_3 V_18 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
void T_1 * V_120 ;
V_120 = V_4 -> V_61 + V_115 ;
V_120 += F_39 ( V_37 , V_115 ) ;
if ( F_41 ( V_18 ) ) {
unsigned short V_121 ;
int V_124 ;
V_18 -- ;
V_124 = V_41 + V_18 ;
V_121 = V_4 -> V_76 ( V_120 + V_124 ) ;
V_121 = ( V_121 & ~ 0xff ) | V_119 [ V_18 ] ;
V_4 -> V_60 ( V_121 , V_120 + V_124 ) ;
}
memcpy ( V_120 + V_41 , V_119 , V_18 ) ;
return 0 ;
}
static int F_44 ( struct V_36 * V_37 , T_2 V_1 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
int V_125 , V_5 , V_9 ;
V_5 = ( int ) ( V_1 >> V_4 -> V_30 ) & ~ 1 ;
if ( V_1 & V_4 -> V_58 )
V_5 ++ ;
V_9 = ( int ) ( V_1 >> ( V_4 -> V_57 + 1 ) ) & V_4 -> V_59 ;
V_125 = ( V_5 << 7 ) | V_9 ;
return V_125 ;
}
static int F_45 ( struct V_36 * V_37 , T_2 V_1 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
int V_125 , V_126 = 0 ;
unsigned int V_38 ;
if ( F_18 ( V_4 ) )
V_125 = F_44 ( V_37 , V_1 ) ;
else
V_125 = ( int ) ( V_1 >> V_4 -> V_57 ) ;
V_38 = F_22 ( V_4 ) ;
if ( V_4 -> V_120 [ V_38 ] . V_125 == V_125 )
V_126 = 1 ;
else {
V_38 = F_46 ( V_4 ) ;
if ( V_4 -> V_120 [ V_38 ] . V_125 == V_125 ) {
F_21 ( V_4 ) ;
V_126 = 1 ;
}
}
if ( V_126 && F_10 ( V_4 ) ) {
int V_5 = F_11 ( V_4 , V_1 ) ;
int V_2 = F_6 ( V_4 , V_5 ) ;
V_4 -> V_60 ( V_2 , V_4 -> V_61 + V_62 ) ;
}
return V_126 ;
}
static void F_47 ( struct V_36 * V_37 , T_2 V_1 ,
int V_127 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
int V_125 ;
unsigned int V_38 ;
if ( F_18 ( V_4 ) )
V_125 = F_44 ( V_37 , V_1 ) ;
else
V_125 = ( int ) ( V_1 >> V_4 -> V_57 ) ;
V_38 = F_46 ( V_4 ) ;
if ( V_4 -> V_120 [ V_38 ] . V_125 == V_125 )
V_4 -> V_120 [ V_38 ] . V_125 = - 1 ;
V_38 = F_22 ( V_4 ) ;
if ( V_127 )
V_4 -> V_120 [ V_38 ] . V_125 = V_125 ;
else
V_4 -> V_120 [ V_38 ] . V_125 = - 1 ;
}
static void F_48 ( struct V_36 * V_37 , T_2 V_1 ,
unsigned int V_43 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
int V_38 ;
T_2 V_128 = V_1 + V_43 ;
for ( V_38 = 0 ; V_38 < V_129 ; V_38 ++ ) {
T_2 V_130 = V_4 -> V_120 [ V_38 ] . V_125 << V_4 -> V_57 ;
if ( V_130 >= V_1 && V_130 < V_128 )
V_4 -> V_120 [ V_38 ] . V_125 = - 1 ;
}
}
static int F_49 ( struct V_36 * V_37 , int V_131 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
F_50 ( V_109 , V_132 ) ;
while ( 1 ) {
F_51 ( & V_4 -> V_133 ) ;
if ( V_4 -> V_81 == V_134 ) {
V_4 -> V_81 = V_131 ;
F_52 ( & V_4 -> V_133 ) ;
if ( V_131 != V_135 && V_4 -> V_136 )
V_4 -> V_136 ( V_37 ) ;
break;
}
if ( V_131 == V_135 ) {
F_52 ( & V_4 -> V_133 ) ;
return ( V_4 -> V_81 == V_135 ) ? 0 : - V_137 ;
}
F_53 ( V_138 ) ;
F_54 ( & V_4 -> V_139 , & V_109 ) ;
F_52 ( & V_4 -> V_133 ) ;
F_55 () ;
F_56 ( & V_4 -> V_139 , & V_109 ) ;
}
return 0 ;
}
static void F_57 ( struct V_36 * V_37 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
if ( V_4 -> V_81 != V_135 && V_4 -> V_140 )
V_4 -> V_140 ( V_37 ) ;
F_51 ( & V_4 -> V_133 ) ;
V_4 -> V_81 = V_134 ;
F_58 ( & V_4 -> V_139 ) ;
F_52 ( & V_4 -> V_133 ) ;
}
static int F_59 ( struct V_36 * V_37 , T_5 * V_141 , int V_142 ,
int V_143 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
struct V_144 * free ;
int V_145 = V_142 ;
int V_146 = V_142 + V_143 ;
int V_147 = 0 ;
unsigned int V_38 ;
T_5 * V_148 = V_4 -> V_148 ;
free = V_4 -> V_149 -> V_150 ;
for ( V_38 = 0 ; V_38 < V_151 && free -> V_152 ; V_38 ++ , free ++ ) {
if ( V_145 >= V_147 )
V_145 += free -> V_41 - V_147 ;
if ( V_146 >= V_147 )
V_146 += free -> V_41 - V_147 ;
V_147 = free -> V_41 + free -> V_152 ;
}
V_4 -> V_153 ( V_37 , V_117 , V_148 , 0 , V_37 -> V_118 ) ;
free = V_4 -> V_149 -> V_150 ;
for ( V_38 = 0 ; V_38 < V_151 && free -> V_152 ; V_38 ++ , free ++ ) {
int V_154 = free -> V_41 + free -> V_152 ;
if ( free -> V_41 < V_146 && V_154 > V_145 ) {
int V_155 = F_60 ( int , free -> V_41 , V_145 ) ;
int V_156 = F_61 ( int , V_154 , V_146 ) ;
int V_157 = V_156 - V_155 ;
memcpy ( V_141 , V_148 + V_155 , V_157 ) ;
V_141 += V_157 ;
} else if ( V_142 == 0 )
break;
}
return 0 ;
}
static int F_62 ( struct V_36 * V_37 , T_2 V_1 , int V_158 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
int V_38 ;
if ( ! F_12 ( V_4 ) )
return V_158 ;
if ( ! F_63 ( V_158 ) && V_158 != V_159 )
return V_158 ;
V_38 = F_16 ( V_37 , V_1 ) ;
if ( V_37 -> V_40 [ V_38 ] . V_160 < ( 1 << V_4 -> V_30 ) )
return V_158 ;
F_29 ( V_110 L_11 ,
V_93 ) ;
V_37 -> V_94 . V_95 -- ;
V_4 -> V_161 ( V_37 , V_65 , V_1 , V_4 -> V_58 ) ;
return V_4 -> V_109 ( V_37 , V_88 ) ;
}
static int F_64 ( struct V_36 * V_37 , T_2 V_162 ,
struct V_163 * V_164 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
struct V_165 V_166 ;
T_3 V_43 = V_164 -> V_43 ;
T_3 V_167 = V_164 -> V_167 ;
T_6 * V_141 = V_164 -> V_168 ;
T_6 * V_169 = V_164 -> V_169 ;
int V_170 = 0 , V_142 , V_143 ;
int V_171 = 0 , V_172 , V_173 , V_118 ;
int V_174 = 0 ;
int V_58 = V_4 -> V_58 ;
F_65 ( L_12 , V_93 , ( unsigned int ) V_162 ,
( int ) V_43 ) ;
if ( V_164 -> V_175 == V_176 )
V_118 = V_4 -> V_149 -> V_177 ;
else
V_118 = V_37 -> V_118 ;
V_172 = V_162 & ( V_37 -> V_118 - 1 ) ;
if ( V_162 + V_43 > V_37 -> V_178 ) {
F_29 ( V_92 L_13 ,
V_93 ) ;
V_164 -> V_179 = 0 ;
V_164 -> V_180 = 0 ;
return - V_181 ;
}
V_166 = V_37 -> V_94 ;
while ( V_170 < V_43 ) {
F_28 () ;
V_143 = F_61 ( int , V_58 , V_43 - V_170 ) ;
V_142 = V_162 & ( V_58 - 1 ) ;
if ( V_142 + V_143 > V_58 )
V_143 = V_58 - V_142 ;
if ( ! F_45 ( V_37 , V_162 ) ) {
V_4 -> V_161 ( V_37 , V_56 , V_162 , V_58 ) ;
V_174 = V_4 -> V_109 ( V_37 , V_88 ) ;
if ( F_66 ( V_174 ) )
V_174 = F_62 ( V_37 , V_162 , V_174 ) ;
F_47 ( V_37 , V_162 , ! V_174 ) ;
if ( F_63 ( V_174 ) )
V_174 = 0 ;
if ( V_174 )
break;
}
V_4 -> V_153 ( V_37 , V_116 , V_141 , V_142 , V_143 ) ;
if ( V_169 ) {
V_173 = V_118 - V_172 ;
V_173 = F_61 ( int , V_173 , V_167 - V_171 ) ;
if ( V_164 -> V_175 == V_176 )
F_59 ( V_37 , V_169 , V_172 , V_173 ) ;
else
V_4 -> V_153 ( V_37 , V_117 , V_169 , V_172 , V_173 ) ;
V_171 += V_173 ;
V_169 += V_173 ;
V_172 = 0 ;
}
V_170 += V_143 ;
if ( V_170 == V_43 )
break;
V_162 += V_143 ;
V_141 += V_143 ;
}
V_164 -> V_179 = V_170 ;
V_164 -> V_180 = V_171 ;
if ( V_174 )
return V_174 ;
if ( V_37 -> V_94 . V_95 - V_166 . V_95 )
return - V_96 ;
return V_37 -> V_94 . V_98 - V_166 . V_98 ? - V_182 : 0 ;
}
static int F_67 ( struct V_36 * V_37 , T_2 V_162 ,
struct V_163 * V_164 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
struct V_165 V_166 ;
T_3 V_43 = V_164 -> V_43 ;
T_3 V_167 = V_164 -> V_167 ;
T_6 * V_141 = V_164 -> V_168 ;
T_6 * V_169 = V_164 -> V_169 ;
int V_170 = 0 , V_142 , V_143 ;
int V_171 = 0 , V_172 , V_173 , V_118 ;
int V_174 = 0 , V_26 = 0 ;
int V_58 = V_4 -> V_58 ;
F_65 ( L_12 , V_93 , ( unsigned int ) V_162 ,
( int ) V_43 ) ;
if ( V_164 -> V_175 == V_176 )
V_118 = V_4 -> V_149 -> V_177 ;
else
V_118 = V_37 -> V_118 ;
V_172 = V_162 & ( V_37 -> V_118 - 1 ) ;
if ( ( V_162 + V_43 ) > V_37 -> V_178 ) {
F_29 ( V_92 L_13 ,
V_93 ) ;
V_164 -> V_179 = 0 ;
V_164 -> V_180 = 0 ;
return - V_181 ;
}
V_166 = V_37 -> V_94 ;
if ( V_170 < V_43 ) {
if ( ! F_45 ( V_37 , V_162 ) ) {
V_4 -> V_161 ( V_37 , V_56 , V_162 , V_58 ) ;
V_174 = V_4 -> V_109 ( V_37 , V_88 ) ;
F_47 ( V_37 , V_162 , ! V_174 ) ;
if ( F_63 ( V_174 ) )
V_174 = 0 ;
}
}
V_143 = F_61 ( int , V_58 , V_43 - V_170 ) ;
V_142 = V_162 & ( V_58 - 1 ) ;
if ( V_142 + V_143 > V_58 )
V_143 = V_58 - V_142 ;
while ( ! V_174 ) {
V_162 += V_143 ;
if ( V_170 + V_143 < V_43 ) {
V_4 -> V_161 ( V_37 , V_56 , V_162 , V_58 ) ;
if ( F_10 ( V_4 ) &&
F_66 ( V_162 == ( V_4 -> V_183 >> 1 ) ) ) {
V_4 -> V_60 ( V_8 , V_4 -> V_61 + V_62 ) ;
V_26 = 1 ;
} else
V_26 = 0 ;
F_68 ( V_4 ) ;
}
V_4 -> V_153 ( V_37 , V_116 , V_141 , V_142 , V_143 ) ;
if ( V_169 ) {
V_173 = V_118 - V_172 ;
V_173 = F_61 ( int , V_173 , V_167 - V_171 ) ;
if ( V_164 -> V_175 == V_176 )
F_59 ( V_37 , V_169 , V_172 , V_173 ) ;
else
V_4 -> V_153 ( V_37 , V_117 , V_169 , V_172 , V_173 ) ;
V_171 += V_173 ;
V_169 += V_173 ;
V_172 = 0 ;
}
V_170 += V_143 ;
if ( V_170 == V_43 )
break;
if ( F_66 ( V_26 ) )
V_4 -> V_60 ( V_7 , V_4 -> V_61 + V_62 ) ;
F_21 ( V_4 ) ;
V_141 += V_143 ;
V_143 = F_61 ( int , V_58 , V_43 - V_170 ) ;
V_142 = 0 ;
F_28 () ;
V_174 = V_4 -> V_109 ( V_37 , V_88 ) ;
F_47 ( V_37 , V_162 , ! V_174 ) ;
if ( F_63 ( V_174 ) )
V_174 = 0 ;
}
V_164 -> V_179 = V_170 ;
V_164 -> V_180 = V_171 ;
if ( V_174 )
return V_174 ;
if ( V_37 -> V_94 . V_95 - V_166 . V_95 )
return - V_96 ;
return V_37 -> V_94 . V_98 - V_166 . V_98 ? - V_182 : 0 ;
}
static int F_69 ( struct V_36 * V_37 , T_2 V_162 ,
struct V_163 * V_164 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
struct V_165 V_166 ;
int V_170 = 0 , V_143 , V_142 , V_118 ;
T_3 V_43 = V_164 -> V_167 ;
unsigned int V_175 = V_164 -> V_175 ;
T_6 * V_141 = V_164 -> V_169 ;
int V_174 = 0 , V_184 ;
V_162 += V_164 -> V_185 ;
F_65 ( L_12 , V_93 , ( unsigned int ) V_162 ,
( int ) V_43 ) ;
V_164 -> V_180 = 0 ;
if ( V_175 == V_176 )
V_118 = V_4 -> V_149 -> V_177 ;
else
V_118 = V_37 -> V_118 ;
V_142 = V_162 & ( V_37 -> V_118 - 1 ) ;
if ( F_66 ( V_142 >= V_118 ) ) {
F_29 ( V_92 L_14 ,
V_93 ) ;
return - V_181 ;
}
if ( F_66 ( V_162 >= V_37 -> V_178 ||
V_142 + V_43 > ( ( V_37 -> V_178 >> V_4 -> V_57 ) -
( V_162 >> V_4 -> V_57 ) ) * V_118 ) ) {
F_29 ( V_92 L_15 ,
V_93 ) ;
return - V_181 ;
}
V_166 = V_37 -> V_94 ;
V_184 = F_19 ( V_4 ) ? V_56 : V_66 ;
while ( V_170 < V_43 ) {
F_28 () ;
V_143 = V_118 - V_142 ;
V_143 = F_61 ( int , V_143 , V_43 ) ;
V_4 -> V_161 ( V_37 , V_184 , V_162 , V_37 -> V_118 ) ;
F_47 ( V_37 , V_162 , 0 ) ;
V_174 = V_4 -> V_109 ( V_37 , V_88 ) ;
if ( F_66 ( V_174 ) )
V_174 = F_62 ( V_37 , V_162 , V_174 ) ;
if ( V_174 && ! F_63 ( V_174 ) ) {
F_29 ( V_92 L_16 ,
V_93 , V_174 ) ;
break;
}
if ( V_175 == V_176 )
F_59 ( V_37 , V_141 , V_142 , V_143 ) ;
else
V_4 -> V_153 ( V_37 , V_117 , V_141 , V_142 , V_143 ) ;
V_170 += V_143 ;
if ( V_170 == V_43 )
break;
V_141 += V_143 ;
if ( V_170 < V_43 ) {
V_162 += V_37 -> V_58 ;
V_142 = 0 ;
}
}
V_164 -> V_180 = V_170 ;
if ( V_174 )
return V_174 ;
if ( V_37 -> V_94 . V_95 - V_166 . V_95 )
return - V_96 ;
return 0 ;
}
static int F_70 ( struct V_36 * V_37 , T_2 V_162 , T_3 V_43 ,
T_3 * V_179 , T_6 * V_141 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
struct V_163 V_164 = {
. V_43 = V_43 ,
. V_167 = 0 ,
. V_168 = V_141 ,
. V_169 = NULL ,
} ;
int V_174 ;
F_49 ( V_37 , V_88 ) ;
V_174 = F_19 ( V_4 ) ?
F_64 ( V_37 , V_162 , & V_164 ) :
F_67 ( V_37 , V_162 , & V_164 ) ;
F_57 ( V_37 ) ;
* V_179 = V_164 . V_179 ;
return V_174 ;
}
static int F_71 ( struct V_36 * V_37 , T_2 V_162 ,
struct V_163 * V_164 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
int V_174 ;
switch ( V_164 -> V_175 ) {
case V_186 :
case V_176 :
break;
case V_187 :
default:
return - V_181 ;
}
F_49 ( V_37 , V_88 ) ;
if ( V_164 -> V_168 )
V_174 = F_19 ( V_4 ) ?
F_64 ( V_37 , V_162 , V_164 ) :
F_67 ( V_37 , V_162 , V_164 ) ;
else
V_174 = F_69 ( V_37 , V_162 , V_164 ) ;
F_57 ( V_37 ) ;
return V_174 ;
}
static int F_72 ( struct V_36 * V_37 , int V_81 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
unsigned long V_82 ;
unsigned int V_85 , V_86 , V_74 , V_188 , V_189 ;
V_82 = V_87 + F_26 ( 20 ) ;
while ( F_27 ( V_87 , V_82 ) ) {
V_85 = V_4 -> V_76 ( V_4 -> V_61 + V_72 ) ;
if ( V_85 & V_84 )
break;
}
V_85 = V_4 -> V_76 ( V_4 -> V_61 + V_72 ) ;
V_86 = V_4 -> V_76 ( V_4 -> V_61 + V_90 ) ;
V_188 = V_4 -> V_76 ( V_4 -> V_61 + V_63 ) ;
V_189 = V_4 -> V_76 ( V_4 -> V_61 + V_69 ) ;
if ( V_85 & V_91 ) {
V_74 = F_23 ( V_4 ) ;
if ( V_74 & V_79 ) {
F_29 ( V_97 L_17
L_18 ,
V_93 , V_74 , V_86 , V_85 , V_188 , V_189 ) ;
return V_159 ;
}
} else {
F_29 ( V_92 L_19
L_18 ,
V_93 , V_86 , V_85 , V_188 , V_189 ) ;
return V_190 ;
}
if ( V_86 & V_101 ) {
F_29 ( V_97 L_20
L_21 , V_93 , V_86 , V_85 , V_188 , V_189 ) ;
return V_191 ;
}
return 0 ;
}
int F_73 ( struct V_36 * V_37 , T_2 V_162 ,
struct V_163 * V_164 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
int V_170 = 0 , V_143 , V_142 ;
int V_174 = 0 , V_184 ;
T_3 V_43 = V_164 -> V_167 ;
T_6 * V_141 = V_164 -> V_169 ;
F_65 ( L_22 , V_93 , ( unsigned int ) V_162 ,
V_43 ) ;
V_164 -> V_180 = 0 ;
if ( F_66 ( ( V_162 + V_43 ) > V_37 -> V_178 ) ) {
F_29 ( V_92 L_13 ,
V_93 ) ;
return V_190 ;
}
F_49 ( V_37 , V_88 ) ;
V_142 = V_162 & ( V_37 -> V_118 - 1 ) ;
V_184 = F_19 ( V_4 ) ? V_56 : V_66 ;
while ( V_170 < V_43 ) {
F_28 () ;
V_143 = V_37 -> V_118 - V_142 ;
V_143 = F_61 ( int , V_143 , V_43 ) ;
V_4 -> V_161 ( V_37 , V_184 , V_162 , V_37 -> V_118 ) ;
F_47 ( V_37 , V_162 , 0 ) ;
V_174 = V_4 -> V_192 ( V_37 , V_88 ) ;
if ( F_66 ( V_174 ) )
V_174 = F_62 ( V_37 , V_162 , V_174 ) ;
if ( V_174 )
break;
V_4 -> V_153 ( V_37 , V_117 , V_141 , V_142 , V_143 ) ;
V_170 += V_143 ;
if ( V_170 == V_43 )
break;
V_141 += V_143 ;
if ( V_170 < V_43 ) {
V_162 += V_4 -> V_58 ;
V_142 = 0 ;
}
}
F_57 ( V_37 ) ;
V_164 -> V_180 = V_170 ;
return V_174 ;
}
static int F_74 ( struct V_36 * V_37 , const T_6 * V_141 , T_2 V_193 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
T_6 * V_148 = V_4 -> V_148 ;
int V_158 , V_38 , V_184 ;
V_184 = F_19 ( V_4 ) ? V_56 : V_66 ;
V_4 -> V_161 ( V_37 , V_184 , V_193 , V_37 -> V_118 ) ;
F_47 ( V_37 , V_193 , 0 ) ;
V_158 = V_4 -> V_109 ( V_37 , V_88 ) ;
if ( V_158 )
return V_158 ;
V_4 -> V_153 ( V_37 , V_117 , V_148 , 0 , V_37 -> V_118 ) ;
for ( V_38 = 0 ; V_38 < V_37 -> V_118 ; V_38 ++ )
if ( V_141 [ V_38 ] != 0xFF && V_141 [ V_38 ] != V_148 [ V_38 ] )
return - V_96 ;
return 0 ;
}
static int F_75 ( struct V_36 * V_37 , const T_6 * V_141 , T_2 V_1 , T_3 V_43 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
int V_174 = 0 ;
int V_143 , V_142 ;
V_142 = V_1 & ( V_4 -> V_58 - 1 ) ;
while ( V_43 != 0 ) {
V_143 = F_61 ( int , V_4 -> V_58 - V_142 , V_43 ) ;
V_4 -> V_161 ( V_37 , V_56 , V_1 , V_4 -> V_58 ) ;
F_47 ( V_37 , V_1 , 0 ) ;
V_174 = V_4 -> V_109 ( V_37 , V_88 ) ;
if ( V_174 )
return V_174 ;
F_47 ( V_37 , V_1 , 1 ) ;
V_4 -> V_153 ( V_37 , V_116 , V_4 -> V_194 , 0 , V_37 -> V_58 ) ;
if ( memcmp ( V_141 , V_4 -> V_194 + V_142 , V_143 ) )
return - V_96 ;
V_43 -= V_143 ;
V_141 += V_143 ;
V_1 += V_143 ;
V_142 = 0 ;
}
return 0 ;
}
static void F_76 ( struct V_36 * V_37 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
unsigned int V_85 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < 2000 ; V_38 ++ ) {
V_85 = V_4 -> V_76 ( V_4 -> V_61 + V_72 ) ;
if ( V_85 & V_84 )
break;
F_77 ( 10 ) ;
}
}
static int F_78 ( struct V_36 * V_37 , T_2 V_193 , T_3 V_43 ,
T_3 * V_179 , const T_6 * V_141 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
int V_142 , V_195 ;
int V_196 = 0 ;
int V_174 = 0 ;
if ( V_4 -> V_81 == V_135 )
return - V_197 ;
F_76 ( V_37 ) ;
F_65 ( L_23 , V_93 , ( unsigned int ) V_193 ,
( int ) V_43 ) ;
if ( F_66 ( F_79 ( V_193 ) || F_79 ( V_43 ) ) ) {
F_29 ( V_92 L_24 ,
V_93 ) ;
return - V_181 ;
}
V_142 = V_193 & ( V_37 -> V_58 - 1 ) ;
while ( V_196 < V_43 ) {
int V_143 = F_61 ( int , V_37 -> V_58 - V_142 , V_43 - V_196 ) ;
T_6 * V_198 = ( T_6 * ) V_141 ;
V_4 -> V_161 ( V_37 , V_53 , V_193 , V_143 ) ;
V_195 = V_143 < V_37 -> V_58 ;
if ( V_195 ) {
memset ( V_4 -> V_199 , 0xff , V_37 -> V_58 ) ;
memcpy ( V_4 -> V_199 + V_142 , V_141 , V_143 ) ;
V_198 = V_4 -> V_199 ;
}
V_4 -> V_200 ( V_37 , V_116 , V_198 , 0 , V_37 -> V_58 ) ;
V_4 -> V_200 ( V_37 , V_117 , V_201 , 0 , V_37 -> V_118 ) ;
V_4 -> V_161 ( V_37 , V_67 , V_193 , V_37 -> V_58 ) ;
F_76 ( V_37 ) ;
F_47 ( V_37 , V_193 , ! V_174 && ! V_195 ) ;
if ( F_18 ( V_4 ) ) {
F_80 ( V_4 ) ;
F_47 ( V_37 , V_193 + V_4 -> V_58 , ! V_174 && ! V_195 ) ;
}
if ( V_174 ) {
F_29 ( V_92 L_25 , V_93 , V_174 ) ;
break;
}
V_196 += V_143 ;
if ( V_196 == V_43 )
break;
V_142 = 0 ;
V_193 += V_143 ;
V_141 += V_143 ;
}
* V_179 = V_196 ;
return V_174 ;
}
static int F_81 ( struct V_36 * V_37 , T_6 * V_148 ,
const T_6 * V_141 , int V_142 , int V_143 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
struct V_144 * free ;
int V_202 = V_142 ;
int V_203 = V_142 + V_143 ;
int V_147 = 0 ;
unsigned int V_38 ;
free = V_4 -> V_149 -> V_150 ;
for ( V_38 = 0 ; V_38 < V_151 && free -> V_152 ; V_38 ++ , free ++ ) {
if ( V_202 >= V_147 )
V_202 += free -> V_41 - V_147 ;
if ( V_203 >= V_147 )
V_203 += free -> V_41 - V_147 ;
V_147 = free -> V_41 + free -> V_152 ;
}
free = V_4 -> V_149 -> V_150 ;
for ( V_38 = 0 ; V_38 < V_151 && free -> V_152 ; V_38 ++ , free ++ ) {
int V_154 = free -> V_41 + free -> V_152 ;
if ( free -> V_41 < V_203 && V_154 > V_202 ) {
int V_155 = F_60 ( int , free -> V_41 , V_202 ) ;
int V_156 = F_61 ( int , V_154 , V_203 ) ;
int V_157 = V_156 - V_155 ;
memcpy ( V_148 + V_155 , V_141 , V_157 ) ;
V_141 += V_157 ;
} else if ( V_142 == 0 )
break;
}
return 0 ;
}
static int F_82 ( struct V_36 * V_37 , T_2 V_193 ,
struct V_163 * V_164 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
int V_196 = 0 , V_142 , V_143 = 0 , V_195 = 0 ;
int V_204 = 0 , V_205 = 0 , V_206 = 0 , V_207 = 1 ;
int V_208 = 0 , V_172 , V_173 , V_118 ;
T_3 V_43 = V_164 -> V_43 ;
T_3 V_167 = V_164 -> V_167 ;
const T_6 * V_141 = V_164 -> V_168 ;
const T_6 * V_209 = V_164 -> V_169 ;
T_6 * V_169 ;
int V_174 = 0 , V_42 ;
F_65 ( L_23 , V_93 , ( unsigned int ) V_193 ,
( int ) V_43 ) ;
V_164 -> V_179 = 0 ;
V_164 -> V_180 = 0 ;
if ( F_66 ( F_79 ( V_193 ) || F_79 ( V_43 ) ) ) {
F_29 ( V_92 L_24 ,
V_93 ) ;
return - V_181 ;
}
if ( ! V_43 )
return 0 ;
if ( V_164 -> V_175 == V_176 )
V_118 = V_4 -> V_149 -> V_177 ;
else
V_118 = V_37 -> V_118 ;
V_172 = V_193 & ( V_37 -> V_118 - 1 ) ;
V_142 = V_193 & ( V_37 -> V_58 - 1 ) ;
while ( 1 ) {
if ( V_196 < V_43 ) {
T_6 * V_198 = ( T_6 * ) V_141 ;
V_143 = F_61 ( int , V_37 -> V_58 - V_142 , V_43 - V_196 ) ;
V_173 = F_61 ( int , V_118 - V_172 , V_167 - V_208 ) ;
F_28 () ;
V_4 -> V_161 ( V_37 , V_53 , V_193 , V_143 ) ;
V_195 = V_143 < V_37 -> V_58 ;
if ( V_195 ) {
memset ( V_4 -> V_199 , 0xff , V_37 -> V_58 ) ;
memcpy ( V_4 -> V_199 + V_142 , V_141 , V_143 ) ;
V_198 = V_4 -> V_199 ;
}
V_4 -> V_200 ( V_37 , V_116 , V_198 , 0 , V_37 -> V_58 ) ;
if ( V_209 ) {
V_169 = V_4 -> V_148 ;
memset ( V_169 , 0xff , V_37 -> V_118 ) ;
if ( V_164 -> V_175 == V_176 )
F_81 ( V_37 , V_169 , V_209 , V_172 , V_173 ) ;
else
memcpy ( V_169 + V_172 , V_209 , V_173 ) ;
V_208 += V_173 ;
V_209 += V_173 ;
V_172 = 0 ;
} else
V_169 = ( T_6 * ) V_201 ;
V_4 -> V_200 ( V_37 , V_117 , V_169 , 0 , V_37 -> V_118 ) ;
} else
F_21 ( V_4 ) ;
if ( ! F_18 ( V_4 ) && ! F_19 ( V_4 ) && ! V_207 ) {
F_68 ( V_4 ) ;
V_174 = V_4 -> V_109 ( V_37 , V_210 ) ;
F_47 ( V_37 , V_204 , ! V_174 && ! V_206 ) ;
if ( V_174 ) {
V_196 -= V_205 ;
F_29 ( V_92 L_25 ,
V_93 , V_174 ) ;
break;
}
if ( V_196 == V_43 ) {
V_174 = F_75 ( V_37 , V_141 - V_43 , V_193 - V_43 , V_43 ) ;
if ( V_174 )
F_29 ( V_92 L_26 ,
V_93 , V_174 ) ;
break;
}
F_21 ( V_4 ) ;
}
V_4 -> V_211 = 0 ;
V_42 = V_67 ;
if ( F_83 ( V_4 ) &&
F_24 ( F_11 ( V_4 , V_193 ) != 0 ) &&
F_19 ( V_4 ) &&
( ( V_196 + V_143 ) < V_43 ) ) {
V_42 = V_212 ;
V_4 -> V_211 = 1 ;
}
V_4 -> V_161 ( V_37 , V_42 , V_193 , V_37 -> V_58 ) ;
if ( F_18 ( V_4 ) || F_19 ( V_4 ) ) {
V_174 = V_4 -> V_109 ( V_37 , V_210 ) ;
F_47 ( V_37 , V_193 , ! V_174 && ! V_195 ) ;
if ( V_174 ) {
F_29 ( V_92 L_25 ,
V_93 , V_174 ) ;
break;
}
V_174 = F_75 ( V_37 , V_141 , V_193 , V_143 ) ;
if ( V_174 ) {
F_29 ( V_92 L_26 ,
V_93 , V_174 ) ;
break;
}
V_196 += V_143 ;
if ( V_196 == V_43 )
break;
} else
V_196 += V_143 ;
V_142 = 0 ;
V_206 = V_195 ;
V_204 = V_193 ;
V_205 = V_143 ;
V_193 += V_143 ;
V_141 += V_143 ;
V_207 = 0 ;
}
if ( V_196 != V_43 )
F_48 ( V_37 , 0 , - 1 ) ;
V_164 -> V_179 = V_196 ;
V_164 -> V_180 = V_208 ;
return V_174 ;
}
static int F_84 ( struct V_36 * V_37 , T_2 V_193 ,
struct V_163 * V_164 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
int V_142 , V_174 = 0 , V_118 ;
int V_196 = 0 , V_213 ;
T_6 * V_169 ;
T_3 V_43 = V_164 -> V_167 ;
const T_6 * V_141 = V_164 -> V_169 ;
unsigned int V_175 = V_164 -> V_175 ;
V_193 += V_164 -> V_185 ;
F_65 ( L_23 , V_93 , ( unsigned int ) V_193 ,
( int ) V_43 ) ;
V_164 -> V_180 = 0 ;
if ( V_175 == V_176 )
V_118 = V_4 -> V_149 -> V_177 ;
else
V_118 = V_37 -> V_118 ;
V_142 = V_193 & ( V_37 -> V_118 - 1 ) ;
if ( F_66 ( V_142 >= V_118 ) ) {
F_29 ( V_92 L_27 ,
V_93 ) ;
return - V_181 ;
}
if ( F_66 ( V_142 + V_43 > V_118 ) ) {
F_29 ( V_92 L_28 ,
V_93 ) ;
return - V_181 ;
}
if ( F_66 ( V_193 >= V_37 -> V_178 ||
V_142 + V_43 > ( ( V_37 -> V_178 >> V_4 -> V_57 ) -
( V_193 >> V_4 -> V_57 ) ) * V_118 ) ) {
F_29 ( V_92 L_29 ,
V_93 ) ;
return - V_181 ;
}
V_169 = V_4 -> V_148 ;
V_213 = F_19 ( V_4 ) ? V_67 : V_214 ;
while ( V_196 < V_43 ) {
int V_143 = F_61 ( int , V_118 , V_43 - V_196 ) ;
F_28 () ;
V_4 -> V_161 ( V_37 , V_53 , V_193 , V_37 -> V_118 ) ;
memset ( V_169 , 0xff , V_37 -> V_118 ) ;
if ( V_175 == V_176 )
F_81 ( V_37 , V_169 , V_141 , V_142 , V_143 ) ;
else
memcpy ( V_169 + V_142 , V_141 , V_143 ) ;
V_4 -> V_200 ( V_37 , V_117 , V_169 , 0 , V_37 -> V_118 ) ;
if ( F_19 ( V_4 ) ) {
memset ( V_4 -> V_199 , 0xff , V_37 -> V_58 ) ;
V_4 -> V_200 ( V_37 , V_116 ,
V_4 -> V_199 , 0 , V_37 -> V_58 ) ;
}
V_4 -> V_161 ( V_37 , V_213 , V_193 , V_37 -> V_118 ) ;
F_47 ( V_37 , V_193 , 0 ) ;
if ( F_18 ( V_4 ) ) {
F_80 ( V_4 ) ;
F_47 ( V_37 , V_193 + V_4 -> V_58 , 0 ) ;
}
V_174 = V_4 -> V_109 ( V_37 , V_210 ) ;
if ( V_174 ) {
F_29 ( V_92 L_25 , V_93 , V_174 ) ;
break;
}
V_174 = F_74 ( V_37 , V_169 , V_193 ) ;
if ( V_174 ) {
F_29 ( V_92 L_26 ,
V_93 , V_174 ) ;
break;
}
V_196 += V_143 ;
if ( V_196 == V_43 )
break;
V_193 += V_37 -> V_58 ;
V_141 += V_143 ;
V_142 = 0 ;
}
V_164 -> V_180 = V_196 ;
return V_174 ;
}
static int F_85 ( struct V_36 * V_37 , T_2 V_193 , T_3 V_43 ,
T_3 * V_179 , const T_6 * V_141 )
{
struct V_163 V_164 = {
. V_43 = V_43 ,
. V_167 = 0 ,
. V_168 = ( T_6 * ) V_141 ,
. V_169 = NULL ,
} ;
int V_174 ;
F_49 ( V_37 , V_210 ) ;
V_174 = F_82 ( V_37 , V_193 , & V_164 ) ;
F_57 ( V_37 ) ;
* V_179 = V_164 . V_179 ;
return V_174 ;
}
static int F_86 ( struct V_36 * V_37 , T_2 V_193 ,
struct V_163 * V_164 )
{
int V_174 ;
switch ( V_164 -> V_175 ) {
case V_186 :
case V_176 :
break;
case V_187 :
default:
return - V_181 ;
}
F_49 ( V_37 , V_210 ) ;
if ( V_164 -> V_168 )
V_174 = F_82 ( V_37 , V_193 , V_164 ) ;
else
V_174 = F_84 ( V_37 , V_193 , V_164 ) ;
F_57 ( V_37 ) ;
return V_174 ;
}
static int F_87 ( struct V_36 * V_37 , T_2 V_31 , int V_215 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
struct V_216 * V_217 = V_4 -> V_217 ;
return V_217 -> V_218 ( V_37 , V_31 , V_215 ) ;
}
static int F_88 ( struct V_36 * V_37 ,
struct V_219 * V_220 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
T_2 V_1 = V_220 -> V_1 ;
int V_43 = V_220 -> V_43 ;
unsigned int V_221 = ( 1 << V_4 -> V_30 ) ;
int V_174 = 0 ;
while ( V_43 ) {
V_4 -> V_161 ( V_37 , V_52 , V_1 , V_221 ) ;
V_174 = V_4 -> V_109 ( V_37 , V_222 ) ;
if ( V_174 ) {
F_29 ( V_92 L_30 ,
V_93 , F_11 ( V_4 , V_1 ) ) ;
V_220 -> V_81 = V_223 ;
V_220 -> V_224 = V_1 ;
return - 1 ;
}
V_43 -= V_221 ;
V_1 += V_221 ;
}
return 0 ;
}
static int F_89 ( struct V_36 * V_37 ,
struct V_219 * V_220 ,
unsigned int V_221 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
T_2 V_1 = V_220 -> V_1 ;
int V_43 = V_220 -> V_43 ;
int V_225 = 0 ;
int V_174 = 0 ;
int V_226 = 0 ;
V_220 -> V_81 = V_227 ;
if ( F_10 ( V_4 ) ) {
T_2 V_228 = V_4 -> V_183 >> 1 ;
if ( V_1 < V_228 && ( V_1 + V_43 ) > V_228 )
V_226 = V_228 >> V_4 -> V_30 ;
}
while ( V_43 ) {
if ( F_87 ( V_37 , V_1 , 0 ) ) {
F_29 ( V_229 L_31
L_32 ,
V_93 , ( unsigned long long ) V_1 ) ;
V_220 -> V_81 = V_223 ;
return - V_99 ;
}
V_43 -= V_221 ;
V_1 += V_221 ;
}
V_43 = V_220 -> V_43 ;
V_1 = V_220 -> V_1 ;
while ( V_43 ) {
struct V_219 V_230 = * V_220 ;
int V_231 = V_232 ;
V_230 . V_1 = V_1 ;
V_230 . V_43 = 0 ;
if ( V_226 ) {
int V_233 = ( V_1 >> V_4 -> V_30 ) ;
if ( V_233 < V_226 ) {
V_231 = F_90 ( V_231 ,
( V_226 - V_233 ) ) ;
}
}
V_225 = 0 ;
while ( V_43 > V_221 && V_225 < ( V_231 - 1 ) ) {
V_4 -> V_161 ( V_37 , V_51 ,
V_1 , V_221 ) ;
F_48 ( V_37 , V_1 , V_221 ) ;
V_174 = V_4 -> V_109 ( V_37 , V_89 ) ;
if ( V_174 ) {
F_29 ( V_92 L_33
L_34 , V_93 ,
F_11 ( V_4 , V_1 ) ) ;
V_220 -> V_81 = V_223 ;
V_220 -> V_224 = V_234 ;
return - V_99 ;
}
V_43 -= V_221 ;
V_1 += V_221 ;
V_225 ++ ;
}
F_28 () ;
V_4 -> V_161 ( V_37 , V_50 , V_1 , V_221 ) ;
F_48 ( V_37 , V_1 , V_221 ) ;
V_174 = V_4 -> V_109 ( V_37 , V_235 ) ;
if ( V_174 ) {
F_29 ( V_92 L_35 ,
V_93 , F_11 ( V_4 , V_1 ) ) ;
V_220 -> V_81 = V_223 ;
V_220 -> V_224 = V_234 ;
return - V_99 ;
}
V_43 -= V_221 ;
V_1 += V_221 ;
V_225 ++ ;
V_230 . V_43 = V_225 * V_221 ;
if ( F_88 ( V_37 , & V_230 ) ) {
V_220 -> V_81 = V_230 . V_81 ;
V_220 -> V_224 = V_230 . V_224 ;
return - V_99 ;
}
}
return 0 ;
}
static int F_91 ( struct V_36 * V_37 ,
struct V_219 * V_220 ,
struct V_236 * V_237 ,
unsigned int V_221 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
T_2 V_1 = V_220 -> V_1 ;
int V_43 = V_220 -> V_43 ;
T_2 V_238 = 0 ;
int V_174 = 0 ;
if ( V_237 ) {
V_238 = V_237 -> V_41 + V_237 -> V_160 * V_237 -> V_239 ;
}
V_220 -> V_81 = V_227 ;
while ( V_43 ) {
F_28 () ;
if ( F_87 ( V_37 , V_1 , 0 ) ) {
F_29 ( V_229 L_31
L_32 ,
V_93 , ( unsigned long long ) V_1 ) ;
V_220 -> V_81 = V_223 ;
return - V_99 ;
}
V_4 -> V_161 ( V_37 , V_50 , V_1 , V_221 ) ;
F_48 ( V_37 , V_1 , V_221 ) ;
V_174 = V_4 -> V_109 ( V_37 , V_235 ) ;
if ( V_174 ) {
F_29 ( V_92 L_35 ,
V_93 , F_11 ( V_4 , V_1 ) ) ;
V_220 -> V_81 = V_223 ;
V_220 -> V_224 = V_1 ;
return - V_99 ;
}
V_43 -= V_221 ;
V_1 += V_221 ;
if ( V_237 && V_1 == V_238 ) {
if ( ! V_43 )
break;
V_237 ++ ;
V_221 = V_237 -> V_160 ;
V_238 = V_237 -> V_41 + V_237 -> V_160 * V_237 -> V_239 ;
if ( V_43 & ( V_221 - 1 ) ) {
F_29 ( V_92 L_36 ,
V_93 ) ;
return - V_99 ;
}
}
}
return 0 ;
}
static int F_92 ( struct V_36 * V_37 , struct V_219 * V_220 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
unsigned int V_221 ;
T_2 V_1 = V_220 -> V_1 ;
T_2 V_43 = V_220 -> V_43 ;
int V_174 = 0 ;
struct V_236 * V_237 = NULL ;
T_2 V_240 = 0 ;
F_65 ( L_37 , V_93 ,
( unsigned long long ) V_220 -> V_1 ,
( unsigned long long ) V_220 -> V_43 ) ;
if ( F_12 ( V_4 ) ) {
int V_38 = F_16 ( V_37 , V_1 ) ;
V_237 = & V_37 -> V_40 [ V_38 ] ;
V_221 = V_237 -> V_160 ;
V_240 = V_237 -> V_41 ;
} else
V_221 = 1 << V_4 -> V_30 ;
if ( F_66 ( ( V_1 - V_240 ) & ( V_221 - 1 ) ) ) {
F_29 ( V_92 L_36 , V_93 ) ;
return - V_181 ;
}
if ( F_66 ( V_43 & ( V_221 - 1 ) ) ) {
F_29 ( V_92 L_38 , V_93 ) ;
return - V_181 ;
}
F_49 ( V_37 , V_235 ) ;
if ( F_19 ( V_4 ) || V_237 ||
V_220 -> V_43 < V_241 * V_221 ) {
V_174 = F_91 ( V_37 , V_220 ,
V_237 , V_221 ) ;
} else {
V_174 = F_89 ( V_37 , V_220 , V_221 ) ;
}
F_57 ( V_37 ) ;
if ( ! V_174 ) {
V_220 -> V_81 = V_242 ;
F_93 ( V_220 ) ;
}
return V_174 ;
}
static void F_94 ( struct V_36 * V_37 )
{
F_65 ( L_39 , V_93 ) ;
F_49 ( V_37 , V_243 ) ;
F_57 ( V_37 ) ;
}
static int F_95 ( struct V_36 * V_37 , T_2 V_31 )
{
int V_174 ;
if ( V_31 > V_37 -> V_178 )
return - V_181 ;
F_49 ( V_37 , V_88 ) ;
V_174 = F_87 ( V_37 , V_31 , 0 ) ;
F_57 ( V_37 ) ;
return V_174 ;
}
static int F_96 ( struct V_36 * V_37 , T_2 V_31 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
struct V_216 * V_217 = V_4 -> V_217 ;
T_6 V_141 [ 2 ] = { 0 , 0 } ;
struct V_163 V_164 = {
. V_175 = V_186 ,
. V_167 = 2 ,
. V_169 = V_141 ,
. V_185 = 0 ,
} ;
int V_5 ;
V_5 = F_11 ( V_4 , V_31 ) ;
if ( V_217 -> V_244 )
V_217 -> V_244 [ V_5 >> 2 ] |= 0x01 << ( ( V_5 & 0x03 ) << 1 ) ;
V_31 += V_37 -> V_118 + ( V_217 -> V_245 & ~ 0x01 ) ;
return F_84 ( V_37 , V_31 , & V_164 ) ;
}
static int F_97 ( struct V_36 * V_37 , T_2 V_31 )
{
int V_174 ;
V_174 = F_95 ( V_37 , V_31 ) ;
if ( V_174 ) {
if ( V_174 > 0 )
return 0 ;
return V_174 ;
}
F_49 ( V_37 , V_210 ) ;
V_174 = F_98 ( V_37 , V_31 ) ;
F_57 ( V_37 ) ;
return V_174 ;
}
static int F_99 ( struct V_36 * V_37 , T_2 V_31 , T_3 V_43 , int V_42 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
int V_246 , V_247 , V_5 , V_2 , V_158 ;
int V_248 ;
V_246 = F_11 ( V_4 , V_31 ) ;
V_247 = F_11 ( V_4 , V_31 + V_43 ) - 1 ;
if ( V_42 == V_46 )
V_248 = V_249 ;
else
V_248 = V_250 ;
if ( V_4 -> V_251 & V_252 ) {
V_4 -> V_60 ( V_246 , V_4 -> V_61 + V_253 ) ;
V_4 -> V_60 ( V_247 , V_4 -> V_61 + V_254 ) ;
V_4 -> V_161 ( V_37 , V_42 , 0 , 0 ) ;
V_4 -> V_109 ( V_37 , V_255 ) ;
while ( V_4 -> V_76 ( V_4 -> V_61 + V_90 )
& V_256 )
continue;
V_158 = V_4 -> V_76 ( V_4 -> V_61 + V_257 ) ;
if ( ! ( V_158 & V_248 ) )
F_29 ( V_92 L_40 ,
V_93 , V_158 ) ;
return 0 ;
}
for ( V_5 = V_246 ; V_5 < V_247 + 1 ; V_5 ++ ) {
V_2 = F_5 ( V_4 , V_5 ) ;
V_4 -> V_60 ( V_2 , V_4 -> V_61 + V_63 ) ;
V_2 = F_6 ( V_4 , V_5 ) ;
V_4 -> V_60 ( V_2 , V_4 -> V_61 + V_62 ) ;
V_4 -> V_60 ( V_5 , V_4 -> V_61 + V_253 ) ;
V_4 -> V_161 ( V_37 , V_42 , 0 , 0 ) ;
V_4 -> V_109 ( V_37 , V_255 ) ;
while ( V_4 -> V_76 ( V_4 -> V_61 + V_90 )
& V_256 )
continue;
V_158 = V_4 -> V_76 ( V_4 -> V_61 + V_257 ) ;
if ( ! ( V_158 & V_248 ) )
F_29 ( V_92 L_41 ,
V_93 , V_5 , V_158 ) ;
}
return 0 ;
}
static int F_100 ( struct V_36 * V_37 , T_2 V_31 , T_7 V_43 )
{
int V_174 ;
F_49 ( V_37 , V_255 ) ;
V_174 = F_99 ( V_37 , V_31 , V_43 , V_46 ) ;
F_57 ( V_37 ) ;
return V_174 ;
}
static int F_101 ( struct V_36 * V_37 , T_2 V_31 , T_7 V_43 )
{
int V_174 ;
F_49 ( V_37 , V_255 ) ;
V_174 = F_99 ( V_37 , V_31 , V_43 , V_45 ) ;
F_57 ( V_37 ) ;
return V_174 ;
}
static int F_102 ( struct V_3 * V_4 )
{
unsigned int V_2 , V_5 , V_158 ;
unsigned int V_247 ;
V_247 = V_4 -> V_183 >> V_4 -> V_30 ;
for ( V_5 = 0 ; V_5 < V_247 ; V_5 ++ ) {
V_2 = F_5 ( V_4 , V_5 ) ;
V_4 -> V_60 ( V_2 , V_4 -> V_61 + V_63 ) ;
V_2 = F_6 ( V_4 , V_5 ) ;
V_4 -> V_60 ( V_2 , V_4 -> V_61 + V_62 ) ;
V_4 -> V_60 ( V_5 , V_4 -> V_61 + V_253 ) ;
V_158 = V_4 -> V_76 ( V_4 -> V_61 + V_257 ) ;
if ( ! ( V_158 & V_250 ) ) {
F_29 ( V_92 L_41 ,
V_93 , V_5 , V_158 ) ;
return 0 ;
}
}
return 1 ;
}
static void F_103 ( struct V_36 * V_37 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
T_2 V_31 = 0 ;
T_2 V_43 = V_37 -> V_178 ;
if ( V_4 -> V_251 & V_258 ) {
V_4 -> V_60 ( 0 , V_4 -> V_61 + V_253 ) ;
V_4 -> V_161 ( V_37 , V_48 , 0 , 0 ) ;
V_4 -> V_109 ( V_37 , V_255 ) ;
while ( V_4 -> V_76 ( V_4 -> V_61 + V_90 )
& V_256 )
continue;
if ( V_4 -> V_251 & V_259 )
return;
if ( F_102 ( V_4 ) )
return;
if ( F_10 ( V_4 ) && ! F_12 ( V_4 ) ) {
V_31 = V_4 -> V_183 >> 1 ;
V_43 = V_4 -> V_183 >> 1 ;
}
}
F_99 ( V_37 , V_31 , V_43 , V_45 ) ;
}
static int F_104 ( struct V_36 * V_37 , int V_42 , T_2 V_1 ,
T_3 V_43 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
int V_2 , V_5 , V_9 ;
switch ( V_42 ) {
case V_54 :
V_5 = ( int ) ( V_1 >> V_4 -> V_30 ) ;
V_9 = - 1 ;
break;
default:
V_5 = ( int ) ( V_1 >> V_4 -> V_30 ) ;
V_9 = ( int ) ( V_1 >> V_4 -> V_57 ) ;
if ( F_18 ( V_4 ) ) {
V_5 &= ~ 1 ;
if ( V_1 & V_4 -> V_58 )
V_5 ++ ;
V_9 >>= 1 ;
}
V_9 &= V_4 -> V_59 ;
break;
}
if ( V_5 != - 1 ) {
V_2 = F_5 ( V_4 , V_5 ) ;
V_4 -> V_60 ( V_2 , V_4 -> V_61 +
V_63 ) ;
}
if ( V_9 != - 1 ) {
int V_17 = 4 , V_18 = 4 ;
int V_64 ;
switch ( V_42 ) {
default:
if ( F_18 ( V_4 ) && V_42 == V_67 )
V_42 = V_68 ;
V_64 = F_22 ( V_4 ) ;
break;
}
V_2 = F_7 ( V_9 , V_17 ) ;
V_4 -> V_60 ( V_2 , V_4 -> V_61 +
V_69 ) ;
V_2 = F_8 ( V_64 , V_17 , V_18 ) ;
V_4 -> V_60 ( V_2 , V_4 -> V_61 + V_70 ) ;
}
V_4 -> V_60 ( V_71 , V_4 -> V_61 + V_72 ) ;
V_4 -> V_60 ( V_42 , V_4 -> V_61 + V_73 ) ;
return 0 ;
}
static int F_105 ( struct V_36 * V_37 , T_2 V_193 ,
struct V_163 * V_164 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
int V_142 , V_174 = 0 , V_118 ;
int V_196 = 0 ;
T_6 * V_169 ;
T_3 V_43 = V_164 -> V_167 ;
const T_6 * V_141 = V_164 -> V_169 ;
int V_5 , V_2 , V_158 ;
V_193 += V_164 -> V_185 ;
V_164 -> V_180 = 0 ;
V_118 = V_37 -> V_118 ;
V_142 = V_193 & ( V_37 -> V_118 - 1 ) ;
V_169 = V_4 -> V_148 ;
while ( V_196 < V_43 ) {
int V_143 = F_61 ( int , V_118 , V_43 - V_196 ) ;
F_28 () ;
V_5 = ( int ) ( V_193 >> V_4 -> V_30 ) ;
V_2 = F_5 ( V_4 , V_5 ) ;
V_4 -> V_60 ( V_2 , V_4 -> V_61 +
V_63 ) ;
V_2 = F_6 ( V_4 , V_5 ) ;
V_4 -> V_60 ( V_2 , V_4 -> V_61 +
V_62 ) ;
F_21 ( V_4 ) ;
V_4 -> V_161 ( V_37 , V_54 , 0 , 0 ) ;
V_4 -> V_109 ( V_37 , V_260 ) ;
memcpy ( V_169 + V_142 , V_141 , V_143 ) ;
V_4 -> V_200 ( V_37 , V_117 ,
V_169 , 0 , V_37 -> V_118 ) ;
F_104 ( V_37 , V_214 , V_193 , V_37 -> V_118 ) ;
F_47 ( V_37 , V_193 , 0 ) ;
if ( F_18 ( V_4 ) ) {
F_80 ( V_4 ) ;
F_47 ( V_37 , V_193 + V_4 -> V_58 , 0 ) ;
}
V_174 = V_4 -> V_109 ( V_37 , V_210 ) ;
if ( V_174 ) {
F_29 ( V_92 L_25 , V_93 , V_174 ) ;
break;
}
V_4 -> V_161 ( V_37 , V_261 , 0 , 0 ) ;
V_4 -> V_109 ( V_37 , V_262 ) ;
V_158 = V_4 -> V_76 ( V_4 -> V_61 + V_90 ) ;
V_158 &= 0x60 ;
if ( V_158 == 0x60 ) {
F_29 ( V_97 L_42 ) ;
F_29 ( V_97 L_43 ) ;
F_29 ( V_97 L_44 ) ;
} else if ( V_158 == 0x20 ) {
F_29 ( V_97 L_42 ) ;
F_29 ( V_97 L_43 ) ;
F_29 ( V_97 L_45 ) ;
} else if ( V_158 == 0x40 ) {
F_29 ( V_97 L_42 ) ;
F_29 ( V_97 L_46 ) ;
F_29 ( V_97 L_44 ) ;
} else {
F_29 ( V_97 L_47 ) ;
}
V_196 += V_143 ;
if ( V_196 == V_43 )
break;
V_193 += V_37 -> V_58 ;
V_141 += V_143 ;
V_142 = 0 ;
}
V_164 -> V_180 = V_196 ;
return V_174 ;
}
static int F_106 ( struct V_36 * V_37 , T_2 V_162 , T_3 V_43 ,
T_3 * V_179 , T_6 * V_141 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
struct V_163 V_164 = {
. V_43 = V_43 ,
. V_167 = 0 ,
. V_168 = V_141 ,
. V_169 = NULL ,
} ;
int V_174 ;
V_4 -> V_161 ( V_37 , V_54 , 0 , 0 ) ;
V_4 -> V_109 ( V_37 , V_260 ) ;
V_174 = F_19 ( V_4 ) ?
F_64 ( V_37 , V_162 , & V_164 ) :
F_67 ( V_37 , V_162 , & V_164 ) ;
V_4 -> V_161 ( V_37 , V_261 , 0 , 0 ) ;
V_4 -> V_109 ( V_37 , V_262 ) ;
return V_174 ;
}
static int F_107 ( struct V_36 * V_37 , T_2 V_193 , T_3 V_43 ,
T_3 * V_179 , T_6 * V_141 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
unsigned char * V_263 = V_141 ;
int V_174 ;
struct V_163 V_164 ;
if ( V_43 < V_37 -> V_58 ) {
memcpy ( V_4 -> V_199 , V_141 , V_43 ) ;
memset ( V_4 -> V_199 + V_43 , 0xff , V_37 -> V_58 - V_43 ) ;
V_263 = V_4 -> V_199 ;
V_43 = V_37 -> V_58 ;
}
V_4 -> V_161 ( V_37 , V_54 , 0 , 0 ) ;
V_4 -> V_109 ( V_37 , V_260 ) ;
V_164 . V_43 = V_43 ;
V_164 . V_167 = 0 ;
V_164 . V_168 = V_263 ;
V_164 . V_169 = NULL ;
V_174 = F_82 ( V_37 , V_193 , & V_164 ) ;
* V_179 = V_164 . V_179 ;
V_4 -> V_161 ( V_37 , V_261 , 0 , 0 ) ;
V_4 -> V_109 ( V_37 , V_262 ) ;
return V_174 ;
}
static int F_108 ( struct V_36 * V_37 , T_2 V_162 , T_3 V_43 ,
T_3 * V_179 , T_6 * V_141 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
struct V_163 V_164 ;
int V_174 ;
if ( F_12 ( V_4 ) ) {
V_4 -> V_161 ( V_37 , V_54 , 0 , 0 ) ;
V_4 -> V_109 ( V_37 , V_260 ) ;
V_164 . V_43 = V_37 -> V_58 ;
V_164 . V_167 = 0 ;
V_164 . V_168 = V_141 ;
V_164 . V_169 = NULL ;
V_174 = F_82 ( V_37 , V_37 -> V_58 * 49 , & V_164 ) ;
* V_179 = V_164 . V_179 ;
V_4 -> V_161 ( V_37 , V_261 , 0 , 0 ) ;
V_4 -> V_109 ( V_37 , V_262 ) ;
} else {
V_164 . V_175 = V_186 ;
V_164 . V_167 = V_43 ;
V_164 . V_169 = V_141 ;
V_164 . V_185 = 0 ;
V_174 = F_105 ( V_37 , V_162 , & V_164 ) ;
* V_179 = V_164 . V_180 ;
}
return V_174 ;
}
static int F_109 ( struct V_36 * V_37 , T_2 V_162 , T_3 V_43 ,
T_3 * V_179 , T_6 * V_141 ,
T_8 V_264 , int V_175 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
int V_265 ;
int V_33 ;
int V_174 = 0 ;
* V_179 = 0 ;
V_33 = F_15 ( V_4 -> V_266 ) ;
if ( V_33 < V_267 )
V_265 = 20 ;
else
V_265 = 50 ;
if ( V_175 == V_268 ) {
V_162 += V_37 -> V_58 * V_265 ;
V_265 = V_269 - V_265 ;
}
if ( V_175 == V_270 ) {
if ( V_37 -> V_58 * V_265 < V_162 + V_43 )
return 0 ;
} else {
if ( V_37 -> V_58 * V_265 < V_43 )
return 0 ;
}
F_49 ( V_37 , V_260 ) ;
while ( V_43 > 0 && V_265 > 0 ) {
if ( ! V_264 ) {
struct V_271 * V_272 ;
V_43 -= sizeof( struct V_271 ) ;
if ( V_43 <= 0 ) {
V_174 = - V_273 ;
break;
}
V_272 = (struct V_271 * ) V_141 ;
V_272 -> V_246 = V_162 ;
V_272 -> V_152 = V_37 -> V_58 ;
V_272 -> V_274 = 0 ;
V_162 += V_37 -> V_58 ;
V_141 += sizeof( struct V_271 ) ;
* V_179 += sizeof( struct V_271 ) ;
} else {
T_3 V_275 ;
V_174 = V_264 ( V_37 , V_162 , V_43 , & V_275 , V_141 ) ;
V_141 += V_275 ;
V_43 -= V_275 ;
* V_179 += V_275 ;
if ( V_174 )
break;
}
V_265 -- ;
}
F_57 ( V_37 ) ;
return V_174 ;
}
static int F_110 ( struct V_36 * V_37 ,
struct V_271 * V_141 , T_3 V_43 )
{
T_3 V_179 ;
int V_174 ;
V_174 = F_109 ( V_37 , 0 , V_43 , & V_179 , ( T_6 * ) V_141 , NULL , V_268 ) ;
return V_174 ? : V_179 ;
}
static int F_111 ( struct V_36 * V_37 , T_2 V_162 ,
T_3 V_43 , T_3 * V_179 , T_6 * V_141 )
{
return F_109 ( V_37 , V_162 , V_43 , V_179 , V_141 , F_106 , V_268 ) ;
}
static int F_112 ( struct V_36 * V_37 ,
struct V_271 * V_141 , T_3 V_43 )
{
T_3 V_179 ;
int V_174 ;
V_174 = F_109 ( V_37 , 0 , V_43 , & V_179 , ( T_6 * ) V_141 , NULL , V_270 ) ;
return V_174 ? : V_179 ;
}
static int F_113 ( struct V_36 * V_37 , T_2 V_162 ,
T_3 V_43 , T_3 * V_179 , T_6 * V_141 )
{
return F_109 ( V_37 , V_162 , V_43 , V_179 , V_141 , F_106 , V_270 ) ;
}
static int F_114 ( struct V_36 * V_37 , T_2 V_162 ,
T_3 V_43 , T_3 * V_179 , T_6 * V_141 )
{
return F_109 ( V_37 , V_162 , V_43 , V_179 , V_141 , F_107 , V_270 ) ;
}
static int F_115 ( struct V_36 * V_37 , T_2 V_162 ,
T_3 V_43 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
T_6 * V_141 = F_12 ( V_4 ) ? V_4 -> V_199 : V_4 -> V_148 ;
T_3 V_179 ;
int V_174 ;
unsigned int V_276 = V_277 ;
memset ( V_141 , 0xff , F_12 ( V_4 ) ? V_4 -> V_58
: V_37 -> V_118 ) ;
V_162 = 0 ;
V_43 = F_12 ( V_4 ) ? V_37 -> V_58 : 16 ;
if ( F_12 ( V_4 ) )
V_276 = V_278 ;
if ( V_279 == 1 )
V_141 [ V_276 ] = 0xFC ;
else if ( V_279 == 2 )
V_141 [ V_276 ] = 0xF3 ;
else if ( V_279 == 3 )
V_141 [ V_276 ] = 0xF0 ;
else if ( V_279 != 0 )
F_29 ( V_97 L_48 ) ;
V_174 = F_109 ( V_37 , V_162 , V_43 , & V_179 , V_141 , F_108 , V_270 ) ;
return V_174 ? : V_179 ;
}
static void F_116 ( struct V_36 * V_37 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
unsigned int V_33 , V_280 , V_281 ;
V_33 = F_15 ( V_4 -> V_266 ) ;
V_280 = V_4 -> V_282 >> V_283 ;
V_281 = V_4 -> V_76 ( V_4 -> V_61 + V_284 ) >> 8 ;
switch ( V_33 ) {
case V_285 :
if ( F_10 ( V_4 ) )
V_4 -> V_251 |= V_286 ;
else if ( V_281 == 1 ) {
V_4 -> V_251 |= V_287 ;
V_4 -> V_251 |= V_288 ;
if ( ( V_4 -> V_282 & 0xf ) == 0xe )
V_4 -> V_251 |= V_289 ;
}
case V_290 :
if ( ! F_10 ( V_4 ) )
V_4 -> V_251 |= V_286 ;
V_4 -> V_251 |= V_258 ;
case V_291 :
if ( V_280 )
V_4 -> V_251 |= V_258 ;
break;
default:
if ( ! V_280 )
V_4 -> V_251 |= V_252 ;
break;
}
if ( F_117 ( V_4 ) )
V_4 -> V_251 |= V_287 ;
if ( F_19 ( V_4 ) )
V_4 -> V_251 &= ~ V_286 ;
if ( F_12 ( V_4 ) ) {
V_4 -> V_251 &= ~ V_252 ;
V_4 -> V_251 |= V_258 ;
}
if ( V_4 -> V_251 & V_252 )
F_29 ( V_97 L_49 ) ;
if ( V_4 -> V_251 & V_258 )
F_29 ( V_97 L_50 ) ;
if ( V_4 -> V_251 & V_286 )
F_29 ( V_97 L_51 ) ;
if ( V_4 -> V_251 & V_287 )
F_29 ( V_97 L_52 ) ;
if ( V_4 -> V_251 & V_288 )
F_29 ( V_97 L_53 ) ;
}
static void F_118 ( int V_292 , int V_293 )
{
int V_294 , V_295 , V_296 , V_33 , V_297 ;
V_294 = V_292 & V_298 ;
V_295 = V_292 & V_299 ;
V_296 = V_292 & V_300 ;
V_33 = F_15 ( V_292 ) ;
V_297 = V_292 & V_301 ;
F_29 ( V_110 L_54 ,
V_295 ? L_55 : L_56 ,
V_297 ? L_57 : L_55 ,
V_296 ? L_58 : L_55 ,
( 16 << V_33 ) ,
V_294 ? L_59 : L_60 ,
V_292 ) ;
F_29 ( V_110 L_61 , V_293 ) ;
}
static int F_119 ( int V_302 )
{
int V_178 = F_120 ( V_303 ) ;
char * V_304 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_178 ; V_38 ++ )
if ( V_302 == V_303 [ V_38 ] . V_305 )
break;
if ( V_38 < V_178 )
V_304 = V_303 [ V_38 ] . V_304 ;
else
V_304 = L_62 ;
F_29 ( V_97 L_63 , V_304 , V_302 ) ;
return ( V_38 == V_178 ) ;
}
static int F_121 ( struct V_36 * V_37 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
unsigned V_28 , V_306 ;
int V_174 , V_111 , V_274 ;
V_111 = V_4 -> V_76 ( V_4 -> V_61 + V_113 ) ;
V_4 -> V_60 ( ( V_111 | 0x0100 ) , V_4 -> V_61 + V_113 ) ;
for ( V_28 = 0 ; V_28 < V_4 -> V_307 ; V_28 ++ ) {
V_4 -> V_161 ( V_37 , V_49 , V_28 , 0 ) ;
V_4 -> V_109 ( V_37 , V_243 ) ;
V_4 -> V_161 ( V_37 , V_55 , V_28 , 0 ) ;
V_174 = V_4 -> V_109 ( V_37 , V_88 ) ;
V_306 = V_4 -> V_76 ( V_4 -> V_61 + V_116 ) ;
if ( ( V_306 >> V_308 ) == 3 )
V_274 = 0 ;
else
V_274 = 1 ;
V_4 -> V_26 [ V_28 ] = V_306 & V_309 ;
V_4 -> V_161 ( V_37 , V_261 , 0 , 0 ) ;
V_174 = V_4 -> V_109 ( V_37 , V_262 ) ;
F_29 ( V_110 L_64 , V_28 ,
V_4 -> V_26 [ V_28 ] , V_274 ? L_65 : L_66 ) ;
}
V_4 -> V_60 ( V_111 , V_4 -> V_61 + V_113 ) ;
return 0 ;
}
static void F_122 ( struct V_36 * V_37 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
int V_28 , V_38 , V_310 , V_33 ;
int V_311 , V_312 ;
T_2 V_31 ;
V_33 = F_15 ( V_4 -> V_266 ) ;
V_311 = ( ( T_2 ) ( 16 << V_33 ) << 20 ) >> ( V_4 -> V_30 ) ;
V_311 >>= F_10 ( V_4 ) ? 1 : 0 ;
V_312 = V_311 - 1 ;
V_310 = V_4 -> V_30 - 1 ;
V_37 -> V_39 = V_4 -> V_307 << 1 ;
F_121 ( V_37 ) ;
V_28 = V_31 = 0 ;
V_38 = - 1 ;
for (; V_28 < V_4 -> V_307 ; V_28 ++ ) {
if ( ! V_28 || V_4 -> V_26 [ V_28 - 1 ] != V_312 ) {
V_38 ++ ;
V_37 -> V_40 [ V_38 ] . V_41 = V_31 ;
V_37 -> V_40 [ V_38 ] . V_160 = 1 << V_310 ;
V_37 -> V_40 [ V_38 ] . V_239 =
V_4 -> V_26 [ V_28 ] + 1 ;
V_31 += V_37 -> V_40 [ V_38 ] . V_239 << V_310 ;
V_310 ++ ;
} else {
V_37 -> V_39 -= 1 ;
V_37 -> V_40 [ V_38 ] . V_239 +=
V_4 -> V_26 [ V_28 ] + 1 ;
V_31 += ( V_4 -> V_26 [ V_28 ] + 1 ) << ( V_310 - 1 ) ;
}
if ( V_4 -> V_26 [ V_28 ] != V_312 ) {
V_38 ++ ;
V_37 -> V_40 [ V_38 ] . V_41 = V_31 ;
V_37 -> V_40 [ V_38 ] . V_160 = 1 << V_310 ;
V_37 -> V_40 [ V_38 ] . V_239 = V_312 ^
V_4 -> V_26 [ V_28 ] ;
V_31 += V_37 -> V_40 [ V_38 ] . V_239 << V_310 ;
V_310 -- ;
} else
V_37 -> V_39 -= 1 ;
}
V_37 -> V_160 = 1 << V_4 -> V_30 ;
if ( V_37 -> V_39 == 1 )
V_37 -> V_160 >>= 1 ;
F_29 ( V_110 L_67 , V_37 -> V_39 ) ;
for ( V_38 = 0 ; V_38 < V_37 -> V_39 ; V_38 ++ )
F_29 ( V_110 L_68
L_69 ,
( unsigned int ) V_37 -> V_40 [ V_38 ] . V_41 ,
V_37 -> V_40 [ V_38 ] . V_160 ,
V_37 -> V_40 [ V_38 ] . V_239 ) ;
for ( V_28 = 0 , V_37 -> V_178 = 0 ; V_28 < V_4 -> V_307 ; V_28 ++ ) {
V_4 -> V_29 [ V_28 ] = ( T_2 ) V_311 << V_4 -> V_30 ;
V_4 -> V_29 [ V_28 ] -= ( T_2 ) ( V_4 -> V_26 [ V_28 ] + 1 )
<< ( V_4 -> V_30 - 1 ) ;
V_37 -> V_178 += V_4 -> V_29 [ V_28 ] ;
}
}
static int F_123 ( struct V_36 * V_37 , int V_246 , int V_247 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
int V_38 , V_174 ;
int V_5 ;
struct V_163 V_164 = {
. V_175 = V_186 ,
. V_185 = 0 ,
. V_167 = V_37 -> V_118 ,
. V_168 = NULL ,
. V_169 = V_4 -> V_148 ,
} ;
T_2 V_1 ;
F_29 ( V_97 L_70 , V_246 , V_247 ) ;
for ( V_5 = V_246 ; V_5 <= V_247 ; V_5 ++ ) {
V_1 = F_13 ( V_4 , V_5 ) ;
if ( F_87 ( V_37 , V_1 , 0 ) )
continue;
V_174 = F_69 ( V_37 , V_1 , & V_164 ) ;
if ( V_174 )
return V_174 ;
for ( V_38 = 0 ; V_38 < V_37 -> V_118 ; V_38 ++ )
if ( V_4 -> V_148 [ V_38 ] != 0xff )
break;
if ( V_38 != V_37 -> V_118 ) {
F_29 ( V_229 L_71 ,
V_93 , V_5 ) ;
return 1 ;
}
}
return 0 ;
}
int F_124 ( struct V_36 * V_37 , int V_28 ,
int V_26 , int V_313 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
int V_174 , V_33 , V_311 , V_314 , V_315 , V_316 ;
T_2 V_1 ;
if ( V_28 && ( ! F_10 ( V_4 ) ) )
return 0 ;
if ( V_26 < 0 || V_26 == V_4 -> V_26 [ V_28 ] )
return 0 ;
V_33 = F_15 ( V_4 -> V_266 ) ;
V_311 = ( ( 16 << V_33 ) << 20 ) >> V_4 -> V_30 ;
V_311 >>= F_10 ( V_4 ) ? 1 : 0 ;
if ( V_26 >= V_311 ) {
F_29 ( V_92 L_72
L_73 , V_93 ) ;
return - V_181 ;
}
V_314 = V_4 -> V_26 [ V_28 ] + ( V_28 * V_4 -> V_6 ) ;
V_315 = V_26 + ( V_28 * V_4 -> V_6 ) ;
V_174 = F_123 ( V_37 , F_90 ( V_314 , V_315 ) + 1 , F_125 ( V_314 , V_315 ) ) ;
if ( V_174 ) {
F_29 ( V_92 L_74
L_75 , V_93 ) ;
return V_174 ;
}
V_4 -> V_161 ( V_37 , V_49 , V_28 , 0 ) ;
V_4 -> V_109 ( V_37 , V_243 ) ;
V_4 -> V_161 ( V_37 , V_55 , V_28 , 0 ) ;
V_174 = V_4 -> V_109 ( V_37 , V_88 ) ;
V_316 = V_4 -> V_76 ( V_4 -> V_61 + V_116 ) ;
if ( ( V_316 >> V_308 ) != 3 ) {
F_29 ( V_92 L_76 , V_93 ) ;
V_174 = 1 ;
goto V_317;
}
F_29 ( V_110 L_77 ,
V_28 , V_26 , V_313 ? L_65 : L_66 ) ;
V_1 = V_28 ? V_4 -> V_29 [ 0 ] : 0 ;
V_26 &= V_309 ;
V_26 |= V_313 ? 0 : ( 3 << V_308 ) ;
V_4 -> V_161 ( V_37 , V_50 , V_1 , 0 ) ;
V_174 = V_4 -> V_109 ( V_37 , V_235 ) ;
if ( V_174 ) {
F_29 ( V_92 L_78 ,
V_93 , V_28 ) ;
goto V_317;
}
V_4 -> V_60 ( V_26 , V_4 -> V_61 + V_116 ) ;
V_4 -> V_161 ( V_37 , V_67 , V_1 , 0 ) ;
V_174 = V_4 -> V_109 ( V_37 , V_210 ) ;
if ( V_174 ) {
F_29 ( V_92 L_79 ,
V_93 , V_28 ) ;
goto V_317;
}
V_4 -> V_161 ( V_37 , V_318 , V_28 , 0 ) ;
V_174 = V_4 -> V_109 ( V_37 , V_210 ) ;
V_317:
V_4 -> V_60 ( V_261 , V_4 -> V_61 + V_73 ) ;
V_4 -> V_109 ( V_37 , V_262 ) ;
if ( ! V_174 )
F_122 ( V_37 ) ;
return V_174 ;
}
static int F_126 ( struct V_36 * V_37 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
int V_319 , V_320 , V_321 , V_32 ;
int V_111 ;
V_111 = V_4 -> V_76 ( V_4 -> V_61 + V_113 ) ;
V_4 -> V_60 ( ( V_111 & ~ V_123 & ~ V_322 ) , V_4 -> V_61 + V_113 ) ;
V_4 -> V_60 ( V_323 , V_4 -> V_61 + V_324 ) ;
V_319 = V_4 -> V_76 ( V_4 -> V_61 + V_324 + 0x0 ) ;
V_320 = V_4 -> V_76 ( V_4 -> V_61 + V_324 + 0x2 ) ;
V_4 -> V_60 ( V_261 , V_4 -> V_61 + V_324 ) ;
V_4 -> V_109 ( V_37 , V_262 ) ;
V_4 -> V_60 ( V_111 , V_4 -> V_61 + V_113 ) ;
if ( F_119 ( V_319 ) )
return - V_325 ;
V_321 = V_4 -> V_76 ( V_4 -> V_61 + V_326 ) ;
V_32 = V_4 -> V_76 ( V_4 -> V_61 + V_327 ) ;
if ( V_321 != V_319 || V_32 != V_320 )
return - V_325 ;
return 0 ;
}
static int F_127 ( struct V_36 * V_37 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
int V_321 , V_32 , V_328 ;
int V_33 ;
int V_174 ;
V_174 = V_4 -> V_329 ( V_37 ) ;
if ( V_174 )
return V_174 ;
V_321 = V_4 -> V_76 ( V_4 -> V_61 + V_326 ) ;
V_32 = V_4 -> V_76 ( V_4 -> V_61 + V_327 ) ;
V_328 = V_4 -> V_76 ( V_4 -> V_61 + V_330 ) ;
V_4 -> V_331 = V_4 -> V_76 ( V_4 -> V_61 + V_332 ) ;
F_118 ( V_32 , V_328 ) ;
V_4 -> V_266 = V_32 ;
V_4 -> V_282 = V_328 ;
F_116 ( V_37 ) ;
V_33 = F_15 ( V_32 ) ;
if ( F_12 ( V_4 ) ) {
V_4 -> V_307 = F_10 ( V_4 ) ? 2 : 1 ;
V_37 -> V_39 = V_4 -> V_307 << 1 ;
V_37 -> V_40 = F_128 ( sizeof( struct V_236 )
* ( V_4 -> V_307 << 1 ) , V_333 ) ;
if ( ! V_37 -> V_40 )
return - V_334 ;
}
V_4 -> V_183 = ( 16 << V_33 ) << 20 ;
V_37 -> V_58 = V_4 -> V_76 ( V_4 -> V_61 + V_335 ) ;
if ( F_19 ( V_4 ) )
V_37 -> V_58 <<= 1 ;
V_37 -> V_118 = V_37 -> V_58 >> 5 ;
V_37 -> V_160 = V_37 -> V_58 << 6 ;
if ( F_12 ( V_4 ) )
V_37 -> V_160 <<= 1 ;
V_4 -> V_30 = F_129 ( V_37 -> V_160 ) - 1 ;
V_4 -> V_57 = F_129 ( V_37 -> V_58 ) - 1 ;
V_4 -> V_59 = ( 1 << ( V_4 -> V_30 - V_4 -> V_57 ) ) - 1 ;
if ( F_10 ( V_4 ) )
V_4 -> V_6 = V_4 -> V_183 >> ( V_4 -> V_30 + 1 ) ;
V_4 -> V_58 = V_37 -> V_58 ;
if ( F_12 ( V_4 ) )
F_122 ( V_37 ) ;
else
V_37 -> V_178 = V_4 -> V_183 ;
if ( F_18 ( V_4 ) ) {
V_37 -> V_58 <<= 1 ;
V_37 -> V_160 <<= 1 ;
}
return 0 ;
}
static int F_130 ( struct V_36 * V_37 )
{
return F_49 ( V_37 , V_135 ) ;
}
static void F_131 ( struct V_36 * V_37 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
if ( V_4 -> V_81 == V_135 )
F_57 ( V_37 ) ;
else
F_29 ( V_92 L_80
L_81 , V_93 ) ;
}
int F_132 ( struct V_36 * V_37 , int V_336 )
{
int V_38 , V_174 ;
struct V_3 * V_4 = V_37 -> V_44 ;
if ( ! V_4 -> V_76 )
V_4 -> V_76 = F_1 ;
if ( ! V_4 -> V_60 )
V_4 -> V_60 = F_3 ;
if ( ! V_4 -> V_161 )
V_4 -> V_161 = F_17 ;
if ( ! V_4 -> V_109 )
F_36 ( V_37 ) ;
if ( ! V_4 -> V_192 )
V_4 -> V_192 = F_72 ;
if ( ! V_4 -> V_337 )
V_4 -> V_337 = F_103 ;
if ( ! V_4 -> V_329 )
V_4 -> V_329 = F_126 ;
if ( ! V_4 -> V_153 )
V_4 -> V_153 = F_40 ;
if ( ! V_4 -> V_200 )
V_4 -> V_200 = F_43 ;
if ( ! V_4 -> V_338 )
V_4 -> V_338 = F_96 ;
if ( ! V_4 -> V_339 )
V_4 -> V_339 = V_340 ;
if ( F_127 ( V_37 ) )
return - V_325 ;
if ( V_4 -> V_122 ) {
F_29 ( V_110 L_82 ) ;
V_4 -> V_153 = F_42 ;
}
if ( ! V_4 -> V_199 ) {
V_4 -> V_199 = F_128 ( V_37 -> V_58 , V_333 ) ;
if ( ! V_4 -> V_199 ) {
F_29 ( V_92 L_83 ,
V_93 ) ;
return - V_334 ;
}
#ifdef F_133
V_4 -> V_194 = F_128 ( V_37 -> V_58 , V_333 ) ;
if ( ! V_4 -> V_194 ) {
F_134 ( V_4 -> V_199 ) ;
return - V_334 ;
}
#endif
V_4 -> V_251 |= V_341 ;
}
if ( ! V_4 -> V_148 ) {
V_4 -> V_148 = F_128 ( V_37 -> V_118 , V_333 ) ;
if ( ! V_4 -> V_148 ) {
F_29 ( V_92 L_84 ,
V_93 ) ;
if ( V_4 -> V_251 & V_341 ) {
V_4 -> V_251 &= ~ V_341 ;
F_134 ( V_4 -> V_199 ) ;
}
return - V_334 ;
}
V_4 -> V_251 |= V_342 ;
}
V_4 -> V_81 = V_134 ;
F_135 ( & V_4 -> V_139 ) ;
F_136 ( & V_4 -> V_133 ) ;
switch ( V_37 -> V_118 ) {
case 128 :
if ( F_12 ( V_4 ) ) {
V_4 -> V_149 = & V_343 ;
V_37 -> V_344 = 0 ;
} else {
V_4 -> V_149 = & V_345 ;
V_37 -> V_344 = 2 ;
}
if ( F_137 ( V_4 ) )
V_37 -> V_344 = 0 ;
break;
case 64 :
V_4 -> V_149 = & V_346 ;
V_37 -> V_344 = 2 ;
break;
case 32 :
V_4 -> V_149 = & V_347 ;
V_37 -> V_344 = 1 ;
break;
default:
F_29 ( V_229 L_85 ,
V_93 , V_37 -> V_118 ) ;
V_37 -> V_344 = 0 ;
V_4 -> V_149 = & V_347 ;
break;
}
V_4 -> V_348 = V_37 -> V_58 >> V_37 -> V_344 ;
V_4 -> V_149 -> V_177 = 0 ;
for ( V_38 = 0 ; V_38 < V_151 &&
V_4 -> V_149 -> V_150 [ V_38 ] . V_152 ; V_38 ++ )
V_4 -> V_149 -> V_177 +=
V_4 -> V_149 -> V_150 [ V_38 ] . V_152 ;
V_37 -> V_177 = V_4 -> V_149 -> V_177 ;
V_37 -> V_149 = V_4 -> V_149 ;
V_37 -> V_349 = 1 ;
V_37 -> type = F_117 ( V_4 ) ? V_350 : V_351 ;
V_37 -> V_83 = V_352 ;
V_37 -> V_353 = F_92 ;
V_37 -> V_354 = NULL ;
V_37 -> V_355 = NULL ;
V_37 -> V_356 = F_70 ;
V_37 -> V_357 = F_85 ;
V_37 -> V_358 = F_71 ;
V_37 -> V_359 = F_86 ;
V_37 -> V_360 = F_78 ;
#ifdef F_138
V_37 -> V_361 = F_110 ;
V_37 -> V_362 = F_111 ;
V_37 -> V_363 = F_112 ;
V_37 -> V_364 = F_113 ;
V_37 -> V_365 = F_114 ;
V_37 -> V_366 = F_115 ;
#endif
V_37 -> V_367 = F_94 ;
V_37 -> V_368 = F_100 ;
V_37 -> V_369 = F_101 ;
V_37 -> V_370 = F_130 ;
V_37 -> V_371 = F_131 ;
V_37 -> V_372 = F_95 ;
V_37 -> V_373 = F_97 ;
V_37 -> V_374 = V_375 ;
V_37 -> V_376 = V_37 -> V_58 ;
if ( ! ( V_4 -> V_251 & V_377 ) )
V_4 -> V_337 ( V_37 ) ;
V_174 = V_4 -> V_339 ( V_37 ) ;
if ( ( ! F_12 ( V_4 ) ) || V_174 )
return V_174 ;
for ( V_38 = 0 ; V_38 < V_378 ; V_38 ++ )
F_124 ( V_37 , V_38 , V_379 [ 2 * V_38 ] ,
V_379 [ ( 2 * V_38 ) + 1 ] ) ;
return 0 ;
}
void F_139 ( struct V_36 * V_37 )
{
struct V_3 * V_4 = V_37 -> V_44 ;
F_140 ( V_37 ) ;
if ( V_4 -> V_217 ) {
struct V_216 * V_217 = V_4 -> V_217 ;
F_134 ( V_217 -> V_244 ) ;
F_134 ( V_4 -> V_217 ) ;
}
if ( V_4 -> V_251 & V_341 ) {
F_134 ( V_4 -> V_199 ) ;
#ifdef F_133
F_134 ( V_4 -> V_194 ) ;
#endif
}
if ( V_4 -> V_251 & V_342 )
F_134 ( V_4 -> V_148 ) ;
F_134 ( V_37 -> V_40 ) ;
}
