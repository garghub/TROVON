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
V_5 -> V_52 = - V_60 ;
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
V_5 -> V_52 = - V_60 ;
F_36 ( V_3 ) ;
F_43 ( V_3 ) ;
return V_61 ;
}
static int F_47 ( struct V_2 * V_3 , int V_23 , int V_67 ,
struct V_68 * V_69 , int V_70 , int * V_42 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
struct V_71 * V_38 = V_25 -> V_55 [ V_23 ] -> V_38 ;
int V_72 ;
struct V_73 V_74 ;
unsigned int V_75 ;
if ( F_48 ( ! V_38 ) ) {
F_44 ( F_2 ( V_3 -> V_4 ) ,
L_14 ,
( V_67 ? L_15 : L_16 ) ) ;
return - V_76 ;
}
V_74 . V_77 = * V_69 ;
V_75 = F_49 () ;
do {
V_38 -> V_78 -> V_79 = V_34 | V_80 ;
V_74 . V_81 = NULL ;
V_74 . V_82 = 0 ;
V_74 . V_83 = NULL ;
V_74 . V_84 = 0 ;
V_74 . V_70 = V_70 | V_85 ;
if ( V_67 )
V_72 = F_50 ( V_38 , & V_74 ) ;
else
V_72 = F_51 ( V_38 , & V_74 , V_74 . V_70 ) ;
if ( V_72 <= 0 ) {
if ( V_72 == 0 )
V_72 = - V_86 ;
break;
}
if ( V_42 )
* V_42 += V_72 ;
} while ( F_52 ( & V_74 ) );
F_53 ( V_75 ) ;
return V_72 ;
}
static int F_54 ( struct V_2 * V_3 , struct V_51 * V_5 , int V_23 )
{
struct V_49 * V_50 = F_55 ( V_5 ) ;
struct V_24 * V_25 = V_3 -> V_25 ;
struct V_29 * V_30 = V_25 -> V_55 [ V_23 ] ;
int V_72 ;
struct V_87 V_49 = { . V_88 = F_56 (NBD_REQUEST_MAGIC) } ;
struct V_89 V_90 = { . V_91 = & V_49 , . V_92 = sizeof( V_49 ) } ;
struct V_68 V_93 ;
unsigned long V_94 = F_57 ( V_50 ) ;
struct V_95 * V_95 ;
T_3 type ;
T_3 V_96 = F_58 ( V_50 ) ;
int V_42 = V_30 -> V_42 , V_97 = 0 ;
F_59 ( & V_93 , V_98 | V_99 , & V_90 , 1 , sizeof( V_49 ) ) ;
switch ( F_60 ( V_50 ) ) {
case V_100 :
type = V_10 ;
break;
case V_101 :
type = V_9 ;
break;
case V_102 :
type = V_7 ;
break;
case V_103 :
type = V_6 ;
break;
default:
return - V_60 ;
}
if ( F_61 ( V_50 ) == V_98 &&
( V_25 -> V_104 & V_105 ) ) {
F_44 ( F_2 ( V_3 -> V_4 ) ,
L_17 ) ;
return - V_60 ;
}
if ( V_42 ) {
if ( V_42 >= sizeof( V_49 ) ) {
V_97 = V_42 - sizeof( V_49 ) ;
goto V_106;
}
F_62 ( & V_93 , V_42 ) ;
}
V_5 -> V_23 = V_23 ;
V_5 -> V_64 = V_30 -> V_64 ;
V_49 . type = F_56 ( type ) ;
if ( type != V_9 ) {
V_49 . V_93 = F_63 ( ( V_107 ) F_64 ( V_50 ) << 9 ) ;
V_49 . V_108 = F_56 ( V_94 ) ;
}
memcpy ( V_49 . V_109 , & V_96 , sizeof( V_96 ) ) ;
F_34 ( F_1 ( V_3 ) , L_18 ,
V_5 , F_3 ( type ) ,
( unsigned long long ) F_64 ( V_50 ) << 9 , F_57 ( V_50 ) ) ;
V_72 = F_47 ( V_3 , V_23 , 1 , & V_93 ,
( type == V_7 ) ? V_110 : 0 , & V_42 ) ;
if ( V_72 <= 0 ) {
if ( V_72 == - V_111 ) {
if ( V_42 ) {
V_30 -> V_41 = V_50 ;
V_30 -> V_42 = V_42 ;
}
return V_112 ;
}
F_44 ( F_2 ( V_3 -> V_4 ) ,
L_19 , V_72 ) ;
return - V_113 ;
}
V_106:
if ( type != V_7 )
goto V_114;
V_95 = V_50 -> V_95 ;
while ( V_95 ) {
struct V_95 * V_115 = V_95 -> V_116 ;
struct V_117 V_69 ;
struct V_118 V_119 ;
F_65 (bvec, bio, iter) {
bool V_120 = ! V_115 && F_66 ( V_119 , V_69 ) ;
int V_104 = V_120 ? 0 : V_110 ;
F_34 ( F_1 ( V_3 ) , L_20 ,
V_5 , V_119 . V_121 ) ;
F_67 ( & V_93 , V_122 | V_98 ,
& V_119 , 1 , V_119 . V_121 ) ;
if ( V_97 ) {
if ( V_97 >= F_68 ( & V_93 ) ) {
V_97 -= F_68 ( & V_93 ) ;
continue;
}
F_62 ( & V_93 , V_97 ) ;
V_97 = 0 ;
}
V_72 = F_47 ( V_3 , V_23 , 1 , & V_93 , V_104 , & V_42 ) ;
if ( V_72 <= 0 ) {
if ( V_72 == - V_111 ) {
V_30 -> V_41 = V_50 ;
V_30 -> V_42 = V_42 ;
return V_112 ;
}
F_69 ( F_2 ( V_3 -> V_4 ) ,
L_21 ,
V_72 ) ;
return - V_113 ;
}
if ( V_120 )
break;
}
V_95 = V_115 ;
}
V_114:
V_30 -> V_41 = NULL ;
V_30 -> V_42 = 0 ;
return 0 ;
}
static struct V_51 * F_70 ( struct V_2 * V_3 , int V_23 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
int V_72 ;
struct V_123 V_124 ;
struct V_51 * V_5 ;
struct V_49 * V_50 = NULL ;
T_4 V_125 ;
T_3 V_96 ;
struct V_89 V_90 = { . V_91 = & V_124 , . V_92 = sizeof( V_124 ) } ;
struct V_68 V_126 ;
V_124 . V_88 = 0 ;
F_59 ( & V_126 , V_127 | V_99 , & V_90 , 1 , sizeof( V_124 ) ) ;
V_72 = F_47 ( V_3 , V_23 , 0 , & V_126 , V_128 , NULL ) ;
if ( V_72 <= 0 ) {
if ( ! F_17 ( V_25 ) )
F_69 ( F_2 ( V_3 -> V_4 ) ,
L_22 , V_72 ) ;
return F_71 ( V_72 ) ;
}
if ( F_72 ( V_124 . V_88 ) != V_129 ) {
F_69 ( F_2 ( V_3 -> V_4 ) , L_23 ,
( unsigned long ) F_72 ( V_124 . V_88 ) ) ;
return F_71 ( - V_130 ) ;
}
memcpy ( & V_96 , V_124 . V_109 , sizeof( T_3 ) ) ;
V_125 = F_73 ( V_96 ) ;
if ( V_125 < V_3 -> V_19 . V_131 )
V_50 = F_74 ( V_3 -> V_19 . V_132 [ V_125 ] ,
F_75 ( V_96 ) ) ;
if ( ! V_50 || ! F_76 ( V_50 ) ) {
F_69 ( F_2 ( V_3 -> V_4 ) , L_24 ,
V_96 , V_50 ) ;
return F_71 ( - V_133 ) ;
}
V_5 = F_33 ( V_50 ) ;
if ( F_72 ( V_124 . error ) ) {
F_69 ( F_2 ( V_3 -> V_4 ) , L_25 ,
F_72 ( V_124 . error ) ) ;
V_5 -> V_52 = - V_60 ;
return V_5 ;
}
F_34 ( F_1 ( V_3 ) , L_26 , V_5 ) ;
if ( F_61 ( V_50 ) != V_98 ) {
struct V_134 V_69 ;
struct V_118 V_119 ;
F_77 (bvec, req, iter) {
F_67 ( & V_126 , V_122 | V_127 ,
& V_119 , 1 , V_119 . V_121 ) ;
V_72 = F_47 ( V_3 , V_23 , 0 , & V_126 , V_128 , NULL ) ;
if ( V_72 <= 0 ) {
F_69 ( F_2 ( V_3 -> V_4 ) , L_27 ,
V_72 ) ;
if ( F_17 ( V_25 ) ||
V_25 -> V_54 <= 1 ) {
V_5 -> V_52 = - V_60 ;
return V_5 ;
}
return F_71 ( - V_60 ) ;
}
F_34 ( F_1 ( V_3 ) , L_28 ,
V_5 , V_119 . V_121 ) ;
}
} else {
F_78 ( & V_5 -> V_62 ) ;
}
return V_5 ;
}
static void F_79 ( struct V_135 * V_35 )
{
struct V_136 * args = F_80 ( V_35 ,
struct V_136 ,
V_35 ) ;
struct V_2 * V_3 = args -> V_3 ;
struct V_24 * V_25 = V_3 -> V_25 ;
struct V_51 * V_5 ;
int V_137 = 0 ;
while ( 1 ) {
V_5 = F_70 ( V_3 , args -> V_23 ) ;
if ( F_81 ( V_5 ) ) {
struct V_29 * V_30 = V_25 -> V_55 [ args -> V_23 ] ;
F_38 ( & V_30 -> V_56 ) ;
F_19 ( V_3 , V_30 , 1 ) ;
F_16 ( & V_30 -> V_56 ) ;
V_137 = F_82 ( V_5 ) ;
break;
}
F_83 ( F_55 ( V_5 ) ) ;
}
F_24 ( & V_25 -> V_138 ) ;
F_84 ( & V_25 -> V_139 ) ;
F_43 ( V_3 ) ;
F_12 ( args ) ;
}
static void F_85 ( struct V_49 * V_50 , void * V_140 , bool V_58 )
{
struct V_51 * V_5 ;
if ( ! F_76 ( V_50 ) )
return;
V_5 = F_33 ( V_50 ) ;
V_5 -> V_52 = - V_60 ;
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
int V_141 = - 1 ;
struct V_29 * V_30 = V_25 -> V_55 [ V_23 ] ;
int V_142 = V_30 -> V_143 ;
if ( F_18 ( V_26 , & V_25 -> V_27 ) )
return V_141 ;
if ( V_25 -> V_54 <= 1 ) {
F_44 ( F_2 ( V_3 -> V_4 ) ,
L_30 ) ;
return V_141 ;
}
if ( V_142 >= 0 && V_142 < V_25 -> V_54 &&
! V_25 -> V_55 [ V_142 ] -> V_32 )
return V_142 ;
if ( V_30 -> V_143 < 0 ||
V_30 -> V_143 >= V_25 -> V_54 ||
V_25 -> V_55 [ V_30 -> V_143 ] -> V_32 ) {
int V_53 ;
for ( V_53 = 0 ; V_53 < V_25 -> V_54 ; V_53 ++ ) {
if ( V_53 == V_23 )
continue;
if ( ! V_25 -> V_55 [ V_53 ] -> V_32 ) {
V_141 = V_53 ;
break;
}
}
V_30 -> V_143 = V_141 ;
if ( V_141 < 0 ) {
F_44 ( F_2 ( V_3 -> V_4 ) ,
L_31 ) ;
return V_141 ;
}
}
V_141 = V_30 -> V_143 ;
return V_141 ;
}
static int F_91 ( struct V_2 * V_3 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
if ( ! V_25 -> V_144 )
return 0 ;
if ( F_18 ( V_26 , & V_25 -> V_27 ) )
return 0 ;
F_92 ( V_25 -> V_145 ,
F_93 ( & V_25 -> V_40 ) ,
V_25 -> V_144 ) ;
return F_93 ( & V_25 -> V_40 ) ;
}
static int F_94 ( struct V_51 * V_5 , int V_23 )
{
struct V_49 * V_50 = F_55 ( V_5 ) ;
struct V_2 * V_3 = V_5 -> V_3 ;
struct V_24 * V_25 ;
struct V_29 * V_30 ;
int V_137 ;
if ( ! F_41 ( & V_3 -> V_59 ) ) {
F_44 ( F_2 ( V_3 -> V_4 ) ,
L_32 ) ;
return - V_76 ;
}
V_25 = V_3 -> V_25 ;
if ( V_23 >= V_25 -> V_54 ) {
F_44 ( F_2 ( V_3 -> V_4 ) ,
L_30 ) ;
F_43 ( V_3 ) ;
return - V_76 ;
}
V_5 -> V_52 = 0 ;
V_146:
V_30 = V_25 -> V_55 [ V_23 ] ;
F_38 ( & V_30 -> V_56 ) ;
if ( V_30 -> V_32 ) {
int V_147 = V_23 ;
V_23 = F_90 ( V_3 , V_23 ) ;
F_16 ( & V_30 -> V_56 ) ;
if ( V_23 < 0 ) {
if ( F_91 ( V_3 ) ) {
V_23 = V_147 ;
goto V_146;
}
F_36 ( V_3 ) ;
F_43 ( V_3 ) ;
return - V_60 ;
}
goto V_146;
}
if ( F_48 ( V_30 -> V_41 && V_30 -> V_41 != V_50 ) ) {
F_45 ( V_50 , true ) ;
V_137 = 0 ;
goto V_114;
}
V_137 = F_54 ( V_3 , V_5 , V_23 ) ;
if ( V_137 == - V_113 ) {
F_44 ( F_2 ( V_3 -> V_4 ) ,
L_33 ) ;
F_19 ( V_3 , V_30 , 1 ) ;
F_16 ( & V_30 -> V_56 ) ;
goto V_146;
}
V_114:
F_16 ( & V_30 -> V_56 ) ;
F_43 ( V_3 ) ;
return V_137 ;
}
static int F_95 ( struct V_148 * V_149 ,
const struct V_150 * V_151 )
{
struct V_51 * V_5 = F_33 ( V_151 -> V_152 ) ;
int V_137 ;
F_96 ( & V_5 -> V_62 ) ;
F_97 ( V_151 -> V_152 ) ;
V_137 = F_94 ( V_5 , V_149 -> V_153 ) ;
if ( V_137 < 0 )
V_137 = V_154 ;
if ( ! V_137 )
V_137 = V_155 ;
F_98 ( & V_5 -> V_62 ) ;
return V_137 ;
}
static int F_99 ( struct V_2 * V_3 , unsigned long V_156 ,
bool V_157 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
struct V_71 * V_38 ;
struct V_29 * * V_55 ;
struct V_29 * V_30 ;
int V_158 ;
V_38 = F_100 ( V_156 , & V_158 ) ;
if ( ! V_38 )
return V_158 ;
if ( ! V_157 && ! V_3 -> V_159 &&
! F_18 ( V_160 , & V_25 -> V_27 ) )
V_3 -> V_159 = V_161 ;
if ( ! V_157 &&
( V_3 -> V_159 != V_161 ||
F_18 ( V_160 , & V_25 -> V_27 ) ) ) {
F_69 ( F_2 ( V_3 -> V_4 ) ,
L_34 ) ;
F_101 ( V_38 ) ;
return - V_162 ;
}
V_55 = F_102 ( V_25 -> V_55 , ( V_25 -> V_54 + 1 ) *
sizeof( struct V_29 * ) , V_163 ) ;
if ( ! V_55 ) {
F_101 ( V_38 ) ;
return - V_164 ;
}
V_30 = F_103 ( sizeof( struct V_29 ) , V_163 ) ;
if ( ! V_30 ) {
F_101 ( V_38 ) ;
return - V_164 ;
}
V_25 -> V_55 = V_55 ;
V_30 -> V_143 = - 1 ;
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
static int F_106 ( struct V_2 * V_3 , unsigned long V_156 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
struct V_71 * V_38 , * V_165 ;
struct V_136 * args ;
int V_53 ;
int V_158 ;
V_38 = F_100 ( V_156 , & V_158 ) ;
if ( ! V_38 )
return V_158 ;
args = F_103 ( sizeof( * args ) , V_163 ) ;
if ( ! args ) {
F_101 ( V_38 ) ;
return - V_164 ;
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
F_107 ( V_38 -> V_78 ) ;
F_105 ( & V_25 -> V_138 ) ;
F_108 ( & V_3 -> V_59 ) ;
V_165 = V_30 -> V_38 ;
V_30 -> V_143 = - 1 ;
V_30 -> V_38 = V_38 ;
V_30 -> V_32 = false ;
F_21 ( & args -> V_35 , F_79 ) ;
args -> V_23 = V_53 ;
args -> V_3 = V_3 ;
V_30 -> V_64 ++ ;
F_16 ( & V_30 -> V_56 ) ;
F_101 ( V_165 ) ;
F_22 ( V_166 , & args -> V_35 ) ;
F_105 ( & V_25 -> V_40 ) ;
F_84 ( & V_25 -> V_145 ) ;
return 0 ;
}
F_101 ( V_38 ) ;
F_12 ( args ) ;
return - V_167 ;
}
static void F_109 ( struct V_168 * V_169 )
{
if ( V_169 -> V_170 > 1 )
return;
F_110 ( V_169 , 0 ) ;
if ( V_171 > 0 ) {
F_111 ( V_169 ) ;
V_169 -> V_172 = 1 ;
}
}
static void F_112 ( struct V_2 * V_3 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
if ( V_25 -> V_104 & V_105 )
F_113 ( V_3 -> V_4 , true ) ;
else
F_113 ( V_3 -> V_4 , false ) ;
if ( V_25 -> V_104 & V_173 )
F_114 ( V_174 , V_3 -> V_4 -> V_18 ) ;
if ( V_25 -> V_104 & V_175 )
F_115 ( V_3 -> V_4 -> V_18 , true , false ) ;
else
F_115 ( V_3 -> V_4 -> V_18 , false , false ) ;
}
static void F_116 ( struct V_2 * V_3 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
struct V_87 V_49 = {
. V_88 = F_56 ( V_176 ) ,
. type = F_56 ( V_8 ) ,
} ;
struct V_89 V_90 = { . V_91 = & V_49 , . V_92 = sizeof( V_49 ) } ;
struct V_68 V_93 ;
int V_53 , V_137 ;
for ( V_53 = 0 ; V_53 < V_25 -> V_54 ; V_53 ++ ) {
F_59 ( & V_93 , V_98 | V_99 , & V_90 , 1 , sizeof( V_49 ) ) ;
V_137 = F_47 ( V_3 , V_53 , 1 , & V_93 , 0 , NULL ) ;
if ( V_137 <= 0 )
F_69 ( F_2 ( V_3 -> V_4 ) ,
L_35 , V_137 ) ;
}
}
static int F_117 ( struct V_2 * V_3 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
F_118 ( F_2 ( V_3 -> V_4 ) , L_36 ) ;
if ( ! F_37 ( V_28 ,
& V_25 -> V_27 ) )
F_116 ( V_3 ) ;
return 0 ;
}
static void F_119 ( struct V_2 * V_3 )
{
F_36 ( V_3 ) ;
F_86 ( V_3 ) ;
V_3 -> V_159 = NULL ;
}
static void F_43 ( struct V_2 * V_3 )
{
if ( F_14 ( & V_3 -> V_59 ,
& V_3 -> V_177 ) ) {
struct V_24 * V_25 = V_3 -> V_25 ;
F_120 ( V_3 ) ;
F_25 ( V_3 ) ;
if ( F_121 ( V_178 ,
& V_25 -> V_27 ) )
F_122 ( F_2 ( V_3 -> V_4 ) , & V_179 ) ;
V_3 -> V_17 = NULL ;
F_119 ( V_3 ) ;
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
V_3 -> V_19 . V_180 = 0 ;
F_123 ( V_174 , V_3 -> V_4 -> V_18 ) ;
F_16 ( & V_3 -> V_177 ) ;
F_13 ( V_3 ) ;
F_124 ( V_181 ) ;
}
}
static int F_125 ( struct V_2 * V_3 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
int V_54 = V_25 -> V_54 ;
int error = 0 , V_53 ;
if ( V_3 -> V_17 )
return - V_162 ;
if ( ! V_25 -> V_55 )
return - V_76 ;
if ( V_54 > 1 &&
! ( V_25 -> V_104 & V_182 ) ) {
F_69 ( F_2 ( V_3 -> V_4 ) , L_37 ) ;
return - V_76 ;
}
F_126 ( & V_3 -> V_19 , V_25 -> V_54 ) ;
V_3 -> V_17 = V_161 ;
F_112 ( V_3 ) ;
error = F_127 ( F_2 ( V_3 -> V_4 ) , & V_179 ) ;
if ( error ) {
F_69 ( F_2 ( V_3 -> V_4 ) , L_38 ) ;
return error ;
}
F_46 ( V_178 , & V_25 -> V_27 ) ;
F_128 ( V_3 ) ;
for ( V_53 = 0 ; V_53 < V_54 ; V_53 ++ ) {
struct V_136 * args ;
args = F_103 ( sizeof( * args ) , V_163 ) ;
if ( ! args ) {
F_36 ( V_3 ) ;
return - V_164 ;
}
F_107 ( V_25 -> V_55 [ V_53 ] -> V_38 -> V_78 ) ;
F_105 ( & V_25 -> V_138 ) ;
F_108 ( & V_3 -> V_59 ) ;
F_21 ( & args -> V_35 , F_79 ) ;
args -> V_3 = V_3 ;
args -> V_23 = V_53 ;
F_22 ( V_166 , & args -> V_35 ) ;
}
return error ;
}
static int F_129 ( struct V_2 * V_3 , struct V_168 * V_169 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
int V_137 ;
V_137 = F_125 ( V_3 ) ;
if ( V_137 )
return V_137 ;
F_110 ( V_169 , V_25 -> V_43 ) ;
if ( V_171 )
V_169 -> V_172 = 1 ;
F_16 ( & V_3 -> V_177 ) ;
V_137 = F_130 ( V_25 -> V_139 ,
F_93 ( & V_25 -> V_138 ) == 0 ) ;
if ( V_137 )
F_36 ( V_3 ) ;
F_38 ( & V_3 -> V_177 ) ;
F_110 ( V_169 , 0 ) ;
if ( F_18 ( V_28 , & V_25 -> V_27 ) )
V_137 = 0 ;
if ( F_18 ( V_66 , & V_25 -> V_27 ) )
V_137 = - V_183 ;
return V_137 ;
}
static void F_131 ( struct V_2 * V_3 ,
struct V_168 * V_169 )
{
F_36 ( V_3 ) ;
F_132 ( V_169 ) ;
F_109 ( V_169 ) ;
if ( F_121 ( V_184 ,
& V_3 -> V_25 -> V_27 ) )
F_43 ( V_3 ) ;
}
static int F_133 ( struct V_168 * V_169 , struct V_2 * V_3 ,
unsigned int V_5 , unsigned long V_156 )
{
struct V_24 * V_25 = V_3 -> V_25 ;
switch ( V_5 ) {
case V_185 :
return F_117 ( V_3 ) ;
case V_186 :
F_131 ( V_3 , V_169 ) ;
return 0 ;
case V_187 :
return F_99 ( V_3 , V_156 , false ) ;
case V_188 :
F_31 ( V_3 , V_156 ,
F_134 ( V_25 -> V_43 , V_156 ) ) ;
return 0 ;
case V_189 :
F_31 ( V_3 , V_25 -> V_46 ,
F_134 ( V_156 , V_25 -> V_46 ) ) ;
return 0 ;
case V_190 :
F_31 ( V_3 , V_25 -> V_46 , V_156 ) ;
return 0 ;
case V_191 :
if ( V_156 ) {
V_3 -> V_19 . V_180 = V_156 * V_192 ;
F_135 ( V_3 -> V_4 -> V_18 , V_156 * V_192 ) ;
}
return 0 ;
case V_193 :
V_25 -> V_104 = V_156 ;
return 0 ;
case V_194 :
return F_129 ( V_3 , V_169 ) ;
case V_195 :
return 0 ;
case V_196 :
return 0 ;
}
return - V_197 ;
}
static int F_136 ( struct V_168 * V_169 , T_5 V_198 ,
unsigned int V_5 , unsigned long V_156 )
{
struct V_2 * V_3 = V_169 -> V_199 -> V_16 ;
struct V_24 * V_25 = V_3 -> V_25 ;
int error = - V_76 ;
if ( ! F_137 ( V_200 ) )
return - V_201 ;
F_38 ( & V_3 -> V_177 ) ;
if ( ! F_18 ( V_160 , & V_25 -> V_27 ) ||
( V_5 == V_185 || V_5 == V_186 ) )
error = F_133 ( V_169 , V_3 , V_5 , V_156 ) ;
else
F_69 ( F_1 ( V_3 ) , L_39 ) ;
F_16 ( & V_3 -> V_177 ) ;
return error ;
}
static struct V_24 * F_138 ( void )
{
struct V_24 * V_25 ;
V_25 = F_103 ( sizeof( struct V_24 ) , V_202 ) ;
if ( ! V_25 )
return NULL ;
F_139 ( & V_25 -> V_138 , 0 ) ;
F_140 ( & V_25 -> V_139 ) ;
F_140 ( & V_25 -> V_145 ) ;
V_25 -> V_46 = 1024 ;
F_139 ( & V_25 -> V_40 , 0 ) ;
F_141 ( V_181 ) ;
return V_25 ;
}
static int F_142 ( struct V_168 * V_169 , T_5 V_198 )
{
struct V_2 * V_3 ;
int V_137 = 0 ;
F_38 ( & V_21 ) ;
V_3 = V_169 -> V_199 -> V_16 ;
if ( ! V_3 ) {
V_137 = - V_203 ;
goto V_114;
}
if ( ! F_41 ( & V_3 -> V_20 ) ) {
V_137 = - V_203 ;
goto V_114;
}
if ( ! F_41 ( & V_3 -> V_59 ) ) {
struct V_24 * V_25 ;
F_38 ( & V_3 -> V_177 ) ;
if ( F_41 ( & V_3 -> V_59 ) ) {
F_16 ( & V_3 -> V_177 ) ;
goto V_114;
}
V_25 = V_3 -> V_25 = F_138 () ;
if ( ! V_25 ) {
V_137 = - V_164 ;
F_16 ( & V_3 -> V_177 ) ;
goto V_114;
}
F_143 ( & V_3 -> V_59 , 1 ) ;
F_108 ( & V_3 -> V_20 ) ;
F_16 ( & V_3 -> V_177 ) ;
}
V_114:
F_16 ( & V_21 ) ;
return V_137 ;
}
static void F_144 ( struct V_15 * V_4 , T_5 V_198 )
{
struct V_2 * V_3 = V_4 -> V_16 ;
F_43 ( V_3 ) ;
F_13 ( V_3 ) ;
}
static int F_145 ( struct V_204 * V_205 , void * V_206 )
{
struct V_2 * V_3 = V_205 -> V_207 ;
if ( V_3 -> V_17 )
F_146 ( V_205 , L_40 , F_6 ( V_3 -> V_17 ) ) ;
return 0 ;
}
static int F_147 ( struct V_208 * V_208 , struct V_209 * V_209 )
{
return F_148 ( V_209 , F_145 , V_208 -> V_210 ) ;
}
static int F_149 ( struct V_204 * V_205 , void * V_206 )
{
struct V_2 * V_3 = V_205 -> V_207 ;
T_3 V_104 = V_3 -> V_25 -> V_104 ;
F_146 ( V_205 , L_41 , V_104 ) ;
F_150 ( V_205 , L_42 ) ;
if ( V_104 & V_211 )
F_150 ( V_205 , L_43 ) ;
if ( V_104 & V_105 )
F_150 ( V_205 , L_44 ) ;
if ( V_104 & V_175 )
F_150 ( V_205 , L_45 ) ;
if ( V_104 & V_173 )
F_150 ( V_205 , L_46 ) ;
return 0 ;
}
static int F_151 ( struct V_208 * V_208 , struct V_209 * V_209 )
{
return F_148 ( V_209 , F_149 , V_208 -> V_210 ) ;
}
static int F_128 ( struct V_2 * V_3 )
{
struct V_212 * V_213 ;
struct V_24 * V_25 = V_3 -> V_25 ;
if ( ! V_214 )
return - V_60 ;
V_213 = F_152 ( F_153 ( V_3 ) , V_214 ) ;
if ( ! V_213 ) {
F_69 ( F_1 ( V_3 ) , L_47 ,
F_153 ( V_3 ) ) ;
return - V_60 ;
}
V_25 -> V_215 = V_213 ;
F_154 ( L_48 , 0444 , V_213 , V_3 , & V_216 ) ;
F_155 ( L_49 , 0444 , V_213 , & V_25 -> V_43 ) ;
F_156 ( L_50 , 0444 , V_213 , & V_3 -> V_19 . V_180 ) ;
F_155 ( L_51 , 0444 , V_213 , & V_25 -> V_46 ) ;
F_154 ( L_52 , 0444 , V_213 , V_3 , & V_217 ) ;
return 0 ;
}
static void F_120 ( struct V_2 * V_3 )
{
F_157 ( V_3 -> V_25 -> V_215 ) ;
}
static int F_158 ( void )
{
struct V_212 * V_215 ;
V_215 = F_152 ( L_53 , NULL ) ;
if ( ! V_215 )
return - V_60 ;
V_214 = V_215 ;
return 0 ;
}
static void F_159 ( void )
{
F_157 ( V_214 ) ;
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
static int F_160 ( struct V_218 * V_219 , struct V_49 * V_152 ,
unsigned int V_220 , unsigned int V_221 )
{
struct V_51 * V_5 = F_33 ( V_152 ) ;
V_5 -> V_3 = V_219 -> V_222 ;
return 0 ;
}
static int F_161 ( int V_23 )
{
struct V_2 * V_3 ;
struct V_15 * V_4 ;
struct V_223 * V_224 ;
int V_158 = - V_164 ;
V_3 = F_103 ( sizeof( struct V_2 ) , V_163 ) ;
if ( ! V_3 )
goto V_114;
V_4 = F_162 ( 1 << V_225 ) ;
if ( ! V_4 )
goto V_226;
if ( V_23 >= 0 ) {
V_158 = F_163 ( & V_22 , V_3 , V_23 , V_23 + 1 ,
V_163 ) ;
if ( V_158 == - V_167 )
V_158 = - V_227 ;
} else {
V_158 = F_163 ( & V_22 , V_3 , 0 , 0 , V_163 ) ;
if ( V_158 >= 0 )
V_23 = V_158 ;
}
if ( V_158 < 0 )
goto V_228;
V_3 -> V_23 = V_23 ;
V_3 -> V_4 = V_4 ;
V_3 -> V_19 . V_229 = & V_230 ;
V_3 -> V_19 . V_131 = 1 ;
V_3 -> V_19 . V_231 = 128 ;
V_3 -> V_19 . V_221 = V_232 ;
V_3 -> V_19 . V_233 = sizeof( struct V_51 ) ;
V_3 -> V_19 . V_104 = V_234 |
V_235 | V_236 ;
V_3 -> V_19 . V_222 = V_3 ;
V_158 = F_164 ( & V_3 -> V_19 ) ;
if ( V_158 )
goto V_237;
V_224 = F_165 ( & V_3 -> V_19 ) ;
if ( F_81 ( V_224 ) ) {
V_158 = F_82 ( V_224 ) ;
goto V_238;
}
V_4 -> V_18 = V_224 ;
F_114 ( V_239 , V_4 -> V_18 ) ;
F_123 ( V_240 , V_4 -> V_18 ) ;
V_4 -> V_18 -> V_241 . V_242 = 512 ;
F_166 ( V_4 -> V_18 , V_243 ) ;
F_167 ( V_4 -> V_18 , V_243 ) ;
F_168 ( V_4 -> V_18 , V_244 ) ;
F_169 ( V_4 -> V_18 , 65536 ) ;
V_4 -> V_18 -> V_241 . V_245 = 256 ;
F_104 ( & V_3 -> V_177 ) ;
F_143 ( & V_3 -> V_59 , 0 ) ;
F_143 ( & V_3 -> V_20 , 1 ) ;
F_170 ( & V_3 -> V_246 ) ;
V_4 -> V_247 = V_248 ;
V_4 -> V_249 = V_23 << V_225 ;
V_4 -> V_250 = & V_251 ;
V_4 -> V_16 = V_3 ;
sprintf ( V_4 -> V_252 , L_54 , V_23 ) ;
F_171 ( V_4 ) ;
V_253 ++ ;
return V_23 ;
V_238:
F_10 ( & V_3 -> V_19 ) ;
V_237:
F_15 ( & V_22 , V_23 ) ;
V_228:
F_11 ( V_4 ) ;
V_226:
F_12 ( V_3 ) ;
V_114:
return V_158 ;
}
static int F_172 ( int V_254 , void * V_255 , void * V_140 )
{
struct V_2 * V_3 = V_255 ;
struct V_2 * * V_256 = V_140 ;
if ( ! F_173 ( & V_3 -> V_59 ) ) {
* V_256 = V_3 ;
return 1 ;
}
return 0 ;
}
static int F_174 ( struct V_257 * V_258 , struct V_259 * V_260 )
{
struct V_2 * V_3 = NULL ;
struct V_24 * V_25 ;
int V_23 = - 1 ;
int V_137 ;
bool V_261 = false ;
if ( ! F_175 ( V_258 , V_200 ) )
return - V_201 ;
if ( V_260 -> V_262 [ V_263 ] )
V_23 = F_176 ( V_260 -> V_262 [ V_263 ] ) ;
if ( ! V_260 -> V_262 [ V_264 ] ) {
F_177 ( V_265 L_55 ) ;
return - V_76 ;
}
if ( ! V_260 -> V_262 [ V_266 ] ) {
F_177 ( V_265 L_56 ) ;
return - V_76 ;
}
V_146:
F_38 ( & V_21 ) ;
if ( V_23 == - 1 ) {
V_137 = F_178 ( & V_22 , & F_172 , & V_3 ) ;
if ( V_137 == 0 ) {
int V_141 ;
V_141 = F_161 ( - 1 ) ;
if ( V_141 < 0 ) {
F_16 ( & V_21 ) ;
F_177 ( V_265 L_57 ) ;
return V_137 ;
}
V_3 = F_179 ( & V_22 , V_141 ) ;
}
} else {
V_3 = F_179 ( & V_22 , V_23 ) ;
}
if ( ! V_3 ) {
F_177 ( V_265 L_58 ,
V_23 ) ;
F_16 ( & V_21 ) ;
return - V_76 ;
}
if ( ! F_41 ( & V_3 -> V_20 ) ) {
F_16 ( & V_21 ) ;
if ( V_23 == - 1 )
goto V_146;
F_177 ( V_265 L_59 ,
V_23 ) ;
return - V_76 ;
}
F_16 ( & V_21 ) ;
F_38 ( & V_3 -> V_177 ) ;
if ( F_173 ( & V_3 -> V_59 ) ) {
F_16 ( & V_3 -> V_177 ) ;
F_13 ( V_3 ) ;
if ( V_23 == - 1 )
goto V_146;
F_177 ( V_265 L_60 , V_23 ) ;
return - V_162 ;
}
if ( F_180 ( V_3 -> V_25 ) ) {
F_16 ( & V_3 -> V_177 ) ;
F_13 ( V_3 ) ;
return - V_76 ;
}
V_25 = V_3 -> V_25 = F_138 () ;
if ( ! V_3 -> V_25 ) {
F_16 ( & V_3 -> V_177 ) ;
F_13 ( V_3 ) ;
F_177 ( V_265 L_61 ) ;
return - V_164 ;
}
F_143 ( & V_3 -> V_59 , 1 ) ;
F_46 ( V_160 , & V_25 -> V_27 ) ;
if ( V_260 -> V_262 [ V_266 ] ) {
V_107 V_267 = F_181 ( V_260 -> V_262 [ V_266 ] ) ;
F_31 ( V_3 , V_25 -> V_46 ,
F_182 ( V_267 , V_25 -> V_46 ) ) ;
}
if ( V_260 -> V_262 [ V_268 ] ) {
V_107 V_269 =
F_181 ( V_260 -> V_262 [ V_268 ] ) ;
F_31 ( V_3 , V_269 , F_182 ( V_25 -> V_43 , V_269 ) ) ;
}
if ( V_260 -> V_262 [ V_270 ] ) {
V_107 V_180 = F_181 ( V_260 -> V_262 [ V_270 ] ) ;
V_3 -> V_19 . V_180 = V_180 * V_192 ;
F_135 ( V_3 -> V_4 -> V_18 , V_180 * V_192 ) ;
}
if ( V_260 -> V_262 [ V_271 ] ) {
V_25 -> V_144 =
F_181 ( V_260 -> V_262 [ V_271 ] ) ;
V_25 -> V_144 *= V_192 ;
}
if ( V_260 -> V_262 [ V_272 ] )
V_25 -> V_104 =
F_181 ( V_260 -> V_262 [ V_272 ] ) ;
if ( V_260 -> V_262 [ V_273 ] ) {
V_107 V_104 = F_181 ( V_260 -> V_262 [ V_273 ] ) ;
if ( V_104 & V_274 ) {
F_46 ( V_275 ,
& V_25 -> V_27 ) ;
V_261 = true ;
}
}
if ( V_260 -> V_262 [ V_264 ] ) {
struct V_276 * V_13 ;
int V_277 , V_278 ;
F_183 (attr, info->attrs[NBD_ATTR_SOCKETS],
rem) {
struct V_276 * V_55 [ V_279 + 1 ] ;
if ( F_184 ( V_13 ) != V_280 ) {
F_177 ( V_265 L_62 ) ;
V_137 = - V_76 ;
goto V_114;
}
V_137 = F_185 ( V_55 , V_279 , V_13 ,
V_281 , V_260 -> V_282 ) ;
if ( V_137 != 0 ) {
F_177 ( V_265 L_63 ) ;
V_137 = - V_76 ;
goto V_114;
}
if ( ! V_55 [ V_283 ] )
continue;
V_278 = ( int ) F_176 ( V_55 [ V_283 ] ) ;
V_137 = F_99 ( V_3 , V_278 , true ) ;
if ( V_137 )
goto V_114;
}
}
V_137 = F_125 ( V_3 ) ;
V_114:
F_16 ( & V_3 -> V_177 ) ;
if ( ! V_137 ) {
F_46 ( V_184 , & V_25 -> V_27 ) ;
F_108 ( & V_3 -> V_59 ) ;
F_186 ( V_260 , V_3 -> V_23 ) ;
}
F_43 ( V_3 ) ;
if ( V_261 )
F_13 ( V_3 ) ;
return V_137 ;
}
static int F_187 ( struct V_257 * V_258 , struct V_259 * V_260 )
{
struct V_2 * V_3 ;
int V_23 ;
if ( ! F_175 ( V_258 , V_200 ) )
return - V_201 ;
if ( ! V_260 -> V_262 [ V_263 ] ) {
F_177 ( V_265 L_64 ) ;
return - V_76 ;
}
V_23 = F_176 ( V_260 -> V_262 [ V_263 ] ) ;
F_38 ( & V_21 ) ;
V_3 = F_179 ( & V_22 , V_23 ) ;
if ( ! V_3 ) {
F_16 ( & V_21 ) ;
F_177 ( V_265 L_58 ,
V_23 ) ;
return - V_76 ;
}
if ( ! F_41 ( & V_3 -> V_20 ) ) {
F_16 ( & V_21 ) ;
F_177 ( V_265 L_59 ,
V_23 ) ;
return - V_76 ;
}
F_16 ( & V_21 ) ;
if ( ! F_41 ( & V_3 -> V_59 ) ) {
F_13 ( V_3 ) ;
return 0 ;
}
F_38 ( & V_3 -> V_177 ) ;
F_117 ( V_3 ) ;
F_16 ( & V_3 -> V_177 ) ;
if ( F_121 ( V_184 ,
& V_3 -> V_25 -> V_27 ) )
F_43 ( V_3 ) ;
F_43 ( V_3 ) ;
F_13 ( V_3 ) ;
return 0 ;
}
static int F_188 ( struct V_257 * V_258 , struct V_259 * V_260 )
{
struct V_2 * V_3 = NULL ;
struct V_24 * V_25 ;
int V_23 ;
int V_137 = - V_76 ;
bool V_261 = false ;
if ( ! F_175 ( V_258 , V_200 ) )
return - V_201 ;
if ( ! V_260 -> V_262 [ V_263 ] ) {
F_177 ( V_265 L_65 ) ;
return - V_76 ;
}
V_23 = F_176 ( V_260 -> V_262 [ V_263 ] ) ;
F_38 ( & V_21 ) ;
V_3 = F_179 ( & V_22 , V_23 ) ;
if ( ! V_3 ) {
F_16 ( & V_21 ) ;
F_177 ( V_265 L_66 ,
V_23 ) ;
return - V_76 ;
}
if ( ! F_41 ( & V_3 -> V_20 ) ) {
F_16 ( & V_21 ) ;
F_177 ( V_265 L_59 ,
V_23 ) ;
return - V_76 ;
}
F_16 ( & V_21 ) ;
if ( ! F_41 ( & V_3 -> V_59 ) ) {
F_69 ( F_1 ( V_3 ) ,
L_67 ) ;
F_13 ( V_3 ) ;
return - V_76 ;
}
F_38 ( & V_3 -> V_177 ) ;
V_25 = V_3 -> V_25 ;
if ( ! F_18 ( V_160 , & V_25 -> V_27 ) ||
! V_3 -> V_17 ) {
F_69 ( F_1 ( V_3 ) ,
L_67 ) ;
goto V_114;
}
if ( V_260 -> V_262 [ V_270 ] ) {
V_107 V_180 = F_181 ( V_260 -> V_262 [ V_270 ] ) ;
V_3 -> V_19 . V_180 = V_180 * V_192 ;
F_135 ( V_3 -> V_4 -> V_18 , V_180 * V_192 ) ;
}
if ( V_260 -> V_262 [ V_271 ] ) {
V_25 -> V_144 =
F_181 ( V_260 -> V_262 [ V_271 ] ) ;
V_25 -> V_144 *= V_192 ;
}
if ( V_260 -> V_262 [ V_273 ] ) {
V_107 V_104 = F_181 ( V_260 -> V_262 [ V_273 ] ) ;
if ( V_104 & V_274 ) {
if ( ! F_37 ( V_275 ,
& V_25 -> V_27 ) )
V_261 = true ;
} else {
if ( F_121 ( V_275 ,
& V_25 -> V_27 ) )
F_108 ( & V_3 -> V_20 ) ;
}
}
if ( V_260 -> V_262 [ V_264 ] ) {
struct V_276 * V_13 ;
int V_277 , V_278 ;
F_183 (attr, info->attrs[NBD_ATTR_SOCKETS],
rem) {
struct V_276 * V_55 [ V_279 + 1 ] ;
if ( F_184 ( V_13 ) != V_280 ) {
F_177 ( V_265 L_62 ) ;
V_137 = - V_76 ;
goto V_114;
}
V_137 = F_185 ( V_55 , V_279 , V_13 ,
V_281 , V_260 -> V_282 ) ;
if ( V_137 != 0 ) {
F_177 ( V_265 L_63 ) ;
V_137 = - V_76 ;
goto V_114;
}
if ( ! V_55 [ V_283 ] )
continue;
V_278 = ( int ) F_176 ( V_55 [ V_283 ] ) ;
V_137 = F_106 ( V_3 , V_278 ) ;
if ( V_137 ) {
if ( V_137 == - V_167 )
V_137 = 0 ;
goto V_114;
}
F_118 ( F_1 ( V_3 ) , L_68 ) ;
}
}
V_114:
F_16 ( & V_3 -> V_177 ) ;
F_43 ( V_3 ) ;
F_13 ( V_3 ) ;
if ( V_261 )
F_13 ( V_3 ) ;
return V_137 ;
}
static int F_189 ( struct V_2 * V_3 , struct V_257 * V_124 )
{
struct V_276 * V_284 ;
T_6 V_285 = 0 ;
int V_137 ;
if ( F_173 ( & V_3 -> V_59 ) )
V_285 = 1 ;
V_284 = F_190 ( V_124 , V_286 ) ;
if ( ! V_284 )
return - V_287 ;
V_137 = F_191 ( V_124 , V_288 , V_3 -> V_23 ) ;
if ( V_137 )
return - V_287 ;
V_137 = F_192 ( V_124 , V_289 ,
V_285 ) ;
if ( V_137 )
return - V_287 ;
F_193 ( V_124 , V_284 ) ;
return 0 ;
}
static int F_194 ( int V_254 , void * V_255 , void * V_140 )
{
struct V_2 * V_3 = V_255 ;
return F_189 ( V_3 , (struct V_257 * ) V_140 ) ;
}
static int F_195 ( struct V_257 * V_258 , struct V_259 * V_260 )
{
struct V_276 * V_290 ;
struct V_257 * V_124 ;
void * V_291 ;
T_7 V_292 ;
int V_23 = - 1 ;
int V_137 = - V_164 ;
if ( V_260 -> V_262 [ V_263 ] )
V_23 = F_176 ( V_260 -> V_262 [ V_263 ] ) ;
F_38 ( & V_21 ) ;
V_292 = F_196 ( F_197 ( sizeof( T_3 ) ) +
F_197 ( sizeof( T_6 ) ) ) ;
V_292 *= ( V_23 == - 1 ) ? V_253 : 1 ;
V_124 = F_198 ( V_292 , V_163 ) ;
if ( ! V_124 )
goto V_114;
V_291 = F_199 ( V_124 , V_260 , & V_293 , 0 ,
V_294 ) ;
if ( ! V_291 ) {
F_200 ( V_124 ) ;
goto V_114;
}
V_290 = F_190 ( V_124 , V_295 ) ;
if ( V_23 == - 1 ) {
V_137 = F_178 ( & V_22 , & F_194 , V_124 ) ;
if ( V_137 ) {
F_200 ( V_124 ) ;
goto V_114;
}
} else {
struct V_2 * V_3 ;
V_3 = F_179 ( & V_22 , V_23 ) ;
if ( V_3 ) {
V_137 = F_189 ( V_3 , V_124 ) ;
if ( V_137 ) {
F_200 ( V_124 ) ;
goto V_114;
}
}
}
F_193 ( V_124 , V_290 ) ;
F_201 ( V_124 , V_291 ) ;
F_202 ( V_124 , V_260 ) ;
V_137 = 0 ;
V_114:
F_16 ( & V_21 ) ;
return V_137 ;
}
static void F_186 ( struct V_259 * V_260 , int V_23 )
{
struct V_257 * V_258 ;
void * V_296 ;
int V_137 ;
V_258 = F_198 ( F_196 ( sizeof( T_3 ) ) , V_163 ) ;
if ( ! V_258 )
return;
V_296 = F_199 ( V_258 , V_260 , & V_293 , 0 ,
V_297 ) ;
if ( ! V_296 ) {
F_200 ( V_258 ) ;
return;
}
V_137 = F_191 ( V_258 , V_263 , V_23 ) ;
if ( V_137 ) {
F_200 ( V_258 ) ;
return;
}
F_201 ( V_258 , V_296 ) ;
F_202 ( V_258 , V_260 ) ;
}
static void F_203 ( int V_23 )
{
struct V_257 * V_258 ;
void * V_296 ;
int V_137 ;
V_258 = F_198 ( F_196 ( sizeof( T_3 ) ) , V_163 ) ;
if ( ! V_258 )
return;
V_296 = F_204 ( V_258 , 0 , 0 , & V_293 , 0 ,
V_298 ) ;
if ( ! V_296 ) {
F_200 ( V_258 ) ;
return;
}
V_137 = F_191 ( V_258 , V_263 , V_23 ) ;
if ( V_137 ) {
F_200 ( V_258 ) ;
return;
}
F_201 ( V_258 , V_296 ) ;
F_205 ( & V_293 , V_258 , 0 , 0 , V_163 ) ;
}
static void V_36 ( struct V_135 * V_35 )
{
struct V_33 * args = F_80 ( V_35 , struct V_33 ,
V_35 ) ;
F_203 ( args -> V_23 ) ;
F_12 ( args ) ;
}
static int T_8 F_206 ( void )
{
int V_53 ;
F_207 ( sizeof( struct V_87 ) != 28 ) ;
if ( V_171 < 0 ) {
F_177 ( V_265 L_69 ) ;
return - V_76 ;
}
V_225 = 0 ;
if ( V_171 > 0 ) {
V_225 = F_208 ( V_171 ) ;
V_171 = ( 1UL << V_225 ) - 1 ;
}
if ( ( 1UL << V_225 ) > V_299 )
return - V_76 ;
if ( V_300 > 1UL << ( V_301 - V_225 ) )
return - V_76 ;
V_166 = F_209 ( L_70 ,
V_302 | V_303 , 0 ) ;
if ( ! V_166 )
return - V_164 ;
if ( F_210 ( V_248 , L_53 ) ) {
F_211 ( V_166 ) ;
return - V_60 ;
}
if ( F_212 ( & V_293 ) ) {
F_213 ( V_248 , L_53 ) ;
F_211 ( V_166 ) ;
return - V_76 ;
}
F_158 () ;
F_38 ( & V_21 ) ;
for ( V_53 = 0 ; V_53 < V_300 ; V_53 ++ )
F_161 ( V_53 ) ;
F_16 ( & V_21 ) ;
return 0 ;
}
static int F_214 ( int V_254 , void * V_255 , void * V_140 )
{
struct V_304 * V_246 = (struct V_304 * ) V_140 ;
struct V_2 * V_3 = V_255 ;
F_215 ( & V_3 -> V_246 , V_246 ) ;
return 0 ;
}
static void T_9 F_216 ( void )
{
struct V_2 * V_3 ;
F_217 ( V_305 ) ;
F_159 () ;
F_38 ( & V_21 ) ;
F_178 ( & V_22 , & F_214 , & V_305 ) ;
F_16 ( & V_21 ) ;
while ( ! F_218 ( & V_305 ) ) {
V_3 = F_219 ( & V_305 , struct V_2 , V_246 ) ;
F_220 ( & V_3 -> V_246 ) ;
if ( F_173 ( & V_3 -> V_20 ) != 1 )
F_177 ( V_265 L_71 ) ;
F_13 ( V_3 ) ;
}
F_221 ( & V_22 ) ;
F_222 ( & V_293 ) ;
F_211 ( V_166 ) ;
F_213 ( V_248 , L_53 ) ;
}
