static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void T_1 * V_5 ,
void T_1 * V_6 ,
T_2 V_7 )
{
const struct V_8 * V_9 ;
T_2 V_10 , V_11 ;
T_2 V_12 ;
int V_13 ;
int V_14 ;
V_9 = & V_15 [ V_7 ] ;
V_12 = F_2 ( V_5 ) ;
V_12 |= V_9 -> V_16 ;
F_3 ( V_12 , V_5 ) ;
F_4 ( V_4 , L_1 , V_7 ) ;
V_10 = 0 ;
V_11 = 0 ;
for ( V_14 = 0 ; V_14 < F_5 ( V_17 ) ; V_14 ++ ) {
const struct V_18 * V_19 = & V_17 [ V_14 ] ;
V_13 = F_6 ( V_2 , V_19 -> V_20 , & V_12 ) ;
if ( V_13 ) {
F_4 ( V_4 , L_2 ,
V_19 -> V_20 , V_7 ) ;
continue;
}
if ( V_19 -> V_21 == 1 && V_12 ) {
if ( V_19 -> V_22 )
V_10 |= F_7 ( V_19 -> V_23 ) ;
else
V_11 |= F_7 ( V_19 -> V_23 ) ;
F_4 ( V_4 , L_3 , V_19 -> V_20 ) ;
continue;
}
if ( V_12 > V_19 -> V_21 ) {
F_8 ( V_4 ,
L_4 ,
V_19 -> V_20 , V_12 , V_19 -> V_21 ) ;
V_12 = V_19 -> V_21 ;
}
if ( V_19 -> V_22 )
V_10 |= ( V_12 << V_19 -> V_23 ) ;
else
V_11 |= ( V_12 << V_19 -> V_23 ) ;
F_4 ( V_4 , L_5 , V_19 -> V_20 , V_12 ) ;
}
F_9 ( V_4 , L_6 ,
V_7 , V_10 , V_11 ) ;
if ( V_10 )
F_3 ( V_10 , V_6 + V_9 -> V_24 ) ;
if ( V_11 )
F_3 ( V_11 , V_6 + V_9 -> V_25 ) ;
}
static int F_10 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_4 . V_28 ;
struct V_1 * V_29 ;
struct V_3 * V_4 = & V_27 -> V_4 ;
struct V_30 * V_31 ;
void T_1 * V_5 ;
void T_1 * V_6 ;
struct V_32 * V_33 ;
struct V_32 * V_34 ;
bool V_35 = false ;
T_2 V_12 ;
int V_13 ;
V_33 = F_11 ( V_4 , L_7 ) ;
if ( F_12 ( V_33 ) )
return F_13 ( V_33 ) ;
V_13 = F_14 ( V_33 ) ;
if ( V_13 ) {
F_8 ( V_4 , L_8 , V_13 ) ;
return V_13 ;
}
V_34 = F_11 ( V_4 , L_9 ) ;
if ( F_12 ( V_34 ) ) {
V_13 = F_13 ( V_34 ) ;
goto V_36;
}
V_13 = F_14 ( V_34 ) ;
if ( V_13 ) {
F_8 ( V_4 , L_10 ) ;
goto V_36;
}
V_31 = F_15 ( V_27 , V_37 , 0 ) ;
V_5 = F_16 ( V_4 , V_31 ) ;
if ( F_12 ( V_5 ) ) {
V_13 = F_13 ( V_5 ) ;
goto V_38;
}
V_31 = F_15 ( V_27 , V_37 , 1 ) ;
V_6 = F_16 ( V_4 , V_31 ) ;
if ( F_12 ( V_6 ) ) {
V_13 = F_13 ( V_6 ) ;
goto V_38;
}
F_3 ( 0UL , V_6 + V_39 ) ;
V_12 = F_2 ( V_5 ) ;
V_12 &= ~ V_40 ;
F_3 ( V_12 , V_5 ) ;
F_17 (np, child) {
T_2 V_7 ;
V_13 = F_6 ( V_29 , L_11 , & V_7 ) ;
if ( V_13 )
return V_13 ;
if ( V_7 > 5 ) {
F_8 ( V_4 ,
L_12 ,
V_7 ) ;
continue;
}
F_1 ( V_29 ,
V_4 ,
V_5 ,
V_6 ,
V_7 ) ;
V_35 = true ;
}
if ( V_35 )
return F_18 ( V_2 , NULL , V_4 ) ;
return 0 ;
V_38:
F_19 ( V_34 ) ;
V_36:
F_19 ( V_33 ) ;
return V_13 ;
}
