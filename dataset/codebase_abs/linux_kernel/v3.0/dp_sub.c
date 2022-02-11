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
case F_2 ( V_17 , V_17 ) :
if ( V_19 != V_20 )
return V_1 ;
F_3 ( V_18 ) ;
return F_6 ( F_5 () , L_1 , V_1 , V_2 ) ;
case F_2 ( V_14 , V_17 ) :
case F_2 ( V_16 , V_17 ) :
case F_2 ( V_15 , V_17 ) :
return F_7 ( V_20 ^ 1 ) ;
case F_2 ( V_17 , V_14 ) :
case F_2 ( V_17 , V_15 ) :
case F_2 ( V_17 , V_16 ) :
return V_1 ;
case F_2 ( V_14 , V_14 ) :
if ( V_19 != V_20 )
return V_1 ;
else
return F_8 ( V_21 . V_22 ==
V_23 ) ;
case F_2 ( V_15 , V_14 ) :
case F_2 ( V_16 , V_14 ) :
return V_1 ;
case F_2 ( V_14 , V_15 ) :
case F_2 ( V_14 , V_16 ) :
F_9 ( V_2 ) ^= 1 ;
return V_2 ;
case F_2 ( V_16 , V_16 ) :
V_24 ;
case F_2 ( V_15 , V_16 ) :
V_25 ;
break;
case F_2 ( V_16 , V_15 ) :
V_24 ;
break;
case F_2 ( V_15 , V_15 ) :
break;
}
V_20 ^= 1 ;
assert ( V_26 & V_27 ) ;
assert ( V_28 & V_27 ) ;
V_26 <<= 3 ;
V_28 <<= 3 ;
if ( V_29 > V_30 ) {
int V_31 = V_29 - V_30 ;
V_28 = F_10 ( V_28 , V_31 ) ;
V_30 += V_31 ;
} else if ( V_30 > V_29 ) {
int V_31 = V_30 - V_29 ;
V_26 = F_10 ( V_26 , V_31 ) ;
V_29 += V_31 ;
}
assert ( V_29 == V_30 ) ;
assert ( V_29 <= V_32 ) ;
if ( V_19 == V_20 ) {
V_26 = V_26 + V_28 ;
V_29 = V_29 ;
V_19 = V_19 ;
if ( V_26 >> ( V_33 + 1 + 3 ) ) {
V_26 = F_11 ( V_26 ) ;
V_29 ++ ;
}
} else {
if ( V_26 >= V_28 ) {
V_26 = V_26 - V_28 ;
V_29 = V_29 ;
V_19 = V_19 ;
} else {
V_26 = V_28 - V_26 ;
V_29 = V_29 ;
V_19 = V_20 ;
}
if ( V_26 == 0 ) {
if ( V_21 . V_22 == V_23 )
return F_8 ( 1 ) ;
else
return F_8 ( 0 ) ;
}
while ( ( V_26 >> ( V_33 + 3 ) ) == 0 ) {
V_26 <<= 1 ;
V_29 -- ;
}
}
F_12 ( V_19 , V_29 , V_26 , L_1 , V_1 , V_2 ) ;
}
