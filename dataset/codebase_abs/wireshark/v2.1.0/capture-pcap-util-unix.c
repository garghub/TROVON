T_1 *
F_1 ( const char * V_1 , const char * V_2 ,
int V_3 , const char * V_4 ,
const char * V_5 , int * V_6 , char * * V_7 )
{
struct V_8 V_9 ;
char V_10 [ V_11 ] ;
char V_12 [ V_13 ] ;
T_1 * V_14 ;
if ( F_2 ( V_10 , V_15 , V_1 , V_2 ,
NULL , V_12 ) == - 1 ) {
* V_6 = V_16 ;
if ( V_7 != NULL )
* V_7 = F_3 ( V_12 ) ;
return NULL ;
}
V_9 . type = V_3 ;
V_9 . V_4 = F_4 ( V_4 ) ;
V_9 . V_17 = F_4 ( V_5 ) ;
V_14 = F_5 ( V_10 , & V_9 , V_6 , V_7 ) ;
F_6 ( V_9 . V_4 ) ;
F_6 ( V_9 . V_17 ) ;
return V_14 ;
}
T_1 *
F_7 ( int * V_6 , char * * V_7 )
{
return F_8 ( V_6 , V_7 ) ;
}
static void
F_9 ( T_2 V_18 , T_2 V_19 )
{
struct V_20 * V_20 = (struct V_20 * ) V_19 ;
T_3 * V_21 = ( T_3 * ) V_18 ;
if ( strcmp ( V_21 -> V_22 , V_20 -> V_22 ) == 0 )
V_20 -> V_21 = V_21 ;
}
T_1 *
F_7 ( int * V_6 , char * * V_7 )
{
T_1 * V_23 = NULL ;
T_4 V_24 = 0 ;
struct V_25 * V_26 , * V_27 ;
struct V_28 V_29 ;
struct V_25 V_30 ;
int V_31 = F_10 ( V_32 , V_33 , 0 ) ;
struct V_20 V_19 ;
T_5 * V_34 ;
int V_35 , V_36 ;
char * V_37 ;
T_3 * V_21 ;
char V_12 [ V_13 ] ;
T_6 V_38 ;
if ( V_31 < 0 ) {
* V_6 = V_16 ;
if ( V_7 != NULL ) {
* V_7 = F_11 (
L_1 ,
F_12 ( V_39 ) ) ;
}
return NULL ;
}
V_36 = 0 ;
V_35 = 100 * sizeof( struct V_25 ) ;
for ( ; ; ) {
V_37 = ( char * ) F_13 ( V_35 ) ;
V_29 . V_40 = V_35 ;
V_29 . V_41 = V_37 ;
memset ( V_37 , 0 , V_35 ) ;
if ( F_14 ( V_31 , V_42 , & V_29 ) < 0 ) {
if ( V_39 != V_43 || V_36 != 0 ) {
if ( V_7 != NULL ) {
* V_7 = F_11 (
L_2 ,
F_12 ( V_39 ) ) ;
}
goto V_44;
}
} else {
if ( ( unsigned int ) V_29 . V_40 < sizeof( struct V_25 ) ) {
if ( V_7 != NULL ) {
* V_7 = F_4 (
L_3 ) ;
}
goto V_44;
}
if ( V_29 . V_40 == V_36 )
break;
V_36 = V_29 . V_40 ;
}
V_35 += 10 * sizeof( struct V_25 ) ;
F_6 ( V_37 ) ;
}
V_26 = (struct V_25 * ) V_29 . V_45 ;
V_27 = (struct V_25 * ) ( ( char * ) V_26 + V_29 . V_40 ) ;
while ( V_26 < V_27 ) {
if ( strncmp ( V_26 -> V_46 , L_4 , 5 ) == 0 ||
strchr ( V_26 -> V_46 , ':' ) != NULL )
goto V_47;
V_19 . V_22 = V_26 -> V_46 ;
V_19 . V_21 = NULL ;
F_15 ( V_23 , F_9 , & V_19 ) ;
if ( V_19 . V_21 != NULL ) {
F_16 ( V_19 . V_21 , & V_26 -> V_48 ) ;
goto V_47;
}
memset ( & V_30 , 0 , sizeof V_30 ) ;
F_17 ( V_30 . V_46 , V_26 -> V_46 ,
sizeof V_30 . V_46 ) ;
if ( F_14 ( V_31 , V_49 , ( char * ) & V_30 ) < 0 ) {
if ( V_39 == V_50 )
goto V_47;
if ( V_7 != NULL ) {
* V_7 = F_11 (
L_5 ,
V_26 -> V_46 , F_12 ( V_39 ) ) ;
}
goto V_44;
}
if ( ! ( V_30 . V_51 & V_52 ) )
goto V_47;
V_34 = F_18 ( V_26 -> V_46 , V_53 , 0 , 0 ,
V_12 ) ;
if ( V_34 == NULL )
goto V_47;
F_19 ( V_34 ) ;
V_38 = ( ( V_30 . V_51 & V_54 ) ||
strncmp ( V_26 -> V_46 , L_6 , 2 ) == 0 ) ;
V_21 = F_20 ( V_26 -> V_46 , NULL , V_38 ) ;
F_16 ( V_21 , & V_26 -> V_48 ) ;
if ( V_38 )
V_23 = F_21 ( V_23 , V_21 ) ;
else {
V_23 = F_22 ( V_23 , V_21 , V_24 ) ;
V_24 ++ ;
}
V_47:
#ifdef F_23
V_26 = (struct V_25 * ) ( ( char * ) V_26 +
( V_26 -> V_48 . V_55 > sizeof( V_26 -> V_48 ) ?
V_26 -> V_48 . V_55 : sizeof( V_26 -> V_48 ) ) +
V_56 ) ;
#else
V_26 = (struct V_25 * ) ( ( char * ) V_26 + sizeof( struct V_25 ) ) ;
#endif
}
#ifdef F_24
V_34 = F_18 ( L_7 , V_53 , 0 , 0 , V_12 ) ;
if ( V_34 != NULL ) {
V_21 = F_20 ( L_7 ,
L_8 , FALSE ) ;
V_23 = F_22 ( V_23 , V_21 , - 1 ) ;
F_19 ( V_34 ) ;
}
#endif
F_6 ( V_29 . V_41 ) ;
F_25 ( V_31 ) ;
if ( V_23 == NULL ) {
* V_6 = 0 ;
if ( V_7 != NULL )
* V_7 = NULL ;
}
return V_23 ;
V_44:
if ( V_23 != NULL )
F_26 ( V_23 ) ;
F_6 ( V_29 . V_41 ) ;
F_25 ( V_31 ) ;
* V_6 = V_16 ;
return NULL ;
}
T_7 *
F_3 ( const char * V_7 )
{
return F_11 ( L_9 , V_7 ) ;
}
void
F_27 ( T_5 * V_57 )
{
#ifdef F_28
static T_6 V_58 = FALSE ;
static int (* F_29)( T_5 * , int );
if ( ! V_58 ) {
F_29 =
( int ( * ) ( T_5 * , int ) )
F_30 ( V_59 , L_10 ) ;
V_58 = TRUE ;
}
if ( F_29 != NULL )
(* F_29)( V_57 , V_60 ) ;
#else
F_31 ( V_57 , V_60 ) ;
#endif
}
T_6
F_32 ( T_5 * V_57 )
{
#ifdef F_28
static T_6 V_58 = FALSE ;
static int (* F_33)( T_5 * );
if ( ! V_58 ) {
F_33 =
( int ( * ) ( T_5 * ) )
F_30 ( V_59 , L_11 ) ;
V_58 = TRUE ;
}
if ( F_33 != NULL )
return (* F_33)( V_57 ) == V_60 ;
else
return FALSE ;
#else
return F_34 ( V_57 ) == V_60 ;
#endif
}
T_8 *
F_35 ( T_9 * V_61 , char * * V_7 )
{
#ifdef F_36
return F_37 ( V_61 , V_7 ) ;
#else
return F_38 ( V_61 , V_7 ) ;
#endif
}
void
F_39 ( T_10 * V_62 )
{
F_40 ( V_62 , L_12 ) ;
F_40 ( V_62 , L_13 ) ;
#ifdef F_41
F_40 ( V_62 , L_14 ) ;
#ifdef F_42
F_40 ( V_62 , L_15 ) ;
#endif
#else
F_40 ( V_62 , L_16 ) ;
#endif
#ifdef F_43
F_40 ( V_62 , L_13 ) ;
#if F_44 ( V_63 )
F_40 ( V_62 , L_17 ) ;
#elif F_44 ( V_64 )
F_40 ( V_62 , L_18 ) ;
#elif F_44 ( V_65 )
F_40 ( V_62 , L_19 ) ;
#else
F_40 ( V_62 , L_20 ) ;
#endif
#endif
}
void
F_45 ( T_10 * V_62 )
{
F_46 ( V_62 , L_21 ) ;
#ifdef F_47
F_40 ( V_62 , F_48 () ) ;
#else
F_40 ( V_62 , L_22 ) ;
#endif
}
void
F_39 ( T_10 * V_62 )
{
F_40 ( V_62 , L_23 ) ;
}
void
F_45 ( T_10 * V_62 V_66 )
{
}
