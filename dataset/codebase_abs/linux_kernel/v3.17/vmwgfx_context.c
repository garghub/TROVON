static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct {
T_1 V_7 ;
T_2 V_8 ;
} * V_9 ;
if ( V_2 -> V_10 -> V_11 == V_12 ) {
F_3 ( & V_6 -> V_13 ) ;
F_4 ( V_4 -> V_14 ) ;
F_3 ( & V_6 -> V_15 ) ;
( void ) F_5 ( & V_4 -> V_16 ) ;
( void ) V_12 ( V_2 ) ;
F_6 ( & V_6 -> V_15 ) ;
if ( V_6 -> V_17 != NULL &&
! V_6 -> V_18 )
F_7 ( V_6 , NULL ) ;
F_6 ( & V_6 -> V_13 ) ;
return;
}
F_8 ( V_6 ) ;
V_9 = F_9 ( V_6 , sizeof( * V_9 ) ) ;
if ( F_10 ( V_9 == NULL ) ) {
F_11 ( L_1
L_2 ) ;
return;
}
V_9 -> V_7 . V_19 = F_12 ( V_20 ) ;
V_9 -> V_7 . V_21 = F_12 ( sizeof( V_9 -> V_8 ) ) ;
V_9 -> V_8 . V_22 = F_12 ( V_2 -> V_19 ) ;
F_13 ( V_6 , sizeof( * V_9 ) ) ;
F_14 ( V_6 , false ) ;
}
static int F_15 ( struct V_5 * V_6 ,
struct V_1 * V_2 ,
void (* F_16) ( struct V_1 * V_2 ) )
{
int V_23 ;
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
V_23 = F_17 ( V_6 , V_2 , true ,
F_16 , & V_24 ) ;
V_2 -> V_25 = V_26 ;
if ( F_10 ( V_23 != 0 ) )
goto V_27;
if ( V_6 -> V_28 ) {
V_4 -> V_14 = F_18 ( V_6 ) ;
if ( F_10 ( F_19 ( V_4 -> V_14 ) ) ) {
V_23 = F_20 ( V_4 -> V_14 ) ;
V_4 -> V_14 = NULL ;
goto V_27;
}
}
memset ( & V_4 -> V_16 , 0 , sizeof( V_4 -> V_16 ) ) ;
F_21 ( & V_4 -> V_16 . V_29 ) ;
F_22 ( V_2 , F_1 ) ;
return 0 ;
V_27:
if ( F_16 )
F_16 ( V_2 ) ;
else
F_23 ( V_2 ) ;
return V_23 ;
}
static int F_24 ( struct V_5 * V_6 ,
struct V_1 * V_2 ,
void (* F_16) ( struct V_1 * V_2 ) )
{
int V_23 ;
struct {
T_1 V_7 ;
T_3 V_8 ;
} * V_9 ;
if ( V_6 -> V_28 )
return F_15 ( V_6 , V_2 , F_16 ) ;
V_23 = F_17 ( V_6 , V_2 , false ,
F_16 , & V_30 ) ;
if ( F_10 ( V_23 != 0 ) ) {
F_11 ( L_3 ) ;
goto V_31;
}
if ( F_10 ( V_2 -> V_19 >= V_32 ) ) {
F_11 ( L_4 ) ;
F_25 ( & V_2 ) ;
return - V_33 ;
}
V_9 = F_9 ( V_6 , sizeof( * V_9 ) ) ;
if ( F_10 ( V_9 == NULL ) ) {
F_11 ( L_5 ) ;
F_25 ( & V_2 ) ;
return - V_33 ;
}
V_9 -> V_7 . V_19 = F_12 ( V_34 ) ;
V_9 -> V_7 . V_21 = F_12 ( sizeof( V_9 -> V_8 ) ) ;
V_9 -> V_8 . V_22 = F_12 ( V_2 -> V_19 ) ;
F_13 ( V_6 , sizeof( * V_9 ) ) ;
( void ) F_26 ( V_6 , false ) ;
F_22 ( V_2 , F_1 ) ;
return 0 ;
V_31:
if ( F_16 == NULL )
F_23 ( V_2 ) ;
else
F_16 ( V_2 ) ;
return V_23 ;
}
struct V_1 * F_27 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_28 ( sizeof( * V_2 ) , V_35 ) ;
int V_23 ;
if ( F_10 ( V_2 == NULL ) )
return NULL ;
V_23 = F_24 ( V_6 , V_2 , NULL ) ;
return ( V_23 == 0 ) ? V_2 : NULL ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_23 ;
struct {
T_1 V_7 ;
T_4 V_8 ;
} * V_9 ;
if ( F_30 ( V_2 -> V_19 != - 1 ) )
return 0 ;
V_23 = F_31 ( V_2 ) ;
if ( F_10 ( V_23 != 0 ) ) {
F_11 ( L_6 ) ;
goto V_36;
}
if ( F_10 ( V_2 -> V_19 >= V_37 ) ) {
V_23 = - V_38 ;
goto V_39;
}
V_9 = F_9 ( V_6 , sizeof( * V_9 ) ) ;
if ( F_10 ( V_9 == NULL ) ) {
F_11 ( L_7
L_8 ) ;
V_23 = - V_33 ;
goto V_39;
}
V_9 -> V_7 . V_19 = V_40 ;
V_9 -> V_7 . V_21 = sizeof( V_9 -> V_8 ) ;
V_9 -> V_8 . V_22 = V_2 -> V_19 ;
F_13 ( V_6 , sizeof( * V_9 ) ) ;
( void ) F_26 ( V_6 , false ) ;
return 0 ;
V_39:
F_32 ( V_2 ) ;
V_36:
return V_23 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct {
T_1 V_7 ;
T_5 V_8 ;
} * V_9 ;
struct V_43 * V_44 = V_42 -> V_44 ;
F_34 ( V_44 -> V_45 . V_46 != V_47 ) ;
V_9 = F_9 ( V_6 , sizeof( * V_9 ) ) ;
if ( F_10 ( V_9 == NULL ) ) {
F_11 ( L_7
L_9 ) ;
return - V_33 ;
}
V_9 -> V_7 . V_19 = V_48 ;
V_9 -> V_7 . V_21 = sizeof( V_9 -> V_8 ) ;
V_9 -> V_8 . V_22 = V_2 -> V_19 ;
V_9 -> V_8 . V_49 = V_44 -> V_45 . V_50 ;
V_9 -> V_8 . V_51 = V_2 -> V_52 ;
V_2 -> V_52 = false ;
F_13 ( V_6 , sizeof( * V_9 ) ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
bool V_53 ,
struct V_41 * V_42 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_43 * V_44 = V_42 -> V_44 ;
struct V_54 * V_55 ;
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
struct {
T_1 V_7 ;
T_6 V_8 ;
} * V_56 ;
struct {
T_1 V_7 ;
T_5 V_8 ;
} * V_57 ;
T_7 V_58 ;
T_8 * V_9 ;
F_34 ( V_44 -> V_45 . V_46 != V_47 ) ;
F_3 ( & V_6 -> V_15 ) ;
F_36 ( & V_4 -> V_16 ) ;
V_58 = sizeof( * V_57 ) + ( V_53 ? sizeof( * V_56 ) : 0 ) ;
V_9 = F_9 ( V_6 , V_58 ) ;
if ( F_10 ( V_9 == NULL ) ) {
F_11 ( L_7
L_10 ) ;
F_6 ( & V_6 -> V_15 ) ;
return - V_33 ;
}
V_57 = ( void * ) V_9 ;
if ( V_53 ) {
V_56 = ( void * ) V_9 ;
V_56 -> V_7 . V_19 = V_59 ;
V_56 -> V_7 . V_21 = sizeof( V_56 -> V_8 ) ;
V_56 -> V_8 . V_22 = V_2 -> V_19 ;
V_57 = ( void * ) ( & V_56 [ 1 ] ) ;
}
V_57 -> V_7 . V_19 = V_48 ;
V_57 -> V_7 . V_21 = sizeof( V_57 -> V_8 ) ;
V_57 -> V_8 . V_22 = V_2 -> V_19 ;
V_57 -> V_8 . V_49 = V_60 ;
F_13 ( V_6 , V_58 ) ;
F_6 ( & V_6 -> V_15 ) ;
( void ) F_37 ( NULL , V_6 ,
& V_55 , NULL ) ;
F_38 ( V_44 , V_55 ) ;
if ( F_30 ( V_55 != NULL ) )
F_39 ( & V_55 ) ;
return 0 ;
}
static int V_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct {
T_1 V_7 ;
T_9 V_8 ;
} * V_9 ;
if ( F_30 ( V_2 -> V_19 == - 1 ) )
return 0 ;
V_9 = F_9 ( V_6 , sizeof( * V_9 ) ) ;
if ( F_10 ( V_9 == NULL ) ) {
F_11 ( L_7
L_2 ) ;
return - V_33 ;
}
V_9 -> V_7 . V_19 = V_61 ;
V_9 -> V_7 . V_21 = sizeof( V_9 -> V_8 ) ;
V_9 -> V_8 . V_22 = V_2 -> V_19 ;
F_13 ( V_6 , sizeof( * V_9 ) ) ;
if ( V_6 -> V_62 == V_2 -> V_19 )
V_6 -> V_18 = false ;
F_32 ( V_2 ) ;
F_14 ( V_6 , false ) ;
return 0 ;
}
static struct V_1 *
F_40 ( struct V_63 * V_64 )
{
return & ( F_2 ( V_64 , struct V_3 , V_64 ) -> V_2 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_3 * V_65 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
F_42 ( V_65 , V_64 ) ;
F_43 ( F_44 ( V_6 ) ,
V_66 ) ;
}
static void F_45 ( struct V_63 * * V_67 )
{
struct V_63 * V_64 = * V_67 ;
struct V_3 * V_65 =
F_2 ( V_64 , struct V_3 , V_64 ) ;
struct V_1 * V_2 = & V_65 -> V_2 ;
* V_67 = NULL ;
F_25 ( & V_2 ) ;
}
int F_46 ( struct V_68 * V_69 , void * V_70 ,
struct V_71 * V_72 )
{
struct V_73 * V_74 = (struct V_73 * ) V_70 ;
struct V_75 * V_76 = F_47 ( V_72 ) -> V_76 ;
return F_48 ( V_76 , V_74 -> V_22 , V_77 ) ;
}
int F_49 ( struct V_68 * V_69 , void * V_70 ,
struct V_71 * V_72 )
{
struct V_5 * V_6 = F_50 ( V_69 ) ;
struct V_3 * V_65 ;
struct V_1 * V_2 ;
struct V_1 * V_78 ;
struct V_73 * V_74 = (struct V_73 * ) V_70 ;
struct V_75 * V_76 = F_47 ( V_72 ) -> V_76 ;
int V_23 ;
if ( F_10 ( V_66 == 0 ) )
V_66 = F_51 ( sizeof( * V_65 ) ) + 128 +
( ( V_6 -> V_28 ) ? F_52 () : 0 ) ;
V_23 = F_53 ( & V_6 -> V_79 , true ) ;
if ( F_10 ( V_23 != 0 ) )
return V_23 ;
V_23 = F_54 ( F_44 ( V_6 ) ,
V_66 ,
false , true ) ;
if ( F_10 ( V_23 != 0 ) ) {
if ( V_23 != - V_80 )
F_11 ( L_11
L_12 ) ;
goto V_81;
}
V_65 = F_55 ( sizeof( * V_65 ) , V_35 ) ;
if ( F_10 ( V_65 == NULL ) ) {
F_43 ( F_44 ( V_6 ) ,
V_66 ) ;
V_23 = - V_33 ;
goto V_81;
}
V_2 = & V_65 -> V_2 ;
V_65 -> V_64 . V_82 = false ;
V_65 -> V_64 . V_76 = NULL ;
V_23 = F_24 ( V_6 , V_2 , F_41 ) ;
if ( F_10 ( V_23 != 0 ) )
goto V_81;
V_78 = F_56 ( & V_65 -> V_2 ) ;
V_23 = F_57 ( V_76 , & V_65 -> V_64 , false , V_83 ,
& F_45 , NULL ) ;
if ( F_10 ( V_23 != 0 ) ) {
F_25 ( & V_78 ) ;
goto V_27;
}
V_74 -> V_22 = V_65 -> V_64 . V_84 . V_85 ;
V_27:
F_25 ( & V_2 ) ;
V_81:
F_58 ( & V_6 -> V_79 ) ;
return V_23 ;
}
static int F_59 ( struct V_86 * V_87 , bool V_88 )
{
struct V_5 * V_6 = V_87 -> V_65 -> V_6 ;
struct {
T_1 V_7 ;
T_10 V_8 ;
} * V_9 ;
V_9 = F_9 ( V_6 , sizeof( * V_9 ) ) ;
if ( F_10 ( V_9 == NULL ) ) {
F_11 ( L_13
L_10 ) ;
return - V_33 ;
}
V_9 -> V_7 . V_19 = V_89 ;
V_9 -> V_7 . V_21 = sizeof( V_9 -> V_8 ) ;
V_9 -> V_8 . V_22 = V_87 -> V_65 -> V_19 ;
V_9 -> V_8 . type = V_87 -> V_90 . V_91 ;
V_9 -> V_8 . V_92 = ( ( V_88 ) ? V_87 -> V_2 -> V_19 : V_60 ) ;
F_13 ( V_6 , sizeof( * V_9 ) ) ;
return 0 ;
}
static int F_60 ( struct V_86 * V_87 ,
bool V_88 )
{
struct V_5 * V_6 = V_87 -> V_65 -> V_6 ;
struct {
T_1 V_7 ;
T_11 V_8 ;
} * V_9 ;
V_9 = F_9 ( V_6 , sizeof( * V_9 ) ) ;
if ( F_10 ( V_9 == NULL ) ) {
F_11 ( L_14
L_10 ) ;
return - V_33 ;
}
V_9 -> V_7 . V_19 = V_93 ;
V_9 -> V_7 . V_21 = sizeof( V_9 -> V_8 ) ;
V_9 -> V_8 . V_22 = V_87 -> V_65 -> V_19 ;
V_9 -> V_8 . type = V_87 -> V_90 . V_94 ;
V_9 -> V_8 . V_95 . V_96 = ( ( V_88 ) ? V_87 -> V_2 -> V_19 : V_60 ) ;
V_9 -> V_8 . V_95 . V_97 = 0 ;
V_9 -> V_8 . V_95 . V_98 = 0 ;
F_13 ( V_6 , sizeof( * V_9 ) ) ;
return 0 ;
}
static int F_61 ( struct V_86 * V_87 ,
bool V_88 )
{
struct V_5 * V_6 = V_87 -> V_65 -> V_6 ;
struct {
T_1 V_7 ;
struct {
T_12 V_99 ;
T_13 V_100 ;
} V_8 ;
} * V_9 ;
V_9 = F_9 ( V_6 , sizeof( * V_9 ) ) ;
if ( F_10 ( V_9 == NULL ) ) {
F_11 ( L_15
L_10 ) ;
return - V_33 ;
}
V_9 -> V_7 . V_19 = V_101 ;
V_9 -> V_7 . V_21 = sizeof( V_9 -> V_8 ) ;
V_9 -> V_8 . V_99 . V_22 = V_87 -> V_65 -> V_19 ;
V_9 -> V_8 . V_100 . V_102 = V_87 -> V_90 . V_103 ;
V_9 -> V_8 . V_100 . V_104 = V_105 ;
V_9 -> V_8 . V_100 . V_106 = ( ( V_88 ) ? V_87 -> V_2 -> V_19 : V_60 ) ;
F_13 ( V_6 , sizeof( * V_9 ) ) ;
return 0 ;
}
static void F_62 ( struct V_107 * V_108 )
{
F_63 ( & V_108 -> V_109 ) ;
if ( ! F_64 ( & V_108 -> V_110 ) )
F_63 ( & V_108 -> V_110 ) ;
V_108 -> V_87 . V_65 = NULL ;
}
int F_65 ( struct V_111 * V_16 ,
const struct V_86 * V_87 )
{
struct V_107 * V_112 ;
switch ( V_87 -> V_113 ) {
case V_114 :
if ( F_10 ( ( unsigned ) V_87 -> V_90 . V_94 >= V_115 ) ) {
F_11 ( L_16 ,
( unsigned ) V_87 -> V_90 . V_94 ) ;
return - V_116 ;
}
V_112 = & V_16 -> V_117 [ V_87 -> V_90 . V_94 ] ;
break;
case V_118 :
if ( F_10 ( ( unsigned ) V_87 -> V_90 . V_103 >=
V_119 ) ) {
F_11 ( L_17 ,
( unsigned ) V_87 -> V_90 . V_103 ) ;
return - V_116 ;
}
V_112 = & V_16 -> V_120 [ V_87 -> V_90 . V_103 ] ;
break;
case V_121 :
if ( F_10 ( ( unsigned ) V_87 -> V_90 . V_91 >=
V_122 ) ) {
F_11 ( L_18 ,
( unsigned ) V_87 -> V_90 . V_91 ) ;
return - V_116 ;
}
V_112 = & V_16 -> V_123 [ V_87 -> V_90 . V_91 ] ;
break;
default:
F_66 () ;
}
if ( V_112 -> V_87 . V_65 != NULL )
F_62 ( V_112 ) ;
V_112 -> V_87 = * V_87 ;
V_112 -> V_87 . V_124 = false ;
F_67 ( & V_112 -> V_109 , & V_16 -> V_29 ) ;
F_21 ( & V_112 -> V_110 ) ;
return 0 ;
}
static void F_68 ( struct V_111 * V_16 ,
const struct V_86 * V_87 )
{
struct V_107 * V_112 ;
switch ( V_87 -> V_113 ) {
case V_114 :
V_112 = & V_16 -> V_117 [ V_87 -> V_90 . V_94 ] ;
break;
case V_118 :
V_112 = & V_16 -> V_120 [ V_87 -> V_90 . V_103 ] ;
break;
case V_121 :
V_112 = & V_16 -> V_123 [ V_87 -> V_90 . V_91 ] ;
break;
default:
F_66 () ;
}
if ( V_112 -> V_87 . V_65 != NULL )
F_62 ( V_112 ) ;
if ( V_87 -> V_2 != NULL ) {
V_112 -> V_87 = * V_87 ;
F_67 ( & V_112 -> V_109 , & V_16 -> V_29 ) ;
F_67 ( & V_112 -> V_110 , & V_87 -> V_2 -> V_125 ) ;
}
}
static void F_69 ( struct V_107 * V_108 )
{
if ( ! V_108 -> V_87 . V_124 ) {
( void ) V_126 [ V_108 -> V_87 . V_113 ] ( & V_108 -> V_87 , false ) ;
V_108 -> V_87 . V_124 = true ;
}
F_62 ( V_108 ) ;
}
static void F_5 ( struct V_111 * V_16 )
{
struct V_107 * V_127 , * V_128 ;
F_70 (entry, next, &cbs->list, ctx_list)
F_69 ( V_127 ) ;
}
static void F_36 ( struct V_111 * V_16 )
{
struct V_107 * V_127 ;
F_71 (entry, &cbs->list, ctx_list) {
if ( ! V_127 -> V_87 . V_124 ) {
( void ) V_126 [ V_127 -> V_87 . V_113 ] ( & V_127 -> V_87 , false ) ;
V_127 -> V_87 . V_124 = true ;
}
}
}
void F_72 ( struct V_129 * V_130 )
{
struct V_107 * V_127 , * V_128 ;
F_70 (entry, next, head, res_list)
F_69 ( V_127 ) ;
}
void F_73 ( struct V_129 * V_130 )
{
struct V_107 * V_127 ;
F_71 (entry, head, res_list) {
if ( ! V_127 -> V_87 . V_124 ) {
( void ) V_126 [ V_127 -> V_87 . V_113 ] ( & V_127 -> V_87 , false ) ;
V_127 -> V_87 . V_124 = true ;
}
}
}
void F_74 ( struct V_1 * V_65 ,
struct V_111 * V_131 )
{
struct V_3 * V_4 =
F_2 ( V_65 , struct V_3 , V_2 ) ;
struct V_107 * V_127 , * V_128 ;
F_70 (entry, next, &from->list, ctx_list)
F_68 ( & V_4 -> V_16 , & V_127 -> V_87 ) ;
}
int F_75 ( struct V_1 * V_65 )
{
struct V_107 * V_127 ;
struct V_3 * V_4 =
F_2 ( V_65 , struct V_3 , V_2 ) ;
struct V_111 * V_16 = & V_4 -> V_16 ;
int V_23 ;
F_71 (entry, &cbs->list, ctx_list) {
if ( F_30 ( ! V_127 -> V_87 . V_124 ) )
continue;
if ( F_76 ( V_127 -> V_87 . V_2 == NULL || V_127 -> V_87 . V_2 -> V_19 ==
V_60 ) )
continue;
V_23 = V_126 [ V_127 -> V_87 . V_113 ] ( & V_127 -> V_87 , true ) ;
if ( F_10 ( V_23 != 0 ) )
return V_23 ;
V_127 -> V_87 . V_124 = false ;
}
return 0 ;
}
struct V_129 * F_77 ( struct V_1 * V_65 )
{
return & ( F_2 ( V_65 , struct V_3 , V_2 ) -> V_16 . V_29 ) ;
}
struct V_132 * F_78 ( struct V_1 * V_65 )
{
return F_2 ( V_65 , struct V_3 , V_2 ) -> V_14 ;
}
