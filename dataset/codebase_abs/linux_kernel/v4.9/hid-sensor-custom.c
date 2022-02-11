static int F_1 ( const void * V_1 , const void * V_2 )
{
if ( * ( int * ) V_1 < * ( int * ) V_2 )
return - 1 ;
if ( * ( int * ) V_1 > * ( int * ) V_2 )
return 1 ;
return 0 ;
}
static T_1 F_2 ( struct V_3 * V_4 ,
struct V_5 * V_6 , char * V_7 )
{
struct V_8 * V_9 = F_3 ( V_4 ) ;
struct V_10 * V_11 = F_4 ( V_9 ) ;
return sprintf ( V_7 , L_1 , V_11 -> V_12 ) ;
}
static int F_5 ( struct V_10 * V_11 ,
bool V_13 )
{
int V_14 = - 1 ;
int V_15 = - 1 ;
T_2 V_16 ;
T_2 V_17 ;
int V_18 ;
if ( V_13 ) {
V_16 =
V_19 ;
V_17 =
V_20 ;
} else {
V_16 =
V_21 ;
V_17 =
V_22 ;
}
if ( V_11 -> V_23 )
V_14 = F_6 ( V_11 -> V_24 ,
V_11 -> V_23 -> V_25 . V_26 ,
V_11 -> V_23 -> V_25 . V_27 ,
V_16 ) ;
if ( V_11 -> V_28 )
V_15 = F_6 ( V_11 -> V_24 ,
V_11 -> V_28 -> V_25 . V_26 ,
V_11 -> V_28 -> V_25 . V_27 ,
V_17 ) ;
if ( V_14 >= 0 ) {
V_14 +=
V_11 -> V_23 -> V_25 . V_29 ;
V_18 = F_7 ( V_11 -> V_24 ,
V_11 -> V_23 -> V_25 . V_26 ,
V_11 -> V_23 -> V_25 . V_27 ,
sizeof( V_14 ) ,
& V_14 ) ;
if ( V_18 ) {
F_8 ( V_11 -> V_24 -> V_30 ,
L_2 ) ;
return V_18 ;
}
}
if ( V_15 >= 0 ) {
V_15 +=
V_11 -> V_28 -> V_25 . V_29 ;
V_18 = F_7 ( V_11 -> V_24 ,
V_11 -> V_28 -> V_25 . V_26 ,
V_11 -> V_28 -> V_25 . V_27 ,
sizeof( V_15 ) ,
& V_15 ) ;
if ( V_18 ) {
F_8 ( V_11 -> V_24 -> V_30 ,
L_3 ) ;
return V_18 ;
}
}
return 0 ;
}
static T_1 F_9 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
const char * V_7 , T_3 V_31 )
{
struct V_8 * V_9 = F_3 ( V_4 ) ;
struct V_10 * V_11 = F_4 ( V_9 ) ;
int V_32 ;
int V_18 = - V_33 ;
if ( F_10 ( V_7 , 0 , & V_32 ) != 0 )
return - V_33 ;
F_11 ( & V_11 -> V_34 ) ;
if ( V_32 && ! V_11 -> V_12 ) {
V_18 = F_12 ( V_11 -> V_24 ) ;
if ( V_18 )
goto V_35;
V_18 = F_5 ( V_11 , true ) ;
if ( V_18 ) {
F_13 ( V_11 -> V_24 ) ;
goto V_35;
}
V_11 -> V_12 = true ;
} else if ( ! V_32 && V_11 -> V_12 ) {
V_18 = F_5 ( V_11 , false ) ;
F_13 ( V_11 -> V_24 ) ;
V_11 -> V_12 = false ;
}
V_35:
F_14 ( & V_11 -> V_34 ) ;
if ( V_18 < 0 )
return V_18 ;
return V_31 ;
}
static T_1 F_15 ( struct V_3 * V_4 , struct V_5 * V_6 ,
char * V_7 )
{
struct V_8 * V_9 = F_3 ( V_4 ) ;
struct V_10 * V_11 = F_4 ( V_9 ) ;
struct V_36 * V_25 ;
int V_27 , V_37 , V_38 ;
char V_39 [ V_40 ] ;
bool V_41 = false ;
bool V_42 = false ;
int V_32 = 0 ;
if ( sscanf ( V_6 -> V_6 . V_39 , L_4 , & V_27 , & V_37 ,
V_39 ) == 3 ) {
V_41 = true ;
V_38 = V_27 + V_11 -> V_43 ;
} else if ( sscanf ( V_6 -> V_6 . V_39 , L_5 , & V_27 , & V_37 ,
V_39 ) == 3 ) {
V_42 = true ;
V_38 = V_27 ;
} else
return - V_33 ;
if ( ! strncmp ( V_39 , L_6 , strlen ( L_6 ) ) ) {
T_2 V_26 ;
int V_18 ;
V_25 = & V_11 -> V_44 [ V_38 ] . V_25 ;
V_26 = V_25 -> V_26 ;
if ( V_41 ) {
T_4 V_45 [ V_46 ] ;
int V_47 = 0 ;
T_5 V_32 = 0 ;
int V_48 = 0 ;
V_18 = F_16 ( V_11 -> V_24 ,
V_26 ,
V_27 ,
sizeof( V_45 ) , V_45 ) ;
if ( V_18 < 0 )
return V_18 ;
while ( V_48 < V_18 ) {
if ( V_48 + V_25 -> V_49 > V_18 ) {
V_47 += snprintf ( & V_7 [ V_47 ] ,
V_50 - V_47 ,
L_7 , V_45 [ V_48 ] ) ;
break;
}
switch ( V_25 -> V_49 ) {
case 2 :
V_32 = ( T_5 ) * ( V_51 * ) & V_45 [ V_48 ] ;
V_48 += V_25 -> V_49 ;
break;
case 4 :
V_32 = ( T_5 ) * ( T_2 * ) & V_45 [ V_48 ] ;
V_48 += V_25 -> V_49 ;
break;
case 8 :
V_32 = * ( T_5 * ) & V_45 [ V_48 ] ;
V_48 += V_25 -> V_49 ;
break;
default:
V_32 = ( T_5 ) V_45 [ V_48 ] ;
++ V_48 ;
break;
}
V_47 += snprintf ( & V_7 [ V_47 ] , V_50 - V_47 ,
L_8 , V_32 ) ;
}
V_47 += snprintf ( & V_7 [ V_47 ] , V_50 - V_47 , L_9 ) ;
return V_47 ;
} else if ( V_42 )
V_32 = F_17 (
V_11 -> V_24 ,
V_11 -> V_24 -> V_37 ,
V_37 , V_26 ,
V_52 ) ;
} else if ( ! strncmp ( V_39 , L_10 , strlen ( L_10 ) ) )
V_32 = V_11 -> V_44 [ V_38 ] . V_25 . V_53 ;
else if ( ! strncmp ( V_39 , L_11 , strlen ( L_11 ) ) )
V_32 = V_11 -> V_44 [ V_38 ] . V_25 . V_54 ;
else if ( ! strncmp ( V_39 , L_12 , strlen ( L_12 ) ) )
V_32 = V_11 -> V_44 [ V_38 ] . V_25 . V_49 ;
else if ( ! strncmp ( V_39 , L_13 , strlen ( L_13 ) ) )
V_32 = V_11 -> V_44 [ V_38 ] . V_25 .
V_29 ;
else if ( ! strncmp ( V_39 , L_14 , strlen ( L_14 ) ) )
V_32 = V_11 -> V_44 [ V_38 ] . V_25 .
V_55 ;
else if ( ! strncmp ( V_39 , L_15 , strlen ( L_15 ) ) ) {
struct V_56 * V_57 ;
V_57 = bsearch ( & V_37 , V_58 ,
F_18 ( V_58 ) ,
sizeof( struct V_56 ) ,
F_1 ) ;
if ( V_57 )
return snprintf ( V_7 , V_50 , L_16 ,
V_57 -> V_59 ) ;
else
return sprintf ( V_7 , L_17 ) ;
} else
return - V_33 ;
return sprintf ( V_7 , L_1 , V_32 ) ;
}
static T_1 F_19 ( struct V_3 * V_4 , struct V_5 * V_6 ,
const char * V_7 , T_3 V_31 )
{
struct V_8 * V_9 = F_3 ( V_4 ) ;
struct V_10 * V_11 = F_4 ( V_9 ) ;
int V_27 , V_38 , V_37 ;
char V_39 [ V_40 ] ;
int V_32 ;
if ( sscanf ( V_6 -> V_6 . V_39 , L_4 , & V_27 , & V_37 ,
V_39 ) == 3 ) {
V_38 = V_27 + V_11 -> V_43 ;
} else
return - V_33 ;
if ( ! strncmp ( V_39 , L_6 , strlen ( L_6 ) ) ) {
T_2 V_26 ;
int V_18 ;
if ( F_10 ( V_7 , 0 , & V_32 ) != 0 )
return - V_33 ;
V_26 = V_11 -> V_44 [ V_38 ] . V_25 .
V_26 ;
V_18 = F_7 ( V_11 -> V_24 , V_26 ,
V_27 , sizeof( V_32 ) , & V_32 ) ;
} else
return - V_33 ;
return V_31 ;
}
static int F_20 ( struct V_60 * V_24 ,
unsigned V_61 , T_3 V_62 ,
char * V_63 , void * V_64 )
{
struct V_10 * V_11 = F_4 ( V_64 ) ;
struct V_65 V_66 ;
if ( V_11 -> V_67 ) {
F_8 ( V_11 -> V_24 -> V_30 , L_18 ) ;
return 0 ;
}
F_21 ( V_11 -> V_24 -> V_30 , L_19 , V_68 ,
( int ) ( V_11 -> V_69 + V_62 ) ,
V_11 -> V_70 ) ;
if ( ! F_22 ( 0 , & V_11 -> V_71 ) )
return 0 ;
if ( ! V_11 -> V_69 ) {
int V_72 = sizeof( struct V_65 ) +
V_11 -> V_70 ;
V_66 . V_61 = V_24 -> V_37 ;
V_66 . V_62 = V_11 -> V_70 ;
V_66 . V_73 = F_23 () ;
if ( F_24 ( & V_11 -> V_74 ) >= V_72 ) {
F_25 ( & V_11 -> V_74 ,
( unsigned char * ) & V_66 ,
sizeof( V_66 ) ) ;
} else
V_11 -> V_67 = true ;
}
if ( F_24 ( & V_11 -> V_74 ) >= V_62 )
F_25 ( & V_11 -> V_74 , ( unsigned char * ) V_63 ,
V_62 ) ;
V_11 -> V_69 += V_62 ;
return 0 ;
}
static int F_26 ( struct V_60 * V_24 ,
unsigned V_61 , void * V_64 )
{
struct V_10 * V_11 = F_4 ( V_64 ) ;
if ( ! F_22 ( 0 , & V_11 -> V_71 ) )
return 0 ;
V_11 -> V_69 = 0 ;
V_11 -> V_67 = false ;
F_27 ( & V_11 -> V_75 ) ;
return 0 ;
}
static int F_28 ( struct V_10 * V_11 ,
int V_27 , int V_76 ,
struct V_77 * V_78 ,
struct V_79 * V_80 )
{
struct V_81 * V_82 ;
void * V_44 ;
V_44 = F_29 ( V_11 -> V_44 ,
( V_11 -> V_83 + 1 ) *
sizeof( struct V_81 ) , V_84 ) ;
if ( ! V_44 ) {
F_30 ( V_11 -> V_44 ) ;
return - V_85 ;
}
V_11 -> V_44 = V_44 ;
V_82 = & V_11 -> V_44 [ V_11 -> V_83 ] ;
V_82 -> V_25 . V_61 = V_11 -> V_24 -> V_37 ;
if ( V_80 -> V_86 )
V_82 -> V_25 . V_87 = V_80 -> V_86 ;
else
V_82 -> V_25 . V_87 = V_80 -> V_37 [ 0 ] . V_88 ;
V_82 -> V_25 . V_27 = V_27 ;
V_82 -> V_25 . V_26 = V_78 -> V_89 ;
V_82 -> V_25 . V_53 = V_80 -> V_90 ;
V_82 -> V_25 . V_54 = V_80 -> V_91 ;
V_82 -> V_25 . V_49 = ( V_80 -> V_92 / 8 ) ;
V_82 -> V_25 . V_29 = V_80 -> V_29 ;
V_82 -> V_25 . V_55 = V_80 -> V_55 ;
if ( V_76 == V_93 )
snprintf ( V_82 -> V_94 ,
sizeof( V_82 -> V_94 ) , L_20 ,
V_82 -> V_25 . V_27 ,
V_82 -> V_25 . V_87 ) ;
else if ( V_76 == V_95 ) {
snprintf ( V_82 -> V_94 ,
sizeof( V_82 -> V_94 ) ,
L_21 , V_82 -> V_25 . V_27 ,
V_82 -> V_25 . V_87 ) ;
V_11 -> V_43 ++ ;
V_11 -> V_70 += ( V_80 -> V_92 *
V_80 -> V_96 ) / 8 ;
}
memset ( & V_82 -> V_97 , 0 ,
sizeof( struct V_98 ) ) ;
V_11 -> V_83 ++ ;
return 0 ;
}
static int F_31 ( struct V_10 * V_11 ,
struct V_99 * V_100 ,
int V_76 )
{
int V_48 ;
int V_18 ;
struct V_77 * V_78 ;
struct V_79 * V_80 ;
struct V_60 * V_24 = V_11 -> V_24 ;
F_32 (report, &report_enum->report_list, list) {
for ( V_48 = 0 ; V_48 < V_78 -> V_101 ; ++ V_48 ) {
V_80 = V_78 -> V_80 [ V_48 ] ;
if ( V_80 -> V_102 &&
( ( V_80 -> V_37 [ 0 ] . V_103 >=
V_24 -> V_104 ) &&
( V_80 -> V_37 [ 0 ] . V_103 <
V_24 -> V_105 ) ) ) {
V_18 = F_28 ( V_11 ,
V_48 ,
V_76 ,
V_78 ,
V_80 ) ;
if ( V_18 )
return V_18 ;
}
}
}
return 0 ;
}
static int F_33 ( struct V_10
* V_11 )
{
struct V_60 * V_24 = V_11 -> V_24 ;
struct V_106 * V_30 = V_24 -> V_30 ;
int V_18 = - 1 ;
int V_48 , V_107 ;
for ( V_107 = 0 ; V_107 < V_108 ; ++ V_107 ) {
if ( V_107 == V_109 )
continue;
V_18 = F_31 ( V_11 ,
& V_30 -> V_100 [ V_107 ] , V_107 ) ;
if ( V_18 )
return V_18 ;
}
for ( V_48 = 0 ; V_48 < V_11 -> V_83 ; ++ V_48 ) {
V_107 = 0 ;
while ( V_107 < V_110 &&
V_111 [ V_107 ] . V_39 ) {
struct V_5 * V_112 ;
V_112 = & V_11 -> V_44 [ V_48 ] . V_113 [ V_107 ] ;
snprintf ( ( char * ) & V_11 -> V_44 [ V_48 ] . V_114 [ V_107 ] ,
V_40 , L_22 ,
V_11 -> V_44 [ V_48 ] . V_94 ,
V_111 [ V_107 ] . V_39 ) ;
F_34 ( & V_112 -> V_6 ) ;
V_112 -> V_6 . V_39 =
( char * ) & V_11 -> V_44 [ V_48 ] . V_114 [ V_107 ] ;
V_112 -> V_6 . V_115 = V_111 [ V_107 ] . V_115 ;
V_112 -> V_116 = F_15 ;
if ( V_111 [ V_107 ] . V_115 & V_117 )
V_112 -> V_118 = F_19 ;
V_11 -> V_44 [ V_48 ] . V_119 [ V_107 ] = & V_112 -> V_6 ;
++ V_107 ;
}
V_11 -> V_44 [ V_48 ] . V_119 [ V_107 ] = NULL ;
V_11 -> V_44 [ V_48 ] . V_97 . V_119 =
V_11 -> V_44 [ V_48 ] . V_119 ;
V_11 -> V_44 [ V_48 ] . V_97 . V_39 =
V_11 -> V_44 [ V_48 ] . V_94 ;
V_18 = F_35 ( & V_11 -> V_9 -> V_4 . V_120 ,
& V_11 -> V_44 [ V_48 ] .
V_97 ) ;
if ( V_18 )
break;
if ( V_11 -> V_44 [ V_48 ] . V_25 . V_87 ==
V_121 )
V_11 -> V_23 = & V_11 -> V_44 [ V_48 ] ;
else if ( V_11 -> V_44 [ V_48 ] . V_25 . V_87 ==
V_122 )
V_11 -> V_28 = & V_11 -> V_44 [ V_48 ] ;
}
return V_18 ;
}
static void F_36 ( struct V_10 *
V_11 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_11 -> V_83 ; ++ V_48 )
F_37 ( & V_11 -> V_9 -> V_4 . V_120 ,
& V_11 -> V_44 [ V_48 ] .
V_97 ) ;
F_30 ( V_11 -> V_44 ) ;
}
static T_1 F_38 ( struct V_123 * V_123 , char T_6 * V_7 ,
T_3 V_31 , T_7 * V_124 )
{
struct V_10 * V_11 ;
unsigned int V_125 ;
int V_18 ;
V_11 = F_39 ( V_123 -> V_126 ,
struct V_10 , V_127 ) ;
if ( V_31 < sizeof( struct V_65 ) )
return - V_33 ;
do {
if ( F_40 ( & V_11 -> V_74 ) ) {
if ( V_123 -> V_128 & V_129 )
return - V_130 ;
V_18 = F_41 ( V_11 -> V_75 ,
! F_40 ( & V_11 -> V_74 ) ) ;
if ( V_18 )
return V_18 ;
}
V_18 = F_42 ( & V_11 -> V_74 , V_7 , V_31 ,
& V_125 ) ;
if ( V_18 )
return V_18 ;
} while ( V_125 == 0 );
return V_125 ;
}
static int F_43 ( struct V_131 * V_131 , struct V_123 * V_123 )
{
struct V_10 * V_11 ;
V_11 = F_39 ( V_123 -> V_126 ,
struct V_10 , V_127 ) ;
F_44 ( 0 , & V_11 -> V_71 ) ;
return 0 ;
}
static int F_45 ( struct V_131 * V_131 , struct V_123 * V_123 )
{
struct V_10 * V_11 ;
V_11 = F_39 ( V_123 -> V_126 ,
struct V_10 , V_127 ) ;
if ( F_46 ( 0 , & V_11 -> V_71 ) )
return - V_132 ;
return F_47 ( V_131 , V_123 ) ;
}
static unsigned int F_48 ( struct V_123 * V_123 ,
struct V_133 * V_75 )
{
struct V_10 * V_11 ;
unsigned int V_134 = 0 ;
V_11 = F_39 ( V_123 -> V_126 ,
struct V_10 , V_127 ) ;
F_49 ( V_123 , & V_11 -> V_75 , V_75 ) ;
if ( ! F_40 ( & V_11 -> V_74 ) )
V_134 = V_135 | V_136 ;
return V_134 ;
}
static int F_50 ( struct V_10 * V_11 )
{
int V_18 ;
V_18 = F_51 ( & V_11 -> V_74 , V_137 ,
V_84 ) ;
if ( V_18 )
return V_18 ;
F_52 ( & V_11 -> V_75 ) ;
V_11 -> V_127 . V_138 = V_139 ;
V_11 -> V_127 . V_39 = F_53 ( & V_11 -> V_9 -> V_4 ) ;
V_11 -> V_127 . V_140 = & V_141 ,
V_18 = F_54 ( & V_11 -> V_127 ) ;
if ( V_18 ) {
F_55 ( & V_11 -> V_74 ) ;
return V_18 ;
}
return 0 ;
}
static void F_56 ( struct V_10
* V_11 )
{
F_27 ( & V_11 -> V_75 ) ;
F_57 ( & V_11 -> V_127 ) ;
F_55 ( & V_11 -> V_74 ) ;
}
static int F_58 ( struct V_8 * V_9 )
{
struct V_10 * V_11 ;
struct V_60 * V_24 = V_9 -> V_4 . V_142 ;
int V_18 ;
V_11 = F_59 ( & V_9 -> V_4 , sizeof( * V_11 ) ,
V_84 ) ;
if ( ! V_11 )
return - V_85 ;
V_11 -> V_143 . V_144 = F_20 ;
V_11 -> V_143 . V_145 = F_26 ;
V_11 -> V_143 . V_9 = V_9 ;
V_11 -> V_24 = V_24 ;
V_11 -> V_9 = V_9 ;
F_60 ( & V_11 -> V_34 ) ;
F_61 ( V_9 , V_11 ) ;
V_18 = F_62 ( V_24 , V_24 -> V_37 ,
& V_11 -> V_143 ) ;
if ( V_18 < 0 ) {
F_63 ( & V_9 -> V_4 , L_23 ) ;
return V_18 ;
}
V_18 = F_35 ( & V_11 -> V_9 -> V_4 . V_120 ,
& V_146 ) ;
if ( V_18 )
goto V_147;
V_18 = F_33 ( V_11 ) ;
if ( V_18 )
goto V_148;
V_18 = F_50 ( V_11 ) ;
if ( V_18 )
goto V_149;
return 0 ;
V_149:
F_36 ( V_11 ) ;
V_148:
F_37 ( & V_11 -> V_9 -> V_4 . V_120 ,
& V_146 ) ;
V_147:
F_64 ( V_24 , V_24 -> V_37 ) ;
return V_18 ;
}
static int F_65 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
struct V_60 * V_24 = V_9 -> V_4 . V_142 ;
F_56 ( V_11 ) ;
F_36 ( V_11 ) ;
F_37 ( & V_11 -> V_9 -> V_4 . V_120 ,
& V_146 ) ;
F_64 ( V_24 , V_24 -> V_37 ) ;
return 0 ;
}
