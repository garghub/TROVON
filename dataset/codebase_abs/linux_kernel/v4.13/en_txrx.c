static inline void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
T_1 * V_7 )
{
struct V_8 * V_9 = & V_4 -> V_9 ;
T_1 V_10 = F_2 ( V_6 -> V_11 ) & V_9 -> V_12 ;
struct V_13 * V_14 = & V_4 -> V_15 . V_16 [ V_10 ] ;
struct V_17 * V_18 = & V_4 -> V_19 -> V_18 ;
F_3 ( V_18 ) ;
F_4 ( & V_2 -> V_9 ) ;
* V_7 += V_14 -> V_20 ;
if ( F_5 ( ( V_6 -> V_21 >> 4 ) != V_22 ) ) {
F_6 ( true , L_1 ,
V_6 -> V_21 ) ;
return;
}
if ( F_7 ( V_14 -> V_23 == V_24 ) ) {
F_8 ( V_18 ) ;
return;
}
if ( F_5 ( V_14 -> V_23 != V_25 ) )
F_6 ( true ,
L_2 ,
V_14 -> V_23 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_10 ( V_2 , struct V_3 , V_2 ) ;
struct V_5 * V_6 ;
T_1 V_7 ;
if ( F_5 ( ! F_11 ( V_26 , & V_4 -> V_27 ) ) )
return;
V_6 = F_12 ( & V_2 -> V_9 ) ;
if ( F_7 ( ! V_6 ) )
return;
V_7 = V_4 -> V_28 ;
F_1 ( V_2 , V_4 , V_6 , & V_7 ) ;
F_13 ( & V_2 -> V_9 ) ;
F_14 () ;
V_4 -> V_28 = V_7 ;
}
int F_15 ( struct V_29 * V_30 , int V_31 )
{
struct V_32 * V_33 = F_10 ( V_30 , struct V_32 ,
V_30 ) ;
bool V_34 = false ;
int V_35 ;
int V_36 ;
F_16 ( V_37 , & V_33 -> V_38 ) ;
for ( V_36 = 0 ; V_36 < V_33 -> V_39 ; V_36 ++ )
V_34 |= F_17 ( & V_33 -> V_4 [ V_36 ] . V_2 , V_31 ) ;
if ( V_33 -> V_40 )
V_34 |= F_18 ( & V_33 -> V_18 . V_41 . V_2 ) ;
V_35 = F_19 ( & V_33 -> V_18 . V_2 , V_31 ) ;
V_34 |= V_35 == V_31 ;
F_9 ( & V_33 -> V_42 . V_2 ) ;
V_34 |= F_20 ( & V_33 -> V_18 ) ;
if ( V_34 )
return V_31 ;
F_21 ( V_30 , V_35 ) ;
if ( F_11 ( V_37 , & V_33 -> V_38 ) ) {
F_22 ( V_30 ) ;
return V_35 ;
}
for ( V_36 = 0 ; V_36 < V_33 -> V_39 ; V_36 ++ )
F_23 ( & V_33 -> V_4 [ V_36 ] . V_2 ) ;
if ( F_11 ( V_43 , & V_33 -> V_18 . V_27 ) )
F_24 ( & V_33 -> V_18 ) ;
F_23 ( & V_33 -> V_18 . V_2 ) ;
F_23 ( & V_33 -> V_42 . V_2 ) ;
return V_35 ;
}
void F_25 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_10 ( V_45 , struct V_1 , V_45 ) ;
V_2 -> V_46 ++ ;
F_26 ( V_37 , & V_2 -> V_19 -> V_38 ) ;
F_22 ( V_2 -> V_30 ) ;
}
void F_27 ( struct V_44 * V_45 , enum V_47 V_48 )
{
struct V_1 * V_2 = F_10 ( V_45 , struct V_1 , V_45 ) ;
struct V_32 * V_33 = V_2 -> V_19 ;
struct V_49 * V_50 = V_33 -> V_50 ;
F_28 ( V_50 , L_3 ,
V_51 , V_45 -> V_52 , V_48 ) ;
}
