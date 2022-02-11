union V_1 F_1 ( union V_1 V_2 , union V_1 V_3 )
{
int V_4 ;
int V_5 ;
unsigned V_6 ;
unsigned short V_7 ;
unsigned short V_8 ;
unsigned short V_9 ;
unsigned short V_10 ;
unsigned V_11 ;
unsigned V_12 ;
unsigned V_13 ;
unsigned V_14 ;
V_15 ;
V_16 ;
V_17 ;
V_18 ;
F_2 () ;
V_19 ;
V_20 ;
switch ( F_3 ( V_21 , V_22 ) ) {
case F_3 ( V_23 , V_24 ) :
case F_3 ( V_25 , V_24 ) :
case F_3 ( V_26 , V_24 ) :
case F_3 ( V_27 , V_24 ) :
case F_3 ( V_28 , V_24 ) :
return F_4 ( V_3 ) ;
case F_3 ( V_24 , V_24 ) :
case F_3 ( V_24 , V_23 ) :
case F_3 ( V_24 , V_25 ) :
case F_3 ( V_24 , V_26 ) :
case F_3 ( V_24 , V_27 ) :
case F_3 ( V_24 , V_28 ) :
return F_4 ( V_2 ) ;
case F_3 ( V_25 , V_23 ) :
case F_3 ( V_26 , V_23 ) :
case F_3 ( V_27 , V_23 ) :
case F_3 ( V_28 , V_23 ) :
return V_3 ;
case F_3 ( V_23 , V_23 ) :
case F_3 ( V_23 , V_25 ) :
case F_3 ( V_23 , V_26 ) :
case F_3 ( V_23 , V_27 ) :
case F_3 ( V_23 , V_28 ) :
return V_2 ;
case F_3 ( V_28 , V_25 ) :
case F_3 ( V_25 , V_28 ) :
F_5 ( V_29 ) ;
return F_6 () ;
case F_3 ( V_26 , V_28 ) :
case F_3 ( V_27 , V_28 ) :
case F_3 ( V_28 , V_26 ) :
case F_3 ( V_28 , V_27 ) :
case F_3 ( V_28 , V_28 ) :
return F_7 ( V_30 ^ V_31 ) ;
case F_3 ( V_25 , V_25 ) :
case F_3 ( V_25 , V_26 ) :
case F_3 ( V_25 , V_27 ) :
case F_3 ( V_26 , V_25 ) :
case F_3 ( V_27 , V_25 ) :
return F_8 ( V_30 ^ V_31 ) ;
case F_3 ( V_27 , V_27 ) :
V_32 ;
case F_3 ( V_26 , V_27 ) :
V_33 ;
break;
case F_3 ( V_27 , V_26 ) :
V_32 ;
break;
case F_3 ( V_26 , V_26 ) :
break;
}
assert ( V_34 & V_35 ) ;
assert ( V_36 & V_35 ) ;
V_4 = V_37 + V_38 ;
V_5 = V_30 ^ V_31 ;
V_34 <<= 32 - ( V_39 + 1 ) ;
V_36 <<= 32 - ( V_39 + 1 ) ;
V_7 = V_34 & 0xffff ;
V_8 = V_34 >> 16 ;
V_9 = V_36 & 0xffff ;
V_10 = V_36 >> 16 ;
V_11 = V_7 * V_9 ;
V_12 = V_8 * V_10 ;
V_13 = V_7 * V_10 ;
V_14 = V_11 + ( V_13 << 16 ) ;
V_12 += V_14 < V_11 ;
V_11 = V_14 ;
V_12 = V_12 + ( V_13 >> 16 ) ;
V_13 = V_8 * V_9 ;
V_14 = V_11 + ( V_13 << 16 ) ;
V_12 += V_14 < V_11 ;
V_11 = V_14 ;
V_12 = V_12 + ( V_13 >> 16 ) ;
V_6 = V_12 | ( V_11 != 0 ) ;
if ( ( int ) V_6 < 0 ) {
V_6 = ( V_6 >> ( 32 - ( V_39 + 1 + 3 ) ) ) |
( ( V_6 << ( V_39 + 1 + 3 ) ) != 0 ) ;
V_4 ++ ;
} else {
V_6 = ( V_6 >> ( 32 - ( V_39 + 1 + 3 + 1 ) ) ) |
( ( V_6 << ( V_39 + 1 + 3 + 1 ) ) != 0 ) ;
}
assert ( V_6 & ( V_35 << 3 ) ) ;
return F_9 ( V_5 , V_4 , V_6 ) ;
}
