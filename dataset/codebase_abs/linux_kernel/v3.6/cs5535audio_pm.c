static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 , V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
struct V_9 * V_10 = F_5 ( V_6 ) ;
struct V_1 * V_2 = V_10 -> V_11 ;
int V_12 ;
F_6 ( V_10 , V_13 ) ;
F_7 ( V_2 -> V_14 ) ;
F_8 ( V_2 -> V_15 ) ;
for ( V_12 = 0 ; V_12 < V_16 ; V_12 ++ ) {
struct V_17 * V_18 = & V_2 -> V_19 [ V_12 ] ;
if ( V_18 && V_18 -> V_20 )
V_18 -> V_21 = V_18 -> V_22 -> V_23 ( V_2 ) ;
}
F_1 ( V_2 ) ;
if ( F_9 ( V_8 ) ) {
F_10 ( V_24 L_1 ) ;
return - V_25 ;
}
F_11 ( V_8 ) ;
F_12 ( V_8 , V_26 ) ;
return 0 ;
}
static int F_13 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
struct V_9 * V_10 = F_5 ( V_6 ) ;
struct V_1 * V_2 = V_10 -> V_11 ;
T_1 V_27 ;
int V_28 ;
int V_12 ;
F_12 ( V_8 , V_29 ) ;
F_14 ( V_8 ) ;
if ( F_15 ( V_8 ) < 0 ) {
F_10 ( V_24 L_2
L_3 ) ;
F_16 ( V_10 ) ;
return - V_25 ;
}
F_17 ( V_8 ) ;
F_2 ( V_2 , V_3 , V_30 ) ;
V_28 = 50 ;
do {
V_27 = F_18 ( V_2 , V_31 ) ;
if ( V_27 & V_32 )
break;
F_19 ( 1 ) ;
} while ( -- V_28 );
if ( ! V_28 )
F_20 ( V_24 L_4 ) ;
for ( V_12 = 0 ; V_12 < V_16 ; V_12 ++ ) {
struct V_17 * V_18 = & V_2 -> V_19 [ V_12 ] ;
if ( V_18 && V_18 -> V_20 ) {
V_18 -> V_20 -> V_22 -> V_33 ( V_18 -> V_20 ) ;
V_18 -> V_22 -> V_34 ( V_2 , V_18 -> V_21 ) ;
}
}
F_21 ( V_2 -> V_15 ) ;
F_6 ( V_10 , V_35 ) ;
return 0 ;
}
