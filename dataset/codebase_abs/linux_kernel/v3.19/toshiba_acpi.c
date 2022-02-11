static T_1 void F_1 ( T_2 * V_1 , T_2 V_2 , int V_3 )
{
* V_1 = ( * V_1 & ~ V_2 ) | ( V_2 * V_3 ) ;
}
static int F_2 ( const char * V_4 , int V_5 )
{
T_3 V_6 ;
V_6 = F_3 ( NULL , ( char * ) V_4 , V_5 ) ;
return ( V_6 == V_7 ) ? 0 : - V_8 ;
}
static T_3 F_4 ( struct V_9 * V_10 ,
const T_2 V_11 [ V_12 ] , T_2 V_13 [ V_12 ] )
{
struct V_14 V_15 ;
union V_16 V_17 [ V_12 ] ;
struct V_18 V_19 ;
union V_16 V_20 [ V_12 + 1 ] ;
T_3 V_6 ;
int V_21 ;
V_15 . V_22 = V_12 ;
V_15 . V_23 = V_17 ;
for ( V_21 = 0 ; V_21 < V_12 ; ++ V_21 ) {
V_17 [ V_21 ] . type = V_24 ;
V_17 [ V_21 ] . integer . V_3 = V_11 [ V_21 ] ;
}
V_19 . V_25 = sizeof( V_20 ) ;
V_19 . V_23 = V_20 ;
V_6 = F_5 ( V_10 -> V_26 -> V_27 ,
( char * ) V_10 -> V_28 , & V_15 ,
& V_19 ) ;
if ( ( V_6 == V_7 ) && ( V_20 -> V_29 . V_22 <= V_12 ) ) {
for ( V_21 = 0 ; V_21 < V_20 -> V_29 . V_22 ; ++ V_21 ) {
V_13 [ V_21 ] = V_20 -> V_29 . V_30 [ V_21 ] . integer . V_3 ;
}
}
return V_6 ;
}
static T_2 F_6 ( struct V_9 * V_10 , T_2 V_31 , T_2 V_32 )
{
T_2 V_11 [ V_12 ] = { V_33 , V_31 , V_32 , 0 , 0 , 0 } ;
T_2 V_13 [ V_12 ] ;
T_3 V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
return F_7 ( V_6 ) ? V_13 [ 0 ] : V_34 ;
}
static T_2 F_8 ( struct V_9 * V_10 , T_2 V_31 , T_2 * V_35 )
{
T_2 V_11 [ V_12 ] = { V_36 , V_31 , 0 , 0 , 0 , 0 } ;
T_2 V_13 [ V_12 ] ;
T_3 V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) )
return V_34 ;
* V_35 = V_13 [ 2 ] ;
return V_13 [ 0 ] ;
}
static T_2 F_10 ( struct V_9 * V_10 , T_2 V_31 , T_2 V_32 , T_2 V_37 )
{
T_2 V_11 [ V_12 ] = { V_33 , V_31 , V_32 , V_37 , 0 , 0 } ;
T_2 V_13 [ V_12 ] ;
T_3 V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
return F_7 ( V_6 ) ? V_13 [ 0 ] : V_34 ;
}
static T_2 F_11 ( struct V_9 * V_10 , T_2 V_31 , T_2 * V_35 , T_2 * V_38 )
{
T_2 V_11 [ V_12 ] = { V_36 , V_31 , * V_35 , * V_38 , 0 , 0 } ;
T_2 V_13 [ V_12 ] ;
T_3 V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) )
return V_34 ;
* V_35 = V_13 [ 2 ] ;
* V_38 = V_13 [ 3 ] ;
return V_13 [ 0 ] ;
}
static int F_12 ( struct V_9 * V_10 )
{
T_2 V_11 [ V_12 ] = { V_39 , 0 , 0 , 0 , 0 , 0 } ;
T_2 V_13 [ V_12 ] ;
T_3 V_6 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) || V_13 [ 0 ] == V_34 ) {
F_13 ( L_1 ) ;
return 0 ;
}
if ( V_13 [ 0 ] == V_40 ) {
return 1 ;
} else if ( V_13 [ 0 ] == V_41 ) {
F_14 ( L_2 ) ;
return 1 ;
} else if ( V_13 [ 0 ] == V_42 ) {
F_14 ( L_3 ) ;
}
return 0 ;
}
static void F_15 ( struct V_9 * V_10 )
{
T_2 V_11 [ V_12 ] = { V_43 , 0 , 0 , 0 , 0 , 0 } ;
T_2 V_13 [ V_12 ] ;
T_3 V_6 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) || V_13 [ 0 ] == V_34 ) {
F_13 ( L_4 ) ;
return;
}
if ( V_13 [ 0 ] == V_40 )
return;
else if ( V_13 [ 0 ] == V_44 )
F_14 ( L_5 ) ;
else if ( V_13 [ 0 ] == V_42 )
F_14 ( L_3 ) ;
}
static T_2 F_16 ( struct V_9 * V_10 , T_2 V_31 , T_2 * V_35 )
{
T_2 V_11 [ V_12 ] = { V_45 , V_31 , 0 , 0 , 0 , 0 } ;
T_2 V_13 [ V_12 ] ;
T_3 V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) )
return V_34 ;
* V_35 = V_13 [ 2 ] ;
return V_13 [ 0 ] ;
}
static T_2 F_17 ( struct V_9 * V_10 , T_2 V_31 , T_2 V_32 )
{
T_2 V_11 [ V_12 ] = { V_46 , V_31 , V_32 , 0 , 0 , 0 } ;
T_2 V_13 [ V_12 ] ;
T_3 V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
return F_7 ( V_6 ) ? V_13 [ 0 ] : V_34 ;
}
static int F_18 ( struct V_9 * V_10 )
{
T_2 V_11 [ V_12 ] = { V_45 , V_47 , 0 , 0 , 0 , 0 } ;
T_2 V_13 [ V_12 ] ;
T_3 V_6 ;
if ( ! F_12 ( V_10 ) )
return 0 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
F_15 ( V_10 ) ;
if ( F_9 ( V_6 ) || V_13 [ 0 ] == V_34 ) {
F_13 ( L_6 ) ;
return 0 ;
} else if ( V_13 [ 0 ] == V_48 ) {
F_14 ( L_7 ) ;
return 0 ;
}
return 1 ;
}
static void F_19 ( struct V_49 * V_50 ,
enum V_51 V_52 )
{
struct V_9 * V_10 = F_20 ( V_50 ,
struct V_9 , V_53 ) ;
T_2 V_54 , V_55 ;
if ( ! F_12 ( V_10 ) )
return;
V_54 = V_52 ? 1 : 0 ;
V_55 = F_17 ( V_10 , V_47 , V_54 ) ;
F_15 ( V_10 ) ;
if ( V_55 == V_34 ) {
F_13 ( L_8 ) ;
return;
} else if ( V_55 == V_48 ) {
F_14 ( L_9 ) ;
return;
}
}
static enum V_51 F_21 ( struct V_49 * V_50 )
{
struct V_9 * V_10 = F_20 ( V_50 ,
struct V_9 , V_53 ) ;
T_2 V_54 , V_55 ;
if ( ! F_12 ( V_10 ) )
return V_56 ;
V_55 = F_16 ( V_10 , V_47 , & V_54 ) ;
F_15 ( V_10 ) ;
if ( V_55 == V_34 || V_55 == V_57 ) {
F_13 ( L_8 ) ;
return V_56 ;
} else if ( V_55 == V_48 ) {
F_14 ( L_9 ) ;
return V_56 ;
}
return V_54 ? V_58 : V_56 ;
}
static int F_22 ( struct V_9 * V_10 )
{
T_2 V_11 [ V_12 ] = { V_45 , V_59 , 0 , 0 , 0 , 0 } ;
T_2 V_13 [ V_12 ] ;
T_3 V_6 ;
if ( ! F_12 ( V_10 ) )
return 0 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
F_15 ( V_10 ) ;
if ( F_9 ( V_6 ) || V_13 [ 0 ] == V_57 ) {
F_13 ( L_10 ) ;
return 0 ;
} else if ( V_13 [ 0 ] == V_48 ) {
F_14 ( L_11 ) ;
return 0 ;
}
if ( V_13 [ 3 ] == V_60 )
V_10 -> V_61 = 2 ;
else
V_10 -> V_61 = 1 ;
V_10 -> V_62 = V_13 [ 2 ] & V_63 ;
V_10 -> V_64 = V_13 [ 2 ] >> V_65 ;
return 1 ;
}
static int F_23 ( struct V_9 * V_10 , T_2 time )
{
T_2 V_55 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
V_55 = F_17 ( V_10 , V_59 , time ) ;
F_15 ( V_10 ) ;
if ( V_55 == V_34 || V_55 == V_57 ) {
F_13 ( L_12 ) ;
return - V_8 ;
} else if ( V_55 == V_48 ) {
F_14 ( L_13 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_24 ( struct V_9 * V_10 , T_2 * time )
{
T_2 V_55 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
V_55 = F_16 ( V_10 , V_59 , time ) ;
F_15 ( V_10 ) ;
if ( V_55 == V_34 || V_55 == V_57 ) {
F_13 ( L_14 ) ;
return - V_8 ;
} else if ( V_55 == V_48 ) {
F_14 ( L_13 ) ;
return - V_66 ;
}
return 0 ;
}
static enum V_51 F_25 ( struct V_49 * V_50 )
{
struct V_9 * V_10 = F_20 ( V_50 ,
struct V_9 , V_67 ) ;
T_2 V_54 , V_55 ;
V_55 = F_8 ( V_10 , V_68 , & V_54 ) ;
if ( V_55 == V_34 || V_55 == V_57 ) {
F_13 ( L_15 ) ;
return V_56 ;
} else if ( V_55 == V_48 ) {
F_14 ( L_16 ) ;
return V_56 ;
}
return V_54 ? V_58 : V_56 ;
}
static void F_26 ( struct V_49 * V_50 ,
enum V_51 V_52 )
{
struct V_9 * V_10 = F_20 ( V_50 ,
struct V_9 , V_67 ) ;
T_2 V_54 , V_55 ;
V_54 = V_52 ? 1 : 0 ;
V_55 = F_6 ( V_10 , V_68 , V_54 ) ;
if ( V_55 == V_34 || V_55 == V_57 ) {
F_13 ( L_17 ) ;
return;
} else if ( V_55 == V_48 ) {
F_14 ( L_16 ) ;
return;
}
}
static int F_27 ( struct V_9 * V_10 , T_2 V_54 )
{
T_2 V_55 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
V_55 = F_17 ( V_10 , V_69 , V_54 ) ;
F_15 ( V_10 ) ;
if ( V_55 == V_34 ) {
F_13 ( L_18 ) ;
return - V_8 ;
} else if ( V_55 == V_48 ) {
return - V_66 ;
}
return 0 ;
}
static int F_28 ( struct V_9 * V_10 , T_2 * V_54 )
{
T_2 V_55 ;
if ( ! F_12 ( V_10 ) )
return - V_8 ;
V_55 = F_16 ( V_10 , V_69 , V_54 ) ;
F_15 ( V_10 ) ;
if ( V_55 == V_34 ) {
F_13 ( L_19 ) ;
return - V_8 ;
} else if ( V_55 == V_48 ) {
return - V_66 ;
}
return 0 ;
}
static int F_29 ( struct V_9 * V_10 )
{
T_3 V_6 ;
T_2 V_11 [ V_12 ] = { V_36 , V_70 , 0 , 1 , 0 , 0 } ;
T_2 V_13 [ V_12 ] ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) || V_13 [ 0 ] == V_57 ) {
F_14 ( L_20 ) ;
return 0 ;
}
return 1 ;
}
static enum V_51 F_30 ( struct V_49 * V_50 )
{
struct V_9 * V_10 = F_20 ( V_50 ,
struct V_9 , V_71 ) ;
T_2 V_11 [ V_12 ] = { V_36 , V_70 , 0 , 1 , 0 , 0 } ;
T_2 V_13 [ V_12 ] ;
T_3 V_6 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) || V_13 [ 0 ] == V_57 ) {
F_13 ( L_20 ) ;
return V_56 ;
}
return V_13 [ 2 ] ? V_58 : V_56 ;
}
static void F_31 ( struct V_49 * V_50 ,
enum V_51 V_52 )
{
struct V_9 * V_10 = F_20 ( V_50 ,
struct V_9 , V_71 ) ;
T_2 V_11 [ V_12 ] = { V_33 , V_70 , 0 , 1 , 0 , 0 } ;
T_2 V_13 [ V_12 ] ;
T_3 V_6 ;
V_11 [ 2 ] = ( V_52 ) ? 1 : 0 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) || V_13 [ 0 ] == V_57 ) {
F_13 ( L_21 ) ;
return;
}
}
static int F_32 ( struct V_9 * V_10 )
{
T_2 V_11 [ V_12 ] = { V_36 , V_72 , 0 , 0 , 0 , 0 } ;
T_2 V_13 [ V_12 ] ;
T_3 V_6 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) || V_13 [ 0 ] == V_57 ) {
F_13 ( L_22 ) ;
return - V_8 ;
} else if ( V_13 [ 0 ] == V_73 ||
V_13 [ 0 ] == V_74 ) {
F_13 ( L_23 ) ;
return - V_8 ;
} else if ( V_13 [ 0 ] == V_48 ) {
F_14 ( L_24 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_33 ( struct V_9 * V_10 ,
T_2 * V_75 , T_2 * V_76 )
{
T_2 V_11 [ V_12 ] = { V_36 , V_77 , 0 , 1 , 0 , 0 } ;
T_2 V_13 [ V_12 ] ;
T_3 V_6 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_9 ( V_6 ) || V_13 [ 0 ] == V_57 ) {
F_13 ( L_22 ) ;
return - V_8 ;
}
* V_75 = V_13 [ 2 ] ;
* V_76 = V_13 [ 4 ] ;
return 0 ;
}
static T_2 F_34 ( struct V_9 * V_10 , bool * V_78 )
{
T_2 V_79 ;
T_2 V_3 , V_80 ;
V_3 = 0 ;
V_80 = 0 ;
V_79 = F_11 ( V_10 , V_81 , & V_3 , & V_80 ) ;
if ( V_79 == V_82 )
* V_78 = ( V_3 & V_83 ) ? true : false ;
return V_79 ;
}
static T_2 F_35 ( struct V_9 * V_10 , bool * V_84 )
{
T_2 V_79 ;
T_2 V_3 , V_80 ;
V_3 = 0 ;
V_80 = 0x0001 ;
V_79 = F_11 ( V_10 , V_81 , & V_3 , & V_80 ) ;
* V_84 = V_3 & V_85 ;
return V_79 ;
}
static int F_36 ( void * V_86 , bool V_87 )
{
struct V_9 * V_10 = V_86 ;
T_2 V_88 , V_89 ;
T_2 V_3 ;
int V_90 ;
bool V_84 ;
V_3 = ( V_87 == false ) ;
F_37 ( & V_10 -> V_91 ) ;
if ( F_35 ( V_10 , & V_84 ) != V_82 ) {
V_90 = - V_8 ;
goto V_13;
}
if ( ! V_84 ) {
V_90 = 0 ;
goto V_13;
}
V_88 = F_10 ( V_10 , V_81 , V_3 , V_92 ) ;
V_89 = F_10 ( V_10 , V_81 , V_3 , V_93 ) ;
if ( V_88 != V_82 || V_89 != V_82 )
V_90 = - V_8 ;
else
V_90 = 0 ;
V_13:
F_38 ( & V_10 -> V_91 ) ;
return V_90 ;
}
static void F_39 ( struct V_94 * V_94 , void * V_86 )
{
bool V_95 ;
bool V_3 ;
T_2 V_79 ;
struct V_9 * V_10 = V_86 ;
F_37 ( & V_10 -> V_91 ) ;
V_79 = F_35 ( V_10 , & V_3 ) ;
if ( V_79 != V_82 ) {
F_38 ( & V_10 -> V_91 ) ;
return;
}
V_95 = V_3 ;
F_38 ( & V_10 -> V_91 ) ;
if ( F_40 ( V_94 , ! V_95 ) )
F_36 ( V_86 , true ) ;
}
static int F_41 ( struct V_9 * V_10 , bool * V_96 )
{
T_2 V_79 ;
T_2 V_6 ;
V_79 = F_8 ( V_10 , V_97 , & V_6 ) ;
* V_96 = ! V_6 ;
return V_79 == V_82 ? 0 : - V_8 ;
}
static int F_42 ( struct V_9 * V_10 , bool V_98 )
{
T_2 V_79 ;
T_2 V_3 = ! V_98 ;
V_79 = F_6 ( V_10 , V_97 , V_3 ) ;
return V_79 == V_82 ? 0 : - V_8 ;
}
static int F_43 ( struct V_9 * V_10 )
{
T_2 V_79 ;
T_2 V_3 ;
int V_52 = 0 ;
if ( V_10 -> V_99 ) {
bool V_96 ;
int V_100 = F_41 ( V_10 , & V_96 ) ;
if ( V_100 )
return V_100 ;
if ( V_96 )
return 0 ;
V_52 ++ ;
}
V_79 = F_8 ( V_10 , V_101 , & V_3 ) ;
if ( V_79 == V_82 )
return V_52 + ( V_3 >> V_102 ) ;
return - V_8 ;
}
static int F_44 ( struct V_103 * V_104 )
{
struct V_9 * V_10 = F_45 ( V_104 ) ;
return F_43 ( V_10 ) ;
}
static int F_46 ( struct V_105 * V_106 , void * V_107 )
{
struct V_9 * V_10 = V_106 -> V_108 ;
int V_3 ;
int V_109 ;
if ( ! V_10 -> V_110 )
return - V_66 ;
V_109 = V_10 -> V_110 -> V_111 . V_112 + 1 ;
V_3 = F_44 ( V_10 -> V_110 ) ;
if ( V_3 >= 0 ) {
F_47 ( V_106 , L_25 , V_3 ) ;
F_47 ( V_106 , L_26 , V_109 ) ;
return 0 ;
}
F_13 ( L_27 ) ;
return - V_8 ;
}
static int F_48 ( struct V_113 * V_113 , struct V_114 * V_114 )
{
return F_49 ( V_114 , F_46 , F_50 ( V_113 ) ) ;
}
static int F_51 ( struct V_9 * V_10 , int V_3 )
{
T_2 V_79 ;
if ( V_10 -> V_99 ) {
bool V_98 = ! V_3 ;
int V_100 = F_42 ( V_10 , V_98 ) ;
if ( V_100 )
return V_100 ;
if ( V_3 )
V_3 -- ;
}
V_3 = V_3 << V_102 ;
V_79 = F_6 ( V_10 , V_101 , V_3 ) ;
return V_79 == V_82 ? 0 : - V_8 ;
}
static int F_52 ( struct V_103 * V_104 )
{
struct V_9 * V_10 = F_45 ( V_104 ) ;
return F_51 ( V_10 , V_104 -> V_111 . V_52 ) ;
}
static T_4 F_53 ( struct V_114 * V_114 , const char T_5 * V_115 ,
T_6 V_22 , T_7 * V_116 )
{
struct V_9 * V_10 = F_50 ( F_54 ( V_114 ) ) ;
char V_117 [ 42 ] ;
T_6 V_118 ;
int V_3 ;
int V_100 ;
int V_109 = V_10 -> V_110 -> V_111 . V_112 + 1 ;
V_118 = F_55 ( V_22 , sizeof( V_117 ) - 1 ) ;
if ( F_56 ( V_117 , V_115 , V_118 ) )
return - V_119 ;
V_117 [ V_118 ] = '\0' ;
if ( sscanf ( V_117 , L_28 , & V_3 ) == 1 &&
V_3 >= 0 && V_3 < V_109 ) {
V_100 = F_51 ( V_10 , V_3 ) ;
if ( V_100 == 0 )
V_100 = V_22 ;
} else {
V_100 = - V_120 ;
}
return V_100 ;
}
static int F_57 ( struct V_9 * V_10 , T_2 * V_6 )
{
T_2 V_79 ;
V_79 = F_8 ( V_10 , V_121 , V_6 ) ;
return V_79 == V_82 ? 0 : - V_8 ;
}
static int F_58 ( struct V_105 * V_106 , void * V_107 )
{
struct V_9 * V_10 = V_106 -> V_108 ;
T_2 V_3 ;
int V_100 ;
V_100 = F_57 ( V_10 , & V_3 ) ;
if ( ! V_100 ) {
int V_122 = ( V_3 & V_123 ) ? 1 : 0 ;
int V_124 = ( V_3 & V_125 ) ? 1 : 0 ;
int V_126 = ( V_3 & V_127 ) ? 1 : 0 ;
F_47 ( V_106 , L_29 , V_122 ) ;
F_47 ( V_106 , L_30 , V_124 ) ;
F_47 ( V_106 , L_31 , V_126 ) ;
}
return V_100 ;
}
static int F_59 ( struct V_113 * V_113 , struct V_114 * V_114 )
{
return F_49 ( V_114 , F_58 , F_50 ( V_113 ) ) ;
}
static T_4 F_60 ( struct V_114 * V_114 , const char T_5 * V_115 ,
T_6 V_22 , T_7 * V_116 )
{
struct V_9 * V_10 = F_50 ( F_54 ( V_114 ) ) ;
char * V_117 , * V_128 ;
int V_100 ;
int V_3 ;
int V_129 = V_22 ;
int V_130 = - 1 ;
int V_131 = - 1 ;
int V_132 = - 1 ;
T_2 V_133 ;
V_117 = F_61 ( V_22 + 1 , V_134 ) ;
if ( ! V_117 )
return - V_135 ;
if ( F_56 ( V_117 , V_115 , V_22 ) ) {
F_62 ( V_117 ) ;
return - V_119 ;
}
V_117 [ V_22 ] = '\0' ;
V_128 = V_117 ;
while ( V_129 ) {
if ( sscanf ( V_128 , L_32 , & V_3 ) == 1 )
V_130 = V_3 & 1 ;
else if ( sscanf ( V_128 , L_33 , & V_3 ) == 1 )
V_131 = V_3 & 1 ;
else if ( sscanf ( V_128 , L_34 , & V_3 ) == 1 )
V_132 = V_3 & 1 ;
do {
++ V_128 ;
-- V_129 ;
}
while ( V_129 && * ( V_128 - 1 ) != ';' );
}
F_62 ( V_117 ) ;
V_100 = F_57 ( V_10 , & V_133 ) ;
if ( ! V_100 ) {
unsigned int V_136 = V_133 ;
if ( V_130 != - 1 )
F_1 ( & V_136 , V_123 , V_130 ) ;
if ( V_131 != - 1 )
F_1 ( & V_136 , V_125 , V_131 ) ;
if ( V_132 != - 1 )
F_1 ( & V_136 , V_127 , V_132 ) ;
if ( V_136 != V_133 )
V_100 = F_2 ( V_137 , V_136 ) ;
}
return V_100 ? V_100 : V_22 ;
}
static int F_63 ( struct V_9 * V_10 , T_2 * V_6 )
{
T_2 V_79 ;
V_79 = F_8 ( V_10 , V_138 , V_6 ) ;
return V_79 == V_82 ? 0 : - V_8 ;
}
static int F_64 ( struct V_105 * V_106 , void * V_107 )
{
struct V_9 * V_10 = V_106 -> V_108 ;
int V_100 ;
T_2 V_3 ;
V_100 = F_63 ( V_10 , & V_3 ) ;
if ( ! V_100 ) {
F_47 ( V_106 , L_35 , ( V_3 > 0 ) ) ;
F_47 ( V_106 , L_36 , V_10 -> V_139 ) ;
}
return V_100 ;
}
static int F_65 ( struct V_113 * V_113 , struct V_114 * V_114 )
{
return F_49 ( V_114 , F_64 , F_50 ( V_113 ) ) ;
}
static T_4 F_66 ( struct V_114 * V_114 , const char T_5 * V_115 ,
T_6 V_22 , T_7 * V_116 )
{
struct V_9 * V_10 = F_50 ( F_54 ( V_114 ) ) ;
char V_117 [ 42 ] ;
T_6 V_118 ;
int V_3 ;
T_2 V_79 ;
V_118 = F_55 ( V_22 , sizeof( V_117 ) - 1 ) ;
if ( F_56 ( V_117 , V_115 , V_118 ) )
return - V_119 ;
V_117 [ V_118 ] = '\0' ;
if ( sscanf ( V_117 , L_37 , & V_3 ) == 1 &&
V_3 >= 0 && V_3 <= 1 ) {
V_79 = F_6 ( V_10 , V_138 , V_3 ) ;
if ( V_79 != V_82 )
return - V_8 ;
else
V_10 -> V_139 = V_3 ;
} else {
return - V_120 ;
}
return V_22 ;
}
static int F_67 ( struct V_105 * V_106 , void * V_107 )
{
struct V_9 * V_10 = V_106 -> V_108 ;
T_2 V_79 ;
T_2 V_3 ;
if ( ! V_10 -> V_140 && V_10 -> V_141 ) {
V_79 = F_8 ( V_10 , V_142 , & V_3 ) ;
if ( V_79 == V_82 ) {
V_10 -> V_140 = 1 ;
V_10 -> V_143 = V_3 ;
} else if ( V_79 == V_144 ) {
} else if ( V_79 == V_48 ) {
V_79 = F_6 ( V_10 , V_142 , 1 ) ;
F_68 ( L_38 ) ;
} else {
F_13 ( L_39 ) ;
return - V_8 ;
}
}
F_47 ( V_106 , L_40 , V_10 -> V_140 ) ;
F_47 ( V_106 , L_41 , V_10 -> V_143 ) ;
return 0 ;
}
static int F_69 ( struct V_113 * V_113 , struct V_114 * V_114 )
{
return F_49 ( V_114 , F_67 , F_50 ( V_113 ) ) ;
}
static T_4 F_70 ( struct V_114 * V_114 , const char T_5 * V_115 ,
T_6 V_22 , T_7 * V_116 )
{
struct V_9 * V_10 = F_50 ( F_54 ( V_114 ) ) ;
char V_117 [ 42 ] ;
T_6 V_118 ;
int V_3 ;
V_118 = F_55 ( V_22 , sizeof( V_117 ) - 1 ) ;
if ( F_56 ( V_117 , V_115 , V_118 ) )
return - V_119 ;
V_117 [ V_118 ] = '\0' ;
if ( sscanf ( V_117 , L_42 , & V_3 ) == 1 && V_3 == 0 ) {
V_10 -> V_140 = 0 ;
} else {
return - V_120 ;
}
return V_22 ;
}
static int F_71 ( struct V_105 * V_106 , void * V_107 )
{
F_47 ( V_106 , L_43 , V_145 ) ;
F_47 ( V_106 , L_44 , V_146 ) ;
return 0 ;
}
static int F_72 ( struct V_113 * V_113 , struct V_114 * V_114 )
{
return F_49 ( V_114 , F_71 , F_50 ( V_113 ) ) ;
}
static void F_73 ( struct V_9 * V_10 )
{
if ( V_10 -> V_110 )
F_74 ( L_45 , V_147 | V_148 , V_149 ,
& V_150 , V_10 ) ;
if ( V_10 -> V_151 )
F_74 ( L_46 , V_147 | V_148 , V_149 ,
& V_152 , V_10 ) ;
if ( V_10 -> V_153 )
F_74 ( L_47 , V_147 | V_148 , V_149 ,
& V_154 , V_10 ) ;
if ( V_10 -> V_155 )
F_74 ( L_48 , V_147 | V_148 , V_149 ,
& V_156 , V_10 ) ;
F_74 ( L_49 , V_147 , V_149 ,
& V_157 , V_10 ) ;
}
static void F_75 ( struct V_9 * V_10 )
{
if ( V_10 -> V_110 )
F_76 ( L_45 , V_149 ) ;
if ( V_10 -> V_151 )
F_76 ( L_46 , V_149 ) ;
if ( V_10 -> V_153 )
F_76 ( L_47 , V_149 ) ;
if ( V_10 -> V_155 )
F_76 ( L_48 , V_149 ) ;
F_76 ( L_49 , V_149 ) ;
}
static T_4 F_77 ( struct V_158 * V_10 ,
struct V_159 * V_160 ,
const char * V_115 , T_6 V_22 )
{
struct V_9 * V_161 = F_78 ( V_10 ) ;
int V_162 ;
int time ;
int V_100 ;
V_100 = F_79 ( V_115 , 0 , & V_162 ) ;
if ( V_100 )
return V_100 ;
if ( V_161 -> V_61 == 1 ) {
if ( V_162 != V_163 && V_162 != V_164 )
return - V_120 ;
} else if ( V_161 -> V_61 == 2 ) {
if ( V_162 != V_164 && V_162 != V_165 &&
V_162 != V_166 )
return - V_120 ;
}
if ( V_161 -> V_62 != V_162 ) {
time = V_161 -> V_64 << V_65 ;
if ( V_161 -> V_61 == 1 ) {
time |= V_161 -> V_62 ;
} else if ( V_161 -> V_61 == 2 ) {
time |= V_162 ;
}
V_100 = F_23 ( V_161 , time ) ;
if ( V_100 )
return V_100 ;
V_161 -> V_62 = V_162 ;
}
return V_22 ;
}
static T_4 F_80 ( struct V_158 * V_10 ,
struct V_159 * V_160 ,
char * V_115 )
{
struct V_9 * V_161 = F_78 ( V_10 ) ;
T_2 time ;
if ( F_24 ( V_161 , & time ) < 0 )
return - V_8 ;
return sprintf ( V_115 , L_50 , time & V_63 ) ;
}
static T_4 F_81 ( struct V_158 * V_10 ,
struct V_159 * V_160 ,
char * V_115 )
{
struct V_9 * V_161 = F_78 ( V_10 ) ;
return sprintf ( V_115 , L_51 , V_161 -> V_61 ) ;
}
static T_4 F_82 ( struct V_158 * V_10 ,
struct V_159 * V_160 ,
char * V_115 )
{
struct V_9 * V_161 = F_78 ( V_10 ) ;
if ( V_161 -> V_61 == 1 )
return sprintf ( V_115 , L_52 ,
V_163 , V_164 ) ;
return sprintf ( V_115 , L_53 ,
V_164 , V_165 , V_166 ) ;
}
static T_4 F_83 ( struct V_158 * V_10 ,
struct V_159 * V_160 ,
const char * V_115 , T_6 V_22 )
{
struct V_9 * V_161 = F_78 ( V_10 ) ;
int time ;
int V_100 ;
V_100 = F_79 ( V_115 , 0 , & time ) ;
if ( V_100 )
return V_100 ;
if ( V_161 -> V_61 == 1 ) {
if ( time < 0 || time > 60 )
return - V_120 ;
} else if ( V_161 -> V_61 == 2 ) {
if ( time < 1 || time > 60 )
return - V_120 ;
}
if ( V_161 -> V_64 != time ) {
time = time << V_65 ;
if ( V_161 -> V_61 == 1 )
time |= V_163 ;
else if ( V_161 -> V_61 == 2 )
time |= V_164 ;
V_100 = F_23 ( V_161 , time ) ;
if ( V_100 )
return V_100 ;
V_161 -> V_64 = time >> V_65 ;
}
return V_22 ;
}
static T_4 F_84 ( struct V_158 * V_10 ,
struct V_159 * V_160 ,
char * V_115 )
{
struct V_9 * V_161 = F_78 ( V_10 ) ;
T_2 time ;
if ( F_24 ( V_161 , & time ) < 0 )
return - V_8 ;
return sprintf ( V_115 , L_50 , time >> V_65 ) ;
}
static T_4 F_85 ( struct V_158 * V_10 ,
struct V_159 * V_160 ,
const char * V_115 , T_6 V_22 )
{
struct V_9 * V_161 = F_78 ( V_10 ) ;
int V_54 ;
int V_100 ;
V_100 = F_79 ( V_115 , 0 , & V_54 ) ;
if ( V_100 )
return V_100 ;
if ( V_54 != 0 && V_54 != 1 )
return - V_120 ;
V_100 = F_27 ( V_161 , V_54 ) ;
if ( V_100 )
return V_100 ;
return V_22 ;
}
static T_4 F_86 ( struct V_158 * V_10 ,
struct V_159 * V_160 , char * V_115 )
{
struct V_9 * V_161 = F_78 ( V_10 ) ;
T_2 V_54 ;
int V_100 ;
V_100 = F_28 ( V_161 , & V_54 ) ;
if ( V_100 < 0 )
return V_100 ;
return sprintf ( V_115 , L_50 , V_54 ) ;
}
static T_4 F_87 ( struct V_158 * V_10 ,
struct V_159 * V_160 , char * V_115 )
{
struct V_9 * V_161 = F_78 ( V_10 ) ;
T_2 V_167 , V_168 , V_169 ;
T_8 V_170 , V_171 , V_76 ;
int V_100 ;
V_167 = V_168 = 0 ;
V_100 = F_33 ( V_161 , & V_167 , & V_168 ) ;
if ( V_100 < 0 )
return V_100 ;
V_170 = V_167 & V_172 ;
V_169 = V_167 >> V_65 ;
V_171 = V_169 & V_172 ;
V_76 = V_168 & V_172 ;
return sprintf ( V_115 , L_54 , V_170 , V_171 , V_76 ) ;
}
static T_9 F_88 ( struct V_173 * V_174 ,
struct V_175 * V_160 , int V_176 )
{
struct V_158 * V_10 = F_20 ( V_174 , struct V_158 , V_174 ) ;
struct V_9 * V_177 = F_78 ( V_10 ) ;
bool V_178 = true ;
if ( V_160 == & V_179 . V_160 )
V_178 = ( V_177 -> V_180 ) ? true : false ;
else if ( V_160 == & V_181 . V_160 )
V_178 = ( V_177 -> V_62 == V_164 ) ? true : false ;
else if ( V_160 == & V_182 . V_160 )
V_178 = ( V_177 -> V_183 ) ? true : false ;
else if ( V_160 == & V_184 . V_160 )
V_178 = ( V_177 -> V_185 ) ? true : false ;
return V_178 ? V_160 -> V_162 : 0 ;
}
static int F_89 ( struct V_9 * V_10 )
{
T_3 V_6 ;
T_2 V_55 ;
V_6 = F_5 ( V_10 -> V_26 -> V_27 ,
L_55 , NULL , NULL ) ;
if ( F_9 ( V_6 ) )
return - V_66 ;
V_55 = F_6 ( V_10 , V_186 , V_187 ) ;
if ( V_55 == V_34 )
return - V_8 ;
else if ( V_55 == V_48 )
return - V_66 ;
return 0 ;
}
static bool F_90 ( unsigned char V_86 , unsigned char V_188 ,
struct V_189 * V_190 )
{
if ( V_188 & V_191 )
return false ;
if ( F_91 ( V_86 == 0xe0 ) )
return false ;
if ( ( V_86 & 0x7f ) == V_192 ) {
F_92 ( & V_193 -> V_194 ) ;
return true ;
}
return false ;
}
static void F_93 ( struct V_195 * V_196 )
{
T_10 V_197 = F_94 () ;
T_3 V_6 ;
if ( ! V_197 )
return;
V_6 = F_5 ( V_197 , L_56 , NULL , NULL ) ;
if ( F_9 ( V_6 ) )
F_13 ( L_57 ) ;
}
static int F_95 ( struct V_9 * V_10 )
{
unsigned long long V_3 ;
T_3 V_6 ;
V_6 = F_96 ( V_10 -> V_26 -> V_27 , L_58 ,
NULL , & V_3 ) ;
if ( F_9 ( V_6 ) ) {
F_13 ( L_59 ) ;
return - V_8 ;
}
return V_3 ;
}
static void F_97 ( struct V_9 * V_10 ,
int V_198 )
{
if ( V_198 == 0x100 )
return;
if ( V_198 & 0x80 )
return;
if ( ! F_98 ( V_10 -> V_155 , V_198 , 1 , true ) )
F_14 ( L_60 , V_198 ) ;
}
static void F_99 ( struct V_9 * V_10 )
{
T_2 V_79 , V_3 ;
int V_199 = 3 ;
int V_198 ;
if ( V_10 -> V_200 ) {
V_198 = F_95 ( V_10 ) ;
if ( V_198 < 0 )
F_13 ( L_61 ) ;
else if ( V_198 != 0 )
F_97 ( V_10 , V_198 ) ;
} else if ( V_10 -> V_141 ) {
do {
V_79 = F_8 ( V_10 , V_142 , & V_3 ) ;
switch ( V_79 ) {
case V_82 :
F_97 ( V_10 , ( int ) V_3 ) ;
break;
case V_48 :
V_79 =
F_6 ( V_10 , V_142 , 1 ) ;
F_68 ( L_38 ) ;
default:
V_199 -- ;
break;
}
} while ( V_199 && V_79 != V_144 );
}
}
static int F_100 ( struct V_9 * V_10 )
{
T_10 V_197 ;
int error ;
T_2 V_79 ;
const struct V_201 * V_202 = V_203 ;
V_10 -> V_155 = F_101 () ;
if ( ! V_10 -> V_155 )
return - V_135 ;
V_10 -> V_155 -> V_204 = L_62 ;
V_10 -> V_155 -> V_205 = L_63 ;
V_10 -> V_155 -> V_206 . V_207 = V_208 ;
if ( F_102 ( V_209 ) )
V_202 = V_210 ;
error = F_103 ( V_10 -> V_155 , V_202 , NULL ) ;
if ( error )
goto V_211;
V_197 = F_94 () ;
if ( V_197 && F_104 ( V_197 , L_56 ) ) {
F_105 ( & V_10 -> V_194 , F_93 ) ;
error = F_106 ( F_90 ) ;
if ( error ) {
F_13 ( L_64 ) ;
goto V_212;
}
V_10 -> V_213 = 1 ;
}
if ( F_104 ( V_10 -> V_26 -> V_27 , L_58 ) )
V_10 -> V_200 = 1 ;
else {
V_79 = F_6 ( V_10 , V_142 , 1 ) ;
if ( V_79 == V_82 )
V_10 -> V_141 = 1 ;
}
if ( ! V_10 -> V_200 && ! V_10 -> V_141 ) {
F_107 ( L_65 ) ;
goto V_214;
}
error = F_89 ( V_10 ) ;
if ( error ) {
F_14 ( L_66 ) ;
goto V_214;
}
error = F_108 ( V_10 -> V_155 ) ;
if ( error ) {
F_14 ( L_67 ) ;
goto V_214;
}
return 0 ;
V_214:
if ( V_10 -> V_213 )
F_109 ( F_90 ) ;
V_212:
F_110 ( V_10 -> V_155 ) ;
V_211:
F_111 ( V_10 -> V_155 ) ;
V_10 -> V_155 = NULL ;
return error ;
}
static int F_112 ( struct V_9 * V_10 )
{
struct V_215 V_111 ;
int V_52 ;
int V_100 ;
bool V_96 ;
V_52 = F_43 ( V_10 ) ;
if ( V_52 < 0 )
return 0 ;
V_100 = F_51 ( V_10 , V_52 ) ;
if ( V_100 ) {
F_113 ( L_68 ) ;
return 0 ;
}
V_100 = F_41 ( V_10 , & V_96 ) ;
V_10 -> V_99 = ! V_100 ;
memset ( & V_111 , 0 , sizeof( V_111 ) ) ;
V_111 . type = V_216 ;
V_111 . V_112 = V_217 - 1 ;
if ( V_10 -> V_99 )
V_111 . V_112 ++ ;
V_10 -> V_110 = F_114 ( L_69 ,
& V_10 -> V_26 -> V_10 ,
V_10 ,
& V_218 ,
& V_111 ) ;
if ( F_115 ( V_10 -> V_110 ) ) {
V_100 = F_116 ( V_10 -> V_110 ) ;
F_13 ( L_70 ) ;
V_10 -> V_110 = NULL ;
return V_100 ;
}
V_10 -> V_110 -> V_111 . V_52 = V_52 ;
return 0 ;
}
static int F_117 ( struct V_219 * V_26 )
{
struct V_9 * V_10 = F_118 ( V_26 ) ;
F_75 ( V_10 ) ;
if ( V_10 -> V_220 )
F_119 ( & V_10 -> V_26 -> V_10 . V_174 ,
& V_221 ) ;
if ( V_10 -> V_213 ) {
F_109 ( F_90 ) ;
F_120 ( & V_10 -> V_194 ) ;
}
if ( V_10 -> V_155 ) {
F_121 ( V_10 -> V_155 ) ;
F_110 ( V_10 -> V_155 ) ;
}
if ( V_10 -> V_222 ) {
F_122 ( V_10 -> V_222 ) ;
F_123 ( V_10 -> V_222 ) ;
}
F_124 ( V_10 -> V_110 ) ;
if ( V_10 -> V_223 )
F_125 ( & V_10 -> V_53 ) ;
if ( V_10 -> V_224 )
F_125 ( & V_10 -> V_67 ) ;
if ( V_10 -> V_225 )
F_125 ( & V_10 -> V_71 ) ;
if ( V_193 )
V_193 = NULL ;
F_62 ( V_10 ) ;
return 0 ;
}
static const char * F_126 ( T_10 V_27 )
{
if ( F_104 ( V_27 , L_71 ) )
return L_71 ;
if ( F_104 ( V_27 , L_72 ) )
return L_72 ;
return NULL ;
}
static int F_127 ( struct V_219 * V_26 )
{
struct V_9 * V_10 ;
const char * V_226 ;
T_2 V_227 ;
bool V_228 ;
int V_100 = 0 ;
if ( V_193 )
return - V_229 ;
F_14 ( L_73 ,
V_145 ) ;
V_226 = F_126 ( V_26 -> V_27 ) ;
if ( ! V_226 ) {
F_13 ( L_74 ) ;
return - V_66 ;
}
V_10 = F_128 ( sizeof( * V_10 ) , V_134 ) ;
if ( ! V_10 )
return - V_135 ;
V_10 -> V_26 = V_26 ;
V_10 -> V_28 = V_226 ;
V_26 -> V_230 = V_10 ;
F_129 ( & V_26 -> V_10 , V_10 ) ;
if ( F_100 ( V_10 ) )
F_14 ( L_75 ) ;
F_130 ( & V_10 -> V_91 ) ;
V_100 = F_112 ( V_10 ) ;
if ( V_100 )
goto error;
if ( F_34 ( V_10 , & V_228 ) == V_82 && V_228 ) {
V_10 -> V_222 = F_131 ( L_76 ,
& V_26 -> V_10 ,
V_231 ,
& V_232 ,
V_10 ) ;
if ( ! V_10 -> V_222 ) {
F_13 ( L_77 ) ;
V_100 = - V_135 ;
goto error;
}
V_100 = F_132 ( V_10 -> V_222 ) ;
if ( V_100 ) {
F_13 ( L_78 ) ;
F_123 ( V_10 -> V_222 ) ;
goto error;
}
}
if ( F_18 ( V_10 ) ) {
V_10 -> V_53 . V_204 = L_79 ;
V_10 -> V_53 . V_112 = 1 ;
V_10 -> V_53 . V_233 = F_19 ;
V_10 -> V_53 . V_234 = F_21 ;
if ( ! F_133 ( & V_26 -> V_10 , & V_10 -> V_53 ) )
V_10 -> V_223 = 1 ;
}
if ( F_29 ( V_10 ) ) {
V_10 -> V_71 . V_204 = L_80 ;
V_10 -> V_71 . V_112 = 1 ;
V_10 -> V_71 . V_233 = F_31 ;
V_10 -> V_71 . V_234 = F_30 ;
if ( ! F_133 ( & V_10 -> V_26 -> V_10 , & V_10 -> V_71 ) )
V_10 -> V_225 = 1 ;
}
V_10 -> V_180 = F_22 ( V_10 ) ;
if ( V_10 -> V_180 && V_10 -> V_62 == V_163 ) {
V_10 -> V_67 . V_204 = L_81 ;
V_10 -> V_67 . V_112 = 1 ;
V_10 -> V_67 . V_233 = F_26 ;
V_10 -> V_67 . V_234 = F_25 ;
if ( ! F_133 ( & V_10 -> V_26 -> V_10 , & V_10 -> V_67 ) )
V_10 -> V_224 = 1 ;
}
V_100 = F_28 ( V_10 , & V_227 ) ;
V_10 -> V_183 = ! V_100 ;
V_100 = F_32 ( V_10 ) ;
V_10 -> V_185 = ! V_100 ;
V_100 = F_57 ( V_10 , & V_227 ) ;
V_10 -> V_151 = ! V_100 ;
V_100 = F_63 ( V_10 , & V_227 ) ;
V_10 -> V_153 = ! V_100 ;
V_100 = F_134 ( & V_10 -> V_26 -> V_10 . V_174 ,
& V_221 ) ;
if ( V_100 ) {
V_10 -> V_220 = 0 ;
goto error;
}
V_10 -> V_220 = ! V_100 ;
F_73 ( V_10 ) ;
V_193 = V_10 ;
return 0 ;
error:
F_117 ( V_26 ) ;
return V_100 ;
}
static void F_135 ( struct V_219 * V_26 , T_2 V_235 )
{
struct V_9 * V_10 = F_118 ( V_26 ) ;
int V_100 ;
switch ( V_235 ) {
case 0x80 :
F_99 ( V_10 ) ;
break;
case 0x92 :
V_100 = F_136 ( & V_26 -> V_10 . V_174 ,
& V_221 ) ;
if ( V_100 )
F_13 ( L_82 ) ;
break;
case 0x81 :
case 0x82 :
case 0x83 :
case 0x8c :
case 0x8e :
case 0x8f :
case 0x90 :
default:
F_14 ( L_83 , V_235 ) ;
break;
}
}
static int F_137 ( struct V_158 * V_158 )
{
struct V_9 * V_10 = F_118 ( F_138 ( V_158 ) ) ;
T_2 V_55 ;
if ( V_10 -> V_155 )
V_55 = F_6 ( V_10 , V_186 , V_236 ) ;
return 0 ;
}
static int F_139 ( struct V_158 * V_158 )
{
struct V_9 * V_10 = F_118 ( F_138 ( V_158 ) ) ;
int error ;
if ( V_10 -> V_155 ) {
error = F_89 ( V_10 ) ;
if ( error )
F_14 ( L_84 ) ;
}
return 0 ;
}
static int T_11 F_140 ( void )
{
int V_100 ;
if ( F_141 ( V_237 ) )
return - V_66 ;
V_149 = F_142 ( V_238 , V_239 ) ;
if ( ! V_149 ) {
F_13 ( L_85 V_238 L_86 ) ;
return - V_66 ;
}
V_100 = F_143 ( & V_240 ) ;
if ( V_100 ) {
F_13 ( L_87 , V_100 ) ;
F_76 ( V_238 , V_239 ) ;
}
return V_100 ;
}
static void T_12 F_144 ( void )
{
F_145 ( & V_240 ) ;
if ( V_149 )
F_76 ( V_238 , V_239 ) ;
}
