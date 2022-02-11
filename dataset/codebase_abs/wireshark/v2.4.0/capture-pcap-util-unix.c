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
if ( V_19 . V_21 -> V_49 ) {
F_17 ( V_19 . V_21 -> V_49 ) ;
}
goto V_47;
}
memset ( & V_30 , 0 , sizeof V_30 ) ;
F_18 ( V_30 . V_46 , V_26 -> V_46 ,
sizeof V_30 . V_46 ) ;
if ( F_14 ( V_31 , V_50 , ( char * ) & V_30 ) < 0 ) {
if ( V_39 == V_51 )
goto V_47;
if ( V_7 != NULL ) {
* V_7 = F_11 (
L_5 ,
V_26 -> V_46 , F_12 ( V_39 ) ) ;
}
goto V_44;
}
if ( ! ( V_30 . V_52 & V_53 ) )
goto V_47;
V_34 = F_19 ( V_26 -> V_46 , V_54 , 0 , 0 ,
V_12 ) ;
if ( V_34 == NULL )
goto V_47;
F_20 ( V_34 ) ;
V_38 = ( ( V_30 . V_52 & V_55 ) ||
strncmp ( V_26 -> V_46 , L_6 , 2 ) == 0 ) ;
V_21 = F_21 ( V_26 -> V_46 , NULL , V_38 ) ;
F_16 ( V_21 , & V_26 -> V_48 ) ;
if ( V_21 -> V_49 ) {
F_17 ( V_21 -> V_49 ) ;
}
if ( V_38 )
V_23 = F_22 ( V_23 , V_21 ) ;
else {
V_23 = F_23 ( V_23 , V_21 , V_24 ) ;
V_24 ++ ;
}
V_47:
#ifdef F_24
V_26 = (struct V_25 * ) ( ( char * ) V_26 +
( V_26 -> V_48 . V_56 > sizeof( V_26 -> V_48 ) ?
V_26 -> V_48 . V_56 : sizeof( V_26 -> V_48 ) ) +
V_57 ) ;
#else
V_26 = (struct V_25 * ) ( ( char * ) V_26 + sizeof( struct V_25 ) ) ;
#endif
}
#ifdef F_25
V_34 = F_19 ( L_7 , V_54 , 0 , 0 , V_12 ) ;
if ( V_34 != NULL ) {
V_21 = F_21 ( L_7 ,
L_8 , FALSE ) ;
V_23 = F_23 ( V_23 , V_21 , - 1 ) ;
F_20 ( V_34 ) ;
}
#endif
F_6 ( V_29 . V_41 ) ;
F_26 ( V_31 ) ;
if ( V_23 == NULL ) {
* V_6 = 0 ;
if ( V_7 != NULL )
* V_7 = NULL ;
}
return V_23 ;
V_44:
if ( V_23 != NULL )
F_27 ( V_23 ) ;
F_6 ( V_29 . V_41 ) ;
F_26 ( V_31 ) ;
* V_6 = V_16 ;
return NULL ;
}
T_7 *
F_3 ( const char * V_7 )
{
return F_11 ( L_9 , V_7 ) ;
}
void
F_28 ( T_5 * V_58 )
{
#ifdef F_29
static T_6 V_59 = FALSE ;
static int (* F_30)( T_5 * , int );
if ( ! V_59 ) {
F_30 =
( int ( * ) ( T_5 * , int ) )
F_31 ( V_60 , L_10 ) ;
V_59 = TRUE ;
}
if ( F_30 != NULL )
(* F_30)( V_58 , V_61 ) ;
#else
F_32 ( V_58 , V_61 ) ;
#endif
}
T_6
F_33 ( T_5 * V_58 )
{
#ifdef F_29
static T_6 V_59 = FALSE ;
static int (* F_34)( T_5 * );
if ( ! V_59 ) {
F_34 =
( int ( * ) ( T_5 * ) )
F_31 ( V_60 , L_11 ) ;
V_59 = TRUE ;
}
if ( F_34 != NULL )
return (* F_34)( V_58 ) == V_61 ;
else
return FALSE ;
#else
return F_35 ( V_58 ) == V_61 ;
#endif
}
T_8 *
F_36 ( T_9 * V_62 , char * * V_7 )
{
#ifdef F_37
return F_38 ( V_62 , V_7 ) ;
#else
return F_39 ( V_62 , V_7 ) ;
#endif
}
void
F_40 ( T_10 * V_63 )
{
F_41 ( V_63 , L_12 ) ;
#ifdef F_42
F_41 ( V_63 , L_13 ) ;
#endif
F_41 ( V_63 , L_14 ) ;
#ifdef F_43
F_41 ( V_63 , L_15 ) ;
#ifdef F_44
F_41 ( V_63 , L_16 ) ;
#endif
#else
F_41 ( V_63 , L_17 ) ;
#endif
#ifdef F_45
F_41 ( V_63 , L_14 ) ;
#if F_46 ( V_64 )
F_41 ( V_63 , L_18 ) ;
#elif F_46 ( V_65 )
F_41 ( V_63 , L_19 ) ;
#elif F_46 ( V_66 )
F_41 ( V_63 , L_20 ) ;
#else
F_41 ( V_63 , L_21 ) ;
#endif
#endif
}
void
F_47 ( T_10 * V_63 )
{
F_48 ( V_63 , L_22 ) ;
#ifdef F_49
F_41 ( V_63 , F_50 () ) ;
#else
F_41 ( V_63 , L_23 ) ;
#endif
}
void
F_40 ( T_10 * V_63 )
{
F_41 ( V_63 , L_24 ) ;
}
void
F_47 ( T_10 * V_63 V_67 )
{
}
