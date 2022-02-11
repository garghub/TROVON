static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_2 * V_3 )
{
( void ) F_4 ( V_3 ) ;
}
static int F_5 ( struct V_4 * V_5 ,
struct V_2 * V_3 ,
T_1 V_6 ,
T_2 V_7 ,
T_3 type ,
struct V_8 * V_9 ,
void (* F_6) ( struct V_2 * V_3 ) )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
int V_11 ;
V_11 = F_7 ( V_5 , V_3 , true ,
F_6 , & V_12 ) ;
if ( F_8 ( V_11 != 0 ) ) {
if ( F_6 )
F_6 ( V_3 ) ;
else
F_9 ( V_3 ) ;
return V_11 ;
}
V_3 -> V_13 = V_6 ;
if ( V_9 ) {
V_3 -> V_14 = F_10 ( V_9 ) ;
V_3 -> V_15 = V_7 ;
}
V_10 -> V_6 = V_6 ;
V_10 -> type = type ;
F_11 ( V_3 , F_3 ) ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_1 * V_10 = F_1 ( V_3 ) ;
int V_11 ;
struct {
T_4 V_16 ;
T_5 V_17 ;
} * V_18 ;
if ( F_13 ( V_3 -> V_19 != - 1 ) )
return 0 ;
V_11 = F_14 ( V_3 ) ;
if ( F_8 ( V_11 != 0 ) ) {
F_15 ( L_1 ) ;
goto V_20;
}
if ( F_8 ( V_3 -> V_19 >= V_21 ) ) {
V_11 = - V_22 ;
goto V_23;
}
V_18 = F_16 ( V_5 , sizeof( * V_18 ) ) ;
if ( F_8 ( V_18 == NULL ) ) {
F_15 ( L_2
L_3 ) ;
V_11 = - V_24 ;
goto V_23;
}
V_18 -> V_16 . V_19 = V_25 ;
V_18 -> V_16 . V_6 = sizeof( V_18 -> V_17 ) ;
V_18 -> V_17 . V_26 = V_3 -> V_19 ;
V_18 -> V_17 . type = V_10 -> type ;
V_18 -> V_17 . V_27 = V_10 -> V_6 ;
F_17 ( V_5 , sizeof( * V_18 ) ) ;
( void ) F_18 ( V_5 , false ) ;
return 0 ;
V_23:
F_19 ( V_3 ) ;
V_20:
return V_11 ;
}
static int F_20 ( struct V_2 * V_3 ,
struct V_28 * V_29 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct {
T_4 V_16 ;
T_6 V_17 ;
} * V_18 ;
struct V_30 * V_31 = V_29 -> V_31 ;
F_21 ( V_31 -> V_32 . V_33 != V_34 ) ;
V_18 = F_16 ( V_5 , sizeof( * V_18 ) ) ;
if ( F_8 ( V_18 == NULL ) ) {
F_15 ( L_2
L_4 ) ;
return - V_24 ;
}
V_18 -> V_16 . V_19 = V_35 ;
V_18 -> V_16 . V_6 = sizeof( V_18 -> V_17 ) ;
V_18 -> V_17 . V_26 = V_3 -> V_19 ;
V_18 -> V_17 . V_36 = V_31 -> V_32 . V_37 ;
V_18 -> V_17 . V_38 = 0 ;
V_3 -> V_39 = false ;
F_17 ( V_5 , sizeof( * V_18 ) ) ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 ,
bool V_40 ,
struct V_28 * V_29 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct {
T_4 V_16 ;
T_6 V_17 ;
} * V_18 ;
struct V_41 * V_42 ;
F_21 ( V_3 -> V_14 -> V_43 . V_32 . V_33 != V_34 ) ;
V_18 = F_16 ( V_5 , sizeof( * V_18 ) ) ;
if ( F_8 ( V_18 == NULL ) ) {
F_15 ( L_2
L_5 ) ;
return - V_24 ;
}
V_18 -> V_16 . V_19 = V_35 ;
V_18 -> V_16 . V_6 = sizeof( V_18 -> V_17 ) ;
V_18 -> V_17 . V_26 = V_3 -> V_19 ;
V_18 -> V_17 . V_36 = V_44 ;
V_18 -> V_17 . V_38 = 0 ;
F_17 ( V_5 , sizeof( * V_18 ) ) ;
( void ) F_23 ( NULL , V_5 ,
& V_42 , NULL ) ;
F_24 ( V_29 -> V_31 , V_42 ) ;
if ( F_13 ( V_42 != NULL ) )
F_25 ( & V_42 ) ;
return 0 ;
}
static int F_4 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct {
T_4 V_16 ;
T_7 V_17 ;
} * V_18 ;
if ( F_13 ( V_3 -> V_19 == - 1 ) )
return 0 ;
F_26 ( & V_5 -> V_45 ) ;
F_27 ( & V_3 -> V_46 ) ;
V_18 = F_16 ( V_5 , sizeof( * V_18 ) ) ;
if ( F_8 ( V_18 == NULL ) ) {
F_15 ( L_2
L_6 ) ;
F_28 ( & V_5 -> V_45 ) ;
return - V_24 ;
}
V_18 -> V_16 . V_19 = V_47 ;
V_18 -> V_16 . V_6 = sizeof( V_18 -> V_17 ) ;
V_18 -> V_17 . V_26 = V_3 -> V_19 ;
F_17 ( V_5 , sizeof( * V_18 ) ) ;
F_28 ( & V_5 -> V_45 ) ;
F_19 ( V_3 ) ;
F_29 ( V_5 , false ) ;
return 0 ;
}
static struct V_2 *
F_30 ( struct V_48 * V_43 )
{
return & ( F_2 ( V_43 , struct V_49 , V_43 ) ->
V_10 . V_3 ) ;
}
static void F_31 ( struct V_2 * V_3 )
{
struct V_49 * V_50 =
F_2 ( V_3 , struct V_49 , V_10 . V_3 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_32 ( V_50 , V_43 ) ;
F_33 ( F_34 ( V_5 ) ,
V_51 ) ;
}
static void F_35 ( struct V_2 * V_3 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
F_9 ( V_10 ) ;
F_33 ( F_34 ( V_5 ) ,
V_52 ) ;
}
static void F_36 ( struct V_48 * * V_53 )
{
struct V_48 * V_43 = * V_53 ;
struct V_2 * V_3 = F_30 ( V_43 ) ;
* V_53 = NULL ;
F_37 ( & V_3 ) ;
}
int F_38 ( struct V_54 * V_55 , void * V_56 ,
struct V_57 * V_58 )
{
struct V_59 * V_60 = (struct V_59 * ) V_56 ;
struct V_61 * V_62 = F_39 ( V_58 ) -> V_62 ;
return F_40 ( V_62 , V_60 -> V_63 ,
V_64 ) ;
}
static int F_41 ( struct V_4 * V_5 ,
struct V_8 * V_65 ,
T_8 V_66 ,
T_8 V_7 ,
T_3 V_67 ,
struct V_61 * V_62 ,
T_9 * V_63 )
{
struct V_49 * V_50 ;
struct V_2 * V_3 , * V_68 ;
int V_11 ;
if ( F_8 ( V_51 == 0 ) )
V_51 =
F_42 ( sizeof( struct V_49 ) ) + 128 ;
V_11 = F_43 ( F_34 ( V_5 ) ,
V_51 ,
false , true ) ;
if ( F_8 ( V_11 != 0 ) ) {
if ( V_11 != - V_69 )
F_15 ( L_7
L_3 ) ;
goto V_70;
}
V_50 = F_44 ( sizeof( * V_50 ) , V_71 ) ;
if ( F_8 ( V_50 == NULL ) ) {
F_33 ( F_34 ( V_5 ) ,
V_51 ) ;
V_11 = - V_24 ;
goto V_70;
}
V_3 = & V_50 -> V_10 . V_3 ;
V_50 -> V_43 . V_72 = false ;
V_50 -> V_43 . V_62 = NULL ;
V_11 = F_5 ( V_5 , V_3 , V_66 ,
V_7 , V_67 , V_65 ,
F_31 ) ;
if ( F_8 ( V_11 != 0 ) )
goto V_70;
V_68 = F_45 ( V_3 ) ;
V_11 = F_46 ( V_62 , & V_50 -> V_43 , false ,
V_73 ,
& F_36 , NULL ) ;
if ( F_8 ( V_11 != 0 ) ) {
F_37 ( & V_68 ) ;
goto V_74;
}
if ( V_63 )
* V_63 = V_50 -> V_43 . V_75 . V_76 ;
V_74:
F_37 ( & V_3 ) ;
V_70:
return V_11 ;
}
struct V_2 * F_47 ( struct V_4 * V_5 ,
struct V_8 * V_65 ,
T_8 V_66 ,
T_8 V_7 ,
T_3 V_67 )
{
struct V_1 * V_10 ;
struct V_2 * V_3 ;
int V_11 ;
if ( F_8 ( V_52 == 0 ) )
V_52 =
F_42 ( sizeof( struct V_1 ) ) + 128 ;
V_11 = F_43 ( F_34 ( V_5 ) ,
V_52 ,
false , true ) ;
if ( F_8 ( V_11 != 0 ) ) {
if ( V_11 != - V_69 )
F_15 ( L_7
L_3 ) ;
goto V_74;
}
V_10 = F_44 ( sizeof( * V_10 ) , V_71 ) ;
if ( F_8 ( V_10 == NULL ) ) {
F_33 ( F_34 ( V_5 ) ,
V_52 ) ;
V_11 = - V_24 ;
goto V_74;
}
V_3 = & V_10 -> V_3 ;
V_11 = F_5 ( V_5 , V_3 , V_66 ,
V_7 , V_67 , V_65 ,
F_35 ) ;
V_74:
return V_11 ? F_48 ( V_11 ) : V_3 ;
}
int F_49 ( struct V_54 * V_55 , void * V_56 ,
struct V_57 * V_58 )
{
struct V_4 * V_5 = F_50 ( V_55 ) ;
struct V_77 * V_60 =
(struct V_77 * ) V_56 ;
struct V_61 * V_62 = F_39 ( V_58 ) -> V_62 ;
struct V_8 * V_65 = NULL ;
T_3 V_67 ;
int V_11 ;
if ( V_60 -> V_78 != V_44 ) {
V_11 = F_51 ( V_62 , V_60 -> V_78 ,
& V_65 ) ;
if ( F_8 ( V_11 != 0 ) ) {
F_15 ( L_8
L_3 ) ;
return V_11 ;
}
if ( ( V_79 ) V_65 -> V_43 . V_80 * V_81 <
( V_79 ) V_60 -> V_6 + ( V_79 ) V_60 -> V_7 ) {
F_15 ( L_9 ) ;
V_11 = - V_82 ;
goto V_83;
}
}
switch ( V_60 -> V_67 ) {
case V_84 :
V_67 = V_85 ;
break;
case V_86 :
V_67 = V_87 ;
break;
case V_88 :
V_67 = V_89 ;
break;
default:
F_15 ( L_10 ) ;
V_11 = - V_82 ;
goto V_83;
}
V_11 = F_52 ( & V_5 -> V_90 , true ) ;
if ( F_8 ( V_11 != 0 ) )
goto V_83;
V_11 = F_41 ( V_5 , V_65 , V_60 -> V_6 , V_60 -> V_7 ,
V_67 , V_62 , & V_60 -> V_91 ) ;
F_53 ( & V_5 -> V_90 ) ;
V_83:
F_54 ( & V_65 ) ;
return V_11 ;
}
static bool F_55 ( T_9 V_92 , T_3 V_67 )
{
return V_92 <= ( ( 1 << 20 ) - 1 ) && ( unsigned ) V_67 < 16 ;
}
static T_9 F_56 ( T_9 V_92 , T_3 V_67 )
{
return V_92 | ( V_67 << 20 ) ;
}
int F_57 ( struct V_93 * V_94 ,
T_9 V_92 , T_3 V_67 ,
struct V_95 * V_96 )
{
if ( ! F_55 ( V_92 , V_67 ) )
return - V_82 ;
return F_58 ( V_94 , V_97 ,
F_56 ( V_92 ,
V_67 ) ,
V_96 ) ;
}
int F_59 ( struct V_4 * V_5 ,
struct V_93 * V_94 ,
T_9 V_92 , const void * V_98 ,
T_3 V_67 ,
T_8 V_6 ,
struct V_95 * V_96 )
{
struct V_8 * V_99 ;
struct V_100 V_101 ;
bool V_102 ;
int V_11 ;
struct V_2 * V_3 ;
if ( ! F_55 ( V_92 , V_67 ) )
return - V_82 ;
V_99 = F_44 ( sizeof( * V_99 ) , V_71 ) ;
if ( F_8 ( V_99 == NULL ) )
return - V_24 ;
V_11 = F_60 ( V_5 , V_99 , V_6 , & V_103 ,
true , V_104 ) ;
if ( F_8 ( V_11 != 0 ) )
goto V_70;
V_11 = F_61 ( & V_99 -> V_43 , false , true , false , NULL ) ;
if ( F_8 ( V_11 != 0 ) )
goto V_105;
V_11 = F_62 ( & V_99 -> V_43 , 0 , F_63 ( V_6 ) >> V_106 ,
& V_101 ) ;
if ( F_8 ( V_11 != 0 ) ) {
F_64 ( & V_99 -> V_43 ) ;
goto V_105;
}
memcpy ( F_65 ( & V_101 , & V_102 ) , V_98 , V_6 ) ;
F_66 ( V_102 ) ;
F_67 ( & V_101 ) ;
V_11 = F_68 ( & V_99 -> V_43 , & V_107 , false , true ) ;
F_66 ( V_11 != 0 ) ;
F_64 ( & V_99 -> V_43 ) ;
V_3 = F_47 ( V_5 , V_99 , V_6 , 0 , V_67 ) ;
if ( F_8 ( V_11 != 0 ) )
goto V_105;
V_11 = F_69 ( V_94 , V_97 ,
F_56 ( V_92 , V_67 ) ,
V_3 , V_96 ) ;
F_37 ( & V_3 ) ;
V_105:
F_54 ( & V_99 ) ;
V_70:
return V_11 ;
}
struct V_2 *
F_70 ( struct V_93 * V_94 ,
T_9 V_92 ,
T_3 V_67 )
{
if ( ! F_55 ( V_92 , V_67 ) )
return F_48 ( - V_82 ) ;
return F_71 ( V_94 , V_97 ,
F_56 ( V_92 ,
V_67 ) ) ;
}
