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
int V_30 , int V_31 , unsigned * V_32 )
{
struct V_1 * V_2 = F_6 ( V_13 ) ;
int V_25 , V_33 , V_3 , V_14 = F_7 ( V_13 ) ;
T_1 V_8 ;
int V_7 ;
F_8 ( F_9 ( V_13 ) , L_3 ,
V_18 , V_14 , V_30 , V_31 ) ;
V_33 = F_16 ( V_13 , V_30 , V_31 ) ;
F_8 ( F_9 ( V_13 ) , L_4 , V_18 , V_33 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = V_16 [ V_14 ] . V_34 [ V_33 ] ;
F_10 ( V_2 -> V_5 ) ;
V_7 = F_3 ( V_2 -> V_5 ,
V_16 [ V_14 ] . V_26 , & V_8 ) ;
if ( V_7 )
goto V_35;
if ( V_33 > 1375000 )
V_25 = 1 ;
else if ( V_33 < 1100000 )
V_25 = 0 ;
else
V_25 = V_8 & V_27 ;
if ( V_25 ) {
V_33 = ( V_33 - 1100000 ) / 25000 ;
V_33 |= V_27 ;
} else
V_33 = ( V_33 - 600000 ) / 25000 ;
V_3 = V_16 [ V_14 ] . V_28 | V_27 ;
V_8 = ( V_8 & ~ V_3 ) |
( V_33 << V_16 [ V_14 ] . V_29 ) ;
V_7 = F_4 ( V_2 -> V_5 , V_16 [ V_14 ] . V_26 ,
V_8 ) ;
V_35:
F_11 ( V_2 -> V_5 ) ;
return V_7 ;
}
static int F_17 ( struct V_12 * V_13 , unsigned int V_36 )
{
unsigned int V_15 = 0 ;
struct V_1 * V_2 = F_6 ( V_13 ) ;
int V_7 , V_14 = F_7 ( V_13 ) ;
if ( V_36 == V_37 )
V_15 = V_38 ;
F_10 ( V_2 -> V_5 ) ;
V_7 = F_18 ( V_2 -> V_5 , V_16 [ V_14 ] . V_24 ,
V_38 , V_15 ) ;
F_11 ( V_2 -> V_5 ) ;
return V_7 ;
}
static unsigned int F_19 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_6 ( V_13 ) ;
int V_7 , V_14 = F_7 ( V_13 ) ;
unsigned int V_4 ;
F_10 ( V_2 -> V_5 ) ;
V_7 = F_3 ( V_2 -> V_5 , V_16 [ V_14 ] . V_24 , & V_4 ) ;
F_11 ( V_2 -> V_5 ) ;
if ( V_7 )
return V_7 ;
if ( V_4 & V_38 )
return V_37 ;
return V_39 ;
}
static int T_2 F_20 ( struct V_40 * V_41 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_21 ( V_41 -> V_42 . V_43 ) ;
struct V_44 * V_45 =
F_22 ( & V_41 -> V_42 ) ;
struct V_46 * V_47 ;
int V_48 , V_7 ;
int V_49 = 0 ;
T_1 V_4 ;
V_49 = F_23 ( V_41 ) ;
if ( V_49 <= 0 && V_45 )
V_49 = V_45 -> V_49 ;
if ( V_49 <= 0 )
return - V_50 ;
V_2 = F_24 ( & V_41 -> V_42 , sizeof( * V_2 ) +
V_49 * sizeof( V_2 -> V_51 [ 0 ] ) ,
V_52 ) ;
if ( ! V_2 )
return - V_53 ;
V_2 -> V_49 = V_49 ;
V_2 -> V_54 = V_16 ;
V_2 -> V_5 = V_6 ;
F_25 ( V_41 , V_2 ) ;
F_10 ( V_6 ) ;
V_7 = F_3 ( V_6 , V_55 , & V_4 ) ;
if ( V_7 )
goto V_56;
if ( ( V_4 & 0x0000FFFF ) == 0x45d0 ) {
V_7 = F_18 ( V_6 , V_57 ,
V_58 |
V_59 ,
V_60 |
V_61 ) ;
if ( V_7 )
goto V_56;
V_7 = F_18 ( V_6 , V_62 ,
V_63 |
V_64 ,
V_65 |
V_66 ) ;
if ( V_7 )
goto V_56;
}
F_11 ( V_6 ) ;
V_16 [ V_67 ] . V_68 . V_69 -> V_70
= F_17 ;
V_16 [ V_67 ] . V_68 . V_69 -> V_71
= F_19 ;
V_47 = F_26 ( V_41 , V_16 ,
F_27 ( V_16 ) ) ;
for ( V_48 = 0 ; V_48 < V_49 ; V_48 ++ ) {
struct V_72 * V_73 ;
struct V_74 * V_68 ;
struct V_75 * V_76 = NULL ;
int V_14 ;
if ( V_47 ) {
V_14 = V_47 [ V_48 ] . V_14 ;
V_73 = V_47 [ V_48 ] . V_73 ;
V_76 = V_47 [ V_48 ] . V_76 ;
} else {
V_14 = V_45 -> V_51 [ V_48 ] . V_14 ;
V_73 = V_45 -> V_51 [ V_48 ] . V_73 ;
}
V_68 = & V_16 [ V_14 ] . V_68 ;
V_2 -> V_51 [ V_48 ] = F_28 (
V_68 , & V_41 -> V_42 , V_73 , V_2 , V_76 ) ;
if ( F_29 ( V_2 -> V_51 [ V_48 ] ) ) {
F_30 ( & V_41 -> V_42 , L_5 ,
V_16 [ V_48 ] . V_68 . V_77 ) ;
V_7 = F_31 ( V_2 -> V_51 [ V_48 ] ) ;
goto V_35;
}
}
return 0 ;
V_35:
while ( -- V_48 >= 0 )
F_32 ( V_2 -> V_51 [ V_48 ] ) ;
V_56:
F_11 ( V_6 ) ;
return V_7 ;
}
static int T_3 F_33 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_34 ( V_41 ) ;
int V_48 ;
F_25 ( V_41 , NULL ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_49 ; V_48 ++ )
F_32 ( V_2 -> V_51 [ V_48 ] ) ;
return 0 ;
}
static int T_4 F_35 ( void )
{
return F_36 ( & V_78 ) ;
}
static void T_5 F_37 ( void )
{
F_38 ( & V_78 ) ;
}
