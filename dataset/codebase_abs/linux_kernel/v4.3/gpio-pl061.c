static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
int V_6 = V_2 -> V_7 + V_3 ;
if ( V_5 -> V_8 )
return F_3 ( V_6 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
int V_6 = V_2 -> V_7 + V_3 ;
if ( V_5 -> V_8 )
F_5 ( V_6 ) ;
}
static int F_6 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
unsigned long V_9 ;
unsigned char V_10 ;
if ( V_3 >= V_2 -> V_11 )
return - V_12 ;
F_7 ( & V_5 -> V_13 , V_9 ) ;
V_10 = F_8 ( V_5 -> V_7 + V_14 ) ;
V_10 &= ~ ( F_9 ( V_3 ) ) ;
F_10 ( V_10 , V_5 -> V_7 + V_14 ) ;
F_11 ( & V_5 -> V_13 , V_9 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned V_3 ,
int V_15 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
unsigned long V_9 ;
unsigned char V_10 ;
if ( V_3 >= V_2 -> V_11 )
return - V_12 ;
F_7 ( & V_5 -> V_13 , V_9 ) ;
F_10 ( ! ! V_15 << V_3 , V_5 -> V_7 + ( F_9 ( V_3 + 2 ) ) ) ;
V_10 = F_8 ( V_5 -> V_7 + V_14 ) ;
V_10 |= F_9 ( V_3 ) ;
F_10 ( V_10 , V_5 -> V_7 + V_14 ) ;
F_10 ( ! ! V_15 << V_3 , V_5 -> V_7 + ( F_9 ( V_3 + 2 ) ) ) ;
F_11 ( & V_5 -> V_13 , V_9 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
return ! ! F_8 ( V_5 -> V_7 + ( F_9 ( V_3 + 2 ) ) ) ;
}
static void F_14 ( struct V_1 * V_2 , unsigned V_3 , int V_15 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
F_10 ( ! ! V_15 << V_3 , V_5 -> V_7 + ( F_9 ( V_3 + 2 ) ) ) ;
}
static int F_15 ( struct V_16 * V_17 , unsigned V_18 )
{
struct V_1 * V_2 = F_16 ( V_17 ) ;
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
int V_3 = F_17 ( V_17 ) ;
unsigned long V_9 ;
T_1 V_19 , V_20 , V_21 ;
T_1 V_22 = F_9 ( V_3 ) ;
if ( V_3 < 0 || V_3 >= V_23 )
return - V_12 ;
F_7 ( & V_5 -> V_13 , V_9 ) ;
V_21 = F_8 ( V_5 -> V_7 + V_24 ) ;
V_19 = F_8 ( V_5 -> V_7 + V_25 ) ;
V_20 = F_8 ( V_5 -> V_7 + V_26 ) ;
if ( V_18 & ( V_27 | V_28 ) ) {
V_19 |= V_22 ;
if ( V_18 & V_27 )
V_21 |= V_22 ;
else
V_21 &= ~ V_22 ;
} else
V_19 &= ~ V_22 ;
if ( ( V_18 & V_29 ) == V_29 )
V_20 |= V_22 ;
else {
V_20 &= ~ V_22 ;
if ( V_18 & V_30 )
V_21 |= V_22 ;
else if ( V_18 & V_31 )
V_21 &= ~ V_22 ;
}
F_10 ( V_19 , V_5 -> V_7 + V_25 ) ;
F_10 ( V_20 , V_5 -> V_7 + V_26 ) ;
F_10 ( V_21 , V_5 -> V_7 + V_24 ) ;
F_11 ( & V_5 -> V_13 , V_9 ) ;
return 0 ;
}
static void F_18 ( struct V_32 * V_33 )
{
unsigned long V_34 ;
int V_3 ;
struct V_1 * V_2 = F_19 ( V_33 ) ;
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
struct V_35 * V_36 = F_20 ( V_33 ) ;
F_21 ( V_36 , V_33 ) ;
V_34 = F_8 ( V_5 -> V_7 + V_37 ) ;
F_10 ( V_34 , V_5 -> V_7 + V_38 ) ;
if ( V_34 ) {
F_22 (offset, &pending, PL061_GPIO_NR)
F_23 ( F_24 ( V_2 -> V_39 ,
V_3 ) ) ;
}
F_25 ( V_36 , V_33 ) ;
}
static void F_26 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_16 ( V_17 ) ;
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
T_1 V_40 = F_9 ( F_17 ( V_17 ) % V_23 ) ;
T_1 V_41 ;
F_27 ( & V_5 -> V_13 ) ;
V_41 = F_8 ( V_5 -> V_7 + V_42 ) & ~ V_40 ;
F_10 ( V_41 , V_5 -> V_7 + V_42 ) ;
F_28 ( & V_5 -> V_13 ) ;
}
static void F_29 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_16 ( V_17 ) ;
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
T_1 V_40 = F_9 ( F_17 ( V_17 ) % V_23 ) ;
T_1 V_41 ;
F_27 ( & V_5 -> V_13 ) ;
V_41 = F_8 ( V_5 -> V_7 + V_42 ) | V_40 ;
F_10 ( V_41 , V_5 -> V_7 + V_42 ) ;
F_28 ( & V_5 -> V_13 ) ;
}
static int F_30 ( struct V_43 * V_44 , const struct V_45 * V_46 )
{
struct V_47 * V_48 = & V_44 -> V_48 ;
struct V_49 * V_50 = F_31 ( V_48 ) ;
struct V_4 * V_5 ;
int V_51 , V_52 , V_53 , V_54 ;
V_5 = F_32 ( V_48 , sizeof( * V_5 ) , V_55 ) ;
if ( V_5 == NULL )
return - V_56 ;
if ( V_50 ) {
V_5 -> V_2 . V_7 = V_50 -> V_57 ;
V_54 = V_50 -> V_54 ;
if ( V_54 <= 0 ) {
F_33 ( & V_44 -> V_48 , L_1 ) ;
return - V_58 ;
}
} else {
V_5 -> V_2 . V_7 = - 1 ;
V_54 = 0 ;
}
V_5 -> V_7 = F_34 ( V_48 , & V_44 -> V_59 ) ;
if ( F_35 ( V_5 -> V_7 ) )
return F_36 ( V_5 -> V_7 ) ;
F_37 ( & V_5 -> V_13 ) ;
if ( F_38 ( V_48 -> V_60 , L_2 ) )
V_5 -> V_8 = true ;
V_5 -> V_2 . V_61 = F_1 ;
V_5 -> V_2 . free = F_4 ;
V_5 -> V_2 . V_62 = F_6 ;
V_5 -> V_2 . V_63 = F_12 ;
V_5 -> V_2 . V_64 = F_13 ;
V_5 -> V_2 . V_65 = F_14 ;
V_5 -> V_2 . V_11 = V_23 ;
V_5 -> V_2 . V_66 = F_39 ( V_48 ) ;
V_5 -> V_2 . V_48 = V_48 ;
V_5 -> V_2 . V_67 = V_68 ;
V_51 = F_40 ( & V_5 -> V_2 ) ;
if ( V_51 )
return V_51 ;
F_10 ( 0 , V_5 -> V_7 + V_42 ) ;
V_52 = V_44 -> V_52 [ 0 ] ;
if ( V_52 < 0 ) {
F_33 ( & V_44 -> V_48 , L_3 ) ;
return - V_58 ;
}
V_51 = F_41 ( & V_5 -> V_2 , & V_69 ,
V_54 , V_70 ,
V_71 ) ;
if ( V_51 ) {
F_42 ( & V_44 -> V_48 , L_4 ) ;
return V_51 ;
}
F_43 ( & V_5 -> V_2 , & V_69 ,
V_52 , F_18 ) ;
for ( V_53 = 0 ; V_53 < V_23 ; V_53 ++ ) {
if ( V_50 ) {
if ( V_50 -> V_72 & ( F_9 ( V_53 ) ) )
F_12 ( & V_5 -> V_2 , V_53 ,
V_50 -> V_73 & ( F_9 ( V_53 ) ) ) ;
else
F_6 ( & V_5 -> V_2 , V_53 ) ;
}
}
F_44 ( V_44 , V_5 ) ;
F_42 ( & V_44 -> V_48 , L_5 ,
& V_44 -> V_59 . V_74 ) ;
return 0 ;
}
static int F_45 ( struct V_47 * V_48 )
{
struct V_4 * V_5 = F_46 ( V_48 ) ;
int V_3 ;
V_5 -> V_75 . V_76 = 0 ;
V_5 -> V_75 . V_77 = F_8 ( V_5 -> V_7 + V_14 ) ;
V_5 -> V_75 . V_78 = F_8 ( V_5 -> V_7 + V_25 ) ;
V_5 -> V_75 . V_79 = F_8 ( V_5 -> V_7 + V_26 ) ;
V_5 -> V_75 . V_80 = F_8 ( V_5 -> V_7 + V_24 ) ;
V_5 -> V_75 . V_81 = F_8 ( V_5 -> V_7 + V_42 ) ;
for ( V_3 = 0 ; V_3 < V_23 ; V_3 ++ ) {
if ( V_5 -> V_75 . V_77 & ( F_9 ( V_3 ) ) )
V_5 -> V_75 . V_76 |=
F_13 ( & V_5 -> V_2 , V_3 ) << V_3 ;
}
return 0 ;
}
static int F_47 ( struct V_47 * V_48 )
{
struct V_4 * V_5 = F_46 ( V_48 ) ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_23 ; V_3 ++ ) {
if ( V_5 -> V_75 . V_77 & ( F_9 ( V_3 ) ) )
F_12 ( & V_5 -> V_2 , V_3 ,
V_5 -> V_75 . V_76 &
( F_9 ( V_3 ) ) ) ;
else
F_6 ( & V_5 -> V_2 , V_3 ) ;
}
F_10 ( V_5 -> V_75 . V_78 , V_5 -> V_7 + V_25 ) ;
F_10 ( V_5 -> V_75 . V_79 , V_5 -> V_7 + V_26 ) ;
F_10 ( V_5 -> V_75 . V_80 , V_5 -> V_7 + V_24 ) ;
F_10 ( V_5 -> V_75 . V_81 , V_5 -> V_7 + V_42 ) ;
return 0 ;
}
static int T_2 F_48 ( void )
{
return F_49 ( & V_82 ) ;
}
