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
#ifdef F_19
V_1 -> V_32 = F_15 ( L_4 ) ;
#endif
#ifdef F_17
if ( T_2 && ( strstr ( T_2 , L_5 ) != NULL ||
strstr ( T_2 , L_6 ) != NULL ) ) {
V_1 -> type = V_21 ;
} else if ( T_2 && ( strstr ( T_2 , L_7 ) != NULL ||
strstr ( T_2 , L_8 ) != NULL ) ) {
V_1 -> type = V_17 ;
} else if ( T_2 && strstr ( T_2 , L_9 ) != NULL ||
strstr ( V_2 , L_10 ) != NULL ) {
V_1 -> type = V_33 ;
} else if ( T_2 && strstr ( T_2 , L_11 ) != NULL ) {
V_1 -> type = V_19 ;
} else if ( T_2 && strstr ( T_2 , L_12 ) != NULL ) {
V_1 -> type = V_34 ;
}
if ( strncmp ( L_13 , V_2 , 12 ) == 0 )
V_29 = V_2 + 12 ;
else
V_29 = V_2 ;
if ( F_20 ( V_29 , & V_30 ) ) {
V_1 -> V_14 = F_21 ( & V_30 ) ;
V_1 -> V_31 = F_15 ( T_2 ) ;
} else {
V_1 -> V_14 = F_15 ( T_2 ) ;
V_1 -> V_31 = NULL ;
}
#else
F_1 ( V_1 , V_2 , T_2 ) ;
if ( V_1 -> type == V_24 ) {
if ( F_22 ( V_2 , L_14 , 5 ) == 0 )
V_1 -> type = V_34 ;
else if ( F_22 ( V_2 , L_15 , 6 ) == 0 )
V_1 -> type = V_34 ;
}
if ( V_1 -> V_14 == NULL ) {
if ( V_28 )
V_1 -> V_14 = F_15 ( L_16 ) ;
}
V_1 -> V_31 = NULL ;
#endif
V_1 -> V_28 = V_28 ;
V_1 -> V_35 = NULL ;
return V_1 ;
}
void
F_23 ( T_1 * V_1 , struct V_36 * V_37 )
{
T_10 * V_38 ;
struct V_39 * V_40 ;
#ifdef F_24
struct V_41 * V_42 ;
#endif
switch ( V_37 -> V_43 ) {
case V_44 :
V_40 = (struct V_39 * ) ( void * ) V_37 ;
V_38 = ( T_10 * ) F_18 ( sizeof( * V_38 ) ) ;
V_38 -> V_45 = V_46 ;
V_38 -> V_37 . V_47 =
* ( ( V_48 * ) & ( V_40 -> V_49 . V_50 ) ) ;
V_1 -> V_35 = F_25 ( V_1 -> V_35 , V_38 ) ;
break;
#ifdef F_24
case V_51 :
V_42 = (struct V_41 * ) ( void * ) V_37 ;
V_38 = ( T_10 * ) F_18 ( sizeof( * V_38 ) ) ;
V_38 -> V_45 = V_52 ;
memcpy ( ( void * ) & V_38 -> V_37 . V_53 ,
( void * ) & V_42 -> V_54 . V_55 ,
sizeof V_38 -> V_37 . V_53 ) ;
V_1 -> V_35 = F_25 ( V_1 -> V_35 , V_38 ) ;
break;
#endif
}
}
static void
F_26 ( T_1 * V_1 , T_11 * V_56 )
{
T_12 * V_57 ;
for ( V_57 = V_56 -> V_58 ; V_57 != NULL ; V_57 = V_57 -> V_59 ) {
if ( V_57 -> V_37 != NULL )
F_23 ( V_1 , V_57 -> V_37 ) ;
}
}
T_13 *
F_27 ( const char * V_60 ,
struct V_61 * V_62 ,
int * V_63 , char * * V_64 )
{
T_13 * V_65 = NULL ;
T_11 * V_66 , * V_67 ;
T_1 * V_1 ;
char V_68 [ V_69 * 4 ] ;
if ( F_28 ( ( char * ) V_60 , V_62 , & V_66 , V_68 ) == - 1 ) {
* V_63 = V_70 ;
if ( V_64 != NULL )
* V_64 = F_29 ( V_68 ) ;
return NULL ;
}
if ( V_66 == NULL ) {
* V_63 = 0 ;
if ( V_64 != NULL )
* V_64 = NULL ;
return NULL ;
}
for ( V_67 = V_66 ; V_67 != NULL ; V_67 = V_67 -> V_59 ) {
V_1 = F_16 ( V_67 -> V_2 , V_67 -> T_2 ,
( V_67 -> V_71 & V_72 ) ? TRUE : FALSE ) ;
V_65 = F_30 ( V_65 , V_1 ) ;
F_26 ( V_1 , V_67 ) ;
}
F_31 ( V_66 ) ;
return V_65 ;
}
T_13 *
F_32 ( int * V_63 , char * * V_64 )
{
T_13 * V_65 = NULL ;
T_11 * V_66 , * V_67 ;
T_1 * V_1 ;
char V_68 [ V_69 ] ;
if ( F_33 ( & V_66 , V_68 ) == - 1 ) {
* V_63 = V_70 ;
if ( V_64 != NULL )
* V_64 = F_29 ( V_68 ) ;
return NULL ;
}
if ( V_66 == NULL ) {
* V_63 = 0 ;
if ( V_64 != NULL )
* V_64 = NULL ;
return NULL ;
}
for ( V_67 = V_66 ; V_67 != NULL ; V_67 = V_67 -> V_59 ) {
V_1 = F_16 ( V_67 -> V_2 , V_67 -> T_2 ,
( V_67 -> V_71 & V_72 ) ? TRUE : FALSE ) ;
V_65 = F_30 ( V_65 , V_1 ) ;
F_26 ( V_1 , V_67 ) ;
}
F_31 ( V_66 ) ;
return V_65 ;
}
static void
F_34 ( T_14 V_37 , T_14 T_15 V_3 )
{
F_14 ( V_37 ) ;
}
static void
F_35 ( T_14 V_73 , T_14 T_15 V_3 )
{
T_1 * V_1 = ( T_1 * ) V_73 ;
F_14 ( V_1 -> V_2 ) ;
F_14 ( V_1 -> V_14 ) ;
F_14 ( V_1 -> V_31 ) ;
#ifdef F_19
F_14 ( V_1 -> V_32 ) ;
#endif
F_36 ( V_1 -> V_35 , F_34 , NULL ) ;
F_37 ( V_1 -> V_35 ) ;
F_14 ( V_1 ) ;
}
void
F_38 ( T_13 * V_74 )
{
F_39 ( V_74 , F_35 , NULL ) ;
F_40 ( V_74 ) ;
}
static int
F_41 ( const char * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_75 [ V_7 ] . V_2 != NULL ; V_7 ++ ) {
if ( F_42 ( V_75 [ V_7 ] . V_2 + sizeof( L_17 ) - 1 ,
V_2 ) == 0 )
return ( V_75 [ V_7 ] . V_76 ) ;
}
return ( - 1 ) ;
}
static const char *
F_43 ( int V_76 )
{
int V_7 ;
for ( V_7 = 0 ; V_75 [ V_7 ] . V_2 != NULL ; V_7 ++ ) {
if ( V_75 [ V_7 ] . V_76 == V_76 )
return ( V_75 [ V_7 ] . V_2 + sizeof( L_17 ) - 1 ) ;
}
return ( NULL ) ;
}
const char *
F_44 ( int V_76 )
{
int V_7 ;
for ( V_7 = 0 ; V_75 [ V_7 ] . V_2 != NULL ; V_7 ++ ) {
if ( V_75 [ V_7 ] . V_76 == V_76 )
return ( V_75 [ V_7 ] . T_2 ) ;
}
return ( NULL ) ;
}
static void
F_45 ( T_14 V_73 , T_14 T_15 V_3 )
{
T_16 * V_77 = ( T_16 * ) V_73 ;
F_14 ( V_77 -> V_2 ) ;
F_14 ( V_77 -> T_2 ) ;
}
void
F_46 ( T_17 * V_78 )
{
F_39 ( V_78 -> V_79 , F_45 , NULL ) ;
F_40 ( V_78 -> V_79 ) ;
F_14 ( V_78 ) ;
}
const char *
F_47 ( int V_76 )
{
return F_43 ( V_76 ) ;
}
int F_48 ( const char * V_80 )
{
return F_41 ( V_80 ) ;
}
