static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct {
T_1 V_5 ;
T_2 V_6 ;
} * V_7 ;
if ( V_2 -> V_8 -> V_9 == V_10 ) {
F_2 ( & V_4 -> V_11 ) ;
F_2 ( & V_4 -> V_12 ) ;
( void ) F_3
( & F_4 ( V_2 , struct V_13 , V_2 ) -> V_14 ) ;
( void ) V_10 ( V_2 ) ;
if ( V_4 -> V_15 != NULL &&
! V_4 -> V_16 )
F_5 ( V_4 , NULL ) ;
F_6 ( & V_4 -> V_12 ) ;
F_6 ( & V_4 -> V_11 ) ;
return;
}
F_7 ( V_4 ) ;
V_7 = F_8 ( V_4 , sizeof( * V_7 ) ) ;
if ( F_9 ( V_7 == NULL ) ) {
F_10 ( L_1
L_2 ) ;
return;
}
V_7 -> V_5 . V_17 = F_11 ( V_18 ) ;
V_7 -> V_5 . V_19 = F_11 ( sizeof( V_7 -> V_6 ) ) ;
V_7 -> V_6 . V_20 = F_11 ( V_2 -> V_17 ) ;
F_12 ( V_4 , sizeof( * V_7 ) ) ;
F_13 ( V_4 , false ) ;
}
static int F_14 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
void (* F_15) ( struct V_1 * V_2 ) )
{
int V_21 ;
struct V_13 * V_22 =
F_4 ( V_2 , struct V_13 , V_2 ) ;
V_21 = F_16 ( V_4 , V_2 , true ,
F_15 , & V_23 ) ;
V_2 -> V_24 = V_25 ;
if ( F_9 ( V_21 != 0 ) ) {
if ( F_15 )
F_15 ( V_2 ) ;
else
F_17 ( V_2 ) ;
return V_21 ;
}
memset ( & V_22 -> V_14 , 0 , sizeof( V_22 -> V_14 ) ) ;
F_18 ( & V_22 -> V_14 . V_26 ) ;
F_19 ( V_2 , F_1 ) ;
return 0 ;
}
static int F_20 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
void (* F_15) ( struct V_1 * V_2 ) )
{
int V_21 ;
struct {
T_1 V_5 ;
T_3 V_6 ;
} * V_7 ;
if ( V_4 -> V_27 )
return F_14 ( V_4 , V_2 , F_15 ) ;
V_21 = F_16 ( V_4 , V_2 , false ,
F_15 , & V_28 ) ;
if ( F_9 ( V_21 != 0 ) ) {
F_10 ( L_3 ) ;
goto V_29;
}
if ( F_9 ( V_2 -> V_17 >= V_30 ) ) {
F_10 ( L_4 ) ;
F_21 ( & V_2 ) ;
return - V_31 ;
}
V_7 = F_8 ( V_4 , sizeof( * V_7 ) ) ;
if ( F_9 ( V_7 == NULL ) ) {
F_10 ( L_5 ) ;
F_21 ( & V_2 ) ;
return - V_31 ;
}
V_7 -> V_5 . V_17 = F_11 ( V_32 ) ;
V_7 -> V_5 . V_19 = F_11 ( sizeof( V_7 -> V_6 ) ) ;
V_7 -> V_6 . V_20 = F_11 ( V_2 -> V_17 ) ;
F_12 ( V_4 , sizeof( * V_7 ) ) ;
( void ) F_22 ( V_4 , false ) ;
F_19 ( V_2 , F_1 ) ;
return 0 ;
V_29:
if ( F_15 == NULL )
F_17 ( V_2 ) ;
else
F_15 ( V_2 ) ;
return V_21 ;
}
struct V_1 * F_23 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_24 ( sizeof( * V_2 ) , V_33 ) ;
int V_21 ;
if ( F_9 ( V_2 == NULL ) )
return NULL ;
V_21 = F_20 ( V_4 , V_2 , NULL ) ;
return ( V_21 == 0 ) ? V_2 : NULL ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_21 ;
struct {
T_1 V_5 ;
T_4 V_6 ;
} * V_7 ;
if ( F_26 ( V_2 -> V_17 != - 1 ) )
return 0 ;
V_21 = F_27 ( V_2 ) ;
if ( F_9 ( V_21 != 0 ) ) {
F_10 ( L_6 ) ;
goto V_34;
}
if ( F_9 ( V_2 -> V_17 >= V_35 ) ) {
V_21 = - V_36 ;
goto V_37;
}
V_7 = F_8 ( V_4 , sizeof( * V_7 ) ) ;
if ( F_9 ( V_7 == NULL ) ) {
F_10 ( L_7
L_8 ) ;
V_21 = - V_31 ;
goto V_37;
}
V_7 -> V_5 . V_17 = V_38 ;
V_7 -> V_5 . V_19 = sizeof( V_7 -> V_6 ) ;
V_7 -> V_6 . V_20 = V_2 -> V_17 ;
F_12 ( V_4 , sizeof( * V_7 ) ) ;
( void ) F_22 ( V_4 , false ) ;
return 0 ;
V_37:
F_28 ( V_2 ) ;
V_34:
return V_21 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_39 * V_40 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct {
T_1 V_5 ;
T_5 V_6 ;
} * V_7 ;
struct V_41 * V_42 = V_40 -> V_42 ;
F_30 ( V_42 -> V_43 . V_44 != V_45 ) ;
V_7 = F_8 ( V_4 , sizeof( * V_7 ) ) ;
if ( F_9 ( V_7 == NULL ) ) {
F_10 ( L_7
L_9 ) ;
return - V_31 ;
}
V_7 -> V_5 . V_17 = V_46 ;
V_7 -> V_5 . V_19 = sizeof( V_7 -> V_6 ) ;
V_7 -> V_6 . V_20 = V_2 -> V_17 ;
V_7 -> V_6 . V_47 = V_42 -> V_43 . V_48 ;
V_7 -> V_6 . V_49 = V_2 -> V_50 ;
V_2 -> V_50 = false ;
F_12 ( V_4 , sizeof( * V_7 ) ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
bool V_51 ,
struct V_39 * V_40 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_41 * V_42 = V_40 -> V_42 ;
struct V_52 * V_53 ;
struct V_13 * V_22 =
F_4 ( V_2 , struct V_13 , V_2 ) ;
struct {
T_1 V_5 ;
T_6 V_6 ;
} * V_54 ;
struct {
T_1 V_5 ;
T_5 V_6 ;
} * V_55 ;
T_7 V_56 ;
T_8 * V_7 ;
F_30 ( V_42 -> V_43 . V_44 != V_45 ) ;
F_2 ( & V_4 -> V_12 ) ;
F_32 ( & V_22 -> V_14 ) ;
V_56 = sizeof( * V_55 ) + ( V_51 ? sizeof( * V_54 ) : 0 ) ;
V_7 = F_8 ( V_4 , V_56 ) ;
if ( F_9 ( V_7 == NULL ) ) {
F_10 ( L_7
L_10 ) ;
F_6 ( & V_4 -> V_12 ) ;
return - V_31 ;
}
V_55 = ( void * ) V_7 ;
if ( V_51 ) {
V_54 = ( void * ) V_7 ;
V_54 -> V_5 . V_17 = V_57 ;
V_54 -> V_5 . V_19 = sizeof( V_54 -> V_6 ) ;
V_54 -> V_6 . V_20 = V_2 -> V_17 ;
V_55 = ( void * ) ( & V_54 [ 1 ] ) ;
}
V_55 -> V_5 . V_17 = V_46 ;
V_55 -> V_5 . V_19 = sizeof( V_55 -> V_6 ) ;
V_55 -> V_6 . V_20 = V_2 -> V_17 ;
V_55 -> V_6 . V_47 = V_58 ;
F_12 ( V_4 , V_56 ) ;
F_6 ( & V_4 -> V_12 ) ;
( void ) F_33 ( NULL , V_4 ,
& V_53 , NULL ) ;
F_34 ( V_42 , V_53 ) ;
if ( F_26 ( V_53 != NULL ) )
F_35 ( & V_53 ) ;
return 0 ;
}
static int V_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct {
T_1 V_5 ;
T_9 V_6 ;
} * V_7 ;
if ( F_26 ( V_2 -> V_17 == - 1 ) )
return 0 ;
V_7 = F_8 ( V_4 , sizeof( * V_7 ) ) ;
if ( F_9 ( V_7 == NULL ) ) {
F_10 ( L_7
L_2 ) ;
return - V_31 ;
}
V_7 -> V_5 . V_17 = V_59 ;
V_7 -> V_5 . V_19 = sizeof( V_7 -> V_6 ) ;
V_7 -> V_6 . V_20 = V_2 -> V_17 ;
F_12 ( V_4 , sizeof( * V_7 ) ) ;
if ( V_4 -> V_60 == V_2 -> V_17 )
V_4 -> V_16 = false ;
F_28 ( V_2 ) ;
F_13 ( V_4 , false ) ;
return 0 ;
}
static struct V_1 *
F_36 ( struct V_61 * V_62 )
{
return & ( F_4 ( V_62 , struct V_13 , V_62 ) -> V_2 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_13 * V_63 =
F_4 ( V_2 , struct V_13 , V_2 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_38 ( V_63 , V_62 ) ;
F_39 ( F_40 ( V_4 ) ,
V_64 ) ;
}
static void F_41 ( struct V_61 * * V_65 )
{
struct V_61 * V_62 = * V_65 ;
struct V_13 * V_63 =
F_4 ( V_62 , struct V_13 , V_62 ) ;
struct V_1 * V_2 = & V_63 -> V_2 ;
* V_65 = NULL ;
F_21 ( & V_2 ) ;
}
int F_42 ( struct V_66 * V_67 , void * V_68 ,
struct V_69 * V_70 )
{
struct V_71 * V_72 = (struct V_71 * ) V_68 ;
struct V_73 * V_74 = F_43 ( V_70 ) -> V_74 ;
return F_44 ( V_74 , V_72 -> V_20 , V_75 ) ;
}
int F_45 ( struct V_66 * V_67 , void * V_68 ,
struct V_69 * V_70 )
{
struct V_3 * V_4 = F_46 ( V_67 ) ;
struct V_13 * V_63 ;
struct V_1 * V_2 ;
struct V_1 * V_76 ;
struct V_71 * V_72 = (struct V_71 * ) V_68 ;
struct V_73 * V_74 = F_43 ( V_70 ) -> V_74 ;
struct V_77 * V_78 = V_77 ( V_70 -> V_79 ) ;
int V_21 ;
if ( F_9 ( V_64 == 0 ) )
V_64 = F_47 ( sizeof( * V_63 ) ) + 128 ;
V_21 = F_48 ( & V_78 -> V_80 , true ) ;
if ( F_9 ( V_21 != 0 ) )
return V_21 ;
V_21 = F_49 ( F_40 ( V_4 ) ,
V_64 ,
false , true ) ;
if ( F_9 ( V_21 != 0 ) ) {
if ( V_21 != - V_81 )
F_10 ( L_11
L_12 ) ;
goto V_82;
}
V_63 = F_50 ( sizeof( * V_63 ) , V_33 ) ;
if ( F_9 ( V_63 == NULL ) ) {
F_39 ( F_40 ( V_4 ) ,
V_64 ) ;
V_21 = - V_31 ;
goto V_82;
}
V_2 = & V_63 -> V_2 ;
V_63 -> V_62 . V_83 = false ;
V_63 -> V_62 . V_74 = NULL ;
V_21 = F_20 ( V_4 , V_2 , F_37 ) ;
if ( F_9 ( V_21 != 0 ) )
goto V_82;
V_76 = F_51 ( & V_63 -> V_2 ) ;
V_21 = F_52 ( V_74 , & V_63 -> V_62 , false , V_84 ,
& F_41 , NULL ) ;
if ( F_9 ( V_21 != 0 ) ) {
F_21 ( & V_76 ) ;
goto V_85;
}
V_72 -> V_20 = V_63 -> V_62 . V_86 . V_87 ;
V_85:
F_21 ( & V_2 ) ;
V_82:
F_53 ( & V_78 -> V_80 ) ;
return V_21 ;
}
static int F_54 ( struct V_88 * V_89 , bool V_90 )
{
struct V_3 * V_4 = V_89 -> V_63 -> V_4 ;
struct {
T_1 V_5 ;
T_10 V_6 ;
} * V_7 ;
V_7 = F_8 ( V_4 , sizeof( * V_7 ) ) ;
if ( F_9 ( V_7 == NULL ) ) {
F_10 ( L_13
L_10 ) ;
return - V_31 ;
}
V_7 -> V_5 . V_17 = V_91 ;
V_7 -> V_5 . V_19 = sizeof( V_7 -> V_6 ) ;
V_7 -> V_6 . V_20 = V_89 -> V_63 -> V_17 ;
V_7 -> V_6 . type = V_89 -> V_92 . V_93 ;
V_7 -> V_6 . V_94 = ( ( V_90 ) ? V_89 -> V_2 -> V_17 : V_58 ) ;
F_12 ( V_4 , sizeof( * V_7 ) ) ;
return 0 ;
}
static int F_55 ( struct V_88 * V_89 ,
bool V_90 )
{
struct V_3 * V_4 = V_89 -> V_63 -> V_4 ;
struct {
T_1 V_5 ;
T_11 V_6 ;
} * V_7 ;
V_7 = F_8 ( V_4 , sizeof( * V_7 ) ) ;
if ( F_9 ( V_7 == NULL ) ) {
F_10 ( L_14
L_10 ) ;
return - V_31 ;
}
V_7 -> V_5 . V_17 = V_95 ;
V_7 -> V_5 . V_19 = sizeof( V_7 -> V_6 ) ;
V_7 -> V_6 . V_20 = V_89 -> V_63 -> V_17 ;
V_7 -> V_6 . type = V_89 -> V_92 . V_96 ;
V_7 -> V_6 . V_97 . V_98 = ( ( V_90 ) ? V_89 -> V_2 -> V_17 : V_58 ) ;
V_7 -> V_6 . V_97 . V_99 = 0 ;
V_7 -> V_6 . V_97 . V_100 = 0 ;
F_12 ( V_4 , sizeof( * V_7 ) ) ;
return 0 ;
}
static int F_56 ( struct V_88 * V_89 ,
bool V_90 )
{
struct V_3 * V_4 = V_89 -> V_63 -> V_4 ;
struct {
T_1 V_5 ;
struct {
T_12 V_101 ;
T_13 V_102 ;
} V_6 ;
} * V_7 ;
V_7 = F_8 ( V_4 , sizeof( * V_7 ) ) ;
if ( F_9 ( V_7 == NULL ) ) {
F_10 ( L_15
L_10 ) ;
return - V_31 ;
}
V_7 -> V_5 . V_17 = V_103 ;
V_7 -> V_5 . V_19 = sizeof( V_7 -> V_6 ) ;
V_7 -> V_6 . V_101 . V_20 = V_89 -> V_63 -> V_17 ;
V_7 -> V_6 . V_102 . V_104 = V_89 -> V_92 . V_105 ;
V_7 -> V_6 . V_102 . V_106 = V_107 ;
V_7 -> V_6 . V_102 . V_108 = ( ( V_90 ) ? V_89 -> V_2 -> V_17 : V_58 ) ;
F_12 ( V_4 , sizeof( * V_7 ) ) ;
return 0 ;
}
static void F_57 ( struct V_109 * V_110 )
{
F_58 ( & V_110 -> V_111 ) ;
if ( ! F_59 ( & V_110 -> V_112 ) )
F_58 ( & V_110 -> V_112 ) ;
V_110 -> V_89 . V_63 = NULL ;
}
int F_60 ( struct V_113 * V_14 ,
const struct V_88 * V_89 )
{
struct V_109 * V_114 ;
switch ( V_89 -> V_115 ) {
case V_116 :
if ( F_9 ( ( unsigned ) V_89 -> V_92 . V_96 >= V_117 ) ) {
F_10 ( L_16 ,
( unsigned ) V_89 -> V_92 . V_96 ) ;
return - V_118 ;
}
V_114 = & V_14 -> V_119 [ V_89 -> V_92 . V_96 ] ;
break;
case V_120 :
if ( F_9 ( ( unsigned ) V_89 -> V_92 . V_105 >=
V_121 ) ) {
F_10 ( L_17 ,
( unsigned ) V_89 -> V_92 . V_105 ) ;
return - V_118 ;
}
V_114 = & V_14 -> V_122 [ V_89 -> V_92 . V_105 ] ;
break;
case V_123 :
if ( F_9 ( ( unsigned ) V_89 -> V_92 . V_93 >=
V_124 ) ) {
F_10 ( L_18 ,
( unsigned ) V_89 -> V_92 . V_93 ) ;
return - V_118 ;
}
V_114 = & V_14 -> V_125 [ V_89 -> V_92 . V_93 ] ;
break;
default:
F_61 () ;
}
if ( V_114 -> V_89 . V_63 != NULL )
F_57 ( V_114 ) ;
V_114 -> V_89 = * V_89 ;
V_114 -> V_89 . V_126 = false ;
F_62 ( & V_114 -> V_111 , & V_14 -> V_26 ) ;
F_18 ( & V_114 -> V_112 ) ;
return 0 ;
}
static void F_63 ( struct V_113 * V_14 ,
const struct V_88 * V_89 )
{
struct V_109 * V_114 ;
switch ( V_89 -> V_115 ) {
case V_116 :
V_114 = & V_14 -> V_119 [ V_89 -> V_92 . V_96 ] ;
break;
case V_120 :
V_114 = & V_14 -> V_122 [ V_89 -> V_92 . V_105 ] ;
break;
case V_123 :
V_114 = & V_14 -> V_125 [ V_89 -> V_92 . V_93 ] ;
break;
default:
F_61 () ;
}
if ( V_114 -> V_89 . V_63 != NULL )
F_57 ( V_114 ) ;
if ( V_89 -> V_2 != NULL ) {
V_114 -> V_89 = * V_89 ;
F_62 ( & V_114 -> V_111 , & V_14 -> V_26 ) ;
F_62 ( & V_114 -> V_112 , & V_89 -> V_2 -> V_127 ) ;
}
}
static void F_64 ( struct V_109 * V_110 )
{
if ( ! V_110 -> V_89 . V_126 ) {
( void ) V_128 [ V_110 -> V_89 . V_115 ] ( & V_110 -> V_89 , false ) ;
V_110 -> V_89 . V_126 = true ;
}
F_57 ( V_110 ) ;
}
static void F_3 ( struct V_113 * V_14 )
{
struct V_109 * V_129 , * V_130 ;
F_65 (entry, next, &cbs->list, ctx_list)
F_64 ( V_129 ) ;
}
static void F_32 ( struct V_113 * V_14 )
{
struct V_109 * V_129 ;
F_66 (entry, &cbs->list, ctx_list) {
if ( ! V_129 -> V_89 . V_126 ) {
( void ) V_128 [ V_129 -> V_89 . V_115 ] ( & V_129 -> V_89 , false ) ;
V_129 -> V_89 . V_126 = true ;
}
}
}
void F_67 ( struct V_131 * V_132 )
{
struct V_109 * V_129 , * V_130 ;
F_65 (entry, next, head, res_list)
F_64 ( V_129 ) ;
}
void F_68 ( struct V_131 * V_132 )
{
struct V_109 * V_129 ;
F_66 (entry, head, res_list) {
if ( ! V_129 -> V_89 . V_126 ) {
( void ) V_128 [ V_129 -> V_89 . V_115 ] ( & V_129 -> V_89 , false ) ;
V_129 -> V_89 . V_126 = true ;
}
}
}
void F_69 ( struct V_1 * V_63 ,
struct V_113 * V_133 )
{
struct V_13 * V_22 =
F_4 ( V_63 , struct V_13 , V_2 ) ;
struct V_109 * V_129 , * V_130 ;
F_65 (entry, next, &from->list, ctx_list)
F_63 ( & V_22 -> V_14 , & V_129 -> V_89 ) ;
}
int F_70 ( struct V_1 * V_63 )
{
struct V_109 * V_129 ;
struct V_13 * V_22 =
F_4 ( V_63 , struct V_13 , V_2 ) ;
struct V_113 * V_14 = & V_22 -> V_14 ;
int V_21 ;
F_66 (entry, &cbs->list, ctx_list) {
if ( F_26 ( ! V_129 -> V_89 . V_126 ) )
continue;
if ( F_71 ( V_129 -> V_89 . V_2 == NULL || V_129 -> V_89 . V_2 -> V_17 ==
V_58 ) )
continue;
V_21 = V_128 [ V_129 -> V_89 . V_115 ] ( & V_129 -> V_89 , true ) ;
if ( F_9 ( V_21 != 0 ) )
return V_21 ;
V_129 -> V_89 . V_126 = false ;
}
return 0 ;
}
struct V_131 * F_72 ( struct V_1 * V_63 )
{
return & ( F_4 ( V_63 , struct V_13 , V_2 ) -> V_14 . V_26 ) ;
}
