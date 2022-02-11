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
static int F_18 ( struct V_10 * V_11 )
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
V_80 -> V_29 = V_30 ;
if ( F_20 ( V_11 ) == V_7 )
F_72 ( V_80 , V_30 ) ;
if ( F_16 ( V_11 ) )
F_73 ( V_11 , V_80 , V_30 ) ;
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
F_74 ( V_11 , V_80 ) ;
if ( V_81 )
F_75 ( V_81 ,
V_118 ) ;
if ( V_80 )
F_76 ( V_80 ,
V_118 ) ;
} else {
F_77 ( V_11 -> V_69 , V_80 ) ;
}
if ( F_20 ( V_11 ) == V_4 ) {
if ( V_81 )
F_75 ( V_81 ,
V_118 ) ;
if ( V_80 ) {
bool V_119 = false ;
F_76 ( V_80 ,
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
void F_78 ( struct V_10 * V_11 )
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
static inline int F_79 ( struct V_22 * V_22 )
{
struct V_125 * V_126 ;
int V_67 = 0 ;
V_126 = F_80 ( sizeof( * V_126 ) , V_127 ) ;
V_67 = - V_128 ;
if ( ! V_126 )
goto V_99;
V_67 = F_81 ( V_126 , V_22 -> V_16 ) ;
if ( V_67 ) {
F_82 ( V_126 ) ;
goto V_99;
}
V_22 -> V_126 = V_126 ;
V_99:
return V_67 ;
}
static inline void F_83 ( struct V_22 * V_22 )
{
struct V_125 * V_126 = V_22 -> V_126 ;
if ( ! V_126 )
return;
V_22 -> V_126 = NULL ;
F_84 ( V_126 ) ;
}
static void F_85 ( struct V_14 * V_19 )
{
}
static void F_86 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter)
if ( F_63 ( V_22 ) )
F_83 ( V_22 ) ;
}
static int F_87 ( struct V_14 * V_16 , struct V_129 * V_130 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_67 = 0 ;
F_12 (bond, slave, iter) {
V_67 = F_79 ( V_22 ) ;
if ( V_67 ) {
F_86 ( V_16 ) ;
break;
}
}
return V_67 ;
}
static inline int F_79 ( struct V_22 * V_22 )
{
return 0 ;
}
static inline void F_83 ( struct V_22 * V_22 )
{
}
static void F_86 ( struct V_14 * V_19 )
{
}
static T_6 F_88 ( struct V_14 * V_16 ,
T_6 V_131 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
struct V_24 * V_25 ;
T_6 V_132 ;
struct V_22 * V_22 ;
V_132 = V_131 ;
V_131 &= ~ V_133 ;
V_131 |= V_134 ;
F_12 (bond, slave, iter) {
V_131 = F_89 ( V_131 ,
V_22 -> V_16 -> V_131 ,
V_132 ) ;
}
V_131 = F_90 ( V_131 , V_132 ) ;
return V_131 ;
}
static void F_91 ( struct V_10 * V_11 )
{
unsigned int V_135 = V_136 |
V_137 ;
T_6 V_138 = V_139 ;
T_6 V_140 = V_141 ;
struct V_14 * V_19 = V_11 -> V_16 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
unsigned short V_142 = V_143 ;
unsigned int V_144 = V_145 ;
T_2 V_146 = V_147 ;
if ( ! F_19 ( V_11 ) )
goto V_148;
V_138 &= V_134 ;
F_12 (bond, slave, iter) {
V_138 = F_89 ( V_138 ,
V_22 -> V_16 -> V_138 , V_139 ) ;
V_140 = F_89 ( V_140 ,
V_22 -> V_16 -> V_149 ,
V_141 ) ;
V_135 &= V_22 -> V_16 -> V_150 ;
if ( V_22 -> V_16 -> V_151 > V_142 )
V_142 = V_22 -> V_16 -> V_151 ;
V_144 = F_92 ( V_144 , V_22 -> V_16 -> V_144 ) ;
V_146 = F_92 ( V_146 , V_22 -> V_16 -> V_146 ) ;
}
V_148:
V_19 -> V_138 = V_138 ;
V_19 -> V_149 = V_140 ;
V_19 -> V_151 = V_142 ;
V_19 -> V_146 = V_146 ;
F_93 ( V_19 , V_144 ) ;
V_19 -> V_150 &= ~ V_136 ;
if ( ( V_19 -> V_150 & V_137 ) &&
V_135 == ( V_136 | V_137 ) )
V_19 -> V_150 |= V_136 ;
F_94 ( V_19 ) ;
}
static void F_95 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
V_19 -> V_152 = V_15 -> V_152 ;
V_19 -> type = V_15 -> type ;
V_19 -> V_151 = V_15 -> V_151 ;
V_19 -> V_85 = V_15 -> V_85 ;
memcpy ( V_19 -> V_153 , V_15 -> V_153 ,
V_15 -> V_85 ) ;
}
static bool F_96 ( struct V_12 * V_13 ,
struct V_22 * V_22 ,
struct V_10 * V_11 )
{
if ( F_97 ( V_22 ) ) {
if ( F_20 ( V_11 ) == V_9 &&
V_13 -> V_154 != V_155 &&
V_13 -> V_154 != V_156 )
return false ;
return true ;
}
return false ;
}
static T_7 F_98 ( struct V_12 * * V_157 )
{
struct V_12 * V_13 = * V_157 ;
struct V_22 * V_22 ;
struct V_10 * V_11 ;
int (* F_99)( const struct V_12 * , struct V_10 * ,
struct V_22 * );
int V_158 = V_159 ;
V_13 = F_100 ( V_13 , V_160 ) ;
if ( F_5 ( ! V_13 ) )
return V_161 ;
* V_157 = V_13 ;
V_22 = F_101 ( V_13 -> V_16 ) ;
V_11 = V_22 -> V_11 ;
F_99 = F_102 ( V_11 -> F_99 ) ;
if ( F_99 ) {
V_158 = F_99 ( V_13 , V_11 , V_22 ) ;
if ( V_158 == V_161 ) {
F_103 ( V_13 ) ;
return V_158 ;
}
}
if ( F_96 ( V_13 , V_22 , V_11 ) ) {
return V_162 ;
}
V_13 -> V_16 = V_11 -> V_16 ;
if ( F_20 ( V_11 ) == V_9 &&
V_11 -> V_16 -> V_150 & V_163 &&
V_13 -> V_154 == V_164 ) {
if ( F_5 ( F_104 ( V_13 ,
V_13 -> V_165 - F_105 ( V_13 ) ) ) ) {
F_106 ( V_13 ) ;
return V_161 ;
}
F_58 ( F_107 ( V_13 ) -> V_166 , V_11 -> V_16 -> V_86 ) ;
}
return V_158 ;
}
static int F_108 ( struct V_14 * V_19 ,
struct V_14 * V_15 ,
struct V_22 * V_22 )
{
int V_67 ;
V_67 = F_109 ( V_15 , V_19 , V_22 ) ;
if ( V_67 )
return V_67 ;
V_15 -> V_82 |= V_167 ;
F_110 ( V_168 , V_15 , V_167 , V_127 ) ;
return 0 ;
}
static void F_111 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
F_112 ( V_15 , V_19 ) ;
V_15 -> V_82 &= ~ V_167 ;
F_110 ( V_168 , V_15 , V_167 , V_127 ) ;
}
static struct V_22 * F_113 ( struct V_10 * V_11 )
{
struct V_22 * V_22 = NULL ;
V_22 = F_80 ( sizeof( struct V_22 ) , V_127 ) ;
if ( ! V_22 )
return NULL ;
if ( F_20 ( V_11 ) == V_7 ) {
F_114 ( V_22 ) = F_80 ( sizeof( struct V_169 ) ,
V_127 ) ;
if ( ! F_114 ( V_22 ) ) {
F_82 ( V_22 ) ;
return NULL ;
}
}
return V_22 ;
}
static void F_115 ( struct V_22 * V_22 )
{
struct V_10 * V_11 = F_116 ( V_22 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_82 ( F_114 ( V_22 ) ) ;
F_82 ( V_22 ) ;
}
int F_117 ( struct V_14 * V_19 , struct V_14 * V_15 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
const struct V_45 * V_46 = V_15 -> V_47 ;
struct V_22 * V_170 = NULL , * V_171 ;
struct V_91 V_172 ;
int V_173 ;
int V_26 = 0 , V_174 ;
if ( ! V_11 -> V_52 . V_53 &&
V_15 -> V_55 -> V_56 == NULL &&
V_46 -> V_57 == NULL ) {
F_118 ( V_19 , L_22 ,
V_15 -> V_59 ) ;
}
if ( V_15 -> V_82 & V_167 ) {
F_56 ( V_19 , L_23 ) ;
return - V_175 ;
}
if ( V_19 == V_15 ) {
F_60 ( V_19 , L_24 ) ;
return - V_176 ;
}
if ( V_15 -> V_131 & V_177 ) {
F_56 ( V_19 , L_25 ,
V_15 -> V_59 ) ;
if ( F_119 ( V_19 ) ) {
F_60 ( V_19 , L_26 ,
V_15 -> V_59 , V_19 -> V_59 ) ;
return - V_176 ;
} else {
F_118 ( V_19 , L_27 ,
V_15 -> V_59 , V_15 -> V_59 ,
V_19 -> V_59 ) ;
}
} else {
F_56 ( V_19 , L_28 ,
V_15 -> V_59 ) ;
}
if ( ( V_15 -> V_82 & V_178 ) ) {
F_60 ( V_19 , L_29 ,
V_15 -> V_59 ) ;
V_26 = - V_176 ;
goto V_179;
}
if ( ! F_19 ( V_11 ) ) {
if ( V_19 -> type != V_15 -> type ) {
F_56 ( V_19 , L_30 ,
V_19 -> type , V_15 -> type ) ;
V_26 = F_44 ( V_180 ,
V_19 ) ;
V_26 = F_120 ( V_26 ) ;
if ( V_26 ) {
F_60 ( V_19 , L_31 ) ;
V_26 = - V_175 ;
goto V_179;
}
F_121 ( V_19 ) ;
F_122 ( V_19 ) ;
if ( V_15 -> type != V_181 )
F_95 ( V_19 , V_15 ) ;
else {
F_123 ( V_19 ) ;
V_19 -> V_150 &= ~ V_182 ;
}
F_44 ( V_183 ,
V_19 ) ;
}
} else if ( V_19 -> type != V_15 -> type ) {
F_60 ( V_19 , L_32 ,
V_15 -> V_59 , V_15 -> type , V_19 -> type ) ;
V_26 = - V_184 ;
goto V_179;
}
if ( V_46 -> V_185 == NULL ) {
F_118 ( V_19 , L_33 ) ;
if ( F_20 ( V_11 ) == V_4 &&
V_11 -> V_52 . V_94 != V_95 ) {
if ( ! F_19 ( V_11 ) ) {
V_11 -> V_52 . V_94 = V_95 ;
F_118 ( V_19 , L_34 ) ;
} else {
F_60 ( V_19 , L_35 ) ;
V_26 = - V_186 ;
goto V_179;
}
}
}
F_44 ( V_187 , V_15 ) ;
if ( ! F_19 ( V_11 ) &&
V_11 -> V_16 -> V_87 == V_188 )
F_55 ( V_11 -> V_16 , V_15 ) ;
V_170 = F_113 ( V_11 ) ;
if ( ! V_170 ) {
V_26 = - V_128 ;
goto V_179;
}
V_170 -> V_11 = V_11 ;
V_170 -> V_16 = V_15 ;
V_170 -> V_189 = 0 ;
V_170 -> V_190 = V_15 -> V_191 ;
V_26 = F_124 ( V_15 , V_11 -> V_16 -> V_191 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_36 , V_26 ) ;
goto V_192;
}
F_58 ( V_170 -> V_193 , V_15 -> V_86 ) ;
if ( ! V_11 -> V_52 . V_94 ||
F_20 ( V_11 ) != V_4 ) {
memcpy ( V_172 . V_97 , V_19 -> V_86 , V_19 -> V_85 ) ;
V_172 . V_98 = V_15 -> type ;
V_26 = F_59 ( V_15 , & V_172 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_37 , V_26 ) ;
goto V_194;
}
}
V_26 = F_125 ( V_15 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_38 , V_15 -> V_59 ) ;
goto V_195;
}
V_15 -> V_150 |= V_196 ;
F_126 ( V_170 -> V_16 , & V_170 -> V_197 ) ;
if ( F_16 ( V_11 ) ) {
V_26 = F_127 ( V_11 , V_170 ) ;
if ( V_26 )
goto V_198;
}
if ( ! F_35 ( V_11 ) ) {
if ( V_19 -> V_82 & V_83 ) {
V_26 = F_37 ( V_15 , 1 ) ;
if ( V_26 )
goto V_198;
}
if ( V_19 -> V_82 & V_84 ) {
V_26 = F_39 ( V_15 , 1 ) ;
if ( V_26 )
goto V_198;
}
F_51 ( V_19 ) ;
F_128 ( V_15 , V_19 ) ;
F_129 ( V_15 , V_19 ) ;
F_54 ( V_19 ) ;
}
if ( F_20 ( V_11 ) == V_7 ) {
T_5 V_77 [ V_78 ] = V_79 ;
F_130 ( V_15 , V_77 ) ;
}
V_26 = F_131 ( V_15 , V_19 ) ;
if ( V_26 ) {
F_60 ( V_19 , L_39 ,
V_15 -> V_59 ) ;
goto V_198;
}
V_171 = F_132 ( V_11 ) ;
V_170 -> V_111 = 0 ;
V_170 -> V_199 = 0 ;
F_25 ( V_170 ) ;
V_170 -> V_200 = V_116 -
( F_133 ( V_11 -> V_52 . V_201 ) + 1 ) ;
for ( V_174 = 0 ; V_174 < V_202 ; V_174 ++ )
V_170 -> V_203 [ V_174 ] = V_170 -> V_200 ;
if ( V_11 -> V_52 . V_117 && ! V_11 -> V_52 . V_53 ) {
V_173 = F_29 ( V_11 , V_15 , 1 ) ;
if ( ( V_173 == - 1 ) && ! V_11 -> V_52 . V_201 ) {
F_118 ( V_19 , L_40 ,
V_15 -> V_59 ) ;
} else if ( V_173 == - 1 ) {
F_118 ( V_19 , L_41 ,
V_15 -> V_59 ) ;
}
}
if ( V_11 -> V_52 . V_117 ) {
if ( F_29 ( V_11 , V_15 , 0 ) == V_54 ) {
if ( V_11 -> V_52 . V_110 ) {
V_170 -> V_29 = V_43 ;
V_170 -> V_111 = V_11 -> V_52 . V_110 ;
} else {
V_170 -> V_29 = V_30 ;
}
} else {
V_170 -> V_29 = V_42 ;
}
} else if ( V_11 -> V_52 . V_201 ) {
V_170 -> V_29 = ( F_22 ( V_15 ) ?
V_30 : V_42 ) ;
} else {
V_170 -> V_29 = V_30 ;
}
if ( V_170 -> V_29 != V_42 )
V_170 -> V_115 = V_116 ;
F_56 ( V_19 , L_42 ,
V_170 -> V_29 == V_42 ? L_43 :
( V_170 -> V_29 == V_30 ? L_44 : L_45 ) ) ;
if ( F_35 ( V_11 ) && V_11 -> V_52 . V_108 [ 0 ] ) {
if ( strcmp ( V_11 -> V_52 . V_108 , V_170 -> V_16 -> V_59 ) == 0 ) {
F_77 ( V_11 -> V_101 , V_170 ) ;
V_11 -> V_103 = true ;
}
}
switch ( F_20 ( V_11 ) ) {
case V_4 :
F_75 ( V_170 ,
V_118 ) ;
break;
case V_7 :
F_75 ( V_170 , V_118 ) ;
if ( ! V_171 ) {
F_114 ( V_170 ) -> V_204 = 1 ;
F_134 ( V_11 , 1000 / V_205 ) ;
} else {
F_114 ( V_170 ) -> V_204 =
F_114 ( V_171 ) -> V_204 + 1 ;
}
F_135 ( V_170 ) ;
break;
case V_8 :
case V_9 :
F_136 ( V_170 ) ;
F_75 ( V_170 , V_118 ) ;
break;
default:
F_56 ( V_19 , L_46 ) ;
F_136 ( V_170 ) ;
if ( ! F_137 ( V_11 -> V_69 ) &&
V_170 -> V_29 == V_30 )
F_77 ( V_11 -> V_69 , V_170 ) ;
break;
}
#ifdef F_138
V_15 -> V_206 = V_11 -> V_16 -> V_206 ;
if ( V_15 -> V_206 ) {
if ( F_79 ( V_170 ) ) {
F_71 ( V_19 , L_47 ) ;
V_26 = - V_175 ;
goto V_207;
}
}
#endif
V_26 = F_139 ( V_15 , F_98 ,
V_170 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_48 , V_26 ) ;
goto V_207;
}
V_26 = F_108 ( V_19 , V_15 , V_170 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_49 , V_26 ) ;
goto V_208;
}
V_26 = F_140 ( V_170 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_50 , V_26 ) ;
goto V_209;
}
V_11 -> V_210 ++ ;
F_91 ( V_11 ) ;
F_18 ( V_11 ) ;
if ( F_35 ( V_11 ) ) {
F_141 () ;
F_78 ( V_11 ) ;
F_142 () ;
}
if ( F_143 ( V_11 ) )
F_144 ( V_11 , NULL ) ;
F_71 ( V_19 , L_51 ,
V_15 -> V_59 ,
F_145 ( V_170 ) ? L_52 : L_53 ,
V_170 -> V_29 != V_42 ? L_54 : L_55 ) ;
return 0 ;
V_209:
F_111 ( V_19 , V_15 ) ;
V_208:
F_146 ( V_15 ) ;
V_207:
if ( ! F_35 ( V_11 ) )
F_46 ( V_19 , V_15 ) ;
F_147 ( V_15 , V_19 ) ;
if ( F_137 ( V_11 -> V_101 ) == V_170 )
F_148 ( V_11 -> V_101 , NULL ) ;
if ( F_137 ( V_11 -> V_69 ) == V_170 ) {
F_141 () ;
F_69 ( V_11 , NULL ) ;
F_78 ( V_11 ) ;
F_142 () ;
}
F_149 () ;
F_83 ( V_170 ) ;
V_198:
V_15 -> V_150 &= ~ V_196 ;
F_150 ( V_15 ) ;
V_195:
if ( ! V_11 -> V_52 . V_94 ||
F_20 ( V_11 ) != V_4 ) {
F_58 ( V_172 . V_97 , V_170 -> V_193 ) ;
V_172 . V_98 = V_15 -> type ;
F_59 ( V_15 , & V_172 ) ;
}
V_194:
F_124 ( V_15 , V_170 -> V_190 ) ;
V_192:
F_115 ( V_170 ) ;
V_179:
if ( ! F_19 ( V_11 ) &&
F_151 ( V_19 -> V_86 , V_15 -> V_86 ) )
F_152 ( V_19 ) ;
return V_26 ;
}
static int F_153 ( struct V_14 * V_19 ,
struct V_14 * V_15 ,
bool V_211 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_212 ;
struct V_91 V_172 ;
int V_213 = V_19 -> V_82 ;
T_6 V_214 = V_19 -> V_131 ;
if ( ! ( V_15 -> V_82 & V_167 ) ||
! F_154 ( V_15 , V_19 ) ) {
F_60 ( V_19 , L_56 ,
V_15 -> V_59 ) ;
return - V_184 ;
}
F_141 () ;
V_22 = F_8 ( V_11 , V_15 ) ;
if ( ! V_22 ) {
F_71 ( V_19 , L_57 ,
V_15 -> V_59 ) ;
F_142 () ;
return - V_184 ;
}
F_155 ( V_22 ) ;
F_156 ( V_11 -> V_16 , & V_11 -> V_215 ) ;
F_111 ( V_19 , V_15 ) ;
F_146 ( V_15 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_157 ( V_22 ) ;
if ( F_143 ( V_11 ) )
F_144 ( V_11 , V_22 ) ;
F_71 ( V_19 , L_58 ,
F_145 ( V_22 ) ? L_59 : L_60 ,
V_15 -> V_59 ) ;
V_212 = F_137 ( V_11 -> V_69 ) ;
F_148 ( V_11 -> V_216 , NULL ) ;
if ( ! V_211 && ( ! V_11 -> V_52 . V_94 ||
F_20 ( V_11 ) != V_4 ) ) {
if ( F_151 ( V_19 -> V_86 , V_22 -> V_193 ) &&
F_19 ( V_11 ) )
F_118 ( V_19 , L_61 ,
V_15 -> V_59 , V_22 -> V_193 ,
V_19 -> V_59 , V_15 -> V_59 ) ;
}
if ( F_36 ( V_11 -> V_101 ) == V_22 )
F_148 ( V_11 -> V_101 , NULL ) ;
if ( V_212 == V_22 )
F_69 ( V_11 , NULL ) ;
if ( F_16 ( V_11 ) ) {
F_158 ( V_11 , V_22 ) ;
}
if ( V_211 ) {
F_148 ( V_11 -> V_69 , NULL ) ;
} else if ( V_212 == V_22 ) {
F_78 ( V_11 ) ;
}
if ( ! F_19 ( V_11 ) ) {
F_18 ( V_11 ) ;
F_152 ( V_19 ) ;
}
F_142 () ;
F_149 () ;
V_11 -> V_210 -- ;
if ( ! F_19 ( V_11 ) ) {
F_44 ( V_89 , V_11 -> V_16 ) ;
F_44 ( V_217 , V_11 -> V_16 ) ;
}
F_91 ( V_11 ) ;
if ( ! ( V_19 -> V_131 & V_177 ) &&
( V_214 & V_177 ) )
F_71 ( V_19 , L_62 ,
V_15 -> V_59 , V_19 -> V_59 ) ;
F_147 ( V_15 , V_19 ) ;
if ( ! F_35 ( V_11 ) ) {
if ( V_213 & V_83 )
F_37 ( V_15 , - 1 ) ;
if ( V_213 & V_84 )
F_39 ( V_15 , - 1 ) ;
F_46 ( V_19 , V_15 ) ;
}
F_83 ( V_22 ) ;
F_150 ( V_15 ) ;
if ( V_11 -> V_52 . V_94 != V_95 ||
F_20 ( V_11 ) != V_4 ) {
F_58 ( V_172 . V_97 , V_22 -> V_193 ) ;
V_172 . V_98 = V_15 -> type ;
F_59 ( V_15 , & V_172 ) ;
}
F_124 ( V_15 , V_22 -> V_190 ) ;
V_15 -> V_150 &= ~ V_196 ;
F_115 ( V_22 ) ;
return 0 ;
}
int F_159 ( struct V_14 * V_19 , struct V_14 * V_15 )
{
return F_153 ( V_19 , V_15 , false ) ;
}
static int F_160 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
int V_158 ;
V_158 = F_159 ( V_19 , V_15 ) ;
if ( V_158 == 0 && ! F_19 ( V_11 ) ) {
V_19 -> V_150 |= V_218 ;
F_71 ( V_19 , L_63 ,
V_19 -> V_59 ) ;
F_161 ( V_19 ) ;
}
return V_158 ;
}
static int F_162 ( struct V_14 * V_19 , struct V_219 * V_220 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
V_220 -> V_221 = F_20 ( V_11 ) ;
V_220 -> V_117 = V_11 -> V_52 . V_117 ;
V_220 -> V_222 = V_11 -> V_210 ;
return 0 ;
}
static int F_163 ( struct V_14 * V_19 , struct V_223 * V_220 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
int V_174 = 0 , V_26 = - V_224 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
if ( V_174 ++ == ( int ) V_220 -> V_225 ) {
V_26 = 0 ;
strcpy ( V_220 -> V_226 , V_22 -> V_16 -> V_59 ) ;
V_220 -> V_29 = V_22 -> V_29 ;
V_220 -> V_114 = F_164 ( V_22 ) ;
V_220 -> V_199 = V_22 -> V_199 ;
break;
}
}
return V_26 ;
}
static int F_165 ( struct V_10 * V_11 )
{
int V_227 , V_228 = 0 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
bool V_229 ;
V_229 = ! F_66 ( V_11 -> V_69 ) ;
F_166 (bond, slave, iter) {
V_22 -> V_230 = V_231 ;
V_227 = F_29 ( V_11 , V_22 -> V_16 , 0 ) ;
switch ( V_22 -> V_29 ) {
case V_30 :
if ( V_227 )
continue;
V_22 -> V_29 = V_41 ;
V_22 -> V_111 = V_11 -> V_52 . V_232 ;
if ( V_22 -> V_111 ) {
F_71 ( V_11 -> V_16 , L_64 ,
( F_20 ( V_11 ) ==
V_4 ) ?
( F_145 ( V_22 ) ?
L_65 : L_66 ) : L_67 ,
V_22 -> V_16 -> V_59 ,
V_11 -> V_52 . V_232 * V_11 -> V_52 . V_117 ) ;
}
case V_41 :
if ( V_227 ) {
V_22 -> V_29 = V_30 ;
V_22 -> V_115 = V_116 ;
F_71 ( V_11 -> V_16 , L_68 ,
( V_11 -> V_52 . V_232 - V_22 -> V_111 ) *
V_11 -> V_52 . V_117 ,
V_22 -> V_16 -> V_59 ) ;
continue;
}
if ( V_22 -> V_111 <= 0 ) {
V_22 -> V_230 = V_42 ;
V_228 ++ ;
continue;
}
V_22 -> V_111 -- ;
break;
case V_42 :
if ( ! V_227 )
continue;
V_22 -> V_29 = V_43 ;
V_22 -> V_111 = V_11 -> V_52 . V_110 ;
if ( V_22 -> V_111 ) {
F_71 ( V_11 -> V_16 , L_69 ,
V_22 -> V_16 -> V_59 ,
V_229 ? 0 :
V_11 -> V_52 . V_110 *
V_11 -> V_52 . V_117 ) ;
}
case V_43 :
if ( ! V_227 ) {
V_22 -> V_29 = V_42 ;
F_71 ( V_11 -> V_16 , L_70 ,
( V_11 -> V_52 . V_110 - V_22 -> V_111 ) *
V_11 -> V_52 . V_117 ,
V_22 -> V_16 -> V_59 ) ;
continue;
}
if ( V_229 )
V_22 -> V_111 = 0 ;
if ( V_22 -> V_111 <= 0 ) {
V_22 -> V_230 = V_30 ;
V_228 ++ ;
V_229 = false ;
continue;
}
V_22 -> V_111 -- ;
break;
}
}
return V_228 ;
}
static void F_167 ( struct V_10 * V_11 )
{
struct V_24 * V_25 ;
struct V_22 * V_22 , * V_108 ;
F_12 (bond, slave, iter) {
switch ( V_22 -> V_230 ) {
case V_231 :
continue;
case V_30 :
V_22 -> V_29 = V_30 ;
V_22 -> V_115 = V_116 ;
V_108 = F_36 ( V_11 -> V_101 ) ;
if ( F_20 ( V_11 ) == V_7 ) {
F_168 ( V_22 ) ;
} else if ( F_20 ( V_11 ) != V_4 ) {
F_136 ( V_22 ) ;
} else if ( V_22 != V_108 ) {
F_168 ( V_22 ) ;
}
F_71 ( V_11 -> V_16 , L_71 ,
V_22 -> V_16 -> V_59 ,
V_22 -> V_34 == V_35 ? 0 : V_22 -> V_34 ,
V_22 -> V_36 ? L_72 : L_73 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_72 ( V_22 , V_30 ) ;
if ( F_16 ( V_11 ) )
F_73 ( V_11 , V_22 ,
V_30 ) ;
if ( F_20 ( V_11 ) == V_5 )
F_144 ( V_11 , NULL ) ;
if ( ! V_11 -> V_69 || V_22 == V_108 )
goto V_233;
continue;
case V_42 :
if ( V_22 -> V_199 < V_234 )
V_22 -> V_199 ++ ;
V_22 -> V_29 = V_42 ;
if ( F_20 ( V_11 ) == V_4 ||
F_20 ( V_11 ) == V_7 )
F_75 ( V_22 ,
V_118 ) ;
F_71 ( V_11 -> V_16 , L_74 ,
V_22 -> V_16 -> V_59 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_72 ( V_22 ,
V_42 ) ;
if ( F_16 ( V_11 ) )
F_73 ( V_11 , V_22 ,
V_42 ) ;
if ( F_20 ( V_11 ) == V_5 )
F_144 ( V_11 , NULL ) ;
if ( V_22 == F_137 ( V_11 -> V_69 ) )
goto V_233;
continue;
default:
F_60 ( V_11 -> V_16 , L_75 ,
V_22 -> V_230 , V_22 -> V_16 -> V_59 ) ;
V_22 -> V_230 = V_231 ;
continue;
}
V_233:
F_141 () ;
F_78 ( V_11 ) ;
F_142 () ;
}
F_18 ( V_11 ) ;
}
static void F_169 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_41 ( V_71 , struct V_10 ,
V_235 . V_71 ) ;
bool V_119 = false ;
unsigned long V_111 ;
V_111 = F_133 ( V_11 -> V_52 . V_117 ) ;
if ( ! F_19 ( V_11 ) )
goto V_236;
F_65 () ;
V_119 = F_64 ( V_11 ) ;
if ( F_165 ( V_11 ) ) {
F_67 () ;
if ( ! F_42 () ) {
V_111 = 1 ;
V_119 = false ;
goto V_236;
}
F_167 ( V_11 ) ;
F_45 () ;
} else
F_67 () ;
V_236:
if ( V_11 -> V_52 . V_117 )
F_43 ( V_11 -> V_73 , & V_11 -> V_235 , V_111 ) ;
if ( V_119 ) {
if ( ! F_42 () )
return;
F_44 ( V_122 , V_11 -> V_16 ) ;
F_45 () ;
}
}
static bool F_170 ( struct V_10 * V_11 , T_8 V_237 )
{
struct V_14 * V_238 ;
struct V_24 * V_25 ;
bool V_158 = false ;
if ( V_237 == F_171 ( V_11 -> V_16 , 0 , V_237 ) )
return true ;
F_65 () ;
F_172 (bond->dev, upper, iter) {
if ( V_237 == F_171 ( V_238 , 0 , V_237 ) ) {
V_158 = true ;
break;
}
}
F_67 () ;
return V_158 ;
}
static void F_173 ( struct V_14 * V_15 , int V_239 ,
T_8 V_240 , T_8 V_241 ,
struct V_242 * V_243 )
{
struct V_12 * V_13 ;
struct V_242 * V_244 = V_243 ;
F_56 ( V_15 , L_76 ,
V_239 , V_15 -> V_59 , & V_240 , & V_241 ) ;
V_13 = F_174 ( V_239 , V_245 , V_240 , V_15 , V_241 ,
NULL , V_15 -> V_86 , NULL ) ;
if ( ! V_13 ) {
F_175 ( L_77 ) ;
return;
}
if ( ! V_243 || V_243 -> V_246 == V_247 )
goto V_248;
V_243 ++ ;
while ( V_243 -> V_246 != V_247 ) {
if ( ! V_243 -> V_249 ) {
V_243 ++ ;
continue;
}
F_56 ( V_15 , L_78 ,
F_176 ( V_244 -> V_246 ) , V_243 -> V_249 ) ;
V_13 = F_177 ( V_13 , V_243 -> V_246 ,
V_243 -> V_249 ) ;
if ( ! V_13 ) {
F_175 ( L_79 ) ;
return;
}
V_243 ++ ;
}
if ( V_244 -> V_249 ) {
F_56 ( V_15 , L_80 ,
F_176 ( V_244 -> V_246 ) , V_244 -> V_249 ) ;
V_13 = F_178 ( V_13 , V_244 -> V_246 ,
V_244 -> V_249 ) ;
if ( ! V_13 ) {
F_175 ( L_81 ) ;
return;
}
}
V_248:
F_179 ( V_13 ) ;
}
struct V_242 * F_180 ( struct V_14 * V_250 ,
struct V_14 * V_251 ,
int V_252 )
{
struct V_242 * V_243 ;
struct V_14 * V_238 ;
struct V_24 * V_25 ;
if ( V_250 == V_251 ) {
V_243 = F_80 ( sizeof( * V_243 ) * ( V_252 + 1 ) , V_160 ) ;
if ( ! V_243 )
return F_181 ( - V_128 ) ;
V_243 [ V_252 ] . V_246 = V_247 ;
return V_243 ;
}
F_182 (start_dev, upper, iter) {
V_243 = F_180 ( V_238 , V_251 , V_252 + 1 ) ;
if ( F_183 ( V_243 ) ) {
if ( F_184 ( V_243 ) )
return V_243 ;
continue;
}
if ( F_185 ( V_238 ) ) {
V_243 [ V_252 ] . V_246 = F_186 ( V_238 ) ;
V_243 [ V_252 ] . V_249 = F_187 ( V_238 ) ;
}
return V_243 ;
}
return NULL ;
}
static void F_188 ( struct V_10 * V_11 , struct V_22 * V_22 )
{
struct V_253 * V_254 ;
struct V_242 * V_243 ;
T_8 * V_255 = V_11 -> V_52 . V_256 , V_172 ;
int V_174 ;
for ( V_174 = 0 ; V_174 < V_202 && V_255 [ V_174 ] ; V_174 ++ ) {
F_56 ( V_11 -> V_16 , L_82 , & V_255 [ V_174 ] ) ;
V_243 = NULL ;
V_254 = F_189 ( F_190 ( V_11 -> V_16 ) , V_255 [ V_174 ] , 0 ,
V_257 , 0 ) ;
if ( F_184 ( V_254 ) ) {
if ( V_11 -> V_52 . V_258 )
F_191 ( L_83 ,
V_11 -> V_16 -> V_59 ,
& V_255 [ V_174 ] ) ;
F_173 ( V_22 -> V_16 , V_259 , V_255 [ V_174 ] ,
0 , V_243 ) ;
continue;
}
if ( V_254 -> V_260 . V_16 == V_11 -> V_16 )
goto V_261;
F_65 () ;
V_243 = F_180 ( V_11 -> V_16 , V_254 -> V_260 . V_16 , 0 ) ;
F_67 () ;
if ( ! F_183 ( V_243 ) )
goto V_261;
F_56 ( V_11 -> V_16 , L_84 ,
& V_255 [ V_174 ] , V_254 -> V_260 . V_16 ? V_254 -> V_260 . V_16 -> V_59 : L_17 ) ;
F_192 ( V_254 ) ;
continue;
V_261:
V_172 = F_171 ( V_254 -> V_260 . V_16 , V_255 [ V_174 ] , 0 ) ;
F_192 ( V_254 ) ;
F_173 ( V_22 -> V_16 , V_259 , V_255 [ V_174 ] ,
V_172 , V_243 ) ;
F_82 ( V_243 ) ;
}
}
static void F_193 ( struct V_10 * V_11 , struct V_22 * V_22 , T_8 V_262 , T_8 V_263 )
{
int V_174 ;
if ( ! V_262 || ! F_170 ( V_11 , V_263 ) ) {
F_56 ( V_11 -> V_16 , L_85 ,
& V_262 , & V_263 ) ;
return;
}
V_174 = F_194 ( V_11 -> V_52 . V_256 , V_262 ) ;
if ( V_174 == - 1 ) {
F_56 ( V_11 -> V_16 , L_86 ,
& V_262 ) ;
return;
}
V_22 -> V_200 = V_116 ;
V_22 -> V_203 [ V_174 ] = V_116 ;
}
int F_195 ( const struct V_12 * V_13 , struct V_10 * V_11 ,
struct V_22 * V_22 )
{
struct V_264 * V_265 = (struct V_264 * ) V_13 -> V_165 ;
struct V_22 * V_69 ;
unsigned char * V_266 ;
T_8 V_262 , V_263 ;
int V_267 , V_268 = V_13 -> V_269 == F_196 ( V_245 ) ;
if ( ! F_197 ( V_11 , V_22 ) ) {
if ( ( F_198 ( V_11 ) && V_268 ) ||
! F_198 ( V_11 ) )
V_22 -> V_200 = V_116 ;
return V_159 ;
} else if ( ! V_268 ) {
return V_159 ;
}
V_267 = F_199 ( V_11 -> V_16 ) ;
F_56 ( V_11 -> V_16 , L_87 ,
V_13 -> V_16 -> V_59 ) ;
if ( V_267 > F_200 ( V_13 ) ) {
V_265 = F_201 ( V_267 , V_160 ) ;
if ( ! V_265 )
goto V_270;
if ( F_202 ( V_13 , 0 , V_265 , V_267 ) < 0 )
goto V_270;
}
if ( V_265 -> V_271 != V_11 -> V_16 -> V_85 ||
V_13 -> V_154 == V_272 ||
V_13 -> V_154 == V_273 ||
V_265 -> V_274 != F_203 ( V_181 ) ||
V_265 -> V_275 != F_203 ( V_276 ) ||
V_265 -> V_277 != 4 )
goto V_270;
V_266 = ( unsigned char * ) ( V_265 + 1 ) ;
V_266 += V_11 -> V_16 -> V_85 ;
memcpy ( & V_262 , V_266 , 4 ) ;
V_266 += 4 + V_11 -> V_16 -> V_85 ;
memcpy ( & V_263 , V_266 , 4 ) ;
F_56 ( V_11 -> V_16 , L_88 ,
V_22 -> V_16 -> V_59 , F_164 ( V_22 ) ,
V_11 -> V_52 . V_258 , F_197 ( V_11 , V_22 ) ,
& V_262 , & V_263 ) ;
V_69 = F_66 ( V_11 -> V_69 ) ;
if ( F_145 ( V_22 ) )
F_193 ( V_11 , V_22 , V_262 , V_263 ) ;
else if ( V_69 &&
F_204 ( F_205 ( V_11 , V_69 ) ,
V_69 -> V_115 ) )
F_193 ( V_11 , V_22 , V_263 , V_262 ) ;
V_270:
if ( V_265 != (struct V_264 * ) V_13 -> V_165 )
F_82 ( V_265 ) ;
return V_159 ;
}
static bool F_206 ( struct V_10 * V_11 , unsigned long V_278 ,
int V_279 )
{
int V_280 = F_133 ( V_11 -> V_52 . V_201 ) ;
return F_207 ( V_116 ,
V_278 - V_280 ,
V_278 + V_279 * V_280 + V_280 / 2 ) ;
}
static void F_208 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_41 ( V_71 , struct V_10 ,
V_281 . V_71 ) ;
struct V_22 * V_22 , * V_212 ;
struct V_24 * V_25 ;
int V_233 = 0 , V_282 = 0 ;
if ( ! F_19 ( V_11 ) )
goto V_236;
F_65 () ;
V_212 = F_66 ( V_11 -> V_69 ) ;
F_166 (bond, slave, iter) {
unsigned long V_283 = F_209 ( V_22 -> V_16 ) ;
if ( V_22 -> V_29 != V_30 ) {
if ( F_206 ( V_11 , V_283 , 1 ) &&
F_206 ( V_11 , V_22 -> V_200 , 1 ) ) {
V_22 -> V_29 = V_30 ;
V_282 = 1 ;
if ( ! V_212 ) {
F_71 ( V_11 -> V_16 , L_89 ,
V_22 -> V_16 -> V_59 ) ;
V_233 = 1 ;
} else {
F_71 ( V_11 -> V_16 , L_90 ,
V_22 -> V_16 -> V_59 ) ;
}
}
} else {
if ( ! F_206 ( V_11 , V_283 , 2 ) ||
! F_206 ( V_11 , V_22 -> V_200 , 2 ) ) {
V_22 -> V_29 = V_42 ;
V_282 = 1 ;
if ( V_22 -> V_199 < V_234 )
V_22 -> V_199 ++ ;
F_71 ( V_11 -> V_16 , L_91 ,
V_22 -> V_16 -> V_59 ) ;
if ( V_22 == V_212 )
V_233 = 1 ;
}
}
if ( F_63 ( V_22 ) )
F_188 ( V_11 , V_22 ) ;
}
F_67 () ;
if ( V_233 || V_282 ) {
if ( ! F_42 () )
goto V_236;
if ( V_282 ) {
F_210 ( V_11 ) ;
if ( F_20 ( V_11 ) == V_5 )
F_144 ( V_11 , NULL ) ;
}
if ( V_233 ) {
F_141 () ;
F_78 ( V_11 ) ;
F_142 () ;
}
F_45 () ;
}
V_236:
if ( V_11 -> V_52 . V_201 )
F_43 ( V_11 -> V_73 , & V_11 -> V_281 ,
F_133 ( V_11 -> V_52 . V_201 ) ) ;
}
static int F_211 ( struct V_10 * V_11 )
{
unsigned long V_283 , V_200 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_228 = 0 ;
F_166 (bond, slave, iter) {
V_22 -> V_230 = V_231 ;
V_200 = F_205 ( V_11 , V_22 ) ;
if ( V_22 -> V_29 != V_30 ) {
if ( F_206 ( V_11 , V_200 , 1 ) ) {
V_22 -> V_230 = V_30 ;
V_228 ++ ;
}
continue;
}
if ( F_206 ( V_11 , V_22 -> V_115 , 2 ) )
continue;
if ( ! F_145 ( V_22 ) &&
! F_137 ( V_11 -> V_216 ) &&
! F_206 ( V_11 , V_200 , 3 ) ) {
V_22 -> V_230 = V_42 ;
V_228 ++ ;
}
V_283 = F_209 ( V_22 -> V_16 ) ;
if ( F_145 ( V_22 ) &&
( ! F_206 ( V_11 , V_283 , 2 ) ||
! F_206 ( V_11 , V_200 , 2 ) ) ) {
V_22 -> V_230 = V_42 ;
V_228 ++ ;
}
}
return V_228 ;
}
static void F_212 ( struct V_10 * V_11 )
{
unsigned long V_283 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
switch ( V_22 -> V_230 ) {
case V_231 :
continue;
case V_30 :
V_283 = F_209 ( V_22 -> V_16 ) ;
if ( F_36 ( V_11 -> V_69 ) != V_22 ||
( ! F_36 ( V_11 -> V_69 ) &&
F_206 ( V_11 , V_283 , 1 ) ) ) {
struct V_22 * V_216 ;
V_216 = F_36 ( V_11 -> V_216 ) ;
V_22 -> V_29 = V_30 ;
if ( V_216 ) {
F_75 (
V_216 ,
V_118 ) ;
F_148 ( V_11 -> V_216 , NULL ) ;
}
F_71 ( V_11 -> V_16 , L_89 ,
V_22 -> V_16 -> V_59 ) ;
if ( ! F_36 ( V_11 -> V_69 ) ||
V_22 == F_36 ( V_11 -> V_101 ) )
goto V_233;
}
continue;
case V_42 :
if ( V_22 -> V_199 < V_234 )
V_22 -> V_199 ++ ;
V_22 -> V_29 = V_42 ;
F_75 ( V_22 ,
V_118 ) ;
F_71 ( V_11 -> V_16 , L_74 ,
V_22 -> V_16 -> V_59 ) ;
if ( V_22 == F_36 ( V_11 -> V_69 ) ) {
F_148 ( V_11 -> V_216 , NULL ) ;
goto V_233;
}
continue;
default:
F_60 ( V_11 -> V_16 , L_92 ,
V_22 -> V_230 , V_22 -> V_16 -> V_59 ) ;
continue;
}
V_233:
F_141 () ;
F_78 ( V_11 ) ;
F_142 () ;
}
F_18 ( V_11 ) ;
}
static bool F_213 ( struct V_10 * V_11 )
{
struct V_22 * V_22 , * V_284 = NULL , * V_170 = NULL ,
* V_285 = F_66 ( V_11 -> V_216 ) ,
* V_69 = F_66 ( V_11 -> V_69 ) ;
struct V_24 * V_25 ;
bool V_261 = false ;
bool V_286 = V_287 ;
if ( V_285 && V_69 )
F_71 ( V_11 -> V_16 , L_93 ,
V_285 -> V_16 -> V_59 ,
V_69 -> V_16 -> V_59 ) ;
if ( V_69 ) {
F_188 ( V_11 , V_69 ) ;
return V_286 ;
}
if ( ! V_285 ) {
V_285 = F_214 ( V_11 ) ;
if ( ! V_285 )
return V_286 ;
}
F_75 ( V_285 , V_287 ) ;
F_166 (bond, slave, iter) {
if ( ! V_261 && ! V_284 && F_63 ( V_22 ) )
V_284 = V_22 ;
if ( V_261 && ! V_170 && F_63 ( V_22 ) )
V_170 = V_22 ;
if ( ! F_63 ( V_22 ) && V_22 -> V_29 == V_30 ) {
V_22 -> V_29 = V_42 ;
if ( V_22 -> V_199 < V_234 )
V_22 -> V_199 ++ ;
F_75 ( V_22 ,
V_287 ) ;
F_71 ( V_11 -> V_16 , L_94 ,
V_22 -> V_16 -> V_59 ) ;
}
if ( V_22 == V_285 )
V_261 = true ;
}
if ( ! V_170 && V_284 )
V_170 = V_284 ;
if ( ! V_170 )
goto V_288;
V_170 -> V_29 = V_43 ;
F_76 ( V_170 , V_287 ) ;
F_188 ( V_11 , V_170 ) ;
V_170 -> V_115 = V_116 ;
F_77 ( V_11 -> V_216 , V_170 ) ;
V_288:
F_166 (bond, slave, iter) {
if ( V_22 -> V_289 ) {
V_286 = V_118 ;
break;
}
}
return V_286 ;
}
static void F_215 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_41 ( V_71 , struct V_10 ,
V_281 . V_71 ) ;
bool V_119 = false ;
bool V_286 = false ;
int V_280 ;
V_280 = F_133 ( V_11 -> V_52 . V_201 ) ;
if ( ! F_19 ( V_11 ) )
goto V_236;
F_65 () ;
V_119 = F_64 ( V_11 ) ;
if ( F_211 ( V_11 ) ) {
F_67 () ;
if ( ! F_42 () ) {
V_280 = 1 ;
V_119 = false ;
goto V_236;
}
F_212 ( V_11 ) ;
F_45 () ;
F_65 () ;
}
V_286 = F_213 ( V_11 ) ;
F_67 () ;
V_236:
if ( V_11 -> V_52 . V_201 )
F_43 ( V_11 -> V_73 , & V_11 -> V_281 , V_280 ) ;
if ( V_119 || V_286 ) {
if ( ! F_42 () )
return;
if ( V_119 )
F_44 ( V_122 ,
V_11 -> V_16 ) ;
if ( V_286 )
F_216 ( V_11 ) ;
F_45 () ;
}
}
static int F_217 ( struct V_10 * V_11 )
{
F_218 ( V_11 ) ;
F_219 ( V_11 ) ;
F_220 ( V_11 ) ;
return V_290 ;
}
static int F_221 ( unsigned long V_291 ,
struct V_14 * V_19 )
{
struct V_10 * V_292 = F_11 ( V_19 ) ;
switch ( V_291 ) {
case V_293 :
return F_217 ( V_292 ) ;
case V_294 :
F_218 ( V_292 ) ;
break;
case V_295 :
F_219 ( V_292 ) ;
break;
case V_122 :
if ( V_292 -> V_112 )
V_292 -> V_112 -- ;
break;
default:
break;
}
return V_290 ;
}
static int F_222 ( unsigned long V_291 ,
struct V_14 * V_15 )
{
struct V_22 * V_22 = F_223 ( V_15 ) , * V_108 ;
struct V_10 * V_11 ;
struct V_14 * V_19 ;
T_3 V_296 ;
T_5 V_297 ;
if ( ! V_22 )
return V_290 ;
V_19 = V_22 -> V_11 -> V_16 ;
V_11 = V_22 -> V_11 ;
V_108 = F_36 ( V_11 -> V_101 ) ;
switch ( V_291 ) {
case V_294 :
if ( V_19 -> type != V_181 )
F_160 ( V_19 , V_15 ) ;
else
F_159 ( V_19 , V_15 ) ;
break;
case V_298 :
case V_299 :
V_296 = V_22 -> V_34 ;
V_297 = V_22 -> V_36 ;
F_25 ( V_22 ) ;
if ( F_20 ( V_11 ) == V_7 ) {
if ( V_296 != V_22 -> V_34 )
F_224 ( V_22 ) ;
if ( V_297 != V_22 -> V_36 )
F_225 ( V_22 ) ;
}
if ( F_143 ( V_11 ) )
F_144 ( V_11 , NULL ) ;
break;
case V_300 :
if ( F_143 ( V_11 ) )
F_144 ( V_11 , NULL ) ;
break;
case V_301 :
break;
case V_293 :
if ( ! F_35 ( V_11 ) ||
! V_11 -> V_52 . V_108 [ 0 ] )
break;
if ( V_22 == V_108 ) {
F_148 ( V_11 -> V_101 , NULL ) ;
} else if ( ! strcmp ( V_15 -> V_59 , V_11 -> V_52 . V_108 ) ) {
F_77 ( V_11 -> V_101 , V_22 ) ;
} else {
break;
}
F_71 ( V_11 -> V_16 , L_95 ,
V_108 ? V_15 -> V_59 : L_96 ) ;
F_141 () ;
F_78 ( V_11 ) ;
F_142 () ;
break;
case V_302 :
F_91 ( V_11 ) ;
break;
case V_74 :
F_44 ( V_291 , V_22 -> V_11 -> V_16 ) ;
break;
default:
break;
}
return V_290 ;
}
static int F_226 ( struct V_303 * V_304 ,
unsigned long V_291 , void * V_305 )
{
struct V_14 * V_306 = F_227 ( V_305 ) ;
F_56 ( V_306 , L_97 , V_291 ) ;
if ( ! ( V_306 -> V_150 & V_196 ) )
return V_290 ;
if ( V_306 -> V_82 & V_307 ) {
F_56 ( V_306 , L_98 ) ;
return F_221 ( V_291 , V_306 ) ;
}
if ( V_306 -> V_82 & V_167 ) {
F_56 ( V_306 , L_99 ) ;
return F_222 ( V_291 , V_306 ) ;
}
return V_290 ;
}
static inline T_3 F_228 ( struct V_12 * V_13 )
{
struct V_308 * V_309 , V_310 ;
V_309 = F_229 ( V_13 , 0 , sizeof( V_310 ) , & V_310 ) ;
if ( V_309 )
return V_309 -> V_166 [ 5 ] ^ V_309 -> V_311 [ 5 ] ^ V_309 -> V_312 ;
return 0 ;
}
static bool F_230 ( struct V_10 * V_11 , struct V_12 * V_13 ,
struct V_313 * V_314 )
{
const struct V_315 * V_316 ;
const struct V_317 * V_318 ;
int V_319 , V_20 = - 1 ;
if ( V_11 -> V_52 . V_320 > V_321 )
return F_231 ( V_13 , V_314 ) ;
V_314 -> V_322 = 0 ;
V_319 = F_232 ( V_13 ) ;
if ( V_13 -> V_269 == F_203 ( V_276 ) ) {
if ( F_5 ( ! F_233 ( V_13 , V_319 + sizeof( * V_318 ) ) ) )
return false ;
V_318 = F_234 ( V_13 ) ;
V_314 -> V_323 = V_318 -> V_92 ;
V_314 -> V_260 = V_318 -> V_324 ;
V_319 += V_318 -> V_325 << 2 ;
if ( ! F_235 ( V_318 ) )
V_20 = V_318 -> V_269 ;
} else if ( V_13 -> V_269 == F_203 ( V_326 ) ) {
if ( F_5 ( ! F_233 ( V_13 , V_319 + sizeof( * V_316 ) ) ) )
return false ;
V_316 = F_236 ( V_13 ) ;
V_314 -> V_323 = ( V_327 T_8 ) F_237 ( & V_316 -> V_92 ) ;
V_314 -> V_260 = ( V_327 T_8 ) F_237 ( & V_316 -> V_324 ) ;
V_319 += sizeof( * V_316 ) ;
V_20 = V_316 -> V_328 ;
} else {
return false ;
}
if ( V_11 -> V_52 . V_320 == V_329 && V_20 >= 0 )
V_314 -> V_322 = F_238 ( V_13 , V_319 , V_20 ) ;
return true ;
}
T_3 F_239 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
struct V_313 V_330 ;
T_3 V_331 ;
if ( V_11 -> V_52 . V_320 == V_332 ||
! F_230 ( V_11 , V_13 , & V_330 ) )
return F_228 ( V_13 ) ;
if ( V_11 -> V_52 . V_320 == V_321 ||
V_11 -> V_52 . V_320 == V_333 )
V_331 = F_228 ( V_13 ) ;
else
V_331 = ( V_327 T_3 ) V_330 . V_322 ;
V_331 ^= ( V_327 T_3 ) V_330 . V_260 ^ ( V_327 T_3 ) V_330 . V_323 ;
V_331 ^= ( V_331 >> 16 ) ;
V_331 ^= ( V_331 >> 8 ) ;
return V_331 ;
}
static void F_240 ( struct V_10 * V_11 )
{
F_241 ( & V_11 -> V_72 ,
F_40 ) ;
F_241 ( & V_11 -> V_334 , V_335 ) ;
F_241 ( & V_11 -> V_235 , F_169 ) ;
if ( F_20 ( V_11 ) == V_4 )
F_241 ( & V_11 -> V_281 , F_215 ) ;
else
F_241 ( & V_11 -> V_281 , F_208 ) ;
F_241 ( & V_11 -> V_336 , V_337 ) ;
F_241 ( & V_11 -> V_338 , V_339 ) ;
}
static void F_242 ( struct V_10 * V_11 )
{
F_243 ( & V_11 -> V_235 ) ;
F_243 ( & V_11 -> V_281 ) ;
F_243 ( & V_11 -> V_334 ) ;
F_243 ( & V_11 -> V_336 ) ;
F_243 ( & V_11 -> V_72 ) ;
F_243 ( & V_11 -> V_338 ) ;
}
static int F_244 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
if ( F_19 ( V_11 ) ) {
F_12 (bond, slave, iter) {
if ( F_35 ( V_11 ) &&
V_22 != F_137 ( V_11 -> V_69 ) ) {
F_75 ( V_22 ,
V_118 ) ;
} else {
F_76 ( V_22 ,
V_118 ) ;
}
}
}
F_240 ( V_11 ) ;
if ( F_16 ( V_11 ) ) {
if ( F_245 ( V_11 , ( F_20 ( V_11 ) == V_9 ) ) )
return - V_128 ;
if ( V_11 -> V_52 . V_340 )
F_43 ( V_11 -> V_73 , & V_11 -> V_334 , 0 ) ;
}
if ( V_11 -> V_52 . V_117 )
F_43 ( V_11 -> V_73 , & V_11 -> V_235 , 0 ) ;
if ( V_11 -> V_52 . V_201 ) {
F_43 ( V_11 -> V_73 , & V_11 -> V_281 , 0 ) ;
V_11 -> F_99 = F_195 ;
}
if ( F_20 ( V_11 ) == V_7 ) {
F_43 ( V_11 -> V_73 , & V_11 -> V_336 , 0 ) ;
V_11 -> F_99 = V_341 ;
F_246 ( V_11 , 1 ) ;
}
if ( F_143 ( V_11 ) )
F_144 ( V_11 , NULL ) ;
return 0 ;
}
static int F_247 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_242 ( V_11 ) ;
V_11 -> V_112 = 0 ;
if ( F_16 ( V_11 ) )
F_248 ( V_11 ) ;
V_11 -> F_99 = NULL ;
return 0 ;
}
static struct V_342 * F_156 ( struct V_14 * V_19 ,
struct V_342 * V_343 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_342 V_344 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
memcpy ( V_343 , & V_11 -> V_215 , sizeof( * V_343 ) ) ;
F_12 (bond, slave, iter) {
const struct V_342 * V_345 =
F_126 ( V_22 -> V_16 , & V_344 ) ;
struct V_342 * V_346 = & V_22 -> V_197 ;
V_343 -> V_347 += V_345 -> V_347 - V_346 -> V_347 ;
V_343 -> V_348 += V_345 -> V_348 - V_346 -> V_348 ;
V_343 -> V_349 += V_345 -> V_349 - V_346 -> V_349 ;
V_343 -> V_350 += V_345 -> V_350 - V_346 -> V_350 ;
V_343 -> V_351 += V_345 -> V_351 - V_346 -> V_351 ; ;
V_343 -> V_352 += V_345 -> V_352 - V_346 -> V_352 ;
V_343 -> V_353 += V_345 -> V_353 - V_346 -> V_353 ;
V_343 -> V_354 += V_345 -> V_354 - V_346 -> V_354 ;
V_343 -> V_355 += V_345 -> V_355 - V_346 -> V_355 ;
V_343 -> V_356 += V_345 -> V_356 - V_346 -> V_356 ;
V_343 -> V_357 += V_345 -> V_357 - V_346 -> V_357 ;
V_343 -> V_358 += V_345 -> V_358 - V_346 -> V_358 ;
V_343 -> V_359 += V_345 -> V_359 - V_346 -> V_359 ;
V_343 -> V_360 += V_345 -> V_360 - V_346 -> V_360 ;
V_343 -> V_361 += V_345 -> V_361 - V_346 -> V_361 ;
V_343 -> V_362 += V_345 -> V_362 - V_346 -> V_362 ;
V_343 -> V_363 += V_345 -> V_363 - V_346 -> V_363 ;
V_343 -> V_364 += V_345 -> V_364 - V_346 -> V_364 ;
V_343 -> V_365 += V_345 -> V_365 - V_346 -> V_365 ;
V_343 -> V_366 += V_345 -> V_366 - V_346 -> V_366 ;
V_343 -> V_367 += V_345 -> V_367 - V_346 -> V_367 ;
memcpy ( V_346 , V_345 , sizeof( * V_345 ) ) ;
}
memcpy ( & V_11 -> V_215 , V_343 , sizeof( * V_343 ) ) ;
return V_343 ;
}
static int F_249 ( struct V_14 * V_19 , struct V_48 * V_49 , int V_368 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_14 * V_15 = NULL ;
struct V_219 V_369 ;
struct V_219 T_9 * V_370 = NULL ;
struct V_223 V_371 ;
struct V_223 T_9 * V_372 = NULL ;
struct V_50 * V_51 = NULL ;
struct V_373 V_374 ;
struct V_375 * V_375 ;
int V_26 = 0 ;
F_56 ( V_19 , L_100 , V_368 ) ;
switch ( V_368 ) {
case V_61 :
V_51 = F_32 ( V_49 ) ;
if ( ! V_51 )
return - V_184 ;
V_51 -> V_376 = 0 ;
case V_64 :
V_51 = F_32 ( V_49 ) ;
if ( ! V_51 )
return - V_184 ;
if ( V_51 -> V_62 == 1 ) {
V_51 -> V_65 = 0 ;
if ( F_22 ( V_11 -> V_16 ) )
V_51 -> V_65 = V_54 ;
}
return 0 ;
case V_377 :
case V_378 :
V_370 = (struct V_219 T_9 * ) V_49 -> V_379 ;
if ( F_250 ( & V_369 , V_370 , sizeof( V_219 ) ) )
return - V_380 ;
V_26 = F_162 ( V_19 , & V_369 ) ;
if ( V_26 == 0 &&
F_251 ( V_370 , & V_369 , sizeof( V_219 ) ) )
return - V_380 ;
return V_26 ;
case V_381 :
case V_382 :
V_372 = (struct V_223 T_9 * ) V_49 -> V_379 ;
if ( F_250 ( & V_371 , V_372 , sizeof( V_223 ) ) )
return - V_380 ;
V_26 = F_163 ( V_19 , & V_371 ) ;
if ( V_26 == 0 &&
F_251 ( V_372 , & V_371 , sizeof( V_223 ) ) )
return - V_380 ;
return V_26 ;
default:
break;
}
V_375 = F_190 ( V_19 ) ;
if ( ! F_252 ( V_375 -> V_383 , V_384 ) )
return - V_176 ;
V_15 = F_253 ( V_375 , V_49 -> V_385 ) ;
F_56 ( V_19 , L_101 , V_15 ) ;
if ( ! V_15 )
return - V_224 ;
F_56 ( V_19 , L_102 , V_15 -> V_59 ) ;
switch ( V_368 ) {
case V_386 :
case V_387 :
V_26 = F_117 ( V_19 , V_15 ) ;
break;
case V_388 :
case V_389 :
V_26 = F_159 ( V_19 , V_15 ) ;
break;
case V_390 :
case V_391 :
F_55 ( V_19 , V_15 ) ;
V_26 = 0 ;
break;
case V_392 :
case V_393 :
F_254 ( & V_374 , V_15 -> V_59 ) ;
V_26 = F_255 ( V_11 , V_394 , & V_374 ) ;
break;
default:
V_26 = - V_186 ;
}
return V_26 ;
}
static void F_256 ( struct V_14 * V_19 , int V_395 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
if ( V_395 & V_83 )
F_34 ( V_11 ,
V_19 -> V_82 & V_83 ? 1 : - 1 ) ;
if ( V_395 & V_84 )
F_38 ( V_11 ,
V_19 -> V_82 & V_84 ? 1 : - 1 ) ;
}
static void F_257 ( struct V_14 * V_19 )
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
F_166 (bond, slave, iter) {
F_129 ( V_22 -> V_16 , V_19 ) ;
F_128 ( V_22 -> V_16 , V_19 ) ;
}
}
F_67 () ;
}
static int F_258 ( struct V_396 * V_397 )
{
struct V_10 * V_11 = F_11 ( V_397 -> V_16 ) ;
const struct V_45 * V_46 ;
struct V_398 V_399 ;
struct V_22 * V_22 ;
int V_158 ;
V_22 = F_259 ( V_11 ) ;
if ( ! V_22 )
return 0 ;
V_46 = V_22 -> V_16 -> V_47 ;
if ( ! V_46 -> V_400 )
return 0 ;
V_399 . V_401 = NULL ;
V_399 . V_402 = NULL ;
V_158 = V_46 -> V_400 ( V_22 -> V_16 , & V_399 ) ;
if ( V_158 )
return V_158 ;
V_397 -> V_399 -> V_402 = V_399 . V_402 ;
if ( ! V_399 . V_401 )
return 0 ;
return V_399 . V_401 ( V_397 ) ;
}
static int F_260 ( struct V_14 * V_16 ,
struct V_398 * V_399 )
{
if ( V_399 -> V_16 == V_16 )
V_399 -> V_401 = F_258 ;
return 0 ;
}
static int F_261 ( struct V_14 * V_19 , int V_403 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_23 ;
struct V_24 * V_25 ;
int V_26 = 0 ;
F_56 ( V_19 , L_103 , V_11 , V_403 ) ;
F_12 (bond, slave, iter) {
F_56 ( V_19 , L_104 ,
V_22 , V_22 -> V_16 -> V_47 -> V_404 ) ;
V_26 = F_124 ( V_22 -> V_16 , V_403 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_105 , V_26 ,
V_22 -> V_16 -> V_59 ) ;
goto V_27;
}
}
V_19 -> V_191 = V_403 ;
return 0 ;
V_27:
F_12 (bond, rollback_slave, iter) {
int V_405 ;
if ( V_23 == V_22 )
break;
V_405 = F_124 ( V_23 -> V_16 , V_19 -> V_191 ) ;
if ( V_405 ) {
F_56 ( V_19 , L_106 ,
V_405 , V_23 -> V_16 -> V_59 ) ;
}
}
return V_26 ;
}
static int F_262 ( struct V_14 * V_19 , void * V_172 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_23 ;
struct V_91 * V_406 = V_172 , V_407 ;
struct V_24 * V_25 ;
int V_26 = 0 ;
if ( F_20 ( V_11 ) == V_9 )
return F_263 ( V_19 , V_172 ) ;
F_56 ( V_19 , L_107 , V_11 ) ;
if ( V_11 -> V_52 . V_94 &&
F_20 ( V_11 ) == V_4 )
return 0 ;
if ( ! F_264 ( V_406 -> V_97 ) )
return - V_408 ;
F_12 (bond, slave, iter) {
F_56 ( V_19 , L_108 , V_22 , V_22 -> V_16 -> V_59 ) ;
V_26 = F_59 ( V_22 -> V_16 , V_172 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_105 , V_26 , V_22 -> V_16 -> V_59 ) ;
goto V_27;
}
}
memcpy ( V_19 -> V_86 , V_406 -> V_97 , V_19 -> V_85 ) ;
return 0 ;
V_27:
memcpy ( V_407 . V_97 , V_19 -> V_86 , V_19 -> V_85 ) ;
V_407 . V_98 = V_19 -> type ;
F_12 (bond, rollback_slave, iter) {
int V_405 ;
if ( V_23 == V_22 )
break;
V_405 = F_59 ( V_23 -> V_16 , & V_407 ) ;
if ( V_405 ) {
F_56 ( V_19 , L_106 ,
V_405 , V_23 -> V_16 -> V_59 ) ;
}
}
return V_26 ;
}
static void F_265 ( struct V_10 * V_11 , struct V_12 * V_13 , int V_225 )
{
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_174 = V_225 ;
F_166 (bond, slave, iter) {
if ( -- V_174 < 0 ) {
if ( F_266 ( V_22 ) ) {
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
return;
}
}
}
V_174 = V_225 ;
F_166 (bond, slave, iter) {
if ( -- V_174 < 0 )
break;
if ( F_266 ( V_22 ) ) {
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
return;
}
}
F_267 ( V_13 ) ;
}
static T_3 F_268 ( struct V_10 * V_11 )
{
T_3 V_225 ;
struct V_409 V_410 ;
int V_411 = V_11 -> V_52 . V_411 ;
switch ( V_411 ) {
case 0 :
V_225 = F_269 () ;
break;
case 1 :
V_225 = V_11 -> V_412 ;
break;
default:
V_410 =
V_11 -> V_52 . V_410 ;
V_225 = F_270 ( V_11 -> V_412 ,
V_410 ) ;
break;
}
V_11 -> V_412 ++ ;
return V_225 ;
}
static int F_271 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_317 * V_318 = F_234 ( V_13 ) ;
struct V_22 * V_22 ;
T_3 V_225 ;
if ( V_318 -> V_269 == V_413 && V_13 -> V_269 == F_203 ( V_276 ) ) {
V_22 = F_66 ( V_11 -> V_69 ) ;
if ( V_22 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_265 ( V_11 , V_13 , 0 ) ;
} else {
int V_210 = F_102 ( V_11 -> V_210 ) ;
if ( F_272 ( V_210 ) ) {
V_225 = F_268 ( V_11 ) ;
F_265 ( V_11 , V_13 , V_225 % V_210 ) ;
} else {
F_267 ( V_13 ) ;
}
}
return V_414 ;
}
static int F_273 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 ;
V_22 = F_66 ( V_11 -> V_69 ) ;
if ( V_22 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_267 ( V_13 ) ;
return V_414 ;
}
void F_274 ( struct V_10 * V_11 , unsigned long V_111 )
{
F_43 ( V_11 -> V_73 , & V_11 -> V_338 , V_111 ) ;
}
static void V_339 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_41 ( V_71 , struct V_10 ,
V_338 . V_71 ) ;
int V_158 ;
if ( ! F_42 () )
goto V_67;
V_158 = F_144 ( V_11 , NULL ) ;
F_45 () ;
if ( V_158 ) {
F_275 ( L_109 ) ;
goto V_67;
}
return;
V_67:
F_274 ( V_11 , 1 ) ;
}
int F_144 ( struct V_10 * V_11 , struct V_22 * V_415 )
{
struct V_22 * V_22 ;
struct V_24 * V_25 ;
struct V_416 * V_417 , * V_418 ;
int V_419 ;
int V_420 = 0 ;
int V_158 = 0 ;
#ifdef F_276
F_277 ( F_278 ( & V_11 -> V_421 ) ) ;
#endif
V_417 = F_80 ( F_279 ( struct V_416 , V_422 [ V_11 -> V_210 ] ) ,
V_127 ) ;
if ( ! V_417 ) {
V_158 = - V_128 ;
F_280 ( L_110 ) ;
goto V_99;
}
if ( F_20 ( V_11 ) == V_7 ) {
struct V_423 V_423 ;
if ( F_281 ( V_11 , & V_423 ) ) {
F_282 ( L_111 ) ;
F_283 ( V_417 , V_424 ) ;
V_418 = F_36 ( V_11 -> V_425 ) ;
if ( V_418 ) {
F_148 ( V_11 -> V_425 , NULL ) ;
F_283 ( V_418 , V_424 ) ;
}
goto V_99;
}
V_419 = V_423 . V_322 ;
V_420 = V_423 . V_426 ;
}
F_12 (bond, slave, iter) {
if ( F_20 ( V_11 ) == V_7 ) {
struct V_427 * V_428 ;
V_428 = F_114 ( V_22 ) -> V_429 . V_427 ;
if ( ! V_428 || V_428 -> V_430 != V_420 )
continue;
}
if ( ! F_266 ( V_22 ) )
continue;
if ( V_415 == V_22 )
continue;
V_417 -> V_422 [ V_417 -> V_431 ++ ] = V_22 ;
}
V_418 = F_36 ( V_11 -> V_425 ) ;
F_77 ( V_11 -> V_425 , V_417 ) ;
if ( V_418 )
F_283 ( V_418 , V_424 ) ;
V_99:
if ( V_158 != 0 && V_415 ) {
int V_432 ;
V_418 = F_36 ( V_11 -> V_425 ) ;
for ( V_432 = 0 ; V_432 < V_418 -> V_431 ; V_432 ++ ) {
if ( V_415 == V_418 -> V_422 [ V_432 ] ) {
V_418 -> V_422 [ V_432 ] =
V_418 -> V_422 [ V_418 -> V_431 - 1 ] ;
V_418 -> V_431 -- ;
break;
}
}
}
return V_158 ;
}
int F_284 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
struct V_22 * V_22 ;
struct V_416 * V_433 ;
unsigned int V_431 ;
V_433 = F_66 ( V_11 -> V_425 ) ;
V_431 = V_433 ? F_102 ( V_433 -> V_431 ) : 0 ;
if ( F_272 ( V_431 ) ) {
V_22 = V_433 -> V_422 [ F_239 ( V_11 , V_13 ) % V_431 ] ;
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
} else {
F_267 ( V_13 ) ;
F_285 ( & V_16 -> V_354 ) ;
}
return V_414 ;
}
static int F_286 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 = NULL ;
struct V_24 * V_25 ;
F_166 (bond, slave, iter) {
if ( F_287 ( V_11 , V_22 ) )
break;
if ( F_63 ( V_22 ) && V_22 -> V_29 == V_30 ) {
struct V_12 * V_434 = F_288 ( V_13 , V_160 ) ;
if ( ! V_434 ) {
F_175 ( L_112 ,
V_19 -> V_59 , V_435 ) ;
continue;
}
F_2 ( V_11 , V_434 , V_22 -> V_16 ) ;
}
}
if ( V_22 && F_63 ( V_22 ) && V_22 -> V_29 == V_30 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_267 ( V_13 ) ;
return V_414 ;
}
static inline int F_289 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_22 * V_22 = NULL ;
struct V_24 * V_25 ;
if ( ! V_13 -> V_17 )
return 1 ;
F_166 (bond, slave, iter) {
if ( V_22 -> V_189 == V_13 -> V_17 ) {
if ( F_266 ( V_22 ) ) {
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
return 0 ;
}
break;
}
}
return 1 ;
}
static T_2 F_290 ( struct V_14 * V_16 , struct V_12 * V_13 ,
void * V_436 , T_10 V_437 )
{
T_2 V_438 = F_291 ( V_13 ) ? F_292 ( V_13 ) : 0 ;
F_4 ( V_13 ) -> V_18 = V_13 -> V_17 ;
if ( F_5 ( V_438 >= V_16 -> V_439 ) ) {
do {
V_438 -= V_16 -> V_439 ;
} while ( V_438 >= V_16 -> V_439 );
}
return V_438 ;
}
static T_11 F_293 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
if ( F_294 ( V_11 ) &&
! F_289 ( V_11 , V_13 ) )
return V_414 ;
switch ( F_20 ( V_11 ) ) {
case V_3 :
return F_271 ( V_13 , V_16 ) ;
case V_4 :
return F_273 ( V_13 , V_16 ) ;
case V_7 :
case V_5 :
return F_284 ( V_13 , V_16 ) ;
case V_6 :
return F_286 ( V_13 , V_16 ) ;
case V_9 :
return F_295 ( V_13 , V_16 ) ;
case V_8 :
return F_296 ( V_13 , V_16 ) ;
default:
F_60 ( V_16 , L_113 , F_20 ( V_11 ) ) ;
F_297 ( 1 ) ;
F_267 ( V_13 ) ;
return V_414 ;
}
}
static T_11 F_298 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
T_11 V_158 = V_414 ;
if ( F_5 ( F_299 ( V_16 ) ) )
return V_440 ;
F_65 () ;
if ( F_19 ( V_11 ) )
V_158 = F_293 ( V_13 , V_16 ) ;
else
F_267 ( V_13 ) ;
F_67 () ;
return V_158 ;
}
static int F_300 ( struct V_14 * V_19 ,
struct V_31 * V_32 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
unsigned long V_34 = 0 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
V_32 -> V_36 = V_37 ;
V_32 -> V_429 = V_441 ;
F_12 (bond, slave, iter) {
if ( F_266 ( V_22 ) ) {
if ( V_22 -> V_34 != V_35 )
V_34 += V_22 -> V_34 ;
if ( V_32 -> V_36 == V_37 &&
V_22 -> V_36 != V_37 )
V_32 -> V_36 = V_22 -> V_36 ;
}
}
F_301 ( V_32 , V_34 ? : V_35 ) ;
return 0 ;
}
static void F_302 ( struct V_14 * V_19 ,
struct V_442 * V_443 )
{
F_303 ( V_443 -> V_444 , V_445 , sizeof( V_443 -> V_444 ) ) ;
F_303 ( V_443 -> V_446 , V_447 , sizeof( V_443 -> V_446 ) ) ;
snprintf ( V_443 -> V_448 , sizeof( V_443 -> V_448 ) , L_114 ,
V_449 ) ;
}
static void F_304 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
if ( V_11 -> V_73 )
F_305 ( V_11 -> V_73 ) ;
F_306 ( V_19 ) ;
}
void F_307 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_308 ( & V_11 -> V_421 ) ;
V_11 -> V_52 = V_450 ;
V_11 -> V_16 = V_19 ;
F_123 ( V_19 ) ;
V_19 -> V_47 = & V_451 ;
V_19 -> V_55 = & V_452 ;
V_19 -> V_453 = F_304 ;
F_309 ( V_19 , & V_454 ) ;
V_19 -> V_455 = 0 ;
V_19 -> V_82 |= V_307 | V_456 ;
V_19 -> V_150 |= V_196 | V_457 ;
V_19 -> V_150 &= ~ ( V_136 | V_182 ) ;
V_19 -> V_131 |= V_458 ;
V_19 -> V_131 |= V_459 ;
V_19 -> V_460 = V_139 |
V_461 |
V_462 |
V_463 ;
V_19 -> V_460 &= ~ ( V_464 & ~ V_465 ) ;
V_19 -> V_460 |= V_466 ;
V_19 -> V_131 |= V_19 -> V_460 ;
}
static void F_310 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
struct V_416 * V_422 ;
F_86 ( V_19 ) ;
F_12 (bond, slave, iter)
F_153 ( V_19 , V_22 -> V_16 , true ) ;
F_71 ( V_19 , L_115 ) ;
V_422 = F_36 ( V_11 -> V_425 ) ;
if ( V_422 ) {
F_148 ( V_11 -> V_425 , NULL ) ;
F_283 ( V_422 , V_424 ) ;
}
F_311 ( & V_11 -> V_467 ) ;
F_312 ( V_11 ) ;
}
static int F_313 ( struct V_468 * V_52 )
{
int V_469 , V_470 , V_471 , V_174 ;
struct V_373 V_374 ;
const struct V_373 * V_472 ;
int V_473 ;
if ( V_1 ) {
F_254 ( & V_374 , V_1 ) ;
V_472 = F_314 ( F_315 ( V_474 ) , & V_374 ) ;
if ( ! V_472 ) {
F_280 ( L_116 , V_1 ) ;
return - V_184 ;
}
V_221 = V_472 -> V_475 ;
}
if ( V_476 ) {
if ( ( V_221 != V_5 ) &&
( V_221 != V_7 ) &&
( V_221 != V_8 ) ) {
F_316 ( L_117 ,
F_1 ( V_221 ) ) ;
} else {
F_254 ( & V_374 , V_476 ) ;
V_472 = F_314 ( F_315 ( V_477 ) ,
& V_374 ) ;
if ( ! V_472 ) {
F_280 ( L_118 ,
V_476 ) ;
return - V_184 ;
}
V_478 = V_472 -> V_475 ;
}
}
if ( V_479 ) {
if ( V_221 != V_7 ) {
F_316 ( L_119 ,
F_1 ( V_221 ) ) ;
} else {
F_254 ( & V_374 , V_479 ) ;
V_472 = F_314 ( F_315 ( V_480 ) ,
& V_374 ) ;
if ( ! V_472 ) {
F_280 ( L_120 ,
V_479 ) ;
return - V_184 ;
}
V_481 = V_472 -> V_475 ;
}
}
if ( V_482 ) {
F_254 ( & V_374 , V_482 ) ;
V_472 = F_314 ( F_315 ( V_483 ) ,
& V_374 ) ;
if ( ! V_472 ) {
F_280 ( L_121 , V_482 ) ;
return - V_184 ;
}
V_52 -> V_482 = V_472 -> V_475 ;
if ( V_221 != V_7 )
F_317 ( L_122 ) ;
} else {
V_52 -> V_482 = V_484 ;
}
if ( V_485 < 0 ) {
F_317 ( L_123 ,
V_485 , 0 , V_486 , V_487 ) ;
V_485 = V_487 ;
}
if ( V_117 < 0 ) {
F_317 ( L_124 ,
V_117 , V_486 ) ;
V_117 = 0 ;
}
if ( V_110 < 0 ) {
F_317 ( L_125 ,
V_110 , V_486 ) ;
V_110 = 0 ;
}
if ( V_232 < 0 ) {
F_317 ( L_126 ,
V_232 , V_486 ) ;
V_232 = 0 ;
}
if ( ( V_53 != 0 ) && ( V_53 != 1 ) ) {
F_317 ( L_127 ,
V_53 ) ;
V_53 = 1 ;
}
if ( V_120 < 0 || V_120 > 255 ) {
F_317 ( L_128 ,
V_120 ) ;
V_120 = 1 ;
}
if ( ! F_318 ( V_221 ) ) {
if ( ! V_117 ) {
F_317 ( L_129 ) ;
F_317 ( L_130 ) ;
V_117 = V_488 ;
}
}
if ( V_489 < 1 || V_489 > 255 ) {
F_317 ( L_131 ,
V_489 , V_490 ) ;
V_489 = V_490 ;
}
if ( ( V_491 != 0 ) && ( V_491 != 1 ) ) {
F_317 ( L_132 ,
V_491 ) ;
V_491 = 0 ;
}
if ( V_123 < 0 || V_123 > 255 ) {
F_317 ( L_133 ,
V_123 , V_492 ) ;
V_123 = V_492 ;
}
F_319 ( & V_374 , V_411 ) ;
if ( ! F_314 ( F_315 ( V_493 ) , & V_374 ) ) {
F_317 ( L_134 ,
V_411 , V_494 ) ;
V_411 = 1 ;
}
if ( V_221 == V_9 ) {
F_320 ( L_135 ,
V_110 ) ;
}
if ( ! V_117 ) {
if ( V_110 || V_232 ) {
F_317 ( L_136 ,
V_110 , V_232 ) ;
}
} else {
if ( V_201 ) {
F_317 ( L_137 ,
V_117 , V_201 ) ;
V_201 = 0 ;
}
if ( ( V_110 % V_117 ) != 0 ) {
F_317 ( L_138 ,
V_110 , V_117 , ( V_110 / V_117 ) * V_117 ) ;
}
V_110 /= V_117 ;
if ( ( V_232 % V_117 ) != 0 ) {
F_317 ( L_139 ,
V_232 , V_117 ,
( V_232 / V_117 ) * V_117 ) ;
}
V_232 /= V_117 ;
}
if ( V_201 < 0 ) {
F_317 ( L_140 ,
V_201 , V_486 ) ;
V_201 = 0 ;
}
for ( V_495 = 0 , V_174 = 0 ;
( V_495 < V_202 ) && V_496 [ V_174 ] ; V_174 ++ ) {
T_8 V_237 ;
if ( ! F_321 ( V_496 [ V_174 ] , - 1 , ( T_5 * ) & V_237 , - 1 , NULL ) ||
! F_322 ( V_237 ) ) {
F_317 ( L_141 ,
V_496 [ V_174 ] ) ;
V_201 = 0 ;
} else {
if ( F_194 ( V_497 , V_237 ) == - 1 )
V_497 [ V_495 ++ ] = V_237 ;
else
F_317 ( L_142 ,
& V_237 ) ;
}
}
if ( V_201 && ! V_495 ) {
F_317 ( L_143 ,
V_201 ) ;
V_201 = 0 ;
}
if ( V_258 ) {
if ( ! V_201 ) {
F_280 ( L_144 ) ;
return - V_184 ;
}
F_254 ( & V_374 , V_258 ) ;
V_472 = F_314 ( F_315 ( V_498 ) ,
& V_374 ) ;
if ( ! V_472 ) {
F_280 ( L_145 ,
V_258 ) ;
return - V_184 ;
}
V_469 = V_472 -> V_475 ;
} else {
V_469 = 0 ;
}
V_473 = 0 ;
if ( V_499 ) {
F_254 ( & V_374 , V_499 ) ;
V_472 = F_314 ( F_315 ( V_500 ) ,
& V_374 ) ;
if ( ! V_472 ) {
F_280 ( L_146 ,
V_499 ) ;
V_473 = 0 ;
} else {
V_473 = V_472 -> V_475 ;
}
}
if ( V_117 ) {
F_316 ( L_147 , V_117 ) ;
} else if ( V_201 ) {
V_472 = F_323 ( V_498 ,
V_469 ) ;
F_316 ( L_148 ,
V_201 , V_472 -> string , V_495 ) ;
for ( V_174 = 0 ; V_174 < V_495 ; V_174 ++ )
F_324 ( L_149 , V_496 [ V_174 ] ) ;
F_324 ( L_150 ) ;
} else if ( V_485 ) {
F_282 ( L_151 ) ;
}
if ( V_108 && ! F_325 ( V_221 ) ) {
F_317 ( L_152 ,
V_108 , F_1 ( V_221 ) ) ;
V_108 = NULL ;
}
if ( V_108 && V_104 ) {
F_254 ( & V_374 , V_104 ) ;
V_472 = F_314 ( F_315 ( V_501 ) ,
& V_374 ) ;
if ( ! V_472 ) {
F_280 ( L_153 ,
V_104 ) ;
return - V_184 ;
}
V_471 = V_472 -> V_475 ;
} else {
V_471 = V_502 ;
}
if ( V_94 ) {
F_254 ( & V_374 , V_94 ) ;
V_472 = F_314 ( F_315 ( V_503 ) ,
& V_374 ) ;
if ( ! V_472 ) {
F_280 ( L_154 ,
V_94 ) ;
return - V_184 ;
}
V_470 = V_472 -> V_475 ;
if ( V_221 != V_4 )
F_317 ( L_155 ) ;
} else {
V_470 = V_504 ;
}
if ( V_505 == 0 ) {
F_317 ( L_156 ,
V_486 , V_506 ) ;
V_505 = V_506 ;
}
V_52 -> V_1 = V_221 ;
V_52 -> V_320 = V_478 ;
V_52 -> V_117 = V_117 ;
V_52 -> V_120 = V_120 ;
V_52 -> V_201 = V_201 ;
V_52 -> V_258 = V_469 ;
V_52 -> V_499 = V_473 ;
V_52 -> V_110 = V_110 ;
V_52 -> V_232 = V_232 ;
V_52 -> V_53 = V_53 ;
V_52 -> V_481 = V_481 ;
V_52 -> V_108 [ 0 ] = 0 ;
V_52 -> V_104 = V_471 ;
V_52 -> V_94 = V_470 ;
V_52 -> V_489 = V_489 ;
V_52 -> V_491 = V_491 ;
V_52 -> V_123 = V_123 ;
V_52 -> V_507 = V_507 ;
V_52 -> V_505 = V_505 ;
V_52 -> V_411 = V_411 ;
V_52 -> V_340 = 1 ;
if ( V_411 > 0 ) {
V_52 -> V_410 =
V_409 ( V_411 ) ;
} else {
V_52 -> V_410 =
(struct V_409 ) { 0 } ;
}
if ( V_108 ) {
strncpy ( V_52 -> V_108 , V_108 , V_60 ) ;
V_52 -> V_108 [ V_60 - 1 ] = 0 ;
}
memcpy ( V_52 -> V_256 , V_497 , sizeof( V_497 ) ) ;
return 0 ;
}
static void F_326 ( struct V_14 * V_16 ,
struct V_508 * V_438 ,
void * V_509 )
{
F_327 ( & V_438 -> V_510 ,
& V_511 ) ;
}
static void F_328 ( struct V_14 * V_16 )
{
F_327 ( & V_16 -> V_512 ,
& V_513 ) ;
F_329 ( V_16 , F_326 , NULL ) ;
V_16 -> V_514 = & V_515 ;
}
static int F_330 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_516 * V_517 = F_331 ( F_190 ( V_19 ) , V_518 ) ;
F_56 ( V_19 , L_157 ) ;
V_11 -> V_73 = F_332 ( V_19 -> V_59 ) ;
if ( ! V_11 -> V_73 )
return - V_128 ;
F_328 ( V_19 ) ;
F_333 ( & V_11 -> V_467 , & V_517 -> V_519 ) ;
F_334 ( V_11 ) ;
F_335 ( V_11 ) ;
if ( F_336 ( V_19 -> V_86 ) &&
V_19 -> V_87 == V_520 )
F_152 ( V_19 ) ;
return 0 ;
}
unsigned int F_337 ( void )
{
return V_489 ;
}
int F_338 ( struct V_375 * V_375 , const char * V_59 )
{
struct V_14 * V_19 ;
int V_26 ;
F_339 () ;
V_19 = F_340 ( sizeof( struct V_10 ) ,
V_59 ? V_59 : L_158 , V_521 ,
F_307 , V_489 ) ;
if ( ! V_19 ) {
F_280 ( L_159 , V_59 ) ;
F_45 () ;
return - V_128 ;
}
F_341 ( V_19 , V_375 ) ;
V_19 -> V_522 = & V_523 ;
V_26 = F_342 ( V_19 ) ;
F_24 ( V_19 ) ;
F_45 () ;
if ( V_26 < 0 )
F_304 ( V_19 ) ;
return V_26 ;
}
static int T_12 F_343 ( struct V_375 * V_375 )
{
struct V_516 * V_517 = F_331 ( V_375 , V_518 ) ;
V_517 -> V_375 = V_375 ;
F_344 ( & V_517 -> V_519 ) ;
F_345 ( V_517 ) ;
F_346 ( V_517 ) ;
return 0 ;
}
static void T_13 F_347 ( struct V_375 * V_375 )
{
struct V_516 * V_517 = F_331 ( V_375 , V_518 ) ;
struct V_10 * V_11 , * V_524 ;
F_348 ( V_525 ) ;
F_349 ( V_517 ) ;
F_339 () ;
F_350 (bond, tmp_bond, &bn->dev_list, bond_list)
F_351 ( V_11 -> V_16 , & V_525 ) ;
F_352 ( & V_525 ) ;
F_45 () ;
F_353 ( V_517 ) ;
}
static int T_14 F_354 ( void )
{
int V_174 ;
int V_26 ;
F_316 ( L_160 , V_526 ) ;
V_26 = F_313 ( & V_450 ) ;
if ( V_26 )
goto V_99;
V_26 = F_355 ( & V_527 ) ;
if ( V_26 )
goto V_99;
V_26 = F_356 () ;
if ( V_26 )
goto V_528;
F_357 () ;
for ( V_174 = 0 ; V_174 < V_485 ; V_174 ++ ) {
V_26 = F_338 ( & V_529 , NULL ) ;
if ( V_26 )
goto V_67;
}
F_358 ( & V_530 ) ;
V_99:
return V_26 ;
V_67:
F_359 () ;
F_360 () ;
V_528:
F_361 ( & V_527 ) ;
goto V_99;
}
static void T_15 F_362 ( void )
{
F_363 ( & V_530 ) ;
F_359 () ;
F_360 () ;
F_361 ( & V_527 ) ;
#ifdef F_138
F_277 ( F_364 ( & V_531 ) ) ;
#endif
}
