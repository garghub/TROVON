static T_1 void F_1 ( T_2 * V_1 , T_2 V_2 , int V_3 )
{
* V_1 = ( * V_1 & ~ V_2 ) | ( V_2 * V_3 ) ;
}
static int F_2 ( const char * V_4 , int V_5 )
{
struct V_6 V_7 ;
union V_8 V_9 [ 1 ] ;
T_3 V_10 ;
V_7 . V_11 = F_3 ( V_9 ) ;
V_7 . V_12 = V_9 ;
V_9 [ 0 ] . type = V_13 ;
V_9 [ 0 ] . integer . V_3 = V_5 ;
V_10 = F_4 ( NULL , ( char * ) V_4 , & V_7 , NULL ) ;
return ( V_10 == V_14 ) ? 0 : - V_15 ;
}
static T_3 F_5 ( struct V_16 * V_17 ,
const T_2 V_18 [ V_19 ] , T_2 V_20 [ V_19 ] )
{
struct V_6 V_7 ;
union V_8 V_9 [ V_19 ] ;
struct V_21 V_22 ;
union V_8 V_23 [ V_19 + 1 ] ;
T_3 V_10 ;
int V_24 ;
V_7 . V_11 = V_19 ;
V_7 . V_12 = V_9 ;
for ( V_24 = 0 ; V_24 < V_19 ; ++ V_24 ) {
V_9 [ V_24 ] . type = V_13 ;
V_9 [ V_24 ] . integer . V_3 = V_18 [ V_24 ] ;
}
V_22 . V_25 = sizeof( V_23 ) ;
V_22 . V_12 = V_23 ;
V_10 = F_4 ( V_17 -> V_26 -> V_27 ,
( char * ) V_17 -> V_28 , & V_7 ,
& V_22 ) ;
if ( ( V_10 == V_14 ) && ( V_23 -> V_29 . V_11 <= V_19 ) ) {
for ( V_24 = 0 ; V_24 < V_23 -> V_29 . V_11 ; ++ V_24 ) {
V_20 [ V_24 ] = V_23 -> V_29 . V_30 [ V_24 ] . integer . V_3 ;
}
}
return V_10 ;
}
static T_3 F_6 ( struct V_16 * V_17 , T_2 V_31 ,
T_2 V_32 , T_2 * V_33 )
{
T_2 V_18 [ V_19 ] = { V_34 , V_31 , V_32 , 0 , 0 , 0 } ;
T_2 V_20 [ V_19 ] ;
T_3 V_10 = F_5 ( V_17 , V_18 , V_20 ) ;
* V_33 = ( V_10 == V_14 ) ? V_20 [ 0 ] : V_35 ;
return V_10 ;
}
static T_3 F_7 ( struct V_16 * V_17 , T_2 V_31 ,
T_2 * V_36 , T_2 * V_33 )
{
T_2 V_18 [ V_19 ] = { V_37 , V_31 , 0 , 0 , 0 , 0 } ;
T_2 V_20 [ V_19 ] ;
T_3 V_10 = F_5 ( V_17 , V_18 , V_20 ) ;
* V_36 = V_20 [ 2 ] ;
* V_33 = ( V_10 == V_14 ) ? V_20 [ 0 ] : V_35 ;
return V_10 ;
}
static T_3 F_8 ( struct V_16 * V_17 , T_2 V_31 ,
T_2 V_32 , T_2 V_38 , T_2 * V_33 )
{
T_2 V_18 [ V_19 ] = { V_34 , V_31 , V_32 , V_38 , 0 , 0 } ;
T_2 V_20 [ V_19 ] ;
T_3 V_10 = F_5 ( V_17 , V_18 , V_20 ) ;
* V_33 = ( V_10 == V_14 ) ? V_20 [ 0 ] : V_35 ;
return V_10 ;
}
static T_3 F_9 ( struct V_16 * V_17 , T_2 V_31 ,
T_2 * V_36 , T_2 * V_39 , T_2 * V_33 )
{
T_2 V_18 [ V_19 ] = { V_37 , V_31 , * V_36 , * V_39 , 0 , 0 } ;
T_2 V_20 [ V_19 ] ;
T_3 V_10 = F_5 ( V_17 , V_18 , V_20 ) ;
* V_36 = V_20 [ 2 ] ;
* V_39 = V_20 [ 3 ] ;
* V_33 = ( V_10 == V_14 ) ? V_20 [ 0 ] : V_35 ;
return V_10 ;
}
static int F_10 ( struct V_16 * V_17 )
{
T_2 V_18 [ V_19 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
T_2 V_20 [ V_19 ] ;
T_3 V_10 ;
V_18 [ 0 ] = 0xf100 ;
V_10 = F_5 ( V_17 , V_18 , V_20 ) ;
if ( F_11 ( V_10 ) ) {
F_12 ( L_1 ) ;
return 0 ;
}
V_18 [ 0 ] = 0xf400 ;
V_10 = F_5 ( V_17 , V_18 , V_20 ) ;
return 1 ;
}
static void F_13 ( struct V_40 * V_41 ,
enum V_42 V_43 )
{
struct V_16 * V_17 = F_14 ( V_41 ,
struct V_16 , V_44 ) ;
T_2 V_18 [ V_19 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
T_2 V_20 [ V_19 ] ;
T_3 V_10 ;
V_18 [ 0 ] = 0xf100 ;
V_10 = F_5 ( V_17 , V_18 , V_20 ) ;
if ( F_11 ( V_10 ) ) {
F_12 ( L_1 ) ;
return;
}
if ( V_43 ) {
V_18 [ 0 ] = 0xf400 ;
V_18 [ 1 ] = 0x14e ;
V_18 [ 2 ] = 1 ;
V_10 = F_5 ( V_17 , V_18 , V_20 ) ;
if ( F_11 ( V_10 ) ) {
F_12 ( L_2 ) ;
return;
}
} else {
V_18 [ 0 ] = 0xf400 ;
V_18 [ 1 ] = 0x14e ;
V_18 [ 2 ] = 0 ;
V_10 = F_5 ( V_17 , V_18 , V_20 ) ;
if ( F_11 ( V_10 ) ) {
F_12 ( L_3 ) ;
return;
}
}
V_18 [ 0 ] = 0xf200 ;
V_18 [ 1 ] = 0 ;
V_18 [ 2 ] = 0 ;
F_5 ( V_17 , V_18 , V_20 ) ;
}
static enum V_42 F_15 ( struct V_40 * V_41 )
{
struct V_16 * V_17 = F_14 ( V_41 ,
struct V_16 , V_44 ) ;
T_2 V_18 [ V_19 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
T_2 V_20 [ V_19 ] ;
T_3 V_10 ;
enum V_42 V_33 ;
V_18 [ 0 ] = 0xf100 ;
V_10 = F_5 ( V_17 , V_18 , V_20 ) ;
if ( F_11 ( V_10 ) ) {
F_12 ( L_1 ) ;
return V_45 ;
}
V_18 [ 0 ] = 0xf300 ;
V_18 [ 1 ] = 0x14e ;
V_10 = F_5 ( V_17 , V_18 , V_20 ) ;
if ( F_11 ( V_10 ) ) {
F_12 ( L_3 ) ;
return V_45 ;
}
V_33 = V_20 [ 2 ] ? V_46 : V_45 ;
V_18 [ 0 ] = 0xf200 ;
V_18 [ 1 ] = 0 ;
V_18 [ 2 ] = 0 ;
F_5 ( V_17 , V_18 , V_20 ) ;
return V_33 ;
}
static T_2 F_16 ( struct V_16 * V_17 , bool * V_47 )
{
T_2 V_48 ;
T_2 V_3 , V_49 ;
V_3 = 0 ;
V_49 = 0 ;
F_9 ( V_17 , V_50 , & V_3 , & V_49 , & V_48 ) ;
if ( V_48 == V_51 )
* V_47 = ( V_3 & V_52 ) ? true : false ;
return V_48 ;
}
static T_2 F_17 ( struct V_16 * V_17 , bool * V_53 )
{
T_2 V_48 ;
T_2 V_3 , V_49 ;
V_3 = 0 ;
V_49 = 0x0001 ;
F_9 ( V_17 , V_50 , & V_3 , & V_49 , & V_48 ) ;
* V_53 = V_3 & V_54 ;
return V_48 ;
}
static int F_18 ( void * V_55 , bool V_56 )
{
struct V_16 * V_17 = V_55 ;
T_2 V_57 , V_58 ;
T_2 V_3 ;
int V_59 ;
bool V_53 ;
V_3 = ( V_56 == false ) ;
F_19 ( & V_17 -> V_60 ) ;
if ( F_17 ( V_17 , & V_53 ) != V_51 ) {
V_59 = - V_15 ;
goto V_20;
}
if ( ! V_53 ) {
V_59 = 0 ;
goto V_20;
}
F_8 ( V_17 , V_50 , V_3 , V_61 , & V_57 ) ;
F_8 ( V_17 , V_50 , V_3 , V_62 , & V_58 ) ;
if ( V_57 != V_51 || V_58 != V_51 )
V_59 = - V_15 ;
else
V_59 = 0 ;
V_20:
F_20 ( & V_17 -> V_60 ) ;
return V_59 ;
}
static void F_21 ( struct V_63 * V_63 , void * V_55 )
{
bool V_64 ;
bool V_3 ;
T_2 V_48 ;
struct V_16 * V_17 = V_55 ;
F_19 ( & V_17 -> V_60 ) ;
V_48 = F_17 ( V_17 , & V_3 ) ;
if ( V_48 != V_51 ) {
F_20 ( & V_17 -> V_60 ) ;
return;
}
V_64 = V_3 ;
F_20 ( & V_17 -> V_60 ) ;
if ( F_22 ( V_63 , ! V_64 ) )
F_18 ( V_55 , true ) ;
}
static int F_23 ( struct V_65 * V_66 )
{
struct V_16 * V_17 = F_24 ( V_66 ) ;
T_2 V_48 ;
T_2 V_3 ;
F_7 ( V_17 , V_67 , & V_3 , & V_48 ) ;
if ( V_48 == V_51 )
return ( V_3 >> V_68 ) ;
return - V_15 ;
}
static int F_25 ( struct V_69 * V_70 , void * V_71 )
{
struct V_16 * V_17 = V_70 -> V_72 ;
int V_3 ;
if ( ! V_17 -> V_73 )
return - V_74 ;
V_3 = F_23 ( V_17 -> V_73 ) ;
if ( V_3 >= 0 ) {
F_26 ( V_70 , L_4 , V_3 ) ;
F_26 ( V_70 , L_5 ,
V_75 ) ;
return 0 ;
}
F_27 ( L_6 ) ;
return - V_15 ;
}
static int F_28 ( struct V_76 * V_76 , struct V_77 * V_77 )
{
return F_29 ( V_77 , F_25 , F_30 ( V_76 ) -> V_55 ) ;
}
static int F_31 ( struct V_16 * V_17 , int V_3 )
{
T_2 V_48 ;
V_3 = V_3 << V_68 ;
F_6 ( V_17 , V_67 , V_3 , & V_48 ) ;
return V_48 == V_51 ? 0 : - V_15 ;
}
static int F_32 ( struct V_65 * V_66 )
{
struct V_16 * V_17 = F_24 ( V_66 ) ;
return F_31 ( V_17 , V_66 -> V_78 . V_43 ) ;
}
static T_4 F_33 ( struct V_77 * V_77 , const char T_5 * V_79 ,
T_6 V_11 , T_7 * V_80 )
{
struct V_16 * V_17 = F_30 ( V_77 -> V_81 . V_82 -> V_83 ) -> V_55 ;
char V_84 [ 42 ] ;
T_6 V_85 ;
int V_3 ;
int V_86 ;
V_85 = F_34 ( V_11 , sizeof( V_84 ) - 1 ) ;
if ( F_35 ( V_84 , V_79 , V_85 ) )
return - V_87 ;
V_84 [ V_85 ] = '\0' ;
if ( sscanf ( V_84 , L_7 , & V_3 ) == 1 &&
V_3 >= 0 && V_3 < V_75 ) {
V_86 = F_31 ( V_17 , V_3 ) ;
if ( V_86 == 0 )
V_86 = V_11 ;
} else {
V_86 = - V_88 ;
}
return V_86 ;
}
static int F_36 ( struct V_16 * V_17 , T_2 * V_10 )
{
T_2 V_48 ;
F_7 ( V_17 , V_89 , V_10 , & V_48 ) ;
return V_48 == V_51 ? 0 : - V_15 ;
}
static int F_37 ( struct V_69 * V_70 , void * V_71 )
{
struct V_16 * V_17 = V_70 -> V_72 ;
T_2 V_3 ;
int V_86 ;
V_86 = F_36 ( V_17 , & V_3 ) ;
if ( ! V_86 ) {
int V_90 = ( V_3 & V_91 ) ? 1 : 0 ;
int V_92 = ( V_3 & V_93 ) ? 1 : 0 ;
int V_94 = ( V_3 & V_95 ) ? 1 : 0 ;
F_26 ( V_70 , L_8 , V_90 ) ;
F_26 ( V_70 , L_9 , V_92 ) ;
F_26 ( V_70 , L_10 , V_94 ) ;
}
return V_86 ;
}
static int F_38 ( struct V_76 * V_76 , struct V_77 * V_77 )
{
return F_29 ( V_77 , F_37 , F_30 ( V_76 ) -> V_55 ) ;
}
static T_4 F_39 ( struct V_77 * V_77 , const char T_5 * V_79 ,
T_6 V_11 , T_7 * V_80 )
{
struct V_16 * V_17 = F_30 ( V_77 -> V_81 . V_82 -> V_83 ) -> V_55 ;
char * V_84 , * V_96 ;
int V_86 ;
int V_3 ;
int V_97 = V_11 ;
int V_98 = - 1 ;
int V_99 = - 1 ;
int V_100 = - 1 ;
T_2 V_101 ;
V_84 = F_40 ( V_11 + 1 , V_102 ) ;
if ( ! V_84 )
return - V_103 ;
if ( F_35 ( V_84 , V_79 , V_11 ) ) {
F_41 ( V_84 ) ;
return - V_87 ;
}
V_84 [ V_11 ] = '\0' ;
V_96 = V_84 ;
while ( V_97 ) {
if ( sscanf ( V_96 , L_11 , & V_3 ) == 1 )
V_98 = V_3 & 1 ;
else if ( sscanf ( V_96 , L_12 , & V_3 ) == 1 )
V_99 = V_3 & 1 ;
else if ( sscanf ( V_96 , L_13 , & V_3 ) == 1 )
V_100 = V_3 & 1 ;
do {
++ V_96 ;
-- V_97 ;
}
while ( V_97 && * ( V_96 - 1 ) != ';' );
}
F_41 ( V_84 ) ;
V_86 = F_36 ( V_17 , & V_101 ) ;
if ( ! V_86 ) {
unsigned int V_104 = V_101 ;
if ( V_98 != - 1 )
F_1 ( & V_104 , V_91 , V_98 ) ;
if ( V_99 != - 1 )
F_1 ( & V_104 , V_93 , V_99 ) ;
if ( V_100 != - 1 )
F_1 ( & V_104 , V_95 , V_100 ) ;
if ( V_104 != V_101 )
V_86 = F_2 ( V_105 , V_104 ) ;
}
return V_86 ? V_86 : V_11 ;
}
static int F_42 ( struct V_16 * V_17 , T_2 * V_10 )
{
T_2 V_48 ;
F_7 ( V_17 , V_106 , V_10 , & V_48 ) ;
return V_48 == V_51 ? 0 : - V_15 ;
}
static int F_43 ( struct V_69 * V_70 , void * V_71 )
{
struct V_16 * V_17 = V_70 -> V_72 ;
int V_86 ;
T_2 V_3 ;
V_86 = F_42 ( V_17 , & V_3 ) ;
if ( ! V_86 ) {
F_26 ( V_70 , L_14 , ( V_3 > 0 ) ) ;
F_26 ( V_70 , L_15 , V_17 -> V_107 ) ;
}
return V_86 ;
}
static int F_44 ( struct V_76 * V_76 , struct V_77 * V_77 )
{
return F_29 ( V_77 , F_43 , F_30 ( V_76 ) -> V_55 ) ;
}
static T_4 F_45 ( struct V_77 * V_77 , const char T_5 * V_79 ,
T_6 V_11 , T_7 * V_80 )
{
struct V_16 * V_17 = F_30 ( V_77 -> V_81 . V_82 -> V_83 ) -> V_55 ;
char V_84 [ 42 ] ;
T_6 V_85 ;
int V_3 ;
T_2 V_48 ;
V_85 = F_34 ( V_11 , sizeof( V_84 ) - 1 ) ;
if ( F_35 ( V_84 , V_79 , V_85 ) )
return - V_87 ;
V_84 [ V_85 ] = '\0' ;
if ( sscanf ( V_84 , L_16 , & V_3 ) == 1 &&
V_3 >= 0 && V_3 <= 1 ) {
F_6 ( V_17 , V_106 , V_3 , & V_48 ) ;
if ( V_48 != V_51 )
return - V_15 ;
else
V_17 -> V_107 = V_3 ;
} else {
return - V_88 ;
}
return V_11 ;
}
static int F_46 ( struct V_69 * V_70 , void * V_71 )
{
struct V_16 * V_17 = V_70 -> V_72 ;
T_2 V_48 ;
T_2 V_3 ;
if ( ! V_17 -> V_108 && V_17 -> V_109 ) {
F_7 ( V_17 , V_110 , & V_3 , & V_48 ) ;
if ( V_48 == V_51 ) {
V_17 -> V_108 = 1 ;
V_17 -> V_111 = V_3 ;
} else if ( V_48 == V_112 ) {
} else if ( V_48 == V_113 ) {
F_6 ( V_17 , V_110 , 1 , & V_48 ) ;
F_47 ( L_17 ) ;
} else {
F_27 ( L_18 ) ;
return - V_15 ;
}
}
F_26 ( V_70 , L_19 , V_17 -> V_108 ) ;
F_26 ( V_70 , L_20 , V_17 -> V_111 ) ;
return 0 ;
}
static int F_48 ( struct V_76 * V_76 , struct V_77 * V_77 )
{
return F_29 ( V_77 , F_46 , F_30 ( V_76 ) -> V_55 ) ;
}
static T_4 F_49 ( struct V_77 * V_77 , const char T_5 * V_79 ,
T_6 V_11 , T_7 * V_80 )
{
struct V_16 * V_17 = F_30 ( V_77 -> V_81 . V_82 -> V_83 ) -> V_55 ;
char V_84 [ 42 ] ;
T_6 V_85 ;
int V_3 ;
V_85 = F_34 ( V_11 , sizeof( V_84 ) - 1 ) ;
if ( F_35 ( V_84 , V_79 , V_85 ) )
return - V_87 ;
V_84 [ V_85 ] = '\0' ;
if ( sscanf ( V_84 , L_21 , & V_3 ) == 1 && V_3 == 0 ) {
V_17 -> V_108 = 0 ;
} else {
return - V_88 ;
}
return V_11 ;
}
static int F_50 ( struct V_69 * V_70 , void * V_71 )
{
F_26 ( V_70 , L_22 , V_114 ) ;
F_26 ( V_70 , L_23 , V_115 ) ;
return 0 ;
}
static int F_51 ( struct V_76 * V_76 , struct V_77 * V_77 )
{
return F_29 ( V_77 , F_50 , F_30 ( V_76 ) -> V_55 ) ;
}
static void T_8
F_52 ( struct V_16 * V_17 )
{
if ( V_17 -> V_73 )
F_53 ( L_24 , V_116 | V_117 , V_118 ,
& V_119 , V_17 ) ;
if ( V_17 -> V_120 )
F_53 ( L_25 , V_116 | V_117 , V_118 ,
& V_121 , V_17 ) ;
if ( V_17 -> V_122 )
F_53 ( L_26 , V_116 | V_117 , V_118 ,
& V_123 , V_17 ) ;
if ( V_17 -> V_124 )
F_53 ( L_27 , V_116 | V_117 , V_118 ,
& V_125 , V_17 ) ;
F_53 ( L_28 , V_116 , V_118 ,
& V_126 , V_17 ) ;
}
static void F_54 ( struct V_16 * V_17 )
{
if ( V_17 -> V_73 )
F_55 ( L_24 , V_118 ) ;
if ( V_17 -> V_120 )
F_55 ( L_25 , V_118 ) ;
if ( V_17 -> V_122 )
F_55 ( L_26 , V_118 ) ;
if ( V_17 -> V_124 )
F_55 ( L_27 , V_118 ) ;
F_55 ( L_28 , V_118 ) ;
}
static bool F_56 ( unsigned char V_55 , unsigned char V_127 ,
struct V_128 * V_129 )
{
if ( V_127 & 0x20 )
return false ;
if ( F_57 ( V_55 == 0xe0 ) )
return false ;
if ( ( V_55 & 0x7f ) == V_130 ) {
F_58 ( & V_131 -> V_132 ) ;
return true ;
}
return false ;
}
static void F_59 ( struct V_133 * V_134 )
{
T_9 V_135 = F_60 () ;
T_3 V_10 ;
if ( ! V_135 )
return;
V_10 = F_4 ( V_135 , L_29 , NULL , NULL ) ;
if ( F_11 ( V_10 ) )
F_27 ( L_30 ) ;
}
static int F_61 ( struct V_16 * V_17 )
{
struct V_21 V_79 ;
union V_8 V_136 ;
T_3 V_10 ;
V_79 . V_12 = & V_136 ;
V_79 . V_25 = sizeof( V_136 ) ;
V_10 = F_4 ( V_17 -> V_26 -> V_27 , L_31 ,
NULL , & V_79 ) ;
if ( F_11 ( V_10 ) || V_136 . type != V_13 ) {
F_27 ( L_32 ) ;
return - V_15 ;
}
return V_136 . integer . V_3 ;
}
static void F_62 ( struct V_16 * V_17 ,
int V_137 )
{
if ( V_137 == 0x100 )
return;
if ( V_137 & 0x80 )
return;
if ( ! F_63 ( V_17 -> V_124 , V_137 , 1 , true ) )
F_12 ( L_33 , V_137 ) ;
}
static int T_8 F_64 ( struct V_16 * V_17 )
{
T_3 V_10 ;
T_9 V_135 , V_27 ;
int error ;
T_2 V_48 ;
V_17 -> V_124 = F_65 () ;
if ( ! V_17 -> V_124 ) {
F_12 ( L_34 ) ;
return - V_103 ;
}
V_17 -> V_124 -> V_138 = L_35 ;
V_17 -> V_124 -> V_139 = L_36 ;
V_17 -> V_124 -> V_140 . V_141 = V_142 ;
error = F_66 ( V_17 -> V_124 , V_143 , NULL ) ;
if ( error )
goto V_144;
V_10 = V_145 ;
V_135 = F_60 () ;
if ( V_135 )
V_10 = F_67 ( V_135 , L_29 , & V_27 ) ;
if ( F_68 ( V_10 ) ) {
F_69 ( & V_17 -> V_132 , F_59 ) ;
error = F_70 ( F_56 ) ;
if ( error ) {
F_27 ( L_37 ) ;
goto V_146;
}
V_17 -> V_147 = 1 ;
}
V_10 = F_67 ( V_17 -> V_26 -> V_27 , L_31 , & V_27 ) ;
if ( F_68 ( V_10 ) ) {
V_17 -> V_148 = 1 ;
} else {
F_6 ( V_17 , V_110 , 1 , & V_48 ) ;
if ( V_48 == V_51 )
V_17 -> V_109 = 1 ;
}
if ( ! V_17 -> V_148 && ! V_17 -> V_109 ) {
F_71 ( L_38 ) ;
goto V_149;
}
V_10 = F_4 ( V_17 -> V_26 -> V_27 , L_39 , NULL , NULL ) ;
if ( F_11 ( V_10 ) ) {
F_12 ( L_40 ) ;
error = - V_74 ;
goto V_149;
}
error = F_72 ( V_17 -> V_124 ) ;
if ( error ) {
F_12 ( L_34 ) ;
goto V_149;
}
F_6 ( V_17 , V_150 , V_151 , & V_48 ) ;
return 0 ;
V_149:
if ( V_17 -> V_147 )
F_73 ( F_56 ) ;
V_146:
F_74 ( V_17 -> V_124 ) ;
V_144:
F_75 ( V_17 -> V_124 ) ;
V_17 -> V_124 = NULL ;
return error ;
}
static int F_76 ( struct V_152 * V_26 , int type )
{
struct V_16 * V_17 = F_77 ( V_26 ) ;
F_54 ( V_17 ) ;
if ( V_17 -> V_147 ) {
F_73 ( F_56 ) ;
F_78 ( & V_17 -> V_132 ) ;
}
if ( V_17 -> V_124 ) {
F_79 ( V_17 -> V_124 ) ;
F_74 ( V_17 -> V_124 ) ;
}
if ( V_17 -> V_153 ) {
F_80 ( V_17 -> V_153 ) ;
F_81 ( V_17 -> V_153 ) ;
}
if ( V_17 -> V_73 )
F_82 ( V_17 -> V_73 ) ;
if ( V_17 -> V_154 )
F_83 ( & V_17 -> V_44 ) ;
if ( V_131 )
V_131 = NULL ;
F_41 ( V_17 ) ;
return 0 ;
}
static const char * T_8 F_84 ( T_9 V_27 )
{
T_3 V_10 ;
T_9 V_155 ;
V_10 = F_67 ( V_27 , L_41 , & V_155 ) ;
if ( F_68 ( V_10 ) )
return L_41 ;
V_10 = F_67 ( V_27 , L_42 , & V_155 ) ;
if ( F_68 ( V_10 ) )
return L_42 ;
return NULL ;
}
static int T_8 F_85 ( struct V_152 * V_26 )
{
struct V_16 * V_17 ;
const char * V_156 ;
T_2 V_157 ;
bool V_158 ;
int V_86 = 0 ;
struct V_159 V_78 ;
if ( V_131 )
return - V_160 ;
F_12 ( L_43 ,
V_114 ) ;
V_156 = F_84 ( V_26 -> V_27 ) ;
if ( ! V_156 ) {
F_27 ( L_44 ) ;
return - V_74 ;
}
V_17 = F_86 ( sizeof( * V_17 ) , V_102 ) ;
if ( ! V_17 )
return - V_103 ;
V_17 -> V_26 = V_26 ;
V_17 -> V_28 = V_156 ;
V_26 -> V_161 = V_17 ;
if ( F_64 ( V_17 ) )
F_12 ( L_45 ) ;
F_87 ( & V_17 -> V_60 ) ;
V_78 . type = V_162 ;
V_78 . V_163 = V_75 - 1 ;
V_17 -> V_73 = F_88 ( L_46 ,
& V_26 -> V_17 ,
V_17 ,
& V_164 ,
& V_78 ) ;
if ( F_89 ( V_17 -> V_73 ) ) {
V_86 = F_90 ( V_17 -> V_73 ) ;
F_27 ( L_47 ) ;
V_17 -> V_73 = NULL ;
goto error;
}
V_17 -> V_73 -> V_78 . V_43 = F_23 ( V_17 -> V_73 ) ;
if ( F_16 ( V_17 , & V_158 ) == V_51 && V_158 ) {
V_17 -> V_153 = F_91 ( L_48 ,
& V_26 -> V_17 ,
V_165 ,
& V_166 ,
V_17 ) ;
if ( ! V_17 -> V_153 ) {
F_27 ( L_49 ) ;
V_86 = - V_103 ;
goto error;
}
V_86 = F_92 ( V_17 -> V_153 ) ;
if ( V_86 ) {
F_27 ( L_50 ) ;
F_81 ( V_17 -> V_153 ) ;
goto error;
}
}
if ( F_10 ( V_17 ) ) {
V_17 -> V_44 . V_138 = L_51 ;
V_17 -> V_44 . V_163 = 1 ;
V_17 -> V_44 . V_167 = F_13 ;
V_17 -> V_44 . V_168 = F_15 ;
if ( ! F_93 ( & V_26 -> V_17 , & V_17 -> V_44 ) )
V_17 -> V_154 = 1 ;
}
V_86 = F_36 ( V_17 , & V_157 ) ;
V_17 -> V_120 = ! V_86 ;
V_86 = F_42 ( V_17 , & V_157 ) ;
V_17 -> V_122 = ! V_86 ;
F_52 ( V_17 ) ;
V_131 = V_17 ;
return 0 ;
error:
F_76 ( V_26 , 0 ) ;
return V_86 ;
}
static void F_94 ( struct V_152 * V_26 , T_2 V_169 )
{
struct V_16 * V_17 = F_77 ( V_26 ) ;
T_2 V_48 , V_3 ;
int V_170 = 3 ;
int V_137 ;
if ( V_169 != 0x80 )
return;
if ( V_17 -> V_148 ) {
V_137 = F_61 ( V_17 ) ;
if ( V_137 < 0 )
F_27 ( L_52 ) ;
else if ( V_137 != 0 )
F_62 ( V_17 , V_137 ) ;
} else if ( V_17 -> V_109 ) {
do {
F_7 ( V_17 , V_110 , & V_3 , & V_48 ) ;
switch ( V_48 ) {
case V_51 :
F_62 ( V_17 , ( int ) V_3 ) ;
break;
case V_113 :
F_6 ( V_17 , V_110 , 1 ,
& V_48 ) ;
F_47 ( L_17 ) ;
default:
V_170 -- ;
break;
}
} while ( V_170 && V_48 != V_112 );
}
}
static int F_95 ( struct V_152 * V_26 ,
T_10 V_171 )
{
struct V_16 * V_17 = F_77 ( V_26 ) ;
T_2 V_33 ;
if ( V_17 -> V_124 )
F_6 ( V_17 , V_150 , V_172 , & V_33 ) ;
return 0 ;
}
static int F_96 ( struct V_152 * V_26 )
{
struct V_16 * V_17 = F_77 ( V_26 ) ;
T_2 V_33 ;
if ( V_17 -> V_124 )
F_6 ( V_17 , V_150 , V_151 , & V_33 ) ;
return 0 ;
}
static int T_11 F_97 ( void )
{
int V_86 ;
if ( F_98 ( V_173 ) )
return - V_74 ;
V_118 = F_99 ( V_174 , V_175 ) ;
if ( ! V_118 ) {
F_27 ( L_53 V_174 L_54 ) ;
return - V_74 ;
}
V_86 = F_100 ( & V_176 ) ;
if ( V_86 ) {
F_27 ( L_55 , V_86 ) ;
F_55 ( V_174 , V_175 ) ;
}
return V_86 ;
}
static void T_12 F_101 ( void )
{
F_102 ( & V_176 ) ;
if ( V_118 )
F_55 ( V_174 , V_175 ) ;
}
