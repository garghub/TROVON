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
}
F_3 () ;
return L_4 ;
}
static const char *
F_4 (
const T_1 * V_3
)
{
switch ( V_3 -> V_6 )
{
case V_7 : return L_5 ;
case V_8 : return L_6 ;
case V_9 : return L_7 ;
}
F_3 () ;
return L_8 ;
}
static const char *
F_5 (
const T_1 * V_3
)
{
static char V_10 [ 512 ] ;
int V_11 = 0 ;
const T_2 * V_12 ;
T_2 V_13 [ V_14 ] ;
T_2 V_15 [ V_14 ] ;
if ( V_3 -> V_16 != V_17 )
{
switch ( V_3 -> type )
{
case V_4 :
V_11 = F_6 ( V_10 , sizeof V_10 ,
L_9 , V_3 -> V_16 ) ;
break;
case V_5 :
break;
}
}
else
{
V_12 = V_3 -> V_18 [ 0 ] . type == V_19 ? L_10 : L_11 ;
F_7 ( & V_3 -> V_18 [ 0 ] , V_13 , sizeof V_13 ) ;
F_7 ( & V_3 -> V_18 [ 1 ] , V_15 , sizeof V_15 ) ;
switch ( V_3 -> type )
{
case V_4 :
V_11 = F_6 ( V_10 , sizeof V_10 ,
L_12
L_13
L_14
L_12
L_13 ,
V_12 , V_13 , V_3 -> V_20 [ 0 ] ,
V_12 , V_15 , V_3 -> V_20 [ 1 ] ,
V_12 , V_15 , V_3 -> V_20 [ 1 ] ,
V_12 , V_13 , V_3 -> V_20 [ 0 ] ) ;
break;
case V_5 :
V_11 = F_6 ( V_10 , sizeof V_10 ,
L_15
L_16
L_14
L_15
L_16 ,
V_12 , V_13 , V_3 -> V_20 [ 0 ] ,
V_12 , V_15 , V_3 -> V_20 [ 1 ] ,
V_12 , V_15 , V_3 -> V_20 [ 1 ] ,
V_12 , V_13 , V_3 -> V_20 [ 0 ] ) ;
break;
}
}
if ( V_11 == 0 )
{
F_1 ( L_17 ) ;
}
if ( V_11 == sizeof V_10 )
{
F_1 ( L_18 ) ;
}
return V_10 ;
}
static void
F_8 (
T_1 * V_3
)
{
if ( V_3 -> V_21 != NULL )
{
fclose ( V_3 -> V_21 ) ;
V_3 -> V_21 = NULL ;
if ( V_3 -> type == V_4 )
{
V_22 = NULL ;
}
}
if ( V_3 -> V_23 != NULL )
{
F_9 ( V_3 -> V_23 ) ;
F_10 ( V_3 -> V_23 ) ;
V_3 -> V_23 = NULL ;
}
}
static void
F_11 (
T_1 * V_3
)
{
int V_24 ;
char * V_25 ;
if ( V_3 -> type == V_4 && V_22 != NULL )
{
F_1 ( L_19 ) ;
}
F_8 ( V_3 ) ;
V_24 = F_12 ( & V_25 , L_20 ) ;
if ( V_24 == - 1 )
{
F_1 ( L_21 ) ;
}
V_3 -> V_23 = F_13 ( V_25 ) ;
if ( V_3 -> V_23 == NULL )
{
F_14 ( V_24 ) ;
F_9 ( V_25 ) ;
F_1 ( L_22 ) ;
}
V_3 -> V_21 = fdopen ( V_24 , L_23 ) ;
if ( V_3 -> V_21 == NULL )
{
F_14 ( V_24 ) ;
F_9 ( V_3 -> V_23 ) ;
F_10 ( V_3 -> V_23 ) ;
V_3 -> V_23 = NULL ;
F_1 ( L_24 ) ;
}
if ( V_3 -> type == V_4 )
{
V_22 = V_3 -> V_21 ;
}
}
static T_1 *
F_15 (
T_3 type
)
{
T_1 * V_3 ;
V_3 = F_16 ( sizeof *V_3 ) ;
V_3 -> type = type ;
F_17 ( & V_3 -> V_18 [ 0 ] , V_26 , 0 , V_3 -> V_27 [ 0 ] ) ;
F_17 ( & V_3 -> V_18 [ 1 ] , V_26 , 0 , V_3 -> V_27 [ 1 ] ) ;
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
void * V_28 ,
T_4 * V_29 ,
T_5 * T_6 V_30 ,
const void * V_31
)
{
T_1 * V_3 = V_28 ;
const T_7 * V_32 = V_31 ;
T_8 V_33 ;
T_9 V_34 ;
if ( V_32 -> V_35 > 0 )
{
memcpy ( V_33 . V_36 , V_29 -> V_37 . V_38 , V_29 -> V_37 . V_11 ) ;
V_33 . V_39 = V_29 -> V_40 ;
V_33 . V_41 = V_32 -> V_35 ;
V_34 = fwrite ( & V_33 , 1 , sizeof V_33 , V_3 -> V_21 ) ;
if ( sizeof V_33 != V_34 )
{
F_1 ( L_25 ) ;
}
V_34 = fwrite ( V_32 -> V_42 , 1 , V_33 . V_41 , V_3 -> V_21 ) ;
if ( V_33 . V_41 != V_34 )
{
F_1 ( L_26 ) ;
}
}
return 0 ;
}
static void
F_20 (
const char * V_43 ,
T_10 V_44 ,
void * V_31 ,
int V_11
)
{
int V_45 ;
int V_46 ;
int V_47 ;
T_11 V_48 ;
char line [ V_49 + 1 ] ;
for ( V_45 = 0 , V_46 = 0 , V_47 = 0 ; V_45 < V_11 ; )
{
if ( ( V_45 % V_50 ) == 0 )
{
F_6 ( line , V_49 + 1 , L_27 , V_51 , V_44 ) ;
memset ( line + V_52 - V_53 , ' ' ,
V_54 + V_53 + V_55 ) ;
V_46 = V_52 ;
V_47 = V_56 ;
}
V_48 = ( ( T_11 * ) V_31 ) [ V_45 ] ;
line [ V_46 ++ ] = V_57 [ V_48 >> 4 ] ;
line [ V_46 ++ ] = V_57 [ V_48 & 0xf ] ;
V_46 ++ ;
line [ V_47 ++ ] = V_48 >= ' ' && V_48 < 0x7f ? V_48 : '.' ;
if ( ++ V_45 % V_50 == V_50 / 2 )
{
line [ V_46 ++ ] = ' ' ;
line [ V_47 ++ ] = ' ' ;
}
if ( ( V_45 % V_50 ) == 0 || V_45 == V_11 )
{
if ( line [ V_47 - 1 ] == ' ' )
{
V_47 -- ;
}
line [ V_47 ] = 0 ;
printf ( L_28 , V_43 , line ) ;
V_44 += V_50 ;
}
}
}
static void
F_21 (
void * V_28
)
{
static const char V_58 [] =
L_29 ;
T_1 * V_3 = V_28 ;
T_8 V_33 ;
int V_59 ;
const T_12 * V_18 [ 2 ] ;
int V_20 [ 2 ] ;
T_2 V_60 [ V_14 ] ;
T_10 V_45 ;
T_10 V_46 ;
T_10 V_11 ;
T_10 V_61 ;
T_10 V_44 [ 2 ] ;
T_11 V_62 [ 4096 ] ;
char V_38 [ ( sizeof V_62 * 2 ) + 2 ] ;
F_22 ( sizeof V_62 % V_50 == 0 ) ;
if ( V_3 -> type == V_4 )
{
T_13 V_63 ;
T_14 type ;
F_23 ( & V_63 ) ;
if ( V_63 . V_64 )
{
type = V_19 ;
V_11 = 16 ;
}
else
{
type = V_65 ;
V_11 = 4 ;
}
for ( V_59 = 0 ; V_59 < 2 ; V_59 ++ )
{
memcpy ( V_3 -> V_27 [ V_59 ] , V_63 . V_66 [ V_59 ] , V_11 ) ;
F_17 ( & V_3 -> V_18 [ V_59 ] , type , V_11 , V_3 -> V_27 [ V_59 ] ) ;
V_3 -> V_20 [ V_59 ] = V_63 . V_20 [ V_59 ] ;
}
}
rewind ( V_3 -> V_21 ) ;
for ( V_61 = 0 ; ; )
{
V_11 = ( T_10 ) fread ( & V_33 , 1 , sizeof V_33 , V_3 -> V_21 ) ;
if ( V_11 != sizeof V_33 )
{
V_33 . V_41 = 0 ;
memcpy ( V_33 . V_36 , V_3 -> V_18 [ 0 ] . V_38 , V_3 -> V_18 [ 0 ] . V_11 ) ;
V_33 . V_39 = V_3 -> V_20 [ 0 ] ;
break;
}
if ( V_33 . V_41 > 0 )
{
V_61 ++ ;
break;
}
}
if ( memcmp ( V_33 . V_36 , V_3 -> V_18 [ 0 ] . V_38 , V_3 -> V_18 [ 0 ] . V_11 ) == 0 &&
V_33 . V_39 == V_3 -> V_20 [ 0 ] )
{
V_18 [ 0 ] = & V_3 -> V_18 [ 0 ] ;
V_20 [ 0 ] = V_3 -> V_20 [ 0 ] ;
V_18 [ 1 ] = & V_3 -> V_18 [ 1 ] ;
V_20 [ 1 ] = V_3 -> V_20 [ 1 ] ;
}
else
{
V_18 [ 0 ] = & V_3 -> V_18 [ 1 ] ;
V_20 [ 0 ] = V_3 -> V_20 [ 1 ] ;
V_18 [ 1 ] = & V_3 -> V_18 [ 0 ] ;
V_20 [ 1 ] = V_3 -> V_20 [ 0 ] ;
}
printf ( L_30 , V_58 ) ;
printf ( L_31 , F_2 ( V_3 ) , F_4 ( V_3 ) ) ;
printf ( L_32 , F_5 ( V_3 ) ) ;
for ( V_59 = 0 ; V_59 < 2 ; V_59 ++ )
{
F_7 ( V_18 [ V_59 ] , V_60 , sizeof V_60 ) ;
if ( V_18 [ V_59 ] -> type == V_19 )
{
printf ( L_33 , V_59 , V_60 , V_20 [ V_59 ] ) ;
}
else
{
printf ( L_34 , V_59 , V_60 , V_20 [ V_59 ] ) ;
}
}
V_44 [ 0 ] = V_44 [ 1 ] = 0 ;
while ( V_61 <= V_3 -> V_67 )
{
V_59 = ( memcmp ( V_18 [ 0 ] -> V_38 , V_33 . V_36 , V_18 [ 0 ] -> V_11 ) == 0 &&
V_20 [ 0 ] == V_33 . V_39 ) ? 0 : 1 ;
if ( V_61 < V_3 -> V_68 )
{
while ( V_33 . V_41 > 0 )
{
V_11 = V_33 . V_41 < sizeof V_62 ? V_33 . V_41 : sizeof V_62 ;
V_33 . V_41 -= V_11 ;
if ( fread ( V_62 , 1 , V_11 , V_3 -> V_21 ) != V_11 )
{
F_1 ( L_35 ) ;
}
V_44 [ V_59 ] += V_11 ;
}
}
else
{
switch ( V_3 -> V_6 )
{
case V_7 :
break;
case V_8 :
printf ( L_36 , V_59 ? L_37 : L_11 , V_33 . V_41 ) ;
break;
case V_9 :
if ( V_59 )
{
putchar ( '\t' ) ;
}
break;
}
while ( V_33 . V_41 > 0 )
{
V_11 = V_33 . V_41 < sizeof V_62 ? V_33 . V_41 : sizeof V_62 ;
V_33 . V_41 -= V_11 ;
if ( fread ( V_62 , 1 , V_11 , V_3 -> V_21 ) != V_11 )
{
F_1 ( L_35 ) ;
}
switch ( V_3 -> V_6 )
{
case V_7 :
F_20 ( V_59 ? L_37 : L_11 , V_44 [ V_59 ] , V_62 , V_11 ) ;
break;
case V_8 :
for ( V_45 = 0 ; V_45 < V_11 ; V_45 ++ )
{
switch ( V_62 [ V_45 ] )
{
case '\r' :
case '\n' :
V_38 [ V_45 ] = V_62 [ V_45 ] ;
break;
default:
V_38 [ V_45 ] = isprint ( V_62 [ V_45 ] ) ? V_62 [ V_45 ] : '.' ;
break;
}
}
if ( V_33 . V_41 == 0 )
{
V_38 [ V_45 ++ ] = '\n' ;
}
V_38 [ V_45 ] = 0 ;
printf ( L_38 , V_38 ) ;
break;
case V_9 :
for ( V_45 = 0 , V_46 = 0 ; V_45 < V_11 ; V_45 ++ )
{
V_38 [ V_46 ++ ] = V_57 [ V_62 [ V_45 ] >> 4 ] ;
V_38 [ V_46 ++ ] = V_57 [ V_62 [ V_45 ] & 0xf ] ;
}
if ( V_33 . V_41 == 0 )
{
V_38 [ V_46 ++ ] = '\n' ;
}
V_38 [ V_46 ] = 0 ;
printf ( L_38 , V_38 ) ;
}
V_44 [ V_59 ] += V_11 ;
}
}
for (; ; )
{
V_11 = ( T_10 ) fread ( & V_33 , 1 , sizeof V_33 , V_3 -> V_21 ) ;
if ( V_11 != sizeof V_33 )
{
V_33 . V_41 = 0 ;
V_61 = V_17 ;
goto V_69;
}
if ( V_33 . V_41 > 0 )
{
V_61 ++ ;
break;
}
}
}
V_69:
printf ( L_38 , V_58 ) ;
F_8 ( V_3 ) ;
}
static T_15
F_24 (
const char * * V_70 ,
const char * V_1
)
{
int V_11 = ( T_10 ) strlen ( V_1 ) ;
if ( strncmp ( * V_70 , V_1 , V_11 ) == 0 )
{
* V_70 += V_11 ;
return TRUE ;
}
return FALSE ;
}
static void
F_25 (
const char * * V_70 ,
T_1 * V_3
)
{
if ( F_24 ( V_70 , V_71 ) )
{
V_3 -> V_6 = V_7 ;
}
else if ( F_24 ( V_70 , V_72 ) )
{
V_3 -> V_6 = V_8 ;
}
else if ( F_24 ( V_70 , V_73 ) )
{
V_3 -> V_6 = V_9 ;
}
else
{
F_1 ( L_39 ) ;
}
}
static void
F_26 (
const char * * V_70 ,
T_1 * V_3
)
{
#define F_27 ( T_16 ) # s
#define STRING ( T_16 ) _STRING(s)
#define F_28 80
#define F_29 (ADDR_CHARS + 1)
#define F_30 ",[%" STRING(ADDR_CHARS) "[^]]]:%d%n"
#define F_31 ",%" STRING(ADDR_CHARS) "[^:]:%d%n"
int V_11 ;
unsigned int V_45 ;
char V_18 [ F_29 ] ;
if ( sscanf ( * V_70 , L_40 , & V_3 -> V_16 , & V_11 ) == 1 &&
( ( * V_70 ) [ V_11 ] == 0 || ( * V_70 ) [ V_11 ] == ',' ) )
{
* V_70 += V_11 ;
}
else
{
for ( V_45 = 0 ; V_45 < sizeof V_3 -> V_18 / sizeof * V_3 -> V_18 ; V_45 ++ )
{
if ( ( sscanf ( * V_70 , F_30 , V_18 , & V_3 -> V_20 [ V_45 ] , & V_11 ) != 2 &&
sscanf ( * V_70 , F_31 , V_18 , & V_3 -> V_20 [ V_45 ] , & V_11 ) != 2 ) ||
V_3 -> V_20 [ V_45 ] <= 0 || V_3 -> V_20 [ V_45 ] > V_74 )
{
F_1 ( L_41 ) ;
}
if ( strcmp ( L_42 , F_32 ( V_18 ) ) == 0 )
{
if ( ! F_33 ( V_18 , (struct V_75 * ) V_3 -> V_27 [ V_45 ] ) )
{
F_1 ( L_43 ) ;
}
F_17 ( & V_3 -> V_18 [ V_45 ] , V_19 , 16 , V_3 -> V_27 [ V_45 ] ) ;
}
else
{
if ( ! F_34 ( V_18 , ( T_10 * ) V_3 -> V_27 [ V_45 ] ) )
{
F_1 ( L_44 ) ;
}
F_17 ( & V_3 -> V_18 [ V_45 ] , V_65 , 4 , V_3 -> V_27 [ V_45 ] ) ;
}
* V_70 += V_11 ;
}
if ( V_3 -> V_18 [ 0 ] . type != V_3 -> V_18 [ 1 ] . type )
{
F_1 ( L_45 ) ;
}
V_3 -> V_16 = V_17 ;
}
}
static void
F_35 (
const char * * V_70 ,
T_1 * V_3
)
{
int V_11 ;
if ( * * V_70 == 0 )
{
V_3 -> V_68 = 1 ;
V_3 -> V_67 = V_17 ;
}
else
{
if ( sscanf ( * V_70 , L_46 , & V_3 -> V_68 , & V_3 -> V_67 , & V_11 ) == 2 )
{
* V_70 += V_11 ;
}
else if ( sscanf ( * V_70 , L_40 , & V_3 -> V_68 , & V_11 ) == 1 )
{
V_3 -> V_67 = V_3 -> V_68 ;
* V_70 += V_11 ;
}
else
{
F_1 ( L_47 ) ;
}
if ( V_3 -> V_68 < 1 || V_3 -> V_68 > V_3 -> V_67 )
{
F_1 ( L_48 ) ;
}
}
}
static void
F_36 (
const char * V_76
)
{
if ( * V_76 != 0 )
{
F_1 ( L_49 ) ;
}
}
static void
F_37 (
const char * V_76 ,
void * T_17 V_30
)
{
T_1 * V_3 ;
T_18 * V_77 ;
V_76 += strlen ( V_78 ) ;
V_3 = F_15 ( V_4 ) ;
F_25 ( & V_76 , V_3 ) ;
F_26 ( & V_76 , V_3 ) ;
F_35 ( & V_76 , V_3 ) ;
F_36 ( V_76 ) ;
F_38 () ;
if ( V_3 -> V_16 != V_17 )
{
if ( ! F_39 ( V_3 -> V_16 ) )
{
F_1 ( L_50 ) ;
}
}
else
{
if ( ! F_40 ( & V_3 -> V_18 [ 0 ] , V_3 -> V_20 [ 0 ] ,
& V_3 -> V_18 [ 1 ] , V_3 -> V_20 [ 1 ] ) )
{
F_1 ( L_51 ) ;
}
}
F_11 ( V_3 ) ;
V_77 = F_41 ( L_52 , V_3 , NULL , 0 ,
NULL , NULL , F_21 ) ;
if ( V_77 != NULL )
{
F_18 ( V_3 ) ;
F_42 ( V_77 , TRUE ) ;
F_1 ( L_53 ) ;
}
}
static void
F_43 (
const char * V_76 ,
void * T_17 V_30
)
{
T_1 * V_3 ;
T_18 * V_77 ;
V_76 += strlen ( V_79 ) ;
V_3 = F_15 ( V_5 ) ;
F_25 ( & V_76 , V_3 ) ;
F_26 ( & V_76 , V_3 ) ;
F_35 ( & V_76 , V_3 ) ;
F_36 ( V_76 ) ;
if ( V_3 -> V_16 != V_17 )
{
F_1 ( L_54 ) ;
}
F_11 ( V_3 ) ;
V_77 = F_41 ( L_55 , V_3 , F_5 ( V_3 ) , 0 ,
NULL , F_19 , F_21 ) ;
if ( V_77 != NULL )
{
F_18 ( V_3 ) ;
F_42 ( V_77 , TRUE ) ;
F_1 ( L_56 ) ;
}
}
void
F_44 ( void )
{
F_45 ( V_78 , F_37 , NULL ) ;
F_45 ( V_79 , F_43 , NULL ) ;
}
