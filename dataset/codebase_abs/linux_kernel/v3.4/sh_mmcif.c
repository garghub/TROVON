static inline void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , T_1 V_4 )
{
F_2 ( V_4 | F_3 ( V_2 -> V_5 + V_3 ) , V_2 -> V_5 + V_3 ) ;
}
static inline void F_4 ( struct V_1 * V_2 ,
unsigned int V_3 , T_1 V_4 )
{
F_2 ( ~ V_4 & F_3 ( V_2 -> V_5 + V_3 ) , V_2 -> V_5 + V_3 ) ;
}
static void F_5 ( void * V_6 )
{
struct V_1 * V_2 = V_6 ;
struct V_7 * V_8 = V_2 -> V_9 -> V_8 ;
F_6 ( & V_2 -> V_10 -> V_11 , L_1 ) ;
if ( F_7 ( ! V_8 , L_2 ,
F_8 ( & V_2 -> V_10 -> V_11 ) ) )
return;
if ( V_8 -> V_12 & V_13 )
F_9 ( V_2 -> V_14 -> V_15 -> V_11 ,
V_8 -> V_16 , V_8 -> V_17 ,
V_18 ) ;
else
F_9 ( V_2 -> V_19 -> V_15 -> V_11 ,
V_8 -> V_16 , V_8 -> V_17 ,
V_20 ) ;
F_10 ( & V_2 -> V_21 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 -> V_8 ;
struct V_22 * V_16 = V_8 -> V_16 ;
struct V_23 * V_24 = NULL ;
struct V_25 * V_26 = V_2 -> V_14 ;
T_2 V_27 = - V_28 ;
int V_29 ;
V_29 = F_12 ( V_26 -> V_15 -> V_11 , V_16 , V_8 -> V_17 ,
V_18 ) ;
if ( V_29 > 0 ) {
V_2 -> V_30 = true ;
V_24 = F_13 ( V_26 , V_16 , V_29 ,
V_31 , V_32 | V_33 ) ;
}
if ( V_24 ) {
V_24 -> V_34 = F_5 ;
V_24 -> V_35 = V_2 ;
V_27 = F_14 ( V_24 ) ;
F_1 ( V_2 , V_36 , V_37 ) ;
F_15 ( V_26 ) ;
}
F_6 ( & V_2 -> V_10 -> V_11 , L_3 ,
V_38 , V_8 -> V_17 , V_29 , V_27 ) ;
if ( ! V_24 ) {
if ( V_29 >= 0 )
V_29 = - V_39 ;
V_2 -> V_14 = NULL ;
V_2 -> V_30 = false ;
F_16 ( V_26 ) ;
V_26 = V_2 -> V_19 ;
if ( V_26 ) {
V_2 -> V_19 = NULL ;
F_16 ( V_26 ) ;
}
F_17 ( & V_2 -> V_10 -> V_11 ,
L_4 , V_29 ) ;
F_4 ( V_2 , V_36 , V_37 | V_40 ) ;
}
F_6 ( & V_2 -> V_10 -> V_11 , L_5 , V_38 ,
V_24 , V_27 , V_8 -> V_17 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 -> V_8 ;
struct V_22 * V_16 = V_8 -> V_16 ;
struct V_23 * V_24 = NULL ;
struct V_25 * V_26 = V_2 -> V_19 ;
T_2 V_27 = - V_28 ;
int V_29 ;
V_29 = F_12 ( V_26 -> V_15 -> V_11 , V_16 , V_8 -> V_17 ,
V_20 ) ;
if ( V_29 > 0 ) {
V_2 -> V_30 = true ;
V_24 = F_13 ( V_26 , V_16 , V_29 ,
V_41 , V_32 | V_33 ) ;
}
if ( V_24 ) {
V_24 -> V_34 = F_5 ;
V_24 -> V_35 = V_2 ;
V_27 = F_14 ( V_24 ) ;
F_1 ( V_2 , V_36 , V_40 ) ;
F_15 ( V_26 ) ;
}
F_6 ( & V_2 -> V_10 -> V_11 , L_3 ,
V_38 , V_8 -> V_17 , V_29 , V_27 ) ;
if ( ! V_24 ) {
if ( V_29 >= 0 )
V_29 = - V_39 ;
V_2 -> V_19 = NULL ;
V_2 -> V_30 = false ;
F_16 ( V_26 ) ;
V_26 = V_2 -> V_14 ;
if ( V_26 ) {
V_2 -> V_14 = NULL ;
F_16 ( V_26 ) ;
}
F_17 ( & V_2 -> V_10 -> V_11 ,
L_4 , V_29 ) ;
F_4 ( V_2 , V_36 , V_37 | V_40 ) ;
}
F_6 ( & V_2 -> V_10 -> V_11 , L_6 , V_38 ,
V_24 , V_27 ) ;
}
static bool F_19 ( struct V_25 * V_26 , void * V_6 )
{
F_6 ( V_26 -> V_15 -> V_11 , L_7 , V_38 , V_6 ) ;
V_26 -> V_42 = V_6 ;
return true ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
struct V_45 * V_46 , * V_47 ;
V_2 -> V_30 = false ;
if ( V_44 -> V_48 ) {
F_17 ( & V_2 -> V_10 -> V_11 ,
L_8 ) ;
V_46 = & V_44 -> V_48 -> V_49 ;
V_47 = & V_44 -> V_48 -> V_50 ;
} else {
V_46 = & V_2 -> V_51 ;
V_46 -> V_52 = V_44 -> V_53 ;
V_47 = & V_2 -> V_54 ;
V_47 -> V_52 = V_44 -> V_55 ;
}
if ( V_46 -> V_52 > 0 && V_47 -> V_52 > 0 ) {
T_3 V_56 ;
F_21 ( V_56 ) ;
F_22 ( V_57 , V_56 ) ;
V_2 -> V_19 = F_23 ( V_56 , F_19 , V_46 ) ;
F_6 ( & V_2 -> V_10 -> V_11 , L_9 , V_38 ,
V_2 -> V_19 ) ;
if ( ! V_2 -> V_19 )
return;
V_2 -> V_14 = F_23 ( V_56 , F_19 , V_47 ) ;
F_6 ( & V_2 -> V_10 -> V_11 , L_10 , V_38 ,
V_2 -> V_14 ) ;
if ( ! V_2 -> V_14 ) {
F_16 ( V_2 -> V_19 ) ;
V_2 -> V_19 = NULL ;
return;
}
F_24 ( & V_2 -> V_21 ) ;
}
}
static void F_25 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_36 , V_37 | V_40 ) ;
if ( V_2 -> V_19 ) {
struct V_25 * V_26 = V_2 -> V_19 ;
V_2 -> V_19 = NULL ;
F_16 ( V_26 ) ;
}
if ( V_2 -> V_14 ) {
struct V_25 * V_26 = V_2 -> V_14 ;
V_2 -> V_14 = NULL ;
F_16 ( V_26 ) ;
}
V_2 -> V_30 = false ;
}
static void F_26 ( struct V_1 * V_2 , unsigned int V_58 )
{
struct V_43 * V_59 = V_2 -> V_10 -> V_11 . V_60 ;
F_4 ( V_2 , V_61 , V_62 ) ;
F_4 ( V_2 , V_61 , V_63 ) ;
if ( ! V_58 )
return;
if ( V_59 -> V_64 && V_58 == V_2 -> V_58 )
F_1 ( V_2 , V_61 , V_65 ) ;
else
F_1 ( V_2 , V_61 , V_63 &
( ( F_27 ( F_28 ( V_2 -> V_58 ,
V_58 ) - 1 ) - 1 ) << 16 ) ) ;
F_1 ( V_2 , V_61 , V_62 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
T_1 V_66 ;
V_66 = 0x010f0000 & F_30 ( V_2 -> V_5 , V_61 ) ;
F_31 ( V_2 -> V_5 , V_67 , V_68 ) ;
F_31 ( V_2 -> V_5 , V_67 , V_69 ) ;
F_1 ( V_2 , V_61 , V_66 |
V_70 | V_71 | V_72 | V_73 ) ;
F_1 ( V_2 , V_36 , V_74 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
T_1 V_75 , V_76 ;
int V_29 , V_77 ;
V_2 -> V_78 = false ;
V_75 = F_30 ( V_2 -> V_5 , V_79 ) ;
V_76 = F_30 ( V_2 -> V_5 , V_80 ) ;
F_6 ( & V_2 -> V_10 -> V_11 , L_11 , V_75 ) ;
F_6 ( & V_2 -> V_10 -> V_11 , L_12 , V_76 ) ;
if ( V_75 & V_81 ) {
F_1 ( V_2 , V_82 , V_83 ) ;
F_1 ( V_2 , V_82 , ~ V_83 ) ;
for ( V_77 = 10000000 ; V_77 ; V_77 -- ) {
if ( ! ( F_30 ( V_2 -> V_5 , V_79 )
& V_81 ) )
break;
F_33 ( 1 ) ;
}
if ( ! V_77 ) {
F_34 ( & V_2 -> V_10 -> V_11 ,
L_13 ) ;
return - V_39 ;
}
F_29 ( V_2 ) ;
F_6 ( & V_2 -> V_10 -> V_11 , L_14 ) ;
return - V_39 ;
}
if ( V_76 & V_84 ) {
F_6 ( & V_2 -> V_10 -> V_11 , L_15 ) ;
V_29 = - V_39 ;
} else if ( V_76 & V_85 ) {
F_6 ( & V_2 -> V_10 -> V_11 , L_16 ) ;
V_29 = - V_86 ;
} else {
F_6 ( & V_2 -> V_10 -> V_11 , L_17 ) ;
V_29 = - V_39 ;
}
return V_29 ;
}
static bool F_35 ( struct V_1 * V_2 , T_1 * V_59 )
{
struct V_7 * V_8 = V_2 -> V_9 -> V_8 ;
V_2 -> V_87 += V_2 -> V_88 ;
F_36 ( V_2 -> V_87 > V_8 -> V_16 -> V_89 ) ;
if ( V_2 -> V_87 == V_8 -> V_16 -> V_89 ) {
V_2 -> V_87 = 0 ;
if ( ++ V_2 -> V_90 < V_8 -> V_17 )
V_2 -> V_91 = F_37 ( ++ V_8 -> V_16 ) ;
} else {
V_2 -> V_91 = V_59 ;
}
if ( V_2 -> V_90 == V_8 -> V_17 )
return false ;
return true ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_92 * V_9 )
{
V_2 -> V_88 = ( F_30 ( V_2 -> V_5 , V_93 ) &
V_94 ) + 3 ;
V_2 -> V_95 = V_96 ;
F_39 ( & V_2 -> V_97 , V_2 -> V_77 ) ;
F_1 ( V_2 , V_98 , V_99 ) ;
}
static bool F_40 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 -> V_8 ;
T_1 * V_59 = F_37 ( V_8 -> V_16 ) ;
int V_100 ;
if ( V_2 -> V_78 ) {
V_8 -> error = F_32 ( V_2 ) ;
return false ;
}
for ( V_100 = 0 ; V_100 < V_2 -> V_88 / 4 ; V_100 ++ )
* V_59 ++ = F_30 ( V_2 -> V_5 , V_101 ) ;
F_1 ( V_2 , V_98 , V_102 ) ;
V_2 -> V_95 = V_103 ;
return true ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_92 * V_9 )
{
struct V_7 * V_8 = V_9 -> V_8 ;
if ( ! V_8 -> V_17 || ! V_8 -> V_16 -> V_89 )
return;
V_2 -> V_88 = F_30 ( V_2 -> V_5 , V_93 ) &
V_94 ;
V_2 -> V_95 = V_104 ;
V_2 -> V_90 = 0 ;
V_2 -> V_87 = 0 ;
V_2 -> V_91 = F_37 ( V_8 -> V_16 ) ;
F_39 ( & V_2 -> V_97 , V_2 -> V_77 ) ;
F_1 ( V_2 , V_98 , V_99 ) ;
}
static bool F_42 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 -> V_8 ;
T_1 * V_59 = V_2 -> V_91 ;
int V_100 ;
if ( V_2 -> V_78 ) {
V_8 -> error = F_32 ( V_2 ) ;
return false ;
}
F_36 ( ! V_8 -> V_16 -> V_89 ) ;
for ( V_100 = 0 ; V_100 < V_2 -> V_88 / 4 ; V_100 ++ )
* V_59 ++ = F_30 ( V_2 -> V_5 , V_101 ) ;
if ( ! F_35 ( V_2 , V_59 ) )
return false ;
F_39 ( & V_2 -> V_97 , V_2 -> V_77 ) ;
F_1 ( V_2 , V_98 , V_99 ) ;
return true ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_92 * V_9 )
{
V_2 -> V_88 = ( F_30 ( V_2 -> V_5 , V_93 ) &
V_94 ) + 3 ;
V_2 -> V_95 = V_105 ;
F_39 ( & V_2 -> V_97 , V_2 -> V_77 ) ;
F_1 ( V_2 , V_98 , V_106 ) ;
}
static bool F_44 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 -> V_8 ;
T_1 * V_59 = F_37 ( V_8 -> V_16 ) ;
int V_100 ;
if ( V_2 -> V_78 ) {
V_8 -> error = F_32 ( V_2 ) ;
return false ;
}
for ( V_100 = 0 ; V_100 < V_2 -> V_88 / 4 ; V_100 ++ )
F_31 ( V_2 -> V_5 , V_101 , * V_59 ++ ) ;
F_1 ( V_2 , V_98 , V_107 ) ;
V_2 -> V_95 = V_108 ;
return true ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_92 * V_9 )
{
struct V_7 * V_8 = V_9 -> V_8 ;
if ( ! V_8 -> V_17 || ! V_8 -> V_16 -> V_89 )
return;
V_2 -> V_88 = F_30 ( V_2 -> V_5 , V_93 ) &
V_94 ;
V_2 -> V_95 = V_109 ;
V_2 -> V_90 = 0 ;
V_2 -> V_87 = 0 ;
V_2 -> V_91 = F_37 ( V_8 -> V_16 ) ;
F_39 ( & V_2 -> V_97 , V_2 -> V_77 ) ;
F_1 ( V_2 , V_98 , V_106 ) ;
}
static bool F_46 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_9 -> V_8 ;
T_1 * V_59 = V_2 -> V_91 ;
int V_100 ;
if ( V_2 -> V_78 ) {
V_8 -> error = F_32 ( V_2 ) ;
return false ;
}
F_36 ( ! V_8 -> V_16 -> V_89 ) ;
for ( V_100 = 0 ; V_100 < V_2 -> V_88 / 4 ; V_100 ++ )
F_31 ( V_2 -> V_5 , V_101 , * V_59 ++ ) ;
if ( ! F_35 ( V_2 , V_59 ) )
return false ;
F_39 ( & V_2 -> V_97 , V_2 -> V_77 ) ;
F_1 ( V_2 , V_98 , V_106 ) ;
return true ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_110 * V_111 )
{
if ( V_111 -> V_12 & V_112 ) {
V_111 -> V_113 [ 0 ] = F_30 ( V_2 -> V_5 , V_114 ) ;
V_111 -> V_113 [ 1 ] = F_30 ( V_2 -> V_5 , V_115 ) ;
V_111 -> V_113 [ 2 ] = F_30 ( V_2 -> V_5 , V_116 ) ;
V_111 -> V_113 [ 3 ] = F_30 ( V_2 -> V_5 , V_117 ) ;
} else
V_111 -> V_113 [ 0 ] = F_30 ( V_2 -> V_5 , V_117 ) ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_110 * V_111 )
{
V_111 -> V_113 [ 0 ] = F_30 ( V_2 -> V_5 , V_118 ) ;
}
static T_1 F_49 ( struct V_1 * V_2 ,
struct V_92 * V_9 )
{
struct V_7 * V_8 = V_9 -> V_8 ;
struct V_110 * V_111 = V_9 -> V_111 ;
T_1 V_119 = V_111 -> V_120 ;
T_1 V_66 = 0 ;
switch ( F_50 ( V_111 ) ) {
case V_121 :
V_66 |= V_122 ;
break;
case V_123 :
case V_124 :
case V_125 :
V_66 |= V_126 ;
break;
case V_127 :
V_66 |= V_128 ;
break;
default:
F_34 ( & V_2 -> V_10 -> V_11 , L_18 ) ;
break;
}
switch ( V_119 ) {
case V_129 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
V_66 |= V_134 ;
break;
}
if ( V_8 ) {
V_66 |= V_135 ;
switch ( V_2 -> V_136 ) {
case V_137 :
V_66 |= V_138 ;
break;
case V_139 :
V_66 |= V_140 ;
break;
case V_141 :
V_66 |= V_142 ;
break;
default:
F_34 ( & V_2 -> V_10 -> V_11 , L_19 ) ;
break;
}
}
if ( V_119 == V_143 || V_119 == V_144 )
V_66 |= V_145 ;
if ( V_119 == V_146 || V_119 == V_144 ) {
V_66 |= V_147 | V_148 ;
F_1 ( V_2 , V_93 ,
V_8 -> V_149 << 16 ) ;
}
if ( V_119 == V_150 || V_119 == V_151 ||
V_119 == V_152 || V_119 == V_153 )
V_66 |= V_154 ;
if ( V_119 == V_150 )
V_66 |= V_155 ;
if ( V_119 == V_151 ||
V_119 == V_152 || V_119 == V_153 )
V_66 |= V_156 ;
return ( V_119 << 24 ) | V_66 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_92 * V_9 , T_1 V_119 )
{
switch ( V_119 ) {
case V_146 :
F_41 ( V_2 , V_9 ) ;
return 0 ;
case V_144 :
F_45 ( V_2 , V_9 ) ;
return 0 ;
case V_143 :
F_43 ( V_2 , V_9 ) ;
return 0 ;
case V_157 :
case V_158 :
F_38 ( V_2 , V_9 ) ;
return 0 ;
default:
F_34 ( & V_2 -> V_10 -> V_11 , L_20 , V_119 ) ;
return - V_28 ;
}
}
static void F_52 ( struct V_1 * V_2 ,
struct V_92 * V_9 )
{
struct V_110 * V_111 = V_9 -> V_111 ;
T_1 V_119 = V_111 -> V_120 ;
T_1 V_56 ;
switch ( V_119 ) {
case V_129 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
V_56 = V_159 | V_160 ;
break;
default:
V_56 = V_159 | V_161 ;
break;
}
if ( V_9 -> V_8 ) {
F_31 ( V_2 -> V_5 , V_93 , 0 ) ;
F_31 ( V_2 -> V_5 , V_93 ,
V_9 -> V_8 -> V_162 ) ;
}
V_119 = F_49 ( V_2 , V_9 ) ;
F_31 ( V_2 -> V_5 , V_163 , 0xD80430C0 ) ;
F_31 ( V_2 -> V_5 , V_98 , V_56 ) ;
F_31 ( V_2 -> V_5 , V_164 , V_111 -> V_6 ) ;
F_31 ( V_2 -> V_5 , V_165 , V_119 ) ;
V_2 -> V_95 = V_166 ;
F_39 ( & V_2 -> V_97 , V_2 -> V_77 ) ;
}
static void F_53 ( struct V_1 * V_2 ,
struct V_92 * V_9 )
{
switch ( V_9 -> V_111 -> V_120 ) {
case V_146 :
F_1 ( V_2 , V_98 , V_167 ) ;
break;
case V_144 :
F_1 ( V_2 , V_98 , V_168 ) ;
break;
default:
F_34 ( & V_2 -> V_10 -> V_11 , L_21 ) ;
V_9 -> V_169 -> error = F_32 ( V_2 ) ;
return;
}
V_2 -> V_95 = V_170 ;
F_39 ( & V_2 -> V_97 , V_2 -> V_77 ) ;
}
static void F_54 ( struct V_171 * V_172 , struct V_92 * V_9 )
{
struct V_1 * V_2 = F_55 ( V_172 ) ;
unsigned long V_12 ;
F_56 ( & V_2 -> V_173 , V_12 ) ;
if ( V_2 -> V_174 != V_175 ) {
F_57 ( & V_2 -> V_173 , V_12 ) ;
V_9 -> V_111 -> error = - V_176 ;
F_58 ( V_172 , V_9 ) ;
return;
}
V_2 -> V_174 = V_177 ;
F_57 ( & V_2 -> V_173 , V_12 ) ;
switch ( V_9 -> V_111 -> V_120 ) {
case V_178 :
case V_179 :
V_2 -> V_174 = V_175 ;
V_9 -> V_111 -> error = - V_86 ;
F_58 ( V_172 , V_9 ) ;
return;
case V_158 :
if ( ! V_9 -> V_8 ) {
V_2 -> V_174 = V_175 ;
V_9 -> V_111 -> error = - V_86 ;
F_58 ( V_172 , V_9 ) ;
return;
}
break;
default:
break;
}
V_2 -> V_9 = V_9 ;
F_52 ( V_2 , V_9 ) ;
}
static void F_59 ( struct V_171 * V_172 , struct V_180 * V_181 )
{
struct V_1 * V_2 = F_55 ( V_172 ) ;
struct V_43 * V_59 = V_2 -> V_10 -> V_11 . V_60 ;
unsigned long V_12 ;
F_56 ( & V_2 -> V_173 , V_12 ) ;
if ( V_2 -> V_174 != V_175 ) {
F_57 ( & V_2 -> V_173 , V_12 ) ;
return;
}
V_2 -> V_174 = V_182 ;
F_57 ( & V_2 -> V_173 , V_12 ) ;
if ( V_181 -> V_183 == V_184 ) {
if ( ! V_2 -> V_185 ) {
F_20 ( V_2 , V_2 -> V_10 -> V_11 . V_60 ) ;
V_2 -> V_185 = true ;
}
} else if ( V_181 -> V_183 == V_186 || ! V_181 -> clock ) {
F_26 ( V_2 , 0 ) ;
if ( V_181 -> V_183 == V_186 ) {
if ( V_2 -> V_185 ) {
F_25 ( V_2 ) ;
V_2 -> V_185 = false ;
}
}
if ( V_2 -> V_187 ) {
F_60 ( & V_2 -> V_10 -> V_11 ) ;
V_2 -> V_187 = false ;
if ( V_59 -> V_188 && V_181 -> V_183 == V_186 )
V_59 -> V_188 ( V_2 -> V_10 ) ;
}
V_2 -> V_174 = V_175 ;
return;
}
if ( V_181 -> clock ) {
if ( ! V_2 -> V_187 ) {
if ( V_59 -> V_189 )
V_59 -> V_189 ( V_2 -> V_10 , V_181 -> V_183 ) ;
F_61 ( & V_2 -> V_10 -> V_11 ) ;
V_2 -> V_187 = true ;
F_29 ( V_2 ) ;
}
F_26 ( V_2 , V_181 -> clock ) ;
}
V_2 -> V_136 = V_181 -> V_136 ;
V_2 -> V_174 = V_175 ;
}
static int F_62 ( struct V_171 * V_172 )
{
struct V_1 * V_2 = F_55 ( V_172 ) ;
struct V_43 * V_59 = V_2 -> V_10 -> V_11 . V_60 ;
if ( ! V_59 -> V_190 )
return - V_191 ;
else
return V_59 -> V_190 ( V_2 -> V_10 ) ;
}
static bool F_63 ( struct V_1 * V_2 )
{
struct V_110 * V_111 = V_2 -> V_9 -> V_111 ;
struct V_7 * V_8 = V_2 -> V_9 -> V_8 ;
long time ;
if ( V_2 -> V_78 ) {
switch ( V_111 -> V_120 ) {
case V_151 :
case V_192 :
case V_179 :
V_111 -> error = - V_86 ;
V_2 -> V_78 = false ;
break;
default:
V_111 -> error = F_32 ( V_2 ) ;
F_6 ( & V_2 -> V_10 -> V_11 , L_22 ,
V_111 -> V_120 , V_111 -> error ) ;
break;
}
return false ;
}
if ( ! ( V_111 -> V_12 & V_193 ) ) {
V_111 -> error = 0 ;
return false ;
}
F_47 ( V_2 , V_111 ) ;
if ( ! V_8 )
return false ;
if ( V_8 -> V_12 & V_13 ) {
if ( V_2 -> V_14 )
F_11 ( V_2 ) ;
} else {
if ( V_2 -> V_19 )
F_18 ( V_2 ) ;
}
if ( ! V_2 -> V_30 ) {
V_8 -> error = F_51 ( V_2 , V_2 -> V_9 , V_111 -> V_120 ) ;
if ( ! V_8 -> error )
return true ;
return false ;
}
time = F_64 ( & V_2 -> V_21 ,
V_2 -> V_77 ) ;
if ( V_2 -> V_78 ) {
F_34 ( V_2 -> V_172 -> V_194 ,
L_23 ) ;
if ( V_8 -> V_12 & V_13 )
F_65 ( V_2 -> V_14 ) ;
else
F_65 ( V_2 -> V_19 ) ;
V_8 -> error = F_32 ( V_2 ) ;
} else if ( ! time ) {
V_8 -> error = - V_86 ;
} else if ( time < 0 ) {
V_8 -> error = time ;
}
F_4 ( V_2 , V_36 ,
V_37 | V_40 ) ;
V_2 -> V_30 = false ;
if ( V_8 -> error )
V_8 -> V_195 = 0 ;
return false ;
}
static T_4 F_66 ( int V_196 , void * V_197 )
{
struct V_1 * V_2 = V_197 ;
struct V_92 * V_9 = V_2 -> V_9 ;
struct V_7 * V_8 = V_9 -> V_8 ;
F_67 ( & V_2 -> V_97 ) ;
switch ( V_2 -> V_95 ) {
case V_198 :
return V_199 ;
case V_166 :
if ( F_63 ( V_2 ) )
return V_199 ;
break;
case V_104 :
if ( F_42 ( V_2 ) )
return V_199 ;
break;
case V_96 :
if ( F_40 ( V_2 ) )
return V_199 ;
break;
case V_109 :
if ( F_46 ( V_2 ) )
return V_199 ;
break;
case V_105 :
if ( F_44 ( V_2 ) )
return V_199 ;
break;
case V_170 :
if ( V_2 -> V_78 ) {
V_9 -> V_169 -> error = F_32 ( V_2 ) ;
break;
}
F_48 ( V_2 , V_9 -> V_169 ) ;
V_9 -> V_169 -> error = 0 ;
break;
case V_103 :
case V_108 :
if ( V_2 -> V_78 )
V_8 -> error = F_32 ( V_2 ) ;
break;
default:
F_68 () ;
}
if ( V_2 -> V_95 != V_170 ) {
if ( ! V_9 -> V_111 -> error && V_8 && ! V_8 -> error )
V_8 -> V_195 =
V_8 -> V_149 * V_8 -> V_162 ;
if ( V_9 -> V_169 && ! V_9 -> V_111 -> error && ( ! V_8 || ! V_8 -> error ) ) {
F_53 ( V_2 , V_9 ) ;
if ( ! V_9 -> V_169 -> error )
return V_199 ;
}
}
V_2 -> V_95 = V_198 ;
V_2 -> V_174 = V_175 ;
V_2 -> V_9 = NULL ;
F_58 ( V_2 -> V_172 , V_9 ) ;
return V_199 ;
}
static T_4 F_69 ( int V_196 , void * V_197 )
{
struct V_1 * V_2 = V_197 ;
T_1 V_174 ;
int V_200 = 0 ;
V_174 = F_30 ( V_2 -> V_5 , V_163 ) ;
if ( V_174 & V_201 ) {
F_31 ( V_2 -> V_5 , V_163 , ~ V_174 ) ;
F_4 ( V_2 , V_98 , V_174 ) ;
V_200 = 1 ;
} else if ( V_174 & V_202 ) {
F_31 ( V_2 -> V_5 , V_163 ,
~ ( V_202 | V_203 ) ) ;
F_4 ( V_2 , V_98 , V_160 ) ;
} else if ( V_174 & V_203 ) {
F_31 ( V_2 -> V_5 , V_163 , ~ V_203 ) ;
F_4 ( V_2 , V_98 , V_161 ) ;
} else if ( V_174 & V_204 ) {
F_31 ( V_2 -> V_5 , V_163 , ~ V_204 ) ;
F_4 ( V_2 , V_98 , V_99 ) ;
} else if ( V_174 & V_205 ) {
F_31 ( V_2 -> V_5 , V_163 , ~ V_205 ) ;
F_4 ( V_2 , V_98 , V_106 ) ;
} else if ( V_174 & V_206 ) {
F_31 ( V_2 -> V_5 , V_163 ,
~ ( V_206 | V_207 |
V_208 | V_209 ) ) ;
F_4 ( V_2 , V_98 , V_167 ) ;
} else if ( V_174 & V_209 ) {
F_31 ( V_2 -> V_5 , V_163 , ~ V_209 ) ;
F_4 ( V_2 , V_98 , V_102 ) ;
} else if ( V_174 & V_210 ) {
F_31 ( V_2 -> V_5 , V_163 , ~ V_210 ) ;
F_4 ( V_2 , V_98 , V_107 ) ;
} else if ( V_174 & V_207 ) {
F_31 ( V_2 -> V_5 , V_163 ,
~ ( V_207 | V_208 ) ) ;
F_4 ( V_2 , V_98 , V_168 ) ;
} else {
F_6 ( & V_2 -> V_10 -> V_11 , L_24 , V_174 ) ;
F_31 ( V_2 -> V_5 , V_163 , ~ V_174 ) ;
F_4 ( V_2 , V_98 , V_174 ) ;
V_200 = 1 ;
}
if ( V_200 ) {
V_2 -> V_78 = true ;
F_6 ( & V_2 -> V_10 -> V_11 , L_25 , V_174 ) ;
}
if ( V_174 & ~ ( V_207 | V_208 ) ) {
if ( ! V_2 -> V_30 )
return V_211 ;
else if ( V_2 -> V_78 )
F_5 ( V_2 ) ;
} else {
F_6 ( & V_2 -> V_10 -> V_11 , L_26 , V_174 ) ;
}
return V_199 ;
}
static void F_70 ( struct V_212 * V_213 )
{
struct V_214 * V_215 = F_71 ( V_213 , struct V_214 , V_213 ) ;
struct V_1 * V_2 = F_71 ( V_215 , struct V_1 , V_97 ) ;
struct V_92 * V_9 = V_2 -> V_9 ;
if ( V_2 -> V_216 )
return;
switch ( V_2 -> V_95 ) {
case V_166 :
V_9 -> V_111 -> error = F_32 ( V_2 ) ;
break;
case V_170 :
V_9 -> V_169 -> error = F_32 ( V_2 ) ;
break;
case V_104 :
case V_109 :
case V_96 :
case V_105 :
case V_103 :
case V_108 :
V_9 -> V_8 -> error = F_32 ( V_2 ) ;
break;
default:
F_68 () ;
}
V_2 -> V_174 = V_175 ;
V_2 -> V_95 = V_198 ;
V_2 -> V_9 = NULL ;
F_58 ( V_2 -> V_172 , V_9 ) ;
}
static int T_5 F_72 ( struct V_217 * V_218 )
{
int V_29 = 0 , V_196 [ 2 ] ;
struct V_171 * V_172 ;
struct V_1 * V_2 ;
struct V_43 * V_10 ;
struct V_219 * V_220 ;
void T_6 * V_3 ;
char V_221 [ 8 ] ;
V_196 [ 0 ] = F_73 ( V_218 , 0 ) ;
V_196 [ 1 ] = F_73 ( V_218 , 1 ) ;
if ( V_196 [ 0 ] < 0 || V_196 [ 1 ] < 0 ) {
F_34 ( & V_218 -> V_11 , L_27 ) ;
return - V_222 ;
}
V_220 = F_74 ( V_218 , V_223 , 0 ) ;
if ( ! V_220 ) {
F_34 ( & V_218 -> V_11 , L_28 ) ;
return - V_222 ;
}
V_3 = F_75 ( V_220 -> V_224 , F_76 ( V_220 ) ) ;
if ( ! V_3 ) {
F_34 ( & V_218 -> V_11 , L_29 ) ;
return - V_225 ;
}
V_10 = V_218 -> V_11 . V_60 ;
if ( ! V_10 ) {
F_34 ( & V_218 -> V_11 , L_30 ) ;
V_29 = - V_222 ;
goto V_226;
}
V_172 = F_77 ( sizeof( struct V_1 ) , & V_218 -> V_11 ) ;
if ( ! V_172 ) {
V_29 = - V_225 ;
goto V_226;
}
V_2 = F_55 ( V_172 ) ;
V_2 -> V_172 = V_172 ;
V_2 -> V_5 = V_3 ;
V_2 -> V_77 = 1000 ;
snprintf ( V_221 , sizeof( V_221 ) , L_31 , V_218 -> V_227 ) ;
V_2 -> V_228 = F_78 ( & V_218 -> V_11 , V_221 ) ;
if ( F_79 ( V_2 -> V_228 ) ) {
F_34 ( & V_218 -> V_11 , L_32 , V_221 ) ;
V_29 = F_80 ( V_2 -> V_228 ) ;
goto V_229;
}
F_81 ( V_2 -> V_228 ) ;
V_2 -> V_58 = F_82 ( V_2 -> V_228 ) ;
V_2 -> V_10 = V_218 ;
F_83 ( & V_2 -> V_173 ) ;
V_172 -> V_230 = & V_231 ;
V_172 -> V_232 = V_2 -> V_58 / 2 ;
V_172 -> V_233 = V_2 -> V_58 / 512 ;
if ( V_10 -> V_234 )
V_172 -> V_235 = V_10 -> V_234 ;
V_172 -> V_236 = V_237 ;
if ( V_10 -> V_236 )
V_172 -> V_236 |= V_10 -> V_236 ;
V_172 -> V_238 = 32 ;
V_172 -> V_239 = 512 ;
V_172 -> V_240 = V_241 * V_172 -> V_238 ;
V_172 -> V_242 = V_172 -> V_240 / V_172 -> V_239 ;
V_172 -> V_243 = V_172 -> V_240 ;
F_29 ( V_2 ) ;
F_84 ( V_218 , V_2 ) ;
F_85 ( & V_218 -> V_11 ) ;
V_2 -> V_187 = false ;
V_29 = F_86 ( & V_218 -> V_11 ) ;
if ( V_29 < 0 )
goto V_244;
F_87 ( & V_2 -> V_97 , F_70 ) ;
F_31 ( V_2 -> V_5 , V_98 , V_245 ) ;
V_29 = F_88 ( V_196 [ 0 ] , F_69 , F_66 , 0 , L_33 , V_2 ) ;
if ( V_29 ) {
F_34 ( & V_218 -> V_11 , L_34 ) ;
goto V_246;
}
V_29 = F_88 ( V_196 [ 1 ] , F_69 , F_66 , 0 , L_35 , V_2 ) ;
if ( V_29 ) {
F_34 ( & V_218 -> V_11 , L_36 ) ;
goto V_247;
}
V_29 = F_89 ( V_172 ) ;
if ( V_29 < 0 )
goto V_248;
F_90 ( & V_218 -> V_11 , 100 ) ;
F_91 ( & V_218 -> V_11 , L_37 , V_249 ) ;
F_6 ( & V_218 -> V_11 , L_38 ,
F_30 ( V_2 -> V_5 , V_67 ) & 0x0000ffff ) ;
return V_29 ;
V_248:
F_92 ( V_196 [ 1 ] , V_2 ) ;
V_247:
F_92 ( V_196 [ 0 ] , V_2 ) ;
V_246:
F_93 ( & V_218 -> V_11 ) ;
V_244:
F_94 ( & V_218 -> V_11 ) ;
F_95 ( V_2 -> V_228 ) ;
V_229:
F_96 ( V_172 ) ;
V_226:
if ( V_3 )
F_97 ( V_3 ) ;
return V_29 ;
}
static int T_7 F_98 ( struct V_217 * V_218 )
{
struct V_1 * V_2 = F_99 ( V_218 ) ;
int V_196 [ 2 ] ;
V_2 -> V_216 = true ;
F_61 ( & V_218 -> V_11 ) ;
F_100 ( & V_218 -> V_11 ) ;
F_101 ( V_2 -> V_172 ) ;
F_31 ( V_2 -> V_5 , V_98 , V_245 ) ;
F_67 ( & V_2 -> V_97 ) ;
if ( V_2 -> V_5 )
F_97 ( V_2 -> V_5 ) ;
V_196 [ 0 ] = F_73 ( V_218 , 0 ) ;
V_196 [ 1 ] = F_73 ( V_218 , 1 ) ;
F_92 ( V_196 [ 0 ] , V_2 ) ;
F_92 ( V_196 [ 1 ] , V_2 ) ;
F_84 ( V_218 , NULL ) ;
F_95 ( V_2 -> V_228 ) ;
F_96 ( V_2 -> V_172 ) ;
F_102 ( & V_218 -> V_11 ) ;
F_94 ( & V_218 -> V_11 ) ;
return 0 ;
}
static int F_103 ( struct V_15 * V_11 )
{
struct V_217 * V_218 = F_104 ( V_11 ) ;
struct V_1 * V_2 = F_99 ( V_218 ) ;
int V_29 = F_105 ( V_2 -> V_172 ) ;
if ( ! V_29 ) {
F_31 ( V_2 -> V_5 , V_98 , V_245 ) ;
F_95 ( V_2 -> V_228 ) ;
}
return V_29 ;
}
static int F_106 ( struct V_15 * V_11 )
{
struct V_217 * V_218 = F_104 ( V_11 ) ;
struct V_1 * V_2 = F_99 ( V_218 ) ;
F_81 ( V_2 -> V_228 ) ;
return F_107 ( V_2 -> V_172 ) ;
}
