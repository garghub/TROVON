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
int V_20 ;
unsigned long V_21 ;
F_6 ( V_21 ) ;
V_20 = F_7 ( & V_22 ) ;
F_8 ( V_21 ) ;
if ( V_20 )
return 1 ;
F_9 ( & V_23 , 0 , 1 , V_19 ) ;
return 0 ;
}
static void F_10 ( unsigned long V_19 )
{
unsigned long V_21 ;
F_11 ( & V_23 , 1 , V_19 ) ;
F_6 ( V_21 ) ;
F_12 ( & V_22 ) ;
F_8 ( V_21 ) ;
}
char * F_13 ( void )
{
return V_24 ;
}
T_5 F_14 ( void )
{
return V_25 ;
}
static char * F_15 ( const struct V_26 * V_27 )
{
return ( char * ) V_27 + sizeof( struct V_26 ) ;
}
static char * F_16 ( const struct V_26 * V_27 )
{
return ( char * ) V_27 + sizeof( struct V_26 ) + V_27 -> V_28 ;
}
static struct V_26 * F_17 ( T_5 V_29 )
{
struct V_26 * V_27 = (struct V_26 * ) ( V_24 + V_29 ) ;
if ( ! V_27 -> V_30 )
return (struct V_26 * ) V_24 ;
return V_27 ;
}
static T_5 F_18 ( T_5 V_29 )
{
struct V_26 * V_27 = (struct V_26 * ) ( V_24 + V_29 ) ;
if ( ! V_27 -> V_30 ) {
V_27 = (struct V_26 * ) V_24 ;
return V_27 -> V_30 ;
}
return V_29 + V_27 -> V_30 ;
}
static int F_19 ( T_5 V_31 , bool V_32 )
{
T_5 free ;
if ( V_33 > V_34 || V_32 )
free = F_20 ( V_25 - V_33 , V_34 ) ;
else
free = V_34 - V_33 ;
return free >= V_31 + sizeof( struct V_26 ) ;
}
static int F_21 ( T_5 V_31 )
{
while ( V_35 < V_36 &&
! F_19 ( V_31 , false ) ) {
V_34 = F_18 ( V_34 ) ;
V_35 ++ ;
}
if ( V_37 < V_35 ) {
V_37 = V_35 ;
V_38 = V_34 ;
}
if ( F_19 ( V_31 , V_35 == V_36 ) )
return 0 ;
return - V_39 ;
}
static T_5 F_22 ( T_6 V_28 , T_6 V_40 , T_5 * V_41 )
{
T_5 V_42 ;
V_42 = sizeof( struct V_26 ) + V_28 + V_40 ;
* V_41 = ( - V_42 ) & ( V_43 - 1 ) ;
V_42 += * V_41 ;
return V_42 ;
}
static T_5 F_23 ( T_6 * V_28 , T_6 * V_44 ,
T_6 * V_40 , T_5 * V_41 )
{
T_5 V_45 = V_25 / V_46 ;
if ( * V_28 > V_45 )
* V_28 = V_45 ;
* V_44 = strlen ( V_47 ) ;
* V_40 = 0 ;
return F_22 ( * V_28 + * V_44 , 0 , V_41 ) ;
}
static int F_24 ( int V_48 , int V_49 ,
enum V_50 V_21 , T_7 V_51 ,
const char * V_52 , T_6 V_40 ,
const char * V_53 , T_6 V_28 )
{
struct V_26 * V_27 ;
T_5 V_42 , V_41 ;
T_6 V_44 = 0 ;
V_42 = F_22 ( V_28 , V_40 , & V_41 ) ;
if ( F_21 ( V_42 ) ) {
V_42 = F_23 ( & V_28 , & V_44 ,
& V_40 , & V_41 ) ;
if ( F_21 ( V_42 ) )
return 0 ;
}
if ( V_33 + V_42 + sizeof( struct V_26 ) > V_25 ) {
memset ( V_24 + V_33 , 0 , sizeof( struct V_26 ) ) ;
V_33 = 0 ;
}
V_27 = (struct V_26 * ) ( V_24 + V_33 ) ;
memcpy ( F_15 ( V_27 ) , V_53 , V_28 ) ;
V_27 -> V_28 = V_28 ;
if ( V_44 ) {
memcpy ( F_15 ( V_27 ) + V_28 , V_47 , V_44 ) ;
V_27 -> V_28 += V_44 ;
}
memcpy ( F_16 ( V_27 ) , V_52 , V_40 ) ;
V_27 -> V_40 = V_40 ;
V_27 -> V_48 = V_48 ;
V_27 -> V_49 = V_49 & 7 ;
V_27 -> V_21 = V_21 & 0x1f ;
if ( V_51 > 0 )
V_27 -> V_51 = V_51 ;
else
V_27 -> V_51 = F_25 () ;
memset ( F_16 ( V_27 ) + V_40 , 0 , V_41 ) ;
V_27 -> V_30 = V_42 ;
V_33 += V_27 -> V_30 ;
V_36 ++ ;
return V_27 -> V_28 ;
}
static int F_26 ( int type )
{
if ( V_54 )
return 1 ;
return type != V_55 &&
type != V_56 ;
}
int F_27 ( int type , int V_57 )
{
if ( V_57 == V_58 && type != V_59 )
goto V_60;
if ( F_26 ( type ) ) {
if ( F_28 ( V_61 ) )
goto V_60;
if ( F_28 ( V_62 ) ) {
F_29 ( L_4
L_5
L_6 ,
V_63 -> V_64 , F_30 ( V_63 ) ) ;
goto V_60;
}
return - V_65 ;
}
V_60:
return F_31 ( type ) ;
}
static void F_32 ( char * * V_66 , char * V_67 , char V_68 )
{
if ( * V_66 < V_67 )
* ( * V_66 ) ++ = V_68 ;
}
static T_8 F_33 ( char * V_69 , T_3 V_42 ,
struct V_26 * V_27 , T_7 V_70 )
{
T_7 V_71 = V_27 -> V_51 ;
F_34 ( V_71 , 1000 ) ;
return F_35 ( V_69 , V_42 , L_7 ,
( V_27 -> V_48 << 3 ) | V_27 -> V_49 , V_70 , V_71 ,
V_27 -> V_21 & V_72 ? 'c' : '-' ) ;
}
static T_8 F_36 ( char * V_69 , T_3 V_42 ,
char * V_52 , T_3 V_40 ,
char * V_53 , T_3 V_28 )
{
char * V_73 = V_69 , * V_67 = V_69 + V_42 ;
T_3 V_74 ;
for ( V_74 = 0 ; V_74 < V_28 ; V_74 ++ ) {
unsigned char V_68 = V_53 [ V_74 ] ;
if ( V_68 < ' ' || V_68 >= 127 || V_68 == '\\' )
V_73 += F_35 ( V_73 , V_67 - V_73 , L_8 , V_68 ) ;
else
F_32 ( & V_73 , V_67 , V_68 ) ;
}
F_32 ( & V_73 , V_67 , '\n' ) ;
if ( V_40 ) {
bool line = true ;
for ( V_74 = 0 ; V_74 < V_40 ; V_74 ++ ) {
unsigned char V_68 = V_52 [ V_74 ] ;
if ( line ) {
F_32 ( & V_73 , V_67 , ' ' ) ;
line = false ;
}
if ( V_68 == '\0' ) {
F_32 ( & V_73 , V_67 , '\n' ) ;
line = true ;
continue;
}
if ( V_68 < ' ' || V_68 >= 127 || V_68 == '\\' ) {
V_73 += F_35 ( V_73 , V_67 - V_73 , L_8 , V_68 ) ;
continue;
}
F_32 ( & V_73 , V_67 , V_68 ) ;
}
F_32 ( & V_73 , V_67 , '\n' ) ;
}
return V_73 - V_69 ;
}
static T_8 F_37 ( struct V_75 * V_76 , struct V_77 * V_78 )
{
char * V_69 , * line ;
int V_49 = V_79 ;
int V_48 = 1 ;
struct V_80 * V_80 = V_76 -> V_81 ;
struct V_82 * V_83 = V_80 -> V_84 ;
T_3 V_30 = F_38 ( V_78 ) ;
T_8 V_85 = V_30 ;
if ( ! V_83 || V_30 > V_86 )
return - V_2 ;
if ( V_3 & V_5 )
return V_30 ;
if ( ! ( V_3 & V_4 ) ) {
if ( ! F_39 ( & V_83 -> V_87 , V_63 -> V_64 ) )
return V_85 ;
}
V_69 = F_40 ( V_30 + 1 , V_88 ) ;
if ( V_69 == NULL )
return - V_39 ;
V_69 [ V_30 ] = '\0' ;
if ( ! F_41 ( V_69 , V_30 , V_78 ) ) {
F_42 ( V_69 ) ;
return - V_89 ;
}
line = V_69 ;
if ( line [ 0 ] == '<' ) {
char * V_90 = NULL ;
unsigned int V_91 ;
V_91 = F_43 ( line + 1 , & V_90 , 10 ) ;
if ( V_90 && V_90 [ 0 ] == '>' ) {
V_49 = F_44 ( V_91 ) ;
if ( F_45 ( V_91 ) != 0 )
V_48 = F_45 ( V_91 ) ;
V_90 ++ ;
V_30 -= V_90 - line ;
line = V_90 ;
}
}
F_46 ( V_48 , V_49 , NULL , 0 , L_9 , line ) ;
F_42 ( V_69 ) ;
return V_85 ;
}
static T_8 F_47 ( struct V_80 * V_80 , char T_2 * V_69 ,
T_3 V_92 , T_4 * V_15 )
{
struct V_82 * V_83 = V_80 -> V_84 ;
struct V_26 * V_27 ;
T_3 V_30 ;
T_8 V_85 ;
if ( ! V_83 )
return - V_93 ;
V_85 = F_48 ( & V_83 -> V_94 ) ;
if ( V_85 )
return V_85 ;
F_49 () ;
while ( V_83 -> V_70 == V_36 ) {
if ( V_80 -> V_95 & V_96 ) {
V_85 = - V_97 ;
F_50 () ;
goto V_98;
}
F_50 () ;
V_85 = F_51 ( V_99 ,
V_83 -> V_70 != V_36 ) ;
if ( V_85 )
goto V_98;
F_49 () ;
}
if ( V_83 -> V_70 < V_35 ) {
V_83 -> V_29 = V_34 ;
V_83 -> V_70 = V_35 ;
V_85 = - V_100 ;
F_50 () ;
goto V_98;
}
V_27 = F_17 ( V_83 -> V_29 ) ;
V_30 = F_33 ( V_83 -> V_69 , sizeof( V_83 -> V_69 ) ,
V_27 , V_83 -> V_70 ) ;
V_30 += F_36 ( V_83 -> V_69 + V_30 , sizeof( V_83 -> V_69 ) - V_30 ,
F_16 ( V_27 ) , V_27 -> V_40 ,
F_15 ( V_27 ) , V_27 -> V_28 ) ;
V_83 -> V_29 = F_18 ( V_83 -> V_29 ) ;
V_83 -> V_70 ++ ;
F_50 () ;
if ( V_30 > V_92 ) {
V_85 = - V_2 ;
goto V_98;
}
if ( F_52 ( V_69 , V_83 -> V_69 , V_30 ) ) {
V_85 = - V_89 ;
goto V_98;
}
V_85 = V_30 ;
V_98:
F_53 ( & V_83 -> V_94 ) ;
return V_85 ;
}
static T_4 F_54 ( struct V_80 * V_80 , T_4 V_101 , int V_102 )
{
struct V_82 * V_83 = V_80 -> V_84 ;
T_4 V_85 = 0 ;
if ( ! V_83 )
return - V_93 ;
if ( V_101 )
return - V_103 ;
F_49 () ;
switch ( V_102 ) {
case V_104 :
V_83 -> V_29 = V_34 ;
V_83 -> V_70 = V_35 ;
break;
case V_105 :
V_83 -> V_29 = V_38 ;
V_83 -> V_70 = V_37 ;
break;
case V_106 :
V_83 -> V_29 = V_33 ;
V_83 -> V_70 = V_36 ;
break;
default:
V_85 = - V_2 ;
}
F_50 () ;
return V_85 ;
}
static unsigned int F_55 ( struct V_80 * V_80 , T_9 * V_107 )
{
struct V_82 * V_83 = V_80 -> V_84 ;
int V_85 = 0 ;
if ( ! V_83 )
return V_108 | V_109 ;
F_56 ( V_80 , & V_99 , V_107 ) ;
F_49 () ;
if ( V_83 -> V_70 < V_36 ) {
if ( V_83 -> V_70 < V_35 )
V_85 = V_110 | V_111 | V_108 | V_112 ;
else
V_85 = V_110 | V_111 ;
}
F_50 () ;
return V_85 ;
}
static int F_57 ( struct V_113 * V_113 , struct V_80 * V_80 )
{
struct V_82 * V_83 ;
int V_18 ;
if ( V_3 & V_5 )
return - V_65 ;
if ( ( V_80 -> V_95 & V_114 ) != V_115 ) {
V_18 = F_27 ( V_55 ,
V_116 ) ;
if ( V_18 )
return V_18 ;
}
V_83 = F_40 ( sizeof( struct V_82 ) , V_88 ) ;
if ( ! V_83 )
return - V_39 ;
F_58 ( & V_83 -> V_87 ) ;
F_59 ( & V_83 -> V_87 , V_117 ) ;
F_60 ( & V_83 -> V_94 ) ;
F_49 () ;
V_83 -> V_29 = V_34 ;
V_83 -> V_70 = V_35 ;
F_50 () ;
V_80 -> V_84 = V_83 ;
return 0 ;
}
static int F_61 ( struct V_113 * V_113 , struct V_80 * V_80 )
{
struct V_82 * V_83 = V_80 -> V_84 ;
if ( ! V_83 )
return 0 ;
F_62 ( & V_83 -> V_87 ) ;
F_63 ( & V_83 -> V_94 ) ;
F_42 ( V_83 ) ;
return 0 ;
}
void F_64 ( void )
{
F_65 ( V_24 ) ;
F_65 ( V_25 ) ;
F_65 ( V_34 ) ;
F_65 ( V_38 ) ;
F_65 ( V_33 ) ;
F_66 ( V_26 ) ;
F_67 ( V_26 , V_51 ) ;
F_67 ( V_26 , V_30 ) ;
F_67 ( V_26 , V_28 ) ;
F_67 ( V_26 , V_40 ) ;
}
static void T_1 F_68 ( unsigned V_42 )
{
if ( V_42 )
V_42 = F_69 ( V_42 ) ;
if ( V_42 > V_25 )
V_118 = V_42 ;
}
static int T_1 F_70 ( char * V_1 )
{
unsigned V_42 = F_71 ( V_1 , & V_1 ) ;
F_68 ( V_42 ) ;
return 0 ;
}
static void T_1 F_72 ( void )
{
unsigned int V_119 ;
if ( F_73 () == 1 )
return;
V_119 = ( F_73 () - 1 ) * V_120 ;
if ( V_119 <= V_121 / 2 )
return;
F_74 ( L_10 ,
V_120 ) ;
F_74 ( L_11 ,
V_119 ) ;
F_74 ( L_12 , V_121 ) ;
F_68 ( V_119 + V_121 ) ;
}
static inline void F_72 ( void ) {}
void T_1 F_75 ( int V_122 )
{
unsigned long V_21 ;
char * V_123 ;
int free ;
if ( V_24 != V_124 )
return;
if ( ! V_122 && ! V_118 )
F_72 () ;
if ( ! V_118 )
return;
if ( V_122 ) {
V_123 =
F_76 ( V_118 , V_43 ) ;
} else {
V_123 = F_77 ( V_118 ,
V_43 ) ;
}
if ( F_78 ( ! V_123 ) ) {
F_79 ( L_13 ,
V_118 ) ;
return;
}
F_80 ( V_21 ) ;
V_25 = V_118 ;
V_24 = V_123 ;
V_118 = 0 ;
free = V_121 - V_33 ;
memcpy ( V_24 , V_124 , V_121 ) ;
F_81 ( V_21 ) ;
F_74 ( L_14 , V_25 ) ;
F_74 ( L_15 ,
free , ( free * 100 ) / V_121 ) ;
}
static int T_1 F_82 ( char * V_1 )
{
V_125 = true ;
F_74 ( L_16 ) ;
return 0 ;
}
static bool F_83 ( int V_49 )
{
return ( V_49 >= V_126 && ! V_125 ) ;
}
static int T_1 F_84 ( char * V_1 )
{
unsigned long V_127 ;
V_127 = V_128 ? V_128 : 1000000 ;
V_129 = ( unsigned long long ) V_127 / 1000 * V_130 ;
F_85 ( & V_1 , & V_131 ) ;
if ( V_131 > 10 * 1000 )
V_131 = 0 ;
F_86 ( L_17
L_18 ,
V_131 , V_128 , V_127 , V_130 , V_129 ) ;
return 0 ;
}
static void F_87 ( int V_49 )
{
unsigned long long V_132 ;
unsigned long V_133 ;
if ( ( V_131 == 0 || V_134 != V_135 )
|| F_83 ( V_49 ) ) {
return;
}
V_132 = ( unsigned long long ) V_129 * V_131 ;
V_133 = V_136 + F_88 ( V_131 ) ;
while ( V_132 ) {
V_132 -- ;
F_89 () ;
if ( F_90 ( V_136 , V_133 ) )
break;
F_91 () ;
}
}
static inline void F_87 ( int V_49 )
{
}
static T_3 F_92 ( T_7 V_137 , char * V_69 )
{
unsigned long V_138 ;
if ( ! V_139 )
return 0 ;
V_138 = F_34 ( V_137 , 1000000000 ) ;
if ( ! V_69 )
return snprintf ( NULL , 0 , L_19 , ( unsigned long ) V_137 ) ;
return sprintf ( V_69 , L_20 ,
( unsigned long ) V_137 , V_138 / 1000 ) ;
}
static T_3 F_93 ( const struct V_26 * V_27 , bool V_140 , char * V_69 )
{
T_3 V_30 = 0 ;
unsigned int V_141 = ( V_27 -> V_48 << 3 ) | V_27 -> V_49 ;
if ( V_140 ) {
if ( V_69 ) {
V_30 += sprintf ( V_69 , L_21 , V_141 ) ;
} else {
V_30 += 3 ;
if ( V_141 > 999 )
V_30 += 3 ;
else if ( V_141 > 99 )
V_30 += 2 ;
else if ( V_141 > 9 )
V_30 ++ ;
}
}
V_30 += F_92 ( V_27 -> V_51 , V_69 ? V_69 + V_30 : NULL ) ;
return V_30 ;
}
static T_3 F_94 ( const struct V_26 * V_27 , bool V_140 , char * V_69 , T_3 V_42 )
{
const char * V_53 = F_15 ( V_27 ) ;
T_3 V_142 = V_27 -> V_28 ;
T_3 V_30 = 0 ;
do {
const char * V_143 = memchr ( V_53 , '\n' , V_142 ) ;
T_3 V_28 ;
if ( V_143 ) {
V_28 = V_143 - V_53 ;
V_143 ++ ;
V_142 -= V_143 - V_53 ;
} else {
V_28 = V_142 ;
}
if ( V_69 ) {
if ( F_93 ( V_27 , V_140 , NULL ) +
V_28 + 1 >= V_42 - V_30 )
break;
V_30 += F_93 ( V_27 , V_140 , V_69 + V_30 ) ;
memcpy ( V_69 + V_30 , V_53 , V_28 ) ;
V_30 += V_28 ;
V_69 [ V_30 ++ ] = '\n' ;
} else {
V_30 += F_93 ( V_27 , V_140 , NULL ) ;
V_30 += V_28 ;
V_30 ++ ;
}
V_53 = V_143 ;
} while ( V_53 );
return V_30 ;
}
static int F_95 ( char T_2 * V_69 , int V_42 )
{
char * V_53 ;
struct V_26 * V_27 ;
int V_30 = 0 ;
V_53 = F_40 ( V_86 + V_144 , V_88 ) ;
if ( ! V_53 )
return - V_39 ;
while ( V_42 > 0 ) {
T_3 V_145 ;
T_3 V_146 ;
F_49 () ;
if ( V_147 < V_35 ) {
V_147 = V_35 ;
V_148 = V_34 ;
V_149 = 0 ;
}
if ( V_147 == V_36 ) {
F_50 () ;
break;
}
V_146 = V_149 ;
V_27 = F_17 ( V_148 ) ;
V_145 = F_94 ( V_27 , true , V_53 , V_86 + V_144 ) ;
if ( V_145 - V_149 <= V_42 ) {
V_148 = F_18 ( V_148 ) ;
V_147 ++ ;
V_145 -= V_149 ;
V_149 = 0 ;
} else if ( ! V_30 ) {
V_145 = V_42 ;
V_149 += V_145 ;
} else
V_145 = 0 ;
F_50 () ;
if ( ! V_145 )
break;
if ( F_52 ( V_69 , V_53 + V_146 , V_145 ) ) {
if ( ! V_30 )
V_30 = - V_89 ;
break;
}
V_30 += V_145 ;
V_42 -= V_145 ;
V_69 += V_145 ;
}
F_42 ( V_53 ) ;
return V_30 ;
}
static int F_96 ( char T_2 * V_69 , int V_42 , bool V_150 )
{
char * V_53 ;
int V_30 = 0 ;
V_53 = F_40 ( V_86 + V_144 , V_88 ) ;
if ( ! V_53 )
return - V_39 ;
F_49 () ;
if ( V_69 ) {
T_7 V_151 ;
T_7 V_70 ;
T_5 V_29 ;
V_70 = V_37 ;
V_29 = V_38 ;
while ( V_70 < V_36 ) {
struct V_26 * V_27 = F_17 ( V_29 ) ;
V_30 += F_94 ( V_27 , true , NULL , 0 ) ;
V_29 = F_18 ( V_29 ) ;
V_70 ++ ;
}
V_70 = V_37 ;
V_29 = V_38 ;
while ( V_30 > V_42 && V_70 < V_36 ) {
struct V_26 * V_27 = F_17 ( V_29 ) ;
V_30 -= F_94 ( V_27 , true , NULL , 0 ) ;
V_29 = F_18 ( V_29 ) ;
V_70 ++ ;
}
V_151 = V_36 ;
V_30 = 0 ;
while ( V_30 >= 0 && V_70 < V_151 ) {
struct V_26 * V_27 = F_17 ( V_29 ) ;
int V_152 ;
V_152 = F_94 ( V_27 , true , V_53 ,
V_86 + V_144 ) ;
if ( V_152 < 0 ) {
V_30 = V_152 ;
break;
}
V_29 = F_18 ( V_29 ) ;
V_70 ++ ;
F_50 () ;
if ( F_52 ( V_69 + V_30 , V_53 , V_152 ) )
V_30 = - V_89 ;
else
V_30 += V_152 ;
F_49 () ;
if ( V_70 < V_35 ) {
V_70 = V_35 ;
V_29 = V_34 ;
}
}
}
if ( V_150 ) {
V_37 = V_36 ;
V_38 = V_33 ;
}
F_50 () ;
F_42 ( V_53 ) ;
return V_30 ;
}
int F_97 ( int type , char T_2 * V_69 , int V_30 , int V_57 )
{
bool V_150 = false ;
static int V_153 = V_154 ;
int error ;
error = F_27 ( type , V_57 ) ;
if ( error )
goto V_98;
switch ( type ) {
case V_155 :
break;
case V_59 :
break;
case V_156 :
error = - V_2 ;
if ( ! V_69 || V_30 < 0 )
goto V_98;
error = 0 ;
if ( ! V_30 )
goto V_98;
if ( ! F_98 ( V_157 , V_69 , V_30 ) ) {
error = - V_89 ;
goto V_98;
}
error = F_51 ( V_99 ,
V_147 != V_36 ) ;
if ( error )
goto V_98;
error = F_95 ( V_69 , V_30 ) ;
break;
case V_158 :
V_150 = true ;
case V_55 :
error = - V_2 ;
if ( ! V_69 || V_30 < 0 )
goto V_98;
error = 0 ;
if ( ! V_30 )
goto V_98;
if ( ! F_98 ( V_157 , V_69 , V_30 ) ) {
error = - V_89 ;
goto V_98;
}
error = F_96 ( V_69 , V_30 , V_150 ) ;
break;
case V_159 :
F_96 ( NULL , 0 , true ) ;
break;
case V_160 :
if ( V_153 == V_154 )
V_153 = V_126 ;
V_126 = V_161 ;
break;
case V_162 :
if ( V_153 != V_154 ) {
V_126 = V_153 ;
V_153 = V_154 ;
}
break;
case V_163 :
error = - V_2 ;
if ( V_30 < 1 || V_30 > 8 )
goto V_98;
if ( V_30 < V_161 )
V_30 = V_161 ;
V_126 = V_30 ;
V_153 = V_154 ;
error = 0 ;
break;
case V_164 :
F_49 () ;
if ( V_147 < V_35 ) {
V_147 = V_35 ;
V_148 = V_34 ;
V_149 = 0 ;
}
if ( V_57 == V_58 ) {
error = V_36 - V_147 ;
} else {
T_7 V_70 = V_147 ;
T_5 V_29 = V_148 ;
error = 0 ;
while ( V_70 < V_36 ) {
struct V_26 * V_27 = F_17 ( V_29 ) ;
error += F_94 ( V_27 , true , NULL , 0 ) ;
V_29 = F_18 ( V_29 ) ;
V_70 ++ ;
}
error -= V_149 ;
}
F_50 () ;
break;
case V_56 :
error = V_25 ;
break;
default:
error = - V_2 ;
break;
}
V_98:
return error ;
}
static void F_99 ( const char * V_165 , T_3 V_166 ,
const char * V_53 , T_3 V_30 )
{
struct V_167 * V_168 ;
F_100 ( V_53 , V_30 ) ;
if ( ! V_169 )
return;
F_101 (con) {
if ( V_170 && V_168 != V_170 )
continue;
if ( ! ( V_168 -> V_21 & V_171 ) )
continue;
if ( ! V_168 -> V_12 )
continue;
if ( ! F_102 ( F_103 () ) &&
! ( V_168 -> V_21 & V_172 ) )
continue;
if ( V_168 -> V_21 & V_173 )
V_168 -> V_12 ( V_168 , V_165 , V_166 ) ;
else
V_168 -> V_12 ( V_168 , V_53 , V_30 ) ;
}
}
static inline void F_104 ( void )
{
if ( F_78 ( V_174 ) ) {
int V_175 = V_174 ;
while ( V_175 -- ) {
F_105 ( 1 ) ;
F_91 () ;
}
}
}
static void F_106 ( void )
{
if ( V_176 . V_30 == 0 )
return;
F_24 ( V_176 . V_48 , V_176 . V_49 , V_176 . V_21 , V_176 . V_51 ,
NULL , 0 , V_176 . V_69 , V_176 . V_30 ) ;
V_176 . V_30 = 0 ;
}
static bool F_107 ( int V_48 , int V_49 , enum V_50 V_21 , const char * V_53 , T_3 V_30 )
{
if ( V_177 || V_176 . V_30 + V_30 > sizeof( V_176 . V_69 ) ) {
F_106 () ;
return false ;
}
if ( ! V_176 . V_30 ) {
V_176 . V_48 = V_48 ;
V_176 . V_49 = V_49 ;
V_176 . V_178 = V_63 ;
V_176 . V_51 = F_25 () ;
V_176 . V_21 = V_21 ;
}
memcpy ( V_176 . V_69 + V_176 . V_30 , V_53 , V_30 ) ;
V_176 . V_30 += V_30 ;
if ( V_21 & V_179 ) {
V_176 . V_21 |= V_179 ;
F_106 () ;
}
if ( V_176 . V_30 > ( sizeof( V_176 . V_69 ) * 80 ) / 100 )
F_106 () ;
return true ;
}
static T_3 F_108 ( int V_48 , int V_49 , enum V_50 V_180 , const char * V_52 , T_3 V_181 , char * V_53 , T_3 V_28 )
{
if ( V_176 . V_30 ) {
if ( V_176 . V_178 == V_63 && ( V_180 & V_72 ) ) {
if ( F_107 ( V_48 , V_49 , V_180 , V_53 , V_28 ) )
return V_28 ;
}
F_106 () ;
}
if ( ! V_28 && ( V_180 & V_72 ) )
return 0 ;
if ( ! ( V_180 & V_179 ) ) {
if ( F_107 ( V_48 , V_49 , V_180 , V_53 , V_28 ) )
return V_28 ;
}
return F_24 ( V_48 , V_49 , V_180 , 0 , V_52 , V_181 , V_53 , V_28 ) ;
}
T_10 int F_109 ( int V_48 , int V_49 ,
const char * V_52 , T_3 V_181 ,
const char * V_182 , T_11 args )
{
static char V_183 [ V_86 ] ;
char * V_53 = V_183 ;
T_3 V_28 = 0 ;
enum V_50 V_180 = 0 ;
unsigned long V_21 ;
int V_184 = 0 ;
bool V_185 = false ;
if ( V_49 == V_186 ) {
V_49 = V_154 ;
V_185 = true ;
}
F_87 ( V_49 ) ;
F_104 () ;
F_80 ( V_21 ) ;
V_28 = F_110 ( V_53 , sizeof( V_183 ) , V_182 , args ) ;
if ( V_28 && V_53 [ V_28 - 1 ] == '\n' ) {
V_28 -- ;
V_180 |= V_179 ;
}
if ( V_48 == 0 ) {
int V_187 ;
while ( ( V_187 = F_111 ( V_53 ) ) != 0 ) {
switch ( V_187 ) {
case '0' ... '7' :
if ( V_49 == V_154 )
V_49 = V_187 - '0' ;
case 'd' :
V_180 |= V_188 ;
break;
case 'c' :
V_180 |= V_72 ;
}
V_28 -= 2 ;
V_53 += 2 ;
}
}
if ( V_49 == V_154 )
V_49 = V_79 ;
if ( V_52 )
V_180 |= V_188 | V_179 ;
V_184 += F_108 ( V_48 , V_49 , V_180 , V_52 , V_181 , V_53 , V_28 ) ;
F_81 ( V_21 ) ;
if ( ! V_185 ) {
if ( F_112 () )
F_113 () ;
}
return V_184 ;
}
T_10 int F_114 ( const char * V_182 , T_11 args )
{
return F_115 ( V_182 , args ) ;
}
T_10 int F_46 ( int V_48 , int V_49 ,
const char * V_52 , T_3 V_181 ,
const char * V_182 , ... )
{
T_11 args ;
int V_189 ;
va_start ( args , V_182 ) ;
V_189 = F_109 ( V_48 , V_49 , V_52 , V_181 , V_182 , args ) ;
va_end ( args ) ;
return V_189 ;
}
int F_116 ( const char * V_182 , T_11 args )
{
int V_189 ;
#ifdef F_117
if ( F_78 ( V_190 && V_191 < 0 ) ) {
V_189 = F_118 ( V_192 , V_182 , args ) ;
return V_189 ;
}
#endif
V_189 = F_109 ( 0 , V_154 , NULL , 0 , V_182 , args ) ;
return V_189 ;
}
T_10 T_12 int F_119 ( const char * V_182 , ... )
{
T_11 args ;
int V_189 ;
va_start ( args , V_182 ) ;
V_189 = F_115 ( V_182 , args ) ;
va_end ( args ) ;
return V_189 ;
}
static char * F_15 ( const struct V_26 * V_27 ) { return NULL ; }
static char * F_16 ( const struct V_26 * V_27 ) { return NULL ; }
static struct V_26 * F_17 ( T_5 V_29 ) { return NULL ; }
static T_5 F_18 ( T_5 V_29 ) { return 0 ; }
static T_8 F_33 ( char * V_69 , T_3 V_42 ,
struct V_26 * V_27 ,
T_7 V_70 ) { return 0 ; }
static T_8 F_36 ( char * V_69 , T_3 V_42 ,
char * V_52 , T_3 V_40 ,
char * V_53 , T_3 V_28 ) { return 0 ; }
static void F_99 ( const char * V_165 , T_3 V_166 ,
const char * V_53 , T_3 V_30 ) {}
static T_3 F_94 ( const struct V_26 * V_27 ,
bool V_140 , char * V_69 , T_3 V_42 ) { return 0 ; }
static bool F_83 ( int V_49 ) { return false ; }
T_10 T_12 void F_120 ( const char * V_182 , ... )
{
T_11 V_193 ;
char V_69 [ 512 ] ;
int V_145 ;
if ( ! V_194 )
return;
va_start ( V_193 , V_182 ) ;
V_145 = F_110 ( V_69 , sizeof( V_69 ) , V_182 , V_193 ) ;
va_end ( V_193 ) ;
V_194 -> V_12 ( V_194 , V_69 , V_145 ) ;
}
static int F_121 ( char * V_195 , int V_29 , char * V_196 ,
char * V_197 )
{
struct V_198 * V_68 ;
int V_74 ;
for ( V_74 = 0 , V_68 = V_198 ;
V_74 < V_199 && V_68 -> V_195 [ 0 ] ;
V_74 ++ , V_68 ++ ) {
if ( strcmp ( V_68 -> V_195 , V_195 ) == 0 && V_68 -> V_200 == V_29 ) {
if ( ! V_197 )
V_201 = V_74 ;
return 0 ;
}
}
if ( V_74 == V_199 )
return - V_202 ;
if ( ! V_197 )
V_201 = V_74 ;
F_122 ( V_68 -> V_195 , V_195 , sizeof( V_68 -> V_195 ) ) ;
V_68 -> V_196 = V_196 ;
F_123 ( V_68 , V_197 ) ;
V_68 -> V_200 = V_29 ;
return 0 ;
}
static int T_1 F_124 ( char * V_1 )
{
char V_69 [ sizeof( V_198 [ 0 ] . V_195 ) + 4 ] ;
char * V_203 , * V_196 , * V_197 = NULL ;
int V_29 ;
if ( F_125 ( & V_1 , & V_197 ) )
return 1 ;
if ( V_1 [ 0 ] >= '0' && V_1 [ 0 ] <= '9' ) {
strcpy ( V_69 , L_22 ) ;
strncpy ( V_69 + 4 , V_1 , sizeof( V_69 ) - 5 ) ;
} else {
strncpy ( V_69 , V_1 , sizeof( V_69 ) - 1 ) ;
}
V_69 [ sizeof( V_69 ) - 1 ] = 0 ;
V_196 = strchr ( V_1 , ',' ) ;
if ( V_196 )
* ( V_196 ++ ) = 0 ;
#ifdef F_126
if ( ! strcmp ( V_1 , L_23 ) )
strcpy ( V_69 , L_24 ) ;
if ( ! strcmp ( V_1 , L_25 ) )
strcpy ( V_69 , L_26 ) ;
#endif
for ( V_203 = V_69 ; * V_203 ; V_203 ++ )
if ( isdigit ( * V_203 ) || * V_203 == ',' )
break;
V_29 = F_43 ( V_203 , NULL , 10 ) ;
* V_203 = 0 ;
F_121 ( V_69 , V_29 , V_196 , V_197 ) ;
V_204 = 1 ;
return 1 ;
}
int F_127 ( char * V_195 , int V_29 , char * V_196 )
{
return F_121 ( V_195 , V_29 , V_196 , NULL ) ;
}
static int T_1 F_128 ( char * V_1 )
{
V_205 = false ;
return 1 ;
}
void F_129 ( void )
{
if ( ! V_205 )
return;
F_119 ( L_27 ) ;
F_130 () ;
V_206 = 1 ;
F_131 () ;
}
void F_132 ( void )
{
if ( ! V_205 )
return;
F_133 () ;
V_206 = 0 ;
F_113 () ;
}
static int F_134 ( unsigned int V_207 )
{
if ( ! V_208 ) {
if ( F_112 () )
F_113 () ;
}
return 0 ;
}
void F_130 ( void )
{
F_135 () ;
F_133 () ;
if ( V_206 )
return;
V_209 = 1 ;
V_210 = 1 ;
}
int F_112 ( void )
{
if ( F_136 () )
return 0 ;
if ( V_206 ) {
F_131 () ;
return 0 ;
}
V_209 = 1 ;
V_210 = ! V_211 &&
F_137 () &&
! F_138 () ;
return 1 ;
}
int F_139 ( void )
{
return V_209 ;
}
static int F_140 ( void )
{
struct V_167 * V_168 ;
F_101 (con)
if ( ( V_168 -> V_21 & V_171 ) &&
( V_168 -> V_21 & V_172 ) )
return 1 ;
return 0 ;
}
static inline int F_141 ( void )
{
return F_102 ( F_142 () ) || F_140 () ;
}
void F_113 ( void )
{
static char V_165 [ V_212 ] ;
static char V_53 [ V_86 + V_144 ] ;
static T_7 V_213 ;
unsigned long V_21 ;
bool V_214 = false ;
bool V_215 , V_216 ;
if ( V_206 ) {
F_131 () ;
return;
}
V_215 = V_210 ;
V_217:
V_210 = 0 ;
if ( ! F_141 () ) {
V_209 = 0 ;
F_131 () ;
return;
}
for (; ; ) {
struct V_26 * V_27 ;
T_3 V_166 = 0 ;
T_3 V_30 ;
F_6 ( V_21 ) ;
F_143 ( & V_218 ) ;
if ( V_213 != V_36 ) {
V_214 = true ;
V_213 = V_36 ;
}
if ( V_219 < V_35 ) {
V_30 = sprintf ( V_53 , L_28 ,
( unsigned ) ( V_35 - V_219 ) ) ;
V_219 = V_35 ;
V_220 = V_34 ;
} else {
V_30 = 0 ;
}
V_146:
if ( V_219 == V_36 )
break;
V_27 = F_17 ( V_220 ) ;
if ( F_83 ( V_27 -> V_49 ) ) {
V_220 = F_18 ( V_220 ) ;
V_219 ++ ;
goto V_146;
}
V_30 += F_94 ( V_27 , false , V_53 + V_30 , sizeof( V_53 ) - V_30 ) ;
if ( V_177 ) {
V_166 = F_33 ( V_165 ,
sizeof( V_165 ) ,
V_27 , V_219 ) ;
V_166 += F_36 ( V_165 + V_166 ,
sizeof( V_165 ) - V_166 ,
F_16 ( V_27 ) , V_27 -> V_40 ,
F_15 ( V_27 ) , V_27 -> V_28 ) ;
}
V_220 = F_18 ( V_220 ) ;
V_219 ++ ;
F_144 ( & V_218 ) ;
F_145 () ;
F_99 ( V_165 , V_166 , V_53 , V_30 ) ;
F_146 () ;
F_8 ( V_21 ) ;
if ( V_215 )
F_147 () ;
}
V_209 = 0 ;
if ( F_78 ( V_170 ) )
V_170 = NULL ;
F_144 ( & V_218 ) ;
F_131 () ;
F_143 ( & V_218 ) ;
V_216 = V_219 != V_36 ;
F_144 ( & V_218 ) ;
F_8 ( V_21 ) ;
if ( V_216 && F_112 () )
goto V_217;
if ( V_214 )
F_148 () ;
}
void T_13 F_149 ( void )
{
if ( V_210 )
F_147 () ;
}
void F_150 ( void )
{
struct V_167 * V_68 ;
if ( V_211 ) {
if ( F_136 () != 0 )
return;
} else
F_130 () ;
V_209 = 1 ;
V_210 = 0 ;
F_101 (c)
if ( ( V_68 -> V_21 & V_171 ) && V_68 -> V_221 )
V_68 -> V_221 () ;
F_113 () ;
}
void F_151 ( void )
{
F_112 () ;
V_210 = 0 ;
F_113 () ;
}
struct V_222 * F_152 ( int * V_200 )
{
struct V_167 * V_68 ;
struct V_222 * V_223 = NULL ;
F_130 () ;
F_101 (c) {
if ( ! V_68 -> V_224 )
continue;
V_223 = V_68 -> V_224 ( V_68 , V_200 ) ;
if ( V_223 )
break;
}
F_113 () ;
return V_223 ;
}
void F_153 ( struct V_167 * V_167 )
{
F_130 () ;
V_167 -> V_21 &= ~ V_171 ;
F_113 () ;
}
void F_154 ( struct V_167 * V_167 )
{
F_130 () ;
V_167 -> V_21 |= V_171 ;
F_113 () ;
}
static int T_1 F_155 ( char * V_1 )
{
V_225 = 1 ;
F_74 ( L_29 ) ;
return 0 ;
}
void F_156 ( struct V_167 * V_226 )
{
int V_74 ;
unsigned long V_21 ;
struct V_167 * V_227 = NULL ;
struct V_198 * V_68 ;
static bool V_228 ;
if ( V_169 )
F_101 (bcon)
if ( F_157 ( V_227 == V_226 ,
L_30 ,
V_227 -> V_195 , V_227 -> V_200 ) )
return;
if ( V_169 && V_226 -> V_21 & V_229 ) {
F_101 (bcon) {
if ( ! ( V_227 -> V_21 & V_229 ) ) {
F_74 ( L_31 ,
V_226 -> V_195 , V_226 -> V_200 ) ;
return;
}
}
}
if ( V_169 && V_169 -> V_21 & V_229 )
V_227 = V_169 ;
if ( ! V_228 || V_227 || ! V_169 )
V_228 = V_201 >= 0 ;
if ( ! V_228 ) {
if ( V_226 -> V_200 < 0 )
V_226 -> V_200 = 0 ;
if ( V_226 -> V_230 == NULL ||
V_226 -> V_230 ( V_226 , NULL ) == 0 ) {
V_226 -> V_21 |= V_171 ;
if ( V_226 -> V_224 ) {
V_226 -> V_21 |= V_231 ;
V_228 = true ;
}
}
}
for ( V_74 = 0 , V_68 = V_198 ;
V_74 < V_199 && V_68 -> V_195 [ 0 ] ;
V_74 ++ , V_68 ++ ) {
if ( ! V_226 -> V_232 ||
V_226 -> V_232 ( V_226 , V_68 -> V_195 , V_68 -> V_200 , V_68 -> V_196 ) != 0 ) {
F_158 ( sizeof( V_68 -> V_195 ) != sizeof( V_226 -> V_195 ) ) ;
if ( strcmp ( V_68 -> V_195 , V_226 -> V_195 ) != 0 )
continue;
if ( V_226 -> V_200 >= 0 &&
V_226 -> V_200 != V_68 -> V_200 )
continue;
if ( V_226 -> V_200 < 0 )
V_226 -> V_200 = V_68 -> V_200 ;
if ( F_159 ( V_226 , V_68 ) )
return;
if ( V_226 -> V_230 &&
V_226 -> V_230 ( V_226 , V_68 -> V_196 ) != 0 )
break;
}
V_226 -> V_21 |= V_171 ;
if ( V_74 == V_201 ) {
V_226 -> V_21 |= V_231 ;
V_228 = true ;
}
break;
}
if ( ! ( V_226 -> V_21 & V_171 ) )
return;
if ( V_227 && ( ( V_226 -> V_21 & ( V_231 | V_229 ) ) == V_231 ) )
V_226 -> V_21 &= ~ V_233 ;
F_130 () ;
if ( ( V_226 -> V_21 & V_231 ) || V_169 == NULL ) {
V_226 -> V_143 = V_169 ;
V_169 = V_226 ;
if ( V_226 -> V_143 )
V_226 -> V_143 -> V_21 &= ~ V_231 ;
} else {
V_226 -> V_143 = V_169 -> V_143 ;
V_169 -> V_143 = V_226 ;
}
if ( V_226 -> V_21 & V_173 )
if ( ! V_177 ++ )
F_74 ( L_32 ) ;
if ( V_226 -> V_21 & V_233 ) {
F_80 ( V_21 ) ;
V_219 = V_147 ;
V_220 = V_148 ;
F_81 ( V_21 ) ;
V_170 = V_226 ;
}
F_113 () ;
F_160 () ;
F_74 ( L_33 ,
( V_226 -> V_21 & V_229 ) ? L_34 : L_35 ,
V_226 -> V_195 , V_226 -> V_200 ) ;
if ( V_227 &&
( ( V_226 -> V_21 & ( V_231 | V_229 ) ) == V_231 ) &&
! V_225 ) {
F_101 (bcon)
if ( V_227 -> V_21 & V_229 )
F_161 ( V_227 ) ;
}
}
int F_161 ( struct V_167 * V_167 )
{
struct V_167 * V_234 , * V_235 ;
int V_236 ;
F_74 ( L_36 ,
( V_167 -> V_21 & V_229 ) ? L_34 : L_35 ,
V_167 -> V_195 , V_167 -> V_200 ) ;
V_236 = F_162 ( V_167 ) ;
if ( V_236 )
return V_236 ;
V_236 = 1 ;
F_130 () ;
if ( V_169 == V_167 ) {
V_169 = V_167 -> V_143 ;
V_236 = 0 ;
} else if ( V_169 ) {
for ( V_234 = V_169 -> V_143 , V_235 = V_169 ;
V_234 ; V_235 = V_234 , V_234 = V_235 -> V_143 ) {
if ( V_234 == V_167 ) {
V_235 -> V_143 = V_234 -> V_143 ;
V_236 = 0 ;
break;
}
}
}
if ( ! V_236 && ( V_167 -> V_21 & V_173 ) )
V_177 -- ;
if ( V_169 != NULL && V_167 -> V_21 & V_231 )
V_169 -> V_21 |= V_231 ;
V_167 -> V_21 &= ~ V_171 ;
F_113 () ;
F_160 () ;
return V_236 ;
}
void T_1 F_163 ( void )
{
T_14 * V_237 ;
F_164 () ;
V_237 = V_238 ;
while ( V_237 < V_239 ) {
(* V_237)() ;
V_237 ++ ;
}
}
static int T_1 F_165 ( void )
{
struct V_167 * V_168 ;
int V_85 ;
F_101 (con) {
if ( ! V_225 && V_168 -> V_21 & V_229 ) {
if ( F_166 ( V_168 , sizeof( * V_168 ) ) )
F_161 ( V_168 ) ;
}
}
V_85 = F_167 ( V_240 , L_37 , NULL ,
F_134 ) ;
F_168 ( V_85 < 0 ) ;
V_85 = F_167 ( V_241 , L_38 ,
F_134 , NULL ) ;
F_168 ( V_85 < 0 ) ;
return 0 ;
}
static void F_169 ( struct V_242 * V_242 )
{
int V_243 = F_170 ( V_244 , 0 ) ;
if ( V_243 & V_245 ) {
if ( F_112 () )
F_113 () ;
}
if ( V_243 & V_246 )
F_171 ( & V_99 ) ;
}
void F_148 ( void )
{
F_172 () ;
if ( F_173 ( & V_99 ) ) {
F_174 ( V_244 , V_246 ) ;
F_175 ( F_176 ( & V_247 ) ) ;
}
F_177 () ;
}
int F_178 ( const char * V_182 , ... )
{
T_11 args ;
int V_189 ;
F_172 () ;
va_start ( args , V_182 ) ;
V_189 = F_109 ( 0 , V_186 , NULL , 0 , V_182 , args ) ;
va_end ( args ) ;
F_179 ( V_244 , V_245 ) ;
F_175 ( F_176 ( & V_247 ) ) ;
F_177 () ;
return V_189 ;
}
int F_180 ( const char * V_248 )
{
return F_39 ( & V_249 , V_248 ) ;
}
bool F_181 ( unsigned long * V_250 ,
unsigned int V_251 )
{
unsigned long V_252 = V_136 - * V_250 ;
if ( * V_250 && V_252 <= F_88 ( V_251 ) )
return false ;
* V_250 = V_136 ;
return true ;
}
int F_182 ( struct V_253 * V_254 )
{
unsigned long V_21 ;
int V_18 = - V_255 ;
if ( ! V_254 -> V_256 )
return - V_2 ;
F_183 ( & V_257 , V_21 ) ;
if ( ! V_254 -> V_258 ) {
V_254 -> V_258 = 1 ;
F_184 ( & V_254 -> V_259 , & V_260 ) ;
V_18 = 0 ;
}
F_185 ( & V_257 , V_21 ) ;
return V_18 ;
}
int F_186 ( struct V_253 * V_254 )
{
unsigned long V_21 ;
int V_18 = - V_2 ;
F_183 ( & V_257 , V_21 ) ;
if ( V_254 -> V_258 ) {
V_254 -> V_258 = 0 ;
F_187 ( & V_254 -> V_259 ) ;
V_18 = 0 ;
}
F_185 ( & V_257 , V_21 ) ;
F_188 () ;
return V_18 ;
}
void F_189 ( enum V_261 V_262 )
{
struct V_253 * V_254 ;
unsigned long V_21 ;
if ( ( V_262 > V_263 ) && ! V_264 )
return;
F_190 () ;
F_191 (dumper, &dump_list, list) {
if ( V_254 -> V_265 && V_262 > V_254 -> V_265 )
continue;
V_254 -> V_266 = true ;
F_80 ( V_21 ) ;
V_254 -> V_267 = V_37 ;
V_254 -> V_268 = V_38 ;
V_254 -> V_151 = V_36 ;
V_254 -> V_269 = V_33 ;
F_81 ( V_21 ) ;
V_254 -> V_256 ( V_254 , V_262 ) ;
V_254 -> V_266 = false ;
}
F_192 () ;
}
bool F_193 ( struct V_253 * V_254 , bool V_140 ,
char * line , T_3 V_42 , T_3 * V_30 )
{
struct V_26 * V_27 ;
T_3 V_270 = 0 ;
bool V_85 = false ;
if ( ! V_254 -> V_266 )
goto V_98;
if ( V_254 -> V_267 < V_35 ) {
V_254 -> V_267 = V_35 ;
V_254 -> V_268 = V_34 ;
}
if ( V_254 -> V_267 >= V_36 )
goto V_98;
V_27 = F_17 ( V_254 -> V_268 ) ;
V_270 = F_94 ( V_27 , V_140 , line , V_42 ) ;
V_254 -> V_268 = F_18 ( V_254 -> V_268 ) ;
V_254 -> V_267 ++ ;
V_85 = true ;
V_98:
if ( V_30 )
* V_30 = V_270 ;
return V_85 ;
}
bool F_194 ( struct V_253 * V_254 , bool V_140 ,
char * line , T_3 V_42 , T_3 * V_30 )
{
unsigned long V_21 ;
bool V_85 ;
F_80 ( V_21 ) ;
V_85 = F_193 ( V_254 , V_140 , line , V_42 , V_30 ) ;
F_81 ( V_21 ) ;
return V_85 ;
}
bool F_195 ( struct V_253 * V_254 , bool V_140 ,
char * V_69 , T_3 V_42 , T_3 * V_30 )
{
unsigned long V_21 ;
T_7 V_70 ;
T_5 V_29 ;
T_7 V_151 ;
T_5 V_269 ;
T_3 V_270 = 0 ;
bool V_85 = false ;
if ( ! V_254 -> V_266 )
goto V_98;
F_80 ( V_21 ) ;
if ( V_254 -> V_267 < V_35 ) {
V_254 -> V_267 = V_35 ;
V_254 -> V_268 = V_34 ;
}
if ( V_254 -> V_267 >= V_254 -> V_151 ) {
F_81 ( V_21 ) ;
goto V_98;
}
V_70 = V_254 -> V_267 ;
V_29 = V_254 -> V_268 ;
while ( V_70 < V_254 -> V_151 ) {
struct V_26 * V_27 = F_17 ( V_29 ) ;
V_270 += F_94 ( V_27 , true , NULL , 0 ) ;
V_29 = F_18 ( V_29 ) ;
V_70 ++ ;
}
V_70 = V_254 -> V_267 ;
V_29 = V_254 -> V_268 ;
while ( V_270 > V_42 && V_70 < V_254 -> V_151 ) {
struct V_26 * V_27 = F_17 ( V_29 ) ;
V_270 -= F_94 ( V_27 , true , NULL , 0 ) ;
V_29 = F_18 ( V_29 ) ;
V_70 ++ ;
}
V_151 = V_70 ;
V_269 = V_29 ;
V_270 = 0 ;
while ( V_70 < V_254 -> V_151 ) {
struct V_26 * V_27 = F_17 ( V_29 ) ;
V_270 += F_94 ( V_27 , V_140 , V_69 + V_270 , V_42 - V_270 ) ;
V_29 = F_18 ( V_29 ) ;
V_70 ++ ;
}
V_254 -> V_151 = V_151 ;
V_254 -> V_269 = V_269 ;
V_85 = true ;
F_81 ( V_21 ) ;
V_98:
if ( V_30 )
* V_30 = V_270 ;
return V_85 ;
}
void F_196 ( struct V_253 * V_254 )
{
V_254 -> V_267 = V_37 ;
V_254 -> V_268 = V_38 ;
V_254 -> V_151 = V_36 ;
V_254 -> V_269 = V_33 ;
}
void F_197 ( struct V_253 * V_254 )
{
unsigned long V_21 ;
F_80 ( V_21 ) ;
F_196 ( V_254 ) ;
F_81 ( V_21 ) ;
}
void T_1 F_198 ( const char * V_182 , ... )
{
T_11 args ;
va_start ( args , V_182 ) ;
vsnprintf ( V_271 , sizeof( V_271 ) ,
V_182 , args ) ;
va_end ( args ) ;
}
void F_199 ( const char * V_272 )
{
F_119 ( L_39 ,
V_272 , F_142 () , V_63 -> V_273 , V_63 -> V_64 ,
F_200 () , F_201 () -> V_274 ,
( int ) strcspn ( F_201 () -> V_275 , L_40 ) ,
F_201 () -> V_275 ) ;
if ( V_271 [ 0 ] != '\0' )
F_119 ( L_41 ,
V_272 , V_271 ) ;
F_202 ( V_272 , V_63 ) ;
}
void F_203 ( const char * V_272 )
{
F_199 ( V_272 ) ;
F_119 ( L_42 ,
V_272 , V_63 , F_204 ( V_63 ) ) ;
}
