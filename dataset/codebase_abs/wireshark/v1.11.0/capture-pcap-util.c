static void
F_1 ( T_1 * V_1 , const char * V_2 ,
const char * T_2 V_3 )
{
T_3 V_4 ;
T_4 V_5 ;
T_5 V_6 ;
T_5 V_7 ;
T_6 V_8 ;
T_3 V_9 ;
T_3 V_10 ;
T_3 V_11 ;
V_5 = F_2 () ;
if ( V_5 == NULL ) {
return;
}
V_4 = F_3 ( V_12 ,
V_2 , V_13 ) ;
if ( V_4 == NULL ) {
F_4 ( V_5 ) ;
return;
}
V_6 = F_5 ( V_5 ) ;
for ( V_7 = 0 ; V_7 < V_6 ; V_7 ++ ) {
V_8 = ( T_6 ) F_6 ( V_5 , V_7 ) ;
V_9 = F_7 ( V_8 ) ;
if ( V_9 == NULL ) {
continue;
}
if ( F_8 ( V_4 , V_9 , 0 ) == 0 ) {
V_10 = F_9 ( V_8 ) ;
if ( V_10 != NULL )
V_1 -> V_14 = F_10 ( V_10 ) ;
V_11 = F_11 ( V_8 ) ;
if ( F_8 ( V_11 ,
V_15 , 0 ) == V_16 )
V_1 -> type = V_17 ;
else if ( F_8 ( V_11 ,
V_18 , 0 ) == V_16 )
V_1 -> type = V_19 ;
else if ( F_8 ( V_11 ,
V_20 , 0 ) == V_16 )
V_1 -> type = V_21 ;
else if ( F_8 ( V_11 ,
V_22 , 0 ) == V_16 )
V_1 -> type = V_21 ;
else if ( F_8 ( V_11 ,
V_23 , 0 ) == V_16 )
V_1 -> type = V_21 ;
else
V_1 -> type = V_24 ;
break;
}
}
F_4 ( V_5 ) ;
F_4 ( V_4 ) ;
}
static void
F_1 ( T_1 * V_1 , const char * V_2 ,
const char * T_2 V_3 )
{
char * V_25 ;
T_7 V_26 ;
V_25 = F_12 ( L_1 , V_2 ) ;
if ( V_25 != NULL ) {
if ( F_13 ( V_25 , & V_26 ) == 0 )
V_1 -> type = V_17 ;
F_14 ( V_25 ) ;
}
if ( V_1 -> type == V_24 ) {
if ( strstr ( V_2 , L_2 ) != NULL ) {
V_1 -> type = V_19 ;
} else if ( strstr ( V_2 , L_3 ) != NULL )
V_1 -> type = V_27 ;
}
}
void
F_1 ( T_1 * V_1 , const char * V_2 V_3 ,
const char * T_2 )
{
V_1 -> V_14 = F_15 ( T_2 ) ;
}
T_1 *
F_16 ( const char * V_2 , const char * T_2 , T_8 V_28 )
{
T_1 * V_1 ;
#ifdef F_17
const char * V_29 ;
T_9 V_30 ;
#endif
V_1 = ( T_1 * ) F_18 ( sizeof ( T_1 ) ) ;
V_1 -> V_2 = F_15 ( V_2 ) ;
V_1 -> V_14 = NULL ;
V_1 -> V_31 = NULL ;
V_1 -> type = V_24 ;
#ifdef F_17
if ( T_2 && ( strstr ( T_2 , L_4 ) != NULL ||
strstr ( T_2 , L_5 ) != NULL ) ) {
V_1 -> type = V_21 ;
} else if ( T_2 && ( strstr ( T_2 , L_6 ) != NULL ||
strstr ( T_2 , L_7 ) != NULL ) ) {
V_1 -> type = V_17 ;
} else if ( T_2 && strstr ( T_2 , L_8 ) != NULL ||
strstr ( V_2 , L_9 ) != NULL ) {
V_1 -> type = V_32 ;
} else if ( T_2 && strstr ( T_2 , L_10 ) != NULL ) {
V_1 -> type = V_19 ;
} else if ( T_2 && strstr ( T_2 , L_11 ) != NULL ) {
V_1 -> type = V_33 ;
}
if ( strncmp ( L_12 , V_2 , 12 ) == 0 )
V_29 = V_2 + 12 ;
else
V_29 = V_2 ;
if ( F_19 ( V_29 , & V_30 ) ) {
V_1 -> V_14 = F_20 ( & V_30 ) ;
V_1 -> V_31 = F_15 ( T_2 ) ;
} else {
V_1 -> V_14 = F_15 ( T_2 ) ;
V_1 -> V_31 = NULL ;
}
#else
F_1 ( V_1 , V_2 , T_2 ) ;
if ( V_1 -> type == V_24 ) {
if ( F_21 ( V_2 , L_13 , 5 ) == 0 )
V_1 -> type = V_33 ;
else if ( F_21 ( V_2 , L_14 , 6 ) == 0 )
V_1 -> type = V_33 ;
}
if ( V_1 -> V_14 == NULL ) {
if ( V_28 )
V_1 -> V_14 = F_15 ( L_15 ) ;
}
V_1 -> V_31 = NULL ;
#endif
V_1 -> V_28 = V_28 ;
V_1 -> V_34 = NULL ;
return V_1 ;
}
void
F_22 ( T_1 * V_1 , struct V_35 * V_36 )
{
T_10 * V_37 ;
struct V_38 * V_39 ;
#ifdef F_23
struct V_40 * V_41 ;
#endif
switch ( V_36 -> V_42 ) {
case V_43 :
V_39 = (struct V_38 * ) ( void * ) V_36 ;
V_37 = ( T_10 * ) F_18 ( sizeof( * V_37 ) ) ;
V_37 -> V_44 = V_45 ;
V_37 -> V_36 . V_46 =
* ( ( V_47 * ) & ( V_39 -> V_48 . V_49 ) ) ;
V_1 -> V_34 = F_24 ( V_1 -> V_34 , V_37 ) ;
break;
#ifdef F_23
case V_50 :
V_41 = (struct V_40 * ) ( void * ) V_36 ;
V_37 = ( T_10 * ) F_18 ( sizeof( * V_37 ) ) ;
V_37 -> V_44 = V_51 ;
memcpy ( ( void * ) & V_37 -> V_36 . V_52 ,
( void * ) & V_41 -> V_53 . V_54 ,
sizeof V_37 -> V_36 . V_52 ) ;
V_1 -> V_34 = F_24 ( V_1 -> V_34 , V_37 ) ;
break;
#endif
}
}
static void
F_25 ( T_1 * V_1 , T_11 * V_55 )
{
T_12 * V_56 ;
for ( V_56 = V_55 -> V_57 ; V_56 != NULL ; V_56 = V_56 -> V_58 ) {
if ( V_56 -> V_36 != NULL )
F_22 ( V_1 , V_56 -> V_36 ) ;
}
}
T_13 *
F_26 ( const char * V_59 ,
struct V_60 * V_61 ,
int * V_62 , char * * V_63 )
{
T_13 * V_64 = NULL ;
T_11 * V_65 , * V_66 ;
T_1 * V_1 ;
char V_67 [ V_68 ] ;
if ( F_27 ( ( char * ) V_59 , V_61 , & V_65 , V_67 ) == - 1 ) {
* V_62 = V_69 ;
if ( V_63 != NULL )
* V_63 = F_28 ( V_67 ) ;
return NULL ;
}
if ( V_65 == NULL ) {
* V_62 = V_70 ;
if ( V_63 != NULL )
* V_63 = NULL ;
return NULL ;
}
for ( V_66 = V_65 ; V_66 != NULL ; V_66 = V_66 -> V_58 ) {
V_1 = F_16 ( V_66 -> V_2 , V_66 -> T_2 ,
( V_66 -> V_71 & V_72 ) ? TRUE : FALSE ) ;
V_64 = F_29 ( V_64 , V_1 ) ;
F_25 ( V_1 , V_66 ) ;
}
F_30 ( V_65 ) ;
return V_64 ;
}
T_13 *
F_31 ( int * V_62 , char * * V_63 )
{
T_13 * V_64 = NULL ;
T_11 * V_65 , * V_66 ;
T_1 * V_1 ;
char V_67 [ V_68 ] ;
if ( F_32 ( & V_65 , V_67 ) == - 1 ) {
* V_62 = V_69 ;
if ( V_63 != NULL )
* V_63 = F_28 ( V_67 ) ;
return NULL ;
}
if ( V_65 == NULL ) {
* V_62 = V_70 ;
if ( V_63 != NULL )
* V_63 = NULL ;
return NULL ;
}
for ( V_66 = V_65 ; V_66 != NULL ; V_66 = V_66 -> V_58 ) {
V_1 = F_16 ( V_66 -> V_2 , V_66 -> T_2 ,
( V_66 -> V_71 & V_72 ) ? TRUE : FALSE ) ;
V_64 = F_29 ( V_64 , V_1 ) ;
F_25 ( V_1 , V_66 ) ;
}
F_30 ( V_65 ) ;
return V_64 ;
}
static void
F_33 ( T_14 V_36 , T_14 T_15 V_3 )
{
F_14 ( V_36 ) ;
}
static void
F_34 ( T_14 V_73 , T_14 T_15 V_3 )
{
T_1 * V_1 = ( T_1 * ) V_73 ;
F_14 ( V_1 -> V_2 ) ;
F_14 ( V_1 -> V_14 ) ;
F_14 ( V_1 -> V_31 ) ;
F_35 ( V_1 -> V_34 , F_33 , NULL ) ;
F_36 ( V_1 -> V_34 ) ;
F_14 ( V_1 ) ;
}
void
F_37 ( T_13 * V_74 )
{
F_38 ( V_74 , F_34 , NULL ) ;
F_39 ( V_74 ) ;
}
static int
F_40 ( const char * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_75 [ V_7 ] . V_2 != NULL ; V_7 ++ ) {
if ( F_41 ( V_75 [ V_7 ] . V_2 + sizeof( L_16 ) - 1 ,
V_2 ) == 0 )
return ( V_75 [ V_7 ] . V_76 ) ;
}
return ( - 1 ) ;
}
static const char *
F_42 ( int V_76 )
{
int V_7 ;
for ( V_7 = 0 ; V_75 [ V_7 ] . V_2 != NULL ; V_7 ++ ) {
if ( V_75 [ V_7 ] . V_76 == V_76 )
return ( V_75 [ V_7 ] . V_2 + sizeof( L_16 ) - 1 ) ;
}
return ( NULL ) ;
}
const char *
F_43 ( int V_76 )
{
int V_7 ;
for ( V_7 = 0 ; V_75 [ V_7 ] . V_2 != NULL ; V_7 ++ ) {
if ( V_75 [ V_7 ] . V_76 == V_76 )
return ( V_75 [ V_7 ] . T_2 ) ;
}
return ( NULL ) ;
}
static void
F_44 ( T_14 V_73 , T_14 T_15 V_3 )
{
T_16 * V_77 = ( T_16 * ) V_73 ;
F_14 ( V_77 -> V_2 ) ;
F_14 ( V_77 -> T_2 ) ;
}
void
F_45 ( T_17 * V_78 )
{
F_38 ( V_78 -> V_79 , F_44 , NULL ) ;
F_39 ( V_78 -> V_79 ) ;
F_14 ( V_78 ) ;
}
const char *
F_46 ( int V_76 )
{
return F_42 ( V_76 ) ;
}
int F_47 ( const char * V_80 )
{
return F_40 ( V_80 ) ;
}
