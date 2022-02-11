static int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 , V_7 , V_8 = V_4 -> V_9 ;
int V_10 = V_4 -> V_11 ;
for ( V_7 = V_8 ; V_7 <= V_10 ; V_7 ++ ) {
if ( ! F_2 ( F_3 ( V_4 ) , V_7 ) )
break;
}
if ( V_7 -- > V_10 ) {
F_4 ( L_1 ,
F_5 ( V_2 ) ) ;
return - 1 ;
}
for ( V_6 = 0 ; V_6 < 2 ; V_6 ++ )
V_7 = F_6 ( V_4 , V_2 , V_7 , V_6 ) ;
if ( ! V_2 -> V_11 )
return - 1 ;
return 0 ;
}
int F_7 ( struct V_12 * V_13 )
{
struct V_1 * V_2 ;
struct V_1 * V_14 = V_13 -> V_15 -> V_16 -> V_17 ;
struct V_3 * V_4 = V_14 -> V_11 ;
int V_18 , V_19 ;
struct V_20 * V_15 = V_13 -> V_15 ;
V_2 = F_8 ( V_4 , F_9 ( 0 , 0 ) ) ;
if ( V_2 ) {
F_10 ( V_15 , L_2
L_3 , F_5 ( V_2 ) ,
F_3 ( V_4 ) , V_4 -> V_21 ) ;
F_11 ( V_2 ) ;
return - V_22 ;
}
V_18 = F_12 ( V_4 , F_9 ( 0 , 0 ) ) ;
if ( V_18 == 0 ) {
F_10 ( V_15 , L_4 ) ;
return - V_23 ;
}
for ( V_19 = 0 ; V_19 < 8 ; V_19 ++ ) {
V_2 = F_8 ( V_4 , F_9 ( 0 , V_19 ) ) ;
if ( ! V_2 )
continue;
if ( ( V_2 -> V_24 == V_25 ) ||
( V_2 -> V_24 == V_26 ) ) {
F_1 ( V_2 ) ;
}
F_11 ( V_2 ) ;
}
F_13 ( V_14 ) ;
for ( V_19 = 0 ; V_19 < 8 ; V_19 ++ ) {
V_2 = F_8 ( V_4 , F_9 ( 0 , V_19 ) ) ;
if ( ! V_2 )
continue;
if ( ( V_2 -> V_27 >> 16 ) == V_28 ) {
F_11 ( V_2 ) ;
continue;
}
F_14 ( V_2 ) ;
F_11 ( V_2 ) ;
}
F_15 ( V_4 ) ;
return 0 ;
}
int F_16 ( struct V_12 * V_13 )
{
int V_29 , V_30 = 0 ;
int V_31 ;
T_2 V_32 = 0 ;
T_2 V_33 = 0 ;
struct V_3 * V_4 = V_13 -> V_15 -> V_16 -> V_17 -> V_11 ;
T_3 V_34 ;
struct V_20 * V_15 = V_13 -> V_15 ;
F_17 ( V_15 , L_5 ,
V_35 , F_3 ( V_4 ) , V_4 -> V_21 ) ;
V_29 = F_18 ( V_13 , & V_33 ) ;
if ( V_29 )
V_33 = 0 ;
for ( V_31 = 0 ; V_31 < 8 ; V_31 ++ ) {
struct V_1 * V_36 = F_8 ( V_4 , F_9 ( 0 , V_31 ) ) ;
if ( ! V_36 )
continue;
if ( V_36 -> V_24 == V_25 && V_33 ) {
F_19 ( V_36 , V_37 , & V_32 ) ;
if ( V_32 & V_38 ) {
F_10 ( V_15 ,
L_6 ,
F_5 ( V_36 ) ) ;
F_11 ( V_36 ) ;
V_30 = - V_22 ;
break;
}
}
F_20 ( V_36 ) ;
if ( V_33 ) {
F_21 ( V_36 , V_39 , & V_34 ) ;
V_34 &= ~ ( V_40 | V_41 ) ;
V_34 |= V_42 ;
F_22 ( V_36 , V_39 , V_34 ) ;
}
F_11 ( V_36 ) ;
}
return V_30 ;
}
