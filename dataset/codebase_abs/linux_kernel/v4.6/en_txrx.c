struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = & V_3 -> V_5 ;
T_1 V_6 = F_2 ( V_5 ) ;
struct V_1 * V_7 = F_3 ( V_5 , V_6 ) ;
int V_8 = V_7 -> V_9 & V_10 ;
int V_11 = F_4 ( V_5 ) & 1 ;
if ( V_8 != V_11 )
return NULL ;
F_5 () ;
return V_7 ;
}
int F_6 ( struct V_12 * V_13 , int V_14 )
{
struct V_15 * V_16 = F_7 ( V_13 , struct V_15 ,
V_13 ) ;
bool V_17 = false ;
int V_18 ;
int V_19 ;
F_8 ( V_20 , & V_16 -> V_21 ) ;
for ( V_19 = 0 ; V_19 < V_16 -> V_22 ; V_19 ++ )
V_17 |= F_9 ( & V_16 -> V_23 [ V_19 ] . V_3 , V_14 ) ;
V_18 = F_10 ( & V_16 -> V_24 . V_3 , V_14 ) ;
V_17 |= V_18 == V_14 ;
V_17 |= F_11 ( & V_16 -> V_24 ) ;
if ( V_17 )
return V_14 ;
F_12 ( V_13 , V_18 ) ;
if ( F_13 ( V_20 , & V_16 -> V_21 ) ) {
F_14 ( V_13 ) ;
return V_18 ;
}
for ( V_19 = 0 ; V_19 < V_16 -> V_22 ; V_19 ++ )
F_15 ( & V_16 -> V_23 [ V_19 ] . V_3 ) ;
F_15 ( & V_16 -> V_24 . V_3 ) ;
return V_18 ;
}
void F_16 ( struct V_25 * V_26 )
{
struct V_2 * V_3 = F_7 ( V_26 , struct V_2 , V_26 ) ;
F_17 ( V_20 , & V_3 -> V_27 -> V_21 ) ;
F_18 () ;
F_14 ( V_3 -> V_13 ) ;
}
void F_19 ( struct V_25 * V_26 , enum V_28 V_29 )
{
struct V_2 * V_3 = F_7 ( V_26 , struct V_2 , V_26 ) ;
struct V_15 * V_16 = V_3 -> V_27 ;
struct V_30 * V_31 = V_16 -> V_31 ;
struct V_32 * V_33 = V_31 -> V_33 ;
F_20 ( V_33 , L_1 ,
V_34 , V_26 -> V_35 , V_29 ) ;
}
