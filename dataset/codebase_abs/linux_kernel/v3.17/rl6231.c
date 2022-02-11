int F_1 ( int V_1 )
{
int div [] = { 2 , 3 , 4 , 6 , 8 , 12 } , V_2 = - V_3 ;
int V_4 , V_5 , V_6 , V_7 ;
V_5 = 3000000 * 12 ;
for ( V_4 = 0 ; V_4 < F_2 ( div ) ; V_4 ++ ) {
V_6 = div [ V_4 ] * 3000000 ;
if ( V_1 > V_6 )
continue;
V_7 = V_6 - V_1 ;
if ( V_7 < V_5 ) {
V_5 = V_7 ;
V_2 = V_4 ;
}
}
return V_2 ;
}
int F_3 ( const unsigned int V_8 ,
const unsigned int V_9 , struct V_10 * V_11 )
{
int V_12 = V_13 , V_14 = V_15 ;
int V_16 , V_5 , V_17 , V_18 , V_19 , V_20 ;
int V_21 = 0 , V_22 = 0 , V_23 = 0 ;
int V_24 = abs ( V_9 - V_8 ) ;
bool V_25 = false ;
if ( V_26 < V_8 || V_27 > V_8 )
return - V_3 ;
V_16 = 100000000 / V_9 - 2 ;
if ( V_16 > V_28 )
V_16 = V_28 ;
for ( V_17 = 0 ; V_17 <= V_12 ; V_17 ++ ) {
V_19 = V_8 / ( V_16 + 2 ) ;
V_18 = V_9 / ( V_17 + 2 ) ;
if ( V_19 < 0 )
continue;
if ( V_19 == V_18 ) {
V_25 = true ;
V_21 = V_17 ;
goto V_29;
}
V_5 = abs ( V_19 - V_18 ) ;
if ( V_5 < V_24 ) {
V_25 = true ;
V_21 = V_17 ;
V_22 = V_23 ;
if ( V_5 == 0 )
goto V_29;
V_24 = V_5 ;
}
for ( V_23 = 0 ; V_23 <= V_14 ; V_23 ++ ) {
V_20 = V_19 / ( V_23 + 2 ) ;
V_5 = abs ( V_20 - V_18 ) ;
if ( V_5 < V_24 ) {
V_25 = false ;
V_21 = V_17 ;
V_22 = V_23 ;
if ( V_5 == 0 )
goto V_29;
V_24 = V_5 ;
}
}
}
F_4 ( L_1 ) ;
V_29:
V_11 -> V_30 = V_25 ;
V_11 -> V_31 = V_22 ;
V_11 -> V_32 = V_21 ;
V_11 -> V_33 = V_16 ;
return 0 ;
}
int F_5 ( int V_34 , int V_1 )
{
int V_4 , V_35 [] = { 1 , 2 , 3 , 4 , 6 , 8 , 12 , 16 } ;
if ( V_34 <= 0 || V_1 <= 0 )
return - V_3 ;
V_1 = V_1 << 8 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_35 ) ; V_4 ++ )
if ( V_34 == V_1 * V_35 [ V_4 ] )
return V_4 ;
return - V_3 ;
}
