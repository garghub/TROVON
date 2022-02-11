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
do {
if ( F_20 ( F_21 ( V_13 , V_31 ) == 0 ) )
return - V_32 ;
F_5 ( & V_12 -> V_17 ) ;
V_30 = F_22 ( V_13 , V_9 , 1 , & V_9 -> V_18 ) ;
F_7 ( & V_12 -> V_17 ) ;
} while ( V_30 == - V_33 );
return V_30 ;
}
int F_23 ( struct V_11 * V_12 , struct V_8 * V_9 ,
bool V_34 ,
void (* V_28) ( struct V_8 * V_9 ) ,
const struct V_35 * V_15 )
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
V_9 -> V_36 = 0 ;
V_9 -> V_26 = false ;
V_9 -> V_37 = false ;
if ( V_34 )
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
if ( F_20 ( V_9 == NULL ) )
return NULL ;
return V_9 ;
}
int F_31 ( struct V_11 * V_12 ,
struct V_38 * V_39 ,
T_1 V_40 ,
const struct V_41
* V_42 ,
struct V_8 * * V_29 )
{
struct V_43 * V_4 ;
struct V_8 * V_9 ;
int V_30 = - V_44 ;
V_4 = F_32 ( V_39 , V_40 ) ;
if ( F_20 ( V_4 == NULL ) )
return - V_44 ;
if ( F_20 ( V_4 -> V_45 != V_42 -> V_45 ) )
goto V_46;
V_9 = V_42 -> V_47 ( V_4 ) ;
F_28 ( & V_12 -> V_17 ) ;
if ( ! V_9 -> V_19 || V_9 -> V_28 != V_42 -> V_28 ) {
F_30 ( & V_12 -> V_17 ) ;
goto V_46;
}
F_3 ( & V_9 -> V_10 ) ;
F_30 ( & V_12 -> V_17 ) ;
* V_29 = V_9 ;
V_30 = 0 ;
V_46:
F_33 ( & V_4 ) ;
return V_30 ;
}
int F_34 ( struct V_11 * V_12 ,
struct V_38 * V_39 ,
T_1 V_40 ,
struct V_48 * * V_49 ,
struct V_1 * * V_50 )
{
struct V_8 * V_9 ;
int V_30 ;
F_19 ( * V_49 || * V_50 ) ;
V_30 = F_31 ( V_12 , V_39 , V_40 ,
V_51 ,
& V_9 ) ;
if ( ! V_30 ) {
* V_49 = F_35 ( V_9 ) ;
return 0 ;
}
* V_49 = NULL ;
V_30 = F_36 ( V_39 , V_40 , V_50 ) ;
return V_30 ;
}
void F_37 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = V_1 ( V_3 ) ;
F_15 ( V_6 ) ;
}
int F_38 ( struct V_11 * V_12 ,
struct V_1 * V_6 ,
T_2 V_52 , struct V_53 * V_54 ,
bool V_55 ,
void (* F_39) ( struct V_2 * V_3 ) )
{
struct V_56 * V_57 = & V_12 -> V_57 ;
T_2 V_58 ;
int V_30 ;
F_19 ( ! F_39 ) ;
V_58 = F_40 ( V_57 , V_52 , sizeof( struct V_1 ) ) ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
F_25 ( & V_6 -> V_59 ) ;
V_30 = F_41 ( V_57 , & V_6 -> V_4 , V_52 ,
V_60 , V_54 ,
0 , V_55 ,
NULL , V_58 , NULL , F_39 ) ;
return V_30 ;
}
static void F_42 ( struct V_2 * V_3 )
{
struct V_5 * V_61 = V_5 ( V_3 ) ;
F_43 ( V_61 , V_4 ) ;
}
static void F_44 ( struct V_43 * * V_62 )
{
struct V_5 * V_61 ;
struct V_43 * V_4 = * V_62 ;
struct V_2 * V_3 ;
* V_62 = NULL ;
if ( F_20 ( V_4 == NULL ) )
return;
V_61 = F_1 ( V_4 , struct V_5 , V_4 ) ;
V_3 = & V_61 -> V_7 . V_4 ;
F_45 ( & V_3 ) ;
}
int F_46 ( struct V_11 * V_12 ,
struct V_38 * V_39 ,
T_1 V_52 ,
bool V_63 ,
T_1 * V_40 ,
struct V_1 * * V_64 )
{
struct V_5 * V_65 ;
struct V_2 * V_66 ;
int V_30 ;
V_65 = F_47 ( sizeof( * V_65 ) , V_31 ) ;
if ( F_20 ( V_65 == NULL ) ) {
F_48 ( L_1 ) ;
return - V_32 ;
}
V_30 = F_38 ( V_12 , & V_65 -> V_7 , V_52 ,
& V_67 , true ,
& F_42 ) ;
if ( F_20 ( V_30 != 0 ) )
return V_30 ;
V_66 = F_49 ( & V_65 -> V_7 . V_4 ) ;
V_30 = F_50 ( V_39 ,
& V_65 -> V_4 ,
V_63 ,
V_68 ,
& F_44 , NULL ) ;
if ( F_20 ( V_30 != 0 ) ) {
F_45 ( & V_66 ) ;
goto V_69;
}
* V_64 = & V_65 -> V_7 ;
* V_40 = V_65 -> V_4 . V_70 . V_71 ;
V_69:
return V_30 ;
}
int F_51 ( struct V_2 * V_3 ,
struct V_38 * V_39 )
{
struct V_5 * V_61 ;
if ( F_20 ( V_3 -> V_72 != F_42 ) )
return - V_73 ;
V_61 = V_5 ( V_3 ) ;
return ( V_61 -> V_4 . V_39 == V_39 ||
V_61 -> V_4 . V_63 ) ? 0 : - V_73 ;
}
int F_52 ( struct V_74 * V_75 , void * V_76 ,
struct V_77 * V_78 )
{
struct V_11 * V_12 = F_53 ( V_75 ) ;
union V_79 * V_80 =
(union V_79 * ) V_76 ;
struct V_81 * V_82 = & V_80 -> V_82 ;
struct V_83 * V_84 = & V_80 -> V_84 ;
struct V_1 * V_85 ;
T_1 V_40 ;
struct V_86 * V_87 = V_86 ( V_78 -> V_88 ) ;
int V_30 ;
V_30 = F_54 ( & V_87 -> V_89 , true ) ;
if ( F_20 ( V_30 != 0 ) )
return V_30 ;
V_30 = F_46 ( V_12 , F_55 ( V_78 ) -> V_39 ,
V_82 -> V_52 , false , & V_40 , & V_85 ) ;
if ( F_20 ( V_30 != 0 ) )
goto V_90;
V_84 -> V_40 = V_40 ;
V_84 -> V_91 = V_85 -> V_4 . V_92 ;
V_84 -> V_93 = V_40 ;
V_84 -> V_94 = 0 ;
F_13 ( & V_85 ) ;
V_90:
F_56 ( & V_87 -> V_89 ) ;
return V_30 ;
}
int F_57 ( struct V_74 * V_75 , void * V_76 ,
struct V_77 * V_78 )
{
struct V_95 * V_80 =
(struct V_95 * ) V_76 ;
return F_58 ( F_55 ( V_78 ) -> V_39 ,
V_80 -> V_40 ,
V_96 ) ;
}
int F_36 ( struct V_38 * V_39 ,
T_1 V_40 , struct V_1 * * V_97 )
{
struct V_5 * V_61 ;
struct V_43 * V_4 ;
V_4 = F_32 ( V_39 , V_40 ) ;
if ( F_20 ( V_4 == NULL ) ) {
F_59 ( V_98 L_2 ,
( unsigned long ) V_40 ) ;
return - V_99 ;
}
if ( F_20 ( V_4 -> V_45 != V_68 ) ) {
F_33 ( & V_4 ) ;
F_59 ( V_98 L_2 ,
( unsigned long ) V_40 ) ;
return - V_44 ;
}
V_61 = F_1 ( V_4 , struct V_5 , V_4 ) ;
( void ) F_49 ( & V_61 -> V_7 . V_4 ) ;
F_33 ( & V_4 ) ;
* V_97 = & V_61 -> V_7 ;
return 0 ;
}
int F_60 ( struct V_38 * V_39 ,
struct V_1 * V_85 )
{
struct V_5 * V_65 ;
if ( V_85 -> V_4 . V_72 != F_42 )
return - V_44 ;
V_65 = F_1 ( V_85 , struct V_5 , V_7 ) ;
return F_61 ( V_39 , & V_65 -> V_4 , V_96 , NULL ) ;
}
static void F_62 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
struct V_100 * V_101 ;
int V_30 ;
F_63 ( L_3 , V_102 ) ;
V_101 = F_1 ( V_9 , struct V_100 , V_9 ) ;
V_30 = F_64 ( V_12 , V_101 -> V_103 ) ;
F_65 ( V_30 != 0 ) ;
}
static int F_66 ( struct V_11 * V_12 ,
struct V_100 * V_101 ,
void (* V_28) ( struct V_8 * V_9 ) )
{
struct V_8 * V_9 = & V_101 -> V_9 ;
int V_30 ;
V_30 = F_23 ( V_12 , V_9 , false , V_28 ,
& V_104 ) ;
if ( F_20 ( V_30 != 0 ) ) {
if ( V_28 == NULL )
F_15 ( V_101 ) ;
else
V_28 ( & V_101 -> V_9 ) ;
return V_30 ;
}
V_30 = F_67 ( V_12 , & V_101 -> V_103 ) ;
if ( V_30 ) {
F_16 ( & V_9 ) ;
return V_30 ;
}
F_63 ( L_4 , V_102 ) ;
F_26 ( & V_101 -> V_9 , F_62 ) ;
return 0 ;
}
static void F_68 ( struct V_8 * V_9 )
{
struct V_105 * V_101 =
F_1 ( V_9 , struct V_105 , V_101 . V_9 ) ;
struct V_11 * V_12 = V_9 -> V_12 ;
F_43 ( V_101 , V_4 ) ;
F_69 ( F_70 ( V_12 ) ,
V_106 ) ;
}
static void F_71 ( struct V_43 * * V_62 )
{
struct V_43 * V_4 = * V_62 ;
struct V_105 * V_101 =
F_1 ( V_4 , struct V_105 , V_4 ) ;
struct V_8 * V_9 = & V_101 -> V_101 . V_9 ;
* V_62 = NULL ;
F_16 ( & V_9 ) ;
}
int F_72 ( struct V_74 * V_75 , void * V_76 ,
struct V_77 * V_78 )
{
struct V_11 * V_12 = F_53 ( V_75 ) ;
struct V_8 * V_9 ;
struct V_105 * V_101 ;
struct V_107 * V_80 = (struct V_107 * ) V_76 ;
struct V_38 * V_39 = F_55 ( V_78 ) -> V_39 ;
struct V_13 * V_13 = & V_12 -> V_14 [ V_108 ] ;
int V_30 = 0 ;
V_9 = F_27 ( V_12 , V_13 , V_80 -> V_103 ) ;
if ( F_20 ( V_9 == NULL ) )
return - V_44 ;
if ( V_9 -> V_28 != & F_68 ) {
V_30 = - V_44 ;
goto V_97;
}
V_101 = F_1 ( V_9 , struct V_105 , V_101 . V_9 ) ;
if ( V_101 -> V_4 . V_39 != V_39 ) {
V_30 = - V_44 ;
goto V_97;
}
F_58 ( V_39 , V_101 -> V_4 . V_70 . V_71 , V_96 ) ;
V_97:
F_16 ( & V_9 ) ;
return V_30 ;
}
int F_73 ( struct V_74 * V_75 , void * V_76 ,
struct V_77 * V_78 )
{
struct V_11 * V_12 = F_53 ( V_75 ) ;
struct V_105 * V_101 ;
struct V_8 * V_9 ;
struct V_8 * V_66 ;
struct V_107 * V_80 = (struct V_107 * ) V_76 ;
struct V_38 * V_39 = F_55 ( V_78 ) -> V_39 ;
struct V_86 * V_87 = V_86 ( V_78 -> V_88 ) ;
int V_30 ;
if ( F_20 ( V_106 == 0 ) )
V_106 = F_74 ( sizeof( * V_101 ) ) + 128 ;
V_30 = F_54 ( & V_87 -> V_89 , true ) ;
if ( F_20 ( V_30 != 0 ) )
return V_30 ;
V_30 = F_75 ( F_70 ( V_12 ) ,
V_106 ,
false , true ) ;
if ( F_20 ( V_30 != 0 ) ) {
if ( V_30 != - V_109 )
F_48 ( L_5
L_6 ) ;
goto V_110;
}
V_101 = F_76 ( sizeof( * V_101 ) , V_31 ) ;
if ( F_20 ( V_101 == NULL ) ) {
F_69 ( F_70 ( V_12 ) ,
V_106 ) ;
V_30 = - V_32 ;
goto V_110;
}
V_9 = & V_101 -> V_101 . V_9 ;
V_101 -> V_4 . V_63 = false ;
V_101 -> V_4 . V_39 = NULL ;
V_30 = F_66 ( V_12 , & V_101 -> V_101 , F_68 ) ;
if ( F_20 ( V_30 != 0 ) )
goto V_110;
V_66 = F_2 ( V_9 ) ;
V_30 = F_50 ( V_39 , & V_101 -> V_4 , false , V_111 ,
& F_71 , NULL ) ;
if ( F_20 ( V_30 != 0 ) ) {
F_16 ( & V_66 ) ;
goto V_112;
}
V_80 -> V_103 = V_9 -> V_18 ;
V_112:
F_16 ( & V_9 ) ;
V_110:
F_56 ( & V_87 -> V_89 ) ;
return V_30 ;
}
int F_77 ( struct V_11 * V_12 ,
struct V_38 * V_39 ,
T_1 * V_113 , struct V_8 * * V_97 )
{
struct V_105 * V_101 ;
struct V_8 * V_9 ;
int V_30 ;
V_9 = F_27 ( V_12 , & V_12 -> V_14 [ V_108 ] ,
* V_113 ) ;
if ( F_20 ( V_9 == NULL ) )
return - V_44 ;
if ( V_9 -> V_28 != & F_68 ) {
V_30 = - V_44 ;
goto V_114;
}
V_101 = F_1 ( V_9 , struct V_105 , V_101 . V_9 ) ;
if ( V_101 -> V_4 . V_39 != V_39 ) {
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
int F_78 ( struct V_77 * V_78 ,
struct V_74 * V_75 ,
struct V_115 * args )
{
struct V_11 * V_12 = F_53 ( V_75 ) ;
struct V_86 * V_87 = V_86 ( V_78 -> V_88 ) ;
struct V_5 * V_61 ;
struct V_2 * V_66 ;
int V_30 ;
args -> V_116 = args -> V_117 * ( ( args -> V_118 + 7 ) / 8 ) ;
args -> V_52 = args -> V_116 * args -> V_119 ;
V_61 = F_47 ( sizeof( * V_61 ) , V_31 ) ;
if ( V_61 == NULL )
return - V_32 ;
V_30 = F_54 ( & V_87 -> V_89 , true ) ;
if ( V_30 != 0 ) {
F_15 ( V_61 ) ;
return V_30 ;
}
V_30 = F_38 ( V_12 , & V_61 -> V_7 , args -> V_52 ,
& V_67 , true ,
& F_42 ) ;
if ( V_30 != 0 )
goto V_90;
V_66 = F_49 ( & V_61 -> V_7 . V_4 ) ;
V_30 = F_50 ( F_55 ( V_78 ) -> V_39 ,
& V_61 -> V_4 ,
false ,
V_68 ,
& F_44 , NULL ) ;
if ( F_20 ( V_30 != 0 ) )
goto V_69;
args -> V_40 = V_61 -> V_4 . V_70 . V_71 ;
V_69:
F_45 ( & V_66 ) ;
V_90:
F_56 ( & V_87 -> V_89 ) ;
return V_30 ;
}
int F_79 ( struct V_77 * V_78 ,
struct V_74 * V_75 , T_1 V_40 ,
T_3 * V_120 )
{
struct V_38 * V_39 = F_55 ( V_78 ) -> V_39 ;
struct V_1 * V_50 ;
int V_30 ;
V_30 = F_36 ( V_39 , V_40 , & V_50 ) ;
if ( V_30 != 0 )
return - V_44 ;
* V_120 = V_50 -> V_4 . V_92 ;
F_13 ( & V_50 ) ;
return 0 ;
}
int F_80 ( struct V_77 * V_78 ,
struct V_74 * V_75 ,
T_1 V_40 )
{
return F_58 ( F_55 ( V_78 ) -> V_39 ,
V_40 , V_96 ) ;
}
static int F_81 ( struct V_8 * V_9 ,
bool V_55 )
{
unsigned long V_52 =
( V_9 -> V_121 + V_122 - 1 ) & V_123 ;
struct V_1 * V_21 ;
int V_30 ;
if ( F_14 ( V_9 -> V_21 ) ) {
F_19 ( V_9 -> V_21 -> V_4 . V_124 * V_122 < V_52 ) ;
return 0 ;
}
V_21 = F_47 ( sizeof( * V_21 ) , V_31 ) ;
if ( F_20 ( V_21 == NULL ) )
return - V_32 ;
V_30 = F_38 ( V_9 -> V_12 , V_21 , V_9 -> V_121 ,
V_9 -> V_15 -> V_125 ,
V_55 ,
& F_37 ) ;
if ( F_20 ( V_30 != 0 ) )
goto V_90;
V_9 -> V_21 = V_21 ;
V_90:
return V_30 ;
}
static int F_82 ( struct V_8 * V_9 ,
struct V_24 * V_25 )
{
int V_30 = 0 ;
const struct V_35 * V_15 = V_9 -> V_15 ;
if ( F_20 ( V_9 -> V_18 == - 1 ) ) {
V_30 = V_15 -> V_126 ( V_9 ) ;
if ( F_20 ( V_30 != 0 ) )
return V_30 ;
}
if ( V_15 -> V_127 &&
( ( V_15 -> V_128 && F_11 ( & V_9 -> V_22 ) &&
V_25 -> V_3 != NULL ) ||
( ! V_15 -> V_128 && V_25 -> V_3 != NULL ) ) ) {
V_30 = V_15 -> V_127 ( V_9 , V_25 ) ;
if ( F_20 ( V_30 != 0 ) )
goto V_129;
if ( V_15 -> V_128 )
F_83 ( & V_9 -> V_22 , & V_9 -> V_21 -> V_59 ) ;
}
V_9 -> V_37 = true ;
return 0 ;
V_129:
V_15 -> V_72 ( V_9 ) ;
return V_30 ;
}
void F_84 ( struct V_8 * V_9 ,
struct V_1 * V_130 ,
unsigned long V_131 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
if ( ! F_11 ( & V_9 -> V_20 ) )
return;
if ( V_130 && V_130 != V_9 -> V_21 ) {
if ( V_9 -> V_21 ) {
F_19 ( F_85 ( & V_9 -> V_21 -> V_4 . V_132 ) == 0 ) ;
F_9 ( & V_9 -> V_22 ) ;
F_13 ( & V_9 -> V_21 ) ;
}
V_9 -> V_21 = F_86 ( V_130 ) ;
F_19 ( F_85 ( & V_130 -> V_4 . V_132 ) == 0 ) ;
F_83 ( & V_9 -> V_22 , & V_130 -> V_59 ) ;
}
if ( V_130 )
V_9 -> V_36 = V_131 ;
if ( ! V_9 -> V_15 -> V_133 )
return;
F_5 ( & V_12 -> V_17 ) ;
F_83 ( & V_9 -> V_20 ,
& V_9 -> V_12 -> V_134 [ V_9 -> V_15 -> V_16 ] ) ;
F_7 ( & V_12 -> V_17 ) ;
}
int F_87 ( struct V_8 * V_9 ,
bool V_55 ,
struct V_24 * V_25 )
{
struct V_135 V_136 ;
bool V_26 = false ;
int V_30 ;
if ( F_20 ( V_9 -> V_21 == NULL ) ) {
V_30 = F_81 ( V_9 , V_55 ) ;
if ( F_20 ( V_30 != 0 ) )
return V_30 ;
}
F_25 ( & V_136 ) ;
V_25 -> V_3 = F_49 ( & V_9 -> V_21 -> V_4 ) ;
F_83 ( & V_25 -> V_137 , & V_136 ) ;
V_30 = F_88 ( & V_136 ) ;
if ( F_20 ( V_30 != 0 ) )
goto V_138;
if ( V_9 -> V_15 -> V_128 && F_11 ( & V_9 -> V_22 ) )
return 0 ;
V_26 = V_9 -> V_26 ;
V_30 = F_89 ( & V_9 -> V_21 -> V_4 ,
V_9 -> V_15 -> V_125 ,
true , false ) ;
if ( F_20 ( V_30 != 0 ) )
goto V_139;
return 0 ;
V_139:
F_90 ( & V_136 ) ;
V_138:
F_45 ( & V_25 -> V_3 ) ;
if ( V_26 )
F_13 ( & V_9 -> V_21 ) ;
return V_30 ;
}
int F_91 ( struct V_8 * V_9 , bool V_140 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
int V_30 ;
F_5 ( & V_12 -> V_17 ) ;
F_9 ( & V_9 -> V_20 ) ;
F_7 ( & V_12 -> V_17 ) ;
if ( V_9 -> V_15 -> V_128 && V_9 -> V_21 == NULL &&
! V_140 ) {
V_30 = F_81 ( V_9 , true ) ;
if ( F_20 ( V_30 != 0 ) )
return V_30 ;
}
return 0 ;
}
void F_92 ( struct V_24 * V_25 )
{
struct V_135 V_136 ;
if ( F_14 ( V_25 -> V_3 == NULL ) )
return;
F_25 ( & V_136 ) ;
F_83 ( & V_25 -> V_137 , & V_136 ) ;
F_90 ( & V_136 ) ;
F_45 ( & V_25 -> V_3 ) ;
}
int F_93 ( struct V_8 * V_9 )
{
struct V_24 V_25 ;
const struct V_35 * V_15 = V_9 -> V_15 ;
int V_30 ;
F_19 ( ! V_15 -> V_133 ) ;
V_25 . V_3 = NULL ;
V_30 = F_87 ( V_9 , true , & V_25 ) ;
if ( F_20 ( V_30 != 0 ) )
return V_30 ;
if ( F_20 ( V_15 -> V_23 != NULL &&
( ! V_15 -> V_128 || ! F_11 ( & V_9 -> V_22 ) ) ) ) {
V_30 = V_15 -> V_23 ( V_9 , V_9 -> V_37 , & V_25 ) ;
if ( F_20 ( V_30 != 0 ) )
goto V_141;
F_9 ( & V_9 -> V_22 ) ;
}
V_30 = V_15 -> V_72 ( V_9 ) ;
V_9 -> V_26 = true ;
V_9 -> V_37 = false ;
V_141:
F_92 ( & V_25 ) ;
return V_30 ;
}
int F_94 ( struct V_8 * V_9 )
{
int V_30 ;
struct V_8 * V_142 ;
struct V_11 * V_12 = V_9 -> V_12 ;
struct V_135 * V_143 = & V_12 -> V_134 [ V_9 -> V_15 -> V_16 ] ;
struct V_24 V_25 ;
if ( F_14 ( ! V_9 -> V_15 -> V_133 ) )
return 0 ;
V_25 . V_3 = NULL ;
if ( V_9 -> V_21 )
V_25 . V_3 = & V_9 -> V_21 -> V_4 ;
do {
V_30 = F_82 ( V_9 , & V_25 ) ;
if ( F_14 ( V_30 != - V_144 ) )
break;
F_5 ( & V_12 -> V_17 ) ;
if ( F_11 ( V_143 ) || ! V_9 -> V_15 -> V_133 ) {
F_48 ( L_7
L_8 , V_9 -> V_15 -> V_145 ) ;
V_30 = - V_144 ;
F_7 ( & V_12 -> V_17 ) ;
break;
}
V_142 = F_2
( F_95 ( V_143 , struct V_8 ,
V_20 ) ) ;
F_9 ( & V_142 -> V_20 ) ;
F_7 ( & V_12 -> V_17 ) ;
F_93 ( V_142 ) ;
F_16 ( & V_142 ) ;
} while ( 1 );
if ( F_20 ( V_30 != 0 ) )
goto V_139;
else if ( ! V_9 -> V_15 -> V_128 && V_9 -> V_21 ) {
F_9 ( & V_9 -> V_22 ) ;
F_13 ( & V_9 -> V_21 ) ;
}
return 0 ;
V_139:
return V_30 ;
}
void F_96 ( struct V_2 * V_3 ,
struct V_146 * V_147 )
{
struct V_56 * V_57 = V_3 -> V_57 ;
struct V_148 * V_149 = V_57 -> V_149 ;
struct V_146 * V_150 ;
struct V_11 * V_12 =
F_1 ( V_57 , struct V_11 , V_57 ) ;
if ( V_147 == NULL )
F_97 ( NULL , V_12 , & V_147 , NULL ) ;
else
V_149 -> V_151 ( V_147 ) ;
F_98 ( & V_57 -> V_152 ) ;
V_150 = V_3 -> V_153 ;
V_3 -> V_153 = V_147 ;
F_99 ( & V_57 -> V_152 ) ;
if ( V_150 )
F_100 ( & V_150 ) ;
}
void F_101 ( struct V_2 * V_3 ,
struct V_154 * V_155 )
{
}
bool F_102 ( const struct V_8 * V_9 )
{
return V_9 -> V_15 -> V_128 ;
}
static void F_103 ( struct V_11 * V_12 ,
enum V_156 type )
{
struct V_135 * V_143 = & V_12 -> V_134 [ type ] ;
struct V_8 * V_142 ;
do {
F_5 ( & V_12 -> V_17 ) ;
if ( F_11 ( V_143 ) )
goto V_110;
V_142 = F_2 (
F_95 ( V_143 , struct V_8 ,
V_20 ) ) ;
F_9 ( & V_142 -> V_20 ) ;
F_7 ( & V_12 -> V_17 ) ;
F_93 ( V_142 ) ;
F_16 ( & V_142 ) ;
} while ( 1 );
V_110:
F_7 ( & V_12 -> V_17 ) ;
}
void F_104 ( struct V_11 * V_12 )
{
enum V_156 type ;
F_105 ( & V_12 -> V_157 ) ;
for ( type = 0 ; type < V_158 ; ++ type )
F_103 ( V_12 , type ) ;
F_106 ( & V_12 -> V_157 ) ;
}
