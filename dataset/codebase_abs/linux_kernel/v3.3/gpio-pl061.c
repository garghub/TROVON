static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
unsigned long V_6 ;
unsigned char V_7 ;
if ( V_3 >= V_2 -> V_8 )
return - V_9 ;
F_3 ( & V_5 -> V_10 , V_6 ) ;
V_7 = F_4 ( V_5 -> V_11 + V_12 ) ;
V_7 &= ~ ( 1 << V_3 ) ;
F_5 ( V_7 , V_5 -> V_11 + V_12 ) ;
F_6 ( & V_5 -> V_10 , V_6 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned V_3 ,
int V_13 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
unsigned long V_6 ;
unsigned char V_7 ;
if ( V_3 >= V_2 -> V_8 )
return - V_9 ;
F_3 ( & V_5 -> V_10 , V_6 ) ;
F_5 ( ! ! V_13 << V_3 , V_5 -> V_11 + ( 1 << ( V_3 + 2 ) ) ) ;
V_7 = F_4 ( V_5 -> V_11 + V_12 ) ;
V_7 |= 1 << V_3 ;
F_5 ( V_7 , V_5 -> V_11 + V_12 ) ;
F_5 ( ! ! V_13 << V_3 , V_5 -> V_11 + ( 1 << ( V_3 + 2 ) ) ) ;
F_6 ( & V_5 -> V_10 , V_6 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
return ! ! F_4 ( V_5 -> V_11 + ( 1 << ( V_3 + 2 ) ) ) ;
}
static void F_9 ( struct V_1 * V_2 , unsigned V_3 , int V_13 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
F_5 ( ! ! V_13 << V_3 , V_5 -> V_11 + ( 1 << ( V_3 + 2 ) ) ) ;
}
static int F_10 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
if ( V_5 -> V_14 <= 0 )
return - V_9 ;
return V_5 -> V_14 + V_3 ;
}
static int F_11 ( struct V_15 * V_16 , unsigned V_17 )
{
struct V_18 * V_2 = F_12 ( V_16 ) ;
struct V_4 * V_5 = V_2 -> V_19 ;
int V_3 = V_16 -> V_20 - V_5 -> V_14 ;
unsigned long V_6 ;
T_1 V_21 , V_22 , V_23 ;
if ( V_3 < 0 || V_3 >= V_24 )
return - V_9 ;
F_13 ( & V_2 -> V_10 , V_6 ) ;
V_23 = F_4 ( V_5 -> V_11 + V_25 ) ;
V_21 = F_4 ( V_5 -> V_11 + V_26 ) ;
if ( V_17 & ( V_27 | V_28 ) ) {
V_21 |= 1 << V_3 ;
if ( V_17 & V_27 )
V_23 |= 1 << V_3 ;
else
V_23 &= ~ ( 1 << V_3 ) ;
} else
V_21 &= ~ ( 1 << V_3 ) ;
F_5 ( V_21 , V_5 -> V_11 + V_26 ) ;
V_22 = F_4 ( V_5 -> V_11 + V_29 ) ;
if ( ( V_17 & V_30 ) == V_30 )
V_22 |= 1 << V_3 ;
else {
V_22 &= ~ ( 1 << V_3 ) ;
if ( V_17 & V_31 )
V_23 |= 1 << V_3 ;
else if ( V_17 & V_32 )
V_23 &= ~ ( 1 << V_3 ) ;
}
F_5 ( V_22 , V_5 -> V_11 + V_29 ) ;
F_5 ( V_23 , V_5 -> V_11 + V_25 ) ;
F_14 ( & V_2 -> V_10 , V_6 ) ;
return 0 ;
}
static void F_15 ( unsigned V_20 , struct V_33 * V_34 )
{
unsigned long V_35 ;
int V_3 ;
struct V_4 * V_5 = F_16 ( V_34 ) ;
struct V_36 * V_37 = F_17 ( V_34 ) ;
F_18 ( V_37 , V_34 ) ;
V_35 = F_4 ( V_5 -> V_11 + V_38 ) ;
F_5 ( V_35 , V_5 -> V_11 + V_39 ) ;
if ( V_35 ) {
F_19 (offset, &pending, PL061_GPIO_NR)
F_20 ( F_10 ( & V_5 -> V_2 , V_3 ) ) ;
}
F_21 ( V_37 , V_34 ) ;
}
static void T_2 F_22 ( struct V_4 * V_5 , int V_14 )
{
struct V_40 * V_41 ;
V_5 -> V_42 = F_23 ( L_1 , 1 , V_14 ,
V_5 -> V_11 , V_43 ) ;
V_5 -> V_42 -> V_19 = V_5 ;
V_41 = V_5 -> V_42 -> V_44 ;
V_41 -> V_5 . V_45 = V_46 ;
V_41 -> V_5 . V_47 = V_48 ;
V_41 -> V_5 . V_49 = F_11 ;
V_41 -> V_5 . V_50 = V_51 ;
V_41 -> V_52 . V_53 = V_54 ;
F_24 ( V_5 -> V_42 , F_25 ( V_24 ) ,
V_55 , V_56 , 0 ) ;
}
static int F_26 ( struct V_57 * V_58 , const struct V_59 * V_60 )
{
struct V_61 * V_62 ;
struct V_4 * V_5 ;
int V_63 , V_20 , V_64 ;
V_5 = F_27 ( sizeof( * V_5 ) , V_65 ) ;
if ( V_5 == NULL )
return - V_66 ;
V_62 = V_58 -> V_58 . V_67 ;
if ( V_62 ) {
V_5 -> V_2 . V_11 = V_62 -> V_68 ;
V_5 -> V_14 = V_62 -> V_14 ;
} else if ( V_58 -> V_58 . V_69 ) {
V_5 -> V_2 . V_11 = - 1 ;
V_5 -> V_14 = 0 ;
} else {
V_63 = - V_70 ;
goto V_71;
}
if ( ! F_28 ( V_58 -> V_72 . V_73 ,
F_29 ( & V_58 -> V_72 ) , L_2 ) ) {
V_63 = - V_74 ;
goto V_71;
}
V_5 -> V_11 = F_30 ( V_58 -> V_72 . V_73 , F_29 ( & V_58 -> V_72 ) ) ;
if ( V_5 -> V_11 == NULL ) {
V_63 = - V_66 ;
goto V_75;
}
F_31 ( & V_5 -> V_10 ) ;
V_5 -> V_2 . V_76 = F_1 ;
V_5 -> V_2 . V_77 = F_7 ;
V_5 -> V_2 . V_78 = F_8 ;
V_5 -> V_2 . V_79 = F_9 ;
V_5 -> V_2 . V_80 = F_10 ;
V_5 -> V_2 . V_8 = V_24 ;
V_5 -> V_2 . V_81 = F_32 ( & V_58 -> V_58 ) ;
V_5 -> V_2 . V_58 = & V_58 -> V_58 ;
V_5 -> V_2 . V_82 = V_83 ;
V_63 = F_33 ( & V_5 -> V_2 ) ;
if ( V_63 )
goto V_84;
if ( V_5 -> V_14 <= 0 )
return 0 ;
F_22 ( V_5 , V_5 -> V_14 ) ;
F_5 ( 0 , V_5 -> V_11 + V_54 ) ;
V_20 = V_58 -> V_20 [ 0 ] ;
if ( V_20 < 0 ) {
V_63 = - V_70 ;
goto V_84;
}
F_34 ( V_20 , F_15 ) ;
F_35 ( V_20 , V_5 ) ;
for ( V_64 = 0 ; V_64 < V_24 ; V_64 ++ ) {
if ( V_62 ) {
if ( V_62 -> V_85 & ( 1 << V_64 ) )
F_7 ( & V_5 -> V_2 , V_64 ,
V_62 -> V_86 & ( 1 << V_64 ) ) ;
else
F_1 ( & V_5 -> V_2 , V_64 ) ;
}
}
F_36 ( V_58 , V_5 ) ;
return 0 ;
V_84:
V_84 ( V_5 -> V_11 ) ;
V_75:
F_37 ( V_58 -> V_72 . V_73 , F_29 ( & V_58 -> V_72 ) ) ;
V_71:
F_38 ( V_5 ) ;
return V_63 ;
}
static int F_39 ( struct V_87 * V_58 )
{
struct V_4 * V_5 = F_40 ( V_58 ) ;
int V_3 ;
V_5 -> V_88 . V_89 = 0 ;
V_5 -> V_88 . V_90 = F_4 ( V_5 -> V_11 + V_12 ) ;
V_5 -> V_88 . V_91 = F_4 ( V_5 -> V_11 + V_26 ) ;
V_5 -> V_88 . V_92 = F_4 ( V_5 -> V_11 + V_29 ) ;
V_5 -> V_88 . V_93 = F_4 ( V_5 -> V_11 + V_25 ) ;
V_5 -> V_88 . V_94 = F_4 ( V_5 -> V_11 + V_54 ) ;
for ( V_3 = 0 ; V_3 < V_24 ; V_3 ++ ) {
if ( V_5 -> V_88 . V_90 & ( 1 << V_3 ) )
V_5 -> V_88 . V_89 |=
F_8 ( & V_5 -> V_2 , V_3 ) << V_3 ;
}
return 0 ;
}
static int F_41 ( struct V_87 * V_58 )
{
struct V_4 * V_5 = F_40 ( V_58 ) ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_24 ; V_3 ++ ) {
if ( V_5 -> V_88 . V_90 & ( 1 << V_3 ) )
F_7 ( & V_5 -> V_2 , V_3 ,
V_5 -> V_88 . V_89 &
( 1 << V_3 ) ) ;
else
F_1 ( & V_5 -> V_2 , V_3 ) ;
}
F_5 ( V_5 -> V_88 . V_91 , V_5 -> V_11 + V_26 ) ;
F_5 ( V_5 -> V_88 . V_92 , V_5 -> V_11 + V_29 ) ;
F_5 ( V_5 -> V_88 . V_93 , V_5 -> V_11 + V_25 ) ;
F_5 ( V_5 -> V_88 . V_94 , V_5 -> V_11 + V_54 ) ;
return 0 ;
}
static int T_2 F_42 ( void )
{
return F_43 ( & V_95 ) ;
}
