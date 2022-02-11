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
V_35 = fwrite ( & V_34 , 1 , sizeof V_34 , V_3 -> V_22 ) ;
if ( sizeof V_34 != V_35 )
{
F_1 ( L_26 ) ;
}
V_35 = fwrite ( V_33 -> V_43 , 1 , V_34 . V_42 , V_3 -> V_22 ) ;
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
T_10 * V_44 = ( T_10 * ) F_21 ( V_30 -> V_25 , F_22 ( V_32 ) , 0 ) ;
T_11 * V_45 ;
T_12 V_36 ;
T_8 V_34 ;
T_9 V_35 ;
if ( V_44 == NULL )
{
return 0 ;
}
if ( V_3 -> V_19 [ 0 ] . type == V_27 )
{
memcpy ( V_3 -> V_28 [ 0 ] , V_30 -> V_38 . V_39 , V_30 -> V_38 . V_12 ) ;
F_17 ( & V_3 -> V_19 [ 0 ] , V_30 -> V_38 . type , V_30 -> V_38 . V_12 ,
V_3 -> V_28 [ 0 ] ) ;
V_3 -> V_21 [ 0 ] = V_30 -> V_41 ;
memcpy ( V_3 -> V_28 [ 1 ] , V_30 -> V_46 . V_39 , V_30 -> V_46 . V_12 ) ;
F_17 ( & V_3 -> V_19 [ 1 ] , V_30 -> V_46 . type , V_30 -> V_46 . V_12 ,
V_3 -> V_28 [ 1 ] ) ;
V_3 -> V_21 [ 1 ] = V_30 -> V_47 ;
}
for ( V_36 = 0 , V_45 = V_44 -> V_48 ; V_45 != NULL ; V_45 = V_45 -> V_49 )
{
V_36 += V_45 -> V_50 . V_51 ;
}
if ( V_36 > 0 )
{
memcpy ( V_34 . V_37 , V_30 -> V_38 . V_39 , V_30 -> V_38 . V_12 ) ;
V_34 . V_40 = V_30 -> V_41 ;
V_34 . V_42 = V_36 ;
V_35 = fwrite ( & V_34 , 1 , sizeof V_34 , V_3 -> V_22 ) ;
if ( sizeof V_34 != V_35 )
{
F_1 ( L_26 ) ;
}
for ( V_45 = V_44 -> V_48 ; V_45 != NULL ; V_45 = V_45 -> V_49 )
{
if ( V_45 -> V_50 . V_51 > 0 )
{
V_35 = fwrite ( V_45 -> V_50 . V_39 , 1 , V_45 -> V_50 . V_51 ,
V_3 -> V_22 ) ;
if ( V_45 -> V_50 . V_51 != V_35 )
{
F_1 ( L_27 ) ;
}
}
}
}
return 0 ;
}
static void
F_23 (
const char * V_52 ,
T_13 V_53 ,
void * V_32 ,
int V_12
)
{
int V_54 ;
int V_55 ;
int V_56 ;
T_14 V_57 ;
char line [ V_58 + 1 ] ;
for ( V_54 = 0 , V_55 = 0 , V_56 = 0 ; V_54 < V_12 ; )
{
if ( ( V_54 % V_59 ) == 0 )
{
F_6 ( line , V_58 + 1 , L_28 , V_60 , V_53 ) ;
memset ( line + V_61 - V_62 , ' ' ,
V_63 + V_62 + V_64 ) ;
V_55 = V_61 ;
V_56 = V_65 ;
}
V_57 = ( ( T_14 * ) V_32 ) [ V_54 ] ;
line [ V_55 ++ ] = V_66 [ V_57 >> 4 ] ;
line [ V_55 ++ ] = V_66 [ V_57 & 0xf ] ;
V_55 ++ ;
line [ V_56 ++ ] = V_57 >= ' ' && V_57 < 0x7f ? V_57 : '.' ;
if ( ++ V_54 % V_59 == V_59 / 2 )
{
line [ V_55 ++ ] = ' ' ;
line [ V_56 ++ ] = ' ' ;
}
if ( ( V_54 % V_59 ) == 0 || V_54 == V_12 )
{
if ( line [ V_56 - 1 ] == ' ' )
{
V_56 -- ;
}
line [ V_56 ] = 0 ;
printf ( L_29 , V_52 , line ) ;
V_53 += V_59 ;
}
}
}
static void
F_24 (
void * V_29
)
{
static const char V_67 [] =
L_30 ;
T_1 * V_3 = ( T_1 * ) V_29 ;
T_8 V_34 ;
int V_68 ;
const T_15 * V_19 [ 2 ] ;
int V_21 [ 2 ] ;
T_2 V_69 [ V_15 ] ;
T_13 V_54 ;
T_13 V_55 ;
T_13 V_12 ;
T_13 V_70 ;
T_13 V_53 [ 2 ] ;
T_14 V_71 [ 4096 ] ;
char V_39 [ ( sizeof V_71 * 2 ) + 2 ] ;
F_25 ( sizeof V_71 % V_59 == 0 ) ;
if ( V_3 -> type == V_4 )
{
static const T_14 V_72 [ V_73 ] = { 0 } ;
T_16 V_74 ;
T_17 type ;
F_26 ( & V_74 ) ;
if ( V_74 . V_21 [ 0 ] == 0 && V_74 . V_21 [ 1 ] == 0 &&
memcmp ( V_74 . V_75 [ 0 ] , V_72 , sizeof V_72 ) == 0 &&
memcmp ( V_74 . V_75 [ 1 ] , V_72 , sizeof V_72 ) == 0 )
{
type = V_27 ;
V_12 = 0 ;
}
else if ( V_74 . V_76 )
{
type = V_20 ;
V_12 = 16 ;
}
else
{
type = V_77 ;
V_12 = 4 ;
}
for ( V_68 = 0 ; V_68 < 2 ; V_68 ++ )
{
memcpy ( V_3 -> V_28 [ V_68 ] , V_74 . V_75 [ V_68 ] , V_12 ) ;
F_17 ( & V_3 -> V_19 [ V_68 ] , type , V_12 , V_3 -> V_28 [ V_68 ] ) ;
V_3 -> V_21 [ V_68 ] = V_74 . V_21 [ V_68 ] ;
}
}
rewind ( V_3 -> V_22 ) ;
for ( V_70 = 0 ; ; )
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
V_70 ++ ;
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
printf ( L_31 , V_67 ) ;
printf ( L_32 , F_2 ( V_3 ) , F_4 ( V_3 ) ) ;
printf ( L_33 , F_5 ( V_3 ) ) ;
for ( V_68 = 0 ; V_68 < 2 ; V_68 ++ )
{
F_7 ( V_19 [ V_68 ] , V_69 , sizeof V_69 ) ;
if ( V_19 [ V_68 ] -> type == V_20 )
{
printf ( L_34 , V_68 , V_69 , V_21 [ V_68 ] ) ;
}
else
{
printf ( L_35 , V_68 , V_69 , V_21 [ V_68 ] ) ;
}
}
V_53 [ 0 ] = V_53 [ 1 ] = 0 ;
while ( V_70 <= V_3 -> V_78 )
{
V_68 = ( memcmp ( V_19 [ 0 ] -> V_39 , V_34 . V_37 , V_19 [ 0 ] -> V_12 ) == 0 &&
V_21 [ 0 ] == V_34 . V_40 ) ? 0 : 1 ;
if ( V_70 < V_3 -> V_79 )
{
while ( V_34 . V_42 > 0 )
{
V_12 = V_34 . V_42 < sizeof V_71 ? V_34 . V_42 : ( T_13 ) sizeof V_71 ;
V_34 . V_42 -= V_12 ;
if ( fread ( V_71 , 1 , V_12 , V_3 -> V_22 ) != V_12 )
{
F_1 ( L_36 ) ;
}
V_53 [ V_68 ] += V_12 ;
}
}
else
{
switch ( V_3 -> V_7 )
{
case V_8 :
break;
case V_9 :
printf ( L_37 , V_68 ? L_38 : L_12 , V_34 . V_42 ) ;
break;
case V_10 :
if ( V_68 )
{
putchar ( '\t' ) ;
}
break;
}
while ( V_34 . V_42 > 0 )
{
V_12 = V_34 . V_42 < sizeof V_71 ? V_34 . V_42 : ( T_13 ) sizeof V_71 ;
V_34 . V_42 -= V_12 ;
if ( fread ( V_71 , 1 , V_12 , V_3 -> V_22 ) != V_12 )
{
F_1 ( L_36 ) ;
}
switch ( V_3 -> V_7 )
{
case V_8 :
F_23 ( V_68 ? L_38 : L_12 , V_53 [ V_68 ] , V_71 , V_12 ) ;
break;
case V_9 :
for ( V_54 = 0 ; V_54 < V_12 ; V_54 ++ )
{
switch ( V_71 [ V_54 ] )
{
case '\r' :
case '\n' :
V_39 [ V_54 ] = V_71 [ V_54 ] ;
break;
default:
V_39 [ V_54 ] = isprint ( V_71 [ V_54 ] ) ? V_71 [ V_54 ] : '.' ;
break;
}
}
if ( V_34 . V_42 == 0 )
{
V_39 [ V_54 ++ ] = '\n' ;
}
V_39 [ V_54 ] = 0 ;
printf ( L_39 , V_39 ) ;
break;
case V_10 :
for ( V_54 = 0 , V_55 = 0 ; V_54 < V_12 ; V_54 ++ )
{
V_39 [ V_55 ++ ] = V_66 [ V_71 [ V_54 ] >> 4 ] ;
V_39 [ V_55 ++ ] = V_66 [ V_71 [ V_54 ] & 0xf ] ;
}
if ( V_34 . V_42 == 0 )
{
V_39 [ V_55 ++ ] = '\n' ;
}
V_39 [ V_55 ] = 0 ;
printf ( L_39 , V_39 ) ;
}
V_53 [ V_68 ] += V_12 ;
}
}
for (; ; )
{
V_12 = ( T_13 ) fread ( & V_34 , 1 , sizeof V_34 , V_3 -> V_22 ) ;
if ( V_12 != sizeof V_34 )
{
V_34 . V_42 = 0 ;
goto V_80;
}
if ( V_34 . V_42 > 0 )
{
V_70 ++ ;
break;
}
}
}
V_80:
printf ( L_39 , V_67 ) ;
F_8 ( V_3 ) ;
}
static T_18
F_27 (
const char * * V_81 ,
const char * V_1
)
{
int V_12 = ( T_13 ) strlen ( V_1 ) ;
if ( strncmp ( * V_81 , V_1 , V_12 ) == 0 )
{
* V_81 += V_12 ;
return TRUE ;
}
return FALSE ;
}
static void
F_28 (
const char * * V_81 ,
T_1 * V_3
)
{
if ( F_27 ( V_81 , V_82 ) )
{
V_3 -> V_7 = V_8 ;
}
else if ( F_27 ( V_81 , V_83 ) )
{
V_3 -> V_7 = V_9 ;
}
else if ( F_27 ( V_81 , V_84 ) )
{
V_3 -> V_7 = V_10 ;
}
else
{
F_1 ( L_40 ) ;
}
}
static void
F_29 (
const char * * V_81 ,
T_1 * V_3
)
{
#define F_30 ( T_19 ) # s
#define STRING ( T_19 ) _STRING(s)
#define F_31 80
#define F_32 (ADDR_CHARS + 1)
#define F_33 ",[%" STRING(ADDR_CHARS) "[^]]]:%d%n"
#define F_34 ",%" STRING(ADDR_CHARS) "[^:]:%d%n"
int V_12 ;
unsigned int V_54 ;
char V_19 [ F_32 ] ;
if ( sscanf ( * V_81 , L_41 , & V_3 -> V_17 , & V_12 ) == 1 &&
( ( * V_81 ) [ V_12 ] == 0 || ( * V_81 ) [ V_12 ] == ',' ) )
{
* V_81 += V_12 ;
}
else
{
for ( V_54 = 0 ; V_54 < sizeof V_3 -> V_19 / sizeof * V_3 -> V_19 ; V_54 ++ )
{
if ( ( sscanf ( * V_81 , F_33 , V_19 , & V_3 -> V_21 [ V_54 ] , & V_12 ) != 2 &&
sscanf ( * V_81 , F_34 , V_19 , & V_3 -> V_21 [ V_54 ] , & V_12 ) != 2 ) ||
V_3 -> V_21 [ V_54 ] <= 0 || V_3 -> V_21 [ V_54 ] > V_85 )
{
F_1 ( L_42 ) ;
}
if ( strcmp ( L_43 , F_35 ( V_19 ) ) == 0 )
{
if ( ! F_36 ( V_19 , (struct V_86 * ) V_3 -> V_28 [ V_54 ] ) )
{
F_1 ( L_44 ) ;
}
F_17 ( & V_3 -> V_19 [ V_54 ] , V_20 , 16 , V_3 -> V_28 [ V_54 ] ) ;
}
else
{
if ( ! F_37 ( V_19 , ( T_13 * ) V_3 -> V_28 [ V_54 ] ) )
{
F_1 ( L_45 ) ;
}
F_17 ( & V_3 -> V_19 [ V_54 ] , V_77 , 4 , V_3 -> V_28 [ V_54 ] ) ;
}
* V_81 += V_12 ;
}
if ( V_3 -> V_19 [ 0 ] . type != V_3 -> V_19 [ 1 ] . type )
{
F_1 ( L_46 ) ;
}
V_3 -> V_17 = V_18 ;
}
}
static void
F_38 (
const char * * V_81 ,
T_1 * V_3
)
{
int V_12 ;
if ( * * V_81 == 0 )
{
V_3 -> V_79 = 1 ;
V_3 -> V_78 = V_18 ;
}
else
{
if ( sscanf ( * V_81 , L_47 , & V_3 -> V_79 , & V_3 -> V_78 , & V_12 ) == 2 )
{
* V_81 += V_12 ;
}
else if ( sscanf ( * V_81 , L_41 , & V_3 -> V_79 , & V_12 ) == 1 )
{
V_3 -> V_78 = V_3 -> V_79 ;
* V_81 += V_12 ;
}
else
{
F_1 ( L_48 ) ;
}
if ( V_3 -> V_79 < 1 || V_3 -> V_79 > V_3 -> V_78 )
{
F_1 ( L_49 ) ;
}
}
}
static void
F_39 (
const char * V_81
)
{
if ( * V_81 != 0 )
{
F_1 ( L_50 ) ;
}
}
static void
F_40 (
const char * V_81 ,
void * T_20 V_31
)
{
T_1 * V_3 ;
T_21 * V_87 ;
V_81 += strlen ( V_88 ) ;
V_3 = F_15 ( V_4 ) ;
F_28 ( & V_81 , V_3 ) ;
F_29 ( & V_81 , V_3 ) ;
F_38 ( & V_81 , V_3 ) ;
F_39 ( V_81 ) ;
F_41 () ;
if ( V_3 -> V_17 != V_18 )
{
if ( ! F_42 ( V_3 -> V_17 ) )
{
F_1 ( L_51 ) ;
}
}
else
{
if ( ! F_43 ( & V_3 -> V_19 [ 0 ] , V_3 -> V_21 [ 0 ] ,
& V_3 -> V_19 [ 1 ] , V_3 -> V_21 [ 1 ] ) )
{
F_1 ( L_52 ) ;
}
}
F_11 ( V_3 ) ;
V_87 = F_44 ( L_53 , V_3 , NULL , 0 ,
NULL , NULL , F_24 ) ;
if ( V_87 != NULL )
{
F_18 ( V_3 ) ;
F_45 ( V_87 , TRUE ) ;
F_1 ( L_54 ) ;
}
}
static void
F_46 (
const char * V_81 ,
void * T_20 V_31
)
{
T_1 * V_3 ;
T_21 * V_87 ;
V_81 += strlen ( V_89 ) ;
V_3 = F_15 ( V_5 ) ;
F_28 ( & V_81 , V_3 ) ;
F_29 ( & V_81 , V_3 ) ;
F_38 ( & V_81 , V_3 ) ;
F_39 ( V_81 ) ;
if ( V_3 -> V_17 != V_18 )
{
F_1 ( L_55 ) ;
}
F_11 ( V_3 ) ;
V_87 = F_44 ( L_56 , V_3 , F_5 ( V_3 ) , 0 ,
NULL , F_19 , F_24 ) ;
if ( V_87 != NULL )
{
F_18 ( V_3 ) ;
F_45 ( V_87 , TRUE ) ;
F_1 ( L_57 ) ;
}
}
static void
F_47 (
const char * V_81 ,
void * T_20 V_31
)
{
T_1 * V_3 ;
T_21 * V_87 ;
V_81 += strlen ( V_90 ) ;
V_3 = F_15 ( V_6 ) ;
F_28 ( & V_81 , V_3 ) ;
F_29 ( & V_81 , V_3 ) ;
F_38 ( & V_81 , V_3 ) ;
F_39 ( V_81 ) ;
if ( V_3 -> V_17 == V_18 )
{
F_1 ( L_58 ) ;
}
F_11 ( V_3 ) ;
V_87 = F_44 ( L_4 , V_3 , F_5 ( V_3 ) , 0 ,
NULL , F_20 , F_24 ) ;
if ( V_87 != NULL )
{
F_18 ( V_3 ) ;
F_45 ( V_87 , TRUE ) ;
F_1 ( L_59 ) ;
}
}
void
F_48 ( void )
{
F_49 ( V_88 , F_40 , NULL ) ;
F_49 ( V_89 , F_46 , NULL ) ;
F_49 ( V_90 , F_47 , NULL ) ;
}
