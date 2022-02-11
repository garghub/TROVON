void F_1 ( int * V_1 , int * V_2 )
{
int V_3 [] = { V_4 , V_5 } ;
int V_6 ;
for ( V_6 = 0 ; V_6 < F_2 ( V_3 ) ; V_6 ++ ) {
T_1 V_7 ;
V_7 . V_8 = V_3 [ V_6 ] ;
if ( F_3 ( V_9 , & V_7 ) == 0 ) {
* V_2 = V_3 [ V_6 ] ;
* V_1 = 1 ;
return;
} else {
if ( V_10 == V_11 )
continue;
else if ( V_10 == V_12 )
* V_1 = 0 ;
return;
}
}
* V_1 = 0 ;
}
int F_4 ( T_1 * V_7 , int V_13 )
{
int V_14 ;
V_14 = F_5 ( V_15 , V_13 , V_7 -> V_8 ,
( unsigned long ) V_7 ) ;
if ( V_14 < 0 )
V_14 = - V_10 ;
return V_14 ;
}
int F_6 ( T_1 * V_7 , int V_13 )
{
int V_14 ;
V_14 = F_5 ( V_16 , V_13 , V_7 -> V_8 ,
( unsigned long ) V_7 ) ;
if ( V_14 < 0 )
V_14 = - V_10 ;
return V_14 ;
}
