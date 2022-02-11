static void
F_1 (
T_1 * V_1 ,
char * V_2 ,
char * V_3 ,
T_2 V_4 ,
int V_5 ,
T_3 V_6 ,
T_4 * V_7 ,
T_4 * V_8 )
{
T_5 * V_9 ;
for( V_9 = V_1 -> V_10 ; V_9 ; V_9 = V_9 -> V_11 ) {
if( ( V_9 -> V_4 == V_4 )
&& ( ! strcmp ( V_9 -> V_2 , V_2 ) )
&& ( ! strcmp ( V_9 -> V_3 , V_3 ) ) ) {
break;
}
}
if( ! V_9 ) {
V_9 = F_2 ( T_5 , 1 ) ;
V_9 -> V_11 = V_1 -> V_10 ;
V_1 -> V_10 = V_9 ;
V_9 -> V_2 = F_3 ( V_2 ) ;
V_9 -> V_3 = F_3 ( V_3 ) ;
V_9 -> V_4 = V_4 ;
V_9 -> V_12 = 0 ;
V_9 -> V_13 = 0 ;
V_9 -> V_14 = 0 ;
V_9 -> V_15 = 0 ;
memcpy ( & V_9 -> V_16 , V_7 , sizeof( V_9 -> V_16 ) ) ;
memcpy ( & V_9 -> V_17 , V_7 , sizeof( V_9 -> V_17 ) ) ;
memcpy ( & V_9 -> V_18 , V_8 , sizeof( V_9 -> V_18 ) ) ;
}
else {
if ( F_4 ( V_7 , & V_9 -> V_17 ) > 0 ) {
memcpy ( & V_9 -> V_17 , V_7 , sizeof( V_9 -> V_17 ) ) ;
} else if ( F_4 ( V_7 , & V_9 -> V_16 ) < 0 ) {
memcpy ( & V_9 -> V_16 , V_7 , sizeof( V_9 -> V_16 ) ) ;
memcpy ( & V_9 -> V_18 , V_8 , sizeof( V_9 -> V_18 ) ) ;
}
}
if( V_5 ) {
V_9 -> V_12 ++ ;
V_9 -> V_14 += V_6 ;
} else {
V_9 -> V_13 ++ ;
V_9 -> V_15 += V_6 ;
}
}
static void
F_5 ( T_1 * V_1 , const T_6 * V_19 , const T_6 * V_20 , T_3 V_6 ,
T_4 * V_21 )
{
const T_6 * V_22 , * V_23 ;
T_5 * V_9 ;
if( F_6 ( V_19 , V_20 ) > 0 ) {
V_22 = V_19 ;
V_23 = V_20 ;
} else {
V_23 = V_19 ;
V_22 = V_20 ;
}
for( V_9 = V_1 -> V_10 ; V_9 ; V_9 = V_9 -> V_11 ) {
if( ( ! F_6 ( & V_9 -> V_22 , V_22 ) )
&& ( ! F_6 ( & V_9 -> V_23 , V_23 ) ) ) {
break;
}
}
if( ! V_9 ) {
V_9 = F_2 ( T_5 , 1 ) ;
V_9 -> V_11 = V_1 -> V_10 ;
V_1 -> V_10 = V_9 ;
F_7 ( & V_9 -> V_22 , V_22 ) ;
V_9 -> V_2 = F_3 ( F_8 ( V_22 ) ) ;
F_7 ( & V_9 -> V_23 , V_23 ) ;
V_9 -> V_3 = F_3 ( F_8 ( V_23 ) ) ;
V_9 -> V_12 = 0 ;
V_9 -> V_13 = 0 ;
V_9 -> V_14 = 0 ;
V_9 -> V_15 = 0 ;
memcpy ( & V_9 -> V_16 , V_21 , sizeof( V_9 -> V_16 ) ) ;
memcpy ( & V_9 -> V_17 , V_21 , sizeof( V_9 -> V_17 ) ) ;
}
else {
if ( F_4 ( V_21 , & V_9 -> V_17 ) > 0 ) {
memcpy ( & V_9 -> V_17 , V_21 , sizeof( V_9 -> V_17 ) ) ;
} else if ( F_4 ( V_21 , & V_9 -> V_16 ) < 0 ) {
memcpy ( & V_9 -> V_16 , V_21 , sizeof( V_9 -> V_16 ) ) ;
}
}
if( ! F_6 ( V_20 , & V_9 -> V_22 ) ) {
V_9 -> V_12 ++ ;
V_9 -> V_14 += V_6 ;
} else {
V_9 -> V_13 ++ ;
V_9 -> V_15 += V_6 ;
}
}
static int
F_9 ( void * V_24 , T_7 * V_25 , T_8 * T_9 V_26 , const void * V_27 )
{
T_1 * V_1 = ( T_1 * ) V_24 ;
const T_10 * V_28 = ( const T_10 * ) V_27 ;
char V_2 [ 256 ] , V_3 [ 256 ] ;
int V_5 = 0 ;
if( V_28 -> V_29 > V_28 -> V_30 ) {
V_5 = 0 ;
F_10 ( V_2 , 256 , L_1 , F_8 ( & V_28 -> V_31 ) , F_11 ( V_28 -> V_29 ) ) ;
F_10 ( V_3 , 256 , L_1 , F_8 ( & V_28 -> V_32 ) , F_11 ( V_28 -> V_30 ) ) ;
} else if( V_28 -> V_29 < V_28 -> V_30 ) {
V_5 = 1 ;
F_10 ( V_3 , 256 , L_1 , F_8 ( & V_28 -> V_31 ) , F_11 ( V_28 -> V_29 ) ) ;
F_10 ( V_2 , 256 , L_1 , F_8 ( & V_28 -> V_32 ) , F_11 ( V_28 -> V_30 ) ) ;
} else if( F_6 ( & V_28 -> V_31 , & V_28 -> V_32 ) > 0 ) {
V_5 = 0 ;
F_10 ( V_2 , 256 , L_1 , F_8 ( & V_28 -> V_31 ) , F_11 ( V_28 -> V_29 ) ) ;
F_10 ( V_3 , 256 , L_1 , F_8 ( & V_28 -> V_32 ) , F_11 ( V_28 -> V_30 ) ) ;
} else {
V_5 = 1 ;
F_10 ( V_3 , 256 , L_1 , F_8 ( & V_28 -> V_31 ) , F_11 ( V_28 -> V_29 ) ) ;
F_10 ( V_2 , 256 , L_1 , F_8 ( & V_28 -> V_32 ) , F_11 ( V_28 -> V_30 ) ) ;
}
F_12 ( V_1 , V_2 , V_3 , V_5 , V_25 -> V_33 -> V_6 , & V_25 -> V_7 , & V_25 -> V_33 -> V_8 ) ;
return 1 ;
}
static int
F_13 ( void * V_24 , T_7 * V_25 , T_8 * T_9 V_26 , const void * V_34 )
{
T_1 * V_1 = ( T_1 * ) V_24 ;
const struct V_35 * V_36 = ( const struct V_35 * ) V_34 ;
char V_2 [ 256 ] , V_3 [ 256 ] , V_37 [ 10 ] , V_38 [ 10 ] ;
int V_5 = 0 ;
F_10 ( V_37 , sizeof V_37 , L_2 , V_36 -> V_39 ) ;
F_10 ( V_38 , sizeof V_38 , L_2 , V_36 -> V_40 ) ;
if( V_36 -> V_39 > V_36 -> V_40 ) {
V_5 = 0 ;
F_10 ( V_2 , 256 , L_1 , F_8 ( & V_36 -> V_31 ) , V_37 ) ;
F_10 ( V_3 , 256 , L_1 , F_8 ( & V_36 -> V_32 ) , V_38 ) ;
} else if( V_36 -> V_39 < V_36 -> V_40 ) {
V_5 = 1 ;
F_10 ( V_2 , 256 , L_1 , F_8 ( & V_36 -> V_31 ) , V_37 ) ;
F_10 ( V_3 , 256 , L_1 , F_8 ( & V_36 -> V_32 ) , V_38 ) ;
} else {
V_5 = 0 ;
F_10 ( V_2 , 256 , L_1 , F_8 ( & V_36 -> V_31 ) , V_37 ) ;
F_10 ( V_3 , 256 , L_1 , F_8 ( & V_36 -> V_32 ) , V_38 ) ;
}
F_12 ( V_1 , V_2 , V_3 , V_5 , V_25 -> V_33 -> V_6 , & V_25 -> V_7 , & V_25 -> V_33 -> V_8 ) ;
return 1 ;
}
static int
F_14 ( void * V_24 , T_7 * V_25 , T_8 * T_9 V_26 , const void * V_41 )
{
T_1 * V_1 = ( T_1 * ) V_24 ;
const struct V_42 * V_43 = ( const struct V_42 * ) V_41 ;
char V_2 [ 256 ] , V_3 [ 256 ] ;
int V_5 = 0 ;
if( V_43 -> V_44 > V_43 -> V_45 ) {
V_5 = 0 ;
F_10 ( V_2 , 256 , L_1 , F_8 ( & V_43 -> V_31 ) , F_15 ( V_43 -> V_44 ) ) ;
F_10 ( V_3 , 256 , L_1 , F_8 ( & V_43 -> V_32 ) , F_15 ( V_43 -> V_45 ) ) ;
} else if( V_43 -> V_44 < V_43 -> V_45 ) {
V_5 = 1 ;
F_10 ( V_3 , 256 , L_1 , F_8 ( & V_43 -> V_31 ) , F_15 ( V_43 -> V_44 ) ) ;
F_10 ( V_2 , 256 , L_1 , F_8 ( & V_43 -> V_32 ) , F_15 ( V_43 -> V_45 ) ) ;
} else if( F_6 ( & V_43 -> V_31 , & V_43 -> V_32 ) > 0 ) {
V_5 = 0 ;
F_10 ( V_2 , 256 , L_1 , F_8 ( & V_43 -> V_31 ) , F_15 ( V_43 -> V_44 ) ) ;
F_10 ( V_3 , 256 , L_1 , F_8 ( & V_43 -> V_32 ) , F_15 ( V_43 -> V_45 ) ) ;
} else {
V_5 = 1 ;
F_10 ( V_3 , 256 , L_1 , F_8 ( & V_43 -> V_31 ) , F_15 ( V_43 -> V_44 ) ) ;
F_10 ( V_2 , 256 , L_1 , F_8 ( & V_43 -> V_32 ) , F_15 ( V_43 -> V_45 ) ) ;
}
F_1 ( V_1 , V_2 , V_3 , V_43 -> V_46 , V_5 , V_25 -> V_33 -> V_6 , & V_25 -> V_7 , & V_25 -> V_33 -> V_8 ) ;
return 1 ;
}
static int
F_16 ( void * V_24 , T_7 * V_25 , T_8 * T_9 V_26 , const void * V_47 )
{
T_1 * V_1 = ( T_1 * ) V_24 ;
const T_11 * V_48 = ( const T_11 * ) V_47 ;
F_5 ( V_1 , & V_48 -> V_31 , & V_48 -> V_32 , V_25 -> V_33 -> V_6 , & V_25 -> V_7 ) ;
return 1 ;
}
static int
F_17 ( void * V_24 , T_7 * V_25 , T_8 * T_9 V_26 , const void * V_47 )
{
T_1 * V_1 = ( T_1 * ) V_24 ;
const struct V_49 * V_50 = ( const struct V_49 * ) V_47 ;
T_6 V_19 , V_20 ;
V_19 . type = V_20 . type = V_51 ;
V_19 . V_52 = V_20 . V_52 = sizeof( struct V_53 ) ;
V_19 . V_54 = & V_50 -> V_55 ;
V_20 . V_54 = & V_50 -> V_56 ;
F_5 ( V_1 , & V_19 , & V_20 , V_25 -> V_33 -> V_6 , & V_25 -> V_7 ) ;
return 1 ;
}
static int
F_18 ( void * V_24 , T_7 * V_25 , T_8 * T_9 V_26 , const void * V_57 )
{
T_1 * V_1 = ( T_1 * ) V_24 ;
const T_12 * V_58 = ( const T_12 * ) V_57 ;
F_5 ( V_1 , & V_58 -> V_59 , & V_58 -> V_60 , V_25 -> V_33 -> V_6 , & V_25 -> V_7 ) ;
return 1 ;
}
static int
F_19 ( void * V_24 , T_7 * V_25 , T_8 * T_9 V_26 , const void * V_61 )
{
T_1 * V_1 = ( T_1 * ) V_24 ;
const T_13 * V_62 = ( const T_13 * ) V_61 ;
F_5 ( V_1 , & V_62 -> V_63 , & V_62 -> V_64 , V_25 -> V_33 -> V_6 , & V_25 -> V_7 ) ;
return 1 ;
}
static int
F_20 ( void * V_24 , T_7 * V_25 , T_8 * T_9 V_26 , const void * V_65 )
{
T_1 * V_1 = ( T_1 * ) V_24 ;
const T_14 * V_66 = ( const T_14 * ) V_65 ;
F_5 ( V_1 , & V_66 -> V_19 , & V_66 -> V_20 , V_25 -> V_33 -> V_6 , & V_25 -> V_7 ) ;
return 1 ;
}
static int
F_21 ( void * V_24 , T_7 * V_25 , T_8 * T_9 V_26 , const void * V_65 )
{
T_1 * V_1 = ( T_1 * ) V_24 ;
const T_15 * V_66 = ( const T_15 * ) V_65 ;
F_5 ( V_1 , & V_66 -> V_19 , & V_66 -> V_20 , V_25 -> V_33 -> V_6 , & V_25 -> V_7 ) ;
return 1 ;
}
static int
F_22 ( void * V_24 , T_7 * V_25 , T_8 * T_9 V_26 , const void * V_67 )
{
T_1 * V_1 = ( T_1 * ) V_24 ;
const T_16 * V_68 = ( const T_16 * ) V_67 ;
F_5 ( V_1 , & V_68 -> V_19 , & V_68 -> V_20 , V_25 -> V_33 -> V_6 , & V_25 -> V_7 ) ;
return 1 ;
}
static void
F_23 ( void * V_24 )
{
T_1 * V_1 = ( T_1 * ) V_24 ;
T_5 * V_9 ;
T_17 V_69 , V_70 ;
struct V_71 * V_72 ;
printf ( L_3 ) ;
printf ( L_4 , V_1 -> type ) ;
printf ( L_5 , V_1 -> V_73 ? V_1 -> V_73 : L_6 ) ;
switch ( F_24 () ) {
case V_74 :
printf ( L_7 ) ;
printf ( L_8 ) ;
break;
case V_75 :
printf ( L_9 ) ;
printf ( L_10 ) ;
break;
case V_76 :
case V_77 :
default:
printf ( L_11 ) ;
printf ( L_8 ) ;
break;
}
V_70 = 0xffffffff ;
do {
V_69 = 0 ;
for( V_9 = V_1 -> V_10 ; V_9 ; V_9 = V_9 -> V_11 ) {
T_17 V_78 ;
V_78 = V_9 -> V_12 + V_9 -> V_13 ;
if( ( V_78 > V_69 )
&& ( V_78 < V_70 ) ) {
V_69 = V_78 ;
}
}
for( V_9 = V_1 -> V_10 ; V_9 ; V_9 = V_9 -> V_11 ) {
T_17 V_78 ;
V_78 = V_9 -> V_12 + V_9 -> V_13 ;
if( V_78 == V_69 ) {
printf ( L_12 V_79 L_13 V_79 L_13 V_79 L_14 ,
V_9 -> V_2 , V_9 -> V_3 ,
V_9 -> V_12 , V_9 -> V_14 ,
V_9 -> V_13 , V_9 -> V_15 ,
V_9 -> V_12 + V_9 -> V_13 ,
V_9 -> V_14 + V_9 -> V_15
) ;
V_72 = localtime ( & V_9 -> V_18 . V_80 ) ;
switch ( F_24 () ) {
case V_74 :
printf ( L_15 ,
V_72 -> V_81 ,
V_72 -> V_82 ,
V_72 -> V_83 ,
F_25 ( & V_9 -> V_17 ) - F_25 ( & V_9 -> V_16 ) ) ;
break;
case V_75 :
printf ( L_16 ,
V_72 -> V_84 + 1900 ,
V_72 -> V_85 + 1 ,
V_72 -> V_86 ,
V_72 -> V_81 ,
V_72 -> V_82 ,
V_72 -> V_83 ,
F_25 ( & V_9 -> V_17 ) - F_25 ( & V_9 -> V_16 ) ) ;
break;
case V_76 :
case V_77 :
default:
printf ( L_17 ,
F_25 ( & V_9 -> V_16 ) ,
F_25 ( & V_9 -> V_17 ) - F_25 ( & V_9 -> V_16 )
) ;
break;
}
}
}
V_70 = V_69 ;
} while( V_69 );
printf ( L_3 ) ;
}
static void
F_26 ( const char * V_87 , void * T_18 V_26 )
{
const char * V_73 = NULL ;
const char * V_88 , * V_89 ;
T_19 V_90 ;
T_1 * V_1 = NULL ;
T_20 * V_91 ;
if( ! strncmp ( V_87 , L_18 , 8 ) ) {
if( V_87 [ 8 ] == ',' ) {
V_73 = V_87 + 9 ;
} else {
V_73 = NULL ;
}
V_88 = L_19 ;
V_89 = L_20 ;
V_90 = F_20 ;
} else if( ! strncmp ( V_87 , L_21 , 7 ) ) {
if( V_87 [ 7 ] == ',' ) {
V_73 = V_87 + 8 ;
} else {
V_73 = NULL ;
}
V_88 = L_22 ;
V_89 = L_23 ;
V_90 = F_19 ;
} else if( ! strncmp ( V_87 , L_24 , 9 ) ) {
if( V_87 [ 9 ] == ',' ) {
V_73 = V_87 + 10 ;
} else {
V_73 = NULL ;
}
V_88 = L_25 ;
V_89 = L_26 ;
V_90 = F_21 ;
} else if( ! strncmp ( V_87 , L_27 , 8 ) ) {
if( V_87 [ 8 ] == ',' ) {
V_73 = V_87 + 9 ;
} else {
V_73 = NULL ;
}
V_88 = L_28 ;
V_89 = L_29 ;
V_90 = F_14 ;
} else if( ! strncmp ( V_87 , L_30 , 8 ) ) {
if( V_87 [ 8 ] == ',' ) {
V_73 = V_87 + 9 ;
} else {
V_73 = NULL ;
}
V_88 = L_31 ;
V_89 = L_32 ;
V_90 = F_9 ;
} else if( ! strncmp ( V_87 , L_33 , 7 ) ) {
if( V_87 [ 7 ] == ',' ) {
V_73 = V_87 + 8 ;
} else {
V_73 = NULL ;
}
V_88 = L_34 ;
V_89 = L_35 ;
V_90 = F_22 ;
} else if( ! strncmp ( V_87 , L_36 , 8 ) ) {
if( V_87 [ 8 ] == ',' ) {
V_73 = V_87 + 9 ;
} else {
V_73 = NULL ;
}
V_88 = L_37 ;
V_89 = L_38 ;
V_90 = F_18 ;
} else if( ! strncmp ( V_87 , L_39 , 9 ) ) {
if( V_87 [ 9 ] == ',' ) {
V_73 = V_87 + 10 ;
} else {
V_73 = NULL ;
}
V_88 = L_40 ;
V_89 = L_41 ;
V_90 = F_17 ;
} else if( ! strncmp ( V_87 , L_42 , 7 ) ) {
if( V_87 [ 7 ] == ',' ) {
V_73 = V_87 + 8 ;
} else {
V_73 = NULL ;
}
V_88 = L_43 ;
V_89 = L_44 ;
V_90 = F_16 ;
} else if( ! strncmp ( V_87 , L_45 , 9 ) ) {
if( V_87 [ 9 ] == ',' ) {
V_73 = V_87 + 10 ;
} else {
V_73 = NULL ;
}
V_88 = L_46 ;
V_89 = L_47 ;
V_90 = F_13 ;
} else {
fprintf ( V_92 , L_48 ) ;
fprintf ( V_92 , L_49 ) ;
fprintf ( V_92 , L_50 ) ;
fprintf ( V_92 , L_51 ) ;
fprintf ( V_92 , L_52 ) ;
fprintf ( V_92 , L_53 ) ;
fprintf ( V_92 , L_54 ) ;
fprintf ( V_92 , L_55 ) ;
fprintf ( V_92 , L_56 ) ;
fprintf ( V_92 , L_57 ) ;
fprintf ( V_92 , L_58 ) ;
exit ( 1 ) ;
}
V_1 = F_2 ( T_1 , 1 ) ;
V_1 -> V_10 = NULL ;
V_1 -> type = V_89 ;
if( V_73 ) {
V_1 -> V_73 = F_3 ( V_73 ) ;
} else {
V_1 -> V_73 = NULL ;
}
V_91 = F_27 ( V_88 , V_1 , V_73 , 0 , NULL , V_90 , F_23 ) ;
if( V_91 ) {
if( V_1 -> V_10 ) {
F_28 ( V_1 -> V_10 ) ;
}
F_28 ( V_1 ) ;
fprintf ( V_92 , L_59 ,
V_91 -> V_93 ) ;
F_29 ( V_91 , TRUE ) ;
exit ( 1 ) ;
}
}
void
F_30 ( void )
{
F_31 ( L_60 , F_26 , NULL ) ;
}
