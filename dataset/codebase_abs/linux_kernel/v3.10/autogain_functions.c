int F_1 (
struct V_1 * V_1 ,
int V_2 ,
int V_3 ,
int V_4 ,
int V_5 ,
int V_6 )
{
T_1 V_7 , V_8 , V_9 , V_10 ;
int V_11 , V_12 , V_13 = 0 ;
if ( F_2 ( V_1 -> V_14 ) == 0 )
return 0 ;
V_8 = V_7 = F_2 ( V_1 -> V_7 ) ;
V_10 = V_9 = F_2 ( V_1 -> V_9 ) ;
V_12 = abs ( V_3 - V_2 ) / V_4 ;
F_3 ( V_15 , L_1 ,
V_2 , V_3 , V_12 ) ;
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ ) {
if ( V_2 > V_3 ) {
if ( V_7 > V_5 )
V_7 -- ;
else if ( V_9 > V_6 )
V_9 -- ;
else if ( V_7 > V_1 -> V_7 -> V_16 )
V_7 -- ;
else if ( V_9 > V_1 -> V_9 -> V_17 )
V_9 -- ;
else if ( V_7 > V_1 -> V_7 -> V_17 )
V_7 -- ;
else
break;
} else {
if ( V_7 < V_1 -> V_7 -> V_16 )
V_7 ++ ;
else if ( V_9 < V_6 )
V_9 ++ ;
else if ( V_7 < V_5 )
V_7 ++ ;
else if ( V_9 < V_1 -> V_9 -> V_18 )
V_9 ++ ;
else if ( V_7 < V_1 -> V_7 -> V_18 )
V_7 ++ ;
else
break;
}
}
if ( V_7 != V_8 ) {
F_4 ( V_1 -> V_7 , V_7 ) ;
V_13 = 1 ;
}
if ( V_9 != V_10 ) {
F_4 ( V_1 -> V_9 , V_9 ) ;
V_13 = 1 ;
}
if ( V_13 )
F_3 ( V_15 , L_2 ,
V_7 , V_9 ) ;
return V_13 ;
}
int F_5 (
struct V_1 * V_1 ,
int V_2 ,
int V_3 ,
int V_4 )
{
T_1 V_19 , V_20 , V_7 , V_8 , V_9 , V_10 ;
int V_12 , V_13 = 0 ;
if ( F_2 ( V_1 -> V_14 ) == 0 )
return 0 ;
V_8 = V_7 = F_2 ( V_1 -> V_7 ) ;
V_10 = V_9 = F_2 ( V_1 -> V_9 ) ;
V_19 = ( V_1 -> V_7 -> V_18 - V_1 -> V_7 -> V_17 ) /
5 * 2 + V_1 -> V_7 -> V_17 ;
V_20 = ( V_1 -> V_7 -> V_18 - V_1 -> V_7 -> V_17 ) /
5 * 4 + V_1 -> V_7 -> V_17 ;
V_12 = ( V_3 - V_2 ) / V_4 ;
F_3 ( V_15 , L_1 ,
V_2 , V_3 , V_12 ) ;
if ( ( V_7 + V_12 ) > V_20 &&
V_9 < V_1 -> V_9 -> V_18 ) {
V_7 = V_20 ;
V_1 -> V_21 ++ ;
V_1 -> V_22 = 0 ;
} else if ( ( V_7 + V_12 ) < V_19 &&
V_9 > V_1 -> V_9 -> V_17 ) {
V_7 = V_19 ;
V_1 -> V_22 ++ ;
V_1 -> V_21 = 0 ;
} else {
V_7 += V_12 ;
if ( V_7 > V_1 -> V_7 -> V_18 )
V_7 = V_1 -> V_7 -> V_18 ;
else if ( V_7 < V_1 -> V_7 -> V_17 )
V_7 = V_1 -> V_7 -> V_17 ;
V_1 -> V_22 = 0 ;
V_1 -> V_21 = 0 ;
}
if ( V_1 -> V_22 > 3 ) {
V_9 -- ;
V_1 -> V_22 = 0 ;
} else if ( V_1 -> V_21 > 3 ) {
V_9 ++ ;
V_1 -> V_21 = 0 ;
}
if ( V_7 != V_8 ) {
F_4 ( V_1 -> V_7 , V_7 ) ;
V_13 = 1 ;
}
if ( V_9 != V_10 ) {
F_4 ( V_1 -> V_9 , V_9 ) ;
V_13 = 1 ;
}
if ( V_13 )
F_3 ( V_15 , L_2 ,
V_7 , V_9 ) ;
return V_13 ;
}
