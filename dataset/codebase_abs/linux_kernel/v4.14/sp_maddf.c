static union V_1 F_1 ( union V_1 V_2 , union V_1 V_3 ,
union V_1 V_4 , enum V_5 V_6 )
{
int V_7 ;
int V_8 ;
unsigned V_9 ;
T_1 V_10 ;
T_1 V_11 ;
int V_12 ;
V_13 ;
V_14 ;
V_15 ;
V_16 ;
V_17 ;
V_18 ;
V_19 ;
V_20 ;
V_21 ;
F_2 () ;
if ( V_22 == V_23 )
return F_3 ( V_2 ) ;
if ( V_24 == V_23 )
return F_3 ( V_3 ) ;
if ( V_25 == V_23 )
return F_3 ( V_4 ) ;
if ( V_22 == V_26 )
return V_2 ;
if ( V_24 == V_26 )
return V_3 ;
if ( V_25 == V_26 )
return V_4 ;
if ( V_22 == V_27 )
V_28 ;
switch ( F_4 ( V_24 , V_25 ) ) {
case F_4 ( V_29 , V_30 ) :
case F_4 ( V_30 , V_29 ) :
F_5 ( V_31 ) ;
return F_6 () ;
case F_4 ( V_32 , V_29 ) :
case F_4 ( V_27 , V_29 ) :
case F_4 ( V_29 , V_32 ) :
case F_4 ( V_29 , V_27 ) :
case F_4 ( V_29 , V_29 ) :
if ( ( V_22 == V_29 ) &&
( ( ! ( V_6 & V_33 ) && ( V_34 != ( V_35 ^ V_36 ) ) ) ||
( ( V_6 & V_33 ) && ( V_34 == ( V_35 ^ V_36 ) ) ) ) ) {
F_5 ( V_31 ) ;
return F_6 () ;
}
if ( V_6 & V_33 )
return F_7 ( 1 ^ ( V_35 ^ V_36 ) ) ;
else
return F_7 ( V_35 ^ V_36 ) ;
case F_4 ( V_30 , V_30 ) :
case F_4 ( V_30 , V_32 ) :
case F_4 ( V_30 , V_27 ) :
case F_4 ( V_32 , V_30 ) :
case F_4 ( V_27 , V_30 ) :
if ( V_22 == V_29 )
return F_7 ( V_34 ) ;
if ( V_22 == V_30 ) {
if ( ( ! ( V_6 & V_33 )
&& ( V_34 == ( V_35 ^ V_36 ) ) ) ||
( ( V_6 & V_33 )
&& ( V_34 != ( V_35 ^ V_36 ) ) ) )
return V_2 ;
return F_8 ( V_37 . V_9 == V_38 ) ;
}
return V_2 ;
case F_4 ( V_27 , V_27 ) :
V_39 ;
case F_4 ( V_32 , V_27 ) :
if ( V_22 == V_29 )
return F_7 ( V_34 ) ;
V_40 ;
break;
case F_4 ( V_27 , V_32 ) :
if ( V_22 == V_29 )
return F_7 ( V_34 ) ;
V_39 ;
break;
case F_4 ( V_32 , V_32 ) :
if ( V_22 == V_29 )
return F_7 ( V_34 ) ;
}
assert ( V_41 & V_42 ) ;
assert ( V_43 & V_42 ) ;
V_7 = V_44 + V_45 ;
V_8 = V_35 ^ V_36 ;
if ( V_6 & V_33 )
V_8 ^= 1 ;
V_10 = ( T_1 ) V_41 * V_43 ;
V_10 = V_10 << 16 ;
if ( ( V_46 ) V_10 < 0 ) {
V_10 = V_10 >> 1 ;
V_7 ++ ;
}
assert ( V_10 & ( 1 << 62 ) ) ;
if ( V_22 == V_30 ) {
V_9 = F_9 ( V_10 , ( 62 - 26 ) ) ;
return F_10 ( V_8 , V_7 , V_9 ) ;
}
V_11 = ( T_1 ) V_47 << ( 62 - 23 ) ;
assert ( V_11 & ( 1 << 62 ) ) ;
if ( V_48 > V_7 ) {
V_12 = V_48 - V_7 ;
V_10 = F_9 ( V_10 , V_12 ) ;
V_7 += V_12 ;
} else if ( V_7 > V_48 ) {
V_12 = V_7 - V_48 ;
V_11 = F_9 ( V_11 , V_12 ) ;
V_48 += V_12 ;
}
assert ( V_48 == V_7 ) ;
assert ( V_48 <= V_49 ) ;
if ( V_34 == V_8 ) {
V_11 = V_11 + V_10 ;
if ( ( V_46 ) V_11 < 0 ) {
V_11 = F_11 ( V_11 ) ;
V_48 ++ ;
}
} else {
if ( V_11 >= V_10 ) {
V_11 = V_11 - V_10 ;
} else {
V_11 = V_10 - V_11 ;
V_34 = V_8 ;
}
if ( V_11 == 0 )
return F_8 ( V_37 . V_9 == V_38 ) ;
while ( ( V_11 >> 62 ) == 0 ) {
V_11 <<= 1 ;
V_48 -- ;
}
}
V_47 = F_9 ( V_11 , ( 62 - 26 ) ) ;
return F_10 ( V_34 , V_48 , V_47 ) ;
}
union V_1 F_12 ( union V_1 V_2 , union V_1 V_3 ,
union V_1 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , 0 ) ;
}
union V_1 F_13 ( union V_1 V_2 , union V_1 V_3 ,
union V_1 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , V_33 ) ;
}
