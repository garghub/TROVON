static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_5 = F_2 ( V_4 , V_6 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
T_1 V_9 ;
if ( V_5 & V_10 )
return - V_11 ;
if ( V_2 -> V_12 == V_13 || V_2 -> V_12 == V_14 ) {
F_3 ( V_4 , V_15 , V_16 ) ;
if ( V_2 -> V_12 == V_14 )
return - V_17 ;
return 0 ;
}
if ( V_5 & V_18 ) {
V_2 -> V_12 = V_14 ;
F_3 ( V_4 , V_15 , V_19 ) ;
return - V_20 ;
}
if ( V_2 -> V_12 == V_21 ) {
if ( V_5 & V_22 )
return - V_11 ;
V_2 -> V_12 = V_23 ;
}
if ( V_2 -> V_12 == V_23 ) {
if ( V_2 -> V_8 -> V_24 & V_25 ) {
V_9 = 0xf0 | ( ( V_2 -> V_8 -> V_9 >> 7 ) & 0x6 ) ;
V_2 -> V_12 = V_26 ;
} else {
V_9 = ( V_2 -> V_8 -> V_9 << 1 ) ;
V_2 -> V_12 = V_27 ;
}
V_9 |= ( V_2 -> V_8 -> V_24 & V_28 ) ? 1 : 0 ;
F_3 ( V_4 , V_29 , V_9 ) ;
F_3 ( V_4 , V_15 , V_30 ) ;
return 0 ;
}
if ( V_2 -> V_12 == V_26 ) {
F_3 ( V_4 , V_29 , V_2 -> V_8 -> V_9 & 0xff ) ;
F_3 ( V_4 , V_15 , V_31 ) ;
V_2 -> V_12 = V_27 ;
return 0 ;
}
if ( V_2 -> V_12 == V_27 || V_2 -> V_12 == V_32 ) {
V_2 -> V_12 = ( V_8 -> V_24 & V_28 ) ? V_33 : V_32 ;
if ( V_5 & V_34 ) {
V_2 -> V_12 = V_14 ;
F_3 ( V_4 , V_15 , V_19 ) ;
return - V_35 ;
}
} else {
V_8 -> V_36 [ V_2 -> V_37 ++ ] = F_2 ( V_4 , V_29 ) ;
}
if ( V_2 -> V_37 >= V_8 -> V_38 ) {
V_2 -> V_39 -- ;
V_2 -> V_8 ++ ;
V_2 -> V_37 = 0 ;
V_8 = V_2 -> V_8 ;
if ( V_2 -> V_39 ) {
if ( ! ( V_8 -> V_24 & V_40 ) ) {
V_2 -> V_12 = V_23 ;
return 0 ;
} else {
V_2 -> V_12 = ( V_8 -> V_24 & V_28 )
? V_33 : V_32 ;
}
} else {
V_2 -> V_12 = V_13 ;
F_3 ( V_4 , V_15 , V_19 ) ;
return 0 ;
}
}
if ( V_2 -> V_12 == V_33 ) {
F_3 ( V_4 , V_15 , V_2 -> V_37 == ( V_8 -> V_38 - 1 ) ?
V_41 : V_42 ) ;
} else {
F_3 ( V_4 , V_29 , V_8 -> V_36 [ V_2 -> V_37 ++ ] ) ;
F_3 ( V_4 , V_15 , V_31 ) ;
}
return 0 ;
}
static int F_4 ( struct V_43 * V_44 , struct V_7 * V_45 ,
int V_46 )
{
struct V_1 * V_2 = F_5 ( V_44 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_47 = V_48 + V_49 ;
int V_50 ;
V_2 -> V_8 = V_45 ;
V_2 -> V_37 = 0 ;
V_2 -> V_39 = V_46 ;
V_2 -> V_12 = V_21 ;
while ( F_6 ( V_48 , V_47 ) ) {
F_7 ( V_4 ) ;
V_50 = F_1 ( V_2 ) ;
F_8 ( V_4 ) ;
if ( V_2 -> V_12 == V_13 || V_2 -> V_12 == V_14 )
return ( V_2 -> V_12 == V_13 ) ? V_46 : V_50 ;
if ( V_50 == 0 )
V_47 = V_48 + V_49 ;
F_9 ( 5 , 15 ) ;
}
V_2 -> V_12 = V_14 ;
return - V_51 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_2 V_52 ;
long V_53 ;
T_1 V_54 ;
T_1 V_5 ;
T_1 V_55 ;
V_54 = F_2 ( V_4 , V_56 ) ;
V_54 &= ~ ( V_57 | V_58 ) ;
F_3 ( V_4 , V_56 , V_54 ) ;
if ( V_59 > V_60 )
V_59 = V_60 ;
if ( V_4 -> V_61 . V_62 == 1 )
V_53 = V_4 -> V_63 / ( V_59 * 5 ) - 1000 ;
else
V_53 = V_4 -> V_63 / ( V_59 * 4 ) - 3000 ;
if ( V_53 < 0 )
V_53 = 0 ;
V_52 = V_53 / 1000 ;
if ( V_53 % 1000 >= 500 )
V_52 ++ ;
F_3 ( V_4 , V_64 , V_52 & 0xff ) ;
F_3 ( V_4 , V_65 , V_52 >> 8 ) ;
V_55 = F_2 ( V_4 , V_66 ) ;
if ( V_67 )
V_55 |= V_68 ;
else
V_55 &= ~ V_68 ;
F_3 ( V_4 , V_66 , V_55 ) ;
F_3 ( V_4 , V_15 , V_16 ) ;
V_54 |= V_57 ;
F_3 ( V_4 , V_56 , V_54 ) ;
V_5 = F_2 ( V_4 , V_6 ) ;
if ( V_5 & V_22 )
F_3 ( V_4 , V_15 , V_19 ) ;
}
static T_3 F_11 ( struct V_43 * V_44 )
{
return V_69 | V_70 | V_71 ;
}
static int F_12 ( struct V_72 * V_73 )
{
struct V_3 * V_4 = F_13 ( V_73 -> V_74 . V_75 ) ;
struct V_1 * V_2 ;
int V_50 ;
T_1 V_54 ;
V_2 = F_14 ( & V_73 -> V_74 , sizeof( * V_2 ) , V_76 ) ;
if ( ! V_2 )
return - V_77 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_74 = & V_73 -> V_74 ;
V_2 -> V_44 = V_78 ;
V_2 -> V_44 . V_74 . V_75 = V_2 -> V_74 ;
F_15 ( & V_2 -> V_44 , V_2 ) ;
F_16 ( V_73 , V_2 ) ;
F_7 ( V_4 ) ;
V_54 = F_2 ( V_4 , V_56 ) ;
if ( V_54 & V_57 )
V_2 -> V_79 = true ;
F_10 ( V_2 ) ;
F_8 ( V_4 ) ;
if ( V_80 >= - 1 )
V_2 -> V_44 . V_81 = V_80 ;
V_50 = F_17 ( & V_2 -> V_44 ) ;
if ( V_50 )
return V_50 ;
F_18 ( V_2 -> V_74 , L_1 ,
V_59 ) ;
return 0 ;
}
static int F_19 ( struct V_72 * V_73 )
{
struct V_1 * V_2 = F_20 ( V_73 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_54 ;
F_7 ( V_4 ) ;
if ( ! V_2 -> V_79 ) {
V_54 = F_2 ( V_4 , V_56 ) ;
V_54 &= ~ V_57 ;
F_3 ( V_4 , V_56 , V_54 ) ;
}
F_8 ( V_4 ) ;
F_21 ( & V_2 -> V_44 ) ;
return 0 ;
}
static int F_22 ( struct V_72 * V_73 , T_4 V_12 )
{
struct V_1 * V_2 = F_20 ( V_73 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_54 ;
F_7 ( V_4 ) ;
V_54 = F_2 ( V_4 , V_56 ) ;
V_54 &= ~ V_57 ;
F_3 ( V_4 , V_56 , V_54 ) ;
F_8 ( V_4 ) ;
return 0 ;
}
static int F_23 ( struct V_72 * V_73 )
{
struct V_1 * V_2 = F_20 ( V_73 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_7 ( V_4 ) ;
F_10 ( V_2 ) ;
F_8 ( V_4 ) ;
return 0 ;
}
