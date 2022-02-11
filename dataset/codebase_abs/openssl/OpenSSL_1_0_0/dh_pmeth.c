static int F_1 ( T_1 * V_1 )
{
T_2 * V_2 ;
V_2 = F_2 ( sizeof( T_2 ) ) ;
if ( ! V_2 )
return 0 ;
V_2 -> V_3 = 1024 ;
V_2 -> V_4 = 2 ;
V_2 -> V_5 = 0 ;
V_1 -> V_6 = V_2 ;
V_1 -> V_7 = V_2 -> V_8 ;
V_1 -> V_9 = 2 ;
return 1 ;
}
static int F_3 ( T_1 * V_10 , T_1 * V_11 )
{
T_2 * V_2 , * V_12 ;
if ( ! F_1 ( V_10 ) )
return 0 ;
V_12 = V_11 -> V_6 ;
V_2 = V_10 -> V_6 ;
V_2 -> V_3 = V_12 -> V_3 ;
V_2 -> V_4 = V_12 -> V_4 ;
V_2 -> V_5 = V_12 -> V_5 ;
return 1 ;
}
static void F_4 ( T_1 * V_1 )
{
T_2 * V_2 = V_1 -> V_6 ;
if ( V_2 )
F_5 ( V_2 ) ;
}
static int F_6 ( T_1 * V_1 , int type , int V_13 , void * V_14 )
{
T_2 * V_2 = V_1 -> V_6 ;
switch ( type )
{
case V_15 :
if ( V_13 < 256 )
return - 2 ;
V_2 -> V_3 = V_13 ;
return 1 ;
case V_16 :
V_2 -> V_4 = V_13 ;
return 1 ;
case V_17 :
return 1 ;
default:
return - 2 ;
}
}
static int F_7 ( T_1 * V_1 ,
const char * type , const char * V_18 )
{
if ( ! strcmp ( type , L_1 ) )
{
int V_19 ;
V_19 = atoi ( V_18 ) ;
return F_8 ( V_1 , V_19 ) ;
}
if ( ! strcmp ( type , L_2 ) )
{
int V_19 ;
V_19 = atoi ( V_18 ) ;
return F_9 ( V_1 , V_19 ) ;
}
return - 2 ;
}
static int F_10 ( T_1 * V_1 , T_3 * V_20 )
{
T_4 * V_21 = NULL ;
T_2 * V_2 = V_1 -> V_6 ;
T_5 * V_22 , V_23 ;
int V_24 ;
if ( V_1 -> V_25 )
{
V_22 = & V_23 ;
F_11 ( V_22 , V_1 ) ;
}
else
V_22 = NULL ;
V_21 = F_12 () ;
if ( ! V_21 )
return 0 ;
V_24 = F_13 ( V_21 ,
V_2 -> V_3 , V_2 -> V_4 , V_22 ) ;
if ( V_24 )
F_14 ( V_20 , V_21 ) ;
else
F_15 ( V_21 ) ;
return V_24 ;
}
static int F_16 ( T_1 * V_1 , T_3 * V_20 )
{
T_4 * V_21 = NULL ;
if ( V_1 -> V_20 == NULL )
{
F_17 ( V_26 , V_27 ) ;
return 0 ;
}
V_21 = F_12 () ;
if ( ! V_21 )
return 0 ;
F_14 ( V_20 , V_21 ) ;
if ( ! F_18 ( V_20 , V_1 -> V_20 ) )
return 0 ;
return F_19 ( V_20 -> V_20 . V_21 ) ;
}
static int F_20 ( T_1 * V_1 , unsigned char * V_28 , T_6 * V_29 )
{
int V_24 ;
if ( ! V_1 -> V_20 || ! V_1 -> V_30 )
{
F_17 ( V_31 , V_32 ) ;
return 0 ;
}
V_24 = F_21 ( V_28 , V_1 -> V_30 -> V_20 . V_21 -> V_33 ,
V_1 -> V_20 -> V_20 . V_21 ) ;
if ( V_24 < 0 )
return V_24 ;
* V_29 = V_24 ;
return 1 ;
}
