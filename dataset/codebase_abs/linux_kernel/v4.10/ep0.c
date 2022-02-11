static void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_3 V_5 , T_3 type , bool V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
V_10 = V_2 -> V_11 [ V_3 ] ;
V_8 = & V_2 -> V_12 [ V_10 -> V_13 ] ;
if ( V_6 )
V_10 -> V_13 ++ ;
V_8 -> V_14 = F_2 ( V_4 ) ;
V_8 -> V_15 = F_3 ( V_4 ) ;
V_8 -> V_16 = V_5 ;
V_8 -> V_17 = type ;
V_8 -> V_17 |= ( V_18
| V_19 ) ;
if ( V_6 )
V_8 -> V_17 |= V_20 ;
else
V_8 -> V_17 |= ( V_21
| V_22 ) ;
F_4 ( V_10 , V_8 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_23 V_24 ;
struct V_9 * V_10 ;
int V_25 ;
V_10 = V_2 -> V_11 [ V_3 ] ;
if ( V_10 -> V_26 & V_27 )
return 0 ;
memset ( & V_24 , 0 , sizeof( V_24 ) ) ;
V_24 . V_28 = F_3 ( V_2 -> V_29 ) ;
V_24 . V_30 = F_2 ( V_2 -> V_29 ) ;
V_25 = F_6 ( V_10 , V_31 , & V_24 ) ;
if ( V_25 < 0 )
return V_25 ;
V_10 -> V_26 |= V_27 ;
V_10 -> V_32 = F_7 ( V_10 ) ;
V_2 -> V_33 = V_34 ;
return 0 ;
}
static int F_8 ( struct V_9 * V_10 ,
struct V_35 * V_36 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
V_36 -> V_37 . V_38 = 0 ;
V_36 -> V_37 . V_39 = - V_40 ;
V_36 -> V_3 = V_10 -> V_41 ;
F_9 ( & V_36 -> V_42 , & V_10 -> V_43 ) ;
if ( V_10 -> V_26 & V_44 ) {
unsigned V_45 ;
V_45 = ! ! ( V_10 -> V_26 & V_46 ) ;
if ( V_2 -> V_47 != V_48 ) {
F_10 ( V_2 -> V_49 , L_1 ) ;
return 0 ;
}
F_11 ( V_2 , V_2 -> V_11 [ V_45 ] , V_36 ) ;
V_10 -> V_26 &= ~ ( V_44 |
V_46 ) ;
return 0 ;
}
if ( V_2 -> V_50 ) {
unsigned V_45 ;
V_45 = ! V_2 -> V_51 ;
V_2 -> V_50 = false ;
F_12 ( & V_2 -> V_52 , V_53 ) ;
if ( V_2 -> V_47 == V_54 )
F_13 ( V_2 , V_2 -> V_11 [ V_45 ] ) ;
return 0 ;
}
if ( V_2 -> V_55 ) {
unsigned V_45 ;
V_45 = V_2 -> V_51 ;
V_2 -> V_47 = V_48 ;
F_11 ( V_2 , V_2 -> V_11 [ V_45 ] , V_36 ) ;
V_10 -> V_26 &= ~ V_46 ;
}
return 0 ;
}
int F_14 ( struct V_56 * V_57 , struct V_58 * V_37 ,
T_4 V_59 )
{
struct V_35 * V_36 = F_15 ( V_37 ) ;
struct V_9 * V_10 = F_16 ( V_57 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned long V_26 ;
int V_25 ;
F_17 ( & V_2 -> V_60 , V_26 ) ;
if ( ! V_10 -> V_61 . V_62 ) {
F_18 ( V_2 -> V_49 , L_2 ,
V_10 -> V_63 ) ;
V_25 = - V_64 ;
goto V_65;
}
if ( ! F_19 ( & V_10 -> V_43 ) ) {
V_25 = - V_66 ;
goto V_65;
}
V_25 = F_8 ( V_10 , V_36 ) ;
V_65:
F_20 ( & V_2 -> V_60 , V_26 ) ;
return V_25 ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
V_10 = V_2 -> V_11 [ 1 ] ;
V_10 -> V_26 = V_67 ;
V_10 = V_2 -> V_11 [ 0 ] ;
F_22 ( V_10 , 1 , false ) ;
V_10 -> V_26 = V_67 ;
V_2 -> V_50 = false ;
if ( ! F_19 ( & V_10 -> V_43 ) ) {
struct V_35 * V_36 ;
V_36 = F_23 ( & V_10 -> V_43 ) ;
F_24 ( V_10 , V_36 , - V_68 ) ;
}
V_2 -> V_47 = V_69 ;
F_25 ( V_2 ) ;
}
int F_26 ( struct V_56 * V_57 , int V_70 )
{
struct V_9 * V_10 = F_16 ( V_57 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_21 ( V_2 ) ;
return 0 ;
}
int F_27 ( struct V_56 * V_57 , int V_70 )
{
struct V_9 * V_10 = F_16 ( V_57 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
unsigned long V_26 ;
int V_25 ;
F_17 ( & V_2 -> V_60 , V_26 ) ;
V_25 = F_26 ( V_57 , V_70 ) ;
F_20 ( & V_2 -> V_60 , V_26 ) ;
return V_25 ;
}
void F_25 ( struct V_1 * V_2 )
{
int V_25 ;
F_28 ( & V_2 -> V_71 ) ;
F_1 ( V_2 , 0 , V_2 -> V_72 , 8 ,
V_73 , false ) ;
V_25 = F_5 ( V_2 , 0 ) ;
F_29 ( V_25 < 0 ) ;
}
static struct V_9 * F_30 ( struct V_1 * V_2 , T_5 V_74 )
{
struct V_9 * V_10 ;
T_3 V_75 = F_31 ( V_74 ) ;
T_3 V_3 ;
V_3 = ( V_75 & V_76 ) << 1 ;
if ( ( V_75 & V_77 ) == V_78 )
V_3 |= 1 ;
V_10 = V_2 -> V_11 [ V_3 ] ;
if ( V_10 -> V_26 & V_67 )
return V_10 ;
return NULL ;
}
static void F_32 ( struct V_56 * V_57 , struct V_58 * V_36 )
{
}
static int F_33 ( struct V_1 * V_2 ,
struct V_79 * V_17 )
{
struct V_9 * V_10 ;
T_3 V_80 ;
T_3 V_81 ;
T_6 V_82 = 0 ;
T_5 * V_83 ;
V_80 = V_17 -> V_84 & V_85 ;
switch ( V_80 ) {
case V_86 :
V_82 |= V_2 -> V_52 . V_87 ;
if ( ( V_2 -> V_88 == V_89 ) ||
( V_2 -> V_88 == V_90 ) ) {
V_81 = F_34 ( V_2 -> V_91 , V_92 ) ;
if ( V_81 & V_93 )
V_82 |= 1 << V_94 ;
if ( V_81 & V_95 )
V_82 |= 1 << V_96 ;
}
break;
case V_97 :
break;
case V_98 :
V_10 = F_30 ( V_2 , V_17 -> V_99 ) ;
if ( ! V_10 )
return - V_100 ;
if ( V_10 -> V_26 & V_101 )
V_82 = 1 << V_102 ;
break;
default:
return - V_100 ;
}
V_83 = ( T_5 * ) V_2 -> V_103 ;
* V_83 = F_35 ( V_82 ) ;
V_10 = V_2 -> V_11 [ 0 ] ;
V_2 -> V_104 . V_10 = V_10 ;
V_2 -> V_104 . V_37 . V_105 = sizeof( * V_83 ) ;
V_2 -> V_104 . V_37 . V_106 = V_2 -> V_103 ;
V_2 -> V_104 . V_37 . F_28 = F_32 ;
return F_8 ( V_10 , & V_2 -> V_104 ) ;
}
static int F_36 ( struct V_1 * V_2 , enum V_107 V_108 ,
int V_109 )
{
T_3 V_81 ;
if ( V_108 != V_53 )
return - V_100 ;
if ( ( V_2 -> V_88 != V_89 ) &&
( V_2 -> V_88 != V_90 ) )
return - V_100 ;
V_81 = F_34 ( V_2 -> V_91 , V_92 ) ;
if ( V_109 )
V_81 |= V_93 ;
else
V_81 &= ~ V_93 ;
F_37 ( V_2 -> V_91 , V_92 , V_81 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , enum V_107 V_108 ,
int V_109 )
{
T_3 V_81 ;
if ( V_108 != V_53 )
return - V_100 ;
if ( ( V_2 -> V_88 != V_89 ) &&
( V_2 -> V_88 != V_90 ) )
return - V_100 ;
V_81 = F_34 ( V_2 -> V_91 , V_92 ) ;
if ( V_109 )
V_81 |= V_95 ;
else
V_81 &= ~ V_95 ;
F_37 ( V_2 -> V_91 , V_92 , V_81 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , enum V_107 V_108 ,
T_3 V_99 , int V_109 )
{
if ( ( V_99 & 0xff ) != 0 )
return - V_100 ;
if ( ! V_109 )
return - V_100 ;
switch ( V_99 >> 8 ) {
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
V_2 -> V_115 = V_99 >> 8 ;
V_2 -> V_116 = true ;
break;
default:
return - V_100 ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_79 * V_17 , int V_109 )
{
enum V_107 V_108 ;
T_3 V_117 ;
T_3 V_99 ;
int V_25 = 0 ;
V_117 = F_31 ( V_17 -> V_117 ) ;
V_99 = F_31 ( V_17 -> V_99 ) ;
V_108 = V_2 -> V_52 . V_108 ;
switch ( V_117 ) {
case V_118 :
break;
case V_119 :
V_25 = F_36 ( V_2 , V_108 , V_109 ) ;
break;
case V_120 :
V_25 = F_38 ( V_2 , V_108 , V_109 ) ;
break;
case V_121 :
V_25 = - V_100 ;
break;
case V_122 :
V_25 = F_39 ( V_2 , V_108 , V_99 , V_109 ) ;
break;
default:
V_25 = - V_100 ;
}
return V_25 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_79 * V_17 , int V_109 )
{
enum V_107 V_108 ;
T_3 V_117 ;
T_3 V_99 ;
int V_25 = 0 ;
V_117 = F_31 ( V_17 -> V_117 ) ;
V_99 = F_31 ( V_17 -> V_99 ) ;
V_108 = V_2 -> V_52 . V_108 ;
switch ( V_117 ) {
case V_123 :
break;
default:
V_25 = - V_100 ;
}
return V_25 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_79 * V_17 , int V_109 )
{
struct V_9 * V_10 ;
enum V_107 V_108 ;
T_3 V_117 ;
T_3 V_99 ;
int V_25 ;
V_117 = F_31 ( V_17 -> V_117 ) ;
V_99 = F_31 ( V_17 -> V_99 ) ;
V_108 = V_2 -> V_52 . V_108 ;
switch ( V_117 ) {
case V_102 :
V_10 = F_30 ( V_2 , V_17 -> V_99 ) ;
if ( ! V_10 )
return - V_100 ;
if ( V_109 == 0 && ( V_10 -> V_26 & V_124 ) )
break;
V_25 = F_22 ( V_10 , V_109 , true ) ;
if ( V_25 )
return - V_100 ;
break;
default:
return - V_100 ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_79 * V_17 , int V_109 )
{
T_3 V_80 ;
int V_25 ;
enum V_107 V_108 ;
V_80 = V_17 -> V_84 & V_85 ;
V_108 = V_2 -> V_52 . V_108 ;
switch ( V_80 ) {
case V_86 :
V_25 = F_40 ( V_2 , V_17 , V_109 ) ;
break;
case V_97 :
V_25 = F_41 ( V_2 , V_17 , V_109 ) ;
break;
case V_98 :
V_25 = F_42 ( V_2 , V_17 , V_109 ) ;
break;
default:
V_25 = - V_100 ;
}
return V_25 ;
}
static int F_44 ( struct V_1 * V_2 , struct V_79 * V_17 )
{
enum V_107 V_108 = V_2 -> V_52 . V_108 ;
T_3 V_125 ;
T_3 V_81 ;
V_125 = F_31 ( V_17 -> V_117 ) ;
if ( V_125 > 127 ) {
F_18 ( V_2 -> V_49 , L_3 , V_125 ) ;
return - V_100 ;
}
if ( V_108 == V_53 ) {
F_18 ( V_2 -> V_49 , L_4 ) ;
return - V_100 ;
}
V_81 = F_34 ( V_2 -> V_91 , V_126 ) ;
V_81 &= ~ ( V_127 ) ;
V_81 |= F_45 ( V_125 ) ;
F_37 ( V_2 -> V_91 , V_126 , V_81 ) ;
if ( V_125 )
F_12 ( & V_2 -> V_52 , V_128 ) ;
else
F_12 ( & V_2 -> V_52 , V_129 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 , struct V_79 * V_17 )
{
int V_25 ;
F_47 ( & V_2 -> V_60 ) ;
V_25 = V_2 -> V_130 -> V_131 ( & V_2 -> V_52 , V_17 ) ;
F_48 ( & V_2 -> V_60 ) ;
return V_25 ;
}
static int F_49 ( struct V_1 * V_2 , struct V_79 * V_17 )
{
enum V_107 V_108 = V_2 -> V_52 . V_108 ;
T_3 V_132 ;
int V_25 ;
T_3 V_81 ;
V_132 = F_31 ( V_17 -> V_117 ) ;
switch ( V_108 ) {
case V_129 :
return - V_100 ;
case V_128 :
V_25 = F_46 ( V_2 , V_17 ) ;
if ( V_132 && ( ! V_25 || ( V_25 == V_133 ) ) ) {
if ( V_25 == 0 )
F_12 ( & V_2 -> V_52 ,
V_53 ) ;
V_81 = F_34 ( V_2 -> V_91 , V_92 ) ;
V_81 |= ( V_134 | V_135 ) ;
F_37 ( V_2 -> V_91 , V_92 , V_81 ) ;
}
break;
case V_53 :
V_25 = F_46 ( V_2 , V_17 ) ;
if ( ! V_132 && ! V_25 )
F_12 ( & V_2 -> V_52 ,
V_128 ) ;
break;
default:
V_25 = - V_100 ;
}
return V_25 ;
}
static void F_50 ( struct V_56 * V_57 , struct V_58 * V_36 )
{
struct V_9 * V_10 = F_16 ( V_57 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
T_3 V_136 = 0 ;
T_3 V_81 ;
struct V_137 {
T_1 V_138 ;
T_1 V_139 ;
T_5 V_140 ;
T_5 V_141 ;
} V_142 V_137 ;
int V_25 ;
memcpy ( & V_137 , V_36 -> V_106 , sizeof( V_137 ) ) ;
V_2 -> V_138 = V_137 . V_138 ;
V_2 -> V_139 = V_137 . V_139 ;
V_2 -> V_140 = F_31 ( V_137 . V_140 ) ;
V_2 -> V_141 = F_31 ( V_137 . V_141 ) ;
V_81 = F_34 ( V_2 -> V_91 , V_92 ) ;
if ( V_81 & V_95 )
V_136 = V_2 -> V_141 ;
if ( V_81 & V_93 )
V_136 = V_2 -> V_139 ;
if ( V_136 > 125 )
V_136 = 0 ;
V_25 = F_51 ( V_2 ,
V_143 , V_136 ) ;
F_29 ( V_25 < 0 ) ;
}
static int F_52 ( struct V_1 * V_2 , struct V_79 * V_17 )
{
struct V_9 * V_10 ;
enum V_107 V_108 = V_2 -> V_52 . V_108 ;
T_6 V_144 ;
T_6 V_117 ;
if ( V_108 == V_129 )
return - V_100 ;
V_117 = F_31 ( V_17 -> V_117 ) ;
V_144 = F_31 ( V_17 -> V_144 ) ;
if ( V_144 != 6 ) {
F_18 ( V_2 -> V_49 , L_5 ,
V_144 ) ;
return - V_100 ;
}
V_10 = V_2 -> V_11 [ 0 ] ;
V_2 -> V_104 . V_10 = V_10 ;
V_2 -> V_104 . V_37 . V_105 = V_10 -> V_61 . V_145 ;
V_2 -> V_104 . V_37 . V_106 = V_2 -> V_103 ;
V_2 -> V_104 . V_37 . F_28 = F_50 ;
return F_8 ( V_10 , & V_2 -> V_104 ) ;
}
static int F_53 ( struct V_1 * V_2 , struct V_79 * V_17 )
{
T_6 V_144 ;
T_6 V_117 ;
T_6 V_99 ;
V_117 = F_31 ( V_17 -> V_117 ) ;
V_144 = F_31 ( V_17 -> V_144 ) ;
V_99 = F_31 ( V_17 -> V_99 ) ;
if ( V_99 || V_144 )
return - V_100 ;
V_2 -> V_146 = V_117 ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 , struct V_79 * V_17 )
{
int V_25 ;
switch ( V_17 -> V_147 ) {
case V_148 :
V_25 = F_33 ( V_2 , V_17 ) ;
break;
case V_149 :
V_25 = F_43 ( V_2 , V_17 , 0 ) ;
break;
case V_150 :
V_25 = F_43 ( V_2 , V_17 , 1 ) ;
break;
case V_151 :
V_25 = F_44 ( V_2 , V_17 ) ;
break;
case V_152 :
V_25 = F_49 ( V_2 , V_17 ) ;
break;
case V_153 :
V_25 = F_52 ( V_2 , V_17 ) ;
break;
case V_154 :
V_25 = F_53 ( V_2 , V_17 ) ;
break;
default:
V_25 = F_46 ( V_2 , V_17 ) ;
break;
}
return V_25 ;
}
static void F_55 ( struct V_1 * V_2 ,
const struct V_155 * V_156 )
{
struct V_79 * V_17 = V_2 -> V_157 ;
int V_25 = - V_100 ;
T_3 V_5 ;
if ( ! V_2 -> V_130 )
goto V_65;
F_56 ( V_17 ) ;
V_5 = F_31 ( V_17 -> V_144 ) ;
if ( ! V_5 ) {
V_2 -> V_55 = false ;
V_2 -> V_51 = false ;
V_2 -> V_33 = V_158 ;
} else {
V_2 -> V_55 = true ;
V_2 -> V_51 = ! ! ( V_17 -> V_84 & V_78 ) ;
V_2 -> V_33 = V_159 ;
}
if ( ( V_17 -> V_84 & V_160 ) == V_161 )
V_25 = F_54 ( V_2 , V_17 ) ;
else
V_25 = F_46 ( V_2 , V_17 ) ;
if ( V_25 == V_133 )
V_2 -> V_50 = true ;
V_65:
if ( V_25 < 0 )
F_21 ( V_2 ) ;
}
static void F_57 ( struct V_1 * V_2 ,
const struct V_155 * V_156 )
{
struct V_35 * V_162 = NULL ;
struct V_58 * V_163 ;
struct V_7 * V_8 ;
struct V_9 * V_164 ;
unsigned V_165 = 0 ;
unsigned V_166 ;
unsigned V_167 ;
void * V_106 ;
T_3 V_168 = 0 ;
T_3 V_39 ;
T_3 V_105 ;
T_1 V_3 ;
V_3 = V_156 -> V_169 ;
V_164 = V_2 -> V_11 [ 0 ] ;
V_2 -> V_33 = V_158 ;
V_8 = V_2 -> V_12 ;
F_58 ( V_164 , V_8 ) ;
V_162 = F_23 ( & V_164 -> V_43 ) ;
if ( ! V_162 )
return;
V_39 = F_59 ( V_8 -> V_16 ) ;
if ( V_39 == V_170 ) {
V_2 -> V_171 = true ;
if ( V_162 )
F_24 ( V_164 , V_162 , - V_68 ) ;
return;
}
V_163 = & V_162 -> V_37 ;
V_106 = V_163 -> V_106 ;
V_167 = V_163 -> V_105 ;
V_105 = V_8 -> V_16 & V_172 ;
V_166 = V_164 -> V_61 . V_145 ;
if ( V_2 -> V_173 ) {
if ( V_163 -> V_105 > V_174 ) {
V_165 = F_60 ( V_163 -> V_105 - V_166 , V_166 ) ;
V_168 = V_165 - V_105 ;
V_106 = ( T_1 * ) V_106 + V_168 ;
V_163 -> V_38 += V_168 ;
V_167 -= V_168 ;
V_8 ++ ;
V_105 = V_8 -> V_16 & V_172 ;
V_164 -> V_13 = 0 ;
}
V_165 = F_61 ( ( V_163 -> V_105 - V_165 ) ,
V_166 ) ;
V_168 = F_62 ( T_3 , V_167 ,
V_165 - V_105 ) ;
memcpy ( V_106 , V_2 -> V_175 , V_168 ) ;
} else {
V_168 = V_163 -> V_105 - V_105 ;
}
V_163 -> V_38 += V_168 ;
if ( ( V_3 & 1 ) && V_163 -> V_38 < V_163 -> V_105 ) {
F_21 ( V_2 ) ;
} else {
F_24 ( V_164 , V_162 , 0 ) ;
if ( F_63 ( V_163 -> V_105 , V_164 -> V_61 . V_145 ) &&
V_163 -> V_105 && V_163 -> V_176 ) {
int V_25 ;
V_2 -> V_33 = V_34 ;
F_1 ( V_2 , V_3 , V_2 -> V_72 ,
0 , V_177 , false ) ;
V_25 = F_5 ( V_2 , V_3 ) ;
F_29 ( V_25 < 0 ) ;
}
}
}
static void F_64 ( struct V_1 * V_2 ,
const struct V_155 * V_156 )
{
struct V_35 * V_162 ;
struct V_9 * V_10 ;
struct V_7 * V_8 ;
T_3 V_39 ;
V_10 = V_2 -> V_11 [ 0 ] ;
V_8 = V_2 -> V_12 ;
F_58 ( V_10 , V_8 ) ;
if ( ! F_19 ( & V_10 -> V_43 ) ) {
V_162 = F_23 ( & V_10 -> V_43 ) ;
F_24 ( V_10 , V_162 , 0 ) ;
}
if ( V_2 -> V_116 ) {
int V_25 ;
V_25 = F_65 ( V_2 , V_2 -> V_115 ) ;
if ( V_25 < 0 ) {
F_18 ( V_2 -> V_49 , L_6 ,
V_2 -> V_115 ) ;
F_21 ( V_2 ) ;
return;
}
}
V_39 = F_59 ( V_8 -> V_16 ) ;
if ( V_39 == V_170 )
V_2 -> V_171 = true ;
V_2 -> V_47 = V_69 ;
F_25 ( V_2 ) ;
}
static void F_66 ( struct V_1 * V_2 ,
const struct V_155 * V_156 )
{
struct V_9 * V_10 = V_2 -> V_11 [ V_156 -> V_169 ] ;
V_10 -> V_26 &= ~ V_27 ;
V_10 -> V_32 = 0 ;
V_2 -> V_171 = false ;
switch ( V_2 -> V_47 ) {
case V_69 :
F_55 ( V_2 , V_156 ) ;
break;
case V_48 :
F_57 ( V_2 , V_156 ) ;
break;
case V_54 :
F_64 ( V_2 , V_156 ) ;
break;
default:
F_67 ( true , L_7 , V_2 -> V_47 ) ;
}
}
static void F_11 ( struct V_1 * V_2 ,
struct V_9 * V_10 , struct V_35 * V_36 )
{
int V_25 ;
V_36 -> V_45 = ! ! V_10 -> V_41 ;
if ( V_36 -> V_37 . V_105 == 0 ) {
F_1 ( V_2 , V_10 -> V_41 ,
V_2 -> V_72 , 0 ,
V_177 , false ) ;
V_25 = F_5 ( V_2 , V_10 -> V_41 ) ;
} else if ( ! F_63 ( V_36 -> V_37 . V_105 , V_10 -> V_61 . V_145 )
&& ( V_10 -> V_41 == 0 ) ) {
T_3 V_165 = 0 ;
T_3 V_145 ;
V_25 = F_68 ( V_2 -> V_178 ,
& V_36 -> V_37 , V_10 -> V_41 ) ;
if ( V_25 )
return;
V_145 = V_10 -> V_61 . V_145 ;
if ( V_36 -> V_37 . V_105 > V_174 ) {
V_165 = F_60 ( V_36 -> V_37 . V_105 - V_145 ,
V_145 ) ;
F_1 ( V_2 , V_10 -> V_41 ,
V_36 -> V_37 . V_179 ,
V_165 ,
V_177 ,
true ) ;
}
V_165 = F_61 ( ( V_36 -> V_37 . V_105 - V_165 ) ,
V_145 ) ;
V_2 -> V_173 = true ;
F_1 ( V_2 , V_10 -> V_41 ,
V_2 -> V_180 , V_165 ,
V_177 , false ) ;
V_25 = F_5 ( V_2 , V_10 -> V_41 ) ;
} else {
V_25 = F_68 ( V_2 -> V_178 ,
& V_36 -> V_37 , V_10 -> V_41 ) ;
if ( V_25 )
return;
F_1 ( V_2 , V_10 -> V_41 , V_36 -> V_37 . V_179 ,
V_36 -> V_37 . V_105 , V_177 ,
false ) ;
V_25 = F_5 ( V_2 , V_10 -> V_41 ) ;
}
F_29 ( V_25 < 0 ) ;
}
static int F_69 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_3 type ;
type = V_2 -> V_55 ? V_181
: V_182 ;
F_1 ( V_2 , V_10 -> V_41 ,
V_2 -> V_72 , 0 , type , false ) ;
return F_5 ( V_2 , V_10 -> V_41 ) ;
}
static void F_13 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
F_29 ( F_69 ( V_10 ) ) ;
}
static void F_70 ( struct V_1 * V_2 ,
const struct V_155 * V_156 )
{
struct V_9 * V_10 = V_2 -> V_11 [ V_156 -> V_169 ] ;
F_13 ( V_2 , V_10 ) ;
}
static void F_71 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_23 V_24 ;
T_3 V_183 ;
int V_25 ;
if ( ! V_10 -> V_32 )
return;
V_183 = V_184 ;
V_183 |= V_185 ;
V_183 |= F_72 ( V_10 -> V_32 ) ;
memset ( & V_24 , 0 , sizeof( V_24 ) ) ;
V_25 = F_6 ( V_10 , V_183 , & V_24 ) ;
F_73 ( V_25 ) ;
V_10 -> V_32 = 0 ;
}
static void F_74 ( struct V_1 * V_2 ,
const struct V_155 * V_156 )
{
switch ( V_156 -> V_39 ) {
case V_186 :
if ( V_2 -> V_51 != V_156 -> V_169 ) {
struct V_9 * V_10 = V_2 -> V_11 [ V_2 -> V_51 ] ;
F_18 ( V_2 -> V_49 , L_8 ) ;
F_71 ( V_2 , V_10 ) ;
F_21 ( V_2 ) ;
return;
}
break;
case V_187 :
if ( V_2 -> V_33 != V_158 )
return;
V_2 -> V_47 = V_54 ;
if ( V_2 -> V_50 ) {
F_73 ( V_156 -> V_169 != 1 ) ;
return;
}
F_70 ( V_2 , V_156 ) ;
}
}
void F_75 ( struct V_1 * V_2 ,
const struct V_155 * V_156 )
{
switch ( V_156 -> V_188 ) {
case V_189 :
F_66 ( V_2 , V_156 ) ;
break;
case V_190 :
F_74 ( V_2 , V_156 ) ;
break;
case V_191 :
case V_192 :
case V_193 :
case V_194 :
break;
}
}
