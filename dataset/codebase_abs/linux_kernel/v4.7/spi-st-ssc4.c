static int F_1 ( struct V_1 * V_1 )
{
return 0 ;
return F_2 ( V_1 -> V_2 ) ;
}
static void F_3 ( struct V_1 * V_1 )
{
return;
F_4 ( V_1 -> V_2 ) ;
}
static void F_5 ( struct V_1 * V_1 )
{
unsigned int V_3 , V_4 ;
T_1 V_5 = 0 ;
if ( V_1 -> V_6 > V_7 )
V_3 = V_7 ;
else
V_3 = V_1 -> V_6 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
if ( V_1 -> V_8 ) {
if ( V_1 -> V_9 == 1 ) {
V_5 = * V_1 -> V_8 ++ ;
} else {
V_5 = * V_1 -> V_8 ++ ;
V_5 = * V_1 -> V_8 ++ | ( V_5 << 8 ) ;
}
}
F_6 ( V_5 , V_1 -> V_10 + V_11 ) ;
}
}
static void F_7 ( struct V_1 * V_1 )
{
unsigned int V_3 , V_4 ;
T_1 V_5 = 0 ;
if ( V_1 -> V_6 > V_7 )
V_3 = V_7 ;
else
V_3 = V_1 -> V_6 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
V_5 = F_8 ( V_1 -> V_10 + V_12 ) ;
if ( V_1 -> V_13 ) {
if ( V_1 -> V_9 == 1 ) {
* V_1 -> V_13 ++ = ( V_14 ) V_5 ;
} else {
* V_1 -> V_13 ++ = ( V_5 >> 8 ) ;
* V_1 -> V_13 ++ = V_5 & 0xff ;
}
}
}
V_1 -> V_6 -= V_3 ;
}
static int F_9 ( struct V_15 * V_16 ,
struct V_17 * V_18 , struct V_19 * V_20 )
{
struct V_1 * V_1 = F_10 ( V_16 ) ;
T_1 V_21 = 0 ;
V_1 -> V_8 = V_20 -> V_22 ;
V_1 -> V_13 = V_20 -> V_23 ;
if ( V_18 -> V_24 > 8 ) {
V_1 -> V_9 = 2 ;
V_1 -> V_6 = V_20 -> V_25 / 2 ;
} else if ( V_18 -> V_24 == 8 && ! ( V_20 -> V_25 & 0x1 ) ) {
V_1 -> V_9 = 2 ;
V_1 -> V_6 = V_20 -> V_25 / 2 ;
V_21 = F_8 ( V_1 -> V_10 + V_26 ) ;
F_6 ( ( V_21 | 0xf ) , V_1 -> V_10 + V_26 ) ;
F_8 ( V_1 -> V_10 + V_12 ) ;
} else {
V_1 -> V_9 = 1 ;
V_1 -> V_6 = V_20 -> V_25 ;
}
F_11 ( & V_1 -> V_27 ) ;
F_5 ( V_1 ) ;
F_6 ( V_28 , V_1 -> V_10 + V_29 ) ;
F_12 ( & V_1 -> V_27 ) ;
if ( V_21 )
F_6 ( V_21 , V_1 -> V_10 + V_26 ) ;
F_13 ( V_18 -> V_16 ) ;
return V_20 -> V_25 ;
}
static void F_14 ( struct V_17 * V_18 )
{
int V_30 = V_18 -> V_31 ;
if ( F_15 ( V_30 ) )
F_16 ( & V_18 -> V_32 , V_30 ) ;
}
static int F_17 ( struct V_17 * V_18 )
{
struct V_1 * V_1 = F_10 ( V_18 -> V_16 ) ;
T_2 V_33 , V_34 , V_35 ;
T_2 V_36 = V_18 -> V_37 ;
int V_30 = V_18 -> V_31 ;
int V_38 ;
if ( ! V_36 ) {
F_18 ( & V_18 -> V_32 , L_1 ) ;
return - V_39 ;
}
if ( ! F_15 ( V_30 ) ) {
F_18 ( & V_18 -> V_32 , L_2 , V_30 ) ;
return - V_39 ;
}
if ( F_19 ( & V_18 -> V_32 , V_30 , F_20 ( & V_18 -> V_32 ) ) ) {
F_18 ( & V_18 -> V_32 , L_3 , V_30 ) ;
return - V_39 ;
}
V_38 = F_21 ( V_30 , V_18 -> V_40 & V_41 ) ;
if ( V_38 )
return V_38 ;
V_33 = F_22 ( V_1 -> V_2 ) ;
V_34 = V_33 / ( 2 * V_36 ) ;
if ( V_34 < 0x07 || V_34 > F_23 ( 16 ) ) {
F_18 ( & V_18 -> V_32 ,
L_4 , V_34 , V_36 ) ;
return - V_39 ;
}
V_1 -> V_42 = V_33 / ( 2 * V_34 ) ;
if ( V_34 == F_23 ( 16 ) )
V_34 = 0x0 ;
F_6 ( V_34 , V_1 -> V_10 + V_43 ) ;
F_24 ( & V_18 -> V_32 ,
L_5 ,
V_36 , V_1 -> V_42 , V_34 ) ;
V_35 = F_8 ( V_1 -> V_10 + V_26 ) ;
V_35 |= V_44 ;
if ( V_18 -> V_40 & V_45 )
V_35 |= V_46 ;
else
V_35 &= ~ V_46 ;
if ( V_18 -> V_40 & V_47 )
V_35 |= V_48 ;
else
V_35 &= ~ V_48 ;
if ( ( V_18 -> V_40 & V_49 ) == 0 )
V_35 |= V_50 ;
else
V_35 &= ~ V_50 ;
if ( V_18 -> V_40 & V_51 )
V_35 |= V_52 ;
else
V_35 &= ~ V_52 ;
V_35 &= ~ V_53 ;
V_35 |= ( V_18 -> V_24 - 1 ) ;
V_35 |= V_54 | V_55 ;
V_35 |= V_56 ;
F_6 ( V_35 , V_1 -> V_10 + V_26 ) ;
F_8 ( V_1 -> V_10 + V_12 ) ;
return 0 ;
}
static T_3 F_25 ( int V_57 , void * V_58 )
{
struct V_1 * V_1 = (struct V_1 * ) V_58 ;
F_7 ( V_1 ) ;
if ( V_1 -> V_6 ) {
F_5 ( V_1 ) ;
} else {
F_6 ( 0x0 , V_1 -> V_10 + V_29 ) ;
F_26 ( V_1 -> V_10 + V_29 ) ;
F_27 ( & V_1 -> V_27 ) ;
}
return V_59 ;
}
static int F_28 ( struct V_60 * V_61 )
{
struct V_62 * V_63 = V_61 -> V_32 . V_64 ;
struct V_15 * V_16 ;
struct V_65 * V_66 ;
struct V_1 * V_1 ;
int V_57 , V_38 = 0 ;
T_2 V_35 ;
V_16 = F_29 ( & V_61 -> V_32 , sizeof( * V_1 ) ) ;
if ( ! V_16 )
return - V_67 ;
V_16 -> V_32 . V_64 = V_63 ;
V_16 -> V_68 = V_69 ;
V_16 -> V_70 = F_17 ;
V_16 -> V_71 = F_14 ;
V_16 -> V_72 = F_9 ;
V_16 -> V_73 = F_30 ( 8 ) | F_30 ( 16 ) ;
V_16 -> V_74 = true ;
V_16 -> V_75 = V_61 -> V_76 ;
V_1 = F_10 ( V_16 ) ;
V_1 -> V_2 = F_31 ( & V_61 -> V_32 , L_6 ) ;
if ( F_32 ( V_1 -> V_2 ) ) {
F_18 ( & V_61 -> V_32 , L_7 ) ;
V_38 = F_33 ( V_1 -> V_2 ) ;
goto V_77;
}
V_38 = F_1 ( V_1 ) ;
if ( V_38 )
goto V_77;
F_34 ( & V_1 -> V_27 ) ;
V_66 = F_35 ( V_61 , V_78 , 0 ) ;
V_1 -> V_10 = F_36 ( & V_61 -> V_32 , V_66 ) ;
if ( F_32 ( V_1 -> V_10 ) ) {
V_38 = F_33 ( V_1 -> V_10 ) ;
goto V_79;
}
F_6 ( 0x0 , V_1 -> V_10 + V_80 ) ;
V_35 = F_37 ( V_1 -> V_10 + V_26 ) ;
V_35 |= V_81 ;
F_6 ( V_35 , V_1 -> V_10 + V_26 ) ;
F_38 ( 1 ) ;
V_35 = F_8 ( V_1 -> V_10 + V_26 ) ;
V_35 &= ~ V_81 ;
F_6 ( V_35 , V_1 -> V_10 + V_26 ) ;
V_35 = F_8 ( V_1 -> V_10 + V_26 ) ;
V_35 &= ~ V_44 ;
F_6 ( V_35 , V_1 -> V_10 + V_26 ) ;
V_57 = F_39 ( V_63 , 0 ) ;
if ( ! V_57 ) {
F_18 ( & V_61 -> V_32 , L_8 ) ;
V_38 = - V_39 ;
goto V_79;
}
V_38 = F_40 ( & V_61 -> V_32 , V_57 , F_25 , 0 ,
V_61 -> V_82 , V_1 ) ;
if ( V_38 ) {
F_18 ( & V_61 -> V_32 , L_9 , V_57 ) ;
goto V_79;
}
F_41 ( & V_61 -> V_32 ) ;
F_42 ( & V_61 -> V_32 ) ;
F_43 ( V_61 , V_16 ) ;
V_38 = F_44 ( & V_61 -> V_32 , V_16 ) ;
if ( V_38 ) {
F_18 ( & V_61 -> V_32 , L_10 ) ;
goto V_79;
}
return 0 ;
V_79:
F_3 ( V_1 ) ;
V_77:
F_45 ( V_16 ) ;
return V_38 ;
}
static int F_46 ( struct V_60 * V_61 )
{
struct V_15 * V_16 = F_47 ( V_61 ) ;
struct V_1 * V_1 = F_10 ( V_16 ) ;
F_3 ( V_1 ) ;
F_48 ( & V_61 -> V_32 ) ;
return 0 ;
}
static int F_49 ( struct V_83 * V_32 )
{
struct V_15 * V_16 = F_50 ( V_32 ) ;
struct V_1 * V_1 = F_10 ( V_16 ) ;
F_6 ( 0 , V_1 -> V_10 + V_29 ) ;
F_48 ( V_32 ) ;
F_3 ( V_1 ) ;
return 0 ;
}
static int F_51 ( struct V_83 * V_32 )
{
struct V_15 * V_16 = F_50 ( V_32 ) ;
struct V_1 * V_1 = F_10 ( V_16 ) ;
int V_38 ;
V_38 = F_1 ( V_1 ) ;
F_52 ( V_32 ) ;
return V_38 ;
}
static int F_53 ( struct V_83 * V_32 )
{
struct V_15 * V_16 = F_50 ( V_32 ) ;
int V_38 ;
V_38 = F_54 ( V_16 ) ;
if ( V_38 )
return V_38 ;
return F_55 ( V_32 ) ;
}
static int F_56 ( struct V_83 * V_32 )
{
struct V_15 * V_16 = F_50 ( V_32 ) ;
int V_38 ;
V_38 = F_57 ( V_16 ) ;
if ( V_38 )
return V_38 ;
return F_58 ( V_32 ) ;
}
