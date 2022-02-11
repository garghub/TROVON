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
T_3 V_33 ;
int V_26 ;
V_22 -> V_34 = V_35 ;
V_22 -> V_36 = V_37 ;
V_26 = F_26 ( V_15 , & V_32 ) ;
if ( V_26 < 0 )
return;
V_33 = F_27 ( & V_32 ) ;
if ( V_33 == 0 || V_33 == ( ( V_38 ) - 1 ) )
return;
switch ( V_32 . V_36 ) {
case V_39 :
case V_40 :
break;
default:
return;
}
V_22 -> V_34 = V_33 ;
V_22 -> V_36 = V_32 . V_36 ;
return;
}
const char * F_28 ( T_4 V_29 )
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
static int F_29 ( struct V_10 * V_11 ,
struct V_14 * V_15 , int V_44 )
{
const struct V_45 * V_46 = V_15 -> V_47 ;
int (* F_30)( struct V_14 * , struct V_48 * , int );
struct V_48 V_49 ;
struct V_50 * V_51 ;
if ( ! V_44 && ! F_31 ( V_15 ) )
return 0 ;
if ( V_11 -> V_52 . V_53 )
return F_22 ( V_15 ) ? V_54 : 0 ;
if ( V_15 -> V_55 -> V_56 )
return V_15 -> V_55 -> V_56 ( V_15 ) ?
V_54 : 0 ;
F_30 = V_46 -> V_57 ;
if ( F_30 ) {
strncpy ( V_49 . V_58 , V_15 -> V_59 , V_60 ) ;
V_51 = F_32 ( & V_49 ) ;
if ( F_33 ( V_15 , & V_49 , V_61 ) == 0 ) {
V_51 -> V_62 = V_63 ;
if ( F_33 ( V_15 , & V_49 , V_64 ) == 0 )
return V_51 -> V_65 & V_54 ;
}
}
return V_44 ? - 1 : V_54 ;
}
static int F_34 ( struct V_10 * V_11 , int V_66 )
{
struct V_24 * V_25 ;
int V_67 = 0 ;
if ( F_35 ( V_11 ) ) {
struct V_22 * V_68 = F_36 ( V_11 -> V_69 ) ;
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
static int F_38 ( struct V_10 * V_11 , int V_66 )
{
struct V_24 * V_25 ;
int V_67 = 0 ;
if ( F_35 ( V_11 ) ) {
struct V_22 * V_68 = F_36 ( V_11 -> V_69 ) ;
if ( V_68 )
V_67 = F_39 ( V_68 -> V_16 , V_66 ) ;
} else {
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
V_67 = F_39 ( V_22 -> V_16 , V_66 ) ;
if ( V_67 )
return V_67 ;
}
}
return V_67 ;
}
static void F_40 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_41 ( V_71 , struct V_10 ,
V_72 . V_71 ) ;
if ( ! F_42 () ) {
F_43 ( V_11 -> V_73 , & V_11 -> V_72 , 1 ) ;
return;
}
F_44 ( V_74 , V_11 -> V_16 ) ;
if ( V_11 -> V_75 > 1 ) {
V_11 -> V_75 -- ;
F_43 ( V_11 -> V_73 , & V_11 -> V_72 , V_76 / 5 ) ;
}
F_45 () ;
}
static void F_46 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_47 ( V_15 , V_19 ) ;
F_48 ( V_15 , V_19 ) ;
if ( F_20 ( V_11 ) == V_7 ) {
T_5 V_77 [ V_78 ] = V_79 ;
F_49 ( V_15 , V_77 ) ;
}
}
static void F_50 ( struct V_10 * V_11 , struct V_22 * V_80 ,
struct V_22 * V_81 )
{
if ( V_81 ) {
if ( V_11 -> V_16 -> V_82 & V_83 )
F_37 ( V_81 -> V_16 , - 1 ) ;
if ( V_11 -> V_16 -> V_82 & V_84 )
F_39 ( V_81 -> V_16 , - 1 ) ;
F_46 ( V_11 -> V_16 , V_81 -> V_16 ) ;
}
if ( V_80 ) {
if ( V_11 -> V_16 -> V_82 & V_83 )
F_37 ( V_80 -> V_16 , 1 ) ;
if ( V_11 -> V_16 -> V_82 & V_84 )
F_39 ( V_80 -> V_16 , 1 ) ;
F_51 ( V_11 -> V_16 ) ;
F_52 ( V_80 -> V_16 , V_11 -> V_16 ) ;
F_53 ( V_80 -> V_16 , V_11 -> V_16 ) ;
F_54 ( V_11 -> V_16 ) ;
}
}
static void F_55 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
F_56 ( V_19 , L_13 ,
V_19 , V_15 , V_15 -> V_85 ) ;
memcpy ( V_19 -> V_86 , V_15 -> V_86 , V_15 -> V_85 ) ;
V_19 -> V_87 = V_88 ;
F_44 ( V_89 , V_19 ) ;
}
static struct V_22 * F_57 ( struct V_10 * V_11 ,
struct V_22 * V_80 )
{
struct V_22 * V_22 ;
struct V_24 * V_25 ;
F_12 (bond, slave, iter) {
if ( V_22 == V_80 )
continue;
if ( F_58 ( V_11 -> V_16 -> V_86 , V_22 -> V_16 -> V_86 ) )
return V_22 ;
}
return NULL ;
}
static void F_59 ( struct V_10 * V_11 ,
struct V_22 * V_80 ,
struct V_22 * V_81 )
{
T_5 V_90 [ V_78 ] ;
struct V_91 V_92 ;
int V_93 ;
switch ( V_11 -> V_52 . V_94 ) {
case V_95 :
if ( V_80 )
F_55 ( V_11 -> V_16 , V_80 -> V_16 ) ;
break;
case V_96 :
if ( ! V_80 )
return;
if ( ! V_81 )
V_81 = F_57 ( V_11 , V_80 ) ;
if ( V_81 ) {
F_60 ( V_90 , V_80 -> V_16 -> V_86 ) ;
F_60 ( V_92 . V_97 ,
V_81 -> V_16 -> V_86 ) ;
V_92 . V_98 = V_80 -> V_16 -> type ;
} else {
F_60 ( V_92 . V_97 , V_11 -> V_16 -> V_86 ) ;
V_92 . V_98 = V_11 -> V_16 -> type ;
}
V_93 = F_61 ( V_80 -> V_16 , & V_92 ) ;
if ( V_93 ) {
F_62 ( V_11 -> V_16 , L_14 ,
- V_93 , V_80 -> V_16 -> V_59 ) ;
goto V_99;
}
if ( ! V_81 )
goto V_99;
F_60 ( V_92 . V_97 , V_90 ) ;
V_92 . V_98 = V_81 -> V_16 -> type ;
V_93 = F_61 ( V_81 -> V_16 , & V_92 ) ;
if ( V_93 )
F_62 ( V_11 -> V_16 , L_14 ,
- V_93 , V_80 -> V_16 -> V_59 ) ;
V_99:
break;
default:
F_62 ( V_11 -> V_16 , L_15 ,
V_11 -> V_52 . V_94 ) ;
break;
}
}
static struct V_22 * F_63 ( struct V_10 * V_11 )
{
struct V_22 * V_100 = F_36 ( V_11 -> V_101 ) ;
struct V_22 * V_102 = F_36 ( V_11 -> V_69 ) ;
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
if ( V_100 -> V_34 < V_102 -> V_34 )
return V_102 ;
if ( V_100 -> V_34 == V_102 -> V_34 && V_100 -> V_36 <= V_102 -> V_36 )
return V_102 ;
return V_100 ;
case V_107 :
return V_102 ;
default:
F_62 ( V_11 -> V_16 , L_16 ,
V_11 -> V_52 . V_104 ) ;
return V_102 ;
}
}
static struct V_22 * F_64 ( struct V_10 * V_11 )
{
struct V_22 * V_22 , * V_108 = NULL ;
struct V_24 * V_25 ;
int V_109 = V_11 -> V_52 . V_110 ;
V_22 = F_63 ( V_11 ) ;
if ( V_22 )
return V_22 ;
F_12 (bond, slave, iter) {
if ( V_22 -> V_29 == V_30 )
return V_22 ;
if ( V_22 -> V_29 == V_43 && F_65 ( V_22 ) &&
V_22 -> V_111 < V_109 ) {
V_109 = V_22 -> V_111 ;
V_108 = V_22 ;
}
}
return V_108 ;
}
static bool F_66 ( struct V_10 * V_11 )
{
struct V_22 * V_22 ;
F_67 () ;
V_22 = F_68 ( V_11 -> V_69 ) ;
F_69 () ;
F_56 ( V_11 -> V_16 , L_17 ,
V_22 ? V_22 -> V_16 -> V_59 : L_18 ) ;
if ( ! V_22 || ! V_11 -> V_112 ||
! F_22 ( V_11 -> V_16 ) ||
F_70 ( V_113 , & V_22 -> V_16 -> V_114 ) )
return false ;
return true ;
}
void F_71 ( struct V_10 * V_11 , struct V_22 * V_80 )
{
struct V_22 * V_81 ;
F_72 () ;
V_81 = F_36 ( V_11 -> V_69 ) ;
if ( V_81 == V_80 )
return;
if ( V_80 ) {
V_80 -> V_115 = V_116 ;
if ( V_80 -> V_29 == V_43 ) {
if ( F_35 ( V_11 ) ) {
F_73 ( V_11 -> V_16 , L_19 ,
V_80 -> V_16 -> V_59 ,
( V_11 -> V_52 . V_110 - V_80 -> V_111 ) * V_11 -> V_52 . V_117 ) ;
}
V_80 -> V_111 = 0 ;
F_74 ( V_80 , V_30 ,
V_118 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_75 ( V_80 , V_30 ) ;
if ( F_16 ( V_11 ) )
F_76 ( V_11 , V_80 , V_30 ) ;
} else {
if ( F_35 ( V_11 ) ) {
F_73 ( V_11 -> V_16 , L_20 ,
V_80 -> V_16 -> V_59 ) ;
}
}
}
if ( F_35 ( V_11 ) )
F_50 ( V_11 , V_80 , V_81 ) ;
if ( F_16 ( V_11 ) ) {
F_77 ( V_11 , V_80 ) ;
if ( V_81 )
F_78 ( V_81 ,
V_118 ) ;
if ( V_80 )
F_79 ( V_80 ,
V_118 ) ;
} else {
F_80 ( V_11 -> V_69 , V_80 ) ;
}
if ( F_20 ( V_11 ) == V_4 ) {
if ( V_81 )
F_78 ( V_81 ,
V_118 ) ;
if ( V_80 ) {
bool V_119 = false ;
F_79 ( V_80 ,
V_118 ) ;
if ( V_11 -> V_52 . V_94 )
F_59 ( V_11 , V_80 ,
V_81 ) ;
if ( F_31 ( V_11 -> V_16 ) ) {
V_11 -> V_112 =
V_11 -> V_52 . V_120 ;
V_119 =
F_66 ( V_11 ) ;
}
F_44 ( V_121 , V_11 -> V_16 ) ;
if ( V_119 )
F_44 ( V_122 ,
V_11 -> V_16 ) ;
}
}
if ( F_31 ( V_11 -> V_16 ) && ( V_11 -> V_52 . V_123 > 0 ) &&
( ( F_35 ( V_11 ) && V_80 ) ||
F_20 ( V_11 ) == V_3 ) ) {
V_11 -> V_75 = V_11 -> V_52 . V_123 ;
F_43 ( V_11 -> V_73 , & V_11 -> V_72 , 1 ) ;
}
}
void F_81 ( struct V_10 * V_11 )
{
struct V_22 * V_124 ;
int V_93 ;
F_72 () ;
V_124 = F_64 ( V_11 ) ;
if ( V_124 != F_36 ( V_11 -> V_69 ) ) {
F_71 ( V_11 , V_124 ) ;
V_93 = F_18 ( V_11 ) ;
if ( ! V_93 )
return;
if ( F_22 ( V_11 -> V_16 ) ) {
F_73 ( V_11 -> V_16 , L_21 ) ;
} else {
F_73 ( V_11 -> V_16 , L_22 ) ;
}
}
}
static inline int F_82 ( struct V_22 * V_22 )
{
struct V_125 * V_126 ;
int V_67 = 0 ;
V_126 = F_83 ( sizeof( * V_126 ) , V_127 ) ;
V_67 = - V_128 ;
if ( ! V_126 )
goto V_99;
V_67 = F_84 ( V_126 , V_22 -> V_16 ) ;
if ( V_67 ) {
F_85 ( V_126 ) ;
goto V_99;
}
V_22 -> V_126 = V_126 ;
V_99:
return V_67 ;
}
static inline void F_86 ( struct V_22 * V_22 )
{
struct V_125 * V_126 = V_22 -> V_126 ;
if ( ! V_126 )
return;
V_22 -> V_126 = NULL ;
F_87 ( V_126 ) ;
}
static void F_88 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 = NULL ;
struct V_24 * V_25 ;
struct V_129 V_129 ;
struct V_130 * V_131 ;
const struct V_45 * V_132 ;
if ( F_20 ( V_11 ) == V_7 )
if ( F_89 ( V_11 , & V_129 ) )
return;
F_90 (bond, slave, iter) {
V_132 = V_22 -> V_16 -> V_47 ;
if ( ! F_65 ( V_22 ) || ! V_132 -> V_133 )
continue;
if ( F_20 ( V_11 ) == V_7 ) {
struct V_134 * V_135 =
F_91 ( V_22 ) -> V_136 . V_134 ;
if ( V_135 &&
V_135 -> V_137 != V_129 . V_138 )
continue;
}
V_131 = F_92 ( V_22 -> V_16 -> V_139 ) ;
if ( F_93 ( & V_131 -> V_140 ) )
continue;
V_132 -> V_133 ( V_22 -> V_16 ) ;
F_94 ( & V_131 -> V_140 ) ;
}
}
static void F_95 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter)
if ( F_65 ( V_22 ) )
F_86 ( V_22 ) ;
}
static int F_96 ( struct V_14 * V_16 , struct V_130 * V_131 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_67 = 0 ;
F_12 (bond, slave, iter) {
V_67 = F_82 ( V_22 ) ;
if ( V_67 ) {
F_95 ( V_16 ) ;
break;
}
}
return V_67 ;
}
static inline int F_82 ( struct V_22 * V_22 )
{
return 0 ;
}
static inline void F_86 ( struct V_22 * V_22 )
{
}
static void F_95 ( struct V_14 * V_19 )
{
}
static T_6 F_97 ( struct V_14 * V_16 ,
T_6 V_141 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
struct V_24 * V_25 ;
T_6 V_142 ;
struct V_22 * V_22 ;
V_142 = V_141 ;
V_141 &= ~ V_143 ;
V_141 |= V_144 ;
F_12 (bond, slave, iter) {
V_141 = F_98 ( V_141 ,
V_22 -> V_16 -> V_141 ,
V_142 ) ;
}
V_141 = F_99 ( V_141 , V_142 ) ;
return V_141 ;
}
static void F_100 ( struct V_10 * V_11 )
{
unsigned int V_145 = V_146 |
V_147 ;
T_6 V_148 = V_149 ;
T_6 V_150 = V_151 ;
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
V_148 = F_98 ( V_148 ,
V_22 -> V_16 -> V_148 , V_149 ) ;
V_150 = F_98 ( V_150 ,
V_22 -> V_16 -> V_159 ,
V_151 ) ;
V_145 &= V_22 -> V_16 -> V_160 ;
if ( V_22 -> V_16 -> V_161 > V_152 )
V_152 = V_22 -> V_16 -> V_161 ;
V_154 = F_101 ( V_154 , V_22 -> V_16 -> V_154 ) ;
V_156 = F_101 ( V_156 , V_22 -> V_16 -> V_156 ) ;
}
V_158:
V_19 -> V_148 = V_148 ;
V_19 -> V_159 = V_150 | V_162 ;
V_19 -> V_161 = V_152 ;
V_19 -> V_156 = V_156 ;
F_102 ( V_19 , V_154 ) ;
V_19 -> V_160 &= ~ V_146 ;
if ( ( V_19 -> V_160 & V_147 ) &&
V_145 == ( V_146 | V_147 ) )
V_19 -> V_160 |= V_146 ;
F_103 ( V_19 ) ;
}
static void F_104 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
V_19 -> V_163 = V_15 -> V_163 ;
V_19 -> type = V_15 -> type ;
V_19 -> V_161 = V_15 -> V_161 ;
V_19 -> V_85 = V_15 -> V_85 ;
memcpy ( V_19 -> V_164 , V_15 -> V_164 ,
V_15 -> V_85 ) ;
}
static bool F_105 ( struct V_12 * V_13 ,
struct V_22 * V_22 ,
struct V_10 * V_11 )
{
if ( F_106 ( V_22 ) ) {
if ( F_20 ( V_11 ) == V_9 &&
V_13 -> V_165 != V_166 &&
V_13 -> V_165 != V_167 )
return false ;
return true ;
}
return false ;
}
static T_7 F_107 ( struct V_12 * * V_168 )
{
struct V_12 * V_13 = * V_168 ;
struct V_22 * V_22 ;
struct V_10 * V_11 ;
int (* F_108)( const struct V_12 * , struct V_10 * ,
struct V_22 * );
int V_169 = V_170 ;
V_13 = F_109 ( V_13 , V_171 ) ;
if ( F_5 ( ! V_13 ) )
return V_172 ;
* V_168 = V_13 ;
V_22 = F_110 ( V_13 -> V_16 ) ;
V_11 = V_22 -> V_11 ;
F_108 = F_111 ( V_11 -> F_108 ) ;
if ( F_108 ) {
V_169 = F_108 ( V_13 , V_11 , V_22 ) ;
if ( V_169 == V_172 ) {
F_112 ( V_13 ) ;
return V_169 ;
}
}
if ( F_105 ( V_13 , V_22 , V_11 ) ) {
return V_173 ;
}
V_13 -> V_16 = V_11 -> V_16 ;
if ( F_20 ( V_11 ) == V_9 &&
V_11 -> V_16 -> V_160 & V_174 &&
V_13 -> V_165 == V_175 ) {
if ( F_5 ( F_113 ( V_13 ,
V_13 -> V_176 - F_114 ( V_13 ) ) ) ) {
F_115 ( V_13 ) ;
return V_172 ;
}
F_60 ( F_116 ( V_13 ) -> V_177 , V_11 -> V_16 -> V_86 ) ;
}
return V_169 ;
}
static enum V_178 F_117 ( struct V_10 * V_11 )
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
static int F_118 ( struct V_10 * V_11 , struct V_22 * V_22 )
{
struct V_184 V_185 ;
int V_67 ;
V_185 . V_186 = F_117 ( V_11 ) ;
V_67 = F_119 ( V_22 -> V_16 , V_11 -> V_16 , V_22 ,
& V_185 ) ;
if ( V_67 )
return V_67 ;
F_120 ( V_187 , V_22 -> V_16 , V_188 , V_127 ) ;
return 0 ;
}
static void F_121 ( struct V_10 * V_11 , struct V_22 * V_22 )
{
F_122 ( V_22 -> V_16 , V_11 -> V_16 ) ;
V_22 -> V_16 -> V_82 &= ~ V_188 ;
F_120 ( V_187 , V_22 -> V_16 , V_188 , V_127 ) ;
}
static struct V_22 * F_123 ( struct V_10 * V_11 )
{
struct V_22 * V_22 = NULL ;
V_22 = F_83 ( sizeof( struct V_22 ) , V_127 ) ;
if ( ! V_22 )
return NULL ;
if ( F_20 ( V_11 ) == V_7 ) {
F_91 ( V_22 ) = F_83 ( sizeof( struct V_189 ) ,
V_127 ) ;
if ( ! F_91 ( V_22 ) ) {
F_85 ( V_22 ) ;
return NULL ;
}
}
return V_22 ;
}
static void F_124 ( struct V_22 * V_22 )
{
struct V_10 * V_11 = F_125 ( V_22 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_85 ( F_91 ( V_22 ) ) ;
F_85 ( V_22 ) ;
}
static void F_126 ( struct V_10 * V_11 , struct V_190 * V_191 )
{
V_191 -> V_192 = F_20 ( V_11 ) ;
V_191 -> V_117 = V_11 -> V_52 . V_117 ;
V_191 -> V_193 = V_11 -> V_194 ;
}
static void F_127 ( struct V_22 * V_22 , struct V_195 * V_191 )
{
strcpy ( V_191 -> V_196 , V_22 -> V_16 -> V_59 ) ;
V_191 -> V_29 = V_22 -> V_29 ;
V_191 -> V_114 = F_128 ( V_22 ) ;
V_191 -> V_197 = V_22 -> V_197 ;
}
static void F_129 ( struct V_14 * V_16 ,
struct V_198 * V_191 )
{
F_130 () ;
F_131 ( V_16 , V_191 ) ;
F_45 () ;
}
static void F_132 ( struct V_70 * V_199 )
{
struct V_200 * V_201 =
F_41 ( V_199 , struct V_200 , V_71 . V_71 ) ;
F_129 ( V_201 -> V_16 , & V_201 -> V_202 ) ;
F_133 ( V_201 -> V_16 ) ;
F_85 ( V_201 ) ;
}
void F_134 ( struct V_22 * V_22 )
{
struct V_10 * V_11 = V_22 -> V_11 ;
struct V_200 * V_203 = F_83 ( sizeof( * V_203 ) , V_171 ) ;
if ( ! V_203 )
return;
F_135 ( V_22 -> V_16 ) ;
V_203 -> V_16 = V_22 -> V_16 ;
F_127 ( V_22 , & V_203 -> V_202 . V_22 ) ;
F_126 ( V_11 , & V_203 -> V_202 . V_204 ) ;
F_136 ( & V_203 -> V_71 , F_132 ) ;
F_43 ( V_22 -> V_11 -> V_73 , & V_203 -> V_71 , 0 ) ;
}
void F_137 ( struct V_22 * V_22 )
{
struct V_205 V_191 ;
V_191 . V_206 = V_22 -> V_29 == V_30 ||
V_22 -> V_29 == V_41 ;
V_191 . V_207 = F_138 ( V_22 ) ;
F_139 ( V_22 -> V_16 , & V_191 ) ;
}
int F_140 ( struct V_14 * V_19 , struct V_14 * V_15 )
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
F_141 ( V_19 , L_23 ,
V_15 -> V_59 ) ;
}
if ( V_15 -> V_82 & V_188 ) {
F_56 ( V_19 , L_24 ) ;
return - V_213 ;
}
if ( V_19 == V_15 ) {
F_62 ( V_19 , L_25 ) ;
return - V_214 ;
}
if ( V_15 -> V_141 & V_215 ) {
F_56 ( V_19 , L_26 ,
V_15 -> V_59 ) ;
if ( F_142 ( V_19 ) ) {
F_62 ( V_19 , L_27 ,
V_15 -> V_59 , V_19 -> V_59 ) ;
return - V_214 ;
} else {
F_141 ( V_19 , L_28 ,
V_15 -> V_59 , V_15 -> V_59 ,
V_19 -> V_59 ) ;
}
} else {
F_56 ( V_19 , L_29 ,
V_15 -> V_59 ) ;
}
if ( V_15 -> V_82 & V_216 ) {
F_62 ( V_19 , L_30 ,
V_15 -> V_59 ) ;
V_26 = - V_214 ;
goto V_217;
}
if ( ! F_19 ( V_11 ) ) {
if ( V_19 -> type != V_15 -> type ) {
F_56 ( V_19 , L_31 ,
V_19 -> type , V_15 -> type ) ;
V_26 = F_44 ( V_218 ,
V_19 ) ;
V_26 = F_143 ( V_26 ) ;
if ( V_26 ) {
F_62 ( V_19 , L_32 ) ;
V_26 = - V_213 ;
goto V_217;
}
F_144 ( V_19 ) ;
F_145 ( V_19 ) ;
if ( V_15 -> type != V_219 )
F_104 ( V_19 , V_15 ) ;
else {
F_146 ( V_19 ) ;
V_19 -> V_160 &= ~ V_220 ;
}
F_44 ( V_221 ,
V_19 ) ;
}
} else if ( V_19 -> type != V_15 -> type ) {
F_62 ( V_19 , L_33 ,
V_15 -> V_59 , V_15 -> type , V_19 -> type ) ;
V_26 = - V_222 ;
goto V_217;
}
if ( V_46 -> V_223 == NULL ) {
F_141 ( V_19 , L_34 ) ;
if ( F_20 ( V_11 ) == V_4 &&
V_11 -> V_52 . V_94 != V_95 ) {
if ( ! F_19 ( V_11 ) ) {
V_11 -> V_52 . V_94 = V_95 ;
F_141 ( V_19 , L_35 ) ;
} else {
F_62 ( V_19 , L_36 ) ;
V_26 = - V_224 ;
goto V_217;
}
}
}
F_44 ( V_225 , V_15 ) ;
if ( ! F_19 ( V_11 ) &&
V_11 -> V_16 -> V_87 == V_226 )
F_55 ( V_11 -> V_16 , V_15 ) ;
V_208 = F_123 ( V_11 ) ;
if ( ! V_208 ) {
V_26 = - V_128 ;
goto V_217;
}
V_208 -> V_11 = V_11 ;
V_208 -> V_16 = V_15 ;
V_208 -> V_227 = 0 ;
V_208 -> V_228 = V_15 -> V_229 ;
V_26 = F_147 ( V_15 , V_11 -> V_16 -> V_229 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_37 , V_26 ) ;
goto V_230;
}
F_60 ( V_208 -> V_231 , V_15 -> V_86 ) ;
if ( ! V_11 -> V_52 . V_94 ||
F_20 ( V_11 ) != V_4 ) {
memcpy ( V_210 . V_97 , V_19 -> V_86 , V_19 -> V_85 ) ;
V_210 . V_98 = V_15 -> type ;
V_26 = F_61 ( V_15 , & V_210 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_38 , V_26 ) ;
goto V_232;
}
}
V_15 -> V_82 |= V_188 ;
V_26 = F_148 ( V_15 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_39 , V_15 -> V_59 ) ;
goto V_233;
}
V_15 -> V_160 |= V_234 ;
F_149 ( V_208 -> V_16 , & V_208 -> V_235 ) ;
if ( F_16 ( V_11 ) ) {
V_26 = F_150 ( V_11 , V_208 ) ;
if ( V_26 )
goto V_236;
}
if ( ! F_35 ( V_11 ) ) {
if ( V_19 -> V_82 & V_83 ) {
V_26 = F_37 ( V_15 , 1 ) ;
if ( V_26 )
goto V_236;
}
if ( V_19 -> V_82 & V_84 ) {
V_26 = F_39 ( V_15 , 1 ) ;
if ( V_26 )
goto V_236;
}
F_51 ( V_19 ) ;
F_151 ( V_15 , V_19 ) ;
F_152 ( V_15 , V_19 ) ;
F_54 ( V_19 ) ;
}
if ( F_20 ( V_11 ) == V_7 ) {
T_5 V_77 [ V_78 ] = V_79 ;
F_153 ( V_15 , V_77 ) ;
}
V_26 = F_154 ( V_15 , V_19 ) ;
if ( V_26 ) {
F_62 ( V_19 , L_40 ,
V_15 -> V_59 ) ;
goto V_236;
}
V_209 = F_155 ( V_11 ) ;
V_208 -> V_111 = 0 ;
V_208 -> V_197 = 0 ;
F_25 ( V_208 ) ;
V_208 -> V_237 = V_116 -
( F_156 ( V_11 -> V_52 . V_238 ) + 1 ) ;
for ( V_212 = 0 ; V_212 < V_239 ; V_212 ++ )
V_208 -> V_240 [ V_212 ] = V_208 -> V_237 ;
if ( V_11 -> V_52 . V_117 && ! V_11 -> V_52 . V_53 ) {
V_211 = F_29 ( V_11 , V_15 , 1 ) ;
if ( ( V_211 == - 1 ) && ! V_11 -> V_52 . V_238 ) {
F_141 ( V_19 , L_41 ,
V_15 -> V_59 ) ;
} else if ( V_211 == - 1 ) {
F_141 ( V_19 , L_42 ,
V_15 -> V_59 ) ;
}
}
if ( V_11 -> V_52 . V_117 ) {
if ( F_29 ( V_11 , V_15 , 0 ) == V_54 ) {
if ( V_11 -> V_52 . V_110 ) {
F_74 ( V_208 ,
V_43 ,
V_118 ) ;
V_208 -> V_111 = V_11 -> V_52 . V_110 ;
} else {
F_74 ( V_208 ,
V_30 ,
V_118 ) ;
}
} else {
F_74 ( V_208 , V_42 ,
V_118 ) ;
}
} else if ( V_11 -> V_52 . V_238 ) {
F_74 ( V_208 ,
( F_22 ( V_15 ) ?
V_30 : V_42 ) ,
V_118 ) ;
} else {
F_74 ( V_208 , V_30 ,
V_118 ) ;
}
if ( V_208 -> V_29 != V_42 )
V_208 -> V_115 = V_116 ;
F_56 ( V_19 , L_43 ,
V_208 -> V_29 == V_42 ? L_44 :
( V_208 -> V_29 == V_30 ? L_45 : L_46 ) ) ;
if ( F_35 ( V_11 ) && V_11 -> V_52 . V_241 [ 0 ] ) {
if ( strcmp ( V_11 -> V_52 . V_241 , V_208 -> V_16 -> V_59 ) == 0 ) {
F_80 ( V_11 -> V_101 , V_208 ) ;
V_11 -> V_103 = true ;
}
}
switch ( F_20 ( V_11 ) ) {
case V_4 :
F_78 ( V_208 ,
V_118 ) ;
break;
case V_7 :
F_78 ( V_208 , V_118 ) ;
if ( ! V_209 ) {
F_91 ( V_208 ) -> V_242 = 1 ;
F_157 ( V_11 , 1000 / V_243 ) ;
} else {
F_91 ( V_208 ) -> V_242 =
F_91 ( V_209 ) -> V_242 + 1 ;
}
F_158 ( V_208 ) ;
break;
case V_8 :
case V_9 :
F_159 ( V_208 ) ;
F_78 ( V_208 , V_118 ) ;
break;
default:
F_56 ( V_19 , L_47 ) ;
F_159 ( V_208 ) ;
if ( ! F_160 ( V_11 -> V_69 ) &&
V_208 -> V_29 == V_30 )
F_80 ( V_11 -> V_69 , V_208 ) ;
break;
}
#ifdef F_161
V_15 -> V_139 = V_11 -> V_16 -> V_139 ;
if ( V_15 -> V_139 ) {
if ( F_82 ( V_208 ) ) {
F_73 ( V_19 , L_48 ) ;
V_26 = - V_213 ;
goto V_244;
}
}
#endif
if ( ! ( V_19 -> V_141 & V_245 ) )
F_162 ( V_15 ) ;
V_26 = F_163 ( V_15 , F_107 ,
V_208 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_49 , V_26 ) ;
goto V_244;
}
V_26 = F_118 ( V_11 , V_208 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_50 , V_26 ) ;
goto V_246;
}
V_26 = F_164 ( V_208 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_51 , V_26 ) ;
goto V_247;
}
V_11 -> V_194 ++ ;
F_100 ( V_11 ) ;
F_18 ( V_11 ) ;
if ( F_35 ( V_11 ) ) {
F_165 () ;
F_81 ( V_11 ) ;
F_166 () ;
}
if ( F_167 ( V_11 ) )
F_168 ( V_11 , NULL ) ;
F_73 ( V_19 , L_52 ,
V_15 -> V_59 ,
F_138 ( V_208 ) ? L_53 : L_54 ,
V_208 -> V_29 != V_42 ? L_55 : L_56 ) ;
F_134 ( V_208 ) ;
return 0 ;
V_247:
F_121 ( V_11 , V_208 ) ;
V_246:
F_169 ( V_15 ) ;
V_244:
if ( ! F_35 ( V_11 ) )
F_46 ( V_19 , V_15 ) ;
F_170 ( V_15 , V_19 ) ;
if ( F_160 ( V_11 -> V_101 ) == V_208 )
F_171 ( V_11 -> V_101 , NULL ) ;
if ( F_160 ( V_11 -> V_69 ) == V_208 ) {
F_165 () ;
F_71 ( V_11 , NULL ) ;
F_81 ( V_11 ) ;
F_166 () ;
}
F_172 () ;
F_86 ( V_208 ) ;
V_236:
V_15 -> V_160 &= ~ V_234 ;
F_173 ( V_15 ) ;
V_233:
V_15 -> V_82 &= ~ V_188 ;
if ( ! V_11 -> V_52 . V_94 ||
F_20 ( V_11 ) != V_4 ) {
F_60 ( V_210 . V_97 , V_208 -> V_231 ) ;
V_210 . V_98 = V_15 -> type ;
F_61 ( V_15 , & V_210 ) ;
}
V_232:
F_147 ( V_15 , V_208 -> V_228 ) ;
V_230:
F_124 ( V_208 ) ;
V_217:
if ( ! F_19 ( V_11 ) ) {
if ( F_174 ( V_19 -> V_86 ,
V_15 -> V_86 ) )
F_175 ( V_19 ) ;
if ( V_19 -> type != V_219 ) {
F_173 ( V_19 ) ;
F_146 ( V_19 ) ;
V_19 -> V_82 |= V_248 ;
V_19 -> V_160 &= ~ V_220 ;
}
}
return V_26 ;
}
static int F_176 ( struct V_14 * V_19 ,
struct V_14 * V_15 ,
bool V_249 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_250 ;
struct V_91 V_210 ;
int V_251 = V_19 -> V_82 ;
T_6 V_252 = V_19 -> V_141 ;
if ( ! ( V_15 -> V_82 & V_188 ) ||
! F_177 ( V_15 , V_19 ) ) {
F_56 ( V_19 , L_57 ,
V_15 -> V_59 ) ;
return - V_222 ;
}
F_165 () ;
V_22 = F_8 ( V_11 , V_15 ) ;
if ( ! V_22 ) {
F_73 ( V_19 , L_58 ,
V_15 -> V_59 ) ;
F_166 () ;
return - V_222 ;
}
F_78 ( V_22 , V_118 ) ;
F_178 ( V_22 ) ;
F_179 ( V_11 -> V_16 , & V_11 -> V_253 ) ;
F_121 ( V_11 , V_22 ) ;
F_169 ( V_15 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_180 ( V_22 ) ;
if ( F_167 ( V_11 ) )
F_168 ( V_11 , V_22 ) ;
F_73 ( V_19 , L_59 ,
F_138 ( V_22 ) ? L_60 : L_61 ,
V_15 -> V_59 ) ;
V_250 = F_160 ( V_11 -> V_69 ) ;
F_171 ( V_11 -> V_254 , NULL ) ;
if ( ! V_249 && ( ! V_11 -> V_52 . V_94 ||
F_20 ( V_11 ) != V_4 ) ) {
if ( F_174 ( V_19 -> V_86 , V_22 -> V_231 ) &&
F_19 ( V_11 ) )
F_141 ( V_19 , L_62 ,
V_15 -> V_59 , V_22 -> V_231 ,
V_19 -> V_59 , V_15 -> V_59 ) ;
}
if ( F_36 ( V_11 -> V_101 ) == V_22 )
F_171 ( V_11 -> V_101 , NULL ) ;
if ( V_250 == V_22 )
F_71 ( V_11 , NULL ) ;
if ( F_16 ( V_11 ) ) {
F_181 ( V_11 , V_22 ) ;
}
if ( V_249 ) {
F_171 ( V_11 -> V_69 , NULL ) ;
} else if ( V_250 == V_22 ) {
F_81 ( V_11 ) ;
}
if ( ! F_19 ( V_11 ) ) {
F_18 ( V_11 ) ;
F_175 ( V_19 ) ;
}
F_166 () ;
F_172 () ;
V_11 -> V_194 -- ;
if ( ! F_19 ( V_11 ) ) {
F_44 ( V_89 , V_11 -> V_16 ) ;
F_44 ( V_255 , V_11 -> V_16 ) ;
}
F_100 ( V_11 ) ;
if ( ! ( V_19 -> V_141 & V_215 ) &&
( V_252 & V_215 ) )
F_73 ( V_19 , L_63 ,
V_15 -> V_59 , V_19 -> V_59 ) ;
F_170 ( V_15 , V_19 ) ;
if ( ! F_35 ( V_11 ) ) {
if ( V_251 & V_83 )
F_37 ( V_15 , - 1 ) ;
if ( V_251 & V_84 )
F_39 ( V_15 , - 1 ) ;
F_46 ( V_19 , V_15 ) ;
}
F_86 ( V_22 ) ;
F_173 ( V_15 ) ;
if ( V_11 -> V_52 . V_94 != V_95 ||
F_20 ( V_11 ) != V_4 ) {
F_60 ( V_210 . V_97 , V_22 -> V_231 ) ;
V_210 . V_98 = V_15 -> type ;
F_61 ( V_15 , & V_210 ) ;
}
F_147 ( V_15 , V_22 -> V_228 ) ;
V_15 -> V_160 &= ~ V_234 ;
F_124 ( V_22 ) ;
return 0 ;
}
int F_182 ( struct V_14 * V_19 , struct V_14 * V_15 )
{
return F_176 ( V_19 , V_15 , false ) ;
}
static int F_183 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
int V_169 ;
V_169 = F_182 ( V_19 , V_15 ) ;
if ( V_169 == 0 && ! F_19 ( V_11 ) ) {
V_19 -> V_160 |= V_256 ;
F_73 ( V_19 , L_64 ,
V_19 -> V_59 ) ;
F_184 ( V_11 ) ;
F_185 ( V_19 ) ;
}
return V_169 ;
}
static int F_186 ( struct V_14 * V_19 , struct V_190 * V_191 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_126 ( V_11 , V_191 ) ;
return 0 ;
}
static int F_187 ( struct V_14 * V_19 , struct V_195 * V_191 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
int V_212 = 0 , V_26 = - V_257 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
if ( V_212 ++ == ( int ) V_191 -> V_258 ) {
V_26 = 0 ;
F_127 ( V_22 , V_191 ) ;
break;
}
}
return V_26 ;
}
static int F_188 ( struct V_10 * V_11 )
{
int V_259 , V_260 = 0 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
bool V_261 ;
V_261 = ! F_68 ( V_11 -> V_69 ) ;
F_90 (bond, slave, iter) {
V_22 -> V_262 = V_263 ;
V_259 = F_29 ( V_11 , V_22 -> V_16 , 0 ) ;
switch ( V_22 -> V_29 ) {
case V_30 :
if ( V_259 )
continue;
F_74 ( V_22 , V_41 ,
V_264 ) ;
V_22 -> V_111 = V_11 -> V_52 . V_265 ;
if ( V_22 -> V_111 ) {
F_73 ( V_11 -> V_16 , L_65 ,
( F_20 ( V_11 ) ==
V_4 ) ?
( F_138 ( V_22 ) ?
L_66 : L_67 ) : L_68 ,
V_22 -> V_16 -> V_59 ,
V_11 -> V_52 . V_265 * V_11 -> V_52 . V_117 ) ;
}
case V_41 :
if ( V_259 ) {
F_74 ( V_22 , V_30 ,
V_264 ) ;
V_22 -> V_115 = V_116 ;
F_73 ( V_11 -> V_16 , L_69 ,
( V_11 -> V_52 . V_265 - V_22 -> V_111 ) *
V_11 -> V_52 . V_117 ,
V_22 -> V_16 -> V_59 ) ;
continue;
}
if ( V_22 -> V_111 <= 0 ) {
V_22 -> V_262 = V_42 ;
V_260 ++ ;
continue;
}
V_22 -> V_111 -- ;
break;
case V_42 :
if ( ! V_259 )
continue;
F_74 ( V_22 , V_43 ,
V_264 ) ;
V_22 -> V_111 = V_11 -> V_52 . V_110 ;
if ( V_22 -> V_111 ) {
F_73 ( V_11 -> V_16 , L_70 ,
V_22 -> V_16 -> V_59 ,
V_261 ? 0 :
V_11 -> V_52 . V_110 *
V_11 -> V_52 . V_117 ) ;
}
case V_43 :
if ( ! V_259 ) {
F_74 ( V_22 ,
V_42 ,
V_264 ) ;
F_73 ( V_11 -> V_16 , L_71 ,
( V_11 -> V_52 . V_110 - V_22 -> V_111 ) *
V_11 -> V_52 . V_117 ,
V_22 -> V_16 -> V_59 ) ;
continue;
}
if ( V_261 )
V_22 -> V_111 = 0 ;
if ( V_22 -> V_111 <= 0 ) {
V_22 -> V_262 = V_30 ;
V_260 ++ ;
V_261 = false ;
continue;
}
V_22 -> V_111 -- ;
break;
}
}
return V_260 ;
}
static void F_189 ( struct V_10 * V_11 )
{
struct V_24 * V_25 ;
struct V_22 * V_22 , * V_241 ;
F_12 (bond, slave, iter) {
switch ( V_22 -> V_262 ) {
case V_263 :
continue;
case V_30 :
F_25 ( V_22 ) ;
F_74 ( V_22 , V_30 ,
V_118 ) ;
V_22 -> V_115 = V_116 ;
V_241 = F_36 ( V_11 -> V_101 ) ;
if ( F_20 ( V_11 ) == V_7 ) {
F_190 ( V_22 ) ;
} else if ( F_20 ( V_11 ) != V_4 ) {
F_159 ( V_22 ) ;
} else if ( V_22 != V_241 ) {
F_190 ( V_22 ) ;
}
F_73 ( V_11 -> V_16 , L_72 ,
V_22 -> V_16 -> V_59 ,
V_22 -> V_34 == V_35 ? 0 : V_22 -> V_34 ,
V_22 -> V_36 ? L_73 : L_74 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_75 ( V_22 , V_30 ) ;
if ( F_16 ( V_11 ) )
F_76 ( V_11 , V_22 ,
V_30 ) ;
if ( F_20 ( V_11 ) == V_5 )
F_168 ( V_11 , NULL ) ;
if ( ! V_11 -> V_69 || V_22 == V_241 )
goto V_266;
continue;
case V_42 :
if ( V_22 -> V_197 < V_267 )
V_22 -> V_197 ++ ;
F_74 ( V_22 , V_42 ,
V_118 ) ;
if ( F_20 ( V_11 ) == V_4 ||
F_20 ( V_11 ) == V_7 )
F_78 ( V_22 ,
V_118 ) ;
F_73 ( V_11 -> V_16 , L_75 ,
V_22 -> V_16 -> V_59 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_75 ( V_22 ,
V_42 ) ;
if ( F_16 ( V_11 ) )
F_76 ( V_11 , V_22 ,
V_42 ) ;
if ( F_20 ( V_11 ) == V_5 )
F_168 ( V_11 , NULL ) ;
if ( V_22 == F_160 ( V_11 -> V_69 ) )
goto V_266;
continue;
default:
F_62 ( V_11 -> V_16 , L_76 ,
V_22 -> V_262 , V_22 -> V_16 -> V_59 ) ;
V_22 -> V_262 = V_263 ;
continue;
}
V_266:
F_165 () ;
F_81 ( V_11 ) ;
F_166 () ;
}
F_18 ( V_11 ) ;
}
static void F_191 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_41 ( V_71 , struct V_10 ,
V_268 . V_71 ) ;
bool V_119 = false ;
unsigned long V_111 ;
V_111 = F_156 ( V_11 -> V_52 . V_117 ) ;
if ( ! F_19 ( V_11 ) )
goto V_269;
F_67 () ;
V_119 = F_66 ( V_11 ) ;
if ( F_188 ( V_11 ) ) {
F_69 () ;
if ( ! F_42 () ) {
V_111 = 1 ;
V_119 = false ;
goto V_269;
}
F_189 ( V_11 ) ;
F_45 () ;
} else
F_69 () ;
V_269:
if ( V_11 -> V_52 . V_117 )
F_43 ( V_11 -> V_73 , & V_11 -> V_268 , V_111 ) ;
if ( V_119 ) {
if ( ! F_42 () )
return;
F_44 ( V_122 , V_11 -> V_16 ) ;
F_45 () ;
}
}
static bool F_192 ( struct V_10 * V_11 , T_8 V_270 )
{
struct V_14 * V_271 ;
struct V_24 * V_25 ;
bool V_169 = false ;
if ( V_270 == F_193 ( V_11 -> V_16 , 0 , V_270 ) )
return true ;
F_67 () ;
F_194 (bond->dev, upper, iter) {
if ( V_270 == F_193 ( V_271 , 0 , V_270 ) ) {
V_169 = true ;
break;
}
}
F_69 () ;
return V_169 ;
}
static void F_195 ( struct V_14 * V_15 , int V_272 ,
T_8 V_273 , T_8 V_274 ,
struct V_275 * V_276 )
{
struct V_12 * V_13 ;
struct V_275 * V_277 = V_276 ;
F_56 ( V_15 , L_77 ,
V_272 , V_15 -> V_59 , & V_273 , & V_274 ) ;
V_13 = F_196 ( V_272 , V_278 , V_273 , V_15 , V_274 ,
NULL , V_15 -> V_86 , NULL ) ;
if ( ! V_13 ) {
F_197 ( L_78 ) ;
return;
}
if ( ! V_276 || V_276 -> V_279 == V_280 )
goto V_281;
V_276 ++ ;
while ( V_276 -> V_279 != V_280 ) {
if ( ! V_276 -> V_282 ) {
V_276 ++ ;
continue;
}
F_56 ( V_15 , L_79 ,
F_198 ( V_277 -> V_279 ) , V_276 -> V_282 ) ;
V_13 = F_199 ( V_13 , V_276 -> V_279 ,
V_276 -> V_282 ) ;
if ( ! V_13 ) {
F_197 ( L_80 ) ;
return;
}
V_276 ++ ;
}
if ( V_277 -> V_282 ) {
F_56 ( V_15 , L_81 ,
F_198 ( V_277 -> V_279 ) , V_277 -> V_282 ) ;
F_200 ( V_13 , V_277 -> V_279 ,
V_277 -> V_282 ) ;
}
V_281:
F_201 ( V_13 ) ;
}
struct V_275 * F_202 ( struct V_14 * V_283 ,
struct V_14 * V_284 ,
int V_285 )
{
struct V_275 * V_276 ;
struct V_14 * V_271 ;
struct V_24 * V_25 ;
if ( V_283 == V_284 ) {
V_276 = F_83 ( sizeof( * V_276 ) * ( V_285 + 1 ) , V_171 ) ;
if ( ! V_276 )
return F_203 ( - V_128 ) ;
V_276 [ V_285 ] . V_279 = V_280 ;
return V_276 ;
}
F_204 (start_dev, upper, iter) {
V_276 = F_202 ( V_271 , V_284 , V_285 + 1 ) ;
if ( F_205 ( V_276 ) ) {
if ( F_206 ( V_276 ) )
return V_276 ;
continue;
}
if ( F_207 ( V_271 ) ) {
V_276 [ V_285 ] . V_279 = F_208 ( V_271 ) ;
V_276 [ V_285 ] . V_282 = F_209 ( V_271 ) ;
}
return V_276 ;
}
return NULL ;
}
static void F_210 ( struct V_10 * V_11 , struct V_22 * V_22 )
{
struct V_286 * V_287 ;
struct V_275 * V_276 ;
T_8 * V_288 = V_11 -> V_52 . V_289 , V_210 ;
int V_212 ;
for ( V_212 = 0 ; V_212 < V_239 && V_288 [ V_212 ] ; V_212 ++ ) {
F_56 ( V_11 -> V_16 , L_82 , & V_288 [ V_212 ] ) ;
V_276 = NULL ;
V_287 = F_211 ( F_212 ( V_11 -> V_16 ) , V_288 [ V_212 ] , 0 ,
V_290 , 0 ) ;
if ( F_206 ( V_287 ) ) {
if ( V_11 -> V_52 . V_291 )
F_213 ( L_83 ,
V_11 -> V_16 -> V_59 ,
& V_288 [ V_212 ] ) ;
F_195 ( V_22 -> V_16 , V_292 , V_288 [ V_212 ] ,
0 , V_276 ) ;
continue;
}
if ( V_287 -> V_293 . V_16 == V_11 -> V_16 )
goto V_294;
F_67 () ;
V_276 = F_202 ( V_11 -> V_16 , V_287 -> V_293 . V_16 , 0 ) ;
F_69 () ;
if ( ! F_205 ( V_276 ) )
goto V_294;
F_56 ( V_11 -> V_16 , L_84 ,
& V_288 [ V_212 ] , V_287 -> V_293 . V_16 ? V_287 -> V_293 . V_16 -> V_59 : L_18 ) ;
F_214 ( V_287 ) ;
continue;
V_294:
V_210 = F_193 ( V_287 -> V_293 . V_16 , V_288 [ V_212 ] , 0 ) ;
F_214 ( V_287 ) ;
F_195 ( V_22 -> V_16 , V_292 , V_288 [ V_212 ] ,
V_210 , V_276 ) ;
F_85 ( V_276 ) ;
}
}
static void F_215 ( struct V_10 * V_11 , struct V_22 * V_22 , T_8 V_295 , T_8 V_296 )
{
int V_212 ;
if ( ! V_295 || ! F_192 ( V_11 , V_296 ) ) {
F_56 ( V_11 -> V_16 , L_85 ,
& V_295 , & V_296 ) ;
return;
}
V_212 = F_216 ( V_11 -> V_52 . V_289 , V_295 ) ;
if ( V_212 == - 1 ) {
F_56 ( V_11 -> V_16 , L_86 ,
& V_295 ) ;
return;
}
V_22 -> V_237 = V_116 ;
V_22 -> V_240 [ V_212 ] = V_116 ;
}
int F_217 ( const struct V_12 * V_13 , struct V_10 * V_11 ,
struct V_22 * V_22 )
{
struct V_297 * V_298 = (struct V_297 * ) V_13 -> V_176 ;
struct V_22 * V_69 , * V_299 ;
unsigned char * V_300 ;
T_8 V_295 , V_296 ;
int V_301 , V_302 = V_13 -> V_303 == F_218 ( V_278 ) ;
if ( ! F_219 ( V_11 , V_22 ) ) {
if ( ( F_220 ( V_11 ) && V_302 ) ||
! F_220 ( V_11 ) )
V_22 -> V_237 = V_116 ;
return V_170 ;
} else if ( ! V_302 ) {
return V_170 ;
}
V_301 = F_221 ( V_11 -> V_16 ) ;
F_56 ( V_11 -> V_16 , L_87 ,
V_13 -> V_16 -> V_59 ) ;
if ( V_301 > F_222 ( V_13 ) ) {
V_298 = F_223 ( V_301 , V_171 ) ;
if ( ! V_298 )
goto V_304;
if ( F_224 ( V_13 , 0 , V_298 , V_301 ) < 0 )
goto V_304;
}
if ( V_298 -> V_305 != V_11 -> V_16 -> V_85 ||
V_13 -> V_165 == V_306 ||
V_13 -> V_165 == V_307 ||
V_298 -> V_308 != F_225 ( V_219 ) ||
V_298 -> V_309 != F_225 ( V_310 ) ||
V_298 -> V_311 != 4 )
goto V_304;
V_300 = ( unsigned char * ) ( V_298 + 1 ) ;
V_300 += V_11 -> V_16 -> V_85 ;
memcpy ( & V_295 , V_300 , 4 ) ;
V_300 += 4 + V_11 -> V_16 -> V_85 ;
memcpy ( & V_296 , V_300 , 4 ) ;
F_56 ( V_11 -> V_16 , L_88 ,
V_22 -> V_16 -> V_59 , F_128 ( V_22 ) ,
V_11 -> V_52 . V_291 , F_219 ( V_11 , V_22 ) ,
& V_295 , & V_296 ) ;
V_69 = F_68 ( V_11 -> V_69 ) ;
V_299 = F_68 ( V_11 -> V_254 ) ;
if ( F_138 ( V_22 ) )
F_215 ( V_11 , V_22 , V_295 , V_296 ) ;
else if ( V_69 &&
F_226 ( F_227 ( V_11 , V_69 ) ,
V_69 -> V_115 ) )
F_215 ( V_11 , V_22 , V_296 , V_295 ) ;
else if ( V_299 && ( V_298 -> V_312 == F_225 ( V_313 ) ) &&
F_228 ( V_11 ,
F_229 ( V_299 -> V_16 ) , 1 ) )
F_215 ( V_11 , V_22 , V_295 , V_296 ) ;
V_304:
if ( V_298 != (struct V_297 * ) V_13 -> V_176 )
F_85 ( V_298 ) ;
return V_170 ;
}
static bool F_228 ( struct V_10 * V_11 , unsigned long V_314 ,
int V_315 )
{
int V_316 = F_156 ( V_11 -> V_52 . V_238 ) ;
return F_230 ( V_116 ,
V_314 - V_316 ,
V_314 + V_315 * V_316 + V_316 / 2 ) ;
}
static void F_231 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_41 ( V_71 , struct V_10 ,
V_317 . V_71 ) ;
struct V_22 * V_22 , * V_250 ;
struct V_24 * V_25 ;
int V_266 = 0 , V_318 = 0 ;
if ( ! F_19 ( V_11 ) )
goto V_269;
F_67 () ;
V_250 = F_68 ( V_11 -> V_69 ) ;
F_90 (bond, slave, iter) {
unsigned long V_319 = F_229 ( V_22 -> V_16 ) ;
if ( V_22 -> V_29 != V_30 ) {
if ( F_228 ( V_11 , V_319 , 1 ) &&
F_228 ( V_11 , V_22 -> V_237 , 1 ) ) {
V_22 -> V_29 = V_30 ;
V_318 = 1 ;
if ( ! V_250 ) {
F_73 ( V_11 -> V_16 , L_89 ,
V_22 -> V_16 -> V_59 ) ;
V_266 = 1 ;
} else {
F_73 ( V_11 -> V_16 , L_90 ,
V_22 -> V_16 -> V_59 ) ;
}
}
} else {
if ( ! F_228 ( V_11 , V_319 , 2 ) ||
! F_228 ( V_11 , V_22 -> V_237 , 2 ) ) {
V_22 -> V_29 = V_42 ;
V_318 = 1 ;
if ( V_22 -> V_197 < V_267 )
V_22 -> V_197 ++ ;
F_73 ( V_11 -> V_16 , L_91 ,
V_22 -> V_16 -> V_59 ) ;
if ( V_22 == V_250 )
V_266 = 1 ;
}
}
if ( F_65 ( V_22 ) )
F_210 ( V_11 , V_22 ) ;
}
F_69 () ;
if ( V_266 || V_318 ) {
if ( ! F_42 () )
goto V_269;
if ( V_318 ) {
F_232 ( V_11 ) ;
if ( F_20 ( V_11 ) == V_5 )
F_168 ( V_11 , NULL ) ;
}
if ( V_266 ) {
F_165 () ;
F_81 ( V_11 ) ;
F_166 () ;
}
F_45 () ;
}
V_269:
if ( V_11 -> V_52 . V_238 )
F_43 ( V_11 -> V_73 , & V_11 -> V_317 ,
F_156 ( V_11 -> V_52 . V_238 ) ) ;
}
static int F_233 ( struct V_10 * V_11 )
{
unsigned long V_319 , V_237 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_260 = 0 ;
F_90 (bond, slave, iter) {
V_22 -> V_262 = V_263 ;
V_237 = F_227 ( V_11 , V_22 ) ;
if ( V_22 -> V_29 != V_30 ) {
if ( F_228 ( V_11 , V_237 , 1 ) ) {
V_22 -> V_262 = V_30 ;
V_260 ++ ;
}
continue;
}
if ( F_228 ( V_11 , V_22 -> V_115 , 2 ) )
continue;
if ( ! F_138 ( V_22 ) &&
! F_160 ( V_11 -> V_254 ) &&
! F_228 ( V_11 , V_237 , 3 ) ) {
V_22 -> V_262 = V_42 ;
V_260 ++ ;
}
V_319 = F_229 ( V_22 -> V_16 ) ;
if ( F_138 ( V_22 ) &&
( ! F_228 ( V_11 , V_319 , 2 ) ||
! F_228 ( V_11 , V_237 , 2 ) ) ) {
V_22 -> V_262 = V_42 ;
V_260 ++ ;
}
}
return V_260 ;
}
static void F_234 ( struct V_10 * V_11 )
{
unsigned long V_319 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
switch ( V_22 -> V_262 ) {
case V_263 :
continue;
case V_30 :
V_319 = F_229 ( V_22 -> V_16 ) ;
if ( F_36 ( V_11 -> V_69 ) != V_22 ||
( ! F_36 ( V_11 -> V_69 ) &&
F_228 ( V_11 , V_319 , 1 ) ) ) {
struct V_22 * V_254 ;
V_254 = F_36 ( V_11 -> V_254 ) ;
F_74 ( V_22 , V_30 ,
V_118 ) ;
if ( V_254 ) {
F_78 (
V_254 ,
V_118 ) ;
F_171 ( V_11 -> V_254 , NULL ) ;
}
F_73 ( V_11 -> V_16 , L_89 ,
V_22 -> V_16 -> V_59 ) ;
if ( ! F_36 ( V_11 -> V_69 ) ||
V_22 == F_36 ( V_11 -> V_101 ) )
goto V_266;
}
continue;
case V_42 :
if ( V_22 -> V_197 < V_267 )
V_22 -> V_197 ++ ;
F_74 ( V_22 , V_42 ,
V_118 ) ;
F_78 ( V_22 ,
V_118 ) ;
F_73 ( V_11 -> V_16 , L_75 ,
V_22 -> V_16 -> V_59 ) ;
if ( V_22 == F_36 ( V_11 -> V_69 ) ) {
F_171 ( V_11 -> V_254 , NULL ) ;
goto V_266;
}
continue;
default:
F_62 ( V_11 -> V_16 , L_92 ,
V_22 -> V_262 , V_22 -> V_16 -> V_59 ) ;
continue;
}
V_266:
F_165 () ;
F_81 ( V_11 ) ;
F_166 () ;
}
F_18 ( V_11 ) ;
}
static bool F_235 ( struct V_10 * V_11 )
{
struct V_22 * V_22 , * V_320 = NULL , * V_208 = NULL ,
* V_299 = F_68 ( V_11 -> V_254 ) ,
* V_69 = F_68 ( V_11 -> V_69 ) ;
struct V_24 * V_25 ;
bool V_294 = false ;
bool V_321 = V_264 ;
if ( V_299 && V_69 )
F_73 ( V_11 -> V_16 , L_93 ,
V_299 -> V_16 -> V_59 ,
V_69 -> V_16 -> V_59 ) ;
if ( V_69 ) {
F_210 ( V_11 , V_69 ) ;
return V_321 ;
}
if ( ! V_299 ) {
V_299 = F_236 ( V_11 ) ;
if ( ! V_299 )
return V_321 ;
}
F_78 ( V_299 , V_264 ) ;
F_90 (bond, slave, iter) {
if ( ! V_294 && ! V_320 && F_65 ( V_22 ) )
V_320 = V_22 ;
if ( V_294 && ! V_208 && F_65 ( V_22 ) )
V_208 = V_22 ;
if ( ! F_65 ( V_22 ) && V_22 -> V_29 == V_30 ) {
F_74 ( V_22 , V_42 ,
V_264 ) ;
if ( V_22 -> V_197 < V_267 )
V_22 -> V_197 ++ ;
F_78 ( V_22 ,
V_264 ) ;
F_73 ( V_11 -> V_16 , L_94 ,
V_22 -> V_16 -> V_59 ) ;
}
if ( V_22 == V_299 )
V_294 = true ;
}
if ( ! V_208 && V_320 )
V_208 = V_320 ;
if ( ! V_208 )
goto V_322;
F_74 ( V_208 , V_43 ,
V_264 ) ;
F_79 ( V_208 , V_264 ) ;
F_210 ( V_11 , V_208 ) ;
V_208 -> V_115 = V_116 ;
F_80 ( V_11 -> V_254 , V_208 ) ;
V_322:
F_90 (bond, slave, iter) {
if ( V_22 -> V_323 || V_22 -> V_324 ) {
V_321 = V_118 ;
break;
}
}
return V_321 ;
}
static void F_237 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_41 ( V_71 , struct V_10 ,
V_317 . V_71 ) ;
bool V_119 = false ;
bool V_321 = false ;
int V_316 ;
V_316 = F_156 ( V_11 -> V_52 . V_238 ) ;
if ( ! F_19 ( V_11 ) )
goto V_269;
F_67 () ;
V_119 = F_66 ( V_11 ) ;
if ( F_233 ( V_11 ) ) {
F_69 () ;
if ( ! F_42 () ) {
V_316 = 1 ;
V_119 = false ;
goto V_269;
}
F_234 ( V_11 ) ;
F_45 () ;
F_67 () ;
}
V_321 = F_235 ( V_11 ) ;
F_69 () ;
V_269:
if ( V_11 -> V_52 . V_238 )
F_43 ( V_11 -> V_73 , & V_11 -> V_317 , V_316 ) ;
if ( V_119 || V_321 ) {
if ( ! F_42 () )
return;
if ( V_119 )
F_44 ( V_122 ,
V_11 -> V_16 ) ;
if ( V_321 ) {
F_238 ( V_11 ) ;
F_239 ( V_11 ) ;
}
F_45 () ;
}
}
static int F_240 ( struct V_10 * V_11 )
{
F_184 ( V_11 ) ;
F_241 ( V_11 ) ;
F_242 ( V_11 ) ;
return V_325 ;
}
static int F_243 ( unsigned long V_326 ,
struct V_14 * V_19 )
{
struct V_10 * V_327 = F_11 ( V_19 ) ;
switch ( V_326 ) {
case V_328 :
return F_240 ( V_327 ) ;
case V_329 :
F_184 ( V_327 ) ;
break;
case V_330 :
F_241 ( V_327 ) ;
break;
case V_122 :
if ( V_327 -> V_112 )
V_327 -> V_112 -- ;
break;
default:
break;
}
return V_325 ;
}
static int F_244 ( unsigned long V_326 ,
struct V_14 * V_15 )
{
struct V_22 * V_22 = F_245 ( V_15 ) , * V_241 ;
struct V_10 * V_11 ;
struct V_14 * V_19 ;
if ( ! V_22 )
return V_325 ;
V_19 = V_22 -> V_11 -> V_16 ;
V_11 = V_22 -> V_11 ;
V_241 = F_36 ( V_11 -> V_101 ) ;
switch ( V_326 ) {
case V_329 :
if ( V_19 -> type != V_219 )
F_183 ( V_19 , V_15 ) ;
else
F_182 ( V_19 , V_15 ) ;
break;
case V_331 :
case V_332 :
F_25 ( V_22 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_246 ( V_22 ) ;
case V_333 :
if ( F_167 ( V_11 ) )
F_168 ( V_11 , NULL ) ;
break;
case V_334 :
break;
case V_328 :
if ( ! F_35 ( V_11 ) ||
! V_11 -> V_52 . V_241 [ 0 ] )
break;
if ( V_22 == V_241 ) {
F_171 ( V_11 -> V_101 , NULL ) ;
} else if ( ! strcmp ( V_15 -> V_59 , V_11 -> V_52 . V_241 ) ) {
F_80 ( V_11 -> V_101 , V_22 ) ;
} else {
break;
}
F_73 ( V_11 -> V_16 , L_95 ,
V_241 ? V_15 -> V_59 : L_96 ) ;
F_165 () ;
F_81 ( V_11 ) ;
F_166 () ;
break;
case V_335 :
F_100 ( V_11 ) ;
break;
case V_74 :
F_44 ( V_326 , V_22 -> V_11 -> V_16 ) ;
break;
default:
break;
}
return V_325 ;
}
static int F_247 ( struct V_336 * V_337 ,
unsigned long V_326 , void * V_338 )
{
struct V_14 * V_339 = F_248 ( V_338 ) ;
F_56 ( V_339 , L_97 , V_326 ) ;
if ( ! ( V_339 -> V_160 & V_234 ) )
return V_325 ;
if ( V_339 -> V_82 & V_248 ) {
F_56 ( V_339 , L_98 ) ;
return F_243 ( V_326 , V_339 ) ;
}
if ( V_339 -> V_82 & V_188 ) {
F_56 ( V_339 , L_99 ) ;
return F_244 ( V_326 , V_339 ) ;
}
return V_325 ;
}
static inline T_3 F_249 ( struct V_12 * V_13 )
{
struct V_340 * V_341 , V_342 ;
V_341 = F_250 ( V_13 , 0 , sizeof( V_342 ) , & V_342 ) ;
if ( V_341 )
return V_341 -> V_177 [ 5 ] ^ V_341 -> V_343 [ 5 ] ^ V_341 -> V_344 ;
return 0 ;
}
static bool F_251 ( struct V_10 * V_11 , struct V_12 * V_13 ,
struct V_345 * V_346 )
{
const struct V_347 * V_348 ;
const struct V_349 * V_350 ;
int V_351 , V_20 = - 1 ;
if ( V_11 -> V_52 . V_352 > V_353 )
return F_252 ( V_13 , V_346 , 0 ) ;
V_346 -> V_354 . V_354 = 0 ;
V_351 = F_253 ( V_13 ) ;
if ( V_13 -> V_303 == F_225 ( V_310 ) ) {
if ( F_5 ( ! F_254 ( V_13 , V_351 + sizeof( * V_350 ) ) ) )
return false ;
V_350 = F_255 ( V_13 ) ;
F_256 ( V_346 , V_350 ) ;
V_351 += V_350 -> V_355 << 2 ;
if ( ! F_257 ( V_350 ) )
V_20 = V_350 -> V_303 ;
} else if ( V_13 -> V_303 == F_225 ( V_356 ) ) {
if ( F_5 ( ! F_254 ( V_13 , V_351 + sizeof( * V_348 ) ) ) )
return false ;
V_348 = F_258 ( V_13 ) ;
F_259 ( V_346 , V_348 ) ;
V_351 += sizeof( * V_348 ) ;
V_20 = V_348 -> V_357 ;
} else {
return false ;
}
if ( V_11 -> V_52 . V_352 == V_358 && V_20 >= 0 )
V_346 -> V_354 . V_354 = F_260 ( V_13 , V_351 , V_20 ) ;
return true ;
}
T_3 F_261 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
struct V_345 V_359 ;
T_3 V_360 ;
if ( V_11 -> V_52 . V_352 == V_361 &&
V_13 -> V_362 )
return V_13 -> V_360 ;
if ( V_11 -> V_52 . V_352 == V_363 ||
! F_251 ( V_11 , V_13 , & V_359 ) )
return F_249 ( V_13 ) ;
if ( V_11 -> V_52 . V_352 == V_353 ||
V_11 -> V_52 . V_352 == V_364 )
V_360 = F_249 ( V_13 ) ;
else
V_360 = ( V_365 T_3 ) V_359 . V_354 . V_354 ;
V_360 ^= ( V_365 T_3 ) F_262 ( & V_359 ) ^
( V_365 T_3 ) F_263 ( & V_359 ) ;
V_360 ^= ( V_360 >> 16 ) ;
V_360 ^= ( V_360 >> 8 ) ;
return V_360 ;
}
static void F_264 ( struct V_10 * V_11 )
{
F_136 ( & V_11 -> V_72 ,
F_40 ) ;
F_136 ( & V_11 -> V_366 , V_367 ) ;
F_136 ( & V_11 -> V_268 , F_191 ) ;
if ( F_20 ( V_11 ) == V_4 )
F_136 ( & V_11 -> V_317 , F_237 ) ;
else
F_136 ( & V_11 -> V_317 , F_231 ) ;
F_136 ( & V_11 -> V_368 , V_369 ) ;
F_136 ( & V_11 -> V_370 , V_371 ) ;
}
static void F_265 ( struct V_10 * V_11 )
{
F_266 ( & V_11 -> V_268 ) ;
F_266 ( & V_11 -> V_317 ) ;
F_266 ( & V_11 -> V_366 ) ;
F_266 ( & V_11 -> V_368 ) ;
F_266 ( & V_11 -> V_72 ) ;
F_266 ( & V_11 -> V_370 ) ;
}
static int F_267 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
if ( F_19 ( V_11 ) ) {
F_12 (bond, slave, iter) {
if ( F_35 ( V_11 ) &&
V_22 != F_160 ( V_11 -> V_69 ) ) {
F_78 ( V_22 ,
V_118 ) ;
} else if ( F_20 ( V_11 ) != V_7 ) {
F_79 ( V_22 ,
V_118 ) ;
}
}
}
F_264 ( V_11 ) ;
if ( F_16 ( V_11 ) ) {
if ( F_268 ( V_11 , ( F_20 ( V_11 ) == V_9 ) ) )
return - V_128 ;
if ( V_11 -> V_52 . V_372 )
F_43 ( V_11 -> V_73 , & V_11 -> V_366 , 0 ) ;
}
if ( V_11 -> V_52 . V_117 )
F_43 ( V_11 -> V_73 , & V_11 -> V_268 , 0 ) ;
if ( V_11 -> V_52 . V_238 ) {
F_43 ( V_11 -> V_73 , & V_11 -> V_317 , 0 ) ;
V_11 -> F_108 = F_217 ;
}
if ( F_20 ( V_11 ) == V_7 ) {
F_43 ( V_11 -> V_73 , & V_11 -> V_368 , 0 ) ;
V_11 -> F_108 = V_373 ;
F_269 ( V_11 , 1 ) ;
}
if ( F_167 ( V_11 ) )
F_168 ( V_11 , NULL ) ;
return 0 ;
}
static int F_270 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_265 ( V_11 ) ;
V_11 -> V_112 = 0 ;
if ( F_16 ( V_11 ) )
F_271 ( V_11 ) ;
V_11 -> F_108 = NULL ;
return 0 ;
}
static struct V_374 * F_179 ( struct V_14 * V_19 ,
struct V_374 * V_375 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_374 V_376 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
memcpy ( V_375 , & V_11 -> V_253 , sizeof( * V_375 ) ) ;
F_12 (bond, slave, iter) {
const struct V_374 * V_377 =
F_149 ( V_22 -> V_16 , & V_376 ) ;
struct V_374 * V_378 = & V_22 -> V_235 ;
V_375 -> V_379 += V_377 -> V_379 - V_378 -> V_379 ;
V_375 -> V_380 += V_377 -> V_380 - V_378 -> V_380 ;
V_375 -> V_381 += V_377 -> V_381 - V_378 -> V_381 ;
V_375 -> V_382 += V_377 -> V_382 - V_378 -> V_382 ;
V_375 -> V_383 += V_377 -> V_383 - V_378 -> V_383 ; ;
V_375 -> V_384 += V_377 -> V_384 - V_378 -> V_384 ;
V_375 -> V_385 += V_377 -> V_385 - V_378 -> V_385 ;
V_375 -> V_386 += V_377 -> V_386 - V_378 -> V_386 ;
V_375 -> V_387 += V_377 -> V_387 - V_378 -> V_387 ;
V_375 -> V_388 += V_377 -> V_388 - V_378 -> V_388 ;
V_375 -> V_389 += V_377 -> V_389 - V_378 -> V_389 ;
V_375 -> V_390 += V_377 -> V_390 - V_378 -> V_390 ;
V_375 -> V_391 += V_377 -> V_391 - V_378 -> V_391 ;
V_375 -> V_392 += V_377 -> V_392 - V_378 -> V_392 ;
V_375 -> V_393 += V_377 -> V_393 - V_378 -> V_393 ;
V_375 -> V_394 += V_377 -> V_394 - V_378 -> V_394 ;
V_375 -> V_395 += V_377 -> V_395 - V_378 -> V_395 ;
V_375 -> V_396 += V_377 -> V_396 - V_378 -> V_396 ;
V_375 -> V_397 += V_377 -> V_397 - V_378 -> V_397 ;
V_375 -> V_398 += V_377 -> V_398 - V_378 -> V_398 ;
V_375 -> V_399 += V_377 -> V_399 - V_378 -> V_399 ;
memcpy ( V_378 , V_377 , sizeof( * V_377 ) ) ;
}
memcpy ( & V_11 -> V_253 , V_375 , sizeof( * V_375 ) ) ;
return V_375 ;
}
static int F_272 ( struct V_14 * V_19 , struct V_48 * V_49 , int V_400 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_14 * V_15 = NULL ;
struct V_190 V_401 ;
struct V_190 T_9 * V_402 = NULL ;
struct V_195 V_403 ;
struct V_195 T_9 * V_404 = NULL ;
struct V_50 * V_51 = NULL ;
struct V_405 V_406 ;
struct V_407 * V_407 ;
int V_26 = 0 ;
F_56 ( V_19 , L_100 , V_400 ) ;
switch ( V_400 ) {
case V_61 :
V_51 = F_32 ( V_49 ) ;
if ( ! V_51 )
return - V_222 ;
V_51 -> V_408 = 0 ;
case V_64 :
V_51 = F_32 ( V_49 ) ;
if ( ! V_51 )
return - V_222 ;
if ( V_51 -> V_62 == 1 ) {
V_51 -> V_65 = 0 ;
if ( F_22 ( V_11 -> V_16 ) )
V_51 -> V_65 = V_54 ;
}
return 0 ;
case V_409 :
case V_410 :
V_402 = (struct V_190 T_9 * ) V_49 -> V_411 ;
if ( F_273 ( & V_401 , V_402 , sizeof( V_190 ) ) )
return - V_412 ;
V_26 = F_186 ( V_19 , & V_401 ) ;
if ( V_26 == 0 &&
F_274 ( V_402 , & V_401 , sizeof( V_190 ) ) )
return - V_412 ;
return V_26 ;
case V_413 :
case V_414 :
V_404 = (struct V_195 T_9 * ) V_49 -> V_411 ;
if ( F_273 ( & V_403 , V_404 , sizeof( V_195 ) ) )
return - V_412 ;
V_26 = F_187 ( V_19 , & V_403 ) ;
if ( V_26 == 0 &&
F_274 ( V_404 , & V_403 , sizeof( V_195 ) ) )
return - V_412 ;
return V_26 ;
default:
break;
}
V_407 = F_212 ( V_19 ) ;
if ( ! F_275 ( V_407 -> V_415 , V_416 ) )
return - V_214 ;
V_15 = F_276 ( V_407 , V_49 -> V_417 ) ;
F_56 ( V_19 , L_101 , V_15 ) ;
if ( ! V_15 )
return - V_257 ;
F_56 ( V_19 , L_102 , V_15 -> V_59 ) ;
switch ( V_400 ) {
case V_418 :
case V_419 :
V_26 = F_140 ( V_19 , V_15 ) ;
break;
case V_420 :
case V_421 :
V_26 = F_182 ( V_19 , V_15 ) ;
break;
case V_422 :
case V_423 :
F_55 ( V_19 , V_15 ) ;
V_26 = 0 ;
break;
case V_424 :
case V_425 :
F_277 ( & V_406 , V_15 -> V_59 ) ;
V_26 = F_278 ( V_11 , V_426 , & V_406 ) ;
break;
default:
V_26 = - V_224 ;
}
return V_26 ;
}
static void F_279 ( struct V_14 * V_19 , int V_427 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
if ( V_427 & V_83 )
F_34 ( V_11 ,
V_19 -> V_82 & V_83 ? 1 : - 1 ) ;
if ( V_427 & V_84 )
F_38 ( V_11 ,
V_19 -> V_82 & V_84 ? 1 : - 1 ) ;
}
static void F_280 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_67 () ;
if ( F_35 ( V_11 ) ) {
V_22 = F_68 ( V_11 -> V_69 ) ;
if ( V_22 ) {
F_52 ( V_22 -> V_16 , V_19 ) ;
F_53 ( V_22 -> V_16 , V_19 ) ;
}
} else {
F_90 (bond, slave, iter) {
F_152 ( V_22 -> V_16 , V_19 ) ;
F_151 ( V_22 -> V_16 , V_19 ) ;
}
}
F_69 () ;
}
static int F_281 ( struct V_428 * V_429 )
{
struct V_10 * V_11 = F_11 ( V_429 -> V_16 ) ;
const struct V_45 * V_46 ;
struct V_430 V_431 ;
struct V_22 * V_22 ;
int V_169 ;
V_22 = F_282 ( V_11 ) ;
if ( ! V_22 )
return 0 ;
V_46 = V_22 -> V_16 -> V_47 ;
if ( ! V_46 -> V_432 )
return 0 ;
V_431 . V_433 = NULL ;
V_431 . V_434 = NULL ;
V_169 = V_46 -> V_432 ( V_22 -> V_16 , & V_431 ) ;
if ( V_169 )
return V_169 ;
V_429 -> V_431 -> V_434 = V_431 . V_434 ;
if ( ! V_431 . V_433 )
return 0 ;
return V_431 . V_433 ( V_429 ) ;
}
static int F_283 ( struct V_14 * V_16 ,
struct V_430 * V_431 )
{
if ( V_431 -> V_16 == V_16 )
V_431 -> V_433 = F_281 ;
return 0 ;
}
static int F_284 ( struct V_14 * V_19 , int V_435 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_23 ;
struct V_24 * V_25 ;
int V_26 = 0 ;
F_56 ( V_19 , L_103 , V_11 , V_435 ) ;
F_12 (bond, slave, iter) {
F_56 ( V_19 , L_104 ,
V_22 , V_22 -> V_16 -> V_47 -> V_436 ) ;
V_26 = F_147 ( V_22 -> V_16 , V_435 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_105 , V_26 ,
V_22 -> V_16 -> V_59 ) ;
goto V_27;
}
}
V_19 -> V_229 = V_435 ;
return 0 ;
V_27:
F_12 (bond, rollback_slave, iter) {
int V_437 ;
if ( V_23 == V_22 )
break;
V_437 = F_147 ( V_23 -> V_16 , V_19 -> V_229 ) ;
if ( V_437 ) {
F_56 ( V_19 , L_106 ,
V_437 , V_23 -> V_16 -> V_59 ) ;
}
}
return V_26 ;
}
static int F_285 ( struct V_14 * V_19 , void * V_210 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_23 ;
struct V_91 * V_438 = V_210 , V_439 ;
struct V_24 * V_25 ;
int V_26 = 0 ;
if ( F_20 ( V_11 ) == V_9 )
return F_286 ( V_19 , V_210 ) ;
F_56 ( V_19 , L_107 , V_11 ) ;
if ( V_11 -> V_52 . V_94 &&
F_20 ( V_11 ) == V_4 )
return 0 ;
if ( ! F_287 ( V_438 -> V_97 ) )
return - V_440 ;
F_12 (bond, slave, iter) {
F_56 ( V_19 , L_108 , V_22 , V_22 -> V_16 -> V_59 ) ;
V_26 = F_61 ( V_22 -> V_16 , V_210 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_105 , V_26 , V_22 -> V_16 -> V_59 ) ;
goto V_27;
}
}
memcpy ( V_19 -> V_86 , V_438 -> V_97 , V_19 -> V_85 ) ;
return 0 ;
V_27:
memcpy ( V_439 . V_97 , V_19 -> V_86 , V_19 -> V_85 ) ;
V_439 . V_98 = V_19 -> type ;
F_12 (bond, rollback_slave, iter) {
int V_437 ;
if ( V_23 == V_22 )
break;
V_437 = F_61 ( V_23 -> V_16 , & V_439 ) ;
if ( V_437 ) {
F_56 ( V_19 , L_106 ,
V_437 , V_23 -> V_16 -> V_59 ) ;
}
}
return V_26 ;
}
static void F_288 ( struct V_10 * V_11 , struct V_12 * V_13 , int V_258 )
{
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_212 = V_258 ;
F_90 (bond, slave, iter) {
if ( -- V_212 < 0 ) {
if ( F_289 ( V_22 ) ) {
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
return;
}
}
}
V_212 = V_258 ;
F_90 (bond, slave, iter) {
if ( -- V_212 < 0 )
break;
if ( F_289 ( V_22 ) ) {
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
return;
}
}
F_290 ( V_11 -> V_16 , V_13 ) ;
}
static T_3 F_291 ( struct V_10 * V_11 )
{
T_3 V_258 ;
struct V_441 V_442 ;
int V_443 = V_11 -> V_52 . V_443 ;
switch ( V_443 ) {
case 0 :
V_258 = F_292 () ;
break;
case 1 :
V_258 = V_11 -> V_444 ;
break;
default:
V_442 =
V_11 -> V_52 . V_442 ;
V_258 = F_293 ( V_11 -> V_444 ,
V_442 ) ;
break;
}
V_11 -> V_444 ++ ;
return V_258 ;
}
static int F_294 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_349 * V_350 = F_255 ( V_13 ) ;
struct V_22 * V_22 ;
T_3 V_258 ;
if ( V_350 -> V_303 == V_445 && V_13 -> V_303 == F_225 ( V_310 ) ) {
V_22 = F_68 ( V_11 -> V_69 ) ;
if ( V_22 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_288 ( V_11 , V_13 , 0 ) ;
} else {
int V_194 = F_111 ( V_11 -> V_194 ) ;
if ( F_295 ( V_194 ) ) {
V_258 = F_291 ( V_11 ) ;
F_288 ( V_11 , V_13 , V_258 % V_194 ) ;
} else {
F_290 ( V_19 , V_13 ) ;
}
}
return V_446 ;
}
static int F_296 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 ;
V_22 = F_68 ( V_11 -> V_69 ) ;
if ( V_22 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_290 ( V_19 , V_13 ) ;
return V_446 ;
}
void F_297 ( struct V_10 * V_11 , unsigned long V_111 )
{
F_43 ( V_11 -> V_73 , & V_11 -> V_370 , V_111 ) ;
}
static void V_371 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_41 ( V_71 , struct V_10 ,
V_370 . V_71 ) ;
int V_169 ;
if ( ! F_42 () )
goto V_67;
V_169 = F_168 ( V_11 , NULL ) ;
F_45 () ;
if ( V_169 ) {
F_298 ( L_109 ) ;
goto V_67;
}
return;
V_67:
F_297 ( V_11 , 1 ) ;
}
int F_168 ( struct V_10 * V_11 , struct V_22 * V_447 )
{
struct V_22 * V_22 ;
struct V_24 * V_25 ;
struct V_448 * V_449 , * V_450 ;
int V_451 = 0 ;
int V_169 = 0 ;
#ifdef F_299
F_300 ( F_301 ( & V_11 -> V_452 ) ) ;
#endif
V_449 = F_83 ( F_302 ( struct V_448 , V_453 [ V_11 -> V_194 ] ) ,
V_127 ) ;
if ( ! V_449 ) {
V_169 = - V_128 ;
F_303 ( L_110 ) ;
goto V_99;
}
if ( F_20 ( V_11 ) == V_7 ) {
struct V_129 V_129 ;
if ( F_89 ( V_11 , & V_129 ) ) {
F_304 ( L_111 ) ;
F_305 ( V_449 , V_454 ) ;
V_450 = F_36 ( V_11 -> V_455 ) ;
if ( V_450 ) {
F_171 ( V_11 -> V_455 , NULL ) ;
F_305 ( V_450 , V_454 ) ;
}
goto V_99;
}
V_451 = V_129 . V_138 ;
}
F_12 (bond, slave, iter) {
if ( F_20 ( V_11 ) == V_7 ) {
struct V_134 * V_135 ;
V_135 = F_91 ( V_22 ) -> V_136 . V_134 ;
if ( ! V_135 || V_135 -> V_137 != V_451 )
continue;
}
if ( ! F_289 ( V_22 ) )
continue;
if ( V_447 == V_22 )
continue;
V_449 -> V_453 [ V_449 -> V_456 ++ ] = V_22 ;
}
V_450 = F_36 ( V_11 -> V_455 ) ;
F_80 ( V_11 -> V_455 , V_449 ) ;
if ( V_450 )
F_305 ( V_450 , V_454 ) ;
V_99:
if ( V_169 != 0 && V_447 ) {
int V_457 ;
V_450 = F_36 ( V_11 -> V_455 ) ;
for ( V_457 = 0 ; V_457 < V_450 -> V_456 ; V_457 ++ ) {
if ( V_447 == V_450 -> V_453 [ V_457 ] ) {
V_450 -> V_453 [ V_457 ] =
V_450 -> V_453 [ V_450 -> V_456 - 1 ] ;
V_450 -> V_456 -- ;
break;
}
}
}
return V_169 ;
}
static int F_306 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
struct V_22 * V_22 ;
struct V_448 * V_458 ;
unsigned int V_456 ;
V_458 = F_68 ( V_11 -> V_455 ) ;
V_456 = V_458 ? F_111 ( V_458 -> V_456 ) : 0 ;
if ( F_295 ( V_456 ) ) {
V_22 = V_458 -> V_453 [ F_261 ( V_11 , V_13 ) % V_456 ] ;
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
} else {
F_290 ( V_16 , V_13 ) ;
}
return V_446 ;
}
static int F_307 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 = NULL ;
struct V_24 * V_25 ;
F_90 (bond, slave, iter) {
if ( F_308 ( V_11 , V_22 ) )
break;
if ( F_65 ( V_22 ) && V_22 -> V_29 == V_30 ) {
struct V_12 * V_459 = F_309 ( V_13 , V_171 ) ;
if ( ! V_459 ) {
F_197 ( L_112 ,
V_19 -> V_59 , V_460 ) ;
continue;
}
F_2 ( V_11 , V_459 , V_22 -> V_16 ) ;
}
}
if ( V_22 && F_65 ( V_22 ) && V_22 -> V_29 == V_30 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_290 ( V_19 , V_13 ) ;
return V_446 ;
}
static inline int F_310 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_22 * V_22 = NULL ;
struct V_24 * V_25 ;
if ( ! V_13 -> V_17 )
return 1 ;
F_90 (bond, slave, iter) {
if ( V_22 -> V_227 == V_13 -> V_17 ) {
if ( F_65 ( V_22 ) &&
V_22 -> V_29 == V_30 ) {
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
return 0 ;
}
break;
}
}
return 1 ;
}
static T_2 F_311 ( struct V_14 * V_16 , struct V_12 * V_13 ,
void * V_461 , T_10 V_462 )
{
T_2 V_463 = F_312 ( V_13 ) ? F_313 ( V_13 ) : 0 ;
F_4 ( V_13 ) -> V_18 = V_13 -> V_17 ;
if ( F_5 ( V_463 >= V_16 -> V_464 ) ) {
do {
V_463 -= V_16 -> V_464 ;
} while ( V_463 >= V_16 -> V_464 );
}
return V_463 ;
}
static T_11 F_314 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
if ( F_315 ( V_11 ) &&
! F_310 ( V_11 , V_13 ) )
return V_446 ;
switch ( F_20 ( V_11 ) ) {
case V_3 :
return F_294 ( V_13 , V_16 ) ;
case V_4 :
return F_296 ( V_13 , V_16 ) ;
case V_7 :
case V_5 :
return F_306 ( V_13 , V_16 ) ;
case V_6 :
return F_307 ( V_13 , V_16 ) ;
case V_9 :
return F_316 ( V_13 , V_16 ) ;
case V_8 :
return F_317 ( V_13 , V_16 ) ;
default:
F_62 ( V_16 , L_113 , F_20 ( V_11 ) ) ;
F_318 ( 1 ) ;
F_290 ( V_16 , V_13 ) ;
return V_446 ;
}
}
static T_11 F_319 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
T_11 V_169 = V_446 ;
if ( F_5 ( F_320 ( V_16 ) ) )
return V_465 ;
F_67 () ;
if ( F_19 ( V_11 ) )
V_169 = F_314 ( V_13 , V_16 ) ;
else
F_290 ( V_16 , V_13 ) ;
F_69 () ;
return V_169 ;
}
static int F_321 ( struct V_14 * V_19 ,
struct V_31 * V_32 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
unsigned long V_34 = 0 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
V_32 -> V_36 = V_37 ;
V_32 -> V_136 = V_466 ;
F_12 (bond, slave, iter) {
if ( F_289 ( V_22 ) ) {
if ( V_22 -> V_34 != V_35 )
V_34 += V_22 -> V_34 ;
if ( V_32 -> V_36 == V_37 &&
V_22 -> V_36 != V_37 )
V_32 -> V_36 = V_22 -> V_36 ;
}
}
F_322 ( V_32 , V_34 ? : V_35 ) ;
return 0 ;
}
static void F_323 ( struct V_14 * V_19 ,
struct V_467 * V_468 )
{
F_324 ( V_468 -> V_469 , V_470 , sizeof( V_468 -> V_469 ) ) ;
F_324 ( V_468 -> V_471 , V_472 , sizeof( V_468 -> V_471 ) ) ;
snprintf ( V_468 -> V_473 , sizeof( V_468 -> V_473 ) , L_114 ,
V_474 ) ;
}
static void F_325 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
if ( V_11 -> V_73 )
F_326 ( V_11 -> V_73 ) ;
F_327 ( V_19 ) ;
}
void F_328 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_329 ( & V_11 -> V_452 ) ;
V_11 -> V_52 = V_475 ;
V_11 -> V_16 = V_19 ;
F_146 ( V_19 ) ;
V_19 -> V_47 = & V_476 ;
V_19 -> V_55 = & V_477 ;
V_19 -> V_478 = F_325 ;
F_330 ( V_19 , & V_479 ) ;
V_19 -> V_82 |= V_248 | V_480 ;
V_19 -> V_160 |= V_234 | V_481 | V_482 ;
V_19 -> V_160 &= ~ ( V_146 | V_220 ) ;
V_19 -> V_141 |= V_483 ;
V_19 -> V_141 |= V_484 ;
V_19 -> V_485 = V_149 |
V_486 |
V_487 |
V_488 ;
V_19 -> V_485 |= V_162 ;
V_19 -> V_141 |= V_19 -> V_485 ;
}
static void F_331 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
struct V_448 * V_453 ;
F_95 ( V_19 ) ;
F_12 (bond, slave, iter)
F_176 ( V_19 , V_22 -> V_16 , true ) ;
F_73 ( V_19 , L_115 ) ;
V_453 = F_36 ( V_11 -> V_455 ) ;
if ( V_453 ) {
F_171 ( V_11 -> V_455 , NULL ) ;
F_305 ( V_453 , V_454 ) ;
}
F_332 ( & V_11 -> V_489 ) ;
F_333 ( V_11 ) ;
}
static int F_334 ( struct V_490 * V_52 )
{
int V_491 , V_492 , V_493 , V_212 ;
struct V_405 V_406 ;
const struct V_405 * V_494 ;
int V_495 ;
T_2 V_496 = 0 ;
T_2 V_497 = 0 ;
if ( V_1 ) {
F_277 ( & V_406 , V_1 ) ;
V_494 = F_335 ( F_336 ( V_498 ) , & V_406 ) ;
if ( ! V_494 ) {
F_303 ( L_116 , V_1 ) ;
return - V_222 ;
}
V_192 = V_494 -> V_499 ;
}
if ( V_500 ) {
if ( ( V_192 != V_5 ) &&
( V_192 != V_7 ) &&
( V_192 != V_8 ) ) {
F_337 ( L_117 ,
F_1 ( V_192 ) ) ;
} else {
F_277 ( & V_406 , V_500 ) ;
V_494 = F_335 ( F_336 ( V_501 ) ,
& V_406 ) ;
if ( ! V_494 ) {
F_303 ( L_118 ,
V_500 ) ;
return - V_222 ;
}
V_502 = V_494 -> V_499 ;
}
}
if ( V_503 ) {
if ( V_192 != V_7 ) {
F_337 ( L_119 ,
F_1 ( V_192 ) ) ;
} else {
F_277 ( & V_406 , V_503 ) ;
V_494 = F_335 ( F_336 ( V_504 ) ,
& V_406 ) ;
if ( ! V_494 ) {
F_303 ( L_120 ,
V_503 ) ;
return - V_222 ;
}
V_505 = V_494 -> V_499 ;
}
}
if ( V_506 ) {
F_277 ( & V_406 , V_506 ) ;
V_494 = F_335 ( F_336 ( V_507 ) ,
& V_406 ) ;
if ( ! V_494 ) {
F_303 ( L_121 , V_506 ) ;
return - V_222 ;
}
V_52 -> V_506 = V_494 -> V_499 ;
if ( V_192 != V_7 )
F_338 ( L_122 ) ;
} else {
V_52 -> V_506 = V_508 ;
}
if ( V_509 < 0 ) {
F_338 ( L_123 ,
V_509 , 0 , V_510 , V_511 ) ;
V_509 = V_511 ;
}
if ( V_117 < 0 ) {
F_338 ( L_124 ,
V_117 , V_510 ) ;
V_117 = 0 ;
}
if ( V_110 < 0 ) {
F_338 ( L_125 ,
V_110 , V_510 ) ;
V_110 = 0 ;
}
if ( V_265 < 0 ) {
F_338 ( L_126 ,
V_265 , V_510 ) ;
V_265 = 0 ;
}
if ( ( V_53 != 0 ) && ( V_53 != 1 ) ) {
F_338 ( L_127 ,
V_53 ) ;
V_53 = 1 ;
}
if ( V_120 < 0 || V_120 > 255 ) {
F_338 ( L_128 ,
V_120 ) ;
V_120 = 1 ;
}
if ( ! F_339 ( V_192 ) ) {
if ( ! V_117 ) {
F_338 ( L_129 ) ;
F_338 ( L_130 ) ;
V_117 = V_512 ;
}
}
if ( V_513 < 1 || V_513 > 255 ) {
F_338 ( L_131 ,
V_513 , V_514 ) ;
V_513 = V_514 ;
}
if ( ( V_515 != 0 ) && ( V_515 != 1 ) ) {
F_338 ( L_132 ,
V_515 ) ;
V_515 = 0 ;
}
if ( V_123 < 0 || V_123 > 255 ) {
F_338 ( L_133 ,
V_123 , V_516 ) ;
V_123 = V_516 ;
}
F_340 ( & V_406 , V_443 ) ;
if ( ! F_335 ( F_336 ( V_517 ) , & V_406 ) ) {
F_338 ( L_134 ,
V_443 , V_518 ) ;
V_443 = 1 ;
}
if ( V_192 == V_9 ) {
F_341 ( L_135 ,
V_110 ) ;
}
if ( ! V_117 ) {
if ( V_110 || V_265 ) {
F_338 ( L_136 ,
V_110 , V_265 ) ;
}
} else {
if ( V_238 ) {
F_338 ( L_137 ,
V_117 , V_238 ) ;
V_238 = 0 ;
}
if ( ( V_110 % V_117 ) != 0 ) {
F_338 ( L_138 ,
V_110 , V_117 , ( V_110 / V_117 ) * V_117 ) ;
}
V_110 /= V_117 ;
if ( ( V_265 % V_117 ) != 0 ) {
F_338 ( L_139 ,
V_265 , V_117 ,
( V_265 / V_117 ) * V_117 ) ;
}
V_265 /= V_117 ;
}
if ( V_238 < 0 ) {
F_338 ( L_140 ,
V_238 , V_510 ) ;
V_238 = 0 ;
}
for ( V_519 = 0 , V_212 = 0 ;
( V_519 < V_239 ) && V_520 [ V_212 ] ; V_212 ++ ) {
T_8 V_270 ;
if ( ! F_342 ( V_520 [ V_212 ] , - 1 , ( T_5 * ) & V_270 , - 1 , NULL ) ||
! F_343 ( V_270 ) ) {
F_338 ( L_141 ,
V_520 [ V_212 ] ) ;
V_238 = 0 ;
} else {
if ( F_216 ( V_521 , V_270 ) == - 1 )
V_521 [ V_519 ++ ] = V_270 ;
else
F_338 ( L_142 ,
& V_270 ) ;
}
}
if ( V_238 && ! V_519 ) {
F_338 ( L_143 ,
V_238 ) ;
V_238 = 0 ;
}
if ( V_291 ) {
if ( ! V_238 ) {
F_303 ( L_144 ) ;
return - V_222 ;
}
F_277 ( & V_406 , V_291 ) ;
V_494 = F_335 ( F_336 ( V_522 ) ,
& V_406 ) ;
if ( ! V_494 ) {
F_303 ( L_145 ,
V_291 ) ;
return - V_222 ;
}
V_491 = V_494 -> V_499 ;
} else {
V_491 = 0 ;
}
V_495 = 0 ;
if ( V_523 ) {
F_277 ( & V_406 , V_523 ) ;
V_494 = F_335 ( F_336 ( V_524 ) ,
& V_406 ) ;
if ( ! V_494 ) {
F_303 ( L_146 ,
V_523 ) ;
V_495 = 0 ;
} else {
V_495 = V_494 -> V_499 ;
}
}
if ( V_117 ) {
F_337 ( L_147 , V_117 ) ;
} else if ( V_238 ) {
V_494 = F_344 ( V_522 ,
V_491 ) ;
F_337 ( L_148 ,
V_238 , V_494 -> string , V_519 ) ;
for ( V_212 = 0 ; V_212 < V_519 ; V_212 ++ )
F_345 ( L_149 , V_520 [ V_212 ] ) ;
F_345 ( L_150 ) ;
} else if ( V_509 ) {
F_304 ( L_151 ) ;
}
if ( V_241 && ! F_346 ( V_192 ) ) {
F_338 ( L_152 ,
V_241 , F_1 ( V_192 ) ) ;
V_241 = NULL ;
}
if ( V_241 && V_104 ) {
F_277 ( & V_406 , V_104 ) ;
V_494 = F_335 ( F_336 ( V_525 ) ,
& V_406 ) ;
if ( ! V_494 ) {
F_303 ( L_153 ,
V_104 ) ;
return - V_222 ;
}
V_493 = V_494 -> V_499 ;
} else {
V_493 = V_105 ;
}
if ( V_94 ) {
F_277 ( & V_406 , V_94 ) ;
V_494 = F_335 ( F_336 ( V_526 ) ,
& V_406 ) ;
if ( ! V_494 ) {
F_303 ( L_154 ,
V_94 ) ;
return - V_222 ;
}
V_492 = V_494 -> V_499 ;
if ( V_192 != V_4 )
F_338 ( L_155 ) ;
} else {
V_492 = V_527 ;
}
F_277 ( & V_406 , L_156 ) ;
V_494 = F_335 (
F_336 ( V_528 ) ,
& V_406 ) ;
if ( ! V_494 ) {
F_303 ( L_157 ) ;
return - V_222 ;
}
V_496 = V_494 -> V_499 ;
V_494 = F_335 ( F_336 ( V_529 ) ,
& V_406 ) ;
if ( ! V_494 ) {
F_303 ( L_158 ) ;
return - V_222 ;
}
V_497 = V_494 -> V_499 ;
if ( V_530 == 0 ) {
F_338 ( L_159 ,
V_510 , V_531 ) ;
V_530 = V_531 ;
}
V_52 -> V_1 = V_192 ;
V_52 -> V_352 = V_502 ;
V_52 -> V_117 = V_117 ;
V_52 -> V_120 = V_120 ;
V_52 -> V_238 = V_238 ;
V_52 -> V_291 = V_491 ;
V_52 -> V_523 = V_495 ;
V_52 -> V_110 = V_110 ;
V_52 -> V_265 = V_265 ;
V_52 -> V_53 = V_53 ;
V_52 -> V_505 = V_505 ;
V_52 -> V_241 [ 0 ] = 0 ;
V_52 -> V_104 = V_493 ;
V_52 -> V_94 = V_492 ;
V_52 -> V_513 = V_513 ;
V_52 -> V_515 = V_515 ;
V_52 -> V_123 = V_123 ;
V_52 -> V_532 = V_532 ;
V_52 -> V_530 = V_530 ;
V_52 -> V_443 = V_443 ;
V_52 -> V_372 = 1 ;
V_52 -> V_496 = V_496 ;
F_347 ( V_52 -> V_533 ) ;
V_52 -> V_497 = V_497 ;
if ( V_443 > 0 ) {
V_52 -> V_442 =
V_441 ( V_443 ) ;
} else {
V_52 -> V_442 =
(struct V_441 ) { 0 } ;
}
if ( V_241 ) {
strncpy ( V_52 -> V_241 , V_241 , V_60 ) ;
V_52 -> V_241 [ V_60 - 1 ] = 0 ;
}
memcpy ( V_52 -> V_289 , V_521 , sizeof( V_521 ) ) ;
return 0 ;
}
static void F_348 ( struct V_14 * V_16 ,
struct V_534 * V_463 ,
void * V_535 )
{
F_349 ( & V_463 -> V_536 ,
& V_537 ) ;
}
static void F_350 ( struct V_14 * V_16 )
{
F_349 ( & V_16 -> V_538 ,
& V_539 ) ;
F_351 ( V_16 , F_348 , NULL ) ;
V_16 -> V_540 = & V_541 ;
}
static int F_352 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_542 * V_543 = F_353 ( F_212 ( V_19 ) , V_544 ) ;
F_56 ( V_19 , L_160 ) ;
V_11 -> V_73 = F_354 ( V_19 -> V_59 ) ;
if ( ! V_11 -> V_73 )
return - V_128 ;
F_350 ( V_19 ) ;
F_355 ( & V_11 -> V_489 , & V_543 -> V_545 ) ;
F_356 ( V_11 ) ;
F_357 ( V_11 ) ;
if ( F_358 ( V_19 -> V_86 ) &&
V_19 -> V_87 == V_546 )
F_175 ( V_19 ) ;
return 0 ;
}
unsigned int F_359 ( void )
{
return V_513 ;
}
int F_360 ( struct V_407 * V_407 , const char * V_59 )
{
struct V_14 * V_19 ;
struct V_10 * V_11 ;
struct V_547 * V_548 ;
int V_26 ;
F_130 () ;
V_19 = F_361 ( sizeof( struct V_10 ) ,
V_59 ? V_59 : L_161 , V_549 ,
F_328 , V_513 ) ;
if ( ! V_19 ) {
F_303 ( L_162 , V_59 ) ;
F_45 () ;
return - V_128 ;
}
V_11 = F_11 ( V_19 ) ;
V_548 = & ( F_362 ( V_11 ) ) ;
V_548 -> V_550 = V_551 ;
F_363 ( V_19 , V_407 ) ;
V_19 -> V_552 = & V_553 ;
V_26 = F_364 ( V_19 ) ;
F_24 ( V_19 ) ;
F_45 () ;
if ( V_26 < 0 )
F_325 ( V_19 ) ;
return V_26 ;
}
static int T_12 F_365 ( struct V_407 * V_407 )
{
struct V_542 * V_543 = F_353 ( V_407 , V_544 ) ;
V_543 -> V_407 = V_407 ;
F_366 ( & V_543 -> V_545 ) ;
F_367 ( V_543 ) ;
F_368 ( V_543 ) ;
return 0 ;
}
static void T_13 F_369 ( struct V_407 * V_407 )
{
struct V_542 * V_543 = F_353 ( V_407 , V_544 ) ;
struct V_10 * V_11 , * V_554 ;
F_370 ( V_555 ) ;
F_371 ( V_543 ) ;
F_130 () ;
F_372 (bond, tmp_bond, &bn->dev_list, bond_list)
F_373 ( V_11 -> V_16 , & V_555 ) ;
F_374 ( & V_555 ) ;
F_45 () ;
F_375 ( V_543 ) ;
}
static int T_14 F_376 ( void )
{
int V_212 ;
int V_26 ;
F_337 ( L_163 , V_556 ) ;
V_26 = F_334 ( & V_475 ) ;
if ( V_26 )
goto V_99;
V_26 = F_377 ( & V_557 ) ;
if ( V_26 )
goto V_99;
V_26 = F_378 () ;
if ( V_26 )
goto V_558;
F_379 () ;
for ( V_212 = 0 ; V_212 < V_509 ; V_212 ++ ) {
V_26 = F_360 ( & V_559 , NULL ) ;
if ( V_26 )
goto V_67;
}
F_380 ( & V_560 ) ;
V_99:
return V_26 ;
V_67:
F_381 () ;
F_382 () ;
V_558:
F_383 ( & V_557 ) ;
goto V_99;
}
static void T_15 F_384 ( void )
{
F_385 ( & V_560 ) ;
F_381 () ;
F_382 () ;
F_383 ( & V_557 ) ;
#ifdef F_161
F_300 ( F_386 ( & V_561 ) ) ;
#endif
}
