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
static void
V_21 ( T_7 * V_22 , T_8 V_7 )
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
if ( F_12 ( V_22 ) )
V_28 = F_13 ( L_2 , V_28 , L_3 , NULL ) ;
V_24 -> V_9 = F_14 ( V_24 -> V_6 , V_24 -> V_8 , V_28 ) ;
if ( F_12 ( V_22 ) )
F_15 ( V_28 ) ;
if ( ! V_24 -> V_9 )
return;
if ( ( V_31 != NULL ) && ( V_24 -> V_8 == 0 )
&& ( F_16 ( V_31 , V_23 -> V_32 -> V_33 ) == NULL ) ) {
return;
}
if ( ( V_23 -> V_32 -> V_34 == V_35 ) && ( V_24 -> V_18 ) ) {
V_25 = F_17 ( V_24 -> V_10 , V_23 ) ;
if ( V_25 ) {
if ( ! F_14 ( V_24 -> V_6 , 0 , L_4 ) ) {
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
( V_23 -> V_37 >= 0 ) && F_19 ( V_23 -> V_37 ) ) ) {
if ( V_22 -> V_41 != NULL ) {
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
F_20 ( T_1 * V_3 , const T_11 * V_42 )
{
T_12 V_43 = time ( NULL ) ;
char * V_44 = asctime ( localtime ( & V_43 ) ) ;
V_44 [ strlen ( V_44 ) - 1 ] = 0 ;
fputs ( L_5 , V_3 ) ;
fputs ( L_6 V_45 L_7 , V_3 ) ;
fprintf ( V_3 , L_8 V_45 L_9 V_45 L_10 , F_21 () ) ;
fputs ( L_11 V_46 L_12 , V_3 ) ;
fprintf ( V_3 , L_13 , V_47 , V_48 , V_44 , V_42 ? V_42 : L_4 ) ;
}
void
F_22 ( T_4 * V_5 , T_1 * V_3 )
{
T_13 V_7 ;
V_7 . V_8 = 0 ;
V_7 . V_3 = V_3 ;
V_7 . V_10 = V_5 -> V_11 . V_12 ;
V_7 . V_5 = V_5 ;
fprintf ( V_3 , L_14 ) ;
F_23 ( V_5 -> V_20 , V_3 ) ;
F_7 ( V_5 -> V_20 , V_49 ,
& V_7 ) ;
fprintf ( V_3 , L_15 ) ;
}
static void
V_49 ( T_7 * V_22 , T_8 V_7 )
{
T_9 * V_23 = F_8 ( V_22 ) ;
T_13 * V_24 = ( T_13 * ) V_7 ;
const T_11 * V_28 ;
T_11 V_26 [ V_27 ] ;
char * V_50 ;
int V_51 ;
T_2 V_52 ;
F_9 ( V_23 ) ;
V_52 =
( ( ( V_23 -> V_32 -> type != V_53 ) ||
( V_23 -> V_32 -> V_34 == V_35 ) ) &&
( V_24 -> V_8 == 0 ) ) ;
for ( V_51 = - 1 ; V_51 < V_24 -> V_8 ; V_51 ++ ) {
fputs ( L_16 , V_24 -> V_3 ) ;
}
if ( V_52 ) {
fputs ( L_17 , V_24 -> V_3 ) ;
V_24 -> V_8 ++ ;
for ( V_51 = - 1 ; V_51 < V_24 -> V_8 ; V_51 ++ ) {
fputs ( L_16 , V_24 -> V_3 ) ;
}
}
if ( V_23 -> V_32 -> V_34 == V_54 ) {
if ( V_23 -> V_29 ) {
V_28 = V_23 -> V_29 -> V_30 ;
}
else {
V_28 = L_4 ;
}
fputs ( L_18 , V_24 -> V_3 ) ;
fputs ( L_19 , V_24 -> V_3 ) ;
F_24 ( V_24 -> V_3 , V_28 ) ;
fprintf ( V_24 -> V_3 , L_20 , V_23 -> V_36 ) ;
if ( V_22 -> V_55 && V_22 -> V_55 -> V_56 && ( V_23 -> V_57 < V_22 -> V_55 -> V_56 -> V_57 ) ) {
fprintf ( V_24 -> V_3 , L_21 , V_22 -> V_55 -> V_56 -> V_57 + V_23 -> V_57 ) ;
} else {
fprintf ( V_24 -> V_3 , L_21 , V_23 -> V_57 ) ;
}
fputs ( L_22 , V_24 -> V_3 ) ;
F_25 ( V_24 , V_23 ) ;
if ( V_22 -> V_41 != NULL ) {
fputs ( L_23 , V_24 -> V_3 ) ;
}
else {
fputs ( L_24 , V_24 -> V_3 ) ;
}
}
else if ( V_23 -> V_32 -> V_34 == V_35 ) {
fputs ( L_25 , V_24 -> V_3 ) ;
F_25 ( V_24 , V_23 ) ;
fputs ( L_23 , V_24 -> V_3 ) ;
}
else {
if ( ( V_23 -> V_32 -> type == V_53 ) && ( V_23 -> V_32 -> V_34 != V_58 ) ) {
fputs ( L_26 , V_24 -> V_3 ) ;
}
else {
fputs ( L_18 , V_24 -> V_3 ) ;
}
F_24 ( V_24 -> V_3 , V_23 -> V_32 -> V_33 ) ;
#if 0
fputs("\" showname=\"", pdata->fh);
print_escaped_xml(pdata->fh, fi->hfinfo->name);
#endif
if ( V_23 -> V_29 ) {
fputs ( L_27 , V_24 -> V_3 ) ;
F_24 ( V_24 -> V_3 , V_23 -> V_29 -> V_30 ) ;
}
else {
V_28 = V_26 ;
F_11 ( V_23 , V_26 ) ;
fputs ( L_27 , V_24 -> V_3 ) ;
F_24 ( V_24 -> V_3 , V_28 ) ;
}
if ( F_10 ( V_22 ) )
fprintf ( V_24 -> V_3 , L_28 ) ;
fprintf ( V_24 -> V_3 , L_20 , V_23 -> V_36 ) ;
if ( V_22 -> V_55 && V_22 -> V_55 -> V_56 && ( V_23 -> V_57 < V_22 -> V_55 -> V_56 -> V_57 ) ) {
fprintf ( V_24 -> V_3 , L_21 , V_22 -> V_55 -> V_56 -> V_57 + V_23 -> V_57 ) ;
} else {
fprintf ( V_24 -> V_3 , L_21 , V_23 -> V_57 ) ;
}
switch ( V_23 -> V_32 -> type )
{
case V_53 :
break;
case V_59 :
fputs ( L_29 , V_24 -> V_3 ) ;
break;
default:
V_50 = F_26 ( & V_23 -> V_60 , V_61 , NULL ) ;
if ( V_50 != NULL ) {
fputs ( L_19 , V_24 -> V_3 ) ;
F_24 ( V_24 -> V_3 , V_50 ) ;
}
F_15 ( V_50 ) ;
if ( V_23 -> V_36 > 0 ) {
fputs ( L_22 , V_24 -> V_3 ) ;
if ( V_23 -> V_32 -> V_62 != 0 ) {
switch ( V_23 -> V_60 . V_63 -> V_63 ) {
case V_64 :
case V_65 :
case V_66 :
case V_67 :
fprintf ( V_24 -> V_3 , L_30 , ( V_68 ) F_27 ( & V_23 -> V_60 ) ) ;
break;
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
fprintf ( V_24 -> V_3 , L_30 , F_28 ( & V_23 -> V_60 ) ) ;
break;
case V_74 :
case V_75 :
fprintf ( V_24 -> V_3 , L_31 V_76 L_32 ,
F_29 ( & V_23 -> V_60 ) ) ;
break;
default:
F_30 () ;
}
fputs ( L_33 , V_24 -> V_3 ) ;
F_25 ( V_24 , V_23 ) ;
}
else {
F_25 ( V_24 , V_23 ) ;
}
}
}
if ( V_22 -> V_41 != NULL ) {
fputs ( L_23 , V_24 -> V_3 ) ;
}
else if ( V_23 -> V_32 -> V_34 == V_35 ) {
fputs ( L_23 , V_24 -> V_3 ) ;
}
else {
fputs ( L_24 , V_24 -> V_3 ) ;
}
}
if ( V_22 -> V_41 != NULL ) {
V_24 -> V_8 ++ ;
F_7 ( V_22 ,
V_49 , V_24 ) ;
V_24 -> V_8 -- ;
}
if ( V_52 ) {
V_24 -> V_8 -- ;
}
if ( V_22 -> V_41 != NULL ) {
for ( V_51 = - 1 ; V_51 < V_24 -> V_8 ; V_51 ++ ) {
fputs ( L_16 , V_24 -> V_3 ) ;
}
if ( ( V_23 -> V_32 -> V_34 != V_35 ) && ( V_23 -> V_32 -> V_34 != V_58 ) ) {
if ( V_23 -> V_32 -> type == V_53 ) {
fputs ( L_34 , V_24 -> V_3 ) ;
}
else {
fputs ( L_35 , V_24 -> V_3 ) ;
}
} else {
fputs ( L_35 , V_24 -> V_3 ) ;
}
}
if ( V_52 ) {
fputs ( L_34 , V_24 -> V_3 ) ;
}
}
static void
F_23 ( T_14 * V_20 , T_1 * V_3 )
{
T_15 V_77 , V_78 , V_79 ;
T_16 * V_80 ;
T_17 * V_81 ;
T_9 * V_82 ;
V_81 = F_31 ( V_20 , V_83 ) ;
if ( F_32 ( V_81 ) < 1 ) {
return;
}
V_82 = ( T_9 * ) V_81 -> V_24 [ 0 ] ;
F_33 ( V_81 , TRUE ) ;
V_81 = F_31 ( V_20 , V_84 ) ;
if ( F_32 ( V_81 ) < 1 ) {
return;
}
V_77 = F_28 ( & ( ( T_9 * ) V_81 -> V_24 [ 0 ] ) -> V_60 ) ;
F_33 ( V_81 , TRUE ) ;
V_81 = F_31 ( V_20 , V_85 ) ;
if ( F_32 ( V_81 ) < 1 ) {
return;
}
V_78 = F_28 ( & ( ( T_9 * ) V_81 -> V_24 [ 0 ] ) -> V_60 ) ;
F_33 ( V_81 , TRUE ) ;
V_81 = F_31 ( V_20 , V_86 ) ;
if ( F_32 ( V_81 ) < 1 ) {
return;
}
V_79 = F_28 ( & ( ( T_9 * ) V_81 -> V_24 [ 0 ] ) -> V_60 ) ;
F_33 ( V_81 , TRUE ) ;
V_81 = F_31 ( V_20 , V_87 ) ;
if ( F_32 ( V_81 ) < 1 ) {
return;
}
V_80 = ( T_16 * ) F_34 ( & ( ( T_9 * ) V_81 -> V_24 [ 0 ] ) -> V_60 ) ;
F_33 ( V_81 , TRUE ) ;
fprintf ( V_3 ,
L_36 ,
V_82 -> V_36 ) ;
fprintf ( V_3 ,
L_37 ,
V_77 , V_77 , V_82 -> V_36 ) ;
fprintf ( V_3 ,
L_38 ,
V_78 , V_78 , V_82 -> V_36 ) ;
fprintf ( V_3 ,
L_39 ,
V_79 , V_79 , V_82 -> V_36 ) ;
fprintf ( V_3 ,
L_40 ,
F_35 ( V_80 , V_88 , TRUE ) , ( int ) V_80 -> V_89 , V_80 -> V_90 , V_82 -> V_36 ) ;
fprintf ( V_3 ,
L_41 ) ;
}
void
F_36 ( T_1 * V_3 )
{
fputs ( L_42 , V_3 ) ;
}
void
F_37 ( T_1 * V_3 )
{
fputs ( L_5 , V_3 ) ;
fputs ( L_43 V_91 L_12 , V_3 ) ;
fprintf ( V_3 , L_44 , V_47 , V_48 ) ;
V_92 = TRUE ;
}
void
F_38 ( T_4 * V_5 , T_1 * V_3 )
{
T_18 V_51 ;
if ( V_92 ) {
fprintf ( V_3 , L_45 ) ;
for ( V_51 = 0 ; V_51 < V_5 -> V_11 . V_93 -> V_94 ; V_51 ++ ) {
fprintf ( V_3 , L_46 ) ;
F_24 ( V_3 , V_5 -> V_11 . V_93 -> V_95 [ V_51 ] ) ;
fprintf ( V_3 , L_47 ) ;
}
fprintf ( V_3 , L_48 ) ;
V_92 = FALSE ;
}
fprintf ( V_3 , L_14 ) ;
for ( V_51 = 0 ; V_51 < V_5 -> V_11 . V_93 -> V_94 ; V_51 ++ ) {
fprintf ( V_3 , L_46 ) ;
F_24 ( V_3 , V_5 -> V_11 . V_93 -> V_96 [ V_51 ] ) ;
fprintf ( V_3 , L_47 ) ;
}
fprintf ( V_3 , L_15 ) ;
}
void
F_39 ( T_1 * V_3 )
{
fputs ( L_49 , V_3 ) ;
}
void
F_40 ( T_1 * V_3 V_97 )
{
V_92 = TRUE ;
}
static T_11 * F_41 ( const T_11 * V_98 , const T_11 * V_99 )
{
T_11 * V_100 ;
T_11 * V_101 ;
V_100 = F_42 ( V_98 , V_99 ) ;
V_101 = V_100 ;
while ( ( V_101 = strstr ( V_101 , L_50 ) ) != NULL ) {
V_101 [ 0 ] = ' ' ;
V_101 [ 1 ] = '>' ;
V_101 [ 2 ] = ' ' ;
}
V_101 = V_100 ;
while ( ( V_101 = strstr ( V_101 , L_51 ) ) != NULL )
* V_101 = '\"' ;
return V_100 ;
}
static void F_43 ( const char * V_102 , char V_103 , T_1 * V_3 )
{
T_11 * V_100 ;
V_100 = F_41 ( V_102 , L_50 ) ;
fprintf ( V_3 , L_52 , V_100 , V_103 ) ;
F_15 ( V_100 ) ;
}
void
F_44 ( T_4 * V_5 , T_1 * V_3 )
{
T_18 V_51 ;
if ( V_92 ) {
for ( V_51 = 0 ; V_51 < V_5 -> V_11 . V_93 -> V_94 - 1 ; V_51 ++ )
F_43 ( V_5 -> V_11 . V_93 -> V_95 [ V_51 ] , ',' , V_3 ) ;
F_43 ( V_5 -> V_11 . V_93 -> V_95 [ V_51 ] , '\n' , V_3 ) ;
V_92 = FALSE ;
}
for ( V_51 = 0 ; V_51 < V_5 -> V_11 . V_93 -> V_94 - 1 ; V_51 ++ )
F_43 ( V_5 -> V_11 . V_93 -> V_96 [ V_51 ] , ',' , V_3 ) ;
F_43 ( V_5 -> V_11 . V_93 -> V_96 [ V_51 ] , '\n' , V_3 ) ;
}
void
F_45 ( T_1 * V_3 V_97 )
{
}
void
F_46 ( T_1 * V_3 V_97 )
{
}
void
F_47 ( T_15 V_77 , T_1 * V_3 , T_4 * V_5 )
{
T_15 V_51 = 0 , V_104 = 0 ;
T_19 * V_105 ;
T_20 * V_106 ;
const char * V_107 ;
const T_21 * V_108 ;
V_68 V_36 ;
char V_109 [ 9 ] ;
struct V_110 * V_111 ;
for ( V_105 = V_5 -> V_11 . V_12 ; V_105 != NULL ; V_105 = V_105 -> V_112 ) {
memset ( V_109 , 0 , sizeof( V_109 ) ) ;
V_111 = (struct V_110 * ) V_105 -> V_7 ;
V_106 = F_48 ( V_111 ) ;
V_36 = F_49 ( V_106 ) ;
if ( V_36 == 0 )
continue;
V_108 = F_50 ( V_106 , 0 , V_36 ) ;
V_107 = F_51 ( V_111 ) ;
if ( V_107 )
fprintf ( V_3 , L_53 , V_107 ) ;
if ( V_104 ) {
fprintf ( V_3 , L_54 ,
V_77 , V_104 , V_36 ) ;
} else {
fprintf ( V_3 , L_55 ,
V_77 , V_36 ) ;
}
V_104 ++ ;
for ( V_51 = 0 ; V_51 < V_36 ; V_51 ++ ) {
fprintf ( V_3 , L_56 , * ( V_108 + V_51 ) ) ;
V_109 [ V_51 % 8 ] = F_52 ( * ( V_108 + V_51 ) ) ? * ( V_108 + V_51 ) : '.' ;
if ( V_51 == ( V_36 - 1 ) ) {
V_68 V_113 ;
V_113 = V_36 % 8 ;
if ( V_113 ) {
V_68 V_114 ;
for ( V_114 = 0 ; V_114 < 8 - V_113 ; V_114 ++ )
fprintf ( V_3 , L_57 ) ;
}
fprintf ( V_3 , L_58 , V_109 ) ;
break;
}
if ( ! ( ( V_51 + 1 ) % 8 ) ) {
fprintf ( V_3 , L_59 , V_109 ) ;
memset ( V_109 , 0 , sizeof( V_109 ) ) ;
}
else {
fprintf ( V_3 , L_60 ) ;
}
}
}
}
void
F_53 ( T_1 * V_3 V_97 )
{
}
static const T_10 *
F_17 ( T_19 * V_10 , T_9 * V_23 )
{
T_19 * V_105 ;
T_20 * V_115 ;
T_18 V_36 , V_116 ;
struct V_110 * V_111 ;
for ( V_105 = V_10 ; V_105 != NULL ; V_105 = V_105 -> V_112 ) {
V_111 = (struct V_110 * ) V_105 -> V_7 ;
V_115 = F_48 ( V_111 ) ;
if ( V_23 -> V_117 == V_115 ) {
V_116 = F_54 ( V_115 ,
V_23 -> V_57 ) ;
if ( V_116 < 0 ) {
return NULL ;
}
V_36 = V_23 -> V_36 ;
if ( V_36 > V_116 )
V_36 = V_116 ;
return F_50 ( V_115 , V_23 -> V_57 , V_36 ) ;
}
}
F_30 () ;
return NULL ;
}
static void
F_24 ( T_1 * V_3 , const char * V_118 )
{
const char * V_119 ;
char V_120 [ 8 ] ;
for ( V_119 = V_118 ; * V_119 != '\0' ; V_119 ++ ) {
switch ( * V_119 ) {
case '&' :
fputs ( L_61 , V_3 ) ;
break;
case '<' :
fputs ( L_62 , V_3 ) ;
break;
case '>' :
fputs ( L_63 , V_3 ) ;
break;
case '"' :
fputs ( L_64 , V_3 ) ;
break;
case '\'' :
fputs ( L_65 , V_3 ) ;
break;
default:
if ( F_52 ( * V_119 ) )
fputc ( * V_119 , V_3 ) ;
else {
F_55 ( V_120 , sizeof( V_120 ) , L_66 , ( T_10 ) * V_119 ) ;
fputs ( V_120 , V_3 ) ;
}
}
}
}
static void
F_25 ( T_13 * V_24 , T_9 * V_23 )
{
int V_51 ;
const T_10 * V_25 ;
if ( ! V_23 -> V_117 )
return;
if ( V_23 -> V_36 > F_54 ( V_23 -> V_117 , V_23 -> V_57 ) ) {
fprintf ( V_24 -> V_3 , L_67 ) ;
return;
}
V_25 = F_17 ( V_24 -> V_10 , V_23 ) ;
if ( V_25 ) {
for ( V_51 = 0 ; V_51 < V_23 -> V_36 ; V_51 ++ ) {
fprintf ( V_24 -> V_3 , L_68 , V_25 [ V_51 ] ) ;
}
}
}
T_2
F_56 ( T_5 * V_6 , T_4 * V_5 )
{
T_2 V_121 ;
T_19 * V_105 ;
T_20 * V_106 ;
const char * V_107 ;
char * line ;
const T_21 * V_108 ;
V_68 V_36 ;
struct V_110 * V_111 ;
V_121 = ( V_5 -> V_11 . V_12 -> V_112 != NULL ) ;
for ( V_105 = V_5 -> V_11 . V_12 ; V_105 != NULL ;
V_105 = V_105 -> V_112 ) {
V_111 = (struct V_110 * ) V_105 -> V_7 ;
V_106 = F_48 ( V_111 ) ;
if ( V_121 ) {
V_107 = F_51 ( V_111 ) ;
line = F_57 ( L_69 , V_107 ) ;
F_14 ( V_6 , 0 , line ) ;
F_15 ( line ) ;
}
V_36 = F_49 ( V_106 ) ;
if ( V_36 == 0 )
return TRUE ;
V_108 = F_50 ( V_106 , 0 , V_36 ) ;
if ( ! F_18 ( V_6 , V_108 , V_36 ,
( V_14 ) V_5 -> V_11 . V_15 -> V_16 . V_13 ) )
return FALSE ;
}
return TRUE ;
}
static T_2
F_18 ( T_5 * V_6 , const T_21 * V_108 ,
V_68 V_36 , V_14 V_13 )
{
register unsigned int V_122 , V_51 , V_114 , V_123 , V_124 ;
T_21 V_125 ;
T_11 line [ V_126 + 1 ] ;
unsigned int V_127 ;
static T_11 V_128 [ 16 ] = {
'0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' ,
'8' , '9' , 'a' , 'b' , 'c' , 'd' , 'e' , 'f' } ;
if ( ( ( V_36 - 1 ) & 0xF0000000 ) != 0 )
V_127 = 8 ;
else if ( ( ( V_36 - 1 ) & 0x0F000000 ) != 0 )
V_127 = 7 ;
else if ( ( ( V_36 - 1 ) & 0x00F00000 ) != 0 )
V_127 = 6 ;
else if ( ( ( V_36 - 1 ) & 0x000F0000 ) != 0 )
V_127 = 5 ;
else
V_127 = 4 ;
V_122 = 0 ;
V_51 = 0 ;
V_114 = 0 ;
V_123 = 0 ;
while ( V_51 < V_36 ) {
if ( ( V_51 & 15 ) == 0 ) {
V_114 = 0 ;
V_124 = V_127 ;
do {
V_124 -- ;
V_125 = ( V_122 >> ( V_124 * 4 ) ) & 0xF ;
line [ V_114 ++ ] = V_128 [ V_125 ] ;
} while ( V_124 != 0 );
line [ V_114 ++ ] = ' ' ;
line [ V_114 ++ ] = ' ' ;
memset ( line + V_114 , ' ' , V_129 ) ;
V_123 = V_114 + V_130 + 2 ;
}
V_125 = * V_108 ++ ;
line [ V_114 ++ ] = V_128 [ V_125 >> 4 ] ;
line [ V_114 ++ ] = V_128 [ V_125 & 0xf ] ;
V_114 ++ ;
if ( V_13 == V_131 ) {
V_125 = F_58 ( V_125 ) ;
}
line [ V_123 ++ ] = ( ( V_125 >= ' ' ) && ( V_125 < 0x7f ) ) ? V_125 : '.' ;
V_51 ++ ;
if ( ( ( V_51 & 15 ) == 0 ) || ( V_51 == V_36 ) ) {
line [ V_123 ] = '\0' ;
if ( ! F_14 ( V_6 , 0 , line ) )
return FALSE ;
V_122 += 16 ;
}
}
return TRUE ;
}
static
void F_59 ( char * V_132 , const char * V_133 , int V_134 )
{
int V_135 , V_136 ;
char V_125 ;
if ( V_133 == NULL ) {
V_132 [ 0 ] = '\0' ;
return;
}
for ( V_135 = 0 , V_136 = 0 ; V_136 < V_134 ; V_135 ++ , V_136 ++ ) {
V_125 = V_133 [ V_135 ] ;
switch ( V_125 ) {
case '(' :
case ')' :
case '\\' :
V_132 [ V_136 ] = '\\' ;
V_132 [ ++ V_136 ] = V_125 ;
break;
default:
V_132 [ V_136 ] = V_125 ;
break;
}
if ( V_125 == 0 ) {
break;
}
}
}
T_2
F_60 ( T_5 * V_137 , T_11 * V_42 , const char * V_138 )
{
return V_137 -> V_139 -> F_60 ? ( V_137 -> V_139 -> F_60 ) ( V_137 , V_42 , V_138 ) : TRUE ;
}
T_2
F_14 ( T_5 * V_137 , int V_140 , const char * line )
{
return ( V_137 -> V_139 -> F_14 ) ( V_137 , V_140 , line ) ;
}
T_2
F_61 ( T_5 * V_137 , const T_11 * V_107 , const T_11 * V_141 )
{
return V_137 -> V_139 -> F_61 ? ( V_137 -> V_139 -> F_61 ) ( V_137 , V_107 , V_141 ) : TRUE ;
}
T_2
F_62 ( T_5 * V_137 )
{
return V_137 -> V_139 -> F_62 ? ( V_137 -> V_139 -> F_62 ) ( V_137 ) : TRUE ;
}
T_2
F_63 ( T_5 * V_137 )
{
return V_137 -> V_139 -> F_63 ? ( V_137 -> V_139 -> F_63 ) ( V_137 ) : TRUE ;
}
T_2
F_64 ( T_5 * V_137 )
{
return V_137 -> V_139 -> V_142 ? ( V_137 -> V_139 -> V_142 ) ( V_137 ) : TRUE ;
}
static T_2
F_65 ( T_5 * V_137 , int V_140 , const char * line )
{
static char V_143 [ V_144 ] ;
T_22 V_145 ;
T_23 * V_146 = ( T_23 * ) V_137 -> V_7 ;
unsigned int V_147 ;
if ( ! V_143 [ 0 ] ) {
int V_51 ;
for ( V_51 = 0 ; V_51 < V_144 ; V_51 ++ )
V_143 [ V_51 ] = ' ' ;
}
V_147 = V_140 * 4 ;
if ( V_147 > V_144 )
V_147 = V_144 ;
V_145 = fwrite ( V_143 , 1 , V_147 , V_146 -> V_3 ) ;
if ( V_145 == V_147 ) {
fputs ( line , V_146 -> V_3 ) ;
putc ( '\n' , V_146 -> V_3 ) ;
}
return ! ferror ( V_146 -> V_3 ) ;
}
static T_2
F_66 ( T_5 * V_137 )
{
T_23 * V_146 = ( T_23 * ) V_137 -> V_7 ;
fputs ( L_70 , V_146 -> V_3 ) ;
return ! ferror ( V_146 -> V_3 ) ;
}
static T_2
F_67 ( T_5 * V_137 )
{
T_23 * V_146 = ( T_23 * ) V_137 -> V_7 ;
T_2 V_145 ;
V_145 = F_4 ( V_146 -> V_1 , V_146 -> V_3 ) ;
F_15 ( V_146 ) ;
F_15 ( V_137 ) ;
return V_145 ;
}
static T_5 *
F_68 ( T_2 V_1 , T_1 * V_3 )
{
T_5 * V_6 ;
T_23 * V_146 ;
V_146 = ( T_23 * ) F_69 ( sizeof *V_146 ) ;
V_146 -> V_1 = V_1 ;
V_146 -> V_3 = V_3 ;
V_6 = ( T_5 * ) F_69 ( sizeof ( T_5 ) ) ;
V_6 -> V_139 = & V_148 ;
V_6 -> V_7 = V_146 ;
return V_6 ;
}
T_5 *
F_70 ( T_2 V_1 , const char * V_2 )
{
T_1 * V_3 ;
V_3 = F_1 ( V_1 , V_2 ) ;
if ( V_3 == NULL )
return NULL ;
return F_68 ( V_1 , V_3 ) ;
}
T_5 *
F_71 ( T_1 * V_3 )
{
return F_68 ( TRUE , V_3 ) ;
}
static T_2
F_72 ( T_5 * V_137 , T_11 * V_42 , const char * V_138 )
{
T_24 * V_146 = ( T_24 * ) V_137 -> V_7 ;
char V_149 [ V_150 ] ;
F_73 ( V_146 -> V_3 ) ;
fputs ( L_71 , V_146 -> V_3 ) ;
F_59 ( V_149 , V_42 , V_150 ) ;
fprintf ( V_146 -> V_3 , L_72 V_48 L_73 , V_149 , V_138 ) ;
fputs ( L_74 , V_146 -> V_3 ) ;
return ! ferror ( V_146 -> V_3 ) ;
}
static T_2
F_74 ( T_5 * V_137 , int V_140 , const char * line )
{
T_24 * V_146 = ( T_24 * ) V_137 -> V_7 ;
char V_149 [ V_150 ] ;
F_59 ( V_149 , line , V_150 ) ;
fprintf ( V_146 -> V_3 , L_75 , V_140 , V_149 ) ;
return ! ferror ( V_146 -> V_3 ) ;
}
static T_2
F_75 ( T_5 * V_137 , const T_11 * V_107 , const T_11 * V_141 )
{
T_24 * V_146 = ( T_24 * ) V_137 -> V_7 ;
char V_149 [ V_150 ] ;
F_59 ( V_149 , V_141 , V_150 ) ;
fprintf ( V_146 -> V_3 , L_76 , V_107 ,
V_149 ) ;
fputs ( L_77 ,
V_146 -> V_3 ) ;
fputs ( L_78 ,
V_146 -> V_3 ) ;
fprintf ( V_146 -> V_3 , L_79 , V_107 ) ;
return ! ferror ( V_146 -> V_3 ) ;
}
static T_2
F_76 ( T_5 * V_137 )
{
T_24 * V_146 = ( T_24 * ) V_137 -> V_7 ;
fputs ( L_80 , V_146 -> V_3 ) ;
return ! ferror ( V_146 -> V_3 ) ;
}
static T_2
F_77 ( T_5 * V_137 )
{
T_24 * V_146 = ( T_24 * ) V_137 -> V_7 ;
F_78 ( V_146 -> V_3 ) ;
return ! ferror ( V_146 -> V_3 ) ;
}
static T_2
F_79 ( T_5 * V_137 )
{
T_24 * V_146 = ( T_24 * ) V_137 -> V_7 ;
T_2 V_145 ;
V_145 = F_4 ( V_146 -> V_1 , V_146 -> V_3 ) ;
F_15 ( V_146 ) ;
F_15 ( V_137 ) ;
return V_145 ;
}
static T_5 *
F_80 ( T_2 V_1 , T_1 * V_3 )
{
T_5 * V_6 ;
T_24 * V_146 ;
V_146 = ( T_24 * ) F_69 ( sizeof *V_146 ) ;
V_146 -> V_1 = V_1 ;
V_146 -> V_3 = V_3 ;
V_6 = ( T_5 * ) F_69 ( sizeof ( T_5 ) ) ;
V_6 -> V_139 = & V_151 ;
V_6 -> V_7 = V_146 ;
return V_6 ;
}
T_5 *
F_81 ( T_2 V_1 , const char * V_2 )
{
T_1 * V_3 ;
V_3 = F_1 ( V_1 , V_2 ) ;
if ( V_3 == NULL )
return NULL ;
return F_80 ( V_1 , V_3 ) ;
}
T_5 *
F_82 ( T_1 * V_3 )
{
return F_80 ( TRUE , V_3 ) ;
}
T_25 * F_83 ( void )
{
T_25 * V_152 = F_84 ( T_25 , 1 ) ;
V_152 -> V_153 = FALSE ;
V_152 -> V_154 = '\t' ;
V_152 -> V_155 = 'a' ;
V_152 -> V_156 = ',' ;
V_152 -> V_152 = NULL ;
V_152 -> V_157 = NULL ;
V_152 -> V_158 = NULL ;
V_152 -> V_159 = '\0' ;
V_152 -> V_160 = FALSE ;
return V_152 ;
}
T_26 F_85 ( T_25 * V_152 )
{
F_9 ( V_152 ) ;
if ( NULL == V_152 -> V_152 ) {
return 0 ;
} else {
return V_152 -> V_152 -> V_78 ;
}
}
void F_86 ( T_25 * V_152 )
{
F_9 ( V_152 ) ;
if ( NULL != V_152 -> V_152 ) {
T_26 V_51 ;
if ( NULL != V_152 -> V_157 ) {
F_87 ( V_152 -> V_157 ) ;
}
if ( NULL != V_152 -> V_158 ) {
F_15 ( V_152 -> V_158 ) ;
}
for( V_51 = 0 ; V_51 < V_152 -> V_152 -> V_78 ; ++ V_51 ) {
T_11 * V_161 = ( T_11 * ) F_88 ( V_152 -> V_152 , V_51 ) ;
F_15 ( V_161 ) ;
}
F_33 ( V_152 -> V_152 , TRUE ) ;
}
F_15 ( V_152 ) ;
}
void F_89 ( T_25 * V_152 , const T_11 * V_161 )
{
T_11 * V_162 ;
F_9 ( V_152 ) ;
F_9 ( V_161 ) ;
if ( NULL == V_152 -> V_152 ) {
V_152 -> V_152 = F_90 () ;
}
V_162 = F_91 ( V_161 ) ;
F_92 ( V_152 -> V_152 , V_162 ) ;
if ( ! strncmp ( V_161 , V_163 , strlen ( V_163 ) ) )
V_152 -> V_160 = TRUE ;
}
static void
F_93 ( void * V_7 , void * V_164 )
{
T_11 * V_161 = ( T_11 * ) V_7 ;
T_2 * V_165 = ( T_2 * ) V_164 ;
if ( ! strncmp ( V_161 , V_163 , strlen ( V_163 ) ) )
return;
if ( ! F_94 ( V_161 ) ) {
F_95 ( L_81 , V_161 ) ;
* V_165 = FALSE ;
}
}
T_2
F_96 ( T_25 * V_152 )
{
T_2 V_165 = TRUE ;
if ( V_152 -> V_152 == NULL ) {
return TRUE ;
}
F_97 ( V_152 -> V_152 , F_93 , & V_165 ) ;
return V_165 ;
}
T_2 F_98 ( T_25 * V_166 , T_11 * V_167 )
{
const T_11 * V_168 ;
const T_11 * V_169 ;
F_9 ( V_166 ) ;
F_9 ( V_167 ) ;
if ( '\0' == * V_167 ) {
return FALSE ;
}
V_168 = strtok ( V_167 , L_82 ) ;
if ( ! V_168 ) {
return FALSE ;
}
V_169 = V_167 + strlen ( V_168 ) + 1 ;
if ( 0 == strcmp ( V_168 , L_83 ) ) {
switch ( NULL == V_169 ? '\0' : * V_169 ) {
case 'n' :
V_166 -> V_153 = FALSE ;
break;
case 'y' :
V_166 -> V_153 = TRUE ;
break;
default:
return FALSE ;
}
return TRUE ;
}
if ( 0 == strcmp ( V_168 , L_84 ) ) {
switch ( NULL == V_169 ? '\0' : * V_169 ) {
case '\0' :
return FALSE ;
case '/' :
switch ( * ++ V_169 ) {
case 't' :
V_166 -> V_154 = '\t' ;
break;
case 's' :
V_166 -> V_154 = ' ' ;
break;
default:
V_166 -> V_154 = '\\' ;
}
break;
default:
V_166 -> V_154 = * V_169 ;
break;
}
return TRUE ;
}
if ( 0 == strcmp ( V_168 , L_85 ) ) {
switch ( NULL == V_169 ? '\0' : * V_169 ) {
case 'f' :
case 'l' :
case 'a' :
V_166 -> V_155 = * V_169 ;
break;
default:
return FALSE ;
}
return TRUE ;
}
if ( 0 == strcmp ( V_168 , L_86 ) ) {
switch ( NULL == V_169 ? '\0' : * V_169 ) {
case '\0' :
return FALSE ;
case '/' :
switch ( * ++ V_169 ) {
case 's' :
V_166 -> V_156 = ' ' ;
break;
default:
V_166 -> V_156 = '\\' ;
}
break;
default:
V_166 -> V_156 = * V_169 ;
break;
}
return TRUE ;
}
if ( 0 == strcmp ( V_168 , L_87 ) ) {
switch ( NULL == V_169 ? '\0' : * V_169 ) {
default:
case '\0' :
V_166 -> V_159 = '\0' ;
return FALSE ;
case 'd' :
V_166 -> V_159 = '"' ;
break;
case 's' :
V_166 -> V_159 = '\'' ;
break;
case 'n' :
V_166 -> V_159 = '\0' ;
break;
}
return TRUE ;
}
return FALSE ;
}
void F_99 ( T_1 * V_3 )
{
fprintf ( V_3 , L_88 ) ;
fputs ( L_89 , V_3 ) ;
fputs ( L_90 , V_3 ) ;
fputs ( L_91 , V_3 ) ;
fputs ( L_92 , V_3 ) ;
fputs ( L_93 , V_3 ) ;
}
T_2 F_100 ( T_25 * V_152 )
{
F_9 ( V_152 ) ;
return V_152 -> V_160 ;
}
void F_101 ( T_25 * V_152 , T_1 * V_3 )
{
T_26 V_51 ;
F_9 ( V_152 ) ;
F_9 ( V_3 ) ;
F_9 ( V_152 -> V_152 ) ;
if ( ! V_152 -> V_153 ) {
return;
}
for( V_51 = 0 ; V_51 < V_152 -> V_152 -> V_78 ; ++ V_51 ) {
const T_11 * V_161 = ( const T_11 * ) F_88 ( V_152 -> V_152 , V_51 ) ;
if ( V_51 != 0 ) {
fputc ( V_152 -> V_154 , V_3 ) ;
}
fputs ( V_161 , V_3 ) ;
}
fputc ( '\n' , V_3 ) ;
}
static void F_102 ( T_25 * V_152 , T_8 V_170 , const T_11 * V_60 )
{
V_68 V_171 ;
T_17 * V_172 ;
if ( ( NULL == V_60 ) || ( '\0' == * V_60 ) )
return;
V_171 = F_103 ( V_170 ) - 1 ;
if ( V_152 -> V_158 [ V_171 ] == NULL ) {
V_152 -> V_158 [ V_171 ] = F_90 () ;
}
V_172 = V_152 -> V_158 [ V_171 ] ;
switch ( V_152 -> V_155 ) {
case 'f' :
if ( F_32 ( V_172 ) != 0 )
return;
break;
case 'l' :
F_104 ( V_172 , 0 ) ;
break;
case 'a' :
if ( F_32 ( V_172 ) > 0 ) {
F_92 ( V_172 , ( T_8 ) F_57 ( L_94 , V_152 -> V_156 ) ) ;
}
break;
default:
F_30 () ;
break;
}
F_92 ( V_172 , ( T_8 ) V_60 ) ;
}
static void F_105 ( T_7 * V_22 , T_8 V_7 )
{
T_27 * V_173 ;
T_9 * V_23 ;
T_8 V_170 ;
V_173 = ( T_27 * ) V_7 ;
V_23 = F_8 ( V_22 ) ;
F_9 ( V_23 ) ;
V_170 = F_16 ( V_173 -> V_152 -> V_157 , V_23 -> V_32 -> V_33 ) ;
if ( NULL != V_170 ) {
F_102 ( V_173 -> V_152 , V_170 ,
F_106 ( V_23 , V_173 -> V_5 )
) ;
}
if ( V_22 -> V_41 != NULL ) {
F_7 ( V_22 , F_105 ,
V_173 ) ;
}
}
void F_107 ( T_25 * V_152 , T_4 * V_5 , T_28 * V_93 , T_1 * V_3 )
{
T_26 V_51 ;
T_18 V_174 ;
T_11 * V_175 ;
T_8 V_170 ;
T_27 V_7 ;
F_9 ( V_152 ) ;
F_9 ( V_152 -> V_152 ) ;
F_9 ( V_5 ) ;
F_9 ( V_3 ) ;
V_7 . V_152 = V_152 ;
V_7 . V_5 = V_5 ;
if ( NULL == V_152 -> V_157 ) {
V_152 -> V_157 = F_108 ( V_176 , V_177 ) ;
V_51 = 0 ;
while ( V_51 < V_152 -> V_152 -> V_78 ) {
T_11 * V_161 = ( T_11 * ) F_88 ( V_152 -> V_152 , V_51 ) ;
++ V_51 ;
F_109 ( V_152 -> V_157 , V_161 , F_110 ( V_51 ) ) ;
}
}
if ( NULL == V_152 -> V_158 )
V_152 -> V_158 = F_111 ( T_17 * , V_152 -> V_152 -> V_78 ) ;
F_7 ( V_5 -> V_20 , F_105 ,
& V_7 ) ;
if ( V_152 -> V_160 ) {
for ( V_174 = 0 ; V_174 < V_93 -> V_94 ; V_174 ++ ) {
V_175 = F_112 ( L_95 , V_163 , V_93 -> V_95 [ V_174 ] ) ;
V_170 = F_16 ( V_152 -> V_157 , V_175 ) ;
if ( NULL != V_170 ) {
F_102 ( V_152 , V_170 , F_91 ( V_93 -> V_96 [ V_174 ] ) ) ;
}
}
}
for( V_51 = 0 ; V_51 < V_152 -> V_152 -> V_78 ; ++ V_51 ) {
if ( 0 != V_51 ) {
fputc ( V_152 -> V_154 , V_3 ) ;
}
if ( NULL != V_152 -> V_158 [ V_51 ] ) {
T_17 * V_172 ;
T_11 * V_102 ;
T_26 V_114 ;
V_172 = V_152 -> V_158 [ V_51 ] ;
if ( V_152 -> V_159 != '\0' ) {
fputc ( V_152 -> V_159 , V_3 ) ;
}
for ( V_114 = 0 ; V_114 < F_32 ( V_172 ) ; V_114 ++ ) {
V_102 = ( T_11 * ) F_88 ( V_172 , V_114 ) ;
fputs ( V_102 , V_3 ) ;
F_15 ( V_102 ) ;
}
if ( V_152 -> V_159 != '\0' ) {
fputc ( V_152 -> V_159 , V_3 ) ;
}
F_33 ( V_172 , TRUE ) ;
V_152 -> V_158 [ V_51 ] = NULL ;
}
}
}
void F_113 ( T_25 * V_152 V_97 , T_1 * V_3 V_97 )
{
}
T_11 * F_106 ( T_9 * V_23 , T_4 * V_5 )
{
if ( V_23 -> V_32 -> V_34 == V_54 ) {
if ( V_23 -> V_29 ) {
return F_91 ( V_23 -> V_29 -> V_30 ) ;
}
else {
return F_114 ( V_5 -> V_11 . V_12 , V_23 ) ;
}
}
else if ( V_23 -> V_32 -> V_34 == V_35 ) {
return F_114 ( V_5 -> V_11 . V_12 , V_23 ) ;
}
else {
T_11 * V_50 ;
switch ( V_23 -> V_32 -> type )
{
case V_53 :
if ( V_23 -> V_29 ) {
return F_91 ( V_23 -> V_29 -> V_30 ) ;
} else {
return F_91 ( V_23 -> V_32 -> V_33 ) ;
}
case V_59 :
return F_91 ( L_96 ) ;
default:
V_50 = F_26 ( & V_23 -> V_60 , V_61 , NULL ) ;
if ( V_50 != NULL ) {
return V_50 ;
} else {
return F_114 ( V_5 -> V_11 . V_12 , V_23 ) ;
}
}
}
}
static T_11 *
F_114 ( T_19 * V_10 , T_9 * V_23 )
{
const T_10 * V_25 ;
if ( ! V_23 -> V_117 )
return NULL ;
if ( V_23 -> V_36 > F_54 ( V_23 -> V_117 , V_23 -> V_57 ) ) {
return F_91 ( L_67 ) ;
}
V_25 = F_17 ( V_10 , V_23 ) ;
if ( V_25 ) {
int V_51 ;
T_11 * V_178 ;
T_11 * V_119 ;
int V_78 ;
const int V_179 = 2 ;
V_78 = V_179 * V_23 -> V_36 ;
V_178 = ( T_11 * ) F_69 ( sizeof( T_11 ) * ( V_78 + 1 ) ) ;
V_178 [ V_78 ] = '\0' ;
V_119 = V_178 ;
for ( V_51 = 0 ; V_51 < V_23 -> V_36 ; V_51 ++ ) {
F_55 ( V_119 , V_179 + 1 , L_68 , V_25 [ V_51 ] ) ;
V_119 += V_179 ;
}
return V_178 ;
} else {
return NULL ;
}
}
