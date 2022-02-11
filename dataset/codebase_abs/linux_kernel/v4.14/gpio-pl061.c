static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
return ! ( F_3 ( V_4 -> V_5 + V_6 ) & F_4 ( V_3 ) ) ;
}
static int F_5 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
unsigned long V_7 ;
unsigned char V_8 ;
F_6 ( & V_4 -> V_9 , V_7 ) ;
V_8 = F_3 ( V_4 -> V_5 + V_6 ) ;
V_8 &= ~ ( F_4 ( V_3 ) ) ;
F_7 ( V_8 , V_4 -> V_5 + V_6 ) ;
F_8 ( & V_4 -> V_9 , V_7 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned V_3 ,
int V_10 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
unsigned long V_7 ;
unsigned char V_8 ;
F_6 ( & V_4 -> V_9 , V_7 ) ;
F_7 ( ! ! V_10 << V_3 , V_4 -> V_5 + ( F_4 ( V_3 + 2 ) ) ) ;
V_8 = F_3 ( V_4 -> V_5 + V_6 ) ;
V_8 |= F_4 ( V_3 ) ;
F_7 ( V_8 , V_4 -> V_5 + V_6 ) ;
F_7 ( ! ! V_10 << V_3 , V_4 -> V_5 + ( F_4 ( V_3 + 2 ) ) ) ;
F_8 ( & V_4 -> V_9 , V_7 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
return ! ! F_3 ( V_4 -> V_5 + ( F_4 ( V_3 + 2 ) ) ) ;
}
static void F_11 ( struct V_1 * V_2 , unsigned V_3 , int V_10 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
F_7 ( ! ! V_10 << V_3 , V_4 -> V_5 + ( F_4 ( V_3 + 2 ) ) ) ;
}
static int F_12 ( struct V_11 * V_12 , unsigned V_13 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
struct V_4 * V_4 = F_2 ( V_2 ) ;
int V_3 = F_14 ( V_12 ) ;
unsigned long V_7 ;
T_1 V_14 , V_15 , V_16 ;
T_1 V_17 = F_4 ( V_3 ) ;
if ( V_3 < 0 || V_3 >= V_18 )
return - V_19 ;
if ( ( V_13 & ( V_20 | V_21 ) ) &&
( V_13 & ( V_22 | V_23 ) ) )
{
F_15 ( V_2 -> V_24 ,
L_1
L_2 ,
V_3 ) ;
return - V_19 ;
}
F_6 ( & V_4 -> V_9 , V_7 ) ;
V_16 = F_3 ( V_4 -> V_5 + V_25 ) ;
V_14 = F_3 ( V_4 -> V_5 + V_26 ) ;
V_15 = F_3 ( V_4 -> V_5 + V_27 ) ;
if ( V_13 & ( V_20 | V_21 ) ) {
bool V_28 = V_13 & V_20 ;
V_15 &= ~ V_17 ;
V_14 |= V_17 ;
if ( V_28 )
V_16 |= V_17 ;
else
V_16 &= ~ V_17 ;
F_16 ( V_12 , V_29 ) ;
F_17 ( V_2 -> V_24 , L_3 ,
V_3 ,
V_28 ? L_4 : L_5 ) ;
} else if ( ( V_13 & V_30 ) == V_30 ) {
V_14 &= ~ V_17 ;
V_15 |= V_17 ;
F_16 ( V_12 , V_31 ) ;
F_17 ( V_2 -> V_24 , L_6 , V_3 ) ;
} else if ( ( V_13 & V_22 ) ||
( V_13 & V_23 ) ) {
bool V_32 = V_13 & V_22 ;
V_14 &= ~ V_17 ;
V_15 &= ~ V_17 ;
if ( V_32 )
V_16 |= V_17 ;
else
V_16 &= ~ V_17 ;
F_16 ( V_12 , V_31 ) ;
F_17 ( V_2 -> V_24 , L_7 ,
V_3 ,
V_32 ? L_8 : L_9 ) ;
} else {
V_14 &= ~ V_17 ;
V_15 &= ~ V_17 ;
V_16 &= ~ V_17 ;
F_16 ( V_12 , V_33 ) ;
F_18 ( V_2 -> V_24 , L_10 ,
V_3 ) ;
}
F_7 ( V_14 , V_4 -> V_5 + V_26 ) ;
F_7 ( V_15 , V_4 -> V_5 + V_27 ) ;
F_7 ( V_16 , V_4 -> V_5 + V_25 ) ;
F_8 ( & V_4 -> V_9 , V_7 ) ;
return 0 ;
}
static void F_19 ( struct V_34 * V_35 )
{
unsigned long V_36 ;
int V_3 ;
struct V_1 * V_2 = F_20 ( V_35 ) ;
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_37 * V_38 = F_21 ( V_35 ) ;
F_22 ( V_38 , V_35 ) ;
V_36 = F_3 ( V_4 -> V_5 + V_39 ) ;
if ( V_36 ) {
F_23 (offset, &pending, PL061_GPIO_NR)
F_24 ( F_25 ( V_2 -> V_40 ,
V_3 ) ) ;
}
F_26 ( V_38 , V_35 ) ;
}
static void F_27 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
struct V_4 * V_4 = F_2 ( V_2 ) ;
T_1 V_41 = F_4 ( F_14 ( V_12 ) % V_18 ) ;
T_1 V_42 ;
F_28 ( & V_4 -> V_9 ) ;
V_42 = F_3 ( V_4 -> V_5 + V_43 ) & ~ V_41 ;
F_7 ( V_42 , V_4 -> V_5 + V_43 ) ;
F_29 ( & V_4 -> V_9 ) ;
}
static void F_30 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
struct V_4 * V_4 = F_2 ( V_2 ) ;
T_1 V_41 = F_4 ( F_14 ( V_12 ) % V_18 ) ;
T_1 V_42 ;
F_28 ( & V_4 -> V_9 ) ;
V_42 = F_3 ( V_4 -> V_5 + V_43 ) | V_41 ;
F_7 ( V_42 , V_4 -> V_5 + V_43 ) ;
F_29 ( & V_4 -> V_9 ) ;
}
static void F_31 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
struct V_4 * V_4 = F_2 ( V_2 ) ;
T_1 V_41 = F_4 ( F_14 ( V_12 ) % V_18 ) ;
F_28 ( & V_4 -> V_9 ) ;
F_7 ( V_41 , V_4 -> V_5 + V_44 ) ;
F_29 ( & V_4 -> V_9 ) ;
}
static int F_32 ( struct V_11 * V_12 , unsigned int V_45 )
{
struct V_1 * V_2 = F_13 ( V_12 ) ;
struct V_4 * V_4 = F_2 ( V_2 ) ;
return F_33 ( V_4 -> V_46 , V_45 ) ;
}
static int F_34 ( struct V_47 * V_48 , const struct V_49 * V_50 )
{
struct V_51 * V_52 = & V_48 -> V_52 ;
struct V_4 * V_4 ;
int V_53 , V_54 ;
V_4 = F_35 ( V_52 , sizeof( * V_4 ) , V_55 ) ;
if ( V_4 == NULL )
return - V_56 ;
V_4 -> V_5 = F_36 ( V_52 , & V_48 -> V_57 ) ;
if ( F_37 ( V_4 -> V_5 ) )
return F_38 ( V_4 -> V_5 ) ;
F_39 ( & V_4 -> V_9 ) ;
if ( F_40 ( V_52 -> V_58 , L_11 ) ) {
V_4 -> V_2 . V_59 = V_60 ;
V_4 -> V_2 . free = V_61 ;
}
V_4 -> V_2 . V_5 = - 1 ;
V_4 -> V_2 . V_62 = F_1 ;
V_4 -> V_2 . V_63 = F_5 ;
V_4 -> V_2 . V_64 = F_9 ;
V_4 -> V_2 . V_65 = F_10 ;
V_4 -> V_2 . V_66 = F_11 ;
V_4 -> V_2 . V_67 = V_18 ;
V_4 -> V_2 . V_68 = F_41 ( V_52 ) ;
V_4 -> V_2 . V_24 = V_52 ;
V_4 -> V_2 . V_69 = V_70 ;
V_53 = F_42 ( & V_4 -> V_2 , V_4 ) ;
if ( V_53 )
return V_53 ;
F_7 ( 0 , V_4 -> V_5 + V_43 ) ;
V_54 = V_48 -> V_54 [ 0 ] ;
if ( V_54 < 0 ) {
F_15 ( & V_48 -> V_52 , L_12 ) ;
return - V_71 ;
}
V_4 -> V_46 = V_54 ;
V_53 = F_43 ( & V_4 -> V_2 , & V_72 ,
0 , V_33 ,
V_73 ) ;
if ( V_53 ) {
F_44 ( & V_48 -> V_52 , L_13 ) ;
return V_53 ;
}
F_45 ( & V_4 -> V_2 , & V_72 ,
V_54 , F_19 ) ;
F_46 ( V_48 , V_4 ) ;
F_44 ( & V_48 -> V_52 , L_14 ,
& V_48 -> V_57 . V_74 ) ;
return 0 ;
}
static int F_47 ( struct V_51 * V_52 )
{
struct V_4 * V_4 = F_48 ( V_52 ) ;
int V_3 ;
V_4 -> V_75 . V_76 = 0 ;
V_4 -> V_75 . V_77 = F_3 ( V_4 -> V_5 + V_6 ) ;
V_4 -> V_75 . V_78 = F_3 ( V_4 -> V_5 + V_26 ) ;
V_4 -> V_75 . V_79 = F_3 ( V_4 -> V_5 + V_27 ) ;
V_4 -> V_75 . V_80 = F_3 ( V_4 -> V_5 + V_25 ) ;
V_4 -> V_75 . V_81 = F_3 ( V_4 -> V_5 + V_43 ) ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ ) {
if ( V_4 -> V_75 . V_77 & ( F_4 ( V_3 ) ) )
V_4 -> V_75 . V_76 |=
F_10 ( & V_4 -> V_2 , V_3 ) << V_3 ;
}
return 0 ;
}
static int F_49 ( struct V_51 * V_52 )
{
struct V_4 * V_4 = F_48 ( V_52 ) ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ ) {
if ( V_4 -> V_75 . V_77 & ( F_4 ( V_3 ) ) )
F_9 ( & V_4 -> V_2 , V_3 ,
V_4 -> V_75 . V_76 &
( F_4 ( V_3 ) ) ) ;
else
F_5 ( & V_4 -> V_2 , V_3 ) ;
}
F_7 ( V_4 -> V_75 . V_78 , V_4 -> V_5 + V_26 ) ;
F_7 ( V_4 -> V_75 . V_79 , V_4 -> V_5 + V_27 ) ;
F_7 ( V_4 -> V_75 . V_80 , V_4 -> V_5 + V_25 ) ;
F_7 ( V_4 -> V_75 . V_81 , V_4 -> V_5 + V_43 ) ;
return 0 ;
}
static int T_2 F_50 ( void )
{
return F_51 ( & V_82 ) ;
}
