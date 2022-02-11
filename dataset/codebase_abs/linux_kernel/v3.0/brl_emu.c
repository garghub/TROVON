struct V_1
F_1 ( struct V_2 * V_3 , unsigned long V_4 )
{
unsigned long V_5 [ 2 ] ;
unsigned long V_6 , V_7 , V_8 , V_9 , V_10 ;
unsigned long V_11 ;
struct V_12 V_12 ;
struct V_1 V_13 ;
long V_14 , V_15 ;
V_13 . V_16 = ( unsigned long ) - 1 ;
if ( F_2 ( V_5 , ( void * ) ( V_3 -> V_17 ) , sizeof( V_5 ) ) )
return V_13 ;
V_11 = ( unsigned long ) V_3 -> V_17 + 16 ;
if ( F_3 ( V_3 ) -> V_18 != 1 ) return V_13 ;
if ( ( V_5 [ 0 ] & 0x1e ) != 0x4 ) return V_13 ;
V_6 = ( V_5 [ 1 ] >> 60 ) ;
V_7 = ( ( V_5 [ 1 ] >> 29 ) & 0x7 ) ;
V_8 = ( ( V_5 [ 1 ] >> 23 ) & 0x3f ) ;
V_9 = ( ( V_5 [ 1 ] & 0x0800000000000000L ) << 4 )
| ( ( V_5 [ 1 ] & 0x00fffff000000000L ) >> 32 )
| ( ( V_5 [ 1 ] & 0x00000000007fffffL ) << 40 )
| ( ( V_5 [ 0 ] & 0xffff000000000000L ) >> 24 ) ;
V_14 = V_3 -> V_19 & ( 1L << V_8 ) ;
switch( V_6 ) {
case 0xC :
if ( V_7 != 0 ) return V_13 ;
V_13 . V_16 = 0 ;
if ( ! ( V_14 ) ) {
V_3 -> V_17 = V_11 ;
F_3 ( V_3 ) -> V_18 = 0 ;
return V_13 ;
}
break;
case 0xD :
V_13 . V_16 = 0 ;
if ( ! ( V_14 ) ) {
V_3 -> V_17 = V_11 ;
F_3 ( V_3 ) -> V_18 = 0 ;
return V_13 ;
}
switch( V_7 ) {
case 0 :
V_3 -> V_20 = V_11 ;
break;
case 1 :
V_13 . V_16 = ( unsigned long ) & V_21 ;
break;
case 2 :
V_13 . V_16 = ( unsigned long ) & V_22 ;
break;
case 3 :
V_13 . V_16 = ( unsigned long ) & V_23 ;
break;
case 4 :
V_13 . V_16 = ( unsigned long ) & V_24 ;
break;
case 5 :
V_13 . V_16 = ( unsigned long ) & V_25 ;
break;
case 6 :
V_3 -> V_26 = V_11 ;
break;
case 7 :
V_3 -> V_27 = V_11 ;
break;
}
V_13 . V_28 = V_11 ;
V_10 = F_3 ( V_3 ) -> V_10 ;
V_3 -> V_29 = ( ( V_3 -> V_30 & 0x3fffffffff )
| ( V_4 << 52 ) | ( V_10 << 62 ) ) ;
V_3 -> V_30 = ( ( V_3 -> V_30 & 0xffffffc00000007f )
- ( ( V_3 -> V_30 >> 7 ) & 0x7f ) ) ;
break;
default:
return V_13 ;
}
V_3 -> V_17 += V_9 ;
F_3 ( V_3 ) -> V_18 = 0 ;
if ( F_3 ( V_3 ) -> V_31 == 0 )
V_15 = F_4 ( V_3 -> V_17 ) ;
else
V_15 = F_5 ( V_3 -> V_17 ) ;
if ( V_15 ) {
F_6 ( V_32 L_1 ) ;
V_12 . V_33 = V_34 ;
V_12 . V_35 = 0 ;
V_12 . V_36 = 0 ;
V_12 . V_37 = 0 ;
V_12 . V_38 = 0 ;
V_12 . V_39 = V_40 ;
F_7 ( V_34 , & V_12 , V_41 ) ;
} else if ( F_3 ( V_3 ) -> V_42 ) {
V_12 . V_33 = V_43 ;
V_12 . V_35 = 0 ;
V_12 . V_39 = V_44 ;
V_12 . V_36 = 0 ;
V_12 . V_37 = 0 ;
V_12 . V_45 = 0 ;
V_12 . V_38 = 0 ;
F_7 ( V_43 , & V_12 , V_41 ) ;
} else if ( F_3 ( V_3 ) -> V_46 ) {
V_12 . V_33 = V_43 ;
V_12 . V_35 = 0 ;
V_12 . V_39 = V_47 ;
V_12 . V_36 = 0 ;
V_12 . V_37 = 0 ;
V_12 . V_45 = 0 ;
V_12 . V_38 = 0 ;
F_7 ( V_43 , & V_12 , V_41 ) ;
}
return V_13 ;
}
