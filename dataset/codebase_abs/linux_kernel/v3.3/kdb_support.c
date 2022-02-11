int F_1 ( const char * V_1 , T_1 * V_2 )
{
if ( F_2 ( V_3 ) )
F_3 ( L_1 , V_1 ,
V_2 ) ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_4 = F_4 ( V_1 ) ;
if ( V_2 -> V_4 ) {
if ( F_2 ( V_3 ) )
F_3 ( L_2
L_3 ,
V_2 -> V_4 ) ;
return 1 ;
}
if ( F_2 ( V_3 ) )
F_3 ( L_4 ) ;
return 0 ;
}
int F_5 ( unsigned long V_5 , T_1 * V_2 )
{
int V_6 = 0 ;
unsigned long V_7 = 0 ;
unsigned long V_8 = 0 ;
#define F_6 128
char * V_9 = NULL ;
if ( F_2 ( V_3 ) )
F_3 ( L_5 , V_5 , V_2 ) ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
if ( V_5 < 4096 )
goto V_10;
V_9 = F_7 ( F_6 , V_11 ) ;
if ( ! V_9 ) {
F_3 ( L_6 ,
V_5 ) ;
goto V_10;
}
V_2 -> V_12 = F_8 ( V_5 , & V_7 , & V_8 ,
( char * * ) ( & V_2 -> V_13 ) , V_9 ) ;
if ( V_8 > 8 * 1024 * 1024 ) {
V_2 -> V_12 = NULL ;
V_5 = V_8 = V_7 = 0 ;
}
V_2 -> V_4 = V_5 - V_8 ;
V_2 -> V_14 = V_2 -> V_4 + V_7 ;
V_6 = V_2 -> V_12 != NULL && * ( V_2 -> V_12 ) != '\0' ;
if ( V_6 ) {
int V_15 ;
if ( V_2 -> V_12 != V_9 ) {
strncpy ( V_9 , V_2 -> V_12 , F_6 ) ;
V_9 [ F_6 - 1 ] = '\0' ;
}
for ( V_15 = 0 ; V_15 < F_9 ( V_16 ) ; ++ V_15 ) {
if ( V_16 [ V_15 ] &&
strcmp ( V_16 [ V_15 ] , V_9 ) == 0 )
break;
}
if ( V_15 >= F_9 ( V_16 ) ) {
F_10 ( V_16 [ 0 ] ) ;
memcpy ( V_16 , V_16 + 1 ,
sizeof( V_16 [ 0 ] ) *
( F_9 ( V_16 ) - 1 ) ) ;
} else {
F_10 ( V_9 ) ;
V_9 = V_16 [ V_15 ] ;
memcpy ( V_16 + V_15 , V_16 + V_15 + 1 ,
sizeof( V_16 [ 0 ] ) *
( F_9 ( V_16 ) - V_15 - 1 ) ) ;
}
V_15 = F_9 ( V_16 ) - 1 ;
V_16 [ V_15 ] = V_9 ;
V_2 -> V_12 = V_16 [ V_15 ] ;
V_9 = NULL ;
}
if ( V_2 -> V_13 == NULL )
V_2 -> V_13 = L_7 ;
if ( F_2 ( V_3 ) )
F_3 ( L_8
L_9 , V_6 ,
V_2 -> V_4 , V_2 -> V_13 , V_2 -> V_12 ,
V_2 -> V_12 ) ;
V_10:
F_10 ( V_9 ) ;
return V_6 ;
}
void F_11 ( void )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < F_9 ( V_16 ) ; ++ V_15 ) {
if ( V_16 [ V_15 ] ) {
F_10 ( V_16 [ V_15 ] ) ;
V_16 [ V_15 ] = NULL ;
}
}
}
int F_12 ( char * V_17 , int V_18 )
{
T_2 V_19 = 0 ;
int V_20 = strlen ( V_17 ) , V_21 = 0 ;
int V_15 , V_22 = 0 ;
const char * V_23 ;
while ( ( V_23 = F_13 ( & V_19 ) ) ) {
if ( strncmp ( V_23 , V_17 , V_20 ) == 0 ) {
strcpy ( V_24 , V_23 ) ;
if ( ++ V_22 == 1 ) {
V_21 = F_14 ( int , V_18 - 1 ,
strlen ( V_24 ) ) ;
memcpy ( V_25 , V_24 , V_21 ) ;
V_25 [ V_21 ] = '\0' ;
continue;
}
for ( V_15 = 0 ; V_15 < V_21 ; V_15 ++ ) {
if ( V_24 [ V_15 ] != V_25 [ V_15 ] ) {
V_21 = V_15 ;
V_25 [ V_15 ] = '\0' ;
break;
}
}
}
}
if ( V_21 > V_20 )
memcpy ( V_17 , V_25 , V_21 + 1 ) ;
return V_22 ;
}
int F_15 ( char * V_17 , int V_26 )
{
int V_20 = strlen ( V_17 ) ;
static T_2 V_19 ;
const char * V_23 ;
if ( ! V_26 )
V_19 = 0 ;
while ( ( V_23 = F_13 ( & V_19 ) ) ) {
if ( strncmp ( V_23 , V_17 , V_20 ) == 0 ) {
strncpy ( V_17 , V_23 , strlen ( V_23 ) + 1 ) ;
return 1 ;
}
}
return 0 ;
}
void F_16 ( unsigned long V_5 , const T_1 * V_27 ,
unsigned int V_28 )
{
T_1 V_2 , * V_29 ;
if ( V_27 ) {
V_29 = ( T_1 * ) V_27 ;
} else {
V_29 = & V_2 ;
F_5 ( V_5 , V_29 ) ;
}
if ( ! ( V_29 -> V_12 || ( V_28 & V_30 ) ) )
return;
if ( V_28 & V_31 )
F_3 ( L_10 ) ;
if ( V_28 & V_30 )
F_3 ( V_32 , V_5 ) ;
if ( V_29 -> V_12 ) {
if ( V_28 & V_30 )
F_3 ( L_10 ) ;
if ( V_28 & V_33 )
F_3 ( L_11 ) ;
if ( strcmp ( V_29 -> V_13 , L_7 ) )
F_3 ( L_12 , V_29 -> V_13 ) ;
F_3 ( L_13 , V_29 -> V_12 ) ;
if ( V_5 != V_29 -> V_4 )
F_3 ( L_14 , V_5 - V_29 -> V_4 ) ;
if ( V_28 & V_34 )
F_3 ( L_15 ,
V_29 -> V_14 - V_29 -> V_4 ) ;
if ( V_28 & V_33 )
F_3 ( L_16 ) ;
}
if ( V_28 & V_35 )
F_3 ( L_10 ) ;
if ( V_28 & V_36 )
F_3 ( L_17 ) ;
}
char * F_17 ( const char * V_37 , T_3 type )
{
int V_38 = strlen ( V_37 ) + 1 ;
char * V_39 = F_18 ( V_38 , type ) ;
if ( ! V_39 )
return NULL ;
return strcpy ( V_39 , V_37 ) ;
}
int F_19 ( void * V_40 , unsigned long V_5 , T_4 V_41 )
{
int V_6 = F_20 ( ( char * ) V_40 , ( char * ) V_5 , V_41 ) ;
if ( V_6 ) {
if ( ! F_21 ( V_42 ) ) {
F_3 ( L_18 , V_5 ) ;
F_22 ( V_42 ) ;
}
V_6 = V_43 ;
} else {
F_23 ( V_42 ) ;
}
return V_6 ;
}
int F_24 ( unsigned long V_5 , void * V_40 , T_4 V_41 )
{
int V_6 = F_20 ( ( char * ) V_5 , ( char * ) V_40 , V_41 ) ;
if ( V_6 ) {
if ( ! F_21 ( V_42 ) ) {
F_3 ( L_19 , V_5 ) ;
F_22 ( V_42 ) ;
}
V_6 = V_43 ;
} else {
F_23 ( V_42 ) ;
}
return V_6 ;
}
static int F_25 ( void * V_40 , unsigned long V_5 , T_4 V_41 )
{
unsigned long V_44 ;
void * V_45 ;
struct V_46 * V_46 ;
V_44 = ( V_5 >> V_47 ) ;
if ( ! F_26 ( V_44 ) )
return 1 ;
V_46 = F_27 ( V_44 ) ;
V_45 = F_28 ( V_46 , V_48 ) ;
memcpy ( V_40 , V_45 + ( V_5 & ( V_49 - 1 ) ) , V_41 ) ;
F_29 ( V_45 , V_48 ) ;
return 0 ;
}
int F_30 ( unsigned long * V_50 , unsigned long V_5 , T_4 V_41 )
{
int V_51 ;
T_5 V_52 ;
T_6 V_53 ;
T_7 V_54 ;
T_8 V_55 ;
* V_50 = 0 ;
switch ( V_41 ) {
case 1 :
V_51 = F_25 ( & V_52 , V_5 , sizeof( V_52 ) ) ;
if ( ! V_51 )
* V_50 = V_52 ;
break;
case 2 :
V_51 = F_25 ( & V_53 , V_5 , sizeof( V_53 ) ) ;
if ( ! V_51 )
* V_50 = V_53 ;
break;
case 4 :
V_51 = F_25 ( & V_54 , V_5 , sizeof( V_54 ) ) ;
if ( ! V_51 )
* V_50 = V_54 ;
break;
case 8 :
if ( V_41 <= sizeof( * V_50 ) ) {
V_51 = F_25 ( & V_55 , V_5 , sizeof( V_55 ) ) ;
if ( ! V_51 )
* V_50 = V_55 ;
break;
}
default:
V_51 = V_56 ;
F_3 ( L_20 , ( long ) V_41 ) ;
}
return V_51 ;
}
int F_31 ( unsigned long * V_50 , unsigned long V_5 , T_4 V_41 )
{
int V_51 ;
T_5 V_52 ;
T_6 V_53 ;
T_7 V_54 ;
T_8 V_55 ;
* V_50 = 0 ;
switch ( V_41 ) {
case 1 :
V_51 = F_32 ( V_52 , V_5 ) ;
if ( ! V_51 )
* V_50 = V_52 ;
break;
case 2 :
V_51 = F_32 ( V_53 , V_5 ) ;
if ( ! V_51 )
* V_50 = V_53 ;
break;
case 4 :
V_51 = F_32 ( V_54 , V_5 ) ;
if ( ! V_51 )
* V_50 = V_54 ;
break;
case 8 :
if ( V_41 <= sizeof( * V_50 ) ) {
V_51 = F_32 ( V_55 , V_5 ) ;
if ( ! V_51 )
* V_50 = V_55 ;
break;
}
default:
V_51 = V_56 ;
F_3 ( L_21 , ( long ) V_41 ) ;
}
return V_51 ;
}
int F_33 ( unsigned long V_5 , unsigned long V_50 , T_4 V_41 )
{
int V_51 ;
T_5 V_52 ;
T_6 V_53 ;
T_7 V_54 ;
T_8 V_55 ;
switch ( V_41 ) {
case 1 :
V_52 = V_50 ;
V_51 = F_34 ( V_5 , V_52 ) ;
break;
case 2 :
V_53 = V_50 ;
V_51 = F_34 ( V_5 , V_53 ) ;
break;
case 4 :
V_54 = V_50 ;
V_51 = F_34 ( V_5 , V_54 ) ;
break;
case 8 :
if ( V_41 <= sizeof( V_50 ) ) {
V_55 = V_50 ;
V_51 = F_34 ( V_5 , V_55 ) ;
break;
}
default:
V_51 = V_56 ;
F_3 ( L_22 , ( long ) V_41 ) ;
}
return V_51 ;
}
unsigned long F_35 ( const char * V_39 )
{
long V_40 = 0 ;
if ( ! V_39 ) {
V_39 = F_36 ( L_23 ) ;
if ( ! V_39 )
V_39 = L_24 ;
}
while ( * V_39 ) {
switch ( * V_39 ) {
case 'D' :
V_40 |= V_57 ;
break;
case 'R' :
V_40 |= V_58 ;
break;
case 'S' :
V_40 |= V_59 ;
break;
case 'T' :
V_40 |= V_60 ;
break;
case 'C' :
V_40 |= V_61 ;
break;
case 'Z' :
V_40 |= V_62 << 16 ;
break;
case 'E' :
V_40 |= V_63 << 16 ;
break;
case 'U' :
V_40 |= V_64 ;
break;
case 'I' :
V_40 |= V_65 ;
break;
case 'M' :
V_40 |= V_66 ;
break;
case 'A' :
V_40 = ~ 0UL ;
break;
default:
F_3 ( L_25 ,
V_67 , * V_39 ) ;
break;
}
++ V_39 ;
}
return V_40 ;
}
char F_37 ( const struct V_68 * V_69 )
{
int V_70 ;
char V_71 ;
unsigned long V_72 ;
if ( ! V_69 || F_20 ( & V_72 , ( char * ) V_69 , sizeof( unsigned long ) ) )
return 'E' ;
V_70 = F_38 ( V_69 ) ;
V_71 = ( V_69 -> V_71 == 0 ) ? 'R' :
( V_69 -> V_71 < 0 ) ? 'U' :
( V_69 -> V_71 & V_57 ) ? 'D' :
( V_69 -> V_71 & V_60 ) ? 'T' :
( V_69 -> V_71 & V_61 ) ? 'C' :
( V_69 -> V_73 & V_62 ) ? 'Z' :
( V_69 -> V_73 & V_63 ) ? 'E' :
( V_69 -> V_71 & V_59 ) ? 'S' : '?' ;
if ( F_39 ( V_69 ) ) {
if ( ! F_40 ( V_69 ) || V_74 [ V_70 ] . V_75 == 1 ) {
if ( V_70 != V_76 )
V_71 = 'I' ;
}
} else if ( ! V_69 -> V_77 && V_71 == 'S' ) {
V_71 = 'M' ;
}
return V_71 ;
}
unsigned long F_41 ( const struct V_68 * V_69 , unsigned long V_78 )
{
char V_71 [] = { F_37 ( V_69 ) , '\0' } ;
return ( V_78 & F_35 ( V_71 ) ) != 0 ;
}
void F_42 ( const char * V_23 , unsigned long V_79 )
{
T_1 V_2 ;
F_3 ( L_26 , V_23 ) ;
if ( F_5 ( V_79 , & V_2 ) )
F_16 ( V_79 , & V_2 ,
V_30 | V_34 | V_36 ) ;
else
F_3 ( L_27 , V_79 ) ;
}
static int F_43 ( void )
__acquires( T_9 )
{
static int V_80 = - 1 ;
int V_81 ;
if ( V_80 == F_44 () )
V_81 = 1 ;
else
V_81 = 1000 ;
while ( 1 ) {
if ( F_45 ( & T_9 ) ) {
V_80 = - 1 ;
return 1 ;
}
if ( ! V_81 -- )
break;
F_46 ( 1000 ) ;
}
V_80 = F_44 () ;
F_47 ( T_9 ) ;
return 0 ;
}
void * F_7 ( T_4 V_41 , T_3 V_82 )
{
unsigned int V_83 , V_84 ;
struct V_85 * V_86 , * V_87 , * V_88 , * V_89 ;
void * V_69 = NULL ;
if ( ! F_43 () ) {
F_48 ( T_9 ) ;
return NULL ;
}
V_89 = (struct V_85 * ) ( V_90 + V_91 ) ;
if ( V_92 ) {
V_89 -> V_41 = sizeof( V_93 ) - V_94 ;
V_92 = 0 ;
}
V_41 = F_49 ( V_41 , V_95 ) ;
V_88 = V_86 = V_87 = NULL ;
while ( 1 ) {
if ( V_89 -> V_41 >= V_41 && ( ! V_86 || V_89 -> V_41 < V_86 -> V_41 ) ) {
V_86 = V_89 ;
V_87 = V_88 ;
if ( V_89 -> V_41 == V_41 )
break;
}
if ( ! V_89 -> V_96 )
break;
V_88 = V_89 ;
V_89 = (struct V_85 * ) ( V_90 + V_89 -> V_96 ) ;
}
if ( ! V_86 )
goto V_10;
V_83 = V_86 -> V_41 - V_41 ;
if ( V_86 -> V_96 == 0 && V_87 == NULL && V_83 < V_94 )
goto V_10;
if ( V_83 >= V_94 ) {
V_86 -> V_41 = V_41 ;
V_84 = ( ( char * ) V_86 - V_90 ) +
V_94 + V_86 -> V_41 ;
V_89 = (struct V_85 * ) ( V_90 + V_84 ) ;
V_89 -> V_41 = V_83 - V_94 ;
V_89 -> V_96 = V_86 -> V_96 ;
} else
V_84 = V_86 -> V_96 ;
V_86 -> V_97 = F_50 ( 0 ) ;
V_98 += V_86 -> V_41 ;
V_99 = F_51 ( V_98 , V_99 ) ;
if ( V_87 )
V_87 -> V_96 = V_84 ;
else
V_91 = V_84 ;
V_69 = ( char * ) V_86 + V_94 ;
memset ( V_69 , V_100 , V_86 -> V_41 - 1 ) ;
* ( ( char * ) V_69 + V_86 -> V_41 - 1 ) = V_101 ;
V_10:
F_52 ( & T_9 ) ;
return V_69 ;
}
void F_10 ( void * V_69 )
{
struct V_85 * V_89 ;
unsigned int V_84 ;
if ( ! V_69 )
return;
if ( ( char * ) V_69 < V_90 ||
( char * ) V_69 >= V_90 + sizeof( V_93 ) ) {
F_53 ( V_69 ) ;
return;
}
if ( ! F_43 () ) {
F_48 ( T_9 ) ;
return;
}
V_89 = (struct V_85 * ) ( ( char * ) V_69 - V_94 ) ;
memset ( V_69 , V_102 , V_89 -> V_41 - 1 ) ;
* ( ( char * ) V_69 + V_89 -> V_41 - 1 ) = V_101 ;
V_89 -> V_97 = NULL ;
V_98 -= V_89 -> V_41 ;
V_84 = ( char * ) V_89 - V_90 ;
if ( V_84 < V_91 ) {
V_89 -> V_96 = V_91 ;
V_91 = V_84 ;
} else {
struct V_85 * V_88 ;
unsigned int V_103 ;
V_88 = (struct V_85 * ) ( V_90 +
V_91 ) ;
while ( 1 ) {
if ( ! V_88 -> V_96 || V_88 -> V_96 > V_84 )
break;
V_88 = (struct V_85 * )
( V_90 + V_88 -> V_96 ) ;
}
V_103 = ( char * ) V_88 - V_90 ;
if ( V_103 + V_94 + V_88 -> V_41 == V_84 ) {
V_88 -> V_41 += V_94 + V_89 -> V_41 ;
memset ( V_89 , V_102 , V_94 - 1 ) ;
* ( ( char * ) V_89 + V_94 - 1 ) = V_101 ;
V_89 = V_88 ;
V_84 = V_103 ;
} else {
V_89 -> V_96 = V_88 -> V_96 ;
V_88 -> V_96 = V_84 ;
}
}
if ( V_84 + V_94 + V_89 -> V_41 == V_89 -> V_96 ) {
struct V_85 * V_96 ;
V_96 = (struct V_85 * )
( V_90 + V_89 -> V_96 ) ;
V_89 -> V_41 += V_94 + V_96 -> V_41 ;
V_89 -> V_96 = V_96 -> V_96 ;
memset ( V_96 , V_102 , V_94 - 1 ) ;
* ( ( char * ) V_96 + V_94 - 1 ) = V_101 ;
}
F_52 ( & T_9 ) ;
}
void F_54 ( void )
{
struct V_85 * V_104 , * V_105 ;
#ifdef F_55
static int V_106 ;
#else
static int V_106 = 1 ;
#endif
if ( ! F_43 () ) {
F_48 ( T_9 ) ;
return;
}
V_104 = (struct V_85 * ) ( V_90 + V_91 ) ;
if ( V_91 == 0 &&
( V_104 -> V_41 == sizeof( V_93 ) - V_94 ||
V_92 ) )
goto V_10;
if ( ! V_106 )
goto V_10;
V_106 = 0 ;
F_3 ( L_28 ,
V_67 , V_91 ) ;
if ( V_91 ) {
V_105 = (struct V_85 * ) V_90 ;
F_3 ( L_29 , V_67 , V_105 ,
V_105 -> V_41 ) ;
}
do {
V_105 = (struct V_85 * )
( ( char * ) V_104 + V_94 + V_104 -> V_41 ) ;
F_3 ( L_30 ,
V_67 , V_105 , V_105 -> V_41 , V_105 -> V_97 ) ;
V_104 = (struct V_85 * )
( V_90 + V_104 -> V_96 ) ;
} while ( V_104 -> V_96 );
V_105 = (struct V_85 * )
( ( char * ) V_104 + V_94 + V_104 -> V_41 ) ;
if ( ( char * ) V_105 - V_90 !=
sizeof( V_93 ) )
F_3 ( L_30 ,
V_67 , V_105 , V_105 -> V_41 , V_105 -> V_97 ) ;
V_10:
F_52 ( & T_9 ) ;
}
void F_56 ( void )
{
F_57 ( V_107 >= F_9 ( V_108 ) ) ;
V_108 [ V_107 ++ ] = V_109 ;
}
void F_58 ( void )
{
F_57 ( V_107 <= 0 ) ;
V_109 = V_108 [ -- V_107 ] ;
}
