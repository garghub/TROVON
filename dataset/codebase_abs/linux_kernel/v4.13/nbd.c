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
F_28 ( V_3 ) ;
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
static int F_54 ( struct V_2 * V_3 , struct V_51 * V_5 , int V_23 )
{
struct V_49 * V_50 = F_55 ( V_5 ) ;
struct V_24 * V_25 = V_3 -> V_25 ;
struct V_29 * V_30 = V_25 -> V_55 [ V_23 ] ;
int V_73 ;
struct V_88 V_49 = { . V_89 = F_56 (NBD_REQUEST_MAGIC) } ;
struct V_90 V_91 = { . V_92 = & V_49 , . V_93 = sizeof( V_49 ) } ;
struct V_69 V_94 ;
unsigned long V_95 = F_57 ( V_50 ) ;
struct V_96 * V_96 ;
T_3 type ;
T_3 V_97 = 0 ;
T_3 V_98 = F_58 ( V_50 ) ;
int V_42 = V_30 -> V_42 , V_99 = 0 ;
F_59 ( & V_94 , V_100 | V_101 , & V_91 , 1 , sizeof( V_49 ) ) ;
switch ( F_60 ( V_50 ) ) {
case V_102 :
type = V_10 ;
break;
case V_103 :
type = V_9 ;
break;
case V_104 :
type = V_7 ;
break;
case V_105 :
type = V_6 ;
break;
default:
return - V_106 ;
}
if ( F_61 ( V_50 ) == V_100 &&
( V_25 -> V_107 & V_108 ) ) {
F_44 ( F_2 ( V_3 -> V_4 ) ,
L_17 ) ;
return - V_106 ;
}
if ( V_50 -> V_109 & V_110 )
V_97 |= V_111 ;
if ( V_42 ) {
if ( V_42 >= sizeof( V_49 ) ) {
V_99 = V_42 - sizeof( V_49 ) ;
goto V_112;
}
F_62 ( & V_94 , V_42 ) ;
}
V_5 -> V_23 = V_23 ;
V_5 -> V_64 = V_30 -> V_64 ;
V_49 . type = F_56 ( type | V_97 ) ;
if ( type != V_9 ) {
V_49 . V_94 = F_63 ( ( V_113 ) F_64 ( V_50 ) << 9 ) ;
V_49 . V_114 = F_56 ( V_95 ) ;
}
memcpy ( V_49 . V_115 , & V_98 , sizeof( V_98 ) ) ;
F_34 ( F_1 ( V_3 ) , L_18 ,
V_5 , F_3 ( type ) ,
( unsigned long long ) F_64 ( V_50 ) << 9 , F_57 ( V_50 ) ) ;
V_73 = F_47 ( V_3 , V_23 , 1 , & V_94 ,
( type == V_7 ) ? V_116 : 0 , & V_42 ) ;
if ( V_73 <= 0 ) {
if ( V_73 == - V_117 ) {
if ( V_42 ) {
V_30 -> V_41 = V_50 ;
V_30 -> V_42 = V_42 ;
}
return V_118 ;
}
F_44 ( F_2 ( V_3 -> V_4 ) ,
L_19 , V_73 ) ;
return - V_119 ;
}
V_112:
if ( type != V_7 )
goto V_120;
V_96 = V_50 -> V_96 ;
while ( V_96 ) {
struct V_96 * V_121 = V_96 -> V_122 ;
struct V_123 V_70 ;
struct V_124 V_125 ;
F_65 (bvec, bio, iter) {
bool V_126 = ! V_121 && F_66 ( V_125 , V_70 ) ;
int V_107 = V_126 ? 0 : V_116 ;
F_34 ( F_1 ( V_3 ) , L_20 ,
V_5 , V_125 . V_127 ) ;
F_67 ( & V_94 , V_128 | V_100 ,
& V_125 , 1 , V_125 . V_127 ) ;
if ( V_99 ) {
if ( V_99 >= F_68 ( & V_94 ) ) {
V_99 -= F_68 ( & V_94 ) ;
continue;
}
F_62 ( & V_94 , V_99 ) ;
V_99 = 0 ;
}
V_73 = F_47 ( V_3 , V_23 , 1 , & V_94 , V_107 , & V_42 ) ;
if ( V_73 <= 0 ) {
if ( V_73 == - V_117 ) {
V_30 -> V_41 = V_50 ;
V_30 -> V_42 = V_42 ;
return V_118 ;
}
F_69 ( F_2 ( V_3 -> V_4 ) ,
L_21 ,
V_73 ) ;
return - V_119 ;
}
if ( V_126 )
break;
}
V_96 = V_121 ;
}
V_120:
V_30 -> V_41 = NULL ;
V_30 -> V_42 = 0 ;
return 0 ;
}
static struct V_51 * F_70 ( struct V_2 * V_3 , int V_23 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
int V_73 ;
struct V_129 V_130 ;
struct V_51 * V_5 ;
struct V_49 * V_50 = NULL ;
T_4 V_131 ;
T_3 V_98 ;
struct V_90 V_91 = { . V_92 = & V_130 , . V_93 = sizeof( V_130 ) } ;
struct V_69 V_132 ;
V_130 . V_89 = 0 ;
F_59 ( & V_132 , V_133 | V_101 , & V_91 , 1 , sizeof( V_130 ) ) ;
V_73 = F_47 ( V_3 , V_23 , 0 , & V_132 , V_134 , NULL ) ;
if ( V_73 <= 0 ) {
if ( ! F_17 ( V_25 ) )
F_69 ( F_2 ( V_3 -> V_4 ) ,
L_22 , V_73 ) ;
return F_71 ( V_73 ) ;
}
if ( F_72 ( V_130 . V_89 ) != V_135 ) {
F_69 ( F_2 ( V_3 -> V_4 ) , L_23 ,
( unsigned long ) F_72 ( V_130 . V_89 ) ) ;
return F_71 ( - V_136 ) ;
}
memcpy ( & V_98 , V_130 . V_115 , sizeof( T_3 ) ) ;
V_131 = F_73 ( V_98 ) ;
if ( V_131 < V_3 -> V_19 . V_137 )
V_50 = F_74 ( V_3 -> V_19 . V_138 [ V_131 ] ,
F_75 ( V_98 ) ) ;
if ( ! V_50 || ! F_76 ( V_50 ) ) {
F_69 ( F_2 ( V_3 -> V_4 ) , L_24 ,
V_98 , V_50 ) ;
return F_71 ( - V_139 ) ;
}
V_5 = F_33 ( V_50 ) ;
if ( F_72 ( V_130 . error ) ) {
F_69 ( F_2 ( V_3 -> V_4 ) , L_25 ,
F_72 ( V_130 . error ) ) ;
V_5 -> V_52 = V_67 ;
return V_5 ;
}
F_34 ( F_1 ( V_3 ) , L_26 , V_5 ) ;
if ( F_61 ( V_50 ) != V_100 ) {
struct V_140 V_70 ;
struct V_124 V_125 ;
F_77 (bvec, req, iter) {
F_67 ( & V_132 , V_128 | V_133 ,
& V_125 , 1 , V_125 . V_127 ) ;
V_73 = F_47 ( V_3 , V_23 , 0 , & V_132 , V_134 , NULL ) ;
if ( V_73 <= 0 ) {
F_69 ( F_2 ( V_3 -> V_4 ) , L_27 ,
V_73 ) ;
if ( F_17 ( V_25 ) ||
V_25 -> V_54 <= 1 ) {
V_5 -> V_52 = V_67 ;
return V_5 ;
}
return F_71 ( - V_106 ) ;
}
F_34 ( F_1 ( V_3 ) , L_28 ,
V_5 , V_125 . V_127 ) ;
}
} else {
F_78 ( & V_5 -> V_62 ) ;
}
return V_5 ;
}
static void F_79 ( struct V_141 * V_35 )
{
struct V_142 * args = F_80 ( V_35 ,
struct V_142 ,
V_35 ) ;
struct V_2 * V_3 = args -> V_3 ;
struct V_24 * V_25 = V_3 -> V_25 ;
struct V_51 * V_5 ;
while ( 1 ) {
V_5 = F_70 ( V_3 , args -> V_23 ) ;
if ( F_81 ( V_5 ) ) {
struct V_29 * V_30 = V_25 -> V_55 [ args -> V_23 ] ;
F_38 ( & V_30 -> V_56 ) ;
F_19 ( V_3 , V_30 , 1 ) ;
F_16 ( & V_30 -> V_56 ) ;
break;
}
F_82 ( F_55 ( V_5 ) ) ;
}
F_24 ( & V_25 -> V_143 ) ;
F_83 ( & V_25 -> V_144 ) ;
F_43 ( V_3 ) ;
F_12 ( args ) ;
}
static void F_84 ( struct V_49 * V_50 , void * V_145 , bool V_58 )
{
struct V_51 * V_5 ;
if ( ! F_76 ( V_50 ) )
return;
V_5 = F_33 ( V_50 ) ;
V_5 -> V_52 = V_67 ;
F_82 ( V_50 ) ;
}
static void F_85 ( struct V_2 * V_3 )
{
F_86 ( V_3 -> V_4 -> V_18 ) ;
F_87 ( & V_3 -> V_19 , F_84 , NULL ) ;
F_88 ( V_3 -> V_4 -> V_18 ) ;
F_34 ( F_2 ( V_3 -> V_4 ) , L_29 ) ;
}
static int F_89 ( struct V_2 * V_3 , int V_23 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
int V_146 = - 1 ;
struct V_29 * V_30 = V_25 -> V_55 [ V_23 ] ;
int V_147 = V_30 -> V_148 ;
if ( F_18 ( V_26 , & V_25 -> V_27 ) )
return V_146 ;
if ( V_25 -> V_54 <= 1 ) {
F_44 ( F_2 ( V_3 -> V_4 ) ,
L_30 ) ;
return V_146 ;
}
if ( V_147 >= 0 && V_147 < V_25 -> V_54 &&
! V_25 -> V_55 [ V_147 ] -> V_32 )
return V_147 ;
if ( V_30 -> V_148 < 0 ||
V_30 -> V_148 >= V_25 -> V_54 ||
V_25 -> V_55 [ V_30 -> V_148 ] -> V_32 ) {
int V_53 ;
for ( V_53 = 0 ; V_53 < V_25 -> V_54 ; V_53 ++ ) {
if ( V_53 == V_23 )
continue;
if ( ! V_25 -> V_55 [ V_53 ] -> V_32 ) {
V_146 = V_53 ;
break;
}
}
V_30 -> V_148 = V_146 ;
if ( V_146 < 0 ) {
F_44 ( F_2 ( V_3 -> V_4 ) ,
L_31 ) ;
return V_146 ;
}
}
V_146 = V_30 -> V_148 ;
return V_146 ;
}
static int F_90 ( struct V_2 * V_3 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
if ( ! V_25 -> V_149 )
return 0 ;
if ( F_18 ( V_26 , & V_25 -> V_27 ) )
return 0 ;
F_91 ( V_25 -> V_150 ,
F_92 ( & V_25 -> V_40 ) ,
V_25 -> V_149 ) ;
return F_92 ( & V_25 -> V_40 ) ;
}
static int F_93 ( struct V_51 * V_5 , int V_23 )
{
struct V_49 * V_50 = F_55 ( V_5 ) ;
struct V_2 * V_3 = V_5 -> V_3 ;
struct V_24 * V_25 ;
struct V_29 * V_30 ;
int V_151 ;
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
V_5 -> V_52 = V_152 ;
V_153:
V_30 = V_25 -> V_55 [ V_23 ] ;
F_38 ( & V_30 -> V_56 ) ;
if ( V_30 -> V_32 ) {
int V_154 = V_23 ;
V_23 = F_89 ( V_3 , V_23 ) ;
F_16 ( & V_30 -> V_56 ) ;
if ( V_23 < 0 ) {
if ( F_90 ( V_3 ) ) {
V_23 = V_154 ;
goto V_153;
}
F_36 ( V_3 ) ;
F_43 ( V_3 ) ;
return - V_106 ;
}
goto V_153;
}
if ( F_48 ( V_30 -> V_41 && V_30 -> V_41 != V_50 ) ) {
F_45 ( V_50 , true ) ;
V_151 = 0 ;
goto V_120;
}
V_151 = F_54 ( V_3 , V_5 , V_23 ) ;
if ( V_151 == - V_119 ) {
F_44 ( F_2 ( V_3 -> V_4 ) ,
L_33 ) ;
F_19 ( V_3 , V_30 , 1 ) ;
F_16 ( & V_30 -> V_56 ) ;
goto V_153;
}
V_120:
F_16 ( & V_30 -> V_56 ) ;
F_43 ( V_3 ) ;
return V_151 ;
}
static T_5 F_94 ( struct V_155 * V_156 ,
const struct V_157 * V_158 )
{
struct V_51 * V_5 = F_33 ( V_158 -> V_159 ) ;
int V_151 ;
F_95 ( & V_5 -> V_62 ) ;
F_96 ( V_158 -> V_159 ) ;
V_151 = F_93 ( V_5 , V_156 -> V_160 ) ;
F_97 ( & V_5 -> V_62 ) ;
return V_151 < 0 ? V_67 : V_152 ;
}
static int F_98 ( struct V_2 * V_3 , unsigned long V_161 ,
bool V_162 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
struct V_72 * V_38 ;
struct V_29 * * V_55 ;
struct V_29 * V_30 ;
int V_163 ;
V_38 = F_99 ( V_161 , & V_163 ) ;
if ( ! V_38 )
return V_163 ;
if ( ! V_162 && ! V_3 -> V_164 &&
! F_18 ( V_165 , & V_25 -> V_27 ) )
V_3 -> V_164 = V_166 ;
if ( ! V_162 &&
( V_3 -> V_164 != V_166 ||
F_18 ( V_165 , & V_25 -> V_27 ) ) ) {
F_69 ( F_2 ( V_3 -> V_4 ) ,
L_34 ) ;
F_100 ( V_38 ) ;
return - V_167 ;
}
V_55 = F_101 ( V_25 -> V_55 , ( V_25 -> V_54 + 1 ) *
sizeof( struct V_29 * ) , V_168 ) ;
if ( ! V_55 ) {
F_100 ( V_38 ) ;
return - V_169 ;
}
V_30 = F_102 ( sizeof( struct V_29 ) , V_168 ) ;
if ( ! V_30 ) {
F_100 ( V_38 ) ;
return - V_169 ;
}
V_25 -> V_55 = V_55 ;
V_30 -> V_148 = - 1 ;
V_30 -> V_32 = false ;
F_103 ( & V_30 -> V_56 ) ;
V_30 -> V_38 = V_38 ;
V_30 -> V_41 = NULL ;
V_30 -> V_42 = 0 ;
V_30 -> V_64 = 0 ;
V_55 [ V_25 -> V_54 ++ ] = V_30 ;
F_104 ( & V_25 -> V_40 ) ;
return 0 ;
}
static int F_105 ( struct V_2 * V_3 , unsigned long V_161 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
struct V_72 * V_38 , * V_170 ;
struct V_142 * args ;
int V_53 ;
int V_163 ;
V_38 = F_99 ( V_161 , & V_163 ) ;
if ( ! V_38 )
return V_163 ;
args = F_102 ( sizeof( * args ) , V_168 ) ;
if ( ! args ) {
F_100 ( V_38 ) ;
return - V_169 ;
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
F_106 ( V_38 -> V_79 ) ;
if ( V_3 -> V_19 . V_171 )
V_38 -> V_79 -> V_172 = V_3 -> V_19 . V_171 ;
F_104 ( & V_25 -> V_143 ) ;
F_107 ( & V_3 -> V_59 ) ;
V_170 = V_30 -> V_38 ;
V_30 -> V_148 = - 1 ;
V_30 -> V_38 = V_38 ;
V_30 -> V_32 = false ;
F_21 ( & args -> V_35 , F_79 ) ;
args -> V_23 = V_53 ;
args -> V_3 = V_3 ;
V_30 -> V_64 ++ ;
F_16 ( & V_30 -> V_56 ) ;
F_100 ( V_170 ) ;
F_108 ( V_26 , & V_25 -> V_27 ) ;
F_22 ( V_173 , & args -> V_35 ) ;
F_104 ( & V_25 -> V_40 ) ;
F_83 ( & V_25 -> V_150 ) ;
return 0 ;
}
F_100 ( V_38 ) ;
F_12 ( args ) ;
return - V_174 ;
}
static void F_109 ( struct V_175 * V_176 )
{
if ( V_176 -> V_177 > 1 )
return;
F_110 ( V_176 , 0 ) ;
if ( V_178 > 0 ) {
F_111 ( V_176 ) ;
V_176 -> V_179 = 1 ;
}
}
static void F_112 ( struct V_2 * V_3 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
if ( V_25 -> V_107 & V_108 )
F_113 ( V_3 -> V_4 , true ) ;
else
F_113 ( V_3 -> V_4 , false ) ;
if ( V_25 -> V_107 & V_180 )
F_114 ( V_181 , V_3 -> V_4 -> V_18 ) ;
if ( V_25 -> V_107 & V_182 ) {
if ( V_25 -> V_107 & V_183 )
F_115 ( V_3 -> V_4 -> V_18 , true , true ) ;
else
F_115 ( V_3 -> V_4 -> V_18 , true , false ) ;
}
else
F_115 ( V_3 -> V_4 -> V_18 , false , false ) ;
}
static void F_116 ( struct V_2 * V_3 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
struct V_88 V_49 = {
. V_89 = F_56 ( V_184 ) ,
. type = F_56 ( V_8 ) ,
} ;
struct V_90 V_91 = { . V_92 = & V_49 , . V_93 = sizeof( V_49 ) } ;
struct V_69 V_94 ;
int V_53 , V_151 ;
for ( V_53 = 0 ; V_53 < V_25 -> V_54 ; V_53 ++ ) {
struct V_29 * V_30 = V_25 -> V_55 [ V_53 ] ;
F_59 ( & V_94 , V_100 | V_101 , & V_91 , 1 , sizeof( V_49 ) ) ;
F_38 ( & V_30 -> V_56 ) ;
V_151 = F_47 ( V_3 , V_53 , 1 , & V_94 , 0 , NULL ) ;
if ( V_151 <= 0 )
F_69 ( F_2 ( V_3 -> V_4 ) ,
L_35 , V_151 ) ;
F_16 ( & V_30 -> V_56 ) ;
}
}
static int F_117 ( struct V_2 * V_3 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
F_118 ( F_2 ( V_3 -> V_4 ) , L_36 ) ;
F_46 ( V_28 , & V_25 -> V_27 ) ;
F_116 ( V_3 ) ;
return 0 ;
}
static void F_119 ( struct V_2 * V_3 )
{
F_36 ( V_3 ) ;
F_85 ( V_3 ) ;
V_3 -> V_164 = NULL ;
}
static void F_43 ( struct V_2 * V_3 )
{
if ( F_14 ( & V_3 -> V_59 ,
& V_3 -> V_185 ) ) {
struct V_24 * V_25 = V_3 -> V_25 ;
F_120 ( V_3 ) ;
F_25 ( V_3 ) ;
if ( F_121 ( V_186 ,
& V_25 -> V_27 ) )
F_122 ( F_2 ( V_3 -> V_4 ) , & V_187 ) ;
V_3 -> V_17 = NULL ;
F_119 ( V_3 ) ;
if ( V_25 -> V_54 ) {
int V_53 ;
for ( V_53 = 0 ; V_53 < V_25 -> V_54 ; V_53 ++ ) {
F_100 ( V_25 -> V_55 [ V_53 ] -> V_38 ) ;
F_12 ( V_25 -> V_55 [ V_53 ] ) ;
}
F_12 ( V_25 -> V_55 ) ;
}
F_12 ( V_3 -> V_25 ) ;
V_3 -> V_25 = NULL ;
V_3 -> V_19 . V_171 = 0 ;
F_123 ( V_181 , V_3 -> V_4 -> V_18 ) ;
F_16 ( & V_3 -> V_185 ) ;
F_13 ( V_3 ) ;
F_124 ( V_188 ) ;
}
}
static int F_125 ( struct V_2 * V_3 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
int V_54 = V_25 -> V_54 ;
int error = 0 , V_53 ;
if ( V_3 -> V_17 )
return - V_167 ;
if ( ! V_25 -> V_55 )
return - V_77 ;
if ( V_54 > 1 &&
! ( V_25 -> V_107 & V_189 ) ) {
F_69 ( F_2 ( V_3 -> V_4 ) , L_37 ) ;
return - V_77 ;
}
F_126 ( & V_3 -> V_19 , V_25 -> V_54 ) ;
V_3 -> V_17 = V_166 ;
F_112 ( V_3 ) ;
error = F_127 ( F_2 ( V_3 -> V_4 ) , & V_187 ) ;
if ( error ) {
F_69 ( F_2 ( V_3 -> V_4 ) , L_38 ) ;
return error ;
}
F_46 ( V_186 , & V_25 -> V_27 ) ;
F_128 ( V_3 ) ;
for ( V_53 = 0 ; V_53 < V_54 ; V_53 ++ ) {
struct V_142 * args ;
args = F_102 ( sizeof( * args ) , V_168 ) ;
if ( ! args ) {
F_36 ( V_3 ) ;
return - V_169 ;
}
F_106 ( V_25 -> V_55 [ V_53 ] -> V_38 -> V_79 ) ;
if ( V_3 -> V_19 . V_171 )
V_25 -> V_55 [ V_53 ] -> V_38 -> V_79 -> V_172 =
V_3 -> V_19 . V_171 ;
F_104 ( & V_25 -> V_143 ) ;
F_107 ( & V_3 -> V_59 ) ;
F_21 ( & args -> V_35 , F_79 ) ;
args -> V_3 = V_3 ;
args -> V_23 = V_53 ;
F_22 ( V_173 , & args -> V_35 ) ;
}
return error ;
}
static int F_129 ( struct V_2 * V_3 , struct V_175 * V_176 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
int V_151 ;
V_151 = F_125 ( V_3 ) ;
if ( V_151 )
return V_151 ;
F_110 ( V_176 , V_25 -> V_43 ) ;
if ( V_178 )
V_176 -> V_179 = 1 ;
F_16 ( & V_3 -> V_185 ) ;
V_151 = F_130 ( V_25 -> V_144 ,
F_92 ( & V_25 -> V_143 ) == 0 ) ;
if ( V_151 )
F_36 ( V_3 ) ;
F_38 ( & V_3 -> V_185 ) ;
F_110 ( V_176 , 0 ) ;
if ( F_18 ( V_28 , & V_25 -> V_27 ) )
V_151 = 0 ;
if ( F_18 ( V_66 , & V_25 -> V_27 ) )
V_151 = - V_190 ;
return V_151 ;
}
static void F_131 ( struct V_2 * V_3 ,
struct V_175 * V_176 )
{
F_36 ( V_3 ) ;
F_132 ( V_176 ) ;
F_109 ( V_176 ) ;
if ( F_121 ( V_191 ,
& V_3 -> V_25 -> V_27 ) )
F_43 ( V_3 ) ;
}
static int F_133 ( struct V_175 * V_176 , struct V_2 * V_3 ,
unsigned int V_5 , unsigned long V_161 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
switch ( V_5 ) {
case V_192 :
return F_117 ( V_3 ) ;
case V_193 :
F_131 ( V_3 , V_176 ) ;
return 0 ;
case V_194 :
return F_98 ( V_3 , V_161 , false ) ;
case V_195 :
F_31 ( V_3 , V_161 ,
F_134 ( V_25 -> V_43 , V_161 ) ) ;
return 0 ;
case V_196 :
F_31 ( V_3 , V_25 -> V_46 ,
F_134 ( V_161 , V_25 -> V_46 ) ) ;
return 0 ;
case V_197 :
F_31 ( V_3 , V_25 -> V_46 , V_161 ) ;
return 0 ;
case V_198 :
if ( V_161 ) {
V_3 -> V_19 . V_171 = V_161 * V_199 ;
F_135 ( V_3 -> V_4 -> V_18 , V_161 * V_199 ) ;
}
return 0 ;
case V_200 :
V_25 -> V_107 = V_161 ;
return 0 ;
case V_201 :
return F_129 ( V_3 , V_176 ) ;
case V_202 :
return 0 ;
case V_203 :
return 0 ;
}
return - V_204 ;
}
static int F_136 ( struct V_175 * V_176 , T_6 V_205 ,
unsigned int V_5 , unsigned long V_161 )
{
struct V_2 * V_3 = V_176 -> V_206 -> V_16 ;
struct V_24 * V_25 = V_3 -> V_25 ;
int error = - V_77 ;
if ( ! F_137 ( V_207 ) )
return - V_208 ;
F_38 ( & V_3 -> V_185 ) ;
if ( ! F_18 ( V_165 , & V_25 -> V_27 ) ||
( V_5 == V_192 || V_5 == V_193 ) )
error = F_133 ( V_176 , V_3 , V_5 , V_161 ) ;
else
F_69 ( F_1 ( V_3 ) , L_39 ) ;
F_16 ( & V_3 -> V_185 ) ;
return error ;
}
static struct V_24 * F_138 ( void )
{
struct V_24 * V_25 ;
V_25 = F_102 ( sizeof( struct V_24 ) , V_209 ) ;
if ( ! V_25 )
return NULL ;
F_139 ( & V_25 -> V_143 , 0 ) ;
F_140 ( & V_25 -> V_144 ) ;
F_140 ( & V_25 -> V_150 ) ;
V_25 -> V_46 = 1024 ;
F_139 ( & V_25 -> V_40 , 0 ) ;
F_141 ( V_188 ) ;
return V_25 ;
}
static int F_142 ( struct V_175 * V_176 , T_6 V_205 )
{
struct V_2 * V_3 ;
int V_151 = 0 ;
F_38 ( & V_21 ) ;
V_3 = V_176 -> V_206 -> V_16 ;
if ( ! V_3 ) {
V_151 = - V_210 ;
goto V_120;
}
if ( ! F_41 ( & V_3 -> V_20 ) ) {
V_151 = - V_210 ;
goto V_120;
}
if ( ! F_41 ( & V_3 -> V_59 ) ) {
struct V_24 * V_25 ;
F_38 ( & V_3 -> V_185 ) ;
if ( F_41 ( & V_3 -> V_59 ) ) {
F_16 ( & V_3 -> V_185 ) ;
goto V_120;
}
V_25 = V_3 -> V_25 = F_138 () ;
if ( ! V_25 ) {
V_151 = - V_169 ;
F_16 ( & V_3 -> V_185 ) ;
goto V_120;
}
F_143 ( & V_3 -> V_59 , 1 ) ;
F_107 ( & V_3 -> V_20 ) ;
F_16 ( & V_3 -> V_185 ) ;
}
V_120:
F_16 ( & V_21 ) ;
return V_151 ;
}
static void F_144 ( struct V_15 * V_4 , T_6 V_205 )
{
struct V_2 * V_3 = V_4 -> V_16 ;
F_43 ( V_3 ) ;
F_13 ( V_3 ) ;
}
static int F_145 ( struct V_211 * V_212 , void * V_213 )
{
struct V_2 * V_3 = V_212 -> V_214 ;
if ( V_3 -> V_17 )
F_146 ( V_212 , L_40 , F_6 ( V_3 -> V_17 ) ) ;
return 0 ;
}
static int F_147 ( struct V_215 * V_215 , struct V_216 * V_216 )
{
return F_148 ( V_216 , F_145 , V_215 -> V_217 ) ;
}
static int F_149 ( struct V_211 * V_212 , void * V_213 )
{
struct V_2 * V_3 = V_212 -> V_214 ;
T_3 V_107 = V_3 -> V_25 -> V_107 ;
F_146 ( V_212 , L_41 , V_107 ) ;
F_150 ( V_212 , L_42 ) ;
if ( V_107 & V_218 )
F_150 ( V_212 , L_43 ) ;
if ( V_107 & V_108 )
F_150 ( V_212 , L_44 ) ;
if ( V_107 & V_182 )
F_150 ( V_212 , L_45 ) ;
if ( V_107 & V_183 )
F_150 ( V_212 , L_46 ) ;
if ( V_107 & V_180 )
F_150 ( V_212 , L_47 ) ;
return 0 ;
}
static int F_151 ( struct V_215 * V_215 , struct V_216 * V_216 )
{
return F_148 ( V_216 , F_149 , V_215 -> V_217 ) ;
}
static int F_128 ( struct V_2 * V_3 )
{
struct V_219 * V_220 ;
struct V_24 * V_25 = V_3 -> V_25 ;
if ( ! V_221 )
return - V_106 ;
V_220 = F_152 ( F_153 ( V_3 ) , V_221 ) ;
if ( ! V_220 ) {
F_69 ( F_1 ( V_3 ) , L_48 ,
F_153 ( V_3 ) ) ;
return - V_106 ;
}
V_25 -> V_222 = V_220 ;
F_154 ( L_49 , 0444 , V_220 , V_3 , & V_223 ) ;
F_155 ( L_50 , 0444 , V_220 , & V_25 -> V_43 ) ;
F_156 ( L_51 , 0444 , V_220 , & V_3 -> V_19 . V_171 ) ;
F_155 ( L_52 , 0444 , V_220 , & V_25 -> V_46 ) ;
F_154 ( L_53 , 0444 , V_220 , V_3 , & V_224 ) ;
return 0 ;
}
static void F_120 ( struct V_2 * V_3 )
{
F_157 ( V_3 -> V_25 -> V_222 ) ;
}
static int F_158 ( void )
{
struct V_219 * V_222 ;
V_222 = F_152 ( L_54 , NULL ) ;
if ( ! V_222 )
return - V_106 ;
V_221 = V_222 ;
return 0 ;
}
static void F_159 ( void )
{
F_157 ( V_221 ) ;
}
static int F_128 ( struct V_2 * V_3 )
{
return 0 ;
}
static void F_120 ( struct V_2 * V_3 )
{
}
static int F_158 ( void )
{
return 0 ;
}
static void F_159 ( void )
{
}
static int F_160 ( struct V_225 * V_226 , struct V_49 * V_159 ,
unsigned int V_227 , unsigned int V_228 )
{
struct V_51 * V_5 = F_33 ( V_159 ) ;
V_5 -> V_3 = V_226 -> V_229 ;
return 0 ;
}
static int F_161 ( int V_23 )
{
struct V_2 * V_3 ;
struct V_15 * V_4 ;
struct V_230 * V_231 ;
int V_163 = - V_169 ;
V_3 = F_102 ( sizeof( struct V_2 ) , V_168 ) ;
if ( ! V_3 )
goto V_120;
V_4 = F_162 ( 1 << V_232 ) ;
if ( ! V_4 )
goto V_233;
if ( V_23 >= 0 ) {
V_163 = F_163 ( & V_22 , V_3 , V_23 , V_23 + 1 ,
V_168 ) ;
if ( V_163 == - V_174 )
V_163 = - V_234 ;
} else {
V_163 = F_163 ( & V_22 , V_3 , 0 , 0 , V_168 ) ;
if ( V_163 >= 0 )
V_23 = V_163 ;
}
if ( V_163 < 0 )
goto V_235;
V_3 -> V_23 = V_23 ;
V_3 -> V_4 = V_4 ;
V_3 -> V_19 . V_236 = & V_237 ;
V_3 -> V_19 . V_137 = 1 ;
V_3 -> V_19 . V_238 = 128 ;
V_3 -> V_19 . V_228 = V_239 ;
V_3 -> V_19 . V_240 = sizeof( struct V_51 ) ;
V_3 -> V_19 . V_107 = V_241 |
V_242 | V_243 ;
V_3 -> V_19 . V_229 = V_3 ;
V_163 = F_164 ( & V_3 -> V_19 ) ;
if ( V_163 )
goto V_244;
V_231 = F_165 ( & V_3 -> V_19 ) ;
if ( F_81 ( V_231 ) ) {
V_163 = F_166 ( V_231 ) ;
goto V_245;
}
V_4 -> V_18 = V_231 ;
F_114 ( V_246 , V_4 -> V_18 ) ;
F_123 ( V_247 , V_4 -> V_18 ) ;
V_4 -> V_18 -> V_248 . V_249 = 512 ;
F_167 ( V_4 -> V_18 , V_250 ) ;
F_168 ( V_4 -> V_18 , V_250 ) ;
F_169 ( V_4 -> V_18 , V_251 ) ;
F_170 ( V_4 -> V_18 , 65536 ) ;
V_4 -> V_18 -> V_248 . V_252 = 256 ;
F_103 ( & V_3 -> V_185 ) ;
F_143 ( & V_3 -> V_59 , 0 ) ;
F_143 ( & V_3 -> V_20 , 1 ) ;
F_171 ( & V_3 -> V_253 ) ;
V_4 -> V_254 = V_255 ;
V_4 -> V_256 = V_23 << V_232 ;
V_4 -> V_257 = & V_258 ;
V_4 -> V_16 = V_3 ;
sprintf ( V_4 -> V_259 , L_55 , V_23 ) ;
F_172 ( V_4 ) ;
V_260 ++ ;
return V_23 ;
V_245:
F_10 ( & V_3 -> V_19 ) ;
V_244:
F_15 ( & V_22 , V_23 ) ;
V_235:
F_11 ( V_4 ) ;
V_233:
F_12 ( V_3 ) ;
V_120:
return V_163 ;
}
static int F_173 ( int V_261 , void * V_262 , void * V_145 )
{
struct V_2 * V_3 = V_262 ;
struct V_2 * * V_263 = V_145 ;
if ( ! F_174 ( & V_3 -> V_59 ) ) {
* V_263 = V_3 ;
return 1 ;
}
return 0 ;
}
static int F_175 ( struct V_264 * V_265 , struct V_266 * V_267 )
{
struct V_2 * V_3 = NULL ;
struct V_24 * V_25 ;
int V_23 = - 1 ;
int V_151 ;
bool V_268 = false ;
if ( ! F_176 ( V_265 , V_207 ) )
return - V_208 ;
if ( V_267 -> V_269 [ V_270 ] )
V_23 = F_177 ( V_267 -> V_269 [ V_270 ] ) ;
if ( ! V_267 -> V_269 [ V_271 ] ) {
F_178 ( V_272 L_56 ) ;
return - V_77 ;
}
if ( ! V_267 -> V_269 [ V_273 ] ) {
F_178 ( V_272 L_57 ) ;
return - V_77 ;
}
V_153:
F_38 ( & V_21 ) ;
if ( V_23 == - 1 ) {
V_151 = F_179 ( & V_22 , & F_173 , & V_3 ) ;
if ( V_151 == 0 ) {
int V_146 ;
V_146 = F_161 ( - 1 ) ;
if ( V_146 < 0 ) {
F_16 ( & V_21 ) ;
F_178 ( V_272 L_58 ) ;
return V_151 ;
}
V_3 = F_180 ( & V_22 , V_146 ) ;
}
} else {
V_3 = F_180 ( & V_22 , V_23 ) ;
}
if ( ! V_3 ) {
F_178 ( V_272 L_59 ,
V_23 ) ;
F_16 ( & V_21 ) ;
return - V_77 ;
}
if ( ! F_41 ( & V_3 -> V_20 ) ) {
F_16 ( & V_21 ) ;
if ( V_23 == - 1 )
goto V_153;
F_178 ( V_272 L_60 ,
V_23 ) ;
return - V_77 ;
}
F_16 ( & V_21 ) ;
F_38 ( & V_3 -> V_185 ) ;
if ( F_174 ( & V_3 -> V_59 ) ) {
F_16 ( & V_3 -> V_185 ) ;
F_13 ( V_3 ) ;
if ( V_23 == - 1 )
goto V_153;
F_178 ( V_272 L_61 , V_23 ) ;
return - V_167 ;
}
if ( F_181 ( V_3 -> V_25 ) ) {
F_16 ( & V_3 -> V_185 ) ;
F_13 ( V_3 ) ;
return - V_77 ;
}
V_25 = V_3 -> V_25 = F_138 () ;
if ( ! V_3 -> V_25 ) {
F_16 ( & V_3 -> V_185 ) ;
F_13 ( V_3 ) ;
F_178 ( V_272 L_62 ) ;
return - V_169 ;
}
F_143 ( & V_3 -> V_59 , 1 ) ;
F_46 ( V_165 , & V_25 -> V_27 ) ;
if ( V_267 -> V_269 [ V_273 ] ) {
V_113 V_274 = F_182 ( V_267 -> V_269 [ V_273 ] ) ;
F_31 ( V_3 , V_25 -> V_46 ,
F_183 ( V_274 , V_25 -> V_46 ) ) ;
}
if ( V_267 -> V_269 [ V_275 ] ) {
V_113 V_276 =
F_182 ( V_267 -> V_269 [ V_275 ] ) ;
F_31 ( V_3 , V_276 , F_183 ( V_25 -> V_43 , V_276 ) ) ;
}
if ( V_267 -> V_269 [ V_277 ] ) {
V_113 V_171 = F_182 ( V_267 -> V_269 [ V_277 ] ) ;
V_3 -> V_19 . V_171 = V_171 * V_199 ;
F_135 ( V_3 -> V_4 -> V_18 , V_171 * V_199 ) ;
}
if ( V_267 -> V_269 [ V_278 ] ) {
V_25 -> V_149 =
F_182 ( V_267 -> V_269 [ V_278 ] ) ;
V_25 -> V_149 *= V_199 ;
}
if ( V_267 -> V_269 [ V_279 ] )
V_25 -> V_107 =
F_182 ( V_267 -> V_269 [ V_279 ] ) ;
if ( V_267 -> V_269 [ V_280 ] ) {
V_113 V_107 = F_182 ( V_267 -> V_269 [ V_280 ] ) ;
if ( V_107 & V_281 ) {
F_46 ( V_282 ,
& V_25 -> V_27 ) ;
V_268 = true ;
}
}
if ( V_267 -> V_269 [ V_271 ] ) {
struct V_283 * V_13 ;
int V_284 , V_285 ;
F_184 (attr, info->attrs[NBD_ATTR_SOCKETS],
rem) {
struct V_283 * V_55 [ V_286 + 1 ] ;
if ( F_185 ( V_13 ) != V_287 ) {
F_178 ( V_272 L_63 ) ;
V_151 = - V_77 ;
goto V_120;
}
V_151 = F_186 ( V_55 , V_286 , V_13 ,
V_288 , V_267 -> V_289 ) ;
if ( V_151 != 0 ) {
F_178 ( V_272 L_64 ) ;
V_151 = - V_77 ;
goto V_120;
}
if ( ! V_55 [ V_290 ] )
continue;
V_285 = ( int ) F_177 ( V_55 [ V_290 ] ) ;
V_151 = F_98 ( V_3 , V_285 , true ) ;
if ( V_151 )
goto V_120;
}
}
V_151 = F_125 ( V_3 ) ;
V_120:
F_16 ( & V_3 -> V_185 ) ;
if ( ! V_151 ) {
F_46 ( V_191 , & V_25 -> V_27 ) ;
F_107 ( & V_3 -> V_59 ) ;
F_187 ( V_267 , V_3 -> V_23 ) ;
}
F_43 ( V_3 ) ;
if ( V_268 )
F_13 ( V_3 ) ;
return V_151 ;
}
static int F_188 ( struct V_264 * V_265 , struct V_266 * V_267 )
{
struct V_2 * V_3 ;
int V_23 ;
if ( ! F_176 ( V_265 , V_207 ) )
return - V_208 ;
if ( ! V_267 -> V_269 [ V_270 ] ) {
F_178 ( V_272 L_65 ) ;
return - V_77 ;
}
V_23 = F_177 ( V_267 -> V_269 [ V_270 ] ) ;
F_38 ( & V_21 ) ;
V_3 = F_180 ( & V_22 , V_23 ) ;
if ( ! V_3 ) {
F_16 ( & V_21 ) ;
F_178 ( V_272 L_59 ,
V_23 ) ;
return - V_77 ;
}
if ( ! F_41 ( & V_3 -> V_20 ) ) {
F_16 ( & V_21 ) ;
F_178 ( V_272 L_60 ,
V_23 ) ;
return - V_77 ;
}
F_16 ( & V_21 ) ;
if ( ! F_41 ( & V_3 -> V_59 ) ) {
F_13 ( V_3 ) ;
return 0 ;
}
F_38 ( & V_3 -> V_185 ) ;
F_117 ( V_3 ) ;
F_16 ( & V_3 -> V_185 ) ;
if ( F_121 ( V_191 ,
& V_3 -> V_25 -> V_27 ) )
F_43 ( V_3 ) ;
F_43 ( V_3 ) ;
F_13 ( V_3 ) ;
return 0 ;
}
static int F_189 ( struct V_264 * V_265 , struct V_266 * V_267 )
{
struct V_2 * V_3 = NULL ;
struct V_24 * V_25 ;
int V_23 ;
int V_151 = - V_77 ;
bool V_268 = false ;
if ( ! F_176 ( V_265 , V_207 ) )
return - V_208 ;
if ( ! V_267 -> V_269 [ V_270 ] ) {
F_178 ( V_272 L_66 ) ;
return - V_77 ;
}
V_23 = F_177 ( V_267 -> V_269 [ V_270 ] ) ;
F_38 ( & V_21 ) ;
V_3 = F_180 ( & V_22 , V_23 ) ;
if ( ! V_3 ) {
F_16 ( & V_21 ) ;
F_178 ( V_272 L_67 ,
V_23 ) ;
return - V_77 ;
}
if ( ! F_41 ( & V_3 -> V_20 ) ) {
F_16 ( & V_21 ) ;
F_178 ( V_272 L_60 ,
V_23 ) ;
return - V_77 ;
}
F_16 ( & V_21 ) ;
if ( ! F_41 ( & V_3 -> V_59 ) ) {
F_69 ( F_1 ( V_3 ) ,
L_68 ) ;
F_13 ( V_3 ) ;
return - V_77 ;
}
F_38 ( & V_3 -> V_185 ) ;
V_25 = V_3 -> V_25 ;
if ( ! F_18 ( V_165 , & V_25 -> V_27 ) ||
! V_3 -> V_17 ) {
F_69 ( F_1 ( V_3 ) ,
L_68 ) ;
goto V_120;
}
if ( V_267 -> V_269 [ V_277 ] ) {
V_113 V_171 = F_182 ( V_267 -> V_269 [ V_277 ] ) ;
V_3 -> V_19 . V_171 = V_171 * V_199 ;
F_135 ( V_3 -> V_4 -> V_18 , V_171 * V_199 ) ;
}
if ( V_267 -> V_269 [ V_278 ] ) {
V_25 -> V_149 =
F_182 ( V_267 -> V_269 [ V_278 ] ) ;
V_25 -> V_149 *= V_199 ;
}
if ( V_267 -> V_269 [ V_280 ] ) {
V_113 V_107 = F_182 ( V_267 -> V_269 [ V_280 ] ) ;
if ( V_107 & V_281 ) {
if ( ! F_37 ( V_282 ,
& V_25 -> V_27 ) )
V_268 = true ;
} else {
if ( F_121 ( V_282 ,
& V_25 -> V_27 ) )
F_107 ( & V_3 -> V_20 ) ;
}
}
if ( V_267 -> V_269 [ V_271 ] ) {
struct V_283 * V_13 ;
int V_284 , V_285 ;
F_184 (attr, info->attrs[NBD_ATTR_SOCKETS],
rem) {
struct V_283 * V_55 [ V_286 + 1 ] ;
if ( F_185 ( V_13 ) != V_287 ) {
F_178 ( V_272 L_63 ) ;
V_151 = - V_77 ;
goto V_120;
}
V_151 = F_186 ( V_55 , V_286 , V_13 ,
V_288 , V_267 -> V_289 ) ;
if ( V_151 != 0 ) {
F_178 ( V_272 L_64 ) ;
V_151 = - V_77 ;
goto V_120;
}
if ( ! V_55 [ V_290 ] )
continue;
V_285 = ( int ) F_177 ( V_55 [ V_290 ] ) ;
V_151 = F_105 ( V_3 , V_285 ) ;
if ( V_151 ) {
if ( V_151 == - V_174 )
V_151 = 0 ;
goto V_120;
}
F_118 ( F_1 ( V_3 ) , L_69 ) ;
}
}
V_120:
F_16 ( & V_3 -> V_185 ) ;
F_43 ( V_3 ) ;
F_13 ( V_3 ) ;
if ( V_268 )
F_13 ( V_3 ) ;
return V_151 ;
}
static int F_190 ( struct V_2 * V_3 , struct V_264 * V_130 )
{
struct V_283 * V_291 ;
T_7 V_292 = 0 ;
int V_151 ;
if ( F_174 ( & V_3 -> V_59 ) )
V_292 = 1 ;
V_291 = F_191 ( V_130 , V_293 ) ;
if ( ! V_291 )
return - V_294 ;
V_151 = F_192 ( V_130 , V_295 , V_3 -> V_23 ) ;
if ( V_151 )
return - V_294 ;
V_151 = F_193 ( V_130 , V_296 ,
V_292 ) ;
if ( V_151 )
return - V_294 ;
F_194 ( V_130 , V_291 ) ;
return 0 ;
}
static int F_195 ( int V_261 , void * V_262 , void * V_145 )
{
struct V_2 * V_3 = V_262 ;
return F_190 ( V_3 , (struct V_264 * ) V_145 ) ;
}
static int F_196 ( struct V_264 * V_265 , struct V_266 * V_267 )
{
struct V_283 * V_297 ;
struct V_264 * V_130 ;
void * V_298 ;
T_8 V_299 ;
int V_23 = - 1 ;
int V_151 = - V_169 ;
if ( V_267 -> V_269 [ V_270 ] )
V_23 = F_177 ( V_267 -> V_269 [ V_270 ] ) ;
F_38 ( & V_21 ) ;
V_299 = F_197 ( F_198 ( sizeof( T_3 ) ) +
F_198 ( sizeof( T_7 ) ) ) ;
V_299 *= ( V_23 == - 1 ) ? V_260 : 1 ;
V_130 = F_199 ( V_299 , V_168 ) ;
if ( ! V_130 )
goto V_120;
V_298 = F_200 ( V_130 , V_267 , & V_300 , 0 ,
V_301 ) ;
if ( ! V_298 ) {
F_201 ( V_130 ) ;
goto V_120;
}
V_297 = F_191 ( V_130 , V_302 ) ;
if ( V_23 == - 1 ) {
V_151 = F_179 ( & V_22 , & F_195 , V_130 ) ;
if ( V_151 ) {
F_201 ( V_130 ) ;
goto V_120;
}
} else {
struct V_2 * V_3 ;
V_3 = F_180 ( & V_22 , V_23 ) ;
if ( V_3 ) {
V_151 = F_190 ( V_3 , V_130 ) ;
if ( V_151 ) {
F_201 ( V_130 ) ;
goto V_120;
}
}
}
F_194 ( V_130 , V_297 ) ;
F_202 ( V_130 , V_298 ) ;
F_203 ( V_130 , V_267 ) ;
V_151 = 0 ;
V_120:
F_16 ( & V_21 ) ;
return V_151 ;
}
static void F_187 ( struct V_266 * V_267 , int V_23 )
{
struct V_264 * V_265 ;
void * V_303 ;
int V_151 ;
V_265 = F_199 ( F_197 ( sizeof( T_3 ) ) , V_168 ) ;
if ( ! V_265 )
return;
V_303 = F_200 ( V_265 , V_267 , & V_300 , 0 ,
V_304 ) ;
if ( ! V_303 ) {
F_201 ( V_265 ) ;
return;
}
V_151 = F_192 ( V_265 , V_270 , V_23 ) ;
if ( V_151 ) {
F_201 ( V_265 ) ;
return;
}
F_202 ( V_265 , V_303 ) ;
F_203 ( V_265 , V_267 ) ;
}
static void F_204 ( int V_23 )
{
struct V_264 * V_265 ;
void * V_303 ;
int V_151 ;
V_265 = F_199 ( F_197 ( sizeof( T_3 ) ) , V_168 ) ;
if ( ! V_265 )
return;
V_303 = F_205 ( V_265 , 0 , 0 , & V_300 , 0 ,
V_305 ) ;
if ( ! V_303 ) {
F_201 ( V_265 ) ;
return;
}
V_151 = F_192 ( V_265 , V_270 , V_23 ) ;
if ( V_151 ) {
F_201 ( V_265 ) ;
return;
}
F_202 ( V_265 , V_303 ) ;
F_206 ( & V_300 , V_265 , 0 , 0 , V_168 ) ;
}
static void V_36 ( struct V_141 * V_35 )
{
struct V_33 * args = F_80 ( V_35 , struct V_33 ,
V_35 ) ;
F_204 ( args -> V_23 ) ;
F_12 ( args ) ;
}
static int T_9 F_207 ( void )
{
int V_53 ;
F_208 ( sizeof( struct V_88 ) != 28 ) ;
if ( V_178 < 0 ) {
F_178 ( V_272 L_70 ) ;
return - V_77 ;
}
V_232 = 0 ;
if ( V_178 > 0 ) {
V_232 = F_209 ( V_178 ) ;
V_178 = ( 1UL << V_232 ) - 1 ;
}
if ( ( 1UL << V_232 ) > V_306 )
return - V_77 ;
if ( V_307 > 1UL << ( V_308 - V_232 ) )
return - V_77 ;
V_173 = F_210 ( L_71 ,
V_309 | V_310 , 0 ) ;
if ( ! V_173 )
return - V_169 ;
if ( F_211 ( V_255 , L_54 ) ) {
F_212 ( V_173 ) ;
return - V_106 ;
}
if ( F_213 ( & V_300 ) ) {
F_214 ( V_255 , L_54 ) ;
F_212 ( V_173 ) ;
return - V_77 ;
}
F_158 () ;
F_38 ( & V_21 ) ;
for ( V_53 = 0 ; V_53 < V_307 ; V_53 ++ )
F_161 ( V_53 ) ;
F_16 ( & V_21 ) ;
return 0 ;
}
static int F_215 ( int V_261 , void * V_262 , void * V_145 )
{
struct V_311 * V_253 = (struct V_311 * ) V_145 ;
struct V_2 * V_3 = V_262 ;
F_216 ( & V_3 -> V_253 , V_253 ) ;
return 0 ;
}
static void T_10 F_217 ( void )
{
struct V_2 * V_3 ;
F_218 ( V_312 ) ;
F_159 () ;
F_38 ( & V_21 ) ;
F_179 ( & V_22 , & F_215 , & V_312 ) ;
F_16 ( & V_21 ) ;
while ( ! F_219 ( & V_312 ) ) {
V_3 = F_220 ( & V_312 , struct V_2 , V_253 ) ;
F_221 ( & V_3 -> V_253 ) ;
if ( F_174 ( & V_3 -> V_20 ) != 1 )
F_178 ( V_272 L_72 ) ;
F_13 ( V_3 ) ;
}
F_222 ( & V_22 ) ;
F_223 ( & V_300 ) ;
F_212 ( V_173 ) ;
F_214 ( V_255 , L_54 ) ;
}
