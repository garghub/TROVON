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
T_3 V_11 , T_3 type )
{
struct V_12 V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
int V_18 ;
V_17 = V_8 -> V_19 [ V_9 ] ;
if ( V_17 -> V_20 & V_21 ) {
F_3 ( V_22 , L_6 , V_17 -> V_23 ) ;
return 0 ;
}
V_15 = V_8 -> V_24 ;
V_15 -> V_25 = F_4 ( V_10 ) ;
V_15 -> V_26 = F_5 ( V_10 ) ;
V_15 -> V_27 = V_11 ;
V_15 -> V_28 = type ;
V_15 -> V_28 |= ( V_29
| V_30
| V_31
| V_32 ) ;
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
V_13 . V_33 = F_5 ( V_8 -> V_34 ) ;
V_13 . V_35 = F_4 ( V_8 -> V_34 ) ;
F_6 ( V_17 , V_15 ) ;
V_18 = F_7 ( V_8 , V_17 -> V_36 ,
V_37 , & V_13 ) ;
if ( V_18 < 0 ) {
F_3 ( V_22 , L_7 ,
V_17 -> V_23 ) ;
return V_18 ;
}
V_17 -> V_20 |= V_21 ;
V_17 -> V_38 = F_8 ( V_8 ,
V_17 -> V_36 ) ;
V_8 -> V_39 = V_40 ;
return 0 ;
}
static int F_9 ( struct V_16 * V_17 ,
struct V_41 * V_42 )
{
struct V_7 * V_8 = V_17 -> V_8 ;
V_42 -> V_43 . V_44 = 0 ;
V_42 -> V_43 . V_45 = - V_46 ;
V_42 -> V_9 = V_17 -> V_36 ;
F_10 ( & V_42 -> V_47 , & V_17 -> V_48 ) ;
if ( V_17 -> V_20 & V_49 ) {
unsigned V_50 ;
V_50 = ! ! ( V_17 -> V_20 & V_51 ) ;
if ( V_8 -> V_52 != V_5 ) {
F_11 ( V_8 -> V_53 , L_8 ) ;
return 0 ;
}
F_12 ( V_8 , V_8 -> V_19 [ V_50 ] , V_42 ) ;
V_17 -> V_20 &= ~ ( V_49 |
V_51 ) ;
return 0 ;
}
if ( V_8 -> V_54 ) {
unsigned V_50 ;
V_50 = ! V_8 -> V_55 ;
V_8 -> V_54 = false ;
F_13 ( & V_8 -> V_56 , V_57 ) ;
if ( V_8 -> V_52 == V_6 )
F_14 ( V_8 , V_8 -> V_19 [ V_50 ] ) ;
else
F_3 ( V_22 ,
L_9 ) ;
return 0 ;
}
if ( V_8 -> V_58 ) {
unsigned V_50 ;
V_50 = V_8 -> V_55 ;
V_8 -> V_52 = V_5 ;
F_12 ( V_8 , V_8 -> V_19 [ V_50 ] , V_42 ) ;
V_17 -> V_20 &= ~ V_51 ;
}
return 0 ;
}
int F_15 ( struct V_59 * V_60 , struct V_61 * V_43 ,
T_4 V_62 )
{
struct V_41 * V_42 = F_16 ( V_43 ) ;
struct V_16 * V_17 = F_17 ( V_60 ) ;
struct V_7 * V_8 = V_17 -> V_8 ;
unsigned long V_20 ;
int V_18 ;
F_18 ( & V_8 -> V_63 , V_20 ) ;
if ( ! V_17 -> V_64 . V_65 ) {
F_3 ( V_22 ,
L_10 ,
V_43 , V_17 -> V_23 ) ;
V_18 = - V_66 ;
goto V_67;
}
if ( ! F_19 ( & V_17 -> V_48 ) ) {
V_18 = - V_68 ;
goto V_67;
}
F_3 ( V_22 ,
L_11 ,
V_43 , V_17 -> V_23 , V_43 -> V_69 ,
F_1 ( V_8 -> V_52 ) ) ;
V_18 = F_9 ( V_17 , V_42 ) ;
V_67:
F_20 ( & V_8 -> V_63 , V_20 ) ;
return V_18 ;
}
static void F_21 ( struct V_7 * V_8 )
{
struct V_16 * V_17 ;
V_17 = V_8 -> V_19 [ 1 ] ;
V_17 -> V_20 = V_70 ;
V_17 = V_8 -> V_19 [ 0 ] ;
F_22 ( V_17 , 1 , false ) ;
V_17 -> V_20 = V_70 ;
V_8 -> V_54 = false ;
if ( ! F_19 ( & V_17 -> V_48 ) ) {
struct V_41 * V_42 ;
V_42 = F_23 ( & V_17 -> V_48 ) ;
F_24 ( V_17 , V_42 , - V_71 ) ;
}
V_8 -> V_52 = V_4 ;
F_25 ( V_8 ) ;
}
int F_26 ( struct V_59 * V_60 , int V_72 )
{
struct V_16 * V_17 = F_17 ( V_60 ) ;
struct V_7 * V_8 = V_17 -> V_8 ;
F_21 ( V_8 ) ;
return 0 ;
}
int F_27 ( struct V_59 * V_60 , int V_72 )
{
struct V_16 * V_17 = F_17 ( V_60 ) ;
struct V_7 * V_8 = V_17 -> V_8 ;
unsigned long V_20 ;
int V_18 ;
F_18 ( & V_8 -> V_63 , V_20 ) ;
V_18 = F_26 ( V_60 , V_72 ) ;
F_20 ( & V_8 -> V_63 , V_20 ) ;
return V_18 ;
}
void F_25 ( struct V_7 * V_8 )
{
int V_18 ;
V_18 = F_2 ( V_8 , 0 , V_8 -> V_73 , 8 ,
V_74 ) ;
F_28 ( V_18 < 0 ) ;
}
static struct V_16 * F_29 ( struct V_7 * V_8 , T_5 V_75 )
{
struct V_16 * V_17 ;
T_3 V_76 = F_30 ( V_75 ) ;
T_3 V_9 ;
V_9 = ( V_76 & V_77 ) << 1 ;
if ( ( V_76 & V_78 ) == V_79 )
V_9 |= 1 ;
V_17 = V_8 -> V_19 [ V_9 ] ;
if ( V_17 -> V_20 & V_70 )
return V_17 ;
return NULL ;
}
static void F_31 ( struct V_59 * V_60 , struct V_61 * V_42 )
{
}
static int F_32 ( struct V_7 * V_8 ,
struct V_80 * V_28 )
{
struct V_16 * V_17 ;
T_3 V_81 ;
T_3 V_82 ;
T_6 V_83 = 0 ;
T_5 * V_84 ;
V_81 = V_28 -> V_85 & V_86 ;
switch ( V_81 ) {
case V_87 :
V_83 |= V_8 -> V_56 . V_88 ;
if ( V_8 -> V_89 == V_90 ) {
V_82 = F_33 ( V_8 -> V_91 , V_92 ) ;
if ( V_82 & V_93 )
V_83 |= 1 << V_94 ;
if ( V_82 & V_95 )
V_83 |= 1 << V_96 ;
}
break;
case V_97 :
break;
case V_98 :
V_17 = F_29 ( V_8 , V_28 -> V_99 ) ;
if ( ! V_17 )
return - V_100 ;
if ( V_17 -> V_20 & V_101 )
V_83 = 1 << V_102 ;
break;
default:
return - V_100 ;
}
V_84 = ( T_5 * ) V_8 -> V_103 ;
* V_84 = F_34 ( V_83 ) ;
V_17 = V_8 -> V_19 [ 0 ] ;
V_8 -> V_104 . V_17 = V_17 ;
V_8 -> V_104 . V_43 . V_69 = sizeof( * V_84 ) ;
V_8 -> V_104 . V_43 . V_105 = V_8 -> V_103 ;
V_8 -> V_104 . V_43 . V_106 = F_31 ;
return F_9 ( V_17 , & V_8 -> V_104 ) ;
}
static int F_35 ( struct V_7 * V_8 ,
struct V_80 * V_28 , int V_107 )
{
struct V_16 * V_17 ;
T_3 V_81 ;
T_3 V_108 ;
T_3 V_99 ;
T_3 V_82 ;
int V_18 ;
enum V_109 V_2 ;
V_108 = F_30 ( V_28 -> V_108 ) ;
V_99 = F_30 ( V_28 -> V_99 ) ;
V_81 = V_28 -> V_85 & V_86 ;
V_2 = V_8 -> V_56 . V_2 ;
switch ( V_81 ) {
case V_87 :
switch ( V_108 ) {
case V_110 :
break;
case V_111 :
if ( V_2 != V_57 )
return - V_100 ;
if ( V_8 -> V_89 != V_90 )
return - V_100 ;
V_82 = F_33 ( V_8 -> V_91 , V_92 ) ;
if ( V_107 )
V_82 |= V_93 ;
else
V_82 &= ~ V_93 ;
F_36 ( V_8 -> V_91 , V_92 , V_82 ) ;
break;
case V_112 :
if ( V_2 != V_57 )
return - V_100 ;
if ( V_8 -> V_89 != V_90 )
return - V_100 ;
V_82 = F_33 ( V_8 -> V_91 , V_92 ) ;
if ( V_107 )
V_82 |= V_95 ;
else
V_82 &= ~ V_95 ;
F_36 ( V_8 -> V_91 , V_92 , V_82 ) ;
break;
case V_113 :
return - V_100 ;
case V_114 :
if ( ( V_99 & 0xff ) != 0 )
return - V_100 ;
if ( ! V_107 )
return - V_100 ;
V_8 -> V_115 = V_99 >> 8 ;
V_8 -> V_116 = true ;
break;
default:
return - V_100 ;
}
break;
case V_97 :
switch ( V_108 ) {
case V_117 :
if ( V_99 & V_118 )
;
if ( V_99 & V_119 )
;
break;
default:
return - V_100 ;
}
break;
case V_98 :
switch ( V_108 ) {
case V_102 :
V_17 = F_29 ( V_8 , V_99 ) ;
if ( ! V_17 )
return - V_100 ;
if ( V_107 == 0 && ( V_17 -> V_20 & V_120 ) )
break;
V_18 = F_22 ( V_17 , V_107 , true ) ;
if ( V_18 )
return - V_100 ;
break;
default:
return - V_100 ;
}
break;
default:
return - V_100 ;
}
return 0 ;
}
static int F_37 ( struct V_7 * V_8 , struct V_80 * V_28 )
{
enum V_109 V_2 = V_8 -> V_56 . V_2 ;
T_3 V_121 ;
T_3 V_82 ;
V_121 = F_30 ( V_28 -> V_108 ) ;
if ( V_121 > 127 ) {
F_3 ( V_22 , L_12 , V_121 ) ;
return - V_100 ;
}
if ( V_2 == V_57 ) {
F_3 ( V_22 ,
L_13 ) ;
return - V_100 ;
}
V_82 = F_33 ( V_8 -> V_91 , V_122 ) ;
V_82 &= ~ ( V_123 ) ;
V_82 |= F_38 ( V_121 ) ;
F_36 ( V_8 -> V_91 , V_122 , V_82 ) ;
if ( V_121 )
F_13 ( & V_8 -> V_56 , V_124 ) ;
else
F_13 ( & V_8 -> V_56 , V_125 ) ;
return 0 ;
}
static int F_39 ( struct V_7 * V_8 , struct V_80 * V_28 )
{
int V_18 ;
F_40 ( & V_8 -> V_63 ) ;
V_18 = V_8 -> V_126 -> V_127 ( & V_8 -> V_56 , V_28 ) ;
F_41 ( & V_8 -> V_63 ) ;
return V_18 ;
}
static int F_42 ( struct V_7 * V_8 , struct V_80 * V_28 )
{
enum V_109 V_2 = V_8 -> V_56 . V_2 ;
T_3 V_128 ;
int V_18 ;
T_3 V_82 ;
V_8 -> V_129 = false ;
V_128 = F_30 ( V_28 -> V_108 ) ;
switch ( V_2 ) {
case V_125 :
return - V_100 ;
case V_124 :
V_18 = F_39 ( V_8 , V_28 ) ;
if ( V_128 && ( ! V_18 || ( V_18 == V_130 ) ) ) {
if ( V_18 == 0 )
F_13 ( & V_8 -> V_56 ,
V_57 ) ;
V_82 = F_33 ( V_8 -> V_91 , V_92 ) ;
V_82 |= ( V_131 | V_132 ) ;
F_36 ( V_8 -> V_91 , V_92 , V_82 ) ;
V_8 -> V_133 = true ;
F_3 ( V_22 , L_14 ) ;
}
break;
case V_57 :
V_18 = F_39 ( V_8 , V_28 ) ;
if ( ! V_128 && ! V_18 )
F_13 ( & V_8 -> V_56 ,
V_124 ) ;
break;
default:
V_18 = - V_100 ;
}
return V_18 ;
}
static void F_43 ( struct V_59 * V_60 , struct V_61 * V_42 )
{
struct V_16 * V_17 = F_17 ( V_60 ) ;
struct V_7 * V_8 = V_17 -> V_8 ;
T_3 V_134 = 0 ;
T_3 V_82 ;
struct V_135 {
T_1 V_136 ;
T_1 V_137 ;
T_6 V_138 ;
T_6 V_139 ;
} V_140 V_135 ;
int V_18 ;
memcpy ( & V_135 , V_42 -> V_105 , sizeof( V_135 ) ) ;
V_8 -> V_136 = V_135 . V_136 ;
V_8 -> V_137 = V_135 . V_137 ;
V_8 -> V_138 = F_30 ( V_135 . V_138 ) ;
V_8 -> V_139 = F_30 ( V_135 . V_139 ) ;
V_82 = F_33 ( V_8 -> V_91 , V_92 ) ;
if ( V_82 & V_95 )
V_134 = V_8 -> V_139 ;
if ( V_82 & V_93 )
V_134 = V_8 -> V_137 ;
if ( V_134 > 125 )
V_134 = 0 ;
V_18 = F_44 ( V_8 ,
V_141 , V_134 ) ;
F_28 ( V_18 < 0 ) ;
}
static int F_45 ( struct V_7 * V_8 , struct V_80 * V_28 )
{
struct V_16 * V_17 ;
enum V_109 V_2 = V_8 -> V_56 . V_2 ;
T_6 V_142 ;
T_6 V_108 ;
if ( V_2 == V_125 )
return - V_100 ;
V_108 = F_30 ( V_28 -> V_108 ) ;
V_142 = F_30 ( V_28 -> V_142 ) ;
if ( V_142 != 6 ) {
F_46 ( V_8 -> V_53 , L_15 ,
V_142 ) ;
return - V_100 ;
}
V_17 = V_8 -> V_19 [ 0 ] ;
V_8 -> V_104 . V_17 = V_17 ;
V_8 -> V_104 . V_43 . V_69 = V_17 -> V_64 . V_143 ;
V_8 -> V_104 . V_43 . V_105 = V_8 -> V_103 ;
V_8 -> V_104 . V_43 . V_106 = F_43 ;
return F_9 ( V_17 , & V_8 -> V_104 ) ;
}
static int F_47 ( struct V_7 * V_8 , struct V_80 * V_28 )
{
T_6 V_142 ;
T_6 V_108 ;
T_6 V_99 ;
V_108 = F_30 ( V_28 -> V_108 ) ;
V_142 = F_30 ( V_28 -> V_142 ) ;
V_99 = F_30 ( V_28 -> V_99 ) ;
if ( V_99 || V_142 )
return - V_100 ;
V_8 -> V_144 = V_108 ;
return 0 ;
}
static int F_48 ( struct V_7 * V_8 , struct V_80 * V_28 )
{
int V_18 ;
switch ( V_28 -> V_145 ) {
case V_146 :
F_3 ( V_22 , L_16 ) ;
V_18 = F_32 ( V_8 , V_28 ) ;
break;
case V_147 :
F_3 ( V_22 , L_17 ) ;
V_18 = F_35 ( V_8 , V_28 , 0 ) ;
break;
case V_148 :
F_3 ( V_22 , L_18 ) ;
V_18 = F_35 ( V_8 , V_28 , 1 ) ;
break;
case V_149 :
F_3 ( V_22 , L_19 ) ;
V_18 = F_37 ( V_8 , V_28 ) ;
break;
case V_150 :
F_3 ( V_22 , L_20 ) ;
V_18 = F_42 ( V_8 , V_28 ) ;
break;
case V_151 :
F_3 ( V_22 , L_21 ) ;
V_18 = F_45 ( V_8 , V_28 ) ;
break;
case V_152 :
F_3 ( V_22 , L_22 ) ;
V_18 = F_47 ( V_8 , V_28 ) ;
break;
default:
F_3 ( V_22 , L_23 ) ;
V_18 = F_39 ( V_8 , V_28 ) ;
break;
}
return V_18 ;
}
static void F_49 ( struct V_7 * V_8 ,
const struct V_153 * V_154 )
{
struct V_80 * V_28 = V_8 -> V_155 ;
int V_18 = - V_100 ;
T_3 V_11 ;
if ( ! V_8 -> V_126 )
goto V_67;
F_50 ( V_28 ) ;
V_11 = F_30 ( V_28 -> V_142 ) ;
if ( ! V_11 ) {
V_8 -> V_58 = false ;
V_8 -> V_55 = false ;
V_8 -> V_39 = V_156 ;
} else {
V_8 -> V_58 = true ;
V_8 -> V_55 = ! ! ( V_28 -> V_85 & V_79 ) ;
V_8 -> V_39 = V_157 ;
}
if ( ( V_28 -> V_85 & V_158 ) == V_159 )
V_18 = F_48 ( V_8 , V_28 ) ;
else
V_18 = F_39 ( V_8 , V_28 ) ;
if ( V_18 == V_130 )
V_8 -> V_54 = true ;
V_67:
if ( V_18 < 0 )
F_21 ( V_8 ) ;
}
static void F_51 ( struct V_7 * V_8 ,
const struct V_153 * V_154 )
{
struct V_41 * V_160 = NULL ;
struct V_61 * V_161 ;
struct V_14 * V_15 ;
struct V_16 * V_162 ;
T_3 V_163 ;
T_3 V_45 ;
T_3 V_69 ;
T_1 V_9 ;
V_9 = V_154 -> V_164 ;
V_162 = V_8 -> V_19 [ 0 ] ;
V_8 -> V_39 = V_156 ;
V_15 = V_8 -> V_24 ;
F_52 ( V_162 , V_15 ) ;
V_160 = F_23 ( & V_162 -> V_48 ) ;
if ( ! V_160 )
return;
V_45 = F_53 ( V_15 -> V_27 ) ;
if ( V_45 == V_165 ) {
F_3 ( V_22 , L_24 ) ;
if ( V_160 )
F_24 ( V_162 , V_160 , - V_71 ) ;
return;
}
V_161 = & V_160 -> V_43 ;
V_69 = V_15 -> V_27 & V_166 ;
if ( V_8 -> V_167 ) {
unsigned V_168 = V_161 -> V_69 ;
unsigned V_169 = V_162 -> V_64 . V_143 ;
V_168 += ( V_169 - ( V_168 % V_169 ) ) ;
V_163 = F_54 ( T_3 , V_161 -> V_69 ,
V_168 - V_69 ) ;
memcpy ( V_161 -> V_105 , V_8 -> V_170 , V_163 ) ;
} else {
V_163 = V_161 -> V_69 - V_69 ;
}
V_161 -> V_44 += V_163 ;
if ( ( V_9 & 1 ) && V_161 -> V_44 < V_161 -> V_69 ) {
F_21 ( V_8 ) ;
} else {
F_24 ( V_162 , V_160 , 0 ) ;
if ( F_55 ( V_161 -> V_69 , V_162 -> V_64 . V_143 ) &&
V_161 -> V_69 && V_161 -> V_171 ) {
int V_18 ;
V_8 -> V_39 = V_40 ;
V_18 = F_2 ( V_8 , V_9 ,
V_8 -> V_73 , 0 ,
V_172 ) ;
F_28 ( V_18 < 0 ) ;
}
}
}
static void F_56 ( struct V_7 * V_8 ,
const struct V_153 * V_154 )
{
struct V_41 * V_160 ;
struct V_16 * V_17 ;
struct V_14 * V_15 ;
T_3 V_45 ;
V_17 = V_8 -> V_19 [ 0 ] ;
V_15 = V_8 -> V_24 ;
F_52 ( V_17 , V_15 ) ;
if ( ! F_19 ( & V_17 -> V_48 ) ) {
V_160 = F_23 ( & V_17 -> V_48 ) ;
F_24 ( V_17 , V_160 , 0 ) ;
}
if ( V_8 -> V_116 ) {
int V_18 ;
V_18 = F_57 ( V_8 , V_8 -> V_115 ) ;
if ( V_18 < 0 ) {
F_3 ( V_22 , L_25 ,
V_8 -> V_115 ) ;
F_21 ( V_8 ) ;
return;
}
}
V_45 = F_53 ( V_15 -> V_27 ) ;
if ( V_45 == V_165 )
F_3 ( V_22 , L_24 ) ;
V_8 -> V_52 = V_4 ;
F_25 ( V_8 ) ;
}
static void F_58 ( struct V_7 * V_8 ,
const struct V_153 * V_154 )
{
struct V_16 * V_17 = V_8 -> V_19 [ V_154 -> V_164 ] ;
V_17 -> V_20 &= ~ V_21 ;
V_17 -> V_38 = 0 ;
V_8 -> V_173 = false ;
switch ( V_8 -> V_52 ) {
case V_4 :
F_3 ( V_22 , L_2 ) ;
F_49 ( V_8 , V_154 ) ;
break;
case V_5 :
F_3 ( V_22 , L_3 ) ;
F_51 ( V_8 , V_154 ) ;
break;
case V_6 :
F_3 ( V_22 , L_4 ) ;
F_56 ( V_8 , V_154 ) ;
break;
default:
F_59 ( true , L_26 , V_8 -> V_52 ) ;
}
}
static void F_12 ( struct V_7 * V_8 ,
struct V_16 * V_17 , struct V_41 * V_42 )
{
int V_18 ;
V_42 -> V_50 = ! ! V_17 -> V_36 ;
if ( V_42 -> V_43 . V_69 == 0 ) {
V_18 = F_2 ( V_8 , V_17 -> V_36 ,
V_8 -> V_73 , 0 ,
V_172 ) ;
} else if ( ! F_55 ( V_42 -> V_43 . V_69 , V_17 -> V_64 . V_143 )
&& ( V_17 -> V_36 == 0 ) ) {
T_3 V_168 ;
T_3 V_143 ;
V_18 = F_60 ( & V_8 -> V_56 , & V_42 -> V_43 ,
V_17 -> V_36 ) ;
if ( V_18 ) {
F_61 ( V_8 -> V_53 , L_27 ) ;
return;
}
F_28 ( V_42 -> V_43 . V_69 > V_174 ) ;
V_143 = V_17 -> V_64 . V_143 ;
V_168 = F_62 ( V_42 -> V_43 . V_69 , V_143 ) ;
V_8 -> V_167 = true ;
V_18 = F_2 ( V_8 , V_17 -> V_36 ,
V_8 -> V_175 , V_168 ,
V_172 ) ;
} else {
V_18 = F_60 ( & V_8 -> V_56 , & V_42 -> V_43 ,
V_17 -> V_36 ) ;
if ( V_18 ) {
F_61 ( V_8 -> V_53 , L_27 ) ;
return;
}
V_18 = F_2 ( V_8 , V_17 -> V_36 , V_42 -> V_43 . V_176 ,
V_42 -> V_43 . V_69 , V_172 ) ;
}
F_28 ( V_18 < 0 ) ;
}
static int F_63 ( struct V_16 * V_17 )
{
struct V_7 * V_8 = V_17 -> V_8 ;
T_3 type ;
type = V_8 -> V_58 ? V_177
: V_178 ;
return F_2 ( V_8 , V_17 -> V_36 ,
V_8 -> V_73 , 0 , type ) ;
}
static void F_14 ( struct V_7 * V_8 , struct V_16 * V_17 )
{
if ( V_8 -> V_133 ) {
F_3 ( V_22 , L_28 ) ;
F_64 ( V_8 ) ;
V_8 -> V_133 = 0 ;
}
F_28 ( F_63 ( V_17 ) ) ;
}
static void F_65 ( struct V_7 * V_8 ,
const struct V_153 * V_154 )
{
struct V_16 * V_17 = V_8 -> V_19 [ V_154 -> V_164 ] ;
F_14 ( V_8 , V_17 ) ;
}
static void F_66 ( struct V_7 * V_8 , struct V_16 * V_17 )
{
struct V_12 V_13 ;
T_3 V_179 ;
int V_18 ;
if ( ! V_17 -> V_38 )
return;
V_179 = V_180 ;
V_179 |= V_181 ;
V_179 |= F_67 ( V_17 -> V_38 ) ;
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
V_18 = F_7 ( V_8 , V_17 -> V_36 , V_179 , & V_13 ) ;
F_68 ( V_18 ) ;
V_17 -> V_38 = 0 ;
}
static void F_69 ( struct V_7 * V_8 ,
const struct V_153 * V_154 )
{
V_8 -> V_173 = true ;
switch ( V_154 -> V_45 ) {
case V_182 :
F_3 ( V_22 , L_29 ) ;
if ( V_8 -> V_55 != V_154 -> V_164 ) {
struct V_16 * V_17 = V_8 -> V_19 [ V_8 -> V_55 ] ;
F_3 ( V_22 ,
L_30 ) ;
F_66 ( V_8 , V_17 ) ;
F_21 ( V_8 ) ;
return;
}
break;
case V_183 :
if ( V_8 -> V_39 != V_156 )
return;
F_3 ( V_22 , L_31 ) ;
V_8 -> V_52 = V_6 ;
if ( V_8 -> V_54 ) {
F_68 ( V_154 -> V_164 != 1 ) ;
F_3 ( V_22 , L_32 ) ;
return;
}
F_65 ( V_8 , V_154 ) ;
}
}
void F_70 ( struct V_7 * V_8 ,
const struct V_153 * V_154 )
{
T_1 V_9 = V_154 -> V_164 ;
F_3 ( V_22 , L_33 ,
F_71 ( V_154 -> V_184 ) ,
V_9 >> 1 , ( V_9 & 1 ) ? L_34 : L_35 ,
F_1 ( V_8 -> V_52 ) ) ;
switch ( V_154 -> V_184 ) {
case V_185 :
F_58 ( V_8 , V_154 ) ;
break;
case V_186 :
F_69 ( V_8 , V_154 ) ;
break;
case V_187 :
case V_188 :
case V_189 :
case V_190 :
break;
}
}
