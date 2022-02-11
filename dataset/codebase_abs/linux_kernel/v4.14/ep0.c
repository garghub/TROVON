static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 , T_2 type , bool V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
V_9 = V_2 -> V_9 ;
V_7 = & V_9 -> V_10 [ V_2 -> V_11 ] ;
if ( V_5 )
V_2 -> V_11 ++ ;
V_7 -> V_12 = F_2 ( V_3 ) ;
V_7 -> V_13 = F_3 ( V_3 ) ;
V_7 -> V_14 = V_4 ;
V_7 -> V_15 = type ;
V_7 -> V_15 |= ( V_16
| V_17 ) ;
if ( V_5 )
V_7 -> V_15 |= V_18 ;
else
V_7 -> V_15 |= ( V_19
| V_20 ) ;
F_4 ( V_2 , V_7 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_21 V_22 ;
struct V_8 * V_9 ;
int V_23 ;
if ( V_2 -> V_24 & V_25 )
return 0 ;
V_9 = V_2 -> V_9 ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
V_22 . V_26 = F_3 ( V_9 -> V_27 ) ;
V_22 . V_28 = F_2 ( V_9 -> V_27 ) ;
V_23 = F_6 ( V_2 , V_29 , & V_22 ) ;
if ( V_23 < 0 )
return V_23 ;
V_2 -> V_24 |= V_25 ;
V_2 -> V_30 = F_7 ( V_2 ) ;
V_9 -> V_31 = V_32 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
V_34 -> V_35 . V_36 = 0 ;
V_34 -> V_35 . V_37 = - V_38 ;
V_34 -> V_39 = V_2 -> V_40 ;
F_9 ( & V_34 -> V_41 , & V_2 -> V_42 ) ;
if ( V_2 -> V_24 & V_43 ) {
unsigned V_44 ;
V_44 = ! ! ( V_2 -> V_24 & V_45 ) ;
if ( V_9 -> V_46 != V_47 ) {
F_10 ( V_9 -> V_48 , L_1 ) ;
return 0 ;
}
F_11 ( V_9 , V_9 -> V_49 [ V_44 ] , V_34 ) ;
V_2 -> V_24 &= ~ ( V_43 |
V_45 ) ;
return 0 ;
}
if ( V_9 -> V_50 ) {
unsigned V_44 ;
V_44 = ! V_9 -> V_51 ;
V_9 -> V_50 = false ;
F_12 ( & V_9 -> V_52 , V_53 ) ;
if ( V_9 -> V_46 == V_54 )
F_13 ( V_9 , V_9 -> V_49 [ V_44 ] ) ;
return 0 ;
}
if ( V_9 -> V_55 ) {
unsigned V_44 ;
V_44 = V_9 -> V_51 ;
V_9 -> V_46 = V_47 ;
F_11 ( V_9 , V_9 -> V_49 [ V_44 ] , V_34 ) ;
V_2 -> V_24 &= ~ V_45 ;
}
return 0 ;
}
int F_14 ( struct V_56 * V_57 , struct V_58 * V_35 ,
T_3 V_59 )
{
struct V_33 * V_34 = F_15 ( V_35 ) ;
struct V_1 * V_2 = F_16 ( V_57 ) ;
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned long V_24 ;
int V_23 ;
F_17 ( & V_9 -> V_60 , V_24 ) ;
if ( ! V_2 -> V_61 . V_62 ) {
F_18 ( V_9 -> V_48 , L_2 ,
V_2 -> V_63 ) ;
V_23 = - V_64 ;
goto V_65;
}
if ( ! F_19 ( & V_2 -> V_42 ) ) {
V_23 = - V_66 ;
goto V_65;
}
V_23 = F_8 ( V_2 , V_34 ) ;
V_65:
F_20 ( & V_9 -> V_60 , V_24 ) ;
return V_23 ;
}
static void F_21 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
V_2 = V_9 -> V_49 [ 1 ] ;
V_2 -> V_24 = V_67 ;
V_2 = V_9 -> V_49 [ 0 ] ;
F_22 ( V_2 , 1 , false ) ;
V_2 -> V_24 = V_67 ;
V_9 -> V_50 = false ;
if ( ! F_19 ( & V_2 -> V_42 ) ) {
struct V_33 * V_34 ;
V_34 = F_23 ( & V_2 -> V_42 ) ;
F_24 ( V_2 , V_34 , - V_68 ) ;
}
V_9 -> V_46 = V_69 ;
F_25 ( V_9 ) ;
}
int F_26 ( struct V_56 * V_57 , int V_70 )
{
struct V_1 * V_2 = F_16 ( V_57 ) ;
struct V_8 * V_9 = V_2 -> V_9 ;
F_21 ( V_9 ) ;
return 0 ;
}
int F_27 ( struct V_56 * V_57 , int V_70 )
{
struct V_1 * V_2 = F_16 ( V_57 ) ;
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned long V_24 ;
int V_23 ;
F_17 ( & V_9 -> V_60 , V_24 ) ;
V_23 = F_26 ( V_57 , V_70 ) ;
F_20 ( & V_9 -> V_60 , V_24 ) ;
return V_23 ;
}
void F_25 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
int V_23 ;
F_28 ( & V_9 -> V_71 ) ;
V_2 = V_9 -> V_49 [ 0 ] ;
F_1 ( V_2 , V_9 -> V_27 , 8 ,
V_72 , false ) ;
V_23 = F_5 ( V_2 ) ;
F_29 ( V_23 < 0 ) ;
}
static struct V_1 * F_30 ( struct V_8 * V_9 , T_4 V_73 )
{
struct V_1 * V_2 ;
T_2 V_74 = F_31 ( V_73 ) ;
T_2 V_39 ;
V_39 = ( V_74 & V_75 ) << 1 ;
if ( ( V_74 & V_76 ) == V_77 )
V_39 |= 1 ;
V_2 = V_9 -> V_49 [ V_39 ] ;
if ( V_2 -> V_24 & V_67 )
return V_2 ;
return NULL ;
}
static void F_32 ( struct V_56 * V_57 , struct V_58 * V_34 )
{
}
static int F_33 ( struct V_8 * V_9 ,
struct V_78 * V_15 )
{
struct V_1 * V_2 ;
T_2 V_79 ;
T_2 V_70 ;
T_2 V_80 ;
T_5 V_81 = 0 ;
T_4 * V_82 ;
V_70 = F_31 ( V_15 -> V_83 ) ;
if ( V_70 != 0 )
return - V_84 ;
V_79 = V_15 -> V_85 & V_86 ;
switch ( V_79 ) {
case V_87 :
V_81 |= V_9 -> V_52 . V_88 ;
if ( ( V_9 -> V_89 == V_90 ) ||
( V_9 -> V_89 == V_91 ) ) {
V_80 = F_34 ( V_9 -> V_92 , V_93 ) ;
if ( V_80 & V_94 )
V_81 |= 1 << V_95 ;
if ( V_80 & V_96 )
V_81 |= 1 << V_97 ;
}
break;
case V_98 :
break;
case V_99 :
V_2 = F_30 ( V_9 , V_15 -> V_100 ) ;
if ( ! V_2 )
return - V_84 ;
if ( V_2 -> V_24 & V_101 )
V_81 = 1 << V_102 ;
break;
default:
return - V_84 ;
}
V_82 = ( T_4 * ) V_9 -> V_103 ;
* V_82 = F_35 ( V_81 ) ;
V_2 = V_9 -> V_49 [ 0 ] ;
V_9 -> V_104 . V_2 = V_2 ;
V_9 -> V_104 . V_35 . V_105 = sizeof( * V_82 ) ;
V_9 -> V_104 . V_35 . V_106 = V_9 -> V_103 ;
V_9 -> V_104 . V_35 . F_28 = F_32 ;
return F_8 ( V_2 , & V_9 -> V_104 ) ;
}
static int F_36 ( struct V_8 * V_9 , enum V_107 V_108 ,
int V_109 )
{
T_2 V_80 ;
if ( V_108 != V_53 )
return - V_84 ;
if ( ( V_9 -> V_89 != V_90 ) &&
( V_9 -> V_89 != V_91 ) )
return - V_84 ;
V_80 = F_34 ( V_9 -> V_92 , V_93 ) ;
if ( V_109 )
V_80 |= V_94 ;
else
V_80 &= ~ V_94 ;
F_37 ( V_9 -> V_92 , V_93 , V_80 ) ;
return 0 ;
}
static int F_38 ( struct V_8 * V_9 , enum V_107 V_108 ,
int V_109 )
{
T_2 V_80 ;
if ( V_108 != V_53 )
return - V_84 ;
if ( ( V_9 -> V_89 != V_90 ) &&
( V_9 -> V_89 != V_91 ) )
return - V_84 ;
V_80 = F_34 ( V_9 -> V_92 , V_93 ) ;
if ( V_109 )
V_80 |= V_96 ;
else
V_80 &= ~ V_96 ;
F_37 ( V_9 -> V_92 , V_93 , V_80 ) ;
return 0 ;
}
static int F_39 ( struct V_8 * V_9 , enum V_107 V_108 ,
T_2 V_100 , int V_109 )
{
if ( ( V_100 & 0xff ) != 0 )
return - V_84 ;
if ( ! V_109 )
return - V_84 ;
switch ( V_100 >> 8 ) {
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
V_9 -> V_115 = V_100 >> 8 ;
V_9 -> V_116 = true ;
break;
default:
return - V_84 ;
}
return 0 ;
}
static int F_40 ( struct V_8 * V_9 ,
struct V_78 * V_15 , int V_109 )
{
enum V_107 V_108 ;
T_2 V_83 ;
T_2 V_100 ;
int V_23 = 0 ;
V_83 = F_31 ( V_15 -> V_83 ) ;
V_100 = F_31 ( V_15 -> V_100 ) ;
V_108 = V_9 -> V_52 . V_108 ;
switch ( V_83 ) {
case V_117 :
break;
case V_118 :
V_23 = F_36 ( V_9 , V_108 , V_109 ) ;
break;
case V_119 :
V_23 = F_38 ( V_9 , V_108 , V_109 ) ;
break;
case V_120 :
V_23 = - V_84 ;
break;
case V_121 :
V_23 = F_39 ( V_9 , V_108 , V_100 , V_109 ) ;
break;
default:
V_23 = - V_84 ;
}
return V_23 ;
}
static int F_41 ( struct V_8 * V_9 ,
struct V_78 * V_15 , int V_109 )
{
enum V_107 V_108 ;
T_2 V_83 ;
T_2 V_100 ;
int V_23 = 0 ;
V_83 = F_31 ( V_15 -> V_83 ) ;
V_100 = F_31 ( V_15 -> V_100 ) ;
V_108 = V_9 -> V_52 . V_108 ;
switch ( V_83 ) {
case V_122 :
break;
default:
V_23 = - V_84 ;
}
return V_23 ;
}
static int F_42 ( struct V_8 * V_9 ,
struct V_78 * V_15 , int V_109 )
{
struct V_1 * V_2 ;
enum V_107 V_108 ;
T_2 V_83 ;
T_2 V_100 ;
int V_23 ;
V_83 = F_31 ( V_15 -> V_83 ) ;
V_100 = F_31 ( V_15 -> V_100 ) ;
V_108 = V_9 -> V_52 . V_108 ;
switch ( V_83 ) {
case V_102 :
V_2 = F_30 ( V_9 , V_15 -> V_100 ) ;
if ( ! V_2 )
return - V_84 ;
if ( V_109 == 0 && ( V_2 -> V_24 & V_123 ) )
break;
V_23 = F_22 ( V_2 , V_109 , true ) ;
if ( V_23 )
return - V_84 ;
break;
default:
return - V_84 ;
}
return 0 ;
}
static int F_43 ( struct V_8 * V_9 ,
struct V_78 * V_15 , int V_109 )
{
T_2 V_79 ;
int V_23 ;
enum V_107 V_108 ;
V_79 = V_15 -> V_85 & V_86 ;
V_108 = V_9 -> V_52 . V_108 ;
switch ( V_79 ) {
case V_87 :
V_23 = F_40 ( V_9 , V_15 , V_109 ) ;
break;
case V_98 :
V_23 = F_41 ( V_9 , V_15 , V_109 ) ;
break;
case V_99 :
V_23 = F_42 ( V_9 , V_15 , V_109 ) ;
break;
default:
V_23 = - V_84 ;
}
return V_23 ;
}
static int F_44 ( struct V_8 * V_9 , struct V_78 * V_15 )
{
enum V_107 V_108 = V_9 -> V_52 . V_108 ;
T_2 V_124 ;
T_2 V_80 ;
V_124 = F_31 ( V_15 -> V_83 ) ;
if ( V_124 > 127 ) {
F_18 ( V_9 -> V_48 , L_3 , V_124 ) ;
return - V_84 ;
}
if ( V_108 == V_53 ) {
F_18 ( V_9 -> V_48 , L_4 ) ;
return - V_84 ;
}
V_80 = F_34 ( V_9 -> V_92 , V_125 ) ;
V_80 &= ~ ( V_126 ) ;
V_80 |= F_45 ( V_124 ) ;
F_37 ( V_9 -> V_92 , V_125 , V_80 ) ;
if ( V_124 )
F_12 ( & V_9 -> V_52 , V_127 ) ;
else
F_12 ( & V_9 -> V_52 , V_128 ) ;
return 0 ;
}
static int F_46 ( struct V_8 * V_9 , struct V_78 * V_15 )
{
int V_23 ;
F_47 ( & V_9 -> V_60 ) ;
V_23 = V_9 -> V_129 -> V_130 ( & V_9 -> V_52 , V_15 ) ;
F_48 ( & V_9 -> V_60 ) ;
return V_23 ;
}
static int F_49 ( struct V_8 * V_9 , struct V_78 * V_15 )
{
enum V_107 V_108 = V_9 -> V_52 . V_108 ;
T_2 V_131 ;
int V_23 ;
T_2 V_80 ;
V_131 = F_31 ( V_15 -> V_83 ) ;
switch ( V_108 ) {
case V_128 :
return - V_84 ;
case V_127 :
V_23 = F_46 ( V_9 , V_15 ) ;
if ( V_131 && ( ! V_23 || ( V_23 == V_132 ) ) ) {
if ( V_23 == 0 )
F_12 ( & V_9 -> V_52 ,
V_53 ) ;
V_80 = F_34 ( V_9 -> V_92 , V_93 ) ;
V_80 |= ( V_133 | V_134 ) ;
F_37 ( V_9 -> V_92 , V_93 , V_80 ) ;
}
break;
case V_53 :
V_23 = F_46 ( V_9 , V_15 ) ;
if ( ! V_131 && ! V_23 )
F_12 ( & V_9 -> V_52 ,
V_127 ) ;
break;
default:
V_23 = - V_84 ;
}
return V_23 ;
}
static void F_50 ( struct V_56 * V_57 , struct V_58 * V_34 )
{
struct V_1 * V_2 = F_16 ( V_57 ) ;
struct V_8 * V_9 = V_2 -> V_9 ;
T_2 V_135 = 0 ;
T_2 V_80 ;
struct V_136 {
T_6 V_137 ;
T_6 V_138 ;
T_4 V_139 ;
T_4 V_140 ;
} V_141 V_136 ;
int V_23 ;
memcpy ( & V_136 , V_34 -> V_106 , sizeof( V_136 ) ) ;
V_9 -> V_137 = V_136 . V_137 ;
V_9 -> V_138 = V_136 . V_138 ;
V_9 -> V_139 = F_31 ( V_136 . V_139 ) ;
V_9 -> V_140 = F_31 ( V_136 . V_140 ) ;
V_80 = F_34 ( V_9 -> V_92 , V_93 ) ;
if ( V_80 & V_96 )
V_135 = V_9 -> V_140 ;
if ( V_80 & V_94 )
V_135 = V_9 -> V_138 ;
if ( V_135 > 125 )
V_135 = 0 ;
V_23 = F_51 ( V_9 ,
V_142 , V_135 ) ;
F_29 ( V_23 < 0 ) ;
}
static int F_52 ( struct V_8 * V_9 , struct V_78 * V_15 )
{
struct V_1 * V_2 ;
enum V_107 V_108 = V_9 -> V_52 . V_108 ;
T_5 V_143 ;
T_5 V_83 ;
if ( V_108 == V_128 )
return - V_84 ;
V_83 = F_31 ( V_15 -> V_83 ) ;
V_143 = F_31 ( V_15 -> V_143 ) ;
if ( V_143 != 6 ) {
F_18 ( V_9 -> V_48 , L_5 ,
V_143 ) ;
return - V_84 ;
}
V_2 = V_9 -> V_49 [ 0 ] ;
V_9 -> V_104 . V_2 = V_2 ;
V_9 -> V_104 . V_35 . V_105 = V_2 -> V_61 . V_144 ;
V_9 -> V_104 . V_35 . V_106 = V_9 -> V_103 ;
V_9 -> V_104 . V_35 . F_28 = F_50 ;
return F_8 ( V_2 , & V_9 -> V_104 ) ;
}
static int F_53 ( struct V_8 * V_9 , struct V_78 * V_15 )
{
T_5 V_143 ;
T_5 V_83 ;
T_5 V_100 ;
V_83 = F_31 ( V_15 -> V_83 ) ;
V_143 = F_31 ( V_15 -> V_143 ) ;
V_100 = F_31 ( V_15 -> V_100 ) ;
if ( V_100 || V_143 )
return - V_84 ;
V_9 -> V_145 = V_83 ;
return 0 ;
}
static int F_54 ( struct V_8 * V_9 , struct V_78 * V_15 )
{
int V_23 ;
switch ( V_15 -> V_146 ) {
case V_147 :
V_23 = F_33 ( V_9 , V_15 ) ;
break;
case V_148 :
V_23 = F_43 ( V_9 , V_15 , 0 ) ;
break;
case V_149 :
V_23 = F_43 ( V_9 , V_15 , 1 ) ;
break;
case V_150 :
V_23 = F_44 ( V_9 , V_15 ) ;
break;
case V_151 :
V_23 = F_49 ( V_9 , V_15 ) ;
break;
case V_152 :
V_23 = F_52 ( V_9 , V_15 ) ;
break;
case V_153 :
V_23 = F_53 ( V_9 , V_15 ) ;
break;
default:
V_23 = F_46 ( V_9 , V_15 ) ;
break;
}
return V_23 ;
}
static void F_55 ( struct V_8 * V_9 ,
const struct V_154 * V_155 )
{
struct V_78 * V_15 = ( void * ) V_9 -> V_10 ;
int V_23 = - V_84 ;
T_2 V_4 ;
if ( ! V_9 -> V_129 )
goto V_65;
F_56 ( V_15 ) ;
V_4 = F_31 ( V_15 -> V_143 ) ;
if ( ! V_4 ) {
V_9 -> V_55 = false ;
V_9 -> V_51 = false ;
V_9 -> V_31 = V_156 ;
} else {
V_9 -> V_55 = true ;
V_9 -> V_51 = ! ! ( V_15 -> V_85 & V_77 ) ;
V_9 -> V_31 = V_157 ;
}
if ( ( V_15 -> V_85 & V_158 ) == V_159 )
V_23 = F_54 ( V_9 , V_15 ) ;
else
V_23 = F_46 ( V_9 , V_15 ) ;
if ( V_23 == V_132 )
V_9 -> V_50 = true ;
V_65:
if ( V_23 < 0 )
F_21 ( V_9 ) ;
}
static void F_57 ( struct V_8 * V_9 ,
const struct V_154 * V_155 )
{
struct V_33 * V_160 = NULL ;
struct V_58 * V_161 ;
struct V_6 * V_7 ;
struct V_1 * V_162 ;
unsigned V_163 ;
unsigned V_164 ;
void * V_106 ;
T_2 V_165 = 0 ;
T_2 V_37 ;
T_2 V_105 ;
T_6 V_39 ;
V_39 = V_155 -> V_166 ;
V_162 = V_9 -> V_49 [ 0 ] ;
V_9 -> V_31 = V_156 ;
V_7 = V_9 -> V_10 ;
F_58 ( V_162 , V_7 ) ;
V_160 = F_23 ( & V_162 -> V_42 ) ;
if ( ! V_160 )
return;
V_37 = F_59 ( V_7 -> V_14 ) ;
if ( V_37 == V_167 ) {
V_9 -> V_168 = true ;
if ( V_160 )
F_24 ( V_162 , V_160 , - V_68 ) ;
return;
}
V_161 = & V_160 -> V_35 ;
V_106 = V_161 -> V_106 ;
V_164 = V_161 -> V_105 ;
V_105 = V_7 -> V_14 & V_169 ;
V_163 = V_162 -> V_61 . V_144 ;
V_165 = V_161 -> V_105 - V_105 ;
V_161 -> V_36 += V_165 ;
if ( ( F_60 ( V_161 -> V_105 , V_162 -> V_61 . V_144 ) &&
V_161 -> V_105 && V_161 -> V_170 ) || V_9 -> V_171 ) {
V_7 ++ ;
V_7 -> V_15 &= ~ V_16 ;
F_58 ( V_162 , V_7 ) ;
V_162 -> V_11 = 0 ;
V_9 -> V_171 = false ;
}
if ( ( V_39 & 1 ) && V_161 -> V_36 < V_161 -> V_105 )
F_21 ( V_9 ) ;
else
F_24 ( V_162 , V_160 , 0 ) ;
}
static void F_61 ( struct V_8 * V_9 ,
const struct V_154 * V_155 )
{
struct V_33 * V_160 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
T_2 V_37 ;
V_2 = V_9 -> V_49 [ 0 ] ;
V_7 = V_9 -> V_10 ;
F_58 ( V_2 , V_7 ) ;
if ( ! F_19 ( & V_2 -> V_42 ) ) {
V_160 = F_23 ( & V_2 -> V_42 ) ;
F_24 ( V_2 , V_160 , 0 ) ;
}
if ( V_9 -> V_116 ) {
int V_23 ;
V_23 = F_62 ( V_9 , V_9 -> V_115 ) ;
if ( V_23 < 0 ) {
F_18 ( V_9 -> V_48 , L_6 ,
V_9 -> V_115 ) ;
F_21 ( V_9 ) ;
return;
}
}
V_37 = F_59 ( V_7 -> V_14 ) ;
if ( V_37 == V_167 )
V_9 -> V_168 = true ;
V_9 -> V_46 = V_69 ;
F_25 ( V_9 ) ;
}
static void F_63 ( struct V_8 * V_9 ,
const struct V_154 * V_155 )
{
struct V_1 * V_2 = V_9 -> V_49 [ V_155 -> V_166 ] ;
V_2 -> V_24 &= ~ V_25 ;
V_2 -> V_30 = 0 ;
V_9 -> V_168 = false ;
switch ( V_9 -> V_46 ) {
case V_69 :
F_55 ( V_9 , V_155 ) ;
break;
case V_47 :
F_57 ( V_9 , V_155 ) ;
break;
case V_54 :
F_61 ( V_9 , V_155 ) ;
break;
default:
F_64 ( true , L_7 , V_9 -> V_46 ) ;
}
}
static void F_11 ( struct V_8 * V_9 ,
struct V_1 * V_2 , struct V_33 * V_34 )
{
int V_23 ;
V_34 -> V_44 = ! ! V_2 -> V_40 ;
if ( V_34 -> V_35 . V_105 == 0 ) {
F_1 ( V_2 , V_9 -> V_27 , 0 ,
V_172 , false ) ;
V_23 = F_5 ( V_2 ) ;
} else if ( ! F_60 ( V_34 -> V_35 . V_105 , V_2 -> V_61 . V_144 )
&& ( V_2 -> V_40 == 0 ) ) {
T_2 V_144 ;
T_2 V_173 ;
V_23 = F_65 ( V_9 -> V_174 ,
& V_34 -> V_35 , V_2 -> V_40 ) ;
if ( V_23 )
return;
V_144 = V_2 -> V_61 . V_144 ;
V_173 = V_34 -> V_35 . V_105 % V_144 ;
V_9 -> V_171 = true ;
F_1 ( V_2 , V_34 -> V_35 . V_175 ,
V_34 -> V_35 . V_105 ,
V_172 ,
true ) ;
V_34 -> V_7 = & V_9 -> V_10 [ V_2 -> V_11 - 1 ] ;
F_1 ( V_2 , V_9 -> V_176 ,
V_144 - V_173 ,
V_172 ,
false ) ;
V_23 = F_5 ( V_2 ) ;
} else if ( F_60 ( V_34 -> V_35 . V_105 , V_2 -> V_61 . V_144 ) &&
V_34 -> V_35 . V_105 && V_34 -> V_35 . V_170 ) {
T_2 V_144 ;
T_2 V_173 ;
V_23 = F_65 ( V_9 -> V_174 ,
& V_34 -> V_35 , V_2 -> V_40 ) ;
if ( V_23 )
return;
V_144 = V_2 -> V_61 . V_144 ;
V_173 = V_34 -> V_35 . V_105 % V_144 ;
F_1 ( V_2 , V_34 -> V_35 . V_175 ,
V_34 -> V_35 . V_105 ,
V_172 ,
true ) ;
V_34 -> V_7 = & V_9 -> V_10 [ V_2 -> V_11 - 1 ] ;
F_1 ( V_2 , V_9 -> V_176 ,
0 , V_172 ,
false ) ;
V_23 = F_5 ( V_2 ) ;
} else {
V_23 = F_65 ( V_9 -> V_174 ,
& V_34 -> V_35 , V_2 -> V_40 ) ;
if ( V_23 )
return;
F_1 ( V_2 , V_34 -> V_35 . V_175 ,
V_34 -> V_35 . V_105 , V_172 ,
false ) ;
V_34 -> V_7 = & V_9 -> V_10 [ V_2 -> V_11 ] ;
V_23 = F_5 ( V_2 ) ;
}
F_29 ( V_23 < 0 ) ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_2 type ;
type = V_9 -> V_55 ? V_177
: V_178 ;
F_1 ( V_2 , V_9 -> V_27 , 0 , type , false ) ;
return F_5 ( V_2 ) ;
}
static void F_13 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
F_29 ( F_66 ( V_2 ) ) ;
}
static void F_67 ( struct V_8 * V_9 ,
const struct V_154 * V_155 )
{
struct V_1 * V_2 = V_9 -> V_49 [ V_155 -> V_166 ] ;
F_13 ( V_9 , V_2 ) ;
}
static void F_68 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
struct V_21 V_22 ;
T_2 V_179 ;
int V_23 ;
if ( ! V_2 -> V_30 )
return;
V_179 = V_180 ;
V_179 |= V_181 ;
V_179 |= F_69 ( V_2 -> V_30 ) ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
V_23 = F_6 ( V_2 , V_179 , & V_22 ) ;
F_70 ( V_23 ) ;
V_2 -> V_30 = 0 ;
}
static void F_71 ( struct V_8 * V_9 ,
const struct V_154 * V_155 )
{
switch ( V_155 -> V_37 ) {
case V_182 :
if ( V_9 -> V_51 != V_155 -> V_166 ) {
struct V_1 * V_2 = V_9 -> V_49 [ V_9 -> V_51 ] ;
F_18 ( V_9 -> V_48 , L_8 ) ;
F_68 ( V_9 , V_2 ) ;
F_21 ( V_9 ) ;
return;
}
break;
case V_183 :
if ( V_9 -> V_31 != V_156 )
return;
V_9 -> V_46 = V_54 ;
if ( V_9 -> V_50 ) {
struct V_1 * V_2 = V_9 -> V_49 [ 0 ] ;
F_70 ( V_155 -> V_166 != 1 ) ;
if ( ! F_19 ( & V_2 -> V_42 ) ) {
V_9 -> V_50 = false ;
F_12 ( & V_9 -> V_52 ,
V_53 ) ;
F_67 ( V_9 , V_155 ) ;
}
return;
}
F_67 ( V_9 , V_155 ) ;
}
}
void F_72 ( struct V_8 * V_9 ,
const struct V_154 * V_155 )
{
switch ( V_155 -> V_184 ) {
case V_185 :
F_63 ( V_9 , V_155 ) ;
break;
case V_186 :
F_71 ( V_9 , V_155 ) ;
break;
case V_187 :
case V_188 :
case V_189 :
case V_190 :
break;
}
}
