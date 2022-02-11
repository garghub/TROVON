static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
unsigned long V_6 ;
unsigned char V_7 ;
if ( V_3 >= V_2 -> V_8 )
return - V_9 ;
F_3 ( & V_5 -> V_10 , V_6 ) ;
V_7 = F_4 ( V_5 -> V_11 + V_12 ) ;
V_7 &= ~ ( F_5 ( V_3 ) ) ;
F_6 ( V_7 , V_5 -> V_11 + V_12 ) ;
F_7 ( & V_5 -> V_10 , V_6 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 ,
int V_13 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
unsigned long V_6 ;
unsigned char V_7 ;
if ( V_3 >= V_2 -> V_8 )
return - V_9 ;
F_3 ( & V_5 -> V_10 , V_6 ) ;
F_6 ( ! ! V_13 << V_3 , V_5 -> V_11 + ( F_5 ( V_3 + 2 ) ) ) ;
V_7 = F_4 ( V_5 -> V_11 + V_12 ) ;
V_7 |= F_5 ( V_3 ) ;
F_6 ( V_7 , V_5 -> V_11 + V_12 ) ;
F_6 ( ! ! V_13 << V_3 , V_5 -> V_11 + ( F_5 ( V_3 + 2 ) ) ) ;
F_7 ( & V_5 -> V_10 , V_6 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
return ! ! F_4 ( V_5 -> V_11 + ( F_5 ( V_3 + 2 ) ) ) ;
}
static void F_10 ( struct V_1 * V_2 , unsigned V_3 , int V_13 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
F_6 ( ! ! V_13 << V_3 , V_5 -> V_11 + ( F_5 ( V_3 + 2 ) ) ) ;
}
static int F_11 ( struct V_14 * V_15 , unsigned V_16 )
{
struct V_1 * V_2 = F_12 ( V_15 ) ;
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
int V_3 = F_13 ( V_15 ) ;
unsigned long V_6 ;
T_1 V_17 , V_18 , V_19 ;
T_1 V_20 = F_5 ( V_3 ) ;
if ( V_3 < 0 || V_3 >= V_21 )
return - V_9 ;
if ( ( V_16 & ( V_22 | V_23 ) ) &&
( V_16 & ( V_24 | V_25 ) ) )
{
F_14 ( V_2 -> V_26 ,
L_1
L_2 ,
V_3 ) ;
return - V_9 ;
}
F_3 ( & V_5 -> V_10 , V_6 ) ;
V_19 = F_4 ( V_5 -> V_11 + V_27 ) ;
V_17 = F_4 ( V_5 -> V_11 + V_28 ) ;
V_18 = F_4 ( V_5 -> V_11 + V_29 ) ;
if ( V_16 & ( V_22 | V_23 ) ) {
bool V_30 = V_16 & V_22 ;
V_18 &= ~ V_20 ;
V_17 |= V_20 ;
if ( V_30 )
V_19 |= V_20 ;
else
V_19 &= ~ V_20 ;
F_15 ( V_15 , V_31 ) ;
F_16 ( V_2 -> V_26 , L_3 ,
V_3 ,
V_30 ? L_4 : L_5 ) ;
} else if ( ( V_16 & V_32 ) == V_32 ) {
V_17 &= ~ V_20 ;
V_18 |= V_20 ;
F_15 ( V_15 , V_33 ) ;
F_16 ( V_2 -> V_26 , L_6 , V_3 ) ;
} else if ( ( V_16 & V_24 ) ||
( V_16 & V_25 ) ) {
bool V_34 = V_16 & V_24 ;
V_17 &= ~ V_20 ;
V_18 &= ~ V_20 ;
if ( V_34 )
V_19 |= V_20 ;
else
V_19 &= ~ V_20 ;
F_15 ( V_15 , V_33 ) ;
F_16 ( V_2 -> V_26 , L_7 ,
V_3 ,
V_34 ? L_8 : L_9 ) ;
} else {
V_17 &= ~ V_20 ;
V_18 &= ~ V_20 ;
V_19 &= ~ V_20 ;
F_15 ( V_15 , V_35 ) ;
F_17 ( V_2 -> V_26 , L_10 ,
V_3 ) ;
}
F_6 ( V_17 , V_5 -> V_11 + V_28 ) ;
F_6 ( V_18 , V_5 -> V_11 + V_29 ) ;
F_6 ( V_19 , V_5 -> V_11 + V_27 ) ;
F_7 ( & V_5 -> V_10 , V_6 ) ;
return 0 ;
}
static void F_18 ( struct V_36 * V_37 )
{
unsigned long V_38 ;
int V_3 ;
struct V_1 * V_2 = F_19 ( V_37 ) ;
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
struct V_39 * V_40 = F_20 ( V_37 ) ;
F_21 ( V_40 , V_37 ) ;
V_38 = F_4 ( V_5 -> V_11 + V_41 ) ;
if ( V_38 ) {
F_22 (offset, &pending, PL061_GPIO_NR)
F_23 ( F_24 ( V_2 -> V_42 ,
V_3 ) ) ;
}
F_25 ( V_40 , V_37 ) ;
}
static void F_26 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_12 ( V_15 ) ;
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
T_1 V_43 = F_5 ( F_13 ( V_15 ) % V_21 ) ;
T_1 V_44 ;
F_27 ( & V_5 -> V_10 ) ;
V_44 = F_4 ( V_5 -> V_11 + V_45 ) & ~ V_43 ;
F_6 ( V_44 , V_5 -> V_11 + V_45 ) ;
F_28 ( & V_5 -> V_10 ) ;
}
static void F_29 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_12 ( V_15 ) ;
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
T_1 V_43 = F_5 ( F_13 ( V_15 ) % V_21 ) ;
T_1 V_44 ;
F_27 ( & V_5 -> V_10 ) ;
V_44 = F_4 ( V_5 -> V_11 + V_45 ) | V_43 ;
F_6 ( V_44 , V_5 -> V_11 + V_45 ) ;
F_28 ( & V_5 -> V_10 ) ;
}
static void F_30 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_12 ( V_15 ) ;
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
T_1 V_43 = F_5 ( F_13 ( V_15 ) % V_21 ) ;
F_27 ( & V_5 -> V_10 ) ;
F_6 ( V_43 , V_5 -> V_11 + V_46 ) ;
F_28 ( & V_5 -> V_10 ) ;
}
static int F_31 ( struct V_47 * V_48 , const struct V_49 * V_50 )
{
struct V_51 * V_26 = & V_48 -> V_26 ;
struct V_52 * V_53 = F_32 ( V_26 ) ;
struct V_4 * V_5 ;
int V_54 , V_55 , V_56 , V_57 ;
V_5 = F_33 ( V_26 , sizeof( * V_5 ) , V_58 ) ;
if ( V_5 == NULL )
return - V_59 ;
if ( V_53 ) {
V_5 -> V_2 . V_11 = V_53 -> V_60 ;
V_57 = V_53 -> V_57 ;
if ( V_57 <= 0 ) {
F_14 ( & V_48 -> V_26 , L_11 ) ;
return - V_61 ;
}
} else {
V_5 -> V_2 . V_11 = - 1 ;
V_57 = 0 ;
}
V_5 -> V_11 = F_34 ( V_26 , & V_48 -> V_62 ) ;
if ( F_35 ( V_5 -> V_11 ) )
return F_36 ( V_5 -> V_11 ) ;
F_37 ( & V_5 -> V_10 ) ;
if ( F_38 ( V_26 -> V_63 , L_12 ) ) {
V_5 -> V_2 . V_64 = V_65 ;
V_5 -> V_2 . free = V_66 ;
}
V_5 -> V_2 . V_67 = F_1 ;
V_5 -> V_2 . V_68 = F_8 ;
V_5 -> V_2 . V_69 = F_9 ;
V_5 -> V_2 . V_70 = F_10 ;
V_5 -> V_2 . V_8 = V_21 ;
V_5 -> V_2 . V_71 = F_39 ( V_26 ) ;
V_5 -> V_2 . V_26 = V_26 ;
V_5 -> V_2 . V_72 = V_73 ;
V_54 = F_40 ( & V_5 -> V_2 ) ;
if ( V_54 )
return V_54 ;
F_6 ( 0 , V_5 -> V_11 + V_45 ) ;
V_55 = V_48 -> V_55 [ 0 ] ;
if ( V_55 < 0 ) {
F_14 ( & V_48 -> V_26 , L_13 ) ;
return - V_61 ;
}
V_54 = F_41 ( & V_5 -> V_2 , & V_74 ,
V_57 , V_35 ,
V_75 ) ;
if ( V_54 ) {
F_42 ( & V_48 -> V_26 , L_14 ) ;
return V_54 ;
}
F_43 ( & V_5 -> V_2 , & V_74 ,
V_55 , F_18 ) ;
for ( V_56 = 0 ; V_56 < V_21 ; V_56 ++ ) {
if ( V_53 ) {
if ( V_53 -> V_76 & ( F_5 ( V_56 ) ) )
F_8 ( & V_5 -> V_2 , V_56 ,
V_53 -> V_77 & ( F_5 ( V_56 ) ) ) ;
else
F_1 ( & V_5 -> V_2 , V_56 ) ;
}
}
F_44 ( V_48 , V_5 ) ;
F_42 ( & V_48 -> V_26 , L_15 ,
& V_48 -> V_62 . V_78 ) ;
return 0 ;
}
static int F_45 ( struct V_51 * V_26 )
{
struct V_4 * V_5 = F_46 ( V_26 ) ;
int V_3 ;
V_5 -> V_79 . V_80 = 0 ;
V_5 -> V_79 . V_81 = F_4 ( V_5 -> V_11 + V_12 ) ;
V_5 -> V_79 . V_82 = F_4 ( V_5 -> V_11 + V_28 ) ;
V_5 -> V_79 . V_83 = F_4 ( V_5 -> V_11 + V_29 ) ;
V_5 -> V_79 . V_84 = F_4 ( V_5 -> V_11 + V_27 ) ;
V_5 -> V_79 . V_85 = F_4 ( V_5 -> V_11 + V_45 ) ;
for ( V_3 = 0 ; V_3 < V_21 ; V_3 ++ ) {
if ( V_5 -> V_79 . V_81 & ( F_5 ( V_3 ) ) )
V_5 -> V_79 . V_80 |=
F_9 ( & V_5 -> V_2 , V_3 ) << V_3 ;
}
return 0 ;
}
static int F_47 ( struct V_51 * V_26 )
{
struct V_4 * V_5 = F_46 ( V_26 ) ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_21 ; V_3 ++ ) {
if ( V_5 -> V_79 . V_81 & ( F_5 ( V_3 ) ) )
F_8 ( & V_5 -> V_2 , V_3 ,
V_5 -> V_79 . V_80 &
( F_5 ( V_3 ) ) ) ;
else
F_1 ( & V_5 -> V_2 , V_3 ) ;
}
F_6 ( V_5 -> V_79 . V_82 , V_5 -> V_11 + V_28 ) ;
F_6 ( V_5 -> V_79 . V_83 , V_5 -> V_11 + V_29 ) ;
F_6 ( V_5 -> V_79 . V_84 , V_5 -> V_11 + V_27 ) ;
F_6 ( V_5 -> V_79 . V_85 , V_5 -> V_11 + V_45 ) ;
return 0 ;
}
static int T_2 F_48 ( void )
{
return F_49 ( & V_86 ) ;
}
