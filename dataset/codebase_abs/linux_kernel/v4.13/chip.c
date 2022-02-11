static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 ;
V_5 = V_2 -> V_6 -> V_7 ( V_2 -> V_8 , F_2 ( V_4 -> V_9 , V_10 ) ) ;
V_4 -> V_11 = F_3 ( V_5 ) ;
}
static bool F_4 ( struct V_12 * V_4 )
{
struct V_1 * V_2 ;
T_1 V_5 ;
T_1 V_13 ;
V_2 = V_4 -> V_14 ;
V_13 = F_2 ( V_4 -> V_15 . V_9 , V_16 ) ;
V_5 = V_2 -> V_6 -> V_7 ( V_2 -> V_8 , V_13 ) ;
V_5 &= ( V_17 | V_18 |
V_19 | V_20 ) ;
return V_20 == V_5 ;
}
static bool F_5 ( struct V_12 * V_4 )
{
struct V_1 * V_2 ;
T_1 V_5 ;
bool V_21 ;
V_2 = V_4 -> V_14 ;
V_5 = V_2 -> V_6 -> V_7 ( V_2 -> V_8 , V_4 -> V_22 + V_23 ) ;
V_21 = ( V_5 & ( V_24 | V_25 ) ) == V_25 ;
V_5 = V_2 -> V_6 -> V_7 ( V_2 -> V_8 , V_4 -> V_22 + V_26 ) ;
V_21 = V_21 && ( ( V_5 & V_27 ) == 0 ) ;
return V_21 ;
}
static void F_6 ( struct V_12 * V_4 ,
T_1 V_28 , T_1 V_29 )
{
struct V_1 * V_2 ;
T_1 V_30 , V_9 ;
V_2 = V_4 -> V_14 ;
V_9 = V_4 -> V_15 . V_9 ;
V_30 = V_2 -> V_6 -> V_7 ( V_2 -> V_8 , F_2 ( V_9 , V_16 ) ) ;
if ( V_30 & V_17 )
return;
V_30 = V_2 -> V_6 -> V_7 ( V_2 -> V_8 , F_2 ( V_9 , V_16 ) ) ;
if ( ( V_30 & V_20 ) != 0 ) {
V_30 = V_2 -> V_6 -> V_7 ( V_2 -> V_8 , F_2 ( V_9 , V_16 ) ) ;
V_2 -> V_6 -> V_31 ( V_2 -> V_8 , F_2 ( V_9 , V_16 ) ,
V_30 | V_18 ) ;
V_30 = V_2 -> V_6 -> V_7 ( V_2 -> V_8 , F_2 ( V_9 , V_16 ) ) ;
F_7 ( 1 ) ;
F_8 ( ( V_2 -> V_6 -> V_7 ( V_2 -> V_8 , F_2 ( V_9 , V_32 ) )
& V_33 ) , 100000 ) ;
V_30 = V_2 -> V_6 -> V_7 ( V_2 -> V_8 , F_2 ( V_9 , V_32 ) ) ;
if ( V_30 & V_33 )
F_9 ( L_1 ) ;
V_30 = V_2 -> V_6 -> V_7 ( V_2 -> V_8 , F_2 ( V_9 , V_34 ) ) ;
if ( V_30 & V_35 ) {
V_30 = V_2 -> V_6 -> V_7 ( V_2 -> V_8 ,
F_2 ( V_9 , V_36 ) ) ;
V_30 |= V_19 ;
V_2 -> V_6 -> V_31 ( V_2 -> V_8 ,
F_2 ( V_9 , V_36 ) , V_30 ) ;
V_30 = V_2 -> V_6 -> V_7 ( V_2 -> V_8 ,
F_2 ( V_9 , V_36 ) ) ;
F_7 ( 1 ) ;
F_8 ( ( V_2 -> V_6 -> V_7 ( V_2 -> V_8 ,
F_2 ( V_9 , V_36 ) ) &
V_37 ) , 100000 ) ;
}
V_30 = V_38 | V_20 |
V_18 | V_17 ;
V_2 -> V_6 -> V_31 ( V_2 -> V_8 , F_2 ( V_9 , V_16 ) , V_30 ) ;
V_30 = V_2 -> V_6 -> V_7 ( V_2 -> V_8 , F_2 ( V_9 , V_16 ) ) ;
F_7 ( 10 ) ;
V_30 = V_2 -> V_6 -> V_7 ( V_2 -> V_8 , F_2 ( V_9 , V_34 ) ) ;
if ( V_30 & V_35 ) {
V_30 = V_2 -> V_6 -> V_7 ( V_2 -> V_8 ,
F_2 ( V_9 , V_36 ) ) ;
V_30 &= ~ V_19 ;
V_2 -> V_6 -> V_31 ( V_2 -> V_8 ,
F_2 ( V_9 , V_36 ) , V_30 ) ;
}
}
V_2 -> V_6 -> V_31 ( V_2 -> V_8 , F_2 ( V_9 , V_16 ) ,
( V_18 | V_17 ) ) ;
F_7 ( 1 ) ;
}
static void F_10 ( struct V_12 * V_4 ,
T_1 V_28 , T_1 V_29 )
{
struct V_1 * V_2 ;
T_1 V_5 ;
V_2 = V_4 -> V_14 ;
V_5 = V_2 -> V_6 -> V_7 ( V_2 -> V_8 , V_4 -> V_22 + V_26 ) ;
if ( ( V_5 & V_27 ) != 0 )
goto V_39;
V_2 -> V_6 -> V_31 ( V_2 -> V_8 , V_4 -> V_22 + V_23 ,
V_28 | V_24 | V_25 ) ;
V_2 -> V_6 -> V_7 ( V_2 -> V_8 , V_4 -> V_22 + V_23 ) ;
V_2 -> V_6 -> V_31 ( V_2 -> V_8 , V_4 -> V_22 + V_26 ,
V_27 ) ;
F_11 ( 10 , 20 ) ;
F_8 ( V_2 -> V_6 -> V_7 ( V_2 -> V_8 , V_4 -> V_22 + V_26 ) !=
V_27 , 300 ) ;
V_39:
V_2 -> V_6 -> V_31 ( V_2 -> V_8 , V_4 -> V_22 + V_23 ,
V_29 | V_24 | V_25 ) ;
V_2 -> V_6 -> V_7 ( V_2 -> V_8 , V_4 -> V_22 + V_23 ) ;
}
static void F_12 ( struct V_12 * V_4 , T_1 V_28 ,
T_1 V_29 , T_1 V_40 )
{
struct V_1 * V_2 ;
T_1 V_5 ;
T_1 V_9 ;
V_2 = V_4 -> V_14 ;
V_9 = V_4 -> V_15 . V_9 ;
F_6 ( V_4 , 0 , 0 ) ;
V_2 -> V_6 -> V_31 ( V_2 -> V_8 , F_2 ( V_9 , V_16 ) ,
V_38 | V_20 |
V_17 ) ;
V_5 = V_2 -> V_6 -> V_7 ( V_2 -> V_8 , F_2 ( V_9 , V_16 ) ) ;
F_7 ( 1 ) ;
V_5 = V_2 -> V_6 -> V_7 ( V_2 -> V_8 , F_2 ( V_9 , V_32 ) ) ;
if ( V_5 & V_41 )
V_2 -> V_6 -> V_31 ( V_2 -> V_8 , F_2 ( V_9 , V_32 ) , 0 ) ;
V_5 = V_2 -> V_6 -> V_7 ( V_2 -> V_8 , F_2 ( V_9 , V_36 ) ) ;
if ( V_5 & ( V_42 | V_43 ) ) {
V_5 &= ~ ( V_42 | V_43 ) ;
V_2 -> V_6 -> V_31 ( V_2 -> V_8 , F_2 ( V_9 , V_36 ) , V_5 ) ;
}
V_2 -> V_6 -> V_31 ( V_2 -> V_8 , F_2 ( V_9 , V_16 ) ,
V_38 | V_20 ) ;
V_5 = V_2 -> V_6 -> V_7 ( V_2 -> V_8 , F_2 ( V_9 , V_16 ) ) ;
F_7 ( 1 ) ;
V_2 -> V_6 -> V_31 ( V_2 -> V_8 , F_2 ( V_9 , V_16 ) ,
V_20 ) ;
V_5 = V_2 -> V_6 -> V_7 ( V_2 -> V_8 , F_2 ( V_9 , V_16 ) ) ;
F_7 ( 1 ) ;
}
static void F_13 ( struct V_12 * V_4 , T_1 V_28 ,
T_1 V_29 , T_1 V_40 )
{
struct V_1 * V_2 ;
int V_44 ;
V_2 = V_4 -> V_14 ;
F_10 ( V_4 , V_28 , V_29 ) ;
V_44 = 0 ;
while ( V_2 -> V_6 -> V_7 ( V_2 -> V_8 , V_4 -> V_22 + V_26 ) &
V_27 ) {
V_2 -> V_6 -> V_31 ( V_2 -> V_8 , V_4 -> V_22 + V_26 , 0 ) ;
V_44 ++ ;
if ( V_44 > 50 )
break;
F_11 ( 40 , 60 ) ;
}
V_2 -> V_6 -> V_31 ( V_2 -> V_8 , V_4 -> V_22 + V_23 ,
V_40 | V_25 ) ;
V_2 -> V_6 -> V_7 ( V_2 -> V_8 , V_4 -> V_22 + V_23 ) ;
}
static char * F_14 ( T_2 V_45 , char * V_46 , T_2 V_47 )
{
const char * V_48 ;
V_48 = ( ( V_45 > 0xa000 ) || ( V_45 < 0x4000 ) ) ? L_2 : L_3 ;
snprintf ( V_46 , V_47 , V_48 , V_45 ) ;
return V_46 ;
}
static struct V_3 * F_15 ( struct V_1 * V_2 ,
T_3 V_49 , T_1 V_9 ,
T_1 V_22 )
{
struct V_12 * V_4 ;
V_4 = F_16 ( sizeof( * V_4 ) , V_50 ) ;
if ( ! V_4 )
return F_17 ( - V_51 ) ;
V_4 -> V_15 . V_52 = V_49 ;
V_4 -> V_15 . V_9 = V_9 ;
V_4 -> V_14 = V_2 ;
V_4 -> V_22 = V_22 ;
F_18 ( & V_4 -> V_53 , & V_2 -> V_54 ) ;
return & V_4 -> V_15 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_12 * V_4 ;
bool V_55 = false ;
bool V_56 = false ;
bool V_57 = false ;
int V_58 = 1 ;
F_20 (core, &ci->cores, list) {
F_21 ( V_59 , L_4 ,
V_58 ++ , V_4 -> V_15 . V_52 , V_4 -> V_15 . V_11 , V_4 -> V_15 . V_9 ,
V_4 -> V_22 ) ;
switch ( V_4 -> V_15 . V_52 ) {
case V_60 :
V_57 = true ;
V_55 = true ;
break;
case V_61 :
V_56 = true ;
break;
case V_62 :
V_57 = true ;
break;
case V_63 :
V_57 = true ;
break;
default:
break;
}
}
if ( ! V_57 ) {
F_9 ( L_5 ) ;
return - V_64 ;
}
if ( V_55 && ! V_56 ) {
F_9 ( L_6 ) ;
return - V_65 ;
}
return 0 ;
}
static T_1 F_22 ( struct V_12 * V_4 , T_3 V_66 )
{
return V_4 -> V_14 -> V_6 -> V_7 ( V_4 -> V_14 -> V_8 , V_4 -> V_15 . V_9 + V_66 ) ;
}
static void F_23 ( struct V_12 * V_4 ,
T_3 V_66 , T_1 V_30 )
{
V_4 -> V_14 -> V_6 -> V_31 ( V_4 -> V_14 -> V_8 , V_4 -> V_15 . V_9 + V_66 , V_30 ) ;
}
static bool F_24 ( struct V_12 * V_4 , T_4 V_58 ,
T_1 * V_67 )
{
T_1 V_68 ;
T_1 V_69 = ( V_70 << V_71 ) ;
V_69 |= V_58 ;
F_23 ( V_4 , F_25 ( V_69 ) , V_69 ) ;
V_68 = F_22 ( V_4 , F_25 ( V_68 ) ) ;
* V_67 = ( V_68 & V_72 ) + 1 ;
* V_67 *= V_73 ;
return ! ! ( V_68 & V_74 ) ;
}
static void F_26 ( struct V_12 * V_75 , T_1 * V_76 ,
T_1 * V_77 )
{
T_1 V_78 ;
T_2 V_79 , V_67 , V_80 ;
bool V_81 ;
int V_82 ;
* V_76 = 0 ;
* V_77 = 0 ;
if ( F_27 ( V_75 -> V_15 . V_11 < 4 ) )
return;
if ( ! F_28 ( & V_75 -> V_15 ) )
F_29 ( & V_75 -> V_15 , 0 , 0 , 0 ) ;
V_78 = F_22 ( V_75 , F_25 ( V_78 ) ) ;
V_79 = ( V_78 & V_83 ) >> V_84 ;
if ( ( V_75 -> V_15 . V_11 <= 7 ) || ( V_75 -> V_15 . V_11 == 12 ) ) {
V_67 = ( V_78 & V_85 ) ;
V_80 = ( V_78 & V_86 ) >> V_87 ;
if ( V_80 != 0 )
V_79 -- ;
* V_76 = V_79 * ( 1 << ( V_67 + V_88 ) ) ;
if ( V_80 != 0 )
* V_76 += ( 1 << ( ( V_80 - 1 ) + V_88 ) ) ;
} else {
V_79 = ( V_78 & V_83 ) >> V_84 ;
for ( V_82 = 0 ; V_82 < V_79 ; V_82 ++ ) {
V_81 = F_24 ( V_75 , V_82 , & V_67 ) ;
* V_76 += V_67 ;
if ( V_81 )
* V_77 += V_67 ;
}
}
switch ( V_75 -> V_14 -> V_15 . V_14 ) {
case V_89 :
if ( V_75 -> V_14 -> V_15 . V_90 < 2 )
* V_77 = ( 32 * 1024 ) ;
break;
case V_91 :
* V_77 = ( 64 * 1024 ) ;
break;
default:
break;
}
}
static T_1 F_30 ( struct V_12 * V_92 )
{
T_1 V_93 = 0 ;
T_1 V_78 ;
T_1 V_58 ;
T_1 V_79 ;
T_1 V_67 ;
if ( ! F_28 ( & V_92 -> V_15 ) )
F_29 ( & V_92 -> V_15 , 0 , 0 , 0 ) ;
V_78 = F_22 ( V_92 , F_31 ( V_78 ) ) ;
V_79 = ( V_78 & V_83 ) >> V_84 ;
for ( V_58 = 0 ; V_58 < V_79 ; V_58 ++ ) {
F_24 ( V_92 , V_58 , & V_67 ) ;
V_93 += V_67 ;
}
return V_93 ;
}
static T_1 F_32 ( struct V_12 * V_94 )
{
T_1 V_95 ;
T_1 V_93 = 0 ;
T_1 V_96 ;
T_1 V_97 ;
T_1 V_98 ;
T_1 V_99 ;
T_1 V_58 ;
V_95 = F_22 ( V_94 , V_100 ) ;
V_96 = ( V_95 & V_101 ) >> V_102 ;
V_97 = ( V_95 & V_103 ) >> V_104 ;
V_98 = V_96 + V_97 ;
for ( V_58 = 0 ; V_58 < V_98 ; V_58 ++ ) {
F_23 ( V_94 , V_105 , V_58 ) ;
V_99 = F_22 ( V_94 , V_106 ) ;
V_93 += ( ( V_99 & V_107 ) + 1 ) * V_108 ;
}
return V_93 ;
}
static T_1 F_33 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_15 . V_14 ) {
case V_109 :
return 0x198000 ;
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
return 0x180000 ;
case V_122 :
case V_123 :
case V_124 :
case V_125 :
return 0x200000 ;
default:
F_9 ( L_7 , V_2 -> V_15 . V_126 ) ;
break;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_12 * V_127 ;
struct V_3 * V_128 ;
V_128 = F_35 ( & V_2 -> V_15 , V_62 ) ;
if ( V_128 ) {
V_127 = F_36 ( V_128 , struct V_12 , V_15 ) ;
V_2 -> V_15 . V_76 = F_32 ( V_127 ) ;
V_2 -> V_15 . V_129 = F_33 ( V_2 ) ;
if ( ! V_2 -> V_15 . V_129 ) {
F_9 ( L_8 ) ;
return - V_130 ;
}
} else {
V_128 = F_35 ( & V_2 -> V_15 , V_131 ) ;
if ( V_128 ) {
V_127 = F_36 ( V_128 , struct V_12 ,
V_15 ) ;
V_2 -> V_15 . V_76 = F_30 ( V_127 ) ;
V_2 -> V_15 . V_129 = F_33 ( V_2 ) ;
if ( ! V_2 -> V_15 . V_129 ) {
F_9 ( L_9 ) ;
return - V_130 ;
}
} else {
V_128 = F_35 ( & V_2 -> V_15 ,
V_61 ) ;
if ( ! V_128 ) {
F_9 ( L_10 ) ;
return - V_51 ;
}
V_127 = F_36 ( V_128 , struct V_12 ,
V_15 ) ;
F_26 ( V_127 , & V_2 -> V_15 . V_76 ,
& V_2 -> V_15 . V_77 ) ;
}
}
F_21 ( V_59 , L_11 ,
V_2 -> V_15 . V_129 , V_2 -> V_15 . V_76 , V_2 -> V_15 . V_76 ,
V_2 -> V_15 . V_77 , V_2 -> V_15 . V_77 ) ;
if ( ! V_2 -> V_15 . V_76 ) {
F_9 ( L_12 ) ;
return - V_51 ;
}
if ( V_2 -> V_15 . V_76 > V_132 ) {
F_9 ( L_13 ) ;
return - V_51 ;
}
return 0 ;
}
static T_1 F_37 ( struct V_1 * V_2 , T_1 * V_133 ,
T_4 * type )
{
T_1 V_30 ;
V_30 = V_2 -> V_6 -> V_7 ( V_2 -> V_8 , * V_133 ) ;
* V_133 += 4 ;
if ( ! type )
return V_30 ;
* type = ( V_30 & V_134 ) ;
if ( ( * type & ~ V_135 ) == V_136 )
* type = V_136 ;
return V_30 ;
}
static int F_38 ( struct V_1 * V_2 , T_1 * V_133 ,
T_1 * V_137 , T_1 * V_22 )
{
T_4 V_138 ;
T_1 V_30 ;
T_4 V_139 = 0 ;
T_4 V_140 , V_141 , V_142 ;
* V_137 = 0 ;
* V_22 = 0 ;
V_30 = F_37 ( V_2 , V_133 , & V_138 ) ;
if ( V_138 == V_143 ) {
V_139 = ( V_30 & V_144 ) >> V_145 ;
V_142 = V_146 ;
} else if ( V_138 == V_136 ) {
* V_133 -= 4 ;
V_142 = V_147 ;
} else {
* V_133 -= 4 ;
return - V_148 ;
}
do {
do {
V_30 = F_37 ( V_2 , V_133 , & V_138 ) ;
if ( V_138 == V_149 ) {
* V_133 -= 4 ;
return - V_150 ;
}
} while ( V_138 != V_136 &&
V_138 != V_151 );
if ( V_138 == V_151 ) {
* V_133 -= 4 ;
return 0 ;
}
if ( V_30 & V_135 )
F_37 ( V_2 , V_133 , NULL ) ;
V_141 = ( V_30 & V_152 ) >> V_153 ;
if ( V_141 == V_154 ) {
V_30 = F_37 ( V_2 , V_133 , NULL ) ;
if ( V_30 & V_135 )
F_37 ( V_2 , V_133 , NULL ) ;
}
if ( V_141 != V_155 )
continue;
V_140 = ( V_30 & V_156 ) >> V_157 ;
if ( * V_137 == 0 && V_140 == V_158 )
* V_137 = V_30 & V_159 ;
if ( * V_22 == 0 && V_140 == V_142 )
* V_22 = V_30 & V_159 ;
} while ( * V_137 == 0 || * V_22 == 0 );
return 0 ;
}
static
int F_39 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 V_133 ;
T_4 V_160 = 0 ;
T_1 V_30 ;
T_3 V_52 ;
T_4 V_161 , V_162 , V_163 , V_164 , V_11 ;
T_1 V_9 , V_165 ;
int V_166 ;
V_133 = V_2 -> V_6 -> V_7 ( V_2 -> V_8 , F_40 ( V_167 , V_168 ) ) ;
while ( V_160 != V_149 ) {
V_30 = F_37 ( V_2 , & V_133 , & V_160 ) ;
if ( ! ( V_30 & V_169 ) )
continue;
if ( V_160 == V_170 )
continue;
if ( V_160 != V_151 )
continue;
V_52 = ( V_30 & V_171 ) >> V_172 ;
V_30 = F_37 ( V_2 , & V_133 , & V_160 ) ;
if ( F_27 ( ( V_30 & V_134 ) != V_151 ) )
return - V_150 ;
V_161 = ( V_30 & V_173 ) >> V_174 ;
V_162 = ( V_30 & V_175 ) >> V_176 ;
V_163 = ( V_30 & V_177 ) >> V_178 ;
V_164 = ( V_30 & V_179 ) >> V_180 ;
V_11 = ( V_30 & V_181 ) >> V_182 ;
if ( V_163 + V_164 == 0 &&
V_52 != V_183 )
continue;
V_166 = F_38 ( V_2 , & V_133 , & V_9 , & V_165 ) ;
if ( V_166 )
continue;
V_4 = F_15 ( V_2 , V_52 , V_9 , V_165 ) ;
if ( F_41 ( V_4 ) )
return F_42 ( V_4 ) ;
V_4 -> V_11 = V_11 ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 V_5 ;
T_1 V_184 ;
int V_21 ;
V_5 = V_2 -> V_6 -> V_7 ( V_2 -> V_8 , F_40 ( V_167 , V_45 ) ) ;
V_2 -> V_15 . V_14 = V_5 & V_185 ;
V_2 -> V_15 . V_90 = ( V_5 & V_186 ) >> V_187 ;
V_184 = ( V_5 & V_188 ) >> V_189 ;
F_14 ( V_2 -> V_15 . V_14 , V_2 -> V_15 . V_126 , sizeof( V_2 -> V_15 . V_126 ) ) ;
F_21 ( V_59 , L_14 ,
V_184 == V_190 ? L_15 : L_16 , V_2 -> V_15 . V_126 ,
V_2 -> V_15 . V_90 ) ;
if ( V_184 == V_190 ) {
if ( V_2 -> V_15 . V_14 != V_191 ) {
F_9 ( L_17 ) ;
return - V_65 ;
}
V_2 -> V_192 = F_4 ;
V_2 -> V_193 = F_6 ;
V_2 -> V_194 = F_12 ;
V_4 = F_15 ( V_2 , V_195 ,
V_167 , 0 ) ;
F_1 ( V_2 , V_4 ) ;
V_4 = F_15 ( V_2 , V_196 ,
V_197 , 0 ) ;
F_1 ( V_2 , V_4 ) ;
V_4 = F_15 ( V_2 , V_61 ,
V_198 , 0 ) ;
F_1 ( V_2 , V_4 ) ;
V_4 = F_15 ( V_2 , V_60 ,
V_199 , 0 ) ;
F_1 ( V_2 , V_4 ) ;
V_4 = F_15 ( V_2 , V_200 , 0x18001000 , 0 ) ;
F_1 ( V_2 , V_4 ) ;
} else if ( V_184 == V_201 ) {
V_2 -> V_192 = F_5 ;
V_2 -> V_193 = F_10 ;
V_2 -> V_194 = F_13 ;
F_39 ( V_2 ) ;
} else {
F_9 ( L_18 ,
V_184 ) ;
return - V_65 ;
}
V_21 = F_19 ( V_2 ) ;
if ( V_21 )
return V_21 ;
F_44 ( & V_2 -> V_15 ) ;
if ( V_2 -> V_6 -> V_29 ) {
V_2 -> V_6 -> V_29 ( V_2 -> V_8 , & V_2 -> V_15 ) ;
F_44 ( & V_2 -> V_15 ) ;
}
return F_34 ( V_2 ) ;
}
static void F_45 ( struct V_1 * V_14 , T_3 V_52 )
{
struct V_3 * V_4 ;
struct V_12 * V_202 ;
T_1 V_30 ;
V_4 = F_35 ( & V_14 -> V_15 , V_52 ) ;
if ( ! V_4 )
return;
switch ( V_52 ) {
case V_60 :
F_46 ( V_4 , 0 , 0 ) ;
break;
case V_62 :
case V_63 :
V_202 = F_36 ( V_4 , struct V_12 , V_15 ) ;
V_30 = V_14 -> V_6 -> V_7 ( V_14 -> V_8 , V_202 -> V_22 + V_23 ) ;
V_30 &= V_203 ;
F_29 ( V_4 , V_30 , V_203 ,
V_203 ) ;
break;
default:
F_9 ( L_19 , V_52 ) ;
break;
}
}
static int F_47 ( struct V_1 * V_14 )
{
struct V_204 * V_15 ;
struct V_12 * V_205 ;
struct V_3 * V_206 ;
T_1 V_9 ;
T_1 V_30 ;
int V_21 = 0 ;
V_15 = & V_14 -> V_15 ;
V_205 = F_48 ( & V_14 -> V_54 , struct V_12 , V_53 ) ;
V_9 = V_205 -> V_15 . V_9 ;
V_15 -> V_207 = V_14 -> V_6 -> V_7 ( V_14 -> V_8 ,
F_40 ( V_9 , V_208 ) ) ;
V_15 -> V_209 = V_14 -> V_6 -> V_7 ( V_14 -> V_8 ,
F_40 ( V_9 ,
V_210 ) ) ;
V_206 = F_49 ( V_15 ) ;
if ( V_15 -> V_207 & V_211 ) {
V_30 = V_14 -> V_6 -> V_7 ( V_14 -> V_8 ,
F_40 ( V_206 -> V_9 , V_212 ) ) ;
V_15 -> V_213 = V_30 & V_214 ;
V_15 -> V_215 = V_30 ;
}
F_21 ( V_59 , L_20 ,
V_205 -> V_15 . V_11 , V_15 -> V_213 , V_15 -> V_215 ) ;
if ( V_14 -> V_6 -> V_216 )
V_21 = V_14 -> V_6 -> V_216 ( V_14 -> V_8 , V_15 ) ;
return V_21 ;
}
struct V_204 * F_50 ( void * V_8 ,
const struct V_217 * V_6 )
{
struct V_1 * V_14 ;
int V_166 = 0 ;
if ( F_27 ( ! V_6 -> V_7 ) )
V_166 = - V_130 ;
if ( F_27 ( ! V_6 -> V_31 ) )
V_166 = - V_130 ;
if ( F_27 ( ! V_6 -> V_218 ) )
V_166 = - V_130 ;
if ( F_27 ( ! V_6 -> V_219 ) )
V_166 = - V_130 ;
if ( V_166 < 0 )
return F_17 ( - V_130 ) ;
V_14 = F_16 ( sizeof( * V_14 ) , V_50 ) ;
if ( ! V_14 )
return F_17 ( - V_51 ) ;
F_51 ( & V_14 -> V_54 ) ;
V_14 -> V_220 = 0 ;
V_14 -> V_6 = V_6 ;
V_14 -> V_8 = V_8 ;
V_166 = V_6 -> V_218 ( V_8 ) ;
if ( V_166 < 0 )
goto V_221;
V_166 = F_43 ( V_14 ) ;
if ( V_166 < 0 )
goto V_221;
V_166 = F_47 ( V_14 ) ;
if ( V_166 < 0 )
goto V_221;
return & V_14 -> V_15 ;
V_221:
F_52 ( & V_14 -> V_15 ) ;
return F_17 ( V_166 ) ;
}
void F_52 ( struct V_204 * V_15 )
{
struct V_1 * V_14 ;
struct V_12 * V_4 ;
struct V_12 * V_222 ;
V_14 = F_36 ( V_15 , struct V_1 , V_15 ) ;
F_53 (core, tmp, &chip->cores, list) {
F_54 ( & V_4 -> V_53 ) ;
F_55 ( V_4 ) ;
}
F_55 ( V_14 ) ;
}
struct V_3 * F_35 ( struct V_204 * V_15 , T_3 V_49 )
{
struct V_1 * V_14 ;
struct V_12 * V_4 ;
V_14 = F_36 ( V_15 , struct V_1 , V_15 ) ;
F_20 (core, &chip->cores, list)
if ( V_4 -> V_15 . V_52 == V_49 )
return & V_4 -> V_15 ;
return NULL ;
}
struct V_3 * F_56 ( struct V_204 * V_15 )
{
struct V_1 * V_14 ;
struct V_12 * V_205 ;
V_14 = F_36 ( V_15 , struct V_1 , V_15 ) ;
V_205 = F_48 ( & V_14 -> V_54 , struct V_12 , V_53 ) ;
if ( F_27 ( ! V_205 || V_205 -> V_15 . V_52 != V_195 ) )
return F_35 ( V_15 , V_195 ) ;
return & V_205 -> V_15 ;
}
struct V_3 * F_49 ( struct V_204 * V_15 )
{
struct V_3 * V_205 = F_56 ( V_15 ) ;
struct V_3 * V_206 ;
if ( V_205 -> V_11 >= 35 &&
V_15 -> V_209 & V_223 ) {
V_206 = F_35 ( V_15 , V_183 ) ;
if ( V_206 )
return V_206 ;
}
return V_205 ;
}
bool F_28 ( struct V_3 * V_15 )
{
struct V_12 * V_4 ;
V_4 = F_36 ( V_15 , struct V_12 , V_15 ) ;
return V_4 -> V_14 -> V_192 ( V_4 ) ;
}
void F_46 ( struct V_3 * V_15 , T_1 V_28 , T_1 V_29 )
{
struct V_12 * V_4 ;
V_4 = F_36 ( V_15 , struct V_12 , V_15 ) ;
V_4 -> V_14 -> V_193 ( V_4 , V_28 , V_29 ) ;
}
void F_29 ( struct V_3 * V_15 , T_1 V_28 , T_1 V_29 ,
T_1 V_40 )
{
struct V_12 * V_4 ;
V_4 = F_36 ( V_15 , struct V_12 , V_15 ) ;
V_4 -> V_14 -> V_194 ( V_4 , V_28 , V_29 , V_40 ) ;
}
static void
F_57 ( struct V_1 * V_14 )
{
struct V_3 * V_4 ;
struct V_12 * V_75 ;
F_45 ( V_14 , V_60 ) ;
V_4 = F_35 ( & V_14 -> V_15 , V_200 ) ;
F_29 ( V_4 , V_224 |
V_225 ,
V_225 ,
V_225 ) ;
V_4 = F_35 ( & V_14 -> V_15 , V_61 ) ;
F_29 ( V_4 , 0 , 0 , 0 ) ;
if ( V_14 -> V_15 . V_14 == V_91 ) {
V_75 = F_36 ( V_4 , struct V_12 , V_15 ) ;
F_23 ( V_75 , F_25 ( V_69 ) , 3 ) ;
F_23 ( V_75 , F_25 ( V_226 ) , 0 ) ;
}
}
static bool F_58 ( struct V_1 * V_14 )
{
struct V_3 * V_4 ;
V_4 = F_35 ( & V_14 -> V_15 , V_61 ) ;
if ( ! F_28 ( V_4 ) ) {
F_9 ( L_21 ) ;
return false ;
}
V_14 -> V_6 -> V_219 ( V_14 -> V_8 , & V_14 -> V_15 , 0 ) ;
V_4 = F_35 ( & V_14 -> V_15 , V_60 ) ;
F_29 ( V_4 , 0 , 0 , 0 ) ;
return true ;
}
static inline void
F_59 ( struct V_1 * V_14 )
{
struct V_3 * V_4 ;
F_45 ( V_14 , V_62 ) ;
V_4 = F_35 ( & V_14 -> V_15 , V_200 ) ;
F_29 ( V_4 , V_224 |
V_225 ,
V_225 ,
V_225 ) ;
}
static bool F_60 ( struct V_1 * V_14 , T_1 V_227 )
{
struct V_3 * V_4 ;
V_14 -> V_6 -> V_219 ( V_14 -> V_8 , & V_14 -> V_15 , V_227 ) ;
V_4 = F_35 ( & V_14 -> V_15 , V_62 ) ;
F_29 ( V_4 , V_203 , 0 , 0 ) ;
return true ;
}
static inline void
F_61 ( struct V_1 * V_14 )
{
struct V_3 * V_4 ;
F_45 ( V_14 , V_63 ) ;
V_4 = F_35 ( & V_14 -> V_15 , V_200 ) ;
F_29 ( V_4 , V_224 |
V_225 ,
V_225 ,
V_225 ) ;
}
static bool F_62 ( struct V_1 * V_14 , T_1 V_227 )
{
struct V_3 * V_4 ;
V_14 -> V_6 -> V_219 ( V_14 -> V_8 , & V_14 -> V_15 , V_227 ) ;
V_4 = F_35 ( & V_14 -> V_15 , V_63 ) ;
F_29 ( V_4 , V_203 , 0 , 0 ) ;
return true ;
}
void F_44 ( struct V_204 * V_15 )
{
struct V_1 * V_14 ;
struct V_3 * V_228 ;
F_21 ( V_229 , L_22 ) ;
V_14 = F_36 ( V_15 , struct V_1 , V_15 ) ;
V_228 = F_35 ( V_15 , V_62 ) ;
if ( V_228 ) {
F_59 ( V_14 ) ;
return;
}
V_228 = F_35 ( V_15 , V_63 ) ;
if ( V_228 ) {
F_61 ( V_14 ) ;
return;
}
V_228 = F_35 ( V_15 , V_60 ) ;
if ( V_228 ) {
F_57 ( V_14 ) ;
return;
}
}
bool F_63 ( struct V_204 * V_15 , T_1 V_227 )
{
struct V_1 * V_14 ;
struct V_3 * V_228 ;
F_21 ( V_229 , L_22 ) ;
V_14 = F_36 ( V_15 , struct V_1 , V_15 ) ;
V_228 = F_35 ( V_15 , V_62 ) ;
if ( V_228 )
return F_60 ( V_14 , V_227 ) ;
V_228 = F_35 ( V_15 , V_63 ) ;
if ( V_228 )
return F_62 ( V_14 , V_227 ) ;
V_228 = F_35 ( V_15 , V_60 ) ;
if ( V_228 )
return F_58 ( V_14 ) ;
return false ;
}
bool F_64 ( struct V_204 * V_15 )
{
T_1 V_9 , V_230 , V_66 , V_231 = ~ 0 ;
struct V_1 * V_14 ;
struct V_3 * V_206 = F_49 ( V_15 ) ;
F_21 ( V_229 , L_22 ) ;
if ( V_15 -> V_213 < 17 )
return false ;
V_9 = F_56 ( V_15 ) -> V_9 ;
V_14 = F_36 ( V_15 , struct V_1 , V_15 ) ;
switch ( V_15 -> V_14 ) {
case V_113 :
case V_114 :
V_231 = F_65 ( 2 ) ;
case V_232 :
case V_110 :
case V_111 :
V_230 = F_40 ( V_206 -> V_9 , V_233 ) ;
V_14 -> V_6 -> V_31 ( V_14 -> V_8 , V_230 , 3 ) ;
V_230 = F_40 ( V_206 -> V_9 , V_234 ) ;
V_66 = V_14 -> V_6 -> V_7 ( V_14 -> V_8 , V_230 ) ;
return ( V_66 & V_231 ) != 0 ;
case V_91 :
V_230 = F_40 ( V_9 , V_235 ) ;
V_66 = V_14 -> V_6 -> V_7 ( V_14 -> V_8 , V_230 ) ;
return V_66 != 0 ;
default:
V_230 = F_40 ( V_206 -> V_9 , V_236 ) ;
V_66 = V_14 -> V_6 -> V_7 ( V_14 -> V_8 , V_230 ) ;
if ( ( V_66 & V_237 ) == 0 )
return false ;
V_230 = F_40 ( V_206 -> V_9 , V_238 ) ;
V_66 = V_14 -> V_6 -> V_7 ( V_14 -> V_8 , V_230 ) ;
return ( V_66 & ( V_239 |
V_240 ) ) == 0 ;
}
}
