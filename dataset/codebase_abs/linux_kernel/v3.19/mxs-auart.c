static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_4 ;
}
static inline bool F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_5 & V_6 ;
}
static void F_3 ( void * V_7 )
{
struct V_1 * V_2 = V_7 ;
struct V_8 * V_9 = & V_2 -> V_10 . V_11 -> V_9 ;
F_4 ( V_2 -> V_12 , & V_2 -> V_13 , 1 , V_14 ) ;
F_5 ( V_15 , & V_2 -> V_5 ) ;
F_6 () ;
if ( F_7 ( V_9 ) < V_16 )
F_8 ( & V_2 -> V_10 ) ;
F_9 ( V_2 ) ;
}
static int F_10 ( struct V_1 * V_2 , int V_17 )
{
struct V_18 * V_19 ;
struct V_20 * V_21 = & V_2 -> V_13 ;
struct V_22 * V_23 = V_2 -> V_24 ;
T_1 V_25 ;
V_25 = F_11 ( V_17 ) ;
V_19 = F_12 ( V_23 , (struct V_20 * ) & V_25 ,
1 , V_26 , 0 ) ;
if ( ! V_19 ) {
F_13 ( V_2 -> V_12 , L_1 ) ;
return - V_27 ;
}
F_14 ( V_21 , V_2 -> V_28 , V_17 ) ;
F_15 ( V_2 -> V_12 , V_21 , 1 , V_14 ) ;
V_19 = F_12 ( V_23 , V_21 ,
1 , V_29 , V_30 | V_31 ) ;
if ( ! V_19 ) {
F_13 ( V_2 -> V_12 , L_2 ) ;
return - V_27 ;
}
V_19 -> V_32 = F_3 ;
V_19 -> V_33 = V_2 ;
F_16 ( V_19 ) ;
F_17 ( V_23 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_10 . V_11 -> V_9 ;
if ( F_2 ( V_2 ) ) {
T_1 V_34 = 0 ;
int V_17 ;
void * V_35 = V_2 -> V_28 ;
if ( F_18 ( V_15 , & V_2 -> V_5 ) )
return;
while ( ! F_19 ( V_9 ) && ! F_20 ( & V_2 -> V_10 ) ) {
V_17 = F_21 ( T_1 , V_36 - V_34 ,
F_22 ( V_9 -> V_37 ,
V_9 -> V_38 ,
V_36 ) ) ;
memcpy ( V_35 + V_34 , V_9 -> V_39 + V_9 -> V_38 , V_17 ) ;
V_9 -> V_38 = ( V_9 -> V_38 + V_17 ) & ( V_36 - 1 ) ;
V_34 += V_17 ;
if ( V_34 >= V_36 )
break;
}
if ( F_20 ( & V_2 -> V_10 ) )
F_23 ( & V_2 -> V_10 ) ;
if ( V_34 ) {
F_10 ( V_2 , V_34 ) ;
} else {
F_5 ( V_15 , & V_2 -> V_5 ) ;
F_6 () ;
}
return;
}
while ( ! ( F_24 ( V_2 -> V_10 . V_40 + V_41 ) &
V_42 ) ) {
if ( V_2 -> V_10 . V_43 ) {
V_2 -> V_10 . V_44 . V_45 ++ ;
F_25 ( V_2 -> V_10 . V_43 ,
V_2 -> V_10 . V_40 + V_46 ) ;
V_2 -> V_10 . V_43 = 0 ;
continue;
}
if ( ! F_19 ( V_9 ) && ! F_20 ( & V_2 -> V_10 ) ) {
V_2 -> V_10 . V_44 . V_45 ++ ;
F_25 ( V_9 -> V_39 [ V_9 -> V_38 ] ,
V_2 -> V_10 . V_40 + V_46 ) ;
V_9 -> V_38 = ( V_9 -> V_38 + 1 ) & ( V_36 - 1 ) ;
} else
break;
}
if ( F_7 ( V_9 ) < V_16 )
F_8 ( & V_2 -> V_10 ) ;
if ( F_19 ( & ( V_2 -> V_10 . V_11 -> V_9 ) ) )
F_25 ( V_47 ,
V_2 -> V_10 . V_40 + V_48 ) ;
else
F_25 ( V_47 ,
V_2 -> V_10 . V_40 + V_49 ) ;
if ( F_20 ( & V_2 -> V_10 ) )
F_23 ( & V_2 -> V_10 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
int V_50 ;
T_1 V_51 ;
T_2 V_52 ;
V_52 = F_24 ( V_2 -> V_10 . V_40 + V_46 ) ;
V_51 = F_24 ( V_2 -> V_10 . V_40 + V_41 ) ;
V_50 = V_53 ;
V_2 -> V_10 . V_44 . V_54 ++ ;
if ( V_51 & V_55 ) {
V_2 -> V_10 . V_44 . V_56 ++ ;
if ( F_27 ( & V_2 -> V_10 ) )
goto V_57;
} else if ( V_51 & V_58 ) {
V_2 -> V_10 . V_44 . V_59 ++ ;
} else if ( V_51 & V_60 ) {
V_2 -> V_10 . V_44 . V_61 ++ ;
}
V_51 &= V_2 -> V_10 . V_62 ;
if ( V_51 & V_55 ) {
V_50 = V_63 ;
} else if ( V_51 & V_58 )
V_50 = V_64 ;
else if ( V_51 & V_60 )
V_50 = V_65 ;
if ( V_51 & V_66 )
V_2 -> V_10 . V_44 . V_67 ++ ;
if ( F_28 ( & V_2 -> V_10 , V_52 ) )
goto V_57;
F_29 ( & V_2 -> V_10 , V_51 , V_66 , V_52 , V_50 ) ;
V_57:
F_25 ( V_51 , V_2 -> V_10 . V_40 + V_41 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
T_1 V_51 = 0 ;
for (; ; ) {
V_51 = F_24 ( V_2 -> V_10 . V_40 + V_41 ) ;
if ( V_51 & V_68 )
break;
F_26 ( V_2 ) ;
}
F_25 ( V_51 , V_2 -> V_10 . V_40 + V_41 ) ;
F_31 ( & V_2 -> V_10 . V_11 -> V_10 ) ;
}
static int F_32 ( struct V_69 * V_70 )
{
return 0 ;
}
static int F_33 ( struct V_69 * V_70 ,
struct V_71 * V_72 )
{
if ( V_70 -> type != V_73 && V_70 -> type != V_74 )
return - V_27 ;
return 0 ;
}
static void F_34 ( struct V_69 * V_70 , int V_5 )
{
}
static const char * F_35 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_36 ( V_70 ) ;
return F_37 ( V_2 -> V_12 ) ;
}
static void F_38 ( struct V_69 * V_70 )
{
}
static void F_39 ( struct V_69 * V_70 , unsigned V_75 )
{
struct V_1 * V_2 = F_36 ( V_70 ) ;
T_1 V_76 = F_24 ( V_70 -> V_40 + V_77 ) ;
V_76 &= ~ ( V_78 | V_79 ) ;
if ( V_75 & V_80 ) {
if ( F_40 ( V_70 ) )
V_76 |= V_78 ;
else
V_76 |= V_79 ;
}
F_25 ( V_76 , V_70 -> V_40 + V_77 ) ;
F_41 ( V_2 -> V_81 , V_75 ) ;
}
static T_1 F_42 ( struct V_1 * V_2 , T_1 V_75 )
{
T_1 V_82 ;
V_82 = V_75 ^ V_2 -> V_83 ;
V_2 -> V_83 = V_75 ;
if ( V_82 & V_84 && V_2 -> V_85 &&
V_2 -> V_10 . V_11 != NULL ) {
if ( V_82 & V_86 )
V_2 -> V_10 . V_44 . V_87 ++ ;
if ( V_82 & V_88 )
V_2 -> V_10 . V_44 . V_89 ++ ;
if ( V_82 & V_90 )
F_43 ( & V_2 -> V_10 , V_75 & V_90 ) ;
if ( V_82 & V_91 )
F_44 ( & V_2 -> V_10 , V_75 & V_91 ) ;
F_45 ( & V_2 -> V_10 . V_11 -> V_10 . V_92 ) ;
}
return V_75 ;
}
static T_1 F_46 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_36 ( V_70 ) ;
T_1 V_51 = F_24 ( V_70 -> V_40 + V_41 ) ;
T_1 V_75 = 0 ;
if ( V_51 & V_93 )
V_75 |= V_91 ;
return F_47 ( V_2 -> V_81 , & V_75 ) ;
}
static void F_48 ( struct V_69 * V_10 )
{
struct V_1 * V_2 = F_36 ( V_10 ) ;
if ( V_2 -> V_85 )
return;
V_2 -> V_85 = true ;
if ( V_2 -> V_94 [ V_95 ] >= 0 )
F_49 ( V_2 -> V_94 [ V_95 ] ) ;
if ( V_2 -> V_94 [ V_96 ] >= 0 )
F_49 ( V_2 -> V_94 [ V_96 ] ) ;
if ( V_2 -> V_94 [ V_97 ] >= 0 )
F_49 ( V_2 -> V_94 [ V_97 ] ) ;
if ( V_2 -> V_94 [ V_98 ] >= 0 )
F_49 ( V_2 -> V_94 [ V_98 ] ) ;
}
static void F_50 ( struct V_69 * V_10 )
{
struct V_1 * V_2 = F_36 ( V_10 ) ;
if ( ! V_2 -> V_85 )
return;
V_2 -> V_85 = false ;
if ( V_2 -> V_94 [ V_95 ] >= 0 )
F_51 ( V_2 -> V_94 [ V_95 ] ) ;
if ( V_2 -> V_94 [ V_96 ] >= 0 )
F_51 ( V_2 -> V_94 [ V_96 ] ) ;
if ( V_2 -> V_94 [ V_97 ] >= 0 )
F_51 ( V_2 -> V_94 [ V_97 ] ) ;
if ( V_2 -> V_94 [ V_98 ] >= 0 )
F_51 ( V_2 -> V_94 [ V_98 ] ) ;
}
static void F_52 ( void * V_99 )
{
struct V_1 * V_2 = (struct V_1 * ) V_99 ;
struct V_100 * V_10 = & V_2 -> V_10 . V_11 -> V_10 ;
int V_101 ;
T_1 V_51 ;
F_4 ( V_2 -> V_12 , & V_2 -> V_102 , 1 , V_103 ) ;
V_51 = F_24 ( V_2 -> V_10 . V_40 + V_41 ) ;
V_51 &= ~ ( V_66 | V_55 |
V_58 | V_60 ) ;
V_101 = V_51 & V_104 ;
F_53 ( V_10 , V_2 -> V_105 , V_101 ) ;
F_25 ( V_51 , V_2 -> V_10 . V_40 + V_41 ) ;
F_31 ( V_10 ) ;
F_54 ( V_2 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_18 * V_19 ;
struct V_20 * V_21 = & V_2 -> V_102 ;
struct V_22 * V_23 = V_2 -> V_106 ;
T_1 V_25 [ 1 ] ;
V_25 [ 0 ] = V_107
| F_55 ( 0x80 )
| F_56 ( V_36 ) ;
V_19 = F_12 ( V_23 , (struct V_20 * ) V_25 ,
1 , V_26 , 0 ) ;
if ( ! V_19 ) {
F_13 ( V_2 -> V_12 , L_1 ) ;
return - V_27 ;
}
F_14 ( V_21 , V_2 -> V_105 , V_36 ) ;
F_15 ( V_2 -> V_12 , V_21 , 1 , V_103 ) ;
V_19 = F_12 ( V_23 , V_21 , 1 , V_108 ,
V_30 | V_31 ) ;
if ( ! V_19 ) {
F_13 ( V_2 -> V_12 , L_2 ) ;
return - 1 ;
}
V_19 -> V_32 = F_52 ;
V_19 -> V_33 = V_2 ;
F_16 ( V_19 ) ;
F_17 ( V_23 ) ;
return 0 ;
}
static void F_57 ( struct V_1 * V_2 )
{
if ( V_2 -> V_24 ) {
F_58 ( V_2 -> V_24 ) ;
V_2 -> V_24 = NULL ;
}
if ( V_2 -> V_106 ) {
F_58 ( V_2 -> V_106 ) ;
V_2 -> V_106 = NULL ;
}
F_59 ( V_2 -> V_28 ) ;
F_59 ( V_2 -> V_105 ) ;
V_2 -> V_28 = NULL ;
V_2 -> V_105 = NULL ;
}
static void F_60 ( struct V_1 * V_2 )
{
F_25 ( V_109 | V_110 | V_111 ,
V_2 -> V_10 . V_40 + V_112 ) ;
F_57 ( V_2 ) ;
V_2 -> V_5 &= ~ V_6 ;
F_5 ( V_15 , & V_2 -> V_5 ) ;
F_5 ( V_113 , & V_2 -> V_5 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
return 0 ;
V_2 -> V_106 = F_62 ( V_2 -> V_12 , L_3 ) ;
if ( ! V_2 -> V_106 )
goto V_114;
V_2 -> V_105 = F_63 ( V_36 , V_115 | V_116 ) ;
if ( ! V_2 -> V_105 )
goto V_114;
V_2 -> V_24 = F_62 ( V_2 -> V_12 , L_4 ) ;
if ( ! V_2 -> V_24 )
goto V_114;
V_2 -> V_28 = F_63 ( V_36 , V_115 | V_116 ) ;
if ( ! V_2 -> V_28 )
goto V_114;
V_2 -> V_5 |= V_6 ;
F_64 ( V_2 -> V_12 , L_5 ) ;
V_2 -> V_10 . V_117 = V_36 ;
return 0 ;
V_114:
F_57 ( V_2 ) ;
return - V_27 ;
}
static void F_65 ( struct V_69 * V_70 ,
struct V_118 * V_119 ,
struct V_118 * V_120 )
{
struct V_1 * V_2 = F_36 ( V_70 ) ;
T_1 V_121 , V_76 , V_122 , div ;
unsigned int V_123 , V_124 ;
V_123 = V_119 -> V_125 ;
V_76 = V_126 ;
V_122 = F_24 ( V_70 -> V_40 + V_77 ) ;
switch ( V_123 & V_127 ) {
case V_128 :
V_121 = 0 ;
break;
case V_129 :
V_121 = 1 ;
break;
case V_130 :
V_121 = 2 ;
break;
case V_131 :
V_121 = 3 ;
break;
default:
return;
}
V_76 |= F_66 ( V_121 ) ;
if ( V_123 & V_132 ) {
V_76 |= V_133 ;
if ( ( V_123 & V_134 ) == 0 )
V_76 |= V_135 ;
}
V_70 -> V_62 = 0 ;
if ( V_119 -> V_136 & V_137 )
V_70 -> V_62 |= V_58 ;
if ( V_119 -> V_136 & ( V_138 | V_139 | V_140 ) )
V_70 -> V_62 |= V_55 ;
V_70 -> V_141 = 0 ;
if ( V_119 -> V_136 & V_142 )
V_70 -> V_141 |= V_58 ;
if ( V_119 -> V_136 & V_138 ) {
V_70 -> V_141 |= V_55 ;
if ( V_119 -> V_136 & V_142 )
V_70 -> V_141 |= V_66 ;
}
if ( V_123 & V_143 )
V_122 |= V_144 ;
else
V_122 &= ~ V_144 ;
if ( V_123 & V_145 )
V_76 |= V_146 ;
V_122 &= ~ ( V_147 | V_78 ) ;
if ( V_123 & V_148 ) {
if ( F_1 ( V_2 )
&& F_67 ( V_149 , & V_2 -> V_5 ) ) {
if ( ! F_61 ( V_2 ) )
V_122 |= V_109 | V_110
| V_111 ;
}
V_122 |= V_78 ;
if ( F_68 () )
V_122 |= V_147 ;
}
V_124 = F_69 ( V_70 , V_119 , V_120 , 0 , V_70 -> V_150 ) ;
div = V_70 -> V_150 * 32 / V_124 ;
V_76 |= F_70 ( div & 0x3F ) ;
V_76 |= F_71 ( div >> 6 ) ;
F_25 ( V_76 , V_70 -> V_40 + V_151 ) ;
F_25 ( V_122 , V_70 -> V_40 + V_77 ) ;
F_72 ( V_70 , V_119 -> V_125 , V_124 ) ;
if ( F_2 ( V_2 ) &&
! F_18 ( V_113 , & V_2 -> V_5 ) ) {
if ( ! F_54 ( V_2 ) ) {
F_25 ( V_152 | V_153 ,
V_70 -> V_40 + V_48 ) ;
} else {
F_60 ( V_2 ) ;
F_13 ( V_2 -> V_12 , L_6 ) ;
}
}
if ( F_73 ( V_70 , V_119 -> V_125 ) )
F_48 ( V_70 ) ;
else
F_50 ( V_70 ) ;
}
static void F_74 ( struct V_69 * V_10 ,
struct V_118 * V_119 )
{
if ( V_119 -> V_154 == V_155 ) {
V_10 -> V_5 |= V_156 ;
F_48 ( V_10 ) ;
} else {
V_10 -> V_5 &= ~ V_156 ;
}
}
static T_3 F_75 ( int V_157 , void * V_158 )
{
T_1 V_159 ;
struct V_1 * V_2 = V_158 ;
T_1 V_160 = V_2 -> V_83 ;
T_1 V_51 = F_24 ( V_2 -> V_10 . V_40 + V_41 ) ;
V_159 = F_24 ( V_2 -> V_10 . V_40 + V_161 ) ;
F_25 ( V_159 & ( V_162
| V_163
| V_164
| V_165 ) ,
V_2 -> V_10 . V_40 + V_48 ) ;
if ( V_157 == V_2 -> V_94 [ V_95 ] ||
V_157 == V_2 -> V_94 [ V_98 ] ||
V_157 == V_2 -> V_94 [ V_96 ] ||
V_157 == V_2 -> V_94 [ V_97 ] )
F_42 ( V_2 ,
F_47 ( V_2 -> V_81 , & V_160 ) ) ;
if ( V_159 & V_165 ) {
if ( F_68 () && V_2 -> V_85 )
F_44 ( & V_2 -> V_10 ,
V_51 & V_93 ) ;
F_25 ( V_165 ,
V_2 -> V_10 . V_40 + V_48 ) ;
V_159 &= ~ V_165 ;
}
if ( V_159 & ( V_162 | V_164 ) ) {
if ( ! F_2 ( V_2 ) )
F_30 ( V_2 ) ;
V_159 &= ~ ( V_162 | V_164 ) ;
}
if ( V_159 & V_163 ) {
F_9 ( V_2 ) ;
V_159 &= ~ V_163 ;
}
return V_166 ;
}
static void F_76 ( struct V_69 * V_70 )
{
int V_34 ;
unsigned int V_167 ;
F_25 ( V_168 , V_70 -> V_40 + V_169 ) ;
for ( V_34 = 0 ; V_34 < 10000 ; V_34 ++ ) {
V_167 = F_24 ( V_70 -> V_40 + V_170 ) ;
if ( ! ( V_167 & V_168 ) )
break;
F_77 ( 3 ) ;
}
F_25 ( V_171 , V_70 -> V_40 + V_169 ) ;
}
static int F_78 ( struct V_69 * V_70 )
{
int V_172 ;
struct V_1 * V_2 = F_36 ( V_70 ) ;
V_172 = F_79 ( V_2 -> V_173 ) ;
if ( V_172 )
return V_172 ;
F_25 ( V_171 , V_70 -> V_40 + V_169 ) ;
F_25 ( V_174 , V_70 -> V_40 + V_175 ) ;
F_25 ( V_152 | V_153 | V_176 ,
V_70 -> V_40 + V_161 ) ;
V_70 -> V_117 = V_177 ;
F_25 ( V_126 , V_70 -> V_40 + V_178 ) ;
F_47 ( V_2 -> V_81 , & V_2 -> V_83 ) ;
V_2 -> V_85 = false ;
return 0 ;
}
static void F_80 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_36 ( V_70 ) ;
F_50 ( V_70 ) ;
if ( F_2 ( V_2 ) )
F_60 ( V_2 ) ;
F_25 ( V_174 , V_70 -> V_40 + V_112 ) ;
F_25 ( V_152 | V_153 | V_176 ,
V_70 -> V_40 + V_48 ) ;
F_25 ( V_171 , V_70 -> V_40 + V_179 ) ;
F_81 ( V_2 -> V_173 ) ;
}
static unsigned int F_82 ( struct V_69 * V_70 )
{
if ( ( F_24 ( V_70 -> V_40 + V_41 ) &
( V_180 | V_181 ) ) == V_180 )
return V_182 ;
return 0 ;
}
static void F_83 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_36 ( V_70 ) ;
F_25 ( V_183 , V_70 -> V_40 + V_175 ) ;
F_9 ( V_2 ) ;
}
static void F_23 ( struct V_69 * V_70 )
{
F_25 ( V_183 , V_70 -> V_40 + V_112 ) ;
}
static void F_84 ( struct V_69 * V_70 )
{
F_25 ( V_144 , V_70 -> V_40 + V_112 ) ;
}
static void F_85 ( struct V_69 * V_70 , int V_184 )
{
if ( V_184 )
F_25 ( V_185 ,
V_70 -> V_40 + V_178 ) ;
else
F_25 ( V_185 ,
V_70 -> V_40 + V_186 ) ;
}
static void F_86 ( struct V_69 * V_10 , int V_187 )
{
unsigned int V_188 = 1000 ;
while ( F_24 ( V_10 -> V_40 + V_41 ) & V_42 ) {
if ( ! V_188 -- )
break;
F_77 ( 1 ) ;
}
F_25 ( V_187 , V_10 -> V_40 + V_46 ) ;
}
static void
F_87 ( struct V_189 * V_190 , const char * V_191 , unsigned int V_101 )
{
struct V_1 * V_2 ;
struct V_69 * V_10 ;
unsigned int V_192 , V_193 ;
unsigned int V_188 = 20000 ;
if ( V_190 -> V_194 >= V_195 || V_190 -> V_194 < 0 )
return;
V_2 = V_196 [ V_190 -> V_194 ] ;
V_10 = & V_2 -> V_10 ;
F_88 ( V_2 -> V_173 ) ;
V_193 = F_24 ( V_10 -> V_40 + V_77 ) ;
V_192 = F_24 ( V_10 -> V_40 + V_170 ) ;
F_25 ( V_171 ,
V_10 -> V_40 + V_169 ) ;
F_25 ( V_174 | V_183 ,
V_10 -> V_40 + V_175 ) ;
F_89 ( V_10 , V_191 , V_101 , F_86 ) ;
while ( F_24 ( V_10 -> V_40 + V_41 ) & V_181 ) {
F_77 ( 1 ) ;
if ( ! V_188 -- )
break;
}
if ( ! ( F_24 ( V_10 -> V_40 + V_41 ) & V_181 ) ) {
F_25 ( V_192 , V_10 -> V_40 + V_170 ) ;
F_25 ( V_193 , V_10 -> V_40 + V_77 ) ;
}
F_90 ( V_2 -> V_173 ) ;
}
static void T_4
F_91 ( struct V_69 * V_10 , int * V_124 ,
int * V_59 , int * V_197 )
{
unsigned int V_198 , V_199 ;
if ( ! ( F_24 ( V_10 -> V_40 + V_77 ) & V_174 ) )
return;
V_198 = F_24 ( V_10 -> V_40 + V_151 ) ;
* V_59 = 'n' ;
if ( V_198 & V_133 ) {
if ( V_198 & V_135 )
* V_59 = 'e' ;
else
* V_59 = 'o' ;
}
if ( ( V_198 & V_200 ) == F_66 ( 2 ) )
* V_197 = 7 ;
else
* V_197 = 8 ;
V_199 = ( ( F_24 ( V_10 -> V_40 + V_151 )
& V_201 ) )
>> ( V_202 - 6 ) ;
V_199 |= ( ( F_24 ( V_10 -> V_40 + V_151 )
& V_203 ) )
>> V_204 ;
if ( V_199 == 0 )
V_199 = 1 ;
* V_124 = ( V_10 -> V_150 << 2 ) / V_199 ;
}
static int T_4
F_92 ( struct V_189 * V_190 , char * V_205 )
{
struct V_1 * V_2 ;
int V_124 = 9600 ;
int V_197 = 8 ;
int V_59 = 'n' ;
int V_206 = 'n' ;
int V_172 ;
if ( V_190 -> V_194 == - 1 || V_190 -> V_194 >= F_93 ( V_196 ) )
V_190 -> V_194 = 0 ;
V_2 = V_196 [ V_190 -> V_194 ] ;
if ( ! V_2 )
return - V_207 ;
V_172 = F_79 ( V_2 -> V_173 ) ;
if ( V_172 )
return V_172 ;
if ( V_205 )
F_94 ( V_205 , & V_124 , & V_59 , & V_197 , & V_206 ) ;
else
F_91 ( & V_2 -> V_10 , & V_124 , & V_59 , & V_197 ) ;
V_172 = F_95 ( & V_2 -> V_10 , V_190 , V_124 , V_59 , V_197 , V_206 ) ;
F_81 ( V_2 -> V_173 ) ;
return V_172 ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_208 * V_209 )
{
struct V_210 * V_211 = V_209 -> V_12 . V_212 ;
int V_172 ;
if ( ! V_211 )
return 1 ;
V_172 = F_97 ( V_211 , L_7 ) ;
if ( V_172 < 0 ) {
F_13 ( & V_209 -> V_12 , L_8 , V_172 ) ;
return V_172 ;
}
V_2 -> V_10 . line = V_172 ;
if ( F_98 ( V_211 , L_9 , NULL ) )
F_99 ( V_149 , & V_2 -> V_5 ) ;
return 0 ;
}
static bool F_100 ( struct V_1 * V_2 , struct V_213 * V_12 )
{
enum V_214 V_34 ;
struct V_215 * V_216 ;
V_2 -> V_81 = F_101 ( V_12 , 0 ) ;
if ( F_102 ( V_2 -> V_81 ) )
return false ;
if ( ! F_103 () || ! F_68 () ) {
if ( F_67 ( V_149 , & V_2 -> V_5 ) )
F_104 ( V_12 ,
L_10 ) ;
F_5 ( V_149 , & V_2 -> V_5 ) ;
}
for ( V_34 = 0 ; V_34 < V_217 ; V_34 ++ ) {
V_216 = F_105 ( V_2 -> V_81 , V_34 ) ;
if ( V_216 && ( F_106 ( V_216 ) == V_218 ) )
V_2 -> V_94 [ V_34 ] = F_107 ( V_216 ) ;
else
V_2 -> V_94 [ V_34 ] = - V_27 ;
}
return true ;
}
static void F_108 ( struct V_1 * V_2 )
{
enum V_214 V_34 ;
for ( V_34 = 0 ; V_34 < V_217 ; V_34 ++ )
if ( V_2 -> V_94 [ V_34 ] >= 0 )
F_109 ( V_2 -> V_94 [ V_34 ] , V_2 ) ;
}
static int F_110 ( struct V_1 * V_2 )
{
int * V_157 = V_2 -> V_94 ;
enum V_214 V_34 ;
int V_219 = 0 ;
for ( V_34 = 0 ; ( V_34 < V_217 ) && ! V_219 ; V_34 ++ ) {
if ( V_157 [ V_34 ] < 0 )
continue;
F_111 ( V_157 [ V_34 ] , V_220 ) ;
V_219 = F_112 ( V_157 [ V_34 ] , F_75 ,
V_221 , F_37 ( V_2 -> V_12 ) , V_2 ) ;
if ( V_219 )
F_13 ( V_2 -> V_12 , L_11 ,
V_222 , V_157 [ V_34 ] ) ;
}
while ( V_219 && ( -- V_34 >= 0 ) )
if ( V_157 [ V_34 ] >= 0 )
F_109 ( V_157 [ V_34 ] , V_2 ) ;
return V_219 ;
}
static int F_113 ( struct V_208 * V_209 )
{
const struct V_223 * V_224 =
F_114 ( V_225 , & V_209 -> V_12 ) ;
struct V_1 * V_2 ;
T_1 V_226 ;
int V_172 = 0 ;
struct V_227 * V_228 ;
V_2 = F_63 ( sizeof( struct V_1 ) , V_115 ) ;
if ( ! V_2 ) {
V_172 = - V_229 ;
goto V_57;
}
V_172 = F_96 ( V_2 , V_209 ) ;
if ( V_172 > 0 )
V_2 -> V_10 . line = V_209 -> V_230 < 0 ? 0 : V_209 -> V_230 ;
else if ( V_172 < 0 )
goto V_231;
if ( V_224 ) {
V_209 -> V_232 = V_224 -> V_233 ;
V_2 -> V_3 = V_209 -> V_232 -> V_234 ;
}
V_2 -> V_173 = F_115 ( & V_209 -> V_12 , NULL ) ;
if ( F_116 ( V_2 -> V_173 ) ) {
V_172 = F_117 ( V_2 -> V_173 ) ;
goto V_231;
}
V_228 = F_118 ( V_209 , V_235 , 0 ) ;
if ( ! V_228 ) {
V_172 = - V_236 ;
goto V_237;
}
V_2 -> V_10 . V_238 = V_228 -> V_239 ;
V_2 -> V_10 . V_40 = F_119 ( V_228 -> V_239 , F_120 ( V_228 ) ) ;
V_2 -> V_10 . V_240 = & V_241 ;
V_2 -> V_10 . V_242 = V_243 ;
V_2 -> V_10 . V_117 = V_177 ;
V_2 -> V_10 . V_150 = F_121 ( V_2 -> V_173 ) ;
V_2 -> V_10 . type = V_74 ;
V_2 -> V_10 . V_12 = V_2 -> V_12 = & V_209 -> V_12 ;
V_2 -> V_83 = 0 ;
V_2 -> V_157 = F_122 ( V_209 , 0 ) ;
V_2 -> V_10 . V_157 = V_2 -> V_157 ;
V_172 = F_112 ( V_2 -> V_157 , F_75 , 0 , F_37 ( & V_209 -> V_12 ) , V_2 ) ;
if ( V_172 )
goto V_237;
F_123 ( V_209 , V_2 ) ;
if ( ! F_100 ( V_2 , & V_209 -> V_12 ) )
F_13 ( & V_209 -> V_12 ,
L_12 ) ;
V_172 = F_110 ( V_2 ) ;
if ( V_172 )
goto V_244;
V_196 [ V_2 -> V_10 . line ] = V_2 ;
F_76 ( & V_2 -> V_10 ) ;
V_172 = F_124 ( & V_245 , & V_2 -> V_10 ) ;
if ( V_172 )
goto V_246;
V_226 = F_24 ( V_2 -> V_10 . V_40 + V_247 ) ;
F_125 ( & V_209 -> V_12 , L_13 ,
( V_226 >> 24 ) & 0xff ,
( V_226 >> 16 ) & 0xff , V_226 & 0xffff ) ;
return 0 ;
V_246:
F_108 ( V_2 ) ;
V_244:
V_196 [ V_209 -> V_230 ] = NULL ;
F_109 ( V_2 -> V_157 , V_2 ) ;
V_237:
F_126 ( V_2 -> V_173 ) ;
V_231:
F_59 ( V_2 ) ;
V_57:
return V_172 ;
}
static int F_127 ( struct V_208 * V_209 )
{
struct V_1 * V_2 = F_128 ( V_209 ) ;
F_129 ( & V_245 , & V_2 -> V_10 ) ;
V_196 [ V_209 -> V_230 ] = NULL ;
F_108 ( V_2 ) ;
F_126 ( V_2 -> V_173 ) ;
F_109 ( V_2 -> V_157 , V_2 ) ;
F_59 ( V_2 ) ;
return 0 ;
}
static int T_4 F_130 ( void )
{
int V_228 ;
V_228 = F_131 ( & V_245 ) ;
if ( V_228 )
goto V_57;
V_228 = F_132 ( & V_248 ) ;
if ( V_228 )
goto V_249;
return 0 ;
V_249:
F_133 ( & V_245 ) ;
V_57:
return V_228 ;
}
static void T_5 F_134 ( void )
{
F_135 ( & V_248 ) ;
F_133 ( & V_245 ) ;
}
