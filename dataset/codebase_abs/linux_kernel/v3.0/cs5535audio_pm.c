static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 , V_4 ) ;
}
int F_3 ( struct V_5 * V_6 , T_1 V_7 )
{
struct V_8 * V_9 = F_4 ( V_6 ) ;
struct V_1 * V_2 = V_9 -> V_10 ;
int V_11 ;
F_5 ( V_9 , V_12 ) ;
F_6 ( V_2 -> V_13 ) ;
F_7 ( V_2 -> V_14 ) ;
for ( V_11 = 0 ; V_11 < V_15 ; V_11 ++ ) {
struct V_16 * V_17 = & V_2 -> V_18 [ V_11 ] ;
if ( V_17 && V_17 -> V_19 )
V_17 -> V_20 = V_17 -> V_21 -> V_22 ( V_2 ) ;
}
F_1 ( V_2 ) ;
if ( F_8 ( V_6 ) ) {
F_9 ( V_23 L_1 ) ;
return - V_24 ;
}
F_10 ( V_6 ) ;
F_11 ( V_6 , F_12 ( V_6 , V_7 ) ) ;
return 0 ;
}
int F_13 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = F_4 ( V_6 ) ;
struct V_1 * V_2 = V_9 -> V_10 ;
T_2 V_25 ;
int V_26 ;
int V_11 ;
F_11 ( V_6 , V_27 ) ;
F_14 ( V_6 ) ;
if ( F_15 ( V_6 ) < 0 ) {
F_9 ( V_23 L_2
L_3 ) ;
F_16 ( V_9 ) ;
return - V_24 ;
}
F_17 ( V_6 ) ;
F_2 ( V_2 , V_3 , V_28 ) ;
V_26 = 50 ;
do {
V_25 = F_18 ( V_2 , V_29 ) ;
if ( V_25 & V_30 )
break;
F_19 ( 1 ) ;
} while ( -- V_26 );
if ( ! V_26 )
F_20 ( V_23 L_4 ) ;
for ( V_11 = 0 ; V_11 < V_15 ; V_11 ++ ) {
struct V_16 * V_17 = & V_2 -> V_18 [ V_11 ] ;
if ( V_17 && V_17 -> V_19 ) {
V_17 -> V_19 -> V_21 -> V_31 ( V_17 -> V_19 ) ;
V_17 -> V_21 -> V_32 ( V_2 , V_17 -> V_20 ) ;
}
}
F_21 ( V_2 -> V_14 ) ;
F_5 ( V_9 , V_33 ) ;
return 0 ;
}
