static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned short type , const void * V_5 ,
const void * V_6 , unsigned int V_7 )
{
unsigned char * V_8 ;
if ( type == V_9 )
return 0 ;
V_8 = F_2 ( V_2 , V_10 ) ;
* V_8 ++ = 0x00 ;
if ( V_5 != NULL )
memcpy ( V_8 , V_5 , V_4 -> V_11 ) ;
V_8 [ 6 ] &= ~ V_12 ;
V_8 [ 6 ] &= ~ V_13 ;
V_8 [ 6 ] |= V_14 ;
V_8 += V_15 ;
if ( V_6 != NULL )
memcpy ( V_8 , V_6 , V_4 -> V_11 ) ;
else
memcpy ( V_8 , V_4 -> V_16 , V_4 -> V_11 ) ;
V_8 [ 6 ] &= ~ V_12 ;
V_8 [ 6 ] |= V_13 ;
V_8 [ 6 ] |= V_14 ;
V_8 += V_15 ;
* V_8 ++ = V_17 ;
switch ( type ) {
case V_18 :
* V_8 ++ = V_19 ;
break;
case V_20 :
* V_8 ++ = V_21 ;
break;
default:
F_3 ( V_22 L_1 , type ) ;
* V_8 ++ = 0 ;
break;
}
if ( V_5 != NULL )
return V_10 ;
return - V_10 ;
}
T_1 F_4 ( struct V_1 * V_2 )
{
struct V_1 * V_23 ;
unsigned char * V_24 = V_2 -> V_25 ;
T_2 * V_26 ;
struct V_3 * V_4 = NULL ;
T_3 * V_27 , * V_28 ;
T_4 * V_29 = NULL ;
T_5 * T_5 ;
T_6 * V_30 ;
char V_31 = ' ' ;
V_28 = ( T_3 * ) ( V_24 + 1 ) ;
V_27 = ( T_3 * ) ( V_24 + 8 ) ;
V_26 = F_5 ( V_28 , NULL ) ;
if ( V_26 ) {
V_29 = V_26 -> V_29 ;
V_4 = V_26 -> V_4 ;
V_31 = V_26 -> V_31 ;
}
if ( V_4 == NULL )
V_4 = V_2 -> V_4 ;
if ( ( T_5 = F_6 ( V_4 ) ) == NULL ) {
F_7 ( V_2 ) ;
goto V_32;
}
if ( V_24 [ 16 ] == V_19 ) {
if ( V_31 == 'V' || ( V_31 == ' ' && T_5 -> V_33 [ V_34 ] ) ) {
T_3 V_35 ;
T_3 V_36 ;
if ( ( V_23 = F_8 ( V_2 , V_37 ) ) == NULL ) {
F_7 ( V_2 ) ;
goto V_32;
}
if ( V_2 -> V_38 != NULL )
F_9 ( V_23 , V_2 -> V_38 ) ;
F_7 ( V_2 ) ;
V_24 = V_23 -> V_25 ;
V_36 = * ( T_3 * ) ( V_24 + 1 ) ;
V_35 = * ( T_3 * ) ( V_24 + 8 ) ;
F_10 ( V_23 , V_10 - 1 ) ;
F_11 ( V_23 ) ;
V_30 = F_12 (
V_23 ,
T_5 -> V_33 [ V_39 ] ,
& V_35 ,
& V_36 , V_29 , V_4 ) ;
if ( V_30 ) {
F_13 ( V_30 ) ;
}
goto V_32;
}
}
V_24 [ 7 ] &= ~ V_12 ;
V_24 [ 7 ] &= ~ V_13 ;
V_24 [ 7 ] |= V_14 ;
V_24 [ 14 ] &= ~ V_12 ;
V_24 [ 14 ] |= V_13 ;
V_24 [ 14 ] |= V_14 ;
F_10 ( V_2 , V_40 ) ;
if ( V_29 != NULL ) {
if ( ( V_23 = F_14 ( V_2 , V_27 , V_28 , V_26 -> V_29 ) ) == NULL ) {
F_7 ( V_2 ) ;
goto V_32;
}
V_2 = V_23 ;
}
F_15 ( V_2 , V_4 ) ;
V_32:
if ( V_26 )
F_16 ( V_26 ) ;
return V_41 ;
}
static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned short type , const void * V_5 ,
const void * V_6 , unsigned int V_7 )
{
return - V_10 ;
}
T_1 F_4 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
return V_41 ;
}
static bool F_17 ( const char * V_42 , unsigned int V_7 )
{
T_4 V_43 ;
if ( ! V_7 )
return false ;
if ( V_42 [ 0 ] )
return true ;
return F_18 ( V_42 + 1 , V_7 - 1 , NULL , NULL , & V_43 , NULL ,
NULL ) ;
}
