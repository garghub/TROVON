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
static int F_14 ( struct V_1 * V_6 , unsigned V_3 )
{
struct V_7 * V_2 = F_6 ( V_6 , struct V_7 , V_6 ) ;
return F_15 ( V_2 -> V_15 , V_3 ) ;
}
static int F_16 ( struct V_16 * V_17 , unsigned V_18 )
{
struct V_7 * V_2 = F_17 ( V_17 ) ;
int V_3 = F_18 ( V_17 ) ;
unsigned long V_8 ;
T_1 V_19 , V_20 , V_21 ;
if ( V_3 < 0 || V_3 >= V_22 )
return - V_11 ;
F_7 ( & V_2 -> V_12 , V_8 ) ;
V_21 = F_8 ( V_2 -> V_5 + V_23 ) ;
V_19 = F_8 ( V_2 -> V_5 + V_24 ) ;
if ( V_18 & ( V_25 | V_26 ) ) {
V_19 |= 1 << V_3 ;
if ( V_18 & V_25 )
V_21 |= 1 << V_3 ;
else
V_21 &= ~ ( 1 << V_3 ) ;
} else
V_19 &= ~ ( 1 << V_3 ) ;
F_9 ( V_19 , V_2 -> V_5 + V_24 ) ;
V_20 = F_8 ( V_2 -> V_5 + V_27 ) ;
if ( ( V_18 & V_28 ) == V_28 )
V_20 |= 1 << V_3 ;
else {
V_20 &= ~ ( 1 << V_3 ) ;
if ( V_18 & V_29 )
V_21 |= 1 << V_3 ;
else if ( V_18 & V_30 )
V_21 &= ~ ( 1 << V_3 ) ;
}
F_9 ( V_20 , V_2 -> V_5 + V_27 ) ;
F_9 ( V_21 , V_2 -> V_5 + V_23 ) ;
F_10 ( & V_2 -> V_12 , V_8 ) ;
return 0 ;
}
static void F_19 ( unsigned V_31 , struct V_32 * V_33 )
{
unsigned long V_34 ;
int V_3 ;
struct V_7 * V_2 = F_20 ( V_33 ) ;
struct V_35 * V_36 = F_21 ( V_33 ) ;
F_22 ( V_36 , V_33 ) ;
V_34 = F_8 ( V_2 -> V_5 + V_37 ) ;
F_9 ( V_34 , V_2 -> V_5 + V_38 ) ;
if ( V_34 ) {
F_23 (offset, &pending, PL061_GPIO_NR)
F_24 ( F_14 ( & V_2 -> V_6 , V_3 ) ) ;
}
F_25 ( V_36 , V_33 ) ;
}
static void F_26 ( struct V_16 * V_17 )
{
struct V_7 * V_2 = F_17 ( V_17 ) ;
T_1 V_39 = 1 << ( F_18 ( V_17 ) % V_22 ) ;
T_1 V_40 ;
F_27 ( & V_2 -> V_12 ) ;
V_40 = F_8 ( V_2 -> V_5 + V_41 ) & ~ V_39 ;
F_9 ( V_40 , V_2 -> V_5 + V_41 ) ;
F_28 ( & V_2 -> V_12 ) ;
}
static void F_29 ( struct V_16 * V_17 )
{
struct V_7 * V_2 = F_17 ( V_17 ) ;
T_1 V_39 = 1 << ( F_18 ( V_17 ) % V_22 ) ;
T_1 V_40 ;
F_27 ( & V_2 -> V_12 ) ;
V_40 = F_8 ( V_2 -> V_5 + V_41 ) | V_39 ;
F_9 ( V_40 , V_2 -> V_5 + V_41 ) ;
F_28 ( & V_2 -> V_12 ) ;
}
static int F_30 ( struct V_42 * V_17 , unsigned int V_43 ,
T_2 V_44 )
{
struct V_7 * V_2 = V_17 -> V_45 ;
F_31 ( V_43 , & V_46 , V_47 ,
L_1 ) ;
F_32 ( V_43 , V_2 ) ;
F_33 ( V_43 , V_48 ) ;
return 0 ;
}
static int F_34 ( struct V_49 * V_50 , const struct V_51 * V_52 )
{
struct V_53 * V_54 = & V_50 -> V_54 ;
struct V_55 * V_56 = V_54 -> V_57 ;
struct V_7 * V_2 ;
int V_58 , V_31 , V_59 , V_60 ;
V_2 = F_35 ( V_54 , sizeof( * V_2 ) , V_61 ) ;
if ( V_2 == NULL )
return - V_62 ;
if ( V_56 ) {
V_2 -> V_6 . V_5 = V_56 -> V_63 ;
V_60 = V_56 -> V_60 ;
if ( V_60 <= 0 )
return - V_64 ;
} else {
V_2 -> V_6 . V_5 = - 1 ;
V_60 = 0 ;
}
if ( ! F_36 ( V_54 , V_50 -> V_65 . V_66 ,
F_37 ( & V_50 -> V_65 ) , L_1 ) )
return - V_67 ;
V_2 -> V_5 = F_38 ( V_54 , V_50 -> V_65 . V_66 ,
F_37 ( & V_50 -> V_65 ) ) ;
if ( ! V_2 -> V_5 )
return - V_62 ;
V_2 -> V_15 = F_39 ( V_50 -> V_54 . V_68 , V_22 ,
V_60 , & V_69 , V_2 ) ;
if ( ! V_2 -> V_15 )
return - V_64 ;
F_40 ( & V_2 -> V_12 ) ;
V_2 -> V_6 . V_70 = F_1 ;
V_2 -> V_6 . free = F_3 ;
V_2 -> V_6 . V_71 = F_5 ;
V_2 -> V_6 . V_72 = F_11 ;
V_2 -> V_6 . V_73 = F_12 ;
V_2 -> V_6 . V_74 = F_13 ;
V_2 -> V_6 . V_75 = F_14 ;
V_2 -> V_6 . V_10 = V_22 ;
V_2 -> V_6 . V_76 = F_41 ( V_54 ) ;
V_2 -> V_6 . V_54 = V_54 ;
V_2 -> V_6 . V_77 = V_78 ;
V_58 = F_42 ( & V_2 -> V_6 ) ;
if ( V_58 )
return V_58 ;
F_9 ( 0 , V_2 -> V_5 + V_41 ) ;
V_31 = V_50 -> V_31 [ 0 ] ;
if ( V_31 < 0 )
return - V_64 ;
F_43 ( V_31 , F_19 ) ;
F_44 ( V_31 , V_2 ) ;
for ( V_59 = 0 ; V_59 < V_22 ; V_59 ++ ) {
if ( V_56 ) {
if ( V_56 -> V_79 & ( 1 << V_59 ) )
F_11 ( & V_2 -> V_6 , V_59 ,
V_56 -> V_80 & ( 1 << V_59 ) ) ;
else
F_5 ( & V_2 -> V_6 , V_59 ) ;
}
}
F_45 ( V_50 , V_2 ) ;
return 0 ;
}
static int F_46 ( struct V_53 * V_54 )
{
struct V_7 * V_2 = F_47 ( V_54 ) ;
int V_3 ;
V_2 -> V_81 . V_82 = 0 ;
V_2 -> V_81 . V_83 = F_8 ( V_2 -> V_5 + V_13 ) ;
V_2 -> V_81 . V_84 = F_8 ( V_2 -> V_5 + V_24 ) ;
V_2 -> V_81 . V_85 = F_8 ( V_2 -> V_5 + V_27 ) ;
V_2 -> V_81 . V_86 = F_8 ( V_2 -> V_5 + V_23 ) ;
V_2 -> V_81 . V_87 = F_8 ( V_2 -> V_5 + V_41 ) ;
for ( V_3 = 0 ; V_3 < V_22 ; V_3 ++ ) {
if ( V_2 -> V_81 . V_83 & ( 1 << V_3 ) )
V_2 -> V_81 . V_82 |=
F_12 ( & V_2 -> V_6 , V_3 ) << V_3 ;
}
return 0 ;
}
static int F_48 ( struct V_53 * V_54 )
{
struct V_7 * V_2 = F_47 ( V_54 ) ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_22 ; V_3 ++ ) {
if ( V_2 -> V_81 . V_83 & ( 1 << V_3 ) )
F_11 ( & V_2 -> V_6 , V_3 ,
V_2 -> V_81 . V_82 &
( 1 << V_3 ) ) ;
else
F_5 ( & V_2 -> V_6 , V_3 ) ;
}
F_9 ( V_2 -> V_81 . V_84 , V_2 -> V_5 + V_24 ) ;
F_9 ( V_2 -> V_81 . V_85 , V_2 -> V_5 + V_27 ) ;
F_9 ( V_2 -> V_81 . V_86 , V_2 -> V_5 + V_23 ) ;
F_9 ( V_2 -> V_81 . V_87 , V_2 -> V_5 + V_41 ) ;
return 0 ;
}
static int T_3 F_49 ( void )
{
return F_50 ( & V_88 ) ;
}
