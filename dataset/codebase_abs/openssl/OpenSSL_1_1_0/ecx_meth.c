static int F_1 ( T_1 * V_1 , const T_2 * V_2 ,
const unsigned char * V_3 , int V_4 , T_3 V_5 )
{
T_4 * V_6 ;
if ( V_5 != V_7 ) {
if ( V_2 != NULL ) {
int V_8 ;
F_2 ( NULL , & V_8 , NULL , V_2 ) ;
if ( V_8 != V_9 ) {
F_3 ( V_10 , V_11 ) ;
return 0 ;
}
}
if ( V_3 == NULL || V_4 != V_12 ) {
F_3 ( V_10 , V_11 ) ;
return 0 ;
}
}
V_6 = F_4 ( sizeof( * V_6 ) ) ;
if ( V_6 == NULL ) {
F_3 ( V_10 , V_13 ) ;
return 0 ;
}
if ( V_5 == V_14 ) {
memcpy ( V_6 -> V_15 , V_3 , V_4 ) ;
} else {
V_6 -> V_16 = F_5 ( V_12 ) ;
if ( V_6 -> V_16 == NULL ) {
F_3 ( V_10 , V_13 ) ;
F_6 ( V_6 ) ;
return 0 ;
}
if ( V_5 == V_7 ) {
if ( F_7 ( V_6 -> V_16 , V_12 ) <= 0 ) {
F_8 ( V_6 -> V_16 ) ;
F_6 ( V_6 ) ;
return 0 ;
}
V_6 -> V_16 [ 0 ] &= 248 ;
V_6 -> V_16 [ 31 ] &= 127 ;
V_6 -> V_16 [ 31 ] |= 64 ;
} else {
memcpy ( V_6 -> V_16 , V_3 , V_12 ) ;
}
F_9 ( V_6 -> V_15 , V_6 -> V_16 ) ;
}
F_10 ( V_1 , V_17 , V_6 ) ;
return 1 ;
}
static int F_11 ( T_5 * V_18 , const T_1 * V_1 )
{
const T_4 * V_6 = V_1 -> V_1 . V_19 ;
unsigned char * V_20 ;
if ( V_6 == NULL ) {
F_3 ( V_21 , V_22 ) ;
return 0 ;
}
V_20 = F_12 ( V_6 -> V_15 , V_12 ) ;
if ( V_20 == NULL ) {
F_3 ( V_21 , V_13 ) ;
return 0 ;
}
if ( ! F_13 ( V_18 , F_14 ( V_17 ) , V_9 ,
NULL , V_20 , V_12 ) ) {
F_6 ( V_20 ) ;
F_3 ( V_21 , V_13 ) ;
return 0 ;
}
return 1 ;
}
static int F_15 ( T_1 * V_1 , T_5 * V_15 )
{
const unsigned char * V_3 ;
int V_23 ;
T_2 * V_2 ;
if ( ! F_16 ( NULL , & V_3 , & V_23 , & V_2 , V_15 ) )
return 0 ;
return F_1 ( V_1 , V_2 , V_3 , V_23 , V_14 ) ;
}
static int F_17 ( const T_1 * V_24 , const T_1 * V_25 )
{
const T_4 * V_26 = V_24 -> V_1 . V_19 ;
const T_4 * V_27 = V_25 -> V_1 . V_19 ;
if ( V_26 == NULL || V_27 == NULL )
return - 2 ;
return ! F_18 ( V_26 -> V_15 , V_27 -> V_15 , V_12 ) ;
}
static int F_19 ( T_1 * V_1 , const T_6 * V_28 )
{
const unsigned char * V_3 ;
int V_4 ;
T_7 * V_29 = NULL ;
const T_2 * V_2 ;
int V_30 ;
if ( ! F_20 ( NULL , & V_3 , & V_4 , & V_2 , V_28 ) )
return 0 ;
V_29 = F_21 ( NULL , & V_3 , V_4 ) ;
if ( V_29 == NULL ) {
V_3 = NULL ;
V_4 = 0 ;
} else {
V_3 = F_22 ( V_29 ) ;
V_4 = F_23 ( V_29 ) ;
}
V_30 = F_1 ( V_1 , V_2 , V_3 , V_4 , V_31 ) ;
F_24 ( V_29 ) ;
return V_30 ;
}
static int F_25 ( T_6 * V_28 , const T_1 * V_1 )
{
const T_4 * V_6 = V_1 -> V_1 . V_19 ;
T_7 V_29 ;
unsigned char * V_20 = NULL ;
int V_32 ;
if ( V_6 == NULL || V_6 -> V_16 == NULL ) {
F_3 ( V_33 , V_34 ) ;
return 0 ;
}
V_29 . V_35 = V_6 -> V_16 ;
V_29 . V_36 = V_12 ;
V_29 . V_37 = 0 ;
V_32 = F_26 ( & V_29 , & V_20 ) ;
if ( V_32 < 0 ) {
F_3 ( V_33 , V_13 ) ;
return 0 ;
}
if ( ! F_27 ( V_28 , F_14 ( V_17 ) , 0 ,
V_9 , NULL , V_20 , V_32 ) ) {
F_28 ( V_20 , V_32 ) ;
F_3 ( V_33 , V_13 ) ;
return 0 ;
}
return 1 ;
}
static int F_29 ( const T_1 * V_1 )
{
return V_12 ;
}
static int F_30 ( const T_1 * V_1 )
{
return V_38 ;
}
static int F_31 ( const T_1 * V_1 )
{
return V_39 ;
}
static void F_32 ( T_1 * V_1 )
{
T_4 * V_6 = V_1 -> V_1 . V_19 ;
if ( V_6 )
F_8 ( V_6 -> V_16 ) ;
F_6 ( V_6 ) ;
}
static int F_33 ( const T_1 * V_24 , const T_1 * V_25 )
{
return 1 ;
}
static int F_34 ( T_8 * V_40 , const T_1 * V_1 , int V_41 ,
T_9 * V_42 , T_3 V_5 )
{
const T_4 * V_6 = V_1 -> V_1 . V_19 ;
if ( V_5 == V_31 ) {
if ( V_6 == NULL || V_6 -> V_16 == NULL ) {
if ( F_35 ( V_40 , L_1 , V_41 , L_2 ) <= 0 )
return 0 ;
return 1 ;
}
if ( F_35 ( V_40 , L_3 , V_41 , L_2 ) <= 0 )
return 0 ;
if ( F_35 ( V_40 , L_4 , V_41 , L_2 ) <= 0 )
return 0 ;
if ( F_36 ( V_40 , V_6 -> V_16 , V_12 , V_41 + 4 ) == 0 )
return 0 ;
} else {
if ( V_6 == NULL ) {
if ( F_35 ( V_40 , L_5 , V_41 , L_2 ) <= 0 )
return 0 ;
return 1 ;
}
if ( F_35 ( V_40 , L_6 , V_41 , L_2 ) <= 0 )
return 0 ;
}
if ( F_35 ( V_40 , L_7 , V_41 , L_2 ) <= 0 )
return 0 ;
if ( F_36 ( V_40 , V_6 -> V_15 , V_12 , V_41 + 4 ) == 0 )
return 0 ;
return 1 ;
}
static int F_37 ( T_8 * V_40 , const T_1 * V_1 , int V_41 ,
T_9 * V_42 )
{
return F_34 ( V_40 , V_1 , V_41 , V_42 , V_31 ) ;
}
static int F_38 ( T_8 * V_40 , const T_1 * V_1 , int V_41 ,
T_9 * V_42 )
{
return F_34 ( V_40 , V_1 , V_41 , V_42 , V_14 ) ;
}
static int F_39 ( T_1 * V_1 , int V_5 , long V_43 , void * V_44 )
{
switch ( V_5 ) {
case V_45 :
return F_1 ( V_1 , NULL , V_44 , V_43 , V_14 ) ;
case V_46 :
if ( V_1 -> V_1 . V_19 != NULL ) {
const T_4 * V_6 = V_1 -> V_1 . V_19 ;
unsigned char * * V_47 = V_44 ;
* V_47 = F_12 ( V_6 -> V_15 , V_12 ) ;
if ( * V_47 != NULL )
return V_12 ;
}
return 0 ;
case V_48 :
* ( int * ) V_44 = V_49 ;
return 2 ;
default:
return - 2 ;
}
}
static int F_40 ( T_10 * V_42 , T_1 * V_1 )
{
return F_1 ( V_1 , NULL , NULL , 0 , V_7 ) ;
}
static int F_41 ( T_10 * V_42 , unsigned char * V_50 ,
T_11 * V_51 )
{
const T_4 * V_1 , * V_52 ;
if ( V_42 -> V_1 == NULL || V_42 -> V_52 == NULL ) {
F_3 ( V_53 , V_54 ) ;
return 0 ;
}
V_1 = V_42 -> V_1 -> V_1 . V_19 ;
V_52 = V_42 -> V_52 -> V_1 . V_19 ;
if ( V_1 == NULL || V_1 -> V_16 == NULL ) {
F_3 ( V_53 , V_34 ) ;
return 0 ;
}
if ( V_52 == NULL ) {
F_3 ( V_53 , V_55 ) ;
return 0 ;
}
* V_51 = V_12 ;
if ( V_50 != NULL && F_42 ( V_50 , V_1 -> V_16 , V_52 -> V_15 ) == 0 )
return 0 ;
return 1 ;
}
static int F_43 ( T_10 * V_42 , int type , int V_56 , void * V_57 )
{
if ( type == V_58 )
return 1 ;
return - 2 ;
}
