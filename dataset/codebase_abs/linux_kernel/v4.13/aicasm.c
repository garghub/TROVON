int
main ( int V_1 , char * V_2 [] )
{
extern char * V_3 ;
extern int V_4 ;
int V_5 ;
int V_6 ;
char * V_7 ;
T_1 * V_8 ;
F_1 ( & V_9 ) ;
F_2 ( & V_10 ) ;
F_1 ( & V_11 ) ;
F_3 ( & V_12 ) ;
F_2 ( & V_13 ) ;
V_8 = F_4 () ;
V_8 -> type = V_14 ;
V_15 = 1 ;
V_16 = * V_2 ;
V_17 = NULL ;
V_18 = NULL ;
#if V_19
V_20 = 0 ;
V_21 = 0 ;
V_22 = 0 ;
V_23 = 0 ;
#endif
while ( ( V_5 = F_5 ( V_1 , V_2 , L_1 ) ) != - 1 ) {
switch( V_5 ) {
case 'd' :
#if V_19
if ( strcmp ( V_3 , L_2 ) == 0 ) {
V_20 = 1 ;
V_21 = 1 ;
} else if ( strcmp ( V_3 , L_3 ) == 0 ) {
V_22 = 1 ;
V_23 = 1 ;
} else {
fprintf ( V_24 , L_4
L_5 , V_16 ) ;
F_6 () ;
}
#else
F_7 ( L_6
L_7 , V_25 ) ;
#endif
break;
case 'i' :
V_26 = V_3 ;
break;
case 'l' :
if ( ( V_18 = fopen ( V_3 , L_8 ) ) == NULL ) {
perror ( V_3 ) ;
F_7 ( NULL , V_27 ) ;
}
V_28 = V_3 ;
break;
case 'n' :
if ( strcmp ( V_3 , L_9 ) ) {
fprintf ( V_24 , L_10 ,
V_16 , V_5 , V_3 ) ;
F_6 () ;
}
break;
case 'o' :
if ( ( V_29 = fopen ( V_3 , L_8 ) ) == NULL ) {
perror ( V_3 ) ;
F_7 ( NULL , V_27 ) ;
}
V_30 = V_3 ;
break;
case 'p' :
if ( ( V_31 = fopen ( V_3 , L_8 ) ) == NULL ) {
perror ( V_3 ) ;
F_7 ( NULL , V_27 ) ;
}
V_32 = V_3 ;
break;
case 'r' :
if ( ( V_17 = fopen ( V_3 , L_8 ) ) == NULL ) {
perror ( V_3 ) ;
F_7 ( NULL , V_27 ) ;
}
V_33 = V_3 ;
break;
case 'I' :
{
T_2 V_34 ;
if ( strcmp ( V_3 , L_11 ) == 0 ) {
if ( V_15 == 0 ) {
fprintf ( V_24 , L_12
L_13
L_14 , V_16 ) ;
}
V_15 = 0 ;
for ( V_34 = F_8 ( & V_10 ) ;
V_34 != NULL ;
V_34 = F_9 ( V_34 ,
V_35 ) )
V_34 -> V_36 = 1 ;
} else {
V_34 =
( T_2 ) malloc ( sizeof( * V_34 ) ) ;
if ( V_34 == NULL ) {
perror ( V_3 ) ;
F_7 ( NULL , V_37 ) ;
}
V_34 -> V_38 = F_10 ( V_3 ) ;
if ( V_34 -> V_38 == NULL ) {
perror ( V_3 ) ;
F_7 ( NULL , V_37 ) ;
}
V_34 -> V_36 = 0 ;
F_11 ( & V_10 , V_34 ,
V_35 ) ;
}
break;
}
case '?' :
default:
F_6 () ;
}
}
V_1 -= V_4 ;
V_2 += V_4 ;
if ( V_1 != 1 ) {
fprintf ( V_24 , L_15 , V_16 ) ;
F_6 () ;
}
if ( V_31 != NULL
&& ( V_17 == NULL || V_26 == NULL ) ) {
fprintf ( V_24 ,
L_16 ,
V_16 ) ;
F_6 () ;
}
F_12 () ;
V_7 = * V_2 ;
F_13 ( * V_2 , V_39 ) ;
V_6 = F_14 () ;
if ( V_6 == 0 ) {
if ( F_8 ( & V_13 ) == NULL
|| F_8 ( & V_13 ) -> type != V_14 ) {
F_7 ( L_17 , V_40 ) ;
}
F_15 ( F_8 ( & V_13 ) ) ;
F_16 ( F_8 ( & V_13 ) ) ;
F_17 () ;
if ( V_29 != NULL )
F_18 () ;
if ( V_17 != NULL )
F_19 ( V_17 , V_31 ) ;
if ( V_18 != NULL )
F_20 ( V_7 ) ;
}
F_7 ( NULL , 0 ) ;
return ( 0 ) ;
}
static void
F_6 ()
{
( void ) fprintf ( V_24 ,
L_18
L_19
L_20
L_21 , V_16 ) ;
exit ( V_41 ) ;
}
static void
F_17 ()
{
struct V_42 * V_43 ;
for ( V_43 = F_21 ( & V_11 ) ;
V_43 != NULL ;
V_43 = F_22 ( V_43 , V_35 ) ) {
if ( V_43 -> V_44 != NULL ) {
struct V_45 * V_46 ;
T_3 V_47 ;
if ( V_43 -> V_44 -> type != V_48 ) {
char V_49 [ 255 ] ;
snprintf ( V_49 , sizeof( V_49 ) ,
L_22 ,
V_43 -> V_44 -> V_50 ) ;
F_7 ( V_49 , V_40 ) ;
}
V_46 = & V_43 -> V_51 . V_52 ;
V_47 = V_46 -> V_47 ;
V_47 += V_43 -> V_44 -> V_53 . V_54 -> V_47 ;
V_46 -> V_47 = V_47 ;
}
}
}
static void
F_18 ()
{
struct V_42 * V_43 ;
T_4 * V_55 ;
T_5 * V_56 ;
T_6 * V_57 ;
int V_58 ;
V_58 = 0 ;
fprintf ( V_29 ,
L_23
L_24
L_25
L_26
L_27 , V_59 ) ;
fprintf ( V_29 , L_28 ) ;
for ( V_43 = F_21 ( & V_11 ) ;
V_43 != NULL ;
V_43 = F_22 ( V_43 , V_35 ) ) {
fprintf ( V_29 , L_29 ,
V_43 == F_21 ( & V_11 ) ? L_30 : L_31 ,
#ifdef F_23
V_43 -> V_51 . V_60 [ 0 ] ,
V_43 -> V_51 . V_60 [ 1 ] ,
V_43 -> V_51 . V_60 [ 2 ] ,
V_43 -> V_51 . V_60 [ 3 ] ) ;
#else
V_43 -> V_51 . V_60 [ 3 ] ,
V_43 -> V_51 . V_60 [ 2 ] ,
V_43 -> V_51 . V_60 [ 1 ] ,
V_43 -> V_51 . V_60 [ 0 ] ) ;
#endif
V_58 ++ ;
}
void
F_16 ( T_1 * V_61 )
{
T_1 * V_62 ;
F_24 ( V_61 , 0 ) ;
V_62 = F_25 ( & V_61 -> V_63 ) ;
while ( V_62 != NULL ) {
F_16 ( V_62 ) ;
V_62 = F_26 ( V_62 , V_64 ) ;
}
F_24 ( V_61 , 1 ) ;
}
void
F_24 ( T_1 * V_61 , int V_65 )
{
T_7 * V_66 ;
T_4 * V_67 ;
V_66 = & V_61 -> V_9 [ V_65 ] ;
if ( V_66 -> V_68 == 0 )
return;
V_67 = ( T_4 * ) malloc ( sizeof( * V_67 ) ) ;
if ( V_67 == NULL )
F_7 ( L_32 , V_37 ) ;
memset ( V_67 , 0 , sizeof( * V_67 ) ) ;
if ( V_65 == 0 ) {
V_67 -> V_69 = V_61 -> V_70 ;
V_67 -> V_71 = V_61 -> V_72 ;
} else {
V_67 -> V_69 = 0 ;
V_67 -> V_71 = V_61 -> V_73 ;
}
V_67 -> V_68 = V_66 -> V_68 ;
V_67 -> V_74 = V_66 -> V_74 ;
F_27 ( & V_9 , V_67 , V_35 ) ;
}
void
F_20 ( char * V_75 )
{
char V_49 [ 1024 ] ;
T_8 * V_76 ;
struct V_42 * V_43 ;
T_4 * V_55 ;
T_6 * V_77 ;
int * V_78 ;
int V_58 ;
int V_79 ;
int line ;
int V_80 ;
int V_81 ;
V_58 = 0 ;
V_79 = 0 ;
line = 1 ;
V_81 = 0 ;
if ( ( V_76 = fopen ( V_75 , L_33 ) ) == NULL ) {
perror ( V_75 ) ;
F_7 ( NULL , V_40 ) ;
}
for ( V_80 = 0 , V_77 = F_8 ( & V_82 ) ;
V_77 != NULL ;
V_77 = F_9 ( V_77 , V_35 ) )
V_80 ++ ;
V_78 = NULL ;
if ( V_80 != 0 ) {
V_78 = ( int * ) malloc ( V_80 * sizeof( int ) ) ;
if ( V_78 == NULL )
F_7 ( L_34 , V_37 ) ;
V_78 [ 0 ] = 0 ;
V_80 -- ;
for ( V_77 = F_8 ( & V_82 ) ;
V_77 != NULL && F_9 ( V_77 , V_35 ) != NULL ;
V_77 = F_9 ( V_77 , V_35 ) , V_80 -- ) {
int V_83 ;
fprintf ( stdout , L_35 , V_77 -> V_84 -> V_50 ) ;
fprintf ( stdout ,
L_36
L_37 ) ;
while ( 1 ) {
V_83 = getchar () ;
V_83 = toupper ( V_83 ) ;
if ( V_83 == 'T' ) {
V_78 [ V_80 ] = 1 ;
break;
} else if ( V_83 == 'F' ) {
V_78 [ V_80 ] = 0 ;
break;
}
}
if ( F_28 ( fileno ( V_85 ) ) == 0 )
putchar ( V_83 ) ;
}
fprintf ( stdout , L_38 ) ;
}
V_55 = F_21 ( & V_9 ) ;
for ( V_43 = F_21 ( & V_11 ) ;
V_43 != NULL ;
V_43 = F_22 ( V_43 , V_35 ) , V_58 ++ ) {
if ( F_29 ( & V_55 , V_58 ,
& V_81 , V_78 ) == 0 ) {
continue;
}
while ( line < V_43 -> V_86 ) {
fgets ( V_49 , sizeof( V_49 ) , V_76 ) ;
fprintf ( V_18 , L_39 , V_49 ) ;
line ++ ;
}
fprintf ( V_18 , L_40 , V_79 ,
#ifdef F_23
V_43 -> V_51 . V_60 [ 0 ] ,
V_43 -> V_51 . V_60 [ 1 ] ,
V_43 -> V_51 . V_60 [ 2 ] ,
V_43 -> V_51 . V_60 [ 3 ] ) ;
#else
V_43 -> V_51 . V_60 [ 3 ] ,
V_43 -> V_51 . V_60 [ 2 ] ,
V_43 -> V_51 . V_60 [ 1 ] ,
V_43 -> V_51 . V_60 [ 0 ] ) ;
#endif
if ( line == V_43 -> V_86 ) {
fgets ( V_49 , sizeof( V_49 ) , V_76 ) ;
fprintf ( V_18 , L_41 , V_49 ) ;
line ++ ;
} else {
fprintf ( V_18 , L_42 ) ;
}
V_79 ++ ;
}
int
F_29 ( T_4 * * V_87 , int V_88 ,
int * V_81 , int * V_89 )
{
T_4 * V_55 ;
V_55 = * V_87 ;
while ( V_55 != NULL && V_88 == V_55 -> V_71 ) {
if ( V_89 [ V_55 -> V_69 ] == 0 ) {
int V_90 ;
* V_81 = V_88 + V_55 -> V_68 ;
for ( V_90 = V_55 -> V_74 ;
V_90 > 0 && V_55 != NULL ;
V_90 -- )
V_55 = F_22 ( V_55 , V_35 ) ;
} else {
V_55 = F_22 ( V_55 , V_35 ) ;
}
}
* V_87 = V_55 ;
if ( V_88 < * V_81 )
return ( 0 ) ;
return ( 1 ) ;
}
void
F_7 ( const char * string , int V_91 )
{
if ( string != NULL ) {
fprintf ( V_24 , L_43 , V_16 ) ;
if ( V_92 != NULL ) {
fprintf ( V_24 , L_44 ,
V_92 , V_93 ) ;
}
fprintf ( V_24 , L_45 , string ) ;
}
if ( V_29 != NULL ) {
fclose ( V_29 ) ;
if ( V_91 != 0 ) {
fprintf ( V_24 , L_46 ,
V_16 , V_30 ) ;
F_30 ( V_30 ) ;
}
}
if ( V_17 != NULL ) {
fclose ( V_17 ) ;
if ( V_91 != 0 ) {
fprintf ( V_24 , L_46 ,
V_16 , V_33 ) ;
F_30 ( V_33 ) ;
}
}
if ( V_18 != NULL ) {
fclose ( V_18 ) ;
if ( V_91 != 0 ) {
fprintf ( V_24 , L_46 ,
V_16 , V_28 ) ;
F_30 ( V_28 ) ;
}
}
F_31 ( & V_82 ) ;
F_32 () ;
exit ( V_91 ) ;
}
struct V_42 *
F_33 ()
{
struct V_42 * V_94 ;
V_94 = (struct V_42 * ) malloc ( sizeof( struct V_42 ) ) ;
if ( V_94 == NULL )
F_7 ( L_47 , V_25 ) ;
memset ( V_94 , 0 , sizeof( * V_94 ) ) ;
F_27 ( & V_11 , V_94 , V_35 ) ;
V_94 -> V_86 = V_93 ;
return V_94 ;
}
T_5 *
F_34 ()
{
T_5 * V_95 ;
V_95 = ( T_5 * ) malloc ( sizeof( T_5 ) ) ;
if ( V_95 == NULL )
F_7 ( L_48 , V_25 ) ;
memset ( V_95 , 0 , sizeof( * V_95 ) ) ;
F_35 ( & V_12 , V_95 , V_35 ) ;
return V_95 ;
}
T_1 *
F_4 ()
{
T_1 * V_96 ;
V_96 = ( T_1 * ) malloc ( sizeof( T_1 ) ) ;
if ( V_96 == NULL )
F_7 ( L_49 , V_25 ) ;
memset ( V_96 , 0 , sizeof( * V_96 ) ) ;
F_3 ( & V_96 -> V_63 ) ;
if ( F_8 ( & V_13 ) != NULL ) {
F_35 ( & F_8 ( & V_13 ) -> V_63 ,
V_96 , V_64 ) ;
}
F_11 ( & V_13 , V_96 , V_97 ) ;
return V_96 ;
}
void
F_15 ( T_1 * V_61 )
{
T_1 * V_62 ;
T_3 V_98 ;
T_3 V_99 ;
V_62 = F_36 ( & V_61 -> V_63 , V_100 ) ;
V_98 = 0 ;
V_99 = 0 ;
while ( V_62 != NULL ) {
T_3 V_101 ;
V_101 = 0 ;
switch ( V_62 -> type ) {
case V_102 :
case V_103 :
if ( V_99 != 0 ) {
V_101 ++ ;
V_62 -> V_9 [ 1 ] . V_74 =
V_98 + 1 ;
V_62 -> V_9 [ 1 ] . V_68 =
V_99 ;
}
V_101 ++ ;
V_101 += V_62 -> V_104 ;
V_62 -> V_9 [ 0 ] . V_74 = V_101 ;
V_62 -> V_9 [ 0 ] . V_68 =
V_62 -> V_73 - V_62 -> V_72 ;
V_99 += V_62 -> V_9 [ 0 ] . V_68 ;
V_98 += V_101 ;
if ( V_62 -> type == V_102 ) {
V_61 -> V_104 += V_98 ;
V_98 = 0 ;
V_99 = 0 ;
}
break;
case V_105 :
V_98 += V_62 -> V_104 ;
V_99 += V_62 -> V_73
- V_62 -> V_72 ;
break;
case V_14 :
F_7 ( L_50 , V_25 ) ;
}
V_62 = F_37 ( V_62 , V_100 , V_64 ) ;
}
}
