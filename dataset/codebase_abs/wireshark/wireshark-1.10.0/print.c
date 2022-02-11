static T_1 *
F_1 ( T_2 V_1 , const char * V_2 )
{
T_1 * V_3 ;
if ( V_1 )
V_3 = F_2 ( V_2 , L_1 ) ;
else
V_3 = F_3 ( V_2 , L_1 ) ;
return V_3 ;
}
static T_2
F_4 ( T_2 V_1 , T_1 * V_3 )
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
V_7 . V_13 = ( V_14 ) V_5 -> V_11 . V_15 -> V_16 . V_13 ;
V_7 . V_17 = V_4 -> V_17 ;
V_7 . V_18 = ! V_4 -> V_19 ;
V_7 . V_5 = V_5 ;
F_7 ( V_5 -> V_20 , V_21 , & V_7 ) ;
return V_7 . V_9 ;
}
static
void V_21 ( T_7 * V_22 , T_8 V_7 )
{
T_9 * V_23 = F_8 ( V_22 ) ;
T_6 * V_24 = ( T_6 * ) V_7 ;
const T_10 * V_25 ;
T_11 V_26 [ V_27 ] ;
T_11 * V_28 ;
F_9 ( V_23 ) ;
if ( F_10 ( V_22 ) )
return;
if ( ! V_24 -> V_9 )
return;
if ( V_23 -> V_29 ) {
V_28 = V_23 -> V_29 -> V_30 ;
}
else {
V_28 = V_26 ;
F_11 ( V_23 , V_26 ) ;
}
if ( F_12 ( V_22 ) ) {
V_28 = F_13 ( L_2 , V_28 ) ;
}
if ( ! F_14 ( V_24 -> V_6 , V_24 -> V_8 , V_28 ) ) {
V_24 -> V_9 = FALSE ;
return;
}
if ( ( V_31 != NULL ) && ( V_24 -> V_8 == 0 )
&& ( F_15 ( V_31 , V_23 -> V_32 -> V_33 ) == NULL ) ) {
V_24 -> V_9 = TRUE ;
return;
}
if ( F_12 ( V_22 ) ) {
F_16 ( V_28 ) ;
}
if ( ( V_23 -> V_32 -> V_34 == V_35 ) && ( V_24 -> V_18 ) ) {
V_25 = F_17 ( V_24 -> V_10 , V_23 ) ;
if ( V_25 ) {
if ( ! F_14 ( V_24 -> V_6 , 0 , L_3 ) ) {
V_24 -> V_9 = FALSE ;
return;
}
if ( ! F_18 ( V_24 -> V_6 , V_25 ,
V_23 -> V_36 , V_24 -> V_13 ) ) {
V_24 -> V_9 = FALSE ;
return;
}
}
}
F_9 ( ( V_23 -> V_37 >= - 1 ) && ( V_23 -> V_37 < V_38 ) ) ;
if ( ( V_24 -> V_17 == V_39 ) ||
( ( V_24 -> V_17 == V_40 ) &&
( V_23 -> V_37 >= 0 ) && V_41 [ V_23 -> V_37 ] ) ) {
if ( V_22 -> V_42 != NULL ) {
V_24 -> V_8 ++ ;
F_7 ( V_22 ,
V_21 , V_24 ) ;
V_24 -> V_8 -- ;
if ( ! V_24 -> V_9 )
return;
}
}
}
void
F_19 ( T_1 * V_3 , const T_11 * V_43 )
{
T_12 V_44 = time ( NULL ) ;
char * V_45 = asctime ( localtime ( & V_44 ) ) ;
V_45 [ strlen ( V_45 ) - 1 ] = 0 ;
fputs ( L_4 , V_3 ) ;
fputs ( L_5 V_46 L_6 , V_3 ) ;
fprintf ( V_3 , L_7 V_46 L_8 V_46 L_9 , F_20 () ) ;
fputs ( L_10 V_47 L_11 , V_3 ) ;
fprintf ( V_3 , L_12 , V_48 , V_49 , V_45 , V_43 ? V_43 : L_3 ) ;
}
void
F_21 ( T_4 * V_5 , T_1 * V_3 )
{
T_13 V_7 ;
V_7 . V_8 = 0 ;
V_7 . V_3 = V_3 ;
V_7 . V_10 = V_5 -> V_11 . V_12 ;
V_7 . V_5 = V_5 ;
fprintf ( V_3 , L_13 ) ;
F_22 ( V_5 -> V_20 , V_3 ) ;
F_7 ( V_5 -> V_20 , V_50 ,
& V_7 ) ;
fprintf ( V_3 , L_14 ) ;
}
static void
V_50 ( T_7 * V_22 , T_8 V_7 )
{
T_9 * V_23 = F_8 ( V_22 ) ;
T_13 * V_24 = ( T_13 * ) V_7 ;
const T_11 * V_28 ;
T_11 V_26 [ V_27 ] ;
char * V_51 ;
T_14 V_52 ;
int V_53 ;
T_2 V_54 ;
F_9 ( V_23 ) ;
V_54 =
( ( ( V_23 -> V_32 -> type != V_55 ) ||
( V_23 -> V_32 -> V_34 == V_35 ) ) &&
( V_24 -> V_8 == 0 ) ) ;
for ( V_53 = - 1 ; V_53 < V_24 -> V_8 ; V_53 ++ ) {
fputs ( L_15 , V_24 -> V_3 ) ;
}
if ( V_54 ) {
fputs ( L_16 , V_24 -> V_3 ) ;
V_24 -> V_8 ++ ;
for ( V_53 = - 1 ; V_53 < V_24 -> V_8 ; V_53 ++ ) {
fputs ( L_15 , V_24 -> V_3 ) ;
}
}
if ( V_23 -> V_32 -> V_34 == V_56 ) {
if ( V_23 -> V_29 ) {
V_28 = V_23 -> V_29 -> V_30 ;
}
else {
V_28 = L_3 ;
}
fputs ( L_17 , V_24 -> V_3 ) ;
fputs ( L_18 , V_24 -> V_3 ) ;
F_23 ( V_24 -> V_3 , V_28 ) ;
fprintf ( V_24 -> V_3 , L_19 , V_23 -> V_36 ) ;
if ( V_22 -> V_57 && V_22 -> V_57 -> V_58 && ( V_23 -> V_59 < V_22 -> V_57 -> V_58 -> V_59 ) ) {
fprintf ( V_24 -> V_3 , L_20 , V_22 -> V_57 -> V_58 -> V_59 + V_23 -> V_59 ) ;
} else {
fprintf ( V_24 -> V_3 , L_20 , V_23 -> V_59 ) ;
}
fputs ( L_21 , V_24 -> V_3 ) ;
F_24 ( V_24 , V_23 ) ;
if ( V_22 -> V_42 != NULL ) {
fputs ( L_22 , V_24 -> V_3 ) ;
}
else {
fputs ( L_23 , V_24 -> V_3 ) ;
}
}
else if ( V_23 -> V_32 -> V_34 == V_35 ) {
fputs ( L_24 , V_24 -> V_3 ) ;
F_24 ( V_24 , V_23 ) ;
fputs ( L_22 , V_24 -> V_3 ) ;
}
else {
if ( ( V_23 -> V_32 -> type == V_55 ) && ( V_23 -> V_32 -> V_34 != V_60 ) ) {
fputs ( L_25 , V_24 -> V_3 ) ;
}
else {
fputs ( L_17 , V_24 -> V_3 ) ;
}
F_23 ( V_24 -> V_3 , V_23 -> V_32 -> V_33 ) ;
#if 0
fputs("\" showname=\"", pdata->fh);
print_escaped_xml(pdata->fh, fi->hfinfo->name);
#endif
if ( V_23 -> V_29 ) {
fputs ( L_26 , V_24 -> V_3 ) ;
F_23 ( V_24 -> V_3 , V_23 -> V_29 -> V_30 ) ;
}
else {
V_28 = V_26 ;
F_11 ( V_23 , V_26 ) ;
fputs ( L_26 , V_24 -> V_3 ) ;
F_23 ( V_24 -> V_3 , V_28 ) ;
}
if ( F_10 ( V_22 ) )
fprintf ( V_24 -> V_3 , L_27 ) ;
fprintf ( V_24 -> V_3 , L_19 , V_23 -> V_36 ) ;
if ( V_22 -> V_57 && V_22 -> V_57 -> V_58 && ( V_23 -> V_59 < V_22 -> V_57 -> V_58 -> V_59 ) ) {
fprintf ( V_24 -> V_3 , L_20 , V_22 -> V_57 -> V_58 -> V_59 + V_23 -> V_59 ) ;
} else {
fprintf ( V_24 -> V_3 , L_20 , V_23 -> V_59 ) ;
}
switch ( V_23 -> V_32 -> type )
{
case V_55 :
break;
case V_61 :
fputs ( L_28 , V_24 -> V_3 ) ;
break;
default:
V_51 = F_25 ( V_23 ,
V_24 -> V_5 ) ;
if ( V_51 != NULL ) {
V_52 = strlen ( V_23 -> V_32 -> V_33 ) + 4 ;
if ( V_51 [ strlen ( V_51 ) - 1 ] == '"' ) {
V_51 [ strlen ( V_51 ) - 1 ] = '\0' ;
V_52 ++ ;
}
fputs ( L_18 , V_24 -> V_3 ) ;
F_23 ( V_24 -> V_3 , & V_51 [ V_52 ] ) ;
}
if ( V_23 -> V_36 > 0 ) {
fputs ( L_21 , V_24 -> V_3 ) ;
if ( V_23 -> V_32 -> V_62 != 0 ) {
fprintf ( V_24 -> V_3 , L_29 , F_26 ( & V_23 -> V_63 ) ) ;
fputs ( L_30 , V_24 -> V_3 ) ;
F_24 ( V_24 , V_23 ) ;
}
else {
F_24 ( V_24 , V_23 ) ;
}
}
}
if ( V_22 -> V_42 != NULL ) {
fputs ( L_22 , V_24 -> V_3 ) ;
}
else if ( V_23 -> V_32 -> V_34 == V_35 ) {
fputs ( L_22 , V_24 -> V_3 ) ;
}
else {
fputs ( L_23 , V_24 -> V_3 ) ;
}
}
if ( V_22 -> V_42 != NULL ) {
V_24 -> V_8 ++ ;
F_7 ( V_22 ,
V_50 , V_24 ) ;
V_24 -> V_8 -- ;
}
if ( V_54 ) {
V_24 -> V_8 -- ;
}
if ( V_22 -> V_42 != NULL ) {
for ( V_53 = - 1 ; V_53 < V_24 -> V_8 ; V_53 ++ ) {
fputs ( L_15 , V_24 -> V_3 ) ;
}
if ( ( V_23 -> V_32 -> V_34 != V_35 ) && ( V_23 -> V_32 -> V_34 != V_60 ) ) {
if ( V_23 -> V_32 -> type == V_55 ) {
fputs ( L_31 , V_24 -> V_3 ) ;
}
else {
fputs ( L_32 , V_24 -> V_3 ) ;
}
} else {
fputs ( L_32 , V_24 -> V_3 ) ;
}
}
if ( V_54 ) {
fputs ( L_31 , V_24 -> V_3 ) ;
}
}
static void
F_22 ( T_15 * V_20 , T_1 * V_3 )
{
T_16 V_64 , V_65 , V_66 ;
T_17 * V_67 ;
T_18 * V_68 ;
T_9 * V_69 ;
V_68 = F_27 ( V_20 , V_70 ) ;
if ( F_28 ( V_68 ) < 1 ) {
return;
}
V_69 = ( T_9 * ) V_68 -> V_24 [ 0 ] ;
F_29 ( V_68 , TRUE ) ;
V_68 = F_27 ( V_20 , V_71 ) ;
if ( F_28 ( V_68 ) < 1 ) {
return;
}
V_64 = F_26 ( & ( ( T_9 * ) V_68 -> V_24 [ 0 ] ) -> V_63 ) ;
F_29 ( V_68 , TRUE ) ;
V_68 = F_27 ( V_20 , V_72 ) ;
if ( F_28 ( V_68 ) < 1 ) {
return;
}
V_65 = F_26 ( & ( ( T_9 * ) V_68 -> V_24 [ 0 ] ) -> V_63 ) ;
F_29 ( V_68 , TRUE ) ;
V_68 = F_27 ( V_20 , V_73 ) ;
if ( F_28 ( V_68 ) < 1 ) {
return;
}
V_66 = F_26 ( & ( ( T_9 * ) V_68 -> V_24 [ 0 ] ) -> V_63 ) ;
F_29 ( V_68 , TRUE ) ;
V_68 = F_27 ( V_20 , V_74 ) ;
if ( F_28 ( V_68 ) < 1 ) {
return;
}
V_67 = ( T_17 * ) F_30 ( & ( ( T_9 * ) V_68 -> V_24 [ 0 ] ) -> V_63 ) ;
F_29 ( V_68 , TRUE ) ;
fprintf ( V_3 ,
L_33 ,
V_69 -> V_36 ) ;
fprintf ( V_3 ,
L_34 ,
V_64 , V_64 , V_69 -> V_36 ) ;
fprintf ( V_3 ,
L_35 ,
V_65 , V_65 , V_69 -> V_36 ) ;
fprintf ( V_3 ,
L_36 ,
V_66 , V_66 , V_69 -> V_36 ) ;
fprintf ( V_3 ,
L_37 ,
F_31 ( V_67 , V_75 , TRUE ) , ( int ) V_67 -> V_76 , V_67 -> V_77 , V_69 -> V_36 ) ;
fprintf ( V_3 ,
L_38 ) ;
}
void
F_32 ( T_1 * V_3 )
{
fputs ( L_39 , V_3 ) ;
}
void
F_33 ( T_1 * V_3 )
{
fputs ( L_4 , V_3 ) ;
fputs ( L_40 V_78 L_11 , V_3 ) ;
fprintf ( V_3 , L_41 , V_48 , V_49 ) ;
V_79 = TRUE ;
}
void
F_34 ( T_4 * V_5 , T_1 * V_3 )
{
T_19 V_53 ;
if ( V_79 ) {
fprintf ( V_3 , L_42 ) ;
for ( V_53 = 0 ; V_53 < V_5 -> V_11 . V_80 -> V_81 ; V_53 ++ ) {
fprintf ( V_3 , L_43 ) ;
F_23 ( V_3 , V_5 -> V_11 . V_80 -> V_82 [ V_53 ] ) ;
fprintf ( V_3 , L_44 ) ;
}
fprintf ( V_3 , L_45 ) ;
V_79 = FALSE ;
}
fprintf ( V_3 , L_13 ) ;
for ( V_53 = 0 ; V_53 < V_5 -> V_11 . V_80 -> V_81 ; V_53 ++ ) {
fprintf ( V_3 , L_43 ) ;
F_23 ( V_3 , V_5 -> V_11 . V_80 -> V_83 [ V_53 ] ) ;
fprintf ( V_3 , L_44 ) ;
}
fprintf ( V_3 , L_14 ) ;
}
void
F_35 ( T_1 * V_3 )
{
fputs ( L_46 , V_3 ) ;
}
void
F_36 ( T_1 * V_3 V_84 )
{
V_79 = TRUE ;
}
static T_11 * F_37 ( const T_11 * V_85 , const T_11 * V_86 )
{
T_11 * V_87 ;
T_11 * V_88 ;
V_87 = F_38 ( V_85 , V_86 ) ;
V_88 = V_87 ;
while ( ( V_88 = strstr ( V_88 , L_47 ) ) != NULL )
* V_88 = '\"' ;
return V_87 ;
}
static void F_39 ( const char * V_89 , char V_90 , T_1 * V_3 )
{
T_11 * V_87 ;
V_87 = F_37 ( V_89 , NULL ) ;
fprintf ( V_3 , L_48 , V_87 , V_90 ) ;
F_16 ( V_87 ) ;
}
void
F_40 ( T_4 * V_5 , T_1 * V_3 )
{
T_19 V_53 ;
if ( V_79 ) {
for ( V_53 = 0 ; V_53 < V_5 -> V_11 . V_80 -> V_81 - 1 ; V_53 ++ )
F_39 ( V_5 -> V_11 . V_80 -> V_82 [ V_53 ] , ',' , V_3 ) ;
F_39 ( V_5 -> V_11 . V_80 -> V_82 [ V_53 ] , '\n' , V_3 ) ;
V_79 = FALSE ;
}
for ( V_53 = 0 ; V_53 < V_5 -> V_11 . V_80 -> V_81 - 1 ; V_53 ++ )
F_39 ( V_5 -> V_11 . V_80 -> V_83 [ V_53 ] , ',' , V_3 ) ;
F_39 ( V_5 -> V_11 . V_80 -> V_83 [ V_53 ] , '\n' , V_3 ) ;
}
void
F_41 ( T_1 * V_3 V_84 )
{
}
void
F_42 ( T_1 * V_3 V_84 )
{
}
void
F_43 ( T_16 V_64 , T_1 * V_3 , T_4 * V_5 )
{
T_16 V_53 = 0 , V_91 = 0 ;
T_20 * V_92 ;
T_21 * V_93 ;
const char * V_94 ;
const T_22 * V_95 ;
T_23 V_36 ;
char V_96 [ 9 ] ;
struct V_97 * V_98 ;
for ( V_92 = V_5 -> V_11 . V_12 ; V_92 != NULL ; V_92 = V_92 -> V_99 ) {
memset ( V_96 , 0 , sizeof( V_96 ) ) ;
V_98 = (struct V_97 * ) V_92 -> V_7 ;
V_93 = F_44 ( V_98 ) ;
V_36 = F_45 ( V_93 ) ;
if ( V_36 == 0 )
continue;
V_95 = F_46 ( V_93 , 0 , V_36 ) ;
V_94 = F_47 ( V_98 ) ;
if ( V_94 )
fprintf ( V_3 , L_49 , V_94 ) ;
if ( V_91 ) {
fprintf ( V_3 , L_50 ,
V_64 , V_91 , V_36 ) ;
} else {
fprintf ( V_3 , L_51 ,
V_64 , V_36 ) ;
}
V_91 ++ ;
for ( V_53 = 0 ; V_53 < V_36 ; V_53 ++ ) {
fprintf ( V_3 , L_52 , * ( V_95 + V_53 ) ) ;
V_96 [ V_53 % 8 ] = isprint ( * ( V_95 + V_53 ) ) ? * ( V_95 + V_53 ) : '.' ;
if ( V_53 == ( V_36 - 1 ) ) {
T_23 V_100 ;
V_100 = V_36 % 8 ;
if ( V_100 ) {
T_23 V_101 ;
for ( V_101 = 0 ; V_101 < 8 - V_100 ; V_101 ++ )
fprintf ( V_3 , L_53 ) ;
}
fprintf ( V_3 , L_54 , V_96 ) ;
break;
}
if ( ! ( ( V_53 + 1 ) % 8 ) ) {
fprintf ( V_3 , L_55 , V_96 ) ;
memset ( V_96 , 0 , sizeof( V_96 ) ) ;
}
else {
fprintf ( V_3 , L_56 ) ;
}
}
}
}
void
F_48 ( T_1 * V_3 V_84 )
{
}
static const T_10 *
F_17 ( T_20 * V_10 , T_9 * V_23 )
{
T_20 * V_92 ;
T_21 * V_102 ;
T_19 V_36 , V_103 ;
struct V_97 * V_98 ;
for ( V_92 = V_10 ; V_92 != NULL ; V_92 = V_92 -> V_99 ) {
V_98 = (struct V_97 * ) V_92 -> V_7 ;
V_102 = F_44 ( V_98 ) ;
if ( V_23 -> V_104 == V_102 ) {
V_103 = F_49 ( V_102 ,
V_23 -> V_59 ) ;
if ( V_103 < 0 ) {
return NULL ;
}
V_36 = V_23 -> V_36 ;
if ( V_36 > V_103 )
V_36 = V_103 ;
return F_46 ( V_102 , V_23 -> V_59 , V_36 ) ;
}
}
F_50 () ;
return NULL ;
}
static void
F_23 ( T_1 * V_3 , const char * V_105 )
{
const char * V_106 ;
char V_107 [ 8 ] ;
for ( V_106 = V_105 ; * V_106 != '\0' ; V_106 ++ ) {
switch ( * V_106 ) {
case '&' :
fputs ( L_57 , V_3 ) ;
break;
case '<' :
fputs ( L_58 , V_3 ) ;
break;
case '>' :
fputs ( L_59 , V_3 ) ;
break;
case '"' :
fputs ( L_60 , V_3 ) ;
break;
case '\'' :
fputs ( L_61 , V_3 ) ;
break;
default:
if ( F_51 ( * V_106 ) )
fputc ( * V_106 , V_3 ) ;
else {
F_52 ( V_107 , sizeof( V_107 ) , L_62 , ( T_10 ) * V_106 ) ;
fputs ( V_107 , V_3 ) ;
}
}
}
}
static void
F_24 ( T_13 * V_24 , T_9 * V_23 )
{
int V_53 ;
const T_10 * V_25 ;
if ( ! V_23 -> V_104 )
return;
if ( V_23 -> V_36 > F_49 ( V_23 -> V_104 , V_23 -> V_59 ) ) {
fprintf ( V_24 -> V_3 , L_63 ) ;
return;
}
V_25 = F_17 ( V_24 -> V_10 , V_23 ) ;
if ( V_25 ) {
for ( V_53 = 0 ; V_53 < V_23 -> V_36 ; V_53 ++ ) {
fprintf ( V_24 -> V_3 , L_64 , V_25 [ V_53 ] ) ;
}
}
}
T_2
F_53 ( T_5 * V_6 , T_4 * V_5 )
{
T_2 V_108 ;
T_20 * V_92 ;
T_21 * V_93 ;
const char * V_94 ;
char * line ;
const T_22 * V_95 ;
T_23 V_36 ;
struct V_97 * V_98 ;
V_108 = ( V_5 -> V_11 . V_12 -> V_99 != NULL ) ;
for ( V_92 = V_5 -> V_11 . V_12 ; V_92 != NULL ;
V_92 = V_92 -> V_99 ) {
V_98 = (struct V_97 * ) V_92 -> V_7 ;
V_93 = F_44 ( V_98 ) ;
if ( V_108 ) {
V_94 = F_47 ( V_98 ) ;
line = F_13 ( L_65 , V_94 ) ;
F_14 ( V_6 , 0 , line ) ;
F_16 ( line ) ;
}
V_36 = F_45 ( V_93 ) ;
if ( V_36 == 0 )
return TRUE ;
V_95 = F_46 ( V_93 , 0 , V_36 ) ;
if ( ! F_18 ( V_6 , V_95 , V_36 ,
( V_14 ) V_5 -> V_11 . V_15 -> V_16 . V_13 ) )
return FALSE ;
}
return TRUE ;
}
static T_2
F_18 ( T_5 * V_6 , const T_22 * V_95 ,
T_23 V_36 , V_14 V_13 )
{
register unsigned int V_109 , V_53 , V_101 , V_110 , V_111 ;
T_22 V_112 ;
T_11 line [ V_113 + 1 ] ;
unsigned int V_114 ;
static T_11 V_115 [ 16 ] = {
'0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' ,
'8' , '9' , 'a' , 'b' , 'c' , 'd' , 'e' , 'f' } ;
if ( ( ( V_36 - 1 ) & 0xF0000000 ) != 0 )
V_114 = 8 ;
else if ( ( ( V_36 - 1 ) & 0x0F000000 ) != 0 )
V_114 = 7 ;
else if ( ( ( V_36 - 1 ) & 0x00F00000 ) != 0 )
V_114 = 6 ;
else if ( ( ( V_36 - 1 ) & 0x000F0000 ) != 0 )
V_114 = 5 ;
else
V_114 = 4 ;
V_109 = 0 ;
V_53 = 0 ;
V_101 = 0 ;
V_110 = 0 ;
while ( V_53 < V_36 ) {
if ( ( V_53 & 15 ) == 0 ) {
V_101 = 0 ;
V_111 = V_114 ;
do {
V_111 -- ;
V_112 = ( V_109 >> ( V_111 * 4 ) ) & 0xF ;
line [ V_101 ++ ] = V_115 [ V_112 ] ;
} while ( V_111 != 0 );
line [ V_101 ++ ] = ' ' ;
line [ V_101 ++ ] = ' ' ;
memset ( line + V_101 , ' ' , V_116 ) ;
V_110 = V_101 + V_117 + 2 ;
}
V_112 = * V_95 ++ ;
line [ V_101 ++ ] = V_115 [ V_112 >> 4 ] ;
line [ V_101 ++ ] = V_115 [ V_112 & 0xf ] ;
V_101 ++ ;
if ( V_13 == V_118 ) {
V_112 = F_54 ( V_112 ) ;
}
line [ V_110 ++ ] = ( ( V_112 >= ' ' ) && ( V_112 < 0x7f ) ) ? V_112 : '.' ;
V_53 ++ ;
if ( ( ( V_53 & 15 ) == 0 ) || ( V_53 == V_36 ) ) {
line [ V_110 ] = '\0' ;
if ( ! F_14 ( V_6 , 0 , line ) )
return FALSE ;
V_109 += 16 ;
}
}
return TRUE ;
}
static
void F_55 ( char * V_119 , const char * V_120 , int V_121 )
{
int V_122 , V_123 ;
char V_112 ;
if ( V_120 == NULL ) {
V_119 [ 0 ] = '\0' ;
return;
}
for ( V_122 = 0 , V_123 = 0 ; V_123 < V_121 ; V_122 ++ , V_123 ++ ) {
V_112 = V_120 [ V_122 ] ;
switch ( V_112 ) {
case '(' :
case ')' :
case '\\' :
V_119 [ V_123 ] = '\\' ;
V_119 [ ++ V_123 ] = V_112 ;
break;
default:
V_119 [ V_123 ] = V_112 ;
break;
}
if ( V_112 == 0 ) {
break;
}
}
}
T_2
F_56 ( T_5 * V_124 , T_11 * V_43 )
{
return V_124 -> V_125 -> F_56 ? ( V_124 -> V_125 -> F_56 ) ( V_124 , V_43 ) : TRUE ;
}
T_2
F_14 ( T_5 * V_124 , int V_126 , const char * line )
{
return ( V_124 -> V_125 -> F_14 ) ( V_124 , V_126 , line ) ;
}
T_2
F_57 ( T_5 * V_124 , const T_11 * V_94 , const T_11 * V_127 )
{
return V_124 -> V_125 -> F_57 ? ( V_124 -> V_125 -> F_57 ) ( V_124 , V_94 , V_127 ) : TRUE ;
}
T_2
F_58 ( T_5 * V_124 )
{
return V_124 -> V_125 -> F_58 ? ( V_124 -> V_125 -> F_58 ) ( V_124 ) : TRUE ;
}
T_2
F_59 ( T_5 * V_124 )
{
return V_124 -> V_125 -> F_59 ? ( V_124 -> V_125 -> F_59 ) ( V_124 ) : TRUE ;
}
T_2
F_60 ( T_5 * V_124 )
{
return V_124 -> V_125 -> V_128 ? ( V_124 -> V_125 -> V_128 ) ( V_124 ) : TRUE ;
}
static T_2
F_61 ( T_5 * V_124 , int V_126 , const char * line )
{
T_24 * V_129 = ( T_24 * ) V_124 -> V_7 ;
char V_130 [ V_131 + 1 ] ;
int V_53 ;
int V_132 ;
V_132 = V_126 * 4 ;
if ( V_132 > V_131 ) {
V_132 = V_131 ;
}
for ( V_53 = 0 ; V_53 < V_132 ; V_53 ++ ) {
V_130 [ V_53 ] = ' ' ;
}
V_130 [ V_132 ] = '\0' ;
fputs ( V_130 , V_129 -> V_3 ) ;
fputs ( line , V_129 -> V_3 ) ;
putc ( '\n' , V_129 -> V_3 ) ;
return ! ferror ( V_129 -> V_3 ) ;
}
static T_2
F_62 ( T_5 * V_124 )
{
T_24 * V_129 = ( T_24 * ) V_124 -> V_7 ;
fputs ( L_66 , V_129 -> V_3 ) ;
return ! ferror ( V_129 -> V_3 ) ;
}
static T_2
F_63 ( T_5 * V_124 )
{
T_24 * V_129 = ( T_24 * ) V_124 -> V_7 ;
T_2 V_133 ;
V_133 = F_4 ( V_129 -> V_1 , V_129 -> V_3 ) ;
F_16 ( V_129 ) ;
F_16 ( V_124 ) ;
return V_133 ;
}
static T_5 *
F_64 ( T_2 V_1 , T_1 * V_3 )
{
T_5 * V_6 ;
T_24 * V_129 ;
V_129 = ( T_24 * ) F_65 ( sizeof *V_129 ) ;
V_129 -> V_1 = V_1 ;
V_129 -> V_3 = V_3 ;
V_6 = ( T_5 * ) F_65 ( sizeof ( T_5 ) ) ;
V_6 -> V_125 = & V_134 ;
V_6 -> V_7 = V_129 ;
return V_6 ;
}
T_5 *
F_66 ( T_2 V_1 , const char * V_2 )
{
T_1 * V_3 ;
V_3 = F_1 ( V_1 , V_2 ) ;
if ( V_3 == NULL )
return NULL ;
return F_64 ( V_1 , V_3 ) ;
}
T_5 *
F_67 ( T_1 * V_3 )
{
return F_64 ( TRUE , V_3 ) ;
}
static T_2
F_68 ( T_5 * V_124 , T_11 * V_43 )
{
T_25 * V_129 = ( T_25 * ) V_124 -> V_7 ;
char V_135 [ V_136 ] ;
F_69 ( V_129 -> V_3 ) ;
fputs ( L_67 , V_129 -> V_3 ) ;
F_55 ( V_135 , V_43 , V_136 ) ;
fprintf ( V_129 -> V_3 , L_68 V_49 L_69 , V_135 , V_137 ) ;
fputs ( L_70 , V_129 -> V_3 ) ;
return ! ferror ( V_129 -> V_3 ) ;
}
static T_2
F_70 ( T_5 * V_124 , int V_126 , const char * line )
{
T_25 * V_129 = ( T_25 * ) V_124 -> V_7 ;
char V_135 [ V_136 ] ;
F_55 ( V_135 , line , V_136 ) ;
fprintf ( V_129 -> V_3 , L_71 , V_126 , V_135 ) ;
return ! ferror ( V_129 -> V_3 ) ;
}
static T_2
F_71 ( T_5 * V_124 , const T_11 * V_94 , const T_11 * V_127 )
{
T_25 * V_129 = ( T_25 * ) V_124 -> V_7 ;
char V_135 [ V_136 ] ;
F_55 ( V_135 , V_127 , V_136 ) ;
fprintf ( V_129 -> V_3 , L_72 , V_94 ,
V_135 ) ;
fputs ( L_73 ,
V_129 -> V_3 ) ;
fputs ( L_74 ,
V_129 -> V_3 ) ;
fprintf ( V_129 -> V_3 , L_75 , V_94 ) ;
return ! ferror ( V_129 -> V_3 ) ;
}
static T_2
F_72 ( T_5 * V_124 )
{
T_25 * V_129 = ( T_25 * ) V_124 -> V_7 ;
fputs ( L_76 , V_129 -> V_3 ) ;
return ! ferror ( V_129 -> V_3 ) ;
}
static T_2
F_73 ( T_5 * V_124 )
{
T_25 * V_129 = ( T_25 * ) V_124 -> V_7 ;
F_74 ( V_129 -> V_3 ) ;
return ! ferror ( V_129 -> V_3 ) ;
}
static T_2
F_75 ( T_5 * V_124 )
{
T_25 * V_129 = ( T_25 * ) V_124 -> V_7 ;
T_2 V_133 ;
V_133 = F_4 ( V_129 -> V_1 , V_129 -> V_3 ) ;
F_16 ( V_129 ) ;
F_16 ( V_124 ) ;
return V_133 ;
}
static T_5 *
F_76 ( T_2 V_1 , T_1 * V_3 )
{
T_5 * V_6 ;
T_25 * V_129 ;
V_129 = ( T_25 * ) F_65 ( sizeof *V_129 ) ;
V_129 -> V_1 = V_1 ;
V_129 -> V_3 = V_3 ;
V_6 = ( T_5 * ) F_65 ( sizeof ( T_5 ) ) ;
V_6 -> V_125 = & V_138 ;
V_6 -> V_7 = V_129 ;
return V_6 ;
}
T_5 *
F_77 ( T_2 V_1 , const char * V_2 )
{
T_1 * V_3 ;
V_3 = F_1 ( V_1 , V_2 ) ;
if ( V_3 == NULL )
return NULL ;
return F_76 ( V_1 , V_3 ) ;
}
T_5 *
F_78 ( T_1 * V_3 )
{
return F_76 ( TRUE , V_3 ) ;
}
T_26 * F_79 ( void )
{
T_26 * V_139 = F_80 ( T_26 , 1 ) ;
V_139 -> V_140 = FALSE ;
V_139 -> V_141 = '\t' ;
V_139 -> V_142 = 'a' ;
V_139 -> V_143 = ',' ;
V_139 -> V_139 = NULL ;
V_139 -> V_144 = NULL ;
V_139 -> V_145 = NULL ;
V_139 -> V_146 = '\0' ;
V_139 -> V_147 = FALSE ;
return V_139 ;
}
T_27 F_81 ( T_26 * V_139 )
{
F_9 ( V_139 ) ;
if ( NULL == V_139 -> V_139 ) {
return 0 ;
} else {
return V_139 -> V_139 -> V_65 ;
}
}
void F_82 ( T_26 * V_139 )
{
F_9 ( V_139 ) ;
if ( NULL != V_139 -> V_139 ) {
T_27 V_53 ;
if ( NULL != V_139 -> V_144 ) {
F_83 ( V_139 -> V_144 ) ;
}
if ( NULL != V_139 -> V_145 ) {
F_16 ( V_139 -> V_145 ) ;
}
for( V_53 = 0 ; V_53 < V_139 -> V_139 -> V_65 ; ++ V_53 ) {
T_11 * V_148 = ( T_11 * ) F_84 ( V_139 -> V_139 , V_53 ) ;
F_16 ( V_148 ) ;
}
F_29 ( V_139 -> V_139 , TRUE ) ;
}
F_16 ( V_139 ) ;
}
void F_85 ( T_26 * V_139 , const T_11 * V_148 )
{
T_11 * V_149 ;
F_9 ( V_139 ) ;
F_9 ( V_148 ) ;
if ( NULL == V_139 -> V_139 ) {
V_139 -> V_139 = F_86 () ;
}
V_149 = F_87 ( V_148 ) ;
F_88 ( V_139 -> V_139 , V_149 ) ;
if ( ! strncmp ( V_148 , V_150 , strlen ( V_150 ) ) )
V_139 -> V_147 = TRUE ;
}
T_2 F_89 ( T_26 * V_151 , T_11 * V_152 )
{
const T_11 * V_153 ;
const T_11 * V_154 ;
F_9 ( V_151 ) ;
F_9 ( V_152 ) ;
if ( '\0' == * V_152 ) {
return FALSE ;
}
V_153 = strtok ( V_152 , L_77 ) ;
if ( ! V_153 ) {
return FALSE ;
}
V_154 = V_152 + strlen ( V_153 ) + 1 ;
if ( 0 == strcmp ( V_153 , L_78 ) ) {
switch ( NULL == V_154 ? '\0' : * V_154 ) {
case 'n' :
V_151 -> V_140 = FALSE ;
break;
case 'y' :
V_151 -> V_140 = TRUE ;
break;
default:
return FALSE ;
}
return TRUE ;
}
if ( 0 == strcmp ( V_153 , L_79 ) ) {
switch ( NULL == V_154 ? '\0' : * V_154 ) {
case '\0' :
return FALSE ;
case '/' :
switch ( * ++ V_154 ) {
case 't' :
V_151 -> V_141 = '\t' ;
break;
case 's' :
V_151 -> V_141 = ' ' ;
break;
default:
V_151 -> V_141 = '\\' ;
}
break;
default:
V_151 -> V_141 = * V_154 ;
break;
}
return TRUE ;
}
if ( 0 == strcmp ( V_153 , L_80 ) ) {
switch ( NULL == V_154 ? '\0' : * V_154 ) {
case 'f' :
case 'l' :
case 'a' :
V_151 -> V_142 = * V_154 ;
break;
default:
return FALSE ;
}
return TRUE ;
}
if ( 0 == strcmp ( V_153 , L_81 ) ) {
switch ( NULL == V_154 ? '\0' : * V_154 ) {
case '\0' :
return FALSE ;
case '/' :
switch ( * ++ V_154 ) {
case 's' :
V_151 -> V_143 = ' ' ;
break;
default:
V_151 -> V_143 = '\\' ;
}
break;
default:
V_151 -> V_143 = * V_154 ;
break;
}
return TRUE ;
}
if ( 0 == strcmp ( V_153 , L_82 ) ) {
switch ( NULL == V_154 ? '\0' : * V_154 ) {
default:
case '\0' :
V_151 -> V_146 = '\0' ;
return FALSE ;
case 'd' :
V_151 -> V_146 = '"' ;
break;
case 's' :
V_151 -> V_146 = '\'' ;
break;
case 'n' :
V_151 -> V_146 = '\0' ;
break;
}
return TRUE ;
}
return FALSE ;
}
void F_90 ( T_1 * V_3 )
{
fprintf ( V_3 , L_83 ) ;
fputs ( L_84 , V_3 ) ;
fputs ( L_85 , V_3 ) ;
fputs ( L_86 , V_3 ) ;
fputs ( L_87 , V_3 ) ;
fputs ( L_88 , V_3 ) ;
}
T_2 F_91 ( T_26 * V_139 )
{
F_9 ( V_139 ) ;
return V_139 -> V_147 ;
}
void F_92 ( T_26 * V_139 , T_1 * V_3 )
{
T_27 V_53 ;
F_9 ( V_139 ) ;
F_9 ( V_3 ) ;
F_9 ( V_139 -> V_139 ) ;
if ( ! V_139 -> V_140 ) {
return;
}
for( V_53 = 0 ; V_53 < V_139 -> V_139 -> V_65 ; ++ V_53 ) {
const T_11 * V_148 = ( const T_11 * ) F_84 ( V_139 -> V_139 , V_53 ) ;
if ( V_53 != 0 ) {
fputc ( V_139 -> V_141 , V_3 ) ;
}
fputs ( V_148 , V_3 ) ;
}
fputc ( '\n' , V_3 ) ;
}
static void F_93 ( T_26 * V_139 , T_8 V_155 , const T_11 * V_63 )
{
T_23 V_156 ;
T_18 * V_157 ;
if ( ( NULL == V_63 ) || ( '\0' == * V_63 ) )
return;
V_156 = F_94 ( V_155 ) - 1 ;
if ( V_139 -> V_145 [ V_156 ] == NULL ) {
V_139 -> V_145 [ V_156 ] = F_86 () ;
}
V_157 = V_139 -> V_145 [ V_156 ] ;
switch ( V_139 -> V_142 ) {
case 'f' :
if ( F_28 ( V_157 ) != 0 )
return;
break;
case 'l' :
F_95 ( V_157 , 0 ) ;
break;
case 'a' :
if ( F_28 ( V_157 ) > 0 ) {
F_88 ( V_157 , ( T_8 ) F_96 ( L_89 , V_139 -> V_143 ) ) ;
}
break;
default:
F_50 () ;
break;
}
F_88 ( V_157 , ( T_8 ) V_63 ) ;
}
static void F_97 ( T_7 * V_22 , T_8 V_7 )
{
T_28 * V_158 ;
T_9 * V_23 ;
T_8 V_155 ;
V_158 = ( T_28 * ) V_7 ;
V_23 = F_8 ( V_22 ) ;
F_9 ( V_23 ) ;
V_155 = F_15 ( V_158 -> V_139 -> V_144 , V_23 -> V_32 -> V_33 ) ;
if ( NULL != V_155 ) {
F_93 ( V_158 -> V_139 , V_155 ,
F_98 ( V_23 , V_158 -> V_5 )
) ;
}
if ( V_22 -> V_42 != NULL ) {
F_7 ( V_22 , F_97 ,
V_158 ) ;
}
}
void F_99 ( T_26 * V_139 , T_4 * V_5 , T_29 * V_80 , T_1 * V_3 )
{
T_27 V_53 ;
T_19 V_159 ;
T_11 * V_160 ;
T_8 V_155 ;
T_28 V_7 ;
F_9 ( V_139 ) ;
F_9 ( V_139 -> V_139 ) ;
F_9 ( V_5 ) ;
F_9 ( V_3 ) ;
V_7 . V_139 = V_139 ;
V_7 . V_5 = V_5 ;
if ( NULL == V_139 -> V_144 ) {
V_139 -> V_144 = F_100 ( V_161 , V_162 ) ;
V_53 = 0 ;
while ( V_53 < V_139 -> V_139 -> V_65 ) {
T_11 * V_148 = ( T_11 * ) F_84 ( V_139 -> V_139 , V_53 ) ;
++ V_53 ;
F_101 ( V_139 -> V_144 , V_148 , F_102 ( V_53 ) ) ;
}
}
if ( NULL == V_139 -> V_145 )
V_139 -> V_145 = F_103 ( T_18 * , V_139 -> V_139 -> V_65 ) ;
F_7 ( V_5 -> V_20 , F_97 ,
& V_7 ) ;
if ( V_139 -> V_147 ) {
for ( V_159 = 0 ; V_159 < V_80 -> V_81 ; V_159 ++ ) {
V_160 = F_96 ( L_90 , V_150 , V_80 -> V_82 [ V_159 ] ) ;
V_155 = F_15 ( V_139 -> V_144 , V_160 ) ;
if ( NULL != V_155 ) {
F_93 ( V_139 , V_155 , V_80 -> V_83 [ V_159 ] ) ;
}
}
}
for( V_53 = 0 ; V_53 < V_139 -> V_139 -> V_65 ; ++ V_53 ) {
if ( 0 != V_53 ) {
fputc ( V_139 -> V_141 , V_3 ) ;
}
if ( NULL != V_139 -> V_145 [ V_53 ] ) {
T_18 * V_157 ;
T_27 V_101 ;
V_157 = V_139 -> V_145 [ V_53 ] ;
if ( V_139 -> V_146 != '\0' ) {
fputc ( V_139 -> V_146 , V_3 ) ;
}
for ( V_101 = 0 ; V_101 < F_28 ( V_157 ) ; V_101 ++ ) {
fputs ( ( T_11 * ) F_84 ( V_157 , V_101 ) , V_3 ) ;
}
if ( V_139 -> V_146 != '\0' ) {
fputc ( V_139 -> V_146 , V_3 ) ;
}
F_29 ( V_157 , TRUE ) ;
V_139 -> V_145 [ V_53 ] = NULL ;
}
}
}
void F_104 ( T_26 * V_139 V_84 , T_1 * V_3 V_84 )
{
}
const T_11 * F_98 ( T_9 * V_23 , T_4 * V_5 )
{
if ( V_23 -> V_32 -> V_34 == V_56 ) {
if ( V_23 -> V_29 ) {
return V_23 -> V_29 -> V_30 ;
}
else {
return F_105 ( V_5 -> V_11 . V_12 , V_23 ) ;
}
}
else if ( V_23 -> V_32 -> V_34 == V_35 ) {
return F_105 ( V_5 -> V_11 . V_12 , V_23 ) ;
}
else {
T_11 * V_51 ;
T_14 V_52 ;
switch ( V_23 -> V_32 -> type )
{
case V_55 :
if ( V_23 -> V_29 ) {
return V_23 -> V_29 -> V_30 ;
} else {
return V_23 -> V_32 -> V_33 ;
}
case V_61 :
return L_91 ;
default:
V_51 = F_25 ( V_23 ,
V_5 ) ;
if ( V_51 != NULL ) {
V_52 = strlen ( V_23 -> V_32 -> V_33 ) + 4 ;
if ( V_51 [ strlen ( V_51 ) - 1 ] == '"' ) {
V_51 [ strlen ( V_51 ) - 1 ] = '\0' ;
V_52 ++ ;
}
return & ( V_51 [ V_52 ] ) ;
} else {
return F_105 ( V_5 -> V_11 . V_12 , V_23 ) ;
}
}
}
}
static const T_11 *
F_105 ( T_20 * V_10 , T_9 * V_23 )
{
const T_10 * V_25 ;
if ( ! V_23 -> V_104 )
return NULL ;
if ( V_23 -> V_36 > F_49 ( V_23 -> V_104 , V_23 -> V_59 ) ) {
return L_63 ;
}
V_25 = F_17 ( V_10 , V_23 ) ;
if ( V_25 ) {
int V_53 ;
T_11 * V_163 ;
T_11 * V_106 ;
int V_65 ;
const int V_164 = 2 ;
V_65 = V_164 * V_23 -> V_36 ;
V_163 = F_106 ( T_11 , V_65 + 1 ) ;
V_163 [ V_65 ] = '\0' ;
V_106 = V_163 ;
for ( V_53 = 0 ; V_53 < V_23 -> V_36 ; V_53 ++ ) {
F_52 ( V_106 , V_164 + 1 , L_64 , V_25 [ V_53 ] ) ;
V_106 += V_164 ;
}
return V_163 ;
} else {
return NULL ;
}
}
