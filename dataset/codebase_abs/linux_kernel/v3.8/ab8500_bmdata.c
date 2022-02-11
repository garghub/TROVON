int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * * V_6 )
{
struct V_7 * V_8 ;
struct V_3 * V_9 ;
struct V_5 * V_10 ;
const char * V_11 ;
char V_12 [ 8 ] ;
int V_13 , V_14 ;
* V_6 = & V_15 ;
V_9 = F_2 ( V_4 , L_1 , 0 ) ;
if ( ! V_9 ) {
F_3 ( V_2 , L_2 ) ;
return - V_16 ;
}
if ( F_4 ( V_9 ,
L_3 ) )
V_14 = V_17 ;
else
V_14 = V_18 ;
V_10 = * V_6 ;
if ( V_14 == V_18 ) {
V_10 -> V_19 = 4 ;
V_10 -> V_20 = V_21 ;
V_10 -> V_22 = V_23 ;
}
V_11 = F_5 ( V_9 ,
L_4 , NULL ) ;
if ( ! V_11 ) {
F_6 ( V_2 , L_5 ) ;
strcpy ( V_12 , L_6 ) ;
} else {
strcpy ( V_12 , V_11 ) ;
}
if ( strncmp ( V_12 , L_7 , 4 ) == 0 ) {
V_10 -> V_24 = true ;
V_10 -> V_25 = true ;
V_10 -> V_20 [ V_26 ] . V_27 = 2600 ;
V_10 -> V_20 [ V_26 ] . V_28 = 4150 ;
V_10 -> V_20 [ V_26 ] . V_29 = 4130 ;
V_10 -> V_20 [ V_26 ] . V_30 = 520 ;
V_10 -> V_20 [ V_26 ] . V_31 = 4200 ;
}
for ( V_13 = 0 ; V_13 < V_10 -> V_19 ; ++ V_13 ) {
V_8 = ( V_10 -> V_20 + V_13 ) ;
if ( V_14 == V_18 ) {
V_8 -> V_32 =
V_33 ;
} else if ( strncmp ( V_12 , L_7 , 4 ) == 0 ) {
V_8 -> V_32 =
V_34 ;
} else {
V_8 -> V_32 =
V_35 ;
}
}
F_7 ( V_9 ) ;
return 0 ;
}
