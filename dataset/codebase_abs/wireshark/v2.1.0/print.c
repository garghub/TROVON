void F_1 ( void )
{
V_1 = F_2 ( L_1 ) ;
V_2 = F_2 ( L_2 ) ;
V_3 = F_3 ( L_3 ) ;
V_4 = F_3 ( L_4 ) ;
V_5 = F_3 ( L_5 ) ;
V_6 = F_3 ( L_6 ) ;
}
T_1
F_4 ( T_2 * V_7 , T_3 * V_8 ,
T_4 * V_9 , T_5 * V_10 )
{
T_6 V_11 ;
V_11 . V_12 = 0 ;
V_11 . V_10 = V_10 ;
V_11 . V_13 = TRUE ;
V_11 . V_14 = V_8 -> V_15 . V_16 ;
V_11 . V_17 = ( V_18 ) V_8 -> V_15 . V_19 -> V_20 . V_17 ;
V_11 . V_21 = V_7 -> V_21 ;
V_11 . V_22 = ! V_7 -> V_23 ;
V_11 . V_8 = V_8 ;
V_11 . V_9 = V_9 ;
F_5 ( V_8 -> V_24 , V_25 , & V_11 ) ;
return V_11 . V_13 ;
}
static void
V_25 ( T_7 * V_26 , T_8 V_11 )
{
T_9 * V_27 = F_6 ( V_26 ) ;
T_6 * V_28 = ( T_6 * ) V_11 ;
const T_10 * V_29 ;
T_11 V_30 [ V_31 ] ;
T_11 * V_32 ;
F_7 ( V_27 ) ;
if ( F_8 ( V_26 ) )
return;
if ( ! V_28 -> V_13 )
return;
if ( V_27 -> V_33 ) {
V_32 = V_27 -> V_33 -> V_34 ;
}
else {
V_32 = V_30 ;
F_9 ( V_27 , V_30 ) ;
}
if ( F_10 ( V_26 ) )
V_32 = F_11 ( L_7 , V_32 , L_8 , NULL ) ;
V_28 -> V_13 = F_12 ( V_28 -> V_10 , V_28 -> V_12 , V_32 ) ;
if ( F_10 ( V_26 ) )
F_13 ( V_32 ) ;
if ( ! V_28 -> V_13 )
return;
if ( ( V_28 -> V_9 != NULL ) && ( V_28 -> V_12 == 0 )
&& ( F_14 ( V_28 -> V_9 , V_27 -> V_35 -> V_36 ) == NULL ) ) {
return;
}
if ( ( V_27 -> V_35 -> V_37 == V_1 ) && ( V_28 -> V_22 ) ) {
V_29 = F_15 ( V_28 -> V_14 , V_27 ) ;
if ( V_29 ) {
if ( ! F_12 ( V_28 -> V_10 , 0 , L_9 ) ) {
V_28 -> V_13 = FALSE ;
return;
}
if ( ! F_16 ( V_28 -> V_10 , V_29 ,
V_27 -> V_38 , V_28 -> V_17 ) ) {
V_28 -> V_13 = FALSE ;
return;
}
}
}
F_7 ( ( V_27 -> V_39 >= - 1 ) && ( V_27 -> V_39 < V_40 ) ) ;
if ( ( V_28 -> V_21 == V_41 ) ||
( ( V_28 -> V_21 == V_42 ) &&
( V_27 -> V_39 >= 0 ) && F_17 ( V_27 -> V_39 ) ) ) {
if ( V_26 -> V_43 != NULL ) {
V_28 -> V_12 ++ ;
F_5 ( V_26 ,
V_25 , V_28 ) ;
V_28 -> V_12 -- ;
if ( ! V_28 -> V_13 )
return;
}
}
}
void
F_18 ( T_12 * V_44 , const T_11 * V_45 )
{
T_13 V_46 = time ( NULL ) ;
char * V_47 = asctime ( localtime ( & V_46 ) ) ;
V_47 [ strlen ( V_47 ) - 1 ] = 0 ;
fputs ( L_10 , V_44 ) ;
fputs ( L_11 V_48 L_12 , V_44 ) ;
fprintf ( V_44 , L_13 V_48 L_14 V_48 L_15 , F_19 () ) ;
fputs ( L_16 V_49 L_17 , V_44 ) ;
fprintf ( V_44 , L_18 , V_50 , V_51 , V_47 , V_45 ? V_45 : L_9 ) ;
}
void
F_20 ( T_3 * V_8 , T_12 * V_44 )
{
T_14 V_11 ;
V_11 . V_12 = 0 ;
V_11 . V_44 = V_44 ;
V_11 . V_14 = V_8 -> V_15 . V_16 ;
V_11 . V_8 = V_8 ;
fprintf ( V_44 , L_19 ) ;
F_21 ( V_8 -> V_24 , V_44 ) ;
F_5 ( V_8 -> V_24 , V_52 ,
& V_11 ) ;
fprintf ( V_44 , L_20 ) ;
}
static void
V_52 ( T_7 * V_26 , T_8 V_11 )
{
T_9 * V_27 = F_6 ( V_26 ) ;
T_14 * V_28 = ( T_14 * ) V_11 ;
const T_11 * V_32 ;
T_11 V_30 [ V_31 ] ;
char * V_53 ;
int V_54 ;
T_1 V_55 ;
F_7 ( V_27 ) ;
V_55 =
( ( ( V_27 -> V_35 -> type != V_56 ) ||
( V_27 -> V_35 -> V_37 == V_1 ) ) &&
( V_28 -> V_12 == 0 ) ) ;
for ( V_54 = - 1 ; V_54 < V_28 -> V_12 ; V_54 ++ ) {
fputs ( L_21 , V_28 -> V_44 ) ;
}
if ( V_55 ) {
fputs ( L_22 , V_28 -> V_44 ) ;
V_28 -> V_12 ++ ;
for ( V_54 = - 1 ; V_54 < V_28 -> V_12 ; V_54 ++ ) {
fputs ( L_21 , V_28 -> V_44 ) ;
}
}
if ( V_27 -> V_35 -> V_37 == V_57 ) {
if ( V_27 -> V_33 ) {
V_32 = V_27 -> V_33 -> V_34 ;
}
else {
V_32 = L_9 ;
}
fputs ( L_23 , V_28 -> V_44 ) ;
fputs ( L_24 , V_28 -> V_44 ) ;
F_22 ( V_28 -> V_44 , V_32 ) ;
fprintf ( V_28 -> V_44 , L_25 , V_27 -> V_38 ) ;
if ( V_26 -> V_58 && V_26 -> V_58 -> V_59 && ( V_27 -> V_60 < V_26 -> V_58 -> V_59 -> V_60 ) ) {
fprintf ( V_28 -> V_44 , L_26 , V_26 -> V_58 -> V_59 -> V_60 + V_27 -> V_60 ) ;
} else {
fprintf ( V_28 -> V_44 , L_26 , V_27 -> V_60 ) ;
}
if ( V_27 -> V_38 > 0 ) {
fputs ( L_27 , V_28 -> V_44 ) ;
F_23 ( V_28 , V_27 ) ;
}
if ( V_26 -> V_43 != NULL ) {
fputs ( L_28 , V_28 -> V_44 ) ;
}
else {
fputs ( L_29 , V_28 -> V_44 ) ;
}
}
else if ( V_27 -> V_35 -> V_37 == V_1 ) {
fputs ( L_30 , V_28 -> V_44 ) ;
F_23 ( V_28 , V_27 ) ;
fputs ( L_28 , V_28 -> V_44 ) ;
}
else {
if ( ( V_27 -> V_35 -> type == V_56 ) && ( V_27 -> V_35 -> V_37 != V_61 ) ) {
fputs ( L_31 , V_28 -> V_44 ) ;
}
else {
fputs ( L_23 , V_28 -> V_44 ) ;
}
F_22 ( V_28 -> V_44 , V_27 -> V_35 -> V_36 ) ;
#if 0
fputs("\" showname=\"", pdata->fh);
print_escaped_xml(pdata->fh, fi->hfinfo->name);
#endif
if ( V_27 -> V_33 ) {
fputs ( L_32 , V_28 -> V_44 ) ;
F_22 ( V_28 -> V_44 , V_27 -> V_33 -> V_34 ) ;
}
else {
V_32 = V_30 ;
F_9 ( V_27 , V_30 ) ;
fputs ( L_32 , V_28 -> V_44 ) ;
F_22 ( V_28 -> V_44 , V_32 ) ;
}
if ( F_8 ( V_26 ) )
fprintf ( V_28 -> V_44 , L_33 ) ;
fprintf ( V_28 -> V_44 , L_25 , V_27 -> V_38 ) ;
if ( V_26 -> V_58 && V_26 -> V_58 -> V_59 && ( V_27 -> V_60 < V_26 -> V_58 -> V_59 -> V_60 ) ) {
fprintf ( V_28 -> V_44 , L_26 , V_26 -> V_58 -> V_59 -> V_60 + V_27 -> V_60 ) ;
} else {
fprintf ( V_28 -> V_44 , L_26 , V_27 -> V_60 ) ;
}
switch ( V_27 -> V_35 -> type )
{
case V_56 :
break;
case V_62 :
fputs ( L_34 , V_28 -> V_44 ) ;
break;
default:
V_53 = F_24 ( NULL , & V_27 -> V_63 , V_64 , V_27 -> V_35 -> V_65 ) ;
if ( V_53 != NULL ) {
fputs ( L_24 , V_28 -> V_44 ) ;
F_22 ( V_28 -> V_44 , V_53 ) ;
}
F_25 ( NULL , V_53 ) ;
if ( V_27 -> V_38 > 0 ) {
fputs ( L_27 , V_28 -> V_44 ) ;
if ( V_27 -> V_35 -> V_66 != 0 ) {
switch ( V_27 -> V_63 . V_67 -> V_67 ) {
case V_68 :
case V_69 :
case V_70 :
case V_71 :
fprintf ( V_28 -> V_44 , L_35 , ( V_72 ) F_26 ( & V_27 -> V_63 ) ) ;
break;
case V_73 :
case V_74 :
case V_75 :
case V_76 :
fprintf ( V_28 -> V_44 , L_35 , F_27 ( & V_27 -> V_63 ) ) ;
break;
case V_77 :
case V_78 :
case V_79 :
case V_80 :
fprintf ( V_28 -> V_44 , L_36 V_81 L_37 , F_28 ( & V_27 -> V_63 ) ) ;
break;
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_86 :
fprintf ( V_28 -> V_44 , L_36 V_81 L_37 , F_29 ( & V_27 -> V_63 ) ) ;
break;
default:
F_30 () ;
}
fputs ( L_38 , V_28 -> V_44 ) ;
F_23 ( V_28 , V_27 ) ;
}
else {
F_23 ( V_28 , V_27 ) ;
}
}
}
if ( V_26 -> V_43 != NULL ) {
fputs ( L_28 , V_28 -> V_44 ) ;
}
else if ( V_27 -> V_35 -> V_37 == V_1 ) {
fputs ( L_28 , V_28 -> V_44 ) ;
}
else {
fputs ( L_29 , V_28 -> V_44 ) ;
}
}
if ( V_26 -> V_43 != NULL ) {
V_28 -> V_12 ++ ;
F_5 ( V_26 ,
V_52 , V_28 ) ;
V_28 -> V_12 -- ;
}
if ( V_55 ) {
V_28 -> V_12 -- ;
}
if ( V_26 -> V_43 != NULL ) {
for ( V_54 = - 1 ; V_54 < V_28 -> V_12 ; V_54 ++ ) {
fputs ( L_21 , V_28 -> V_44 ) ;
}
if ( ( V_27 -> V_35 -> V_37 != V_1 ) && ( V_27 -> V_35 -> V_37 != V_61 ) ) {
if ( V_27 -> V_35 -> type == V_56 ) {
fputs ( L_39 , V_28 -> V_44 ) ;
}
else {
fputs ( L_40 , V_28 -> V_44 ) ;
}
} else {
fputs ( L_40 , V_28 -> V_44 ) ;
}
}
if ( V_55 ) {
fputs ( L_39 , V_28 -> V_44 ) ;
}
}
static void
F_21 ( T_15 * V_24 , T_12 * V_44 )
{
T_16 V_87 , V_88 , V_89 ;
T_17 * V_90 ;
T_18 * V_91 ;
T_9 * V_92 ;
T_11 * V_93 ;
V_91 = F_31 ( V_24 , V_2 ) ;
if ( F_32 ( V_91 ) < 1 ) {
return;
}
V_92 = ( T_9 * ) V_91 -> V_28 [ 0 ] ;
F_33 ( V_91 , TRUE ) ;
V_91 = F_31 ( V_24 , V_4 ) ;
if ( F_32 ( V_91 ) < 1 ) {
return;
}
V_87 = F_27 ( & ( ( T_9 * ) V_91 -> V_28 [ 0 ] ) -> V_63 ) ;
F_33 ( V_91 , TRUE ) ;
V_91 = F_31 ( V_24 , V_5 ) ;
if ( F_32 ( V_91 ) < 1 ) {
return;
}
V_88 = F_27 ( & ( ( T_9 * ) V_91 -> V_28 [ 0 ] ) -> V_63 ) ;
F_33 ( V_91 , TRUE ) ;
V_91 = F_31 ( V_24 , V_6 ) ;
if ( F_32 ( V_91 ) < 1 ) {
return;
}
V_89 = F_27 ( & ( ( T_9 * ) V_91 -> V_28 [ 0 ] ) -> V_63 ) ;
F_33 ( V_91 , TRUE ) ;
V_91 = F_31 ( V_24 , V_3 ) ;
if ( F_32 ( V_91 ) < 1 ) {
return;
}
V_90 = ( T_17 * ) F_34 ( & ( ( T_9 * ) V_91 -> V_28 [ 0 ] ) -> V_63 ) ;
F_33 ( V_91 , TRUE ) ;
fprintf ( V_44 ,
L_41 ,
V_92 -> V_38 ) ;
fprintf ( V_44 ,
L_42 ,
V_87 , V_87 , V_92 -> V_38 ) ;
fprintf ( V_44 ,
L_43 ,
V_88 , V_88 , V_92 -> V_38 ) ;
fprintf ( V_44 ,
L_44 ,
V_89 , V_89 , V_92 -> V_38 ) ;
V_93 = F_35 ( NULL , V_90 , V_94 , TRUE ) ;
fprintf ( V_44 ,
L_45 ,
V_93 , ( int ) V_90 -> V_95 , V_90 -> V_96 , V_92 -> V_38 ) ;
F_25 ( NULL , V_93 ) ;
fprintf ( V_44 ,
L_46 ) ;
}
void
F_36 ( T_12 * V_44 )
{
fputs ( L_47 , V_44 ) ;
}
void
F_37 ( T_19 * V_97 , T_12 * V_44 )
{
T_20 V_54 ;
fputs ( L_10 , V_44 ) ;
fputs ( L_48 V_98 L_17 , V_44 ) ;
fprintf ( V_44 , L_49 , V_50 , V_51 ) ;
fprintf ( V_44 , L_50 ) ;
for ( V_54 = 0 ; V_54 < V_97 -> V_99 ; V_54 ++ ) {
fprintf ( V_44 , L_51 ) ;
F_22 ( V_44 , V_97 -> V_100 [ V_54 ] . V_101 ) ;
fprintf ( V_44 , L_52 ) ;
}
fprintf ( V_44 , L_53 ) ;
}
void
F_38 ( T_3 * V_8 , T_12 * V_44 )
{
T_20 V_54 ;
fprintf ( V_44 , L_19 ) ;
for ( V_54 = 0 ; V_54 < V_8 -> V_15 . V_97 -> V_99 ; V_54 ++ ) {
fprintf ( V_44 , L_51 ) ;
F_22 ( V_44 , V_8 -> V_15 . V_97 -> V_100 [ V_54 ] . V_102 ) ;
fprintf ( V_44 , L_52 ) ;
}
fprintf ( V_44 , L_20 ) ;
}
void
F_39 ( T_12 * V_44 )
{
fputs ( L_54 , V_44 ) ;
}
static T_11 * F_40 ( const T_11 * V_103 , const T_11 * V_104 )
{
T_11 * V_105 ;
T_11 * V_106 ;
V_105 = F_41 ( V_103 , V_104 ) ;
V_106 = V_105 ;
while ( ( V_106 = strstr ( V_106 , V_107 ) ) != NULL ) {
V_106 [ 0 ] = ' ' ;
V_106 [ 1 ] = '>' ;
V_106 [ 2 ] = ' ' ;
}
V_106 = V_105 ;
while ( ( V_106 = strstr ( V_106 , L_55 ) ) != NULL )
* V_106 = '\"' ;
return V_105 ;
}
static void F_42 ( const char * V_108 , char V_109 , T_12 * V_44 )
{
T_11 * V_105 ;
V_105 = F_40 ( V_108 , V_107 ) ;
fprintf ( V_44 , L_56 , V_105 , V_109 ) ;
F_13 ( V_105 ) ;
}
void
F_43 ( T_19 * V_97 , T_12 * V_44 )
{
T_20 V_54 ;
for ( V_54 = 0 ; V_54 < V_97 -> V_99 - 1 ; V_54 ++ )
F_42 ( V_97 -> V_100 [ V_54 ] . V_101 , ',' , V_44 ) ;
F_42 ( V_97 -> V_100 [ V_54 ] . V_101 , '\n' , V_44 ) ;
}
void
F_44 ( T_3 * V_8 , T_12 * V_44 )
{
T_20 V_54 ;
for ( V_54 = 0 ; V_54 < V_8 -> V_15 . V_97 -> V_99 - 1 ; V_54 ++ )
F_42 ( V_8 -> V_15 . V_97 -> V_100 [ V_54 ] . V_102 , ',' , V_44 ) ;
F_42 ( V_8 -> V_15 . V_97 -> V_100 [ V_54 ] . V_102 , '\n' , V_44 ) ;
}
void
F_45 ( T_16 V_87 , T_12 * V_44 , T_3 * V_8 )
{
T_16 V_54 = 0 , V_110 = 0 ;
T_21 * V_111 ;
T_22 * V_112 ;
char * V_113 ;
const T_23 * V_114 ;
V_72 V_38 ;
char V_115 [ 9 ] ;
struct V_116 * V_117 ;
for ( V_111 = V_8 -> V_15 . V_16 ; V_111 != NULL ; V_111 = V_111 -> V_118 ) {
memset ( V_115 , 0 , sizeof( V_115 ) ) ;
V_117 = (struct V_116 * ) V_111 -> V_11 ;
V_112 = F_46 ( V_117 ) ;
V_38 = F_47 ( V_112 ) ;
if ( V_38 == 0 )
continue;
V_114 = F_48 ( V_112 , 0 , V_38 ) ;
V_113 = F_49 ( V_117 ) ;
if ( V_113 ) {
fprintf ( V_44 , L_57 , V_113 ) ;
F_25 ( NULL , V_113 ) ;
}
if ( V_110 ) {
fprintf ( V_44 , L_58 ,
V_87 , V_110 , V_38 ) ;
} else {
fprintf ( V_44 , L_59 ,
V_87 , V_38 ) ;
}
V_110 ++ ;
for ( V_54 = 0 ; V_54 < V_38 ; V_54 ++ ) {
fprintf ( V_44 , L_60 , * ( V_114 + V_54 ) ) ;
V_115 [ V_54 % 8 ] = F_50 ( * ( V_114 + V_54 ) ) ? * ( V_114 + V_54 ) : '.' ;
if ( V_54 == ( V_38 - 1 ) ) {
V_72 V_119 ;
V_119 = V_38 % 8 ;
if ( V_119 ) {
V_72 V_120 ;
for ( V_120 = 0 ; V_120 < 8 - V_119 ; V_120 ++ )
fprintf ( V_44 , L_61 ) ;
}
fprintf ( V_44 , L_62 , V_115 ) ;
break;
}
if ( ! ( ( V_54 + 1 ) % 8 ) ) {
fprintf ( V_44 , L_63 , V_115 ) ;
memset ( V_115 , 0 , sizeof( V_115 ) ) ;
}
else {
fprintf ( V_44 , L_64 ) ;
}
}
}
}
static const T_10 *
F_15 ( T_21 * V_14 , T_9 * V_27 )
{
T_21 * V_111 ;
T_22 * V_121 ;
T_20 V_38 , V_122 ;
struct V_116 * V_117 ;
for ( V_111 = V_14 ; V_111 != NULL ; V_111 = V_111 -> V_118 ) {
V_117 = (struct V_116 * ) V_111 -> V_11 ;
V_121 = F_46 ( V_117 ) ;
if ( V_27 -> V_123 == V_121 ) {
V_122 = F_51 ( V_121 ,
V_27 -> V_60 ) ;
if ( V_122 < 0 ) {
return NULL ;
}
V_38 = V_27 -> V_38 ;
if ( V_38 > V_122 )
V_38 = V_122 ;
return F_48 ( V_121 , V_27 -> V_60 , V_38 ) ;
}
}
F_30 () ;
return NULL ;
}
static void
F_22 ( T_12 * V_44 , const char * V_124 )
{
const char * V_125 ;
char V_126 [ 8 ] ;
for ( V_125 = V_124 ; * V_125 != '\0' ; V_125 ++ ) {
switch ( * V_125 ) {
case '&' :
fputs ( L_65 , V_44 ) ;
break;
case '<' :
fputs ( L_66 , V_44 ) ;
break;
case '>' :
fputs ( L_67 , V_44 ) ;
break;
case '"' :
fputs ( L_68 , V_44 ) ;
break;
case '\'' :
fputs ( L_69 , V_44 ) ;
break;
default:
if ( F_50 ( * V_125 ) )
fputc ( * V_125 , V_44 ) ;
else {
F_52 ( V_126 , sizeof( V_126 ) , L_70 , ( T_10 ) * V_125 ) ;
fputs ( V_126 , V_44 ) ;
}
}
}
}
static void
F_23 ( T_14 * V_28 , T_9 * V_27 )
{
int V_54 ;
const T_10 * V_29 ;
if ( ! V_27 -> V_123 )
return;
if ( V_27 -> V_38 > F_51 ( V_27 -> V_123 , V_27 -> V_60 ) ) {
fprintf ( V_28 -> V_44 , L_71 ) ;
return;
}
V_29 = F_15 ( V_28 -> V_14 , V_27 ) ;
if ( V_29 ) {
for ( V_54 = 0 ; V_54 < V_27 -> V_38 ; V_54 ++ ) {
fprintf ( V_28 -> V_44 , L_72 , V_29 [ V_54 ] ) ;
}
}
}
T_1
F_53 ( T_5 * V_10 , T_3 * V_8 )
{
T_1 V_127 ;
T_21 * V_111 ;
T_22 * V_112 ;
char * line , * V_113 ;
const T_23 * V_114 ;
V_72 V_38 ;
struct V_116 * V_117 ;
V_127 = ( V_8 -> V_15 . V_16 -> V_118 != NULL ) ;
for ( V_111 = V_8 -> V_15 . V_16 ; V_111 != NULL ;
V_111 = V_111 -> V_118 ) {
V_117 = (struct V_116 * ) V_111 -> V_11 ;
V_112 = F_46 ( V_117 ) ;
if ( V_127 ) {
V_113 = F_49 ( V_117 ) ;
line = F_54 ( L_73 , V_113 ) ;
F_25 ( NULL , V_113 ) ;
F_12 ( V_10 , 0 , line ) ;
F_13 ( line ) ;
}
V_38 = F_47 ( V_112 ) ;
if ( V_38 == 0 )
return TRUE ;
V_114 = F_48 ( V_112 , 0 , V_38 ) ;
if ( ! F_16 ( V_10 , V_114 , V_38 ,
( V_18 ) V_8 -> V_15 . V_19 -> V_20 . V_17 ) )
return FALSE ;
}
return TRUE ;
}
static T_1
F_16 ( T_5 * V_10 , const T_23 * V_114 ,
V_72 V_38 , V_18 V_17 )
{
register unsigned int V_128 , V_54 , V_120 , V_129 , V_130 ;
T_23 V_131 ;
T_11 line [ V_132 + 1 ] ;
unsigned int V_133 ;
static T_11 V_134 [ 16 ] = {
'0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' ,
'8' , '9' , 'a' , 'b' , 'c' , 'd' , 'e' , 'f' } ;
if ( ( ( V_38 - 1 ) & 0xF0000000 ) != 0 )
V_133 = 8 ;
else if ( ( ( V_38 - 1 ) & 0x0F000000 ) != 0 )
V_133 = 7 ;
else if ( ( ( V_38 - 1 ) & 0x00F00000 ) != 0 )
V_133 = 6 ;
else if ( ( ( V_38 - 1 ) & 0x000F0000 ) != 0 )
V_133 = 5 ;
else
V_133 = 4 ;
V_128 = 0 ;
V_54 = 0 ;
V_120 = 0 ;
V_129 = 0 ;
while ( V_54 < V_38 ) {
if ( ( V_54 & 15 ) == 0 ) {
V_120 = 0 ;
V_130 = V_133 ;
do {
V_130 -- ;
V_131 = ( V_128 >> ( V_130 * 4 ) ) & 0xF ;
line [ V_120 ++ ] = V_134 [ V_131 ] ;
} while ( V_130 != 0 );
line [ V_120 ++ ] = ' ' ;
line [ V_120 ++ ] = ' ' ;
memset ( line + V_120 , ' ' , V_135 ) ;
V_129 = V_120 + V_136 + 2 ;
}
V_131 = * V_114 ++ ;
line [ V_120 ++ ] = V_134 [ V_131 >> 4 ] ;
line [ V_120 ++ ] = V_134 [ V_131 & 0xf ] ;
V_120 ++ ;
if ( V_17 == V_137 ) {
V_131 = F_55 ( V_131 ) ;
}
line [ V_129 ++ ] = ( ( V_131 >= ' ' ) && ( V_131 < 0x7f ) ) ? V_131 : '.' ;
V_54 ++ ;
if ( ( ( V_54 & 15 ) == 0 ) || ( V_54 == V_38 ) ) {
line [ V_129 ] = '\0' ;
if ( ! F_12 ( V_10 , 0 , line ) )
return FALSE ;
V_128 += 16 ;
}
}
return TRUE ;
}
T_24 F_56 ( T_25 * V_138 )
{
F_7 ( V_138 ) ;
if ( NULL == V_138 -> V_138 ) {
return 0 ;
} else {
return V_138 -> V_138 -> V_88 ;
}
}
void F_57 ( T_25 * V_138 )
{
F_7 ( V_138 ) ;
if ( NULL != V_138 -> V_138 ) {
T_24 V_54 ;
if ( NULL != V_138 -> V_139 ) {
F_58 ( V_138 -> V_139 ) ;
}
if ( NULL != V_138 -> V_140 ) {
F_13 ( V_138 -> V_140 ) ;
}
for( V_54 = 0 ; V_54 < V_138 -> V_138 -> V_88 ; ++ V_54 ) {
T_11 * V_141 = ( T_11 * ) F_59 ( V_138 -> V_138 , V_54 ) ;
F_13 ( V_141 ) ;
}
F_33 ( V_138 -> V_138 , TRUE ) ;
}
F_13 ( V_138 ) ;
}
void F_60 ( T_25 * V_138 , const T_11 * V_141 )
{
T_11 * V_142 ;
F_7 ( V_138 ) ;
F_7 ( V_141 ) ;
if ( NULL == V_138 -> V_138 ) {
V_138 -> V_138 = F_61 () ;
}
V_142 = F_62 ( V_141 ) ;
F_63 ( V_138 -> V_138 , V_142 ) ;
if ( ! strncmp ( V_141 , V_143 , strlen ( V_143 ) ) )
V_138 -> V_144 = TRUE ;
}
static void
F_64 ( void * V_11 , void * V_145 )
{
T_11 * V_141 = ( T_11 * ) V_11 ;
T_21 * * V_146 = ( T_21 * * ) V_145 ;
if ( ! strncmp ( V_141 , V_143 , strlen ( V_143 ) ) )
return;
if ( ! F_65 ( V_141 ) ) {
* V_146 = F_66 ( * V_146 , V_141 ) ;
}
}
T_21 *
F_67 ( T_25 * V_138 )
{
T_21 * V_146 = NULL ;
if ( V_138 -> V_138 == NULL ) {
return NULL ;
}
F_68 ( V_138 -> V_138 , F_64 , & V_146 ) ;
return V_146 ;
}
T_1 F_69 ( T_25 * V_147 , T_11 * V_148 )
{
const T_11 * V_149 ;
const T_11 * V_150 ;
F_7 ( V_147 ) ;
F_7 ( V_148 ) ;
if ( '\0' == * V_148 ) {
return FALSE ;
}
V_149 = strtok ( V_148 , L_74 ) ;
if ( ! V_149 ) {
return FALSE ;
}
V_150 = V_148 + strlen ( V_149 ) + 1 ;
if ( * V_150 == '\0' ) {
return FALSE ;
}
if ( 0 == strcmp ( V_149 , L_75 ) ) {
switch ( * V_150 ) {
case 'n' :
V_147 -> V_151 = FALSE ;
break;
case 'y' :
V_147 -> V_151 = TRUE ;
break;
default:
return FALSE ;
}
return TRUE ;
}
else if ( 0 == strcmp ( V_149 , L_76 ) ) {
switch ( * V_150 ) {
case '/' :
switch ( * ++ V_150 ) {
case 't' :
V_147 -> V_152 = '\t' ;
break;
case 's' :
V_147 -> V_152 = ' ' ;
break;
default:
V_147 -> V_152 = '\\' ;
}
break;
default:
V_147 -> V_152 = * V_150 ;
break;
}
return TRUE ;
}
else if ( 0 == strcmp ( V_149 , L_77 ) ) {
switch ( * V_150 ) {
case 'f' :
case 'l' :
case 'a' :
V_147 -> V_153 = * V_150 ;
break;
default:
return FALSE ;
}
return TRUE ;
}
else if ( 0 == strcmp ( V_149 , L_78 ) ) {
switch ( * V_150 ) {
case '/' :
switch ( * ++ V_150 ) {
case 's' :
V_147 -> V_154 = ' ' ;
break;
default:
V_147 -> V_154 = '\\' ;
}
break;
default:
V_147 -> V_154 = * V_150 ;
break;
}
return TRUE ;
}
else if ( 0 == strcmp ( V_149 , L_79 ) ) {
switch ( * V_150 ) {
case 'd' :
V_147 -> V_155 = '"' ;
break;
case 's' :
V_147 -> V_155 = '\'' ;
break;
case 'n' :
V_147 -> V_155 = '\0' ;
break;
default:
V_147 -> V_155 = '\0' ;
return FALSE ;
}
return TRUE ;
}
else if ( 0 == strcmp ( V_149 , L_80 ) ) {
switch ( * V_150 ) {
case 'n' :
V_147 -> V_156 = FALSE ;
break;
case 'y' :
V_147 -> V_156 = TRUE ;
break;
default:
return FALSE ;
}
return TRUE ;
}
return FALSE ;
}
void F_70 ( T_12 * V_44 )
{
fprintf ( V_44 , L_81 ) ;
fputs ( L_82 , V_44 ) ;
fputs ( L_83 , V_44 ) ;
fputs ( L_84 , V_44 ) ;
fputs ( L_85 , V_44 ) ;
fputs ( L_86 , V_44 ) ;
fputs ( L_87 , V_44 ) ;
}
T_1 F_71 ( T_25 * V_138 )
{
F_7 ( V_138 ) ;
return V_138 -> V_144 ;
}
void F_72 ( T_25 * V_138 , T_12 * V_44 )
{
T_24 V_54 ;
F_7 ( V_138 ) ;
F_7 ( V_44 ) ;
F_7 ( V_138 -> V_138 ) ;
if ( V_138 -> V_156 ) {
fputs ( V_157 , V_44 ) ;
}
if ( ! V_138 -> V_151 ) {
return;
}
for( V_54 = 0 ; V_54 < V_138 -> V_138 -> V_88 ; ++ V_54 ) {
const T_11 * V_141 = ( const T_11 * ) F_59 ( V_138 -> V_138 , V_54 ) ;
if ( V_54 != 0 ) {
fputc ( V_138 -> V_152 , V_44 ) ;
}
fputs ( V_141 , V_44 ) ;
}
fputc ( '\n' , V_44 ) ;
}
static void F_73 ( T_25 * V_138 , T_8 V_158 , const T_11 * V_63 )
{
V_72 V_159 ;
T_18 * V_160 ;
if ( NULL == V_63 )
return;
V_159 = F_74 ( V_158 ) - 1 ;
if ( V_138 -> V_140 [ V_159 ] == NULL ) {
V_138 -> V_140 [ V_159 ] = F_61 () ;
}
V_160 = V_138 -> V_140 [ V_159 ] ;
switch ( V_138 -> V_153 ) {
case 'f' :
if ( F_32 ( V_160 ) != 0 )
return;
break;
case 'l' :
F_75 ( V_160 , 0 ) ;
break;
case 'a' :
if ( F_32 ( V_160 ) > 0 ) {
F_63 ( V_160 , ( T_8 ) F_54 ( L_88 , V_138 -> V_154 ) ) ;
}
break;
default:
F_30 () ;
break;
}
F_63 ( V_160 , ( T_8 ) V_63 ) ;
}
static void F_76 ( T_7 * V_26 , T_8 V_11 )
{
T_26 * V_161 ;
T_9 * V_27 ;
T_8 V_158 ;
V_161 = ( T_26 * ) V_11 ;
V_27 = F_6 ( V_26 ) ;
F_7 ( V_27 ) ;
V_158 = F_14 ( V_161 -> V_138 -> V_139 , V_27 -> V_35 -> V_36 ) ;
if ( NULL != V_158 ) {
F_73 ( V_161 -> V_138 , V_158 ,
F_77 ( V_27 , V_161 -> V_8 )
) ;
}
if ( V_26 -> V_43 != NULL ) {
F_5 ( V_26 , F_76 ,
V_161 ) ;
}
}
void F_78 ( T_25 * V_138 , T_3 * V_8 , T_19 * V_97 , T_12 * V_44 )
{
T_24 V_54 ;
T_20 V_162 ;
T_11 * V_163 ;
T_8 V_158 ;
T_26 V_11 ;
F_7 ( V_138 ) ;
F_7 ( V_138 -> V_138 ) ;
F_7 ( V_8 ) ;
F_7 ( V_44 ) ;
V_11 . V_138 = V_138 ;
V_11 . V_8 = V_8 ;
if ( NULL == V_138 -> V_139 ) {
V_138 -> V_139 = F_79 ( V_164 , V_165 ) ;
V_54 = 0 ;
while ( V_54 < V_138 -> V_138 -> V_88 ) {
T_11 * V_141 = ( T_11 * ) F_59 ( V_138 -> V_138 , V_54 ) ;
++ V_54 ;
F_80 ( V_138 -> V_139 , V_141 , F_81 ( V_54 ) ) ;
}
}
if ( NULL == V_138 -> V_140 )
V_138 -> V_140 = F_82 ( T_18 * , V_138 -> V_138 -> V_88 ) ;
F_5 ( V_8 -> V_24 , F_76 ,
& V_11 ) ;
if ( V_138 -> V_144 ) {
for ( V_162 = 0 ; V_162 < V_97 -> V_99 ; V_162 ++ ) {
V_163 = F_54 ( L_89 , V_143 , V_97 -> V_100 [ V_162 ] . V_101 ) ;
V_158 = F_14 ( V_138 -> V_139 , V_163 ) ;
F_13 ( V_163 ) ;
if ( NULL != V_158 ) {
F_73 ( V_138 , V_158 , F_62 ( V_97 -> V_100 [ V_162 ] . V_102 ) ) ;
}
}
}
for( V_54 = 0 ; V_54 < V_138 -> V_138 -> V_88 ; ++ V_54 ) {
if ( 0 != V_54 ) {
fputc ( V_138 -> V_152 , V_44 ) ;
}
if ( NULL != V_138 -> V_140 [ V_54 ] ) {
T_18 * V_160 ;
T_11 * V_108 ;
T_24 V_120 ;
V_160 = V_138 -> V_140 [ V_54 ] ;
if ( V_138 -> V_155 != '\0' ) {
fputc ( V_138 -> V_155 , V_44 ) ;
}
for ( V_120 = 0 ; V_120 < F_32 ( V_160 ) ; V_120 ++ ) {
V_108 = ( T_11 * ) F_59 ( V_160 , V_120 ) ;
fputs ( V_108 , V_44 ) ;
F_13 ( V_108 ) ;
}
if ( V_138 -> V_155 != '\0' ) {
fputc ( V_138 -> V_155 , V_44 ) ;
}
F_33 ( V_160 , TRUE ) ;
V_138 -> V_140 [ V_54 ] = NULL ;
}
}
}
void F_83 ( T_25 * V_138 V_166 , T_12 * V_44 V_166 )
{
}
T_11 * F_77 ( T_9 * V_27 , T_3 * V_8 )
{
if ( V_27 -> V_35 -> V_37 == V_57 ) {
if ( V_27 -> V_33 ) {
return F_62 ( V_27 -> V_33 -> V_34 ) ;
}
else {
return F_84 ( V_8 -> V_15 . V_16 , V_27 ) ;
}
}
else if ( V_27 -> V_35 -> V_37 == V_1 ) {
return F_84 ( V_8 -> V_15 . V_16 , V_27 ) ;
}
else {
T_11 * V_53 ;
switch ( V_27 -> V_35 -> type )
{
case V_56 :
if ( V_27 -> V_33 ) {
return F_62 ( V_27 -> V_33 -> V_34 ) ;
} else {
return F_62 ( V_27 -> V_35 -> V_36 ) ;
}
case V_62 :
return F_62 ( L_90 ) ;
default:
V_53 = F_24 ( NULL , & V_27 -> V_63 , V_64 , V_27 -> V_35 -> V_65 ) ;
if ( V_53 != NULL ) {
T_11 * V_167 = F_62 ( V_53 ) ;
F_25 ( NULL , V_53 ) ;
return V_167 ;
} else {
return F_84 ( V_8 -> V_15 . V_16 , V_27 ) ;
}
}
}
}
static T_11 *
F_84 ( T_21 * V_14 , T_9 * V_27 )
{
const T_10 * V_29 ;
if ( ! V_27 -> V_123 )
return NULL ;
if ( V_27 -> V_38 > F_51 ( V_27 -> V_123 , V_27 -> V_60 ) ) {
return F_62 ( L_71 ) ;
}
V_29 = F_15 ( V_14 , V_27 ) ;
if ( V_29 ) {
int V_54 ;
T_11 * V_168 ;
T_11 * V_125 ;
int V_88 ;
const int V_169 = 2 ;
V_88 = V_169 * V_27 -> V_38 ;
V_168 = ( T_11 * ) F_85 ( sizeof( T_11 ) * ( V_88 + 1 ) ) ;
V_168 [ V_88 ] = '\0' ;
V_125 = V_168 ;
for ( V_54 = 0 ; V_54 < V_27 -> V_38 ; V_54 ++ ) {
F_52 ( V_125 , V_169 + 1 , L_72 , V_29 [ V_54 ] ) ;
V_125 += V_169 ;
}
return V_168 ;
} else {
return NULL ;
}
}
T_25 * F_86 ( void )
{
T_25 * V_138 = F_87 ( T_25 , 1 ) ;
V_138 -> V_156 = FALSE ;
V_138 -> V_151 = FALSE ;
V_138 -> V_152 = '\t' ;
V_138 -> V_153 = 'a' ;
V_138 -> V_154 = ',' ;
V_138 -> V_138 = NULL ;
V_138 -> V_139 = NULL ;
V_138 -> V_140 = NULL ;
V_138 -> V_155 = '\0' ;
V_138 -> V_144 = FALSE ;
return V_138 ;
}
