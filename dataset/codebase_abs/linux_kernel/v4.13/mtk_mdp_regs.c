static T_1 F_1 ( int V_1 )
{
switch ( V_1 ) {
case V_2 :
case V_3 :
return V_4 ;
case V_5 :
return V_6 ;
case V_7 :
case V_8 :
return V_9 ;
case V_10 :
return V_11 ;
}
F_2 ( L_1 , V_1 ) ;
return V_12 ;
}
void F_3 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = & V_14 -> V_19 . V_20 -> V_21 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < F_4 ( V_16 -> V_16 ) ; V_22 ++ )
V_18 -> V_23 [ V_22 ] = ( V_24 ) V_16 -> V_16 [ V_22 ] ;
}
void F_5 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_17 * V_25 = & V_14 -> V_19 . V_20 -> V_26 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < F_4 ( V_16 -> V_16 ) ; V_22 ++ )
V_25 -> V_23 [ V_22 ] = ( V_24 ) V_16 -> V_16 [ V_22 ] ;
}
void F_6 ( struct V_13 * V_14 )
{
struct V_27 * V_28 = & V_14 -> V_29 ;
struct V_30 * V_31 = & V_14 -> V_19 . V_20 -> V_32 ;
V_31 -> V_33 = V_28 -> V_34 . V_35 ;
V_31 -> V_36 = V_28 -> V_34 . V_37 ;
V_31 -> V_38 = V_28 -> V_34 . V_39 ;
V_31 -> V_40 = V_28 -> V_34 . V_41 ;
V_31 -> V_42 = 0 ;
V_31 -> V_43 = 0 ;
V_31 -> V_44 = V_28 -> V_39 ;
V_31 -> V_45 = V_28 -> V_41 ;
}
void F_7 ( struct V_13 * V_14 )
{
unsigned int V_22 ;
struct V_27 * V_28 = & V_14 -> V_29 ;
struct V_30 * V_31 = & V_14 -> V_19 . V_20 -> V_32 ;
struct V_17 * V_18 = & V_14 -> V_19 . V_20 -> V_21 ;
V_18 -> V_46 = V_28 -> V_47 -> V_48 ;
V_31 -> V_49 = F_1 ( V_28 -> V_47 -> V_50 ) ;
V_31 -> V_51 = 0 ;
V_31 -> V_52 = 0 ;
for ( V_22 = 0 ; V_22 < V_18 -> V_46 ; V_22 ++ )
V_18 -> V_53 [ V_22 ] = V_28 -> V_54 [ V_22 ] ;
}
void F_8 ( struct V_13 * V_14 )
{
struct V_27 * V_28 = & V_14 -> V_55 ;
struct V_30 * V_31 = & V_14 -> V_19 . V_20 -> V_56 ;
V_31 -> V_33 = V_28 -> V_34 . V_35 ;
V_31 -> V_36 = V_28 -> V_34 . V_37 ;
V_31 -> V_38 = V_28 -> V_34 . V_39 ;
V_31 -> V_40 = V_28 -> V_34 . V_41 ;
V_31 -> V_42 = 0 ;
V_31 -> V_43 = 0 ;
V_31 -> V_44 = V_28 -> V_39 ;
V_31 -> V_45 = V_28 -> V_41 ;
}
void F_9 ( struct V_13 * V_14 )
{
unsigned int V_22 ;
struct V_27 * V_28 = & V_14 -> V_55 ;
struct V_30 * V_31 = & V_14 -> V_19 . V_20 -> V_56 ;
struct V_17 * V_25 = & V_14 -> V_19 . V_20 -> V_26 ;
V_25 -> V_46 = V_28 -> V_47 -> V_48 ;
V_31 -> V_49 = F_1 ( V_28 -> V_47 -> V_50 ) ;
V_31 -> V_51 = 0 ;
V_31 -> V_52 = 0 ;
for ( V_22 = 0 ; V_22 < V_25 -> V_46 ; V_22 ++ )
V_25 -> V_53 [ V_22 ] = V_28 -> V_54 [ V_22 ] ;
}
void F_10 ( struct V_13 * V_14 )
{
struct V_57 * V_58 = & V_14 -> V_19 . V_20 -> V_58 ;
V_58 -> V_59 = V_14 -> V_60 . V_61 -> V_62 ;
V_58 -> V_63 = V_14 -> V_60 . V_63 -> V_62 ;
V_58 -> V_64 = V_14 -> V_60 . V_64 -> V_62 ;
}
void F_11 ( struct V_13 * V_14 )
{
struct V_57 * V_58 = & V_14 -> V_19 . V_20 -> V_58 ;
V_58 -> V_65 = V_14 -> V_60 . V_66 -> V_62 ;
}
