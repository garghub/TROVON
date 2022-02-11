int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
int V_4 , V_5 = 0 , V_6 ;
T_1 V_7 [ V_8 ] ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
for ( V_4 = 0 ; V_4 < V_8 ; V_4 ++ ) {
if ( F_3 ( V_4 , V_2 -> V_11 ) ) {
V_7 [ V_5 ] = V_2 -> V_12 [ V_4 ] . V_13 ;
V_5 ++ ;
}
}
switch ( V_5 ) {
case 1 :
V_6 = V_10 -> V_14 -> V_15 ( & V_10 -> V_16 , V_10 -> V_17 ,
V_7 [ 0 ] , V_18 , V_3 ,
V_10 -> V_19 ) ;
break;
case 2 :
if ( ( V_7 [ 1 ] - V_7 [ 0 ] ) == V_18 ) {
V_6 = V_10 -> V_14 -> V_15 ( & V_10 -> V_16 ,
V_10 -> V_17 , V_7 [ 0 ] ,
V_18 * V_5 ,
V_3 , V_10 -> V_19 ) ;
} else {
T_1 V_20 [ V_18 *
V_8 ] ;
V_6 = V_10 -> V_14 -> V_15 ( & V_10 -> V_16 ,
V_10 -> V_17 , V_7 [ 0 ] ,
V_18 *
V_8 ,
V_20 , V_10 -> V_19 ) ;
if ( V_6 < 0 )
goto V_21;
for ( V_4 = 0 ; V_4 < V_5 * V_8 ;
V_4 ++ ) {
if ( V_4 < V_5 )
V_3 [ V_4 ] = V_20 [ V_4 ] ;
else
V_3 [ V_4 ] = V_20 [ V_5 + V_4 ] ;
}
V_6 = V_18 * V_5 ;
}
break;
case 3 :
V_6 = V_10 -> V_14 -> V_15 ( & V_10 -> V_16 , V_10 -> V_17 ,
V_7 [ 0 ] , V_18 *
V_8 ,
V_3 , V_10 -> V_19 ) ;
break;
default:
V_6 = - V_22 ;
goto V_21;
}
if ( V_6 != V_18 * V_5 ) {
V_6 = - V_23 ;
goto V_21;
}
V_21:
return V_6 ;
}
T_2 F_4 ( int V_24 , void * V_25 )
{
int V_6 ;
struct V_26 * V_27 = V_25 ;
struct V_1 * V_2 = V_27 -> V_2 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
V_6 = F_1 ( V_2 , V_10 -> V_28 ) ;
if ( V_6 < 0 )
goto V_29;
if ( V_2 -> V_30 )
* ( V_31 * ) ( ( T_1 * ) V_10 -> V_28 +
F_5 ( V_6 , sizeof( V_31 ) ) ) = V_27 -> V_32 ;
F_6 ( V_2 , V_10 -> V_28 ) ;
V_29:
F_7 ( V_2 -> V_33 ) ;
return V_34 ;
}
