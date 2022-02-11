static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 , V_9 ;
if ( V_4 -> V_10 >= 0 )
F_2 ( V_7 , V_11 ,
F_3 ( V_4 -> V_10 ) ^ V_4 -> V_12 ) ;
if ( V_4 -> V_13 >= 0 )
F_2 ( V_7 , V_14 ,
F_3 ( V_4 -> V_13 ) ^ V_4 -> V_12 ) ;
if ( V_4 -> V_15 >= 0 )
F_2 ( V_7 , V_16 ,
F_3 ( V_4 -> V_15 ) ^ V_4 -> V_12 ) ;
V_8 = ( F_3 ( V_4 -> V_17 ) ^ V_4 -> V_12 )
- ( F_3 ( V_4 -> V_18 ) ^ V_4 -> V_12 ) ;
V_9 = ( F_3 ( V_4 -> V_19 ) ^ V_4 -> V_12 )
- ( F_3 ( V_4 -> V_20 ) ^ V_4 -> V_12 ) ;
F_4 ( V_7 , V_21 , V_8 ) ;
F_4 ( V_7 , V_22 , V_9 ) ;
F_5 ( V_7 ) ;
}
static int T_1 F_6 ( struct V_23 * V_24 )
{
struct V_3 * V_25 = V_24 -> V_2 . V_26 ;
struct V_1 * V_27 ;
struct V_6 * V_7 ;
int V_28 , V_29 ;
int error ;
if ( ! V_25 ) {
F_7 ( & V_24 -> V_2 , L_1 ) ;
error = - V_30 ;
goto V_31;
}
if ( V_25 -> V_32 < 0 ) {
F_7 ( & V_24 -> V_2 , L_2 ) ;
error = - V_33 ;
goto V_31;
}
for ( V_29 = 0 ; V_29 < V_34 ; V_29 ++ ) {
V_28 = V_25 -> V_35 [ V_29 ] ;
if ( V_28 < 0 ) {
if ( V_29 <= V_36 ) {
F_7 ( & V_24 -> V_2 ,
L_3 ) ;
error = - V_33 ;
goto V_37;
}
if ( V_29 == V_38 )
F_8 ( & V_24 -> V_2 , L_4 ) ;
} else {
error = F_9 ( V_28 , L_5 ) ;
if ( error ) {
F_7 ( & V_24 -> V_2 , L_6 ,
V_28 , V_29 ) ;
goto V_37;
}
F_10 ( V_28 ) ;
}
}
V_27 = F_11 () ;
if ( ! V_27 ) {
F_7 ( & V_24 -> V_2 , L_7 ) ;
error = - V_39 ;
goto V_37;
}
F_12 ( V_24 , V_27 ) ;
V_27 -> V_5 = V_25 ;
V_27 -> V_40 = F_1 ;
V_27 -> V_41 = V_25 -> V_32 ;
V_7 = V_27 -> V_7 ;
V_7 -> V_42 = V_24 -> V_42 ;
V_7 -> V_43 . V_44 = V_45 ;
V_7 -> V_2 . V_46 = & V_24 -> V_2 ;
F_13 ( V_7 , V_47 , V_21 ) ;
F_13 ( V_7 , V_47 , V_22 ) ;
if ( V_25 -> V_10 >= 0 )
F_13 ( V_7 , V_48 , V_11 ) ;
if ( V_25 -> V_13 >= 0 )
F_13 ( V_7 , V_48 , V_14 ) ;
if ( V_25 -> V_15 >= 0 )
F_13 ( V_7 , V_48 , V_16 ) ;
error = F_14 ( V_27 ) ;
if ( error ) {
F_7 ( & V_24 -> V_2 , L_8 ) ;
goto V_49;
}
F_8 ( & V_24 -> V_2 , L_9 ,
V_25 -> V_32 ,
V_25 -> V_10 < 0 ? L_10 : L_11 ,
V_25 -> V_13 < 0 ? L_10 : L_12 ,
V_25 -> V_15 < 0 ? L_10 : L_13 ) ;
return 0 ;
V_49:
F_15 ( V_27 ) ;
F_12 ( V_24 , NULL ) ;
V_37:
while ( -- V_29 >= 0 ) {
V_28 = V_25 -> V_35 [ V_29 ] ;
if ( V_28 )
F_16 ( V_28 ) ;
}
V_31:
return error ;
}
static int T_2 F_17 ( struct V_23 * V_24 )
{
struct V_1 * V_7 = F_18 ( V_24 ) ;
struct V_3 * V_25 = V_7 -> V_5 ;
int V_28 , V_29 ;
F_19 ( V_7 ) ;
F_15 ( V_7 ) ;
for ( V_29 = 0 ; V_29 < V_34 ; V_29 ++ ) {
V_28 = V_25 -> V_35 [ V_29 ] ;
if ( V_28 >= 0 )
F_16 ( V_28 ) ;
}
F_12 ( V_24 , NULL ) ;
return 0 ;
}
