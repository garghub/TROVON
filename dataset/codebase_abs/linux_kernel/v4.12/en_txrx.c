struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = & V_3 -> V_5 ;
T_1 V_6 = F_2 ( V_5 ) ;
struct V_1 * V_7 = F_3 ( V_5 , V_6 ) ;
T_2 V_8 = V_7 -> V_9 & V_10 ;
T_2 V_11 = F_4 ( V_5 ) & 1 ;
if ( V_8 != V_11 )
return NULL ;
F_5 () ;
return V_7 ;
}
static inline void F_6 ( struct V_2 * V_3 ,
struct V_12 * V_13 ,
struct V_1 * V_7 ,
T_3 * V_14 )
{
struct V_15 * V_5 = & V_13 -> V_5 ;
T_3 V_6 = F_7 ( V_7 -> V_16 ) & V_5 -> V_17 ;
struct V_18 * V_19 = & V_13 -> V_20 . V_21 [ V_6 ] ;
struct V_22 * V_23 = & V_13 -> V_24 -> V_23 ;
F_8 ( V_23 ) ;
F_9 ( & V_3 -> V_5 ) ;
* V_14 += V_19 -> V_25 ;
if ( F_10 ( ( V_7 -> V_9 >> 4 ) != V_26 ) ) {
F_11 ( true , L_1 ,
V_7 -> V_9 ) ;
return;
}
if ( F_12 ( V_19 -> V_27 == V_28 ) ) {
F_13 ( V_23 ) ;
return;
}
if ( F_10 ( V_19 -> V_27 != V_29 ) )
F_11 ( true ,
L_2 ,
V_19 -> V_27 ) ;
}
static void F_14 ( struct V_2 * V_3 )
{
struct V_12 * V_13 = F_15 ( V_3 , struct V_12 , V_3 ) ;
struct V_1 * V_7 ;
T_3 V_14 ;
if ( F_10 ( ! F_16 ( V_30 , & V_13 -> V_31 ) ) )
return;
V_7 = F_1 ( V_3 ) ;
if ( F_12 ( ! V_7 ) )
return;
V_14 = V_13 -> V_32 ;
F_6 ( V_3 , V_13 , V_7 , & V_14 ) ;
F_17 ( & V_3 -> V_5 ) ;
F_18 () ;
V_13 -> V_32 = V_14 ;
}
int F_19 ( struct V_33 * V_34 , int V_35 )
{
struct V_36 * V_37 = F_15 ( V_34 , struct V_36 ,
V_34 ) ;
bool V_38 = false ;
int V_39 ;
int V_40 ;
F_20 ( V_41 , & V_37 -> V_42 ) ;
for ( V_40 = 0 ; V_40 < V_37 -> V_43 ; V_40 ++ )
V_38 |= F_21 ( & V_37 -> V_13 [ V_40 ] . V_3 , V_35 ) ;
if ( V_37 -> V_44 )
V_38 |= F_22 ( & V_37 -> V_23 . V_45 . V_3 ) ;
V_39 = F_23 ( & V_37 -> V_23 . V_3 , V_35 ) ;
V_38 |= V_39 == V_35 ;
F_14 ( & V_37 -> V_46 . V_3 ) ;
V_38 |= F_24 ( & V_37 -> V_23 ) ;
if ( V_38 )
return V_35 ;
F_25 ( V_34 , V_39 ) ;
if ( F_16 ( V_41 , & V_37 -> V_42 ) ) {
F_26 ( V_34 ) ;
return V_39 ;
}
for ( V_40 = 0 ; V_40 < V_37 -> V_43 ; V_40 ++ )
F_27 ( & V_37 -> V_13 [ V_40 ] . V_3 ) ;
if ( F_16 ( V_47 , & V_37 -> V_23 . V_31 ) )
F_28 ( & V_37 -> V_23 ) ;
F_27 ( & V_37 -> V_23 . V_3 ) ;
F_27 ( & V_37 -> V_46 . V_3 ) ;
return V_39 ;
}
void F_29 ( struct V_48 * V_49 )
{
struct V_2 * V_3 = F_15 ( V_49 , struct V_2 , V_49 ) ;
V_3 -> V_50 ++ ;
F_30 ( V_41 , & V_3 -> V_24 -> V_42 ) ;
F_26 ( V_3 -> V_34 ) ;
}
void F_31 ( struct V_48 * V_49 , enum V_51 V_52 )
{
struct V_2 * V_3 = F_15 ( V_49 , struct V_2 , V_49 ) ;
struct V_36 * V_37 = V_3 -> V_24 ;
struct V_53 * V_54 = V_37 -> V_54 ;
F_32 ( V_54 , L_3 ,
V_55 , V_49 -> V_56 , V_52 ) ;
}
