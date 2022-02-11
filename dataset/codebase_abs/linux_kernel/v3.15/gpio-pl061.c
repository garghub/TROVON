static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
int V_4 = V_2 -> V_5 + V_3 ;
return F_2 ( V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 , unsigned V_3 )
{
int V_4 = V_2 -> V_5 + V_3 ;
F_4 ( V_4 ) ;
}
static int F_5 ( struct V_1 * V_6 , unsigned V_3 )
{
struct V_7 * V_2 = F_6 ( V_6 , struct V_7 , V_6 ) ;
unsigned long V_8 ;
unsigned char V_9 ;
if ( V_3 >= V_6 -> V_10 )
return - V_11 ;
F_7 ( & V_2 -> V_12 , V_8 ) ;
V_9 = F_8 ( V_2 -> V_5 + V_13 ) ;
V_9 &= ~ ( 1 << V_3 ) ;
F_9 ( V_9 , V_2 -> V_5 + V_13 ) ;
F_10 ( & V_2 -> V_12 , V_8 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_6 , unsigned V_3 ,
int V_14 )
{
struct V_7 * V_2 = F_6 ( V_6 , struct V_7 , V_6 ) ;
unsigned long V_8 ;
unsigned char V_9 ;
if ( V_3 >= V_6 -> V_10 )
return - V_11 ;
F_7 ( & V_2 -> V_12 , V_8 ) ;
F_9 ( ! ! V_14 << V_3 , V_2 -> V_5 + ( 1 << ( V_3 + 2 ) ) ) ;
V_9 = F_8 ( V_2 -> V_5 + V_13 ) ;
V_9 |= 1 << V_3 ;
F_9 ( V_9 , V_2 -> V_5 + V_13 ) ;
F_9 ( ! ! V_14 << V_3 , V_2 -> V_5 + ( 1 << ( V_3 + 2 ) ) ) ;
F_10 ( & V_2 -> V_12 , V_8 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_6 , unsigned V_3 )
{
struct V_7 * V_2 = F_6 ( V_6 , struct V_7 , V_6 ) ;
return ! ! F_8 ( V_2 -> V_5 + ( 1 << ( V_3 + 2 ) ) ) ;
}
static void F_13 ( struct V_1 * V_6 , unsigned V_3 , int V_14 )
{
struct V_7 * V_2 = F_6 ( V_6 , struct V_7 , V_6 ) ;
F_9 ( ! ! V_14 << V_3 , V_2 -> V_5 + ( 1 << ( V_3 + 2 ) ) ) ;
}
static int F_14 ( struct V_15 * V_16 , unsigned V_17 )
{
struct V_1 * V_6 = F_15 ( V_16 ) ;
struct V_7 * V_2 = F_6 ( V_6 , struct V_7 , V_6 ) ;
int V_3 = F_16 ( V_16 ) ;
unsigned long V_8 ;
T_1 V_18 , V_19 , V_20 ;
T_1 V_21 = F_17 ( V_3 ) ;
if ( V_3 < 0 || V_3 >= V_22 )
return - V_11 ;
F_7 ( & V_2 -> V_12 , V_8 ) ;
V_20 = F_8 ( V_2 -> V_5 + V_23 ) ;
V_18 = F_8 ( V_2 -> V_5 + V_24 ) ;
V_19 = F_8 ( V_2 -> V_5 + V_25 ) ;
if ( V_17 & ( V_26 | V_27 ) ) {
V_18 |= V_21 ;
if ( V_17 & V_26 )
V_20 |= V_21 ;
else
V_20 &= ~ V_21 ;
} else
V_18 &= ~ V_21 ;
if ( ( V_17 & V_28 ) == V_28 )
V_19 |= V_21 ;
else {
V_19 &= ~ V_21 ;
if ( V_17 & V_29 )
V_20 |= V_21 ;
else if ( V_17 & V_30 )
V_20 &= ~ V_21 ;
}
F_9 ( V_18 , V_2 -> V_5 + V_24 ) ;
F_9 ( V_19 , V_2 -> V_5 + V_25 ) ;
F_9 ( V_20 , V_2 -> V_5 + V_23 ) ;
F_10 ( & V_2 -> V_12 , V_8 ) ;
return 0 ;
}
static void F_18 ( unsigned V_31 , struct V_32 * V_33 )
{
unsigned long V_34 ;
int V_3 ;
struct V_1 * V_6 = F_19 ( V_33 ) ;
struct V_7 * V_2 = F_6 ( V_6 , struct V_7 , V_6 ) ;
struct V_35 * V_36 = F_20 ( V_33 ) ;
F_21 ( V_36 , V_33 ) ;
V_34 = F_8 ( V_2 -> V_5 + V_37 ) ;
F_9 ( V_34 , V_2 -> V_5 + V_38 ) ;
if ( V_34 ) {
F_22 (offset, &pending, PL061_GPIO_NR)
F_23 ( F_24 ( V_6 -> V_39 ,
V_3 ) ) ;
}
F_25 ( V_36 , V_33 ) ;
}
static void F_26 ( struct V_15 * V_16 )
{
struct V_1 * V_6 = F_15 ( V_16 ) ;
struct V_7 * V_2 = F_6 ( V_6 , struct V_7 , V_6 ) ;
T_1 V_40 = 1 << ( F_16 ( V_16 ) % V_22 ) ;
T_1 V_41 ;
F_27 ( & V_2 -> V_12 ) ;
V_41 = F_8 ( V_2 -> V_5 + V_42 ) & ~ V_40 ;
F_9 ( V_41 , V_2 -> V_5 + V_42 ) ;
F_28 ( & V_2 -> V_12 ) ;
}
static void F_29 ( struct V_15 * V_16 )
{
struct V_1 * V_6 = F_15 ( V_16 ) ;
struct V_7 * V_2 = F_6 ( V_6 , struct V_7 , V_6 ) ;
T_1 V_40 = 1 << ( F_16 ( V_16 ) % V_22 ) ;
T_1 V_41 ;
F_27 ( & V_2 -> V_12 ) ;
V_41 = F_8 ( V_2 -> V_5 + V_42 ) | V_40 ;
F_9 ( V_41 , V_2 -> V_5 + V_42 ) ;
F_28 ( & V_2 -> V_12 ) ;
}
static int F_30 ( struct V_43 * V_44 , const struct V_45 * V_46 )
{
struct V_47 * V_48 = & V_44 -> V_48 ;
struct V_49 * V_50 = F_31 ( V_48 ) ;
struct V_7 * V_2 ;
int V_51 , V_31 , V_52 , V_53 ;
V_2 = F_32 ( V_48 , sizeof( * V_2 ) , V_54 ) ;
if ( V_2 == NULL )
return - V_55 ;
if ( V_50 ) {
V_2 -> V_6 . V_5 = V_50 -> V_56 ;
V_53 = V_50 -> V_53 ;
if ( V_53 <= 0 ) {
F_33 ( & V_44 -> V_48 , L_1 ) ;
return - V_57 ;
}
} else {
V_2 -> V_6 . V_5 = - 1 ;
V_53 = 0 ;
}
V_2 -> V_5 = F_34 ( V_48 , & V_44 -> V_58 ) ;
if ( F_35 ( V_2 -> V_5 ) )
return F_36 ( V_2 -> V_5 ) ;
F_37 ( & V_2 -> V_12 ) ;
V_2 -> V_6 . V_59 = F_1 ;
V_2 -> V_6 . free = F_3 ;
V_2 -> V_6 . V_60 = F_5 ;
V_2 -> V_6 . V_61 = F_11 ;
V_2 -> V_6 . V_62 = F_12 ;
V_2 -> V_6 . V_63 = F_13 ;
V_2 -> V_6 . V_10 = V_22 ;
V_2 -> V_6 . V_64 = F_38 ( V_48 ) ;
V_2 -> V_6 . V_48 = V_48 ;
V_2 -> V_6 . V_65 = V_66 ;
V_51 = F_39 ( & V_2 -> V_6 ) ;
if ( V_51 )
return V_51 ;
F_9 ( 0 , V_2 -> V_5 + V_42 ) ;
V_31 = V_44 -> V_31 [ 0 ] ;
if ( V_31 < 0 ) {
F_33 ( & V_44 -> V_48 , L_2 ) ;
return - V_57 ;
}
V_51 = F_40 ( & V_2 -> V_6 , & V_67 ,
V_53 , V_68 ,
V_69 ) ;
if ( V_51 ) {
F_41 ( & V_44 -> V_48 , L_3 ) ;
return V_51 ;
}
F_42 ( & V_2 -> V_6 , & V_67 ,
V_31 , F_18 ) ;
for ( V_52 = 0 ; V_52 < V_22 ; V_52 ++ ) {
if ( V_50 ) {
if ( V_50 -> V_70 & ( 1 << V_52 ) )
F_11 ( & V_2 -> V_6 , V_52 ,
V_50 -> V_71 & ( 1 << V_52 ) ) ;
else
F_5 ( & V_2 -> V_6 , V_52 ) ;
}
}
F_43 ( V_44 , V_2 ) ;
F_41 ( & V_44 -> V_48 , L_4 ,
& V_44 -> V_58 . V_72 ) ;
return 0 ;
}
static int F_44 ( struct V_47 * V_48 )
{
struct V_7 * V_2 = F_45 ( V_48 ) ;
int V_3 ;
V_2 -> V_73 . V_74 = 0 ;
V_2 -> V_73 . V_75 = F_8 ( V_2 -> V_5 + V_13 ) ;
V_2 -> V_73 . V_76 = F_8 ( V_2 -> V_5 + V_24 ) ;
V_2 -> V_73 . V_77 = F_8 ( V_2 -> V_5 + V_25 ) ;
V_2 -> V_73 . V_78 = F_8 ( V_2 -> V_5 + V_23 ) ;
V_2 -> V_73 . V_79 = F_8 ( V_2 -> V_5 + V_42 ) ;
for ( V_3 = 0 ; V_3 < V_22 ; V_3 ++ ) {
if ( V_2 -> V_73 . V_75 & ( 1 << V_3 ) )
V_2 -> V_73 . V_74 |=
F_12 ( & V_2 -> V_6 , V_3 ) << V_3 ;
}
return 0 ;
}
static int F_46 ( struct V_47 * V_48 )
{
struct V_7 * V_2 = F_45 ( V_48 ) ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_22 ; V_3 ++ ) {
if ( V_2 -> V_73 . V_75 & ( 1 << V_3 ) )
F_11 ( & V_2 -> V_6 , V_3 ,
V_2 -> V_73 . V_74 &
( 1 << V_3 ) ) ;
else
F_5 ( & V_2 -> V_6 , V_3 ) ;
}
F_9 ( V_2 -> V_73 . V_76 , V_2 -> V_5 + V_24 ) ;
F_9 ( V_2 -> V_73 . V_77 , V_2 -> V_5 + V_25 ) ;
F_9 ( V_2 -> V_73 . V_78 , V_2 -> V_5 + V_23 ) ;
F_9 ( V_2 -> V_73 . V_79 , V_2 -> V_5 + V_42 ) ;
return 0 ;
}
static int T_2 F_47 ( void )
{
return F_48 ( & V_80 ) ;
}
