int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 ;
struct V_3 * V_9 ;
const char * V_10 ;
int V_11 ;
V_9 = F_2 ( V_4 , L_1 , 0 ) ;
if ( ! V_9 ) {
F_3 ( V_2 , L_2 ) ;
return - V_12 ;
}
V_10 = F_4 ( V_9 , L_3 , NULL ) ;
if ( ! V_10 ) {
F_5 ( V_2 , L_4 ) ;
return - V_12 ;
}
if ( strncmp ( V_10 , L_5 , 4 ) == 0 ) {
V_6 -> V_13 = true ;
V_6 -> V_14 = true ;
V_6 -> V_15 [ V_16 ] . V_17 = 2600 ;
V_6 -> V_15 [ V_16 ] . V_18 = 4150 ;
V_6 -> V_15 [ V_16 ] . V_19 = 95 ;
V_6 -> V_15 [ V_16 ] . V_20 = 520 ;
V_6 -> V_15 [ V_16 ] . V_21 = 4200 ;
}
if ( F_6 ( V_9 , L_6 ) ) {
if ( strncmp ( V_10 , L_5 , 4 ) == 0 )
V_8 = V_22 ;
else
V_8 = V_23 ;
} else {
V_6 -> V_24 = 4 ;
V_6 -> V_15 = V_25 ;
V_6 -> V_26 = V_27 ;
V_8 = V_28 ;
}
for ( V_11 = 0 ; V_11 < V_6 -> V_24 ; ++ V_11 )
V_6 -> V_15 [ V_11 ] . V_29 = V_8 ;
F_7 ( V_9 ) ;
return 0 ;
}
