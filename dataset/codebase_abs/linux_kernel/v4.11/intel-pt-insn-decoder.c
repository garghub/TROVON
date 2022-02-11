static void F_1 ( struct V_1 * V_1 ,
struct V_2 * V_2 )
{
enum V_3 V_4 = V_5 ;
enum V_6 V_7 = V_8 ;
int V_9 ;
if ( F_2 ( V_1 ) ) {
V_2 -> V_4 = V_5 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_10 = V_1 -> V_10 ;
return;
}
switch ( V_1 -> V_11 . V_12 [ 0 ] ) {
case 0xf :
switch ( V_1 -> V_11 . V_12 [ 1 ] ) {
case 0x05 :
case 0x34 :
V_4 = V_13 ;
V_7 = V_14 ;
break;
case 0x07 :
case 0x35 :
V_4 = V_15 ;
V_7 = V_14 ;
break;
case 0x80 ... 0x8f :
V_4 = V_16 ;
V_7 = V_17 ;
break;
default:
break;
}
break;
case 0x70 ... 0x7f :
V_4 = V_16 ;
V_7 = V_17 ;
break;
case 0xc2 :
case 0xc3 :
case 0xca :
case 0xcb :
V_4 = V_18 ;
V_7 = V_14 ;
break;
case 0xcf :
V_4 = V_19 ;
V_7 = V_14 ;
break;
case 0xcc ... 0xce :
V_4 = V_20 ;
V_7 = V_14 ;
break;
case 0xe8 :
V_4 = V_21 ;
V_7 = V_22 ;
break;
case 0x9a :
V_4 = V_21 ;
V_7 = V_14 ;
break;
case 0xe0 ... 0xe2 :
V_4 = V_23 ;
V_7 = V_17 ;
break;
case 0xe3 :
V_4 = V_16 ;
V_7 = V_17 ;
break;
case 0xe9 :
case 0xeb :
V_4 = V_24 ;
V_7 = V_22 ;
break;
case 0xea :
V_4 = V_24 ;
V_7 = V_14 ;
break;
case 0xff :
V_9 = ( V_1 -> V_25 . V_12 [ 0 ] >> 3 ) & 0x7 ;
switch ( V_9 ) {
case 2 :
case 3 :
V_4 = V_21 ;
V_7 = V_14 ;
break;
case 4 :
case 5 :
V_4 = V_24 ;
V_7 = V_14 ;
break;
default:
break;
}
break;
default:
break;
}
V_2 -> V_4 = V_4 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_10 = V_1 -> V_10 ;
if ( V_7 == V_17 ||
V_7 == V_22 ) {
#if V_26 == V_27
switch ( V_1 -> V_28 . V_29 ) {
case 1 :
V_2 -> V_30 = V_1 -> V_28 . V_31 ;
break;
case 2 :
V_2 -> V_30 =
F_3 ( ( short ) V_1 -> V_28 . V_31 ) ;
break;
case 4 :
V_2 -> V_30 = F_4 ( V_1 -> V_28 . V_31 ) ;
break;
default:
V_2 -> V_30 = 0 ;
break;
}
#else
V_2 -> V_30 = V_1 -> V_28 . V_31 ;
#endif
}
}
int F_5 ( const unsigned char * V_32 , T_1 V_33 , int V_34 ,
struct V_2 * V_2 )
{
struct V_1 V_1 ;
F_6 ( & V_1 , V_32 , V_33 , V_34 ) ;
F_7 ( & V_1 ) ;
if ( ! F_8 ( & V_1 ) || V_1 . V_10 > V_33 )
return - 1 ;
F_1 ( & V_1 , V_2 ) ;
if ( V_1 . V_10 < V_35 )
memcpy ( V_2 -> V_32 , V_32 , V_1 . V_10 ) ;
else
memcpy ( V_2 -> V_32 , V_32 , V_35 ) ;
return 0 ;
}
const char * F_9 ( enum V_3 V_4 )
{
return V_36 [ V_4 ] ;
}
int F_10 ( const struct V_2 * V_2 , char * V_32 ,
T_1 V_37 )
{
switch ( V_2 -> V_7 ) {
case V_17 :
case V_22 :
return snprintf ( V_32 , V_37 , L_1 ,
F_9 ( V_2 -> V_4 ) ,
V_2 -> V_30 > 0 ? L_2 : L_3 ,
V_2 -> V_30 ) ;
case V_8 :
case V_14 :
return snprintf ( V_32 , V_37 , L_4 ,
F_9 ( V_2 -> V_4 ) ) ;
default:
break;
}
return 0 ;
}
int F_11 ( enum V_3 V_4 )
{
switch ( V_4 ) {
case V_5 :
return 0 ;
case V_21 :
return V_38 | V_39 ;
case V_18 :
return V_38 | V_40 ;
case V_16 :
return V_38 | V_41 ;
case V_24 :
return V_38 ;
case V_23 :
return V_38 | V_41 ;
case V_19 :
return V_38 | V_40 |
V_42 ;
case V_20 :
return V_38 | V_39 |
V_42 ;
case V_13 :
return V_38 | V_39 |
V_43 ;
case V_15 :
return V_38 | V_40 |
V_43 ;
default:
return 0 ;
}
}
