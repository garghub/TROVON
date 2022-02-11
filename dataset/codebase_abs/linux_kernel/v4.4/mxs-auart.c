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
unsigned int V_123 , V_124 , V_125 , V_126 ;
V_123 = V_119 -> V_127 ;
V_76 = V_128 ;
V_122 = F_24 ( V_70 -> V_40 + V_77 ) ;
switch ( V_123 & V_129 ) {
case V_130 :
V_121 = 0 ;
break;
case V_131 :
V_121 = 1 ;
break;
case V_132 :
V_121 = 2 ;
break;
case V_133 :
V_121 = 3 ;
break;
default:
return;
}
V_76 |= F_66 ( V_121 ) ;
if ( V_123 & V_134 ) {
V_76 |= V_135 ;
if ( ( V_123 & V_136 ) == 0 )
V_76 |= V_137 ;
}
V_70 -> V_62 = 0 ;
if ( V_119 -> V_138 & V_139 )
V_70 -> V_62 |= V_58 ;
if ( V_119 -> V_138 & ( V_140 | V_141 | V_142 ) )
V_70 -> V_62 |= V_55 ;
V_70 -> V_143 = 0 ;
if ( V_119 -> V_138 & V_144 )
V_70 -> V_143 |= V_58 ;
if ( V_119 -> V_138 & V_140 ) {
V_70 -> V_143 |= V_55 ;
if ( V_119 -> V_138 & V_144 )
V_70 -> V_143 |= V_66 ;
}
if ( V_123 & V_145 )
V_122 |= V_146 ;
else
V_122 &= ~ V_146 ;
if ( V_123 & V_147 )
V_76 |= V_148 ;
V_122 &= ~ ( V_149 | V_78 ) ;
if ( V_123 & V_150 ) {
if ( F_1 ( V_2 )
&& F_67 ( V_151 , & V_2 -> V_5 ) ) {
if ( ! F_61 ( V_2 ) )
V_122 |= V_109 | V_110
| V_111 ;
}
V_122 |= V_78 ;
if ( F_68 () )
V_122 |= V_149 ;
}
V_125 = F_69 ( V_70 -> V_152 * 32 , V_153 ) ;
V_126 = V_70 -> V_152 * 32 / V_154 ;
V_124 = F_70 ( V_70 , V_119 , V_120 , V_125 , V_126 ) ;
div = V_70 -> V_152 * 32 / V_124 ;
V_76 |= F_71 ( div & 0x3F ) ;
V_76 |= F_72 ( div >> 6 ) ;
F_25 ( V_76 , V_70 -> V_40 + V_155 ) ;
F_25 ( V_122 , V_70 -> V_40 + V_77 ) ;
F_73 ( V_70 , V_119 -> V_127 , V_124 ) ;
if ( F_2 ( V_2 ) &&
! F_18 ( V_113 , & V_2 -> V_5 ) ) {
if ( ! F_54 ( V_2 ) ) {
F_25 ( V_156 | V_157 ,
V_70 -> V_40 + V_48 ) ;
} else {
F_60 ( V_2 ) ;
F_13 ( V_2 -> V_12 , L_6 ) ;
}
}
if ( F_74 ( V_70 , V_119 -> V_127 ) )
F_48 ( V_70 ) ;
else
F_50 ( V_70 ) ;
}
static void F_75 ( struct V_69 * V_10 ,
struct V_118 * V_119 )
{
if ( V_119 -> V_158 == V_159 ) {
V_10 -> V_5 |= V_160 ;
F_48 ( V_10 ) ;
} else {
V_10 -> V_5 &= ~ V_160 ;
}
}
static T_3 F_76 ( int V_161 , void * V_162 )
{
T_1 V_163 ;
struct V_1 * V_2 = V_162 ;
T_1 V_164 = V_2 -> V_83 ;
T_1 V_51 = F_24 ( V_2 -> V_10 . V_40 + V_41 ) ;
V_163 = F_24 ( V_2 -> V_10 . V_40 + V_165 ) ;
F_25 ( V_163 & ( V_166
| V_167
| V_168
| V_169 ) ,
V_2 -> V_10 . V_40 + V_48 ) ;
if ( V_161 == V_2 -> V_94 [ V_95 ] ||
V_161 == V_2 -> V_94 [ V_98 ] ||
V_161 == V_2 -> V_94 [ V_96 ] ||
V_161 == V_2 -> V_94 [ V_97 ] )
F_42 ( V_2 ,
F_47 ( V_2 -> V_81 , & V_164 ) ) ;
if ( V_163 & V_169 ) {
if ( F_68 () && V_2 -> V_85 )
F_44 ( & V_2 -> V_10 ,
V_51 & V_93 ) ;
F_25 ( V_169 ,
V_2 -> V_10 . V_40 + V_48 ) ;
V_163 &= ~ V_169 ;
}
if ( V_163 & ( V_166 | V_168 ) ) {
if ( ! F_2 ( V_2 ) )
F_30 ( V_2 ) ;
V_163 &= ~ ( V_166 | V_168 ) ;
}
if ( V_163 & V_167 ) {
F_9 ( V_2 ) ;
V_163 &= ~ V_167 ;
}
return V_170 ;
}
static void F_77 ( struct V_69 * V_70 )
{
int V_34 ;
unsigned int V_171 ;
F_25 ( V_172 , V_70 -> V_40 + V_173 ) ;
for ( V_34 = 0 ; V_34 < 10000 ; V_34 ++ ) {
V_171 = F_24 ( V_70 -> V_40 + V_174 ) ;
if ( ! ( V_171 & V_172 ) )
break;
F_78 ( 3 ) ;
}
F_25 ( V_175 , V_70 -> V_40 + V_173 ) ;
}
static void F_79 ( struct V_69 * V_70 )
{
int V_34 ;
T_1 V_171 ;
V_171 = F_24 ( V_70 -> V_40 + V_174 ) ;
if ( V_171 & V_172 )
return;
F_25 ( V_175 , V_70 -> V_40 + V_173 ) ;
F_25 ( V_172 , V_70 -> V_40 + V_176 ) ;
for ( V_34 = 0 ; V_34 < 1000 ; V_34 ++ ) {
V_171 = F_24 ( V_70 -> V_40 + V_174 ) ;
if ( V_171 & V_175 )
return;
F_78 ( 10 ) ;
}
F_13 ( V_70 -> V_12 , L_7 ) ;
}
static int F_80 ( struct V_69 * V_70 )
{
int V_177 ;
struct V_1 * V_2 = F_36 ( V_70 ) ;
V_177 = F_81 ( V_2 -> V_178 ) ;
if ( V_177 )
return V_177 ;
if ( F_82 ( V_70 ) ) {
F_25 ( V_175 , V_70 -> V_40 + V_173 ) ;
} else {
F_79 ( V_70 ) ;
F_77 ( V_70 ) ;
}
F_25 ( V_179 , V_70 -> V_40 + V_180 ) ;
F_25 ( V_156 | V_157 | V_181 ,
V_70 -> V_40 + V_165 ) ;
V_70 -> V_117 = V_182 ;
F_25 ( V_128 , V_70 -> V_40 + V_183 ) ;
F_47 ( V_2 -> V_81 , & V_2 -> V_83 ) ;
V_2 -> V_85 = false ;
return 0 ;
}
static void F_83 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_36 ( V_70 ) ;
F_50 ( V_70 ) ;
if ( F_2 ( V_2 ) )
F_60 ( V_2 ) ;
if ( F_82 ( V_70 ) ) {
F_25 ( V_179 , V_70 -> V_40 + V_112 ) ;
F_25 ( V_156 | V_157 | V_181 ,
V_70 -> V_40 + V_48 ) ;
F_25 ( V_175 , V_70 -> V_40 + V_176 ) ;
} else {
F_79 ( V_70 ) ;
}
F_84 ( V_2 -> V_178 ) ;
}
static unsigned int F_85 ( struct V_69 * V_70 )
{
if ( ( F_24 ( V_70 -> V_40 + V_41 ) &
( V_184 | V_185 ) ) == V_184 )
return V_186 ;
return 0 ;
}
static void F_86 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_36 ( V_70 ) ;
F_25 ( V_187 , V_70 -> V_40 + V_180 ) ;
F_9 ( V_2 ) ;
}
static void F_23 ( struct V_69 * V_70 )
{
F_25 ( V_187 , V_70 -> V_40 + V_112 ) ;
}
static void F_87 ( struct V_69 * V_70 )
{
F_25 ( V_146 , V_70 -> V_40 + V_112 ) ;
}
static void F_88 ( struct V_69 * V_70 , int V_188 )
{
if ( V_188 )
F_25 ( V_189 ,
V_70 -> V_40 + V_183 ) ;
else
F_25 ( V_189 ,
V_70 -> V_40 + V_190 ) ;
}
static void F_89 ( struct V_69 * V_10 , int V_191 )
{
unsigned int V_192 = 1000 ;
while ( F_24 ( V_10 -> V_40 + V_41 ) & V_42 ) {
if ( ! V_192 -- )
break;
F_78 ( 1 ) ;
}
F_25 ( V_191 , V_10 -> V_40 + V_46 ) ;
}
static void
F_90 ( struct V_193 * V_194 , const char * V_195 , unsigned int V_101 )
{
struct V_1 * V_2 ;
struct V_69 * V_10 ;
unsigned int V_196 , V_197 ;
unsigned int V_192 = 20000 ;
if ( V_194 -> V_198 >= V_199 || V_194 -> V_198 < 0 )
return;
V_2 = V_200 [ V_194 -> V_198 ] ;
V_10 = & V_2 -> V_10 ;
F_91 ( V_2 -> V_178 ) ;
V_197 = F_24 ( V_10 -> V_40 + V_77 ) ;
V_196 = F_24 ( V_10 -> V_40 + V_174 ) ;
F_25 ( V_175 ,
V_10 -> V_40 + V_173 ) ;
F_25 ( V_179 | V_187 ,
V_10 -> V_40 + V_180 ) ;
F_92 ( V_10 , V_195 , V_101 , F_89 ) ;
while ( F_24 ( V_10 -> V_40 + V_41 ) & V_185 ) {
F_78 ( 1 ) ;
if ( ! V_192 -- )
break;
}
if ( ! ( F_24 ( V_10 -> V_40 + V_41 ) & V_185 ) ) {
F_25 ( V_196 , V_10 -> V_40 + V_174 ) ;
F_25 ( V_197 , V_10 -> V_40 + V_77 ) ;
}
F_93 ( V_2 -> V_178 ) ;
}
static void T_4
F_94 ( struct V_69 * V_10 , int * V_124 ,
int * V_59 , int * V_201 )
{
unsigned int V_202 , V_203 ;
if ( ! ( F_24 ( V_10 -> V_40 + V_77 ) & V_179 ) )
return;
V_202 = F_24 ( V_10 -> V_40 + V_155 ) ;
* V_59 = 'n' ;
if ( V_202 & V_135 ) {
if ( V_202 & V_137 )
* V_59 = 'e' ;
else
* V_59 = 'o' ;
}
if ( ( V_202 & V_204 ) == F_66 ( 2 ) )
* V_201 = 7 ;
else
* V_201 = 8 ;
V_203 = ( ( F_24 ( V_10 -> V_40 + V_155 )
& V_205 ) )
>> ( V_206 - 6 ) ;
V_203 |= ( ( F_24 ( V_10 -> V_40 + V_155 )
& V_207 ) )
>> V_208 ;
if ( V_203 == 0 )
V_203 = 1 ;
* V_124 = ( V_10 -> V_152 << 2 ) / V_203 ;
}
static int T_4
F_95 ( struct V_193 * V_194 , char * V_209 )
{
struct V_1 * V_2 ;
int V_124 = 9600 ;
int V_201 = 8 ;
int V_59 = 'n' ;
int V_210 = 'n' ;
int V_177 ;
if ( V_194 -> V_198 == - 1 || V_194 -> V_198 >= F_96 ( V_200 ) )
V_194 -> V_198 = 0 ;
V_2 = V_200 [ V_194 -> V_198 ] ;
if ( ! V_2 )
return - V_211 ;
V_177 = F_81 ( V_2 -> V_178 ) ;
if ( V_177 )
return V_177 ;
if ( V_209 )
F_97 ( V_209 , & V_124 , & V_59 , & V_201 , & V_210 ) ;
else
F_94 ( & V_2 -> V_10 , & V_124 , & V_59 , & V_201 ) ;
V_177 = F_98 ( & V_2 -> V_10 , V_194 , V_124 , V_59 , V_201 , V_210 ) ;
F_84 ( V_2 -> V_178 ) ;
return V_177 ;
}
static int F_99 ( struct V_1 * V_2 ,
struct V_212 * V_213 )
{
struct V_214 * V_215 = V_213 -> V_12 . V_216 ;
int V_177 ;
if ( ! V_215 )
return 1 ;
V_177 = F_100 ( V_215 , L_8 ) ;
if ( V_177 < 0 ) {
F_13 ( & V_213 -> V_12 , L_9 , V_177 ) ;
return V_177 ;
}
V_2 -> V_10 . line = V_177 ;
if ( F_101 ( V_215 , L_10 , NULL ) )
F_102 ( V_151 , & V_2 -> V_5 ) ;
return 0 ;
}
static int F_103 ( struct V_1 * V_2 , struct V_217 * V_12 )
{
enum V_218 V_34 ;
struct V_219 * V_220 ;
V_2 -> V_81 = F_104 ( V_12 , 0 ) ;
if ( F_105 ( V_2 -> V_81 ) )
return F_106 ( V_2 -> V_81 ) ;
if ( ! F_107 () || ! F_68 () ) {
if ( F_67 ( V_151 , & V_2 -> V_5 ) )
F_108 ( V_12 ,
L_11 ) ;
F_5 ( V_151 , & V_2 -> V_5 ) ;
}
for ( V_34 = 0 ; V_34 < V_221 ; V_34 ++ ) {
V_220 = F_109 ( V_2 -> V_81 , V_34 ) ;
if ( V_220 && ( F_110 ( V_220 ) == V_222 ) )
V_2 -> V_94 [ V_34 ] = F_111 ( V_220 ) ;
else
V_2 -> V_94 [ V_34 ] = - V_27 ;
}
return 0 ;
}
static void F_112 ( struct V_1 * V_2 )
{
enum V_218 V_34 ;
for ( V_34 = 0 ; V_34 < V_221 ; V_34 ++ )
if ( V_2 -> V_94 [ V_34 ] >= 0 )
F_113 ( V_2 -> V_94 [ V_34 ] , V_2 ) ;
}
static int F_114 ( struct V_1 * V_2 )
{
int * V_161 = V_2 -> V_94 ;
enum V_218 V_34 ;
int V_223 = 0 ;
for ( V_34 = 0 ; ( V_34 < V_221 ) && ! V_223 ; V_34 ++ ) {
if ( V_161 [ V_34 ] < 0 )
continue;
F_115 ( V_161 [ V_34 ] , V_224 ) ;
V_223 = F_116 ( V_161 [ V_34 ] , F_76 ,
V_225 , F_37 ( V_2 -> V_12 ) , V_2 ) ;
if ( V_223 )
F_13 ( V_2 -> V_12 , L_12 ,
V_226 , V_161 [ V_34 ] ) ;
}
while ( V_223 && ( -- V_34 >= 0 ) )
if ( V_161 [ V_34 ] >= 0 )
F_113 ( V_161 [ V_34 ] , V_2 ) ;
return V_223 ;
}
static int F_117 ( struct V_212 * V_213 )
{
const struct V_227 * V_228 =
F_118 ( V_229 , & V_213 -> V_12 ) ;
struct V_1 * V_2 ;
T_1 V_230 ;
int V_177 , V_161 ;
struct V_231 * V_232 ;
V_2 = F_119 ( & V_213 -> V_12 , sizeof( * V_2 ) , V_115 ) ;
if ( ! V_2 )
return - V_233 ;
V_177 = F_99 ( V_2 , V_213 ) ;
if ( V_177 > 0 )
V_2 -> V_10 . line = V_213 -> V_234 < 0 ? 0 : V_213 -> V_234 ;
else if ( V_177 < 0 )
return V_177 ;
if ( V_228 ) {
V_213 -> V_235 = V_228 -> V_236 ;
V_2 -> V_3 = V_213 -> V_235 -> V_237 ;
}
V_2 -> V_178 = F_120 ( & V_213 -> V_12 , NULL ) ;
if ( F_105 ( V_2 -> V_178 ) )
return F_106 ( V_2 -> V_178 ) ;
V_232 = F_121 ( V_213 , V_238 , 0 ) ;
if ( ! V_232 )
return - V_239 ;
V_2 -> V_10 . V_240 = V_232 -> V_241 ;
V_2 -> V_10 . V_40 = F_122 ( V_232 -> V_241 , F_123 ( V_232 ) ) ;
V_2 -> V_10 . V_242 = & V_243 ;
V_2 -> V_10 . V_244 = V_245 ;
V_2 -> V_10 . V_117 = V_182 ;
V_2 -> V_10 . V_152 = F_124 ( V_2 -> V_178 ) ;
V_2 -> V_10 . type = V_74 ;
V_2 -> V_10 . V_12 = V_2 -> V_12 = & V_213 -> V_12 ;
V_2 -> V_83 = 0 ;
V_161 = F_125 ( V_213 , 0 ) ;
if ( V_161 < 0 )
return V_161 ;
V_2 -> V_10 . V_161 = V_161 ;
V_177 = F_126 ( & V_213 -> V_12 , V_161 , F_76 , 0 ,
F_37 ( & V_213 -> V_12 ) , V_2 ) ;
if ( V_177 )
return V_177 ;
F_127 ( V_213 , V_2 ) ;
V_177 = F_103 ( V_2 , & V_213 -> V_12 ) ;
if ( V_177 ) {
F_13 ( & V_213 -> V_12 , L_13 ) ;
return V_177 ;
}
V_177 = F_114 ( V_2 ) ;
if ( V_177 )
return V_177 ;
V_200 [ V_2 -> V_10 . line ] = V_2 ;
F_77 ( & V_2 -> V_10 ) ;
V_177 = F_128 ( & V_246 , & V_2 -> V_10 ) ;
if ( V_177 )
goto V_247;
V_230 = F_24 ( V_2 -> V_10 . V_40 + V_248 ) ;
F_129 ( & V_213 -> V_12 , L_14 ,
( V_230 >> 24 ) & 0xff ,
( V_230 >> 16 ) & 0xff , V_230 & 0xffff ) ;
return 0 ;
V_247:
F_112 ( V_2 ) ;
V_200 [ V_213 -> V_234 ] = NULL ;
return V_177 ;
}
static int F_130 ( struct V_212 * V_213 )
{
struct V_1 * V_2 = F_131 ( V_213 ) ;
F_132 ( & V_246 , & V_2 -> V_10 ) ;
V_200 [ V_213 -> V_234 ] = NULL ;
F_112 ( V_2 ) ;
return 0 ;
}
static int T_4 F_133 ( void )
{
int V_232 ;
V_232 = F_134 ( & V_246 ) ;
if ( V_232 )
goto V_57;
V_232 = F_135 ( & V_249 ) ;
if ( V_232 )
goto V_250;
return 0 ;
V_250:
F_136 ( & V_246 ) ;
V_57:
return V_232 ;
}
static void T_5 F_137 ( void )
{
F_138 ( & V_249 ) ;
F_136 ( & V_246 ) ;
}
