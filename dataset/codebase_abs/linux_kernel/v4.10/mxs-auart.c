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
}
V_78 -> V_70 = V_74 ;
if ( V_126 -> V_145 & V_146 )
V_78 -> V_70 |= V_66 ;
if ( V_126 -> V_145 & ( V_147 | V_148 | V_149 ) )
V_78 -> V_70 |= V_63 ;
V_78 -> V_150 = 0 ;
if ( V_126 -> V_145 & V_151 )
V_78 -> V_150 |= V_66 ;
if ( V_126 -> V_145 & V_147 ) {
V_78 -> V_150 |= V_63 ;
if ( V_126 -> V_145 & V_151 )
V_78 -> V_150 |= V_74 ;
}
if ( V_130 & V_152 )
V_129 |= V_153 ;
else
V_129 &= ~ V_153 ;
if ( V_130 & V_154 )
V_84 |= V_155 ;
V_129 &= ~ ( V_156 | V_86 ) ;
if ( V_130 & V_157 ) {
if ( F_1 ( V_2 )
&& F_73 ( V_158 , & V_2 -> V_6 ) ) {
if ( ! F_67 ( V_2 ) )
V_129 |= V_117 | V_118
| V_119 ;
}
V_129 |= V_86 ;
if ( F_74 () )
V_129 |= V_156 ;
}
if ( F_2 ( V_2 ) ) {
V_131 = F_75 ( V_78 , V_126 , V_127 ,
V_78 -> V_159 * 4 / 0x3FFFFF ,
V_78 -> V_159 / 16 ) ;
div = V_78 -> V_159 * 4 / V_131 ;
} else {
V_132 = F_76 ( V_78 -> V_159 * 32 ,
V_160 ) ;
V_133 = V_78 -> V_159 * 32 / V_161 ;
V_131 = F_75 ( V_78 , V_126 , V_127 , V_132 , V_133 ) ;
div = V_78 -> V_159 * 32 / V_131 ;
}
V_84 |= F_77 ( div & 0x3F ) ;
V_84 |= F_78 ( div >> 6 ) ;
F_7 ( V_84 , V_2 , V_162 ) ;
F_7 ( V_129 , V_2 , V_85 ) ;
F_79 ( V_78 , V_126 -> V_134 , V_131 ) ;
if ( F_3 ( V_2 ) &&
! F_26 ( V_120 , & V_2 -> V_6 ) ) {
if ( ! F_60 ( V_2 ) ) {
F_10 ( V_163 | V_164 ,
V_2 , V_57 ) ;
} else {
F_66 ( V_2 ) ;
F_21 ( V_2 -> V_22 , L_6 ) ;
}
}
if ( F_80 ( V_78 , V_126 -> V_134 ) )
F_54 ( V_78 ) ;
else
F_56 ( V_78 ) ;
}
static void F_81 ( struct V_77 * V_13 ,
struct V_125 * V_126 )
{
if ( V_126 -> V_165 == V_166 ) {
V_13 -> V_6 |= V_167 ;
F_54 ( V_13 ) ;
} else {
V_13 -> V_6 &= ~ V_167 ;
}
}
static T_4 F_82 ( int V_168 , void * V_169 )
{
T_2 V_170 ;
struct V_1 * V_2 = V_169 ;
T_2 V_171 = V_2 -> V_91 ;
T_2 V_59 = F_5 ( V_2 , V_50 ) ;
V_170 = F_5 ( V_2 , V_57 ) ;
F_10 ( V_170 & ( V_172 | V_173 | V_174
| V_175 ) , V_2 , V_57 ) ;
if ( V_168 == V_2 -> V_102 [ V_103 ] ||
V_168 == V_2 -> V_102 [ V_106 ] ||
V_168 == V_2 -> V_102 [ V_104 ] ||
V_168 == V_2 -> V_102 [ V_105 ] )
F_48 ( V_2 ,
F_53 ( V_2 -> V_89 , & V_171 ) ) ;
if ( V_170 & V_175 ) {
if ( F_74 () && V_2 -> V_93 )
F_50 ( & V_2 -> V_13 ,
V_59 & V_101 ) ;
F_10 ( V_175 , V_2 , V_57 ) ;
V_170 &= ~ V_175 ;
}
if ( V_170 & ( V_172 | V_174 ) ) {
if ( ! F_3 ( V_2 ) )
F_36 ( V_2 ) ;
V_170 &= ~ ( V_172 | V_174 ) ;
}
if ( V_170 & V_173 ) {
F_17 ( V_2 ) ;
V_170 &= ~ V_173 ;
}
return V_176 ;
}
static void F_83 ( struct V_1 * V_2 )
{
int V_44 ;
unsigned int V_9 ;
F_10 ( V_177 , V_2 , V_178 ) ;
for ( V_44 = 0 ; V_44 < 10000 ; V_44 ++ ) {
V_9 = F_5 ( V_2 , V_178 ) ;
if ( ! ( V_9 & V_177 ) )
break;
F_84 ( 3 ) ;
}
F_10 ( V_179 , V_2 , V_178 ) ;
}
static void F_85 ( struct V_1 * V_2 )
{
int V_44 ;
T_2 V_9 ;
V_9 = F_5 ( V_2 , V_178 ) ;
if ( V_9 & V_177 )
return;
F_10 ( V_179 , V_2 , V_178 ) ;
F_9 ( V_177 , V_2 , V_178 ) ;
for ( V_44 = 0 ; V_44 < 1000 ; V_44 ++ ) {
V_9 = F_5 ( V_2 , V_178 ) ;
if ( V_9 & V_179 )
return;
F_84 ( 10 ) ;
}
F_21 ( V_2 -> V_22 , L_7 ) ;
}
static int F_86 ( struct V_77 * V_78 )
{
int V_180 ;
struct V_1 * V_2 = F_42 ( V_78 ) ;
V_180 = F_87 ( V_2 -> V_181 ) ;
if ( V_180 )
return V_180 ;
if ( F_88 ( V_78 ) ) {
F_10 ( V_179 , V_2 , V_178 ) ;
} else {
F_85 ( V_2 ) ;
F_83 ( V_2 ) ;
}
F_9 ( V_182 , V_2 , V_85 ) ;
F_7 ( V_163 | V_164 | V_183 ,
V_2 , V_57 ) ;
V_78 -> V_124 = V_184 ;
F_9 ( V_135 , V_2 , V_162 ) ;
F_53 ( V_2 -> V_89 , & V_2 -> V_91 ) ;
V_2 -> V_93 = false ;
return 0 ;
}
static void F_89 ( struct V_77 * V_78 )
{
struct V_1 * V_2 = F_42 ( V_78 ) ;
F_56 ( V_78 ) ;
if ( F_3 ( V_2 ) )
F_66 ( V_2 ) ;
if ( F_88 ( V_78 ) ) {
F_10 ( V_182 , V_2 , V_85 ) ;
F_10 ( V_163 | V_164 |
V_183 , V_2 , V_57 ) ;
F_9 ( V_179 , V_2 , V_178 ) ;
} else {
F_85 ( V_2 ) ;
}
F_90 ( V_2 -> V_181 ) ;
}
static unsigned int F_91 ( struct V_77 * V_78 )
{
struct V_1 * V_2 = F_42 ( V_78 ) ;
if ( ( F_5 ( V_2 , V_50 ) &
( V_185 | V_186 ) ) == V_185 )
return V_187 ;
return 0 ;
}
static void F_92 ( struct V_77 * V_78 )
{
struct V_1 * V_2 = F_42 ( V_78 ) ;
F_9 ( V_188 , V_2 , V_85 ) ;
F_17 ( V_2 ) ;
}
static void F_31 ( struct V_77 * V_78 )
{
struct V_1 * V_2 = F_42 ( V_78 ) ;
F_10 ( V_188 , V_2 , V_85 ) ;
}
static void F_93 ( struct V_77 * V_78 )
{
struct V_1 * V_2 = F_42 ( V_78 ) ;
F_10 ( V_153 , V_2 , V_85 ) ;
}
static void F_94 ( struct V_77 * V_78 , int V_189 )
{
struct V_1 * V_2 = F_42 ( V_78 ) ;
if ( V_189 )
F_9 ( V_190 , V_2 , V_162 ) ;
else
F_10 ( V_190 , V_2 , V_162 ) ;
}
static void F_95 ( struct V_77 * V_13 , int V_191 )
{
struct V_1 * V_2 = F_42 ( V_13 ) ;
unsigned int V_192 = 1000 ;
while ( F_5 ( V_2 , V_50 ) & V_51 ) {
if ( ! V_192 -- )
break;
F_84 ( 1 ) ;
}
F_7 ( V_191 , V_2 , V_55 ) ;
}
static void
F_96 ( struct V_193 * V_194 , const char * V_195 , unsigned int V_109 )
{
struct V_1 * V_2 ;
struct V_77 * V_13 ;
unsigned int V_196 , V_197 ;
unsigned int V_192 = 20000 ;
if ( V_194 -> V_198 >= V_199 || V_194 -> V_198 < 0 )
return;
V_2 = V_200 [ V_194 -> V_198 ] ;
V_13 = & V_2 -> V_13 ;
F_97 ( V_2 -> V_181 ) ;
V_197 = F_5 ( V_2 , V_85 ) ;
V_196 = F_5 ( V_2 , V_178 ) ;
F_10 ( V_179 , V_2 , V_178 ) ;
F_9 ( V_182 | V_188 , V_2 , V_85 ) ;
F_98 ( V_13 , V_195 , V_109 , F_95 ) ;
while ( F_5 ( V_2 , V_50 ) & V_186 ) {
F_84 ( 1 ) ;
if ( ! V_192 -- )
break;
}
if ( ! ( F_5 ( V_2 , V_50 ) & V_186 ) ) {
F_7 ( V_196 , V_2 , V_178 ) ;
F_7 ( V_197 , V_2 , V_85 ) ;
}
F_99 ( V_2 -> V_181 ) ;
}
static void T_5
F_100 ( struct V_1 * V_2 , int * V_131 ,
int * V_67 , int * V_201 )
{
struct V_77 * V_13 = & V_2 -> V_13 ;
unsigned int V_202 , V_203 ;
if ( ! ( F_5 ( V_2 , V_85 ) & V_182 ) )
return;
V_202 = F_5 ( V_2 , V_162 ) ;
* V_67 = 'n' ;
if ( V_202 & V_142 ) {
if ( V_202 & V_144 )
* V_67 = 'e' ;
else
* V_67 = 'o' ;
}
if ( ( V_202 & V_204 ) == F_72 ( 2 ) )
* V_201 = 7 ;
else
* V_201 = 8 ;
V_203 = ( ( F_5 ( V_2 , V_162 ) & V_205 ) )
>> ( V_206 - 6 ) ;
V_203 |= ( ( F_5 ( V_2 , V_162 ) & V_207 ) )
>> V_208 ;
if ( V_203 == 0 )
V_203 = 1 ;
* V_131 = ( V_13 -> V_159 << 2 ) / V_203 ;
}
static int T_5
F_101 ( struct V_193 * V_194 , char * V_209 )
{
struct V_1 * V_2 ;
int V_131 = 9600 ;
int V_201 = 8 ;
int V_67 = 'n' ;
int V_210 = 'n' ;
int V_180 ;
if ( V_194 -> V_198 == - 1 || V_194 -> V_198 >= F_102 ( V_200 ) )
V_194 -> V_198 = 0 ;
V_2 = V_200 [ V_194 -> V_198 ] ;
if ( ! V_2 )
return - V_211 ;
V_180 = F_87 ( V_2 -> V_181 ) ;
if ( V_180 )
return V_180 ;
if ( V_209 )
F_103 ( V_209 , & V_131 , & V_67 , & V_201 , & V_210 ) ;
else
F_100 ( V_2 , & V_131 , & V_67 , & V_201 ) ;
V_180 = F_104 ( & V_2 -> V_13 , V_194 , V_131 , V_67 , V_201 , V_210 ) ;
F_90 ( V_2 -> V_181 ) ;
return V_180 ;
}
static void F_105 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
V_2 -> V_10 = & V_212 ;
else
V_2 -> V_10 = & V_213 ;
}
static int F_106 ( struct V_1 * V_2 ,
struct V_214 * V_215 )
{
int V_216 ;
if ( ! F_2 ( V_2 ) ) {
V_2 -> V_181 = F_107 ( & V_215 -> V_22 , NULL ) ;
return F_108 ( V_2 -> V_181 ) ;
}
V_2 -> V_181 = F_107 ( V_2 -> V_22 , L_8 ) ;
if ( F_109 ( V_2 -> V_181 ) ) {
F_21 ( V_2 -> V_22 , L_9 ) ;
return F_110 ( V_2 -> V_181 ) ;
}
V_2 -> V_217 = F_107 ( V_2 -> V_22 , L_10 ) ;
if ( F_109 ( V_2 -> V_217 ) ) {
F_21 ( V_2 -> V_22 , L_11 ) ;
return F_110 ( V_2 -> V_217 ) ;
}
V_216 = F_87 ( V_2 -> V_217 ) ;
if ( V_216 ) {
F_21 ( V_2 -> V_22 , L_12 ) ;
return V_216 ;
}
V_216 = F_111 ( V_2 -> V_181 , F_112 ( V_2 -> V_217 ) ) ;
if ( V_216 ) {
F_21 ( V_2 -> V_22 , L_13 ) ;
goto V_218;
}
V_216 = F_87 ( V_2 -> V_181 ) ;
if ( V_216 ) {
F_21 ( V_2 -> V_22 , L_14 ) ;
goto V_218;
}
return 0 ;
V_218:
F_90 ( V_2 -> V_217 ) ;
return V_216 ;
}
static int F_113 ( struct V_1 * V_2 ,
struct V_214 * V_215 )
{
struct V_219 * V_220 = V_215 -> V_22 . V_221 ;
int V_180 ;
if ( ! V_220 )
return 1 ;
V_180 = F_114 ( V_220 , L_15 ) ;
if ( V_180 < 0 ) {
F_21 ( & V_215 -> V_22 , L_16 , V_180 ) ;
return V_180 ;
}
V_2 -> V_13 . line = V_180 ;
if ( F_115 ( V_220 , L_17 , NULL ) ||
F_115 ( V_220 , L_18 , NULL ) )
F_116 ( V_158 , & V_2 -> V_6 ) ;
return 0 ;
}
static int F_117 ( struct V_1 * V_2 , struct V_222 * V_22 )
{
enum V_223 V_44 ;
struct V_224 * V_225 ;
V_2 -> V_89 = F_118 ( V_22 , 0 ) ;
if ( F_109 ( V_2 -> V_89 ) )
return F_110 ( V_2 -> V_89 ) ;
if ( ! F_119 () || ! F_74 () ) {
if ( F_73 ( V_158 , & V_2 -> V_6 ) )
F_120 ( V_22 ,
L_19 ) ;
F_13 ( V_158 , & V_2 -> V_6 ) ;
}
for ( V_44 = 0 ; V_44 < V_226 ; V_44 ++ ) {
V_225 = F_121 ( V_2 -> V_89 , V_44 ) ;
if ( V_225 && ( F_122 ( V_225 ) == V_227 ) )
V_2 -> V_102 [ V_44 ] = F_123 ( V_225 ) ;
else
V_2 -> V_102 [ V_44 ] = - V_37 ;
}
return 0 ;
}
static void F_124 ( struct V_1 * V_2 )
{
enum V_223 V_44 ;
for ( V_44 = 0 ; V_44 < V_226 ; V_44 ++ )
if ( V_2 -> V_102 [ V_44 ] >= 0 )
F_125 ( V_2 -> V_102 [ V_44 ] , V_2 ) ;
}
static int F_126 ( struct V_1 * V_2 )
{
int * V_168 = V_2 -> V_102 ;
enum V_223 V_44 ;
int V_216 = 0 ;
for ( V_44 = 0 ; ( V_44 < V_226 ) && ! V_216 ; V_44 ++ ) {
if ( V_168 [ V_44 ] < 0 )
continue;
F_127 ( V_168 [ V_44 ] , V_228 ) ;
V_216 = F_128 ( V_168 [ V_44 ] , F_82 ,
V_229 , F_43 ( V_2 -> V_22 ) , V_2 ) ;
if ( V_216 )
F_21 ( V_2 -> V_22 , L_20 ,
V_230 , V_168 [ V_44 ] ) ;
}
while ( V_216 && ( -- V_44 >= 0 ) )
if ( V_168 [ V_44 ] >= 0 )
F_125 ( V_168 [ V_44 ] , V_2 ) ;
return V_216 ;
}
static int F_129 ( struct V_214 * V_215 )
{
const struct V_231 * V_232 =
F_130 ( V_233 , & V_215 -> V_22 ) ;
struct V_1 * V_2 ;
T_2 V_234 ;
int V_180 , V_168 ;
struct V_235 * V_236 ;
V_2 = F_131 ( & V_215 -> V_22 , sizeof( * V_2 ) , V_122 ) ;
if ( ! V_2 )
return - V_237 ;
V_2 -> V_13 . V_22 = & V_215 -> V_22 ;
V_2 -> V_22 = & V_215 -> V_22 ;
V_180 = F_113 ( V_2 , V_215 ) ;
if ( V_180 > 0 )
V_2 -> V_13 . line = V_215 -> V_238 < 0 ? 0 : V_215 -> V_238 ;
else if ( V_180 < 0 )
return V_180 ;
if ( V_232 ) {
V_215 -> V_239 = V_232 -> V_240 ;
V_2 -> V_3 = V_215 -> V_239 -> V_241 ;
}
V_180 = F_106 ( V_2 , V_215 ) ;
if ( V_180 )
return V_180 ;
V_236 = F_132 ( V_215 , V_242 , 0 ) ;
if ( ! V_236 )
return - V_243 ;
V_2 -> V_13 . V_244 = V_236 -> V_245 ;
V_2 -> V_13 . V_14 = F_133 ( V_236 -> V_245 , F_134 ( V_236 ) ) ;
V_2 -> V_13 . V_246 = & V_247 ;
V_2 -> V_13 . V_248 = V_249 ;
V_2 -> V_13 . V_124 = V_184 ;
V_2 -> V_13 . V_159 = F_112 ( V_2 -> V_181 ) ;
V_2 -> V_13 . type = V_82 ;
F_105 ( V_2 ) ;
V_2 -> V_91 = 0 ;
V_168 = F_135 ( V_215 , 0 ) ;
if ( V_168 < 0 )
return V_168 ;
V_2 -> V_13 . V_168 = V_168 ;
V_180 = F_136 ( & V_215 -> V_22 , V_168 , F_82 , 0 ,
F_43 ( & V_215 -> V_22 ) , V_2 ) ;
if ( V_180 )
return V_180 ;
F_137 ( V_215 , V_2 ) ;
V_180 = F_117 ( V_2 , & V_215 -> V_22 ) ;
if ( V_180 ) {
F_21 ( & V_215 -> V_22 , L_21 ) ;
return V_180 ;
}
V_180 = F_126 ( V_2 ) ;
if ( V_180 )
return V_180 ;
V_200 [ V_2 -> V_13 . line ] = V_2 ;
F_83 ( V_2 ) ;
V_180 = F_138 ( & V_250 , & V_2 -> V_13 ) ;
if ( V_180 )
goto V_251;
if ( F_2 ( V_2 ) ) {
F_139 ( & V_215 -> V_22 , L_22 ) ;
} else {
V_234 = F_5 ( V_2 , V_252 ) ;
F_139 ( & V_215 -> V_22 , L_23 ,
( V_234 >> 24 ) & 0xff ,
( V_234 >> 16 ) & 0xff , V_234 & 0xffff ) ;
}
return 0 ;
V_251:
F_124 ( V_2 ) ;
V_200 [ V_215 -> V_238 ] = NULL ;
return V_180 ;
}
static int F_140 ( struct V_214 * V_215 )
{
struct V_1 * V_2 = F_141 ( V_215 ) ;
F_142 ( & V_250 , & V_2 -> V_13 ) ;
V_200 [ V_215 -> V_238 ] = NULL ;
F_124 ( V_2 ) ;
return 0 ;
}
static int T_5 F_143 ( void )
{
int V_236 ;
V_236 = F_144 ( & V_250 ) ;
if ( V_236 )
goto V_65;
V_236 = F_145 ( & V_253 ) ;
if ( V_236 )
goto V_254;
return 0 ;
V_254:
F_146 ( & V_250 ) ;
V_65:
return V_236 ;
}
static void T_6 F_147 ( void )
{
F_148 ( & V_253 ) ;
F_146 ( & V_250 ) ;
}
