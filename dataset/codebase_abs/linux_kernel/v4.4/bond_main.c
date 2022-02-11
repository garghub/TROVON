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
F_74 ( V_80 , V_30 ) ;
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
static int F_117 ( struct V_14 * V_19 ,
struct V_14 * V_15 ,
struct V_22 * V_22 )
{
int V_67 ;
V_67 = F_118 ( V_15 , V_19 , V_22 ) ;
if ( V_67 )
return V_67 ;
V_15 -> V_82 |= V_178 ;
F_119 ( V_179 , V_15 , V_178 , V_127 ) ;
return 0 ;
}
static void F_120 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
F_121 ( V_15 , V_19 ) ;
V_15 -> V_82 &= ~ V_178 ;
F_119 ( V_179 , V_15 , V_178 , V_127 ) ;
}
static struct V_22 * F_122 ( struct V_10 * V_11 )
{
struct V_22 * V_22 = NULL ;
V_22 = F_83 ( sizeof( struct V_22 ) , V_127 ) ;
if ( ! V_22 )
return NULL ;
if ( F_20 ( V_11 ) == V_7 ) {
F_91 ( V_22 ) = F_83 ( sizeof( struct V_180 ) ,
V_127 ) ;
if ( ! F_91 ( V_22 ) ) {
F_85 ( V_22 ) ;
return NULL ;
}
}
return V_22 ;
}
static void F_123 ( struct V_22 * V_22 )
{
struct V_10 * V_11 = F_124 ( V_22 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_85 ( F_91 ( V_22 ) ) ;
F_85 ( V_22 ) ;
}
static void F_125 ( struct V_10 * V_11 , struct V_181 * V_182 )
{
V_182 -> V_183 = F_20 ( V_11 ) ;
V_182 -> V_117 = V_11 -> V_52 . V_117 ;
V_182 -> V_184 = V_11 -> V_185 ;
}
static void F_126 ( struct V_22 * V_22 , struct V_186 * V_182 )
{
strcpy ( V_182 -> V_187 , V_22 -> V_16 -> V_59 ) ;
V_182 -> V_29 = V_22 -> V_29 ;
V_182 -> V_114 = F_127 ( V_22 ) ;
V_182 -> V_188 = V_22 -> V_188 ;
}
static void F_128 ( struct V_14 * V_16 ,
struct V_189 * V_182 )
{
F_129 () ;
F_130 ( V_16 , V_182 ) ;
F_45 () ;
}
static void F_131 ( struct V_70 * V_190 )
{
struct V_191 * V_192 =
F_41 ( V_190 , struct V_191 , V_71 . V_71 ) ;
F_128 ( V_192 -> V_16 , & V_192 -> V_193 ) ;
F_132 ( V_192 -> V_16 ) ;
F_85 ( V_192 ) ;
}
void F_133 ( struct V_22 * V_22 )
{
struct V_10 * V_11 = V_22 -> V_11 ;
struct V_191 * V_194 = F_83 ( sizeof( * V_194 ) , V_171 ) ;
if ( ! V_194 )
return;
F_134 ( V_22 -> V_16 ) ;
V_194 -> V_16 = V_22 -> V_16 ;
F_126 ( V_22 , & V_194 -> V_193 . V_22 ) ;
F_125 ( V_11 , & V_194 -> V_193 . V_195 ) ;
F_135 ( & V_194 -> V_71 , F_131 ) ;
F_43 ( V_22 -> V_11 -> V_73 , & V_194 -> V_71 , 0 ) ;
}
int F_136 ( struct V_14 * V_19 , struct V_14 * V_15 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
const struct V_45 * V_46 = V_15 -> V_47 ;
struct V_22 * V_196 = NULL , * V_197 ;
struct V_91 V_198 ;
int V_199 ;
int V_26 = 0 , V_200 ;
if ( ! V_11 -> V_52 . V_53 &&
V_15 -> V_55 -> V_56 == NULL &&
V_46 -> V_57 == NULL ) {
F_137 ( V_19 , L_23 ,
V_15 -> V_59 ) ;
}
if ( V_15 -> V_82 & V_178 ) {
F_56 ( V_19 , L_24 ) ;
return - V_201 ;
}
if ( V_19 == V_15 ) {
F_62 ( V_19 , L_25 ) ;
return - V_202 ;
}
if ( V_15 -> V_141 & V_203 ) {
F_56 ( V_19 , L_26 ,
V_15 -> V_59 ) ;
if ( F_138 ( V_19 ) ) {
F_62 ( V_19 , L_27 ,
V_15 -> V_59 , V_19 -> V_59 ) ;
return - V_202 ;
} else {
F_137 ( V_19 , L_28 ,
V_15 -> V_59 , V_15 -> V_59 ,
V_19 -> V_59 ) ;
}
} else {
F_56 ( V_19 , L_29 ,
V_15 -> V_59 ) ;
}
if ( ( V_15 -> V_82 & V_204 ) ) {
F_62 ( V_19 , L_30 ,
V_15 -> V_59 ) ;
V_26 = - V_202 ;
goto V_205;
}
if ( ! F_19 ( V_11 ) ) {
if ( V_19 -> type != V_15 -> type ) {
F_56 ( V_19 , L_31 ,
V_19 -> type , V_15 -> type ) ;
V_26 = F_44 ( V_206 ,
V_19 ) ;
V_26 = F_139 ( V_26 ) ;
if ( V_26 ) {
F_62 ( V_19 , L_32 ) ;
V_26 = - V_201 ;
goto V_205;
}
F_140 ( V_19 ) ;
F_141 ( V_19 ) ;
if ( V_15 -> type != V_207 )
F_104 ( V_19 , V_15 ) ;
else {
F_142 ( V_19 ) ;
V_19 -> V_160 &= ~ V_208 ;
}
F_44 ( V_209 ,
V_19 ) ;
}
} else if ( V_19 -> type != V_15 -> type ) {
F_62 ( V_19 , L_33 ,
V_15 -> V_59 , V_15 -> type , V_19 -> type ) ;
V_26 = - V_210 ;
goto V_205;
}
if ( V_46 -> V_211 == NULL ) {
F_137 ( V_19 , L_34 ) ;
if ( F_20 ( V_11 ) == V_4 &&
V_11 -> V_52 . V_94 != V_95 ) {
if ( ! F_19 ( V_11 ) ) {
V_11 -> V_52 . V_94 = V_95 ;
F_137 ( V_19 , L_35 ) ;
} else {
F_62 ( V_19 , L_36 ) ;
V_26 = - V_212 ;
goto V_205;
}
}
}
F_44 ( V_213 , V_15 ) ;
if ( ! F_19 ( V_11 ) &&
V_11 -> V_16 -> V_87 == V_214 )
F_55 ( V_11 -> V_16 , V_15 ) ;
V_196 = F_122 ( V_11 ) ;
if ( ! V_196 ) {
V_26 = - V_128 ;
goto V_205;
}
V_196 -> V_11 = V_11 ;
V_196 -> V_16 = V_15 ;
V_196 -> V_215 = 0 ;
V_196 -> V_216 = V_15 -> V_217 ;
V_26 = F_143 ( V_15 , V_11 -> V_16 -> V_217 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_37 , V_26 ) ;
goto V_218;
}
F_60 ( V_196 -> V_219 , V_15 -> V_86 ) ;
if ( ! V_11 -> V_52 . V_94 ||
F_20 ( V_11 ) != V_4 ) {
memcpy ( V_198 . V_97 , V_19 -> V_86 , V_19 -> V_85 ) ;
V_198 . V_98 = V_15 -> type ;
V_26 = F_61 ( V_15 , & V_198 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_38 , V_26 ) ;
goto V_220;
}
}
V_26 = F_144 ( V_15 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_39 , V_15 -> V_59 ) ;
goto V_221;
}
V_15 -> V_160 |= V_222 ;
F_145 ( V_196 -> V_16 , & V_196 -> V_223 ) ;
if ( F_16 ( V_11 ) ) {
V_26 = F_146 ( V_11 , V_196 ) ;
if ( V_26 )
goto V_224;
}
if ( ! F_35 ( V_11 ) ) {
if ( V_19 -> V_82 & V_83 ) {
V_26 = F_37 ( V_15 , 1 ) ;
if ( V_26 )
goto V_224;
}
if ( V_19 -> V_82 & V_84 ) {
V_26 = F_39 ( V_15 , 1 ) ;
if ( V_26 )
goto V_224;
}
F_51 ( V_19 ) ;
F_147 ( V_15 , V_19 ) ;
F_148 ( V_15 , V_19 ) ;
F_54 ( V_19 ) ;
}
if ( F_20 ( V_11 ) == V_7 ) {
T_5 V_77 [ V_78 ] = V_79 ;
F_149 ( V_15 , V_77 ) ;
}
V_26 = F_150 ( V_15 , V_19 ) ;
if ( V_26 ) {
F_62 ( V_19 , L_40 ,
V_15 -> V_59 ) ;
goto V_224;
}
V_197 = F_151 ( V_11 ) ;
V_196 -> V_111 = 0 ;
V_196 -> V_188 = 0 ;
F_25 ( V_196 ) ;
V_196 -> V_225 = V_116 -
( F_152 ( V_11 -> V_52 . V_226 ) + 1 ) ;
for ( V_200 = 0 ; V_200 < V_227 ; V_200 ++ )
V_196 -> V_228 [ V_200 ] = V_196 -> V_225 ;
if ( V_11 -> V_52 . V_117 && ! V_11 -> V_52 . V_53 ) {
V_199 = F_29 ( V_11 , V_15 , 1 ) ;
if ( ( V_199 == - 1 ) && ! V_11 -> V_52 . V_226 ) {
F_137 ( V_19 , L_41 ,
V_15 -> V_59 ) ;
} else if ( V_199 == - 1 ) {
F_137 ( V_19 , L_42 ,
V_15 -> V_59 ) ;
}
}
if ( V_11 -> V_52 . V_117 ) {
if ( F_29 ( V_11 , V_15 , 0 ) == V_54 ) {
if ( V_11 -> V_52 . V_110 ) {
F_74 ( V_196 ,
V_43 ) ;
V_196 -> V_111 = V_11 -> V_52 . V_110 ;
} else {
F_74 ( V_196 ,
V_30 ) ;
}
} else {
F_74 ( V_196 , V_42 ) ;
}
} else if ( V_11 -> V_52 . V_226 ) {
F_74 ( V_196 ,
( F_22 ( V_15 ) ?
V_30 : V_42 ) ) ;
} else {
F_74 ( V_196 , V_30 ) ;
}
if ( V_196 -> V_29 != V_42 )
V_196 -> V_115 = V_116 ;
F_56 ( V_19 , L_43 ,
V_196 -> V_29 == V_42 ? L_44 :
( V_196 -> V_29 == V_30 ? L_45 : L_46 ) ) ;
if ( F_35 ( V_11 ) && V_11 -> V_52 . V_229 [ 0 ] ) {
if ( strcmp ( V_11 -> V_52 . V_229 , V_196 -> V_16 -> V_59 ) == 0 ) {
F_80 ( V_11 -> V_101 , V_196 ) ;
V_11 -> V_103 = true ;
}
}
switch ( F_20 ( V_11 ) ) {
case V_4 :
F_78 ( V_196 ,
V_118 ) ;
break;
case V_7 :
F_78 ( V_196 , V_118 ) ;
if ( ! V_197 ) {
F_91 ( V_196 ) -> V_230 = 1 ;
F_153 ( V_11 , 1000 / V_231 ) ;
} else {
F_91 ( V_196 ) -> V_230 =
F_91 ( V_197 ) -> V_230 + 1 ;
}
F_154 ( V_196 ) ;
break;
case V_8 :
case V_9 :
F_155 ( V_196 ) ;
F_78 ( V_196 , V_118 ) ;
break;
default:
F_56 ( V_19 , L_47 ) ;
F_155 ( V_196 ) ;
if ( ! F_156 ( V_11 -> V_69 ) &&
V_196 -> V_29 == V_30 )
F_80 ( V_11 -> V_69 , V_196 ) ;
break;
}
#ifdef F_157
V_15 -> V_139 = V_11 -> V_16 -> V_139 ;
if ( V_15 -> V_139 ) {
if ( F_82 ( V_196 ) ) {
F_73 ( V_19 , L_48 ) ;
V_26 = - V_201 ;
goto V_232;
}
}
#endif
if ( ! ( V_19 -> V_141 & V_233 ) )
F_158 ( V_15 ) ;
V_26 = F_159 ( V_15 , F_107 ,
V_196 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_49 , V_26 ) ;
goto V_232;
}
V_26 = F_117 ( V_19 , V_15 , V_196 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_50 , V_26 ) ;
goto V_234;
}
V_26 = F_160 ( V_196 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_51 , V_26 ) ;
goto V_235;
}
V_11 -> V_185 ++ ;
F_100 ( V_11 ) ;
F_18 ( V_11 ) ;
if ( F_35 ( V_11 ) ) {
F_161 () ;
F_81 ( V_11 ) ;
F_162 () ;
}
if ( F_163 ( V_11 ) )
F_164 ( V_11 , NULL ) ;
F_73 ( V_19 , L_52 ,
V_15 -> V_59 ,
F_165 ( V_196 ) ? L_53 : L_54 ,
V_196 -> V_29 != V_42 ? L_55 : L_56 ) ;
F_133 ( V_196 ) ;
return 0 ;
V_235:
F_120 ( V_19 , V_15 ) ;
V_234:
F_166 ( V_15 ) ;
V_232:
if ( ! F_35 ( V_11 ) )
F_46 ( V_19 , V_15 ) ;
F_167 ( V_15 , V_19 ) ;
if ( F_156 ( V_11 -> V_101 ) == V_196 )
F_168 ( V_11 -> V_101 , NULL ) ;
if ( F_156 ( V_11 -> V_69 ) == V_196 ) {
F_161 () ;
F_71 ( V_11 , NULL ) ;
F_81 ( V_11 ) ;
F_162 () ;
}
F_169 () ;
F_86 ( V_196 ) ;
V_224:
V_15 -> V_160 &= ~ V_222 ;
F_170 ( V_15 ) ;
V_221:
if ( ! V_11 -> V_52 . V_94 ||
F_20 ( V_11 ) != V_4 ) {
F_60 ( V_198 . V_97 , V_196 -> V_219 ) ;
V_198 . V_98 = V_15 -> type ;
F_61 ( V_15 , & V_198 ) ;
}
V_220:
F_143 ( V_15 , V_196 -> V_216 ) ;
V_218:
F_123 ( V_196 ) ;
V_205:
if ( ! F_19 ( V_11 ) ) {
if ( F_171 ( V_19 -> V_86 ,
V_15 -> V_86 ) )
F_172 ( V_19 ) ;
if ( V_19 -> type != V_207 ) {
F_170 ( V_19 ) ;
F_142 ( V_19 ) ;
V_19 -> V_82 |= V_236 ;
V_19 -> V_160 &= ~ V_208 ;
}
}
return V_26 ;
}
static int F_173 ( struct V_14 * V_19 ,
struct V_14 * V_15 ,
bool V_237 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_238 ;
struct V_91 V_198 ;
int V_239 = V_19 -> V_82 ;
T_6 V_240 = V_19 -> V_141 ;
if ( ! ( V_15 -> V_82 & V_178 ) ||
! F_174 ( V_15 , V_19 ) ) {
F_56 ( V_19 , L_57 ,
V_15 -> V_59 ) ;
return - V_210 ;
}
F_161 () ;
V_22 = F_8 ( V_11 , V_15 ) ;
if ( ! V_22 ) {
F_73 ( V_19 , L_58 ,
V_15 -> V_59 ) ;
F_162 () ;
return - V_210 ;
}
F_175 ( V_22 ) ;
F_176 ( V_11 -> V_16 , & V_11 -> V_241 ) ;
F_120 ( V_19 , V_15 ) ;
F_166 ( V_15 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_177 ( V_22 ) ;
if ( F_163 ( V_11 ) )
F_164 ( V_11 , V_22 ) ;
F_73 ( V_19 , L_59 ,
F_165 ( V_22 ) ? L_60 : L_61 ,
V_15 -> V_59 ) ;
V_238 = F_156 ( V_11 -> V_69 ) ;
F_168 ( V_11 -> V_242 , NULL ) ;
if ( ! V_237 && ( ! V_11 -> V_52 . V_94 ||
F_20 ( V_11 ) != V_4 ) ) {
if ( F_171 ( V_19 -> V_86 , V_22 -> V_219 ) &&
F_19 ( V_11 ) )
F_137 ( V_19 , L_62 ,
V_15 -> V_59 , V_22 -> V_219 ,
V_19 -> V_59 , V_15 -> V_59 ) ;
}
if ( F_36 ( V_11 -> V_101 ) == V_22 )
F_168 ( V_11 -> V_101 , NULL ) ;
if ( V_238 == V_22 )
F_71 ( V_11 , NULL ) ;
if ( F_16 ( V_11 ) ) {
F_178 ( V_11 , V_22 ) ;
}
if ( V_237 ) {
F_168 ( V_11 -> V_69 , NULL ) ;
} else if ( V_238 == V_22 ) {
F_81 ( V_11 ) ;
}
if ( ! F_19 ( V_11 ) ) {
F_18 ( V_11 ) ;
F_172 ( V_19 ) ;
}
F_162 () ;
F_169 () ;
V_11 -> V_185 -- ;
if ( ! F_19 ( V_11 ) ) {
F_44 ( V_89 , V_11 -> V_16 ) ;
F_44 ( V_243 , V_11 -> V_16 ) ;
}
F_100 ( V_11 ) ;
if ( ! ( V_19 -> V_141 & V_203 ) &&
( V_240 & V_203 ) )
F_73 ( V_19 , L_63 ,
V_15 -> V_59 , V_19 -> V_59 ) ;
F_167 ( V_15 , V_19 ) ;
if ( ! F_35 ( V_11 ) ) {
if ( V_239 & V_83 )
F_37 ( V_15 , - 1 ) ;
if ( V_239 & V_84 )
F_39 ( V_15 , - 1 ) ;
F_46 ( V_19 , V_15 ) ;
}
F_86 ( V_22 ) ;
F_170 ( V_15 ) ;
if ( V_11 -> V_52 . V_94 != V_95 ||
F_20 ( V_11 ) != V_4 ) {
F_60 ( V_198 . V_97 , V_22 -> V_219 ) ;
V_198 . V_98 = V_15 -> type ;
F_61 ( V_15 , & V_198 ) ;
}
F_143 ( V_15 , V_22 -> V_216 ) ;
V_15 -> V_160 &= ~ V_222 ;
F_123 ( V_22 ) ;
return 0 ;
}
int F_179 ( struct V_14 * V_19 , struct V_14 * V_15 )
{
return F_173 ( V_19 , V_15 , false ) ;
}
static int F_180 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
int V_169 ;
V_169 = F_179 ( V_19 , V_15 ) ;
if ( V_169 == 0 && ! F_19 ( V_11 ) ) {
V_19 -> V_160 |= V_244 ;
F_73 ( V_19 , L_64 ,
V_19 -> V_59 ) ;
F_181 ( V_11 ) ;
F_182 ( V_19 ) ;
}
return V_169 ;
}
static int F_183 ( struct V_14 * V_19 , struct V_181 * V_182 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_125 ( V_11 , V_182 ) ;
return 0 ;
}
static int F_184 ( struct V_14 * V_19 , struct V_186 * V_182 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
int V_200 = 0 , V_26 = - V_245 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
if ( V_200 ++ == ( int ) V_182 -> V_246 ) {
V_26 = 0 ;
F_126 ( V_22 , V_182 ) ;
break;
}
}
return V_26 ;
}
static int F_185 ( struct V_10 * V_11 )
{
int V_247 , V_248 = 0 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
bool V_249 ;
V_249 = ! F_68 ( V_11 -> V_69 ) ;
F_90 (bond, slave, iter) {
V_22 -> V_250 = V_251 ;
V_247 = F_29 ( V_11 , V_22 -> V_16 , 0 ) ;
switch ( V_22 -> V_29 ) {
case V_30 :
if ( V_247 )
continue;
F_74 ( V_22 , V_41 ) ;
V_22 -> V_111 = V_11 -> V_52 . V_252 ;
if ( V_22 -> V_111 ) {
F_73 ( V_11 -> V_16 , L_65 ,
( F_20 ( V_11 ) ==
V_4 ) ?
( F_165 ( V_22 ) ?
L_66 : L_67 ) : L_68 ,
V_22 -> V_16 -> V_59 ,
V_11 -> V_52 . V_252 * V_11 -> V_52 . V_117 ) ;
}
case V_41 :
if ( V_247 ) {
F_74 ( V_22 , V_30 ) ;
V_22 -> V_115 = V_116 ;
F_73 ( V_11 -> V_16 , L_69 ,
( V_11 -> V_52 . V_252 - V_22 -> V_111 ) *
V_11 -> V_52 . V_117 ,
V_22 -> V_16 -> V_59 ) ;
continue;
}
if ( V_22 -> V_111 <= 0 ) {
V_22 -> V_250 = V_42 ;
V_248 ++ ;
continue;
}
V_22 -> V_111 -- ;
break;
case V_42 :
if ( ! V_247 )
continue;
F_74 ( V_22 , V_43 ) ;
V_22 -> V_111 = V_11 -> V_52 . V_110 ;
if ( V_22 -> V_111 ) {
F_73 ( V_11 -> V_16 , L_70 ,
V_22 -> V_16 -> V_59 ,
V_249 ? 0 :
V_11 -> V_52 . V_110 *
V_11 -> V_52 . V_117 ) ;
}
case V_43 :
if ( ! V_247 ) {
F_74 ( V_22 ,
V_42 ) ;
F_73 ( V_11 -> V_16 , L_71 ,
( V_11 -> V_52 . V_110 - V_22 -> V_111 ) *
V_11 -> V_52 . V_117 ,
V_22 -> V_16 -> V_59 ) ;
continue;
}
if ( V_249 )
V_22 -> V_111 = 0 ;
if ( V_22 -> V_111 <= 0 ) {
V_22 -> V_250 = V_30 ;
V_248 ++ ;
V_249 = false ;
continue;
}
V_22 -> V_111 -- ;
break;
}
}
return V_248 ;
}
static void F_186 ( struct V_10 * V_11 )
{
struct V_24 * V_25 ;
struct V_22 * V_22 , * V_229 ;
F_12 (bond, slave, iter) {
switch ( V_22 -> V_250 ) {
case V_251 :
continue;
case V_30 :
F_74 ( V_22 , V_30 ) ;
V_22 -> V_115 = V_116 ;
V_229 = F_36 ( V_11 -> V_101 ) ;
if ( F_20 ( V_11 ) == V_7 ) {
F_187 ( V_22 ) ;
} else if ( F_20 ( V_11 ) != V_4 ) {
F_155 ( V_22 ) ;
} else if ( V_22 != V_229 ) {
F_187 ( V_22 ) ;
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
F_164 ( V_11 , NULL ) ;
if ( ! V_11 -> V_69 || V_22 == V_229 )
goto V_253;
continue;
case V_42 :
if ( V_22 -> V_188 < V_254 )
V_22 -> V_188 ++ ;
F_74 ( V_22 , V_42 ) ;
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
F_164 ( V_11 , NULL ) ;
if ( V_22 == F_156 ( V_11 -> V_69 ) )
goto V_253;
continue;
default:
F_62 ( V_11 -> V_16 , L_76 ,
V_22 -> V_250 , V_22 -> V_16 -> V_59 ) ;
V_22 -> V_250 = V_251 ;
continue;
}
V_253:
F_161 () ;
F_81 ( V_11 ) ;
F_162 () ;
}
F_18 ( V_11 ) ;
}
static void F_188 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_41 ( V_71 , struct V_10 ,
V_255 . V_71 ) ;
bool V_119 = false ;
unsigned long V_111 ;
V_111 = F_152 ( V_11 -> V_52 . V_117 ) ;
if ( ! F_19 ( V_11 ) )
goto V_256;
F_67 () ;
V_119 = F_66 ( V_11 ) ;
if ( F_185 ( V_11 ) ) {
F_69 () ;
if ( ! F_42 () ) {
V_111 = 1 ;
V_119 = false ;
goto V_256;
}
F_186 ( V_11 ) ;
F_45 () ;
} else
F_69 () ;
V_256:
if ( V_11 -> V_52 . V_117 )
F_43 ( V_11 -> V_73 , & V_11 -> V_255 , V_111 ) ;
if ( V_119 ) {
if ( ! F_42 () )
return;
F_44 ( V_122 , V_11 -> V_16 ) ;
F_45 () ;
}
}
static bool F_189 ( struct V_10 * V_11 , T_8 V_257 )
{
struct V_14 * V_258 ;
struct V_24 * V_25 ;
bool V_169 = false ;
if ( V_257 == F_190 ( V_11 -> V_16 , 0 , V_257 ) )
return true ;
F_67 () ;
F_191 (bond->dev, upper, iter) {
if ( V_257 == F_190 ( V_258 , 0 , V_257 ) ) {
V_169 = true ;
break;
}
}
F_69 () ;
return V_169 ;
}
static void F_192 ( struct V_14 * V_15 , int V_259 ,
T_8 V_260 , T_8 V_261 ,
struct V_262 * V_263 )
{
struct V_12 * V_13 ;
struct V_262 * V_264 = V_263 ;
F_56 ( V_15 , L_77 ,
V_259 , V_15 -> V_59 , & V_260 , & V_261 ) ;
V_13 = F_193 ( V_259 , V_265 , V_260 , V_15 , V_261 ,
NULL , V_15 -> V_86 , NULL ) ;
if ( ! V_13 ) {
F_194 ( L_78 ) ;
return;
}
if ( ! V_263 || V_263 -> V_266 == V_267 )
goto V_268;
V_263 ++ ;
while ( V_263 -> V_266 != V_267 ) {
if ( ! V_263 -> V_269 ) {
V_263 ++ ;
continue;
}
F_56 ( V_15 , L_79 ,
F_195 ( V_264 -> V_266 ) , V_263 -> V_269 ) ;
V_13 = F_196 ( V_13 , V_263 -> V_266 ,
V_263 -> V_269 ) ;
if ( ! V_13 ) {
F_194 ( L_80 ) ;
return;
}
V_263 ++ ;
}
if ( V_264 -> V_269 ) {
F_56 ( V_15 , L_81 ,
F_195 ( V_264 -> V_266 ) , V_264 -> V_269 ) ;
F_197 ( V_13 , V_264 -> V_266 ,
V_264 -> V_269 ) ;
}
V_268:
F_198 ( V_13 ) ;
}
struct V_262 * F_199 ( struct V_14 * V_270 ,
struct V_14 * V_271 ,
int V_272 )
{
struct V_262 * V_263 ;
struct V_14 * V_258 ;
struct V_24 * V_25 ;
if ( V_270 == V_271 ) {
V_263 = F_83 ( sizeof( * V_263 ) * ( V_272 + 1 ) , V_171 ) ;
if ( ! V_263 )
return F_200 ( - V_128 ) ;
V_263 [ V_272 ] . V_266 = V_267 ;
return V_263 ;
}
F_201 (start_dev, upper, iter) {
V_263 = F_199 ( V_258 , V_271 , V_272 + 1 ) ;
if ( F_202 ( V_263 ) ) {
if ( F_203 ( V_263 ) )
return V_263 ;
continue;
}
if ( F_204 ( V_258 ) ) {
V_263 [ V_272 ] . V_266 = F_205 ( V_258 ) ;
V_263 [ V_272 ] . V_269 = F_206 ( V_258 ) ;
}
return V_263 ;
}
return NULL ;
}
static void F_207 ( struct V_10 * V_11 , struct V_22 * V_22 )
{
struct V_273 * V_274 ;
struct V_262 * V_263 ;
T_8 * V_275 = V_11 -> V_52 . V_276 , V_198 ;
int V_200 ;
for ( V_200 = 0 ; V_200 < V_227 && V_275 [ V_200 ] ; V_200 ++ ) {
F_56 ( V_11 -> V_16 , L_82 , & V_275 [ V_200 ] ) ;
V_263 = NULL ;
V_274 = F_208 ( F_209 ( V_11 -> V_16 ) , V_275 [ V_200 ] , 0 ,
V_277 , 0 ) ;
if ( F_203 ( V_274 ) ) {
if ( V_11 -> V_52 . V_278 )
F_210 ( L_83 ,
V_11 -> V_16 -> V_59 ,
& V_275 [ V_200 ] ) ;
F_192 ( V_22 -> V_16 , V_279 , V_275 [ V_200 ] ,
0 , V_263 ) ;
continue;
}
if ( V_274 -> V_280 . V_16 == V_11 -> V_16 )
goto V_281;
F_67 () ;
V_263 = F_199 ( V_11 -> V_16 , V_274 -> V_280 . V_16 , 0 ) ;
F_69 () ;
if ( ! F_202 ( V_263 ) )
goto V_281;
F_56 ( V_11 -> V_16 , L_84 ,
& V_275 [ V_200 ] , V_274 -> V_280 . V_16 ? V_274 -> V_280 . V_16 -> V_59 : L_18 ) ;
F_211 ( V_274 ) ;
continue;
V_281:
V_198 = F_190 ( V_274 -> V_280 . V_16 , V_275 [ V_200 ] , 0 ) ;
F_211 ( V_274 ) ;
F_192 ( V_22 -> V_16 , V_279 , V_275 [ V_200 ] ,
V_198 , V_263 ) ;
F_85 ( V_263 ) ;
}
}
static void F_212 ( struct V_10 * V_11 , struct V_22 * V_22 , T_8 V_282 , T_8 V_283 )
{
int V_200 ;
if ( ! V_282 || ! F_189 ( V_11 , V_283 ) ) {
F_56 ( V_11 -> V_16 , L_85 ,
& V_282 , & V_283 ) ;
return;
}
V_200 = F_213 ( V_11 -> V_52 . V_276 , V_282 ) ;
if ( V_200 == - 1 ) {
F_56 ( V_11 -> V_16 , L_86 ,
& V_282 ) ;
return;
}
V_22 -> V_225 = V_116 ;
V_22 -> V_228 [ V_200 ] = V_116 ;
}
int F_214 ( const struct V_12 * V_13 , struct V_10 * V_11 ,
struct V_22 * V_22 )
{
struct V_284 * V_285 = (struct V_284 * ) V_13 -> V_176 ;
struct V_22 * V_69 ;
unsigned char * V_286 ;
T_8 V_282 , V_283 ;
int V_287 , V_288 = V_13 -> V_289 == F_215 ( V_265 ) ;
if ( ! F_216 ( V_11 , V_22 ) ) {
if ( ( F_217 ( V_11 ) && V_288 ) ||
! F_217 ( V_11 ) )
V_22 -> V_225 = V_116 ;
return V_170 ;
} else if ( ! V_288 ) {
return V_170 ;
}
V_287 = F_218 ( V_11 -> V_16 ) ;
F_56 ( V_11 -> V_16 , L_87 ,
V_13 -> V_16 -> V_59 ) ;
if ( V_287 > F_219 ( V_13 ) ) {
V_285 = F_220 ( V_287 , V_171 ) ;
if ( ! V_285 )
goto V_290;
if ( F_221 ( V_13 , 0 , V_285 , V_287 ) < 0 )
goto V_290;
}
if ( V_285 -> V_291 != V_11 -> V_16 -> V_85 ||
V_13 -> V_165 == V_292 ||
V_13 -> V_165 == V_293 ||
V_285 -> V_294 != F_222 ( V_207 ) ||
V_285 -> V_295 != F_222 ( V_296 ) ||
V_285 -> V_297 != 4 )
goto V_290;
V_286 = ( unsigned char * ) ( V_285 + 1 ) ;
V_286 += V_11 -> V_16 -> V_85 ;
memcpy ( & V_282 , V_286 , 4 ) ;
V_286 += 4 + V_11 -> V_16 -> V_85 ;
memcpy ( & V_283 , V_286 , 4 ) ;
F_56 ( V_11 -> V_16 , L_88 ,
V_22 -> V_16 -> V_59 , F_127 ( V_22 ) ,
V_11 -> V_52 . V_278 , F_216 ( V_11 , V_22 ) ,
& V_282 , & V_283 ) ;
V_69 = F_68 ( V_11 -> V_69 ) ;
if ( F_165 ( V_22 ) )
F_212 ( V_11 , V_22 , V_282 , V_283 ) ;
else if ( V_69 &&
F_223 ( F_224 ( V_11 , V_69 ) ,
V_69 -> V_115 ) )
F_212 ( V_11 , V_22 , V_283 , V_282 ) ;
V_290:
if ( V_285 != (struct V_284 * ) V_13 -> V_176 )
F_85 ( V_285 ) ;
return V_170 ;
}
static bool F_225 ( struct V_10 * V_11 , unsigned long V_298 ,
int V_299 )
{
int V_300 = F_152 ( V_11 -> V_52 . V_226 ) ;
return F_226 ( V_116 ,
V_298 - V_300 ,
V_298 + V_299 * V_300 + V_300 / 2 ) ;
}
static void F_227 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_41 ( V_71 , struct V_10 ,
V_301 . V_71 ) ;
struct V_22 * V_22 , * V_238 ;
struct V_24 * V_25 ;
int V_253 = 0 , V_302 = 0 ;
if ( ! F_19 ( V_11 ) )
goto V_256;
F_67 () ;
V_238 = F_68 ( V_11 -> V_69 ) ;
F_90 (bond, slave, iter) {
unsigned long V_303 = F_228 ( V_22 -> V_16 ) ;
if ( V_22 -> V_29 != V_30 ) {
if ( F_225 ( V_11 , V_303 , 1 ) &&
F_225 ( V_11 , V_22 -> V_225 , 1 ) ) {
V_22 -> V_29 = V_30 ;
V_302 = 1 ;
if ( ! V_238 ) {
F_73 ( V_11 -> V_16 , L_89 ,
V_22 -> V_16 -> V_59 ) ;
V_253 = 1 ;
} else {
F_73 ( V_11 -> V_16 , L_90 ,
V_22 -> V_16 -> V_59 ) ;
}
}
} else {
if ( ! F_225 ( V_11 , V_303 , 2 ) ||
! F_225 ( V_11 , V_22 -> V_225 , 2 ) ) {
V_22 -> V_29 = V_42 ;
V_302 = 1 ;
if ( V_22 -> V_188 < V_254 )
V_22 -> V_188 ++ ;
F_73 ( V_11 -> V_16 , L_91 ,
V_22 -> V_16 -> V_59 ) ;
if ( V_22 == V_238 )
V_253 = 1 ;
}
}
if ( F_65 ( V_22 ) )
F_207 ( V_11 , V_22 ) ;
}
F_69 () ;
if ( V_253 || V_302 ) {
if ( ! F_42 () )
goto V_256;
if ( V_302 ) {
F_229 ( V_11 ) ;
if ( F_20 ( V_11 ) == V_5 )
F_164 ( V_11 , NULL ) ;
}
if ( V_253 ) {
F_161 () ;
F_81 ( V_11 ) ;
F_162 () ;
}
F_45 () ;
}
V_256:
if ( V_11 -> V_52 . V_226 )
F_43 ( V_11 -> V_73 , & V_11 -> V_301 ,
F_152 ( V_11 -> V_52 . V_226 ) ) ;
}
static int F_230 ( struct V_10 * V_11 )
{
unsigned long V_303 , V_225 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_248 = 0 ;
F_90 (bond, slave, iter) {
V_22 -> V_250 = V_251 ;
V_225 = F_224 ( V_11 , V_22 ) ;
if ( V_22 -> V_29 != V_30 ) {
if ( F_225 ( V_11 , V_225 , 1 ) ) {
V_22 -> V_250 = V_30 ;
V_248 ++ ;
}
continue;
}
if ( F_225 ( V_11 , V_22 -> V_115 , 2 ) )
continue;
if ( ! F_165 ( V_22 ) &&
! F_156 ( V_11 -> V_242 ) &&
! F_225 ( V_11 , V_225 , 3 ) ) {
V_22 -> V_250 = V_42 ;
V_248 ++ ;
}
V_303 = F_228 ( V_22 -> V_16 ) ;
if ( F_165 ( V_22 ) &&
( ! F_225 ( V_11 , V_303 , 2 ) ||
! F_225 ( V_11 , V_225 , 2 ) ) ) {
V_22 -> V_250 = V_42 ;
V_248 ++ ;
}
}
return V_248 ;
}
static void F_231 ( struct V_10 * V_11 )
{
unsigned long V_303 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
switch ( V_22 -> V_250 ) {
case V_251 :
continue;
case V_30 :
V_303 = F_228 ( V_22 -> V_16 ) ;
if ( F_36 ( V_11 -> V_69 ) != V_22 ||
( ! F_36 ( V_11 -> V_69 ) &&
F_225 ( V_11 , V_303 , 1 ) ) ) {
struct V_22 * V_242 ;
V_242 = F_36 ( V_11 -> V_242 ) ;
F_74 ( V_22 , V_30 ) ;
if ( V_242 ) {
F_78 (
V_242 ,
V_118 ) ;
F_168 ( V_11 -> V_242 , NULL ) ;
}
F_73 ( V_11 -> V_16 , L_89 ,
V_22 -> V_16 -> V_59 ) ;
if ( ! F_36 ( V_11 -> V_69 ) ||
V_22 == F_36 ( V_11 -> V_101 ) )
goto V_253;
}
continue;
case V_42 :
if ( V_22 -> V_188 < V_254 )
V_22 -> V_188 ++ ;
F_74 ( V_22 , V_42 ) ;
F_78 ( V_22 ,
V_118 ) ;
F_73 ( V_11 -> V_16 , L_75 ,
V_22 -> V_16 -> V_59 ) ;
if ( V_22 == F_36 ( V_11 -> V_69 ) ) {
F_168 ( V_11 -> V_242 , NULL ) ;
goto V_253;
}
continue;
default:
F_62 ( V_11 -> V_16 , L_92 ,
V_22 -> V_250 , V_22 -> V_16 -> V_59 ) ;
continue;
}
V_253:
F_161 () ;
F_81 ( V_11 ) ;
F_162 () ;
}
F_18 ( V_11 ) ;
}
static bool F_232 ( struct V_10 * V_11 )
{
struct V_22 * V_22 , * V_304 = NULL , * V_196 = NULL ,
* V_305 = F_68 ( V_11 -> V_242 ) ,
* V_69 = F_68 ( V_11 -> V_69 ) ;
struct V_24 * V_25 ;
bool V_281 = false ;
bool V_306 = V_307 ;
if ( V_305 && V_69 )
F_73 ( V_11 -> V_16 , L_93 ,
V_305 -> V_16 -> V_59 ,
V_69 -> V_16 -> V_59 ) ;
if ( V_69 ) {
F_207 ( V_11 , V_69 ) ;
return V_306 ;
}
if ( ! V_305 ) {
V_305 = F_233 ( V_11 ) ;
if ( ! V_305 )
return V_306 ;
}
F_78 ( V_305 , V_307 ) ;
F_90 (bond, slave, iter) {
if ( ! V_281 && ! V_304 && F_65 ( V_22 ) )
V_304 = V_22 ;
if ( V_281 && ! V_196 && F_65 ( V_22 ) )
V_196 = V_22 ;
if ( ! F_65 ( V_22 ) && V_22 -> V_29 == V_30 ) {
F_74 ( V_22 , V_42 ) ;
if ( V_22 -> V_188 < V_254 )
V_22 -> V_188 ++ ;
F_78 ( V_22 ,
V_307 ) ;
F_73 ( V_11 -> V_16 , L_94 ,
V_22 -> V_16 -> V_59 ) ;
}
if ( V_22 == V_305 )
V_281 = true ;
}
if ( ! V_196 && V_304 )
V_196 = V_304 ;
if ( ! V_196 )
goto V_308;
F_74 ( V_196 , V_43 ) ;
F_79 ( V_196 , V_307 ) ;
F_207 ( V_11 , V_196 ) ;
V_196 -> V_115 = V_116 ;
F_80 ( V_11 -> V_242 , V_196 ) ;
V_308:
F_90 (bond, slave, iter) {
if ( V_22 -> V_309 ) {
V_306 = V_118 ;
break;
}
}
return V_306 ;
}
static void F_234 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_41 ( V_71 , struct V_10 ,
V_301 . V_71 ) ;
bool V_119 = false ;
bool V_306 = false ;
int V_300 ;
V_300 = F_152 ( V_11 -> V_52 . V_226 ) ;
if ( ! F_19 ( V_11 ) )
goto V_256;
F_67 () ;
V_119 = F_66 ( V_11 ) ;
if ( F_230 ( V_11 ) ) {
F_69 () ;
if ( ! F_42 () ) {
V_300 = 1 ;
V_119 = false ;
goto V_256;
}
F_231 ( V_11 ) ;
F_45 () ;
F_67 () ;
}
V_306 = F_232 ( V_11 ) ;
F_69 () ;
V_256:
if ( V_11 -> V_52 . V_226 )
F_43 ( V_11 -> V_73 , & V_11 -> V_301 , V_300 ) ;
if ( V_119 || V_306 ) {
if ( ! F_42 () )
return;
if ( V_119 )
F_44 ( V_122 ,
V_11 -> V_16 ) ;
if ( V_306 )
F_235 ( V_11 ) ;
F_45 () ;
}
}
static int F_236 ( struct V_10 * V_11 )
{
F_181 ( V_11 ) ;
F_237 ( V_11 ) ;
F_238 ( V_11 ) ;
return V_310 ;
}
static int F_239 ( unsigned long V_311 ,
struct V_14 * V_19 )
{
struct V_10 * V_312 = F_11 ( V_19 ) ;
switch ( V_311 ) {
case V_313 :
return F_236 ( V_312 ) ;
case V_314 :
F_181 ( V_312 ) ;
break;
case V_315 :
F_237 ( V_312 ) ;
break;
case V_122 :
if ( V_312 -> V_112 )
V_312 -> V_112 -- ;
break;
default:
break;
}
return V_310 ;
}
static int F_240 ( unsigned long V_311 ,
struct V_14 * V_15 )
{
struct V_22 * V_22 = F_241 ( V_15 ) , * V_229 ;
struct V_10 * V_11 ;
struct V_14 * V_19 ;
if ( ! V_22 )
return V_310 ;
V_19 = V_22 -> V_11 -> V_16 ;
V_11 = V_22 -> V_11 ;
V_229 = F_36 ( V_11 -> V_101 ) ;
switch ( V_311 ) {
case V_314 :
if ( V_19 -> type != V_207 )
F_180 ( V_19 , V_15 ) ;
else
F_179 ( V_19 , V_15 ) ;
break;
case V_316 :
case V_317 :
F_25 ( V_22 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_242 ( V_22 ) ;
case V_318 :
if ( F_163 ( V_11 ) )
F_164 ( V_11 , NULL ) ;
break;
case V_319 :
break;
case V_313 :
if ( ! F_35 ( V_11 ) ||
! V_11 -> V_52 . V_229 [ 0 ] )
break;
if ( V_22 == V_229 ) {
F_168 ( V_11 -> V_101 , NULL ) ;
} else if ( ! strcmp ( V_15 -> V_59 , V_11 -> V_52 . V_229 ) ) {
F_80 ( V_11 -> V_101 , V_22 ) ;
} else {
break;
}
F_73 ( V_11 -> V_16 , L_95 ,
V_229 ? V_15 -> V_59 : L_96 ) ;
F_161 () ;
F_81 ( V_11 ) ;
F_162 () ;
break;
case V_320 :
F_100 ( V_11 ) ;
break;
case V_74 :
F_44 ( V_311 , V_22 -> V_11 -> V_16 ) ;
break;
default:
break;
}
return V_310 ;
}
static int F_243 ( struct V_321 * V_322 ,
unsigned long V_311 , void * V_323 )
{
struct V_14 * V_324 = F_244 ( V_323 ) ;
F_56 ( V_324 , L_97 , V_311 ) ;
if ( ! ( V_324 -> V_160 & V_222 ) )
return V_310 ;
if ( V_324 -> V_82 & V_236 ) {
F_56 ( V_324 , L_98 ) ;
return F_239 ( V_311 , V_324 ) ;
}
if ( V_324 -> V_82 & V_178 ) {
F_56 ( V_324 , L_99 ) ;
return F_240 ( V_311 , V_324 ) ;
}
return V_310 ;
}
static inline T_3 F_245 ( struct V_12 * V_13 )
{
struct V_325 * V_326 , V_327 ;
V_326 = F_246 ( V_13 , 0 , sizeof( V_327 ) , & V_327 ) ;
if ( V_326 )
return V_326 -> V_177 [ 5 ] ^ V_326 -> V_328 [ 5 ] ^ V_326 -> V_329 ;
return 0 ;
}
static bool F_247 ( struct V_10 * V_11 , struct V_12 * V_13 ,
struct V_330 * V_331 )
{
const struct V_332 * V_333 ;
const struct V_334 * V_335 ;
int V_336 , V_20 = - 1 ;
if ( V_11 -> V_52 . V_337 > V_338 )
return F_248 ( V_13 , V_331 , 0 ) ;
V_331 -> V_339 . V_339 = 0 ;
V_336 = F_249 ( V_13 ) ;
if ( V_13 -> V_289 == F_222 ( V_296 ) ) {
if ( F_5 ( ! F_250 ( V_13 , V_336 + sizeof( * V_335 ) ) ) )
return false ;
V_335 = F_251 ( V_13 ) ;
F_252 ( V_331 , V_335 ) ;
V_336 += V_335 -> V_340 << 2 ;
if ( ! F_253 ( V_335 ) )
V_20 = V_335 -> V_289 ;
} else if ( V_13 -> V_289 == F_222 ( V_341 ) ) {
if ( F_5 ( ! F_250 ( V_13 , V_336 + sizeof( * V_333 ) ) ) )
return false ;
V_333 = F_254 ( V_13 ) ;
F_255 ( V_331 , V_333 ) ;
V_336 += sizeof( * V_333 ) ;
V_20 = V_333 -> V_342 ;
} else {
return false ;
}
if ( V_11 -> V_52 . V_337 == V_343 && V_20 >= 0 )
V_331 -> V_339 . V_339 = F_256 ( V_13 , V_336 , V_20 ) ;
return true ;
}
T_3 F_257 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
struct V_330 V_344 ;
T_3 V_345 ;
if ( V_11 -> V_52 . V_337 == V_346 &&
V_13 -> V_347 )
return V_13 -> V_345 ;
if ( V_11 -> V_52 . V_337 == V_348 ||
! F_247 ( V_11 , V_13 , & V_344 ) )
return F_245 ( V_13 ) ;
if ( V_11 -> V_52 . V_337 == V_338 ||
V_11 -> V_52 . V_337 == V_349 )
V_345 = F_245 ( V_13 ) ;
else
V_345 = ( V_350 T_3 ) V_344 . V_339 . V_339 ;
V_345 ^= ( V_350 T_3 ) F_258 ( & V_344 ) ^
( V_350 T_3 ) F_259 ( & V_344 ) ;
V_345 ^= ( V_345 >> 16 ) ;
V_345 ^= ( V_345 >> 8 ) ;
return V_345 ;
}
static void F_260 ( struct V_10 * V_11 )
{
F_135 ( & V_11 -> V_72 ,
F_40 ) ;
F_135 ( & V_11 -> V_351 , V_352 ) ;
F_135 ( & V_11 -> V_255 , F_188 ) ;
if ( F_20 ( V_11 ) == V_4 )
F_135 ( & V_11 -> V_301 , F_234 ) ;
else
F_135 ( & V_11 -> V_301 , F_227 ) ;
F_135 ( & V_11 -> V_353 , V_354 ) ;
F_135 ( & V_11 -> V_355 , V_356 ) ;
}
static void F_261 ( struct V_10 * V_11 )
{
F_262 ( & V_11 -> V_255 ) ;
F_262 ( & V_11 -> V_301 ) ;
F_262 ( & V_11 -> V_351 ) ;
F_262 ( & V_11 -> V_353 ) ;
F_262 ( & V_11 -> V_72 ) ;
F_262 ( & V_11 -> V_355 ) ;
}
static int F_263 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
if ( F_19 ( V_11 ) ) {
F_12 (bond, slave, iter) {
if ( F_35 ( V_11 ) &&
V_22 != F_156 ( V_11 -> V_69 ) ) {
F_78 ( V_22 ,
V_118 ) ;
} else if ( F_20 ( V_11 ) != V_7 ) {
F_79 ( V_22 ,
V_118 ) ;
}
}
}
F_260 ( V_11 ) ;
if ( F_16 ( V_11 ) ) {
if ( F_264 ( V_11 , ( F_20 ( V_11 ) == V_9 ) ) )
return - V_128 ;
if ( V_11 -> V_52 . V_357 )
F_43 ( V_11 -> V_73 , & V_11 -> V_351 , 0 ) ;
}
if ( V_11 -> V_52 . V_117 )
F_43 ( V_11 -> V_73 , & V_11 -> V_255 , 0 ) ;
if ( V_11 -> V_52 . V_226 ) {
F_43 ( V_11 -> V_73 , & V_11 -> V_301 , 0 ) ;
V_11 -> F_108 = F_214 ;
}
if ( F_20 ( V_11 ) == V_7 ) {
F_43 ( V_11 -> V_73 , & V_11 -> V_353 , 0 ) ;
V_11 -> F_108 = V_358 ;
F_265 ( V_11 , 1 ) ;
}
if ( F_163 ( V_11 ) )
F_164 ( V_11 , NULL ) ;
return 0 ;
}
static int F_266 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_261 ( V_11 ) ;
V_11 -> V_112 = 0 ;
if ( F_16 ( V_11 ) )
F_267 ( V_11 ) ;
V_11 -> F_108 = NULL ;
return 0 ;
}
static struct V_359 * F_176 ( struct V_14 * V_19 ,
struct V_359 * V_360 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_359 V_361 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
memcpy ( V_360 , & V_11 -> V_241 , sizeof( * V_360 ) ) ;
F_12 (bond, slave, iter) {
const struct V_359 * V_362 =
F_145 ( V_22 -> V_16 , & V_361 ) ;
struct V_359 * V_363 = & V_22 -> V_223 ;
V_360 -> V_364 += V_362 -> V_364 - V_363 -> V_364 ;
V_360 -> V_365 += V_362 -> V_365 - V_363 -> V_365 ;
V_360 -> V_366 += V_362 -> V_366 - V_363 -> V_366 ;
V_360 -> V_367 += V_362 -> V_367 - V_363 -> V_367 ;
V_360 -> V_368 += V_362 -> V_368 - V_363 -> V_368 ; ;
V_360 -> V_369 += V_362 -> V_369 - V_363 -> V_369 ;
V_360 -> V_370 += V_362 -> V_370 - V_363 -> V_370 ;
V_360 -> V_371 += V_362 -> V_371 - V_363 -> V_371 ;
V_360 -> V_372 += V_362 -> V_372 - V_363 -> V_372 ;
V_360 -> V_373 += V_362 -> V_373 - V_363 -> V_373 ;
V_360 -> V_374 += V_362 -> V_374 - V_363 -> V_374 ;
V_360 -> V_375 += V_362 -> V_375 - V_363 -> V_375 ;
V_360 -> V_376 += V_362 -> V_376 - V_363 -> V_376 ;
V_360 -> V_377 += V_362 -> V_377 - V_363 -> V_377 ;
V_360 -> V_378 += V_362 -> V_378 - V_363 -> V_378 ;
V_360 -> V_379 += V_362 -> V_379 - V_363 -> V_379 ;
V_360 -> V_380 += V_362 -> V_380 - V_363 -> V_380 ;
V_360 -> V_381 += V_362 -> V_381 - V_363 -> V_381 ;
V_360 -> V_382 += V_362 -> V_382 - V_363 -> V_382 ;
V_360 -> V_383 += V_362 -> V_383 - V_363 -> V_383 ;
V_360 -> V_384 += V_362 -> V_384 - V_363 -> V_384 ;
memcpy ( V_363 , V_362 , sizeof( * V_362 ) ) ;
}
memcpy ( & V_11 -> V_241 , V_360 , sizeof( * V_360 ) ) ;
return V_360 ;
}
static int F_268 ( struct V_14 * V_19 , struct V_48 * V_49 , int V_385 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_14 * V_15 = NULL ;
struct V_181 V_386 ;
struct V_181 T_9 * V_387 = NULL ;
struct V_186 V_388 ;
struct V_186 T_9 * V_389 = NULL ;
struct V_50 * V_51 = NULL ;
struct V_390 V_391 ;
struct V_392 * V_392 ;
int V_26 = 0 ;
F_56 ( V_19 , L_100 , V_385 ) ;
switch ( V_385 ) {
case V_61 :
V_51 = F_32 ( V_49 ) ;
if ( ! V_51 )
return - V_210 ;
V_51 -> V_393 = 0 ;
case V_64 :
V_51 = F_32 ( V_49 ) ;
if ( ! V_51 )
return - V_210 ;
if ( V_51 -> V_62 == 1 ) {
V_51 -> V_65 = 0 ;
if ( F_22 ( V_11 -> V_16 ) )
V_51 -> V_65 = V_54 ;
}
return 0 ;
case V_394 :
case V_395 :
V_387 = (struct V_181 T_9 * ) V_49 -> V_396 ;
if ( F_269 ( & V_386 , V_387 , sizeof( V_181 ) ) )
return - V_397 ;
V_26 = F_183 ( V_19 , & V_386 ) ;
if ( V_26 == 0 &&
F_270 ( V_387 , & V_386 , sizeof( V_181 ) ) )
return - V_397 ;
return V_26 ;
case V_398 :
case V_399 :
V_389 = (struct V_186 T_9 * ) V_49 -> V_396 ;
if ( F_269 ( & V_388 , V_389 , sizeof( V_186 ) ) )
return - V_397 ;
V_26 = F_184 ( V_19 , & V_388 ) ;
if ( V_26 == 0 &&
F_270 ( V_389 , & V_388 , sizeof( V_186 ) ) )
return - V_397 ;
return V_26 ;
default:
break;
}
V_392 = F_209 ( V_19 ) ;
if ( ! F_271 ( V_392 -> V_400 , V_401 ) )
return - V_202 ;
V_15 = F_272 ( V_392 , V_49 -> V_402 ) ;
F_56 ( V_19 , L_101 , V_15 ) ;
if ( ! V_15 )
return - V_245 ;
F_56 ( V_19 , L_102 , V_15 -> V_59 ) ;
switch ( V_385 ) {
case V_403 :
case V_404 :
V_26 = F_136 ( V_19 , V_15 ) ;
break;
case V_405 :
case V_406 :
V_26 = F_179 ( V_19 , V_15 ) ;
break;
case V_407 :
case V_408 :
F_55 ( V_19 , V_15 ) ;
V_26 = 0 ;
break;
case V_409 :
case V_410 :
F_273 ( & V_391 , V_15 -> V_59 ) ;
V_26 = F_274 ( V_11 , V_411 , & V_391 ) ;
break;
default:
V_26 = - V_212 ;
}
return V_26 ;
}
static void F_275 ( struct V_14 * V_19 , int V_412 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
if ( V_412 & V_83 )
F_34 ( V_11 ,
V_19 -> V_82 & V_83 ? 1 : - 1 ) ;
if ( V_412 & V_84 )
F_38 ( V_11 ,
V_19 -> V_82 & V_84 ? 1 : - 1 ) ;
}
static void F_276 ( struct V_14 * V_19 )
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
F_148 ( V_22 -> V_16 , V_19 ) ;
F_147 ( V_22 -> V_16 , V_19 ) ;
}
}
F_69 () ;
}
static int F_277 ( struct V_413 * V_414 )
{
struct V_10 * V_11 = F_11 ( V_414 -> V_16 ) ;
const struct V_45 * V_46 ;
struct V_415 V_416 ;
struct V_22 * V_22 ;
int V_169 ;
V_22 = F_278 ( V_11 ) ;
if ( ! V_22 )
return 0 ;
V_46 = V_22 -> V_16 -> V_47 ;
if ( ! V_46 -> V_417 )
return 0 ;
V_416 . V_418 = NULL ;
V_416 . V_419 = NULL ;
V_169 = V_46 -> V_417 ( V_22 -> V_16 , & V_416 ) ;
if ( V_169 )
return V_169 ;
V_414 -> V_416 -> V_419 = V_416 . V_419 ;
if ( ! V_416 . V_418 )
return 0 ;
return V_416 . V_418 ( V_414 ) ;
}
static int F_279 ( struct V_14 * V_16 ,
struct V_415 * V_416 )
{
if ( V_416 -> V_16 == V_16 )
V_416 -> V_418 = F_277 ;
return 0 ;
}
static int F_280 ( struct V_14 * V_19 , int V_420 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_23 ;
struct V_24 * V_25 ;
int V_26 = 0 ;
F_56 ( V_19 , L_103 , V_11 , V_420 ) ;
F_12 (bond, slave, iter) {
F_56 ( V_19 , L_104 ,
V_22 , V_22 -> V_16 -> V_47 -> V_421 ) ;
V_26 = F_143 ( V_22 -> V_16 , V_420 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_105 , V_26 ,
V_22 -> V_16 -> V_59 ) ;
goto V_27;
}
}
V_19 -> V_217 = V_420 ;
return 0 ;
V_27:
F_12 (bond, rollback_slave, iter) {
int V_422 ;
if ( V_23 == V_22 )
break;
V_422 = F_143 ( V_23 -> V_16 , V_19 -> V_217 ) ;
if ( V_422 ) {
F_56 ( V_19 , L_106 ,
V_422 , V_23 -> V_16 -> V_59 ) ;
}
}
return V_26 ;
}
static int F_281 ( struct V_14 * V_19 , void * V_198 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_23 ;
struct V_91 * V_423 = V_198 , V_424 ;
struct V_24 * V_25 ;
int V_26 = 0 ;
if ( F_20 ( V_11 ) == V_9 )
return F_282 ( V_19 , V_198 ) ;
F_56 ( V_19 , L_107 , V_11 ) ;
if ( V_11 -> V_52 . V_94 &&
F_20 ( V_11 ) == V_4 )
return 0 ;
if ( ! F_283 ( V_423 -> V_97 ) )
return - V_425 ;
F_12 (bond, slave, iter) {
F_56 ( V_19 , L_108 , V_22 , V_22 -> V_16 -> V_59 ) ;
V_26 = F_61 ( V_22 -> V_16 , V_198 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_105 , V_26 , V_22 -> V_16 -> V_59 ) ;
goto V_27;
}
}
memcpy ( V_19 -> V_86 , V_423 -> V_97 , V_19 -> V_85 ) ;
return 0 ;
V_27:
memcpy ( V_424 . V_97 , V_19 -> V_86 , V_19 -> V_85 ) ;
V_424 . V_98 = V_19 -> type ;
F_12 (bond, rollback_slave, iter) {
int V_422 ;
if ( V_23 == V_22 )
break;
V_422 = F_61 ( V_23 -> V_16 , & V_424 ) ;
if ( V_422 ) {
F_56 ( V_19 , L_106 ,
V_422 , V_23 -> V_16 -> V_59 ) ;
}
}
return V_26 ;
}
static void F_284 ( struct V_10 * V_11 , struct V_12 * V_13 , int V_246 )
{
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_200 = V_246 ;
F_90 (bond, slave, iter) {
if ( -- V_200 < 0 ) {
if ( F_285 ( V_22 ) ) {
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
return;
}
}
}
V_200 = V_246 ;
F_90 (bond, slave, iter) {
if ( -- V_200 < 0 )
break;
if ( F_285 ( V_22 ) ) {
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
return;
}
}
F_286 ( V_11 -> V_16 , V_13 ) ;
}
static T_3 F_287 ( struct V_10 * V_11 )
{
T_3 V_246 ;
struct V_426 V_427 ;
int V_428 = V_11 -> V_52 . V_428 ;
switch ( V_428 ) {
case 0 :
V_246 = F_288 () ;
break;
case 1 :
V_246 = V_11 -> V_429 ;
break;
default:
V_427 =
V_11 -> V_52 . V_427 ;
V_246 = F_289 ( V_11 -> V_429 ,
V_427 ) ;
break;
}
V_11 -> V_429 ++ ;
return V_246 ;
}
static int F_290 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_334 * V_335 = F_251 ( V_13 ) ;
struct V_22 * V_22 ;
T_3 V_246 ;
if ( V_335 -> V_289 == V_430 && V_13 -> V_289 == F_222 ( V_296 ) ) {
V_22 = F_68 ( V_11 -> V_69 ) ;
if ( V_22 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_284 ( V_11 , V_13 , 0 ) ;
} else {
int V_185 = F_111 ( V_11 -> V_185 ) ;
if ( F_291 ( V_185 ) ) {
V_246 = F_287 ( V_11 ) ;
F_284 ( V_11 , V_13 , V_246 % V_185 ) ;
} else {
F_286 ( V_19 , V_13 ) ;
}
}
return V_431 ;
}
static int F_292 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 ;
V_22 = F_68 ( V_11 -> V_69 ) ;
if ( V_22 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_286 ( V_19 , V_13 ) ;
return V_431 ;
}
void F_293 ( struct V_10 * V_11 , unsigned long V_111 )
{
F_43 ( V_11 -> V_73 , & V_11 -> V_355 , V_111 ) ;
}
static void V_356 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_41 ( V_71 , struct V_10 ,
V_355 . V_71 ) ;
int V_169 ;
if ( ! F_42 () )
goto V_67;
V_169 = F_164 ( V_11 , NULL ) ;
F_45 () ;
if ( V_169 ) {
F_294 ( L_109 ) ;
goto V_67;
}
return;
V_67:
F_293 ( V_11 , 1 ) ;
}
int F_164 ( struct V_10 * V_11 , struct V_22 * V_432 )
{
struct V_22 * V_22 ;
struct V_24 * V_25 ;
struct V_433 * V_434 , * V_435 ;
int V_436 = 0 ;
int V_169 = 0 ;
#ifdef F_295
F_296 ( F_297 ( & V_11 -> V_437 ) ) ;
#endif
V_434 = F_83 ( F_298 ( struct V_433 , V_438 [ V_11 -> V_185 ] ) ,
V_127 ) ;
if ( ! V_434 ) {
V_169 = - V_128 ;
F_299 ( L_110 ) ;
goto V_99;
}
if ( F_20 ( V_11 ) == V_7 ) {
struct V_129 V_129 ;
if ( F_89 ( V_11 , & V_129 ) ) {
F_300 ( L_111 ) ;
F_301 ( V_434 , V_439 ) ;
V_435 = F_36 ( V_11 -> V_440 ) ;
if ( V_435 ) {
F_168 ( V_11 -> V_440 , NULL ) ;
F_301 ( V_435 , V_439 ) ;
}
goto V_99;
}
V_436 = V_129 . V_138 ;
}
F_12 (bond, slave, iter) {
if ( F_20 ( V_11 ) == V_7 ) {
struct V_134 * V_135 ;
V_135 = F_91 ( V_22 ) -> V_136 . V_134 ;
if ( ! V_135 || V_135 -> V_137 != V_436 )
continue;
}
if ( ! F_285 ( V_22 ) )
continue;
if ( V_432 == V_22 )
continue;
V_434 -> V_438 [ V_434 -> V_441 ++ ] = V_22 ;
}
V_435 = F_36 ( V_11 -> V_440 ) ;
F_80 ( V_11 -> V_440 , V_434 ) ;
if ( V_435 )
F_301 ( V_435 , V_439 ) ;
V_99:
if ( V_169 != 0 && V_432 ) {
int V_442 ;
V_435 = F_36 ( V_11 -> V_440 ) ;
for ( V_442 = 0 ; V_442 < V_435 -> V_441 ; V_442 ++ ) {
if ( V_432 == V_435 -> V_438 [ V_442 ] ) {
V_435 -> V_438 [ V_442 ] =
V_435 -> V_438 [ V_435 -> V_441 - 1 ] ;
V_435 -> V_441 -- ;
break;
}
}
}
return V_169 ;
}
static int F_302 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
struct V_22 * V_22 ;
struct V_433 * V_443 ;
unsigned int V_441 ;
V_443 = F_68 ( V_11 -> V_440 ) ;
V_441 = V_443 ? F_111 ( V_443 -> V_441 ) : 0 ;
if ( F_291 ( V_441 ) ) {
V_22 = V_443 -> V_438 [ F_257 ( V_11 , V_13 ) % V_441 ] ;
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
} else {
F_286 ( V_16 , V_13 ) ;
}
return V_431 ;
}
static int F_303 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 = NULL ;
struct V_24 * V_25 ;
F_90 (bond, slave, iter) {
if ( F_304 ( V_11 , V_22 ) )
break;
if ( F_65 ( V_22 ) && V_22 -> V_29 == V_30 ) {
struct V_12 * V_444 = F_305 ( V_13 , V_171 ) ;
if ( ! V_444 ) {
F_194 ( L_112 ,
V_19 -> V_59 , V_445 ) ;
continue;
}
F_2 ( V_11 , V_444 , V_22 -> V_16 ) ;
}
}
if ( V_22 && F_65 ( V_22 ) && V_22 -> V_29 == V_30 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_286 ( V_19 , V_13 ) ;
return V_431 ;
}
static inline int F_306 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_22 * V_22 = NULL ;
struct V_24 * V_25 ;
if ( ! V_13 -> V_17 )
return 1 ;
F_90 (bond, slave, iter) {
if ( V_22 -> V_215 == V_13 -> V_17 ) {
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
static T_2 F_307 ( struct V_14 * V_16 , struct V_12 * V_13 ,
void * V_446 , T_10 V_447 )
{
T_2 V_448 = F_308 ( V_13 ) ? F_309 ( V_13 ) : 0 ;
F_4 ( V_13 ) -> V_18 = V_13 -> V_17 ;
if ( F_5 ( V_448 >= V_16 -> V_449 ) ) {
do {
V_448 -= V_16 -> V_449 ;
} while ( V_448 >= V_16 -> V_449 );
}
return V_448 ;
}
static T_11 F_310 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
if ( F_311 ( V_11 ) &&
! F_306 ( V_11 , V_13 ) )
return V_431 ;
switch ( F_20 ( V_11 ) ) {
case V_3 :
return F_290 ( V_13 , V_16 ) ;
case V_4 :
return F_292 ( V_13 , V_16 ) ;
case V_7 :
case V_5 :
return F_302 ( V_13 , V_16 ) ;
case V_6 :
return F_303 ( V_13 , V_16 ) ;
case V_9 :
return F_312 ( V_13 , V_16 ) ;
case V_8 :
return F_313 ( V_13 , V_16 ) ;
default:
F_62 ( V_16 , L_113 , F_20 ( V_11 ) ) ;
F_314 ( 1 ) ;
F_286 ( V_16 , V_13 ) ;
return V_431 ;
}
}
static T_11 F_315 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
T_11 V_169 = V_431 ;
if ( F_5 ( F_316 ( V_16 ) ) )
return V_450 ;
F_67 () ;
if ( F_19 ( V_11 ) )
V_169 = F_310 ( V_13 , V_16 ) ;
else
F_286 ( V_16 , V_13 ) ;
F_69 () ;
return V_169 ;
}
static int F_317 ( struct V_14 * V_19 ,
struct V_31 * V_32 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
unsigned long V_34 = 0 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
V_32 -> V_36 = V_37 ;
V_32 -> V_136 = V_451 ;
F_12 (bond, slave, iter) {
if ( F_285 ( V_22 ) ) {
if ( V_22 -> V_34 != V_35 )
V_34 += V_22 -> V_34 ;
if ( V_32 -> V_36 == V_37 &&
V_22 -> V_36 != V_37 )
V_32 -> V_36 = V_22 -> V_36 ;
}
}
F_318 ( V_32 , V_34 ? : V_35 ) ;
return 0 ;
}
static void F_319 ( struct V_14 * V_19 ,
struct V_452 * V_453 )
{
F_320 ( V_453 -> V_454 , V_455 , sizeof( V_453 -> V_454 ) ) ;
F_320 ( V_453 -> V_456 , V_457 , sizeof( V_453 -> V_456 ) ) ;
snprintf ( V_453 -> V_458 , sizeof( V_453 -> V_458 ) , L_114 ,
V_459 ) ;
}
static void F_321 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
if ( V_11 -> V_73 )
F_322 ( V_11 -> V_73 ) ;
F_323 ( V_19 ) ;
}
void F_324 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_325 ( & V_11 -> V_437 ) ;
V_11 -> V_52 = V_460 ;
V_11 -> V_16 = V_19 ;
F_142 ( V_19 ) ;
V_19 -> V_47 = & V_461 ;
V_19 -> V_55 = & V_462 ;
V_19 -> V_463 = F_321 ;
F_326 ( V_19 , & V_464 ) ;
V_19 -> V_82 |= V_236 | V_465 ;
V_19 -> V_160 |= V_222 | V_466 | V_467 ;
V_19 -> V_160 &= ~ ( V_146 | V_208 ) ;
V_19 -> V_141 |= V_468 ;
V_19 -> V_141 |= V_469 ;
V_19 -> V_470 = V_149 |
V_471 |
V_472 |
V_473 ;
V_19 -> V_470 &= ~ ( V_474 & ~ V_475 ) ;
V_19 -> V_470 |= V_162 ;
V_19 -> V_141 |= V_19 -> V_470 ;
}
static void F_327 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
struct V_433 * V_438 ;
F_95 ( V_19 ) ;
F_12 (bond, slave, iter)
F_173 ( V_19 , V_22 -> V_16 , true ) ;
F_73 ( V_19 , L_115 ) ;
V_438 = F_36 ( V_11 -> V_440 ) ;
if ( V_438 ) {
F_168 ( V_11 -> V_440 , NULL ) ;
F_301 ( V_438 , V_439 ) ;
}
F_328 ( & V_11 -> V_476 ) ;
F_329 ( V_11 ) ;
}
static int F_330 ( struct V_477 * V_52 )
{
int V_478 , V_479 , V_480 , V_200 ;
struct V_390 V_391 ;
const struct V_390 * V_481 ;
int V_482 ;
T_2 V_483 = 0 ;
T_2 V_484 = 0 ;
if ( V_1 ) {
F_273 ( & V_391 , V_1 ) ;
V_481 = F_331 ( F_332 ( V_485 ) , & V_391 ) ;
if ( ! V_481 ) {
F_299 ( L_116 , V_1 ) ;
return - V_210 ;
}
V_183 = V_481 -> V_486 ;
}
if ( V_487 ) {
if ( ( V_183 != V_5 ) &&
( V_183 != V_7 ) &&
( V_183 != V_8 ) ) {
F_333 ( L_117 ,
F_1 ( V_183 ) ) ;
} else {
F_273 ( & V_391 , V_487 ) ;
V_481 = F_331 ( F_332 ( V_488 ) ,
& V_391 ) ;
if ( ! V_481 ) {
F_299 ( L_118 ,
V_487 ) ;
return - V_210 ;
}
V_489 = V_481 -> V_486 ;
}
}
if ( V_490 ) {
if ( V_183 != V_7 ) {
F_333 ( L_119 ,
F_1 ( V_183 ) ) ;
} else {
F_273 ( & V_391 , V_490 ) ;
V_481 = F_331 ( F_332 ( V_491 ) ,
& V_391 ) ;
if ( ! V_481 ) {
F_299 ( L_120 ,
V_490 ) ;
return - V_210 ;
}
V_492 = V_481 -> V_486 ;
}
}
if ( V_493 ) {
F_273 ( & V_391 , V_493 ) ;
V_481 = F_331 ( F_332 ( V_494 ) ,
& V_391 ) ;
if ( ! V_481 ) {
F_299 ( L_121 , V_493 ) ;
return - V_210 ;
}
V_52 -> V_493 = V_481 -> V_486 ;
if ( V_183 != V_7 )
F_334 ( L_122 ) ;
} else {
V_52 -> V_493 = V_495 ;
}
if ( V_496 < 0 ) {
F_334 ( L_123 ,
V_496 , 0 , V_497 , V_498 ) ;
V_496 = V_498 ;
}
if ( V_117 < 0 ) {
F_334 ( L_124 ,
V_117 , V_497 ) ;
V_117 = 0 ;
}
if ( V_110 < 0 ) {
F_334 ( L_125 ,
V_110 , V_497 ) ;
V_110 = 0 ;
}
if ( V_252 < 0 ) {
F_334 ( L_126 ,
V_252 , V_497 ) ;
V_252 = 0 ;
}
if ( ( V_53 != 0 ) && ( V_53 != 1 ) ) {
F_334 ( L_127 ,
V_53 ) ;
V_53 = 1 ;
}
if ( V_120 < 0 || V_120 > 255 ) {
F_334 ( L_128 ,
V_120 ) ;
V_120 = 1 ;
}
if ( ! F_335 ( V_183 ) ) {
if ( ! V_117 ) {
F_334 ( L_129 ) ;
F_334 ( L_130 ) ;
V_117 = V_499 ;
}
}
if ( V_500 < 1 || V_500 > 255 ) {
F_334 ( L_131 ,
V_500 , V_501 ) ;
V_500 = V_501 ;
}
if ( ( V_502 != 0 ) && ( V_502 != 1 ) ) {
F_334 ( L_132 ,
V_502 ) ;
V_502 = 0 ;
}
if ( V_123 < 0 || V_123 > 255 ) {
F_334 ( L_133 ,
V_123 , V_503 ) ;
V_123 = V_503 ;
}
F_336 ( & V_391 , V_428 ) ;
if ( ! F_331 ( F_332 ( V_504 ) , & V_391 ) ) {
F_334 ( L_134 ,
V_428 , V_505 ) ;
V_428 = 1 ;
}
if ( V_183 == V_9 ) {
F_337 ( L_135 ,
V_110 ) ;
}
if ( ! V_117 ) {
if ( V_110 || V_252 ) {
F_334 ( L_136 ,
V_110 , V_252 ) ;
}
} else {
if ( V_226 ) {
F_334 ( L_137 ,
V_117 , V_226 ) ;
V_226 = 0 ;
}
if ( ( V_110 % V_117 ) != 0 ) {
F_334 ( L_138 ,
V_110 , V_117 , ( V_110 / V_117 ) * V_117 ) ;
}
V_110 /= V_117 ;
if ( ( V_252 % V_117 ) != 0 ) {
F_334 ( L_139 ,
V_252 , V_117 ,
( V_252 / V_117 ) * V_117 ) ;
}
V_252 /= V_117 ;
}
if ( V_226 < 0 ) {
F_334 ( L_140 ,
V_226 , V_497 ) ;
V_226 = 0 ;
}
for ( V_506 = 0 , V_200 = 0 ;
( V_506 < V_227 ) && V_507 [ V_200 ] ; V_200 ++ ) {
T_8 V_257 ;
if ( ! F_338 ( V_507 [ V_200 ] , - 1 , ( T_5 * ) & V_257 , - 1 , NULL ) ||
! F_339 ( V_257 ) ) {
F_334 ( L_141 ,
V_507 [ V_200 ] ) ;
V_226 = 0 ;
} else {
if ( F_213 ( V_508 , V_257 ) == - 1 )
V_508 [ V_506 ++ ] = V_257 ;
else
F_334 ( L_142 ,
& V_257 ) ;
}
}
if ( V_226 && ! V_506 ) {
F_334 ( L_143 ,
V_226 ) ;
V_226 = 0 ;
}
if ( V_278 ) {
if ( ! V_226 ) {
F_299 ( L_144 ) ;
return - V_210 ;
}
F_273 ( & V_391 , V_278 ) ;
V_481 = F_331 ( F_332 ( V_509 ) ,
& V_391 ) ;
if ( ! V_481 ) {
F_299 ( L_145 ,
V_278 ) ;
return - V_210 ;
}
V_478 = V_481 -> V_486 ;
} else {
V_478 = 0 ;
}
V_482 = 0 ;
if ( V_510 ) {
F_273 ( & V_391 , V_510 ) ;
V_481 = F_331 ( F_332 ( V_511 ) ,
& V_391 ) ;
if ( ! V_481 ) {
F_299 ( L_146 ,
V_510 ) ;
V_482 = 0 ;
} else {
V_482 = V_481 -> V_486 ;
}
}
if ( V_117 ) {
F_333 ( L_147 , V_117 ) ;
} else if ( V_226 ) {
V_481 = F_340 ( V_509 ,
V_478 ) ;
F_333 ( L_148 ,
V_226 , V_481 -> string , V_506 ) ;
for ( V_200 = 0 ; V_200 < V_506 ; V_200 ++ )
F_341 ( L_149 , V_507 [ V_200 ] ) ;
F_341 ( L_150 ) ;
} else if ( V_496 ) {
F_300 ( L_151 ) ;
}
if ( V_229 && ! F_342 ( V_183 ) ) {
F_334 ( L_152 ,
V_229 , F_1 ( V_183 ) ) ;
V_229 = NULL ;
}
if ( V_229 && V_104 ) {
F_273 ( & V_391 , V_104 ) ;
V_481 = F_331 ( F_332 ( V_512 ) ,
& V_391 ) ;
if ( ! V_481 ) {
F_299 ( L_153 ,
V_104 ) ;
return - V_210 ;
}
V_480 = V_481 -> V_486 ;
} else {
V_480 = V_105 ;
}
if ( V_94 ) {
F_273 ( & V_391 , V_94 ) ;
V_481 = F_331 ( F_332 ( V_513 ) ,
& V_391 ) ;
if ( ! V_481 ) {
F_299 ( L_154 ,
V_94 ) ;
return - V_210 ;
}
V_479 = V_481 -> V_486 ;
if ( V_183 != V_4 )
F_334 ( L_155 ) ;
} else {
V_479 = V_514 ;
}
F_273 ( & V_391 , L_156 ) ;
V_481 = F_331 (
F_332 ( V_515 ) ,
& V_391 ) ;
if ( ! V_481 ) {
F_299 ( L_157 ) ;
return - V_210 ;
}
V_483 = V_481 -> V_486 ;
V_481 = F_331 ( F_332 ( V_516 ) ,
& V_391 ) ;
if ( ! V_481 ) {
F_299 ( L_158 ) ;
return - V_210 ;
}
V_484 = V_481 -> V_486 ;
if ( V_517 == 0 ) {
F_334 ( L_159 ,
V_497 , V_518 ) ;
V_517 = V_518 ;
}
V_52 -> V_1 = V_183 ;
V_52 -> V_337 = V_489 ;
V_52 -> V_117 = V_117 ;
V_52 -> V_120 = V_120 ;
V_52 -> V_226 = V_226 ;
V_52 -> V_278 = V_478 ;
V_52 -> V_510 = V_482 ;
V_52 -> V_110 = V_110 ;
V_52 -> V_252 = V_252 ;
V_52 -> V_53 = V_53 ;
V_52 -> V_492 = V_492 ;
V_52 -> V_229 [ 0 ] = 0 ;
V_52 -> V_104 = V_480 ;
V_52 -> V_94 = V_479 ;
V_52 -> V_500 = V_500 ;
V_52 -> V_502 = V_502 ;
V_52 -> V_123 = V_123 ;
V_52 -> V_519 = V_519 ;
V_52 -> V_517 = V_517 ;
V_52 -> V_428 = V_428 ;
V_52 -> V_357 = 1 ;
V_52 -> V_483 = V_483 ;
F_343 ( V_52 -> V_520 ) ;
V_52 -> V_484 = V_484 ;
if ( V_428 > 0 ) {
V_52 -> V_427 =
V_426 ( V_428 ) ;
} else {
V_52 -> V_427 =
(struct V_426 ) { 0 } ;
}
if ( V_229 ) {
strncpy ( V_52 -> V_229 , V_229 , V_60 ) ;
V_52 -> V_229 [ V_60 - 1 ] = 0 ;
}
memcpy ( V_52 -> V_276 , V_508 , sizeof( V_508 ) ) ;
return 0 ;
}
static void F_344 ( struct V_14 * V_16 ,
struct V_521 * V_448 ,
void * V_522 )
{
F_345 ( & V_448 -> V_523 ,
& V_524 ) ;
}
static void F_346 ( struct V_14 * V_16 )
{
F_345 ( & V_16 -> V_525 ,
& V_526 ) ;
F_347 ( V_16 , F_344 , NULL ) ;
V_16 -> V_527 = & V_528 ;
}
static int F_348 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_529 * V_530 = F_349 ( F_209 ( V_19 ) , V_531 ) ;
F_56 ( V_19 , L_160 ) ;
V_11 -> V_73 = F_350 ( V_19 -> V_59 ) ;
if ( ! V_11 -> V_73 )
return - V_128 ;
F_346 ( V_19 ) ;
F_351 ( & V_11 -> V_476 , & V_530 -> V_532 ) ;
F_352 ( V_11 ) ;
F_353 ( V_11 ) ;
if ( F_354 ( V_19 -> V_86 ) &&
V_19 -> V_87 == V_533 )
F_172 ( V_19 ) ;
return 0 ;
}
unsigned int F_355 ( void )
{
return V_500 ;
}
int F_356 ( struct V_392 * V_392 , const char * V_59 )
{
struct V_14 * V_19 ;
struct V_10 * V_11 ;
struct V_534 * V_535 ;
int V_26 ;
F_129 () ;
V_19 = F_357 ( sizeof( struct V_10 ) ,
V_59 ? V_59 : L_161 , V_536 ,
F_324 , V_500 ) ;
if ( ! V_19 ) {
F_299 ( L_162 , V_59 ) ;
F_45 () ;
return - V_128 ;
}
V_11 = F_11 ( V_19 ) ;
V_535 = & ( F_358 ( V_11 ) ) ;
V_535 -> V_537 = V_538 ;
F_359 ( V_19 , V_392 ) ;
V_19 -> V_539 = & V_540 ;
V_26 = F_360 ( V_19 ) ;
F_24 ( V_19 ) ;
F_45 () ;
if ( V_26 < 0 )
F_321 ( V_19 ) ;
return V_26 ;
}
static int T_12 F_361 ( struct V_392 * V_392 )
{
struct V_529 * V_530 = F_349 ( V_392 , V_531 ) ;
V_530 -> V_392 = V_392 ;
F_362 ( & V_530 -> V_532 ) ;
F_363 ( V_530 ) ;
F_364 ( V_530 ) ;
return 0 ;
}
static void T_13 F_365 ( struct V_392 * V_392 )
{
struct V_529 * V_530 = F_349 ( V_392 , V_531 ) ;
struct V_10 * V_11 , * V_541 ;
F_366 ( V_542 ) ;
F_367 ( V_530 ) ;
F_129 () ;
F_368 (bond, tmp_bond, &bn->dev_list, bond_list)
F_369 ( V_11 -> V_16 , & V_542 ) ;
F_370 ( & V_542 ) ;
F_45 () ;
F_371 ( V_530 ) ;
}
static int T_14 F_372 ( void )
{
int V_200 ;
int V_26 ;
F_333 ( L_163 , V_543 ) ;
V_26 = F_330 ( & V_460 ) ;
if ( V_26 )
goto V_99;
V_26 = F_373 ( & V_544 ) ;
if ( V_26 )
goto V_99;
V_26 = F_374 () ;
if ( V_26 )
goto V_545;
F_375 () ;
for ( V_200 = 0 ; V_200 < V_496 ; V_200 ++ ) {
V_26 = F_356 ( & V_546 , NULL ) ;
if ( V_26 )
goto V_67;
}
F_376 ( & V_547 ) ;
V_99:
return V_26 ;
V_67:
F_377 () ;
F_378 () ;
V_545:
F_379 ( & V_544 ) ;
goto V_99;
}
static void T_15 F_380 ( void )
{
F_381 ( & V_547 ) ;
F_377 () ;
F_378 () ;
F_379 ( & V_544 ) ;
#ifdef F_157
F_296 ( F_382 ( & V_548 ) ) ;
#endif
}
