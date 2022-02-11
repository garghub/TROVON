int F_1 ( const T_1 * V_1 , unsigned int V_2 , unsigned int V_3 , T_1 V_4 )
{
int V_5 ;
for ( V_5 = V_2 ; V_5 < V_3 ; ) {
T_1 V_6 = V_1 [ V_5 ] ;
if ( V_6 & V_7 ) {
if ( V_5 + V_8 > V_3 )
break;
if ( V_6 == V_4 )
return V_5 ;
V_5 += V_8 +
F_2 ( & V_1 [ V_5 ] ) ;
} else {
T_1 V_9 = V_6 & ~ V_10 ;
if ( V_9 == V_4 )
return V_5 ;
if ( V_9 == V_11 )
break;
V_5 += V_12 +
F_3 ( & V_1 [ V_5 ] ) ;
}
}
return - V_13 ;
}
int F_4 ( const T_1 * V_1 , unsigned int V_2 ,
unsigned int V_3 , const char * V_14 )
{
int V_5 ;
for ( V_5 = V_2 ; V_5 + V_15 <= V_2 + V_3 ; ) {
if ( V_1 [ V_5 + 0 ] == V_14 [ 0 ] &&
V_1 [ V_5 + 1 ] == V_14 [ 1 ] )
return V_5 ;
V_5 += V_15 +
F_5 ( & V_1 [ V_5 ] ) ;
}
return - V_13 ;
}
