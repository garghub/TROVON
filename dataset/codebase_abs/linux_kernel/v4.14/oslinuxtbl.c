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
memcpy ( V_15 , V_14 , V_13 ) ;
exit:
F_7 ( V_14 ) ;
* V_12 = V_15 ;
return ( V_16 ) ;
}
T_1
F_8 ( char * V_19 ,
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
F_9 ( V_19 , V_20 , V_12 , V_10 ) ;
} else {
V_16 = F_10 ( V_22 , V_19 ,
V_20 , V_12 , V_10 ) ;
}
if ( F_4 ( V_16 ) && V_16 == V_23 ) {
if ( V_24 ) {
V_16 =
F_10 ( V_25 ,
V_19 , V_20 , V_12 ,
V_10 ) ;
}
}
return ( V_16 ) ;
}
static T_1 F_11 ( char * V_19 , T_3 V_20 )
{
struct V_26 * V_27 ;
struct V_26 * V_28 ;
T_3 V_29 = 0 ;
T_4 V_30 = FALSE ;
V_27 = calloc ( 1 , sizeof( struct V_26 ) ) ;
if ( ! V_27 ) {
return ( V_9 ) ;
}
F_12 ( V_27 -> V_19 , V_19 ) ;
if ( ! V_31 ) {
V_31 = V_27 ;
} else {
V_28 = V_31 ;
while ( 1 ) {
if ( F_13 ( V_28 -> V_19 , V_19 ) ) {
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
F_14 ( T_3 V_34 ,
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
V_16 = F_8 ( V_35 -> V_19 , V_35 -> V_20 ,
V_12 , V_10 ) ;
if ( F_15 ( V_16 ) ) {
* V_20 = V_35 -> V_20 ;
}
return ( V_16 ) ;
}
static T_2
F_16 ( T_5 * V_37 , const char * V_38 )
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
static T_2 F_17 ( void )
{
T_5 * V_37 ;
T_2 V_10 = 0 ;
V_37 = fopen ( V_42 , L_4 ) ;
if ( V_37 ) {
V_10 = F_16 ( V_37 , L_5 ) ;
if ( ! V_10 ) {
V_10 =
F_16 ( V_37 , L_6 ) ;
}
fclose ( V_37 ) ;
}
return ( V_10 ) ;
}
static T_1 F_18 ( void )
{
struct V_11 * V_14 ;
T_4 * V_43 ;
T_2 V_44 ;
T_6 V_45 ;
V_45 = sizeof( struct V_46 ) ;
if ( V_47 ) {
V_44 = V_47 ;
} else {
V_44 = F_17 () ;
}
if ( ! V_44 ) {
V_44 = V_48 ;
V_45 = V_49 ;
}
V_43 = F_19 ( V_44 , V_45 ) ;
if ( ! V_43 ) {
return ( F_1 ( V_50 ) ) ;
}
V_14 = F_20 ( struct V_11 ,
F_21 ( V_43 ,
V_45 ) ) ;
if ( ! V_14 ) {
F_22 ( V_43 , V_45 ) ;
return ( V_7 ) ;
}
V_51 =
V_44 + ( F_23 ( V_14 ) - V_43 ) ;
memcpy ( & V_52 , V_14 , sizeof( struct V_46 ) ) ;
F_22 ( V_43 , V_45 ) ;
return ( V_17 ) ;
}
static T_4 F_24 ( void )
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
if ( ! V_21 ) {
V_16 = F_18 () ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
if ( V_52 . V_56 && ! V_57 ) {
if ( V_58 ) {
free ( V_58 ) ;
V_58 = NULL ;
}
V_53 = 2 ;
V_16 = F_9 ( V_59 , 0 ,
F_20 ( struct
V_11
* , & V_58 ) ,
& V_10 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
}
if ( V_52 . V_60 ) {
if ( V_61 ) {
free ( V_61 ) ;
V_61 = NULL ;
}
V_16 = F_9 ( V_62 , 0 ,
F_20 ( struct
V_11
* , & V_61 ) ,
& V_10 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
}
if ( V_63 ) {
free ( V_63 ) ;
V_63 = NULL ;
}
V_16 = F_9 ( V_64 , 0 ,
F_20 ( struct
V_11 * ,
& V_63 ) ,
& V_65 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
V_16 = F_11 ( V_66 , 0 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
V_16 = F_11 ( V_62 , 0 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
if ( V_53 == 2 ) {
V_16 = F_11 ( V_59 , 0 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
}
V_16 = F_11 ( V_67 , 0 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
V_16 = F_11 ( V_68 , 0 ) ;
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
V_55 = TRUE ;
return ( V_17 ) ;
}
static T_1 F_25 ( void )
{
struct V_11 * V_14 = NULL ;
T_4 * V_69 ;
T_4 V_70 ;
T_4 V_71 ;
T_2 V_72 = 0 ;
T_1 V_16 = V_17 ;
T_3 V_36 ;
if ( F_24 () ) {
V_71 = sizeof( V_73 ) ;
V_69 =
F_23 ( V_58 ) + sizeof( struct V_11 ) ;
V_70 =
( T_4 ) ( ( V_58 -> V_74 . V_75 -
sizeof( struct V_11 ) )
/ V_71 ) ;
} else {
V_71 = sizeof( T_3 ) ;
V_69 =
F_23 ( V_61 ) + sizeof( struct V_11 ) ;
V_70 =
( T_4 ) ( ( V_61 -> V_74 . V_75 -
sizeof( struct V_11 ) )
/ V_71 ) ;
}
for ( V_36 = 0 ; V_36 < V_70 ; ++ V_36 , V_69 += V_71 ) {
if ( F_24 () ) {
V_72 =
( T_2 ) ( * F_27 ( V_69 ) ) ;
} else {
V_72 =
( T_2 ) ( * F_28 ( V_69 ) ) ;
}
if ( V_72 == 0 ) {
continue;
}
V_16 = F_5 ( V_72 , NULL , & V_14 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
F_11 ( V_14 -> V_19 , 0 ) ;
F_7 ( V_14 ) ;
}
return ( V_17 ) ;
}
static T_1
F_9 ( char * V_19 ,
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
T_2 V_72 ;
T_2 V_77 = 0 ;
T_3 V_13 = 0 ;
T_1 V_16 = V_17 ;
T_3 V_36 ;
if ( F_13 ( V_19 , V_66 ) ||
F_13 ( V_19 , V_62 ) ||
F_13 ( V_19 , V_59 ) ||
F_13 ( V_19 , V_67 ) ||
F_13 ( V_19 , V_68 ) ) {
V_78:
V_72 = 0 ;
if ( F_13 ( V_19 , V_67 ) ) {
if ( V_76 < 2 ) {
if ( ( V_63 -> V_74 . V_75 >=
V_79 ) && V_63 -> V_80
&& V_76 == 0 ) {
V_72 =
( T_2 ) V_63 ->
V_80 ;
} else
if ( ( V_63 -> V_74 . V_75 >=
V_81 )
&& V_63 -> V_82 !=
V_77 ) {
V_72 =
( T_2 ) V_63 ->
V_82 ;
}
}
} else if ( F_13 ( V_19 , V_68 ) ) {
if ( V_76 < 2 ) {
if ( ( V_63 -> V_74 . V_75 >=
V_83 ) && V_63 -> V_84
&& V_76 == 0 ) {
V_72 =
( T_2 ) V_63 ->
V_84 ;
} else
if ( ( V_63 -> V_74 . V_75 >=
V_85 )
&& V_63 -> V_86 !=
V_77 ) {
V_72 =
( T_2 ) V_63 ->
V_86 ;
}
}
} else if ( F_13 ( V_19 , V_59 ) ) {
if ( ! V_53 ) {
return ( V_87 ) ;
}
if ( V_76 == 0 ) {
V_72 =
( T_2 ) V_52 .
V_88 ;
}
} else if ( F_13 ( V_19 , V_62 ) ) {
if ( V_76 == 0 ) {
V_72 =
( T_2 ) V_52 .
V_60 ;
}
} else {
if ( V_76 == 0 ) {
V_72 =
( T_2 ) V_51 ;
V_19 = V_89 ;
}
}
if ( V_72 == 0 ) {
goto V_90;
}
V_16 = F_5 ( V_72 , V_19 , & V_14 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
V_13 = F_6 ( V_14 ) ;
if ( V_77 == 0 ) {
V_77 = V_72 ;
}
if ( V_76 != V_20 ) {
F_7 ( V_14 ) ;
V_14 = NULL ;
V_76 ++ ;
goto V_78;
}
} else {
if ( F_24 () ) {
V_71 = sizeof( V_73 ) ;
V_69 =
F_23 ( V_58 ) +
sizeof( struct V_11 ) ;
V_70 =
( T_4 ) ( ( V_58 -> V_74 . V_75 -
sizeof( struct V_11 ) )
/ V_71 ) ;
} else {
V_71 = sizeof( T_3 ) ;
V_69 =
F_23 ( V_61 ) +
sizeof( struct V_11 ) ;
V_70 =
( T_4 ) ( ( V_61 -> V_74 . V_75 -
sizeof( struct V_11 ) )
/ V_71 ) ;
}
for ( V_36 = 0 ; V_36 < V_70 ; ++ V_36 , V_69 += V_71 ) {
if ( F_24 () ) {
V_72 =
( T_2 ) ( * F_27
( V_69 ) ) ;
} else {
V_72 =
( T_2 ) ( * F_28
( V_69 ) ) ;
}
if ( V_72 == 0 ) {
continue;
}
V_16 =
F_5 ( V_72 , NULL , & V_14 ) ;
if ( F_4 ( V_16 ) ) {
return ( V_16 ) ;
}
V_13 = V_14 -> V_75 ;
if ( ! F_13
( V_14 -> V_19 , V_19 ) ) {
F_7 ( V_14 ) ;
V_14 = NULL ;
continue;
}
if ( V_76 != V_20 ) {
F_7 ( V_14 ) ;
V_14 = NULL ;
V_76 ++ ;
continue;
}
break;
}
}
V_90:
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
memcpy ( V_15 , V_14 , V_13 ) ;
* V_10 = V_72 ;
* V_12 = V_15 ;
exit:
F_7 ( V_14 ) ;
return ( V_16 ) ;
}
static T_1 F_26 ( char * V_91 )
{
void * V_92 ;
T_3 V_20 ;
char V_93 [ V_94 ] ;
char * V_95 ;
T_1 V_16 = V_17 ;
V_92 = F_29 ( V_91 , L_7 , V_96 ) ;
if ( ! V_92 ) {
return ( F_1 ( V_7 ) ) ;
}
while ( ( V_95 = F_30 ( V_92 ) ) ) {
V_16 =
F_31 ( V_95 , V_93 , & V_20 ) ;
if ( F_4 ( V_16 ) ) {
continue;
}
V_16 = F_11 ( V_93 , V_20 ) ;
if ( F_4 ( V_16 ) ) {
break;
}
}
F_32 ( V_92 ) ;
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
F_19 ( V_10 , sizeof( struct V_11 ) ) ;
if ( ! V_14 ) {
fprintf ( V_32 , L_8 ,
F_33 ( V_10 ) ) ;
return ( F_1 ( V_50 ) ) ;
}
if ( V_19 ) {
if ( F_34 ( V_19 ) ) {
if ( ! F_34 ( V_14 -> V_19 ) ) {
F_22 ( V_14 ,
sizeof( struct
V_11 ) ) ;
return ( V_87 ) ;
}
} else
if ( ! F_13 ( V_19 , V_14 -> V_19 ) )
{
F_22 ( V_14 ,
sizeof( struct V_11 ) ) ;
return ( V_87 ) ;
}
}
V_75 = F_6 ( V_14 ) ;
F_22 ( V_14 , sizeof( struct V_11 ) ) ;
if ( V_75 == 0 ) {
return ( V_18 ) ;
}
V_14 = F_19 ( V_10 , V_75 ) ;
if ( ! V_14 ) {
fprintf ( V_32 ,
L_9 ,
F_33 ( V_10 ) , V_75 ) ;
return ( F_1 ( V_97 ) ) ;
}
( void ) F_35 ( V_14 ) ;
* V_12 = V_14 ;
return ( V_17 ) ;
}
static void F_7 ( struct V_11 * V_12 )
{
if ( V_12 ) {
F_22 ( V_12 , F_6 ( V_12 ) ) ;
}
}
static T_1
F_31 ( char * V_95 , char * V_19 , T_3 * V_20 )
{
if ( strlen ( V_95 ) < V_94 ) {
return ( V_87 ) ;
}
if ( isdigit ( ( int ) V_95 [ V_94 ] ) ) {
sscanf ( & V_95 [ V_94 ] , L_10 , V_20 ) ;
} else if ( strlen ( V_95 ) != V_94 ) {
return ( V_87 ) ;
} else {
* V_20 = 0 ;
}
F_12 ( V_19 , V_95 ) ;
return ( V_17 ) ;
}
static T_1
F_36 ( char * V_95 ,
T_6 V_98 ,
char * V_19 , struct V_11 * * V_12 )
{
T_5 * V_99 ;
struct V_11 V_74 ;
struct V_11 * V_15 = NULL ;
T_3 V_13 ;
T_7 V_100 ;
T_1 V_16 = V_17 ;
V_99 = fopen ( V_95 , L_11 ) ;
if ( V_99 == NULL ) {
fprintf ( V_32 , L_12 , V_95 ) ;
return ( F_1 ( V_7 ) ) ;
}
fseek ( V_99 , V_98 , V_41 ) ;
V_100 = fread ( & V_74 , 1 , sizeof( struct V_11 ) , V_99 ) ;
if ( V_100 != sizeof( struct V_11 ) ) {
fprintf ( V_32 , L_13 , V_95 ) ;
V_16 = V_18 ;
goto exit;
}
if ( V_19 ) {
if ( F_34 ( V_19 ) ) {
if ( ! F_34 ( V_74 . V_19 ) ) {
fprintf ( V_32 ,
L_14 ,
V_74 . V_19 ) ;
V_16 = V_87 ;
goto exit;
}
} else if ( ! F_13 ( V_19 , V_74 . V_19 ) ) {
fprintf ( V_32 ,
L_15 ,
V_19 , V_74 . V_19 ) ;
V_16 = V_87 ;
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
fseek ( V_99 , V_98 , V_41 ) ;
V_100 = fread ( V_15 , 1 , V_13 , V_99 ) ;
if ( V_100 != V_13 ) {
fprintf ( V_32 , L_17 ,
V_74 . V_19 ) ;
V_16 = V_97 ;
goto exit;
}
( void ) F_35 ( V_15 ) ;
exit:
fclose ( V_99 ) ;
* V_12 = V_15 ;
return ( V_16 ) ;
}
static T_1
F_10 ( char * V_101 ,
char * V_19 ,
T_3 V_20 ,
struct V_11 * * V_12 ,
T_2 * V_10 )
{
void * V_92 ;
T_3 V_76 = 0 ;
char V_93 [ V_94 ] ;
char V_102 [ V_103 ] ;
char * V_95 ;
T_1 V_16 ;
V_92 = F_29 ( V_101 , L_7 , V_96 ) ;
if ( ! V_92 ) {
return ( F_1 ( V_7 ) ) ;
}
while ( ( V_95 = F_30 ( V_92 ) ) ) {
if ( ! F_13 ( V_95 , V_19 ) ) {
continue;
}
V_16 =
F_31 ( V_95 , V_93 ,
& V_76 ) ;
if ( F_4 ( V_16 ) || V_76 != V_20 ) {
continue;
}
if ( V_20 != 0 ) {
sprintf ( V_102 , L_18 , V_101 ,
V_93 , V_20 ) ;
} else {
sprintf ( V_102 , L_19 , V_101 ,
V_93 ) ;
}
break;
}
F_32 ( V_92 ) ;
if ( ! V_95 ) {
return ( V_23 ) ;
}
* V_10 = 0 ;
V_16 = F_36 ( V_102 , 0 , NULL , V_12 ) ;
return ( V_16 ) ;
}
