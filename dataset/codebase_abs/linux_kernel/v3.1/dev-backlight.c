static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_4 * V_5 =
F_2 ( V_2 -> V_6 , struct V_4 , V_2 ) ;
struct V_7 * V_8 =
V_5 -> V_2 . V_9 ;
V_3 = F_3 ( V_8 -> V_10 , L_1 ) ;
if ( V_3 ) {
F_4 ( V_11 L_2 ) ;
return V_3 ;
}
F_5 ( V_8 -> V_10 , V_8 -> V_12 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 =
F_2 ( V_2 -> V_6 , struct V_4 , V_2 ) ;
struct V_7 * V_8 =
V_5 -> V_2 . V_9 ;
F_5 ( V_8 -> V_10 , V_13 ) ;
F_7 ( V_8 -> V_10 ) ;
}
void F_8 ( struct V_7 * V_14 ,
struct V_15 * V_16 )
{
int V_3 = 0 ;
struct V_4 * V_17 ;
struct V_15 * V_18 ;
V_17 = F_9 ( & V_19 ,
sizeof( struct V_4 ) , V_20 ) ;
if ( ! V_17 ) {
F_4 ( V_11 L_3 , V_21 ) ;
return;
}
V_18 = F_10 ( & V_22 ,
sizeof( struct V_15 ) , V_17 ) ;
if ( ! V_18 ) {
F_4 ( V_11 L_3 , V_21 ) ;
goto V_23;
}
V_18 -> V_24 = V_16 -> V_24 ;
V_17 -> V_2 . V_6 =
& V_25 [ V_18 -> V_24 ] . V_2 ;
if ( V_16 -> V_26 )
V_18 -> V_26 = V_16 -> V_26 ;
if ( V_16 -> V_27 )
V_18 -> V_27 = V_16 -> V_27 ;
if ( V_16 -> V_28 )
V_18 -> V_28 = V_16 -> V_28 ;
if ( V_16 -> V_29 )
V_18 -> V_29 = V_16 -> V_29 ;
if ( V_16 -> V_30 )
V_18 -> V_30 = V_16 -> V_30 ;
if ( V_16 -> V_31 )
V_18 -> V_31 = V_16 -> V_31 ;
if ( V_16 -> exit )
V_18 -> exit = V_16 -> exit ;
if ( V_16 -> V_32 )
V_18 -> V_32 = V_16 -> V_32 ;
V_25 [ V_18 -> V_24 ] . V_2 . V_9 = V_14 ;
V_3 = F_11 (
& V_25 [ V_18 -> V_24 ] ) ;
if ( V_3 ) {
F_4 ( V_11 L_4 , V_3 ) ;
goto V_33;
}
V_3 = F_11 ( V_17 ) ;
if ( V_3 ) {
F_4 ( V_11 L_5 , V_3 ) ;
goto V_34;
}
return;
V_34:
F_12 ( & V_25 [ V_18 -> V_24 ] ) ;
V_33:
F_13 ( V_18 ) ;
V_23:
F_13 ( V_17 ) ;
return;
}
