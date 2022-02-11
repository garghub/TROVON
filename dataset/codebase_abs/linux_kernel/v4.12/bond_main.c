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
static int F_25 ( struct V_22 * V_22 )
{
struct V_14 * V_15 = V_22 -> V_16 ;
struct V_31 V_32 ;
int V_26 ;
V_22 -> V_33 = V_34 ;
V_22 -> V_35 = V_36 ;
V_26 = F_26 ( V_15 , & V_32 ) ;
if ( V_26 < 0 )
return 1 ;
if ( V_32 . V_37 . V_33 == 0 || V_32 . V_37 . V_33 == ( ( V_38 ) - 1 ) )
return 1 ;
switch ( V_32 . V_37 . V_35 ) {
case V_39 :
case V_40 :
break;
default:
return 1 ;
}
V_22 -> V_33 = V_32 . V_37 . V_33 ;
V_22 -> V_35 = V_32 . V_37 . V_35 ;
return 0 ;
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
T_4 V_90 [ V_91 ] ;
struct V_92 V_93 ;
int V_94 ;
switch ( V_11 -> V_52 . V_95 ) {
case V_96 :
if ( V_80 )
F_53 ( V_11 -> V_16 , V_80 -> V_16 ) ;
break;
case V_97 :
if ( ! V_80 )
return;
if ( ! V_81 )
V_81 = F_55 ( V_11 , V_80 ) ;
if ( V_81 ) {
F_58 ( V_90 , V_80 -> V_16 -> V_86 ,
V_80 -> V_16 -> V_85 ) ;
F_58 ( V_93 . V_98 ,
V_81 -> V_16 -> V_86 ,
V_81 -> V_16 -> V_85 ) ;
V_93 . V_99 = V_80 -> V_16 -> type ;
} else {
F_58 ( V_93 . V_98 , V_11 -> V_16 -> V_86 ,
V_11 -> V_16 -> V_85 ) ;
V_93 . V_99 = V_11 -> V_16 -> type ;
}
V_94 = F_59 ( V_80 -> V_16 ,
(struct V_100 * ) & V_93 ) ;
if ( V_94 ) {
F_60 ( V_11 -> V_16 , L_14 ,
- V_94 , V_80 -> V_16 -> V_59 ) ;
goto V_101;
}
if ( ! V_81 )
goto V_101;
F_58 ( V_93 . V_98 , V_90 ,
V_80 -> V_16 -> V_85 ) ;
V_93 . V_99 = V_81 -> V_16 -> type ;
V_94 = F_59 ( V_81 -> V_16 ,
(struct V_100 * ) & V_93 ) ;
if ( V_94 )
F_60 ( V_11 -> V_16 , L_14 ,
- V_94 , V_80 -> V_16 -> V_59 ) ;
V_101:
break;
default:
F_60 ( V_11 -> V_16 , L_15 ,
V_11 -> V_52 . V_95 ) ;
break;
}
}
static struct V_22 * F_61 ( struct V_10 * V_11 )
{
struct V_22 * V_102 = F_34 ( V_11 -> V_103 ) ;
struct V_22 * V_104 = F_34 ( V_11 -> V_69 ) ;
if ( ! V_102 || V_102 -> V_29 != V_30 ) {
if ( ! V_104 || V_104 -> V_29 != V_30 )
return NULL ;
return V_104 ;
}
if ( V_11 -> V_105 ) {
V_11 -> V_105 = false ;
return V_102 ;
}
if ( ! V_104 || V_104 -> V_29 != V_30 )
return V_102 ;
switch ( V_11 -> V_52 . V_106 ) {
case V_107 :
return V_102 ;
case V_108 :
if ( V_102 -> V_33 < V_104 -> V_33 )
return V_104 ;
if ( V_102 -> V_33 == V_104 -> V_33 && V_102 -> V_35 <= V_104 -> V_35 )
return V_104 ;
return V_102 ;
case V_109 :
return V_104 ;
default:
F_60 ( V_11 -> V_16 , L_16 ,
V_11 -> V_52 . V_106 ) ;
return V_104 ;
}
}
static struct V_22 * F_62 ( struct V_10 * V_11 )
{
struct V_22 * V_22 , * V_110 = NULL ;
struct V_24 * V_25 ;
int V_111 = V_11 -> V_52 . V_112 ;
V_22 = F_61 ( V_11 ) ;
if ( V_22 )
return V_22 ;
F_12 (bond, slave, iter) {
if ( V_22 -> V_29 == V_30 )
return V_22 ;
if ( V_22 -> V_29 == V_43 && F_63 ( V_22 ) &&
V_22 -> V_113 < V_111 ) {
V_111 = V_22 -> V_113 ;
V_110 = V_22 ;
}
}
return V_110 ;
}
static bool F_64 ( struct V_10 * V_11 )
{
struct V_22 * V_22 ;
F_65 () ;
V_22 = F_66 ( V_11 -> V_69 ) ;
F_67 () ;
F_54 ( V_11 -> V_16 , L_17 ,
V_22 ? V_22 -> V_16 -> V_59 : L_18 ) ;
if ( ! V_22 || ! V_11 -> V_114 ||
! F_22 ( V_11 -> V_16 ) ||
F_68 ( V_115 , & V_22 -> V_16 -> V_116 ) )
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
V_80 -> V_117 = V_118 ;
if ( V_80 -> V_29 == V_43 ) {
if ( F_33 ( V_11 ) ) {
F_71 ( V_11 -> V_16 , L_19 ,
V_80 -> V_16 -> V_59 ,
( V_11 -> V_52 . V_112 - V_80 -> V_113 ) * V_11 -> V_52 . V_119 ) ;
}
V_80 -> V_113 = 0 ;
F_72 ( V_80 , V_30 ,
V_120 ) ;
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
V_120 ) ;
if ( V_80 )
F_77 ( V_80 ,
V_120 ) ;
} else {
F_78 ( V_11 -> V_69 , V_80 ) ;
}
if ( F_20 ( V_11 ) == V_4 ) {
if ( V_81 )
F_76 ( V_81 ,
V_120 ) ;
if ( V_80 ) {
bool V_121 = false ;
F_77 ( V_80 ,
V_120 ) ;
if ( V_11 -> V_52 . V_95 )
F_57 ( V_11 , V_80 ,
V_81 ) ;
if ( F_30 ( V_11 -> V_16 ) ) {
V_11 -> V_114 =
V_11 -> V_52 . V_122 ;
V_121 =
F_64 ( V_11 ) ;
}
F_42 ( V_123 , V_11 -> V_16 ) ;
if ( V_121 )
F_42 ( V_124 ,
V_11 -> V_16 ) ;
}
}
if ( F_30 ( V_11 -> V_16 ) && ( V_11 -> V_52 . V_125 > 0 ) &&
( ( F_33 ( V_11 ) && V_80 ) ||
F_20 ( V_11 ) == V_3 ) ) {
V_11 -> V_75 = V_11 -> V_52 . V_125 ;
F_41 ( V_11 -> V_73 , & V_11 -> V_72 , 1 ) ;
}
}
void F_79 ( struct V_10 * V_11 )
{
struct V_22 * V_126 ;
int V_94 ;
F_70 () ;
V_126 = F_62 ( V_11 ) ;
if ( V_126 != F_34 ( V_11 -> V_69 ) ) {
F_69 ( V_11 , V_126 ) ;
V_94 = F_18 ( V_11 ) ;
if ( ! V_94 )
return;
if ( F_22 ( V_11 -> V_16 ) )
F_71 ( V_11 -> V_16 , L_21 ) ;
else
F_71 ( V_11 -> V_16 , L_22 ) ;
}
}
static inline int F_80 ( struct V_22 * V_22 )
{
struct V_127 * V_128 ;
int V_67 = 0 ;
V_128 = F_81 ( sizeof( * V_128 ) , V_129 ) ;
V_67 = - V_130 ;
if ( ! V_128 )
goto V_101;
V_67 = F_82 ( V_128 , V_22 -> V_16 ) ;
if ( V_67 ) {
F_83 ( V_128 ) ;
goto V_101;
}
V_22 -> V_128 = V_128 ;
V_101:
return V_67 ;
}
static inline void F_84 ( struct V_22 * V_22 )
{
struct V_127 * V_128 = V_22 -> V_128 ;
if ( ! V_128 )
return;
V_22 -> V_128 = NULL ;
F_85 ( V_128 ) ;
}
static void F_86 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 = NULL ;
struct V_24 * V_25 ;
struct V_131 V_131 ;
struct V_132 * V_133 ;
const struct V_45 * V_134 ;
if ( F_20 ( V_11 ) == V_7 )
if ( F_87 ( V_11 , & V_131 ) )
return;
F_88 (bond, slave, iter) {
V_134 = V_22 -> V_16 -> V_47 ;
if ( ! F_63 ( V_22 ) || ! V_134 -> V_135 )
continue;
if ( F_20 ( V_11 ) == V_7 ) {
struct V_136 * V_137 =
F_89 ( V_22 ) -> V_138 . V_136 ;
if ( V_137 &&
V_137 -> V_139 != V_131 . V_140 )
continue;
}
V_133 = F_90 ( V_22 -> V_16 -> V_141 ) ;
if ( F_91 ( & V_133 -> V_142 ) )
continue;
V_134 -> V_135 ( V_22 -> V_16 ) ;
F_92 ( & V_133 -> V_142 ) ;
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
static int F_94 ( struct V_14 * V_16 , struct V_132 * V_133 )
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
T_5 V_143 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
struct V_24 * V_25 ;
T_5 V_144 ;
struct V_22 * V_22 ;
V_144 = V_143 ;
V_143 &= ~ V_145 ;
V_143 |= V_146 ;
F_12 (bond, slave, iter) {
V_143 = F_96 ( V_143 ,
V_22 -> V_16 -> V_143 ,
V_144 ) ;
}
V_143 = F_97 ( V_143 , V_144 ) ;
return V_143 ;
}
static void F_98 ( struct V_10 * V_11 )
{
unsigned int V_147 = V_148 |
V_149 ;
T_5 V_150 = V_151 ;
T_5 V_152 = V_153 ;
struct V_14 * V_19 = V_11 -> V_16 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
unsigned short V_154 = V_155 ;
unsigned int V_156 = V_157 ;
T_2 V_158 = V_159 ;
if ( ! F_19 ( V_11 ) )
goto V_160;
V_150 &= V_146 ;
F_12 (bond, slave, iter) {
V_150 = F_96 ( V_150 ,
V_22 -> V_16 -> V_150 , V_151 ) ;
V_152 = F_96 ( V_152 ,
V_22 -> V_16 -> V_161 ,
V_153 ) ;
V_147 &= V_22 -> V_16 -> V_162 ;
if ( V_22 -> V_16 -> V_163 > V_154 )
V_154 = V_22 -> V_16 -> V_163 ;
V_156 = F_99 ( V_156 , V_22 -> V_16 -> V_156 ) ;
V_158 = F_99 ( V_158 , V_22 -> V_16 -> V_158 ) ;
}
V_19 -> V_163 = V_154 ;
V_160:
V_19 -> V_150 = V_150 ;
V_19 -> V_161 = V_152 | V_164 ;
V_19 -> V_158 = V_158 ;
F_100 ( V_19 , V_156 ) ;
V_19 -> V_162 &= ~ V_148 ;
if ( ( V_19 -> V_162 & V_149 ) &&
V_147 == ( V_148 | V_149 ) )
V_19 -> V_162 |= V_148 ;
F_101 ( V_19 ) ;
}
static void F_102 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
V_19 -> V_165 = V_15 -> V_165 ;
V_19 -> type = V_15 -> type ;
V_19 -> V_163 = V_15 -> V_163 ;
V_19 -> V_85 = V_15 -> V_85 ;
memcpy ( V_19 -> V_166 , V_15 -> V_166 ,
V_15 -> V_85 ) ;
}
static bool F_103 ( struct V_12 * V_13 ,
struct V_22 * V_22 ,
struct V_10 * V_11 )
{
if ( F_104 ( V_22 ) ) {
if ( F_20 ( V_11 ) == V_9 &&
V_13 -> V_167 != V_168 &&
V_13 -> V_167 != V_169 )
return false ;
return true ;
}
return false ;
}
static T_6 F_105 ( struct V_12 * * V_170 )
{
struct V_12 * V_13 = * V_170 ;
struct V_22 * V_22 ;
struct V_10 * V_11 ;
int (* F_106)( const struct V_12 * , struct V_10 * ,
struct V_22 * );
int V_171 = V_172 ;
V_13 = F_107 ( V_13 , V_173 ) ;
if ( F_5 ( ! V_13 ) )
return V_174 ;
* V_170 = V_13 ;
V_22 = F_108 ( V_13 -> V_16 ) ;
V_11 = V_22 -> V_11 ;
F_106 = F_109 ( V_11 -> F_106 ) ;
if ( F_106 ) {
V_171 = F_106 ( V_13 , V_11 , V_22 ) ;
if ( V_171 == V_174 ) {
F_110 ( V_13 ) ;
return V_171 ;
}
}
if ( F_111 ( F_112 ( V_13 ) -> V_175 ) )
return V_176 ;
if ( F_103 ( V_13 , V_22 , V_11 ) )
return V_177 ;
V_13 -> V_16 = V_11 -> V_16 ;
if ( F_20 ( V_11 ) == V_9 &&
V_11 -> V_16 -> V_162 & V_178 &&
V_13 -> V_167 == V_179 ) {
if ( F_5 ( F_113 ( V_13 ,
V_13 -> V_180 - F_114 ( V_13 ) ) ) ) {
F_115 ( V_13 ) ;
return V_174 ;
}
F_58 ( F_112 ( V_13 ) -> V_175 , V_11 -> V_16 -> V_86 ,
V_11 -> V_16 -> V_85 ) ;
}
return V_171 ;
}
static enum V_181 F_116 ( struct V_10 * V_11 )
{
switch ( F_20 ( V_11 ) ) {
case V_3 :
return V_182 ;
case V_4 :
return V_183 ;
case V_6 :
return V_184 ;
case V_5 :
case V_7 :
return V_185 ;
default:
return V_186 ;
}
}
static int F_117 ( struct V_10 * V_11 , struct V_22 * V_22 )
{
struct V_187 V_188 ;
int V_67 ;
V_188 . V_189 = F_116 ( V_11 ) ;
V_67 = F_118 ( V_22 -> V_16 , V_11 -> V_16 , V_22 ,
& V_188 ) ;
if ( V_67 )
return V_67 ;
F_119 ( V_190 , V_22 -> V_16 , V_191 , V_129 ) ;
return 0 ;
}
static void F_120 ( struct V_10 * V_11 , struct V_22 * V_22 )
{
F_121 ( V_22 -> V_16 , V_11 -> V_16 ) ;
V_22 -> V_16 -> V_82 &= ~ V_191 ;
F_119 ( V_190 , V_22 -> V_16 , V_191 , V_129 ) ;
}
static struct V_22 * F_122 ( struct V_10 * V_11 )
{
struct V_22 * V_22 = NULL ;
V_22 = F_81 ( sizeof( * V_22 ) , V_129 ) ;
if ( ! V_22 )
return NULL ;
if ( F_20 ( V_11 ) == V_7 ) {
F_89 ( V_22 ) = F_81 ( sizeof( struct V_192 ) ,
V_129 ) ;
if ( ! F_89 ( V_22 ) ) {
F_83 ( V_22 ) ;
return NULL ;
}
}
return V_22 ;
}
static void F_123 ( struct V_22 * V_22 )
{
struct V_10 * V_11 = F_124 ( V_22 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_83 ( F_89 ( V_22 ) ) ;
F_83 ( V_22 ) ;
}
static void F_125 ( struct V_10 * V_11 , struct V_193 * V_194 )
{
V_194 -> V_195 = F_20 ( V_11 ) ;
V_194 -> V_119 = V_11 -> V_52 . V_119 ;
V_194 -> V_196 = V_11 -> V_197 ;
}
static void F_126 ( struct V_22 * V_22 , struct V_198 * V_194 )
{
strcpy ( V_194 -> V_199 , V_22 -> V_16 -> V_59 ) ;
V_194 -> V_29 = V_22 -> V_29 ;
V_194 -> V_116 = F_127 ( V_22 ) ;
V_194 -> V_200 = V_22 -> V_200 ;
}
static void F_128 ( struct V_14 * V_16 ,
struct V_201 * V_194 )
{
F_129 () ;
F_130 ( V_16 , V_194 ) ;
F_43 () ;
}
static void F_131 ( struct V_70 * V_202 )
{
struct V_203 * V_204 =
F_39 ( V_202 , struct V_203 , V_71 . V_71 ) ;
F_128 ( V_204 -> V_16 , & V_204 -> V_205 ) ;
F_132 ( V_204 -> V_16 ) ;
F_83 ( V_204 ) ;
}
void F_133 ( struct V_22 * V_22 )
{
struct V_10 * V_11 = V_22 -> V_11 ;
struct V_203 * V_206 = F_81 ( sizeof( * V_206 ) , V_173 ) ;
if ( ! V_206 )
return;
F_134 ( V_22 -> V_16 ) ;
V_206 -> V_16 = V_22 -> V_16 ;
F_126 ( V_22 , & V_206 -> V_205 . V_22 ) ;
F_125 ( V_11 , & V_206 -> V_205 . V_207 ) ;
F_135 ( & V_206 -> V_71 , F_131 ) ;
F_41 ( V_22 -> V_11 -> V_73 , & V_206 -> V_71 , 0 ) ;
}
void F_136 ( struct V_22 * V_22 )
{
struct V_208 V_194 ;
V_194 . V_209 = V_22 -> V_29 == V_30 ||
V_22 -> V_29 == V_41 ;
V_194 . V_210 = F_137 ( V_22 ) ;
F_138 ( V_22 -> V_16 , & V_194 ) ;
}
int F_139 ( struct V_14 * V_19 , struct V_14 * V_15 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
const struct V_45 * V_46 = V_15 -> V_47 ;
struct V_22 * V_211 = NULL , * V_212 ;
struct V_92 V_93 ;
int V_213 ;
int V_26 = 0 , V_214 ;
if ( ! V_11 -> V_52 . V_53 &&
V_15 -> V_55 -> V_56 == NULL &&
V_46 -> V_57 == NULL ) {
F_140 ( V_19 , L_23 ,
V_15 -> V_59 ) ;
}
if ( F_141 ( V_15 ) ) {
F_60 ( V_19 ,
L_24 ) ;
return - V_215 ;
}
if ( V_19 == V_15 ) {
F_60 ( V_19 , L_25 ) ;
return - V_216 ;
}
if ( V_15 -> V_143 & V_217 ) {
F_54 ( V_19 , L_26 ,
V_15 -> V_59 ) ;
if ( F_142 ( V_19 ) ) {
F_60 ( V_19 , L_27 ,
V_15 -> V_59 , V_19 -> V_59 ) ;
return - V_216 ;
} else {
F_140 ( V_19 , L_28 ,
V_15 -> V_59 , V_15 -> V_59 ,
V_19 -> V_59 ) ;
}
} else {
F_54 ( V_19 , L_29 ,
V_15 -> V_59 ) ;
}
if ( V_15 -> V_82 & V_218 ) {
F_60 ( V_19 , L_30 ,
V_15 -> V_59 ) ;
return - V_216 ;
}
if ( ! F_19 ( V_11 ) ) {
if ( V_19 -> type != V_15 -> type ) {
F_54 ( V_19 , L_31 ,
V_19 -> type , V_15 -> type ) ;
V_26 = F_42 ( V_219 ,
V_19 ) ;
V_26 = F_143 ( V_26 ) ;
if ( V_26 ) {
F_60 ( V_19 , L_32 ) ;
return - V_215 ;
}
F_144 ( V_19 ) ;
F_145 ( V_19 ) ;
if ( V_15 -> type != V_220 )
F_102 ( V_19 , V_15 ) ;
else {
F_146 ( V_19 ) ;
V_19 -> V_162 &= ~ V_221 ;
}
F_42 ( V_222 ,
V_19 ) ;
}
} else if ( V_19 -> type != V_15 -> type ) {
F_60 ( V_19 , L_33 ,
V_15 -> V_59 , V_15 -> type , V_19 -> type ) ;
return - V_223 ;
}
if ( V_15 -> type == V_224 &&
F_20 ( V_11 ) != V_4 ) {
F_140 ( V_19 , L_34 ,
V_15 -> type ) ;
V_26 = - V_225 ;
goto V_226;
}
if ( ! V_46 -> V_227 ||
V_15 -> type == V_224 ) {
F_140 ( V_19 , L_35 ) ;
if ( F_20 ( V_11 ) == V_4 &&
V_11 -> V_52 . V_95 != V_96 ) {
if ( ! F_19 ( V_11 ) ) {
V_11 -> V_52 . V_95 = V_96 ;
F_140 ( V_19 , L_36 ) ;
} else {
F_60 ( V_19 , L_37 ) ;
V_26 = - V_225 ;
goto V_226;
}
}
}
F_42 ( V_228 , V_15 ) ;
if ( ! F_19 ( V_11 ) &&
V_11 -> V_16 -> V_87 == V_229 )
F_53 ( V_11 -> V_16 , V_15 ) ;
V_211 = F_122 ( V_11 ) ;
if ( ! V_211 ) {
V_26 = - V_130 ;
goto V_226;
}
V_211 -> V_11 = V_11 ;
V_211 -> V_16 = V_15 ;
V_211 -> V_230 = 0 ;
V_211 -> V_231 = V_15 -> V_232 ;
V_26 = F_147 ( V_15 , V_11 -> V_16 -> V_232 ) ;
if ( V_26 ) {
F_54 ( V_19 , L_38 , V_26 ) ;
goto V_233;
}
F_58 ( V_211 -> V_234 , V_15 -> V_86 ,
V_15 -> V_85 ) ;
if ( ! V_11 -> V_52 . V_95 ||
F_20 ( V_11 ) != V_4 ) {
memcpy ( V_93 . V_98 , V_19 -> V_86 , V_19 -> V_85 ) ;
V_93 . V_99 = V_15 -> type ;
V_26 = F_59 ( V_15 , (struct V_100 * ) & V_93 ) ;
if ( V_26 ) {
F_54 ( V_19 , L_39 , V_26 ) ;
goto V_235;
}
}
V_15 -> V_82 |= V_191 ;
V_26 = F_148 ( V_15 ) ;
if ( V_26 ) {
F_54 ( V_19 , L_40 , V_15 -> V_59 ) ;
goto V_236;
}
V_15 -> V_162 |= V_237 ;
F_149 ( V_211 -> V_16 , & V_211 -> V_238 ) ;
if ( F_16 ( V_11 ) ) {
V_26 = F_150 ( V_11 , V_211 ) ;
if ( V_26 )
goto V_239;
}
if ( ! F_33 ( V_11 ) ) {
if ( V_19 -> V_82 & V_83 ) {
V_26 = F_35 ( V_15 , 1 ) ;
if ( V_26 )
goto V_239;
}
if ( V_19 -> V_82 & V_84 ) {
V_26 = F_37 ( V_15 , 1 ) ;
if ( V_26 )
goto V_239;
}
F_49 ( V_19 ) ;
F_151 ( V_15 , V_19 ) ;
F_152 ( V_15 , V_19 ) ;
F_52 ( V_19 ) ;
}
if ( F_20 ( V_11 ) == V_7 ) {
T_4 V_77 [ V_78 ] = V_79 ;
F_153 ( V_15 , V_77 ) ;
}
V_26 = F_154 ( V_15 , V_19 ) ;
if ( V_26 ) {
F_60 ( V_19 , L_41 ,
V_15 -> V_59 ) ;
goto V_239;
}
V_212 = F_155 ( V_11 ) ;
V_211 -> V_113 = 0 ;
V_211 -> V_200 = 0 ;
if ( F_25 ( V_211 ) )
V_211 -> V_29 = V_42 ;
V_211 -> V_240 = V_118 -
( F_156 ( V_11 -> V_52 . V_241 ) + 1 ) ;
for ( V_214 = 0 ; V_214 < V_242 ; V_214 ++ )
V_211 -> V_243 [ V_214 ] = V_211 -> V_240 ;
if ( V_11 -> V_52 . V_119 && ! V_11 -> V_52 . V_53 ) {
V_213 = F_28 ( V_11 , V_15 , 1 ) ;
if ( ( V_213 == - 1 ) && ! V_11 -> V_52 . V_241 ) {
F_140 ( V_19 , L_42 ,
V_15 -> V_59 ) ;
} else if ( V_213 == - 1 ) {
F_140 ( V_19 , L_43 ,
V_15 -> V_59 ) ;
}
}
V_211 -> V_29 = V_244 ;
if ( V_11 -> V_52 . V_119 ) {
if ( F_28 ( V_11 , V_15 , 0 ) == V_54 ) {
if ( V_11 -> V_52 . V_112 ) {
F_72 ( V_211 ,
V_43 ,
V_120 ) ;
V_211 -> V_113 = V_11 -> V_52 . V_112 ;
} else {
F_72 ( V_211 ,
V_30 ,
V_120 ) ;
}
} else {
F_72 ( V_211 , V_42 ,
V_120 ) ;
}
} else if ( V_11 -> V_52 . V_241 ) {
F_72 ( V_211 ,
( F_22 ( V_15 ) ?
V_30 : V_42 ) ,
V_120 ) ;
} else {
F_72 ( V_211 , V_30 ,
V_120 ) ;
}
if ( V_211 -> V_29 != V_42 )
V_211 -> V_117 = V_118 ;
F_54 ( V_19 , L_44 ,
V_211 -> V_29 == V_42 ? L_45 :
( V_211 -> V_29 == V_30 ? L_46 : L_47 ) ) ;
if ( F_33 ( V_11 ) && V_11 -> V_52 . V_245 [ 0 ] ) {
if ( strcmp ( V_11 -> V_52 . V_245 , V_211 -> V_16 -> V_59 ) == 0 ) {
F_78 ( V_11 -> V_103 , V_211 ) ;
V_11 -> V_105 = true ;
}
}
switch ( F_20 ( V_11 ) ) {
case V_4 :
F_76 ( V_211 ,
V_120 ) ;
break;
case V_7 :
F_76 ( V_211 , V_120 ) ;
if ( ! V_212 ) {
F_89 ( V_211 ) -> V_246 = 1 ;
F_157 ( V_11 , 1000 / V_247 ) ;
} else {
F_89 ( V_211 ) -> V_246 =
F_89 ( V_212 ) -> V_246 + 1 ;
}
F_158 ( V_211 ) ;
break;
case V_8 :
case V_9 :
F_159 ( V_211 ) ;
F_76 ( V_211 , V_120 ) ;
break;
default:
F_54 ( V_19 , L_48 ) ;
F_159 ( V_211 ) ;
if ( ! F_160 ( V_11 -> V_69 ) &&
V_211 -> V_29 == V_30 )
F_78 ( V_11 -> V_69 , V_211 ) ;
break;
}
#ifdef F_161
V_15 -> V_141 = V_11 -> V_16 -> V_141 ;
if ( V_15 -> V_141 ) {
if ( F_80 ( V_211 ) ) {
F_71 ( V_19 , L_49 ) ;
V_26 = - V_215 ;
goto V_248;
}
}
#endif
if ( ! ( V_19 -> V_143 & V_249 ) )
F_162 ( V_15 ) ;
V_26 = F_163 ( V_15 , F_105 ,
V_211 ) ;
if ( V_26 ) {
F_54 ( V_19 , L_50 , V_26 ) ;
goto V_248;
}
V_26 = F_117 ( V_11 , V_211 ) ;
if ( V_26 ) {
F_54 ( V_19 , L_51 , V_26 ) ;
goto V_250;
}
V_26 = F_164 ( V_211 ) ;
if ( V_26 ) {
F_54 ( V_19 , L_52 , V_26 ) ;
goto V_251;
}
V_11 -> V_197 ++ ;
F_98 ( V_11 ) ;
F_18 ( V_11 ) ;
if ( F_33 ( V_11 ) ) {
F_165 () ;
F_79 ( V_11 ) ;
F_166 () ;
}
if ( F_167 ( V_11 ) )
F_168 ( V_11 , NULL ) ;
F_71 ( V_19 , L_53 ,
V_15 -> V_59 ,
F_137 ( V_211 ) ? L_54 : L_55 ,
V_211 -> V_29 != V_42 ? L_56 : L_57 ) ;
F_133 ( V_211 ) ;
return 0 ;
V_251:
F_120 ( V_11 , V_211 ) ;
V_250:
F_169 ( V_15 ) ;
V_248:
if ( ! F_33 ( V_11 ) )
F_44 ( V_19 , V_15 ) ;
F_170 ( V_15 , V_19 ) ;
if ( F_160 ( V_11 -> V_103 ) == V_211 )
F_171 ( V_11 -> V_103 , NULL ) ;
if ( F_160 ( V_11 -> V_69 ) == V_211 ) {
F_165 () ;
F_69 ( V_11 , NULL ) ;
F_79 ( V_11 ) ;
F_166 () ;
}
F_172 () ;
F_84 ( V_211 ) ;
V_239:
V_15 -> V_162 &= ~ V_237 ;
F_173 ( V_15 ) ;
V_236:
V_15 -> V_82 &= ~ V_191 ;
if ( ! V_11 -> V_52 . V_95 ||
F_20 ( V_11 ) != V_4 ) {
F_58 ( V_93 . V_98 , V_211 -> V_234 ,
V_211 -> V_16 -> V_85 ) ;
V_93 . V_99 = V_15 -> type ;
F_59 ( V_15 , (struct V_100 * ) & V_93 ) ;
}
V_235:
F_147 ( V_15 , V_211 -> V_231 ) ;
V_233:
F_123 ( V_211 ) ;
V_226:
if ( ! F_19 ( V_11 ) ) {
if ( F_174 ( V_19 -> V_86 ,
V_15 -> V_86 ) )
F_175 ( V_19 ) ;
if ( V_19 -> type != V_220 ) {
F_173 ( V_19 ) ;
F_146 ( V_19 ) ;
V_19 -> V_82 |= V_252 ;
V_19 -> V_162 &= ~ V_221 ;
}
}
return V_26 ;
}
static int F_176 ( struct V_14 * V_19 ,
struct V_14 * V_15 ,
bool V_253 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_254 ;
struct V_92 V_93 ;
int V_255 = V_19 -> V_82 ;
T_5 V_256 = V_19 -> V_143 ;
if ( ! ( V_15 -> V_82 & V_191 ) ||
! F_177 ( V_15 , V_19 ) ) {
F_54 ( V_19 , L_58 ,
V_15 -> V_59 ) ;
return - V_223 ;
}
F_165 () ;
V_22 = F_8 ( V_11 , V_15 ) ;
if ( ! V_22 ) {
F_71 ( V_19 , L_59 ,
V_15 -> V_59 ) ;
F_166 () ;
return - V_223 ;
}
F_76 ( V_22 , V_120 ) ;
F_178 ( V_22 ) ;
F_179 ( V_11 -> V_16 , & V_11 -> V_257 ) ;
F_120 ( V_11 , V_22 ) ;
F_169 ( V_15 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_180 ( V_22 ) ;
if ( F_167 ( V_11 ) )
F_168 ( V_11 , V_22 ) ;
F_71 ( V_19 , L_60 ,
F_137 ( V_22 ) ? L_61 : L_62 ,
V_15 -> V_59 ) ;
V_254 = F_160 ( V_11 -> V_69 ) ;
F_171 ( V_11 -> V_258 , NULL ) ;
if ( ! V_253 && ( ! V_11 -> V_52 . V_95 ||
F_20 ( V_11 ) != V_4 ) ) {
if ( F_174 ( V_19 -> V_86 , V_22 -> V_234 ) &&
F_19 ( V_11 ) )
F_140 ( V_19 , L_63 ,
V_15 -> V_59 , V_22 -> V_234 ,
V_19 -> V_59 , V_15 -> V_59 ) ;
}
if ( F_34 ( V_11 -> V_103 ) == V_22 )
F_171 ( V_11 -> V_103 , NULL ) ;
if ( V_254 == V_22 )
F_69 ( V_11 , NULL ) ;
if ( F_16 ( V_11 ) ) {
F_181 ( V_11 , V_22 ) ;
}
if ( V_253 ) {
F_171 ( V_11 -> V_69 , NULL ) ;
} else if ( V_254 == V_22 ) {
F_79 ( V_11 ) ;
}
if ( ! F_19 ( V_11 ) ) {
F_18 ( V_11 ) ;
F_175 ( V_19 ) ;
}
F_166 () ;
F_172 () ;
V_11 -> V_197 -- ;
if ( ! F_19 ( V_11 ) ) {
F_42 ( V_89 , V_11 -> V_16 ) ;
F_42 ( V_259 , V_11 -> V_16 ) ;
}
F_98 ( V_11 ) ;
if ( ! ( V_19 -> V_143 & V_217 ) &&
( V_256 & V_217 ) )
F_71 ( V_19 , L_64 ,
V_15 -> V_59 , V_19 -> V_59 ) ;
F_170 ( V_15 , V_19 ) ;
if ( ! F_33 ( V_11 ) ) {
if ( V_255 & V_83 )
F_35 ( V_15 , - 1 ) ;
if ( V_255 & V_84 )
F_37 ( V_15 , - 1 ) ;
F_44 ( V_19 , V_15 ) ;
}
F_84 ( V_22 ) ;
F_173 ( V_15 ) ;
if ( V_11 -> V_52 . V_95 != V_96 ||
F_20 ( V_11 ) != V_4 ) {
F_58 ( V_93 . V_98 , V_22 -> V_234 ,
V_22 -> V_16 -> V_85 ) ;
V_93 . V_99 = V_15 -> type ;
F_59 ( V_15 , (struct V_100 * ) & V_93 ) ;
}
F_147 ( V_15 , V_22 -> V_231 ) ;
V_15 -> V_162 &= ~ V_237 ;
F_123 ( V_22 ) ;
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
int V_171 ;
V_171 = F_182 ( V_19 , V_15 ) ;
if ( V_171 == 0 && ! F_19 ( V_11 ) ) {
V_19 -> V_162 |= V_260 ;
F_71 ( V_19 , L_65 ,
V_19 -> V_59 ) ;
F_184 ( V_11 ) ;
F_185 ( V_19 ) ;
}
return V_171 ;
}
static void F_186 ( struct V_14 * V_19 , struct V_193 * V_194 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_125 ( V_11 , V_194 ) ;
}
static int F_187 ( struct V_14 * V_19 , struct V_198 * V_194 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
int V_214 = 0 , V_26 = - V_261 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
if ( V_214 ++ == ( int ) V_194 -> V_262 ) {
V_26 = 0 ;
F_126 ( V_22 , V_194 ) ;
break;
}
}
return V_26 ;
}
static int F_188 ( struct V_10 * V_11 )
{
int V_263 , V_264 = 0 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
bool V_265 ;
V_265 = ! F_66 ( V_11 -> V_69 ) ;
F_88 (bond, slave, iter) {
V_22 -> V_266 = V_244 ;
V_263 = F_28 ( V_11 , V_22 -> V_16 , 0 ) ;
switch ( V_22 -> V_29 ) {
case V_30 :
if ( V_263 )
continue;
F_189 ( V_22 , V_41 ) ;
V_22 -> V_113 = V_11 -> V_52 . V_267 ;
if ( V_22 -> V_113 ) {
F_71 ( V_11 -> V_16 , L_66 ,
( F_20 ( V_11 ) ==
V_4 ) ?
( F_137 ( V_22 ) ?
L_67 : L_68 ) : L_69 ,
V_22 -> V_16 -> V_59 ,
V_11 -> V_52 . V_267 * V_11 -> V_52 . V_119 ) ;
}
case V_41 :
if ( V_263 ) {
F_189 ( V_22 , V_30 ) ;
V_22 -> V_117 = V_118 ;
F_71 ( V_11 -> V_16 , L_70 ,
( V_11 -> V_52 . V_267 - V_22 -> V_113 ) *
V_11 -> V_52 . V_119 ,
V_22 -> V_16 -> V_59 ) ;
V_264 ++ ;
continue;
}
if ( V_22 -> V_113 <= 0 ) {
V_22 -> V_266 = V_42 ;
V_264 ++ ;
continue;
}
V_22 -> V_113 -- ;
break;
case V_42 :
if ( ! V_263 )
continue;
F_189 ( V_22 , V_43 ) ;
V_22 -> V_113 = V_11 -> V_52 . V_112 ;
if ( V_22 -> V_113 ) {
F_71 ( V_11 -> V_16 , L_71 ,
V_22 -> V_16 -> V_59 ,
V_265 ? 0 :
V_11 -> V_52 . V_112 *
V_11 -> V_52 . V_119 ) ;
}
case V_43 :
if ( ! V_263 ) {
F_189 ( V_22 , V_42 ) ;
F_71 ( V_11 -> V_16 , L_72 ,
( V_11 -> V_52 . V_112 - V_22 -> V_113 ) *
V_11 -> V_52 . V_119 ,
V_22 -> V_16 -> V_59 ) ;
V_264 ++ ;
continue;
}
if ( V_265 )
V_22 -> V_113 = 0 ;
if ( V_22 -> V_113 <= 0 ) {
V_22 -> V_266 = V_30 ;
V_264 ++ ;
V_265 = false ;
continue;
}
V_22 -> V_113 -- ;
break;
}
}
return V_264 ;
}
static void F_190 ( struct V_10 * V_11 )
{
struct V_24 * V_25 ;
struct V_22 * V_22 , * V_245 ;
F_12 (bond, slave, iter) {
switch ( V_22 -> V_266 ) {
case V_244 :
continue;
case V_30 :
if ( F_25 ( V_22 ) ) {
V_22 -> V_29 = V_42 ;
F_140 ( V_11 -> V_16 ,
L_73 ,
V_22 -> V_16 -> V_59 ) ;
continue;
}
F_72 ( V_22 , V_30 ,
V_120 ) ;
V_22 -> V_117 = V_118 ;
V_245 = F_34 ( V_11 -> V_103 ) ;
if ( F_20 ( V_11 ) == V_7 ) {
F_191 ( V_22 ) ;
} else if ( F_20 ( V_11 ) != V_4 ) {
F_159 ( V_22 ) ;
} else if ( V_22 != V_245 ) {
F_191 ( V_22 ) ;
}
F_71 ( V_11 -> V_16 , L_74 ,
V_22 -> V_16 -> V_59 ,
V_22 -> V_33 == V_34 ? 0 : V_22 -> V_33 ,
V_22 -> V_35 ? L_75 : L_76 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_73 ( V_22 , V_30 ) ;
if ( F_16 ( V_11 ) )
F_74 ( V_11 , V_22 ,
V_30 ) ;
if ( F_20 ( V_11 ) == V_5 )
F_168 ( V_11 , NULL ) ;
if ( ! V_11 -> V_69 || V_22 == V_245 )
goto V_268;
continue;
case V_42 :
if ( V_22 -> V_200 < V_269 )
V_22 -> V_200 ++ ;
F_72 ( V_22 , V_42 ,
V_120 ) ;
if ( F_20 ( V_11 ) == V_4 ||
F_20 ( V_11 ) == V_7 )
F_76 ( V_22 ,
V_120 ) ;
F_71 ( V_11 -> V_16 , L_77 ,
V_22 -> V_16 -> V_59 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_73 ( V_22 ,
V_42 ) ;
if ( F_16 ( V_11 ) )
F_74 ( V_11 , V_22 ,
V_42 ) ;
if ( F_20 ( V_11 ) == V_5 )
F_168 ( V_11 , NULL ) ;
if ( V_22 == F_160 ( V_11 -> V_69 ) )
goto V_268;
continue;
default:
F_60 ( V_11 -> V_16 , L_78 ,
V_22 -> V_266 , V_22 -> V_16 -> V_59 ) ;
V_22 -> V_266 = V_244 ;
continue;
}
V_268:
F_165 () ;
F_79 ( V_11 ) ;
F_166 () ;
}
F_18 ( V_11 ) ;
}
static void F_192 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_39 ( V_71 , struct V_10 ,
V_270 . V_71 ) ;
bool V_121 = false ;
unsigned long V_113 ;
struct V_22 * V_22 ;
struct V_24 * V_25 ;
V_113 = F_156 ( V_11 -> V_52 . V_119 ) ;
if ( ! F_19 ( V_11 ) )
goto V_271;
F_65 () ;
V_121 = F_64 ( V_11 ) ;
if ( F_188 ( V_11 ) ) {
F_67 () ;
if ( ! F_40 () ) {
V_113 = 1 ;
V_121 = false ;
goto V_271;
}
F_12 (bond, slave, iter) {
F_193 ( V_22 , V_272 ) ;
}
F_190 ( V_11 ) ;
F_43 () ;
} else
F_67 () ;
V_271:
if ( V_11 -> V_52 . V_119 )
F_41 ( V_11 -> V_73 , & V_11 -> V_270 , V_113 ) ;
if ( V_121 ) {
if ( ! F_40 () )
return;
F_42 ( V_124 , V_11 -> V_16 ) ;
F_43 () ;
}
}
static int F_194 ( struct V_14 * V_273 , void * V_180 )
{
T_7 V_274 = * ( ( T_7 * ) V_180 ) ;
return V_274 == F_195 ( V_273 , 0 , V_274 ) ;
}
static bool F_196 ( struct V_10 * V_11 , T_7 V_274 )
{
bool V_171 = false ;
if ( V_274 == F_195 ( V_11 -> V_16 , 0 , V_274 ) )
return true ;
F_65 () ;
if ( F_197 ( V_11 -> V_16 , F_194 , & V_274 ) )
V_171 = true ;
F_67 () ;
return V_171 ;
}
static void F_198 ( struct V_14 * V_15 , int V_275 ,
T_7 V_276 , T_7 V_277 ,
struct V_278 * V_279 )
{
struct V_12 * V_13 ;
struct V_278 * V_280 = V_279 ;
F_54 ( V_15 , L_79 ,
V_275 , V_15 -> V_59 , & V_276 , & V_277 ) ;
V_13 = F_199 ( V_275 , V_281 , V_276 , V_15 , V_277 ,
NULL , V_15 -> V_86 , NULL ) ;
if ( ! V_13 ) {
F_200 ( L_80 ) ;
return;
}
if ( ! V_279 || V_279 -> V_282 == V_283 )
goto V_284;
V_279 ++ ;
while ( V_279 -> V_282 != V_283 ) {
if ( ! V_279 -> V_285 ) {
V_279 ++ ;
continue;
}
F_54 ( V_15 , L_81 ,
F_201 ( V_280 -> V_282 ) , V_279 -> V_285 ) ;
V_13 = F_202 ( V_13 , V_279 -> V_282 ,
V_279 -> V_285 ) ;
if ( ! V_13 ) {
F_200 ( L_82 ) ;
return;
}
V_279 ++ ;
}
if ( V_280 -> V_285 ) {
F_54 ( V_15 , L_83 ,
F_201 ( V_280 -> V_282 ) , V_280 -> V_285 ) ;
F_203 ( V_13 , V_280 -> V_282 ,
V_280 -> V_285 ) ;
}
V_284:
F_204 ( V_13 ) ;
}
struct V_278 * F_205 ( struct V_14 * V_286 ,
struct V_14 * V_287 ,
int V_288 )
{
struct V_278 * V_279 ;
struct V_14 * V_273 ;
struct V_24 * V_25 ;
if ( V_286 == V_287 ) {
V_279 = F_81 ( sizeof( * V_279 ) * ( V_288 + 1 ) , V_173 ) ;
if ( ! V_279 )
return F_206 ( - V_130 ) ;
V_279 [ V_288 ] . V_282 = V_283 ;
return V_279 ;
}
F_207 (start_dev, upper, iter) {
V_279 = F_205 ( V_273 , V_287 , V_288 + 1 ) ;
if ( F_208 ( V_279 ) ) {
if ( F_209 ( V_279 ) )
return V_279 ;
continue;
}
if ( F_210 ( V_273 ) ) {
V_279 [ V_288 ] . V_282 = F_211 ( V_273 ) ;
V_279 [ V_288 ] . V_285 = F_212 ( V_273 ) ;
}
return V_279 ;
}
return NULL ;
}
static void F_213 ( struct V_10 * V_11 , struct V_22 * V_22 )
{
struct V_289 * V_290 ;
struct V_278 * V_279 ;
T_7 * V_291 = V_11 -> V_52 . V_292 , V_293 ;
int V_214 ;
for ( V_214 = 0 ; V_214 < V_242 && V_291 [ V_214 ] ; V_214 ++ ) {
F_54 ( V_11 -> V_16 , L_84 , & V_291 [ V_214 ] ) ;
V_279 = NULL ;
V_290 = F_214 ( F_215 ( V_11 -> V_16 ) , V_291 [ V_214 ] , 0 ,
V_294 , 0 ) ;
if ( F_209 ( V_290 ) ) {
if ( V_11 -> V_52 . V_295 )
F_216 ( L_85 ,
V_11 -> V_16 -> V_59 ,
& V_291 [ V_214 ] ) ;
F_198 ( V_22 -> V_16 , V_296 , V_291 [ V_214 ] ,
0 , V_279 ) ;
continue;
}
if ( V_290 -> V_297 . V_16 == V_11 -> V_16 )
goto V_298;
F_65 () ;
V_279 = F_205 ( V_11 -> V_16 , V_290 -> V_297 . V_16 , 0 ) ;
F_67 () ;
if ( ! F_208 ( V_279 ) )
goto V_298;
F_54 ( V_11 -> V_16 , L_86 ,
& V_291 [ V_214 ] , V_290 -> V_297 . V_16 ? V_290 -> V_297 . V_16 -> V_59 : L_18 ) ;
F_217 ( V_290 ) ;
continue;
V_298:
V_293 = F_195 ( V_290 -> V_297 . V_16 , V_291 [ V_214 ] , 0 ) ;
F_217 ( V_290 ) ;
F_198 ( V_22 -> V_16 , V_296 , V_291 [ V_214 ] ,
V_293 , V_279 ) ;
F_83 ( V_279 ) ;
}
}
static void F_218 ( struct V_10 * V_11 , struct V_22 * V_22 , T_7 V_299 , T_7 V_300 )
{
int V_214 ;
if ( ! V_299 || ! F_196 ( V_11 , V_300 ) ) {
F_54 ( V_11 -> V_16 , L_87 ,
& V_299 , & V_300 ) ;
return;
}
V_214 = F_219 ( V_11 -> V_52 . V_292 , V_299 ) ;
if ( V_214 == - 1 ) {
F_54 ( V_11 -> V_16 , L_88 ,
& V_299 ) ;
return;
}
V_22 -> V_240 = V_118 ;
V_22 -> V_243 [ V_214 ] = V_118 ;
}
int F_220 ( const struct V_12 * V_13 , struct V_10 * V_11 ,
struct V_22 * V_22 )
{
struct V_301 * V_302 = (struct V_301 * ) V_13 -> V_180 ;
struct V_22 * V_69 , * V_303 ;
unsigned char * V_304 ;
T_7 V_299 , V_300 ;
int V_305 , V_306 = V_13 -> V_307 == F_221 ( V_281 ) ;
if ( ! F_222 ( V_11 , V_22 ) ) {
if ( ( F_223 ( V_11 ) && V_306 ) ||
! F_223 ( V_11 ) )
V_22 -> V_240 = V_118 ;
return V_172 ;
} else if ( ! V_306 ) {
return V_172 ;
}
V_305 = F_224 ( V_11 -> V_16 ) ;
F_54 ( V_11 -> V_16 , L_89 ,
V_13 -> V_16 -> V_59 ) ;
if ( V_305 > F_225 ( V_13 ) ) {
V_302 = F_226 ( V_305 , V_173 ) ;
if ( ! V_302 )
goto V_308;
if ( F_227 ( V_13 , 0 , V_302 , V_305 ) < 0 )
goto V_308;
}
if ( V_302 -> V_309 != V_11 -> V_16 -> V_85 ||
V_13 -> V_167 == V_310 ||
V_13 -> V_167 == V_311 ||
V_302 -> V_312 != F_228 ( V_220 ) ||
V_302 -> V_313 != F_228 ( V_314 ) ||
V_302 -> V_315 != 4 )
goto V_308;
V_304 = ( unsigned char * ) ( V_302 + 1 ) ;
V_304 += V_11 -> V_16 -> V_85 ;
memcpy ( & V_299 , V_304 , 4 ) ;
V_304 += 4 + V_11 -> V_16 -> V_85 ;
memcpy ( & V_300 , V_304 , 4 ) ;
F_54 ( V_11 -> V_16 , L_90 ,
V_22 -> V_16 -> V_59 , F_127 ( V_22 ) ,
V_11 -> V_52 . V_295 , F_222 ( V_11 , V_22 ) ,
& V_299 , & V_300 ) ;
V_69 = F_66 ( V_11 -> V_69 ) ;
V_303 = F_66 ( V_11 -> V_258 ) ;
if ( F_137 ( V_22 ) )
F_218 ( V_11 , V_22 , V_299 , V_300 ) ;
else if ( V_69 &&
F_229 ( F_230 ( V_11 , V_69 ) ,
V_69 -> V_117 ) )
F_218 ( V_11 , V_22 , V_300 , V_299 ) ;
else if ( V_303 && ( V_302 -> V_316 == F_228 ( V_317 ) ) &&
F_231 ( V_11 ,
F_232 ( V_303 -> V_16 ) , 1 ) )
F_218 ( V_11 , V_22 , V_299 , V_300 ) ;
V_308:
if ( V_302 != (struct V_301 * ) V_13 -> V_180 )
F_83 ( V_302 ) ;
return V_172 ;
}
static bool F_231 ( struct V_10 * V_11 , unsigned long V_318 ,
int V_319 )
{
int V_320 = F_156 ( V_11 -> V_52 . V_241 ) ;
return F_233 ( V_118 ,
V_318 - V_320 ,
V_318 + V_319 * V_320 + V_320 / 2 ) ;
}
static void F_234 ( struct V_10 * V_11 )
{
struct V_22 * V_22 , * V_254 ;
struct V_24 * V_25 ;
int V_268 = 0 , V_321 = 0 ;
if ( ! F_19 ( V_11 ) )
goto V_271;
F_65 () ;
V_254 = F_66 ( V_11 -> V_69 ) ;
F_88 (bond, slave, iter) {
unsigned long V_322 = F_232 ( V_22 -> V_16 ) ;
V_22 -> V_266 = V_244 ;
if ( V_22 -> V_29 != V_30 ) {
if ( F_231 ( V_11 , V_322 , 1 ) &&
F_231 ( V_11 , V_22 -> V_240 , 1 ) ) {
V_22 -> V_266 = V_30 ;
V_321 = 1 ;
if ( ! V_254 ) {
F_71 ( V_11 -> V_16 , L_91 ,
V_22 -> V_16 -> V_59 ) ;
V_268 = 1 ;
} else {
F_71 ( V_11 -> V_16 , L_92 ,
V_22 -> V_16 -> V_59 ) ;
}
}
} else {
if ( ! F_231 ( V_11 , V_322 , 2 ) ||
! F_231 ( V_11 , V_22 -> V_240 , 2 ) ) {
V_22 -> V_266 = V_42 ;
V_321 = 1 ;
if ( V_22 -> V_200 < V_269 )
V_22 -> V_200 ++ ;
F_71 ( V_11 -> V_16 , L_93 ,
V_22 -> V_16 -> V_59 ) ;
if ( V_22 == V_254 )
V_268 = 1 ;
}
}
if ( F_63 ( V_22 ) )
F_213 ( V_11 , V_22 ) ;
}
F_67 () ;
if ( V_268 || V_321 ) {
if ( ! F_40 () )
goto V_271;
F_12 (bond, slave, iter) {
if ( V_22 -> V_266 != V_244 )
V_22 -> V_29 = V_22 -> V_266 ;
}
if ( V_321 ) {
F_235 ( V_11 ) ;
if ( F_20 ( V_11 ) == V_5 )
F_168 ( V_11 , NULL ) ;
}
if ( V_268 ) {
F_165 () ;
F_79 ( V_11 ) ;
F_166 () ;
}
F_43 () ;
}
V_271:
if ( V_11 -> V_52 . V_241 )
F_41 ( V_11 -> V_73 , & V_11 -> V_323 ,
F_156 ( V_11 -> V_52 . V_241 ) ) ;
}
static int F_236 ( struct V_10 * V_11 )
{
unsigned long V_322 , V_240 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_264 = 0 ;
F_88 (bond, slave, iter) {
V_22 -> V_266 = V_244 ;
V_240 = F_230 ( V_11 , V_22 ) ;
if ( V_22 -> V_29 != V_30 ) {
if ( F_231 ( V_11 , V_240 , 1 ) ) {
V_22 -> V_266 = V_30 ;
V_264 ++ ;
}
continue;
}
if ( F_231 ( V_11 , V_22 -> V_117 , 2 ) )
continue;
if ( ! F_137 ( V_22 ) &&
! F_160 ( V_11 -> V_258 ) &&
! F_231 ( V_11 , V_240 , 3 ) ) {
V_22 -> V_266 = V_42 ;
V_264 ++ ;
}
V_322 = F_232 ( V_22 -> V_16 ) ;
if ( F_137 ( V_22 ) &&
( ! F_231 ( V_11 , V_322 , 2 ) ||
! F_231 ( V_11 , V_240 , 2 ) ) ) {
V_22 -> V_266 = V_42 ;
V_264 ++ ;
}
}
return V_264 ;
}
static void F_237 ( struct V_10 * V_11 )
{
unsigned long V_322 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
switch ( V_22 -> V_266 ) {
case V_244 :
continue;
case V_30 :
V_322 = F_232 ( V_22 -> V_16 ) ;
if ( F_34 ( V_11 -> V_69 ) != V_22 ||
( ! F_34 ( V_11 -> V_69 ) &&
F_231 ( V_11 , V_322 , 1 ) ) ) {
struct V_22 * V_258 ;
V_258 = F_34 ( V_11 -> V_258 ) ;
F_72 ( V_22 , V_30 ,
V_120 ) ;
if ( V_258 ) {
F_76 (
V_258 ,
V_120 ) ;
F_171 ( V_11 -> V_258 , NULL ) ;
}
F_71 ( V_11 -> V_16 , L_91 ,
V_22 -> V_16 -> V_59 ) ;
if ( ! F_34 ( V_11 -> V_69 ) ||
V_22 == F_34 ( V_11 -> V_103 ) )
goto V_268;
}
continue;
case V_42 :
if ( V_22 -> V_200 < V_269 )
V_22 -> V_200 ++ ;
F_72 ( V_22 , V_42 ,
V_120 ) ;
F_76 ( V_22 ,
V_120 ) ;
F_71 ( V_11 -> V_16 , L_77 ,
V_22 -> V_16 -> V_59 ) ;
if ( V_22 == F_34 ( V_11 -> V_69 ) ) {
F_171 ( V_11 -> V_258 , NULL ) ;
goto V_268;
}
continue;
default:
F_60 ( V_11 -> V_16 , L_94 ,
V_22 -> V_266 , V_22 -> V_16 -> V_59 ) ;
continue;
}
V_268:
F_165 () ;
F_79 ( V_11 ) ;
F_166 () ;
}
F_18 ( V_11 ) ;
}
static bool F_238 ( struct V_10 * V_11 )
{
struct V_22 * V_22 , * V_324 = NULL , * V_211 = NULL ,
* V_303 = F_66 ( V_11 -> V_258 ) ,
* V_69 = F_66 ( V_11 -> V_69 ) ;
struct V_24 * V_25 ;
bool V_298 = false ;
bool V_325 = V_272 ;
if ( V_303 && V_69 )
F_71 ( V_11 -> V_16 , L_95 ,
V_303 -> V_16 -> V_59 ,
V_69 -> V_16 -> V_59 ) ;
if ( V_69 ) {
F_213 ( V_11 , V_69 ) ;
return V_325 ;
}
if ( ! V_303 ) {
V_303 = F_239 ( V_11 ) ;
if ( ! V_303 )
return V_325 ;
}
F_76 ( V_303 , V_272 ) ;
F_88 (bond, slave, iter) {
if ( ! V_298 && ! V_324 && F_63 ( V_22 ) )
V_324 = V_22 ;
if ( V_298 && ! V_211 && F_63 ( V_22 ) )
V_211 = V_22 ;
if ( ! F_63 ( V_22 ) && V_22 -> V_29 == V_30 ) {
F_72 ( V_22 , V_42 ,
V_272 ) ;
if ( V_22 -> V_200 < V_269 )
V_22 -> V_200 ++ ;
F_76 ( V_22 ,
V_272 ) ;
F_71 ( V_11 -> V_16 , L_96 ,
V_22 -> V_16 -> V_59 ) ;
}
if ( V_22 == V_303 )
V_298 = true ;
}
if ( ! V_211 && V_324 )
V_211 = V_324 ;
if ( ! V_211 )
goto V_326;
F_72 ( V_211 , V_43 ,
V_272 ) ;
F_77 ( V_211 , V_272 ) ;
F_213 ( V_11 , V_211 ) ;
V_211 -> V_117 = V_118 ;
F_78 ( V_11 -> V_258 , V_211 ) ;
V_326:
F_88 (bond, slave, iter) {
if ( V_22 -> V_327 || V_22 -> V_328 ) {
V_325 = V_120 ;
break;
}
}
return V_325 ;
}
static void F_240 ( struct V_10 * V_11 )
{
bool V_121 = false ;
bool V_325 = false ;
int V_320 ;
V_320 = F_156 ( V_11 -> V_52 . V_241 ) ;
if ( ! F_19 ( V_11 ) )
goto V_271;
F_65 () ;
V_121 = F_64 ( V_11 ) ;
if ( F_236 ( V_11 ) ) {
F_67 () ;
if ( ! F_40 () ) {
V_320 = 1 ;
V_121 = false ;
goto V_271;
}
F_237 ( V_11 ) ;
F_43 () ;
F_65 () ;
}
V_325 = F_238 ( V_11 ) ;
F_67 () ;
V_271:
if ( V_11 -> V_52 . V_241 )
F_41 ( V_11 -> V_73 , & V_11 -> V_323 , V_320 ) ;
if ( V_121 || V_325 ) {
if ( ! F_40 () )
return;
if ( V_121 )
F_42 ( V_124 ,
V_11 -> V_16 ) ;
if ( V_325 ) {
F_241 ( V_11 ) ;
F_242 ( V_11 ) ;
}
F_43 () ;
}
}
static void F_243 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_39 ( V_71 , struct V_10 ,
V_323 . V_71 ) ;
if ( F_20 ( V_11 ) == V_4 )
F_240 ( V_11 ) ;
else
F_234 ( V_11 ) ;
}
static int F_244 ( struct V_10 * V_11 )
{
F_184 ( V_11 ) ;
F_245 ( V_11 ) ;
F_246 ( V_11 ) ;
return V_329 ;
}
static int F_247 ( unsigned long V_330 ,
struct V_14 * V_19 )
{
struct V_10 * V_331 = F_11 ( V_19 ) ;
switch ( V_330 ) {
case V_332 :
return F_244 ( V_331 ) ;
case V_333 :
F_184 ( V_331 ) ;
break;
case V_334 :
F_245 ( V_331 ) ;
break;
case V_124 :
if ( V_331 -> V_114 )
V_331 -> V_114 -- ;
break;
default:
break;
}
return V_329 ;
}
static int F_248 ( unsigned long V_330 ,
struct V_14 * V_15 )
{
struct V_22 * V_22 = F_249 ( V_15 ) , * V_245 ;
struct V_10 * V_11 ;
struct V_14 * V_19 ;
if ( ! V_22 )
return V_329 ;
V_19 = V_22 -> V_11 -> V_16 ;
V_11 = V_22 -> V_11 ;
V_245 = F_34 ( V_11 -> V_103 ) ;
switch ( V_330 ) {
case V_333 :
if ( V_19 -> type != V_220 )
F_183 ( V_19 , V_15 ) ;
else
F_182 ( V_19 , V_15 ) ;
break;
case V_335 :
case V_336 :
F_25 ( V_22 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_250 ( V_22 ) ;
case V_337 :
if ( F_167 ( V_11 ) )
F_168 ( V_11 , NULL ) ;
break;
case V_338 :
break;
case V_332 :
if ( ! F_33 ( V_11 ) ||
! V_11 -> V_52 . V_245 [ 0 ] )
break;
if ( V_22 == V_245 ) {
F_171 ( V_11 -> V_103 , NULL ) ;
} else if ( ! strcmp ( V_15 -> V_59 , V_11 -> V_52 . V_245 ) ) {
F_78 ( V_11 -> V_103 , V_22 ) ;
} else {
break;
}
F_71 ( V_11 -> V_16 , L_97 ,
V_245 ? V_15 -> V_59 : L_98 ) ;
F_165 () ;
F_79 ( V_11 ) ;
F_166 () ;
break;
case V_339 :
F_98 ( V_11 ) ;
break;
case V_74 :
F_42 ( V_330 , V_22 -> V_11 -> V_16 ) ;
break;
default:
break;
}
return V_329 ;
}
static int F_251 ( struct V_340 * V_341 ,
unsigned long V_330 , void * V_342 )
{
struct V_14 * V_343 = F_252 ( V_342 ) ;
F_54 ( V_343 , L_99 , V_330 ) ;
if ( ! ( V_343 -> V_162 & V_237 ) )
return V_329 ;
if ( V_343 -> V_82 & V_252 ) {
F_54 ( V_343 , L_100 ) ;
return F_247 ( V_330 , V_343 ) ;
}
if ( V_343 -> V_82 & V_191 ) {
F_54 ( V_343 , L_101 ) ;
return F_248 ( V_330 , V_343 ) ;
}
return V_329 ;
}
static inline T_8 F_253 ( struct V_12 * V_13 )
{
struct V_344 * V_345 , V_346 ;
V_345 = F_254 ( V_13 , 0 , sizeof( V_346 ) , & V_346 ) ;
if ( V_345 )
return V_345 -> V_175 [ 5 ] ^ V_345 -> V_347 [ 5 ] ^ V_345 -> V_348 ;
return 0 ;
}
static bool F_255 ( struct V_10 * V_11 , struct V_12 * V_13 ,
struct V_349 * V_350 )
{
const struct V_351 * V_352 ;
const struct V_353 * V_354 ;
int V_355 , V_20 = - 1 ;
if ( V_11 -> V_52 . V_356 > V_357 )
return F_256 ( V_13 , V_350 , 0 ) ;
V_350 -> V_358 . V_358 = 0 ;
V_355 = F_257 ( V_13 ) ;
if ( V_13 -> V_307 == F_228 ( V_314 ) ) {
if ( F_5 ( ! F_258 ( V_13 , V_355 + sizeof( * V_354 ) ) ) )
return false ;
V_354 = F_259 ( V_13 ) ;
F_260 ( V_350 , V_354 ) ;
V_355 += V_354 -> V_359 << 2 ;
if ( ! F_261 ( V_354 ) )
V_20 = V_354 -> V_307 ;
} else if ( V_13 -> V_307 == F_228 ( V_360 ) ) {
if ( F_5 ( ! F_258 ( V_13 , V_355 + sizeof( * V_352 ) ) ) )
return false ;
V_352 = F_262 ( V_13 ) ;
F_263 ( V_350 , V_352 ) ;
V_355 += sizeof( * V_352 ) ;
V_20 = V_352 -> V_361 ;
} else {
return false ;
}
if ( V_11 -> V_52 . V_356 == V_362 && V_20 >= 0 )
V_350 -> V_358 . V_358 = F_264 ( V_13 , V_355 , V_20 ) ;
return true ;
}
T_8 F_265 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
struct V_349 V_363 ;
T_8 V_364 ;
if ( V_11 -> V_52 . V_356 == V_365 &&
V_13 -> V_366 )
return V_13 -> V_364 ;
if ( V_11 -> V_52 . V_356 == V_367 ||
! F_255 ( V_11 , V_13 , & V_363 ) )
return F_253 ( V_13 ) ;
if ( V_11 -> V_52 . V_356 == V_357 ||
V_11 -> V_52 . V_356 == V_368 )
V_364 = F_253 ( V_13 ) ;
else
V_364 = ( V_369 T_8 ) V_363 . V_358 . V_358 ;
V_364 ^= ( V_369 T_8 ) F_266 ( & V_363 ) ^
( V_369 T_8 ) F_267 ( & V_363 ) ;
V_364 ^= ( V_364 >> 16 ) ;
V_364 ^= ( V_364 >> 8 ) ;
return V_364 ;
}
void F_268 ( struct V_10 * V_11 )
{
F_135 ( & V_11 -> V_72 ,
F_38 ) ;
F_135 ( & V_11 -> V_370 , V_371 ) ;
F_135 ( & V_11 -> V_270 , F_192 ) ;
F_135 ( & V_11 -> V_323 , F_243 ) ;
F_135 ( & V_11 -> V_372 , V_373 ) ;
F_135 ( & V_11 -> V_374 , V_375 ) ;
}
static void F_269 ( struct V_10 * V_11 )
{
F_270 ( & V_11 -> V_270 ) ;
F_270 ( & V_11 -> V_323 ) ;
F_270 ( & V_11 -> V_370 ) ;
F_270 ( & V_11 -> V_372 ) ;
F_270 ( & V_11 -> V_72 ) ;
F_270 ( & V_11 -> V_374 ) ;
}
static int F_271 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
if ( F_19 ( V_11 ) ) {
F_12 (bond, slave, iter) {
if ( F_33 ( V_11 ) &&
V_22 != F_160 ( V_11 -> V_69 ) ) {
F_76 ( V_22 ,
V_120 ) ;
} else if ( F_20 ( V_11 ) != V_7 ) {
F_77 ( V_22 ,
V_120 ) ;
}
}
}
if ( F_16 ( V_11 ) ) {
if ( F_272 ( V_11 , ( F_20 ( V_11 ) == V_9 ) ) )
return - V_130 ;
if ( V_11 -> V_52 . V_376 )
F_41 ( V_11 -> V_73 , & V_11 -> V_370 , 0 ) ;
}
if ( V_11 -> V_52 . V_119 )
F_41 ( V_11 -> V_73 , & V_11 -> V_270 , 0 ) ;
if ( V_11 -> V_52 . V_241 ) {
F_41 ( V_11 -> V_73 , & V_11 -> V_323 , 0 ) ;
V_11 -> F_106 = F_220 ;
}
if ( F_20 ( V_11 ) == V_7 ) {
F_41 ( V_11 -> V_73 , & V_11 -> V_372 , 0 ) ;
V_11 -> F_106 = V_377 ;
F_273 ( V_11 , 1 ) ;
}
if ( F_167 ( V_11 ) )
F_168 ( V_11 , NULL ) ;
return 0 ;
}
static int F_274 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_269 ( V_11 ) ;
V_11 -> V_114 = 0 ;
if ( F_16 ( V_11 ) )
F_275 ( V_11 ) ;
V_11 -> F_106 = NULL ;
return 0 ;
}
static void F_276 ( struct V_378 * V_379 ,
const struct V_378 * V_380 ,
const struct V_378 * V_381 )
{
const T_9 * V_382 = ( const T_9 * ) V_380 ;
const T_9 * V_383 = ( const T_9 * ) V_381 ;
T_9 * V_26 = ( T_9 * ) V_379 ;
int V_214 ;
for ( V_214 = 0 ; V_214 < sizeof( * V_379 ) / sizeof( T_9 ) ; V_214 ++ ) {
T_9 V_384 = V_382 [ V_214 ] ;
T_9 V_385 = V_383 [ V_214 ] ;
T_10 V_386 = V_384 - V_385 ;
if ( ( ( V_384 | V_385 ) >> 32 ) == 0 )
V_386 = ( T_10 ) ( V_387 ) ( ( T_8 ) V_384 - ( T_8 ) V_385 ) ;
if ( V_386 > 0 )
V_26 [ V_214 ] += V_386 ;
}
}
static void F_179 ( struct V_14 * V_19 ,
struct V_378 * V_388 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_378 V_389 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_277 ( & V_11 -> V_390 ) ;
memcpy ( V_388 , & V_11 -> V_257 , sizeof( * V_388 ) ) ;
F_65 () ;
F_88 (bond, slave, iter) {
const struct V_378 * V_382 =
F_149 ( V_22 -> V_16 , & V_389 ) ;
F_276 ( V_388 , V_382 , & V_22 -> V_238 ) ;
memcpy ( & V_22 -> V_238 , V_382 , sizeof( * V_382 ) ) ;
}
F_67 () ;
memcpy ( & V_11 -> V_257 , V_388 , sizeof( * V_388 ) ) ;
F_278 ( & V_11 -> V_390 ) ;
}
static int F_279 ( struct V_14 * V_19 , struct V_48 * V_49 , int V_391 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_14 * V_15 = NULL ;
struct V_193 V_392 ;
struct V_193 T_11 * V_393 = NULL ;
struct V_198 V_394 ;
struct V_198 T_11 * V_395 = NULL ;
struct V_50 * V_51 = NULL ;
struct V_396 V_397 ;
struct V_398 * V_398 ;
int V_26 = 0 ;
F_54 ( V_19 , L_102 , V_391 ) ;
switch ( V_391 ) {
case V_61 :
V_51 = F_31 ( V_49 ) ;
if ( ! V_51 )
return - V_223 ;
V_51 -> V_399 = 0 ;
case V_64 :
V_51 = F_31 ( V_49 ) ;
if ( ! V_51 )
return - V_223 ;
if ( V_51 -> V_62 == 1 ) {
V_51 -> V_65 = 0 ;
if ( F_22 ( V_11 -> V_16 ) )
V_51 -> V_65 = V_54 ;
}
return 0 ;
case V_400 :
case V_401 :
V_393 = (struct V_193 T_11 * ) V_49 -> V_402 ;
if ( F_280 ( & V_392 , V_393 , sizeof( V_193 ) ) )
return - V_403 ;
F_186 ( V_19 , & V_392 ) ;
if ( F_281 ( V_393 , & V_392 , sizeof( V_193 ) ) )
return - V_403 ;
return 0 ;
case V_404 :
case V_405 :
V_395 = (struct V_198 T_11 * ) V_49 -> V_402 ;
if ( F_280 ( & V_394 , V_395 , sizeof( V_198 ) ) )
return - V_403 ;
V_26 = F_187 ( V_19 , & V_394 ) ;
if ( V_26 == 0 &&
F_281 ( V_395 , & V_394 , sizeof( V_198 ) ) )
return - V_403 ;
return V_26 ;
default:
break;
}
V_398 = F_215 ( V_19 ) ;
if ( ! F_282 ( V_398 -> V_406 , V_407 ) )
return - V_216 ;
V_15 = F_283 ( V_398 , V_49 -> V_408 ) ;
F_54 ( V_19 , L_103 , V_15 ) ;
if ( ! V_15 )
return - V_261 ;
F_54 ( V_19 , L_104 , V_15 -> V_59 ) ;
switch ( V_391 ) {
case V_409 :
case V_410 :
V_26 = F_139 ( V_19 , V_15 ) ;
break;
case V_411 :
case V_412 :
V_26 = F_182 ( V_19 , V_15 ) ;
break;
case V_413 :
case V_414 :
F_53 ( V_19 , V_15 ) ;
V_26 = 0 ;
break;
case V_415 :
case V_416 :
F_284 ( & V_397 , V_15 -> V_59 ) ;
V_26 = F_285 ( V_11 , V_417 , & V_397 ) ;
break;
default:
V_26 = - V_225 ;
}
return V_26 ;
}
static void F_286 ( struct V_14 * V_19 , int V_418 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
if ( V_418 & V_83 )
F_32 ( V_11 ,
V_19 -> V_82 & V_83 ? 1 : - 1 ) ;
if ( V_418 & V_84 )
F_36 ( V_11 ,
V_19 -> V_82 & V_84 ? 1 : - 1 ) ;
}
static void F_287 ( struct V_14 * V_19 )
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
F_152 ( V_22 -> V_16 , V_19 ) ;
F_151 ( V_22 -> V_16 , V_19 ) ;
}
}
F_67 () ;
}
static int F_288 ( struct V_419 * V_420 )
{
struct V_10 * V_11 = F_11 ( V_420 -> V_16 ) ;
const struct V_45 * V_46 ;
struct V_421 V_422 ;
struct V_22 * V_22 ;
int V_171 ;
V_22 = F_289 ( V_11 ) ;
if ( ! V_22 )
return 0 ;
V_46 = V_22 -> V_16 -> V_47 ;
if ( ! V_46 -> V_423 )
return 0 ;
V_422 . V_424 = NULL ;
V_422 . V_425 = NULL ;
V_171 = V_46 -> V_423 ( V_22 -> V_16 , & V_422 ) ;
if ( V_171 )
return V_171 ;
V_420 -> V_422 -> V_425 = V_422 . V_425 ;
if ( ! V_422 . V_424 )
return 0 ;
return V_422 . V_424 ( V_420 ) ;
}
static int F_290 ( struct V_14 * V_16 ,
struct V_421 * V_422 )
{
if ( V_422 -> V_16 == V_16 )
V_422 -> V_424 = F_288 ;
return 0 ;
}
static int F_291 ( struct V_14 * V_19 , int V_426 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_23 ;
struct V_24 * V_25 ;
int V_26 = 0 ;
F_54 ( V_19 , L_105 , V_11 , V_426 ) ;
F_12 (bond, slave, iter) {
F_54 ( V_19 , L_106 ,
V_22 , V_22 -> V_16 -> V_47 -> V_427 ) ;
V_26 = F_147 ( V_22 -> V_16 , V_426 ) ;
if ( V_26 ) {
F_54 ( V_19 , L_107 , V_26 ,
V_22 -> V_16 -> V_59 ) ;
goto V_27;
}
}
V_19 -> V_232 = V_426 ;
return 0 ;
V_27:
F_12 (bond, rollback_slave, iter) {
int V_428 ;
if ( V_23 == V_22 )
break;
V_428 = F_147 ( V_23 -> V_16 , V_19 -> V_232 ) ;
if ( V_428 ) {
F_54 ( V_19 , L_108 ,
V_428 , V_23 -> V_16 -> V_59 ) ;
}
}
return V_26 ;
}
static int F_292 ( struct V_14 * V_19 , void * V_293 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_23 ;
struct V_92 * V_93 = V_293 , V_429 ;
struct V_24 * V_25 ;
int V_26 = 0 ;
if ( F_20 ( V_11 ) == V_9 )
return F_293 ( V_19 , V_293 ) ;
F_54 ( V_19 , L_109 , V_11 ) ;
if ( V_11 -> V_52 . V_95 &&
F_20 ( V_11 ) == V_4 )
return 0 ;
if ( ! F_294 ( V_93 -> V_98 ) )
return - V_430 ;
F_12 (bond, slave, iter) {
F_54 ( V_19 , L_110 , V_22 , V_22 -> V_16 -> V_59 ) ;
V_26 = F_59 ( V_22 -> V_16 , V_293 ) ;
if ( V_26 ) {
F_54 ( V_19 , L_107 , V_26 , V_22 -> V_16 -> V_59 ) ;
goto V_27;
}
}
memcpy ( V_19 -> V_86 , V_93 -> V_98 , V_19 -> V_85 ) ;
return 0 ;
V_27:
memcpy ( V_429 . V_98 , V_19 -> V_86 , V_19 -> V_85 ) ;
V_429 . V_99 = V_19 -> type ;
F_12 (bond, rollback_slave, iter) {
int V_428 ;
if ( V_23 == V_22 )
break;
V_428 = F_59 ( V_23 -> V_16 ,
(struct V_100 * ) & V_429 ) ;
if ( V_428 ) {
F_54 ( V_19 , L_108 ,
V_428 , V_23 -> V_16 -> V_59 ) ;
}
}
return V_26 ;
}
static void F_295 ( struct V_10 * V_11 , struct V_12 * V_13 , int V_262 )
{
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_214 = V_262 ;
F_88 (bond, slave, iter) {
if ( -- V_214 < 0 ) {
if ( F_296 ( V_22 ) ) {
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
return;
}
}
}
V_214 = V_262 ;
F_88 (bond, slave, iter) {
if ( -- V_214 < 0 )
break;
if ( F_296 ( V_22 ) ) {
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
return;
}
}
F_297 ( V_11 -> V_16 , V_13 ) ;
}
static T_8 F_298 ( struct V_10 * V_11 )
{
T_8 V_262 ;
struct V_431 V_432 ;
int V_433 = V_11 -> V_52 . V_433 ;
switch ( V_433 ) {
case 0 :
V_262 = F_299 () ;
break;
case 1 :
V_262 = V_11 -> V_434 ;
break;
default:
V_432 =
V_11 -> V_52 . V_432 ;
V_262 = F_300 ( V_11 -> V_434 ,
V_432 ) ;
break;
}
V_11 -> V_434 ++ ;
return V_262 ;
}
static int F_301 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_353 * V_354 = F_259 ( V_13 ) ;
struct V_22 * V_22 ;
T_8 V_262 ;
if ( V_354 -> V_307 == V_435 && V_13 -> V_307 == F_228 ( V_314 ) ) {
V_22 = F_66 ( V_11 -> V_69 ) ;
if ( V_22 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_295 ( V_11 , V_13 , 0 ) ;
} else {
int V_197 = F_109 ( V_11 -> V_197 ) ;
if ( F_302 ( V_197 ) ) {
V_262 = F_298 ( V_11 ) ;
F_295 ( V_11 , V_13 , V_262 % V_197 ) ;
} else {
F_297 ( V_19 , V_13 ) ;
}
}
return V_436 ;
}
static int F_303 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 ;
V_22 = F_66 ( V_11 -> V_69 ) ;
if ( V_22 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_297 ( V_19 , V_13 ) ;
return V_436 ;
}
void F_304 ( struct V_10 * V_11 , unsigned long V_113 )
{
F_41 ( V_11 -> V_73 , & V_11 -> V_374 , V_113 ) ;
}
static void V_375 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_39 ( V_71 , struct V_10 ,
V_374 . V_71 ) ;
int V_171 ;
if ( ! F_40 () )
goto V_67;
V_171 = F_168 ( V_11 , NULL ) ;
F_43 () ;
if ( V_171 ) {
F_305 ( L_111 ) ;
goto V_67;
}
return;
V_67:
F_304 ( V_11 , 1 ) ;
}
int F_168 ( struct V_10 * V_11 , struct V_22 * V_437 )
{
struct V_22 * V_22 ;
struct V_24 * V_25 ;
struct V_438 * V_439 , * V_440 ;
int V_441 = 0 ;
int V_171 = 0 ;
#ifdef F_306
F_307 ( F_308 ( & V_11 -> V_442 ) ) ;
#endif
V_439 = F_81 ( F_309 ( struct V_438 , V_443 [ V_11 -> V_197 ] ) ,
V_129 ) ;
if ( ! V_439 ) {
V_171 = - V_130 ;
F_310 ( L_112 ) ;
goto V_101;
}
if ( F_20 ( V_11 ) == V_7 ) {
struct V_131 V_131 ;
if ( F_87 ( V_11 , & V_131 ) ) {
F_311 ( L_113 ) ;
F_312 ( V_439 , V_444 ) ;
V_440 = F_34 ( V_11 -> V_445 ) ;
if ( V_440 ) {
F_171 ( V_11 -> V_445 , NULL ) ;
F_312 ( V_440 , V_444 ) ;
}
goto V_101;
}
V_441 = V_131 . V_140 ;
}
F_12 (bond, slave, iter) {
if ( F_20 ( V_11 ) == V_7 ) {
struct V_136 * V_137 ;
V_137 = F_89 ( V_22 ) -> V_138 . V_136 ;
if ( ! V_137 || V_137 -> V_139 != V_441 )
continue;
}
if ( ! F_296 ( V_22 ) )
continue;
if ( V_437 == V_22 )
continue;
V_439 -> V_443 [ V_439 -> V_446 ++ ] = V_22 ;
}
V_440 = F_34 ( V_11 -> V_445 ) ;
F_78 ( V_11 -> V_445 , V_439 ) ;
if ( V_440 )
F_312 ( V_440 , V_444 ) ;
V_101:
if ( V_171 != 0 && V_437 ) {
int V_447 ;
V_440 = F_34 ( V_11 -> V_445 ) ;
for ( V_447 = 0 ; V_447 < V_440 -> V_446 ; V_447 ++ ) {
if ( V_437 == V_440 -> V_443 [ V_447 ] ) {
V_440 -> V_443 [ V_447 ] =
V_440 -> V_443 [ V_440 -> V_446 - 1 ] ;
V_440 -> V_446 -- ;
break;
}
}
}
return V_171 ;
}
static int F_313 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
struct V_22 * V_22 ;
struct V_438 * V_448 ;
unsigned int V_446 ;
V_448 = F_66 ( V_11 -> V_445 ) ;
V_446 = V_448 ? F_109 ( V_448 -> V_446 ) : 0 ;
if ( F_302 ( V_446 ) ) {
V_22 = V_448 -> V_443 [ F_265 ( V_11 , V_13 ) % V_446 ] ;
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
} else {
F_297 ( V_16 , V_13 ) ;
}
return V_436 ;
}
static int F_314 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 = NULL ;
struct V_24 * V_25 ;
F_88 (bond, slave, iter) {
if ( F_315 ( V_11 , V_22 ) )
break;
if ( F_63 ( V_22 ) && V_22 -> V_29 == V_30 ) {
struct V_12 * V_449 = F_316 ( V_13 , V_173 ) ;
if ( ! V_449 ) {
F_200 ( L_114 ,
V_19 -> V_59 , V_450 ) ;
continue;
}
F_2 ( V_11 , V_449 , V_22 -> V_16 ) ;
}
}
if ( V_22 && F_63 ( V_22 ) && V_22 -> V_29 == V_30 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_297 ( V_19 , V_13 ) ;
return V_436 ;
}
static inline int F_317 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_22 * V_22 = NULL ;
struct V_24 * V_25 ;
if ( ! V_13 -> V_17 )
return 1 ;
F_88 (bond, slave, iter) {
if ( V_22 -> V_230 == V_13 -> V_17 ) {
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
static T_2 F_318 ( struct V_14 * V_16 , struct V_12 * V_13 ,
void * V_451 , T_12 V_452 )
{
T_2 V_453 = F_319 ( V_13 ) ? F_320 ( V_13 ) : 0 ;
F_4 ( V_13 ) -> V_18 = V_13 -> V_17 ;
if ( F_5 ( V_453 >= V_16 -> V_454 ) ) {
do {
V_453 -= V_16 -> V_454 ;
} while ( V_453 >= V_16 -> V_454 );
}
return V_453 ;
}
static T_13 F_321 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
if ( F_322 ( V_11 ) &&
! F_317 ( V_11 , V_13 ) )
return V_436 ;
switch ( F_20 ( V_11 ) ) {
case V_3 :
return F_301 ( V_13 , V_16 ) ;
case V_4 :
return F_303 ( V_13 , V_16 ) ;
case V_7 :
case V_5 :
return F_313 ( V_13 , V_16 ) ;
case V_6 :
return F_314 ( V_13 , V_16 ) ;
case V_9 :
return F_323 ( V_13 , V_16 ) ;
case V_8 :
return F_324 ( V_13 , V_16 ) ;
default:
F_60 ( V_16 , L_115 , F_20 ( V_11 ) ) ;
F_325 ( 1 ) ;
F_297 ( V_16 , V_13 ) ;
return V_436 ;
}
}
static T_13 F_326 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
T_13 V_171 = V_436 ;
if ( F_5 ( F_327 ( V_16 ) ) )
return V_455 ;
F_65 () ;
if ( F_19 ( V_11 ) )
V_171 = F_321 ( V_13 , V_16 ) ;
else
F_297 ( V_16 , V_13 ) ;
F_67 () ;
return V_171 ;
}
static int F_328 ( struct V_14 * V_19 ,
struct V_31 * V_391 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
unsigned long V_33 = 0 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
V_391 -> V_37 . V_35 = V_36 ;
V_391 -> V_37 . V_138 = V_456 ;
F_12 (bond, slave, iter) {
if ( F_296 ( V_22 ) ) {
if ( V_22 -> V_33 != V_34 )
V_33 += V_22 -> V_33 ;
if ( V_391 -> V_37 . V_35 == V_36 &&
V_22 -> V_35 != V_36 )
V_391 -> V_37 . V_35 = V_22 -> V_35 ;
}
}
V_391 -> V_37 . V_33 = V_33 ? : V_34 ;
return 0 ;
}
static void F_329 ( struct V_14 * V_19 ,
struct V_457 * V_458 )
{
F_330 ( V_458 -> V_459 , V_460 , sizeof( V_458 -> V_459 ) ) ;
F_330 ( V_458 -> V_461 , V_462 , sizeof( V_458 -> V_461 ) ) ;
snprintf ( V_458 -> V_463 , sizeof( V_458 -> V_463 ) , L_116 ,
V_464 ) ;
}
static void F_331 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
if ( V_11 -> V_73 )
F_332 ( V_11 -> V_73 ) ;
}
void F_333 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_334 ( & V_11 -> V_442 ) ;
F_334 ( & V_11 -> V_390 ) ;
V_11 -> V_52 = V_465 ;
V_11 -> V_16 = V_19 ;
F_146 ( V_19 ) ;
V_19 -> V_466 = V_467 ;
V_19 -> V_47 = & V_468 ;
V_19 -> V_55 = & V_469 ;
V_19 -> V_470 = true ;
V_19 -> V_471 = F_331 ;
F_335 ( V_19 , & V_472 ) ;
V_19 -> V_82 |= V_252 ;
V_19 -> V_162 |= V_237 | V_473 | V_474 ;
V_19 -> V_162 &= ~ ( V_148 | V_221 ) ;
V_19 -> V_143 |= V_475 ;
V_19 -> V_143 |= V_476 ;
V_19 -> V_477 = V_151 |
V_478 |
V_479 |
V_480 ;
V_19 -> V_477 |= V_164 ;
V_19 -> V_143 |= V_19 -> V_477 ;
}
static void F_336 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
struct V_438 * V_443 ;
F_93 ( V_19 ) ;
F_12 (bond, slave, iter)
F_176 ( V_19 , V_22 -> V_16 , true ) ;
F_71 ( V_19 , L_117 ) ;
V_443 = F_34 ( V_11 -> V_445 ) ;
if ( V_443 ) {
F_171 ( V_11 -> V_445 , NULL ) ;
F_312 ( V_443 , V_444 ) ;
}
F_337 ( & V_11 -> V_481 ) ;
F_338 ( V_11 ) ;
}
static int F_339 ( struct V_482 * V_52 )
{
int V_483 , V_484 , V_485 , V_214 ;
struct V_396 V_397 ;
const struct V_396 * V_486 ;
int V_487 = 0 ;
T_2 V_488 = 0 ;
T_2 V_489 = 0 ;
T_7 V_490 [ V_242 ] = { 0 } ;
int V_491 ;
int V_195 = V_3 ;
int V_492 = V_367 ;
int V_493 = 0 ;
int V_376 = 0 ;
if ( V_1 ) {
F_284 ( & V_397 , V_1 ) ;
V_486 = F_340 ( F_341 ( V_494 ) , & V_397 ) ;
if ( ! V_486 ) {
F_310 ( L_118 , V_1 ) ;
return - V_223 ;
}
V_195 = V_486 -> V_495 ;
}
if ( V_496 ) {
if ( ( V_195 != V_5 ) &&
( V_195 != V_7 ) &&
( V_195 != V_8 ) ) {
F_342 ( L_119 ,
F_1 ( V_195 ) ) ;
} else {
F_284 ( & V_397 , V_496 ) ;
V_486 = F_340 ( F_341 ( V_497 ) ,
& V_397 ) ;
if ( ! V_486 ) {
F_310 ( L_120 ,
V_496 ) ;
return - V_223 ;
}
V_492 = V_486 -> V_495 ;
}
}
if ( V_498 ) {
if ( V_195 != V_7 ) {
F_342 ( L_121 ,
F_1 ( V_195 ) ) ;
} else {
F_284 ( & V_397 , V_498 ) ;
V_486 = F_340 ( F_341 ( V_499 ) ,
& V_397 ) ;
if ( ! V_486 ) {
F_310 ( L_122 ,
V_498 ) ;
return - V_223 ;
}
V_493 = V_486 -> V_495 ;
}
}
if ( V_500 ) {
F_284 ( & V_397 , V_500 ) ;
V_486 = F_340 ( F_341 ( V_501 ) ,
& V_397 ) ;
if ( ! V_486 ) {
F_310 ( L_123 , V_500 ) ;
return - V_223 ;
}
V_52 -> V_500 = V_486 -> V_495 ;
if ( V_195 != V_7 )
F_343 ( L_124 ) ;
} else {
V_52 -> V_500 = V_502 ;
}
if ( V_503 < 0 ) {
F_343 ( L_125 ,
V_503 , 0 , V_504 , V_505 ) ;
V_503 = V_505 ;
}
if ( V_119 < 0 ) {
F_343 ( L_126 ,
V_119 , V_504 ) ;
V_119 = 0 ;
}
if ( V_112 < 0 ) {
F_343 ( L_127 ,
V_112 , V_504 ) ;
V_112 = 0 ;
}
if ( V_267 < 0 ) {
F_343 ( L_128 ,
V_267 , V_504 ) ;
V_267 = 0 ;
}
if ( ( V_53 != 0 ) && ( V_53 != 1 ) ) {
F_343 ( L_129 ,
V_53 ) ;
V_53 = 1 ;
}
if ( V_122 < 0 || V_122 > 255 ) {
F_343 ( L_130 ,
V_122 ) ;
V_122 = 1 ;
}
if ( ! F_344 ( V_195 ) ) {
if ( ! V_119 ) {
F_343 ( L_131 ) ;
F_343 ( L_132 ) ;
V_119 = V_506 ;
}
}
if ( V_507 < 1 || V_507 > 255 ) {
F_343 ( L_133 ,
V_507 , V_508 ) ;
V_507 = V_508 ;
}
if ( ( V_509 != 0 ) && ( V_509 != 1 ) ) {
F_343 ( L_134 ,
V_509 ) ;
V_509 = 0 ;
}
if ( V_125 < 0 || V_125 > 255 ) {
F_343 ( L_135 ,
V_125 , V_510 ) ;
V_125 = V_510 ;
}
F_345 ( & V_397 , V_433 ) ;
if ( ! F_340 ( F_341 ( V_511 ) , & V_397 ) ) {
F_343 ( L_136 ,
V_433 , V_512 ) ;
V_433 = 1 ;
}
if ( V_195 == V_9 ) {
F_346 ( L_137 ,
V_112 ) ;
}
if ( ! V_119 ) {
if ( V_112 || V_267 ) {
F_343 ( L_138 ,
V_112 , V_267 ) ;
}
} else {
if ( V_241 ) {
F_343 ( L_139 ,
V_119 , V_241 ) ;
V_241 = 0 ;
}
if ( ( V_112 % V_119 ) != 0 ) {
F_343 ( L_140 ,
V_112 , V_119 , ( V_112 / V_119 ) * V_119 ) ;
}
V_112 /= V_119 ;
if ( ( V_267 % V_119 ) != 0 ) {
F_343 ( L_141 ,
V_267 , V_119 ,
( V_267 / V_119 ) * V_119 ) ;
}
V_267 /= V_119 ;
}
if ( V_241 < 0 ) {
F_343 ( L_142 ,
V_241 , V_504 ) ;
V_241 = 0 ;
}
for ( V_491 = 0 , V_214 = 0 ;
( V_491 < V_242 ) && V_513 [ V_214 ] ; V_214 ++ ) {
T_7 V_274 ;
if ( ! F_347 ( V_513 [ V_214 ] , - 1 , ( T_4 * ) & V_274 , - 1 , NULL ) ||
! F_348 ( V_274 ) ) {
F_343 ( L_143 ,
V_513 [ V_214 ] ) ;
V_241 = 0 ;
} else {
if ( F_219 ( V_490 , V_274 ) == - 1 )
V_490 [ V_491 ++ ] = V_274 ;
else
F_343 ( L_144 ,
& V_274 ) ;
}
}
if ( V_241 && ! V_491 ) {
F_343 ( L_145 ,
V_241 ) ;
V_241 = 0 ;
}
if ( V_295 ) {
if ( ! V_241 ) {
F_310 ( L_146 ) ;
return - V_223 ;
}
F_284 ( & V_397 , V_295 ) ;
V_486 = F_340 ( F_341 ( V_514 ) ,
& V_397 ) ;
if ( ! V_486 ) {
F_310 ( L_147 ,
V_295 ) ;
return - V_223 ;
}
V_483 = V_486 -> V_495 ;
} else {
V_483 = 0 ;
}
if ( V_515 ) {
F_284 ( & V_397 , V_515 ) ;
V_486 = F_340 ( F_341 ( V_516 ) ,
& V_397 ) ;
if ( ! V_486 ) {
F_310 ( L_148 ,
V_515 ) ;
V_487 = 0 ;
} else {
V_487 = V_486 -> V_495 ;
}
}
if ( V_119 ) {
F_342 ( L_149 , V_119 ) ;
} else if ( V_241 ) {
V_486 = F_349 ( V_514 ,
V_483 ) ;
F_342 ( L_150 ,
V_241 , V_486 -> string , V_491 ) ;
for ( V_214 = 0 ; V_214 < V_491 ; V_214 ++ )
F_350 ( L_151 , V_513 [ V_214 ] ) ;
F_350 ( L_152 ) ;
} else if ( V_503 ) {
F_311 ( L_153 ) ;
}
if ( V_245 && ! F_351 ( V_195 ) ) {
F_343 ( L_154 ,
V_245 , F_1 ( V_195 ) ) ;
V_245 = NULL ;
}
if ( V_245 && V_106 ) {
F_284 ( & V_397 , V_106 ) ;
V_486 = F_340 ( F_341 ( V_517 ) ,
& V_397 ) ;
if ( ! V_486 ) {
F_310 ( L_155 ,
V_106 ) ;
return - V_223 ;
}
V_485 = V_486 -> V_495 ;
} else {
V_485 = V_107 ;
}
if ( V_95 ) {
F_284 ( & V_397 , V_95 ) ;
V_486 = F_340 ( F_341 ( V_518 ) ,
& V_397 ) ;
if ( ! V_486 ) {
F_310 ( L_156 ,
V_95 ) ;
return - V_223 ;
}
V_484 = V_486 -> V_495 ;
if ( V_195 != V_4 )
F_343 ( L_157 ) ;
} else {
V_484 = V_519 ;
}
F_284 ( & V_397 , L_158 ) ;
V_486 = F_340 (
F_341 ( V_520 ) ,
& V_397 ) ;
if ( ! V_486 ) {
F_310 ( L_159 ) ;
return - V_223 ;
}
V_488 = V_486 -> V_495 ;
V_486 = F_340 ( F_341 ( V_521 ) ,
& V_397 ) ;
if ( ! V_486 ) {
F_310 ( L_160 ) ;
return - V_223 ;
}
V_489 = V_486 -> V_495 ;
if ( V_195 == V_8 ) {
F_284 ( & V_397 , L_158 ) ;
V_486 = F_340 ( F_341 ( V_522 ) ,
& V_397 ) ;
if ( ! V_486 ) {
F_310 ( L_161 ) ;
return - V_223 ;
}
V_376 = V_486 -> V_495 ;
}
if ( V_523 == 0 ) {
F_343 ( L_162 ,
V_504 , V_524 ) ;
V_523 = V_524 ;
}
V_52 -> V_1 = V_195 ;
V_52 -> V_356 = V_492 ;
V_52 -> V_119 = V_119 ;
V_52 -> V_122 = V_122 ;
V_52 -> V_241 = V_241 ;
V_52 -> V_295 = V_483 ;
V_52 -> V_515 = V_487 ;
V_52 -> V_112 = V_112 ;
V_52 -> V_267 = V_267 ;
V_52 -> V_53 = V_53 ;
V_52 -> V_493 = V_493 ;
V_52 -> V_245 [ 0 ] = 0 ;
V_52 -> V_106 = V_485 ;
V_52 -> V_95 = V_484 ;
V_52 -> V_507 = V_507 ;
V_52 -> V_509 = V_509 ;
V_52 -> V_125 = V_125 ;
V_52 -> V_525 = V_525 ;
V_52 -> V_523 = V_523 ;
V_52 -> V_433 = V_433 ;
V_52 -> V_376 = V_376 ;
V_52 -> V_488 = V_488 ;
F_352 ( V_52 -> V_526 ) ;
V_52 -> V_489 = V_489 ;
if ( V_433 > 0 ) {
V_52 -> V_432 =
V_431 ( V_433 ) ;
} else {
V_52 -> V_432 =
(struct V_431 ) { 0 } ;
}
if ( V_245 ) {
strncpy ( V_52 -> V_245 , V_245 , V_60 ) ;
V_52 -> V_245 [ V_60 - 1 ] = 0 ;
}
memcpy ( V_52 -> V_292 , V_490 , sizeof( V_490 ) ) ;
return 0 ;
}
static int F_353 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_527 * V_528 = F_354 ( F_215 ( V_19 ) , V_529 ) ;
F_54 ( V_19 , L_163 ) ;
V_11 -> V_73 = F_355 ( V_19 -> V_59 , V_530 ) ;
if ( ! V_11 -> V_73 )
return - V_130 ;
F_356 ( V_19 ) ;
F_357 ( & V_11 -> V_481 , & V_528 -> V_531 ) ;
F_358 ( V_11 ) ;
F_359 ( V_11 ) ;
if ( F_360 ( V_19 -> V_86 ) &&
V_19 -> V_87 == V_532 )
F_175 ( V_19 ) ;
return 0 ;
}
unsigned int F_361 ( void )
{
return V_507 ;
}
int F_362 ( struct V_398 * V_398 , const char * V_59 )
{
struct V_14 * V_19 ;
struct V_10 * V_11 ;
struct V_533 * V_534 ;
int V_26 ;
F_129 () ;
V_19 = F_363 ( sizeof( struct V_10 ) ,
V_59 ? V_59 : L_164 , V_535 ,
F_333 , V_507 ) ;
if ( ! V_19 ) {
F_310 ( L_165 , V_59 ) ;
F_43 () ;
return - V_130 ;
}
V_11 = F_11 ( V_19 ) ;
V_534 = & ( F_364 ( V_11 ) ) ;
V_534 -> V_536 = V_537 ;
F_365 ( V_19 , V_398 ) ;
V_19 -> V_538 = & V_539 ;
V_26 = F_366 ( V_19 ) ;
F_24 ( V_19 ) ;
F_268 ( V_11 ) ;
F_43 () ;
if ( V_26 < 0 )
F_367 ( V_19 ) ;
return V_26 ;
}
static int T_14 F_368 ( struct V_398 * V_398 )
{
struct V_527 * V_528 = F_354 ( V_398 , V_529 ) ;
V_528 -> V_398 = V_398 ;
F_369 ( & V_528 -> V_531 ) ;
F_370 ( V_528 ) ;
F_371 ( V_528 ) ;
return 0 ;
}
static void T_15 F_372 ( struct V_398 * V_398 )
{
struct V_527 * V_528 = F_354 ( V_398 , V_529 ) ;
struct V_10 * V_11 , * V_540 ;
F_373 ( V_541 ) ;
F_374 ( V_528 ) ;
F_129 () ;
F_375 (bond, tmp_bond, &bn->dev_list, bond_list)
F_376 ( V_11 -> V_16 , & V_541 ) ;
F_377 ( & V_541 ) ;
F_43 () ;
F_378 ( V_528 ) ;
}
static int T_16 F_379 ( void )
{
int V_214 ;
int V_26 ;
F_342 ( L_166 , V_542 ) ;
V_26 = F_339 ( & V_465 ) ;
if ( V_26 )
goto V_101;
V_26 = F_380 ( & V_543 ) ;
if ( V_26 )
goto V_101;
V_26 = F_381 () ;
if ( V_26 )
goto V_544;
F_382 () ;
for ( V_214 = 0 ; V_214 < V_503 ; V_214 ++ ) {
V_26 = F_362 ( & V_545 , NULL ) ;
if ( V_26 )
goto V_67;
}
F_383 ( & V_546 ) ;
V_101:
return V_26 ;
V_67:
F_384 () ;
F_385 () ;
V_544:
F_386 ( & V_543 ) ;
goto V_101;
}
static void T_17 F_387 ( void )
{
F_388 ( & V_546 ) ;
F_384 () ;
F_385 () ;
F_386 ( & V_543 ) ;
#ifdef F_161
F_307 ( F_389 ( & V_547 ) ) ;
#endif
}
