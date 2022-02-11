static inline struct V_1 *
V_1 ( struct V_2 * V_3 )
{
return F_1 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 *
V_5 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = V_1 ( V_3 ) ;
return F_1 ( V_6 , struct V_5 , V_7 ) ;
}
struct V_8 * F_2 ( struct V_8 * V_9 )
{
F_3 ( & V_9 -> V_10 ) ;
return V_9 ;
}
void F_4 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
struct V_13 * V_13 = & V_12 -> V_14 [ V_9 -> V_15 -> V_16 ] ;
F_5 ( & V_12 -> V_17 ) ;
if ( V_9 -> V_18 != - 1 )
F_6 ( V_13 , V_9 -> V_18 ) ;
V_9 -> V_18 = - 1 ;
F_7 ( & V_12 -> V_17 ) ;
}
static void F_8 ( struct V_10 * V_10 )
{
struct V_8 * V_9 =
F_1 ( V_10 , struct V_8 , V_10 ) ;
struct V_11 * V_12 = V_9 -> V_12 ;
int V_18 ;
struct V_13 * V_13 = & V_12 -> V_14 [ V_9 -> V_15 -> V_16 ] ;
V_9 -> V_19 = false ;
F_9 ( & V_9 -> V_20 ) ;
F_7 ( & V_12 -> V_17 ) ;
if ( V_9 -> V_21 ) {
struct V_2 * V_3 = & V_9 -> V_21 -> V_4 ;
F_10 ( V_3 , false , false , false , 0 ) ;
if ( ! F_11 ( & V_9 -> V_22 ) &&
V_9 -> V_15 -> V_23 != NULL ) {
struct V_24 V_25 ;
V_25 . V_3 = V_3 ;
V_9 -> V_15 -> V_23 ( V_9 , false , & V_25 ) ;
}
V_9 -> V_26 = false ;
F_9 ( & V_9 -> V_22 ) ;
F_12 ( V_3 ) ;
F_13 ( & V_9 -> V_21 ) ;
}
if ( F_14 ( V_9 -> V_27 != NULL ) )
V_9 -> V_27 ( V_9 ) ;
V_18 = V_9 -> V_18 ;
if ( V_9 -> V_28 != NULL )
V_9 -> V_28 ( V_9 ) ;
else
F_15 ( V_9 ) ;
F_5 ( & V_12 -> V_17 ) ;
if ( V_18 != - 1 )
F_6 ( V_13 , V_18 ) ;
}
void F_16 ( struct V_8 * * V_29 )
{
struct V_8 * V_9 = * V_29 ;
struct V_11 * V_12 = V_9 -> V_12 ;
* V_29 = NULL ;
F_5 ( & V_12 -> V_17 ) ;
F_17 ( & V_9 -> V_10 , F_8 ) ;
F_7 ( & V_12 -> V_17 ) ;
}
int F_18 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
int V_30 ;
struct V_13 * V_13 = & V_12 -> V_14 [ V_9 -> V_15 -> V_16 ] ;
F_19 ( V_9 -> V_18 != - 1 ) ;
F_20 ( V_31 ) ;
F_5 ( & V_12 -> V_17 ) ;
V_30 = F_21 ( V_13 , V_9 , 1 , 0 , V_32 ) ;
if ( V_30 >= 0 )
V_9 -> V_18 = V_30 ;
F_7 ( & V_12 -> V_17 ) ;
F_22 () ;
return V_30 < 0 ? V_30 : 0 ;
}
int F_23 ( struct V_11 * V_12 , struct V_8 * V_9 ,
bool V_33 ,
void (* V_28) ( struct V_8 * V_9 ) ,
const struct V_34 * V_15 )
{
F_24 ( & V_9 -> V_10 ) ;
V_9 -> V_27 = NULL ;
V_9 -> V_28 = V_28 ;
V_9 -> V_19 = false ;
V_9 -> V_12 = V_12 ;
V_9 -> V_15 = V_15 ;
F_25 ( & V_9 -> V_20 ) ;
F_25 ( & V_9 -> V_22 ) ;
V_9 -> V_18 = - 1 ;
V_9 -> V_21 = NULL ;
V_9 -> V_35 = 0 ;
V_9 -> V_26 = false ;
V_9 -> V_36 = false ;
if ( V_33 )
return 0 ;
else
return F_18 ( V_9 ) ;
}
void F_26 ( struct V_8 * V_9 ,
void (* V_27) ( struct V_8 * ) )
{
struct V_11 * V_12 = V_9 -> V_12 ;
F_5 ( & V_12 -> V_17 ) ;
V_9 -> V_19 = true ;
V_9 -> V_27 = V_27 ;
F_7 ( & V_12 -> V_17 ) ;
}
struct V_8 * F_27 ( struct V_11 * V_12 ,
struct V_13 * V_13 , int V_18 )
{
struct V_8 * V_9 ;
F_28 ( & V_12 -> V_17 ) ;
V_9 = F_29 ( V_13 , V_18 ) ;
if ( V_9 && V_9 -> V_19 )
F_3 ( & V_9 -> V_10 ) ;
else
V_9 = NULL ;
F_30 ( & V_12 -> V_17 ) ;
if ( F_31 ( V_9 == NULL ) )
return NULL ;
return V_9 ;
}
int F_32 ( struct V_11 * V_12 ,
struct V_37 * V_38 ,
T_1 V_39 ,
const struct V_40
* V_41 ,
struct V_8 * * V_29 )
{
struct V_42 * V_4 ;
struct V_8 * V_9 ;
int V_30 = - V_43 ;
V_4 = F_33 ( V_38 , V_39 ) ;
if ( F_31 ( V_4 == NULL ) )
return - V_43 ;
if ( F_31 ( V_4 -> V_44 != V_41 -> V_44 ) )
goto V_45;
V_9 = V_41 -> V_46 ( V_4 ) ;
F_28 ( & V_12 -> V_17 ) ;
if ( ! V_9 -> V_19 || V_9 -> V_28 != V_41 -> V_28 ) {
F_30 ( & V_12 -> V_17 ) ;
goto V_45;
}
F_3 ( & V_9 -> V_10 ) ;
F_30 ( & V_12 -> V_17 ) ;
* V_29 = V_9 ;
V_30 = 0 ;
V_45:
F_34 ( & V_4 ) ;
return V_30 ;
}
int F_35 ( struct V_11 * V_12 ,
struct V_37 * V_38 ,
T_1 V_39 ,
struct V_47 * * V_48 ,
struct V_1 * * V_49 )
{
struct V_8 * V_9 ;
int V_30 ;
F_19 ( * V_48 || * V_49 ) ;
V_30 = F_32 ( V_12 , V_38 , V_39 ,
V_50 ,
& V_9 ) ;
if ( ! V_30 ) {
* V_48 = F_36 ( V_9 ) ;
return 0 ;
}
* V_48 = NULL ;
V_30 = F_37 ( V_38 , V_39 , V_49 ) ;
return V_30 ;
}
void F_38 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = V_1 ( V_3 ) ;
F_15 ( V_6 ) ;
}
int F_39 ( struct V_11 * V_12 ,
struct V_1 * V_6 ,
T_2 V_51 , struct V_52 * V_53 ,
bool V_54 ,
void (* F_40) ( struct V_2 * V_3 ) )
{
struct V_55 * V_56 = & V_12 -> V_56 ;
T_2 V_57 ;
int V_30 ;
F_19 ( ! F_40 ) ;
V_57 = F_41 ( V_56 , V_51 , sizeof( struct V_1 ) ) ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
F_25 ( & V_6 -> V_58 ) ;
V_30 = F_42 ( V_56 , & V_6 -> V_4 , V_51 ,
V_59 , V_53 ,
0 , V_54 ,
NULL , V_57 , NULL , F_40 ) ;
return V_30 ;
}
static void F_43 ( struct V_2 * V_3 )
{
struct V_5 * V_60 = V_5 ( V_3 ) ;
F_44 ( V_60 , V_4 ) ;
}
static void F_45 ( struct V_42 * * V_61 )
{
struct V_5 * V_60 ;
struct V_42 * V_4 = * V_61 ;
struct V_2 * V_3 ;
* V_61 = NULL ;
if ( F_31 ( V_4 == NULL ) )
return;
V_60 = F_1 ( V_4 , struct V_5 , V_4 ) ;
V_3 = & V_60 -> V_7 . V_4 ;
F_46 ( & V_3 ) ;
}
int F_47 ( struct V_11 * V_12 ,
struct V_37 * V_38 ,
T_1 V_51 ,
bool V_62 ,
T_1 * V_39 ,
struct V_1 * * V_63 )
{
struct V_5 * V_64 ;
struct V_2 * V_65 ;
int V_30 ;
V_64 = F_48 ( sizeof( * V_64 ) , V_31 ) ;
if ( F_31 ( V_64 == NULL ) ) {
F_49 ( L_1 ) ;
return - V_66 ;
}
V_30 = F_39 ( V_12 , & V_64 -> V_7 , V_51 ,
& V_67 , true ,
& F_43 ) ;
if ( F_31 ( V_30 != 0 ) )
return V_30 ;
V_65 = F_50 ( & V_64 -> V_7 . V_4 ) ;
V_30 = F_51 ( V_38 ,
& V_64 -> V_4 ,
V_62 ,
V_68 ,
& F_45 , NULL ) ;
if ( F_31 ( V_30 != 0 ) ) {
F_46 ( & V_65 ) ;
goto V_69;
}
* V_63 = & V_64 -> V_7 ;
* V_39 = V_64 -> V_4 . V_70 . V_71 ;
V_69:
return V_30 ;
}
int F_52 ( struct V_2 * V_3 ,
struct V_37 * V_38 )
{
struct V_5 * V_60 ;
if ( F_31 ( V_3 -> V_72 != F_43 ) )
return - V_73 ;
V_60 = V_5 ( V_3 ) ;
return ( V_60 -> V_4 . V_38 == V_38 ||
V_60 -> V_4 . V_62 ) ? 0 : - V_73 ;
}
int F_53 ( struct V_74 * V_75 , void * V_76 ,
struct V_77 * V_78 )
{
struct V_11 * V_12 = F_54 ( V_75 ) ;
union V_79 * V_80 =
(union V_79 * ) V_76 ;
struct V_81 * V_82 = & V_80 -> V_82 ;
struct V_83 * V_84 = & V_80 -> V_84 ;
struct V_1 * V_85 ;
T_1 V_39 ;
struct V_86 * V_87 = V_86 ( V_78 -> V_88 ) ;
int V_30 ;
V_30 = F_55 ( & V_87 -> V_89 , true ) ;
if ( F_31 ( V_30 != 0 ) )
return V_30 ;
V_30 = F_47 ( V_12 , F_56 ( V_78 ) -> V_38 ,
V_82 -> V_51 , false , & V_39 , & V_85 ) ;
if ( F_31 ( V_30 != 0 ) )
goto V_90;
V_84 -> V_39 = V_39 ;
V_84 -> V_91 = V_85 -> V_4 . V_92 ;
V_84 -> V_93 = V_39 ;
V_84 -> V_94 = 0 ;
F_13 ( & V_85 ) ;
V_90:
F_57 ( & V_87 -> V_89 ) ;
return V_30 ;
}
int F_58 ( struct V_74 * V_75 , void * V_76 ,
struct V_77 * V_78 )
{
struct V_95 * V_80 =
(struct V_95 * ) V_76 ;
return F_59 ( F_56 ( V_78 ) -> V_38 ,
V_80 -> V_39 ,
V_96 ) ;
}
int F_37 ( struct V_37 * V_38 ,
T_1 V_39 , struct V_1 * * V_97 )
{
struct V_5 * V_60 ;
struct V_42 * V_4 ;
V_4 = F_33 ( V_38 , V_39 ) ;
if ( F_31 ( V_4 == NULL ) ) {
F_60 ( V_98 L_2 ,
( unsigned long ) V_39 ) ;
return - V_99 ;
}
if ( F_31 ( V_4 -> V_44 != V_68 ) ) {
F_34 ( & V_4 ) ;
F_60 ( V_98 L_2 ,
( unsigned long ) V_39 ) ;
return - V_43 ;
}
V_60 = F_1 ( V_4 , struct V_5 , V_4 ) ;
( void ) F_50 ( & V_60 -> V_7 . V_4 ) ;
F_34 ( & V_4 ) ;
* V_97 = & V_60 -> V_7 ;
return 0 ;
}
int F_61 ( struct V_37 * V_38 ,
struct V_1 * V_85 )
{
struct V_5 * V_64 ;
if ( V_85 -> V_4 . V_72 != F_43 )
return - V_43 ;
V_64 = F_1 ( V_85 , struct V_5 , V_7 ) ;
return F_62 ( V_38 , & V_64 -> V_4 , V_96 , NULL ) ;
}
static void F_63 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
struct V_100 * V_101 ;
int V_30 ;
F_64 ( L_3 , V_102 ) ;
V_101 = F_1 ( V_9 , struct V_100 , V_9 ) ;
V_30 = F_65 ( V_12 , V_101 -> V_103 ) ;
F_66 ( V_30 != 0 ) ;
}
static int F_67 ( struct V_11 * V_12 ,
struct V_100 * V_101 ,
void (* V_28) ( struct V_8 * V_9 ) )
{
struct V_8 * V_9 = & V_101 -> V_9 ;
int V_30 ;
V_30 = F_23 ( V_12 , V_9 , false , V_28 ,
& V_104 ) ;
if ( F_31 ( V_30 != 0 ) ) {
if ( V_28 == NULL )
F_15 ( V_101 ) ;
else
V_28 ( & V_101 -> V_9 ) ;
return V_30 ;
}
V_30 = F_68 ( V_12 , & V_101 -> V_103 ) ;
if ( V_30 ) {
F_16 ( & V_9 ) ;
return V_30 ;
}
F_64 ( L_4 , V_102 ) ;
F_26 ( & V_101 -> V_9 , F_63 ) ;
return 0 ;
}
static void F_69 ( struct V_8 * V_9 )
{
struct V_105 * V_101 =
F_1 ( V_9 , struct V_105 , V_101 . V_9 ) ;
struct V_11 * V_12 = V_9 -> V_12 ;
F_44 ( V_101 , V_4 ) ;
F_70 ( F_71 ( V_12 ) ,
V_106 ) ;
}
static void F_72 ( struct V_42 * * V_61 )
{
struct V_42 * V_4 = * V_61 ;
struct V_105 * V_101 =
F_1 ( V_4 , struct V_105 , V_4 ) ;
struct V_8 * V_9 = & V_101 -> V_101 . V_9 ;
* V_61 = NULL ;
F_16 ( & V_9 ) ;
}
int F_73 ( struct V_74 * V_75 , void * V_76 ,
struct V_77 * V_78 )
{
struct V_11 * V_12 = F_54 ( V_75 ) ;
struct V_8 * V_9 ;
struct V_105 * V_101 ;
struct V_107 * V_80 = (struct V_107 * ) V_76 ;
struct V_37 * V_38 = F_56 ( V_78 ) -> V_38 ;
struct V_13 * V_13 = & V_12 -> V_14 [ V_108 ] ;
int V_30 = 0 ;
V_9 = F_27 ( V_12 , V_13 , V_80 -> V_103 ) ;
if ( F_31 ( V_9 == NULL ) )
return - V_43 ;
if ( V_9 -> V_28 != & F_69 ) {
V_30 = - V_43 ;
goto V_97;
}
V_101 = F_1 ( V_9 , struct V_105 , V_101 . V_9 ) ;
if ( V_101 -> V_4 . V_38 != V_38 ) {
V_30 = - V_43 ;
goto V_97;
}
F_59 ( V_38 , V_101 -> V_4 . V_70 . V_71 , V_96 ) ;
V_97:
F_16 ( & V_9 ) ;
return V_30 ;
}
int F_74 ( struct V_74 * V_75 , void * V_76 ,
struct V_77 * V_78 )
{
struct V_11 * V_12 = F_54 ( V_75 ) ;
struct V_105 * V_101 ;
struct V_8 * V_9 ;
struct V_8 * V_65 ;
struct V_107 * V_80 = (struct V_107 * ) V_76 ;
struct V_37 * V_38 = F_56 ( V_78 ) -> V_38 ;
struct V_86 * V_87 = V_86 ( V_78 -> V_88 ) ;
int V_30 ;
if ( F_31 ( V_106 == 0 ) )
V_106 = F_75 ( sizeof( * V_101 ) ) + 128 ;
V_30 = F_55 ( & V_87 -> V_89 , true ) ;
if ( F_31 ( V_30 != 0 ) )
return V_30 ;
V_30 = F_76 ( F_71 ( V_12 ) ,
V_106 ,
false , true ) ;
if ( F_31 ( V_30 != 0 ) ) {
if ( V_30 != - V_109 )
F_49 ( L_5
L_6 ) ;
goto V_110;
}
V_101 = F_77 ( sizeof( * V_101 ) , V_31 ) ;
if ( F_31 ( V_101 == NULL ) ) {
F_70 ( F_71 ( V_12 ) ,
V_106 ) ;
V_30 = - V_66 ;
goto V_110;
}
V_9 = & V_101 -> V_101 . V_9 ;
V_101 -> V_4 . V_62 = false ;
V_101 -> V_4 . V_38 = NULL ;
V_30 = F_67 ( V_12 , & V_101 -> V_101 , F_69 ) ;
if ( F_31 ( V_30 != 0 ) )
goto V_110;
V_65 = F_2 ( V_9 ) ;
V_30 = F_51 ( V_38 , & V_101 -> V_4 , false , V_111 ,
& F_72 , NULL ) ;
if ( F_31 ( V_30 != 0 ) ) {
F_16 ( & V_65 ) ;
goto V_112;
}
V_80 -> V_103 = V_9 -> V_18 ;
V_112:
F_16 ( & V_9 ) ;
V_110:
F_57 ( & V_87 -> V_89 ) ;
return V_30 ;
}
int F_78 ( struct V_11 * V_12 ,
struct V_37 * V_38 ,
T_1 * V_113 , struct V_8 * * V_97 )
{
struct V_105 * V_101 ;
struct V_8 * V_9 ;
int V_30 ;
V_9 = F_27 ( V_12 , & V_12 -> V_14 [ V_108 ] ,
* V_113 ) ;
if ( F_31 ( V_9 == NULL ) )
return - V_43 ;
if ( V_9 -> V_28 != & F_69 ) {
V_30 = - V_43 ;
goto V_114;
}
V_101 = F_1 ( V_9 , struct V_105 , V_101 . V_9 ) ;
if ( V_101 -> V_4 . V_38 != V_38 ) {
V_30 = - V_73 ;
goto V_114;
}
* V_113 = V_101 -> V_101 . V_103 ;
* V_97 = V_9 ;
return 0 ;
V_114:
F_16 ( & V_9 ) ;
return V_30 ;
}
int F_79 ( struct V_77 * V_78 ,
struct V_74 * V_75 ,
struct V_115 * args )
{
struct V_11 * V_12 = F_54 ( V_75 ) ;
struct V_86 * V_87 = V_86 ( V_78 -> V_88 ) ;
struct V_5 * V_60 ;
struct V_2 * V_65 ;
int V_30 ;
args -> V_116 = args -> V_117 * ( ( args -> V_118 + 7 ) / 8 ) ;
args -> V_51 = args -> V_116 * args -> V_119 ;
V_60 = F_48 ( sizeof( * V_60 ) , V_31 ) ;
if ( V_60 == NULL )
return - V_66 ;
V_30 = F_55 ( & V_87 -> V_89 , true ) ;
if ( V_30 != 0 ) {
F_15 ( V_60 ) ;
return V_30 ;
}
V_30 = F_39 ( V_12 , & V_60 -> V_7 , args -> V_51 ,
& V_67 , true ,
& F_43 ) ;
if ( V_30 != 0 )
goto V_90;
V_65 = F_50 ( & V_60 -> V_7 . V_4 ) ;
V_30 = F_51 ( F_56 ( V_78 ) -> V_38 ,
& V_60 -> V_4 ,
false ,
V_68 ,
& F_45 , NULL ) ;
if ( F_31 ( V_30 != 0 ) )
goto V_69;
args -> V_39 = V_60 -> V_4 . V_70 . V_71 ;
V_69:
F_46 ( & V_65 ) ;
V_90:
F_57 ( & V_87 -> V_89 ) ;
return V_30 ;
}
int F_80 ( struct V_77 * V_78 ,
struct V_74 * V_75 , T_1 V_39 ,
T_3 * V_120 )
{
struct V_37 * V_38 = F_56 ( V_78 ) -> V_38 ;
struct V_1 * V_49 ;
int V_30 ;
V_30 = F_37 ( V_38 , V_39 , & V_49 ) ;
if ( V_30 != 0 )
return - V_43 ;
* V_120 = V_49 -> V_4 . V_92 ;
F_13 ( & V_49 ) ;
return 0 ;
}
int F_81 ( struct V_77 * V_78 ,
struct V_74 * V_75 ,
T_1 V_39 )
{
return F_59 ( F_56 ( V_78 ) -> V_38 ,
V_39 , V_96 ) ;
}
static int F_82 ( struct V_8 * V_9 ,
bool V_54 )
{
unsigned long V_51 =
( V_9 -> V_121 + V_122 - 1 ) & V_123 ;
struct V_1 * V_21 ;
int V_30 ;
if ( F_14 ( V_9 -> V_21 ) ) {
F_19 ( V_9 -> V_21 -> V_4 . V_124 * V_122 < V_51 ) ;
return 0 ;
}
V_21 = F_48 ( sizeof( * V_21 ) , V_31 ) ;
if ( F_31 ( V_21 == NULL ) )
return - V_66 ;
V_30 = F_39 ( V_9 -> V_12 , V_21 , V_9 -> V_121 ,
V_9 -> V_15 -> V_125 ,
V_54 ,
& F_38 ) ;
if ( F_31 ( V_30 != 0 ) )
goto V_90;
V_9 -> V_21 = V_21 ;
V_90:
return V_30 ;
}
static int F_83 ( struct V_8 * V_9 ,
struct V_24 * V_25 )
{
int V_30 = 0 ;
const struct V_34 * V_15 = V_9 -> V_15 ;
if ( F_31 ( V_9 -> V_18 == - 1 ) ) {
V_30 = V_15 -> V_126 ( V_9 ) ;
if ( F_31 ( V_30 != 0 ) )
return V_30 ;
}
if ( V_15 -> V_127 &&
( ( V_15 -> V_128 && F_11 ( & V_9 -> V_22 ) &&
V_25 -> V_3 != NULL ) ||
( ! V_15 -> V_128 && V_25 -> V_3 != NULL ) ) ) {
V_30 = V_15 -> V_127 ( V_9 , V_25 ) ;
if ( F_31 ( V_30 != 0 ) )
goto V_129;
if ( V_15 -> V_128 )
F_84 ( & V_9 -> V_22 , & V_9 -> V_21 -> V_58 ) ;
}
V_9 -> V_36 = true ;
return 0 ;
V_129:
V_15 -> V_72 ( V_9 ) ;
return V_30 ;
}
void F_85 ( struct V_8 * V_9 ,
struct V_1 * V_130 ,
unsigned long V_131 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
if ( ! F_11 ( & V_9 -> V_20 ) )
return;
if ( V_130 && V_130 != V_9 -> V_21 ) {
if ( V_9 -> V_21 ) {
F_19 ( ! F_86 ( & V_9 -> V_21 -> V_4 ) ) ;
F_9 ( & V_9 -> V_22 ) ;
F_13 ( & V_9 -> V_21 ) ;
}
V_9 -> V_21 = F_87 ( V_130 ) ;
F_19 ( ! F_86 ( & V_130 -> V_4 ) ) ;
F_84 ( & V_9 -> V_22 , & V_130 -> V_58 ) ;
}
if ( V_130 )
V_9 -> V_35 = V_131 ;
if ( ! V_9 -> V_15 -> V_132 )
return;
F_5 ( & V_12 -> V_17 ) ;
F_84 ( & V_9 -> V_20 ,
& V_9 -> V_12 -> V_133 [ V_9 -> V_15 -> V_16 ] ) ;
F_7 ( & V_12 -> V_17 ) ;
}
int F_88 ( struct V_8 * V_9 ,
bool V_54 ,
struct V_24 * V_25 )
{
struct V_134 V_135 ;
bool V_26 = false ;
int V_30 ;
if ( F_31 ( V_9 -> V_21 == NULL ) ) {
V_30 = F_82 ( V_9 , V_54 ) ;
if ( F_31 ( V_30 != 0 ) )
return V_30 ;
}
F_25 ( & V_135 ) ;
V_25 -> V_3 = F_50 ( & V_9 -> V_21 -> V_4 ) ;
F_84 ( & V_25 -> V_136 , & V_135 ) ;
V_30 = F_89 ( & V_135 ) ;
if ( F_31 ( V_30 != 0 ) )
goto V_137;
if ( V_9 -> V_15 -> V_128 && F_11 ( & V_9 -> V_22 ) )
return 0 ;
V_26 = V_9 -> V_26 ;
V_30 = F_90 ( & V_9 -> V_21 -> V_4 ,
V_9 -> V_15 -> V_125 ,
true , false ) ;
if ( F_31 ( V_30 != 0 ) )
goto V_138;
return 0 ;
V_138:
F_91 ( & V_135 ) ;
V_137:
F_46 ( & V_25 -> V_3 ) ;
if ( V_26 )
F_13 ( & V_9 -> V_21 ) ;
return V_30 ;
}
int F_92 ( struct V_8 * V_9 , bool V_139 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
int V_30 ;
F_5 ( & V_12 -> V_17 ) ;
F_9 ( & V_9 -> V_20 ) ;
F_7 ( & V_12 -> V_17 ) ;
if ( V_9 -> V_15 -> V_128 && V_9 -> V_21 == NULL &&
! V_139 ) {
V_30 = F_82 ( V_9 , true ) ;
if ( F_31 ( V_30 != 0 ) )
return V_30 ;
}
return 0 ;
}
void F_93 ( struct V_24 * V_25 )
{
struct V_134 V_135 ;
if ( F_14 ( V_25 -> V_3 == NULL ) )
return;
F_25 ( & V_135 ) ;
F_84 ( & V_25 -> V_136 , & V_135 ) ;
F_91 ( & V_135 ) ;
F_46 ( & V_25 -> V_3 ) ;
}
int F_94 ( struct V_8 * V_9 )
{
struct V_24 V_25 ;
const struct V_34 * V_15 = V_9 -> V_15 ;
int V_30 ;
F_19 ( ! V_15 -> V_132 ) ;
V_25 . V_3 = NULL ;
V_30 = F_88 ( V_9 , true , & V_25 ) ;
if ( F_31 ( V_30 != 0 ) )
return V_30 ;
if ( F_31 ( V_15 -> V_23 != NULL &&
( ! V_15 -> V_128 || ! F_11 ( & V_9 -> V_22 ) ) ) ) {
V_30 = V_15 -> V_23 ( V_9 , V_9 -> V_36 , & V_25 ) ;
if ( F_31 ( V_30 != 0 ) )
goto V_140;
F_9 ( & V_9 -> V_22 ) ;
}
V_30 = V_15 -> V_72 ( V_9 ) ;
V_9 -> V_26 = true ;
V_9 -> V_36 = false ;
V_140:
F_93 ( & V_25 ) ;
return V_30 ;
}
int F_95 ( struct V_8 * V_9 )
{
int V_30 ;
struct V_8 * V_141 ;
struct V_11 * V_12 = V_9 -> V_12 ;
struct V_134 * V_142 = & V_12 -> V_133 [ V_9 -> V_15 -> V_16 ] ;
struct V_24 V_25 ;
if ( F_14 ( ! V_9 -> V_15 -> V_132 ) )
return 0 ;
V_25 . V_3 = NULL ;
if ( V_9 -> V_21 )
V_25 . V_3 = & V_9 -> V_21 -> V_4 ;
do {
V_30 = F_83 ( V_9 , & V_25 ) ;
if ( F_14 ( V_30 != - V_143 ) )
break;
F_5 ( & V_12 -> V_17 ) ;
if ( F_11 ( V_142 ) || ! V_9 -> V_15 -> V_132 ) {
F_49 ( L_7
L_8 , V_9 -> V_15 -> V_144 ) ;
V_30 = - V_143 ;
F_7 ( & V_12 -> V_17 ) ;
break;
}
V_141 = F_2
( F_96 ( V_142 , struct V_8 ,
V_20 ) ) ;
F_9 ( & V_141 -> V_20 ) ;
F_7 ( & V_12 -> V_17 ) ;
F_94 ( V_141 ) ;
F_16 ( & V_141 ) ;
} while ( 1 );
if ( F_31 ( V_30 != 0 ) )
goto V_138;
else if ( ! V_9 -> V_15 -> V_128 && V_9 -> V_21 ) {
F_9 ( & V_9 -> V_22 ) ;
F_13 ( & V_9 -> V_21 ) ;
}
return 0 ;
V_138:
return V_30 ;
}
void F_97 ( struct V_2 * V_3 ,
struct V_145 * V_146 )
{
struct V_55 * V_56 = V_3 -> V_56 ;
struct V_147 * V_148 = V_56 -> V_148 ;
struct V_145 * V_149 ;
struct V_11 * V_12 =
F_1 ( V_56 , struct V_11 , V_56 ) ;
if ( V_146 == NULL )
F_98 ( NULL , V_12 , & V_146 , NULL ) ;
else
V_148 -> V_150 ( V_146 ) ;
F_99 ( & V_56 -> V_151 ) ;
V_149 = V_3 -> V_152 ;
V_3 -> V_152 = V_146 ;
F_100 ( & V_56 -> V_151 ) ;
if ( V_149 )
F_101 ( & V_149 ) ;
}
void F_102 ( struct V_2 * V_3 ,
struct V_153 * V_154 )
{
}
bool F_103 ( const struct V_8 * V_9 )
{
return V_9 -> V_15 -> V_128 ;
}
static void F_104 ( struct V_11 * V_12 ,
enum V_155 type )
{
struct V_134 * V_142 = & V_12 -> V_133 [ type ] ;
struct V_8 * V_141 ;
do {
F_5 ( & V_12 -> V_17 ) ;
if ( F_11 ( V_142 ) )
goto V_110;
V_141 = F_2 (
F_96 ( V_142 , struct V_8 ,
V_20 ) ) ;
F_9 ( & V_141 -> V_20 ) ;
F_7 ( & V_12 -> V_17 ) ;
F_94 ( V_141 ) ;
F_16 ( & V_141 ) ;
} while ( 1 );
V_110:
F_7 ( & V_12 -> V_17 ) ;
}
void F_105 ( struct V_11 * V_12 )
{
enum V_155 type ;
F_106 ( & V_12 -> V_156 ) ;
for ( type = 0 ; type < V_157 ; ++ type )
F_104 ( V_12 , type ) ;
F_107 ( & V_12 -> V_156 ) ;
}
