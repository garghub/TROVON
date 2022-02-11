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
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 = NULL ;
struct V_24 * V_25 ;
struct V_129 V_129 ;
struct V_130 * V_131 ;
const struct V_45 * V_132 ;
if ( F_20 ( V_11 ) == V_7 )
if ( F_87 ( V_11 , & V_129 ) )
return;
F_88 () ;
F_89 (bond, slave, iter) {
V_132 = V_22 -> V_16 -> V_47 ;
if ( ! F_63 ( V_22 ) || ! V_132 -> V_133 )
continue;
if ( F_20 ( V_11 ) == V_7 ) {
struct V_134 * V_135 =
F_90 ( V_22 ) -> V_136 . V_134 ;
if ( V_135 &&
V_135 -> V_137 != V_129 . V_138 )
continue;
}
V_131 = F_91 ( V_22 -> V_16 -> V_139 ) ;
if ( F_92 ( & V_131 -> V_140 ) )
continue;
V_132 -> V_133 ( V_22 -> V_16 ) ;
F_93 ( & V_131 -> V_140 ) ;
}
F_94 () ;
}
static void F_95 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter)
if ( F_63 ( V_22 ) )
F_84 ( V_22 ) ;
}
static int F_96 ( struct V_14 * V_16 , struct V_130 * V_131 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_67 = 0 ;
F_12 (bond, slave, iter) {
V_67 = F_80 ( V_22 ) ;
if ( V_67 ) {
F_95 ( V_16 ) ;
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
V_142 = V_141 | V_143 ;
V_141 &= ~ V_144 ;
V_141 |= V_145 ;
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
unsigned int V_146 = V_147 |
V_148 ;
T_6 V_149 = V_150 ;
T_6 V_151 = V_152 ;
struct V_14 * V_19 = V_11 -> V_16 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
unsigned short V_153 = V_154 ;
unsigned int V_155 = V_156 ;
T_2 V_157 = V_158 ;
if ( ! F_19 ( V_11 ) )
goto V_159;
V_149 &= V_145 ;
F_12 (bond, slave, iter) {
V_149 = F_98 ( V_149 ,
V_22 -> V_16 -> V_149 , V_150 ) ;
V_151 = F_98 ( V_151 ,
V_22 -> V_16 -> V_160 ,
V_152 ) ;
V_146 &= V_22 -> V_16 -> V_161 ;
if ( V_22 -> V_16 -> V_162 > V_153 )
V_153 = V_22 -> V_16 -> V_162 ;
V_155 = F_101 ( V_155 , V_22 -> V_16 -> V_155 ) ;
V_157 = F_101 ( V_157 , V_22 -> V_16 -> V_157 ) ;
}
V_159:
V_19 -> V_149 = V_149 ;
V_19 -> V_160 = V_151 | V_163 ;
V_19 -> V_162 = V_153 ;
V_19 -> V_157 = V_157 ;
F_102 ( V_19 , V_155 ) ;
V_19 -> V_161 &= ~ V_147 ;
if ( ( V_19 -> V_161 & V_148 ) &&
V_146 == ( V_147 | V_148 ) )
V_19 -> V_161 |= V_147 ;
F_103 ( V_19 ) ;
}
static void F_104 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
V_19 -> V_164 = V_15 -> V_164 ;
V_19 -> type = V_15 -> type ;
V_19 -> V_162 = V_15 -> V_162 ;
V_19 -> V_85 = V_15 -> V_85 ;
memcpy ( V_19 -> V_165 , V_15 -> V_165 ,
V_15 -> V_85 ) ;
}
static bool F_105 ( struct V_12 * V_13 ,
struct V_22 * V_22 ,
struct V_10 * V_11 )
{
if ( F_106 ( V_22 ) ) {
if ( F_20 ( V_11 ) == V_9 &&
V_13 -> V_166 != V_167 &&
V_13 -> V_166 != V_168 )
return false ;
return true ;
}
return false ;
}
static T_7 F_107 ( struct V_12 * * V_169 )
{
struct V_12 * V_13 = * V_169 ;
struct V_22 * V_22 ;
struct V_10 * V_11 ;
int (* F_108)( const struct V_12 * , struct V_10 * ,
struct V_22 * );
int V_170 = V_171 ;
V_13 = F_109 ( V_13 , V_172 ) ;
if ( F_5 ( ! V_13 ) )
return V_173 ;
* V_169 = V_13 ;
V_22 = F_110 ( V_13 -> V_16 ) ;
V_11 = V_22 -> V_11 ;
F_108 = F_111 ( V_11 -> F_108 ) ;
if ( F_108 ) {
V_170 = F_108 ( V_13 , V_11 , V_22 ) ;
if ( V_170 == V_173 ) {
F_112 ( V_13 ) ;
return V_170 ;
}
}
if ( F_105 ( V_13 , V_22 , V_11 ) ) {
return V_174 ;
}
V_13 -> V_16 = V_11 -> V_16 ;
if ( F_20 ( V_11 ) == V_9 &&
V_11 -> V_16 -> V_161 & V_175 &&
V_13 -> V_166 == V_176 ) {
if ( F_5 ( F_113 ( V_13 ,
V_13 -> V_177 - F_114 ( V_13 ) ) ) ) {
F_115 ( V_13 ) ;
return V_173 ;
}
F_58 ( F_116 ( V_13 ) -> V_178 , V_11 -> V_16 -> V_86 ) ;
}
return V_170 ;
}
static int F_117 ( struct V_14 * V_19 ,
struct V_14 * V_15 ,
struct V_22 * V_22 )
{
int V_67 ;
V_67 = F_118 ( V_15 , V_19 , V_22 ) ;
if ( V_67 )
return V_67 ;
V_15 -> V_82 |= V_179 ;
F_119 ( V_180 , V_15 , V_179 , V_127 ) ;
return 0 ;
}
static void F_120 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
F_121 ( V_15 , V_19 ) ;
V_15 -> V_82 &= ~ V_179 ;
F_119 ( V_180 , V_15 , V_179 , V_127 ) ;
}
static struct V_22 * F_122 ( struct V_10 * V_11 )
{
struct V_22 * V_22 = NULL ;
V_22 = F_81 ( sizeof( struct V_22 ) , V_127 ) ;
if ( ! V_22 )
return NULL ;
if ( F_20 ( V_11 ) == V_7 ) {
F_90 ( V_22 ) = F_81 ( sizeof( struct V_181 ) ,
V_127 ) ;
if ( ! F_90 ( V_22 ) ) {
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
F_83 ( F_90 ( V_22 ) ) ;
F_83 ( V_22 ) ;
}
static void F_125 ( struct V_10 * V_11 , struct V_182 * V_183 )
{
V_183 -> V_184 = F_20 ( V_11 ) ;
V_183 -> V_117 = V_11 -> V_52 . V_117 ;
V_183 -> V_185 = V_11 -> V_186 ;
}
static void F_126 ( struct V_22 * V_22 , struct V_187 * V_183 )
{
strcpy ( V_183 -> V_188 , V_22 -> V_16 -> V_59 ) ;
V_183 -> V_29 = V_22 -> V_29 ;
V_183 -> V_114 = F_127 ( V_22 ) ;
V_183 -> V_189 = V_22 -> V_189 ;
}
static void F_128 ( struct V_14 * V_16 ,
struct V_190 * V_183 )
{
F_129 () ;
F_130 ( V_16 , V_183 ) ;
F_45 () ;
}
static void F_131 ( struct V_70 * V_191 )
{
struct V_192 * V_193 =
F_41 ( V_191 , struct V_192 , V_71 . V_71 ) ;
F_128 ( V_193 -> V_16 , & V_193 -> V_194 ) ;
F_132 ( V_193 -> V_16 ) ;
F_83 ( V_193 ) ;
}
void F_133 ( struct V_22 * V_22 )
{
struct V_10 * V_11 = V_22 -> V_11 ;
struct V_192 * V_195 = F_81 ( sizeof( * V_195 ) , V_172 ) ;
if ( ! V_195 )
return;
F_134 ( V_22 -> V_16 ) ;
V_195 -> V_16 = V_22 -> V_16 ;
F_126 ( V_22 , & V_195 -> V_194 . V_22 ) ;
F_125 ( V_11 , & V_195 -> V_194 . V_196 ) ;
F_135 ( & V_195 -> V_71 , F_131 ) ;
F_43 ( V_22 -> V_11 -> V_73 , & V_195 -> V_71 , 0 ) ;
}
int F_136 ( struct V_14 * V_19 , struct V_14 * V_15 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
const struct V_45 * V_46 = V_15 -> V_47 ;
struct V_22 * V_197 = NULL , * V_198 ;
struct V_91 V_199 ;
int V_200 ;
int V_26 = 0 , V_201 ;
if ( ! V_11 -> V_52 . V_53 &&
V_15 -> V_55 -> V_56 == NULL &&
V_46 -> V_57 == NULL ) {
F_137 ( V_19 , L_22 ,
V_15 -> V_59 ) ;
}
if ( V_15 -> V_82 & V_179 ) {
F_56 ( V_19 , L_23 ) ;
return - V_202 ;
}
if ( V_19 == V_15 ) {
F_60 ( V_19 , L_24 ) ;
return - V_203 ;
}
if ( V_15 -> V_141 & V_204 ) {
F_56 ( V_19 , L_25 ,
V_15 -> V_59 ) ;
if ( F_138 ( V_19 ) ) {
F_60 ( V_19 , L_26 ,
V_15 -> V_59 , V_19 -> V_59 ) ;
return - V_203 ;
} else {
F_137 ( V_19 , L_27 ,
V_15 -> V_59 , V_15 -> V_59 ,
V_19 -> V_59 ) ;
}
} else {
F_56 ( V_19 , L_28 ,
V_15 -> V_59 ) ;
}
if ( ( V_15 -> V_82 & V_205 ) ) {
F_60 ( V_19 , L_29 ,
V_15 -> V_59 ) ;
V_26 = - V_203 ;
goto V_206;
}
if ( ! F_19 ( V_11 ) ) {
if ( V_19 -> type != V_15 -> type ) {
F_56 ( V_19 , L_30 ,
V_19 -> type , V_15 -> type ) ;
V_26 = F_44 ( V_207 ,
V_19 ) ;
V_26 = F_139 ( V_26 ) ;
if ( V_26 ) {
F_60 ( V_19 , L_31 ) ;
V_26 = - V_202 ;
goto V_206;
}
F_140 ( V_19 ) ;
F_141 ( V_19 ) ;
if ( V_15 -> type != V_208 )
F_104 ( V_19 , V_15 ) ;
else {
F_142 ( V_19 ) ;
V_19 -> V_161 &= ~ V_209 ;
}
F_44 ( V_210 ,
V_19 ) ;
}
} else if ( V_19 -> type != V_15 -> type ) {
F_60 ( V_19 , L_32 ,
V_15 -> V_59 , V_15 -> type , V_19 -> type ) ;
V_26 = - V_211 ;
goto V_206;
}
if ( V_46 -> V_212 == NULL ) {
F_137 ( V_19 , L_33 ) ;
if ( F_20 ( V_11 ) == V_4 &&
V_11 -> V_52 . V_94 != V_95 ) {
if ( ! F_19 ( V_11 ) ) {
V_11 -> V_52 . V_94 = V_95 ;
F_137 ( V_19 , L_34 ) ;
} else {
F_60 ( V_19 , L_35 ) ;
V_26 = - V_213 ;
goto V_206;
}
}
}
F_44 ( V_214 , V_15 ) ;
if ( ! F_19 ( V_11 ) &&
V_11 -> V_16 -> V_87 == V_215 )
F_55 ( V_11 -> V_16 , V_15 ) ;
V_197 = F_122 ( V_11 ) ;
if ( ! V_197 ) {
V_26 = - V_128 ;
goto V_206;
}
V_197 -> V_11 = V_11 ;
V_197 -> V_16 = V_15 ;
V_197 -> V_216 = 0 ;
V_197 -> V_217 = V_15 -> V_218 ;
V_26 = F_143 ( V_15 , V_11 -> V_16 -> V_218 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_36 , V_26 ) ;
goto V_219;
}
F_58 ( V_197 -> V_220 , V_15 -> V_86 ) ;
if ( ! V_11 -> V_52 . V_94 ||
F_20 ( V_11 ) != V_4 ) {
memcpy ( V_199 . V_97 , V_19 -> V_86 , V_19 -> V_85 ) ;
V_199 . V_98 = V_15 -> type ;
V_26 = F_59 ( V_15 , & V_199 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_37 , V_26 ) ;
goto V_221;
}
}
V_26 = F_144 ( V_15 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_38 , V_15 -> V_59 ) ;
goto V_222;
}
V_15 -> V_161 |= V_223 ;
F_145 ( V_197 -> V_16 , & V_197 -> V_224 ) ;
if ( F_16 ( V_11 ) ) {
V_26 = F_146 ( V_11 , V_197 ) ;
if ( V_26 )
goto V_225;
}
if ( ! F_35 ( V_11 ) ) {
if ( V_19 -> V_82 & V_83 ) {
V_26 = F_37 ( V_15 , 1 ) ;
if ( V_26 )
goto V_225;
}
if ( V_19 -> V_82 & V_84 ) {
V_26 = F_39 ( V_15 , 1 ) ;
if ( V_26 )
goto V_225;
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
F_60 ( V_19 , L_39 ,
V_15 -> V_59 ) ;
goto V_225;
}
V_198 = F_151 ( V_11 ) ;
V_197 -> V_111 = 0 ;
V_197 -> V_189 = 0 ;
F_25 ( V_197 ) ;
V_197 -> V_226 = V_116 -
( F_152 ( V_11 -> V_52 . V_227 ) + 1 ) ;
for ( V_201 = 0 ; V_201 < V_228 ; V_201 ++ )
V_197 -> V_229 [ V_201 ] = V_197 -> V_226 ;
if ( V_11 -> V_52 . V_117 && ! V_11 -> V_52 . V_53 ) {
V_200 = F_29 ( V_11 , V_15 , 1 ) ;
if ( ( V_200 == - 1 ) && ! V_11 -> V_52 . V_227 ) {
F_137 ( V_19 , L_40 ,
V_15 -> V_59 ) ;
} else if ( V_200 == - 1 ) {
F_137 ( V_19 , L_41 ,
V_15 -> V_59 ) ;
}
}
if ( V_11 -> V_52 . V_117 ) {
if ( F_29 ( V_11 , V_15 , 0 ) == V_54 ) {
if ( V_11 -> V_52 . V_110 ) {
F_72 ( V_197 ,
V_43 ) ;
V_197 -> V_111 = V_11 -> V_52 . V_110 ;
} else {
F_72 ( V_197 ,
V_30 ) ;
}
} else {
F_72 ( V_197 , V_42 ) ;
}
} else if ( V_11 -> V_52 . V_227 ) {
F_72 ( V_197 ,
( F_22 ( V_15 ) ?
V_30 : V_42 ) ) ;
} else {
F_72 ( V_197 , V_30 ) ;
}
if ( V_197 -> V_29 != V_42 )
V_197 -> V_115 = V_116 ;
F_56 ( V_19 , L_42 ,
V_197 -> V_29 == V_42 ? L_43 :
( V_197 -> V_29 == V_30 ? L_44 : L_45 ) ) ;
if ( F_35 ( V_11 ) && V_11 -> V_52 . V_108 [ 0 ] ) {
if ( strcmp ( V_11 -> V_52 . V_108 , V_197 -> V_16 -> V_59 ) == 0 ) {
F_78 ( V_11 -> V_101 , V_197 ) ;
V_11 -> V_103 = true ;
}
}
switch ( F_20 ( V_11 ) ) {
case V_4 :
F_76 ( V_197 ,
V_118 ) ;
break;
case V_7 :
F_76 ( V_197 , V_118 ) ;
if ( ! V_198 ) {
F_90 ( V_197 ) -> V_230 = 1 ;
F_153 ( V_11 , 1000 / V_231 ) ;
} else {
F_90 ( V_197 ) -> V_230 =
F_90 ( V_198 ) -> V_230 + 1 ;
}
F_154 ( V_197 ) ;
break;
case V_8 :
case V_9 :
F_155 ( V_197 ) ;
F_76 ( V_197 , V_118 ) ;
break;
default:
F_56 ( V_19 , L_46 ) ;
F_155 ( V_197 ) ;
if ( ! F_156 ( V_11 -> V_69 ) &&
V_197 -> V_29 == V_30 )
F_78 ( V_11 -> V_69 , V_197 ) ;
break;
}
#ifdef F_157
V_15 -> V_139 = V_11 -> V_16 -> V_139 ;
if ( V_15 -> V_139 ) {
if ( F_80 ( V_197 ) ) {
F_71 ( V_19 , L_47 ) ;
V_26 = - V_202 ;
goto V_232;
}
}
#endif
if ( ! ( V_19 -> V_141 & V_233 ) )
F_158 ( V_15 ) ;
V_26 = F_159 ( V_15 , F_107 ,
V_197 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_48 , V_26 ) ;
goto V_232;
}
V_26 = F_117 ( V_19 , V_15 , V_197 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_49 , V_26 ) ;
goto V_234;
}
V_26 = F_160 ( V_197 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_50 , V_26 ) ;
goto V_235;
}
V_11 -> V_186 ++ ;
F_100 ( V_11 ) ;
F_18 ( V_11 ) ;
if ( F_35 ( V_11 ) ) {
F_161 () ;
F_79 ( V_11 ) ;
F_162 () ;
}
if ( F_163 ( V_11 ) )
F_164 ( V_11 , NULL ) ;
F_71 ( V_19 , L_51 ,
V_15 -> V_59 ,
F_165 ( V_197 ) ? L_52 : L_53 ,
V_197 -> V_29 != V_42 ? L_54 : L_55 ) ;
F_133 ( V_197 ) ;
return 0 ;
V_235:
F_120 ( V_19 , V_15 ) ;
V_234:
F_166 ( V_15 ) ;
V_232:
if ( ! F_35 ( V_11 ) )
F_46 ( V_19 , V_15 ) ;
F_167 ( V_15 , V_19 ) ;
if ( F_156 ( V_11 -> V_101 ) == V_197 )
F_168 ( V_11 -> V_101 , NULL ) ;
if ( F_156 ( V_11 -> V_69 ) == V_197 ) {
F_161 () ;
F_69 ( V_11 , NULL ) ;
F_79 ( V_11 ) ;
F_162 () ;
}
F_169 () ;
F_84 ( V_197 ) ;
V_225:
V_15 -> V_161 &= ~ V_223 ;
F_170 ( V_15 ) ;
V_222:
if ( ! V_11 -> V_52 . V_94 ||
F_20 ( V_11 ) != V_4 ) {
F_58 ( V_199 . V_97 , V_197 -> V_220 ) ;
V_199 . V_98 = V_15 -> type ;
F_59 ( V_15 , & V_199 ) ;
}
V_221:
F_143 ( V_15 , V_197 -> V_217 ) ;
V_219:
F_123 ( V_197 ) ;
V_206:
if ( ! F_19 ( V_11 ) &&
F_171 ( V_19 -> V_86 , V_15 -> V_86 ) )
F_172 ( V_19 ) ;
return V_26 ;
}
static int F_173 ( struct V_14 * V_19 ,
struct V_14 * V_15 ,
bool V_236 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_237 ;
struct V_91 V_199 ;
int V_238 = V_19 -> V_82 ;
T_6 V_239 = V_19 -> V_141 ;
if ( ! ( V_15 -> V_82 & V_179 ) ||
! F_174 ( V_15 , V_19 ) ) {
F_56 ( V_19 , L_56 ,
V_15 -> V_59 ) ;
return - V_211 ;
}
F_161 () ;
V_22 = F_8 ( V_11 , V_15 ) ;
if ( ! V_22 ) {
F_71 ( V_19 , L_57 ,
V_15 -> V_59 ) ;
F_162 () ;
return - V_211 ;
}
F_175 ( V_22 ) ;
F_176 ( V_11 -> V_16 , & V_11 -> V_240 ) ;
F_120 ( V_19 , V_15 ) ;
F_166 ( V_15 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_177 ( V_22 ) ;
if ( F_163 ( V_11 ) )
F_164 ( V_11 , V_22 ) ;
F_71 ( V_19 , L_58 ,
F_165 ( V_22 ) ? L_59 : L_60 ,
V_15 -> V_59 ) ;
V_237 = F_156 ( V_11 -> V_69 ) ;
F_168 ( V_11 -> V_241 , NULL ) ;
if ( ! V_236 && ( ! V_11 -> V_52 . V_94 ||
F_20 ( V_11 ) != V_4 ) ) {
if ( F_171 ( V_19 -> V_86 , V_22 -> V_220 ) &&
F_19 ( V_11 ) )
F_137 ( V_19 , L_61 ,
V_15 -> V_59 , V_22 -> V_220 ,
V_19 -> V_59 , V_15 -> V_59 ) ;
}
if ( F_36 ( V_11 -> V_101 ) == V_22 )
F_168 ( V_11 -> V_101 , NULL ) ;
if ( V_237 == V_22 )
F_69 ( V_11 , NULL ) ;
if ( F_16 ( V_11 ) ) {
F_178 ( V_11 , V_22 ) ;
}
if ( V_236 ) {
F_168 ( V_11 -> V_69 , NULL ) ;
} else if ( V_237 == V_22 ) {
F_79 ( V_11 ) ;
}
if ( ! F_19 ( V_11 ) ) {
F_18 ( V_11 ) ;
F_172 ( V_19 ) ;
}
F_162 () ;
F_169 () ;
V_11 -> V_186 -- ;
if ( ! F_19 ( V_11 ) ) {
F_44 ( V_89 , V_11 -> V_16 ) ;
F_44 ( V_242 , V_11 -> V_16 ) ;
}
F_100 ( V_11 ) ;
if ( ! ( V_19 -> V_141 & V_204 ) &&
( V_239 & V_204 ) )
F_71 ( V_19 , L_62 ,
V_15 -> V_59 , V_19 -> V_59 ) ;
F_167 ( V_15 , V_19 ) ;
if ( ! F_35 ( V_11 ) ) {
if ( V_238 & V_83 )
F_37 ( V_15 , - 1 ) ;
if ( V_238 & V_84 )
F_39 ( V_15 , - 1 ) ;
F_46 ( V_19 , V_15 ) ;
}
F_84 ( V_22 ) ;
F_170 ( V_15 ) ;
if ( V_11 -> V_52 . V_94 != V_95 ||
F_20 ( V_11 ) != V_4 ) {
F_58 ( V_199 . V_97 , V_22 -> V_220 ) ;
V_199 . V_98 = V_15 -> type ;
F_59 ( V_15 , & V_199 ) ;
}
F_143 ( V_15 , V_22 -> V_217 ) ;
V_15 -> V_161 &= ~ V_223 ;
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
int V_170 ;
V_170 = F_179 ( V_19 , V_15 ) ;
if ( V_170 == 0 && ! F_19 ( V_11 ) ) {
V_19 -> V_161 |= V_243 ;
F_71 ( V_19 , L_63 ,
V_19 -> V_59 ) ;
F_181 ( V_19 ) ;
}
return V_170 ;
}
static int F_182 ( struct V_14 * V_19 , struct V_182 * V_183 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_125 ( V_11 , V_183 ) ;
return 0 ;
}
static int F_183 ( struct V_14 * V_19 , struct V_187 * V_183 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
int V_201 = 0 , V_26 = - V_244 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
if ( V_201 ++ == ( int ) V_183 -> V_245 ) {
V_26 = 0 ;
F_126 ( V_22 , V_183 ) ;
break;
}
}
return V_26 ;
}
static int F_184 ( struct V_10 * V_11 )
{
int V_246 , V_247 = 0 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
bool V_248 ;
V_248 = ! F_66 ( V_11 -> V_69 ) ;
F_89 (bond, slave, iter) {
V_22 -> V_249 = V_250 ;
V_246 = F_29 ( V_11 , V_22 -> V_16 , 0 ) ;
switch ( V_22 -> V_29 ) {
case V_30 :
if ( V_246 )
continue;
F_72 ( V_22 , V_41 ) ;
V_22 -> V_111 = V_11 -> V_52 . V_251 ;
if ( V_22 -> V_111 ) {
F_71 ( V_11 -> V_16 , L_64 ,
( F_20 ( V_11 ) ==
V_4 ) ?
( F_165 ( V_22 ) ?
L_65 : L_66 ) : L_67 ,
V_22 -> V_16 -> V_59 ,
V_11 -> V_52 . V_251 * V_11 -> V_52 . V_117 ) ;
}
case V_41 :
if ( V_246 ) {
F_72 ( V_22 , V_30 ) ;
V_22 -> V_115 = V_116 ;
F_71 ( V_11 -> V_16 , L_68 ,
( V_11 -> V_52 . V_251 - V_22 -> V_111 ) *
V_11 -> V_52 . V_117 ,
V_22 -> V_16 -> V_59 ) ;
continue;
}
if ( V_22 -> V_111 <= 0 ) {
V_22 -> V_249 = V_42 ;
V_247 ++ ;
continue;
}
V_22 -> V_111 -- ;
break;
case V_42 :
if ( ! V_246 )
continue;
F_72 ( V_22 , V_43 ) ;
V_22 -> V_111 = V_11 -> V_52 . V_110 ;
if ( V_22 -> V_111 ) {
F_71 ( V_11 -> V_16 , L_69 ,
V_22 -> V_16 -> V_59 ,
V_248 ? 0 :
V_11 -> V_52 . V_110 *
V_11 -> V_52 . V_117 ) ;
}
case V_43 :
if ( ! V_246 ) {
F_72 ( V_22 ,
V_42 ) ;
F_71 ( V_11 -> V_16 , L_70 ,
( V_11 -> V_52 . V_110 - V_22 -> V_111 ) *
V_11 -> V_52 . V_117 ,
V_22 -> V_16 -> V_59 ) ;
continue;
}
if ( V_248 )
V_22 -> V_111 = 0 ;
if ( V_22 -> V_111 <= 0 ) {
V_22 -> V_249 = V_30 ;
V_247 ++ ;
V_248 = false ;
continue;
}
V_22 -> V_111 -- ;
break;
}
}
return V_247 ;
}
static void F_185 ( struct V_10 * V_11 )
{
struct V_24 * V_25 ;
struct V_22 * V_22 , * V_108 ;
F_12 (bond, slave, iter) {
switch ( V_22 -> V_249 ) {
case V_250 :
continue;
case V_30 :
F_72 ( V_22 , V_30 ) ;
V_22 -> V_115 = V_116 ;
V_108 = F_36 ( V_11 -> V_101 ) ;
if ( F_20 ( V_11 ) == V_7 ) {
F_186 ( V_22 ) ;
} else if ( F_20 ( V_11 ) != V_4 ) {
F_155 ( V_22 ) ;
} else if ( V_22 != V_108 ) {
F_186 ( V_22 ) ;
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
F_164 ( V_11 , NULL ) ;
if ( ! V_11 -> V_69 || V_22 == V_108 )
goto V_252;
continue;
case V_42 :
if ( V_22 -> V_189 < V_253 )
V_22 -> V_189 ++ ;
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
F_164 ( V_11 , NULL ) ;
if ( V_22 == F_156 ( V_11 -> V_69 ) )
goto V_252;
continue;
default:
F_60 ( V_11 -> V_16 , L_75 ,
V_22 -> V_249 , V_22 -> V_16 -> V_59 ) ;
V_22 -> V_249 = V_250 ;
continue;
}
V_252:
F_161 () ;
F_79 ( V_11 ) ;
F_162 () ;
}
F_18 ( V_11 ) ;
}
static void F_187 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_41 ( V_71 , struct V_10 ,
V_254 . V_71 ) ;
bool V_119 = false ;
unsigned long V_111 ;
V_111 = F_152 ( V_11 -> V_52 . V_117 ) ;
if ( ! F_19 ( V_11 ) )
goto V_255;
F_65 () ;
V_119 = F_64 ( V_11 ) ;
if ( F_184 ( V_11 ) ) {
F_67 () ;
if ( ! F_42 () ) {
V_111 = 1 ;
V_119 = false ;
goto V_255;
}
F_185 ( V_11 ) ;
F_45 () ;
} else
F_67 () ;
V_255:
if ( V_11 -> V_52 . V_117 )
F_43 ( V_11 -> V_73 , & V_11 -> V_254 , V_111 ) ;
if ( V_119 ) {
if ( ! F_42 () )
return;
F_44 ( V_122 , V_11 -> V_16 ) ;
F_45 () ;
}
}
static bool F_188 ( struct V_10 * V_11 , T_8 V_256 )
{
struct V_14 * V_257 ;
struct V_24 * V_25 ;
bool V_170 = false ;
if ( V_256 == F_189 ( V_11 -> V_16 , 0 , V_256 ) )
return true ;
F_65 () ;
F_190 (bond->dev, upper, iter) {
if ( V_256 == F_189 ( V_257 , 0 , V_256 ) ) {
V_170 = true ;
break;
}
}
F_67 () ;
return V_170 ;
}
static void F_191 ( struct V_14 * V_15 , int V_258 ,
T_8 V_259 , T_8 V_260 ,
struct V_261 * V_262 )
{
struct V_12 * V_13 ;
struct V_261 * V_263 = V_262 ;
F_56 ( V_15 , L_76 ,
V_258 , V_15 -> V_59 , & V_259 , & V_260 ) ;
V_13 = F_192 ( V_258 , V_264 , V_259 , V_15 , V_260 ,
NULL , V_15 -> V_86 , NULL ) ;
if ( ! V_13 ) {
F_193 ( L_77 ) ;
return;
}
if ( ! V_262 || V_262 -> V_265 == V_266 )
goto V_267;
V_262 ++ ;
while ( V_262 -> V_265 != V_266 ) {
if ( ! V_262 -> V_268 ) {
V_262 ++ ;
continue;
}
F_56 ( V_15 , L_78 ,
F_194 ( V_263 -> V_265 ) , V_262 -> V_268 ) ;
V_13 = F_195 ( V_13 , V_262 -> V_265 ,
V_262 -> V_268 ) ;
if ( ! V_13 ) {
F_193 ( L_79 ) ;
return;
}
V_262 ++ ;
}
if ( V_263 -> V_268 ) {
F_56 ( V_15 , L_80 ,
F_194 ( V_263 -> V_265 ) , V_263 -> V_268 ) ;
F_196 ( V_13 , V_263 -> V_265 ,
V_263 -> V_268 ) ;
}
V_267:
F_197 ( V_13 ) ;
}
struct V_261 * F_198 ( struct V_14 * V_269 ,
struct V_14 * V_270 ,
int V_271 )
{
struct V_261 * V_262 ;
struct V_14 * V_257 ;
struct V_24 * V_25 ;
if ( V_269 == V_270 ) {
V_262 = F_81 ( sizeof( * V_262 ) * ( V_271 + 1 ) , V_172 ) ;
if ( ! V_262 )
return F_199 ( - V_128 ) ;
V_262 [ V_271 ] . V_265 = V_266 ;
return V_262 ;
}
F_200 (start_dev, upper, iter) {
V_262 = F_198 ( V_257 , V_270 , V_271 + 1 ) ;
if ( F_201 ( V_262 ) ) {
if ( F_202 ( V_262 ) )
return V_262 ;
continue;
}
if ( F_203 ( V_257 ) ) {
V_262 [ V_271 ] . V_265 = F_204 ( V_257 ) ;
V_262 [ V_271 ] . V_268 = F_205 ( V_257 ) ;
}
return V_262 ;
}
return NULL ;
}
static void F_206 ( struct V_10 * V_11 , struct V_22 * V_22 )
{
struct V_272 * V_273 ;
struct V_261 * V_262 ;
T_8 * V_274 = V_11 -> V_52 . V_275 , V_199 ;
int V_201 ;
for ( V_201 = 0 ; V_201 < V_228 && V_274 [ V_201 ] ; V_201 ++ ) {
F_56 ( V_11 -> V_16 , L_81 , & V_274 [ V_201 ] ) ;
V_262 = NULL ;
V_273 = F_207 ( F_208 ( V_11 -> V_16 ) , V_274 [ V_201 ] , 0 ,
V_276 , 0 ) ;
if ( F_202 ( V_273 ) ) {
if ( V_11 -> V_52 . V_277 )
F_209 ( L_82 ,
V_11 -> V_16 -> V_59 ,
& V_274 [ V_201 ] ) ;
F_191 ( V_22 -> V_16 , V_278 , V_274 [ V_201 ] ,
0 , V_262 ) ;
continue;
}
if ( V_273 -> V_279 . V_16 == V_11 -> V_16 )
goto V_280;
F_65 () ;
V_262 = F_198 ( V_11 -> V_16 , V_273 -> V_279 . V_16 , 0 ) ;
F_67 () ;
if ( ! F_201 ( V_262 ) )
goto V_280;
F_56 ( V_11 -> V_16 , L_83 ,
& V_274 [ V_201 ] , V_273 -> V_279 . V_16 ? V_273 -> V_279 . V_16 -> V_59 : L_17 ) ;
F_210 ( V_273 ) ;
continue;
V_280:
V_199 = F_189 ( V_273 -> V_279 . V_16 , V_274 [ V_201 ] , 0 ) ;
F_210 ( V_273 ) ;
F_191 ( V_22 -> V_16 , V_278 , V_274 [ V_201 ] ,
V_199 , V_262 ) ;
F_83 ( V_262 ) ;
}
}
static void F_211 ( struct V_10 * V_11 , struct V_22 * V_22 , T_8 V_281 , T_8 V_282 )
{
int V_201 ;
if ( ! V_281 || ! F_188 ( V_11 , V_282 ) ) {
F_56 ( V_11 -> V_16 , L_84 ,
& V_281 , & V_282 ) ;
return;
}
V_201 = F_212 ( V_11 -> V_52 . V_275 , V_281 ) ;
if ( V_201 == - 1 ) {
F_56 ( V_11 -> V_16 , L_85 ,
& V_281 ) ;
return;
}
V_22 -> V_226 = V_116 ;
V_22 -> V_229 [ V_201 ] = V_116 ;
}
int F_213 ( const struct V_12 * V_13 , struct V_10 * V_11 ,
struct V_22 * V_22 )
{
struct V_283 * V_284 = (struct V_283 * ) V_13 -> V_177 ;
struct V_22 * V_69 ;
unsigned char * V_285 ;
T_8 V_281 , V_282 ;
int V_286 , V_287 = V_13 -> V_288 == F_214 ( V_264 ) ;
if ( ! F_215 ( V_11 , V_22 ) ) {
if ( ( F_216 ( V_11 ) && V_287 ) ||
! F_216 ( V_11 ) )
V_22 -> V_226 = V_116 ;
return V_171 ;
} else if ( ! V_287 ) {
return V_171 ;
}
V_286 = F_217 ( V_11 -> V_16 ) ;
F_56 ( V_11 -> V_16 , L_86 ,
V_13 -> V_16 -> V_59 ) ;
if ( V_286 > F_218 ( V_13 ) ) {
V_284 = F_219 ( V_286 , V_172 ) ;
if ( ! V_284 )
goto V_289;
if ( F_220 ( V_13 , 0 , V_284 , V_286 ) < 0 )
goto V_289;
}
if ( V_284 -> V_290 != V_11 -> V_16 -> V_85 ||
V_13 -> V_166 == V_291 ||
V_13 -> V_166 == V_292 ||
V_284 -> V_293 != F_221 ( V_208 ) ||
V_284 -> V_294 != F_221 ( V_295 ) ||
V_284 -> V_296 != 4 )
goto V_289;
V_285 = ( unsigned char * ) ( V_284 + 1 ) ;
V_285 += V_11 -> V_16 -> V_85 ;
memcpy ( & V_281 , V_285 , 4 ) ;
V_285 += 4 + V_11 -> V_16 -> V_85 ;
memcpy ( & V_282 , V_285 , 4 ) ;
F_56 ( V_11 -> V_16 , L_87 ,
V_22 -> V_16 -> V_59 , F_127 ( V_22 ) ,
V_11 -> V_52 . V_277 , F_215 ( V_11 , V_22 ) ,
& V_281 , & V_282 ) ;
V_69 = F_66 ( V_11 -> V_69 ) ;
if ( F_165 ( V_22 ) )
F_211 ( V_11 , V_22 , V_281 , V_282 ) ;
else if ( V_69 &&
F_222 ( F_223 ( V_11 , V_69 ) ,
V_69 -> V_115 ) )
F_211 ( V_11 , V_22 , V_282 , V_281 ) ;
V_289:
if ( V_284 != (struct V_283 * ) V_13 -> V_177 )
F_83 ( V_284 ) ;
return V_171 ;
}
static bool F_224 ( struct V_10 * V_11 , unsigned long V_297 ,
int V_298 )
{
int V_299 = F_152 ( V_11 -> V_52 . V_227 ) ;
return F_225 ( V_116 ,
V_297 - V_299 ,
V_297 + V_298 * V_299 + V_299 / 2 ) ;
}
static void F_226 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_41 ( V_71 , struct V_10 ,
V_300 . V_71 ) ;
struct V_22 * V_22 , * V_237 ;
struct V_24 * V_25 ;
int V_252 = 0 , V_301 = 0 ;
if ( ! F_19 ( V_11 ) )
goto V_255;
F_65 () ;
V_237 = F_66 ( V_11 -> V_69 ) ;
F_89 (bond, slave, iter) {
unsigned long V_302 = F_227 ( V_22 -> V_16 ) ;
if ( V_22 -> V_29 != V_30 ) {
if ( F_224 ( V_11 , V_302 , 1 ) &&
F_224 ( V_11 , V_22 -> V_226 , 1 ) ) {
V_22 -> V_29 = V_30 ;
V_301 = 1 ;
if ( ! V_237 ) {
F_71 ( V_11 -> V_16 , L_88 ,
V_22 -> V_16 -> V_59 ) ;
V_252 = 1 ;
} else {
F_71 ( V_11 -> V_16 , L_89 ,
V_22 -> V_16 -> V_59 ) ;
}
}
} else {
if ( ! F_224 ( V_11 , V_302 , 2 ) ||
! F_224 ( V_11 , V_22 -> V_226 , 2 ) ) {
V_22 -> V_29 = V_42 ;
V_301 = 1 ;
if ( V_22 -> V_189 < V_253 )
V_22 -> V_189 ++ ;
F_71 ( V_11 -> V_16 , L_90 ,
V_22 -> V_16 -> V_59 ) ;
if ( V_22 == V_237 )
V_252 = 1 ;
}
}
if ( F_63 ( V_22 ) )
F_206 ( V_11 , V_22 ) ;
}
F_67 () ;
if ( V_252 || V_301 ) {
if ( ! F_42 () )
goto V_255;
if ( V_301 ) {
F_228 ( V_11 ) ;
if ( F_20 ( V_11 ) == V_5 )
F_164 ( V_11 , NULL ) ;
}
if ( V_252 ) {
F_161 () ;
F_79 ( V_11 ) ;
F_162 () ;
}
F_45 () ;
}
V_255:
if ( V_11 -> V_52 . V_227 )
F_43 ( V_11 -> V_73 , & V_11 -> V_300 ,
F_152 ( V_11 -> V_52 . V_227 ) ) ;
}
static int F_229 ( struct V_10 * V_11 )
{
unsigned long V_302 , V_226 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_247 = 0 ;
F_89 (bond, slave, iter) {
V_22 -> V_249 = V_250 ;
V_226 = F_223 ( V_11 , V_22 ) ;
if ( V_22 -> V_29 != V_30 ) {
if ( F_224 ( V_11 , V_226 , 1 ) ) {
V_22 -> V_249 = V_30 ;
V_247 ++ ;
}
continue;
}
if ( F_224 ( V_11 , V_22 -> V_115 , 2 ) )
continue;
if ( ! F_165 ( V_22 ) &&
! F_156 ( V_11 -> V_241 ) &&
! F_224 ( V_11 , V_226 , 3 ) ) {
V_22 -> V_249 = V_42 ;
V_247 ++ ;
}
V_302 = F_227 ( V_22 -> V_16 ) ;
if ( F_165 ( V_22 ) &&
( ! F_224 ( V_11 , V_302 , 2 ) ||
! F_224 ( V_11 , V_226 , 2 ) ) ) {
V_22 -> V_249 = V_42 ;
V_247 ++ ;
}
}
return V_247 ;
}
static void F_230 ( struct V_10 * V_11 )
{
unsigned long V_302 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
switch ( V_22 -> V_249 ) {
case V_250 :
continue;
case V_30 :
V_302 = F_227 ( V_22 -> V_16 ) ;
if ( F_36 ( V_11 -> V_69 ) != V_22 ||
( ! F_36 ( V_11 -> V_69 ) &&
F_224 ( V_11 , V_302 , 1 ) ) ) {
struct V_22 * V_241 ;
V_241 = F_36 ( V_11 -> V_241 ) ;
F_72 ( V_22 , V_30 ) ;
if ( V_241 ) {
F_76 (
V_241 ,
V_118 ) ;
F_168 ( V_11 -> V_241 , NULL ) ;
}
F_71 ( V_11 -> V_16 , L_88 ,
V_22 -> V_16 -> V_59 ) ;
if ( ! F_36 ( V_11 -> V_69 ) ||
V_22 == F_36 ( V_11 -> V_101 ) )
goto V_252;
}
continue;
case V_42 :
if ( V_22 -> V_189 < V_253 )
V_22 -> V_189 ++ ;
F_72 ( V_22 , V_42 ) ;
F_76 ( V_22 ,
V_118 ) ;
F_71 ( V_11 -> V_16 , L_74 ,
V_22 -> V_16 -> V_59 ) ;
if ( V_22 == F_36 ( V_11 -> V_69 ) ) {
F_168 ( V_11 -> V_241 , NULL ) ;
goto V_252;
}
continue;
default:
F_60 ( V_11 -> V_16 , L_91 ,
V_22 -> V_249 , V_22 -> V_16 -> V_59 ) ;
continue;
}
V_252:
F_161 () ;
F_79 ( V_11 ) ;
F_162 () ;
}
F_18 ( V_11 ) ;
}
static bool F_231 ( struct V_10 * V_11 )
{
struct V_22 * V_22 , * V_303 = NULL , * V_197 = NULL ,
* V_304 = F_66 ( V_11 -> V_241 ) ,
* V_69 = F_66 ( V_11 -> V_69 ) ;
struct V_24 * V_25 ;
bool V_280 = false ;
bool V_305 = V_306 ;
if ( V_304 && V_69 )
F_71 ( V_11 -> V_16 , L_92 ,
V_304 -> V_16 -> V_59 ,
V_69 -> V_16 -> V_59 ) ;
if ( V_69 ) {
F_206 ( V_11 , V_69 ) ;
return V_305 ;
}
if ( ! V_304 ) {
V_304 = F_232 ( V_11 ) ;
if ( ! V_304 )
return V_305 ;
}
F_76 ( V_304 , V_306 ) ;
F_89 (bond, slave, iter) {
if ( ! V_280 && ! V_303 && F_63 ( V_22 ) )
V_303 = V_22 ;
if ( V_280 && ! V_197 && F_63 ( V_22 ) )
V_197 = V_22 ;
if ( ! F_63 ( V_22 ) && V_22 -> V_29 == V_30 ) {
F_72 ( V_22 , V_42 ) ;
if ( V_22 -> V_189 < V_253 )
V_22 -> V_189 ++ ;
F_76 ( V_22 ,
V_306 ) ;
F_71 ( V_11 -> V_16 , L_93 ,
V_22 -> V_16 -> V_59 ) ;
}
if ( V_22 == V_304 )
V_280 = true ;
}
if ( ! V_197 && V_303 )
V_197 = V_303 ;
if ( ! V_197 )
goto V_307;
F_72 ( V_197 , V_43 ) ;
F_77 ( V_197 , V_306 ) ;
F_206 ( V_11 , V_197 ) ;
V_197 -> V_115 = V_116 ;
F_78 ( V_11 -> V_241 , V_197 ) ;
V_307:
F_89 (bond, slave, iter) {
if ( V_22 -> V_308 ) {
V_305 = V_118 ;
break;
}
}
return V_305 ;
}
static void F_233 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_41 ( V_71 , struct V_10 ,
V_300 . V_71 ) ;
bool V_119 = false ;
bool V_305 = false ;
int V_299 ;
V_299 = F_152 ( V_11 -> V_52 . V_227 ) ;
if ( ! F_19 ( V_11 ) )
goto V_255;
F_65 () ;
V_119 = F_64 ( V_11 ) ;
if ( F_229 ( V_11 ) ) {
F_67 () ;
if ( ! F_42 () ) {
V_299 = 1 ;
V_119 = false ;
goto V_255;
}
F_230 ( V_11 ) ;
F_45 () ;
F_65 () ;
}
V_305 = F_231 ( V_11 ) ;
F_67 () ;
V_255:
if ( V_11 -> V_52 . V_227 )
F_43 ( V_11 -> V_73 , & V_11 -> V_300 , V_299 ) ;
if ( V_119 || V_305 ) {
if ( ! F_42 () )
return;
if ( V_119 )
F_44 ( V_122 ,
V_11 -> V_16 ) ;
if ( V_305 )
F_234 ( V_11 ) ;
F_45 () ;
}
}
static int F_235 ( struct V_10 * V_11 )
{
F_236 ( V_11 ) ;
F_237 ( V_11 ) ;
F_238 ( V_11 ) ;
return V_309 ;
}
static int F_239 ( unsigned long V_310 ,
struct V_14 * V_19 )
{
struct V_10 * V_311 = F_11 ( V_19 ) ;
switch ( V_310 ) {
case V_312 :
return F_235 ( V_311 ) ;
case V_313 :
F_236 ( V_311 ) ;
break;
case V_314 :
F_237 ( V_311 ) ;
break;
case V_122 :
if ( V_311 -> V_112 )
V_311 -> V_112 -- ;
break;
default:
break;
}
return V_309 ;
}
static int F_240 ( unsigned long V_310 ,
struct V_14 * V_15 )
{
struct V_22 * V_22 = F_241 ( V_15 ) , * V_108 ;
struct V_10 * V_11 ;
struct V_14 * V_19 ;
T_3 V_315 ;
T_5 V_316 ;
if ( ! V_22 )
return V_309 ;
V_19 = V_22 -> V_11 -> V_16 ;
V_11 = V_22 -> V_11 ;
V_108 = F_36 ( V_11 -> V_101 ) ;
switch ( V_310 ) {
case V_313 :
if ( V_19 -> type != V_208 )
F_180 ( V_19 , V_15 ) ;
else
F_179 ( V_19 , V_15 ) ;
break;
case V_317 :
case V_318 :
V_315 = V_22 -> V_34 ;
V_316 = V_22 -> V_36 ;
F_25 ( V_22 ) ;
if ( F_20 ( V_11 ) == V_7 ) {
if ( V_315 != V_22 -> V_34 )
F_242 ( V_22 ) ;
if ( V_316 != V_22 -> V_36 )
F_243 ( V_22 ) ;
}
case V_319 :
if ( F_163 ( V_11 ) )
F_164 ( V_11 , NULL ) ;
break;
case V_320 :
break;
case V_312 :
if ( ! F_35 ( V_11 ) ||
! V_11 -> V_52 . V_108 [ 0 ] )
break;
if ( V_22 == V_108 ) {
F_168 ( V_11 -> V_101 , NULL ) ;
} else if ( ! strcmp ( V_15 -> V_59 , V_11 -> V_52 . V_108 ) ) {
F_78 ( V_11 -> V_101 , V_22 ) ;
} else {
break;
}
F_71 ( V_11 -> V_16 , L_94 ,
V_108 ? V_15 -> V_59 : L_95 ) ;
F_161 () ;
F_79 ( V_11 ) ;
F_162 () ;
break;
case V_321 :
F_100 ( V_11 ) ;
break;
case V_74 :
F_44 ( V_310 , V_22 -> V_11 -> V_16 ) ;
break;
default:
break;
}
return V_309 ;
}
static int F_244 ( struct V_322 * V_323 ,
unsigned long V_310 , void * V_324 )
{
struct V_14 * V_325 = F_245 ( V_324 ) ;
F_56 ( V_325 , L_96 , V_310 ) ;
if ( ! ( V_325 -> V_161 & V_223 ) )
return V_309 ;
if ( V_325 -> V_82 & V_326 ) {
F_56 ( V_325 , L_97 ) ;
return F_239 ( V_310 , V_325 ) ;
}
if ( V_325 -> V_82 & V_179 ) {
F_56 ( V_325 , L_98 ) ;
return F_240 ( V_310 , V_325 ) ;
}
return V_309 ;
}
static inline T_3 F_246 ( struct V_12 * V_13 )
{
struct V_327 * V_328 , V_329 ;
V_328 = F_247 ( V_13 , 0 , sizeof( V_329 ) , & V_329 ) ;
if ( V_328 )
return V_328 -> V_178 [ 5 ] ^ V_328 -> V_330 [ 5 ] ^ V_328 -> V_331 ;
return 0 ;
}
static bool F_248 ( struct V_10 * V_11 , struct V_12 * V_13 ,
struct V_332 * V_333 )
{
const struct V_334 * V_335 ;
const struct V_336 * V_337 ;
int V_338 , V_20 = - 1 ;
if ( V_11 -> V_52 . V_339 > V_340 )
return F_249 ( V_13 , V_333 ) ;
V_333 -> V_341 = 0 ;
V_338 = F_250 ( V_13 ) ;
if ( V_13 -> V_288 == F_221 ( V_295 ) ) {
if ( F_5 ( ! F_251 ( V_13 , V_338 + sizeof( * V_337 ) ) ) )
return false ;
V_337 = F_252 ( V_13 ) ;
V_333 -> V_342 = V_337 -> V_92 ;
V_333 -> V_279 = V_337 -> V_343 ;
V_338 += V_337 -> V_344 << 2 ;
if ( ! F_253 ( V_337 ) )
V_20 = V_337 -> V_288 ;
} else if ( V_13 -> V_288 == F_221 ( V_345 ) ) {
if ( F_5 ( ! F_251 ( V_13 , V_338 + sizeof( * V_335 ) ) ) )
return false ;
V_335 = F_254 ( V_13 ) ;
V_333 -> V_342 = ( V_346 T_8 ) F_255 ( & V_335 -> V_92 ) ;
V_333 -> V_279 = ( V_346 T_8 ) F_255 ( & V_335 -> V_343 ) ;
V_338 += sizeof( * V_335 ) ;
V_20 = V_335 -> V_347 ;
} else {
return false ;
}
if ( V_11 -> V_52 . V_339 == V_348 && V_20 >= 0 )
V_333 -> V_341 = F_256 ( V_13 , V_338 , V_20 ) ;
return true ;
}
T_3 F_257 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
struct V_332 V_349 ;
T_3 V_350 ;
if ( V_11 -> V_52 . V_339 == V_351 ||
! F_248 ( V_11 , V_13 , & V_349 ) )
return F_246 ( V_13 ) ;
if ( V_11 -> V_52 . V_339 == V_340 ||
V_11 -> V_52 . V_339 == V_352 )
V_350 = F_246 ( V_13 ) ;
else
V_350 = ( V_346 T_3 ) V_349 . V_341 ;
V_350 ^= ( V_346 T_3 ) V_349 . V_279 ^ ( V_346 T_3 ) V_349 . V_342 ;
V_350 ^= ( V_350 >> 16 ) ;
V_350 ^= ( V_350 >> 8 ) ;
return V_350 ;
}
static void F_258 ( struct V_10 * V_11 )
{
F_135 ( & V_11 -> V_72 ,
F_40 ) ;
F_135 ( & V_11 -> V_353 , V_354 ) ;
F_135 ( & V_11 -> V_254 , F_187 ) ;
if ( F_20 ( V_11 ) == V_4 )
F_135 ( & V_11 -> V_300 , F_233 ) ;
else
F_135 ( & V_11 -> V_300 , F_226 ) ;
F_135 ( & V_11 -> V_355 , V_356 ) ;
F_135 ( & V_11 -> V_357 , V_358 ) ;
}
static void F_259 ( struct V_10 * V_11 )
{
F_260 ( & V_11 -> V_254 ) ;
F_260 ( & V_11 -> V_300 ) ;
F_260 ( & V_11 -> V_353 ) ;
F_260 ( & V_11 -> V_355 ) ;
F_260 ( & V_11 -> V_72 ) ;
F_260 ( & V_11 -> V_357 ) ;
}
static int F_261 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
if ( F_19 ( V_11 ) ) {
F_12 (bond, slave, iter) {
if ( F_35 ( V_11 ) &&
V_22 != F_156 ( V_11 -> V_69 ) ) {
F_76 ( V_22 ,
V_118 ) ;
} else if ( F_20 ( V_11 ) != V_7 ) {
F_77 ( V_22 ,
V_118 ) ;
}
}
}
F_258 ( V_11 ) ;
if ( F_16 ( V_11 ) ) {
if ( F_262 ( V_11 , ( F_20 ( V_11 ) == V_9 ) ) )
return - V_128 ;
if ( V_11 -> V_52 . V_359 )
F_43 ( V_11 -> V_73 , & V_11 -> V_353 , 0 ) ;
}
if ( V_11 -> V_52 . V_117 )
F_43 ( V_11 -> V_73 , & V_11 -> V_254 , 0 ) ;
if ( V_11 -> V_52 . V_227 ) {
F_43 ( V_11 -> V_73 , & V_11 -> V_300 , 0 ) ;
V_11 -> F_108 = F_213 ;
}
if ( F_20 ( V_11 ) == V_7 ) {
F_43 ( V_11 -> V_73 , & V_11 -> V_355 , 0 ) ;
V_11 -> F_108 = V_360 ;
F_263 ( V_11 , 1 ) ;
}
if ( F_163 ( V_11 ) )
F_164 ( V_11 , NULL ) ;
return 0 ;
}
static int F_264 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_259 ( V_11 ) ;
V_11 -> V_112 = 0 ;
if ( F_16 ( V_11 ) )
F_265 ( V_11 ) ;
V_11 -> F_108 = NULL ;
return 0 ;
}
static struct V_361 * F_176 ( struct V_14 * V_19 ,
struct V_361 * V_362 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_361 V_363 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
memcpy ( V_362 , & V_11 -> V_240 , sizeof( * V_362 ) ) ;
F_12 (bond, slave, iter) {
const struct V_361 * V_364 =
F_145 ( V_22 -> V_16 , & V_363 ) ;
struct V_361 * V_365 = & V_22 -> V_224 ;
V_362 -> V_366 += V_364 -> V_366 - V_365 -> V_366 ;
V_362 -> V_367 += V_364 -> V_367 - V_365 -> V_367 ;
V_362 -> V_368 += V_364 -> V_368 - V_365 -> V_368 ;
V_362 -> V_369 += V_364 -> V_369 - V_365 -> V_369 ;
V_362 -> V_370 += V_364 -> V_370 - V_365 -> V_370 ; ;
V_362 -> V_371 += V_364 -> V_371 - V_365 -> V_371 ;
V_362 -> V_372 += V_364 -> V_372 - V_365 -> V_372 ;
V_362 -> V_373 += V_364 -> V_373 - V_365 -> V_373 ;
V_362 -> V_374 += V_364 -> V_374 - V_365 -> V_374 ;
V_362 -> V_375 += V_364 -> V_375 - V_365 -> V_375 ;
V_362 -> V_376 += V_364 -> V_376 - V_365 -> V_376 ;
V_362 -> V_377 += V_364 -> V_377 - V_365 -> V_377 ;
V_362 -> V_378 += V_364 -> V_378 - V_365 -> V_378 ;
V_362 -> V_379 += V_364 -> V_379 - V_365 -> V_379 ;
V_362 -> V_380 += V_364 -> V_380 - V_365 -> V_380 ;
V_362 -> V_381 += V_364 -> V_381 - V_365 -> V_381 ;
V_362 -> V_382 += V_364 -> V_382 - V_365 -> V_382 ;
V_362 -> V_383 += V_364 -> V_383 - V_365 -> V_383 ;
V_362 -> V_384 += V_364 -> V_384 - V_365 -> V_384 ;
V_362 -> V_385 += V_364 -> V_385 - V_365 -> V_385 ;
V_362 -> V_386 += V_364 -> V_386 - V_365 -> V_386 ;
memcpy ( V_365 , V_364 , sizeof( * V_364 ) ) ;
}
memcpy ( & V_11 -> V_240 , V_362 , sizeof( * V_362 ) ) ;
return V_362 ;
}
static int F_266 ( struct V_14 * V_19 , struct V_48 * V_49 , int V_387 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_14 * V_15 = NULL ;
struct V_182 V_388 ;
struct V_182 T_9 * V_389 = NULL ;
struct V_187 V_390 ;
struct V_187 T_9 * V_391 = NULL ;
struct V_50 * V_51 = NULL ;
struct V_392 V_393 ;
struct V_394 * V_394 ;
int V_26 = 0 ;
F_56 ( V_19 , L_99 , V_387 ) ;
switch ( V_387 ) {
case V_61 :
V_51 = F_32 ( V_49 ) ;
if ( ! V_51 )
return - V_211 ;
V_51 -> V_395 = 0 ;
case V_64 :
V_51 = F_32 ( V_49 ) ;
if ( ! V_51 )
return - V_211 ;
if ( V_51 -> V_62 == 1 ) {
V_51 -> V_65 = 0 ;
if ( F_22 ( V_11 -> V_16 ) )
V_51 -> V_65 = V_54 ;
}
return 0 ;
case V_396 :
case V_397 :
V_389 = (struct V_182 T_9 * ) V_49 -> V_398 ;
if ( F_267 ( & V_388 , V_389 , sizeof( V_182 ) ) )
return - V_399 ;
V_26 = F_182 ( V_19 , & V_388 ) ;
if ( V_26 == 0 &&
F_268 ( V_389 , & V_388 , sizeof( V_182 ) ) )
return - V_399 ;
return V_26 ;
case V_400 :
case V_401 :
V_391 = (struct V_187 T_9 * ) V_49 -> V_398 ;
if ( F_267 ( & V_390 , V_391 , sizeof( V_187 ) ) )
return - V_399 ;
V_26 = F_183 ( V_19 , & V_390 ) ;
if ( V_26 == 0 &&
F_268 ( V_391 , & V_390 , sizeof( V_187 ) ) )
return - V_399 ;
return V_26 ;
default:
break;
}
V_394 = F_208 ( V_19 ) ;
if ( ! F_269 ( V_394 -> V_402 , V_403 ) )
return - V_203 ;
V_15 = F_270 ( V_394 , V_49 -> V_404 ) ;
F_56 ( V_19 , L_100 , V_15 ) ;
if ( ! V_15 )
return - V_244 ;
F_56 ( V_19 , L_101 , V_15 -> V_59 ) ;
switch ( V_387 ) {
case V_405 :
case V_406 :
V_26 = F_136 ( V_19 , V_15 ) ;
break;
case V_407 :
case V_408 :
V_26 = F_179 ( V_19 , V_15 ) ;
break;
case V_409 :
case V_410 :
F_55 ( V_19 , V_15 ) ;
V_26 = 0 ;
break;
case V_411 :
case V_412 :
F_271 ( & V_393 , V_15 -> V_59 ) ;
V_26 = F_272 ( V_11 , V_413 , & V_393 ) ;
break;
default:
V_26 = - V_213 ;
}
return V_26 ;
}
static void F_273 ( struct V_14 * V_19 , int V_414 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
if ( V_414 & V_83 )
F_34 ( V_11 ,
V_19 -> V_82 & V_83 ? 1 : - 1 ) ;
if ( V_414 & V_84 )
F_38 ( V_11 ,
V_19 -> V_82 & V_84 ? 1 : - 1 ) ;
}
static void F_274 ( struct V_14 * V_19 )
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
F_89 (bond, slave, iter) {
F_148 ( V_22 -> V_16 , V_19 ) ;
F_147 ( V_22 -> V_16 , V_19 ) ;
}
}
F_67 () ;
}
static int F_275 ( struct V_415 * V_416 )
{
struct V_10 * V_11 = F_11 ( V_416 -> V_16 ) ;
const struct V_45 * V_46 ;
struct V_417 V_418 ;
struct V_22 * V_22 ;
int V_170 ;
V_22 = F_276 ( V_11 ) ;
if ( ! V_22 )
return 0 ;
V_46 = V_22 -> V_16 -> V_47 ;
if ( ! V_46 -> V_419 )
return 0 ;
V_418 . V_420 = NULL ;
V_418 . V_421 = NULL ;
V_170 = V_46 -> V_419 ( V_22 -> V_16 , & V_418 ) ;
if ( V_170 )
return V_170 ;
V_416 -> V_418 -> V_421 = V_418 . V_421 ;
if ( ! V_418 . V_420 )
return 0 ;
return V_418 . V_420 ( V_416 ) ;
}
static int F_277 ( struct V_14 * V_16 ,
struct V_417 * V_418 )
{
if ( V_418 -> V_16 == V_16 )
V_418 -> V_420 = F_275 ;
return 0 ;
}
static int F_278 ( struct V_14 * V_19 , int V_422 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_23 ;
struct V_24 * V_25 ;
int V_26 = 0 ;
F_56 ( V_19 , L_102 , V_11 , V_422 ) ;
F_12 (bond, slave, iter) {
F_56 ( V_19 , L_103 ,
V_22 , V_22 -> V_16 -> V_47 -> V_423 ) ;
V_26 = F_143 ( V_22 -> V_16 , V_422 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_104 , V_26 ,
V_22 -> V_16 -> V_59 ) ;
goto V_27;
}
}
V_19 -> V_218 = V_422 ;
return 0 ;
V_27:
F_12 (bond, rollback_slave, iter) {
int V_424 ;
if ( V_23 == V_22 )
break;
V_424 = F_143 ( V_23 -> V_16 , V_19 -> V_218 ) ;
if ( V_424 ) {
F_56 ( V_19 , L_105 ,
V_424 , V_23 -> V_16 -> V_59 ) ;
}
}
return V_26 ;
}
static int F_279 ( struct V_14 * V_19 , void * V_199 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_23 ;
struct V_91 * V_425 = V_199 , V_426 ;
struct V_24 * V_25 ;
int V_26 = 0 ;
if ( F_20 ( V_11 ) == V_9 )
return F_280 ( V_19 , V_199 ) ;
F_56 ( V_19 , L_106 , V_11 ) ;
if ( V_11 -> V_52 . V_94 &&
F_20 ( V_11 ) == V_4 )
return 0 ;
if ( ! F_281 ( V_425 -> V_97 ) )
return - V_427 ;
F_12 (bond, slave, iter) {
F_56 ( V_19 , L_107 , V_22 , V_22 -> V_16 -> V_59 ) ;
V_26 = F_59 ( V_22 -> V_16 , V_199 ) ;
if ( V_26 ) {
F_56 ( V_19 , L_104 , V_26 , V_22 -> V_16 -> V_59 ) ;
goto V_27;
}
}
memcpy ( V_19 -> V_86 , V_425 -> V_97 , V_19 -> V_85 ) ;
return 0 ;
V_27:
memcpy ( V_426 . V_97 , V_19 -> V_86 , V_19 -> V_85 ) ;
V_426 . V_98 = V_19 -> type ;
F_12 (bond, rollback_slave, iter) {
int V_424 ;
if ( V_23 == V_22 )
break;
V_424 = F_59 ( V_23 -> V_16 , & V_426 ) ;
if ( V_424 ) {
F_56 ( V_19 , L_105 ,
V_424 , V_23 -> V_16 -> V_59 ) ;
}
}
return V_26 ;
}
static void F_282 ( struct V_10 * V_11 , struct V_12 * V_13 , int V_245 )
{
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_201 = V_245 ;
F_89 (bond, slave, iter) {
if ( -- V_201 < 0 ) {
if ( F_283 ( V_22 ) ) {
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
return;
}
}
}
V_201 = V_245 ;
F_89 (bond, slave, iter) {
if ( -- V_201 < 0 )
break;
if ( F_283 ( V_22 ) ) {
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
return;
}
}
F_284 ( V_11 -> V_16 , V_13 ) ;
}
static T_3 F_285 ( struct V_10 * V_11 )
{
T_3 V_245 ;
struct V_428 V_429 ;
int V_430 = V_11 -> V_52 . V_430 ;
switch ( V_430 ) {
case 0 :
V_245 = F_286 () ;
break;
case 1 :
V_245 = V_11 -> V_431 ;
break;
default:
V_429 =
V_11 -> V_52 . V_429 ;
V_245 = F_287 ( V_11 -> V_431 ,
V_429 ) ;
break;
}
V_11 -> V_431 ++ ;
return V_245 ;
}
static int F_288 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_336 * V_337 = F_252 ( V_13 ) ;
struct V_22 * V_22 ;
T_3 V_245 ;
if ( V_337 -> V_288 == V_432 && V_13 -> V_288 == F_221 ( V_295 ) ) {
V_22 = F_66 ( V_11 -> V_69 ) ;
if ( V_22 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_282 ( V_11 , V_13 , 0 ) ;
} else {
int V_186 = F_111 ( V_11 -> V_186 ) ;
if ( F_289 ( V_186 ) ) {
V_245 = F_285 ( V_11 ) ;
F_282 ( V_11 , V_13 , V_245 % V_186 ) ;
} else {
F_284 ( V_19 , V_13 ) ;
}
}
return V_433 ;
}
static int F_290 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 ;
V_22 = F_66 ( V_11 -> V_69 ) ;
if ( V_22 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_284 ( V_19 , V_13 ) ;
return V_433 ;
}
void F_291 ( struct V_10 * V_11 , unsigned long V_111 )
{
F_43 ( V_11 -> V_73 , & V_11 -> V_357 , V_111 ) ;
}
static void V_358 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_41 ( V_71 , struct V_10 ,
V_357 . V_71 ) ;
int V_170 ;
if ( ! F_42 () )
goto V_67;
V_170 = F_164 ( V_11 , NULL ) ;
F_45 () ;
if ( V_170 ) {
F_292 ( L_108 ) ;
goto V_67;
}
return;
V_67:
F_291 ( V_11 , 1 ) ;
}
int F_164 ( struct V_10 * V_11 , struct V_22 * V_434 )
{
struct V_22 * V_22 ;
struct V_24 * V_25 ;
struct V_435 * V_436 , * V_437 ;
int V_438 ;
int V_439 = 0 ;
int V_170 = 0 ;
#ifdef F_293
F_294 ( F_295 ( & V_11 -> V_440 ) ) ;
#endif
V_436 = F_81 ( F_296 ( struct V_435 , V_441 [ V_11 -> V_186 ] ) ,
V_127 ) ;
if ( ! V_436 ) {
V_170 = - V_128 ;
F_297 ( L_109 ) ;
goto V_99;
}
if ( F_20 ( V_11 ) == V_7 ) {
struct V_129 V_129 ;
if ( F_87 ( V_11 , & V_129 ) ) {
F_298 ( L_110 ) ;
F_299 ( V_436 , V_442 ) ;
V_437 = F_36 ( V_11 -> V_443 ) ;
if ( V_437 ) {
F_168 ( V_11 -> V_443 , NULL ) ;
F_299 ( V_437 , V_442 ) ;
}
goto V_99;
}
V_438 = V_129 . V_341 ;
V_439 = V_129 . V_138 ;
}
F_12 (bond, slave, iter) {
if ( F_20 ( V_11 ) == V_7 ) {
struct V_134 * V_135 ;
V_135 = F_90 ( V_22 ) -> V_136 . V_134 ;
if ( ! V_135 || V_135 -> V_137 != V_439 )
continue;
}
if ( ! F_283 ( V_22 ) )
continue;
if ( V_434 == V_22 )
continue;
V_436 -> V_441 [ V_436 -> V_444 ++ ] = V_22 ;
}
V_437 = F_36 ( V_11 -> V_443 ) ;
F_78 ( V_11 -> V_443 , V_436 ) ;
if ( V_437 )
F_299 ( V_437 , V_442 ) ;
V_99:
if ( V_170 != 0 && V_434 ) {
int V_445 ;
V_437 = F_36 ( V_11 -> V_443 ) ;
for ( V_445 = 0 ; V_445 < V_437 -> V_444 ; V_445 ++ ) {
if ( V_434 == V_437 -> V_441 [ V_445 ] ) {
V_437 -> V_441 [ V_445 ] =
V_437 -> V_441 [ V_437 -> V_444 - 1 ] ;
V_437 -> V_444 -- ;
break;
}
}
}
return V_170 ;
}
static int F_300 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
struct V_22 * V_22 ;
struct V_435 * V_446 ;
unsigned int V_444 ;
V_446 = F_66 ( V_11 -> V_443 ) ;
V_444 = V_446 ? F_111 ( V_446 -> V_444 ) : 0 ;
if ( F_289 ( V_444 ) ) {
V_22 = V_446 -> V_441 [ F_257 ( V_11 , V_13 ) % V_444 ] ;
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
} else {
F_284 ( V_16 , V_13 ) ;
}
return V_433 ;
}
static int F_301 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 = NULL ;
struct V_24 * V_25 ;
F_89 (bond, slave, iter) {
if ( F_302 ( V_11 , V_22 ) )
break;
if ( F_63 ( V_22 ) && V_22 -> V_29 == V_30 ) {
struct V_12 * V_447 = F_303 ( V_13 , V_172 ) ;
if ( ! V_447 ) {
F_193 ( L_111 ,
V_19 -> V_59 , V_448 ) ;
continue;
}
F_2 ( V_11 , V_447 , V_22 -> V_16 ) ;
}
}
if ( V_22 && F_63 ( V_22 ) && V_22 -> V_29 == V_30 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_284 ( V_19 , V_13 ) ;
return V_433 ;
}
static inline int F_304 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_22 * V_22 = NULL ;
struct V_24 * V_25 ;
if ( ! V_13 -> V_17 )
return 1 ;
F_89 (bond, slave, iter) {
if ( V_22 -> V_216 == V_13 -> V_17 ) {
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
static T_2 F_305 ( struct V_14 * V_16 , struct V_12 * V_13 ,
void * V_449 , T_10 V_450 )
{
T_2 V_451 = F_306 ( V_13 ) ? F_307 ( V_13 ) : 0 ;
F_4 ( V_13 ) -> V_18 = V_13 -> V_17 ;
if ( F_5 ( V_451 >= V_16 -> V_452 ) ) {
do {
V_451 -= V_16 -> V_452 ;
} while ( V_451 >= V_16 -> V_452 );
}
return V_451 ;
}
static T_11 F_308 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
if ( F_309 ( V_11 ) &&
! F_304 ( V_11 , V_13 ) )
return V_433 ;
switch ( F_20 ( V_11 ) ) {
case V_3 :
return F_288 ( V_13 , V_16 ) ;
case V_4 :
return F_290 ( V_13 , V_16 ) ;
case V_7 :
case V_5 :
return F_300 ( V_13 , V_16 ) ;
case V_6 :
return F_301 ( V_13 , V_16 ) ;
case V_9 :
return F_310 ( V_13 , V_16 ) ;
case V_8 :
return F_311 ( V_13 , V_16 ) ;
default:
F_60 ( V_16 , L_112 , F_20 ( V_11 ) ) ;
F_312 ( 1 ) ;
F_284 ( V_16 , V_13 ) ;
return V_433 ;
}
}
static T_11 F_313 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
T_11 V_170 = V_433 ;
if ( F_5 ( F_314 ( V_16 ) ) )
return V_453 ;
F_65 () ;
if ( F_19 ( V_11 ) )
V_170 = F_308 ( V_13 , V_16 ) ;
else
F_284 ( V_16 , V_13 ) ;
F_67 () ;
return V_170 ;
}
static int F_315 ( struct V_14 * V_19 ,
struct V_31 * V_32 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
unsigned long V_34 = 0 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
V_32 -> V_36 = V_37 ;
V_32 -> V_136 = V_454 ;
F_12 (bond, slave, iter) {
if ( F_283 ( V_22 ) ) {
if ( V_22 -> V_34 != V_35 )
V_34 += V_22 -> V_34 ;
if ( V_32 -> V_36 == V_37 &&
V_22 -> V_36 != V_37 )
V_32 -> V_36 = V_22 -> V_36 ;
}
}
F_316 ( V_32 , V_34 ? : V_35 ) ;
return 0 ;
}
static void F_317 ( struct V_14 * V_19 ,
struct V_455 * V_456 )
{
F_318 ( V_456 -> V_457 , V_458 , sizeof( V_456 -> V_457 ) ) ;
F_318 ( V_456 -> V_459 , V_460 , sizeof( V_456 -> V_459 ) ) ;
snprintf ( V_456 -> V_461 , sizeof( V_456 -> V_461 ) , L_113 ,
V_462 ) ;
}
static void F_319 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
if ( V_11 -> V_73 )
F_320 ( V_11 -> V_73 ) ;
F_321 ( V_19 ) ;
}
void F_322 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_323 ( & V_11 -> V_440 ) ;
V_11 -> V_52 = V_463 ;
V_11 -> V_16 = V_19 ;
F_142 ( V_19 ) ;
V_19 -> V_47 = & V_464 ;
V_19 -> V_55 = & V_465 ;
V_19 -> V_466 = F_319 ;
F_324 ( V_19 , & V_467 ) ;
V_19 -> V_468 = 0 ;
V_19 -> V_82 |= V_326 | V_469 ;
V_19 -> V_161 |= V_223 | V_470 ;
V_19 -> V_161 &= ~ ( V_147 | V_209 ) ;
V_19 -> V_141 |= V_471 ;
V_19 -> V_141 |= V_472 ;
V_19 -> V_473 = V_150 |
V_474 |
V_475 |
V_476 ;
V_19 -> V_473 &= ~ ( V_477 & ~ V_478 ) ;
V_19 -> V_473 |= V_163 ;
V_19 -> V_141 |= V_19 -> V_473 ;
}
static void F_325 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
struct V_435 * V_441 ;
F_95 ( V_19 ) ;
F_12 (bond, slave, iter)
F_173 ( V_19 , V_22 -> V_16 , true ) ;
F_71 ( V_19 , L_114 ) ;
V_441 = F_36 ( V_11 -> V_443 ) ;
if ( V_441 ) {
F_168 ( V_11 -> V_443 , NULL ) ;
F_299 ( V_441 , V_442 ) ;
}
F_326 ( & V_11 -> V_479 ) ;
F_327 ( V_11 ) ;
}
static int F_328 ( struct V_480 * V_52 )
{
int V_481 , V_482 , V_483 , V_201 ;
struct V_392 V_393 ;
const struct V_392 * V_484 ;
int V_485 ;
if ( V_1 ) {
F_271 ( & V_393 , V_1 ) ;
V_484 = F_329 ( F_330 ( V_486 ) , & V_393 ) ;
if ( ! V_484 ) {
F_297 ( L_115 , V_1 ) ;
return - V_211 ;
}
V_184 = V_484 -> V_487 ;
}
if ( V_488 ) {
if ( ( V_184 != V_5 ) &&
( V_184 != V_7 ) &&
( V_184 != V_8 ) ) {
F_331 ( L_116 ,
F_1 ( V_184 ) ) ;
} else {
F_271 ( & V_393 , V_488 ) ;
V_484 = F_329 ( F_330 ( V_489 ) ,
& V_393 ) ;
if ( ! V_484 ) {
F_297 ( L_117 ,
V_488 ) ;
return - V_211 ;
}
V_490 = V_484 -> V_487 ;
}
}
if ( V_491 ) {
if ( V_184 != V_7 ) {
F_331 ( L_118 ,
F_1 ( V_184 ) ) ;
} else {
F_271 ( & V_393 , V_491 ) ;
V_484 = F_329 ( F_330 ( V_492 ) ,
& V_393 ) ;
if ( ! V_484 ) {
F_297 ( L_119 ,
V_491 ) ;
return - V_211 ;
}
V_493 = V_484 -> V_487 ;
}
}
if ( V_494 ) {
F_271 ( & V_393 , V_494 ) ;
V_484 = F_329 ( F_330 ( V_495 ) ,
& V_393 ) ;
if ( ! V_484 ) {
F_297 ( L_120 , V_494 ) ;
return - V_211 ;
}
V_52 -> V_494 = V_484 -> V_487 ;
if ( V_184 != V_7 )
F_332 ( L_121 ) ;
} else {
V_52 -> V_494 = V_496 ;
}
if ( V_497 < 0 ) {
F_332 ( L_122 ,
V_497 , 0 , V_498 , V_499 ) ;
V_497 = V_499 ;
}
if ( V_117 < 0 ) {
F_332 ( L_123 ,
V_117 , V_498 ) ;
V_117 = 0 ;
}
if ( V_110 < 0 ) {
F_332 ( L_124 ,
V_110 , V_498 ) ;
V_110 = 0 ;
}
if ( V_251 < 0 ) {
F_332 ( L_125 ,
V_251 , V_498 ) ;
V_251 = 0 ;
}
if ( ( V_53 != 0 ) && ( V_53 != 1 ) ) {
F_332 ( L_126 ,
V_53 ) ;
V_53 = 1 ;
}
if ( V_120 < 0 || V_120 > 255 ) {
F_332 ( L_127 ,
V_120 ) ;
V_120 = 1 ;
}
if ( ! F_333 ( V_184 ) ) {
if ( ! V_117 ) {
F_332 ( L_128 ) ;
F_332 ( L_129 ) ;
V_117 = V_500 ;
}
}
if ( V_501 < 1 || V_501 > 255 ) {
F_332 ( L_130 ,
V_501 , V_502 ) ;
V_501 = V_502 ;
}
if ( ( V_503 != 0 ) && ( V_503 != 1 ) ) {
F_332 ( L_131 ,
V_503 ) ;
V_503 = 0 ;
}
if ( V_123 < 0 || V_123 > 255 ) {
F_332 ( L_132 ,
V_123 , V_504 ) ;
V_123 = V_504 ;
}
F_334 ( & V_393 , V_430 ) ;
if ( ! F_329 ( F_330 ( V_505 ) , & V_393 ) ) {
F_332 ( L_133 ,
V_430 , V_506 ) ;
V_430 = 1 ;
}
if ( V_184 == V_9 ) {
F_335 ( L_134 ,
V_110 ) ;
}
if ( ! V_117 ) {
if ( V_110 || V_251 ) {
F_332 ( L_135 ,
V_110 , V_251 ) ;
}
} else {
if ( V_227 ) {
F_332 ( L_136 ,
V_117 , V_227 ) ;
V_227 = 0 ;
}
if ( ( V_110 % V_117 ) != 0 ) {
F_332 ( L_137 ,
V_110 , V_117 , ( V_110 / V_117 ) * V_117 ) ;
}
V_110 /= V_117 ;
if ( ( V_251 % V_117 ) != 0 ) {
F_332 ( L_138 ,
V_251 , V_117 ,
( V_251 / V_117 ) * V_117 ) ;
}
V_251 /= V_117 ;
}
if ( V_227 < 0 ) {
F_332 ( L_139 ,
V_227 , V_498 ) ;
V_227 = 0 ;
}
for ( V_507 = 0 , V_201 = 0 ;
( V_507 < V_228 ) && V_508 [ V_201 ] ; V_201 ++ ) {
T_8 V_256 ;
if ( ! F_336 ( V_508 [ V_201 ] , - 1 , ( T_5 * ) & V_256 , - 1 , NULL ) ||
! F_337 ( V_256 ) ) {
F_332 ( L_140 ,
V_508 [ V_201 ] ) ;
V_227 = 0 ;
} else {
if ( F_212 ( V_509 , V_256 ) == - 1 )
V_509 [ V_507 ++ ] = V_256 ;
else
F_332 ( L_141 ,
& V_256 ) ;
}
}
if ( V_227 && ! V_507 ) {
F_332 ( L_142 ,
V_227 ) ;
V_227 = 0 ;
}
if ( V_277 ) {
if ( ! V_227 ) {
F_297 ( L_143 ) ;
return - V_211 ;
}
F_271 ( & V_393 , V_277 ) ;
V_484 = F_329 ( F_330 ( V_510 ) ,
& V_393 ) ;
if ( ! V_484 ) {
F_297 ( L_144 ,
V_277 ) ;
return - V_211 ;
}
V_481 = V_484 -> V_487 ;
} else {
V_481 = 0 ;
}
V_485 = 0 ;
if ( V_511 ) {
F_271 ( & V_393 , V_511 ) ;
V_484 = F_329 ( F_330 ( V_512 ) ,
& V_393 ) ;
if ( ! V_484 ) {
F_297 ( L_145 ,
V_511 ) ;
V_485 = 0 ;
} else {
V_485 = V_484 -> V_487 ;
}
}
if ( V_117 ) {
F_331 ( L_146 , V_117 ) ;
} else if ( V_227 ) {
V_484 = F_338 ( V_510 ,
V_481 ) ;
F_331 ( L_147 ,
V_227 , V_484 -> string , V_507 ) ;
for ( V_201 = 0 ; V_201 < V_507 ; V_201 ++ )
F_339 ( L_148 , V_508 [ V_201 ] ) ;
F_339 ( L_149 ) ;
} else if ( V_497 ) {
F_298 ( L_150 ) ;
}
if ( V_108 && ! F_340 ( V_184 ) ) {
F_332 ( L_151 ,
V_108 , F_1 ( V_184 ) ) ;
V_108 = NULL ;
}
if ( V_108 && V_104 ) {
F_271 ( & V_393 , V_104 ) ;
V_484 = F_329 ( F_330 ( V_513 ) ,
& V_393 ) ;
if ( ! V_484 ) {
F_297 ( L_152 ,
V_104 ) ;
return - V_211 ;
}
V_483 = V_484 -> V_487 ;
} else {
V_483 = V_514 ;
}
if ( V_94 ) {
F_271 ( & V_393 , V_94 ) ;
V_484 = F_329 ( F_330 ( V_515 ) ,
& V_393 ) ;
if ( ! V_484 ) {
F_297 ( L_153 ,
V_94 ) ;
return - V_211 ;
}
V_482 = V_484 -> V_487 ;
if ( V_184 != V_4 )
F_332 ( L_154 ) ;
} else {
V_482 = V_516 ;
}
if ( V_517 == 0 ) {
F_332 ( L_155 ,
V_498 , V_518 ) ;
V_517 = V_518 ;
}
V_52 -> V_1 = V_184 ;
V_52 -> V_339 = V_490 ;
V_52 -> V_117 = V_117 ;
V_52 -> V_120 = V_120 ;
V_52 -> V_227 = V_227 ;
V_52 -> V_277 = V_481 ;
V_52 -> V_511 = V_485 ;
V_52 -> V_110 = V_110 ;
V_52 -> V_251 = V_251 ;
V_52 -> V_53 = V_53 ;
V_52 -> V_493 = V_493 ;
V_52 -> V_108 [ 0 ] = 0 ;
V_52 -> V_104 = V_483 ;
V_52 -> V_94 = V_482 ;
V_52 -> V_501 = V_501 ;
V_52 -> V_503 = V_503 ;
V_52 -> V_123 = V_123 ;
V_52 -> V_519 = V_519 ;
V_52 -> V_517 = V_517 ;
V_52 -> V_430 = V_430 ;
V_52 -> V_359 = 1 ;
if ( V_430 > 0 ) {
V_52 -> V_429 =
V_428 ( V_430 ) ;
} else {
V_52 -> V_429 =
(struct V_428 ) { 0 } ;
}
if ( V_108 ) {
strncpy ( V_52 -> V_108 , V_108 , V_60 ) ;
V_52 -> V_108 [ V_60 - 1 ] = 0 ;
}
memcpy ( V_52 -> V_275 , V_509 , sizeof( V_509 ) ) ;
return 0 ;
}
static void F_341 ( struct V_14 * V_16 ,
struct V_520 * V_451 ,
void * V_521 )
{
F_342 ( & V_451 -> V_522 ,
& V_523 ) ;
}
static void F_343 ( struct V_14 * V_16 )
{
F_342 ( & V_16 -> V_524 ,
& V_525 ) ;
F_344 ( V_16 , F_341 , NULL ) ;
V_16 -> V_526 = & V_527 ;
}
static int F_345 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_528 * V_529 = F_346 ( F_208 ( V_19 ) , V_530 ) ;
F_56 ( V_19 , L_156 ) ;
V_11 -> V_73 = F_347 ( V_19 -> V_59 ) ;
if ( ! V_11 -> V_73 )
return - V_128 ;
F_343 ( V_19 ) ;
F_348 ( & V_11 -> V_479 , & V_529 -> V_531 ) ;
F_349 ( V_11 ) ;
F_350 ( V_11 ) ;
if ( F_351 ( V_19 -> V_86 ) &&
V_19 -> V_87 == V_532 )
F_172 ( V_19 ) ;
return 0 ;
}
unsigned int F_352 ( void )
{
return V_501 ;
}
int F_353 ( struct V_394 * V_394 , const char * V_59 )
{
struct V_14 * V_19 ;
struct V_10 * V_11 ;
struct V_533 * V_534 ;
int V_26 ;
F_129 () ;
V_19 = F_354 ( sizeof( struct V_10 ) ,
V_59 ? V_59 : L_157 , V_535 ,
F_322 , V_501 ) ;
if ( ! V_19 ) {
F_297 ( L_158 , V_59 ) ;
F_45 () ;
return - V_128 ;
}
V_11 = F_11 ( V_19 ) ;
V_534 = & ( F_355 ( V_11 ) ) ;
V_534 -> V_536 = V_537 ;
F_356 ( V_19 , V_394 ) ;
V_19 -> V_538 = & V_539 ;
V_26 = F_357 ( V_19 ) ;
F_24 ( V_19 ) ;
F_45 () ;
if ( V_26 < 0 )
F_319 ( V_19 ) ;
return V_26 ;
}
static int T_12 F_358 ( struct V_394 * V_394 )
{
struct V_528 * V_529 = F_346 ( V_394 , V_530 ) ;
V_529 -> V_394 = V_394 ;
F_359 ( & V_529 -> V_531 ) ;
F_360 ( V_529 ) ;
F_361 ( V_529 ) ;
return 0 ;
}
static void T_13 F_362 ( struct V_394 * V_394 )
{
struct V_528 * V_529 = F_346 ( V_394 , V_530 ) ;
struct V_10 * V_11 , * V_540 ;
F_363 ( V_541 ) ;
F_364 ( V_529 ) ;
F_129 () ;
F_365 (bond, tmp_bond, &bn->dev_list, bond_list)
F_366 ( V_11 -> V_16 , & V_541 ) ;
F_367 ( & V_541 ) ;
F_45 () ;
F_368 ( V_529 ) ;
}
static int T_14 F_369 ( void )
{
int V_201 ;
int V_26 ;
F_331 ( L_159 , V_542 ) ;
V_26 = F_328 ( & V_463 ) ;
if ( V_26 )
goto V_99;
V_26 = F_370 ( & V_543 ) ;
if ( V_26 )
goto V_99;
V_26 = F_371 () ;
if ( V_26 )
goto V_544;
F_372 () ;
for ( V_201 = 0 ; V_201 < V_497 ; V_201 ++ ) {
V_26 = F_353 ( & V_545 , NULL ) ;
if ( V_26 )
goto V_67;
}
F_373 ( & V_546 ) ;
V_99:
return V_26 ;
V_67:
F_374 () ;
F_375 () ;
V_544:
F_376 ( & V_543 ) ;
goto V_99;
}
static void T_15 F_377 ( void )
{
F_378 ( & V_546 ) ;
F_374 () ;
F_375 () ;
F_376 ( & V_543 ) ;
#ifdef F_157
F_294 ( F_379 ( & V_547 ) ) ;
#endif
}
