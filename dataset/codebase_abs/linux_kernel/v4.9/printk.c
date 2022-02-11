static int F_1 ( char * V_1 )
{
if ( ! V_1 )
return - V_2 ;
if ( ! strncmp ( V_1 , L_1 , 2 ) ) {
V_3 = V_4 ;
return 2 ;
} else if ( ! strncmp ( V_1 , L_2 , 3 ) ) {
V_3 = V_5 ;
return 3 ;
} else if ( ! strncmp ( V_1 , L_3 , 9 ) ) {
V_3 = V_6 ;
return 9 ;
}
return - V_2 ;
}
static int T_1 F_2 ( char * V_1 )
{
if ( F_1 ( V_1 ) < 0 )
return 1 ;
if ( V_3 == V_4 ) {
memset ( V_7 , 0 , V_8 ) ;
strncpy ( V_7 , L_1 , 2 ) ;
} else if ( V_3 == V_5 ) {
memset ( V_7 , 0 , V_8 ) ;
strncpy ( V_7 , L_2 , 3 ) ;
}
V_3 |= V_9 ;
return 0 ;
}
int F_3 ( struct V_10 * V_11 , int V_12 ,
void T_2 * V_13 , T_3 * V_14 , T_4 * V_15 )
{
char V_16 [ V_8 ] ;
unsigned int V_17 ;
int V_18 ;
if ( V_12 ) {
if ( V_3 & V_9 )
return - V_2 ;
V_17 = V_3 ;
strncpy ( V_16 , V_7 , V_8 ) ;
}
V_18 = F_4 ( V_11 , V_12 , V_13 , V_14 , V_15 ) ;
if ( V_18 )
return V_18 ;
if ( V_12 ) {
V_18 = F_1 ( V_7 ) ;
if ( V_18 < 0 || ( V_18 + 1 != * V_14 ) ) {
V_3 = V_17 ;
strncpy ( V_7 , V_16 , V_8 ) ;
return - V_2 ;
}
}
return 0 ;
}
static int F_5 ( unsigned long V_19 )
{
if ( F_6 ( & V_20 ) )
return 1 ;
F_7 ( & V_21 , 0 , 1 , V_19 ) ;
return 0 ;
}
char * F_8 ( void )
{
return V_22 ;
}
T_5 F_9 ( void )
{
return V_23 ;
}
static char * F_10 ( const struct V_24 * V_25 )
{
return ( char * ) V_25 + sizeof( struct V_24 ) ;
}
static char * F_11 ( const struct V_24 * V_25 )
{
return ( char * ) V_25 + sizeof( struct V_24 ) + V_25 -> V_26 ;
}
static struct V_24 * F_12 ( T_5 V_27 )
{
struct V_24 * V_25 = (struct V_24 * ) ( V_22 + V_27 ) ;
if ( ! V_25 -> V_28 )
return (struct V_24 * ) V_22 ;
return V_25 ;
}
static T_5 F_13 ( T_5 V_27 )
{
struct V_24 * V_25 = (struct V_24 * ) ( V_22 + V_27 ) ;
if ( ! V_25 -> V_28 ) {
V_25 = (struct V_24 * ) V_22 ;
return V_25 -> V_28 ;
}
return V_27 + V_25 -> V_28 ;
}
static int F_14 ( T_5 V_29 , bool V_30 )
{
T_5 free ;
if ( V_31 > V_32 || V_30 )
free = F_15 ( V_23 - V_31 , V_32 ) ;
else
free = V_32 - V_31 ;
return free >= V_29 + sizeof( struct V_24 ) ;
}
static int F_16 ( T_5 V_29 )
{
while ( V_33 < V_34 &&
! F_14 ( V_29 , false ) ) {
V_32 = F_13 ( V_32 ) ;
V_33 ++ ;
}
if ( V_35 < V_33 ) {
V_35 = V_33 ;
V_36 = V_32 ;
}
if ( F_14 ( V_29 , V_33 == V_34 ) )
return 0 ;
return - V_37 ;
}
static T_5 F_17 ( T_6 V_26 , T_6 V_38 , T_5 * V_39 )
{
T_5 V_40 ;
V_40 = sizeof( struct V_24 ) + V_26 + V_38 ;
* V_39 = ( - V_40 ) & ( V_41 - 1 ) ;
V_40 += * V_39 ;
return V_40 ;
}
static T_5 F_18 ( T_6 * V_26 , T_6 * V_42 ,
T_6 * V_38 , T_5 * V_39 )
{
T_5 V_43 = V_23 / V_44 ;
if ( * V_26 > V_43 )
* V_26 = V_43 ;
* V_42 = strlen ( V_45 ) ;
* V_38 = 0 ;
return F_17 ( * V_26 + * V_42 , 0 , V_39 ) ;
}
static int F_19 ( int V_46 , int V_47 ,
enum V_48 V_49 , T_7 V_50 ,
const char * V_51 , T_6 V_38 ,
const char * V_52 , T_6 V_26 )
{
struct V_24 * V_25 ;
T_5 V_40 , V_39 ;
T_6 V_42 = 0 ;
V_40 = F_17 ( V_26 , V_38 , & V_39 ) ;
if ( F_16 ( V_40 ) ) {
V_40 = F_18 ( & V_26 , & V_42 ,
& V_38 , & V_39 ) ;
if ( F_16 ( V_40 ) )
return 0 ;
}
if ( V_31 + V_40 + sizeof( struct V_24 ) > V_23 ) {
memset ( V_22 + V_31 , 0 , sizeof( struct V_24 ) ) ;
V_31 = 0 ;
}
V_25 = (struct V_24 * ) ( V_22 + V_31 ) ;
memcpy ( F_10 ( V_25 ) , V_52 , V_26 ) ;
V_25 -> V_26 = V_26 ;
if ( V_42 ) {
memcpy ( F_10 ( V_25 ) + V_26 , V_45 , V_42 ) ;
V_25 -> V_26 += V_42 ;
}
memcpy ( F_11 ( V_25 ) , V_51 , V_38 ) ;
V_25 -> V_38 = V_38 ;
V_25 -> V_46 = V_46 ;
V_25 -> V_47 = V_47 & 7 ;
V_25 -> V_49 = V_49 & 0x1f ;
if ( V_50 > 0 )
V_25 -> V_50 = V_50 ;
else
V_25 -> V_50 = F_20 () ;
memset ( F_11 ( V_25 ) + V_38 , 0 , V_39 ) ;
V_25 -> V_28 = V_40 ;
V_31 += V_25 -> V_28 ;
V_34 ++ ;
return V_25 -> V_26 ;
}
static int F_21 ( int type )
{
if ( V_53 )
return 1 ;
return type != V_54 &&
type != V_55 ;
}
int F_22 ( int type , int V_56 )
{
if ( V_56 == V_57 && type != V_58 )
goto V_59;
if ( F_21 ( type ) ) {
if ( F_23 ( V_60 ) )
goto V_59;
if ( F_23 ( V_61 ) ) {
F_24 ( L_4
L_5
L_6 ,
V_62 -> V_63 , F_25 ( V_62 ) ) ;
goto V_59;
}
return - V_64 ;
}
V_59:
return F_26 ( type ) ;
}
static void F_27 ( char * * V_65 , char * V_66 , char V_67 )
{
if ( * V_65 < V_66 )
* ( * V_65 ) ++ = V_67 ;
}
static T_8 F_28 ( char * V_68 , T_3 V_40 ,
struct V_24 * V_25 , T_7 V_69 ,
enum V_48 V_70 )
{
T_7 V_71 = V_25 -> V_50 ;
char V_72 = '-' ;
F_29 ( V_71 , 1000 ) ;
if ( V_25 -> V_49 & V_73 )
V_72 = ( V_70 & V_73 ) ? '+' : 'c' ;
return F_30 ( V_68 , V_40 , L_7 ,
( V_25 -> V_46 << 3 ) | V_25 -> V_47 , V_69 , V_71 , V_72 ) ;
}
static T_8 F_31 ( char * V_68 , T_3 V_40 ,
char * V_51 , T_3 V_38 ,
char * V_52 , T_3 V_26 )
{
char * V_74 = V_68 , * V_66 = V_68 + V_40 ;
T_3 V_75 ;
for ( V_75 = 0 ; V_75 < V_26 ; V_75 ++ ) {
unsigned char V_67 = V_52 [ V_75 ] ;
if ( V_67 < ' ' || V_67 >= 127 || V_67 == '\\' )
V_74 += F_30 ( V_74 , V_66 - V_74 , L_8 , V_67 ) ;
else
F_27 ( & V_74 , V_66 , V_67 ) ;
}
F_27 ( & V_74 , V_66 , '\n' ) ;
if ( V_38 ) {
bool line = true ;
for ( V_75 = 0 ; V_75 < V_38 ; V_75 ++ ) {
unsigned char V_67 = V_51 [ V_75 ] ;
if ( line ) {
F_27 ( & V_74 , V_66 , ' ' ) ;
line = false ;
}
if ( V_67 == '\0' ) {
F_27 ( & V_74 , V_66 , '\n' ) ;
line = true ;
continue;
}
if ( V_67 < ' ' || V_67 >= 127 || V_67 == '\\' ) {
V_74 += F_30 ( V_74 , V_66 - V_74 , L_8 , V_67 ) ;
continue;
}
F_27 ( & V_74 , V_66 , V_67 ) ;
}
F_27 ( & V_74 , V_66 , '\n' ) ;
}
return V_74 - V_68 ;
}
static T_8 F_32 ( struct V_76 * V_77 , struct V_78 * V_79 )
{
char * V_68 , * line ;
int V_47 = V_80 ;
int V_46 = 1 ;
struct V_81 * V_81 = V_77 -> V_82 ;
struct V_83 * V_84 = V_81 -> V_85 ;
T_3 V_28 = F_33 ( V_79 ) ;
T_8 V_86 = V_28 ;
if ( ! V_84 || V_28 > V_87 )
return - V_2 ;
if ( V_3 & V_5 )
return V_28 ;
if ( ! ( V_3 & V_4 ) ) {
if ( ! F_34 ( & V_84 -> V_88 , V_62 -> V_63 ) )
return V_86 ;
}
V_68 = F_35 ( V_28 + 1 , V_89 ) ;
if ( V_68 == NULL )
return - V_37 ;
V_68 [ V_28 ] = '\0' ;
if ( F_36 ( V_68 , V_28 , V_79 ) != V_28 ) {
F_37 ( V_68 ) ;
return - V_90 ;
}
line = V_68 ;
if ( line [ 0 ] == '<' ) {
char * V_91 = NULL ;
unsigned int V_92 ;
V_92 = F_38 ( line + 1 , & V_91 , 10 ) ;
if ( V_91 && V_91 [ 0 ] == '>' ) {
V_47 = F_39 ( V_92 ) ;
if ( F_40 ( V_92 ) != 0 )
V_46 = F_40 ( V_92 ) ;
V_91 ++ ;
V_28 -= V_91 - line ;
line = V_91 ;
}
}
F_41 ( V_46 , V_47 , NULL , 0 , L_9 , line ) ;
F_37 ( V_68 ) ;
return V_86 ;
}
static T_8 F_42 ( struct V_81 * V_81 , char T_2 * V_68 ,
T_3 V_93 , T_4 * V_15 )
{
struct V_83 * V_84 = V_81 -> V_85 ;
struct V_24 * V_25 ;
T_3 V_28 ;
T_8 V_86 ;
if ( ! V_84 )
return - V_94 ;
V_86 = F_43 ( & V_84 -> V_95 ) ;
if ( V_86 )
return V_86 ;
F_44 ( & V_96 ) ;
while ( V_84 -> V_69 == V_34 ) {
if ( V_81 -> V_97 & V_98 ) {
V_86 = - V_99 ;
F_45 ( & V_96 ) ;
goto V_100;
}
F_45 ( & V_96 ) ;
V_86 = F_46 ( V_101 ,
V_84 -> V_69 != V_34 ) ;
if ( V_86 )
goto V_100;
F_44 ( & V_96 ) ;
}
if ( V_84 -> V_69 < V_33 ) {
V_84 -> V_27 = V_32 ;
V_84 -> V_69 = V_33 ;
V_86 = - V_102 ;
F_45 ( & V_96 ) ;
goto V_100;
}
V_25 = F_12 ( V_84 -> V_27 ) ;
V_28 = F_28 ( V_84 -> V_68 , sizeof( V_84 -> V_68 ) ,
V_25 , V_84 -> V_69 , V_84 -> V_103 ) ;
V_28 += F_31 ( V_84 -> V_68 + V_28 , sizeof( V_84 -> V_68 ) - V_28 ,
F_11 ( V_25 ) , V_25 -> V_38 ,
F_10 ( V_25 ) , V_25 -> V_26 ) ;
V_84 -> V_103 = V_25 -> V_49 ;
V_84 -> V_27 = F_13 ( V_84 -> V_27 ) ;
V_84 -> V_69 ++ ;
F_45 ( & V_96 ) ;
if ( V_28 > V_93 ) {
V_86 = - V_2 ;
goto V_100;
}
if ( F_47 ( V_68 , V_84 -> V_68 , V_28 ) ) {
V_86 = - V_90 ;
goto V_100;
}
V_86 = V_28 ;
V_100:
F_48 ( & V_84 -> V_95 ) ;
return V_86 ;
}
static T_4 F_49 ( struct V_81 * V_81 , T_4 V_104 , int V_105 )
{
struct V_83 * V_84 = V_81 -> V_85 ;
T_4 V_86 = 0 ;
if ( ! V_84 )
return - V_94 ;
if ( V_104 )
return - V_106 ;
F_44 ( & V_96 ) ;
switch ( V_105 ) {
case V_107 :
V_84 -> V_27 = V_32 ;
V_84 -> V_69 = V_33 ;
break;
case V_108 :
V_84 -> V_27 = V_36 ;
V_84 -> V_69 = V_35 ;
break;
case V_109 :
V_84 -> V_27 = V_31 ;
V_84 -> V_69 = V_34 ;
break;
default:
V_86 = - V_2 ;
}
F_45 ( & V_96 ) ;
return V_86 ;
}
static unsigned int F_50 ( struct V_81 * V_81 , T_9 * V_110 )
{
struct V_83 * V_84 = V_81 -> V_85 ;
int V_86 = 0 ;
if ( ! V_84 )
return V_111 | V_112 ;
F_51 ( V_81 , & V_101 , V_110 ) ;
F_44 ( & V_96 ) ;
if ( V_84 -> V_69 < V_34 ) {
if ( V_84 -> V_69 < V_33 )
V_86 = V_113 | V_114 | V_111 | V_115 ;
else
V_86 = V_113 | V_114 ;
}
F_45 ( & V_96 ) ;
return V_86 ;
}
static int F_52 ( struct V_116 * V_116 , struct V_81 * V_81 )
{
struct V_83 * V_84 ;
int V_18 ;
if ( V_3 & V_5 )
return - V_64 ;
if ( ( V_81 -> V_97 & V_117 ) != V_118 ) {
V_18 = F_22 ( V_54 ,
V_119 ) ;
if ( V_18 )
return V_18 ;
}
V_84 = F_35 ( sizeof( struct V_83 ) , V_89 ) ;
if ( ! V_84 )
return - V_37 ;
F_53 ( & V_84 -> V_88 ) ;
F_54 ( & V_84 -> V_88 , V_120 ) ;
F_55 ( & V_84 -> V_95 ) ;
F_44 ( & V_96 ) ;
V_84 -> V_27 = V_32 ;
V_84 -> V_69 = V_33 ;
F_45 ( & V_96 ) ;
V_81 -> V_85 = V_84 ;
return 0 ;
}
static int F_56 ( struct V_116 * V_116 , struct V_81 * V_81 )
{
struct V_83 * V_84 = V_81 -> V_85 ;
if ( ! V_84 )
return 0 ;
F_57 ( & V_84 -> V_88 ) ;
F_58 ( & V_84 -> V_95 ) ;
F_37 ( V_84 ) ;
return 0 ;
}
void F_59 ( void )
{
F_60 ( V_22 ) ;
F_60 ( V_23 ) ;
F_60 ( V_32 ) ;
F_60 ( V_36 ) ;
F_60 ( V_31 ) ;
F_61 ( V_24 ) ;
F_62 ( V_24 , V_50 ) ;
F_62 ( V_24 , V_28 ) ;
F_62 ( V_24 , V_26 ) ;
F_62 ( V_24 , V_38 ) ;
}
static void T_1 F_63 ( unsigned V_40 )
{
if ( V_40 )
V_40 = F_64 ( V_40 ) ;
if ( V_40 > V_23 )
V_121 = V_40 ;
}
static int T_1 F_65 ( char * V_1 )
{
unsigned V_40 = F_66 ( V_1 , & V_1 ) ;
F_63 ( V_40 ) ;
return 0 ;
}
static void T_1 F_67 ( void )
{
unsigned int V_122 ;
if ( F_68 () == 1 )
return;
V_122 = ( F_68 () - 1 ) * V_123 ;
if ( V_122 <= V_124 / 2 )
return;
F_69 ( L_10 ,
V_123 ) ;
F_69 ( L_11 ,
V_122 ) ;
F_69 ( L_12 , V_124 ) ;
F_63 ( V_122 + V_124 ) ;
}
static inline void F_67 ( void ) {}
void T_1 F_70 ( int V_125 )
{
unsigned long V_49 ;
char * V_126 ;
int free ;
if ( V_22 != V_127 )
return;
if ( ! V_125 && ! V_121 )
F_67 () ;
if ( ! V_121 )
return;
if ( V_125 ) {
V_126 =
F_71 ( V_121 , V_41 ) ;
} else {
V_126 = F_72 ( V_121 ,
V_41 ) ;
}
if ( F_73 ( ! V_126 ) ) {
F_74 ( L_13 ,
V_121 ) ;
return;
}
F_75 ( & V_96 , V_49 ) ;
V_23 = V_121 ;
V_22 = V_126 ;
V_121 = 0 ;
free = V_124 - V_31 ;
memcpy ( V_22 , V_127 , V_124 ) ;
F_76 ( & V_96 , V_49 ) ;
F_69 ( L_14 , V_23 ) ;
F_69 ( L_15 ,
free , ( free * 100 ) / V_124 ) ;
}
static int T_1 F_77 ( char * V_1 )
{
V_128 = true ;
F_69 ( L_16 ) ;
return 0 ;
}
static bool F_78 ( int V_47 )
{
return ( V_47 >= V_129 && ! V_128 ) ;
}
static int T_1 F_79 ( char * V_1 )
{
unsigned long V_130 ;
V_130 = V_131 ? V_131 : 1000000 ;
V_132 = ( unsigned long long ) V_130 / 1000 * V_133 ;
F_80 ( & V_1 , & V_134 ) ;
if ( V_134 > 10 * 1000 )
V_134 = 0 ;
F_81 ( L_17
L_18 ,
V_134 , V_131 , V_130 , V_133 , V_132 ) ;
return 0 ;
}
static void F_82 ( int V_47 )
{
unsigned long long V_135 ;
unsigned long V_136 ;
if ( ( V_134 == 0 || V_137 != V_138 )
|| F_78 ( V_47 ) ) {
return;
}
V_135 = ( unsigned long long ) V_132 * V_134 ;
V_136 = V_139 + F_83 ( V_134 ) ;
while ( V_135 ) {
V_135 -- ;
F_84 () ;
if ( F_85 ( V_139 , V_136 ) )
break;
F_86 () ;
}
}
static inline void F_82 ( int V_47 )
{
}
static T_3 F_87 ( T_7 V_140 , char * V_68 )
{
unsigned long V_141 ;
if ( ! V_142 )
return 0 ;
V_141 = F_29 ( V_140 , 1000000000 ) ;
if ( ! V_68 )
return snprintf ( NULL , 0 , L_19 , ( unsigned long ) V_140 ) ;
return sprintf ( V_68 , L_20 ,
( unsigned long ) V_140 , V_141 / 1000 ) ;
}
static T_3 F_88 ( const struct V_24 * V_25 , bool V_143 , char * V_68 )
{
T_3 V_28 = 0 ;
unsigned int V_144 = ( V_25 -> V_46 << 3 ) | V_25 -> V_47 ;
if ( V_143 ) {
if ( V_68 ) {
V_28 += sprintf ( V_68 , L_21 , V_144 ) ;
} else {
V_28 += 3 ;
if ( V_144 > 999 )
V_28 += 3 ;
else if ( V_144 > 99 )
V_28 += 2 ;
else if ( V_144 > 9 )
V_28 ++ ;
}
}
V_28 += F_87 ( V_25 -> V_50 , V_68 ? V_68 + V_28 : NULL ) ;
return V_28 ;
}
static T_3 F_89 ( const struct V_24 * V_25 , enum V_48 V_103 ,
bool V_143 , char * V_68 , T_3 V_40 )
{
const char * V_52 = F_10 ( V_25 ) ;
T_3 V_145 = V_25 -> V_26 ;
bool V_144 = true ;
bool V_146 = true ;
T_3 V_28 = 0 ;
if ( ( V_103 & V_73 ) && ! ( V_25 -> V_49 & V_147 ) )
V_144 = false ;
if ( V_25 -> V_49 & V_73 ) {
if ( ( V_103 & V_73 ) && ! ( V_103 & V_148 ) )
V_144 = false ;
if ( ! ( V_25 -> V_49 & V_148 ) )
V_146 = false ;
}
do {
const char * V_149 = memchr ( V_52 , '\n' , V_145 ) ;
T_3 V_26 ;
if ( V_149 ) {
V_26 = V_149 - V_52 ;
V_149 ++ ;
V_145 -= V_149 - V_52 ;
} else {
V_26 = V_145 ;
}
if ( V_68 ) {
if ( F_88 ( V_25 , V_143 , NULL ) +
V_26 + 1 >= V_40 - V_28 )
break;
if ( V_144 )
V_28 += F_88 ( V_25 , V_143 , V_68 + V_28 ) ;
memcpy ( V_68 + V_28 , V_52 , V_26 ) ;
V_28 += V_26 ;
if ( V_149 || V_146 )
V_68 [ V_28 ++ ] = '\n' ;
} else {
if ( V_144 )
V_28 += F_88 ( V_25 , V_143 , NULL ) ;
V_28 += V_26 ;
if ( V_149 || V_146 )
V_28 ++ ;
}
V_144 = true ;
V_52 = V_149 ;
} while ( V_52 );
return V_28 ;
}
static int F_90 ( char T_2 * V_68 , int V_40 )
{
char * V_52 ;
struct V_24 * V_25 ;
int V_28 = 0 ;
V_52 = F_35 ( V_87 + V_150 , V_89 ) ;
if ( ! V_52 )
return - V_37 ;
while ( V_40 > 0 ) {
T_3 V_151 ;
T_3 V_152 ;
F_44 ( & V_96 ) ;
if ( V_153 < V_33 ) {
V_153 = V_33 ;
V_154 = V_32 ;
V_155 = 0 ;
V_156 = 0 ;
}
if ( V_153 == V_34 ) {
F_45 ( & V_96 ) ;
break;
}
V_152 = V_156 ;
V_25 = F_12 ( V_154 ) ;
V_151 = F_89 ( V_25 , V_155 , true , V_52 ,
V_87 + V_150 ) ;
if ( V_151 - V_156 <= V_40 ) {
V_154 = F_13 ( V_154 ) ;
V_153 ++ ;
V_155 = V_25 -> V_49 ;
V_151 -= V_156 ;
V_156 = 0 ;
} else if ( ! V_28 ) {
V_151 = V_40 ;
V_156 += V_151 ;
} else
V_151 = 0 ;
F_45 ( & V_96 ) ;
if ( ! V_151 )
break;
if ( F_47 ( V_68 , V_52 + V_152 , V_151 ) ) {
if ( ! V_28 )
V_28 = - V_90 ;
break;
}
V_28 += V_151 ;
V_40 -= V_151 ;
V_68 += V_151 ;
}
F_37 ( V_52 ) ;
return V_28 ;
}
static int F_91 ( char T_2 * V_68 , int V_40 , bool V_157 )
{
char * V_52 ;
int V_28 = 0 ;
V_52 = F_35 ( V_87 + V_150 , V_89 ) ;
if ( ! V_52 )
return - V_37 ;
F_44 ( & V_96 ) ;
if ( V_68 ) {
T_7 V_158 ;
T_7 V_69 ;
T_5 V_27 ;
enum V_48 V_103 ;
V_69 = V_35 ;
V_27 = V_36 ;
V_103 = 0 ;
while ( V_69 < V_34 ) {
struct V_24 * V_25 = F_12 ( V_27 ) ;
V_28 += F_89 ( V_25 , V_103 , true , NULL , 0 ) ;
V_103 = V_25 -> V_49 ;
V_27 = F_13 ( V_27 ) ;
V_69 ++ ;
}
V_69 = V_35 ;
V_27 = V_36 ;
V_103 = 0 ;
while ( V_28 > V_40 && V_69 < V_34 ) {
struct V_24 * V_25 = F_12 ( V_27 ) ;
V_28 -= F_89 ( V_25 , V_103 , true , NULL , 0 ) ;
V_103 = V_25 -> V_49 ;
V_27 = F_13 ( V_27 ) ;
V_69 ++ ;
}
V_158 = V_34 ;
V_28 = 0 ;
while ( V_28 >= 0 && V_69 < V_158 ) {
struct V_24 * V_25 = F_12 ( V_27 ) ;
int V_159 ;
V_159 = F_89 ( V_25 , V_103 , true , V_52 ,
V_87 + V_150 ) ;
if ( V_159 < 0 ) {
V_28 = V_159 ;
break;
}
V_27 = F_13 ( V_27 ) ;
V_69 ++ ;
V_103 = V_25 -> V_49 ;
F_45 ( & V_96 ) ;
if ( F_47 ( V_68 + V_28 , V_52 , V_159 ) )
V_28 = - V_90 ;
else
V_28 += V_159 ;
F_44 ( & V_96 ) ;
if ( V_69 < V_33 ) {
V_69 = V_33 ;
V_27 = V_32 ;
V_103 = 0 ;
}
}
}
if ( V_157 ) {
V_35 = V_34 ;
V_36 = V_31 ;
}
F_45 ( & V_96 ) ;
F_37 ( V_52 ) ;
return V_28 ;
}
int F_92 ( int type , char T_2 * V_68 , int V_28 , int V_56 )
{
bool V_157 = false ;
static int V_160 = V_161 ;
int error ;
error = F_22 ( type , V_56 ) ;
if ( error )
goto V_100;
switch ( type ) {
case V_162 :
break;
case V_58 :
break;
case V_163 :
error = - V_2 ;
if ( ! V_68 || V_28 < 0 )
goto V_100;
error = 0 ;
if ( ! V_28 )
goto V_100;
if ( ! F_93 ( V_164 , V_68 , V_28 ) ) {
error = - V_90 ;
goto V_100;
}
error = F_46 ( V_101 ,
V_153 != V_34 ) ;
if ( error )
goto V_100;
error = F_90 ( V_68 , V_28 ) ;
break;
case V_165 :
V_157 = true ;
case V_54 :
error = - V_2 ;
if ( ! V_68 || V_28 < 0 )
goto V_100;
error = 0 ;
if ( ! V_28 )
goto V_100;
if ( ! F_93 ( V_164 , V_68 , V_28 ) ) {
error = - V_90 ;
goto V_100;
}
error = F_91 ( V_68 , V_28 , V_157 ) ;
break;
case V_166 :
F_91 ( NULL , 0 , true ) ;
break;
case V_167 :
if ( V_160 == V_161 )
V_160 = V_129 ;
V_129 = V_168 ;
break;
case V_169 :
if ( V_160 != V_161 ) {
V_129 = V_160 ;
V_160 = V_161 ;
}
break;
case V_170 :
error = - V_2 ;
if ( V_28 < 1 || V_28 > 8 )
goto V_100;
if ( V_28 < V_168 )
V_28 = V_168 ;
V_129 = V_28 ;
V_160 = V_161 ;
error = 0 ;
break;
case V_171 :
F_44 ( & V_96 ) ;
if ( V_153 < V_33 ) {
V_153 = V_33 ;
V_154 = V_32 ;
V_155 = 0 ;
V_156 = 0 ;
}
if ( V_56 == V_57 ) {
error = V_34 - V_153 ;
} else {
T_7 V_69 = V_153 ;
T_5 V_27 = V_154 ;
enum V_48 V_103 = V_155 ;
error = 0 ;
while ( V_69 < V_34 ) {
struct V_24 * V_25 = F_12 ( V_27 ) ;
error += F_89 ( V_25 , V_103 , true , NULL , 0 ) ;
V_27 = F_13 ( V_27 ) ;
V_69 ++ ;
V_103 = V_25 -> V_49 ;
}
error -= V_156 ;
}
F_45 ( & V_96 ) ;
break;
case V_55 :
error = V_23 ;
break;
default:
error = - V_2 ;
break;
}
V_100:
return error ;
}
static void F_94 ( int V_47 ,
const char * V_172 , T_3 V_173 ,
const char * V_52 , T_3 V_28 )
{
struct V_174 * V_175 ;
F_95 ( V_52 , V_28 ) ;
if ( ! V_176 )
return;
F_96 (con) {
if ( V_177 && V_175 != V_177 )
continue;
if ( ! ( V_175 -> V_49 & V_178 ) )
continue;
if ( ! V_175 -> V_12 )
continue;
if ( ! F_97 ( F_98 () ) &&
! ( V_175 -> V_49 & V_179 ) )
continue;
if ( V_175 -> V_49 & V_180 )
V_175 -> V_12 ( V_175 , V_172 , V_173 ) ;
else
V_175 -> V_12 ( V_175 , V_52 , V_28 ) ;
}
}
static void F_99 ( void )
{
static unsigned long V_181 ;
if ( F_100 ( V_139 , V_181 ) &&
! F_85 ( V_139 , V_181 + 30 * V_133 ) )
return;
V_181 = V_139 ;
F_101 () ;
F_102 ( & V_96 ) ;
F_103 ( & V_20 , 1 ) ;
}
static inline void F_104 ( void )
{
if ( F_73 ( V_182 ) ) {
int V_183 = V_182 ;
while ( V_183 -- ) {
F_105 ( 1 ) ;
F_86 () ;
}
}
}
static void F_106 ( void )
{
if ( V_72 . V_184 )
return;
if ( V_72 . V_28 == 0 )
return;
if ( V_72 . V_185 ) {
F_19 ( V_72 . V_46 , V_72 . V_47 , V_72 . V_49 | V_186 ,
V_72 . V_50 , NULL , 0 , V_72 . V_68 , V_72 . V_28 ) ;
V_72 . V_184 = true ;
} else {
F_19 ( V_72 . V_46 , V_72 . V_47 , V_72 . V_49 , 0 ,
NULL , 0 , V_72 . V_68 , V_72 . V_28 ) ;
V_72 . V_28 = 0 ;
}
}
static bool F_107 ( int V_46 , int V_47 , enum V_48 V_49 , const char * V_52 , T_3 V_28 )
{
if ( V_72 . V_28 && V_72 . V_184 )
return false ;
if ( V_187 || V_72 . V_28 + V_28 > sizeof( V_72 . V_68 ) ) {
F_106 () ;
return false ;
}
if ( ! V_72 . V_28 ) {
V_72 . V_46 = V_46 ;
V_72 . V_47 = V_47 ;
V_72 . V_188 = V_62 ;
V_72 . V_50 = F_20 () ;
V_72 . V_49 = V_49 ;
V_72 . V_185 = 0 ;
V_72 . V_184 = false ;
}
memcpy ( V_72 . V_68 + V_72 . V_28 , V_52 , V_28 ) ;
V_72 . V_28 += V_28 ;
if ( V_49 & V_148 ) {
V_72 . V_49 |= V_148 ;
F_106 () ;
}
if ( V_72 . V_28 > ( sizeof( V_72 . V_68 ) * 80 ) / 100 )
F_106 () ;
return true ;
}
static T_3 F_108 ( char * V_52 , T_3 V_40 )
{
T_3 V_159 = 0 ;
T_3 V_28 ;
if ( V_72 . V_185 == 0 && ( V_189 & V_148 ) ) {
V_159 += F_87 ( V_72 . V_50 , V_52 ) ;
V_40 -= V_159 ;
}
V_28 = V_72 . V_28 - V_72 . V_185 ;
if ( V_28 > 0 ) {
if ( V_28 + 1 > V_40 )
V_28 = V_40 - 1 ;
memcpy ( V_52 + V_159 , V_72 . V_68 + V_72 . V_185 , V_28 ) ;
V_159 += V_28 ;
V_72 . V_185 = V_72 . V_28 ;
}
if ( V_72 . V_184 ) {
if ( V_72 . V_49 & V_148 )
V_52 [ V_159 ++ ] = '\n' ;
V_72 . V_28 = 0 ;
}
return V_159 ;
}
static T_3 F_109 ( int V_46 , int V_47 , enum V_48 V_190 , const char * V_51 , T_3 V_191 , char * V_52 , T_3 V_26 )
{
if ( V_72 . V_28 ) {
if ( V_72 . V_188 == V_62 && ( V_190 & V_73 ) ) {
if ( F_107 ( V_46 , V_47 , V_190 , V_52 , V_26 ) )
return V_26 ;
}
F_106 () ;
}
if ( ! V_26 && ( V_190 & V_73 ) )
return 0 ;
if ( ! ( V_190 & V_148 ) ) {
if ( F_107 ( V_46 , V_47 , V_190 , V_52 , V_26 ) )
return V_26 ;
}
return F_19 ( V_46 , V_47 , V_190 , 0 , V_51 , V_191 , V_52 , V_26 ) ;
}
T_10 int F_110 ( int V_46 , int V_47 ,
const char * V_51 , T_3 V_191 ,
const char * V_192 , T_11 args )
{
static bool V_193 ;
static char V_194 [ V_87 ] ;
char * V_52 = V_194 ;
T_3 V_26 = 0 ;
enum V_48 V_190 = 0 ;
unsigned long V_49 ;
int V_195 ;
int V_196 = 0 ;
int V_197 ;
bool V_198 = false ;
static unsigned int V_199 = V_200 ;
if ( V_47 == V_201 ) {
V_47 = V_161 ;
V_198 = true ;
}
F_82 ( V_47 ) ;
F_104 () ;
F_111 ( V_49 ) ;
V_195 = F_98 () ;
if ( F_73 ( V_199 == V_195 ) ) {
if ( ! V_202 && ! F_112 ( V_62 ) ) {
V_193 = true ;
F_113 ( V_49 ) ;
return 0 ;
}
F_99 () ;
}
F_114 () ;
F_115 ( & V_96 ) ;
V_199 = V_195 ;
if ( F_73 ( V_193 ) ) {
static const char V_203 [] =
L_22 ;
V_193 = false ;
V_196 += F_19 ( 0 , 2 , V_147 | V_148 , 0 ,
NULL , 0 , V_203 ,
strlen ( V_203 ) ) ;
}
V_197 = F_116 () ;
if ( F_73 ( V_197 ) ) {
V_26 = F_30 ( V_194 , sizeof( V_194 ) ,
L_23 ,
V_197 ) ;
V_196 += F_19 ( 0 , 2 , V_147 | V_148 , 0 ,
NULL , 0 , V_194 , V_26 ) ;
}
V_26 = F_117 ( V_52 , sizeof( V_194 ) , V_192 , args ) ;
if ( V_26 && V_52 [ V_26 - 1 ] == '\n' ) {
V_26 -- ;
V_190 |= V_148 ;
}
if ( V_46 == 0 ) {
int V_204 ;
while ( ( V_204 = F_118 ( V_52 ) ) != 0 ) {
switch ( V_204 ) {
case '0' ... '7' :
if ( V_47 == V_161 )
V_47 = V_204 - '0' ;
case 'd' :
V_190 |= V_147 ;
break;
case 'c' :
V_190 |= V_73 ;
}
V_26 -= 2 ;
V_52 += 2 ;
}
}
if ( V_47 == V_161 )
V_47 = V_80 ;
if ( V_51 )
V_190 |= V_147 | V_148 ;
V_196 += F_109 ( V_46 , V_47 , V_190 , V_51 , V_191 , V_52 , V_26 ) ;
V_199 = V_200 ;
F_119 ( & V_96 ) ;
F_120 () ;
F_113 ( V_49 ) ;
if ( ! V_198 ) {
F_114 () ;
if ( F_121 () )
F_122 () ;
F_120 () ;
}
return V_196 ;
}
T_10 int F_123 ( const char * V_192 , T_11 args )
{
return F_110 ( 0 , V_161 , NULL , 0 , V_192 , args ) ;
}
T_10 int F_41 ( int V_46 , int V_47 ,
const char * V_51 , T_3 V_191 ,
const char * V_192 , ... )
{
T_11 args ;
int V_205 ;
va_start ( args , V_192 ) ;
V_205 = F_110 ( V_46 , V_47 , V_51 , V_191 , V_192 , args ) ;
va_end ( args ) ;
return V_205 ;
}
int F_124 ( const char * V_192 , T_11 args )
{
int V_205 ;
#ifdef F_125
if ( F_73 ( V_206 ) ) {
V_205 = F_126 ( V_207 , V_192 , args ) ;
return V_205 ;
}
#endif
V_205 = F_110 ( 0 , V_161 , NULL , 0 , V_192 , args ) ;
return V_205 ;
}
T_10 T_12 int F_127 ( const char * V_192 , ... )
{
T_11 args ;
int V_205 ;
va_start ( args , V_192 ) ;
V_205 = F_128 ( V_192 , args ) ;
va_end ( args ) ;
return V_205 ;
}
static char * F_10 ( const struct V_24 * V_25 ) { return NULL ; }
static char * F_11 ( const struct V_24 * V_25 ) { return NULL ; }
static struct V_24 * F_12 ( T_5 V_27 ) { return NULL ; }
static T_5 F_13 ( T_5 V_27 ) { return 0 ; }
static T_8 F_28 ( char * V_68 , T_3 V_40 ,
struct V_24 * V_25 , T_7 V_69 ,
enum V_48 V_70 ) { return 0 ; }
static T_8 F_31 ( char * V_68 , T_3 V_40 ,
char * V_51 , T_3 V_38 ,
char * V_52 , T_3 V_26 ) { return 0 ; }
static void F_94 ( int V_47 ,
const char * V_172 , T_3 V_173 ,
const char * V_52 , T_3 V_28 ) {}
static T_3 F_89 ( const struct V_24 * V_25 , enum V_48 V_103 ,
bool V_143 , char * V_68 , T_3 V_40 ) { return 0 ; }
static T_3 F_108 ( char * V_52 , T_3 V_40 ) { return 0 ; }
static bool F_78 ( int V_47 ) { return false ; }
T_10 T_12 void F_129 ( const char * V_192 , ... )
{
T_11 V_208 ;
char V_68 [ 512 ] ;
int V_151 ;
if ( ! V_209 )
return;
va_start ( V_208 , V_192 ) ;
V_151 = F_117 ( V_68 , sizeof( V_68 ) , V_192 , V_208 ) ;
va_end ( V_208 ) ;
V_209 -> V_12 ( V_209 , V_68 , V_151 ) ;
}
static int F_130 ( char * V_210 , int V_27 , char * V_211 ,
char * V_212 )
{
struct V_213 * V_67 ;
int V_75 ;
for ( V_75 = 0 , V_67 = V_213 ;
V_75 < V_214 && V_67 -> V_210 [ 0 ] ;
V_75 ++ , V_67 ++ ) {
if ( strcmp ( V_67 -> V_210 , V_210 ) == 0 && V_67 -> V_215 == V_27 ) {
if ( ! V_212 )
V_216 = V_75 ;
return 0 ;
}
}
if ( V_75 == V_214 )
return - V_217 ;
if ( ! V_212 )
V_216 = V_75 ;
F_131 ( V_67 -> V_210 , V_210 , sizeof( V_67 -> V_210 ) ) ;
V_67 -> V_211 = V_211 ;
F_132 ( V_67 , V_212 ) ;
V_67 -> V_215 = V_27 ;
return 0 ;
}
static int T_1 F_133 ( char * V_1 )
{
char V_68 [ sizeof( V_213 [ 0 ] . V_210 ) + 4 ] ;
char * V_218 , * V_211 , * V_212 = NULL ;
int V_27 ;
if ( F_134 ( & V_1 , & V_212 ) )
return 1 ;
if ( V_1 [ 0 ] >= '0' && V_1 [ 0 ] <= '9' ) {
strcpy ( V_68 , L_24 ) ;
strncpy ( V_68 + 4 , V_1 , sizeof( V_68 ) - 5 ) ;
} else {
strncpy ( V_68 , V_1 , sizeof( V_68 ) - 1 ) ;
}
V_68 [ sizeof( V_68 ) - 1 ] = 0 ;
V_211 = strchr ( V_1 , ',' ) ;
if ( V_211 )
* ( V_211 ++ ) = 0 ;
#ifdef F_135
if ( ! strcmp ( V_1 , L_25 ) )
strcpy ( V_68 , L_26 ) ;
if ( ! strcmp ( V_1 , L_27 ) )
strcpy ( V_68 , L_28 ) ;
#endif
for ( V_218 = V_68 ; * V_218 ; V_218 ++ )
if ( isdigit ( * V_218 ) || * V_218 == ',' )
break;
V_27 = F_38 ( V_218 , NULL , 10 ) ;
* V_218 = 0 ;
F_130 ( V_68 , V_27 , V_211 , V_212 ) ;
V_219 = 1 ;
return 1 ;
}
int F_136 ( char * V_210 , int V_27 , char * V_211 )
{
return F_130 ( V_210 , V_27 , V_211 , NULL ) ;
}
static int T_1 F_137 ( char * V_1 )
{
V_220 = false ;
return 1 ;
}
void F_138 ( void )
{
if ( ! V_220 )
return;
F_127 ( L_29 ) ;
F_139 () ;
V_221 = 1 ;
F_140 () ;
}
void F_141 ( void )
{
if ( ! V_220 )
return;
F_142 () ;
V_221 = 0 ;
F_122 () ;
}
static int F_143 ( struct V_222 * V_223 ,
unsigned long V_224 , void * V_225 )
{
switch ( V_224 ) {
case V_226 :
case V_227 :
case V_228 :
case V_229 :
F_139 () ;
F_122 () ;
}
return V_230 ;
}
void F_139 ( void )
{
F_144 () ;
F_142 () ;
if ( V_221 )
return;
V_231 = 1 ;
V_232 = 1 ;
}
int F_121 ( void )
{
if ( F_145 () )
return 0 ;
if ( V_221 ) {
F_140 () ;
return 0 ;
}
V_231 = 1 ;
V_232 = ! V_202 &&
F_146 () &&
! F_147 () ;
return 1 ;
}
int F_148 ( void )
{
return V_231 ;
}
static int F_149 ( void )
{
struct V_174 * V_175 ;
F_96 (con)
if ( ( V_175 -> V_49 & V_178 ) &&
( V_175 -> V_49 & V_179 ) )
return 1 ;
return 0 ;
}
static inline int F_150 ( void )
{
return F_97 ( F_151 () ) || F_149 () ;
}
static void F_152 ( char * V_52 , T_3 V_40 )
{
unsigned long V_49 ;
T_3 V_28 ;
F_75 ( & V_96 , V_49 ) ;
if ( ! V_72 . V_28 )
goto V_100;
if ( F_78 ( V_72 . V_47 ) ) {
V_72 . V_185 = V_72 . V_28 ;
if ( V_72 . V_184 )
V_72 . V_28 = 0 ;
goto V_100;
}
if ( V_233 < V_34 && ! V_72 . V_185 )
goto V_100;
V_28 = F_108 ( V_52 , V_40 ) ;
F_119 ( & V_96 ) ;
F_153 () ;
F_94 ( V_72 . V_47 , NULL , 0 , V_52 , V_28 ) ;
F_154 () ;
F_113 ( V_49 ) ;
return;
V_100:
F_76 ( & V_96 , V_49 ) ;
}
void F_122 ( void )
{
static char V_172 [ V_234 ] ;
static char V_52 [ V_87 + V_150 ] ;
static T_7 V_235 ;
unsigned long V_49 ;
bool V_236 = false ;
bool V_237 , V_238 ;
if ( V_221 ) {
F_140 () ;
return;
}
V_237 = V_232 ;
V_232 = 0 ;
V_239:
if ( ! F_150 () ) {
V_231 = 0 ;
F_140 () ;
return;
}
F_152 ( V_52 , sizeof( V_52 ) ) ;
for (; ; ) {
struct V_24 * V_25 ;
T_3 V_173 = 0 ;
T_3 V_28 ;
int V_47 ;
F_75 ( & V_96 , V_49 ) ;
if ( V_235 != V_34 ) {
V_236 = true ;
V_235 = V_34 ;
}
if ( V_233 < V_33 ) {
V_28 = sprintf ( V_52 , L_30 ,
( unsigned ) ( V_33 - V_233 ) ) ;
V_233 = V_33 ;
V_240 = V_32 ;
V_189 = 0 ;
} else {
V_28 = 0 ;
}
V_152:
if ( V_233 == V_34 )
break;
V_25 = F_12 ( V_240 ) ;
V_47 = V_25 -> V_47 ;
if ( ( V_25 -> V_49 & V_186 ) ||
F_78 ( V_47 ) ) {
V_240 = F_13 ( V_240 ) ;
V_233 ++ ;
V_25 -> V_49 &= ~ V_186 ;
V_189 = V_25 -> V_49 ;
goto V_152;
}
V_28 += F_89 ( V_25 , V_189 , false ,
V_52 + V_28 , sizeof( V_52 ) - V_28 ) ;
if ( V_187 ) {
V_173 = F_28 ( V_172 ,
sizeof( V_172 ) ,
V_25 , V_233 , V_189 ) ;
V_173 += F_31 ( V_172 + V_173 ,
sizeof( V_172 ) - V_173 ,
F_11 ( V_25 ) , V_25 -> V_38 ,
F_10 ( V_25 ) , V_25 -> V_26 ) ;
}
V_240 = F_13 ( V_240 ) ;
V_233 ++ ;
V_189 = V_25 -> V_49 ;
F_119 ( & V_96 ) ;
F_153 () ;
F_94 ( V_47 , V_172 , V_173 , V_52 , V_28 ) ;
F_154 () ;
F_113 ( V_49 ) ;
if ( V_237 )
F_155 () ;
}
V_231 = 0 ;
if ( F_73 ( V_177 ) )
V_177 = NULL ;
F_119 ( & V_96 ) ;
F_140 () ;
F_115 ( & V_96 ) ;
V_238 = V_233 != V_34 ;
F_76 ( & V_96 , V_49 ) ;
if ( V_238 && F_121 () )
goto V_239;
if ( V_236 )
F_156 () ;
}
void T_13 F_157 ( void )
{
if ( V_232 )
F_155 () ;
}
void F_158 ( void )
{
struct V_174 * V_67 ;
if ( V_202 ) {
if ( F_145 () != 0 )
return;
} else
F_139 () ;
V_231 = 1 ;
V_232 = 0 ;
F_96 (c)
if ( ( V_67 -> V_49 & V_178 ) && V_67 -> V_241 )
V_67 -> V_241 () ;
F_122 () ;
}
void F_159 ( void )
{
F_121 () ;
V_232 = 0 ;
F_122 () ;
}
struct V_242 * F_160 ( int * V_215 )
{
struct V_174 * V_67 ;
struct V_242 * V_243 = NULL ;
F_139 () ;
F_96 (c) {
if ( ! V_67 -> V_244 )
continue;
V_243 = V_67 -> V_244 ( V_67 , V_215 ) ;
if ( V_243 )
break;
}
F_122 () ;
return V_243 ;
}
void F_161 ( struct V_174 * V_174 )
{
F_139 () ;
V_174 -> V_49 &= ~ V_178 ;
F_122 () ;
}
void F_162 ( struct V_174 * V_174 )
{
F_139 () ;
V_174 -> V_49 |= V_178 ;
F_122 () ;
}
static int T_1 F_163 ( char * V_1 )
{
V_245 = 1 ;
F_69 ( L_31 ) ;
return 0 ;
}
void F_164 ( struct V_174 * V_246 )
{
int V_75 ;
unsigned long V_49 ;
struct V_174 * V_247 = NULL ;
struct V_213 * V_67 ;
if ( V_176 )
F_96 (bcon)
if ( F_165 ( V_247 == V_246 ,
L_32 ,
V_247 -> V_210 , V_247 -> V_215 ) )
return;
if ( V_176 && V_246 -> V_49 & V_248 ) {
F_96 (bcon) {
if ( ! ( V_247 -> V_49 & V_248 ) ) {
F_69 ( L_33 ,
V_246 -> V_210 , V_246 -> V_215 ) ;
return;
}
}
}
if ( V_176 && V_176 -> V_49 & V_248 )
V_247 = V_176 ;
if ( V_249 < 0 || V_247 || ! V_176 )
V_249 = V_216 ;
if ( V_249 < 0 ) {
if ( V_246 -> V_215 < 0 )
V_246 -> V_215 = 0 ;
if ( V_246 -> V_250 == NULL ||
V_246 -> V_250 ( V_246 , NULL ) == 0 ) {
V_246 -> V_49 |= V_178 ;
if ( V_246 -> V_244 ) {
V_246 -> V_49 |= V_251 ;
V_249 = 0 ;
}
}
}
for ( V_75 = 0 , V_67 = V_213 ;
V_75 < V_214 && V_67 -> V_210 [ 0 ] ;
V_75 ++ , V_67 ++ ) {
if ( ! V_246 -> V_252 ||
V_246 -> V_252 ( V_246 , V_67 -> V_210 , V_67 -> V_215 , V_67 -> V_211 ) != 0 ) {
F_166 ( sizeof( V_67 -> V_210 ) != sizeof( V_246 -> V_210 ) ) ;
if ( strcmp ( V_67 -> V_210 , V_246 -> V_210 ) != 0 )
continue;
if ( V_246 -> V_215 >= 0 &&
V_246 -> V_215 != V_67 -> V_215 )
continue;
if ( V_246 -> V_215 < 0 )
V_246 -> V_215 = V_67 -> V_215 ;
if ( F_167 ( V_246 , V_67 ) )
return;
if ( V_246 -> V_250 &&
V_246 -> V_250 ( V_246 , V_67 -> V_211 ) != 0 )
break;
}
V_246 -> V_49 |= V_178 ;
if ( V_75 == V_216 ) {
V_246 -> V_49 |= V_251 ;
V_249 = V_216 ;
}
break;
}
if ( ! ( V_246 -> V_49 & V_178 ) )
return;
if ( V_247 && ( ( V_246 -> V_49 & ( V_251 | V_248 ) ) == V_251 ) )
V_246 -> V_49 &= ~ V_253 ;
F_139 () ;
if ( ( V_246 -> V_49 & V_251 ) || V_176 == NULL ) {
V_246 -> V_149 = V_176 ;
V_176 = V_246 ;
if ( V_246 -> V_149 )
V_246 -> V_149 -> V_49 &= ~ V_251 ;
} else {
V_246 -> V_149 = V_176 -> V_149 ;
V_176 -> V_149 = V_246 ;
}
if ( V_246 -> V_49 & V_180 )
if ( ! V_187 ++ )
F_69 ( L_34 ) ;
if ( V_246 -> V_49 & V_253 ) {
F_75 ( & V_96 , V_49 ) ;
V_233 = V_153 ;
V_240 = V_154 ;
V_189 = V_155 ;
F_76 ( & V_96 , V_49 ) ;
V_177 = V_246 ;
}
F_122 () ;
F_168 () ;
F_69 ( L_35 ,
( V_246 -> V_49 & V_248 ) ? L_36 : L_37 ,
V_246 -> V_210 , V_246 -> V_215 ) ;
if ( V_247 &&
( ( V_246 -> V_49 & ( V_251 | V_248 ) ) == V_251 ) &&
! V_245 ) {
F_96 (bcon)
if ( V_247 -> V_49 & V_248 )
F_169 ( V_247 ) ;
}
}
int F_169 ( struct V_174 * V_174 )
{
struct V_174 * V_254 , * V_255 ;
int V_256 ;
F_69 ( L_38 ,
( V_174 -> V_49 & V_248 ) ? L_36 : L_37 ,
V_174 -> V_210 , V_174 -> V_215 ) ;
V_256 = F_170 ( V_174 ) ;
if ( V_256 )
return V_256 ;
V_256 = 1 ;
F_139 () ;
if ( V_176 == V_174 ) {
V_176 = V_174 -> V_149 ;
V_256 = 0 ;
} else if ( V_176 ) {
for ( V_254 = V_176 -> V_149 , V_255 = V_176 ;
V_254 ; V_255 = V_254 , V_254 = V_255 -> V_149 ) {
if ( V_254 == V_174 ) {
V_255 -> V_149 = V_254 -> V_149 ;
V_256 = 0 ;
break;
}
}
}
if ( ! V_256 && ( V_174 -> V_49 & V_180 ) )
V_187 -- ;
if ( V_176 != NULL && V_174 -> V_49 & V_251 )
V_176 -> V_49 |= V_251 ;
V_174 -> V_49 &= ~ V_178 ;
F_122 () ;
F_168 () ;
return V_256 ;
}
static int T_1 F_171 ( void )
{
struct V_174 * V_175 ;
F_96 (con) {
if ( ! V_245 && V_175 -> V_49 & V_248 ) {
if ( F_172 ( V_175 , sizeof( * V_175 ) ) )
F_169 ( V_175 ) ;
}
}
F_173 ( F_143 , 0 ) ;
return 0 ;
}
static void F_174 ( struct V_257 * V_257 )
{
int V_258 = F_175 ( V_259 , 0 ) ;
if ( V_258 & V_260 ) {
if ( F_121 () )
F_122 () ;
}
if ( V_258 & V_261 )
F_176 ( & V_101 ) ;
}
void F_156 ( void )
{
F_177 () ;
if ( F_178 ( & V_101 ) ) {
F_179 ( V_259 , V_261 ) ;
F_180 ( F_181 ( & V_262 ) ) ;
}
F_182 () ;
}
int F_183 ( const char * V_192 , ... )
{
T_11 args ;
int V_205 ;
F_177 () ;
va_start ( args , V_192 ) ;
V_205 = F_110 ( 0 , V_201 , NULL , 0 , V_192 , args ) ;
va_end ( args ) ;
F_184 ( V_259 , V_260 ) ;
F_180 ( F_181 ( & V_262 ) ) ;
F_182 () ;
return V_205 ;
}
int F_185 ( const char * V_263 )
{
return F_34 ( & V_264 , V_263 ) ;
}
bool F_186 ( unsigned long * V_265 ,
unsigned int V_266 )
{
unsigned long V_267 = V_139 - * V_265 ;
if ( * V_265 && V_267 <= F_83 ( V_266 ) )
return false ;
* V_265 = V_139 ;
return true ;
}
int F_187 ( struct V_268 * V_269 )
{
unsigned long V_49 ;
int V_18 = - V_270 ;
if ( ! V_269 -> V_271 )
return - V_2 ;
F_188 ( & V_272 , V_49 ) ;
if ( ! V_269 -> V_273 ) {
V_269 -> V_273 = 1 ;
F_189 ( & V_269 -> V_274 , & V_275 ) ;
V_18 = 0 ;
}
F_190 ( & V_272 , V_49 ) ;
return V_18 ;
}
int F_191 ( struct V_268 * V_269 )
{
unsigned long V_49 ;
int V_18 = - V_2 ;
F_188 ( & V_272 , V_49 ) ;
if ( V_269 -> V_273 ) {
V_269 -> V_273 = 0 ;
F_192 ( & V_269 -> V_274 ) ;
V_18 = 0 ;
}
F_190 ( & V_272 , V_49 ) ;
F_193 () ;
return V_18 ;
}
void F_194 ( enum V_276 V_277 )
{
struct V_268 * V_269 ;
unsigned long V_49 ;
if ( ( V_277 > V_278 ) && ! V_279 )
return;
F_195 () ;
F_196 (dumper, &dump_list, list) {
if ( V_269 -> V_280 && V_277 > V_269 -> V_280 )
continue;
V_269 -> V_281 = true ;
F_75 ( & V_96 , V_49 ) ;
V_269 -> V_282 = V_35 ;
V_269 -> V_283 = V_36 ;
V_269 -> V_158 = V_34 ;
V_269 -> V_284 = V_31 ;
F_76 ( & V_96 , V_49 ) ;
V_269 -> V_271 ( V_269 , V_277 ) ;
V_269 -> V_281 = false ;
}
F_197 () ;
}
bool F_198 ( struct V_268 * V_269 , bool V_143 ,
char * line , T_3 V_40 , T_3 * V_28 )
{
struct V_24 * V_25 ;
T_3 V_285 = 0 ;
bool V_86 = false ;
if ( ! V_269 -> V_281 )
goto V_100;
if ( V_269 -> V_282 < V_33 ) {
V_269 -> V_282 = V_33 ;
V_269 -> V_283 = V_32 ;
}
if ( V_269 -> V_282 >= V_34 )
goto V_100;
V_25 = F_12 ( V_269 -> V_283 ) ;
V_285 = F_89 ( V_25 , 0 , V_143 , line , V_40 ) ;
V_269 -> V_283 = F_13 ( V_269 -> V_283 ) ;
V_269 -> V_282 ++ ;
V_86 = true ;
V_100:
if ( V_28 )
* V_28 = V_285 ;
return V_86 ;
}
bool F_199 ( struct V_268 * V_269 , bool V_143 ,
char * line , T_3 V_40 , T_3 * V_28 )
{
unsigned long V_49 ;
bool V_86 ;
F_75 ( & V_96 , V_49 ) ;
V_86 = F_198 ( V_269 , V_143 , line , V_40 , V_28 ) ;
F_76 ( & V_96 , V_49 ) ;
return V_86 ;
}
bool F_200 ( struct V_268 * V_269 , bool V_143 ,
char * V_68 , T_3 V_40 , T_3 * V_28 )
{
unsigned long V_49 ;
T_7 V_69 ;
T_5 V_27 ;
T_7 V_158 ;
T_5 V_284 ;
enum V_48 V_103 ;
T_3 V_285 = 0 ;
bool V_86 = false ;
if ( ! V_269 -> V_281 )
goto V_100;
F_75 ( & V_96 , V_49 ) ;
if ( V_269 -> V_282 < V_33 ) {
V_269 -> V_282 = V_33 ;
V_269 -> V_283 = V_32 ;
}
if ( V_269 -> V_282 >= V_269 -> V_158 ) {
F_76 ( & V_96 , V_49 ) ;
goto V_100;
}
V_69 = V_269 -> V_282 ;
V_27 = V_269 -> V_283 ;
V_103 = 0 ;
while ( V_69 < V_269 -> V_158 ) {
struct V_24 * V_25 = F_12 ( V_27 ) ;
V_285 += F_89 ( V_25 , V_103 , true , NULL , 0 ) ;
V_27 = F_13 ( V_27 ) ;
V_69 ++ ;
V_103 = V_25 -> V_49 ;
}
V_69 = V_269 -> V_282 ;
V_27 = V_269 -> V_283 ;
V_103 = 0 ;
while ( V_285 > V_40 && V_69 < V_269 -> V_158 ) {
struct V_24 * V_25 = F_12 ( V_27 ) ;
V_285 -= F_89 ( V_25 , V_103 , true , NULL , 0 ) ;
V_27 = F_13 ( V_27 ) ;
V_69 ++ ;
V_103 = V_25 -> V_49 ;
}
V_158 = V_69 ;
V_284 = V_27 ;
V_285 = 0 ;
while ( V_69 < V_269 -> V_158 ) {
struct V_24 * V_25 = F_12 ( V_27 ) ;
V_285 += F_89 ( V_25 , V_103 , V_143 , V_68 + V_285 , V_40 - V_285 ) ;
V_27 = F_13 ( V_27 ) ;
V_69 ++ ;
V_103 = V_25 -> V_49 ;
}
V_269 -> V_158 = V_158 ;
V_269 -> V_284 = V_284 ;
V_86 = true ;
F_76 ( & V_96 , V_49 ) ;
V_100:
if ( V_28 )
* V_28 = V_285 ;
return V_86 ;
}
void F_201 ( struct V_268 * V_269 )
{
V_269 -> V_282 = V_35 ;
V_269 -> V_283 = V_36 ;
V_269 -> V_158 = V_34 ;
V_269 -> V_284 = V_31 ;
}
void F_202 ( struct V_268 * V_269 )
{
unsigned long V_49 ;
F_75 ( & V_96 , V_49 ) ;
F_201 ( V_269 ) ;
F_76 ( & V_96 , V_49 ) ;
}
void T_1 F_203 ( const char * V_192 , ... )
{
T_11 args ;
va_start ( args , V_192 ) ;
vsnprintf ( V_286 , sizeof( V_286 ) ,
V_192 , args ) ;
va_end ( args ) ;
}
void F_204 ( const char * V_287 )
{
F_127 ( L_39 ,
V_287 , F_151 () , V_62 -> V_288 , V_62 -> V_63 ,
F_205 () , F_206 () -> V_289 ,
( int ) strcspn ( F_206 () -> V_290 , L_40 ) ,
F_206 () -> V_290 ) ;
if ( V_286 [ 0 ] != '\0' )
F_127 ( L_41 ,
V_287 , V_286 ) ;
F_207 ( V_287 , V_62 ) ;
}
void F_208 ( const char * V_287 )
{
F_204 ( V_287 ) ;
F_127 ( L_42 ,
V_287 , V_62 , F_209 ( V_62 ) ) ;
}
