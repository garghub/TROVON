int F_1 ( struct V_1 * V_2 , unsigned int V_3 , int V_4 )
{
int V_5 , V_6 ;
F_2 ( V_2 , V_3 , & V_6 ) ;
V_6 = ( V_6 >> V_4 ) & 0x7 ;
switch ( V_6 ) {
case 0 :
case 1 :
case 2 :
case 3 :
V_5 = V_6 + 1 ;
break;
case 4 :
V_5 = 6 ;
break;
case 5 :
V_5 = 8 ;
break;
case 6 :
V_5 = 12 ;
break;
case 7 :
V_5 = 16 ;
break;
default:
V_5 = - V_7 ;
break;
}
return V_5 ;
}
int F_3 ( int V_8 )
{
int div [] = { 2 , 3 , 4 , 6 , 8 , 12 } ;
int V_9 ;
if ( V_8 < 1000000 * div [ 0 ] ) {
F_4 ( L_1 , V_8 ) ;
return - V_7 ;
}
for ( V_9 = 0 ; V_9 < F_5 ( div ) ; V_9 ++ ) {
if ( ( div [ V_9 ] % 3 ) == 0 )
continue;
if ( 3072000 * div [ V_9 ] >= V_8 )
return V_9 ;
}
F_4 ( L_2 , V_8 ) ;
return - V_7 ;
}
int F_6 ( const unsigned int V_10 ,
const unsigned int V_11 , struct V_12 * V_13 )
{
int V_14 = V_15 , V_16 = V_17 ;
int V_9 , V_18 , V_19 , V_20 , V_21 , V_22 , V_23 ;
int V_24 = 0 , V_25 = 0 , V_26 = 0 ;
int V_27 = abs ( V_11 - V_10 ) ;
bool V_28 = false ;
if ( V_29 < V_10 || V_30 > V_10 )
return - V_7 ;
for ( V_9 = 0 ; V_9 < F_5 ( V_31 ) ; V_9 ++ ) {
if ( V_10 == V_31 [ V_9 ] . V_32 &&
V_11 == V_31 [ V_9 ] . V_21 ) {
V_18 = V_31 [ V_9 ] . V_18 ;
V_25 = V_31 [ V_9 ] . V_25 ;
V_24 = V_31 [ V_9 ] . V_24 ;
V_28 = V_31 [ V_9 ] . V_33 ;
F_7 ( L_3 ) ;
goto V_34;
}
}
V_18 = 100000000 / V_11 - 2 ;
if ( V_18 > V_35 )
V_18 = V_35 ;
for ( V_20 = 0 ; V_20 <= V_14 ; V_20 ++ ) {
V_22 = V_10 / ( V_18 + 2 ) ;
V_21 = V_11 / ( V_20 + 2 ) ;
if ( V_22 < 0 )
continue;
if ( V_22 == V_21 ) {
V_28 = true ;
V_24 = V_20 ;
goto V_34;
}
V_19 = abs ( V_22 - V_21 ) ;
if ( V_19 < V_27 ) {
V_28 = true ;
V_24 = V_20 ;
V_25 = V_26 ;
if ( V_19 == 0 )
goto V_34;
V_27 = V_19 ;
}
for ( V_26 = 0 ; V_26 <= V_16 ; V_26 ++ ) {
V_23 = V_22 / ( V_26 + 2 ) ;
V_19 = abs ( V_23 - V_21 ) ;
if ( V_19 < V_27 ) {
V_28 = false ;
V_24 = V_20 ;
V_25 = V_26 ;
if ( V_19 == 0 )
goto V_34;
V_27 = V_19 ;
}
}
}
F_7 ( L_4 ) ;
V_34:
V_13 -> V_33 = V_28 ;
V_13 -> V_36 = V_25 ;
V_13 -> V_37 = V_24 ;
V_13 -> V_38 = V_18 ;
return 0 ;
}
int F_8 ( int V_39 , int V_8 )
{
int V_9 , V_5 [] = { 1 , 2 , 3 , 4 , 6 , 8 , 12 , 16 } ;
if ( V_39 <= 0 || V_8 <= 0 )
return - V_7 ;
V_8 = V_8 << 8 ;
for ( V_9 = 0 ; V_9 < F_5 ( V_5 ) ; V_9 ++ )
if ( V_39 == V_8 * V_5 [ V_9 ] )
return V_9 ;
return - V_7 ;
}
