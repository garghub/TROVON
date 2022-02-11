void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
bool V_6 = V_2 -> V_7 ;
if ( V_2 -> V_8 && ! V_2 -> V_9 )
return;
if ( V_2 -> V_8 ) {
F_2 ( V_2 -> V_10 ) ;
V_4 -> V_11 = V_2 -> V_10 -> V_12 . V_13 ;
V_4 -> V_14 = V_2 -> V_15 -> V_12 . V_13 ;
V_4 -> V_16 = V_2 -> V_17 -> V_12 . V_13 ;
V_4 -> V_18 = V_2 -> V_19 -> V_12 . V_13 ;
V_4 -> V_20 = V_2 -> V_21 -> V_12 . V_13 ;
V_4 -> V_22 = V_2 -> V_23 -> V_12 . V_13 ;
V_4 -> V_24 = V_2 -> V_25 -> V_12 . V_13 ;
V_4 -> V_26 = V_2 -> V_27 -> V_12 . V_13 ;
V_4 -> V_28 = V_2 -> V_29 -> V_12 . V_13 ;
F_3 ( V_4 -> V_30 ,
V_2 -> V_31 -> V_32 . V_33 ,
sizeof( V_4 -> V_30 ) ) ;
F_3 ( V_4 -> V_34 ,
V_2 -> V_35 -> V_32 . V_33 + V_6 * 64 ,
sizeof( V_4 -> V_34 ) ) ;
F_4 ( V_2 -> V_10 ) ;
} else {
F_5 ( V_4 , V_2 -> V_36 , V_6 ) ;
}
if ( V_2 -> V_37 ) {
F_6 ( V_2 -> V_38 , V_4 -> V_14 ) ;
F_6 ( V_2 -> V_39 , V_4 -> V_24 ) ;
F_6 ( V_2 -> V_40 , V_4 -> V_26 ) ;
F_6 ( V_2 -> V_41 , V_4 -> V_28 ) ;
F_7 ( V_2 -> V_42 , V_4 -> V_30 ) ;
F_7 ( V_2 -> V_43 , V_4 -> V_34 ) ;
if ( ! V_2 -> V_8 )
V_2 -> V_7 = ! V_2 -> V_7 ;
}
F_8 ( V_4 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
int V_44 = 16000 ;
int V_45 = 800 ;
int V_46 , V_47 = V_44 ;
if ( V_2 -> V_36 <= V_48 ) {
V_44 /= 10 ;
V_45 /= 10 ;
}
V_46 = ( V_2 -> V_36 + V_45 ) % V_44 - V_45 ;
if ( V_2 -> V_49 )
V_47 = V_2 -> V_36 - V_2 -> V_50 ;
if ( abs ( V_47 ) <= abs ( V_46 ) ) {
V_46 = V_47 ;
if ( ! V_2 -> V_8 && ! V_2 -> V_9 )
memset ( V_2 -> V_5 . V_51 , 0 ,
sizeof( V_2 -> V_5 . V_51 ) ) ;
V_2 -> V_8 = V_2 -> V_36 >= V_52 ;
} else {
V_2 -> V_8 = false ;
}
if ( V_2 -> V_36 <= V_48 )
V_46 *= 10 ;
V_2 -> V_53 = V_46 ;
}
int F_10 ( struct V_54 * V_54 , const unsigned * V_55 , struct V_56 * V_57 )
{
if ( V_57 -> V_58 != 0 )
return - V_59 ;
V_57 -> V_60 = * V_55 ;
return 0 ;
}
int F_11 ( struct V_54 * V_54 , unsigned * V_55 , const struct V_56 * V_57 )
{
struct V_1 * V_2 = F_12 ( V_54 ) ;
unsigned V_61 ;
unsigned V_62 ;
if ( V_57 -> V_58 != 0 )
return - V_59 ;
if ( V_57 -> V_60 >= ( V_52 + V_63 ) / 2 )
V_62 = V_64 ;
else if ( V_57 -> V_60 <= ( V_48 + V_65 ) / 2 )
V_62 = V_66 ;
else
V_62 = V_67 ;
V_61 = F_13 ( V_68 , V_57 -> V_60 , V_69 [ V_62 ] . V_70 ,
V_69 [ V_62 ] . V_71 ) ;
* V_55 = V_61 ;
F_9 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
