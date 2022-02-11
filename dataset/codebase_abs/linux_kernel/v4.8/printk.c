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
if ( V_25 -> V_49 & V_73 && ! ( V_70 & V_73 ) )
V_72 = 'c' ;
else if ( ( V_25 -> V_49 & V_73 ) ||
( ( V_70 & V_73 ) && ! ( V_25 -> V_49 & V_74 ) ) )
V_72 = '+' ;
return F_30 ( V_68 , V_40 , L_7 ,
( V_25 -> V_46 << 3 ) | V_25 -> V_47 , V_69 , V_71 , V_72 ) ;
}
static T_8 F_31 ( char * V_68 , T_3 V_40 ,
char * V_51 , T_3 V_38 ,
char * V_52 , T_3 V_26 )
{
char * V_75 = V_68 , * V_66 = V_68 + V_40 ;
T_3 V_76 ;
for ( V_76 = 0 ; V_76 < V_26 ; V_76 ++ ) {
unsigned char V_67 = V_52 [ V_76 ] ;
if ( V_67 < ' ' || V_67 >= 127 || V_67 == '\\' )
V_75 += F_30 ( V_75 , V_66 - V_75 , L_8 , V_67 ) ;
else
F_27 ( & V_75 , V_66 , V_67 ) ;
}
F_27 ( & V_75 , V_66 , '\n' ) ;
if ( V_38 ) {
bool line = true ;
for ( V_76 = 0 ; V_76 < V_38 ; V_76 ++ ) {
unsigned char V_67 = V_51 [ V_76 ] ;
if ( line ) {
F_27 ( & V_75 , V_66 , ' ' ) ;
line = false ;
}
if ( V_67 == '\0' ) {
F_27 ( & V_75 , V_66 , '\n' ) ;
line = true ;
continue;
}
if ( V_67 < ' ' || V_67 >= 127 || V_67 == '\\' ) {
V_75 += F_30 ( V_75 , V_66 - V_75 , L_8 , V_67 ) ;
continue;
}
F_27 ( & V_75 , V_66 , V_67 ) ;
}
F_27 ( & V_75 , V_66 , '\n' ) ;
}
return V_75 - V_68 ;
}
static T_8 F_32 ( struct V_77 * V_78 , struct V_79 * V_80 )
{
char * V_68 , * line ;
int V_47 = V_81 ;
int V_46 = 1 ;
struct V_82 * V_82 = V_78 -> V_83 ;
struct V_84 * V_85 = V_82 -> V_86 ;
T_3 V_28 = F_33 ( V_80 ) ;
T_8 V_87 = V_28 ;
if ( ! V_85 || V_28 > V_88 )
return - V_2 ;
if ( V_3 & V_5 )
return V_28 ;
if ( ! ( V_3 & V_4 ) ) {
if ( ! F_34 ( & V_85 -> V_89 , V_62 -> V_63 ) )
return V_87 ;
}
V_68 = F_35 ( V_28 + 1 , V_90 ) ;
if ( V_68 == NULL )
return - V_37 ;
V_68 [ V_28 ] = '\0' ;
if ( F_36 ( V_68 , V_28 , V_80 ) != V_28 ) {
F_37 ( V_68 ) ;
return - V_91 ;
}
line = V_68 ;
if ( line [ 0 ] == '<' ) {
char * V_92 = NULL ;
unsigned int V_93 ;
V_93 = F_38 ( line + 1 , & V_92 , 10 ) ;
if ( V_92 && V_92 [ 0 ] == '>' ) {
V_47 = F_39 ( V_93 ) ;
if ( F_40 ( V_93 ) != 0 )
V_46 = F_40 ( V_93 ) ;
V_92 ++ ;
V_28 -= V_92 - line ;
line = V_92 ;
}
}
F_41 ( V_46 , V_47 , NULL , 0 , L_9 , line ) ;
F_37 ( V_68 ) ;
return V_87 ;
}
static T_8 F_42 ( struct V_82 * V_82 , char T_2 * V_68 ,
T_3 V_94 , T_4 * V_15 )
{
struct V_84 * V_85 = V_82 -> V_86 ;
struct V_24 * V_25 ;
T_3 V_28 ;
T_8 V_87 ;
if ( ! V_85 )
return - V_95 ;
V_87 = F_43 ( & V_85 -> V_96 ) ;
if ( V_87 )
return V_87 ;
F_44 ( & V_97 ) ;
while ( V_85 -> V_69 == V_34 ) {
if ( V_82 -> V_98 & V_99 ) {
V_87 = - V_100 ;
F_45 ( & V_97 ) ;
goto V_101;
}
F_45 ( & V_97 ) ;
V_87 = F_46 ( V_102 ,
V_85 -> V_69 != V_34 ) ;
if ( V_87 )
goto V_101;
F_44 ( & V_97 ) ;
}
if ( V_85 -> V_69 < V_33 ) {
V_85 -> V_27 = V_32 ;
V_85 -> V_69 = V_33 ;
V_87 = - V_103 ;
F_45 ( & V_97 ) ;
goto V_101;
}
V_25 = F_12 ( V_85 -> V_27 ) ;
V_28 = F_28 ( V_85 -> V_68 , sizeof( V_85 -> V_68 ) ,
V_25 , V_85 -> V_69 , V_85 -> V_104 ) ;
V_28 += F_31 ( V_85 -> V_68 + V_28 , sizeof( V_85 -> V_68 ) - V_28 ,
F_11 ( V_25 ) , V_25 -> V_38 ,
F_10 ( V_25 ) , V_25 -> V_26 ) ;
V_85 -> V_104 = V_25 -> V_49 ;
V_85 -> V_27 = F_13 ( V_85 -> V_27 ) ;
V_85 -> V_69 ++ ;
F_45 ( & V_97 ) ;
if ( V_28 > V_94 ) {
V_87 = - V_2 ;
goto V_101;
}
if ( F_47 ( V_68 , V_85 -> V_68 , V_28 ) ) {
V_87 = - V_91 ;
goto V_101;
}
V_87 = V_28 ;
V_101:
F_48 ( & V_85 -> V_96 ) ;
return V_87 ;
}
static T_4 F_49 ( struct V_82 * V_82 , T_4 V_105 , int V_106 )
{
struct V_84 * V_85 = V_82 -> V_86 ;
T_4 V_87 = 0 ;
if ( ! V_85 )
return - V_95 ;
if ( V_105 )
return - V_107 ;
F_44 ( & V_97 ) ;
switch ( V_106 ) {
case V_108 :
V_85 -> V_27 = V_32 ;
V_85 -> V_69 = V_33 ;
break;
case V_109 :
V_85 -> V_27 = V_36 ;
V_85 -> V_69 = V_35 ;
break;
case V_110 :
V_85 -> V_27 = V_31 ;
V_85 -> V_69 = V_34 ;
break;
default:
V_87 = - V_2 ;
}
F_45 ( & V_97 ) ;
return V_87 ;
}
static unsigned int F_50 ( struct V_82 * V_82 , T_9 * V_111 )
{
struct V_84 * V_85 = V_82 -> V_86 ;
int V_87 = 0 ;
if ( ! V_85 )
return V_112 | V_113 ;
F_51 ( V_82 , & V_102 , V_111 ) ;
F_44 ( & V_97 ) ;
if ( V_85 -> V_69 < V_34 ) {
if ( V_85 -> V_69 < V_33 )
V_87 = V_114 | V_115 | V_112 | V_116 ;
else
V_87 = V_114 | V_115 ;
}
F_45 ( & V_97 ) ;
return V_87 ;
}
static int F_52 ( struct V_117 * V_117 , struct V_82 * V_82 )
{
struct V_84 * V_85 ;
int V_18 ;
if ( V_3 & V_5 )
return - V_64 ;
if ( ( V_82 -> V_98 & V_118 ) != V_119 ) {
V_18 = F_22 ( V_54 ,
V_120 ) ;
if ( V_18 )
return V_18 ;
}
V_85 = F_35 ( sizeof( struct V_84 ) , V_90 ) ;
if ( ! V_85 )
return - V_37 ;
F_53 ( & V_85 -> V_89 ) ;
F_54 ( & V_85 -> V_89 , V_121 ) ;
F_55 ( & V_85 -> V_96 ) ;
F_44 ( & V_97 ) ;
V_85 -> V_27 = V_32 ;
V_85 -> V_69 = V_33 ;
F_45 ( & V_97 ) ;
V_82 -> V_86 = V_85 ;
return 0 ;
}
static int F_56 ( struct V_117 * V_117 , struct V_82 * V_82 )
{
struct V_84 * V_85 = V_82 -> V_86 ;
if ( ! V_85 )
return 0 ;
F_57 ( & V_85 -> V_89 ) ;
F_58 ( & V_85 -> V_96 ) ;
F_37 ( V_85 ) ;
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
V_122 = V_40 ;
}
static int T_1 F_65 ( char * V_1 )
{
unsigned V_40 = F_66 ( V_1 , & V_1 ) ;
F_63 ( V_40 ) ;
return 0 ;
}
static void T_1 F_67 ( void )
{
unsigned int V_123 ;
if ( F_68 () == 1 )
return;
V_123 = ( F_68 () - 1 ) * V_124 ;
if ( V_123 <= V_125 / 2 )
return;
F_69 ( L_10 ,
V_124 ) ;
F_69 ( L_11 ,
V_123 ) ;
F_69 ( L_12 , V_125 ) ;
F_63 ( V_123 + V_125 ) ;
}
static inline void F_67 ( void ) {}
void T_1 F_70 ( int V_126 )
{
unsigned long V_49 ;
char * V_127 ;
int free ;
if ( V_22 != V_128 )
return;
if ( ! V_126 && ! V_122 )
F_67 () ;
if ( ! V_122 )
return;
if ( V_126 ) {
V_127 =
F_71 ( V_122 , V_41 ) ;
} else {
V_127 = F_72 ( V_122 ,
V_41 ) ;
}
if ( F_73 ( ! V_127 ) ) {
F_74 ( L_13 ,
V_122 ) ;
return;
}
F_75 ( & V_97 , V_49 ) ;
V_23 = V_122 ;
V_22 = V_127 ;
V_122 = 0 ;
free = V_125 - V_31 ;
memcpy ( V_22 , V_128 , V_125 ) ;
F_76 ( & V_97 , V_49 ) ;
F_69 ( L_14 , V_23 ) ;
F_69 ( L_15 ,
free , ( free * 100 ) / V_125 ) ;
}
static int T_1 F_77 ( char * V_1 )
{
V_129 = true ;
F_69 ( L_16 ) ;
return 0 ;
}
static bool F_78 ( int V_47 )
{
return ( V_47 >= V_130 && ! V_129 ) ;
}
static int T_1 F_79 ( char * V_1 )
{
unsigned long V_131 ;
V_131 = V_132 ? V_132 : 1000000 ;
V_133 = ( unsigned long long ) V_131 / 1000 * V_134 ;
F_80 ( & V_1 , & V_135 ) ;
if ( V_135 > 10 * 1000 )
V_135 = 0 ;
F_81 ( L_17
L_18 ,
V_135 , V_132 , V_131 , V_134 , V_133 ) ;
return 0 ;
}
static void F_82 ( int V_47 )
{
unsigned long long V_136 ;
unsigned long V_137 ;
if ( ( V_135 == 0 || V_138 != V_139 )
|| F_78 ( V_47 ) ) {
return;
}
V_136 = ( unsigned long long ) V_133 * V_135 ;
V_137 = V_140 + F_83 ( V_135 ) ;
while ( V_136 ) {
V_136 -- ;
F_84 () ;
if ( F_85 ( V_140 , V_137 ) )
break;
F_86 () ;
}
}
static inline void F_82 ( int V_47 )
{
}
static T_3 F_87 ( T_7 V_141 , char * V_68 )
{
unsigned long V_142 ;
if ( ! V_143 )
return 0 ;
V_142 = F_29 ( V_141 , 1000000000 ) ;
if ( ! V_68 )
return snprintf ( NULL , 0 , L_19 , ( unsigned long ) V_141 ) ;
return sprintf ( V_68 , L_20 ,
( unsigned long ) V_141 , V_142 / 1000 ) ;
}
static T_3 F_88 ( const struct V_24 * V_25 , bool V_144 , char * V_68 )
{
T_3 V_28 = 0 ;
unsigned int V_145 = ( V_25 -> V_46 << 3 ) | V_25 -> V_47 ;
if ( V_144 ) {
if ( V_68 ) {
V_28 += sprintf ( V_68 , L_21 , V_145 ) ;
} else {
V_28 += 3 ;
if ( V_145 > 999 )
V_28 += 3 ;
else if ( V_145 > 99 )
V_28 += 2 ;
else if ( V_145 > 9 )
V_28 ++ ;
}
}
V_28 += F_87 ( V_25 -> V_50 , V_68 ? V_68 + V_28 : NULL ) ;
return V_28 ;
}
static T_3 F_89 ( const struct V_24 * V_25 , enum V_48 V_104 ,
bool V_144 , char * V_68 , T_3 V_40 )
{
const char * V_52 = F_10 ( V_25 ) ;
T_3 V_146 = V_25 -> V_26 ;
bool V_145 = true ;
bool V_147 = true ;
T_3 V_28 = 0 ;
if ( ( V_104 & V_73 ) && ! ( V_25 -> V_49 & V_74 ) )
V_145 = false ;
if ( V_25 -> V_49 & V_73 ) {
if ( ( V_104 & V_73 ) && ! ( V_104 & V_148 ) )
V_145 = false ;
if ( ! ( V_25 -> V_49 & V_148 ) )
V_147 = false ;
}
do {
const char * V_149 = memchr ( V_52 , '\n' , V_146 ) ;
T_3 V_26 ;
if ( V_149 ) {
V_26 = V_149 - V_52 ;
V_149 ++ ;
V_146 -= V_149 - V_52 ;
} else {
V_26 = V_146 ;
}
if ( V_68 ) {
if ( F_88 ( V_25 , V_144 , NULL ) +
V_26 + 1 >= V_40 - V_28 )
break;
if ( V_145 )
V_28 += F_88 ( V_25 , V_144 , V_68 + V_28 ) ;
memcpy ( V_68 + V_28 , V_52 , V_26 ) ;
V_28 += V_26 ;
if ( V_149 || V_147 )
V_68 [ V_28 ++ ] = '\n' ;
} else {
if ( V_145 )
V_28 += F_88 ( V_25 , V_144 , NULL ) ;
V_28 += V_26 ;
if ( V_149 || V_147 )
V_28 ++ ;
}
V_145 = true ;
V_52 = V_149 ;
} while ( V_52 );
return V_28 ;
}
static int F_90 ( char T_2 * V_68 , int V_40 )
{
char * V_52 ;
struct V_24 * V_25 ;
int V_28 = 0 ;
V_52 = F_35 ( V_88 + V_150 , V_90 ) ;
if ( ! V_52 )
return - V_37 ;
while ( V_40 > 0 ) {
T_3 V_151 ;
T_3 V_152 ;
F_44 ( & V_97 ) ;
if ( V_153 < V_33 ) {
V_153 = V_33 ;
V_154 = V_32 ;
V_155 = 0 ;
V_156 = 0 ;
}
if ( V_153 == V_34 ) {
F_45 ( & V_97 ) ;
break;
}
V_152 = V_156 ;
V_25 = F_12 ( V_154 ) ;
V_151 = F_89 ( V_25 , V_155 , true , V_52 ,
V_88 + V_150 ) ;
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
F_45 ( & V_97 ) ;
if ( ! V_151 )
break;
if ( F_47 ( V_68 , V_52 + V_152 , V_151 ) ) {
if ( ! V_28 )
V_28 = - V_91 ;
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
V_52 = F_35 ( V_88 + V_150 , V_90 ) ;
if ( ! V_52 )
return - V_37 ;
F_44 ( & V_97 ) ;
if ( V_68 ) {
T_7 V_158 ;
T_7 V_69 ;
T_5 V_27 ;
enum V_48 V_104 ;
V_69 = V_35 ;
V_27 = V_36 ;
V_104 = 0 ;
while ( V_69 < V_34 ) {
struct V_24 * V_25 = F_12 ( V_27 ) ;
V_28 += F_89 ( V_25 , V_104 , true , NULL , 0 ) ;
V_104 = V_25 -> V_49 ;
V_27 = F_13 ( V_27 ) ;
V_69 ++ ;
}
V_69 = V_35 ;
V_27 = V_36 ;
V_104 = 0 ;
while ( V_28 > V_40 && V_69 < V_34 ) {
struct V_24 * V_25 = F_12 ( V_27 ) ;
V_28 -= F_89 ( V_25 , V_104 , true , NULL , 0 ) ;
V_104 = V_25 -> V_49 ;
V_27 = F_13 ( V_27 ) ;
V_69 ++ ;
}
V_158 = V_34 ;
V_28 = 0 ;
while ( V_28 >= 0 && V_69 < V_158 ) {
struct V_24 * V_25 = F_12 ( V_27 ) ;
int V_159 ;
V_159 = F_89 ( V_25 , V_104 , true , V_52 ,
V_88 + V_150 ) ;
if ( V_159 < 0 ) {
V_28 = V_159 ;
break;
}
V_27 = F_13 ( V_27 ) ;
V_69 ++ ;
V_104 = V_25 -> V_49 ;
F_45 ( & V_97 ) ;
if ( F_47 ( V_68 + V_28 , V_52 , V_159 ) )
V_28 = - V_91 ;
else
V_28 += V_159 ;
F_44 ( & V_97 ) ;
if ( V_69 < V_33 ) {
V_69 = V_33 ;
V_27 = V_32 ;
V_104 = 0 ;
}
}
}
if ( V_157 ) {
V_35 = V_34 ;
V_36 = V_31 ;
}
F_45 ( & V_97 ) ;
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
goto V_101;
switch ( type ) {
case V_162 :
break;
case V_58 :
break;
case V_163 :
error = - V_2 ;
if ( ! V_68 || V_28 < 0 )
goto V_101;
error = 0 ;
if ( ! V_28 )
goto V_101;
if ( ! F_93 ( V_164 , V_68 , V_28 ) ) {
error = - V_91 ;
goto V_101;
}
error = F_46 ( V_102 ,
V_153 != V_34 ) ;
if ( error )
goto V_101;
error = F_90 ( V_68 , V_28 ) ;
break;
case V_165 :
V_157 = true ;
case V_54 :
error = - V_2 ;
if ( ! V_68 || V_28 < 0 )
goto V_101;
error = 0 ;
if ( ! V_28 )
goto V_101;
if ( ! F_93 ( V_164 , V_68 , V_28 ) ) {
error = - V_91 ;
goto V_101;
}
error = F_91 ( V_68 , V_28 , V_157 ) ;
break;
case V_166 :
F_91 ( NULL , 0 , true ) ;
break;
case V_167 :
if ( V_160 == V_161 )
V_160 = V_130 ;
V_130 = V_168 ;
break;
case V_169 :
if ( V_160 != V_161 ) {
V_130 = V_160 ;
V_160 = V_161 ;
}
break;
case V_170 :
error = - V_2 ;
if ( V_28 < 1 || V_28 > 8 )
goto V_101;
if ( V_28 < V_168 )
V_28 = V_168 ;
V_130 = V_28 ;
V_160 = V_161 ;
error = 0 ;
break;
case V_171 :
F_44 ( & V_97 ) ;
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
enum V_48 V_104 = V_155 ;
error = 0 ;
while ( V_69 < V_34 ) {
struct V_24 * V_25 = F_12 ( V_27 ) ;
error += F_89 ( V_25 , V_104 , true , NULL , 0 ) ;
V_27 = F_13 ( V_27 ) ;
V_69 ++ ;
V_104 = V_25 -> V_49 ;
}
error -= V_156 ;
}
F_45 ( & V_97 ) ;
break;
case V_55 :
error = V_23 ;
break;
default:
error = - V_2 ;
break;
}
V_101:
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
if ( F_100 ( V_140 , V_181 ) &&
! F_85 ( V_140 , V_181 + 30 * V_134 ) )
return;
V_181 = V_140 ;
F_101 () ;
F_102 ( & V_97 ) ;
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
static void F_106 ( enum V_48 V_49 )
{
if ( V_72 . V_184 )
return;
if ( V_72 . V_28 == 0 )
return;
if ( V_72 . V_185 ) {
F_19 ( V_72 . V_46 , V_72 . V_47 , V_49 | V_186 ,
V_72 . V_50 , NULL , 0 , V_72 . V_68 , V_72 . V_28 ) ;
V_72 . V_49 = V_49 ;
V_72 . V_184 = true ;
} else {
F_19 ( V_72 . V_46 , V_72 . V_47 , V_49 , 0 ,
NULL , 0 , V_72 . V_68 , V_72 . V_28 ) ;
V_72 . V_28 = 0 ;
}
}
static bool F_107 ( int V_46 , int V_47 , const char * V_52 , T_3 V_28 )
{
if ( V_72 . V_28 && V_72 . V_184 )
return false ;
if ( V_187 || V_72 . V_28 + V_28 > sizeof( V_72 . V_68 ) ) {
F_106 ( V_73 ) ;
return false ;
}
if ( ! V_72 . V_28 ) {
V_72 . V_46 = V_46 ;
V_72 . V_47 = V_47 ;
V_72 . V_188 = V_62 ;
V_72 . V_50 = F_20 () ;
V_72 . V_49 = 0 ;
V_72 . V_185 = 0 ;
V_72 . V_184 = false ;
}
memcpy ( V_72 . V_68 + V_72 . V_28 , V_52 , V_28 ) ;
V_72 . V_28 += V_28 ;
if ( V_72 . V_28 > ( sizeof( V_72 . V_68 ) * 80 ) / 100 )
F_106 ( V_73 ) ;
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
T_10 int F_109 ( int V_46 , int V_47 ,
const char * V_51 , T_3 V_190 ,
const char * V_191 , T_11 args )
{
static bool V_192 ;
static char V_193 [ V_88 ] ;
char * V_52 = V_193 ;
T_3 V_26 = 0 ;
enum V_48 V_194 = 0 ;
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
F_110 ( V_49 ) ;
V_195 = F_98 () ;
if ( F_73 ( V_199 == V_195 ) ) {
if ( ! V_202 && ! F_111 ( V_62 ) ) {
V_192 = true ;
F_112 ( V_49 ) ;
return 0 ;
}
F_99 () ;
}
F_113 () ;
F_114 ( & V_97 ) ;
V_199 = V_195 ;
if ( F_73 ( V_192 ) ) {
static const char V_203 [] =
L_22 ;
V_192 = false ;
V_196 += F_19 ( 0 , 2 , V_74 | V_148 , 0 ,
NULL , 0 , V_203 ,
strlen ( V_203 ) ) ;
}
V_197 = F_115 () ;
if ( F_73 ( V_197 ) ) {
V_26 = F_30 ( V_193 , sizeof( V_193 ) ,
L_23 ,
V_197 ) ;
V_196 += F_19 ( 0 , 2 , V_74 | V_148 , 0 ,
NULL , 0 , V_193 , V_26 ) ;
}
V_26 = F_116 ( V_52 , sizeof( V_193 ) , V_191 , args ) ;
if ( V_26 && V_52 [ V_26 - 1 ] == '\n' ) {
V_26 -- ;
V_194 |= V_148 ;
}
if ( V_46 == 0 ) {
int V_204 = F_117 ( V_52 ) ;
if ( V_204 ) {
const char * V_205 = F_118 ( V_52 ) ;
switch ( V_204 ) {
case '0' ... '7' :
if ( V_47 == V_161 )
V_47 = V_204 - '0' ;
case 'd' :
V_194 |= V_74 ;
}
V_26 -= V_205 - V_52 ;
V_52 = ( char * ) V_205 ;
}
}
if ( V_47 == V_161 )
V_47 = V_81 ;
if ( V_51 )
V_194 |= V_74 | V_148 ;
if ( ! ( V_194 & V_148 ) ) {
if ( V_72 . V_28 && ( V_194 & V_74 || V_72 . V_188 != V_62 ) )
F_106 ( V_148 ) ;
if ( F_107 ( V_46 , V_47 , V_52 , V_26 ) )
V_196 += V_26 ;
else
V_196 += F_19 ( V_46 , V_47 ,
V_194 | V_73 , 0 ,
V_51 , V_190 , V_52 , V_26 ) ;
} else {
bool V_206 = false ;
if ( V_72 . V_28 ) {
if ( V_72 . V_188 == V_62 && ! ( V_194 & V_74 ) )
V_206 = F_107 ( V_46 , V_47 , V_52 ,
V_26 ) ;
F_106 ( V_148 ) ;
}
if ( V_206 )
V_196 += V_26 ;
else
V_196 += F_19 ( V_46 , V_47 , V_194 , 0 ,
V_51 , V_190 , V_52 , V_26 ) ;
}
V_199 = V_200 ;
F_119 ( & V_97 ) ;
F_120 () ;
F_112 ( V_49 ) ;
if ( ! V_198 ) {
F_113 () ;
if ( F_121 () )
F_122 () ;
F_120 () ;
}
return V_196 ;
}
T_10 int F_123 ( const char * V_191 , T_11 args )
{
return F_109 ( 0 , V_161 , NULL , 0 , V_191 , args ) ;
}
T_10 int F_41 ( int V_46 , int V_47 ,
const char * V_51 , T_3 V_190 ,
const char * V_191 , ... )
{
T_11 args ;
int V_207 ;
va_start ( args , V_191 ) ;
V_207 = F_109 ( V_46 , V_47 , V_51 , V_190 , V_191 , args ) ;
va_end ( args ) ;
return V_207 ;
}
int F_124 ( const char * V_191 , T_11 args )
{
int V_207 ;
#ifdef F_125
if ( F_73 ( V_208 ) ) {
V_207 = F_126 ( V_209 , V_191 , args ) ;
return V_207 ;
}
#endif
V_207 = F_109 ( 0 , V_161 , NULL , 0 , V_191 , args ) ;
return V_207 ;
}
T_10 T_12 int F_127 ( const char * V_191 , ... )
{
T_11 args ;
int V_207 ;
va_start ( args , V_191 ) ;
V_207 = F_128 ( V_191 , args ) ;
va_end ( args ) ;
return V_207 ;
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
static T_3 F_89 ( const struct V_24 * V_25 , enum V_48 V_104 ,
bool V_144 , char * V_68 , T_3 V_40 ) { return 0 ; }
static T_3 F_108 ( char * V_52 , T_3 V_40 ) { return 0 ; }
static bool F_78 ( int V_47 ) { return false ; }
T_10 T_12 void F_129 ( const char * V_191 , ... )
{
T_11 V_210 ;
char V_68 [ 512 ] ;
int V_151 ;
if ( ! V_211 )
return;
va_start ( V_210 , V_191 ) ;
V_151 = F_116 ( V_68 , sizeof( V_68 ) , V_191 , V_210 ) ;
va_end ( V_210 ) ;
V_211 -> V_12 ( V_211 , V_68 , V_151 ) ;
}
static int F_130 ( char * V_212 , int V_27 , char * V_213 ,
char * V_214 )
{
struct V_215 * V_67 ;
int V_76 ;
for ( V_76 = 0 , V_67 = V_215 ;
V_76 < V_216 && V_67 -> V_212 [ 0 ] ;
V_76 ++ , V_67 ++ ) {
if ( strcmp ( V_67 -> V_212 , V_212 ) == 0 && V_67 -> V_217 == V_27 ) {
if ( ! V_214 )
V_218 = V_76 ;
return 0 ;
}
}
if ( V_76 == V_216 )
return - V_219 ;
if ( ! V_214 )
V_218 = V_76 ;
F_131 ( V_67 -> V_212 , V_212 , sizeof( V_67 -> V_212 ) ) ;
V_67 -> V_213 = V_213 ;
F_132 ( V_67 , V_214 ) ;
V_67 -> V_217 = V_27 ;
return 0 ;
}
static int T_1 F_133 ( char * V_1 )
{
char V_68 [ sizeof( V_215 [ 0 ] . V_212 ) + 4 ] ;
char * V_220 , * V_213 , * V_214 = NULL ;
int V_27 ;
if ( F_134 ( & V_1 , & V_214 ) )
return 1 ;
if ( V_1 [ 0 ] >= '0' && V_1 [ 0 ] <= '9' ) {
strcpy ( V_68 , L_24 ) ;
strncpy ( V_68 + 4 , V_1 , sizeof( V_68 ) - 5 ) ;
} else {
strncpy ( V_68 , V_1 , sizeof( V_68 ) - 1 ) ;
}
V_68 [ sizeof( V_68 ) - 1 ] = 0 ;
V_213 = strchr ( V_1 , ',' ) ;
if ( V_213 )
* ( V_213 ++ ) = 0 ;
#ifdef F_135
if ( ! strcmp ( V_1 , L_25 ) )
strcpy ( V_68 , L_26 ) ;
if ( ! strcmp ( V_1 , L_27 ) )
strcpy ( V_68 , L_28 ) ;
#endif
for ( V_220 = V_68 ; * V_220 ; V_220 ++ )
if ( isdigit ( * V_220 ) || * V_220 == ',' )
break;
V_27 = F_38 ( V_220 , NULL , 10 ) ;
* V_220 = 0 ;
F_130 ( V_68 , V_27 , V_213 , V_214 ) ;
V_221 = 1 ;
return 1 ;
}
int F_136 ( char * V_212 , int V_27 , char * V_213 )
{
return F_130 ( V_212 , V_27 , V_213 , NULL ) ;
}
static int T_1 F_137 ( char * V_1 )
{
V_222 = false ;
return 1 ;
}
void F_138 ( void )
{
if ( ! V_222 )
return;
F_127 ( L_29 ) ;
F_139 () ;
V_223 = 1 ;
F_140 () ;
}
void F_141 ( void )
{
if ( ! V_222 )
return;
F_142 () ;
V_223 = 0 ;
F_122 () ;
}
static int F_143 ( struct V_224 * V_225 ,
unsigned long V_226 , void * V_227 )
{
switch ( V_226 ) {
case V_228 :
case V_229 :
case V_230 :
case V_231 :
F_139 () ;
F_122 () ;
}
return V_232 ;
}
void F_139 ( void )
{
F_144 () ;
F_142 () ;
if ( V_223 )
return;
V_233 = 1 ;
V_234 = 1 ;
}
int F_121 ( void )
{
if ( F_145 () )
return 0 ;
if ( V_223 ) {
F_140 () ;
return 0 ;
}
V_233 = 1 ;
V_234 = ! V_202 &&
F_146 () &&
! F_147 () ;
return 1 ;
}
int F_148 ( void )
{
return V_233 ;
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
F_75 ( & V_97 , V_49 ) ;
if ( ! V_72 . V_28 )
goto V_101;
if ( F_78 ( V_72 . V_47 ) ) {
V_72 . V_185 = V_72 . V_28 ;
if ( V_72 . V_184 )
V_72 . V_28 = 0 ;
goto V_101;
}
if ( V_235 < V_34 && ! V_72 . V_185 )
goto V_101;
V_28 = F_108 ( V_52 , V_40 ) ;
F_119 ( & V_97 ) ;
F_153 () ;
F_94 ( V_72 . V_47 , NULL , 0 , V_52 , V_28 ) ;
F_154 () ;
F_112 ( V_49 ) ;
return;
V_101:
F_76 ( & V_97 , V_49 ) ;
}
void F_122 ( void )
{
static char V_172 [ V_236 ] ;
static char V_52 [ V_88 + V_150 ] ;
static T_7 V_237 ;
unsigned long V_49 ;
bool V_238 = false ;
bool V_239 , V_240 ;
if ( V_223 ) {
F_140 () ;
return;
}
V_239 = V_234 ;
V_234 = 0 ;
V_241:
if ( ! F_150 () ) {
V_233 = 0 ;
F_140 () ;
return;
}
F_152 ( V_52 , sizeof( V_52 ) ) ;
for (; ; ) {
struct V_24 * V_25 ;
T_3 V_173 = 0 ;
T_3 V_28 ;
int V_47 ;
F_75 ( & V_97 , V_49 ) ;
if ( V_237 != V_34 ) {
V_238 = true ;
V_237 = V_34 ;
}
if ( V_235 < V_33 ) {
V_28 = sprintf ( V_52 , L_30 ,
( unsigned ) ( V_33 - V_235 ) ) ;
V_235 = V_33 ;
V_242 = V_32 ;
V_189 = 0 ;
} else {
V_28 = 0 ;
}
V_152:
if ( V_235 == V_34 )
break;
V_25 = F_12 ( V_242 ) ;
V_47 = V_25 -> V_47 ;
if ( ( V_25 -> V_49 & V_186 ) ||
F_78 ( V_47 ) ) {
V_242 = F_13 ( V_242 ) ;
V_235 ++ ;
V_25 -> V_49 &= ~ V_186 ;
V_189 = V_25 -> V_49 ;
goto V_152;
}
V_28 += F_89 ( V_25 , V_189 , false ,
V_52 + V_28 , sizeof( V_52 ) - V_28 ) ;
if ( V_187 ) {
V_173 = F_28 ( V_172 ,
sizeof( V_172 ) ,
V_25 , V_235 , V_189 ) ;
V_173 += F_31 ( V_172 + V_173 ,
sizeof( V_172 ) - V_173 ,
F_11 ( V_25 ) , V_25 -> V_38 ,
F_10 ( V_25 ) , V_25 -> V_26 ) ;
}
V_242 = F_13 ( V_242 ) ;
V_235 ++ ;
V_189 = V_25 -> V_49 ;
F_119 ( & V_97 ) ;
F_153 () ;
F_94 ( V_47 , V_172 , V_173 , V_52 , V_28 ) ;
F_154 () ;
F_112 ( V_49 ) ;
if ( V_239 )
F_155 () ;
}
V_233 = 0 ;
if ( F_73 ( V_177 ) )
V_177 = NULL ;
F_119 ( & V_97 ) ;
F_140 () ;
F_114 ( & V_97 ) ;
V_240 = V_235 != V_34 ;
F_76 ( & V_97 , V_49 ) ;
if ( V_240 && F_121 () )
goto V_241;
if ( V_238 )
F_156 () ;
}
void T_13 F_157 ( void )
{
if ( V_234 )
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
V_233 = 1 ;
V_234 = 0 ;
F_96 (c)
if ( ( V_67 -> V_49 & V_178 ) && V_67 -> V_243 )
V_67 -> V_243 () ;
F_122 () ;
}
void F_159 ( void )
{
F_121 () ;
V_234 = 0 ;
F_122 () ;
}
struct V_244 * F_160 ( int * V_217 )
{
struct V_174 * V_67 ;
struct V_244 * V_245 = NULL ;
F_139 () ;
F_96 (c) {
if ( ! V_67 -> V_246 )
continue;
V_245 = V_67 -> V_246 ( V_67 , V_217 ) ;
if ( V_245 )
break;
}
F_122 () ;
return V_245 ;
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
V_247 = 1 ;
F_69 ( L_31 ) ;
return 0 ;
}
void F_164 ( struct V_174 * V_248 )
{
int V_76 ;
unsigned long V_49 ;
struct V_174 * V_249 = NULL ;
struct V_215 * V_67 ;
if ( V_176 )
F_96 (bcon)
if ( F_165 ( V_249 == V_248 ,
L_32 ,
V_249 -> V_212 , V_249 -> V_217 ) )
return;
if ( V_176 && V_248 -> V_49 & V_250 ) {
F_96 (bcon) {
if ( ! ( V_249 -> V_49 & V_250 ) ) {
F_69 ( L_33 ,
V_248 -> V_212 , V_248 -> V_217 ) ;
return;
}
}
}
if ( V_176 && V_176 -> V_49 & V_250 )
V_249 = V_176 ;
if ( V_251 < 0 || V_249 || ! V_176 )
V_251 = V_218 ;
if ( V_251 < 0 ) {
if ( V_248 -> V_217 < 0 )
V_248 -> V_217 = 0 ;
if ( V_248 -> V_252 == NULL ||
V_248 -> V_252 ( V_248 , NULL ) == 0 ) {
V_248 -> V_49 |= V_178 ;
if ( V_248 -> V_246 ) {
V_248 -> V_49 |= V_253 ;
V_251 = 0 ;
}
}
}
for ( V_76 = 0 , V_67 = V_215 ;
V_76 < V_216 && V_67 -> V_212 [ 0 ] ;
V_76 ++ , V_67 ++ ) {
if ( ! V_248 -> V_254 ||
V_248 -> V_254 ( V_248 , V_67 -> V_212 , V_67 -> V_217 , V_67 -> V_213 ) != 0 ) {
F_166 ( sizeof( V_67 -> V_212 ) != sizeof( V_248 -> V_212 ) ) ;
if ( strcmp ( V_67 -> V_212 , V_248 -> V_212 ) != 0 )
continue;
if ( V_248 -> V_217 >= 0 &&
V_248 -> V_217 != V_67 -> V_217 )
continue;
if ( V_248 -> V_217 < 0 )
V_248 -> V_217 = V_67 -> V_217 ;
if ( F_167 ( V_248 , V_67 ) )
return;
if ( V_248 -> V_252 &&
V_248 -> V_252 ( V_248 , V_67 -> V_213 ) != 0 )
break;
}
V_248 -> V_49 |= V_178 ;
if ( V_76 == V_218 ) {
V_248 -> V_49 |= V_253 ;
V_251 = V_218 ;
}
break;
}
if ( ! ( V_248 -> V_49 & V_178 ) )
return;
if ( V_249 && ( ( V_248 -> V_49 & ( V_253 | V_250 ) ) == V_253 ) )
V_248 -> V_49 &= ~ V_255 ;
F_139 () ;
if ( ( V_248 -> V_49 & V_253 ) || V_176 == NULL ) {
V_248 -> V_149 = V_176 ;
V_176 = V_248 ;
if ( V_248 -> V_149 )
V_248 -> V_149 -> V_49 &= ~ V_253 ;
} else {
V_248 -> V_149 = V_176 -> V_149 ;
V_176 -> V_149 = V_248 ;
}
if ( V_248 -> V_49 & V_180 )
if ( ! V_187 ++ )
F_69 ( L_34 ) ;
if ( V_248 -> V_49 & V_255 ) {
F_75 ( & V_97 , V_49 ) ;
V_235 = V_153 ;
V_242 = V_154 ;
V_189 = V_155 ;
F_76 ( & V_97 , V_49 ) ;
V_177 = V_248 ;
}
F_122 () ;
F_168 () ;
F_69 ( L_35 ,
( V_248 -> V_49 & V_250 ) ? L_36 : L_37 ,
V_248 -> V_212 , V_248 -> V_217 ) ;
if ( V_249 &&
( ( V_248 -> V_49 & ( V_253 | V_250 ) ) == V_253 ) &&
! V_247 ) {
F_96 (bcon)
if ( V_249 -> V_49 & V_250 )
F_169 ( V_249 ) ;
}
}
int F_169 ( struct V_174 * V_174 )
{
struct V_174 * V_256 , * V_257 ;
int V_258 ;
F_69 ( L_38 ,
( V_174 -> V_49 & V_250 ) ? L_36 : L_37 ,
V_174 -> V_212 , V_174 -> V_217 ) ;
V_258 = F_170 ( V_174 ) ;
if ( V_258 )
return V_258 ;
V_258 = 1 ;
F_139 () ;
if ( V_176 == V_174 ) {
V_176 = V_174 -> V_149 ;
V_258 = 0 ;
} else if ( V_176 ) {
for ( V_256 = V_176 -> V_149 , V_257 = V_176 ;
V_256 ; V_257 = V_256 , V_256 = V_257 -> V_149 ) {
if ( V_256 == V_174 ) {
V_257 -> V_149 = V_256 -> V_149 ;
V_258 = 0 ;
break;
}
}
}
if ( ! V_258 && ( V_174 -> V_49 & V_180 ) )
V_187 -- ;
if ( V_176 != NULL && V_174 -> V_49 & V_253 )
V_176 -> V_49 |= V_253 ;
V_174 -> V_49 &= ~ V_178 ;
F_122 () ;
F_168 () ;
return V_258 ;
}
static int T_1 F_171 ( void )
{
struct V_174 * V_175 ;
F_96 (con) {
if ( ! V_247 && V_175 -> V_49 & V_250 ) {
if ( F_172 ( V_175 , sizeof( * V_175 ) ) )
F_169 ( V_175 ) ;
}
}
F_173 ( F_143 , 0 ) ;
return 0 ;
}
static void F_174 ( struct V_259 * V_259 )
{
int V_260 = F_175 ( V_261 , 0 ) ;
if ( V_260 & V_262 ) {
if ( F_121 () )
F_122 () ;
}
if ( V_260 & V_263 )
F_176 ( & V_102 ) ;
}
void F_156 ( void )
{
F_177 () ;
if ( F_178 ( & V_102 ) ) {
F_179 ( V_261 , V_263 ) ;
F_180 ( F_181 ( & V_264 ) ) ;
}
F_182 () ;
}
int F_183 ( const char * V_191 , ... )
{
T_11 args ;
int V_207 ;
F_177 () ;
va_start ( args , V_191 ) ;
V_207 = F_109 ( 0 , V_201 , NULL , 0 , V_191 , args ) ;
va_end ( args ) ;
F_184 ( V_261 , V_262 ) ;
F_180 ( F_181 ( & V_264 ) ) ;
F_182 () ;
return V_207 ;
}
int F_185 ( const char * V_265 )
{
return F_34 ( & V_266 , V_265 ) ;
}
bool F_186 ( unsigned long * V_267 ,
unsigned int V_268 )
{
unsigned long V_269 = V_140 - * V_267 ;
if ( * V_267 && V_269 <= F_83 ( V_268 ) )
return false ;
* V_267 = V_140 ;
return true ;
}
int F_187 ( struct V_270 * V_271 )
{
unsigned long V_49 ;
int V_18 = - V_272 ;
if ( ! V_271 -> V_273 )
return - V_2 ;
F_188 ( & V_274 , V_49 ) ;
if ( ! V_271 -> V_275 ) {
V_271 -> V_275 = 1 ;
F_189 ( & V_271 -> V_276 , & V_277 ) ;
V_18 = 0 ;
}
F_190 ( & V_274 , V_49 ) ;
return V_18 ;
}
int F_191 ( struct V_270 * V_271 )
{
unsigned long V_49 ;
int V_18 = - V_2 ;
F_188 ( & V_274 , V_49 ) ;
if ( V_271 -> V_275 ) {
V_271 -> V_275 = 0 ;
F_192 ( & V_271 -> V_276 ) ;
V_18 = 0 ;
}
F_190 ( & V_274 , V_49 ) ;
F_193 () ;
return V_18 ;
}
void F_194 ( enum V_278 V_279 )
{
struct V_270 * V_271 ;
unsigned long V_49 ;
if ( ( V_279 > V_280 ) && ! V_281 )
return;
F_195 () ;
F_196 (dumper, &dump_list, list) {
if ( V_271 -> V_282 && V_279 > V_271 -> V_282 )
continue;
V_271 -> V_283 = true ;
F_75 ( & V_97 , V_49 ) ;
V_271 -> V_284 = V_35 ;
V_271 -> V_285 = V_36 ;
V_271 -> V_158 = V_34 ;
V_271 -> V_286 = V_31 ;
F_76 ( & V_97 , V_49 ) ;
V_271 -> V_273 ( V_271 , V_279 ) ;
V_271 -> V_283 = false ;
}
F_197 () ;
}
bool F_198 ( struct V_270 * V_271 , bool V_144 ,
char * line , T_3 V_40 , T_3 * V_28 )
{
struct V_24 * V_25 ;
T_3 V_287 = 0 ;
bool V_87 = false ;
if ( ! V_271 -> V_283 )
goto V_101;
if ( V_271 -> V_284 < V_33 ) {
V_271 -> V_284 = V_33 ;
V_271 -> V_285 = V_32 ;
}
if ( V_271 -> V_284 >= V_34 )
goto V_101;
V_25 = F_12 ( V_271 -> V_285 ) ;
V_287 = F_89 ( V_25 , 0 , V_144 , line , V_40 ) ;
V_271 -> V_285 = F_13 ( V_271 -> V_285 ) ;
V_271 -> V_284 ++ ;
V_87 = true ;
V_101:
if ( V_28 )
* V_28 = V_287 ;
return V_87 ;
}
bool F_199 ( struct V_270 * V_271 , bool V_144 ,
char * line , T_3 V_40 , T_3 * V_28 )
{
unsigned long V_49 ;
bool V_87 ;
F_75 ( & V_97 , V_49 ) ;
V_87 = F_198 ( V_271 , V_144 , line , V_40 , V_28 ) ;
F_76 ( & V_97 , V_49 ) ;
return V_87 ;
}
bool F_200 ( struct V_270 * V_271 , bool V_144 ,
char * V_68 , T_3 V_40 , T_3 * V_28 )
{
unsigned long V_49 ;
T_7 V_69 ;
T_5 V_27 ;
T_7 V_158 ;
T_5 V_286 ;
enum V_48 V_104 ;
T_3 V_287 = 0 ;
bool V_87 = false ;
if ( ! V_271 -> V_283 )
goto V_101;
F_75 ( & V_97 , V_49 ) ;
if ( V_271 -> V_284 < V_33 ) {
V_271 -> V_284 = V_33 ;
V_271 -> V_285 = V_32 ;
}
if ( V_271 -> V_284 >= V_271 -> V_158 ) {
F_76 ( & V_97 , V_49 ) ;
goto V_101;
}
V_69 = V_271 -> V_284 ;
V_27 = V_271 -> V_285 ;
V_104 = 0 ;
while ( V_69 < V_271 -> V_158 ) {
struct V_24 * V_25 = F_12 ( V_27 ) ;
V_287 += F_89 ( V_25 , V_104 , true , NULL , 0 ) ;
V_27 = F_13 ( V_27 ) ;
V_69 ++ ;
V_104 = V_25 -> V_49 ;
}
V_69 = V_271 -> V_284 ;
V_27 = V_271 -> V_285 ;
V_104 = 0 ;
while ( V_287 > V_40 && V_69 < V_271 -> V_158 ) {
struct V_24 * V_25 = F_12 ( V_27 ) ;
V_287 -= F_89 ( V_25 , V_104 , true , NULL , 0 ) ;
V_27 = F_13 ( V_27 ) ;
V_69 ++ ;
V_104 = V_25 -> V_49 ;
}
V_158 = V_69 ;
V_286 = V_27 ;
V_287 = 0 ;
while ( V_69 < V_271 -> V_158 ) {
struct V_24 * V_25 = F_12 ( V_27 ) ;
V_287 += F_89 ( V_25 , V_104 , V_144 , V_68 + V_287 , V_40 - V_287 ) ;
V_27 = F_13 ( V_27 ) ;
V_69 ++ ;
V_104 = V_25 -> V_49 ;
}
V_271 -> V_158 = V_158 ;
V_271 -> V_286 = V_286 ;
V_87 = true ;
F_76 ( & V_97 , V_49 ) ;
V_101:
if ( V_28 )
* V_28 = V_287 ;
return V_87 ;
}
void F_201 ( struct V_270 * V_271 )
{
V_271 -> V_284 = V_35 ;
V_271 -> V_285 = V_36 ;
V_271 -> V_158 = V_34 ;
V_271 -> V_286 = V_31 ;
}
void F_202 ( struct V_270 * V_271 )
{
unsigned long V_49 ;
F_75 ( & V_97 , V_49 ) ;
F_201 ( V_271 ) ;
F_76 ( & V_97 , V_49 ) ;
}
void T_1 F_203 ( const char * V_191 , ... )
{
T_11 args ;
va_start ( args , V_191 ) ;
vsnprintf ( V_288 , sizeof( V_288 ) ,
V_191 , args ) ;
va_end ( args ) ;
}
void F_204 ( const char * V_289 )
{
F_127 ( L_39 ,
V_289 , F_151 () , V_62 -> V_290 , V_62 -> V_63 ,
F_205 () , F_206 () -> V_291 ,
( int ) strcspn ( F_206 () -> V_292 , L_40 ) ,
F_206 () -> V_292 ) ;
if ( V_288 [ 0 ] != '\0' )
F_127 ( L_41 ,
V_289 , V_288 ) ;
F_207 ( V_289 , V_62 ) ;
}
void F_208 ( const char * V_289 )
{
F_204 ( V_289 ) ;
F_127 ( L_42 ,
V_289 , V_62 , F_209 ( V_62 ) ) ;
}
