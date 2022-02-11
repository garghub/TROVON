static void F_1 ( struct V_1 * V_1 )
{
unsigned int V_2 , V_3 ;
T_1 V_4 = 0 ;
if ( V_1 -> V_5 > V_6 )
V_2 = V_6 ;
else
V_2 = V_1 -> V_5 ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ ) {
if ( V_1 -> V_7 ) {
if ( V_1 -> V_8 == 1 ) {
V_4 = * V_1 -> V_7 ++ ;
} else {
V_4 = * V_1 -> V_7 ++ ;
V_4 = * V_1 -> V_7 ++ | ( V_4 << 8 ) ;
}
}
F_2 ( V_4 , V_1 -> V_9 + V_10 ) ;
}
}
static void F_3 ( struct V_1 * V_1 )
{
unsigned int V_2 , V_3 ;
T_1 V_4 = 0 ;
if ( V_1 -> V_5 > V_6 )
V_2 = V_6 ;
else
V_2 = V_1 -> V_5 ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ ) {
V_4 = F_4 ( V_1 -> V_9 + V_11 ) ;
if ( V_1 -> V_12 ) {
if ( V_1 -> V_8 == 1 ) {
* V_1 -> V_12 ++ = ( V_13 ) V_4 ;
} else {
* V_1 -> V_12 ++ = ( V_4 >> 8 ) ;
* V_1 -> V_12 ++ = V_4 & 0xff ;
}
}
}
V_1 -> V_5 -= V_2 ;
}
static int F_5 ( struct V_14 * V_15 ,
struct V_16 * V_17 , struct V_18 * V_19 )
{
struct V_1 * V_1 = F_6 ( V_15 ) ;
T_1 V_20 = 0 ;
V_1 -> V_7 = V_19 -> V_21 ;
V_1 -> V_12 = V_19 -> V_22 ;
if ( V_17 -> V_23 > 8 ) {
V_1 -> V_8 = 2 ;
V_1 -> V_5 = V_19 -> V_24 / 2 ;
} else if ( V_17 -> V_23 == 8 && ! ( V_19 -> V_24 & 0x1 ) ) {
V_1 -> V_8 = 2 ;
V_1 -> V_5 = V_19 -> V_24 / 2 ;
V_20 = F_4 ( V_1 -> V_9 + V_25 ) ;
F_2 ( ( V_20 | 0xf ) , V_1 -> V_9 + V_25 ) ;
F_4 ( V_1 -> V_9 + V_11 ) ;
} else {
V_1 -> V_8 = 1 ;
V_1 -> V_5 = V_19 -> V_24 ;
}
F_7 ( & V_1 -> V_26 ) ;
F_1 ( V_1 ) ;
F_2 ( V_27 , V_1 -> V_9 + V_28 ) ;
F_8 ( & V_1 -> V_26 ) ;
if ( V_20 )
F_2 ( V_20 , V_1 -> V_9 + V_25 ) ;
F_9 ( V_17 -> V_15 ) ;
return V_19 -> V_24 ;
}
static void F_10 ( struct V_16 * V_17 )
{
int V_29 = V_17 -> V_30 ;
if ( F_11 ( V_29 ) )
F_12 ( & V_17 -> V_31 , V_29 ) ;
}
static int F_13 ( struct V_16 * V_17 )
{
struct V_1 * V_1 = F_6 ( V_17 -> V_15 ) ;
T_2 V_32 , V_33 , V_34 ;
T_2 V_35 = V_17 -> V_36 ;
int V_29 = V_17 -> V_30 ;
int V_37 ;
if ( ! V_35 ) {
F_14 ( & V_17 -> V_31 , L_1 ) ;
return - V_38 ;
}
if ( ! F_11 ( V_29 ) ) {
F_14 ( & V_17 -> V_31 , L_2 , V_29 ) ;
return - V_38 ;
}
if ( F_15 ( & V_17 -> V_31 , V_29 , F_16 ( & V_17 -> V_31 ) ) ) {
F_14 ( & V_17 -> V_31 , L_3 , V_29 ) ;
return - V_38 ;
}
V_37 = F_17 ( V_29 , V_17 -> V_39 & V_40 ) ;
if ( V_37 )
return V_37 ;
V_32 = F_18 ( V_1 -> V_41 ) ;
V_33 = V_32 / ( 2 * V_35 ) ;
if ( V_33 < 0x07 || V_33 > F_19 ( 16 ) ) {
F_14 ( & V_17 -> V_31 ,
L_4 , V_33 , V_35 ) ;
return - V_38 ;
}
V_1 -> V_42 = V_32 / ( 2 * V_33 ) ;
if ( V_33 == F_19 ( 16 ) )
V_33 = 0x0 ;
F_2 ( V_33 , V_1 -> V_9 + V_43 ) ;
F_20 ( & V_17 -> V_31 ,
L_5 ,
V_35 , V_1 -> V_42 , V_33 ) ;
V_34 = F_4 ( V_1 -> V_9 + V_25 ) ;
V_34 |= V_44 ;
if ( V_17 -> V_39 & V_45 )
V_34 |= V_46 ;
else
V_34 &= ~ V_46 ;
if ( V_17 -> V_39 & V_47 )
V_34 |= V_48 ;
else
V_34 &= ~ V_48 ;
if ( ( V_17 -> V_39 & V_49 ) == 0 )
V_34 |= V_50 ;
else
V_34 &= ~ V_50 ;
if ( V_17 -> V_39 & V_51 )
V_34 |= V_52 ;
else
V_34 &= ~ V_52 ;
V_34 &= ~ V_53 ;
V_34 |= ( V_17 -> V_23 - 1 ) ;
V_34 |= V_54 | V_55 ;
V_34 |= V_56 ;
F_2 ( V_34 , V_1 -> V_9 + V_25 ) ;
F_4 ( V_1 -> V_9 + V_11 ) ;
return 0 ;
}
static T_3 F_21 ( int V_57 , void * V_58 )
{
struct V_1 * V_1 = (struct V_1 * ) V_58 ;
F_3 ( V_1 ) ;
if ( V_1 -> V_5 ) {
F_1 ( V_1 ) ;
} else {
F_2 ( 0x0 , V_1 -> V_9 + V_28 ) ;
F_22 ( V_1 -> V_9 + V_28 ) ;
F_23 ( & V_1 -> V_26 ) ;
}
return V_59 ;
}
static int F_24 ( struct V_60 * V_61 )
{
struct V_62 * V_63 = V_61 -> V_31 . V_64 ;
struct V_14 * V_15 ;
struct V_65 * V_66 ;
struct V_1 * V_1 ;
int V_57 , V_37 = 0 ;
T_2 V_34 ;
V_15 = F_25 ( & V_61 -> V_31 , sizeof( * V_1 ) ) ;
if ( ! V_15 )
return - V_67 ;
V_15 -> V_31 . V_64 = V_63 ;
V_15 -> V_68 = V_69 ;
V_15 -> V_70 = F_13 ;
V_15 -> V_71 = F_10 ;
V_15 -> V_72 = F_5 ;
V_15 -> V_73 = F_26 ( 8 ) | F_26 ( 16 ) ;
V_15 -> V_74 = true ;
V_15 -> V_75 = V_61 -> V_76 ;
V_1 = F_6 ( V_15 ) ;
V_1 -> V_41 = F_27 ( & V_61 -> V_31 , L_6 ) ;
if ( F_28 ( V_1 -> V_41 ) ) {
F_14 ( & V_61 -> V_31 , L_7 ) ;
V_37 = F_29 ( V_1 -> V_41 ) ;
goto V_77;
}
V_37 = F_30 ( V_1 -> V_41 ) ;
if ( V_37 )
goto V_77;
F_31 ( & V_1 -> V_26 ) ;
V_66 = F_32 ( V_61 , V_78 , 0 ) ;
V_1 -> V_9 = F_33 ( & V_61 -> V_31 , V_66 ) ;
if ( F_28 ( V_1 -> V_9 ) ) {
V_37 = F_29 ( V_1 -> V_9 ) ;
goto V_79;
}
F_2 ( 0x0 , V_1 -> V_9 + V_80 ) ;
V_34 = F_34 ( V_1 -> V_9 + V_25 ) ;
V_34 |= V_81 ;
F_2 ( V_34 , V_1 -> V_9 + V_25 ) ;
F_35 ( 1 ) ;
V_34 = F_4 ( V_1 -> V_9 + V_25 ) ;
V_34 &= ~ V_81 ;
F_2 ( V_34 , V_1 -> V_9 + V_25 ) ;
V_34 = F_4 ( V_1 -> V_9 + V_25 ) ;
V_34 &= ~ V_44 ;
F_2 ( V_34 , V_1 -> V_9 + V_25 ) ;
V_57 = F_36 ( V_63 , 0 ) ;
if ( ! V_57 ) {
F_14 ( & V_61 -> V_31 , L_8 ) ;
V_37 = - V_38 ;
goto V_79;
}
V_37 = F_37 ( & V_61 -> V_31 , V_57 , F_21 , 0 ,
V_61 -> V_82 , V_1 ) ;
if ( V_37 ) {
F_14 ( & V_61 -> V_31 , L_9 , V_57 ) ;
goto V_79;
}
F_38 ( & V_61 -> V_31 ) ;
F_39 ( & V_61 -> V_31 ) ;
F_40 ( V_61 , V_15 ) ;
V_37 = F_41 ( & V_61 -> V_31 , V_15 ) ;
if ( V_37 ) {
F_14 ( & V_61 -> V_31 , L_10 ) ;
goto V_79;
}
return 0 ;
V_79:
F_42 ( V_1 -> V_41 ) ;
V_77:
F_43 ( V_15 ) ;
return V_37 ;
}
static int F_44 ( struct V_60 * V_61 )
{
struct V_14 * V_15 = F_45 ( V_61 ) ;
struct V_1 * V_1 = F_6 ( V_15 ) ;
F_42 ( V_1 -> V_41 ) ;
F_46 ( & V_61 -> V_31 ) ;
return 0 ;
}
static int F_47 ( struct V_83 * V_31 )
{
struct V_14 * V_15 = F_48 ( V_31 ) ;
struct V_1 * V_1 = F_6 ( V_15 ) ;
F_2 ( 0 , V_1 -> V_9 + V_28 ) ;
F_46 ( V_31 ) ;
F_42 ( V_1 -> V_41 ) ;
return 0 ;
}
static int F_49 ( struct V_83 * V_31 )
{
struct V_14 * V_15 = F_48 ( V_31 ) ;
struct V_1 * V_1 = F_6 ( V_15 ) ;
int V_37 ;
V_37 = F_30 ( V_1 -> V_41 ) ;
F_50 ( V_31 ) ;
return V_37 ;
}
static int F_51 ( struct V_83 * V_31 )
{
struct V_14 * V_15 = F_48 ( V_31 ) ;
int V_37 ;
V_37 = F_52 ( V_15 ) ;
if ( V_37 )
return V_37 ;
return F_53 ( V_31 ) ;
}
static int F_54 ( struct V_83 * V_31 )
{
struct V_14 * V_15 = F_48 ( V_31 ) ;
int V_37 ;
V_37 = F_55 ( V_15 ) ;
if ( V_37 )
return V_37 ;
return F_56 ( V_31 ) ;
}
