union V_1 F_1 ( union V_1 V_2 , union V_1 V_3 ,
union V_1 V_4 )
{
int V_5 ;
int V_6 ;
T_1 V_7 ;
unsigned V_8 ;
unsigned V_9 ;
unsigned V_10 ;
unsigned V_11 ;
T_1 V_12 ;
T_1 V_13 ;
T_1 V_14 ;
T_1 V_15 ;
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
V_40 <<= 64 - ( V_45 + 1 ) ;
V_42 <<= 64 - ( V_45 + 1 ) ;
#define F_11 ( V_3 , V_4 ) ((u64)(x) * (u64)y)
V_8 = V_40 ;
V_9 = V_40 >> 32 ;
V_10 = V_42 ;
V_11 = V_42 >> 32 ;
V_12 = F_11 ( V_8 , V_10 ) ;
V_13 = F_11 ( V_9 , V_11 ) ;
V_14 = F_11 ( V_8 , V_11 ) ;
V_15 = V_12 + ( V_14 << 32 ) ;
V_13 += V_15 < V_12 ;
V_12 = V_15 ;
V_13 = V_13 + ( V_14 >> 32 ) ;
V_14 = F_11 ( V_9 , V_10 ) ;
V_15 = V_12 + ( V_14 << 32 ) ;
V_13 += V_15 < V_12 ;
V_12 = V_15 ;
V_13 = V_13 + ( V_14 >> 32 ) ;
V_7 = V_13 | ( V_12 != 0 ) ;
if ( ( V_46 ) V_7 < 0 ) {
V_7 = ( V_7 >> ( 64 - ( V_45 + 1 + 3 ) ) ) |
( ( V_7 << ( V_45 + 1 + 3 ) ) != 0 ) ;
V_5 ++ ;
} else {
V_7 = ( V_7 >> ( 64 - ( V_45 + 1 + 3 + 1 ) ) ) |
( ( V_7 << ( V_45 + 1 + 3 + 1 ) ) != 0 ) ;
}
assert ( V_7 & ( V_41 << 3 ) ) ;
V_6 ^= 1 ;
assert ( V_19 & V_41 ) ;
V_19 <<= 3 ;
if ( V_20 > V_5 ) {
V_16 = V_20 - V_5 ;
V_7 = F_12 ( V_7 , V_16 ) ;
V_5 += V_16 ;
} else if ( V_5 > V_20 ) {
V_16 = V_5 - V_20 ;
V_19 = F_12 ( V_19 , V_16 ) ;
V_20 += V_16 ;
}
assert ( V_20 == V_5 ) ;
assert ( V_20 <= V_47 ) ;
if ( T_2 == V_6 ) {
V_19 = V_19 + V_7 ;
if ( V_19 >> ( V_45 + 1 + 3 ) ) {
V_19 = F_13 ( V_19 ) ;
V_20 ++ ;
}
} else {
if ( V_19 >= V_7 ) {
V_19 = V_19 - V_7 ;
} else {
V_19 = V_7 - V_19 ;
T_2 = V_6 ;
}
if ( V_19 == 0 )
return F_14 ( V_48 . V_7 == V_49 ) ;
while ( ( V_19 >> ( V_45 + 3 ) ) == 0 ) {
V_19 <<= 1 ;
V_20 -- ;
}
}
return F_15 ( T_2 , V_20 , V_19 ) ;
}
