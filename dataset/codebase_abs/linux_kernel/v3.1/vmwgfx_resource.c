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
static void F_4 ( struct V_10 * V_10 )
{
struct V_8 * V_9 =
F_1 ( V_10 , struct V_8 , V_10 ) ;
struct V_11 * V_12 = V_9 -> V_12 ;
F_5 ( V_9 -> V_13 , V_9 -> V_14 ) ;
F_6 ( & V_12 -> V_15 ) ;
if ( F_7 ( V_9 -> V_16 != NULL ) )
V_9 -> V_16 ( V_9 ) ;
if ( V_9 -> V_17 != NULL )
V_9 -> V_17 ( V_9 ) ;
else
F_8 ( V_9 ) ;
F_9 ( & V_12 -> V_15 ) ;
}
void F_10 ( struct V_8 * * V_18 )
{
struct V_8 * V_9 = * V_18 ;
struct V_11 * V_12 = V_9 -> V_12 ;
* V_18 = NULL ;
F_9 ( & V_12 -> V_15 ) ;
F_11 ( & V_9 -> V_10 , F_4 ) ;
F_6 ( & V_12 -> V_15 ) ;
}
static int F_12 ( struct V_11 * V_12 ,
struct V_8 * V_9 ,
struct V_13 * V_13 ,
enum V_19 V_20 ,
void (* V_17) ( struct V_8 * V_9 ) )
{
int V_21 ;
F_13 ( & V_9 -> V_10 ) ;
V_9 -> V_16 = NULL ;
V_9 -> V_17 = V_17 ;
V_9 -> V_22 = V_20 ;
V_9 -> V_13 = V_13 ;
V_9 -> V_23 = false ;
V_9 -> V_12 = V_12 ;
do {
if ( F_14 ( F_15 ( V_13 , V_24 ) == 0 ) )
return - V_25 ;
F_9 ( & V_12 -> V_15 ) ;
V_21 = F_16 ( V_13 , V_9 , 1 , & V_9 -> V_14 ) ;
F_6 ( & V_12 -> V_15 ) ;
} while ( V_21 == - V_26 );
return V_21 ;
}
static void F_17 ( struct V_8 * V_9 ,
void (* V_16) ( struct V_8 * ) )
{
struct V_11 * V_12 = V_9 -> V_12 ;
F_9 ( & V_12 -> V_15 ) ;
V_9 -> V_23 = true ;
V_9 -> V_16 = V_16 ;
F_6 ( & V_12 -> V_15 ) ;
}
struct V_8 * F_18 ( struct V_11 * V_12 ,
struct V_13 * V_13 , int V_14 )
{
struct V_8 * V_9 ;
F_19 ( & V_12 -> V_15 ) ;
V_9 = F_20 ( V_13 , V_14 ) ;
if ( V_9 && V_9 -> V_23 )
F_3 ( & V_9 -> V_10 ) ;
else
V_9 = NULL ;
F_21 ( & V_12 -> V_15 ) ;
if ( F_14 ( V_9 == NULL ) )
return NULL ;
return V_9 ;
}
static void F_22 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
struct {
T_1 V_27 ;
T_2 V_28 ;
} * V_29 = F_23 ( V_12 , sizeof( * V_29 ) ) ;
if ( F_14 ( V_29 == NULL ) ) {
F_24 ( L_1
L_2 ) ;
return;
}
V_29 -> V_27 . V_14 = F_25 ( V_30 ) ;
V_29 -> V_27 . V_31 = F_25 ( sizeof( V_29 -> V_28 ) ) ;
V_29 -> V_28 . V_32 = F_25 ( V_9 -> V_14 ) ;
F_26 ( V_12 , sizeof( * V_29 ) ) ;
F_27 ( V_12 ) ;
}
static int F_28 ( struct V_11 * V_12 ,
struct V_8 * V_9 ,
void (* V_17) ( struct V_8 * V_9 ) )
{
int V_21 ;
struct {
T_1 V_27 ;
T_3 V_28 ;
} * V_29 ;
V_21 = F_12 ( V_12 , V_9 , & V_12 -> V_33 ,
V_34 , V_17 ) ;
if ( F_14 ( V_21 != 0 ) ) {
if ( V_17 == NULL )
F_8 ( V_9 ) ;
else
V_17 ( V_9 ) ;
return V_21 ;
}
V_29 = F_23 ( V_12 , sizeof( * V_29 ) ) ;
if ( F_14 ( V_29 == NULL ) ) {
F_24 ( L_3 ) ;
F_10 ( & V_9 ) ;
return - V_25 ;
}
V_29 -> V_27 . V_14 = F_25 ( V_35 ) ;
V_29 -> V_27 . V_31 = F_25 ( sizeof( V_29 -> V_28 ) ) ;
V_29 -> V_28 . V_32 = F_25 ( V_9 -> V_14 ) ;
F_26 ( V_12 , sizeof( * V_29 ) ) ;
( void ) F_29 ( V_12 ) ;
F_17 ( V_9 , F_22 ) ;
return 0 ;
}
struct V_8 * F_30 ( struct V_11 * V_12 )
{
struct V_8 * V_9 = F_31 ( sizeof( * V_9 ) , V_24 ) ;
int V_21 ;
if ( F_14 ( V_9 == NULL ) )
return NULL ;
V_21 = F_28 ( V_12 , V_9 , NULL ) ;
return ( V_21 == 0 ) ? V_9 : NULL ;
}
static void F_32 ( struct V_8 * V_9 )
{
struct V_36 * V_37 =
F_1 ( V_9 , struct V_36 , V_9 ) ;
F_8 ( V_37 ) ;
}
static void F_33 ( struct V_38 * * V_39 )
{
struct V_38 * V_4 = * V_39 ;
struct V_36 * V_37 =
F_1 ( V_4 , struct V_36 , V_4 ) ;
struct V_8 * V_9 = & V_37 -> V_9 ;
* V_39 = NULL ;
F_10 ( & V_9 ) ;
}
int F_34 ( struct V_40 * V_41 , void * V_42 ,
struct V_43 * V_44 )
{
struct V_11 * V_12 = F_35 ( V_41 ) ;
struct V_8 * V_9 ;
struct V_36 * V_37 ;
struct V_45 * V_46 = (struct V_45 * ) V_42 ;
struct V_47 * V_48 = F_36 ( V_44 ) -> V_48 ;
int V_21 = 0 ;
V_9 = F_18 ( V_12 , & V_12 -> V_33 , V_46 -> V_32 ) ;
if ( F_14 ( V_9 == NULL ) )
return - V_49 ;
if ( V_9 -> V_17 != & F_32 ) {
V_21 = - V_49 ;
goto V_50;
}
V_37 = F_1 ( V_9 , struct V_36 , V_9 ) ;
if ( V_37 -> V_4 . V_48 != V_48 && ! V_37 -> V_4 . V_51 ) {
V_21 = - V_52 ;
goto V_50;
}
F_37 ( V_48 , V_37 -> V_4 . V_53 . V_54 , V_55 ) ;
V_50:
F_10 ( & V_9 ) ;
return V_21 ;
}
int F_38 ( struct V_40 * V_41 , void * V_42 ,
struct V_43 * V_44 )
{
struct V_11 * V_12 = F_35 ( V_41 ) ;
struct V_36 * V_37 = F_31 ( sizeof( * V_37 ) , V_24 ) ;
struct V_8 * V_9 ;
struct V_8 * V_56 ;
struct V_45 * V_46 = (struct V_45 * ) V_42 ;
struct V_47 * V_48 = F_36 ( V_44 ) -> V_48 ;
int V_21 ;
if ( F_14 ( V_37 == NULL ) )
return - V_25 ;
V_9 = & V_37 -> V_9 ;
V_37 -> V_4 . V_51 = false ;
V_37 -> V_4 . V_48 = NULL ;
V_21 = F_28 ( V_12 , V_9 , F_32 ) ;
if ( F_14 ( V_21 != 0 ) )
return V_21 ;
V_56 = F_2 ( & V_37 -> V_9 ) ;
V_21 = F_39 ( V_48 , & V_37 -> V_4 , false , V_34 ,
& F_33 , NULL ) ;
if ( F_14 ( V_21 != 0 ) ) {
F_10 ( & V_56 ) ;
goto V_57;
}
V_46 -> V_32 = V_9 -> V_14 ;
V_57:
F_10 ( & V_9 ) ;
return V_21 ;
}
int F_40 ( struct V_11 * V_12 ,
struct V_47 * V_48 ,
int V_14 )
{
struct V_8 * V_9 ;
int V_21 = 0 ;
F_19 ( & V_12 -> V_15 ) ;
V_9 = F_20 ( & V_12 -> V_33 , V_14 ) ;
if ( V_9 && V_9 -> V_23 ) {
struct V_36 * V_37 =
F_1 ( V_9 , struct V_36 , V_9 ) ;
if ( V_37 -> V_4 . V_48 != V_48 && ! V_37 -> V_4 . V_51 )
V_21 = - V_52 ;
} else
V_21 = - V_49 ;
F_21 ( & V_12 -> V_15 ) ;
return V_21 ;
}
static void F_41 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
struct {
T_1 V_27 ;
T_4 V_28 ;
} * V_29 = F_23 ( V_12 , sizeof( * V_29 ) ) ;
if ( F_14 ( V_29 == NULL ) ) {
F_24 ( L_1
L_2 ) ;
return;
}
V_29 -> V_27 . V_14 = F_25 ( V_58 ) ;
V_29 -> V_27 . V_31 = F_25 ( sizeof( V_29 -> V_28 ) ) ;
V_29 -> V_28 . V_59 = F_25 ( V_9 -> V_14 ) ;
F_26 ( V_12 , sizeof( * V_29 ) ) ;
F_27 ( V_12 ) ;
}
void F_42 ( struct V_8 * V_9 )
{
struct V_60 * V_61 = F_1 ( V_9 , struct V_60 , V_9 ) ;
F_8 ( V_61 -> V_62 ) ;
F_8 ( V_61 -> V_63 . V_64 ) ;
F_8 ( V_61 ) ;
}
int F_43 ( struct V_11 * V_12 ,
struct V_60 * V_61 ,
void (* V_17) ( struct V_8 * V_9 ) )
{
int V_21 ;
struct {
T_1 V_27 ;
T_5 V_28 ;
} * V_29 ;
T_6 * V_65 ;
struct V_8 * V_9 = & V_61 -> V_9 ;
struct V_66 * V_67 ;
T_7 V_68 ;
T_8 V_69 ;
int V_70 ;
F_44 ( V_17 == NULL ) ;
V_21 = F_12 ( V_12 , V_9 , & V_12 -> V_71 ,
V_72 , V_17 ) ;
if ( F_14 ( V_21 != 0 ) ) {
V_17 ( V_9 ) ;
return V_21 ;
}
V_68 = sizeof( * V_29 ) + V_61 -> V_73 * sizeof( T_6 ) ;
V_69 = sizeof( V_29 -> V_28 ) + V_61 -> V_73 * sizeof( T_6 ) ;
V_29 = F_23 ( V_12 , V_68 ) ;
if ( F_14 ( V_29 == NULL ) ) {
F_24 ( L_4 ) ;
F_10 ( & V_9 ) ;
return - V_25 ;
}
V_29 -> V_27 . V_14 = F_25 ( V_74 ) ;
V_29 -> V_27 . V_31 = F_25 ( V_69 ) ;
V_29 -> V_28 . V_59 = F_25 ( V_9 -> V_14 ) ;
V_29 -> V_28 . V_75 = F_25 ( V_61 -> V_76 ) ;
V_29 -> V_28 . V_77 = F_25 ( V_61 -> V_77 ) ;
for ( V_70 = 0 ; V_70 < V_78 ; ++ V_70 ) {
V_29 -> V_28 . V_79 [ V_70 ] . V_80 =
F_25 ( V_61 -> V_81 [ V_70 ] ) ;
}
V_29 += 1 ;
V_65 = ( T_6 * ) V_29 ;
V_67 = V_61 -> V_62 ;
for ( V_70 = 0 ; V_70 < V_61 -> V_73 ; ++ V_70 , V_65 ++ , V_67 ++ ) {
V_65 -> V_82 = F_25 ( V_67 -> V_82 ) ;
V_65 -> V_83 = F_25 ( V_67 -> V_83 ) ;
V_65 -> V_84 = F_25 ( V_67 -> V_84 ) ;
}
F_26 ( V_12 , V_68 ) ;
( void ) F_29 ( V_12 ) ;
F_17 ( V_9 , F_41 ) ;
return 0 ;
}
static void F_45 ( struct V_8 * V_9 )
{
struct V_60 * V_61 = F_1 ( V_9 , struct V_60 , V_9 ) ;
struct V_85 * V_86 =
F_1 ( V_61 , struct V_85 , V_61 ) ;
F_8 ( V_61 -> V_62 ) ;
F_8 ( V_61 -> V_63 . V_64 ) ;
F_8 ( V_86 ) ;
}
int F_46 ( struct V_11 * V_12 ,
struct V_47 * V_48 ,
T_8 V_87 , struct V_60 * * V_50 )
{
struct V_8 * V_9 ;
struct V_60 * V_61 ;
struct V_85 * V_86 ;
struct V_38 * V_4 ;
int V_21 = - V_49 ;
V_4 = F_47 ( V_48 , V_87 ) ;
if ( F_14 ( V_4 == NULL ) )
return - V_49 ;
if ( F_14 ( V_4 -> V_88 != V_72 ) )
goto V_89;
V_86 = F_1 ( V_4 , struct V_85 , V_4 ) ;
V_61 = & V_86 -> V_61 ;
V_9 = & V_61 -> V_9 ;
F_19 ( & V_12 -> V_15 ) ;
if ( ! V_9 -> V_23 || V_9 -> V_17 != & F_45 ) {
F_21 ( & V_12 -> V_15 ) ;
goto V_89;
}
F_3 ( & V_9 -> V_10 ) ;
F_21 ( & V_12 -> V_15 ) ;
* V_50 = V_61 ;
V_21 = 0 ;
V_89:
F_48 ( & V_4 ) ;
return V_21 ;
}
static void F_49 ( struct V_38 * * V_39 )
{
struct V_38 * V_4 = * V_39 ;
struct V_85 * V_86 =
F_1 ( V_4 , struct V_85 , V_4 ) ;
struct V_8 * V_9 = & V_86 -> V_61 . V_9 ;
* V_39 = NULL ;
F_10 ( & V_9 ) ;
}
int F_50 ( struct V_40 * V_41 , void * V_42 ,
struct V_43 * V_44 )
{
struct V_90 * V_46 = (struct V_90 * ) V_42 ;
struct V_47 * V_48 = F_36 ( V_44 ) -> V_48 ;
return F_37 ( V_48 , V_46 -> V_59 , V_55 ) ;
}
int F_51 ( struct V_40 * V_41 , void * V_42 ,
struct V_43 * V_44 )
{
struct V_11 * V_12 = F_35 ( V_41 ) ;
struct V_85 * V_86 =
F_31 ( sizeof( * V_86 ) , V_24 ) ;
struct V_60 * V_61 ;
struct V_8 * V_9 ;
struct V_8 * V_56 ;
union V_91 * V_46 =
(union V_91 * ) V_42 ;
struct V_92 * V_93 = & V_46 -> V_93 ;
struct V_90 * V_94 = & V_46 -> V_94 ;
struct V_47 * V_48 = F_36 ( V_44 ) -> V_48 ;
struct V_66 T_9 * V_95 ;
int V_21 ;
int V_70 ;
if ( F_14 ( V_86 == NULL ) )
return - V_25 ;
V_61 = & V_86 -> V_61 ;
V_9 = & V_61 -> V_9 ;
V_61 -> V_76 = V_93 -> V_76 ;
V_61 -> V_77 = V_93 -> V_77 ;
V_61 -> V_96 = V_93 -> V_96 ;
memcpy ( V_61 -> V_81 , V_93 -> V_81 , sizeof( V_61 -> V_81 ) ) ;
V_61 -> V_73 = 0 ;
for ( V_70 = 0 ; V_70 < V_78 ; ++ V_70 )
V_61 -> V_73 += V_61 -> V_81 [ V_70 ] ;
if ( V_61 -> V_73 > V_78 *
V_97 ) {
V_21 = - V_49 ;
goto V_98;
}
V_61 -> V_62 = F_31 ( V_61 -> V_73 * sizeof( * V_61 -> V_62 ) , V_24 ) ;
if ( F_14 ( V_61 -> V_62 == NULL ) ) {
V_21 = - V_25 ;
goto V_98;
}
V_95 = (struct V_66 T_9 * ) ( unsigned long )
V_93 -> V_99 ;
V_21 = F_52 ( V_61 -> V_62 , V_95 ,
V_61 -> V_73 * sizeof( * V_61 -> V_62 ) ) ;
if ( F_14 ( V_21 != 0 ) ) {
V_21 = - V_100 ;
goto V_101;
}
if ( V_61 -> V_96 &&
V_61 -> V_73 == 1 &&
V_61 -> V_62 [ 0 ] . V_82 == 64 &&
V_61 -> V_62 [ 0 ] . V_83 == 64 &&
V_61 -> V_77 == V_102 ) {
V_61 -> V_63 . V_64 = F_53 ( 64 * 64 * 4 , V_24 ) ;
if ( ! V_61 -> V_63 . V_64 ) {
F_24 ( L_5 ) ;
V_21 = - V_25 ;
goto V_101;
}
} else {
V_61 -> V_63 . V_64 = NULL ;
}
V_61 -> V_63 . V_103 = NULL ;
V_86 -> V_4 . V_51 = false ;
V_86 -> V_4 . V_48 = NULL ;
V_21 = F_43 ( V_12 , V_61 , F_45 ) ;
if ( F_14 ( V_21 != 0 ) )
return V_21 ;
V_56 = F_2 ( & V_61 -> V_9 ) ;
V_21 = F_39 ( V_48 , & V_86 -> V_4 ,
V_93 -> V_51 , V_72 ,
& F_49 , NULL ) ;
if ( F_14 ( V_21 != 0 ) ) {
F_10 ( & V_56 ) ;
F_10 ( & V_9 ) ;
return V_21 ;
}
V_94 -> V_59 = V_86 -> V_4 . V_53 . V_54 ;
if ( V_94 -> V_59 == V_104 )
F_24 ( L_6 ) ;
F_10 ( & V_9 ) ;
return 0 ;
V_101:
F_8 ( V_61 -> V_62 ) ;
V_98:
F_8 ( V_86 ) ;
return V_21 ;
}
int F_54 ( struct V_40 * V_41 , void * V_42 ,
struct V_43 * V_44 )
{
union V_105 * V_46 =
(union V_105 * ) V_42 ;
struct V_90 * V_93 = & V_46 -> V_93 ;
struct V_92 * V_94 = & V_46 -> V_94 ;
struct V_47 * V_48 = F_36 ( V_44 ) -> V_48 ;
struct V_60 * V_61 ;
struct V_85 * V_86 ;
struct V_66 T_9 * V_95 ;
struct V_38 * V_4 ;
int V_21 = - V_49 ;
V_4 = F_47 ( V_48 , V_93 -> V_59 ) ;
if ( F_14 ( V_4 == NULL ) ) {
F_24 ( L_7 ) ;
return - V_49 ;
}
if ( F_14 ( V_4 -> V_88 != V_72 ) )
goto V_89;
V_86 = F_1 ( V_4 , struct V_85 , V_4 ) ;
V_61 = & V_86 -> V_61 ;
V_21 = F_55 ( V_48 , & V_86 -> V_4 , V_55 , NULL ) ;
if ( F_14 ( V_21 != 0 ) ) {
F_24 ( L_8 ) ;
goto V_106;
}
V_94 -> V_76 = V_61 -> V_76 ;
V_94 -> V_77 = V_61 -> V_77 ;
memcpy ( V_94 -> V_81 , V_61 -> V_81 , sizeof( V_61 -> V_81 ) ) ;
V_95 = (struct V_66 T_9 * ) ( unsigned long )
V_94 -> V_99 ;
if ( V_95 )
V_21 = F_56 ( V_95 , V_61 -> V_62 ,
V_61 -> V_73 * sizeof( * V_61 -> V_62 ) ) ;
if ( F_14 ( V_21 != 0 ) ) {
F_24 ( L_9 ,
V_95 , V_61 -> V_73 ) ;
V_21 = - V_100 ;
}
V_89:
V_106:
F_48 ( & V_4 ) ;
return V_21 ;
}
int F_57 ( struct V_11 * V_12 ,
struct V_47 * V_48 ,
T_8 V_87 , int * V_14 )
{
struct V_38 * V_4 ;
struct V_85 * V_86 ;
int V_21 = - V_52 ;
V_4 = F_47 ( V_48 , V_87 ) ;
if ( F_14 ( V_4 == NULL ) )
return - V_49 ;
if ( F_14 ( V_4 -> V_88 != V_72 ) )
goto V_107;
V_86 = F_1 ( V_4 , struct V_85 , V_4 ) ;
* V_14 = V_86 -> V_61 . V_9 . V_14 ;
V_21 = 0 ;
V_107:
F_48 ( & V_4 ) ;
return V_21 ;
}
static T_7 F_58 ( struct V_108 * V_109 ,
unsigned long V_110 )
{
static T_7 V_111 = ~ 0 ;
T_7 V_112 =
( V_110 * sizeof( void * ) + V_113 - 1 ) & V_114 ;
if ( F_14 ( V_111 == ~ 0 ) ) {
V_111 = V_109 -> V_115 +
F_59 ( sizeof( struct V_1 ) ) ;
}
return V_111 + V_112 ;
}
void F_60 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = V_1 ( V_3 ) ;
struct V_108 * V_109 = V_3 -> V_109 ;
F_61 ( V_109 -> V_116 , V_3 -> V_117 ) ;
F_8 ( V_6 ) ;
}
int F_62 ( struct V_11 * V_12 ,
struct V_1 * V_6 ,
T_7 V_31 , struct V_118 * V_119 ,
bool V_120 ,
void (* F_63) ( struct V_2 * V_3 ) )
{
struct V_121 * V_122 = & V_12 -> V_122 ;
struct V_123 * V_116 = V_122 -> V_109 -> V_116 ;
T_7 V_117 ;
int V_21 ;
F_44 ( ! F_63 ) ;
V_117 =
F_58 ( V_122 -> V_109 ,
( V_31 + V_113 - 1 ) >> V_124 ) ;
V_21 = F_64 ( V_116 , V_117 , false , false ) ;
if ( F_14 ( V_21 != 0 ) ) {
F_63 ( & V_6 -> V_4 ) ;
return V_21 ;
}
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
F_65 ( & V_6 -> V_125 ) ;
V_21 = F_66 ( V_122 , & V_6 -> V_4 , V_31 ,
V_126 , V_119 ,
0 , 0 , V_120 ,
NULL , V_117 , F_63 ) ;
return V_21 ;
}
static void F_67 ( struct V_2 * V_3 )
{
struct V_5 * V_127 = V_5 ( V_3 ) ;
struct V_108 * V_109 = V_3 -> V_109 ;
F_61 ( V_109 -> V_116 , V_3 -> V_117 ) ;
F_8 ( V_127 ) ;
}
static void F_68 ( struct V_38 * * V_39 )
{
struct V_5 * V_127 ;
struct V_38 * V_4 = * V_39 ;
struct V_2 * V_3 ;
* V_39 = NULL ;
if ( F_14 ( V_4 == NULL ) )
return;
V_127 = F_1 ( V_4 , struct V_5 , V_4 ) ;
V_3 = & V_127 -> V_7 . V_4 ;
F_69 ( & V_3 ) ;
}
int F_70 ( struct V_40 * V_41 , void * V_42 ,
struct V_43 * V_44 )
{
struct V_11 * V_12 = F_35 ( V_41 ) ;
union V_128 * V_46 =
(union V_128 * ) V_42 ;
struct V_129 * V_93 = & V_46 -> V_93 ;
struct V_130 * V_94 = & V_46 -> V_94 ;
struct V_5 * V_127 ;
struct V_2 * V_56 ;
struct V_131 * V_132 = V_131 ( V_44 -> V_133 ) ;
int V_21 ;
V_127 = F_53 ( sizeof( * V_127 ) , V_24 ) ;
if ( F_14 ( V_127 == NULL ) )
return - V_25 ;
V_21 = F_71 ( & V_132 -> V_134 , true ) ;
if ( F_14 ( V_21 != 0 ) ) {
F_8 ( V_127 ) ;
return V_21 ;
}
V_21 = F_62 ( V_12 , & V_127 -> V_7 , V_93 -> V_31 ,
& V_135 , true ,
& F_67 ) ;
if ( F_14 ( V_21 != 0 ) )
goto V_136;
V_56 = F_72 ( & V_127 -> V_7 . V_4 ) ;
V_21 = F_39 ( F_36 ( V_44 ) -> V_48 ,
& V_127 -> V_4 ,
false ,
V_137 ,
& F_68 , NULL ) ;
if ( F_14 ( V_21 != 0 ) )
goto V_138;
else {
V_94 -> V_87 = V_127 -> V_4 . V_53 . V_54 ;
V_94 -> V_139 = V_127 -> V_7 . V_4 . V_140 ;
V_94 -> V_141 = V_127 -> V_4 . V_53 . V_54 ;
V_94 -> V_142 = 0 ;
}
V_138:
F_69 ( & V_56 ) ;
V_136:
F_73 ( & V_132 -> V_134 ) ;
return V_21 ;
}
int F_74 ( struct V_40 * V_41 , void * V_42 ,
struct V_43 * V_44 )
{
struct V_143 * V_46 =
(struct V_143 * ) V_42 ;
return F_37 ( F_36 ( V_44 ) -> V_48 ,
V_46 -> V_87 ,
V_55 ) ;
}
T_8 F_75 ( struct V_2 * V_3 ,
T_8 V_144 )
{
struct V_1 * V_6 = V_1 ( V_3 ) ;
if ( F_7 ( V_6 -> V_145 ) )
return V_6 -> V_144 ;
V_6 -> V_144 = V_144 ;
V_6 -> V_145 = true ;
return V_144 ;
}
void F_76 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = V_1 ( V_3 ) ;
V_6 -> V_145 = false ;
}
int F_77 ( struct V_47 * V_48 ,
T_8 V_87 , struct V_1 * * V_50 )
{
struct V_5 * V_127 ;
struct V_38 * V_4 ;
V_4 = F_47 ( V_48 , V_87 ) ;
if ( F_14 ( V_4 == NULL ) ) {
F_78 ( V_146 L_10 ,
( unsigned long ) V_87 ) ;
return - V_147 ;
}
if ( F_14 ( V_4 -> V_88 != V_137 ) ) {
F_48 ( & V_4 ) ;
F_78 ( V_146 L_10 ,
( unsigned long ) V_87 ) ;
return - V_49 ;
}
V_127 = F_1 ( V_4 , struct V_5 , V_4 ) ;
( void ) F_72 ( & V_127 -> V_7 . V_4 ) ;
F_48 ( & V_4 ) ;
* V_50 = & V_127 -> V_7 ;
return 0 ;
}
static void F_79 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = V_9 -> V_12 ;
struct V_148 * V_149 ;
int V_21 ;
F_80 ( L_11 , V_150 ) ;
V_149 = F_1 ( V_9 , struct V_148 , V_9 ) ;
V_21 = F_81 ( V_12 , V_149 -> V_151 ) ;
F_82 ( V_21 != 0 ) ;
}
static int F_83 ( struct V_11 * V_12 ,
struct V_148 * V_149 ,
void (* V_17) ( struct V_8 * V_9 ) )
{
struct V_8 * V_9 = & V_149 -> V_9 ;
int V_21 ;
V_21 = F_12 ( V_12 , V_9 , & V_12 -> V_152 ,
V_153 , V_17 ) ;
if ( F_14 ( V_21 != 0 ) ) {
if ( V_17 == NULL )
F_8 ( V_149 ) ;
else
V_17 ( & V_149 -> V_9 ) ;
return V_21 ;
}
V_21 = F_84 ( V_12 , & V_149 -> V_151 ) ;
if ( V_21 ) {
F_10 ( & V_9 ) ;
return V_21 ;
}
F_80 ( L_12 , V_150 ) ;
F_17 ( & V_149 -> V_9 , F_79 ) ;
return 0 ;
}
static void F_85 ( struct V_8 * V_9 )
{
struct V_154 * V_149 =
F_1 ( V_9 , struct V_154 , V_149 . V_9 ) ;
F_8 ( V_149 ) ;
}
static void F_86 ( struct V_38 * * V_39 )
{
struct V_38 * V_4 = * V_39 ;
struct V_154 * V_149 =
F_1 ( V_4 , struct V_154 , V_4 ) ;
struct V_8 * V_9 = & V_149 -> V_149 . V_9 ;
* V_39 = NULL ;
F_10 ( & V_9 ) ;
}
int F_87 ( struct V_40 * V_41 , void * V_42 ,
struct V_43 * V_44 )
{
struct V_11 * V_12 = F_35 ( V_41 ) ;
struct V_8 * V_9 ;
struct V_154 * V_149 ;
struct V_155 * V_46 = (struct V_155 * ) V_42 ;
struct V_47 * V_48 = F_36 ( V_44 ) -> V_48 ;
int V_21 = 0 ;
V_9 = F_18 ( V_12 , & V_12 -> V_152 , V_46 -> V_151 ) ;
if ( F_14 ( V_9 == NULL ) )
return - V_49 ;
if ( V_9 -> V_17 != & F_85 ) {
V_21 = - V_49 ;
goto V_50;
}
V_149 = F_1 ( V_9 , struct V_154 , V_149 . V_9 ) ;
if ( V_149 -> V_4 . V_48 != V_48 ) {
V_21 = - V_49 ;
goto V_50;
}
F_37 ( V_48 , V_149 -> V_4 . V_53 . V_54 , V_55 ) ;
V_50:
F_10 ( & V_9 ) ;
return V_21 ;
}
int F_88 ( struct V_40 * V_41 , void * V_42 ,
struct V_43 * V_44 )
{
struct V_11 * V_12 = F_35 ( V_41 ) ;
struct V_154 * V_149 = F_31 ( sizeof( * V_149 ) , V_24 ) ;
struct V_8 * V_9 ;
struct V_8 * V_56 ;
struct V_155 * V_46 = (struct V_155 * ) V_42 ;
struct V_47 * V_48 = F_36 ( V_44 ) -> V_48 ;
int V_21 ;
if ( F_14 ( V_149 == NULL ) )
return - V_25 ;
V_9 = & V_149 -> V_149 . V_9 ;
V_149 -> V_4 . V_51 = false ;
V_149 -> V_4 . V_48 = NULL ;
V_21 = F_83 ( V_12 , & V_149 -> V_149 , F_85 ) ;
if ( F_14 ( V_21 != 0 ) )
return V_21 ;
V_56 = F_2 ( V_9 ) ;
V_21 = F_39 ( V_48 , & V_149 -> V_4 , false , V_153 ,
& F_86 , NULL ) ;
if ( F_14 ( V_21 != 0 ) ) {
F_10 ( & V_56 ) ;
goto V_57;
}
V_46 -> V_151 = V_9 -> V_14 ;
V_57:
F_10 ( & V_9 ) ;
return V_21 ;
}
int F_89 ( struct V_11 * V_12 ,
struct V_47 * V_48 ,
T_8 * V_156 , struct V_8 * * V_50 )
{
struct V_154 * V_149 ;
struct V_8 * V_9 ;
int V_21 ;
V_9 = F_18 ( V_12 , & V_12 -> V_152 , * V_156 ) ;
if ( F_14 ( V_9 == NULL ) )
return - V_49 ;
if ( V_9 -> V_17 != & F_85 ) {
V_21 = - V_49 ;
goto V_157;
}
V_149 = F_1 ( V_9 , struct V_154 , V_149 . V_9 ) ;
if ( V_149 -> V_4 . V_48 != V_48 ) {
V_21 = - V_52 ;
goto V_157;
}
* V_156 = V_149 -> V_149 . V_151 ;
* V_50 = V_9 ;
return 0 ;
V_157:
F_10 ( & V_9 ) ;
return V_21 ;
}
