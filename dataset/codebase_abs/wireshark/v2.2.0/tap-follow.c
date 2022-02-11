T_1 static void F_1 ( const char * V_1 )
{
fprintf ( V_2 , L_1 , V_1 ) ;
exit ( 1 ) ;
}
static const char * F_2 ( T_2 * V_3 )
{
switch ( V_3 -> V_4 )
{
case V_5 : return L_2 ;
case V_6 : return L_3 ;
case V_7 : return L_4 ;
case V_8 : return L_5 ;
default:
F_3 () ;
break;
}
F_3 () ;
return L_6 ;
}
static void
F_4 ( T_3 * V_9 )
{
T_2 * V_3 = ( T_2 * ) V_9 -> V_10 ;
F_5 ( V_3 ) ;
F_5 ( V_9 -> V_11 ) ;
F_5 ( V_9 ) ;
}
static void F_6 ( const char * V_12 , T_4 V_13 , void * V_14 , int V_15 )
{
int V_16 ;
int V_17 ;
int V_18 ;
T_5 V_19 ;
char line [ V_20 + 1 ] ;
for ( V_16 = 0 , V_17 = 0 , V_18 = 0 ; V_16 < V_15 ; )
{
if ( ( V_16 % V_21 ) == 0 )
{
F_7 ( line , V_20 + 1 , L_7 , V_22 , V_13 ) ;
memset ( line + V_23 - V_24 , ' ' ,
V_25 + V_24 + V_26 ) ;
V_17 = V_23 ;
V_18 = V_27 ;
}
V_19 = ( ( T_5 * ) V_14 ) [ V_16 ] ;
line [ V_17 ++ ] = V_28 [ V_19 >> 4 ] ;
line [ V_17 ++ ] = V_28 [ V_19 & 0xf ] ;
V_17 ++ ;
line [ V_18 ++ ] = V_19 >= ' ' && V_19 < 0x7f ? V_19 : '.' ;
if ( ++ V_16 % V_21 == V_21 / 2 )
{
line [ V_17 ++ ] = ' ' ;
line [ V_18 ++ ] = ' ' ;
}
if ( ( V_16 % V_21 ) == 0 || V_16 == V_15 )
{
if ( line [ V_18 - 1 ] == ' ' )
{
V_18 -- ;
}
line [ V_18 ] = 0 ;
printf ( L_8 , V_12 , line ) ;
V_13 += V_21 ;
}
}
}
static void F_8 ( void * V_29 )
{
static const char V_30 [] =
L_9 ;
T_3 * V_9 = ( T_3 * ) V_29 ;
T_2 * V_3 = ( T_2 * ) V_9 -> V_10 ;
T_6 V_31 [ V_32 ] ;
T_4 V_33 = 0 , V_34 = 0 ;
T_4 * V_35 ;
T_4 V_16 , V_17 ;
char * V_36 ;
T_7 * V_37 ;
T_8 * V_38 ;
T_9 V_39 ;
printf ( L_10 , V_30 ) ;
printf ( L_11 , F_9 ( F_10 ( V_3 -> V_40 ) ) , F_2 ( V_3 ) ) ;
printf ( L_12 , V_9 -> V_11 ) ;
F_11 ( & V_9 -> V_41 , V_31 , sizeof V_31 ) ;
if ( V_9 -> V_41 . type == V_42 )
printf ( L_13 , V_31 , V_9 -> V_43 ) ;
else
printf ( L_14 , V_31 , V_9 -> V_43 ) ;
F_11 ( & V_9 -> V_44 , V_31 , sizeof V_31 ) ;
if ( V_9 -> V_41 . type == V_42 )
printf ( L_15 , V_31 , V_9 -> V_45 ) ;
else
printf ( L_16 , V_31 , V_9 -> V_45 ) ;
for ( V_37 = V_9 -> V_46 , V_39 = 0 ;
V_37 != NULL ;
V_37 = F_12 ( V_37 ) , V_39 ++ )
{
V_38 = ( T_8 * ) V_37 -> V_47 ;
if ( ! V_38 -> V_48 ) {
V_35 = & V_33 ;
} else {
V_35 = & V_34 ;
}
if ( ( V_39 < V_3 -> V_49 ) || ( V_39 > V_3 -> V_50 ) ) {
( * V_35 ) += V_38 -> V_47 -> V_15 ;
continue;
}
switch ( V_3 -> V_4 )
{
case V_5 :
break;
case V_6 :
case V_7 :
printf ( L_17 , V_38 -> V_48 ? L_18 : L_19 , V_38 -> V_47 -> V_15 ) ;
break;
case V_8 :
if ( V_38 -> V_48 )
{
putchar ( '\t' ) ;
}
break;
default:
F_3 () ;
}
switch ( V_3 -> V_4 )
{
case V_5 :
F_6 ( V_38 -> V_48 ? L_18 : L_19 , * V_35 , V_38 -> V_47 -> V_47 , V_38 -> V_47 -> V_15 ) ;
( * V_35 ) += V_38 -> V_47 -> V_15 ;
break;
case V_6 :
case V_7 :
V_36 = ( char * ) F_13 ( V_38 -> V_47 -> V_15 + 2 ) ;
for ( V_16 = 0 ; V_16 < V_38 -> V_47 -> V_15 ; V_16 ++ )
{
switch ( V_38 -> V_47 -> V_47 [ V_16 ] )
{
case '\r' :
case '\n' :
V_36 [ V_16 ] = V_38 -> V_47 -> V_47 [ V_16 ] ;
break;
default:
V_36 [ V_16 ] = F_14 ( V_38 -> V_47 -> V_47 [ V_16 ] ) ? V_38 -> V_47 -> V_47 [ V_16 ] : '.' ;
break;
}
}
V_36 [ V_16 ++ ] = '\n' ;
V_36 [ V_16 ] = 0 ;
if ( V_3 -> V_4 == V_7 ) {
F_15 ( V_36 , V_16 ) ;
}
printf ( L_20 , V_36 ) ;
F_5 ( V_36 ) ;
break;
case V_8 :
V_36 = ( char * ) F_13 ( ( V_38 -> V_47 -> V_15 * 2 ) + 2 ) ;
for ( V_16 = 0 , V_17 = 0 ; V_16 < V_38 -> V_47 -> V_15 ; V_16 ++ )
{
V_36 [ V_17 ++ ] = V_28 [ V_38 -> V_47 -> V_47 [ V_16 ] >> 4 ] ;
V_36 [ V_17 ++ ] = V_28 [ V_38 -> V_47 -> V_47 [ V_16 ] & 0xf ] ;
}
V_36 [ V_17 ++ ] = '\n' ;
V_36 [ V_17 ] = 0 ;
printf ( L_20 , V_36 ) ;
F_5 ( V_36 ) ;
break;
default:
F_3 () ;
}
}
printf ( L_20 , V_30 ) ;
}
static T_10 F_16 ( const char * * V_51 , const char * V_1 )
{
T_11 V_15 = strlen ( V_1 ) ;
if ( strncmp ( * V_51 , V_1 , V_15 ) == 0 )
{
* V_51 += V_15 ;
return TRUE ;
}
return FALSE ;
}
static void
F_17 ( const char * * V_51 , T_3 * V_9 )
{
T_2 * V_3 = ( T_2 * ) V_9 -> V_10 ;
if ( F_16 ( V_51 , V_52 ) )
{
V_3 -> V_4 = V_5 ;
}
else if ( F_16 ( V_51 , V_53 ) )
{
V_3 -> V_4 = V_6 ;
}
else if ( F_16 ( V_51 , V_54 ) )
{
V_3 -> V_4 = V_7 ;
}
else if ( F_16 ( V_51 , V_55 ) )
{
V_3 -> V_4 = V_8 ;
}
else
{
F_1 ( L_21 ) ;
}
}
static void
F_18 ( const char * * V_51 , T_3 * V_9 )
{
int V_15 ;
unsigned int V_16 ;
char V_56 [ V_57 ] ;
T_2 * V_3 = ( T_2 * ) V_9 -> V_10 ;
T_10 V_58 ;
if ( sscanf ( * V_51 , L_22 , & V_3 -> V_59 , & V_15 ) == 1 &&
( ( * V_51 ) [ V_15 ] == 0 || ( * V_51 ) [ V_15 ] == ',' ) )
{
* V_51 += V_15 ;
}
else
{
for ( V_16 = 0 ; V_16 < sizeof V_3 -> V_56 / sizeof * V_3 -> V_56 ; V_16 ++ )
{
if ( sscanf ( * V_51 , V_60 , V_56 , & V_3 -> V_61 [ V_16 ] , & V_15 ) == 2 )
{
V_58 = TRUE ;
}
else if ( sscanf ( * V_51 , V_62 , V_56 , & V_3 -> V_61 [ V_16 ] , & V_15 ) == 2 )
{
V_58 = FALSE ;
}
else
{
F_1 ( L_23 ) ;
}
if ( V_3 -> V_61 [ V_16 ] <= 0 || V_3 -> V_61 [ V_16 ] > V_63 )
{
F_1 ( L_24 ) ;
}
if ( V_58 )
{
if ( ! F_19 ( V_56 , (struct V_64 * ) V_3 -> V_65 [ V_16 ] ) )
{
F_1 ( L_25 ) ;
}
F_20 ( & V_3 -> V_56 [ V_16 ] , V_42 , 16 , V_3 -> V_65 [ V_16 ] ) ;
}
else
{
if ( ! F_21 ( V_56 , ( T_4 * ) V_3 -> V_65 [ V_16 ] ) )
{
F_1 ( L_26 ) ;
}
F_20 ( & V_3 -> V_56 [ V_16 ] , V_66 , 4 , V_3 -> V_65 [ V_16 ] ) ;
}
* V_51 += V_15 ;
}
if ( V_3 -> V_56 [ 0 ] . type != V_3 -> V_56 [ 1 ] . type )
{
F_1 ( L_27 ) ;
}
V_3 -> V_59 = - 1 ;
}
}
static void F_22 ( const char * * V_51 , T_2 * V_3 )
{
int V_15 ;
if ( * * V_51 == 0 )
{
V_3 -> V_49 = 1 ;
V_3 -> V_50 = V_67 ;
}
else
{
if ( sscanf ( * V_51 , L_28 , & V_3 -> V_49 , & V_3 -> V_50 , & V_15 ) == 2 )
{
* V_51 += V_15 ;
}
else if ( sscanf ( * V_51 , L_29 , & V_3 -> V_49 , & V_15 ) == 1 )
{
V_3 -> V_50 = V_3 -> V_49 ;
* V_51 += V_15 ;
}
else
{
F_1 ( L_30 ) ;
}
if ( V_3 -> V_49 < 1 || V_3 -> V_49 > V_3 -> V_50 )
{
F_1 ( L_31 ) ;
}
}
}
static void
F_23 ( const char * V_51 )
{
if ( * V_51 != 0 )
{
F_1 ( L_32 ) ;
}
}
static void F_24 ( const char * V_51 , void * V_68 )
{
T_3 * V_9 ;
T_2 * V_3 ;
T_12 * V_69 ;
T_13 * V_40 = ( T_13 * ) V_68 ;
T_14 V_70 ;
T_15 V_71 ;
V_51 += strlen ( V_72 ) ;
V_51 += strlen ( F_9 ( F_10 ( V_40 ) ) ) ;
V_3 = F_25 ( T_2 , 1 ) ;
V_9 = F_25 ( T_3 , 1 ) ;
V_9 -> V_10 = V_3 ;
V_3 -> V_40 = V_40 ;
F_17 ( & V_51 , V_9 ) ;
F_18 ( & V_51 , V_9 ) ;
F_22 ( & V_51 , V_3 ) ;
F_23 ( V_51 ) ;
if ( V_3 -> V_59 >= 0 )
{
V_70 = F_26 ( V_40 ) ;
V_9 -> V_11 = V_70 ( V_3 -> V_59 ) ;
if ( V_9 -> V_11 == NULL )
{
F_1 ( L_33 ) ;
}
}
else
{
V_71 = F_27 ( V_40 ) ;
V_9 -> V_11 = V_71 ( & V_3 -> V_56 [ 0 ] , & V_3 -> V_56 [ 1 ] , V_3 -> V_61 [ 0 ] , V_3 -> V_61 [ 1 ] ) ;
if ( V_9 -> V_11 == NULL )
{
F_1 ( L_34 ) ;
}
}
V_69 = F_28 ( F_29 ( V_40 ) , V_9 , V_9 -> V_11 , 0 ,
NULL , F_30 ( V_40 ) , F_8 ) ;
if ( V_69 != NULL )
{
F_4 ( V_9 ) ;
F_31 ( V_69 , TRUE ) ;
F_1 ( L_35 ) ;
}
}
static void
F_32 ( T_16 V_47 , T_16 T_17 V_73 )
{
T_13 * V_40 = ( T_13 * ) V_47 ;
T_18 V_74 ;
V_74 . V_75 = V_76 ;
V_74 . V_77 = NULL ;
V_74 . V_78 = F_33 ( V_40 ) ;
V_74 . V_79 = F_24 ;
V_74 . V_80 = 0 ;
V_74 . V_81 = NULL ;
F_34 ( & V_74 , V_40 ) ;
}
void
F_35 ( void )
{
F_36 ( F_32 , NULL ) ;
}
