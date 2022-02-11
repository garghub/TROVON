static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_2 * V_3 , T_1 V_4 , T_1 V_5 )
{
T_1 V_6 ;
V_6 = F_4 ( V_3 -> V_7 + V_4 ) ;
V_6 |= V_5 ;
F_5 ( V_6 , V_3 -> V_7 + V_4 ) ;
}
static void F_6 ( struct V_2 * V_3 , T_1 V_4 , T_1 V_5 )
{
T_1 V_6 ;
V_6 = F_4 ( V_3 -> V_7 + V_4 ) ;
V_6 &= ~ V_5 ;
F_5 ( V_6 , V_3 -> V_7 + V_4 ) ;
}
static int F_7 ( struct V_2 * V_3 , T_1 * V_8 , int * V_9 ,
bool V_10 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_11 * V_12 = & V_1 -> V_13 -> V_12 ;
enum V_14 V_15 ;
struct V_16 V_17 ;
* V_8 = F_4 ( V_3 -> V_7 + V_12 -> V_18 ) ;
if ( V_10 && V_1 -> V_19 ) {
V_15 = F_8 ( V_1 -> V_19 ,
V_1 -> V_19 -> V_20 ,
& V_17 ) ;
if ( ( V_15 == V_21 ) &&
( * V_9 != V_17 . V_22 ) )
return 1 ;
else
return 0 ;
} else if ( * V_8 & V_23 ) {
return 1 ;
}
return 0 ;
}
static unsigned long
F_9 ( struct V_2 * V_3 , T_1 * V_8 , int * V_9 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_11 * V_12 = & V_1 -> V_13 -> V_12 ;
unsigned long V_24 ;
if ( V_1 -> V_19 ) {
V_24 = V_1 -> V_25 [ V_26 - ( * V_9 ) -- ] ;
if ( ( * V_9 ) == 0 )
* V_9 = V_26 ;
return V_24 ;
} else {
return F_4 ( V_3 -> V_7 + V_12 -> V_27 ) ;
}
}
static void F_10 ( struct V_2 * V_3 , bool V_10 )
{
struct V_28 * V_29 = & V_3 -> V_17 -> V_3 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_11 * V_12 = & V_1 -> V_13 -> V_12 ;
unsigned long V_24 ;
T_1 V_8 ;
char V_30 ;
if ( F_11 ( F_12 ( V_3 -> V_31 ) ) )
F_13 ( V_29 -> V_32 -> V_33 , 0 ) ;
while ( F_7 ( V_3 , & V_8 , & V_1 -> V_9 , V_10 ) ) {
V_8 |= V_34 ;
V_24 = F_9 ( V_3 , & V_8 , & V_1 -> V_9 ) ;
V_30 = V_35 ;
V_3 -> V_36 . V_37 ++ ;
if ( V_8 & V_38 ) {
if ( V_8 & V_39 ) {
V_3 -> V_36 . V_40 ++ ;
if ( F_14 ( V_3 ) )
continue;
} else if ( V_8 & V_41 ) {
if ( V_12 -> V_42 != V_43 )
F_5 ( V_44 ,
V_3 -> V_7 +
V_12 -> V_42 ) ;
V_3 -> V_36 . V_45 ++ ;
} else if ( V_8 & V_46 ) {
V_3 -> V_36 . V_47 ++ ;
} else if ( V_8 & V_48 ) {
V_3 -> V_36 . V_49 ++ ;
}
V_8 &= V_3 -> V_50 ;
if ( V_8 & V_39 )
V_30 = V_51 ;
else if ( V_8 & V_46 )
V_30 = V_52 ;
else if ( V_8 & V_48 )
V_30 = V_53 ;
}
if ( F_15 ( V_3 , V_24 ) )
continue;
F_16 ( V_3 , V_8 , V_41 , V_24 , V_30 ) ;
}
F_17 ( & V_3 -> V_54 ) ;
F_18 ( V_29 ) ;
F_19 ( & V_3 -> V_54 ) ;
}
static void F_20 ( void * V_55 )
{
struct V_2 * V_3 = V_55 ;
struct V_1 * V_56 = F_1 ( V_3 ) ;
struct V_11 * V_12 = & V_56 -> V_13 -> V_12 ;
unsigned int V_18 ;
int V_57 ;
V_57 = F_21 ( V_3 -> V_7 + V_12 -> V_18 ,
V_18 ,
( V_18 & V_58 ) ,
10 , 100000 ) ;
if ( V_57 )
F_22 ( V_3 -> V_33 , L_1 ) ;
if ( V_12 -> V_42 == V_43 )
F_6 ( V_3 , V_12 -> V_18 , V_58 ) ;
else
F_3 ( V_3 , V_12 -> V_42 , V_59 ) ;
F_6 ( V_3 , V_12 -> V_60 , V_61 ) ;
V_56 -> V_62 = false ;
F_23 ( V_3 ) ;
}
static void F_24 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_11 * V_12 = & V_1 -> V_13 -> V_12 ;
struct V_63 * V_64 = & V_3 -> V_17 -> V_64 ;
unsigned int V_18 ;
int V_57 ;
if ( V_1 -> V_62 ) {
F_6 ( V_3 , V_12 -> V_60 , V_61 ) ;
V_1 -> V_62 = false ;
}
V_57 = F_21 ( V_3 -> V_7 + V_12 -> V_18 ,
V_18 ,
( V_18 & V_65 ) ,
10 , 100000 ) ;
if ( V_57 )
F_22 ( V_3 -> V_33 , L_2 ) ;
F_3 ( V_3 , V_12 -> V_66 , V_67 ) ;
F_5 ( V_64 -> V_68 [ V_64 -> V_69 ] , V_3 -> V_7 + V_12 -> V_70 ) ;
V_64 -> V_69 = ( V_64 -> V_69 + 1 ) & ( V_71 - 1 ) ;
V_3 -> V_36 . V_72 ++ ;
}
static void F_25 ( struct V_2 * V_3 )
{
struct V_1 * V_56 = F_1 ( V_3 ) ;
struct V_11 * V_12 = & V_56 -> V_13 -> V_12 ;
struct V_63 * V_64 = & V_3 -> V_17 -> V_64 ;
struct V_73 * V_74 = NULL ;
T_2 V_20 ;
unsigned int V_75 , V_76 ;
if ( V_56 -> V_62 )
return;
V_56 -> V_62 = true ;
V_75 = F_26 ( V_64 ) ;
if ( V_75 > V_77 )
V_75 = V_77 ;
if ( V_64 -> V_69 < V_64 -> V_78 ) {
memcpy ( & V_56 -> V_79 [ 0 ] , & V_64 -> V_68 [ V_64 -> V_69 ] , V_75 ) ;
} else {
T_3 V_80 = V_71 - V_64 -> V_69 ;
T_3 V_81 ;
if ( V_80 > V_75 )
V_80 = V_75 ;
V_81 = V_75 - V_80 ;
memcpy ( & V_56 -> V_79 [ 0 ] , & V_64 -> V_68 [ V_64 -> V_69 ] , V_80 ) ;
if ( V_81 )
memcpy ( & V_56 -> V_79 [ V_80 ] , & V_64 -> V_68 [ 0 ] , V_81 ) ;
}
V_74 = F_27 ( V_56 -> V_82 ,
V_56 -> V_83 ,
V_75 ,
V_84 ,
V_85 ) ;
if ( ! V_74 ) {
for ( V_76 = V_75 ; V_76 > 0 ; V_76 -- )
F_24 ( V_3 ) ;
return;
}
V_74 -> V_86 = F_20 ;
V_74 -> V_87 = V_3 ;
V_20 = F_28 ( V_74 ) ;
F_29 ( V_56 -> V_82 ) ;
F_6 ( V_3 , V_12 -> V_18 , V_58 ) ;
F_3 ( V_3 , V_12 -> V_60 , V_61 ) ;
V_64 -> V_69 = ( V_64 -> V_69 + V_75 ) & ( V_71 - 1 ) ;
V_3 -> V_36 . V_72 += V_75 ;
}
static void F_23 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_11 * V_12 = & V_1 -> V_13 -> V_12 ;
struct V_63 * V_64 = & V_3 -> V_17 -> V_64 ;
if ( V_3 -> V_88 ) {
if ( V_1 -> V_62 )
F_6 ( V_3 , V_12 -> V_60 , V_61 ) ;
F_5 ( V_3 -> V_88 , V_3 -> V_7 + V_12 -> V_70 ) ;
V_3 -> V_88 = 0 ;
V_3 -> V_36 . V_72 ++ ;
if ( V_1 -> V_62 )
F_3 ( V_3 , V_12 -> V_60 , V_61 ) ;
return;
}
if ( F_30 ( V_3 ) ) {
F_31 ( V_3 ) ;
return;
}
if ( F_32 ( V_64 ) ) {
F_31 ( V_3 ) ;
return;
}
if ( V_1 -> V_82 )
F_25 ( V_3 ) ;
else
F_24 ( V_3 ) ;
if ( F_26 ( V_64 ) < V_89 )
F_33 ( V_3 ) ;
if ( F_32 ( V_64 ) )
F_31 ( V_3 ) ;
}
static T_4 F_34 ( int V_31 , void * V_90 )
{
struct V_2 * V_3 = V_90 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_11 * V_12 = & V_1 -> V_13 -> V_12 ;
T_1 V_8 ;
F_19 ( & V_3 -> V_54 ) ;
V_8 = F_4 ( V_3 -> V_7 + V_12 -> V_18 ) ;
if ( ( V_8 & V_91 ) && ( V_12 -> V_42 != V_43 ) )
F_5 ( V_92 ,
V_3 -> V_7 + V_12 -> V_42 ) ;
if ( ( V_8 & V_23 ) && ! ( V_1 -> V_19 ) )
F_10 ( V_3 , false ) ;
if ( ( V_8 & V_65 ) && ! ( V_1 -> V_82 ) )
F_23 ( V_3 ) ;
F_17 ( & V_3 -> V_54 ) ;
if ( V_1 -> V_19 )
return V_93 ;
else
return V_94 ;
}
static T_4 F_35 ( int V_31 , void * V_90 )
{
struct V_2 * V_3 = V_90 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_19 ( & V_3 -> V_54 ) ;
if ( V_1 -> V_19 )
F_10 ( V_3 , true ) ;
F_17 ( & V_3 -> V_54 ) ;
return V_94 ;
}
static unsigned int F_36 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_11 * V_12 = & V_1 -> V_13 -> V_12 ;
return F_4 ( V_3 -> V_7 + V_12 -> V_18 ) & V_65 ;
}
static void F_37 ( struct V_2 * V_3 , unsigned int V_95 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_11 * V_12 = & V_1 -> V_13 -> V_12 ;
if ( ( V_95 & V_96 ) && ( V_3 -> V_15 & V_97 ) )
F_3 ( V_3 , V_12 -> V_60 , V_98 ) ;
else
F_6 ( V_3 , V_12 -> V_60 , V_98 ) ;
}
static unsigned int F_38 ( struct V_2 * V_3 )
{
return V_99 | V_100 | V_101 ;
}
static void F_31 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_11 * V_12 = & V_1 -> V_13 -> V_12 ;
F_6 ( V_3 , V_12 -> V_66 , V_67 ) ;
}
static void F_39 ( struct V_2 * V_3 )
{
struct V_63 * V_64 = & V_3 -> V_17 -> V_64 ;
if ( F_32 ( V_64 ) )
return;
F_23 ( V_3 ) ;
}
static void F_40 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_11 * V_12 = & V_1 -> V_13 -> V_12 ;
unsigned long V_102 ;
F_41 ( & V_3 -> V_54 , V_102 ) ;
F_6 ( V_3 , V_12 -> V_66 , V_103 ) ;
F_42 ( & V_3 -> V_54 , V_102 ) ;
}
static void F_43 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_11 * V_12 = & V_1 -> V_13 -> V_12 ;
unsigned long V_102 ;
F_41 ( & V_3 -> V_54 , V_102 ) ;
F_3 ( V_3 , V_12 -> V_66 , V_103 ) ;
F_42 ( & V_3 -> V_54 , V_102 ) ;
}
static void F_44 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_11 * V_12 = & V_1 -> V_13 -> V_12 ;
F_6 ( V_3 , V_12 -> V_66 , V_103 ) ;
}
static void F_45 ( struct V_2 * V_3 , int V_104 )
{
}
static int F_46 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_11 * V_12 = & V_1 -> V_13 -> V_12 ;
struct V_105 * V_106 = & V_1 -> V_13 -> V_106 ;
const char * V_107 = F_47 ( V_3 -> V_33 ) -> V_107 ;
T_1 V_6 ;
int V_57 ;
V_57 = F_48 ( V_3 -> V_31 , F_34 ,
F_35 ,
V_108 , V_107 , V_3 ) ;
if ( V_57 )
return V_57 ;
if ( V_106 -> V_109 && V_1 -> V_110 >= 0 ) {
V_57 = F_49 ( V_3 -> V_33 ,
V_1 -> V_110 ) ;
if ( V_57 ) {
F_50 ( V_3 -> V_31 , V_3 ) ;
return V_57 ;
}
}
V_6 = V_103 | V_111 | V_112 ;
if ( V_1 -> V_113 )
V_6 |= V_114 ;
F_3 ( V_3 , V_12 -> V_66 , V_6 ) ;
return 0 ;
}
static void F_51 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_11 * V_12 = & V_1 -> V_13 -> V_12 ;
struct V_105 * V_106 = & V_1 -> V_13 -> V_106 ;
T_1 V_6 ;
V_6 = V_67 | V_103 | V_111 | V_112 ;
V_6 |= F_52 ( V_106 -> V_115 ) ;
if ( V_1 -> V_113 )
V_6 |= V_114 ;
F_6 ( V_3 , V_12 -> V_66 , V_6 ) ;
F_53 ( V_3 -> V_33 ) ;
F_50 ( V_3 -> V_31 , V_3 ) ;
}
static void F_54 ( struct V_2 * V_3 , struct V_116 * V_117 ,
struct V_116 * V_118 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_11 * V_12 = & V_1 -> V_13 -> V_12 ;
struct V_105 * V_106 = & V_1 -> V_13 -> V_106 ;
unsigned int V_119 ;
T_1 V_120 , V_121 , V_122 , V_123 ;
T_5 V_124 = V_117 -> V_125 ;
T_1 V_66 , V_126 , V_60 ;
unsigned long V_102 ;
if ( ! V_1 -> V_127 )
V_124 &= ~ V_128 ;
V_119 = F_55 ( V_3 , V_117 , V_118 , 0 , V_3 -> V_129 / 8 ) ;
F_41 ( & V_3 -> V_54 , V_102 ) ;
F_5 ( 0 , V_3 -> V_7 + V_12 -> V_66 ) ;
V_66 = V_111 | V_112 | V_103 ;
V_66 |= F_52 ( V_106 -> V_115 ) ;
if ( V_1 -> V_113 )
V_66 |= V_114 ;
V_126 = 0 ;
V_60 = 0 ;
if ( V_124 & V_130 )
V_126 |= V_131 ;
if ( V_124 & V_132 ) {
V_66 |= V_133 ;
if ( ( V_124 & V_134 ) == V_135 ) {
if ( V_106 -> V_136 )
V_66 |= V_137 ;
else
V_66 |= V_138 ;
}
}
if ( V_124 & V_139 )
V_66 |= V_140 ;
V_3 -> V_15 &= ~ ( V_141 | V_97 ) ;
if ( V_124 & V_128 ) {
V_3 -> V_15 |= V_141 | V_97 ;
V_60 |= V_142 | V_98 ;
}
V_120 = F_56 ( V_3 -> V_129 , V_119 ) ;
if ( V_120 < 16 ) {
V_123 = 8 ;
F_3 ( V_3 , V_12 -> V_66 , V_143 ) ;
} else {
V_123 = 16 ;
F_6 ( V_3 , V_12 -> V_66 , V_143 ) ;
}
V_121 = ( V_120 / V_123 ) << V_144 ;
V_122 = V_120 % V_123 ;
F_5 ( V_121 | V_122 , V_3 -> V_7 + V_12 -> V_145 ) ;
F_57 ( V_3 , V_124 , V_119 ) ;
V_3 -> V_50 = V_41 ;
if ( V_117 -> V_146 & V_147 )
V_3 -> V_50 |= V_46 | V_48 ;
if ( V_117 -> V_146 & ( V_148 | V_149 | V_150 ) )
V_3 -> V_50 |= V_39 ;
V_3 -> V_151 = 0 ;
if ( V_117 -> V_146 & V_152 )
V_3 -> V_151 = V_46 | V_48 ;
if ( V_117 -> V_146 & V_148 ) {
V_3 -> V_151 |= V_39 ;
if ( V_117 -> V_146 & V_152 )
V_3 -> V_151 |= V_41 ;
}
if ( ( V_117 -> V_125 & V_153 ) == 0 )
V_3 -> V_151 |= V_34 ;
if ( V_1 -> V_19 )
V_60 |= V_154 ;
F_5 ( V_60 , V_3 -> V_7 + V_12 -> V_60 ) ;
F_5 ( V_126 , V_3 -> V_7 + V_12 -> V_126 ) ;
F_5 ( V_66 , V_3 -> V_7 + V_12 -> V_66 ) ;
F_42 ( & V_3 -> V_54 , V_102 ) ;
}
static const char * F_58 ( struct V_2 * V_3 )
{
return ( V_3 -> type == V_155 ) ? V_156 : NULL ;
}
static void F_59 ( struct V_2 * V_3 )
{
}
static int F_60 ( struct V_2 * V_3 )
{
return 0 ;
}
static void F_61 ( struct V_2 * V_3 , int V_102 )
{
if ( V_102 & V_157 )
V_3 -> type = V_155 ;
}
static int
F_62 ( struct V_2 * V_3 , struct V_158 * V_159 )
{
return - V_160 ;
}
static void F_63 ( struct V_2 * V_3 , unsigned int V_17 ,
unsigned int V_161 )
{
struct V_1 * V_56 = F_2 ( V_3 ,
struct V_1 , V_3 ) ;
struct V_11 * V_12 = & V_56 -> V_13 -> V_12 ;
struct V_105 * V_106 = & V_56 -> V_13 -> V_106 ;
unsigned long V_102 = 0 ;
switch ( V_17 ) {
case V_162 :
F_64 ( V_56 -> V_163 ) ;
break;
case V_164 :
F_41 ( & V_3 -> V_54 , V_102 ) ;
F_6 ( V_3 , V_12 -> V_66 , F_52 ( V_106 -> V_115 ) ) ;
F_42 ( & V_3 -> V_54 , V_102 ) ;
F_65 ( V_56 -> V_163 ) ;
break;
}
}
static int F_66 ( struct V_1 * V_56 ,
struct V_165 * V_166 )
{
struct V_2 * V_3 = & V_56 -> V_3 ;
struct V_167 * V_168 ;
int V_57 ;
V_3 -> V_169 = V_170 ;
V_3 -> V_102 = V_171 ;
V_3 -> V_172 = & V_173 ;
V_3 -> V_33 = & V_166 -> V_33 ;
V_3 -> V_31 = F_67 ( V_166 , 0 ) ;
V_56 -> V_110 = F_67 ( V_166 , 1 ) ;
V_56 -> V_113 = V_56 -> V_13 -> V_106 . V_174 ;
V_168 = F_68 ( V_166 , V_175 , 0 ) ;
V_3 -> V_7 = F_69 ( & V_166 -> V_33 , V_168 ) ;
if ( F_70 ( V_3 -> V_7 ) )
return F_71 ( V_3 -> V_7 ) ;
V_3 -> V_176 = V_168 -> V_177 ;
F_72 ( & V_3 -> V_54 ) ;
V_56 -> V_163 = F_73 ( & V_166 -> V_33 , NULL ) ;
if ( F_70 ( V_56 -> V_163 ) )
return F_71 ( V_56 -> V_163 ) ;
V_57 = F_64 ( V_56 -> V_163 ) ;
if ( V_57 )
return V_57 ;
V_56 -> V_3 . V_129 = F_74 ( V_56 -> V_163 ) ;
if ( ! V_56 -> V_3 . V_129 ) {
F_65 ( V_56 -> V_163 ) ;
V_57 = - V_160 ;
}
return V_57 ;
}
static struct V_1 * F_75 ( struct V_165 * V_166 )
{
struct V_178 * V_179 = V_166 -> V_33 . V_180 ;
int V_181 ;
if ( ! V_179 )
return NULL ;
V_181 = F_76 ( V_179 , L_3 ) ;
if ( V_181 < 0 ) {
F_22 ( & V_166 -> V_33 , L_4 , V_181 ) ;
return NULL ;
}
if ( F_77 ( V_181 >= V_182 ) )
return NULL ;
V_183 [ V_181 ] . V_127 = F_78 ( V_179 ,
L_5 ) ;
V_183 [ V_181 ] . V_3 . line = V_181 ;
V_183 [ V_181 ] . V_9 = V_26 ;
return & V_183 [ V_181 ] ;
}
static int F_79 ( struct V_1 * V_56 ,
struct V_165 * V_166 )
{
struct V_11 * V_12 = & V_56 -> V_13 -> V_12 ;
struct V_2 * V_3 = & V_56 -> V_3 ;
struct V_184 * V_33 = & V_166 -> V_33 ;
struct V_185 V_186 ;
struct V_73 * V_74 = NULL ;
T_2 V_20 ;
int V_57 ;
V_56 -> V_19 = F_80 ( V_33 , L_6 ) ;
if ( ! V_56 -> V_19 ) {
F_81 ( V_33 , L_7 ) ;
return - V_187 ;
}
V_56 -> V_25 = F_82 ( & V_166 -> V_33 , V_26 ,
& V_56 -> V_188 ,
V_189 ) ;
if ( ! V_56 -> V_25 ) {
V_57 = - V_190 ;
goto V_191;
}
memset ( & V_186 , 0 , sizeof( V_186 ) ) ;
V_186 . V_192 = V_3 -> V_176 + V_12 -> V_27 ;
V_186 . V_193 = V_194 ;
V_57 = F_83 ( V_56 -> V_19 , & V_186 ) ;
if ( V_57 < 0 ) {
F_22 ( V_33 , L_8 ) ;
V_57 = - V_187 ;
goto V_195;
}
V_74 = F_84 ( V_56 -> V_19 ,
V_56 -> V_188 ,
V_26 , V_196 , V_197 ,
V_85 ) ;
if ( ! V_74 ) {
F_22 ( V_33 , L_9 ) ;
V_57 = - V_187 ;
goto V_195;
}
V_74 -> V_86 = NULL ;
V_74 -> V_87 = NULL ;
V_20 = F_28 ( V_74 ) ;
F_29 ( V_56 -> V_19 ) ;
return 0 ;
V_195:
F_85 ( & V_166 -> V_33 ,
V_26 , V_56 -> V_25 ,
V_56 -> V_188 ) ;
V_191:
F_86 ( V_56 -> V_19 ) ;
V_56 -> V_19 = NULL ;
return V_57 ;
}
static int F_87 ( struct V_1 * V_56 ,
struct V_165 * V_166 )
{
struct V_11 * V_12 = & V_56 -> V_13 -> V_12 ;
struct V_2 * V_3 = & V_56 -> V_3 ;
struct V_184 * V_33 = & V_166 -> V_33 ;
struct V_185 V_186 ;
int V_57 ;
V_56 -> V_62 = false ;
V_56 -> V_82 = F_80 ( V_33 , L_10 ) ;
if ( ! V_56 -> V_82 ) {
F_81 ( V_33 , L_11 ) ;
return - V_187 ;
}
V_56 -> V_79 = F_82 ( & V_166 -> V_33 , V_77 ,
& V_56 -> V_83 ,
V_189 ) ;
if ( ! V_56 -> V_79 ) {
V_57 = - V_190 ;
goto V_191;
}
memset ( & V_186 , 0 , sizeof( V_186 ) ) ;
V_186 . V_198 = V_3 -> V_176 + V_12 -> V_70 ;
V_186 . V_199 = V_194 ;
V_57 = F_83 ( V_56 -> V_82 , & V_186 ) ;
if ( V_57 < 0 ) {
F_22 ( V_33 , L_12 ) ;
V_57 = - V_187 ;
goto V_195;
}
return 0 ;
V_195:
F_85 ( & V_166 -> V_33 ,
V_77 , V_56 -> V_79 ,
V_56 -> V_83 ) ;
V_191:
F_86 ( V_56 -> V_82 ) ;
V_56 -> V_82 = NULL ;
return V_57 ;
}
static int F_88 ( struct V_165 * V_166 )
{
const struct V_200 * V_201 ;
struct V_1 * V_56 ;
int V_57 ;
V_56 = F_75 ( V_166 ) ;
if ( ! V_56 )
return - V_187 ;
V_201 = F_89 ( V_202 , & V_166 -> V_33 ) ;
if ( V_201 && V_201 -> V_203 )
V_56 -> V_13 = (struct V_204 * ) V_201 -> V_203 ;
else
return - V_160 ;
V_57 = F_66 ( V_56 , V_166 ) ;
if ( V_57 )
return V_57 ;
if ( V_56 -> V_13 -> V_106 . V_109 && V_56 -> V_110 >= 0 ) {
V_57 = F_90 ( & V_166 -> V_33 , true ) ;
if ( V_57 )
goto V_205;
}
V_57 = F_91 ( & V_206 , & V_56 -> V_3 ) ;
if ( V_57 )
goto V_207;
V_57 = F_79 ( V_56 , V_166 ) ;
if ( V_57 )
F_81 ( & V_166 -> V_33 , L_13 ) ;
V_57 = F_87 ( V_56 , V_166 ) ;
if ( V_57 )
F_81 ( & V_166 -> V_33 , L_14 ) ;
F_92 ( V_166 , & V_56 -> V_3 ) ;
return 0 ;
V_207:
if ( V_56 -> V_13 -> V_106 . V_109 && V_56 -> V_110 >= 0 )
F_90 ( & V_166 -> V_33 , false ) ;
V_205:
F_65 ( V_56 -> V_163 ) ;
return V_57 ;
}
static int F_93 ( struct V_165 * V_166 )
{
struct V_2 * V_3 = F_94 ( V_166 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_11 * V_12 = & V_1 -> V_13 -> V_12 ;
struct V_105 * V_106 = & V_1 -> V_13 -> V_106 ;
F_6 ( V_3 , V_12 -> V_60 , V_154 ) ;
if ( V_1 -> V_19 )
F_86 ( V_1 -> V_19 ) ;
if ( V_1 -> V_188 )
F_85 ( & V_166 -> V_33 ,
V_26 , V_1 -> V_25 ,
V_1 -> V_188 ) ;
F_6 ( V_3 , V_12 -> V_60 , V_61 ) ;
if ( V_1 -> V_82 )
F_86 ( V_1 -> V_82 ) ;
if ( V_1 -> V_83 )
F_85 ( & V_166 -> V_33 ,
V_77 , V_1 -> V_79 ,
V_1 -> V_83 ) ;
if ( V_106 -> V_109 && V_1 -> V_110 >= 0 )
F_90 ( & V_166 -> V_33 , false ) ;
F_65 ( V_1 -> V_163 ) ;
return F_95 ( & V_206 , V_3 ) ;
}
static void F_96 ( struct V_2 * V_3 , int V_208 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_11 * V_12 = & V_1 -> V_13 -> V_12 ;
while ( ! ( F_4 ( V_3 -> V_7 + V_12 -> V_18 ) & V_65 ) )
F_97 () ;
F_5 ( V_208 , V_3 -> V_7 + V_12 -> V_70 ) ;
}
static void F_98 ( struct V_209 * V_210 , const char * V_211 , unsigned V_212 )
{
struct V_2 * V_3 = & V_183 [ V_210 -> V_213 ] . V_3 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_11 * V_12 = & V_1 -> V_13 -> V_12 ;
struct V_105 * V_106 = & V_1 -> V_13 -> V_106 ;
unsigned long V_102 ;
T_1 V_214 , V_215 ;
int V_216 = 1 ;
F_99 ( V_102 ) ;
if ( V_3 -> V_217 )
V_216 = 0 ;
else if ( V_218 )
V_216 = F_100 ( & V_3 -> V_54 ) ;
else
F_19 ( & V_3 -> V_54 ) ;
V_214 = F_4 ( V_3 -> V_7 + V_12 -> V_66 ) ;
V_215 = V_214 & ~ V_219 ;
V_215 |= V_111 | F_52 ( V_106 -> V_115 ) ;
F_5 ( V_215 , V_3 -> V_7 + V_12 -> V_66 ) ;
F_101 ( V_3 , V_211 , V_212 , F_96 ) ;
F_5 ( V_214 , V_3 -> V_7 + V_12 -> V_66 ) ;
if ( V_216 )
F_17 ( & V_3 -> V_54 ) ;
F_102 ( V_102 ) ;
}
static int F_103 ( struct V_209 * V_210 , char * V_220 )
{
struct V_1 * V_56 ;
int V_119 = 9600 ;
int V_5 = 8 ;
int V_47 = 'n' ;
int V_221 = 'n' ;
if ( V_210 -> V_213 >= V_182 )
return - V_187 ;
V_56 = & V_183 [ V_210 -> V_213 ] ;
if ( V_56 -> V_3 . V_176 == 0 || V_56 -> V_3 . V_7 == NULL )
return - V_222 ;
if ( V_220 )
F_104 ( V_220 , & V_119 , & V_47 , & V_5 , & V_221 ) ;
return F_105 ( & V_56 -> V_3 , V_210 , V_119 , V_47 , V_5 , V_221 ) ;
}
static void F_106 ( struct V_2 * V_3 , bool V_223 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_11 * V_12 = & V_1 -> V_13 -> V_12 ;
struct V_105 * V_106 = & V_1 -> V_13 -> V_106 ;
T_1 V_6 ;
if ( ! V_106 -> V_109 || V_1 -> V_110 < 0 )
return;
if ( V_223 ) {
F_6 ( V_3 , V_12 -> V_66 , F_52 ( V_106 -> V_115 ) ) ;
F_3 ( V_3 , V_12 -> V_66 , V_224 ) ;
V_6 = F_4 ( V_3 -> V_7 + V_12 -> V_60 ) ;
V_6 &= ~ V_225 ;
V_6 |= V_226 | V_227 ;
F_5 ( V_6 , V_3 -> V_7 + V_12 -> V_60 ) ;
F_3 ( V_3 , V_12 -> V_66 , F_52 ( V_106 -> V_115 ) ) ;
} else {
F_6 ( V_3 , V_12 -> V_66 , V_224 ) ;
}
}
static int F_107 ( struct V_184 * V_33 )
{
struct V_2 * V_3 = F_108 ( V_33 ) ;
F_109 ( & V_206 , V_3 ) ;
if ( F_110 ( V_33 ) )
F_106 ( V_3 , true ) ;
else
F_106 ( V_3 , false ) ;
return 0 ;
}
static int F_111 ( struct V_184 * V_33 )
{
struct V_2 * V_3 = F_108 ( V_33 ) ;
if ( F_110 ( V_33 ) )
F_106 ( V_3 , false ) ;
return F_112 ( & V_206 , V_3 ) ;
}
static int T_6 F_113 ( void )
{
static char V_228 [] V_229 = L_15 ;
int V_57 ;
F_114 ( L_16 , V_228 ) ;
V_57 = F_115 ( & V_206 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_116 ( & V_230 ) ;
if ( V_57 )
F_117 ( & V_206 ) ;
return V_57 ;
}
static void T_7 F_118 ( void )
{
F_119 ( & V_230 ) ;
F_117 ( & V_206 ) ;
}
