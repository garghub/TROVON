static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 ) ;
}
static bool F_3 ( struct V_2 * V_3 )
{
return ! ! V_3 -> V_5 ;
}
static const char * F_4 ( int V_6 )
{
switch ( V_6 ) {
case V_7 : return L_1 ;
case V_8 : return L_2 ;
case V_9 : return L_3 ;
case V_10 : return L_4 ;
case V_11 : return L_5 ;
}
return L_6 ;
}
static int F_5 ( struct V_2 * V_3 , struct V_12 * V_13 )
{
V_13 -> V_14 -> V_15 = 0 ;
F_6 ( V_3 -> V_4 , 0 ) ;
F_7 ( & F_1 ( V_3 ) -> V_16 , V_17 ) ;
return 0 ;
}
static void F_8 ( struct V_2 * V_3 , struct V_12 * V_13 )
{
if ( ! F_3 ( V_3 ) )
return;
V_13 -> V_14 -> V_15 = V_3 -> V_18 ;
F_6 ( V_3 -> V_4 , V_3 -> V_18 >> 9 ) ;
F_7 ( & F_1 ( V_3 ) -> V_16 , V_17 ) ;
}
static int F_9 ( struct V_2 * V_3 , struct V_12 * V_13 ,
int V_19 , int V_20 )
{
int V_21 ;
V_21 = F_10 ( V_13 , V_19 ) ;
if ( V_21 )
return V_21 ;
V_3 -> V_22 = V_19 ;
V_3 -> V_18 = ( V_23 ) V_19 * ( V_23 ) V_20 ;
F_8 ( V_3 , V_13 ) ;
return 0 ;
}
static void F_11 ( struct V_24 * V_6 )
{
struct V_2 * V_3 = V_6 -> V_3 ;
struct V_25 * V_26 = F_12 ( V_6 ) ;
int error = V_26 -> V_27 ? - V_28 : 0 ;
F_13 ( F_1 ( V_3 ) , L_7 , V_6 ,
error ? L_8 : L_9 ) ;
F_14 ( V_26 , error ) ;
}
static void F_15 ( struct V_2 * V_3 )
{
struct V_29 * V_30 ;
F_16 ( & V_3 -> V_31 ) ;
if ( ! V_3 -> V_30 ) {
F_17 ( & V_3 -> V_31 ) ;
return;
}
V_30 = V_3 -> V_30 ;
F_18 ( F_2 ( V_3 -> V_4 ) , L_10 ) ;
V_3 -> V_30 = NULL ;
F_17 ( & V_3 -> V_31 ) ;
F_19 ( V_30 , V_32 ) ;
F_20 ( V_30 ) ;
}
static enum V_33 F_21 ( struct V_25 * V_26 ,
bool V_34 )
{
struct V_24 * V_6 = F_22 ( V_26 ) ;
struct V_2 * V_3 = V_6 -> V_3 ;
struct V_29 * V_30 = NULL ;
F_16 ( & V_3 -> V_31 ) ;
F_23 ( V_35 , & V_3 -> V_36 ) ;
if ( V_3 -> V_30 ) {
V_30 = V_3 -> V_30 ;
F_24 ( V_30 -> V_37 ) ;
}
F_17 ( & V_3 -> V_31 ) ;
if ( V_30 ) {
F_19 ( V_30 , V_32 ) ;
F_20 ( V_30 ) ;
}
V_26 -> V_27 ++ ;
F_25 ( F_1 ( V_3 ) , L_11 ) ;
return V_38 ;
}
static int F_26 ( struct V_2 * V_3 , int V_39 , void * V_40 , int V_41 ,
int V_42 )
{
struct V_29 * V_30 = V_3 -> V_30 ;
int V_43 ;
struct V_44 V_45 ;
struct V_46 V_47 ;
unsigned long V_48 = V_49 -> V_50 ;
if ( F_27 ( ! V_30 ) ) {
F_25 ( F_2 ( V_3 -> V_4 ) ,
L_12 ,
( V_39 ? L_13 : L_14 ) ) ;
return - V_51 ;
}
V_49 -> V_50 |= V_52 ;
do {
V_30 -> V_53 -> V_54 = V_55 | V_56 ;
V_47 . V_57 = V_40 ;
V_47 . V_58 = V_41 ;
V_45 . V_59 = NULL ;
V_45 . V_60 = 0 ;
V_45 . V_61 = NULL ;
V_45 . V_62 = 0 ;
V_45 . V_42 = V_42 | V_63 ;
if ( V_39 )
V_43 = F_28 ( V_30 , & V_45 , & V_47 , 1 , V_41 ) ;
else
V_43 = F_29 ( V_30 , & V_45 , & V_47 , 1 , V_41 ,
V_45 . V_42 ) ;
if ( V_43 <= 0 ) {
if ( V_43 == 0 )
V_43 = - V_64 ;
break;
}
V_41 -= V_43 ;
V_40 += V_43 ;
} while ( V_41 > 0 );
F_30 ( V_49 , V_48 , V_52 ) ;
return V_43 ;
}
static inline int F_31 ( struct V_2 * V_3 , struct V_65 * V_66 ,
int V_50 )
{
int V_43 ;
void * V_67 = F_32 ( V_66 -> V_68 ) ;
V_43 = F_26 ( V_3 , 1 , V_67 + V_66 -> V_69 ,
V_66 -> V_70 , V_50 ) ;
F_33 ( V_66 -> V_68 ) ;
return V_43 ;
}
static int F_34 ( struct V_2 * V_3 , struct V_24 * V_6 )
{
struct V_25 * V_26 = F_12 ( V_6 ) ;
int V_43 , V_50 ;
struct V_71 V_25 ;
unsigned long V_41 = F_35 ( V_26 ) ;
T_1 type ;
if ( V_26 -> V_72 == V_73 )
type = V_9 ;
else if ( F_36 ( V_26 ) == V_74 )
type = V_11 ;
else if ( F_36 ( V_26 ) == V_75 )
type = V_10 ;
else if ( F_37 ( V_26 ) == V_76 )
type = V_8 ;
else
type = V_7 ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
V_25 . V_77 = F_38 ( V_78 ) ;
V_25 . type = F_38 ( type ) ;
if ( type != V_10 && type != V_9 ) {
V_25 . V_79 = F_39 ( ( V_80 ) F_40 ( V_26 ) << 9 ) ;
V_25 . V_81 = F_38 ( V_41 ) ;
}
memcpy ( V_25 . V_82 , & V_26 -> V_83 , sizeof( V_26 -> V_83 ) ) ;
F_13 ( F_1 ( V_3 ) , L_15 ,
V_6 , F_4 ( type ) ,
( unsigned long long ) F_40 ( V_26 ) << 9 , F_35 ( V_26 ) ) ;
V_43 = F_26 ( V_3 , 1 , & V_25 , sizeof( V_25 ) ,
( type == V_8 ) ? V_84 : 0 ) ;
if ( V_43 <= 0 ) {
F_25 ( F_2 ( V_3 -> V_4 ) ,
L_16 , V_43 ) ;
return - V_28 ;
}
if ( type == V_8 ) {
struct V_85 V_86 ;
struct V_65 V_66 ;
F_41 (bvec, req, iter) {
V_50 = 0 ;
if ( ! F_42 ( V_66 , V_86 ) )
V_50 = V_84 ;
F_13 ( F_1 ( V_3 ) , L_17 ,
V_6 , V_66 . V_70 ) ;
V_43 = F_31 ( V_3 , & V_66 , V_50 ) ;
if ( V_43 <= 0 ) {
F_25 ( F_2 ( V_3 -> V_4 ) ,
L_18 ,
V_43 ) ;
return - V_28 ;
}
}
}
return 0 ;
}
static inline int F_43 ( struct V_2 * V_3 , struct V_65 * V_66 )
{
int V_43 ;
void * V_67 = F_32 ( V_66 -> V_68 ) ;
V_43 = F_26 ( V_3 , 0 , V_67 + V_66 -> V_69 , V_66 -> V_70 ,
V_87 ) ;
F_33 ( V_66 -> V_68 ) ;
return V_43 ;
}
static struct V_24 * F_44 ( struct V_2 * V_3 )
{
int V_43 ;
struct V_88 V_89 ;
struct V_24 * V_6 ;
struct V_25 * V_26 = NULL ;
T_2 V_90 ;
int V_83 ;
V_89 . V_77 = 0 ;
V_43 = F_26 ( V_3 , 0 , & V_89 , sizeof( V_89 ) , V_87 ) ;
if ( V_43 <= 0 ) {
F_25 ( F_2 ( V_3 -> V_4 ) ,
L_19 , V_43 ) ;
return F_45 ( V_43 ) ;
}
if ( F_46 ( V_89 . V_77 ) != V_91 ) {
F_25 ( F_2 ( V_3 -> V_4 ) , L_20 ,
( unsigned long ) F_46 ( V_89 . V_77 ) ) ;
return F_45 ( - V_92 ) ;
}
memcpy ( & V_83 , V_89 . V_82 , sizeof( int ) ) ;
V_90 = F_47 ( V_83 ) ;
if ( V_90 < V_3 -> V_93 . V_94 )
V_26 = F_48 ( V_3 -> V_93 . V_95 [ V_90 ] ,
F_49 ( V_83 ) ) ;
if ( ! V_26 || ! F_50 ( V_26 ) ) {
F_25 ( F_2 ( V_3 -> V_4 ) , L_21 ,
V_83 , V_26 ) ;
return F_45 ( - V_96 ) ;
}
V_6 = F_22 ( V_26 ) ;
if ( F_46 ( V_89 . error ) ) {
F_25 ( F_2 ( V_3 -> V_4 ) , L_22 ,
F_46 ( V_89 . error ) ) ;
V_26 -> V_27 ++ ;
return V_6 ;
}
F_13 ( F_1 ( V_3 ) , L_23 , V_6 ) ;
if ( F_37 ( V_26 ) != V_76 ) {
struct V_85 V_86 ;
struct V_65 V_66 ;
F_41 (bvec, req, iter) {
V_43 = F_43 ( V_3 , & V_66 ) ;
if ( V_43 <= 0 ) {
F_25 ( F_2 ( V_3 -> V_4 ) , L_24 ,
V_43 ) ;
V_26 -> V_27 ++ ;
return V_6 ;
}
F_13 ( F_1 ( V_3 ) , L_25 ,
V_6 , V_66 . V_70 ) ;
}
}
return V_6 ;
}
static T_3 F_51 ( struct V_1 * V_97 ,
struct V_98 * V_99 , char * V_40 )
{
struct V_100 * V_4 = F_52 ( V_97 ) ;
struct V_2 * V_3 = (struct V_2 * ) V_4 -> V_101 ;
return sprintf ( V_40 , L_26 , F_53 ( V_3 -> V_5 ) ) ;
}
static int F_54 ( struct V_2 * V_3 , struct V_12 * V_13 )
{
struct V_24 * V_6 ;
int V_21 ;
F_55 ( V_3 -> V_77 != V_102 ) ;
F_56 ( V_3 -> V_30 -> V_53 ) ;
V_21 = F_57 ( F_2 ( V_3 -> V_4 ) , & V_103 ) ;
if ( V_21 ) {
F_25 ( F_2 ( V_3 -> V_4 ) , L_27 ) ;
return V_21 ;
}
F_8 ( V_3 , V_13 ) ;
while ( 1 ) {
V_6 = F_44 ( V_3 ) ;
if ( F_58 ( V_6 ) ) {
V_21 = F_59 ( V_6 ) ;
break;
}
F_11 ( V_6 ) ;
}
F_5 ( V_3 , V_13 ) ;
F_60 ( F_2 ( V_3 -> V_4 ) , & V_103 ) ;
return V_21 ;
}
static void F_61 ( struct V_25 * V_26 , void * V_104 , bool V_34 )
{
struct V_24 * V_6 ;
if ( ! F_50 ( V_26 ) )
return;
V_6 = F_22 ( V_26 ) ;
V_26 -> V_27 ++ ;
F_11 ( V_6 ) ;
}
static void F_62 ( struct V_2 * V_3 )
{
F_55 ( V_3 -> V_77 != V_102 ) ;
F_55 ( V_3 -> V_30 ) ;
F_63 ( & V_3 -> V_93 , F_61 , NULL ) ;
F_13 ( F_2 ( V_3 -> V_4 ) , L_28 ) ;
}
static void F_64 ( struct V_24 * V_6 )
{
struct V_25 * V_26 = F_12 ( V_6 ) ;
struct V_2 * V_3 = V_6 -> V_3 ;
if ( V_26 -> V_72 != V_105 )
goto V_106;
if ( F_37 ( V_26 ) == V_76 &&
( V_3 -> V_50 & V_107 ) ) {
F_25 ( F_2 ( V_3 -> V_4 ) ,
L_29 ) ;
goto V_106;
}
V_26 -> V_27 = 0 ;
F_65 ( & V_3 -> V_108 ) ;
V_3 -> V_109 = V_49 ;
if ( F_27 ( ! V_3 -> V_30 ) ) {
F_66 ( & V_3 -> V_108 ) ;
F_25 ( F_2 ( V_3 -> V_4 ) ,
L_30 ) ;
goto V_106;
}
if ( F_34 ( V_3 , V_6 ) != 0 ) {
F_25 ( F_2 ( V_3 -> V_4 ) , L_31 ) ;
V_26 -> V_27 ++ ;
F_11 ( V_6 ) ;
}
V_3 -> V_109 = NULL ;
F_66 ( & V_3 -> V_108 ) ;
return;
V_106:
V_26 -> V_27 ++ ;
F_11 ( V_6 ) ;
}
static int F_67 ( struct V_110 * V_111 ,
const struct V_112 * V_113 )
{
struct V_24 * V_6 = F_22 ( V_113 -> V_114 ) ;
F_68 ( V_113 -> V_114 ) ;
F_64 ( V_6 ) ;
return V_115 ;
}
static int F_69 ( struct V_2 * V_3 , struct V_29 * V_30 )
{
int V_21 = 0 ;
F_70 ( & V_3 -> V_31 ) ;
if ( V_3 -> V_30 ) {
V_21 = - V_116 ;
goto V_117;
}
V_3 -> V_30 = V_30 ;
V_117:
F_71 ( & V_3 -> V_31 ) ;
return V_21 ;
}
static void F_72 ( struct V_2 * V_3 )
{
V_3 -> V_36 = 0 ;
V_3 -> V_22 = 1024 ;
V_3 -> V_18 = 0 ;
F_6 ( V_3 -> V_4 , 0 ) ;
V_3 -> V_50 = 0 ;
V_3 -> V_93 . V_118 = 0 ;
F_73 ( V_119 , V_3 -> V_4 -> V_120 ) ;
}
static void F_74 ( struct V_12 * V_13 )
{
F_75 ( V_13 , false ) ;
V_13 -> V_14 -> V_15 = 0 ;
if ( V_121 > 0 ) {
F_76 ( V_13 ) ;
V_13 -> V_122 = 1 ;
}
}
static void F_77 ( struct V_2 * V_3 , struct V_12 * V_13 )
{
if ( V_3 -> V_50 & V_107 )
F_75 ( V_13 , true ) ;
if ( V_3 -> V_50 & V_123 )
F_78 ( V_119 , V_3 -> V_4 -> V_120 ) ;
if ( V_3 -> V_50 & V_124 )
F_79 ( V_3 -> V_4 -> V_120 , true , false ) ;
else
F_79 ( V_3 -> V_4 -> V_120 , false , false ) ;
}
static int F_80 ( struct V_12 * V_13 , struct V_2 * V_3 ,
unsigned int V_6 , unsigned long V_125 )
{
switch ( V_6 ) {
case V_126 : {
struct V_25 * V_127 ;
F_81 ( F_2 ( V_3 -> V_4 ) , L_32 ) ;
if ( ! V_3 -> V_30 )
return - V_51 ;
V_127 = F_82 ( F_83 ( V_13 ) , V_76 , 0 ) ;
if ( F_58 ( V_127 ) )
return - V_128 ;
F_66 ( & V_3 -> V_108 ) ;
F_84 ( V_13 ) ;
F_65 ( & V_3 -> V_108 ) ;
V_127 -> V_72 = V_73 ;
if ( ! V_3 -> V_30 ) {
F_85 ( V_127 ) ;
return - V_51 ;
}
F_23 ( V_129 , & V_3 -> V_36 ) ;
F_34 ( V_3 , F_22 ( V_127 ) ) ;
F_85 ( V_127 ) ;
return 0 ;
}
case V_130 :
F_15 ( V_3 ) ;
F_62 ( V_3 ) ;
F_86 ( V_13 ) ;
return 0 ;
case V_131 : {
int V_132 ;
struct V_29 * V_30 = F_87 ( V_125 , & V_132 ) ;
if ( ! V_30 )
return V_132 ;
V_132 = F_69 ( V_3 , V_30 ) ;
if ( ! V_132 && V_121 )
V_13 -> V_122 = 1 ;
return V_132 ;
}
case V_133 : {
V_23 V_134 = F_88 ( V_3 -> V_18 , V_125 ) ;
return F_9 ( V_3 , V_13 , V_125 , V_134 ) ;
}
case V_135 :
return F_9 ( V_3 , V_13 , V_3 -> V_22 ,
V_125 / V_3 -> V_22 ) ;
case V_136 :
return F_9 ( V_3 , V_13 , V_3 -> V_22 , V_125 ) ;
case V_137 :
V_3 -> V_93 . V_118 = V_125 * V_138 ;
return 0 ;
case V_139 :
V_3 -> V_50 = V_125 ;
return 0 ;
case V_140 : {
int error ;
if ( V_3 -> V_5 )
return - V_116 ;
if ( ! V_3 -> V_30 )
return - V_51 ;
V_3 -> V_5 = V_49 ;
F_66 ( & V_3 -> V_108 ) ;
F_77 ( V_3 , V_13 ) ;
F_89 ( V_3 ) ;
error = F_54 ( V_3 , V_13 ) ;
F_90 ( V_3 ) ;
F_65 ( & V_3 -> V_108 ) ;
V_3 -> V_5 = NULL ;
F_15 ( V_3 ) ;
F_62 ( V_3 ) ;
F_86 ( V_13 ) ;
F_74 ( V_13 ) ;
if ( F_91 ( V_129 , & V_3 -> V_36 ) )
error = 0 ;
if ( F_91 ( V_35 , & V_3 -> V_36 ) )
error = - V_141 ;
F_72 ( V_3 ) ;
return error ;
}
case V_142 :
return 0 ;
case V_143 :
return 0 ;
}
return - V_144 ;
}
static int F_92 ( struct V_12 * V_13 , T_4 V_145 ,
unsigned int V_6 , unsigned long V_125 )
{
struct V_2 * V_3 = V_13 -> V_146 -> V_101 ;
int error ;
if ( ! F_93 ( V_147 ) )
return - V_148 ;
F_55 ( V_3 -> V_77 != V_102 ) ;
F_65 ( & V_3 -> V_108 ) ;
error = F_80 ( V_13 , V_3 , V_6 , V_125 ) ;
F_66 ( & V_3 -> V_108 ) ;
return error ;
}
static int F_94 ( struct V_149 * V_150 , void * V_151 )
{
struct V_2 * V_3 = V_150 -> V_152 ;
if ( V_3 -> V_5 )
F_95 ( V_150 , L_33 , F_53 ( V_3 -> V_5 ) ) ;
if ( V_3 -> V_109 )
F_95 ( V_150 , L_34 , F_53 ( V_3 -> V_109 ) ) ;
return 0 ;
}
static int F_96 ( struct V_153 * V_153 , struct V_37 * V_37 )
{
return F_97 ( V_37 , F_94 , V_153 -> V_154 ) ;
}
static int F_98 ( struct V_149 * V_150 , void * V_151 )
{
struct V_2 * V_3 = V_150 -> V_152 ;
T_1 V_50 = V_3 -> V_50 ;
F_95 ( V_150 , L_35 , V_50 ) ;
F_99 ( V_150 , L_36 ) ;
if ( V_50 & V_155 )
F_99 ( V_150 , L_37 ) ;
if ( V_50 & V_107 )
F_99 ( V_150 , L_38 ) ;
if ( V_50 & V_124 )
F_99 ( V_150 , L_39 ) ;
if ( V_50 & V_123 )
F_99 ( V_150 , L_40 ) ;
return 0 ;
}
static int F_100 ( struct V_153 * V_153 , struct V_37 * V_37 )
{
return F_97 ( V_37 , F_98 , V_153 -> V_154 ) ;
}
static int F_89 ( struct V_2 * V_3 )
{
struct V_156 * V_157 ;
if ( ! V_158 )
return - V_28 ;
V_157 = F_101 ( F_102 ( V_3 ) , V_158 ) ;
if ( ! V_157 ) {
F_25 ( F_1 ( V_3 ) , L_41 ,
F_102 ( V_3 ) ) ;
return - V_28 ;
}
V_3 -> V_159 = V_157 ;
F_103 ( L_42 , 0444 , V_157 , V_3 , & V_160 ) ;
F_104 ( L_43 , 0444 , V_157 , & V_3 -> V_18 ) ;
F_105 ( L_44 , 0444 , V_157 , & V_3 -> V_93 . V_118 ) ;
F_105 ( L_45 , 0444 , V_157 , & V_3 -> V_22 ) ;
F_103 ( L_46 , 0444 , V_157 , V_3 , & V_161 ) ;
return 0 ;
}
static void F_90 ( struct V_2 * V_3 )
{
F_106 ( V_3 -> V_159 ) ;
}
static int F_107 ( void )
{
struct V_156 * V_159 ;
V_159 = F_101 ( L_47 , NULL ) ;
if ( ! V_159 )
return - V_28 ;
V_158 = V_159 ;
return 0 ;
}
static void F_108 ( void )
{
F_106 ( V_158 ) ;
}
static int F_89 ( struct V_2 * V_3 )
{
return 0 ;
}
static void F_90 ( struct V_2 * V_3 )
{
}
static int F_107 ( void )
{
return 0 ;
}
static void F_108 ( void )
{
}
static int F_109 ( void * V_104 , struct V_25 * V_114 ,
unsigned int V_162 , unsigned int V_163 ,
unsigned int V_164 )
{
struct V_24 * V_6 = F_22 ( V_114 ) ;
V_6 -> V_3 = V_104 ;
F_110 ( & V_6 -> V_165 ) ;
return 0 ;
}
static int T_5 F_111 ( void )
{
int V_132 = - V_128 ;
int V_166 ;
int V_167 ;
F_112 ( sizeof( struct V_71 ) != 28 ) ;
if ( V_121 < 0 ) {
F_113 ( V_168 L_48 ) ;
return - V_51 ;
}
V_167 = 0 ;
if ( V_121 > 0 ) {
V_167 = F_114 ( V_121 ) ;
V_121 = ( 1UL << V_167 ) - 1 ;
}
if ( ( 1UL << V_167 ) > V_169 )
return - V_51 ;
if ( V_170 > 1UL << ( V_171 - V_167 ) )
return - V_51 ;
V_172 = F_115 ( V_170 , sizeof( * V_172 ) , V_173 ) ;
if ( ! V_172 )
return - V_128 ;
for ( V_166 = 0 ; V_166 < V_170 ; V_166 ++ ) {
struct V_100 * V_4 = F_116 ( 1 << V_167 ) ;
if ( ! V_4 )
goto V_117;
V_172 [ V_166 ] . V_4 = V_4 ;
V_172 [ V_166 ] . V_93 . V_174 = & V_175 ;
V_172 [ V_166 ] . V_93 . V_94 = 1 ;
V_172 [ V_166 ] . V_93 . V_176 = 128 ;
V_172 [ V_166 ] . V_93 . V_164 = V_177 ;
V_172 [ V_166 ] . V_93 . V_178 = sizeof( struct V_24 ) ;
V_172 [ V_166 ] . V_93 . V_50 = V_179 |
V_180 | V_181 ;
V_172 [ V_166 ] . V_93 . V_182 = & V_172 [ V_166 ] ;
V_132 = F_117 ( & V_172 [ V_166 ] . V_93 ) ;
if ( V_132 ) {
F_118 ( V_4 ) ;
goto V_117;
}
V_4 -> V_120 = F_119 ( & V_172 [ V_166 ] . V_93 ) ;
if ( ! V_4 -> V_120 ) {
F_120 ( & V_172 [ V_166 ] . V_93 ) ;
F_118 ( V_4 ) ;
goto V_117;
}
F_78 ( V_183 , V_4 -> V_120 ) ;
F_73 ( V_184 , V_4 -> V_120 ) ;
V_4 -> V_120 -> V_185 . V_186 = 512 ;
F_121 ( V_4 -> V_120 , V_187 ) ;
V_4 -> V_120 -> V_185 . V_188 = 0 ;
F_122 ( V_4 -> V_120 , 65536 ) ;
V_4 -> V_120 -> V_185 . V_189 = 256 ;
}
if ( F_123 ( V_190 , L_47 ) ) {
V_132 = - V_28 ;
goto V_117;
}
F_113 ( V_191 L_49 , V_190 ) ;
F_107 () ;
for ( V_166 = 0 ; V_166 < V_170 ; V_166 ++ ) {
struct V_100 * V_4 = V_172 [ V_166 ] . V_4 ;
V_172 [ V_166 ] . V_77 = V_102 ;
F_124 ( & V_172 [ V_166 ] . V_31 ) ;
F_125 ( & V_172 [ V_166 ] . V_108 ) ;
V_4 -> V_192 = V_190 ;
V_4 -> V_193 = V_166 << V_167 ;
V_4 -> V_194 = & V_195 ;
V_4 -> V_101 = & V_172 [ V_166 ] ;
sprintf ( V_4 -> V_196 , L_50 , V_166 ) ;
F_72 ( & V_172 [ V_166 ] ) ;
F_126 ( V_4 ) ;
}
return 0 ;
V_117:
while ( V_166 -- ) {
F_120 ( & V_172 [ V_166 ] . V_93 ) ;
F_127 ( V_172 [ V_166 ] . V_4 -> V_120 ) ;
F_118 ( V_172 [ V_166 ] . V_4 ) ;
}
F_128 ( V_172 ) ;
return V_132 ;
}
static void T_6 F_129 ( void )
{
int V_166 ;
F_108 () ;
for ( V_166 = 0 ; V_166 < V_170 ; V_166 ++ ) {
struct V_100 * V_4 = V_172 [ V_166 ] . V_4 ;
V_172 [ V_166 ] . V_77 = 0 ;
if ( V_4 ) {
F_130 ( V_4 ) ;
F_127 ( V_4 -> V_120 ) ;
F_120 ( & V_172 [ V_166 ] . V_93 ) ;
F_118 ( V_4 ) ;
}
}
F_131 ( V_190 , L_47 ) ;
F_128 ( V_172 ) ;
F_113 ( V_191 L_51 , V_190 ) ;
}
