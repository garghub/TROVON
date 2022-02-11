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
return F_32 ( V_84 , F_28 , F_33 ( V_83 ) -> V_55 ) ;
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
struct V_16 * V_17 = F_33 ( V_84 -> V_87 . V_88 -> V_89 ) -> V_55 ;
char V_90 [ 42 ] ;
T_6 V_91 ;
int V_3 ;
int V_69 ;
int V_78 = V_17 -> V_79 -> V_81 . V_82 + 1 ;
V_91 = F_37 ( V_11 , sizeof( V_90 ) - 1 ) ;
if ( F_38 ( V_90 , V_85 , V_91 ) )
return - V_92 ;
V_90 [ V_91 ] = '\0' ;
if ( sscanf ( V_90 , L_7 , & V_3 ) == 1 &&
V_3 >= 0 && V_3 < V_78 ) {
V_69 = F_34 ( V_17 , V_3 ) ;
if ( V_69 == 0 )
V_69 = V_11 ;
} else {
V_69 = - V_93 ;
}
return V_69 ;
}
static int F_39 ( struct V_16 * V_17 , T_2 * V_10 )
{
T_2 V_48 ;
F_7 ( V_17 , V_94 , V_10 , & V_48 ) ;
return V_48 == V_51 ? 0 : - V_15 ;
}
static int F_40 ( struct V_74 * V_75 , void * V_76 )
{
struct V_16 * V_17 = V_75 -> V_77 ;
T_2 V_3 ;
int V_69 ;
V_69 = F_39 ( V_17 , & V_3 ) ;
if ( ! V_69 ) {
int V_95 = ( V_3 & V_96 ) ? 1 : 0 ;
int V_97 = ( V_3 & V_98 ) ? 1 : 0 ;
int V_99 = ( V_3 & V_100 ) ? 1 : 0 ;
F_29 ( V_75 , L_8 , V_95 ) ;
F_29 ( V_75 , L_9 , V_97 ) ;
F_29 ( V_75 , L_10 , V_99 ) ;
}
return V_69 ;
}
static int F_41 ( struct V_83 * V_83 , struct V_84 * V_84 )
{
return F_32 ( V_84 , F_40 , F_33 ( V_83 ) -> V_55 ) ;
}
static T_4 F_42 ( struct V_84 * V_84 , const char T_5 * V_85 ,
T_6 V_11 , T_7 * V_86 )
{
struct V_16 * V_17 = F_33 ( V_84 -> V_87 . V_88 -> V_89 ) -> V_55 ;
char * V_90 , * V_101 ;
int V_69 ;
int V_3 ;
int V_102 = V_11 ;
int V_103 = - 1 ;
int V_104 = - 1 ;
int V_105 = - 1 ;
T_2 V_106 ;
V_90 = F_43 ( V_11 + 1 , V_107 ) ;
if ( ! V_90 )
return - V_108 ;
if ( F_38 ( V_90 , V_85 , V_11 ) ) {
F_44 ( V_90 ) ;
return - V_92 ;
}
V_90 [ V_11 ] = '\0' ;
V_101 = V_90 ;
while ( V_102 ) {
if ( sscanf ( V_101 , L_11 , & V_3 ) == 1 )
V_103 = V_3 & 1 ;
else if ( sscanf ( V_101 , L_12 , & V_3 ) == 1 )
V_104 = V_3 & 1 ;
else if ( sscanf ( V_101 , L_13 , & V_3 ) == 1 )
V_105 = V_3 & 1 ;
do {
++ V_101 ;
-- V_102 ;
}
while ( V_102 && * ( V_101 - 1 ) != ';' );
}
F_44 ( V_90 ) ;
V_69 = F_39 ( V_17 , & V_106 ) ;
if ( ! V_69 ) {
unsigned int V_109 = V_106 ;
if ( V_103 != - 1 )
F_1 ( & V_109 , V_96 , V_103 ) ;
if ( V_104 != - 1 )
F_1 ( & V_109 , V_98 , V_104 ) ;
if ( V_105 != - 1 )
F_1 ( & V_109 , V_100 , V_105 ) ;
if ( V_109 != V_106 )
V_69 = F_2 ( V_110 , V_109 ) ;
}
return V_69 ? V_69 : V_11 ;
}
static int F_45 ( struct V_16 * V_17 , T_2 * V_10 )
{
T_2 V_48 ;
F_7 ( V_17 , V_111 , V_10 , & V_48 ) ;
return V_48 == V_51 ? 0 : - V_15 ;
}
static int F_46 ( struct V_74 * V_75 , void * V_76 )
{
struct V_16 * V_17 = V_75 -> V_77 ;
int V_69 ;
T_2 V_3 ;
V_69 = F_45 ( V_17 , & V_3 ) ;
if ( ! V_69 ) {
F_29 ( V_75 , L_14 , ( V_3 > 0 ) ) ;
F_29 ( V_75 , L_15 , V_17 -> V_112 ) ;
}
return V_69 ;
}
static int F_47 ( struct V_83 * V_83 , struct V_84 * V_84 )
{
return F_32 ( V_84 , F_46 , F_33 ( V_83 ) -> V_55 ) ;
}
static T_4 F_48 ( struct V_84 * V_84 , const char T_5 * V_85 ,
T_6 V_11 , T_7 * V_86 )
{
struct V_16 * V_17 = F_33 ( V_84 -> V_87 . V_88 -> V_89 ) -> V_55 ;
char V_90 [ 42 ] ;
T_6 V_91 ;
int V_3 ;
T_2 V_48 ;
V_91 = F_37 ( V_11 , sizeof( V_90 ) - 1 ) ;
if ( F_38 ( V_90 , V_85 , V_91 ) )
return - V_92 ;
V_90 [ V_91 ] = '\0' ;
if ( sscanf ( V_90 , L_16 , & V_3 ) == 1 &&
V_3 >= 0 && V_3 <= 1 ) {
F_6 ( V_17 , V_111 , V_3 , & V_48 ) ;
if ( V_48 != V_51 )
return - V_15 ;
else
V_17 -> V_112 = V_3 ;
} else {
return - V_93 ;
}
return V_11 ;
}
static int F_49 ( struct V_74 * V_75 , void * V_76 )
{
struct V_16 * V_17 = V_75 -> V_77 ;
T_2 V_48 ;
T_2 V_3 ;
if ( ! V_17 -> V_113 && V_17 -> V_114 ) {
F_7 ( V_17 , V_115 , & V_3 , & V_48 ) ;
if ( V_48 == V_51 ) {
V_17 -> V_113 = 1 ;
V_17 -> V_116 = V_3 ;
} else if ( V_48 == V_117 ) {
} else if ( V_48 == V_118 ) {
F_6 ( V_17 , V_115 , 1 , & V_48 ) ;
F_50 ( L_17 ) ;
} else {
F_30 ( L_18 ) ;
return - V_15 ;
}
}
F_29 ( V_75 , L_19 , V_17 -> V_113 ) ;
F_29 ( V_75 , L_20 , V_17 -> V_116 ) ;
return 0 ;
}
static int F_51 ( struct V_83 * V_83 , struct V_84 * V_84 )
{
return F_32 ( V_84 , F_49 , F_33 ( V_83 ) -> V_55 ) ;
}
static T_4 F_52 ( struct V_84 * V_84 , const char T_5 * V_85 ,
T_6 V_11 , T_7 * V_86 )
{
struct V_16 * V_17 = F_33 ( V_84 -> V_87 . V_88 -> V_89 ) -> V_55 ;
char V_90 [ 42 ] ;
T_6 V_91 ;
int V_3 ;
V_91 = F_37 ( V_11 , sizeof( V_90 ) - 1 ) ;
if ( F_38 ( V_90 , V_85 , V_91 ) )
return - V_92 ;
V_90 [ V_91 ] = '\0' ;
if ( sscanf ( V_90 , L_21 , & V_3 ) == 1 && V_3 == 0 ) {
V_17 -> V_113 = 0 ;
} else {
return - V_93 ;
}
return V_11 ;
}
static int F_53 ( struct V_74 * V_75 , void * V_76 )
{
F_29 ( V_75 , L_22 , V_119 ) ;
F_29 ( V_75 , L_23 , V_120 ) ;
return 0 ;
}
static int F_54 ( struct V_83 * V_83 , struct V_84 * V_84 )
{
return F_32 ( V_84 , F_53 , F_33 ( V_83 ) -> V_55 ) ;
}
static void T_8
F_55 ( struct V_16 * V_17 )
{
if ( V_17 -> V_79 )
F_56 ( L_24 , V_121 | V_122 , V_123 ,
& V_124 , V_17 ) ;
if ( V_17 -> V_125 )
F_56 ( L_25 , V_121 | V_122 , V_123 ,
& V_126 , V_17 ) ;
if ( V_17 -> V_127 )
F_56 ( L_26 , V_121 | V_122 , V_123 ,
& V_128 , V_17 ) ;
if ( V_17 -> V_129 )
F_56 ( L_27 , V_121 | V_122 , V_123 ,
& V_130 , V_17 ) ;
F_56 ( L_28 , V_121 , V_123 ,
& V_131 , V_17 ) ;
}
static void F_57 ( struct V_16 * V_17 )
{
if ( V_17 -> V_79 )
F_58 ( L_24 , V_123 ) ;
if ( V_17 -> V_125 )
F_58 ( L_25 , V_123 ) ;
if ( V_17 -> V_127 )
F_58 ( L_26 , V_123 ) ;
if ( V_17 -> V_129 )
F_58 ( L_27 , V_123 ) ;
F_58 ( L_28 , V_123 ) ;
}
static bool F_59 ( unsigned char V_55 , unsigned char V_132 ,
struct V_133 * V_134 )
{
if ( V_132 & 0x20 )
return false ;
if ( F_60 ( V_55 == 0xe0 ) )
return false ;
if ( ( V_55 & 0x7f ) == V_135 ) {
F_61 ( & V_136 -> V_137 ) ;
return true ;
}
return false ;
}
static void F_62 ( struct V_138 * V_139 )
{
T_9 V_140 = F_63 () ;
T_3 V_10 ;
if ( ! V_140 )
return;
V_10 = F_4 ( V_140 , L_29 , NULL , NULL ) ;
if ( F_11 ( V_10 ) )
F_30 ( L_30 ) ;
}
static int F_64 ( struct V_16 * V_17 )
{
struct V_21 V_85 ;
union V_8 V_141 ;
T_3 V_10 ;
V_85 . V_12 = & V_141 ;
V_85 . V_25 = sizeof( V_141 ) ;
V_10 = F_4 ( V_17 -> V_26 -> V_27 , L_31 ,
NULL , & V_85 ) ;
if ( F_11 ( V_10 ) || V_141 . type != V_13 ) {
F_30 ( L_32 ) ;
return - V_15 ;
}
return V_141 . integer . V_3 ;
}
static void F_65 ( struct V_16 * V_17 ,
int V_142 )
{
if ( V_142 == 0x100 )
return;
if ( V_142 & 0x80 )
return;
if ( ! F_66 ( V_17 -> V_129 , V_142 , 1 , true ) )
F_12 ( L_33 , V_142 ) ;
}
static int T_8 F_67 ( struct V_16 * V_17 )
{
T_3 V_10 ;
T_9 V_140 , V_27 ;
int error ;
T_2 V_48 ;
V_17 -> V_129 = F_68 () ;
if ( ! V_17 -> V_129 ) {
F_12 ( L_34 ) ;
return - V_108 ;
}
V_17 -> V_129 -> V_143 = L_35 ;
V_17 -> V_129 -> V_144 = L_36 ;
V_17 -> V_129 -> V_145 . V_146 = V_147 ;
error = F_69 ( V_17 -> V_129 , V_148 , NULL ) ;
if ( error )
goto V_149;
V_10 = V_150 ;
V_140 = F_63 () ;
if ( V_140 )
V_10 = F_70 ( V_140 , L_29 , & V_27 ) ;
if ( F_71 ( V_10 ) ) {
F_72 ( & V_17 -> V_137 , F_62 ) ;
error = F_73 ( F_59 ) ;
if ( error ) {
F_30 ( L_37 ) ;
goto V_151;
}
V_17 -> V_152 = 1 ;
}
V_10 = F_70 ( V_17 -> V_26 -> V_27 , L_31 , & V_27 ) ;
if ( F_71 ( V_10 ) ) {
V_17 -> V_153 = 1 ;
} else {
F_6 ( V_17 , V_115 , 1 , & V_48 ) ;
if ( V_48 == V_51 )
V_17 -> V_114 = 1 ;
}
if ( ! V_17 -> V_153 && ! V_17 -> V_114 ) {
F_74 ( L_38 ) ;
goto V_154;
}
V_10 = F_4 ( V_17 -> V_26 -> V_27 , L_39 , NULL , NULL ) ;
if ( F_11 ( V_10 ) ) {
F_12 ( L_40 ) ;
error = - V_80 ;
goto V_154;
}
error = F_75 ( V_17 -> V_129 ) ;
if ( error ) {
F_12 ( L_34 ) ;
goto V_154;
}
F_6 ( V_17 , V_155 , V_156 , & V_48 ) ;
return 0 ;
V_154:
if ( V_17 -> V_152 )
F_76 ( F_59 ) ;
V_151:
F_77 ( V_17 -> V_129 ) ;
V_149:
F_78 ( V_17 -> V_129 ) ;
V_17 -> V_129 = NULL ;
return error ;
}
static int T_8 F_79 ( struct V_16 * V_17 )
{
struct V_157 V_81 ;
int V_43 ;
int V_69 ;
bool V_65 ;
V_43 = F_25 ( V_17 ) ;
if ( V_43 < 0 )
return 0 ;
V_69 = F_34 ( V_17 , V_43 ) ;
if ( V_69 ) {
F_80 ( L_41 ) ;
return 0 ;
}
V_69 = F_23 ( V_17 , & V_65 ) ;
V_17 -> V_68 = ! V_69 ;
memset ( & V_81 , 0 , sizeof( V_81 ) ) ;
V_81 . type = V_158 ;
V_81 . V_82 = V_159 - 1 ;
if ( V_17 -> V_68 )
V_81 . V_82 ++ ;
V_17 -> V_79 = F_81 ( L_42 ,
& V_17 -> V_26 -> V_17 ,
V_17 ,
& V_160 ,
& V_81 ) ;
if ( F_82 ( V_17 -> V_79 ) ) {
V_69 = F_83 ( V_17 -> V_79 ) ;
F_30 ( L_43 ) ;
V_17 -> V_79 = NULL ;
return V_69 ;
}
V_17 -> V_79 -> V_81 . V_43 = V_43 ;
return 0 ;
}
static int F_84 ( struct V_161 * V_26 , int type )
{
struct V_16 * V_17 = F_85 ( V_26 ) ;
F_57 ( V_17 ) ;
if ( V_17 -> V_152 ) {
F_76 ( F_59 ) ;
F_86 ( & V_17 -> V_137 ) ;
}
if ( V_17 -> V_129 ) {
F_87 ( V_17 -> V_129 ) ;
F_77 ( V_17 -> V_129 ) ;
}
if ( V_17 -> V_162 ) {
F_88 ( V_17 -> V_162 ) ;
F_89 ( V_17 -> V_162 ) ;
}
if ( V_17 -> V_79 )
F_90 ( V_17 -> V_79 ) ;
if ( V_17 -> V_163 )
F_91 ( & V_17 -> V_44 ) ;
if ( V_136 )
V_136 = NULL ;
F_44 ( V_17 ) ;
return 0 ;
}
static const char * T_8 F_92 ( T_9 V_27 )
{
T_3 V_10 ;
T_9 V_164 ;
V_10 = F_70 ( V_27 , L_44 , & V_164 ) ;
if ( F_71 ( V_10 ) )
return L_44 ;
V_10 = F_70 ( V_27 , L_45 , & V_164 ) ;
if ( F_71 ( V_10 ) )
return L_45 ;
return NULL ;
}
static int T_8 F_93 ( struct V_161 * V_26 )
{
struct V_16 * V_17 ;
const char * V_165 ;
T_2 V_166 ;
bool V_167 ;
int V_69 = 0 ;
if ( V_136 )
return - V_168 ;
F_12 ( L_46 ,
V_119 ) ;
V_165 = F_92 ( V_26 -> V_27 ) ;
if ( ! V_165 ) {
F_30 ( L_47 ) ;
return - V_80 ;
}
V_17 = F_94 ( sizeof( * V_17 ) , V_107 ) ;
if ( ! V_17 )
return - V_108 ;
V_17 -> V_26 = V_26 ;
V_17 -> V_28 = V_165 ;
V_26 -> V_169 = V_17 ;
if ( F_67 ( V_17 ) )
F_12 ( L_48 ) ;
F_95 ( & V_17 -> V_60 ) ;
V_69 = F_79 ( V_17 ) ;
if ( V_69 )
goto error;
if ( F_16 ( V_17 , & V_167 ) == V_51 && V_167 ) {
V_17 -> V_162 = F_96 ( L_49 ,
& V_26 -> V_17 ,
V_170 ,
& V_171 ,
V_17 ) ;
if ( ! V_17 -> V_162 ) {
F_30 ( L_50 ) ;
V_69 = - V_108 ;
goto error;
}
V_69 = F_97 ( V_17 -> V_162 ) ;
if ( V_69 ) {
F_30 ( L_51 ) ;
F_89 ( V_17 -> V_162 ) ;
goto error;
}
}
if ( F_10 ( V_17 ) ) {
V_17 -> V_44 . V_143 = L_52 ;
V_17 -> V_44 . V_82 = 1 ;
V_17 -> V_44 . V_172 = F_13 ;
V_17 -> V_44 . V_173 = F_15 ;
if ( ! F_98 ( & V_26 -> V_17 , & V_17 -> V_44 ) )
V_17 -> V_163 = 1 ;
}
V_69 = F_39 ( V_17 , & V_166 ) ;
V_17 -> V_125 = ! V_69 ;
V_69 = F_45 ( V_17 , & V_166 ) ;
V_17 -> V_127 = ! V_69 ;
F_55 ( V_17 ) ;
V_136 = V_17 ;
return 0 ;
error:
F_84 ( V_26 , 0 ) ;
return V_69 ;
}
static void F_99 ( struct V_161 * V_26 , T_2 V_174 )
{
struct V_16 * V_17 = F_85 ( V_26 ) ;
T_2 V_48 , V_3 ;
int V_175 = 3 ;
int V_142 ;
if ( V_174 != 0x80 )
return;
if ( V_17 -> V_153 ) {
V_142 = F_64 ( V_17 ) ;
if ( V_142 < 0 )
F_30 ( L_53 ) ;
else if ( V_142 != 0 )
F_65 ( V_17 , V_142 ) ;
} else if ( V_17 -> V_114 ) {
do {
F_7 ( V_17 , V_115 , & V_3 , & V_48 ) ;
switch ( V_48 ) {
case V_51 :
F_65 ( V_17 , ( int ) V_3 ) ;
break;
case V_118 :
F_6 ( V_17 , V_115 , 1 ,
& V_48 ) ;
F_50 ( L_17 ) ;
default:
V_175 -- ;
break;
}
} while ( V_175 && V_48 != V_117 );
}
}
static int F_100 ( struct V_176 * V_176 )
{
struct V_16 * V_17 = F_85 ( F_101 ( V_176 ) ) ;
T_2 V_33 ;
if ( V_17 -> V_129 )
F_6 ( V_17 , V_155 , V_177 , & V_33 ) ;
return 0 ;
}
static int F_102 ( struct V_176 * V_176 )
{
struct V_16 * V_17 = F_85 ( F_101 ( V_176 ) ) ;
T_2 V_33 ;
if ( V_17 -> V_129 )
F_6 ( V_17 , V_155 , V_156 , & V_33 ) ;
return 0 ;
}
static int T_10 F_103 ( void )
{
int V_69 ;
if ( F_104 ( V_178 ) )
return - V_80 ;
V_123 = F_105 ( V_179 , V_180 ) ;
if ( ! V_123 ) {
F_30 ( L_54 V_179 L_55 ) ;
return - V_80 ;
}
V_69 = F_106 ( & V_181 ) ;
if ( V_69 ) {
F_30 ( L_56 , V_69 ) ;
F_58 ( V_179 , V_180 ) ;
}
return V_69 ;
}
static void T_11 F_107 ( void )
{
F_108 ( & V_181 ) ;
if ( V_123 )
F_58 ( V_179 , V_180 ) ;
}
