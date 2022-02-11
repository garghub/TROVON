static union V_1 F_1 ( union V_1 V_2 , union V_1 V_3 ,
union V_1 V_4 , enum V_5 V_6 )
{
int V_7 ;
int V_8 ;
T_1 V_9 ;
unsigned V_10 ;
unsigned V_11 ;
unsigned V_12 ;
unsigned V_13 ;
T_1 V_14 ;
T_1 V_15 ;
T_1 V_16 ;
T_1 V_17 ;
int V_18 ;
V_19 ;
V_20 ;
V_21 ;
V_22 ;
V_23 ;
V_24 ;
V_25 ;
V_26 ;
V_27 ;
F_2 () ;
switch ( V_28 ) {
case V_29 :
F_3 ( V_30 ) ;
return F_4 ( V_2 ) ;
case V_31 :
V_32 ;
}
switch ( F_5 ( V_33 , V_34 ) ) {
case F_5 ( V_35 , V_29 ) :
case F_5 ( V_36 , V_29 ) :
case F_5 ( V_37 , V_29 ) :
case F_5 ( V_31 , V_29 ) :
case F_5 ( V_38 , V_29 ) :
return F_4 ( V_4 ) ;
case F_5 ( V_29 , V_29 ) :
case F_5 ( V_29 , V_35 ) :
case F_5 ( V_29 , V_36 ) :
case F_5 ( V_29 , V_37 ) :
case F_5 ( V_29 , V_31 ) :
case F_5 ( V_29 , V_38 ) :
return F_4 ( V_3 ) ;
case F_5 ( V_36 , V_35 ) :
case F_5 ( V_37 , V_35 ) :
case F_5 ( V_31 , V_35 ) :
case F_5 ( V_38 , V_35 ) :
return V_4 ;
case F_5 ( V_35 , V_35 ) :
case F_5 ( V_35 , V_36 ) :
case F_5 ( V_35 , V_37 ) :
case F_5 ( V_35 , V_31 ) :
case F_5 ( V_35 , V_38 ) :
return V_3 ;
case F_5 ( V_38 , V_36 ) :
case F_5 ( V_36 , V_38 ) :
if ( V_28 == V_35 )
return V_2 ;
F_3 ( V_30 ) ;
return F_6 () ;
case F_5 ( V_37 , V_38 ) :
case F_5 ( V_31 , V_38 ) :
case F_5 ( V_38 , V_37 ) :
case F_5 ( V_38 , V_31 ) :
case F_5 ( V_38 , V_38 ) :
if ( V_28 == V_35 )
return V_2 ;
return F_7 ( V_39 ^ V_40 ) ;
case F_5 ( V_36 , V_36 ) :
case F_5 ( V_36 , V_37 ) :
case F_5 ( V_36 , V_31 ) :
case F_5 ( V_37 , V_36 ) :
case F_5 ( V_31 , V_36 ) :
if ( V_28 == V_38 )
return F_7 ( V_41 ) ;
return V_2 ;
case F_5 ( V_31 , V_31 ) :
V_42 ;
case F_5 ( V_37 , V_31 ) :
if ( V_28 == V_35 )
return V_2 ;
else if ( V_28 == V_38 )
return F_7 ( V_41 ) ;
V_43 ;
break;
case F_5 ( V_31 , V_37 ) :
if ( V_28 == V_35 )
return V_2 ;
else if ( V_28 == V_38 )
return F_7 ( V_41 ) ;
V_42 ;
break;
case F_5 ( V_37 , V_37 ) :
if ( V_28 == V_35 )
return V_2 ;
else if ( V_28 == V_38 )
return F_7 ( V_41 ) ;
}
assert ( V_44 & V_45 ) ;
assert ( V_46 & V_45 ) ;
V_7 = V_47 + V_48 ;
V_8 = V_39 ^ V_40 ;
if ( V_6 & V_49 )
V_8 ^= 1 ;
V_44 <<= 64 - ( V_50 + 1 ) ;
V_46 <<= 64 - ( V_50 + 1 ) ;
#define F_8 ( V_3 , V_4 ) ((u64)(x) * (u64)y)
V_10 = V_44 ;
V_11 = V_44 >> 32 ;
V_12 = V_46 ;
V_13 = V_46 >> 32 ;
V_14 = F_8 ( V_10 , V_12 ) ;
V_15 = F_8 ( V_11 , V_13 ) ;
V_16 = F_8 ( V_10 , V_13 ) ;
V_17 = V_14 + ( V_16 << 32 ) ;
V_15 += V_17 < V_14 ;
V_14 = V_17 ;
V_15 = V_15 + ( V_16 >> 32 ) ;
V_16 = F_8 ( V_11 , V_12 ) ;
V_17 = V_14 + ( V_16 << 32 ) ;
V_15 += V_17 < V_14 ;
V_14 = V_17 ;
V_15 = V_15 + ( V_16 >> 32 ) ;
V_9 = V_15 | ( V_14 != 0 ) ;
if ( ( V_51 ) V_9 < 0 ) {
V_9 = ( V_9 >> ( 64 - ( V_50 + 1 + 3 ) ) ) |
( ( V_9 << ( V_50 + 1 + 3 ) ) != 0 ) ;
V_7 ++ ;
} else {
V_9 = ( V_9 >> ( 64 - ( V_50 + 1 + 3 + 1 ) ) ) |
( ( V_9 << ( V_50 + 1 + 3 + 1 ) ) != 0 ) ;
}
assert ( V_9 & ( V_45 << 3 ) ) ;
if ( V_28 == V_36 )
return F_9 ( V_8 , V_7 , V_9 ) ;
assert ( V_52 & V_45 ) ;
V_52 <<= 3 ;
if ( V_53 > V_7 ) {
V_18 = V_53 - V_7 ;
V_9 = F_10 ( V_9 , V_18 ) ;
V_7 += V_18 ;
} else if ( V_7 > V_53 ) {
V_18 = V_7 - V_53 ;
V_52 = F_10 ( V_52 , V_18 ) ;
V_53 += V_18 ;
}
assert ( V_53 == V_7 ) ;
assert ( V_53 <= V_54 ) ;
if ( V_41 == V_8 ) {
V_52 = V_52 + V_9 ;
if ( V_52 >> ( V_50 + 1 + 3 ) ) {
V_52 = F_11 ( V_52 ) ;
V_53 ++ ;
}
} else {
if ( V_52 >= V_9 ) {
V_52 = V_52 - V_9 ;
} else {
V_52 = V_9 - V_52 ;
V_41 = V_8 ;
}
if ( V_52 == 0 )
return F_12 ( V_55 . V_9 == V_56 ) ;
while ( ( V_52 >> ( V_50 + 3 ) ) == 0 ) {
V_52 <<= 1 ;
V_53 -- ;
}
}
return F_9 ( V_41 , V_53 , V_52 ) ;
}
union V_1 F_13 ( union V_1 V_2 , union V_1 V_3 ,
union V_1 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , 0 ) ;
}
union V_1 F_14 ( union V_1 V_2 , union V_1 V_3 ,
union V_1 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , V_49 ) ;
}
