T_1 * F_1 ( T_2 * V_1 )
{
T_1 * V_2 = NULL ;
T_3 * V_3 ;
char V_4 [ 80 ] ;
if ( ! F_2 ( & V_3 , NULL , NULL , NULL , V_1 ) )
return NULL ;
if ( ! ( V_2 = F_3 () ) ) {
F_4 ( V_5 , V_6 ) ;
return NULL ;
}
if ( ! F_5 ( V_2 , F_6 ( V_3 ) ) )
{
F_4 ( V_5 , V_7 ) ;
F_7 ( V_4 , 80 , V_3 ) ;
F_8 ( 2 , L_1 , V_4 ) ;
goto error;
}
if ( V_2 -> V_8 -> V_9 )
{
if ( ! V_2 -> V_8 -> V_9 ( V_2 , V_1 ) )
{
F_4 ( V_5 ,
V_10 ) ;
goto error;
}
}
else
{
F_4 ( V_5 , V_11 ) ;
goto error;
}
return V_2 ;
error:
F_9 ( V_2 ) ;
return NULL ;
}
T_2 * F_10 ( T_1 * V_2 )
{
return F_11 ( V_2 , V_12 ) ;
}
T_2 * F_11 ( T_1 * V_2 , int V_13 )
{
T_2 * V_1 ;
if ( ! ( V_1 = F_12 () ) ) {
F_4 ( V_14 , V_6 ) ;
return NULL ;
}
V_1 -> V_13 = V_13 ;
if ( V_2 -> V_8 )
{
if ( V_2 -> V_8 -> V_15 )
{
if ( ! V_2 -> V_8 -> V_15 ( V_1 , V_2 ) )
{
F_4 ( V_14 ,
V_16 ) ;
goto error;
}
}
else
{
F_4 ( V_14 ,
V_11 ) ;
goto error;
}
}
else
{
F_4 ( V_14 ,
V_7 ) ;
goto error;
}
F_13 ( V_1 -> V_2 -> V_17 . V_18 -> V_19 ,
V_1 -> V_2 -> V_17 . V_18 -> V_20 , 0.0 ) ;
return V_1 ;
error:
F_14 ( V_1 ) ;
return NULL ;
}
T_2 * F_15 ( T_2 * V_1 , int V_13 )
{
switch ( V_13 ) {
case V_12 :
V_1 -> V_13 = V_12 ;
return V_1 ;
break;
case V_21 :
V_1 -> V_13 = V_21 ;
V_1 -> V_2 -> type = V_22 ;
return V_1 ;
break;
default:
F_4 ( V_23 , V_24 ) ;
return NULL ;
}
}
int F_16 ( const T_1 * V_25 )
{
return F_17 ( V_25 -> V_26 ) ;
}
int F_18 ( const T_1 * V_25 , int V_27 ,
int V_28 )
{
return F_19 ( V_25 -> V_26 , V_27 , V_28 ) ;
}
int F_20 ( const T_1 * V_25 , T_3 * V_29 ,
int V_28 )
{
return F_21 ( V_25 -> V_26 , V_29 , V_28 ) ;
}
T_4 * F_22 ( const T_1 * V_25 , int V_30 )
{
return F_23 ( V_25 -> V_26 , V_30 ) ;
}
T_4 * F_24 ( T_1 * V_25 , int V_30 )
{
return F_25 ( V_25 -> V_26 , V_30 ) ;
}
int F_26 ( T_1 * V_25 , T_4 * V_31 )
{
if( F_27 ( & V_25 -> V_26 , V_31 ) ) return 1 ;
return 0 ;
}
int F_28 ( T_1 * V_25 ,
const T_3 * V_29 , int type ,
const unsigned char * V_32 , int V_33 )
{
if( F_29 ( & V_25 -> V_26 , V_29 ,
type , V_32 , V_33 ) ) return 1 ;
return 0 ;
}
int F_30 ( T_1 * V_25 ,
int V_27 , int type ,
const unsigned char * V_32 , int V_33 )
{
if( F_31 ( & V_25 -> V_26 , V_27 ,
type , V_32 , V_33 ) ) return 1 ;
return 0 ;
}
int F_32 ( T_1 * V_25 ,
const char * V_34 , int type ,
const unsigned char * V_32 , int V_33 )
{
if( F_33 ( & V_25 -> V_26 , V_34 ,
type , V_32 , V_33 ) ) return 1 ;
return 0 ;
}
