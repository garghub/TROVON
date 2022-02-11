static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
enum V_6 V_7 )
{
struct V_8 * V_9 = F_4 ( V_5 ) ;
V_9 -> V_7 = V_7 ;
return 0 ;
}
static int F_5 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
struct V_8 * V_9 ;
struct V_11 * V_12 = V_10 -> V_12 ;
void T_1 * V_13 = V_12 -> V_13 ;
unsigned V_14 = V_5 -> V_15 / 2 ;
unsigned V_16 = V_5 -> V_15 % 2 ;
unsigned V_17 ;
int V_18 ;
V_9 = F_6 ( V_3 -> V_19 , sizeof( * V_9 ) , V_20 ) ;
if ( ! V_9 )
return - V_21 ;
V_18 = F_7 ( V_12 -> V_22 [ V_14 ] ) ;
if ( V_18 ) {
F_8 ( V_3 -> V_19 , V_9 ) ;
return V_18 ;
}
F_9 ( V_5 , V_9 ) ;
V_9 -> V_7 = V_23 ;
V_9 -> V_24 = 0 ;
V_9 -> V_25 = 0 ;
V_9 -> div = 0 ;
F_10 ( & V_10 -> V_26 ) ;
V_17 = F_11 ( V_13 + F_12 ( V_14 , V_27 ) ) ;
if ( V_17 & V_28 ) {
if ( V_16 == 0 )
V_9 -> V_24 =
F_11 ( V_13 + F_12 ( V_14 , V_29 ) ) ;
else
V_9 -> V_24 =
F_11 ( V_13 + F_12 ( V_14 , V_30 ) ) ;
V_9 -> div = V_17 & V_31 ;
V_9 -> V_25 = F_11 ( V_13 + F_12 ( V_14 , V_32 ) ) ;
V_17 &= ( V_31 | V_33 |
V_34 ) ;
} else
V_17 = 0 ;
V_17 |= V_28 | V_35 | V_36 ;
F_13 ( V_17 , V_13 + F_12 ( V_14 , V_27 ) ) ;
F_14 ( & V_10 -> V_26 ) ;
V_10 -> V_37 [ V_5 -> V_15 ] = V_9 ;
return 0 ;
}
static void F_15 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
struct V_8 * V_9 = F_4 ( V_5 ) ;
struct V_11 * V_12 = V_10 -> V_12 ;
F_16 ( V_12 -> V_22 [ V_5 -> V_15 / 2 ] ) ;
V_10 -> V_37 [ V_5 -> V_15 ] = NULL ;
F_8 ( V_3 -> V_19 , V_9 ) ;
}
static void F_17 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
struct V_8 * V_9 = F_4 ( V_5 ) ;
struct V_11 * V_12 = V_10 -> V_12 ;
void T_1 * V_13 = V_12 -> V_13 ;
unsigned V_14 = V_5 -> V_15 / 2 ;
unsigned V_16 = V_5 -> V_15 % 2 ;
unsigned V_17 ;
enum V_6 V_7 = V_9 -> V_7 ;
if ( V_9 -> V_24 == 0 )
V_7 = ! V_7 ;
F_10 ( & V_10 -> V_26 ) ;
V_17 = F_11 ( V_13 + F_12 ( V_14 , V_27 ) ) ;
if ( V_16 == 0 ) {
V_17 &= ~ V_33 ;
if ( V_7 == V_38 )
V_17 |= V_39 ;
else
V_17 |= V_40 ;
} else {
V_17 &= ~ V_34 ;
if ( V_7 == V_38 )
V_17 |= V_41 ;
else
V_17 |= V_42 ;
}
F_13 ( V_17 , V_13 + F_12 ( V_14 , V_27 ) ) ;
if ( ! ( V_17 & ( V_43 | V_44 ) ) )
F_13 ( V_45 | V_46 ,
V_13 + F_12 ( V_14 , V_47 ) ) ;
else
F_13 ( V_45 , V_13 +
F_12 ( V_14 , V_47 ) ) ;
F_14 ( & V_10 -> V_26 ) ;
}
static int F_18 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
struct V_8 * V_9 = F_4 ( V_5 ) ;
struct V_11 * V_12 = V_10 -> V_12 ;
void T_1 * V_13 = V_12 -> V_13 ;
unsigned V_14 = V_5 -> V_15 / 2 ;
unsigned V_16 = V_5 -> V_15 % 2 ;
T_2 V_17 ;
enum V_6 V_7 = V_9 -> V_7 ;
if ( V_9 -> V_24 == 0 )
V_7 = ! V_7 ;
F_10 ( & V_10 -> V_26 ) ;
V_17 = F_11 ( V_13 + F_12 ( V_14 , V_27 ) ) ;
V_17 &= ~ V_31 ;
if ( V_16 == 0 ) {
V_17 &= ~ V_33 ;
if ( V_7 == V_38 )
V_17 |= V_39 ;
else
V_17 |= V_40 ;
} else {
V_17 &= ~ V_34 ;
if ( V_7 == V_38 )
V_17 |= V_41 ;
else
V_17 |= V_42 ;
}
if ( V_9 -> V_24 != V_9 -> V_25 && V_9 -> V_24 > 0 ) {
if ( V_16 == 0 ) {
if ( V_7 == V_38 )
V_17 |= V_48 | V_49 ;
else
V_17 |= V_50 | V_51 ;
} else {
if ( V_7 == V_38 )
V_17 |= V_52 | V_53 ;
else
V_17 |= V_54 | V_55 ;
}
}
V_17 |= ( V_9 -> div & V_31 ) ;
F_13 ( V_17 , V_13 + F_12 ( V_14 , V_27 ) ) ;
if ( V_16 == 0 )
F_13 ( V_9 -> V_24 , V_13 + F_12 ( V_14 , V_29 ) ) ;
else
F_13 ( V_9 -> V_24 , V_13 + F_12 ( V_14 , V_30 ) ) ;
F_13 ( V_9 -> V_25 , V_13 + F_12 ( V_14 , V_32 ) ) ;
F_13 ( V_56 | V_45 ,
V_13 + F_12 ( V_14 , V_47 ) ) ;
F_14 ( & V_10 -> V_26 ) ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 , struct V_4 * V_5 ,
int V_57 , int V_58 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
struct V_8 * V_9 = F_4 ( V_5 ) ;
unsigned V_14 = V_5 -> V_15 / 2 ;
unsigned V_16 = V_5 -> V_15 % 2 ;
struct V_8 * V_59 = NULL ;
struct V_11 * V_12 = V_10 -> V_12 ;
int V_60 ;
int V_61 = 0 ;
unsigned V_25 ;
unsigned V_24 ;
unsigned V_62 = F_20 ( V_12 -> V_22 [ V_14 ] ) ;
unsigned long long V_63 ;
unsigned long long V_64 ;
for ( V_60 = 0 ; V_60 < 5 ; ++ V_60 ) {
if ( V_65 [ V_60 ] == 0 ) {
V_61 = V_60 ;
continue;
}
V_63 = F_21 ( ( V_66 ) V_67 * V_65 [ V_60 ] , V_62 ) ;
V_64 = V_63 << V_12 -> V_68 -> V_69 ;
if ( V_64 >= V_58 )
break;
}
if ( V_60 == 5 ) {
V_60 = V_61 ;
V_62 = 32768 ;
V_63 = F_21 ( V_67 , V_62 ) ;
V_64 = V_63 << V_12 -> V_68 -> V_69 ;
if ( V_64 < V_58 )
return - V_70 ;
}
V_24 = F_21 ( V_57 , V_63 ) ;
V_25 = F_21 ( V_58 , V_63 ) ;
if ( V_16 == 0 )
V_59 = V_10 -> V_37 [ V_5 -> V_15 + 1 ] ;
else
V_59 = V_10 -> V_37 [ V_5 -> V_15 - 1 ] ;
if ( ( V_59 && V_59 -> V_24 > 0 &&
V_59 -> V_24 != V_59 -> V_25 ) &&
( V_59 -> div != V_60 || V_59 -> V_25 != V_25 ) ) {
F_22 ( V_3 -> V_19 ,
L_1 ) ;
return - V_71 ;
}
V_9 -> V_25 = V_25 ;
V_9 -> div = V_60 ;
V_9 -> V_24 = V_24 ;
if ( F_23 ( V_72 , & V_5 -> V_73 ) )
F_18 ( V_3 , V_5 ) ;
return 0 ;
}
static int F_24 ( struct V_74 * V_75 )
{
struct V_1 * V_9 ;
struct V_76 * V_77 = V_75 -> V_19 . V_78 ;
struct V_11 * V_12 ;
int V_79 ;
int V_80 ;
V_79 = F_25 ( V_77 , L_2 , & V_80 ) ;
if ( V_79 < 0 ) {
F_22 ( & V_75 -> V_19 ,
L_3 ,
V_79 ) ;
return V_79 ;
}
V_12 = F_26 ( V_80 ) ;
if ( V_12 == NULL ) {
F_22 ( & V_75 -> V_19 , L_4 ) ;
return - V_21 ;
}
V_9 = F_6 ( & V_75 -> V_19 , sizeof( * V_9 ) , V_20 ) ;
if ( V_9 == NULL ) {
F_27 ( V_12 ) ;
F_22 ( & V_75 -> V_19 , L_5 ) ;
return - V_21 ;
}
V_9 -> V_3 . V_19 = & V_75 -> V_19 ;
V_9 -> V_3 . V_81 = & V_82 ;
V_9 -> V_3 . V_83 = V_84 ;
V_9 -> V_3 . V_85 = 3 ;
V_9 -> V_3 . V_86 = - 1 ;
V_9 -> V_3 . V_87 = V_88 ;
V_9 -> V_12 = V_12 ;
F_28 ( & V_9 -> V_26 ) ;
V_79 = F_29 ( & V_9 -> V_3 ) ;
if ( V_79 < 0 ) {
F_27 ( V_12 ) ;
return V_79 ;
}
F_30 ( V_75 , V_9 ) ;
return 0 ;
}
static int F_31 ( struct V_74 * V_75 )
{
struct V_1 * V_9 = F_32 ( V_75 ) ;
int V_79 ;
V_79 = F_33 ( & V_9 -> V_3 ) ;
if ( V_79 < 0 )
return V_79 ;
F_27 ( V_9 -> V_12 ) ;
return 0 ;
}
