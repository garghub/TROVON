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
static int F_23 ( struct V_16 * V_17 , bool * V_65 )
{
T_2 V_48 ;
T_2 V_10 ;
F_7 ( V_17 , V_66 , & V_10 , & V_48 ) ;
* V_65 = ! V_10 ;
return V_48 == V_51 ? 0 : - V_15 ;
}
static int F_24 ( struct V_16 * V_17 , bool V_67 )
{
T_2 V_48 ;
T_2 V_3 = ! V_67 ;
F_6 ( V_17 , V_66 , V_3 , & V_48 ) ;
return V_48 == V_51 ? 0 : - V_15 ;
}
static int F_25 ( struct V_16 * V_17 )
{
T_2 V_48 ;
T_2 V_3 ;
int V_43 = 0 ;
if ( V_17 -> V_68 ) {
bool V_65 ;
int V_69 = F_23 ( V_17 , & V_65 ) ;
if ( V_69 )
return V_69 ;
if ( V_65 )
return 0 ;
V_43 ++ ;
}
F_7 ( V_17 , V_70 , & V_3 , & V_48 ) ;
if ( V_48 == V_51 )
return V_43 + ( V_3 >> V_71 ) ;
return - V_15 ;
}
static int F_26 ( struct V_72 * V_73 )
{
struct V_16 * V_17 = F_27 ( V_73 ) ;
return F_25 ( V_17 ) ;
}
static int F_28 ( struct V_74 * V_75 , void * V_76 )
{
struct V_16 * V_17 = V_75 -> V_77 ;
int V_3 ;
int V_78 ;
if ( ! V_17 -> V_79 )
return - V_80 ;
V_78 = V_17 -> V_79 -> V_81 . V_82 + 1 ;
V_3 = F_26 ( V_17 -> V_79 ) ;
if ( V_3 >= 0 ) {
F_29 ( V_75 , L_4 , V_3 ) ;
F_29 ( V_75 , L_5 , V_78 ) ;
return 0 ;
}
F_30 ( L_6 ) ;
return - V_15 ;
}
static int F_31 ( struct V_83 * V_83 , struct V_84 * V_84 )
{
return F_32 ( V_84 , F_28 , F_33 ( V_83 ) ) ;
}
static int F_34 ( struct V_16 * V_17 , int V_3 )
{
T_2 V_48 ;
if ( V_17 -> V_68 ) {
bool V_67 = ! V_3 ;
int V_69 = F_24 ( V_17 , V_67 ) ;
if ( V_69 )
return V_69 ;
if ( V_3 )
V_3 -- ;
}
V_3 = V_3 << V_71 ;
F_6 ( V_17 , V_70 , V_3 , & V_48 ) ;
return V_48 == V_51 ? 0 : - V_15 ;
}
static int F_35 ( struct V_72 * V_73 )
{
struct V_16 * V_17 = F_27 ( V_73 ) ;
return F_34 ( V_17 , V_73 -> V_81 . V_43 ) ;
}
static T_4 F_36 ( struct V_84 * V_84 , const char T_5 * V_85 ,
T_6 V_11 , T_7 * V_86 )
{
struct V_16 * V_17 = F_33 ( F_37 ( V_84 ) ) ;
char V_87 [ 42 ] ;
T_6 V_88 ;
int V_3 ;
int V_69 ;
int V_78 = V_17 -> V_79 -> V_81 . V_82 + 1 ;
V_88 = F_38 ( V_11 , sizeof( V_87 ) - 1 ) ;
if ( F_39 ( V_87 , V_85 , V_88 ) )
return - V_89 ;
V_87 [ V_88 ] = '\0' ;
if ( sscanf ( V_87 , L_7 , & V_3 ) == 1 &&
V_3 >= 0 && V_3 < V_78 ) {
V_69 = F_34 ( V_17 , V_3 ) ;
if ( V_69 == 0 )
V_69 = V_11 ;
} else {
V_69 = - V_90 ;
}
return V_69 ;
}
static int F_40 ( struct V_16 * V_17 , T_2 * V_10 )
{
T_2 V_48 ;
F_7 ( V_17 , V_91 , V_10 , & V_48 ) ;
return V_48 == V_51 ? 0 : - V_15 ;
}
static int F_41 ( struct V_74 * V_75 , void * V_76 )
{
struct V_16 * V_17 = V_75 -> V_77 ;
T_2 V_3 ;
int V_69 ;
V_69 = F_40 ( V_17 , & V_3 ) ;
if ( ! V_69 ) {
int V_92 = ( V_3 & V_93 ) ? 1 : 0 ;
int V_94 = ( V_3 & V_95 ) ? 1 : 0 ;
int V_96 = ( V_3 & V_97 ) ? 1 : 0 ;
F_29 ( V_75 , L_8 , V_92 ) ;
F_29 ( V_75 , L_9 , V_94 ) ;
F_29 ( V_75 , L_10 , V_96 ) ;
}
return V_69 ;
}
static int F_42 ( struct V_83 * V_83 , struct V_84 * V_84 )
{
return F_32 ( V_84 , F_41 , F_33 ( V_83 ) ) ;
}
static T_4 F_43 ( struct V_84 * V_84 , const char T_5 * V_85 ,
T_6 V_11 , T_7 * V_86 )
{
struct V_16 * V_17 = F_33 ( F_37 ( V_84 ) ) ;
char * V_87 , * V_98 ;
int V_69 ;
int V_3 ;
int V_99 = V_11 ;
int V_100 = - 1 ;
int V_101 = - 1 ;
int V_102 = - 1 ;
T_2 V_103 ;
V_87 = F_44 ( V_11 + 1 , V_104 ) ;
if ( ! V_87 )
return - V_105 ;
if ( F_39 ( V_87 , V_85 , V_11 ) ) {
F_45 ( V_87 ) ;
return - V_89 ;
}
V_87 [ V_11 ] = '\0' ;
V_98 = V_87 ;
while ( V_99 ) {
if ( sscanf ( V_98 , L_11 , & V_3 ) == 1 )
V_100 = V_3 & 1 ;
else if ( sscanf ( V_98 , L_12 , & V_3 ) == 1 )
V_101 = V_3 & 1 ;
else if ( sscanf ( V_98 , L_13 , & V_3 ) == 1 )
V_102 = V_3 & 1 ;
do {
++ V_98 ;
-- V_99 ;
}
while ( V_99 && * ( V_98 - 1 ) != ';' );
}
F_45 ( V_87 ) ;
V_69 = F_40 ( V_17 , & V_103 ) ;
if ( ! V_69 ) {
unsigned int V_106 = V_103 ;
if ( V_100 != - 1 )
F_1 ( & V_106 , V_93 , V_100 ) ;
if ( V_101 != - 1 )
F_1 ( & V_106 , V_95 , V_101 ) ;
if ( V_102 != - 1 )
F_1 ( & V_106 , V_97 , V_102 ) ;
if ( V_106 != V_103 )
V_69 = F_2 ( V_107 , V_106 ) ;
}
return V_69 ? V_69 : V_11 ;
}
static int F_46 ( struct V_16 * V_17 , T_2 * V_10 )
{
T_2 V_48 ;
F_7 ( V_17 , V_108 , V_10 , & V_48 ) ;
return V_48 == V_51 ? 0 : - V_15 ;
}
static int F_47 ( struct V_74 * V_75 , void * V_76 )
{
struct V_16 * V_17 = V_75 -> V_77 ;
int V_69 ;
T_2 V_3 ;
V_69 = F_46 ( V_17 , & V_3 ) ;
if ( ! V_69 ) {
F_29 ( V_75 , L_14 , ( V_3 > 0 ) ) ;
F_29 ( V_75 , L_15 , V_17 -> V_109 ) ;
}
return V_69 ;
}
static int F_48 ( struct V_83 * V_83 , struct V_84 * V_84 )
{
return F_32 ( V_84 , F_47 , F_33 ( V_83 ) ) ;
}
static T_4 F_49 ( struct V_84 * V_84 , const char T_5 * V_85 ,
T_6 V_11 , T_7 * V_86 )
{
struct V_16 * V_17 = F_33 ( F_37 ( V_84 ) ) ;
char V_87 [ 42 ] ;
T_6 V_88 ;
int V_3 ;
T_2 V_48 ;
V_88 = F_38 ( V_11 , sizeof( V_87 ) - 1 ) ;
if ( F_39 ( V_87 , V_85 , V_88 ) )
return - V_89 ;
V_87 [ V_88 ] = '\0' ;
if ( sscanf ( V_87 , L_16 , & V_3 ) == 1 &&
V_3 >= 0 && V_3 <= 1 ) {
F_6 ( V_17 , V_108 , V_3 , & V_48 ) ;
if ( V_48 != V_51 )
return - V_15 ;
else
V_17 -> V_109 = V_3 ;
} else {
return - V_90 ;
}
return V_11 ;
}
static int F_50 ( struct V_74 * V_75 , void * V_76 )
{
struct V_16 * V_17 = V_75 -> V_77 ;
T_2 V_48 ;
T_2 V_3 ;
if ( ! V_17 -> V_110 && V_17 -> V_111 ) {
F_7 ( V_17 , V_112 , & V_3 , & V_48 ) ;
if ( V_48 == V_51 ) {
V_17 -> V_110 = 1 ;
V_17 -> V_113 = V_3 ;
} else if ( V_48 == V_114 ) {
} else if ( V_48 == V_115 ) {
F_6 ( V_17 , V_112 , 1 , & V_48 ) ;
F_51 ( L_17 ) ;
} else {
F_30 ( L_18 ) ;
return - V_15 ;
}
}
F_29 ( V_75 , L_19 , V_17 -> V_110 ) ;
F_29 ( V_75 , L_20 , V_17 -> V_113 ) ;
return 0 ;
}
static int F_52 ( struct V_83 * V_83 , struct V_84 * V_84 )
{
return F_32 ( V_84 , F_50 , F_33 ( V_83 ) ) ;
}
static T_4 F_53 ( struct V_84 * V_84 , const char T_5 * V_85 ,
T_6 V_11 , T_7 * V_86 )
{
struct V_16 * V_17 = F_33 ( F_37 ( V_84 ) ) ;
char V_87 [ 42 ] ;
T_6 V_88 ;
int V_3 ;
V_88 = F_38 ( V_11 , sizeof( V_87 ) - 1 ) ;
if ( F_39 ( V_87 , V_85 , V_88 ) )
return - V_89 ;
V_87 [ V_88 ] = '\0' ;
if ( sscanf ( V_87 , L_21 , & V_3 ) == 1 && V_3 == 0 ) {
V_17 -> V_110 = 0 ;
} else {
return - V_90 ;
}
return V_11 ;
}
static int F_54 ( struct V_74 * V_75 , void * V_76 )
{
F_29 ( V_75 , L_22 , V_116 ) ;
F_29 ( V_75 , L_23 , V_117 ) ;
return 0 ;
}
static int F_55 ( struct V_83 * V_83 , struct V_84 * V_84 )
{
return F_32 ( V_84 , F_54 , F_33 ( V_83 ) ) ;
}
static void F_56 ( struct V_16 * V_17 )
{
if ( V_17 -> V_79 )
F_57 ( L_24 , V_118 | V_119 , V_120 ,
& V_121 , V_17 ) ;
if ( V_17 -> V_122 )
F_57 ( L_25 , V_118 | V_119 , V_120 ,
& V_123 , V_17 ) ;
if ( V_17 -> V_124 )
F_57 ( L_26 , V_118 | V_119 , V_120 ,
& V_125 , V_17 ) ;
if ( V_17 -> V_126 )
F_57 ( L_27 , V_118 | V_119 , V_120 ,
& V_127 , V_17 ) ;
F_57 ( L_28 , V_118 , V_120 ,
& V_128 , V_17 ) ;
}
static void F_58 ( struct V_16 * V_17 )
{
if ( V_17 -> V_79 )
F_59 ( L_24 , V_120 ) ;
if ( V_17 -> V_122 )
F_59 ( L_25 , V_120 ) ;
if ( V_17 -> V_124 )
F_59 ( L_26 , V_120 ) ;
if ( V_17 -> V_126 )
F_59 ( L_27 , V_120 ) ;
F_59 ( L_28 , V_120 ) ;
}
static bool F_60 ( unsigned char V_55 , unsigned char V_129 ,
struct V_130 * V_131 )
{
if ( V_129 & 0x20 )
return false ;
if ( F_61 ( V_55 == 0xe0 ) )
return false ;
if ( ( V_55 & 0x7f ) == V_132 ) {
F_62 ( & V_133 -> V_134 ) ;
return true ;
}
return false ;
}
static void F_63 ( struct V_135 * V_136 )
{
T_8 V_137 = F_64 () ;
T_3 V_10 ;
if ( ! V_137 )
return;
V_10 = F_4 ( V_137 , L_29 , NULL , NULL ) ;
if ( F_11 ( V_10 ) )
F_30 ( L_30 ) ;
}
static int F_65 ( struct V_16 * V_17 )
{
struct V_21 V_85 ;
union V_8 V_138 ;
T_3 V_10 ;
V_85 . V_12 = & V_138 ;
V_85 . V_25 = sizeof( V_138 ) ;
V_10 = F_4 ( V_17 -> V_26 -> V_27 , L_31 ,
NULL , & V_85 ) ;
if ( F_11 ( V_10 ) || V_138 . type != V_13 ) {
F_30 ( L_32 ) ;
return - V_15 ;
}
return V_138 . integer . V_3 ;
}
static void F_66 ( struct V_16 * V_17 ,
int V_139 )
{
if ( V_139 == 0x100 )
return;
if ( V_139 & 0x80 )
return;
if ( ! F_67 ( V_17 -> V_126 , V_139 , 1 , true ) )
F_12 ( L_33 , V_139 ) ;
}
static int F_68 ( struct V_16 * V_17 )
{
T_3 V_10 ;
T_8 V_137 , V_27 ;
int error ;
T_2 V_48 ;
V_17 -> V_126 = F_69 () ;
if ( ! V_17 -> V_126 ) {
F_12 ( L_34 ) ;
return - V_105 ;
}
V_17 -> V_126 -> V_140 = L_35 ;
V_17 -> V_126 -> V_141 = L_36 ;
V_17 -> V_126 -> V_142 . V_143 = V_144 ;
error = F_70 ( V_17 -> V_126 , V_145 , NULL ) ;
if ( error )
goto V_146;
V_10 = V_147 ;
V_137 = F_64 () ;
if ( V_137 )
V_10 = F_71 ( V_137 , L_29 , & V_27 ) ;
if ( F_72 ( V_10 ) ) {
F_73 ( & V_17 -> V_134 , F_63 ) ;
error = F_74 ( F_60 ) ;
if ( error ) {
F_30 ( L_37 ) ;
goto V_148;
}
V_17 -> V_149 = 1 ;
}
V_10 = F_71 ( V_17 -> V_26 -> V_27 , L_31 , & V_27 ) ;
if ( F_72 ( V_10 ) ) {
V_17 -> V_150 = 1 ;
} else {
F_6 ( V_17 , V_112 , 1 , & V_48 ) ;
if ( V_48 == V_51 )
V_17 -> V_111 = 1 ;
}
if ( ! V_17 -> V_150 && ! V_17 -> V_111 ) {
F_75 ( L_38 ) ;
goto V_151;
}
V_10 = F_4 ( V_17 -> V_26 -> V_27 , L_39 , NULL , NULL ) ;
if ( F_11 ( V_10 ) ) {
F_12 ( L_40 ) ;
error = - V_80 ;
goto V_151;
}
error = F_76 ( V_17 -> V_126 ) ;
if ( error ) {
F_12 ( L_34 ) ;
goto V_151;
}
F_6 ( V_17 , V_152 , V_153 , & V_48 ) ;
return 0 ;
V_151:
if ( V_17 -> V_149 )
F_77 ( F_60 ) ;
V_148:
F_78 ( V_17 -> V_126 ) ;
V_146:
F_79 ( V_17 -> V_126 ) ;
V_17 -> V_126 = NULL ;
return error ;
}
static int F_80 ( struct V_16 * V_17 )
{
struct V_154 V_81 ;
int V_43 ;
int V_69 ;
bool V_65 ;
V_43 = F_25 ( V_17 ) ;
if ( V_43 < 0 )
return 0 ;
V_69 = F_34 ( V_17 , V_43 ) ;
if ( V_69 ) {
F_81 ( L_41 ) ;
return 0 ;
}
V_69 = F_23 ( V_17 , & V_65 ) ;
V_17 -> V_68 = ! V_69 ;
memset ( & V_81 , 0 , sizeof( V_81 ) ) ;
V_81 . type = V_155 ;
V_81 . V_82 = V_156 - 1 ;
if ( V_17 -> V_68 )
V_81 . V_82 ++ ;
V_17 -> V_79 = F_82 ( L_42 ,
& V_17 -> V_26 -> V_17 ,
V_17 ,
& V_157 ,
& V_81 ) ;
if ( F_83 ( V_17 -> V_79 ) ) {
V_69 = F_84 ( V_17 -> V_79 ) ;
F_30 ( L_43 ) ;
V_17 -> V_79 = NULL ;
return V_69 ;
}
V_17 -> V_79 -> V_81 . V_43 = V_43 ;
return 0 ;
}
static int F_85 ( struct V_158 * V_26 )
{
struct V_16 * V_17 = F_86 ( V_26 ) ;
F_58 ( V_17 ) ;
if ( V_17 -> V_149 ) {
F_77 ( F_60 ) ;
F_87 ( & V_17 -> V_134 ) ;
}
if ( V_17 -> V_126 ) {
F_88 ( V_17 -> V_126 ) ;
F_78 ( V_17 -> V_126 ) ;
}
if ( V_17 -> V_159 ) {
F_89 ( V_17 -> V_159 ) ;
F_90 ( V_17 -> V_159 ) ;
}
if ( V_17 -> V_79 )
F_91 ( V_17 -> V_79 ) ;
if ( V_17 -> V_160 )
F_92 ( & V_17 -> V_44 ) ;
if ( V_133 )
V_133 = NULL ;
F_45 ( V_17 ) ;
return 0 ;
}
static const char * F_93 ( T_8 V_27 )
{
T_3 V_10 ;
T_8 V_161 ;
V_10 = F_71 ( V_27 , L_44 , & V_161 ) ;
if ( F_72 ( V_10 ) )
return L_44 ;
V_10 = F_71 ( V_27 , L_45 , & V_161 ) ;
if ( F_72 ( V_10 ) )
return L_45 ;
return NULL ;
}
static int F_94 ( struct V_158 * V_26 )
{
struct V_16 * V_17 ;
const char * V_162 ;
T_2 V_163 ;
bool V_164 ;
int V_69 = 0 ;
if ( V_133 )
return - V_165 ;
F_12 ( L_46 ,
V_116 ) ;
V_162 = F_93 ( V_26 -> V_27 ) ;
if ( ! V_162 ) {
F_30 ( L_47 ) ;
return - V_80 ;
}
V_17 = F_95 ( sizeof( * V_17 ) , V_104 ) ;
if ( ! V_17 )
return - V_105 ;
V_17 -> V_26 = V_26 ;
V_17 -> V_28 = V_162 ;
V_26 -> V_166 = V_17 ;
if ( F_68 ( V_17 ) )
F_12 ( L_48 ) ;
F_96 ( & V_17 -> V_60 ) ;
V_69 = F_80 ( V_17 ) ;
if ( V_69 )
goto error;
if ( F_16 ( V_17 , & V_164 ) == V_51 && V_164 ) {
V_17 -> V_159 = F_97 ( L_49 ,
& V_26 -> V_17 ,
V_167 ,
& V_168 ,
V_17 ) ;
if ( ! V_17 -> V_159 ) {
F_30 ( L_50 ) ;
V_69 = - V_105 ;
goto error;
}
V_69 = F_98 ( V_17 -> V_159 ) ;
if ( V_69 ) {
F_30 ( L_51 ) ;
F_90 ( V_17 -> V_159 ) ;
goto error;
}
}
if ( F_10 ( V_17 ) ) {
V_17 -> V_44 . V_140 = L_52 ;
V_17 -> V_44 . V_82 = 1 ;
V_17 -> V_44 . V_169 = F_13 ;
V_17 -> V_44 . V_170 = F_15 ;
if ( ! F_99 ( & V_26 -> V_17 , & V_17 -> V_44 ) )
V_17 -> V_160 = 1 ;
}
V_69 = F_40 ( V_17 , & V_163 ) ;
V_17 -> V_122 = ! V_69 ;
V_69 = F_46 ( V_17 , & V_163 ) ;
V_17 -> V_124 = ! V_69 ;
F_56 ( V_17 ) ;
V_133 = V_17 ;
return 0 ;
error:
F_85 ( V_26 ) ;
return V_69 ;
}
static void F_100 ( struct V_158 * V_26 , T_2 V_171 )
{
struct V_16 * V_17 = F_86 ( V_26 ) ;
T_2 V_48 , V_3 ;
int V_172 = 3 ;
int V_139 ;
if ( V_171 != 0x80 )
return;
if ( V_17 -> V_150 ) {
V_139 = F_65 ( V_17 ) ;
if ( V_139 < 0 )
F_30 ( L_53 ) ;
else if ( V_139 != 0 )
F_66 ( V_17 , V_139 ) ;
} else if ( V_17 -> V_111 ) {
do {
F_7 ( V_17 , V_112 , & V_3 , & V_48 ) ;
switch ( V_48 ) {
case V_51 :
F_66 ( V_17 , ( int ) V_3 ) ;
break;
case V_115 :
F_6 ( V_17 , V_112 , 1 ,
& V_48 ) ;
F_51 ( L_17 ) ;
default:
V_172 -- ;
break;
}
} while ( V_172 && V_48 != V_114 );
}
}
static int F_101 ( struct V_173 * V_173 )
{
struct V_16 * V_17 = F_86 ( F_102 ( V_173 ) ) ;
T_2 V_33 ;
if ( V_17 -> V_126 )
F_6 ( V_17 , V_152 , V_174 , & V_33 ) ;
return 0 ;
}
static int F_103 ( struct V_173 * V_173 )
{
struct V_16 * V_17 = F_86 ( F_102 ( V_173 ) ) ;
T_2 V_33 ;
if ( V_17 -> V_126 )
F_6 ( V_17 , V_152 , V_153 , & V_33 ) ;
return 0 ;
}
static int T_9 F_104 ( void )
{
int V_69 ;
if ( F_105 ( V_175 ) )
return - V_80 ;
V_120 = F_106 ( V_176 , V_177 ) ;
if ( ! V_120 ) {
F_30 ( L_54 V_176 L_55 ) ;
return - V_80 ;
}
V_69 = F_107 ( & V_178 ) ;
if ( V_69 ) {
F_30 ( L_56 , V_69 ) ;
F_59 ( V_176 , V_177 ) ;
}
return V_69 ;
}
static void T_10 F_108 ( void )
{
F_109 ( & V_178 ) ;
if ( V_120 )
F_59 ( V_176 , V_177 ) ;
}
