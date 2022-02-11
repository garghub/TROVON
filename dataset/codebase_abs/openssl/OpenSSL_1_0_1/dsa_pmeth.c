static int F_1 ( T_1 * V_1 )
{
T_2 * V_2 ;
V_2 = F_2 ( sizeof( T_2 ) ) ;
if ( ! V_2 )
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
if ( V_2 )
F_5 ( V_2 ) ;
}
static int F_6 ( T_1 * V_1 , unsigned char * V_14 , T_3 * V_15 ,
const unsigned char * V_16 , T_3 V_17 )
{
int V_18 , type ;
unsigned int V_19 ;
T_2 * V_2 = V_1 -> V_7 ;
T_4 * V_20 = V_1 -> V_21 -> V_21 . V_20 ;
if ( V_2 -> V_6 )
type = F_7 ( V_2 -> V_6 ) ;
else
type = V_22 ;
V_18 = F_8 ( type , V_16 , V_17 , V_14 , & V_19 , V_20 ) ;
if ( V_18 <= 0 )
return V_18 ;
* V_15 = V_19 ;
return 1 ;
}
static int F_9 ( T_1 * V_1 ,
const unsigned char * V_14 , T_3 V_15 ,
const unsigned char * V_16 , T_3 V_17 )
{
int V_18 , type ;
T_2 * V_2 = V_1 -> V_7 ;
T_4 * V_20 = V_1 -> V_21 -> V_21 . V_20 ;
if ( V_2 -> V_6 )
type = F_7 ( V_2 -> V_6 ) ;
else
type = V_22 ;
V_18 = F_10 ( type , V_16 , V_17 , V_14 , V_15 , V_20 ) ;
return V_18 ;
}
static int F_11 ( T_1 * V_1 , int type , int V_23 , void * V_24 )
{
T_2 * V_2 = V_1 -> V_7 ;
switch ( type )
{
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
if ( F_7 ( ( const V_28 * ) V_24 ) != V_22 &&
F_7 ( ( const V_28 * ) V_24 ) != V_29 &&
F_7 ( ( const V_28 * ) V_24 ) != V_30 )
{
F_12 ( V_31 , V_32 ) ;
return 0 ;
}
V_2 -> V_6 = V_24 ;
return 1 ;
case V_33 :
if ( F_7 ( ( const V_28 * ) V_24 ) != V_22 &&
F_7 ( ( const V_28 * ) V_24 ) != V_34 &&
F_7 ( ( const V_28 * ) V_24 ) != V_35 &&
F_7 ( ( const V_28 * ) V_24 ) != V_29 &&
F_7 ( ( const V_28 * ) V_24 ) != V_30 &&
F_7 ( ( const V_28 * ) V_24 ) != V_36 &&
F_7 ( ( const V_28 * ) V_24 ) != V_37 )
{
F_12 ( V_31 , V_32 ) ;
return 0 ;
}
V_2 -> V_6 = V_24 ;
return 1 ;
case V_38 :
case V_39 :
case V_40 :
return 1 ;
case V_41 :
F_12 ( V_31 ,
V_42 ) ;
return - 2 ;
default:
return - 2 ;
}
}
static int F_13 ( T_1 * V_1 ,
const char * type , const char * V_43 )
{
if ( ! strcmp ( type , L_1 ) )
{
int V_3 ;
V_3 = atoi ( V_43 ) ;
return F_14 ( V_1 , V_3 ) ;
}
if ( ! strcmp ( type , L_2 ) )
{
int V_4 = atoi ( V_43 ) ;
return F_15 ( V_1 , V_44 , V_45 ,
V_26 , V_4 , NULL ) ;
}
if ( ! strcmp ( type , L_3 ) )
{
return F_15 ( V_1 , V_44 , V_45 ,
V_27 , 0 ,
( void * ) F_16 ( V_43 ) ) ;
}
return - 2 ;
}
static int F_17 ( T_1 * V_1 , T_5 * V_21 )
{
T_4 * V_20 = NULL ;
T_2 * V_2 = V_1 -> V_7 ;
T_6 * V_46 , V_47 ;
int V_18 ;
if ( V_1 -> V_48 )
{
V_46 = & V_47 ;
F_18 ( V_46 , V_1 ) ;
}
else
V_46 = NULL ;
V_20 = F_19 () ;
if ( ! V_20 )
return 0 ;
V_18 = F_20 ( V_20 , V_2 -> V_3 , V_2 -> V_4 , V_2 -> V_5 ,
NULL , 0 , NULL , NULL , NULL , V_46 ) ;
if ( V_18 )
F_21 ( V_21 , V_20 ) ;
else
F_22 ( V_20 ) ;
return V_18 ;
}
static int F_23 ( T_1 * V_1 , T_5 * V_21 )
{
T_4 * V_20 = NULL ;
if ( V_1 -> V_21 == NULL )
{
F_12 ( V_49 , V_50 ) ;
return 0 ;
}
V_20 = F_19 () ;
if ( ! V_20 )
return 0 ;
F_21 ( V_21 , V_20 ) ;
if ( ! F_24 ( V_21 , V_1 -> V_21 ) )
return 0 ;
return F_25 ( V_21 -> V_21 . V_20 ) ;
}
