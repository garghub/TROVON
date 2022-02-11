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
static void F_35 ( struct V_48 * * V_52 )
{
struct V_48 * V_43 = * V_52 ;
struct V_2 * V_3 = F_30 ( V_43 ) ;
* V_52 = NULL ;
F_36 ( & V_3 ) ;
}
int F_37 ( struct V_53 * V_54 , void * V_55 ,
struct V_56 * V_57 )
{
struct V_58 * V_59 = (struct V_58 * ) V_55 ;
struct V_60 * V_61 = F_38 ( V_57 ) -> V_61 ;
return F_39 ( V_61 , V_59 -> V_62 ,
V_63 ) ;
}
static int F_40 ( struct V_4 * V_5 ,
struct V_8 * V_64 ,
T_8 V_65 ,
T_8 V_7 ,
T_3 V_66 ,
struct V_60 * V_61 ,
T_9 * V_62 )
{
struct V_49 * V_50 ;
struct V_2 * V_3 , * V_67 ;
int V_11 ;
if ( F_8 ( V_51 == 0 ) )
V_51 =
F_41 ( sizeof( struct V_49 ) ) + 128 ;
V_11 = F_42 ( F_34 ( V_5 ) ,
V_51 ,
false , true ) ;
if ( F_8 ( V_11 != 0 ) ) {
if ( V_11 != - V_68 )
F_15 ( L_7
L_3 ) ;
goto V_69;
}
V_50 = F_43 ( sizeof( * V_50 ) , V_70 ) ;
if ( F_8 ( V_50 == NULL ) ) {
F_33 ( F_34 ( V_5 ) ,
V_51 ) ;
V_11 = - V_24 ;
goto V_69;
}
V_3 = & V_50 -> V_10 . V_3 ;
V_50 -> V_43 . V_71 = false ;
V_50 -> V_43 . V_61 = NULL ;
V_11 = F_5 ( V_5 , V_3 , V_65 ,
V_7 , V_66 , V_64 ,
F_31 ) ;
if ( F_8 ( V_11 != 0 ) )
goto V_69;
V_67 = F_44 ( V_3 ) ;
V_11 = F_45 ( V_61 , & V_50 -> V_43 , false ,
V_72 ,
& F_35 , NULL ) ;
if ( F_8 ( V_11 != 0 ) ) {
F_36 ( & V_67 ) ;
goto V_73;
}
if ( V_62 )
* V_62 = V_50 -> V_43 . V_74 . V_75 ;
V_73:
F_36 ( & V_3 ) ;
V_69:
return V_11 ;
}
int F_46 ( struct V_53 * V_54 , void * V_55 ,
struct V_56 * V_57 )
{
struct V_4 * V_5 = F_47 ( V_54 ) ;
struct V_76 * V_59 =
(struct V_76 * ) V_55 ;
struct V_60 * V_61 = F_38 ( V_57 ) -> V_61 ;
struct V_8 * V_64 = NULL ;
T_3 V_66 ;
int V_11 ;
if ( V_59 -> V_77 != V_44 ) {
V_11 = F_48 ( V_61 , V_59 -> V_77 ,
& V_64 ) ;
if ( F_8 ( V_11 != 0 ) ) {
F_15 ( L_8
L_3 ) ;
return V_11 ;
}
if ( ( V_78 ) V_64 -> V_43 . V_79 * V_80 <
( V_78 ) V_59 -> V_6 + ( V_78 ) V_59 -> V_7 ) {
F_15 ( L_9 ) ;
V_11 = - V_81 ;
goto V_82;
}
}
switch ( V_59 -> V_66 ) {
case V_83 :
V_66 = V_84 ;
break;
case V_85 :
V_66 = V_86 ;
break;
case V_87 :
V_66 = V_88 ;
break;
default:
F_15 ( L_10 ) ;
V_11 = - V_81 ;
goto V_82;
}
V_11 = F_49 ( & V_5 -> V_89 , true ) ;
if ( F_8 ( V_11 != 0 ) )
goto V_82;
V_11 = F_40 ( V_5 , V_64 , V_59 -> V_6 , V_59 -> V_7 ,
V_66 , V_61 , & V_59 -> V_90 ) ;
F_50 ( & V_5 -> V_89 ) ;
V_82:
F_51 ( & V_64 ) ;
return V_11 ;
}
int F_52 ( struct V_91 * V_92 ,
T_3 V_66 ,
T_9 * V_93 )
{
struct V_94 * V_74 ;
int V_11 ;
unsigned long V_75 = * V_93 | ( V_66 << 24 ) ;
V_11 = F_53 ( & V_92 -> V_95 , V_75 , & V_74 ) ;
if ( F_8 ( V_11 != 0 ) )
return V_11 ;
* V_93 = F_54 ( V_74 , struct V_96 ,
V_74 ) -> V_62 ;
return 0 ;
}
static void F_55 ( struct V_91 * V_92 ,
struct V_96 * V_97 )
{
F_56 ( & V_97 -> V_98 ) ;
F_57 ( F_58 ( & V_92 -> V_95 , & V_97 -> V_74 ) ) ;
F_57 ( F_39 ( V_97 -> V_61 , V_97 -> V_62 ,
V_63 ) ) ;
F_9 ( V_97 ) ;
}
void F_59 ( struct V_91 * V_92 ,
struct V_99 * V_100 )
{
struct V_96 * V_97 , * V_101 ;
F_60 (entry, next, list, head) {
F_56 ( & V_97 -> V_98 ) ;
switch ( V_97 -> V_102 ) {
case V_103 :
V_97 -> V_102 = V_104 ;
F_61 ( & V_97 -> V_98 , & V_92 -> V_100 ) ;
break;
case V_105 :
F_39 ( V_97 -> V_61 , V_97 -> V_62 ,
V_63 ) ;
F_9 ( V_97 ) ;
break;
default:
F_62 () ;
break;
}
}
}
void F_63 ( struct V_91 * V_92 ,
struct V_99 * V_100 )
{
struct V_96 * V_97 , * V_101 ;
int V_11 ;
F_60 (entry, next, list, head) {
switch ( V_97 -> V_102 ) {
case V_103 :
F_55 ( V_92 , V_97 ) ;
break;
case V_105 :
V_11 = F_64 ( & V_92 -> V_95 , & V_97 -> V_74 ) ;
F_56 ( & V_97 -> V_98 ) ;
F_61 ( & V_97 -> V_98 , & V_92 -> V_100 ) ;
V_97 -> V_102 = V_104 ;
break;
default:
F_62 () ;
break;
}
}
}
int F_65 ( struct V_91 * V_92 ,
T_9 V_93 , T_3 V_66 ,
struct V_99 * V_100 )
{
struct V_96 * V_97 ;
struct V_94 * V_74 ;
int V_11 ;
V_11 = F_53 ( & V_92 -> V_95 , V_93 | ( V_66 << 24 ) ,
& V_74 ) ;
if ( F_13 ( V_11 != 0 ) )
return - V_81 ;
V_97 = F_54 ( V_74 , struct V_96 , V_74 ) ;
switch ( V_97 -> V_102 ) {
case V_103 :
F_55 ( V_92 , V_97 ) ;
break;
case V_104 :
( void ) F_58 ( & V_92 -> V_95 , & V_97 -> V_74 ) ;
F_56 ( & V_97 -> V_98 ) ;
V_97 -> V_102 = V_105 ;
F_61 ( & V_97 -> V_98 , V_100 ) ;
break;
default:
F_62 () ;
break;
}
return 0 ;
}
int F_66 ( struct V_91 * V_92 ,
T_9 V_93 , const void * V_106 ,
T_3 V_66 ,
T_8 V_6 ,
struct V_60 * V_61 ,
struct V_99 * V_100 )
{
struct V_8 * V_107 ;
struct V_108 V_109 ;
bool V_110 ;
struct V_96 * V_111 ;
T_9 V_62 ;
int V_11 ;
if ( V_93 > ( ( 1 << 24 ) - 1 ) || ( unsigned ) V_66 > 16 )
return - V_81 ;
V_107 = F_43 ( sizeof( * V_107 ) , V_70 ) ;
if ( F_8 ( V_107 == NULL ) )
return - V_24 ;
V_11 = F_67 ( V_92 -> V_5 , V_107 , V_6 , & V_112 ,
true , V_113 ) ;
if ( F_8 ( V_11 != 0 ) )
goto V_69;
V_11 = F_68 ( & V_107 -> V_43 , false , true , false , NULL ) ;
if ( F_8 ( V_11 != 0 ) )
goto V_114;
V_11 = F_69 ( & V_107 -> V_43 , 0 , F_70 ( V_6 ) >> V_115 ,
& V_109 ) ;
if ( F_8 ( V_11 != 0 ) ) {
F_71 ( & V_107 -> V_43 ) ;
goto V_114;
}
memcpy ( F_72 ( & V_109 , & V_110 ) , V_106 , V_6 ) ;
F_57 ( V_110 ) ;
F_73 ( & V_109 ) ;
V_11 = F_74 ( & V_107 -> V_43 , & V_116 , false , true ) ;
F_57 ( V_11 != 0 ) ;
F_71 ( & V_107 -> V_43 ) ;
V_11 = F_40 ( V_92 -> V_5 , V_107 , V_6 , 0 , V_66 ,
V_61 , & V_62 ) ;
F_51 ( & V_107 ) ;
if ( F_8 ( V_11 != 0 ) )
goto V_114;
V_111 = F_43 ( sizeof( * V_111 ) , V_70 ) ;
if ( V_111 == NULL )
goto V_117;
V_111 -> V_74 . V_75 = V_93 | ( V_66 << 24 ) ;
V_11 = F_64 ( & V_92 -> V_95 , & V_111 -> V_74 ) ;
if ( F_8 ( V_11 != 0 ) )
goto V_118;
V_111 -> V_102 = V_103 ;
V_111 -> V_62 = V_62 ;
V_111 -> V_61 = V_61 ;
F_61 ( & V_111 -> V_98 , V_100 ) ;
return 0 ;
V_118:
F_9 ( V_111 ) ;
V_117:
F_39 ( V_61 , V_62 , V_63 ) ;
V_114:
V_69:
return V_11 ;
}
struct V_91 *
F_75 ( struct V_4 * V_5 )
{
struct V_91 * V_92 ;
int V_11 ;
V_92 = F_43 ( sizeof( * V_92 ) , V_70 ) ;
if ( V_92 == NULL )
return F_76 ( - V_24 ) ;
V_92 -> V_5 = V_5 ;
F_77 ( & V_92 -> V_100 ) ;
V_11 = F_78 ( & V_92 -> V_95 , V_119 ) ;
if ( V_11 == 0 )
return V_92 ;
F_9 ( V_92 ) ;
return F_76 ( V_11 ) ;
}
void F_79 ( struct V_91 * V_92 )
{
struct V_96 * V_97 , * V_101 ;
F_26 ( & V_92 -> V_5 -> V_120 ) ;
F_60 (entry, next, &man->list, head)
F_55 ( V_92 , V_97 ) ;
F_28 ( & V_92 -> V_5 -> V_120 ) ;
F_9 ( V_92 ) ;
}
