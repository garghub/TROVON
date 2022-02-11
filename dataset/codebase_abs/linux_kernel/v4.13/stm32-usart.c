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
static int V_9 = V_26 ;
if ( V_3 -> V_31 )
F_11 ( V_29 -> V_32 -> V_33 , 0 ) ;
while ( F_7 ( V_3 , & V_8 , & V_9 , V_10 ) ) {
V_8 |= V_34 ;
V_24 = F_9 ( V_3 , & V_8 , & V_9 ) ;
V_30 = V_35 ;
V_3 -> V_36 . V_37 ++ ;
if ( V_8 & V_38 ) {
if ( V_8 & V_39 ) {
V_3 -> V_36 . V_40 ++ ;
if ( F_12 ( V_3 ) )
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
if ( F_13 ( V_3 , V_24 ) )
continue;
F_14 ( V_3 , V_8 , V_41 , V_24 , V_30 ) ;
}
F_15 ( & V_3 -> V_54 ) ;
F_16 ( V_29 ) ;
F_17 ( & V_3 -> V_54 ) ;
}
static void F_18 ( void * V_55 )
{
struct V_2 * V_3 = V_55 ;
struct V_1 * V_56 = F_1 ( V_3 ) ;
struct V_11 * V_12 = & V_56 -> V_13 -> V_12 ;
unsigned int V_18 ;
int V_57 ;
V_57 = F_19 ( V_3 -> V_7 + V_12 -> V_18 ,
V_18 ,
( V_18 & V_58 ) ,
10 , 100000 ) ;
if ( V_57 )
F_20 ( V_3 -> V_33 , L_1 ) ;
if ( V_12 -> V_42 == V_43 )
F_6 ( V_3 , V_12 -> V_18 , V_58 ) ;
else
F_3 ( V_3 , V_12 -> V_42 , V_59 ) ;
F_6 ( V_3 , V_12 -> V_60 , V_61 ) ;
V_56 -> V_62 = false ;
F_21 ( V_3 ) ;
}
static void F_22 ( struct V_2 * V_3 )
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
V_57 = F_19 ( V_3 -> V_7 + V_12 -> V_18 ,
V_18 ,
( V_18 & V_65 ) ,
10 , 100 ) ;
if ( V_57 )
F_20 ( V_3 -> V_33 , L_2 ) ;
F_3 ( V_3 , V_12 -> V_66 , V_67 ) ;
F_5 ( V_64 -> V_68 [ V_64 -> V_69 ] , V_3 -> V_7 + V_12 -> V_70 ) ;
V_64 -> V_69 = ( V_64 -> V_69 + 1 ) & ( V_71 - 1 ) ;
V_3 -> V_36 . V_72 ++ ;
}
static void F_23 ( struct V_2 * V_3 )
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
V_75 = F_24 ( V_64 ) ;
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
V_74 = F_25 ( V_56 -> V_82 ,
V_56 -> V_83 ,
V_75 ,
V_84 ,
V_85 ) ;
if ( ! V_74 ) {
for ( V_76 = V_75 ; V_76 > 0 ; V_76 -- )
F_22 ( V_3 ) ;
return;
}
V_74 -> V_86 = F_18 ;
V_74 -> V_87 = V_3 ;
V_20 = F_26 ( V_74 ) ;
F_27 ( V_56 -> V_82 ) ;
F_6 ( V_3 , V_12 -> V_18 , V_58 ) ;
F_3 ( V_3 , V_12 -> V_60 , V_61 ) ;
V_64 -> V_69 = ( V_64 -> V_69 + V_75 ) & ( V_71 - 1 ) ;
V_3 -> V_36 . V_72 += V_75 ;
}
static void F_21 ( struct V_2 * V_3 )
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
if ( F_28 ( V_3 ) ) {
F_29 ( V_3 ) ;
return;
}
if ( F_30 ( V_64 ) ) {
F_29 ( V_3 ) ;
return;
}
if ( V_1 -> V_82 )
F_23 ( V_3 ) ;
else
F_22 ( V_3 ) ;
if ( F_24 ( V_64 ) < V_89 )
F_31 ( V_3 ) ;
if ( F_30 ( V_64 ) )
F_29 ( V_3 ) ;
}
static T_4 F_32 ( int V_90 , void * V_91 )
{
struct V_2 * V_3 = V_91 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_11 * V_12 = & V_1 -> V_13 -> V_12 ;
T_1 V_8 ;
F_17 ( & V_3 -> V_54 ) ;
V_8 = F_4 ( V_3 -> V_7 + V_12 -> V_18 ) ;
if ( ( V_8 & V_23 ) && ! ( V_1 -> V_19 ) )
F_10 ( V_3 , false ) ;
if ( ( V_8 & V_65 ) && ! ( V_1 -> V_82 ) )
F_21 ( V_3 ) ;
F_15 ( & V_3 -> V_54 ) ;
if ( V_1 -> V_19 )
return V_92 ;
else
return V_93 ;
}
static T_4 F_33 ( int V_90 , void * V_91 )
{
struct V_2 * V_3 = V_91 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_17 ( & V_3 -> V_54 ) ;
if ( V_1 -> V_19 )
F_10 ( V_3 , true ) ;
F_15 ( & V_3 -> V_54 ) ;
return V_93 ;
}
static unsigned int F_34 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_11 * V_12 = & V_1 -> V_13 -> V_12 ;
return F_4 ( V_3 -> V_7 + V_12 -> V_18 ) & V_65 ;
}
static void F_35 ( struct V_2 * V_3 , unsigned int V_94 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_11 * V_12 = & V_1 -> V_13 -> V_12 ;
if ( ( V_94 & V_95 ) && ( V_3 -> V_15 & V_96 ) )
F_3 ( V_3 , V_12 -> V_60 , V_97 ) ;
else
F_6 ( V_3 , V_12 -> V_60 , V_97 ) ;
}
static unsigned int F_36 ( struct V_2 * V_3 )
{
return V_98 | V_99 | V_100 ;
}
static void F_29 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_11 * V_12 = & V_1 -> V_13 -> V_12 ;
F_6 ( V_3 , V_12 -> V_66 , V_67 ) ;
}
static void F_37 ( struct V_2 * V_3 )
{
struct V_63 * V_64 = & V_3 -> V_17 -> V_64 ;
if ( F_30 ( V_64 ) )
return;
F_21 ( V_3 ) ;
}
static void F_38 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_11 * V_12 = & V_1 -> V_13 -> V_12 ;
unsigned long V_101 ;
F_39 ( & V_3 -> V_54 , V_101 ) ;
F_6 ( V_3 , V_12 -> V_66 , V_102 ) ;
F_40 ( & V_3 -> V_54 , V_101 ) ;
}
static void F_41 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_11 * V_12 = & V_1 -> V_13 -> V_12 ;
unsigned long V_101 ;
F_39 ( & V_3 -> V_54 , V_101 ) ;
F_3 ( V_3 , V_12 -> V_66 , V_102 ) ;
F_40 ( & V_3 -> V_54 , V_101 ) ;
}
static void F_42 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_11 * V_12 = & V_1 -> V_13 -> V_12 ;
F_6 ( V_3 , V_12 -> V_66 , V_102 ) ;
}
static void F_43 ( struct V_2 * V_3 , int V_103 )
{
}
static int F_44 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_11 * V_12 = & V_1 -> V_13 -> V_12 ;
const char * V_104 = F_45 ( V_3 -> V_33 ) -> V_104 ;
T_1 V_6 ;
int V_57 ;
V_57 = F_46 ( V_3 -> V_90 , F_32 ,
F_33 ,
V_105 , V_104 , V_3 ) ;
if ( V_57 )
return V_57 ;
V_6 = V_102 | V_106 | V_107 ;
F_3 ( V_3 , V_12 -> V_66 , V_6 ) ;
return 0 ;
}
static void F_47 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_11 * V_12 = & V_1 -> V_13 -> V_12 ;
struct V_108 * V_109 = & V_1 -> V_13 -> V_109 ;
T_1 V_6 ;
V_6 = V_67 | V_102 | V_106 | V_107 ;
V_6 |= F_48 ( V_109 -> V_110 ) ;
F_6 ( V_3 , V_12 -> V_66 , V_6 ) ;
F_49 ( V_3 -> V_90 , V_3 ) ;
}
static void F_50 ( struct V_2 * V_3 , struct V_111 * V_112 ,
struct V_111 * V_113 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_11 * V_12 = & V_1 -> V_13 -> V_12 ;
struct V_108 * V_109 = & V_1 -> V_13 -> V_109 ;
unsigned int V_114 ;
T_1 V_115 , V_116 , V_117 , V_118 ;
T_5 V_119 = V_112 -> V_120 ;
T_1 V_66 , V_121 , V_60 ;
unsigned long V_101 ;
if ( ! V_1 -> V_122 )
V_119 &= ~ V_123 ;
V_114 = F_51 ( V_3 , V_112 , V_113 , 0 , V_3 -> V_124 / 8 ) ;
F_39 ( & V_3 -> V_54 , V_101 ) ;
F_5 ( 0 , V_3 -> V_7 + V_12 -> V_66 ) ;
V_66 = V_106 | V_107 | V_102 ;
V_66 |= F_48 ( V_109 -> V_110 ) ;
V_121 = 0 ;
V_60 = 0 ;
if ( V_119 & V_125 )
V_121 |= V_126 ;
if ( V_119 & V_127 ) {
V_66 |= V_128 ;
if ( ( V_119 & V_129 ) == V_130 ) {
if ( V_109 -> V_131 )
V_66 |= V_132 ;
else
V_66 |= V_133 ;
}
}
if ( V_119 & V_134 )
V_66 |= V_135 ;
V_3 -> V_15 &= ~ ( V_136 | V_96 ) ;
if ( V_119 & V_123 ) {
V_3 -> V_15 |= V_136 | V_96 ;
V_60 |= V_137 ;
}
V_115 = F_52 ( V_3 -> V_124 , V_114 ) ;
if ( V_115 < 16 ) {
V_118 = 8 ;
F_3 ( V_3 , V_12 -> V_66 , V_138 ) ;
} else {
V_118 = 16 ;
F_6 ( V_3 , V_12 -> V_66 , V_138 ) ;
}
V_116 = ( V_115 / V_118 ) << V_139 ;
V_117 = V_115 % V_118 ;
F_5 ( V_116 | V_117 , V_3 -> V_7 + V_12 -> V_140 ) ;
F_53 ( V_3 , V_119 , V_114 ) ;
V_3 -> V_50 = V_41 ;
if ( V_112 -> V_141 & V_142 )
V_3 -> V_50 |= V_46 | V_48 ;
if ( V_112 -> V_141 & ( V_143 | V_144 | V_145 ) )
V_3 -> V_50 |= V_39 ;
V_3 -> V_146 = 0 ;
if ( V_112 -> V_141 & V_147 )
V_3 -> V_146 = V_46 | V_48 ;
if ( V_112 -> V_141 & V_143 ) {
V_3 -> V_146 |= V_39 ;
if ( V_112 -> V_141 & V_147 )
V_3 -> V_146 |= V_41 ;
}
if ( ( V_112 -> V_120 & V_148 ) == 0 )
V_3 -> V_146 |= V_34 ;
if ( V_1 -> V_19 )
V_60 |= V_149 ;
F_5 ( V_60 , V_3 -> V_7 + V_12 -> V_60 ) ;
F_5 ( V_121 , V_3 -> V_7 + V_12 -> V_121 ) ;
F_5 ( V_66 , V_3 -> V_7 + V_12 -> V_66 ) ;
F_40 ( & V_3 -> V_54 , V_101 ) ;
}
static const char * F_54 ( struct V_2 * V_3 )
{
return ( V_3 -> type == V_150 ) ? V_151 : NULL ;
}
static void F_55 ( struct V_2 * V_3 )
{
}
static int F_56 ( struct V_2 * V_3 )
{
return 0 ;
}
static void F_57 ( struct V_2 * V_3 , int V_101 )
{
if ( V_101 & V_152 )
V_3 -> type = V_150 ;
}
static int
F_58 ( struct V_2 * V_3 , struct V_153 * V_154 )
{
return - V_155 ;
}
static void F_59 ( struct V_2 * V_3 , unsigned int V_17 ,
unsigned int V_156 )
{
struct V_1 * V_56 = F_2 ( V_3 ,
struct V_1 , V_3 ) ;
struct V_11 * V_12 = & V_56 -> V_13 -> V_12 ;
struct V_108 * V_109 = & V_56 -> V_13 -> V_109 ;
unsigned long V_101 = 0 ;
switch ( V_17 ) {
case V_157 :
F_60 ( V_56 -> V_158 ) ;
break;
case V_159 :
F_39 ( & V_3 -> V_54 , V_101 ) ;
F_6 ( V_3 , V_12 -> V_66 , F_48 ( V_109 -> V_110 ) ) ;
F_40 ( & V_3 -> V_54 , V_101 ) ;
F_61 ( V_56 -> V_158 ) ;
break;
}
}
static int F_62 ( struct V_1 * V_56 ,
struct V_160 * V_161 )
{
struct V_2 * V_3 = & V_56 -> V_3 ;
struct V_162 * V_163 ;
int V_57 ;
V_3 -> V_164 = V_165 ;
V_3 -> V_101 = V_166 ;
V_3 -> V_167 = & V_168 ;
V_3 -> V_33 = & V_161 -> V_33 ;
V_3 -> V_90 = F_63 ( V_161 , 0 ) ;
V_163 = F_64 ( V_161 , V_169 , 0 ) ;
V_3 -> V_7 = F_65 ( & V_161 -> V_33 , V_163 ) ;
if ( F_66 ( V_3 -> V_7 ) )
return F_67 ( V_3 -> V_7 ) ;
V_3 -> V_170 = V_163 -> V_171 ;
F_68 ( & V_3 -> V_54 ) ;
V_56 -> V_158 = F_69 ( & V_161 -> V_33 , NULL ) ;
if ( F_66 ( V_56 -> V_158 ) )
return F_67 ( V_56 -> V_158 ) ;
V_57 = F_60 ( V_56 -> V_158 ) ;
if ( V_57 )
return V_57 ;
V_56 -> V_3 . V_124 = F_70 ( V_56 -> V_158 ) ;
if ( ! V_56 -> V_3 . V_124 )
V_57 = - V_155 ;
return V_57 ;
}
static struct V_1 * F_71 ( struct V_160 * V_161 )
{
struct V_172 * V_173 = V_161 -> V_33 . V_174 ;
int V_175 ;
if ( ! V_173 )
return NULL ;
V_175 = F_72 ( V_173 , L_3 ) ;
if ( V_175 < 0 )
V_175 = 0 ;
if ( F_73 ( V_175 >= V_176 ) )
return NULL ;
V_177 [ V_175 ] . V_122 = F_74 ( V_173 ,
L_4 ) ;
V_177 [ V_175 ] . V_3 . line = V_175 ;
return & V_177 [ V_175 ] ;
}
static int F_75 ( struct V_1 * V_56 ,
struct V_160 * V_161 )
{
struct V_11 * V_12 = & V_56 -> V_13 -> V_12 ;
struct V_2 * V_3 = & V_56 -> V_3 ;
struct V_178 * V_33 = & V_161 -> V_33 ;
struct V_179 V_180 ;
struct V_73 * V_74 = NULL ;
T_2 V_20 ;
int V_57 ;
V_56 -> V_19 = F_76 ( V_33 , L_5 ) ;
if ( ! V_56 -> V_19 ) {
F_77 ( V_33 , L_6 ) ;
return - V_181 ;
}
V_56 -> V_25 = F_78 ( & V_161 -> V_33 , V_26 ,
& V_56 -> V_182 ,
V_183 ) ;
if ( ! V_56 -> V_25 ) {
V_57 = - V_184 ;
goto V_185;
}
memset ( & V_180 , 0 , sizeof( V_180 ) ) ;
V_180 . V_186 = V_3 -> V_170 + V_12 -> V_27 ;
V_180 . V_187 = V_188 ;
V_57 = F_79 ( V_56 -> V_19 , & V_180 ) ;
if ( V_57 < 0 ) {
F_20 ( V_33 , L_7 ) ;
V_57 = - V_181 ;
goto V_189;
}
V_74 = F_80 ( V_56 -> V_19 ,
V_56 -> V_182 ,
V_26 , V_190 , V_191 ,
V_85 ) ;
if ( ! V_74 ) {
F_20 ( V_33 , L_8 ) ;
V_57 = - V_181 ;
goto V_189;
}
V_74 -> V_86 = NULL ;
V_74 -> V_87 = NULL ;
V_20 = F_26 ( V_74 ) ;
F_27 ( V_56 -> V_19 ) ;
return 0 ;
V_189:
F_81 ( & V_161 -> V_33 ,
V_26 , V_56 -> V_25 ,
V_56 -> V_182 ) ;
V_185:
F_82 ( V_56 -> V_19 ) ;
V_56 -> V_19 = NULL ;
return V_57 ;
}
static int F_83 ( struct V_1 * V_56 ,
struct V_160 * V_161 )
{
struct V_11 * V_12 = & V_56 -> V_13 -> V_12 ;
struct V_2 * V_3 = & V_56 -> V_3 ;
struct V_178 * V_33 = & V_161 -> V_33 ;
struct V_179 V_180 ;
int V_57 ;
V_56 -> V_62 = false ;
V_56 -> V_82 = F_76 ( V_33 , L_9 ) ;
if ( ! V_56 -> V_82 ) {
F_77 ( V_33 , L_10 ) ;
return - V_181 ;
}
V_56 -> V_79 = F_78 ( & V_161 -> V_33 , V_77 ,
& V_56 -> V_83 ,
V_183 ) ;
if ( ! V_56 -> V_79 ) {
V_57 = - V_184 ;
goto V_185;
}
memset ( & V_180 , 0 , sizeof( V_180 ) ) ;
V_180 . V_192 = V_3 -> V_170 + V_12 -> V_70 ;
V_180 . V_193 = V_188 ;
V_57 = F_79 ( V_56 -> V_82 , & V_180 ) ;
if ( V_57 < 0 ) {
F_20 ( V_33 , L_11 ) ;
V_57 = - V_181 ;
goto V_189;
}
return 0 ;
V_189:
F_81 ( & V_161 -> V_33 ,
V_77 , V_56 -> V_79 ,
V_56 -> V_83 ) ;
V_185:
F_82 ( V_56 -> V_82 ) ;
V_56 -> V_82 = NULL ;
return V_57 ;
}
static int F_84 ( struct V_160 * V_161 )
{
const struct V_194 * V_195 ;
struct V_1 * V_56 ;
int V_57 ;
V_56 = F_71 ( V_161 ) ;
if ( ! V_56 )
return - V_181 ;
V_195 = F_85 ( V_196 , & V_161 -> V_33 ) ;
if ( V_195 && V_195 -> V_197 )
V_56 -> V_13 = (struct V_198 * ) V_195 -> V_197 ;
else
return - V_155 ;
V_57 = F_62 ( V_56 , V_161 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_86 ( & V_199 , & V_56 -> V_3 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_75 ( V_56 , V_161 ) ;
if ( V_57 )
F_77 ( & V_161 -> V_33 , L_12 ) ;
V_57 = F_83 ( V_56 , V_161 ) ;
if ( V_57 )
F_77 ( & V_161 -> V_33 , L_13 ) ;
F_87 ( V_161 , & V_56 -> V_3 ) ;
return 0 ;
}
static int F_88 ( struct V_160 * V_161 )
{
struct V_2 * V_3 = F_89 ( V_161 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_11 * V_12 = & V_1 -> V_13 -> V_12 ;
F_6 ( V_3 , V_12 -> V_60 , V_149 ) ;
if ( V_1 -> V_19 )
F_82 ( V_1 -> V_19 ) ;
if ( V_1 -> V_182 )
F_81 ( & V_161 -> V_33 ,
V_26 , V_1 -> V_25 ,
V_1 -> V_182 ) ;
F_6 ( V_3 , V_12 -> V_60 , V_61 ) ;
if ( V_1 -> V_82 )
F_82 ( V_1 -> V_82 ) ;
if ( V_1 -> V_83 )
F_81 ( & V_161 -> V_33 ,
V_77 , V_1 -> V_79 ,
V_1 -> V_83 ) ;
F_61 ( V_1 -> V_158 ) ;
return F_90 ( & V_199 , V_3 ) ;
}
static void F_91 ( struct V_2 * V_3 , int V_200 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_11 * V_12 = & V_1 -> V_13 -> V_12 ;
while ( ! ( F_4 ( V_3 -> V_7 + V_12 -> V_18 ) & V_65 ) )
F_92 () ;
F_5 ( V_200 , V_3 -> V_7 + V_12 -> V_70 ) ;
}
static void F_93 ( struct V_201 * V_202 , const char * V_203 , unsigned V_204 )
{
struct V_2 * V_3 = & V_177 [ V_202 -> V_205 ] . V_3 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_11 * V_12 = & V_1 -> V_13 -> V_12 ;
struct V_108 * V_109 = & V_1 -> V_13 -> V_109 ;
unsigned long V_101 ;
T_1 V_206 , V_207 ;
int V_208 = 1 ;
F_94 ( V_101 ) ;
if ( V_3 -> V_209 )
V_208 = 0 ;
else if ( V_210 )
V_208 = F_95 ( & V_3 -> V_54 ) ;
else
F_17 ( & V_3 -> V_54 ) ;
V_206 = F_4 ( V_3 -> V_7 + V_12 -> V_66 ) ;
V_207 = V_206 & ~ V_211 ;
V_207 |= V_106 | F_48 ( V_109 -> V_110 ) ;
F_5 ( V_207 , V_3 -> V_7 + V_12 -> V_66 ) ;
F_96 ( V_3 , V_203 , V_204 , F_91 ) ;
F_5 ( V_206 , V_3 -> V_7 + V_12 -> V_66 ) ;
if ( V_208 )
F_15 ( & V_3 -> V_54 ) ;
F_97 ( V_101 ) ;
}
static int F_98 ( struct V_201 * V_202 , char * V_212 )
{
struct V_1 * V_56 ;
int V_114 = 9600 ;
int V_5 = 8 ;
int V_47 = 'n' ;
int V_213 = 'n' ;
if ( V_202 -> V_205 >= V_176 )
return - V_181 ;
V_56 = & V_177 [ V_202 -> V_205 ] ;
if ( V_56 -> V_3 . V_170 == 0 || V_56 -> V_3 . V_7 == NULL )
return - V_214 ;
if ( V_212 )
F_99 ( V_212 , & V_114 , & V_47 , & V_5 , & V_213 ) ;
return F_100 ( & V_56 -> V_3 , V_202 , V_114 , V_47 , V_5 , V_213 ) ;
}
static int T_6 F_101 ( void )
{
static char V_215 [] V_216 = L_14 ;
int V_57 ;
F_102 ( L_15 , V_215 ) ;
V_57 = F_103 ( & V_199 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_104 ( & V_217 ) ;
if ( V_57 )
F_105 ( & V_199 ) ;
return V_57 ;
}
static void T_7 F_106 ( void )
{
F_107 ( & V_217 ) ;
F_105 ( & V_199 ) ;
}
