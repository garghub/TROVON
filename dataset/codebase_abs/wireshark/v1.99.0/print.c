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
T_11 * V_83 ;
V_81 = F_31 ( V_20 , V_84 ) ;
if ( F_32 ( V_81 ) < 1 ) {
return;
}
V_82 = ( T_9 * ) V_81 -> V_24 [ 0 ] ;
F_33 ( V_81 , TRUE ) ;
V_81 = F_31 ( V_20 , V_85 ) ;
if ( F_32 ( V_81 ) < 1 ) {
return;
}
V_77 = F_28 ( & ( ( T_9 * ) V_81 -> V_24 [ 0 ] ) -> V_60 ) ;
F_33 ( V_81 , TRUE ) ;
V_81 = F_31 ( V_20 , V_86 ) ;
if ( F_32 ( V_81 ) < 1 ) {
return;
}
V_78 = F_28 ( & ( ( T_9 * ) V_81 -> V_24 [ 0 ] ) -> V_60 ) ;
F_33 ( V_81 , TRUE ) ;
V_81 = F_31 ( V_20 , V_87 ) ;
if ( F_32 ( V_81 ) < 1 ) {
return;
}
V_79 = F_28 ( & ( ( T_9 * ) V_81 -> V_24 [ 0 ] ) -> V_60 ) ;
F_33 ( V_81 , TRUE ) ;
V_81 = F_31 ( V_20 , V_88 ) ;
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
V_83 = F_35 ( NULL , V_80 , V_89 , TRUE ) ;
fprintf ( V_3 ,
L_40 ,
V_83 , ( int ) V_80 -> V_90 , V_80 -> V_91 , V_82 -> V_36 ) ;
F_36 ( NULL , V_83 ) ;
fprintf ( V_3 ,
L_41 ) ;
}
void
F_37 ( T_1 * V_3 )
{
fputs ( L_42 , V_3 ) ;
}
void
F_38 ( T_1 * V_3 )
{
fputs ( L_5 , V_3 ) ;
fputs ( L_43 V_92 L_12 , V_3 ) ;
fprintf ( V_3 , L_44 , V_47 , V_48 ) ;
V_93 = TRUE ;
}
void
F_39 ( T_4 * V_5 , T_1 * V_3 )
{
T_18 V_51 ;
if ( V_93 ) {
fprintf ( V_3 , L_45 ) ;
for ( V_51 = 0 ; V_51 < V_5 -> V_11 . V_94 -> V_95 ; V_51 ++ ) {
fprintf ( V_3 , L_46 ) ;
F_24 ( V_3 , V_5 -> V_11 . V_94 -> V_96 [ V_51 ] ) ;
fprintf ( V_3 , L_47 ) ;
}
fprintf ( V_3 , L_48 ) ;
V_93 = FALSE ;
}
fprintf ( V_3 , L_14 ) ;
for ( V_51 = 0 ; V_51 < V_5 -> V_11 . V_94 -> V_95 ; V_51 ++ ) {
fprintf ( V_3 , L_46 ) ;
F_24 ( V_3 , V_5 -> V_11 . V_94 -> V_97 [ V_51 ] ) ;
fprintf ( V_3 , L_47 ) ;
}
fprintf ( V_3 , L_15 ) ;
}
void
F_40 ( T_1 * V_3 )
{
fputs ( L_49 , V_3 ) ;
}
void
F_41 ( T_1 * V_3 V_98 )
{
V_93 = TRUE ;
}
static T_11 * F_42 ( const T_11 * V_99 , const T_11 * V_100 )
{
T_11 * V_101 ;
T_11 * V_102 ;
V_101 = F_43 ( V_99 , V_100 ) ;
V_102 = V_101 ;
while ( ( V_102 = strstr ( V_102 , L_50 ) ) != NULL ) {
V_102 [ 0 ] = ' ' ;
V_102 [ 1 ] = '>' ;
V_102 [ 2 ] = ' ' ;
}
V_102 = V_101 ;
while ( ( V_102 = strstr ( V_102 , L_51 ) ) != NULL )
* V_102 = '\"' ;
return V_101 ;
}
static void F_44 ( const char * V_103 , char V_104 , T_1 * V_3 )
{
T_11 * V_101 ;
V_101 = F_42 ( V_103 , L_50 ) ;
fprintf ( V_3 , L_52 , V_101 , V_104 ) ;
F_15 ( V_101 ) ;
}
void
F_45 ( T_4 * V_5 , T_1 * V_3 )
{
T_18 V_51 ;
if ( V_93 ) {
for ( V_51 = 0 ; V_51 < V_5 -> V_11 . V_94 -> V_95 - 1 ; V_51 ++ )
F_44 ( V_5 -> V_11 . V_94 -> V_96 [ V_51 ] , ',' , V_3 ) ;
F_44 ( V_5 -> V_11 . V_94 -> V_96 [ V_51 ] , '\n' , V_3 ) ;
V_93 = FALSE ;
}
for ( V_51 = 0 ; V_51 < V_5 -> V_11 . V_94 -> V_95 - 1 ; V_51 ++ )
F_44 ( V_5 -> V_11 . V_94 -> V_97 [ V_51 ] , ',' , V_3 ) ;
F_44 ( V_5 -> V_11 . V_94 -> V_97 [ V_51 ] , '\n' , V_3 ) ;
}
void
F_46 ( T_1 * V_3 V_98 )
{
}
void
F_47 ( T_1 * V_3 V_98 )
{
}
void
F_48 ( T_15 V_77 , T_1 * V_3 , T_4 * V_5 )
{
T_15 V_51 = 0 , V_105 = 0 ;
T_19 * V_106 ;
T_20 * V_107 ;
const char * V_108 ;
const T_21 * V_109 ;
V_68 V_36 ;
char V_110 [ 9 ] ;
struct V_111 * V_112 ;
for ( V_106 = V_5 -> V_11 . V_12 ; V_106 != NULL ; V_106 = V_106 -> V_113 ) {
memset ( V_110 , 0 , sizeof( V_110 ) ) ;
V_112 = (struct V_111 * ) V_106 -> V_7 ;
V_107 = F_49 ( V_112 ) ;
V_36 = F_50 ( V_107 ) ;
if ( V_36 == 0 )
continue;
V_109 = F_51 ( V_107 , 0 , V_36 ) ;
V_108 = F_52 ( V_112 ) ;
if ( V_108 )
fprintf ( V_3 , L_53 , V_108 ) ;
if ( V_105 ) {
fprintf ( V_3 , L_54 ,
V_77 , V_105 , V_36 ) ;
} else {
fprintf ( V_3 , L_55 ,
V_77 , V_36 ) ;
}
V_105 ++ ;
for ( V_51 = 0 ; V_51 < V_36 ; V_51 ++ ) {
fprintf ( V_3 , L_56 , * ( V_109 + V_51 ) ) ;
V_110 [ V_51 % 8 ] = F_53 ( * ( V_109 + V_51 ) ) ? * ( V_109 + V_51 ) : '.' ;
if ( V_51 == ( V_36 - 1 ) ) {
V_68 V_114 ;
V_114 = V_36 % 8 ;
if ( V_114 ) {
V_68 V_115 ;
for ( V_115 = 0 ; V_115 < 8 - V_114 ; V_115 ++ )
fprintf ( V_3 , L_57 ) ;
}
fprintf ( V_3 , L_58 , V_110 ) ;
break;
}
if ( ! ( ( V_51 + 1 ) % 8 ) ) {
fprintf ( V_3 , L_59 , V_110 ) ;
memset ( V_110 , 0 , sizeof( V_110 ) ) ;
}
else {
fprintf ( V_3 , L_60 ) ;
}
}
}
}
void
F_54 ( T_1 * V_3 V_98 )
{
}
static const T_10 *
F_17 ( T_19 * V_10 , T_9 * V_23 )
{
T_19 * V_106 ;
T_20 * V_116 ;
T_18 V_36 , V_117 ;
struct V_111 * V_112 ;
for ( V_106 = V_10 ; V_106 != NULL ; V_106 = V_106 -> V_113 ) {
V_112 = (struct V_111 * ) V_106 -> V_7 ;
V_116 = F_49 ( V_112 ) ;
if ( V_23 -> V_118 == V_116 ) {
V_117 = F_55 ( V_116 ,
V_23 -> V_57 ) ;
if ( V_117 < 0 ) {
return NULL ;
}
V_36 = V_23 -> V_36 ;
if ( V_36 > V_117 )
V_36 = V_117 ;
return F_51 ( V_116 , V_23 -> V_57 , V_36 ) ;
}
}
F_30 () ;
return NULL ;
}
static void
F_24 ( T_1 * V_3 , const char * V_119 )
{
const char * V_120 ;
char V_121 [ 8 ] ;
for ( V_120 = V_119 ; * V_120 != '\0' ; V_120 ++ ) {
switch ( * V_120 ) {
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
if ( F_53 ( * V_120 ) )
fputc ( * V_120 , V_3 ) ;
else {
F_56 ( V_121 , sizeof( V_121 ) , L_66 , ( T_10 ) * V_120 ) ;
fputs ( V_121 , V_3 ) ;
}
}
}
}
static void
F_25 ( T_13 * V_24 , T_9 * V_23 )
{
int V_51 ;
const T_10 * V_25 ;
if ( ! V_23 -> V_118 )
return;
if ( V_23 -> V_36 > F_55 ( V_23 -> V_118 , V_23 -> V_57 ) ) {
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
F_57 ( T_5 * V_6 , T_4 * V_5 )
{
T_2 V_122 ;
T_19 * V_106 ;
T_20 * V_107 ;
const char * V_108 ;
char * line ;
const T_21 * V_109 ;
V_68 V_36 ;
struct V_111 * V_112 ;
V_122 = ( V_5 -> V_11 . V_12 -> V_113 != NULL ) ;
for ( V_106 = V_5 -> V_11 . V_12 ; V_106 != NULL ;
V_106 = V_106 -> V_113 ) {
V_112 = (struct V_111 * ) V_106 -> V_7 ;
V_107 = F_49 ( V_112 ) ;
if ( V_122 ) {
V_108 = F_52 ( V_112 ) ;
line = F_58 ( L_69 , V_108 ) ;
F_14 ( V_6 , 0 , line ) ;
F_15 ( line ) ;
}
V_36 = F_50 ( V_107 ) ;
if ( V_36 == 0 )
return TRUE ;
V_109 = F_51 ( V_107 , 0 , V_36 ) ;
if ( ! F_18 ( V_6 , V_109 , V_36 ,
( V_14 ) V_5 -> V_11 . V_15 -> V_16 . V_13 ) )
return FALSE ;
}
return TRUE ;
}
static T_2
F_18 ( T_5 * V_6 , const T_21 * V_109 ,
V_68 V_36 , V_14 V_13 )
{
register unsigned int V_123 , V_51 , V_115 , V_124 , V_125 ;
T_21 V_126 ;
T_11 line [ V_127 + 1 ] ;
unsigned int V_128 ;
static T_11 V_129 [ 16 ] = {
'0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' ,
'8' , '9' , 'a' , 'b' , 'c' , 'd' , 'e' , 'f' } ;
if ( ( ( V_36 - 1 ) & 0xF0000000 ) != 0 )
V_128 = 8 ;
else if ( ( ( V_36 - 1 ) & 0x0F000000 ) != 0 )
V_128 = 7 ;
else if ( ( ( V_36 - 1 ) & 0x00F00000 ) != 0 )
V_128 = 6 ;
else if ( ( ( V_36 - 1 ) & 0x000F0000 ) != 0 )
V_128 = 5 ;
else
V_128 = 4 ;
V_123 = 0 ;
V_51 = 0 ;
V_115 = 0 ;
V_124 = 0 ;
while ( V_51 < V_36 ) {
if ( ( V_51 & 15 ) == 0 ) {
V_115 = 0 ;
V_125 = V_128 ;
do {
V_125 -- ;
V_126 = ( V_123 >> ( V_125 * 4 ) ) & 0xF ;
line [ V_115 ++ ] = V_129 [ V_126 ] ;
} while ( V_125 != 0 );
line [ V_115 ++ ] = ' ' ;
line [ V_115 ++ ] = ' ' ;
memset ( line + V_115 , ' ' , V_130 ) ;
V_124 = V_115 + V_131 + 2 ;
}
V_126 = * V_109 ++ ;
line [ V_115 ++ ] = V_129 [ V_126 >> 4 ] ;
line [ V_115 ++ ] = V_129 [ V_126 & 0xf ] ;
V_115 ++ ;
if ( V_13 == V_132 ) {
V_126 = F_59 ( V_126 ) ;
}
line [ V_124 ++ ] = ( ( V_126 >= ' ' ) && ( V_126 < 0x7f ) ) ? V_126 : '.' ;
V_51 ++ ;
if ( ( ( V_51 & 15 ) == 0 ) || ( V_51 == V_36 ) ) {
line [ V_124 ] = '\0' ;
if ( ! F_14 ( V_6 , 0 , line ) )
return FALSE ;
V_123 += 16 ;
}
}
return TRUE ;
}
static
void F_60 ( char * V_133 , const char * V_134 , int V_135 )
{
int V_136 , V_137 ;
char V_126 ;
if ( V_134 == NULL ) {
V_133 [ 0 ] = '\0' ;
return;
}
for ( V_136 = 0 , V_137 = 0 ; V_137 < V_135 ; V_136 ++ , V_137 ++ ) {
V_126 = V_134 [ V_136 ] ;
switch ( V_126 ) {
case '(' :
case ')' :
case '\\' :
V_133 [ V_137 ] = '\\' ;
V_133 [ ++ V_137 ] = V_126 ;
break;
default:
V_133 [ V_137 ] = V_126 ;
break;
}
if ( V_126 == 0 ) {
break;
}
}
}
T_2
F_61 ( T_5 * V_138 , T_11 * V_42 , const char * V_139 )
{
return V_138 -> V_140 -> F_61 ? ( V_138 -> V_140 -> F_61 ) ( V_138 , V_42 , V_139 ) : TRUE ;
}
T_2
F_14 ( T_5 * V_138 , int V_141 , const char * line )
{
return ( V_138 -> V_140 -> F_14 ) ( V_138 , V_141 , line ) ;
}
T_2
F_62 ( T_5 * V_138 , const T_11 * V_108 , const T_11 * V_142 )
{
return V_138 -> V_140 -> F_62 ? ( V_138 -> V_140 -> F_62 ) ( V_138 , V_108 , V_142 ) : TRUE ;
}
T_2
F_63 ( T_5 * V_138 )
{
return V_138 -> V_140 -> F_63 ? ( V_138 -> V_140 -> F_63 ) ( V_138 ) : TRUE ;
}
T_2
F_64 ( T_5 * V_138 )
{
return V_138 -> V_140 -> F_64 ? ( V_138 -> V_140 -> F_64 ) ( V_138 ) : TRUE ;
}
T_2
F_65 ( T_5 * V_138 )
{
return V_138 -> V_140 -> V_143 ? ( V_138 -> V_140 -> V_143 ) ( V_138 ) : TRUE ;
}
static T_2
F_66 ( T_5 * V_138 , int V_141 , const char * line )
{
static char V_144 [ V_145 ] ;
T_22 V_146 ;
T_23 * V_147 = ( T_23 * ) V_138 -> V_7 ;
unsigned int V_148 ;
if ( ! V_144 [ 0 ] ) {
int V_51 ;
for ( V_51 = 0 ; V_51 < V_145 ; V_51 ++ )
V_144 [ V_51 ] = ' ' ;
}
V_148 = V_141 * 4 ;
if ( V_148 > V_145 )
V_148 = V_145 ;
V_146 = fwrite ( V_144 , 1 , V_148 , V_147 -> V_3 ) ;
if ( V_146 == V_148 ) {
fputs ( line , V_147 -> V_3 ) ;
putc ( '\n' , V_147 -> V_3 ) ;
}
return ! ferror ( V_147 -> V_3 ) ;
}
static T_2
F_67 ( T_5 * V_138 )
{
T_23 * V_147 = ( T_23 * ) V_138 -> V_7 ;
fputs ( L_70 , V_147 -> V_3 ) ;
return ! ferror ( V_147 -> V_3 ) ;
}
static T_2
F_68 ( T_5 * V_138 )
{
T_23 * V_147 = ( T_23 * ) V_138 -> V_7 ;
T_2 V_146 ;
V_146 = F_4 ( V_147 -> V_1 , V_147 -> V_3 ) ;
F_15 ( V_147 ) ;
F_15 ( V_138 ) ;
return V_146 ;
}
static T_5 *
F_69 ( T_2 V_1 , T_1 * V_3 )
{
T_5 * V_6 ;
T_23 * V_147 ;
V_147 = ( T_23 * ) F_70 ( sizeof *V_147 ) ;
V_147 -> V_1 = V_1 ;
V_147 -> V_3 = V_3 ;
V_6 = ( T_5 * ) F_70 ( sizeof ( T_5 ) ) ;
V_6 -> V_140 = & V_149 ;
V_6 -> V_7 = V_147 ;
return V_6 ;
}
T_5 *
F_71 ( T_2 V_1 , const char * V_2 )
{
T_1 * V_3 ;
V_3 = F_1 ( V_1 , V_2 ) ;
if ( V_3 == NULL )
return NULL ;
return F_69 ( V_1 , V_3 ) ;
}
T_5 *
F_72 ( T_1 * V_3 )
{
return F_69 ( TRUE , V_3 ) ;
}
static T_2
F_73 ( T_5 * V_138 , T_11 * V_42 , const char * V_139 )
{
T_24 * V_147 = ( T_24 * ) V_138 -> V_7 ;
char V_150 [ V_151 ] ;
F_74 ( V_147 -> V_3 ) ;
fputs ( L_71 , V_147 -> V_3 ) ;
F_60 ( V_150 , V_42 , V_151 ) ;
fprintf ( V_147 -> V_3 , L_72 , V_150 , V_139 ) ;
fputs ( L_73 , V_147 -> V_3 ) ;
return ! ferror ( V_147 -> V_3 ) ;
}
static T_2
F_75 ( T_5 * V_138 , int V_141 , const char * line )
{
T_24 * V_147 = ( T_24 * ) V_138 -> V_7 ;
char V_150 [ V_151 ] ;
F_60 ( V_150 , line , V_151 ) ;
fprintf ( V_147 -> V_3 , L_74 , V_141 , V_150 ) ;
return ! ferror ( V_147 -> V_3 ) ;
}
static T_2
F_76 ( T_5 * V_138 , const T_11 * V_108 , const T_11 * V_142 )
{
T_24 * V_147 = ( T_24 * ) V_138 -> V_7 ;
char V_150 [ V_151 ] ;
F_60 ( V_150 , V_142 , V_151 ) ;
fprintf ( V_147 -> V_3 , L_75 , V_108 ,
V_150 ) ;
fputs ( L_76 ,
V_147 -> V_3 ) ;
fputs ( L_77 ,
V_147 -> V_3 ) ;
fprintf ( V_147 -> V_3 , L_78 , V_108 ) ;
return ! ferror ( V_147 -> V_3 ) ;
}
static T_2
F_77 ( T_5 * V_138 )
{
T_24 * V_147 = ( T_24 * ) V_138 -> V_7 ;
fputs ( L_79 , V_147 -> V_3 ) ;
return ! ferror ( V_147 -> V_3 ) ;
}
static T_2
F_78 ( T_5 * V_138 )
{
T_24 * V_147 = ( T_24 * ) V_138 -> V_7 ;
F_79 ( V_147 -> V_3 ) ;
return ! ferror ( V_147 -> V_3 ) ;
}
static T_2
F_80 ( T_5 * V_138 )
{
T_24 * V_147 = ( T_24 * ) V_138 -> V_7 ;
T_2 V_146 ;
V_146 = F_4 ( V_147 -> V_1 , V_147 -> V_3 ) ;
F_15 ( V_147 ) ;
F_15 ( V_138 ) ;
return V_146 ;
}
static T_5 *
F_81 ( T_2 V_1 , T_1 * V_3 )
{
T_5 * V_6 ;
T_24 * V_147 ;
V_147 = ( T_24 * ) F_70 ( sizeof *V_147 ) ;
V_147 -> V_1 = V_1 ;
V_147 -> V_3 = V_3 ;
V_6 = ( T_5 * ) F_70 ( sizeof ( T_5 ) ) ;
V_6 -> V_140 = & V_152 ;
V_6 -> V_7 = V_147 ;
return V_6 ;
}
T_5 *
F_82 ( T_2 V_1 , const char * V_2 )
{
T_1 * V_3 ;
V_3 = F_1 ( V_1 , V_2 ) ;
if ( V_3 == NULL )
return NULL ;
return F_81 ( V_1 , V_3 ) ;
}
T_5 *
F_83 ( T_1 * V_3 )
{
return F_81 ( TRUE , V_3 ) ;
}
T_25 * F_84 ( void )
{
T_25 * V_153 = F_85 ( T_25 , 1 ) ;
V_153 -> V_154 = FALSE ;
V_153 -> V_155 = '\t' ;
V_153 -> V_156 = 'a' ;
V_153 -> V_157 = ',' ;
V_153 -> V_153 = NULL ;
V_153 -> V_158 = NULL ;
V_153 -> V_159 = NULL ;
V_153 -> V_160 = '\0' ;
V_153 -> V_161 = FALSE ;
return V_153 ;
}
T_26 F_86 ( T_25 * V_153 )
{
F_9 ( V_153 ) ;
if ( NULL == V_153 -> V_153 ) {
return 0 ;
} else {
return V_153 -> V_153 -> V_78 ;
}
}
void F_87 ( T_25 * V_153 )
{
F_9 ( V_153 ) ;
if ( NULL != V_153 -> V_153 ) {
T_26 V_51 ;
if ( NULL != V_153 -> V_158 ) {
F_88 ( V_153 -> V_158 ) ;
}
if ( NULL != V_153 -> V_159 ) {
F_15 ( V_153 -> V_159 ) ;
}
for( V_51 = 0 ; V_51 < V_153 -> V_153 -> V_78 ; ++ V_51 ) {
T_11 * V_162 = ( T_11 * ) F_89 ( V_153 -> V_153 , V_51 ) ;
F_15 ( V_162 ) ;
}
F_33 ( V_153 -> V_153 , TRUE ) ;
}
F_15 ( V_153 ) ;
}
void F_90 ( T_25 * V_153 , const T_11 * V_162 )
{
T_11 * V_163 ;
F_9 ( V_153 ) ;
F_9 ( V_162 ) ;
if ( NULL == V_153 -> V_153 ) {
V_153 -> V_153 = F_91 () ;
}
V_163 = F_92 ( V_162 ) ;
F_93 ( V_153 -> V_153 , V_163 ) ;
if ( ! strncmp ( V_162 , V_164 , strlen ( V_164 ) ) )
V_153 -> V_161 = TRUE ;
}
static void
F_94 ( void * V_7 , void * V_165 )
{
T_11 * V_162 = ( T_11 * ) V_7 ;
T_2 * V_166 = ( T_2 * ) V_165 ;
if ( ! strncmp ( V_162 , V_164 , strlen ( V_164 ) ) )
return;
if ( ! F_95 ( V_162 ) ) {
F_96 ( L_80 , V_162 ) ;
* V_166 = FALSE ;
}
}
T_2
F_97 ( T_25 * V_153 )
{
T_2 V_166 = TRUE ;
if ( V_153 -> V_153 == NULL ) {
return TRUE ;
}
F_98 ( V_153 -> V_153 , F_94 , & V_166 ) ;
return V_166 ;
}
T_2 F_99 ( T_25 * V_167 , T_11 * V_168 )
{
const T_11 * V_169 ;
const T_11 * V_170 ;
F_9 ( V_167 ) ;
F_9 ( V_168 ) ;
if ( '\0' == * V_168 ) {
return FALSE ;
}
V_169 = strtok ( V_168 , L_81 ) ;
if ( ! V_169 ) {
return FALSE ;
}
V_170 = V_168 + strlen ( V_169 ) + 1 ;
if ( 0 == strcmp ( V_169 , L_82 ) ) {
switch ( NULL == V_170 ? '\0' : * V_170 ) {
case 'n' :
V_167 -> V_154 = FALSE ;
break;
case 'y' :
V_167 -> V_154 = TRUE ;
break;
default:
return FALSE ;
}
return TRUE ;
}
if ( 0 == strcmp ( V_169 , L_83 ) ) {
switch ( NULL == V_170 ? '\0' : * V_170 ) {
case '\0' :
return FALSE ;
case '/' :
switch ( * ++ V_170 ) {
case 't' :
V_167 -> V_155 = '\t' ;
break;
case 's' :
V_167 -> V_155 = ' ' ;
break;
default:
V_167 -> V_155 = '\\' ;
}
break;
default:
V_167 -> V_155 = * V_170 ;
break;
}
return TRUE ;
}
if ( 0 == strcmp ( V_169 , L_84 ) ) {
switch ( NULL == V_170 ? '\0' : * V_170 ) {
case 'f' :
case 'l' :
case 'a' :
V_167 -> V_156 = * V_170 ;
break;
default:
return FALSE ;
}
return TRUE ;
}
if ( 0 == strcmp ( V_169 , L_85 ) ) {
switch ( NULL == V_170 ? '\0' : * V_170 ) {
case '\0' :
return FALSE ;
case '/' :
switch ( * ++ V_170 ) {
case 's' :
V_167 -> V_157 = ' ' ;
break;
default:
V_167 -> V_157 = '\\' ;
}
break;
default:
V_167 -> V_157 = * V_170 ;
break;
}
return TRUE ;
}
if ( 0 == strcmp ( V_169 , L_86 ) ) {
switch ( NULL == V_170 ? '\0' : * V_170 ) {
default:
case '\0' :
V_167 -> V_160 = '\0' ;
return FALSE ;
case 'd' :
V_167 -> V_160 = '"' ;
break;
case 's' :
V_167 -> V_160 = '\'' ;
break;
case 'n' :
V_167 -> V_160 = '\0' ;
break;
}
return TRUE ;
}
return FALSE ;
}
void F_100 ( T_1 * V_3 )
{
fprintf ( V_3 , L_87 ) ;
fputs ( L_88 , V_3 ) ;
fputs ( L_89 , V_3 ) ;
fputs ( L_90 , V_3 ) ;
fputs ( L_91 , V_3 ) ;
fputs ( L_92 , V_3 ) ;
}
T_2 F_101 ( T_25 * V_153 )
{
F_9 ( V_153 ) ;
return V_153 -> V_161 ;
}
void F_102 ( T_25 * V_153 , T_1 * V_3 )
{
T_26 V_51 ;
F_9 ( V_153 ) ;
F_9 ( V_3 ) ;
F_9 ( V_153 -> V_153 ) ;
if ( ! V_153 -> V_154 ) {
return;
}
for( V_51 = 0 ; V_51 < V_153 -> V_153 -> V_78 ; ++ V_51 ) {
const T_11 * V_162 = ( const T_11 * ) F_89 ( V_153 -> V_153 , V_51 ) ;
if ( V_51 != 0 ) {
fputc ( V_153 -> V_155 , V_3 ) ;
}
fputs ( V_162 , V_3 ) ;
}
fputc ( '\n' , V_3 ) ;
}
static void F_103 ( T_25 * V_153 , T_8 V_171 , const T_11 * V_60 )
{
V_68 V_172 ;
T_17 * V_173 ;
if ( ( NULL == V_60 ) || ( '\0' == * V_60 ) )
return;
V_172 = F_104 ( V_171 ) - 1 ;
if ( V_153 -> V_159 [ V_172 ] == NULL ) {
V_153 -> V_159 [ V_172 ] = F_91 () ;
}
V_173 = V_153 -> V_159 [ V_172 ] ;
switch ( V_153 -> V_156 ) {
case 'f' :
if ( F_32 ( V_173 ) != 0 )
return;
break;
case 'l' :
F_105 ( V_173 , 0 ) ;
break;
case 'a' :
if ( F_32 ( V_173 ) > 0 ) {
F_93 ( V_173 , ( T_8 ) F_58 ( L_93 , V_153 -> V_157 ) ) ;
}
break;
default:
F_30 () ;
break;
}
F_93 ( V_173 , ( T_8 ) V_60 ) ;
}
static void F_106 ( T_7 * V_22 , T_8 V_7 )
{
T_27 * V_174 ;
T_9 * V_23 ;
T_8 V_171 ;
V_174 = ( T_27 * ) V_7 ;
V_23 = F_8 ( V_22 ) ;
F_9 ( V_23 ) ;
V_171 = F_16 ( V_174 -> V_153 -> V_158 , V_23 -> V_32 -> V_33 ) ;
if ( NULL != V_171 ) {
F_103 ( V_174 -> V_153 , V_171 ,
F_107 ( V_23 , V_174 -> V_5 )
) ;
}
if ( V_22 -> V_41 != NULL ) {
F_7 ( V_22 , F_106 ,
V_174 ) ;
}
}
void F_108 ( T_25 * V_153 , T_4 * V_5 , T_28 * V_94 , T_1 * V_3 )
{
T_26 V_51 ;
T_18 V_175 ;
T_11 * V_176 ;
T_8 V_171 ;
T_27 V_7 ;
F_9 ( V_153 ) ;
F_9 ( V_153 -> V_153 ) ;
F_9 ( V_5 ) ;
F_9 ( V_3 ) ;
V_7 . V_153 = V_153 ;
V_7 . V_5 = V_5 ;
if ( NULL == V_153 -> V_158 ) {
V_153 -> V_158 = F_109 ( V_177 , V_178 ) ;
V_51 = 0 ;
while ( V_51 < V_153 -> V_153 -> V_78 ) {
T_11 * V_162 = ( T_11 * ) F_89 ( V_153 -> V_153 , V_51 ) ;
++ V_51 ;
F_110 ( V_153 -> V_158 , V_162 , F_111 ( V_51 ) ) ;
}
}
if ( NULL == V_153 -> V_159 )
V_153 -> V_159 = F_112 ( T_17 * , V_153 -> V_153 -> V_78 ) ;
F_7 ( V_5 -> V_20 , F_106 ,
& V_7 ) ;
if ( V_153 -> V_161 ) {
for ( V_175 = 0 ; V_175 < V_94 -> V_95 ; V_175 ++ ) {
V_176 = F_113 ( L_94 , V_164 , V_94 -> V_96 [ V_175 ] ) ;
V_171 = F_16 ( V_153 -> V_158 , V_176 ) ;
if ( NULL != V_171 ) {
F_103 ( V_153 , V_171 , F_92 ( V_94 -> V_97 [ V_175 ] ) ) ;
}
}
}
for( V_51 = 0 ; V_51 < V_153 -> V_153 -> V_78 ; ++ V_51 ) {
if ( 0 != V_51 ) {
fputc ( V_153 -> V_155 , V_3 ) ;
}
if ( NULL != V_153 -> V_159 [ V_51 ] ) {
T_17 * V_173 ;
T_11 * V_103 ;
T_26 V_115 ;
V_173 = V_153 -> V_159 [ V_51 ] ;
if ( V_153 -> V_160 != '\0' ) {
fputc ( V_153 -> V_160 , V_3 ) ;
}
for ( V_115 = 0 ; V_115 < F_32 ( V_173 ) ; V_115 ++ ) {
V_103 = ( T_11 * ) F_89 ( V_173 , V_115 ) ;
fputs ( V_103 , V_3 ) ;
F_15 ( V_103 ) ;
}
if ( V_153 -> V_160 != '\0' ) {
fputc ( V_153 -> V_160 , V_3 ) ;
}
F_33 ( V_173 , TRUE ) ;
V_153 -> V_159 [ V_51 ] = NULL ;
}
}
}
void F_114 ( T_25 * V_153 V_98 , T_1 * V_3 V_98 )
{
}
T_11 * F_107 ( T_9 * V_23 , T_4 * V_5 )
{
if ( V_23 -> V_32 -> V_34 == V_54 ) {
if ( V_23 -> V_29 ) {
return F_92 ( V_23 -> V_29 -> V_30 ) ;
}
else {
return F_115 ( V_5 -> V_11 . V_12 , V_23 ) ;
}
}
else if ( V_23 -> V_32 -> V_34 == V_35 ) {
return F_115 ( V_5 -> V_11 . V_12 , V_23 ) ;
}
else {
T_11 * V_50 ;
switch ( V_23 -> V_32 -> type )
{
case V_53 :
if ( V_23 -> V_29 ) {
return F_92 ( V_23 -> V_29 -> V_30 ) ;
} else {
return F_92 ( V_23 -> V_32 -> V_33 ) ;
}
case V_59 :
return F_92 ( L_95 ) ;
default:
V_50 = F_26 ( & V_23 -> V_60 , V_61 , NULL ) ;
if ( V_50 != NULL ) {
return V_50 ;
} else {
return F_115 ( V_5 -> V_11 . V_12 , V_23 ) ;
}
}
}
}
static T_11 *
F_115 ( T_19 * V_10 , T_9 * V_23 )
{
const T_10 * V_25 ;
if ( ! V_23 -> V_118 )
return NULL ;
if ( V_23 -> V_36 > F_55 ( V_23 -> V_118 , V_23 -> V_57 ) ) {
return F_92 ( L_67 ) ;
}
V_25 = F_17 ( V_10 , V_23 ) ;
if ( V_25 ) {
int V_51 ;
T_11 * V_179 ;
T_11 * V_120 ;
int V_78 ;
const int V_180 = 2 ;
V_78 = V_180 * V_23 -> V_36 ;
V_179 = ( T_11 * ) F_70 ( sizeof( T_11 ) * ( V_78 + 1 ) ) ;
V_179 [ V_78 ] = '\0' ;
V_120 = V_179 ;
for ( V_51 = 0 ; V_51 < V_23 -> V_36 ; V_51 ++ ) {
F_56 ( V_120 , V_180 + 1 , L_68 , V_25 [ V_51 ] ) ;
V_120 += V_180 ;
}
return V_179 ;
} else {
return NULL ;
}
}
