const char * F_1 ( int V_1 )
{
static const char * V_2 [] = {
[ V_3 ] = L_1 ,
[ V_4 ] = L_2 ,
[ V_5 ] = L_3 ,
[ V_6 ] = L_4 ,
[ V_7 ] = L_5 ,
[ V_8 ] = L_6 ,
[ V_9 ] = L_7 ,
} ;
if ( V_1 < V_3 || V_1 > V_9 )
return L_8 ;
return V_2 [ V_1 ] ;
}
void F_2 ( struct V_10 * V_11 , struct V_12 * V_13 ,
struct V_14 * V_15 )
{
V_13 -> V_16 = V_15 ;
F_3 ( sizeof( V_13 -> V_17 ) !=
sizeof( F_4 ( V_13 ) -> V_18 ) ) ;
V_13 -> V_17 = F_4 ( V_13 ) -> V_18 ;
if ( F_5 ( F_6 ( V_11 -> V_16 ) ) )
F_7 ( F_8 ( V_11 , V_15 ) , V_13 ) ;
else
F_9 ( V_13 ) ;
}
static int F_10 ( struct V_14 * V_19 ,
T_1 V_20 , T_2 V_21 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_23 ;
struct V_24 * V_25 ;
int V_26 ;
F_12 (bond, slave, iter) {
V_26 = F_13 ( V_22 -> V_16 , V_20 , V_21 ) ;
if ( V_26 )
goto V_27;
}
return 0 ;
V_27:
F_12 (bond, rollback_slave, iter) {
if ( V_23 == V_22 )
break;
F_14 ( V_23 -> V_16 , V_20 , V_21 ) ;
}
return V_26 ;
}
static int F_15 ( struct V_14 * V_19 ,
T_1 V_20 , T_2 V_21 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter)
F_14 ( V_22 -> V_16 , V_20 , V_21 ) ;
if ( F_16 ( V_11 ) )
F_17 ( V_11 , V_21 ) ;
return 0 ;
}
int F_18 ( struct V_10 * V_11 )
{
struct V_24 * V_25 ;
struct V_22 * V_22 ;
if ( ! F_19 ( V_11 ) )
goto V_28;
if ( F_20 ( V_11 ) == V_7 )
return F_21 ( V_11 ) ;
F_12 (bond, slave, iter) {
if ( V_22 -> V_29 == V_30 ) {
if ( ! F_22 ( V_11 -> V_16 ) ) {
F_23 ( V_11 -> V_16 ) ;
return 1 ;
}
return 0 ;
}
}
V_28:
if ( F_22 ( V_11 -> V_16 ) ) {
F_24 ( V_11 -> V_16 ) ;
return 1 ;
}
return 0 ;
}
static void F_25 ( struct V_22 * V_22 )
{
struct V_14 * V_15 = V_22 -> V_16 ;
struct V_31 V_32 ;
int V_26 ;
V_22 -> V_33 = V_34 ;
V_22 -> V_35 = V_36 ;
V_26 = F_26 ( V_15 , & V_32 ) ;
if ( V_26 < 0 )
return;
if ( V_32 . V_37 . V_33 == 0 || V_32 . V_37 . V_33 == ( ( V_38 ) - 1 ) )
return;
switch ( V_32 . V_37 . V_35 ) {
case V_39 :
case V_40 :
break;
default:
return;
}
V_22 -> V_33 = V_32 . V_37 . V_33 ;
V_22 -> V_35 = V_32 . V_37 . V_35 ;
return;
}
const char * F_27 ( T_3 V_29 )
{
switch ( V_29 ) {
case V_30 :
return L_9 ;
case V_41 :
return L_10 ;
case V_42 :
return L_11 ;
case V_43 :
return L_12 ;
default:
return L_8 ;
}
}
static int F_28 ( struct V_10 * V_11 ,
struct V_14 * V_15 , int V_44 )
{
const struct V_45 * V_46 = V_15 -> V_47 ;
int (* F_29)( struct V_14 * , struct V_48 * , int );
struct V_48 V_49 ;
struct V_50 * V_51 ;
if ( ! V_44 && ! F_30 ( V_15 ) )
return 0 ;
if ( V_11 -> V_52 . V_53 )
return F_22 ( V_15 ) ? V_54 : 0 ;
if ( V_15 -> V_55 -> V_56 )
return V_15 -> V_55 -> V_56 ( V_15 ) ?
V_54 : 0 ;
F_29 = V_46 -> V_57 ;
if ( F_29 ) {
strncpy ( V_49 . V_58 , V_15 -> V_59 , V_60 ) ;
V_51 = F_31 ( & V_49 ) ;
if ( F_29 ( V_15 , & V_49 , V_61 ) == 0 ) {
V_51 -> V_62 = V_63 ;
if ( F_29 ( V_15 , & V_49 , V_64 ) == 0 )
return V_51 -> V_65 & V_54 ;
}
}
return V_44 ? - 1 : V_54 ;
}
static int F_32 ( struct V_10 * V_11 , int V_66 )
{
struct V_24 * V_25 ;
int V_67 = 0 ;
if ( F_33 ( V_11 ) ) {
struct V_22 * V_68 = F_34 ( V_11 -> V_69 ) ;
if ( V_68 )
V_67 = F_35 ( V_68 -> V_16 , V_66 ) ;
} else {
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
V_67 = F_35 ( V_22 -> V_16 , V_66 ) ;
if ( V_67 )
return V_67 ;
}
}
return V_67 ;
}
static int F_36 ( struct V_10 * V_11 , int V_66 )
{
struct V_24 * V_25 ;
int V_67 = 0 ;
if ( F_33 ( V_11 ) ) {
struct V_22 * V_68 = F_34 ( V_11 -> V_69 ) ;
if ( V_68 )
V_67 = F_37 ( V_68 -> V_16 , V_66 ) ;
} else {
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
V_67 = F_37 ( V_22 -> V_16 , V_66 ) ;
if ( V_67 )
return V_67 ;
}
}
return V_67 ;
}
static void F_38 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_39 ( V_71 , struct V_10 ,
V_72 . V_71 ) ;
if ( ! F_40 () ) {
F_41 ( V_11 -> V_73 , & V_11 -> V_72 , 1 ) ;
return;
}
F_42 ( V_74 , V_11 -> V_16 ) ;
if ( V_11 -> V_75 > 1 ) {
V_11 -> V_75 -- ;
F_41 ( V_11 -> V_73 , & V_11 -> V_72 , V_76 / 5 ) ;
}
F_43 () ;
}
static void F_44 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_45 ( V_15 , V_19 ) ;
F_46 ( V_15 , V_19 ) ;
if ( F_20 ( V_11 ) == V_7 ) {
T_4 V_77 [ V_78 ] = V_79 ;
F_47 ( V_15 , V_77 ) ;
}
}
static void F_48 ( struct V_10 * V_11 , struct V_22 * V_80 ,
struct V_22 * V_81 )
{
if ( V_81 ) {
if ( V_11 -> V_16 -> V_82 & V_83 )
F_35 ( V_81 -> V_16 , - 1 ) ;
if ( V_11 -> V_16 -> V_82 & V_84 )
F_37 ( V_81 -> V_16 , - 1 ) ;
F_44 ( V_11 -> V_16 , V_81 -> V_16 ) ;
}
if ( V_80 ) {
if ( V_11 -> V_16 -> V_82 & V_83 )
F_35 ( V_80 -> V_16 , 1 ) ;
if ( V_11 -> V_16 -> V_82 & V_84 )
F_37 ( V_80 -> V_16 , 1 ) ;
F_49 ( V_11 -> V_16 ) ;
F_50 ( V_80 -> V_16 , V_11 -> V_16 ) ;
F_51 ( V_80 -> V_16 , V_11 -> V_16 ) ;
F_52 ( V_11 -> V_16 ) ;
}
}
static void F_53 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
F_54 ( V_19 , L_13 ,
V_19 , V_15 , V_15 -> V_59 , V_15 -> V_85 ) ;
memcpy ( V_19 -> V_86 , V_15 -> V_86 , V_15 -> V_85 ) ;
V_19 -> V_87 = V_88 ;
F_42 ( V_89 , V_19 ) ;
}
static struct V_22 * F_55 ( struct V_10 * V_11 ,
struct V_22 * V_80 )
{
struct V_22 * V_22 ;
struct V_24 * V_25 ;
F_12 (bond, slave, iter) {
if ( V_22 == V_80 )
continue;
if ( F_56 ( V_11 -> V_16 -> V_86 , V_22 -> V_16 -> V_86 ) )
return V_22 ;
}
return NULL ;
}
static void F_57 ( struct V_10 * V_11 ,
struct V_22 * V_80 ,
struct V_22 * V_81 )
{
T_4 V_90 [ V_78 ] ;
struct V_91 V_92 ;
int V_93 ;
switch ( V_11 -> V_52 . V_94 ) {
case V_95 :
if ( V_80 )
F_53 ( V_11 -> V_16 , V_80 -> V_16 ) ;
break;
case V_96 :
if ( ! V_80 )
return;
if ( ! V_81 )
V_81 = F_55 ( V_11 , V_80 ) ;
if ( V_81 ) {
F_58 ( V_90 , V_80 -> V_16 -> V_86 ) ;
F_58 ( V_92 . V_97 ,
V_81 -> V_16 -> V_86 ) ;
V_92 . V_98 = V_80 -> V_16 -> type ;
} else {
F_58 ( V_92 . V_97 , V_11 -> V_16 -> V_86 ) ;
V_92 . V_98 = V_11 -> V_16 -> type ;
}
V_93 = F_59 ( V_80 -> V_16 , & V_92 ) ;
if ( V_93 ) {
F_60 ( V_11 -> V_16 , L_14 ,
- V_93 , V_80 -> V_16 -> V_59 ) ;
goto V_99;
}
if ( ! V_81 )
goto V_99;
F_58 ( V_92 . V_97 , V_90 ) ;
V_92 . V_98 = V_81 -> V_16 -> type ;
V_93 = F_59 ( V_81 -> V_16 , & V_92 ) ;
if ( V_93 )
F_60 ( V_11 -> V_16 , L_14 ,
- V_93 , V_80 -> V_16 -> V_59 ) ;
V_99:
break;
default:
F_60 ( V_11 -> V_16 , L_15 ,
V_11 -> V_52 . V_94 ) ;
break;
}
}
static struct V_22 * F_61 ( struct V_10 * V_11 )
{
struct V_22 * V_100 = F_34 ( V_11 -> V_101 ) ;
struct V_22 * V_102 = F_34 ( V_11 -> V_69 ) ;
if ( ! V_100 || V_100 -> V_29 != V_30 ) {
if ( ! V_102 || V_102 -> V_29 != V_30 )
return NULL ;
return V_102 ;
}
if ( V_11 -> V_103 ) {
V_11 -> V_103 = false ;
return V_100 ;
}
if ( ! V_102 || V_102 -> V_29 != V_30 )
return V_100 ;
switch ( V_11 -> V_52 . V_104 ) {
case V_105 :
return V_100 ;
case V_106 :
if ( V_100 -> V_33 < V_102 -> V_33 )
return V_102 ;
if ( V_100 -> V_33 == V_102 -> V_33 && V_100 -> V_35 <= V_102 -> V_35 )
return V_102 ;
return V_100 ;
case V_107 :
return V_102 ;
default:
F_60 ( V_11 -> V_16 , L_16 ,
V_11 -> V_52 . V_104 ) ;
return V_102 ;
}
}
static struct V_22 * F_62 ( struct V_10 * V_11 )
{
struct V_22 * V_22 , * V_108 = NULL ;
struct V_24 * V_25 ;
int V_109 = V_11 -> V_52 . V_110 ;
V_22 = F_61 ( V_11 ) ;
if ( V_22 )
return V_22 ;
F_12 (bond, slave, iter) {
if ( V_22 -> V_29 == V_30 )
return V_22 ;
if ( V_22 -> V_29 == V_43 && F_63 ( V_22 ) &&
V_22 -> V_111 < V_109 ) {
V_109 = V_22 -> V_111 ;
V_108 = V_22 ;
}
}
return V_108 ;
}
static bool F_64 ( struct V_10 * V_11 )
{
struct V_22 * V_22 ;
F_65 () ;
V_22 = F_66 ( V_11 -> V_69 ) ;
F_67 () ;
F_54 ( V_11 -> V_16 , L_17 ,
V_22 ? V_22 -> V_16 -> V_59 : L_18 ) ;
if ( ! V_22 || ! V_11 -> V_112 ||
! F_22 ( V_11 -> V_16 ) ||
F_68 ( V_113 , & V_22 -> V_16 -> V_114 ) )
return false ;
return true ;
}
void F_69 ( struct V_10 * V_11 , struct V_22 * V_80 )
{
struct V_22 * V_81 ;
F_70 () ;
V_81 = F_34 ( V_11 -> V_69 ) ;
if ( V_81 == V_80 )
return;
if ( V_80 ) {
V_80 -> V_115 = V_116 ;
if ( V_80 -> V_29 == V_43 ) {
if ( F_33 ( V_11 ) ) {
F_71 ( V_11 -> V_16 , L_19 ,
V_80 -> V_16 -> V_59 ,
( V_11 -> V_52 . V_110 - V_80 -> V_111 ) * V_11 -> V_52 . V_117 ) ;
}
V_80 -> V_111 = 0 ;
F_72 ( V_80 , V_30 ,
V_118 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_73 ( V_80 , V_30 ) ;
if ( F_16 ( V_11 ) )
F_74 ( V_11 , V_80 , V_30 ) ;
} else {
if ( F_33 ( V_11 ) ) {
F_71 ( V_11 -> V_16 , L_20 ,
V_80 -> V_16 -> V_59 ) ;
}
}
}
if ( F_33 ( V_11 ) )
F_48 ( V_11 , V_80 , V_81 ) ;
if ( F_16 ( V_11 ) ) {
F_75 ( V_11 , V_80 ) ;
if ( V_81 )
F_76 ( V_81 ,
V_118 ) ;
if ( V_80 )
F_77 ( V_80 ,
V_118 ) ;
} else {
F_78 ( V_11 -> V_69 , V_80 ) ;
}
if ( F_20 ( V_11 ) == V_4 ) {
if ( V_81 )
F_76 ( V_81 ,
V_118 ) ;
if ( V_80 ) {
bool V_119 = false ;
F_77 ( V_80 ,
V_118 ) ;
if ( V_11 -> V_52 . V_94 )
F_57 ( V_11 , V_80 ,
V_81 ) ;
if ( F_30 ( V_11 -> V_16 ) ) {
V_11 -> V_112 =
V_11 -> V_52 . V_120 ;
V_119 =
F_64 ( V_11 ) ;
}
F_42 ( V_121 , V_11 -> V_16 ) ;
if ( V_119 )
F_42 ( V_122 ,
V_11 -> V_16 ) ;
}
}
if ( F_30 ( V_11 -> V_16 ) && ( V_11 -> V_52 . V_123 > 0 ) &&
( ( F_33 ( V_11 ) && V_80 ) ||
F_20 ( V_11 ) == V_3 ) ) {
V_11 -> V_75 = V_11 -> V_52 . V_123 ;
F_41 ( V_11 -> V_73 , & V_11 -> V_72 , 1 ) ;
}
}
void F_79 ( struct V_10 * V_11 )
{
struct V_22 * V_124 ;
int V_93 ;
F_70 () ;
V_124 = F_62 ( V_11 ) ;
if ( V_124 != F_34 ( V_11 -> V_69 ) ) {
F_69 ( V_11 , V_124 ) ;
V_93 = F_18 ( V_11 ) ;
if ( ! V_93 )
return;
if ( F_22 ( V_11 -> V_16 ) )
F_71 ( V_11 -> V_16 , L_21 ) ;
else
F_71 ( V_11 -> V_16 , L_22 ) ;
}
}
static inline int F_80 ( struct V_22 * V_22 )
{
struct V_125 * V_126 ;
int V_67 = 0 ;
V_126 = F_81 ( sizeof( * V_126 ) , V_127 ) ;
V_67 = - V_128 ;
if ( ! V_126 )
goto V_99;
V_67 = F_82 ( V_126 , V_22 -> V_16 ) ;
if ( V_67 ) {
F_83 ( V_126 ) ;
goto V_99;
}
V_22 -> V_126 = V_126 ;
V_99:
return V_67 ;
}
static inline void F_84 ( struct V_22 * V_22 )
{
struct V_125 * V_126 = V_22 -> V_126 ;
if ( ! V_126 )
return;
V_22 -> V_126 = NULL ;
F_85 ( V_126 ) ;
}
static void F_86 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 = NULL ;
struct V_24 * V_25 ;
struct V_129 V_129 ;
struct V_130 * V_131 ;
const struct V_45 * V_132 ;
if ( F_20 ( V_11 ) == V_7 )
if ( F_87 ( V_11 , & V_129 ) )
return;
F_88 (bond, slave, iter) {
V_132 = V_22 -> V_16 -> V_47 ;
if ( ! F_63 ( V_22 ) || ! V_132 -> V_133 )
continue;
if ( F_20 ( V_11 ) == V_7 ) {
struct V_134 * V_135 =
F_89 ( V_22 ) -> V_136 . V_134 ;
if ( V_135 &&
V_135 -> V_137 != V_129 . V_138 )
continue;
}
V_131 = F_90 ( V_22 -> V_16 -> V_139 ) ;
if ( F_91 ( & V_131 -> V_140 ) )
continue;
V_132 -> V_133 ( V_22 -> V_16 ) ;
F_92 ( & V_131 -> V_140 ) ;
}
}
static void F_93 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter)
if ( F_63 ( V_22 ) )
F_84 ( V_22 ) ;
}
static int F_94 ( struct V_14 * V_16 , struct V_130 * V_131 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_67 = 0 ;
F_12 (bond, slave, iter) {
V_67 = F_80 ( V_22 ) ;
if ( V_67 ) {
F_93 ( V_16 ) ;
break;
}
}
return V_67 ;
}
static inline int F_80 ( struct V_22 * V_22 )
{
return 0 ;
}
static inline void F_84 ( struct V_22 * V_22 )
{
}
static void F_93 ( struct V_14 * V_19 )
{
}
static T_5 F_95 ( struct V_14 * V_16 ,
T_5 V_141 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
struct V_24 * V_25 ;
T_5 V_142 ;
struct V_22 * V_22 ;
V_142 = V_141 ;
V_141 &= ~ V_143 ;
V_141 |= V_144 ;
F_12 (bond, slave, iter) {
V_141 = F_96 ( V_141 ,
V_22 -> V_16 -> V_141 ,
V_142 ) ;
}
V_141 = F_97 ( V_141 , V_142 ) ;
return V_141 ;
}
static void F_98 ( struct V_10 * V_11 )
{
unsigned int V_145 = V_146 |
V_147 ;
T_5 V_148 = V_149 ;
T_5 V_150 = V_151 ;
struct V_14 * V_19 = V_11 -> V_16 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
unsigned short V_152 = V_153 ;
unsigned int V_154 = V_155 ;
T_2 V_156 = V_157 ;
if ( ! F_19 ( V_11 ) )
goto V_158;
V_148 &= V_144 ;
F_12 (bond, slave, iter) {
V_148 = F_96 ( V_148 ,
V_22 -> V_16 -> V_148 , V_149 ) ;
V_150 = F_96 ( V_150 ,
V_22 -> V_16 -> V_159 ,
V_151 ) ;
V_145 &= V_22 -> V_16 -> V_160 ;
if ( V_22 -> V_16 -> V_161 > V_152 )
V_152 = V_22 -> V_16 -> V_161 ;
V_154 = F_99 ( V_154 , V_22 -> V_16 -> V_154 ) ;
V_156 = F_99 ( V_156 , V_22 -> V_16 -> V_156 ) ;
}
V_19 -> V_161 = V_152 ;
V_158:
V_19 -> V_148 = V_148 ;
V_19 -> V_159 = V_150 | V_162 ;
V_19 -> V_156 = V_156 ;
F_100 ( V_19 , V_154 ) ;
V_19 -> V_160 &= ~ V_146 ;
if ( ( V_19 -> V_160 & V_147 ) &&
V_145 == ( V_146 | V_147 ) )
V_19 -> V_160 |= V_146 ;
F_101 ( V_19 ) ;
}
static void F_102 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
V_19 -> V_163 = V_15 -> V_163 ;
V_19 -> type = V_15 -> type ;
V_19 -> V_161 = V_15 -> V_161 ;
V_19 -> V_85 = V_15 -> V_85 ;
memcpy ( V_19 -> V_164 , V_15 -> V_164 ,
V_15 -> V_85 ) ;
}
static bool F_103 ( struct V_12 * V_13 ,
struct V_22 * V_22 ,
struct V_10 * V_11 )
{
if ( F_104 ( V_22 ) ) {
if ( F_20 ( V_11 ) == V_9 &&
V_13 -> V_165 != V_166 &&
V_13 -> V_165 != V_167 )
return false ;
return true ;
}
return false ;
}
static T_6 F_105 ( struct V_12 * * V_168 )
{
struct V_12 * V_13 = * V_168 ;
struct V_22 * V_22 ;
struct V_10 * V_11 ;
int (* F_106)( const struct V_12 * , struct V_10 * ,
struct V_22 * );
int V_169 = V_170 ;
V_13 = F_107 ( V_13 , V_171 ) ;
if ( F_5 ( ! V_13 ) )
return V_172 ;
* V_168 = V_13 ;
V_22 = F_108 ( V_13 -> V_16 ) ;
V_11 = V_22 -> V_11 ;
F_106 = F_109 ( V_11 -> F_106 ) ;
if ( F_106 ) {
V_169 = F_106 ( V_13 , V_11 , V_22 ) ;
if ( V_169 == V_172 ) {
F_110 ( V_13 ) ;
return V_169 ;
}
}
if ( F_103 ( V_13 , V_22 , V_11 ) )
return V_173 ;
V_13 -> V_16 = V_11 -> V_16 ;
if ( F_20 ( V_11 ) == V_9 &&
V_11 -> V_16 -> V_160 & V_174 &&
V_13 -> V_165 == V_175 ) {
if ( F_5 ( F_111 ( V_13 ,
V_13 -> V_176 - F_112 ( V_13 ) ) ) ) {
F_113 ( V_13 ) ;
return V_172 ;
}
F_58 ( F_114 ( V_13 ) -> V_177 , V_11 -> V_16 -> V_86 ) ;
}
return V_169 ;
}
static enum V_178 F_115 ( struct V_10 * V_11 )
{
switch ( F_20 ( V_11 ) ) {
case V_3 :
return V_179 ;
case V_4 :
return V_180 ;
case V_6 :
return V_181 ;
case V_5 :
case V_7 :
return V_182 ;
default:
return V_183 ;
}
}
static int F_116 ( struct V_10 * V_11 , struct V_22 * V_22 )
{
struct V_184 V_185 ;
int V_67 ;
V_185 . V_186 = F_115 ( V_11 ) ;
V_67 = F_117 ( V_22 -> V_16 , V_11 -> V_16 , V_22 ,
& V_185 ) ;
if ( V_67 )
return V_67 ;
F_118 ( V_187 , V_22 -> V_16 , V_188 , V_127 ) ;
return 0 ;
}
static void F_119 ( struct V_10 * V_11 , struct V_22 * V_22 )
{
F_120 ( V_22 -> V_16 , V_11 -> V_16 ) ;
V_22 -> V_16 -> V_82 &= ~ V_188 ;
F_118 ( V_187 , V_22 -> V_16 , V_188 , V_127 ) ;
}
static struct V_22 * F_121 ( struct V_10 * V_11 )
{
struct V_22 * V_22 = NULL ;
V_22 = F_81 ( sizeof( * V_22 ) , V_127 ) ;
if ( ! V_22 )
return NULL ;
if ( F_20 ( V_11 ) == V_7 ) {
F_89 ( V_22 ) = F_81 ( sizeof( struct V_189 ) ,
V_127 ) ;
if ( ! F_89 ( V_22 ) ) {
F_83 ( V_22 ) ;
return NULL ;
}
}
return V_22 ;
}
static void F_122 ( struct V_22 * V_22 )
{
struct V_10 * V_11 = F_123 ( V_22 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_83 ( F_89 ( V_22 ) ) ;
F_83 ( V_22 ) ;
}
static void F_124 ( struct V_10 * V_11 , struct V_190 * V_191 )
{
V_191 -> V_192 = F_20 ( V_11 ) ;
V_191 -> V_117 = V_11 -> V_52 . V_117 ;
V_191 -> V_193 = V_11 -> V_194 ;
}
static void F_125 ( struct V_22 * V_22 , struct V_195 * V_191 )
{
strcpy ( V_191 -> V_196 , V_22 -> V_16 -> V_59 ) ;
V_191 -> V_29 = V_22 -> V_29 ;
V_191 -> V_114 = F_126 ( V_22 ) ;
V_191 -> V_197 = V_22 -> V_197 ;
}
static void F_127 ( struct V_14 * V_16 ,
struct V_198 * V_191 )
{
F_128 () ;
F_129 ( V_16 , V_191 ) ;
F_43 () ;
}
static void F_130 ( struct V_70 * V_199 )
{
struct V_200 * V_201 =
F_39 ( V_199 , struct V_200 , V_71 . V_71 ) ;
F_127 ( V_201 -> V_16 , & V_201 -> V_202 ) ;
F_131 ( V_201 -> V_16 ) ;
F_83 ( V_201 ) ;
}
void F_132 ( struct V_22 * V_22 )
{
struct V_10 * V_11 = V_22 -> V_11 ;
struct V_200 * V_203 = F_81 ( sizeof( * V_203 ) , V_171 ) ;
if ( ! V_203 )
return;
F_133 ( V_22 -> V_16 ) ;
V_203 -> V_16 = V_22 -> V_16 ;
F_125 ( V_22 , & V_203 -> V_202 . V_22 ) ;
F_124 ( V_11 , & V_203 -> V_202 . V_204 ) ;
F_134 ( & V_203 -> V_71 , F_130 ) ;
F_41 ( V_22 -> V_11 -> V_73 , & V_203 -> V_71 , 0 ) ;
}
void F_135 ( struct V_22 * V_22 )
{
struct V_205 V_191 ;
V_191 . V_206 = V_22 -> V_29 == V_30 ||
V_22 -> V_29 == V_41 ;
V_191 . V_207 = F_136 ( V_22 ) ;
F_137 ( V_22 -> V_16 , & V_191 ) ;
}
int F_138 ( struct V_14 * V_19 , struct V_14 * V_15 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
const struct V_45 * V_46 = V_15 -> V_47 ;
struct V_22 * V_208 = NULL , * V_209 ;
struct V_91 V_210 ;
int V_211 ;
int V_26 = 0 , V_212 ;
if ( ! V_11 -> V_52 . V_53 &&
V_15 -> V_55 -> V_56 == NULL &&
V_46 -> V_57 == NULL ) {
F_139 ( V_19 , L_23 ,
V_15 -> V_59 ) ;
}
if ( F_140 ( V_15 ) ) {
F_60 ( V_19 ,
L_24 ) ;
return - V_213 ;
}
if ( V_19 == V_15 ) {
F_60 ( V_19 , L_25 ) ;
return - V_214 ;
}
if ( V_15 -> V_141 & V_215 ) {
F_54 ( V_19 , L_26 ,
V_15 -> V_59 ) ;
if ( F_141 ( V_19 ) ) {
F_60 ( V_19 , L_27 ,
V_15 -> V_59 , V_19 -> V_59 ) ;
return - V_214 ;
} else {
F_139 ( V_19 , L_28 ,
V_15 -> V_59 , V_15 -> V_59 ,
V_19 -> V_59 ) ;
}
} else {
F_54 ( V_19 , L_29 ,
V_15 -> V_59 ) ;
}
if ( V_15 -> V_82 & V_216 ) {
F_60 ( V_19 , L_30 ,
V_15 -> V_59 ) ;
return - V_214 ;
}
if ( ! F_19 ( V_11 ) ) {
if ( V_19 -> type != V_15 -> type ) {
F_54 ( V_19 , L_31 ,
V_19 -> type , V_15 -> type ) ;
V_26 = F_42 ( V_217 ,
V_19 ) ;
V_26 = F_142 ( V_26 ) ;
if ( V_26 ) {
F_60 ( V_19 , L_32 ) ;
return - V_213 ;
}
F_143 ( V_19 ) ;
F_144 ( V_19 ) ;
if ( V_15 -> type != V_218 )
F_102 ( V_19 , V_15 ) ;
else {
F_145 ( V_19 ) ;
V_19 -> V_160 &= ~ V_219 ;
}
F_42 ( V_220 ,
V_19 ) ;
}
} else if ( V_19 -> type != V_15 -> type ) {
F_60 ( V_19 , L_33 ,
V_15 -> V_59 , V_15 -> type , V_19 -> type ) ;
return - V_221 ;
}
if ( V_15 -> type == V_222 &&
F_20 ( V_11 ) != V_4 ) {
F_139 ( V_19 , L_34 ,
V_15 -> type ) ;
V_26 = - V_223 ;
goto V_224;
}
if ( ! V_46 -> V_225 ||
V_15 -> type == V_222 ) {
F_139 ( V_19 , L_35 ) ;
if ( F_20 ( V_11 ) == V_4 &&
V_11 -> V_52 . V_94 != V_95 ) {
if ( ! F_19 ( V_11 ) ) {
V_11 -> V_52 . V_94 = V_95 ;
F_139 ( V_19 , L_36 ) ;
} else {
F_60 ( V_19 , L_37 ) ;
V_26 = - V_223 ;
goto V_224;
}
}
}
F_42 ( V_226 , V_15 ) ;
if ( ! F_19 ( V_11 ) &&
V_11 -> V_16 -> V_87 == V_227 )
F_53 ( V_11 -> V_16 , V_15 ) ;
V_208 = F_121 ( V_11 ) ;
if ( ! V_208 ) {
V_26 = - V_128 ;
goto V_224;
}
V_208 -> V_11 = V_11 ;
V_208 -> V_16 = V_15 ;
V_208 -> V_228 = 0 ;
V_208 -> V_229 = V_15 -> V_230 ;
V_26 = F_146 ( V_15 , V_11 -> V_16 -> V_230 ) ;
if ( V_26 ) {
F_54 ( V_19 , L_38 , V_26 ) ;
goto V_231;
}
F_58 ( V_208 -> V_232 , V_15 -> V_86 ) ;
if ( ! V_11 -> V_52 . V_94 ||
F_20 ( V_11 ) != V_4 ) {
memcpy ( V_210 . V_97 , V_19 -> V_86 , V_19 -> V_85 ) ;
V_210 . V_98 = V_15 -> type ;
V_26 = F_59 ( V_15 , & V_210 ) ;
if ( V_26 ) {
F_54 ( V_19 , L_39 , V_26 ) ;
goto V_233;
}
}
V_15 -> V_82 |= V_188 ;
V_26 = F_147 ( V_15 ) ;
if ( V_26 ) {
F_54 ( V_19 , L_40 , V_15 -> V_59 ) ;
goto V_234;
}
V_15 -> V_160 |= V_235 ;
F_148 ( V_208 -> V_16 , & V_208 -> V_236 ) ;
if ( F_16 ( V_11 ) ) {
V_26 = F_149 ( V_11 , V_208 ) ;
if ( V_26 )
goto V_237;
}
if ( ! F_33 ( V_11 ) ) {
if ( V_19 -> V_82 & V_83 ) {
V_26 = F_35 ( V_15 , 1 ) ;
if ( V_26 )
goto V_237;
}
if ( V_19 -> V_82 & V_84 ) {
V_26 = F_37 ( V_15 , 1 ) ;
if ( V_26 )
goto V_237;
}
F_49 ( V_19 ) ;
F_150 ( V_15 , V_19 ) ;
F_151 ( V_15 , V_19 ) ;
F_52 ( V_19 ) ;
}
if ( F_20 ( V_11 ) == V_7 ) {
T_4 V_77 [ V_78 ] = V_79 ;
F_152 ( V_15 , V_77 ) ;
}
V_26 = F_153 ( V_15 , V_19 ) ;
if ( V_26 ) {
F_60 ( V_19 , L_41 ,
V_15 -> V_59 ) ;
goto V_237;
}
V_209 = F_154 ( V_11 ) ;
V_208 -> V_111 = 0 ;
V_208 -> V_197 = 0 ;
F_25 ( V_208 ) ;
V_208 -> V_238 = V_116 -
( F_155 ( V_11 -> V_52 . V_239 ) + 1 ) ;
for ( V_212 = 0 ; V_212 < V_240 ; V_212 ++ )
V_208 -> V_241 [ V_212 ] = V_208 -> V_238 ;
if ( V_11 -> V_52 . V_117 && ! V_11 -> V_52 . V_53 ) {
V_211 = F_28 ( V_11 , V_15 , 1 ) ;
if ( ( V_211 == - 1 ) && ! V_11 -> V_52 . V_239 ) {
F_139 ( V_19 , L_42 ,
V_15 -> V_59 ) ;
} else if ( V_211 == - 1 ) {
F_139 ( V_19 , L_43 ,
V_15 -> V_59 ) ;
}
}
V_208 -> V_29 = V_242 ;
if ( V_11 -> V_52 . V_117 ) {
if ( F_28 ( V_11 , V_15 , 0 ) == V_54 ) {
if ( V_11 -> V_52 . V_110 ) {
F_72 ( V_208 ,
V_43 ,
V_118 ) ;
V_208 -> V_111 = V_11 -> V_52 . V_110 ;
} else {
F_72 ( V_208 ,
V_30 ,
V_118 ) ;
}
} else {
F_72 ( V_208 , V_42 ,
V_118 ) ;
}
} else if ( V_11 -> V_52 . V_239 ) {
F_72 ( V_208 ,
( F_22 ( V_15 ) ?
V_30 : V_42 ) ,
V_118 ) ;
} else {
F_72 ( V_208 , V_30 ,
V_118 ) ;
}
if ( V_208 -> V_29 != V_42 )
V_208 -> V_115 = V_116 ;
F_54 ( V_19 , L_44 ,
V_208 -> V_29 == V_42 ? L_45 :
( V_208 -> V_29 == V_30 ? L_46 : L_47 ) ) ;
if ( F_33 ( V_11 ) && V_11 -> V_52 . V_243 [ 0 ] ) {
if ( strcmp ( V_11 -> V_52 . V_243 , V_208 -> V_16 -> V_59 ) == 0 ) {
F_78 ( V_11 -> V_101 , V_208 ) ;
V_11 -> V_103 = true ;
}
}
switch ( F_20 ( V_11 ) ) {
case V_4 :
F_76 ( V_208 ,
V_118 ) ;
break;
case V_7 :
F_76 ( V_208 , V_118 ) ;
if ( ! V_209 ) {
F_89 ( V_208 ) -> V_244 = 1 ;
F_156 ( V_11 , 1000 / V_245 ) ;
} else {
F_89 ( V_208 ) -> V_244 =
F_89 ( V_209 ) -> V_244 + 1 ;
}
F_157 ( V_208 ) ;
break;
case V_8 :
case V_9 :
F_158 ( V_208 ) ;
F_76 ( V_208 , V_118 ) ;
break;
default:
F_54 ( V_19 , L_48 ) ;
F_158 ( V_208 ) ;
if ( ! F_159 ( V_11 -> V_69 ) &&
V_208 -> V_29 == V_30 )
F_78 ( V_11 -> V_69 , V_208 ) ;
break;
}
#ifdef F_160
V_15 -> V_139 = V_11 -> V_16 -> V_139 ;
if ( V_15 -> V_139 ) {
if ( F_80 ( V_208 ) ) {
F_71 ( V_19 , L_49 ) ;
V_26 = - V_213 ;
goto V_246;
}
}
#endif
if ( ! ( V_19 -> V_141 & V_247 ) )
F_161 ( V_15 ) ;
V_26 = F_162 ( V_15 , F_105 ,
V_208 ) ;
if ( V_26 ) {
F_54 ( V_19 , L_50 , V_26 ) ;
goto V_246;
}
V_26 = F_116 ( V_11 , V_208 ) ;
if ( V_26 ) {
F_54 ( V_19 , L_51 , V_26 ) ;
goto V_248;
}
V_26 = F_163 ( V_208 ) ;
if ( V_26 ) {
F_54 ( V_19 , L_52 , V_26 ) ;
goto V_249;
}
V_11 -> V_194 ++ ;
F_98 ( V_11 ) ;
F_18 ( V_11 ) ;
if ( F_33 ( V_11 ) ) {
F_164 () ;
F_79 ( V_11 ) ;
F_165 () ;
}
if ( F_166 ( V_11 ) )
F_167 ( V_11 , NULL ) ;
F_71 ( V_19 , L_53 ,
V_15 -> V_59 ,
F_136 ( V_208 ) ? L_54 : L_55 ,
V_208 -> V_29 != V_42 ? L_56 : L_57 ) ;
F_132 ( V_208 ) ;
return 0 ;
V_249:
F_119 ( V_11 , V_208 ) ;
V_248:
F_168 ( V_15 ) ;
V_246:
if ( ! F_33 ( V_11 ) )
F_44 ( V_19 , V_15 ) ;
F_169 ( V_15 , V_19 ) ;
if ( F_159 ( V_11 -> V_101 ) == V_208 )
F_170 ( V_11 -> V_101 , NULL ) ;
if ( F_159 ( V_11 -> V_69 ) == V_208 ) {
F_164 () ;
F_69 ( V_11 , NULL ) ;
F_79 ( V_11 ) ;
F_165 () ;
}
F_171 () ;
F_84 ( V_208 ) ;
V_237:
V_15 -> V_160 &= ~ V_235 ;
F_172 ( V_15 ) ;
V_234:
V_15 -> V_82 &= ~ V_188 ;
if ( ! V_11 -> V_52 . V_94 ||
F_20 ( V_11 ) != V_4 ) {
F_58 ( V_210 . V_97 , V_208 -> V_232 ) ;
V_210 . V_98 = V_15 -> type ;
F_59 ( V_15 , & V_210 ) ;
}
V_233:
F_146 ( V_15 , V_208 -> V_229 ) ;
V_231:
F_122 ( V_208 ) ;
V_224:
if ( ! F_19 ( V_11 ) ) {
if ( F_173 ( V_19 -> V_86 ,
V_15 -> V_86 ) )
F_174 ( V_19 ) ;
if ( V_19 -> type != V_218 ) {
F_172 ( V_19 ) ;
F_145 ( V_19 ) ;
V_19 -> V_82 |= V_250 ;
V_19 -> V_160 &= ~ V_219 ;
}
}
return V_26 ;
}
static int F_175 ( struct V_14 * V_19 ,
struct V_14 * V_15 ,
bool V_251 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_252 ;
struct V_91 V_210 ;
int V_253 = V_19 -> V_82 ;
T_5 V_254 = V_19 -> V_141 ;
if ( ! ( V_15 -> V_82 & V_188 ) ||
! F_176 ( V_15 , V_19 ) ) {
F_54 ( V_19 , L_58 ,
V_15 -> V_59 ) ;
return - V_221 ;
}
F_164 () ;
V_22 = F_8 ( V_11 , V_15 ) ;
if ( ! V_22 ) {
F_71 ( V_19 , L_59 ,
V_15 -> V_59 ) ;
F_165 () ;
return - V_221 ;
}
F_76 ( V_22 , V_118 ) ;
F_177 ( V_22 ) ;
F_178 ( V_11 -> V_16 , & V_11 -> V_255 ) ;
F_119 ( V_11 , V_22 ) ;
F_168 ( V_15 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_179 ( V_22 ) ;
if ( F_166 ( V_11 ) )
F_167 ( V_11 , V_22 ) ;
F_71 ( V_19 , L_60 ,
F_136 ( V_22 ) ? L_61 : L_62 ,
V_15 -> V_59 ) ;
V_252 = F_159 ( V_11 -> V_69 ) ;
F_170 ( V_11 -> V_256 , NULL ) ;
if ( ! V_251 && ( ! V_11 -> V_52 . V_94 ||
F_20 ( V_11 ) != V_4 ) ) {
if ( F_173 ( V_19 -> V_86 , V_22 -> V_232 ) &&
F_19 ( V_11 ) )
F_139 ( V_19 , L_63 ,
V_15 -> V_59 , V_22 -> V_232 ,
V_19 -> V_59 , V_15 -> V_59 ) ;
}
if ( F_34 ( V_11 -> V_101 ) == V_22 )
F_170 ( V_11 -> V_101 , NULL ) ;
if ( V_252 == V_22 )
F_69 ( V_11 , NULL ) ;
if ( F_16 ( V_11 ) ) {
F_180 ( V_11 , V_22 ) ;
}
if ( V_251 ) {
F_170 ( V_11 -> V_69 , NULL ) ;
} else if ( V_252 == V_22 ) {
F_79 ( V_11 ) ;
}
if ( ! F_19 ( V_11 ) ) {
F_18 ( V_11 ) ;
F_174 ( V_19 ) ;
}
F_165 () ;
F_171 () ;
V_11 -> V_194 -- ;
if ( ! F_19 ( V_11 ) ) {
F_42 ( V_89 , V_11 -> V_16 ) ;
F_42 ( V_257 , V_11 -> V_16 ) ;
}
F_98 ( V_11 ) ;
if ( ! ( V_19 -> V_141 & V_215 ) &&
( V_254 & V_215 ) )
F_71 ( V_19 , L_64 ,
V_15 -> V_59 , V_19 -> V_59 ) ;
F_169 ( V_15 , V_19 ) ;
if ( ! F_33 ( V_11 ) ) {
if ( V_253 & V_83 )
F_35 ( V_15 , - 1 ) ;
if ( V_253 & V_84 )
F_37 ( V_15 , - 1 ) ;
F_44 ( V_19 , V_15 ) ;
}
F_84 ( V_22 ) ;
F_172 ( V_15 ) ;
if ( V_11 -> V_52 . V_94 != V_95 ||
F_20 ( V_11 ) != V_4 ) {
F_58 ( V_210 . V_97 , V_22 -> V_232 ) ;
V_210 . V_98 = V_15 -> type ;
F_59 ( V_15 , & V_210 ) ;
}
F_146 ( V_15 , V_22 -> V_229 ) ;
V_15 -> V_160 &= ~ V_235 ;
F_122 ( V_22 ) ;
return 0 ;
}
int F_181 ( struct V_14 * V_19 , struct V_14 * V_15 )
{
return F_175 ( V_19 , V_15 , false ) ;
}
static int F_182 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
int V_169 ;
V_169 = F_181 ( V_19 , V_15 ) ;
if ( V_169 == 0 && ! F_19 ( V_11 ) ) {
V_19 -> V_160 |= V_258 ;
F_71 ( V_19 , L_65 ,
V_19 -> V_59 ) ;
F_183 ( V_11 ) ;
F_184 ( V_19 ) ;
}
return V_169 ;
}
static void F_185 ( struct V_14 * V_19 , struct V_190 * V_191 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_124 ( V_11 , V_191 ) ;
}
static int F_186 ( struct V_14 * V_19 , struct V_195 * V_191 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
int V_212 = 0 , V_26 = - V_259 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
if ( V_212 ++ == ( int ) V_191 -> V_260 ) {
V_26 = 0 ;
F_125 ( V_22 , V_191 ) ;
break;
}
}
return V_26 ;
}
static int F_187 ( struct V_10 * V_11 )
{
int V_261 , V_262 = 0 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
bool V_263 ;
V_263 = ! F_66 ( V_11 -> V_69 ) ;
F_88 (bond, slave, iter) {
V_22 -> V_264 = V_242 ;
V_261 = F_28 ( V_11 , V_22 -> V_16 , 0 ) ;
switch ( V_22 -> V_29 ) {
case V_30 :
if ( V_261 )
continue;
F_72 ( V_22 , V_41 ,
V_265 ) ;
V_22 -> V_111 = V_11 -> V_52 . V_266 ;
if ( V_22 -> V_111 ) {
F_71 ( V_11 -> V_16 , L_66 ,
( F_20 ( V_11 ) ==
V_4 ) ?
( F_136 ( V_22 ) ?
L_67 : L_68 ) : L_69 ,
V_22 -> V_16 -> V_59 ,
V_11 -> V_52 . V_266 * V_11 -> V_52 . V_117 ) ;
}
case V_41 :
if ( V_261 ) {
F_72 ( V_22 , V_30 ,
V_265 ) ;
V_22 -> V_115 = V_116 ;
F_71 ( V_11 -> V_16 , L_70 ,
( V_11 -> V_52 . V_266 - V_22 -> V_111 ) *
V_11 -> V_52 . V_117 ,
V_22 -> V_16 -> V_59 ) ;
continue;
}
if ( V_22 -> V_111 <= 0 ) {
V_22 -> V_264 = V_42 ;
V_262 ++ ;
continue;
}
V_22 -> V_111 -- ;
break;
case V_42 :
if ( ! V_261 )
continue;
F_72 ( V_22 , V_43 ,
V_265 ) ;
V_22 -> V_111 = V_11 -> V_52 . V_110 ;
if ( V_22 -> V_111 ) {
F_71 ( V_11 -> V_16 , L_71 ,
V_22 -> V_16 -> V_59 ,
V_263 ? 0 :
V_11 -> V_52 . V_110 *
V_11 -> V_52 . V_117 ) ;
}
case V_43 :
if ( ! V_261 ) {
F_72 ( V_22 ,
V_42 ,
V_265 ) ;
F_71 ( V_11 -> V_16 , L_72 ,
( V_11 -> V_52 . V_110 - V_22 -> V_111 ) *
V_11 -> V_52 . V_117 ,
V_22 -> V_16 -> V_59 ) ;
continue;
}
if ( V_263 )
V_22 -> V_111 = 0 ;
if ( V_22 -> V_111 <= 0 ) {
V_22 -> V_264 = V_30 ;
V_262 ++ ;
V_263 = false ;
continue;
}
V_22 -> V_111 -- ;
break;
}
}
return V_262 ;
}
static void F_188 ( struct V_10 * V_11 )
{
struct V_24 * V_25 ;
struct V_22 * V_22 , * V_243 ;
F_12 (bond, slave, iter) {
switch ( V_22 -> V_264 ) {
case V_242 :
continue;
case V_30 :
F_25 ( V_22 ) ;
F_72 ( V_22 , V_30 ,
V_118 ) ;
V_22 -> V_115 = V_116 ;
V_243 = F_34 ( V_11 -> V_101 ) ;
if ( F_20 ( V_11 ) == V_7 ) {
F_189 ( V_22 ) ;
} else if ( F_20 ( V_11 ) != V_4 ) {
F_158 ( V_22 ) ;
} else if ( V_22 != V_243 ) {
F_189 ( V_22 ) ;
}
F_71 ( V_11 -> V_16 , L_73 ,
V_22 -> V_16 -> V_59 ,
V_22 -> V_33 == V_34 ? 0 : V_22 -> V_33 ,
V_22 -> V_35 ? L_74 : L_75 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_73 ( V_22 , V_30 ) ;
if ( F_16 ( V_11 ) )
F_74 ( V_11 , V_22 ,
V_30 ) ;
if ( F_20 ( V_11 ) == V_5 )
F_167 ( V_11 , NULL ) ;
if ( ! V_11 -> V_69 || V_22 == V_243 )
goto V_267;
continue;
case V_42 :
if ( V_22 -> V_197 < V_268 )
V_22 -> V_197 ++ ;
F_72 ( V_22 , V_42 ,
V_118 ) ;
if ( F_20 ( V_11 ) == V_4 ||
F_20 ( V_11 ) == V_7 )
F_76 ( V_22 ,
V_118 ) ;
F_71 ( V_11 -> V_16 , L_76 ,
V_22 -> V_16 -> V_59 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_73 ( V_22 ,
V_42 ) ;
if ( F_16 ( V_11 ) )
F_74 ( V_11 , V_22 ,
V_42 ) ;
if ( F_20 ( V_11 ) == V_5 )
F_167 ( V_11 , NULL ) ;
if ( V_22 == F_159 ( V_11 -> V_69 ) )
goto V_267;
continue;
default:
F_60 ( V_11 -> V_16 , L_77 ,
V_22 -> V_264 , V_22 -> V_16 -> V_59 ) ;
V_22 -> V_264 = V_242 ;
continue;
}
V_267:
F_164 () ;
F_79 ( V_11 ) ;
F_165 () ;
}
F_18 ( V_11 ) ;
}
static void F_190 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_39 ( V_71 , struct V_10 ,
V_269 . V_71 ) ;
bool V_119 = false ;
unsigned long V_111 ;
V_111 = F_155 ( V_11 -> V_52 . V_117 ) ;
if ( ! F_19 ( V_11 ) )
goto V_270;
F_65 () ;
V_119 = F_64 ( V_11 ) ;
if ( F_187 ( V_11 ) ) {
F_67 () ;
if ( ! F_40 () ) {
V_111 = 1 ;
V_119 = false ;
goto V_270;
}
F_188 ( V_11 ) ;
F_43 () ;
} else
F_67 () ;
V_270:
if ( V_11 -> V_52 . V_117 )
F_41 ( V_11 -> V_73 , & V_11 -> V_269 , V_111 ) ;
if ( V_119 ) {
if ( ! F_40 () )
return;
F_42 ( V_122 , V_11 -> V_16 ) ;
F_43 () ;
}
}
static int F_191 ( struct V_14 * V_271 , void * V_176 )
{
T_7 V_272 = * ( ( T_7 * ) V_176 ) ;
return V_272 == F_192 ( V_271 , 0 , V_272 ) ;
}
static bool F_193 ( struct V_10 * V_11 , T_7 V_272 )
{
bool V_169 = false ;
if ( V_272 == F_192 ( V_11 -> V_16 , 0 , V_272 ) )
return true ;
F_65 () ;
if ( F_194 ( V_11 -> V_16 , F_191 , & V_272 ) )
V_169 = true ;
F_67 () ;
return V_169 ;
}
static void F_195 ( struct V_14 * V_15 , int V_273 ,
T_7 V_274 , T_7 V_275 ,
struct V_276 * V_277 )
{
struct V_12 * V_13 ;
struct V_276 * V_278 = V_277 ;
F_54 ( V_15 , L_78 ,
V_273 , V_15 -> V_59 , & V_274 , & V_275 ) ;
V_13 = F_196 ( V_273 , V_279 , V_274 , V_15 , V_275 ,
NULL , V_15 -> V_86 , NULL ) ;
if ( ! V_13 ) {
F_197 ( L_79 ) ;
return;
}
if ( ! V_277 || V_277 -> V_280 == V_281 )
goto V_282;
V_277 ++ ;
while ( V_277 -> V_280 != V_281 ) {
if ( ! V_277 -> V_283 ) {
V_277 ++ ;
continue;
}
F_54 ( V_15 , L_80 ,
F_198 ( V_278 -> V_280 ) , V_277 -> V_283 ) ;
V_13 = F_199 ( V_13 , V_277 -> V_280 ,
V_277 -> V_283 ) ;
if ( ! V_13 ) {
F_197 ( L_81 ) ;
return;
}
V_277 ++ ;
}
if ( V_278 -> V_283 ) {
F_54 ( V_15 , L_82 ,
F_198 ( V_278 -> V_280 ) , V_278 -> V_283 ) ;
F_200 ( V_13 , V_278 -> V_280 ,
V_278 -> V_283 ) ;
}
V_282:
F_201 ( V_13 ) ;
}
struct V_276 * F_202 ( struct V_14 * V_284 ,
struct V_14 * V_285 ,
int V_286 )
{
struct V_276 * V_277 ;
struct V_14 * V_271 ;
struct V_24 * V_25 ;
if ( V_284 == V_285 ) {
V_277 = F_81 ( sizeof( * V_277 ) * ( V_286 + 1 ) , V_171 ) ;
if ( ! V_277 )
return F_203 ( - V_128 ) ;
V_277 [ V_286 ] . V_280 = V_281 ;
return V_277 ;
}
F_204 (start_dev, upper, iter) {
V_277 = F_202 ( V_271 , V_285 , V_286 + 1 ) ;
if ( F_205 ( V_277 ) ) {
if ( F_206 ( V_277 ) )
return V_277 ;
continue;
}
if ( F_207 ( V_271 ) ) {
V_277 [ V_286 ] . V_280 = F_208 ( V_271 ) ;
V_277 [ V_286 ] . V_283 = F_209 ( V_271 ) ;
}
return V_277 ;
}
return NULL ;
}
static void F_210 ( struct V_10 * V_11 , struct V_22 * V_22 )
{
struct V_287 * V_288 ;
struct V_276 * V_277 ;
T_7 * V_289 = V_11 -> V_52 . V_290 , V_210 ;
int V_212 ;
for ( V_212 = 0 ; V_212 < V_240 && V_289 [ V_212 ] ; V_212 ++ ) {
F_54 ( V_11 -> V_16 , L_83 , & V_289 [ V_212 ] ) ;
V_277 = NULL ;
V_288 = F_211 ( F_212 ( V_11 -> V_16 ) , V_289 [ V_212 ] , 0 ,
V_291 , 0 ) ;
if ( F_206 ( V_288 ) ) {
if ( V_11 -> V_52 . V_292 )
F_213 ( L_84 ,
V_11 -> V_16 -> V_59 ,
& V_289 [ V_212 ] ) ;
F_195 ( V_22 -> V_16 , V_293 , V_289 [ V_212 ] ,
0 , V_277 ) ;
continue;
}
if ( V_288 -> V_294 . V_16 == V_11 -> V_16 )
goto V_295;
F_65 () ;
V_277 = F_202 ( V_11 -> V_16 , V_288 -> V_294 . V_16 , 0 ) ;
F_67 () ;
if ( ! F_205 ( V_277 ) )
goto V_295;
F_54 ( V_11 -> V_16 , L_85 ,
& V_289 [ V_212 ] , V_288 -> V_294 . V_16 ? V_288 -> V_294 . V_16 -> V_59 : L_18 ) ;
F_214 ( V_288 ) ;
continue;
V_295:
V_210 = F_192 ( V_288 -> V_294 . V_16 , V_289 [ V_212 ] , 0 ) ;
F_214 ( V_288 ) ;
F_195 ( V_22 -> V_16 , V_293 , V_289 [ V_212 ] ,
V_210 , V_277 ) ;
F_83 ( V_277 ) ;
}
}
static void F_215 ( struct V_10 * V_11 , struct V_22 * V_22 , T_7 V_296 , T_7 V_297 )
{
int V_212 ;
if ( ! V_296 || ! F_193 ( V_11 , V_297 ) ) {
F_54 ( V_11 -> V_16 , L_86 ,
& V_296 , & V_297 ) ;
return;
}
V_212 = F_216 ( V_11 -> V_52 . V_290 , V_296 ) ;
if ( V_212 == - 1 ) {
F_54 ( V_11 -> V_16 , L_87 ,
& V_296 ) ;
return;
}
V_22 -> V_238 = V_116 ;
V_22 -> V_241 [ V_212 ] = V_116 ;
}
int F_217 ( const struct V_12 * V_13 , struct V_10 * V_11 ,
struct V_22 * V_22 )
{
struct V_298 * V_299 = (struct V_298 * ) V_13 -> V_176 ;
struct V_22 * V_69 , * V_300 ;
unsigned char * V_301 ;
T_7 V_296 , V_297 ;
int V_302 , V_303 = V_13 -> V_304 == F_218 ( V_279 ) ;
if ( ! F_219 ( V_11 , V_22 ) ) {
if ( ( F_220 ( V_11 ) && V_303 ) ||
! F_220 ( V_11 ) )
V_22 -> V_238 = V_116 ;
return V_170 ;
} else if ( ! V_303 ) {
return V_170 ;
}
V_302 = F_221 ( V_11 -> V_16 ) ;
F_54 ( V_11 -> V_16 , L_88 ,
V_13 -> V_16 -> V_59 ) ;
if ( V_302 > F_222 ( V_13 ) ) {
V_299 = F_223 ( V_302 , V_171 ) ;
if ( ! V_299 )
goto V_305;
if ( F_224 ( V_13 , 0 , V_299 , V_302 ) < 0 )
goto V_305;
}
if ( V_299 -> V_306 != V_11 -> V_16 -> V_85 ||
V_13 -> V_165 == V_307 ||
V_13 -> V_165 == V_308 ||
V_299 -> V_309 != F_225 ( V_218 ) ||
V_299 -> V_310 != F_225 ( V_311 ) ||
V_299 -> V_312 != 4 )
goto V_305;
V_301 = ( unsigned char * ) ( V_299 + 1 ) ;
V_301 += V_11 -> V_16 -> V_85 ;
memcpy ( & V_296 , V_301 , 4 ) ;
V_301 += 4 + V_11 -> V_16 -> V_85 ;
memcpy ( & V_297 , V_301 , 4 ) ;
F_54 ( V_11 -> V_16 , L_89 ,
V_22 -> V_16 -> V_59 , F_126 ( V_22 ) ,
V_11 -> V_52 . V_292 , F_219 ( V_11 , V_22 ) ,
& V_296 , & V_297 ) ;
V_69 = F_66 ( V_11 -> V_69 ) ;
V_300 = F_66 ( V_11 -> V_256 ) ;
if ( F_136 ( V_22 ) )
F_215 ( V_11 , V_22 , V_296 , V_297 ) ;
else if ( V_69 &&
F_226 ( F_227 ( V_11 , V_69 ) ,
V_69 -> V_115 ) )
F_215 ( V_11 , V_22 , V_297 , V_296 ) ;
else if ( V_300 && ( V_299 -> V_313 == F_225 ( V_314 ) ) &&
F_228 ( V_11 ,
F_229 ( V_300 -> V_16 ) , 1 ) )
F_215 ( V_11 , V_22 , V_296 , V_297 ) ;
V_305:
if ( V_299 != (struct V_298 * ) V_13 -> V_176 )
F_83 ( V_299 ) ;
return V_170 ;
}
static bool F_228 ( struct V_10 * V_11 , unsigned long V_315 ,
int V_316 )
{
int V_317 = F_155 ( V_11 -> V_52 . V_239 ) ;
return F_230 ( V_116 ,
V_315 - V_317 ,
V_315 + V_316 * V_317 + V_317 / 2 ) ;
}
static void F_231 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_39 ( V_71 , struct V_10 ,
V_318 . V_71 ) ;
struct V_22 * V_22 , * V_252 ;
struct V_24 * V_25 ;
int V_267 = 0 , V_319 = 0 ;
if ( ! F_19 ( V_11 ) )
goto V_270;
F_65 () ;
V_252 = F_66 ( V_11 -> V_69 ) ;
F_88 (bond, slave, iter) {
unsigned long V_320 = F_229 ( V_22 -> V_16 ) ;
if ( V_22 -> V_29 != V_30 ) {
if ( F_228 ( V_11 , V_320 , 1 ) &&
F_228 ( V_11 , V_22 -> V_238 , 1 ) ) {
V_22 -> V_29 = V_30 ;
V_319 = 1 ;
if ( ! V_252 ) {
F_71 ( V_11 -> V_16 , L_90 ,
V_22 -> V_16 -> V_59 ) ;
V_267 = 1 ;
} else {
F_71 ( V_11 -> V_16 , L_91 ,
V_22 -> V_16 -> V_59 ) ;
}
}
} else {
if ( ! F_228 ( V_11 , V_320 , 2 ) ||
! F_228 ( V_11 , V_22 -> V_238 , 2 ) ) {
V_22 -> V_29 = V_42 ;
V_319 = 1 ;
if ( V_22 -> V_197 < V_268 )
V_22 -> V_197 ++ ;
F_71 ( V_11 -> V_16 , L_92 ,
V_22 -> V_16 -> V_59 ) ;
if ( V_22 == V_252 )
V_267 = 1 ;
}
}
if ( F_63 ( V_22 ) )
F_210 ( V_11 , V_22 ) ;
}
F_67 () ;
if ( V_267 || V_319 ) {
if ( ! F_40 () )
goto V_270;
if ( V_319 ) {
F_232 ( V_11 ) ;
if ( F_20 ( V_11 ) == V_5 )
F_167 ( V_11 , NULL ) ;
}
if ( V_267 ) {
F_164 () ;
F_79 ( V_11 ) ;
F_165 () ;
}
F_43 () ;
}
V_270:
if ( V_11 -> V_52 . V_239 )
F_41 ( V_11 -> V_73 , & V_11 -> V_318 ,
F_155 ( V_11 -> V_52 . V_239 ) ) ;
}
static int F_233 ( struct V_10 * V_11 )
{
unsigned long V_320 , V_238 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_262 = 0 ;
F_88 (bond, slave, iter) {
V_22 -> V_264 = V_242 ;
V_238 = F_227 ( V_11 , V_22 ) ;
if ( V_22 -> V_29 != V_30 ) {
if ( F_228 ( V_11 , V_238 , 1 ) ) {
V_22 -> V_264 = V_30 ;
V_262 ++ ;
}
continue;
}
if ( F_228 ( V_11 , V_22 -> V_115 , 2 ) )
continue;
if ( ! F_136 ( V_22 ) &&
! F_159 ( V_11 -> V_256 ) &&
! F_228 ( V_11 , V_238 , 3 ) ) {
V_22 -> V_264 = V_42 ;
V_262 ++ ;
}
V_320 = F_229 ( V_22 -> V_16 ) ;
if ( F_136 ( V_22 ) &&
( ! F_228 ( V_11 , V_320 , 2 ) ||
! F_228 ( V_11 , V_238 , 2 ) ) ) {
V_22 -> V_264 = V_42 ;
V_262 ++ ;
}
}
return V_262 ;
}
static void F_234 ( struct V_10 * V_11 )
{
unsigned long V_320 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
switch ( V_22 -> V_264 ) {
case V_242 :
continue;
case V_30 :
V_320 = F_229 ( V_22 -> V_16 ) ;
if ( F_34 ( V_11 -> V_69 ) != V_22 ||
( ! F_34 ( V_11 -> V_69 ) &&
F_228 ( V_11 , V_320 , 1 ) ) ) {
struct V_22 * V_256 ;
V_256 = F_34 ( V_11 -> V_256 ) ;
F_72 ( V_22 , V_30 ,
V_118 ) ;
if ( V_256 ) {
F_76 (
V_256 ,
V_118 ) ;
F_170 ( V_11 -> V_256 , NULL ) ;
}
F_71 ( V_11 -> V_16 , L_90 ,
V_22 -> V_16 -> V_59 ) ;
if ( ! F_34 ( V_11 -> V_69 ) ||
V_22 == F_34 ( V_11 -> V_101 ) )
goto V_267;
}
continue;
case V_42 :
if ( V_22 -> V_197 < V_268 )
V_22 -> V_197 ++ ;
F_72 ( V_22 , V_42 ,
V_118 ) ;
F_76 ( V_22 ,
V_118 ) ;
F_71 ( V_11 -> V_16 , L_76 ,
V_22 -> V_16 -> V_59 ) ;
if ( V_22 == F_34 ( V_11 -> V_69 ) ) {
F_170 ( V_11 -> V_256 , NULL ) ;
goto V_267;
}
continue;
default:
F_60 ( V_11 -> V_16 , L_93 ,
V_22 -> V_264 , V_22 -> V_16 -> V_59 ) ;
continue;
}
V_267:
F_164 () ;
F_79 ( V_11 ) ;
F_165 () ;
}
F_18 ( V_11 ) ;
}
static bool F_235 ( struct V_10 * V_11 )
{
struct V_22 * V_22 , * V_321 = NULL , * V_208 = NULL ,
* V_300 = F_66 ( V_11 -> V_256 ) ,
* V_69 = F_66 ( V_11 -> V_69 ) ;
struct V_24 * V_25 ;
bool V_295 = false ;
bool V_322 = V_265 ;
if ( V_300 && V_69 )
F_71 ( V_11 -> V_16 , L_94 ,
V_300 -> V_16 -> V_59 ,
V_69 -> V_16 -> V_59 ) ;
if ( V_69 ) {
F_210 ( V_11 , V_69 ) ;
return V_322 ;
}
if ( ! V_300 ) {
V_300 = F_236 ( V_11 ) ;
if ( ! V_300 )
return V_322 ;
}
F_76 ( V_300 , V_265 ) ;
F_88 (bond, slave, iter) {
if ( ! V_295 && ! V_321 && F_63 ( V_22 ) )
V_321 = V_22 ;
if ( V_295 && ! V_208 && F_63 ( V_22 ) )
V_208 = V_22 ;
if ( ! F_63 ( V_22 ) && V_22 -> V_29 == V_30 ) {
F_72 ( V_22 , V_42 ,
V_265 ) ;
if ( V_22 -> V_197 < V_268 )
V_22 -> V_197 ++ ;
F_76 ( V_22 ,
V_265 ) ;
F_71 ( V_11 -> V_16 , L_95 ,
V_22 -> V_16 -> V_59 ) ;
}
if ( V_22 == V_300 )
V_295 = true ;
}
if ( ! V_208 && V_321 )
V_208 = V_321 ;
if ( ! V_208 )
goto V_323;
F_72 ( V_208 , V_43 ,
V_265 ) ;
F_77 ( V_208 , V_265 ) ;
F_210 ( V_11 , V_208 ) ;
V_208 -> V_115 = V_116 ;
F_78 ( V_11 -> V_256 , V_208 ) ;
V_323:
F_88 (bond, slave, iter) {
if ( V_22 -> V_324 || V_22 -> V_325 ) {
V_322 = V_118 ;
break;
}
}
return V_322 ;
}
static void F_237 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_39 ( V_71 , struct V_10 ,
V_318 . V_71 ) ;
bool V_119 = false ;
bool V_322 = false ;
int V_317 ;
V_317 = F_155 ( V_11 -> V_52 . V_239 ) ;
if ( ! F_19 ( V_11 ) )
goto V_270;
F_65 () ;
V_119 = F_64 ( V_11 ) ;
if ( F_233 ( V_11 ) ) {
F_67 () ;
if ( ! F_40 () ) {
V_317 = 1 ;
V_119 = false ;
goto V_270;
}
F_234 ( V_11 ) ;
F_43 () ;
F_65 () ;
}
V_322 = F_235 ( V_11 ) ;
F_67 () ;
V_270:
if ( V_11 -> V_52 . V_239 )
F_41 ( V_11 -> V_73 , & V_11 -> V_318 , V_317 ) ;
if ( V_119 || V_322 ) {
if ( ! F_40 () )
return;
if ( V_119 )
F_42 ( V_122 ,
V_11 -> V_16 ) ;
if ( V_322 ) {
F_238 ( V_11 ) ;
F_239 ( V_11 ) ;
}
F_43 () ;
}
}
static int F_240 ( struct V_10 * V_11 )
{
F_183 ( V_11 ) ;
F_241 ( V_11 ) ;
F_242 ( V_11 ) ;
return V_326 ;
}
static int F_243 ( unsigned long V_327 ,
struct V_14 * V_19 )
{
struct V_10 * V_328 = F_11 ( V_19 ) ;
switch ( V_327 ) {
case V_329 :
return F_240 ( V_328 ) ;
case V_330 :
F_183 ( V_328 ) ;
break;
case V_331 :
F_241 ( V_328 ) ;
break;
case V_122 :
if ( V_328 -> V_112 )
V_328 -> V_112 -- ;
break;
default:
break;
}
return V_326 ;
}
static int F_244 ( unsigned long V_327 ,
struct V_14 * V_15 )
{
struct V_22 * V_22 = F_245 ( V_15 ) , * V_243 ;
struct V_10 * V_11 ;
struct V_14 * V_19 ;
if ( ! V_22 )
return V_326 ;
V_19 = V_22 -> V_11 -> V_16 ;
V_11 = V_22 -> V_11 ;
V_243 = F_34 ( V_11 -> V_101 ) ;
switch ( V_327 ) {
case V_330 :
if ( V_19 -> type != V_218 )
F_182 ( V_19 , V_15 ) ;
else
F_181 ( V_19 , V_15 ) ;
break;
case V_332 :
case V_333 :
F_25 ( V_22 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_246 ( V_22 ) ;
case V_334 :
if ( F_166 ( V_11 ) )
F_167 ( V_11 , NULL ) ;
break;
case V_335 :
break;
case V_329 :
if ( ! F_33 ( V_11 ) ||
! V_11 -> V_52 . V_243 [ 0 ] )
break;
if ( V_22 == V_243 ) {
F_170 ( V_11 -> V_101 , NULL ) ;
} else if ( ! strcmp ( V_15 -> V_59 , V_11 -> V_52 . V_243 ) ) {
F_78 ( V_11 -> V_101 , V_22 ) ;
} else {
break;
}
F_71 ( V_11 -> V_16 , L_96 ,
V_243 ? V_15 -> V_59 : L_97 ) ;
F_164 () ;
F_79 ( V_11 ) ;
F_165 () ;
break;
case V_336 :
F_98 ( V_11 ) ;
break;
case V_74 :
F_42 ( V_327 , V_22 -> V_11 -> V_16 ) ;
break;
default:
break;
}
return V_326 ;
}
static int F_247 ( struct V_337 * V_338 ,
unsigned long V_327 , void * V_339 )
{
struct V_14 * V_340 = F_248 ( V_339 ) ;
F_54 ( V_340 , L_98 , V_327 ) ;
if ( ! ( V_340 -> V_160 & V_235 ) )
return V_326 ;
if ( V_340 -> V_82 & V_250 ) {
F_54 ( V_340 , L_99 ) ;
return F_243 ( V_327 , V_340 ) ;
}
if ( V_340 -> V_82 & V_188 ) {
F_54 ( V_340 , L_100 ) ;
return F_244 ( V_327 , V_340 ) ;
}
return V_326 ;
}
static inline T_8 F_249 ( struct V_12 * V_13 )
{
struct V_341 * V_342 , V_343 ;
V_342 = F_250 ( V_13 , 0 , sizeof( V_343 ) , & V_343 ) ;
if ( V_342 )
return V_342 -> V_177 [ 5 ] ^ V_342 -> V_344 [ 5 ] ^ V_342 -> V_345 ;
return 0 ;
}
static bool F_251 ( struct V_10 * V_11 , struct V_12 * V_13 ,
struct V_346 * V_347 )
{
const struct V_348 * V_349 ;
const struct V_350 * V_351 ;
int V_352 , V_20 = - 1 ;
if ( V_11 -> V_52 . V_353 > V_354 )
return F_252 ( V_13 , V_347 , 0 ) ;
V_347 -> V_355 . V_355 = 0 ;
V_352 = F_253 ( V_13 ) ;
if ( V_13 -> V_304 == F_225 ( V_311 ) ) {
if ( F_5 ( ! F_254 ( V_13 , V_352 + sizeof( * V_351 ) ) ) )
return false ;
V_351 = F_255 ( V_13 ) ;
F_256 ( V_347 , V_351 ) ;
V_352 += V_351 -> V_356 << 2 ;
if ( ! F_257 ( V_351 ) )
V_20 = V_351 -> V_304 ;
} else if ( V_13 -> V_304 == F_225 ( V_357 ) ) {
if ( F_5 ( ! F_254 ( V_13 , V_352 + sizeof( * V_349 ) ) ) )
return false ;
V_349 = F_258 ( V_13 ) ;
F_259 ( V_347 , V_349 ) ;
V_352 += sizeof( * V_349 ) ;
V_20 = V_349 -> V_358 ;
} else {
return false ;
}
if ( V_11 -> V_52 . V_353 == V_359 && V_20 >= 0 )
V_347 -> V_355 . V_355 = F_260 ( V_13 , V_352 , V_20 ) ;
return true ;
}
T_8 F_261 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
struct V_346 V_360 ;
T_8 V_361 ;
if ( V_11 -> V_52 . V_353 == V_362 &&
V_13 -> V_363 )
return V_13 -> V_361 ;
if ( V_11 -> V_52 . V_353 == V_364 ||
! F_251 ( V_11 , V_13 , & V_360 ) )
return F_249 ( V_13 ) ;
if ( V_11 -> V_52 . V_353 == V_354 ||
V_11 -> V_52 . V_353 == V_365 )
V_361 = F_249 ( V_13 ) ;
else
V_361 = ( V_366 T_8 ) V_360 . V_355 . V_355 ;
V_361 ^= ( V_366 T_8 ) F_262 ( & V_360 ) ^
( V_366 T_8 ) F_263 ( & V_360 ) ;
V_361 ^= ( V_361 >> 16 ) ;
V_361 ^= ( V_361 >> 8 ) ;
return V_361 ;
}
static void F_264 ( struct V_10 * V_11 )
{
F_134 ( & V_11 -> V_72 ,
F_38 ) ;
F_134 ( & V_11 -> V_367 , V_368 ) ;
F_134 ( & V_11 -> V_269 , F_190 ) ;
if ( F_20 ( V_11 ) == V_4 )
F_134 ( & V_11 -> V_318 , F_237 ) ;
else
F_134 ( & V_11 -> V_318 , F_231 ) ;
F_134 ( & V_11 -> V_369 , V_370 ) ;
F_134 ( & V_11 -> V_371 , V_372 ) ;
}
static void F_265 ( struct V_10 * V_11 )
{
F_266 ( & V_11 -> V_269 ) ;
F_266 ( & V_11 -> V_318 ) ;
F_266 ( & V_11 -> V_367 ) ;
F_266 ( & V_11 -> V_369 ) ;
F_266 ( & V_11 -> V_72 ) ;
F_266 ( & V_11 -> V_371 ) ;
}
static int F_267 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
if ( F_19 ( V_11 ) ) {
F_12 (bond, slave, iter) {
if ( F_33 ( V_11 ) &&
V_22 != F_159 ( V_11 -> V_69 ) ) {
F_76 ( V_22 ,
V_118 ) ;
} else if ( F_20 ( V_11 ) != V_7 ) {
F_77 ( V_22 ,
V_118 ) ;
}
}
}
F_264 ( V_11 ) ;
if ( F_16 ( V_11 ) ) {
if ( F_268 ( V_11 , ( F_20 ( V_11 ) == V_9 ) ) )
return - V_128 ;
if ( V_11 -> V_52 . V_373 )
F_41 ( V_11 -> V_73 , & V_11 -> V_367 , 0 ) ;
}
if ( V_11 -> V_52 . V_117 )
F_41 ( V_11 -> V_73 , & V_11 -> V_269 , 0 ) ;
if ( V_11 -> V_52 . V_239 ) {
F_41 ( V_11 -> V_73 , & V_11 -> V_318 , 0 ) ;
V_11 -> F_106 = F_217 ;
}
if ( F_20 ( V_11 ) == V_7 ) {
F_41 ( V_11 -> V_73 , & V_11 -> V_369 , 0 ) ;
V_11 -> F_106 = V_374 ;
F_269 ( V_11 , 1 ) ;
}
if ( F_166 ( V_11 ) )
F_167 ( V_11 , NULL ) ;
return 0 ;
}
static int F_270 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_265 ( V_11 ) ;
V_11 -> V_112 = 0 ;
if ( F_16 ( V_11 ) )
F_271 ( V_11 ) ;
V_11 -> F_106 = NULL ;
return 0 ;
}
static void F_272 ( struct V_375 * V_376 ,
const struct V_375 * V_377 ,
const struct V_375 * V_378 )
{
const T_9 * V_379 = ( const T_9 * ) V_377 ;
const T_9 * V_380 = ( const T_9 * ) V_378 ;
T_9 * V_26 = ( T_9 * ) V_376 ;
int V_212 ;
for ( V_212 = 0 ; V_212 < sizeof( * V_376 ) / sizeof( T_9 ) ; V_212 ++ ) {
T_9 V_381 = V_379 [ V_212 ] ;
T_9 V_382 = V_380 [ V_212 ] ;
if ( ( ( V_381 | V_382 ) >> 32 ) == 0 )
V_26 [ V_212 ] += ( T_8 ) V_381 - ( T_8 ) V_382 ;
else
V_26 [ V_212 ] += V_381 - V_382 ;
}
}
static void F_178 ( struct V_14 * V_19 ,
struct V_375 * V_383 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_375 V_384 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_273 ( & V_11 -> V_385 ) ;
memcpy ( V_383 , & V_11 -> V_255 , sizeof( * V_383 ) ) ;
F_65 () ;
F_88 (bond, slave, iter) {
const struct V_375 * V_379 =
F_148 ( V_22 -> V_16 , & V_384 ) ;
F_272 ( V_383 , V_379 , & V_22 -> V_236 ) ;
memcpy ( & V_22 -> V_236 , V_379 , sizeof( * V_379 ) ) ;
}
F_67 () ;
memcpy ( & V_11 -> V_255 , V_383 , sizeof( * V_383 ) ) ;
F_274 ( & V_11 -> V_385 ) ;
}
static int F_275 ( struct V_14 * V_19 , struct V_48 * V_49 , int V_386 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_14 * V_15 = NULL ;
struct V_190 V_387 ;
struct V_190 T_10 * V_388 = NULL ;
struct V_195 V_389 ;
struct V_195 T_10 * V_390 = NULL ;
struct V_50 * V_51 = NULL ;
struct V_391 V_392 ;
struct V_393 * V_393 ;
int V_26 = 0 ;
F_54 ( V_19 , L_101 , V_386 ) ;
switch ( V_386 ) {
case V_61 :
V_51 = F_31 ( V_49 ) ;
if ( ! V_51 )
return - V_221 ;
V_51 -> V_394 = 0 ;
case V_64 :
V_51 = F_31 ( V_49 ) ;
if ( ! V_51 )
return - V_221 ;
if ( V_51 -> V_62 == 1 ) {
V_51 -> V_65 = 0 ;
if ( F_22 ( V_11 -> V_16 ) )
V_51 -> V_65 = V_54 ;
}
return 0 ;
case V_395 :
case V_396 :
V_388 = (struct V_190 T_10 * ) V_49 -> V_397 ;
if ( F_276 ( & V_387 , V_388 , sizeof( V_190 ) ) )
return - V_398 ;
F_185 ( V_19 , & V_387 ) ;
if ( F_277 ( V_388 , & V_387 , sizeof( V_190 ) ) )
return - V_398 ;
return 0 ;
case V_399 :
case V_400 :
V_390 = (struct V_195 T_10 * ) V_49 -> V_397 ;
if ( F_276 ( & V_389 , V_390 , sizeof( V_195 ) ) )
return - V_398 ;
V_26 = F_186 ( V_19 , & V_389 ) ;
if ( V_26 == 0 &&
F_277 ( V_390 , & V_389 , sizeof( V_195 ) ) )
return - V_398 ;
return V_26 ;
default:
break;
}
V_393 = F_212 ( V_19 ) ;
if ( ! F_278 ( V_393 -> V_401 , V_402 ) )
return - V_214 ;
V_15 = F_279 ( V_393 , V_49 -> V_403 ) ;
F_54 ( V_19 , L_102 , V_15 ) ;
if ( ! V_15 )
return - V_259 ;
F_54 ( V_19 , L_103 , V_15 -> V_59 ) ;
switch ( V_386 ) {
case V_404 :
case V_405 :
V_26 = F_138 ( V_19 , V_15 ) ;
break;
case V_406 :
case V_407 :
V_26 = F_181 ( V_19 , V_15 ) ;
break;
case V_408 :
case V_409 :
F_53 ( V_19 , V_15 ) ;
V_26 = 0 ;
break;
case V_410 :
case V_411 :
F_280 ( & V_392 , V_15 -> V_59 ) ;
V_26 = F_281 ( V_11 , V_412 , & V_392 ) ;
break;
default:
V_26 = - V_223 ;
}
return V_26 ;
}
static void F_282 ( struct V_14 * V_19 , int V_413 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
if ( V_413 & V_83 )
F_32 ( V_11 ,
V_19 -> V_82 & V_83 ? 1 : - 1 ) ;
if ( V_413 & V_84 )
F_36 ( V_11 ,
V_19 -> V_82 & V_84 ? 1 : - 1 ) ;
}
static void F_283 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_65 () ;
if ( F_33 ( V_11 ) ) {
V_22 = F_66 ( V_11 -> V_69 ) ;
if ( V_22 ) {
F_50 ( V_22 -> V_16 , V_19 ) ;
F_51 ( V_22 -> V_16 , V_19 ) ;
}
} else {
F_88 (bond, slave, iter) {
F_151 ( V_22 -> V_16 , V_19 ) ;
F_150 ( V_22 -> V_16 , V_19 ) ;
}
}
F_67 () ;
}
static int F_284 ( struct V_414 * V_415 )
{
struct V_10 * V_11 = F_11 ( V_415 -> V_16 ) ;
const struct V_45 * V_46 ;
struct V_416 V_417 ;
struct V_22 * V_22 ;
int V_169 ;
V_22 = F_285 ( V_11 ) ;
if ( ! V_22 )
return 0 ;
V_46 = V_22 -> V_16 -> V_47 ;
if ( ! V_46 -> V_418 )
return 0 ;
V_417 . V_419 = NULL ;
V_417 . V_420 = NULL ;
V_169 = V_46 -> V_418 ( V_22 -> V_16 , & V_417 ) ;
if ( V_169 )
return V_169 ;
V_415 -> V_417 -> V_420 = V_417 . V_420 ;
if ( ! V_417 . V_419 )
return 0 ;
return V_417 . V_419 ( V_415 ) ;
}
static int F_286 ( struct V_14 * V_16 ,
struct V_416 * V_417 )
{
if ( V_417 -> V_16 == V_16 )
V_417 -> V_419 = F_284 ;
return 0 ;
}
static int F_287 ( struct V_14 * V_19 , int V_421 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_23 ;
struct V_24 * V_25 ;
int V_26 = 0 ;
F_54 ( V_19 , L_104 , V_11 , V_421 ) ;
F_12 (bond, slave, iter) {
F_54 ( V_19 , L_105 ,
V_22 , V_22 -> V_16 -> V_47 -> V_422 ) ;
V_26 = F_146 ( V_22 -> V_16 , V_421 ) ;
if ( V_26 ) {
F_54 ( V_19 , L_106 , V_26 ,
V_22 -> V_16 -> V_59 ) ;
goto V_27;
}
}
V_19 -> V_230 = V_421 ;
return 0 ;
V_27:
F_12 (bond, rollback_slave, iter) {
int V_423 ;
if ( V_23 == V_22 )
break;
V_423 = F_146 ( V_23 -> V_16 , V_19 -> V_230 ) ;
if ( V_423 ) {
F_54 ( V_19 , L_107 ,
V_423 , V_23 -> V_16 -> V_59 ) ;
}
}
return V_26 ;
}
static int F_288 ( struct V_14 * V_19 , void * V_210 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_23 ;
struct V_91 * V_424 = V_210 , V_425 ;
struct V_24 * V_25 ;
int V_26 = 0 ;
if ( F_20 ( V_11 ) == V_9 )
return F_289 ( V_19 , V_210 ) ;
F_54 ( V_19 , L_108 , V_11 ) ;
if ( V_11 -> V_52 . V_94 &&
F_20 ( V_11 ) == V_4 )
return 0 ;
if ( ! F_290 ( V_424 -> V_97 ) )
return - V_426 ;
F_12 (bond, slave, iter) {
F_54 ( V_19 , L_109 , V_22 , V_22 -> V_16 -> V_59 ) ;
V_26 = F_59 ( V_22 -> V_16 , V_210 ) ;
if ( V_26 ) {
F_54 ( V_19 , L_106 , V_26 , V_22 -> V_16 -> V_59 ) ;
goto V_27;
}
}
memcpy ( V_19 -> V_86 , V_424 -> V_97 , V_19 -> V_85 ) ;
return 0 ;
V_27:
memcpy ( V_425 . V_97 , V_19 -> V_86 , V_19 -> V_85 ) ;
V_425 . V_98 = V_19 -> type ;
F_12 (bond, rollback_slave, iter) {
int V_423 ;
if ( V_23 == V_22 )
break;
V_423 = F_59 ( V_23 -> V_16 , & V_425 ) ;
if ( V_423 ) {
F_54 ( V_19 , L_107 ,
V_423 , V_23 -> V_16 -> V_59 ) ;
}
}
return V_26 ;
}
static void F_291 ( struct V_10 * V_11 , struct V_12 * V_13 , int V_260 )
{
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_212 = V_260 ;
F_88 (bond, slave, iter) {
if ( -- V_212 < 0 ) {
if ( F_292 ( V_22 ) ) {
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
return;
}
}
}
V_212 = V_260 ;
F_88 (bond, slave, iter) {
if ( -- V_212 < 0 )
break;
if ( F_292 ( V_22 ) ) {
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
return;
}
}
F_293 ( V_11 -> V_16 , V_13 ) ;
}
static T_8 F_294 ( struct V_10 * V_11 )
{
T_8 V_260 ;
struct V_427 V_428 ;
int V_429 = V_11 -> V_52 . V_429 ;
switch ( V_429 ) {
case 0 :
V_260 = F_295 () ;
break;
case 1 :
V_260 = V_11 -> V_430 ;
break;
default:
V_428 =
V_11 -> V_52 . V_428 ;
V_260 = F_296 ( V_11 -> V_430 ,
V_428 ) ;
break;
}
V_11 -> V_430 ++ ;
return V_260 ;
}
static int F_297 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_350 * V_351 = F_255 ( V_13 ) ;
struct V_22 * V_22 ;
T_8 V_260 ;
if ( V_351 -> V_304 == V_431 && V_13 -> V_304 == F_225 ( V_311 ) ) {
V_22 = F_66 ( V_11 -> V_69 ) ;
if ( V_22 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_291 ( V_11 , V_13 , 0 ) ;
} else {
int V_194 = F_109 ( V_11 -> V_194 ) ;
if ( F_298 ( V_194 ) ) {
V_260 = F_294 ( V_11 ) ;
F_291 ( V_11 , V_13 , V_260 % V_194 ) ;
} else {
F_293 ( V_19 , V_13 ) ;
}
}
return V_432 ;
}
static int F_299 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 ;
V_22 = F_66 ( V_11 -> V_69 ) ;
if ( V_22 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_293 ( V_19 , V_13 ) ;
return V_432 ;
}
void F_300 ( struct V_10 * V_11 , unsigned long V_111 )
{
F_41 ( V_11 -> V_73 , & V_11 -> V_371 , V_111 ) ;
}
static void V_372 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_39 ( V_71 , struct V_10 ,
V_371 . V_71 ) ;
int V_169 ;
if ( ! F_40 () )
goto V_67;
V_169 = F_167 ( V_11 , NULL ) ;
F_43 () ;
if ( V_169 ) {
F_301 ( L_110 ) ;
goto V_67;
}
return;
V_67:
F_300 ( V_11 , 1 ) ;
}
int F_167 ( struct V_10 * V_11 , struct V_22 * V_433 )
{
struct V_22 * V_22 ;
struct V_24 * V_25 ;
struct V_434 * V_435 , * V_436 ;
int V_437 = 0 ;
int V_169 = 0 ;
#ifdef F_302
F_303 ( F_304 ( & V_11 -> V_438 ) ) ;
#endif
V_435 = F_81 ( F_305 ( struct V_434 , V_439 [ V_11 -> V_194 ] ) ,
V_127 ) ;
if ( ! V_435 ) {
V_169 = - V_128 ;
F_306 ( L_111 ) ;
goto V_99;
}
if ( F_20 ( V_11 ) == V_7 ) {
struct V_129 V_129 ;
if ( F_87 ( V_11 , & V_129 ) ) {
F_307 ( L_112 ) ;
F_308 ( V_435 , V_440 ) ;
V_436 = F_34 ( V_11 -> V_441 ) ;
if ( V_436 ) {
F_170 ( V_11 -> V_441 , NULL ) ;
F_308 ( V_436 , V_440 ) ;
}
goto V_99;
}
V_437 = V_129 . V_138 ;
}
F_12 (bond, slave, iter) {
if ( F_20 ( V_11 ) == V_7 ) {
struct V_134 * V_135 ;
V_135 = F_89 ( V_22 ) -> V_136 . V_134 ;
if ( ! V_135 || V_135 -> V_137 != V_437 )
continue;
}
if ( ! F_292 ( V_22 ) )
continue;
if ( V_433 == V_22 )
continue;
V_435 -> V_439 [ V_435 -> V_442 ++ ] = V_22 ;
}
V_436 = F_34 ( V_11 -> V_441 ) ;
F_78 ( V_11 -> V_441 , V_435 ) ;
if ( V_436 )
F_308 ( V_436 , V_440 ) ;
V_99:
if ( V_169 != 0 && V_433 ) {
int V_443 ;
V_436 = F_34 ( V_11 -> V_441 ) ;
for ( V_443 = 0 ; V_443 < V_436 -> V_442 ; V_443 ++ ) {
if ( V_433 == V_436 -> V_439 [ V_443 ] ) {
V_436 -> V_439 [ V_443 ] =
V_436 -> V_439 [ V_436 -> V_442 - 1 ] ;
V_436 -> V_442 -- ;
break;
}
}
}
return V_169 ;
}
static int F_309 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
struct V_22 * V_22 ;
struct V_434 * V_444 ;
unsigned int V_442 ;
V_444 = F_66 ( V_11 -> V_441 ) ;
V_442 = V_444 ? F_109 ( V_444 -> V_442 ) : 0 ;
if ( F_298 ( V_442 ) ) {
V_22 = V_444 -> V_439 [ F_261 ( V_11 , V_13 ) % V_442 ] ;
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
} else {
F_293 ( V_16 , V_13 ) ;
}
return V_432 ;
}
static int F_310 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 = NULL ;
struct V_24 * V_25 ;
F_88 (bond, slave, iter) {
if ( F_311 ( V_11 , V_22 ) )
break;
if ( F_63 ( V_22 ) && V_22 -> V_29 == V_30 ) {
struct V_12 * V_445 = F_312 ( V_13 , V_171 ) ;
if ( ! V_445 ) {
F_197 ( L_113 ,
V_19 -> V_59 , V_446 ) ;
continue;
}
F_2 ( V_11 , V_445 , V_22 -> V_16 ) ;
}
}
if ( V_22 && F_63 ( V_22 ) && V_22 -> V_29 == V_30 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_293 ( V_19 , V_13 ) ;
return V_432 ;
}
static inline int F_313 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_22 * V_22 = NULL ;
struct V_24 * V_25 ;
if ( ! V_13 -> V_17 )
return 1 ;
F_88 (bond, slave, iter) {
if ( V_22 -> V_228 == V_13 -> V_17 ) {
if ( F_63 ( V_22 ) &&
V_22 -> V_29 == V_30 ) {
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
return 0 ;
}
break;
}
}
return 1 ;
}
static T_2 F_314 ( struct V_14 * V_16 , struct V_12 * V_13 ,
void * V_447 , T_11 V_448 )
{
T_2 V_449 = F_315 ( V_13 ) ? F_316 ( V_13 ) : 0 ;
F_4 ( V_13 ) -> V_18 = V_13 -> V_17 ;
if ( F_5 ( V_449 >= V_16 -> V_450 ) ) {
do {
V_449 -= V_16 -> V_450 ;
} while ( V_449 >= V_16 -> V_450 );
}
return V_449 ;
}
static T_12 F_317 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
if ( F_318 ( V_11 ) &&
! F_313 ( V_11 , V_13 ) )
return V_432 ;
switch ( F_20 ( V_11 ) ) {
case V_3 :
return F_297 ( V_13 , V_16 ) ;
case V_4 :
return F_299 ( V_13 , V_16 ) ;
case V_7 :
case V_5 :
return F_309 ( V_13 , V_16 ) ;
case V_6 :
return F_310 ( V_13 , V_16 ) ;
case V_9 :
return F_319 ( V_13 , V_16 ) ;
case V_8 :
return F_320 ( V_13 , V_16 ) ;
default:
F_60 ( V_16 , L_114 , F_20 ( V_11 ) ) ;
F_321 ( 1 ) ;
F_293 ( V_16 , V_13 ) ;
return V_432 ;
}
}
static T_12 F_322 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
T_12 V_169 = V_432 ;
if ( F_5 ( F_323 ( V_16 ) ) )
return V_451 ;
F_65 () ;
if ( F_19 ( V_11 ) )
V_169 = F_317 ( V_13 , V_16 ) ;
else
F_293 ( V_16 , V_13 ) ;
F_67 () ;
return V_169 ;
}
static int F_324 ( struct V_14 * V_19 ,
struct V_31 * V_386 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
unsigned long V_33 = 0 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
V_386 -> V_37 . V_35 = V_36 ;
V_386 -> V_37 . V_136 = V_452 ;
F_12 (bond, slave, iter) {
if ( F_292 ( V_22 ) ) {
if ( V_22 -> V_33 != V_34 )
V_33 += V_22 -> V_33 ;
if ( V_386 -> V_37 . V_35 == V_36 &&
V_22 -> V_35 != V_36 )
V_386 -> V_37 . V_35 = V_22 -> V_35 ;
}
}
V_386 -> V_37 . V_33 = V_33 ? : V_34 ;
return 0 ;
}
static void F_325 ( struct V_14 * V_19 ,
struct V_453 * V_454 )
{
F_326 ( V_454 -> V_455 , V_456 , sizeof( V_454 -> V_455 ) ) ;
F_326 ( V_454 -> V_457 , V_458 , sizeof( V_454 -> V_457 ) ) ;
snprintf ( V_454 -> V_459 , sizeof( V_454 -> V_459 ) , L_115 ,
V_460 ) ;
}
static void F_327 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
if ( V_11 -> V_73 )
F_328 ( V_11 -> V_73 ) ;
F_329 ( V_19 ) ;
}
void F_330 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_331 ( & V_11 -> V_438 ) ;
F_331 ( & V_11 -> V_385 ) ;
V_11 -> V_52 = V_461 ;
V_11 -> V_16 = V_19 ;
F_145 ( V_19 ) ;
V_19 -> V_462 = V_463 ;
V_19 -> V_47 = & V_464 ;
V_19 -> V_55 = & V_465 ;
V_19 -> V_466 = F_327 ;
F_332 ( V_19 , & V_467 ) ;
V_19 -> V_82 |= V_250 ;
V_19 -> V_160 |= V_235 | V_468 | V_469 ;
V_19 -> V_160 &= ~ ( V_146 | V_219 ) ;
V_19 -> V_141 |= V_470 ;
V_19 -> V_141 |= V_471 ;
V_19 -> V_472 = V_149 |
V_473 |
V_474 |
V_475 ;
V_19 -> V_472 |= V_162 ;
V_19 -> V_141 |= V_19 -> V_472 ;
}
static void F_333 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
struct V_434 * V_439 ;
F_93 ( V_19 ) ;
F_12 (bond, slave, iter)
F_175 ( V_19 , V_22 -> V_16 , true ) ;
F_71 ( V_19 , L_116 ) ;
V_439 = F_34 ( V_11 -> V_441 ) ;
if ( V_439 ) {
F_170 ( V_11 -> V_441 , NULL ) ;
F_308 ( V_439 , V_440 ) ;
}
F_334 ( & V_11 -> V_476 ) ;
F_335 ( V_11 ) ;
}
static int F_336 ( struct V_477 * V_52 )
{
int V_478 , V_479 , V_480 , V_212 ;
struct V_391 V_392 ;
const struct V_391 * V_481 ;
int V_482 ;
T_2 V_483 = 0 ;
T_2 V_484 = 0 ;
if ( V_1 ) {
F_280 ( & V_392 , V_1 ) ;
V_481 = F_337 ( F_338 ( V_485 ) , & V_392 ) ;
if ( ! V_481 ) {
F_306 ( L_117 , V_1 ) ;
return - V_221 ;
}
V_192 = V_481 -> V_486 ;
}
if ( V_487 ) {
if ( ( V_192 != V_5 ) &&
( V_192 != V_7 ) &&
( V_192 != V_8 ) ) {
F_339 ( L_118 ,
F_1 ( V_192 ) ) ;
} else {
F_280 ( & V_392 , V_487 ) ;
V_481 = F_337 ( F_338 ( V_488 ) ,
& V_392 ) ;
if ( ! V_481 ) {
F_306 ( L_119 ,
V_487 ) ;
return - V_221 ;
}
V_489 = V_481 -> V_486 ;
}
}
if ( V_490 ) {
if ( V_192 != V_7 ) {
F_339 ( L_120 ,
F_1 ( V_192 ) ) ;
} else {
F_280 ( & V_392 , V_490 ) ;
V_481 = F_337 ( F_338 ( V_491 ) ,
& V_392 ) ;
if ( ! V_481 ) {
F_306 ( L_121 ,
V_490 ) ;
return - V_221 ;
}
V_492 = V_481 -> V_486 ;
}
}
if ( V_493 ) {
F_280 ( & V_392 , V_493 ) ;
V_481 = F_337 ( F_338 ( V_494 ) ,
& V_392 ) ;
if ( ! V_481 ) {
F_306 ( L_122 , V_493 ) ;
return - V_221 ;
}
V_52 -> V_493 = V_481 -> V_486 ;
if ( V_192 != V_7 )
F_340 ( L_123 ) ;
} else {
V_52 -> V_493 = V_495 ;
}
if ( V_496 < 0 ) {
F_340 ( L_124 ,
V_496 , 0 , V_497 , V_498 ) ;
V_496 = V_498 ;
}
if ( V_117 < 0 ) {
F_340 ( L_125 ,
V_117 , V_497 ) ;
V_117 = 0 ;
}
if ( V_110 < 0 ) {
F_340 ( L_126 ,
V_110 , V_497 ) ;
V_110 = 0 ;
}
if ( V_266 < 0 ) {
F_340 ( L_127 ,
V_266 , V_497 ) ;
V_266 = 0 ;
}
if ( ( V_53 != 0 ) && ( V_53 != 1 ) ) {
F_340 ( L_128 ,
V_53 ) ;
V_53 = 1 ;
}
if ( V_120 < 0 || V_120 > 255 ) {
F_340 ( L_129 ,
V_120 ) ;
V_120 = 1 ;
}
if ( ! F_341 ( V_192 ) ) {
if ( ! V_117 ) {
F_340 ( L_130 ) ;
F_340 ( L_131 ) ;
V_117 = V_499 ;
}
}
if ( V_500 < 1 || V_500 > 255 ) {
F_340 ( L_132 ,
V_500 , V_501 ) ;
V_500 = V_501 ;
}
if ( ( V_502 != 0 ) && ( V_502 != 1 ) ) {
F_340 ( L_133 ,
V_502 ) ;
V_502 = 0 ;
}
if ( V_123 < 0 || V_123 > 255 ) {
F_340 ( L_134 ,
V_123 , V_503 ) ;
V_123 = V_503 ;
}
F_342 ( & V_392 , V_429 ) ;
if ( ! F_337 ( F_338 ( V_504 ) , & V_392 ) ) {
F_340 ( L_135 ,
V_429 , V_505 ) ;
V_429 = 1 ;
}
if ( V_192 == V_9 ) {
F_343 ( L_136 ,
V_110 ) ;
}
if ( ! V_117 ) {
if ( V_110 || V_266 ) {
F_340 ( L_137 ,
V_110 , V_266 ) ;
}
} else {
if ( V_239 ) {
F_340 ( L_138 ,
V_117 , V_239 ) ;
V_239 = 0 ;
}
if ( ( V_110 % V_117 ) != 0 ) {
F_340 ( L_139 ,
V_110 , V_117 , ( V_110 / V_117 ) * V_117 ) ;
}
V_110 /= V_117 ;
if ( ( V_266 % V_117 ) != 0 ) {
F_340 ( L_140 ,
V_266 , V_117 ,
( V_266 / V_117 ) * V_117 ) ;
}
V_266 /= V_117 ;
}
if ( V_239 < 0 ) {
F_340 ( L_141 ,
V_239 , V_497 ) ;
V_239 = 0 ;
}
for ( V_506 = 0 , V_212 = 0 ;
( V_506 < V_240 ) && V_507 [ V_212 ] ; V_212 ++ ) {
T_7 V_272 ;
if ( ! F_344 ( V_507 [ V_212 ] , - 1 , ( T_4 * ) & V_272 , - 1 , NULL ) ||
! F_345 ( V_272 ) ) {
F_340 ( L_142 ,
V_507 [ V_212 ] ) ;
V_239 = 0 ;
} else {
if ( F_216 ( V_508 , V_272 ) == - 1 )
V_508 [ V_506 ++ ] = V_272 ;
else
F_340 ( L_143 ,
& V_272 ) ;
}
}
if ( V_239 && ! V_506 ) {
F_340 ( L_144 ,
V_239 ) ;
V_239 = 0 ;
}
if ( V_292 ) {
if ( ! V_239 ) {
F_306 ( L_145 ) ;
return - V_221 ;
}
F_280 ( & V_392 , V_292 ) ;
V_481 = F_337 ( F_338 ( V_509 ) ,
& V_392 ) ;
if ( ! V_481 ) {
F_306 ( L_146 ,
V_292 ) ;
return - V_221 ;
}
V_478 = V_481 -> V_486 ;
} else {
V_478 = 0 ;
}
V_482 = 0 ;
if ( V_510 ) {
F_280 ( & V_392 , V_510 ) ;
V_481 = F_337 ( F_338 ( V_511 ) ,
& V_392 ) ;
if ( ! V_481 ) {
F_306 ( L_147 ,
V_510 ) ;
V_482 = 0 ;
} else {
V_482 = V_481 -> V_486 ;
}
}
if ( V_117 ) {
F_339 ( L_148 , V_117 ) ;
} else if ( V_239 ) {
V_481 = F_346 ( V_509 ,
V_478 ) ;
F_339 ( L_149 ,
V_239 , V_481 -> string , V_506 ) ;
for ( V_212 = 0 ; V_212 < V_506 ; V_212 ++ )
F_347 ( L_150 , V_507 [ V_212 ] ) ;
F_347 ( L_151 ) ;
} else if ( V_496 ) {
F_307 ( L_152 ) ;
}
if ( V_243 && ! F_348 ( V_192 ) ) {
F_340 ( L_153 ,
V_243 , F_1 ( V_192 ) ) ;
V_243 = NULL ;
}
if ( V_243 && V_104 ) {
F_280 ( & V_392 , V_104 ) ;
V_481 = F_337 ( F_338 ( V_512 ) ,
& V_392 ) ;
if ( ! V_481 ) {
F_306 ( L_154 ,
V_104 ) ;
return - V_221 ;
}
V_480 = V_481 -> V_486 ;
} else {
V_480 = V_105 ;
}
if ( V_94 ) {
F_280 ( & V_392 , V_94 ) ;
V_481 = F_337 ( F_338 ( V_513 ) ,
& V_392 ) ;
if ( ! V_481 ) {
F_306 ( L_155 ,
V_94 ) ;
return - V_221 ;
}
V_479 = V_481 -> V_486 ;
if ( V_192 != V_4 )
F_340 ( L_156 ) ;
} else {
V_479 = V_514 ;
}
F_280 ( & V_392 , L_157 ) ;
V_481 = F_337 (
F_338 ( V_515 ) ,
& V_392 ) ;
if ( ! V_481 ) {
F_306 ( L_158 ) ;
return - V_221 ;
}
V_483 = V_481 -> V_486 ;
V_481 = F_337 ( F_338 ( V_516 ) ,
& V_392 ) ;
if ( ! V_481 ) {
F_306 ( L_159 ) ;
return - V_221 ;
}
V_484 = V_481 -> V_486 ;
if ( V_517 == 0 ) {
F_340 ( L_160 ,
V_497 , V_518 ) ;
V_517 = V_518 ;
}
V_52 -> V_1 = V_192 ;
V_52 -> V_353 = V_489 ;
V_52 -> V_117 = V_117 ;
V_52 -> V_120 = V_120 ;
V_52 -> V_239 = V_239 ;
V_52 -> V_292 = V_478 ;
V_52 -> V_510 = V_482 ;
V_52 -> V_110 = V_110 ;
V_52 -> V_266 = V_266 ;
V_52 -> V_53 = V_53 ;
V_52 -> V_492 = V_492 ;
V_52 -> V_243 [ 0 ] = 0 ;
V_52 -> V_104 = V_480 ;
V_52 -> V_94 = V_479 ;
V_52 -> V_500 = V_500 ;
V_52 -> V_502 = V_502 ;
V_52 -> V_123 = V_123 ;
V_52 -> V_519 = V_519 ;
V_52 -> V_517 = V_517 ;
V_52 -> V_429 = V_429 ;
V_52 -> V_373 = 1 ;
V_52 -> V_483 = V_483 ;
F_349 ( V_52 -> V_520 ) ;
V_52 -> V_484 = V_484 ;
if ( V_429 > 0 ) {
V_52 -> V_428 =
V_427 ( V_429 ) ;
} else {
V_52 -> V_428 =
(struct V_427 ) { 0 } ;
}
if ( V_243 ) {
strncpy ( V_52 -> V_243 , V_243 , V_60 ) ;
V_52 -> V_243 [ V_60 - 1 ] = 0 ;
}
memcpy ( V_52 -> V_290 , V_508 , sizeof( V_508 ) ) ;
return 0 ;
}
static int F_350 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_521 * V_522 = F_351 ( F_212 ( V_19 ) , V_523 ) ;
F_54 ( V_19 , L_161 ) ;
V_11 -> V_73 = F_352 ( V_19 -> V_59 , V_524 ) ;
if ( ! V_11 -> V_73 )
return - V_128 ;
F_353 ( V_19 ) ;
F_354 ( & V_11 -> V_476 , & V_522 -> V_525 ) ;
F_355 ( V_11 ) ;
F_356 ( V_11 ) ;
if ( F_357 ( V_19 -> V_86 ) &&
V_19 -> V_87 == V_526 )
F_174 ( V_19 ) ;
return 0 ;
}
unsigned int F_358 ( void )
{
return V_500 ;
}
int F_359 ( struct V_393 * V_393 , const char * V_59 )
{
struct V_14 * V_19 ;
struct V_10 * V_11 ;
struct V_527 * V_528 ;
int V_26 ;
F_128 () ;
V_19 = F_360 ( sizeof( struct V_10 ) ,
V_59 ? V_59 : L_162 , V_529 ,
F_330 , V_500 ) ;
if ( ! V_19 ) {
F_306 ( L_163 , V_59 ) ;
F_43 () ;
return - V_128 ;
}
V_11 = F_11 ( V_19 ) ;
V_528 = & ( F_361 ( V_11 ) ) ;
V_528 -> V_530 = V_531 ;
F_362 ( V_19 , V_393 ) ;
V_19 -> V_532 = & V_533 ;
V_26 = F_363 ( V_19 ) ;
F_24 ( V_19 ) ;
F_43 () ;
if ( V_26 < 0 )
F_327 ( V_19 ) ;
return V_26 ;
}
static int T_13 F_364 ( struct V_393 * V_393 )
{
struct V_521 * V_522 = F_351 ( V_393 , V_523 ) ;
V_522 -> V_393 = V_393 ;
F_365 ( & V_522 -> V_525 ) ;
F_366 ( V_522 ) ;
F_367 ( V_522 ) ;
return 0 ;
}
static void T_14 F_368 ( struct V_393 * V_393 )
{
struct V_521 * V_522 = F_351 ( V_393 , V_523 ) ;
struct V_10 * V_11 , * V_534 ;
F_369 ( V_535 ) ;
F_370 ( V_522 ) ;
F_128 () ;
F_371 (bond, tmp_bond, &bn->dev_list, bond_list)
F_372 ( V_11 -> V_16 , & V_535 ) ;
F_373 ( & V_535 ) ;
F_43 () ;
F_374 ( V_522 ) ;
}
static int T_15 F_375 ( void )
{
int V_212 ;
int V_26 ;
F_339 ( L_164 , V_536 ) ;
V_26 = F_336 ( & V_461 ) ;
if ( V_26 )
goto V_99;
V_26 = F_376 ( & V_537 ) ;
if ( V_26 )
goto V_99;
V_26 = F_377 () ;
if ( V_26 )
goto V_538;
F_378 () ;
for ( V_212 = 0 ; V_212 < V_496 ; V_212 ++ ) {
V_26 = F_359 ( & V_539 , NULL ) ;
if ( V_26 )
goto V_67;
}
F_379 ( & V_540 ) ;
V_99:
return V_26 ;
V_67:
F_380 () ;
F_381 () ;
V_538:
F_382 ( & V_537 ) ;
goto V_99;
}
static void T_16 F_383 ( void )
{
F_384 ( & V_540 ) ;
F_380 () ;
F_381 () ;
F_382 ( & V_537 ) ;
#ifdef F_160
F_303 ( F_385 ( & V_541 ) ) ;
#endif
}
