int F_1 ( T_1 * V_1 , T_2 * type )
{
int V_2 ;
if ( V_1 -> V_3 -> V_4 != NULL )
V_2 = V_1 -> V_3 -> V_4 ( V_1 , type ) ;
else if ( V_1 -> V_3 -> V_5 & V_6 ) {
switch ( F_2 ( V_1 ) ) {
case V_7 :
if ( F_3 ( V_1 ) == V_8 )
F_4 ( type , V_9 , NULL ) ;
V_2 = 1 ;
break;
case V_10 :
case V_11 :
case V_12 :
case V_13 :
V_2 = - 1 ;
break;
default:
V_2 = F_5 ( V_1 , type ) ;
}
} else
V_2 = - 1 ;
return ( V_2 ) ;
}
int F_6 ( T_1 * V_1 , T_2 * type )
{
int V_2 ;
if ( V_1 -> V_3 -> V_14 != NULL )
V_2 = V_1 -> V_3 -> V_14 ( V_1 , type ) ;
else if ( V_1 -> V_3 -> V_5 & V_6 ) {
switch ( F_2 ( V_1 ) ) {
case V_7 :
V_2 = 1 ;
break;
case V_10 :
case V_11 :
case V_12 :
case V_13 :
V_2 = - 1 ;
break;
default:
V_2 = F_7 ( V_1 , type ) ;
break;
}
} else
V_2 = - 1 ;
return ( V_2 ) ;
}
int F_7 ( T_1 * V_1 , T_2 * type )
{
int V_15 = 0 ;
unsigned int V_16 ;
if ( type != NULL ) {
V_16 = F_8 ( V_1 ) ;
F_9 ( V_16 <= sizeof( V_1 -> V_17 ) ) ;
V_15 = F_10 ( type , V_1 -> V_18 , V_16 ) ;
if ( V_15 != ( int ) V_16 )
return ( - 1 ) ;
else if ( V_15 > 0 )
memcpy ( V_1 -> V_17 , V_1 -> V_18 , V_16 ) ;
}
return ( V_15 ) ;
}
int F_5 ( T_1 * V_1 , T_2 * type )
{
int V_15 = 0 ;
unsigned int V_19 ;
if ( type != NULL ) {
V_19 = F_8 ( V_1 ) ;
F_9 ( V_19 <= sizeof( V_1 -> V_17 ) ) ;
V_15 = F_11 ( type , V_1 -> V_18 , V_19 ) ;
}
return ( V_15 ) ;
}
int F_12 ( const T_3 * V_20 )
{
int V_21 ;
T_4 * V_22 ;
V_21 = F_13 ( V_20 ) ;
switch ( V_21 ) {
case V_23 :
case V_24 :
case V_25 :
return V_23 ;
case V_26 :
case V_27 :
return V_26 ;
case V_28 :
case V_29 :
case V_30 :
return V_28 ;
case V_31 :
case V_32 :
case V_33 :
return V_31 ;
case V_34 :
case V_35 :
case V_36 :
return V_34 ;
case V_37 :
case V_38 :
case V_39 :
return V_37 ;
case V_40 :
case V_41 :
case V_42 :
return V_37 ;
default:
V_22 = F_14 ( V_21 ) ;
if ( F_15 ( V_22 ) == NULL )
V_21 = V_43 ;
F_16 ( V_22 ) ;
return V_21 ;
}
}
int F_17 ( const T_3 * V_44 )
{
return V_44 -> V_45 ;
}
int F_18 ( const T_1 * V_20 )
{
return V_20 -> V_3 -> V_45 ;
}
int F_19 ( const T_3 * V_44 )
{
return V_44 -> V_46 ;
}
int F_20 ( T_1 * V_20 , unsigned char * V_47 ,
const unsigned char * V_48 , unsigned int V_49 )
{
return V_20 -> V_3 -> V_50 ( V_20 , V_47 , V_48 , V_49 ) ;
}
const T_3 * F_21 ( const T_1 * V_20 )
{
return V_20 -> V_3 ;
}
int F_22 ( const T_1 * V_20 )
{
return V_20 -> V_51 ;
}
unsigned long F_23 ( const T_3 * V_3 )
{
return V_3 -> V_5 ;
}
void * F_24 ( const T_1 * V_20 )
{
return V_20 -> V_52 ;
}
void F_25 ( T_1 * V_20 , void * V_53 )
{
V_20 -> V_52 = V_53 ;
}
void * F_26 ( const T_1 * V_20 )
{
return V_20 -> V_54 ;
}
void * F_27 ( T_1 * V_20 , void * V_54 )
{
void * V_55 ;
V_55 = V_20 -> V_54 ;
V_20 -> V_54 = V_54 ;
return V_55 ;
}
int F_28 ( const T_3 * V_3 )
{
return V_3 -> V_56 ;
}
int F_8 ( const T_1 * V_20 )
{
return V_20 -> V_3 -> V_56 ;
}
const unsigned char * F_29 ( const T_1 * V_20 )
{
return V_20 -> V_18 ;
}
const unsigned char * F_30 ( const T_1 * V_20 )
{
return V_20 -> V_17 ;
}
unsigned char * F_31 ( T_1 * V_20 )
{
return V_20 -> V_17 ;
}
unsigned char * F_32 ( T_1 * V_20 )
{
return V_20 -> V_57 ;
}
int F_33 ( const T_1 * V_20 )
{
return V_20 -> V_58 ;
}
void F_34 ( T_1 * V_20 , int V_58 )
{
V_20 -> V_58 = V_58 ;
}
int F_35 ( const T_3 * V_3 )
{
return V_3 -> V_59 ;
}
int F_36 ( const T_1 * V_20 )
{
return V_20 -> V_59 ;
}
int F_13 ( const T_3 * V_3 )
{
return V_3 -> V_21 ;
}
int F_3 ( const T_1 * V_20 )
{
return V_20 -> V_3 -> V_21 ;
}
int F_37 ( const T_5 * V_60 )
{
return V_60 -> V_45 ;
}
int F_38 ( const T_5 * V_60 )
{
return V_60 -> type ;
}
int F_39 ( const T_5 * V_60 )
{
return V_60 -> V_61 ;
}
int F_40 ( const T_5 * V_60 )
{
if ( ! V_60 ) {
F_41 ( V_62 , V_63 ) ;
return - 1 ;
}
return V_60 -> V_64 ;
}
unsigned long F_42 ( const T_5 * V_60 )
{
return V_60 -> V_5 ;
}
T_5 * F_43 ( int V_65 , int V_61 )
{
T_5 * V_60 = F_44 ( sizeof( * V_60 ) ) ;
if ( V_60 != NULL ) {
V_60 -> type = V_65 ;
V_60 -> V_61 = V_61 ;
}
return V_60 ;
}
T_5 * F_45 ( const T_5 * V_60 )
{
T_5 * V_66 = F_43 ( V_60 -> type , V_60 -> V_61 ) ;
if ( V_66 != NULL )
memcpy ( V_66 , V_60 , sizeof( * V_66 ) ) ;
return V_66 ;
}
void F_46 ( T_5 * V_60 )
{
F_47 ( V_60 ) ;
}
int F_48 ( T_5 * V_60 , int V_67 )
{
V_60 -> V_45 = V_67 ;
return 1 ;
}
int F_49 ( T_5 * V_60 , int V_68 )
{
V_60 -> V_64 = V_68 ;
return 1 ;
}
int F_50 ( T_5 * V_60 , int V_69 )
{
V_60 -> V_46 = V_69 ;
return 1 ;
}
int F_51 ( T_5 * V_60 , unsigned long V_5 )
{
V_60 -> V_5 = V_5 ;
return 1 ;
}
int F_52 ( T_5 * V_60 , int (* F_53)( T_6 * V_20 ) )
{
V_60 -> F_53 = F_53 ;
return 1 ;
}
int F_54 ( T_5 * V_60 , int (* F_55)( T_6 * V_20 ,
const void * V_53 ,
T_7 V_70 ) )
{
V_60 -> F_55 = F_55 ;
return 1 ;
}
int F_56 ( T_5 * V_60 , int (* F_57)( T_6 * V_20 ,
unsigned char * V_60 ) )
{
V_60 -> F_57 = F_57 ;
return 1 ;
}
int F_58 ( T_5 * V_60 , int (* F_59)( T_6 * V_66 ,
const T_6 * V_71 ) )
{
V_60 -> F_59 = F_59 ;
return 1 ;
}
int F_60 ( T_5 * V_60 , int (* F_61)( T_6 * V_20 ) )
{
V_60 -> F_61 = F_61 ;
return 1 ;
}
int F_62 ( T_5 * V_60 , int (* F_63)( T_6 * V_20 , int V_72 ,
int V_73 , void * V_74 ) )
{
V_60 -> V_75 = F_63 ;
return 1 ;
}
int F_64 ( const T_5 * V_60 )
{
return V_60 -> V_45 ;
}
int F_65 ( const T_5 * V_60 )
{
return V_60 -> V_64 ;
}
int F_66 ( const T_5 * V_60 )
{
return V_60 -> V_46 ;
}
unsigned long F_67 ( const T_5 * V_60 )
{
return V_60 -> V_45 ;
}
const T_5 * F_68 ( const T_6 * V_20 )
{
if ( ! V_20 )
return NULL ;
return V_20 -> V_76 ;
}
T_8 * F_69 ( const T_6 * V_20 )
{
return V_20 -> V_77 ;
}
void * F_70 ( const T_6 * V_20 )
{
return V_20 -> V_78 ;
}
void F_71 ( T_6 * V_20 ,
int (* F_55) ( T_6 * V_20 ,
const void * V_53 , T_7 V_70 ) )
{
V_20 -> F_55 = F_55 ;
}
void F_72 ( T_6 * V_20 , int V_5 )
{
V_20 -> V_5 |= V_5 ;
}
void F_73 ( T_6 * V_20 , int V_5 )
{
V_20 -> V_5 &= ~ V_5 ;
}
int F_74 ( const T_6 * V_20 , int V_5 )
{
return ( V_20 -> V_5 & V_5 ) ;
}
void F_75 ( T_1 * V_20 , int V_5 )
{
V_20 -> V_5 |= V_5 ;
}
void F_76 ( T_1 * V_20 , int V_5 )
{
V_20 -> V_5 &= ~ V_5 ;
}
int F_77 ( const T_1 * V_20 , int V_5 )
{
return ( V_20 -> V_5 & V_5 ) ;
}
