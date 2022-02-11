static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
int V_6 ;
V_6 = F_3 ( V_4 , L_1 ) ;
if ( V_6 > 0 )
goto V_7;
if ( V_6 == - V_8 )
goto V_7;
V_6 = F_3 ( V_4 , L_2 ) ;
if ( V_6 > 0 )
goto V_7;
if ( V_6 == - V_8 )
goto V_7;
V_6 = F_4 ( V_4 , 0 ) ;
if ( V_6 > 0 )
goto V_7;
if ( V_6 != - V_8 )
F_5 ( V_2 -> V_5 , L_3 ) ;
if ( ! V_6 )
V_6 = - V_9 ;
V_7:
return V_6 ;
}
int F_6 ( struct V_1 * V_2 )
{
struct V_10 V_11 [ 3 ] ;
struct V_3 * V_12 ;
int V_13 , V_6 ;
struct V_14 * V_15 ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
int V_16 = 0 ;
V_6 = F_1 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
V_15 = F_7 ( V_4 , V_17 , L_1 ) ;
if ( ! V_15 )
V_15 = F_7 ( V_4 , V_17 ,
L_2 ) ;
if ( ! V_15 )
V_15 = F_8 ( V_4 , V_17 , 0 ) ;
if ( ! V_15 )
return - V_18 ;
V_2 -> V_19 [ 1 ] . V_20 = V_6 ;
V_2 -> V_19 [ 1 ] . V_21 = V_6 ;
V_2 -> V_19 [ 1 ] . V_22 = V_15 -> V_22 ;
V_2 -> V_19 [ 1 ] . V_23 = V_15 -> V_23 ;
V_12 = F_9 ( L_4 , V_24 ) ;
if ( ! V_12 ) {
F_5 ( V_2 -> V_5 , L_5 ) ;
return - V_18 ;
}
V_12 -> V_5 . V_25 = V_2 -> V_5 ;
V_2 -> V_12 = V_12 ;
V_13 = F_10 ( V_12 , V_2 -> V_19 ,
V_26 ) ;
if ( V_13 ) {
F_5 ( V_2 -> V_5 , L_6 ) ;
goto V_27;
}
memset ( V_11 , 0 , sizeof( struct V_10 ) * F_11 ( V_11 ) ) ;
if ( V_2 -> V_28 )
V_11 [ V_16 ++ ] . V_23 = L_7 ;
if ( V_2 -> V_29 <= V_30 )
V_11 [ V_16 ++ ] . V_23 = L_8 ;
if ( V_16 ) {
V_13 = F_12 ( V_12 , V_11 ) ;
if ( V_13 ) {
F_5 ( V_2 -> V_5 , L_9 ) ;
goto V_27;
}
}
F_13 ( V_2 -> V_31 , L_10 ,
F_14 ( V_2 -> V_5 ) ) ;
F_13 ( V_2 -> V_32 , L_11 ,
F_14 ( V_2 -> V_5 ) ) ;
V_13 = F_15 ( V_12 ) ;
if ( V_13 ) {
F_5 ( V_2 -> V_5 , L_12 ) ;
goto V_33;
}
return 0 ;
V_33:
F_16 ( V_2 -> V_31 , L_10 ,
F_14 ( V_2 -> V_5 ) ) ;
F_16 ( V_2 -> V_32 , L_11 ,
F_14 ( V_2 -> V_5 ) ) ;
V_27:
F_17 ( V_12 ) ;
return V_13 ;
}
void F_18 ( struct V_1 * V_2 )
{
F_16 ( V_2 -> V_31 , L_10 ,
F_14 ( V_2 -> V_5 ) ) ;
F_16 ( V_2 -> V_32 , L_11 ,
F_14 ( V_2 -> V_5 ) ) ;
F_19 ( V_2 -> V_12 ) ;
}
