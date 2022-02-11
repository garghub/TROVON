static void
F_1 (
const char * V_1
)
{
fprintf ( V_2 , L_1 , V_1 ) ;
exit ( 1 ) ;
}
static const char *
F_2 (
const T_1 * V_3
)
{
switch ( V_3 -> type )
{
case V_4 : return L_2 ;
case V_5 : return L_3 ;
case V_6 : return L_4 ;
}
F_3 () ;
return L_5 ;
}
static const char *
F_4 (
const T_1 * V_3
)
{
switch ( V_3 -> V_7 )
{
case V_8 : return L_6 ;
case V_9 : return L_7 ;
case V_10 : return L_8 ;
}
F_3 () ;
return L_9 ;
}
static const char *
F_5 (
const T_1 * V_3
)
{
static char V_11 [ 512 ] ;
int V_12 = 0 ;
const T_2 * V_13 ;
T_2 V_14 [ V_15 ] ;
T_2 V_16 [ V_15 ] ;
if ( V_3 -> V_17 != V_18 )
{
switch ( V_3 -> type )
{
case V_4 :
case V_6 :
V_12 = F_6 ( V_11 , sizeof V_11 ,
L_10 , V_3 -> V_17 ) ;
break;
case V_5 :
break;
}
}
else
{
V_13 = V_3 -> V_19 [ 0 ] . type == V_20 ? L_11 : L_12 ;
F_7 ( & V_3 -> V_19 [ 0 ] , V_14 , sizeof V_14 ) ;
F_7 ( & V_3 -> V_19 [ 1 ] , V_16 , sizeof V_16 ) ;
switch ( V_3 -> type )
{
case V_4 :
V_12 = F_6 ( V_11 , sizeof V_11 ,
L_13
L_14
L_15
L_13
L_14 ,
V_13 , V_14 , V_3 -> V_21 [ 0 ] ,
V_13 , V_16 , V_3 -> V_21 [ 1 ] ,
V_13 , V_16 , V_3 -> V_21 [ 1 ] ,
V_13 , V_14 , V_3 -> V_21 [ 0 ] ) ;
break;
case V_5 :
V_12 = F_6 ( V_11 , sizeof V_11 ,
L_16
L_17
L_15
L_16
L_17 ,
V_13 , V_14 , V_3 -> V_21 [ 0 ] ,
V_13 , V_16 , V_3 -> V_21 [ 1 ] ,
V_13 , V_16 , V_3 -> V_21 [ 1 ] ,
V_13 , V_14 , V_3 -> V_21 [ 0 ] ) ;
break;
case V_6 :
break;
}
}
if ( V_12 == 0 )
{
F_1 ( L_18 ) ;
}
if ( V_12 == sizeof V_11 )
{
F_1 ( L_19 ) ;
}
return V_11 ;
}
static void
F_8 (
T_1 * V_3
)
{
if ( V_3 -> V_22 != NULL )
{
fclose ( V_3 -> V_22 ) ;
V_3 -> V_22 = NULL ;
if ( V_3 -> type == V_4 )
{
V_23 = NULL ;
}
}
if ( V_3 -> V_24 != NULL )
{
F_9 ( V_3 -> V_24 ) ;
F_10 ( V_3 -> V_24 ) ;
V_3 -> V_24 = NULL ;
}
}
static void
F_11 (
T_1 * V_3
)
{
int V_25 ;
char * V_26 ;
if ( V_3 -> type == V_4 && V_23 != NULL )
{
F_1 ( L_20 ) ;
}
F_8 ( V_3 ) ;
V_25 = F_12 ( & V_26 , L_21 ) ;
if ( V_25 == - 1 )
{
F_1 ( L_22 ) ;
}
V_3 -> V_24 = F_13 ( V_26 ) ;
if ( V_3 -> V_24 == NULL )
{
F_14 ( V_25 ) ;
F_9 ( V_26 ) ;
F_1 ( L_23 ) ;
}
V_3 -> V_22 = fdopen ( V_25 , L_24 ) ;
if ( V_3 -> V_22 == NULL )
{
F_14 ( V_25 ) ;
F_9 ( V_3 -> V_24 ) ;
F_10 ( V_3 -> V_24 ) ;
V_3 -> V_24 = NULL ;
F_1 ( L_25 ) ;
}
if ( V_3 -> type == V_4 )
{
V_23 = V_3 -> V_22 ;
}
}
static T_1 *
F_15 (
T_3 type
)
{
T_1 * V_3 ;
V_3 = ( T_1 * ) F_16 ( sizeof *V_3 ) ;
V_3 -> type = type ;
F_17 ( & V_3 -> V_19 [ 0 ] , V_27 , 0 , V_3 -> V_28 [ 0 ] ) ;
F_17 ( & V_3 -> V_19 [ 1 ] , V_27 , 0 , V_3 -> V_28 [ 1 ] ) ;
return V_3 ;
}
static void
F_18 (
T_1 * V_3
)
{
F_8 ( V_3 ) ;
F_10 ( V_3 ) ;
}
static int
F_19 (
void * V_29 ,
T_4 * V_30 ,
T_5 * T_6 V_31 ,
const void * V_32
)
{
T_1 * V_3 = ( T_1 * ) V_29 ;
const T_7 * V_33 = ( const T_7 * ) V_32 ;
T_8 V_34 ;
T_9 V_35 ;
if ( V_33 -> V_36 > 0 )
{
memcpy ( V_34 . V_37 , V_30 -> V_38 . V_39 , V_30 -> V_38 . V_12 ) ;
V_34 . V_40 = V_30 -> V_41 ;
V_34 . V_42 = V_33 -> V_36 ;
V_34 . V_43 = V_30 -> V_25 -> V_44 ;
V_35 = fwrite ( & V_34 , 1 , sizeof V_34 , V_3 -> V_22 ) ;
if ( sizeof V_34 != V_35 )
{
F_1 ( L_26 ) ;
}
V_35 = fwrite ( V_33 -> V_45 , 1 , V_34 . V_42 , V_3 -> V_22 ) ;
if ( V_34 . V_42 != V_35 )
{
F_1 ( L_27 ) ;
}
}
return 0 ;
}
static int
F_20 (
void * V_29 ,
T_4 * V_30 ,
T_5 * T_6 V_31 ,
const void * V_32
)
{
T_1 * V_3 = ( T_1 * ) V_29 ;
T_10 * V_46 = ( T_10 * ) F_21 ( F_22 () , V_30 , F_23 ( V_32 ) , 0 ) ;
T_11 * V_47 ;
T_12 V_36 ;
T_8 V_34 ;
T_9 V_35 ;
if ( V_46 == NULL )
{
return 0 ;
}
if ( V_3 -> V_19 [ 0 ] . type == V_27 )
{
memcpy ( V_3 -> V_28 [ 0 ] , V_30 -> V_38 . V_39 , V_30 -> V_38 . V_12 ) ;
F_17 ( & V_3 -> V_19 [ 0 ] , V_30 -> V_38 . type , V_30 -> V_38 . V_12 ,
V_3 -> V_28 [ 0 ] ) ;
V_3 -> V_21 [ 0 ] = V_30 -> V_41 ;
memcpy ( V_3 -> V_28 [ 1 ] , V_30 -> V_48 . V_39 , V_30 -> V_48 . V_12 ) ;
F_17 ( & V_3 -> V_19 [ 1 ] , V_30 -> V_48 . type , V_30 -> V_48 . V_12 ,
V_3 -> V_28 [ 1 ] ) ;
V_3 -> V_21 [ 1 ] = V_30 -> V_49 ;
}
for ( V_36 = 0 , V_47 = V_46 -> V_50 ; V_47 != NULL ; V_47 = V_47 -> V_51 )
{
V_36 += V_47 -> V_52 . V_53 ;
}
if ( V_36 > 0 )
{
memcpy ( V_34 . V_37 , V_30 -> V_38 . V_39 , V_30 -> V_38 . V_12 ) ;
V_34 . V_40 = V_30 -> V_41 ;
V_34 . V_42 = V_36 ;
V_34 . V_43 = V_30 -> V_25 -> V_44 ;
V_35 = fwrite ( & V_34 , 1 , sizeof V_34 , V_3 -> V_22 ) ;
if ( sizeof V_34 != V_35 )
{
F_1 ( L_26 ) ;
}
for ( V_47 = V_46 -> V_50 ; V_47 != NULL ; V_47 = V_47 -> V_51 )
{
if ( V_47 -> V_52 . V_53 > 0 )
{
V_35 = fwrite ( V_47 -> V_52 . V_39 , 1 , V_47 -> V_52 . V_53 ,
V_3 -> V_22 ) ;
if ( V_47 -> V_52 . V_53 != V_35 )
{
F_1 ( L_27 ) ;
}
}
}
}
return 0 ;
}
static void
F_24 (
const char * V_54 ,
T_13 V_55 ,
void * V_32 ,
int V_12
)
{
int V_56 ;
int V_57 ;
int V_58 ;
T_14 V_59 ;
char line [ V_60 + 1 ] ;
for ( V_56 = 0 , V_57 = 0 , V_58 = 0 ; V_56 < V_12 ; )
{
if ( ( V_56 % V_61 ) == 0 )
{
F_6 ( line , V_60 + 1 , L_28 , V_62 , V_55 ) ;
memset ( line + V_63 - V_64 , ' ' ,
V_65 + V_64 + V_66 ) ;
V_57 = V_63 ;
V_58 = V_67 ;
}
V_59 = ( ( T_14 * ) V_32 ) [ V_56 ] ;
line [ V_57 ++ ] = V_68 [ V_59 >> 4 ] ;
line [ V_57 ++ ] = V_68 [ V_59 & 0xf ] ;
V_57 ++ ;
line [ V_58 ++ ] = V_59 >= ' ' && V_59 < 0x7f ? V_59 : '.' ;
if ( ++ V_56 % V_61 == V_61 / 2 )
{
line [ V_57 ++ ] = ' ' ;
line [ V_58 ++ ] = ' ' ;
}
if ( ( V_56 % V_61 ) == 0 || V_56 == V_12 )
{
if ( line [ V_58 - 1 ] == ' ' )
{
V_58 -- ;
}
line [ V_58 ] = 0 ;
printf ( L_29 , V_54 , line ) ;
V_55 += V_61 ;
}
}
}
static void
F_25 (
void * V_29
)
{
static const char V_69 [] =
L_30 ;
T_1 * V_3 = ( T_1 * ) V_29 ;
T_8 V_34 ;
int V_70 ;
const T_15 * V_19 [ 2 ] ;
int V_21 [ 2 ] ;
T_2 V_71 [ V_15 ] ;
T_13 V_56 ;
T_13 V_57 ;
T_13 V_12 ;
T_13 V_72 ;
T_13 V_55 [ 2 ] ;
T_14 V_73 [ 4096 ] ;
char V_39 [ ( sizeof V_73 * 2 ) + 2 ] ;
F_26 ( sizeof V_73 % V_61 == 0 ) ;
if ( V_3 -> type == V_4 )
{
static const T_14 V_74 [ V_75 ] = { 0 } ;
T_16 V_76 ;
T_17 type ;
F_27 ( & V_76 ) ;
if ( V_76 . V_21 [ 0 ] == 0 && V_76 . V_21 [ 1 ] == 0 &&
memcmp ( V_76 . V_77 [ 0 ] , V_74 , sizeof V_74 ) == 0 &&
memcmp ( V_76 . V_77 [ 1 ] , V_74 , sizeof V_74 ) == 0 )
{
type = V_27 ;
V_12 = 0 ;
}
else if ( V_76 . V_78 )
{
type = V_20 ;
V_12 = 16 ;
}
else
{
type = V_79 ;
V_12 = 4 ;
}
for ( V_70 = 0 ; V_70 < 2 ; V_70 ++ )
{
memcpy ( V_3 -> V_28 [ V_70 ] , V_76 . V_77 [ V_70 ] , V_12 ) ;
F_17 ( & V_3 -> V_19 [ V_70 ] , type , V_12 , V_3 -> V_28 [ V_70 ] ) ;
V_3 -> V_21 [ V_70 ] = V_76 . V_21 [ V_70 ] ;
}
}
rewind ( V_3 -> V_22 ) ;
for ( V_72 = 0 ; ; )
{
V_12 = ( T_13 ) fread ( & V_34 , 1 , sizeof V_34 , V_3 -> V_22 ) ;
if ( V_12 != sizeof V_34 )
{
V_34 . V_42 = 0 ;
memcpy ( V_34 . V_37 , V_3 -> V_19 [ 0 ] . V_39 , V_3 -> V_19 [ 0 ] . V_12 ) ;
V_34 . V_40 = V_3 -> V_21 [ 0 ] ;
break;
}
if ( V_34 . V_42 > 0 )
{
V_72 ++ ;
break;
}
}
if ( memcmp ( V_34 . V_37 , V_3 -> V_19 [ 0 ] . V_39 , V_3 -> V_19 [ 0 ] . V_12 ) == 0 &&
V_34 . V_40 == V_3 -> V_21 [ 0 ] )
{
V_19 [ 0 ] = & V_3 -> V_19 [ 0 ] ;
V_21 [ 0 ] = V_3 -> V_21 [ 0 ] ;
V_19 [ 1 ] = & V_3 -> V_19 [ 1 ] ;
V_21 [ 1 ] = V_3 -> V_21 [ 1 ] ;
}
else
{
V_19 [ 0 ] = & V_3 -> V_19 [ 1 ] ;
V_21 [ 0 ] = V_3 -> V_21 [ 1 ] ;
V_19 [ 1 ] = & V_3 -> V_19 [ 0 ] ;
V_21 [ 1 ] = V_3 -> V_21 [ 0 ] ;
}
printf ( L_31 , V_69 ) ;
printf ( L_32 , F_2 ( V_3 ) , F_4 ( V_3 ) ) ;
printf ( L_33 , F_5 ( V_3 ) ) ;
for ( V_70 = 0 ; V_70 < 2 ; V_70 ++ )
{
F_7 ( V_19 [ V_70 ] , V_71 , sizeof V_71 ) ;
if ( V_19 [ V_70 ] -> type == V_20 )
{
printf ( L_34 , V_70 , V_71 , V_21 [ V_70 ] ) ;
}
else
{
printf ( L_35 , V_70 , V_71 , V_21 [ V_70 ] ) ;
}
}
V_55 [ 0 ] = V_55 [ 1 ] = 0 ;
while ( V_72 <= V_3 -> V_80 )
{
V_70 = ( memcmp ( V_19 [ 0 ] -> V_39 , V_34 . V_37 , V_19 [ 0 ] -> V_12 ) == 0 &&
V_21 [ 0 ] == V_34 . V_40 ) ? 0 : 1 ;
if ( V_72 < V_3 -> V_81 )
{
while ( V_34 . V_42 > 0 )
{
V_12 = V_34 . V_42 < sizeof V_73 ? V_34 . V_42 : ( T_13 ) sizeof V_73 ;
V_34 . V_42 -= V_12 ;
if ( fread ( V_73 , 1 , V_12 , V_3 -> V_22 ) != V_12 )
{
F_1 ( L_36 ) ;
}
V_55 [ V_70 ] += V_12 ;
}
}
else
{
switch ( V_3 -> V_7 )
{
case V_8 :
break;
case V_9 :
printf ( L_37 , V_70 ? L_38 : L_12 , V_34 . V_42 ) ;
break;
case V_10 :
if ( V_70 )
{
putchar ( '\t' ) ;
}
break;
}
while ( V_34 . V_42 > 0 )
{
V_12 = V_34 . V_42 < sizeof V_73 ? V_34 . V_42 : ( T_13 ) sizeof V_73 ;
V_34 . V_42 -= V_12 ;
if ( fread ( V_73 , 1 , V_12 , V_3 -> V_22 ) != V_12 )
{
F_1 ( L_36 ) ;
}
switch ( V_3 -> V_7 )
{
case V_8 :
F_24 ( V_70 ? L_38 : L_12 , V_55 [ V_70 ] , V_73 , V_12 ) ;
break;
case V_9 :
for ( V_56 = 0 ; V_56 < V_12 ; V_56 ++ )
{
switch ( V_73 [ V_56 ] )
{
case '\r' :
case '\n' :
V_39 [ V_56 ] = V_73 [ V_56 ] ;
break;
default:
V_39 [ V_56 ] = F_28 ( V_73 [ V_56 ] ) ? V_73 [ V_56 ] : '.' ;
break;
}
}
if ( V_34 . V_42 == 0 )
{
V_39 [ V_56 ++ ] = '\n' ;
}
V_39 [ V_56 ] = 0 ;
printf ( L_39 , V_39 ) ;
break;
case V_10 :
for ( V_56 = 0 , V_57 = 0 ; V_56 < V_12 ; V_56 ++ )
{
V_39 [ V_57 ++ ] = V_68 [ V_73 [ V_56 ] >> 4 ] ;
V_39 [ V_57 ++ ] = V_68 [ V_73 [ V_56 ] & 0xf ] ;
}
if ( V_34 . V_42 == 0 )
{
V_39 [ V_57 ++ ] = '\n' ;
}
V_39 [ V_57 ] = 0 ;
printf ( L_39 , V_39 ) ;
}
V_55 [ V_70 ] += V_12 ;
}
}
for (; ; )
{
V_12 = ( T_13 ) fread ( & V_34 , 1 , sizeof V_34 , V_3 -> V_22 ) ;
if ( V_12 != sizeof V_34 )
{
V_34 . V_42 = 0 ;
goto V_82;
}
if ( V_34 . V_42 > 0 )
{
V_72 ++ ;
break;
}
}
}
V_82:
printf ( L_39 , V_69 ) ;
F_8 ( V_3 ) ;
}
static T_18
F_29 (
const char * * V_83 ,
const char * V_1
)
{
int V_12 = ( T_13 ) strlen ( V_1 ) ;
if ( strncmp ( * V_83 , V_1 , V_12 ) == 0 )
{
* V_83 += V_12 ;
return TRUE ;
}
return FALSE ;
}
static void
F_30 (
const char * * V_83 ,
T_1 * V_3
)
{
if ( F_29 ( V_83 , V_84 ) )
{
V_3 -> V_7 = V_8 ;
}
else if ( F_29 ( V_83 , V_85 ) )
{
V_3 -> V_7 = V_9 ;
}
else if ( F_29 ( V_83 , V_86 ) )
{
V_3 -> V_7 = V_10 ;
}
else
{
F_1 ( L_40 ) ;
}
}
static void
F_31 (
const char * * V_83 ,
T_1 * V_3
)
{
#define F_32 ( T_19 ) # s
#define STRING ( T_19 ) _STRING(s)
#define F_33 80
#define F_34 (ADDR_CHARS + 1)
#define F_35 ",[%" STRING(ADDR_CHARS) "[^]]]:%d%n"
#define F_36 ",%" STRING(ADDR_CHARS) "[^:]:%d%n"
int V_12 ;
unsigned int V_56 ;
char V_19 [ F_34 ] ;
if ( sscanf ( * V_83 , L_41 , & V_3 -> V_17 , & V_12 ) == 1 &&
( ( * V_83 ) [ V_12 ] == 0 || ( * V_83 ) [ V_12 ] == ',' ) )
{
* V_83 += V_12 ;
}
else
{
for ( V_56 = 0 ; V_56 < sizeof V_3 -> V_19 / sizeof * V_3 -> V_19 ; V_56 ++ )
{
if ( ( sscanf ( * V_83 , F_35 , V_19 , & V_3 -> V_21 [ V_56 ] , & V_12 ) != 2 &&
sscanf ( * V_83 , F_36 , V_19 , & V_3 -> V_21 [ V_56 ] , & V_12 ) != 2 ) ||
V_3 -> V_21 [ V_56 ] <= 0 || V_3 -> V_21 [ V_56 ] > V_87 )
{
F_1 ( L_42 ) ;
}
if ( strcmp ( L_43 , F_37 ( V_19 ) ) == 0 )
{
if ( ! F_38 ( V_19 , (struct V_88 * ) V_3 -> V_28 [ V_56 ] ) )
{
F_1 ( L_44 ) ;
}
F_17 ( & V_3 -> V_19 [ V_56 ] , V_20 , 16 , V_3 -> V_28 [ V_56 ] ) ;
}
else
{
if ( ! F_39 ( V_19 , ( T_13 * ) V_3 -> V_28 [ V_56 ] ) )
{
F_1 ( L_45 ) ;
}
F_17 ( & V_3 -> V_19 [ V_56 ] , V_79 , 4 , V_3 -> V_28 [ V_56 ] ) ;
}
* V_83 += V_12 ;
}
if ( V_3 -> V_19 [ 0 ] . type != V_3 -> V_19 [ 1 ] . type )
{
F_1 ( L_46 ) ;
}
V_3 -> V_17 = V_18 ;
}
}
static void
F_40 (
const char * * V_83 ,
T_1 * V_3
)
{
int V_12 ;
if ( * * V_83 == 0 )
{
V_3 -> V_81 = 1 ;
V_3 -> V_80 = V_18 ;
}
else
{
if ( sscanf ( * V_83 , L_47 , & V_3 -> V_81 , & V_3 -> V_80 , & V_12 ) == 2 )
{
* V_83 += V_12 ;
}
else if ( sscanf ( * V_83 , L_41 , & V_3 -> V_81 , & V_12 ) == 1 )
{
V_3 -> V_80 = V_3 -> V_81 ;
* V_83 += V_12 ;
}
else
{
F_1 ( L_48 ) ;
}
if ( V_3 -> V_81 < 1 || V_3 -> V_81 > V_3 -> V_80 )
{
F_1 ( L_49 ) ;
}
}
}
static void
F_41 (
const char * V_83
)
{
if ( * V_83 != 0 )
{
F_1 ( L_50 ) ;
}
}
static void
F_42 (
const char * V_83 ,
void * T_20 V_31
)
{
T_1 * V_3 ;
T_21 * V_89 ;
V_83 += strlen ( V_90 ) ;
V_3 = F_15 ( V_4 ) ;
F_30 ( & V_83 , V_3 ) ;
F_31 ( & V_83 , V_3 ) ;
F_40 ( & V_83 , V_3 ) ;
F_41 ( V_83 ) ;
F_43 () ;
if ( V_3 -> V_17 != V_18 )
{
if ( ! F_44 ( V_3 -> V_17 ) )
{
F_1 ( L_51 ) ;
}
}
else
{
if ( ! F_45 ( & V_3 -> V_19 [ 0 ] , V_3 -> V_21 [ 0 ] ,
& V_3 -> V_19 [ 1 ] , V_3 -> V_21 [ 1 ] ) )
{
F_1 ( L_52 ) ;
}
}
F_11 ( V_3 ) ;
V_89 = F_46 ( L_53 , V_3 , NULL , 0 ,
NULL , NULL , F_25 ) ;
if ( V_89 != NULL )
{
F_18 ( V_3 ) ;
F_47 ( V_89 , TRUE ) ;
F_1 ( L_54 ) ;
}
}
static void
F_48 (
const char * V_83 ,
void * T_20 V_31
)
{
T_1 * V_3 ;
T_21 * V_89 ;
V_83 += strlen ( V_91 ) ;
V_3 = F_15 ( V_5 ) ;
F_30 ( & V_83 , V_3 ) ;
F_31 ( & V_83 , V_3 ) ;
F_40 ( & V_83 , V_3 ) ;
F_41 ( V_83 ) ;
if ( V_3 -> V_17 != V_18 )
{
F_1 ( L_55 ) ;
}
F_11 ( V_3 ) ;
V_89 = F_46 ( L_56 , V_3 , F_5 ( V_3 ) , 0 ,
NULL , F_19 , F_25 ) ;
if ( V_89 != NULL )
{
F_18 ( V_3 ) ;
F_47 ( V_89 , TRUE ) ;
F_1 ( L_57 ) ;
}
}
static void
F_49 (
const char * V_83 ,
void * T_20 V_31
)
{
T_1 * V_3 ;
T_21 * V_89 ;
V_83 += strlen ( V_92 ) ;
V_3 = F_15 ( V_6 ) ;
F_30 ( & V_83 , V_3 ) ;
F_31 ( & V_83 , V_3 ) ;
F_40 ( & V_83 , V_3 ) ;
F_41 ( V_83 ) ;
if ( V_3 -> V_17 == V_18 )
{
F_1 ( L_58 ) ;
}
F_11 ( V_3 ) ;
V_89 = F_46 ( L_4 , V_3 , F_5 ( V_3 ) , 0 ,
NULL , F_20 , F_25 ) ;
if ( V_89 != NULL )
{
F_18 ( V_3 ) ;
F_47 ( V_89 , TRUE ) ;
F_1 ( L_59 ) ;
}
}
void
F_50 ( void )
{
F_51 ( V_90 , F_42 , NULL ) ;
F_51 ( V_91 , F_48 , NULL ) ;
F_51 ( V_92 , F_49 , NULL ) ;
}
