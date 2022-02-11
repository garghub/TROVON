static void *
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 * V_5 ;
void * V_6 ;
int V_7 = V_8 + V_2 -> V_9 -> V_10 ;
V_4 -> V_11 = F_2 ( & V_2 -> V_12 , V_7 ) ;
V_5 = ( T_1 * ) V_4 -> V_13 ;
F_3 ( & V_2 -> V_12 , V_7 , ( unsigned char * * ) & V_5 ) ;
V_6 = V_5 ;
* V_5 ++ = V_14 ;
* V_5 ++ = ( V_15 T_1 ) F_4 ( V_2 -> V_9 -> V_16 ) ;
* V_5 ++ = V_17 ;
* V_5 = 0xffff ;
return V_6 ;
}
static void *
F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 * V_5 ;
void * V_6 ;
T_2 * V_18 , V_19 = 0x00 ;
if ( ( V_2 -> V_19 & V_20 ) == 0 )
V_19 |= 0x01 ;
if ( V_2 -> V_19 & V_21 )
V_19 |= 0x04 ;
V_6 = V_5 = ( T_1 * ) V_4 -> V_13 ;
* V_5 ++ = V_22 ;
V_18 = ( T_2 * ) V_5 ;
* V_18 ++ = V_19 ;
* V_18 ++ = 0xff ;
V_5 = ( T_1 * ) V_18 ;
* V_5 ++ = 0xffff ;
* V_5 = 0xffff ;
V_4 -> V_11 = V_8 + V_2 -> V_9 -> V_10 ;
return V_6 ;
}
static T_3
F_6 ( struct V_1 * V_2 , struct V_23 * V_24 ,
struct V_3 * V_4 )
{
char V_25 [ V_26 ] ;
struct V_3 V_27 = { . V_11 = sizeof( V_25 ) ,
. V_13 = V_25 } ;
void * V_5 ;
T_4 V_28 ;
T_3 V_29 ;
T_2 * V_30 ;
F_7 ( L_1 , V_31 ) ;
F_8 ( V_2 == NULL ) ;
V_28 = F_9 () ;
V_5 = F_1 ( V_2 , V_4 ) ;
if ( V_2 -> V_9 -> V_32 )
V_30 = V_2 -> V_33 ;
else
V_30 = NULL ;
if ( F_10 ( V_2 , V_5 , 8 , V_24 , 0 , V_30 ,
V_34 , & V_27 ) )
return V_35 ;
memcpy ( V_5 + V_8 , V_27 . V_13 , V_27 . V_11 ) ;
F_11 ( & V_36 ) ;
V_29 = V_2 -> V_29 ++ ;
F_12 ( & V_36 ) ;
if ( F_13 ( V_2 , V_2 -> V_37 , V_2 -> V_38 ? 0 : 0xff ,
V_29 , V_5 + V_8 , V_5 + 8 ) )
return V_35 ;
return ( V_2 -> V_39 < V_28 ) ? V_40 : V_41 ;
}
static T_3
F_14 ( struct V_1 * V_2 , struct V_23 * V_24 ,
struct V_3 * V_4 )
{
char V_25 [ V_26 ] ;
struct V_3 V_42 = { . V_11 = sizeof( V_25 ) ,
. V_13 = V_25 } ;
void * V_6 ;
T_4 V_28 ;
T_5 V_29 ;
T_2 * V_30 ;
unsigned int V_43 ;
F_7 ( L_1 , V_31 ) ;
V_6 = F_5 ( V_2 , V_4 ) ;
F_11 ( & V_36 ) ;
V_29 = V_2 -> V_44 ++ ;
F_12 ( & V_36 ) ;
* ( ( V_45 * ) ( V_6 + 8 ) ) = F_15 ( V_29 ) ;
if ( V_2 -> V_38 ) {
V_30 = V_2 -> V_46 ;
V_43 = V_47 ;
} else {
V_30 = V_2 -> V_48 ;
V_43 = V_49 ;
}
if ( F_16 ( V_2 , V_6 , V_8 ,
V_24 , 0 , V_30 , V_43 , & V_42 ) )
return V_35 ;
memcpy ( V_6 + V_8 , V_42 . V_13 , V_42 . V_11 ) ;
V_28 = F_9 () ;
return ( V_2 -> V_39 < V_28 ) ? V_40 : V_41 ;
}
T_3
F_17 ( struct V_50 * V_50 , struct V_23 * V_24 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_50 -> V_51 ;
switch ( V_2 -> V_52 ) {
default:
F_18 () ;
case V_53 :
case V_54 :
case V_55 :
return F_6 ( V_2 , V_24 , V_4 ) ;
case V_56 :
case V_57 :
return F_14 ( V_2 , V_24 , V_4 ) ;
}
}
