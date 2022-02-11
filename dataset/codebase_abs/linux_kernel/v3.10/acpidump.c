static inline T_1 F_1 ( T_1 * V_1 , T_2 V_2 )
{
T_1 V_3 = 0 , * V_4 = V_1 ;
V_1 += V_2 ;
for (; V_4 < V_1 ; V_3 += * ( V_4 ++ ) ) ;
return V_3 ;
}
static unsigned long F_2 ( void )
{
char V_1 [ 80 ] ;
unsigned long V_5 ;
T_3 * V_6 = fopen ( L_1 , L_2 ) ;
if ( V_6 ) {
while ( fgets ( V_1 , 80 , V_6 ) ) {
if ( sscanf ( V_1 , L_3 , & V_5 ) == 1 )
return V_5 ;
}
fclose ( V_6 ) ;
}
return 0 ;
}
static T_1 * F_3 ( unsigned long V_7 , unsigned V_2 )
{
unsigned long V_8 ;
T_1 * V_9 ;
int V_10 = F_4 ( L_4 , V_11 ) ;
if ( V_10 < 0 ) {
fprintf ( V_12 , L_5 ) ;
exit ( 1 ) ;
}
V_8 = V_7 % V_13 ;
V_9 = F_5 ( NULL , V_2 + V_8 , V_14 , V_15 ,
V_10 , V_7 - V_8 ) ;
F_6 ( V_10 ) ;
if ( V_9 == V_16 ) return 0 ;
return ( V_9 + V_8 ) ;
}
static void F_7 ( T_1 * V_9 , unsigned V_2 )
{
unsigned long V_8 = ( unsigned long ) V_9 % V_13 ;
F_8 ( V_9 - V_8 , V_2 + V_8 ) ;
}
static struct V_17 * F_9 ( unsigned long V_7 , char * V_18 )
{
unsigned V_19 ;
struct V_17 * V_20 = (struct V_17 * )
F_3 ( V_7 , sizeof( struct V_17 ) ) ;
if ( ! V_20 || ( V_18 && memcmp ( V_18 , V_20 -> V_21 , 4 ) ) ) return 0 ;
V_19 = V_20 -> V_2 ;
F_7 ( ( T_1 * ) V_20 , sizeof( struct V_17 ) ) ;
return (struct V_17 * ) F_3 ( V_7 , V_19 ) ;
}
static void F_10 ( struct V_17 * V_20 )
{
F_7 ( ( T_1 * ) V_20 , V_20 -> V_2 ) ;
}
static struct V_22 * F_11 ( T_1 * V_23 , T_2 V_2 )
{
struct V_22 * V_24 ;
T_1 * V_4 , * V_25 = V_23 + V_2 ;
for ( V_4 = V_23 ; V_4 < V_25 ; V_4 += V_26 ) {
if ( memcmp ( ( char * ) V_4 , L_6 , 8 ) ) continue;
V_24 = (struct V_22 * ) V_4 ;
if ( ! F_1 ( ( T_1 * ) V_24 , ( V_24 -> V_27 < 2 ) ?
V_28 :
V_29 ) )
return V_24 ;
}
return 0 ;
}
static void F_12 ( int V_10 , T_1 * V_30 , int V_19 )
{
char V_1 [ 256 ] ;
int V_31 ;
int V_4 , V_32 = V_19 ;
while ( V_32 > 0 ) {
V_31 = snprintf ( V_1 , 256 , L_7 , V_19 - V_32 ) ;
for ( V_4 = 0 ; V_4 < 16 && V_4 < V_32 ; V_4 ++ ) {
V_31 +=
snprintf ( & V_1 [ V_31 ] , 256 - V_31 , L_8 , V_30 [ V_4 ] ) ;
}
for (; V_4 < 16 ; V_4 ++ ) {
V_31 += snprintf ( & V_1 [ V_31 ] , 256 - V_31 , L_9 ) ;
}
V_31 += snprintf ( & V_1 [ V_31 ] , 256 - V_31 , L_10 ) ;
for ( V_4 = 0 ; V_4 < 16 && V_4 < V_32 ; V_4 ++ ) {
V_1 [ V_31 ++ ] = ( isprint ( V_30 [ V_4 ] ) ) ? V_30 [ V_4 ] : '.' ;
}
V_1 [ V_31 ++ ] = '\n' ;
F_13 ( V_10 , V_1 , V_31 ) ;
V_30 += 16 ;
V_32 -= 16 ;
}
}
static void F_14 ( int V_10 , struct V_17 * V_33 , unsigned long V_5 )
{
char V_34 [ 80 ] ;
int V_31 = snprintf ( V_34 , 80 , L_11 , V_33 -> V_21 , ( void * ) V_5 ) ;
F_13 ( V_10 , V_34 , V_31 ) ;
F_12 ( V_10 , ( T_1 * ) V_33 , V_33 -> V_2 ) ;
V_34 [ 0 ] = '\n' ;
F_13 ( V_10 , V_34 , 1 ) ;
}
static void F_15 ( int V_10 , struct V_17 * V_20 , unsigned long V_5 )
{
static int V_35 = 0 ;
if ( ! V_36 [ 0 ] ) {
if ( V_37 ) {
F_14 ( V_10 , V_20 , V_5 ) ;
} else {
F_13 ( V_10 , V_20 , V_20 -> V_2 ) ;
}
} else if ( ! V_35 && ! memcmp ( V_36 , V_20 -> V_21 , 4 ) ) {
if ( V_38 > 0 ) {
-- V_38 ;
return;
}
if ( V_37 ) {
F_14 ( V_10 , V_20 , V_5 ) ;
} else {
F_13 ( V_10 , V_20 , V_20 -> V_2 ) ;
}
V_35 = 1 ;
}
}
static void F_16 ( int V_10 , struct V_17 * V_20 , unsigned long V_39 ) {
struct V_40 V_41 ;
unsigned long V_5 ;
T_4 V_31 = sizeof( struct V_40 ) ;
if ( V_31 > V_20 -> V_2 ) V_31 = V_20 -> V_2 ;
memcpy ( & V_41 , V_20 , V_31 ) ;
V_41 . V_42 . V_2 = V_31 ;
if ( F_1 ( ( T_1 * ) V_20 , V_31 ) ) {
fprintf ( V_12 , L_12 ) ;
}
if ( V_41 . V_42 . V_2 >= 148 && V_41 . V_43 ) {
V_5 = ( unsigned long ) V_41 . V_43 ;
if ( V_44 ) {
V_41 . V_43 = F_17 ( V_10 , 0 , V_45 ) ;
}
} else if ( V_41 . V_42 . V_2 >= 44 && V_41 . V_46 ) {
V_5 = ( unsigned long ) V_41 . V_46 ;
if ( V_44 ) {
V_41 . V_46 = F_17 ( V_10 , 0 , V_45 ) ;
}
} else {
fprintf ( V_12 , L_13 ) ;
goto V_47;
}
V_20 = F_9 ( V_5 , V_48 ) ;
if ( ! V_20 ) goto V_47;
if ( F_1 ( ( T_1 * ) V_20 , V_20 -> V_2 ) )
fprintf ( V_12 , L_14 ) ;
F_15 ( V_10 , V_20 , V_5 ) ;
F_10 ( V_20 ) ;
V_47:
if ( V_41 . V_42 . V_2 >= 140 && V_41 . V_49 ) {
V_5 = ( unsigned long ) V_41 . V_49 ;
if ( V_44 ) {
V_41 . V_49 = F_17 ( V_10 , 0 , V_45 ) ;
}
} else if ( V_41 . V_42 . V_2 >= 40 && V_41 . V_50 ) {
V_5 = ( unsigned long ) V_41 . V_50 ;
if ( V_44 ) {
V_41 . V_50 = F_17 ( V_10 , 0 , V_45 ) ;
}
} else {
fprintf ( V_12 , L_15 ) ;
goto V_51;
}
V_20 = F_9 ( V_5 , V_52 ) ;
if ( ! V_20 ) goto V_51;
F_15 ( V_10 , V_20 , V_5 ) ;
F_10 ( V_20 ) ;
V_51:
F_15 ( V_10 , (struct V_17 * ) & V_41 , V_39 ) ;
}
static int F_18 ( int V_10 , struct V_22 * V_24 )
{
struct V_17 * V_53 , * V_20 = 0 ;
int V_54 = 1 , V_4 , V_55 ;
char * V_8 ;
unsigned long V_5 ;
if ( V_24 -> V_27 > 1 && V_24 -> V_56 ) {
V_20 = F_9 ( V_24 -> V_56 , L_16 ) ;
}
if ( ! V_20 && V_24 -> V_57 ) {
V_54 = 0 ;
V_20 = F_9 ( V_24 -> V_57 , L_17 ) ;
}
if ( ! V_20 ) return 0 ;
V_53 = malloc ( V_20 -> V_2 ) ;
memcpy ( V_53 , V_20 , V_20 -> V_2 ) ;
F_10 ( V_20 ) ;
if ( F_1 ( ( T_1 * ) V_53 , V_53 -> V_2 ) )
fprintf ( V_12 , L_18 , ( V_54 ) ? L_16 : L_17 ) ;
V_55 = ( V_53 -> V_2 - sizeof( struct V_17 ) ) / ( ( V_54 ) ? sizeof( V_58 ) : sizeof( T_2 ) ) ;
V_8 = ( char * ) V_53 + sizeof( struct V_17 ) ;
for ( V_4 = 0 ; V_4 < V_55 ; ++ V_4 , V_8 += ( ( V_54 ) ? sizeof( V_58 ) : sizeof( T_2 ) ) ) {
V_5 = ( V_54 ) ? ( unsigned long ) ( * ( V_58 * ) V_8 ) :
( unsigned long ) ( * ( T_2 * ) V_8 ) ;
if ( ! V_5 ) continue;
V_20 = F_9 ( V_5 , 0 ) ;
if ( ! V_20 ) continue;
if ( ! memcmp ( V_20 -> V_21 , V_59 , 4 ) ) {
F_16 ( V_10 , V_20 , V_5 ) ;
} else {
if ( F_1 ( ( T_1 * ) V_20 , V_20 -> V_2 ) )
fprintf ( V_12 , L_19 ) ;
F_15 ( V_10 , V_20 , V_5 ) ;
}
F_10 ( V_20 ) ;
if ( V_44 ) {
if ( V_54 )
( * ( V_58 * ) V_8 ) = F_17 ( V_10 , 0 , V_45 ) ;
else
( * ( T_2 * ) V_8 ) = F_17 ( V_10 , 0 , V_45 ) ;
}
}
if ( V_54 ) {
V_5 = ( unsigned long ) V_24 -> V_56 ;
if ( V_44 ) {
V_24 -> V_56 = F_17 ( V_10 , 0 , V_45 ) ;
}
} else {
V_5 = ( unsigned long ) V_24 -> V_57 ;
if ( V_44 ) {
V_24 -> V_57 = F_17 ( V_10 , 0 , V_45 ) ;
}
}
F_15 ( V_10 , V_53 , V_5 ) ;
free ( V_53 ) ;
return 1 ;
}
static void F_19 ( int V_10 )
{
struct V_60 V_61 ;
char V_62 [ 256 ] , * V_63 ;
T_5 * V_64 ;
struct V_65 * V_66 ;
T_3 * V_67 ;
int V_68 , V_69 , V_2 ;
struct V_17 V_70 , * V_71 ;
if ( V_60 ( V_72 , & V_61 ) == - 1 ) {
return;
}
V_64 = F_20 ( V_72 ) ;
if( ! V_64 ) {
return;
}
while ( ( V_66 = F_21 ( V_64 ) ) != 0 ) {
if ( V_66 -> V_73 [ 0 ] == '.' )
continue;
sprintf ( V_62 , L_20 , V_72 , V_66 -> V_73 ) ;
V_67 = fopen ( V_62 , L_2 ) ;
if ( V_67 == NULL ) {
fprintf ( V_12 , L_21 ,
V_62 ) ;
continue;
}
V_68 = fread ( & V_70 , 1 , sizeof( struct V_17 ) , V_67 ) ;
if ( V_68 < sizeof( V_70 ) ) {
fclose ( V_67 ) ;
continue;
}
V_2 = V_70 . V_2 ;
V_63 = malloc ( V_70 . V_2 ) ;
fseek ( V_67 , 0 , V_74 ) ;
V_69 = 0 ;
while( ! feof ( V_67 ) && V_69 < V_2 ) {
V_68 = fread ( V_63 + V_69 , 1 , 256 , V_67 ) ;
V_69 += V_68 ;
}
fclose ( V_67 ) ;
V_71 = (struct V_17 * ) V_63 ;
if ( F_1 ( ( T_1 * ) V_71 , V_71 -> V_2 ) )
fprintf ( V_12 , L_22
L_23 ) ;
F_15 ( V_10 , V_71 , 0 ) ;
free ( V_63 ) ;
}
F_22 ( V_64 ) ;
return;
}
static void F_23 ( const char * V_75 )
{
puts ( L_24 ) ;
printf ( L_25
L_26 , V_75 ) ;
puts ( L_27 ) ;
puts ( L_28 ) ;
puts ( L_29 ) ;
puts ( L_30 ) ;
puts ( L_31
L_32 ) ;
puts ( L_33 ) ;
puts ( L_34 ) ;
exit ( 0 ) ;
}
int main ( int V_76 , char * * V_77 )
{
int V_78 , V_79 , V_10 ;
T_1 * V_80 ;
struct V_22 V_81 , * V_41 = 0 ;
char * V_62 = 0 ;
char V_34 [ 80 ] ;
memset ( V_36 , 0 , 4 ) ;
V_37 = 1 ;
V_44 = 0 ;
V_5 = V_2 = 0 ;
V_38 = 0 ;
while ( 1 ) {
V_78 = 0 ;
V_79 = F_24 ( V_76 , V_77 , L_35 ,
V_82 , & V_78 ) ;
if ( V_79 == - 1 )
break;
switch ( V_79 ) {
case 0 :
switch ( V_78 ) {
case 0 :
V_5 = strtoul ( V_83 , ( char * * ) NULL , 16 ) ;
break;
case 1 :
memcpy ( V_36 , V_83 , 4 ) ;
break;
case 2 :
V_62 = V_83 ;
break;
case 3 :
V_37 = 0 ;
break;
case 4 :
V_2 = strtoul ( V_83 , ( char * * ) NULL , 16 ) ;
break;
case 5 :
V_38 = strtoul ( V_83 , ( char * * ) NULL , 10 ) ;
break;
case 6 :
F_23 ( V_77 [ 0 ] ) ;
exit ( 0 ) ;
}
break;
case 'a' :
V_5 = strtoul ( V_83 , ( char * * ) NULL , 16 ) ;
break;
case 't' :
memcpy ( V_36 , V_83 , 4 ) ;
break;
case 'o' :
V_62 = V_83 ;
break;
case 'b' :
V_37 = 0 ;
break;
case 'l' :
V_2 = strtoul ( V_83 , ( char * * ) NULL , 16 ) ;
break;
case 's' :
V_38 = strtoul ( V_83 , ( char * * ) NULL , 10 ) ;
break;
case 'h' :
F_23 ( V_77 [ 0 ] ) ;
exit ( 0 ) ;
default:
printf ( L_36 ) ;
F_23 ( V_77 [ 0 ] ) ;
exit ( 0 ) ;
}
}
V_10 = V_84 ;
if ( V_62 ) {
V_10 = F_25 ( V_62 , V_85 | V_86 | V_87 | V_88 ) ;
if ( V_10 < 0 )
return V_10 ;
}
if ( ! V_36 [ 0 ] && ! V_37 ) {
V_44 = 1 ;
}
V_13 = F_26 ( V_89 ) ;
if ( V_2 && V_5 ) {
if ( ! ( V_80 = F_3 ( V_5 , V_2 ) ) )
goto V_90;
F_13 ( V_10 , V_80 , V_2 ) ;
F_7 ( V_80 , V_2 ) ;
F_6 ( V_10 ) ;
return 0 ;
}
V_2 = sizeof( struct V_22 ) ;
if ( ! V_5 ) {
V_5 = F_2 () ;
if ( ! V_5 ) {
V_5 = V_91 ;
V_2 = V_92 ;
}
}
if ( ! ( V_80 = F_3 ( V_5 , V_2 ) ) ||
! ( V_41 = F_11 ( V_80 , V_2 ) ) )
goto V_90;
memcpy ( & V_81 , V_41 , sizeof( struct V_22 ) ) ;
F_7 ( V_80 , V_2 ) ;
if ( V_44 ) {
F_17 ( V_10 , sizeof( struct V_22 ) , V_74 ) ;
}
if ( ! F_18 ( V_10 , & V_81 ) )
goto V_90;
if ( V_44 ) {
F_17 ( V_10 , 0 , V_74 ) ;
F_13 ( V_10 , V_41 , ( V_81 . V_27 < 2 ) ?
V_28 : V_29 ) ;
} else if ( ! V_36 [ 0 ] || ! memcmp ( L_6 , V_36 , 4 ) ) {
V_5 += ( long ) V_41 - ( long ) V_80 ;
V_2 = snprintf ( V_34 , 80 , L_37 , ( void * ) V_5 ) ;
F_13 ( V_10 , V_34 , V_2 ) ;
F_12 ( V_10 , ( T_1 * ) & V_81 , ( V_81 . V_27 < 2 ) ?
V_28 : V_29 ) ;
V_34 [ 0 ] = '\n' ;
F_13 ( V_10 , V_34 , 1 ) ;
}
F_19 ( V_10 ) ;
F_6 ( V_10 ) ;
return 0 ;
V_90:
F_6 ( V_10 ) ;
fprintf ( V_12 , L_38
L_39
L_40 ) ;
return 1 ;
}
