T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
V_3 ;
V_4 ;
V_5 ;
V_6 ;
V_7 ;
V_8 ;
V_9 ;
switch ( F_2 ( V_10 , V_11 ) ) {
case F_2 ( V_12 , V_13 ) :
case F_2 ( V_13 , V_12 ) :
case F_2 ( V_12 , V_12 ) :
case F_2 ( V_14 , V_12 ) :
case F_2 ( V_15 , V_12 ) :
case F_2 ( V_16 , V_12 ) :
case F_2 ( V_17 , V_12 ) :
case F_2 ( V_12 , V_14 ) :
case F_2 ( V_12 , V_15 ) :
case F_2 ( V_12 , V_16 ) :
case F_2 ( V_12 , V_17 ) :
F_3 ( V_18 ) ;
return F_4 ( F_5 () , L_1 , V_1 , V_2 ) ;
case F_2 ( V_14 , V_13 ) :
case F_2 ( V_15 , V_13 ) :
case F_2 ( V_16 , V_13 ) :
case F_2 ( V_17 , V_13 ) :
return V_2 ;
case F_2 ( V_13 , V_13 ) :
case F_2 ( V_13 , V_14 ) :
case F_2 ( V_13 , V_15 ) :
case F_2 ( V_13 , V_16 ) :
case F_2 ( V_13 , V_17 ) :
return V_1 ;
case F_2 ( V_17 , V_14 ) :
case F_2 ( V_14 , V_17 ) :
F_3 ( V_18 ) ;
return F_6 ( F_5 () , L_1 , V_1 , V_2 ) ;
case F_2 ( V_15 , V_17 ) :
case F_2 ( V_16 , V_17 ) :
case F_2 ( V_17 , V_15 ) :
case F_2 ( V_17 , V_16 ) :
case F_2 ( V_17 , V_17 ) :
return F_7 ( V_19 ^ V_20 ) ;
case F_2 ( V_14 , V_14 ) :
case F_2 ( V_14 , V_15 ) :
case F_2 ( V_14 , V_16 ) :
case F_2 ( V_15 , V_14 ) :
case F_2 ( V_16 , V_14 ) :
return F_8 ( V_19 ^ V_20 ) ;
case F_2 ( V_16 , V_16 ) :
V_21 ;
case F_2 ( V_15 , V_16 ) :
V_22 ;
break;
case F_2 ( V_16 , V_15 ) :
V_21 ;
break;
case F_2 ( V_15 , V_15 ) :
break;
}
assert ( V_23 & V_24 ) ;
assert ( V_25 & V_24 ) ;
{
int V_26 = V_27 + V_28 ;
int V_29 = V_19 ^ V_20 ;
unsigned V_30 ;
V_23 <<= 32 - ( V_31 + 1 ) ;
V_25 <<= 32 - ( V_31 + 1 ) ;
{
unsigned short V_32 = V_23 & 0xffff ;
unsigned short V_33 = V_23 >> 16 ;
unsigned short V_34 = V_25 & 0xffff ;
unsigned short V_35 = V_25 >> 16 ;
unsigned V_36 ;
unsigned V_37 ;
V_36 = V_32 * V_34 ;
V_37 = V_33 * V_35 ;
{
unsigned V_38 = V_32 * V_35 ;
{
unsigned V_39 = V_36 + ( V_38 << 16 ) ;
V_37 += V_39 < V_36 ;
V_36 = V_39 ;
}
V_37 = V_37 + ( V_38 >> 16 ) ;
}
{
unsigned V_38 = V_33 * V_34 ;
{
unsigned V_39 = V_36 + ( V_38 << 16 ) ;
V_37 += V_39 < V_36 ;
V_36 = V_39 ;
}
V_37 = V_37 + ( V_38 >> 16 ) ;
}
V_30 = V_37 | ( V_36 != 0 ) ;
}
if ( ( int ) V_30 < 0 ) {
V_30 = ( V_30 >> ( 32 - ( V_31 + 1 + 3 ) ) ) |
( ( V_30 << ( V_31 + 1 + 3 ) ) != 0 ) ;
V_26 ++ ;
} else {
V_30 = ( V_30 >> ( 32 - ( V_31 + 1 + 3 + 1 ) ) ) |
( ( V_30 << ( V_31 + 1 + 3 + 1 ) ) != 0 ) ;
}
assert ( V_30 & ( V_24 << 3 ) ) ;
F_9 ( V_29 , V_26 , V_30 , L_1 , V_1 , V_2 ) ;
}
}
