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
V_18 = F_6 ( V_8 , V_17 -> V_36 ,
V_37 , & V_13 ) ;
if ( V_18 < 0 ) {
F_3 ( V_22 , L_7 ,
V_17 -> V_23 ) ;
return V_18 ;
}
V_17 -> V_20 |= V_21 ;
V_17 -> V_38 = F_7 ( V_8 ,
V_17 -> V_36 ) ;
V_8 -> V_39 = V_40 ;
return 0 ;
}
static int F_8 ( struct V_16 * V_17 ,
struct V_41 * V_42 )
{
struct V_7 * V_8 = V_17 -> V_8 ;
V_42 -> V_43 . V_44 = 0 ;
V_42 -> V_43 . V_45 = - V_46 ;
V_42 -> V_9 = V_17 -> V_36 ;
F_9 ( & V_42 -> V_47 , & V_17 -> V_48 ) ;
if ( V_17 -> V_20 & V_49 ) {
unsigned V_50 ;
V_50 = ! ! ( V_17 -> V_20 & V_51 ) ;
if ( V_8 -> V_52 != V_5 ) {
F_10 ( V_8 -> V_53 , L_8 ) ;
return 0 ;
}
F_11 ( V_8 , V_8 -> V_19 [ V_50 ] , V_42 ) ;
V_17 -> V_20 &= ~ ( V_49 |
V_51 ) ;
return 0 ;
}
if ( V_8 -> V_54 ) {
unsigned V_50 ;
V_50 = ! V_8 -> V_55 ;
V_8 -> V_54 = false ;
F_12 ( & V_8 -> V_56 , V_57 ) ;
if ( V_8 -> V_52 == V_6 )
F_13 ( V_8 , V_8 -> V_19 [ V_50 ] ) ;
else
F_3 ( V_22 ,
L_9 ) ;
return 0 ;
}
if ( V_8 -> V_58 ) {
unsigned V_50 ;
V_50 = V_8 -> V_55 ;
V_8 -> V_52 = V_5 ;
F_11 ( V_8 , V_8 -> V_19 [ V_50 ] , V_42 ) ;
V_17 -> V_20 &= ~ V_51 ;
}
return 0 ;
}
int F_14 ( struct V_59 * V_60 , struct V_61 * V_43 ,
T_4 V_62 )
{
struct V_41 * V_42 = F_15 ( V_43 ) ;
struct V_16 * V_17 = F_16 ( V_60 ) ;
struct V_7 * V_8 = V_17 -> V_8 ;
unsigned long V_20 ;
int V_18 ;
F_17 ( & V_8 -> V_63 , V_20 ) ;
if ( ! V_17 -> V_64 . V_65 ) {
F_3 ( V_22 ,
L_10 ,
V_43 , V_17 -> V_23 ) ;
V_18 = - V_66 ;
goto V_67;
}
if ( ! F_18 ( & V_17 -> V_48 ) ) {
V_18 = - V_68 ;
goto V_67;
}
F_3 ( V_22 ,
L_11 ,
V_43 , V_17 -> V_23 , V_43 -> V_69 ,
F_1 ( V_8 -> V_52 ) ) ;
V_18 = F_8 ( V_17 , V_42 ) ;
V_67:
F_19 ( & V_8 -> V_63 , V_20 ) ;
return V_18 ;
}
static void F_20 ( struct V_7 * V_8 )
{
struct V_16 * V_17 ;
V_17 = V_8 -> V_19 [ 1 ] ;
V_17 -> V_20 = V_70 ;
V_17 = V_8 -> V_19 [ 0 ] ;
F_21 ( V_17 , 1 , false ) ;
V_17 -> V_20 = V_70 ;
V_8 -> V_54 = false ;
if ( ! F_18 ( & V_17 -> V_48 ) ) {
struct V_41 * V_42 ;
V_42 = F_22 ( & V_17 -> V_48 ) ;
F_23 ( V_17 , V_42 , - V_71 ) ;
}
V_8 -> V_52 = V_4 ;
F_24 ( V_8 ) ;
}
int F_25 ( struct V_59 * V_60 , int V_72 )
{
struct V_16 * V_17 = F_16 ( V_60 ) ;
struct V_7 * V_8 = V_17 -> V_8 ;
F_20 ( V_8 ) ;
return 0 ;
}
int F_26 ( struct V_59 * V_60 , int V_72 )
{
struct V_16 * V_17 = F_16 ( V_60 ) ;
struct V_7 * V_8 = V_17 -> V_8 ;
unsigned long V_20 ;
int V_18 ;
F_17 ( & V_8 -> V_63 , V_20 ) ;
V_18 = F_25 ( V_60 , V_72 ) ;
F_19 ( & V_8 -> V_63 , V_20 ) ;
return V_18 ;
}
void F_24 ( struct V_7 * V_8 )
{
int V_18 ;
V_18 = F_2 ( V_8 , 0 , V_8 -> V_73 , 8 ,
V_74 ) ;
F_27 ( V_18 < 0 ) ;
}
static struct V_16 * F_28 ( struct V_7 * V_8 , T_5 V_75 )
{
struct V_16 * V_17 ;
T_3 V_76 = F_29 ( V_75 ) ;
T_3 V_9 ;
V_9 = ( V_76 & V_77 ) << 1 ;
if ( ( V_76 & V_78 ) == V_79 )
V_9 |= 1 ;
V_17 = V_8 -> V_19 [ V_9 ] ;
if ( V_17 -> V_20 & V_70 )
return V_17 ;
return NULL ;
}
static void F_30 ( struct V_59 * V_60 , struct V_61 * V_42 )
{
}
static int F_31 ( struct V_7 * V_8 ,
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
V_83 |= V_8 -> V_88 << V_89 ;
if ( V_8 -> V_90 == V_91 ) {
V_82 = F_32 ( V_8 -> V_92 , V_93 ) ;
if ( V_82 & V_94 )
V_83 |= 1 << V_95 ;
if ( V_82 & V_96 )
V_83 |= 1 << V_97 ;
}
break;
case V_98 :
break;
case V_99 :
V_17 = F_28 ( V_8 , V_28 -> V_100 ) ;
if ( ! V_17 )
return - V_101 ;
if ( V_17 -> V_20 & V_102 )
V_83 = 1 << V_103 ;
break;
default:
return - V_101 ;
}
V_84 = ( T_5 * ) V_8 -> V_104 ;
* V_84 = F_33 ( V_83 ) ;
V_17 = V_8 -> V_19 [ 0 ] ;
V_8 -> V_105 . V_17 = V_17 ;
V_8 -> V_105 . V_43 . V_69 = sizeof( * V_84 ) ;
V_8 -> V_105 . V_43 . V_106 = V_8 -> V_104 ;
V_8 -> V_105 . V_43 . V_107 = F_30 ;
return F_8 ( V_17 , & V_8 -> V_105 ) ;
}
static int F_34 ( struct V_7 * V_8 ,
struct V_80 * V_28 , int V_108 )
{
struct V_16 * V_17 ;
T_3 V_81 ;
T_3 V_109 ;
T_3 V_100 ;
T_3 V_82 ;
int V_18 ;
enum V_110 V_2 ;
V_109 = F_29 ( V_28 -> V_109 ) ;
V_100 = F_29 ( V_28 -> V_100 ) ;
V_81 = V_28 -> V_85 & V_86 ;
V_2 = V_8 -> V_56 . V_2 ;
switch ( V_81 ) {
case V_87 :
switch ( V_109 ) {
case V_111 :
break;
case V_112 :
if ( V_2 != V_57 )
return - V_101 ;
if ( V_8 -> V_90 != V_91 )
return - V_101 ;
V_82 = F_32 ( V_8 -> V_92 , V_93 ) ;
if ( V_108 )
V_82 |= V_94 ;
else
V_82 &= ~ V_94 ;
F_35 ( V_8 -> V_92 , V_93 , V_82 ) ;
break;
case V_113 :
if ( V_2 != V_57 )
return - V_101 ;
if ( V_8 -> V_90 != V_91 )
return - V_101 ;
V_82 = F_32 ( V_8 -> V_92 , V_93 ) ;
if ( V_108 )
V_82 |= V_96 ;
else
V_82 &= ~ V_96 ;
F_35 ( V_8 -> V_92 , V_93 , V_82 ) ;
break;
case V_114 :
return - V_101 ;
break;
case V_115 :
if ( ( V_100 & 0xff ) != 0 )
return - V_101 ;
if ( ! V_108 )
return - V_101 ;
V_8 -> V_116 = V_100 >> 8 ;
V_8 -> V_117 = true ;
break;
default:
return - V_101 ;
}
break;
case V_98 :
switch ( V_109 ) {
case V_118 :
if ( V_100 & V_119 )
;
if ( V_100 & V_120 )
;
break;
default:
return - V_101 ;
}
break;
case V_99 :
switch ( V_109 ) {
case V_103 :
V_17 = F_28 ( V_8 , V_100 ) ;
if ( ! V_17 )
return - V_101 ;
if ( V_108 == 0 && ( V_17 -> V_20 & V_121 ) )
break;
V_18 = F_21 ( V_17 , V_108 , true ) ;
if ( V_18 )
return - V_101 ;
break;
default:
return - V_101 ;
}
break;
default:
return - V_101 ;
}
return 0 ;
}
static int F_36 ( struct V_7 * V_8 , struct V_80 * V_28 )
{
enum V_110 V_2 = V_8 -> V_56 . V_2 ;
T_3 V_122 ;
T_3 V_82 ;
V_122 = F_29 ( V_28 -> V_109 ) ;
if ( V_122 > 127 ) {
F_3 ( V_22 , L_12 , V_122 ) ;
return - V_101 ;
}
if ( V_2 == V_57 ) {
F_3 ( V_22 ,
L_13 ) ;
return - V_101 ;
}
V_82 = F_32 ( V_8 -> V_92 , V_123 ) ;
V_82 &= ~ ( V_124 ) ;
V_82 |= F_37 ( V_122 ) ;
F_35 ( V_8 -> V_92 , V_123 , V_82 ) ;
if ( V_122 )
F_12 ( & V_8 -> V_56 , V_125 ) ;
else
F_12 ( & V_8 -> V_56 , V_126 ) ;
return 0 ;
}
static int F_38 ( struct V_7 * V_8 , struct V_80 * V_28 )
{
int V_18 ;
F_39 ( & V_8 -> V_63 ) ;
V_18 = V_8 -> V_127 -> V_128 ( & V_8 -> V_56 , V_28 ) ;
F_40 ( & V_8 -> V_63 ) ;
return V_18 ;
}
static int F_41 ( struct V_7 * V_8 , struct V_80 * V_28 )
{
enum V_110 V_2 = V_8 -> V_56 . V_2 ;
T_3 V_129 ;
int V_18 ;
T_3 V_82 ;
V_8 -> V_130 = false ;
V_129 = F_29 ( V_28 -> V_109 ) ;
switch ( V_2 ) {
case V_126 :
return - V_101 ;
break;
case V_125 :
V_18 = F_38 ( V_8 , V_28 ) ;
if ( V_129 && ( ! V_18 || ( V_18 == V_131 ) ) ) {
if ( V_18 == 0 )
F_12 ( & V_8 -> V_56 ,
V_57 ) ;
V_82 = F_32 ( V_8 -> V_92 , V_93 ) ;
V_82 |= ( V_132 | V_133 ) ;
F_35 ( V_8 -> V_92 , V_93 , V_82 ) ;
V_8 -> V_134 = true ;
F_3 ( V_22 , L_14 ) ;
}
break;
case V_57 :
V_18 = F_38 ( V_8 , V_28 ) ;
if ( ! V_129 && ! V_18 )
F_12 ( & V_8 -> V_56 ,
V_125 ) ;
break;
default:
V_18 = - V_101 ;
}
return V_18 ;
}
static void F_42 ( struct V_59 * V_60 , struct V_61 * V_42 )
{
struct V_16 * V_17 = F_16 ( V_60 ) ;
struct V_7 * V_8 = V_17 -> V_8 ;
T_3 V_135 = 0 ;
T_3 V_82 ;
struct V_136 {
T_1 V_137 ;
T_1 V_138 ;
T_6 V_139 ;
T_6 V_140 ;
} V_141 V_136 ;
int V_18 ;
memcpy ( & V_136 , V_42 -> V_106 , sizeof( V_136 ) ) ;
V_8 -> V_137 = V_136 . V_137 ;
V_8 -> V_138 = V_136 . V_138 ;
V_8 -> V_139 = F_29 ( V_136 . V_139 ) ;
V_8 -> V_140 = F_29 ( V_136 . V_140 ) ;
V_82 = F_32 ( V_8 -> V_92 , V_93 ) ;
if ( V_82 & V_96 )
V_135 = V_8 -> V_140 ;
if ( V_82 & V_94 )
V_135 = V_8 -> V_138 ;
if ( V_135 > 125 )
V_135 = 0 ;
V_18 = F_43 ( V_8 ,
V_142 , V_135 ) ;
F_27 ( V_18 < 0 ) ;
}
static int F_44 ( struct V_7 * V_8 , struct V_80 * V_28 )
{
struct V_16 * V_17 ;
enum V_110 V_2 = V_8 -> V_56 . V_2 ;
T_6 V_143 ;
T_6 V_109 ;
if ( V_2 == V_126 )
return - V_101 ;
V_109 = F_29 ( V_28 -> V_109 ) ;
V_143 = F_29 ( V_28 -> V_143 ) ;
if ( V_143 != 6 ) {
F_45 ( V_8 -> V_53 , L_15 ,
V_143 ) ;
return - V_101 ;
}
V_17 = V_8 -> V_19 [ 0 ] ;
V_8 -> V_105 . V_17 = V_17 ;
V_8 -> V_105 . V_43 . V_69 = V_17 -> V_64 . V_144 ;
V_8 -> V_105 . V_43 . V_106 = V_8 -> V_104 ;
V_8 -> V_105 . V_43 . V_107 = F_42 ;
return F_8 ( V_17 , & V_8 -> V_105 ) ;
}
static int F_46 ( struct V_7 * V_8 , struct V_80 * V_28 )
{
T_6 V_143 ;
T_6 V_109 ;
T_6 V_100 ;
V_109 = F_29 ( V_28 -> V_109 ) ;
V_143 = F_29 ( V_28 -> V_143 ) ;
V_100 = F_29 ( V_28 -> V_100 ) ;
if ( V_100 || V_143 )
return - V_101 ;
V_8 -> V_145 = V_109 ;
return 0 ;
}
static int F_47 ( struct V_7 * V_8 , struct V_80 * V_28 )
{
int V_18 ;
switch ( V_28 -> V_146 ) {
case V_147 :
F_3 ( V_22 , L_16 ) ;
V_18 = F_31 ( V_8 , V_28 ) ;
break;
case V_148 :
F_3 ( V_22 , L_17 ) ;
V_18 = F_34 ( V_8 , V_28 , 0 ) ;
break;
case V_149 :
F_3 ( V_22 , L_18 ) ;
V_18 = F_34 ( V_8 , V_28 , 1 ) ;
break;
case V_150 :
F_3 ( V_22 , L_19 ) ;
V_18 = F_36 ( V_8 , V_28 ) ;
break;
case V_151 :
F_3 ( V_22 , L_20 ) ;
V_18 = F_41 ( V_8 , V_28 ) ;
break;
case V_152 :
F_3 ( V_22 , L_21 ) ;
V_18 = F_44 ( V_8 , V_28 ) ;
break;
case V_153 :
F_3 ( V_22 , L_22 ) ;
V_18 = F_46 ( V_8 , V_28 ) ;
break;
default:
F_3 ( V_22 , L_23 ) ;
V_18 = F_38 ( V_8 , V_28 ) ;
break;
}
return V_18 ;
}
static void F_48 ( struct V_7 * V_8 ,
const struct V_154 * V_155 )
{
struct V_80 * V_28 = V_8 -> V_156 ;
int V_18 = - V_101 ;
T_3 V_11 ;
if ( ! V_8 -> V_127 )
goto V_67;
F_49 ( V_28 ) ;
V_11 = F_29 ( V_28 -> V_143 ) ;
if ( ! V_11 ) {
V_8 -> V_58 = false ;
V_8 -> V_55 = false ;
V_8 -> V_39 = V_157 ;
} else {
V_8 -> V_58 = true ;
V_8 -> V_55 = ! ! ( V_28 -> V_85 & V_79 ) ;
V_8 -> V_39 = V_158 ;
}
if ( ( V_28 -> V_85 & V_159 ) == V_160 )
V_18 = F_47 ( V_8 , V_28 ) ;
else
V_18 = F_38 ( V_8 , V_28 ) ;
if ( V_18 == V_131 )
V_8 -> V_54 = true ;
V_67:
if ( V_18 < 0 )
F_20 ( V_8 ) ;
}
static void F_50 ( struct V_7 * V_8 ,
const struct V_154 * V_155 )
{
struct V_41 * V_161 = NULL ;
struct V_61 * V_162 ;
struct V_14 * V_15 ;
struct V_16 * V_163 ;
T_3 V_164 ;
T_3 V_45 ;
T_3 V_69 ;
T_1 V_9 ;
V_9 = V_155 -> V_165 ;
V_163 = V_8 -> V_19 [ 0 ] ;
V_8 -> V_39 = V_157 ;
V_15 = V_8 -> V_24 ;
V_161 = F_22 ( & V_163 -> V_48 ) ;
if ( ! V_161 )
return;
V_45 = F_51 ( V_15 -> V_27 ) ;
if ( V_45 == V_166 ) {
F_3 ( V_22 , L_24 ) ;
if ( V_161 )
F_23 ( V_163 , V_161 , - V_71 ) ;
return;
}
V_162 = & V_161 -> V_43 ;
V_69 = V_15 -> V_27 & V_167 ;
if ( V_8 -> V_168 ) {
unsigned V_169 = V_162 -> V_69 ;
unsigned V_170 = V_163 -> V_64 . V_144 ;
V_169 += ( V_170 - ( V_169 % V_170 ) ) ;
V_164 = F_52 ( T_3 , V_162 -> V_69 ,
V_169 - V_69 ) ;
memcpy ( V_162 -> V_106 , V_8 -> V_171 , V_164 ) ;
} else {
V_164 = V_162 -> V_69 - V_69 ;
}
V_162 -> V_44 += V_164 ;
if ( ( V_9 & 1 ) && V_162 -> V_44 < V_162 -> V_69 ) {
F_20 ( V_8 ) ;
} else {
F_23 ( V_163 , V_161 , 0 ) ;
if ( F_53 ( V_162 -> V_69 , V_163 -> V_64 . V_144 ) &&
V_162 -> V_69 && V_162 -> V_172 ) {
int V_18 ;
V_8 -> V_39 = V_40 ;
V_18 = F_2 ( V_8 , V_9 ,
V_8 -> V_73 , 0 ,
V_173 ) ;
F_27 ( V_18 < 0 ) ;
}
}
}
static void F_54 ( struct V_7 * V_8 ,
const struct V_154 * V_155 )
{
struct V_41 * V_161 ;
struct V_16 * V_17 ;
struct V_14 * V_15 ;
T_3 V_45 ;
V_17 = V_8 -> V_19 [ 0 ] ;
V_15 = V_8 -> V_24 ;
if ( ! F_18 ( & V_17 -> V_48 ) ) {
V_161 = F_22 ( & V_17 -> V_48 ) ;
F_23 ( V_17 , V_161 , 0 ) ;
}
if ( V_8 -> V_117 ) {
int V_18 ;
V_18 = F_55 ( V_8 , V_8 -> V_116 ) ;
if ( V_18 < 0 ) {
F_3 ( V_22 , L_25 ,
V_8 -> V_116 ) ;
F_20 ( V_8 ) ;
return;
}
}
V_45 = F_51 ( V_15 -> V_27 ) ;
if ( V_45 == V_166 )
F_3 ( V_22 , L_26 ) ;
V_8 -> V_52 = V_4 ;
F_24 ( V_8 ) ;
}
static void F_56 ( struct V_7 * V_8 ,
const struct V_154 * V_155 )
{
struct V_16 * V_17 = V_8 -> V_19 [ V_155 -> V_165 ] ;
V_17 -> V_20 &= ~ V_21 ;
V_17 -> V_38 = 0 ;
V_8 -> V_174 = false ;
switch ( V_8 -> V_52 ) {
case V_4 :
F_3 ( V_22 , L_2 ) ;
F_48 ( V_8 , V_155 ) ;
break;
case V_5 :
F_3 ( V_22 , L_3 ) ;
F_50 ( V_8 , V_155 ) ;
break;
case V_6 :
F_3 ( V_22 , L_4 ) ;
F_54 ( V_8 , V_155 ) ;
break;
default:
F_57 ( true , L_27 , V_8 -> V_52 ) ;
}
}
static void F_11 ( struct V_7 * V_8 ,
struct V_16 * V_17 , struct V_41 * V_42 )
{
int V_18 ;
V_42 -> V_50 = ! ! V_17 -> V_36 ;
if ( V_42 -> V_43 . V_69 == 0 ) {
V_18 = F_2 ( V_8 , V_17 -> V_36 ,
V_8 -> V_73 , 0 ,
V_173 ) ;
} else if ( ! F_53 ( V_42 -> V_43 . V_69 , V_17 -> V_64 . V_144 )
&& ( V_17 -> V_36 == 0 ) ) {
T_3 V_169 ;
T_3 V_144 ;
V_18 = F_58 ( & V_8 -> V_56 , & V_42 -> V_43 ,
V_17 -> V_36 ) ;
if ( V_18 ) {
F_59 ( V_8 -> V_53 , L_28 ) ;
return;
}
F_27 ( V_42 -> V_43 . V_69 > V_175 ) ;
V_144 = V_17 -> V_64 . V_144 ;
V_169 = F_60 ( V_42 -> V_43 . V_69 , V_144 ) ;
V_8 -> V_168 = true ;
V_18 = F_2 ( V_8 , V_17 -> V_36 ,
V_8 -> V_176 , V_169 ,
V_173 ) ;
} else {
V_18 = F_58 ( & V_8 -> V_56 , & V_42 -> V_43 ,
V_17 -> V_36 ) ;
if ( V_18 ) {
F_59 ( V_8 -> V_53 , L_28 ) ;
return;
}
V_18 = F_2 ( V_8 , V_17 -> V_36 , V_42 -> V_43 . V_177 ,
V_42 -> V_43 . V_69 , V_173 ) ;
}
F_27 ( V_18 < 0 ) ;
}
static int F_61 ( struct V_16 * V_17 )
{
struct V_7 * V_8 = V_17 -> V_8 ;
T_3 type ;
type = V_8 -> V_58 ? V_178
: V_179 ;
return F_2 ( V_8 , V_17 -> V_36 ,
V_8 -> V_73 , 0 , type ) ;
}
static void F_13 ( struct V_7 * V_8 , struct V_16 * V_17 )
{
if ( V_8 -> V_134 ) {
F_3 ( V_22 , L_29 ) ;
F_62 ( V_8 ) ;
V_8 -> V_134 = 0 ;
}
F_27 ( F_61 ( V_17 ) ) ;
}
static void F_63 ( struct V_7 * V_8 ,
const struct V_154 * V_155 )
{
struct V_16 * V_17 = V_8 -> V_19 [ V_155 -> V_165 ] ;
F_13 ( V_8 , V_17 ) ;
}
static void F_64 ( struct V_7 * V_8 , struct V_16 * V_17 )
{
struct V_12 V_13 ;
T_3 V_180 ;
int V_18 ;
if ( ! V_17 -> V_38 )
return;
V_180 = V_181 ;
V_180 |= V_182 ;
V_180 |= F_65 ( V_17 -> V_38 ) ;
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
V_18 = F_6 ( V_8 , V_17 -> V_36 , V_180 , & V_13 ) ;
F_66 ( V_18 ) ;
V_17 -> V_38 = 0 ;
}
static void F_67 ( struct V_7 * V_8 ,
const struct V_154 * V_155 )
{
V_8 -> V_174 = true ;
switch ( V_155 -> V_45 ) {
case V_183 :
F_3 ( V_22 , L_30 ) ;
if ( V_8 -> V_55 != V_155 -> V_165 ) {
struct V_16 * V_17 = V_8 -> V_19 [ V_8 -> V_55 ] ;
F_3 ( V_22 ,
L_31 ) ;
F_64 ( V_8 , V_17 ) ;
F_20 ( V_8 ) ;
return;
}
break;
case V_184 :
if ( V_8 -> V_39 != V_157 )
return;
F_3 ( V_22 , L_32 ) ;
V_8 -> V_52 = V_6 ;
if ( V_8 -> V_54 ) {
F_66 ( V_155 -> V_165 != 1 ) ;
F_3 ( V_22 , L_33 ) ;
return;
}
F_63 ( V_8 , V_155 ) ;
}
}
void F_68 ( struct V_7 * V_8 ,
const struct V_154 * V_155 )
{
T_1 V_9 = V_155 -> V_165 ;
F_3 ( V_22 , L_34 ,
F_69 ( V_155 -> V_185 ) ,
V_9 >> 1 , ( V_9 & 1 ) ? L_35 : L_36 ,
F_1 ( V_8 -> V_52 ) ) ;
switch ( V_155 -> V_185 ) {
case V_186 :
F_56 ( V_8 , V_155 ) ;
break;
case V_187 :
F_67 ( V_8 , V_155 ) ;
break;
case V_188 :
case V_189 :
case V_190 :
case V_191 :
break;
}
}
