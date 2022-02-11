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
F_6 ( V_9 ) ;
}
static void F_7 ( const char * V_11 , T_4 V_12 , void * V_13 , int V_14 )
{
int V_15 ;
int V_16 ;
int V_17 ;
T_5 V_18 ;
char line [ V_19 + 1 ] ;
for ( V_15 = 0 , V_16 = 0 , V_17 = 0 ; V_15 < V_14 ; )
{
if ( ( V_15 % V_20 ) == 0 )
{
F_8 ( line , V_19 + 1 , L_7 , V_21 , V_12 ) ;
memset ( line + V_22 - V_23 , ' ' ,
V_24 + V_23 + V_25 ) ;
V_16 = V_22 ;
V_17 = V_26 ;
}
V_18 = ( ( T_5 * ) V_13 ) [ V_15 ] ;
line [ V_16 ++ ] = V_27 [ V_18 >> 4 ] ;
line [ V_16 ++ ] = V_27 [ V_18 & 0xf ] ;
V_16 ++ ;
line [ V_17 ++ ] = V_18 >= ' ' && V_18 < 0x7f ? V_18 : '.' ;
if ( ++ V_15 % V_20 == V_20 / 2 )
{
line [ V_16 ++ ] = ' ' ;
line [ V_17 ++ ] = ' ' ;
}
if ( ( V_15 % V_20 ) == 0 || V_15 == V_14 )
{
if ( line [ V_17 - 1 ] == ' ' )
{
V_17 -- ;
}
line [ V_17 ] = 0 ;
printf ( L_8 , V_11 , line ) ;
V_12 += V_20 ;
}
}
}
static void F_9 ( void * V_28 )
{
static const char V_29 [] =
L_9 ;
T_3 * V_9 = ( T_3 * ) V_28 ;
T_2 * V_3 = ( T_2 * ) V_9 -> V_10 ;
T_6 V_30 [ V_31 ] ;
T_4 V_32 = 0 , V_33 = 0 ;
T_4 * V_34 ;
T_4 V_15 , V_16 ;
char * V_35 ;
T_7 * V_36 ;
T_8 * V_37 ;
T_9 V_38 ;
printf ( L_10 , V_29 ) ;
printf ( L_11 , F_10 ( F_11 ( V_3 -> V_39 ) ) , F_2 ( V_3 ) ) ;
printf ( L_12 , V_9 -> V_40 ) ;
F_12 ( & V_9 -> V_41 , V_30 , sizeof V_30 ) ;
if ( V_9 -> V_41 . type == V_42 )
printf ( L_13 , V_30 , V_9 -> V_43 ) ;
else
printf ( L_14 , V_30 , V_9 -> V_43 ) ;
F_12 ( & V_9 -> V_44 , V_30 , sizeof V_30 ) ;
if ( V_9 -> V_41 . type == V_42 )
printf ( L_15 , V_30 , V_9 -> V_45 ) ;
else
printf ( L_16 , V_30 , V_9 -> V_45 ) ;
for ( V_36 = V_9 -> V_46 , V_38 = 1 ;
V_36 != NULL ;
V_36 = F_13 ( V_36 ) , V_38 ++ )
{
V_37 = ( T_8 * ) V_36 -> V_47 ;
if ( ! V_37 -> V_48 ) {
V_34 = & V_32 ;
} else {
V_34 = & V_33 ;
}
if ( ( V_38 < V_3 -> V_49 ) || ( V_38 > V_3 -> V_50 ) ) {
( * V_34 ) += V_37 -> V_47 -> V_14 ;
continue;
}
switch ( V_3 -> V_4 )
{
case V_5 :
break;
case V_6 :
case V_7 :
printf ( L_17 , V_37 -> V_48 ? L_18 : L_19 , V_37 -> V_47 -> V_14 ) ;
break;
case V_8 :
if ( V_37 -> V_48 )
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
F_7 ( V_37 -> V_48 ? L_18 : L_19 , * V_34 , V_37 -> V_47 -> V_47 , V_37 -> V_47 -> V_14 ) ;
( * V_34 ) += V_37 -> V_47 -> V_14 ;
break;
case V_6 :
case V_7 :
V_35 = ( char * ) F_14 ( V_37 -> V_47 -> V_14 + 2 ) ;
for ( V_15 = 0 ; V_15 < V_37 -> V_47 -> V_14 ; V_15 ++ )
{
switch ( V_37 -> V_47 -> V_47 [ V_15 ] )
{
case '\r' :
case '\n' :
V_35 [ V_15 ] = V_37 -> V_47 -> V_47 [ V_15 ] ;
break;
default:
V_35 [ V_15 ] = F_15 ( V_37 -> V_47 -> V_47 [ V_15 ] ) ? V_37 -> V_47 -> V_47 [ V_15 ] : '.' ;
break;
}
}
V_35 [ V_15 ++ ] = '\n' ;
V_35 [ V_15 ] = 0 ;
if ( V_3 -> V_4 == V_7 ) {
F_16 ( V_35 , V_15 ) ;
}
printf ( L_20 , V_35 ) ;
F_5 ( V_35 ) ;
break;
case V_8 :
V_35 = ( char * ) F_14 ( ( V_37 -> V_47 -> V_14 * 2 ) + 2 ) ;
for ( V_15 = 0 , V_16 = 0 ; V_15 < V_37 -> V_47 -> V_14 ; V_15 ++ )
{
V_35 [ V_16 ++ ] = V_27 [ V_37 -> V_47 -> V_47 [ V_15 ] >> 4 ] ;
V_35 [ V_16 ++ ] = V_27 [ V_37 -> V_47 -> V_47 [ V_15 ] & 0xf ] ;
}
V_35 [ V_16 ++ ] = '\n' ;
V_35 [ V_16 ] = 0 ;
printf ( L_20 , V_35 ) ;
F_5 ( V_35 ) ;
break;
default:
F_3 () ;
}
}
printf ( L_20 , V_29 ) ;
}
static T_10 F_17 ( const char * * V_51 , const char * V_1 )
{
T_11 V_14 = strlen ( V_1 ) ;
if ( strncmp ( * V_51 , V_1 , V_14 ) == 0 )
{
* V_51 += V_14 ;
return TRUE ;
}
return FALSE ;
}
static void
F_18 ( const char * * V_51 , T_3 * V_9 )
{
T_2 * V_3 = ( T_2 * ) V_9 -> V_10 ;
if ( F_17 ( V_51 , V_52 ) )
{
V_3 -> V_4 = V_5 ;
}
else if ( F_17 ( V_51 , V_53 ) )
{
V_3 -> V_4 = V_6 ;
}
else if ( F_17 ( V_51 , V_54 ) )
{
V_3 -> V_4 = V_7 ;
}
else if ( F_17 ( V_51 , V_55 ) )
{
V_3 -> V_4 = V_8 ;
}
else
{
F_1 ( L_21 ) ;
}
}
static void
F_19 ( const char * * V_51 , T_3 * V_9 )
{
int V_14 ;
unsigned int V_15 ;
char V_56 [ V_57 ] ;
T_2 * V_3 = ( T_2 * ) V_9 -> V_10 ;
T_10 V_58 ;
if ( sscanf ( * V_51 , L_22 , & V_3 -> V_59 , & V_14 ) == 1 &&
( ( * V_51 ) [ V_14 ] == 0 || ( * V_51 ) [ V_14 ] == ',' ) )
{
* V_51 += V_14 ;
}
else
{
for ( V_15 = 0 ; V_15 < sizeof V_3 -> V_56 / sizeof * V_3 -> V_56 ; V_15 ++ )
{
if ( sscanf ( * V_51 , V_60 , V_56 , & V_3 -> V_61 [ V_15 ] , & V_14 ) == 2 )
{
V_58 = TRUE ;
}
else if ( sscanf ( * V_51 , V_62 , V_56 , & V_3 -> V_61 [ V_15 ] , & V_14 ) == 2 )
{
V_58 = FALSE ;
}
else
{
F_1 ( L_23 ) ;
}
if ( V_3 -> V_61 [ V_15 ] <= 0 || V_3 -> V_61 [ V_15 ] > V_63 )
{
F_1 ( L_24 ) ;
}
if ( V_58 )
{
if ( ! F_20 ( V_56 , (struct V_64 * ) V_3 -> V_65 [ V_15 ] ) )
{
F_1 ( L_25 ) ;
}
F_21 ( & V_3 -> V_56 [ V_15 ] , V_42 , 16 , V_3 -> V_65 [ V_15 ] ) ;
}
else
{
if ( ! F_22 ( V_56 , ( T_4 * ) V_3 -> V_65 [ V_15 ] ) )
{
F_1 ( L_26 ) ;
}
F_21 ( & V_3 -> V_56 [ V_15 ] , V_66 , 4 , V_3 -> V_65 [ V_15 ] ) ;
}
* V_51 += V_14 ;
}
if ( V_3 -> V_56 [ 0 ] . type != V_3 -> V_56 [ 1 ] . type )
{
F_1 ( L_27 ) ;
}
V_3 -> V_59 = - 1 ;
}
}
static void F_23 ( const char * * V_51 , T_2 * V_3 )
{
int V_14 ;
if ( * * V_51 == 0 )
{
V_3 -> V_49 = 1 ;
V_3 -> V_50 = V_67 ;
}
else
{
if ( sscanf ( * V_51 , L_28 , & V_3 -> V_49 , & V_3 -> V_50 , & V_14 ) == 2 )
{
* V_51 += V_14 ;
}
else if ( sscanf ( * V_51 , L_29 , & V_3 -> V_49 , & V_14 ) == 1 )
{
V_3 -> V_50 = V_3 -> V_49 ;
* V_51 += V_14 ;
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
F_24 ( const char * V_51 )
{
if ( * V_51 != 0 )
{
F_1 ( L_32 ) ;
}
}
static void F_25 ( const char * V_51 , void * V_68 )
{
T_3 * V_9 ;
T_2 * V_3 ;
T_12 * V_69 ;
T_13 * V_39 = ( T_13 * ) V_68 ;
T_14 V_70 ;
T_15 V_71 ;
V_51 += strlen ( V_72 ) ;
V_51 += strlen ( F_10 ( F_11 ( V_39 ) ) ) ;
V_3 = F_26 ( T_2 , 1 ) ;
V_9 = F_26 ( T_3 , 1 ) ;
V_9 -> V_10 = V_3 ;
V_3 -> V_39 = V_39 ;
F_18 ( & V_51 , V_9 ) ;
F_19 ( & V_51 , V_9 ) ;
F_23 ( & V_51 , V_3 ) ;
F_24 ( V_51 ) ;
if ( V_3 -> V_59 >= 0 )
{
V_70 = F_27 ( V_39 ) ;
V_9 -> V_40 = V_70 ( V_3 -> V_59 ) ;
if ( V_9 -> V_40 == NULL )
{
F_1 ( L_33 ) ;
}
}
else
{
V_71 = F_28 ( V_39 ) ;
V_9 -> V_40 = V_71 ( & V_3 -> V_56 [ 0 ] , & V_3 -> V_56 [ 1 ] , V_3 -> V_61 [ 0 ] , V_3 -> V_61 [ 1 ] ) ;
if ( V_9 -> V_40 == NULL )
{
F_1 ( L_34 ) ;
}
}
V_69 = F_29 ( F_30 ( V_39 ) , V_9 , V_9 -> V_40 , 0 ,
NULL , F_31 ( V_39 ) , F_9 ) ;
if ( V_69 != NULL )
{
F_4 ( V_9 ) ;
F_32 ( V_69 , TRUE ) ;
F_1 ( L_35 ) ;
}
}
static T_10
F_33 ( const void * T_16 V_73 , void * V_74 , void * V_68 V_73 )
{
T_13 * V_39 = ( T_13 * ) V_74 ;
T_17 V_75 ;
V_75 . V_76 = V_77 ;
V_75 . V_78 = NULL ;
V_75 . V_79 = F_34 ( V_39 ) ;
V_75 . V_80 = F_25 ;
V_75 . V_81 = 0 ;
V_75 . V_82 = NULL ;
F_35 ( & V_75 , V_39 ) ;
F_5 ( ( char * ) V_75 . V_79 ) ;
return FALSE ;
}
void
F_36 ( void )
{
F_37 ( F_33 , NULL ) ;
}
