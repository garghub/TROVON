union V_1 F_1 ( union V_1 V_2 , union V_1 V_3 )
{
V_4 ;
V_5 ;
V_6 ;
V_7 ;
V_8 ;
V_9 ;
F_2 () ;
switch ( F_3 ( V_10 , V_11 ) ) {
case F_3 ( V_12 , V_13 ) :
case F_3 ( V_14 , V_13 ) :
case F_3 ( V_15 , V_13 ) :
case F_3 ( V_16 , V_13 ) :
case F_3 ( V_17 , V_13 ) :
return F_4 ( V_3 ) ;
case F_3 ( V_13 , V_13 ) :
case F_3 ( V_13 , V_12 ) :
case F_3 ( V_13 , V_14 ) :
case F_3 ( V_13 , V_15 ) :
case F_3 ( V_13 , V_16 ) :
case F_3 ( V_13 , V_17 ) :
return F_4 ( V_2 ) ;
case F_3 ( V_14 , V_12 ) :
case F_3 ( V_15 , V_12 ) :
case F_3 ( V_16 , V_12 ) :
case F_3 ( V_17 , V_12 ) :
return V_2 ;
case F_3 ( V_12 , V_12 ) :
case F_3 ( V_12 , V_14 ) :
case F_3 ( V_12 , V_15 ) :
case F_3 ( V_12 , V_16 ) :
case F_3 ( V_12 , V_17 ) :
return V_3 ;
case F_3 ( V_17 , V_14 ) :
case F_3 ( V_17 , V_15 ) :
case F_3 ( V_17 , V_16 ) :
case F_3 ( V_15 , V_14 ) :
case F_3 ( V_16 , V_14 ) :
return V_18 ? V_2 : V_3 ;
case F_3 ( V_17 , V_17 ) :
case F_3 ( V_15 , V_17 ) :
case F_3 ( V_16 , V_17 ) :
case F_3 ( V_14 , V_17 ) :
case F_3 ( V_14 , V_15 ) :
case F_3 ( V_14 , V_16 ) :
return V_19 ? V_3 : V_2 ;
case F_3 ( V_14 , V_14 ) :
if ( V_18 == V_19 )
return V_2 ;
return F_5 ( 1 ) ;
case F_3 ( V_16 , V_16 ) :
V_20 ;
case F_3 ( V_15 , V_16 ) :
V_21 ;
break;
case F_3 ( V_16 , V_15 ) :
V_20 ;
}
assert ( V_22 & V_23 ) ;
assert ( V_24 & V_23 ) ;
if ( V_18 > V_19 )
return V_2 ;
else if ( V_18 < V_19 )
return V_3 ;
if ( V_25 > V_26 )
return V_3 ;
else if ( V_25 < V_26 )
return V_2 ;
if ( V_22 <= V_24 )
return V_2 ;
return V_3 ;
}
union V_1 F_6 ( union V_1 V_2 , union V_1 V_3 )
{
V_4 ;
V_5 ;
V_6 ;
V_7 ;
V_8 ;
V_9 ;
F_2 () ;
switch ( F_3 ( V_10 , V_11 ) ) {
case F_3 ( V_12 , V_13 ) :
case F_3 ( V_14 , V_13 ) :
case F_3 ( V_15 , V_13 ) :
case F_3 ( V_16 , V_13 ) :
case F_3 ( V_17 , V_13 ) :
return F_4 ( V_3 ) ;
case F_3 ( V_13 , V_13 ) :
case F_3 ( V_13 , V_12 ) :
case F_3 ( V_13 , V_14 ) :
case F_3 ( V_13 , V_15 ) :
case F_3 ( V_13 , V_16 ) :
case F_3 ( V_13 , V_17 ) :
return F_4 ( V_2 ) ;
case F_3 ( V_14 , V_12 ) :
case F_3 ( V_15 , V_12 ) :
case F_3 ( V_16 , V_12 ) :
case F_3 ( V_17 , V_12 ) :
return V_2 ;
case F_3 ( V_12 , V_12 ) :
case F_3 ( V_12 , V_14 ) :
case F_3 ( V_12 , V_15 ) :
case F_3 ( V_12 , V_16 ) :
case F_3 ( V_12 , V_17 ) :
return V_3 ;
case F_3 ( V_17 , V_14 ) :
case F_3 ( V_17 , V_15 ) :
case F_3 ( V_17 , V_16 ) :
case F_3 ( V_15 , V_14 ) :
case F_3 ( V_16 , V_14 ) :
return V_2 ;
case F_3 ( V_17 , V_17 ) :
case F_3 ( V_15 , V_17 ) :
case F_3 ( V_16 , V_17 ) :
case F_3 ( V_14 , V_17 ) :
case F_3 ( V_14 , V_15 ) :
case F_3 ( V_14 , V_16 ) :
return V_3 ;
case F_3 ( V_14 , V_14 ) :
if ( V_18 == V_19 )
return V_2 ;
return F_5 ( 1 ) ;
case F_3 ( V_16 , V_16 ) :
V_20 ;
case F_3 ( V_15 , V_16 ) :
V_21 ;
break;
case F_3 ( V_16 , V_15 ) :
V_20 ;
}
assert ( V_22 & V_23 ) ;
assert ( V_24 & V_23 ) ;
if ( V_25 > V_26 )
return V_3 ;
else if ( V_25 < V_26 )
return V_2 ;
if ( V_22 <= V_24 )
return V_2 ;
return V_3 ;
}
