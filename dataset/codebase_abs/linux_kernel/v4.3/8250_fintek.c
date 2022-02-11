static int F_1 ( T_1 V_1 , T_2 V_2 )
{
if ( ! F_2 ( V_1 , 2 , V_3 ) )
return - V_4 ;
F_3 ( V_2 , V_1 + V_5 ) ;
F_3 ( V_2 , V_1 + V_5 ) ;
return 0 ;
}
static void F_4 ( T_1 V_1 )
{
F_3 ( V_6 , V_1 + V_5 ) ;
F_5 ( V_1 + V_5 , 2 ) ;
}
static int F_6 ( T_1 V_1 )
{
T_1 V_7 ;
F_3 ( V_8 , V_1 + V_5 ) ;
if ( F_7 ( V_1 + V_9 ) != V_10 )
return - V_11 ;
F_3 ( V_12 , V_1 + V_5 ) ;
if ( F_7 ( V_1 + V_9 ) != V_13 )
return - V_11 ;
F_3 ( V_14 , V_1 + V_5 ) ;
V_7 = F_7 ( V_1 + V_9 ) ;
F_3 ( V_15 , V_1 + V_5 ) ;
V_7 |= F_7 ( V_1 + V_9 ) << 8 ;
if ( V_7 != V_16 && V_7 != V_17 )
return - V_11 ;
return 0 ;
}
static int F_8 ( struct V_18 * V_19 ,
struct V_20 * V_21 )
{
T_3 V_22 = 0 ;
struct V_23 * V_24 = V_19 -> V_25 ;
if ( ! V_24 )
return - V_26 ;
if ( V_21 -> V_27 & V_28 )
memset ( V_21 -> V_29 , 0 , sizeof( V_21 -> V_29 ) ) ;
else
memset ( V_21 , 0 , sizeof( * V_21 ) ) ;
V_21 -> V_27 &= V_28 | V_30 |
V_31 ;
if ( V_21 -> V_32 ) {
V_21 -> V_32 = 1 ;
V_22 |= V_33 ;
}
if ( V_21 -> V_34 ) {
V_21 -> V_34 = 1 ;
V_22 |= V_35 ;
}
if ( ( ! ! ( V_21 -> V_27 & V_30 ) ) ==
( ! ! ( V_21 -> V_27 & V_31 ) ) )
V_21 -> V_27 &= V_28 ;
else
V_22 |= V_36 ;
if ( V_21 -> V_27 & V_30 )
V_22 |= V_37 ;
if ( F_1 ( V_24 -> V_1 , V_24 -> V_2 ) )
return - V_4 ;
F_3 ( V_38 , V_24 -> V_1 + V_5 ) ;
F_3 ( V_24 -> V_39 , V_24 -> V_1 + V_9 ) ;
F_3 ( V_40 , V_24 -> V_1 + V_5 ) ;
F_3 ( V_22 , V_24 -> V_1 + V_9 ) ;
F_4 ( V_24 -> V_1 ) ;
V_19 -> V_21 = * V_21 ;
return 0 ;
}
static int F_9 ( T_1 V_41 , T_2 * V_2 , T_2 * V_39 )
{
static const T_1 V_42 [] = { 0x4e , 0x2e } ;
static const T_2 V_43 [] = { 0x77 , 0xa0 , 0x87 , 0x67 } ;
int V_44 , V_45 , V_46 ;
for ( V_44 = 0 ; V_44 < F_10 ( V_42 ) ; V_44 ++ ) {
for ( V_45 = 0 ; V_45 < F_10 ( V_43 ) ; V_45 ++ ) {
if ( F_1 ( V_42 [ V_44 ] , V_43 [ V_45 ] ) )
continue;
if ( F_6 ( V_42 [ V_44 ] ) ) {
F_4 ( V_42 [ V_44 ] ) ;
continue;
}
for ( V_46 = 0 ; V_46 < 4 ; V_46 ++ ) {
T_1 V_47 ;
F_3 ( V_38 , V_42 [ V_44 ] + V_5 ) ;
F_3 ( V_46 , V_42 [ V_44 ] + V_9 ) ;
F_3 ( V_48 , V_42 [ V_44 ] + V_5 ) ;
V_47 = F_7 ( V_42 [ V_44 ] + V_9 ) ;
F_3 ( V_49 , V_42 [ V_44 ] + V_5 ) ;
V_47 |= F_7 ( V_42 [ V_44 ] + V_9 ) << 8 ;
if ( V_47 != V_41 )
continue;
F_4 ( V_42 [ V_44 ] ) ;
* V_2 = V_43 [ V_45 ] ;
* V_39 = V_46 ;
return V_42 [ V_44 ] ;
}
F_4 ( V_42 [ V_44 ] ) ;
}
}
return - V_11 ;
}
static int
F_11 ( struct V_50 * V_51 , const struct V_52 * V_53 )
{
struct V_54 V_55 ;
struct V_23 * V_24 ;
int V_1 ;
T_2 V_2 ;
T_2 V_39 ;
if ( ! F_12 ( V_51 , 0 ) )
return - V_11 ;
V_1 = F_9 ( F_13 ( V_51 , 0 ) , & V_2 , & V_39 ) ;
if ( V_1 < 0 )
return - V_11 ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
V_24 = F_14 ( & V_51 -> V_51 , sizeof( * V_24 ) , V_56 ) ;
if ( ! V_24 )
return - V_57 ;
V_55 . V_19 . V_25 = V_24 ;
if ( ! F_15 ( V_51 , 0 ) )
return - V_11 ;
V_55 . V_19 . V_58 = F_16 ( V_51 , 0 ) ;
V_55 . V_19 . V_59 = F_13 ( V_51 , 0 ) ;
V_55 . V_19 . V_60 = V_61 ;
V_55 . V_19 . V_62 = F_8 ;
V_55 . V_19 . V_27 |= V_63 | V_64 ;
if ( F_17 ( V_51 , 0 ) & V_65 )
V_55 . V_19 . V_27 |= V_66 ;
V_55 . V_19 . V_67 = 1843200 ;
V_55 . V_19 . V_51 = & V_51 -> V_51 ;
V_24 -> V_2 = V_2 ;
V_24 -> V_1 = V_1 ;
V_24 -> V_39 = V_39 ;
V_24 -> line = F_18 ( & V_55 ) ;
if ( V_24 -> line < 0 )
return - V_11 ;
F_19 ( V_51 , V_24 ) ;
return 0 ;
}
static void F_20 ( struct V_50 * V_51 )
{
struct V_23 * V_24 = F_21 ( V_51 ) ;
if ( V_24 )
F_22 ( V_24 -> line ) ;
}
static int F_23 ( struct V_50 * V_51 , T_4 V_68 )
{
struct V_23 * V_24 = F_21 ( V_51 ) ;
if ( ! V_24 )
return - V_11 ;
F_24 ( V_24 -> line ) ;
return 0 ;
}
static int F_25 ( struct V_50 * V_51 )
{
struct V_23 * V_24 = F_21 ( V_51 ) ;
if ( ! V_24 )
return - V_11 ;
F_26 ( V_24 -> line ) ;
return 0 ;
}
