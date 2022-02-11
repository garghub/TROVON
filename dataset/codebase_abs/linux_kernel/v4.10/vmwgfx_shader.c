static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_4 *
F_3 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_4 , V_3 ) ;
}
static void F_4 ( struct V_2 * V_3 )
{
if ( F_5 ( V_3 -> V_5 -> V_6 ) )
( void ) V_3 -> V_5 -> V_6 ( V_3 ) ;
else
V_3 -> V_7 = - 1 ;
}
static int F_6 ( struct V_8 * V_9 ,
struct V_2 * V_3 ,
T_1 V_10 ,
T_2 V_11 ,
T_3 type ,
T_4 V_12 ,
T_4 V_13 ,
struct V_14 * V_15 ,
void (* F_7) ( struct V_2 * V_3 ) )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_17 ;
V_17 = F_8 ( V_9 , V_3 , true , F_7 ,
& V_18 ) ;
if ( F_9 ( V_17 != 0 ) ) {
if ( F_7 )
F_7 ( V_3 ) ;
else
F_10 ( V_3 ) ;
return V_17 ;
}
V_3 -> V_19 = V_10 ;
if ( V_15 ) {
V_3 -> V_20 = F_11 ( V_15 ) ;
V_3 -> V_21 = V_11 ;
}
V_16 -> V_10 = V_10 ;
V_16 -> type = type ;
V_16 -> V_12 = V_12 ;
V_16 -> V_13 = V_13 ;
F_12 ( V_3 , F_4 ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_17 ;
struct {
T_5 V_22 ;
T_6 V_23 ;
} * V_24 ;
if ( F_5 ( V_3 -> V_7 != - 1 ) )
return 0 ;
V_17 = F_14 ( V_3 ) ;
if ( F_9 ( V_17 != 0 ) ) {
F_15 ( L_1 ) ;
goto V_25;
}
if ( F_9 ( V_3 -> V_7 >= V_26 ) ) {
V_17 = - V_27 ;
goto V_28;
}
V_24 = F_16 ( V_9 , sizeof( * V_24 ) ) ;
if ( F_9 ( V_24 == NULL ) ) {
F_15 ( L_2
L_3 ) ;
V_17 = - V_29 ;
goto V_28;
}
V_24 -> V_22 . V_7 = V_30 ;
V_24 -> V_22 . V_10 = sizeof( V_24 -> V_23 ) ;
V_24 -> V_23 . V_31 = V_3 -> V_7 ;
V_24 -> V_23 . type = V_16 -> type ;
V_24 -> V_23 . V_32 = V_16 -> V_10 ;
F_17 ( V_9 , sizeof( * V_24 ) ) ;
F_18 ( V_9 ) ;
return 0 ;
V_28:
F_19 ( V_3 ) ;
V_25:
return V_17 ;
}
static int F_20 ( struct V_2 * V_3 ,
struct V_33 * V_34 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct {
T_5 V_22 ;
T_7 V_23 ;
} * V_24 ;
struct V_35 * V_36 = V_34 -> V_36 ;
F_21 ( V_36 -> V_37 . V_38 != V_39 ) ;
V_24 = F_16 ( V_9 , sizeof( * V_24 ) ) ;
if ( F_9 ( V_24 == NULL ) ) {
F_15 ( L_2
L_4 ) ;
return - V_29 ;
}
V_24 -> V_22 . V_7 = V_40 ;
V_24 -> V_22 . V_10 = sizeof( V_24 -> V_23 ) ;
V_24 -> V_23 . V_31 = V_3 -> V_7 ;
V_24 -> V_23 . V_41 = V_36 -> V_37 . V_42 ;
V_24 -> V_23 . V_43 = V_3 -> V_21 ;
V_3 -> V_44 = false ;
F_17 ( V_9 , sizeof( * V_24 ) ) ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 ,
bool V_45 ,
struct V_33 * V_34 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct {
T_5 V_22 ;
T_7 V_23 ;
} * V_24 ;
struct V_46 * V_47 ;
F_21 ( V_3 -> V_20 -> V_48 . V_37 . V_38 != V_39 ) ;
V_24 = F_16 ( V_9 , sizeof( * V_24 ) ) ;
if ( F_9 ( V_24 == NULL ) ) {
F_15 ( L_2
L_5 ) ;
return - V_29 ;
}
V_24 -> V_22 . V_7 = V_40 ;
V_24 -> V_22 . V_10 = sizeof( V_24 -> V_23 ) ;
V_24 -> V_23 . V_31 = V_3 -> V_7 ;
V_24 -> V_23 . V_41 = V_49 ;
V_24 -> V_23 . V_43 = 0 ;
F_17 ( V_9 , sizeof( * V_24 ) ) ;
( void ) F_23 ( NULL , V_9 ,
& V_47 , NULL ) ;
F_24 ( V_34 -> V_36 , V_47 ) ;
if ( F_5 ( V_47 != NULL ) )
F_25 ( & V_47 ) ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct {
T_5 V_22 ;
T_8 V_23 ;
} * V_24 ;
if ( F_5 ( V_3 -> V_7 == - 1 ) )
return 0 ;
F_27 ( & V_9 -> V_50 ) ;
F_28 ( & V_3 -> V_51 ) ;
V_24 = F_16 ( V_9 , sizeof( * V_24 ) ) ;
if ( F_9 ( V_24 == NULL ) ) {
F_15 ( L_2
L_6 ) ;
F_29 ( & V_9 -> V_50 ) ;
return - V_29 ;
}
V_24 -> V_22 . V_7 = V_52 ;
V_24 -> V_22 . V_10 = sizeof( V_24 -> V_23 ) ;
V_24 -> V_23 . V_31 = V_3 -> V_7 ;
F_17 ( V_9 , sizeof( * V_24 ) ) ;
F_29 ( & V_9 -> V_50 ) ;
F_19 ( V_3 ) ;
F_30 ( V_9 ) ;
return 0 ;
}
static void F_31 ( struct V_2 * V_3 ,
enum V_53 V_54 )
{
struct V_4 * V_16 = F_3 ( V_3 ) ;
struct V_8 * V_9 = V_3 -> V_9 ;
if ( V_54 == V_55 ) {
F_27 ( & V_9 -> V_50 ) ;
F_32 ( V_16 -> V_56 ,
& V_16 -> V_57 ) ;
V_16 -> V_58 = true ;
V_3 -> V_7 = V_16 -> V_7 ;
F_29 ( & V_9 -> V_50 ) ;
} else {
F_27 ( & V_9 -> V_50 ) ;
F_33 ( & V_16 -> V_57 ) ;
V_16 -> V_58 = false ;
V_3 -> V_7 = - 1 ;
F_29 ( & V_9 -> V_50 ) ;
}
}
static int F_34 ( struct V_2 * V_3 )
{
struct V_4 * V_16 = F_3 ( V_3 ) ;
struct V_8 * V_9 = V_3 -> V_9 ;
struct {
T_5 V_22 ;
T_9 V_23 ;
} * V_24 ;
if ( ! F_35 ( & V_16 -> V_57 ) || ! V_16 -> V_58 )
return 0 ;
V_24 = F_36 ( V_9 , sizeof( * V_24 ) ,
V_16 -> V_59 -> V_7 ) ;
if ( F_9 ( V_24 == NULL ) ) {
F_15 ( L_2
L_7 ) ;
return - V_29 ;
}
V_24 -> V_22 . V_7 = V_60 ;
V_24 -> V_22 . V_10 = sizeof( V_24 -> V_23 ) ;
V_24 -> V_23 . V_61 = V_16 -> V_59 -> V_7 ;
V_24 -> V_23 . V_31 = V_16 -> V_7 ;
V_24 -> V_23 . V_41 = V_3 -> V_20 -> V_48 . V_37 . V_42 ;
V_24 -> V_23 . V_43 = V_3 -> V_21 ;
F_17 ( V_9 , sizeof( * V_24 ) ) ;
F_32 ( V_16 -> V_56 , & V_16 -> V_57 ) ;
return 0 ;
}
static int F_37 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_4 * V_16 = F_3 ( V_3 ) ;
int V_17 = 0 ;
F_38 ( ! V_16 -> V_58 ) ;
if ( ! F_35 ( & V_3 -> V_62 ) ) {
F_27 ( & V_9 -> V_50 ) ;
V_17 = F_34 ( V_3 ) ;
F_29 ( & V_9 -> V_50 ) ;
}
V_3 -> V_7 = V_16 -> V_7 ;
return V_17 ;
}
static int F_39 ( struct V_2 * V_3 ,
struct V_33 * V_34 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_35 * V_36 = V_34 -> V_36 ;
F_21 ( V_36 -> V_37 . V_38 != V_39 ) ;
F_27 ( & V_9 -> V_50 ) ;
F_34 ( V_3 ) ;
F_29 ( & V_9 -> V_50 ) ;
return 0 ;
}
static int F_40 ( struct V_2 * V_3 )
{
struct V_4 * V_16 = F_3 ( V_3 ) ;
struct V_8 * V_9 = V_3 -> V_9 ;
struct {
T_5 V_22 ;
T_9 V_23 ;
} * V_24 ;
if ( F_35 ( & V_16 -> V_57 ) )
return 0 ;
F_38 ( ! V_16 -> V_58 ) ;
V_24 = F_16 ( V_9 , sizeof( * V_24 ) ) ;
if ( F_9 ( V_24 == NULL ) ) {
F_15 ( L_2
L_7 ) ;
return - V_29 ;
}
V_24 -> V_22 . V_7 = V_60 ;
V_24 -> V_22 . V_10 = sizeof( V_24 -> V_23 ) ;
V_24 -> V_23 . V_61 = V_16 -> V_59 -> V_7 ;
V_24 -> V_23 . V_31 = V_3 -> V_7 ;
V_24 -> V_23 . V_41 = V_49 ;
V_24 -> V_23 . V_43 = 0 ;
F_17 ( V_9 , sizeof( * V_24 ) ) ;
V_3 -> V_7 = - 1 ;
F_33 ( & V_16 -> V_57 ) ;
return 0 ;
}
static int F_41 ( struct V_2 * V_3 ,
bool V_45 ,
struct V_33 * V_34 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_46 * V_47 ;
int V_17 ;
F_21 ( V_3 -> V_20 -> V_48 . V_37 . V_38 != V_39 ) ;
F_27 ( & V_9 -> V_50 ) ;
V_17 = F_40 ( V_3 ) ;
F_29 ( & V_9 -> V_50 ) ;
if ( V_17 )
return V_17 ;
( void ) F_23 ( NULL , V_9 ,
& V_47 , NULL ) ;
F_24 ( V_34 -> V_36 , V_47 ) ;
if ( F_5 ( V_47 != NULL ) )
F_25 ( & V_47 ) ;
return 0 ;
}
void F_42 ( struct V_8 * V_9 ,
struct V_63 * V_64 ,
bool V_45 )
{
struct V_4 * V_65 , * V_66 ;
F_38 ( ! F_43 ( & V_9 -> V_50 ) ) ;
F_44 (entry, next, list, cotable_head) {
F_45 ( F_40 ( & V_65 -> V_3 ) ) ;
if ( ! V_45 )
V_65 -> V_58 = false ;
}
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_9 ;
struct V_4 * V_16 = F_3 ( V_3 ) ;
F_47 ( & V_16 -> V_56 ) ;
F_10 ( V_16 ) ;
F_48 ( F_49 ( V_9 ) , V_67 ) ;
}
int F_50 ( struct V_68 * V_69 ,
struct V_2 * V_59 ,
T_10 V_70 ,
T_3 V_71 ,
struct V_63 * V_64 )
{
struct V_4 * V_16 ;
struct V_2 * V_3 ;
struct V_8 * V_9 = V_59 -> V_9 ;
int V_17 ;
if ( ! V_67 )
V_67 = F_51 ( sizeof( * V_16 ) ) ;
if ( ! F_52 ( V_70 , V_71 ) )
return - V_72 ;
V_17 = F_53 ( F_49 ( V_9 ) , V_67 ,
false , true ) ;
if ( V_17 ) {
if ( V_17 != - V_73 )
F_15 ( L_8
L_3 ) ;
return V_17 ;
}
V_16 = F_54 ( sizeof( * V_16 ) , V_74 ) ;
if ( ! V_16 ) {
F_48 ( F_49 ( V_9 ) , V_67 ) ;
return - V_29 ;
}
V_3 = & V_16 -> V_3 ;
V_16 -> V_59 = V_59 ;
V_16 -> V_56 = F_55 ( V_59 , V_75 ) ;
V_16 -> V_7 = V_70 ;
V_16 -> V_58 = false ;
F_56 ( & V_16 -> V_57 ) ;
V_17 = F_8 ( V_9 , V_3 , true ,
F_46 , & V_76 ) ;
if ( V_17 )
goto V_77;
V_17 = F_57 ( V_69 , V_78 ,
F_58 ( V_70 , 0 ) ,
V_3 , V_64 ) ;
if ( V_17 )
goto V_77;
V_3 -> V_7 = V_16 -> V_7 ;
F_12 ( V_3 , F_4 ) ;
V_77:
F_47 ( & V_3 ) ;
return V_17 ;
}
static struct V_2 *
F_59 ( struct V_79 * V_48 )
{
return & ( F_2 ( V_48 , struct V_80 , V_48 ) ->
V_16 . V_3 ) ;
}
static void F_60 ( struct V_2 * V_3 )
{
struct V_80 * V_81 =
F_2 ( V_3 , struct V_80 , V_16 . V_3 ) ;
struct V_8 * V_9 = V_3 -> V_9 ;
F_61 ( V_81 , V_48 ) ;
F_48 ( F_49 ( V_9 ) ,
V_82 ) ;
}
static void F_62 ( struct V_2 * V_3 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_3 -> V_9 ;
F_10 ( V_16 ) ;
F_48 ( F_49 ( V_9 ) ,
V_83 ) ;
}
static void F_63 ( struct V_79 * * V_84 )
{
struct V_79 * V_48 = * V_84 ;
struct V_2 * V_3 = F_59 ( V_48 ) ;
* V_84 = NULL ;
F_47 ( & V_3 ) ;
}
int F_64 ( struct V_85 * V_86 , void * V_87 ,
struct V_88 * V_89 )
{
struct V_90 * V_91 = (struct V_90 * ) V_87 ;
struct V_92 * V_93 = F_65 ( V_89 ) -> V_93 ;
return F_66 ( V_93 , V_91 -> V_94 ,
V_95 ) ;
}
static int F_67 ( struct V_8 * V_9 ,
struct V_14 * V_96 ,
T_11 V_97 ,
T_11 V_11 ,
T_3 V_71 ,
T_4 V_12 ,
T_4 V_13 ,
struct V_92 * V_93 ,
T_10 * V_94 )
{
struct V_80 * V_81 ;
struct V_2 * V_3 , * V_98 ;
int V_17 ;
if ( F_9 ( V_82 == 0 ) )
V_82 =
F_51 ( sizeof( struct V_80 ) ) + 128 ;
V_17 = F_53 ( F_49 ( V_9 ) ,
V_82 ,
false , true ) ;
if ( F_9 ( V_17 != 0 ) ) {
if ( V_17 != - V_73 )
F_15 ( L_8
L_3 ) ;
goto V_99;
}
V_81 = F_68 ( sizeof( * V_81 ) , V_74 ) ;
if ( F_9 ( V_81 == NULL ) ) {
F_48 ( F_49 ( V_9 ) ,
V_82 ) ;
V_17 = - V_29 ;
goto V_99;
}
V_3 = & V_81 -> V_16 . V_3 ;
V_81 -> V_48 . V_100 = false ;
V_81 -> V_48 . V_93 = NULL ;
V_17 = F_6 ( V_9 , V_3 , V_97 ,
V_11 , V_71 , V_12 ,
V_13 , V_96 ,
F_60 ) ;
if ( F_9 ( V_17 != 0 ) )
goto V_99;
V_98 = F_69 ( V_3 ) ;
V_17 = F_70 ( V_93 , & V_81 -> V_48 , false ,
V_101 ,
& F_63 , NULL ) ;
if ( F_9 ( V_17 != 0 ) ) {
F_47 ( & V_98 ) ;
goto V_102;
}
if ( V_94 )
* V_94 = V_81 -> V_48 . V_103 . V_104 ;
V_102:
F_47 ( & V_3 ) ;
V_99:
return V_17 ;
}
static struct V_2 * F_71 ( struct V_8 * V_9 ,
struct V_14 * V_96 ,
T_11 V_97 ,
T_11 V_11 ,
T_3 V_71 )
{
struct V_1 * V_16 ;
struct V_2 * V_3 ;
int V_17 ;
if ( F_9 ( V_83 == 0 ) )
V_83 =
F_51 ( sizeof( struct V_1 ) ) + 128 ;
V_17 = F_53 ( F_49 ( V_9 ) ,
V_83 ,
false , true ) ;
if ( F_9 ( V_17 != 0 ) ) {
if ( V_17 != - V_73 )
F_15 ( L_8
L_3 ) ;
goto V_102;
}
V_16 = F_68 ( sizeof( * V_16 ) , V_74 ) ;
if ( F_9 ( V_16 == NULL ) ) {
F_48 ( F_49 ( V_9 ) ,
V_83 ) ;
V_17 = - V_29 ;
goto V_102;
}
V_3 = & V_16 -> V_3 ;
V_17 = F_6 ( V_9 , V_3 , V_97 ,
V_11 , V_71 , 0 , 0 , V_96 ,
F_62 ) ;
V_102:
return V_17 ? F_72 ( V_17 ) : V_3 ;
}
static int F_73 ( struct V_85 * V_86 , struct V_88 * V_89 ,
enum V_105 V_106 ,
T_10 V_107 , T_11 V_10 , T_11 V_11 ,
T_4 V_12 , T_4 V_13 ,
T_1 * V_108 )
{
struct V_8 * V_9 = F_74 ( V_86 ) ;
struct V_92 * V_93 = F_65 ( V_89 ) -> V_93 ;
struct V_14 * V_96 = NULL ;
T_3 V_71 ;
int V_17 ;
if ( V_107 != V_49 ) {
V_17 = F_75 ( V_93 , V_107 ,
& V_96 , NULL ) ;
if ( F_9 ( V_17 != 0 ) ) {
F_15 ( L_9
L_3 ) ;
return V_17 ;
}
if ( ( V_109 ) V_96 -> V_48 . V_110 * V_111 <
( V_109 ) V_10 + ( V_109 ) V_11 ) {
F_15 ( L_10 ) ;
V_17 = - V_72 ;
goto V_112;
}
}
switch ( V_106 ) {
case V_113 :
V_71 = V_114 ;
break;
case V_115 :
V_71 = V_116 ;
break;
default:
F_15 ( L_11 ) ;
V_17 = - V_72 ;
goto V_112;
}
V_17 = F_76 ( & V_9 -> V_117 , true ) ;
if ( F_9 ( V_17 != 0 ) )
goto V_112;
V_17 = F_67 ( V_9 , V_96 , V_10 , V_11 ,
V_71 , V_12 ,
V_13 , V_93 , V_108 ) ;
F_77 ( & V_9 -> V_117 ) ;
V_112:
F_78 ( & V_96 ) ;
return V_17 ;
}
static bool F_52 ( T_10 V_70 , T_3 V_71 )
{
return V_70 <= ( ( 1 << 20 ) - 1 ) && ( unsigned ) V_71 < 16 ;
}
static T_10 F_58 ( T_10 V_70 , T_3 V_71 )
{
return V_70 | ( V_71 << 20 ) ;
}
int F_79 ( struct V_68 * V_69 ,
T_10 V_70 , T_3 V_71 ,
struct V_63 * V_64 )
{
struct V_2 * V_118 ;
if ( ! F_52 ( V_70 , V_71 ) )
return - V_72 ;
return F_80 ( V_69 , V_78 ,
F_58 ( V_70 , V_71 ) ,
V_64 , & V_118 ) ;
}
int F_81 ( struct V_8 * V_9 ,
struct V_68 * V_69 ,
T_10 V_70 , const void * V_119 ,
T_3 V_71 ,
T_11 V_10 ,
struct V_63 * V_64 )
{
struct V_14 * V_120 ;
struct V_121 V_122 ;
bool V_123 ;
int V_17 ;
struct V_2 * V_3 ;
if ( ! F_52 ( V_70 , V_71 ) )
return - V_72 ;
V_120 = F_68 ( sizeof( * V_120 ) , V_74 ) ;
if ( F_9 ( V_120 == NULL ) )
return - V_29 ;
V_17 = F_82 ( V_9 , V_120 , V_10 , & V_124 ,
true , V_125 ) ;
if ( F_9 ( V_17 != 0 ) )
goto V_99;
V_17 = F_83 ( & V_120 -> V_48 , false , true , NULL ) ;
if ( F_9 ( V_17 != 0 ) )
goto V_126;
V_17 = F_84 ( & V_120 -> V_48 , 0 , F_85 ( V_10 ) >> V_127 ,
& V_122 ) ;
if ( F_9 ( V_17 != 0 ) ) {
F_86 ( & V_120 -> V_48 ) ;
goto V_126;
}
memcpy ( F_87 ( & V_122 , & V_123 ) , V_119 , V_10 ) ;
F_45 ( V_123 ) ;
F_88 ( & V_122 ) ;
V_17 = F_89 ( & V_120 -> V_48 , & V_128 , false , true ) ;
F_45 ( V_17 != 0 ) ;
F_86 ( & V_120 -> V_48 ) ;
V_3 = F_71 ( V_9 , V_120 , V_10 , 0 , V_71 ) ;
if ( F_9 ( V_17 != 0 ) )
goto V_126;
V_17 = F_57 ( V_69 , V_78 ,
F_58 ( V_70 , V_71 ) ,
V_3 , V_64 ) ;
F_47 ( & V_3 ) ;
V_126:
F_78 ( & V_120 ) ;
V_99:
return V_17 ;
}
struct V_2 *
F_90 ( struct V_68 * V_69 ,
T_10 V_70 ,
T_3 V_71 )
{
if ( ! F_52 ( V_70 , V_71 ) )
return F_72 ( - V_72 ) ;
return F_91 ( V_69 , V_78 ,
F_58 ( V_70 , V_71 ) ) ;
}
int F_92 ( struct V_85 * V_86 , void * V_87 ,
struct V_88 * V_89 )
{
struct V_129 * V_91 =
(struct V_129 * ) V_87 ;
return F_73 ( V_86 , V_89 , V_91 -> V_71 ,
V_91 -> V_107 ,
V_91 -> V_10 , V_91 -> V_11 ,
0 , 0 ,
& V_91 -> V_108 ) ;
}
