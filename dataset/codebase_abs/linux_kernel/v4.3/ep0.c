static const char * F_1 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_3 :
return L_1 ;
case V_4 :
return L_2 ;
case V_5 :
return L_3 ;
case V_6 :
return L_4 ;
default:
return L_5 ;
}
}
static int F_2 ( struct V_7 * V_8 , T_1 V_9 , T_2 V_10 ,
T_3 V_11 , T_3 type , bool V_12 )
{
struct V_13 V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
int V_19 ;
V_18 = V_8 -> V_20 [ V_9 ] ;
if ( V_18 -> V_21 & V_22 ) {
F_3 ( V_23 , L_6 , V_18 -> V_24 ) ;
return 0 ;
}
V_16 = & V_8 -> V_25 [ V_18 -> V_26 ] ;
if ( V_12 )
V_18 -> V_26 ++ ;
V_16 -> V_27 = F_4 ( V_10 ) ;
V_16 -> V_28 = F_5 ( V_10 ) ;
V_16 -> V_29 = V_11 ;
V_16 -> V_30 = type ;
V_16 -> V_30 |= ( V_31
| V_32 ) ;
if ( V_12 )
V_16 -> V_30 |= V_33 ;
else
V_16 -> V_30 |= ( V_34
| V_35 ) ;
if ( V_12 )
return 0 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_14 . V_36 = F_5 ( V_8 -> V_37 ) ;
V_14 . V_38 = F_4 ( V_8 -> V_37 ) ;
F_6 ( V_18 , V_16 ) ;
V_19 = F_7 ( V_8 , V_18 -> V_39 ,
V_40 , & V_14 ) ;
if ( V_19 < 0 ) {
F_3 ( V_23 , L_7 ,
V_18 -> V_24 ) ;
return V_19 ;
}
V_18 -> V_21 |= V_22 ;
V_18 -> V_41 = F_8 ( V_8 ,
V_18 -> V_39 ) ;
V_8 -> V_42 = V_43 ;
return 0 ;
}
static int F_9 ( struct V_17 * V_18 ,
struct V_44 * V_45 )
{
struct V_7 * V_8 = V_18 -> V_8 ;
V_45 -> V_46 . V_47 = 0 ;
V_45 -> V_46 . V_48 = - V_49 ;
V_45 -> V_9 = V_18 -> V_39 ;
F_10 ( & V_45 -> V_50 , & V_18 -> V_51 ) ;
if ( V_18 -> V_21 & V_52 ) {
unsigned V_53 ;
V_53 = ! ! ( V_18 -> V_21 & V_54 ) ;
if ( V_8 -> V_55 != V_5 ) {
F_11 ( V_8 -> V_56 , L_8 ) ;
return 0 ;
}
F_12 ( V_8 , V_8 -> V_20 [ V_53 ] , V_45 ) ;
V_18 -> V_21 &= ~ ( V_52 |
V_54 ) ;
return 0 ;
}
if ( V_8 -> V_57 ) {
unsigned V_53 ;
V_53 = ! V_8 -> V_58 ;
V_8 -> V_57 = false ;
F_13 ( & V_8 -> V_59 , V_60 ) ;
if ( V_8 -> V_55 == V_6 )
F_14 ( V_8 , V_8 -> V_20 [ V_53 ] ) ;
else
F_3 ( V_23 ,
L_9 ) ;
return 0 ;
}
if ( V_8 -> V_61 ) {
unsigned V_53 ;
V_53 = V_8 -> V_58 ;
V_8 -> V_55 = V_5 ;
F_12 ( V_8 , V_8 -> V_20 [ V_53 ] , V_45 ) ;
V_18 -> V_21 &= ~ V_54 ;
}
return 0 ;
}
int F_15 ( struct V_62 * V_63 , struct V_64 * V_46 ,
T_4 V_65 )
{
struct V_44 * V_45 = F_16 ( V_46 ) ;
struct V_17 * V_18 = F_17 ( V_63 ) ;
struct V_7 * V_8 = V_18 -> V_8 ;
unsigned long V_21 ;
int V_19 ;
F_18 ( & V_8 -> V_66 , V_21 ) ;
if ( ! V_18 -> V_67 . V_68 ) {
F_3 ( V_23 ,
L_10 ,
V_46 , V_18 -> V_24 ) ;
V_19 = - V_69 ;
goto V_70;
}
if ( ! F_19 ( & V_18 -> V_51 ) ) {
V_19 = - V_71 ;
goto V_70;
}
F_3 ( V_23 ,
L_11 ,
V_46 , V_18 -> V_24 , V_46 -> V_72 ,
F_1 ( V_8 -> V_55 ) ) ;
V_19 = F_9 ( V_18 , V_45 ) ;
V_70:
F_20 ( & V_8 -> V_66 , V_21 ) ;
return V_19 ;
}
static void F_21 ( struct V_7 * V_8 )
{
struct V_17 * V_18 ;
V_18 = V_8 -> V_20 [ 1 ] ;
V_18 -> V_21 = V_73 ;
V_18 = V_8 -> V_20 [ 0 ] ;
F_22 ( V_18 , 1 , false ) ;
V_18 -> V_21 = V_73 ;
V_8 -> V_57 = false ;
if ( ! F_19 ( & V_18 -> V_51 ) ) {
struct V_44 * V_45 ;
V_45 = F_23 ( & V_18 -> V_51 ) ;
F_24 ( V_18 , V_45 , - V_74 ) ;
}
V_8 -> V_55 = V_4 ;
F_25 ( V_8 ) ;
}
int F_26 ( struct V_62 * V_63 , int V_75 )
{
struct V_17 * V_18 = F_17 ( V_63 ) ;
struct V_7 * V_8 = V_18 -> V_8 ;
F_21 ( V_8 ) ;
return 0 ;
}
int F_27 ( struct V_62 * V_63 , int V_75 )
{
struct V_17 * V_18 = F_17 ( V_63 ) ;
struct V_7 * V_8 = V_18 -> V_8 ;
unsigned long V_21 ;
int V_19 ;
F_18 ( & V_8 -> V_66 , V_21 ) ;
V_19 = F_26 ( V_63 , V_75 ) ;
F_20 ( & V_8 -> V_66 , V_21 ) ;
return V_19 ;
}
void F_25 ( struct V_7 * V_8 )
{
int V_19 ;
V_19 = F_2 ( V_8 , 0 , V_8 -> V_76 , 8 ,
V_77 , false ) ;
F_28 ( V_19 < 0 ) ;
}
static struct V_17 * F_29 ( struct V_7 * V_8 , T_5 V_78 )
{
struct V_17 * V_18 ;
T_3 V_79 = F_30 ( V_78 ) ;
T_3 V_9 ;
V_9 = ( V_79 & V_80 ) << 1 ;
if ( ( V_79 & V_81 ) == V_82 )
V_9 |= 1 ;
V_18 = V_8 -> V_20 [ V_9 ] ;
if ( V_18 -> V_21 & V_73 )
return V_18 ;
return NULL ;
}
static void F_31 ( struct V_62 * V_63 , struct V_64 * V_45 )
{
}
static int F_32 ( struct V_7 * V_8 ,
struct V_83 * V_30 )
{
struct V_17 * V_18 ;
T_3 V_84 ;
T_3 V_85 ;
T_6 V_86 = 0 ;
T_5 * V_87 ;
V_84 = V_30 -> V_88 & V_89 ;
switch ( V_84 ) {
case V_90 :
V_86 |= V_8 -> V_59 . V_91 ;
if ( V_8 -> V_92 == V_93 ) {
V_85 = F_33 ( V_8 -> V_94 , V_95 ) ;
if ( V_85 & V_96 )
V_86 |= 1 << V_97 ;
if ( V_85 & V_98 )
V_86 |= 1 << V_99 ;
}
break;
case V_100 :
break;
case V_101 :
V_18 = F_29 ( V_8 , V_30 -> V_102 ) ;
if ( ! V_18 )
return - V_103 ;
if ( V_18 -> V_21 & V_104 )
V_86 = 1 << V_105 ;
break;
default:
return - V_103 ;
}
V_87 = ( T_5 * ) V_8 -> V_106 ;
* V_87 = F_34 ( V_86 ) ;
V_18 = V_8 -> V_20 [ 0 ] ;
V_8 -> V_107 . V_18 = V_18 ;
V_8 -> V_107 . V_46 . V_72 = sizeof( * V_87 ) ;
V_8 -> V_107 . V_46 . V_108 = V_8 -> V_106 ;
V_8 -> V_107 . V_46 . V_109 = F_31 ;
return F_9 ( V_18 , & V_8 -> V_107 ) ;
}
static int F_35 ( struct V_7 * V_8 ,
struct V_83 * V_30 , int V_110 )
{
struct V_17 * V_18 ;
T_3 V_84 ;
T_3 V_111 ;
T_3 V_102 ;
T_3 V_85 ;
int V_19 ;
enum V_112 V_2 ;
V_111 = F_30 ( V_30 -> V_111 ) ;
V_102 = F_30 ( V_30 -> V_102 ) ;
V_84 = V_30 -> V_88 & V_89 ;
V_2 = V_8 -> V_59 . V_2 ;
switch ( V_84 ) {
case V_90 :
switch ( V_111 ) {
case V_113 :
break;
case V_114 :
if ( V_2 != V_60 )
return - V_103 ;
if ( V_8 -> V_92 != V_93 )
return - V_103 ;
V_85 = F_33 ( V_8 -> V_94 , V_95 ) ;
if ( V_110 )
V_85 |= V_96 ;
else
V_85 &= ~ V_96 ;
F_36 ( V_8 -> V_94 , V_95 , V_85 ) ;
break;
case V_115 :
if ( V_2 != V_60 )
return - V_103 ;
if ( V_8 -> V_92 != V_93 )
return - V_103 ;
V_85 = F_33 ( V_8 -> V_94 , V_95 ) ;
if ( V_110 )
V_85 |= V_98 ;
else
V_85 &= ~ V_98 ;
F_36 ( V_8 -> V_94 , V_95 , V_85 ) ;
break;
case V_116 :
return - V_103 ;
case V_117 :
if ( ( V_102 & 0xff ) != 0 )
return - V_103 ;
if ( ! V_110 )
return - V_103 ;
V_8 -> V_118 = V_102 >> 8 ;
V_8 -> V_119 = true ;
break;
default:
return - V_103 ;
}
break;
case V_100 :
switch ( V_111 ) {
case V_120 :
if ( V_102 & V_121 )
;
if ( V_102 & V_122 )
;
break;
default:
return - V_103 ;
}
break;
case V_101 :
switch ( V_111 ) {
case V_105 :
V_18 = F_29 ( V_8 , V_102 ) ;
if ( ! V_18 )
return - V_103 ;
if ( V_110 == 0 && ( V_18 -> V_21 & V_123 ) )
break;
V_19 = F_22 ( V_18 , V_110 , true ) ;
if ( V_19 )
return - V_103 ;
break;
default:
return - V_103 ;
}
break;
default:
return - V_103 ;
}
return 0 ;
}
static int F_37 ( struct V_7 * V_8 , struct V_83 * V_30 )
{
enum V_112 V_2 = V_8 -> V_59 . V_2 ;
T_3 V_124 ;
T_3 V_85 ;
V_124 = F_30 ( V_30 -> V_111 ) ;
if ( V_124 > 127 ) {
F_3 ( V_23 , L_12 , V_124 ) ;
return - V_103 ;
}
if ( V_2 == V_60 ) {
F_3 ( V_23 ,
L_13 ) ;
return - V_103 ;
}
V_85 = F_33 ( V_8 -> V_94 , V_125 ) ;
V_85 &= ~ ( V_126 ) ;
V_85 |= F_38 ( V_124 ) ;
F_36 ( V_8 -> V_94 , V_125 , V_85 ) ;
if ( V_124 )
F_13 ( & V_8 -> V_59 , V_127 ) ;
else
F_13 ( & V_8 -> V_59 , V_128 ) ;
return 0 ;
}
static int F_39 ( struct V_7 * V_8 , struct V_83 * V_30 )
{
int V_19 ;
F_40 ( & V_8 -> V_66 ) ;
V_19 = V_8 -> V_129 -> V_130 ( & V_8 -> V_59 , V_30 ) ;
F_41 ( & V_8 -> V_66 ) ;
return V_19 ;
}
static int F_42 ( struct V_7 * V_8 , struct V_83 * V_30 )
{
enum V_112 V_2 = V_8 -> V_59 . V_2 ;
T_3 V_131 ;
int V_19 ;
T_3 V_85 ;
V_8 -> V_132 = false ;
V_131 = F_30 ( V_30 -> V_111 ) ;
switch ( V_2 ) {
case V_128 :
return - V_103 ;
case V_127 :
V_19 = F_39 ( V_8 , V_30 ) ;
if ( V_131 && ( ! V_19 || ( V_19 == V_133 ) ) ) {
if ( V_19 == 0 )
F_13 ( & V_8 -> V_59 ,
V_60 ) ;
V_85 = F_33 ( V_8 -> V_94 , V_95 ) ;
V_85 |= ( V_134 | V_135 ) ;
F_36 ( V_8 -> V_94 , V_95 , V_85 ) ;
V_8 -> V_136 = true ;
F_3 ( V_23 , L_14 ) ;
}
break;
case V_60 :
V_19 = F_39 ( V_8 , V_30 ) ;
if ( ! V_131 && ! V_19 )
F_13 ( & V_8 -> V_59 ,
V_127 ) ;
break;
default:
V_19 = - V_103 ;
}
return V_19 ;
}
static void F_43 ( struct V_62 * V_63 , struct V_64 * V_45 )
{
struct V_17 * V_18 = F_17 ( V_63 ) ;
struct V_7 * V_8 = V_18 -> V_8 ;
T_3 V_137 = 0 ;
T_3 V_85 ;
struct V_138 {
T_1 V_139 ;
T_1 V_140 ;
T_6 V_141 ;
T_6 V_142 ;
} V_143 V_138 ;
int V_19 ;
memcpy ( & V_138 , V_45 -> V_108 , sizeof( V_138 ) ) ;
V_8 -> V_139 = V_138 . V_139 ;
V_8 -> V_140 = V_138 . V_140 ;
V_8 -> V_141 = F_30 ( V_138 . V_141 ) ;
V_8 -> V_142 = F_30 ( V_138 . V_142 ) ;
V_85 = F_33 ( V_8 -> V_94 , V_95 ) ;
if ( V_85 & V_98 )
V_137 = V_8 -> V_142 ;
if ( V_85 & V_96 )
V_137 = V_8 -> V_140 ;
if ( V_137 > 125 )
V_137 = 0 ;
V_19 = F_44 ( V_8 ,
V_144 , V_137 ) ;
F_28 ( V_19 < 0 ) ;
}
static int F_45 ( struct V_7 * V_8 , struct V_83 * V_30 )
{
struct V_17 * V_18 ;
enum V_112 V_2 = V_8 -> V_59 . V_2 ;
T_6 V_145 ;
T_6 V_111 ;
if ( V_2 == V_128 )
return - V_103 ;
V_111 = F_30 ( V_30 -> V_111 ) ;
V_145 = F_30 ( V_30 -> V_145 ) ;
if ( V_145 != 6 ) {
F_46 ( V_8 -> V_56 , L_15 ,
V_145 ) ;
return - V_103 ;
}
V_18 = V_8 -> V_20 [ 0 ] ;
V_8 -> V_107 . V_18 = V_18 ;
V_8 -> V_107 . V_46 . V_72 = V_18 -> V_67 . V_146 ;
V_8 -> V_107 . V_46 . V_108 = V_8 -> V_106 ;
V_8 -> V_107 . V_46 . V_109 = F_43 ;
return F_9 ( V_18 , & V_8 -> V_107 ) ;
}
static int F_47 ( struct V_7 * V_8 , struct V_83 * V_30 )
{
T_6 V_145 ;
T_6 V_111 ;
T_6 V_102 ;
V_111 = F_30 ( V_30 -> V_111 ) ;
V_145 = F_30 ( V_30 -> V_145 ) ;
V_102 = F_30 ( V_30 -> V_102 ) ;
if ( V_102 || V_145 )
return - V_103 ;
V_8 -> V_147 = V_111 ;
return 0 ;
}
static int F_48 ( struct V_7 * V_8 , struct V_83 * V_30 )
{
int V_19 ;
switch ( V_30 -> V_148 ) {
case V_149 :
F_3 ( V_23 , L_16 ) ;
V_19 = F_32 ( V_8 , V_30 ) ;
break;
case V_150 :
F_3 ( V_23 , L_17 ) ;
V_19 = F_35 ( V_8 , V_30 , 0 ) ;
break;
case V_151 :
F_3 ( V_23 , L_18 ) ;
V_19 = F_35 ( V_8 , V_30 , 1 ) ;
break;
case V_152 :
F_3 ( V_23 , L_19 ) ;
V_19 = F_37 ( V_8 , V_30 ) ;
break;
case V_153 :
F_3 ( V_23 , L_20 ) ;
V_19 = F_42 ( V_8 , V_30 ) ;
break;
case V_154 :
F_3 ( V_23 , L_21 ) ;
V_19 = F_45 ( V_8 , V_30 ) ;
break;
case V_155 :
F_3 ( V_23 , L_22 ) ;
V_19 = F_47 ( V_8 , V_30 ) ;
break;
case V_156 :
F_3 ( V_23 , L_23 ) ;
V_8 -> V_132 = false ;
default:
F_3 ( V_23 , L_24 ) ;
V_19 = F_39 ( V_8 , V_30 ) ;
break;
}
return V_19 ;
}
static void F_49 ( struct V_7 * V_8 ,
const struct V_157 * V_158 )
{
struct V_83 * V_30 = V_8 -> V_159 ;
int V_19 = - V_103 ;
T_3 V_11 ;
if ( ! V_8 -> V_129 )
goto V_70;
F_50 ( V_30 ) ;
V_11 = F_30 ( V_30 -> V_145 ) ;
if ( ! V_11 ) {
V_8 -> V_61 = false ;
V_8 -> V_58 = false ;
V_8 -> V_42 = V_160 ;
} else {
V_8 -> V_61 = true ;
V_8 -> V_58 = ! ! ( V_30 -> V_88 & V_82 ) ;
V_8 -> V_42 = V_161 ;
}
if ( ( V_30 -> V_88 & V_162 ) == V_163 )
V_19 = F_48 ( V_8 , V_30 ) ;
else
V_19 = F_39 ( V_8 , V_30 ) ;
if ( V_19 == V_133 )
V_8 -> V_57 = true ;
V_70:
if ( V_19 < 0 )
F_21 ( V_8 ) ;
}
static void F_51 ( struct V_7 * V_8 ,
const struct V_157 * V_158 )
{
struct V_44 * V_164 = NULL ;
struct V_64 * V_165 ;
struct V_15 * V_16 ;
struct V_17 * V_166 ;
unsigned V_167 = 0 ;
unsigned V_168 ;
unsigned V_169 ;
void * V_108 ;
T_3 V_170 = 0 ;
T_3 V_48 ;
T_3 V_72 ;
T_1 V_9 ;
V_9 = V_158 -> V_171 ;
V_166 = V_8 -> V_20 [ 0 ] ;
V_8 -> V_42 = V_160 ;
V_16 = V_8 -> V_25 ;
F_52 ( V_166 , V_16 ) ;
V_164 = F_23 ( & V_166 -> V_51 ) ;
if ( ! V_164 )
return;
V_48 = F_53 ( V_16 -> V_29 ) ;
if ( V_48 == V_172 ) {
F_3 ( V_23 , L_25 ) ;
if ( V_164 )
F_24 ( V_166 , V_164 , - V_74 ) ;
return;
}
V_165 = & V_164 -> V_46 ;
V_108 = V_165 -> V_108 ;
V_169 = V_165 -> V_72 ;
V_72 = V_16 -> V_29 & V_173 ;
V_168 = V_166 -> V_67 . V_146 ;
if ( V_8 -> V_174 ) {
if ( V_165 -> V_72 > V_175 ) {
V_167 = F_54 ( V_165 -> V_72 - V_168 , V_168 ) ;
V_170 = V_167 - V_72 ;
V_108 = ( T_1 * ) V_108 + V_170 ;
V_165 -> V_47 += V_170 ;
V_169 -= V_170 ;
V_16 ++ ;
V_72 = V_16 -> V_29 & V_173 ;
V_166 -> V_26 = 0 ;
}
V_167 = F_55 ( ( V_165 -> V_72 - V_167 ) ,
V_168 ) ;
V_170 = F_56 ( T_3 , V_169 ,
V_167 - V_72 ) ;
memcpy ( V_108 , V_8 -> V_176 , V_170 ) ;
} else {
V_170 = V_165 -> V_72 - V_72 ;
}
V_165 -> V_47 += V_170 ;
if ( ( V_9 & 1 ) && V_165 -> V_47 < V_165 -> V_72 ) {
F_21 ( V_8 ) ;
} else {
F_24 ( V_166 , V_164 , 0 ) ;
if ( F_57 ( V_165 -> V_72 , V_166 -> V_67 . V_146 ) &&
V_165 -> V_72 && V_165 -> V_177 ) {
int V_19 ;
V_8 -> V_42 = V_43 ;
V_19 = F_2 ( V_8 , V_9 ,
V_8 -> V_76 , 0 ,
V_178 , false ) ;
F_28 ( V_19 < 0 ) ;
}
}
}
static void F_58 ( struct V_7 * V_8 ,
const struct V_157 * V_158 )
{
struct V_44 * V_164 ;
struct V_17 * V_18 ;
struct V_15 * V_16 ;
T_3 V_48 ;
V_18 = V_8 -> V_20 [ 0 ] ;
V_16 = V_8 -> V_25 ;
F_52 ( V_18 , V_16 ) ;
if ( ! F_19 ( & V_18 -> V_51 ) ) {
V_164 = F_23 ( & V_18 -> V_51 ) ;
F_24 ( V_18 , V_164 , 0 ) ;
}
if ( V_8 -> V_119 ) {
int V_19 ;
V_19 = F_59 ( V_8 , V_8 -> V_118 ) ;
if ( V_19 < 0 ) {
F_3 ( V_23 , L_26 ,
V_8 -> V_118 ) ;
F_21 ( V_8 ) ;
return;
}
}
V_48 = F_53 ( V_16 -> V_29 ) ;
if ( V_48 == V_172 )
F_3 ( V_23 , L_25 ) ;
V_8 -> V_55 = V_4 ;
F_25 ( V_8 ) ;
}
static void F_60 ( struct V_7 * V_8 ,
const struct V_157 * V_158 )
{
struct V_17 * V_18 = V_8 -> V_20 [ V_158 -> V_171 ] ;
V_18 -> V_21 &= ~ V_22 ;
V_18 -> V_41 = 0 ;
V_8 -> V_179 = false ;
switch ( V_8 -> V_55 ) {
case V_4 :
F_3 ( V_23 , L_2 ) ;
F_49 ( V_8 , V_158 ) ;
break;
case V_5 :
F_3 ( V_23 , L_3 ) ;
F_51 ( V_8 , V_158 ) ;
break;
case V_6 :
F_3 ( V_23 , L_4 ) ;
F_58 ( V_8 , V_158 ) ;
break;
default:
F_61 ( true , L_27 , V_8 -> V_55 ) ;
}
}
static void F_12 ( struct V_7 * V_8 ,
struct V_17 * V_18 , struct V_44 * V_45 )
{
int V_19 ;
V_45 -> V_53 = ! ! V_18 -> V_39 ;
if ( V_45 -> V_46 . V_72 == 0 ) {
V_19 = F_2 ( V_8 , V_18 -> V_39 ,
V_8 -> V_76 , 0 ,
V_178 , false ) ;
} else if ( ! F_57 ( V_45 -> V_46 . V_72 , V_18 -> V_67 . V_146 )
&& ( V_18 -> V_39 == 0 ) ) {
T_3 V_167 = 0 ;
T_3 V_146 ;
V_19 = F_62 ( & V_8 -> V_59 , & V_45 -> V_46 ,
V_18 -> V_39 ) ;
if ( V_19 ) {
F_63 ( V_8 -> V_56 , L_28 ) ;
return;
}
V_146 = V_18 -> V_67 . V_146 ;
if ( V_45 -> V_46 . V_72 > V_175 ) {
V_167 = F_54 ( V_45 -> V_46 . V_72 - V_146 ,
V_146 ) ;
V_19 = F_2 ( V_8 , V_18 -> V_39 ,
V_45 -> V_46 . V_180 ,
V_167 ,
V_178 ,
true ) ;
}
V_167 = F_55 ( ( V_45 -> V_46 . V_72 - V_167 ) ,
V_146 ) ;
V_8 -> V_174 = true ;
V_19 = F_2 ( V_8 , V_18 -> V_39 ,
V_8 -> V_181 , V_167 ,
V_178 , false ) ;
} else {
V_19 = F_62 ( & V_8 -> V_59 , & V_45 -> V_46 ,
V_18 -> V_39 ) ;
if ( V_19 ) {
F_63 ( V_8 -> V_56 , L_28 ) ;
return;
}
V_19 = F_2 ( V_8 , V_18 -> V_39 , V_45 -> V_46 . V_180 ,
V_45 -> V_46 . V_72 , V_178 ,
false ) ;
}
F_28 ( V_19 < 0 ) ;
}
static int F_64 ( struct V_17 * V_18 )
{
struct V_7 * V_8 = V_18 -> V_8 ;
T_3 type ;
type = V_8 -> V_61 ? V_182
: V_183 ;
return F_2 ( V_8 , V_18 -> V_39 ,
V_8 -> V_76 , 0 , type , false ) ;
}
static void F_14 ( struct V_7 * V_8 , struct V_17 * V_18 )
{
if ( V_8 -> V_136 ) {
F_3 ( V_23 , L_29 ) ;
F_65 ( V_8 ) ;
V_8 -> V_136 = 0 ;
}
F_28 ( F_64 ( V_18 ) ) ;
}
static void F_66 ( struct V_7 * V_8 ,
const struct V_157 * V_158 )
{
struct V_17 * V_18 = V_8 -> V_20 [ V_158 -> V_171 ] ;
F_14 ( V_8 , V_18 ) ;
}
static void F_67 ( struct V_7 * V_8 , struct V_17 * V_18 )
{
struct V_13 V_14 ;
T_3 V_184 ;
int V_19 ;
if ( ! V_18 -> V_41 )
return;
V_184 = V_185 ;
V_184 |= V_186 ;
V_184 |= F_68 ( V_18 -> V_41 ) ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_19 = F_7 ( V_8 , V_18 -> V_39 , V_184 , & V_14 ) ;
F_69 ( V_19 ) ;
V_18 -> V_41 = 0 ;
}
static void F_70 ( struct V_7 * V_8 ,
const struct V_157 * V_158 )
{
V_8 -> V_179 = true ;
switch ( V_158 -> V_48 ) {
case V_187 :
F_3 ( V_23 , L_30 ) ;
if ( V_8 -> V_58 != V_158 -> V_171 ) {
struct V_17 * V_18 = V_8 -> V_20 [ V_8 -> V_58 ] ;
F_3 ( V_23 ,
L_31 ) ;
F_67 ( V_8 , V_18 ) ;
F_21 ( V_8 ) ;
return;
}
break;
case V_188 :
if ( V_8 -> V_42 != V_160 )
return;
F_3 ( V_23 , L_32 ) ;
V_8 -> V_55 = V_6 ;
if ( V_8 -> V_57 ) {
F_69 ( V_158 -> V_171 != 1 ) ;
F_3 ( V_23 , L_33 ) ;
return;
}
F_66 ( V_8 , V_158 ) ;
}
}
void F_71 ( struct V_7 * V_8 ,
const struct V_157 * V_158 )
{
T_1 V_9 = V_158 -> V_171 ;
F_3 ( V_23 , L_34 ,
F_72 ( V_158 -> V_189 ) ,
V_9 >> 1 , ( V_9 & 1 ) ? L_35 : L_36 ,
F_1 ( V_8 -> V_55 ) ) ;
switch ( V_158 -> V_189 ) {
case V_190 :
F_60 ( V_8 , V_158 ) ;
break;
case V_191 :
F_70 ( V_8 , V_158 ) ;
break;
case V_192 :
case V_193 :
case V_194 :
case V_195 :
break;
}
}
