static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
if ( ! V_2 -> V_4 )
return - V_5 ;
V_6 -> V_7 = V_2 ;
V_3 = F_2 ( V_6 -> V_8 + V_6 -> V_9 . V_10 ) ;
V_3 &= ~ V_6 -> V_9 . V_11 ;
V_3 |= V_2 -> V_11 & V_6 -> V_9 . V_11 ;
F_3 ( V_3 , V_6 -> V_8 + V_6 -> V_9 . V_10 ) ;
return 0 ;
}
static int F_4 ( struct V_12 * * V_13 , T_2 V_14 )
{
T_1 V_3 , V_15 , V_11 ;
if ( ! V_14 )
return - V_16 ;
V_3 = F_2 ( V_6 -> V_8 + V_6 -> V_17 . V_10 ) ;
for ( V_15 = 0 ; V_15 < V_14 ; V_15 ++ ) {
T_2 V_18 = 0 ;
if ( ! V_13 [ V_15 ] -> V_4 || ! V_13 [ V_15 ] -> V_19 ) {
F_5 ( V_20 L_1 ) ;
continue;
}
if ( V_6 -> V_7 ) {
bool V_21 = false ;
for ( V_18 = 0 ; V_18 < V_13 [ V_15 ] -> V_22 ; V_18 ++ ) {
if ( V_13 [ V_15 ] -> V_19 [ V_18 ] . V_23 &
V_6 -> V_7 -> V_24 ) {
V_21 = true ;
break;
}
}
if ( V_21 == false ) {
F_5 ( V_20 L_2\
L_3 , V_13 [ V_15 ] -> V_4 ,
V_6 -> V_7 -> V_4 ) ;
continue;
}
}
V_11 = V_13 [ V_15 ] -> V_19 [ V_18 ] . V_11 & V_6 -> V_17 . V_11 ;
if ( V_13 [ V_15 ] -> V_25 )
V_3 &= ~ V_11 ;
else
V_3 |= V_11 ;
V_13 [ V_15 ] -> V_26 = true ;
}
F_3 ( V_3 , V_6 -> V_8 + V_6 -> V_17 . V_10 ) ;
F_6 ( V_6 ) ;
V_6 = (struct V_6 * ) - 1 ;
return 0 ;
}
int F_7 ( struct V_27 * V_28 )
{
int V_29 = 0 ;
if ( V_6 )
return - V_30 ;
if ( ! V_28 -> V_8 || ! V_28 -> V_13 )
return - V_5 ;
V_6 = F_8 ( sizeof( * V_6 ) , V_31 ) ;
if ( ! V_6 )
return - V_32 ;
V_6 -> V_8 = ( T_1 ) V_28 -> V_8 ;
V_6 -> V_9 . V_10 = V_28 -> V_9 . V_10 ;
V_6 -> V_9 . V_11 = V_28 -> V_9 . V_11 ;
V_6 -> V_17 . V_10 = V_28 -> V_17 . V_10 ;
V_6 -> V_17 . V_11 = V_28 -> V_17 . V_11 ;
if ( V_28 -> V_2 ) {
V_29 = F_1 ( V_28 -> V_2 ) ;
if ( V_29 )
goto V_33;
}
V_29 = F_4 ( V_28 -> V_13 , V_28 -> V_34 ) ;
if ( V_29 )
goto V_33;
return 0 ;
V_33:
return V_29 ;
}
