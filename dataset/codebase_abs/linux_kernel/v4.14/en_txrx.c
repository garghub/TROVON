static inline bool F_1 ( struct V_1 * V_2 )
{
int V_3 = F_2 () ;
const struct V_4 * V_5 ;
struct V_6 * V_7 ;
V_7 = F_3 ( V_2 -> V_8 ) ;
V_5 = F_4 ( V_7 ) ;
return F_5 ( V_3 , V_5 ) ;
}
int F_6 ( struct V_9 * V_10 , int V_11 )
{
struct V_1 * V_2 = F_7 ( V_10 , struct V_1 ,
V_10 ) ;
bool V_12 = false ;
int V_13 = 0 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_15 ; V_14 ++ )
V_12 |= F_8 ( & V_2 -> V_16 [ V_14 ] . V_17 , V_11 ) ;
if ( V_2 -> V_18 )
V_12 |= F_9 ( & V_2 -> V_19 . V_20 . V_17 ) ;
if ( F_10 ( V_11 ) ) {
V_13 = F_11 ( & V_2 -> V_19 . V_17 , V_11 ) ;
V_12 |= V_13 == V_11 ;
}
V_12 |= V_2 -> V_19 . V_21 ( & V_2 -> V_19 ) ;
if ( V_12 ) {
if ( F_10 ( F_1 ( V_2 ) ) )
return V_11 ;
if ( V_11 && V_13 == V_11 )
V_13 -- ;
}
if ( F_12 ( ! F_13 ( V_10 , V_13 ) ) )
return V_13 ;
for ( V_14 = 0 ; V_14 < V_2 -> V_15 ; V_14 ++ )
F_14 ( & V_2 -> V_16 [ V_14 ] . V_17 ) ;
if ( F_15 ( V_2 -> V_19 . V_22 , V_23 ) )
F_16 ( & V_2 -> V_19 ) ;
F_14 ( & V_2 -> V_19 . V_17 ) ;
F_14 ( & V_2 -> V_24 . V_17 ) ;
return V_13 ;
}
void F_17 ( struct V_25 * V_26 )
{
struct V_27 * V_17 = F_7 ( V_26 , struct V_27 , V_26 ) ;
V_17 -> V_28 ++ ;
F_18 ( V_17 -> V_10 ) ;
}
void F_19 ( struct V_25 * V_26 , enum V_29 V_30 )
{
struct V_27 * V_17 = F_7 ( V_26 , struct V_27 , V_26 ) ;
struct V_1 * V_2 = V_17 -> V_31 ;
struct V_32 * V_33 = V_2 -> V_33 ;
F_20 ( V_33 , L_1 ,
V_34 , V_26 -> V_35 , V_30 ) ;
}
