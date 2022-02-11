static void F_1 ( struct V_1 * V_1 )
{
F_2 ( V_1 -> V_2 , & V_1 -> V_3 ) ;
F_2 ( V_1 -> V_2 , & V_1 -> V_4 ) ;
}
T_1 F_3 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_4 ( V_6 ) ;
struct V_1 * V_1 = F_5 ( V_7 ) ;
T_2 V_8 ;
V_8 = F_6 ( V_1 -> V_9 + V_10 ) ;
if ( ! ( V_8 & V_11 ) )
return V_12 ;
F_7 ( V_8 & V_11 , V_1 -> V_9 + V_10 ) ;
if ( V_8 & V_13 )
F_8 ( & V_1 -> V_14 ) ;
if ( V_8 & V_15 )
F_9 ( & V_1 -> V_16 -> V_17 , L_1 ) ;
if ( V_8 & V_18 )
F_8 ( & V_1 -> V_19 ) ;
if ( V_8 & V_20 )
F_8 ( & V_1 -> V_21 ) ;
if ( V_8 & V_22 )
F_2 ( V_1 -> V_2 , & V_1 -> V_23 ) ;
if ( V_8 & ( V_24 | V_25 ) )
F_1 ( V_1 ) ;
return V_26 ;
}
static int F_10 ( struct V_1 * V_1 )
{
struct V_7 * V_7 = & V_1 -> V_7 ;
struct V_27 * V_28 ;
int V_29 = 0 ;
for ( V_28 = V_1 -> V_30 ; V_28 < V_1 -> V_30 + V_31 ; V_28 ++ ) {
if ( V_28 -> V_32 & V_33 ) {
F_11 ( V_7 , V_28 -> V_34 ,
(struct V_35 * ) V_28 -> V_36 ,
V_28 -> V_37 ) ;
V_28 -> V_32 &= ~ V_33 ;
V_29 ++ ;
}
}
return V_29 ;
}
void F_12 ( struct V_38 * V_39 )
{
struct V_1 * V_1 = F_13 ( V_39 , struct V_1 , V_23 ) ;
int V_29 ;
do {
V_29 = F_10 ( V_1 ) ;
} while ( V_29 );
}
