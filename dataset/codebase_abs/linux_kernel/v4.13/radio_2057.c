void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 * V_5 = NULL ;
T_1 V_6 , V_7 ;
switch ( V_4 -> V_8 ) {
case 7 :
V_5 = V_9 [ 0 ] ;
V_6 = F_2 ( V_9 ) ;
break;
case 8 :
if ( V_4 -> V_10 == 5 ) {
V_5 = V_11 [ 0 ] ;
V_6 = F_2 ( V_11 ) ;
} else if ( V_4 -> V_10 == 7 ) {
V_5 = V_12 [ 0 ] ;
V_6 = F_2 ( V_12 ) ;
}
break;
case 9 :
if ( V_4 -> V_10 == 5 ) {
V_5 = V_13 [ 0 ] ;
V_6 = F_2 ( V_13 ) ;
}
break;
case 16 :
if ( V_4 -> V_10 == 9 ) {
V_5 = V_14 [ 0 ] ;
V_6 = F_2 ( V_14 ) ;
}
break;
case 17 :
if ( V_4 -> V_10 == 14 ) {
V_5 = V_15 [ 0 ] ;
V_6 = F_2 ( V_15 ) ;
}
break;
}
F_3 ( ! V_5 ) ;
if ( V_5 ) {
for ( V_7 = 0 ; V_7 < V_6 ; V_7 ++ , V_5 += 2 )
F_4 ( V_2 , V_5 [ 0 ] , V_5 [ 1 ] ) ;
}
}
void F_5 ( struct V_1 * V_2 , T_1 V_16 ,
const struct V_17 * * V_18 ,
const struct V_19 * * V_20 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
const struct V_17 * V_21 = NULL ;
const struct V_19 * V_22 = NULL ;
unsigned int V_23 , V_7 ;
* V_18 = NULL ;
* V_20 = NULL ;
switch ( V_4 -> V_8 ) {
case 8 :
if ( V_4 -> V_10 == 5 ) {
V_22 = V_24 ;
V_23 = F_2 ( V_24 ) ;
}
break;
case 16 :
if ( V_4 -> V_10 == 9 ) {
V_21 = V_25 ;
V_23 = F_2 ( V_25 ) ;
}
break;
case 17 :
if ( V_4 -> V_10 == 14 ) {
V_22 = V_26 ;
V_23 = F_2 ( V_26 ) ;
}
break;
default:
break;
}
if ( V_21 ) {
for ( V_7 = 0 ; V_7 < V_23 ; V_7 ++ , V_21 ++ ) {
if ( V_21 -> V_16 == V_16 ) {
* V_18 = V_21 ;
return;
}
}
} else if ( V_22 ) {
for ( V_7 = 0 ; V_7 < V_23 ; V_7 ++ , V_22 ++ ) {
if ( V_22 -> V_16 == V_16 ) {
* V_20 = V_22 ;
return;
}
}
} else {
F_3 ( 1 ) ;
}
}
