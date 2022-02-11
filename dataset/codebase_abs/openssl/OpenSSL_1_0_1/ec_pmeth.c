static int F_1 ( T_1 * V_1 )
{
T_2 * V_2 ;
V_2 = F_2 ( sizeof( T_2 ) ) ;
if ( ! V_2 )
return 0 ;
V_2 -> V_3 = NULL ;
V_2 -> V_4 = NULL ;
V_1 -> V_5 = V_2 ;
return 1 ;
}
static int F_3 ( T_1 * V_6 , T_1 * V_7 )
{
T_2 * V_2 , * V_8 ;
if ( ! F_1 ( V_6 ) )
return 0 ;
V_8 = V_7 -> V_5 ;
V_2 = V_6 -> V_5 ;
if ( V_8 -> V_3 )
{
V_2 -> V_3 = F_4 ( V_8 -> V_3 ) ;
if ( ! V_2 -> V_3 )
return 0 ;
}
V_2 -> V_4 = V_8 -> V_4 ;
return 1 ;
}
static void F_5 ( T_1 * V_1 )
{
T_2 * V_2 = V_1 -> V_5 ;
if ( V_2 )
{
if ( V_2 -> V_3 )
F_6 ( V_2 -> V_3 ) ;
F_7 ( V_2 ) ;
}
}
static int F_8 ( T_1 * V_1 , unsigned char * V_9 , T_3 * V_10 ,
const unsigned char * V_11 , T_3 V_12 )
{
int V_13 , type ;
unsigned int V_14 ;
T_2 * V_2 = V_1 -> V_5 ;
T_4 * V_15 = V_1 -> V_16 -> V_16 . V_15 ;
if ( ! V_9 )
{
* V_10 = F_9 ( V_15 ) ;
return 1 ;
}
else if( * V_10 < ( T_3 ) F_9 ( V_15 ) )
{
F_10 ( V_17 , V_18 ) ;
return 0 ;
}
if ( V_2 -> V_4 )
type = F_11 ( V_2 -> V_4 ) ;
else
type = V_19 ;
V_13 = F_12 ( type , V_11 , V_12 , V_9 , & V_14 , V_15 ) ;
if ( V_13 <= 0 )
return V_13 ;
* V_10 = ( T_3 ) V_14 ;
return 1 ;
}
static int F_13 ( T_1 * V_1 ,
const unsigned char * V_9 , T_3 V_10 ,
const unsigned char * V_11 , T_3 V_12 )
{
int V_13 , type ;
T_2 * V_2 = V_1 -> V_5 ;
T_4 * V_15 = V_1 -> V_16 -> V_16 . V_15 ;
if ( V_2 -> V_4 )
type = F_11 ( V_2 -> V_4 ) ;
else
type = V_19 ;
V_13 = F_14 ( type , V_11 , V_12 , V_9 , V_10 , V_15 ) ;
return V_13 ;
}
static int F_15 ( T_1 * V_1 , unsigned char * V_20 , T_3 * V_21 )
{
int V_13 ;
T_3 V_22 ;
const T_5 * V_23 = NULL ;
if ( ! V_1 -> V_16 || ! V_1 -> V_24 )
{
F_10 ( V_25 , V_26 ) ;
return 0 ;
}
if ( ! V_20 )
{
const T_6 * V_27 ;
V_27 = F_16 ( V_1 -> V_16 -> V_16 . V_15 ) ;
* V_21 = ( F_17 ( V_27 ) + 7 ) / 8 ;
return 1 ;
}
V_23 = F_18 ( V_1 -> V_24 -> V_16 . V_15 ) ;
V_22 = * V_21 ;
V_13 = F_19 ( V_20 , V_22 , V_23 , V_1 -> V_16 -> V_16 . V_15 , 0 ) ;
if ( V_13 < 0 )
return V_13 ;
* V_21 = V_13 ;
return 1 ;
}
static int F_20 ( T_1 * V_1 , int type , int V_28 , void * V_29 )
{
T_2 * V_2 = V_1 -> V_5 ;
T_6 * V_27 ;
switch ( type )
{
case V_30 :
V_27 = F_21 ( V_28 ) ;
if ( V_27 == NULL )
{
F_10 ( V_31 , V_32 ) ;
return 0 ;
}
if ( V_2 -> V_3 )
F_6 ( V_2 -> V_3 ) ;
V_2 -> V_3 = V_27 ;
return 1 ;
case V_33 :
if ( F_11 ( ( const V_34 * ) V_29 ) != V_19 &&
F_11 ( ( const V_34 * ) V_29 ) != V_35 &&
F_11 ( ( const V_34 * ) V_29 ) != V_36 &&
F_11 ( ( const V_34 * ) V_29 ) != V_37 &&
F_11 ( ( const V_34 * ) V_29 ) != V_38 &&
F_11 ( ( const V_34 * ) V_29 ) != V_39 )
{
F_10 ( V_31 , V_40 ) ;
return 0 ;
}
V_2 -> V_4 = V_29 ;
return 1 ;
case V_41 :
case V_42 :
case V_43 :
case V_44 :
return 1 ;
default:
return - 2 ;
}
}
static int F_22 ( T_1 * V_1 ,
const char * type , const char * V_45 )
{
if ( ! strcmp ( type , L_1 ) )
{
int V_46 ;
V_46 = F_23 ( V_45 ) ;
if ( V_46 == V_47 )
V_46 = F_24 ( V_45 ) ;
if ( V_46 == V_47 )
{
F_10 ( V_48 , V_32 ) ;
return 0 ;
}
return F_25 ( V_1 , V_46 ) ;
}
return - 2 ;
}
static int F_26 ( T_1 * V_1 , T_7 * V_16 )
{
T_4 * V_15 = NULL ;
T_2 * V_2 = V_1 -> V_5 ;
int V_13 = 0 ;
if ( V_2 -> V_3 == NULL )
{
F_10 ( V_49 , V_50 ) ;
return 0 ;
}
V_15 = F_27 () ;
if ( ! V_15 )
return 0 ;
V_13 = F_28 ( V_15 , V_2 -> V_3 ) ;
if ( V_13 )
F_29 ( V_16 , V_15 ) ;
else
F_30 ( V_15 ) ;
return V_13 ;
}
static int F_31 ( T_1 * V_1 , T_7 * V_16 )
{
T_4 * V_15 = NULL ;
if ( V_1 -> V_16 == NULL )
{
F_10 ( V_51 , V_50 ) ;
return 0 ;
}
V_15 = F_27 () ;
if ( ! V_15 )
return 0 ;
F_29 ( V_16 , V_15 ) ;
if ( ! F_32 ( V_16 , V_1 -> V_16 ) )
return 0 ;
return F_33 ( V_16 -> V_16 . V_15 ) ;
}
