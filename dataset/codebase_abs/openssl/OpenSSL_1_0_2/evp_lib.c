int F_1 ( T_1 * V_1 , T_2 * type )
{
int V_2 ;
if ( V_1 -> V_3 -> V_4 != NULL )
V_2 = V_1 -> V_3 -> V_4 ( V_1 , type ) ;
else if ( V_1 -> V_3 -> V_5 & V_6 ) {
if ( F_2 ( V_1 ) == V_7 ) {
F_3 ( type , V_8 , NULL ) ;
V_2 = 1 ;
} else
V_2 = F_4 ( V_1 , type ) ;
} else
V_2 = - 1 ;
return ( V_2 ) ;
}
int F_5 ( T_1 * V_1 , T_2 * type )
{
int V_2 ;
if ( V_1 -> V_3 -> V_9 != NULL )
V_2 = V_1 -> V_3 -> V_9 ( V_1 , type ) ;
else if ( V_1 -> V_3 -> V_5 & V_6 ) {
if ( F_2 ( V_1 ) == V_7 )
return 1 ;
V_2 = F_6 ( V_1 , type ) ;
} else
V_2 = - 1 ;
return ( V_2 ) ;
}
int F_6 ( T_1 * V_1 , T_2 * type )
{
int V_10 = 0 ;
unsigned int V_11 ;
if ( type != NULL ) {
V_11 = F_7 ( V_1 ) ;
F_8 ( V_11 <= sizeof( V_1 -> V_12 ) ) ;
V_10 = F_9 ( type , V_1 -> V_13 , V_11 ) ;
if ( V_10 != ( int ) V_11 )
return ( - 1 ) ;
else if ( V_10 > 0 )
memcpy ( V_1 -> V_12 , V_1 -> V_13 , V_11 ) ;
}
return ( V_10 ) ;
}
int F_4 ( T_1 * V_1 , T_2 * type )
{
int V_10 = 0 ;
unsigned int V_14 ;
if ( type != NULL ) {
V_14 = F_7 ( V_1 ) ;
F_8 ( V_14 <= sizeof( V_1 -> V_12 ) ) ;
V_10 = F_10 ( type , V_1 -> V_13 , V_14 ) ;
}
return ( V_10 ) ;
}
int F_11 ( const T_3 * V_15 )
{
int V_16 ;
T_4 * V_17 ;
V_16 = F_12 ( V_15 ) ;
switch ( V_16 ) {
case V_18 :
case V_19 :
case V_20 :
return V_18 ;
case V_21 :
case V_22 :
return V_21 ;
case V_23 :
case V_24 :
case V_25 :
return V_23 ;
case V_26 :
case V_27 :
case V_28 :
return V_26 ;
case V_29 :
case V_30 :
case V_31 :
return V_29 ;
case V_32 :
case V_33 :
case V_34 :
return V_32 ;
case V_35 :
case V_36 :
case V_37 :
return V_32 ;
default:
V_17 = F_13 ( V_16 ) ;
if ( ! V_17 || ! V_17 -> V_38 )
V_16 = V_39 ;
F_14 ( V_17 ) ;
return V_16 ;
}
}
int F_15 ( const T_3 * V_40 )
{
return V_40 -> V_41 ;
}
int F_16 ( const T_1 * V_15 )
{
return V_15 -> V_3 -> V_41 ;
}
int F_17 ( T_1 * V_15 , unsigned char * V_42 ,
const unsigned char * V_43 , unsigned int V_44 )
{
return V_15 -> V_3 -> V_45 ( V_15 , V_42 , V_43 , V_44 ) ;
}
const T_3 * F_18 ( const T_1 * V_15 )
{
return V_15 -> V_3 ;
}
unsigned long F_19 ( const T_3 * V_3 )
{
#ifdef F_20
const T_3 * V_46 ;
V_46 = F_21 ( V_3 ) ;
if ( V_46 && V_46 -> V_5 & V_47 )
return V_3 -> V_5 | V_47 ;
#endif
return V_3 -> V_5 ;
}
unsigned long F_22 ( const T_1 * V_15 )
{
#ifdef F_20
return F_19 ( V_15 -> V_3 ) ;
#else
return V_15 -> V_3 -> V_5 ;
#endif
}
void * F_23 ( const T_1 * V_15 )
{
return V_15 -> V_48 ;
}
void F_24 ( T_1 * V_15 , void * V_38 )
{
V_15 -> V_48 = V_38 ;
}
int F_25 ( const T_3 * V_3 )
{
return V_3 -> V_49 ;
}
int F_7 ( const T_1 * V_15 )
{
return V_15 -> V_3 -> V_49 ;
}
int F_26 ( const T_3 * V_3 )
{
return V_3 -> V_50 ;
}
int F_27 ( const T_1 * V_15 )
{
return V_15 -> V_50 ;
}
int F_12 ( const T_3 * V_3 )
{
return V_3 -> V_16 ;
}
int F_28 ( const T_1 * V_15 )
{
return V_15 -> V_3 -> V_16 ;
}
int F_29 ( const T_5 * V_51 )
{
return V_51 -> V_41 ;
}
int F_30 ( const T_5 * V_51 )
{
return V_51 -> type ;
}
int F_31 ( const T_5 * V_51 )
{
return V_51 -> V_52 ;
}
int F_32 ( const T_5 * V_51 )
{
if ( ! V_51 ) {
F_33 ( V_53 , V_54 ) ;
return - 1 ;
}
return V_51 -> V_55 ;
}
const T_5 * F_34 ( const T_5 * V_51 )
{
int V_16 = F_30 ( V_51 ) ;
if ( V_16 == V_56 )
return F_35 () ;
else if ( V_16 == V_57 )
return F_36 () ;
else if ( V_16 == V_58 )
return F_37 () ;
else
return F_38 ( V_16 ) ;
}
const T_3 * F_21 ( const T_3 * V_3 )
{
int V_16 = V_3 -> V_16 ;
if ( V_16 == V_39 )
return F_39 () ;
else
return F_40 ( V_16 ) ;
}
unsigned long F_41 ( const T_5 * V_51 )
{
#ifdef F_20
const T_5 * V_59 ;
V_59 = F_34 ( V_51 ) ;
if ( V_59 && V_59 -> V_5 & V_60 )
return V_51 -> V_5 | V_60 ;
#endif
return V_51 -> V_5 ;
}
const T_5 * F_42 ( const T_6 * V_15 )
{
if ( ! V_15 )
return NULL ;
return V_15 -> V_61 ;
}
void F_43 ( T_6 * V_15 , int V_5 )
{
V_15 -> V_5 |= V_5 ;
}
void F_44 ( T_6 * V_15 , int V_5 )
{
V_15 -> V_5 &= ~ V_5 ;
}
int F_45 ( const T_6 * V_15 , int V_5 )
{
return ( V_15 -> V_5 & V_5 ) ;
}
void F_46 ( T_1 * V_15 , int V_5 )
{
V_15 -> V_5 |= V_5 ;
}
void F_47 ( T_1 * V_15 , int V_5 )
{
V_15 -> V_5 &= ~ V_5 ;
}
int F_48 ( const T_1 * V_15 , int V_5 )
{
return ( V_15 -> V_5 & V_5 ) ;
}
