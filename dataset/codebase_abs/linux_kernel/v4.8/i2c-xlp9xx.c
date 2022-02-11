static inline void F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_6 )
{
T_1 V_7 ;
V_7 = F_3 ( V_2 , V_8 ) & ~ V_6 ;
F_1 ( V_2 , V_8 , V_7 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_6 )
{
T_1 V_7 ;
V_7 = F_3 ( V_2 , V_8 ) | V_6 ;
F_1 ( V_2 , V_8 , V_7 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_9 ;
V_9 = F_8 ( V_2 -> V_10 , V_11 ) ;
F_1 ( V_2 , V_12 ,
V_9 << V_13 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
T_1 V_14 , V_15 ;
T_2 * V_16 = V_2 -> V_17 ;
V_14 = F_8 ( V_2 -> V_10 , V_11 ) ;
for ( V_15 = 0 ; V_15 < V_14 ; V_15 ++ )
F_1 ( V_2 , V_18 , V_16 [ V_15 ] ) ;
V_2 -> V_10 -= V_14 ;
V_2 -> V_17 += V_14 ;
}
static void F_10 ( struct V_1 * V_2 )
{
T_1 V_14 , V_15 ;
T_2 * V_16 = V_2 -> V_17 ;
V_14 = F_3 ( V_2 , V_19 ) &
V_20 ;
V_14 = F_8 ( V_2 -> V_10 , V_14 ) ;
for ( V_15 = 0 ; V_15 < V_14 ; V_15 ++ , V_16 ++ )
* V_16 = F_3 ( V_2 , V_21 ) ;
V_2 -> V_10 -= V_14 ;
V_2 -> V_17 = V_16 ;
if ( V_2 -> V_10 )
F_7 ( V_2 ) ;
}
static T_3 F_11 ( int V_22 , void * V_23 )
{
struct V_1 * V_2 = V_23 ;
T_1 V_24 ;
V_24 = F_3 ( V_2 , V_25 ) ;
if ( V_24 == 0 )
return V_26 ;
F_1 ( V_2 , V_25 , V_24 ) ;
if ( V_24 & V_27 ) {
V_2 -> V_28 = V_24 ;
goto V_29;
}
if ( ( V_24 & V_30 ) && ( V_2 -> V_31 == 0 ) )
goto V_29;
if ( ! V_2 -> V_32 ) {
if ( V_24 & V_33 ) {
if ( V_2 -> V_10 )
F_9 ( V_2 ) ;
else
F_5 ( V_2 ,
V_33 ) ;
}
} else {
if ( V_24 & ( V_34 |
V_35 ) ) {
if ( V_2 -> V_10 )
F_10 ( V_2 ) ;
}
}
if ( V_24 & V_34 )
goto V_29;
return V_36 ;
V_29:
F_1 ( V_2 , V_8 , 0 ) ;
F_12 ( & V_2 -> V_37 ) ;
return V_36 ;
}
static int F_13 ( struct V_1 * V_2 )
{
T_1 V_38 ;
V_38 = F_14 ( V_39 , V_2 -> V_40 ) ;
V_38 = ( ( V_38 - 8 ) / 5 ) - 1 ;
F_1 ( V_2 , V_41 , V_42 ) ;
F_1 ( V_2 , V_41 , V_43 |
V_44 ) ;
F_1 ( V_2 , V_45 , V_38 ) ;
F_1 ( V_2 , V_8 , 0 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_46 * V_47 ,
int V_48 )
{
unsigned long V_49 ;
T_1 V_50 , V_51 , V_4 ;
V_2 -> V_17 = V_47 -> V_16 ;
V_2 -> V_10 = V_2 -> V_31 = V_47 -> V_14 ;
V_2 -> V_28 = 0 ;
V_2 -> V_32 = ( V_47 -> V_52 & V_53 ) ;
F_16 ( & V_2 -> V_37 ) ;
F_1 ( V_2 , V_12 ,
V_54 ) ;
if ( V_2 -> V_32 )
F_7 ( V_2 ) ;
F_1 ( V_2 , V_55 ,
( V_47 -> V_56 << V_57 ) |
( V_2 -> V_32 ? V_58 : 0 ) ) ;
V_4 = F_3 ( V_2 , V_41 ) ;
if ( ! V_2 -> V_32 )
V_4 &= ~ V_59 ;
else
V_4 |= V_59 ;
if ( V_47 -> V_52 & V_60 )
V_4 |= V_61 ;
else
V_4 &= ~ V_61 ;
V_4 = ( V_4 & ~ V_62 ) |
( V_47 -> V_14 << V_63 ) ;
F_1 ( V_2 , V_41 , V_4 ) ;
if ( ! V_2 -> V_32 )
F_9 ( V_2 ) ;
V_50 = ( V_64 | V_65 |
V_66 | V_34 ) ;
if ( V_2 -> V_32 ) {
V_50 |= V_35 ;
if ( V_47 -> V_14 == 0 )
V_50 |= V_30 ;
} else {
if ( V_47 -> V_14 == 0 )
V_50 |= V_30 ;
else
V_50 |= V_33 ;
}
F_6 ( V_2 , V_50 ) ;
V_51 = V_67 ;
V_51 |= ( V_2 -> V_32 ? V_68 : V_69 ) ;
if ( V_48 )
V_51 |= V_70 ;
F_1 ( V_2 , V_71 , V_51 ) ;
V_49 = F_17 ( V_72 ) ;
V_49 = F_18 ( & V_2 -> V_37 , V_49 ) ;
if ( V_2 -> V_28 ) {
F_19 ( V_2 -> V_73 , L_1 , V_2 -> V_28 ) ;
if ( V_2 -> V_28 & V_65 )
F_13 ( V_2 ) ;
return - V_74 ;
}
if ( V_49 == 0 ) {
F_19 ( V_2 -> V_73 , L_2 ) ;
F_13 ( V_2 ) ;
return - V_75 ;
}
return 0 ;
}
static int F_20 ( struct V_76 * V_77 , struct V_46 * V_78 ,
int V_79 )
{
int V_15 , V_80 ;
struct V_1 * V_2 = F_21 ( V_77 ) ;
for ( V_15 = 0 ; V_15 < V_79 ; V_15 ++ ) {
V_80 = F_15 ( V_2 , & V_78 [ V_15 ] , V_15 == V_79 - 1 ) ;
if ( V_80 != 0 )
return V_80 ;
}
return V_79 ;
}
static T_1 F_22 ( struct V_76 * V_81 )
{
return V_82 | V_83 |
V_84 ;
}
static int F_23 ( struct V_85 * V_86 ,
struct V_1 * V_2 )
{
T_1 V_87 ;
int V_88 ;
V_88 = F_24 ( & V_86 -> V_73 , L_3 , & V_87 ) ;
if ( V_88 ) {
V_87 = V_89 ;
F_19 ( & V_86 -> V_73 , L_4 , V_87 ) ;
} else if ( V_87 == 0 || V_87 > V_90 ) {
F_25 ( & V_86 -> V_73 , L_5 ,
V_87 ) ;
V_87 = V_89 ;
}
V_2 -> V_40 = V_87 ;
return 0 ;
}
static int F_26 ( struct V_85 * V_86 )
{
struct V_1 * V_2 ;
struct V_91 * V_92 ;
int V_88 = 0 ;
V_2 = F_27 ( & V_86 -> V_73 , sizeof( * V_2 ) , V_93 ) ;
if ( ! V_2 )
return - V_94 ;
V_92 = F_28 ( V_86 , V_95 , 0 ) ;
V_2 -> V_5 = F_29 ( & V_86 -> V_73 , V_92 ) ;
if ( F_30 ( V_2 -> V_5 ) )
return F_31 ( V_2 -> V_5 ) ;
V_2 -> V_22 = F_32 ( V_86 , 0 ) ;
if ( V_2 -> V_22 <= 0 ) {
F_33 ( & V_86 -> V_73 , L_6 ) ;
return V_2 -> V_22 ;
}
F_23 ( V_86 , V_2 ) ;
F_13 ( V_2 ) ;
V_88 = F_34 ( & V_86 -> V_73 , V_2 -> V_22 , F_11 , 0 ,
V_86 -> V_96 , V_2 ) ;
if ( V_88 ) {
F_33 ( & V_86 -> V_73 , L_7 ) ;
return V_88 ;
}
F_35 ( & V_2 -> V_37 ) ;
V_2 -> V_81 . V_73 . V_97 = & V_86 -> V_73 ;
V_2 -> V_81 . V_98 = & V_99 ;
V_2 -> V_81 . V_73 . V_100 = V_86 -> V_73 . V_100 ;
V_2 -> V_73 = & V_86 -> V_73 ;
snprintf ( V_2 -> V_81 . V_96 , sizeof( V_2 -> V_81 . V_96 ) , L_8 ) ;
F_36 ( & V_2 -> V_81 , V_2 ) ;
V_88 = F_37 ( & V_2 -> V_81 ) ;
if ( V_88 ) {
F_33 ( & V_86 -> V_73 , L_9 ) ;
return V_88 ;
}
F_38 ( V_86 , V_2 ) ;
F_19 ( & V_86 -> V_73 , L_10 , V_2 -> V_81 . V_101 ) ;
return 0 ;
}
static int F_39 ( struct V_85 * V_86 )
{
struct V_1 * V_2 ;
V_2 = F_40 ( V_86 ) ;
F_1 ( V_2 , V_8 , 0 ) ;
F_41 ( V_2 -> V_22 ) ;
F_42 ( & V_2 -> V_81 ) ;
F_1 ( V_2 , V_41 , 0 ) ;
return 0 ;
}
