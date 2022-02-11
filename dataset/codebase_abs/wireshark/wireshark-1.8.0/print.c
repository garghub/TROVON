static T_1 *
F_1 ( int V_1 , const char * V_2 )
{
T_1 * V_3 ;
if ( V_1 )
V_3 = F_2 ( V_2 , L_1 ) ;
else
V_3 = F_3 ( V_2 , L_1 ) ;
return V_3 ;
}
static T_2
F_4 ( int V_1 , T_1 * V_3 )
{
if ( V_1 )
return ( fclose ( V_3 ) == 0 ) ;
else
return ( F_5 ( V_3 ) == 0 ) ;
}
T_2
F_6 ( T_3 * V_4 , T_4 * V_5 ,
T_5 * V_6 )
{
T_6 V_7 ;
V_7 . V_8 = 0 ;
V_7 . V_6 = V_6 ;
V_7 . V_9 = TRUE ;
V_7 . V_10 = V_5 -> V_11 . V_12 ;
V_7 . V_13 = V_5 -> V_11 . V_14 -> V_15 . V_13 ;
V_7 . V_16 = V_4 -> V_16 ;
V_7 . V_17 = ! V_4 -> V_18 ;
V_7 . V_5 = V_5 ;
F_7 ( V_5 -> V_19 , V_20 , & V_7 ) ;
return V_7 . V_9 ;
}
static
void V_20 ( T_7 * V_21 , T_8 V_7 )
{
T_9 * V_22 = F_8 ( V_21 ) ;
T_6 * V_23 = ( T_6 * ) V_7 ;
const T_10 * V_24 ;
T_11 V_25 [ V_26 ] ;
T_11 * V_27 ;
F_9 ( V_22 && L_2 ) ;
if ( F_10 ( V_21 ) )
return;
if ( ! V_23 -> V_9 )
return;
if ( V_22 -> V_28 ) {
V_27 = V_22 -> V_28 -> V_29 ;
}
else {
V_27 = V_25 ;
F_11 ( V_22 , V_25 ) ;
}
if ( F_12 ( V_21 ) ) {
V_27 = F_13 ( L_3 , V_27 ) ;
}
if ( ! F_14 ( V_23 -> V_6 , V_23 -> V_8 , V_27 ) ) {
V_23 -> V_9 = FALSE ;
return;
}
if ( V_30 != NULL && V_23 -> V_8 == 0
&& F_15 ( V_30 , V_22 -> V_31 -> V_32 ) == NULL ) {
V_23 -> V_9 = TRUE ;
return;
}
if ( F_12 ( V_21 ) ) {
F_16 ( V_27 ) ;
}
if ( V_22 -> V_31 -> V_33 == V_34 && V_23 -> V_17 ) {
V_24 = F_17 ( V_23 -> V_10 , V_22 ) ;
if ( V_24 ) {
if ( ! F_18 ( V_23 -> V_6 , V_24 ,
V_22 -> V_35 , V_23 -> V_13 ) ) {
V_23 -> V_9 = FALSE ;
return;
}
}
}
F_9 ( V_22 -> V_36 >= - 1 && V_22 -> V_36 < V_37 ) ;
if ( V_23 -> V_16 == V_38 ||
( V_23 -> V_16 == V_39 &&
V_22 -> V_36 >= 0 && V_40 [ V_22 -> V_36 ] ) ) {
if ( V_21 -> V_41 != NULL ) {
V_23 -> V_8 ++ ;
F_7 ( V_21 ,
V_20 , V_23 ) ;
V_23 -> V_8 -- ;
if ( ! V_23 -> V_9 )
return;
}
}
}
void
F_19 ( T_1 * V_3 , const T_11 * V_42 )
{
T_12 V_43 = time ( NULL ) ;
char * V_44 = asctime ( localtime ( & V_43 ) ) ;
V_44 [ strlen ( V_44 ) - 1 ] = 0 ;
fputs ( L_4 , V_3 ) ;
fputs ( L_5 V_45 L_6 , V_3 ) ;
fprintf ( V_3 , L_7 V_45 L_8 V_45 L_9 , F_20 () ) ;
fputs ( L_10 V_46 L_11 , V_3 ) ;
fprintf ( V_3 , L_12 , V_47 , V_48 , V_44 , V_42 ? V_42 : L_13 ) ;
}
void
F_21 ( T_4 * V_5 , T_1 * V_3 )
{
T_13 V_7 ;
V_7 . V_8 = 0 ;
V_7 . V_3 = V_3 ;
V_7 . V_10 = V_5 -> V_11 . V_12 ;
V_7 . V_5 = V_5 ;
fprintf ( V_3 , L_14 ) ;
F_22 ( V_5 -> V_19 , V_3 ) ;
F_7 ( V_5 -> V_19 , V_49 ,
& V_7 ) ;
fprintf ( V_3 , L_15 ) ;
}
static void
V_49 ( T_7 * V_21 , T_8 V_7 )
{
T_9 * V_22 = F_8 ( V_21 ) ;
T_13 * V_23 = ( T_13 * ) V_7 ;
const T_11 * V_27 ;
T_11 V_25 [ V_26 ] ;
char * V_50 ;
T_14 V_51 ;
int V_52 ;
T_2 V_53 ;
F_9 ( V_22 && L_2 ) ;
V_53 =
( ( ( V_22 -> V_31 -> type != V_54 ) ||
( V_22 -> V_31 -> V_33 == V_34 ) ) &&
( V_23 -> V_8 == 0 ) ) ;
for ( V_52 = - 1 ; V_52 < V_23 -> V_8 ; V_52 ++ ) {
fputs ( L_16 , V_23 -> V_3 ) ;
}
if ( V_53 ) {
fputs ( L_17 , V_23 -> V_3 ) ;
V_23 -> V_8 ++ ;
for ( V_52 = - 1 ; V_52 < V_23 -> V_8 ; V_52 ++ ) {
fputs ( L_16 , V_23 -> V_3 ) ;
}
}
if ( V_22 -> V_31 -> V_33 == V_55 ) {
if ( V_22 -> V_28 ) {
V_27 = V_22 -> V_28 -> V_29 ;
}
else {
V_27 = L_13 ;
}
fputs ( L_18 , V_23 -> V_3 ) ;
fputs ( L_19 , V_23 -> V_3 ) ;
F_23 ( V_23 -> V_3 , V_27 ) ;
fprintf ( V_23 -> V_3 , L_20 , V_22 -> V_35 ) ;
if ( V_21 -> V_56 && V_21 -> V_56 -> V_57 && ( V_22 -> V_58 < V_21 -> V_56 -> V_57 -> V_58 ) ) {
fprintf ( V_23 -> V_3 , L_21 , V_21 -> V_56 -> V_57 -> V_58 + V_22 -> V_58 ) ;
} else {
fprintf ( V_23 -> V_3 , L_21 , V_22 -> V_58 ) ;
}
fputs ( L_22 , V_23 -> V_3 ) ;
F_24 ( V_23 , V_22 ) ;
if ( V_21 -> V_41 != NULL ) {
fputs ( L_23 , V_23 -> V_3 ) ;
}
else {
fputs ( L_24 , V_23 -> V_3 ) ;
}
}
else if ( V_22 -> V_31 -> V_33 == V_34 ) {
fputs ( L_25 , V_23 -> V_3 ) ;
F_24 ( V_23 , V_22 ) ;
fputs ( L_23 , V_23 -> V_3 ) ;
}
else {
if ( V_22 -> V_31 -> type == V_54 && V_22 -> V_31 -> V_33 != V_59 ) {
fputs ( L_26 , V_23 -> V_3 ) ;
}
else {
fputs ( L_18 , V_23 -> V_3 ) ;
}
F_23 ( V_23 -> V_3 , V_22 -> V_31 -> V_32 ) ;
#if 0
fputs("\" showname=\"", pdata->fh);
print_escaped_xml(pdata->fh, fi->hfinfo->name);
#endif
if ( V_22 -> V_28 ) {
fputs ( L_27 , V_23 -> V_3 ) ;
F_23 ( V_23 -> V_3 , V_22 -> V_28 -> V_29 ) ;
}
else {
V_27 = V_25 ;
F_11 ( V_22 , V_25 ) ;
fputs ( L_27 , V_23 -> V_3 ) ;
F_23 ( V_23 -> V_3 , V_27 ) ;
}
if ( F_10 ( V_21 ) )
fprintf ( V_23 -> V_3 , L_28 ) ;
fprintf ( V_23 -> V_3 , L_20 , V_22 -> V_35 ) ;
if ( V_21 -> V_56 && V_21 -> V_56 -> V_57 && ( V_22 -> V_58 < V_21 -> V_56 -> V_57 -> V_58 ) ) {
fprintf ( V_23 -> V_3 , L_21 , V_21 -> V_56 -> V_57 -> V_58 + V_22 -> V_58 ) ;
} else {
fprintf ( V_23 -> V_3 , L_21 , V_22 -> V_58 ) ;
}
switch ( V_22 -> V_31 -> type )
{
case V_54 :
break;
case V_60 :
fputs ( L_29 , V_23 -> V_3 ) ;
break;
default:
V_50 = F_25 ( V_22 ,
V_23 -> V_5 ) ;
if ( V_50 != NULL ) {
V_51 = strlen ( V_22 -> V_31 -> V_32 ) + 4 ;
if ( V_50 [ strlen ( V_50 ) - 1 ] == '"' ) {
V_50 [ strlen ( V_50 ) - 1 ] = '\0' ;
V_51 ++ ;
}
fputs ( L_19 , V_23 -> V_3 ) ;
F_23 ( V_23 -> V_3 , & V_50 [ V_51 ] ) ;
}
if ( V_22 -> V_35 > 0 ) {
fputs ( L_22 , V_23 -> V_3 ) ;
if ( V_22 -> V_31 -> V_61 != 0 ) {
fprintf ( V_23 -> V_3 , L_30 , F_26 ( & V_22 -> V_62 ) ) ;
fputs ( L_31 , V_23 -> V_3 ) ;
F_24 ( V_23 , V_22 ) ;
}
else {
F_24 ( V_23 , V_22 ) ;
}
}
}
if ( V_21 -> V_41 != NULL ) {
fputs ( L_23 , V_23 -> V_3 ) ;
}
else if ( V_22 -> V_31 -> V_33 == V_34 ) {
fputs ( L_23 , V_23 -> V_3 ) ;
}
else {
fputs ( L_24 , V_23 -> V_3 ) ;
}
}
if ( V_21 -> V_41 != NULL ) {
V_23 -> V_8 ++ ;
F_7 ( V_21 ,
V_49 , V_23 ) ;
V_23 -> V_8 -- ;
}
if ( V_53 ) {
V_23 -> V_8 -- ;
}
if ( V_21 -> V_41 != NULL ) {
for ( V_52 = - 1 ; V_52 < V_23 -> V_8 ; V_52 ++ ) {
fputs ( L_16 , V_23 -> V_3 ) ;
}
if ( V_22 -> V_31 -> V_33 != V_34 && V_22 -> V_31 -> V_33 != V_59 ) {
if ( V_22 -> V_31 -> type == V_54 ) {
fputs ( L_32 , V_23 -> V_3 ) ;
}
else {
fputs ( L_33 , V_23 -> V_3 ) ;
}
} else {
fputs ( L_33 , V_23 -> V_3 ) ;
}
}
if ( V_53 ) {
fputs ( L_32 , V_23 -> V_3 ) ;
}
}
static void
F_22 ( T_15 * V_19 , T_1 * V_3 )
{
T_16 V_63 , V_64 , V_65 ;
T_17 * V_66 ;
T_18 * V_67 ;
T_9 * V_68 ;
V_67 = F_27 ( V_19 , V_69 ) ;
if ( F_28 ( V_67 ) < 1 ) {
return;
}
V_68 = ( T_9 * ) V_67 -> V_23 [ 0 ] ;
F_29 ( V_67 , TRUE ) ;
V_67 = F_27 ( V_19 , V_70 ) ;
if ( F_28 ( V_67 ) < 1 ) {
return;
}
V_63 = F_26 ( & ( ( T_9 * ) V_67 -> V_23 [ 0 ] ) -> V_62 ) ;
F_29 ( V_67 , TRUE ) ;
V_67 = F_27 ( V_19 , V_71 ) ;
if ( F_28 ( V_67 ) < 1 ) {
return;
}
V_64 = F_26 ( & ( ( T_9 * ) V_67 -> V_23 [ 0 ] ) -> V_62 ) ;
F_29 ( V_67 , TRUE ) ;
V_67 = F_27 ( V_19 , V_72 ) ;
if ( F_28 ( V_67 ) < 1 ) {
return;
}
V_65 = F_26 ( & ( ( T_9 * ) V_67 -> V_23 [ 0 ] ) -> V_62 ) ;
F_29 ( V_67 , TRUE ) ;
V_67 = F_27 ( V_19 , V_73 ) ;
if ( F_28 ( V_67 ) < 1 ) {
return;
}
V_66 = ( T_17 * ) F_30 ( & ( ( T_9 * ) V_67 -> V_23 [ 0 ] ) -> V_62 ) ;
F_29 ( V_67 , TRUE ) ;
fprintf ( V_3 ,
L_34 ,
V_68 -> V_35 ) ;
fprintf ( V_3 ,
L_35 ,
V_63 , V_63 , V_68 -> V_35 ) ;
fprintf ( V_3 ,
L_36 ,
V_64 , V_64 , V_68 -> V_35 ) ;
fprintf ( V_3 ,
L_37 ,
V_65 , V_65 , V_68 -> V_35 ) ;
fprintf ( V_3 ,
L_38 ,
F_31 ( V_66 , V_74 , TRUE ) , ( int ) V_66 -> V_75 , V_66 -> V_76 , V_68 -> V_35 ) ;
fprintf ( V_3 ,
L_39 ) ;
}
void
F_32 ( T_1 * V_3 )
{
fputs ( L_40 , V_3 ) ;
}
void
F_33 ( T_1 * V_3 )
{
fputs ( L_4 , V_3 ) ;
fputs ( L_41 V_77 L_11 , V_3 ) ;
fprintf ( V_3 , L_42 , V_47 , V_48 ) ;
V_78 = TRUE ;
}
void
F_34 ( T_4 * V_5 , T_1 * V_3 )
{
T_19 V_52 ;
if( V_78 ) {
fprintf ( V_3 , L_43 ) ;
for( V_52 = 0 ; V_52 < V_5 -> V_11 . V_79 -> V_80 ; V_52 ++ ) {
fprintf ( V_3 , L_44 ) ;
F_23 ( V_3 , V_5 -> V_11 . V_79 -> V_81 [ V_52 ] ) ;
fprintf ( V_3 , L_45 ) ;
}
fprintf ( V_3 , L_46 ) ;
V_78 = FALSE ;
}
fprintf ( V_3 , L_14 ) ;
for( V_52 = 0 ; V_52 < V_5 -> V_11 . V_79 -> V_80 ; V_52 ++ ) {
fprintf ( V_3 , L_44 ) ;
F_23 ( V_3 , V_5 -> V_11 . V_79 -> V_82 [ V_52 ] ) ;
fprintf ( V_3 , L_45 ) ;
}
fprintf ( V_3 , L_15 ) ;
}
void
F_35 ( T_1 * V_3 )
{
fputs ( L_47 , V_3 ) ;
}
void
F_36 ( T_1 * V_3 V_83 )
{
V_78 = TRUE ;
}
static T_11 * F_37 ( const T_11 * V_84 , const T_11 * V_85 )
{
T_11 * V_86 ;
T_11 * V_87 ;
V_86 = F_38 ( V_84 , V_85 ) ;
V_87 = V_86 ;
while ( ( V_87 = strstr ( V_87 , L_48 ) ) != NULL )
* V_87 = '\"' ;
return V_86 ;
}
static void F_39 ( const char * V_88 , char V_89 , T_1 * V_3 )
{
T_11 * V_86 ;
V_86 = F_37 ( V_88 , NULL ) ;
fprintf ( V_3 , L_49 , V_86 , V_89 ) ;
F_16 ( V_86 ) ;
}
void
F_40 ( T_4 * V_5 , T_1 * V_3 )
{
T_19 V_52 ;
if( V_78 ) {
for( V_52 = 0 ; V_52 < V_5 -> V_11 . V_79 -> V_80 - 1 ; V_52 ++ )
F_39 ( V_5 -> V_11 . V_79 -> V_81 [ V_52 ] , ',' , V_3 ) ;
F_39 ( V_5 -> V_11 . V_79 -> V_81 [ V_52 ] , '\n' , V_3 ) ;
V_78 = FALSE ;
}
for( V_52 = 0 ; V_52 < V_5 -> V_11 . V_79 -> V_80 - 1 ; V_52 ++ )
F_39 ( V_5 -> V_11 . V_79 -> V_82 [ V_52 ] , ',' , V_3 ) ;
F_39 ( V_5 -> V_11 . V_79 -> V_82 [ V_52 ] , '\n' , V_3 ) ;
}
void
F_41 ( T_1 * V_3 V_83 )
{
}
void
F_42 ( T_1 * V_3 V_83 )
{
}
void
F_43 ( T_16 V_63 , T_1 * V_3 , T_4 * V_5 )
{
T_16 V_52 = 0 , V_90 = 0 ;
T_20 * V_91 ;
T_21 * V_92 ;
T_22 * V_93 ;
const char * V_94 ;
const T_23 * V_95 ;
T_24 V_35 ;
char V_96 [ 9 ] ;
for ( V_91 = V_5 -> V_11 . V_12 ; V_91 != NULL ; V_91 = V_91 -> V_97 ) {
memset ( V_96 , 0 , sizeof( V_96 ) ) ;
V_92 = ( T_21 * ) V_91 -> V_7 ;
V_93 = V_92 -> V_93 ;
V_35 = F_44 ( V_93 ) ;
if ( V_35 == 0 )
continue;
V_95 = F_45 ( V_93 , 0 , V_35 ) ;
V_94 = F_46 ( V_92 ) ;
if ( V_94 )
fprintf ( V_3 , L_50 , V_94 ) ;
if ( V_90 ) {
fprintf ( V_3 , L_51 ,
V_63 , V_90 , V_35 ) ;
} else {
fprintf ( V_3 , L_52 ,
V_63 , V_35 ) ;
}
V_90 ++ ;
for ( V_52 = 0 ; V_52 < V_35 ; V_52 ++ ) {
fprintf ( V_3 , L_53 , * ( V_95 + V_52 ) ) ;
V_96 [ V_52 % 8 ] = isprint ( * ( V_95 + V_52 ) ) ? * ( V_95 + V_52 ) : '.' ;
if ( V_52 == ( V_35 - 1 ) ) {
T_24 V_98 ;
V_98 = V_35 % 8 ;
if ( V_98 ) {
T_24 V_99 ;
for ( V_99 = 0 ; V_99 < 8 - V_98 ; V_99 ++ )
fprintf ( V_3 , L_54 ) ;
}
fprintf ( V_3 , L_55 , V_96 ) ;
break;
}
if ( ! ( ( V_52 + 1 ) % 8 ) ) {
fprintf ( V_3 , L_56 , V_96 ) ;
memset ( V_96 , 0 , sizeof( V_96 ) ) ;
}
else {
fprintf ( V_3 , L_57 ) ;
}
}
}
}
void
F_47 ( T_1 * V_3 V_83 )
{
}
static const T_10 *
F_17 ( T_20 * V_10 , T_9 * V_22 )
{
T_20 * V_91 ;
T_21 * V_92 ;
T_22 * V_100 ;
T_19 V_35 , V_101 ;
for ( V_91 = V_10 ; V_91 != NULL ; V_91 = V_91 -> V_97 ) {
V_92 = ( T_21 * ) V_91 -> V_7 ;
V_100 = V_92 -> V_93 ;
if ( V_22 -> V_102 == V_100 ) {
V_101 = F_48 ( V_100 ,
V_22 -> V_58 ) ;
if ( V_101 < 0 ) {
return NULL ;
}
V_35 = V_22 -> V_35 ;
if ( V_35 > V_101 )
V_35 = V_101 ;
return F_45 ( V_100 , V_22 -> V_58 , V_35 ) ;
}
}
F_49 () ;
return NULL ;
}
static void
F_23 ( T_1 * V_3 , const char * V_103 )
{
const char * V_104 ;
char V_105 [ 8 ] ;
for ( V_104 = V_103 ; * V_104 != '\0' ; V_104 ++ ) {
switch ( * V_104 ) {
case '&' :
fputs ( L_58 , V_3 ) ;
break;
case '<' :
fputs ( L_59 , V_3 ) ;
break;
case '>' :
fputs ( L_60 , V_3 ) ;
break;
case '"' :
fputs ( L_61 , V_3 ) ;
break;
case '\'' :
fputs ( L_62 , V_3 ) ;
break;
default:
if ( F_50 ( * V_104 ) )
fputc ( * V_104 , V_3 ) ;
else {
F_51 ( V_105 , sizeof( V_105 ) , L_63 , ( T_10 ) * V_104 ) ;
fputs ( V_105 , V_3 ) ;
}
}
}
}
static void
F_24 ( T_13 * V_23 , T_9 * V_22 )
{
int V_52 ;
const T_10 * V_24 ;
if ( ! V_22 -> V_102 )
return;
if ( V_22 -> V_35 > F_48 ( V_22 -> V_102 , V_22 -> V_58 ) ) {
fprintf ( V_23 -> V_3 , L_64 ) ;
return;
}
V_24 = F_17 ( V_23 -> V_10 , V_22 ) ;
if ( V_24 ) {
for ( V_52 = 0 ; V_52 < V_22 -> V_35 ; V_52 ++ ) {
fprintf ( V_23 -> V_3 , L_65 , V_24 [ V_52 ] ) ;
}
}
}
T_2
F_52 ( T_5 * V_6 , T_4 * V_5 )
{
T_2 V_106 ;
T_20 * V_91 ;
T_21 * V_92 ;
T_22 * V_93 ;
const char * V_94 ;
char * line ;
const T_23 * V_95 ;
T_24 V_35 ;
V_106 = ( V_5 -> V_11 . V_12 -> V_97 != NULL ) ;
for ( V_91 = V_5 -> V_11 . V_12 ; V_91 != NULL ;
V_91 = V_91 -> V_97 ) {
V_92 = ( T_21 * ) V_91 -> V_7 ;
V_93 = V_92 -> V_93 ;
if ( V_106 ) {
V_94 = F_46 ( V_92 ) ;
F_14 ( V_6 , 0 , L_13 ) ;
line = F_13 ( L_66 , V_94 ) ;
F_14 ( V_6 , 0 , line ) ;
F_16 ( line ) ;
}
V_35 = F_44 ( V_93 ) ;
if ( V_35 == 0 )
return TRUE ;
V_95 = F_45 ( V_93 , 0 , V_35 ) ;
if ( ! F_18 ( V_6 , V_95 , V_35 ,
V_5 -> V_11 . V_14 -> V_15 . V_13 ) )
return FALSE ;
}
return TRUE ;
}
static T_2
F_18 ( T_5 * V_6 , const T_23 * V_95 ,
T_24 V_35 , T_25 V_13 )
{
register unsigned int V_107 , V_52 , V_99 , V_108 , V_109 ;
T_23 V_110 ;
T_23 line [ V_111 + 1 ] ;
unsigned int V_112 ;
static T_23 V_113 [ 16 ] = {
'0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' ,
'8' , '9' , 'a' , 'b' , 'c' , 'd' , 'e' , 'f' } ;
if ( ! F_14 ( V_6 , 0 , L_13 ) )
return FALSE ;
if ( ( ( V_35 - 1 ) & 0xF0000000 ) != 0 )
V_112 = 8 ;
else if ( ( ( V_35 - 1 ) & 0x0F000000 ) != 0 )
V_112 = 7 ;
else if ( ( ( V_35 - 1 ) & 0x00F00000 ) != 0 )
V_112 = 6 ;
else if ( ( ( V_35 - 1 ) & 0x000F0000 ) != 0 )
V_112 = 5 ;
else
V_112 = 4 ;
V_107 = 0 ;
V_52 = 0 ;
V_99 = 0 ;
V_108 = 0 ;
while ( V_52 < V_35 ) {
if ( ( V_52 & 15 ) == 0 ) {
V_99 = 0 ;
V_109 = V_112 ;
do {
V_109 -- ;
V_110 = ( V_107 >> ( V_109 * 4 ) ) & 0xF ;
line [ V_99 ++ ] = V_113 [ V_110 ] ;
} while ( V_109 != 0 );
line [ V_99 ++ ] = ' ' ;
line [ V_99 ++ ] = ' ' ;
memset ( line + V_99 , ' ' , V_114 ) ;
V_108 = V_99 + V_115 + 2 ;
}
V_110 = * V_95 ++ ;
line [ V_99 ++ ] = V_113 [ V_110 >> 4 ] ;
line [ V_99 ++ ] = V_113 [ V_110 & 0xf ] ;
V_99 ++ ;
if ( V_13 == V_116 ) {
V_110 = F_53 ( V_110 ) ;
}
line [ V_108 ++ ] = V_110 >= ' ' && V_110 < 0x7f ? V_110 : '.' ;
V_52 ++ ;
if ( ( V_52 & 15 ) == 0 || V_52 == V_35 ) {
line [ V_108 ] = '\0' ;
if ( ! F_14 ( V_6 , 0 , line ) )
return FALSE ;
V_107 += 16 ;
}
}
return TRUE ;
}
static
void F_54 ( unsigned char * V_117 , const unsigned char * V_118 ,
int V_119 )
{
int V_120 , V_121 ;
char V_110 ;
if ( V_118 == NULL ) {
V_117 [ 0 ] = '\0' ;
return;
}
for ( V_120 = 0 , V_121 = 0 ; V_121 < V_119 ; V_120 ++ , V_121 ++ ) {
V_110 = V_118 [ V_120 ] ;
switch ( V_110 ) {
case '(' :
case ')' :
case '\\' :
V_117 [ V_121 ] = '\\' ;
V_117 [ ++ V_121 ] = V_110 ;
break;
default:
V_117 [ V_121 ] = V_110 ;
break;
}
if ( V_110 == 0 ) {
break;
}
}
}
T_2
F_55 ( T_5 * V_122 , T_11 * V_42 )
{
return ( V_122 -> V_123 -> F_55 ) ( V_122 , V_42 ) ;
}
T_2
F_14 ( T_5 * V_122 , int V_124 , const char * line )
{
return ( V_122 -> V_123 -> F_14 ) ( V_122 , V_124 , line ) ;
}
T_2
F_56 ( T_5 * V_122 , const T_11 * V_94 , const T_11 * V_125 )
{
return ( V_122 -> V_123 -> F_56 ) ( V_122 , V_94 , V_125 ) ;
}
T_2
F_57 ( T_5 * V_122 )
{
return ( V_122 -> V_123 -> F_57 ) ( V_122 ) ;
}
T_2
F_58 ( T_5 * V_122 )
{
return ( V_122 -> V_123 -> F_58 ) ( V_122 ) ;
}
T_2
F_59 ( T_5 * V_122 )
{
return ( V_122 -> V_123 -> V_126 ) ( V_122 ) ;
}
static T_2
F_60 ( T_5 * V_122 V_83 , T_11 * V_42 V_83 )
{
return TRUE ;
}
static T_2
F_61 ( T_5 * V_122 , int V_124 , const char * line )
{
T_26 * V_127 = ( T_26 * ) V_122 -> V_7 ;
char V_128 [ V_129 + 1 ] ;
int V_52 ;
int V_130 ;
V_130 = V_124 * 4 ;
if ( V_130 > V_129 ) {
V_130 = V_129 ;
}
for ( V_52 = 0 ; V_52 < V_130 ; V_52 ++ ) {
V_128 [ V_52 ] = ' ' ;
}
V_128 [ V_130 ] = '\0' ;
fputs ( V_128 , V_127 -> V_3 ) ;
fputs ( line , V_127 -> V_3 ) ;
putc ( '\n' , V_127 -> V_3 ) ;
return ! ferror ( V_127 -> V_3 ) ;
}
static T_2
F_62 ( T_5 * V_122 V_83 , const T_11 * V_94 V_83 ,
const T_11 * V_125 V_83 )
{
return TRUE ;
}
static T_2
F_63 ( T_5 * V_122 )
{
T_26 * V_127 = ( T_26 * ) V_122 -> V_7 ;
fputs ( L_67 , V_127 -> V_3 ) ;
return ! ferror ( V_127 -> V_3 ) ;
}
static T_2
F_64 ( T_5 * V_122 V_83 )
{
return TRUE ;
}
static T_2
F_65 ( T_5 * V_122 )
{
T_26 * V_127 = ( T_26 * ) V_122 -> V_7 ;
T_2 V_131 ;
V_131 = F_4 ( V_127 -> V_1 , V_127 -> V_3 ) ;
F_16 ( V_127 ) ;
F_16 ( V_122 ) ;
return V_131 ;
}
static T_5 *
F_66 ( int V_1 , T_1 * V_3 )
{
T_5 * V_6 ;
T_26 * V_127 ;
V_127 = ( T_26 * ) F_67 ( sizeof *V_127 ) ;
V_127 -> V_1 = V_1 ;
V_127 -> V_3 = V_3 ;
V_6 = ( T_5 * ) F_67 ( sizeof ( T_5 ) ) ;
V_6 -> V_123 = & V_132 ;
V_6 -> V_7 = V_127 ;
return V_6 ;
}
T_5 *
F_68 ( int V_1 , const char * V_2 )
{
T_1 * V_3 ;
V_3 = F_1 ( V_1 , V_2 ) ;
if ( V_3 == NULL )
return NULL ;
return F_66 ( V_1 , V_3 ) ;
}
T_5 *
F_69 ( T_1 * V_3 )
{
return F_66 ( TRUE , V_3 ) ;
}
static T_2
F_70 ( T_5 * V_122 , T_11 * V_42 )
{
T_27 * V_127 = ( T_27 * ) V_122 -> V_7 ;
unsigned char V_133 [ V_134 ] ;
F_71 ( V_127 -> V_3 ) ;
fputs ( L_68 , V_127 -> V_3 ) ;
F_54 ( V_133 , V_42 , V_134 ) ;
fprintf ( V_127 -> V_3 , L_69 V_48 L_70 , V_133 , V_135 ) ;
fputs ( L_71 , V_127 -> V_3 ) ;
return ! ferror ( V_127 -> V_3 ) ;
}
static T_2
F_72 ( T_5 * V_122 , int V_124 , const char * line )
{
T_27 * V_127 = ( T_27 * ) V_122 -> V_7 ;
unsigned char V_133 [ V_134 ] ;
F_54 ( V_133 , line , V_134 ) ;
fprintf ( V_127 -> V_3 , L_72 , V_124 , V_133 ) ;
return ! ferror ( V_127 -> V_3 ) ;
}
static T_2
F_73 ( T_5 * V_122 , const T_11 * V_94 , const T_11 * V_125 )
{
T_27 * V_127 = ( T_27 * ) V_122 -> V_7 ;
unsigned char V_133 [ V_134 ] ;
F_54 ( V_133 , V_125 , V_134 ) ;
fprintf ( V_127 -> V_3 , L_73 , V_94 ,
V_133 ) ;
fputs ( L_74 ,
V_127 -> V_3 ) ;
fputs ( L_75 ,
V_127 -> V_3 ) ;
fprintf ( V_127 -> V_3 , L_76 , V_94 ) ;
return ! ferror ( V_127 -> V_3 ) ;
}
static T_2
F_74 ( T_5 * V_122 )
{
T_27 * V_127 = ( T_27 * ) V_122 -> V_7 ;
fputs ( L_77 , V_127 -> V_3 ) ;
return ! ferror ( V_127 -> V_3 ) ;
}
static T_2
F_75 ( T_5 * V_122 )
{
T_27 * V_127 = ( T_27 * ) V_122 -> V_7 ;
F_76 ( V_127 -> V_3 ) ;
return ! ferror ( V_127 -> V_3 ) ;
}
static T_2
F_77 ( T_5 * V_122 )
{
T_27 * V_127 = ( T_27 * ) V_122 -> V_7 ;
T_2 V_131 ;
V_131 = F_4 ( V_127 -> V_1 , V_127 -> V_3 ) ;
F_16 ( V_127 ) ;
F_16 ( V_122 ) ;
return V_131 ;
}
static T_5 *
F_78 ( int V_1 , T_1 * V_3 )
{
T_5 * V_6 ;
T_27 * V_127 ;
V_127 = ( T_27 * ) F_67 ( sizeof *V_127 ) ;
V_127 -> V_1 = V_1 ;
V_127 -> V_3 = V_3 ;
V_6 = ( T_5 * ) F_67 ( sizeof ( T_5 ) ) ;
V_6 -> V_123 = & V_136 ;
V_6 -> V_7 = V_127 ;
return V_6 ;
}
T_5 *
F_79 ( int V_1 , const char * V_2 )
{
T_1 * V_3 ;
V_3 = F_1 ( V_1 , V_2 ) ;
if ( V_3 == NULL )
return NULL ;
return F_78 ( V_1 , V_3 ) ;
}
T_5 *
F_80 ( T_1 * V_3 )
{
return F_78 ( TRUE , V_3 ) ;
}
T_28 * F_81 ( void )
{
T_28 * V_137 = F_82 ( T_28 , 1 ) ;
V_137 -> V_138 = FALSE ;
V_137 -> V_139 = '\t' ;
V_137 -> V_140 = 'a' ;
V_137 -> V_141 = ',' ;
V_137 -> V_137 = NULL ;
V_137 -> V_142 = NULL ;
V_137 -> V_143 = NULL ;
V_137 -> V_144 = '\0' ;
return V_137 ;
}
T_29 F_83 ( T_28 * V_137 )
{
F_9 ( V_137 ) ;
if( NULL == V_137 -> V_137 ) {
return 0 ;
} else {
return V_137 -> V_137 -> V_64 ;
}
}
void F_84 ( T_28 * V_137 )
{
F_9 ( V_137 ) ;
if( NULL != V_137 -> V_142 ) {
F_85 ( V_137 -> V_142 ) ;
}
if( NULL != V_137 -> V_137 ) {
T_29 V_52 ;
for( V_52 = 0 ; V_52 < V_137 -> V_137 -> V_64 ; ++ V_52 ) {
T_11 * V_145 = ( T_11 * ) F_86 ( V_137 -> V_137 , V_52 ) ;
F_16 ( V_145 ) ;
}
F_29 ( V_137 -> V_137 , TRUE ) ;
}
F_16 ( V_137 ) ;
}
void F_87 ( T_28 * V_137 , const T_11 * V_145 )
{
T_11 * V_146 ;
F_9 ( V_137 ) ;
F_9 ( V_145 ) ;
if( NULL == V_137 -> V_137 ) {
V_137 -> V_137 = F_88 () ;
}
V_146 = F_89 ( V_145 ) ;
F_90 ( V_137 -> V_137 , V_146 ) ;
}
T_2 F_91 ( T_28 * V_147 , T_11 * V_148 )
{
const T_11 * V_149 ;
const T_11 * V_150 ;
F_9 ( V_147 ) ;
F_9 ( V_148 ) ;
if( '\0' == * V_148 ) {
return FALSE ;
}
V_149 = strtok ( V_148 , L_78 ) ;
if ( ! V_149 ) {
return FALSE ;
}
V_150 = V_148 + strlen ( V_149 ) + 1 ;
if( 0 == strcmp ( V_149 , L_79 ) ) {
switch( NULL == V_150 ? '\0' : * V_150 ) {
case 'n' :
V_147 -> V_138 = FALSE ;
break;
case 'y' :
V_147 -> V_138 = TRUE ;
break;
default:
return FALSE ;
}
return TRUE ;
}
if( 0 == strcmp ( V_149 , L_80 ) ) {
switch( NULL == V_150 ? '\0' : * V_150 ) {
case '\0' :
return FALSE ;
case '/' :
switch( * ++ V_150 ) {
case 't' :
V_147 -> V_139 = '\t' ;
break;
case 's' :
V_147 -> V_139 = ' ' ;
break;
default:
V_147 -> V_139 = '\\' ;
}
break;
default:
V_147 -> V_139 = * V_150 ;
break;
}
return TRUE ;
}
if( 0 == strcmp ( V_149 , L_81 ) ) {
switch( NULL == V_150 ? '\0' : * V_150 ) {
case 'f' :
case 'l' :
case 'a' :
V_147 -> V_140 = * V_150 ;
break;
default:
return FALSE ;
}
return TRUE ;
}
if( 0 == strcmp ( V_149 , L_82 ) ) {
switch( NULL == V_150 ? '\0' : * V_150 ) {
case '\0' :
return FALSE ;
case '/' :
switch( * ++ V_150 ) {
case 's' :
V_147 -> V_141 = ' ' ;
break;
default:
V_147 -> V_141 = '\\' ;
}
break;
default:
V_147 -> V_141 = * V_150 ;
break;
}
return TRUE ;
}
if( 0 == strcmp ( V_149 , L_83 ) ) {
switch( NULL == V_150 ? '\0' : * V_150 ) {
default:
case '\0' :
V_147 -> V_144 = '\0' ;
return FALSE ;
case 'd' :
V_147 -> V_144 = '"' ;
break;
case 's' :
V_147 -> V_144 = '\'' ;
break;
case 'n' :
V_147 -> V_144 = '\0' ;
break;
}
return TRUE ;
}
return FALSE ;
}
void F_92 ( T_1 * V_3 )
{
fprintf ( V_3 , L_84 ) ;
fputs ( L_85 , V_3 ) ;
fputs ( L_86 , V_3 ) ;
fputs ( L_87 , V_3 ) ;
fputs ( L_88 , V_3 ) ;
fputs ( L_89 , V_3 ) ;
}
void F_93 ( T_28 * V_137 , T_1 * V_3 )
{
T_29 V_52 ;
F_9 ( V_137 ) ;
F_9 ( V_3 ) ;
if( ! V_137 -> V_138 ) {
return;
}
for( V_52 = 0 ; V_52 < V_137 -> V_137 -> V_64 ; ++ V_52 ) {
const T_11 * V_145 = ( const T_11 * ) F_86 ( V_137 -> V_137 , V_52 ) ;
if( V_52 != 0 ) {
fputc ( V_137 -> V_139 , V_3 ) ;
}
fputs ( V_145 , V_3 ) ;
}
fputc ( '\n' , V_3 ) ;
}
static void F_94 ( T_7 * V_21 , T_8 V_7 )
{
T_30 * V_151 ;
T_9 * V_22 ;
T_8 V_152 ;
V_151 = ( T_30 * ) V_7 ;
V_22 = F_8 ( V_21 ) ;
F_9 ( V_22 && L_2 ) ;
V_152 = F_15 ( V_151 -> V_137 -> V_142 , V_22 -> V_31 -> V_32 ) ;
if( NULL != V_152 ) {
const T_11 * V_62 ;
V_62 = F_95 ( V_22 , V_151 -> V_5 ) ;
if( NULL != V_62 && '\0' != * V_62 ) {
T_24 V_153 ;
V_153 = F_96 ( V_152 ) ;
if ( V_151 -> V_137 -> V_143 [ V_153 - 1 ] == NULL ) {
V_151 -> V_137 -> V_143 [ V_153 - 1 ] = F_97 ( V_62 ) ;
} else if ( V_151 -> V_137 -> V_140 == 'l' ) {
F_98 ( V_151 -> V_137 -> V_143 [ V_153 - 1 ] , L_90 , V_62 ) ;
} else if ( V_151 -> V_137 -> V_140 == 'a' ) {
F_99 ( V_151 -> V_137 -> V_143 [ V_153 - 1 ] ,
L_91 , V_151 -> V_137 -> V_141 , V_62 ) ;
}
}
}
if ( V_21 -> V_41 != NULL ) {
F_7 ( V_21 , F_94 ,
V_151 ) ;
}
}
void F_100 ( T_28 * V_137 , T_4 * V_5 , T_1 * V_3 )
{
T_29 V_52 ;
T_30 V_7 ;
F_9 ( V_137 ) ;
F_9 ( V_5 ) ;
F_9 ( V_3 ) ;
V_7 . V_137 = V_137 ;
V_7 . V_5 = V_5 ;
if( NULL == V_137 -> V_142 ) {
V_137 -> V_142 = F_101 ( V_154 , V_155 ) ;
V_52 = 0 ;
while( V_52 < V_137 -> V_137 -> V_64 ) {
T_11 * V_145 = ( T_11 * ) F_86 ( V_137 -> V_137 , V_52 ) ;
++ V_52 ;
F_102 ( V_137 -> V_142 , V_145 , F_103 ( V_52 ) ) ;
}
}
V_137 -> V_143 = F_104 ( V_156 * , V_137 -> V_137 -> V_64 ) ;
F_7 ( V_5 -> V_19 , F_94 ,
& V_7 ) ;
for( V_52 = 0 ; V_52 < V_137 -> V_137 -> V_64 ; ++ V_52 ) {
if( 0 != V_52 ) {
fputc ( V_137 -> V_139 , V_3 ) ;
}
if( NULL != V_137 -> V_143 [ V_52 ] ) {
if( V_137 -> V_144 != '\0' ) {
fputc ( V_137 -> V_144 , V_3 ) ;
}
fputs ( V_137 -> V_143 [ V_52 ] -> V_88 , V_3 ) ;
if( V_137 -> V_144 != '\0' ) {
fputc ( V_137 -> V_144 , V_3 ) ;
}
}
}
}
void F_105 ( T_28 * V_137 V_83 , T_1 * V_3 V_83 )
{
}
const T_11 * F_95 ( T_9 * V_22 , T_4 * V_5 )
{
if ( V_22 -> V_31 -> V_33 == V_55 ) {
if ( V_22 -> V_28 ) {
return V_22 -> V_28 -> V_29 ;
}
else {
return F_106 ( V_5 -> V_11 . V_12 , V_22 ) ;
}
}
else if ( V_22 -> V_31 -> V_33 == V_34 ) {
return F_106 ( V_5 -> V_11 . V_12 , V_22 ) ;
}
else {
T_11 * V_50 ;
T_14 V_51 ;
switch ( V_22 -> V_31 -> type )
{
case V_54 :
if ( V_22 -> V_28 ) {
return V_22 -> V_28 -> V_29 ;
} else {
return V_22 -> V_31 -> V_32 ;
}
case V_60 :
return L_92 ;
default:
V_50 = F_25 ( V_22 ,
V_5 ) ;
if ( V_50 != NULL ) {
V_51 = strlen ( V_22 -> V_31 -> V_32 ) + 4 ;
if ( V_50 [ strlen ( V_50 ) - 1 ] == '"' ) {
V_50 [ strlen ( V_50 ) - 1 ] = '\0' ;
V_51 ++ ;
}
return & ( V_50 [ V_51 ] ) ;
} else {
return F_106 ( V_5 -> V_11 . V_12 , V_22 ) ;
}
}
}
}
static const T_11 *
F_106 ( T_20 * V_10 , T_9 * V_22 )
{
const T_10 * V_24 ;
if ( ! V_22 -> V_102 )
return NULL ;
if ( V_22 -> V_35 > F_48 ( V_22 -> V_102 , V_22 -> V_58 ) ) {
return L_64 ;
}
V_24 = F_17 ( V_10 , V_22 ) ;
if ( V_24 ) {
int V_52 ;
T_11 * V_157 ;
T_11 * V_104 ;
int V_64 ;
const int V_158 = 2 ;
V_64 = V_158 * V_22 -> V_35 ;
V_157 = F_107 ( T_11 , V_64 + 1 ) ;
V_157 [ V_64 ] = '\0' ;
V_104 = V_157 ;
for ( V_52 = 0 ; V_52 < V_22 -> V_35 ; V_52 ++ ) {
F_51 ( V_104 , V_158 + 1 , L_65 , V_24 [ V_52 ] ) ;
V_104 += V_158 ;
}
return V_157 ;
} else {
return NULL ;
}
}
