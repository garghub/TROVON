union V_1 F_1 ( union V_1 V_2 , union V_1 V_3 )
{
int V_4 ;
V_5 ;
V_6 ;
V_7 ;
V_8 ;
F_2 () ;
V_9 ;
V_10 ;
switch ( F_3 ( V_11 , V_12 ) ) {
case F_3 ( V_13 , V_14 ) :
case F_3 ( V_15 , V_14 ) :
case F_3 ( V_16 , V_14 ) :
case F_3 ( V_17 , V_14 ) :
case F_3 ( V_18 , V_14 ) :
return F_4 ( V_3 ) ;
case F_3 ( V_14 , V_14 ) :
case F_3 ( V_14 , V_13 ) :
case F_3 ( V_14 , V_15 ) :
case F_3 ( V_14 , V_16 ) :
case F_3 ( V_14 , V_17 ) :
case F_3 ( V_14 , V_18 ) :
return F_4 ( V_2 ) ;
case F_3 ( V_15 , V_13 ) :
case F_3 ( V_16 , V_13 ) :
case F_3 ( V_17 , V_13 ) :
case F_3 ( V_18 , V_13 ) :
return V_3 ;
case F_3 ( V_13 , V_13 ) :
case F_3 ( V_13 , V_15 ) :
case F_3 ( V_13 , V_16 ) :
case F_3 ( V_13 , V_17 ) :
case F_3 ( V_13 , V_18 ) :
return V_2 ;
case F_3 ( V_18 , V_18 ) :
if ( V_19 == V_20 )
return V_2 ;
F_5 ( V_21 ) ;
return F_6 () ;
case F_3 ( V_16 , V_18 ) :
case F_3 ( V_15 , V_18 ) :
case F_3 ( V_17 , V_18 ) :
return V_3 ;
case F_3 ( V_18 , V_15 ) :
case F_3 ( V_18 , V_16 ) :
case F_3 ( V_18 , V_17 ) :
return V_2 ;
case F_3 ( V_15 , V_15 ) :
if ( V_19 == V_20 )
return V_2 ;
else
return F_7 ( V_22 . V_23 == V_24 ) ;
case F_3 ( V_16 , V_15 ) :
case F_3 ( V_17 , V_15 ) :
return V_2 ;
case F_3 ( V_15 , V_16 ) :
case F_3 ( V_15 , V_17 ) :
return V_3 ;
case F_3 ( V_17 , V_17 ) :
V_25 ;
case F_3 ( V_16 , V_17 ) :
V_26 ;
break;
case F_3 ( V_17 , V_16 ) :
V_25 ;
break;
case F_3 ( V_16 , V_16 ) :
break;
}
assert ( V_27 & V_28 ) ;
assert ( V_29 & V_28 ) ;
V_27 <<= 3 ;
V_29 <<= 3 ;
if ( V_30 > V_31 ) {
V_4 = V_30 - V_31 ;
F_8 ( V_4 ) ;
} else if ( V_31 > V_30 ) {
V_4 = V_31 - V_30 ;
F_9 ( V_4 ) ;
}
assert ( V_30 == V_31 ) ;
assert ( V_30 <= V_32 ) ;
if ( V_19 == V_20 ) {
V_27 = V_27 + V_29 ;
if ( V_27 >> ( V_33 + 1 + 3 ) ) {
F_10 () ;
}
} else {
if ( V_27 >= V_29 ) {
V_27 = V_27 - V_29 ;
} else {
V_27 = V_29 - V_27 ;
V_19 = V_20 ;
}
if ( V_27 == 0 )
return F_7 ( V_22 . V_23 == V_24 ) ;
while ( ( V_27 >> ( V_33 + 3 ) ) == 0 ) {
V_27 <<= 1 ;
V_30 -- ;
}
}
return F_11 ( V_19 , V_30 , V_27 ) ;
}
