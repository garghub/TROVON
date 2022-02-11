int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
T_1 * V_4 ;
int V_5 , V_6 = 0 , V_7 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
unsigned int V_10 = V_9 -> V_10 ;
unsigned int V_11 =
V_2 -> V_12 [ 0 ] . V_13 . V_14 >> 3 ;
V_4 = F_3 ( V_10 , V_15 ) ;
if ( ! V_4 ) {
V_7 = - V_16 ;
goto V_17;
}
for ( V_5 = 0 ; V_5 < V_10 ; V_5 ++ ) {
if ( F_4 ( V_5 , V_2 -> V_18 ) ) {
V_4 [ V_6 ] = V_2 -> V_12 [ V_5 ] . V_19 ;
V_6 ++ ;
}
}
switch ( V_6 ) {
case 1 :
V_7 = V_9 -> V_20 -> V_21 ( & V_9 -> V_22 , V_9 -> V_23 ,
V_4 [ 0 ] , V_11 , V_3 , V_9 -> V_24 ) ;
break;
case 2 :
if ( ( V_4 [ 1 ] - V_4 [ 0 ] ) == V_11 ) {
V_7 = V_9 -> V_20 -> V_21 ( & V_9 -> V_22 ,
V_9 -> V_23 , V_4 [ 0 ] , V_11 * V_6 ,
V_3 , V_9 -> V_24 ) ;
} else {
T_1 * V_25 ;
V_25 = F_3 ( V_11 * V_10 ,
V_15 ) ;
if ( ! V_25 ) {
V_7 = - V_16 ;
goto V_26;
}
V_7 = V_9 -> V_20 -> V_21 ( & V_9 -> V_22 ,
V_9 -> V_23 , V_4 [ 0 ] ,
V_11 * V_10 ,
V_25 , V_9 -> V_24 ) ;
if ( V_7 < 0 ) {
F_5 ( V_25 ) ;
goto V_26;
}
for ( V_5 = 0 ; V_5 < V_6 * V_10 ; V_5 ++ ) {
if ( V_5 < V_6 )
V_3 [ V_5 ] = V_25 [ V_5 ] ;
else
V_3 [ V_5 ] = V_25 [ V_6 + V_5 ] ;
}
F_5 ( V_25 ) ;
V_7 = V_11 * V_6 ;
}
break;
case 3 :
V_7 = V_9 -> V_20 -> V_21 ( & V_9 -> V_22 , V_9 -> V_23 ,
V_4 [ 0 ] , V_11 * V_10 ,
V_3 , V_9 -> V_24 ) ;
break;
default:
V_7 = - V_27 ;
goto V_26;
}
if ( V_7 != V_11 * V_6 ) {
V_7 = - V_28 ;
goto V_26;
}
V_26:
F_5 ( V_4 ) ;
V_17:
return V_7 ;
}
T_2 F_6 ( int V_29 , void * V_30 )
{
int V_7 ;
struct V_31 * V_32 = V_30 ;
struct V_1 * V_2 = V_32 -> V_2 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
V_7 = F_1 ( V_2 , V_9 -> V_33 ) ;
if ( V_7 < 0 )
goto V_17;
F_7 ( V_2 , V_9 -> V_33 ,
V_32 -> V_34 ) ;
V_17:
F_8 ( V_2 -> V_35 ) ;
return V_36 ;
}
