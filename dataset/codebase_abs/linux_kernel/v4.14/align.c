static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
int V_5 ;
union {
T_1 V_6 ;
T_2 V_7 [ 2 ] ;
T_3 V_8 [ 4 ] ;
T_4 V_9 [ 8 ] ;
} V_10 , V_11 ;
unsigned char T_5 * V_12 , * V_13 ;
unsigned long * V_14 = & V_15 -> V_16 . V_14 [ V_3 ] ;
unsigned int V_17 , V_18 ;
V_4 = ( V_4 >> 1 ) & 0x1f ;
V_13 = ( unsigned char T_5 * ) V_2 -> V_19 ;
V_17 = V_20 [ V_4 ] . V_21 ;
V_18 = V_20 [ V_4 ] . V_18 ;
if ( F_2 ( F_3 ( V_2 ) &&
! F_4 ( ( V_18 & V_22 ? V_23 : V_24 ) ,
V_13 , V_17 ) ) )
return - V_25 ;
if ( F_2 ( ! F_3 ( V_2 ) ) )
return 0 ;
F_5 ( V_15 ) ;
if ( V_18 & V_22 ) {
V_10 . V_6 = 0 ;
switch ( V_4 ) {
case V_26 :
case V_27 :
case V_28 :
V_10 . V_7 [ 0 ] = * V_14 ;
V_10 . V_7 [ 1 ] = V_2 -> V_29 [ V_3 ] ;
break;
case V_30 :
V_10 . V_8 [ 2 ] = * V_14 >> 16 ;
V_10 . V_8 [ 3 ] = V_2 -> V_29 [ V_3 ] >> 16 ;
break;
case V_31 :
V_10 . V_8 [ 2 ] = * V_14 & 0xffff ;
V_10 . V_8 [ 3 ] = V_2 -> V_29 [ V_3 ] & 0xffff ;
break;
case V_32 :
V_10 . V_7 [ 1 ] = * V_14 ;
break;
case V_33 :
V_10 . V_7 [ 1 ] = V_2 -> V_29 [ V_3 ] ;
break;
default:
return - V_34 ;
}
} else {
V_11 . V_6 = V_10 . V_6 = 0 ;
V_5 = 0 ;
V_12 = V_13 ;
switch ( V_17 ) {
case 8 :
V_5 |= F_6 ( V_11 . V_9 [ 0 ] , V_12 ++ ) ;
V_5 |= F_6 ( V_11 . V_9 [ 1 ] , V_12 ++ ) ;
V_5 |= F_6 ( V_11 . V_9 [ 2 ] , V_12 ++ ) ;
V_5 |= F_6 ( V_11 . V_9 [ 3 ] , V_12 ++ ) ;
case 4 :
V_5 |= F_6 ( V_11 . V_9 [ 4 ] , V_12 ++ ) ;
V_5 |= F_6 ( V_11 . V_9 [ 5 ] , V_12 ++ ) ;
case 2 :
V_5 |= F_6 ( V_11 . V_9 [ 6 ] , V_12 ++ ) ;
V_5 |= F_6 ( V_11 . V_9 [ 7 ] , V_12 ++ ) ;
if ( F_2 ( V_5 ) )
return - V_25 ;
}
switch ( V_4 ) {
case V_35 :
case V_36 :
case V_37 :
V_10 . V_6 = V_11 . V_6 ;
break;
case V_38 :
V_10 . V_8 [ 0 ] = V_11 . V_8 [ 3 ] ;
V_10 . V_8 [ 2 ] = V_11 . V_8 [ 3 ] ;
break;
case V_39 :
case V_40 :
V_10 . V_8 [ 1 ] = V_11 . V_8 [ 3 ] ;
V_10 . V_8 [ 3 ] = V_11 . V_8 [ 3 ] ;
break;
case V_41 :
V_10 . V_8 [ 0 ] = V_11 . V_8 [ 2 ] ;
V_10 . V_8 [ 2 ] = V_11 . V_8 [ 3 ] ;
break;
case V_42 :
case V_43 :
V_10 . V_8 [ 1 ] = V_11 . V_8 [ 2 ] ;
V_10 . V_8 [ 3 ] = V_11 . V_8 [ 3 ] ;
break;
case V_44 :
V_10 . V_7 [ 0 ] = V_11 . V_7 [ 1 ] ;
V_10 . V_7 [ 1 ] = V_11 . V_7 [ 1 ] ;
break;
case V_45 :
V_10 . V_8 [ 0 ] = V_11 . V_8 [ 2 ] ;
V_10 . V_8 [ 1 ] = V_11 . V_8 [ 2 ] ;
V_10 . V_8 [ 2 ] = V_11 . V_8 [ 3 ] ;
V_10 . V_8 [ 3 ] = V_11 . V_8 [ 3 ] ;
break;
default:
return - V_34 ;
}
}
if ( V_18 & V_46 ) {
switch ( V_18 & 0xf0 ) {
case V_47 :
V_10 . V_6 = F_7 ( V_10 . V_6 ) ;
break;
case V_48 :
V_10 . V_7 [ 0 ] = F_8 ( V_10 . V_7 [ 0 ] ) ;
V_10 . V_7 [ 1 ] = F_8 ( V_10 . V_7 [ 1 ] ) ;
break;
default:
V_10 . V_8 [ 0 ] = F_9 ( V_10 . V_8 [ 0 ] ) ;
V_10 . V_8 [ 1 ] = F_9 ( V_10 . V_8 [ 1 ] ) ;
V_10 . V_8 [ 2 ] = F_9 ( V_10 . V_8 [ 2 ] ) ;
V_10 . V_8 [ 3 ] = F_9 ( V_10 . V_8 [ 3 ] ) ;
break;
}
}
if ( V_18 & V_49 ) {
V_10 . V_7 [ 0 ] = ( V_50 ) V_10 . V_8 [ 1 ] ;
V_10 . V_7 [ 1 ] = ( V_50 ) V_10 . V_8 [ 3 ] ;
}
if ( V_18 & V_22 ) {
V_5 = 0 ;
V_12 = V_13 ;
switch ( V_17 ) {
case 8 :
V_5 |= F_10 ( V_10 . V_9 [ 0 ] , V_12 ++ ) ;
V_5 |= F_10 ( V_10 . V_9 [ 1 ] , V_12 ++ ) ;
V_5 |= F_10 ( V_10 . V_9 [ 2 ] , V_12 ++ ) ;
V_5 |= F_10 ( V_10 . V_9 [ 3 ] , V_12 ++ ) ;
case 4 :
V_5 |= F_10 ( V_10 . V_9 [ 4 ] , V_12 ++ ) ;
V_5 |= F_10 ( V_10 . V_9 [ 5 ] , V_12 ++ ) ;
case 2 :
V_5 |= F_10 ( V_10 . V_9 [ 6 ] , V_12 ++ ) ;
V_5 |= F_10 ( V_10 . V_9 [ 7 ] , V_12 ++ ) ;
}
if ( F_2 ( V_5 ) )
return - V_25 ;
} else {
* V_14 = V_10 . V_7 [ 0 ] ;
V_2 -> V_29 [ V_3 ] = V_10 . V_7 [ 1 ] ;
}
return 1 ;
}
int F_11 ( struct V_1 * V_2 )
{
unsigned int V_4 ;
struct V_51 V_52 ;
int V_53 , type ;
F_12 ( V_2 ) ;
if ( F_2 ( F_13 ( V_4 , ( unsigned int T_5 * ) V_2 -> V_54 ) ) )
return - V_25 ;
if ( ( V_2 -> V_55 & V_56 ) != ( V_57 & V_56 ) ) {
if ( F_14 ( V_58 ) )
return - V_59 ;
V_4 = F_8 ( V_4 ) ;
}
#ifdef F_15
if ( ( V_4 >> 26 ) == 0x4 ) {
int V_3 = ( V_4 >> 21 ) & 0x1f ;
F_16 ( V_60 , V_2 ) ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
#endif
if ( ( V_4 & 0xfc0006fe ) == ( V_61 & 0xfc0006fe ) )
return - V_59 ;
V_53 = F_17 ( & V_52 , V_2 , V_4 ) ;
if ( V_53 < 0 )
return - V_34 ;
type = V_52 . type & V_62 ;
if ( ! F_18 ( type ) ) {
if ( V_52 . type != V_63 + V_64 )
return - V_34 ;
F_16 ( V_65 , V_2 ) ;
V_53 = F_19 ( V_52 . V_66 , V_2 ) ;
} else {
if ( type == V_67 || type == V_68 )
return - V_59 ;
F_16 ( V_69 , V_2 ) ;
V_53 = F_20 ( V_2 , & V_52 ) ;
}
if ( ! V_53 )
return 1 ;
return V_53 ;
}
