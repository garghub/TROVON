T_1 F_1 ( T_2 V_1 )
{
T_3 V_2 = V_3 ;
unsigned long long V_4 ;
if ( V_1 )
V_2 = F_2 ( V_1 , V_5 ,
NULL , & V_4 ) ;
if ( F_3 ( V_2 ) )
return 0 ;
return ( T_1 ) V_4 ;
}
static T_3 F_4 ( union V_6 * V_7 ,
struct V_8 * V_9 )
{
int V_10 ;
union V_6 * V_11 = V_7 -> V_12 . V_13 ;
T_4 V_14 = V_11 [ 1 ] . integer . V_15 ;
switch ( V_14 ) {
case 1 :
if ( V_7 -> V_12 . V_16 != 6 )
return V_17 ;
for ( V_10 = 2 ; V_10 < 6 ; V_10 ++ )
if ( V_11 [ V_10 ] . type != V_18 )
return V_17 ;
V_9 -> V_19 = & V_9 -> V_20 ;
V_9 -> V_19 -> V_14 = V_14 ;
V_9 -> V_19 -> V_21 = V_11 [ 2 ] . integer . V_15 ;
V_9 -> V_19 -> V_22 = V_11 [ 3 ] . integer . V_15 ;
V_9 -> V_19 -> V_23 = V_11 [ 4 ] . integer . V_15 ;
V_9 -> V_19 -> V_24 = V_11 [ 5 ] . integer . V_15 ;
break;
default:
F_5 ( V_25
L_1 ,
V_26 , V_14 ) ;
return V_17 ;
}
return V_27 ;
}
static T_3 F_6 ( union V_6 * V_7 ,
struct V_8 * V_9 )
{
int V_10 ;
union V_6 * V_11 = V_7 -> V_12 . V_13 ;
T_4 V_14 = V_11 [ 1 ] . integer . V_15 ;
switch ( V_14 ) {
case 1 :
if ( V_7 -> V_12 . V_16 != 5 )
return V_17 ;
for ( V_10 = 2 ; V_10 < 5 ; V_10 ++ )
if ( V_11 [ V_10 ] . type != V_18 )
return V_17 ;
V_9 -> V_28 = & V_9 -> V_29 ;
V_9 -> V_28 -> V_14 = V_14 ;
V_9 -> V_28 -> V_30 = V_11 [ 2 ] . integer . V_15 ;
V_9 -> V_28 -> V_31 = V_11 [ 3 ] . integer . V_15 ;
V_9 -> V_28 -> V_32 = V_11 [ 4 ] . integer . V_15 ;
break;
default:
F_5 ( V_25
L_2 ,
V_26 , V_14 ) ;
return V_17 ;
}
return V_27 ;
}
static T_3 F_7 ( union V_6 * V_7 ,
struct V_8 * V_9 )
{
int V_10 ;
union V_6 * V_11 = V_7 -> V_12 . V_13 ;
T_4 V_14 = V_11 [ 1 ] . integer . V_15 ;
switch ( V_14 ) {
case 1 :
if ( V_7 -> V_12 . V_16 != 18 )
return V_17 ;
for ( V_10 = 2 ; V_10 < 18 ; V_10 ++ )
if ( V_11 [ V_10 ] . type != V_18 )
return V_17 ;
V_9 -> V_33 = & V_9 -> V_34 ;
V_9 -> V_33 -> V_14 = V_14 ;
V_9 -> V_33 -> V_35 = V_11 [ 2 ] . integer . V_15 ;
V_9 -> V_33 -> V_36 = V_11 [ 3 ] . integer . V_15 ;
V_9 -> V_33 -> V_37 = V_11 [ 4 ] . integer . V_15 ;
V_9 -> V_33 -> V_38 = V_11 [ 5 ] . integer . V_15 ;
V_9 -> V_33 -> V_39 = V_11 [ 6 ] . integer . V_15 ;
V_9 -> V_33 -> V_40 = V_11 [ 7 ] . integer . V_15 ;
V_9 -> V_33 -> V_41 = V_11 [ 8 ] . integer . V_15 ;
V_9 -> V_33 -> V_42 = V_11 [ 9 ] . integer . V_15 ;
V_9 -> V_33 -> V_43 = V_11 [ 10 ] . integer . V_15 ;
V_9 -> V_33 -> V_44 = V_11 [ 11 ] . integer . V_15 ;
V_9 -> V_33 -> V_45 = V_11 [ 12 ] . integer . V_15 ;
V_9 -> V_33 -> V_46 = V_11 [ 13 ] . integer . V_15 ;
V_9 -> V_33 -> V_47 = V_11 [ 14 ] . integer . V_15 ;
V_9 -> V_33 -> V_48 = V_11 [ 15 ] . integer . V_15 ;
V_9 -> V_33 -> V_49 = V_11 [ 16 ] . integer . V_15 ;
V_9 -> V_33 -> V_50 = V_11 [ 17 ] . integer . V_15 ;
break;
default:
F_5 ( V_25
L_3 ,
V_26 , V_14 ) ;
return V_17 ;
}
return V_27 ;
}
static T_3 F_8 ( T_2 V_1 , struct V_8 * V_9 )
{
T_3 V_2 ;
struct V_51 V_52 = { V_53 , NULL } ;
union V_6 * V_12 , * V_7 , * V_11 ;
T_4 type ;
int V_10 ;
memset ( V_9 , 0 , sizeof( struct V_8 ) ) ;
V_2 = F_9 ( V_1 , L_4 , NULL , & V_52 ) ;
if ( F_3 ( V_2 ) )
return V_2 ;
V_12 = (union V_6 * ) V_52 . V_54 ;
if ( V_12 -> type != V_55 ) {
V_2 = V_17 ;
goto exit;
}
for ( V_10 = 0 ; V_10 < V_12 -> V_12 . V_16 ; V_10 ++ ) {
V_7 = & V_12 -> V_12 . V_13 [ V_10 ] ;
if ( V_7 -> type != V_55 ) {
V_2 = V_17 ;
goto exit;
}
V_11 = V_7 -> V_12 . V_13 ;
if ( V_11 [ 0 ] . type != V_18 ||
V_11 [ 1 ] . type != V_18 ) {
V_2 = V_17 ;
goto exit;
}
type = V_11 [ 0 ] . integer . V_15 ;
switch ( type ) {
case 0 :
V_2 = F_4 ( V_7 , V_9 ) ;
if ( F_3 ( V_2 ) )
goto exit;
break;
case 1 :
V_2 = F_6 ( V_7 , V_9 ) ;
if ( F_3 ( V_2 ) )
goto exit;
break;
case 2 :
V_2 = F_7 ( V_7 , V_9 ) ;
if ( F_3 ( V_2 ) )
goto exit;
break;
default:
F_5 ( V_56 L_5 ,
V_26 , type ) ;
V_2 = V_17 ;
goto exit;
}
}
exit:
F_10 ( V_52 . V_54 ) ;
return V_2 ;
}
static T_3 F_11 ( T_2 V_1 , struct V_8 * V_57 )
{
T_3 V_2 ;
struct V_51 V_52 = { V_53 , NULL } ;
union V_6 * V_12 , * V_11 ;
int V_10 ;
memset ( V_57 , 0 , sizeof( struct V_8 ) ) ;
V_2 = F_9 ( V_1 , L_6 , NULL , & V_52 ) ;
if ( F_3 ( V_2 ) )
return V_2 ;
V_12 = (union V_6 * ) V_52 . V_54 ;
if ( V_12 -> type != V_55 ||
V_12 -> V_12 . V_16 != 4 ) {
V_2 = V_17 ;
goto exit;
}
V_11 = V_12 -> V_12 . V_13 ;
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ ) {
if ( V_11 [ V_10 ] . type != V_18 ) {
V_2 = V_17 ;
goto exit;
}
}
V_57 -> V_19 = & V_57 -> V_20 ;
V_57 -> V_19 -> V_14 = 1 ;
V_57 -> V_19 -> V_21 = V_11 [ 0 ] . integer . V_15 ;
V_57 -> V_19 -> V_22 = V_11 [ 1 ] . integer . V_15 ;
V_57 -> V_19 -> V_23 = V_11 [ 2 ] . integer . V_15 ;
V_57 -> V_19 -> V_24 = V_11 [ 3 ] . integer . V_15 ;
exit:
F_10 ( V_52 . V_54 ) ;
return V_2 ;
}
int F_12 ( struct V_58 * V_59 , struct V_8 * V_57 )
{
T_3 V_2 ;
T_2 V_1 , V_60 ;
struct V_61 * V_62 ;
if ( V_63 )
return - V_64 ;
V_1 = NULL ;
for ( V_62 = V_59 -> V_65 ; V_62 ; V_62 = V_62 -> V_66 ) {
V_1 = F_13 ( V_62 ) ;
if ( V_1 )
break;
}
while ( V_1 ) {
V_2 = F_8 ( V_1 , V_57 ) ;
if ( F_14 ( V_2 ) )
return 0 ;
V_2 = F_11 ( V_1 , V_57 ) ;
if ( F_14 ( V_2 ) )
return 0 ;
if ( F_15 ( V_1 ) )
break;
V_2 = F_16 ( V_1 , & V_60 ) ;
if ( F_3 ( V_2 ) )
break;
V_1 = V_60 ;
}
return - V_64 ;
}
static void F_17 ( struct V_67 * V_68 )
{
struct V_69 * V_70 ;
struct V_71 * V_72 ;
V_70 = F_18 ( V_68 , struct V_69 , V_73 . V_74 . V_68 ) ;
V_72 = F_19 ( V_70 ) ;
F_20 ( V_72 -> V_65 ) ;
}
static void F_21 ( struct V_67 * V_68 )
{
struct V_75 * V_74 ;
struct V_58 * V_58 ;
V_74 = F_18 ( V_68 , struct V_75 , V_68 ) ;
V_58 = F_22 ( V_74 -> V_59 ) ;
if ( V_58 -> V_76 )
V_58 -> V_76 = false ;
if ( V_58 -> V_77 == V_78 ) {
F_23 ( V_58 ) ;
F_24 ( & V_58 -> V_59 ) ;
return;
}
if ( V_58 -> V_79 )
F_25 ( V_58 ) ;
F_23 ( V_58 ) ;
F_24 ( & V_58 -> V_59 ) ;
F_20 ( V_58 -> V_80 ) ;
}
T_3 F_26 ( struct V_69 * V_59 )
{
return F_27 ( V_59 , NULL , F_17 ) ;
}
T_3 F_28 ( struct V_69 * V_59 ,
struct V_58 * V_58 )
{
return F_27 ( V_59 , & V_58 -> V_59 , F_21 ) ;
}
static T_5 F_29 ( struct V_58 * V_81 )
{
int V_82 , V_83 ;
if ( V_81 -> V_84 )
V_83 = V_85 ;
else
V_83 = V_86 ;
V_82 = F_30 ( & V_81 -> V_59 , NULL , V_83 ) ;
if ( V_82 < 0 )
return V_87 ;
switch ( V_82 ) {
case V_88 :
return V_89 ;
case V_90 :
return V_91 ;
case V_92 :
return V_93 ;
case V_85 :
return V_94 ;
case V_86 :
return V_78 ;
}
return V_87 ;
}
static bool F_31 ( struct V_58 * V_59 )
{
struct V_69 * V_70 = F_32 ( & V_59 -> V_59 ) ;
return V_70 ? F_33 ( V_70 ) : false ;
}
static int F_34 ( struct V_58 * V_59 , T_5 V_95 )
{
struct V_69 * V_70 = F_32 ( & V_59 -> V_59 ) ;
static const T_6 V_96 [] = {
[ V_89 ] = V_88 ,
[ V_91 ] = V_90 ,
[ V_93 ] = V_92 ,
[ V_94 ] = V_85 ,
[ V_78 ] = V_86 ,
} ;
int error = - V_97 ;
if ( ! V_70 || F_35 ( V_70 -> V_1 , L_7 ) )
return - V_64 ;
switch ( V_95 ) {
case V_78 :
if ( F_36 ( & V_59 -> V_59 , V_98 ) ==
V_99 ) {
error = - V_100 ;
break;
}
case V_89 :
case V_91 :
case V_93 :
case V_94 :
error = F_37 ( V_70 , V_96 [ V_95 ] ) ;
}
if ( ! error )
F_38 ( & V_59 -> V_59 , L_8 ,
F_39 ( V_96 [ V_95 ] ) ) ;
return error ;
}
static bool F_40 ( struct V_58 * V_59 )
{
struct V_69 * V_70 = F_32 ( & V_59 -> V_59 ) ;
return V_70 ? F_41 ( V_70 ) : false ;
}
static void F_42 ( struct V_61 * V_65 , bool V_101 )
{
while ( V_65 -> V_66 ) {
if ( ! F_43 ( & V_65 -> V_102 -> V_59 , V_101 ) )
return;
V_65 = V_65 -> V_66 ;
}
if ( V_65 -> V_103 )
F_43 ( V_65 -> V_103 , V_101 ) ;
}
static int F_44 ( struct V_58 * V_59 , bool V_101 )
{
if ( F_40 ( V_59 ) )
return F_43 ( & V_59 -> V_59 , V_101 ) ;
F_42 ( V_59 -> V_65 , V_101 ) ;
return 0 ;
}
static void F_45 ( struct V_61 * V_65 , bool V_101 )
{
while ( V_65 -> V_66 ) {
struct V_58 * V_103 = V_65 -> V_102 ;
if ( V_103 -> V_104 )
return;
if ( ! F_46 ( & V_103 -> V_59 , V_101 ) )
return;
V_65 = V_65 -> V_66 ;
}
if ( V_65 -> V_103 )
F_46 ( V_65 -> V_103 , V_101 ) ;
}
static int F_47 ( struct V_58 * V_59 , bool V_101 )
{
if ( V_59 -> V_104 && ! V_59 -> V_105 )
return 0 ;
if ( ! F_46 ( & V_59 -> V_59 , V_101 ) )
return 0 ;
F_45 ( V_59 -> V_65 , V_101 ) ;
return 0 ;
}
static bool F_48 ( struct V_58 * V_59 )
{
struct V_69 * V_70 = F_32 ( & V_59 -> V_59 ) ;
if ( ! V_70 || ! F_33 ( V_70 ) )
return false ;
if ( F_49 ( & V_59 -> V_59 ) != ! ! V_70 -> V_73 . V_106 )
return true ;
if ( F_50 () == V_107 )
return false ;
return ! ! V_70 -> V_108 . V_109 . V_110 ;
}
void F_51 ( struct V_61 * V_65 )
{
union V_6 * V_111 ;
struct V_112 * V_103 ;
if ( V_63 || ! V_65 -> V_103 )
return;
F_52 ( V_65 ) ;
F_53 ( V_65 ) ;
if ( ! F_54 ( V_65 ) )
return;
V_111 = F_55 ( F_56 ( V_65 -> V_103 ) , V_113 , 3 ,
V_114 , NULL ) ;
if ( ! V_111 )
return;
if ( V_111 -> type == V_18 && V_111 -> integer . V_15 == 1 ) {
V_103 = F_57 ( V_65 ) ;
V_103 -> V_115 = 1 ;
}
F_58 ( V_111 ) ;
}
void F_59 ( struct V_61 * V_65 )
{
if ( V_63 || ! V_65 -> V_103 )
return;
F_60 ( V_65 ) ;
F_61 ( V_65 ) ;
}
static struct V_69 * F_62 ( struct V_116 * V_59 )
{
struct V_58 * V_58 = F_22 ( V_59 ) ;
bool V_117 ;
T_7 V_118 ;
V_117 = F_63 ( V_58 ) ;
V_118 = ( F_64 ( V_58 -> V_119 ) << 16 ) | F_65 ( V_58 -> V_119 ) ;
return F_66 ( F_32 ( V_59 -> V_66 ) , V_118 ,
V_117 ) ;
}
static void F_67 ( struct V_58 * V_81 ,
T_2 V_1 )
{
struct V_112 * V_103 = F_57 ( V_81 -> V_65 ) ;
int V_15 ;
union V_6 * V_111 , * V_13 ;
if ( V_103 -> V_115 )
V_81 -> V_120 = 0 ;
V_111 = F_55 ( V_1 , V_113 , 3 ,
V_121 , NULL ) ;
if ( ! V_111 )
return;
if ( V_111 -> type == V_55 && V_111 -> V_12 . V_16 == 5 ) {
V_13 = V_111 -> V_12 . V_13 ;
if ( V_13 [ 0 ] . type == V_18 ) {
V_15 = ( int ) V_13 [ 0 ] . integer . V_15 / 1000 ;
if ( V_15 < V_122 )
V_81 -> V_120 = V_15 ;
}
if ( V_13 [ 3 ] . type == V_18 ) {
V_15 = ( int ) V_13 [ 3 ] . integer . V_15 / 1000 ;
if ( V_15 < V_123 )
V_81 -> V_124 = V_15 ;
}
}
F_58 ( V_111 ) ;
}
static void F_68 ( struct V_116 * V_59 )
{
struct V_58 * V_58 = F_22 ( V_59 ) ;
struct V_69 * V_70 = F_32 ( V_59 ) ;
if ( ! V_70 )
return;
F_67 ( V_58 , V_70 -> V_1 ) ;
F_28 ( V_70 , V_58 ) ;
if ( ! V_70 -> V_73 . V_109 . V_125 )
return;
F_69 ( V_59 , true ) ;
F_44 ( V_58 , false ) ;
if ( V_70 -> V_73 . V_109 . V_126 )
F_70 ( V_59 , true ) ;
}
static void F_71 ( struct V_116 * V_59 )
{
struct V_69 * V_70 = F_32 ( V_59 ) ;
if ( ! V_70 )
return;
F_72 ( V_70 ) ;
if ( V_70 -> V_73 . V_109 . V_125 ) {
F_69 ( V_59 , false ) ;
F_70 ( V_59 , false ) ;
}
}
static bool F_73 ( struct V_116 * V_59 )
{
return F_74 ( V_59 ) ;
}
struct V_127 * F_75 ( struct V_61 * V_65 )
{
struct V_128 * V_129 ;
if ( ! V_130 )
return NULL ;
V_129 = V_130 ( & V_65 -> V_59 ) ;
if ( ! V_129 )
return NULL ;
return F_76 ( V_129 , V_131 ) ;
}
static int T_8 F_77 ( void )
{
int V_132 ;
if ( V_133 . V_134 & V_135 ) {
F_78 ( L_9 ) ;
F_79 () ;
}
if ( V_133 . V_134 & V_136 ) {
F_78 ( L_10 ) ;
F_80 () ;
}
V_132 = F_81 ( & V_137 ) ;
if ( V_132 )
return 0 ;
F_82 ( & V_138 ) ;
F_83 () ;
F_84 () ;
return 0 ;
}
