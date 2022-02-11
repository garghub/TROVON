void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 ,
int V_5 , int V_6 , int V_7 , int V_8 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
memset ( V_10 , 0 , sizeof *V_10 ) ;
V_10 -> V_13 = F_2 ( 7 << 16 | V_6 << 13 ) ;
V_10 -> V_14 = F_2 ( V_12 -> V_15 ) ;
V_10 -> V_16 = 0xff ;
if ( ! V_5 && ! V_6 )
V_10 -> V_17 = F_3 ( V_3 ) << 3 | ( F_3 ( V_4 ) - 4 ) ;
if ( V_5 )
V_10 -> V_18 = F_3 ( V_3 ) << 3 | ( F_3 ( V_4 ) - 4 ) ;
else
V_10 -> V_18 = F_3 ( V_19 ) - 4 ;
V_10 -> V_20 = F_2 ( V_12 -> V_21 . V_22 ) ;
V_10 -> V_23 = F_2 ( V_7 ) ;
V_10 -> V_24 . V_25 = 1 & 0x07 ;
V_10 -> V_24 . V_26 = 0x83 | ( V_2 -> V_27 - 1 ) << 6 ;
V_10 -> V_24 . V_28 = 0xff ;
V_10 -> V_29 = F_2 ( V_8 ) ;
V_10 -> V_30 = F_2 ( V_8 ) ;
V_10 -> V_31 = F_4 ( V_2 -> V_32 . V_33 . V_34 << 2 ) ;
}
int F_5 ( struct V_35 * V_36 )
{
struct V_37 * * V_38 ;
int V_39 ;
if ( V_40 == 64 || V_36 -> V_41 == 1 )
return 0 ;
V_38 = F_6 ( sizeof *V_38 * V_36 -> V_41 , V_42 ) ;
if ( ! V_38 )
return - V_43 ;
for ( V_39 = 0 ; V_39 < V_36 -> V_41 ; ++ V_39 )
V_38 [ V_39 ] = F_7 ( V_36 -> V_44 [ V_39 ] . V_36 ) ;
V_36 -> V_45 . V_36 = F_8 ( V_38 , V_36 -> V_41 , V_46 , V_47 ) ;
F_9 ( V_38 ) ;
if ( ! V_36 -> V_45 . V_36 )
return - V_43 ;
return 0 ;
}
void F_10 ( struct V_35 * V_36 )
{
if ( V_40 == 64 || V_36 -> V_41 == 1 )
return;
F_11 ( V_36 -> V_45 . V_36 ) ;
}
void F_12 ( struct V_48 * V_49 , enum V_50 V_51 )
{
return;
}
