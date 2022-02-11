static int F_1 ( T_1 * V_1 )
{
T_2 * V_2 ;
V_2 = F_2 ( sizeof( * V_2 ) ) ;
if ( V_2 == NULL )
return 0 ;
V_2 -> V_3 = 1024 ;
V_2 -> V_4 = 160 ;
V_2 -> V_5 = NULL ;
V_2 -> V_6 = NULL ;
V_1 -> V_7 = V_2 ;
V_1 -> V_8 = V_2 -> V_9 ;
V_1 -> V_10 = 2 ;
return 1 ;
}
static int F_3 ( T_1 * V_11 , T_1 * V_12 )
{
T_2 * V_2 , * V_13 ;
if ( ! F_1 ( V_11 ) )
return 0 ;
V_13 = V_12 -> V_7 ;
V_2 = V_11 -> V_7 ;
V_2 -> V_3 = V_13 -> V_3 ;
V_2 -> V_4 = V_13 -> V_4 ;
V_2 -> V_5 = V_13 -> V_5 ;
V_2 -> V_6 = V_13 -> V_6 ;
return 1 ;
}
static void F_4 ( T_1 * V_1 )
{
T_2 * V_2 = V_1 -> V_7 ;
F_5 ( V_2 ) ;
}
static int F_6 ( T_1 * V_1 , unsigned char * V_14 ,
T_3 * V_15 , const unsigned char * V_16 ,
T_3 V_17 )
{
int V_18 ;
unsigned int V_19 ;
T_2 * V_2 = V_1 -> V_7 ;
T_4 * V_20 = V_1 -> V_21 -> V_21 . V_20 ;
if ( V_2 -> V_6 ) {
if ( V_17 != ( T_3 ) F_7 ( V_2 -> V_6 ) )
return 0 ;
} else {
if ( V_17 != V_22 )
return 0 ;
}
V_18 = F_8 ( 0 , V_16 , V_17 , V_14 , & V_19 , V_20 ) ;
if ( V_18 <= 0 )
return V_18 ;
* V_15 = V_19 ;
return 1 ;
}
static int F_9 ( T_1 * V_1 ,
const unsigned char * V_14 , T_3 V_15 ,
const unsigned char * V_16 , T_3 V_17 )
{
int V_18 ;
T_2 * V_2 = V_1 -> V_7 ;
T_4 * V_20 = V_1 -> V_21 -> V_21 . V_20 ;
if ( V_2 -> V_6 ) {
if ( V_17 != ( T_3 ) F_7 ( V_2 -> V_6 ) )
return 0 ;
} else {
if ( V_17 != V_22 )
return 0 ;
}
V_18 = F_10 ( 0 , V_16 , V_17 , V_14 , V_15 , V_20 ) ;
return V_18 ;
}
static int F_11 ( T_1 * V_1 , int type , int V_23 , void * V_24 )
{
T_2 * V_2 = V_1 -> V_7 ;
switch ( type ) {
case V_25 :
if ( V_23 < 256 )
return - 2 ;
V_2 -> V_3 = V_23 ;
return 1 ;
case V_26 :
if ( V_23 != 160 && V_23 != 224 && V_23 && V_23 != 256 )
return - 2 ;
V_2 -> V_4 = V_23 ;
return 1 ;
case V_27 :
if ( F_12 ( ( const V_28 * ) V_24 ) != V_29 &&
F_12 ( ( const V_28 * ) V_24 ) != V_30 &&
F_12 ( ( const V_28 * ) V_24 ) != V_31 ) {
F_13 ( V_32 , V_33 ) ;
return 0 ;
}
V_2 -> V_6 = V_24 ;
return 1 ;
case V_34 :
if ( F_12 ( ( const V_28 * ) V_24 ) != V_29 &&
F_12 ( ( const V_28 * ) V_24 ) != V_35 &&
F_12 ( ( const V_28 * ) V_24 ) != V_36 &&
F_12 ( ( const V_28 * ) V_24 ) != V_30 &&
F_12 ( ( const V_28 * ) V_24 ) != V_31 &&
F_12 ( ( const V_28 * ) V_24 ) != V_37 &&
F_12 ( ( const V_28 * ) V_24 ) != V_38 ) {
F_13 ( V_32 , V_33 ) ;
return 0 ;
}
V_2 -> V_6 = V_24 ;
return 1 ;
case V_39 :
* ( const V_28 * * ) V_24 = V_2 -> V_6 ;
return 1 ;
case V_40 :
case V_41 :
case V_42 :
return 1 ;
case V_43 :
F_13 ( V_32 ,
V_44 ) ;
return - 2 ;
default:
return - 2 ;
}
}
static int F_14 ( T_1 * V_1 ,
const char * type , const char * V_45 )
{
if ( strcmp ( type , L_1 ) == 0 ) {
int V_3 ;
V_3 = atoi ( V_45 ) ;
return F_15 ( V_1 , V_3 ) ;
}
if ( strcmp ( type , L_2 ) == 0 ) {
int V_4 = atoi ( V_45 ) ;
return F_16 ( V_1 , V_46 , V_47 ,
V_26 , V_4 ,
NULL ) ;
}
if ( strcmp ( type , L_3 ) == 0 ) {
return F_16 ( V_1 , V_46 , V_47 ,
V_27 , 0 ,
( void * ) F_17 ( V_45 ) ) ;
}
return - 2 ;
}
static int F_18 ( T_1 * V_1 , T_5 * V_21 )
{
T_4 * V_20 = NULL ;
T_2 * V_2 = V_1 -> V_7 ;
T_6 * V_48 ;
int V_18 ;
if ( V_1 -> V_49 ) {
V_48 = F_19 () ;
if ( V_48 == NULL )
return 0 ;
F_20 ( V_48 , V_1 ) ;
} else
V_48 = NULL ;
V_20 = F_21 () ;
if ( V_20 == NULL ) {
F_22 ( V_48 ) ;
return 0 ;
}
V_18 = F_23 ( V_20 , V_2 -> V_3 , V_2 -> V_4 , V_2 -> V_5 ,
NULL , 0 , NULL , NULL , NULL , V_48 ) ;
F_22 ( V_48 ) ;
if ( V_18 )
F_24 ( V_21 , V_20 ) ;
else
F_25 ( V_20 ) ;
return V_18 ;
}
static int F_26 ( T_1 * V_1 , T_5 * V_21 )
{
T_4 * V_20 = NULL ;
if ( V_1 -> V_21 == NULL ) {
F_13 ( V_50 , V_51 ) ;
return 0 ;
}
V_20 = F_21 () ;
if ( V_20 == NULL )
return 0 ;
F_24 ( V_21 , V_20 ) ;
if ( ! F_27 ( V_21 , V_1 -> V_21 ) )
return 0 ;
return F_28 ( V_21 -> V_21 . V_20 ) ;
}
