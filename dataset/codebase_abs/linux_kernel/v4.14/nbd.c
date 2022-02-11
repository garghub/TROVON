static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 ) ;
}
static const char * F_3 ( int V_5 )
{
switch ( V_5 ) {
case V_6 : return L_1 ;
case V_7 : return L_2 ;
case V_8 : return L_3 ;
case V_9 : return L_4 ;
case V_10 : return L_5 ;
}
return L_6 ;
}
static T_1 F_4 ( struct V_1 * V_11 ,
struct V_12 * V_13 , char * V_14 )
{
struct V_15 * V_4 = F_5 ( V_11 ) ;
struct V_2 * V_3 = (struct V_2 * ) V_4 -> V_16 ;
return sprintf ( V_14 , L_7 , F_6 ( V_3 -> V_17 ) ) ;
}
static void F_7 ( struct V_2 * V_3 )
{
struct V_15 * V_4 = V_3 -> V_4 ;
if ( V_4 ) {
F_8 ( V_4 ) ;
F_9 ( V_4 -> V_18 ) ;
F_10 ( & V_3 -> V_19 ) ;
V_4 -> V_16 = NULL ;
F_11 ( V_4 ) ;
}
F_12 ( V_3 ) ;
}
static void F_13 ( struct V_2 * V_3 )
{
if ( F_14 ( & V_3 -> V_20 ,
& V_21 ) ) {
F_15 ( & V_22 , V_3 -> V_23 ) ;
F_16 ( & V_21 ) ;
F_7 ( V_3 ) ;
}
}
static int F_17 ( struct V_24 * V_25 )
{
return F_18 ( V_26 , & V_25 -> V_27 ) ||
F_18 ( V_28 , & V_25 -> V_27 ) ;
}
static void F_19 ( struct V_2 * V_3 , struct V_29 * V_30 ,
int V_31 )
{
if ( ! V_30 -> V_32 && V_31 && ! F_17 ( V_3 -> V_25 ) ) {
struct V_33 * args ;
args = F_20 ( sizeof( struct V_33 ) , V_34 ) ;
if ( args ) {
F_21 ( & args -> V_35 , V_36 ) ;
args -> V_23 = V_3 -> V_23 ;
F_22 ( V_37 , & args -> V_35 ) ;
}
}
if ( ! V_30 -> V_32 ) {
F_23 ( V_30 -> V_38 , V_39 ) ;
F_24 ( & V_3 -> V_25 -> V_40 ) ;
}
V_30 -> V_32 = true ;
V_30 -> V_41 = NULL ;
V_30 -> V_42 = 0 ;
}
static void F_25 ( struct V_2 * V_3 )
{
if ( V_3 -> V_25 -> V_43 ) {
F_26 ( V_3 -> V_4 , 0 ) ;
F_27 ( & F_1 ( V_3 ) -> V_44 , V_45 ) ;
}
}
static void F_28 ( struct V_2 * V_3 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
F_29 ( V_3 -> V_4 -> V_18 , V_25 -> V_46 ) ;
F_30 ( V_3 -> V_4 -> V_18 , V_25 -> V_46 ) ;
F_26 ( V_3 -> V_4 , V_25 -> V_43 >> 9 ) ;
F_27 ( & F_1 ( V_3 ) -> V_44 , V_45 ) ;
}
static void F_31 ( struct V_2 * V_3 , T_2 V_47 ,
T_2 V_48 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
V_25 -> V_46 = V_47 ;
V_25 -> V_43 = V_47 * V_48 ;
}
static void F_32 ( struct V_49 * V_50 )
{
struct V_51 * V_5 = F_33 ( V_50 ) ;
F_34 ( F_1 ( V_5 -> V_3 ) , L_8 , V_5 ,
V_5 -> V_52 ? L_9 : L_10 ) ;
F_35 ( V_50 , V_5 -> V_52 ) ;
}
static void F_36 ( struct V_2 * V_3 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
int V_53 ;
if ( V_25 -> V_54 == 0 )
return;
if ( F_37 ( V_26 , & V_25 -> V_27 ) )
return;
for ( V_53 = 0 ; V_53 < V_25 -> V_54 ; V_53 ++ ) {
struct V_29 * V_30 = V_25 -> V_55 [ V_53 ] ;
F_38 ( & V_30 -> V_56 ) ;
F_19 ( V_3 , V_30 , 0 ) ;
F_16 ( & V_30 -> V_56 ) ;
}
F_39 ( F_2 ( V_3 -> V_4 ) , L_11 ) ;
}
static enum V_57 F_40 ( struct V_49 * V_50 ,
bool V_58 )
{
struct V_51 * V_5 = F_33 ( V_50 ) ;
struct V_2 * V_3 = V_5 -> V_3 ;
struct V_24 * V_25 ;
if ( ! F_41 ( & V_3 -> V_59 ) ) {
V_5 -> V_52 = V_60 ;
return V_61 ;
}
if ( ! F_42 ( & V_5 -> V_62 ) ) {
F_43 ( V_3 ) ;
return V_63 ;
}
V_25 = V_3 -> V_25 ;
if ( V_25 -> V_54 > 1 ) {
F_44 ( F_1 ( V_3 ) ,
L_12 ) ;
if ( V_25 -> V_55 && V_25 -> V_54 > 1 ) {
if ( V_5 -> V_23 < V_25 -> V_54 ) {
struct V_29 * V_30 =
V_25 -> V_55 [ V_5 -> V_23 ] ;
F_38 ( & V_30 -> V_56 ) ;
if ( V_5 -> V_64 == V_30 -> V_64 )
F_19 ( V_3 , V_30 , 1 ) ;
F_16 ( & V_30 -> V_56 ) ;
}
F_45 ( V_50 , true ) ;
F_43 ( V_3 ) ;
return V_65 ;
}
} else {
F_44 ( F_1 ( V_3 ) ,
L_13 ) ;
}
F_46 ( V_66 , & V_25 -> V_27 ) ;
V_5 -> V_52 = V_67 ;
F_36 ( V_3 ) ;
F_43 ( V_3 ) ;
return V_61 ;
}
static int F_47 ( struct V_2 * V_3 , int V_23 , int V_68 ,
struct V_69 * V_70 , int V_71 , int * V_42 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
struct V_72 * V_38 = V_25 -> V_55 [ V_23 ] -> V_38 ;
int V_73 ;
struct V_74 V_75 ;
unsigned int V_76 ;
if ( F_48 ( ! V_38 ) ) {
F_44 ( F_2 ( V_3 -> V_4 ) ,
L_14 ,
( V_68 ? L_15 : L_16 ) ) ;
return - V_77 ;
}
V_75 . V_78 = * V_70 ;
V_76 = F_49 () ;
do {
V_38 -> V_79 -> V_80 = V_34 | V_81 ;
V_75 . V_82 = NULL ;
V_75 . V_83 = 0 ;
V_75 . V_84 = NULL ;
V_75 . V_85 = 0 ;
V_75 . V_71 = V_71 | V_86 ;
if ( V_68 )
V_73 = F_50 ( V_38 , & V_75 ) ;
else
V_73 = F_51 ( V_38 , & V_75 , V_75 . V_71 ) ;
if ( V_73 <= 0 ) {
if ( V_73 == 0 )
V_73 = - V_87 ;
break;
}
if ( V_42 )
* V_42 += V_73 ;
} while ( F_52 ( & V_75 ) );
F_53 ( V_76 ) ;
return V_73 ;
}
static inline int F_54 ( int V_73 )
{
return V_73 == - V_88 || V_73 == - V_89 ;
}
static int F_55 ( struct V_2 * V_3 , struct V_51 * V_5 , int V_23 )
{
struct V_49 * V_50 = F_56 ( V_5 ) ;
struct V_24 * V_25 = V_3 -> V_25 ;
struct V_29 * V_30 = V_25 -> V_55 [ V_23 ] ;
int V_73 ;
struct V_90 V_49 = { . V_91 = F_57 (NBD_REQUEST_MAGIC) } ;
struct V_92 V_93 = { . V_94 = & V_49 , . V_95 = sizeof( V_49 ) } ;
struct V_69 V_96 ;
unsigned long V_97 = F_58 ( V_50 ) ;
struct V_98 * V_98 ;
T_3 type ;
T_3 V_99 = 0 ;
T_3 V_100 = F_59 ( V_50 ) ;
int V_42 = V_30 -> V_42 , V_101 = 0 ;
F_60 ( & V_96 , V_102 | V_103 , & V_93 , 1 , sizeof( V_49 ) ) ;
switch ( F_61 ( V_50 ) ) {
case V_104 :
type = V_10 ;
break;
case V_105 :
type = V_9 ;
break;
case V_106 :
type = V_7 ;
break;
case V_107 :
type = V_6 ;
break;
default:
return - V_108 ;
}
if ( F_62 ( V_50 ) == V_102 &&
( V_25 -> V_109 & V_110 ) ) {
F_44 ( F_2 ( V_3 -> V_4 ) ,
L_17 ) ;
return - V_108 ;
}
if ( V_50 -> V_111 & V_112 )
V_99 |= V_113 ;
if ( V_42 ) {
if ( V_42 >= sizeof( V_49 ) ) {
V_101 = V_42 - sizeof( V_49 ) ;
goto V_114;
}
F_63 ( & V_96 , V_42 ) ;
}
V_5 -> V_23 = V_23 ;
V_5 -> V_64 = V_30 -> V_64 ;
V_49 . type = F_57 ( type | V_99 ) ;
if ( type != V_9 ) {
V_49 . V_96 = F_64 ( ( V_115 ) F_65 ( V_50 ) << 9 ) ;
V_49 . V_116 = F_57 ( V_97 ) ;
}
memcpy ( V_49 . V_117 , & V_100 , sizeof( V_100 ) ) ;
F_34 ( F_1 ( V_3 ) , L_18 ,
V_5 , F_3 ( type ) ,
( unsigned long long ) F_65 ( V_50 ) << 9 , F_58 ( V_50 ) ) ;
V_73 = F_47 ( V_3 , V_23 , 1 , & V_96 ,
( type == V_7 ) ? V_118 : 0 , & V_42 ) ;
if ( V_73 <= 0 ) {
if ( F_54 ( V_73 ) ) {
if ( V_42 ) {
V_30 -> V_41 = V_50 ;
V_30 -> V_42 = V_42 ;
}
return V_119 ;
}
F_44 ( F_2 ( V_3 -> V_4 ) ,
L_19 , V_73 ) ;
return - V_120 ;
}
V_114:
if ( type != V_7 )
goto V_121;
V_98 = V_50 -> V_98 ;
while ( V_98 ) {
struct V_98 * V_122 = V_98 -> V_123 ;
struct V_124 V_70 ;
struct V_125 V_126 ;
F_66 (bvec, bio, iter) {
bool V_127 = ! V_122 && F_67 ( V_126 , V_70 ) ;
int V_109 = V_127 ? 0 : V_118 ;
F_34 ( F_1 ( V_3 ) , L_20 ,
V_5 , V_126 . V_128 ) ;
F_68 ( & V_96 , V_129 | V_102 ,
& V_126 , 1 , V_126 . V_128 ) ;
if ( V_101 ) {
if ( V_101 >= F_69 ( & V_96 ) ) {
V_101 -= F_69 ( & V_96 ) ;
continue;
}
F_63 ( & V_96 , V_101 ) ;
V_101 = 0 ;
}
V_73 = F_47 ( V_3 , V_23 , 1 , & V_96 , V_109 , & V_42 ) ;
if ( V_73 <= 0 ) {
if ( F_54 ( V_73 ) ) {
V_30 -> V_41 = V_50 ;
V_30 -> V_42 = V_42 ;
return V_119 ;
}
F_70 ( F_2 ( V_3 -> V_4 ) ,
L_21 ,
V_73 ) ;
return - V_120 ;
}
if ( V_127 )
break;
}
V_98 = V_122 ;
}
V_121:
V_30 -> V_41 = NULL ;
V_30 -> V_42 = 0 ;
return 0 ;
}
static struct V_51 * F_71 ( struct V_2 * V_3 , int V_23 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
int V_73 ;
struct V_130 V_131 ;
struct V_51 * V_5 ;
struct V_49 * V_50 = NULL ;
T_4 V_132 ;
T_3 V_100 ;
struct V_92 V_93 = { . V_94 = & V_131 , . V_95 = sizeof( V_131 ) } ;
struct V_69 V_133 ;
V_131 . V_91 = 0 ;
F_60 ( & V_133 , V_134 | V_103 , & V_93 , 1 , sizeof( V_131 ) ) ;
V_73 = F_47 ( V_3 , V_23 , 0 , & V_133 , V_135 , NULL ) ;
if ( V_73 <= 0 ) {
if ( ! F_17 ( V_25 ) )
F_70 ( F_2 ( V_3 -> V_4 ) ,
L_22 , V_73 ) ;
return F_72 ( V_73 ) ;
}
if ( F_73 ( V_131 . V_91 ) != V_136 ) {
F_70 ( F_2 ( V_3 -> V_4 ) , L_23 ,
( unsigned long ) F_73 ( V_131 . V_91 ) ) ;
return F_72 ( - V_137 ) ;
}
memcpy ( & V_100 , V_131 . V_117 , sizeof( T_3 ) ) ;
V_132 = F_74 ( V_100 ) ;
if ( V_132 < V_3 -> V_19 . V_138 )
V_50 = F_75 ( V_3 -> V_19 . V_139 [ V_132 ] ,
F_76 ( V_100 ) ) ;
if ( ! V_50 || ! F_77 ( V_50 ) ) {
F_70 ( F_2 ( V_3 -> V_4 ) , L_24 ,
V_100 , V_50 ) ;
return F_72 ( - V_140 ) ;
}
V_5 = F_33 ( V_50 ) ;
if ( F_73 ( V_131 . error ) ) {
F_70 ( F_2 ( V_3 -> V_4 ) , L_25 ,
F_73 ( V_131 . error ) ) ;
V_5 -> V_52 = V_67 ;
return V_5 ;
}
F_34 ( F_1 ( V_3 ) , L_26 , V_5 ) ;
if ( F_62 ( V_50 ) != V_102 ) {
struct V_141 V_70 ;
struct V_125 V_126 ;
F_78 (bvec, req, iter) {
F_68 ( & V_133 , V_129 | V_134 ,
& V_126 , 1 , V_126 . V_128 ) ;
V_73 = F_47 ( V_3 , V_23 , 0 , & V_133 , V_135 , NULL ) ;
if ( V_73 <= 0 ) {
F_70 ( F_2 ( V_3 -> V_4 ) , L_27 ,
V_73 ) ;
if ( F_17 ( V_25 ) ||
V_25 -> V_54 <= 1 ) {
V_5 -> V_52 = V_67 ;
return V_5 ;
}
return F_72 ( - V_108 ) ;
}
F_34 ( F_1 ( V_3 ) , L_28 ,
V_5 , V_126 . V_128 ) ;
}
} else {
F_79 ( & V_5 -> V_62 ) ;
}
return V_5 ;
}
static void F_80 ( struct V_142 * V_35 )
{
struct V_143 * args = F_81 ( V_35 ,
struct V_143 ,
V_35 ) ;
struct V_2 * V_3 = args -> V_3 ;
struct V_24 * V_25 = V_3 -> V_25 ;
struct V_51 * V_5 ;
while ( 1 ) {
V_5 = F_71 ( V_3 , args -> V_23 ) ;
if ( F_82 ( V_5 ) ) {
struct V_29 * V_30 = V_25 -> V_55 [ args -> V_23 ] ;
F_38 ( & V_30 -> V_56 ) ;
F_19 ( V_3 , V_30 , 1 ) ;
F_16 ( & V_30 -> V_56 ) ;
break;
}
F_83 ( F_56 ( V_5 ) ) ;
}
F_24 ( & V_25 -> V_144 ) ;
F_84 ( & V_25 -> V_145 ) ;
F_43 ( V_3 ) ;
F_12 ( args ) ;
}
static void F_85 ( struct V_49 * V_50 , void * V_146 , bool V_58 )
{
struct V_51 * V_5 ;
if ( ! F_77 ( V_50 ) )
return;
V_5 = F_33 ( V_50 ) ;
V_5 -> V_52 = V_67 ;
F_83 ( V_50 ) ;
}
static void F_86 ( struct V_2 * V_3 )
{
F_87 ( V_3 -> V_4 -> V_18 ) ;
F_88 ( & V_3 -> V_19 , F_85 , NULL ) ;
F_89 ( V_3 -> V_4 -> V_18 ) ;
F_34 ( F_2 ( V_3 -> V_4 ) , L_29 ) ;
}
static int F_90 ( struct V_2 * V_3 , int V_23 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
int V_147 = - 1 ;
struct V_29 * V_30 = V_25 -> V_55 [ V_23 ] ;
int V_148 = V_30 -> V_149 ;
if ( F_18 ( V_26 , & V_25 -> V_27 ) )
return V_147 ;
if ( V_25 -> V_54 <= 1 ) {
F_44 ( F_2 ( V_3 -> V_4 ) ,
L_30 ) ;
return V_147 ;
}
if ( V_148 >= 0 && V_148 < V_25 -> V_54 &&
! V_25 -> V_55 [ V_148 ] -> V_32 )
return V_148 ;
if ( V_30 -> V_149 < 0 ||
V_30 -> V_149 >= V_25 -> V_54 ||
V_25 -> V_55 [ V_30 -> V_149 ] -> V_32 ) {
int V_53 ;
for ( V_53 = 0 ; V_53 < V_25 -> V_54 ; V_53 ++ ) {
if ( V_53 == V_23 )
continue;
if ( ! V_25 -> V_55 [ V_53 ] -> V_32 ) {
V_147 = V_53 ;
break;
}
}
V_30 -> V_149 = V_147 ;
if ( V_147 < 0 ) {
F_44 ( F_2 ( V_3 -> V_4 ) ,
L_31 ) ;
return V_147 ;
}
}
V_147 = V_30 -> V_149 ;
return V_147 ;
}
static int F_91 ( struct V_2 * V_3 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
if ( ! V_25 -> V_150 )
return 0 ;
if ( F_18 ( V_26 , & V_25 -> V_27 ) )
return 0 ;
F_92 ( V_25 -> V_151 ,
F_93 ( & V_25 -> V_40 ) ,
V_25 -> V_150 ) ;
return F_93 ( & V_25 -> V_40 ) ;
}
static int F_94 ( struct V_51 * V_5 , int V_23 )
{
struct V_49 * V_50 = F_56 ( V_5 ) ;
struct V_2 * V_3 = V_5 -> V_3 ;
struct V_24 * V_25 ;
struct V_29 * V_30 ;
int V_152 ;
if ( ! F_41 ( & V_3 -> V_59 ) ) {
F_44 ( F_2 ( V_3 -> V_4 ) ,
L_32 ) ;
return - V_77 ;
}
V_25 = V_3 -> V_25 ;
if ( V_23 >= V_25 -> V_54 ) {
F_44 ( F_2 ( V_3 -> V_4 ) ,
L_30 ) ;
F_43 ( V_3 ) ;
return - V_77 ;
}
V_5 -> V_52 = V_153 ;
V_154:
V_30 = V_25 -> V_55 [ V_23 ] ;
F_38 ( & V_30 -> V_56 ) ;
if ( V_30 -> V_32 ) {
int V_155 = V_23 ;
V_23 = F_90 ( V_3 , V_23 ) ;
F_16 ( & V_30 -> V_56 ) ;
if ( V_23 < 0 ) {
if ( F_91 ( V_3 ) ) {
V_23 = V_155 ;
goto V_154;
}
F_36 ( V_3 ) ;
F_43 ( V_3 ) ;
return - V_108 ;
}
goto V_154;
}
if ( F_48 ( V_30 -> V_41 && V_30 -> V_41 != V_50 ) ) {
F_45 ( V_50 , true ) ;
V_152 = 0 ;
goto V_121;
}
V_152 = F_55 ( V_3 , V_5 , V_23 ) ;
if ( V_152 == - V_120 ) {
F_44 ( F_2 ( V_3 -> V_4 ) ,
L_33 ) ;
F_19 ( V_3 , V_30 , 1 ) ;
F_16 ( & V_30 -> V_56 ) ;
goto V_154;
}
V_121:
F_16 ( & V_30 -> V_56 ) ;
F_43 ( V_3 ) ;
return V_152 ;
}
static T_5 F_95 ( struct V_156 * V_157 ,
const struct V_158 * V_159 )
{
struct V_51 * V_5 = F_33 ( V_159 -> V_160 ) ;
int V_152 ;
F_96 ( & V_5 -> V_62 ) ;
F_97 ( V_159 -> V_160 ) ;
V_152 = F_94 ( V_5 , V_157 -> V_161 ) ;
if ( V_152 < 0 )
V_152 = V_67 ;
else if ( ! V_152 )
V_152 = V_153 ;
F_98 ( & V_5 -> V_62 ) ;
return V_152 ;
}
static int F_99 ( struct V_2 * V_3 , unsigned long V_162 ,
bool V_163 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
struct V_72 * V_38 ;
struct V_29 * * V_55 ;
struct V_29 * V_30 ;
int V_164 ;
V_38 = F_100 ( V_162 , & V_164 ) ;
if ( ! V_38 )
return V_164 ;
if ( ! V_163 && ! V_3 -> V_165 &&
! F_18 ( V_166 , & V_25 -> V_27 ) )
V_3 -> V_165 = V_167 ;
if ( ! V_163 &&
( V_3 -> V_165 != V_167 ||
F_18 ( V_166 , & V_25 -> V_27 ) ) ) {
F_70 ( F_2 ( V_3 -> V_4 ) ,
L_34 ) ;
F_101 ( V_38 ) ;
return - V_168 ;
}
V_55 = F_102 ( V_25 -> V_55 , ( V_25 -> V_54 + 1 ) *
sizeof( struct V_29 * ) , V_169 ) ;
if ( ! V_55 ) {
F_101 ( V_38 ) ;
return - V_170 ;
}
V_30 = F_103 ( sizeof( struct V_29 ) , V_169 ) ;
if ( ! V_30 ) {
F_101 ( V_38 ) ;
return - V_170 ;
}
V_25 -> V_55 = V_55 ;
V_30 -> V_149 = - 1 ;
V_30 -> V_32 = false ;
F_104 ( & V_30 -> V_56 ) ;
V_30 -> V_38 = V_38 ;
V_30 -> V_41 = NULL ;
V_30 -> V_42 = 0 ;
V_30 -> V_64 = 0 ;
V_55 [ V_25 -> V_54 ++ ] = V_30 ;
F_105 ( & V_25 -> V_40 ) ;
return 0 ;
}
static int F_106 ( struct V_2 * V_3 , unsigned long V_162 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
struct V_72 * V_38 , * V_171 ;
struct V_143 * args ;
int V_53 ;
int V_164 ;
V_38 = F_100 ( V_162 , & V_164 ) ;
if ( ! V_38 )
return V_164 ;
args = F_103 ( sizeof( * args ) , V_169 ) ;
if ( ! args ) {
F_101 ( V_38 ) ;
return - V_170 ;
}
for ( V_53 = 0 ; V_53 < V_25 -> V_54 ; V_53 ++ ) {
struct V_29 * V_30 = V_25 -> V_55 [ V_53 ] ;
if ( ! V_30 -> V_32 )
continue;
F_38 ( & V_30 -> V_56 ) ;
if ( ! V_30 -> V_32 ) {
F_16 ( & V_30 -> V_56 ) ;
continue;
}
F_107 ( V_38 -> V_79 ) ;
if ( V_3 -> V_19 . V_172 )
V_38 -> V_79 -> V_173 = V_3 -> V_19 . V_172 ;
F_105 ( & V_25 -> V_144 ) ;
F_108 ( & V_3 -> V_59 ) ;
V_171 = V_30 -> V_38 ;
V_30 -> V_149 = - 1 ;
V_30 -> V_38 = V_38 ;
V_30 -> V_32 = false ;
F_21 ( & args -> V_35 , F_80 ) ;
args -> V_23 = V_53 ;
args -> V_3 = V_3 ;
V_30 -> V_64 ++ ;
F_16 ( & V_30 -> V_56 ) ;
F_101 ( V_171 ) ;
F_109 ( V_26 , & V_25 -> V_27 ) ;
F_22 ( V_174 , & args -> V_35 ) ;
F_105 ( & V_25 -> V_40 ) ;
F_84 ( & V_25 -> V_151 ) ;
return 0 ;
}
F_101 ( V_38 ) ;
F_12 ( args ) ;
return - V_175 ;
}
static void F_110 ( struct V_176 * V_177 )
{
if ( V_177 -> V_178 > 1 )
return;
F_111 ( V_177 , 0 ) ;
if ( V_179 > 0 ) {
F_112 ( V_177 ) ;
V_177 -> V_180 = 1 ;
}
}
static void F_113 ( struct V_2 * V_3 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
if ( V_25 -> V_109 & V_110 )
F_114 ( V_3 -> V_4 , true ) ;
else
F_114 ( V_3 -> V_4 , false ) ;
if ( V_25 -> V_109 & V_181 )
F_115 ( V_182 , V_3 -> V_4 -> V_18 ) ;
if ( V_25 -> V_109 & V_183 ) {
if ( V_25 -> V_109 & V_184 )
F_116 ( V_3 -> V_4 -> V_18 , true , true ) ;
else
F_116 ( V_3 -> V_4 -> V_18 , true , false ) ;
}
else
F_116 ( V_3 -> V_4 -> V_18 , false , false ) ;
}
static void F_117 ( struct V_2 * V_3 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
struct V_90 V_49 = {
. V_91 = F_57 ( V_185 ) ,
. type = F_57 ( V_8 ) ,
} ;
struct V_92 V_93 = { . V_94 = & V_49 , . V_95 = sizeof( V_49 ) } ;
struct V_69 V_96 ;
int V_53 , V_152 ;
for ( V_53 = 0 ; V_53 < V_25 -> V_54 ; V_53 ++ ) {
struct V_29 * V_30 = V_25 -> V_55 [ V_53 ] ;
F_60 ( & V_96 , V_102 | V_103 , & V_93 , 1 , sizeof( V_49 ) ) ;
F_38 ( & V_30 -> V_56 ) ;
V_152 = F_47 ( V_3 , V_53 , 1 , & V_96 , 0 , NULL ) ;
if ( V_152 <= 0 )
F_70 ( F_2 ( V_3 -> V_4 ) ,
L_35 , V_152 ) ;
F_16 ( & V_30 -> V_56 ) ;
}
}
static int F_118 ( struct V_2 * V_3 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
F_119 ( F_2 ( V_3 -> V_4 ) , L_36 ) ;
F_46 ( V_28 , & V_25 -> V_27 ) ;
F_117 ( V_3 ) ;
return 0 ;
}
static void F_120 ( struct V_2 * V_3 )
{
F_36 ( V_3 ) ;
F_86 ( V_3 ) ;
V_3 -> V_165 = NULL ;
}
static void F_43 ( struct V_2 * V_3 )
{
if ( F_14 ( & V_3 -> V_59 ,
& V_3 -> V_186 ) ) {
struct V_24 * V_25 = V_3 -> V_25 ;
F_121 ( V_3 ) ;
F_25 ( V_3 ) ;
if ( F_122 ( V_187 ,
& V_25 -> V_27 ) )
F_123 ( F_2 ( V_3 -> V_4 ) , & V_188 ) ;
V_3 -> V_17 = NULL ;
F_120 ( V_3 ) ;
if ( V_25 -> V_54 ) {
int V_53 ;
for ( V_53 = 0 ; V_53 < V_25 -> V_54 ; V_53 ++ ) {
F_101 ( V_25 -> V_55 [ V_53 ] -> V_38 ) ;
F_12 ( V_25 -> V_55 [ V_53 ] ) ;
}
F_12 ( V_25 -> V_55 ) ;
}
F_12 ( V_3 -> V_25 ) ;
V_3 -> V_25 = NULL ;
V_3 -> V_19 . V_172 = 0 ;
F_124 ( V_182 , V_3 -> V_4 -> V_18 ) ;
F_16 ( & V_3 -> V_186 ) ;
F_13 ( V_3 ) ;
F_125 ( V_189 ) ;
}
}
static int F_126 ( struct V_2 * V_3 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
int V_54 = V_25 -> V_54 ;
int error = 0 , V_53 ;
if ( V_3 -> V_17 )
return - V_168 ;
if ( ! V_25 -> V_55 )
return - V_77 ;
if ( V_54 > 1 &&
! ( V_25 -> V_109 & V_190 ) ) {
F_70 ( F_2 ( V_3 -> V_4 ) , L_37 ) ;
return - V_77 ;
}
F_127 ( & V_3 -> V_19 , V_25 -> V_54 ) ;
V_3 -> V_17 = V_167 ;
F_113 ( V_3 ) ;
error = F_128 ( F_2 ( V_3 -> V_4 ) , & V_188 ) ;
if ( error ) {
F_70 ( F_2 ( V_3 -> V_4 ) , L_38 ) ;
return error ;
}
F_46 ( V_187 , & V_25 -> V_27 ) ;
F_129 ( V_3 ) ;
for ( V_53 = 0 ; V_53 < V_54 ; V_53 ++ ) {
struct V_143 * args ;
args = F_103 ( sizeof( * args ) , V_169 ) ;
if ( ! args ) {
F_36 ( V_3 ) ;
return - V_170 ;
}
F_107 ( V_25 -> V_55 [ V_53 ] -> V_38 -> V_79 ) ;
if ( V_3 -> V_19 . V_172 )
V_25 -> V_55 [ V_53 ] -> V_38 -> V_79 -> V_173 =
V_3 -> V_19 . V_172 ;
F_105 ( & V_25 -> V_144 ) ;
F_108 ( & V_3 -> V_59 ) ;
F_21 ( & args -> V_35 , F_80 ) ;
args -> V_3 = V_3 ;
args -> V_23 = V_53 ;
F_22 ( V_174 , & args -> V_35 ) ;
}
F_28 ( V_3 ) ;
return error ;
}
static int F_130 ( struct V_2 * V_3 , struct V_176 * V_177 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
int V_152 ;
V_152 = F_126 ( V_3 ) ;
if ( V_152 )
return V_152 ;
F_111 ( V_177 , V_25 -> V_43 ) ;
if ( V_179 )
V_177 -> V_180 = 1 ;
F_16 ( & V_3 -> V_186 ) ;
V_152 = F_131 ( V_25 -> V_145 ,
F_93 ( & V_25 -> V_144 ) == 0 ) ;
if ( V_152 )
F_36 ( V_3 ) ;
F_38 ( & V_3 -> V_186 ) ;
F_111 ( V_177 , 0 ) ;
if ( F_18 ( V_28 , & V_25 -> V_27 ) )
V_152 = 0 ;
if ( F_18 ( V_66 , & V_25 -> V_27 ) )
V_152 = - V_191 ;
return V_152 ;
}
static void F_132 ( struct V_2 * V_3 ,
struct V_176 * V_177 )
{
F_36 ( V_3 ) ;
F_133 ( V_177 ) ;
F_110 ( V_177 ) ;
if ( F_122 ( V_192 ,
& V_3 -> V_25 -> V_27 ) )
F_43 ( V_3 ) ;
}
static int F_134 ( struct V_176 * V_177 , struct V_2 * V_3 ,
unsigned int V_5 , unsigned long V_162 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
switch ( V_5 ) {
case V_193 :
return F_118 ( V_3 ) ;
case V_194 :
F_132 ( V_3 , V_177 ) ;
return 0 ;
case V_195 :
return F_99 ( V_3 , V_162 , false ) ;
case V_196 :
F_31 ( V_3 , V_162 ,
F_135 ( V_25 -> V_43 , V_162 ) ) ;
return 0 ;
case V_197 :
F_31 ( V_3 , V_25 -> V_46 ,
F_135 ( V_162 , V_25 -> V_46 ) ) ;
return 0 ;
case V_198 :
F_31 ( V_3 , V_25 -> V_46 , V_162 ) ;
return 0 ;
case V_199 :
if ( V_162 ) {
V_3 -> V_19 . V_172 = V_162 * V_200 ;
F_136 ( V_3 -> V_4 -> V_18 , V_162 * V_200 ) ;
}
return 0 ;
case V_201 :
V_25 -> V_109 = V_162 ;
return 0 ;
case V_202 :
return F_130 ( V_3 , V_177 ) ;
case V_203 :
return 0 ;
case V_204 :
return 0 ;
}
return - V_205 ;
}
static int F_137 ( struct V_176 * V_177 , T_6 V_206 ,
unsigned int V_5 , unsigned long V_162 )
{
struct V_2 * V_3 = V_177 -> V_207 -> V_16 ;
struct V_24 * V_25 = V_3 -> V_25 ;
int error = - V_77 ;
if ( ! F_138 ( V_208 ) )
return - V_209 ;
if ( F_139 ( V_5 ) != 0xab )
return - V_77 ;
F_38 ( & V_3 -> V_186 ) ;
if ( ! F_18 ( V_166 , & V_25 -> V_27 ) ||
( V_5 == V_193 || V_5 == V_194 ) )
error = F_134 ( V_177 , V_3 , V_5 , V_162 ) ;
else
F_70 ( F_1 ( V_3 ) , L_39 ) ;
F_16 ( & V_3 -> V_186 ) ;
return error ;
}
static struct V_24 * F_140 ( void )
{
struct V_24 * V_25 ;
V_25 = F_103 ( sizeof( struct V_24 ) , V_210 ) ;
if ( ! V_25 )
return NULL ;
F_141 ( & V_25 -> V_144 , 0 ) ;
F_142 ( & V_25 -> V_145 ) ;
F_142 ( & V_25 -> V_151 ) ;
V_25 -> V_46 = 1024 ;
F_141 ( & V_25 -> V_40 , 0 ) ;
F_143 ( V_189 ) ;
return V_25 ;
}
static int F_144 ( struct V_176 * V_177 , T_6 V_206 )
{
struct V_2 * V_3 ;
int V_152 = 0 ;
F_38 ( & V_21 ) ;
V_3 = V_177 -> V_207 -> V_16 ;
if ( ! V_3 ) {
V_152 = - V_211 ;
goto V_121;
}
if ( ! F_41 ( & V_3 -> V_20 ) ) {
V_152 = - V_211 ;
goto V_121;
}
if ( ! F_41 ( & V_3 -> V_59 ) ) {
struct V_24 * V_25 ;
F_38 ( & V_3 -> V_186 ) ;
if ( F_41 ( & V_3 -> V_59 ) ) {
F_16 ( & V_3 -> V_186 ) ;
goto V_121;
}
V_25 = V_3 -> V_25 = F_140 () ;
if ( ! V_25 ) {
V_152 = - V_170 ;
F_16 ( & V_3 -> V_186 ) ;
goto V_121;
}
F_145 ( & V_3 -> V_59 , 1 ) ;
F_108 ( & V_3 -> V_20 ) ;
F_16 ( & V_3 -> V_186 ) ;
}
V_121:
F_16 ( & V_21 ) ;
return V_152 ;
}
static void F_146 ( struct V_15 * V_4 , T_6 V_206 )
{
struct V_2 * V_3 = V_4 -> V_16 ;
F_43 ( V_3 ) ;
F_13 ( V_3 ) ;
}
static int F_147 ( struct V_212 * V_213 , void * V_214 )
{
struct V_2 * V_3 = V_213 -> V_215 ;
if ( V_3 -> V_17 )
F_148 ( V_213 , L_40 , F_6 ( V_3 -> V_17 ) ) ;
return 0 ;
}
static int F_149 ( struct V_216 * V_216 , struct V_217 * V_217 )
{
return F_150 ( V_217 , F_147 , V_216 -> V_218 ) ;
}
static int F_151 ( struct V_212 * V_213 , void * V_214 )
{
struct V_2 * V_3 = V_213 -> V_215 ;
T_3 V_109 = V_3 -> V_25 -> V_109 ;
F_148 ( V_213 , L_41 , V_109 ) ;
F_152 ( V_213 , L_42 ) ;
if ( V_109 & V_219 )
F_152 ( V_213 , L_43 ) ;
if ( V_109 & V_110 )
F_152 ( V_213 , L_44 ) ;
if ( V_109 & V_183 )
F_152 ( V_213 , L_45 ) ;
if ( V_109 & V_184 )
F_152 ( V_213 , L_46 ) ;
if ( V_109 & V_181 )
F_152 ( V_213 , L_47 ) ;
return 0 ;
}
static int F_153 ( struct V_216 * V_216 , struct V_217 * V_217 )
{
return F_150 ( V_217 , F_151 , V_216 -> V_218 ) ;
}
static int F_129 ( struct V_2 * V_3 )
{
struct V_220 * V_221 ;
struct V_24 * V_25 = V_3 -> V_25 ;
if ( ! V_222 )
return - V_108 ;
V_221 = F_154 ( F_155 ( V_3 ) , V_222 ) ;
if ( ! V_221 ) {
F_70 ( F_1 ( V_3 ) , L_48 ,
F_155 ( V_3 ) ) ;
return - V_108 ;
}
V_25 -> V_223 = V_221 ;
F_156 ( L_49 , 0444 , V_221 , V_3 , & V_224 ) ;
F_157 ( L_50 , 0444 , V_221 , & V_25 -> V_43 ) ;
F_158 ( L_51 , 0444 , V_221 , & V_3 -> V_19 . V_172 ) ;
F_157 ( L_52 , 0444 , V_221 , & V_25 -> V_46 ) ;
F_156 ( L_53 , 0444 , V_221 , V_3 , & V_225 ) ;
return 0 ;
}
static void F_121 ( struct V_2 * V_3 )
{
F_159 ( V_3 -> V_25 -> V_223 ) ;
}
static int F_160 ( void )
{
struct V_220 * V_223 ;
V_223 = F_154 ( L_54 , NULL ) ;
if ( ! V_223 )
return - V_108 ;
V_222 = V_223 ;
return 0 ;
}
static void F_161 ( void )
{
F_159 ( V_222 ) ;
}
static int F_129 ( struct V_2 * V_3 )
{
return 0 ;
}
static void F_121 ( struct V_2 * V_3 )
{
}
static int F_160 ( void )
{
return 0 ;
}
static void F_161 ( void )
{
}
static int F_162 ( struct V_226 * V_227 , struct V_49 * V_160 ,
unsigned int V_228 , unsigned int V_229 )
{
struct V_51 * V_5 = F_33 ( V_160 ) ;
V_5 -> V_3 = V_227 -> V_230 ;
return 0 ;
}
static int F_163 ( int V_23 )
{
struct V_2 * V_3 ;
struct V_15 * V_4 ;
struct V_231 * V_232 ;
int V_164 = - V_170 ;
V_3 = F_103 ( sizeof( struct V_2 ) , V_169 ) ;
if ( ! V_3 )
goto V_121;
V_4 = F_164 ( 1 << V_233 ) ;
if ( ! V_4 )
goto V_234;
if ( V_23 >= 0 ) {
V_164 = F_165 ( & V_22 , V_3 , V_23 , V_23 + 1 ,
V_169 ) ;
if ( V_164 == - V_175 )
V_164 = - V_235 ;
} else {
V_164 = F_165 ( & V_22 , V_3 , 0 , 0 , V_169 ) ;
if ( V_164 >= 0 )
V_23 = V_164 ;
}
if ( V_164 < 0 )
goto V_236;
V_3 -> V_23 = V_23 ;
V_3 -> V_4 = V_4 ;
V_3 -> V_19 . V_237 = & V_238 ;
V_3 -> V_19 . V_138 = 1 ;
V_3 -> V_19 . V_239 = 128 ;
V_3 -> V_19 . V_229 = V_240 ;
V_3 -> V_19 . V_241 = sizeof( struct V_51 ) ;
V_3 -> V_19 . V_109 = V_242 |
V_243 | V_244 ;
V_3 -> V_19 . V_230 = V_3 ;
V_164 = F_166 ( & V_3 -> V_19 ) ;
if ( V_164 )
goto V_245;
V_232 = F_167 ( & V_3 -> V_19 ) ;
if ( F_82 ( V_232 ) ) {
V_164 = F_168 ( V_232 ) ;
goto V_246;
}
V_4 -> V_18 = V_232 ;
F_115 ( V_247 , V_4 -> V_18 ) ;
F_124 ( V_248 , V_4 -> V_18 ) ;
V_4 -> V_18 -> V_249 . V_250 = 512 ;
F_169 ( V_4 -> V_18 , V_251 ) ;
F_170 ( V_4 -> V_18 , V_251 ) ;
F_171 ( V_4 -> V_18 , V_252 ) ;
F_172 ( V_4 -> V_18 , 65536 ) ;
V_4 -> V_18 -> V_249 . V_253 = 256 ;
F_104 ( & V_3 -> V_186 ) ;
F_145 ( & V_3 -> V_59 , 0 ) ;
F_145 ( & V_3 -> V_20 , 1 ) ;
F_173 ( & V_3 -> V_254 ) ;
V_4 -> V_255 = V_256 ;
V_4 -> V_257 = V_23 << V_233 ;
V_4 -> V_258 = & V_259 ;
V_4 -> V_16 = V_3 ;
sprintf ( V_4 -> V_260 , L_55 , V_23 ) ;
F_174 ( V_4 ) ;
V_261 ++ ;
return V_23 ;
V_246:
F_10 ( & V_3 -> V_19 ) ;
V_245:
F_15 ( & V_22 , V_23 ) ;
V_236:
F_11 ( V_4 ) ;
V_234:
F_12 ( V_3 ) ;
V_121:
return V_164 ;
}
static int F_175 ( int V_262 , void * V_263 , void * V_146 )
{
struct V_2 * V_3 = V_263 ;
struct V_2 * * V_264 = V_146 ;
if ( ! F_176 ( & V_3 -> V_59 ) ) {
* V_264 = V_3 ;
return 1 ;
}
return 0 ;
}
static int F_177 ( struct V_265 * V_266 , struct V_267 * V_268 )
{
struct V_2 * V_3 = NULL ;
struct V_24 * V_25 ;
int V_23 = - 1 ;
int V_152 ;
bool V_269 = false ;
if ( ! F_178 ( V_266 , V_208 ) )
return - V_209 ;
if ( V_268 -> V_270 [ V_271 ] )
V_23 = F_179 ( V_268 -> V_270 [ V_271 ] ) ;
if ( ! V_268 -> V_270 [ V_272 ] ) {
F_180 ( V_273 L_56 ) ;
return - V_77 ;
}
if ( ! V_268 -> V_270 [ V_274 ] ) {
F_180 ( V_273 L_57 ) ;
return - V_77 ;
}
V_154:
F_38 ( & V_21 ) ;
if ( V_23 == - 1 ) {
V_152 = F_181 ( & V_22 , & F_175 , & V_3 ) ;
if ( V_152 == 0 ) {
int V_147 ;
V_147 = F_163 ( - 1 ) ;
if ( V_147 < 0 ) {
F_16 ( & V_21 ) ;
F_180 ( V_273 L_58 ) ;
return V_152 ;
}
V_3 = F_182 ( & V_22 , V_147 ) ;
}
} else {
V_3 = F_182 ( & V_22 , V_23 ) ;
if ( ! V_3 ) {
V_152 = F_163 ( V_23 ) ;
if ( V_152 < 0 ) {
F_16 ( & V_21 ) ;
F_180 ( V_273 L_58 ) ;
return V_152 ;
}
V_3 = F_182 ( & V_22 , V_23 ) ;
}
}
if ( ! V_3 ) {
F_180 ( V_273 L_59 ,
V_23 ) ;
F_16 ( & V_21 ) ;
return - V_77 ;
}
if ( ! F_41 ( & V_3 -> V_20 ) ) {
F_16 ( & V_21 ) ;
if ( V_23 == - 1 )
goto V_154;
F_180 ( V_273 L_60 ,
V_23 ) ;
return - V_77 ;
}
F_16 ( & V_21 ) ;
F_38 ( & V_3 -> V_186 ) ;
if ( F_176 ( & V_3 -> V_59 ) ) {
F_16 ( & V_3 -> V_186 ) ;
F_13 ( V_3 ) ;
if ( V_23 == - 1 )
goto V_154;
F_180 ( V_273 L_61 , V_23 ) ;
return - V_168 ;
}
if ( F_183 ( V_3 -> V_25 ) ) {
F_16 ( & V_3 -> V_186 ) ;
F_13 ( V_3 ) ;
return - V_77 ;
}
V_25 = V_3 -> V_25 = F_140 () ;
if ( ! V_3 -> V_25 ) {
F_16 ( & V_3 -> V_186 ) ;
F_13 ( V_3 ) ;
F_180 ( V_273 L_62 ) ;
return - V_170 ;
}
F_145 ( & V_3 -> V_59 , 1 ) ;
F_46 ( V_166 , & V_25 -> V_27 ) ;
if ( V_268 -> V_270 [ V_274 ] ) {
V_115 V_275 = F_184 ( V_268 -> V_270 [ V_274 ] ) ;
F_31 ( V_3 , V_25 -> V_46 ,
F_185 ( V_275 , V_25 -> V_46 ) ) ;
}
if ( V_268 -> V_270 [ V_276 ] ) {
V_115 V_277 =
F_184 ( V_268 -> V_270 [ V_276 ] ) ;
F_31 ( V_3 , V_277 , F_185 ( V_25 -> V_43 , V_277 ) ) ;
}
if ( V_268 -> V_270 [ V_278 ] ) {
V_115 V_172 = F_184 ( V_268 -> V_270 [ V_278 ] ) ;
V_3 -> V_19 . V_172 = V_172 * V_200 ;
F_136 ( V_3 -> V_4 -> V_18 , V_172 * V_200 ) ;
}
if ( V_268 -> V_270 [ V_279 ] ) {
V_25 -> V_150 =
F_184 ( V_268 -> V_270 [ V_279 ] ) ;
V_25 -> V_150 *= V_200 ;
}
if ( V_268 -> V_270 [ V_280 ] )
V_25 -> V_109 =
F_184 ( V_268 -> V_270 [ V_280 ] ) ;
if ( V_268 -> V_270 [ V_281 ] ) {
V_115 V_109 = F_184 ( V_268 -> V_270 [ V_281 ] ) ;
if ( V_109 & V_282 ) {
F_46 ( V_283 ,
& V_25 -> V_27 ) ;
V_269 = true ;
}
}
if ( V_268 -> V_270 [ V_272 ] ) {
struct V_284 * V_13 ;
int V_285 , V_286 ;
F_186 (attr, info->attrs[NBD_ATTR_SOCKETS],
rem) {
struct V_284 * V_55 [ V_287 + 1 ] ;
if ( F_187 ( V_13 ) != V_288 ) {
F_180 ( V_273 L_63 ) ;
V_152 = - V_77 ;
goto V_121;
}
V_152 = F_188 ( V_55 , V_287 , V_13 ,
V_289 , V_268 -> V_290 ) ;
if ( V_152 != 0 ) {
F_180 ( V_273 L_64 ) ;
V_152 = - V_77 ;
goto V_121;
}
if ( ! V_55 [ V_291 ] )
continue;
V_286 = ( int ) F_179 ( V_55 [ V_291 ] ) ;
V_152 = F_99 ( V_3 , V_286 , true ) ;
if ( V_152 )
goto V_121;
}
}
V_152 = F_126 ( V_3 ) ;
V_121:
F_16 ( & V_3 -> V_186 ) ;
if ( ! V_152 ) {
F_46 ( V_192 , & V_25 -> V_27 ) ;
F_108 ( & V_3 -> V_59 ) ;
F_189 ( V_268 , V_3 -> V_23 ) ;
}
F_43 ( V_3 ) ;
if ( V_269 )
F_13 ( V_3 ) ;
return V_152 ;
}
static int F_190 ( struct V_265 * V_266 , struct V_267 * V_268 )
{
struct V_2 * V_3 ;
int V_23 ;
if ( ! F_178 ( V_266 , V_208 ) )
return - V_209 ;
if ( ! V_268 -> V_270 [ V_271 ] ) {
F_180 ( V_273 L_65 ) ;
return - V_77 ;
}
V_23 = F_179 ( V_268 -> V_270 [ V_271 ] ) ;
F_38 ( & V_21 ) ;
V_3 = F_182 ( & V_22 , V_23 ) ;
if ( ! V_3 ) {
F_16 ( & V_21 ) ;
F_180 ( V_273 L_59 ,
V_23 ) ;
return - V_77 ;
}
if ( ! F_41 ( & V_3 -> V_20 ) ) {
F_16 ( & V_21 ) ;
F_180 ( V_273 L_60 ,
V_23 ) ;
return - V_77 ;
}
F_16 ( & V_21 ) ;
if ( ! F_41 ( & V_3 -> V_59 ) ) {
F_13 ( V_3 ) ;
return 0 ;
}
F_38 ( & V_3 -> V_186 ) ;
F_118 ( V_3 ) ;
F_16 ( & V_3 -> V_186 ) ;
if ( F_122 ( V_192 ,
& V_3 -> V_25 -> V_27 ) )
F_43 ( V_3 ) ;
F_43 ( V_3 ) ;
F_13 ( V_3 ) ;
return 0 ;
}
static int F_191 ( struct V_265 * V_266 , struct V_267 * V_268 )
{
struct V_2 * V_3 = NULL ;
struct V_24 * V_25 ;
int V_23 ;
int V_152 = - V_77 ;
bool V_269 = false ;
if ( ! F_178 ( V_266 , V_208 ) )
return - V_209 ;
if ( ! V_268 -> V_270 [ V_271 ] ) {
F_180 ( V_273 L_66 ) ;
return - V_77 ;
}
V_23 = F_179 ( V_268 -> V_270 [ V_271 ] ) ;
F_38 ( & V_21 ) ;
V_3 = F_182 ( & V_22 , V_23 ) ;
if ( ! V_3 ) {
F_16 ( & V_21 ) ;
F_180 ( V_273 L_67 ,
V_23 ) ;
return - V_77 ;
}
if ( ! F_41 ( & V_3 -> V_20 ) ) {
F_16 ( & V_21 ) ;
F_180 ( V_273 L_60 ,
V_23 ) ;
return - V_77 ;
}
F_16 ( & V_21 ) ;
if ( ! F_41 ( & V_3 -> V_59 ) ) {
F_70 ( F_1 ( V_3 ) ,
L_68 ) ;
F_13 ( V_3 ) ;
return - V_77 ;
}
F_38 ( & V_3 -> V_186 ) ;
V_25 = V_3 -> V_25 ;
if ( ! F_18 ( V_166 , & V_25 -> V_27 ) ||
! V_3 -> V_17 ) {
F_70 ( F_1 ( V_3 ) ,
L_68 ) ;
goto V_121;
}
if ( V_268 -> V_270 [ V_278 ] ) {
V_115 V_172 = F_184 ( V_268 -> V_270 [ V_278 ] ) ;
V_3 -> V_19 . V_172 = V_172 * V_200 ;
F_136 ( V_3 -> V_4 -> V_18 , V_172 * V_200 ) ;
}
if ( V_268 -> V_270 [ V_279 ] ) {
V_25 -> V_150 =
F_184 ( V_268 -> V_270 [ V_279 ] ) ;
V_25 -> V_150 *= V_200 ;
}
if ( V_268 -> V_270 [ V_281 ] ) {
V_115 V_109 = F_184 ( V_268 -> V_270 [ V_281 ] ) ;
if ( V_109 & V_282 ) {
if ( ! F_37 ( V_283 ,
& V_25 -> V_27 ) )
V_269 = true ;
} else {
if ( F_122 ( V_283 ,
& V_25 -> V_27 ) )
F_108 ( & V_3 -> V_20 ) ;
}
}
if ( V_268 -> V_270 [ V_272 ] ) {
struct V_284 * V_13 ;
int V_285 , V_286 ;
F_186 (attr, info->attrs[NBD_ATTR_SOCKETS],
rem) {
struct V_284 * V_55 [ V_287 + 1 ] ;
if ( F_187 ( V_13 ) != V_288 ) {
F_180 ( V_273 L_63 ) ;
V_152 = - V_77 ;
goto V_121;
}
V_152 = F_188 ( V_55 , V_287 , V_13 ,
V_289 , V_268 -> V_290 ) ;
if ( V_152 != 0 ) {
F_180 ( V_273 L_64 ) ;
V_152 = - V_77 ;
goto V_121;
}
if ( ! V_55 [ V_291 ] )
continue;
V_286 = ( int ) F_179 ( V_55 [ V_291 ] ) ;
V_152 = F_106 ( V_3 , V_286 ) ;
if ( V_152 ) {
if ( V_152 == - V_175 )
V_152 = 0 ;
goto V_121;
}
F_119 ( F_1 ( V_3 ) , L_69 ) ;
}
}
V_121:
F_16 ( & V_3 -> V_186 ) ;
F_43 ( V_3 ) ;
F_13 ( V_3 ) ;
if ( V_269 )
F_13 ( V_3 ) ;
return V_152 ;
}
static int F_192 ( struct V_2 * V_3 , struct V_265 * V_131 )
{
struct V_284 * V_292 ;
T_7 V_293 = 0 ;
int V_152 ;
if ( F_176 ( & V_3 -> V_59 ) )
V_293 = 1 ;
V_292 = F_193 ( V_131 , V_294 ) ;
if ( ! V_292 )
return - V_295 ;
V_152 = F_194 ( V_131 , V_296 , V_3 -> V_23 ) ;
if ( V_152 )
return - V_295 ;
V_152 = F_195 ( V_131 , V_297 ,
V_293 ) ;
if ( V_152 )
return - V_295 ;
F_196 ( V_131 , V_292 ) ;
return 0 ;
}
static int F_197 ( int V_262 , void * V_263 , void * V_146 )
{
struct V_2 * V_3 = V_263 ;
return F_192 ( V_3 , (struct V_265 * ) V_146 ) ;
}
static int F_198 ( struct V_265 * V_266 , struct V_267 * V_268 )
{
struct V_284 * V_298 ;
struct V_265 * V_131 ;
void * V_299 ;
T_8 V_300 ;
int V_23 = - 1 ;
int V_152 = - V_170 ;
if ( V_268 -> V_270 [ V_271 ] )
V_23 = F_179 ( V_268 -> V_270 [ V_271 ] ) ;
F_38 ( & V_21 ) ;
V_300 = F_199 ( F_200 ( sizeof( T_3 ) ) +
F_200 ( sizeof( T_7 ) ) ) ;
V_300 *= ( V_23 == - 1 ) ? V_261 : 1 ;
V_131 = F_201 ( V_300 , V_169 ) ;
if ( ! V_131 )
goto V_121;
V_299 = F_202 ( V_131 , V_268 , & V_301 , 0 ,
V_302 ) ;
if ( ! V_299 ) {
F_203 ( V_131 ) ;
goto V_121;
}
V_298 = F_193 ( V_131 , V_303 ) ;
if ( V_23 == - 1 ) {
V_152 = F_181 ( & V_22 , & F_197 , V_131 ) ;
if ( V_152 ) {
F_203 ( V_131 ) ;
goto V_121;
}
} else {
struct V_2 * V_3 ;
V_3 = F_182 ( & V_22 , V_23 ) ;
if ( V_3 ) {
V_152 = F_192 ( V_3 , V_131 ) ;
if ( V_152 ) {
F_203 ( V_131 ) ;
goto V_121;
}
}
}
F_196 ( V_131 , V_298 ) ;
F_204 ( V_131 , V_299 ) ;
F_205 ( V_131 , V_268 ) ;
V_152 = 0 ;
V_121:
F_16 ( & V_21 ) ;
return V_152 ;
}
static void F_189 ( struct V_267 * V_268 , int V_23 )
{
struct V_265 * V_266 ;
void * V_304 ;
int V_152 ;
V_266 = F_201 ( F_199 ( sizeof( T_3 ) ) , V_169 ) ;
if ( ! V_266 )
return;
V_304 = F_202 ( V_266 , V_268 , & V_301 , 0 ,
V_305 ) ;
if ( ! V_304 ) {
F_203 ( V_266 ) ;
return;
}
V_152 = F_194 ( V_266 , V_271 , V_23 ) ;
if ( V_152 ) {
F_203 ( V_266 ) ;
return;
}
F_204 ( V_266 , V_304 ) ;
F_205 ( V_266 , V_268 ) ;
}
static void F_206 ( int V_23 )
{
struct V_265 * V_266 ;
void * V_304 ;
int V_152 ;
V_266 = F_201 ( F_199 ( sizeof( T_3 ) ) , V_169 ) ;
if ( ! V_266 )
return;
V_304 = F_207 ( V_266 , 0 , 0 , & V_301 , 0 ,
V_306 ) ;
if ( ! V_304 ) {
F_203 ( V_266 ) ;
return;
}
V_152 = F_194 ( V_266 , V_271 , V_23 ) ;
if ( V_152 ) {
F_203 ( V_266 ) ;
return;
}
F_204 ( V_266 , V_304 ) ;
F_208 ( & V_301 , V_266 , 0 , 0 , V_169 ) ;
}
static void V_36 ( struct V_142 * V_35 )
{
struct V_33 * args = F_81 ( V_35 , struct V_33 ,
V_35 ) ;
F_206 ( args -> V_23 ) ;
F_12 ( args ) ;
}
static int T_9 F_209 ( void )
{
int V_53 ;
F_210 ( sizeof( struct V_90 ) != 28 ) ;
if ( V_179 < 0 ) {
F_180 ( V_273 L_70 ) ;
return - V_77 ;
}
V_233 = 0 ;
if ( V_179 > 0 ) {
V_233 = F_211 ( V_179 ) ;
V_179 = ( 1UL << V_233 ) - 1 ;
}
if ( ( 1UL << V_233 ) > V_307 )
return - V_77 ;
if ( V_308 > 1UL << ( V_309 - V_233 ) )
return - V_77 ;
V_174 = F_212 ( L_71 ,
V_310 | V_311 , 0 ) ;
if ( ! V_174 )
return - V_170 ;
if ( F_213 ( V_256 , L_54 ) ) {
F_214 ( V_174 ) ;
return - V_108 ;
}
if ( F_215 ( & V_301 ) ) {
F_216 ( V_256 , L_54 ) ;
F_214 ( V_174 ) ;
return - V_77 ;
}
F_160 () ;
F_38 ( & V_21 ) ;
for ( V_53 = 0 ; V_53 < V_308 ; V_53 ++ )
F_163 ( V_53 ) ;
F_16 ( & V_21 ) ;
return 0 ;
}
static int F_217 ( int V_262 , void * V_263 , void * V_146 )
{
struct V_312 * V_254 = (struct V_312 * ) V_146 ;
struct V_2 * V_3 = V_263 ;
F_218 ( & V_3 -> V_254 , V_254 ) ;
return 0 ;
}
static void T_10 F_219 ( void )
{
struct V_2 * V_3 ;
F_220 ( V_313 ) ;
F_161 () ;
F_38 ( & V_21 ) ;
F_181 ( & V_22 , & F_217 , & V_313 ) ;
F_16 ( & V_21 ) ;
while ( ! F_221 ( & V_313 ) ) {
V_3 = F_222 ( & V_313 , struct V_2 , V_254 ) ;
F_223 ( & V_3 -> V_254 ) ;
if ( F_176 ( & V_3 -> V_20 ) != 1 )
F_180 ( V_273 L_72 ) ;
F_13 ( V_3 ) ;
}
F_224 ( & V_22 ) ;
F_225 ( & V_301 ) ;
F_214 ( V_174 ) ;
F_216 ( V_256 , L_54 ) ;
}
