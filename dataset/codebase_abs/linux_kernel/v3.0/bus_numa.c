void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 ;
struct V_5 * V_6 ;
if ( V_2 -> V_7 [ 0 ] != & V_8 ||
V_2 -> V_7 [ 1 ] != & V_9 )
return;
if ( ! V_10 )
return;
for ( V_3 = 0 ; V_3 < V_10 ; V_3 ++ ) {
if ( V_5 [ V_3 ] . V_11 == V_2 -> V_12 )
break;
}
if ( V_3 == V_10 )
return;
F_2 ( V_13 L_1 ,
V_2 -> V_12 ) ;
F_3 ( V_2 ) ;
V_6 = & V_5 [ V_3 ] ;
for ( V_4 = 0 ; V_4 < V_6 -> V_14 ; V_4 ++ ) {
struct V_7 * V_15 ;
struct V_7 * V_16 ;
V_15 = & V_6 -> V_15 [ V_4 ] ;
F_4 ( V_2 , V_15 , 0 ) ;
if ( V_15 -> V_17 & V_18 )
V_16 = & V_8 ;
else
V_16 = & V_9 ;
F_5 ( V_16 , V_15 ) ;
}
}
void T_1 F_6 ( struct V_5 * V_6 , T_2 V_19 ,
T_2 V_20 , unsigned long V_17 , int V_21 )
{
int V_3 ;
struct V_7 * V_15 ;
if ( V_19 > V_20 )
return;
if ( V_19 == V_22 )
return;
if ( ! V_21 )
goto V_23;
for ( V_3 = 0 ; V_3 < V_6 -> V_14 ; V_3 ++ ) {
T_2 V_24 , V_25 ;
T_2 V_26 , V_27 ;
V_15 = & V_6 -> V_15 [ V_3 ] ;
if ( V_15 -> V_17 != V_17 )
continue;
V_26 = F_7 ( V_15 -> V_19 , V_19 ) ;
V_27 = F_8 ( V_15 -> V_20 , V_20 ) ;
if ( V_26 > V_27 + 1 )
continue;
V_24 = F_8 ( V_15 -> V_19 , V_19 ) ;
V_25 = F_7 ( V_15 -> V_20 , V_20 ) ;
V_15 -> V_19 = V_24 ;
V_15 -> V_20 = V_25 ;
return;
}
V_23:
if ( V_6 -> V_14 >= V_28 )
return;
V_15 = & V_6 -> V_15 [ V_6 -> V_14 ] ;
V_15 -> V_29 = V_6 -> V_29 ;
V_15 -> V_17 = V_17 ;
V_15 -> V_19 = V_19 ;
V_15 -> V_20 = V_20 ;
V_15 -> V_30 = NULL ;
V_6 -> V_14 ++ ;
}
