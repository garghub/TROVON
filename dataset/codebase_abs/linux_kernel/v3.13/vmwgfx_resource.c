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
if ( F_31 ( F_34 ( V_4 ) != V_41 -> V_44 ) )
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
F_35 ( & V_4 ) ;
return V_30 ;
}
int F_36 ( struct V_11 * V_12 ,
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
* V_48 = F_37 ( V_9 ) ;
return 0 ;
}
* V_48 = NULL ;
V_30 = F_38 ( V_38 , V_39 , V_49 ) ;
return V_30 ;
}
static T_2 F_39 ( struct V_11 * V_12 , T_2 V_51 ,
bool V_52 )
{
static T_2 V_53 , V_54 ;
T_2 V_55 = F_40 ( V_51 ) >> V_56 ;
T_2 V_57 = F_41 ( V_55 * sizeof( void * ) ) ;
if ( F_31 ( V_53 == 0 ) ) {
T_2 V_58 = F_41 ( V_59 ) ;
V_53 = V_58 +
F_41 ( sizeof( struct V_1 ) ) ;
V_54 = V_58 +
F_41 ( sizeof( struct V_5 ) ) ;
}
if ( V_12 -> V_60 == V_61 )
V_57 +=
F_41 ( V_55 * sizeof( V_62 ) ) ;
return ( ( V_52 ) ? V_54 : V_53 ) +
V_57 ;
}
void F_42 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = V_1 ( V_3 ) ;
F_15 ( V_6 ) ;
}
static void F_43 ( struct V_2 * V_3 )
{
struct V_5 * V_63 = V_5 ( V_3 ) ;
F_44 ( V_63 , V_64 ) ;
}
int F_45 ( struct V_11 * V_12 ,
struct V_1 * V_6 ,
T_2 V_51 , struct V_65 * V_66 ,
bool V_67 ,
void (* F_46) ( struct V_2 * V_3 ) )
{
struct V_68 * V_69 = & V_12 -> V_69 ;
T_2 V_70 ;
int V_30 ;
bool V_52 = ( F_46 == & F_43 ) ;
F_19 ( ! F_46 && ( ! V_52 && ( F_46 != F_42 ) ) ) ;
V_70 = F_39 ( V_12 , V_51 , V_52 ) ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
F_25 ( & V_6 -> V_71 ) ;
V_30 = F_47 ( V_69 , & V_6 -> V_4 , V_51 ,
( V_52 ) ? V_72 :
V_73 , V_66 ,
0 , V_67 ,
NULL , V_70 , NULL , F_46 ) ;
return V_30 ;
}
static void F_48 ( struct V_42 * * V_74 )
{
struct V_5 * V_63 ;
struct V_42 * V_4 = * V_74 ;
struct V_2 * V_3 ;
* V_74 = NULL ;
if ( F_31 ( V_4 == NULL ) )
return;
V_63 = F_1 ( V_4 , struct V_5 ,
V_64 . V_4 ) ;
V_3 = & V_63 -> V_7 . V_4 ;
F_49 ( & V_3 ) ;
}
int F_50 ( struct V_11 * V_12 ,
struct V_37 * V_38 ,
T_1 V_51 ,
bool V_75 ,
T_1 * V_39 ,
struct V_1 * * V_76 )
{
struct V_5 * V_77 ;
struct V_2 * V_78 ;
int V_30 ;
V_77 = F_51 ( sizeof( * V_77 ) , V_31 ) ;
if ( F_31 ( V_77 == NULL ) ) {
F_52 ( L_1 ) ;
return - V_79 ;
}
V_30 = F_45 ( V_12 , & V_77 -> V_7 , V_51 ,
& V_80 , true ,
& F_43 ) ;
if ( F_31 ( V_30 != 0 ) )
return V_30 ;
V_78 = F_53 ( & V_77 -> V_7 . V_4 ) ;
V_30 = F_54 ( V_38 ,
V_51 ,
& V_77 -> V_64 ,
V_75 ,
V_81 ,
& F_48 , NULL ) ;
if ( F_31 ( V_30 != 0 ) ) {
F_49 ( & V_78 ) ;
goto V_82;
}
* V_76 = & V_77 -> V_7 ;
* V_39 = V_77 -> V_64 . V_4 . V_83 . V_84 ;
V_82:
return V_30 ;
}
int F_55 ( struct V_2 * V_3 ,
struct V_37 * V_38 )
{
struct V_5 * V_63 ;
if ( F_31 ( V_3 -> V_85 != F_43 ) )
return - V_86 ;
V_63 = V_5 ( V_3 ) ;
return ( V_63 -> V_64 . V_4 . V_38 == V_38 ||
V_63 -> V_64 . V_4 . V_75 ) ? 0 : - V_86 ;
}
int F_56 ( struct V_87 * V_88 , void * V_89 ,
struct V_90 * V_91 )
{
struct V_11 * V_12 = F_57 ( V_88 ) ;
union V_92 * V_93 =
(union V_92 * ) V_89 ;
struct V_94 * V_95 = & V_93 -> V_95 ;
struct V_96 * V_97 = & V_93 -> V_97 ;
struct V_1 * V_98 ;
T_1 V_39 ;
struct V_99 * V_100 = V_99 ( V_91 -> V_101 ) ;
int V_30 ;
V_30 = F_58 ( & V_100 -> V_102 , true ) ;
if ( F_31 ( V_30 != 0 ) )
return V_30 ;
V_30 = F_50 ( V_12 , F_59 ( V_91 ) -> V_38 ,
V_95 -> V_51 , false , & V_39 , & V_98 ) ;
if ( F_31 ( V_30 != 0 ) )
goto V_103;
V_97 -> V_39 = V_39 ;
V_97 -> V_104 = F_60 ( & V_98 -> V_4 . V_105 ) ;
V_97 -> V_106 = V_39 ;
V_97 -> V_107 = 0 ;
F_13 ( & V_98 ) ;
V_103:
F_61 ( & V_100 -> V_102 ) ;
return V_30 ;
}
int F_62 ( struct V_87 * V_88 , void * V_89 ,
struct V_90 * V_91 )
{
struct V_108 * V_93 =
(struct V_108 * ) V_89 ;
return F_63 ( F_59 ( V_91 ) -> V_38 ,
V_93 -> V_39 ,
V_109 ) ;
}
int F_38 ( struct V_37 * V_38 ,
T_1 V_39 , struct V_1 * * V_110 )
{
struct V_5 * V_63 ;
struct V_42 * V_4 ;
V_4 = F_33 ( V_38 , V_39 ) ;
if ( F_31 ( V_4 == NULL ) ) {
F_64 ( V_111 L_2 ,
( unsigned long ) V_39 ) ;
return - V_112 ;
}
if ( F_31 ( F_34 ( V_4 ) != V_81 ) ) {
F_35 ( & V_4 ) ;
F_64 ( V_111 L_2 ,
( unsigned long ) V_39 ) ;
return - V_43 ;
}
V_63 = F_1 ( V_4 , struct V_5 ,
V_64 . V_4 ) ;
( void ) F_53 ( & V_63 -> V_7 . V_4 ) ;
F_35 ( & V_4 ) ;
* V_110 = & V_63 -> V_7 ;
return 0 ;
}
int F_65 ( struct V_37 * V_38 ,
struct V_1 * V_98 )
{
struct V_5 * V_77 ;
if ( V_98 -> V_4 . V_85 != F_43 )
return - V_43 ;
V_77 = F_1 ( V_98 , struct V_5 , V_7 ) ;
return F_66 ( V_38 , & V_77 -> V_64 . V_4 ,
V_109 , NULL ) ;
}
static void F_67 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
struct V_113 * V_114 ;
int V_30 ;
F_68 ( L_3 , V_115 ) ;
V_114 = F_1 ( V_9 , struct V_113 , V_9 ) ;
V_30 = F_69 ( V_12 , V_114 -> V_116 ) ;
F_70 ( V_30 != 0 ) ;
}
static int F_71 ( struct V_11 * V_12 ,
struct V_113 * V_114 ,
void (* V_28) ( struct V_8 * V_9 ) )
{
struct V_8 * V_9 = & V_114 -> V_9 ;
int V_30 ;
V_30 = F_23 ( V_12 , V_9 , false , V_28 ,
& V_117 ) ;
if ( F_31 ( V_30 != 0 ) ) {
if ( V_28 == NULL )
F_15 ( V_114 ) ;
else
V_28 ( & V_114 -> V_9 ) ;
return V_30 ;
}
V_30 = F_72 ( V_12 , & V_114 -> V_116 ) ;
if ( V_30 ) {
F_16 ( & V_9 ) ;
return V_30 ;
}
F_68 ( L_4 , V_115 ) ;
F_26 ( & V_114 -> V_9 , F_67 ) ;
return 0 ;
}
static void F_73 ( struct V_8 * V_9 )
{
struct V_118 * V_114 =
F_1 ( V_9 , struct V_118 , V_114 . V_9 ) ;
struct V_11 * V_12 = V_9 -> V_12 ;
F_74 ( V_114 , V_4 ) ;
F_75 ( F_76 ( V_12 ) ,
V_119 ) ;
}
static void F_77 ( struct V_42 * * V_74 )
{
struct V_42 * V_4 = * V_74 ;
struct V_118 * V_114 =
F_1 ( V_4 , struct V_118 , V_4 ) ;
struct V_8 * V_9 = & V_114 -> V_114 . V_9 ;
* V_74 = NULL ;
F_16 ( & V_9 ) ;
}
int F_78 ( struct V_87 * V_88 , void * V_89 ,
struct V_90 * V_91 )
{
struct V_11 * V_12 = F_57 ( V_88 ) ;
struct V_8 * V_9 ;
struct V_118 * V_114 ;
struct V_120 * V_93 = (struct V_120 * ) V_89 ;
struct V_37 * V_38 = F_59 ( V_91 ) -> V_38 ;
struct V_13 * V_13 = & V_12 -> V_14 [ V_121 ] ;
int V_30 = 0 ;
V_9 = F_27 ( V_12 , V_13 , V_93 -> V_116 ) ;
if ( F_31 ( V_9 == NULL ) )
return - V_43 ;
if ( V_9 -> V_28 != & F_73 ) {
V_30 = - V_43 ;
goto V_110;
}
V_114 = F_1 ( V_9 , struct V_118 , V_114 . V_9 ) ;
if ( V_114 -> V_4 . V_38 != V_38 ) {
V_30 = - V_43 ;
goto V_110;
}
F_63 ( V_38 , V_114 -> V_4 . V_83 . V_84 , V_109 ) ;
V_110:
F_16 ( & V_9 ) ;
return V_30 ;
}
int F_79 ( struct V_87 * V_88 , void * V_89 ,
struct V_90 * V_91 )
{
struct V_11 * V_12 = F_57 ( V_88 ) ;
struct V_118 * V_114 ;
struct V_8 * V_9 ;
struct V_8 * V_78 ;
struct V_120 * V_93 = (struct V_120 * ) V_89 ;
struct V_37 * V_38 = F_59 ( V_91 ) -> V_38 ;
struct V_99 * V_100 = V_99 ( V_91 -> V_101 ) ;
int V_30 ;
if ( F_31 ( V_119 == 0 ) )
V_119 = F_41 ( sizeof( * V_114 ) ) + 128 ;
V_30 = F_58 ( & V_100 -> V_102 , true ) ;
if ( F_31 ( V_30 != 0 ) )
return V_30 ;
V_30 = F_80 ( F_76 ( V_12 ) ,
V_119 ,
false , true ) ;
if ( F_31 ( V_30 != 0 ) ) {
if ( V_30 != - V_122 )
F_52 ( L_5
L_6 ) ;
goto V_123;
}
V_114 = F_81 ( sizeof( * V_114 ) , V_31 ) ;
if ( F_31 ( V_114 == NULL ) ) {
F_75 ( F_76 ( V_12 ) ,
V_119 ) ;
V_30 = - V_79 ;
goto V_123;
}
V_9 = & V_114 -> V_114 . V_9 ;
V_114 -> V_4 . V_75 = false ;
V_114 -> V_4 . V_38 = NULL ;
V_30 = F_71 ( V_12 , & V_114 -> V_114 , F_73 ) ;
if ( F_31 ( V_30 != 0 ) )
goto V_123;
V_78 = F_2 ( V_9 ) ;
V_30 = F_82 ( V_38 , & V_114 -> V_4 , false , V_124 ,
& F_77 , NULL ) ;
if ( F_31 ( V_30 != 0 ) ) {
F_16 ( & V_78 ) ;
goto V_125;
}
V_93 -> V_116 = V_9 -> V_18 ;
V_125:
F_16 ( & V_9 ) ;
V_123:
F_61 ( & V_100 -> V_102 ) ;
return V_30 ;
}
int F_83 ( struct V_11 * V_12 ,
struct V_37 * V_38 ,
T_1 * V_126 , struct V_8 * * V_110 )
{
struct V_118 * V_114 ;
struct V_8 * V_9 ;
int V_30 ;
V_9 = F_27 ( V_12 , & V_12 -> V_14 [ V_121 ] ,
* V_126 ) ;
if ( F_31 ( V_9 == NULL ) )
return - V_43 ;
if ( V_9 -> V_28 != & F_73 ) {
V_30 = - V_43 ;
goto V_127;
}
V_114 = F_1 ( V_9 , struct V_118 , V_114 . V_9 ) ;
if ( V_114 -> V_4 . V_38 != V_38 ) {
V_30 = - V_86 ;
goto V_127;
}
* V_126 = V_114 -> V_114 . V_116 ;
* V_110 = V_9 ;
return 0 ;
V_127:
F_16 ( & V_9 ) ;
return V_30 ;
}
int F_84 ( struct V_90 * V_91 ,
struct V_87 * V_88 ,
struct V_128 * args )
{
struct V_11 * V_12 = F_57 ( V_88 ) ;
struct V_99 * V_100 = V_99 ( V_91 -> V_101 ) ;
struct V_1 * V_98 ;
int V_30 ;
args -> V_129 = args -> V_130 * ( ( args -> V_131 + 7 ) / 8 ) ;
args -> V_51 = args -> V_129 * args -> V_132 ;
V_30 = F_58 ( & V_100 -> V_102 , true ) ;
if ( F_31 ( V_30 != 0 ) )
return V_30 ;
V_30 = F_50 ( V_12 , F_59 ( V_91 ) -> V_38 ,
args -> V_51 , false , & args -> V_39 ,
& V_98 ) ;
if ( F_31 ( V_30 != 0 ) )
goto V_103;
F_13 ( & V_98 ) ;
V_103:
F_61 ( & V_100 -> V_102 ) ;
return V_30 ;
}
int F_85 ( struct V_90 * V_91 ,
struct V_87 * V_88 , T_1 V_39 ,
T_3 * V_133 )
{
struct V_37 * V_38 = F_59 ( V_91 ) -> V_38 ;
struct V_1 * V_49 ;
int V_30 ;
V_30 = F_38 ( V_38 , V_39 , & V_49 ) ;
if ( V_30 != 0 )
return - V_43 ;
* V_133 = F_60 ( & V_49 -> V_4 . V_105 ) ;
F_13 ( & V_49 ) ;
return 0 ;
}
int F_86 ( struct V_90 * V_91 ,
struct V_87 * V_88 ,
T_1 V_39 )
{
return F_63 ( F_59 ( V_91 ) -> V_38 ,
V_39 , V_109 ) ;
}
static int F_87 ( struct V_8 * V_9 ,
bool V_67 )
{
unsigned long V_51 =
( V_9 -> V_134 + V_135 - 1 ) & V_136 ;
struct V_1 * V_21 ;
int V_30 ;
if ( F_14 ( V_9 -> V_21 ) ) {
F_19 ( V_9 -> V_21 -> V_4 . V_55 * V_135 < V_51 ) ;
return 0 ;
}
V_21 = F_51 ( sizeof( * V_21 ) , V_31 ) ;
if ( F_31 ( V_21 == NULL ) )
return - V_79 ;
V_30 = F_45 ( V_9 -> V_12 , V_21 , V_9 -> V_134 ,
V_9 -> V_15 -> V_137 ,
V_67 ,
& F_42 ) ;
if ( F_31 ( V_30 != 0 ) )
goto V_103;
V_9 -> V_21 = V_21 ;
V_103:
return V_30 ;
}
static int F_88 ( struct V_8 * V_9 ,
struct V_24 * V_25 )
{
int V_30 = 0 ;
const struct V_34 * V_15 = V_9 -> V_15 ;
if ( F_31 ( V_9 -> V_18 == - 1 ) ) {
V_30 = V_15 -> V_138 ( V_9 ) ;
if ( F_31 ( V_30 != 0 ) )
return V_30 ;
}
if ( V_15 -> V_139 &&
( ( V_15 -> V_140 && F_11 ( & V_9 -> V_22 ) &&
V_25 -> V_3 != NULL ) ||
( ! V_15 -> V_140 && V_25 -> V_3 != NULL ) ) ) {
V_30 = V_15 -> V_139 ( V_9 , V_25 ) ;
if ( F_31 ( V_30 != 0 ) )
goto V_141;
if ( V_15 -> V_140 )
F_89 ( & V_9 -> V_22 , & V_9 -> V_21 -> V_71 ) ;
}
V_9 -> V_36 = true ;
return 0 ;
V_141:
V_15 -> V_85 ( V_9 ) ;
return V_30 ;
}
void F_90 ( struct V_8 * V_9 ,
struct V_1 * V_142 ,
unsigned long V_143 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
if ( ! F_11 ( & V_9 -> V_20 ) )
return;
if ( V_142 && V_142 != V_9 -> V_21 ) {
if ( V_9 -> V_21 ) {
F_91 ( & V_9 -> V_21 -> V_4 . V_144 -> V_102 . V_4 ) ;
F_9 ( & V_9 -> V_22 ) ;
F_13 ( & V_9 -> V_21 ) ;
}
V_9 -> V_21 = F_92 ( V_142 ) ;
F_91 ( & V_142 -> V_4 . V_144 -> V_102 . V_4 ) ;
F_89 ( & V_9 -> V_22 , & V_142 -> V_71 ) ;
}
if ( V_142 )
V_9 -> V_35 = V_143 ;
if ( ! V_9 -> V_15 -> V_145 || V_9 -> V_18 == - 1 )
return;
F_5 ( & V_12 -> V_17 ) ;
F_89 ( & V_9 -> V_20 ,
& V_9 -> V_12 -> V_146 [ V_9 -> V_15 -> V_16 ] ) ;
F_7 ( & V_12 -> V_17 ) ;
}
static int
F_93 ( struct V_8 * V_9 ,
bool V_67 ,
struct V_24 * V_25 )
{
struct V_147 V_148 ;
bool V_26 = false ;
int V_30 ;
if ( F_31 ( V_9 -> V_21 == NULL ) ) {
V_30 = F_87 ( V_9 , V_67 ) ;
if ( F_31 ( V_30 != 0 ) )
return V_30 ;
}
F_25 ( & V_148 ) ;
V_25 -> V_3 = F_53 ( & V_9 -> V_21 -> V_4 ) ;
F_89 ( & V_25 -> V_149 , & V_148 ) ;
V_30 = F_94 ( NULL , & V_148 ) ;
if ( F_31 ( V_30 != 0 ) )
goto V_150;
if ( V_9 -> V_15 -> V_140 && F_11 ( & V_9 -> V_22 ) )
return 0 ;
V_26 = V_9 -> V_26 ;
V_30 = F_95 ( & V_9 -> V_21 -> V_4 ,
V_9 -> V_15 -> V_137 ,
true , false ) ;
if ( F_31 ( V_30 != 0 ) )
goto V_151;
return 0 ;
V_151:
F_96 ( NULL , & V_148 ) ;
V_150:
F_49 ( & V_25 -> V_3 ) ;
if ( V_26 )
F_13 ( & V_9 -> V_21 ) ;
return V_30 ;
}
int F_97 ( struct V_8 * V_9 , bool V_152 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
int V_30 ;
F_5 ( & V_12 -> V_17 ) ;
F_9 ( & V_9 -> V_20 ) ;
F_7 ( & V_12 -> V_17 ) ;
if ( V_9 -> V_15 -> V_140 && V_9 -> V_21 == NULL &&
! V_152 ) {
V_30 = F_87 ( V_9 , true ) ;
if ( F_31 ( V_30 != 0 ) )
return V_30 ;
}
return 0 ;
}
static void
F_98 ( struct V_24 * V_25 )
{
struct V_147 V_148 ;
if ( F_14 ( V_25 -> V_3 == NULL ) )
return;
F_25 ( & V_148 ) ;
F_89 ( & V_25 -> V_149 , & V_148 ) ;
F_96 ( NULL , & V_148 ) ;
F_49 ( & V_25 -> V_3 ) ;
}
int F_99 ( struct V_8 * V_9 , bool V_67 )
{
struct V_24 V_25 ;
const struct V_34 * V_15 = V_9 -> V_15 ;
int V_30 ;
F_19 ( ! V_15 -> V_145 ) ;
V_25 . V_3 = NULL ;
V_30 = F_93 ( V_9 , V_67 , & V_25 ) ;
if ( F_31 ( V_30 != 0 ) )
return V_30 ;
if ( F_31 ( V_15 -> V_23 != NULL &&
( ! V_15 -> V_140 || ! F_11 ( & V_9 -> V_22 ) ) ) ) {
V_30 = V_15 -> V_23 ( V_9 , V_9 -> V_36 , & V_25 ) ;
if ( F_31 ( V_30 != 0 ) )
goto V_153;
F_9 ( & V_9 -> V_22 ) ;
}
V_30 = V_15 -> V_85 ( V_9 ) ;
V_9 -> V_26 = true ;
V_9 -> V_36 = false ;
V_153:
F_98 ( & V_25 ) ;
return V_30 ;
}
int F_100 ( struct V_8 * V_9 )
{
int V_30 ;
struct V_8 * V_154 ;
struct V_11 * V_12 = V_9 -> V_12 ;
struct V_147 * V_155 = & V_12 -> V_146 [ V_9 -> V_15 -> V_16 ] ;
struct V_24 V_25 ;
unsigned V_156 = 0 ;
if ( F_14 ( ! V_9 -> V_15 -> V_145 ) )
return 0 ;
V_25 . V_3 = NULL ;
if ( V_9 -> V_21 )
V_25 . V_3 = & V_9 -> V_21 -> V_4 ;
do {
V_30 = F_88 ( V_9 , & V_25 ) ;
if ( F_14 ( V_30 != - V_157 ) )
break;
F_5 ( & V_12 -> V_17 ) ;
if ( F_11 ( V_155 ) || ! V_9 -> V_15 -> V_145 ) {
F_52 ( L_7
L_8 , V_9 -> V_15 -> V_158 ) ;
V_30 = - V_157 ;
F_7 ( & V_12 -> V_17 ) ;
break;
}
V_154 = F_2
( F_101 ( V_155 , struct V_8 ,
V_20 ) ) ;
F_9 ( & V_154 -> V_20 ) ;
F_7 ( & V_12 -> V_17 ) ;
V_30 = F_99 ( V_154 , true ) ;
if ( F_31 ( V_30 != 0 ) ) {
F_5 ( & V_12 -> V_17 ) ;
F_89 ( & V_154 -> V_20 , V_155 ) ;
F_7 ( & V_12 -> V_17 ) ;
if ( V_30 == - V_122 ||
++ V_156 > V_159 ) {
F_16 ( & V_154 ) ;
goto V_151;
}
}
F_16 ( & V_154 ) ;
} while ( 1 );
if ( F_31 ( V_30 != 0 ) )
goto V_151;
else if ( ! V_9 -> V_15 -> V_140 && V_9 -> V_21 ) {
F_9 ( & V_9 -> V_22 ) ;
F_13 ( & V_9 -> V_21 ) ;
}
return 0 ;
V_151:
return V_30 ;
}
void F_102 ( struct V_2 * V_3 ,
struct V_160 * V_161 )
{
struct V_68 * V_69 = V_3 -> V_69 ;
struct V_162 * V_163 = V_69 -> V_163 ;
struct V_160 * V_164 ;
struct V_11 * V_12 =
F_1 ( V_69 , struct V_11 , V_69 ) ;
if ( V_161 == NULL )
F_103 ( NULL , V_12 , & V_161 , NULL ) ;
else
V_163 -> V_165 ( V_161 ) ;
F_104 ( & V_69 -> V_166 ) ;
V_164 = V_3 -> V_167 ;
V_3 -> V_167 = V_161 ;
F_105 ( & V_69 -> V_166 ) ;
if ( V_164 )
F_106 ( & V_164 ) ;
}
void F_107 ( struct V_2 * V_3 ,
struct V_168 * V_169 )
{
}
bool F_108 ( const struct V_8 * V_9 )
{
return V_9 -> V_15 -> V_140 ;
}
static void F_109 ( struct V_11 * V_12 ,
enum V_170 type )
{
struct V_147 * V_155 = & V_12 -> V_146 [ type ] ;
struct V_8 * V_154 ;
unsigned V_156 = 0 ;
int V_30 ;
do {
F_5 ( & V_12 -> V_17 ) ;
if ( F_11 ( V_155 ) )
goto V_123;
V_154 = F_2 (
F_101 ( V_155 , struct V_8 ,
V_20 ) ) ;
F_9 ( & V_154 -> V_20 ) ;
F_7 ( & V_12 -> V_17 ) ;
V_30 = F_99 ( V_154 , false ) ;
if ( F_31 ( V_30 != 0 ) ) {
F_5 ( & V_12 -> V_17 ) ;
F_89 ( & V_154 -> V_20 , V_155 ) ;
F_7 ( & V_12 -> V_17 ) ;
if ( ++ V_156 > V_159 ) {
F_16 ( & V_154 ) ;
return;
}
}
F_16 ( & V_154 ) ;
} while ( 1 );
V_123:
F_7 ( & V_12 -> V_17 ) ;
}
void F_110 ( struct V_11 * V_12 )
{
enum V_170 type ;
F_111 ( & V_12 -> V_171 ) ;
for ( type = 0 ; type < V_172 ; ++ type )
F_109 ( V_12 , type ) ;
F_112 ( & V_12 -> V_171 ) ;
}
