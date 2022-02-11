static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 V_10 ;
unsigned long V_11 ;
int V_12 ;
F_2 ( & V_10 ) ;
V_11 = V_13 ;
V_12 = F_3 ( V_2 , & V_10 ,
V_14 ,
( void * ) V_11 ) ;
if ( V_12 < 0 ) {
F_4 ( V_6 , L_1 ,
V_12 ) ;
return V_12 ;
}
if ( V_12 == 0 ) {
F_4 ( V_6 , L_2 ) ;
return - V_15 ;
}
V_8 = F_5 ( & V_10 , struct V_7 , V_16 ) ;
* V_4 = * V_8 -> V_4 ;
F_6 ( & V_10 ) ;
return 0 ;
}
static T_1 F_7 ( T_2 V_17 , T_3 V_18 , void * V_19 ,
void * * V_20 )
{
T_4 * V_21 = V_19 ;
unsigned long long V_22 ;
T_1 V_23 ;
V_23 = F_8 ( V_17 , L_3 , NULL , & V_22 ) ;
if ( F_9 ( V_23 ) || V_22 != * V_21 )
return V_24 ;
* ( T_2 * ) V_20 = V_17 ;
return V_25 ;
}
int F_10 ( struct V_5 * V_6 , const char * V_26 , T_4 V_21 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 ;
T_1 V_23 ;
T_2 V_17 ;
int V_12 ;
V_23 = F_11 ( V_26 , F_7 , & V_21 , & V_17 ) ;
if ( F_9 ( V_23 ) ) {
F_4 ( V_6 , L_4 ,
V_26 ) ;
return - V_27 ;
}
V_12 = F_12 ( V_17 , & V_2 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_1 ( V_2 , V_4 ) ;
if ( V_12 ) {
F_4 ( V_6 , L_5 ,
F_13 ( & V_2 -> V_6 ) ) ;
return V_12 ;
}
return 0 ;
}
T_5 F_14 ( T_2 V_17 )
{
T_1 V_23 = V_28 ;
unsigned long long V_29 ;
if ( V_17 )
V_23 = F_8 ( V_17 , V_30 ,
NULL , & V_29 ) ;
if ( F_9 ( V_23 ) )
return 0 ;
return ( T_5 ) V_29 ;
}
static T_1 F_15 ( union V_31 * V_32 ,
struct V_33 * V_34 )
{
int V_35 ;
union V_31 * V_36 = V_32 -> V_37 . V_38 ;
T_3 V_39 = V_36 [ 1 ] . integer . V_40 ;
switch ( V_39 ) {
case 1 :
if ( V_32 -> V_37 . V_41 != 6 )
return V_42 ;
for ( V_35 = 2 ; V_35 < 6 ; V_35 ++ )
if ( V_36 [ V_35 ] . type != V_43 )
return V_42 ;
V_34 -> V_44 = & V_34 -> V_45 ;
V_34 -> V_44 -> V_39 = V_39 ;
V_34 -> V_44 -> V_46 = V_36 [ 2 ] . integer . V_40 ;
V_34 -> V_44 -> V_47 = V_36 [ 3 ] . integer . V_40 ;
V_34 -> V_44 -> V_48 = V_36 [ 4 ] . integer . V_40 ;
V_34 -> V_44 -> V_49 = V_36 [ 5 ] . integer . V_40 ;
break;
default:
F_16 ( V_50
L_6 ,
V_51 , V_39 ) ;
return V_42 ;
}
return V_52 ;
}
static T_1 F_17 ( union V_31 * V_32 ,
struct V_33 * V_34 )
{
int V_35 ;
union V_31 * V_36 = V_32 -> V_37 . V_38 ;
T_3 V_39 = V_36 [ 1 ] . integer . V_40 ;
switch ( V_39 ) {
case 1 :
if ( V_32 -> V_37 . V_41 != 5 )
return V_42 ;
for ( V_35 = 2 ; V_35 < 5 ; V_35 ++ )
if ( V_36 [ V_35 ] . type != V_43 )
return V_42 ;
V_34 -> V_53 = & V_34 -> V_54 ;
V_34 -> V_53 -> V_39 = V_39 ;
V_34 -> V_53 -> V_55 = V_36 [ 2 ] . integer . V_40 ;
V_34 -> V_53 -> V_56 = V_36 [ 3 ] . integer . V_40 ;
V_34 -> V_53 -> V_57 = V_36 [ 4 ] . integer . V_40 ;
break;
default:
F_16 ( V_50
L_7 ,
V_51 , V_39 ) ;
return V_42 ;
}
return V_52 ;
}
static T_1 F_18 ( union V_31 * V_32 ,
struct V_33 * V_34 )
{
int V_35 ;
union V_31 * V_36 = V_32 -> V_37 . V_38 ;
T_3 V_39 = V_36 [ 1 ] . integer . V_40 ;
switch ( V_39 ) {
case 1 :
if ( V_32 -> V_37 . V_41 != 18 )
return V_42 ;
for ( V_35 = 2 ; V_35 < 18 ; V_35 ++ )
if ( V_36 [ V_35 ] . type != V_43 )
return V_42 ;
V_34 -> V_58 = & V_34 -> V_59 ;
V_34 -> V_58 -> V_39 = V_39 ;
V_34 -> V_58 -> V_60 = V_36 [ 2 ] . integer . V_40 ;
V_34 -> V_58 -> V_61 = V_36 [ 3 ] . integer . V_40 ;
V_34 -> V_58 -> V_62 = V_36 [ 4 ] . integer . V_40 ;
V_34 -> V_58 -> V_63 = V_36 [ 5 ] . integer . V_40 ;
V_34 -> V_58 -> V_64 = V_36 [ 6 ] . integer . V_40 ;
V_34 -> V_58 -> V_65 = V_36 [ 7 ] . integer . V_40 ;
V_34 -> V_58 -> V_66 = V_36 [ 8 ] . integer . V_40 ;
V_34 -> V_58 -> V_67 = V_36 [ 9 ] . integer . V_40 ;
V_34 -> V_58 -> V_68 = V_36 [ 10 ] . integer . V_40 ;
V_34 -> V_58 -> V_69 = V_36 [ 11 ] . integer . V_40 ;
V_34 -> V_58 -> V_70 = V_36 [ 12 ] . integer . V_40 ;
V_34 -> V_58 -> V_71 = V_36 [ 13 ] . integer . V_40 ;
V_34 -> V_58 -> V_72 = V_36 [ 14 ] . integer . V_40 ;
V_34 -> V_58 -> V_73 = V_36 [ 15 ] . integer . V_40 ;
V_34 -> V_58 -> V_74 = V_36 [ 16 ] . integer . V_40 ;
V_34 -> V_58 -> V_75 = V_36 [ 17 ] . integer . V_40 ;
break;
default:
F_16 ( V_50
L_8 ,
V_51 , V_39 ) ;
return V_42 ;
}
return V_52 ;
}
static T_1 F_19 ( T_2 V_17 , struct V_33 * V_34 )
{
T_1 V_23 ;
struct V_76 V_77 = { V_78 , NULL } ;
union V_31 * V_37 , * V_32 , * V_36 ;
T_3 type ;
int V_35 ;
memset ( V_34 , 0 , sizeof( struct V_33 ) ) ;
V_23 = F_20 ( V_17 , L_9 , NULL , & V_77 ) ;
if ( F_9 ( V_23 ) )
return V_23 ;
V_37 = (union V_31 * ) V_77 . V_79 ;
if ( V_37 -> type != V_80 ) {
V_23 = V_42 ;
goto exit;
}
for ( V_35 = 0 ; V_35 < V_37 -> V_37 . V_41 ; V_35 ++ ) {
V_32 = & V_37 -> V_37 . V_38 [ V_35 ] ;
if ( V_32 -> type != V_80 ) {
V_23 = V_42 ;
goto exit;
}
V_36 = V_32 -> V_37 . V_38 ;
if ( V_36 [ 0 ] . type != V_43 ||
V_36 [ 1 ] . type != V_43 ) {
V_23 = V_42 ;
goto exit;
}
type = V_36 [ 0 ] . integer . V_40 ;
switch ( type ) {
case 0 :
V_23 = F_15 ( V_32 , V_34 ) ;
if ( F_9 ( V_23 ) )
goto exit;
break;
case 1 :
V_23 = F_17 ( V_32 , V_34 ) ;
if ( F_9 ( V_23 ) )
goto exit;
break;
case 2 :
V_23 = F_18 ( V_32 , V_34 ) ;
if ( F_9 ( V_23 ) )
goto exit;
break;
default:
F_16 ( V_81 L_10 ,
V_51 , type ) ;
V_23 = V_42 ;
goto exit;
}
}
exit:
F_21 ( V_77 . V_79 ) ;
return V_23 ;
}
static T_1 F_22 ( T_2 V_17 , struct V_33 * V_82 )
{
T_1 V_23 ;
struct V_76 V_77 = { V_78 , NULL } ;
union V_31 * V_37 , * V_36 ;
int V_35 ;
memset ( V_82 , 0 , sizeof( struct V_33 ) ) ;
V_23 = F_20 ( V_17 , L_11 , NULL , & V_77 ) ;
if ( F_9 ( V_23 ) )
return V_23 ;
V_37 = (union V_31 * ) V_77 . V_79 ;
if ( V_37 -> type != V_80 ||
V_37 -> V_37 . V_41 != 4 ) {
V_23 = V_42 ;
goto exit;
}
V_36 = V_37 -> V_37 . V_38 ;
for ( V_35 = 0 ; V_35 < 4 ; V_35 ++ ) {
if ( V_36 [ V_35 ] . type != V_43 ) {
V_23 = V_42 ;
goto exit;
}
}
V_82 -> V_44 = & V_82 -> V_45 ;
V_82 -> V_44 -> V_39 = 1 ;
V_82 -> V_44 -> V_46 = V_36 [ 0 ] . integer . V_40 ;
V_82 -> V_44 -> V_47 = V_36 [ 1 ] . integer . V_40 ;
V_82 -> V_44 -> V_48 = V_36 [ 2 ] . integer . V_40 ;
V_82 -> V_44 -> V_49 = V_36 [ 3 ] . integer . V_40 ;
exit:
F_21 ( V_77 . V_79 ) ;
return V_23 ;
}
int F_23 ( struct V_83 * V_6 , struct V_33 * V_82 )
{
T_1 V_23 ;
T_2 V_17 , V_84 ;
struct V_85 * V_86 ;
if ( V_87 )
return - V_27 ;
V_17 = NULL ;
for ( V_86 = V_6 -> V_88 ; V_86 ; V_86 = V_86 -> V_89 ) {
V_17 = F_24 ( V_86 ) ;
if ( V_17 )
break;
}
while ( V_17 ) {
V_23 = F_19 ( V_17 , V_82 ) ;
if ( F_25 ( V_23 ) )
return 0 ;
V_23 = F_22 ( V_17 , V_82 ) ;
if ( F_25 ( V_23 ) )
return 0 ;
if ( F_26 ( V_17 ) )
break;
V_23 = F_27 ( V_17 , & V_84 ) ;
if ( F_9 ( V_23 ) )
break;
V_17 = V_84 ;
}
return - V_27 ;
}
bool F_28 ( struct V_83 * V_90 )
{
struct V_91 * V_92 ;
T_2 V_17 ;
V_17 = F_29 ( V_90 ) ;
if ( ! V_17 )
return false ;
V_92 = F_30 ( V_17 ) ;
if ( ! V_92 )
return false ;
return V_92 -> V_93 & V_94 ;
}
static void F_31 ( struct V_95 * V_19 )
{
struct V_1 * V_2 ;
struct V_91 * V_92 ;
V_2 = F_32 ( V_19 , struct V_1 , V_96 . V_19 ) ;
V_92 = F_33 ( V_2 ) ;
F_34 ( V_92 -> V_88 ) ;
}
static void F_35 ( struct V_95 * V_19 )
{
struct V_83 * V_83 ;
V_83 = F_36 ( V_19 -> V_6 ) ;
if ( V_83 -> V_97 )
V_83 -> V_97 = false ;
if ( V_83 -> V_98 == V_99 ) {
F_37 ( V_83 ) ;
F_38 ( & V_83 -> V_6 ) ;
return;
}
if ( V_83 -> V_100 )
F_39 ( V_83 ) ;
F_37 ( V_83 ) ;
F_38 ( & V_83 -> V_6 ) ;
F_34 ( V_83 -> V_101 ) ;
}
T_1 F_40 ( struct V_1 * V_6 )
{
return F_41 ( V_6 , NULL , F_31 ) ;
}
T_1 F_42 ( struct V_1 * V_6 ,
struct V_83 * V_83 )
{
return F_41 ( V_6 , & V_83 -> V_6 , F_35 ) ;
}
static T_6 F_43 ( struct V_83 * V_90 )
{
int V_102 , V_103 ;
if ( V_90 -> V_104 )
V_103 = V_105 ;
else
V_103 = V_106 ;
V_102 = F_44 ( & V_90 -> V_6 , NULL , V_103 ) ;
if ( V_102 < 0 )
return V_107 ;
switch ( V_102 ) {
case V_108 :
return V_109 ;
case V_110 :
return V_111 ;
case V_112 :
return V_113 ;
case V_105 :
return V_114 ;
case V_106 :
return V_99 ;
}
return V_107 ;
}
static bool F_45 ( struct V_83 * V_6 )
{
struct V_1 * V_2 = F_46 ( & V_6 -> V_6 ) ;
return V_2 ? F_47 ( V_2 ) : false ;
}
static int F_48 ( struct V_83 * V_6 , T_6 V_115 )
{
struct V_1 * V_2 = F_46 ( & V_6 -> V_6 ) ;
static const T_7 V_116 [] = {
[ V_109 ] = V_108 ,
[ V_111 ] = V_110 ,
[ V_113 ] = V_112 ,
[ V_114 ] = V_105 ,
[ V_99 ] = V_106 ,
} ;
int error = - V_15 ;
if ( ! V_2 || F_49 ( V_2 -> V_17 , L_12 ) )
return - V_27 ;
switch ( V_115 ) {
case V_99 :
if ( F_50 ( & V_6 -> V_6 , V_117 ) ==
V_118 ) {
error = - V_119 ;
break;
}
case V_109 :
case V_111 :
case V_113 :
case V_114 :
error = F_51 ( V_2 , V_116 [ V_115 ] ) ;
}
if ( ! error )
F_52 ( & V_6 -> V_6 , L_13 ,
F_53 ( V_116 [ V_115 ] ) ) ;
return error ;
}
static T_6 F_54 ( struct V_83 * V_6 )
{
struct V_1 * V_2 = F_46 ( & V_6 -> V_6 ) ;
static const T_6 V_116 [] = {
[ V_108 ] = V_109 ,
[ V_110 ] = V_111 ,
[ V_112 ] = V_113 ,
[ V_105 ] = V_114 ,
[ V_106 ] = V_99 ,
} ;
int V_115 ;
if ( ! V_2 || ! F_47 ( V_2 ) )
return V_120 ;
if ( F_55 ( V_2 , & V_115 ) || V_115 == V_121 )
return V_120 ;
return V_116 [ V_115 ] ;
}
static int F_56 ( struct V_85 * V_88 , bool V_122 )
{
while ( V_88 -> V_89 ) {
if ( F_57 ( & V_88 -> V_123 -> V_6 ) )
return F_58 ( & V_88 -> V_123 -> V_6 , V_122 ) ;
V_88 = V_88 -> V_89 ;
}
if ( V_88 -> V_124 ) {
if ( F_57 ( V_88 -> V_124 ) )
return F_58 ( V_88 -> V_124 , V_122 ) ;
}
return 0 ;
}
static int F_59 ( struct V_83 * V_6 , bool V_122 )
{
if ( F_57 ( & V_6 -> V_6 ) )
return F_58 ( & V_6 -> V_6 , V_122 ) ;
return F_56 ( V_6 -> V_88 , V_122 ) ;
}
static bool F_60 ( struct V_83 * V_6 )
{
struct V_1 * V_2 = F_46 ( & V_6 -> V_6 ) ;
if ( ! V_2 || ! F_47 ( V_2 ) )
return false ;
if ( F_61 ( & V_6 -> V_6 ) != ! ! V_2 -> V_96 . V_125 )
return true ;
if ( F_62 () == V_126 )
return false ;
return ! ! V_2 -> V_127 . V_11 . V_128 ;
}
void F_63 ( struct V_85 * V_88 )
{
union V_31 * V_129 ;
struct V_130 * V_124 ;
if ( V_87 || ! V_88 -> V_124 )
return;
F_64 ( V_88 ) ;
F_65 ( V_88 ) ;
if ( ! F_66 ( V_88 ) )
return;
V_129 = F_67 ( F_68 ( V_88 -> V_124 ) , & V_131 , 3 ,
V_132 , NULL ) ;
if ( ! V_129 )
return;
if ( V_129 -> type == V_43 && V_129 -> integer . V_40 == 1 ) {
V_124 = F_69 ( V_88 ) ;
V_124 -> V_133 = 1 ;
}
F_70 ( V_129 ) ;
}
void F_71 ( struct V_85 * V_88 )
{
if ( V_87 || ! V_88 -> V_124 )
return;
F_72 ( V_88 ) ;
F_73 ( V_88 ) ;
}
static struct V_1 * F_74 ( struct V_5 * V_6 )
{
struct V_83 * V_83 = F_36 ( V_6 ) ;
bool V_134 ;
T_8 V_135 ;
V_134 = F_75 ( V_83 ) ;
V_135 = ( F_76 ( V_83 -> V_136 ) << 16 ) | F_77 ( V_83 -> V_136 ) ;
return F_78 ( F_46 ( V_6 -> V_89 ) , V_135 ,
V_134 ) ;
}
static void F_79 ( struct V_83 * V_90 ,
T_2 V_17 )
{
struct V_130 * V_124 = F_69 ( V_90 -> V_88 ) ;
int V_40 ;
union V_31 * V_129 , * V_38 ;
if ( V_124 -> V_133 )
V_90 -> V_137 = 0 ;
V_129 = F_67 ( V_17 , & V_131 , 3 ,
V_138 , NULL ) ;
if ( ! V_129 )
return;
if ( V_129 -> type == V_80 && V_129 -> V_37 . V_41 == 5 ) {
V_38 = V_129 -> V_37 . V_38 ;
if ( V_38 [ 0 ] . type == V_43 ) {
V_40 = ( int ) V_38 [ 0 ] . integer . V_40 / 1000 ;
if ( V_40 < V_139 )
V_90 -> V_137 = V_40 ;
}
if ( V_38 [ 3 ] . type == V_43 ) {
V_40 = ( int ) V_38 [ 3 ] . integer . V_40 / 1000 ;
if ( V_40 < V_140 )
V_90 -> V_141 = V_40 ;
}
}
F_70 ( V_129 ) ;
}
static void F_80 ( struct V_5 * V_6 )
{
struct V_83 * V_83 = F_36 ( V_6 ) ;
struct V_1 * V_2 = F_46 ( V_6 ) ;
if ( ! V_2 )
return;
F_79 ( V_83 , V_2 -> V_17 ) ;
F_42 ( V_2 , V_83 ) ;
if ( ! V_2 -> V_96 . V_11 . V_142 )
return;
F_81 ( V_6 , true ) ;
F_59 ( V_83 , false ) ;
}
static void F_82 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_46 ( V_6 ) ;
if ( ! V_2 )
return;
F_83 ( V_2 ) ;
if ( V_2 -> V_96 . V_11 . V_142 )
F_81 ( V_6 , false ) ;
}
static bool F_84 ( struct V_5 * V_6 )
{
return F_85 ( V_6 ) ;
}
struct V_143 * F_86 ( struct V_85 * V_88 )
{
struct V_144 * V_145 ;
if ( ! V_146 )
return NULL ;
V_145 = V_146 ( & V_88 -> V_6 ) ;
if ( ! V_145 )
return NULL ;
return F_87 ( V_145 , V_147 ) ;
}
static int T_9 F_88 ( void )
{
int V_12 ;
if ( V_148 . V_149 & V_150 ) {
F_89 ( L_14 ) ;
F_90 () ;
}
if ( V_148 . V_149 & V_151 ) {
F_89 ( L_15 ) ;
F_91 () ;
}
V_12 = F_92 ( & V_152 ) ;
if ( V_12 )
return 0 ;
F_93 ( & V_153 ) ;
F_94 () ;
F_95 () ;
return 0 ;
}
