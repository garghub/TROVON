static void
F_1 ( struct V_1 * V_2 ) {
if ( F_2 ( V_3 , & V_2 -> V_4 ) ) {
F_3 ( & V_2 -> V_5 . V_6 . V_7 ) ;
}
F_4 ( & V_2 -> V_5 . V_6 . V_7 ) ;
V_2 -> V_5 . V_6 . V_7 . V_8 = V_9 + ( ( V_10 * V_11 ) / 1000 ) ;
F_5 ( & V_2 -> V_5 . V_6 . V_7 ) ;
}
static void
F_6 ( struct V_1 * V_2 ) {
F_1 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_12 = 0 ;
V_2 -> V_5 . V_6 . V_13 = V_2 -> V_5 . V_6 . V_14 -> V_15 ;
memcpy ( V_2 -> V_5 . V_6 . V_16 , V_2 -> V_5 . V_6 . V_14 -> V_17 , V_2 -> V_5 . V_6 . V_13 ) ;
switch ( V_2 -> V_5 . V_6 . V_18 ) {
case 0 : break;
case 1 : V_2 -> V_5 . V_6 . V_16 [ 1 ] |= 0x40 ;
break;
default: break;
}
V_2 -> V_5 . V_6 . V_19 &= 0x0f ;
V_2 -> V_5 . V_6 . V_19 |= 0xa0 ;
V_2 -> V_20 ( V_2 , V_21 , V_2 -> V_5 . V_6 . V_19 ) ;
( void ) V_2 -> V_22 ( V_2 , V_23 ) ;
V_2 -> V_20 ( V_2 , V_24 , V_2 -> V_5 . V_6 . V_16 [ V_2 -> V_5 . V_6 . V_12 ++ ] ) ;
V_2 -> V_5 . V_6 . V_19 |= 0x10 ;
V_2 -> V_20 ( V_2 , V_21 , V_2 -> V_5 . V_6 . V_19 ) ;
}
int
F_7 ( struct V_1 * V_2 , int V_25 , void * V_26 ) {
if ( V_2 -> V_27 & V_28 ) {
F_8 ( V_2 , L_1 , V_2 -> V_5 . V_6 . V_29 , V_25 ) ;
}
if ( V_25 == V_30 ) {
V_2 -> V_5 . V_6 . V_29 = V_31 ;
F_2 ( V_32 , & V_2 -> V_4 ) ;
F_9 ( & V_2 -> V_5 . V_6 . V_33 ) ;
return ( 1 ) ;
}
switch ( V_2 -> V_5 . V_6 . V_29 ) {
case V_31 :
if ( V_25 == V_34 ) {
V_2 -> V_5 . V_6 . V_14 = V_26 ;
V_2 -> V_5 . V_6 . V_29 = V_35 ;
F_6 ( V_2 ) ;
}
break;
case V_35 :
if ( V_25 == V_36 ) {
if ( V_2 -> V_5 . V_6 . V_14 -> V_37 ) {
F_1 ( V_2 ) ;
V_2 -> V_5 . V_6 . V_29 = V_38 ;
} else {
if ( V_2 -> V_5 . V_6 . V_14 -> V_39 ) {
V_2 -> V_5 . V_6 . V_14 =
V_2 -> V_5 . V_6 . V_14 -> V_39 ;
F_6 ( V_2 ) ;
} else {
if ( F_10 ( V_3 , & V_2 -> V_4 ) ) {
F_3 ( & V_2 -> V_5 . V_6 . V_7 ) ;
}
V_2 -> V_5 . V_6 . V_29 = V_31 ;
F_9 ( & V_2 -> V_5 . V_6 . V_33 ) ;
}
}
}
break;
case V_38 :
if ( V_25 == V_40 ) {
if ( V_2 -> V_5 . V_6 . V_14 -> V_39 ) {
V_2 -> V_5 . V_6 . V_14 =
V_2 -> V_5 . V_6 . V_14 -> V_39 ;
V_2 -> V_5 . V_6 . V_29 = V_35 ;
F_6 ( V_2 ) ;
} else {
if ( F_10 ( V_3 , & V_2 -> V_4 ) ) {
F_3 ( & V_2 -> V_5 . V_6 . V_7 ) ;
}
V_2 -> V_5 . V_6 . V_29 = V_31 ;
F_9 ( & V_2 -> V_5 . V_6 . V_33 ) ;
}
}
break;
default:
F_8 ( V_2 , L_2 , V_2 -> V_5 . V_6 . V_29 ) ;
return ( 2 ) ;
}
return ( 0 ) ;
}
static void
F_11 ( struct V_1 * V_2 ) {
F_7 ( V_2 , V_30 , NULL ) ;
}
void
F_12 ( struct V_1 * V_2 ) {
if ( F_10 ( V_3 , & V_2 -> V_4 ) ) {
F_3 ( & V_2 -> V_5 . V_6 . V_7 ) ;
}
}
void
F_13 ( struct V_1 * V_2 ) {
F_14 ( & V_2 -> V_5 . V_6 . V_7 , ( void * ) F_11 , ( long ) V_2 ) ;
F_15 ( & V_2 -> V_5 . V_6 . V_33 ) ;
F_2 ( V_41 , & V_2 -> V_4 ) ;
}
