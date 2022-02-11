int F_1 ( T_1 * V_1 , T_2 * type )
{
int V_2 ;
if ( V_1 -> V_3 -> V_4 != NULL )
V_2 = V_1 -> V_3 -> V_4 ( V_1 , type ) ;
else
V_2 = - 1 ;
return ( V_2 ) ;
}
int F_2 ( T_1 * V_1 , T_2 * type )
{
int V_2 ;
if ( V_1 -> V_3 -> V_5 != NULL )
V_2 = V_1 -> V_3 -> V_5 ( V_1 , type ) ;
else
V_2 = - 1 ;
return ( V_2 ) ;
}
int F_3 ( T_1 * V_1 , T_2 * type )
{
int V_6 = 0 ;
unsigned int V_7 ;
if ( type != NULL )
{
V_7 = F_4 ( V_1 ) ;
F_5 ( V_7 <= sizeof( V_1 -> V_8 ) ) ;
V_6 = F_6 ( type , V_1 -> V_9 , V_7 ) ;
if ( V_6 != ( int ) V_7 )
return ( - 1 ) ;
else if ( V_6 > 0 )
memcpy ( V_1 -> V_8 , V_1 -> V_9 , V_7 ) ;
}
return ( V_6 ) ;
}
int F_7 ( T_1 * V_1 , T_2 * type )
{
int V_6 = 0 ;
unsigned int V_10 ;
if ( type != NULL )
{
V_10 = F_4 ( V_1 ) ;
F_5 ( V_10 <= sizeof( V_1 -> V_8 ) ) ;
V_6 = F_8 ( type , V_1 -> V_9 , V_10 ) ;
}
return ( V_6 ) ;
}
int F_9 ( const T_3 * V_11 )
{
int V_12 ;
T_4 * V_13 ;
V_12 = F_10 ( V_11 ) ;
switch( V_12 ) {
case V_14 :
case V_15 :
case V_16 :
return V_14 ;
case V_17 :
case V_18 :
return V_17 ;
case V_19 :
case V_20 :
case V_21 :
return V_19 ;
case V_22 :
case V_23 :
case V_24 :
return V_22 ;
case V_25 :
case V_26 :
case V_27 :
return V_25 ;
case V_28 :
case V_29 :
case V_30 :
return V_28 ;
case V_31 :
case V_32 :
case V_33 :
return V_28 ;
default:
V_13 = F_11 ( V_12 ) ;
if( ! V_13 || ! V_13 -> V_34 ) V_12 = V_35 ;
F_12 ( V_13 ) ;
return V_12 ;
}
}
int F_13 ( const T_3 * V_36 )
{
return V_36 -> V_37 ;
}
int F_14 ( const T_1 * V_11 )
{
return V_11 -> V_3 -> V_37 ;
}
int F_15 ( T_1 * V_11 , unsigned char * V_38 , const unsigned char * V_39 , unsigned int V_40 )
{
return V_11 -> V_3 -> V_41 ( V_11 , V_38 , V_39 , V_40 ) ;
}
const T_3 * F_16 ( const T_1 * V_11 )
{
return V_11 -> V_3 ;
}
unsigned long F_17 ( const T_3 * V_3 )
{
return V_3 -> V_42 ;
}
unsigned long F_18 ( const T_1 * V_11 )
{
return V_11 -> V_3 -> V_42 ;
}
void * F_19 ( const T_1 * V_11 )
{
return V_11 -> V_43 ;
}
void F_20 ( T_1 * V_11 , void * V_34 )
{
V_11 -> V_43 = V_34 ;
}
int F_21 ( const T_3 * V_3 )
{
return V_3 -> V_44 ;
}
int F_4 ( const T_1 * V_11 )
{
return V_11 -> V_3 -> V_44 ;
}
int F_22 ( const T_3 * V_3 )
{
return V_3 -> V_45 ;
}
int F_23 ( const T_1 * V_11 )
{
return V_11 -> V_45 ;
}
int F_10 ( const T_3 * V_3 )
{
return V_3 -> V_12 ;
}
int F_24 ( const T_1 * V_11 )
{
return V_11 -> V_3 -> V_12 ;
}
int F_25 ( const T_5 * V_46 )
{
return V_46 -> V_37 ;
}
int F_26 ( const T_5 * V_46 )
{
return V_46 -> type ;
}
int F_27 ( const T_5 * V_46 )
{
return V_46 -> V_47 ;
}
int F_28 ( const T_5 * V_46 )
{
if ( ! V_46 )
{
F_29 ( V_48 , V_49 ) ;
return - 1 ;
}
return V_46 -> V_50 ;
}
unsigned long F_30 ( const T_5 * V_46 )
{
return V_46 -> V_42 ;
}
const T_5 * F_31 ( const T_6 * V_11 )
{
if ( ! V_11 )
return NULL ;
return V_11 -> V_51 ;
}
void F_32 ( T_6 * V_11 , int V_42 )
{
V_11 -> V_42 |= V_42 ;
}
void F_33 ( T_6 * V_11 , int V_42 )
{
V_11 -> V_42 &= ~ V_42 ;
}
int F_34 ( const T_6 * V_11 , int V_42 )
{
return ( V_11 -> V_42 & V_42 ) ;
}
void F_35 ( T_1 * V_11 , int V_42 )
{
V_11 -> V_42 |= V_42 ;
}
void F_36 ( T_1 * V_11 , int V_42 )
{
V_11 -> V_42 &= ~ V_42 ;
}
int F_37 ( const T_1 * V_11 , int V_42 )
{
return ( V_11 -> V_42 & V_42 ) ;
}
