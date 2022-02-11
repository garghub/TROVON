void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 ,
int V_5 , int V_6 , int V_7 , int V_8 ,
int V_9 , struct V_10 * V_11 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
memset ( V_11 , 0 , sizeof *V_11 ) ;
V_11 -> V_14 = F_2 ( 7 << 16 | V_6 << V_15 ) ;
V_11 -> V_16 = F_2 ( V_13 -> V_17 ) ;
V_11 -> V_18 = 0xff ;
if ( ! V_5 && ! V_6 )
V_11 -> V_19 = F_3 ( V_3 ) << 3 | ( F_3 ( V_4 ) - 4 ) ;
if ( V_5 )
V_11 -> V_20 = F_3 ( V_3 ) << 3 | ( F_3 ( V_4 ) - 4 ) ;
else
V_11 -> V_20 = F_3 ( V_21 ) - 4 ;
V_11 -> V_22 = F_2 ( V_13 -> V_23 . V_24 ) ;
V_11 -> V_25 = F_2 ( V_7 ) ;
V_11 -> V_26 . V_27 = 1 & 0x07 ;
V_11 -> V_26 . V_28 = 0x83 | ( V_2 -> V_29 - 1 ) << 6 ;
if ( V_9 >= 0 ) {
V_11 -> V_26 . V_28 |= V_9 << 3 ;
V_11 -> V_26 . V_30 = 1 << 6 ;
}
V_11 -> V_26 . V_31 = 0xff ;
V_11 -> V_32 = F_2 ( V_8 ) ;
V_11 -> V_33 = F_2 ( V_8 ) ;
V_11 -> V_34 = F_4 ( V_2 -> V_35 . V_36 . V_37 << 2 ) ;
}
int F_5 ( struct V_38 * V_39 )
{
struct V_40 * * V_41 ;
int V_42 ;
if ( V_43 == 64 || V_39 -> V_44 == 1 )
return 0 ;
V_41 = F_6 ( sizeof *V_41 * V_39 -> V_44 , V_45 ) ;
if ( ! V_41 )
return - V_46 ;
for ( V_42 = 0 ; V_42 < V_39 -> V_44 ; ++ V_42 )
V_41 [ V_42 ] = F_7 ( V_39 -> V_47 [ V_42 ] . V_39 ) ;
V_39 -> V_48 . V_39 = F_8 ( V_41 , V_39 -> V_44 , V_49 , V_50 ) ;
F_9 ( V_41 ) ;
if ( ! V_39 -> V_48 . V_39 )
return - V_46 ;
return 0 ;
}
void F_10 ( struct V_38 * V_39 )
{
if ( V_43 == 64 || V_39 -> V_44 == 1 )
return;
F_11 ( V_39 -> V_48 . V_39 ) ;
}
void F_12 ( struct V_51 * V_52 , enum V_53 V_54 )
{
return;
}
