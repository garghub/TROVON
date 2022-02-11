static void F_1 ( struct V_1 * V_1 ,
struct V_2 * V_2 )
{
enum V_3 V_4 = V_5 ;
enum V_6 V_7 = V_8 ;
int V_9 ;
V_2 -> V_10 = 0 ;
if ( F_2 ( V_1 ) ) {
V_2 -> V_4 = V_5 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_11 = V_1 -> V_11 ;
return;
}
switch ( V_1 -> V_12 . V_13 [ 0 ] ) {
case 0xf :
switch ( V_1 -> V_12 . V_13 [ 1 ] ) {
case 0x05 :
case 0x34 :
V_4 = V_14 ;
V_7 = V_15 ;
break;
case 0x07 :
case 0x35 :
V_4 = V_16 ;
V_7 = V_15 ;
break;
case 0x80 ... 0x8f :
V_4 = V_17 ;
V_7 = V_18 ;
break;
default:
break;
}
break;
case 0x70 ... 0x7f :
V_4 = V_17 ;
V_7 = V_18 ;
break;
case 0xc2 :
case 0xc3 :
case 0xca :
case 0xcb :
V_4 = V_19 ;
V_7 = V_15 ;
break;
case 0xcf :
V_4 = V_20 ;
V_7 = V_15 ;
break;
case 0xcc ... 0xce :
V_4 = V_21 ;
V_7 = V_15 ;
break;
case 0xe8 :
V_4 = V_22 ;
V_7 = V_23 ;
break;
case 0x9a :
V_4 = V_22 ;
V_7 = V_15 ;
break;
case 0xe0 ... 0xe2 :
V_4 = V_24 ;
V_7 = V_18 ;
break;
case 0xe3 :
V_4 = V_17 ;
V_7 = V_18 ;
break;
case 0xe9 :
case 0xeb :
V_4 = V_25 ;
V_7 = V_23 ;
break;
case 0xea :
V_4 = V_25 ;
V_7 = V_15 ;
break;
case 0xff :
V_9 = ( V_1 -> V_26 . V_13 [ 0 ] >> 3 ) & 0x7 ;
switch ( V_9 ) {
case 2 :
case 3 :
V_4 = V_22 ;
V_7 = V_15 ;
break;
case 4 :
case 5 :
V_4 = V_25 ;
V_7 = V_15 ;
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
V_2 -> V_11 = V_1 -> V_11 ;
if ( V_7 == V_18 ||
V_7 == V_23 ) {
#if V_27 == V_28
switch ( V_1 -> V_29 . V_30 ) {
case 1 :
V_2 -> V_10 = V_1 -> V_29 . V_31 ;
break;
case 2 :
V_2 -> V_10 =
F_3 ( ( short ) V_1 -> V_29 . V_31 ) ;
break;
case 4 :
V_2 -> V_10 = F_4 ( V_1 -> V_29 . V_31 ) ;
break;
default:
V_2 -> V_10 = 0 ;
break;
}
#else
V_2 -> V_10 = V_1 -> V_29 . V_31 ;
#endif
}
}
int F_5 ( const unsigned char * V_32 , T_1 V_33 , int V_34 ,
struct V_2 * V_2 )
{
struct V_1 V_1 ;
F_6 ( & V_1 , V_32 , V_33 , V_34 ) ;
F_7 ( & V_1 ) ;
if ( ! F_8 ( & V_1 ) || V_1 . V_11 > V_33 )
return - 1 ;
F_1 ( & V_1 , V_2 ) ;
if ( V_1 . V_11 < V_35 )
memcpy ( V_2 -> V_32 , V_32 , V_1 . V_11 ) ;
else
memcpy ( V_2 -> V_32 , V_32 , V_35 ) ;
return 0 ;
}
const char * F_9 ( struct V_36 * V_37 , T_2 T_3 V_38 ,
T_4 * V_39 , int V_40 , int * V_41 )
{
struct V_1 V_1 ;
int V_42 , V_43 ;
int V_44 ;
F_6 ( & V_1 , V_39 , V_40 , V_37 -> V_45 ) ;
F_7 ( & V_1 ) ;
if ( ! F_8 ( & V_1 ) || V_1 . V_11 > V_40 )
return L_1 ;
if ( V_41 )
* V_41 = V_1 . V_11 ;
V_44 = sizeof( V_37 -> V_46 ) ;
V_42 = snprintf ( V_37 -> V_46 , V_44 , L_2 ) ;
V_44 -= V_42 ;
for ( V_43 = 0 ; V_43 < V_1 . V_11 ; V_43 ++ ) {
V_42 += snprintf ( V_37 -> V_46 + V_42 , V_44 , L_3 , V_39 [ V_43 ] ) ;
V_44 -= V_42 ;
}
return V_37 -> V_46 ;
}
const char * F_10 ( enum V_3 V_4 )
{
return V_47 [ V_4 ] ;
}
int F_11 ( const struct V_2 * V_2 , char * V_32 ,
T_1 V_48 )
{
switch ( V_2 -> V_7 ) {
case V_18 :
case V_23 :
return snprintf ( V_32 , V_48 , L_4 ,
F_10 ( V_2 -> V_4 ) ,
V_2 -> V_10 > 0 ? L_5 : L_6 ,
V_2 -> V_10 ) ;
case V_8 :
case V_15 :
return snprintf ( V_32 , V_48 , L_7 ,
F_10 ( V_2 -> V_4 ) ) ;
default:
break;
}
return 0 ;
}
int F_12 ( enum V_3 V_4 )
{
switch ( V_4 ) {
case V_5 :
return 0 ;
case V_22 :
return V_49 | V_50 ;
case V_19 :
return V_49 | V_51 ;
case V_17 :
return V_49 | V_52 ;
case V_25 :
return V_49 ;
case V_24 :
return V_49 | V_52 ;
case V_20 :
return V_49 | V_51 |
V_53 ;
case V_21 :
return V_49 | V_50 |
V_53 ;
case V_14 :
return V_49 | V_50 |
V_54 ;
case V_16 :
return V_49 | V_51 |
V_54 ;
default:
return 0 ;
}
}
