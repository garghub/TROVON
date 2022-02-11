void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 ,
int V_5 , int V_6 , int V_7 , int V_8 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
memset ( V_10 , 0 , sizeof *V_10 ) ;
V_10 -> V_13 = F_2 ( 7 << 16 | V_6 << V_14 ) ;
V_10 -> V_15 = F_2 ( V_12 -> V_16 ) ;
V_10 -> V_17 = 0xff ;
if ( ! V_5 && ! V_6 )
V_10 -> V_18 = F_3 ( V_3 ) << 3 | ( F_3 ( V_4 ) - 4 ) ;
if ( V_5 )
V_10 -> V_19 = F_3 ( V_3 ) << 3 | ( F_3 ( V_4 ) - 4 ) ;
else
V_10 -> V_19 = F_3 ( V_20 ) - 4 ;
V_10 -> V_21 = F_2 ( V_12 -> V_22 . V_23 ) ;
V_10 -> V_24 = F_2 ( V_7 ) ;
V_10 -> V_25 . V_26 = 1 & 0x07 ;
V_10 -> V_25 . V_27 = 0x83 | ( V_2 -> V_28 - 1 ) << 6 ;
V_10 -> V_25 . V_29 = 0xff ;
V_10 -> V_30 = F_2 ( V_8 ) ;
V_10 -> V_31 = F_2 ( V_8 ) ;
V_10 -> V_32 = F_4 ( V_2 -> V_33 . V_34 . V_35 << 2 ) ;
}
int F_5 ( struct V_36 * V_37 )
{
struct V_38 * * V_39 ;
int V_40 ;
if ( V_41 == 64 || V_37 -> V_42 == 1 )
return 0 ;
V_39 = F_6 ( sizeof *V_39 * V_37 -> V_42 , V_43 ) ;
if ( ! V_39 )
return - V_44 ;
for ( V_40 = 0 ; V_40 < V_37 -> V_42 ; ++ V_40 )
V_39 [ V_40 ] = F_7 ( V_37 -> V_45 [ V_40 ] . V_37 ) ;
V_37 -> V_46 . V_37 = F_8 ( V_39 , V_37 -> V_42 , V_47 , V_48 ) ;
F_9 ( V_39 ) ;
if ( ! V_37 -> V_46 . V_37 )
return - V_44 ;
return 0 ;
}
void F_10 ( struct V_36 * V_37 )
{
if ( V_41 == 64 || V_37 -> V_42 == 1 )
return;
F_11 ( V_37 -> V_46 . V_37 ) ;
}
void F_12 ( struct V_49 * V_50 , enum V_51 V_52 )
{
return;
}
