void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> V_5 . V_6 ++ ;
V_4 -> V_5 . V_7 += V_2 -> V_8 ;
}
void F_2 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> V_5 . V_9 ++ ;
V_4 -> V_5 . V_10 += V_2 -> V_8 ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_11 * V_12 ;
V_12 = F_4 ( V_4 ) ;
if ( V_12 -> V_13 . V_14 ) {
F_5 ( V_2 , & V_12 -> V_13 ) ;
} else {
V_4 -> V_5 . V_15 ++ ;
F_6 ( V_2 ) ;
}
return V_16 ;
}
static int F_7 ( struct V_3 * V_17 , int V_18 )
{
if ( V_18 < 0 || V_18 > V_19 )
return - V_20 ;
V_17 -> V_21 = V_18 ;
return 0 ;
}
static int F_8 ( const struct V_3 * V_4 )
{
struct V_11 * V_12 = F_4 ( V_4 ) ;
return V_12 -> V_22 -> V_23 ;
}
void F_9 ( struct V_3 * V_17 )
{
V_17 -> V_24 = & V_25 ;
V_17 -> V_21 = V_26 ;
V_17 -> V_27 = V_28 ;
F_10 ( V_17 -> V_29 ) ;
V_17 -> V_30 = V_31 ;
V_17 -> V_32 = NULL ;
V_17 -> type = V_33 ;
V_17 -> V_34 = 0 ;
V_17 -> V_35 &= ~ ( V_36 | V_37 ) ;
V_17 -> V_38 = true ;
}
int F_11 ( T_2 V_39 , struct V_3 * V_17 ,
struct V_40 * V_41 ,
struct V_3 * V_22 )
{
struct V_11 * V_12 ;
int V_42 ;
if ( V_41 -> V_43 [ V_39 ] )
return - V_20 ;
V_42 = F_12 ( V_17 ) ;
if ( ! V_42 ) {
V_41 -> V_43 [ V_39 ] = V_17 ;
V_41 -> V_44 ++ ;
V_17 -> V_45 = & V_46 ;
V_12 = F_4 ( V_17 ) ;
V_12 -> V_47 = V_39 ;
V_12 -> V_22 = V_22 ;
F_13 ( V_17 , L_1 ) ;
}
return V_42 ;
}
int F_14 ( T_2 V_39 , struct V_40 * V_41 )
{
if ( V_39 >= V_48 || ! V_41 -> V_43 [ V_39 ] )
return - V_20 ;
V_41 -> V_43 [ V_39 ] = NULL ;
V_41 -> V_44 -- ;
return 0 ;
}
T_2 F_15 ( struct V_3 * V_17 )
{
struct V_11 * V_12 ;
V_12 = F_4 ( V_17 ) ;
return V_12 -> V_47 ;
}
struct V_49 * F_16 ( struct V_3 * V_17 )
{
struct V_11 * V_12 ;
if ( ! V_17 )
return NULL ;
V_12 = F_4 ( V_17 ) ;
return & V_12 -> V_13 ;
}
int F_17 ( struct V_3 * V_17 , int V_50 )
{
F_13 ( V_17 , L_2 , V_50 ) ;
if ( F_18 ( V_50 ) )
F_19 ( V_17 ) ;
else
F_20 ( V_17 ) ;
return 0 ;
}
