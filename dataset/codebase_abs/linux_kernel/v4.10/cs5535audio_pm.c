static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 , V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
struct V_1 * V_2 = V_8 -> V_9 ;
int V_10 ;
F_5 ( V_8 , V_11 ) ;
F_6 ( V_2 -> V_12 ) ;
F_7 ( V_2 -> V_13 ) ;
for ( V_10 = 0 ; V_10 < V_14 ; V_10 ++ ) {
struct V_15 * V_16 = & V_2 -> V_17 [ V_10 ] ;
if ( V_16 && V_16 -> V_18 )
V_16 -> V_19 = V_16 -> V_20 -> V_21 ( V_2 ) ;
}
F_1 ( V_2 ) ;
return 0 ;
}
static int F_8 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
struct V_1 * V_2 = V_8 -> V_9 ;
T_1 V_22 ;
int V_23 ;
int V_10 ;
F_2 ( V_2 , V_3 , V_24 ) ;
V_23 = 50 ;
do {
V_22 = F_9 ( V_2 , V_25 ) ;
if ( V_22 & V_26 )
break;
F_10 ( 1 ) ;
} while ( -- V_23 );
if ( ! V_23 )
F_11 ( V_2 -> V_8 -> V_6 , L_1 ) ;
for ( V_10 = 0 ; V_10 < V_14 ; V_10 ++ ) {
struct V_15 * V_16 = & V_2 -> V_17 [ V_10 ] ;
if ( V_16 && V_16 -> V_18 ) {
V_16 -> V_18 -> V_20 -> V_27 ( V_16 -> V_18 ) ;
V_16 -> V_20 -> V_28 ( V_2 , V_16 -> V_19 ) ;
}
}
F_12 ( V_2 -> V_13 ) ;
F_5 ( V_8 , V_29 ) ;
return 0 ;
}
