static struct V_1 *
F_1 ( char * V_2 , struct V_1 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_2 , V_5 , V_3 ) ;
if ( V_4 == NULL )
F_3 ( L_1 , V_2 ) ;
return V_4 ;
}
static int F_4 ( struct V_6 * V_6 , struct V_7 * V_7 )
{
return F_5 ( V_7 , V_8 , F_6 ( V_6 ) ) ;
}
static int F_7 ( struct V_6 * V_6 , struct V_7 * V_7 )
{
return F_5 ( V_7 , V_9 , F_6 ( V_6 ) ) ;
}
static int F_8 ( struct V_6 * V_6 , struct V_7 * V_7 )
{
return F_5 ( V_7 , V_10 , F_6 ( V_6 ) ) ;
}
void F_9 ( struct V_11 * V_12 ,
char * V_13 ,
void (* F_10)( struct V_14 * ) ,
void (* F_11)( struct V_14 * ,
void * ) )
{
memset ( V_12 , 0 , sizeof( struct V_11 ) ) ;
V_12 -> V_15 = V_13 ;
if ( V_12 -> V_15 == NULL )
F_3 ( L_2 ) ;
V_12 -> V_16 = F_10 ;
V_12 -> V_17 = F_11 ;
if ( V_12 -> V_18 == NULL )
V_12 -> V_18 = F_1 ( V_12 -> V_15 , NULL ) ;
if ( ( V_12 -> V_18 != NULL ) && ( V_12 -> V_19 == NULL ) )
V_12 -> V_19 = F_1 ( L_3 ,
V_12 -> V_18 ) ;
if ( ( V_12 -> V_18 != NULL ) && ( V_12 -> V_20 == NULL ) )
V_12 -> V_20 = F_1 ( L_4 ,
V_12 -> V_18 ) ;
if ( ( V_12 -> V_19 != NULL ) &&
( V_12 -> V_21 == NULL ) ) {
V_12 -> V_21 =
F_12 ( L_5 , 0 ,
V_12 -> V_19 ,
& V_22 , V_12 ) ;
if ( V_12 -> V_21 == NULL )
F_3 ( L_6 ,
V_12 -> V_15 ) ;
}
}
void F_13 ( struct V_11 * V_12 ,
char * V_13 ,
void (* F_10)( struct V_14 * ) ,
void (* F_11)( struct V_14 * ,
void * ) ,
void (* F_14)( char * V_23 ,
T_1 V_24 ,
T_2 * V_25 ) ,
void (* F_15)( char * V_23 ,
T_1 V_24 ,
T_2 * V_25 ,
void * V_4 ) )
{
F_9 ( V_12 , V_13 ,
F_10 , F_11 ) ;
V_12 -> V_26 = F_14 ;
V_12 -> V_27 = F_15 ;
}
void F_16 ( struct V_11 * V_12 )
{
if ( V_12 -> V_21 != NULL ) {
F_17 ( L_5 , V_12 -> V_19 ) ;
V_12 -> V_21 = NULL ;
}
if ( V_12 -> V_19 != NULL ) {
F_17 ( L_3 , V_12 -> V_18 ) ;
V_12 -> V_19 = NULL ;
}
if ( V_12 -> V_20 != NULL ) {
F_17 ( L_4 , V_12 -> V_18 ) ;
V_12 -> V_20 = NULL ;
}
if ( V_12 -> V_18 != NULL ) {
F_17 ( V_12 -> V_15 , NULL ) ;
V_12 -> V_18 = NULL ;
}
V_12 -> V_15 = NULL ;
V_12 -> V_16 = NULL ;
V_12 -> V_17 = NULL ;
V_12 -> V_26 = NULL ;
V_12 -> V_27 = NULL ;
}
void F_18 ( struct V_11 * V_12 ,
struct V_28 * V_4 , int V_29 ,
void * V_30 )
{
if ( ( V_12 -> V_20 != NULL ) && ( V_4 -> V_31 == NULL ) ) {
char V_32 [ 29 ] ;
sprintf ( V_32 , L_7 , V_29 ) ;
V_4 -> V_31 = F_1 ( V_32 , V_12 -> V_20 ) ;
V_4 -> V_29 = V_29 ;
}
V_4 -> V_30 = V_30 ;
V_4 -> V_12 = V_12 ;
V_4 -> V_29 = V_29 ;
if ( ( V_4 -> V_31 != NULL ) && ( V_4 -> V_33 == NULL ) ) {
V_4 -> V_33 =
F_12 ( L_5 , 0 , V_4 -> V_31 ,
& V_34 , V_4 ) ;
if ( V_4 -> V_33 == NULL )
F_19 ( V_29 , L_8 ,
V_12 -> V_15 , V_29
) ;
}
memset ( & ( V_4 -> V_35 [ 0 ] ) , 0 ,
sizeof( V_4 -> V_35 ) ) ;
}
void F_20 ( struct V_28 * V_4 ,
void (* F_21)
( struct V_14 * , void * ) ,
char * V_36 )
{
T_1 V_37 ;
struct V_38 * V_39 = NULL ;
if ( V_4 -> V_31 == NULL ) {
F_3 ( L_9 ) ;
return;
}
for ( V_37 = 0 ; V_37 < F_22 ( V_4 -> V_35 ) ; V_37 ++ ) {
if ( V_4 -> V_35 [ V_37 ] . V_40 == NULL ) {
V_39 = & ( V_4 -> V_35 [ V_37 ] ) ;
break;
}
}
if ( ! V_39 ) {
F_19 ( V_4 -> V_29 , L_10 ) ;
return;
}
V_39 -> V_30 = V_4 -> V_30 ;
V_39 -> V_12 = V_4 -> V_12 ;
V_39 -> V_40 = F_12 ( V_36 , 0 , V_4 -> V_31 ,
& V_41 , V_39 ) ;
if ( strlen ( V_36 ) + 1 > sizeof( V_39 -> V_36 ) ) {
F_19 ( V_4 -> V_29 , L_11 ,
V_36 ) ;
return;
}
strcpy ( V_39 -> V_36 , V_36 ) ;
if ( V_39 -> V_40 == NULL ) {
F_19 ( V_4 -> V_29 , L_12 ,
V_4 -> V_12 -> V_15 , V_4 -> V_29 , V_36
) ;
return;
}
V_39 -> V_42 = F_21 ;
}
void F_23 ( struct V_11 * V_12 ,
struct V_28 * V_4 , int V_29 )
{
T_1 V_37 ;
for ( V_37 = 0 ; V_37 < F_22 ( V_4 -> V_35 ) ; V_37 ++ ) {
if ( V_4 -> V_35 [ V_37 ] . V_40 != NULL ) {
struct V_38 * V_39 =
& ( V_4 -> V_35 [ V_37 ] ) ;
F_17 ( V_39 -> V_36 , V_4 -> V_31 ) ;
V_39 -> V_40 = NULL ;
}
}
if ( V_4 -> V_33 != NULL ) {
F_17 ( L_5 , V_4 -> V_31 ) ;
V_4 -> V_33 = NULL ;
}
if ( V_4 -> V_31 != NULL ) {
char V_32 [ 29 ] ;
sprintf ( V_32 , L_7 , V_29 ) ;
F_17 ( V_32 , V_12 -> V_20 ) ;
V_4 -> V_31 = NULL ;
}
V_4 -> V_30 = NULL ;
V_4 -> V_12 = NULL ;
}
static int V_8 ( struct V_14 * V_43 , void * V_44 )
{
struct V_11 * V_4 =
(struct V_11 * ) ( V_43 -> V_45 ) ;
if ( ! V_4 )
return 0 ;
( * ( V_4 -> V_16 ) ) ( V_43 ) ;
return 0 ;
}
static int V_9 ( struct V_14 * V_43 , void * V_44 )
{
struct V_28 * V_4 =
(struct V_28 * ) ( V_43 -> V_45 ) ;
if ( ( ! V_4 ) || ( ! ( V_4 -> V_12 ) ) )
return 0 ;
( * ( V_4 -> V_12 -> V_17 ) ) ( V_43 , V_4 -> V_30 ) ;
return 0 ;
}
static int V_10 ( struct V_14 * V_43 , void * V_44 )
{
struct V_38 * V_4 =
(struct V_38 * ) ( V_43 -> V_45 ) ;
if ( ( ! V_4 ) || ( ! ( V_4 -> V_42 ) ) )
return 0 ;
( * ( V_4 -> V_42 ) ) ( V_43 , V_4 -> V_30 ) ;
return 0 ;
}
static T_3 F_24 ( struct V_7 * V_7 , const char T_4 * V_46 ,
T_1 V_24 , T_2 * V_25 )
{
struct V_14 * V_43 = (struct V_14 * ) V_7 -> V_47 ;
struct V_11 * V_4 = NULL ;
char V_48 [ 256 ] ;
if ( V_43 == NULL )
return 0 ;
V_4 = (struct V_11 * ) ( V_43 -> V_45 ) ;
if ( ( ! V_4 ) || ( ! ( V_4 -> V_26 ) ) )
return 0 ;
if ( V_24 >= sizeof( V_48 ) )
return - V_49 ;
if ( F_25 ( V_48 , V_46 , V_24 ) )
return - V_50 ;
V_48 [ V_24 ] = '\0' ;
( * ( V_4 -> V_26 ) ) ( V_48 , V_24 , V_25 ) ;
return V_24 ;
}
static T_3 F_26 ( struct V_7 * V_7 , const char T_4 * V_46 ,
T_1 V_24 , T_2 * V_25 )
{
struct V_14 * V_43 = (struct V_14 * ) V_7 -> V_47 ;
struct V_28 * V_4 = NULL ;
char V_48 [ 256 ] ;
if ( V_43 == NULL )
return 0 ;
V_4 = (struct V_28 * ) ( V_43 -> V_45 ) ;
if ( ( ! V_4 ) || ( ! ( V_4 -> V_12 ) ) || ( ! ( V_4 -> V_12 -> V_27 ) ) )
return 0 ;
if ( V_24 >= sizeof( V_48 ) )
return - V_49 ;
if ( F_25 ( V_48 , V_46 , V_24 ) )
return - V_50 ;
V_48 [ V_24 ] = '\0' ;
( * ( V_4 -> V_12 -> V_27 ) ) ( V_48 , V_24 , V_25 , V_4 -> V_30 ) ;
return V_24 ;
}
