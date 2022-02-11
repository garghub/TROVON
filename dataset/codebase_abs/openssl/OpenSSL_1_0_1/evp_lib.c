int F_1 ( T_1 * V_1 , T_2 * type )
{
int V_2 ;
if ( V_1 -> V_3 -> V_4 != NULL )
V_2 = V_1 -> V_3 -> V_4 ( V_1 , type ) ;
else if ( V_1 -> V_3 -> V_5 & V_6 )
V_2 = F_2 ( V_1 , type ) ;
else
V_2 = - 1 ;
return ( V_2 ) ;
}
int F_3 ( T_1 * V_1 , T_2 * type )
{
int V_2 ;
if ( V_1 -> V_3 -> V_7 != NULL )
V_2 = V_1 -> V_3 -> V_7 ( V_1 , type ) ;
else if ( V_1 -> V_3 -> V_5 & V_6 )
V_2 = F_4 ( V_1 , type ) ;
else
V_2 = - 1 ;
return ( V_2 ) ;
}
int F_4 ( T_1 * V_1 , T_2 * type )
{
int V_8 = 0 ;
unsigned int V_9 ;
if ( type != NULL )
{
V_9 = F_5 ( V_1 ) ;
F_6 ( V_9 <= sizeof( V_1 -> V_10 ) ) ;
V_8 = F_7 ( type , V_1 -> V_11 , V_9 ) ;
if ( V_8 != ( int ) V_9 )
return ( - 1 ) ;
else if ( V_8 > 0 )
memcpy ( V_1 -> V_10 , V_1 -> V_11 , V_9 ) ;
}
return ( V_8 ) ;
}
int F_2 ( T_1 * V_1 , T_2 * type )
{
int V_8 = 0 ;
unsigned int V_12 ;
if ( type != NULL )
{
V_12 = F_5 ( V_1 ) ;
F_6 ( V_12 <= sizeof( V_1 -> V_10 ) ) ;
V_8 = F_8 ( type , V_1 -> V_11 , V_12 ) ;
}
return ( V_8 ) ;
}
int F_9 ( const T_3 * V_13 )
{
int V_14 ;
T_4 * V_15 ;
V_14 = F_10 ( V_13 ) ;
switch( V_14 ) {
case V_16 :
case V_17 :
case V_18 :
return V_16 ;
case V_19 :
case V_20 :
return V_19 ;
case V_21 :
case V_22 :
case V_23 :
return V_21 ;
case V_24 :
case V_25 :
case V_26 :
return V_24 ;
case V_27 :
case V_28 :
case V_29 :
return V_27 ;
case V_30 :
case V_31 :
case V_32 :
return V_30 ;
case V_33 :
case V_34 :
case V_35 :
return V_30 ;
default:
V_15 = F_11 ( V_14 ) ;
if( ! V_15 || ! V_15 -> V_36 ) V_14 = V_37 ;
F_12 ( V_15 ) ;
return V_14 ;
}
}
int F_13 ( const T_3 * V_38 )
{
return V_38 -> V_39 ;
}
int F_14 ( const T_1 * V_13 )
{
return V_13 -> V_3 -> V_39 ;
}
int F_15 ( T_1 * V_13 , unsigned char * V_40 , const unsigned char * V_41 , unsigned int V_42 )
{
return V_13 -> V_3 -> V_43 ( V_13 , V_40 , V_41 , V_42 ) ;
}
const T_3 * F_16 ( const T_1 * V_13 )
{
return V_13 -> V_3 ;
}
unsigned long F_17 ( const T_3 * V_3 )
{
return V_3 -> V_5 ;
}
unsigned long F_18 ( const T_1 * V_13 )
{
return V_13 -> V_3 -> V_5 ;
}
void * F_19 ( const T_1 * V_13 )
{
return V_13 -> V_44 ;
}
void F_20 ( T_1 * V_13 , void * V_36 )
{
V_13 -> V_44 = V_36 ;
}
int F_21 ( const T_3 * V_3 )
{
return V_3 -> V_45 ;
}
int F_5 ( const T_1 * V_13 )
{
return V_13 -> V_3 -> V_45 ;
}
int F_22 ( const T_3 * V_3 )
{
return V_3 -> V_46 ;
}
int F_23 ( const T_1 * V_13 )
{
return V_13 -> V_46 ;
}
int F_10 ( const T_3 * V_3 )
{
return V_3 -> V_14 ;
}
int F_24 ( const T_1 * V_13 )
{
return V_13 -> V_3 -> V_14 ;
}
int F_25 ( const T_5 * V_47 )
{
return V_47 -> V_39 ;
}
int F_26 ( const T_5 * V_47 )
{
return V_47 -> type ;
}
int F_27 ( const T_5 * V_47 )
{
return V_47 -> V_48 ;
}
int F_28 ( const T_5 * V_47 )
{
if ( ! V_47 )
{
F_29 ( V_49 , V_50 ) ;
return - 1 ;
}
return V_47 -> V_51 ;
}
unsigned long F_30 ( const T_5 * V_47 )
{
return V_47 -> V_5 ;
}
const T_5 * F_31 ( const T_6 * V_13 )
{
if ( ! V_13 )
return NULL ;
return V_13 -> V_52 ;
}
void F_32 ( T_6 * V_13 , int V_5 )
{
V_13 -> V_5 |= V_5 ;
}
void F_33 ( T_6 * V_13 , int V_5 )
{
V_13 -> V_5 &= ~ V_5 ;
}
int F_34 ( const T_6 * V_13 , int V_5 )
{
return ( V_13 -> V_5 & V_5 ) ;
}
void F_35 ( T_1 * V_13 , int V_5 )
{
V_13 -> V_5 |= V_5 ;
}
void F_36 ( T_1 * V_13 , int V_5 )
{
V_13 -> V_5 &= ~ V_5 ;
}
int F_37 ( const T_1 * V_13 , int V_5 )
{
return ( V_13 -> V_5 & V_5 ) ;
}
