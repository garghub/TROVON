static int F_1 ( T_1 V_1 , T_2 V_2 )
{
if ( ! F_2 ( V_1 , 2 , L_1 ) )
return - V_3 ;
F_3 ( V_2 , V_1 + V_4 ) ;
F_3 ( V_2 , V_1 + V_4 ) ;
return 0 ;
}
static void F_4 ( T_1 V_1 )
{
F_3 ( V_5 , V_1 + V_4 ) ;
F_5 ( V_1 + V_4 , 2 ) ;
}
static int F_6 ( T_1 V_1 )
{
T_1 V_6 ;
F_3 ( V_7 , V_1 + V_4 ) ;
if ( F_7 ( V_1 + V_8 ) != V_9 )
return - V_10 ;
F_3 ( V_11 , V_1 + V_4 ) ;
if ( F_7 ( V_1 + V_8 ) != V_12 )
return - V_10 ;
F_3 ( V_13 , V_1 + V_4 ) ;
V_6 = F_7 ( V_1 + V_8 ) ;
F_3 ( V_14 , V_1 + V_4 ) ;
V_6 |= F_7 ( V_1 + V_8 ) << 8 ;
if ( V_6 != V_15 && V_6 != V_16 )
return - V_10 ;
return 0 ;
}
static int F_8 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
T_3 V_21 = 0 ;
struct V_22 * V_23 = V_18 -> V_24 ;
if ( ! V_23 )
return - V_25 ;
if ( V_20 -> V_26 & V_27 )
memset ( V_20 -> V_28 , 0 , sizeof( V_20 -> V_28 ) ) ;
else
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
V_20 -> V_26 &= V_27 | V_29 |
V_30 ;
if ( V_20 -> V_31 ) {
V_20 -> V_31 = 1 ;
V_21 |= V_32 ;
}
if ( V_20 -> V_33 ) {
V_20 -> V_33 = 1 ;
V_21 |= V_34 ;
}
if ( ( ! ! ( V_20 -> V_26 & V_29 ) ) ==
( ! ! ( V_20 -> V_26 & V_30 ) ) )
V_20 -> V_26 &= V_27 ;
else
V_21 |= V_35 ;
if ( V_20 -> V_26 & V_29 )
V_21 |= V_36 ;
if ( F_1 ( V_23 -> V_1 , V_23 -> V_2 ) )
return - V_3 ;
F_3 ( V_37 , V_23 -> V_1 + V_4 ) ;
F_3 ( V_23 -> V_38 , V_23 -> V_1 + V_8 ) ;
F_3 ( V_39 , V_23 -> V_1 + V_4 ) ;
F_3 ( V_21 , V_23 -> V_1 + V_8 ) ;
F_4 ( V_23 -> V_1 ) ;
V_18 -> V_20 = * V_20 ;
return 0 ;
}
static int F_9 ( struct V_22 * V_23 , T_1 V_40 )
{
static const T_1 V_41 [] = { 0x4e , 0x2e } ;
static const T_2 V_42 [] = { 0x77 , 0xa0 , 0x87 , 0x67 } ;
int V_43 , V_44 , V_45 ;
for ( V_43 = 0 ; V_43 < F_10 ( V_41 ) ; V_43 ++ ) {
for ( V_44 = 0 ; V_44 < F_10 ( V_42 ) ; V_44 ++ ) {
if ( F_1 ( V_41 [ V_43 ] , V_42 [ V_44 ] ) )
continue;
if ( F_6 ( V_41 [ V_43 ] ) ) {
F_4 ( V_41 [ V_43 ] ) ;
continue;
}
for ( V_45 = 0 ; V_45 < 4 ; V_45 ++ ) {
T_1 V_46 ;
F_3 ( V_37 , V_41 [ V_43 ] + V_4 ) ;
F_3 ( V_45 , V_41 [ V_43 ] + V_8 ) ;
F_3 ( V_47 , V_41 [ V_43 ] + V_4 ) ;
V_46 = F_7 ( V_41 [ V_43 ] + V_8 ) ;
F_3 ( V_48 , V_41 [ V_43 ] + V_4 ) ;
V_46 |= F_7 ( V_41 [ V_43 ] + V_8 ) << 8 ;
if ( V_46 != V_40 )
continue;
F_4 ( V_41 [ V_43 ] ) ;
V_23 -> V_2 = V_42 [ V_44 ] ;
V_23 -> V_1 = V_41 [ V_43 ] ;
V_23 -> V_38 = V_45 ;
return 0 ;
}
F_4 ( V_41 [ V_43 ] ) ;
}
}
return - V_10 ;
}
int F_11 ( struct V_49 * V_50 )
{
struct V_22 * V_23 ;
struct V_22 V_51 ;
if ( F_9 ( & V_51 , V_50 -> V_18 . V_52 ) )
return - V_10 ;
V_23 = F_12 ( V_50 -> V_18 . V_53 , sizeof( * V_23 ) , V_54 ) ;
if ( ! V_23 )
return - V_55 ;
memcpy ( V_23 , & V_51 , sizeof( V_51 ) ) ;
V_50 -> V_18 . V_56 = F_8 ;
V_50 -> V_18 . V_24 = V_23 ;
return 0 ;
}
