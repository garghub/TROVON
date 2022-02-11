int T_1 F_1 ( struct V_1 * V_2 ,
T_2 V_3 )
{
int V_4 , V_5 ;
if ( F_2 () )
return - V_6 ;
if ( ! V_2 || ! V_3 ) {
F_3 ( L_1 , V_7 ) ;
return - V_6 ;
}
if ( V_8 )
return - V_9 ;
V_8 = 1 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ , V_2 ++ ) {
struct V_10 * V_11 ;
struct V_12 * V_13 ;
if ( ! V_2 -> V_14 ) {
F_3 ( L_2 ,
V_7 , V_4 ) ;
return - V_6 ;
}
if ( ! strncmp ( V_2 -> V_14 , L_3 , 3 ) ) {
V_13 = F_4 ( 0 ) ;
} else {
V_11 = F_5 ( V_2 -> V_14 ) ;
if ( ! V_11 || ! V_11 -> V_15 ) {
F_6 ( L_4 ,
V_7 , V_2 -> V_14 , V_4 ) ;
continue;
}
V_13 = & V_11 -> V_15 -> V_16 -> V_13 ;
}
V_5 = F_7 ( V_13 , V_2 -> V_17 , V_2 -> V_18 ) ;
if ( V_5 ) {
F_8 ( V_13 , L_5 ,
V_7 , V_2 -> V_17 ,
V_2 -> V_14 , V_4 , V_5 ) ;
} else {
if ( ! V_2 -> V_19 )
V_5 = F_9 ( V_13 , V_2 -> V_17 ) ;
if ( V_5 )
F_8 ( V_13 , L_6 ,
V_7 , V_2 -> V_17 ,
V_2 -> V_14 , V_4 , V_5 ) ;
}
}
return 0 ;
}
