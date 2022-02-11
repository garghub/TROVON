static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_4 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_5 ;
}
static inline bool F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_6 & V_7 ;
}
static unsigned int F_4 ( const struct V_1 * V_8 ,
unsigned int V_9 )
{
return V_8 -> V_10 -> V_11 [ V_9 ] ;
}
static unsigned int F_5 ( const struct V_1 * V_8 ,
unsigned int V_9 )
{
void T_1 * V_12 = V_8 -> V_13 . V_14 + F_4 ( V_8 , V_9 ) ;
return F_6 ( V_12 ) ;
}
static void F_7 ( unsigned int V_15 , struct V_1 * V_8 ,
unsigned int V_9 )
{
void T_1 * V_12 = V_8 -> V_13 . V_14 + F_4 ( V_8 , V_9 ) ;
F_8 ( V_15 , V_12 ) ;
}
static void F_9 ( unsigned int V_15 , struct V_1 * V_8 ,
unsigned int V_9 )
{
void T_1 * V_12 = V_8 -> V_13 . V_14 + F_4 ( V_8 , V_9 ) ;
F_8 ( V_15 , V_12 + V_16 ) ;
}
static void F_10 ( unsigned int V_15 , struct V_1 * V_8 ,
unsigned int V_9 )
{
void T_1 * V_12 = V_8 -> V_13 . V_14 + F_4 ( V_8 , V_9 ) ;
F_8 ( V_15 , V_12 + V_17 ) ;
}
static void F_11 ( void * V_18 )
{
struct V_1 * V_2 = V_18 ;
struct V_19 * V_20 = & V_2 -> V_13 . V_21 -> V_20 ;
F_12 ( V_2 -> V_22 , & V_2 -> V_23 , 1 , V_24 ) ;
F_13 ( V_25 , & V_2 -> V_6 ) ;
F_14 () ;
if ( F_15 ( V_20 ) < V_26 )
F_16 ( & V_2 -> V_13 ) ;
F_17 ( V_2 ) ;
}
static int F_18 ( struct V_1 * V_2 , int V_27 )
{
struct V_28 * V_29 ;
struct V_30 * V_31 = & V_2 -> V_23 ;
struct V_32 * V_33 = V_2 -> V_34 ;
T_2 V_35 ;
V_35 = F_19 ( V_27 ) ;
V_29 = F_20 ( V_33 , (struct V_30 * ) & V_35 ,
1 , V_36 , 0 ) ;
if ( ! V_29 ) {
F_21 ( V_2 -> V_22 , L_1 ) ;
return - V_37 ;
}
F_22 ( V_31 , V_2 -> V_38 , V_27 ) ;
F_23 ( V_2 -> V_22 , V_31 , 1 , V_24 ) ;
V_29 = F_20 ( V_33 , V_31 ,
1 , V_39 , V_40 | V_41 ) ;
if ( ! V_29 ) {
F_21 ( V_2 -> V_22 , L_2 ) ;
return - V_37 ;
}
V_29 -> V_42 = F_11 ;
V_29 -> V_43 = V_2 ;
F_24 ( V_29 ) ;
F_25 ( V_33 ) ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = & V_2 -> V_13 . V_21 -> V_20 ;
if ( F_3 ( V_2 ) ) {
T_2 V_44 = 0 ;
int V_27 ;
void * V_45 = V_2 -> V_38 ;
if ( F_26 ( V_25 , & V_2 -> V_6 ) )
return;
while ( ! F_27 ( V_20 ) && ! F_28 ( & V_2 -> V_13 ) ) {
V_27 = F_29 ( T_2 , V_46 - V_44 ,
F_30 ( V_20 -> V_47 ,
V_20 -> V_48 ,
V_46 ) ) ;
memcpy ( V_45 + V_44 , V_20 -> V_49 + V_20 -> V_48 , V_27 ) ;
V_20 -> V_48 = ( V_20 -> V_48 + V_27 ) & ( V_46 - 1 ) ;
V_44 += V_27 ;
if ( V_44 >= V_46 )
break;
}
if ( F_28 ( & V_2 -> V_13 ) )
F_31 ( & V_2 -> V_13 ) ;
if ( V_44 ) {
F_18 ( V_2 , V_44 ) ;
} else {
F_13 ( V_25 , & V_2 -> V_6 ) ;
F_14 () ;
}
return;
}
while ( ! ( F_5 ( V_2 , V_50 ) & V_51 ) ) {
if ( V_2 -> V_13 . V_52 ) {
V_2 -> V_13 . V_53 . V_54 ++ ;
F_7 ( V_2 -> V_13 . V_52 , V_2 , V_55 ) ;
V_2 -> V_13 . V_52 = 0 ;
continue;
}
if ( ! F_27 ( V_20 ) && ! F_28 ( & V_2 -> V_13 ) ) {
V_2 -> V_13 . V_53 . V_54 ++ ;
F_7 ( V_20 -> V_49 [ V_20 -> V_48 ] , V_2 , V_55 ) ;
V_20 -> V_48 = ( V_20 -> V_48 + 1 ) & ( V_46 - 1 ) ;
} else
break;
}
if ( F_15 ( V_20 ) < V_26 )
F_16 ( & V_2 -> V_13 ) ;
if ( F_27 ( & ( V_2 -> V_13 . V_21 -> V_20 ) ) )
F_10 ( V_56 , V_2 , V_57 ) ;
else
F_9 ( V_56 , V_2 , V_57 ) ;
if ( F_28 ( & V_2 -> V_13 ) )
F_31 ( & V_2 -> V_13 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
int V_58 ;
T_2 V_59 ;
T_3 V_60 ;
V_60 = F_5 ( V_2 , V_55 ) ;
V_59 = F_5 ( V_2 , V_50 ) ;
V_58 = V_61 ;
V_2 -> V_13 . V_53 . V_62 ++ ;
if ( V_59 & V_63 ) {
V_2 -> V_13 . V_53 . V_64 ++ ;
if ( F_33 ( & V_2 -> V_13 ) )
goto V_65;
} else if ( V_59 & V_66 ) {
V_2 -> V_13 . V_53 . V_67 ++ ;
} else if ( V_59 & V_68 ) {
V_2 -> V_13 . V_53 . V_69 ++ ;
}
V_59 &= V_2 -> V_13 . V_70 ;
if ( V_59 & V_63 ) {
V_58 = V_71 ;
} else if ( V_59 & V_66 )
V_58 = V_72 ;
else if ( V_59 & V_68 )
V_58 = V_73 ;
if ( V_59 & V_74 )
V_2 -> V_13 . V_53 . V_75 ++ ;
if ( F_34 ( & V_2 -> V_13 , V_60 ) )
goto V_65;
F_35 ( & V_2 -> V_13 , V_59 , V_74 , V_60 , V_58 ) ;
V_65:
F_7 ( V_59 , V_2 , V_50 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
T_2 V_59 = 0 ;
for (; ; ) {
V_59 = F_5 ( V_2 , V_50 ) ;
if ( V_59 & V_76 )
break;
F_32 ( V_2 ) ;
}
F_7 ( V_59 , V_2 , V_50 ) ;
F_37 ( & V_2 -> V_13 . V_21 -> V_13 ) ;
}
static int F_38 ( struct V_77 * V_78 )
{
return 0 ;
}
static int F_39 ( struct V_77 * V_78 ,
struct V_79 * V_80 )
{
if ( V_78 -> type != V_81 && V_78 -> type != V_82 )
return - V_37 ;
return 0 ;
}
static void F_40 ( struct V_77 * V_78 , int V_6 )
{
}
static const char * F_41 ( struct V_77 * V_78 )
{
struct V_1 * V_2 = F_42 ( V_78 ) ;
return F_43 ( V_2 -> V_22 ) ;
}
static void F_44 ( struct V_77 * V_78 )
{
}
static void F_45 ( struct V_77 * V_78 , unsigned V_83 )
{
struct V_1 * V_2 = F_42 ( V_78 ) ;
T_2 V_84 = F_5 ( V_2 , V_85 ) ;
V_84 &= ~ ( V_86 | V_87 ) ;
if ( V_83 & V_88 ) {
if ( F_46 ( V_78 ) )
V_84 |= V_86 ;
else
V_84 |= V_87 ;
}
F_7 ( V_84 , V_2 , V_85 ) ;
F_47 ( V_2 -> V_89 , V_83 ) ;
}
static T_2 F_48 ( struct V_1 * V_2 , T_2 V_83 )
{
T_2 V_90 ;
V_90 = V_83 ^ V_2 -> V_91 ;
V_2 -> V_91 = V_83 ;
if ( V_90 & V_92 && V_2 -> V_93 &&
V_2 -> V_13 . V_21 != NULL ) {
if ( V_90 & V_94 )
V_2 -> V_13 . V_53 . V_95 ++ ;
if ( V_90 & V_96 )
V_2 -> V_13 . V_53 . V_97 ++ ;
if ( V_90 & V_98 )
F_49 ( & V_2 -> V_13 , V_83 & V_98 ) ;
if ( V_90 & V_99 )
F_50 ( & V_2 -> V_13 , V_83 & V_99 ) ;
F_51 ( & V_2 -> V_13 . V_21 -> V_13 . V_100 ) ;
}
return V_83 ;
}
static T_2 F_52 ( struct V_77 * V_78 )
{
struct V_1 * V_2 = F_42 ( V_78 ) ;
T_2 V_59 = F_5 ( V_2 , V_50 ) ;
T_2 V_83 = 0 ;
if ( V_59 & V_101 )
V_83 |= V_99 ;
return F_53 ( V_2 -> V_89 , & V_83 ) ;
}
static void F_54 ( struct V_77 * V_13 )
{
struct V_1 * V_2 = F_42 ( V_13 ) ;
if ( V_2 -> V_93 )
return;
V_2 -> V_93 = true ;
if ( V_2 -> V_102 [ V_103 ] >= 0 )
F_55 ( V_2 -> V_102 [ V_103 ] ) ;
if ( V_2 -> V_102 [ V_104 ] >= 0 )
F_55 ( V_2 -> V_102 [ V_104 ] ) ;
if ( V_2 -> V_102 [ V_105 ] >= 0 )
F_55 ( V_2 -> V_102 [ V_105 ] ) ;
if ( V_2 -> V_102 [ V_106 ] >= 0 )
F_55 ( V_2 -> V_102 [ V_106 ] ) ;
}
static void F_56 ( struct V_77 * V_13 )
{
struct V_1 * V_2 = F_42 ( V_13 ) ;
if ( ! V_2 -> V_93 )
return;
V_2 -> V_93 = false ;
if ( V_2 -> V_102 [ V_103 ] >= 0 )
F_57 ( V_2 -> V_102 [ V_103 ] ) ;
if ( V_2 -> V_102 [ V_104 ] >= 0 )
F_57 ( V_2 -> V_102 [ V_104 ] ) ;
if ( V_2 -> V_102 [ V_105 ] >= 0 )
F_57 ( V_2 -> V_102 [ V_105 ] ) ;
if ( V_2 -> V_102 [ V_106 ] >= 0 )
F_57 ( V_2 -> V_102 [ V_106 ] ) ;
}
static void F_58 ( void * V_107 )
{
struct V_1 * V_2 = (struct V_1 * ) V_107 ;
struct V_108 * V_13 = & V_2 -> V_13 . V_21 -> V_13 ;
int V_109 ;
T_2 V_59 ;
F_12 ( V_2 -> V_22 , & V_2 -> V_110 , 1 , V_111 ) ;
V_59 = F_5 ( V_2 , V_50 ) ;
V_59 &= ~ ( V_74 | V_63 |
V_66 | V_68 ) ;
V_109 = V_59 & V_112 ;
F_59 ( V_13 , V_2 -> V_113 , V_109 ) ;
F_7 ( V_59 , V_2 , V_50 ) ;
F_37 ( V_13 ) ;
F_60 ( V_2 ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_28 * V_29 ;
struct V_30 * V_31 = & V_2 -> V_110 ;
struct V_32 * V_33 = V_2 -> V_114 ;
T_2 V_35 [ 1 ] ;
V_35 [ 0 ] = V_115
| F_61 ( 0x80 )
| F_62 ( V_46 ) ;
V_29 = F_20 ( V_33 , (struct V_30 * ) V_35 ,
1 , V_36 , 0 ) ;
if ( ! V_29 ) {
F_21 ( V_2 -> V_22 , L_1 ) ;
return - V_37 ;
}
F_22 ( V_31 , V_2 -> V_113 , V_46 ) ;
F_23 ( V_2 -> V_22 , V_31 , 1 , V_111 ) ;
V_29 = F_20 ( V_33 , V_31 , 1 , V_116 ,
V_40 | V_41 ) ;
if ( ! V_29 ) {
F_21 ( V_2 -> V_22 , L_2 ) ;
return - 1 ;
}
V_29 -> V_42 = F_58 ;
V_29 -> V_43 = V_2 ;
F_24 ( V_29 ) ;
F_25 ( V_33 ) ;
return 0 ;
}
static void F_63 ( struct V_1 * V_2 )
{
if ( V_2 -> V_34 ) {
F_64 ( V_2 -> V_34 ) ;
V_2 -> V_34 = NULL ;
}
if ( V_2 -> V_114 ) {
F_64 ( V_2 -> V_114 ) ;
V_2 -> V_114 = NULL ;
}
F_65 ( V_2 -> V_38 ) ;
F_65 ( V_2 -> V_113 ) ;
V_2 -> V_38 = NULL ;
V_2 -> V_113 = NULL ;
}
static void F_66 ( struct V_1 * V_2 )
{
F_10 ( V_117 | V_118 | V_119 ,
V_2 , V_85 ) ;
F_63 ( V_2 ) ;
V_2 -> V_6 &= ~ V_7 ;
F_13 ( V_25 , & V_2 -> V_6 ) ;
F_13 ( V_120 , & V_2 -> V_6 ) ;
}
static int F_67 ( struct V_1 * V_2 )
{
if ( F_3 ( V_2 ) )
return 0 ;
V_2 -> V_114 = F_68 ( V_2 -> V_22 , L_3 ) ;
if ( ! V_2 -> V_114 )
goto V_121;
V_2 -> V_113 = F_69 ( V_46 , V_122 | V_123 ) ;
if ( ! V_2 -> V_113 )
goto V_121;
V_2 -> V_34 = F_68 ( V_2 -> V_22 , L_4 ) ;
if ( ! V_2 -> V_34 )
goto V_121;
V_2 -> V_38 = F_69 ( V_46 , V_122 | V_123 ) ;
if ( ! V_2 -> V_38 )
goto V_121;
V_2 -> V_6 |= V_7 ;
F_70 ( V_2 -> V_22 , L_5 ) ;
V_2 -> V_13 . V_124 = V_46 ;
return 0 ;
V_121:
F_63 ( V_2 ) ;
return - V_37 ;
}
static void F_71 ( struct V_77 * V_78 ,
struct V_125 * V_126 ,
struct V_125 * V_127 )
{
struct V_1 * V_2 = F_42 ( V_78 ) ;
T_2 V_128 , V_84 , V_129 , div ;
unsigned int V_130 , V_131 , V_132 , V_133 ;
V_130 = V_126 -> V_134 ;
V_84 = V_135 ;
V_129 = F_5 ( V_2 , V_85 ) ;
switch ( V_130 & V_136 ) {
case V_137 :
V_128 = 0 ;
break;
case V_138 :
V_128 = 1 ;
break;
case V_139 :
V_128 = 2 ;
break;
case V_140 :
V_128 = 3 ;
break;
default:
return;
}
V_84 |= F_72 ( V_128 ) ;
if ( V_130 & V_141 ) {
V_84 |= V_142 ;
if ( ( V_130 & V_143 ) == 0 )
V_84 |= V_144 ;
if ( V_130 & V_145 )
V_84 |= V_146 ;
}
V_78 -> V_70 = V_74 ;
if ( V_126 -> V_147 & V_148 )
V_78 -> V_70 |= V_66 ;
if ( V_126 -> V_147 & ( V_149 | V_150 | V_151 ) )
V_78 -> V_70 |= V_63 ;
V_78 -> V_152 = 0 ;
if ( V_126 -> V_147 & V_153 )
V_78 -> V_152 |= V_66 ;
if ( V_126 -> V_147 & V_149 ) {
V_78 -> V_152 |= V_63 ;
if ( V_126 -> V_147 & V_153 )
V_78 -> V_152 |= V_74 ;
}
if ( V_130 & V_154 )
V_129 |= V_155 ;
else
V_129 &= ~ V_155 ;
if ( V_130 & V_156 )
V_84 |= V_157 ;
V_129 &= ~ ( V_158 | V_86 ) ;
if ( V_130 & V_159 ) {
if ( F_1 ( V_2 )
&& F_73 ( V_160 , & V_2 -> V_6 ) ) {
if ( ! F_67 ( V_2 ) )
V_129 |= V_117 | V_118
| V_119 ;
}
V_129 |= V_86 ;
if ( F_74 () )
V_129 |= V_158 ;
}
if ( F_2 ( V_2 ) ) {
V_131 = F_75 ( V_78 , V_126 , V_127 ,
V_78 -> V_161 * 4 / 0x3FFFFF ,
V_78 -> V_161 / 16 ) ;
div = V_78 -> V_161 * 4 / V_131 ;
} else {
V_132 = F_76 ( V_78 -> V_161 * 32 ,
V_162 ) ;
V_133 = V_78 -> V_161 * 32 / V_163 ;
V_131 = F_75 ( V_78 , V_126 , V_127 , V_132 , V_133 ) ;
div = F_77 ( V_78 -> V_161 * 32 , V_131 ) ;
}
V_84 |= F_78 ( div & 0x3F ) ;
V_84 |= F_79 ( div >> 6 ) ;
F_7 ( V_84 , V_2 , V_164 ) ;
F_7 ( V_129 , V_2 , V_85 ) ;
F_80 ( V_78 , V_126 -> V_134 , V_131 ) ;
if ( F_3 ( V_2 ) &&
! F_26 ( V_120 , & V_2 -> V_6 ) ) {
if ( ! F_60 ( V_2 ) ) {
F_10 ( V_165 | V_166 ,
V_2 , V_57 ) ;
} else {
F_66 ( V_2 ) ;
F_21 ( V_2 -> V_22 , L_6 ) ;
}
}
if ( F_81 ( V_78 , V_126 -> V_134 ) )
F_54 ( V_78 ) ;
else
F_56 ( V_78 ) ;
}
static void F_82 ( struct V_77 * V_13 ,
struct V_125 * V_126 )
{
if ( V_126 -> V_167 == V_168 ) {
V_13 -> V_6 |= V_169 ;
F_54 ( V_13 ) ;
} else {
V_13 -> V_6 &= ~ V_169 ;
}
}
static T_4 F_83 ( int V_170 , void * V_171 )
{
T_2 V_172 ;
struct V_1 * V_2 = V_171 ;
T_2 V_173 = V_2 -> V_91 ;
T_2 V_59 = F_5 ( V_2 , V_50 ) ;
V_172 = F_5 ( V_2 , V_57 ) ;
F_10 ( V_172 & ( V_174 | V_175 | V_176
| V_177 ) , V_2 , V_57 ) ;
if ( V_170 == V_2 -> V_102 [ V_103 ] ||
V_170 == V_2 -> V_102 [ V_106 ] ||
V_170 == V_2 -> V_102 [ V_104 ] ||
V_170 == V_2 -> V_102 [ V_105 ] )
F_48 ( V_2 ,
F_53 ( V_2 -> V_89 , & V_173 ) ) ;
if ( V_172 & V_177 ) {
if ( F_74 () && V_2 -> V_93 )
F_50 ( & V_2 -> V_13 ,
V_59 & V_101 ) ;
F_10 ( V_177 , V_2 , V_57 ) ;
V_172 &= ~ V_177 ;
}
if ( V_172 & ( V_174 | V_176 ) ) {
if ( ! F_3 ( V_2 ) )
F_36 ( V_2 ) ;
V_172 &= ~ ( V_174 | V_176 ) ;
}
if ( V_172 & V_175 ) {
F_17 ( V_2 ) ;
V_172 &= ~ V_175 ;
}
return V_178 ;
}
static void F_84 ( struct V_1 * V_2 )
{
int V_44 ;
unsigned int V_9 ;
F_10 ( V_179 , V_2 , V_180 ) ;
for ( V_44 = 0 ; V_44 < 10000 ; V_44 ++ ) {
V_9 = F_5 ( V_2 , V_180 ) ;
if ( ! ( V_9 & V_179 ) )
break;
F_85 ( 3 ) ;
}
F_10 ( V_181 , V_2 , V_180 ) ;
}
static void F_86 ( struct V_1 * V_2 )
{
int V_44 ;
T_2 V_9 ;
V_9 = F_5 ( V_2 , V_180 ) ;
if ( V_9 & V_179 )
return;
F_10 ( V_181 , V_2 , V_180 ) ;
F_9 ( V_179 , V_2 , V_180 ) ;
for ( V_44 = 0 ; V_44 < 1000 ; V_44 ++ ) {
V_9 = F_5 ( V_2 , V_180 ) ;
if ( V_9 & V_181 )
return;
F_85 ( 10 ) ;
}
F_21 ( V_2 -> V_22 , L_7 ) ;
}
static int F_87 ( struct V_77 * V_78 )
{
int V_182 ;
struct V_1 * V_2 = F_42 ( V_78 ) ;
V_182 = F_88 ( V_2 -> V_183 ) ;
if ( V_182 )
return V_182 ;
if ( F_89 ( V_78 ) ) {
F_10 ( V_181 , V_2 , V_180 ) ;
} else {
F_86 ( V_2 ) ;
F_84 ( V_2 ) ;
}
F_9 ( V_184 , V_2 , V_85 ) ;
F_7 ( V_165 | V_166 | V_185 ,
V_2 , V_57 ) ;
V_78 -> V_124 = V_186 ;
F_9 ( V_135 , V_2 , V_164 ) ;
F_53 ( V_2 -> V_89 , & V_2 -> V_91 ) ;
V_2 -> V_93 = false ;
return 0 ;
}
static void F_90 ( struct V_77 * V_78 )
{
struct V_1 * V_2 = F_42 ( V_78 ) ;
F_56 ( V_78 ) ;
if ( F_3 ( V_2 ) )
F_66 ( V_2 ) ;
if ( F_89 ( V_78 ) ) {
F_10 ( V_184 , V_2 , V_85 ) ;
F_10 ( V_165 | V_166 |
V_185 , V_2 , V_57 ) ;
F_9 ( V_181 , V_2 , V_180 ) ;
} else {
F_86 ( V_2 ) ;
}
F_91 ( V_2 -> V_183 ) ;
}
static unsigned int F_92 ( struct V_77 * V_78 )
{
struct V_1 * V_2 = F_42 ( V_78 ) ;
if ( ( F_5 ( V_2 , V_50 ) &
( V_187 | V_188 ) ) == V_187 )
return V_189 ;
return 0 ;
}
static void F_93 ( struct V_77 * V_78 )
{
struct V_1 * V_2 = F_42 ( V_78 ) ;
F_9 ( V_190 , V_2 , V_85 ) ;
F_17 ( V_2 ) ;
}
static void F_31 ( struct V_77 * V_78 )
{
struct V_1 * V_2 = F_42 ( V_78 ) ;
F_10 ( V_190 , V_2 , V_85 ) ;
}
static void F_94 ( struct V_77 * V_78 )
{
struct V_1 * V_2 = F_42 ( V_78 ) ;
F_10 ( V_155 , V_2 , V_85 ) ;
}
static void F_95 ( struct V_77 * V_78 , int V_191 )
{
struct V_1 * V_2 = F_42 ( V_78 ) ;
if ( V_191 )
F_9 ( V_192 , V_2 , V_164 ) ;
else
F_10 ( V_192 , V_2 , V_164 ) ;
}
static void F_96 ( struct V_77 * V_13 , int V_193 )
{
struct V_1 * V_2 = F_42 ( V_13 ) ;
unsigned int V_194 = 1000 ;
while ( F_5 ( V_2 , V_50 ) & V_51 ) {
if ( ! V_194 -- )
break;
F_85 ( 1 ) ;
}
F_7 ( V_193 , V_2 , V_55 ) ;
}
static void
F_97 ( struct V_195 * V_196 , const char * V_197 , unsigned int V_109 )
{
struct V_1 * V_2 ;
struct V_77 * V_13 ;
unsigned int V_198 , V_199 ;
unsigned int V_194 = 20000 ;
if ( V_196 -> V_200 >= V_201 || V_196 -> V_200 < 0 )
return;
V_2 = V_202 [ V_196 -> V_200 ] ;
V_13 = & V_2 -> V_13 ;
F_98 ( V_2 -> V_183 ) ;
V_199 = F_5 ( V_2 , V_85 ) ;
V_198 = F_5 ( V_2 , V_180 ) ;
F_10 ( V_181 , V_2 , V_180 ) ;
F_9 ( V_184 | V_190 , V_2 , V_85 ) ;
F_99 ( V_13 , V_197 , V_109 , F_96 ) ;
while ( F_5 ( V_2 , V_50 ) & V_188 ) {
F_85 ( 1 ) ;
if ( ! V_194 -- )
break;
}
if ( ! ( F_5 ( V_2 , V_50 ) & V_188 ) ) {
F_7 ( V_198 , V_2 , V_180 ) ;
F_7 ( V_199 , V_2 , V_85 ) ;
}
F_100 ( V_2 -> V_183 ) ;
}
static void T_5
F_101 ( struct V_1 * V_2 , int * V_131 ,
int * V_67 , int * V_203 )
{
struct V_77 * V_13 = & V_2 -> V_13 ;
unsigned int V_204 , V_205 ;
if ( ! ( F_5 ( V_2 , V_85 ) & V_184 ) )
return;
V_204 = F_5 ( V_2 , V_164 ) ;
* V_67 = 'n' ;
if ( V_204 & V_142 ) {
if ( V_204 & V_144 )
* V_67 = 'e' ;
else
* V_67 = 'o' ;
}
if ( ( V_204 & V_206 ) == F_72 ( 2 ) )
* V_203 = 7 ;
else
* V_203 = 8 ;
V_205 = ( ( F_5 ( V_2 , V_164 ) & V_207 ) )
>> ( V_208 - 6 ) ;
V_205 |= ( ( F_5 ( V_2 , V_164 ) & V_209 ) )
>> V_210 ;
if ( V_205 == 0 )
V_205 = 1 ;
* V_131 = ( V_13 -> V_161 << 2 ) / V_205 ;
}
static int T_5
F_102 ( struct V_195 * V_196 , char * V_211 )
{
struct V_1 * V_2 ;
int V_131 = 9600 ;
int V_203 = 8 ;
int V_67 = 'n' ;
int V_212 = 'n' ;
int V_182 ;
if ( V_196 -> V_200 == - 1 || V_196 -> V_200 >= F_103 ( V_202 ) )
V_196 -> V_200 = 0 ;
V_2 = V_202 [ V_196 -> V_200 ] ;
if ( ! V_2 )
return - V_213 ;
V_182 = F_88 ( V_2 -> V_183 ) ;
if ( V_182 )
return V_182 ;
if ( V_211 )
F_104 ( V_211 , & V_131 , & V_67 , & V_203 , & V_212 ) ;
else
F_101 ( V_2 , & V_131 , & V_67 , & V_203 ) ;
V_182 = F_105 ( & V_2 -> V_13 , V_196 , V_131 , V_67 , V_203 , V_212 ) ;
F_91 ( V_2 -> V_183 ) ;
return V_182 ;
}
static void F_106 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
V_2 -> V_10 = & V_214 ;
else
V_2 -> V_10 = & V_215 ;
}
static int F_107 ( struct V_1 * V_2 ,
struct V_216 * V_217 )
{
int V_218 ;
if ( ! F_2 ( V_2 ) ) {
V_2 -> V_183 = F_108 ( & V_217 -> V_22 , NULL ) ;
return F_109 ( V_2 -> V_183 ) ;
}
V_2 -> V_183 = F_108 ( V_2 -> V_22 , L_8 ) ;
if ( F_110 ( V_2 -> V_183 ) ) {
F_21 ( V_2 -> V_22 , L_9 ) ;
return F_111 ( V_2 -> V_183 ) ;
}
V_2 -> V_219 = F_108 ( V_2 -> V_22 , L_10 ) ;
if ( F_110 ( V_2 -> V_219 ) ) {
F_21 ( V_2 -> V_22 , L_11 ) ;
return F_111 ( V_2 -> V_219 ) ;
}
V_218 = F_88 ( V_2 -> V_219 ) ;
if ( V_218 ) {
F_21 ( V_2 -> V_22 , L_12 ) ;
return V_218 ;
}
V_218 = F_112 ( V_2 -> V_183 , F_113 ( V_2 -> V_219 ) ) ;
if ( V_218 ) {
F_21 ( V_2 -> V_22 , L_13 ) ;
goto V_220;
}
V_218 = F_88 ( V_2 -> V_183 ) ;
if ( V_218 ) {
F_21 ( V_2 -> V_22 , L_14 ) ;
goto V_220;
}
return 0 ;
V_220:
F_91 ( V_2 -> V_219 ) ;
return V_218 ;
}
static int F_114 ( struct V_1 * V_2 ,
struct V_216 * V_217 )
{
struct V_221 * V_222 = V_217 -> V_22 . V_223 ;
int V_182 ;
if ( ! V_222 )
return 1 ;
V_182 = F_115 ( V_222 , L_15 ) ;
if ( V_182 < 0 ) {
F_21 ( & V_217 -> V_22 , L_16 , V_182 ) ;
return V_182 ;
}
V_2 -> V_13 . line = V_182 ;
if ( F_116 ( V_222 , L_17 , NULL ) ||
F_116 ( V_222 , L_18 , NULL ) )
F_117 ( V_160 , & V_2 -> V_6 ) ;
return 0 ;
}
static int F_118 ( struct V_1 * V_2 , struct V_224 * V_22 )
{
enum V_225 V_44 ;
struct V_226 * V_227 ;
V_2 -> V_89 = F_119 ( V_22 , 0 ) ;
if ( F_110 ( V_2 -> V_89 ) )
return F_111 ( V_2 -> V_89 ) ;
if ( ! F_120 () || ! F_74 () ) {
if ( F_73 ( V_160 , & V_2 -> V_6 ) )
F_121 ( V_22 ,
L_19 ) ;
F_13 ( V_160 , & V_2 -> V_6 ) ;
}
for ( V_44 = 0 ; V_44 < V_228 ; V_44 ++ ) {
V_227 = F_122 ( V_2 -> V_89 , V_44 ) ;
if ( V_227 && ( F_123 ( V_227 ) == V_229 ) )
V_2 -> V_102 [ V_44 ] = F_124 ( V_227 ) ;
else
V_2 -> V_102 [ V_44 ] = - V_37 ;
}
return 0 ;
}
static void F_125 ( struct V_1 * V_2 )
{
enum V_225 V_44 ;
for ( V_44 = 0 ; V_44 < V_228 ; V_44 ++ )
if ( V_2 -> V_102 [ V_44 ] >= 0 )
F_126 ( V_2 -> V_102 [ V_44 ] , V_2 ) ;
}
static int F_127 ( struct V_1 * V_2 )
{
int * V_170 = V_2 -> V_102 ;
enum V_225 V_44 ;
int V_218 = 0 ;
for ( V_44 = 0 ; ( V_44 < V_228 ) && ! V_218 ; V_44 ++ ) {
if ( V_170 [ V_44 ] < 0 )
continue;
F_128 ( V_170 [ V_44 ] , V_230 ) ;
V_218 = F_129 ( V_170 [ V_44 ] , F_83 ,
V_231 , F_43 ( V_2 -> V_22 ) , V_2 ) ;
if ( V_218 )
F_21 ( V_2 -> V_22 , L_20 ,
V_232 , V_170 [ V_44 ] ) ;
}
while ( V_218 && ( -- V_44 >= 0 ) )
if ( V_170 [ V_44 ] >= 0 )
F_126 ( V_170 [ V_44 ] , V_2 ) ;
return V_218 ;
}
static int F_130 ( struct V_216 * V_217 )
{
const struct V_233 * V_234 =
F_131 ( V_235 , & V_217 -> V_22 ) ;
struct V_1 * V_2 ;
T_2 V_236 ;
int V_182 , V_170 ;
struct V_237 * V_238 ;
V_2 = F_132 ( & V_217 -> V_22 , sizeof( * V_2 ) , V_122 ) ;
if ( ! V_2 )
return - V_239 ;
V_2 -> V_13 . V_22 = & V_217 -> V_22 ;
V_2 -> V_22 = & V_217 -> V_22 ;
V_182 = F_114 ( V_2 , V_217 ) ;
if ( V_182 > 0 )
V_2 -> V_13 . line = V_217 -> V_240 < 0 ? 0 : V_217 -> V_240 ;
else if ( V_182 < 0 )
return V_182 ;
if ( V_234 ) {
V_217 -> V_241 = V_234 -> V_242 ;
V_2 -> V_3 = V_217 -> V_241 -> V_243 ;
}
V_182 = F_107 ( V_2 , V_217 ) ;
if ( V_182 )
return V_182 ;
V_238 = F_133 ( V_217 , V_244 , 0 ) ;
if ( ! V_238 )
return - V_245 ;
V_2 -> V_13 . V_246 = V_238 -> V_247 ;
V_2 -> V_13 . V_14 = F_134 ( V_238 -> V_247 , F_135 ( V_238 ) ) ;
V_2 -> V_13 . V_248 = & V_249 ;
V_2 -> V_13 . V_250 = V_251 ;
V_2 -> V_13 . V_124 = V_186 ;
V_2 -> V_13 . V_161 = F_113 ( V_2 -> V_183 ) ;
V_2 -> V_13 . type = V_82 ;
F_106 ( V_2 ) ;
V_2 -> V_91 = 0 ;
V_170 = F_136 ( V_217 , 0 ) ;
if ( V_170 < 0 )
return V_170 ;
V_2 -> V_13 . V_170 = V_170 ;
V_182 = F_137 ( & V_217 -> V_22 , V_170 , F_83 , 0 ,
F_43 ( & V_217 -> V_22 ) , V_2 ) ;
if ( V_182 )
return V_182 ;
F_138 ( V_217 , V_2 ) ;
V_182 = F_118 ( V_2 , & V_217 -> V_22 ) ;
if ( V_182 ) {
F_21 ( & V_217 -> V_22 , L_21 ) ;
return V_182 ;
}
V_182 = F_127 ( V_2 ) ;
if ( V_182 )
return V_182 ;
V_202 [ V_2 -> V_13 . line ] = V_2 ;
F_84 ( V_2 ) ;
V_182 = F_139 ( & V_252 , & V_2 -> V_13 ) ;
if ( V_182 )
goto V_253;
if ( F_2 ( V_2 ) ) {
F_140 ( & V_217 -> V_22 , L_22 ) ;
} else {
V_236 = F_5 ( V_2 , V_254 ) ;
F_140 ( & V_217 -> V_22 , L_23 ,
( V_236 >> 24 ) & 0xff ,
( V_236 >> 16 ) & 0xff , V_236 & 0xffff ) ;
}
return 0 ;
V_253:
F_125 ( V_2 ) ;
V_202 [ V_217 -> V_240 ] = NULL ;
return V_182 ;
}
static int F_141 ( struct V_216 * V_217 )
{
struct V_1 * V_2 = F_142 ( V_217 ) ;
F_143 ( & V_252 , & V_2 -> V_13 ) ;
V_202 [ V_217 -> V_240 ] = NULL ;
F_125 ( V_2 ) ;
return 0 ;
}
static int T_5 F_144 ( void )
{
int V_238 ;
V_238 = F_145 ( & V_252 ) ;
if ( V_238 )
goto V_65;
V_238 = F_146 ( & V_255 ) ;
if ( V_238 )
goto V_256;
return 0 ;
V_256:
F_147 ( & V_252 ) ;
V_65:
return V_238 ;
}
static void T_6 F_148 ( void )
{
F_149 ( & V_255 ) ;
F_147 ( & V_252 ) ;
}
