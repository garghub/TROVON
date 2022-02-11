int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = V_2 -> V_7 -> V_3 -> V_8 ;
int V_9 , V_10 ;
struct V_11 * V_7 = V_2 -> V_7 ;
V_4 = F_2 ( V_6 , F_3 ( V_2 -> V_12 , 0 ) ) ;
if ( V_4 ) {
F_4 ( V_7 , L_1
L_2 , F_5 ( V_4 ) ,
F_6 ( V_6 ) , V_2 -> V_13 , V_2 -> V_12 ) ;
F_7 ( V_4 ) ;
return - V_14 ;
}
V_9 = F_8 ( V_6 , F_3 ( V_2 -> V_12 , 0 ) ) ;
if ( V_9 == 0 ) {
F_4 ( V_7 , L_3 ) ;
return - V_15 ;
}
for ( V_10 = 0 ; V_10 < 8 ; V_10 ++ ) {
V_4 = F_2 ( V_6 , F_3 ( V_2 -> V_12 , V_10 ) ) ;
if ( ! V_4 )
continue;
if ( ( V_4 -> V_16 == V_17 ) ||
( V_4 -> V_16 == V_18 ) ) {
struct V_5 * V_19 ;
unsigned char V_20 , V_21 = V_6 -> V_22 ;
unsigned char V_23 = V_6 -> V_8 ;
for ( V_20 = V_21 ; V_20 <= V_23 ; V_20 ++ ) {
if ( ! F_9 ( F_6 ( V_6 ) ,
V_20 ) )
break;
}
if ( V_20 > V_23 ) {
F_4 ( V_7 ,
L_4 ) ;
F_7 ( V_4 ) ;
continue;
}
V_19 = F_10 ( V_6 , V_4 , V_20 ) ;
if ( ! V_19 ) {
F_4 ( V_7 , L_5 ,
F_5 ( V_4 ) ) ;
F_7 ( V_4 ) ;
continue;
}
V_19 -> V_8 = F_11 ( V_19 ) ;
F_12 ( V_19 ) ;
}
F_13 ( V_4 ) ;
F_7 ( V_4 ) ;
}
F_14 ( V_6 ) ;
F_15 ( V_6 ) ;
F_16 ( V_6 ) ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 )
{
int V_24 = 0 ;
int V_25 ;
T_2 V_26 = 0 ;
struct V_5 * V_6 = V_2 -> V_7 -> V_3 -> V_8 ;
struct V_11 * V_7 = V_2 -> V_7 ;
F_18 ( V_7 , L_6 ,
V_27 , F_6 ( V_6 ) , V_2 -> V_13 , V_2 -> V_12 ) ;
for ( V_25 = 0 ; V_25 < 8 ; V_25 ++ ) {
struct V_3 * V_28 = F_2 ( V_6 ,
( V_2 -> V_12 << 3 ) | V_25 ) ;
if ( ! V_28 )
continue;
if ( V_28 -> V_16 == V_17 ) {
F_19 ( V_28 , V_29 , & V_26 ) ;
if ( V_26 & V_30 ) {
F_4 ( V_7 ,
L_7 ,
F_5 ( V_28 ) ) ;
F_7 ( V_28 ) ;
V_24 = - V_14 ;
break;
}
}
F_20 ( V_28 ) ;
F_7 ( V_28 ) ;
}
return V_24 ;
}
