static char *
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 * V_5 , * V_6 ;
int V_7 = V_8 + V_2 -> V_9 -> V_10 ;
V_4 -> V_11 = F_2 ( & V_2 -> V_12 , V_7 ) ;
V_5 = ( T_1 * ) V_4 -> V_13 ;
F_3 ( & V_2 -> V_12 , V_7 , ( unsigned char * * ) & V_5 ) ;
V_6 = V_5 ;
* V_5 ++ = V_14 ;
* V_5 ++ = F_4 ( V_2 -> V_9 -> V_15 ) ;
* V_5 ++ = V_16 ;
* V_5 ++ = 0xffff ;
return ( char * ) V_6 ;
}
static void *
F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 * V_5 , * V_6 ;
T_2 * V_17 , V_18 = 0x00 ;
if ( ( V_2 -> V_18 & V_19 ) == 0 )
V_18 |= 0x01 ;
if ( V_2 -> V_18 & V_20 )
V_18 |= 0x04 ;
V_6 = V_5 = ( T_1 * ) V_4 -> V_13 ;
* V_5 ++ = V_21 ;
V_17 = ( T_2 * ) V_5 ;
* V_17 ++ = V_18 ;
* V_17 ++ = 0xff ;
V_5 = ( T_1 * ) V_17 ;
* V_5 ++ = 0xffff ;
* V_5 ++ = 0xffff ;
V_4 -> V_11 = V_8 + V_2 -> V_9 -> V_10 ;
return V_6 ;
}
static T_3
F_6 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_3 * V_4 )
{
char V_24 [ V_25 ] ;
struct V_3 V_26 = { . V_11 = sizeof( V_24 ) ,
. V_13 = V_24 } ;
void * V_5 ;
T_4 V_27 ;
T_3 V_28 ;
T_2 * V_29 ;
F_7 ( L_1 , V_30 ) ;
F_8 ( V_2 == NULL ) ;
V_27 = F_9 () ;
V_5 = F_1 ( V_2 , V_4 ) ;
if ( V_2 -> V_9 -> V_31 )
V_29 = V_2 -> V_32 ;
else
V_29 = NULL ;
if ( F_10 ( V_2 , V_5 , 8 , V_23 , 0 , V_29 ,
V_33 , & V_26 ) )
return V_34 ;
memcpy ( V_5 + V_8 , V_26 . V_13 , V_26 . V_11 ) ;
F_11 ( & V_35 ) ;
V_28 = V_2 -> V_28 ++ ;
F_12 ( & V_35 ) ;
if ( F_13 ( V_2 , V_2 -> V_36 , V_2 -> V_37 ? 0 : 0xff ,
V_28 , V_5 + V_8 , V_5 + 8 ) )
return V_34 ;
return ( V_2 -> V_38 < V_27 ) ? V_39 : V_40 ;
}
static T_3
F_14 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_3 * V_4 )
{
char V_24 [ V_25 ] ;
struct V_3 V_41 = { . V_11 = sizeof( V_24 ) ,
. V_13 = V_24 } ;
void * V_6 ;
T_4 V_27 ;
T_5 V_28 ;
T_2 * V_29 ;
unsigned int V_42 ;
F_7 ( L_1 , V_30 ) ;
V_6 = F_5 ( V_2 , V_4 ) ;
F_11 ( & V_35 ) ;
V_28 = V_2 -> V_43 ++ ;
F_12 ( & V_35 ) ;
* ( ( T_5 * ) ( V_6 + 8 ) ) = F_15 ( V_28 ) ;
if ( V_2 -> V_37 ) {
V_29 = V_2 -> V_44 ;
V_42 = V_45 ;
} else {
V_29 = V_2 -> V_46 ;
V_42 = V_47 ;
}
if ( F_16 ( V_2 , V_6 , V_8 ,
V_23 , 0 , V_29 , V_42 , & V_41 ) )
return V_34 ;
memcpy ( V_6 + V_8 , V_41 . V_13 , V_41 . V_11 ) ;
V_27 = F_9 () ;
return ( V_2 -> V_38 < V_27 ) ? V_39 : V_40 ;
}
T_3
F_17 ( struct V_48 * V_48 , struct V_22 * V_23 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_48 -> V_49 ;
switch ( V_2 -> V_50 ) {
default:
F_18 () ;
case V_51 :
case V_52 :
case V_53 :
return F_6 ( V_2 , V_23 , V_4 ) ;
case V_54 :
case V_55 :
return F_14 ( V_2 , V_23 , V_4 ) ;
}
}
