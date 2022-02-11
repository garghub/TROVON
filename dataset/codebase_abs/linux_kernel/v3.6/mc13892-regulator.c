static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
int V_7 ;
T_1 V_8 ;
F_2 ( V_4 & ~ V_3 ) ;
V_7 = F_3 ( V_6 , V_9 , & V_8 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_10 =
( V_2 -> V_10 & ~ V_3 ) | V_4 ;
V_2 -> V_10 &= V_11 ;
V_8 = ( V_8 & ~ V_3 ) | V_4 ;
V_8 = ( V_8 & ~ V_11 ) |
V_2 -> V_10 ;
return F_4 ( V_6 , V_9 , V_8 ) ;
}
static int F_5 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_6 ( V_13 ) ;
int V_14 = F_7 ( V_13 ) ;
int V_7 ;
T_1 V_15 = V_16 [ V_14 ] . V_17 ;
T_1 V_3 = V_16 [ V_14 ] . V_17 ;
F_8 ( F_9 ( V_13 ) , L_1 , V_18 , V_14 ) ;
if ( V_14 == V_19 || V_14 == V_20 )
V_15 = 0 ;
if ( V_14 == V_21 )
V_3 |= V_22 ;
F_10 ( V_2 -> V_5 ) ;
V_7 = F_1 ( V_2 , V_3 , V_15 ) ;
F_11 ( V_2 -> V_5 ) ;
return V_7 ;
}
static int F_12 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_6 ( V_13 ) ;
int V_14 = F_7 ( V_13 ) ;
int V_7 ;
T_1 V_23 = 0 ;
F_8 ( F_9 ( V_13 ) , L_1 , V_18 , V_14 ) ;
if ( V_14 == V_19 || V_14 == V_20 )
V_23 = V_16 [ V_14 ] . V_17 ;
F_10 ( V_2 -> V_5 ) ;
V_7 = F_1 ( V_2 , V_16 [ V_14 ] . V_17 ,
V_23 ) ;
F_11 ( V_2 -> V_5 ) ;
return V_7 ;
}
static int F_13 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_6 ( V_13 ) ;
int V_7 , V_14 = F_7 ( V_13 ) ;
unsigned int V_4 ;
F_10 ( V_2 -> V_5 ) ;
V_7 = F_3 ( V_2 -> V_5 , V_16 [ V_14 ] . V_24 , & V_4 ) ;
F_11 ( V_2 -> V_5 ) ;
if ( V_7 )
return V_7 ;
V_4 = ( V_4 & ~ V_11 ) |
( V_2 -> V_10 ^ V_11 ) ;
return ( V_4 & V_16 [ V_14 ] . V_17 ) != 0 ;
}
static int F_14 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_6 ( V_13 ) ;
int V_7 , V_14 = F_7 ( V_13 ) ;
unsigned int V_4 , V_25 ;
F_8 ( F_9 ( V_13 ) , L_1 , V_18 , V_14 ) ;
F_10 ( V_2 -> V_5 ) ;
V_7 = F_3 ( V_2 -> V_5 ,
V_16 [ V_14 ] . V_26 , & V_4 ) ;
F_11 ( V_2 -> V_5 ) ;
if ( V_7 )
return V_7 ;
V_25 = V_4 & V_27 ;
V_4 = ( V_4 & V_16 [ V_14 ] . V_28 )
>> V_16 [ V_14 ] . V_29 ;
F_8 ( F_9 ( V_13 ) , L_2 , V_18 , V_14 , V_4 ) ;
if ( V_25 )
V_4 = ( 25000 * V_4 ) + 1100000 ;
else
V_4 = ( 25000 * V_4 ) + 600000 ;
return V_4 ;
}
static int F_15 ( struct V_12 * V_13 ,
unsigned V_30 )
{
struct V_1 * V_2 = F_6 ( V_13 ) ;
int V_25 , V_31 , V_3 , V_14 = F_7 ( V_13 ) ;
T_1 V_8 ;
int V_7 ;
V_31 = V_13 -> V_32 -> V_33 [ V_30 ] ;
F_10 ( V_2 -> V_5 ) ;
V_7 = F_3 ( V_2 -> V_5 ,
V_16 [ V_14 ] . V_26 , & V_8 ) ;
if ( V_7 )
goto V_34;
if ( V_31 > 1375000 )
V_25 = 1 ;
else if ( V_31 < 1100000 )
V_25 = 0 ;
else
V_25 = V_8 & V_27 ;
if ( V_25 ) {
V_31 = ( V_31 - 1100000 ) / 25000 ;
V_31 |= V_27 ;
} else
V_31 = ( V_31 - 600000 ) / 25000 ;
V_3 = V_16 [ V_14 ] . V_28 | V_27 ;
V_8 = ( V_8 & ~ V_3 ) |
( V_31 << V_16 [ V_14 ] . V_29 ) ;
V_7 = F_4 ( V_2 -> V_5 , V_16 [ V_14 ] . V_26 ,
V_8 ) ;
V_34:
F_11 ( V_2 -> V_5 ) ;
return V_7 ;
}
static int F_16 ( struct V_12 * V_13 , unsigned int V_35 )
{
unsigned int V_15 = 0 ;
struct V_1 * V_2 = F_6 ( V_13 ) ;
int V_7 , V_14 = F_7 ( V_13 ) ;
if ( V_35 == V_36 )
V_15 = V_37 ;
F_10 ( V_2 -> V_5 ) ;
V_7 = F_17 ( V_2 -> V_5 , V_16 [ V_14 ] . V_24 ,
V_37 , V_15 ) ;
F_11 ( V_2 -> V_5 ) ;
return V_7 ;
}
static unsigned int F_18 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_6 ( V_13 ) ;
int V_7 , V_14 = F_7 ( V_13 ) ;
unsigned int V_4 ;
F_10 ( V_2 -> V_5 ) ;
V_7 = F_3 ( V_2 -> V_5 , V_16 [ V_14 ] . V_24 , & V_4 ) ;
F_11 ( V_2 -> V_5 ) ;
if ( V_7 )
return V_7 ;
if ( V_4 & V_37 )
return V_36 ;
return V_38 ;
}
static int T_2 F_19 ( struct V_39 * V_40 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_20 ( V_40 -> V_41 . V_42 ) ;
struct V_43 * V_44 =
F_21 ( & V_40 -> V_41 ) ;
struct V_45 * V_46 ;
struct V_47 V_48 = { } ;
int V_49 , V_7 ;
int V_50 = 0 ;
T_1 V_4 ;
V_50 = F_22 ( V_40 ) ;
if ( V_50 <= 0 && V_44 )
V_50 = V_44 -> V_50 ;
if ( V_50 <= 0 )
return - V_51 ;
V_2 = F_23 ( & V_40 -> V_41 , sizeof( * V_2 ) +
V_50 * sizeof( V_2 -> V_52 [ 0 ] ) ,
V_53 ) ;
if ( ! V_2 )
return - V_54 ;
V_2 -> V_50 = V_50 ;
V_2 -> V_55 = V_16 ;
V_2 -> V_5 = V_6 ;
F_24 ( V_40 , V_2 ) ;
F_10 ( V_6 ) ;
V_7 = F_3 ( V_6 , V_56 , & V_4 ) ;
if ( V_7 )
goto V_57;
if ( ( V_4 & 0x0000FFFF ) == 0x45d0 ) {
V_7 = F_17 ( V_6 , V_58 ,
V_59 |
V_60 ,
V_61 |
V_62 ) ;
if ( V_7 )
goto V_57;
V_7 = F_17 ( V_6 , V_63 ,
V_64 |
V_65 ,
V_66 |
V_67 ) ;
if ( V_7 )
goto V_57;
}
F_11 ( V_6 ) ;
V_16 [ V_68 ] . V_32 . V_69 -> V_70
= F_16 ;
V_16 [ V_68 ] . V_32 . V_69 -> V_71
= F_18 ;
V_46 = F_25 ( V_40 , V_16 ,
F_26 ( V_16 ) ) ;
for ( V_49 = 0 ; V_49 < V_50 ; V_49 ++ ) {
struct V_72 * V_73 ;
struct V_74 * V_32 ;
struct V_75 * V_76 = NULL ;
int V_14 ;
if ( V_46 ) {
V_14 = V_46 [ V_49 ] . V_14 ;
V_73 = V_46 [ V_49 ] . V_73 ;
V_76 = V_46 [ V_49 ] . V_76 ;
} else {
V_14 = V_44 -> V_52 [ V_49 ] . V_14 ;
V_73 = V_44 -> V_52 [ V_49 ] . V_73 ;
}
V_32 = & V_16 [ V_14 ] . V_32 ;
V_48 . V_41 = & V_40 -> V_41 ;
V_48 . V_73 = V_73 ;
V_48 . V_77 = V_2 ;
V_48 . V_78 = V_76 ;
V_2 -> V_52 [ V_49 ] = F_27 ( V_32 , & V_48 ) ;
if ( F_28 ( V_2 -> V_52 [ V_49 ] ) ) {
F_29 ( & V_40 -> V_41 , L_3 ,
V_16 [ V_49 ] . V_32 . V_79 ) ;
V_7 = F_30 ( V_2 -> V_52 [ V_49 ] ) ;
goto V_34;
}
}
return 0 ;
V_34:
while ( -- V_49 >= 0 )
F_31 ( V_2 -> V_52 [ V_49 ] ) ;
return V_7 ;
V_57:
F_11 ( V_6 ) ;
return V_7 ;
}
static int T_3 F_32 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_33 ( V_40 ) ;
int V_49 ;
F_24 ( V_40 , NULL ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_50 ; V_49 ++ )
F_31 ( V_2 -> V_52 [ V_49 ] ) ;
return 0 ;
}
static int T_4 F_34 ( void )
{
return F_35 ( & V_80 ) ;
}
static void T_5 F_36 ( void )
{
F_37 ( & V_80 ) ;
}
