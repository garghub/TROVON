static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_5 ;
int V_7 ;
T_1 V_8 ;
F_2 ( V_4 & ~ V_3 ) ;
F_3 ( V_2 -> V_5 ) ;
V_7 = F_4 ( V_6 , V_9 , & V_8 ) ;
if ( V_7 )
goto V_10;
V_2 -> V_11 =
( V_2 -> V_11 & ~ V_3 ) | V_4 ;
V_2 -> V_11 &= V_12 ;
V_8 = ( V_8 & ~ V_3 ) | V_4 ;
V_8 = ( V_8 & ~ V_12 ) |
V_2 -> V_11 ;
V_7 = F_5 ( V_6 , V_9 , V_8 ) ;
V_10:
F_6 ( V_2 -> V_5 ) ;
return V_7 ;
}
static int F_7 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_8 ( V_14 ) ;
int V_15 = F_9 ( V_14 ) ;
T_1 V_16 = V_17 [ V_15 ] . V_18 ;
T_1 V_3 = V_17 [ V_15 ] . V_18 ;
F_10 ( F_11 ( V_14 ) , L_1 , V_19 , V_15 ) ;
if ( V_15 == V_20 || V_15 == V_21 )
V_16 = 0 ;
if ( V_15 == V_22 )
V_3 |= V_23 ;
return F_1 ( V_2 , V_3 , V_16 ) ;
}
static int F_12 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_8 ( V_14 ) ;
int V_15 = F_9 ( V_14 ) ;
T_1 V_24 = 0 ;
F_10 ( F_11 ( V_14 ) , L_1 , V_19 , V_15 ) ;
if ( V_15 == V_20 || V_15 == V_21 )
V_24 = V_17 [ V_15 ] . V_18 ;
return F_1 ( V_2 , V_17 [ V_15 ] . V_18 ,
V_24 ) ;
}
static int F_13 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_8 ( V_14 ) ;
int V_7 , V_15 = F_9 ( V_14 ) ;
unsigned int V_4 ;
F_3 ( V_2 -> V_5 ) ;
V_7 = F_4 ( V_2 -> V_5 , V_17 [ V_15 ] . V_25 , & V_4 ) ;
F_6 ( V_2 -> V_5 ) ;
if ( V_7 )
return V_7 ;
V_4 = ( V_4 & ~ V_12 ) |
( V_2 -> V_11 ^ V_12 ) ;
return ( V_4 & V_17 [ V_15 ] . V_18 ) != 0 ;
}
static int F_14 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_8 ( V_14 ) ;
int V_7 , V_15 = F_9 ( V_14 ) ;
unsigned int V_4 , V_26 ;
F_10 ( F_11 ( V_14 ) , L_1 , V_19 , V_15 ) ;
F_3 ( V_2 -> V_5 ) ;
V_7 = F_4 ( V_2 -> V_5 ,
V_17 [ V_15 ] . V_27 , & V_4 ) ;
F_6 ( V_2 -> V_5 ) ;
if ( V_7 )
return V_7 ;
V_26 = V_4 & V_17 [ V_15 ] . V_28 ;
if ( ( V_17 [ V_15 ] . V_27 != V_29 ) &&
( V_4 & V_30 ) ) {
V_26 += V_31 ;
}
F_10 ( F_11 ( V_14 ) , L_2 ,
V_19 , V_15 , V_4 , V_26 ) ;
return V_26 ;
}
static int F_15 ( struct V_13 * V_14 ,
unsigned V_26 )
{
struct V_1 * V_2 = F_8 ( V_14 ) ;
int V_32 , V_3 , V_15 = F_9 ( V_14 ) ;
T_1 V_33 ;
int V_7 ;
V_32 = V_14 -> V_34 -> V_35 [ V_26 ] ;
V_3 = V_17 [ V_15 ] . V_28 ;
V_33 = V_26 ;
if ( V_17 [ V_15 ] . V_27 != V_29 ) {
V_3 |= V_30 ;
if ( V_32 > 1375000 ) {
V_33 -= V_31 ;
V_33 |= V_30 ;
} else {
V_33 &= ~ V_30 ;
}
}
F_3 ( V_2 -> V_5 ) ;
V_7 = F_16 ( V_2 -> V_5 , V_17 [ V_15 ] . V_27 , V_3 ,
V_33 ) ;
F_6 ( V_2 -> V_5 ) ;
return V_7 ;
}
static int F_17 ( struct V_13 * V_14 , unsigned int V_36 )
{
unsigned int V_16 = 0 ;
struct V_1 * V_2 = F_8 ( V_14 ) ;
int V_7 , V_15 = F_9 ( V_14 ) ;
if ( V_36 == V_37 )
V_16 = V_38 ;
F_3 ( V_2 -> V_5 ) ;
V_7 = F_16 ( V_2 -> V_5 , V_17 [ V_15 ] . V_25 ,
V_38 , V_16 ) ;
F_6 ( V_2 -> V_5 ) ;
return V_7 ;
}
static unsigned int F_18 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_8 ( V_14 ) ;
int V_7 , V_15 = F_9 ( V_14 ) ;
unsigned int V_4 ;
F_3 ( V_2 -> V_5 ) ;
V_7 = F_4 ( V_2 -> V_5 , V_17 [ V_15 ] . V_25 , & V_4 ) ;
F_6 ( V_2 -> V_5 ) ;
if ( V_7 )
return V_7 ;
if ( V_4 & V_38 )
return V_37 ;
return V_39 ;
}
static int F_19 ( struct V_40 * V_41 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_20 ( V_41 -> V_42 . V_43 ) ;
struct V_44 * V_45 =
F_21 ( & V_41 -> V_42 ) ;
struct V_46 * V_47 ;
struct V_48 V_49 = { } ;
int V_50 , V_7 ;
int V_51 = 0 ;
T_1 V_4 ;
V_51 = F_22 ( V_41 ) ;
if ( V_51 <= 0 && V_45 )
V_51 = V_45 -> V_51 ;
if ( V_51 <= 0 )
return - V_52 ;
V_2 = F_23 ( & V_41 -> V_42 , sizeof( * V_2 ) +
V_51 * sizeof( V_2 -> V_53 [ 0 ] ) ,
V_54 ) ;
if ( ! V_2 )
return - V_55 ;
V_2 -> V_51 = V_51 ;
V_2 -> V_56 = V_17 ;
V_2 -> V_5 = V_6 ;
F_24 ( V_41 , V_2 ) ;
F_3 ( V_6 ) ;
V_7 = F_4 ( V_6 , V_57 , & V_4 ) ;
if ( V_7 )
goto V_58;
if ( ( V_4 & 0x0000FFFF ) == 0x45d0 ) {
V_7 = F_16 ( V_6 , V_59 ,
V_60 |
V_61 ,
V_62 |
V_63 ) ;
if ( V_7 )
goto V_58;
V_7 = F_16 ( V_6 , V_64 ,
V_65 |
V_66 ,
V_67 |
V_68 ) ;
if ( V_7 )
goto V_58;
}
F_6 ( V_6 ) ;
V_17 [ V_69 ] . V_34 . V_70 -> V_71
= F_17 ;
V_17 [ V_69 ] . V_34 . V_70 -> V_72
= F_18 ;
V_47 = F_25 ( V_41 , V_17 ,
F_26 ( V_17 ) ) ;
for ( V_50 = 0 ; V_50 < V_2 -> V_51 ; V_50 ++ ) {
struct V_73 * V_74 ;
struct V_75 * V_34 ;
struct V_76 * V_77 = NULL ;
int V_15 ;
if ( V_47 ) {
V_15 = V_47 [ V_50 ] . V_15 ;
V_74 = V_47 [ V_50 ] . V_74 ;
V_77 = V_47 [ V_50 ] . V_77 ;
} else {
V_15 = V_45 -> V_53 [ V_50 ] . V_15 ;
V_74 = V_45 -> V_53 [ V_50 ] . V_74 ;
}
V_34 = & V_17 [ V_15 ] . V_34 ;
V_49 . V_42 = & V_41 -> V_42 ;
V_49 . V_74 = V_74 ;
V_49 . V_78 = V_2 ;
V_49 . V_79 = V_77 ;
V_2 -> V_53 [ V_50 ] = F_27 ( V_34 , & V_49 ) ;
if ( F_28 ( V_2 -> V_53 [ V_50 ] ) ) {
F_29 ( & V_41 -> V_42 , L_3 ,
V_17 [ V_50 ] . V_34 . V_80 ) ;
V_7 = F_30 ( V_2 -> V_53 [ V_50 ] ) ;
goto V_81;
}
}
return 0 ;
V_81:
while ( -- V_50 >= 0 )
F_31 ( V_2 -> V_53 [ V_50 ] ) ;
return V_7 ;
V_58:
F_6 ( V_6 ) ;
return V_7 ;
}
static int F_32 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_33 ( V_41 ) ;
int V_50 ;
F_24 ( V_41 , NULL ) ;
for ( V_50 = 0 ; V_50 < V_2 -> V_51 ; V_50 ++ )
F_31 ( V_2 -> V_53 [ V_50 ] ) ;
return 0 ;
}
static int T_2 F_34 ( void )
{
return F_35 ( & V_82 ) ;
}
static void T_3 F_36 ( void )
{
F_37 ( & V_82 ) ;
}
