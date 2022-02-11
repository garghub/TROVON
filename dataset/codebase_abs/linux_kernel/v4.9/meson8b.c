static int F_1 ( struct V_1 * V_2 )
{
void T_1 * V_3 ;
int V_4 , V_5 , V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 = & V_2 -> V_12 ;
V_3 = F_2 ( V_12 -> V_13 , 1 ) ;
if ( ! V_3 ) {
F_3 ( L_1 , V_14 ) ;
return - V_15 ;
}
for ( V_6 = 0 ; V_6 < F_4 ( V_16 ) ; V_6 ++ )
V_16 [ V_6 ] -> V_17 = V_3 ;
V_18 . V_17 = V_3 ;
V_19 . V_20 = V_3 + ( V_21 ) V_19 . V_20 ;
V_22 . V_20 = V_3 + ( V_21 ) V_22 . V_20 ;
V_23 . V_20 = V_3 + ( V_21 ) V_23 . V_20 ;
for ( V_6 = 0 ; V_6 < F_4 ( V_24 ) ; V_6 ++ )
V_24 [ V_6 ] -> V_20 = V_3 +
( V_21 ) V_24 [ V_6 ] -> V_20 ;
for ( V_5 = V_25 ; V_5 < V_26 ; V_5 ++ ) {
if ( ! V_27 . V_28 [ V_5 ] )
continue;
V_4 = F_5 ( V_12 , V_27 . V_28 [ V_5 ] ) ;
if ( V_4 )
goto V_29;
}
V_8 = F_6 ( & V_18 . V_30 ) ;
V_10 = V_8 -> V_9 ;
V_4 = F_7 ( V_10 , & V_18 . V_31 ) ;
if ( V_4 ) {
F_3 ( L_2 ,
V_14 ) ;
goto V_29;
}
return F_8 ( V_12 -> V_13 , V_32 ,
& V_27 ) ;
V_29:
V_29 ( V_3 ) ;
return V_4 ;
}
