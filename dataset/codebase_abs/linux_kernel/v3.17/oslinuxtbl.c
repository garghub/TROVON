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
static T_2
F_17 ( T_5 * V_37 , const char * V_38 )
{
char V_39 [ 80 ] ;
unsigned long long V_10 = 0 ;
char V_40 [ 32 ] ;
snprintf ( V_40 , 32 , L_2 , V_38 , L_3 ) ;
fseek ( V_37 , 0 , V_41 ) ;
while ( fgets ( V_39 , 80 , V_37 ) ) {
if ( sscanf ( V_39 , V_40 , & V_10 ) == 1 ) {
break;
}
}
return ( ( T_2 ) ( V_10 ) ) ;
}
static T_2 F_18 ( void )
{
T_5 * V_37 ;
T_2 V_10 = 0 ;
V_37 = fopen ( V_42 , L_4 ) ;
if ( V_37 ) {
V_10 = F_17 ( V_37 , L_5 ) ;
if ( ! V_10 ) {
V_10 =
F_17 ( V_37 , L_6 ) ;
}
fclose ( V_37 ) ;
}
return ( V_10 ) ;
}
static T_1 F_19 ( void )
{
struct V_11 * V_14 ;
T_4 * V_43 ;
T_2 V_44 ;
T_6 V_45 ;
V_45 = sizeof( struct V_46 ) ;
if ( V_47 ) {
V_44 = V_47 ;
} else {
V_44 = F_18 () ;
}
if ( ! V_44 ) {
V_44 = V_48 ;
V_45 = V_49 ;
}
V_43 = F_20 ( V_44 , V_45 ) ;
if ( ! V_43 ) {
return ( F_1 ( V_50 ) ) ;
}
V_14 = F_21 ( struct V_11 ,
F_22 ( V_43 ,
V_45 ) ) ;
if ( ! V_14 ) {
F_23 ( V_43 , V_45 ) ;
return ( V_7 ) ;
}
V_51 =
V_44 + ( F_24 ( V_14 ) - V_43 ) ;
F_7 ( & V_52 , V_14 , sizeof( struct V_46 ) ) ;
F_23 ( V_43 , V_45 ) ;
return ( V_17 ) ;
}
static T_4 F_25 ( void )
{
if ( V_53 && ! V_54 ) {
return ( TRUE ) ;
} else {
return ( FALSE ) ;
}
}
static T_1 F_3 ( void )
{
T_1 V_16 ;
T_2 V_10 ;
if ( V_55 ) {
return ( V_17 ) ;
}
V_16 = F_19 () ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
if ( V_52 . V_56 && ! V_57 ) {
if ( V_58 ) {
free ( V_58 ) ;
V_58 = NULL ;
}
V_53 = 2 ;
V_16 = F_10 ( V_59 , 0 ,
F_21 ( struct
V_11 * ,
& V_58 ) , & V_10 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
}
if ( V_52 . V_60 ) {
if ( V_61 ) {
free ( V_61 ) ;
V_61 = NULL ;
}
V_16 = F_10 ( V_62 , 0 ,
F_21 ( struct
V_11 * ,
& V_61 ) , & V_10 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
}
if ( V_63 ) {
free ( V_63 ) ;
V_63 = NULL ;
}
V_16 = F_10 ( V_64 , 0 ,
F_21 ( struct V_11 * ,
& V_63 ) ,
& V_65 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
if ( ! V_21 ) {
V_16 = F_12 ( V_66 , 0 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
V_16 = F_12 ( V_62 , 0 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
if ( V_53 == 2 ) {
V_16 = F_12 ( V_59 , 0 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
}
V_16 = F_12 ( V_67 , 0 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
V_16 = F_12 ( V_68 , 0 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
V_16 = F_26 () ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
} else {
V_16 = F_27 ( V_22 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
}
if ( V_24 ) {
V_16 = F_27 ( V_25 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
}
V_55 = TRUE ;
return ( V_17 ) ;
}
static T_1 F_26 ( void )
{
struct V_11 * V_14 = NULL ;
T_4 * V_69 ;
T_4 V_70 ;
T_4 V_71 ;
T_2 V_72 = 0 ;
T_1 V_16 = V_17 ;
T_3 V_36 ;
if ( F_25 () ) {
V_71 = sizeof( V_73 ) ;
V_69 =
F_24 ( V_58 ) + sizeof( struct V_11 ) ;
V_70 =
( T_4 ) ( ( V_58 -> V_74 . V_75 -
sizeof( struct V_11 ) )
/ V_71 ) ;
} else {
V_71 = sizeof( T_3 ) ;
V_69 =
F_24 ( V_61 ) + sizeof( struct V_11 ) ;
V_70 =
( T_4 ) ( ( V_61 -> V_74 . V_75 -
sizeof( struct V_11 ) )
/ V_71 ) ;
}
for ( V_36 = 0 ; V_36 < V_70 ; ++ V_36 , V_69 += V_71 ) {
if ( F_25 () ) {
V_72 =
( T_2 ) ( * F_28 ( V_69 ) ) ;
} else {
V_72 =
( T_2 ) ( * F_29 ( V_69 ) ) ;
}
if ( ! V_72 ) {
continue;
}
V_16 = F_5 ( V_72 , NULL , & V_14 ) ;
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
T_4 * V_69 ;
T_4 V_70 ;
T_4 V_71 ;
T_3 V_76 = 0 ;
T_2 V_72 = 0 ;
T_3 V_13 = 0 ;
T_1 V_16 = V_17 ;
T_3 V_36 ;
if ( F_14 ( V_19 , V_66 ) ||
F_14 ( V_19 , V_62 ) ||
F_14 ( V_19 , V_59 ) ||
F_14 ( V_19 , V_67 ) ||
F_14 ( V_19 , V_68 ) ) {
if ( V_20 > 0 ) {
return ( V_23 ) ;
}
if ( F_14 ( V_19 , V_67 ) ) {
if ( ( V_63 -> V_74 . V_75 >= V_77 ) &&
V_63 -> V_78 ) {
V_72 =
( T_2 ) V_63 -> V_78 ;
} else
if ( ( V_63 -> V_74 . V_75 >= V_79 )
&& V_63 -> V_80 ) {
V_72 =
( T_2 ) V_63 -> V_80 ;
}
} else if ( F_14 ( V_19 , V_68 ) ) {
if ( ( V_63 -> V_74 . V_75 >= V_81 ) &&
V_63 -> V_82 ) {
V_72 =
( T_2 ) V_63 -> V_82 ;
} else
if ( ( V_63 -> V_74 . V_75 >= V_83 )
&& V_63 -> V_84 ) {
V_72 =
( T_2 ) V_63 -> V_84 ;
}
} else if ( F_14 ( V_19 , V_59 ) ) {
if ( ! V_53 ) {
return ( V_85 ) ;
}
V_72 =
( T_2 ) V_52 .
V_86 ;
} else if ( F_14 ( V_19 , V_62 ) ) {
V_72 =
( T_2 ) V_52 .
V_60 ;
} else {
V_72 =
( T_2 ) V_51 ;
V_19 = V_87 ;
}
V_16 = F_5 ( V_72 , V_19 , & V_14 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
V_13 = F_6 ( V_14 ) ;
} else {
if ( F_25 () ) {
V_71 = sizeof( V_73 ) ;
V_69 =
F_24 ( V_58 ) +
sizeof( struct V_11 ) ;
V_70 =
( T_4 ) ( ( V_58 -> V_74 . V_75 -
sizeof( struct V_11 ) )
/ V_71 ) ;
} else {
V_71 = sizeof( T_3 ) ;
V_69 =
F_24 ( V_61 ) +
sizeof( struct V_11 ) ;
V_70 =
( T_4 ) ( ( V_61 -> V_74 . V_75 -
sizeof( struct V_11 ) )
/ V_71 ) ;
}
for ( V_36 = 0 ; V_36 < V_70 ; ++ V_36 , V_69 += V_71 ) {
if ( F_25 () ) {
V_72 =
( T_2 ) ( * F_28
( V_69 ) ) ;
} else {
V_72 =
( T_2 ) ( * F_29
( V_69 ) ) ;
}
if ( ! V_72 ) {
continue;
}
V_16 =
F_5 ( V_72 , NULL , & V_14 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
V_13 = V_14 -> V_75 ;
if ( ! F_14
( V_14 -> V_19 , V_19 ) ) {
F_8 ( V_14 ) ;
V_14 = NULL ;
continue;
}
if ( V_76 != V_20 ) {
F_8 ( V_14 ) ;
V_14 = NULL ;
V_76 ++ ;
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
* V_10 = V_72 ;
* V_12 = V_15 ;
exit:
F_8 ( V_14 ) ;
return ( V_16 ) ;
}
static T_1 F_27 ( char * V_88 )
{
void * V_89 ;
T_3 V_20 ;
char V_90 [ V_91 ] ;
char * V_92 ;
T_1 V_16 = V_17 ;
V_89 = F_30 ( V_88 , L_7 , V_93 ) ;
if ( ! V_89 ) {
return ( F_1 ( V_7 ) ) ;
}
while ( ( V_92 = F_31 ( V_89 ) ) ) {
V_16 =
F_32 ( V_92 , V_90 , & V_20 ) ;
if ( F_4 ( V_16 ) ) {
continue;
}
V_16 = F_12 ( V_90 , V_20 ) ;
if ( F_4 ( V_16 ) ) {
break;
}
}
F_33 ( V_89 ) ;
return ( V_16 ) ;
}
static T_1
F_5 ( T_6 V_10 ,
char * V_19 , struct V_11 * * V_12 )
{
struct V_11 * V_14 ;
T_3 V_75 ;
if ( ! V_10 ) {
return ( V_50 ) ;
}
V_14 =
F_20 ( V_10 , sizeof( struct V_11 ) ) ;
if ( ! V_14 ) {
fprintf ( V_32 , L_8 ,
F_34 ( V_10 ) ) ;
return ( F_1 ( V_50 ) ) ;
}
if ( V_19 ) {
if ( F_35 ( V_19 ) ) {
if ( ! F_35 ( V_14 -> V_19 ) ) {
F_23 ( V_14 ,
sizeof( struct
V_11 ) ) ;
return ( V_85 ) ;
}
} else
if ( ! F_14 ( V_19 , V_14 -> V_19 ) )
{
F_23 ( V_14 ,
sizeof( struct V_11 ) ) ;
return ( V_85 ) ;
}
}
V_75 = F_6 ( V_14 ) ;
F_23 ( V_14 , sizeof( struct V_11 ) ) ;
if ( V_75 == 0 ) {
return ( V_18 ) ;
}
V_14 = F_20 ( V_10 , V_75 ) ;
if ( ! V_14 ) {
fprintf ( V_32 ,
L_9 ,
F_34 ( V_10 ) , V_75 ) ;
return ( F_1 ( V_94 ) ) ;
}
( void ) F_36 ( V_14 ) ;
* V_12 = V_14 ;
return ( V_17 ) ;
}
static void F_8 ( struct V_11 * V_12 )
{
if ( V_12 ) {
F_23 ( V_12 , F_6 ( V_12 ) ) ;
}
}
static T_1
F_32 ( char * V_92 , char * V_19 , T_3 * V_20 )
{
if ( strlen ( V_92 ) < V_91 ) {
return ( V_85 ) ;
}
if ( isdigit ( ( int ) V_92 [ V_91 ] ) ) {
sscanf ( & V_92 [ V_91 ] , L_10 , V_20 ) ;
} else if ( strlen ( V_92 ) != V_91 ) {
return ( V_85 ) ;
} else {
* V_20 = 0 ;
}
F_13 ( V_19 , V_92 ) ;
return ( V_17 ) ;
}
static T_1
F_37 ( char * V_92 ,
T_6 V_95 ,
char * V_19 , struct V_11 * * V_12 )
{
T_5 * V_96 ;
struct V_11 V_74 ;
struct V_11 * V_15 = NULL ;
T_3 V_13 ;
T_7 V_97 ;
T_1 V_16 = V_17 ;
V_96 = fopen ( V_92 , L_11 ) ;
if ( V_96 == NULL ) {
fprintf ( V_32 , L_12 , V_92 ) ;
return ( F_1 ( V_7 ) ) ;
}
fseek ( V_96 , V_95 , V_41 ) ;
V_97 = fread ( & V_74 , 1 , sizeof( struct V_11 ) , V_96 ) ;
if ( V_97 != sizeof( struct V_11 ) ) {
fprintf ( V_32 , L_13 , V_92 ) ;
V_16 = V_18 ;
goto exit;
}
if ( V_19 ) {
if ( F_35 ( V_19 ) ) {
if ( ! F_35 ( V_74 . V_19 ) ) {
fprintf ( V_32 ,
L_14 ,
V_74 . V_19 ) ;
V_16 = V_85 ;
goto exit;
}
} else if ( ! F_14 ( V_19 , V_74 . V_19 ) ) {
fprintf ( V_32 ,
L_15 ,
V_19 , V_74 . V_19 ) ;
V_16 = V_85 ;
goto exit;
}
}
V_13 = F_6 ( & V_74 ) ;
if ( V_13 == 0 ) {
V_16 = V_18 ;
goto exit;
}
V_15 = calloc ( 1 , V_13 ) ;
if ( ! V_15 ) {
fprintf ( V_32 ,
L_16 ,
V_74 . V_19 , V_13 ) ;
V_16 = V_9 ;
goto exit;
}
fseek ( V_96 , V_95 , V_41 ) ;
V_97 = fread ( V_15 , 1 , V_13 , V_96 ) ;
if ( V_97 != V_13 ) {
fprintf ( V_32 , L_17 ,
V_74 . V_19 ) ;
V_16 = V_94 ;
goto exit;
}
( void ) F_36 ( V_15 ) ;
exit:
fclose ( V_96 ) ;
* V_12 = V_15 ;
return ( V_16 ) ;
}
static T_1
F_11 ( char * V_98 ,
char * V_19 ,
T_3 V_20 ,
struct V_11 * * V_12 ,
T_2 * V_10 )
{
void * V_89 ;
T_3 V_76 = 0 ;
char V_90 [ V_91 ] ;
char V_99 [ V_100 ] ;
char * V_92 ;
T_1 V_16 ;
V_89 = F_30 ( V_98 , L_7 , V_93 ) ;
if ( ! V_89 ) {
return ( F_1 ( V_7 ) ) ;
}
while ( ( V_92 = F_31 ( V_89 ) ) ) {
if ( ! F_14 ( V_92 , V_19 ) ) {
continue;
}
V_16 =
F_32 ( V_92 , V_90 ,
& V_76 ) ;
if ( F_4 ( V_16 ) || V_76 != V_20 ) {
continue;
}
if ( V_20 != 0 ) {
sprintf ( V_99 , L_18 , V_98 ,
V_90 , V_20 ) ;
} else {
sprintf ( V_99 , L_19 , V_98 ,
V_90 ) ;
}
break;
}
F_33 ( V_89 ) ;
if ( ! V_92 ) {
return ( V_23 ) ;
}
* V_10 = 0 ;
V_16 = F_37 ( V_99 , 0 , NULL , V_12 ) ;
return ( V_16 ) ;
}
