void F_1 ( int V_1 , struct V_2 * V_3 )
{
int V_4 ;
int V_5 ;
struct V_6 * V_7 ;
if ( ! V_8 )
goto V_9;
for ( V_4 = 0 ; V_4 < V_8 ; V_4 ++ ) {
if ( V_6 [ V_4 ] . V_10 == V_1 )
break;
}
if ( V_4 == V_8 )
goto V_9;
F_2 ( V_11 L_1 ,
V_1 ) ;
V_7 = & V_6 [ V_4 ] ;
for ( V_5 = 0 ; V_5 < V_7 -> V_12 ; V_5 ++ ) {
struct V_13 * V_14 ;
struct V_13 * V_15 ;
V_14 = & V_7 -> V_14 [ V_5 ] ;
F_3 ( V_3 , V_14 ) ;
if ( V_14 -> V_16 & V_17 )
V_15 = & V_18 ;
else
V_15 = & V_19 ;
F_4 ( V_15 , V_14 ) ;
}
return;
V_9:
F_2 ( V_11 L_2 , V_1 ) ;
F_3 ( V_3 , & V_18 ) ;
F_3 ( V_3 , & V_19 ) ;
}
void T_1 F_5 ( struct V_6 * V_7 , T_2 V_20 ,
T_2 V_21 , unsigned long V_16 , int V_22 )
{
int V_4 ;
struct V_13 * V_14 ;
if ( V_20 > V_21 )
return;
if ( V_20 == V_23 )
return;
if ( ! V_22 )
goto V_24;
for ( V_4 = 0 ; V_4 < V_7 -> V_12 ; V_4 ++ ) {
T_2 V_25 , V_26 ;
T_2 V_27 , V_28 ;
V_14 = & V_7 -> V_14 [ V_4 ] ;
if ( V_14 -> V_16 != V_16 )
continue;
V_27 = F_6 ( V_14 -> V_20 , V_20 ) ;
V_28 = F_7 ( V_14 -> V_21 , V_21 ) ;
if ( V_27 > V_28 + 1 )
continue;
V_25 = F_7 ( V_14 -> V_20 , V_20 ) ;
V_26 = F_6 ( V_14 -> V_21 , V_21 ) ;
V_14 -> V_20 = V_25 ;
V_14 -> V_21 = V_26 ;
return;
}
V_24:
if ( V_7 -> V_12 >= V_29 )
return;
V_14 = & V_7 -> V_14 [ V_7 -> V_12 ] ;
V_14 -> V_30 = V_7 -> V_30 ;
V_14 -> V_16 = V_16 ;
V_14 -> V_20 = V_20 ;
V_14 -> V_21 = V_21 ;
V_14 -> V_31 = NULL ;
V_7 -> V_12 ++ ;
}
