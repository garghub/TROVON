static int F_1 ( struct V_1 * * V_2 , T_1 * V_3 ,
void * V_4 , T_1 V_5 , T_1 V_6 , int V_7 )
{
unsigned int V_8 , V_9 = 0 ;
while ( V_5 && V_6 ) {
V_8 = F_2 ( ( * V_2 ) -> V_10 - * V_3 , V_6 ) ;
V_8 = F_2 ( V_8 , V_5 ) ;
if ( ! V_8 )
return V_9 ;
F_3 ( V_4 + V_9 , * V_2 , * V_3 , V_8 , V_7 ) ;
V_9 += V_8 ;
V_5 -= V_8 ;
* V_3 += V_8 ;
V_6 -= V_8 ;
if ( * V_3 == ( * V_2 ) -> V_10 ) {
* V_2 = F_4 ( * V_2 ) ;
if ( * V_2 )
* V_3 = 0 ;
else
V_6 = 0 ;
}
}
return V_9 ;
}
static inline T_2 F_5 ( struct V_11 * V_12 , T_2 V_3 )
{
return F_6 ( V_12 -> V_13 + V_3 ) ;
}
static inline void F_7 ( struct V_11 * V_12 ,
T_2 V_3 , T_2 V_14 )
{
F_8 ( V_14 , V_12 -> V_13 + V_3 ) ;
}
static void F_9 ( struct V_11 * V_12 , T_2 V_3 ,
T_2 * V_14 , int V_8 )
{
for (; V_8 -- ; V_14 ++ , V_3 += 4 )
F_7 ( V_12 , V_3 , * V_14 ) ;
}
static struct V_11 * F_10 ( struct V_15 * V_16 )
{
struct V_11 * V_17 = NULL ;
struct V_11 * V_18 ;
F_11 ( & V_19 . V_20 ) ;
if ( ! V_16 -> V_12 ) {
F_12 (tmp, &atmel_tdes.dev_list, list) {
V_17 = V_18 ;
break;
}
V_16 -> V_12 = V_17 ;
} else {
V_17 = V_16 -> V_12 ;
}
F_13 ( & V_19 . V_20 ) ;
return V_17 ;
}
static int F_14 ( struct V_11 * V_12 )
{
F_15 ( V_12 -> V_21 ) ;
if ( ! ( V_12 -> V_22 & V_23 ) ) {
F_7 ( V_12 , V_24 , V_25 ) ;
V_12 -> V_22 |= V_23 ;
V_12 -> V_26 = 0 ;
}
return 0 ;
}
static inline unsigned int F_16 ( struct V_11 * V_12 )
{
return F_5 ( V_12 , V_27 ) & 0x00000fff ;
}
static void F_17 ( struct V_11 * V_12 )
{
F_14 ( V_12 ) ;
V_12 -> V_28 = F_16 ( V_12 ) ;
F_18 ( V_12 -> V_29 ,
L_1 , V_12 -> V_28 ) ;
F_19 ( V_12 -> V_21 ) ;
}
static void F_20 ( void * V_30 )
{
struct V_11 * V_12 = V_30 ;
F_21 ( & V_12 -> V_31 ) ;
}
static int F_22 ( struct V_11 * V_12 )
{
int V_26 ;
T_2 V_32 = 0 , V_33 = V_34 ;
V_26 = F_14 ( V_12 ) ;
if ( V_26 )
return V_26 ;
if ( ! V_12 -> V_35 . V_36 )
F_7 ( V_12 , V_37 ,
V_38 | V_39 ) ;
if ( V_12 -> V_16 -> V_40 > ( V_41 << 1 ) ) {
V_33 |= V_42 ;
V_33 |= V_43 ;
} else if ( V_12 -> V_16 -> V_40 > V_41 ) {
V_33 |= V_44 ;
V_33 |= V_43 ;
} else {
V_33 |= V_45 ;
}
if ( V_12 -> V_22 & V_46 ) {
V_33 |= V_47 ;
} else if ( V_12 -> V_22 & V_48 ) {
V_33 |= V_49 ;
if ( V_12 -> V_22 & V_50 )
V_33 |= V_51 ;
else if ( V_12 -> V_22 & V_52 )
V_33 |= V_53 ;
else if ( V_12 -> V_22 & V_54 )
V_33 |= V_55 ;
else if ( V_12 -> V_22 & V_56 )
V_33 |= V_57 ;
} else if ( V_12 -> V_22 & V_58 ) {
V_33 |= V_59 ;
}
if ( ( V_12 -> V_22 & V_60 ) || ( V_12 -> V_22 & V_58 ) )
V_33 |= V_61 ;
F_7 ( V_12 , V_24 , V_32 ) ;
F_7 ( V_12 , V_62 , V_33 ) ;
F_9 ( V_12 , V_63 , V_12 -> V_16 -> V_64 ,
V_12 -> V_16 -> V_40 >> 2 ) ;
if ( ( ( V_12 -> V_22 & V_46 ) || ( V_12 -> V_22 & V_48 ) ||
( V_12 -> V_22 & V_58 ) ) && V_12 -> V_65 -> V_66 ) {
F_9 ( V_12 , V_67 , V_12 -> V_65 -> V_66 , 2 ) ;
}
return 0 ;
}
static int F_23 ( struct V_11 * V_12 )
{
int V_26 = 0 ;
T_1 V_8 ;
F_7 ( V_12 , V_37 , V_38 | V_39 ) ;
if ( V_12 -> V_22 & V_68 ) {
F_24 ( V_12 -> V_29 , V_12 -> V_69 , 1 , V_70 ) ;
F_24 ( V_12 -> V_29 , V_12 -> V_71 , 1 , V_72 ) ;
} else {
F_25 ( V_12 -> V_29 , V_12 -> V_73 ,
V_12 -> V_74 , V_70 ) ;
V_8 = F_1 ( & V_12 -> V_69 , & V_12 -> V_75 ,
V_12 -> V_76 , V_12 -> V_5 , V_12 -> V_74 , 1 ) ;
if ( V_8 != V_12 -> V_74 ) {
V_26 = - V_77 ;
F_26 ( L_2 , V_8 ) ;
}
}
return V_26 ;
}
static int F_27 ( struct V_11 * V_12 )
{
int V_26 = - V_78 ;
V_12 -> V_79 = ( void * ) F_28 ( V_80 , 0 ) ;
V_12 -> V_76 = ( void * ) F_28 ( V_80 , 0 ) ;
V_12 -> V_5 = V_81 ;
V_12 -> V_5 &= ~ ( V_82 - 1 ) ;
if ( ! V_12 -> V_79 || ! V_12 -> V_76 ) {
F_29 ( V_12 -> V_29 , L_3 ) ;
goto V_83;
}
V_12 -> V_84 = F_30 ( V_12 -> V_29 , V_12 -> V_79 ,
V_12 -> V_5 , V_72 ) ;
if ( F_31 ( V_12 -> V_29 , V_12 -> V_84 ) ) {
F_29 ( V_12 -> V_29 , L_4 , V_12 -> V_5 ) ;
V_26 = - V_77 ;
goto V_85;
}
V_12 -> V_73 = F_30 ( V_12 -> V_29 , V_12 -> V_76 ,
V_12 -> V_5 , V_70 ) ;
if ( F_31 ( V_12 -> V_29 , V_12 -> V_73 ) ) {
F_29 ( V_12 -> V_29 , L_4 , V_12 -> V_5 ) ;
V_26 = - V_77 ;
goto V_86;
}
return 0 ;
V_86:
F_32 ( V_12 -> V_29 , V_12 -> V_84 , V_12 -> V_5 ,
V_72 ) ;
V_85:
F_33 ( ( unsigned long ) V_12 -> V_76 ) ;
F_33 ( ( unsigned long ) V_12 -> V_79 ) ;
V_83:
if ( V_26 )
F_26 ( L_5 , V_26 ) ;
return V_26 ;
}
static void F_34 ( struct V_11 * V_12 )
{
F_32 ( V_12 -> V_29 , V_12 -> V_73 , V_12 -> V_5 ,
V_70 ) ;
F_32 ( V_12 -> V_29 , V_12 -> V_84 , V_12 -> V_5 ,
V_72 ) ;
F_33 ( ( unsigned long ) V_12 -> V_76 ) ;
F_33 ( ( unsigned long ) V_12 -> V_79 ) ;
}
static int F_35 ( struct V_87 * V_88 , T_3 V_84 ,
T_3 V_73 , int V_10 )
{
struct V_15 * V_16 = F_36 ( V_88 ) ;
struct V_11 * V_12 = V_16 -> V_12 ;
int V_89 ;
V_12 -> V_74 = V_10 ;
if ( ! ( V_12 -> V_22 & V_68 ) ) {
F_25 ( V_12 -> V_29 , V_84 , V_10 ,
V_72 ) ;
}
if ( ( V_12 -> V_22 & V_48 ) && ( V_12 -> V_22 & V_50 ) )
V_89 = F_37 ( V_10 , sizeof( V_90 ) ) ;
else if ( ( V_12 -> V_22 & V_48 ) && ( V_12 -> V_22 & V_52 ) )
V_89 = F_37 ( V_10 , sizeof( V_91 ) ) ;
else
V_89 = F_37 ( V_10 , sizeof( T_2 ) ) ;
F_7 ( V_12 , V_37 , V_38 | V_39 ) ;
F_7 ( V_12 , V_92 , V_84 ) ;
F_7 ( V_12 , V_93 , V_89 ) ;
F_7 ( V_12 , V_94 , V_73 ) ;
F_7 ( V_12 , V_95 , V_89 ) ;
F_7 ( V_12 , V_96 , V_97 ) ;
F_7 ( V_12 , V_37 , V_98 | V_99 ) ;
return 0 ;
}
static int F_38 ( struct V_87 * V_88 , T_3 V_84 ,
T_3 V_73 , int V_10 )
{
struct V_15 * V_16 = F_36 ( V_88 ) ;
struct V_11 * V_12 = V_16 -> V_12 ;
struct V_1 V_2 [ 2 ] ;
struct V_100 * V_101 , * V_102 ;
V_12 -> V_74 = V_10 ;
if ( ! ( V_12 -> V_22 & V_68 ) ) {
F_25 ( V_12 -> V_29 , V_84 , V_10 ,
V_72 ) ;
}
if ( V_12 -> V_22 & V_50 ) {
V_12 -> V_103 . V_104 . V_105 =
V_106 ;
V_12 -> V_107 . V_104 . V_108 =
V_106 ;
} else if ( V_12 -> V_22 & V_52 ) {
V_12 -> V_103 . V_104 . V_105 =
V_109 ;
V_12 -> V_107 . V_104 . V_108 =
V_109 ;
} else {
V_12 -> V_103 . V_104 . V_105 =
V_110 ;
V_12 -> V_107 . V_104 . V_108 =
V_110 ;
}
F_39 ( V_12 -> V_103 . V_111 , & V_12 -> V_103 . V_104 ) ;
F_39 ( V_12 -> V_107 . V_111 , & V_12 -> V_107 . V_104 ) ;
V_12 -> V_22 |= V_112 ;
F_40 ( & V_2 [ 0 ] , 1 ) ;
F_41 ( & V_2 [ 0 ] ) = V_84 ;
F_42 ( & V_2 [ 0 ] ) = V_10 ;
F_40 ( & V_2 [ 1 ] , 1 ) ;
F_41 ( & V_2 [ 1 ] ) = V_73 ;
F_42 ( & V_2 [ 1 ] ) = V_10 ;
V_101 = F_43 ( V_12 -> V_103 . V_111 , & V_2 [ 0 ] ,
1 , V_113 ,
V_114 | V_115 ) ;
if ( ! V_101 )
return - V_77 ;
V_102 = F_43 ( V_12 -> V_107 . V_111 , & V_2 [ 1 ] ,
1 , V_116 ,
V_114 | V_115 ) ;
if ( ! V_102 )
return - V_77 ;
V_102 -> V_117 = F_20 ;
V_102 -> V_118 = V_12 ;
F_44 ( V_102 ) ;
F_45 ( V_12 -> V_107 . V_111 ) ;
F_44 ( V_101 ) ;
F_45 ( V_12 -> V_103 . V_111 ) ;
return 0 ;
}
static int F_46 ( struct V_11 * V_12 )
{
struct V_87 * V_88 = F_47 (
F_48 ( V_12 -> V_65 ) ) ;
int V_26 , V_119 = 0 , V_120 , V_7 ;
T_1 V_8 ;
T_3 V_121 , V_122 ;
if ( ( ! V_12 -> V_123 ) && ( ! V_12 -> V_75 ) ) {
V_120 = F_49 ( ( T_2 ) V_12 -> V_71 -> V_3 , sizeof( T_2 ) ) &&
F_49 ( V_12 -> V_71 -> V_10 , V_12 -> V_16 -> V_124 ) ;
V_7 = F_49 ( ( T_2 ) V_12 -> V_69 -> V_3 , sizeof( T_2 ) ) &&
F_49 ( V_12 -> V_69 -> V_10 , V_12 -> V_16 -> V_124 ) ;
V_119 = V_120 && V_7 ;
if ( F_42 ( V_12 -> V_71 ) != F_42 ( V_12 -> V_69 ) )
V_119 = 0 ;
}
if ( V_119 ) {
V_8 = F_2 ( V_12 -> V_6 , F_42 ( V_12 -> V_71 ) ) ;
V_8 = F_2 ( V_8 , F_42 ( V_12 -> V_69 ) ) ;
V_26 = F_50 ( V_12 -> V_29 , V_12 -> V_71 , 1 , V_72 ) ;
if ( ! V_26 ) {
F_29 ( V_12 -> V_29 , L_6 ) ;
return - V_77 ;
}
V_26 = F_50 ( V_12 -> V_29 , V_12 -> V_69 , 1 ,
V_70 ) ;
if ( ! V_26 ) {
F_29 ( V_12 -> V_29 , L_6 ) ;
F_24 ( V_12 -> V_29 , V_12 -> V_71 , 1 ,
V_72 ) ;
return - V_77 ;
}
V_121 = F_41 ( V_12 -> V_71 ) ;
V_122 = F_41 ( V_12 -> V_69 ) ;
V_12 -> V_22 |= V_68 ;
} else {
V_8 = F_1 ( & V_12 -> V_71 , & V_12 -> V_123 ,
V_12 -> V_79 , V_12 -> V_5 , V_12 -> V_6 , 0 ) ;
V_121 = V_12 -> V_84 ;
V_122 = V_12 -> V_73 ;
V_12 -> V_22 &= ~ V_68 ;
}
V_12 -> V_6 -= V_8 ;
if ( V_12 -> V_35 . V_36 )
V_26 = F_38 ( V_88 , V_121 , V_122 , V_8 ) ;
else
V_26 = F_35 ( V_88 , V_121 , V_122 , V_8 ) ;
if ( V_26 && ( V_12 -> V_22 & V_68 ) ) {
F_24 ( V_12 -> V_29 , V_12 -> V_71 , 1 , V_72 ) ;
F_24 ( V_12 -> V_29 , V_12 -> V_69 , 1 , V_72 ) ;
}
return V_26 ;
}
static void F_51 ( struct V_11 * V_12 , int V_26 )
{
struct V_125 * V_65 = V_12 -> V_65 ;
F_19 ( V_12 -> V_21 ) ;
V_12 -> V_22 &= ~ V_126 ;
V_65 -> V_127 . V_128 ( & V_65 -> V_127 , V_26 ) ;
}
static int F_52 ( struct V_11 * V_12 ,
struct V_125 * V_65 )
{
struct V_129 * V_130 , * V_131 ;
struct V_15 * V_16 ;
struct V_132 * V_133 ;
unsigned long V_22 ;
int V_26 , V_134 = 0 ;
F_53 ( & V_12 -> V_20 , V_22 ) ;
if ( V_65 )
V_134 = F_54 ( & V_12 -> V_135 , V_65 ) ;
if ( V_12 -> V_22 & V_126 ) {
F_55 ( & V_12 -> V_20 , V_22 ) ;
return V_134 ;
}
V_131 = F_56 ( & V_12 -> V_135 ) ;
V_130 = F_57 ( & V_12 -> V_135 ) ;
if ( V_130 )
V_12 -> V_22 |= V_126 ;
F_55 ( & V_12 -> V_20 , V_22 ) ;
if ( ! V_130 )
return V_134 ;
if ( V_131 )
V_131 -> V_128 ( V_131 , - V_136 ) ;
V_65 = F_58 ( V_130 ) ;
V_12 -> V_65 = V_65 ;
V_12 -> V_6 = V_65 -> V_137 ;
V_12 -> V_123 = 0 ;
V_12 -> V_71 = V_65 -> V_138 ;
V_12 -> V_75 = 0 ;
V_12 -> V_69 = V_65 -> V_139 ;
V_133 = F_59 ( V_65 ) ;
V_16 = F_60 ( F_48 ( V_65 ) ) ;
V_133 -> V_140 &= V_141 ;
V_12 -> V_22 = ( V_12 -> V_22 & ~ V_141 ) | V_133 -> V_140 ;
V_12 -> V_16 = V_16 ;
V_16 -> V_12 = V_12 ;
V_26 = F_22 ( V_12 ) ;
if ( ! V_26 )
V_26 = F_46 ( V_12 ) ;
if ( V_26 ) {
F_51 ( V_12 , V_26 ) ;
F_21 ( & V_12 -> V_142 ) ;
}
return V_134 ;
}
static int F_61 ( struct V_11 * V_12 )
{
int V_26 = - V_77 ;
T_1 V_8 ;
if ( V_12 -> V_22 & V_112 ) {
V_26 = 0 ;
if ( V_12 -> V_22 & V_68 ) {
F_24 ( V_12 -> V_29 , V_12 -> V_69 , 1 , V_70 ) ;
F_24 ( V_12 -> V_29 , V_12 -> V_71 , 1 , V_72 ) ;
} else {
F_25 ( V_12 -> V_29 , V_12 -> V_73 ,
V_12 -> V_74 , V_70 ) ;
V_8 = F_1 ( & V_12 -> V_69 , & V_12 -> V_75 ,
V_12 -> V_76 , V_12 -> V_5 , V_12 -> V_74 , 1 ) ;
if ( V_8 != V_12 -> V_74 ) {
V_26 = - V_77 ;
F_26 ( L_2 , V_8 ) ;
}
}
}
return V_26 ;
}
static int F_62 ( struct V_125 * V_65 , unsigned long V_140 )
{
struct V_15 * V_16 = F_60 (
F_48 ( V_65 ) ) ;
struct V_132 * V_133 = F_59 ( V_65 ) ;
if ( V_140 & V_50 ) {
if ( ! F_49 ( V_65 -> V_137 , V_143 ) ) {
F_26 ( L_7 ) ;
return - V_77 ;
}
V_16 -> V_124 = V_143 ;
} else if ( V_140 & V_52 ) {
if ( ! F_49 ( V_65 -> V_137 , V_144 ) ) {
F_26 ( L_8 ) ;
return - V_77 ;
}
V_16 -> V_124 = V_144 ;
} else if ( V_140 & V_54 ) {
if ( ! F_49 ( V_65 -> V_137 , V_145 ) ) {
F_26 ( L_9 ) ;
return - V_77 ;
}
V_16 -> V_124 = V_145 ;
} else {
if ( ! F_49 ( V_65 -> V_137 , V_82 ) ) {
F_26 ( L_10 ) ;
return - V_77 ;
}
V_16 -> V_124 = V_82 ;
}
V_133 -> V_140 = V_140 ;
return F_52 ( V_16 -> V_12 , V_65 ) ;
}
static bool F_63 ( struct V_146 * V_111 , void * V_147 )
{
struct V_148 * V_149 = V_147 ;
if ( V_149 && V_149 -> V_150 == V_111 -> V_151 -> V_29 ) {
V_111 -> V_152 = V_149 ;
return true ;
} else {
return false ;
}
}
static int F_64 ( struct V_11 * V_12 ,
struct V_153 * V_154 )
{
int V_26 = - V_78 ;
T_4 V_155 ;
F_65 ( V_155 ) ;
F_66 ( V_156 , V_155 ) ;
V_12 -> V_103 . V_111 = F_67 ( V_155 ,
F_63 , & V_154 -> V_157 -> V_158 , V_12 -> V_29 , L_11 ) ;
if ( ! V_12 -> V_103 . V_111 )
goto V_159;
V_12 -> V_103 . V_104 . V_160 = V_113 ;
V_12 -> V_103 . V_104 . V_161 = V_12 -> V_162 +
V_163 ;
V_12 -> V_103 . V_104 . V_164 = 1 ;
V_12 -> V_103 . V_104 . V_108 =
V_110 ;
V_12 -> V_103 . V_104 . V_165 = 1 ;
V_12 -> V_103 . V_104 . V_105 =
V_110 ;
V_12 -> V_103 . V_104 . V_166 = false ;
V_12 -> V_107 . V_111 = F_67 ( V_155 ,
F_63 , & V_154 -> V_157 -> V_167 , V_12 -> V_29 , L_12 ) ;
if ( ! V_12 -> V_107 . V_111 )
goto V_168;
V_12 -> V_107 . V_104 . V_160 = V_116 ;
V_12 -> V_107 . V_104 . V_169 = V_12 -> V_162 +
V_170 ;
V_12 -> V_107 . V_104 . V_164 = 1 ;
V_12 -> V_107 . V_104 . V_108 =
V_110 ;
V_12 -> V_107 . V_104 . V_165 = 1 ;
V_12 -> V_107 . V_104 . V_105 =
V_110 ;
V_12 -> V_107 . V_104 . V_166 = false ;
return 0 ;
V_168:
F_68 ( V_12 -> V_103 . V_111 ) ;
V_159:
F_69 ( V_12 -> V_29 , L_13 ) ;
return V_26 ;
}
static void F_70 ( struct V_11 * V_12 )
{
F_68 ( V_12 -> V_103 . V_111 ) ;
F_68 ( V_12 -> V_107 . V_111 ) ;
}
static int F_71 ( struct V_171 * V_88 , const V_90 * V_64 ,
unsigned int V_40 )
{
T_2 V_18 [ V_172 ] ;
int V_26 ;
struct V_87 * V_173 = F_47 ( V_88 ) ;
struct V_15 * V_16 = F_60 ( V_88 ) ;
if ( V_40 != V_41 ) {
F_72 ( V_88 , V_174 ) ;
return - V_77 ;
}
V_26 = F_73 ( V_18 , V_64 ) ;
if ( V_26 == 0 && ( V_173 -> V_175 & V_176 ) ) {
V_173 -> V_175 |= V_177 ;
return - V_77 ;
}
memcpy ( V_16 -> V_64 , V_64 , V_40 ) ;
V_16 -> V_40 = V_40 ;
return 0 ;
}
static int F_74 ( struct V_171 * V_88 , const V_90 * V_64 ,
unsigned int V_40 )
{
struct V_15 * V_16 = F_60 ( V_88 ) ;
const char * V_178 ;
V_178 = F_75 ( F_47 ( V_88 ) ) ;
if ( ! V_16 -> V_12 -> V_35 . V_179 && strstr ( V_178 , L_14 )
&& ( V_40 != 2 * V_41 ) ) {
F_72 ( V_88 , V_174 ) ;
return - V_77 ;
} else if ( ( V_40 != 2 * V_41 ) && ( V_40 != 3 * V_41 ) ) {
F_72 ( V_88 , V_174 ) ;
return - V_77 ;
}
memcpy ( V_16 -> V_64 , V_64 , V_40 ) ;
V_16 -> V_40 = V_40 ;
return 0 ;
}
static int F_76 ( struct V_125 * V_65 )
{
return F_62 ( V_65 , V_60 ) ;
}
static int F_77 ( struct V_125 * V_65 )
{
return F_62 ( V_65 , 0 ) ;
}
static int F_78 ( struct V_125 * V_65 )
{
return F_62 ( V_65 , V_60 | V_46 ) ;
}
static int F_79 ( struct V_125 * V_65 )
{
return F_62 ( V_65 , V_46 ) ;
}
static int F_80 ( struct V_125 * V_65 )
{
return F_62 ( V_65 , V_60 | V_48 ) ;
}
static int F_81 ( struct V_125 * V_65 )
{
return F_62 ( V_65 , V_48 ) ;
}
static int F_82 ( struct V_125 * V_65 )
{
return F_62 ( V_65 , V_60 | V_48 |
V_50 ) ;
}
static int F_83 ( struct V_125 * V_65 )
{
return F_62 ( V_65 , V_48 | V_50 ) ;
}
static int F_84 ( struct V_125 * V_65 )
{
return F_62 ( V_65 , V_60 | V_48 |
V_52 ) ;
}
static int F_85 ( struct V_125 * V_65 )
{
return F_62 ( V_65 , V_48 | V_52 ) ;
}
static int F_86 ( struct V_125 * V_65 )
{
return F_62 ( V_65 , V_60 | V_48 |
V_54 ) ;
}
static int F_87 ( struct V_125 * V_65 )
{
return F_62 ( V_65 , V_48 | V_54 ) ;
}
static int F_88 ( struct V_125 * V_65 )
{
return F_62 ( V_65 , V_60 | V_58 ) ;
}
static int F_89 ( struct V_125 * V_65 )
{
return F_62 ( V_65 , V_58 ) ;
}
static int F_90 ( struct V_87 * V_88 )
{
struct V_15 * V_16 = F_36 ( V_88 ) ;
struct V_11 * V_12 ;
V_88 -> V_180 . V_181 = sizeof( struct V_132 ) ;
V_12 = F_10 ( V_16 ) ;
if ( ! V_12 )
return - V_182 ;
return 0 ;
}
static void F_91 ( struct V_87 * V_88 )
{
}
static void F_92 ( unsigned long V_30 )
{
struct V_11 * V_12 = (struct V_11 * ) V_30 ;
F_52 ( V_12 , NULL ) ;
}
static void F_93 ( unsigned long V_30 )
{
struct V_11 * V_12 = (struct V_11 * ) V_30 ;
int V_26 ;
if ( ! ( V_12 -> V_22 & V_112 ) )
V_26 = F_23 ( V_12 ) ;
else
V_26 = F_61 ( V_12 ) ;
V_26 = V_12 -> V_26 ? : V_26 ;
if ( V_12 -> V_6 && ! V_26 ) {
if ( V_12 -> V_22 & V_68 ) {
V_12 -> V_71 = F_4 ( V_12 -> V_71 ) ;
V_12 -> V_69 = F_4 ( V_12 -> V_69 ) ;
if ( ! V_12 -> V_71 || ! V_12 -> V_69 )
V_26 = - V_77 ;
}
if ( ! V_26 )
V_26 = F_46 ( V_12 ) ;
if ( ! V_26 )
return;
}
F_51 ( V_12 , V_26 ) ;
F_52 ( V_12 , NULL ) ;
}
static T_5 F_94 ( int V_183 , void * V_184 )
{
struct V_11 * V_17 = V_184 ;
T_2 V_185 ;
V_185 = F_5 ( V_17 , V_186 ) ;
if ( V_185 & F_5 ( V_17 , V_187 ) ) {
F_7 ( V_17 , V_188 , V_185 ) ;
if ( V_126 & V_17 -> V_22 )
F_21 ( & V_17 -> V_31 ) ;
else
F_69 ( V_17 -> V_29 , L_15 ) ;
return V_189 ;
}
return V_190 ;
}
static void F_95 ( struct V_11 * V_12 )
{
int V_191 ;
for ( V_191 = 0 ; V_191 < F_96 ( V_192 ) ; V_191 ++ )
F_97 ( & V_192 [ V_191 ] ) ;
}
static int F_98 ( struct V_11 * V_12 )
{
int V_26 , V_191 , V_193 ;
for ( V_191 = 0 ; V_191 < F_96 ( V_192 ) ; V_191 ++ ) {
V_26 = F_99 ( & V_192 [ V_191 ] ) ;
if ( V_26 )
goto V_194;
}
return 0 ;
V_194:
for ( V_193 = 0 ; V_193 < V_191 ; V_193 ++ )
F_97 ( & V_192 [ V_193 ] ) ;
return V_26 ;
}
static void F_100 ( struct V_11 * V_12 )
{
V_12 -> V_35 . V_36 = 0 ;
V_12 -> V_35 . V_179 = 0 ;
switch ( V_12 -> V_28 & 0xf00 ) {
case 0x700 :
V_12 -> V_35 . V_36 = 1 ;
V_12 -> V_35 . V_179 = 1 ;
break;
case 0x600 :
break;
default:
F_69 ( V_12 -> V_29 ,
L_16 ) ;
break;
}
}
static struct V_153 * F_101 ( struct V_195 * V_196 )
{
struct V_197 * V_198 = V_196 -> V_29 . V_199 ;
struct V_153 * V_154 ;
if ( ! V_198 ) {
F_29 ( & V_196 -> V_29 , L_17 ) ;
return F_102 ( - V_77 ) ;
}
V_154 = F_103 ( & V_196 -> V_29 , sizeof( * V_154 ) , V_80 ) ;
if ( ! V_154 ) {
F_29 ( & V_196 -> V_29 , L_18 ) ;
return F_102 ( - V_78 ) ;
}
V_154 -> V_157 = F_103 ( & V_196 -> V_29 ,
sizeof( * ( V_154 -> V_157 ) ) ,
V_80 ) ;
if ( ! V_154 -> V_157 ) {
F_29 ( & V_196 -> V_29 , L_19 ) ;
return F_102 ( - V_78 ) ;
}
return V_154 ;
}
static inline struct V_153 * F_101 ( struct V_195 * V_196 )
{
return F_102 ( - V_77 ) ;
}
static int F_104 ( struct V_195 * V_196 )
{
struct V_11 * V_17 ;
struct V_153 * V_154 ;
struct V_151 * V_29 = & V_196 -> V_29 ;
struct V_200 * V_201 ;
unsigned long V_202 ;
int V_26 ;
V_17 = F_105 ( & V_196 -> V_29 , sizeof( * V_17 ) , V_80 ) ;
if ( V_17 == NULL ) {
F_29 ( V_29 , L_20 ) ;
V_26 = - V_78 ;
goto V_203;
}
V_17 -> V_29 = V_29 ;
F_106 ( V_196 , V_17 ) ;
F_107 ( & V_17 -> V_204 ) ;
F_108 ( & V_17 -> V_31 , F_93 ,
( unsigned long ) V_17 ) ;
F_108 ( & V_17 -> V_142 , F_92 ,
( unsigned long ) V_17 ) ;
F_109 ( & V_17 -> V_135 , V_205 ) ;
V_17 -> V_183 = - 1 ;
V_201 = F_110 ( V_196 , V_206 , 0 ) ;
if ( ! V_201 ) {
F_29 ( V_29 , L_21 ) ;
V_26 = - V_182 ;
goto V_207;
}
V_17 -> V_162 = V_201 -> V_208 ;
V_202 = F_111 ( V_201 ) ;
V_17 -> V_183 = F_112 ( V_196 , 0 ) ;
if ( V_17 -> V_183 < 0 ) {
F_29 ( V_29 , L_22 ) ;
V_26 = V_17 -> V_183 ;
goto V_207;
}
V_26 = F_113 ( V_17 -> V_183 , F_94 , V_209 ,
L_23 , V_17 ) ;
if ( V_26 ) {
F_29 ( V_29 , L_24 ) ;
goto V_210;
}
V_17 -> V_21 = F_114 ( & V_196 -> V_29 , L_25 ) ;
if ( F_115 ( V_17 -> V_21 ) ) {
F_29 ( V_29 , L_26 ) ;
V_26 = F_116 ( V_17 -> V_21 ) ;
goto V_211;
}
V_17 -> V_13 = F_117 ( V_17 -> V_162 , V_202 ) ;
if ( ! V_17 -> V_13 ) {
F_29 ( V_29 , L_27 ) ;
V_26 = - V_78 ;
goto V_212;
}
F_17 ( V_17 ) ;
F_100 ( V_17 ) ;
V_26 = F_27 ( V_17 ) ;
if ( V_26 )
goto V_213;
if ( V_17 -> V_35 . V_36 ) {
V_154 = V_196 -> V_29 . V_214 ;
if ( ! V_154 ) {
V_154 = F_101 ( V_196 ) ;
if ( F_115 ( V_154 ) ) {
F_29 ( & V_196 -> V_29 , L_28 ) ;
V_26 = F_116 ( V_154 ) ;
goto V_215;
}
}
if ( ! V_154 -> V_157 ) {
V_26 = - V_216 ;
goto V_215;
}
V_26 = F_64 ( V_17 , V_154 ) ;
if ( V_26 )
goto V_217;
F_18 ( V_29 , L_29 ,
F_118 ( V_17 -> V_103 . V_111 ) ,
F_118 ( V_17 -> V_107 . V_111 ) ) ;
}
F_119 ( & V_19 . V_20 ) ;
F_120 ( & V_17 -> V_204 , & V_19 . V_218 ) ;
F_121 ( & V_19 . V_20 ) ;
V_26 = F_98 ( V_17 ) ;
if ( V_26 )
goto V_219;
F_18 ( V_29 , L_30 ) ;
return 0 ;
V_219:
F_119 ( & V_19 . V_20 ) ;
F_122 ( & V_17 -> V_204 ) ;
F_121 ( & V_19 . V_20 ) ;
if ( V_17 -> V_35 . V_36 )
F_70 ( V_17 ) ;
V_217:
V_215:
F_34 ( V_17 ) ;
V_213:
F_123 ( V_17 -> V_13 ) ;
V_212:
F_124 ( V_17 -> V_21 ) ;
V_211:
F_125 ( V_17 -> V_183 , V_17 ) ;
V_210:
V_207:
F_126 ( & V_17 -> V_31 ) ;
F_126 ( & V_17 -> V_142 ) ;
V_203:
F_29 ( V_29 , L_31 ) ;
return V_26 ;
}
static int F_127 ( struct V_195 * V_196 )
{
static struct V_11 * V_17 ;
V_17 = F_128 ( V_196 ) ;
if ( ! V_17 )
return - V_182 ;
F_119 ( & V_19 . V_20 ) ;
F_122 ( & V_17 -> V_204 ) ;
F_121 ( & V_19 . V_20 ) ;
F_95 ( V_17 ) ;
F_126 ( & V_17 -> V_31 ) ;
F_126 ( & V_17 -> V_142 ) ;
if ( V_17 -> V_35 . V_36 )
F_70 ( V_17 ) ;
F_34 ( V_17 ) ;
F_123 ( V_17 -> V_13 ) ;
F_124 ( V_17 -> V_21 ) ;
if ( V_17 -> V_183 >= 0 )
F_125 ( V_17 -> V_183 , V_17 ) ;
return 0 ;
}
