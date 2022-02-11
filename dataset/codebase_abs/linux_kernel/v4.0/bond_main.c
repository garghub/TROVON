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
static void F_57 ( struct V_10 * V_11 ,
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
static bool F_61 ( struct V_10 * V_11 )
{
struct V_22 * V_100 = F_36 ( V_11 -> V_101 ) ;
struct V_22 * V_102 = F_36 ( V_11 -> V_69 ) ;
if ( ! V_100 || ! V_102 || V_102 -> V_29 != V_30 )
return true ;
if ( V_11 -> V_103 ) {
V_11 -> V_103 = false ;
return true ;
}
if ( V_11 -> V_52 . V_104 == V_105 &&
( V_100 -> V_34 < V_102 -> V_34 ||
( V_100 -> V_34 == V_102 -> V_34 && V_100 -> V_36 <= V_102 -> V_36 ) ) )
return false ;
if ( V_11 -> V_52 . V_104 == V_106 )
return false ;
return true ;
}
static struct V_22 * F_62 ( struct V_10 * V_11 )
{
struct V_22 * V_22 , * V_107 = NULL , * V_108 ;
struct V_24 * V_25 ;
int V_109 = V_11 -> V_52 . V_110 ;
V_108 = F_36 ( V_11 -> V_101 ) ;
if ( V_108 && V_108 -> V_29 == V_30 &&
F_61 ( V_11 ) )
return V_108 ;
F_12 (bond, slave, iter) {
if ( V_22 -> V_29 == V_30 )
return V_22 ;
if ( V_22 -> V_29 == V_43 && F_63 ( V_22 ) &&
V_22 -> V_111 < V_109 ) {
V_109 = V_22 -> V_111 ;
V_107 = V_22 ;
}
}
return V_107 ;
}
static bool F_64 ( struct V_10 * V_11 )
{
struct V_22 * V_22 ;
F_65 () ;
V_22 = F_66 ( V_11 -> V_69 ) ;
F_67 () ;
F_56 ( V_11 -> V_16 , L_16 ,
V_22 ? V_22 -> V_16 -> V_59 : L_17 ) ;
if ( ! V_22 || ! V_11 -> V_112 ||
F_68 ( V_113 , & V_22 -> V_16 -> V_114 ) )
return false ;
return true ;
}
void F_69 ( struct V_10 * V_11 , struct V_22 * V_80 )
{
struct V_22 * V_81 ;
F_70 () ;
V_81 = F_36 ( V_11 -> V_69 ) ;
if ( V_81 == V_80 )
return;
if ( V_80 ) {
V_80 -> V_115 = V_116 ;
if ( V_80 -> V_29 == V_43 ) {
if ( F_35 ( V_11 ) ) {
F_71 ( V_11 -> V_16 , L_18 ,
V_80 -> V_16 -> V_59 ,
( V_11 -> V_52 . V_110 - V_80 -> V_111 ) * V_11 -> V_52 . V_117 ) ;
}
V_80 -> V_111 = 0 ;
F_72 ( V_80 , V_30 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_73 ( V_80 , V_30 ) ;
if ( F_16 ( V_11 ) )
F_74 ( V_11 , V_80 , V_30 ) ;
} else {
if ( F_35 ( V_11 ) ) {
F_71 ( V_11 -> V_16 , L_19 ,
V_80 -> V_16 -> V_59 ) ;
}
}
}
if ( F_35 ( V_11 ) )
F_50 ( V_11 , V_80 , V_81 ) ;
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
if ( F_31 ( V_11 -> V_16 ) ) {
V_11 -> V_112 =
V_11 -> V_52 . V_120 ;
V_119 =
F_64 ( V_11 ) ;
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
void F_79 ( struct V_10 * V_11 )
{
struct V_22 * V_124 ;
int V_93 ;
F_70 () ;
V_124 = F_62 ( V_11 ) ;
if ( V_124 != F_36 ( V_11 -> V_69 ) ) {
F_69 ( V_11 , V_124 ) ;
V_93 = F_18 ( V_11 ) ;
if ( ! V_93 )
return;
if ( F_22 ( V_11 -> V_16 ) ) {
F_71 ( V_11 -> V_16 , L_20 ) ;
} else {
F_71 ( V_11 -> V_16 , L_21 ) ;
}
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
}
static void F_87 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter)
if ( F_63 ( V_22 ) )
F_84 ( V_22 ) ;
}
static int F_88 ( struct V_14 * V_16 , struct V_129 * V_130 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_67 = 0 ;
F_12 (bond, slave, iter) {
V_67 = F_80 ( V_22 ) ;
if ( V_67 ) {
F_87 ( V_16 ) ;
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
static void F_87 ( struct V_14 * V_19 )
{
}
static T_6 F_89 ( struct V_14 * V_16 ,
T_6 V_131 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
struct V_24 * V_25 ;
T_6 V_132 ;
struct V_22 * V_22 ;
V_132 = V_131 | V_133 ;
V_131 &= ~ V_134 ;
V_131 |= V_135 ;
F_12 (bond, slave, iter) {
V_131 = F_90 ( V_131 ,
V_22 -> V_16 -> V_131 ,
V_132 ) ;
}
V_131 = F_91 ( V_131 , V_132 ) ;
return V_131 ;
}
static void F_92 ( struct V_10 * V_11 )
{
unsigned int V_136 = V_137 |
V_138 ;
T_6 V_139 = V_140 ;
T_6 V_141 = V_142 ;
struct V_14 * V_19 = V_11 -> V_16 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
unsigned short V_143 = V_144 ;
unsigned int V_145 = V_146 ;
T_2 V_147 = V_148 ;
if ( ! F_19 ( V_11 ) )
goto V_149;
V_139 &= V_135 ;
F_12 (bond, slave, iter) {
V_139 = F_90 ( V_139 ,
V_22 -> V_16 -> V_139 , V_140 ) ;
V_141 = F_90 ( V_141 ,
V_22 -> V_16 -> V_150 ,
V_142 ) ;
V_136 &= V_22 -> V_16 -> V_151 ;
if ( V_22 -> V_16 -> V_152 > V_143 )
V_143 = V_22 -> V_16 -> V_152 ;
V_145 = F_93 ( V_145 , V_22 -> V_16 -> V_145 ) ;
V_147 = F_93 ( V_147 , V_22 -> V_16 -> V_147 ) ;
}
V_149:
V_19 -> V_139 = V_139 ;
V_19 -> V_150 = V_141 | V_153 ;
V_19 -> V_152 = V_143 ;
V_19 -> V_147 = V_147 ;
F_94 ( V_19 , V_145 ) ;
V_19 -> V_151 &= ~ V_137 ;
if ( ( V_19 -> V_151 & V_138 ) &&
V_136 == ( V_137 | V_138 ) )
V_19 -> V_151 |= V_137 ;
F_95 ( V_19 ) ;
}
static void F_96 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
V_19 -> V_154 = V_15 -> V_154 ;
V_19 -> type = V_15 -> type ;
V_19 -> V_152 = V_15 -> V_152 ;
V_19 -> V_85 = V_15 -> V_85 ;
memcpy ( V_19 -> V_155 , V_15 -> V_155 ,
V_15 -> V_85 ) ;
}
static bool F_97 ( struct V_12 * V_13 ,
struct V_22 * V_22 ,
struct V_10 * V_11 )
{
if ( F_98 ( V_22 ) ) {
if ( F_20 ( V_11 ) == V_9 &&
V_13 -> V_156 != V_157 &&
V_13 -> V_156 != V_158 )
return false ;
return true ;
}
return false ;
}
static T_7 F_99 ( struct V_12 * * V_159 )
{
struct V_12 * V_13 = * V_159 ;
struct V_22 * V_22 ;
struct V_10 * V_11 ;
int (* F_100)( const struct V_12 * , struct V_10 * ,
struct V_22 * );
int V_160 = V_161 ;
V_13 = F_101 ( V_13 , V_162 ) ;
if ( F_5 ( ! V_13 ) )
return V_163 ;
* V_159 = V_13 ;
V_22 = F_102 ( V_13 -> V_16 ) ;
V_11 = V_22 -> V_11 ;
F_100 = F_103 ( V_11 -> F_100 ) ;
if ( F_100 ) {
V_160 = F_100 ( V_13 , V_11 , V_22 ) ;
if ( V_160 == V_163 ) {
F_104 ( V_13 ) ;
return V_160 ;
}
}
if ( F_97 ( V_13 , V_22 , V_11 ) ) {
return V_164 ;
}
V_13 -> V_16 = V_11 -> V_16 ;
if ( F_20 ( V_11 ) == V_9 &&
V_11 -> V_16 -> V_151 & V_165 &&
V_13 -> V_156 == V_166 ) {
if ( F_5 ( F_105 ( V_13 ,
V_13 -> V_167 - F_106 ( V_13 ) ) ) ) {
F_107 ( V_13 ) ;
return V_163 ;
}
F_58 ( F_108 ( V_13 ) -> V_168 , V_11 -> V_16 -> V_86 ) ;
}
return V_160 ;
}
static int F_109 ( struct V_14 * V_19 ,
struct V_14 * V_15 ,
struct V_22 * V_22 )
{
int V_67 ;
V_67 = F_110 ( V_15 , V_19 , V_22 ) ;
if ( V_67 )
return V_67 ;
V_15 -> V_82 |= V_169 ;
F_111 ( V_170 , V_15 , V_169 , V_127 ) ;
return 0 ;
}
static void F_112 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
F_113 ( V_15 , V_19 ) ;
V_15 -> V_82 &= ~ V_169 ;
F_111 ( V_170 , V_15 , V_169 , V_127 ) ;
}
static struct V_22 * F_114 ( struct V_10 * V_11 )
{
struct V_22 * V_22 = NULL ;
V_22 = F_81 ( sizeof( struct V_22 ) , V_127 ) ;
if ( ! V_22 )
return NULL ;
if ( F_20 ( V_11 ) == V_7 ) {
F_115 ( V_22 ) = F_81 ( sizeof( struct V_171 ) ,
V_127 ) ;
if ( ! F_115 ( V_22 ) ) {
F_83 ( V_22 ) ;
return NULL ;
}
}
return V_22 ;
}
static void F_116 ( struct V_22 * V_22 )
{
struct V_10 * V_11 = F_117 ( V_22 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_83 ( F_115 ( V_22 ) ) ;
F_83 ( V_22 ) ;
}
static void F_118 ( struct V_10 * V_11 , struct V_172 * V_173 )
{
V_173 -> V_174 = F_20 ( V_11 ) ;
V_173 -> V_117 = V_11 -> V_52 . V_117 ;
V_173 -> V_175 = V_11 -> V_176 ;
}
static void F_119 ( struct V_22 * V_22 , struct V_177 * V_173 )
{
strcpy ( V_173 -> V_178 , V_22 -> V_16 -> V_59 ) ;
V_173 -> V_29 = V_22 -> V_29 ;
V_173 -> V_114 = F_120 ( V_22 ) ;
V_173 -> V_179 = V_22 -> V_179 ;
}
static void F_121 ( struct V_14 * V_16 ,
struct V_180 * V_173 )
{
F_122 () ;
F_123 ( V_16 , V_173 ) ;
F_45 () ;
}
static void F_124 ( struct V_70 * V_181 )
{
struct V_182 * V_183 =
F_41 ( V_181 , struct V_182 , V_71 . V_71 ) ;
F_121 ( V_183 -> V_16 , & V_183 -> V_184 ) ;
F_125 ( V_183 -> V_16 ) ;
F_83 ( V_183 ) ;
}
void F_126 ( struct V_22 * V_22 )
{
struct V_10 * V_11 = V_22 -> V_11 ;
struct V_182 * V_185 = F_81 ( sizeof( * V_185 ) , V_162 ) ;
if ( ! V_185 )
return;
F_127 ( V_22 -> V_16 ) ;
V_185 -> V_16 = V_22 -> V_16 ;
F_119 ( V_22 , & V_185 -> V_184 . V_22 ) ;
F_118 ( V_11 , & V_185 -> V_184 . V_186 ) ;
F_128 ( & V_185 -> V_71 , F_124 ) ;
F_43 ( V_22 -> V_11 -> V_73 , & V_185 -> V_71 , 0 ) ;
}
int F_129 ( struct V_14 * V_19 , struct V_14 * V_15 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
const struct V_45 * V_46 = V_15 -> V_47 ;
struct V_22 * V_187 = NULL , * V_188 ;
struct V_91 V_189 ;
int V_190 ;
int V_26 = 0 , V_191 ;
if ( ! V_11 -> V_52 . V_53 &&
V_15 -> V_55 -> V_56 == NULL &&
V_46 -> V_57 == NULL ) {
F_130 ( V_19 , L_22 ,
V_15 -> V_59 ) ;
}
if ( V_15 -> V_82 & V_169 ) {
F_56 ( V_19 , L_23 ) ;
return - V_192 ;
}
if ( V_19 == V_15 ) {
F_60 ( V_19 , L_24 ) ;
return - V_193 ;
}
if ( V_15 -> V_131 & V_194 ) {
F_56 ( V_19 , L_25 ,
V_15 -> V_59 ) ;
if ( F_131 ( V_19 ) ) {
F_60 ( V_19 , L_26 ,
V_15 -> V_59 , V_19 -> V_59 ) ;
return - V_193 ;
} else {
F_130 ( V_19 , L_27 ,
V_15 -> V_59 , V_15 -> V_59 ,
V_19 -> V_59 ) ;
}
} else {
F_56 ( V_19 , L_28 ,
V_15 -> V_59 ) ;
}
if ( ( V_15 -> V_82 & V_195 ) ) {
F_60 ( V_19 , L_29 ,
V_15 -> V_59 ) ;
V_26 = - V_193 ;
goto V_196;
}
if ( ! F_19 ( V_11 ) ) {
if ( V_19 -> type != V_15 -> type ) {
F_56 ( V_19 , L_30 ,
V_19 -> type , V_15 -> type ) ;
V_26 = F_44 ( V_197 ,
V_19 ) ;
V_26 = F_132 ( V_26 ) ;
if ( V_26 ) {
F_60 ( V_19 , L_31 ) ;
V_26 = - V_192 ;
goto V_196;
}
F_133 ( V_19 ) ;
F_134 ( V_19 ) ;
if ( V_15 -> type != V_198 )
F_96 ( V_19 , V_15 ) ;
else {
F_135 ( V_19 ) ;
V_19 -> V_151 &= ~ V_199 ;
}
F_44 ( V_200 ,
V_19 ) ;
}
} else if ( V_19 -> type != V_15 -> type ) {
F_60 ( V_19 , L_32 ,
V_15 -> V_59 , V_15 -> type , V_19 -> type ) ;
V_26 = - V_201 ;
goto V_196;
}
if ( V_46 -> V_202 == NULL ) {
F_130 ( V_19 , L_33 ) ;
if ( F_20 ( V_11 ) == V_4 &&
V_11 -> V_52 . V_94 != V_95 ) {
if ( ! F_19 ( V_11 ) ) {
V_11 -> V_52 . V_94 = V_95 ;
F_130 ( V_19 , L_34 ) ;
} else {
F_60 ( V_19 , L_35 ) ;
V_26 = - V_203 ;
goto V_196;
}
}
}
F_44 ( V_204 , V_15 ) ;
if ( ! F_19 ( V_11 ) &&
V_11 -> V_16 -> V_87 == V_205 )
F_55 ( V_11 -> V_16 , V_15 ) ;
V_187 = F_114 ( V_11 ) ;
if ( ! V_187 ) {
V_26 = - V_128 ;
goto V_196;
}
V_187 -> V_11 = V_11 ;
V_187 -> V_16 = V_15 ;
V_187 -> V_206 = 0 ;
V_187 -> V_207 = V_15 -> V_208 ;
V_26 = F_136 ( V_15 , V_11 -> V_16 -> V_208 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_36 , V_26 ) ;
goto V_209;
}
F_58 ( V_187 -> V_210 , V_15 -> V_86 ) ;
if ( ! V_11 -> V_52 . V_94 ||
F_20 ( V_11 ) != V_4 ) {
memcpy ( V_189 . V_97 , V_19 -> V_86 , V_19 -> V_85 ) ;
V_189 . V_98 = V_15 -> type ;
V_26 = F_59 ( V_15 , & V_189 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_37 , V_26 ) ;
goto V_211;
}
}
V_26 = F_137 ( V_15 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_38 , V_15 -> V_59 ) ;
goto V_212;
}
V_15 -> V_151 |= V_213 ;
F_138 ( V_187 -> V_16 , & V_187 -> V_214 ) ;
if ( F_16 ( V_11 ) ) {
V_26 = F_139 ( V_11 , V_187 ) ;
if ( V_26 )
goto V_215;
}
if ( ! F_35 ( V_11 ) ) {
if ( V_19 -> V_82 & V_83 ) {
V_26 = F_37 ( V_15 , 1 ) ;
if ( V_26 )
goto V_215;
}
if ( V_19 -> V_82 & V_84 ) {
V_26 = F_39 ( V_15 , 1 ) ;
if ( V_26 )
goto V_215;
}
F_51 ( V_19 ) ;
F_140 ( V_15 , V_19 ) ;
F_141 ( V_15 , V_19 ) ;
F_54 ( V_19 ) ;
}
if ( F_20 ( V_11 ) == V_7 ) {
T_5 V_77 [ V_78 ] = V_79 ;
F_142 ( V_15 , V_77 ) ;
}
V_26 = F_143 ( V_15 , V_19 ) ;
if ( V_26 ) {
F_60 ( V_19 , L_39 ,
V_15 -> V_59 ) ;
goto V_215;
}
V_188 = F_144 ( V_11 ) ;
V_187 -> V_111 = 0 ;
V_187 -> V_179 = 0 ;
F_25 ( V_187 ) ;
V_187 -> V_216 = V_116 -
( F_145 ( V_11 -> V_52 . V_217 ) + 1 ) ;
for ( V_191 = 0 ; V_191 < V_218 ; V_191 ++ )
V_187 -> V_219 [ V_191 ] = V_187 -> V_216 ;
if ( V_11 -> V_52 . V_117 && ! V_11 -> V_52 . V_53 ) {
V_190 = F_29 ( V_11 , V_15 , 1 ) ;
if ( ( V_190 == - 1 ) && ! V_11 -> V_52 . V_217 ) {
F_130 ( V_19 , L_40 ,
V_15 -> V_59 ) ;
} else if ( V_190 == - 1 ) {
F_130 ( V_19 , L_41 ,
V_15 -> V_59 ) ;
}
}
if ( V_11 -> V_52 . V_117 ) {
if ( F_29 ( V_11 , V_15 , 0 ) == V_54 ) {
if ( V_11 -> V_52 . V_110 ) {
F_72 ( V_187 ,
V_43 ) ;
V_187 -> V_111 = V_11 -> V_52 . V_110 ;
} else {
F_72 ( V_187 ,
V_30 ) ;
}
} else {
F_72 ( V_187 , V_42 ) ;
}
} else if ( V_11 -> V_52 . V_217 ) {
F_72 ( V_187 ,
( F_22 ( V_15 ) ?
V_30 : V_42 ) ) ;
} else {
F_72 ( V_187 , V_30 ) ;
}
if ( V_187 -> V_29 != V_42 )
V_187 -> V_115 = V_116 ;
F_56 ( V_19 , L_42 ,
V_187 -> V_29 == V_42 ? L_43 :
( V_187 -> V_29 == V_30 ? L_44 : L_45 ) ) ;
if ( F_35 ( V_11 ) && V_11 -> V_52 . V_108 [ 0 ] ) {
if ( strcmp ( V_11 -> V_52 . V_108 , V_187 -> V_16 -> V_59 ) == 0 ) {
F_78 ( V_11 -> V_101 , V_187 ) ;
V_11 -> V_103 = true ;
}
}
switch ( F_20 ( V_11 ) ) {
case V_4 :
F_76 ( V_187 ,
V_118 ) ;
break;
case V_7 :
F_76 ( V_187 , V_118 ) ;
if ( ! V_188 ) {
F_115 ( V_187 ) -> V_220 = 1 ;
F_146 ( V_11 , 1000 / V_221 ) ;
} else {
F_115 ( V_187 ) -> V_220 =
F_115 ( V_188 ) -> V_220 + 1 ;
}
F_147 ( V_187 ) ;
break;
case V_8 :
case V_9 :
F_148 ( V_187 ) ;
F_76 ( V_187 , V_118 ) ;
break;
default:
F_56 ( V_19 , L_46 ) ;
F_148 ( V_187 ) ;
if ( ! F_149 ( V_11 -> V_69 ) &&
V_187 -> V_29 == V_30 )
F_78 ( V_11 -> V_69 , V_187 ) ;
break;
}
#ifdef F_150
V_15 -> V_222 = V_11 -> V_16 -> V_222 ;
if ( V_15 -> V_222 ) {
if ( F_80 ( V_187 ) ) {
F_71 ( V_19 , L_47 ) ;
V_26 = - V_192 ;
goto V_223;
}
}
#endif
if ( ! ( V_19 -> V_131 & V_224 ) )
F_151 ( V_15 ) ;
V_26 = F_152 ( V_15 , F_99 ,
V_187 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_48 , V_26 ) ;
goto V_223;
}
V_26 = F_109 ( V_19 , V_15 , V_187 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_49 , V_26 ) ;
goto V_225;
}
V_26 = F_153 ( V_187 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_50 , V_26 ) ;
goto V_226;
}
V_11 -> V_176 ++ ;
F_92 ( V_11 ) ;
F_18 ( V_11 ) ;
if ( F_35 ( V_11 ) ) {
F_154 () ;
F_79 ( V_11 ) ;
F_155 () ;
}
if ( F_156 ( V_11 ) )
F_157 ( V_11 , NULL ) ;
F_71 ( V_19 , L_51 ,
V_15 -> V_59 ,
F_158 ( V_187 ) ? L_52 : L_53 ,
V_187 -> V_29 != V_42 ? L_54 : L_55 ) ;
F_126 ( V_187 ) ;
return 0 ;
V_226:
F_112 ( V_19 , V_15 ) ;
V_225:
F_159 ( V_15 ) ;
V_223:
if ( ! F_35 ( V_11 ) )
F_46 ( V_19 , V_15 ) ;
F_160 ( V_15 , V_19 ) ;
if ( F_149 ( V_11 -> V_101 ) == V_187 )
F_161 ( V_11 -> V_101 , NULL ) ;
if ( F_149 ( V_11 -> V_69 ) == V_187 ) {
F_154 () ;
F_69 ( V_11 , NULL ) ;
F_79 ( V_11 ) ;
F_155 () ;
}
F_162 () ;
F_84 ( V_187 ) ;
V_215:
V_15 -> V_151 &= ~ V_213 ;
F_163 ( V_15 ) ;
V_212:
if ( ! V_11 -> V_52 . V_94 ||
F_20 ( V_11 ) != V_4 ) {
F_58 ( V_189 . V_97 , V_187 -> V_210 ) ;
V_189 . V_98 = V_15 -> type ;
F_59 ( V_15 , & V_189 ) ;
}
V_211:
F_136 ( V_15 , V_187 -> V_207 ) ;
V_209:
F_116 ( V_187 ) ;
V_196:
if ( ! F_19 ( V_11 ) &&
F_164 ( V_19 -> V_86 , V_15 -> V_86 ) )
F_165 ( V_19 ) ;
return V_26 ;
}
static int F_166 ( struct V_14 * V_19 ,
struct V_14 * V_15 ,
bool V_227 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_228 ;
struct V_91 V_189 ;
int V_229 = V_19 -> V_82 ;
T_6 V_230 = V_19 -> V_131 ;
if ( ! ( V_15 -> V_82 & V_169 ) ||
! F_167 ( V_15 , V_19 ) ) {
F_56 ( V_19 , L_56 ,
V_15 -> V_59 ) ;
return - V_201 ;
}
F_154 () ;
V_22 = F_8 ( V_11 , V_15 ) ;
if ( ! V_22 ) {
F_71 ( V_19 , L_57 ,
V_15 -> V_59 ) ;
F_155 () ;
return - V_201 ;
}
F_168 ( V_22 ) ;
F_169 ( V_11 -> V_16 , & V_11 -> V_231 ) ;
F_112 ( V_19 , V_15 ) ;
F_159 ( V_15 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_170 ( V_22 ) ;
if ( F_156 ( V_11 ) )
F_157 ( V_11 , V_22 ) ;
F_71 ( V_19 , L_58 ,
F_158 ( V_22 ) ? L_59 : L_60 ,
V_15 -> V_59 ) ;
V_228 = F_149 ( V_11 -> V_69 ) ;
F_161 ( V_11 -> V_232 , NULL ) ;
if ( ! V_227 && ( ! V_11 -> V_52 . V_94 ||
F_20 ( V_11 ) != V_4 ) ) {
if ( F_164 ( V_19 -> V_86 , V_22 -> V_210 ) &&
F_19 ( V_11 ) )
F_130 ( V_19 , L_61 ,
V_15 -> V_59 , V_22 -> V_210 ,
V_19 -> V_59 , V_15 -> V_59 ) ;
}
if ( F_36 ( V_11 -> V_101 ) == V_22 )
F_161 ( V_11 -> V_101 , NULL ) ;
if ( V_228 == V_22 )
F_69 ( V_11 , NULL ) ;
if ( F_16 ( V_11 ) ) {
F_171 ( V_11 , V_22 ) ;
}
if ( V_227 ) {
F_161 ( V_11 -> V_69 , NULL ) ;
} else if ( V_228 == V_22 ) {
F_79 ( V_11 ) ;
}
if ( ! F_19 ( V_11 ) ) {
F_18 ( V_11 ) ;
F_165 ( V_19 ) ;
}
F_155 () ;
F_162 () ;
V_11 -> V_176 -- ;
if ( ! F_19 ( V_11 ) ) {
F_44 ( V_89 , V_11 -> V_16 ) ;
F_44 ( V_233 , V_11 -> V_16 ) ;
}
F_92 ( V_11 ) ;
if ( ! ( V_19 -> V_131 & V_194 ) &&
( V_230 & V_194 ) )
F_71 ( V_19 , L_62 ,
V_15 -> V_59 , V_19 -> V_59 ) ;
F_160 ( V_15 , V_19 ) ;
if ( ! F_35 ( V_11 ) ) {
if ( V_229 & V_83 )
F_37 ( V_15 , - 1 ) ;
if ( V_229 & V_84 )
F_39 ( V_15 , - 1 ) ;
F_46 ( V_19 , V_15 ) ;
}
F_84 ( V_22 ) ;
F_163 ( V_15 ) ;
if ( V_11 -> V_52 . V_94 != V_95 ||
F_20 ( V_11 ) != V_4 ) {
F_58 ( V_189 . V_97 , V_22 -> V_210 ) ;
V_189 . V_98 = V_15 -> type ;
F_59 ( V_15 , & V_189 ) ;
}
F_136 ( V_15 , V_22 -> V_207 ) ;
V_15 -> V_151 &= ~ V_213 ;
F_116 ( V_22 ) ;
return 0 ;
}
int F_172 ( struct V_14 * V_19 , struct V_14 * V_15 )
{
return F_166 ( V_19 , V_15 , false ) ;
}
static int F_173 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
int V_160 ;
V_160 = F_172 ( V_19 , V_15 ) ;
if ( V_160 == 0 && ! F_19 ( V_11 ) ) {
V_19 -> V_151 |= V_234 ;
F_71 ( V_19 , L_63 ,
V_19 -> V_59 ) ;
F_174 ( V_19 ) ;
}
return V_160 ;
}
static int F_175 ( struct V_14 * V_19 , struct V_172 * V_173 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_118 ( V_11 , V_173 ) ;
return 0 ;
}
static int F_176 ( struct V_14 * V_19 , struct V_177 * V_173 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
int V_191 = 0 , V_26 = - V_235 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
if ( V_191 ++ == ( int ) V_173 -> V_236 ) {
V_26 = 0 ;
F_119 ( V_22 , V_173 ) ;
break;
}
}
return V_26 ;
}
static int F_177 ( struct V_10 * V_11 )
{
int V_237 , V_238 = 0 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
bool V_239 ;
V_239 = ! F_66 ( V_11 -> V_69 ) ;
F_178 (bond, slave, iter) {
V_22 -> V_240 = V_241 ;
V_237 = F_29 ( V_11 , V_22 -> V_16 , 0 ) ;
switch ( V_22 -> V_29 ) {
case V_30 :
if ( V_237 )
continue;
F_72 ( V_22 , V_41 ) ;
V_22 -> V_111 = V_11 -> V_52 . V_242 ;
if ( V_22 -> V_111 ) {
F_71 ( V_11 -> V_16 , L_64 ,
( F_20 ( V_11 ) ==
V_4 ) ?
( F_158 ( V_22 ) ?
L_65 : L_66 ) : L_67 ,
V_22 -> V_16 -> V_59 ,
V_11 -> V_52 . V_242 * V_11 -> V_52 . V_117 ) ;
}
case V_41 :
if ( V_237 ) {
F_72 ( V_22 , V_30 ) ;
V_22 -> V_115 = V_116 ;
F_71 ( V_11 -> V_16 , L_68 ,
( V_11 -> V_52 . V_242 - V_22 -> V_111 ) *
V_11 -> V_52 . V_117 ,
V_22 -> V_16 -> V_59 ) ;
continue;
}
if ( V_22 -> V_111 <= 0 ) {
V_22 -> V_240 = V_42 ;
V_238 ++ ;
continue;
}
V_22 -> V_111 -- ;
break;
case V_42 :
if ( ! V_237 )
continue;
F_72 ( V_22 , V_43 ) ;
V_22 -> V_111 = V_11 -> V_52 . V_110 ;
if ( V_22 -> V_111 ) {
F_71 ( V_11 -> V_16 , L_69 ,
V_22 -> V_16 -> V_59 ,
V_239 ? 0 :
V_11 -> V_52 . V_110 *
V_11 -> V_52 . V_117 ) ;
}
case V_43 :
if ( ! V_237 ) {
F_72 ( V_22 ,
V_42 ) ;
F_71 ( V_11 -> V_16 , L_70 ,
( V_11 -> V_52 . V_110 - V_22 -> V_111 ) *
V_11 -> V_52 . V_117 ,
V_22 -> V_16 -> V_59 ) ;
continue;
}
if ( V_239 )
V_22 -> V_111 = 0 ;
if ( V_22 -> V_111 <= 0 ) {
V_22 -> V_240 = V_30 ;
V_238 ++ ;
V_239 = false ;
continue;
}
V_22 -> V_111 -- ;
break;
}
}
return V_238 ;
}
static void F_179 ( struct V_10 * V_11 )
{
struct V_24 * V_25 ;
struct V_22 * V_22 , * V_108 ;
F_12 (bond, slave, iter) {
switch ( V_22 -> V_240 ) {
case V_241 :
continue;
case V_30 :
F_72 ( V_22 , V_30 ) ;
V_22 -> V_115 = V_116 ;
V_108 = F_36 ( V_11 -> V_101 ) ;
if ( F_20 ( V_11 ) == V_7 ) {
F_180 ( V_22 ) ;
} else if ( F_20 ( V_11 ) != V_4 ) {
F_148 ( V_22 ) ;
} else if ( V_22 != V_108 ) {
F_180 ( V_22 ) ;
}
F_71 ( V_11 -> V_16 , L_71 ,
V_22 -> V_16 -> V_59 ,
V_22 -> V_34 == V_35 ? 0 : V_22 -> V_34 ,
V_22 -> V_36 ? L_72 : L_73 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_73 ( V_22 , V_30 ) ;
if ( F_16 ( V_11 ) )
F_74 ( V_11 , V_22 ,
V_30 ) ;
if ( F_20 ( V_11 ) == V_5 )
F_157 ( V_11 , NULL ) ;
if ( ! V_11 -> V_69 || V_22 == V_108 )
goto V_243;
continue;
case V_42 :
if ( V_22 -> V_179 < V_244 )
V_22 -> V_179 ++ ;
F_72 ( V_22 , V_42 ) ;
if ( F_20 ( V_11 ) == V_4 ||
F_20 ( V_11 ) == V_7 )
F_76 ( V_22 ,
V_118 ) ;
F_71 ( V_11 -> V_16 , L_74 ,
V_22 -> V_16 -> V_59 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_73 ( V_22 ,
V_42 ) ;
if ( F_16 ( V_11 ) )
F_74 ( V_11 , V_22 ,
V_42 ) ;
if ( F_20 ( V_11 ) == V_5 )
F_157 ( V_11 , NULL ) ;
if ( V_22 == F_149 ( V_11 -> V_69 ) )
goto V_243;
continue;
default:
F_60 ( V_11 -> V_16 , L_75 ,
V_22 -> V_240 , V_22 -> V_16 -> V_59 ) ;
V_22 -> V_240 = V_241 ;
continue;
}
V_243:
F_154 () ;
F_79 ( V_11 ) ;
F_155 () ;
}
F_18 ( V_11 ) ;
}
static void F_181 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_41 ( V_71 , struct V_10 ,
V_245 . V_71 ) ;
bool V_119 = false ;
unsigned long V_111 ;
V_111 = F_145 ( V_11 -> V_52 . V_117 ) ;
if ( ! F_19 ( V_11 ) )
goto V_246;
F_65 () ;
V_119 = F_64 ( V_11 ) ;
if ( F_177 ( V_11 ) ) {
F_67 () ;
if ( ! F_42 () ) {
V_111 = 1 ;
V_119 = false ;
goto V_246;
}
F_179 ( V_11 ) ;
F_45 () ;
} else
F_67 () ;
V_246:
if ( V_11 -> V_52 . V_117 )
F_43 ( V_11 -> V_73 , & V_11 -> V_245 , V_111 ) ;
if ( V_119 ) {
if ( ! F_42 () )
return;
F_44 ( V_122 , V_11 -> V_16 ) ;
F_45 () ;
}
}
static bool F_182 ( struct V_10 * V_11 , T_8 V_247 )
{
struct V_14 * V_248 ;
struct V_24 * V_25 ;
bool V_160 = false ;
if ( V_247 == F_183 ( V_11 -> V_16 , 0 , V_247 ) )
return true ;
F_65 () ;
F_184 (bond->dev, upper, iter) {
if ( V_247 == F_183 ( V_248 , 0 , V_247 ) ) {
V_160 = true ;
break;
}
}
F_67 () ;
return V_160 ;
}
static void F_185 ( struct V_14 * V_15 , int V_249 ,
T_8 V_250 , T_8 V_251 ,
struct V_252 * V_253 )
{
struct V_12 * V_13 ;
struct V_252 * V_254 = V_253 ;
F_56 ( V_15 , L_76 ,
V_249 , V_15 -> V_59 , & V_250 , & V_251 ) ;
V_13 = F_186 ( V_249 , V_255 , V_250 , V_15 , V_251 ,
NULL , V_15 -> V_86 , NULL ) ;
if ( ! V_13 ) {
F_187 ( L_77 ) ;
return;
}
if ( ! V_253 || V_253 -> V_256 == V_257 )
goto V_258;
V_253 ++ ;
while ( V_253 -> V_256 != V_257 ) {
if ( ! V_253 -> V_259 ) {
V_253 ++ ;
continue;
}
F_56 ( V_15 , L_78 ,
F_188 ( V_254 -> V_256 ) , V_253 -> V_259 ) ;
V_13 = F_189 ( V_13 , V_253 -> V_256 ,
V_253 -> V_259 ) ;
if ( ! V_13 ) {
F_187 ( L_79 ) ;
return;
}
V_253 ++ ;
}
if ( V_254 -> V_259 ) {
F_56 ( V_15 , L_80 ,
F_188 ( V_254 -> V_256 ) , V_254 -> V_259 ) ;
F_190 ( V_13 , V_254 -> V_256 ,
V_254 -> V_259 ) ;
}
V_258:
F_191 ( V_13 ) ;
}
struct V_252 * F_192 ( struct V_14 * V_260 ,
struct V_14 * V_261 ,
int V_262 )
{
struct V_252 * V_253 ;
struct V_14 * V_248 ;
struct V_24 * V_25 ;
if ( V_260 == V_261 ) {
V_253 = F_81 ( sizeof( * V_253 ) * ( V_262 + 1 ) , V_162 ) ;
if ( ! V_253 )
return F_193 ( - V_128 ) ;
V_253 [ V_262 ] . V_256 = V_257 ;
return V_253 ;
}
F_194 (start_dev, upper, iter) {
V_253 = F_192 ( V_248 , V_261 , V_262 + 1 ) ;
if ( F_195 ( V_253 ) ) {
if ( F_196 ( V_253 ) )
return V_253 ;
continue;
}
if ( F_197 ( V_248 ) ) {
V_253 [ V_262 ] . V_256 = F_198 ( V_248 ) ;
V_253 [ V_262 ] . V_259 = F_199 ( V_248 ) ;
}
return V_253 ;
}
return NULL ;
}
static void F_200 ( struct V_10 * V_11 , struct V_22 * V_22 )
{
struct V_263 * V_264 ;
struct V_252 * V_253 ;
T_8 * V_265 = V_11 -> V_52 . V_266 , V_189 ;
int V_191 ;
for ( V_191 = 0 ; V_191 < V_218 && V_265 [ V_191 ] ; V_191 ++ ) {
F_56 ( V_11 -> V_16 , L_81 , & V_265 [ V_191 ] ) ;
V_253 = NULL ;
V_264 = F_201 ( F_202 ( V_11 -> V_16 ) , V_265 [ V_191 ] , 0 ,
V_267 , 0 ) ;
if ( F_196 ( V_264 ) ) {
if ( V_11 -> V_52 . V_268 )
F_203 ( L_82 ,
V_11 -> V_16 -> V_59 ,
& V_265 [ V_191 ] ) ;
F_185 ( V_22 -> V_16 , V_269 , V_265 [ V_191 ] ,
0 , V_253 ) ;
continue;
}
if ( V_264 -> V_270 . V_16 == V_11 -> V_16 )
goto V_271;
F_65 () ;
V_253 = F_192 ( V_11 -> V_16 , V_264 -> V_270 . V_16 , 0 ) ;
F_67 () ;
if ( ! F_195 ( V_253 ) )
goto V_271;
F_56 ( V_11 -> V_16 , L_83 ,
& V_265 [ V_191 ] , V_264 -> V_270 . V_16 ? V_264 -> V_270 . V_16 -> V_59 : L_17 ) ;
F_204 ( V_264 ) ;
continue;
V_271:
V_189 = F_183 ( V_264 -> V_270 . V_16 , V_265 [ V_191 ] , 0 ) ;
F_204 ( V_264 ) ;
F_185 ( V_22 -> V_16 , V_269 , V_265 [ V_191 ] ,
V_189 , V_253 ) ;
F_83 ( V_253 ) ;
}
}
static void F_205 ( struct V_10 * V_11 , struct V_22 * V_22 , T_8 V_272 , T_8 V_273 )
{
int V_191 ;
if ( ! V_272 || ! F_182 ( V_11 , V_273 ) ) {
F_56 ( V_11 -> V_16 , L_84 ,
& V_272 , & V_273 ) ;
return;
}
V_191 = F_206 ( V_11 -> V_52 . V_266 , V_272 ) ;
if ( V_191 == - 1 ) {
F_56 ( V_11 -> V_16 , L_85 ,
& V_272 ) ;
return;
}
V_22 -> V_216 = V_116 ;
V_22 -> V_219 [ V_191 ] = V_116 ;
}
int F_207 ( const struct V_12 * V_13 , struct V_10 * V_11 ,
struct V_22 * V_22 )
{
struct V_274 * V_275 = (struct V_274 * ) V_13 -> V_167 ;
struct V_22 * V_69 ;
unsigned char * V_276 ;
T_8 V_272 , V_273 ;
int V_277 , V_278 = V_13 -> V_279 == F_208 ( V_255 ) ;
if ( ! F_209 ( V_11 , V_22 ) ) {
if ( ( F_210 ( V_11 ) && V_278 ) ||
! F_210 ( V_11 ) )
V_22 -> V_216 = V_116 ;
return V_161 ;
} else if ( ! V_278 ) {
return V_161 ;
}
V_277 = F_211 ( V_11 -> V_16 ) ;
F_56 ( V_11 -> V_16 , L_86 ,
V_13 -> V_16 -> V_59 ) ;
if ( V_277 > F_212 ( V_13 ) ) {
V_275 = F_213 ( V_277 , V_162 ) ;
if ( ! V_275 )
goto V_280;
if ( F_214 ( V_13 , 0 , V_275 , V_277 ) < 0 )
goto V_280;
}
if ( V_275 -> V_281 != V_11 -> V_16 -> V_85 ||
V_13 -> V_156 == V_282 ||
V_13 -> V_156 == V_283 ||
V_275 -> V_284 != F_215 ( V_198 ) ||
V_275 -> V_285 != F_215 ( V_286 ) ||
V_275 -> V_287 != 4 )
goto V_280;
V_276 = ( unsigned char * ) ( V_275 + 1 ) ;
V_276 += V_11 -> V_16 -> V_85 ;
memcpy ( & V_272 , V_276 , 4 ) ;
V_276 += 4 + V_11 -> V_16 -> V_85 ;
memcpy ( & V_273 , V_276 , 4 ) ;
F_56 ( V_11 -> V_16 , L_87 ,
V_22 -> V_16 -> V_59 , F_120 ( V_22 ) ,
V_11 -> V_52 . V_268 , F_209 ( V_11 , V_22 ) ,
& V_272 , & V_273 ) ;
V_69 = F_66 ( V_11 -> V_69 ) ;
if ( F_158 ( V_22 ) )
F_205 ( V_11 , V_22 , V_272 , V_273 ) ;
else if ( V_69 &&
F_216 ( F_217 ( V_11 , V_69 ) ,
V_69 -> V_115 ) )
F_205 ( V_11 , V_22 , V_273 , V_272 ) ;
V_280:
if ( V_275 != (struct V_274 * ) V_13 -> V_167 )
F_83 ( V_275 ) ;
return V_161 ;
}
static bool F_218 ( struct V_10 * V_11 , unsigned long V_288 ,
int V_289 )
{
int V_290 = F_145 ( V_11 -> V_52 . V_217 ) ;
return F_219 ( V_116 ,
V_288 - V_290 ,
V_288 + V_289 * V_290 + V_290 / 2 ) ;
}
static void F_220 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_41 ( V_71 , struct V_10 ,
V_291 . V_71 ) ;
struct V_22 * V_22 , * V_228 ;
struct V_24 * V_25 ;
int V_243 = 0 , V_292 = 0 ;
if ( ! F_19 ( V_11 ) )
goto V_246;
F_65 () ;
V_228 = F_66 ( V_11 -> V_69 ) ;
F_178 (bond, slave, iter) {
unsigned long V_293 = F_221 ( V_22 -> V_16 ) ;
if ( V_22 -> V_29 != V_30 ) {
if ( F_218 ( V_11 , V_293 , 1 ) &&
F_218 ( V_11 , V_22 -> V_216 , 1 ) ) {
V_22 -> V_29 = V_30 ;
V_292 = 1 ;
if ( ! V_228 ) {
F_71 ( V_11 -> V_16 , L_88 ,
V_22 -> V_16 -> V_59 ) ;
V_243 = 1 ;
} else {
F_71 ( V_11 -> V_16 , L_89 ,
V_22 -> V_16 -> V_59 ) ;
}
}
} else {
if ( ! F_218 ( V_11 , V_293 , 2 ) ||
! F_218 ( V_11 , V_22 -> V_216 , 2 ) ) {
V_22 -> V_29 = V_42 ;
V_292 = 1 ;
if ( V_22 -> V_179 < V_244 )
V_22 -> V_179 ++ ;
F_71 ( V_11 -> V_16 , L_90 ,
V_22 -> V_16 -> V_59 ) ;
if ( V_22 == V_228 )
V_243 = 1 ;
}
}
if ( F_63 ( V_22 ) )
F_200 ( V_11 , V_22 ) ;
}
F_67 () ;
if ( V_243 || V_292 ) {
if ( ! F_42 () )
goto V_246;
if ( V_292 ) {
F_222 ( V_11 ) ;
if ( F_20 ( V_11 ) == V_5 )
F_157 ( V_11 , NULL ) ;
}
if ( V_243 ) {
F_154 () ;
F_79 ( V_11 ) ;
F_155 () ;
}
F_45 () ;
}
V_246:
if ( V_11 -> V_52 . V_217 )
F_43 ( V_11 -> V_73 , & V_11 -> V_291 ,
F_145 ( V_11 -> V_52 . V_217 ) ) ;
}
static int F_223 ( struct V_10 * V_11 )
{
unsigned long V_293 , V_216 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_238 = 0 ;
F_178 (bond, slave, iter) {
V_22 -> V_240 = V_241 ;
V_216 = F_217 ( V_11 , V_22 ) ;
if ( V_22 -> V_29 != V_30 ) {
if ( F_218 ( V_11 , V_216 , 1 ) ) {
V_22 -> V_240 = V_30 ;
V_238 ++ ;
}
continue;
}
if ( F_218 ( V_11 , V_22 -> V_115 , 2 ) )
continue;
if ( ! F_158 ( V_22 ) &&
! F_149 ( V_11 -> V_232 ) &&
! F_218 ( V_11 , V_216 , 3 ) ) {
V_22 -> V_240 = V_42 ;
V_238 ++ ;
}
V_293 = F_221 ( V_22 -> V_16 ) ;
if ( F_158 ( V_22 ) &&
( ! F_218 ( V_11 , V_293 , 2 ) ||
! F_218 ( V_11 , V_216 , 2 ) ) ) {
V_22 -> V_240 = V_42 ;
V_238 ++ ;
}
}
return V_238 ;
}
static void F_224 ( struct V_10 * V_11 )
{
unsigned long V_293 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
switch ( V_22 -> V_240 ) {
case V_241 :
continue;
case V_30 :
V_293 = F_221 ( V_22 -> V_16 ) ;
if ( F_36 ( V_11 -> V_69 ) != V_22 ||
( ! F_36 ( V_11 -> V_69 ) &&
F_218 ( V_11 , V_293 , 1 ) ) ) {
struct V_22 * V_232 ;
V_232 = F_36 ( V_11 -> V_232 ) ;
F_72 ( V_22 , V_30 ) ;
if ( V_232 ) {
F_76 (
V_232 ,
V_118 ) ;
F_161 ( V_11 -> V_232 , NULL ) ;
}
F_71 ( V_11 -> V_16 , L_88 ,
V_22 -> V_16 -> V_59 ) ;
if ( ! F_36 ( V_11 -> V_69 ) ||
V_22 == F_36 ( V_11 -> V_101 ) )
goto V_243;
}
continue;
case V_42 :
if ( V_22 -> V_179 < V_244 )
V_22 -> V_179 ++ ;
F_72 ( V_22 , V_42 ) ;
F_76 ( V_22 ,
V_118 ) ;
F_71 ( V_11 -> V_16 , L_74 ,
V_22 -> V_16 -> V_59 ) ;
if ( V_22 == F_36 ( V_11 -> V_69 ) ) {
F_161 ( V_11 -> V_232 , NULL ) ;
goto V_243;
}
continue;
default:
F_60 ( V_11 -> V_16 , L_91 ,
V_22 -> V_240 , V_22 -> V_16 -> V_59 ) ;
continue;
}
V_243:
F_154 () ;
F_79 ( V_11 ) ;
F_155 () ;
}
F_18 ( V_11 ) ;
}
static bool F_225 ( struct V_10 * V_11 )
{
struct V_22 * V_22 , * V_294 = NULL , * V_187 = NULL ,
* V_295 = F_66 ( V_11 -> V_232 ) ,
* V_69 = F_66 ( V_11 -> V_69 ) ;
struct V_24 * V_25 ;
bool V_271 = false ;
bool V_296 = V_297 ;
if ( V_295 && V_69 )
F_71 ( V_11 -> V_16 , L_92 ,
V_295 -> V_16 -> V_59 ,
V_69 -> V_16 -> V_59 ) ;
if ( V_69 ) {
F_200 ( V_11 , V_69 ) ;
return V_296 ;
}
if ( ! V_295 ) {
V_295 = F_226 ( V_11 ) ;
if ( ! V_295 )
return V_296 ;
}
F_76 ( V_295 , V_297 ) ;
F_178 (bond, slave, iter) {
if ( ! V_271 && ! V_294 && F_63 ( V_22 ) )
V_294 = V_22 ;
if ( V_271 && ! V_187 && F_63 ( V_22 ) )
V_187 = V_22 ;
if ( ! F_63 ( V_22 ) && V_22 -> V_29 == V_30 ) {
F_72 ( V_22 , V_42 ) ;
if ( V_22 -> V_179 < V_244 )
V_22 -> V_179 ++ ;
F_76 ( V_22 ,
V_297 ) ;
F_71 ( V_11 -> V_16 , L_93 ,
V_22 -> V_16 -> V_59 ) ;
}
if ( V_22 == V_295 )
V_271 = true ;
}
if ( ! V_187 && V_294 )
V_187 = V_294 ;
if ( ! V_187 )
goto V_298;
F_72 ( V_187 , V_43 ) ;
F_77 ( V_187 , V_297 ) ;
F_200 ( V_11 , V_187 ) ;
V_187 -> V_115 = V_116 ;
F_78 ( V_11 -> V_232 , V_187 ) ;
V_298:
F_178 (bond, slave, iter) {
if ( V_22 -> V_299 ) {
V_296 = V_118 ;
break;
}
}
return V_296 ;
}
static void F_227 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_41 ( V_71 , struct V_10 ,
V_291 . V_71 ) ;
bool V_119 = false ;
bool V_296 = false ;
int V_290 ;
V_290 = F_145 ( V_11 -> V_52 . V_217 ) ;
if ( ! F_19 ( V_11 ) )
goto V_246;
F_65 () ;
V_119 = F_64 ( V_11 ) ;
if ( F_223 ( V_11 ) ) {
F_67 () ;
if ( ! F_42 () ) {
V_290 = 1 ;
V_119 = false ;
goto V_246;
}
F_224 ( V_11 ) ;
F_45 () ;
F_65 () ;
}
V_296 = F_225 ( V_11 ) ;
F_67 () ;
V_246:
if ( V_11 -> V_52 . V_217 )
F_43 ( V_11 -> V_73 , & V_11 -> V_291 , V_290 ) ;
if ( V_119 || V_296 ) {
if ( ! F_42 () )
return;
if ( V_119 )
F_44 ( V_122 ,
V_11 -> V_16 ) ;
if ( V_296 )
F_228 ( V_11 ) ;
F_45 () ;
}
}
static int F_229 ( struct V_10 * V_11 )
{
F_230 ( V_11 ) ;
F_231 ( V_11 ) ;
F_232 ( V_11 ) ;
return V_300 ;
}
static int F_233 ( unsigned long V_301 ,
struct V_14 * V_19 )
{
struct V_10 * V_302 = F_11 ( V_19 ) ;
switch ( V_301 ) {
case V_303 :
return F_229 ( V_302 ) ;
case V_304 :
F_230 ( V_302 ) ;
break;
case V_305 :
F_231 ( V_302 ) ;
break;
case V_122 :
if ( V_302 -> V_112 )
V_302 -> V_112 -- ;
break;
default:
break;
}
return V_300 ;
}
static int F_234 ( unsigned long V_301 ,
struct V_14 * V_15 )
{
struct V_22 * V_22 = F_235 ( V_15 ) , * V_108 ;
struct V_10 * V_11 ;
struct V_14 * V_19 ;
T_3 V_306 ;
T_5 V_307 ;
if ( ! V_22 )
return V_300 ;
V_19 = V_22 -> V_11 -> V_16 ;
V_11 = V_22 -> V_11 ;
V_108 = F_36 ( V_11 -> V_101 ) ;
switch ( V_301 ) {
case V_304 :
if ( V_19 -> type != V_198 )
F_173 ( V_19 , V_15 ) ;
else
F_172 ( V_19 , V_15 ) ;
break;
case V_308 :
case V_309 :
V_306 = V_22 -> V_34 ;
V_307 = V_22 -> V_36 ;
F_25 ( V_22 ) ;
if ( F_20 ( V_11 ) == V_7 ) {
if ( V_306 != V_22 -> V_34 )
F_236 ( V_22 ) ;
if ( V_307 != V_22 -> V_36 )
F_237 ( V_22 ) ;
}
if ( F_156 ( V_11 ) )
F_157 ( V_11 , NULL ) ;
break;
case V_310 :
if ( F_156 ( V_11 ) )
F_157 ( V_11 , NULL ) ;
break;
case V_311 :
break;
case V_303 :
if ( ! F_35 ( V_11 ) ||
! V_11 -> V_52 . V_108 [ 0 ] )
break;
if ( V_22 == V_108 ) {
F_161 ( V_11 -> V_101 , NULL ) ;
} else if ( ! strcmp ( V_15 -> V_59 , V_11 -> V_52 . V_108 ) ) {
F_78 ( V_11 -> V_101 , V_22 ) ;
} else {
break;
}
F_71 ( V_11 -> V_16 , L_94 ,
V_108 ? V_15 -> V_59 : L_95 ) ;
F_154 () ;
F_79 ( V_11 ) ;
F_155 () ;
break;
case V_312 :
F_92 ( V_11 ) ;
break;
case V_74 :
F_44 ( V_301 , V_22 -> V_11 -> V_16 ) ;
break;
default:
break;
}
return V_300 ;
}
static int F_238 ( struct V_313 * V_314 ,
unsigned long V_301 , void * V_315 )
{
struct V_14 * V_316 = F_239 ( V_315 ) ;
F_56 ( V_316 , L_96 , V_301 ) ;
if ( ! ( V_316 -> V_151 & V_213 ) )
return V_300 ;
if ( V_316 -> V_82 & V_317 ) {
F_56 ( V_316 , L_97 ) ;
return F_233 ( V_301 , V_316 ) ;
}
if ( V_316 -> V_82 & V_169 ) {
F_56 ( V_316 , L_98 ) ;
return F_234 ( V_301 , V_316 ) ;
}
return V_300 ;
}
static inline T_3 F_240 ( struct V_12 * V_13 )
{
struct V_318 * V_319 , V_320 ;
V_319 = F_241 ( V_13 , 0 , sizeof( V_320 ) , & V_320 ) ;
if ( V_319 )
return V_319 -> V_168 [ 5 ] ^ V_319 -> V_321 [ 5 ] ^ V_319 -> V_322 ;
return 0 ;
}
static bool F_242 ( struct V_10 * V_11 , struct V_12 * V_13 ,
struct V_323 * V_324 )
{
const struct V_325 * V_326 ;
const struct V_327 * V_328 ;
int V_329 , V_20 = - 1 ;
if ( V_11 -> V_52 . V_330 > V_331 )
return F_243 ( V_13 , V_324 ) ;
V_324 -> V_332 = 0 ;
V_329 = F_244 ( V_13 ) ;
if ( V_13 -> V_279 == F_215 ( V_286 ) ) {
if ( F_5 ( ! F_245 ( V_13 , V_329 + sizeof( * V_328 ) ) ) )
return false ;
V_328 = F_246 ( V_13 ) ;
V_324 -> V_333 = V_328 -> V_92 ;
V_324 -> V_270 = V_328 -> V_334 ;
V_329 += V_328 -> V_335 << 2 ;
if ( ! F_247 ( V_328 ) )
V_20 = V_328 -> V_279 ;
} else if ( V_13 -> V_279 == F_215 ( V_336 ) ) {
if ( F_5 ( ! F_245 ( V_13 , V_329 + sizeof( * V_326 ) ) ) )
return false ;
V_326 = F_248 ( V_13 ) ;
V_324 -> V_333 = ( V_337 T_8 ) F_249 ( & V_326 -> V_92 ) ;
V_324 -> V_270 = ( V_337 T_8 ) F_249 ( & V_326 -> V_334 ) ;
V_329 += sizeof( * V_326 ) ;
V_20 = V_326 -> V_338 ;
} else {
return false ;
}
if ( V_11 -> V_52 . V_330 == V_339 && V_20 >= 0 )
V_324 -> V_332 = F_250 ( V_13 , V_329 , V_20 ) ;
return true ;
}
T_3 F_251 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
struct V_323 V_340 ;
T_3 V_341 ;
if ( V_11 -> V_52 . V_330 == V_342 ||
! F_242 ( V_11 , V_13 , & V_340 ) )
return F_240 ( V_13 ) ;
if ( V_11 -> V_52 . V_330 == V_331 ||
V_11 -> V_52 . V_330 == V_343 )
V_341 = F_240 ( V_13 ) ;
else
V_341 = ( V_337 T_3 ) V_340 . V_332 ;
V_341 ^= ( V_337 T_3 ) V_340 . V_270 ^ ( V_337 T_3 ) V_340 . V_333 ;
V_341 ^= ( V_341 >> 16 ) ;
V_341 ^= ( V_341 >> 8 ) ;
return V_341 ;
}
static void F_252 ( struct V_10 * V_11 )
{
F_128 ( & V_11 -> V_72 ,
F_40 ) ;
F_128 ( & V_11 -> V_344 , V_345 ) ;
F_128 ( & V_11 -> V_245 , F_181 ) ;
if ( F_20 ( V_11 ) == V_4 )
F_128 ( & V_11 -> V_291 , F_227 ) ;
else
F_128 ( & V_11 -> V_291 , F_220 ) ;
F_128 ( & V_11 -> V_346 , V_347 ) ;
F_128 ( & V_11 -> V_348 , V_349 ) ;
}
static void F_253 ( struct V_10 * V_11 )
{
F_254 ( & V_11 -> V_245 ) ;
F_254 ( & V_11 -> V_291 ) ;
F_254 ( & V_11 -> V_344 ) ;
F_254 ( & V_11 -> V_346 ) ;
F_254 ( & V_11 -> V_72 ) ;
F_254 ( & V_11 -> V_348 ) ;
}
static int F_255 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
if ( F_19 ( V_11 ) ) {
F_12 (bond, slave, iter) {
if ( F_35 ( V_11 ) &&
V_22 != F_149 ( V_11 -> V_69 ) ) {
F_76 ( V_22 ,
V_118 ) ;
} else if ( F_20 ( V_11 ) != V_7 ) {
F_77 ( V_22 ,
V_118 ) ;
}
}
}
F_252 ( V_11 ) ;
if ( F_16 ( V_11 ) ) {
if ( F_256 ( V_11 , ( F_20 ( V_11 ) == V_9 ) ) )
return - V_128 ;
if ( V_11 -> V_52 . V_350 )
F_43 ( V_11 -> V_73 , & V_11 -> V_344 , 0 ) ;
}
if ( V_11 -> V_52 . V_117 )
F_43 ( V_11 -> V_73 , & V_11 -> V_245 , 0 ) ;
if ( V_11 -> V_52 . V_217 ) {
F_43 ( V_11 -> V_73 , & V_11 -> V_291 , 0 ) ;
V_11 -> F_100 = F_207 ;
}
if ( F_20 ( V_11 ) == V_7 ) {
F_43 ( V_11 -> V_73 , & V_11 -> V_346 , 0 ) ;
V_11 -> F_100 = V_351 ;
F_257 ( V_11 , 1 ) ;
}
if ( F_156 ( V_11 ) )
F_157 ( V_11 , NULL ) ;
return 0 ;
}
static int F_258 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_253 ( V_11 ) ;
V_11 -> V_112 = 0 ;
if ( F_16 ( V_11 ) )
F_259 ( V_11 ) ;
V_11 -> F_100 = NULL ;
return 0 ;
}
static struct V_352 * F_169 ( struct V_14 * V_19 ,
struct V_352 * V_353 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_352 V_354 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
memcpy ( V_353 , & V_11 -> V_231 , sizeof( * V_353 ) ) ;
F_12 (bond, slave, iter) {
const struct V_352 * V_355 =
F_138 ( V_22 -> V_16 , & V_354 ) ;
struct V_352 * V_356 = & V_22 -> V_214 ;
V_353 -> V_357 += V_355 -> V_357 - V_356 -> V_357 ;
V_353 -> V_358 += V_355 -> V_358 - V_356 -> V_358 ;
V_353 -> V_359 += V_355 -> V_359 - V_356 -> V_359 ;
V_353 -> V_360 += V_355 -> V_360 - V_356 -> V_360 ;
V_353 -> V_361 += V_355 -> V_361 - V_356 -> V_361 ; ;
V_353 -> V_362 += V_355 -> V_362 - V_356 -> V_362 ;
V_353 -> V_363 += V_355 -> V_363 - V_356 -> V_363 ;
V_353 -> V_364 += V_355 -> V_364 - V_356 -> V_364 ;
V_353 -> V_365 += V_355 -> V_365 - V_356 -> V_365 ;
V_353 -> V_366 += V_355 -> V_366 - V_356 -> V_366 ;
V_353 -> V_367 += V_355 -> V_367 - V_356 -> V_367 ;
V_353 -> V_368 += V_355 -> V_368 - V_356 -> V_368 ;
V_353 -> V_369 += V_355 -> V_369 - V_356 -> V_369 ;
V_353 -> V_370 += V_355 -> V_370 - V_356 -> V_370 ;
V_353 -> V_371 += V_355 -> V_371 - V_356 -> V_371 ;
V_353 -> V_372 += V_355 -> V_372 - V_356 -> V_372 ;
V_353 -> V_373 += V_355 -> V_373 - V_356 -> V_373 ;
V_353 -> V_374 += V_355 -> V_374 - V_356 -> V_374 ;
V_353 -> V_375 += V_355 -> V_375 - V_356 -> V_375 ;
V_353 -> V_376 += V_355 -> V_376 - V_356 -> V_376 ;
V_353 -> V_377 += V_355 -> V_377 - V_356 -> V_377 ;
memcpy ( V_356 , V_355 , sizeof( * V_355 ) ) ;
}
memcpy ( & V_11 -> V_231 , V_353 , sizeof( * V_353 ) ) ;
return V_353 ;
}
static int F_260 ( struct V_14 * V_19 , struct V_48 * V_49 , int V_378 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_14 * V_15 = NULL ;
struct V_172 V_379 ;
struct V_172 T_9 * V_380 = NULL ;
struct V_177 V_381 ;
struct V_177 T_9 * V_382 = NULL ;
struct V_50 * V_51 = NULL ;
struct V_383 V_384 ;
struct V_385 * V_385 ;
int V_26 = 0 ;
F_56 ( V_19 , L_99 , V_378 ) ;
switch ( V_378 ) {
case V_61 :
V_51 = F_32 ( V_49 ) ;
if ( ! V_51 )
return - V_201 ;
V_51 -> V_386 = 0 ;
case V_64 :
V_51 = F_32 ( V_49 ) ;
if ( ! V_51 )
return - V_201 ;
if ( V_51 -> V_62 == 1 ) {
V_51 -> V_65 = 0 ;
if ( F_22 ( V_11 -> V_16 ) )
V_51 -> V_65 = V_54 ;
}
return 0 ;
case V_387 :
case V_388 :
V_380 = (struct V_172 T_9 * ) V_49 -> V_389 ;
if ( F_261 ( & V_379 , V_380 , sizeof( V_172 ) ) )
return - V_390 ;
V_26 = F_175 ( V_19 , & V_379 ) ;
if ( V_26 == 0 &&
F_262 ( V_380 , & V_379 , sizeof( V_172 ) ) )
return - V_390 ;
return V_26 ;
case V_391 :
case V_392 :
V_382 = (struct V_177 T_9 * ) V_49 -> V_389 ;
if ( F_261 ( & V_381 , V_382 , sizeof( V_177 ) ) )
return - V_390 ;
V_26 = F_176 ( V_19 , & V_381 ) ;
if ( V_26 == 0 &&
F_262 ( V_382 , & V_381 , sizeof( V_177 ) ) )
return - V_390 ;
return V_26 ;
default:
break;
}
V_385 = F_202 ( V_19 ) ;
if ( ! F_263 ( V_385 -> V_393 , V_394 ) )
return - V_193 ;
V_15 = F_264 ( V_385 , V_49 -> V_395 ) ;
F_56 ( V_19 , L_100 , V_15 ) ;
if ( ! V_15 )
return - V_235 ;
F_56 ( V_19 , L_101 , V_15 -> V_59 ) ;
switch ( V_378 ) {
case V_396 :
case V_397 :
V_26 = F_129 ( V_19 , V_15 ) ;
break;
case V_398 :
case V_399 :
V_26 = F_172 ( V_19 , V_15 ) ;
break;
case V_400 :
case V_401 :
F_55 ( V_19 , V_15 ) ;
V_26 = 0 ;
break;
case V_402 :
case V_403 :
F_265 ( & V_384 , V_15 -> V_59 ) ;
V_26 = F_266 ( V_11 , V_404 , & V_384 ) ;
break;
default:
V_26 = - V_203 ;
}
return V_26 ;
}
static void F_267 ( struct V_14 * V_19 , int V_405 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
if ( V_405 & V_83 )
F_34 ( V_11 ,
V_19 -> V_82 & V_83 ? 1 : - 1 ) ;
if ( V_405 & V_84 )
F_38 ( V_11 ,
V_19 -> V_82 & V_84 ? 1 : - 1 ) ;
}
static void F_268 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_65 () ;
if ( F_35 ( V_11 ) ) {
V_22 = F_66 ( V_11 -> V_69 ) ;
if ( V_22 ) {
F_52 ( V_22 -> V_16 , V_19 ) ;
F_53 ( V_22 -> V_16 , V_19 ) ;
}
} else {
F_178 (bond, slave, iter) {
F_141 ( V_22 -> V_16 , V_19 ) ;
F_140 ( V_22 -> V_16 , V_19 ) ;
}
}
F_67 () ;
}
static int F_269 ( struct V_406 * V_407 )
{
struct V_10 * V_11 = F_11 ( V_407 -> V_16 ) ;
const struct V_45 * V_46 ;
struct V_408 V_409 ;
struct V_22 * V_22 ;
int V_160 ;
V_22 = F_270 ( V_11 ) ;
if ( ! V_22 )
return 0 ;
V_46 = V_22 -> V_16 -> V_47 ;
if ( ! V_46 -> V_410 )
return 0 ;
V_409 . V_411 = NULL ;
V_409 . V_412 = NULL ;
V_160 = V_46 -> V_410 ( V_22 -> V_16 , & V_409 ) ;
if ( V_160 )
return V_160 ;
V_407 -> V_409 -> V_412 = V_409 . V_412 ;
if ( ! V_409 . V_411 )
return 0 ;
return V_409 . V_411 ( V_407 ) ;
}
static int F_271 ( struct V_14 * V_16 ,
struct V_408 * V_409 )
{
if ( V_409 -> V_16 == V_16 )
V_409 -> V_411 = F_269 ;
return 0 ;
}
static int F_272 ( struct V_14 * V_19 , int V_413 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_23 ;
struct V_24 * V_25 ;
int V_26 = 0 ;
F_56 ( V_19 , L_102 , V_11 , V_413 ) ;
F_12 (bond, slave, iter) {
F_56 ( V_19 , L_103 ,
V_22 , V_22 -> V_16 -> V_47 -> V_414 ) ;
V_26 = F_136 ( V_22 -> V_16 , V_413 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_104 , V_26 ,
V_22 -> V_16 -> V_59 ) ;
goto V_27;
}
}
V_19 -> V_208 = V_413 ;
return 0 ;
V_27:
F_12 (bond, rollback_slave, iter) {
int V_415 ;
if ( V_23 == V_22 )
break;
V_415 = F_136 ( V_23 -> V_16 , V_19 -> V_208 ) ;
if ( V_415 ) {
F_56 ( V_19 , L_105 ,
V_415 , V_23 -> V_16 -> V_59 ) ;
}
}
return V_26 ;
}
static int F_273 ( struct V_14 * V_19 , void * V_189 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_23 ;
struct V_91 * V_416 = V_189 , V_417 ;
struct V_24 * V_25 ;
int V_26 = 0 ;
if ( F_20 ( V_11 ) == V_9 )
return F_274 ( V_19 , V_189 ) ;
F_56 ( V_19 , L_106 , V_11 ) ;
if ( V_11 -> V_52 . V_94 &&
F_20 ( V_11 ) == V_4 )
return 0 ;
if ( ! F_275 ( V_416 -> V_97 ) )
return - V_418 ;
F_12 (bond, slave, iter) {
F_56 ( V_19 , L_107 , V_22 , V_22 -> V_16 -> V_59 ) ;
V_26 = F_59 ( V_22 -> V_16 , V_189 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_104 , V_26 , V_22 -> V_16 -> V_59 ) ;
goto V_27;
}
}
memcpy ( V_19 -> V_86 , V_416 -> V_97 , V_19 -> V_85 ) ;
return 0 ;
V_27:
memcpy ( V_417 . V_97 , V_19 -> V_86 , V_19 -> V_85 ) ;
V_417 . V_98 = V_19 -> type ;
F_12 (bond, rollback_slave, iter) {
int V_415 ;
if ( V_23 == V_22 )
break;
V_415 = F_59 ( V_23 -> V_16 , & V_417 ) ;
if ( V_415 ) {
F_56 ( V_19 , L_105 ,
V_415 , V_23 -> V_16 -> V_59 ) ;
}
}
return V_26 ;
}
static void F_276 ( struct V_10 * V_11 , struct V_12 * V_13 , int V_236 )
{
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_191 = V_236 ;
F_178 (bond, slave, iter) {
if ( -- V_191 < 0 ) {
if ( F_277 ( V_22 ) ) {
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
return;
}
}
}
V_191 = V_236 ;
F_178 (bond, slave, iter) {
if ( -- V_191 < 0 )
break;
if ( F_277 ( V_22 ) ) {
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
return;
}
}
F_278 ( V_11 -> V_16 , V_13 ) ;
}
static T_3 F_279 ( struct V_10 * V_11 )
{
T_3 V_236 ;
struct V_419 V_420 ;
int V_421 = V_11 -> V_52 . V_421 ;
switch ( V_421 ) {
case 0 :
V_236 = F_280 () ;
break;
case 1 :
V_236 = V_11 -> V_422 ;
break;
default:
V_420 =
V_11 -> V_52 . V_420 ;
V_236 = F_281 ( V_11 -> V_422 ,
V_420 ) ;
break;
}
V_11 -> V_422 ++ ;
return V_236 ;
}
static int F_282 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_327 * V_328 = F_246 ( V_13 ) ;
struct V_22 * V_22 ;
T_3 V_236 ;
if ( V_328 -> V_279 == V_423 && V_13 -> V_279 == F_215 ( V_286 ) ) {
V_22 = F_66 ( V_11 -> V_69 ) ;
if ( V_22 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_276 ( V_11 , V_13 , 0 ) ;
} else {
int V_176 = F_103 ( V_11 -> V_176 ) ;
if ( F_283 ( V_176 ) ) {
V_236 = F_279 ( V_11 ) ;
F_276 ( V_11 , V_13 , V_236 % V_176 ) ;
} else {
F_278 ( V_19 , V_13 ) ;
}
}
return V_424 ;
}
static int F_284 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 ;
V_22 = F_66 ( V_11 -> V_69 ) ;
if ( V_22 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_278 ( V_19 , V_13 ) ;
return V_424 ;
}
void F_285 ( struct V_10 * V_11 , unsigned long V_111 )
{
F_43 ( V_11 -> V_73 , & V_11 -> V_348 , V_111 ) ;
}
static void V_349 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_41 ( V_71 , struct V_10 ,
V_348 . V_71 ) ;
int V_160 ;
if ( ! F_42 () )
goto V_67;
V_160 = F_157 ( V_11 , NULL ) ;
F_45 () ;
if ( V_160 ) {
F_286 ( L_108 ) ;
goto V_67;
}
return;
V_67:
F_285 ( V_11 , 1 ) ;
}
int F_157 ( struct V_10 * V_11 , struct V_22 * V_425 )
{
struct V_22 * V_22 ;
struct V_24 * V_25 ;
struct V_426 * V_427 , * V_428 ;
int V_429 ;
int V_430 = 0 ;
int V_160 = 0 ;
#ifdef F_287
F_288 ( F_289 ( & V_11 -> V_431 ) ) ;
#endif
V_427 = F_81 ( F_290 ( struct V_426 , V_432 [ V_11 -> V_176 ] ) ,
V_127 ) ;
if ( ! V_427 ) {
V_160 = - V_128 ;
F_291 ( L_109 ) ;
goto V_99;
}
if ( F_20 ( V_11 ) == V_7 ) {
struct V_433 V_433 ;
if ( F_292 ( V_11 , & V_433 ) ) {
F_293 ( L_110 ) ;
F_294 ( V_427 , V_434 ) ;
V_428 = F_36 ( V_11 -> V_435 ) ;
if ( V_428 ) {
F_161 ( V_11 -> V_435 , NULL ) ;
F_294 ( V_428 , V_434 ) ;
}
goto V_99;
}
V_429 = V_433 . V_332 ;
V_430 = V_433 . V_436 ;
}
F_12 (bond, slave, iter) {
if ( F_20 ( V_11 ) == V_7 ) {
struct V_437 * V_438 ;
V_438 = F_115 ( V_22 ) -> V_439 . V_437 ;
if ( ! V_438 || V_438 -> V_440 != V_430 )
continue;
}
if ( ! F_277 ( V_22 ) )
continue;
if ( V_425 == V_22 )
continue;
V_427 -> V_432 [ V_427 -> V_441 ++ ] = V_22 ;
}
V_428 = F_36 ( V_11 -> V_435 ) ;
F_78 ( V_11 -> V_435 , V_427 ) ;
if ( V_428 )
F_294 ( V_428 , V_434 ) ;
V_99:
if ( V_160 != 0 && V_425 ) {
int V_442 ;
V_428 = F_36 ( V_11 -> V_435 ) ;
for ( V_442 = 0 ; V_442 < V_428 -> V_441 ; V_442 ++ ) {
if ( V_425 == V_428 -> V_432 [ V_442 ] ) {
V_428 -> V_432 [ V_442 ] =
V_428 -> V_432 [ V_428 -> V_441 - 1 ] ;
V_428 -> V_441 -- ;
break;
}
}
}
return V_160 ;
}
static int F_295 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
struct V_22 * V_22 ;
struct V_426 * V_443 ;
unsigned int V_441 ;
V_443 = F_66 ( V_11 -> V_435 ) ;
V_441 = V_443 ? F_103 ( V_443 -> V_441 ) : 0 ;
if ( F_283 ( V_441 ) ) {
V_22 = V_443 -> V_432 [ F_251 ( V_11 , V_13 ) % V_441 ] ;
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
} else {
F_278 ( V_16 , V_13 ) ;
}
return V_424 ;
}
static int F_296 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 = NULL ;
struct V_24 * V_25 ;
F_178 (bond, slave, iter) {
if ( F_297 ( V_11 , V_22 ) )
break;
if ( F_63 ( V_22 ) && V_22 -> V_29 == V_30 ) {
struct V_12 * V_444 = F_298 ( V_13 , V_162 ) ;
if ( ! V_444 ) {
F_187 ( L_111 ,
V_19 -> V_59 , V_445 ) ;
continue;
}
F_2 ( V_11 , V_444 , V_22 -> V_16 ) ;
}
}
if ( V_22 && F_63 ( V_22 ) && V_22 -> V_29 == V_30 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_278 ( V_19 , V_13 ) ;
return V_424 ;
}
static inline int F_299 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_22 * V_22 = NULL ;
struct V_24 * V_25 ;
if ( ! V_13 -> V_17 )
return 1 ;
F_178 (bond, slave, iter) {
if ( V_22 -> V_206 == V_13 -> V_17 ) {
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
static T_2 F_300 ( struct V_14 * V_16 , struct V_12 * V_13 ,
void * V_446 , T_10 V_447 )
{
T_2 V_448 = F_301 ( V_13 ) ? F_302 ( V_13 ) : 0 ;
F_4 ( V_13 ) -> V_18 = V_13 -> V_17 ;
if ( F_5 ( V_448 >= V_16 -> V_449 ) ) {
do {
V_448 -= V_16 -> V_449 ;
} while ( V_448 >= V_16 -> V_449 );
}
return V_448 ;
}
static T_11 F_303 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
if ( F_304 ( V_11 ) &&
! F_299 ( V_11 , V_13 ) )
return V_424 ;
switch ( F_20 ( V_11 ) ) {
case V_3 :
return F_282 ( V_13 , V_16 ) ;
case V_4 :
return F_284 ( V_13 , V_16 ) ;
case V_7 :
case V_5 :
return F_295 ( V_13 , V_16 ) ;
case V_6 :
return F_296 ( V_13 , V_16 ) ;
case V_9 :
return F_305 ( V_13 , V_16 ) ;
case V_8 :
return F_306 ( V_13 , V_16 ) ;
default:
F_60 ( V_16 , L_112 , F_20 ( V_11 ) ) ;
F_307 ( 1 ) ;
F_278 ( V_16 , V_13 ) ;
return V_424 ;
}
}
static T_11 F_308 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
T_11 V_160 = V_424 ;
if ( F_5 ( F_309 ( V_16 ) ) )
return V_450 ;
F_65 () ;
if ( F_19 ( V_11 ) )
V_160 = F_303 ( V_13 , V_16 ) ;
else
F_278 ( V_16 , V_13 ) ;
F_67 () ;
return V_160 ;
}
static int F_310 ( struct V_14 * V_19 ,
struct V_31 * V_32 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
unsigned long V_34 = 0 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
V_32 -> V_36 = V_37 ;
V_32 -> V_439 = V_451 ;
F_12 (bond, slave, iter) {
if ( F_277 ( V_22 ) ) {
if ( V_22 -> V_34 != V_35 )
V_34 += V_22 -> V_34 ;
if ( V_32 -> V_36 == V_37 &&
V_22 -> V_36 != V_37 )
V_32 -> V_36 = V_22 -> V_36 ;
}
}
F_311 ( V_32 , V_34 ? : V_35 ) ;
return 0 ;
}
static void F_312 ( struct V_14 * V_19 ,
struct V_452 * V_453 )
{
F_313 ( V_453 -> V_454 , V_455 , sizeof( V_453 -> V_454 ) ) ;
F_313 ( V_453 -> V_456 , V_457 , sizeof( V_453 -> V_456 ) ) ;
snprintf ( V_453 -> V_458 , sizeof( V_453 -> V_458 ) , L_113 ,
V_459 ) ;
}
static void F_314 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
if ( V_11 -> V_73 )
F_315 ( V_11 -> V_73 ) ;
F_316 ( V_19 ) ;
}
void F_317 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_318 ( & V_11 -> V_431 ) ;
V_11 -> V_52 = V_460 ;
V_11 -> V_16 = V_19 ;
F_135 ( V_19 ) ;
V_19 -> V_47 = & V_461 ;
V_19 -> V_55 = & V_462 ;
V_19 -> V_463 = F_314 ;
F_319 ( V_19 , & V_464 ) ;
V_19 -> V_465 = 0 ;
V_19 -> V_82 |= V_317 | V_466 ;
V_19 -> V_151 |= V_213 | V_467 ;
V_19 -> V_151 &= ~ ( V_137 | V_199 ) ;
V_19 -> V_131 |= V_468 ;
V_19 -> V_131 |= V_469 ;
V_19 -> V_470 = V_140 |
V_471 |
V_472 |
V_473 ;
V_19 -> V_470 &= ~ ( V_474 & ~ V_475 ) ;
V_19 -> V_470 |= V_153 ;
V_19 -> V_131 |= V_19 -> V_470 ;
}
static void F_320 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
struct V_426 * V_432 ;
F_87 ( V_19 ) ;
F_12 (bond, slave, iter)
F_166 ( V_19 , V_22 -> V_16 , true ) ;
F_71 ( V_19 , L_114 ) ;
V_432 = F_36 ( V_11 -> V_435 ) ;
if ( V_432 ) {
F_161 ( V_11 -> V_435 , NULL ) ;
F_294 ( V_432 , V_434 ) ;
}
F_321 ( & V_11 -> V_476 ) ;
F_322 ( V_11 ) ;
}
static int F_323 ( struct V_477 * V_52 )
{
int V_478 , V_479 , V_480 , V_191 ;
struct V_383 V_384 ;
const struct V_383 * V_481 ;
int V_482 ;
if ( V_1 ) {
F_265 ( & V_384 , V_1 ) ;
V_481 = F_324 ( F_325 ( V_483 ) , & V_384 ) ;
if ( ! V_481 ) {
F_291 ( L_115 , V_1 ) ;
return - V_201 ;
}
V_174 = V_481 -> V_484 ;
}
if ( V_485 ) {
if ( ( V_174 != V_5 ) &&
( V_174 != V_7 ) &&
( V_174 != V_8 ) ) {
F_326 ( L_116 ,
F_1 ( V_174 ) ) ;
} else {
F_265 ( & V_384 , V_485 ) ;
V_481 = F_324 ( F_325 ( V_486 ) ,
& V_384 ) ;
if ( ! V_481 ) {
F_291 ( L_117 ,
V_485 ) ;
return - V_201 ;
}
V_487 = V_481 -> V_484 ;
}
}
if ( V_488 ) {
if ( V_174 != V_7 ) {
F_326 ( L_118 ,
F_1 ( V_174 ) ) ;
} else {
F_265 ( & V_384 , V_488 ) ;
V_481 = F_324 ( F_325 ( V_489 ) ,
& V_384 ) ;
if ( ! V_481 ) {
F_291 ( L_119 ,
V_488 ) ;
return - V_201 ;
}
V_490 = V_481 -> V_484 ;
}
}
if ( V_491 ) {
F_265 ( & V_384 , V_491 ) ;
V_481 = F_324 ( F_325 ( V_492 ) ,
& V_384 ) ;
if ( ! V_481 ) {
F_291 ( L_120 , V_491 ) ;
return - V_201 ;
}
V_52 -> V_491 = V_481 -> V_484 ;
if ( V_174 != V_7 )
F_327 ( L_121 ) ;
} else {
V_52 -> V_491 = V_493 ;
}
if ( V_494 < 0 ) {
F_327 ( L_122 ,
V_494 , 0 , V_495 , V_496 ) ;
V_494 = V_496 ;
}
if ( V_117 < 0 ) {
F_327 ( L_123 ,
V_117 , V_495 ) ;
V_117 = 0 ;
}
if ( V_110 < 0 ) {
F_327 ( L_124 ,
V_110 , V_495 ) ;
V_110 = 0 ;
}
if ( V_242 < 0 ) {
F_327 ( L_125 ,
V_242 , V_495 ) ;
V_242 = 0 ;
}
if ( ( V_53 != 0 ) && ( V_53 != 1 ) ) {
F_327 ( L_126 ,
V_53 ) ;
V_53 = 1 ;
}
if ( V_120 < 0 || V_120 > 255 ) {
F_327 ( L_127 ,
V_120 ) ;
V_120 = 1 ;
}
if ( ! F_328 ( V_174 ) ) {
if ( ! V_117 ) {
F_327 ( L_128 ) ;
F_327 ( L_129 ) ;
V_117 = V_497 ;
}
}
if ( V_498 < 1 || V_498 > 255 ) {
F_327 ( L_130 ,
V_498 , V_499 ) ;
V_498 = V_499 ;
}
if ( ( V_500 != 0 ) && ( V_500 != 1 ) ) {
F_327 ( L_131 ,
V_500 ) ;
V_500 = 0 ;
}
if ( V_123 < 0 || V_123 > 255 ) {
F_327 ( L_132 ,
V_123 , V_501 ) ;
V_123 = V_501 ;
}
F_329 ( & V_384 , V_421 ) ;
if ( ! F_324 ( F_325 ( V_502 ) , & V_384 ) ) {
F_327 ( L_133 ,
V_421 , V_503 ) ;
V_421 = 1 ;
}
if ( V_174 == V_9 ) {
F_330 ( L_134 ,
V_110 ) ;
}
if ( ! V_117 ) {
if ( V_110 || V_242 ) {
F_327 ( L_135 ,
V_110 , V_242 ) ;
}
} else {
if ( V_217 ) {
F_327 ( L_136 ,
V_117 , V_217 ) ;
V_217 = 0 ;
}
if ( ( V_110 % V_117 ) != 0 ) {
F_327 ( L_137 ,
V_110 , V_117 , ( V_110 / V_117 ) * V_117 ) ;
}
V_110 /= V_117 ;
if ( ( V_242 % V_117 ) != 0 ) {
F_327 ( L_138 ,
V_242 , V_117 ,
( V_242 / V_117 ) * V_117 ) ;
}
V_242 /= V_117 ;
}
if ( V_217 < 0 ) {
F_327 ( L_139 ,
V_217 , V_495 ) ;
V_217 = 0 ;
}
for ( V_504 = 0 , V_191 = 0 ;
( V_504 < V_218 ) && V_505 [ V_191 ] ; V_191 ++ ) {
T_8 V_247 ;
if ( ! F_331 ( V_505 [ V_191 ] , - 1 , ( T_5 * ) & V_247 , - 1 , NULL ) ||
! F_332 ( V_247 ) ) {
F_327 ( L_140 ,
V_505 [ V_191 ] ) ;
V_217 = 0 ;
} else {
if ( F_206 ( V_506 , V_247 ) == - 1 )
V_506 [ V_504 ++ ] = V_247 ;
else
F_327 ( L_141 ,
& V_247 ) ;
}
}
if ( V_217 && ! V_504 ) {
F_327 ( L_142 ,
V_217 ) ;
V_217 = 0 ;
}
if ( V_268 ) {
if ( ! V_217 ) {
F_291 ( L_143 ) ;
return - V_201 ;
}
F_265 ( & V_384 , V_268 ) ;
V_481 = F_324 ( F_325 ( V_507 ) ,
& V_384 ) ;
if ( ! V_481 ) {
F_291 ( L_144 ,
V_268 ) ;
return - V_201 ;
}
V_478 = V_481 -> V_484 ;
} else {
V_478 = 0 ;
}
V_482 = 0 ;
if ( V_508 ) {
F_265 ( & V_384 , V_508 ) ;
V_481 = F_324 ( F_325 ( V_509 ) ,
& V_384 ) ;
if ( ! V_481 ) {
F_291 ( L_145 ,
V_508 ) ;
V_482 = 0 ;
} else {
V_482 = V_481 -> V_484 ;
}
}
if ( V_117 ) {
F_326 ( L_146 , V_117 ) ;
} else if ( V_217 ) {
V_481 = F_333 ( V_507 ,
V_478 ) ;
F_326 ( L_147 ,
V_217 , V_481 -> string , V_504 ) ;
for ( V_191 = 0 ; V_191 < V_504 ; V_191 ++ )
F_334 ( L_148 , V_505 [ V_191 ] ) ;
F_334 ( L_149 ) ;
} else if ( V_494 ) {
F_293 ( L_150 ) ;
}
if ( V_108 && ! F_335 ( V_174 ) ) {
F_327 ( L_151 ,
V_108 , F_1 ( V_174 ) ) ;
V_108 = NULL ;
}
if ( V_108 && V_104 ) {
F_265 ( & V_384 , V_104 ) ;
V_481 = F_324 ( F_325 ( V_510 ) ,
& V_384 ) ;
if ( ! V_481 ) {
F_291 ( L_152 ,
V_104 ) ;
return - V_201 ;
}
V_480 = V_481 -> V_484 ;
} else {
V_480 = V_511 ;
}
if ( V_94 ) {
F_265 ( & V_384 , V_94 ) ;
V_481 = F_324 ( F_325 ( V_512 ) ,
& V_384 ) ;
if ( ! V_481 ) {
F_291 ( L_153 ,
V_94 ) ;
return - V_201 ;
}
V_479 = V_481 -> V_484 ;
if ( V_174 != V_4 )
F_327 ( L_154 ) ;
} else {
V_479 = V_513 ;
}
if ( V_514 == 0 ) {
F_327 ( L_155 ,
V_495 , V_515 ) ;
V_514 = V_515 ;
}
V_52 -> V_1 = V_174 ;
V_52 -> V_330 = V_487 ;
V_52 -> V_117 = V_117 ;
V_52 -> V_120 = V_120 ;
V_52 -> V_217 = V_217 ;
V_52 -> V_268 = V_478 ;
V_52 -> V_508 = V_482 ;
V_52 -> V_110 = V_110 ;
V_52 -> V_242 = V_242 ;
V_52 -> V_53 = V_53 ;
V_52 -> V_490 = V_490 ;
V_52 -> V_108 [ 0 ] = 0 ;
V_52 -> V_104 = V_480 ;
V_52 -> V_94 = V_479 ;
V_52 -> V_498 = V_498 ;
V_52 -> V_500 = V_500 ;
V_52 -> V_123 = V_123 ;
V_52 -> V_516 = V_516 ;
V_52 -> V_514 = V_514 ;
V_52 -> V_421 = V_421 ;
V_52 -> V_350 = 1 ;
if ( V_421 > 0 ) {
V_52 -> V_420 =
V_419 ( V_421 ) ;
} else {
V_52 -> V_420 =
(struct V_419 ) { 0 } ;
}
if ( V_108 ) {
strncpy ( V_52 -> V_108 , V_108 , V_60 ) ;
V_52 -> V_108 [ V_60 - 1 ] = 0 ;
}
memcpy ( V_52 -> V_266 , V_506 , sizeof( V_506 ) ) ;
return 0 ;
}
static void F_336 ( struct V_14 * V_16 ,
struct V_517 * V_448 ,
void * V_518 )
{
F_337 ( & V_448 -> V_519 ,
& V_520 ) ;
}
static void F_338 ( struct V_14 * V_16 )
{
F_337 ( & V_16 -> V_521 ,
& V_522 ) ;
F_339 ( V_16 , F_336 , NULL ) ;
V_16 -> V_523 = & V_524 ;
}
static int F_340 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_525 * V_526 = F_341 ( F_202 ( V_19 ) , V_527 ) ;
F_56 ( V_19 , L_156 ) ;
V_11 -> V_73 = F_342 ( V_19 -> V_59 ) ;
if ( ! V_11 -> V_73 )
return - V_128 ;
F_338 ( V_19 ) ;
F_343 ( & V_11 -> V_476 , & V_526 -> V_528 ) ;
F_344 ( V_11 ) ;
F_345 ( V_11 ) ;
if ( F_346 ( V_19 -> V_86 ) &&
V_19 -> V_87 == V_529 )
F_165 ( V_19 ) ;
return 0 ;
}
unsigned int F_347 ( void )
{
return V_498 ;
}
int F_348 ( struct V_385 * V_385 , const char * V_59 )
{
struct V_14 * V_19 ;
int V_26 ;
F_122 () ;
V_19 = F_349 ( sizeof( struct V_10 ) ,
V_59 ? V_59 : L_157 , V_530 ,
F_317 , V_498 ) ;
if ( ! V_19 ) {
F_291 ( L_158 , V_59 ) ;
F_45 () ;
return - V_128 ;
}
F_350 ( V_19 , V_385 ) ;
V_19 -> V_531 = & V_532 ;
V_26 = F_351 ( V_19 ) ;
F_24 ( V_19 ) ;
F_45 () ;
if ( V_26 < 0 )
F_314 ( V_19 ) ;
return V_26 ;
}
static int T_12 F_352 ( struct V_385 * V_385 )
{
struct V_525 * V_526 = F_341 ( V_385 , V_527 ) ;
V_526 -> V_385 = V_385 ;
F_353 ( & V_526 -> V_528 ) ;
F_354 ( V_526 ) ;
F_355 ( V_526 ) ;
return 0 ;
}
static void T_13 F_356 ( struct V_385 * V_385 )
{
struct V_525 * V_526 = F_341 ( V_385 , V_527 ) ;
struct V_10 * V_11 , * V_533 ;
F_357 ( V_534 ) ;
F_358 ( V_526 ) ;
F_122 () ;
F_359 (bond, tmp_bond, &bn->dev_list, bond_list)
F_360 ( V_11 -> V_16 , & V_534 ) ;
F_361 ( & V_534 ) ;
F_45 () ;
F_362 ( V_526 ) ;
}
static int T_14 F_363 ( void )
{
int V_191 ;
int V_26 ;
F_326 ( L_159 , V_535 ) ;
V_26 = F_323 ( & V_460 ) ;
if ( V_26 )
goto V_99;
V_26 = F_364 ( & V_536 ) ;
if ( V_26 )
goto V_99;
V_26 = F_365 () ;
if ( V_26 )
goto V_537;
F_366 () ;
for ( V_191 = 0 ; V_191 < V_494 ; V_191 ++ ) {
V_26 = F_348 ( & V_538 , NULL ) ;
if ( V_26 )
goto V_67;
}
F_367 ( & V_539 ) ;
V_99:
return V_26 ;
V_67:
F_368 () ;
F_369 () ;
V_537:
F_370 ( & V_536 ) ;
goto V_99;
}
static void T_15 F_371 ( void )
{
F_372 ( & V_539 ) ;
F_368 () ;
F_369 () ;
F_370 ( & V_536 ) ;
#ifdef F_150
F_288 ( F_373 ( & V_540 ) ) ;
#endif
}
