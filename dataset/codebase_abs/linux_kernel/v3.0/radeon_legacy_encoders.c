static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 ;
V_5 = V_2 -> V_6 ;
V_5 -> V_7 ( V_2 , V_8 ) ;
V_3 -> V_9 = 0 ;
}
static void F_3 ( struct V_1 * V_2 , int V_10 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_16 , V_17 , V_18 , V_19 ;
int V_20 = 2000 ;
bool V_21 = false ;
T_2 V_22 ;
F_4 ( L_1 ) ;
V_16 = F_5 ( V_23 ) ;
V_22 = ( V_16 >> V_24 ) & 0xff ;
if ( V_3 -> V_25 ) {
if ( V_14 -> V_26 ) {
struct V_27 * V_28 = V_3 -> V_25 ;
V_20 = V_28 -> V_20 ;
if ( V_28 -> V_29 )
V_22 = V_28 -> V_22 ;
} else {
struct V_30 * V_28 = V_3 -> V_25 ;
V_20 = V_28 -> V_20 ;
if ( V_28 -> V_29 )
V_22 = V_28 -> V_22 ;
}
}
if ( ( V_14 -> V_31 . V_32 == V_33 ) ||
( V_14 -> V_31 . V_32 == V_34 ) ||
( V_14 -> V_31 . V_32 == V_35 ) ||
( V_14 -> V_31 . V_32 == V_36 ) )
V_21 = true ;
switch ( V_10 ) {
case V_37 :
V_19 = F_5 ( V_38 ) ;
V_19 |= V_39 ;
F_6 ( V_38 , V_19 ) ;
V_17 = F_5 ( V_40 ) ;
V_17 |= V_41 ;
F_6 ( V_40 , V_17 ) ;
F_7 ( 1000 ) ;
V_17 = F_5 ( V_40 ) ;
V_17 &= ~ V_42 ;
F_6 ( V_40 , V_17 ) ;
V_16 &= ~ ( V_43 |
V_44 ) ;
V_16 |= ( V_45 | V_46 |
V_47 | V_48 |
( V_22 << V_24 ) ) ;
if ( V_21 )
V_16 |= V_49 ;
F_7 ( V_20 * 1000 ) ;
F_6 ( V_23 , V_16 ) ;
break;
case V_50 :
case V_51 :
case V_8 :
V_18 = F_8 ( V_52 ) ;
F_9 ( V_52 , 0 , ~ V_53 ) ;
V_16 |= V_43 ;
if ( V_21 ) {
V_16 &= ~ V_49 ;
F_6 ( V_23 , V_16 ) ;
V_16 &= ~ ( V_45 | V_46 ) ;
} else {
F_6 ( V_23 , V_16 ) ;
V_16 &= ~ ( V_45 | V_48 | V_46 | V_47 ) ;
}
F_7 ( V_20 * 1000 ) ;
F_6 ( V_23 , V_16 ) ;
F_10 ( V_52 , V_18 ) ;
F_7 ( V_20 * 1000 ) ;
break;
}
if ( V_14 -> V_26 )
F_11 ( V_2 , ( V_10 == V_37 ) ? true : false ) ;
else
F_12 ( V_2 , ( V_10 == V_37 ) ? true : false ) ;
}
static void F_13 ( struct V_1 * V_2 , int V_10 )
{
struct V_13 * V_14 = V_2 -> V_12 -> V_15 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_14 ( L_1 ) ;
if ( V_3 -> V_25 ) {
if ( V_14 -> V_26 ) {
struct V_27 * V_28 = V_3 -> V_25 ;
V_28 -> V_54 = V_10 ;
} else {
struct V_30 * V_28 = V_3 -> V_25 ;
V_28 -> V_54 = V_10 ;
}
}
F_3 ( V_2 , V_10 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_12 -> V_15 ;
if ( V_14 -> V_26 )
F_16 ( V_2 , true ) ;
else
F_17 ( V_2 , true ) ;
F_13 ( V_2 , V_8 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_12 -> V_15 ;
F_13 ( V_2 , V_37 ) ;
if ( V_14 -> V_26 )
F_16 ( V_2 , false ) ;
else
F_17 ( V_2 , false ) ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_55 * V_10 ,
struct V_55 * V_56 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_57 * V_57 = F_20 ( V_2 -> V_58 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_17 , V_16 , V_59 ;
F_4 ( L_1 ) ;
V_17 = F_5 ( V_40 ) ;
V_17 &= ~ V_41 ;
V_59 = F_5 ( V_60 ) ;
if ( V_14 -> V_26 ) {
V_3 -> V_61 = V_56 -> clock ;
F_21 ( V_2 , V_62 ) ;
V_16 = F_5 ( V_23 ) ;
} else {
struct V_30 * V_28 = (struct V_30 * ) V_3 -> V_25 ;
if ( V_28 ) {
F_4 ( L_2 , V_28 -> V_16 ) ;
V_16 = V_28 -> V_16 ;
V_59 &= ~ ( ( 0xf << V_63 ) |
( 0xf << V_64 ) ) ;
V_59 |= ( ( V_28 -> V_65 << V_63 ) |
( V_28 -> V_66 << V_64 ) ) ;
} else
V_16 = F_5 ( V_23 ) ;
}
V_16 |= V_43 ;
V_16 &= ~ ( V_45 |
V_48 |
V_46 |
V_67 ) ;
if ( F_22 ( V_14 ) )
V_17 &= ~ ( V_68 ) ;
if ( V_57 -> V_69 == 0 ) {
if ( F_22 ( V_14 ) ) {
if ( V_3 -> V_70 != V_71 )
V_17 |= V_72 ;
} else
V_16 &= ~ V_73 ;
} else {
if ( F_22 ( V_14 ) )
V_17 |= V_74 ;
else
V_16 |= V_73 ;
}
F_6 ( V_23 , V_16 ) ;
F_6 ( V_40 , V_17 ) ;
F_6 ( V_60 , V_59 ) ;
if ( V_14 -> V_75 == V_76 )
F_6 ( V_77 , 0 ) ;
if ( V_14 -> V_26 )
F_23 ( V_2 , V_57 -> V_69 ) ;
else
F_24 ( V_2 , V_57 -> V_69 ) ;
}
static bool F_25 ( struct V_1 * V_2 ,
struct V_55 * V_10 ,
struct V_55 * V_56 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
F_26 ( V_2 ) ;
F_27 ( V_56 , 0 ) ;
if ( V_3 -> V_9 & ( V_78 ) )
F_28 ( V_2 , V_56 ) ;
return true ;
}
static T_2 F_29 ( struct V_79 * V_80 )
{
struct V_81 * V_82 = F_30 ( V_80 ) ;
T_2 V_83 ;
if ( V_80 -> V_84 . V_85 < 0 )
V_83 = 0 ;
else if ( V_80 -> V_84 . V_85 > V_86 )
V_83 = V_86 ;
else
V_83 = V_80 -> V_84 . V_85 ;
if ( V_82 -> V_87 )
V_83 = V_86 - V_83 ;
return V_83 ;
}
static int F_31 ( struct V_79 * V_80 )
{
struct V_81 * V_82 = F_30 ( V_80 ) ;
struct V_3 * V_3 = V_82 -> V_2 ;
struct V_11 * V_12 = V_3 -> V_88 . V_12 ;
struct V_13 * V_14 = V_12 -> V_15 ;
int V_54 = V_37 ;
if ( V_3 -> V_25 ) {
if ( V_14 -> V_26 ) {
struct V_27 * V_28 = V_3 -> V_25 ;
V_54 = V_28 -> V_54 ;
V_28 -> V_22 = F_29 ( V_80 ) ;
} else {
struct V_30 * V_28 = V_3 -> V_25 ;
V_54 = V_28 -> V_54 ;
V_28 -> V_22 = F_29 ( V_80 ) ;
}
}
if ( V_80 -> V_84 . V_85 > 0 )
F_3 ( & V_3 -> V_88 , V_54 ) ;
else
F_3 ( & V_3 -> V_88 , V_8 ) ;
return 0 ;
}
static int F_32 ( struct V_79 * V_80 )
{
struct V_81 * V_82 = F_30 ( V_80 ) ;
struct V_3 * V_3 = V_82 -> V_2 ;
struct V_11 * V_12 = V_3 -> V_88 . V_12 ;
struct V_13 * V_14 = V_12 -> V_15 ;
T_2 V_22 ;
V_22 = ( F_5 ( V_23 ) >>
V_24 ) & 0xff ;
return V_82 -> V_87 ? V_86 - V_22 : V_22 ;
}
void F_33 ( struct V_3 * V_3 ,
struct V_89 * V_89 )
{
struct V_11 * V_12 = V_3 -> V_88 . V_12 ;
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_79 * V_80 ;
struct V_90 V_84 ;
struct V_81 * V_82 ;
T_2 V_22 ;
if ( ! V_3 -> V_25 )
return;
#ifdef F_34
if ( ! F_35 ( L_3 ) &&
! F_35 ( L_4 ) )
return;
#endif
V_82 = F_36 ( sizeof( struct V_81 ) , V_91 ) ;
if ( ! V_82 ) {
F_37 ( L_5 ) ;
goto error;
}
V_84 . V_92 = V_86 ;
V_84 . type = V_93 ;
V_80 = F_38 ( L_6 , & V_89 -> V_94 ,
V_82 , & V_95 , & V_84 ) ;
if ( F_39 ( V_80 ) ) {
F_37 ( L_7 ) ;
goto error;
}
V_82 -> V_2 = V_3 ;
V_22 = ( F_5 ( V_23 ) >>
V_24 ) & 0xff ;
if ( V_22 == 0 )
V_82 -> V_87 = true ;
else if ( V_22 == 0xff )
V_82 -> V_87 = false ;
else {
V_82 -> V_87 = ( V_14 -> V_75 != V_96 &&
V_14 -> V_75 != V_97 &&
V_14 -> V_75 != V_98 &&
V_14 -> V_75 != V_99 ) ;
#ifdef F_34
V_82 -> V_87 = ( V_82 -> V_87 ||
F_40 ( L_8 ) ||
F_40 ( L_9 ) ||
F_40 ( L_10 ) ) ;
#endif
}
if ( V_14 -> V_26 ) {
struct V_27 * V_28 = V_3 -> V_25 ;
V_28 -> V_29 = V_80 ;
} else {
struct V_30 * V_28 = V_3 -> V_25 ;
V_28 -> V_29 = V_80 ;
}
V_80 -> V_84 . V_85 = F_32 ( V_80 ) ;
V_80 -> V_84 . V_100 = V_101 ;
F_41 ( V_80 ) ;
F_42 ( L_11 ) ;
return;
error:
F_43 ( V_82 ) ;
return;
}
static void F_44 ( struct V_3 * V_3 )
{
struct V_11 * V_12 = V_3 -> V_88 . V_12 ;
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_79 * V_80 = NULL ;
if ( ! V_3 -> V_25 )
return;
if ( V_14 -> V_26 ) {
struct V_27 * V_28 = V_3 -> V_25 ;
V_80 = V_28 -> V_29 ;
V_28 -> V_29 = NULL ;
} else {
struct V_30 * V_28 = V_3 -> V_25 ;
V_80 = V_28 -> V_29 ;
V_28 -> V_29 = NULL ;
}
if ( V_80 ) {
struct V_102 * V_82 ;
V_82 = F_30 ( V_80 ) ;
F_45 ( V_80 ) ;
F_43 ( V_82 ) ;
F_42 ( L_12 ) ;
}
}
void F_33 ( struct V_3 * V_2 )
{
}
static void F_44 ( struct V_3 * V_2 )
{
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_3 -> V_25 ) {
F_44 ( V_3 ) ;
F_43 ( V_3 -> V_25 ) ;
}
F_47 ( V_2 ) ;
F_43 ( V_3 ) ;
}
static void F_48 ( struct V_1 * V_2 , int V_10 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = V_12 -> V_15 ;
T_1 V_103 = F_5 ( V_104 ) ;
T_1 V_105 = F_5 ( V_106 ) ;
T_1 V_107 = F_5 ( V_108 ) ;
F_4 ( L_1 ) ;
switch ( V_10 ) {
case V_37 :
V_103 |= V_109 ;
V_105 &= ~ V_110 ;
V_107 &= ~ ( V_111 |
V_112 |
V_113 ) ;
break;
case V_50 :
case V_51 :
case V_8 :
V_103 &= ~ V_109 ;
V_105 |= V_110 ;
V_107 |= ( V_111 |
V_112 |
V_113 ) ;
break;
}
F_6 ( V_104 , V_103 ) ;
F_6 ( V_106 , V_105 ) ;
F_6 ( V_108 , V_107 ) ;
if ( V_14 -> V_26 )
F_11 ( V_2 , ( V_10 == V_37 ) ? true : false ) ;
else
F_12 ( V_2 , ( V_10 == V_37 ) ? true : false ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_12 -> V_15 ;
if ( V_14 -> V_26 )
F_16 ( V_2 , true ) ;
else
F_17 ( V_2 , true ) ;
F_48 ( V_2 , V_8 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_12 -> V_15 ;
F_48 ( V_2 , V_37 ) ;
if ( V_14 -> V_26 )
F_16 ( V_2 , false ) ;
else
F_17 ( V_2 , false ) ;
}
static void F_51 ( struct V_1 * V_2 ,
struct V_55 * V_10 ,
struct V_55 * V_56 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_57 * V_57 = F_20 ( V_2 -> V_58 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_114 , V_105 , V_115 , V_107 ;
F_4 ( L_1 ) ;
if ( V_57 -> V_69 == 0 ) {
if ( V_14 -> V_75 == V_116 || F_22 ( V_14 ) ) {
V_114 = F_5 ( V_117 ) &
~ ( V_118 ) ;
F_6 ( V_117 , V_114 ) ;
} else {
V_115 = F_5 ( V_119 ) & ~ ( V_120 ) ;
F_6 ( V_119 , V_115 ) ;
}
} else {
if ( V_14 -> V_75 == V_116 || F_22 ( V_14 ) ) {
V_114 = F_5 ( V_117 ) &
~ ( V_118 ) ;
V_114 |= V_121 ;
F_6 ( V_117 , V_114 ) ;
} else {
V_115 = F_5 ( V_119 ) | V_120 ;
F_6 ( V_119 , V_115 ) ;
}
}
V_105 = ( V_122 |
V_123 |
V_124 ) ;
F_52 ( V_106 ,
V_105 ,
V_125 |
V_126 ) ;
if ( V_3 -> V_25 ) {
struct V_127 * V_128 = (struct V_127 * ) V_3 -> V_25 ;
V_107 = V_128 -> V_129 ;
} else
V_107 = F_5 ( V_108 ) ;
V_107 |= V_111 | V_112 | V_113 ;
F_6 ( V_108 , V_107 ) ;
if ( V_14 -> V_26 )
F_23 ( V_2 , V_57 -> V_69 ) ;
else
F_24 ( V_2 , V_57 -> V_69 ) ;
}
static enum V_130 F_53 ( struct V_1 * V_2 ,
struct V_89 * V_131 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = V_12 -> V_15 ;
T_1 V_132 , V_103 ;
T_1 V_133 , V_105 , V_107 , V_134 ;
enum V_130 V_135 = V_136 ;
bool V_137 = true ;
V_132 = F_8 ( V_138 ) ;
V_103 = F_5 ( V_104 ) ;
V_133 = F_5 ( V_139 ) ;
V_105 = F_5 ( V_106 ) ;
V_107 = F_5 ( V_108 ) ;
V_134 = V_132 &
~ ( V_140 | V_141 ) ;
F_10 ( V_138 , V_134 ) ;
V_134 = V_103 | V_109 ;
F_6 ( V_104 , V_134 ) ;
V_134 = V_142 |
V_143 ;
if ( V_137 )
V_134 |= V_144 ;
else
V_134 |= V_145 ;
if ( F_22 ( V_14 ) )
V_134 |= ( 0x1b6 << V_146 ) ;
else
V_134 |= ( 0x180 << V_146 ) ;
F_6 ( V_139 , V_134 ) ;
V_134 = V_105 & ~ ( V_147 | V_110 ) ;
V_134 |= V_148 | V_149 ;
F_6 ( V_106 , V_134 ) ;
V_134 &= ~ ( V_111 |
V_112 |
V_113 ) ;
F_6 ( V_108 , V_134 ) ;
F_7 ( 2000 ) ;
if ( F_5 ( V_106 ) & V_150 )
V_135 = V_151 ;
F_6 ( V_106 , V_105 ) ;
F_6 ( V_108 , V_107 ) ;
F_6 ( V_139 , V_133 ) ;
F_6 ( V_104 , V_103 ) ;
F_10 ( V_138 , V_132 ) ;
return V_135 ;
}
static void F_54 ( struct V_1 * V_2 , int V_10 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = V_12 -> V_15 ;
T_1 V_152 = F_5 ( V_153 ) ;
F_4 ( L_1 ) ;
switch ( V_10 ) {
case V_37 :
V_152 |= ( V_154 | V_155 ) ;
break;
case V_50 :
case V_51 :
case V_8 :
V_152 &= ~ ( V_154 | V_155 ) ;
break;
}
F_6 ( V_153 , V_152 ) ;
if ( V_14 -> V_26 )
F_11 ( V_2 , ( V_10 == V_37 ) ? true : false ) ;
else
F_12 ( V_2 , ( V_10 == V_37 ) ? true : false ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_12 -> V_15 ;
if ( V_14 -> V_26 )
F_16 ( V_2 , true ) ;
else
F_17 ( V_2 , true ) ;
F_54 ( V_2 , V_8 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_12 -> V_15 ;
F_54 ( V_2 , V_37 ) ;
if ( V_14 -> V_26 )
F_16 ( V_2 , true ) ;
else
F_17 ( V_2 , true ) ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_55 * V_10 ,
struct V_55 * V_56 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_57 * V_57 = F_20 ( V_2 -> V_58 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_134 , V_156 , V_157 , V_152 ;
int V_158 ;
F_4 ( L_1 ) ;
V_134 = V_156 = F_5 ( V_159 ) ;
V_134 &= 0xfffff ;
if ( V_14 -> V_75 == V_98 ) {
V_134 ^= ( 1 << 22 ) ;
V_156 ^= ( 1 << 22 ) ;
}
if ( V_3 -> V_25 ) {
struct V_160 * V_161 = (struct V_160 * ) V_3 -> V_25 ;
for ( V_158 = 0 ; V_158 < 4 ; V_158 ++ ) {
if ( V_161 -> V_162 [ V_158 ] . V_163 == 0 )
break;
if ( ( T_1 ) ( V_10 -> clock / 10 ) < V_161 -> V_162 [ V_158 ] . V_163 ) {
V_134 = V_161 -> V_162 [ V_158 ] . V_164 ;
break;
}
}
}
if ( F_22 ( V_14 ) || ( V_14 -> V_75 == V_98 ) ) {
if ( V_134 & 0xfff00000 )
V_156 = V_134 ;
else {
V_156 &= 0xfff00000 ;
V_156 |= V_134 ;
}
} else
V_156 = V_134 ;
V_157 = F_5 ( V_165 ) &
~ ( V_166 ) ;
if ( V_14 -> V_75 == V_116 ||
V_14 -> V_75 == V_167 ||
F_22 ( V_14 ) )
V_157 &= ~ ( V_168 ) ;
else
V_157 |= V_168 ;
V_152 = ( F_5 ( V_153 ) |
( V_169 |
V_170 ) ) ;
V_152 &= ~ ( V_154 | V_155 ) ;
V_152 &= ~ ( V_171 |
V_172 |
V_173 |
V_174 |
V_175 |
V_176 |
V_177 ) ;
if ( 1 )
V_152 |= V_178 ;
else
V_152 &= ~ V_178 ;
if ( V_57 -> V_69 == 0 ) {
if ( F_22 ( V_14 ) || V_14 -> V_75 == V_116 ) {
V_152 &= ~ V_179 ;
if ( V_3 -> V_70 != V_71 )
V_152 |= V_180 ;
else
V_152 |= V_181 ;
} else
V_152 &= ~ V_182 ;
} else {
if ( F_22 ( V_14 ) || V_14 -> V_75 == V_116 ) {
V_152 &= ~ V_179 ;
V_152 |= V_183 ;
} else
V_152 |= V_182 ;
}
F_6 ( V_159 , V_156 ) ;
F_6 ( V_165 , V_157 ) ;
F_6 ( V_153 , V_152 ) ;
if ( V_14 -> V_26 )
F_23 ( V_2 , V_57 -> V_69 ) ;
else
F_24 ( V_2 , V_57 -> V_69 ) ;
}
static void F_58 ( struct V_1 * V_2 , int V_10 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = V_12 -> V_15 ;
T_1 V_184 = F_5 ( V_185 ) ;
F_4 ( L_1 ) ;
switch ( V_10 ) {
case V_37 :
V_184 &= ~ V_186 ;
V_184 |= ( V_187 | V_188 ) ;
break;
case V_50 :
case V_51 :
case V_8 :
V_184 |= V_186 ;
V_184 &= ~ ( V_187 | V_188 ) ;
break;
}
F_6 ( V_185 , V_184 ) ;
if ( V_14 -> V_26 )
F_11 ( V_2 , ( V_10 == V_37 ) ? true : false ) ;
else
F_12 ( V_2 , ( V_10 == V_37 ) ? true : false ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_12 -> V_15 ;
if ( V_14 -> V_26 )
F_16 ( V_2 , true ) ;
else
F_17 ( V_2 , true ) ;
F_58 ( V_2 , V_8 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_12 -> V_15 ;
F_58 ( V_2 , V_37 ) ;
if ( V_14 -> V_26 )
F_16 ( V_2 , false ) ;
else
F_17 ( V_2 , false ) ;
}
static void F_61 ( struct V_1 * V_2 ,
struct V_55 * V_10 ,
struct V_55 * V_56 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_57 * V_57 = F_20 ( V_2 -> V_58 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_184 ;
F_4 ( L_1 ) ;
if ( V_14 -> V_26 ) {
V_3 -> V_61 = V_56 -> clock ;
F_62 ( V_2 , V_189 ) ;
V_184 = F_5 ( V_185 ) ;
} else {
V_184 = F_5 ( V_185 ) ;
if ( 1 )
V_184 |= V_190 ;
else
V_184 &= ~ V_190 ;
V_184 &= ~ ( V_187 |
V_188 |
V_191 ) ;
if ( F_22 ( V_14 ) ) {
if ( ( V_12 -> V_192 -> V_193 == 0x4850 ) &&
( V_12 -> V_192 -> V_194 == 0x1028 ) &&
( V_12 -> V_192 -> V_195 == 0x2001 ) )
V_184 |= V_196 ;
else
V_184 |= V_197 | V_196 ;
}
if ( ! F_63 ( V_2 ) )
F_64 ( V_2 ) ;
}
if ( V_57 -> V_69 == 0 ) {
if ( ( V_14 -> V_75 == V_116 ) || F_22 ( V_14 ) ) {
V_184 &= ~ V_198 ;
if ( V_3 -> V_70 != V_71 )
V_184 |= V_199 ;
else
V_184 |= V_200 ;
} else
V_184 &= ~ V_201 ;
} else {
if ( ( V_14 -> V_75 == V_116 ) || F_22 ( V_14 ) ) {
V_184 &= ~ V_198 ;
V_184 |= V_202 ;
} else
V_184 |= V_201 ;
}
F_6 ( V_185 , V_184 ) ;
if ( V_14 -> V_26 )
F_23 ( V_2 , V_57 -> V_69 ) ;
else
F_24 ( V_2 , V_57 -> V_69 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_203 * V_161 = V_3 -> V_25 ;
if ( V_161 ) {
if ( V_161 -> V_204 )
F_66 ( V_161 -> V_204 ) ;
}
F_43 ( V_3 -> V_25 ) ;
F_47 ( V_2 ) ;
F_43 ( V_3 ) ;
}
static void F_67 ( struct V_1 * V_2 , int V_10 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_184 = 0 , V_205 = 0 , V_206 = 0 ;
T_1 V_207 = 0 ;
bool V_208 ;
F_4 ( L_1 ) ;
V_208 = V_3 -> V_9 & V_209 ? true : false ;
if ( V_14 -> V_75 == V_116 )
V_184 = F_5 ( V_185 ) ;
else {
if ( V_208 )
V_207 = F_5 ( V_210 ) ;
else
V_205 = F_5 ( V_211 ) ;
V_206 = F_5 ( V_212 ) ;
}
switch ( V_10 ) {
case V_37 :
if ( V_14 -> V_75 == V_116 ) {
V_184 |= ( V_187 | V_188 ) ;
} else {
if ( V_208 )
V_207 |= V_213 ;
else
V_205 |= V_214 ;
if ( V_14 -> V_75 == V_215 ||
V_14 -> V_75 == V_216 ||
V_14 -> V_75 == V_76 )
V_206 &= ~ ( V_217 |
V_218 |
V_219 |
V_220 ) ;
else
V_206 &= ~ ( V_221 |
V_222 |
V_223 |
V_220 ) ;
}
break;
case V_50 :
case V_51 :
case V_8 :
if ( V_14 -> V_75 == V_116 )
V_184 &= ~ ( V_187 | V_188 ) ;
else {
if ( V_208 )
V_207 &= ~ V_213 ;
else
V_205 &= ~ V_214 ;
if ( V_14 -> V_75 == V_215 ||
V_14 -> V_75 == V_216 ||
V_14 -> V_75 == V_76 )
V_206 |= ( V_217 |
V_218 |
V_219 |
V_220 ) ;
else
V_206 |= ( V_221 |
V_222 |
V_223 |
V_220 ) ;
}
break;
}
if ( V_14 -> V_75 == V_116 ) {
F_6 ( V_185 , V_184 ) ;
} else {
if ( V_208 )
F_6 ( V_210 , V_207 ) ;
else
F_6 ( V_211 , V_205 ) ;
F_6 ( V_212 , V_206 ) ;
}
if ( V_14 -> V_26 )
F_11 ( V_2 , ( V_10 == V_37 ) ? true : false ) ;
else
F_12 ( V_2 , ( V_10 == V_37 ) ? true : false ) ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_12 -> V_15 ;
if ( V_14 -> V_26 )
F_16 ( V_2 , true ) ;
else
F_17 ( V_2 , true ) ;
F_67 ( V_2 , V_8 ) ;
}
static void F_69 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_12 -> V_15 ;
F_67 ( V_2 , V_37 ) ;
if ( V_14 -> V_26 )
F_16 ( V_2 , true ) ;
else
F_17 ( V_2 , true ) ;
}
static void F_70 ( struct V_1 * V_2 ,
struct V_55 * V_10 ,
struct V_55 * V_56 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_57 * V_57 = F_20 ( V_2 -> V_58 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_224 * V_225 = V_3 -> V_25 ;
T_1 V_206 , V_226 = 0 , V_115 , V_114 = 0 ;
T_1 V_227 = 0 , V_184 = 0 , V_228 = 0 ;
bool V_208 = false ;
F_4 ( L_1 ) ;
V_208 = V_3 -> V_9 & V_209 ? true : false ;
if ( V_14 -> V_75 != V_116 ) {
V_206 = F_5 ( V_212 ) ;
if ( V_14 -> V_75 == V_215 ||
V_14 -> V_75 == V_216 ||
V_14 -> V_75 == V_76 ) {
V_206 &= ~ ( V_229 |
V_230 |
V_231 |
V_217 |
V_218 |
V_219 |
V_232 ) ;
} else {
V_206 &= ~ ( V_229 |
V_230 |
V_233 |
V_221 |
V_222 |
V_223 ) ;
}
V_206 |= V_234 | V_235 ;
if ( V_208 ) {
if ( V_225 -> V_236 == V_237 ||
V_225 -> V_236 == V_238 ||
V_225 -> V_236 == V_239 ||
V_225 -> V_236 == V_240 )
V_206 |= V_225 -> V_241 ;
else
V_206 |= V_225 -> V_242 ;
if ( V_225 -> V_236 == V_237 ||
V_225 -> V_236 == V_238 )
V_206 |= V_243 ;
else
V_206 |= V_244 ;
} else
V_206 |= ( V_245 |
V_225 -> V_246 ) ;
F_6 ( V_212 , V_206 ) ;
}
if ( F_22 ( V_14 ) ) {
V_226 = F_5 ( V_247 ) | 1 ;
V_114 = F_5 ( V_117 ) ;
} else if ( V_14 -> V_75 != V_116 )
V_227 = F_5 ( V_248 ) ;
else if ( V_14 -> V_75 == V_116 )
V_184 = F_5 ( V_185 ) ;
if ( V_14 -> V_75 >= V_116 )
V_228 = F_5 ( V_249 ) ;
if ( V_208 ) {
T_1 V_105 ;
V_105 = F_5 ( V_106 ) ;
V_105 &= ~ V_250 ;
F_6 ( V_106 , V_105 ) ;
if ( F_22 ( V_14 ) )
V_226 = F_5 ( V_247 ) & ~ 1 ;
V_115 = F_5 ( V_119 ) & ~ V_251 ;
if ( V_57 -> V_69 == 0 ) {
if ( F_22 ( V_14 ) ) {
V_114 &= ~ V_252 ;
V_114 |= ( V_253 |
V_254 ) ;
}
if ( V_14 -> V_75 >= V_116 ) {
V_228 &= ~ V_255 ;
} else {
V_227 |= V_256 ;
}
} else {
if ( F_22 ( V_14 ) ) {
V_114 &= ~ V_252 ;
V_114 |= V_254 ;
}
if ( V_14 -> V_75 >= V_116 ) {
V_228 |= V_255 ;
} else {
V_227 &= ~ V_256 ;
}
}
F_6 ( V_119 , V_115 ) ;
} else {
V_115 = F_5 ( V_119 ) | V_251 ;
if ( V_57 -> V_69 == 0 ) {
if ( F_22 ( V_14 ) ) {
V_114 &= ~ V_252 ;
V_114 |= V_253 ;
} else if ( V_14 -> V_75 == V_116 ) {
V_184 &= ~ ( V_198 |
V_191 ) ;
} else
V_227 |= V_256 ;
} else {
if ( F_22 ( V_14 ) ) {
V_114 &= ~ V_252 ;
V_114 |= V_257 ;
} else if ( V_14 -> V_75 == V_116 ) {
V_184 &= ~ ( V_198 |
V_191 ) ;
V_184 |= V_202 ;
} else
V_227 &= ~ V_256 ;
}
F_6 ( V_119 , V_115 ) ;
}
if ( F_22 ( V_14 ) ) {
F_52 ( V_247 , V_226 , ~ 1 ) ;
F_6 ( V_117 , V_114 ) ;
} else if ( V_14 -> V_75 != V_116 )
F_6 ( V_248 , V_227 ) ;
else if ( V_14 -> V_75 == V_116 )
F_6 ( V_185 , V_184 ) ;
if ( V_14 -> V_75 >= V_116 )
F_6 ( V_249 , V_228 ) ;
if ( V_208 )
F_71 ( V_2 , V_10 , V_56 ) ;
if ( V_14 -> V_26 )
F_23 ( V_2 , V_57 -> V_69 ) ;
else
F_24 ( V_2 , V_57 -> V_69 ) ;
}
static bool F_72 ( struct V_1 * V_2 ,
struct V_89 * V_131 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = V_12 -> V_15 ;
T_1 V_205 , V_206 , V_258 , V_133 ;
T_1 V_114 , V_226 , V_134 ;
bool V_135 = false ;
V_226 = F_5 ( V_247 ) ;
V_258 = F_5 ( V_119 ) ;
V_205 = F_5 ( V_211 ) ;
V_133 = F_5 ( V_139 ) ;
V_206 = F_5 ( V_212 ) ;
V_114 = F_5 ( V_117 ) ;
F_52 ( V_247 , 0 , ~ 1 ) ;
F_6 ( V_119 , V_251 ) ;
F_6 ( V_211 ,
V_214 | V_259 ) ;
V_134 = V_114 & ~ V_252 ;
V_134 |= V_257 ;
F_6 ( V_117 , V_134 ) ;
F_6 ( V_139 ,
V_260 |
V_261 |
V_144 |
( 0xec << V_146 ) ) ;
F_6 ( V_212 ,
V_243 |
( 8 << V_262 ) |
( 6 << V_263 ) ) ;
F_5 ( V_212 ) ;
F_73 ( 4 ) ;
F_6 ( V_212 ,
V_234 |
V_235 |
V_264 |
V_243 |
( 8 << V_262 ) |
( 6 << V_263 ) ) ;
F_5 ( V_212 ) ;
F_73 ( 6 ) ;
V_134 = F_5 ( V_212 ) ;
if ( ( V_134 & V_265 ) != 0 ) {
V_135 = true ;
F_4 ( L_13 ) ;
} else if ( ( V_134 & V_266 ) != 0 ) {
V_135 = true ;
F_4 ( L_14 ) ;
}
F_6 ( V_212 , V_206 ) ;
F_6 ( V_139 , V_133 ) ;
F_6 ( V_211 , V_205 ) ;
F_6 ( V_117 , V_114 ) ;
F_6 ( V_119 , V_258 ) ;
F_52 ( V_247 , V_226 , ~ 1 ) ;
return V_135 ;
}
static bool F_74 ( struct V_1 * V_2 ,
struct V_89 * V_131 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = V_12 -> V_15 ;
T_1 V_206 , V_258 ;
T_1 V_267 , V_268 , V_207 , V_134 ;
bool V_135 = false ;
if ( F_22 ( V_14 ) )
return F_72 ( V_2 , V_131 ) ;
V_258 = F_5 ( V_119 ) ;
V_207 = F_5 ( V_210 ) ;
V_206 = F_5 ( V_212 ) ;
V_267 = F_5 ( V_269 ) ;
V_268 = F_5 ( V_270 ) ;
V_134 = V_258 & ~ V_251 ;
F_6 ( V_119 , V_134 ) ;
V_134 = V_207 | V_213 ;
V_134 &= ~ ( V_271 |
V_272 |
V_273 |
V_274 |
V_275 ) ;
V_134 |= V_276 | V_277 ;
F_6 ( V_210 , V_134 ) ;
V_134 = V_234 | V_235 |
V_264 | V_243 |
( 8 << V_262 ) ;
if ( V_267 & V_278 )
V_134 |= ( 4 << V_263 ) ;
else
V_134 |= ( 8 << V_263 ) ;
F_6 ( V_212 , V_134 ) ;
V_134 = V_279 | V_280 |
V_281 |
V_282 |
V_283 |
( 0x109 << V_284 ) ;
F_6 ( V_270 , V_134 ) ;
F_73 ( 3 ) ;
V_134 = F_5 ( V_212 ) ;
if ( V_134 & V_265 ) {
V_135 = true ;
F_4 ( L_13 ) ;
} else if ( ( V_134 & V_266 ) != 0 ) {
V_135 = true ;
F_4 ( L_14 ) ;
}
F_6 ( V_270 , V_268 ) ;
F_6 ( V_212 , V_206 ) ;
F_6 ( V_210 , V_207 ) ;
F_6 ( V_119 , V_258 ) ;
return V_135 ;
}
static enum V_130 F_75 ( struct V_1 * V_2 ,
struct V_89 * V_131 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = V_12 -> V_15 ;
T_1 V_205 , V_206 , V_258 , V_133 ;
T_1 V_227 , V_114 , V_226 , V_18 , V_134 ;
enum V_130 V_135 = V_136 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_224 * V_225 = V_3 -> V_25 ;
bool V_137 = true ;
struct V_285 * V_58 ;
F_76 (crtc, &dev->mode_config.crtc_list, head) {
struct V_57 * V_57 = F_20 ( V_58 ) ;
if ( ( V_57 -> V_69 == 1 ) && V_58 -> V_286 ) {
if ( V_2 -> V_58 != V_58 ) {
return V_136 ;
}
}
}
if ( V_131 -> V_287 == V_288 ||
V_131 -> V_287 == V_289 ||
V_131 -> V_287 == V_290 ) {
bool V_291 ;
if ( V_3 -> V_9 && ! ( V_3 -> V_9 & V_209 ) )
return V_136 ;
V_291 = F_74 ( V_2 , V_131 ) ;
if ( V_291 && V_225 )
V_135 = V_151 ;
return V_135 ;
}
if ( V_3 -> V_9 && ! ( V_3 -> V_9 & V_292 ) ) {
F_42 ( L_15 , V_3 -> V_9 ) ;
return V_136 ;
}
V_18 = F_8 ( V_52 ) ;
V_226 = F_22 ( V_14 ) ? F_5 ( V_247 ) : 0 ;
V_114 = F_22 ( V_14 ) ? F_5 ( V_117 ) : 0 ;
V_227 = F_22 ( V_14 ) ? 0 : F_5 ( V_248 ) ;
V_205 = F_5 ( V_211 ) ;
V_206 = F_5 ( V_212 ) ;
V_133 = F_5 ( V_139 ) ;
V_258 = F_5 ( V_119 ) ;
V_134 = V_18 & ~ ( V_293
| V_294 ) ;
F_10 ( V_52 , V_134 ) ;
if ( F_22 ( V_14 ) )
F_52 ( V_247 , 1 , ~ 1 ) ;
V_134 = V_205 & ~ V_295 ;
V_134 |= V_214 |
( 2 << V_296 ) ;
F_6 ( V_211 , V_134 ) ;
if ( F_22 ( V_14 ) ) {
V_134 = V_114 & ~ V_252 ;
V_134 |= V_257 ;
F_6 ( V_117 , V_134 ) ;
} else {
V_134 = V_227 & ~ V_256 ;
F_6 ( V_248 , V_134 ) ;
}
V_134 = V_234 |
V_235 |
V_264 |
V_245 ;
F_6 ( V_212 , V_134 ) ;
V_134 = V_260 |
V_261 ;
if ( V_137 )
V_134 |= V_144 ;
else
V_134 |= V_145 ;
if ( F_22 ( V_14 ) )
V_134 |= ( 0x1b6 << V_146 ) ;
else
V_134 |= ( 0x180 << V_146 ) ;
F_6 ( V_139 , V_134 ) ;
V_134 = V_258 | V_251 | V_297 ;
F_6 ( V_119 , V_134 ) ;
F_7 ( 10000 ) ;
if ( F_22 ( V_14 ) ) {
if ( F_5 ( V_119 ) & V_298 )
V_135 = V_151 ;
} else {
if ( F_5 ( V_119 ) & V_299 )
V_135 = V_151 ;
}
F_6 ( V_119 , V_258 ) ;
F_6 ( V_139 , V_133 ) ;
F_6 ( V_212 , V_206 ) ;
F_6 ( V_211 , V_205 ) ;
if ( F_22 ( V_14 ) ) {
F_6 ( V_117 , V_114 ) ;
F_52 ( V_247 , V_226 , ~ 1 ) ;
} else {
F_6 ( V_248 , V_227 ) ;
}
F_10 ( V_52 , V_18 ) ;
return V_135 ;
}
static struct V_160 * F_77 ( struct V_3 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_88 . V_12 ;
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_160 * V_161 = NULL ;
bool V_300 ;
V_161 = F_78 ( sizeof( struct V_160 ) , V_91 ) ;
if ( ! V_161 )
return NULL ;
if ( V_14 -> V_26 )
V_300 = F_79 ( V_2 , V_161 ) ;
else
V_300 = F_80 ( V_2 , V_161 ) ;
if ( V_300 == false )
F_81 ( V_2 , V_161 ) ;
return V_161 ;
}
static struct V_203 * F_82 ( struct V_3 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_88 . V_12 ;
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_203 * V_161 = NULL ;
bool V_300 ;
if ( V_14 -> V_26 )
return NULL ;
V_161 = F_78 ( sizeof( struct V_203 ) , V_91 ) ;
if ( ! V_161 )
return NULL ;
V_300 = F_83 ( V_2 , V_161 ) ;
if ( V_300 == false )
F_84 ( V_2 , V_161 ) ;
return V_161 ;
}
void
F_85 ( struct V_11 * V_12 , T_1 V_301 , T_1 V_302 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_1 * V_2 ;
struct V_3 * V_3 ;
F_76 (encoder, &dev->mode_config.encoder_list, head) {
V_3 = F_2 ( V_2 ) ;
if ( V_3 -> V_301 == V_301 ) {
V_3 -> V_303 |= V_302 ;
return;
}
}
V_3 = F_78 ( sizeof( struct V_3 ) , V_91 ) ;
if ( ! V_3 )
return;
V_2 = & V_3 -> V_88 ;
if ( V_14 -> V_304 & V_305 )
V_2 -> V_306 = 0x1 ;
else
V_2 -> V_306 = 0x3 ;
V_3 -> V_25 = NULL ;
V_3 -> V_301 = V_301 ;
V_3 -> V_307 = ( V_301 & V_308 ) >> V_309 ;
V_3 -> V_303 = V_302 ;
V_3 -> V_70 = V_71 ;
switch ( V_3 -> V_307 ) {
case V_310 :
V_2 -> V_306 = 0x1 ;
F_86 ( V_12 , V_2 , & V_311 , V_312 ) ;
F_87 ( V_2 , & V_313 ) ;
if ( V_14 -> V_26 )
V_3 -> V_25 = F_88 ( V_3 ) ;
else
V_3 -> V_25 = F_89 ( V_3 ) ;
V_3 -> V_70 = V_314 ;
break;
case V_315 :
F_86 ( V_12 , V_2 , & V_316 , V_317 ) ;
F_87 ( V_2 , & V_318 ) ;
V_3 -> V_25 = F_77 ( V_3 ) ;
break;
case V_319 :
F_86 ( V_12 , V_2 , & V_320 , V_321 ) ;
F_87 ( V_2 , & V_322 ) ;
if ( V_14 -> V_26 )
V_3 -> V_25 = F_90 ( V_3 ) ;
else
V_3 -> V_25 = F_91 ( V_3 ) ;
break;
case V_323 :
F_86 ( V_12 , V_2 , & V_324 , V_325 ) ;
F_87 ( V_2 , & V_326 ) ;
if ( V_14 -> V_26 )
V_3 -> V_25 = F_92 ( V_3 ) ;
else
V_3 -> V_25 = F_93 ( V_3 ) ;
break;
case V_327 :
F_86 ( V_12 , V_2 , & V_328 , V_317 ) ;
F_87 ( V_2 , & V_329 ) ;
if ( ! V_14 -> V_26 )
V_3 -> V_25 = F_82 ( V_3 ) ;
break;
}
}
