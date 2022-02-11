T_1 *
F_1 ( char * V_1 )
{
T_1 * V_2 ;
V_2 = ( T_1 * ) malloc ( sizeof( T_1 ) ) ;
if ( V_2 == NULL ) {
perror ( L_1 ) ;
exit ( V_3 ) ;
}
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_1 = F_2 ( V_1 ) ;
if ( V_2 -> V_1 == NULL )
F_3 ( L_2 , V_3 ) ;
V_2 -> type = V_4 ;
V_2 -> V_5 = 1 ;
return ( V_2 ) ;
}
void
F_4 ( T_1 * V_6 )
{
if ( V_7 != NULL ) {
T_2 V_8 ;
V_8 . V_9 = V_6 -> V_1 ;
V_8 . V_10 = strlen ( V_6 -> V_1 ) ;
V_7 -> V_11 ( V_7 , & V_8 , 0 ) ;
}
switch( V_6 -> type ) {
case V_12 :
case V_13 :
case REGISTER :
if ( V_6 -> V_14 . V_15 != NULL )
free ( V_6 -> V_14 . V_15 ) ;
break;
case V_16 :
if ( V_6 -> V_14 . V_17 != NULL )
free ( V_6 -> V_14 . V_17 ) ;
break;
case V_18 :
case V_19 :
case ENUM :
case V_20 :
if ( V_6 -> V_14 . V_21 != NULL ) {
F_5 ( & V_6 -> V_14 . V_21 -> V_22 ) ;
free ( V_6 -> V_14 . V_21 ) ;
}
break;
case V_23 :
case CONST :
if ( V_6 -> V_14 . V_24 != NULL )
free ( V_6 -> V_14 . V_24 ) ;
break;
case V_25 :
if ( V_6 -> V_14 . V_26 != NULL )
free ( V_6 -> V_14 . V_26 ) ;
break;
case V_4 :
default:
break;
}
free ( V_6 -> V_1 ) ;
free ( V_6 ) ;
}
void
F_6 ()
{
V_7 = F_7 ( NULL ,
V_27 | V_28 | V_29 , 0 , V_30 ,
NULL ) ;
if ( V_7 == NULL ) {
perror ( L_3 ) ;
exit ( V_3 ) ;
}
}
void
F_8 ()
{
if ( V_7 != NULL ) {
T_2 V_8 ;
T_2 V_9 ;
while ( V_7 -> V_31 ( V_7 , & V_8 , & V_9 , V_32 ) == 0 ) {
T_1 * V_33 ;
memcpy ( & V_33 , V_9 . V_9 , sizeof( V_33 ) ) ;
F_4 ( V_33 ) ;
}
V_7 -> V_34 ( V_7 ) ;
}
}
T_1 *
F_9 ( char * V_1 )
{
T_1 * V_33 ;
T_2 V_8 ;
T_2 V_9 ;
int V_35 ;
V_8 . V_9 = ( void * ) V_1 ;
V_8 . V_10 = strlen ( V_1 ) ;
if ( ( V_35 = V_7 -> V_36 ( V_7 , & V_8 , & V_9 , 0 ) ) != 0 ) {
if ( V_35 == - 1 ) {
perror ( L_4 ) ;
exit ( V_3 ) ;
} else if ( V_35 == 1 ) {
T_1 * V_2 ;
V_2 = F_1 ( V_1 ) ;
V_9 . V_9 = & V_2 ;
V_9 . V_10 = sizeof( V_2 ) ;
if ( V_7 -> V_37 ( V_7 , & V_8 , & V_9 ,
0 ) != 0 ) {
perror ( L_5 ) ;
exit ( V_3 ) ;
}
return ( V_2 ) ;
} else {
perror ( L_6 ) ;
exit ( V_3 ) ;
}
}
memcpy ( & V_33 , V_9 . V_9 , sizeof( V_33 ) ) ;
V_33 -> V_5 ++ ;
V_9 . V_9 = & V_33 ;
if ( V_7 -> V_37 ( V_7 , & V_8 , & V_9 , 0 ) != 0 ) {
perror ( L_5 ) ;
exit ( V_3 ) ;
}
return ( V_33 ) ;
}
T_3 *
F_10 ( T_4 * V_38 , char * V_39 )
{
T_3 * V_40 ;
V_40 = F_11 ( V_38 ) ;
while( V_40 != NULL ) {
if ( strcmp ( V_39 , V_40 -> V_6 -> V_1 ) == 0 )
break;
V_40 = F_12 ( V_40 , V_41 ) ;
}
return ( V_40 ) ;
}
void
F_13 ( T_4 * V_38 , T_1 * V_6 , int V_42 )
{
T_3 * V_43 ;
V_43 = ( T_3 * ) malloc ( sizeof( T_3 ) ) ;
if ( V_43 == NULL ) {
F_3 ( L_7 , V_3 ) ;
}
V_43 -> V_6 = V_6 ;
if ( V_42 == V_44 ) {
T_3 * V_40 ;
int V_45 ;
V_45 = FALSE ;
switch( V_6 -> type ) {
case REGISTER :
case V_12 :
case V_13 :
break;
case V_19 :
case V_18 :
case ENUM :
case V_20 :
V_45 = TRUE ;
break;
default:
F_3 ( L_8 ,
V_3 ) ;
}
V_40 = F_11 ( V_38 ) ;
if ( V_40 == NULL
|| ( V_45
&& ( V_40 -> V_6 -> type > V_43 -> V_6 -> type
|| ( V_40 -> V_6 -> type == V_43 -> V_6 -> type
&& ( V_40 -> V_6 -> V_14 . V_21 -> V_46 >
V_43 -> V_6 -> V_14 . V_21 -> V_46 ) ) ) )
|| ( ! V_45 && ( V_40 -> V_6 -> V_14 . V_15 -> V_47 >
V_43 -> V_6 -> V_14 . V_15 -> V_47 ) ) ) {
F_14 ( V_38 , V_43 , V_41 ) ;
return;
}
while ( 1 ) {
if ( F_12 ( V_40 , V_41 ) == NULL ) {
F_15 ( V_40 , V_43 ,
V_41 ) ;
break;
} else {
T_1 * V_48 ;
V_48 = F_12 ( V_40 , V_41 ) -> V_6 ;
if ( ( V_45
&& ( V_48 -> type > V_6 -> type
|| ( V_48 -> type == V_6 -> type
&& ( V_48 -> V_14 . V_21 -> V_46 >
V_6 -> V_14 . V_21 -> V_46 ) ) ) )
|| ( ! V_45
&& ( V_48 -> V_14 . V_15 -> V_47 >
V_6 -> V_14 . V_15 -> V_47 ) ) ) {
F_15 ( V_40 , V_43 ,
V_41 ) ;
break;
}
}
V_40 = F_12 ( V_40 , V_41 ) ;
}
} else {
F_14 ( V_38 , V_43 , V_41 ) ;
}
}
void
F_5 ( T_4 * V_38 )
{
T_3 * V_49 , * V_50 ;
V_49 = F_11 ( V_38 ) ;
while ( V_49 != NULL ) {
V_50 = F_12 ( V_49 , V_41 ) ;
free ( V_49 ) ;
V_49 = V_50 ;
}
F_16 ( V_38 ) ;
}
void
F_17 ( T_4 * V_51 , T_4 * V_52 ,
T_4 * V_53 )
{
T_3 * V_54 ;
* V_51 = * V_52 ;
while( ( V_54 = F_11 ( V_53 ) ) != NULL ) {
F_18 ( V_53 , V_41 ) ;
F_14 ( V_51 , V_54 , V_41 ) ;
}
F_16 ( V_52 ) ;
F_16 ( V_53 ) ;
}
void
F_19 ( T_5 * V_55 )
{
if ( V_55 == NULL )
return;
fprintf ( V_55 ,
L_9
L_10
L_11
L_12
L_13 ,
V_56 ) ;
}
void
F_20 ( T_5 * V_57 , char * V_58 )
{
if ( V_57 == NULL )
return;
fprintf ( V_57 , L_14 , V_58 ) ;
}
void
F_21 ( T_5 * V_55 )
{
if ( V_55 == NULL )
return;
fprintf ( V_55 ,
L_15
L_16
L_17
L_18
L_19
L_20
L_21 ,
V_59 , V_59 , V_59 ) ;
}
static void
F_22 ( T_5 * V_57 , T_3 * V_60 )
{
if ( V_57 == NULL )
return;
fprintf ( V_57 ,
L_22 ,
V_59 ,
V_60 -> V_6 -> V_1 ) ;
}
static void
F_23 ( T_5 * V_55 , T_5 * V_57 ,
T_3 * V_60 , T_6 V_61 )
{
char * V_62 ;
char * V_63 ;
V_62 = F_2 ( V_60 -> V_6 -> V_1 ) ;
if ( V_62 == NULL )
F_3 ( L_2 , V_3 ) ;
for ( V_63 = V_62 ; * V_63 != '\0' ; V_63 ++ )
* V_63 = tolower ( * V_63 ) ;
if ( V_57 != NULL ) {
if ( V_61 != 0 )
fprintf ( V_57 ,
L_21
L_23
L_21 ) ;
fprintf ( V_57 ,
L_24
L_25
L_26
L_27
L_28
L_29
L_21 ,
V_59 ,
V_62 ,
V_59 ,
V_61 != 0 ? V_60 -> V_6 -> V_1 : L_30 ,
V_61 != 0 ? L_31 : L_32 ,
V_61 ,
V_60 -> V_6 -> V_1 ,
V_60 -> V_6 -> V_14 . V_15 -> V_47 ) ;
}
fprintf ( V_55 ,
L_33
L_34
L_35
L_36
L_37
L_38
L_21 ,
V_59 ,
V_59 ,
V_62 ,
V_59 ,
V_62 ,
V_59 ,
V_60 -> V_6 -> V_1 ,
V_60 -> V_6 -> V_14 . V_15 -> V_47 ) ;
}
static void
F_24 ( T_5 * V_57 , T_3 * V_40 )
{
int V_64 ;
if ( V_57 == NULL )
return;
fprintf ( V_57 ,
L_39 ,
V_40 -> V_6 -> V_1 ) ;
V_64 = 3 - ( strlen ( V_40 -> V_6 -> V_1 ) + 5 ) / 8 ;
while ( V_64 -- > 0 )
fputc ( '\t' , V_57 ) ;
fprintf ( V_57 , L_40 ,
V_40 -> V_6 -> V_14 . V_21 -> V_46 ,
V_40 -> V_6 -> V_14 . V_21 -> V_65 ) ;
}
void
F_25 ( T_5 * V_55 , T_5 * V_57 )
{
T_4 V_66 ;
T_4 V_67 ;
T_4 V_68 ;
T_4 V_69 ;
T_4 V_70 ;
T_4 V_71 ;
T_3 * V_40 ;
T_3 * V_60 ;
T_2 V_8 ;
T_2 V_9 ;
int V_72 ;
int V_73 = 0 , V_74 = 0 ;
T_6 V_75 ;
if ( V_7 == NULL )
return;
F_16 ( & V_66 ) ;
F_16 ( & V_67 ) ;
F_16 ( & V_68 ) ;
F_16 ( & V_69 ) ;
F_16 ( & V_70 ) ;
F_16 ( & V_71 ) ;
V_72 = V_32 ;
while ( V_7 -> V_31 ( V_7 , & V_8 , & V_9 , V_72 ) == 0 ) {
T_1 * V_76 ;
memcpy ( & V_76 , V_9 . V_9 , sizeof( V_76 ) ) ;
switch( V_76 -> type ) {
case REGISTER :
case V_12 :
case V_13 :
F_13 ( & V_66 , V_76 , V_44 ) ;
break;
case V_18 :
case V_19 :
case ENUM :
case V_20 :
F_13 ( & V_67 , V_76 , V_44 ) ;
break;
case CONST :
F_13 ( & V_68 , V_76 ,
V_77 ) ;
break;
case V_23 :
F_13 ( & V_69 , V_76 ,
V_77 ) ;
break;
case V_16 :
F_13 ( & V_70 , V_76 ,
V_77 ) ;
break;
case V_25 :
if ( V_76 -> V_14 . V_26 -> V_78 == 0 )
break;
F_13 ( & V_71 , V_76 ,
V_77 ) ;
break;
default:
break;
}
V_72 = V_79 ;
}
F_19 ( V_55 ) ;
F_21 ( V_55 ) ;
F_19 ( V_57 ) ;
F_20 ( V_57 , V_80 ) ;
F_26 (curnode, &registers, links) {
if ( V_40 -> V_6 -> V_81 )
continue;
switch( V_40 -> V_6 -> type ) {
case REGISTER :
case V_12 :
case V_13 :
{
T_4 * V_82 ;
T_3 * V_83 ;
int V_61 ;
V_61 = 0 ;
V_73 ++ ;
if ( V_40 -> V_6 -> V_5 == 1 )
break;
V_82 = & V_40 -> V_6 -> V_14 . V_15 -> V_82 ;
F_26 (fieldnode, fields, links) {
if ( V_61 == 0 )
F_22 ( V_57 ,
V_40 ) ;
else if ( V_57 != NULL )
fputs ( L_41 , V_57 ) ;
V_61 ++ ;
F_24 ( V_57 , V_83 ) ;
}
F_23 ( V_55 , V_57 ,
V_40 , V_61 ) ;
V_74 ++ ;
}
default:
break;
}
}
fprintf ( V_84 , L_42 , V_85 ,
V_74 , V_73 ) ;
while ( F_11 ( & V_67 ) != NULL ) {
char * V_86 ;
V_40 = F_11 ( & V_67 ) ;
F_18 ( & V_67 , V_41 ) ;
V_60 = F_11 ( & V_40 -> V_6 -> V_14 . V_21 -> V_22 ) ;
V_86 = V_60 -> V_6 -> V_1 ;
V_60 = F_10 ( & V_66 , V_86 ) ;
F_15 ( V_60 , V_40 , V_41 ) ;
}
while ( F_11 ( & V_70 ) != NULL ) {
char * V_86 ;
V_40 = F_11 ( & V_70 ) ;
F_18 ( & V_70 , V_41 ) ;
V_86 = V_40 -> V_6 -> V_14 . V_17 -> V_87 -> V_1 ;
V_60 = F_10 ( & V_66 , V_86 ) ;
F_15 ( V_60 , V_40 , V_41 ) ;
}
while ( F_11 ( & V_66 ) != NULL ) {
T_3 * V_40 ;
T_6 V_46 ;
char * V_88 ;
char * V_89 ;
V_40 = F_11 ( & V_66 ) ;
F_18 ( & V_66 , V_41 ) ;
switch( V_40 -> V_6 -> type ) {
case REGISTER :
case V_12 :
case V_13 :
fprintf ( V_55 , L_21 ) ;
V_46 = V_40 -> V_6 -> V_14 . V_15 -> V_47 ;
V_88 = L_43 ;
V_89 = L_44 ;
break;
case V_16 :
{
T_1 * V_87 ;
V_87 = V_40 -> V_6 -> V_14 . V_17 -> V_87 ;
V_46 = V_87 -> V_14 . V_15 -> V_47 ;
V_88 = L_43 ;
V_89 = L_44 ;
break;
}
case V_18 :
case V_19 :
case ENUM :
case V_20 :
V_46 = V_40 -> V_6 -> V_14 . V_21 -> V_46 ;
V_88 = L_44 ;
V_89 = L_43 ;
break;
default:
V_46 = 0 ;
V_88 = NULL ;
V_89 = NULL ;
F_3 ( L_45
L_46 , V_3 ) ;
break;
}
fprintf ( V_55 , L_47 ,
V_88 , V_40 -> V_6 -> V_1 , V_89 ,
V_46 ) ;
free ( V_40 ) ;
}
fprintf ( V_55 , L_48 ) ;
while ( F_11 ( & V_68 ) != NULL ) {
T_3 * V_40 ;
V_40 = F_11 ( & V_68 ) ;
F_18 ( & V_68 , V_41 ) ;
fprintf ( V_55 , L_49 ,
V_40 -> V_6 -> V_1 ,
V_40 -> V_6 -> V_14 . V_24 -> V_46 ) ;
free ( V_40 ) ;
}
fprintf ( V_55 , L_50 ) ;
for ( V_75 = 0 ; F_11 ( & V_69 ) != NULL ; V_75 ++ ) {
T_3 * V_40 ;
V_40 = F_11 ( & V_69 ) ;
F_18 ( & V_69 , V_41 ) ;
fprintf ( V_55 , L_49 ,
V_40 -> V_6 -> V_1 ,
V_40 -> V_6 -> V_14 . V_24 -> V_46 ) ;
free ( V_40 ) ;
}
fprintf ( V_55 , L_51 , V_75 ) ;
fprintf ( V_55 , L_52 ) ;
while ( F_11 ( & V_71 ) != NULL ) {
T_3 * V_40 ;
V_40 = F_11 ( & V_71 ) ;
F_18 ( & V_71 , V_41 ) ;
fprintf ( V_55 , L_53 ,
V_40 -> V_6 -> V_1 ,
V_40 -> V_6 -> V_14 . V_26 -> V_47 ) ;
free ( V_40 ) ;
}
}
