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
V_11 . V_17 = V_8 -> V_15 . V_18 -> V_19 . V_17 ;
V_11 . V_20 = V_7 -> V_20 ;
V_11 . V_21 = ! V_7 -> V_22 ;
V_11 . V_8 = V_8 ;
V_11 . V_9 = V_9 ;
F_5 ( V_8 -> V_23 , V_24 , & V_11 ) ;
return V_11 . V_13 ;
}
static void
V_24 ( T_7 * V_25 , T_8 V_11 )
{
T_9 * V_26 = F_6 ( V_25 ) ;
T_6 * V_27 = ( T_6 * ) V_11 ;
const T_10 * V_28 ;
T_11 V_29 [ V_30 ] ;
T_11 * V_31 ;
F_7 ( V_26 ) ;
if ( F_8 ( V_25 ) )
return;
if ( ! V_27 -> V_13 )
return;
if ( V_26 -> V_32 ) {
V_31 = V_26 -> V_32 -> V_33 ;
}
else {
V_31 = V_29 ;
F_9 ( V_26 , V_29 ) ;
}
if ( F_10 ( V_25 ) )
V_31 = F_11 ( L_7 , V_31 , L_8 , NULL ) ;
V_27 -> V_13 = F_12 ( V_27 -> V_10 , V_27 -> V_12 , V_31 ) ;
if ( F_10 ( V_25 ) )
F_13 ( V_31 ) ;
if ( ! V_27 -> V_13 )
return;
if ( ( V_27 -> V_9 != NULL ) && ( V_27 -> V_12 == 0 )
&& ( F_14 ( V_27 -> V_9 , V_26 -> V_34 -> V_35 ) == NULL ) ) {
return;
}
if ( ( V_26 -> V_34 -> V_36 == V_1 ) && ( V_27 -> V_21 ) ) {
V_28 = F_15 ( V_27 -> V_14 , V_26 ) ;
if ( V_28 ) {
if ( ! F_12 ( V_27 -> V_10 , 0 , L_9 ) ) {
V_27 -> V_13 = FALSE ;
return;
}
if ( ! F_16 ( V_27 -> V_10 , V_28 ,
V_26 -> V_37 , V_27 -> V_17 ) ) {
V_27 -> V_13 = FALSE ;
return;
}
}
}
F_7 ( ( V_26 -> V_38 >= - 1 ) && ( V_26 -> V_38 < V_39 ) ) ;
if ( ( V_27 -> V_20 == V_40 ) ||
( ( V_27 -> V_20 == V_41 ) &&
( V_26 -> V_38 >= 0 ) && F_17 ( V_26 -> V_38 ) ) ) {
if ( V_25 -> V_42 != NULL ) {
V_27 -> V_12 ++ ;
F_5 ( V_25 ,
V_24 , V_27 ) ;
V_27 -> V_12 -- ;
if ( ! V_27 -> V_13 )
return;
}
}
}
void
F_18 ( T_12 * V_43 , const T_11 * V_44 )
{
T_13 V_45 = time ( NULL ) ;
char * V_46 = asctime ( localtime ( & V_45 ) ) ;
V_46 [ strlen ( V_46 ) - 1 ] = 0 ;
fputs ( L_10 , V_43 ) ;
fputs ( L_11 V_47 L_12 , V_43 ) ;
fprintf ( V_43 , L_13 V_47 L_14 V_47 L_15 , F_19 () ) ;
fputs ( L_16 V_48 L_17 , V_43 ) ;
fprintf ( V_43 , L_18 , V_49 , V_50 , V_46 , V_44 ? V_44 : L_9 ) ;
}
void
F_20 ( T_3 * V_8 , T_12 * V_43 )
{
T_14 V_11 ;
V_11 . V_12 = 0 ;
V_11 . V_43 = V_43 ;
V_11 . V_14 = V_8 -> V_15 . V_16 ;
V_11 . V_8 = V_8 ;
fprintf ( V_43 , L_19 ) ;
F_21 ( V_8 -> V_23 , V_43 ) ;
F_5 ( V_8 -> V_23 , V_51 ,
& V_11 ) ;
fprintf ( V_43 , L_20 ) ;
}
static void
V_51 ( T_7 * V_25 , T_8 V_11 )
{
T_9 * V_26 = F_6 ( V_25 ) ;
T_14 * V_27 = ( T_14 * ) V_11 ;
const T_11 * V_31 ;
T_11 V_29 [ V_30 ] ;
char * V_52 ;
int V_53 ;
T_1 V_54 ;
F_7 ( V_26 ) ;
V_54 =
( ( ( V_26 -> V_34 -> type != V_55 ) ||
( V_26 -> V_34 -> V_36 == V_1 ) ) &&
( V_27 -> V_12 == 0 ) ) ;
for ( V_53 = - 1 ; V_53 < V_27 -> V_12 ; V_53 ++ ) {
fputs ( L_21 , V_27 -> V_43 ) ;
}
if ( V_54 ) {
fputs ( L_22 , V_27 -> V_43 ) ;
V_27 -> V_12 ++ ;
for ( V_53 = - 1 ; V_53 < V_27 -> V_12 ; V_53 ++ ) {
fputs ( L_21 , V_27 -> V_43 ) ;
}
}
if ( V_26 -> V_34 -> V_36 == V_56 ) {
if ( V_26 -> V_32 ) {
V_31 = V_26 -> V_32 -> V_33 ;
}
else {
V_31 = L_9 ;
}
fputs ( L_23 , V_27 -> V_43 ) ;
fputs ( L_24 , V_27 -> V_43 ) ;
F_22 ( V_27 -> V_43 , V_31 ) ;
fprintf ( V_27 -> V_43 , L_25 , V_26 -> V_37 ) ;
if ( V_25 -> V_57 && V_25 -> V_57 -> V_58 && ( V_26 -> V_59 < V_25 -> V_57 -> V_58 -> V_59 ) ) {
fprintf ( V_27 -> V_43 , L_26 , V_25 -> V_57 -> V_58 -> V_59 + V_26 -> V_59 ) ;
} else {
fprintf ( V_27 -> V_43 , L_26 , V_26 -> V_59 ) ;
}
if ( V_26 -> V_37 > 0 ) {
fputs ( L_27 , V_27 -> V_43 ) ;
F_23 ( V_27 , V_26 ) ;
}
if ( V_25 -> V_42 != NULL ) {
fputs ( L_28 , V_27 -> V_43 ) ;
}
else {
fputs ( L_29 , V_27 -> V_43 ) ;
}
}
else if ( V_26 -> V_34 -> V_36 == V_1 ) {
fputs ( L_30 , V_27 -> V_43 ) ;
F_23 ( V_27 , V_26 ) ;
fputs ( L_28 , V_27 -> V_43 ) ;
}
else {
if ( ( V_26 -> V_34 -> type == V_55 ) && ( V_26 -> V_34 -> V_36 != V_60 ) ) {
fputs ( L_31 , V_27 -> V_43 ) ;
}
else {
fputs ( L_23 , V_27 -> V_43 ) ;
}
F_22 ( V_27 -> V_43 , V_26 -> V_34 -> V_35 ) ;
#if 0
fputs("\" showname=\"", pdata->fh);
print_escaped_xml(pdata->fh, fi->hfinfo->name);
#endif
if ( V_26 -> V_32 ) {
fputs ( L_32 , V_27 -> V_43 ) ;
F_22 ( V_27 -> V_43 , V_26 -> V_32 -> V_33 ) ;
}
else {
V_31 = V_29 ;
F_9 ( V_26 , V_29 ) ;
fputs ( L_32 , V_27 -> V_43 ) ;
F_22 ( V_27 -> V_43 , V_31 ) ;
}
if ( F_8 ( V_25 ) )
fprintf ( V_27 -> V_43 , L_33 ) ;
fprintf ( V_27 -> V_43 , L_25 , V_26 -> V_37 ) ;
if ( V_25 -> V_57 && V_25 -> V_57 -> V_58 && ( V_26 -> V_59 < V_25 -> V_57 -> V_58 -> V_59 ) ) {
fprintf ( V_27 -> V_43 , L_26 , V_25 -> V_57 -> V_58 -> V_59 + V_26 -> V_59 ) ;
} else {
fprintf ( V_27 -> V_43 , L_26 , V_26 -> V_59 ) ;
}
switch ( V_26 -> V_34 -> type )
{
case V_55 :
break;
case V_61 :
fputs ( L_34 , V_27 -> V_43 ) ;
break;
default:
V_52 = F_24 ( & V_26 -> V_62 , V_63 , V_26 -> V_34 -> V_64 , NULL ) ;
if ( V_52 != NULL ) {
fputs ( L_24 , V_27 -> V_43 ) ;
F_22 ( V_27 -> V_43 , V_52 ) ;
}
F_13 ( V_52 ) ;
if ( V_26 -> V_37 > 0 ) {
fputs ( L_27 , V_27 -> V_43 ) ;
if ( V_26 -> V_34 -> V_65 != 0 ) {
switch ( V_26 -> V_62 . V_66 -> V_66 ) {
case V_67 :
case V_68 :
case V_69 :
case V_70 :
fprintf ( V_27 -> V_43 , L_35 , ( V_71 ) F_25 ( & V_26 -> V_62 ) ) ;
break;
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
fprintf ( V_27 -> V_43 , L_35 , F_26 ( & V_26 -> V_62 ) ) ;
break;
case V_77 :
case V_78 :
case V_79 :
case V_80 :
fprintf ( V_27 -> V_43 , L_36 V_81 L_37 , F_27 ( & V_26 -> V_62 ) ) ;
break;
case V_82 :
case V_83 :
case V_84 :
case V_85 :
fprintf ( V_27 -> V_43 , L_36 V_81 L_37 , F_28 ( & V_26 -> V_62 ) ) ;
break;
default:
F_29 () ;
}
fputs ( L_38 , V_27 -> V_43 ) ;
F_23 ( V_27 , V_26 ) ;
}
else {
F_23 ( V_27 , V_26 ) ;
}
}
}
if ( V_25 -> V_42 != NULL ) {
fputs ( L_28 , V_27 -> V_43 ) ;
}
else if ( V_26 -> V_34 -> V_36 == V_1 ) {
fputs ( L_28 , V_27 -> V_43 ) ;
}
else {
fputs ( L_29 , V_27 -> V_43 ) ;
}
}
if ( V_25 -> V_42 != NULL ) {
V_27 -> V_12 ++ ;
F_5 ( V_25 ,
V_51 , V_27 ) ;
V_27 -> V_12 -- ;
}
if ( V_54 ) {
V_27 -> V_12 -- ;
}
if ( V_25 -> V_42 != NULL ) {
for ( V_53 = - 1 ; V_53 < V_27 -> V_12 ; V_53 ++ ) {
fputs ( L_21 , V_27 -> V_43 ) ;
}
if ( ( V_26 -> V_34 -> V_36 != V_1 ) && ( V_26 -> V_34 -> V_36 != V_60 ) ) {
if ( V_26 -> V_34 -> type == V_55 ) {
fputs ( L_39 , V_27 -> V_43 ) ;
}
else {
fputs ( L_40 , V_27 -> V_43 ) ;
}
} else {
fputs ( L_40 , V_27 -> V_43 ) ;
}
}
if ( V_54 ) {
fputs ( L_39 , V_27 -> V_43 ) ;
}
}
static void
F_21 ( T_15 * V_23 , T_12 * V_43 )
{
T_16 V_86 , V_87 , V_88 ;
T_17 * V_89 ;
T_18 * V_90 ;
T_9 * V_91 ;
T_11 * V_92 ;
V_90 = F_30 ( V_23 , V_2 ) ;
if ( F_31 ( V_90 ) < 1 ) {
return;
}
V_91 = ( T_9 * ) V_90 -> V_27 [ 0 ] ;
F_32 ( V_90 , TRUE ) ;
V_90 = F_30 ( V_23 , V_4 ) ;
if ( F_31 ( V_90 ) < 1 ) {
return;
}
V_86 = F_26 ( & ( ( T_9 * ) V_90 -> V_27 [ 0 ] ) -> V_62 ) ;
F_32 ( V_90 , TRUE ) ;
V_90 = F_30 ( V_23 , V_5 ) ;
if ( F_31 ( V_90 ) < 1 ) {
return;
}
V_87 = F_26 ( & ( ( T_9 * ) V_90 -> V_27 [ 0 ] ) -> V_62 ) ;
F_32 ( V_90 , TRUE ) ;
V_90 = F_30 ( V_23 , V_6 ) ;
if ( F_31 ( V_90 ) < 1 ) {
return;
}
V_88 = F_26 ( & ( ( T_9 * ) V_90 -> V_27 [ 0 ] ) -> V_62 ) ;
F_32 ( V_90 , TRUE ) ;
V_90 = F_30 ( V_23 , V_3 ) ;
if ( F_31 ( V_90 ) < 1 ) {
return;
}
V_89 = ( T_17 * ) F_33 ( & ( ( T_9 * ) V_90 -> V_27 [ 0 ] ) -> V_62 ) ;
F_32 ( V_90 , TRUE ) ;
fprintf ( V_43 ,
L_41 ,
V_91 -> V_37 ) ;
fprintf ( V_43 ,
L_42 ,
V_86 , V_86 , V_91 -> V_37 ) ;
fprintf ( V_43 ,
L_43 ,
V_87 , V_87 , V_91 -> V_37 ) ;
fprintf ( V_43 ,
L_44 ,
V_88 , V_88 , V_91 -> V_37 ) ;
V_92 = F_34 ( NULL , V_89 , V_93 , TRUE ) ;
fprintf ( V_43 ,
L_45 ,
V_92 , ( int ) V_89 -> V_94 , V_89 -> V_95 , V_91 -> V_37 ) ;
F_35 ( NULL , V_92 ) ;
fprintf ( V_43 ,
L_46 ) ;
}
void
F_36 ( T_12 * V_43 )
{
fputs ( L_47 , V_43 ) ;
}
void
F_37 ( T_19 * V_96 , T_12 * V_43 )
{
T_20 V_53 ;
fputs ( L_10 , V_43 ) ;
fputs ( L_48 V_97 L_17 , V_43 ) ;
fprintf ( V_43 , L_49 , V_49 , V_50 ) ;
fprintf ( V_43 , L_50 ) ;
for ( V_53 = 0 ; V_53 < V_96 -> V_98 ; V_53 ++ ) {
fprintf ( V_43 , L_51 ) ;
F_22 ( V_43 , V_96 -> V_99 [ V_53 ] . V_100 ) ;
fprintf ( V_43 , L_52 ) ;
}
fprintf ( V_43 , L_53 ) ;
}
void
F_38 ( T_3 * V_8 , T_12 * V_43 )
{
T_20 V_53 ;
fprintf ( V_43 , L_19 ) ;
for ( V_53 = 0 ; V_53 < V_8 -> V_15 . V_96 -> V_98 ; V_53 ++ ) {
fprintf ( V_43 , L_51 ) ;
F_22 ( V_43 , V_8 -> V_15 . V_96 -> V_99 [ V_53 ] . V_101 ) ;
fprintf ( V_43 , L_52 ) ;
}
fprintf ( V_43 , L_20 ) ;
}
void
F_39 ( T_12 * V_43 )
{
fputs ( L_54 , V_43 ) ;
}
static T_11 * F_40 ( const T_11 * V_102 , const T_11 * V_103 )
{
T_11 * V_104 ;
T_11 * V_105 ;
V_104 = F_41 ( V_102 , V_103 ) ;
V_105 = V_104 ;
while ( ( V_105 = strstr ( V_105 , L_55 ) ) != NULL ) {
V_105 [ 0 ] = ' ' ;
V_105 [ 1 ] = '>' ;
V_105 [ 2 ] = ' ' ;
}
V_105 = V_104 ;
while ( ( V_105 = strstr ( V_105 , L_56 ) ) != NULL )
* V_105 = '\"' ;
return V_104 ;
}
static void F_42 ( const char * V_106 , char V_107 , T_12 * V_43 )
{
T_11 * V_104 ;
V_104 = F_40 ( V_106 , L_55 ) ;
fprintf ( V_43 , L_57 , V_104 , V_107 ) ;
F_13 ( V_104 ) ;
}
void
F_43 ( T_19 * V_96 , T_12 * V_43 )
{
T_20 V_53 ;
for ( V_53 = 0 ; V_53 < V_96 -> V_98 - 1 ; V_53 ++ )
F_42 ( V_96 -> V_99 [ V_53 ] . V_100 , ',' , V_43 ) ;
F_42 ( V_96 -> V_99 [ V_53 ] . V_100 , '\n' , V_43 ) ;
}
void
F_44 ( T_3 * V_8 , T_12 * V_43 )
{
T_20 V_53 ;
for ( V_53 = 0 ; V_53 < V_8 -> V_15 . V_96 -> V_98 - 1 ; V_53 ++ )
F_42 ( V_8 -> V_15 . V_96 -> V_99 [ V_53 ] . V_101 , ',' , V_43 ) ;
F_42 ( V_8 -> V_15 . V_96 -> V_99 [ V_53 ] . V_101 , '\n' , V_43 ) ;
}
void
F_45 ( T_16 V_86 , T_12 * V_43 , T_3 * V_8 )
{
T_16 V_53 = 0 , V_108 = 0 ;
T_21 * V_109 ;
T_22 * V_110 ;
char * V_111 ;
const T_23 * V_112 ;
V_71 V_37 ;
char V_113 [ 9 ] ;
struct V_114 * V_115 ;
for ( V_109 = V_8 -> V_15 . V_16 ; V_109 != NULL ; V_109 = V_109 -> V_116 ) {
memset ( V_113 , 0 , sizeof( V_113 ) ) ;
V_115 = (struct V_114 * ) V_109 -> V_11 ;
V_110 = F_46 ( V_115 ) ;
V_37 = F_47 ( V_110 ) ;
if ( V_37 == 0 )
continue;
V_112 = F_48 ( V_110 , 0 , V_37 ) ;
V_111 = F_49 ( V_115 ) ;
if ( V_111 ) {
fprintf ( V_43 , L_58 , V_111 ) ;
F_35 ( NULL , V_111 ) ;
}
if ( V_108 ) {
fprintf ( V_43 , L_59 ,
V_86 , V_108 , V_37 ) ;
} else {
fprintf ( V_43 , L_60 ,
V_86 , V_37 ) ;
}
V_108 ++ ;
for ( V_53 = 0 ; V_53 < V_37 ; V_53 ++ ) {
fprintf ( V_43 , L_61 , * ( V_112 + V_53 ) ) ;
V_113 [ V_53 % 8 ] = F_50 ( * ( V_112 + V_53 ) ) ? * ( V_112 + V_53 ) : '.' ;
if ( V_53 == ( V_37 - 1 ) ) {
V_71 V_117 ;
V_117 = V_37 % 8 ;
if ( V_117 ) {
V_71 V_118 ;
for ( V_118 = 0 ; V_118 < 8 - V_117 ; V_118 ++ )
fprintf ( V_43 , L_62 ) ;
}
fprintf ( V_43 , L_63 , V_113 ) ;
break;
}
if ( ! ( ( V_53 + 1 ) % 8 ) ) {
fprintf ( V_43 , L_64 , V_113 ) ;
memset ( V_113 , 0 , sizeof( V_113 ) ) ;
}
else {
fprintf ( V_43 , L_65 ) ;
}
}
}
}
static const T_10 *
F_15 ( T_21 * V_14 , T_9 * V_26 )
{
T_21 * V_109 ;
T_22 * V_119 ;
T_20 V_37 , V_120 ;
struct V_114 * V_115 ;
for ( V_109 = V_14 ; V_109 != NULL ; V_109 = V_109 -> V_116 ) {
V_115 = (struct V_114 * ) V_109 -> V_11 ;
V_119 = F_46 ( V_115 ) ;
if ( V_26 -> V_121 == V_119 ) {
V_120 = F_51 ( V_119 ,
V_26 -> V_59 ) ;
if ( V_120 < 0 ) {
return NULL ;
}
V_37 = V_26 -> V_37 ;
if ( V_37 > V_120 )
V_37 = V_120 ;
return F_48 ( V_119 , V_26 -> V_59 , V_37 ) ;
}
}
F_29 () ;
return NULL ;
}
static void
F_22 ( T_12 * V_43 , const char * V_122 )
{
const char * V_123 ;
char V_124 [ 8 ] ;
for ( V_123 = V_122 ; * V_123 != '\0' ; V_123 ++ ) {
switch ( * V_123 ) {
case '&' :
fputs ( L_66 , V_43 ) ;
break;
case '<' :
fputs ( L_67 , V_43 ) ;
break;
case '>' :
fputs ( L_68 , V_43 ) ;
break;
case '"' :
fputs ( L_69 , V_43 ) ;
break;
case '\'' :
fputs ( L_70 , V_43 ) ;
break;
default:
if ( F_50 ( * V_123 ) )
fputc ( * V_123 , V_43 ) ;
else {
F_52 ( V_124 , sizeof( V_124 ) , L_71 , ( T_10 ) * V_123 ) ;
fputs ( V_124 , V_43 ) ;
}
}
}
}
static void
F_23 ( T_14 * V_27 , T_9 * V_26 )
{
int V_53 ;
const T_10 * V_28 ;
if ( ! V_26 -> V_121 )
return;
if ( V_26 -> V_37 > F_51 ( V_26 -> V_121 , V_26 -> V_59 ) ) {
fprintf ( V_27 -> V_43 , L_72 ) ;
return;
}
V_28 = F_15 ( V_27 -> V_14 , V_26 ) ;
if ( V_28 ) {
for ( V_53 = 0 ; V_53 < V_26 -> V_37 ; V_53 ++ ) {
fprintf ( V_27 -> V_43 , L_73 , V_28 [ V_53 ] ) ;
}
}
}
T_1
F_53 ( T_5 * V_10 , T_3 * V_8 )
{
T_1 V_125 ;
T_21 * V_109 ;
T_22 * V_110 ;
char * line , * V_111 ;
const T_23 * V_112 ;
V_71 V_37 ;
struct V_114 * V_115 ;
V_125 = ( V_8 -> V_15 . V_16 -> V_116 != NULL ) ;
for ( V_109 = V_8 -> V_15 . V_16 ; V_109 != NULL ;
V_109 = V_109 -> V_116 ) {
V_115 = (struct V_114 * ) V_109 -> V_11 ;
V_110 = F_46 ( V_115 ) ;
if ( V_125 ) {
V_111 = F_49 ( V_115 ) ;
line = F_54 ( L_74 , V_111 ) ;
F_35 ( NULL , V_111 ) ;
F_12 ( V_10 , 0 , line ) ;
F_13 ( line ) ;
}
V_37 = F_47 ( V_110 ) ;
if ( V_37 == 0 )
return TRUE ;
V_112 = F_48 ( V_110 , 0 , V_37 ) ;
if ( ! F_16 ( V_10 , V_112 , V_37 ,
V_8 -> V_15 . V_18 -> V_19 . V_17 ) )
return FALSE ;
}
return TRUE ;
}
static T_1
F_16 ( T_5 * V_10 , const T_23 * V_112 ,
V_71 V_37 , T_24 V_17 )
{
register unsigned int V_126 , V_53 , V_118 , V_127 , V_128 ;
T_23 V_129 ;
T_11 line [ V_130 + 1 ] ;
unsigned int V_131 ;
static T_11 V_132 [ 16 ] = {
'0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' ,
'8' , '9' , 'a' , 'b' , 'c' , 'd' , 'e' , 'f' } ;
if ( ( ( V_37 - 1 ) & 0xF0000000 ) != 0 )
V_131 = 8 ;
else if ( ( ( V_37 - 1 ) & 0x0F000000 ) != 0 )
V_131 = 7 ;
else if ( ( ( V_37 - 1 ) & 0x00F00000 ) != 0 )
V_131 = 6 ;
else if ( ( ( V_37 - 1 ) & 0x000F0000 ) != 0 )
V_131 = 5 ;
else
V_131 = 4 ;
V_126 = 0 ;
V_53 = 0 ;
V_118 = 0 ;
V_127 = 0 ;
while ( V_53 < V_37 ) {
if ( ( V_53 & 15 ) == 0 ) {
V_118 = 0 ;
V_128 = V_131 ;
do {
V_128 -- ;
V_129 = ( V_126 >> ( V_128 * 4 ) ) & 0xF ;
line [ V_118 ++ ] = V_132 [ V_129 ] ;
} while ( V_128 != 0 );
line [ V_118 ++ ] = ' ' ;
line [ V_118 ++ ] = ' ' ;
memset ( line + V_118 , ' ' , V_133 ) ;
V_127 = V_118 + V_134 + 2 ;
}
V_129 = * V_112 ++ ;
line [ V_118 ++ ] = V_132 [ V_129 >> 4 ] ;
line [ V_118 ++ ] = V_132 [ V_129 & 0xf ] ;
V_118 ++ ;
if ( V_17 == V_135 ) {
V_129 = F_55 ( V_129 ) ;
}
line [ V_127 ++ ] = ( ( V_129 >= ' ' ) && ( V_129 < 0x7f ) ) ? V_129 : '.' ;
V_53 ++ ;
if ( ( ( V_53 & 15 ) == 0 ) || ( V_53 == V_37 ) ) {
line [ V_127 ] = '\0' ;
if ( ! F_12 ( V_10 , 0 , line ) )
return FALSE ;
V_126 += 16 ;
}
}
return TRUE ;
}
T_25 F_56 ( T_26 * V_136 )
{
F_7 ( V_136 ) ;
if ( NULL == V_136 -> V_136 ) {
return 0 ;
} else {
return V_136 -> V_136 -> V_87 ;
}
}
void F_57 ( T_26 * V_136 )
{
F_7 ( V_136 ) ;
if ( NULL != V_136 -> V_136 ) {
T_25 V_53 ;
if ( NULL != V_136 -> V_137 ) {
F_58 ( V_136 -> V_137 ) ;
}
if ( NULL != V_136 -> V_138 ) {
F_13 ( V_136 -> V_138 ) ;
}
for( V_53 = 0 ; V_53 < V_136 -> V_136 -> V_87 ; ++ V_53 ) {
T_11 * V_139 = ( T_11 * ) F_59 ( V_136 -> V_136 , V_53 ) ;
F_13 ( V_139 ) ;
}
F_32 ( V_136 -> V_136 , TRUE ) ;
}
F_13 ( V_136 ) ;
}
void F_60 ( T_26 * V_136 , const T_11 * V_139 )
{
T_11 * V_140 ;
F_7 ( V_136 ) ;
F_7 ( V_139 ) ;
if ( NULL == V_136 -> V_136 ) {
V_136 -> V_136 = F_61 () ;
}
V_140 = F_62 ( V_139 ) ;
F_63 ( V_136 -> V_136 , V_140 ) ;
if ( ! strncmp ( V_139 , V_141 , strlen ( V_141 ) ) )
V_136 -> V_142 = TRUE ;
}
static void
F_64 ( void * V_11 , void * V_143 )
{
T_11 * V_139 = ( T_11 * ) V_11 ;
T_21 * * V_144 = ( T_21 * * ) V_143 ;
if ( ! strncmp ( V_139 , V_141 , strlen ( V_141 ) ) )
return;
if ( ! F_65 ( V_139 ) ) {
* V_144 = F_66 ( * V_144 , V_139 ) ;
}
}
T_21 *
F_67 ( T_26 * V_136 )
{
T_21 * V_144 = NULL ;
if ( V_136 -> V_136 == NULL ) {
return NULL ;
}
F_68 ( V_136 -> V_136 , F_64 , & V_144 ) ;
return V_144 ;
}
T_1 F_69 ( T_26 * V_145 , T_11 * V_146 )
{
const T_11 * V_147 ;
const T_11 * V_148 ;
F_7 ( V_145 ) ;
F_7 ( V_146 ) ;
if ( '\0' == * V_146 ) {
return FALSE ;
}
V_147 = strtok ( V_146 , L_75 ) ;
if ( ! V_147 ) {
return FALSE ;
}
V_148 = V_146 + strlen ( V_147 ) + 1 ;
if ( * V_148 == '\0' ) {
return FALSE ;
}
if ( 0 == strcmp ( V_147 , L_76 ) ) {
switch ( * V_148 ) {
case 'n' :
V_145 -> V_149 = FALSE ;
break;
case 'y' :
V_145 -> V_149 = TRUE ;
break;
default:
return FALSE ;
}
return TRUE ;
}
else if ( 0 == strcmp ( V_147 , L_77 ) ) {
switch ( * V_148 ) {
case '/' :
switch ( * ++ V_148 ) {
case 't' :
V_145 -> V_150 = '\t' ;
break;
case 's' :
V_145 -> V_150 = ' ' ;
break;
default:
V_145 -> V_150 = '\\' ;
}
break;
default:
V_145 -> V_150 = * V_148 ;
break;
}
return TRUE ;
}
else if ( 0 == strcmp ( V_147 , L_78 ) ) {
switch ( * V_148 ) {
case 'f' :
case 'l' :
case 'a' :
V_145 -> V_151 = * V_148 ;
break;
default:
return FALSE ;
}
return TRUE ;
}
else if ( 0 == strcmp ( V_147 , L_79 ) ) {
switch ( * V_148 ) {
case '/' :
switch ( * ++ V_148 ) {
case 's' :
V_145 -> V_152 = ' ' ;
break;
default:
V_145 -> V_152 = '\\' ;
}
break;
default:
V_145 -> V_152 = * V_148 ;
break;
}
return TRUE ;
}
else if ( 0 == strcmp ( V_147 , L_80 ) ) {
switch ( * V_148 ) {
case 'd' :
V_145 -> V_153 = '"' ;
break;
case 's' :
V_145 -> V_153 = '\'' ;
break;
case 'n' :
V_145 -> V_153 = '\0' ;
break;
default:
V_145 -> V_153 = '\0' ;
return FALSE ;
}
return TRUE ;
}
return FALSE ;
}
void F_70 ( T_12 * V_43 )
{
fprintf ( V_43 , L_81 ) ;
fputs ( L_82 , V_43 ) ;
fputs ( L_83 , V_43 ) ;
fputs ( L_84 , V_43 ) ;
fputs ( L_85 , V_43 ) ;
fputs ( L_86 , V_43 ) ;
}
T_1 F_71 ( T_26 * V_136 )
{
F_7 ( V_136 ) ;
return V_136 -> V_142 ;
}
void F_72 ( T_26 * V_136 , T_12 * V_43 )
{
T_25 V_53 ;
F_7 ( V_136 ) ;
F_7 ( V_43 ) ;
F_7 ( V_136 -> V_136 ) ;
if ( ! V_136 -> V_149 ) {
return;
}
for( V_53 = 0 ; V_53 < V_136 -> V_136 -> V_87 ; ++ V_53 ) {
const T_11 * V_139 = ( const T_11 * ) F_59 ( V_136 -> V_136 , V_53 ) ;
if ( V_53 != 0 ) {
fputc ( V_136 -> V_150 , V_43 ) ;
}
fputs ( V_139 , V_43 ) ;
}
fputc ( '\n' , V_43 ) ;
}
static void F_73 ( T_26 * V_136 , T_8 V_154 , const T_11 * V_62 )
{
V_71 V_155 ;
T_18 * V_156 ;
if ( NULL == V_62 )
return;
V_155 = F_74 ( V_154 ) - 1 ;
if ( V_136 -> V_138 [ V_155 ] == NULL ) {
V_136 -> V_138 [ V_155 ] = F_61 () ;
}
V_156 = V_136 -> V_138 [ V_155 ] ;
switch ( V_136 -> V_151 ) {
case 'f' :
if ( F_31 ( V_156 ) != 0 )
return;
break;
case 'l' :
F_75 ( V_156 , 0 ) ;
break;
case 'a' :
if ( F_31 ( V_156 ) > 0 ) {
F_63 ( V_156 , ( T_8 ) F_54 ( L_87 , V_136 -> V_152 ) ) ;
}
break;
default:
F_29 () ;
break;
}
F_63 ( V_156 , ( T_8 ) V_62 ) ;
}
static void F_76 ( T_7 * V_25 , T_8 V_11 )
{
T_27 * V_157 ;
T_9 * V_26 ;
T_8 V_154 ;
V_157 = ( T_27 * ) V_11 ;
V_26 = F_6 ( V_25 ) ;
F_7 ( V_26 ) ;
V_154 = F_14 ( V_157 -> V_136 -> V_137 , V_26 -> V_34 -> V_35 ) ;
if ( NULL != V_154 ) {
F_73 ( V_157 -> V_136 , V_154 ,
F_77 ( V_26 , V_157 -> V_8 )
) ;
}
if ( V_25 -> V_42 != NULL ) {
F_5 ( V_25 , F_76 ,
V_157 ) ;
}
}
void F_78 ( T_26 * V_136 , T_3 * V_8 , T_19 * V_96 , T_12 * V_43 )
{
T_25 V_53 ;
T_20 V_158 ;
T_11 * V_159 ;
T_8 V_154 ;
T_27 V_11 ;
F_7 ( V_136 ) ;
F_7 ( V_136 -> V_136 ) ;
F_7 ( V_8 ) ;
F_7 ( V_43 ) ;
V_11 . V_136 = V_136 ;
V_11 . V_8 = V_8 ;
if ( NULL == V_136 -> V_137 ) {
V_136 -> V_137 = F_79 ( V_160 , V_161 ) ;
V_53 = 0 ;
while ( V_53 < V_136 -> V_136 -> V_87 ) {
T_11 * V_139 = ( T_11 * ) F_59 ( V_136 -> V_136 , V_53 ) ;
++ V_53 ;
F_80 ( V_136 -> V_137 , V_139 , F_81 ( V_53 ) ) ;
}
}
if ( NULL == V_136 -> V_138 )
V_136 -> V_138 = F_82 ( T_18 * , V_136 -> V_136 -> V_87 ) ;
F_5 ( V_8 -> V_23 , F_76 ,
& V_11 ) ;
if ( V_136 -> V_142 ) {
for ( V_158 = 0 ; V_158 < V_96 -> V_98 ; V_158 ++ ) {
V_159 = F_54 ( L_88 , V_141 , V_96 -> V_99 [ V_158 ] . V_100 ) ;
V_154 = F_14 ( V_136 -> V_137 , V_159 ) ;
F_13 ( V_159 ) ;
if ( NULL != V_154 ) {
F_73 ( V_136 , V_154 , F_62 ( V_96 -> V_99 [ V_158 ] . V_101 ) ) ;
}
}
}
for( V_53 = 0 ; V_53 < V_136 -> V_136 -> V_87 ; ++ V_53 ) {
if ( 0 != V_53 ) {
fputc ( V_136 -> V_150 , V_43 ) ;
}
if ( NULL != V_136 -> V_138 [ V_53 ] ) {
T_18 * V_156 ;
T_11 * V_106 ;
T_25 V_118 ;
V_156 = V_136 -> V_138 [ V_53 ] ;
if ( V_136 -> V_153 != '\0' ) {
fputc ( V_136 -> V_153 , V_43 ) ;
}
for ( V_118 = 0 ; V_118 < F_31 ( V_156 ) ; V_118 ++ ) {
V_106 = ( T_11 * ) F_59 ( V_156 , V_118 ) ;
fputs ( V_106 , V_43 ) ;
F_13 ( V_106 ) ;
}
if ( V_136 -> V_153 != '\0' ) {
fputc ( V_136 -> V_153 , V_43 ) ;
}
F_32 ( V_156 , TRUE ) ;
V_136 -> V_138 [ V_53 ] = NULL ;
}
}
}
void F_83 ( T_26 * V_136 V_162 , T_12 * V_43 V_162 )
{
}
T_11 * F_77 ( T_9 * V_26 , T_3 * V_8 )
{
if ( V_26 -> V_34 -> V_36 == V_56 ) {
if ( V_26 -> V_32 ) {
return F_62 ( V_26 -> V_32 -> V_33 ) ;
}
else {
return F_84 ( V_8 -> V_15 . V_16 , V_26 ) ;
}
}
else if ( V_26 -> V_34 -> V_36 == V_1 ) {
return F_84 ( V_8 -> V_15 . V_16 , V_26 ) ;
}
else {
T_11 * V_52 ;
switch ( V_26 -> V_34 -> type )
{
case V_55 :
if ( V_26 -> V_32 ) {
return F_62 ( V_26 -> V_32 -> V_33 ) ;
} else {
return F_62 ( V_26 -> V_34 -> V_35 ) ;
}
case V_61 :
return F_62 ( L_89 ) ;
default:
V_52 = F_24 ( & V_26 -> V_62 , V_63 , V_26 -> V_34 -> V_64 , NULL ) ;
if ( V_52 != NULL ) {
return V_52 ;
} else {
return F_84 ( V_8 -> V_15 . V_16 , V_26 ) ;
}
}
}
}
static T_11 *
F_84 ( T_21 * V_14 , T_9 * V_26 )
{
const T_10 * V_28 ;
if ( ! V_26 -> V_121 )
return NULL ;
if ( V_26 -> V_37 > F_51 ( V_26 -> V_121 , V_26 -> V_59 ) ) {
return F_62 ( L_72 ) ;
}
V_28 = F_15 ( V_14 , V_26 ) ;
if ( V_28 ) {
int V_53 ;
T_11 * V_163 ;
T_11 * V_123 ;
int V_87 ;
const int V_164 = 2 ;
V_87 = V_164 * V_26 -> V_37 ;
V_163 = ( T_11 * ) F_85 ( sizeof( T_11 ) * ( V_87 + 1 ) ) ;
V_163 [ V_87 ] = '\0' ;
V_123 = V_163 ;
for ( V_53 = 0 ; V_53 < V_26 -> V_37 ; V_53 ++ ) {
F_52 ( V_123 , V_164 + 1 , L_73 , V_28 [ V_53 ] ) ;
V_123 += V_164 ;
}
return V_163 ;
} else {
return NULL ;
}
}
T_26 * F_86 ( void )
{
T_26 * V_136 = F_87 ( T_26 , 1 ) ;
V_136 -> V_149 = FALSE ;
V_136 -> V_150 = '\t' ;
V_136 -> V_151 = 'a' ;
V_136 -> V_152 = ',' ;
V_136 -> V_136 = NULL ;
V_136 -> V_137 = NULL ;
V_136 -> V_138 = NULL ;
V_136 -> V_153 = '\0' ;
V_136 -> V_142 = FALSE ;
return V_136 ;
}
