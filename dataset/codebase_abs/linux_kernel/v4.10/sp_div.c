union V_1 F_1 ( union V_1 V_2 , union V_1 V_3 )
{
unsigned V_4 ;
int V_5 ;
unsigned V_6 ;
V_7 ;
V_8 ;
V_9 ;
V_10 ;
F_2 () ;
V_11 ;
V_12 ;
switch ( F_3 ( V_13 , V_14 ) ) {
case F_3 ( V_15 , V_16 ) :
case F_3 ( V_17 , V_16 ) :
case F_3 ( V_18 , V_16 ) :
case F_3 ( V_19 , V_16 ) :
case F_3 ( V_20 , V_16 ) :
return F_4 ( V_3 ) ;
case F_3 ( V_16 , V_16 ) :
case F_3 ( V_16 , V_15 ) :
case F_3 ( V_16 , V_17 ) :
case F_3 ( V_16 , V_18 ) :
case F_3 ( V_16 , V_19 ) :
case F_3 ( V_16 , V_20 ) :
return F_4 ( V_2 ) ;
case F_3 ( V_17 , V_15 ) :
case F_3 ( V_18 , V_15 ) :
case F_3 ( V_19 , V_15 ) :
case F_3 ( V_20 , V_15 ) :
return V_3 ;
case F_3 ( V_15 , V_15 ) :
case F_3 ( V_15 , V_17 ) :
case F_3 ( V_15 , V_18 ) :
case F_3 ( V_15 , V_19 ) :
case F_3 ( V_15 , V_20 ) :
return V_2 ;
case F_3 ( V_20 , V_20 ) :
F_5 ( V_21 ) ;
return F_6 () ;
case F_3 ( V_18 , V_20 ) :
case F_3 ( V_17 , V_20 ) :
case F_3 ( V_19 , V_20 ) :
return F_7 ( V_22 ^ V_23 ) ;
case F_3 ( V_20 , V_17 ) :
case F_3 ( V_20 , V_18 ) :
case F_3 ( V_20 , V_19 ) :
return F_8 ( V_22 ^ V_23 ) ;
case F_3 ( V_17 , V_17 ) :
F_5 ( V_21 ) ;
return F_6 () ;
case F_3 ( V_18 , V_17 ) :
case F_3 ( V_19 , V_17 ) :
F_5 ( V_24 ) ;
return F_8 ( V_22 ^ V_23 ) ;
case F_3 ( V_17 , V_18 ) :
case F_3 ( V_17 , V_19 ) :
return F_7 ( V_22 == V_23 ? 0 : 1 ) ;
case F_3 ( V_19 , V_19 ) :
V_25 ;
case F_3 ( V_18 , V_19 ) :
V_26 ;
break;
case F_3 ( V_19 , V_18 ) :
V_25 ;
break;
case F_3 ( V_18 , V_18 ) :
break;
}
assert ( V_27 & V_28 ) ;
assert ( V_29 & V_28 ) ;
V_27 <<= 3 ;
V_29 <<= 3 ;
V_4 = 0 ;
V_5 = V_30 - V_31 ;
for ( V_6 = F_9 ( V_32 + 2 ) ; V_6 ; V_6 >>= 1 ) {
if ( V_27 >= V_29 ) {
V_27 -= V_29 ;
V_4 |= V_6 ;
if ( V_27 == 0 )
break;
}
V_27 <<= 1 ;
}
V_4 <<= 1 ;
if ( V_27 )
V_4 |= 1 ;
assert ( V_4 ) ;
while ( ( V_4 >> ( V_32 + 3 ) ) == 0 ) {
V_4 <<= 1 ;
V_5 -- ;
}
return F_10 ( V_22 == V_23 ? 0 : 1 , V_5 , V_4 ) ;
}
