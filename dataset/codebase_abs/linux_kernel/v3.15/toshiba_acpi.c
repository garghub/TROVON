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
static T_3 F_6 ( struct V_9 * V_10 , T_2 V_31 ,
T_2 V_32 , T_2 * V_33 )
{
T_2 V_11 [ V_12 ] = { V_34 , V_31 , V_32 , 0 , 0 , 0 } ;
T_2 V_13 [ V_12 ] ;
T_3 V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
* V_33 = ( V_6 == V_7 ) ? V_13 [ 0 ] : V_35 ;
return V_6 ;
}
static T_3 F_7 ( struct V_9 * V_10 , T_2 V_31 ,
T_2 * V_36 , T_2 * V_33 )
{
T_2 V_11 [ V_12 ] = { V_37 , V_31 , 0 , 0 , 0 , 0 } ;
T_2 V_13 [ V_12 ] ;
T_3 V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
* V_36 = V_13 [ 2 ] ;
* V_33 = ( V_6 == V_7 ) ? V_13 [ 0 ] : V_35 ;
return V_6 ;
}
static T_3 F_8 ( struct V_9 * V_10 , T_2 V_31 ,
T_2 V_32 , T_2 V_38 , T_2 * V_33 )
{
T_2 V_11 [ V_12 ] = { V_34 , V_31 , V_32 , V_38 , 0 , 0 } ;
T_2 V_13 [ V_12 ] ;
T_3 V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
* V_33 = ( V_6 == V_7 ) ? V_13 [ 0 ] : V_35 ;
return V_6 ;
}
static T_3 F_9 ( struct V_9 * V_10 , T_2 V_31 ,
T_2 * V_36 , T_2 * V_39 , T_2 * V_33 )
{
T_2 V_11 [ V_12 ] = { V_37 , V_31 , * V_36 , * V_39 , 0 , 0 } ;
T_2 V_13 [ V_12 ] ;
T_3 V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
* V_36 = V_13 [ 2 ] ;
* V_39 = V_13 [ 3 ] ;
* V_33 = ( V_6 == V_7 ) ? V_13 [ 0 ] : V_35 ;
return V_6 ;
}
static int F_10 ( struct V_9 * V_10 )
{
T_2 V_11 [ V_12 ] = { V_40 , 0 , 0 , 0 , 0 , 0 } ;
T_2 V_13 [ V_12 ] ;
T_3 V_6 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_11 ( V_6 ) || V_13 [ 0 ] == V_35 ) {
F_12 ( L_1 ) ;
return 0 ;
}
if ( V_13 [ 0 ] == V_41 ) {
return 1 ;
} else if ( V_13 [ 0 ] == V_42 ) {
F_13 ( L_2 ) ;
return 1 ;
} else if ( V_13 [ 0 ] == V_43 ) {
F_13 ( L_3 ) ;
}
return 0 ;
}
static void F_14 ( struct V_9 * V_10 )
{
T_2 V_11 [ V_12 ] = { V_44 , 0 , 0 , 0 , 0 , 0 } ;
T_2 V_13 [ V_12 ] ;
T_3 V_6 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_11 ( V_6 ) || V_13 [ 0 ] == V_35 ) {
F_12 ( L_4 ) ;
return;
}
if ( V_13 [ 0 ] == V_41 )
return;
else if ( V_13 [ 0 ] == V_45 )
F_13 ( L_5 ) ;
else if ( V_13 [ 0 ] == V_43 )
F_13 ( L_3 ) ;
}
static T_3 F_15 ( struct V_9 * V_10 , T_2 V_31 ,
T_2 * V_36 , T_2 * V_33 )
{
T_2 V_11 [ V_12 ] = { V_46 , V_31 , 0 , 0 , 0 , 0 } ;
T_2 V_13 [ V_12 ] ;
T_3 V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
* V_36 = V_13 [ 2 ] ;
* V_33 = ( F_16 ( V_6 ) ) ? V_13 [ 0 ] : V_35 ;
return V_6 ;
}
static T_3 F_17 ( struct V_9 * V_10 , T_2 V_31 ,
T_2 V_32 , T_2 * V_33 )
{
T_2 V_11 [ V_12 ] = { V_47 , V_31 , V_32 , 0 , 0 , 0 } ;
T_2 V_13 [ V_12 ] ;
T_3 V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
* V_33 = ( F_16 ( V_6 ) ) ? V_13 [ 0 ] : V_35 ;
return V_6 ;
}
static int F_18 ( struct V_9 * V_10 )
{
T_2 V_11 [ V_12 ] = { V_46 , V_48 , 0 , 0 , 0 , 0 } ;
T_2 V_13 [ V_12 ] ;
T_3 V_6 ;
if ( ! F_10 ( V_10 ) )
return 0 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
F_14 ( V_10 ) ;
if ( F_11 ( V_6 ) || V_13 [ 0 ] == V_35 ) {
F_12 ( L_6 ) ;
return 0 ;
} else if ( V_13 [ 0 ] == V_49 || V_13 [ 1 ] != 1 ) {
F_13 ( L_7 ) ;
return 0 ;
}
return 1 ;
}
static void F_19 ( struct V_50 * V_51 ,
enum V_52 V_53 )
{
struct V_9 * V_10 = F_20 ( V_51 ,
struct V_9 , V_54 ) ;
T_2 V_55 , V_33 ;
T_3 V_6 ;
if ( ! F_10 ( V_10 ) )
return;
V_55 = V_53 ? 1 : 0 ;
V_6 = F_17 ( V_10 , V_48 , V_55 , & V_33 ) ;
F_14 ( V_10 ) ;
if ( F_11 ( V_6 ) ) {
F_12 ( L_8 ) ;
return;
} else if ( V_33 == V_49 ) {
F_13 ( L_9 ) ;
return;
}
}
static enum V_52 F_21 ( struct V_50 * V_51 )
{
struct V_9 * V_10 = F_20 ( V_51 ,
struct V_9 , V_54 ) ;
T_2 V_55 , V_33 ;
T_3 V_6 ;
if ( ! F_10 ( V_10 ) )
return V_56 ;
V_6 = F_15 ( V_10 , V_48 , & V_55 , & V_33 ) ;
F_14 ( V_10 ) ;
if ( F_11 ( V_6 ) || V_33 == V_57 ) {
F_12 ( L_8 ) ;
return V_56 ;
} else if ( V_33 == V_49 ) {
F_13 ( L_9 ) ;
return V_56 ;
}
return V_55 ? V_58 : V_56 ;
}
static int F_22 ( struct V_9 * V_10 , T_2 time )
{
T_2 V_33 ;
T_3 V_6 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_6 = F_17 ( V_10 , V_59 , time , & V_33 ) ;
F_14 ( V_10 ) ;
if ( F_11 ( V_6 ) || V_33 == V_57 ) {
F_12 ( L_10 ) ;
return - V_8 ;
} else if ( V_33 == V_49 ) {
F_13 ( L_11 ) ;
return - V_60 ;
}
return 0 ;
}
static int F_23 ( struct V_9 * V_10 , T_2 * time )
{
T_2 V_33 ;
T_3 V_6 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_6 = F_15 ( V_10 , V_59 , time , & V_33 ) ;
F_14 ( V_10 ) ;
if ( F_11 ( V_6 ) || V_33 == V_57 ) {
F_12 ( L_12 ) ;
return - V_8 ;
} else if ( V_33 == V_49 ) {
F_13 ( L_11 ) ;
return - V_60 ;
}
return 0 ;
}
static enum V_52 F_24 ( struct V_50 * V_51 )
{
struct V_9 * V_10 = F_20 ( V_51 ,
struct V_9 , V_61 ) ;
T_2 V_55 , V_33 ;
T_3 V_6 ;
V_6 = F_7 ( V_10 , V_62 , & V_55 , & V_33 ) ;
if ( F_11 ( V_6 ) || V_33 == V_57 ) {
F_12 ( L_13 ) ;
return V_56 ;
} else if ( V_33 == V_49 ) {
F_13 ( L_14 ) ;
return V_56 ;
}
return V_55 ? V_58 : V_56 ;
}
static void F_25 ( struct V_50 * V_51 ,
enum V_52 V_53 )
{
struct V_9 * V_10 = F_20 ( V_51 ,
struct V_9 , V_61 ) ;
T_2 V_55 , V_33 ;
T_3 V_6 ;
V_55 = V_53 ? 1 : 0 ;
V_6 = F_6 ( V_10 , V_62 , V_55 , & V_33 ) ;
if ( F_11 ( V_6 ) || V_33 == V_57 ) {
F_12 ( L_15 ) ;
return;
} else if ( V_33 == V_49 ) {
F_13 ( L_14 ) ;
return;
}
}
static int F_26 ( struct V_9 * V_10 , T_2 V_55 )
{
T_2 V_33 ;
T_3 V_6 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_6 = F_17 ( V_10 , V_63 , V_55 , & V_33 ) ;
F_14 ( V_10 ) ;
if ( F_11 ( V_6 ) ) {
F_12 ( L_16 ) ;
return - V_8 ;
} else if ( V_33 == V_49 ) {
return - V_60 ;
}
return 0 ;
}
static int F_27 ( struct V_9 * V_10 , T_2 * V_55 )
{
T_2 V_33 ;
T_3 V_6 ;
if ( ! F_10 ( V_10 ) )
return - V_8 ;
V_6 = F_15 ( V_10 , V_63 , V_55 , & V_33 ) ;
F_14 ( V_10 ) ;
if ( F_11 ( V_6 ) ) {
F_12 ( L_17 ) ;
return - V_8 ;
} else if ( V_33 == V_49 ) {
return - V_60 ;
}
return 0 ;
}
static int F_28 ( struct V_9 * V_10 )
{
T_3 V_6 ;
T_2 V_11 [ V_12 ] = { V_37 , V_64 , 0 , 1 , 0 , 0 } ;
T_2 V_13 [ V_12 ] ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_11 ( V_6 ) || V_13 [ 0 ] == V_57 ) {
F_13 ( L_18 ) ;
return 0 ;
}
return 1 ;
}
static enum V_52 F_29 ( struct V_50 * V_51 )
{
struct V_9 * V_10 = F_20 ( V_51 ,
struct V_9 , V_65 ) ;
T_2 V_11 [ V_12 ] = { V_37 , V_64 , 0 , 1 , 0 , 0 } ;
T_2 V_13 [ V_12 ] ;
T_3 V_6 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_11 ( V_6 ) || V_13 [ 0 ] == V_57 ) {
F_12 ( L_18 ) ;
return V_56 ;
}
return V_13 [ 2 ] ? V_58 : V_56 ;
}
static void F_30 ( struct V_50 * V_51 ,
enum V_52 V_53 )
{
struct V_9 * V_10 = F_20 ( V_51 ,
struct V_9 , V_65 ) ;
T_2 V_11 [ V_12 ] = { V_34 , V_64 , 0 , 1 , 0 , 0 } ;
T_2 V_13 [ V_12 ] ;
T_3 V_6 ;
V_11 [ 2 ] = ( V_53 ) ? 1 : 0 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_11 ( V_6 ) || V_13 [ 0 ] == V_57 ) {
F_12 ( L_19 ) ;
return;
}
}
static int F_31 ( struct V_9 * V_10 )
{
T_2 V_11 [ V_12 ] = { V_37 , V_66 , 0 , 0 , 0 , 0 } ;
T_2 V_13 [ V_12 ] ;
T_3 V_6 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_11 ( V_6 ) || V_13 [ 0 ] == V_57 ) {
F_12 ( L_20 ) ;
return - V_8 ;
} else if ( V_13 [ 0 ] == V_67 ||
V_13 [ 0 ] == V_68 ) {
F_12 ( L_21 ) ;
return - V_8 ;
} else if ( V_13 [ 0 ] == V_49 ) {
F_13 ( L_22 ) ;
return - V_60 ;
}
return 0 ;
}
static int F_32 ( struct V_9 * V_10 ,
T_2 * V_69 , T_2 * V_70 )
{
T_2 V_11 [ V_12 ] = { V_37 , V_71 , 0 , 1 , 0 , 0 } ;
T_2 V_13 [ V_12 ] ;
T_3 V_6 ;
V_6 = F_4 ( V_10 , V_11 , V_13 ) ;
if ( F_11 ( V_6 ) || V_13 [ 0 ] == V_57 ) {
F_12 ( L_20 ) ;
return - V_8 ;
}
* V_69 = V_13 [ 2 ] ;
* V_70 = V_13 [ 4 ] ;
return 0 ;
}
static T_2 F_33 ( struct V_9 * V_10 , bool * V_72 )
{
T_2 V_73 ;
T_2 V_3 , V_74 ;
V_3 = 0 ;
V_74 = 0 ;
F_9 ( V_10 , V_75 , & V_3 , & V_74 , & V_73 ) ;
if ( V_73 == V_76 )
* V_72 = ( V_3 & V_77 ) ? true : false ;
return V_73 ;
}
static T_2 F_34 ( struct V_9 * V_10 , bool * V_78 )
{
T_2 V_73 ;
T_2 V_3 , V_74 ;
V_3 = 0 ;
V_74 = 0x0001 ;
F_9 ( V_10 , V_75 , & V_3 , & V_74 , & V_73 ) ;
* V_78 = V_3 & V_79 ;
return V_73 ;
}
static int F_35 ( void * V_80 , bool V_81 )
{
struct V_9 * V_10 = V_80 ;
T_2 V_82 , V_83 ;
T_2 V_3 ;
int V_84 ;
bool V_78 ;
V_3 = ( V_81 == false ) ;
F_36 ( & V_10 -> V_85 ) ;
if ( F_34 ( V_10 , & V_78 ) != V_76 ) {
V_84 = - V_8 ;
goto V_13;
}
if ( ! V_78 ) {
V_84 = 0 ;
goto V_13;
}
F_8 ( V_10 , V_75 , V_3 , V_86 , & V_82 ) ;
F_8 ( V_10 , V_75 , V_3 , V_87 , & V_83 ) ;
if ( V_82 != V_76 || V_83 != V_76 )
V_84 = - V_8 ;
else
V_84 = 0 ;
V_13:
F_37 ( & V_10 -> V_85 ) ;
return V_84 ;
}
static void F_38 ( struct V_88 * V_88 , void * V_80 )
{
bool V_89 ;
bool V_3 ;
T_2 V_73 ;
struct V_9 * V_10 = V_80 ;
F_36 ( & V_10 -> V_85 ) ;
V_73 = F_34 ( V_10 , & V_3 ) ;
if ( V_73 != V_76 ) {
F_37 ( & V_10 -> V_85 ) ;
return;
}
V_89 = V_3 ;
F_37 ( & V_10 -> V_85 ) ;
if ( F_39 ( V_88 , ! V_89 ) )
F_35 ( V_80 , true ) ;
}
static int F_40 ( struct V_9 * V_10 , bool * V_90 )
{
T_2 V_73 ;
T_2 V_6 ;
F_7 ( V_10 , V_91 , & V_6 , & V_73 ) ;
* V_90 = ! V_6 ;
return V_73 == V_76 ? 0 : - V_8 ;
}
static int F_41 ( struct V_9 * V_10 , bool V_92 )
{
T_2 V_73 ;
T_2 V_3 = ! V_92 ;
F_6 ( V_10 , V_91 , V_3 , & V_73 ) ;
return V_73 == V_76 ? 0 : - V_8 ;
}
static int F_42 ( struct V_9 * V_10 )
{
T_2 V_73 ;
T_2 V_3 ;
int V_53 = 0 ;
if ( V_10 -> V_93 ) {
bool V_90 ;
int V_94 = F_40 ( V_10 , & V_90 ) ;
if ( V_94 )
return V_94 ;
if ( V_90 )
return 0 ;
V_53 ++ ;
}
F_7 ( V_10 , V_95 , & V_3 , & V_73 ) ;
if ( V_73 == V_76 )
return V_53 + ( V_3 >> V_96 ) ;
return - V_8 ;
}
static int F_43 ( struct V_97 * V_98 )
{
struct V_9 * V_10 = F_44 ( V_98 ) ;
return F_42 ( V_10 ) ;
}
static int F_45 ( struct V_99 * V_100 , void * V_101 )
{
struct V_9 * V_10 = V_100 -> V_102 ;
int V_3 ;
int V_103 ;
if ( ! V_10 -> V_104 )
return - V_60 ;
V_103 = V_10 -> V_104 -> V_105 . V_106 + 1 ;
V_3 = F_43 ( V_10 -> V_104 ) ;
if ( V_3 >= 0 ) {
F_46 ( V_100 , L_23 , V_3 ) ;
F_46 ( V_100 , L_24 , V_103 ) ;
return 0 ;
}
F_12 ( L_25 ) ;
return - V_8 ;
}
static int F_47 ( struct V_107 * V_107 , struct V_108 * V_108 )
{
return F_48 ( V_108 , F_45 , F_49 ( V_107 ) ) ;
}
static int F_50 ( struct V_9 * V_10 , int V_3 )
{
T_2 V_73 ;
if ( V_10 -> V_93 ) {
bool V_92 = ! V_3 ;
int V_94 = F_41 ( V_10 , V_92 ) ;
if ( V_94 )
return V_94 ;
if ( V_3 )
V_3 -- ;
}
V_3 = V_3 << V_96 ;
F_6 ( V_10 , V_95 , V_3 , & V_73 ) ;
return V_73 == V_76 ? 0 : - V_8 ;
}
static int F_51 ( struct V_97 * V_98 )
{
struct V_9 * V_10 = F_44 ( V_98 ) ;
return F_50 ( V_10 , V_98 -> V_105 . V_53 ) ;
}
static T_4 F_52 ( struct V_108 * V_108 , const char T_5 * V_109 ,
T_6 V_22 , T_7 * V_110 )
{
struct V_9 * V_10 = F_49 ( F_53 ( V_108 ) ) ;
char V_111 [ 42 ] ;
T_6 V_112 ;
int V_3 ;
int V_94 ;
int V_103 = V_10 -> V_104 -> V_105 . V_106 + 1 ;
V_112 = F_54 ( V_22 , sizeof( V_111 ) - 1 ) ;
if ( F_55 ( V_111 , V_109 , V_112 ) )
return - V_113 ;
V_111 [ V_112 ] = '\0' ;
if ( sscanf ( V_111 , L_26 , & V_3 ) == 1 &&
V_3 >= 0 && V_3 < V_103 ) {
V_94 = F_50 ( V_10 , V_3 ) ;
if ( V_94 == 0 )
V_94 = V_22 ;
} else {
V_94 = - V_114 ;
}
return V_94 ;
}
static int F_56 ( struct V_9 * V_10 , T_2 * V_6 )
{
T_2 V_73 ;
F_7 ( V_10 , V_115 , V_6 , & V_73 ) ;
return V_73 == V_76 ? 0 : - V_8 ;
}
static int F_57 ( struct V_99 * V_100 , void * V_101 )
{
struct V_9 * V_10 = V_100 -> V_102 ;
T_2 V_3 ;
int V_94 ;
V_94 = F_56 ( V_10 , & V_3 ) ;
if ( ! V_94 ) {
int V_116 = ( V_3 & V_117 ) ? 1 : 0 ;
int V_118 = ( V_3 & V_119 ) ? 1 : 0 ;
int V_120 = ( V_3 & V_121 ) ? 1 : 0 ;
F_46 ( V_100 , L_27 , V_116 ) ;
F_46 ( V_100 , L_28 , V_118 ) ;
F_46 ( V_100 , L_29 , V_120 ) ;
}
return V_94 ;
}
static int F_58 ( struct V_107 * V_107 , struct V_108 * V_108 )
{
return F_48 ( V_108 , F_57 , F_49 ( V_107 ) ) ;
}
static T_4 F_59 ( struct V_108 * V_108 , const char T_5 * V_109 ,
T_6 V_22 , T_7 * V_110 )
{
struct V_9 * V_10 = F_49 ( F_53 ( V_108 ) ) ;
char * V_111 , * V_122 ;
int V_94 ;
int V_3 ;
int V_123 = V_22 ;
int V_124 = - 1 ;
int V_125 = - 1 ;
int V_126 = - 1 ;
T_2 V_127 ;
V_111 = F_60 ( V_22 + 1 , V_128 ) ;
if ( ! V_111 )
return - V_129 ;
if ( F_55 ( V_111 , V_109 , V_22 ) ) {
F_61 ( V_111 ) ;
return - V_113 ;
}
V_111 [ V_22 ] = '\0' ;
V_122 = V_111 ;
while ( V_123 ) {
if ( sscanf ( V_122 , L_30 , & V_3 ) == 1 )
V_124 = V_3 & 1 ;
else if ( sscanf ( V_122 , L_31 , & V_3 ) == 1 )
V_125 = V_3 & 1 ;
else if ( sscanf ( V_122 , L_32 , & V_3 ) == 1 )
V_126 = V_3 & 1 ;
do {
++ V_122 ;
-- V_123 ;
}
while ( V_123 && * ( V_122 - 1 ) != ';' );
}
F_61 ( V_111 ) ;
V_94 = F_56 ( V_10 , & V_127 ) ;
if ( ! V_94 ) {
unsigned int V_130 = V_127 ;
if ( V_124 != - 1 )
F_1 ( & V_130 , V_117 , V_124 ) ;
if ( V_125 != - 1 )
F_1 ( & V_130 , V_119 , V_125 ) ;
if ( V_126 != - 1 )
F_1 ( & V_130 , V_121 , V_126 ) ;
if ( V_130 != V_127 )
V_94 = F_2 ( V_131 , V_130 ) ;
}
return V_94 ? V_94 : V_22 ;
}
static int F_62 ( struct V_9 * V_10 , T_2 * V_6 )
{
T_2 V_73 ;
F_7 ( V_10 , V_132 , V_6 , & V_73 ) ;
return V_73 == V_76 ? 0 : - V_8 ;
}
static int F_63 ( struct V_99 * V_100 , void * V_101 )
{
struct V_9 * V_10 = V_100 -> V_102 ;
int V_94 ;
T_2 V_3 ;
V_94 = F_62 ( V_10 , & V_3 ) ;
if ( ! V_94 ) {
F_46 ( V_100 , L_33 , ( V_3 > 0 ) ) ;
F_46 ( V_100 , L_34 , V_10 -> V_133 ) ;
}
return V_94 ;
}
static int F_64 ( struct V_107 * V_107 , struct V_108 * V_108 )
{
return F_48 ( V_108 , F_63 , F_49 ( V_107 ) ) ;
}
static T_4 F_65 ( struct V_108 * V_108 , const char T_5 * V_109 ,
T_6 V_22 , T_7 * V_110 )
{
struct V_9 * V_10 = F_49 ( F_53 ( V_108 ) ) ;
char V_111 [ 42 ] ;
T_6 V_112 ;
int V_3 ;
T_2 V_73 ;
V_112 = F_54 ( V_22 , sizeof( V_111 ) - 1 ) ;
if ( F_55 ( V_111 , V_109 , V_112 ) )
return - V_113 ;
V_111 [ V_112 ] = '\0' ;
if ( sscanf ( V_111 , L_35 , & V_3 ) == 1 &&
V_3 >= 0 && V_3 <= 1 ) {
F_6 ( V_10 , V_132 , V_3 , & V_73 ) ;
if ( V_73 != V_76 )
return - V_8 ;
else
V_10 -> V_133 = V_3 ;
} else {
return - V_114 ;
}
return V_22 ;
}
static int F_66 ( struct V_99 * V_100 , void * V_101 )
{
struct V_9 * V_10 = V_100 -> V_102 ;
T_2 V_73 ;
T_2 V_3 ;
if ( ! V_10 -> V_134 && V_10 -> V_135 ) {
F_7 ( V_10 , V_136 , & V_3 , & V_73 ) ;
if ( V_73 == V_76 ) {
V_10 -> V_134 = 1 ;
V_10 -> V_137 = V_3 ;
} else if ( V_73 == V_138 ) {
} else if ( V_73 == V_49 ) {
F_6 ( V_10 , V_136 , 1 , & V_73 ) ;
F_67 ( L_36 ) ;
} else {
F_12 ( L_37 ) ;
return - V_8 ;
}
}
F_46 ( V_100 , L_38 , V_10 -> V_134 ) ;
F_46 ( V_100 , L_39 , V_10 -> V_137 ) ;
return 0 ;
}
static int F_68 ( struct V_107 * V_107 , struct V_108 * V_108 )
{
return F_48 ( V_108 , F_66 , F_49 ( V_107 ) ) ;
}
static T_4 F_69 ( struct V_108 * V_108 , const char T_5 * V_109 ,
T_6 V_22 , T_7 * V_110 )
{
struct V_9 * V_10 = F_49 ( F_53 ( V_108 ) ) ;
char V_111 [ 42 ] ;
T_6 V_112 ;
int V_3 ;
V_112 = F_54 ( V_22 , sizeof( V_111 ) - 1 ) ;
if ( F_55 ( V_111 , V_109 , V_112 ) )
return - V_113 ;
V_111 [ V_112 ] = '\0' ;
if ( sscanf ( V_111 , L_40 , & V_3 ) == 1 && V_3 == 0 ) {
V_10 -> V_134 = 0 ;
} else {
return - V_114 ;
}
return V_22 ;
}
static int F_70 ( struct V_99 * V_100 , void * V_101 )
{
F_46 ( V_100 , L_41 , V_139 ) ;
F_46 ( V_100 , L_42 , V_140 ) ;
return 0 ;
}
static int F_71 ( struct V_107 * V_107 , struct V_108 * V_108 )
{
return F_48 ( V_108 , F_70 , F_49 ( V_107 ) ) ;
}
static void F_72 ( struct V_9 * V_10 )
{
if ( V_10 -> V_104 )
F_73 ( L_43 , V_141 | V_142 , V_143 ,
& V_144 , V_10 ) ;
if ( V_10 -> V_145 )
F_73 ( L_44 , V_141 | V_142 , V_143 ,
& V_146 , V_10 ) ;
if ( V_10 -> V_147 )
F_73 ( L_45 , V_141 | V_142 , V_143 ,
& V_148 , V_10 ) ;
if ( V_10 -> V_149 )
F_73 ( L_46 , V_141 | V_142 , V_143 ,
& V_150 , V_10 ) ;
F_73 ( L_47 , V_141 , V_143 ,
& V_151 , V_10 ) ;
}
static void F_74 ( struct V_9 * V_10 )
{
if ( V_10 -> V_104 )
F_75 ( L_43 , V_143 ) ;
if ( V_10 -> V_145 )
F_75 ( L_44 , V_143 ) ;
if ( V_10 -> V_147 )
F_75 ( L_45 , V_143 ) ;
if ( V_10 -> V_149 )
F_75 ( L_46 , V_143 ) ;
F_75 ( L_47 , V_143 ) ;
}
static T_4 F_76 ( struct V_152 * V_10 ,
struct V_153 * V_154 ,
const char * V_109 , T_6 V_22 )
{
struct V_9 * V_155 = F_77 ( V_10 ) ;
int V_156 = - 1 ;
int time = - 1 ;
if ( sscanf ( V_109 , L_48 , & V_156 ) != 1 && ( V_156 != 2 || V_156 != 1 ) )
return - V_114 ;
if ( V_156 != - 1 && V_155 -> V_157 != V_156 ) {
time = V_155 -> V_158 << V_159 ;
time = time + V_155 -> V_157 ;
if ( F_22 ( V_155 , time ) < 0 )
return - V_8 ;
V_155 -> V_157 = V_156 ;
}
return V_22 ;
}
static T_4 F_78 ( struct V_152 * V_10 ,
struct V_153 * V_154 ,
char * V_109 )
{
struct V_9 * V_155 = F_77 ( V_10 ) ;
T_2 time ;
if ( F_23 ( V_155 , & time ) < 0 )
return - V_8 ;
return sprintf ( V_109 , L_49 , time & 0x07 ) ;
}
static T_4 F_79 ( struct V_152 * V_10 ,
struct V_153 * V_154 ,
const char * V_109 , T_6 V_22 )
{
struct V_9 * V_155 = F_77 ( V_10 ) ;
int time = - 1 ;
if ( sscanf ( V_109 , L_48 , & time ) != 1 && ( time < 0 || time > 60 ) )
return - V_114 ;
if ( time != - 1 && V_155 -> V_158 != time ) {
time = time << V_159 ;
time = ( V_155 -> V_157 == V_160 ) ?
time + 1 : time + 2 ;
if ( F_22 ( V_155 , time ) < 0 )
return - V_8 ;
V_155 -> V_158 = time >> V_159 ;
}
return V_22 ;
}
static T_4 F_80 ( struct V_152 * V_10 ,
struct V_153 * V_154 ,
char * V_109 )
{
struct V_9 * V_155 = F_77 ( V_10 ) ;
T_2 time ;
if ( F_23 ( V_155 , & time ) < 0 )
return - V_8 ;
return sprintf ( V_109 , L_49 , time >> V_159 ) ;
}
static T_4 F_81 ( struct V_152 * V_10 ,
struct V_153 * V_154 ,
const char * V_109 , T_6 V_22 )
{
struct V_9 * V_155 = F_77 ( V_10 ) ;
int V_55 ;
if ( sscanf ( V_109 , L_48 , & V_55 ) == 1 && ( V_55 == 0 || V_55 == 1 ) ) {
if ( F_26 ( V_155 , V_55 ) < 0 )
return - V_8 ;
}
return V_22 ;
}
static T_4 F_82 ( struct V_152 * V_10 ,
struct V_153 * V_154 , char * V_109 )
{
struct V_9 * V_155 = F_77 ( V_10 ) ;
T_2 V_55 ;
int V_94 ;
V_94 = F_27 ( V_155 , & V_55 ) ;
if ( V_94 < 0 )
return V_94 ;
return sprintf ( V_109 , L_49 , V_55 ) ;
}
static T_4 F_83 ( struct V_152 * V_10 ,
struct V_153 * V_154 , char * V_109 )
{
struct V_9 * V_155 = F_77 ( V_10 ) ;
T_2 V_161 , V_162 , V_163 ;
T_8 V_164 , V_165 , V_70 ;
int V_94 ;
V_161 = V_162 = 0 ;
V_94 = F_32 ( V_155 , & V_161 , & V_162 ) ;
if ( V_94 < 0 )
return V_94 ;
V_164 = V_161 & V_166 ;
V_163 = V_161 >> V_159 ;
V_165 = V_163 & V_166 ;
V_70 = V_162 & V_166 ;
return sprintf ( V_109 , L_50 , V_164 , V_165 , V_70 ) ;
}
static T_9 F_84 ( struct V_167 * V_168 ,
struct V_169 * V_154 , int V_170 )
{
struct V_152 * V_10 = F_20 ( V_168 , struct V_152 , V_168 ) ;
struct V_9 * V_171 = F_77 ( V_10 ) ;
bool V_172 = true ;
if ( V_154 == & V_173 . V_154 )
V_172 = ( V_171 -> V_174 ) ? true : false ;
else if ( V_154 == & V_175 . V_154 )
V_172 = ( V_171 -> V_157 == V_160 ) ? true : false ;
else if ( V_154 == & V_176 . V_154 )
V_172 = ( V_171 -> V_177 ) ? true : false ;
else if ( V_154 == & V_178 . V_154 )
V_172 = ( V_171 -> V_179 ) ? true : false ;
return V_172 ? V_154 -> V_156 : 0 ;
}
static bool F_85 ( unsigned char V_80 , unsigned char V_180 ,
struct V_181 * V_182 )
{
if ( V_180 & 0x20 )
return false ;
if ( F_86 ( V_80 == 0xe0 ) )
return false ;
if ( ( V_80 & 0x7f ) == V_183 ) {
F_87 ( & V_184 -> V_185 ) ;
return true ;
}
return false ;
}
static void F_88 ( struct V_186 * V_187 )
{
T_10 V_188 = F_89 () ;
T_3 V_6 ;
if ( ! V_188 )
return;
V_6 = F_5 ( V_188 , L_51 , NULL , NULL ) ;
if ( F_11 ( V_6 ) )
F_12 ( L_52 ) ;
}
static int F_90 ( struct V_9 * V_10 )
{
unsigned long long V_3 ;
T_3 V_6 ;
V_6 = F_91 ( V_10 -> V_26 -> V_27 , L_53 ,
NULL , & V_3 ) ;
if ( F_11 ( V_6 ) ) {
F_12 ( L_54 ) ;
return - V_8 ;
}
return V_3 ;
}
static void F_92 ( struct V_9 * V_10 ,
int V_189 )
{
if ( V_189 == 0x100 )
return;
if ( V_189 & 0x80 )
return;
if ( ! F_93 ( V_10 -> V_149 , V_189 , 1 , true ) )
F_13 ( L_55 , V_189 ) ;
}
static int F_94 ( struct V_9 * V_10 )
{
T_3 V_6 ;
T_10 V_188 ;
int error ;
T_2 V_73 ;
V_10 -> V_149 = F_95 () ;
if ( ! V_10 -> V_149 )
return - V_129 ;
V_10 -> V_149 -> V_190 = L_56 ;
V_10 -> V_149 -> V_191 = L_57 ;
V_10 -> V_149 -> V_192 . V_193 = V_194 ;
error = F_96 ( V_10 -> V_149 , V_195 , NULL ) ;
if ( error )
goto V_196;
V_6 = V_197 ;
V_188 = F_89 () ;
if ( V_188 && F_97 ( V_188 , L_51 ) ) {
F_98 ( & V_10 -> V_185 , F_88 ) ;
error = F_99 ( F_85 ) ;
if ( error ) {
F_12 ( L_58 ) ;
goto V_198;
}
V_10 -> V_199 = 1 ;
}
if ( F_97 ( V_10 -> V_26 -> V_27 , L_53 ) )
V_10 -> V_200 = 1 ;
else {
F_6 ( V_10 , V_136 , 1 , & V_73 ) ;
if ( V_73 == V_76 )
V_10 -> V_135 = 1 ;
}
if ( ! V_10 -> V_200 && ! V_10 -> V_135 ) {
F_100 ( L_59 ) ;
goto V_201;
}
V_6 = F_5 ( V_10 -> V_26 -> V_27 , L_60 , NULL , NULL ) ;
if ( F_11 ( V_6 ) ) {
F_13 ( L_61 ) ;
error = - V_60 ;
goto V_201;
}
error = F_101 ( V_10 -> V_149 ) ;
if ( error ) {
F_13 ( L_62 ) ;
goto V_201;
}
F_6 ( V_10 , V_202 , V_203 , & V_73 ) ;
return 0 ;
V_201:
if ( V_10 -> V_199 )
F_102 ( F_85 ) ;
V_198:
F_103 ( V_10 -> V_149 ) ;
V_196:
F_104 ( V_10 -> V_149 ) ;
V_10 -> V_149 = NULL ;
return error ;
}
static int F_105 ( struct V_9 * V_10 )
{
struct V_204 V_105 ;
int V_53 ;
int V_94 ;
bool V_90 ;
V_53 = F_42 ( V_10 ) ;
if ( V_53 < 0 )
return 0 ;
V_94 = F_50 ( V_10 , V_53 ) ;
if ( V_94 ) {
F_106 ( L_63 ) ;
return 0 ;
}
V_94 = F_40 ( V_10 , & V_90 ) ;
V_10 -> V_93 = ! V_94 ;
memset ( & V_105 , 0 , sizeof( V_105 ) ) ;
V_105 . type = V_205 ;
V_105 . V_106 = V_206 - 1 ;
if ( V_10 -> V_93 )
V_105 . V_106 ++ ;
V_10 -> V_104 = F_107 ( L_64 ,
& V_10 -> V_26 -> V_10 ,
V_10 ,
& V_207 ,
& V_105 ) ;
if ( F_108 ( V_10 -> V_104 ) ) {
V_94 = F_109 ( V_10 -> V_104 ) ;
F_12 ( L_65 ) ;
V_10 -> V_104 = NULL ;
return V_94 ;
}
V_10 -> V_104 -> V_105 . V_53 = V_53 ;
return 0 ;
}
static int F_110 ( struct V_208 * V_26 )
{
struct V_9 * V_10 = F_111 ( V_26 ) ;
F_74 ( V_10 ) ;
if ( V_10 -> V_209 )
F_112 ( & V_10 -> V_26 -> V_10 . V_168 ,
& V_210 ) ;
if ( V_10 -> V_199 ) {
F_102 ( F_85 ) ;
F_113 ( & V_10 -> V_185 ) ;
}
if ( V_10 -> V_149 ) {
F_114 ( V_10 -> V_149 ) ;
F_103 ( V_10 -> V_149 ) ;
}
if ( V_10 -> V_211 ) {
F_115 ( V_10 -> V_211 ) ;
F_116 ( V_10 -> V_211 ) ;
}
if ( V_10 -> V_104 )
F_117 ( V_10 -> V_104 ) ;
if ( V_10 -> V_212 )
F_118 ( & V_10 -> V_54 ) ;
if ( V_10 -> V_213 )
F_118 ( & V_10 -> V_61 ) ;
if ( V_10 -> V_214 )
F_118 ( & V_10 -> V_65 ) ;
if ( V_184 )
V_184 = NULL ;
F_61 ( V_10 ) ;
return 0 ;
}
static const char * F_119 ( T_10 V_27 )
{
if ( F_97 ( V_27 , L_66 ) )
return L_66 ;
if ( F_97 ( V_27 , L_67 ) )
return L_67 ;
return NULL ;
}
static int F_120 ( struct V_208 * V_26 )
{
struct V_9 * V_10 ;
const char * V_215 ;
T_2 V_216 ;
bool V_217 ;
int V_94 = 0 ;
if ( V_184 )
return - V_218 ;
F_13 ( L_68 ,
V_139 ) ;
V_215 = F_119 ( V_26 -> V_27 ) ;
if ( ! V_215 ) {
F_12 ( L_69 ) ;
return - V_60 ;
}
V_10 = F_121 ( sizeof( * V_10 ) , V_128 ) ;
if ( ! V_10 )
return - V_129 ;
V_10 -> V_26 = V_26 ;
V_10 -> V_28 = V_215 ;
V_26 -> V_219 = V_10 ;
F_122 ( & V_26 -> V_10 , V_10 ) ;
if ( F_94 ( V_10 ) )
F_13 ( L_70 ) ;
F_123 ( & V_10 -> V_85 ) ;
V_94 = F_105 ( V_10 ) ;
if ( V_94 )
goto error;
if ( F_33 ( V_10 , & V_217 ) == V_76 && V_217 ) {
V_10 -> V_211 = F_124 ( L_71 ,
& V_26 -> V_10 ,
V_220 ,
& V_221 ,
V_10 ) ;
if ( ! V_10 -> V_211 ) {
F_12 ( L_72 ) ;
V_94 = - V_129 ;
goto error;
}
V_94 = F_125 ( V_10 -> V_211 ) ;
if ( V_94 ) {
F_12 ( L_73 ) ;
F_116 ( V_10 -> V_211 ) ;
goto error;
}
}
if ( F_18 ( V_10 ) ) {
V_10 -> V_54 . V_190 = L_74 ;
V_10 -> V_54 . V_106 = 1 ;
V_10 -> V_54 . V_222 = F_19 ;
V_10 -> V_54 . V_223 = F_21 ;
if ( ! F_126 ( & V_26 -> V_10 , & V_10 -> V_54 ) )
V_10 -> V_212 = 1 ;
}
if ( F_28 ( V_10 ) ) {
V_10 -> V_65 . V_190 = L_75 ;
V_10 -> V_65 . V_106 = 1 ;
V_10 -> V_65 . V_222 = F_30 ;
V_10 -> V_65 . V_223 = F_29 ;
if ( ! F_126 ( & V_10 -> V_26 -> V_10 , & V_10 -> V_65 ) )
V_10 -> V_214 = 1 ;
}
V_94 = F_23 ( V_10 , & V_216 ) ;
if ( ! V_94 ) {
V_10 -> V_158 = V_216 >> V_159 ;
V_10 -> V_157 = V_216 & 0x07 ;
}
V_10 -> V_174 = ! V_94 ;
if ( V_10 -> V_174 && V_10 -> V_157 == V_224 ) {
V_10 -> V_61 . V_190 = L_76 ;
V_10 -> V_61 . V_106 = 1 ;
V_10 -> V_61 . V_222 = F_25 ;
V_10 -> V_61 . V_223 = F_24 ;
if ( ! F_126 ( & V_10 -> V_26 -> V_10 , & V_10 -> V_61 ) )
V_10 -> V_213 = 1 ;
}
V_94 = F_27 ( V_10 , & V_216 ) ;
V_10 -> V_177 = ! V_94 ;
V_94 = F_31 ( V_10 ) ;
V_10 -> V_179 = ! V_94 ;
V_94 = F_56 ( V_10 , & V_216 ) ;
V_10 -> V_145 = ! V_94 ;
V_94 = F_62 ( V_10 , & V_216 ) ;
V_10 -> V_147 = ! V_94 ;
V_94 = F_127 ( & V_10 -> V_26 -> V_10 . V_168 ,
& V_210 ) ;
if ( V_94 ) {
V_10 -> V_209 = 0 ;
goto error;
}
V_10 -> V_209 = ! V_94 ;
F_72 ( V_10 ) ;
V_184 = V_10 ;
return 0 ;
error:
F_110 ( V_26 ) ;
return V_94 ;
}
static void F_128 ( struct V_208 * V_26 , T_2 V_225 )
{
struct V_9 * V_10 = F_111 ( V_26 ) ;
T_2 V_73 , V_3 ;
int V_226 = 3 ;
int V_189 ;
if ( V_225 != 0x80 )
return;
if ( V_10 -> V_200 ) {
V_189 = F_90 ( V_10 ) ;
if ( V_189 < 0 )
F_12 ( L_77 ) ;
else if ( V_189 != 0 )
F_92 ( V_10 , V_189 ) ;
} else if ( V_10 -> V_135 ) {
do {
F_7 ( V_10 , V_136 , & V_3 , & V_73 ) ;
switch ( V_73 ) {
case V_76 :
F_92 ( V_10 , ( int ) V_3 ) ;
break;
case V_49 :
F_6 ( V_10 , V_136 , 1 ,
& V_73 ) ;
F_67 ( L_36 ) ;
default:
V_226 -- ;
break;
}
} while ( V_226 && V_73 != V_138 );
}
}
static int F_129 ( struct V_152 * V_152 )
{
struct V_9 * V_10 = F_111 ( F_130 ( V_152 ) ) ;
T_2 V_33 ;
if ( V_10 -> V_149 )
F_6 ( V_10 , V_202 , V_227 , & V_33 ) ;
return 0 ;
}
static int F_131 ( struct V_152 * V_152 )
{
struct V_9 * V_10 = F_111 ( F_130 ( V_152 ) ) ;
T_2 V_33 ;
if ( V_10 -> V_149 )
F_6 ( V_10 , V_202 , V_203 , & V_33 ) ;
return 0 ;
}
static int T_11 F_132 ( void )
{
int V_94 ;
if ( F_133 ( V_228 ) )
return - V_60 ;
V_143 = F_134 ( V_229 , V_230 ) ;
if ( ! V_143 ) {
F_12 ( L_78 V_229 L_79 ) ;
return - V_60 ;
}
V_94 = F_135 ( & V_231 ) ;
if ( V_94 ) {
F_12 ( L_80 , V_94 ) ;
F_75 ( V_229 , V_230 ) ;
}
return V_94 ;
}
static void T_12 F_136 ( void )
{
F_137 ( & V_231 ) ;
if ( V_143 )
F_75 ( V_229 , V_230 ) ;
}
