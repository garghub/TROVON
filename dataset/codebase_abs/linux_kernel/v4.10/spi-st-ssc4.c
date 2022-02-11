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
F_11 ( V_17 -> V_29 ) ;
}
static int F_12 ( struct V_16 * V_17 )
{
struct V_1 * V_1 = F_6 ( V_17 -> V_15 ) ;
T_2 V_30 , V_31 , V_32 ;
T_2 V_33 = V_17 -> V_34 ;
int V_35 = V_17 -> V_29 ;
int V_36 ;
if ( ! V_33 ) {
F_13 ( & V_17 -> V_37 , L_1 ) ;
return - V_38 ;
}
if ( ! F_14 ( V_35 ) ) {
F_13 ( & V_17 -> V_37 , L_2 , V_35 ) ;
return - V_38 ;
}
V_36 = F_15 ( V_35 , F_16 ( & V_17 -> V_37 ) ) ;
if ( V_36 ) {
F_13 ( & V_17 -> V_37 , L_3 , V_35 ) ;
return V_36 ;
}
V_36 = F_17 ( V_35 , V_17 -> V_39 & V_40 ) ;
if ( V_36 )
goto V_41;
V_30 = F_18 ( V_1 -> V_42 ) ;
V_31 = V_30 / ( 2 * V_33 ) ;
if ( V_31 < 0x07 || V_31 > F_19 ( 16 ) ) {
F_13 ( & V_17 -> V_37 ,
L_4 , V_31 , V_33 ) ;
V_36 = - V_38 ;
goto V_41;
}
V_1 -> V_43 = V_30 / ( 2 * V_31 ) ;
if ( V_31 == F_19 ( 16 ) )
V_31 = 0x0 ;
F_2 ( V_31 , V_1 -> V_9 + V_44 ) ;
F_20 ( & V_17 -> V_37 ,
L_5 ,
V_33 , V_1 -> V_43 , V_31 ) ;
V_32 = F_4 ( V_1 -> V_9 + V_25 ) ;
V_32 |= V_45 ;
if ( V_17 -> V_39 & V_46 )
V_32 |= V_47 ;
else
V_32 &= ~ V_47 ;
if ( V_17 -> V_39 & V_48 )
V_32 |= V_49 ;
else
V_32 &= ~ V_49 ;
if ( ( V_17 -> V_39 & V_50 ) == 0 )
V_32 |= V_51 ;
else
V_32 &= ~ V_51 ;
if ( V_17 -> V_39 & V_52 )
V_32 |= V_53 ;
else
V_32 &= ~ V_53 ;
V_32 &= ~ V_54 ;
V_32 |= ( V_17 -> V_23 - 1 ) ;
V_32 |= V_55 | V_56 ;
V_32 |= V_57 ;
F_2 ( V_32 , V_1 -> V_9 + V_25 ) ;
F_4 ( V_1 -> V_9 + V_11 ) ;
return 0 ;
V_41:
F_11 ( V_35 ) ;
return V_36 ;
}
static T_3 F_21 ( int V_58 , void * V_59 )
{
struct V_1 * V_1 = (struct V_1 * ) V_59 ;
F_3 ( V_1 ) ;
if ( V_1 -> V_5 ) {
F_1 ( V_1 ) ;
} else {
F_2 ( 0x0 , V_1 -> V_9 + V_28 ) ;
F_22 ( V_1 -> V_9 + V_28 ) ;
F_23 ( & V_1 -> V_26 ) ;
}
return V_60 ;
}
static int F_24 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = V_62 -> V_37 . V_65 ;
struct V_14 * V_15 ;
struct V_66 * V_67 ;
struct V_1 * V_1 ;
int V_58 , V_36 = 0 ;
T_2 V_32 ;
V_15 = F_25 ( & V_62 -> V_37 , sizeof( * V_1 ) ) ;
if ( ! V_15 )
return - V_68 ;
V_15 -> V_37 . V_65 = V_64 ;
V_15 -> V_69 = V_70 ;
V_15 -> V_71 = F_12 ;
V_15 -> V_72 = F_10 ;
V_15 -> V_73 = F_5 ;
V_15 -> V_74 = F_26 ( 8 ) | F_26 ( 16 ) ;
V_15 -> V_75 = true ;
V_15 -> V_76 = V_62 -> V_77 ;
V_1 = F_6 ( V_15 ) ;
V_1 -> V_42 = F_27 ( & V_62 -> V_37 , L_6 ) ;
if ( F_28 ( V_1 -> V_42 ) ) {
F_13 ( & V_62 -> V_37 , L_7 ) ;
V_36 = F_29 ( V_1 -> V_42 ) ;
goto V_78;
}
V_36 = F_30 ( V_1 -> V_42 ) ;
if ( V_36 )
goto V_78;
F_31 ( & V_1 -> V_26 ) ;
V_67 = F_32 ( V_62 , V_79 , 0 ) ;
V_1 -> V_9 = F_33 ( & V_62 -> V_37 , V_67 ) ;
if ( F_28 ( V_1 -> V_9 ) ) {
V_36 = F_29 ( V_1 -> V_9 ) ;
goto V_80;
}
F_2 ( 0x0 , V_1 -> V_9 + V_81 ) ;
V_32 = F_34 ( V_1 -> V_9 + V_25 ) ;
V_32 |= V_82 ;
F_2 ( V_32 , V_1 -> V_9 + V_25 ) ;
F_35 ( 1 ) ;
V_32 = F_4 ( V_1 -> V_9 + V_25 ) ;
V_32 &= ~ V_82 ;
F_2 ( V_32 , V_1 -> V_9 + V_25 ) ;
V_32 = F_4 ( V_1 -> V_9 + V_25 ) ;
V_32 &= ~ V_45 ;
F_2 ( V_32 , V_1 -> V_9 + V_25 ) ;
V_58 = F_36 ( V_64 , 0 ) ;
if ( ! V_58 ) {
F_13 ( & V_62 -> V_37 , L_8 ) ;
V_36 = - V_38 ;
goto V_80;
}
V_36 = F_37 ( & V_62 -> V_37 , V_58 , F_21 , 0 ,
V_62 -> V_83 , V_1 ) ;
if ( V_36 ) {
F_13 ( & V_62 -> V_37 , L_9 , V_58 ) ;
goto V_80;
}
F_38 ( & V_62 -> V_37 ) ;
F_39 ( & V_62 -> V_37 ) ;
F_40 ( V_62 , V_15 ) ;
V_36 = F_41 ( & V_62 -> V_37 , V_15 ) ;
if ( V_36 ) {
F_13 ( & V_62 -> V_37 , L_10 ) ;
goto V_80;
}
return 0 ;
V_80:
F_42 ( V_1 -> V_42 ) ;
V_78:
F_43 ( V_15 ) ;
return V_36 ;
}
static int F_44 ( struct V_61 * V_62 )
{
struct V_14 * V_15 = F_45 ( V_62 ) ;
struct V_1 * V_1 = F_6 ( V_15 ) ;
F_42 ( V_1 -> V_42 ) ;
F_46 ( & V_62 -> V_37 ) ;
return 0 ;
}
static int F_47 ( struct V_84 * V_37 )
{
struct V_14 * V_15 = F_48 ( V_37 ) ;
struct V_1 * V_1 = F_6 ( V_15 ) ;
F_2 ( 0 , V_1 -> V_9 + V_28 ) ;
F_46 ( V_37 ) ;
F_42 ( V_1 -> V_42 ) ;
return 0 ;
}
static int F_49 ( struct V_84 * V_37 )
{
struct V_14 * V_15 = F_48 ( V_37 ) ;
struct V_1 * V_1 = F_6 ( V_15 ) ;
int V_36 ;
V_36 = F_30 ( V_1 -> V_42 ) ;
F_50 ( V_37 ) ;
return V_36 ;
}
static int F_51 ( struct V_84 * V_37 )
{
struct V_14 * V_15 = F_48 ( V_37 ) ;
int V_36 ;
V_36 = F_52 ( V_15 ) ;
if ( V_36 )
return V_36 ;
return F_53 ( V_37 ) ;
}
static int F_54 ( struct V_84 * V_37 )
{
struct V_14 * V_15 = F_48 ( V_37 ) ;
int V_36 ;
V_36 = F_55 ( V_15 ) ;
if ( V_36 )
return V_36 ;
return F_56 ( V_37 ) ;
}
