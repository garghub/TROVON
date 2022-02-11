static const struct V_1 *
F_1 ( void )
{
const struct V_1 * V_2 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
V_2 = & V_4 [ V_3 ] ;
if ( F_3 ( V_2 -> V_5 ) )
return V_2 ;
}
return NULL ;
}
static int F_4 ( struct V_6 * V_7 )
{
const struct V_1 * V_8 ;
const struct V_9 * V_10 ;
const struct V_11 * V_12 ;
struct V_13 * V_14 = & V_7 -> V_14 ;
struct V_15 * V_16 ;
void T_1 * V_17 ;
T_2 V_18 ;
int V_3 ;
V_16 = F_5 ( V_7 , V_19 , 0 ) ;
V_17 = F_6 ( V_14 , V_16 ) ;
if ( F_7 ( V_17 ) ) {
F_8 ( V_14 , L_1 ) ;
return F_9 ( V_17 ) ;
}
V_8 = F_1 () ;
if ( ! V_8 ) {
F_8 ( V_14 , L_2 ) ;
return - V_20 ;
}
for ( V_3 = 0 ; V_3 < V_8 -> V_21 ; V_3 ++ ) {
V_12 = & V_8 -> V_22 [ V_3 ] ;
V_10 = & V_23 [ V_12 -> V_24 ] ;
if ( V_10 -> V_18 + sizeof( T_2 ) > F_10 ( V_16 ) ) {
F_11 ( V_14 , L_3 ) ;
continue;
}
V_18 = F_12 ( V_17 + V_10 -> V_18 ) ;
V_18 &= ~ V_10 -> V_25 ;
V_18 |= V_12 -> V_26 << V_10 -> V_27 ;
F_13 ( V_18 , V_17 + V_10 -> V_18 ) ;
}
return 0 ;
}
