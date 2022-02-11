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
if ( V_11 -> V_68 ) {
V_67 = F_36 ( V_11 -> V_68 -> V_16 ,
V_66 ) ;
}
} else {
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
V_67 = F_36 ( V_22 -> V_16 , V_66 ) ;
if ( V_67 )
return V_67 ;
}
}
return V_67 ;
}
static int F_37 ( struct V_10 * V_11 , int V_66 )
{
struct V_24 * V_25 ;
int V_67 = 0 ;
if ( F_35 ( V_11 ) ) {
if ( V_11 -> V_68 ) {
V_67 = F_38 ( V_11 -> V_68 -> V_16 ,
V_66 ) ;
}
} else {
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
V_67 = F_38 ( V_22 -> V_16 , V_66 ) ;
if ( V_67 )
return V_67 ;
}
}
return V_67 ;
}
static void F_39 ( struct V_69 * V_70 )
{
struct V_10 * V_11 = F_40 ( V_70 , struct V_10 ,
V_71 . V_70 ) ;
if ( ! F_41 () ) {
F_42 ( V_11 -> V_72 , & V_11 -> V_71 , 1 ) ;
return;
}
F_43 ( V_73 , V_11 -> V_16 ) ;
if ( V_11 -> V_74 > 1 ) {
V_11 -> V_74 -- ;
F_42 ( V_11 -> V_72 , & V_11 -> V_71 , V_75 / 5 ) ;
}
F_44 () ;
}
static void F_45 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_46 ( V_15 , V_19 ) ;
F_47 ( V_15 , V_19 ) ;
if ( F_20 ( V_11 ) == V_7 ) {
T_5 V_76 [ V_77 ] = V_78 ;
F_48 ( V_15 , V_76 ) ;
}
}
static void F_49 ( struct V_10 * V_11 , struct V_22 * V_79 ,
struct V_22 * V_80 )
{
F_50 () ;
if ( V_80 ) {
if ( V_11 -> V_16 -> V_81 & V_82 )
F_36 ( V_80 -> V_16 , - 1 ) ;
if ( V_11 -> V_16 -> V_81 & V_83 )
F_38 ( V_80 -> V_16 , - 1 ) ;
F_45 ( V_11 -> V_16 , V_80 -> V_16 ) ;
}
if ( V_79 ) {
if ( V_11 -> V_16 -> V_81 & V_82 )
F_36 ( V_79 -> V_16 , 1 ) ;
if ( V_11 -> V_16 -> V_81 & V_83 )
F_38 ( V_79 -> V_16 , 1 ) ;
F_51 ( V_11 -> V_16 ) ;
F_52 ( V_79 -> V_16 , V_11 -> V_16 ) ;
F_53 ( V_79 -> V_16 , V_11 -> V_16 ) ;
F_54 ( V_11 -> V_16 ) ;
}
}
static void F_55 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
F_56 ( L_13 ,
V_19 , V_15 , V_15 -> V_84 ) ;
memcpy ( V_19 -> V_85 , V_15 -> V_85 , V_15 -> V_84 ) ;
V_19 -> V_86 = V_87 ;
F_43 ( V_88 , V_19 ) ;
}
static void F_57 ( struct V_10 * V_11 ,
struct V_22 * V_79 ,
struct V_22 * V_80 )
__releases( &bond->curr_slave_lock
static bool F_58 ( struct V_10 * V_11 )
{
struct V_22 * V_89 = V_11 -> V_90 ;
struct V_22 * V_91 = V_11 -> V_68 ;
if ( ! V_89 || ! V_91 || V_91 -> V_29 != V_30 )
return true ;
if ( V_11 -> V_92 ) {
V_11 -> V_92 = false ;
return true ;
}
if ( V_11 -> V_52 . V_93 == V_94 &&
( V_89 -> V_34 < V_91 -> V_34 ||
( V_89 -> V_34 == V_91 -> V_34 && V_89 -> V_36 <= V_91 -> V_36 ) ) )
return false ;
if ( V_11 -> V_52 . V_93 == V_95 )
return false ;
return true ;
}
static struct V_22 * F_59 ( struct V_10 * V_11 )
{
struct V_22 * V_22 , * V_96 = NULL ;
struct V_24 * V_25 ;
int V_97 = V_11 -> V_52 . V_98 ;
if ( V_11 -> V_90 && V_11 -> V_90 -> V_29 == V_30 &&
F_58 ( V_11 ) )
return V_11 -> V_90 ;
F_12 (bond, slave, iter) {
if ( V_22 -> V_29 == V_30 )
return V_22 ;
if ( V_22 -> V_29 == V_43 && F_60 ( V_22 ) &&
V_22 -> V_99 < V_97 ) {
V_97 = V_22 -> V_99 ;
V_96 = V_22 ;
}
}
return V_96 ;
}
static bool F_61 ( struct V_10 * V_11 )
{
struct V_22 * V_22 ;
F_62 () ;
V_22 = F_63 ( V_11 -> V_68 ) ;
F_64 () ;
F_56 ( L_14 ,
V_11 -> V_16 -> V_59 , V_22 ? V_22 -> V_16 -> V_59 : L_15 ) ;
if ( ! V_22 || ! V_11 -> V_100 ||
F_65 ( V_101 , & V_22 -> V_16 -> V_102 ) )
return false ;
return true ;
}
void F_66 ( struct V_10 * V_11 , struct V_22 * V_79 )
{
struct V_22 * V_80 = V_11 -> V_68 ;
if ( V_80 == V_79 )
return;
if ( V_79 ) {
V_79 -> V_103 = V_104 ;
if ( V_79 -> V_29 == V_43 ) {
if ( F_35 ( V_11 ) ) {
F_67 ( L_16 ,
V_11 -> V_16 -> V_59 , V_79 -> V_16 -> V_59 ,
( V_11 -> V_52 . V_98 - V_79 -> V_99 ) * V_11 -> V_52 . V_105 ) ;
}
V_79 -> V_99 = 0 ;
V_79 -> V_29 = V_30 ;
if ( F_20 ( V_11 ) == V_7 )
F_68 ( V_79 , V_30 ) ;
if ( F_16 ( V_11 ) )
F_69 ( V_11 , V_79 , V_30 ) ;
} else {
if ( F_35 ( V_11 ) ) {
F_67 ( L_17 ,
V_11 -> V_16 -> V_59 , V_79 -> V_16 -> V_59 ) ;
}
}
}
if ( F_35 ( V_11 ) )
F_49 ( V_11 , V_79 , V_80 ) ;
if ( F_16 ( V_11 ) ) {
F_70 ( V_11 , V_79 ) ;
if ( V_80 )
F_71 ( V_80 ,
V_106 ) ;
if ( V_79 )
F_72 ( V_79 ,
V_106 ) ;
} else {
F_73 ( V_11 -> V_68 , V_79 ) ;
}
if ( F_20 ( V_11 ) == V_4 ) {
if ( V_80 )
F_71 ( V_80 ,
V_106 ) ;
if ( V_79 ) {
bool V_107 = false ;
F_72 ( V_79 ,
V_106 ) ;
if ( V_11 -> V_52 . V_108 )
F_57 ( V_11 , V_79 ,
V_80 ) ;
if ( F_31 ( V_11 -> V_16 ) ) {
V_11 -> V_100 =
V_11 -> V_52 . V_109 ;
V_107 =
F_61 ( V_11 ) ;
}
F_74 ( & V_11 -> V_110 ) ;
F_43 ( V_111 , V_11 -> V_16 ) ;
if ( V_107 )
F_43 ( V_112 ,
V_11 -> V_16 ) ;
F_75 ( & V_11 -> V_110 ) ;
}
}
if ( F_31 ( V_11 -> V_16 ) && ( V_11 -> V_52 . V_113 > 0 ) &&
( ( F_35 ( V_11 ) && V_79 ) ||
F_20 ( V_11 ) == V_3 ) ) {
V_11 -> V_74 = V_11 -> V_52 . V_113 ;
F_42 ( V_11 -> V_72 , & V_11 -> V_71 , 1 ) ;
}
}
void F_76 ( struct V_10 * V_11 )
{
struct V_22 * V_114 ;
int V_115 ;
V_114 = F_59 ( V_11 ) ;
if ( V_114 != V_11 -> V_68 ) {
F_66 ( V_11 , V_114 ) ;
V_115 = F_18 ( V_11 ) ;
if ( ! V_115 )
return;
if ( F_22 ( V_11 -> V_16 ) ) {
F_67 ( L_18 ,
V_11 -> V_16 -> V_59 ) ;
} else {
F_67 ( L_19 ,
V_11 -> V_16 -> V_59 ) ;
}
}
}
static inline int F_77 ( struct V_22 * V_22 )
{
struct V_116 * V_117 ;
int V_67 = 0 ;
V_117 = F_78 ( sizeof( * V_117 ) , V_118 ) ;
V_67 = - V_119 ;
if ( ! V_117 )
goto V_120;
V_67 = F_79 ( V_117 , V_22 -> V_16 ) ;
if ( V_67 ) {
F_80 ( V_117 ) ;
goto V_120;
}
V_22 -> V_117 = V_117 ;
V_120:
return V_67 ;
}
static inline void F_81 ( struct V_22 * V_22 )
{
struct V_116 * V_117 = V_22 -> V_117 ;
if ( ! V_117 )
return;
V_22 -> V_117 = NULL ;
F_82 ( V_117 ) ;
}
static void F_83 ( struct V_14 * V_19 )
{
}
static void F_84 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter)
if ( F_60 ( V_22 ) )
F_81 ( V_22 ) ;
}
static int F_85 ( struct V_14 * V_16 , struct V_121 * V_122 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_67 = 0 ;
F_12 (bond, slave, iter) {
V_67 = F_77 ( V_22 ) ;
if ( V_67 ) {
F_84 ( V_16 ) ;
break;
}
}
return V_67 ;
}
static inline int F_77 ( struct V_22 * V_22 )
{
return 0 ;
}
static inline void F_81 ( struct V_22 * V_22 )
{
}
static void F_84 ( struct V_14 * V_19 )
{
}
static T_6 F_86 ( struct V_14 * V_16 ,
T_6 V_123 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
struct V_24 * V_25 ;
T_6 V_124 ;
struct V_22 * V_22 ;
if ( ! F_19 ( V_11 ) ) {
V_123 |= V_125 ;
return V_123 ;
}
V_124 = V_123 ;
V_123 &= ~ V_126 ;
V_123 |= V_127 ;
F_12 (bond, slave, iter) {
V_123 = F_87 ( V_123 ,
V_22 -> V_16 -> V_123 ,
V_124 ) ;
}
V_123 = F_88 ( V_123 , V_124 ) ;
return V_123 ;
}
static void F_89 ( struct V_10 * V_11 )
{
unsigned int V_81 , V_128 = V_129 ;
T_6 V_130 = V_131 ;
T_6 V_132 = V_133 ;
struct V_14 * V_19 = V_11 -> V_16 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
unsigned short V_134 = V_135 ;
unsigned int V_136 = V_137 ;
T_2 V_138 = V_139 ;
if ( ! F_19 ( V_11 ) )
goto V_140;
V_130 &= V_127 ;
F_12 (bond, slave, iter) {
V_130 = F_87 ( V_130 ,
V_22 -> V_16 -> V_130 , V_131 ) ;
V_132 = F_87 ( V_132 ,
V_22 -> V_16 -> V_141 ,
V_133 ) ;
V_128 &= V_22 -> V_16 -> V_142 ;
if ( V_22 -> V_16 -> V_143 > V_134 )
V_134 = V_22 -> V_16 -> V_143 ;
V_136 = F_90 ( V_136 , V_22 -> V_16 -> V_136 ) ;
V_138 = F_90 ( V_138 , V_22 -> V_16 -> V_138 ) ;
}
V_140:
V_19 -> V_130 = V_130 ;
V_19 -> V_141 = V_132 ;
V_19 -> V_143 = V_134 ;
V_19 -> V_138 = V_138 ;
F_91 ( V_19 , V_136 ) ;
V_81 = V_19 -> V_142 & ~ V_129 ;
V_19 -> V_142 = V_81 | V_128 ;
F_92 ( V_19 ) ;
}
static void F_93 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
V_19 -> V_144 = V_15 -> V_144 ;
V_19 -> type = V_15 -> type ;
V_19 -> V_143 = V_15 -> V_143 ;
V_19 -> V_84 = V_15 -> V_84 ;
memcpy ( V_19 -> V_145 , V_15 -> V_145 ,
V_15 -> V_84 ) ;
}
static bool F_94 ( struct V_12 * V_13 ,
struct V_22 * V_22 ,
struct V_10 * V_11 )
{
if ( F_95 ( V_22 ) ) {
if ( F_20 ( V_11 ) == V_9 &&
V_13 -> V_146 != V_147 &&
V_13 -> V_146 != V_148 )
return false ;
return true ;
}
return false ;
}
static T_7 F_96 ( struct V_12 * * V_149 )
{
struct V_12 * V_13 = * V_149 ;
struct V_22 * V_22 ;
struct V_10 * V_11 ;
int (* F_97)( const struct V_12 * , struct V_10 * ,
struct V_22 * );
int V_150 = V_151 ;
V_13 = F_98 ( V_13 , V_152 ) ;
if ( F_5 ( ! V_13 ) )
return V_153 ;
* V_149 = V_13 ;
V_22 = F_99 ( V_13 -> V_16 ) ;
V_11 = V_22 -> V_11 ;
F_97 = F_100 ( V_11 -> F_97 ) ;
if ( F_97 ) {
V_150 = F_97 ( V_13 , V_11 , V_22 ) ;
if ( V_150 == V_153 ) {
F_101 ( V_13 ) ;
return V_150 ;
}
}
if ( F_94 ( V_13 , V_22 , V_11 ) ) {
return V_154 ;
}
V_13 -> V_16 = V_11 -> V_16 ;
if ( F_20 ( V_11 ) == V_9 &&
V_11 -> V_16 -> V_142 & V_155 &&
V_13 -> V_146 == V_156 ) {
if ( F_5 ( F_102 ( V_13 ,
V_13 -> V_157 - F_103 ( V_13 ) ) ) ) {
F_104 ( V_13 ) ;
return V_153 ;
}
F_105 ( F_106 ( V_13 ) -> V_158 , V_11 -> V_16 -> V_85 ) ;
}
return V_150 ;
}
static int F_107 ( struct V_14 * V_19 ,
struct V_14 * V_15 ,
struct V_22 * V_22 )
{
int V_67 ;
V_67 = F_108 ( V_15 , V_19 , V_22 ) ;
if ( V_67 )
return V_67 ;
V_15 -> V_81 |= V_159 ;
F_109 ( V_160 , V_15 , V_159 , V_118 ) ;
return 0 ;
}
static void F_110 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
F_111 ( V_15 , V_19 ) ;
V_15 -> V_81 &= ~ V_159 ;
F_109 ( V_160 , V_15 , V_159 , V_118 ) ;
}
static struct V_22 * F_112 ( struct V_10 * V_11 )
{
struct V_22 * V_22 = NULL ;
V_22 = F_78 ( sizeof( struct V_22 ) , V_118 ) ;
if ( ! V_22 )
return NULL ;
if ( F_20 ( V_11 ) == V_7 ) {
F_113 ( V_22 ) = F_78 ( sizeof( struct V_161 ) ,
V_118 ) ;
if ( ! F_113 ( V_22 ) ) {
F_80 ( V_22 ) ;
return NULL ;
}
}
return V_22 ;
}
static void F_114 ( struct V_22 * V_22 )
{
struct V_10 * V_11 = F_115 ( V_22 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_80 ( F_113 ( V_22 ) ) ;
F_80 ( V_22 ) ;
}
int F_116 ( struct V_14 * V_19 , struct V_14 * V_15 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
const struct V_45 * V_46 = V_15 -> V_47 ;
struct V_22 * V_162 = NULL , * V_163 ;
struct V_164 V_165 ;
int V_166 ;
int V_26 = 0 , V_167 ;
if ( ! V_11 -> V_52 . V_53 &&
V_15 -> V_55 -> V_56 == NULL &&
V_46 -> V_57 == NULL ) {
F_117 ( L_20 ,
V_19 -> V_59 , V_15 -> V_59 ) ;
}
if ( V_15 -> V_81 & V_159 ) {
F_56 ( L_21 ) ;
return - V_168 ;
}
if ( V_19 == V_15 ) {
F_118 ( L_22 , V_19 -> V_59 ) ;
return - V_169 ;
}
if ( V_15 -> V_123 & V_125 ) {
F_56 ( L_23 , V_15 -> V_59 ) ;
if ( F_119 ( V_19 ) ) {
F_118 ( L_24 ,
V_19 -> V_59 , V_15 -> V_59 , V_19 -> V_59 ) ;
return - V_169 ;
} else {
F_117 ( L_25 ,
V_19 -> V_59 , V_15 -> V_59 ,
V_15 -> V_59 , V_19 -> V_59 ) ;
}
} else {
F_56 ( L_26 , V_15 -> V_59 ) ;
}
if ( ( V_15 -> V_81 & V_170 ) ) {
F_118 ( L_27 ,
V_15 -> V_59 ) ;
V_26 = - V_169 ;
goto V_171;
}
if ( ! F_19 ( V_11 ) ) {
if ( V_19 -> type != V_15 -> type ) {
F_56 ( L_28 ,
V_19 -> V_59 ,
V_19 -> type , V_15 -> type ) ;
V_26 = F_43 ( V_172 ,
V_19 ) ;
V_26 = F_120 ( V_26 ) ;
if ( V_26 ) {
F_118 ( L_29 ,
V_19 -> V_59 ) ;
V_26 = - V_168 ;
goto V_171;
}
F_121 ( V_19 ) ;
F_122 ( V_19 ) ;
if ( V_15 -> type != V_173 )
F_93 ( V_19 , V_15 ) ;
else {
F_123 ( V_19 ) ;
V_19 -> V_142 &= ~ V_174 ;
}
F_43 ( V_175 ,
V_19 ) ;
}
} else if ( V_19 -> type != V_15 -> type ) {
F_118 ( L_30 ,
V_15 -> V_59 , V_15 -> type , V_19 -> type ) ;
V_26 = - V_176 ;
goto V_171;
}
if ( V_46 -> V_177 == NULL ) {
if ( ! F_19 ( V_11 ) ) {
F_117 ( L_31 ,
V_19 -> V_59 ) ;
if ( F_20 ( V_11 ) == V_4 ) {
V_11 -> V_52 . V_108 = V_178 ;
F_117 ( L_32 ,
V_19 -> V_59 ) ;
}
} else if ( V_11 -> V_52 . V_108 != V_178 ) {
F_118 ( L_33 ,
V_19 -> V_59 ) ;
V_26 = - V_179 ;
goto V_171;
}
}
F_43 ( V_180 , V_15 ) ;
if ( ! F_19 ( V_11 ) &&
V_11 -> V_16 -> V_86 == V_181 )
F_55 ( V_11 -> V_16 , V_15 ) ;
V_162 = F_112 ( V_11 ) ;
if ( ! V_162 ) {
V_26 = - V_119 ;
goto V_171;
}
V_162 -> V_11 = V_11 ;
V_162 -> V_16 = V_15 ;
V_162 -> V_182 = 0 ;
V_162 -> V_183 = V_15 -> V_184 ;
V_26 = F_124 ( V_15 , V_11 -> V_16 -> V_184 ) ;
if ( V_26 ) {
F_56 ( L_34 , V_26 ) ;
goto V_185;
}
F_105 ( V_162 -> V_186 , V_15 -> V_85 ) ;
if ( ! V_11 -> V_52 . V_108 ||
F_20 ( V_11 ) != V_4 ) {
memcpy ( V_165 . V_187 , V_19 -> V_85 , V_19 -> V_84 ) ;
V_165 . V_188 = V_15 -> type ;
V_26 = F_125 ( V_15 , & V_165 ) ;
if ( V_26 ) {
F_56 ( L_35 , V_26 ) ;
goto V_189;
}
}
V_26 = F_126 ( V_15 ) ;
if ( V_26 ) {
F_56 ( L_36 , V_15 -> V_59 ) ;
goto V_190;
}
V_15 -> V_142 |= V_191 ;
if ( F_16 ( V_11 ) ) {
V_26 = F_127 ( V_11 , V_162 ) ;
if ( V_26 )
goto V_192;
}
if ( ! F_35 ( V_11 ) ) {
if ( V_19 -> V_81 & V_82 ) {
V_26 = F_36 ( V_15 , 1 ) ;
if ( V_26 )
goto V_192;
}
if ( V_19 -> V_81 & V_83 ) {
V_26 = F_38 ( V_15 , 1 ) ;
if ( V_26 )
goto V_192;
}
F_51 ( V_19 ) ;
F_128 ( V_15 , V_19 ) ;
F_129 ( V_15 , V_19 ) ;
F_54 ( V_19 ) ;
}
if ( F_20 ( V_11 ) == V_7 ) {
T_5 V_76 [ V_77 ] = V_78 ;
F_130 ( V_15 , V_76 ) ;
}
V_26 = F_131 ( V_15 , V_19 ) ;
if ( V_26 ) {
F_118 ( L_37 ,
V_19 -> V_59 , V_15 -> V_59 ) ;
goto V_192;
}
V_163 = F_132 ( V_11 ) ;
V_162 -> V_99 = 0 ;
V_162 -> V_193 = 0 ;
F_25 ( V_162 ) ;
V_162 -> V_194 = V_104 -
( F_133 ( V_11 -> V_52 . V_195 ) + 1 ) ;
for ( V_167 = 0 ; V_167 < V_196 ; V_167 ++ )
V_162 -> V_197 [ V_167 ] = V_162 -> V_194 ;
if ( V_11 -> V_52 . V_105 && ! V_11 -> V_52 . V_53 ) {
V_166 = F_29 ( V_11 , V_15 , 1 ) ;
if ( ( V_166 == - 1 ) && ! V_11 -> V_52 . V_195 ) {
F_117 ( L_38 ,
V_19 -> V_59 , V_15 -> V_59 ) ;
} else if ( V_166 == - 1 ) {
F_117 ( L_39 ,
V_19 -> V_59 , V_15 -> V_59 ) ;
}
}
if ( V_11 -> V_52 . V_105 ) {
if ( F_29 ( V_11 , V_15 , 0 ) == V_54 ) {
if ( V_11 -> V_52 . V_98 ) {
V_162 -> V_29 = V_43 ;
V_162 -> V_99 = V_11 -> V_52 . V_98 ;
} else {
V_162 -> V_29 = V_30 ;
}
} else {
V_162 -> V_29 = V_42 ;
}
} else if ( V_11 -> V_52 . V_195 ) {
V_162 -> V_29 = ( F_22 ( V_15 ) ?
V_30 : V_42 ) ;
} else {
V_162 -> V_29 = V_30 ;
}
if ( V_162 -> V_29 != V_42 )
V_162 -> V_103 = V_104 ;
F_56 ( L_40 ,
V_162 -> V_29 == V_42 ? L_41 :
( V_162 -> V_29 == V_30 ? L_42 : L_43 ) ) ;
if ( F_35 ( V_11 ) && V_11 -> V_52 . V_198 [ 0 ] ) {
if ( strcmp ( V_11 -> V_52 . V_198 , V_162 -> V_16 -> V_59 ) == 0 ) {
V_11 -> V_90 = V_162 ;
V_11 -> V_92 = true ;
}
}
switch ( F_20 ( V_11 ) ) {
case V_4 :
F_71 ( V_162 ,
V_106 ) ;
break;
case V_7 :
F_71 ( V_162 , V_106 ) ;
if ( ! V_163 ) {
F_113 ( V_162 ) -> V_199 = 1 ;
F_134 ( V_11 , 1000 / V_200 ) ;
} else {
F_113 ( V_162 ) -> V_199 =
F_113 ( V_163 ) -> V_199 + 1 ;
}
F_135 ( V_162 ) ;
break;
case V_8 :
case V_9 :
F_136 ( V_162 ) ;
F_71 ( V_162 , V_106 ) ;
break;
default:
F_56 ( L_44 ) ;
F_136 ( V_162 ) ;
if ( ! V_11 -> V_68 && V_162 -> V_29 == V_30 )
F_73 ( V_11 -> V_68 , V_162 ) ;
break;
}
#ifdef F_137
V_15 -> V_201 = V_11 -> V_16 -> V_201 ;
if ( V_15 -> V_201 ) {
if ( F_77 ( V_162 ) ) {
F_67 ( L_45 ,
V_19 -> V_59 ) ;
V_26 = - V_168 ;
goto V_202;
}
}
#endif
V_26 = F_138 ( V_15 , F_96 ,
V_162 ) ;
if ( V_26 ) {
F_56 ( L_46 , V_26 ) ;
goto V_202;
}
V_26 = F_107 ( V_19 , V_15 , V_162 ) ;
if ( V_26 ) {
F_56 ( L_47 , V_26 ) ;
goto V_203;
}
V_26 = F_139 ( V_162 ) ;
if ( V_26 ) {
F_56 ( L_48 , V_26 ) ;
goto V_204;
}
V_11 -> V_205 ++ ;
F_89 ( V_11 ) ;
F_18 ( V_11 ) ;
if ( F_35 ( V_11 ) ) {
F_140 () ;
F_75 ( & V_11 -> V_110 ) ;
F_76 ( V_11 ) ;
F_74 ( & V_11 -> V_110 ) ;
F_141 () ;
}
F_67 ( L_49 ,
V_19 -> V_59 , V_15 -> V_59 ,
F_142 ( V_162 ) ? L_50 : L_51 ,
V_162 -> V_29 != V_42 ? L_52 : L_53 ) ;
return 0 ;
V_204:
F_110 ( V_19 , V_15 ) ;
V_203:
F_143 ( V_15 ) ;
V_202:
if ( ! F_35 ( V_11 ) )
F_45 ( V_19 , V_15 ) ;
F_144 ( V_15 , V_19 ) ;
if ( V_11 -> V_90 == V_162 )
V_11 -> V_90 = NULL ;
if ( V_11 -> V_68 == V_162 ) {
F_140 () ;
F_75 ( & V_11 -> V_110 ) ;
F_66 ( V_11 , NULL ) ;
F_76 ( V_11 ) ;
F_74 ( & V_11 -> V_110 ) ;
F_141 () ;
}
F_81 ( V_162 ) ;
V_192:
V_15 -> V_142 &= ~ V_191 ;
F_145 ( V_15 ) ;
V_190:
if ( ! V_11 -> V_52 . V_108 ||
F_20 ( V_11 ) != V_4 ) {
F_105 ( V_165 . V_187 , V_162 -> V_186 ) ;
V_165 . V_188 = V_15 -> type ;
F_125 ( V_15 , & V_165 ) ;
}
V_189:
F_124 ( V_15 , V_162 -> V_183 ) ;
V_185:
F_114 ( V_162 ) ;
V_171:
if ( ! F_19 ( V_11 ) &&
F_146 ( V_19 -> V_85 , V_15 -> V_85 ) )
F_147 ( V_19 ) ;
return V_26 ;
}
static int F_148 ( struct V_14 * V_19 ,
struct V_14 * V_15 ,
bool V_206 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_207 ;
struct V_164 V_165 ;
int V_208 = V_19 -> V_81 ;
T_6 V_209 = V_19 -> V_123 ;
if ( ! ( V_15 -> V_81 & V_159 ) ||
! F_149 ( V_15 , V_19 ) ) {
F_118 ( L_54 ,
V_19 -> V_59 , V_15 -> V_59 ) ;
return - V_176 ;
}
F_140 () ;
V_22 = F_8 ( V_11 , V_15 ) ;
if ( ! V_22 ) {
F_67 ( L_55 ,
V_19 -> V_59 , V_15 -> V_59 ) ;
F_141 () ;
return - V_176 ;
}
F_150 ( V_22 ) ;
F_110 ( V_19 , V_15 ) ;
F_143 ( V_15 ) ;
F_75 ( & V_11 -> V_210 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_151 ( V_22 ) ;
F_74 ( & V_11 -> V_210 ) ;
F_67 ( L_56 ,
V_19 -> V_59 ,
F_142 ( V_22 ) ? L_57 : L_58 ,
V_15 -> V_59 ) ;
V_207 = V_11 -> V_68 ;
V_11 -> V_211 = NULL ;
if ( ! V_206 && ( ! V_11 -> V_52 . V_108 ||
F_20 ( V_11 ) != V_4 ) ) {
if ( F_146 ( V_19 -> V_85 , V_22 -> V_186 ) &&
F_19 ( V_11 ) )
F_117 ( L_59 ,
V_19 -> V_59 , V_15 -> V_59 ,
V_22 -> V_186 ,
V_19 -> V_59 , V_15 -> V_59 ) ;
}
if ( V_11 -> V_90 == V_22 )
V_11 -> V_90 = NULL ;
if ( V_207 == V_22 ) {
F_75 ( & V_11 -> V_110 ) ;
F_66 ( V_11 , NULL ) ;
F_74 ( & V_11 -> V_110 ) ;
}
if ( F_16 ( V_11 ) ) {
F_152 ( V_11 , V_22 ) ;
}
if ( V_206 ) {
F_153 ( V_11 -> V_68 , NULL ) ;
} else if ( V_207 == V_22 ) {
F_75 ( & V_11 -> V_110 ) ;
F_76 ( V_11 ) ;
F_74 ( & V_11 -> V_110 ) ;
}
if ( ! F_19 ( V_11 ) ) {
F_18 ( V_11 ) ;
F_147 ( V_19 ) ;
if ( F_119 ( V_19 ) ) {
F_117 ( L_60 ,
V_19 -> V_59 , V_19 -> V_59 ) ;
F_117 ( L_61 ,
V_19 -> V_59 ) ;
}
}
F_141 () ;
F_154 () ;
V_11 -> V_205 -- ;
if ( ! F_19 ( V_11 ) ) {
F_43 ( V_88 , V_11 -> V_16 ) ;
F_43 ( V_212 , V_11 -> V_16 ) ;
}
F_89 ( V_11 ) ;
if ( ! ( V_19 -> V_123 & V_125 ) &&
( V_209 & V_125 ) )
F_67 ( L_62 ,
V_19 -> V_59 , V_15 -> V_59 , V_19 -> V_59 ) ;
F_144 ( V_15 , V_19 ) ;
if ( ! F_35 ( V_11 ) ) {
if ( V_208 & V_82 )
F_36 ( V_15 , - 1 ) ;
if ( V_208 & V_83 )
F_38 ( V_15 , - 1 ) ;
F_45 ( V_19 , V_15 ) ;
}
F_81 ( V_22 ) ;
F_145 ( V_15 ) ;
if ( V_11 -> V_52 . V_108 != V_178 ||
F_20 ( V_11 ) != V_4 ) {
F_105 ( V_165 . V_187 , V_22 -> V_186 ) ;
V_165 . V_188 = V_15 -> type ;
F_125 ( V_15 , & V_165 ) ;
}
F_124 ( V_15 , V_22 -> V_183 ) ;
V_15 -> V_142 &= ~ V_191 ;
F_114 ( V_22 ) ;
return 0 ;
}
int F_155 ( struct V_14 * V_19 , struct V_14 * V_15 )
{
return F_148 ( V_19 , V_15 , false ) ;
}
static int F_156 ( struct V_14 * V_19 ,
struct V_14 * V_15 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
int V_150 ;
V_150 = F_155 ( V_19 , V_15 ) ;
if ( V_150 == 0 && ! F_19 ( V_11 ) ) {
V_19 -> V_142 |= V_213 ;
F_67 ( L_63 ,
V_19 -> V_59 , V_19 -> V_59 ) ;
F_157 ( V_19 ) ;
}
return V_150 ;
}
static int F_158 ( struct V_14 * V_19 , struct V_214 * V_215 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
V_215 -> V_216 = F_20 ( V_11 ) ;
V_215 -> V_105 = V_11 -> V_52 . V_105 ;
V_215 -> V_217 = V_11 -> V_205 ;
return 0 ;
}
static int F_159 ( struct V_14 * V_19 , struct V_218 * V_215 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
int V_167 = 0 , V_26 = - V_219 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
if ( V_167 ++ == ( int ) V_215 -> V_220 ) {
V_26 = 0 ;
strcpy ( V_215 -> V_221 , V_22 -> V_16 -> V_59 ) ;
V_215 -> V_29 = V_22 -> V_29 ;
V_215 -> V_102 = F_160 ( V_22 ) ;
V_215 -> V_193 = V_22 -> V_193 ;
break;
}
}
return V_26 ;
}
static int F_161 ( struct V_10 * V_11 )
{
int V_222 , V_223 = 0 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
bool V_224 ;
V_224 = ! V_11 -> V_68 ? true : false ;
F_162 (bond, slave, iter) {
V_22 -> V_225 = V_226 ;
V_222 = F_29 ( V_11 , V_22 -> V_16 , 0 ) ;
switch ( V_22 -> V_29 ) {
case V_30 :
if ( V_222 )
continue;
V_22 -> V_29 = V_41 ;
V_22 -> V_99 = V_11 -> V_52 . V_227 ;
if ( V_22 -> V_99 ) {
F_67 ( L_64 ,
V_11 -> V_16 -> V_59 ,
( F_20 ( V_11 ) ==
V_4 ) ?
( F_142 ( V_22 ) ?
L_65 : L_66 ) : L_67 ,
V_22 -> V_16 -> V_59 ,
V_11 -> V_52 . V_227 * V_11 -> V_52 . V_105 ) ;
}
case V_41 :
if ( V_222 ) {
V_22 -> V_29 = V_30 ;
V_22 -> V_103 = V_104 ;
F_67 ( L_68 ,
V_11 -> V_16 -> V_59 ,
( V_11 -> V_52 . V_227 - V_22 -> V_99 ) *
V_11 -> V_52 . V_105 ,
V_22 -> V_16 -> V_59 ) ;
continue;
}
if ( V_22 -> V_99 <= 0 ) {
V_22 -> V_225 = V_42 ;
V_223 ++ ;
continue;
}
V_22 -> V_99 -- ;
break;
case V_42 :
if ( ! V_222 )
continue;
V_22 -> V_29 = V_43 ;
V_22 -> V_99 = V_11 -> V_52 . V_98 ;
if ( V_22 -> V_99 ) {
F_67 ( L_69 ,
V_11 -> V_16 -> V_59 , V_22 -> V_16 -> V_59 ,
V_224 ? 0 :
V_11 -> V_52 . V_98 *
V_11 -> V_52 . V_105 ) ;
}
case V_43 :
if ( ! V_222 ) {
V_22 -> V_29 = V_42 ;
F_67 ( L_70 ,
V_11 -> V_16 -> V_59 ,
( V_11 -> V_52 . V_98 - V_22 -> V_99 ) *
V_11 -> V_52 . V_105 ,
V_22 -> V_16 -> V_59 ) ;
continue;
}
if ( V_224 )
V_22 -> V_99 = 0 ;
if ( V_22 -> V_99 <= 0 ) {
V_22 -> V_225 = V_30 ;
V_223 ++ ;
V_224 = false ;
continue;
}
V_22 -> V_99 -- ;
break;
}
}
return V_223 ;
}
static void F_163 ( struct V_10 * V_11 )
{
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
switch ( V_22 -> V_225 ) {
case V_226 :
continue;
case V_30 :
V_22 -> V_29 = V_30 ;
V_22 -> V_103 = V_104 ;
if ( F_20 ( V_11 ) == V_7 ) {
F_164 ( V_22 ) ;
} else if ( F_20 ( V_11 ) != V_4 ) {
F_136 ( V_22 ) ;
} else if ( V_22 != V_11 -> V_90 ) {
F_164 ( V_22 ) ;
}
F_67 ( L_71 ,
V_11 -> V_16 -> V_59 , V_22 -> V_16 -> V_59 ,
V_22 -> V_34 == V_35 ? 0 : V_22 -> V_34 ,
V_22 -> V_36 ? L_72 : L_73 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_68 ( V_22 , V_30 ) ;
if ( F_16 ( V_11 ) )
F_69 ( V_11 , V_22 ,
V_30 ) ;
if ( ! V_11 -> V_68 ||
( V_22 == V_11 -> V_90 ) )
goto V_228;
continue;
case V_42 :
if ( V_22 -> V_193 < V_229 )
V_22 -> V_193 ++ ;
V_22 -> V_29 = V_42 ;
if ( F_20 ( V_11 ) == V_4 ||
F_20 ( V_11 ) == V_7 )
F_71 ( V_22 ,
V_106 ) ;
F_67 ( L_74 ,
V_11 -> V_16 -> V_59 , V_22 -> V_16 -> V_59 ) ;
if ( F_20 ( V_11 ) == V_7 )
F_68 ( V_22 ,
V_42 ) ;
if ( F_16 ( V_11 ) )
F_69 ( V_11 , V_22 ,
V_42 ) ;
if ( V_22 == V_11 -> V_68 )
goto V_228;
continue;
default:
F_118 ( L_75 ,
V_11 -> V_16 -> V_59 , V_22 -> V_225 ,
V_22 -> V_16 -> V_59 ) ;
V_22 -> V_225 = V_226 ;
continue;
}
V_228:
F_50 () ;
F_140 () ;
F_75 ( & V_11 -> V_110 ) ;
F_76 ( V_11 ) ;
F_74 ( & V_11 -> V_110 ) ;
F_141 () ;
}
F_18 ( V_11 ) ;
}
static void F_165 ( struct V_69 * V_70 )
{
struct V_10 * V_11 = F_40 ( V_70 , struct V_10 ,
V_230 . V_70 ) ;
bool V_107 = false ;
unsigned long V_99 ;
V_99 = F_133 ( V_11 -> V_52 . V_105 ) ;
if ( ! F_19 ( V_11 ) )
goto V_231;
F_62 () ;
V_107 = F_61 ( V_11 ) ;
if ( F_161 ( V_11 ) ) {
F_64 () ;
if ( ! F_41 () ) {
V_99 = 1 ;
V_107 = false ;
goto V_231;
}
F_163 ( V_11 ) ;
F_44 () ;
} else
F_64 () ;
V_231:
if ( V_11 -> V_52 . V_105 )
F_42 ( V_11 -> V_72 , & V_11 -> V_230 , V_99 ) ;
if ( V_107 ) {
if ( ! F_41 () )
return;
F_43 ( V_112 , V_11 -> V_16 ) ;
F_44 () ;
}
}
static bool F_166 ( struct V_10 * V_11 , T_8 V_232 )
{
struct V_14 * V_233 ;
struct V_24 * V_25 ;
bool V_150 = false ;
if ( V_232 == F_167 ( V_11 -> V_16 , 0 , V_232 ) )
return true ;
F_62 () ;
F_168 (bond->dev, upper, iter) {
if ( V_232 == F_167 ( V_233 , 0 , V_232 ) ) {
V_150 = true ;
break;
}
}
F_64 () ;
return V_150 ;
}
static void F_169 ( struct V_14 * V_15 , int V_234 ,
T_8 V_235 , T_8 V_236 ,
struct V_237 * V_238 )
{
struct V_12 * V_13 ;
int V_167 ;
F_56 ( L_76 ,
V_234 , V_15 -> V_59 , & V_235 , & V_236 ) ;
V_13 = F_170 ( V_234 , V_239 , V_235 , V_15 , V_236 ,
NULL , V_15 -> V_85 , NULL ) ;
if ( ! V_13 ) {
F_171 ( L_77 ) ;
return;
}
for ( V_167 = V_240 - 1 ; V_167 > 0 ; V_167 -- ) {
if ( ! V_238 [ V_167 ] . V_241 )
continue;
F_56 ( L_78 ,
F_172 ( V_238 [ V_167 ] . V_242 ) , V_238 [ V_167 ] . V_241 ) ;
V_13 = F_173 ( V_13 , V_238 [ V_167 ] . V_242 ,
V_238 [ V_167 ] . V_241 ) ;
if ( ! V_13 ) {
F_171 ( L_79 ) ;
return;
}
}
if ( V_238 [ 0 ] . V_241 ) {
F_56 ( L_80 ,
F_172 ( V_238 [ 0 ] . V_242 ) , V_238 [ 0 ] . V_241 ) ;
V_13 = F_174 ( V_13 , V_238 [ 0 ] . V_242 , V_238 [ 0 ] . V_241 ) ;
if ( ! V_13 ) {
F_171 ( L_81 ) ;
return;
}
}
F_175 ( V_13 ) ;
}
bool F_176 ( struct V_14 * V_243 ,
struct V_14 * V_244 ,
struct V_237 * V_238 )
{
struct V_14 * V_233 ;
struct V_24 * V_25 ;
int V_245 ;
if ( V_243 == V_244 )
return true ;
F_177 (start_dev, upper, iter) {
if ( F_176 ( V_233 , V_244 , V_238 ) ) {
if ( F_178 ( V_233 ) ) {
V_245 = F_179 ( V_233 ) ;
if ( V_245 >= V_240 )
return false ;
V_238 [ V_245 ] . V_242 =
F_180 ( V_233 ) ;
V_238 [ V_245 ] . V_241 = F_181 ( V_233 ) ;
}
return true ;
}
}
return false ;
}
static void F_182 ( struct V_10 * V_11 , struct V_22 * V_22 )
{
struct V_246 * V_247 ;
struct V_237 V_238 [ V_240 ] ;
T_8 * V_248 = V_11 -> V_52 . V_249 , V_165 ;
int V_167 ;
bool V_150 ;
for ( V_167 = 0 ; V_167 < V_196 && V_248 [ V_167 ] ; V_167 ++ ) {
F_56 ( L_82 , & V_248 [ V_167 ] ) ;
memset ( V_238 , 0 , sizeof( V_238 ) ) ;
V_247 = F_183 ( F_184 ( V_11 -> V_16 ) , V_248 [ V_167 ] , 0 ,
V_250 , 0 ) ;
if ( F_185 ( V_247 ) ) {
if ( V_11 -> V_52 . V_251 )
F_186 ( L_83 ,
V_11 -> V_16 -> V_59 ,
& V_248 [ V_167 ] ) ;
F_169 ( V_22 -> V_16 , V_252 , V_248 [ V_167 ] ,
0 , V_238 ) ;
continue;
}
if ( V_247 -> V_253 . V_16 == V_11 -> V_16 )
goto V_254;
F_62 () ;
V_150 = F_176 ( V_11 -> V_16 , V_247 -> V_253 . V_16 , V_238 ) ;
F_64 () ;
if ( V_150 )
goto V_254;
F_56 ( L_84 ,
V_11 -> V_16 -> V_59 , & V_248 [ V_167 ] ,
V_247 -> V_253 . V_16 ? V_247 -> V_253 . V_16 -> V_59 : L_15 ) ;
F_187 ( V_247 ) ;
continue;
V_254:
V_165 = F_167 ( V_247 -> V_253 . V_16 , V_248 [ V_167 ] , 0 ) ;
F_187 ( V_247 ) ;
F_169 ( V_22 -> V_16 , V_252 , V_248 [ V_167 ] ,
V_165 , V_238 ) ;
}
}
static void F_188 ( struct V_10 * V_11 , struct V_22 * V_22 , T_8 V_255 , T_8 V_256 )
{
int V_167 ;
if ( ! V_255 || ! F_166 ( V_11 , V_256 ) ) {
F_56 ( L_85 , & V_255 , & V_256 ) ;
return;
}
V_167 = F_189 ( V_11 -> V_52 . V_249 , V_255 ) ;
if ( V_167 == - 1 ) {
F_56 ( L_86 , & V_255 ) ;
return;
}
V_22 -> V_194 = V_104 ;
V_22 -> V_197 [ V_167 ] = V_104 ;
}
int F_190 ( const struct V_12 * V_13 , struct V_10 * V_11 ,
struct V_22 * V_22 )
{
struct V_257 * V_258 = (struct V_257 * ) V_13 -> V_157 ;
struct V_22 * V_68 ;
unsigned char * V_259 ;
T_8 V_255 , V_256 ;
int V_260 , V_261 = V_13 -> V_262 == F_191 ( V_239 ) ;
if ( ! F_192 ( V_11 , V_22 ) ) {
if ( ( F_193 ( V_11 ) && V_261 ) ||
! F_193 ( V_11 ) )
V_22 -> V_194 = V_104 ;
return V_151 ;
} else if ( ! V_261 ) {
return V_151 ;
}
V_260 = F_194 ( V_11 -> V_16 ) ;
F_56 ( L_87 ,
V_11 -> V_16 -> V_59 , V_13 -> V_16 -> V_59 ) ;
if ( V_260 > F_195 ( V_13 ) ) {
V_258 = F_196 ( V_260 , V_152 ) ;
if ( ! V_258 )
goto V_263;
if ( F_197 ( V_13 , 0 , V_258 , V_260 ) < 0 )
goto V_263;
}
if ( V_258 -> V_264 != V_11 -> V_16 -> V_84 ||
V_13 -> V_146 == V_265 ||
V_13 -> V_146 == V_266 ||
V_258 -> V_267 != F_198 ( V_173 ) ||
V_258 -> V_268 != F_198 ( V_269 ) ||
V_258 -> V_270 != 4 )
goto V_263;
V_259 = ( unsigned char * ) ( V_258 + 1 ) ;
V_259 += V_11 -> V_16 -> V_84 ;
memcpy ( & V_255 , V_259 , 4 ) ;
V_259 += 4 + V_11 -> V_16 -> V_84 ;
memcpy ( & V_256 , V_259 , 4 ) ;
F_56 ( L_88 ,
V_11 -> V_16 -> V_59 , V_22 -> V_16 -> V_59 , F_160 ( V_22 ) ,
V_11 -> V_52 . V_251 , F_192 ( V_11 , V_22 ) ,
& V_255 , & V_256 ) ;
V_68 = F_63 ( V_11 -> V_68 ) ;
if ( F_142 ( V_22 ) )
F_188 ( V_11 , V_22 , V_255 , V_256 ) ;
else if ( V_68 &&
F_199 ( F_200 ( V_11 , V_68 ) ,
V_68 -> V_103 ) )
F_188 ( V_11 , V_22 , V_256 , V_255 ) ;
V_263:
if ( V_258 != (struct V_257 * ) V_13 -> V_157 )
F_80 ( V_258 ) ;
return V_151 ;
}
static bool F_201 ( struct V_10 * V_11 , unsigned long V_271 ,
int V_272 )
{
int V_273 = F_133 ( V_11 -> V_52 . V_195 ) ;
return F_202 ( V_104 ,
V_271 - V_273 ,
V_271 + V_272 * V_273 + V_273 / 2 ) ;
}
static void F_203 ( struct V_69 * V_70 )
{
struct V_10 * V_11 = F_40 ( V_70 , struct V_10 ,
V_274 . V_70 ) ;
struct V_22 * V_22 , * V_207 ;
struct V_24 * V_25 ;
int V_228 = 0 , V_275 = 0 ;
if ( ! F_19 ( V_11 ) )
goto V_231;
F_62 () ;
V_207 = F_100 ( V_11 -> V_68 ) ;
F_162 (bond, slave, iter) {
unsigned long V_276 = F_204 ( V_22 -> V_16 ) ;
if ( V_22 -> V_29 != V_30 ) {
if ( F_201 ( V_11 , V_276 , 1 ) &&
F_201 ( V_11 , V_22 -> V_194 , 1 ) ) {
V_22 -> V_29 = V_30 ;
V_275 = 1 ;
if ( ! V_207 ) {
F_67 ( L_89 ,
V_11 -> V_16 -> V_59 ,
V_22 -> V_16 -> V_59 ) ;
V_228 = 1 ;
} else {
F_67 ( L_90 ,
V_11 -> V_16 -> V_59 ,
V_22 -> V_16 -> V_59 ) ;
}
}
} else {
if ( ! F_201 ( V_11 , V_276 , 2 ) ||
! F_201 ( V_11 , V_22 -> V_194 , 2 ) ) {
V_22 -> V_29 = V_42 ;
V_275 = 1 ;
if ( V_22 -> V_193 < V_229 )
V_22 -> V_193 ++ ;
F_67 ( L_91 ,
V_11 -> V_16 -> V_59 , V_22 -> V_16 -> V_59 ) ;
if ( V_22 == V_207 )
V_228 = 1 ;
}
}
if ( F_60 ( V_22 ) )
F_182 ( V_11 , V_22 ) ;
}
F_64 () ;
if ( V_228 || V_275 ) {
if ( ! F_41 () )
goto V_231;
if ( V_275 ) {
F_205 ( V_11 ) ;
} else if ( V_228 ) {
F_140 () ;
F_75 ( & V_11 -> V_110 ) ;
F_76 ( V_11 ) ;
F_74 ( & V_11 -> V_110 ) ;
F_141 () ;
}
F_44 () ;
}
V_231:
if ( V_11 -> V_52 . V_195 )
F_42 ( V_11 -> V_72 , & V_11 -> V_274 ,
F_133 ( V_11 -> V_52 . V_195 ) ) ;
}
static int F_206 ( struct V_10 * V_11 )
{
unsigned long V_276 , V_194 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_223 = 0 ;
F_162 (bond, slave, iter) {
V_22 -> V_225 = V_226 ;
V_194 = F_200 ( V_11 , V_22 ) ;
if ( V_22 -> V_29 != V_30 ) {
if ( F_201 ( V_11 , V_194 , 1 ) ) {
V_22 -> V_225 = V_30 ;
V_223 ++ ;
}
continue;
}
if ( F_201 ( V_11 , V_22 -> V_103 , 2 ) )
continue;
if ( ! F_142 ( V_22 ) &&
! V_11 -> V_211 &&
! F_201 ( V_11 , V_194 , 3 ) ) {
V_22 -> V_225 = V_42 ;
V_223 ++ ;
}
V_276 = F_204 ( V_22 -> V_16 ) ;
if ( F_142 ( V_22 ) &&
( ! F_201 ( V_11 , V_276 , 2 ) ||
! F_201 ( V_11 , V_194 , 2 ) ) ) {
V_22 -> V_225 = V_42 ;
V_223 ++ ;
}
}
return V_223 ;
}
static void F_207 ( struct V_10 * V_11 )
{
unsigned long V_276 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_12 (bond, slave, iter) {
switch ( V_22 -> V_225 ) {
case V_226 :
continue;
case V_30 :
V_276 = F_204 ( V_22 -> V_16 ) ;
if ( V_11 -> V_68 != V_22 ||
( ! V_11 -> V_68 &&
F_201 ( V_11 , V_276 , 1 ) ) ) {
V_22 -> V_29 = V_30 ;
if ( V_11 -> V_211 ) {
F_71 (
V_11 -> V_211 ,
V_106 ) ;
V_11 -> V_211 = NULL ;
}
F_67 ( L_89 ,
V_11 -> V_16 -> V_59 , V_22 -> V_16 -> V_59 ) ;
if ( ! V_11 -> V_68 ||
( V_22 == V_11 -> V_90 ) )
goto V_228;
}
continue;
case V_42 :
if ( V_22 -> V_193 < V_229 )
V_22 -> V_193 ++ ;
V_22 -> V_29 = V_42 ;
F_71 ( V_22 ,
V_106 ) ;
F_67 ( L_74 ,
V_11 -> V_16 -> V_59 , V_22 -> V_16 -> V_59 ) ;
if ( V_22 == V_11 -> V_68 ) {
V_11 -> V_211 = NULL ;
goto V_228;
}
continue;
default:
F_118 ( L_92 ,
V_11 -> V_16 -> V_59 , V_22 -> V_225 ,
V_22 -> V_16 -> V_59 ) ;
continue;
}
V_228:
F_50 () ;
F_140 () ;
F_75 ( & V_11 -> V_110 ) ;
F_76 ( V_11 ) ;
F_74 ( & V_11 -> V_110 ) ;
F_141 () ;
}
F_18 ( V_11 ) ;
}
static bool F_208 ( struct V_10 * V_11 )
{
struct V_22 * V_22 , * V_277 = NULL , * V_162 = NULL ,
* V_278 = F_63 ( V_11 -> V_211 ) ,
* V_68 = F_63 ( V_11 -> V_68 ) ;
struct V_24 * V_25 ;
bool V_254 = false ;
bool V_279 = V_280 ;
if ( V_278 && V_68 )
F_67 ( L_93 ,
V_278 -> V_16 -> V_59 ,
V_68 -> V_16 -> V_59 ) ;
if ( V_68 ) {
F_182 ( V_11 , V_68 ) ;
return V_279 ;
}
if ( ! V_278 ) {
V_278 = F_209 ( V_11 ) ;
if ( ! V_278 )
return V_279 ;
}
F_71 ( V_278 , V_280 ) ;
F_162 (bond, slave, iter) {
if ( ! V_254 && ! V_277 && F_60 ( V_22 ) )
V_277 = V_22 ;
if ( V_254 && ! V_162 && F_60 ( V_22 ) )
V_162 = V_22 ;
if ( ! F_60 ( V_22 ) && V_22 -> V_29 == V_30 ) {
V_22 -> V_29 = V_42 ;
if ( V_22 -> V_193 < V_229 )
V_22 -> V_193 ++ ;
F_71 ( V_22 ,
V_280 ) ;
F_67 ( L_94 ,
V_11 -> V_16 -> V_59 , V_22 -> V_16 -> V_59 ) ;
}
if ( V_22 == V_278 )
V_254 = true ;
}
if ( ! V_162 && V_277 )
V_162 = V_277 ;
if ( ! V_162 )
goto V_281;
V_162 -> V_29 = V_43 ;
F_72 ( V_162 , V_280 ) ;
F_182 ( V_11 , V_162 ) ;
V_162 -> V_103 = V_104 ;
F_73 ( V_11 -> V_211 , V_162 ) ;
V_281:
F_162 (bond, slave, iter) {
if ( V_22 -> V_282 ) {
V_279 = V_106 ;
break;
}
}
return V_279 ;
}
static void F_210 ( struct V_69 * V_70 )
{
struct V_10 * V_11 = F_40 ( V_70 , struct V_10 ,
V_274 . V_70 ) ;
bool V_107 = false ;
bool V_279 = false ;
int V_273 ;
V_273 = F_133 ( V_11 -> V_52 . V_195 ) ;
if ( ! F_19 ( V_11 ) )
goto V_231;
F_62 () ;
V_107 = F_61 ( V_11 ) ;
if ( F_206 ( V_11 ) ) {
F_64 () ;
if ( ! F_41 () ) {
V_273 = 1 ;
V_107 = false ;
goto V_231;
}
F_207 ( V_11 ) ;
F_44 () ;
F_62 () ;
}
V_279 = F_208 ( V_11 ) ;
F_64 () ;
V_231:
if ( V_11 -> V_52 . V_195 )
F_42 ( V_11 -> V_72 , & V_11 -> V_274 , V_273 ) ;
if ( V_107 || V_279 ) {
if ( ! F_41 () )
return;
if ( V_107 )
F_43 ( V_112 ,
V_11 -> V_16 ) ;
if ( V_279 )
F_211 ( V_11 ) ;
F_44 () ;
}
}
static int F_212 ( struct V_10 * V_11 )
{
F_213 ( V_11 ) ;
F_214 ( V_11 ) ;
F_215 ( V_11 ) ;
return V_283 ;
}
static int F_216 ( unsigned long V_284 ,
struct V_14 * V_19 )
{
struct V_10 * V_285 = F_11 ( V_19 ) ;
switch ( V_284 ) {
case V_286 :
return F_212 ( V_285 ) ;
case V_287 :
F_213 ( V_285 ) ;
break;
case V_288 :
F_214 ( V_285 ) ;
break;
case V_112 :
if ( V_285 -> V_100 )
V_285 -> V_100 -- ;
break;
default:
break;
}
return V_283 ;
}
static int F_217 ( unsigned long V_284 ,
struct V_14 * V_15 )
{
struct V_22 * V_22 = F_218 ( V_15 ) ;
struct V_10 * V_11 ;
struct V_14 * V_19 ;
T_3 V_289 ;
T_5 V_290 ;
if ( ! V_22 )
return V_283 ;
V_19 = V_22 -> V_11 -> V_16 ;
V_11 = V_22 -> V_11 ;
switch ( V_284 ) {
case V_287 :
if ( V_19 -> type != V_173 )
F_156 ( V_19 , V_15 ) ;
else
F_155 ( V_19 , V_15 ) ;
break;
case V_291 :
case V_292 :
V_289 = V_22 -> V_34 ;
V_290 = V_22 -> V_36 ;
F_25 ( V_22 ) ;
if ( F_20 ( V_11 ) == V_7 ) {
if ( V_289 != V_22 -> V_34 )
F_219 ( V_22 ) ;
if ( V_290 != V_22 -> V_36 )
F_220 ( V_22 ) ;
}
break;
case V_293 :
break;
case V_294 :
break;
case V_286 :
if ( ! F_35 ( V_11 ) ||
! V_11 -> V_52 . V_198 [ 0 ] )
break;
if ( V_22 == V_11 -> V_90 ) {
V_11 -> V_90 = NULL ;
} else if ( ! strcmp ( V_15 -> V_59 , V_11 -> V_52 . V_198 ) ) {
V_11 -> V_90 = V_22 ;
} else {
break;
}
F_67 ( L_95 ,
V_11 -> V_16 -> V_59 ,
V_11 -> V_90 ? V_15 -> V_59 : L_96 ) ;
F_140 () ;
F_75 ( & V_11 -> V_110 ) ;
F_76 ( V_11 ) ;
F_74 ( & V_11 -> V_110 ) ;
F_141 () ;
break;
case V_295 :
F_89 ( V_11 ) ;
break;
case V_73 :
F_43 ( V_284 , V_22 -> V_11 -> V_16 ) ;
break;
default:
break;
}
return V_283 ;
}
static int F_221 ( struct V_296 * V_297 ,
unsigned long V_284 , void * V_298 )
{
struct V_14 * V_299 = F_222 ( V_298 ) ;
F_56 ( L_97 ,
V_299 ? V_299 -> V_59 : L_98 , V_284 ) ;
if ( ! ( V_299 -> V_142 & V_191 ) )
return V_283 ;
if ( V_299 -> V_81 & V_300 ) {
F_56 ( L_99 ) ;
return F_216 ( V_284 , V_299 ) ;
}
if ( V_299 -> V_81 & V_159 ) {
F_56 ( L_100 ) ;
return F_217 ( V_284 , V_299 ) ;
}
return V_283 ;
}
static inline T_3 F_223 ( struct V_12 * V_13 )
{
struct V_301 * V_157 = (struct V_301 * ) V_13 -> V_157 ;
if ( F_195 ( V_13 ) >= F_224 ( struct V_301 , V_302 ) )
return V_157 -> V_158 [ 5 ] ^ V_157 -> V_303 [ 5 ] ;
return 0 ;
}
static bool F_225 ( struct V_10 * V_11 , struct V_12 * V_13 ,
struct V_304 * V_305 )
{
const struct V_306 * V_307 ;
const struct V_308 * V_309 ;
int V_310 , V_20 = - 1 ;
if ( V_11 -> V_52 . V_311 > V_312 )
return F_226 ( V_13 , V_305 ) ;
V_305 -> V_313 = 0 ;
V_310 = F_227 ( V_13 ) ;
if ( V_13 -> V_262 == F_198 ( V_269 ) ) {
if ( F_5 ( ! F_228 ( V_13 , V_310 + sizeof( * V_309 ) ) ) )
return false ;
V_309 = F_229 ( V_13 ) ;
V_305 -> V_314 = V_309 -> V_315 ;
V_305 -> V_253 = V_309 -> V_316 ;
V_310 += V_309 -> V_317 << 2 ;
if ( ! F_230 ( V_309 ) )
V_20 = V_309 -> V_262 ;
} else if ( V_13 -> V_262 == F_198 ( V_318 ) ) {
if ( F_5 ( ! F_228 ( V_13 , V_310 + sizeof( * V_307 ) ) ) )
return false ;
V_307 = F_231 ( V_13 ) ;
V_305 -> V_314 = ( V_319 T_8 ) F_232 ( & V_307 -> V_315 ) ;
V_305 -> V_253 = ( V_319 T_8 ) F_232 ( & V_307 -> V_316 ) ;
V_310 += sizeof( * V_307 ) ;
V_20 = V_307 -> V_320 ;
} else {
return false ;
}
if ( V_11 -> V_52 . V_311 == V_321 && V_20 >= 0 )
V_305 -> V_313 = F_233 ( V_13 , V_310 , V_20 ) ;
return true ;
}
T_3 F_234 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
struct V_304 V_322 ;
T_3 V_323 ;
if ( V_11 -> V_52 . V_311 == V_324 ||
! F_225 ( V_11 , V_13 , & V_322 ) )
return F_223 ( V_13 ) ;
if ( V_11 -> V_52 . V_311 == V_312 ||
V_11 -> V_52 . V_311 == V_325 )
V_323 = F_223 ( V_13 ) ;
else
V_323 = ( V_319 T_3 ) V_322 . V_313 ;
V_323 ^= ( V_319 T_3 ) V_322 . V_253 ^ ( V_319 T_3 ) V_322 . V_314 ;
V_323 ^= ( V_323 >> 16 ) ;
V_323 ^= ( V_323 >> 8 ) ;
return V_323 ;
}
static void F_235 ( struct V_10 * V_11 )
{
F_236 ( & V_11 -> V_71 ,
F_39 ) ;
F_236 ( & V_11 -> V_326 , V_327 ) ;
F_236 ( & V_11 -> V_230 , F_165 ) ;
if ( F_20 ( V_11 ) == V_4 )
F_236 ( & V_11 -> V_274 , F_210 ) ;
else
F_236 ( & V_11 -> V_274 , F_203 ) ;
F_236 ( & V_11 -> V_328 , V_329 ) ;
}
static void F_237 ( struct V_10 * V_11 )
{
F_238 ( & V_11 -> V_230 ) ;
F_238 ( & V_11 -> V_274 ) ;
F_238 ( & V_11 -> V_326 ) ;
F_238 ( & V_11 -> V_328 ) ;
F_238 ( & V_11 -> V_71 ) ;
}
static int F_239 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_240 ( & V_11 -> V_210 ) ;
if ( F_19 ( V_11 ) ) {
F_240 ( & V_11 -> V_110 ) ;
F_12 (bond, slave, iter) {
if ( F_35 ( V_11 )
&& ( V_22 != V_11 -> V_68 ) ) {
F_71 ( V_22 ,
V_106 ) ;
} else {
F_72 ( V_22 ,
V_106 ) ;
}
}
F_241 ( & V_11 -> V_110 ) ;
}
F_241 ( & V_11 -> V_210 ) ;
F_235 ( V_11 ) ;
if ( F_16 ( V_11 ) ) {
if ( F_242 ( V_11 , ( F_20 ( V_11 ) == V_9 ) ) )
return - V_119 ;
if ( V_11 -> V_52 . V_330 )
F_42 ( V_11 -> V_72 , & V_11 -> V_326 , 0 ) ;
}
if ( V_11 -> V_52 . V_105 )
F_42 ( V_11 -> V_72 , & V_11 -> V_230 , 0 ) ;
if ( V_11 -> V_52 . V_195 ) {
F_42 ( V_11 -> V_72 , & V_11 -> V_274 , 0 ) ;
V_11 -> F_97 = F_190 ;
}
if ( F_20 ( V_11 ) == V_7 ) {
F_42 ( V_11 -> V_72 , & V_11 -> V_328 , 0 ) ;
V_11 -> F_97 = V_331 ;
F_243 ( V_11 , 1 ) ;
}
return 0 ;
}
static int F_244 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_237 ( V_11 ) ;
V_11 -> V_100 = 0 ;
if ( F_16 ( V_11 ) )
F_245 ( V_11 ) ;
V_11 -> F_97 = NULL ;
return 0 ;
}
static struct V_332 * F_246 ( struct V_14 * V_19 ,
struct V_332 * V_333 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_332 V_334 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
memset ( V_333 , 0 , sizeof( * V_333 ) ) ;
F_247 ( & V_11 -> V_210 ) ;
F_12 (bond, slave, iter) {
const struct V_332 * V_335 =
F_248 ( V_22 -> V_16 , & V_334 ) ;
V_333 -> V_336 += V_335 -> V_336 ;
V_333 -> V_337 += V_335 -> V_337 ;
V_333 -> V_338 += V_335 -> V_338 ;
V_333 -> V_339 += V_335 -> V_339 ;
V_333 -> V_340 += V_335 -> V_340 ;
V_333 -> V_341 += V_335 -> V_341 ;
V_333 -> V_342 += V_335 -> V_342 ;
V_333 -> V_343 += V_335 -> V_343 ;
V_333 -> V_344 += V_335 -> V_344 ;
V_333 -> V_345 += V_335 -> V_345 ;
V_333 -> V_346 += V_335 -> V_346 ;
V_333 -> V_347 += V_335 -> V_347 ;
V_333 -> V_348 += V_335 -> V_348 ;
V_333 -> V_349 += V_335 -> V_349 ;
V_333 -> V_350 += V_335 -> V_350 ;
V_333 -> V_351 += V_335 -> V_351 ;
V_333 -> V_352 += V_335 -> V_352 ;
V_333 -> V_353 += V_335 -> V_353 ;
V_333 -> V_354 += V_335 -> V_354 ;
V_333 -> V_355 += V_335 -> V_355 ;
V_333 -> V_356 += V_335 -> V_356 ;
}
F_249 ( & V_11 -> V_210 ) ;
return V_333 ;
}
static int F_250 ( struct V_14 * V_19 , struct V_48 * V_49 , int V_357 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_14 * V_15 = NULL ;
struct V_214 V_358 ;
struct V_214 T_9 * V_359 = NULL ;
struct V_218 V_360 ;
struct V_218 T_9 * V_361 = NULL ;
struct V_50 * V_51 = NULL ;
struct V_362 V_363 ;
struct V_364 * V_364 ;
int V_26 = 0 ;
F_56 ( L_101 , V_19 -> V_59 , V_357 ) ;
switch ( V_357 ) {
case V_61 :
V_51 = F_32 ( V_49 ) ;
if ( ! V_51 )
return - V_176 ;
V_51 -> V_365 = 0 ;
case V_64 :
V_51 = F_32 ( V_49 ) ;
if ( ! V_51 )
return - V_176 ;
if ( V_51 -> V_62 == 1 ) {
V_51 -> V_65 = 0 ;
F_240 ( & V_11 -> V_210 ) ;
F_240 ( & V_11 -> V_110 ) ;
if ( F_22 ( V_11 -> V_16 ) )
V_51 -> V_65 = V_54 ;
F_241 ( & V_11 -> V_110 ) ;
F_241 ( & V_11 -> V_210 ) ;
}
return 0 ;
case V_366 :
case V_367 :
V_359 = (struct V_214 T_9 * ) V_49 -> V_368 ;
if ( F_251 ( & V_358 , V_359 , sizeof( V_214 ) ) )
return - V_369 ;
V_26 = F_158 ( V_19 , & V_358 ) ;
if ( V_26 == 0 &&
F_252 ( V_359 , & V_358 , sizeof( V_214 ) ) )
return - V_369 ;
return V_26 ;
case V_370 :
case V_371 :
V_361 = (struct V_218 T_9 * ) V_49 -> V_368 ;
if ( F_251 ( & V_360 , V_361 , sizeof( V_218 ) ) )
return - V_369 ;
V_26 = F_159 ( V_19 , & V_360 ) ;
if ( V_26 == 0 &&
F_252 ( V_361 , & V_360 , sizeof( V_218 ) ) )
return - V_369 ;
return V_26 ;
default:
break;
}
V_364 = F_184 ( V_19 ) ;
if ( ! F_253 ( V_364 -> V_372 , V_373 ) )
return - V_169 ;
V_15 = F_254 ( V_364 , V_49 -> V_374 ) ;
F_56 ( L_102 , V_15 ) ;
if ( ! V_15 )
return - V_219 ;
F_56 ( L_103 , V_15 -> V_59 ) ;
switch ( V_357 ) {
case V_375 :
case V_376 :
V_26 = F_116 ( V_19 , V_15 ) ;
break;
case V_377 :
case V_378 :
V_26 = F_155 ( V_19 , V_15 ) ;
break;
case V_379 :
case V_380 :
F_55 ( V_19 , V_15 ) ;
V_26 = 0 ;
break;
case V_381 :
case V_382 :
F_255 ( & V_363 , V_15 -> V_59 ) ;
V_26 = F_256 ( V_11 , V_383 , & V_363 ) ;
break;
default:
V_26 = - V_179 ;
}
return V_26 ;
}
static void F_257 ( struct V_14 * V_19 , int V_384 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
if ( V_384 & V_82 )
F_34 ( V_11 ,
V_19 -> V_81 & V_82 ? 1 : - 1 ) ;
if ( V_384 & V_83 )
F_37 ( V_11 ,
V_19 -> V_81 & V_83 ? 1 : - 1 ) ;
}
static void F_258 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_62 () ;
if ( F_35 ( V_11 ) ) {
V_22 = F_63 ( V_11 -> V_68 ) ;
if ( V_22 ) {
F_52 ( V_22 -> V_16 , V_19 ) ;
F_53 ( V_22 -> V_16 , V_19 ) ;
}
} else {
F_162 (bond, slave, iter) {
F_129 ( V_22 -> V_16 , V_19 ) ;
F_128 ( V_22 -> V_16 , V_19 ) ;
}
}
F_64 () ;
}
static int F_259 ( struct V_385 * V_386 )
{
struct V_10 * V_11 = F_11 ( V_386 -> V_16 ) ;
const struct V_45 * V_46 ;
struct V_387 V_388 ;
struct V_22 * V_22 ;
int V_150 ;
V_22 = F_260 ( V_11 ) ;
if ( ! V_22 )
return 0 ;
V_46 = V_22 -> V_16 -> V_47 ;
if ( ! V_46 -> V_389 )
return 0 ;
V_388 . V_390 = NULL ;
V_388 . V_391 = NULL ;
V_150 = V_46 -> V_389 ( V_22 -> V_16 , & V_388 ) ;
if ( V_150 )
return V_150 ;
V_386 -> V_388 -> V_391 = V_388 . V_391 ;
if ( ! V_388 . V_390 )
return 0 ;
return V_388 . V_390 ( V_386 ) ;
}
static int F_261 ( struct V_14 * V_16 ,
struct V_387 * V_388 )
{
if ( V_388 -> V_16 == V_16 )
V_388 -> V_390 = F_259 ;
return 0 ;
}
static int F_262 ( struct V_14 * V_19 , int V_392 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_23 ;
struct V_24 * V_25 ;
int V_26 = 0 ;
F_56 ( L_104 ,
V_11 , V_19 ? V_19 -> V_59 : L_98 , V_392 ) ;
F_12 (bond, slave, iter) {
F_56 ( L_105 ,
V_22 , V_22 -> V_16 -> V_47 -> V_393 ) ;
V_26 = F_124 ( V_22 -> V_16 , V_392 ) ;
if ( V_26 ) {
F_56 ( L_106 , V_26 , V_22 -> V_16 -> V_59 ) ;
goto V_27;
}
}
V_19 -> V_184 = V_392 ;
return 0 ;
V_27:
F_12 (bond, rollback_slave, iter) {
int V_394 ;
if ( V_23 == V_22 )
break;
V_394 = F_124 ( V_23 -> V_16 , V_19 -> V_184 ) ;
if ( V_394 ) {
F_56 ( L_107 ,
V_394 , V_23 -> V_16 -> V_59 ) ;
}
}
return V_26 ;
}
static int F_263 ( struct V_14 * V_19 , void * V_165 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 , * V_23 ;
struct V_164 * V_395 = V_165 , V_396 ;
struct V_24 * V_25 ;
int V_26 = 0 ;
if ( F_20 ( V_11 ) == V_9 )
return F_264 ( V_19 , V_165 ) ;
F_56 ( L_108 ,
V_11 , V_19 ? V_19 -> V_59 : L_98 ) ;
if ( V_11 -> V_52 . V_108 &&
F_20 ( V_11 ) == V_4 )
return 0 ;
if ( ! F_265 ( V_395 -> V_187 ) )
return - V_397 ;
F_12 (bond, slave, iter) {
F_56 ( L_109 , V_22 , V_22 -> V_16 -> V_59 ) ;
V_26 = F_125 ( V_22 -> V_16 , V_165 ) ;
if ( V_26 ) {
F_56 ( L_106 , V_26 , V_22 -> V_16 -> V_59 ) ;
goto V_27;
}
}
memcpy ( V_19 -> V_85 , V_395 -> V_187 , V_19 -> V_84 ) ;
return 0 ;
V_27:
memcpy ( V_396 . V_187 , V_19 -> V_85 , V_19 -> V_84 ) ;
V_396 . V_188 = V_19 -> type ;
F_12 (bond, rollback_slave, iter) {
int V_394 ;
if ( V_23 == V_22 )
break;
V_394 = F_125 ( V_23 -> V_16 , & V_396 ) ;
if ( V_394 ) {
F_56 ( L_107 ,
V_394 , V_23 -> V_16 -> V_59 ) ;
}
}
return V_26 ;
}
static void F_266 ( struct V_10 * V_11 , struct V_12 * V_13 , int V_220 )
{
struct V_24 * V_25 ;
struct V_22 * V_22 ;
int V_167 = V_220 ;
F_162 (bond, slave, iter) {
if ( -- V_167 < 0 ) {
if ( F_267 ( V_22 ) ) {
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
return;
}
}
}
V_167 = V_220 ;
F_162 (bond, slave, iter) {
if ( -- V_167 < 0 )
break;
if ( F_267 ( V_22 ) ) {
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
return;
}
}
F_268 ( V_13 ) ;
}
static T_3 F_269 ( struct V_10 * V_11 )
{
T_3 V_220 ;
struct V_398 V_399 ;
int V_400 = V_11 -> V_52 . V_400 ;
switch ( V_400 ) {
case 0 :
V_220 = F_270 () ;
break;
case 1 :
V_220 = V_11 -> V_401 ;
break;
default:
V_399 =
V_11 -> V_52 . V_399 ;
V_220 = F_271 ( V_11 -> V_401 ,
V_399 ) ;
break;
}
V_11 -> V_401 ++ ;
return V_220 ;
}
static int F_272 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_308 * V_309 = F_229 ( V_13 ) ;
struct V_22 * V_22 ;
T_3 V_220 ;
if ( V_309 -> V_262 == V_402 && V_13 -> V_262 == F_198 ( V_269 ) ) {
V_22 = F_63 ( V_11 -> V_68 ) ;
if ( V_22 && F_267 ( V_22 ) )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_266 ( V_11 , V_13 , 0 ) ;
} else {
V_220 = F_269 ( V_11 ) ;
F_266 ( V_11 , V_13 , V_220 % V_11 -> V_205 ) ;
}
return V_403 ;
}
static int F_273 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 ;
V_22 = F_63 ( V_11 -> V_68 ) ;
if ( V_22 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_268 ( V_13 ) ;
return V_403 ;
}
static int F_274 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_266 ( V_11 , V_13 , F_234 ( V_11 , V_13 ) % V_11 -> V_205 ) ;
return V_403 ;
}
static int F_275 ( struct V_12 * V_13 , struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_22 * V_22 = NULL ;
struct V_24 * V_25 ;
F_162 (bond, slave, iter) {
if ( F_276 ( V_11 , V_22 ) )
break;
if ( F_60 ( V_22 ) && V_22 -> V_29 == V_30 ) {
struct V_12 * V_404 = F_277 ( V_13 , V_152 ) ;
if ( ! V_404 ) {
F_171 ( L_110 ,
V_19 -> V_59 , V_405 ) ;
continue;
}
F_2 ( V_11 , V_404 , V_22 -> V_16 ) ;
}
}
if ( V_22 && F_60 ( V_22 ) && V_22 -> V_29 == V_30 )
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
else
F_268 ( V_13 ) ;
return V_403 ;
}
static inline int F_278 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_22 * V_22 = NULL ;
struct V_24 * V_25 ;
if ( ! V_13 -> V_17 )
return 1 ;
F_162 (bond, slave, iter) {
if ( V_22 -> V_182 == V_13 -> V_17 ) {
if ( F_267 ( V_22 ) ) {
F_2 ( V_11 , V_13 , V_22 -> V_16 ) ;
return 0 ;
}
break;
}
}
return 1 ;
}
static T_2 F_279 ( struct V_14 * V_16 , struct V_12 * V_13 ,
void * V_406 , T_10 V_407 )
{
T_2 V_408 = F_280 ( V_13 ) ? F_281 ( V_13 ) : 0 ;
F_4 ( V_13 ) -> V_18 = V_13 -> V_17 ;
if ( F_5 ( V_408 >= V_16 -> V_409 ) ) {
do {
V_408 -= V_16 -> V_409 ;
} while ( V_408 >= V_16 -> V_409 );
}
return V_408 ;
}
static T_11 F_282 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
if ( F_283 ( V_11 ) &&
! F_278 ( V_11 , V_13 ) )
return V_403 ;
switch ( F_20 ( V_11 ) ) {
case V_3 :
return F_272 ( V_13 , V_16 ) ;
case V_4 :
return F_273 ( V_13 , V_16 ) ;
case V_5 :
return F_274 ( V_13 , V_16 ) ;
case V_6 :
return F_275 ( V_13 , V_16 ) ;
case V_7 :
return F_284 ( V_13 , V_16 ) ;
case V_9 :
return F_285 ( V_13 , V_16 ) ;
case V_8 :
return F_286 ( V_13 , V_16 ) ;
default:
F_118 ( L_111 ,
V_16 -> V_59 , F_20 ( V_11 ) ) ;
F_287 ( 1 ) ;
F_268 ( V_13 ) ;
return V_403 ;
}
}
static T_11 F_288 ( struct V_12 * V_13 , struct V_14 * V_16 )
{
struct V_10 * V_11 = F_11 ( V_16 ) ;
T_11 V_150 = V_403 ;
if ( F_5 ( F_289 ( V_16 ) ) )
return V_410 ;
F_62 () ;
if ( F_19 ( V_11 ) )
V_150 = F_282 ( V_13 , V_16 ) ;
else
F_268 ( V_13 ) ;
F_64 () ;
return V_150 ;
}
static int F_290 ( struct V_14 * V_19 ,
struct V_31 * V_32 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
unsigned long V_34 = 0 ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
V_32 -> V_36 = V_37 ;
V_32 -> V_411 = V_412 ;
F_240 ( & V_11 -> V_210 ) ;
F_12 (bond, slave, iter) {
if ( F_267 ( V_22 ) ) {
if ( V_22 -> V_34 != V_35 )
V_34 += V_22 -> V_34 ;
if ( V_32 -> V_36 == V_37 &&
V_22 -> V_36 != V_37 )
V_32 -> V_36 = V_22 -> V_36 ;
}
}
F_291 ( V_32 , V_34 ? : V_35 ) ;
F_241 ( & V_11 -> V_210 ) ;
return 0 ;
}
static void F_292 ( struct V_14 * V_19 ,
struct V_413 * V_414 )
{
F_293 ( V_414 -> V_415 , V_416 , sizeof( V_414 -> V_415 ) ) ;
F_293 ( V_414 -> V_417 , V_418 , sizeof( V_414 -> V_417 ) ) ;
snprintf ( V_414 -> V_419 , sizeof( V_414 -> V_419 ) , L_112 ,
V_420 ) ;
}
static void F_294 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
if ( V_11 -> V_72 )
F_295 ( V_11 -> V_72 ) ;
F_296 ( V_19 ) ;
}
void F_297 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
F_298 ( & V_11 -> V_210 ) ;
F_298 ( & V_11 -> V_110 ) ;
V_11 -> V_52 = V_421 ;
V_11 -> V_16 = V_19 ;
F_123 ( V_19 ) ;
V_19 -> V_47 = & V_422 ;
V_19 -> V_55 = & V_423 ;
V_19 -> V_424 = F_294 ;
F_299 ( V_19 , & V_425 ) ;
V_19 -> V_426 = 0 ;
V_19 -> V_81 |= V_300 | V_427 ;
V_19 -> V_142 |= V_191 | V_428 ;
V_19 -> V_142 &= ~ ( V_129 | V_174 ) ;
V_19 -> V_123 |= V_125 ;
V_19 -> V_123 |= V_429 ;
V_19 -> V_123 |= V_430 ;
V_19 -> V_431 = V_131 |
V_432 |
V_433 |
V_434 ;
V_19 -> V_431 &= ~ ( V_435 & ~ V_436 ) ;
V_19 -> V_431 |= V_437 ;
V_19 -> V_123 |= V_19 -> V_431 ;
}
static void F_300 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_24 * V_25 ;
struct V_22 * V_22 ;
F_84 ( V_19 ) ;
F_12 (bond, slave, iter)
F_148 ( V_19 , V_22 -> V_16 , true ) ;
F_67 ( L_113 , V_19 -> V_59 ) ;
F_301 ( & V_11 -> V_438 ) ;
F_302 ( V_11 ) ;
}
static int F_303 ( struct V_439 * V_52 )
{
int V_440 , V_441 , V_442 , V_167 ;
struct V_362 V_363 ;
const struct V_362 * V_443 ;
int V_444 ;
if ( V_1 ) {
F_255 ( & V_363 , V_1 ) ;
V_443 = F_304 ( F_305 ( V_445 ) , & V_363 ) ;
if ( ! V_443 ) {
F_118 ( L_114 , V_1 ) ;
return - V_176 ;
}
V_216 = V_443 -> V_446 ;
}
if ( V_447 ) {
if ( ( V_216 != V_5 ) &&
( V_216 != V_7 ) &&
( V_216 != V_8 ) ) {
F_67 ( L_115 ,
F_1 ( V_216 ) ) ;
} else {
F_255 ( & V_363 , V_447 ) ;
V_443 = F_304 ( F_305 ( V_448 ) ,
& V_363 ) ;
if ( ! V_443 ) {
F_118 ( L_116 ,
V_447 ) ;
return - V_176 ;
}
V_449 = V_443 -> V_446 ;
}
}
if ( V_450 ) {
if ( V_216 != V_7 ) {
F_67 ( L_117 ,
F_1 ( V_216 ) ) ;
} else {
F_255 ( & V_363 , V_450 ) ;
V_443 = F_304 ( F_305 ( V_451 ) ,
& V_363 ) ;
if ( ! V_443 ) {
F_118 ( L_118 ,
V_450 ) ;
return - V_176 ;
}
V_452 = V_443 -> V_446 ;
}
}
if ( V_453 ) {
F_255 ( & V_363 , V_453 ) ;
V_443 = F_304 ( F_305 ( V_454 ) ,
& V_363 ) ;
if ( ! V_443 ) {
F_118 ( L_119 , V_453 ) ;
return - V_176 ;
}
V_52 -> V_453 = V_443 -> V_446 ;
if ( V_216 != V_7 )
F_117 ( L_120 ) ;
} else {
V_52 -> V_453 = V_455 ;
}
if ( V_456 < 0 ) {
F_117 ( L_121 ,
V_456 , 0 , V_457 , V_458 ) ;
V_456 = V_458 ;
}
if ( V_105 < 0 ) {
F_117 ( L_122 ,
V_105 , V_457 ) ;
V_105 = 0 ;
}
if ( V_98 < 0 ) {
F_117 ( L_123 ,
V_98 , V_457 ) ;
V_98 = 0 ;
}
if ( V_227 < 0 ) {
F_117 ( L_124 ,
V_227 , V_457 ) ;
V_227 = 0 ;
}
if ( ( V_53 != 0 ) && ( V_53 != 1 ) ) {
F_117 ( L_125 ,
V_53 ) ;
V_53 = 1 ;
}
if ( V_109 < 0 || V_109 > 255 ) {
F_117 ( L_126 ,
V_109 ) ;
V_109 = 1 ;
}
if ( ! F_306 ( V_216 ) ) {
if ( ! V_105 ) {
F_117 ( L_127 ) ;
F_117 ( L_128 ) ;
V_105 = V_459 ;
}
}
if ( V_460 < 1 || V_460 > 255 ) {
F_117 ( L_129 ,
V_460 , V_461 ) ;
V_460 = V_461 ;
}
if ( ( V_462 != 0 ) && ( V_462 != 1 ) ) {
F_117 ( L_130 ,
V_462 ) ;
V_462 = 0 ;
}
if ( V_113 < 0 || V_113 > 255 ) {
F_117 ( L_131 ,
V_113 , V_463 ) ;
V_113 = V_463 ;
}
F_307 ( & V_363 , V_400 ) ;
if ( ! F_304 ( F_305 ( V_464 ) , & V_363 ) ) {
F_117 ( L_132 ,
V_400 , V_465 ) ;
V_400 = 1 ;
}
if ( V_216 == V_9 ) {
F_308 ( L_133 ,
V_98 ) ;
}
if ( ! V_105 ) {
if ( V_98 || V_227 ) {
F_117 ( L_134 ,
V_98 , V_227 ) ;
}
} else {
if ( V_195 ) {
F_117 ( L_135 ,
V_105 , V_195 ) ;
V_195 = 0 ;
}
if ( ( V_98 % V_105 ) != 0 ) {
F_117 ( L_136 ,
V_98 , V_105 , ( V_98 / V_105 ) * V_105 ) ;
}
V_98 /= V_105 ;
if ( ( V_227 % V_105 ) != 0 ) {
F_117 ( L_137 ,
V_227 , V_105 ,
( V_227 / V_105 ) * V_105 ) ;
}
V_227 /= V_105 ;
}
if ( V_195 < 0 ) {
F_117 ( L_138 ,
V_195 , V_457 ) ;
V_195 = 0 ;
}
for ( V_466 = 0 , V_167 = 0 ;
( V_466 < V_196 ) && V_467 [ V_167 ] ; V_167 ++ ) {
T_8 V_232 ;
if ( ! F_309 ( V_467 [ V_167 ] , - 1 , ( T_5 * ) & V_232 , - 1 , NULL ) ||
! F_310 ( V_232 ) ) {
F_117 ( L_139 ,
V_467 [ V_167 ] ) ;
V_195 = 0 ;
} else {
if ( F_189 ( V_468 , V_232 ) == - 1 )
V_468 [ V_466 ++ ] = V_232 ;
else
F_117 ( L_140 ,
& V_232 ) ;
}
}
if ( V_195 && ! V_466 ) {
F_117 ( L_141 ,
V_195 ) ;
V_195 = 0 ;
}
if ( V_251 ) {
if ( ! V_195 ) {
F_118 ( L_142 ) ;
return - V_176 ;
}
F_255 ( & V_363 , V_251 ) ;
V_443 = F_304 ( F_305 ( V_469 ) ,
& V_363 ) ;
if ( ! V_443 ) {
F_118 ( L_143 ,
V_251 ) ;
return - V_176 ;
}
V_440 = V_443 -> V_446 ;
} else {
V_440 = 0 ;
}
V_444 = 0 ;
if ( V_470 ) {
F_255 ( & V_363 , V_470 ) ;
V_443 = F_304 ( F_305 ( V_471 ) ,
& V_363 ) ;
if ( ! V_443 ) {
F_118 ( L_144 ,
V_470 ) ;
V_444 = 0 ;
} else {
V_444 = V_443 -> V_446 ;
}
}
if ( V_105 ) {
F_67 ( L_145 , V_105 ) ;
} else if ( V_195 ) {
V_443 = F_311 ( V_469 ,
V_440 ) ;
F_67 ( L_146 ,
V_195 , V_443 -> string , V_466 ) ;
for ( V_167 = 0 ; V_167 < V_466 ; V_167 ++ )
F_312 ( L_147 , V_467 [ V_167 ] ) ;
F_312 ( L_148 ) ;
} else if ( V_456 ) {
F_56 ( L_149 ) ;
}
if ( V_198 && ! F_313 ( V_216 ) ) {
F_117 ( L_150 ,
V_198 , F_1 ( V_216 ) ) ;
V_198 = NULL ;
}
if ( V_198 && V_93 ) {
F_255 ( & V_363 , V_93 ) ;
V_443 = F_304 ( F_305 ( V_472 ) ,
& V_363 ) ;
if ( ! V_443 ) {
F_118 ( L_151 ,
V_93 ) ;
return - V_176 ;
}
V_442 = V_443 -> V_446 ;
} else {
V_442 = V_473 ;
}
if ( V_108 ) {
F_255 ( & V_363 , V_108 ) ;
V_443 = F_304 ( F_305 ( V_474 ) ,
& V_363 ) ;
if ( ! V_443 ) {
F_118 ( L_152 ,
V_108 ) ;
return - V_176 ;
}
V_441 = V_443 -> V_446 ;
if ( V_216 != V_4 )
F_117 ( L_153 ) ;
} else {
V_441 = V_475 ;
}
if ( V_476 == 0 ) {
F_117 ( L_154 ,
V_457 , V_477 ) ;
V_476 = V_477 ;
}
V_52 -> V_1 = V_216 ;
V_52 -> V_311 = V_449 ;
V_52 -> V_105 = V_105 ;
V_52 -> V_109 = V_109 ;
V_52 -> V_195 = V_195 ;
V_52 -> V_251 = V_440 ;
V_52 -> V_470 = V_444 ;
V_52 -> V_98 = V_98 ;
V_52 -> V_227 = V_227 ;
V_52 -> V_53 = V_53 ;
V_52 -> V_452 = V_452 ;
V_52 -> V_198 [ 0 ] = 0 ;
V_52 -> V_93 = V_442 ;
V_52 -> V_108 = V_441 ;
V_52 -> V_460 = V_460 ;
V_52 -> V_462 = V_462 ;
V_52 -> V_113 = V_113 ;
V_52 -> V_478 = V_478 ;
V_52 -> V_476 = V_476 ;
V_52 -> V_400 = V_400 ;
V_52 -> V_330 = 1 ;
if ( V_400 > 0 ) {
V_52 -> V_399 =
V_398 ( V_400 ) ;
} else {
V_52 -> V_399 =
(struct V_398 ) { 0 } ;
}
if ( V_198 ) {
strncpy ( V_52 -> V_198 , V_198 , V_60 ) ;
V_52 -> V_198 [ V_60 - 1 ] = 0 ;
}
memcpy ( V_52 -> V_249 , V_468 , sizeof( V_468 ) ) ;
return 0 ;
}
static void F_314 ( struct V_14 * V_16 ,
struct V_479 * V_408 ,
void * V_480 )
{
F_315 ( & V_408 -> V_481 ,
& V_482 ) ;
}
static void F_316 ( struct V_14 * V_16 )
{
F_315 ( & V_16 -> V_483 ,
& V_484 ) ;
F_317 ( V_16 , F_314 , NULL ) ;
V_16 -> V_485 = & V_486 ;
}
static int F_318 ( struct V_14 * V_19 )
{
struct V_10 * V_11 = F_11 ( V_19 ) ;
struct V_487 * V_488 = F_319 ( F_184 ( V_19 ) , V_489 ) ;
struct V_490 * V_491 = & ( F_320 ( V_11 ) ) ;
F_56 ( L_155 , V_19 -> V_59 ) ;
F_321 ( & ( V_491 -> V_492 ) ) ;
F_321 ( & ( V_491 -> V_493 ) ) ;
V_11 -> V_72 = F_322 ( V_19 -> V_59 ) ;
if ( ! V_11 -> V_72 )
return - V_119 ;
F_316 ( V_19 ) ;
F_323 ( & V_11 -> V_438 , & V_488 -> V_494 ) ;
F_324 ( V_11 ) ;
F_325 ( V_11 ) ;
if ( F_326 ( V_19 -> V_85 ) &&
V_19 -> V_86 == V_495 )
F_147 ( V_19 ) ;
return 0 ;
}
unsigned int F_327 ( void )
{
return V_460 ;
}
int F_328 ( struct V_364 * V_364 , const char * V_59 )
{
struct V_14 * V_19 ;
int V_26 ;
F_329 () ;
V_19 = F_330 ( sizeof( struct V_10 ) ,
V_59 ? V_59 : L_156 ,
F_297 , V_460 ) ;
if ( ! V_19 ) {
F_118 ( L_157 , V_59 ) ;
F_44 () ;
return - V_119 ;
}
F_331 ( V_19 , V_364 ) ;
V_19 -> V_496 = & V_497 ;
V_26 = F_332 ( V_19 ) ;
F_24 ( V_19 ) ;
F_44 () ;
if ( V_26 < 0 )
F_294 ( V_19 ) ;
return V_26 ;
}
static int T_12 F_333 ( struct V_364 * V_364 )
{
struct V_487 * V_488 = F_319 ( V_364 , V_489 ) ;
V_488 -> V_364 = V_364 ;
F_334 ( & V_488 -> V_494 ) ;
F_335 ( V_488 ) ;
F_336 ( V_488 ) ;
return 0 ;
}
static void T_13 F_337 ( struct V_364 * V_364 )
{
struct V_487 * V_488 = F_319 ( V_364 , V_489 ) ;
struct V_10 * V_11 , * V_498 ;
F_338 ( V_499 ) ;
F_339 ( V_488 ) ;
F_340 ( V_488 ) ;
F_329 () ;
F_341 (bond, tmp_bond, &bn->dev_list, bond_list)
F_342 ( V_11 -> V_16 , & V_499 ) ;
F_343 ( & V_499 ) ;
F_44 () ;
}
static int T_14 F_344 ( void )
{
int V_167 ;
int V_26 ;
F_67 ( L_158 , V_500 ) ;
V_26 = F_303 ( & V_421 ) ;
if ( V_26 )
goto V_120;
V_26 = F_345 ( & V_501 ) ;
if ( V_26 )
goto V_120;
V_26 = F_346 () ;
if ( V_26 )
goto V_502;
F_347 () ;
for ( V_167 = 0 ; V_167 < V_456 ; V_167 ++ ) {
V_26 = F_328 ( & V_503 , NULL ) ;
if ( V_26 )
goto V_67;
}
F_348 ( & V_504 ) ;
V_120:
return V_26 ;
V_67:
F_349 () ;
F_350 () ;
V_502:
F_351 ( & V_501 ) ;
goto V_120;
}
static void T_15 F_352 ( void )
{
F_353 ( & V_504 ) ;
F_349 () ;
F_350 () ;
F_351 ( & V_501 ) ;
#ifdef F_137
F_354 ( F_355 ( & V_505 ) ) ;
#endif
}
