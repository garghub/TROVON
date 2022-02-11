static T_1 void F_1 ( T_2 * V_1 , T_2 V_2 , int V_3 )
{
* V_1 = ( * V_1 & ~ V_2 ) | ( V_2 * V_3 ) ;
}
static int F_2 ( const char * V_4 )
{
T_3 V_5 ;
T_4 V_6 ;
V_6 = F_3 ( NULL , ( char * ) V_4 , & V_5 ) ;
return ! F_4 ( V_6 ) ;
}
static int F_5 ( const char * V_4 , int V_7 )
{
struct V_8 V_9 ;
union V_10 V_11 [ 1 ] ;
T_4 V_6 ;
V_9 . V_12 = F_6 ( V_11 ) ;
V_9 . V_13 = V_11 ;
V_11 [ 0 ] . type = V_14 ;
V_11 [ 0 ] . integer . V_3 = V_7 ;
V_6 = F_7 ( NULL , ( char * ) V_4 , & V_9 , NULL ) ;
return ( V_6 == V_15 ) ;
}
static T_4 F_8 ( const T_2 V_16 [ V_17 ] , T_2 V_18 [ V_17 ] )
{
struct V_8 V_9 ;
union V_10 V_11 [ V_17 ] ;
struct V_19 V_20 ;
union V_10 V_21 [ V_17 + 1 ] ;
T_4 V_6 ;
int V_22 ;
V_9 . V_12 = V_17 ;
V_9 . V_13 = V_11 ;
for ( V_22 = 0 ; V_22 < V_17 ; ++ V_22 ) {
V_11 [ V_22 ] . type = V_14 ;
V_11 [ V_22 ] . integer . V_3 = V_16 [ V_22 ] ;
}
V_20 . V_23 = sizeof( V_21 ) ;
V_20 . V_13 = V_21 ;
V_6 = F_7 ( NULL , ( char * ) V_24 , & V_9 ,
& V_20 ) ;
if ( ( V_6 == V_15 ) && ( V_21 -> V_25 . V_12 <= V_17 ) ) {
for ( V_22 = 0 ; V_22 < V_21 -> V_25 . V_12 ; ++ V_22 ) {
V_18 [ V_22 ] = V_21 -> V_25 . V_26 [ V_22 ] . integer . V_3 ;
}
}
return V_6 ;
}
static T_4 F_9 ( T_2 V_27 , T_2 V_28 , T_2 * V_29 )
{
T_2 V_16 [ V_17 ] = { V_30 , V_27 , V_28 , 0 , 0 , 0 } ;
T_2 V_18 [ V_17 ] ;
T_4 V_6 = F_8 ( V_16 , V_18 ) ;
* V_29 = ( V_6 == V_15 ) ? V_18 [ 0 ] : V_31 ;
return V_6 ;
}
static T_4 F_10 ( T_2 V_27 , T_2 * V_32 , T_2 * V_29 )
{
T_2 V_16 [ V_17 ] = { V_33 , V_27 , 0 , 0 , 0 , 0 } ;
T_2 V_18 [ V_17 ] ;
T_4 V_6 = F_8 ( V_16 , V_18 ) ;
* V_32 = V_18 [ 2 ] ;
* V_29 = ( V_6 == V_15 ) ? V_18 [ 0 ] : V_31 ;
return V_6 ;
}
static T_4 F_11 ( T_2 V_27 , T_2 V_28 , T_2 V_34 , T_2 * V_29 )
{
T_2 V_16 [ V_17 ] = { V_30 , V_27 , V_28 , V_34 , 0 , 0 } ;
T_2 V_18 [ V_17 ] ;
T_4 V_6 = F_8 ( V_16 , V_18 ) ;
* V_29 = ( V_6 == V_15 ) ? V_18 [ 0 ] : V_31 ;
return V_6 ;
}
static T_4 F_12 ( T_2 V_27 , T_2 * V_32 , T_2 * V_35 , T_2 * V_29 )
{
T_2 V_16 [ V_17 ] = { V_33 , V_27 , * V_32 , * V_35 , 0 , 0 } ;
T_2 V_18 [ V_17 ] ;
T_4 V_6 = F_8 ( V_16 , V_18 ) ;
* V_32 = V_18 [ 2 ] ;
* V_35 = V_18 [ 3 ] ;
* V_29 = ( V_6 == V_15 ) ? V_18 [ 0 ] : V_31 ;
return V_6 ;
}
static int F_13 ( void )
{
T_2 V_16 [ V_17 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
T_2 V_18 [ V_17 ] ;
T_4 V_6 ;
V_16 [ 0 ] = 0xf100 ;
V_6 = F_8 ( V_16 , V_18 ) ;
if ( F_4 ( V_6 ) ) {
F_14 ( L_1 ) ;
return 0 ;
}
V_16 [ 0 ] = 0xf400 ;
V_6 = F_8 ( V_16 , V_18 ) ;
return 1 ;
}
static void F_15 ( struct V_36 * V_37 ,
enum V_38 V_39 )
{
T_2 V_16 [ V_17 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
T_2 V_18 [ V_17 ] ;
T_4 V_6 ;
V_16 [ 0 ] = 0xf100 ;
V_6 = F_8 ( V_16 , V_18 ) ;
if ( F_4 ( V_6 ) ) {
F_14 ( L_1 ) ;
return;
}
if ( V_39 ) {
V_16 [ 0 ] = 0xf400 ;
V_16 [ 1 ] = 0x14e ;
V_16 [ 2 ] = 1 ;
V_6 = F_8 ( V_16 , V_18 ) ;
if ( F_4 ( V_6 ) ) {
F_14 ( L_2 ) ;
return;
}
} else {
V_16 [ 0 ] = 0xf400 ;
V_16 [ 1 ] = 0x14e ;
V_16 [ 2 ] = 0 ;
V_6 = F_8 ( V_16 , V_18 ) ;
if ( F_4 ( V_6 ) ) {
F_14 ( L_3 ) ;
return;
}
}
V_16 [ 0 ] = 0xf200 ;
V_16 [ 1 ] = 0 ;
V_16 [ 2 ] = 0 ;
F_8 ( V_16 , V_18 ) ;
}
static enum V_38 F_16 ( struct V_36 * V_37 )
{
T_2 V_16 [ V_17 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
T_2 V_18 [ V_17 ] ;
T_4 V_6 ;
enum V_38 V_29 ;
V_16 [ 0 ] = 0xf100 ;
V_6 = F_8 ( V_16 , V_18 ) ;
if ( F_4 ( V_6 ) ) {
F_14 ( L_1 ) ;
return V_40 ;
}
V_16 [ 0 ] = 0xf300 ;
V_16 [ 1 ] = 0x14e ;
V_6 = F_8 ( V_16 , V_18 ) ;
if ( F_4 ( V_6 ) ) {
F_14 ( L_3 ) ;
return V_40 ;
}
V_29 = V_18 [ 2 ] ? V_41 : V_40 ;
V_16 [ 0 ] = 0xf200 ;
V_16 [ 1 ] = 0 ;
V_16 [ 2 ] = 0 ;
F_8 ( V_16 , V_18 ) ;
return V_29 ;
}
static T_2 F_17 ( bool * V_42 )
{
T_2 V_43 ;
T_2 V_3 , V_44 ;
V_3 = 0 ;
V_44 = 0 ;
F_12 ( V_45 , & V_3 , & V_44 , & V_43 ) ;
if ( V_43 == V_46 )
* V_42 = ( V_3 & V_47 ) ? true : false ;
return V_43 ;
}
static T_2 F_18 ( bool * V_48 )
{
T_2 V_43 ;
T_2 V_3 , V_44 ;
V_3 = 0 ;
V_44 = 0x0001 ;
F_12 ( V_45 , & V_3 , & V_44 , & V_43 ) ;
* V_48 = V_3 & V_49 ;
return V_43 ;
}
static int F_19 ( void * V_50 , bool V_51 )
{
struct V_52 * V_53 = V_50 ;
T_2 V_54 , V_55 ;
T_2 V_3 ;
int V_56 ;
bool V_48 ;
V_3 = ( V_51 == false ) ;
F_20 ( & V_53 -> V_57 ) ;
if ( F_18 ( & V_48 ) != V_46 ) {
V_56 = - V_58 ;
goto V_18;
}
if ( ! V_48 ) {
V_56 = 0 ;
goto V_18;
}
F_11 ( V_45 , V_3 , V_59 , & V_54 ) ;
F_11 ( V_45 , V_3 , V_60 , & V_55 ) ;
if ( V_54 != V_46 || V_55 != V_46 )
V_56 = - V_58 ;
else
V_56 = 0 ;
V_18:
F_21 ( & V_53 -> V_57 ) ;
return V_56 ;
}
static void F_22 ( struct V_61 * V_61 , void * V_50 )
{
bool V_62 ;
bool V_3 ;
T_2 V_43 ;
struct V_52 * V_53 = V_50 ;
F_20 ( & V_53 -> V_57 ) ;
V_43 = F_18 ( & V_3 ) ;
if ( V_43 != V_46 ) {
F_21 ( & V_53 -> V_57 ) ;
return;
}
V_62 = V_3 ;
F_21 ( & V_53 -> V_57 ) ;
if ( F_23 ( V_61 , ! V_62 ) )
F_19 ( V_50 , true ) ;
}
static int F_24 ( struct V_63 * V_64 )
{
T_2 V_43 ;
T_2 V_3 ;
F_10 ( V_65 , & V_3 , & V_43 ) ;
if ( V_43 == V_46 ) {
return ( V_3 >> V_66 ) ;
} else
return - V_67 ;
}
static int F_25 ( struct V_68 * V_69 , void * V_70 )
{
int V_3 = F_24 ( NULL ) ;
if ( V_3 >= 0 ) {
F_26 ( V_69 , L_4 , V_3 ) ;
F_26 ( V_69 , L_5 ,
V_71 ) ;
} else {
F_27 ( L_6 ) ;
}
return 0 ;
}
static int F_28 ( struct V_72 * V_72 , struct V_73 * V_73 )
{
return F_29 ( V_73 , F_25 , NULL ) ;
}
static int F_30 ( int V_3 )
{
T_2 V_43 ;
V_3 = V_3 << V_66 ;
F_9 ( V_65 , V_3 , & V_43 ) ;
if ( V_43 != V_46 )
return - V_67 ;
return 0 ;
}
static int F_31 ( struct V_63 * V_64 )
{
return F_30 ( V_64 -> V_74 . V_39 ) ;
}
static T_5 F_32 ( struct V_73 * V_73 , const char T_6 * V_75 ,
T_7 V_12 , T_8 * V_76 )
{
char V_77 [ 42 ] ;
T_7 V_78 ;
int V_3 ;
int V_79 ;
V_78 = F_33 ( V_12 , sizeof( V_77 ) - 1 ) ;
if ( F_34 ( V_77 , V_75 , V_78 ) )
return - V_67 ;
V_77 [ V_78 ] = '\0' ;
if ( sscanf ( V_77 , L_7 , & V_3 ) == 1 &&
V_3 >= 0 && V_3 < V_71 ) {
V_79 = F_30 ( V_3 ) ;
if ( V_79 == 0 )
V_79 = V_12 ;
} else {
V_79 = - V_80 ;
}
return V_79 ;
}
static int F_35 ( struct V_68 * V_69 , void * V_70 )
{
T_2 V_43 ;
T_2 V_3 ;
F_10 ( V_81 , & V_3 , & V_43 ) ;
if ( V_43 == V_46 ) {
int V_82 = ( V_3 & V_83 ) ? 1 : 0 ;
int V_84 = ( V_3 & V_85 ) ? 1 : 0 ;
int V_86 = ( V_3 & V_87 ) ? 1 : 0 ;
F_26 ( V_69 , L_8 , V_82 ) ;
F_26 ( V_69 , L_9 , V_84 ) ;
F_26 ( V_69 , L_10 , V_86 ) ;
} else {
F_27 ( L_11 ) ;
}
return 0 ;
}
static int F_36 ( struct V_72 * V_72 , struct V_73 * V_73 )
{
return F_29 ( V_73 , F_35 , NULL ) ;
}
static T_5 F_37 ( struct V_73 * V_73 , const char T_6 * V_75 ,
T_7 V_12 , T_8 * V_76 )
{
char * V_77 , * V_88 ;
int V_3 ;
int V_89 = V_12 ;
int V_90 = - 1 ;
int V_91 = - 1 ;
int V_92 = - 1 ;
T_2 V_43 ;
T_2 V_93 ;
V_77 = F_38 ( V_12 + 1 , V_94 ) ;
if ( ! V_77 )
return - V_95 ;
if ( F_34 ( V_77 , V_75 , V_12 ) ) {
F_39 ( V_77 ) ;
return - V_67 ;
}
V_77 [ V_12 ] = '\0' ;
V_88 = V_77 ;
while ( V_89 ) {
if ( sscanf ( V_88 , L_12 , & V_3 ) == 1 )
V_90 = V_3 & 1 ;
else if ( sscanf ( V_88 , L_13 , & V_3 ) == 1 )
V_91 = V_3 & 1 ;
else if ( sscanf ( V_88 , L_14 , & V_3 ) == 1 )
V_92 = V_3 & 1 ;
do {
++ V_88 ;
-- V_89 ;
}
while ( V_89 && * ( V_88 - 1 ) != ';' );
}
F_39 ( V_77 ) ;
F_10 ( V_81 , & V_93 , & V_43 ) ;
if ( V_43 == V_46 ) {
unsigned int V_96 = V_93 ;
if ( V_90 != - 1 )
F_1 ( & V_96 , V_83 , V_90 ) ;
if ( V_91 != - 1 )
F_1 ( & V_96 , V_85 , V_91 ) ;
if ( V_92 != - 1 )
F_1 ( & V_96 , V_87 , V_92 ) ;
if ( V_96 != V_93 )
F_5 ( V_97 , V_96 ) ;
} else {
return - V_67 ;
}
return V_12 ;
}
static int F_40 ( struct V_68 * V_69 , void * V_70 )
{
T_2 V_43 ;
T_2 V_3 ;
F_10 ( V_98 , & V_3 , & V_43 ) ;
if ( V_43 == V_46 ) {
F_26 ( V_69 , L_15 , ( V_3 > 0 ) ) ;
F_26 ( V_69 , L_16 , V_99 ) ;
} else {
F_27 ( L_17 ) ;
}
return 0 ;
}
static int F_41 ( struct V_72 * V_72 , struct V_73 * V_73 )
{
return F_29 ( V_73 , F_40 , NULL ) ;
}
static T_5 F_42 ( struct V_73 * V_73 , const char T_6 * V_75 ,
T_7 V_12 , T_8 * V_76 )
{
char V_77 [ 42 ] ;
T_7 V_78 ;
int V_3 ;
T_2 V_43 ;
V_78 = F_33 ( V_12 , sizeof( V_77 ) - 1 ) ;
if ( F_34 ( V_77 , V_75 , V_78 ) )
return - V_67 ;
V_77 [ V_78 ] = '\0' ;
if ( sscanf ( V_77 , L_18 , & V_3 ) == 1 &&
V_3 >= 0 && V_3 <= 1 ) {
F_9 ( V_98 , V_3 , & V_43 ) ;
if ( V_43 != V_46 )
return - V_67 ;
else
V_99 = V_3 ;
} else {
return - V_80 ;
}
return V_12 ;
}
static int F_43 ( struct V_68 * V_69 , void * V_70 )
{
T_2 V_43 ;
T_2 V_3 ;
if ( ! V_100 ) {
F_10 ( V_101 , & V_3 , & V_43 ) ;
if ( V_43 == V_46 ) {
V_100 = 1 ;
V_102 = V_3 ;
} else if ( V_43 == V_103 ) {
} else if ( V_43 == V_104 ) {
F_9 ( V_101 , 1 , & V_43 ) ;
F_44 ( L_19 ) ;
} else {
F_27 ( L_20 ) ;
goto V_105;
}
}
F_26 ( V_69 , L_21 , V_100 ) ;
F_26 ( V_69 , L_22 , V_102 ) ;
V_105:
return 0 ;
}
static int F_45 ( struct V_72 * V_72 , struct V_73 * V_73 )
{
return F_29 ( V_73 , F_43 , NULL ) ;
}
static T_5 F_46 ( struct V_73 * V_73 , const char T_6 * V_75 ,
T_7 V_12 , T_8 * V_76 )
{
char V_77 [ 42 ] ;
T_7 V_78 ;
int V_3 ;
V_78 = F_33 ( V_12 , sizeof( V_77 ) - 1 ) ;
if ( F_34 ( V_77 , V_75 , V_78 ) )
return - V_67 ;
V_77 [ V_78 ] = '\0' ;
if ( sscanf ( V_77 , L_23 , & V_3 ) == 1 && V_3 == 0 ) {
V_100 = 0 ;
} else {
return - V_80 ;
}
return V_12 ;
}
static int F_47 ( struct V_68 * V_69 , void * V_70 )
{
F_26 ( V_69 , L_24 , V_106 ) ;
F_26 ( V_69 , L_25 , V_107 ) ;
return 0 ;
}
static int F_48 ( struct V_72 * V_72 , struct V_73 * V_73 )
{
return F_29 ( V_73 , F_47 , F_49 ( V_72 ) -> V_50 ) ;
}
static void T_9 F_50 ( void )
{
F_51 ( L_26 , V_108 | V_109 , V_110 , & V_111 ) ;
F_51 ( L_27 , V_108 | V_109 , V_110 , & V_112 ) ;
F_51 ( L_28 , V_108 | V_109 , V_110 , & V_113 ) ;
F_51 ( L_29 , V_108 | V_109 , V_110 , & V_114 ) ;
F_51 ( L_30 , V_108 , V_110 , & V_115 ) ;
}
static void F_52 ( void )
{
F_53 ( L_26 , V_110 ) ;
F_53 ( L_27 , V_110 ) ;
F_53 ( L_28 , V_110 ) ;
F_53 ( L_29 , V_110 ) ;
F_53 ( L_30 , V_110 ) ;
}
static void F_54 ( T_3 V_5 , T_2 V_116 , void * V_117 )
{
T_2 V_43 , V_3 ;
if ( V_116 != 0x80 )
return;
do {
F_10 ( V_101 , & V_3 , & V_43 ) ;
if ( V_43 == V_46 ) {
if ( V_3 == 0x100 )
continue;
if ( V_3 & 0x80 )
continue;
if ( ! F_55 ( V_118 . V_119 ,
V_3 , 1 , true ) ) {
F_14 ( L_31 ,
V_3 ) ;
}
} else if ( V_43 == V_104 ) {
F_9 ( V_101 , 1 , & V_43 ) ;
F_44 ( L_19 ) ;
}
} while ( V_43 != V_103 );
}
static int T_9 F_56 ( char * V_120 )
{
T_4 V_6 ;
int error ;
V_6 = F_3 ( NULL , V_120 , & V_118 . V_5 ) ;
if ( F_4 ( V_6 ) ) {
F_14 ( L_32 ) ;
return - V_121 ;
}
V_118 . V_119 = F_57 () ;
if ( ! V_118 . V_119 ) {
F_14 ( L_33 ) ;
return - V_95 ;
}
V_118 . V_119 -> V_122 = L_34 ;
V_118 . V_119 -> V_123 = V_120 ;
V_118 . V_119 -> V_124 . V_125 = V_126 ;
error = F_58 ( V_118 . V_119 ,
V_127 , NULL ) ;
if ( error )
goto V_128;
V_6 = F_59 ( V_118 . V_5 ,
V_129 , F_54 , NULL ) ;
if ( F_4 ( V_6 ) ) {
F_14 ( L_35 ) ;
error = - V_121 ;
goto V_130;
}
V_6 = F_7 ( V_118 . V_5 , L_36 , NULL , NULL ) ;
if ( F_4 ( V_6 ) ) {
F_14 ( L_37 ) ;
error = - V_121 ;
goto V_131;
}
error = F_60 ( V_118 . V_119 ) ;
if ( error ) {
F_14 ( L_33 ) ;
goto V_131;
}
return 0 ;
V_131:
F_61 ( V_118 . V_5 ,
V_129 , F_54 ) ;
V_130:
F_62 ( V_118 . V_119 ) ;
V_128:
F_63 ( V_118 . V_119 ) ;
V_118 . V_119 = NULL ;
return error ;
}
static void F_64 ( void )
{
if ( V_118 . V_119 ) {
F_61 ( V_118 . V_5 ,
V_129 , F_54 ) ;
F_62 ( V_118 . V_119 ) ;
F_65 ( V_118 . V_119 ) ;
}
if ( V_118 . V_132 ) {
F_66 ( V_118 . V_132 ) ;
F_67 ( V_118 . V_132 ) ;
}
if ( V_133 )
F_68 ( V_133 ) ;
F_52 () ;
if ( V_110 )
F_53 ( V_134 , V_135 ) ;
if ( V_118 . V_136 )
F_69 ( & V_137 ) ;
F_70 ( V_118 . V_138 ) ;
return;
}
static int T_9 F_71 ( void )
{
T_2 V_43 ;
bool V_139 ;
int V_79 = 0 ;
struct V_140 V_74 ;
if ( V_141 )
return - V_121 ;
if ( F_2 (TOSH_INTERFACE_1 GHCI_METHOD) ) {
V_24 = V_142 V_143 ;
if ( F_56 ( V_142 ) )
F_14 ( L_38 ) ;
} else if ( F_2 (TOSH_INTERFACE_2 GHCI_METHOD) ) {
V_24 = V_144 V_143 ;
if ( F_56 ( V_144 ) )
F_14 ( L_38 ) ;
} else
return - V_121 ;
F_14 ( L_39 ,
V_106 ) ;
F_14 ( L_40 , V_24 ) ;
F_72 ( & V_118 . V_57 ) ;
V_118 . V_138 = F_73 ( L_41 ,
- 1 , NULL , 0 ) ;
if ( F_74 ( V_118 . V_138 ) ) {
V_79 = F_75 ( V_118 . V_138 ) ;
F_27 ( L_42 ) ;
V_118 . V_138 = NULL ;
F_64 () ;
return V_79 ;
}
V_99 = 0 ;
V_100 = 0 ;
F_9 ( V_101 , 1 , & V_43 ) ;
V_110 = F_76 ( V_134 , V_135 ) ;
if ( ! V_110 ) {
F_64 () ;
return - V_121 ;
} else {
F_50 () ;
}
V_74 . type = V_145 ;
V_74 . V_146 = V_71 - 1 ;
V_133 = F_77 ( L_43 ,
& V_118 . V_138 -> V_53 ,
NULL ,
& V_147 ,
& V_74 ) ;
if ( F_74 ( V_133 ) ) {
V_79 = F_75 ( V_133 ) ;
F_27 ( L_44 ) ;
V_133 = NULL ;
F_64 () ;
return V_79 ;
}
if ( F_17 ( & V_139 ) == V_46 && V_139 ) {
V_118 . V_132 = F_78 ( V_118 . V_148 ,
& V_118 . V_138 -> V_53 ,
V_149 ,
& V_150 ,
& V_118 ) ;
if ( ! V_118 . V_132 ) {
F_27 ( L_45 ) ;
F_64 () ;
return - V_95 ;
}
V_79 = F_79 ( V_118 . V_132 ) ;
if ( V_79 ) {
F_27 ( L_46 ) ;
F_67 ( V_118 . V_132 ) ;
F_64 () ;
return V_79 ;
}
}
V_118 . V_136 = 0 ;
if ( F_13 () ) {
if ( ! F_80 ( & ( V_118 . V_138 -> V_53 ) ,
& V_137 ) )
V_118 . V_136 = 1 ;
}
return 0 ;
}
