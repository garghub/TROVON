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
if ( V_13 -> V_14 <= 1 )
F_6 ( V_13 , 0 ) ;
F_7 ( V_3 -> V_4 , 0 ) ;
F_8 ( & F_1 ( V_3 ) -> V_15 , V_16 ) ;
return 0 ;
}
static void F_9 ( struct V_2 * V_3 , struct V_12 * V_13 )
{
F_10 ( V_3 -> V_4 -> V_17 , V_3 -> V_18 ) ;
F_11 ( V_3 -> V_4 -> V_17 , V_3 -> V_18 ) ;
F_6 ( V_13 , V_3 -> V_19 ) ;
F_7 ( V_3 -> V_4 , V_3 -> V_19 >> 9 ) ;
F_8 ( & F_1 ( V_3 ) -> V_15 , V_16 ) ;
}
static void F_12 ( struct V_2 * V_3 , struct V_12 * V_13 ,
T_1 V_20 , T_1 V_21 )
{
V_3 -> V_18 = V_20 ;
V_3 -> V_19 = V_20 * V_21 ;
if ( F_3 ( V_3 ) )
F_9 ( V_3 , V_13 ) ;
}
static void F_13 ( struct V_22 * V_6 )
{
struct V_2 * V_3 = V_6 -> V_3 ;
struct V_23 * V_24 = F_14 ( V_6 ) ;
int error = V_24 -> V_25 ? - V_26 : 0 ;
F_15 ( F_1 ( V_3 ) , L_7 , V_6 ,
error ? L_8 : L_9 ) ;
F_16 ( V_24 , error ) ;
}
static void F_17 ( struct V_2 * V_3 )
{
int V_27 ;
if ( V_3 -> V_28 == 0 )
return;
if ( F_18 ( V_29 , & V_3 -> V_30 ) )
return;
for ( V_27 = 0 ; V_27 < V_3 -> V_28 ; V_27 ++ ) {
struct V_31 * V_32 = V_3 -> V_33 [ V_27 ] ;
F_19 ( & V_32 -> V_34 ) ;
F_20 ( V_32 -> V_35 , V_36 ) ;
F_21 ( & V_32 -> V_34 ) ;
}
F_22 ( F_2 ( V_3 -> V_4 ) , L_10 ) ;
}
static enum V_37 F_23 ( struct V_23 * V_24 ,
bool V_38 )
{
struct V_22 * V_6 = F_24 ( V_24 ) ;
struct V_2 * V_3 = V_6 -> V_3 ;
F_25 ( F_1 ( V_3 ) , L_11 ) ;
F_26 ( V_39 , & V_3 -> V_30 ) ;
V_24 -> V_25 = - V_26 ;
F_19 ( & V_3 -> V_40 ) ;
F_17 ( V_3 ) ;
F_21 ( & V_3 -> V_40 ) ;
return V_41 ;
}
static int F_27 ( struct V_2 * V_3 , int V_42 , int V_43 ,
struct V_44 * V_45 , int V_46 , int * V_47 )
{
struct V_48 * V_35 = V_3 -> V_33 [ V_42 ] -> V_35 ;
int V_49 ;
struct V_50 V_51 ;
unsigned long V_52 = V_53 -> V_54 ;
if ( F_28 ( ! V_35 ) ) {
F_29 ( F_2 ( V_3 -> V_4 ) ,
L_12 ,
( V_43 ? L_13 : L_14 ) ) ;
return - V_55 ;
}
V_51 . V_56 = * V_45 ;
V_53 -> V_54 |= V_57 ;
do {
V_35 -> V_58 -> V_59 = V_60 | V_61 ;
V_51 . V_62 = NULL ;
V_51 . V_63 = 0 ;
V_51 . V_64 = NULL ;
V_51 . V_65 = 0 ;
V_51 . V_46 = V_46 | V_66 ;
if ( V_43 )
V_49 = F_30 ( V_35 , & V_51 ) ;
else
V_49 = F_31 ( V_35 , & V_51 , V_51 . V_46 ) ;
if ( V_49 <= 0 ) {
if ( V_49 == 0 )
V_49 = - V_67 ;
break;
}
if ( V_47 )
* V_47 += V_49 ;
} while ( F_32 ( & V_51 ) );
F_33 ( V_53 , V_52 , V_57 ) ;
return V_49 ;
}
static int F_34 ( struct V_2 * V_3 , struct V_22 * V_6 , int V_42 )
{
struct V_23 * V_24 = F_14 ( V_6 ) ;
struct V_31 * V_32 = V_3 -> V_33 [ V_42 ] ;
int V_49 ;
struct V_68 V_23 = { . V_69 = F_35 (NBD_REQUEST_MAGIC) } ;
struct V_70 V_71 = { . V_72 = & V_23 , . V_73 = sizeof( V_23 ) } ;
struct V_44 V_74 ;
unsigned long V_75 = F_36 ( V_24 ) ;
struct V_76 * V_76 ;
T_2 type ;
T_2 V_77 = F_37 ( V_24 ) ;
int V_47 = V_32 -> V_47 , V_78 = 0 ;
F_38 ( & V_74 , V_79 | V_80 , & V_71 , 1 , sizeof( V_23 ) ) ;
switch ( F_39 ( V_24 ) ) {
case V_81 :
type = V_11 ;
break;
case V_82 :
type = V_10 ;
break;
case V_83 :
type = V_8 ;
break;
case V_84 :
type = V_7 ;
break;
default:
return - V_26 ;
}
if ( F_40 ( V_24 ) == V_79 &&
( V_3 -> V_54 & V_85 ) ) {
F_29 ( F_2 ( V_3 -> V_4 ) ,
L_15 ) ;
return - V_26 ;
}
if ( V_47 ) {
if ( V_47 >= sizeof( V_23 ) ) {
V_78 = V_47 - sizeof( V_23 ) ;
goto V_86;
}
F_41 ( & V_74 , V_47 ) ;
}
V_23 . type = F_35 ( type ) ;
if ( type != V_10 ) {
V_23 . V_74 = F_42 ( ( V_87 ) F_43 ( V_24 ) << 9 ) ;
V_23 . V_88 = F_35 ( V_75 ) ;
}
memcpy ( V_23 . V_89 , & V_77 , sizeof( V_77 ) ) ;
F_15 ( F_1 ( V_3 ) , L_16 ,
V_6 , F_4 ( type ) ,
( unsigned long long ) F_43 ( V_24 ) << 9 , F_36 ( V_24 ) ) ;
V_49 = F_27 ( V_3 , V_42 , 1 , & V_74 ,
( type == V_8 ) ? V_90 : 0 , & V_47 ) ;
if ( V_49 <= 0 ) {
if ( V_49 == - V_91 ) {
if ( V_47 ) {
V_32 -> V_92 = V_24 ;
V_32 -> V_47 = V_47 ;
}
return V_93 ;
}
F_29 ( F_2 ( V_3 -> V_4 ) ,
L_17 , V_49 ) ;
return - V_26 ;
}
V_86:
if ( type != V_8 )
goto V_94;
V_76 = V_24 -> V_76 ;
while ( V_76 ) {
struct V_76 * V_95 = V_76 -> V_96 ;
struct V_97 V_45 ;
struct V_98 V_99 ;
F_44 (bvec, bio, iter) {
bool V_100 = ! V_95 && F_45 ( V_99 , V_45 ) ;
int V_54 = V_100 ? 0 : V_90 ;
F_15 ( F_1 ( V_3 ) , L_18 ,
V_6 , V_99 . V_101 ) ;
F_46 ( & V_74 , V_102 | V_79 ,
& V_99 , 1 , V_99 . V_101 ) ;
if ( V_78 ) {
if ( V_78 >= F_47 ( & V_74 ) ) {
V_78 -= F_47 ( & V_74 ) ;
continue;
}
F_41 ( & V_74 , V_78 ) ;
V_78 = 0 ;
}
V_49 = F_27 ( V_3 , V_42 , 1 , & V_74 , V_54 , & V_47 ) ;
if ( V_49 <= 0 ) {
if ( V_49 == - V_91 ) {
V_32 -> V_92 = V_24 ;
V_32 -> V_47 = V_47 ;
return V_93 ;
}
F_25 ( F_2 ( V_3 -> V_4 ) ,
L_19 ,
V_49 ) ;
return - V_26 ;
}
if ( V_100 )
break;
}
V_76 = V_95 ;
}
V_94:
V_32 -> V_92 = NULL ;
V_32 -> V_47 = 0 ;
return 0 ;
}
static struct V_22 * F_48 ( struct V_2 * V_3 , int V_42 )
{
int V_49 ;
struct V_103 V_104 ;
struct V_22 * V_6 ;
struct V_23 * V_24 = NULL ;
T_3 V_105 ;
T_2 V_77 ;
struct V_70 V_71 = { . V_72 = & V_104 , . V_73 = sizeof( V_104 ) } ;
struct V_44 V_106 ;
V_104 . V_69 = 0 ;
F_38 ( & V_106 , V_107 | V_80 , & V_71 , 1 , sizeof( V_104 ) ) ;
V_49 = F_27 ( V_3 , V_42 , 0 , & V_106 , V_108 , NULL ) ;
if ( V_49 <= 0 ) {
if ( ! F_49 ( V_29 , & V_3 -> V_30 ) &&
! F_49 ( V_109 , & V_3 -> V_30 ) )
F_25 ( F_2 ( V_3 -> V_4 ) ,
L_20 , V_49 ) ;
return F_50 ( V_49 ) ;
}
if ( F_51 ( V_104 . V_69 ) != V_110 ) {
F_25 ( F_2 ( V_3 -> V_4 ) , L_21 ,
( unsigned long ) F_51 ( V_104 . V_69 ) ) ;
return F_50 ( - V_111 ) ;
}
memcpy ( & V_77 , V_104 . V_89 , sizeof( T_2 ) ) ;
V_105 = F_52 ( V_77 ) ;
if ( V_105 < V_3 -> V_112 . V_113 )
V_24 = F_53 ( V_3 -> V_112 . V_114 [ V_105 ] ,
F_54 ( V_77 ) ) ;
if ( ! V_24 || ! F_55 ( V_24 ) ) {
F_25 ( F_2 ( V_3 -> V_4 ) , L_22 ,
V_77 , V_24 ) ;
return F_50 ( - V_115 ) ;
}
V_6 = F_24 ( V_24 ) ;
if ( F_51 ( V_104 . error ) ) {
F_25 ( F_2 ( V_3 -> V_4 ) , L_23 ,
F_51 ( V_104 . error ) ) ;
V_24 -> V_25 = - V_26 ;
return V_6 ;
}
F_15 ( F_1 ( V_3 ) , L_24 , V_6 ) ;
if ( F_40 ( V_24 ) != V_79 ) {
struct V_116 V_45 ;
struct V_98 V_99 ;
F_56 (bvec, req, iter) {
F_46 ( & V_106 , V_102 | V_107 ,
& V_99 , 1 , V_99 . V_101 ) ;
V_49 = F_27 ( V_3 , V_42 , 0 , & V_106 , V_108 , NULL ) ;
if ( V_49 <= 0 ) {
F_25 ( F_2 ( V_3 -> V_4 ) , L_25 ,
V_49 ) ;
V_24 -> V_25 = - V_26 ;
return V_6 ;
}
F_15 ( F_1 ( V_3 ) , L_26 ,
V_6 , V_99 . V_101 ) ;
}
} else {
F_57 ( & V_6 -> V_117 ) ;
}
return V_6 ;
}
static T_4 F_58 ( struct V_1 * V_118 ,
struct V_119 * V_120 , char * V_121 )
{
struct V_122 * V_4 = F_59 ( V_118 ) ;
struct V_2 * V_3 = (struct V_2 * ) V_4 -> V_123 ;
return sprintf ( V_121 , L_27 , F_60 ( V_3 -> V_5 ) ) ;
}
static void F_61 ( struct V_124 * V_125 )
{
struct V_126 * args = F_62 ( V_125 ,
struct V_126 ,
V_125 ) ;
struct V_2 * V_3 = args -> V_3 ;
struct V_22 * V_6 ;
int V_127 = 0 ;
F_63 ( V_3 -> V_69 != V_128 ) ;
while ( 1 ) {
V_6 = F_48 ( V_3 , args -> V_42 ) ;
if ( F_64 ( V_6 ) ) {
V_127 = F_65 ( V_6 ) ;
break;
}
F_13 ( V_6 ) ;
}
if ( V_127 && ! F_49 ( V_109 , & V_3 -> V_30 ) )
F_17 ( V_3 ) ;
F_66 ( & V_3 -> V_129 ) ;
F_67 ( & V_3 -> V_130 ) ;
}
static void F_68 ( struct V_23 * V_24 , void * V_131 , bool V_38 )
{
struct V_22 * V_6 ;
if ( ! F_55 ( V_24 ) )
return;
V_6 = F_24 ( V_24 ) ;
V_24 -> V_25 = - V_26 ;
F_13 ( V_6 ) ;
}
static void F_69 ( struct V_2 * V_3 )
{
F_63 ( V_3 -> V_69 != V_128 ) ;
F_70 ( & V_3 -> V_112 , F_68 , NULL ) ;
F_15 ( F_2 ( V_3 -> V_4 ) , L_28 ) ;
}
static int F_71 ( struct V_22 * V_6 , int V_42 )
{
struct V_23 * V_24 = F_14 ( V_6 ) ;
struct V_2 * V_3 = V_6 -> V_3 ;
struct V_31 * V_32 ;
int V_127 ;
if ( V_42 >= V_3 -> V_28 ) {
F_29 ( F_2 ( V_3 -> V_4 ) ,
L_29 ) ;
return - V_55 ;
}
if ( F_49 ( V_29 , & V_3 -> V_30 ) ) {
F_29 ( F_2 ( V_3 -> V_4 ) ,
L_30 ) ;
return - V_55 ;
}
V_24 -> V_25 = 0 ;
V_32 = V_3 -> V_33 [ V_42 ] ;
F_19 ( & V_32 -> V_34 ) ;
if ( F_28 ( ! V_32 -> V_35 ) ) {
F_21 ( & V_32 -> V_34 ) ;
F_29 ( F_2 ( V_3 -> V_4 ) ,
L_30 ) ;
return - V_55 ;
}
if ( F_28 ( V_32 -> V_92 && V_32 -> V_92 != V_24 ) ) {
F_72 ( V_24 , true ) ;
V_127 = 0 ;
goto V_94;
}
V_127 = F_34 ( V_3 , V_6 , V_42 ) ;
V_94:
F_21 ( & V_32 -> V_34 ) ;
return V_127 ;
}
static int F_73 ( struct V_132 * V_133 ,
const struct V_134 * V_135 )
{
struct V_22 * V_6 = F_24 ( V_135 -> V_136 ) ;
int V_127 ;
F_74 ( & V_6 -> V_117 ) ;
F_75 ( V_135 -> V_136 ) ;
V_127 = F_71 ( V_6 , V_133 -> V_137 ) ;
if ( V_127 < 0 )
V_127 = V_138 ;
if ( ! V_127 )
V_127 = V_139 ;
F_76 ( & V_6 -> V_117 ) ;
return V_127 ;
}
static int F_77 ( struct V_2 * V_3 , struct V_12 * V_13 ,
unsigned long V_140 )
{
struct V_48 * V_35 ;
struct V_31 * * V_33 ;
struct V_31 * V_32 ;
int V_141 ;
V_35 = F_78 ( V_140 , & V_141 ) ;
if ( ! V_35 )
return V_141 ;
if ( ! V_3 -> V_142 )
V_3 -> V_142 = V_53 ;
if ( V_3 -> V_142 != V_53 ) {
F_25 ( F_2 ( V_3 -> V_4 ) ,
L_31 ) ;
return - V_55 ;
}
V_33 = F_79 ( V_3 -> V_33 , ( V_3 -> V_28 + 1 ) *
sizeof( struct V_31 * ) , V_143 ) ;
if ( ! V_33 )
return - V_144 ;
V_32 = F_80 ( sizeof( struct V_31 ) , V_143 ) ;
if ( ! V_32 )
return - V_144 ;
V_3 -> V_33 = V_33 ;
F_81 ( & V_32 -> V_34 ) ;
V_32 -> V_35 = V_35 ;
V_32 -> V_92 = NULL ;
V_32 -> V_47 = 0 ;
V_33 [ V_3 -> V_28 ++ ] = V_32 ;
if ( V_145 )
V_13 -> V_146 = 1 ;
return 0 ;
}
static void F_82 ( struct V_2 * V_3 )
{
V_3 -> V_30 = 0 ;
V_3 -> V_18 = 1024 ;
V_3 -> V_19 = 0 ;
F_7 ( V_3 -> V_4 , 0 ) ;
V_3 -> V_54 = 0 ;
V_3 -> V_112 . V_147 = 0 ;
F_83 ( V_148 , V_3 -> V_4 -> V_17 ) ;
}
static void F_84 ( struct V_12 * V_13 )
{
if ( V_13 -> V_14 > 1 )
return;
F_85 ( V_13 , false ) ;
V_13 -> V_149 -> V_150 = 0 ;
if ( V_145 > 0 ) {
F_86 ( V_13 ) ;
V_13 -> V_146 = 1 ;
}
}
static void F_87 ( struct V_2 * V_3 , struct V_12 * V_13 )
{
if ( V_3 -> V_54 & V_85 )
F_85 ( V_13 , true ) ;
if ( V_3 -> V_54 & V_151 )
F_88 ( V_148 , V_3 -> V_4 -> V_17 ) ;
if ( V_3 -> V_54 & V_152 )
F_89 ( V_3 -> V_4 -> V_17 , true , false ) ;
else
F_89 ( V_3 -> V_4 -> V_17 , false , false ) ;
}
static void F_90 ( struct V_2 * V_3 )
{
struct V_68 V_23 = {
. V_69 = F_35 ( V_153 ) ,
. type = F_35 ( V_9 ) ,
} ;
struct V_70 V_71 = { . V_72 = & V_23 , . V_73 = sizeof( V_23 ) } ;
struct V_44 V_74 ;
int V_27 , V_127 ;
for ( V_27 = 0 ; V_27 < V_3 -> V_28 ; V_27 ++ ) {
F_38 ( & V_74 , V_79 | V_80 , & V_71 , 1 , sizeof( V_23 ) ) ;
V_127 = F_27 ( V_3 , V_27 , 1 , & V_74 , 0 , NULL ) ;
if ( V_127 <= 0 )
F_25 ( F_2 ( V_3 -> V_4 ) ,
L_32 , V_127 ) ;
}
}
static int F_91 ( struct V_2 * V_3 , struct V_12 * V_13 )
{
F_92 ( F_2 ( V_3 -> V_4 ) , L_33 ) ;
if ( ! V_3 -> V_33 )
return - V_55 ;
F_21 ( & V_3 -> V_40 ) ;
F_93 ( V_13 ) ;
F_19 ( & V_3 -> V_40 ) ;
if ( ! V_3 -> V_33 )
return - V_55 ;
if ( ! F_18 ( V_109 ,
& V_3 -> V_30 ) )
F_90 ( V_3 ) ;
return 0 ;
}
static int F_94 ( struct V_2 * V_3 , struct V_12 * V_13 )
{
F_17 ( V_3 ) ;
F_69 ( V_3 ) ;
F_95 ( V_13 , true ) ;
F_84 ( V_13 ) ;
if ( ! F_49 ( V_154 , & V_3 -> V_30 ) &&
V_3 -> V_28 ) {
int V_27 ;
for ( V_27 = 0 ; V_27 < V_3 -> V_28 ; V_27 ++ ) {
F_96 ( V_3 -> V_33 [ V_27 ] -> V_35 ) ;
F_97 ( V_3 -> V_33 [ V_27 ] ) ;
}
F_97 ( V_3 -> V_33 ) ;
V_3 -> V_33 = NULL ;
V_3 -> V_28 = 0 ;
}
V_3 -> V_142 = NULL ;
return 0 ;
}
static int F_98 ( struct V_2 * V_3 , struct V_12 * V_13 )
{
struct V_126 * args ;
int V_28 = V_3 -> V_28 ;
int error = 0 , V_27 ;
if ( V_3 -> V_5 )
return - V_155 ;
if ( ! V_3 -> V_33 )
return - V_55 ;
if ( V_28 > 1 &&
! ( V_3 -> V_54 & V_156 ) ) {
F_25 ( F_2 ( V_3 -> V_4 ) , L_34 ) ;
error = - V_55 ;
goto V_157;
}
F_26 ( V_154 , & V_3 -> V_30 ) ;
F_99 ( & V_3 -> V_112 , V_3 -> V_28 ) ;
args = F_100 ( V_28 , sizeof( * args ) , V_143 ) ;
if ( ! args ) {
error = - V_144 ;
goto V_157;
}
V_3 -> V_5 = V_53 ;
F_21 ( & V_3 -> V_40 ) ;
F_87 ( V_3 , V_13 ) ;
error = F_101 ( F_2 ( V_3 -> V_4 ) , & V_158 ) ;
if ( error ) {
F_25 ( F_2 ( V_3 -> V_4 ) , L_35 ) ;
goto V_159;
}
F_9 ( V_3 , V_13 ) ;
F_102 ( V_3 ) ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ ) {
F_103 ( V_3 -> V_33 [ V_27 ] -> V_35 -> V_58 ) ;
F_104 ( & V_3 -> V_129 ) ;
F_105 ( & args [ V_27 ] . V_125 , F_61 ) ;
args [ V_27 ] . V_3 = V_3 ;
args [ V_27 ] . V_42 = V_27 ;
F_106 ( V_160 , & args [ V_27 ] . V_125 ) ;
}
F_107 ( V_3 -> V_130 ,
F_108 ( & V_3 -> V_129 ) == 0 ) ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ )
F_109 ( & args [ V_27 ] . V_125 ) ;
F_110 ( V_3 ) ;
F_5 ( V_3 , V_13 ) ;
F_111 ( F_2 ( V_3 -> V_4 ) , & V_158 ) ;
V_159:
F_19 ( & V_3 -> V_40 ) ;
V_3 -> V_5 = NULL ;
V_157:
F_112 ( V_154 , & V_3 -> V_30 ) ;
F_94 ( V_3 , V_13 ) ;
if ( F_49 ( V_109 , & V_3 -> V_30 ) )
error = 0 ;
if ( F_49 ( V_39 , & V_3 -> V_30 ) )
error = - V_161 ;
F_82 ( V_3 ) ;
return error ;
}
static int F_113 ( struct V_12 * V_13 , struct V_2 * V_3 ,
unsigned int V_6 , unsigned long V_140 )
{
switch ( V_6 ) {
case V_162 :
return F_91 ( V_3 , V_13 ) ;
case V_163 :
return F_94 ( V_3 , V_13 ) ;
case V_164 :
return F_77 ( V_3 , V_13 , V_140 ) ;
case V_165 :
F_12 ( V_3 , V_13 , V_140 ,
F_114 ( V_3 -> V_19 , V_140 ) ) ;
return 0 ;
case V_166 :
F_12 ( V_3 , V_13 , V_3 -> V_18 ,
F_114 ( V_140 , V_3 -> V_18 ) ) ;
return 0 ;
case V_167 :
F_12 ( V_3 , V_13 , V_3 -> V_18 , V_140 ) ;
return 0 ;
case V_168 :
if ( V_140 ) {
V_3 -> V_112 . V_147 = V_140 * V_169 ;
F_115 ( V_3 -> V_4 -> V_17 , V_140 * V_169 ) ;
}
return 0 ;
case V_170 :
V_3 -> V_54 = V_140 ;
return 0 ;
case V_171 :
return F_98 ( V_3 , V_13 ) ;
case V_172 :
return 0 ;
case V_173 :
return 0 ;
}
return - V_174 ;
}
static int F_116 ( struct V_12 * V_13 , T_5 V_175 ,
unsigned int V_6 , unsigned long V_140 )
{
struct V_2 * V_3 = V_13 -> V_176 -> V_123 ;
int error ;
if ( ! F_117 ( V_177 ) )
return - V_178 ;
F_63 ( V_3 -> V_69 != V_128 ) ;
F_19 ( & V_3 -> V_40 ) ;
error = F_113 ( V_13 , V_3 , V_6 , V_140 ) ;
F_21 ( & V_3 -> V_40 ) ;
return error ;
}
static int F_118 ( struct V_179 * V_180 , void * V_181 )
{
struct V_2 * V_3 = V_180 -> V_182 ;
if ( V_3 -> V_5 )
F_119 ( V_180 , L_36 , F_60 ( V_3 -> V_5 ) ) ;
return 0 ;
}
static int F_120 ( struct V_183 * V_183 , struct V_184 * V_184 )
{
return F_121 ( V_184 , F_118 , V_183 -> V_185 ) ;
}
static int F_122 ( struct V_179 * V_180 , void * V_181 )
{
struct V_2 * V_3 = V_180 -> V_182 ;
T_2 V_54 = V_3 -> V_54 ;
F_119 ( V_180 , L_37 , V_54 ) ;
F_123 ( V_180 , L_38 ) ;
if ( V_54 & V_186 )
F_123 ( V_180 , L_39 ) ;
if ( V_54 & V_85 )
F_123 ( V_180 , L_40 ) ;
if ( V_54 & V_152 )
F_123 ( V_180 , L_41 ) ;
if ( V_54 & V_151 )
F_123 ( V_180 , L_42 ) ;
return 0 ;
}
static int F_124 ( struct V_183 * V_183 , struct V_184 * V_184 )
{
return F_121 ( V_184 , F_122 , V_183 -> V_185 ) ;
}
static int F_102 ( struct V_2 * V_3 )
{
struct V_187 * V_188 ;
if ( ! V_189 )
return - V_26 ;
V_188 = F_125 ( F_126 ( V_3 ) , V_189 ) ;
if ( ! V_188 ) {
F_25 ( F_1 ( V_3 ) , L_43 ,
F_126 ( V_3 ) ) ;
return - V_26 ;
}
V_3 -> V_190 = V_188 ;
F_127 ( L_44 , 0444 , V_188 , V_3 , & V_191 ) ;
F_128 ( L_45 , 0444 , V_188 , & V_3 -> V_19 ) ;
F_129 ( L_46 , 0444 , V_188 , & V_3 -> V_112 . V_147 ) ;
F_128 ( L_47 , 0444 , V_188 , & V_3 -> V_18 ) ;
F_127 ( L_48 , 0444 , V_188 , V_3 , & V_192 ) ;
return 0 ;
}
static void F_110 ( struct V_2 * V_3 )
{
F_130 ( V_3 -> V_190 ) ;
}
static int F_131 ( void )
{
struct V_187 * V_190 ;
V_190 = F_125 ( L_49 , NULL ) ;
if ( ! V_190 )
return - V_26 ;
V_189 = V_190 ;
return 0 ;
}
static void F_132 ( void )
{
F_130 ( V_189 ) ;
}
static int F_102 ( struct V_2 * V_3 )
{
return 0 ;
}
static void F_110 ( struct V_2 * V_3 )
{
}
static int F_131 ( void )
{
return 0 ;
}
static void F_132 ( void )
{
}
static int F_133 ( void * V_131 , struct V_23 * V_136 ,
unsigned int V_193 , unsigned int V_194 ,
unsigned int V_195 )
{
struct V_22 * V_6 = F_24 ( V_136 ) ;
V_6 -> V_3 = V_131 ;
return 0 ;
}
static void F_134 ( struct V_2 * V_3 )
{
struct V_122 * V_4 = V_3 -> V_4 ;
V_3 -> V_69 = 0 ;
if ( V_4 ) {
F_135 ( V_4 ) ;
F_136 ( V_4 -> V_17 ) ;
F_137 ( & V_3 -> V_112 ) ;
F_138 ( V_4 ) ;
}
F_97 ( V_3 ) ;
}
static int F_139 ( int V_42 )
{
struct V_2 * V_3 ;
struct V_122 * V_4 ;
struct V_196 * V_197 ;
int V_141 = - V_144 ;
V_3 = F_80 ( sizeof( struct V_2 ) , V_143 ) ;
if ( ! V_3 )
goto V_94;
V_4 = F_140 ( 1 << V_198 ) ;
if ( ! V_4 )
goto V_199;
if ( V_42 >= 0 ) {
V_141 = F_141 ( & V_200 , V_3 , V_42 , V_42 + 1 ,
V_143 ) ;
if ( V_141 == - V_201 )
V_141 = - V_202 ;
} else {
V_141 = F_141 ( & V_200 , V_3 , 0 , 0 , V_143 ) ;
if ( V_141 >= 0 )
V_42 = V_141 ;
}
if ( V_141 < 0 )
goto V_203;
V_3 -> V_4 = V_4 ;
V_3 -> V_112 . V_204 = & V_205 ;
V_3 -> V_112 . V_113 = 1 ;
V_3 -> V_112 . V_206 = 128 ;
V_3 -> V_112 . V_195 = V_207 ;
V_3 -> V_112 . V_208 = sizeof( struct V_22 ) ;
V_3 -> V_112 . V_54 = V_209 |
V_210 | V_211 ;
V_3 -> V_112 . V_212 = V_3 ;
V_141 = F_142 ( & V_3 -> V_112 ) ;
if ( V_141 )
goto V_213;
V_197 = F_143 ( & V_3 -> V_112 ) ;
if ( F_64 ( V_197 ) ) {
V_141 = F_65 ( V_197 ) ;
goto V_214;
}
V_4 -> V_17 = V_197 ;
F_88 ( V_215 , V_4 -> V_17 ) ;
F_83 ( V_216 , V_4 -> V_17 ) ;
V_4 -> V_17 -> V_217 . V_218 = 512 ;
F_144 ( V_4 -> V_17 , V_219 ) ;
V_4 -> V_17 -> V_217 . V_220 = 0 ;
F_145 ( V_4 -> V_17 , 65536 ) ;
V_4 -> V_17 -> V_217 . V_221 = 256 ;
V_3 -> V_69 = V_128 ;
F_81 ( & V_3 -> V_40 ) ;
V_4 -> V_222 = V_223 ;
V_4 -> V_224 = V_42 << V_198 ;
V_4 -> V_225 = & V_226 ;
V_4 -> V_123 = V_3 ;
sprintf ( V_4 -> V_227 , L_50 , V_42 ) ;
F_146 ( & V_3 -> V_130 ) ;
F_82 ( V_3 ) ;
F_147 ( V_4 ) ;
return V_42 ;
V_214:
F_137 ( & V_3 -> V_112 ) ;
V_213:
F_148 ( & V_200 , V_42 ) ;
V_203:
F_138 ( V_4 ) ;
V_199:
F_97 ( V_3 ) ;
V_94:
return V_141 ;
}
static int T_6 F_149 ( void )
{
int V_27 ;
F_150 ( sizeof( struct V_68 ) != 28 ) ;
if ( V_145 < 0 ) {
F_151 ( V_228 L_51 ) ;
return - V_55 ;
}
V_198 = 0 ;
if ( V_145 > 0 ) {
V_198 = F_152 ( V_145 ) ;
V_145 = ( 1UL << V_198 ) - 1 ;
}
if ( ( 1UL << V_198 ) > V_229 )
return - V_55 ;
if ( V_230 > 1UL << ( V_231 - V_198 ) )
return - V_55 ;
V_160 = F_153 ( L_52 ,
V_232 | V_233 , 0 ) ;
if ( ! V_160 )
return - V_144 ;
if ( F_154 ( V_223 , L_49 ) ) {
F_155 ( V_160 ) ;
return - V_26 ;
}
F_131 () ;
F_19 ( & V_234 ) ;
for ( V_27 = 0 ; V_27 < V_230 ; V_27 ++ )
F_139 ( V_27 ) ;
F_21 ( & V_234 ) ;
return 0 ;
}
static int F_156 ( int V_235 , void * V_236 , void * V_131 )
{
struct V_2 * V_3 = V_236 ;
F_134 ( V_3 ) ;
return 0 ;
}
static void T_7 F_157 ( void )
{
F_132 () ;
F_158 ( & V_200 , & F_156 , NULL ) ;
F_159 ( & V_200 ) ;
F_155 ( V_160 ) ;
F_160 ( V_223 , L_49 ) ;
}
