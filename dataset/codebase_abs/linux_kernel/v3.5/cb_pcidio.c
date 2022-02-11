static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = NULL ;
int V_7 ;
int V_8 ;
if ( F_2 ( V_2 , sizeof( struct V_9 ) ) < 0 )
return - V_10 ;
F_3 (pcidev) {
if ( V_6 -> V_11 != V_12 )
continue;
for ( V_7 = 0 ; V_7 < F_4 ( V_13 ) ; V_7 ++ ) {
if ( V_13 [ V_7 ] . V_14 != V_6 -> V_15 )
continue;
if ( V_4 -> V_16 [ 0 ] || V_4 -> V_16 [ 1 ] ) {
if ( V_6 -> V_17 -> V_18 != V_4 -> V_16 [ 0 ] ||
F_5 ( V_6 -> V_19 ) != V_4 -> V_16 [ 1 ] ) {
continue;
}
}
V_2 -> V_20 = V_13 + V_7 ;
goto V_21;
}
}
F_6 ( V_2 -> V_22 , L_1 ) ;
return - V_23 ;
V_21:
V_2 -> V_24 = V_25 -> V_26 ;
V_27 -> V_5 = V_6 ;
F_7 ( V_2 -> V_22 , L_2 , V_25 -> V_26 ,
V_27 -> V_5 -> V_17 -> V_18 ,
F_5 ( V_27 -> V_5 -> V_19 ) ) ;
if ( F_8 ( V_6 , V_25 -> V_26 ) )
return - V_23 ;
V_27 -> V_28
=
F_9 ( V_27 -> V_5 ,
V_13 [ V_7 ] . V_29 ) ;
if ( F_10 ( V_2 , V_25 -> V_30 ) < 0 )
return - V_10 ;
for ( V_8 = 0 ; V_8 < V_25 -> V_30 ; V_8 ++ ) {
F_11 ( V_2 , V_2 -> V_31 + V_8 ,
NULL , V_27 -> V_28 + V_8 * 4 ) ;
F_7 ( V_2 -> V_22 , L_3 , V_8 ,
V_27 -> V_28 + V_8 * 4 ) ;
}
return 1 ;
}
static void F_12 ( struct V_1 * V_2 )
{
if ( V_27 ) {
if ( V_27 -> V_5 ) {
if ( V_27 -> V_28 )
F_13 ( V_27 -> V_5 ) ;
F_14 ( V_27 -> V_5 ) ;
}
}
if ( V_2 -> V_31 ) {
int V_8 ;
for ( V_8 = 0 ; V_8 < V_25 -> V_30 ; V_8 ++ )
F_15 ( V_2 , V_2 -> V_31 + V_8 ) ;
}
}
static int T_1 F_16 ( struct V_5 * V_2 ,
const struct V_32 * V_33 )
{
return F_17 ( V_2 , & V_34 ) ;
}
static void T_2 F_18 ( struct V_5 * V_2 )
{
F_19 ( V_2 ) ;
}
