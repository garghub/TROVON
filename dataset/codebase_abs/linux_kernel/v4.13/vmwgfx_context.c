static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; ++ V_5 ) {
F_2 ( & V_2 -> V_7 ) ;
V_4 = V_2 -> V_8 [ V_5 ] ;
V_2 -> V_8 [ V_5 ] = NULL ;
F_3 ( & V_2 -> V_7 ) ;
if ( V_4 )
F_4 ( & V_4 ) ;
}
}
static void F_5 ( struct V_3 * V_4 )
{
struct V_1 * V_2 =
F_6 ( V_4 , struct V_1 , V_4 ) ;
struct V_9 * V_10 = V_4 -> V_10 ;
struct {
T_1 V_11 ;
T_2 V_12 ;
} * V_13 ;
if ( V_4 -> V_14 -> V_15 == V_16 ||
V_4 -> V_14 -> V_15 == V_17 ) {
F_7 ( & V_10 -> V_18 ) ;
F_8 ( V_2 -> V_19 ) ;
F_7 ( & V_10 -> V_20 ) ;
F_9 ( V_2 -> V_21 ) ;
( void ) V_4 -> V_14 -> V_15 ( V_4 ) ;
F_10 ( & V_10 -> V_20 ) ;
if ( V_10 -> V_22 != NULL &&
! V_10 -> V_23 )
F_11 ( V_10 , NULL ) ;
F_10 ( & V_10 -> V_18 ) ;
F_1 ( V_2 ) ;
return;
}
F_12 ( V_10 ) ;
V_13 = F_13 ( V_10 , sizeof( * V_13 ) ) ;
if ( F_14 ( V_13 == NULL ) ) {
F_15 ( L_1
L_2 ) ;
return;
}
V_13 -> V_11 . V_24 = V_25 ;
V_13 -> V_11 . V_26 = sizeof( V_13 -> V_12 ) ;
V_13 -> V_12 . V_27 = V_4 -> V_24 ;
F_16 ( V_10 , sizeof( * V_13 ) ) ;
F_17 ( V_10 ) ;
}
static int F_18 ( struct V_9 * V_10 ,
bool V_28 ,
struct V_3 * V_4 ,
void (* F_19)( struct V_3 * V_4 ) )
{
int V_29 , V_5 ;
struct V_1 * V_2 =
F_6 ( V_4 , struct V_1 , V_4 ) ;
V_4 -> V_30 = ( V_28 ? sizeof( V_31 ) :
V_32 ) ;
V_29 = F_20 ( V_10 , V_4 , true ,
F_19 ,
V_28 ? & V_33 :
& V_34 ) ;
if ( F_14 ( V_29 != 0 ) )
goto V_35;
if ( V_10 -> V_36 ) {
V_2 -> V_19 = F_21 ( V_10 ) ;
if ( F_22 ( V_2 -> V_19 ) ) {
V_29 = F_23 ( V_2 -> V_19 ) ;
V_2 -> V_19 = NULL ;
goto V_35;
}
}
V_2 -> V_21 = F_24 ( V_10 ) ;
if ( F_22 ( V_2 -> V_21 ) ) {
V_29 = F_23 ( V_2 -> V_21 ) ;
goto V_35;
}
F_25 ( & V_2 -> V_7 ) ;
if ( V_28 ) {
for ( V_5 = 0 ; V_5 < V_6 ; ++ V_5 ) {
V_2 -> V_8 [ V_5 ] = F_26 ( V_10 ,
& V_2 -> V_4 , V_5 ) ;
if ( F_14 ( F_22 ( V_2 -> V_8 [ V_5 ] ) ) ) {
V_29 = F_23 ( V_2 -> V_8 [ V_5 ] ) ;
goto V_37;
}
}
}
F_27 ( V_4 , F_5 ) ;
return 0 ;
V_37:
F_1 ( V_2 ) ;
V_35:
if ( F_19 )
F_19 ( V_4 ) ;
else
F_28 ( V_4 ) ;
return V_29 ;
}
static int F_29 ( struct V_9 * V_10 ,
struct V_3 * V_4 ,
void (* F_19)( struct V_3 * V_4 ) ,
bool V_28 )
{
int V_29 ;
struct {
T_1 V_11 ;
T_3 V_12 ;
} * V_13 ;
if ( V_10 -> V_36 )
return F_18 ( V_10 , V_28 , V_4 , F_19 ) ;
V_29 = F_20 ( V_10 , V_4 , false ,
F_19 , & V_38 ) ;
if ( F_14 ( V_29 != 0 ) ) {
F_15 ( L_3 ) ;
goto V_39;
}
if ( F_14 ( V_4 -> V_24 >= V_40 ) ) {
F_15 ( L_4 ) ;
F_4 ( & V_4 ) ;
return - V_41 ;
}
V_13 = F_13 ( V_10 , sizeof( * V_13 ) ) ;
if ( F_14 ( V_13 == NULL ) ) {
F_15 ( L_5 ) ;
F_4 ( & V_4 ) ;
return - V_41 ;
}
V_13 -> V_11 . V_24 = V_42 ;
V_13 -> V_11 . V_26 = sizeof( V_13 -> V_12 ) ;
V_13 -> V_12 . V_27 = V_4 -> V_24 ;
F_16 ( V_10 , sizeof( * V_13 ) ) ;
F_30 ( V_10 ) ;
F_27 ( V_4 , F_5 ) ;
return 0 ;
V_39:
if ( F_19 == NULL )
F_28 ( V_4 ) ;
else
F_19 ( V_4 ) ;
return V_29 ;
}
static int F_31 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_10 ;
int V_29 ;
struct {
T_1 V_11 ;
T_4 V_12 ;
} * V_13 ;
if ( F_32 ( V_4 -> V_24 != - 1 ) )
return 0 ;
V_29 = F_33 ( V_4 ) ;
if ( F_14 ( V_29 != 0 ) ) {
F_15 ( L_6 ) ;
goto V_43;
}
if ( F_14 ( V_4 -> V_24 >= V_44 ) ) {
V_29 = - V_45 ;
goto V_46;
}
V_13 = F_13 ( V_10 , sizeof( * V_13 ) ) ;
if ( F_14 ( V_13 == NULL ) ) {
F_15 ( L_7
L_8 ) ;
V_29 = - V_41 ;
goto V_46;
}
V_13 -> V_11 . V_24 = V_47 ;
V_13 -> V_11 . V_26 = sizeof( V_13 -> V_12 ) ;
V_13 -> V_12 . V_27 = V_4 -> V_24 ;
F_16 ( V_10 , sizeof( * V_13 ) ) ;
F_30 ( V_10 ) ;
return 0 ;
V_46:
F_34 ( V_4 ) ;
V_43:
return V_29 ;
}
static int F_35 ( struct V_3 * V_4 ,
struct V_48 * V_49 )
{
struct V_9 * V_10 = V_4 -> V_10 ;
struct {
T_1 V_11 ;
T_5 V_12 ;
} * V_13 ;
struct V_50 * V_51 = V_49 -> V_51 ;
F_36 ( V_51 -> V_52 . V_53 != V_54 ) ;
V_13 = F_13 ( V_10 , sizeof( * V_13 ) ) ;
if ( F_14 ( V_13 == NULL ) ) {
F_15 ( L_7
L_9 ) ;
return - V_41 ;
}
V_13 -> V_11 . V_24 = V_55 ;
V_13 -> V_11 . V_26 = sizeof( V_13 -> V_12 ) ;
V_13 -> V_12 . V_27 = V_4 -> V_24 ;
V_13 -> V_12 . V_56 = V_51 -> V_52 . V_57 ;
V_13 -> V_12 . V_58 = V_4 -> V_59 ;
V_4 -> V_59 = false ;
F_16 ( V_10 , sizeof( * V_13 ) ) ;
return 0 ;
}
static int F_37 ( struct V_3 * V_4 ,
bool V_60 ,
struct V_48 * V_49 )
{
struct V_9 * V_10 = V_4 -> V_10 ;
struct V_50 * V_51 = V_49 -> V_51 ;
struct V_61 * V_62 ;
struct V_1 * V_2 =
F_6 ( V_4 , struct V_1 , V_4 ) ;
struct {
T_1 V_11 ;
T_6 V_12 ;
} * V_63 ;
struct {
T_1 V_11 ;
T_5 V_12 ;
} * V_64 ;
T_7 V_65 ;
T_8 * V_13 ;
F_36 ( V_51 -> V_52 . V_53 != V_54 ) ;
F_7 ( & V_10 -> V_20 ) ;
F_38 ( V_2 -> V_21 ) ;
V_65 = sizeof( * V_64 ) + ( V_60 ? sizeof( * V_63 ) : 0 ) ;
V_13 = F_13 ( V_10 , V_65 ) ;
if ( F_14 ( V_13 == NULL ) ) {
F_15 ( L_7
L_10 ) ;
F_10 ( & V_10 -> V_20 ) ;
return - V_41 ;
}
V_64 = ( void * ) V_13 ;
if ( V_60 ) {
V_63 = ( void * ) V_13 ;
V_63 -> V_11 . V_24 = V_66 ;
V_63 -> V_11 . V_26 = sizeof( V_63 -> V_12 ) ;
V_63 -> V_12 . V_27 = V_4 -> V_24 ;
V_64 = ( void * ) ( & V_63 [ 1 ] ) ;
}
V_64 -> V_11 . V_24 = V_55 ;
V_64 -> V_11 . V_26 = sizeof( V_64 -> V_12 ) ;
V_64 -> V_12 . V_27 = V_4 -> V_24 ;
V_64 -> V_12 . V_56 = V_67 ;
F_16 ( V_10 , V_65 ) ;
F_10 ( & V_10 -> V_20 ) ;
( void ) F_39 ( NULL , V_10 ,
& V_62 , NULL ) ;
F_40 ( V_51 , V_62 ) ;
if ( F_32 ( V_62 != NULL ) )
F_41 ( & V_62 ) ;
return 0 ;
}
static int V_16 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_10 ;
struct {
T_1 V_11 ;
T_9 V_12 ;
} * V_13 ;
if ( F_32 ( V_4 -> V_24 == - 1 ) )
return 0 ;
V_13 = F_13 ( V_10 , sizeof( * V_13 ) ) ;
if ( F_14 ( V_13 == NULL ) ) {
F_15 ( L_7
L_2 ) ;
return - V_41 ;
}
V_13 -> V_11 . V_24 = V_68 ;
V_13 -> V_11 . V_26 = sizeof( V_13 -> V_12 ) ;
V_13 -> V_12 . V_27 = V_4 -> V_24 ;
F_16 ( V_10 , sizeof( * V_13 ) ) ;
if ( V_10 -> V_69 == V_4 -> V_24 )
V_10 -> V_23 = false ;
F_34 ( V_4 ) ;
F_17 ( V_10 ) ;
return 0 ;
}
static int F_42 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_10 ;
int V_29 ;
struct {
T_1 V_11 ;
T_10 V_12 ;
} * V_13 ;
if ( F_32 ( V_4 -> V_24 != - 1 ) )
return 0 ;
V_29 = F_33 ( V_4 ) ;
if ( F_14 ( V_29 != 0 ) ) {
F_15 ( L_6 ) ;
goto V_43;
}
if ( F_14 ( V_4 -> V_24 >= V_70 ) ) {
V_29 = - V_45 ;
goto V_46;
}
V_13 = F_13 ( V_10 , sizeof( * V_13 ) ) ;
if ( F_14 ( V_13 == NULL ) ) {
F_15 ( L_7
L_8 ) ;
V_29 = - V_41 ;
goto V_46;
}
V_13 -> V_11 . V_24 = V_71 ;
V_13 -> V_11 . V_26 = sizeof( V_13 -> V_12 ) ;
V_13 -> V_12 . V_27 = V_4 -> V_24 ;
F_16 ( V_10 , sizeof( * V_13 ) ) ;
F_30 ( V_10 ) ;
return 0 ;
V_46:
F_34 ( V_4 ) ;
V_43:
return V_29 ;
}
static int F_43 ( struct V_3 * V_4 ,
struct V_48 * V_49 )
{
struct V_9 * V_10 = V_4 -> V_10 ;
struct {
T_1 V_11 ;
T_11 V_12 ;
} * V_13 ;
struct V_50 * V_51 = V_49 -> V_51 ;
F_36 ( V_51 -> V_52 . V_53 != V_54 ) ;
V_13 = F_13 ( V_10 , sizeof( * V_13 ) ) ;
if ( F_14 ( V_13 == NULL ) ) {
F_15 ( L_7
L_9 ) ;
return - V_41 ;
}
V_13 -> V_11 . V_24 = V_72 ;
V_13 -> V_11 . V_26 = sizeof( V_13 -> V_12 ) ;
V_13 -> V_12 . V_27 = V_4 -> V_24 ;
V_13 -> V_12 . V_56 = V_51 -> V_52 . V_57 ;
V_13 -> V_12 . V_58 = V_4 -> V_59 ;
V_4 -> V_59 = false ;
F_16 ( V_10 , sizeof( * V_13 ) ) ;
return 0 ;
}
void F_44 ( struct V_3 * V_73 ,
bool V_60 )
{
struct V_1 * V_2 =
F_6 ( V_73 , struct V_1 , V_4 ) ;
int V_5 ;
F_38 ( V_2 -> V_21 ) ;
for ( V_5 = 0 ; V_5 < V_6 ; ++ V_5 ) {
struct V_3 * V_4 ;
F_2 ( & V_2 -> V_7 ) ;
V_4 = V_2 -> V_8 [ V_74 [ V_5 ] ] ;
if ( V_4 )
V_4 = F_45 ( V_4 ) ;
F_3 ( & V_2 -> V_7 ) ;
if ( ! V_4 )
continue;
F_46 ( F_47 ( V_4 , V_60 ) ) ;
F_4 ( & V_4 ) ;
}
}
static int F_48 ( struct V_3 * V_4 ,
bool V_60 ,
struct V_48 * V_49 )
{
struct V_9 * V_10 = V_4 -> V_10 ;
struct V_50 * V_51 = V_49 -> V_51 ;
struct V_61 * V_62 ;
struct V_1 * V_2 =
F_6 ( V_4 , struct V_1 , V_4 ) ;
struct {
T_1 V_11 ;
T_12 V_12 ;
} * V_63 ;
struct {
T_1 V_11 ;
T_11 V_12 ;
} * V_64 ;
T_7 V_65 ;
T_8 * V_13 ;
F_36 ( V_51 -> V_52 . V_53 != V_54 ) ;
F_7 ( & V_10 -> V_20 ) ;
F_44 ( V_4 , V_60 ) ;
if ( V_2 -> V_75 && V_2 -> V_75 -> V_76 &&
V_60 ) {
F_46 ( V_2 -> V_75 -> V_76 != V_4 ) ;
if ( F_49 ( V_2 -> V_75 ) )
F_15 ( L_11 ) ;
}
V_65 = sizeof( * V_64 ) + ( V_60 ? sizeof( * V_63 ) : 0 ) ;
V_13 = F_13 ( V_10 , V_65 ) ;
if ( F_14 ( V_13 == NULL ) ) {
F_15 ( L_7
L_10 ) ;
F_10 ( & V_10 -> V_20 ) ;
return - V_41 ;
}
V_64 = ( void * ) V_13 ;
if ( V_60 ) {
V_63 = ( void * ) V_13 ;
V_63 -> V_11 . V_24 = V_77 ;
V_63 -> V_11 . V_26 = sizeof( V_63 -> V_12 ) ;
V_63 -> V_12 . V_27 = V_4 -> V_24 ;
V_64 = ( void * ) ( & V_63 [ 1 ] ) ;
}
V_64 -> V_11 . V_24 = V_72 ;
V_64 -> V_11 . V_26 = sizeof( V_64 -> V_12 ) ;
V_64 -> V_12 . V_27 = V_4 -> V_24 ;
V_64 -> V_12 . V_56 = V_67 ;
F_16 ( V_10 , V_65 ) ;
F_10 ( & V_10 -> V_20 ) ;
( void ) F_39 ( NULL , V_10 ,
& V_62 , NULL ) ;
F_40 ( V_51 , V_62 ) ;
if ( F_32 ( V_62 != NULL ) )
F_41 ( & V_62 ) ;
return 0 ;
}
static int V_17 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_10 ;
struct {
T_1 V_11 ;
T_13 V_12 ;
} * V_13 ;
if ( F_32 ( V_4 -> V_24 == - 1 ) )
return 0 ;
V_13 = F_13 ( V_10 , sizeof( * V_13 ) ) ;
if ( F_14 ( V_13 == NULL ) ) {
F_15 ( L_7
L_2 ) ;
return - V_41 ;
}
V_13 -> V_11 . V_24 = V_78 ;
V_13 -> V_11 . V_26 = sizeof( V_13 -> V_12 ) ;
V_13 -> V_12 . V_27 = V_4 -> V_24 ;
F_16 ( V_10 , sizeof( * V_13 ) ) ;
if ( V_10 -> V_69 == V_4 -> V_24 )
V_10 -> V_23 = false ;
F_34 ( V_4 ) ;
F_17 ( V_10 ) ;
return 0 ;
}
static struct V_3 *
F_50 ( struct V_79 * V_80 )
{
return & ( F_6 ( V_80 , struct V_1 , V_80 ) -> V_4 ) ;
}
static void F_51 ( struct V_3 * V_4 )
{
struct V_1 * V_73 =
F_6 ( V_4 , struct V_1 , V_4 ) ;
struct V_9 * V_10 = V_4 -> V_10 ;
if ( V_73 -> V_21 )
F_52 ( V_73 -> V_21 ) ;
( void ) F_53 ( V_4 , NULL ) ;
F_54 ( V_73 , V_80 ) ;
F_55 ( F_56 ( V_10 ) ,
V_81 ) ;
}
static void F_57 ( struct V_79 * * V_82 )
{
struct V_79 * V_80 = * V_82 ;
struct V_1 * V_73 =
F_6 ( V_80 , struct V_1 , V_80 ) ;
struct V_3 * V_4 = & V_73 -> V_4 ;
* V_82 = NULL ;
F_4 ( & V_4 ) ;
}
int F_58 ( struct V_83 * V_84 , void * V_85 ,
struct V_86 * V_87 )
{
struct V_88 * V_89 = (struct V_88 * ) V_85 ;
struct V_90 * V_91 = F_59 ( V_87 ) -> V_91 ;
return F_60 ( V_91 , V_89 -> V_27 , V_92 ) ;
}
static int F_61 ( struct V_83 * V_84 , void * V_85 ,
struct V_86 * V_87 , bool V_28 )
{
struct V_9 * V_10 = F_62 ( V_84 ) ;
struct V_1 * V_73 ;
struct V_3 * V_4 ;
struct V_3 * V_93 ;
struct V_88 * V_89 = (struct V_88 * ) V_85 ;
struct V_90 * V_91 = F_59 ( V_87 ) -> V_91 ;
int V_29 ;
if ( ! V_10 -> V_94 && V_28 ) {
F_15 ( L_12 ) ;
return - V_95 ;
}
if ( F_14 ( V_81 == 0 ) )
V_81 = F_63 ( sizeof( * V_73 ) ) + 128 +
( ( V_10 -> V_36 ) ? F_64 () : 0 ) ;
V_29 = F_65 ( & V_10 -> V_96 , true ) ;
if ( F_14 ( V_29 != 0 ) )
return V_29 ;
V_29 = F_66 ( F_56 ( V_10 ) ,
V_81 ,
false , true ) ;
if ( F_14 ( V_29 != 0 ) ) {
if ( V_29 != - V_97 )
F_15 ( L_13
L_14 ) ;
goto V_98;
}
V_73 = F_67 ( sizeof( * V_73 ) , V_99 ) ;
if ( F_14 ( ! V_73 ) ) {
F_55 ( F_56 ( V_10 ) ,
V_81 ) ;
V_29 = - V_41 ;
goto V_98;
}
V_4 = & V_73 -> V_4 ;
V_73 -> V_80 . V_100 = false ;
V_73 -> V_80 . V_91 = NULL ;
V_29 = F_29 ( V_10 , V_4 , F_51 , V_28 ) ;
if ( F_14 ( V_29 != 0 ) )
goto V_98;
V_93 = F_68 ( & V_73 -> V_4 ) ;
V_29 = F_69 ( V_91 , & V_73 -> V_80 , false , V_101 ,
& F_57 , NULL ) ;
if ( F_14 ( V_29 != 0 ) ) {
F_4 ( & V_93 ) ;
goto V_35;
}
V_89 -> V_27 = V_73 -> V_80 . V_102 . V_103 ;
V_35:
F_4 ( & V_4 ) ;
V_98:
F_70 ( & V_10 -> V_96 ) ;
return V_29 ;
}
int F_71 ( struct V_83 * V_84 , void * V_85 ,
struct V_86 * V_87 )
{
return F_61 ( V_84 , V_85 , V_87 , false ) ;
}
int F_72 ( struct V_83 * V_84 , void * V_85 ,
struct V_86 * V_87 )
{
union V_104 * V_89 = ( F_73 ( V_89 ) ) V_85 ;
struct V_88 * V_105 = & V_89 -> V_105 ;
switch ( V_89 -> V_106 ) {
case V_107 :
return F_61 ( V_84 , V_105 , V_87 , false ) ;
case V_108 :
return F_61 ( V_84 , V_105 , V_87 , true ) ;
default:
break;
}
return - V_95 ;
}
struct V_109 * F_74 ( struct V_3 * V_73 )
{
struct V_1 * V_2 =
F_6 ( V_73 , struct V_1 , V_4 ) ;
return F_75 ( V_2 -> V_21 ) ;
}
struct V_110 * F_76 ( struct V_3 * V_73 )
{
return F_6 ( V_73 , struct V_1 , V_4 ) -> V_19 ;
}
struct V_3 * F_77 ( struct V_3 * V_73 ,
T_14 V_111 )
{
if ( V_111 >= V_6 )
return F_78 ( - V_95 ) ;
return F_68
( F_6 ( V_73 , struct V_1 , V_4 ) ->
V_8 [ V_111 ] ) ;
}
struct V_112 *
F_79 ( struct V_3 * V_73 )
{
return F_6 ( V_73 , struct V_1 , V_4 ) -> V_21 ;
}
int F_53 ( struct V_3 * V_113 ,
struct V_114 * V_115 )
{
struct V_1 * V_2 =
F_6 ( V_113 , struct V_1 , V_4 ) ;
if ( V_115 == NULL ) {
if ( V_2 -> V_75 ) {
V_2 -> V_75 -> V_76 = NULL ;
F_80 ( & V_2 -> V_75 ) ;
V_2 -> V_75 = NULL ;
}
return 0 ;
}
if ( V_2 -> V_75 && V_2 -> V_75 != V_115 )
return - V_95 ;
V_115 -> V_76 = V_113 ;
if ( ! V_2 -> V_75 )
V_2 -> V_75 = F_81 ( V_115 ) ;
return 0 ;
}
struct V_114 *
F_82 ( struct V_3 * V_113 )
{
struct V_1 * V_2 =
F_6 ( V_113 , struct V_1 , V_4 ) ;
return V_2 -> V_75 ;
}
