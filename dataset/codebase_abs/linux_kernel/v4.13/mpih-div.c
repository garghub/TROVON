T_1
F_1 ( T_2 V_1 , T_3 V_2 ,
T_2 V_3 , T_3 V_4 , T_2 V_5 , T_3 V_6 )
{
T_1 V_7 = 0 ;
switch ( V_6 ) {
case 0 :
return 1 / V_6 ;
case 1 :
{
T_3 V_8 ;
T_1 V_9 ;
T_1 V_10 ;
V_10 = V_5 [ 0 ] ;
V_9 = V_3 [ V_4 - 1 ] ;
if ( V_9 >= V_10 ) {
V_9 -= V_10 ;
V_7 = 1 ;
}
V_1 += V_2 ;
for ( V_8 = V_4 - 2 ; V_8 >= 0 ; V_8 -- )
F_2 ( V_1 [ V_8 ] , V_9 , V_9 , V_3 [ V_8 ] , V_10 ) ;
V_1 -= V_2 ;
for ( V_8 = V_2 - 1 ; V_8 >= 0 ; V_8 -- )
F_2 ( V_1 [ V_8 ] , V_9 , V_9 , 0 , V_10 ) ;
V_3 [ 0 ] = V_9 ;
}
break;
case 2 :
{
T_3 V_8 ;
T_1 V_9 , V_11 , V_12 ;
T_1 V_13 , V_14 ;
V_3 += V_4 - 2 ;
V_13 = V_5 [ 1 ] ;
V_14 = V_5 [ 0 ] ;
V_9 = V_3 [ 1 ] ;
V_11 = V_3 [ 0 ] ;
if ( V_9 >= V_13 && ( V_9 > V_13 || V_11 >= V_14 ) ) {
F_3 ( V_9 , V_11 , V_9 , V_11 , V_13 , V_14 ) ;
V_7 = 1 ;
}
for ( V_8 = V_2 + V_4 - 2 - 1 ; V_8 >= 0 ; V_8 -- ) {
T_1 V_15 ;
T_1 V_16 ;
if ( V_8 >= V_2 )
V_3 -- ;
else
V_3 [ 0 ] = 0 ;
if ( V_9 == V_13 ) {
V_15 = ~ ( T_1 ) 0 ;
V_16 = V_11 + V_13 ;
if ( V_16 < V_13 ) {
F_4 ( V_9 , V_11 , V_16 - V_14 ,
V_3 [ 0 ] , 0 , V_14 ) ;
V_1 [ V_8 ] = V_15 ;
continue;
}
V_9 = V_14 - ( V_14 != 0 ? 1 : 0 ) ;
V_11 = - V_14 ;
} else {
F_2 ( V_15 , V_16 , V_9 , V_11 , V_13 ) ;
F_5 ( V_9 , V_11 , V_14 , V_15 ) ;
}
V_12 = V_3 [ 0 ] ;
V_17:
if ( V_9 > V_16 || ( V_9 == V_16 && V_11 > V_12 ) ) {
V_15 -- ;
F_3 ( V_9 , V_11 , V_9 , V_11 , 0 , V_14 ) ;
V_16 += V_13 ;
if ( V_16 >= V_13 )
goto V_17;
}
V_1 [ V_8 ] = V_15 ;
F_3 ( V_9 , V_11 , V_16 , V_12 , V_9 , V_11 ) ;
}
V_3 [ 1 ] = V_9 ;
V_3 [ 0 ] = V_11 ;
}
break;
default:
{
T_3 V_8 ;
T_1 V_18 , V_13 , V_11 ;
V_3 += V_4 - V_6 ;
V_18 = V_5 [ V_6 - 1 ] ;
V_13 = V_5 [ V_6 - 2 ] ;
V_11 = V_3 [ V_6 - 1 ] ;
if ( V_11 >= V_18 ) {
if ( V_11 > V_18
|| F_6 ( V_3 , V_5 , V_6 - 1 ) >= 0 ) {
F_7 ( V_3 , V_3 , V_5 , V_6 ) ;
V_11 = V_3 [ V_6 - 1 ] ;
V_7 = 1 ;
}
}
for ( V_8 = V_2 + V_4 - V_6 - 1 ; V_8 >= 0 ; V_8 -- ) {
T_1 V_15 ;
T_1 V_9 , V_12 ;
T_1 V_19 ;
if ( V_8 >= V_2 ) {
V_3 -- ;
V_12 = V_3 [ V_6 ] ;
} else {
V_12 = V_3 [ V_6 - 1 ] ;
F_8 ( V_3 + 1 , V_3 , V_6 - 1 ) ;
V_3 [ 0 ] = 0 ;
}
if ( V_11 == V_18 ) {
V_15 = ~ ( T_1 ) 0 ;
} else {
T_1 V_16 ;
F_2 ( V_15 , V_16 , V_11 , V_3 [ V_6 - 1 ] , V_18 ) ;
F_5 ( V_9 , V_11 , V_13 , V_15 ) ;
while ( V_9 > V_16
|| ( V_9 == V_16
&& V_11 > V_3 [ V_6 - 2 ] ) ) {
V_15 -- ;
V_16 += V_18 ;
if ( V_16 < V_18 )
break;
V_9 -= V_11 < V_13 ;
V_11 -= V_13 ;
}
}
V_19 = F_9 ( V_3 , V_5 , V_6 , V_15 ) ;
if ( V_12 != V_19 ) {
F_10 ( V_3 , V_3 , V_5 , V_6 ) ;
V_15 -- ;
}
V_1 [ V_8 ] = V_15 ;
V_11 = V_3 [ V_6 - 1 ] ;
}
}
}
return V_7 ;
}
