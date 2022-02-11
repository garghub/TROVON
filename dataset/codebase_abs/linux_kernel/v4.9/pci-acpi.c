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
static T_5 F_40 ( struct V_58 * V_59 )
{
struct V_69 * V_70 = F_32 ( & V_59 -> V_59 ) ;
static const T_5 V_96 [] = {
[ V_88 ] = V_89 ,
[ V_90 ] = V_91 ,
[ V_92 ] = V_93 ,
[ V_85 ] = V_94 ,
[ V_86 ] = V_78 ,
} ;
int V_95 ;
if ( ! V_70 || ! F_33 ( V_70 ) )
return V_101 ;
if ( F_41 ( V_70 , & V_95 ) || V_95 == V_102 )
return V_101 ;
return V_96 [ V_95 ] ;
}
static bool F_42 ( struct V_58 * V_59 )
{
struct V_69 * V_70 = F_32 ( & V_59 -> V_59 ) ;
return V_70 ? F_43 ( V_70 ) : false ;
}
static void F_44 ( struct V_61 * V_65 , bool V_103 )
{
while ( V_65 -> V_66 ) {
if ( ! F_45 ( & V_65 -> V_104 -> V_59 , V_103 ) )
return;
V_65 = V_65 -> V_66 ;
}
if ( V_65 -> V_105 )
F_45 ( V_65 -> V_105 , V_103 ) ;
}
static int F_46 ( struct V_58 * V_59 , bool V_103 )
{
if ( F_42 ( V_59 ) )
return F_45 ( & V_59 -> V_59 , V_103 ) ;
F_44 ( V_59 -> V_65 , V_103 ) ;
return 0 ;
}
static void F_47 ( struct V_61 * V_65 , bool V_103 )
{
while ( V_65 -> V_66 ) {
struct V_58 * V_105 = V_65 -> V_104 ;
if ( V_105 -> V_106 )
return;
if ( ! F_48 ( & V_105 -> V_59 , V_103 ) )
return;
V_65 = V_65 -> V_66 ;
}
if ( V_65 -> V_105 )
F_48 ( V_65 -> V_105 , V_103 ) ;
}
static int F_49 ( struct V_58 * V_59 , bool V_103 )
{
if ( V_59 -> V_106 && ! V_59 -> V_107 )
return 0 ;
if ( ! F_48 ( & V_59 -> V_59 , V_103 ) )
return 0 ;
F_47 ( V_59 -> V_65 , V_103 ) ;
return 0 ;
}
static bool F_50 ( struct V_58 * V_59 )
{
struct V_69 * V_70 = F_32 ( & V_59 -> V_59 ) ;
if ( ! V_70 || ! F_33 ( V_70 ) )
return false ;
if ( F_51 ( & V_59 -> V_59 ) != ! ! V_70 -> V_73 . V_108 )
return true ;
if ( F_52 () == V_109 )
return false ;
return ! ! V_70 -> V_110 . V_111 . V_112 ;
}
void F_53 ( struct V_61 * V_65 )
{
union V_6 * V_113 ;
struct V_114 * V_105 ;
if ( V_63 || ! V_65 -> V_105 )
return;
F_54 ( V_65 ) ;
F_55 ( V_65 ) ;
if ( ! F_56 ( V_65 ) )
return;
V_113 = F_57 ( F_58 ( V_65 -> V_105 ) , V_115 , 3 ,
V_116 , NULL ) ;
if ( ! V_113 )
return;
if ( V_113 -> type == V_18 && V_113 -> integer . V_15 == 1 ) {
V_105 = F_59 ( V_65 ) ;
V_105 -> V_117 = 1 ;
}
F_60 ( V_113 ) ;
}
void F_61 ( struct V_61 * V_65 )
{
if ( V_63 || ! V_65 -> V_105 )
return;
F_62 ( V_65 ) ;
F_63 ( V_65 ) ;
}
static struct V_69 * F_64 ( struct V_118 * V_59 )
{
struct V_58 * V_58 = F_22 ( V_59 ) ;
bool V_119 ;
T_7 V_120 ;
V_119 = F_65 ( V_58 ) ;
V_120 = ( F_66 ( V_58 -> V_121 ) << 16 ) | F_67 ( V_58 -> V_121 ) ;
return F_68 ( F_32 ( V_59 -> V_66 ) , V_120 ,
V_119 ) ;
}
static void F_69 ( struct V_58 * V_81 ,
T_2 V_1 )
{
struct V_114 * V_105 = F_59 ( V_81 -> V_65 ) ;
int V_15 ;
union V_6 * V_113 , * V_13 ;
if ( V_105 -> V_117 )
V_81 -> V_122 = 0 ;
V_113 = F_57 ( V_1 , V_115 , 3 ,
V_123 , NULL ) ;
if ( ! V_113 )
return;
if ( V_113 -> type == V_55 && V_113 -> V_12 . V_16 == 5 ) {
V_13 = V_113 -> V_12 . V_13 ;
if ( V_13 [ 0 ] . type == V_18 ) {
V_15 = ( int ) V_13 [ 0 ] . integer . V_15 / 1000 ;
if ( V_15 < V_124 )
V_81 -> V_122 = V_15 ;
}
if ( V_13 [ 3 ] . type == V_18 ) {
V_15 = ( int ) V_13 [ 3 ] . integer . V_15 / 1000 ;
if ( V_15 < V_125 )
V_81 -> V_126 = V_15 ;
}
}
F_60 ( V_113 ) ;
}
static void F_70 ( struct V_118 * V_59 )
{
struct V_58 * V_58 = F_22 ( V_59 ) ;
struct V_69 * V_70 = F_32 ( V_59 ) ;
if ( ! V_70 )
return;
F_69 ( V_58 , V_70 -> V_1 ) ;
F_28 ( V_70 , V_58 ) ;
if ( ! V_70 -> V_73 . V_111 . V_127 )
return;
F_71 ( V_59 , true ) ;
F_46 ( V_58 , false ) ;
if ( V_70 -> V_73 . V_111 . V_128 )
F_72 ( V_59 , true ) ;
}
static void F_73 ( struct V_118 * V_59 )
{
struct V_69 * V_70 = F_32 ( V_59 ) ;
if ( ! V_70 )
return;
F_74 ( V_70 ) ;
if ( V_70 -> V_73 . V_111 . V_127 ) {
F_71 ( V_59 , false ) ;
F_72 ( V_59 , false ) ;
}
}
static bool F_75 ( struct V_118 * V_59 )
{
return F_76 ( V_59 ) ;
}
struct V_129 * F_77 ( struct V_61 * V_65 )
{
struct V_130 * V_131 ;
if ( ! V_132 )
return NULL ;
V_131 = V_132 ( & V_65 -> V_59 ) ;
if ( ! V_131 )
return NULL ;
return F_78 ( V_131 , V_133 ) ;
}
static int T_8 F_79 ( void )
{
int V_134 ;
if ( V_135 . V_136 & V_137 ) {
F_80 ( L_9 ) ;
F_81 () ;
}
if ( V_135 . V_136 & V_138 ) {
F_80 ( L_10 ) ;
F_82 () ;
}
V_134 = F_83 ( & V_139 ) ;
if ( V_134 )
return 0 ;
F_84 ( & V_140 ) ;
F_85 () ;
F_86 () ;
return 0 ;
}
