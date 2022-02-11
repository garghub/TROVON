static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
T_1 V_5 [ V_6 + 1 ] ;
struct V_7 * V_8 ;
const struct V_3 * V_9 ;
enum V_10 V_11 ;
int V_12 , V_13 , V_14 ;
if ( ! F_2 ( V_2 -> V_15 ,
V_16 |
V_17 ) )
return - V_18 ;
V_14 = F_3 ( V_2 , V_19 ,
V_5 ) ;
if ( V_14 < 0 ) {
F_4 ( & V_2 -> V_20 , L_1 ) ;
return V_14 ;
}
V_5 [ V_14 ] = '\0' ;
F_5 ( & V_2 -> V_20 , L_2 , V_5 ) ;
for ( V_9 = V_21 ; V_9 -> V_22 [ 0 ] ; V_9 ++ ) {
if ( ! strncasecmp ( V_9 -> V_22 , V_5 , strlen ( V_9 -> V_22 ) ) )
break;
}
if ( ! V_9 -> V_22 [ 0 ] ) {
F_4 ( & V_2 -> V_20 , L_3 ) ;
return - V_18 ;
}
if ( V_2 -> V_20 . V_23 )
V_11 = (enum V_10 ) F_6 ( & V_2 -> V_20 ) ;
else
V_11 = V_4 -> V_24 ;
if ( V_11 != V_25 && V_11 != V_9 -> V_24 )
F_7 ( & V_2 -> V_20 ,
L_4 ,
V_4 -> V_22 , V_9 -> V_22 ) ;
V_8 = F_8 ( & V_2 -> V_20 , sizeof( struct V_7 ) ,
V_26 ) ;
if ( ! V_8 )
return - V_27 ;
V_14 = F_3 ( V_2 , V_28 ,
V_5 ) ;
if ( V_14 < 0 ) {
F_4 ( & V_2 -> V_20 , L_5 ) ;
return V_14 ;
}
V_8 -> V_29 = 0 ;
for ( V_12 = 0 ; V_12 < V_14 ; V_12 ++ ) {
if ( ! V_5 [ V_12 ] )
break;
V_8 -> V_29 ++ ;
}
if ( ! V_8 -> V_29 ) {
F_4 ( & V_2 -> V_20 , L_6 ) ;
return - V_18 ;
}
F_5 ( & V_2 -> V_20 , L_7 , V_8 -> V_29 ) ;
for ( V_12 = 0 ; V_12 < V_8 -> V_29 ; V_12 ++ ) {
for ( V_13 = 0 ; V_13 < 3 ; V_13 ++ ) {
V_14 = F_9 ( V_2 , V_30 , V_12 ) ;
if ( V_14 < 0 )
continue;
V_14 = F_9 ( V_2 , V_31 ,
0xff ) ;
if ( V_14 < 0 )
continue;
break;
}
if ( V_14 < 0 ) {
F_4 ( & V_2 -> V_20 ,
L_8 ) ;
return V_14 ;
}
}
if ( V_8 -> V_29 > 1 )
F_9 ( V_2 , V_30 , 0 ) ;
V_8 -> V_32 [ 0 ] = V_33 | V_34 |
V_35 | V_36 |
V_37 | V_38 |
V_39 | V_40 |
V_41 | V_42 |
V_43 | V_44 ;
for ( V_12 = 1 ; V_12 < V_8 -> V_29 ; V_12 ++ )
V_8 -> V_32 [ V_12 ] = V_37 | V_38 |
V_39 | V_40 |
V_41 |
V_43 | V_44 ;
if ( V_9 -> V_24 == V_45 )
V_8 -> V_32 [ 0 ] |= V_46 | V_47 ;
return F_10 ( V_2 , V_9 , V_8 ) ;
}
