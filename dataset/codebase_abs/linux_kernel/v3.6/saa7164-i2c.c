static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
int V_11 , V_12 = 0 ;
F_2 ( V_13 , L_1 , V_14 , V_5 ) ;
for ( V_11 = 0 ; V_11 < V_5 ; V_11 ++ ) {
F_2 ( V_13 , L_2 ,
V_14 , V_5 , V_4 [ V_11 ] . V_15 , V_4 [ V_11 ] . V_16 ) ;
if ( V_4 [ V_11 ] . V_17 & V_18 ) {
F_3 ( V_19 L_3 , V_14 ) ;
continue;
} else if ( V_11 + 1 < V_5 && ( V_4 [ V_11 + 1 ] . V_17 & V_18 ) &&
V_4 [ V_11 ] . V_15 == V_4 [ V_11 + 1 ] . V_15 ) {
V_12 = F_4 ( V_7 , V_4 [ V_11 ] . V_15 ,
V_4 [ V_11 ] . V_16 , V_4 [ V_11 ] . V_20 ,
V_4 [ V_11 + 1 ] . V_16 , V_4 [ V_11 + 1 ] . V_20
) ;
V_11 ++ ;
if ( V_12 < 0 )
goto V_21;
} else {
V_12 = F_5 ( V_7 , V_4 [ V_11 ] . V_15 ,
V_4 [ V_11 ] . V_16 , V_4 [ V_11 ] . V_20 ) ;
}
if ( V_12 < 0 )
goto V_21;
}
return V_5 ;
V_21:
return V_12 ;
}
static T_1 F_6 ( struct V_1 * V_22 )
{
return V_23 ;
}
int F_7 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = V_7 -> V_10 ;
F_2 ( V_13 , L_4 , V_14 , V_7 -> V_24 ) ;
V_7 -> V_2 = V_25 ;
V_7 -> V_26 = V_27 ;
V_7 -> V_2 . V_10 . V_28 = & V_10 -> V_29 -> V_10 ;
F_8 ( V_7 -> V_2 . V_30 , V_7 -> V_10 -> V_30 ,
sizeof( V_7 -> V_2 . V_30 ) ) ;
V_7 -> V_2 . V_8 = V_7 ;
F_9 ( & V_7 -> V_2 , V_7 ) ;
F_10 ( & V_7 -> V_2 ) ;
V_7 -> V_26 . V_31 = & V_7 -> V_2 ;
if ( 0 != V_7 -> V_32 )
F_3 ( V_19 L_5 ,
V_10 -> V_30 , V_7 -> V_24 ) ;
return V_7 -> V_32 ;
}
int F_11 ( struct V_6 * V_7 )
{
F_12 ( & V_7 -> V_2 ) ;
return 0 ;
}
