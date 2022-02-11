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
F_90 () ;
F_91 (bond, slave, iter) {
V_132 = V_22 -> V_16 -> V_47 ;
if ( ! F_65 ( V_22 ) || ! V_132 -> V_133 )
continue;
if ( F_20 ( V_11 ) == V_7 ) {
struct V_134 * V_135 =
F_92 ( V_22 ) -> V_136 . V_134 ;
if ( V_135 &&
V_135 -> V_137 != V_129 . V_138 )
continue;
}
V_131 = F_93 ( V_22 -> V_16 -> V_139 ) ;
if ( F_94 ( & V_131 -> V_140 ) )
continue;
V_132 -> V_133 ( V_22 -> V_16 ) ;
F_95 ( & V_131 -> V_140 ) ;
}
F_96 () ;
}
static void F_97 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter)
if ( F_65 ( V_22 ) )
F_86 ( V_22 ) ;
}
static int F_98 ( struct V_14 * V_16 , struct V_130 * V_131 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_67 = 0 ;
F_12 (bond, slave, iter) {
V_67 = F_82 ( V_22 ) ;
if ( V_67 ) {
F_97 ( V_16 ) ;
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
static void F_97 ( struct V_14 * V_19 )
{
}
static T_6 F_99 ( struct V_14 * V_16 ,
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
V_141 = F_100 ( V_141 ,
V_22 -> V_16 -> V_141 ,
V_142 ) ;
}
V_141 = F_101 ( V_141 , V_142 ) ;
return V_141 ;
}
static void F_102 ( struct V_10 * V_11 )
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
V_148 = F_100 ( V_148 ,
V_22 -> V_16 -> V_148 , V_149 ) ;
V_150 = F_100 ( V_150 ,
V_22 -> V_16 -> V_159 ,
V_151 ) ;
V_145 &= V_22 -> V_16 -> V_160 ;
if ( V_22 -> V_16 -> V_161 > V_152 )
V_152 = V_22 -> V_16 -> V_161 ;
V_154 = F_103 ( V_154 , V_22 -> V_16 -> V_154 ) ;
V_156 = F_103 ( V_156 , V_22 -> V_16 -> V_156 ) ;
}
V_158:
V_19 -> V_148 = V_148 ;
V_19 -> V_159 = V_150 | V_162 ;
V_19 -> V_161 = V_152 ;
V_19 -> V_156 = V_156 ;
F_104 ( V_19 , V_154 ) ;
V_19 -> V_160 &= ~ V_146 ;
if ( ( V_19 -> V_160 & V_147 ) &&
V_145 == ( V_146 | V_147 ) )
V_19 -> V_160 |= V_146 ;
F_105 ( V_19 ) ;
}
static void F_106 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
V_19 -> V_163 = V_15 -> V_163 ;
V_19 -> type = V_15 -> type ;
V_19 -> V_161 = V_15 -> V_161 ;
V_19 -> V_85 = V_15 -> V_85 ;
memcpy ( V_19 -> V_164 , V_15 -> V_164 ,
V_15 -> V_85 ) ;
}
static bool F_107 ( struct V_12 * V_13 ,
struct V_22 * V_22 ,
struct V_10 * V_11 )
{
if ( F_108 ( V_22 ) ) {
if ( F_20 ( V_11 ) == V_9 &&
V_13 -> V_165 != V_166 &&
V_13 -> V_165 != V_167 )
return false ;
return true ;
}
return false ;
}
static T_7 F_109 ( struct V_12 * * V_168 )
{
struct V_12 * V_13 = * V_168 ;
struct V_22 * V_22 ;
struct V_10 * V_11 ;
int (* F_110)( const struct V_12 * , struct V_10 * ,
struct V_22 * );
int V_169 = V_170 ;
V_13 = F_111 ( V_13 , V_171 ) ;
if ( F_5 ( ! V_13 ) )
return V_172 ;
* V_168 = V_13 ;
V_22 = F_112 ( V_13 -> V_16 ) ;
V_11 = V_22 -> V_11 ;
F_110 = F_113 ( V_11 -> F_110 ) ;
if ( F_110 ) {
V_169 = F_110 ( V_13 , V_11 , V_22 ) ;
if ( V_169 == V_172 ) {
F_114 ( V_13 ) ;
return V_169 ;
}
}
if ( F_107 ( V_13 , V_22 , V_11 ) ) {
return V_173 ;
}
V_13 -> V_16 = V_11 -> V_16 ;
if ( F_20 ( V_11 ) == V_9 &&
V_11 -> V_16 -> V_160 & V_174 &&
V_13 -> V_165 == V_175 ) {
if ( F_5 ( F_115 ( V_13 ,
V_13 -> V_176 - F_116 ( V_13 ) ) ) ) {
F_117 ( V_13 ) ;
return V_172 ;
}
F_60 ( F_118 ( V_13 ) -> V_177 , V_11 -> V_16 -> V_86 ) ;
}
return V_169 ;
}
static int F_119 ( struct V_14 * V_19 ,
struct V_14 * V_15 ,
struct V_22 * V_22 )
{
int V_67 ;
V_67 = F_120 ( V_15 , V_19 , V_22 ) ;
if ( V_67 )
return V_67 ;
V_15 -> V_82 |= V_178 ;
F_121 ( V_179 , V_15 , V_178 , V_127 ) ;
return 0 ;
}
static void F_122 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
F_123 ( V_15 , V_19 ) ;
V_15 -> V_82 &= ~ V_178 ;
F_121 ( V_179 , V_15 , V_178 , V_127 ) ;
}
static struct V_22 * F_124 ( struct V_10 * V_11 )
{
struct V_22 * V_22 = NULL ;
V_22 = F_83 ( sizeof( struct V_22 ) , V_127 ) ;
if ( ! V_22 )
return NULL ;
if ( F_20 ( V_11 ) == V_7 ) {
F_92 ( V_22 ) = F_83 ( sizeof( struct V_180 ) ,
V_127 ) ;
if ( ! F_92 ( V_22 ) ) {
F_85 ( V_22 ) ;
return NULL ;
}
}
return V_22 ;
}
static void F_125 ( struct V_22 * V_22 )
{
struct V_10 * V_11 = F_126 ( V_22 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_85 ( F_92 ( V_22 ) ) ;
F_85 ( V_22 ) ;
}
static void F_127 ( struct V_10 * V_11 , struct V_181 * V_182 )
{
V_182 -> V_183 = F_20 ( V_11 ) ;
V_182 -> V_117 = V_11 -> V_52 . V_117 ;
V_182 -> V_184 = V_11 -> V_185 ;
}
static void F_128 ( struct V_22 * V_22 , struct V_186 * V_182 )
{
strcpy ( V_182 -> V_187 , V_22 -> V_16 -> V_59 ) ;
V_182 -> V_29 = V_22 -> V_29 ;
V_182 -> V_114 = F_129 ( V_22 ) ;
V_182 -> V_188 = V_22 -> V_188 ;
}
static void F_130 ( struct V_14 * V_16 ,
struct V_189 * V_182 )
{
F_131 () ;
F_132 ( V_16 , V_182 ) ;
F_45 () ;
}
static void F_133 ( struct V_70 * V_190 )
{
struct V_191 * V_192 =
F_41 ( V_190 , struct V_191 , V_71 . V_71 ) ;
F_130 ( V_192 -> V_16 , & V_192 -> V_193 ) ;
F_134 ( V_192 -> V_16 ) ;
F_85 ( V_192 ) ;
}
void F_135 ( struct V_22 * V_22 )
{
struct V_10 * V_11 = V_22 -> V_11 ;
struct V_191 * V_194 = F_83 ( sizeof( * V_194 ) , V_171 ) ;
if ( ! V_194 )
return;
F_136 ( V_22 -> V_16 ) ;
V_194 -> V_16 = V_22 -> V_16 ;
F_128 ( V_22 , & V_194 -> V_193 . V_22 ) ;
F_127 ( V_11 , & V_194 -> V_193 . V_195 ) ;
F_137 ( & V_194 -> V_71 , F_133 ) ;
F_43 ( V_22 -> V_11 -> V_73 , & V_194 -> V_71 , 0 ) ;
}
int F_138 ( struct V_14 * V_19 , struct V_14 * V_15 )
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
F_139 ( V_19 , L_23 ,
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
if ( F_140 ( V_19 ) ) {
F_62 ( V_19 , L_27 ,
V_15 -> V_59 , V_19 -> V_59 ) ;
return - V_202 ;
} else {
F_139 ( V_19 , L_28 ,
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
V_26 = F_141 ( V_26 ) ;
if ( V_26 ) {
F_62 ( V_19 , L_32 ) ;
V_26 = - V_201 ;
goto V_205;
}
F_142 ( V_19 ) ;
F_143 ( V_19 ) ;
if ( V_15 -> type != V_207 )
F_106 ( V_19 , V_15 ) ;
else {
F_144 ( V_19 ) ;
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
F_139 ( V_19 , L_34 ) ;
if ( F_20 ( V_11 ) == V_4 &&
V_11 -> V_52 . V_94 != V_95 ) {
if ( ! F_19 ( V_11 ) ) {
V_11 -> V_52 . V_94 = V_95 ;
F_139 ( V_19 , L_35 ) ;
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
V_196 = F_124 ( V_11 ) ;
if ( ! V_196 ) {
V_26 = - V_128 ;
goto V_205;
}
V_196 -> V_11 = V_11 ;
V_196 -> V_16 = V_15 ;
V_196 -> V_215 = 0 ;
V_196 -> V_216 = V_15 -> V_217 ;
V_26 = F_145 ( V_15 , V_11 -> V_16 -> V_217 ) ;
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
V_26 = F_146 ( V_15 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_39 , V_15 -> V_59 ) ;
goto V_221;
}
V_15 -> V_160 |= V_222 ;
F_147 ( V_196 -> V_16 , & V_196 -> V_223 ) ;
if ( F_16 ( V_11 ) ) {
V_26 = F_148 ( V_11 , V_196 ) ;
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
F_149 ( V_15 , V_19 ) ;
F_150 ( V_15 , V_19 ) ;
F_54 ( V_19 ) ;
}
if ( F_20 ( V_11 ) == V_7 ) {
T_5 V_77 [ V_78 ] = V_79 ;
F_151 ( V_15 , V_77 ) ;
}
V_26 = F_152 ( V_15 , V_19 ) ;
if ( V_26 ) {
F_62 ( V_19 , L_40 ,
V_15 -> V_59 ) ;
goto V_224;
}
V_197 = F_153 ( V_11 ) ;
V_196 -> V_111 = 0 ;
V_196 -> V_188 = 0 ;
F_25 ( V_196 ) ;
V_196 -> V_225 = V_116 -
( F_154 ( V_11 -> V_52 . V_226 ) + 1 ) ;
for ( V_200 = 0 ; V_200 < V_227 ; V_200 ++ )
V_196 -> V_228 [ V_200 ] = V_196 -> V_225 ;
if ( V_11 -> V_52 . V_117 && ! V_11 -> V_52 . V_53 ) {
V_199 = F_29 ( V_11 , V_15 , 1 ) ;
if ( ( V_199 == - 1 ) && ! V_11 -> V_52 . V_226 ) {
F_139 ( V_19 , L_41 ,
V_15 -> V_59 ) ;
} else if ( V_199 == - 1 ) {
F_139 ( V_19 , L_42 ,
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
F_92 ( V_196 ) -> V_230 = 1 ;
F_155 ( V_11 , 1000 / V_231 ) ;
} else {
F_92 ( V_196 ) -> V_230 =
F_92 ( V_197 ) -> V_230 + 1 ;
}
F_156 ( V_196 ) ;
break;
case V_8 :
case V_9 :
F_157 ( V_196 ) ;
F_78 ( V_196 , V_118 ) ;
break;
default:
F_56 ( V_19 , L_47 ) ;
F_157 ( V_196 ) ;
if ( ! F_158 ( V_11 -> V_69 ) &&
V_196 -> V_29 == V_30 )
F_80 ( V_11 -> V_69 , V_196 ) ;
break;
}
#ifdef F_159
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
F_160 ( V_15 ) ;
V_26 = F_161 ( V_15 , F_109 ,
V_196 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_49 , V_26 ) ;
goto V_232;
}
V_26 = F_119 ( V_19 , V_15 , V_196 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_50 , V_26 ) ;
goto V_234;
}
V_26 = F_162 ( V_196 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_51 , V_26 ) ;
goto V_235;
}
V_11 -> V_185 ++ ;
F_102 ( V_11 ) ;
F_18 ( V_11 ) ;
if ( F_35 ( V_11 ) ) {
F_163 () ;
F_81 ( V_11 ) ;
F_164 () ;
}
if ( F_165 ( V_11 ) )
F_166 ( V_11 , NULL ) ;
F_73 ( V_19 , L_52 ,
V_15 -> V_59 ,
F_167 ( V_196 ) ? L_53 : L_54 ,
V_196 -> V_29 != V_42 ? L_55 : L_56 ) ;
F_135 ( V_196 ) ;
return 0 ;
V_235:
F_122 ( V_19 , V_15 ) ;
V_234:
F_168 ( V_15 ) ;
V_232:
if ( ! F_35 ( V_11 ) )
F_46 ( V_19 , V_15 ) ;
F_169 ( V_15 , V_19 ) ;
if ( F_158 ( V_11 -> V_101 ) == V_196 )
F_170 ( V_11 -> V_101 , NULL ) ;
if ( F_158 ( V_11 -> V_69 ) == V_196 ) {
F_163 () ;
F_71 ( V_11 , NULL ) ;
F_81 ( V_11 ) ;
F_164 () ;
}
F_171 () ;
F_86 ( V_196 ) ;
V_224:
V_15 -> V_160 &= ~ V_222 ;
F_172 ( V_15 ) ;
V_221:
if ( ! V_11 -> V_52 . V_94 ||
F_20 ( V_11 ) != V_4 ) {
F_60 ( V_198 . V_97 , V_196 -> V_219 ) ;
V_198 . V_98 = V_15 -> type ;
F_61 ( V_15 , & V_198 ) ;
}
V_220:
F_145 ( V_15 , V_196 -> V_216 ) ;
V_218:
F_125 ( V_196 ) ;
V_205:
if ( ! F_19 ( V_11 ) ) {
if ( F_173 ( V_19 -> V_86 ,
V_15 -> V_86 ) )
F_174 ( V_19 ) ;
if ( V_19 -> type != V_207 ) {
F_144 ( V_19 ) ;
V_19 -> V_82 |= V_236 ;
V_19 -> V_160 &= ~ V_208 ;
}
}
return V_26 ;
}
static int F_175 ( struct V_14 * V_19 ,
struct V_14 * V_15 ,
bool V_237 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_238 ;
struct V_91 V_198 ;
int V_239 = V_19 -> V_82 ;
T_6 V_240 = V_19 -> V_141 ;
if ( ! ( V_15 -> V_82 & V_178 ) ||
! F_176 ( V_15 , V_19 ) ) {
F_56 ( V_19 , L_57 ,
V_15 -> V_59 ) ;
return - V_210 ;
}
F_163 () ;
V_22 = F_8 ( V_11 , V_15 ) ;
if ( ! V_22 ) {
F_73 ( V_19 , L_58 ,
V_15 -> V_59 ) ;
F_164 () ;
return - V_210 ;
}
F_177 ( V_22 ) ;
F_178 ( V_11 -> V_16 , & V_11 -> V_241 ) ;
F_122 ( V_19 , V_15 ) ;
F_168 ( V_15 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_179 ( V_22 ) ;
if ( F_165 ( V_11 ) )
F_166 ( V_11 , V_22 ) ;
F_73 ( V_19 , L_59 ,
F_167 ( V_22 ) ? L_60 : L_61 ,
V_15 -> V_59 ) ;
V_238 = F_158 ( V_11 -> V_69 ) ;
F_170 ( V_11 -> V_242 , NULL ) ;
if ( ! V_237 && ( ! V_11 -> V_52 . V_94 ||
F_20 ( V_11 ) != V_4 ) ) {
if ( F_173 ( V_19 -> V_86 , V_22 -> V_219 ) &&
F_19 ( V_11 ) )
F_139 ( V_19 , L_62 ,
V_15 -> V_59 , V_22 -> V_219 ,
V_19 -> V_59 , V_15 -> V_59 ) ;
}
if ( F_36 ( V_11 -> V_101 ) == V_22 )
F_170 ( V_11 -> V_101 , NULL ) ;
if ( V_238 == V_22 )
F_71 ( V_11 , NULL ) ;
if ( F_16 ( V_11 ) ) {
F_180 ( V_11 , V_22 ) ;
}
if ( V_237 ) {
F_170 ( V_11 -> V_69 , NULL ) ;
} else if ( V_238 == V_22 ) {
F_81 ( V_11 ) ;
}
if ( ! F_19 ( V_11 ) ) {
F_18 ( V_11 ) ;
F_174 ( V_19 ) ;
}
F_164 () ;
F_171 () ;
V_11 -> V_185 -- ;
if ( ! F_19 ( V_11 ) ) {
F_44 ( V_89 , V_11 -> V_16 ) ;
F_44 ( V_243 , V_11 -> V_16 ) ;
}
F_102 ( V_11 ) ;
if ( ! ( V_19 -> V_141 & V_203 ) &&
( V_240 & V_203 ) )
F_73 ( V_19 , L_63 ,
V_15 -> V_59 , V_19 -> V_59 ) ;
F_169 ( V_15 , V_19 ) ;
if ( ! F_35 ( V_11 ) ) {
if ( V_239 & V_83 )
F_37 ( V_15 , - 1 ) ;
if ( V_239 & V_84 )
F_39 ( V_15 , - 1 ) ;
F_46 ( V_19 , V_15 ) ;
}
F_86 ( V_22 ) ;
F_172 ( V_15 ) ;
if ( V_11 -> V_52 . V_94 != V_95 ||
F_20 ( V_11 ) != V_4 ) {
F_60 ( V_198 . V_97 , V_22 -> V_219 ) ;
V_198 . V_98 = V_15 -> type ;
F_61 ( V_15 , & V_198 ) ;
}
F_145 ( V_15 , V_22 -> V_216 ) ;
V_15 -> V_160 &= ~ V_222 ;
F_125 ( V_22 ) ;
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
V_19 -> V_160 |= V_244 ;
F_73 ( V_19 , L_64 ,
V_19 -> V_59 ) ;
F_183 ( V_11 ) ;
F_184 ( V_19 ) ;
}
return V_169 ;
}
static int F_185 ( struct V_14 * V_19 , struct V_181 * V_182 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_127 ( V_11 , V_182 ) ;
return 0 ;
}
static int F_186 ( struct V_14 * V_19 , struct V_186 * V_182 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
int V_200 = 0 , V_26 = - V_245 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
if ( V_200 ++ == ( int ) V_182 -> V_246 ) {
V_26 = 0 ;
F_128 ( V_22 , V_182 ) ;
break;
}
}
return V_26 ;
}
static int F_187 ( struct V_10 * V_11 )
{
int V_247 , V_248 = 0 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
bool V_249 ;
V_249 = ! F_68 ( V_11 -> V_69 ) ;
F_91 (bond, slave, iter) {
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
( F_167 ( V_22 ) ?
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
static void F_188 ( struct V_10 * V_11 )
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
F_189 ( V_22 ) ;
} else if ( F_20 ( V_11 ) != V_4 ) {
F_157 ( V_22 ) ;
} else if ( V_22 != V_229 ) {
F_189 ( V_22 ) ;
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
F_166 ( V_11 , NULL ) ;
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
F_166 ( V_11 , NULL ) ;
if ( V_22 == F_158 ( V_11 -> V_69 ) )
goto V_253;
continue;
default:
F_62 ( V_11 -> V_16 , L_76 ,
V_22 -> V_250 , V_22 -> V_16 -> V_59 ) ;
V_22 -> V_250 = V_251 ;
continue;
}
V_253:
F_163 () ;
F_81 ( V_11 ) ;
F_164 () ;
}
F_18 ( V_11 ) ;
}
static void F_190 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_41 ( V_71 , struct V_10 ,
V_255 . V_71 ) ;
bool V_119 = false ;
unsigned long V_111 ;
V_111 = F_154 ( V_11 -> V_52 . V_117 ) ;
if ( ! F_19 ( V_11 ) )
goto V_256;
F_67 () ;
V_119 = F_66 ( V_11 ) ;
if ( F_187 ( V_11 ) ) {
F_69 () ;
if ( ! F_42 () ) {
V_111 = 1 ;
V_119 = false ;
goto V_256;
}
F_188 ( V_11 ) ;
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
static bool F_191 ( struct V_10 * V_11 , T_8 V_257 )
{
struct V_14 * V_258 ;
struct V_24 * V_25 ;
bool V_169 = false ;
if ( V_257 == F_192 ( V_11 -> V_16 , 0 , V_257 ) )
return true ;
F_67 () ;
F_193 (bond->dev, upper, iter) {
if ( V_257 == F_192 ( V_258 , 0 , V_257 ) ) {
V_169 = true ;
break;
}
}
F_69 () ;
return V_169 ;
}
static void F_194 ( struct V_14 * V_15 , int V_259 ,
T_8 V_260 , T_8 V_261 ,
struct V_262 * V_263 )
{
struct V_12 * V_13 ;
struct V_262 * V_264 = V_263 ;
F_56 ( V_15 , L_77 ,
V_259 , V_15 -> V_59 , & V_260 , & V_261 ) ;
V_13 = F_195 ( V_259 , V_265 , V_260 , V_15 , V_261 ,
NULL , V_15 -> V_86 , NULL ) ;
if ( ! V_13 ) {
F_196 ( L_78 ) ;
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
F_197 ( V_264 -> V_266 ) , V_263 -> V_269 ) ;
V_13 = F_198 ( V_13 , V_263 -> V_266 ,
V_263 -> V_269 ) ;
if ( ! V_13 ) {
F_196 ( L_80 ) ;
return;
}
V_263 ++ ;
}
if ( V_264 -> V_269 ) {
F_56 ( V_15 , L_81 ,
F_197 ( V_264 -> V_266 ) , V_264 -> V_269 ) ;
F_199 ( V_13 , V_264 -> V_266 ,
V_264 -> V_269 ) ;
}
V_268:
F_200 ( V_13 ) ;
}
struct V_262 * F_201 ( struct V_14 * V_270 ,
struct V_14 * V_271 ,
int V_272 )
{
struct V_262 * V_263 ;
struct V_14 * V_258 ;
struct V_24 * V_25 ;
if ( V_270 == V_271 ) {
V_263 = F_83 ( sizeof( * V_263 ) * ( V_272 + 1 ) , V_171 ) ;
if ( ! V_263 )
return F_202 ( - V_128 ) ;
V_263 [ V_272 ] . V_266 = V_267 ;
return V_263 ;
}
F_203 (start_dev, upper, iter) {
V_263 = F_201 ( V_258 , V_271 , V_272 + 1 ) ;
if ( F_204 ( V_263 ) ) {
if ( F_205 ( V_263 ) )
return V_263 ;
continue;
}
if ( F_206 ( V_258 ) ) {
V_263 [ V_272 ] . V_266 = F_207 ( V_258 ) ;
V_263 [ V_272 ] . V_269 = F_208 ( V_258 ) ;
}
return V_263 ;
}
return NULL ;
}
static void F_209 ( struct V_10 * V_11 , struct V_22 * V_22 )
{
struct V_273 * V_274 ;
struct V_262 * V_263 ;
T_8 * V_275 = V_11 -> V_52 . V_276 , V_198 ;
int V_200 ;
for ( V_200 = 0 ; V_200 < V_227 && V_275 [ V_200 ] ; V_200 ++ ) {
F_56 ( V_11 -> V_16 , L_82 , & V_275 [ V_200 ] ) ;
V_263 = NULL ;
V_274 = F_210 ( F_211 ( V_11 -> V_16 ) , V_275 [ V_200 ] , 0 ,
V_277 , 0 ) ;
if ( F_205 ( V_274 ) ) {
if ( V_11 -> V_52 . V_278 )
F_212 ( L_83 ,
V_11 -> V_16 -> V_59 ,
& V_275 [ V_200 ] ) ;
F_194 ( V_22 -> V_16 , V_279 , V_275 [ V_200 ] ,
0 , V_263 ) ;
continue;
}
if ( V_274 -> V_280 . V_16 == V_11 -> V_16 )
goto V_281;
F_67 () ;
V_263 = F_201 ( V_11 -> V_16 , V_274 -> V_280 . V_16 , 0 ) ;
F_69 () ;
if ( ! F_204 ( V_263 ) )
goto V_281;
F_56 ( V_11 -> V_16 , L_84 ,
& V_275 [ V_200 ] , V_274 -> V_280 . V_16 ? V_274 -> V_280 . V_16 -> V_59 : L_18 ) ;
F_213 ( V_274 ) ;
continue;
V_281:
V_198 = F_192 ( V_274 -> V_280 . V_16 , V_275 [ V_200 ] , 0 ) ;
F_213 ( V_274 ) ;
F_194 ( V_22 -> V_16 , V_279 , V_275 [ V_200 ] ,
V_198 , V_263 ) ;
F_85 ( V_263 ) ;
}
}
static void F_214 ( struct V_10 * V_11 , struct V_22 * V_22 , T_8 V_282 , T_8 V_283 )
{
int V_200 ;
if ( ! V_282 || ! F_191 ( V_11 , V_283 ) ) {
F_56 ( V_11 -> V_16 , L_85 ,
& V_282 , & V_283 ) ;
return;
}
V_200 = F_215 ( V_11 -> V_52 . V_276 , V_282 ) ;
if ( V_200 == - 1 ) {
F_56 ( V_11 -> V_16 , L_86 ,
& V_282 ) ;
return;
}
V_22 -> V_225 = V_116 ;
V_22 -> V_228 [ V_200 ] = V_116 ;
}
int F_216 ( const struct V_12 * V_13 , struct V_10 * V_11 ,
struct V_22 * V_22 )
{
struct V_284 * V_285 = (struct V_284 * ) V_13 -> V_176 ;
struct V_22 * V_69 ;
unsigned char * V_286 ;
T_8 V_282 , V_283 ;
int V_287 , V_288 = V_13 -> V_289 == F_217 ( V_265 ) ;
if ( ! F_218 ( V_11 , V_22 ) ) {
if ( ( F_219 ( V_11 ) && V_288 ) ||
! F_219 ( V_11 ) )
V_22 -> V_225 = V_116 ;
return V_170 ;
} else if ( ! V_288 ) {
return V_170 ;
}
V_287 = F_220 ( V_11 -> V_16 ) ;
F_56 ( V_11 -> V_16 , L_87 ,
V_13 -> V_16 -> V_59 ) ;
if ( V_287 > F_221 ( V_13 ) ) {
V_285 = F_222 ( V_287 , V_171 ) ;
if ( ! V_285 )
goto V_290;
if ( F_223 ( V_13 , 0 , V_285 , V_287 ) < 0 )
goto V_290;
}
if ( V_285 -> V_291 != V_11 -> V_16 -> V_85 ||
V_13 -> V_165 == V_292 ||
V_13 -> V_165 == V_293 ||
V_285 -> V_294 != F_224 ( V_207 ) ||
V_285 -> V_295 != F_224 ( V_296 ) ||
V_285 -> V_297 != 4 )
goto V_290;
V_286 = ( unsigned char * ) ( V_285 + 1 ) ;
V_286 += V_11 -> V_16 -> V_85 ;
memcpy ( & V_282 , V_286 , 4 ) ;
V_286 += 4 + V_11 -> V_16 -> V_85 ;
memcpy ( & V_283 , V_286 , 4 ) ;
F_56 ( V_11 -> V_16 , L_88 ,
V_22 -> V_16 -> V_59 , F_129 ( V_22 ) ,
V_11 -> V_52 . V_278 , F_218 ( V_11 , V_22 ) ,
& V_282 , & V_283 ) ;
V_69 = F_68 ( V_11 -> V_69 ) ;
if ( F_167 ( V_22 ) )
F_214 ( V_11 , V_22 , V_282 , V_283 ) ;
else if ( V_69 &&
F_225 ( F_226 ( V_11 , V_69 ) ,
V_69 -> V_115 ) )
F_214 ( V_11 , V_22 , V_283 , V_282 ) ;
V_290:
if ( V_285 != (struct V_284 * ) V_13 -> V_176 )
F_85 ( V_285 ) ;
return V_170 ;
}
static bool F_227 ( struct V_10 * V_11 , unsigned long V_298 ,
int V_299 )
{
int V_300 = F_154 ( V_11 -> V_52 . V_226 ) ;
return F_228 ( V_116 ,
V_298 - V_300 ,
V_298 + V_299 * V_300 + V_300 / 2 ) ;
}
static void F_229 ( struct V_70 * V_71 )
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
F_91 (bond, slave, iter) {
unsigned long V_303 = F_230 ( V_22 -> V_16 ) ;
if ( V_22 -> V_29 != V_30 ) {
if ( F_227 ( V_11 , V_303 , 1 ) &&
F_227 ( V_11 , V_22 -> V_225 , 1 ) ) {
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
if ( ! F_227 ( V_11 , V_303 , 2 ) ||
! F_227 ( V_11 , V_22 -> V_225 , 2 ) ) {
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
F_209 ( V_11 , V_22 ) ;
}
F_69 () ;
if ( V_253 || V_302 ) {
if ( ! F_42 () )
goto V_256;
if ( V_302 ) {
F_231 ( V_11 ) ;
if ( F_20 ( V_11 ) == V_5 )
F_166 ( V_11 , NULL ) ;
}
if ( V_253 ) {
F_163 () ;
F_81 ( V_11 ) ;
F_164 () ;
}
F_45 () ;
}
V_256:
if ( V_11 -> V_52 . V_226 )
F_43 ( V_11 -> V_73 , & V_11 -> V_301 ,
F_154 ( V_11 -> V_52 . V_226 ) ) ;
}
static int F_232 ( struct V_10 * V_11 )
{
unsigned long V_303 , V_225 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_248 = 0 ;
F_91 (bond, slave, iter) {
V_22 -> V_250 = V_251 ;
V_225 = F_226 ( V_11 , V_22 ) ;
if ( V_22 -> V_29 != V_30 ) {
if ( F_227 ( V_11 , V_225 , 1 ) ) {
V_22 -> V_250 = V_30 ;
V_248 ++ ;
}
continue;
}
if ( F_227 ( V_11 , V_22 -> V_115 , 2 ) )
continue;
if ( ! F_167 ( V_22 ) &&
! F_158 ( V_11 -> V_242 ) &&
! F_227 ( V_11 , V_225 , 3 ) ) {
V_22 -> V_250 = V_42 ;
V_248 ++ ;
}
V_303 = F_230 ( V_22 -> V_16 ) ;
if ( F_167 ( V_22 ) &&
( ! F_227 ( V_11 , V_303 , 2 ) ||
! F_227 ( V_11 , V_225 , 2 ) ) ) {
V_22 -> V_250 = V_42 ;
V_248 ++ ;
}
}
return V_248 ;
}
static void F_233 ( struct V_10 * V_11 )
{
unsigned long V_303 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
switch ( V_22 -> V_250 ) {
case V_251 :
continue;
case V_30 :
V_303 = F_230 ( V_22 -> V_16 ) ;
if ( F_36 ( V_11 -> V_69 ) != V_22 ||
( ! F_36 ( V_11 -> V_69 ) &&
F_227 ( V_11 , V_303 , 1 ) ) ) {
struct V_22 * V_242 ;
V_242 = F_36 ( V_11 -> V_242 ) ;
F_74 ( V_22 , V_30 ) ;
if ( V_242 ) {
F_78 (
V_242 ,
V_118 ) ;
F_170 ( V_11 -> V_242 , NULL ) ;
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
F_170 ( V_11 -> V_242 , NULL ) ;
goto V_253;
}
continue;
default:
F_62 ( V_11 -> V_16 , L_92 ,
V_22 -> V_250 , V_22 -> V_16 -> V_59 ) ;
continue;
}
V_253:
F_163 () ;
F_81 ( V_11 ) ;
F_164 () ;
}
F_18 ( V_11 ) ;
}
static bool F_234 ( struct V_10 * V_11 )
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
F_209 ( V_11 , V_69 ) ;
return V_306 ;
}
if ( ! V_305 ) {
V_305 = F_235 ( V_11 ) ;
if ( ! V_305 )
return V_306 ;
}
F_78 ( V_305 , V_307 ) ;
F_91 (bond, slave, iter) {
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
F_209 ( V_11 , V_196 ) ;
V_196 -> V_115 = V_116 ;
F_80 ( V_11 -> V_242 , V_196 ) ;
V_308:
F_91 (bond, slave, iter) {
if ( V_22 -> V_309 ) {
V_306 = V_118 ;
break;
}
}
return V_306 ;
}
static void F_236 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_41 ( V_71 , struct V_10 ,
V_301 . V_71 ) ;
bool V_119 = false ;
bool V_306 = false ;
int V_300 ;
V_300 = F_154 ( V_11 -> V_52 . V_226 ) ;
if ( ! F_19 ( V_11 ) )
goto V_256;
F_67 () ;
V_119 = F_66 ( V_11 ) ;
if ( F_232 ( V_11 ) ) {
F_69 () ;
if ( ! F_42 () ) {
V_300 = 1 ;
V_119 = false ;
goto V_256;
}
F_233 ( V_11 ) ;
F_45 () ;
F_67 () ;
}
V_306 = F_234 ( V_11 ) ;
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
F_237 ( V_11 ) ;
F_45 () ;
}
}
static int F_238 ( struct V_10 * V_11 )
{
F_183 ( V_11 ) ;
F_239 ( V_11 ) ;
F_240 ( V_11 ) ;
return V_310 ;
}
static int F_241 ( unsigned long V_311 ,
struct V_14 * V_19 )
{
struct V_10 * V_312 = F_11 ( V_19 ) ;
switch ( V_311 ) {
case V_313 :
return F_238 ( V_312 ) ;
case V_314 :
F_183 ( V_312 ) ;
break;
case V_315 :
F_239 ( V_312 ) ;
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
static int F_242 ( unsigned long V_311 ,
struct V_14 * V_15 )
{
struct V_22 * V_22 = F_243 ( V_15 ) , * V_229 ;
struct V_10 * V_11 ;
struct V_14 * V_19 ;
T_3 V_316 ;
T_5 V_317 ;
if ( ! V_22 )
return V_310 ;
V_19 = V_22 -> V_11 -> V_16 ;
V_11 = V_22 -> V_11 ;
V_229 = F_36 ( V_11 -> V_101 ) ;
switch ( V_311 ) {
case V_314 :
if ( V_19 -> type != V_207 )
F_182 ( V_19 , V_15 ) ;
else
F_181 ( V_19 , V_15 ) ;
break;
case V_318 :
case V_319 :
V_316 = V_22 -> V_34 ;
V_317 = V_22 -> V_36 ;
F_25 ( V_22 ) ;
if ( F_20 ( V_11 ) == V_7 ) {
if ( V_316 != V_22 -> V_34 )
F_244 ( V_22 ) ;
if ( V_317 != V_22 -> V_36 )
F_245 ( V_22 ) ;
}
case V_320 :
if ( F_165 ( V_11 ) )
F_166 ( V_11 , NULL ) ;
break;
case V_321 :
break;
case V_313 :
if ( ! F_35 ( V_11 ) ||
! V_11 -> V_52 . V_229 [ 0 ] )
break;
if ( V_22 == V_229 ) {
F_170 ( V_11 -> V_101 , NULL ) ;
} else if ( ! strcmp ( V_15 -> V_59 , V_11 -> V_52 . V_229 ) ) {
F_80 ( V_11 -> V_101 , V_22 ) ;
} else {
break;
}
F_73 ( V_11 -> V_16 , L_95 ,
V_229 ? V_15 -> V_59 : L_96 ) ;
F_163 () ;
F_81 ( V_11 ) ;
F_164 () ;
break;
case V_322 :
F_102 ( V_11 ) ;
break;
case V_74 :
F_44 ( V_311 , V_22 -> V_11 -> V_16 ) ;
break;
default:
break;
}
return V_310 ;
}
static int F_246 ( struct V_323 * V_324 ,
unsigned long V_311 , void * V_325 )
{
struct V_14 * V_326 = F_247 ( V_325 ) ;
F_56 ( V_326 , L_97 , V_311 ) ;
if ( ! ( V_326 -> V_160 & V_222 ) )
return V_310 ;
if ( V_326 -> V_82 & V_236 ) {
F_56 ( V_326 , L_98 ) ;
return F_241 ( V_311 , V_326 ) ;
}
if ( V_326 -> V_82 & V_178 ) {
F_56 ( V_326 , L_99 ) ;
return F_242 ( V_311 , V_326 ) ;
}
return V_310 ;
}
static inline T_3 F_248 ( struct V_12 * V_13 )
{
struct V_327 * V_328 , V_329 ;
V_328 = F_249 ( V_13 , 0 , sizeof( V_329 ) , & V_329 ) ;
if ( V_328 )
return V_328 -> V_177 [ 5 ] ^ V_328 -> V_330 [ 5 ] ^ V_328 -> V_331 ;
return 0 ;
}
static bool F_250 ( struct V_10 * V_11 , struct V_12 * V_13 ,
struct V_332 * V_333 )
{
const struct V_334 * V_335 ;
const struct V_336 * V_337 ;
int V_338 , V_20 = - 1 ;
if ( V_11 -> V_52 . V_339 > V_340 )
return F_251 ( V_13 , V_333 ) ;
V_333 -> V_341 . V_341 = 0 ;
V_338 = F_252 ( V_13 ) ;
if ( V_13 -> V_289 == F_224 ( V_296 ) ) {
if ( F_5 ( ! F_253 ( V_13 , V_338 + sizeof( * V_337 ) ) ) )
return false ;
V_337 = F_254 ( V_13 ) ;
F_255 ( V_333 , V_337 ) ;
V_338 += V_337 -> V_342 << 2 ;
if ( ! F_256 ( V_337 ) )
V_20 = V_337 -> V_289 ;
} else if ( V_13 -> V_289 == F_224 ( V_343 ) ) {
if ( F_5 ( ! F_253 ( V_13 , V_338 + sizeof( * V_335 ) ) ) )
return false ;
V_335 = F_257 ( V_13 ) ;
F_258 ( V_333 , V_335 ) ;
V_338 += sizeof( * V_335 ) ;
V_20 = V_335 -> V_344 ;
} else {
return false ;
}
if ( V_11 -> V_52 . V_339 == V_345 && V_20 >= 0 )
V_333 -> V_341 . V_341 = F_259 ( V_13 , V_338 , V_20 ) ;
return true ;
}
T_3 F_260 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
struct V_332 V_346 ;
T_3 V_347 ;
if ( V_11 -> V_52 . V_339 == V_348 ||
! F_250 ( V_11 , V_13 , & V_346 ) )
return F_248 ( V_13 ) ;
if ( V_11 -> V_52 . V_339 == V_340 ||
V_11 -> V_52 . V_339 == V_349 )
V_347 = F_248 ( V_13 ) ;
else
V_347 = ( V_350 T_3 ) V_346 . V_341 . V_341 ;
V_347 ^= ( V_350 T_3 ) F_261 ( & V_346 ) ^
( V_350 T_3 ) F_262 ( & V_346 ) ;
V_347 ^= ( V_347 >> 16 ) ;
V_347 ^= ( V_347 >> 8 ) ;
return V_347 ;
}
static void F_263 ( struct V_10 * V_11 )
{
F_137 ( & V_11 -> V_72 ,
F_40 ) ;
F_137 ( & V_11 -> V_351 , V_352 ) ;
F_137 ( & V_11 -> V_255 , F_190 ) ;
if ( F_20 ( V_11 ) == V_4 )
F_137 ( & V_11 -> V_301 , F_236 ) ;
else
F_137 ( & V_11 -> V_301 , F_229 ) ;
F_137 ( & V_11 -> V_353 , V_354 ) ;
F_137 ( & V_11 -> V_355 , V_356 ) ;
}
static void F_264 ( struct V_10 * V_11 )
{
F_265 ( & V_11 -> V_255 ) ;
F_265 ( & V_11 -> V_301 ) ;
F_265 ( & V_11 -> V_351 ) ;
F_265 ( & V_11 -> V_353 ) ;
F_265 ( & V_11 -> V_72 ) ;
F_265 ( & V_11 -> V_355 ) ;
}
static int F_266 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
if ( F_19 ( V_11 ) ) {
F_12 (bond, slave, iter) {
if ( F_35 ( V_11 ) &&
V_22 != F_158 ( V_11 -> V_69 ) ) {
F_78 ( V_22 ,
V_118 ) ;
} else if ( F_20 ( V_11 ) != V_7 ) {
F_79 ( V_22 ,
V_118 ) ;
}
}
}
F_263 ( V_11 ) ;
if ( F_16 ( V_11 ) ) {
if ( F_267 ( V_11 , ( F_20 ( V_11 ) == V_9 ) ) )
return - V_128 ;
if ( V_11 -> V_52 . V_357 )
F_43 ( V_11 -> V_73 , & V_11 -> V_351 , 0 ) ;
}
if ( V_11 -> V_52 . V_117 )
F_43 ( V_11 -> V_73 , & V_11 -> V_255 , 0 ) ;
if ( V_11 -> V_52 . V_226 ) {
F_43 ( V_11 -> V_73 , & V_11 -> V_301 , 0 ) ;
V_11 -> F_110 = F_216 ;
}
if ( F_20 ( V_11 ) == V_7 ) {
F_43 ( V_11 -> V_73 , & V_11 -> V_353 , 0 ) ;
V_11 -> F_110 = V_358 ;
F_268 ( V_11 , 1 ) ;
}
if ( F_165 ( V_11 ) )
F_166 ( V_11 , NULL ) ;
return 0 ;
}
static int F_269 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_264 ( V_11 ) ;
V_11 -> V_112 = 0 ;
if ( F_16 ( V_11 ) )
F_270 ( V_11 ) ;
V_11 -> F_110 = NULL ;
return 0 ;
}
static struct V_359 * F_178 ( struct V_14 * V_19 ,
struct V_359 * V_360 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_359 V_361 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
memcpy ( V_360 , & V_11 -> V_241 , sizeof( * V_360 ) ) ;
F_12 (bond, slave, iter) {
const struct V_359 * V_362 =
F_147 ( V_22 -> V_16 , & V_361 ) ;
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
static int F_271 ( struct V_14 * V_19 , struct V_48 * V_49 , int V_385 )
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
if ( F_272 ( & V_386 , V_387 , sizeof( V_181 ) ) )
return - V_397 ;
V_26 = F_185 ( V_19 , & V_386 ) ;
if ( V_26 == 0 &&
F_273 ( V_387 , & V_386 , sizeof( V_181 ) ) )
return - V_397 ;
return V_26 ;
case V_398 :
case V_399 :
V_389 = (struct V_186 T_9 * ) V_49 -> V_396 ;
if ( F_272 ( & V_388 , V_389 , sizeof( V_186 ) ) )
return - V_397 ;
V_26 = F_186 ( V_19 , & V_388 ) ;
if ( V_26 == 0 &&
F_273 ( V_389 , & V_388 , sizeof( V_186 ) ) )
return - V_397 ;
return V_26 ;
default:
break;
}
V_392 = F_211 ( V_19 ) ;
if ( ! F_274 ( V_392 -> V_400 , V_401 ) )
return - V_202 ;
V_15 = F_275 ( V_392 , V_49 -> V_402 ) ;
F_56 ( V_19 , L_101 , V_15 ) ;
if ( ! V_15 )
return - V_245 ;
F_56 ( V_19 , L_102 , V_15 -> V_59 ) ;
switch ( V_385 ) {
case V_403 :
case V_404 :
V_26 = F_138 ( V_19 , V_15 ) ;
break;
case V_405 :
case V_406 :
V_26 = F_181 ( V_19 , V_15 ) ;
break;
case V_407 :
case V_408 :
F_55 ( V_19 , V_15 ) ;
V_26 = 0 ;
break;
case V_409 :
case V_410 :
F_276 ( & V_391 , V_15 -> V_59 ) ;
V_26 = F_277 ( V_11 , V_411 , & V_391 ) ;
break;
default:
V_26 = - V_212 ;
}
return V_26 ;
}
static void F_278 ( struct V_14 * V_19 , int V_412 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
if ( V_412 & V_83 )
F_34 ( V_11 ,
V_19 -> V_82 & V_83 ? 1 : - 1 ) ;
if ( V_412 & V_84 )
F_38 ( V_11 ,
V_19 -> V_82 & V_84 ? 1 : - 1 ) ;
}
static void F_279 ( struct V_14 * V_19 )
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
F_91 (bond, slave, iter) {
F_150 ( V_22 -> V_16 , V_19 ) ;
F_149 ( V_22 -> V_16 , V_19 ) ;
}
}
F_69 () ;
}
static int F_280 ( struct V_413 * V_414 )
{
struct V_10 * V_11 = F_11 ( V_414 -> V_16 ) ;
const struct V_45 * V_46 ;
struct V_415 V_416 ;
struct V_22 * V_22 ;
int V_169 ;
V_22 = F_281 ( V_11 ) ;
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
static int F_282 ( struct V_14 * V_16 ,
struct V_415 * V_416 )
{
if ( V_416 -> V_16 == V_16 )
V_416 -> V_418 = F_280 ;
return 0 ;
}
static int F_283 ( struct V_14 * V_19 , int V_420 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_23 ;
struct V_24 * V_25 ;
int V_26 = 0 ;
F_56 ( V_19 , L_103 , V_11 , V_420 ) ;
F_12 (bond, slave, iter) {
F_56 ( V_19 , L_104 ,
V_22 , V_22 -> V_16 -> V_47 -> V_421 ) ;
V_26 = F_145 ( V_22 -> V_16 , V_420 ) ;
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
V_422 = F_145 ( V_23 -> V_16 , V_19 -> V_217 ) ;
if ( V_422 ) {
F_56 ( V_19 , L_106 ,
V_422 , V_23 -> V_16 -> V_59 ) ;
}
}
return V_26 ;
}
static int F_284 ( struct V_14 * V_19 , void * V_198 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_23 ;
struct V_91 * V_423 = V_198 , V_424 ;
struct V_24 * V_25 ;
int V_26 = 0 ;
if ( F_20 ( V_11 ) == V_9 )
return F_285 ( V_19 , V_198 ) ;
F_56 ( V_19 , L_107 , V_11 ) ;
if ( V_11 -> V_52 . V_94 &&
F_20 ( V_11 ) == V_4 )
return 0 ;
if ( ! F_286 ( V_423 -> V_97 ) )
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
static void F_287 ( struct V_10 * V_11 , struct V_12 * V_13 , int V_246 )
{
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_200 = V_246 ;
F_91 (bond, slave, iter) {
if ( -- V_200 < 0 ) {
if ( F_288 ( V_22 ) ) {
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
return;
}
}
}
V_200 = V_246 ;
F_91 (bond, slave, iter) {
if ( -- V_200 < 0 )
break;
if ( F_288 ( V_22 ) ) {
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
return;
}
}
F_289 ( V_11 -> V_16 , V_13 ) ;
}
static T_3 F_290 ( struct V_10 * V_11 )
{
T_3 V_246 ;
struct V_426 V_427 ;
int V_428 = V_11 -> V_52 . V_428 ;
switch ( V_428 ) {
case 0 :
V_246 = F_291 () ;
break;
case 1 :
V_246 = V_11 -> V_429 ;
break;
default:
V_427 =
V_11 -> V_52 . V_427 ;
V_246 = F_292 ( V_11 -> V_429 ,
V_427 ) ;
break;
}
V_11 -> V_429 ++ ;
return V_246 ;
}
static int F_293 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_336 * V_337 = F_254 ( V_13 ) ;
struct V_22 * V_22 ;
T_3 V_246 ;
if ( V_337 -> V_289 == V_430 && V_13 -> V_289 == F_224 ( V_296 ) ) {
V_22 = F_68 ( V_11 -> V_69 ) ;
if ( V_22 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_287 ( V_11 , V_13 , 0 ) ;
} else {
int V_185 = F_113 ( V_11 -> V_185 ) ;
if ( F_294 ( V_185 ) ) {
V_246 = F_290 ( V_11 ) ;
F_287 ( V_11 , V_13 , V_246 % V_185 ) ;
} else {
F_289 ( V_19 , V_13 ) ;
}
}
return V_431 ;
}
static int F_295 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 ;
V_22 = F_68 ( V_11 -> V_69 ) ;
if ( V_22 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_289 ( V_19 , V_13 ) ;
return V_431 ;
}
void F_296 ( struct V_10 * V_11 , unsigned long V_111 )
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
V_169 = F_166 ( V_11 , NULL ) ;
F_45 () ;
if ( V_169 ) {
F_297 ( L_109 ) ;
goto V_67;
}
return;
V_67:
F_296 ( V_11 , 1 ) ;
}
int F_166 ( struct V_10 * V_11 , struct V_22 * V_432 )
{
struct V_22 * V_22 ;
struct V_24 * V_25 ;
struct V_433 * V_434 , * V_435 ;
int V_436 ;
int V_437 = 0 ;
int V_169 = 0 ;
#ifdef F_298
F_299 ( F_300 ( & V_11 -> V_438 ) ) ;
#endif
V_434 = F_83 ( F_301 ( struct V_433 , V_439 [ V_11 -> V_185 ] ) ,
V_127 ) ;
if ( ! V_434 ) {
V_169 = - V_128 ;
F_302 ( L_110 ) ;
goto V_99;
}
if ( F_20 ( V_11 ) == V_7 ) {
struct V_129 V_129 ;
if ( F_89 ( V_11 , & V_129 ) ) {
F_303 ( L_111 ) ;
F_304 ( V_434 , V_440 ) ;
V_435 = F_36 ( V_11 -> V_441 ) ;
if ( V_435 ) {
F_170 ( V_11 -> V_441 , NULL ) ;
F_304 ( V_435 , V_440 ) ;
}
goto V_99;
}
V_436 = V_129 . V_341 ;
V_437 = V_129 . V_138 ;
}
F_12 (bond, slave, iter) {
if ( F_20 ( V_11 ) == V_7 ) {
struct V_134 * V_135 ;
V_135 = F_92 ( V_22 ) -> V_136 . V_134 ;
if ( ! V_135 || V_135 -> V_137 != V_437 )
continue;
}
if ( ! F_288 ( V_22 ) )
continue;
if ( V_432 == V_22 )
continue;
V_434 -> V_439 [ V_434 -> V_442 ++ ] = V_22 ;
}
V_435 = F_36 ( V_11 -> V_441 ) ;
F_80 ( V_11 -> V_441 , V_434 ) ;
if ( V_435 )
F_304 ( V_435 , V_440 ) ;
V_99:
if ( V_169 != 0 && V_432 ) {
int V_443 ;
V_435 = F_36 ( V_11 -> V_441 ) ;
for ( V_443 = 0 ; V_443 < V_435 -> V_442 ; V_443 ++ ) {
if ( V_432 == V_435 -> V_439 [ V_443 ] ) {
V_435 -> V_439 [ V_443 ] =
V_435 -> V_439 [ V_435 -> V_442 - 1 ] ;
V_435 -> V_442 -- ;
break;
}
}
}
return V_169 ;
}
static int F_305 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
struct V_22 * V_22 ;
struct V_433 * V_444 ;
unsigned int V_442 ;
V_444 = F_68 ( V_11 -> V_441 ) ;
V_442 = V_444 ? F_113 ( V_444 -> V_442 ) : 0 ;
if ( F_294 ( V_442 ) ) {
V_22 = V_444 -> V_439 [ F_260 ( V_11 , V_13 ) % V_442 ] ;
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
} else {
F_289 ( V_16 , V_13 ) ;
}
return V_431 ;
}
static int F_306 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 = NULL ;
struct V_24 * V_25 ;
F_91 (bond, slave, iter) {
if ( F_307 ( V_11 , V_22 ) )
break;
if ( F_65 ( V_22 ) && V_22 -> V_29 == V_30 ) {
struct V_12 * V_445 = F_308 ( V_13 , V_171 ) ;
if ( ! V_445 ) {
F_196 ( L_112 ,
V_19 -> V_59 , V_446 ) ;
continue;
}
F_2 ( V_11 , V_445 , V_22 -> V_16 ) ;
}
}
if ( V_22 && F_65 ( V_22 ) && V_22 -> V_29 == V_30 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_289 ( V_19 , V_13 ) ;
return V_431 ;
}
static inline int F_309 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_22 * V_22 = NULL ;
struct V_24 * V_25 ;
if ( ! V_13 -> V_17 )
return 1 ;
F_91 (bond, slave, iter) {
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
static T_2 F_310 ( struct V_14 * V_16 , struct V_12 * V_13 ,
void * V_447 , T_10 V_448 )
{
T_2 V_449 = F_311 ( V_13 ) ? F_312 ( V_13 ) : 0 ;
F_4 ( V_13 ) -> V_18 = V_13 -> V_17 ;
if ( F_5 ( V_449 >= V_16 -> V_450 ) ) {
do {
V_449 -= V_16 -> V_450 ;
} while ( V_449 >= V_16 -> V_450 );
}
return V_449 ;
}
static T_11 F_313 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
if ( F_314 ( V_11 ) &&
! F_309 ( V_11 , V_13 ) )
return V_431 ;
switch ( F_20 ( V_11 ) ) {
case V_3 :
return F_293 ( V_13 , V_16 ) ;
case V_4 :
return F_295 ( V_13 , V_16 ) ;
case V_7 :
case V_5 :
return F_305 ( V_13 , V_16 ) ;
case V_6 :
return F_306 ( V_13 , V_16 ) ;
case V_9 :
return F_315 ( V_13 , V_16 ) ;
case V_8 :
return F_316 ( V_13 , V_16 ) ;
default:
F_62 ( V_16 , L_113 , F_20 ( V_11 ) ) ;
F_317 ( 1 ) ;
F_289 ( V_16 , V_13 ) ;
return V_431 ;
}
}
static T_11 F_318 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
T_11 V_169 = V_431 ;
if ( F_5 ( F_319 ( V_16 ) ) )
return V_451 ;
F_67 () ;
if ( F_19 ( V_11 ) )
V_169 = F_313 ( V_13 , V_16 ) ;
else
F_289 ( V_16 , V_13 ) ;
F_69 () ;
return V_169 ;
}
static int F_320 ( struct V_14 * V_19 ,
struct V_31 * V_32 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
unsigned long V_34 = 0 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
V_32 -> V_36 = V_37 ;
V_32 -> V_136 = V_452 ;
F_12 (bond, slave, iter) {
if ( F_288 ( V_22 ) ) {
if ( V_22 -> V_34 != V_35 )
V_34 += V_22 -> V_34 ;
if ( V_32 -> V_36 == V_37 &&
V_22 -> V_36 != V_37 )
V_32 -> V_36 = V_22 -> V_36 ;
}
}
F_321 ( V_32 , V_34 ? : V_35 ) ;
return 0 ;
}
static void F_322 ( struct V_14 * V_19 ,
struct V_453 * V_454 )
{
F_323 ( V_454 -> V_455 , V_456 , sizeof( V_454 -> V_455 ) ) ;
F_323 ( V_454 -> V_457 , V_458 , sizeof( V_454 -> V_457 ) ) ;
snprintf ( V_454 -> V_459 , sizeof( V_454 -> V_459 ) , L_114 ,
V_460 ) ;
}
static void F_324 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
if ( V_11 -> V_73 )
F_325 ( V_11 -> V_73 ) ;
F_326 ( V_19 ) ;
}
void F_327 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_328 ( & V_11 -> V_438 ) ;
V_11 -> V_52 = V_461 ;
V_11 -> V_16 = V_19 ;
F_144 ( V_19 ) ;
V_19 -> V_47 = & V_462 ;
V_19 -> V_55 = & V_463 ;
V_19 -> V_464 = F_324 ;
F_329 ( V_19 , & V_465 ) ;
V_19 -> V_466 = 0 ;
V_19 -> V_82 |= V_236 | V_467 ;
V_19 -> V_160 |= V_222 | V_468 ;
V_19 -> V_160 &= ~ ( V_146 | V_208 ) ;
V_19 -> V_141 |= V_469 ;
V_19 -> V_141 |= V_470 ;
V_19 -> V_471 = V_149 |
V_472 |
V_473 |
V_474 ;
V_19 -> V_471 &= ~ ( V_475 & ~ V_476 ) ;
V_19 -> V_471 |= V_162 ;
V_19 -> V_141 |= V_19 -> V_471 ;
}
static void F_330 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
struct V_433 * V_439 ;
F_97 ( V_19 ) ;
F_12 (bond, slave, iter)
F_175 ( V_19 , V_22 -> V_16 , true ) ;
F_73 ( V_19 , L_115 ) ;
V_439 = F_36 ( V_11 -> V_441 ) ;
if ( V_439 ) {
F_170 ( V_11 -> V_441 , NULL ) ;
F_304 ( V_439 , V_440 ) ;
}
F_331 ( & V_11 -> V_477 ) ;
F_332 ( V_11 ) ;
}
static int F_333 ( struct V_478 * V_52 )
{
int V_479 , V_480 , V_481 , V_200 ;
struct V_390 V_391 ;
const struct V_390 * V_482 ;
int V_483 ;
T_2 V_484 = 0 ;
T_2 V_485 = 0 ;
if ( V_1 ) {
F_276 ( & V_391 , V_1 ) ;
V_482 = F_334 ( F_335 ( V_486 ) , & V_391 ) ;
if ( ! V_482 ) {
F_302 ( L_116 , V_1 ) ;
return - V_210 ;
}
V_183 = V_482 -> V_487 ;
}
if ( V_488 ) {
if ( ( V_183 != V_5 ) &&
( V_183 != V_7 ) &&
( V_183 != V_8 ) ) {
F_336 ( L_117 ,
F_1 ( V_183 ) ) ;
} else {
F_276 ( & V_391 , V_488 ) ;
V_482 = F_334 ( F_335 ( V_489 ) ,
& V_391 ) ;
if ( ! V_482 ) {
F_302 ( L_118 ,
V_488 ) ;
return - V_210 ;
}
V_490 = V_482 -> V_487 ;
}
}
if ( V_491 ) {
if ( V_183 != V_7 ) {
F_336 ( L_119 ,
F_1 ( V_183 ) ) ;
} else {
F_276 ( & V_391 , V_491 ) ;
V_482 = F_334 ( F_335 ( V_492 ) ,
& V_391 ) ;
if ( ! V_482 ) {
F_302 ( L_120 ,
V_491 ) ;
return - V_210 ;
}
V_493 = V_482 -> V_487 ;
}
}
if ( V_494 ) {
F_276 ( & V_391 , V_494 ) ;
V_482 = F_334 ( F_335 ( V_495 ) ,
& V_391 ) ;
if ( ! V_482 ) {
F_302 ( L_121 , V_494 ) ;
return - V_210 ;
}
V_52 -> V_494 = V_482 -> V_487 ;
if ( V_183 != V_7 )
F_337 ( L_122 ) ;
} else {
V_52 -> V_494 = V_496 ;
}
if ( V_497 < 0 ) {
F_337 ( L_123 ,
V_497 , 0 , V_498 , V_499 ) ;
V_497 = V_499 ;
}
if ( V_117 < 0 ) {
F_337 ( L_124 ,
V_117 , V_498 ) ;
V_117 = 0 ;
}
if ( V_110 < 0 ) {
F_337 ( L_125 ,
V_110 , V_498 ) ;
V_110 = 0 ;
}
if ( V_252 < 0 ) {
F_337 ( L_126 ,
V_252 , V_498 ) ;
V_252 = 0 ;
}
if ( ( V_53 != 0 ) && ( V_53 != 1 ) ) {
F_337 ( L_127 ,
V_53 ) ;
V_53 = 1 ;
}
if ( V_120 < 0 || V_120 > 255 ) {
F_337 ( L_128 ,
V_120 ) ;
V_120 = 1 ;
}
if ( ! F_338 ( V_183 ) ) {
if ( ! V_117 ) {
F_337 ( L_129 ) ;
F_337 ( L_130 ) ;
V_117 = V_500 ;
}
}
if ( V_501 < 1 || V_501 > 255 ) {
F_337 ( L_131 ,
V_501 , V_502 ) ;
V_501 = V_502 ;
}
if ( ( V_503 != 0 ) && ( V_503 != 1 ) ) {
F_337 ( L_132 ,
V_503 ) ;
V_503 = 0 ;
}
if ( V_123 < 0 || V_123 > 255 ) {
F_337 ( L_133 ,
V_123 , V_504 ) ;
V_123 = V_504 ;
}
F_339 ( & V_391 , V_428 ) ;
if ( ! F_334 ( F_335 ( V_505 ) , & V_391 ) ) {
F_337 ( L_134 ,
V_428 , V_506 ) ;
V_428 = 1 ;
}
if ( V_183 == V_9 ) {
F_340 ( L_135 ,
V_110 ) ;
}
if ( ! V_117 ) {
if ( V_110 || V_252 ) {
F_337 ( L_136 ,
V_110 , V_252 ) ;
}
} else {
if ( V_226 ) {
F_337 ( L_137 ,
V_117 , V_226 ) ;
V_226 = 0 ;
}
if ( ( V_110 % V_117 ) != 0 ) {
F_337 ( L_138 ,
V_110 , V_117 , ( V_110 / V_117 ) * V_117 ) ;
}
V_110 /= V_117 ;
if ( ( V_252 % V_117 ) != 0 ) {
F_337 ( L_139 ,
V_252 , V_117 ,
( V_252 / V_117 ) * V_117 ) ;
}
V_252 /= V_117 ;
}
if ( V_226 < 0 ) {
F_337 ( L_140 ,
V_226 , V_498 ) ;
V_226 = 0 ;
}
for ( V_507 = 0 , V_200 = 0 ;
( V_507 < V_227 ) && V_508 [ V_200 ] ; V_200 ++ ) {
T_8 V_257 ;
if ( ! F_341 ( V_508 [ V_200 ] , - 1 , ( T_5 * ) & V_257 , - 1 , NULL ) ||
! F_342 ( V_257 ) ) {
F_337 ( L_141 ,
V_508 [ V_200 ] ) ;
V_226 = 0 ;
} else {
if ( F_215 ( V_509 , V_257 ) == - 1 )
V_509 [ V_507 ++ ] = V_257 ;
else
F_337 ( L_142 ,
& V_257 ) ;
}
}
if ( V_226 && ! V_507 ) {
F_337 ( L_143 ,
V_226 ) ;
V_226 = 0 ;
}
if ( V_278 ) {
if ( ! V_226 ) {
F_302 ( L_144 ) ;
return - V_210 ;
}
F_276 ( & V_391 , V_278 ) ;
V_482 = F_334 ( F_335 ( V_510 ) ,
& V_391 ) ;
if ( ! V_482 ) {
F_302 ( L_145 ,
V_278 ) ;
return - V_210 ;
}
V_479 = V_482 -> V_487 ;
} else {
V_479 = 0 ;
}
V_483 = 0 ;
if ( V_511 ) {
F_276 ( & V_391 , V_511 ) ;
V_482 = F_334 ( F_335 ( V_512 ) ,
& V_391 ) ;
if ( ! V_482 ) {
F_302 ( L_146 ,
V_511 ) ;
V_483 = 0 ;
} else {
V_483 = V_482 -> V_487 ;
}
}
if ( V_117 ) {
F_336 ( L_147 , V_117 ) ;
} else if ( V_226 ) {
V_482 = F_343 ( V_510 ,
V_479 ) ;
F_336 ( L_148 ,
V_226 , V_482 -> string , V_507 ) ;
for ( V_200 = 0 ; V_200 < V_507 ; V_200 ++ )
F_344 ( L_149 , V_508 [ V_200 ] ) ;
F_344 ( L_150 ) ;
} else if ( V_497 ) {
F_303 ( L_151 ) ;
}
if ( V_229 && ! F_345 ( V_183 ) ) {
F_337 ( L_152 ,
V_229 , F_1 ( V_183 ) ) ;
V_229 = NULL ;
}
if ( V_229 && V_104 ) {
F_276 ( & V_391 , V_104 ) ;
V_482 = F_334 ( F_335 ( V_513 ) ,
& V_391 ) ;
if ( ! V_482 ) {
F_302 ( L_153 ,
V_104 ) ;
return - V_210 ;
}
V_481 = V_482 -> V_487 ;
} else {
V_481 = V_105 ;
}
if ( V_94 ) {
F_276 ( & V_391 , V_94 ) ;
V_482 = F_334 ( F_335 ( V_514 ) ,
& V_391 ) ;
if ( ! V_482 ) {
F_302 ( L_154 ,
V_94 ) ;
return - V_210 ;
}
V_480 = V_482 -> V_487 ;
if ( V_183 != V_4 )
F_337 ( L_155 ) ;
} else {
V_480 = V_515 ;
}
F_276 ( & V_391 , L_156 ) ;
V_482 = F_334 (
F_335 ( V_516 ) ,
& V_391 ) ;
if ( ! V_482 ) {
F_302 ( L_157 ) ;
return - V_210 ;
}
V_484 = V_482 -> V_487 ;
V_482 = F_334 ( F_335 ( V_517 ) ,
& V_391 ) ;
if ( ! V_482 ) {
F_302 ( L_158 ) ;
return - V_210 ;
}
V_485 = V_482 -> V_487 ;
if ( V_518 == 0 ) {
F_337 ( L_159 ,
V_498 , V_519 ) ;
V_518 = V_519 ;
}
V_52 -> V_1 = V_183 ;
V_52 -> V_339 = V_490 ;
V_52 -> V_117 = V_117 ;
V_52 -> V_120 = V_120 ;
V_52 -> V_226 = V_226 ;
V_52 -> V_278 = V_479 ;
V_52 -> V_511 = V_483 ;
V_52 -> V_110 = V_110 ;
V_52 -> V_252 = V_252 ;
V_52 -> V_53 = V_53 ;
V_52 -> V_493 = V_493 ;
V_52 -> V_229 [ 0 ] = 0 ;
V_52 -> V_104 = V_481 ;
V_52 -> V_94 = V_480 ;
V_52 -> V_501 = V_501 ;
V_52 -> V_503 = V_503 ;
V_52 -> V_123 = V_123 ;
V_52 -> V_520 = V_520 ;
V_52 -> V_518 = V_518 ;
V_52 -> V_428 = V_428 ;
V_52 -> V_357 = 1 ;
V_52 -> V_484 = V_484 ;
F_346 ( V_52 -> V_521 ) ;
V_52 -> V_485 = V_485 ;
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
memcpy ( V_52 -> V_276 , V_509 , sizeof( V_509 ) ) ;
return 0 ;
}
static void F_347 ( struct V_14 * V_16 ,
struct V_522 * V_449 ,
void * V_523 )
{
F_348 ( & V_449 -> V_524 ,
& V_525 ) ;
}
static void F_349 ( struct V_14 * V_16 )
{
F_348 ( & V_16 -> V_526 ,
& V_527 ) ;
F_350 ( V_16 , F_347 , NULL ) ;
V_16 -> V_528 = & V_529 ;
}
static int F_351 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_530 * V_531 = F_352 ( F_211 ( V_19 ) , V_532 ) ;
F_56 ( V_19 , L_160 ) ;
V_11 -> V_73 = F_353 ( V_19 -> V_59 ) ;
if ( ! V_11 -> V_73 )
return - V_128 ;
F_349 ( V_19 ) ;
F_354 ( & V_11 -> V_477 , & V_531 -> V_533 ) ;
F_355 ( V_11 ) ;
F_356 ( V_11 ) ;
if ( F_357 ( V_19 -> V_86 ) &&
V_19 -> V_87 == V_534 )
F_174 ( V_19 ) ;
return 0 ;
}
unsigned int F_358 ( void )
{
return V_501 ;
}
int F_359 ( struct V_392 * V_392 , const char * V_59 )
{
struct V_14 * V_19 ;
struct V_10 * V_11 ;
struct V_535 * V_536 ;
int V_26 ;
F_131 () ;
V_19 = F_360 ( sizeof( struct V_10 ) ,
V_59 ? V_59 : L_161 , V_537 ,
F_327 , V_501 ) ;
if ( ! V_19 ) {
F_302 ( L_162 , V_59 ) ;
F_45 () ;
return - V_128 ;
}
V_11 = F_11 ( V_19 ) ;
V_536 = & ( F_361 ( V_11 ) ) ;
V_536 -> V_538 = V_539 ;
F_362 ( V_19 , V_392 ) ;
V_19 -> V_540 = & V_541 ;
V_26 = F_363 ( V_19 ) ;
F_24 ( V_19 ) ;
F_45 () ;
if ( V_26 < 0 )
F_324 ( V_19 ) ;
return V_26 ;
}
static int T_12 F_364 ( struct V_392 * V_392 )
{
struct V_530 * V_531 = F_352 ( V_392 , V_532 ) ;
V_531 -> V_392 = V_392 ;
F_365 ( & V_531 -> V_533 ) ;
F_366 ( V_531 ) ;
F_367 ( V_531 ) ;
return 0 ;
}
static void T_13 F_368 ( struct V_392 * V_392 )
{
struct V_530 * V_531 = F_352 ( V_392 , V_532 ) ;
struct V_10 * V_11 , * V_542 ;
F_369 ( V_543 ) ;
F_370 ( V_531 ) ;
F_131 () ;
F_371 (bond, tmp_bond, &bn->dev_list, bond_list)
F_372 ( V_11 -> V_16 , & V_543 ) ;
F_373 ( & V_543 ) ;
F_45 () ;
F_374 ( V_531 ) ;
}
static int T_14 F_375 ( void )
{
int V_200 ;
int V_26 ;
F_336 ( L_163 , V_544 ) ;
V_26 = F_333 ( & V_461 ) ;
if ( V_26 )
goto V_99;
V_26 = F_376 ( & V_545 ) ;
if ( V_26 )
goto V_99;
V_26 = F_377 () ;
if ( V_26 )
goto V_546;
F_378 () ;
for ( V_200 = 0 ; V_200 < V_497 ; V_200 ++ ) {
V_26 = F_359 ( & V_547 , NULL ) ;
if ( V_26 )
goto V_67;
}
F_379 ( & V_548 ) ;
V_99:
return V_26 ;
V_67:
F_380 () ;
F_381 () ;
V_546:
F_382 ( & V_545 ) ;
goto V_99;
}
static void T_15 F_383 ( void )
{
F_384 ( & V_548 ) ;
F_380 () ;
F_381 () ;
F_382 ( & V_545 ) ;
#ifdef F_159
F_299 ( F_385 ( & V_549 ) ) ;
#endif
}
