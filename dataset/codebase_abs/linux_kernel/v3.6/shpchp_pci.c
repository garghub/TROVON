int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_3 * V_7 = V_6 -> V_3 ;
struct V_8 * V_9 = V_7 -> V_10 ;
int V_11 , V_12 ;
V_4 = F_2 ( V_9 , F_3 ( V_2 -> V_13 , 0 ) ) ;
if ( V_4 ) {
F_4 ( V_6 , L_1
L_2 , F_5 ( V_4 ) ,
F_6 ( V_9 ) , V_2 -> V_14 , V_2 -> V_13 ) ;
F_7 ( V_4 ) ;
return - V_15 ;
}
V_11 = F_8 ( V_9 , F_3 ( V_2 -> V_13 , 0 ) ) ;
if ( V_11 == 0 ) {
F_4 ( V_6 , L_3 ) ;
return - V_16 ;
}
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ ) {
V_4 = F_2 ( V_9 , F_3 ( V_2 -> V_13 , V_12 ) ) ;
if ( ! V_4 )
continue;
if ( ( V_4 -> V_17 == V_18 ) ||
( V_4 -> V_17 == V_19 ) )
F_9 ( V_4 ) ;
F_7 ( V_4 ) ;
}
F_10 ( V_7 ) ;
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ ) {
V_4 = F_2 ( V_9 , F_3 ( V_2 -> V_13 , V_12 ) ) ;
if ( ! V_4 )
continue;
F_11 ( V_4 ) ;
F_7 ( V_4 ) ;
}
F_12 ( V_9 ) ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 )
{
int V_20 = 0 ;
int V_21 ;
T_2 V_22 = 0 ;
struct V_8 * V_9 = V_2 -> V_6 -> V_3 -> V_10 ;
struct V_5 * V_6 = V_2 -> V_6 ;
F_14 ( V_6 , L_4 ,
V_23 , F_6 ( V_9 ) , V_2 -> V_14 , V_2 -> V_13 ) ;
for ( V_21 = 0 ; V_21 < 8 ; V_21 ++ ) {
struct V_3 * V_24 = F_2 ( V_9 ,
( V_2 -> V_13 << 3 ) | V_21 ) ;
if ( ! V_24 )
continue;
if ( V_24 -> V_17 == V_18 ) {
F_15 ( V_24 , V_25 , & V_22 ) ;
if ( V_22 & V_26 ) {
F_4 ( V_6 ,
L_5 ,
F_5 ( V_24 ) ) ;
F_7 ( V_24 ) ;
V_20 = - V_15 ;
break;
}
}
F_16 ( V_24 ) ;
F_7 ( V_24 ) ;
}
return V_20 ;
}
