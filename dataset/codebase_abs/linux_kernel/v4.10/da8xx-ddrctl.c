static const struct V_1 *
F_1 ( const struct V_2 * V_3 )
{
const struct V_1 * V_4 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_6 ) ; V_5 ++ ) {
V_4 = & V_6 [ V_5 ] ;
if ( strcmp ( V_4 -> V_7 , V_3 -> V_7 ) == 0 )
return V_4 ;
}
return NULL ;
}
static const struct V_2 * F_3 ( void )
{
const struct V_8 * V_9 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_10 ) ; V_5 ++ ) {
V_9 = & V_10 [ V_5 ] ;
if ( F_4 ( V_9 -> V_11 ) )
return V_9 -> V_12 ;
}
return NULL ;
}
static int F_5 ( struct V_13 * V_14 )
{
const struct V_1 * V_4 ;
const struct V_2 * V_3 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
void T_1 * V_19 ;
struct V_20 * V_21 ;
T_2 V_22 ;
V_21 = & V_14 -> V_21 ;
V_16 = V_21 -> V_23 ;
V_3 = F_3 () ;
if ( ! V_3 ) {
F_6 ( V_21 , L_1 ) ;
return - V_24 ;
}
V_18 = F_7 ( V_14 , V_25 , 0 ) ;
V_19 = F_8 ( V_21 , V_18 ) ;
if ( F_9 ( V_19 ) ) {
F_6 ( V_21 , L_2 ) ;
return F_10 ( V_19 ) ;
}
for (; V_3 -> V_7 ; V_3 ++ ) {
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
F_11 ( V_21 ,
L_3 , V_3 -> V_7 ) ;
continue;
}
if ( V_4 -> V_22 + sizeof( T_2 ) > F_12 ( V_18 ) ) {
F_11 ( V_21 ,
L_4 ,
V_4 -> V_7 ) ;
continue;
}
V_22 = F_13 ( V_19 + V_4 -> V_22 ) ;
V_22 &= V_4 -> V_26 ;
V_22 |= V_3 -> V_27 << V_4 -> V_28 ;
F_14 ( V_21 , L_5 , V_22 , V_3 -> V_7 ) ;
F_15 ( V_22 , V_19 + V_4 -> V_22 ) ;
}
return 0 ;
}
