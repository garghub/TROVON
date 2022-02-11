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
#ifdef F_8
return F_9 ( V_6 , V_7 ) ;
#else
T_1 * V_18 = NULL ;
T_2 V_19 = 0 ;
struct V_20 * V_21 , * V_22 ;
struct V_23 V_24 ;
struct V_20 V_25 ;
int V_26 = F_10 ( V_27 , V_28 , 0 ) ;
struct V_29 V_30 ;
T_3 * V_31 ;
int V_32 , V_33 ;
char * V_34 ;
T_4 * V_35 ;
char V_12 [ V_13 ] ;
if ( V_26 < 0 ) {
* V_6 = V_16 ;
if ( V_7 != NULL ) {
* V_7 = F_11 (
L_1 ,
F_12 ( V_36 ) ) ;
}
return NULL ;
}
V_33 = 0 ;
V_32 = 100 * sizeof( struct V_20 ) ;
for ( ; ; ) {
V_34 = F_13 ( V_32 ) ;
V_24 . V_37 = V_32 ;
V_24 . V_38 = V_34 ;
memset ( V_34 , 0 , V_32 ) ;
if ( F_14 ( V_26 , V_39 , & V_24 ) < 0 ) {
if ( V_36 != V_40 || V_33 != 0 ) {
if ( V_7 != NULL ) {
* V_7 = F_11 (
L_2 ,
F_12 ( V_36 ) ) ;
}
goto V_41;
}
} else {
if ( ( unsigned ) V_24 . V_37 < sizeof( struct V_20 ) ) {
if ( V_7 != NULL ) {
* V_7 = F_4 (
L_3 ) ;
}
goto V_41;
}
if ( V_24 . V_37 == V_33 )
break;
V_33 = V_24 . V_37 ;
}
V_32 += 10 * sizeof( struct V_20 ) ;
F_6 ( V_34 ) ;
}
V_21 = (struct V_20 * ) V_24 . V_42 ;
V_22 = (struct V_20 * ) ( ( char * ) V_21 + V_24 . V_37 ) ;
while ( V_21 < V_22 ) {
if ( strncmp ( V_21 -> V_43 , L_4 , 5 ) == 0 ||
strchr ( V_21 -> V_43 , ':' ) != NULL )
goto V_44;
V_30 . V_45 = V_21 -> V_43 ;
V_30 . V_35 = NULL ;
F_15 ( V_18 , V_46 , & V_30 ) ;
if ( V_30 . V_35 != NULL ) {
F_16 ( V_30 . V_35 , & V_21 -> V_47 ) ;
goto V_44;
}
memset ( & V_25 , 0 , sizeof V_25 ) ;
F_17 ( V_25 . V_43 , V_21 -> V_43 ,
sizeof V_25 . V_43 ) ;
if ( F_14 ( V_26 , V_48 , ( char * ) & V_25 ) < 0 ) {
if ( V_36 == V_49 )
goto V_44;
if ( V_7 != NULL ) {
* V_7 = F_11 (
L_5 ,
V_21 -> V_43 , F_12 ( V_36 ) ) ;
}
goto V_41;
}
if ( ! ( V_25 . V_50 & V_51 ) )
goto V_44;
V_31 = F_18 ( V_21 -> V_43 , V_52 , 0 , 0 ,
V_12 ) ;
if ( V_31 == NULL )
goto V_44;
F_19 ( V_31 ) ;
V_35 = F_20 ( V_21 -> V_43 , NULL ) ;
F_16 ( V_35 , & V_21 -> V_47 ) ;
if ( ( V_25 . V_50 & V_53 ) ||
strncmp ( V_21 -> V_43 , L_6 , 2 ) == 0 ) {
V_35 -> V_54 = TRUE ;
V_18 = F_21 ( V_18 , V_35 ) ;
} else {
V_35 -> V_54 = FALSE ;
V_18 = F_22 ( V_18 , V_35 , V_19 ) ;
V_19 ++ ;
}
V_44:
#ifdef F_23
V_21 = (struct V_20 * ) ( ( char * ) V_21 +
( V_21 -> V_47 . V_55 > sizeof( V_21 -> V_47 ) ?
V_21 -> V_47 . V_55 : sizeof( V_21 -> V_47 ) ) +
V_56 ) ;
#else
V_21 = (struct V_20 * ) ( ( char * ) V_21 + sizeof( struct V_20 ) ) ;
#endif
}
#ifdef F_24
V_31 = F_18 ( L_7 , V_52 , 0 , 0 , V_12 ) ;
if ( V_31 != NULL ) {
V_35 = F_20 ( L_7 ,
L_8 ) ;
V_18 = F_22 ( V_18 , V_35 , - 1 ) ;
F_19 ( V_31 ) ;
}
#endif
F_6 ( V_24 . V_38 ) ;
F_25 ( V_26 ) ;
if ( V_18 == NULL ) {
* V_6 = V_57 ;
if ( V_7 != NULL )
* V_7 = NULL ;
}
return V_18 ;
V_41:
if ( V_18 != NULL )
F_26 ( V_18 ) ;
F_6 ( V_24 . V_38 ) ;
F_25 ( V_26 ) ;
* V_6 = V_16 ;
return NULL ;
#endif
}
static void
V_46 ( T_5 V_58 , T_5 V_30 )
{
struct V_29 * V_29 = V_30 ;
T_4 * V_35 = V_58 ;
if ( strcmp ( V_35 -> V_45 , V_29 -> V_45 ) == 0 )
V_29 -> V_35 = V_35 ;
}
T_6 *
F_3 ( const char * V_7 )
{
return F_11 ( L_9 , V_7 ) ;
}
void
F_27 ( T_7 * V_59 )
{
F_28 ( V_59 , L_10 ) ;
}
void
F_29 ( T_7 * V_59 )
{
F_30 ( V_59 , L_11 ) ;
#ifdef F_31
F_28 ( V_59 , F_32 () ) ;
#else
F_28 ( V_59 , L_12 ) ;
#endif
}
void
F_27 ( T_7 * V_59 )
{
F_28 ( V_59 , L_13 ) ;
}
void
F_29 ( T_7 * V_59 V_60 )
{
}
