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
V_1 = NULL ;
for ( V_62 = V_59 -> V_63 ; V_62 ; V_62 = V_62 -> V_64 ) {
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
return - V_65 ;
}
static void F_17 ( struct V_66 * V_67 )
{
struct V_68 * V_69 ;
struct V_70 * V_71 ;
V_69 = F_18 ( V_67 , struct V_68 , V_72 . V_73 . V_67 ) ;
V_71 = F_19 ( V_69 ) ;
F_20 ( V_71 -> V_63 ) ;
}
static void F_21 ( struct V_66 * V_67 )
{
struct V_74 * V_73 ;
struct V_58 * V_58 ;
V_73 = F_18 ( V_67 , struct V_74 , V_67 ) ;
V_58 = F_22 ( V_73 -> V_59 ) ;
if ( V_58 -> V_75 )
V_58 -> V_75 = false ;
if ( V_58 -> V_76 == V_77 ) {
F_23 ( V_58 ) ;
F_24 ( & V_58 -> V_59 ) ;
return;
}
if ( V_58 -> V_78 )
F_25 ( V_58 ) ;
F_23 ( V_58 ) ;
F_24 ( & V_58 -> V_59 ) ;
if ( V_58 -> V_79 )
F_20 ( V_58 -> V_79 ) ;
}
T_3 F_26 ( struct V_68 * V_59 )
{
return F_27 ( V_59 , NULL , F_17 ) ;
}
T_3 F_28 ( struct V_68 * V_59 ,
struct V_58 * V_58 )
{
return F_27 ( V_59 , & V_58 -> V_59 , F_21 ) ;
}
static T_5 F_29 ( struct V_58 * V_80 )
{
int V_81 , V_82 ;
if ( V_80 -> V_83 )
V_82 = V_84 ;
else
V_82 = V_85 ;
V_81 = F_30 ( & V_80 -> V_59 , NULL , V_82 ) ;
if ( V_81 < 0 )
return V_86 ;
switch ( V_81 ) {
case V_87 :
return V_88 ;
case V_89 :
return V_90 ;
case V_91 :
return V_92 ;
case V_84 :
return V_93 ;
case V_85 :
return V_77 ;
}
return V_86 ;
}
static bool F_31 ( struct V_58 * V_59 )
{
struct V_68 * V_69 = F_32 ( & V_59 -> V_59 ) ;
return V_69 ? F_33 ( V_69 ) : false ;
}
static int F_34 ( struct V_58 * V_59 , T_5 V_94 )
{
struct V_68 * V_69 = F_32 ( & V_59 -> V_59 ) ;
static const T_6 V_95 [] = {
[ V_88 ] = V_87 ,
[ V_90 ] = V_89 ,
[ V_92 ] = V_91 ,
[ V_93 ] = V_85 ,
[ V_77 ] = V_85 ,
} ;
int error = - V_96 ;
if ( ! V_69 || F_35 ( V_69 -> V_1 , L_7 ) )
return - V_65 ;
switch ( V_94 ) {
case V_77 :
if ( F_36 ( & V_59 -> V_59 , V_97 ) ==
V_98 ) {
error = - V_99 ;
break;
}
case V_88 :
case V_90 :
case V_92 :
case V_93 :
error = F_37 ( V_69 , V_95 [ V_94 ] ) ;
}
if ( ! error )
F_38 ( & V_59 -> V_59 , L_8 ,
F_39 ( V_95 [ V_94 ] ) ) ;
return error ;
}
static bool F_40 ( struct V_58 * V_59 )
{
struct V_68 * V_69 = F_32 ( & V_59 -> V_59 ) ;
return V_69 ? F_41 ( V_69 ) : false ;
}
static void F_42 ( struct V_61 * V_63 , bool V_100 )
{
while ( V_63 -> V_64 ) {
if ( ! F_43 ( & V_63 -> V_101 -> V_59 , V_100 ) )
return;
V_63 = V_63 -> V_64 ;
}
if ( V_63 -> V_102 )
F_43 ( V_63 -> V_102 , V_100 ) ;
}
static int F_44 ( struct V_58 * V_59 , bool V_100 )
{
if ( F_40 ( V_59 ) )
return F_43 ( & V_59 -> V_59 , V_100 ) ;
F_42 ( V_59 -> V_63 , V_100 ) ;
return 0 ;
}
static void F_45 ( struct V_61 * V_63 , bool V_100 )
{
while ( V_63 -> V_64 ) {
struct V_58 * V_102 = V_63 -> V_101 ;
if ( V_102 -> V_103 )
return;
if ( ! F_46 ( & V_102 -> V_59 , V_100 ) )
return;
V_63 = V_63 -> V_64 ;
}
if ( V_63 -> V_102 )
F_46 ( V_63 -> V_102 , V_100 ) ;
}
static int F_47 ( struct V_58 * V_59 , bool V_100 )
{
if ( V_59 -> V_103 && ! V_59 -> V_104 )
return 0 ;
if ( ! F_46 ( & V_59 -> V_59 , V_100 ) )
return 0 ;
F_45 ( V_59 -> V_63 , V_100 ) ;
return 0 ;
}
void F_48 ( struct V_61 * V_63 )
{
if ( V_105 || ! V_63 -> V_102 )
return;
F_49 ( V_63 ) ;
F_50 ( V_63 ) ;
}
void F_51 ( struct V_61 * V_63 )
{
if ( V_105 || ! V_63 -> V_102 )
return;
F_52 ( V_63 ) ;
F_53 ( V_63 ) ;
}
static struct V_68 * F_54 ( struct V_106 * V_59 )
{
struct V_58 * V_58 = F_22 ( V_59 ) ;
bool V_107 ;
T_7 V_108 ;
V_107 = F_55 ( V_58 ) ;
V_108 = ( F_56 ( V_58 -> V_109 ) << 16 ) | F_57 ( V_58 -> V_109 ) ;
return F_58 ( F_32 ( V_59 -> V_64 ) , V_108 ,
V_107 ) ;
}
static void F_59 ( struct V_106 * V_59 )
{
struct V_58 * V_58 = F_22 ( V_59 ) ;
struct V_68 * V_69 = F_32 ( V_59 ) ;
if ( ! V_69 )
return;
F_28 ( V_69 , V_58 ) ;
if ( ! V_69 -> V_72 . V_110 . V_111 )
return;
F_60 ( V_59 , true ) ;
F_44 ( V_58 , false ) ;
if ( V_69 -> V_72 . V_110 . V_112 )
F_61 ( V_59 , true ) ;
}
static void F_62 ( struct V_106 * V_59 )
{
struct V_68 * V_69 = F_32 ( V_59 ) ;
if ( ! V_69 )
return;
F_63 ( V_69 ) ;
if ( V_69 -> V_72 . V_110 . V_111 ) {
F_60 ( V_59 , false ) ;
F_61 ( V_59 , false ) ;
}
}
static bool F_64 ( struct V_106 * V_59 )
{
return F_65 ( V_59 ) ;
}
static int T_8 F_66 ( void )
{
int V_113 ;
if ( V_114 . V_115 & V_116 ) {
F_67 ( L_9 ) ;
F_68 () ;
}
if ( V_114 . V_115 & V_117 ) {
F_67 ( L_10 ) ;
F_69 () ;
}
V_113 = F_70 ( & V_118 ) ;
if ( V_113 )
return 0 ;
F_71 ( & V_119 ) ;
F_72 () ;
F_73 () ;
return 0 ;
}
