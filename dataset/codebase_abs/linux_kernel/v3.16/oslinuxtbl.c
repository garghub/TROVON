static T_1 F_1 ( T_1 V_1 )
{
switch ( V_2 ) {
case V_3 :
case V_4 :
return ( V_5 ) ;
case V_6 :
return ( V_7 ) ;
case V_8 :
return ( V_9 ) ;
default:
return ( V_1 ) ;
}
}
T_1
F_2 ( T_2 V_10 ,
struct V_11 * * V_12 )
{
T_3 V_13 ;
struct V_11 * V_14 ;
struct V_11 * V_15 = NULL ;
T_1 V_16 = V_17 ;
V_16 = F_3 () ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
V_16 = F_5 ( V_10 , NULL , & V_14 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
V_13 = F_6 ( V_14 ) ;
if ( V_13 == 0 ) {
V_16 = V_18 ;
goto exit;
}
V_15 = calloc ( 1 , V_13 ) ;
if ( ! V_15 ) {
V_16 = V_9 ;
goto exit;
}
F_7 ( V_15 , V_14 , V_13 ) ;
exit:
F_8 ( V_14 ) ;
* V_12 = V_15 ;
return ( V_16 ) ;
}
T_1
F_9 ( char * V_19 ,
T_3 V_20 ,
struct V_11 * * V_12 ,
T_2 * V_10 )
{
T_1 V_16 ;
V_16 = F_3 () ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
if ( ! V_21 ) {
V_16 =
F_10 ( V_19 , V_20 , V_12 , V_10 ) ;
} else {
V_16 = F_11 ( V_22 , V_19 ,
V_20 , V_12 , V_10 ) ;
}
if ( F_4 ( V_16 ) && V_16 == V_23 ) {
if ( V_24 ) {
V_16 =
F_11 ( V_25 ,
V_19 , V_20 , V_12 ,
V_10 ) ;
}
}
return ( V_16 ) ;
}
static T_1 F_12 ( char * V_19 , T_3 V_20 )
{
struct V_26 * V_27 ;
struct V_26 * V_28 ;
T_3 V_29 = 0 ;
T_4 V_30 = FALSE ;
V_27 = calloc ( 1 , sizeof( struct V_26 ) ) ;
if ( ! V_27 ) {
return ( V_9 ) ;
}
F_13 ( V_27 -> V_19 , V_19 ) ;
if ( ! V_31 ) {
V_31 = V_27 ;
} else {
V_28 = V_31 ;
while ( 1 ) {
if ( F_14 ( V_28 -> V_19 , V_19 ) ) {
if ( V_28 -> V_20 == V_20 ) {
V_30 = TRUE ;
}
if ( V_28 -> V_20 >= V_29 ) {
V_29 = V_28 -> V_20 + 1 ;
}
}
if ( ! V_28 -> V_28 ) {
break;
}
V_28 = V_28 -> V_28 ;
}
V_28 -> V_28 = V_27 ;
}
if ( V_30 ) {
if ( V_20 ) {
fprintf ( V_32 ,
L_1 ,
V_19 , V_20 , V_29 ) ;
}
V_20 = V_29 ;
}
V_27 -> V_20 = V_20 ;
V_33 ++ ;
return ( V_17 ) ;
}
T_1
F_15 ( T_3 V_34 ,
struct V_11 * * V_12 ,
T_3 * V_20 , T_2 * V_10 )
{
struct V_26 * V_35 ;
T_1 V_16 ;
T_3 V_36 ;
V_16 = F_3 () ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
if ( V_34 >= V_33 ) {
return ( V_23 ) ;
}
V_35 = V_31 ;
for ( V_36 = 0 ; V_36 < V_34 ; V_36 ++ ) {
V_35 = V_35 -> V_28 ;
}
V_16 = F_9 ( V_35 -> V_19 , V_35 -> V_20 ,
V_12 , V_10 ) ;
if ( F_16 ( V_16 ) ) {
* V_20 = V_35 -> V_20 ;
}
return ( V_16 ) ;
}
static T_2 F_17 ( void )
{
T_5 * V_37 ;
char V_38 [ 80 ] ;
unsigned long V_10 = 0 ;
V_37 = fopen ( V_39 , L_2 ) ;
if ( V_37 ) {
while ( fgets ( V_38 , 80 , V_37 ) ) {
if ( sscanf ( V_38 , L_3 , & V_10 ) == 1 ) {
break;
}
}
fclose ( V_37 ) ;
}
return ( ( T_2 ) ( V_10 ) ) ;
}
static T_1 F_18 ( void )
{
struct V_11 * V_14 ;
T_4 * V_40 ;
T_2 V_41 ;
T_6 V_42 ;
V_42 = sizeof( struct V_43 ) ;
if ( V_44 ) {
V_41 = V_44 ;
} else {
V_41 = F_17 () ;
}
if ( ! V_41 ) {
V_41 = V_45 ;
V_42 = V_46 ;
}
V_40 = F_19 ( V_41 , V_42 ) ;
if ( ! V_40 ) {
return ( F_1 ( V_47 ) ) ;
}
V_14 = F_20 ( struct V_11 ,
F_21 ( V_40 ,
V_42 ) ) ;
if ( ! V_14 ) {
F_22 ( V_40 , V_42 ) ;
return ( V_7 ) ;
}
V_48 =
V_41 + ( F_23 ( V_14 ) - V_40 ) ;
F_7 ( & V_49 , V_14 , sizeof( struct V_43 ) ) ;
F_22 ( V_40 , V_42 ) ;
return ( V_17 ) ;
}
static T_4 F_24 ( void )
{
if ( V_50 && ! V_51 ) {
return ( TRUE ) ;
} else {
return ( FALSE ) ;
}
}
static T_1 F_3 ( void )
{
T_1 V_16 ;
T_2 V_10 ;
if ( V_52 ) {
return ( V_17 ) ;
}
V_16 = F_18 () ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
if ( V_49 . V_53 && ! V_54 ) {
if ( V_55 ) {
free ( V_55 ) ;
V_55 = NULL ;
}
V_50 = 2 ;
V_16 = F_10 ( V_56 , 0 ,
F_20 ( struct
V_11 * ,
& V_55 ) , & V_10 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
}
if ( V_49 . V_57 ) {
if ( V_58 ) {
free ( V_58 ) ;
V_58 = NULL ;
}
V_16 = F_10 ( V_59 , 0 ,
F_20 ( struct
V_11 * ,
& V_58 ) , & V_10 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
}
if ( V_60 ) {
free ( V_60 ) ;
V_60 = NULL ;
}
V_16 = F_10 ( V_61 , 0 ,
F_20 ( struct V_11 * ,
& V_60 ) ,
& V_62 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
if ( ! V_21 ) {
V_16 = F_12 ( V_63 , 0 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
V_16 = F_12 ( V_59 , 0 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
if ( V_50 == 2 ) {
V_16 = F_12 ( V_56 , 0 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
}
V_16 = F_12 ( V_64 , 0 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
V_16 = F_12 ( V_65 , 0 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
V_16 = F_25 () ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
} else {
V_16 = F_26 ( V_22 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
}
if ( V_24 ) {
V_16 = F_26 ( V_25 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
}
V_52 = TRUE ;
return ( V_17 ) ;
}
static T_1 F_25 ( void )
{
struct V_11 * V_14 = NULL ;
T_4 * V_66 ;
T_4 V_67 ;
T_4 V_68 ;
T_2 V_69 = 0 ;
T_1 V_16 = V_17 ;
T_3 V_36 ;
if ( F_24 () ) {
V_68 = sizeof( V_70 ) ;
V_66 =
F_23 ( V_55 ) + sizeof( struct V_11 ) ;
V_67 =
( T_4 ) ( ( V_55 -> V_71 . V_72 -
sizeof( struct V_11 ) )
/ V_68 ) ;
} else {
V_68 = sizeof( T_3 ) ;
V_66 =
F_23 ( V_58 ) + sizeof( struct V_11 ) ;
V_67 =
( T_4 ) ( ( V_58 -> V_71 . V_72 -
sizeof( struct V_11 ) )
/ V_68 ) ;
}
for ( V_36 = 0 ; V_36 < V_67 ; ++ V_36 , V_66 += V_68 ) {
if ( F_24 () ) {
V_69 =
( T_2 ) ( * F_27 ( V_66 ) ) ;
} else {
V_69 =
( T_2 ) ( * F_28 ( V_66 ) ) ;
}
if ( ! V_69 ) {
continue;
}
V_16 = F_5 ( V_69 , NULL , & V_14 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
F_12 ( V_14 -> V_19 , 0 ) ;
F_8 ( V_14 ) ;
}
return ( V_17 ) ;
}
static T_1
F_10 ( char * V_19 ,
T_3 V_20 ,
struct V_11 * * V_12 ,
T_2 * V_10 )
{
struct V_11 * V_15 = NULL ;
struct V_11 * V_14 = NULL ;
T_4 * V_66 ;
T_4 V_67 ;
T_4 V_68 ;
T_3 V_73 = 0 ;
T_2 V_69 = 0 ;
T_3 V_13 = 0 ;
T_1 V_16 = V_17 ;
T_3 V_36 ;
if ( F_14 ( V_19 , V_63 ) ||
F_14 ( V_19 , V_59 ) ||
F_14 ( V_19 , V_56 ) ||
F_14 ( V_19 , V_64 ) ||
F_14 ( V_19 , V_65 ) ) {
if ( V_20 > 0 ) {
return ( V_23 ) ;
}
if ( F_14 ( V_19 , V_64 ) ) {
if ( ( V_60 -> V_71 . V_72 >= V_74 ) &&
V_60 -> V_75 ) {
V_69 =
( T_2 ) V_60 -> V_75 ;
} else
if ( ( V_60 -> V_71 . V_72 >= V_76 )
&& V_60 -> V_77 ) {
V_69 =
( T_2 ) V_60 -> V_77 ;
}
} else if ( F_14 ( V_19 , V_65 ) ) {
if ( ( V_60 -> V_71 . V_72 >= V_78 ) &&
V_60 -> V_79 ) {
V_69 =
( T_2 ) V_60 -> V_79 ;
} else
if ( ( V_60 -> V_71 . V_72 >= V_80 )
&& V_60 -> V_81 ) {
V_69 =
( T_2 ) V_60 -> V_81 ;
}
} else if ( F_14 ( V_19 , V_56 ) ) {
if ( ! V_50 ) {
return ( V_82 ) ;
}
V_69 =
( T_2 ) V_49 .
V_83 ;
} else if ( F_14 ( V_19 , V_59 ) ) {
V_69 =
( T_2 ) V_49 .
V_57 ;
} else {
V_69 =
( T_2 ) V_48 ;
V_19 = V_84 ;
}
V_16 = F_5 ( V_69 , V_19 , & V_14 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
V_13 = F_6 ( V_14 ) ;
} else {
if ( F_24 () ) {
V_68 = sizeof( V_70 ) ;
V_66 =
F_23 ( V_55 ) +
sizeof( struct V_11 ) ;
V_67 =
( T_4 ) ( ( V_55 -> V_71 . V_72 -
sizeof( struct V_11 ) )
/ V_68 ) ;
} else {
V_68 = sizeof( T_3 ) ;
V_66 =
F_23 ( V_58 ) +
sizeof( struct V_11 ) ;
V_67 =
( T_4 ) ( ( V_58 -> V_71 . V_72 -
sizeof( struct V_11 ) )
/ V_68 ) ;
}
for ( V_36 = 0 ; V_36 < V_67 ; ++ V_36 , V_66 += V_68 ) {
if ( F_24 () ) {
V_69 =
( T_2 ) ( * F_27
( V_66 ) ) ;
} else {
V_69 =
( T_2 ) ( * F_28
( V_66 ) ) ;
}
if ( ! V_69 ) {
continue;
}
V_16 =
F_5 ( V_69 , NULL , & V_14 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
V_13 = V_14 -> V_72 ;
if ( ! F_14
( V_14 -> V_19 , V_19 ) ) {
F_8 ( V_14 ) ;
V_14 = NULL ;
continue;
}
if ( V_73 != V_20 ) {
F_8 ( V_14 ) ;
V_14 = NULL ;
V_73 ++ ;
continue;
}
break;
}
}
if ( ! V_14 ) {
return ( V_23 ) ;
}
if ( V_13 == 0 ) {
V_16 = V_18 ;
goto exit;
}
V_15 = calloc ( 1 , V_13 ) ;
if ( ! V_15 ) {
V_16 = V_9 ;
goto exit;
}
F_7 ( V_15 , V_14 , V_13 ) ;
* V_10 = V_69 ;
* V_12 = V_15 ;
exit:
F_8 ( V_14 ) ;
return ( V_16 ) ;
}
static T_1 F_26 ( char * V_85 )
{
void * V_86 ;
T_3 V_20 ;
char V_87 [ V_88 ] ;
char * V_89 ;
T_1 V_16 = V_17 ;
V_86 = F_29 ( V_85 , L_4 , V_90 ) ;
if ( ! V_86 ) {
return ( F_1 ( V_7 ) ) ;
}
while ( ( V_89 = F_30 ( V_86 ) ) ) {
V_16 =
F_31 ( V_89 , V_87 , & V_20 ) ;
if ( F_4 ( V_16 ) ) {
continue;
}
V_16 = F_12 ( V_87 , V_20 ) ;
if ( F_4 ( V_16 ) ) {
break;
}
}
F_32 ( V_86 ) ;
return ( V_16 ) ;
}
static T_1
F_5 ( T_6 V_10 ,
char * V_19 , struct V_11 * * V_12 )
{
struct V_11 * V_14 ;
T_3 V_72 ;
if ( ! V_10 ) {
return ( V_47 ) ;
}
V_14 =
F_19 ( V_10 , sizeof( struct V_11 ) ) ;
if ( ! V_14 ) {
fprintf ( V_32 , L_5 ,
F_33 ( V_10 ) ) ;
return ( F_1 ( V_47 ) ) ;
}
if ( V_19 ) {
if ( F_34 ( V_19 ) ) {
if ( ! F_34 ( V_14 -> V_19 ) ) {
F_22 ( V_14 ,
sizeof( struct
V_11 ) ) ;
return ( V_82 ) ;
}
} else
if ( ! F_14 ( V_19 , V_14 -> V_19 ) )
{
F_22 ( V_14 ,
sizeof( struct V_11 ) ) ;
return ( V_82 ) ;
}
}
V_72 = F_6 ( V_14 ) ;
F_22 ( V_14 , sizeof( struct V_11 ) ) ;
if ( V_72 == 0 ) {
return ( V_18 ) ;
}
V_14 = F_19 ( V_10 , V_72 ) ;
if ( ! V_14 ) {
fprintf ( V_32 ,
L_6 ,
F_33 ( V_10 ) , V_72 ) ;
return ( F_1 ( V_91 ) ) ;
}
( void ) F_35 ( V_14 ) ;
* V_12 = V_14 ;
return ( V_17 ) ;
}
static void F_8 ( struct V_11 * V_12 )
{
if ( V_12 ) {
F_22 ( V_12 , F_6 ( V_12 ) ) ;
}
}
static T_1
F_31 ( char * V_89 , char * V_19 , T_3 * V_20 )
{
if ( strlen ( V_89 ) < V_88 ) {
return ( V_82 ) ;
}
if ( isdigit ( ( int ) V_89 [ V_88 ] ) ) {
sscanf ( & V_89 [ V_88 ] , L_7 , V_20 ) ;
} else if ( strlen ( V_89 ) != V_88 ) {
return ( V_82 ) ;
} else {
* V_20 = 0 ;
}
F_13 ( V_19 , V_89 ) ;
return ( V_17 ) ;
}
static T_1
F_36 ( char * V_89 ,
T_6 V_92 ,
char * V_19 , struct V_11 * * V_12 )
{
T_5 * V_93 ;
struct V_11 V_71 ;
struct V_11 * V_15 = NULL ;
T_3 V_13 ;
T_7 V_94 ;
T_1 V_16 = V_17 ;
V_93 = fopen ( V_89 , L_8 ) ;
if ( V_93 == NULL ) {
fprintf ( V_32 , L_9 , V_89 ) ;
return ( F_1 ( V_7 ) ) ;
}
fseek ( V_93 , V_92 , V_95 ) ;
V_94 = fread ( & V_71 , 1 , sizeof( struct V_11 ) , V_93 ) ;
if ( V_94 != sizeof( struct V_11 ) ) {
fprintf ( V_32 , L_10 , V_89 ) ;
V_16 = V_18 ;
goto exit;
}
if ( V_19 ) {
if ( F_34 ( V_19 ) ) {
if ( ! F_34 ( V_71 . V_19 ) ) {
fprintf ( V_32 ,
L_11 ,
V_71 . V_19 ) ;
V_16 = V_82 ;
goto exit;
}
} else if ( ! F_14 ( V_19 , V_71 . V_19 ) ) {
fprintf ( V_32 ,
L_12 ,
V_19 , V_71 . V_19 ) ;
V_16 = V_82 ;
goto exit;
}
}
V_13 = F_6 ( & V_71 ) ;
if ( V_13 == 0 ) {
V_16 = V_18 ;
goto exit;
}
V_15 = calloc ( 1 , V_13 ) ;
if ( ! V_15 ) {
fprintf ( V_32 ,
L_13 ,
V_71 . V_19 , V_13 ) ;
V_16 = V_9 ;
goto exit;
}
fseek ( V_93 , V_92 , V_95 ) ;
V_94 = fread ( V_15 , 1 , V_13 , V_93 ) ;
if ( V_94 != V_13 ) {
fprintf ( V_32 , L_14 ,
V_71 . V_19 ) ;
V_16 = V_91 ;
goto exit;
}
( void ) F_35 ( V_15 ) ;
exit:
fclose ( V_93 ) ;
* V_12 = V_15 ;
return ( V_16 ) ;
}
static T_1
F_11 ( char * V_96 ,
char * V_19 ,
T_3 V_20 ,
struct V_11 * * V_12 ,
T_2 * V_10 )
{
void * V_86 ;
T_3 V_73 = 0 ;
char V_87 [ V_88 ] ;
char V_97 [ V_98 ] ;
char * V_89 ;
T_1 V_16 ;
V_86 = F_29 ( V_96 , L_4 , V_90 ) ;
if ( ! V_86 ) {
return ( F_1 ( V_7 ) ) ;
}
while ( ( V_89 = F_30 ( V_86 ) ) ) {
if ( ! F_14 ( V_89 , V_19 ) ) {
continue;
}
V_16 =
F_31 ( V_89 , V_87 ,
& V_73 ) ;
if ( F_4 ( V_16 ) || V_73 != V_20 ) {
continue;
}
if ( V_20 != 0 ) {
sprintf ( V_97 , L_15 , V_96 ,
V_87 , V_20 ) ;
} else {
sprintf ( V_97 , L_16 , V_96 ,
V_87 ) ;
}
break;
}
F_32 ( V_86 ) ;
if ( ! V_89 ) {
return ( V_23 ) ;
}
* V_10 = 0 ;
V_16 = F_36 ( V_97 , 0 , NULL , V_12 ) ;
return ( V_16 ) ;
}
