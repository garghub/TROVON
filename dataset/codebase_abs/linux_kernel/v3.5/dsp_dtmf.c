void F_1 ( struct V_1 * V_1 )
{
V_1 -> V_2 . V_3 = 0 ;
V_1 -> V_2 . V_4 = '\0' ;
V_1 -> V_2 . V_5 = '\0' ;
V_1 -> V_2 . V_6 = 0 ;
}
void F_2 ( struct V_1 * V_1 )
{
int V_7 = 1 ;
if ( ! V_1 -> V_2 . V_8 )
return;
if ( ! V_1 -> V_9 . V_10 )
V_7 = 0 ;
if ( V_1 -> V_11 ) {
if ( V_12 & V_13 )
F_3 ( V_14 L_1
L_2 ,
V_15 , V_1 -> V_16 ) ;
V_7 = 0 ;
}
if ( V_1 -> V_17 ) {
if ( V_12 & V_13 )
F_3 ( V_14 L_1
L_3 ,
V_15 , V_1 -> V_16 ) ;
V_7 = 0 ;
}
if ( V_1 -> V_18 ) {
if ( V_12 & V_13 )
F_3 ( V_14 L_1
L_4 ,
V_15 , V_1 -> V_16 ) ;
V_7 = 0 ;
}
if ( V_1 -> V_19 . V_20 ) {
if ( V_12 & V_13 )
F_3 ( V_14 L_1
L_5 ,
V_15 , V_1 -> V_16 ) ;
V_7 = 0 ;
}
V_1 -> V_2 . V_7 = V_7 ;
V_1 -> V_2 . V_21 = ! V_7 ;
}
T_1
* F_4 ( struct V_1 * V_1 , T_1 * V_22 , int V_23 , int V_24 )
{
T_1 V_25 ;
int V_3 ;
signed short * V_26 ;
T_2 V_27 , V_28 , V_29 ;
int V_30 , V_31 , V_32 ;
T_2 * V_33 ;
T_2 V_34 [ V_35 ] , V_36 , V_37 ;
int V_38 , V_39 ;
T_3 V_40 ;
V_1 -> V_2 . V_41 [ 0 ] = '\0' ;
V_42:
V_3 = V_1 -> V_2 . V_3 ;
V_26 = V_1 -> V_2 . V_43 ;
switch ( V_24 ) {
case 0 :
case 1 :
while ( V_3 < V_44 && V_23 ) {
V_26 [ V_3 ++ ] = V_45 [ * V_22 ++ ] ;
V_23 -- ;
}
break;
case 2 :
default:
if ( V_23 < 64 ) {
if ( V_23 > 0 )
F_3 ( V_46 L_6
L_7 ,
V_15 , V_23 , 64 ) ;
return V_1 -> V_2 . V_41 ;
}
V_33 = ( T_2 * ) V_22 ;
for ( V_30 = 0 ; V_30 < V_35 ; V_30 ++ ) {
V_29 = ( * V_33 ++ ) >> 4 ;
V_27 = ( * V_33 ++ ) >> 4 ;
if ( V_27 > 32767 || V_27 < - 32767 || V_29 > 32767
|| V_29 < - 32767 )
F_3 ( V_47
L_8 ) ;
V_34 [ V_30 ] =
( V_27 * V_27 ) -
( ( ( V_48 [ V_30 ] * V_27 ) >> 15 ) * V_29 ) +
( V_29 * V_29 ) ;
}
V_22 += 64 ;
V_23 -= 64 ;
goto V_49;
break;
}
V_1 -> V_2 . V_3 = V_3 ;
if ( V_3 < V_44 )
return V_1 -> V_2 . V_41 ;
V_1 -> V_2 . V_3 = 0 ;
for ( V_30 = 0 ; V_30 < V_35 ; V_30 ++ ) {
V_27 = 0 ;
V_28 = 0 ;
V_29 = 0 ;
V_26 = V_1 -> V_2 . V_43 ;
V_40 = V_48 [ V_30 ] ;
for ( V_31 = 0 ; V_31 < V_44 ; V_31 ++ ) {
V_27 = ( ( V_40 * V_28 ) >> 15 ) - V_29 + ( * V_26 ++ ) ;
V_29 = V_28 ;
V_28 = V_27 ;
}
V_27 >>= 8 ;
V_29 >>= 8 ;
if ( V_27 > 32767 || V_27 < - 32767 || V_29 > 32767 || V_29 < - 32767 )
F_3 ( V_47 L_8 ) ;
V_34 [ V_30 ] =
( V_27 * V_27 ) -
( ( ( V_48 [ V_30 ] * V_27 ) >> 15 ) * V_29 ) +
( V_29 * V_29 ) ;
}
V_49:
V_36 = 0 ;
for ( V_32 = 0 ; V_32 < V_35 ; V_32 ++ ) {
if ( V_34 [ V_32 ] < 0 )
V_34 [ V_32 ] = 0 ;
if ( V_34 [ V_32 ] > V_1 -> V_2 . V_50 ) {
if ( V_34 [ V_32 ] > V_36 )
V_36 = V_34 [ V_32 ] ;
}
}
if ( V_36 == 0 ) {
V_25 = 0 ;
goto V_51;
}
if ( V_12 & V_52 ) {
T_2 V_53 = V_36 / 100 ;
if ( V_53 == 0 ) {
V_53 = 1 ;
F_3 ( V_14
L_9 ,
V_36 ) ;
}
F_3 ( V_14 L_10
L_11 ,
V_34 [ 0 ] / 10000 , V_34 [ 1 ] / 10000 , V_34 [ 2 ] / 10000 ,
V_34 [ 3 ] / 10000 , V_34 [ 4 ] / 10000 , V_34 [ 5 ] / 10000 ,
V_34 [ 6 ] / 10000 , V_34 [ 7 ] / 10000 , V_36 / 10000 ,
V_34 [ 0 ] / ( V_53 ) , V_34 [ 1 ] / ( V_53 ) ,
V_34 [ 2 ] / ( V_53 ) , V_34 [ 3 ] / ( V_53 ) ,
V_34 [ 4 ] / ( V_53 ) , V_34 [ 5 ] / ( V_53 ) ,
V_34 [ 6 ] / ( V_53 ) , V_34 [ 7 ] / ( V_53 ) ) ;
}
V_38 = - 1 ;
V_39 = - 1 ;
V_37 = V_36 >> 3 ;
V_36 = V_36 >> 2 ;
for ( V_32 = 0 ; V_32 < V_35 ; V_32 ++ ) {
if ( V_34 [ V_32 ] < V_37 )
continue;
if ( V_34 [ V_32 ] < V_36 ) {
V_38 = - 1 ;
V_39 = - 1 ;
break;
}
if ( V_32 < V_35 / 2 ) {
if ( V_38 >= 0 ) {
V_38 = - 1 ;
break;
} else
V_38 = V_32 ;
} else {
if ( V_39 >= 0 ) {
V_39 = - 1 ;
break;
} else
V_39 = V_32 - ( V_35 / 2 ) ;
}
}
V_25 = 0 ;
if ( V_38 >= 0 && V_39 >= 0 )
V_25 = V_54 [ V_38 ] [ V_39 ] ;
V_51:
if ( V_25 && ( V_12 & V_13 ) )
F_3 ( V_14 L_12 , V_25 ) ;
if ( V_1 -> V_2 . V_4 != V_25 )
V_1 -> V_2 . V_6 = 0 ;
if ( V_1 -> V_2 . V_6 == 2 ) {
if ( V_1 -> V_2 . V_5 != V_25 ) {
V_1 -> V_2 . V_5 = V_25 ;
if ( V_25 ) {
if ( V_12 & V_13 )
F_3 ( V_14 L_13 ,
V_25 ) ;
if ( ( strlen ( V_1 -> V_2 . V_41 ) + 1 )
< sizeof( V_1 -> V_2 . V_41 ) ) {
V_1 -> V_2 . V_41 [ strlen (
V_1 -> V_2 . V_41 ) + 1 ] = '\0' ;
V_1 -> V_2 . V_41 [ strlen (
V_1 -> V_2 . V_41 ) ] = V_25 ;
}
}
}
} else
V_1 -> V_2 . V_6 ++ ;
V_1 -> V_2 . V_4 = V_25 ;
goto V_42;
}
