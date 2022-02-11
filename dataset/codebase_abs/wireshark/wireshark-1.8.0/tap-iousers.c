void
F_1 (
T_1 * V_1 ,
char * V_2 ,
char * V_3 ,
T_2 V_4 ,
int V_5 ,
T_3 V_6 ,
T_4 * V_7 )
{
T_5 * V_8 ;
for( V_8 = V_1 -> V_9 ; V_8 ; V_8 = V_8 -> V_10 ) {
if( ( V_8 -> V_4 == V_4 )
&& ( ! strcmp ( V_8 -> V_2 , V_2 ) )
&& ( ! strcmp ( V_8 -> V_3 , V_3 ) ) ) {
break;
}
}
if( ! V_8 ) {
V_8 = F_2 ( sizeof( T_5 ) ) ;
V_8 -> V_10 = V_1 -> V_9 ;
V_1 -> V_9 = V_8 ;
V_8 -> V_2 = F_3 ( V_2 ) ;
V_8 -> V_3 = F_3 ( V_3 ) ;
V_8 -> V_4 = V_4 ;
V_8 -> V_11 = 0 ;
V_8 -> V_12 = 0 ;
V_8 -> V_13 = 0 ;
V_8 -> V_14 = 0 ;
memcpy ( & V_8 -> V_15 , V_7 , sizeof( V_8 -> V_15 ) ) ;
memcpy ( & V_8 -> V_16 , V_7 , sizeof( V_8 -> V_16 ) ) ;
}
else {
if ( F_4 ( V_7 , & V_8 -> V_16 ) > 0 ) {
memcpy ( & V_8 -> V_16 , V_7 , sizeof( V_8 -> V_16 ) ) ;
} else if ( F_4 ( V_7 , & V_8 -> V_15 ) < 0 ) {
memcpy ( & V_8 -> V_15 , V_7 , sizeof( V_8 -> V_15 ) ) ;
}
}
if( V_5 ) {
V_8 -> V_11 ++ ;
V_8 -> V_13 += V_6 ;
} else {
V_8 -> V_12 ++ ;
V_8 -> V_14 += V_6 ;
}
}
void
F_5 ( T_1 * V_1 , const T_6 * V_17 , const T_6 * V_18 , T_3 V_6 , T_4 * V_7 )
{
const T_6 * V_19 , * V_20 ;
T_5 * V_8 ;
if( F_6 ( V_17 , V_18 ) > 0 ) {
V_19 = V_17 ;
V_20 = V_18 ;
} else {
V_20 = V_17 ;
V_19 = V_18 ;
}
for( V_8 = V_1 -> V_9 ; V_8 ; V_8 = V_8 -> V_10 ) {
if( ( ! F_6 ( & V_8 -> V_19 , V_19 ) )
&& ( ! F_6 ( & V_8 -> V_20 , V_20 ) ) ) {
break;
}
}
if( ! V_8 ) {
V_8 = F_2 ( sizeof( T_5 ) ) ;
V_8 -> V_10 = V_1 -> V_9 ;
V_1 -> V_9 = V_8 ;
F_7 ( & V_8 -> V_19 , V_19 ) ;
V_8 -> V_2 = F_3 ( F_8 ( V_19 ) ) ;
F_7 ( & V_8 -> V_20 , V_20 ) ;
V_8 -> V_3 = F_3 ( F_8 ( V_20 ) ) ;
V_8 -> V_11 = 0 ;
V_8 -> V_12 = 0 ;
V_8 -> V_13 = 0 ;
V_8 -> V_14 = 0 ;
memcpy ( & V_8 -> V_15 , V_7 , sizeof( V_8 -> V_15 ) ) ;
memcpy ( & V_8 -> V_16 , V_7 , sizeof( V_8 -> V_16 ) ) ;
}
else {
if ( F_4 ( V_7 , & V_8 -> V_16 ) > 0 ) {
memcpy ( & V_8 -> V_16 , V_7 , sizeof( V_8 -> V_16 ) ) ;
} else if ( F_4 ( V_7 , & V_8 -> V_15 ) < 0 ) {
memcpy ( & V_8 -> V_15 , V_7 , sizeof( V_8 -> V_15 ) ) ;
}
}
if( ! F_6 ( V_18 , & V_8 -> V_19 ) ) {
V_8 -> V_11 ++ ;
V_8 -> V_13 += V_6 ;
} else {
V_8 -> V_12 ++ ;
V_8 -> V_14 += V_6 ;
}
}
static int
F_9 ( void * V_21 , T_7 * V_22 , T_8 * T_9 V_23 , const void * V_24 )
{
T_1 * V_1 = V_21 ;
const T_10 * V_25 = V_24 ;
char V_2 [ 256 ] , V_3 [ 256 ] ;
int V_5 = 0 ;
if( V_25 -> V_26 > V_25 -> V_27 ) {
V_5 = 0 ;
F_10 ( V_2 , 256 , L_1 , F_8 ( & V_25 -> V_28 ) , F_11 ( V_25 -> V_26 ) ) ;
F_10 ( V_3 , 256 , L_1 , F_8 ( & V_25 -> V_29 ) , F_11 ( V_25 -> V_27 ) ) ;
} else if( V_25 -> V_26 < V_25 -> V_27 ) {
V_5 = 1 ;
F_10 ( V_3 , 256 , L_1 , F_8 ( & V_25 -> V_28 ) , F_11 ( V_25 -> V_26 ) ) ;
F_10 ( V_2 , 256 , L_1 , F_8 ( & V_25 -> V_29 ) , F_11 ( V_25 -> V_27 ) ) ;
} else if( F_6 ( & V_25 -> V_28 , & V_25 -> V_29 ) > 0 ) {
V_5 = 0 ;
F_10 ( V_2 , 256 , L_1 , F_8 ( & V_25 -> V_28 ) , F_11 ( V_25 -> V_26 ) ) ;
F_10 ( V_3 , 256 , L_1 , F_8 ( & V_25 -> V_29 ) , F_11 ( V_25 -> V_27 ) ) ;
} else {
V_5 = 1 ;
F_10 ( V_3 , 256 , L_1 , F_8 ( & V_25 -> V_28 ) , F_11 ( V_25 -> V_26 ) ) ;
F_10 ( V_2 , 256 , L_1 , F_8 ( & V_25 -> V_29 ) , F_11 ( V_25 -> V_27 ) ) ;
}
F_12 ( V_1 , V_2 , V_3 , V_5 , V_22 -> V_30 -> V_6 , & V_22 -> V_30 -> V_31 ) ;
return 1 ;
}
static int
F_13 ( void * V_21 , T_7 * V_22 , T_8 * T_9 V_23 , const void * V_32 )
{
T_1 * V_1 = V_21 ;
const struct V_33 * V_34 = V_32 ;
char V_2 [ 256 ] , V_3 [ 256 ] , V_35 [ 10 ] , V_36 [ 10 ] ;
int V_5 = 0 ;
F_10 ( V_35 , sizeof V_35 , L_2 , V_34 -> V_37 ) ;
F_10 ( V_36 , sizeof V_36 , L_2 , V_34 -> V_38 ) ;
if( V_34 -> V_37 > V_34 -> V_38 ) {
V_5 = 0 ;
F_10 ( V_2 , 256 , L_1 , F_8 ( & V_34 -> V_28 ) , V_35 ) ;
F_10 ( V_3 , 256 , L_1 , F_8 ( & V_34 -> V_29 ) , V_36 ) ;
} else if( V_34 -> V_37 < V_34 -> V_38 ) {
V_5 = 1 ;
F_10 ( V_2 , 256 , L_1 , F_8 ( & V_34 -> V_28 ) , V_35 ) ;
F_10 ( V_3 , 256 , L_1 , F_8 ( & V_34 -> V_29 ) , V_36 ) ;
} else {
V_5 = 0 ;
F_10 ( V_2 , 256 , L_1 , F_8 ( & V_34 -> V_28 ) , V_35 ) ;
F_10 ( V_3 , 256 , L_1 , F_8 ( & V_34 -> V_29 ) , V_36 ) ;
}
F_12 ( V_1 , V_2 , V_3 , V_5 , V_22 -> V_30 -> V_6 , & V_22 -> V_30 -> V_31 ) ;
return 1 ;
}
static int
F_14 ( void * V_21 , T_7 * V_22 , T_8 * T_9 V_23 , const void * V_39 )
{
T_1 * V_1 = V_21 ;
const struct V_40 * V_41 = V_39 ;
char V_2 [ 256 ] , V_3 [ 256 ] ;
int V_5 = 0 ;
if( V_41 -> V_42 > V_41 -> V_43 ) {
V_5 = 0 ;
F_10 ( V_2 , 256 , L_1 , F_8 ( & V_41 -> V_28 ) , F_15 ( V_41 -> V_42 ) ) ;
F_10 ( V_3 , 256 , L_1 , F_8 ( & V_41 -> V_29 ) , F_15 ( V_41 -> V_43 ) ) ;
} else if( V_41 -> V_42 < V_41 -> V_43 ) {
V_5 = 1 ;
F_10 ( V_3 , 256 , L_1 , F_8 ( & V_41 -> V_28 ) , F_15 ( V_41 -> V_42 ) ) ;
F_10 ( V_2 , 256 , L_1 , F_8 ( & V_41 -> V_29 ) , F_15 ( V_41 -> V_43 ) ) ;
} else if( F_6 ( & V_41 -> V_28 , & V_41 -> V_29 ) > 0 ) {
V_5 = 0 ;
F_10 ( V_2 , 256 , L_1 , F_8 ( & V_41 -> V_28 ) , F_15 ( V_41 -> V_42 ) ) ;
F_10 ( V_3 , 256 , L_1 , F_8 ( & V_41 -> V_29 ) , F_15 ( V_41 -> V_43 ) ) ;
} else {
V_5 = 1 ;
F_10 ( V_3 , 256 , L_1 , F_8 ( & V_41 -> V_28 ) , F_15 ( V_41 -> V_42 ) ) ;
F_10 ( V_2 , 256 , L_1 , F_8 ( & V_41 -> V_29 ) , F_15 ( V_41 -> V_43 ) ) ;
}
F_1 ( V_1 , V_2 , V_3 , V_41 -> V_44 , V_5 , V_22 -> V_30 -> V_6 , & V_22 -> V_30 -> V_31 ) ;
return 1 ;
}
static int
F_16 ( void * V_21 , T_7 * V_22 , T_8 * T_9 V_23 , const void * V_45 )
{
T_1 * V_1 = V_21 ;
const T_11 * V_46 = V_45 ;
F_5 ( V_1 , & V_46 -> V_28 , & V_46 -> V_29 , V_22 -> V_30 -> V_6 , & V_22 -> V_30 -> V_31 ) ;
return 1 ;
}
static int
F_17 ( void * V_21 , T_7 * V_22 , T_8 * T_9 V_23 , const void * V_45 )
{
T_1 * V_1 = V_21 ;
const struct V_47 * V_48 = V_45 ;
T_6 V_17 , V_18 ;
V_17 . type = V_18 . type = V_49 ;
V_17 . V_50 = V_18 . V_50 = sizeof( struct V_51 ) ;
V_17 . V_52 = & V_48 -> V_53 ;
V_18 . V_52 = & V_48 -> V_54 ;
F_5 ( V_1 , & V_17 , & V_18 , V_22 -> V_30 -> V_6 , & V_22 -> V_30 -> V_31 ) ;
return 1 ;
}
static int
F_18 ( void * V_21 , T_7 * V_22 , T_8 * T_9 V_23 , const void * V_55 )
{
T_1 * V_1 = V_21 ;
const T_12 * V_56 = V_55 ;
F_5 ( V_1 , & V_56 -> V_57 , & V_56 -> V_58 , V_22 -> V_30 -> V_6 , & V_22 -> V_30 -> V_31 ) ;
return 1 ;
}
static int
F_19 ( void * V_21 , T_7 * V_22 , T_8 * T_9 V_23 , const void * V_59 )
{
T_1 * V_1 = V_21 ;
const T_13 * V_60 = V_59 ;
F_5 ( V_1 , & V_60 -> V_61 , & V_60 -> V_62 , V_22 -> V_30 -> V_6 , & V_22 -> V_30 -> V_31 ) ;
return 1 ;
}
static int
F_20 ( void * V_21 , T_7 * V_22 , T_8 * T_9 V_23 , const void * V_63 )
{
T_1 * V_1 = V_21 ;
const T_14 * V_64 = V_63 ;
F_5 ( V_1 , & V_64 -> V_17 , & V_64 -> V_18 , V_22 -> V_30 -> V_6 , & V_22 -> V_30 -> V_31 ) ;
return 1 ;
}
static int
F_21 ( void * V_21 , T_7 * V_22 , T_8 * T_9 V_23 , const void * V_63 )
{
T_1 * V_1 = V_21 ;
const T_15 * V_64 = V_63 ;
F_5 ( V_1 , & V_64 -> V_17 , & V_64 -> V_18 , V_22 -> V_30 -> V_6 , & V_22 -> V_30 -> V_31 ) ;
return 1 ;
}
static int
F_22 ( void * V_21 , T_7 * V_22 , T_8 * T_9 V_23 , const void * V_65 )
{
T_1 * V_1 = V_21 ;
const T_16 * V_66 = V_65 ;
F_5 ( V_1 , & V_66 -> V_17 , & V_66 -> V_18 , V_22 -> V_30 -> V_6 , & V_22 -> V_30 -> V_31 ) ;
return 1 ;
}
static void
F_23 ( void * V_21 )
{
T_1 * V_1 = V_21 ;
T_5 * V_8 ;
T_17 V_67 , V_68 ;
printf ( L_3 ) ;
printf ( L_4 , V_1 -> type ) ;
printf ( L_5 , V_1 -> V_69 ? V_1 -> V_69 : L_6 ) ;
printf ( L_7 ) ;
printf ( L_8 ) ;
V_68 = 0xffffffff ;
do {
V_67 = 0 ;
for( V_8 = V_1 -> V_9 ; V_8 ; V_8 = V_8 -> V_10 ) {
T_17 V_70 ;
V_70 = V_8 -> V_11 + V_8 -> V_12 ;
if( ( V_70 > V_67 )
&& ( V_70 < V_68 ) ) {
V_67 = V_70 ;
}
}
for( V_8 = V_1 -> V_9 ; V_8 ; V_8 = V_8 -> V_10 ) {
T_17 V_70 ;
V_70 = V_8 -> V_11 + V_8 -> V_12 ;
if( V_70 == V_67 ) {
printf ( L_9 V_71 L_10 V_71 L_10 V_71 L_11 ,
V_8 -> V_2 , V_8 -> V_3 ,
V_8 -> V_11 , V_8 -> V_13 ,
V_8 -> V_12 , V_8 -> V_14 ,
V_8 -> V_11 + V_8 -> V_12 ,
V_8 -> V_13 + V_8 -> V_14 ,
F_24 ( & V_8 -> V_15 ) ,
F_24 ( & V_8 -> V_16 ) - F_24 ( & V_8 -> V_15 )
) ;
}
}
V_68 = V_67 ;
} while( V_67 );
printf ( L_3 ) ;
}
static void
F_25 ( const char * V_72 , void * T_18 V_23 )
{
const char * V_69 = NULL ;
const char * V_73 , * V_74 ;
T_19 V_75 ;
T_1 * V_1 = NULL ;
T_20 * V_76 ;
if( ! strncmp ( V_72 , L_12 , 8 ) ) {
if( V_72 [ 8 ] == ',' ) {
V_69 = V_72 + 9 ;
} else {
V_69 = NULL ;
}
V_73 = L_13 ;
V_74 = L_14 ;
V_75 = F_20 ;
} else if( ! strncmp ( V_72 , L_15 , 7 ) ) {
if( V_72 [ 7 ] == ',' ) {
V_69 = V_72 + 8 ;
} else {
V_69 = NULL ;
}
V_73 = L_16 ;
V_74 = L_17 ;
V_75 = F_19 ;
} else if( ! strncmp ( V_72 , L_18 , 9 ) ) {
if( V_72 [ 9 ] == ',' ) {
V_69 = V_72 + 10 ;
} else {
V_69 = NULL ;
}
V_73 = L_19 ;
V_74 = L_20 ;
V_75 = F_21 ;
} else if( ! strncmp ( V_72 , L_21 , 8 ) ) {
if( V_72 [ 8 ] == ',' ) {
V_69 = V_72 + 9 ;
} else {
V_69 = NULL ;
}
V_73 = L_22 ;
V_74 = L_23 ;
V_75 = F_14 ;
} else if( ! strncmp ( V_72 , L_24 , 8 ) ) {
if( V_72 [ 8 ] == ',' ) {
V_69 = V_72 + 9 ;
} else {
V_69 = NULL ;
}
V_73 = L_25 ;
V_74 = L_26 ;
V_75 = F_9 ;
} else if( ! strncmp ( V_72 , L_27 , 7 ) ) {
if( V_72 [ 7 ] == ',' ) {
V_69 = V_72 + 8 ;
} else {
V_69 = NULL ;
}
V_73 = L_28 ;
V_74 = L_29 ;
V_75 = F_22 ;
} else if( ! strncmp ( V_72 , L_30 , 8 ) ) {
if( V_72 [ 8 ] == ',' ) {
V_69 = V_72 + 9 ;
} else {
V_69 = NULL ;
}
V_73 = L_31 ;
V_74 = L_32 ;
V_75 = F_18 ;
} else if( ! strncmp ( V_72 , L_33 , 9 ) ) {
if( V_72 [ 9 ] == ',' ) {
V_69 = V_72 + 10 ;
} else {
V_69 = NULL ;
}
V_73 = L_34 ;
V_74 = L_35 ;
V_75 = F_17 ;
} else if( ! strncmp ( V_72 , L_36 , 7 ) ) {
if( V_72 [ 7 ] == ',' ) {
V_69 = V_72 + 8 ;
} else {
V_69 = NULL ;
}
V_73 = L_37 ;
V_74 = L_38 ;
V_75 = F_16 ;
} else if( ! strncmp ( V_72 , L_39 , 9 ) ) {
if( V_72 [ 9 ] == ',' ) {
V_69 = V_72 + 10 ;
} else {
V_69 = NULL ;
}
V_73 = L_40 ;
V_74 = L_41 ;
V_75 = F_13 ;
} else {
fprintf ( V_77 , L_42 ) ;
fprintf ( V_77 , L_43 ) ;
fprintf ( V_77 , L_44 ) ;
fprintf ( V_77 , L_45 ) ;
fprintf ( V_77 , L_46 ) ;
fprintf ( V_77 , L_47 ) ;
fprintf ( V_77 , L_48 ) ;
fprintf ( V_77 , L_49 ) ;
fprintf ( V_77 , L_50 ) ;
fprintf ( V_77 , L_51 ) ;
fprintf ( V_77 , L_52 ) ;
exit ( 1 ) ;
}
V_1 = F_2 ( sizeof( T_1 ) ) ;
V_1 -> V_9 = NULL ;
V_1 -> type = V_74 ;
if( V_69 ) {
V_1 -> V_69 = F_3 ( V_69 ) ;
} else {
V_1 -> V_69 = NULL ;
}
V_76 = F_26 ( V_73 , V_1 , V_69 , 0 , NULL , V_75 , F_23 ) ;
if( V_76 ) {
if( V_1 -> V_9 ) {
F_27 ( V_1 -> V_9 ) ;
}
F_27 ( V_1 ) ;
fprintf ( V_77 , L_53 ,
V_76 -> V_78 ) ;
F_28 ( V_76 , TRUE ) ;
exit ( 1 ) ;
}
}
void
F_29 ( void )
{
F_30 ( L_54 , F_25 , NULL ) ;
}
