T_1 *
F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 * V_4 ;
V_4 = F_2 ( sizeof( T_1 ) ) ;
if ( V_4 != NULL ) {
if ( V_3 )
{
V_4 -> V_5 = F_2 ( V_3 ) ;
if ( V_4 -> V_5 == NULL ) {
F_3 ( V_4 ) ;
V_4 = NULL ;
return V_4 ;
}
}
} else {
return V_4 ;
}
V_4 -> V_6 = NULL ;
V_4 -> V_7 = NULL ;
V_4 -> V_8 = NULL ;
V_4 -> V_9 = NULL ;
V_4 -> V_10 = 0 ;
#ifdef F_4
V_4 -> V_11 = 0 ;
#endif
return V_4 ;
}
void
F_5 ( T_1 * V_4 )
{
if ( V_4 -> V_5 != NULL ) {
F_3 ( V_4 -> V_5 ) ;
}
F_3 ( V_4 ) ;
}
void
F_6 ( struct V_1 * V_2 , T_1 * V_4 ,
const T_2 * V_12 )
{
int V_13 ;
T_3 V_14 = 0 ;
memcpy ( V_4 -> V_15 , V_12 , V_16 ) ;
V_13 = F_7 ( V_12 ) ;
F_8 ( V_4 ) ;
V_14 = V_2 -> V_17 ;
V_4 -> V_18 = F_9 ( 0 ) ;
V_4 -> V_19 = V_20 ;
F_10 ( V_2 ) ;
V_4 -> V_6 = NULL ;
V_4 -> V_7 = V_2 -> V_21 ;
if( V_2 -> V_21 != NULL )
{
V_2 -> V_21 -> V_6 = V_4 ;
}
V_2 -> V_21 = V_4 ;
if( V_2 -> V_22 == NULL )
{
V_2 -> V_22 = V_4 ;
}
if( ( V_4 -> V_8 = V_2 -> V_23 [ V_13 ] ) != NULL )
{
V_2 -> V_23 [ V_13 ] -> V_9 = V_4 ;
}
V_4 -> V_9 = NULL ;
V_2 -> V_23 [ V_13 ] = V_4 ;
#ifdef F_11
if ( ! V_2 -> V_24 ) {
F_12 ( & V_2 -> V_25 , V_14 , 0 ) ;
V_2 -> V_24 = true ;
}
#endif
F_13 ( V_2 ) ;
}
static T_1 *
F_14 ( struct V_1 * V_2 ,
const T_2 * V_12 )
{
T_1 * V_4 ;
int V_13 ;
F_15 ( V_2 ) ;
V_13 = F_7 ( V_12 ) ;
for( V_4 = V_2 -> V_23 [ V_13 ] ; V_4 ; V_4 = V_4 -> V_8 ) {
if ( F_16 ( V_4 -> V_15 , V_12 ) ) {
F_17 ( V_4 ) ;
return V_4 ;
}
}
return NULL ;
}
T_1 *
F_18 ( struct V_1 * V_2 , const T_2 * V_12 )
{
T_1 * V_4 ;
F_19 ( V_2 ) ;
V_4 = F_14 ( V_2 , V_12 ) ;
F_20 ( V_2 ) ;
return V_4 ;
}
void
F_21 ( struct V_1 * V_2 , T_1 * V_4 )
{
F_19 ( V_2 ) ;
if( V_4 -> V_7 == NULL )
{
V_2 -> V_22 = V_4 -> V_6 ;
}
else
{
V_4 -> V_7 -> V_6 = V_4 -> V_6 ;
}
if( V_4 -> V_6 == NULL )
{
V_2 -> V_21 = V_4 -> V_7 ;
}
else
{
V_4 -> V_6 -> V_7 = V_4 -> V_7 ;
}
if( V_4 -> V_9 == NULL )
{
int V_13 ;
V_13 = F_7 ( V_4 -> V_15 ) ;
V_2 -> V_23 [ V_13 ] = V_4 -> V_8 ;
}
else
{
V_4 -> V_9 -> V_8 = V_4 -> V_8 ;
}
if( V_4 -> V_8 != NULL )
{
V_4 -> V_8 -> V_9 = V_4 -> V_9 ;
}
F_5 ( V_4 ) ;
F_20 ( V_2 ) ;
}
static void
F_22 ( T_1 * V_4 )
{
if ( F_23 ( V_4 ) ) {
F_5 ( V_4 ) ;
}
}
void
F_24 ( struct V_1 * V_2 )
{
T_1 * V_4 ;
while ( ( V_4 = V_2 -> V_22 ) != NULL ) {
F_21 ( V_2 , V_4 ) ;
}
}
void
F_25 ( struct V_1 * V_2 , T_4 * V_26 ,
void * V_27 )
{
T_1 * V_4 ;
T_3 V_28 ;
V_28 = ++ V_2 -> V_29 ;
F_19 ( V_2 ) ;
for ( V_4 = V_2 -> V_22 ; V_4 ; V_4 = V_4 -> V_6 ) {
if ( V_4 -> V_10 != V_28 ) {
V_4 -> V_10 = V_28 ;
( void ) F_17 ( V_4 ) ;
(* V_26)( V_27 , V_4 ) ;
F_22 ( V_4 ) ;
}
}
F_20 ( V_2 ) ;
}
void
F_26 ( void * V_30 , struct V_1 * V_2 )
{
int V_31 ;
F_27 ( V_32 , ( L_1 , ( unsigned long ) V_2 ) ) ;
F_28 ( V_2 ) ;
F_29 ( V_33 ) ;
V_2 -> V_22 = V_2 -> V_21 = NULL ;
for( V_31 = 0 ; V_31 < V_34 ; V_31 ++ )
{
V_2 -> V_23 [ V_31 ] = NULL ;
}
#ifdef F_11
F_30 ( & V_2 -> V_25 , V_35 , V_2 ) ;
V_2 -> V_24 = false ;
#endif
V_2 -> V_36 = V_30 ;
V_2 -> V_17 = V_37 ;
V_2 -> V_29 = 0 ;
#ifdef F_4
V_2 -> V_38 = 0 ;
#endif
}
void
F_31 ( struct V_1 * V_2 , T_3 V_39 )
{
V_2 -> V_17 = V_39 ;
return;
}
void
F_32 ( struct V_1 * V_2 )
{
#ifdef F_11
T_1 * V_40 , * V_41 ;
T_2 V_42 [ V_16 ] , V_43 = false ;
F_33 ( V_2 -> V_36 , V_42 ) ;
V_40 = V_2 -> V_22 ;
while ( V_40 != NULL )
{
V_41 = V_40 -> V_6 ;
if ( memcmp ( V_42 , V_40 -> V_15 , sizeof( V_42 ) ) != 0 )
{
F_21 ( V_2 , V_40 ) ;
}
V_40 = V_41 ;
}
#else
T_1 * V_40 , * V_41 ;
T_2 V_42 [ V_16 ] ;
T_3 V_14 = 0 ;
T_3 V_44 = F_9 ( 0 ) ;
V_14 = V_2 -> V_17 ;
F_33 ( V_2 -> V_36 , V_42 ) ;
V_40 = V_2 -> V_22 ;
while ( V_40 != NULL )
{
V_41 = V_40 -> V_6 ;
if ( memcmp ( V_42 , V_40 -> V_15 , sizeof( V_42 ) ) != 0 )
{
if ( ( ( V_44 - V_40 -> V_18 ) > V_14 ) || -- V_40 -> V_19 == 0 )
{
F_21 ( V_2 , V_40 ) ;
}
}
V_40 = V_41 ;
}
#endif
}
static void
V_35 ( unsigned long V_27 )
{
struct V_1 * V_2 = (struct V_1 * ) V_27 ;
T_1 * V_40 , * V_41 ;
T_2 V_42 [ V_16 ] , V_43 = false ;
T_3 V_14 = 0 ;
T_3 V_44 = F_9 ( 0 ) ;
V_14 = V_2 -> V_17 ;
F_33 ( V_2 -> V_36 , V_42 ) ;
V_40 = V_2 -> V_22 ;
while ( V_40 != NULL )
{
V_41 = V_40 -> V_6 ;
if ( memcmp ( V_42 , V_40 -> V_15 , sizeof( V_42 ) ) != 0 )
{
if ( ( V_44 - V_40 -> V_18 ) > V_14 )
{
F_21 ( V_2 , V_40 ) ;
}
else
{
V_43 = true ;
}
}
V_40 = V_41 ;
}
if ( V_43 )
F_12 ( & V_2 -> V_25 , V_14 , 0 ) ;
V_2 -> V_24 = V_43 ;
}
void
F_34 ( struct V_1 * V_2 )
{
#ifdef F_11
F_35 ( & V_2 -> V_25 ) ;
F_36 ( & V_2 -> V_25 ) ;
#endif
F_24 ( V_2 ) ;
F_37 ( V_2 ) ;
}
T_1 *
F_38 ( struct V_1 * V_2 , T_2 * V_45 ,
T_3 V_46 , bool V_47 , bool V_48 )
{
T_1 * V_4 = NULL ;
T_2 * V_49 = NULL ;
F_19 ( V_2 ) ;
for ( V_4 = V_2 -> V_22 ; V_4 ; V_4 = V_4 -> V_6 ) {
V_49 = V_4 -> V_50 . V_51 ;
if ( V_49 [ 1 ] <= 32 ) {
if ( 0x00 == memcmp ( V_45 , & V_49 [ 2 ] , V_46 ) ) {
if ( true == V_48 ) {
F_17 ( V_4 ) ;
F_20 ( V_2 ) ;
return V_4 ;
}
if ( true == V_47 && NULL != V_4 -> V_50 . V_52 ) {
F_17 ( V_4 ) ;
F_20 ( V_2 ) ;
return V_4 ;
}
if ( false == V_47 && NULL != V_4 -> V_50 . V_53 ) {
F_17 ( V_4 ) ;
F_20 ( V_2 ) ;
return V_4 ;
}
}
}
}
F_20 ( V_2 ) ;
return NULL ;
}
void
F_39 ( struct V_1 * V_2 , T_1 * V_4 )
{
F_19 ( V_2 ) ;
F_22 ( V_4 ) ;
F_20 ( V_2 ) ;
}
void
F_40 ( struct V_1 * V_2 , T_1 * V_4 )
{
if( V_4 -> V_7 == NULL )
{
V_2 -> V_22 = V_4 -> V_6 ;
}
else
{
V_4 -> V_7 -> V_6 = V_4 -> V_6 ;
}
if( V_4 -> V_6 == NULL )
{
V_2 -> V_21 = V_4 -> V_7 ;
}
else
{
V_4 -> V_6 -> V_7 = V_4 -> V_7 ;
}
if( V_4 -> V_9 == NULL )
{
int V_13 ;
V_13 = F_7 ( V_4 -> V_15 ) ;
V_2 -> V_23 [ V_13 ] = V_4 -> V_8 ;
}
else
{
V_4 -> V_9 -> V_8 = V_4 -> V_8 ;
}
if( V_4 -> V_8 != NULL )
{
V_4 -> V_8 -> V_9 = V_4 -> V_9 ;
}
}
T_1 *
F_41 ( struct V_1 * V_2 , T_2 * V_54 )
{
T_1 * V_40 , * V_41 ;
F_19 ( V_2 ) ;
V_40 = V_2 -> V_22 ;
while ( V_40 != NULL )
{
V_41 = V_40 -> V_6 ;
if ( memcmp ( V_54 , V_40 -> V_15 , 6 ) == 0 )
{
F_40 ( V_2 , V_40 ) ;
F_20 ( V_2 ) ;
return V_40 ;
}
V_40 = V_41 ;
}
F_20 ( V_2 ) ;
return NULL ;
}
T_1 *
F_42 ( struct V_1 * V_2 , T_2 * V_45 ,
T_3 V_46 , T_3 V_55 , T_3 V_56 ,
T_3 V_57 , T_3 V_58 )
{
T_1 * V_4 = NULL ;
T_1 * V_59 = NULL ;
T_2 * V_49 = NULL ;
F_19 ( V_2 ) ;
for ( V_4 = V_2 -> V_22 ; V_4 ; V_4 = V_4 -> V_6 ) {
V_49 = V_4 -> V_50 . V_51 ;
if ( V_49 [ 1 ] <= 32 ) {
if ( 0x00 == memcmp ( V_45 , & V_49 [ 2 ] , V_46 ) ) {
if ( V_4 -> V_50 . V_60 & 0x10 )
{
if ( ( NULL != V_4 -> V_50 . V_52 ) && ( V_61 == V_56 ) )
{
if ( NULL == V_59 )
{
V_59 = V_4 ;
}
else if ( V_4 -> V_62 > V_59 -> V_62 )
{
V_59 = V_4 ;
}
}
else if ( ( NULL != V_4 -> V_50 . V_53 ) && ( V_63 == V_56 ) )
{
if ( NULL == V_59 )
{
V_59 = V_4 ;
}
else if ( V_4 -> V_62 > V_59 -> V_62 )
{
V_59 = V_4 ;
}
}
else if ( V_64 == V_57 )
{
if ( NULL == V_59 )
{
V_59 = V_4 ;
}
else if ( V_4 -> V_62 > V_59 -> V_62 )
{
V_59 = V_4 ;
}
}
}
else
{
if ( ( V_65 == V_56 ) && ( V_66 == V_57 ) )
{
if ( NULL == V_59 )
{
V_59 = V_4 ;
}
else if ( V_4 -> V_62 > V_59 -> V_62 )
{
V_59 = V_4 ;
}
}
}
}
}
}
F_20 ( V_2 ) ;
return V_59 ;
}
