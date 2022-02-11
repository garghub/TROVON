static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return ! ( F_3 ( V_5 -> V_6 + V_7 ) & F_4 ( V_3 ) ) ;
}
static int F_5 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_8 ;
unsigned char V_9 ;
F_6 ( & V_5 -> V_10 , V_8 ) ;
V_9 = F_3 ( V_5 -> V_6 + V_7 ) ;
V_9 &= ~ ( F_4 ( V_3 ) ) ;
F_7 ( V_9 , V_5 -> V_6 + V_7 ) ;
F_8 ( & V_5 -> V_10 , V_8 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned V_3 ,
int V_11 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_8 ;
unsigned char V_9 ;
F_6 ( & V_5 -> V_10 , V_8 ) ;
F_7 ( ! ! V_11 << V_3 , V_5 -> V_6 + ( F_4 ( V_3 + 2 ) ) ) ;
V_9 = F_3 ( V_5 -> V_6 + V_7 ) ;
V_9 |= F_4 ( V_3 ) ;
F_7 ( V_9 , V_5 -> V_6 + V_7 ) ;
F_7 ( ! ! V_11 << V_3 , V_5 -> V_6 + ( F_4 ( V_3 + 2 ) ) ) ;
F_8 ( & V_5 -> V_10 , V_8 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return ! ! F_3 ( V_5 -> V_6 + ( F_4 ( V_3 + 2 ) ) ) ;
}
static void F_11 ( struct V_1 * V_2 , unsigned V_3 , int V_11 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_7 ( ! ! V_11 << V_3 , V_5 -> V_6 + ( F_4 ( V_3 + 2 ) ) ) ;
}
static int F_12 ( struct V_12 * V_13 , unsigned V_14 )
{
struct V_1 * V_2 = F_13 ( V_13 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_3 = F_14 ( V_13 ) ;
unsigned long V_8 ;
T_1 V_15 , V_16 , V_17 ;
T_1 V_18 = F_4 ( V_3 ) ;
if ( V_3 < 0 || V_3 >= V_19 )
return - V_20 ;
if ( ( V_14 & ( V_21 | V_22 ) ) &&
( V_14 & ( V_23 | V_24 ) ) )
{
F_15 ( V_2 -> V_25 ,
L_1
L_2 ,
V_3 ) ;
return - V_20 ;
}
F_6 ( & V_5 -> V_10 , V_8 ) ;
V_17 = F_3 ( V_5 -> V_6 + V_26 ) ;
V_15 = F_3 ( V_5 -> V_6 + V_27 ) ;
V_16 = F_3 ( V_5 -> V_6 + V_28 ) ;
if ( V_14 & ( V_21 | V_22 ) ) {
bool V_29 = V_14 & V_21 ;
V_16 &= ~ V_18 ;
V_15 |= V_18 ;
if ( V_29 )
V_17 |= V_18 ;
else
V_17 &= ~ V_18 ;
F_16 ( V_13 , V_30 ) ;
F_17 ( V_2 -> V_25 , L_3 ,
V_3 ,
V_29 ? L_4 : L_5 ) ;
} else if ( ( V_14 & V_31 ) == V_31 ) {
V_15 &= ~ V_18 ;
V_16 |= V_18 ;
F_16 ( V_13 , V_32 ) ;
F_17 ( V_2 -> V_25 , L_6 , V_3 ) ;
} else if ( ( V_14 & V_23 ) ||
( V_14 & V_24 ) ) {
bool V_33 = V_14 & V_23 ;
V_15 &= ~ V_18 ;
V_16 &= ~ V_18 ;
if ( V_33 )
V_17 |= V_18 ;
else
V_17 &= ~ V_18 ;
F_16 ( V_13 , V_32 ) ;
F_17 ( V_2 -> V_25 , L_7 ,
V_3 ,
V_33 ? L_8 : L_9 ) ;
} else {
V_15 &= ~ V_18 ;
V_16 &= ~ V_18 ;
V_17 &= ~ V_18 ;
F_16 ( V_13 , V_34 ) ;
F_18 ( V_2 -> V_25 , L_10 ,
V_3 ) ;
}
F_7 ( V_15 , V_5 -> V_6 + V_27 ) ;
F_7 ( V_16 , V_5 -> V_6 + V_28 ) ;
F_7 ( V_17 , V_5 -> V_6 + V_26 ) ;
F_8 ( & V_5 -> V_10 , V_8 ) ;
return 0 ;
}
static void F_19 ( struct V_35 * V_36 )
{
unsigned long V_37 ;
int V_3 ;
struct V_1 * V_2 = F_20 ( V_36 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_38 * V_39 = F_21 ( V_36 ) ;
F_22 ( V_39 , V_36 ) ;
V_37 = F_3 ( V_5 -> V_6 + V_40 ) ;
if ( V_37 ) {
F_23 (offset, &pending, PL061_GPIO_NR)
F_24 ( F_25 ( V_2 -> V_41 ,
V_3 ) ) ;
}
F_26 ( V_39 , V_36 ) ;
}
static void F_27 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_13 ( V_13 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_42 = F_4 ( F_14 ( V_13 ) % V_19 ) ;
T_1 V_43 ;
F_28 ( & V_5 -> V_10 ) ;
V_43 = F_3 ( V_5 -> V_6 + V_44 ) & ~ V_42 ;
F_7 ( V_43 , V_5 -> V_6 + V_44 ) ;
F_29 ( & V_5 -> V_10 ) ;
}
static void F_30 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_13 ( V_13 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_42 = F_4 ( F_14 ( V_13 ) % V_19 ) ;
T_1 V_43 ;
F_28 ( & V_5 -> V_10 ) ;
V_43 = F_3 ( V_5 -> V_6 + V_44 ) | V_42 ;
F_7 ( V_43 , V_5 -> V_6 + V_44 ) ;
F_29 ( & V_5 -> V_10 ) ;
}
static void F_31 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_13 ( V_13 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_42 = F_4 ( F_14 ( V_13 ) % V_19 ) ;
F_28 ( & V_5 -> V_10 ) ;
F_7 ( V_42 , V_5 -> V_6 + V_45 ) ;
F_29 ( & V_5 -> V_10 ) ;
}
static int F_32 ( struct V_12 * V_13 , unsigned int V_46 )
{
struct V_1 * V_2 = F_13 ( V_13 ) ;
return F_33 ( V_2 -> V_47 , V_46 ) ;
}
static int F_34 ( struct V_48 * V_49 , const struct V_50 * V_51 )
{
struct V_52 * V_53 = & V_49 -> V_53 ;
struct V_54 * V_55 = F_35 ( V_53 ) ;
struct V_4 * V_5 ;
int V_56 , V_57 , V_58 , V_59 ;
V_5 = F_36 ( V_53 , sizeof( * V_5 ) , V_60 ) ;
if ( V_5 == NULL )
return - V_61 ;
if ( V_55 ) {
V_5 -> V_2 . V_6 = V_55 -> V_62 ;
V_59 = V_55 -> V_59 ;
if ( V_59 <= 0 ) {
F_15 ( & V_49 -> V_53 , L_11 ) ;
return - V_63 ;
}
} else {
V_5 -> V_2 . V_6 = - 1 ;
V_59 = 0 ;
}
V_5 -> V_6 = F_37 ( V_53 , & V_49 -> V_64 ) ;
if ( F_38 ( V_5 -> V_6 ) )
return F_39 ( V_5 -> V_6 ) ;
F_40 ( & V_5 -> V_10 ) ;
if ( F_41 ( V_53 -> V_65 , L_12 ) ) {
V_5 -> V_2 . V_66 = V_67 ;
V_5 -> V_2 . free = V_68 ;
}
V_5 -> V_2 . V_69 = F_1 ;
V_5 -> V_2 . V_70 = F_5 ;
V_5 -> V_2 . V_71 = F_9 ;
V_5 -> V_2 . V_72 = F_10 ;
V_5 -> V_2 . V_73 = F_11 ;
V_5 -> V_2 . V_74 = V_19 ;
V_5 -> V_2 . V_75 = F_42 ( V_53 ) ;
V_5 -> V_2 . V_25 = V_53 ;
V_5 -> V_2 . V_76 = V_77 ;
V_56 = F_43 ( & V_5 -> V_2 , V_5 ) ;
if ( V_56 )
return V_56 ;
F_7 ( 0 , V_5 -> V_6 + V_44 ) ;
V_57 = V_49 -> V_57 [ 0 ] ;
if ( V_57 < 0 ) {
F_15 ( & V_49 -> V_53 , L_13 ) ;
return - V_63 ;
}
V_56 = F_44 ( & V_5 -> V_2 , & V_78 ,
V_59 , V_34 ,
V_79 ) ;
if ( V_56 ) {
F_45 ( & V_49 -> V_53 , L_14 ) ;
return V_56 ;
}
F_46 ( & V_5 -> V_2 , & V_78 ,
V_57 , F_19 ) ;
for ( V_58 = 0 ; V_58 < V_19 ; V_58 ++ ) {
if ( V_55 ) {
if ( V_55 -> V_80 & ( F_4 ( V_58 ) ) )
F_9 ( & V_5 -> V_2 , V_58 ,
V_55 -> V_81 & ( F_4 ( V_58 ) ) ) ;
else
F_5 ( & V_5 -> V_2 , V_58 ) ;
}
}
F_47 ( V_49 , V_5 ) ;
F_45 ( & V_49 -> V_53 , L_15 ,
& V_49 -> V_64 . V_82 ) ;
return 0 ;
}
static int F_48 ( struct V_52 * V_53 )
{
struct V_4 * V_5 = F_49 ( V_53 ) ;
int V_3 ;
V_5 -> V_83 . V_84 = 0 ;
V_5 -> V_83 . V_85 = F_3 ( V_5 -> V_6 + V_7 ) ;
V_5 -> V_83 . V_86 = F_3 ( V_5 -> V_6 + V_27 ) ;
V_5 -> V_83 . V_87 = F_3 ( V_5 -> V_6 + V_28 ) ;
V_5 -> V_83 . V_88 = F_3 ( V_5 -> V_6 + V_26 ) ;
V_5 -> V_83 . V_89 = F_3 ( V_5 -> V_6 + V_44 ) ;
for ( V_3 = 0 ; V_3 < V_19 ; V_3 ++ ) {
if ( V_5 -> V_83 . V_85 & ( F_4 ( V_3 ) ) )
V_5 -> V_83 . V_84 |=
F_10 ( & V_5 -> V_2 , V_3 ) << V_3 ;
}
return 0 ;
}
static int F_50 ( struct V_52 * V_53 )
{
struct V_4 * V_5 = F_49 ( V_53 ) ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_19 ; V_3 ++ ) {
if ( V_5 -> V_83 . V_85 & ( F_4 ( V_3 ) ) )
F_9 ( & V_5 -> V_2 , V_3 ,
V_5 -> V_83 . V_84 &
( F_4 ( V_3 ) ) ) ;
else
F_5 ( & V_5 -> V_2 , V_3 ) ;
}
F_7 ( V_5 -> V_83 . V_86 , V_5 -> V_6 + V_27 ) ;
F_7 ( V_5 -> V_83 . V_87 , V_5 -> V_6 + V_28 ) ;
F_7 ( V_5 -> V_83 . V_88 , V_5 -> V_6 + V_26 ) ;
F_7 ( V_5 -> V_83 . V_89 , V_5 -> V_6 + V_44 ) ;
return 0 ;
}
static int T_2 F_51 ( void )
{
return F_52 ( & V_90 ) ;
}
