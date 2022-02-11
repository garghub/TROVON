union V_1 F_1 ( union V_1 V_2 , union V_1 V_3 ,
union V_1 V_4 )
{
int V_5 ;
int V_6 ;
unsigned V_7 ;
unsigned short V_8 ;
unsigned short V_9 ;
unsigned short V_10 ;
unsigned short V_11 ;
unsigned V_12 ;
unsigned V_13 ;
unsigned V_14 ;
unsigned V_15 ;
int V_16 ;
V_17 ;
V_18 ;
T_1 V_19 ; int V_20 ; int T_2 V_21 ; int V_22 ;
V_23 ;
V_24 ;
F_2 (z, zc, zs, ze, zm)
V_25 ;
V_26 ;
F_3 ( V_2 , V_22 , T_2 , V_20 , V_19 ) ;
F_4 () ;
switch ( V_22 ) {
case V_27 :
F_5 ( V_28 ) ;
return F_6 ( V_2 ) ;
case V_29 :
F_7 ( V_19 , V_20 ) ;
}
switch ( F_8 ( V_30 , V_31 ) ) {
case F_8 ( V_32 , V_27 ) :
case F_8 ( V_33 , V_27 ) :
case F_8 ( V_34 , V_27 ) :
case F_8 ( V_29 , V_27 ) :
case F_8 ( V_35 , V_27 ) :
return F_6 ( V_4 ) ;
case F_8 ( V_27 , V_27 ) :
case F_8 ( V_27 , V_32 ) :
case F_8 ( V_27 , V_33 ) :
case F_8 ( V_27 , V_34 ) :
case F_8 ( V_27 , V_29 ) :
case F_8 ( V_27 , V_35 ) :
return F_6 ( V_3 ) ;
case F_8 ( V_33 , V_32 ) :
case F_8 ( V_34 , V_32 ) :
case F_8 ( V_29 , V_32 ) :
case F_8 ( V_35 , V_32 ) :
return V_4 ;
case F_8 ( V_32 , V_32 ) :
case F_8 ( V_32 , V_33 ) :
case F_8 ( V_32 , V_34 ) :
case F_8 ( V_32 , V_29 ) :
case F_8 ( V_32 , V_35 ) :
return V_3 ;
case F_8 ( V_35 , V_33 ) :
case F_8 ( V_33 , V_35 ) :
if ( V_22 == V_32 )
return V_2 ;
F_5 ( V_28 ) ;
return F_9 () ;
case F_8 ( V_34 , V_35 ) :
case F_8 ( V_29 , V_35 ) :
case F_8 ( V_35 , V_34 ) :
case F_8 ( V_35 , V_29 ) :
case F_8 ( V_35 , V_35 ) :
if ( V_22 == V_32 )
return V_2 ;
return F_10 ( V_36 ^ V_37 ) ;
case F_8 ( V_33 , V_33 ) :
case F_8 ( V_33 , V_34 ) :
case F_8 ( V_33 , V_29 ) :
case F_8 ( V_34 , V_33 ) :
case F_8 ( V_29 , V_33 ) :
if ( V_22 == V_35 )
return F_10 ( T_2 ) ;
return V_2 ;
case F_8 ( V_29 , V_29 ) :
V_38 ;
case F_8 ( V_34 , V_29 ) :
if ( V_22 == V_32 )
return V_2 ;
else if ( V_22 == V_35 )
return F_10 ( T_2 ) ;
V_39 ;
break;
case F_8 ( V_29 , V_34 ) :
if ( V_22 == V_32 )
return V_2 ;
else if ( V_22 == V_35 )
return F_10 ( T_2 ) ;
V_38 ;
break;
case F_8 ( V_34 , V_34 ) :
if ( V_22 == V_32 )
return V_2 ;
else if ( V_22 == V_35 )
return F_10 ( T_2 ) ;
}
assert ( V_40 & V_41 ) ;
assert ( V_42 & V_41 ) ;
V_5 = V_43 + V_44 ;
V_6 = V_36 ^ V_37 ;
V_40 <<= 32 - ( V_45 + 1 ) ;
V_42 <<= 32 - ( V_45 + 1 ) ;
V_8 = V_40 & 0xffff ;
V_9 = V_40 >> 16 ;
V_10 = V_42 & 0xffff ;
V_11 = V_42 >> 16 ;
V_12 = V_8 * V_10 ;
V_13 = V_9 * V_11 ;
V_14 = V_8 * V_11 ;
V_15 = V_12 + ( V_14 << 16 ) ;
V_13 += V_15 < V_12 ;
V_12 = V_15 ;
V_13 = V_13 + ( V_14 >> 16 ) ;
V_14 = V_9 * V_10 ;
V_15 = V_12 + ( V_14 << 16 ) ;
V_13 += V_15 < V_12 ;
V_12 = V_15 ;
V_13 = V_13 + ( V_14 >> 16 ) ;
V_7 = V_13 | ( V_12 != 0 ) ;
if ( ( int ) V_7 < 0 ) {
V_7 = ( V_7 >> ( 32 - ( V_45 + 1 + 3 ) ) ) |
( ( V_7 << ( V_45 + 1 + 3 ) ) != 0 ) ;
V_5 ++ ;
} else {
V_7 = ( V_7 >> ( 32 - ( V_45 + 1 + 3 + 1 ) ) ) |
( ( V_7 << ( V_45 + 1 + 3 + 1 ) ) != 0 ) ;
}
assert ( V_7 & ( V_41 << 3 ) ) ;
assert ( V_19 & V_41 ) ;
V_19 <<= 3 ;
if ( V_20 > V_5 ) {
V_16 = V_20 - V_5 ;
F_11 ( V_16 ) ;
} else if ( V_5 > V_20 ) {
V_16 = V_5 - V_20 ;
F_11 ( V_16 ) ;
}
assert ( V_20 == V_5 ) ;
assert ( V_20 <= V_46 ) ;
if ( T_2 == V_6 ) {
V_19 = V_19 + V_7 ;
if ( V_19 >> ( V_45 + 1 + 3 ) ) {
F_12 () ;
}
} else {
if ( V_19 >= V_7 ) {
V_19 = V_19 - V_7 ;
} else {
V_19 = V_7 - V_19 ;
T_2 = V_6 ;
}
if ( V_19 == 0 )
return F_13 ( V_47 . V_7 == V_48 ) ;
while ( ( V_19 >> ( V_49 + 3 ) ) == 0 ) {
V_19 <<= 1 ;
V_20 -- ;
}
}
return F_14 ( T_2 , V_20 , V_19 ) ;
}
