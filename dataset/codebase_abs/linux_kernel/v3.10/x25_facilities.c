int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned long * V_7 )
{
unsigned char * V_8 ;
unsigned int V_9 ;
* V_7 = 0 ;
V_6 -> V_10 = 0 ;
V_6 -> V_11 = 0 ;
memset ( V_6 -> V_12 , '\0' , sizeof( V_6 -> V_12 ) ) ;
memset ( V_6 -> V_13 , '\0' , sizeof( V_6 -> V_13 ) ) ;
if ( ! F_2 ( V_2 , 1 ) )
return 0 ;
V_9 = V_2 -> V_14 [ 0 ] ;
if ( ! F_2 ( V_2 , 1 + V_9 ) )
return - 1 ;
V_8 = V_2 -> V_14 + 1 ;
while ( V_9 > 0 ) {
switch ( * V_8 & V_15 ) {
case V_16 :
if ( V_9 < 2 )
return - 1 ;
switch ( * V_8 ) {
case V_17 :
if( ( V_8 [ 1 ] & 0x81 ) == 0x81 ) {
V_4 -> V_18 = V_8 [ 1 ] & 0x81 ;
* V_7 |= V_19 ;
break;
}
if( ( V_8 [ 1 ] & 0x01 ) == 0x01 ) {
V_4 -> V_18 = V_8 [ 1 ] & 0x01 ;
* V_7 |= V_19 ;
break;
}
if( ( V_8 [ 1 ] & 0x80 ) == 0x80 ) {
V_4 -> V_18 = V_8 [ 1 ] & 0x80 ;
* V_7 |= V_19 ;
break;
}
if( V_8 [ 1 ] == 0x00 ) {
V_4 -> V_18
= V_20 ;
* V_7 |= V_19 ;
break;
}
case V_21 :
V_4 -> V_22 = V_8 [ 1 ] ;
* V_7 |= V_23 ;
break;
case V_24 :
break;
default:
F_3 ( V_25 L_1
L_2 ,
V_8 [ 0 ] , V_8 [ 1 ] ) ;
break;
}
V_8 += 2 ;
V_9 -= 2 ;
break;
case V_26 :
if ( V_9 < 3 )
return - 1 ;
switch ( * V_8 ) {
case V_27 :
V_4 -> V_28 = V_8 [ 1 ] ;
V_4 -> V_29 = V_8 [ 2 ] ;
* V_7 |= V_30 ;
break;
case V_31 :
V_4 -> V_32 = V_8 [ 1 ] ;
V_4 -> V_33 = V_8 [ 2 ] ;
* V_7 |= V_34 ;
break;
default:
F_3 ( V_25 L_1
L_3 ,
V_8 [ 0 ] , V_8 [ 1 ] , V_8 [ 2 ] ) ;
break;
}
V_8 += 3 ;
V_9 -= 3 ;
break;
case V_35 :
if ( V_9 < 4 )
return - 1 ;
F_3 ( V_25 L_4
L_5 ,
V_8 [ 0 ] , V_8 [ 1 ] , V_8 [ 2 ] , V_8 [ 3 ] ) ;
V_8 += 4 ;
V_9 -= 4 ;
break;
case V_36 :
if ( V_9 < V_8 [ 1 ] + 2 )
return - 1 ;
switch ( * V_8 ) {
case V_37 :
if ( V_8 [ 1 ] > V_38 || V_8 [ 1 ] <= 1 )
return - 1 ;
V_6 -> V_10 = V_8 [ 2 ] ;
memcpy ( V_6 -> V_13 , & V_8 [ 3 ] , V_8 [ 1 ] - 1 ) ;
* V_7 |= V_39 ;
break;
case V_40 :
if ( V_8 [ 1 ] > V_38 || V_8 [ 1 ] <= 1 )
return - 1 ;
V_6 -> V_11 = V_8 [ 2 ] ;
memcpy ( V_6 -> V_12 , & V_8 [ 3 ] , V_8 [ 1 ] - 1 ) ;
* V_7 |= V_41 ;
break;
default:
F_3 ( V_25 L_6
L_7 , V_8 [ 0 ] , V_8 [ 1 ] ) ;
break;
}
V_9 -= V_8 [ 1 ] + 2 ;
V_8 += V_8 [ 1 ] + 2 ;
break;
}
}
return V_8 - V_2 -> V_14 ;
}
int F_4 ( unsigned char * V_42 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned long V_43 )
{
unsigned char * V_8 = V_42 + 1 ;
int V_9 ;
if ( ! V_43 ) {
V_42 [ 0 ] = 0 ;
V_9 = 1 ;
return V_9 ;
}
if ( V_4 -> V_18 && ( V_43 & V_19 ) ) {
* V_8 ++ = V_17 ;
* V_8 ++ = V_4 -> V_18 ;
}
if ( V_4 -> V_22 && ( V_43 & V_23 ) ) {
* V_8 ++ = V_21 ;
* V_8 ++ = V_4 -> V_22 ;
}
if ( ( V_4 -> V_28 || V_4 -> V_29 ) &&
( V_43 & V_30 ) ) {
* V_8 ++ = V_27 ;
* V_8 ++ = V_4 -> V_28 ? : V_4 -> V_29 ;
* V_8 ++ = V_4 -> V_29 ? : V_4 -> V_28 ;
}
if ( ( V_4 -> V_32 || V_4 -> V_33 ) &&
( V_43 & V_34 ) ) {
* V_8 ++ = V_31 ;
* V_8 ++ = V_4 -> V_32 ? : V_4 -> V_33 ;
* V_8 ++ = V_4 -> V_33 ? : V_4 -> V_32 ;
}
if ( V_43 & ( V_39 | V_41 ) ) {
* V_8 ++ = V_24 ;
* V_8 ++ = V_44 ;
}
if ( V_6 -> V_10 && ( V_43 & V_39 ) ) {
unsigned int V_45 = ( V_6 -> V_10 + 1 ) >> 1 ;
* V_8 ++ = V_37 ;
* V_8 ++ = 1 + V_45 ;
* V_8 ++ = V_6 -> V_10 ;
memcpy ( V_8 , V_6 -> V_13 , V_45 ) ;
V_8 += V_45 ;
}
if ( V_6 -> V_11 && ( V_43 & V_41 ) ) {
unsigned int V_45 = ( V_6 -> V_11 % 2 ) ?
V_6 -> V_11 / 2 + 1 :
V_6 -> V_11 / 2 ;
* V_8 ++ = V_40 ;
* V_8 ++ = 1 + V_45 ;
* V_8 ++ = V_6 -> V_11 ;
memcpy ( V_8 , V_6 -> V_12 , V_45 ) ;
V_8 += V_45 ;
}
V_9 = V_8 - V_42 ;
V_42 [ 0 ] = V_9 - 1 ;
return V_9 ;
}
int F_5 ( struct V_1 * V_2 , struct V_46 * V_47 ,
struct V_3 * V_48 , struct V_5 * V_49 )
{
struct V_50 * V_51 = F_6 ( V_47 ) ;
struct V_3 * V_52 = & V_51 -> V_4 ;
struct V_3 V_53 ;
int V_9 ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
memcpy ( V_48 , V_52 , sizeof( * V_48 ) ) ;
V_9 = F_1 ( V_2 , & V_53 , V_49 , & V_51 -> V_54 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( ( V_53 . V_18 & 0x01 ) && ( V_52 -> V_18 & 0x01 ) ) {
F_7 ( V_47 , L_8 ) ;
return - 1 ;
}
V_48 -> V_18 = V_53 . V_18 ;
if ( V_53 . V_22 ) {
int V_55 = V_53 . V_22 & 0x0f ;
int V_56 = V_53 . V_22 & 0xf0 ;
int V_57 = V_52 -> V_22 & 0x0f ;
int V_58 = V_52 -> V_22 & 0xf0 ;
if ( ! V_57 || V_55 < V_57 ) {
F_7 ( V_47 , L_9 ) ;
V_48 -> V_22 = ( V_48 -> V_22 & 0xf0 ) | V_55 ;
}
if ( ! V_58 || V_56 < V_58 ) {
F_7 ( V_47 ,
L_10 ) ;
V_48 -> V_22 = ( V_48 -> V_22 & 0x0f ) | V_56 ;
}
}
if ( V_53 . V_28 && V_53 . V_29 ) {
if ( V_53 . V_28 < V_52 -> V_28 ) {
F_7 ( V_47 , L_11 ) ;
V_48 -> V_28 = V_53 . V_28 ;
}
if ( V_53 . V_29 < V_52 -> V_29 ) {
F_7 ( V_47 , L_12 ) ;
V_48 -> V_29 = V_53 . V_29 ;
}
}
if ( V_53 . V_32 && V_53 . V_33 ) {
if ( V_53 . V_32 < V_52 -> V_32 ) {
F_7 ( V_47 , L_13 ) ;
V_48 -> V_32 = V_53 . V_32 ;
}
if ( V_53 . V_33 < V_52 -> V_33 ) {
F_7 ( V_47 , L_14 ) ;
V_48 -> V_33 = V_53 . V_33 ;
}
}
return V_9 ;
}
void F_8 ( struct V_3 * V_4 ,
struct V_59 * V_60 )
{
if ( ! V_60 -> V_61 ) {
if ( V_4 -> V_32 > 7 ) {
F_3 ( V_25 L_15 ) ;
V_4 -> V_32 = 7 ;
}
if ( V_4 -> V_33 > 7 ) {
V_4 -> V_33 = 7 ;
F_3 ( V_25 L_16 ) ;
}
}
}
