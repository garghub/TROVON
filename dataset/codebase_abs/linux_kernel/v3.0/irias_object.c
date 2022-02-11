struct V_1 * F_1 ( char * V_2 , int V_3 )
{
struct V_1 * V_4 ;
F_2 ( 4 , L_1 , V_5 ) ;
V_4 = F_3 ( sizeof( struct V_1 ) , V_6 ) ;
if ( V_4 == NULL ) {
F_4 ( L_2 ,
V_5 ) ;
return NULL ;
}
V_4 -> V_7 = V_8 ;
V_4 -> V_2 = F_5 ( V_2 , V_9 , V_6 ) ;
if ( ! V_4 -> V_2 ) {
F_4 ( L_3 ,
V_5 ) ;
F_6 ( V_4 ) ;
return NULL ;
}
V_4 -> V_3 = V_3 ;
V_4 -> V_10 = F_7 ( V_11 ) ;
if ( V_4 -> V_10 == NULL ) {
F_4 ( L_4 ,
V_5 ) ;
F_6 ( V_4 -> V_2 ) ;
F_6 ( V_4 ) ;
return NULL ;
}
return V_4 ;
}
static void F_8 ( struct V_12 * V_13 )
{
F_9 (attrib != NULL, return;) ;
F_9 (attrib->magic == IAS_ATTRIB_MAGIC, return;) ;
F_6 ( V_13 -> V_2 ) ;
F_10 ( V_13 -> V_14 ) ;
V_13 -> V_7 = ~ V_15 ;
F_6 ( V_13 ) ;
}
void F_11 ( struct V_1 * V_4 )
{
F_9 (obj != NULL, return;) ;
F_9 (obj->magic == IAS_OBJECT_MAGIC, return;) ;
F_6 ( V_4 -> V_2 ) ;
F_12 ( V_4 -> V_10 , ( V_16 ) F_8 ) ;
V_4 -> V_7 = ~ V_8 ;
F_6 ( V_4 ) ;
}
int F_13 ( struct V_1 * V_4 )
{
struct V_1 * V_17 ;
F_9 (obj != NULL, return -1;) ;
F_9 (obj->magic == IAS_OBJECT_MAGIC, return -1;) ;
V_17 = F_14 ( V_18 , ( V_19 * ) V_4 ) ;
if ( ! V_17 )
F_2 ( 0 , L_5 ,
V_5 ) ;
F_11 ( V_4 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_4 , struct V_12 * V_13 ,
int V_20 )
{
struct V_12 * V_17 ;
F_9 (obj != NULL, return -1;) ;
F_9 (obj->magic == IAS_OBJECT_MAGIC, return -1;) ;
F_9 (attrib != NULL, return -1;) ;
V_17 = F_14 ( V_4 -> V_10 , ( V_19 * ) V_13 ) ;
if ( ! V_17 )
return 0 ;
F_8 ( V_17 ) ;
V_17 = (struct V_12 * ) F_16 ( V_4 -> V_10 ) ;
if ( V_20 && ! V_17 )
F_13 ( V_4 ) ;
return 0 ;
}
void F_17 ( struct V_1 * V_4 )
{
F_9 (obj != NULL, return;) ;
F_9 (obj->magic == IAS_OBJECT_MAGIC, return;) ;
F_18 ( V_18 , ( V_19 * ) V_4 , 0 , V_4 -> V_2 ) ;
}
struct V_1 * F_19 ( char * V_2 )
{
F_9 (name != NULL, return NULL;) ;
return F_20 ( V_18 , 0 , V_2 ) ;
}
struct V_12 * F_21 ( struct V_1 * V_4 , char * V_2 )
{
struct V_12 * V_13 ;
F_9 (obj != NULL, return NULL;) ;
F_9 (obj->magic == IAS_OBJECT_MAGIC, return NULL;) ;
F_9 (name != NULL, return NULL;) ;
V_13 = F_20 ( V_4 -> V_10 , 0 , V_2 ) ;
if ( V_13 == NULL )
return NULL ;
return V_13 ;
}
static void F_22 ( struct V_1 * V_4 , struct V_12 * V_13 ,
int V_21 )
{
F_9 (obj != NULL, return;) ;
F_9 (obj->magic == IAS_OBJECT_MAGIC, return;) ;
F_9 (attrib != NULL, return;) ;
F_9 (attrib->magic == IAS_ATTRIB_MAGIC, return;) ;
V_13 -> V_14 -> V_21 = V_21 ;
F_18 ( V_4 -> V_10 , ( V_19 * ) V_13 , 0 , V_13 -> V_2 ) ;
}
int F_23 ( char * V_22 , char * V_23 ,
struct V_24 * V_25 )
{
struct V_1 * V_4 ;
struct V_12 * V_13 ;
unsigned long V_26 ;
V_4 = F_20 ( V_18 , 0 , V_22 ) ;
if ( V_4 == NULL ) {
F_4 ( L_6 , V_5 ,
V_22 ) ;
return - 1 ;
}
F_24 ( & V_4 -> V_10 -> V_27 , V_26 ) ;
V_13 = F_25 ( V_4 -> V_10 , 0 , V_23 ) ;
if ( V_13 == NULL ) {
F_4 ( L_7 ,
V_5 , V_23 ) ;
F_26 ( & V_4 -> V_10 -> V_27 , V_26 ) ;
return - 1 ;
}
if ( V_13 -> V_14 -> type != V_25 -> type ) {
F_2 ( 0 , L_8 ,
V_5 ) ;
F_26 ( & V_4 -> V_10 -> V_27 , V_26 ) ;
return - 1 ;
}
F_10 ( V_13 -> V_14 ) ;
V_13 -> V_14 = V_25 ;
F_26 ( & V_4 -> V_10 -> V_27 , V_26 ) ;
return 0 ;
}
void F_27 ( struct V_1 * V_4 , char * V_2 , int V_14 ,
int V_21 )
{
struct V_12 * V_13 ;
F_9 (obj != NULL, return;) ;
F_9 (obj->magic == IAS_OBJECT_MAGIC, return;) ;
F_9 (name != NULL, return;) ;
V_13 = F_3 ( sizeof( struct V_12 ) , V_6 ) ;
if ( V_13 == NULL ) {
F_4 ( L_9 ,
V_5 ) ;
return;
}
V_13 -> V_7 = V_15 ;
V_13 -> V_2 = F_5 ( V_2 , V_28 , V_6 ) ;
V_13 -> V_14 = F_28 ( V_14 ) ;
if ( ! V_13 -> V_2 || ! V_13 -> V_14 ) {
F_4 ( L_9 ,
V_5 ) ;
if ( V_13 -> V_14 )
F_10 ( V_13 -> V_14 ) ;
F_6 ( V_13 -> V_2 ) ;
F_6 ( V_13 ) ;
return;
}
F_22 ( V_4 , V_13 , V_21 ) ;
}
void F_29 ( struct V_1 * V_4 , char * V_2 , T_1 * V_29 ,
int V_30 , int V_21 )
{
struct V_12 * V_13 ;
F_9 (obj != NULL, return;) ;
F_9 (obj->magic == IAS_OBJECT_MAGIC, return;) ;
F_9 (name != NULL, return;) ;
F_9 (octets != NULL, return;) ;
V_13 = F_3 ( sizeof( struct V_12 ) , V_6 ) ;
if ( V_13 == NULL ) {
F_4 ( L_9 ,
V_5 ) ;
return;
}
V_13 -> V_7 = V_15 ;
V_13 -> V_2 = F_5 ( V_2 , V_28 , V_6 ) ;
V_13 -> V_14 = F_30 ( V_29 , V_30 ) ;
if ( ! V_13 -> V_2 || ! V_13 -> V_14 ) {
F_4 ( L_9 ,
V_5 ) ;
if ( V_13 -> V_14 )
F_10 ( V_13 -> V_14 ) ;
F_6 ( V_13 -> V_2 ) ;
F_6 ( V_13 ) ;
return;
}
F_22 ( V_4 , V_13 , V_21 ) ;
}
void F_31 ( struct V_1 * V_4 , char * V_2 , char * V_14 ,
int V_21 )
{
struct V_12 * V_13 ;
F_9 (obj != NULL, return;) ;
F_9 (obj->magic == IAS_OBJECT_MAGIC, return;) ;
F_9 (name != NULL, return;) ;
F_9 (value != NULL, return;) ;
V_13 = F_3 ( sizeof( struct V_12 ) , V_6 ) ;
if ( V_13 == NULL ) {
F_4 ( L_9 ,
V_5 ) ;
return;
}
V_13 -> V_7 = V_15 ;
V_13 -> V_2 = F_5 ( V_2 , V_28 , V_6 ) ;
V_13 -> V_14 = F_32 ( V_14 ) ;
if ( ! V_13 -> V_2 || ! V_13 -> V_14 ) {
F_4 ( L_9 ,
V_5 ) ;
if ( V_13 -> V_14 )
F_10 ( V_13 -> V_14 ) ;
F_6 ( V_13 -> V_2 ) ;
F_6 ( V_13 ) ;
return;
}
F_22 ( V_4 , V_13 , V_21 ) ;
}
struct V_24 * F_28 ( int integer )
{
struct V_24 * V_14 ;
V_14 = F_3 ( sizeof( struct V_24 ) , V_6 ) ;
if ( V_14 == NULL ) {
F_4 ( L_10 , V_5 ) ;
return NULL ;
}
V_14 -> type = V_31 ;
V_14 -> V_30 = 4 ;
V_14 -> V_32 . integer = integer ;
return V_14 ;
}
struct V_24 * F_32 ( char * string )
{
struct V_24 * V_14 ;
V_14 = F_3 ( sizeof( struct V_24 ) , V_6 ) ;
if ( V_14 == NULL ) {
F_4 ( L_10 , V_5 ) ;
return NULL ;
}
V_14 -> type = V_33 ;
V_14 -> V_34 = V_35 ;
V_14 -> V_32 . string = F_5 ( string , V_36 , V_6 ) ;
if ( ! V_14 -> V_32 . string ) {
F_4 ( L_10 , V_5 ) ;
F_6 ( V_14 ) ;
return NULL ;
}
V_14 -> V_30 = strlen ( V_14 -> V_32 . string ) ;
return V_14 ;
}
struct V_24 * F_30 ( T_1 * V_37 , int V_30 )
{
struct V_24 * V_14 ;
V_14 = F_3 ( sizeof( struct V_24 ) , V_6 ) ;
if ( V_14 == NULL ) {
F_4 ( L_10 , V_5 ) ;
return NULL ;
}
V_14 -> type = V_38 ;
if( V_30 > V_39 )
V_30 = V_39 ;
V_14 -> V_30 = V_30 ;
V_14 -> V_32 . V_40 = F_33 ( V_37 , V_30 , V_6 ) ;
if ( V_14 -> V_32 . V_40 == NULL ) {
F_4 ( L_10 , V_5 ) ;
F_6 ( V_14 ) ;
return NULL ;
}
return V_14 ;
}
struct V_24 * F_34 ( void )
{
struct V_24 * V_14 ;
V_14 = F_3 ( sizeof( struct V_24 ) , V_6 ) ;
if ( V_14 == NULL ) {
F_4 ( L_10 , V_5 ) ;
return NULL ;
}
V_14 -> type = V_41 ;
return V_14 ;
}
void F_10 ( struct V_24 * V_14 )
{
F_2 ( 4 , L_1 , V_5 ) ;
F_9 (value != NULL, return;) ;
switch ( V_14 -> type ) {
case V_31 :
case V_41 :
break;
case V_33 :
F_6 ( V_14 -> V_32 . string ) ;
break;
case V_38 :
F_6 ( V_14 -> V_32 . V_40 ) ;
break;
default:
F_2 ( 0 , L_11 , V_5 ) ;
break;
}
F_6 ( V_14 ) ;
}
