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
struct V_24 * V_25 , T_7 V_69 )
{
T_7 V_70 = V_25 -> V_50 ;
F_29 ( V_70 , 1000 ) ;
return F_30 ( V_68 , V_40 , L_7 ,
( V_25 -> V_46 << 3 ) | V_25 -> V_47 , V_69 , V_70 ,
V_25 -> V_49 & V_71 ? 'c' : '-' ) ;
}
static T_8 F_31 ( char * V_68 , T_3 V_40 ,
char * V_51 , T_3 V_38 ,
char * V_52 , T_3 V_26 )
{
char * V_72 = V_68 , * V_66 = V_68 + V_40 ;
T_3 V_73 ;
for ( V_73 = 0 ; V_73 < V_26 ; V_73 ++ ) {
unsigned char V_67 = V_52 [ V_73 ] ;
if ( V_67 < ' ' || V_67 >= 127 || V_67 == '\\' )
V_72 += F_30 ( V_72 , V_66 - V_72 , L_8 , V_67 ) ;
else
F_27 ( & V_72 , V_66 , V_67 ) ;
}
F_27 ( & V_72 , V_66 , '\n' ) ;
if ( V_38 ) {
bool line = true ;
for ( V_73 = 0 ; V_73 < V_38 ; V_73 ++ ) {
unsigned char V_67 = V_51 [ V_73 ] ;
if ( line ) {
F_27 ( & V_72 , V_66 , ' ' ) ;
line = false ;
}
if ( V_67 == '\0' ) {
F_27 ( & V_72 , V_66 , '\n' ) ;
line = true ;
continue;
}
if ( V_67 < ' ' || V_67 >= 127 || V_67 == '\\' ) {
V_72 += F_30 ( V_72 , V_66 - V_72 , L_8 , V_67 ) ;
continue;
}
F_27 ( & V_72 , V_66 , V_67 ) ;
}
F_27 ( & V_72 , V_66 , '\n' ) ;
}
return V_72 - V_68 ;
}
static T_8 F_32 ( struct V_74 * V_75 , struct V_76 * V_77 )
{
char * V_68 , * line ;
int V_47 = V_78 ;
int V_46 = 1 ;
struct V_79 * V_79 = V_75 -> V_80 ;
struct V_81 * V_82 = V_79 -> V_83 ;
T_3 V_28 = F_33 ( V_77 ) ;
T_8 V_84 = V_28 ;
if ( ! V_82 || V_28 > V_85 )
return - V_2 ;
if ( V_3 & V_5 )
return V_28 ;
if ( ! ( V_3 & V_4 ) ) {
if ( ! F_34 ( & V_82 -> V_86 , V_62 -> V_63 ) )
return V_84 ;
}
V_68 = F_35 ( V_28 + 1 , V_87 ) ;
if ( V_68 == NULL )
return - V_37 ;
V_68 [ V_28 ] = '\0' ;
if ( ! F_36 ( V_68 , V_28 , V_77 ) ) {
F_37 ( V_68 ) ;
return - V_88 ;
}
line = V_68 ;
if ( line [ 0 ] == '<' ) {
char * V_89 = NULL ;
unsigned int V_90 ;
V_90 = F_38 ( line + 1 , & V_89 , 10 ) ;
if ( V_89 && V_89 [ 0 ] == '>' ) {
V_47 = F_39 ( V_90 ) ;
if ( F_40 ( V_90 ) != 0 )
V_46 = F_40 ( V_90 ) ;
V_89 ++ ;
V_28 -= V_89 - line ;
line = V_89 ;
}
}
F_41 ( V_46 , V_47 , NULL , 0 , L_9 , line ) ;
F_37 ( V_68 ) ;
return V_84 ;
}
static T_8 F_42 ( struct V_79 * V_79 , char T_2 * V_68 ,
T_3 V_91 , T_4 * V_15 )
{
struct V_81 * V_82 = V_79 -> V_83 ;
struct V_24 * V_25 ;
T_3 V_28 ;
T_8 V_84 ;
if ( ! V_82 )
return - V_92 ;
V_84 = F_43 ( & V_82 -> V_93 ) ;
if ( V_84 )
return V_84 ;
F_44 ( & V_94 ) ;
while ( V_82 -> V_69 == V_34 ) {
if ( V_79 -> V_95 & V_96 ) {
V_84 = - V_97 ;
F_45 ( & V_94 ) ;
goto V_98;
}
F_45 ( & V_94 ) ;
V_84 = F_46 ( V_99 ,
V_82 -> V_69 != V_34 ) ;
if ( V_84 )
goto V_98;
F_44 ( & V_94 ) ;
}
if ( V_82 -> V_69 < V_33 ) {
V_82 -> V_27 = V_32 ;
V_82 -> V_69 = V_33 ;
V_84 = - V_100 ;
F_45 ( & V_94 ) ;
goto V_98;
}
V_25 = F_12 ( V_82 -> V_27 ) ;
V_28 = F_28 ( V_82 -> V_68 , sizeof( V_82 -> V_68 ) ,
V_25 , V_82 -> V_69 ) ;
V_28 += F_31 ( V_82 -> V_68 + V_28 , sizeof( V_82 -> V_68 ) - V_28 ,
F_11 ( V_25 ) , V_25 -> V_38 ,
F_10 ( V_25 ) , V_25 -> V_26 ) ;
V_82 -> V_27 = F_13 ( V_82 -> V_27 ) ;
V_82 -> V_69 ++ ;
F_45 ( & V_94 ) ;
if ( V_28 > V_91 ) {
V_84 = - V_2 ;
goto V_98;
}
if ( F_47 ( V_68 , V_82 -> V_68 , V_28 ) ) {
V_84 = - V_88 ;
goto V_98;
}
V_84 = V_28 ;
V_98:
F_48 ( & V_82 -> V_93 ) ;
return V_84 ;
}
static T_4 F_49 ( struct V_79 * V_79 , T_4 V_101 , int V_102 )
{
struct V_81 * V_82 = V_79 -> V_83 ;
T_4 V_84 = 0 ;
if ( ! V_82 )
return - V_92 ;
if ( V_101 )
return - V_103 ;
F_44 ( & V_94 ) ;
switch ( V_102 ) {
case V_104 :
V_82 -> V_27 = V_32 ;
V_82 -> V_69 = V_33 ;
break;
case V_105 :
V_82 -> V_27 = V_36 ;
V_82 -> V_69 = V_35 ;
break;
case V_106 :
V_82 -> V_27 = V_31 ;
V_82 -> V_69 = V_34 ;
break;
default:
V_84 = - V_2 ;
}
F_45 ( & V_94 ) ;
return V_84 ;
}
static unsigned int F_50 ( struct V_79 * V_79 , T_9 * V_107 )
{
struct V_81 * V_82 = V_79 -> V_83 ;
int V_84 = 0 ;
if ( ! V_82 )
return V_108 | V_109 ;
F_51 ( V_79 , & V_99 , V_107 ) ;
F_44 ( & V_94 ) ;
if ( V_82 -> V_69 < V_34 ) {
if ( V_82 -> V_69 < V_33 )
V_84 = V_110 | V_111 | V_108 | V_112 ;
else
V_84 = V_110 | V_111 ;
}
F_45 ( & V_94 ) ;
return V_84 ;
}
static int F_52 ( struct V_113 * V_113 , struct V_79 * V_79 )
{
struct V_81 * V_82 ;
int V_18 ;
if ( V_3 & V_5 )
return - V_64 ;
if ( ( V_79 -> V_95 & V_114 ) != V_115 ) {
V_18 = F_22 ( V_54 ,
V_116 ) ;
if ( V_18 )
return V_18 ;
}
V_82 = F_35 ( sizeof( struct V_81 ) , V_87 ) ;
if ( ! V_82 )
return - V_37 ;
F_53 ( & V_82 -> V_86 ) ;
F_54 ( & V_82 -> V_86 , V_117 ) ;
F_55 ( & V_82 -> V_93 ) ;
F_44 ( & V_94 ) ;
V_82 -> V_27 = V_32 ;
V_82 -> V_69 = V_33 ;
F_45 ( & V_94 ) ;
V_79 -> V_83 = V_82 ;
return 0 ;
}
static int F_56 ( struct V_113 * V_113 , struct V_79 * V_79 )
{
struct V_81 * V_82 = V_79 -> V_83 ;
if ( ! V_82 )
return 0 ;
F_57 ( & V_82 -> V_86 ) ;
F_58 ( & V_82 -> V_93 ) ;
F_37 ( V_82 ) ;
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
V_118 = V_40 ;
}
static int T_1 F_65 ( char * V_1 )
{
unsigned V_40 = F_66 ( V_1 , & V_1 ) ;
F_63 ( V_40 ) ;
return 0 ;
}
static void T_1 F_67 ( void )
{
unsigned int V_119 ;
if ( F_68 () == 1 )
return;
V_119 = ( F_68 () - 1 ) * V_120 ;
if ( V_119 <= V_121 / 2 )
return;
F_69 ( L_10 ,
V_120 ) ;
F_69 ( L_11 ,
V_119 ) ;
F_69 ( L_12 , V_121 ) ;
F_63 ( V_119 + V_121 ) ;
}
static inline void F_67 ( void ) {}
void T_1 F_70 ( int V_122 )
{
unsigned long V_49 ;
char * V_123 ;
int free ;
if ( V_22 != V_124 )
return;
if ( ! V_122 && ! V_118 )
F_67 () ;
if ( ! V_118 )
return;
if ( V_122 ) {
V_123 =
F_71 ( V_118 , V_41 ) ;
} else {
V_123 = F_72 ( V_118 ,
V_41 ) ;
}
if ( F_73 ( ! V_123 ) ) {
F_74 ( L_13 ,
V_118 ) ;
return;
}
F_75 ( & V_94 , V_49 ) ;
V_23 = V_118 ;
V_22 = V_123 ;
V_118 = 0 ;
free = V_121 - V_31 ;
memcpy ( V_22 , V_124 , V_121 ) ;
F_76 ( & V_94 , V_49 ) ;
F_69 ( L_14 , V_23 ) ;
F_69 ( L_15 ,
free , ( free * 100 ) / V_121 ) ;
}
static int T_1 F_77 ( char * V_1 )
{
V_125 = true ;
F_69 ( L_16 ) ;
return 0 ;
}
static bool F_78 ( int V_47 )
{
return ( V_47 >= V_126 && ! V_125 ) ;
}
static int T_1 F_79 ( char * V_1 )
{
unsigned long V_127 ;
V_127 = V_128 ? V_128 : 1000000 ;
V_129 = ( unsigned long long ) V_127 / 1000 * V_130 ;
F_80 ( & V_1 , & V_131 ) ;
if ( V_131 > 10 * 1000 )
V_131 = 0 ;
F_81 ( L_17
L_18 ,
V_131 , V_128 , V_127 , V_130 , V_129 ) ;
return 0 ;
}
static void F_82 ( int V_47 )
{
unsigned long long V_132 ;
unsigned long V_133 ;
if ( ( V_131 == 0 || V_134 != V_135 )
|| F_78 ( V_47 ) ) {
return;
}
V_132 = ( unsigned long long ) V_129 * V_131 ;
V_133 = V_136 + F_83 ( V_131 ) ;
while ( V_132 ) {
V_132 -- ;
F_84 () ;
if ( F_85 ( V_136 , V_133 ) )
break;
F_86 () ;
}
}
static inline void F_82 ( int V_47 )
{
}
static T_3 F_87 ( T_7 V_137 , char * V_68 )
{
unsigned long V_138 ;
if ( ! V_139 )
return 0 ;
V_138 = F_29 ( V_137 , 1000000000 ) ;
if ( ! V_68 )
return snprintf ( NULL , 0 , L_19 , ( unsigned long ) V_137 ) ;
return sprintf ( V_68 , L_20 ,
( unsigned long ) V_137 , V_138 / 1000 ) ;
}
static T_3 F_88 ( const struct V_24 * V_25 , bool V_140 , char * V_68 )
{
T_3 V_28 = 0 ;
unsigned int V_141 = ( V_25 -> V_46 << 3 ) | V_25 -> V_47 ;
if ( V_140 ) {
if ( V_68 ) {
V_28 += sprintf ( V_68 , L_21 , V_141 ) ;
} else {
V_28 += 3 ;
if ( V_141 > 999 )
V_28 += 3 ;
else if ( V_141 > 99 )
V_28 += 2 ;
else if ( V_141 > 9 )
V_28 ++ ;
}
}
V_28 += F_87 ( V_25 -> V_50 , V_68 ? V_68 + V_28 : NULL ) ;
return V_28 ;
}
static T_3 F_89 ( const struct V_24 * V_25 , bool V_140 , char * V_68 , T_3 V_40 )
{
const char * V_52 = F_10 ( V_25 ) ;
T_3 V_142 = V_25 -> V_26 ;
T_3 V_28 = 0 ;
do {
const char * V_143 = memchr ( V_52 , '\n' , V_142 ) ;
T_3 V_26 ;
if ( V_143 ) {
V_26 = V_143 - V_52 ;
V_143 ++ ;
V_142 -= V_143 - V_52 ;
} else {
V_26 = V_142 ;
}
if ( V_68 ) {
if ( F_88 ( V_25 , V_140 , NULL ) +
V_26 + 1 >= V_40 - V_28 )
break;
V_28 += F_88 ( V_25 , V_140 , V_68 + V_28 ) ;
memcpy ( V_68 + V_28 , V_52 , V_26 ) ;
V_28 += V_26 ;
V_68 [ V_28 ++ ] = '\n' ;
} else {
V_28 += F_88 ( V_25 , V_140 , NULL ) ;
V_28 += V_26 ;
V_28 ++ ;
}
V_52 = V_143 ;
} while ( V_52 );
return V_28 ;
}
static int F_90 ( char T_2 * V_68 , int V_40 )
{
char * V_52 ;
struct V_24 * V_25 ;
int V_28 = 0 ;
V_52 = F_35 ( V_85 + V_144 , V_87 ) ;
if ( ! V_52 )
return - V_37 ;
while ( V_40 > 0 ) {
T_3 V_145 ;
T_3 V_146 ;
F_44 ( & V_94 ) ;
if ( V_147 < V_33 ) {
V_147 = V_33 ;
V_148 = V_32 ;
V_149 = 0 ;
}
if ( V_147 == V_34 ) {
F_45 ( & V_94 ) ;
break;
}
V_146 = V_149 ;
V_25 = F_12 ( V_148 ) ;
V_145 = F_89 ( V_25 , true , V_52 , V_85 + V_144 ) ;
if ( V_145 - V_149 <= V_40 ) {
V_148 = F_13 ( V_148 ) ;
V_147 ++ ;
V_145 -= V_149 ;
V_149 = 0 ;
} else if ( ! V_28 ) {
V_145 = V_40 ;
V_149 += V_145 ;
} else
V_145 = 0 ;
F_45 ( & V_94 ) ;
if ( ! V_145 )
break;
if ( F_47 ( V_68 , V_52 + V_146 , V_145 ) ) {
if ( ! V_28 )
V_28 = - V_88 ;
break;
}
V_28 += V_145 ;
V_40 -= V_145 ;
V_68 += V_145 ;
}
F_37 ( V_52 ) ;
return V_28 ;
}
static int F_91 ( char T_2 * V_68 , int V_40 , bool V_150 )
{
char * V_52 ;
int V_28 = 0 ;
V_52 = F_35 ( V_85 + V_144 , V_87 ) ;
if ( ! V_52 )
return - V_37 ;
F_44 ( & V_94 ) ;
if ( V_68 ) {
T_7 V_151 ;
T_7 V_69 ;
T_5 V_27 ;
V_69 = V_35 ;
V_27 = V_36 ;
while ( V_69 < V_34 ) {
struct V_24 * V_25 = F_12 ( V_27 ) ;
V_28 += F_89 ( V_25 , true , NULL , 0 ) ;
V_27 = F_13 ( V_27 ) ;
V_69 ++ ;
}
V_69 = V_35 ;
V_27 = V_36 ;
while ( V_28 > V_40 && V_69 < V_34 ) {
struct V_24 * V_25 = F_12 ( V_27 ) ;
V_28 -= F_89 ( V_25 , true , NULL , 0 ) ;
V_27 = F_13 ( V_27 ) ;
V_69 ++ ;
}
V_151 = V_34 ;
V_28 = 0 ;
while ( V_28 >= 0 && V_69 < V_151 ) {
struct V_24 * V_25 = F_12 ( V_27 ) ;
int V_152 ;
V_152 = F_89 ( V_25 , true , V_52 ,
V_85 + V_144 ) ;
if ( V_152 < 0 ) {
V_28 = V_152 ;
break;
}
V_27 = F_13 ( V_27 ) ;
V_69 ++ ;
F_45 ( & V_94 ) ;
if ( F_47 ( V_68 + V_28 , V_52 , V_152 ) )
V_28 = - V_88 ;
else
V_28 += V_152 ;
F_44 ( & V_94 ) ;
if ( V_69 < V_33 ) {
V_69 = V_33 ;
V_27 = V_32 ;
}
}
}
if ( V_150 ) {
V_35 = V_34 ;
V_36 = V_31 ;
}
F_45 ( & V_94 ) ;
F_37 ( V_52 ) ;
return V_28 ;
}
int F_92 ( int type , char T_2 * V_68 , int V_28 , int V_56 )
{
bool V_150 = false ;
static int V_153 = V_154 ;
int error ;
error = F_22 ( type , V_56 ) ;
if ( error )
goto V_98;
switch ( type ) {
case V_155 :
break;
case V_58 :
break;
case V_156 :
error = - V_2 ;
if ( ! V_68 || V_28 < 0 )
goto V_98;
error = 0 ;
if ( ! V_28 )
goto V_98;
if ( ! F_93 ( V_157 , V_68 , V_28 ) ) {
error = - V_88 ;
goto V_98;
}
error = F_46 ( V_99 ,
V_147 != V_34 ) ;
if ( error )
goto V_98;
error = F_90 ( V_68 , V_28 ) ;
break;
case V_158 :
V_150 = true ;
case V_54 :
error = - V_2 ;
if ( ! V_68 || V_28 < 0 )
goto V_98;
error = 0 ;
if ( ! V_28 )
goto V_98;
if ( ! F_93 ( V_157 , V_68 , V_28 ) ) {
error = - V_88 ;
goto V_98;
}
error = F_91 ( V_68 , V_28 , V_150 ) ;
break;
case V_159 :
F_91 ( NULL , 0 , true ) ;
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
if ( V_28 < 1 || V_28 > 8 )
goto V_98;
if ( V_28 < V_161 )
V_28 = V_161 ;
V_126 = V_28 ;
V_153 = V_154 ;
error = 0 ;
break;
case V_164 :
F_44 ( & V_94 ) ;
if ( V_147 < V_33 ) {
V_147 = V_33 ;
V_148 = V_32 ;
V_149 = 0 ;
}
if ( V_56 == V_57 ) {
error = V_34 - V_147 ;
} else {
T_7 V_69 = V_147 ;
T_5 V_27 = V_148 ;
error = 0 ;
while ( V_69 < V_34 ) {
struct V_24 * V_25 = F_12 ( V_27 ) ;
error += F_89 ( V_25 , true , NULL , 0 ) ;
V_27 = F_13 ( V_27 ) ;
V_69 ++ ;
}
error -= V_149 ;
}
F_45 ( & V_94 ) ;
break;
case V_55 :
error = V_23 ;
break;
default:
error = - V_2 ;
break;
}
V_98:
return error ;
}
static void F_94 ( int V_47 ,
const char * V_165 , T_3 V_166 ,
const char * V_52 , T_3 V_28 )
{
struct V_167 * V_168 ;
F_95 ( V_52 , V_28 ) ;
if ( ! V_169 )
return;
F_96 (con) {
if ( V_170 && V_168 != V_170 )
continue;
if ( ! ( V_168 -> V_49 & V_171 ) )
continue;
if ( ! V_168 -> V_12 )
continue;
if ( ! F_97 ( F_98 () ) &&
! ( V_168 -> V_49 & V_172 ) )
continue;
if ( V_168 -> V_49 & V_173 )
V_168 -> V_12 ( V_168 , V_165 , V_166 ) ;
else
V_168 -> V_12 ( V_168 , V_52 , V_28 ) ;
}
}
static void F_99 ( void )
{
static unsigned long V_174 ;
if ( F_100 ( V_136 , V_174 ) &&
! F_85 ( V_136 , V_174 + 30 * V_130 ) )
return;
V_174 = V_136 ;
F_101 () ;
F_102 ( & V_94 ) ;
F_103 ( & V_20 , 1 ) ;
}
static inline void F_104 ( void )
{
if ( F_73 ( V_175 ) ) {
int V_176 = V_175 ;
while ( V_176 -- ) {
F_105 ( 1 ) ;
F_86 () ;
}
}
}
static void F_106 ( void )
{
if ( V_177 . V_28 == 0 )
return;
F_19 ( V_177 . V_46 , V_177 . V_47 , V_177 . V_49 , V_177 . V_50 ,
NULL , 0 , V_177 . V_68 , V_177 . V_28 ) ;
V_177 . V_28 = 0 ;
}
static bool F_107 ( int V_46 , int V_47 , enum V_48 V_49 , const char * V_52 , T_3 V_28 )
{
if ( V_178 || V_177 . V_28 + V_28 > sizeof( V_177 . V_68 ) ) {
F_106 () ;
return false ;
}
if ( ! V_177 . V_28 ) {
V_177 . V_46 = V_46 ;
V_177 . V_47 = V_47 ;
V_177 . V_179 = V_62 ;
V_177 . V_50 = F_20 () ;
V_177 . V_49 = V_49 ;
}
memcpy ( V_177 . V_68 + V_177 . V_28 , V_52 , V_28 ) ;
V_177 . V_28 += V_28 ;
if ( V_49 & V_180 ) {
V_177 . V_49 |= V_180 ;
F_106 () ;
}
if ( V_177 . V_28 > ( sizeof( V_177 . V_68 ) * 80 ) / 100 )
F_106 () ;
return true ;
}
static T_3 F_108 ( int V_46 , int V_47 , enum V_48 V_181 , const char * V_51 , T_3 V_182 , char * V_52 , T_3 V_26 )
{
if ( V_177 . V_28 ) {
if ( V_177 . V_179 == V_62 && ( V_181 & V_71 ) ) {
if ( F_107 ( V_46 , V_47 , V_181 , V_52 , V_26 ) )
return V_26 ;
}
F_106 () ;
}
if ( ! V_26 && ( V_181 & V_71 ) )
return 0 ;
if ( ! ( V_181 & V_180 ) ) {
if ( F_107 ( V_46 , V_47 , V_181 , V_52 , V_26 ) )
return V_26 ;
}
return F_19 ( V_46 , V_47 , V_181 , 0 , V_51 , V_182 , V_52 , V_26 ) ;
}
T_10 int F_109 ( int V_46 , int V_47 ,
const char * V_51 , T_3 V_182 ,
const char * V_183 , T_11 args )
{
static bool V_184 ;
static char V_185 [ V_85 ] ;
char * V_52 = V_185 ;
T_3 V_26 = 0 ;
enum V_48 V_181 = 0 ;
unsigned long V_49 ;
int V_186 ;
int V_187 = 0 ;
int V_188 ;
bool V_189 = false ;
static unsigned int V_190 = V_191 ;
if ( V_47 == V_192 ) {
V_47 = V_154 ;
V_189 = true ;
}
F_82 ( V_47 ) ;
F_104 () ;
F_110 ( V_49 ) ;
V_186 = F_98 () ;
if ( F_73 ( V_190 == V_186 ) ) {
if ( ! V_193 && ! F_111 ( V_62 ) ) {
V_184 = true ;
F_112 ( V_49 ) ;
return 0 ;
}
F_99 () ;
}
F_113 () ;
F_114 ( & V_94 ) ;
V_190 = V_186 ;
if ( F_73 ( V_184 ) ) {
static const char V_194 [] =
L_22 ;
V_184 = false ;
V_187 += F_19 ( 0 , 2 , V_195 | V_180 , 0 ,
NULL , 0 , V_194 ,
strlen ( V_194 ) ) ;
}
V_188 = F_115 () ;
if ( F_73 ( V_188 ) ) {
V_26 = F_30 ( V_185 , sizeof( V_185 ) ,
L_23 ,
V_188 ) ;
V_187 += F_19 ( 0 , 2 , V_195 | V_180 , 0 ,
NULL , 0 , V_185 , V_26 ) ;
}
V_26 = F_116 ( V_52 , sizeof( V_185 ) , V_183 , args ) ;
if ( V_26 && V_52 [ V_26 - 1 ] == '\n' ) {
V_26 -- ;
V_181 |= V_180 ;
}
if ( V_46 == 0 ) {
int V_196 ;
while ( ( V_196 = F_117 ( V_52 ) ) != 0 ) {
switch ( V_196 ) {
case '0' ... '7' :
if ( V_47 == V_154 )
V_47 = V_196 - '0' ;
case 'd' :
V_181 |= V_195 ;
break;
case 'c' :
V_181 |= V_71 ;
}
V_26 -= 2 ;
V_52 += 2 ;
}
}
if ( V_47 == V_154 )
V_47 = V_78 ;
if ( V_51 )
V_181 |= V_195 | V_180 ;
V_187 += F_108 ( V_46 , V_47 , V_181 , V_51 , V_182 , V_52 , V_26 ) ;
V_190 = V_191 ;
F_118 ( & V_94 ) ;
F_119 () ;
F_112 ( V_49 ) ;
if ( ! V_189 ) {
F_113 () ;
if ( F_120 () )
F_121 () ;
F_119 () ;
}
return V_187 ;
}
T_10 int F_122 ( const char * V_183 , T_11 args )
{
return F_109 ( 0 , V_154 , NULL , 0 , V_183 , args ) ;
}
T_10 int F_41 ( int V_46 , int V_47 ,
const char * V_51 , T_3 V_182 ,
const char * V_183 , ... )
{
T_11 args ;
int V_197 ;
va_start ( args , V_183 ) ;
V_197 = F_109 ( V_46 , V_47 , V_51 , V_182 , V_183 , args ) ;
va_end ( args ) ;
return V_197 ;
}
int F_123 ( const char * V_183 , T_11 args )
{
int V_197 ;
#ifdef F_124
if ( F_73 ( V_198 && V_199 < 0 ) ) {
V_197 = F_125 ( V_200 , V_183 , args ) ;
return V_197 ;
}
#endif
V_197 = F_109 ( 0 , V_154 , NULL , 0 , V_183 , args ) ;
return V_197 ;
}
T_10 T_12 int F_126 ( const char * V_183 , ... )
{
T_11 args ;
int V_197 ;
va_start ( args , V_183 ) ;
V_197 = F_127 ( V_183 , args ) ;
va_end ( args ) ;
return V_197 ;
}
static char * F_10 ( const struct V_24 * V_25 ) { return NULL ; }
static char * F_11 ( const struct V_24 * V_25 ) { return NULL ; }
static struct V_24 * F_12 ( T_5 V_27 ) { return NULL ; }
static T_5 F_13 ( T_5 V_27 ) { return 0 ; }
static T_8 F_28 ( char * V_68 , T_3 V_40 ,
struct V_24 * V_25 ,
T_7 V_69 ) { return 0 ; }
static T_8 F_31 ( char * V_68 , T_3 V_40 ,
char * V_51 , T_3 V_38 ,
char * V_52 , T_3 V_26 ) { return 0 ; }
static void F_94 ( int V_47 ,
const char * V_165 , T_3 V_166 ,
const char * V_52 , T_3 V_28 ) {}
static T_3 F_89 ( const struct V_24 * V_25 ,
bool V_140 , char * V_68 , T_3 V_40 ) { return 0 ; }
static bool F_78 ( int V_47 ) { return false ; }
T_10 T_12 void F_128 ( const char * V_183 , ... )
{
T_11 V_201 ;
char V_68 [ 512 ] ;
int V_145 ;
if ( ! V_202 )
return;
va_start ( V_201 , V_183 ) ;
V_145 = F_116 ( V_68 , sizeof( V_68 ) , V_183 , V_201 ) ;
va_end ( V_201 ) ;
V_202 -> V_12 ( V_202 , V_68 , V_145 ) ;
}
static int F_129 ( char * V_203 , int V_27 , char * V_204 ,
char * V_205 )
{
struct V_206 * V_67 ;
int V_73 ;
for ( V_73 = 0 , V_67 = V_206 ;
V_73 < V_207 && V_67 -> V_203 [ 0 ] ;
V_73 ++ , V_67 ++ ) {
if ( strcmp ( V_67 -> V_203 , V_203 ) == 0 && V_67 -> V_208 == V_27 ) {
if ( ! V_205 )
V_209 = V_73 ;
return 0 ;
}
}
if ( V_73 == V_207 )
return - V_210 ;
if ( ! V_205 )
V_209 = V_73 ;
F_130 ( V_67 -> V_203 , V_203 , sizeof( V_67 -> V_203 ) ) ;
V_67 -> V_204 = V_204 ;
F_131 ( V_67 , V_205 ) ;
V_67 -> V_208 = V_27 ;
return 0 ;
}
static int T_1 F_132 ( char * V_1 )
{
char V_68 [ sizeof( V_206 [ 0 ] . V_203 ) + 4 ] ;
char * V_211 , * V_204 , * V_205 = NULL ;
int V_27 ;
if ( F_133 ( & V_1 , & V_205 ) )
return 1 ;
if ( V_1 [ 0 ] >= '0' && V_1 [ 0 ] <= '9' ) {
strcpy ( V_68 , L_24 ) ;
strncpy ( V_68 + 4 , V_1 , sizeof( V_68 ) - 5 ) ;
} else {
strncpy ( V_68 , V_1 , sizeof( V_68 ) - 1 ) ;
}
V_68 [ sizeof( V_68 ) - 1 ] = 0 ;
V_204 = strchr ( V_1 , ',' ) ;
if ( V_204 )
* ( V_204 ++ ) = 0 ;
#ifdef F_134
if ( ! strcmp ( V_1 , L_25 ) )
strcpy ( V_68 , L_26 ) ;
if ( ! strcmp ( V_1 , L_27 ) )
strcpy ( V_68 , L_28 ) ;
#endif
for ( V_211 = V_68 ; * V_211 ; V_211 ++ )
if ( isdigit ( * V_211 ) || * V_211 == ',' )
break;
V_27 = F_38 ( V_211 , NULL , 10 ) ;
* V_211 = 0 ;
F_129 ( V_68 , V_27 , V_204 , V_205 ) ;
V_212 = 1 ;
return 1 ;
}
int F_135 ( char * V_203 , int V_27 , char * V_204 )
{
return F_129 ( V_203 , V_27 , V_204 , NULL ) ;
}
static int T_1 F_136 ( char * V_1 )
{
V_213 = false ;
return 1 ;
}
void F_137 ( void )
{
if ( ! V_213 )
return;
F_126 ( L_29 ) ;
F_138 () ;
V_214 = 1 ;
F_139 () ;
}
void F_140 ( void )
{
if ( ! V_213 )
return;
F_141 () ;
V_214 = 0 ;
F_121 () ;
}
static int F_142 ( unsigned int V_215 )
{
if ( ! V_216 ) {
F_138 () ;
F_121 () ;
}
return 0 ;
}
void F_138 ( void )
{
F_143 () ;
F_141 () ;
if ( V_214 )
return;
V_217 = 1 ;
V_218 = 1 ;
}
int F_120 ( void )
{
if ( F_144 () )
return 0 ;
if ( V_214 ) {
F_139 () ;
return 0 ;
}
V_217 = 1 ;
V_218 = ! V_193 &&
F_145 () &&
! F_146 () ;
return 1 ;
}
int F_147 ( void )
{
return V_217 ;
}
static int F_148 ( void )
{
struct V_167 * V_168 ;
F_96 (con)
if ( ( V_168 -> V_49 & V_171 ) &&
( V_168 -> V_49 & V_172 ) )
return 1 ;
return 0 ;
}
static inline int F_149 ( void )
{
return F_97 ( F_150 () ) || F_148 () ;
}
void F_121 ( void )
{
static char V_165 [ V_219 ] ;
static char V_52 [ V_85 + V_144 ] ;
static T_7 V_220 ;
unsigned long V_49 ;
bool V_221 = false ;
bool V_222 , V_223 ;
if ( V_214 ) {
F_139 () ;
return;
}
V_222 = V_218 ;
V_218 = 0 ;
V_224:
if ( ! F_149 () ) {
V_217 = 0 ;
F_139 () ;
return;
}
for (; ; ) {
struct V_24 * V_25 ;
T_3 V_166 = 0 ;
T_3 V_28 ;
int V_47 ;
F_75 ( & V_94 , V_49 ) ;
if ( V_220 != V_34 ) {
V_221 = true ;
V_220 = V_34 ;
}
if ( V_225 < V_33 ) {
V_28 = sprintf ( V_52 , L_30 ,
( unsigned ) ( V_33 - V_225 ) ) ;
V_225 = V_33 ;
V_226 = V_32 ;
} else {
V_28 = 0 ;
}
V_146:
if ( V_225 == V_34 )
break;
V_25 = F_12 ( V_226 ) ;
V_47 = V_25 -> V_47 ;
if ( F_78 ( V_47 ) ) {
V_226 = F_13 ( V_226 ) ;
V_225 ++ ;
goto V_146;
}
V_28 += F_89 ( V_25 , false , V_52 + V_28 , sizeof( V_52 ) - V_28 ) ;
if ( V_178 ) {
V_166 = F_28 ( V_165 ,
sizeof( V_165 ) ,
V_25 , V_225 ) ;
V_166 += F_31 ( V_165 + V_166 ,
sizeof( V_165 ) - V_166 ,
F_11 ( V_25 ) , V_25 -> V_38 ,
F_10 ( V_25 ) , V_25 -> V_26 ) ;
}
V_226 = F_13 ( V_226 ) ;
V_225 ++ ;
F_118 ( & V_94 ) ;
F_151 () ;
F_94 ( V_47 , V_165 , V_166 , V_52 , V_28 ) ;
F_152 () ;
F_112 ( V_49 ) ;
if ( V_222 )
F_153 () ;
}
V_217 = 0 ;
if ( F_73 ( V_170 ) )
V_170 = NULL ;
F_118 ( & V_94 ) ;
F_139 () ;
F_114 ( & V_94 ) ;
V_223 = V_225 != V_34 ;
F_76 ( & V_94 , V_49 ) ;
if ( V_223 && F_120 () )
goto V_224;
if ( V_221 )
F_154 () ;
}
void T_13 F_155 ( void )
{
if ( V_218 )
F_153 () ;
}
void F_156 ( void )
{
struct V_167 * V_67 ;
if ( V_193 ) {
if ( F_144 () != 0 )
return;
} else
F_138 () ;
V_217 = 1 ;
V_218 = 0 ;
F_96 (c)
if ( ( V_67 -> V_49 & V_171 ) && V_67 -> V_227 )
V_67 -> V_227 () ;
F_121 () ;
}
void F_157 ( void )
{
F_120 () ;
V_218 = 0 ;
F_121 () ;
}
struct V_228 * F_158 ( int * V_208 )
{
struct V_167 * V_67 ;
struct V_228 * V_229 = NULL ;
F_138 () ;
F_96 (c) {
if ( ! V_67 -> V_230 )
continue;
V_229 = V_67 -> V_230 ( V_67 , V_208 ) ;
if ( V_229 )
break;
}
F_121 () ;
return V_229 ;
}
void F_159 ( struct V_167 * V_167 )
{
F_138 () ;
V_167 -> V_49 &= ~ V_171 ;
F_121 () ;
}
void F_160 ( struct V_167 * V_167 )
{
F_138 () ;
V_167 -> V_49 |= V_171 ;
F_121 () ;
}
static int T_1 F_161 ( char * V_1 )
{
V_231 = 1 ;
F_69 ( L_31 ) ;
return 0 ;
}
void F_162 ( struct V_167 * V_232 )
{
int V_73 ;
unsigned long V_49 ;
struct V_167 * V_233 = NULL ;
struct V_206 * V_67 ;
if ( V_169 )
F_96 (bcon)
if ( F_163 ( V_233 == V_232 ,
L_32 ,
V_233 -> V_203 , V_233 -> V_208 ) )
return;
if ( V_169 && V_232 -> V_49 & V_234 ) {
F_96 (bcon) {
if ( ! ( V_233 -> V_49 & V_234 ) ) {
F_69 ( L_33 ,
V_232 -> V_203 , V_232 -> V_208 ) ;
return;
}
}
}
if ( V_169 && V_169 -> V_49 & V_234 )
V_233 = V_169 ;
if ( V_235 < 0 || V_233 || ! V_169 )
V_235 = V_209 ;
if ( V_235 < 0 ) {
if ( V_232 -> V_208 < 0 )
V_232 -> V_208 = 0 ;
if ( V_232 -> V_236 == NULL ||
V_232 -> V_236 ( V_232 , NULL ) == 0 ) {
V_232 -> V_49 |= V_171 ;
if ( V_232 -> V_230 ) {
V_232 -> V_49 |= V_237 ;
V_235 = 0 ;
}
}
}
for ( V_73 = 0 , V_67 = V_206 ;
V_73 < V_207 && V_67 -> V_203 [ 0 ] ;
V_73 ++ , V_67 ++ ) {
if ( ! V_232 -> V_238 ||
V_232 -> V_238 ( V_232 , V_67 -> V_203 , V_67 -> V_208 , V_67 -> V_204 ) != 0 ) {
F_164 ( sizeof( V_67 -> V_203 ) != sizeof( V_232 -> V_203 ) ) ;
if ( strcmp ( V_67 -> V_203 , V_232 -> V_203 ) != 0 )
continue;
if ( V_232 -> V_208 >= 0 &&
V_232 -> V_208 != V_67 -> V_208 )
continue;
if ( V_232 -> V_208 < 0 )
V_232 -> V_208 = V_67 -> V_208 ;
if ( F_165 ( V_232 , V_67 ) )
return;
if ( V_232 -> V_236 &&
V_232 -> V_236 ( V_232 , V_67 -> V_204 ) != 0 )
break;
}
V_232 -> V_49 |= V_171 ;
if ( V_73 == V_209 ) {
V_232 -> V_49 |= V_237 ;
V_235 = V_209 ;
}
break;
}
if ( ! ( V_232 -> V_49 & V_171 ) )
return;
if ( V_233 && ( ( V_232 -> V_49 & ( V_237 | V_234 ) ) == V_237 ) )
V_232 -> V_49 &= ~ V_239 ;
F_138 () ;
if ( ( V_232 -> V_49 & V_237 ) || V_169 == NULL ) {
V_232 -> V_143 = V_169 ;
V_169 = V_232 ;
if ( V_232 -> V_143 )
V_232 -> V_143 -> V_49 &= ~ V_237 ;
} else {
V_232 -> V_143 = V_169 -> V_143 ;
V_169 -> V_143 = V_232 ;
}
if ( V_232 -> V_49 & V_173 )
if ( ! V_178 ++ )
F_69 ( L_34 ) ;
if ( V_232 -> V_49 & V_239 ) {
F_75 ( & V_94 , V_49 ) ;
V_225 = V_147 ;
V_226 = V_148 ;
F_76 ( & V_94 , V_49 ) ;
V_170 = V_232 ;
}
F_121 () ;
F_166 () ;
F_69 ( L_35 ,
( V_232 -> V_49 & V_234 ) ? L_36 : L_37 ,
V_232 -> V_203 , V_232 -> V_208 ) ;
if ( V_233 &&
( ( V_232 -> V_49 & ( V_237 | V_234 ) ) == V_237 ) &&
! V_231 ) {
F_96 (bcon)
if ( V_233 -> V_49 & V_234 )
F_167 ( V_233 ) ;
}
}
int F_167 ( struct V_167 * V_167 )
{
struct V_167 * V_240 , * V_241 ;
int V_242 ;
F_69 ( L_38 ,
( V_167 -> V_49 & V_234 ) ? L_36 : L_37 ,
V_167 -> V_203 , V_167 -> V_208 ) ;
V_242 = F_168 ( V_167 ) ;
if ( V_242 )
return V_242 ;
V_242 = 1 ;
F_138 () ;
if ( V_169 == V_167 ) {
V_169 = V_167 -> V_143 ;
V_242 = 0 ;
} else if ( V_169 ) {
for ( V_240 = V_169 -> V_143 , V_241 = V_169 ;
V_240 ; V_241 = V_240 , V_240 = V_241 -> V_143 ) {
if ( V_240 == V_167 ) {
V_241 -> V_143 = V_240 -> V_143 ;
V_242 = 0 ;
break;
}
}
}
if ( ! V_242 && ( V_167 -> V_49 & V_173 ) )
V_178 -- ;
if ( V_169 != NULL && V_167 -> V_49 & V_237 )
V_169 -> V_49 |= V_237 ;
V_167 -> V_49 &= ~ V_171 ;
F_121 () ;
F_166 () ;
return V_242 ;
}
static int T_1 F_169 ( void )
{
struct V_167 * V_168 ;
int V_84 ;
F_96 (con) {
if ( ! V_231 && V_168 -> V_49 & V_234 ) {
if ( F_170 ( V_168 , sizeof( * V_168 ) ) )
F_167 ( V_168 ) ;
}
}
V_84 = F_171 ( V_243 , L_39 , NULL ,
F_142 ) ;
F_172 ( V_84 < 0 ) ;
V_84 = F_171 ( V_244 , L_40 ,
F_142 , NULL ) ;
F_172 ( V_84 < 0 ) ;
return 0 ;
}
static void F_173 ( struct V_245 * V_245 )
{
int V_246 = F_174 ( V_247 , 0 ) ;
if ( V_246 & V_248 ) {
if ( F_120 () )
F_121 () ;
}
if ( V_246 & V_249 )
F_175 ( & V_99 ) ;
}
void F_154 ( void )
{
F_176 () ;
if ( F_177 ( & V_99 ) ) {
F_178 ( V_247 , V_249 ) ;
F_179 ( F_180 ( & V_250 ) ) ;
}
F_181 () ;
}
int F_182 ( const char * V_183 , ... )
{
T_11 args ;
int V_197 ;
F_176 () ;
va_start ( args , V_183 ) ;
V_197 = F_109 ( 0 , V_192 , NULL , 0 , V_183 , args ) ;
va_end ( args ) ;
F_183 ( V_247 , V_248 ) ;
F_179 ( F_180 ( & V_250 ) ) ;
F_181 () ;
return V_197 ;
}
int F_184 ( const char * V_251 )
{
return F_34 ( & V_252 , V_251 ) ;
}
bool F_185 ( unsigned long * V_253 ,
unsigned int V_254 )
{
unsigned long V_255 = V_136 - * V_253 ;
if ( * V_253 && V_255 <= F_83 ( V_254 ) )
return false ;
* V_253 = V_136 ;
return true ;
}
int F_186 ( struct V_256 * V_257 )
{
unsigned long V_49 ;
int V_18 = - V_258 ;
if ( ! V_257 -> V_259 )
return - V_2 ;
F_187 ( & V_260 , V_49 ) ;
if ( ! V_257 -> V_261 ) {
V_257 -> V_261 = 1 ;
F_188 ( & V_257 -> V_262 , & V_263 ) ;
V_18 = 0 ;
}
F_189 ( & V_260 , V_49 ) ;
return V_18 ;
}
int F_190 ( struct V_256 * V_257 )
{
unsigned long V_49 ;
int V_18 = - V_2 ;
F_187 ( & V_260 , V_49 ) ;
if ( V_257 -> V_261 ) {
V_257 -> V_261 = 0 ;
F_191 ( & V_257 -> V_262 ) ;
V_18 = 0 ;
}
F_189 ( & V_260 , V_49 ) ;
F_192 () ;
return V_18 ;
}
void F_193 ( enum V_264 V_265 )
{
struct V_256 * V_257 ;
unsigned long V_49 ;
if ( ( V_265 > V_266 ) && ! V_267 )
return;
F_194 () ;
F_195 (dumper, &dump_list, list) {
if ( V_257 -> V_268 && V_265 > V_257 -> V_268 )
continue;
V_257 -> V_269 = true ;
F_75 ( & V_94 , V_49 ) ;
V_257 -> V_270 = V_35 ;
V_257 -> V_271 = V_36 ;
V_257 -> V_151 = V_34 ;
V_257 -> V_272 = V_31 ;
F_76 ( & V_94 , V_49 ) ;
V_257 -> V_259 ( V_257 , V_265 ) ;
V_257 -> V_269 = false ;
}
F_196 () ;
}
bool F_197 ( struct V_256 * V_257 , bool V_140 ,
char * line , T_3 V_40 , T_3 * V_28 )
{
struct V_24 * V_25 ;
T_3 V_273 = 0 ;
bool V_84 = false ;
if ( ! V_257 -> V_269 )
goto V_98;
if ( V_257 -> V_270 < V_33 ) {
V_257 -> V_270 = V_33 ;
V_257 -> V_271 = V_32 ;
}
if ( V_257 -> V_270 >= V_34 )
goto V_98;
V_25 = F_12 ( V_257 -> V_271 ) ;
V_273 = F_89 ( V_25 , V_140 , line , V_40 ) ;
V_257 -> V_271 = F_13 ( V_257 -> V_271 ) ;
V_257 -> V_270 ++ ;
V_84 = true ;
V_98:
if ( V_28 )
* V_28 = V_273 ;
return V_84 ;
}
bool F_198 ( struct V_256 * V_257 , bool V_140 ,
char * line , T_3 V_40 , T_3 * V_28 )
{
unsigned long V_49 ;
bool V_84 ;
F_75 ( & V_94 , V_49 ) ;
V_84 = F_197 ( V_257 , V_140 , line , V_40 , V_28 ) ;
F_76 ( & V_94 , V_49 ) ;
return V_84 ;
}
bool F_199 ( struct V_256 * V_257 , bool V_140 ,
char * V_68 , T_3 V_40 , T_3 * V_28 )
{
unsigned long V_49 ;
T_7 V_69 ;
T_5 V_27 ;
T_7 V_151 ;
T_5 V_272 ;
T_3 V_273 = 0 ;
bool V_84 = false ;
if ( ! V_257 -> V_269 )
goto V_98;
F_75 ( & V_94 , V_49 ) ;
if ( V_257 -> V_270 < V_33 ) {
V_257 -> V_270 = V_33 ;
V_257 -> V_271 = V_32 ;
}
if ( V_257 -> V_270 >= V_257 -> V_151 ) {
F_76 ( & V_94 , V_49 ) ;
goto V_98;
}
V_69 = V_257 -> V_270 ;
V_27 = V_257 -> V_271 ;
while ( V_69 < V_257 -> V_151 ) {
struct V_24 * V_25 = F_12 ( V_27 ) ;
V_273 += F_89 ( V_25 , true , NULL , 0 ) ;
V_27 = F_13 ( V_27 ) ;
V_69 ++ ;
}
V_69 = V_257 -> V_270 ;
V_27 = V_257 -> V_271 ;
while ( V_273 > V_40 && V_69 < V_257 -> V_151 ) {
struct V_24 * V_25 = F_12 ( V_27 ) ;
V_273 -= F_89 ( V_25 , true , NULL , 0 ) ;
V_27 = F_13 ( V_27 ) ;
V_69 ++ ;
}
V_151 = V_69 ;
V_272 = V_27 ;
V_273 = 0 ;
while ( V_69 < V_257 -> V_151 ) {
struct V_24 * V_25 = F_12 ( V_27 ) ;
V_273 += F_89 ( V_25 , V_140 , V_68 + V_273 , V_40 - V_273 ) ;
V_27 = F_13 ( V_27 ) ;
V_69 ++ ;
}
V_257 -> V_151 = V_151 ;
V_257 -> V_272 = V_272 ;
V_84 = true ;
F_76 ( & V_94 , V_49 ) ;
V_98:
if ( V_28 )
* V_28 = V_273 ;
return V_84 ;
}
void F_200 ( struct V_256 * V_257 )
{
V_257 -> V_270 = V_35 ;
V_257 -> V_271 = V_36 ;
V_257 -> V_151 = V_34 ;
V_257 -> V_272 = V_31 ;
}
void F_201 ( struct V_256 * V_257 )
{
unsigned long V_49 ;
F_75 ( & V_94 , V_49 ) ;
F_200 ( V_257 ) ;
F_76 ( & V_94 , V_49 ) ;
}
void T_1 F_202 ( const char * V_183 , ... )
{
T_11 args ;
va_start ( args , V_183 ) ;
vsnprintf ( V_274 , sizeof( V_274 ) ,
V_183 , args ) ;
va_end ( args ) ;
}
void F_203 ( const char * V_275 )
{
F_126 ( L_41 ,
V_275 , F_150 () , V_62 -> V_276 , V_62 -> V_63 ,
F_204 () , F_205 () -> V_277 ,
( int ) strcspn ( F_205 () -> V_278 , L_42 ) ,
F_205 () -> V_278 ) ;
if ( V_274 [ 0 ] != '\0' )
F_126 ( L_43 ,
V_275 , V_274 ) ;
F_206 ( V_275 , V_62 ) ;
}
void F_207 ( const char * V_275 )
{
F_203 ( V_275 ) ;
F_126 ( L_44 ,
V_275 , V_62 , F_208 ( V_62 ) ) ;
}
