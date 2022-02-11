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
if ( V_5 -> V_14 == V_15 )
return - V_9 ;
return V_5 -> V_14 + V_3 ;
}
static void F_11 ( struct V_16 * V_17 )
{
struct V_4 * V_5 = F_12 ( V_17 ) ;
int V_3 = V_17 -> V_18 - V_5 -> V_14 ;
unsigned long V_6 ;
T_1 V_19 ;
F_3 ( & V_5 -> V_20 , V_6 ) ;
V_19 = F_4 ( V_5 -> V_11 + V_21 ) ;
V_19 &= ~ ( 1 << V_3 ) ;
F_5 ( V_19 , V_5 -> V_11 + V_21 ) ;
F_6 ( & V_5 -> V_20 , V_6 ) ;
}
static void F_13 ( struct V_16 * V_17 )
{
struct V_4 * V_5 = F_12 ( V_17 ) ;
int V_3 = V_17 -> V_18 - V_5 -> V_14 ;
unsigned long V_6 ;
T_1 V_19 ;
F_3 ( & V_5 -> V_20 , V_6 ) ;
V_19 = F_4 ( V_5 -> V_11 + V_21 ) ;
V_19 |= 1 << V_3 ;
F_5 ( V_19 , V_5 -> V_11 + V_21 ) ;
F_6 ( & V_5 -> V_20 , V_6 ) ;
}
static int F_14 ( struct V_16 * V_17 , unsigned V_22 )
{
struct V_4 * V_5 = F_12 ( V_17 ) ;
int V_3 = V_17 -> V_18 - V_5 -> V_14 ;
unsigned long V_6 ;
T_1 V_23 , V_24 , V_25 ;
if ( V_3 < 0 || V_3 >= V_26 )
return - V_9 ;
F_3 ( & V_5 -> V_20 , V_6 ) ;
V_25 = F_4 ( V_5 -> V_11 + V_27 ) ;
V_23 = F_4 ( V_5 -> V_11 + V_28 ) ;
if ( V_22 & ( V_29 | V_30 ) ) {
V_23 |= 1 << V_3 ;
if ( V_22 & V_29 )
V_25 |= 1 << V_3 ;
else
V_25 &= ~ ( 1 << V_3 ) ;
} else
V_23 &= ~ ( 1 << V_3 ) ;
F_5 ( V_23 , V_5 -> V_11 + V_28 ) ;
V_24 = F_4 ( V_5 -> V_11 + V_31 ) ;
if ( ( V_22 & V_32 ) == V_32 )
V_24 |= 1 << V_3 ;
else {
V_24 &= ~ ( 1 << V_3 ) ;
if ( V_22 & V_33 )
V_25 |= 1 << V_3 ;
else if ( V_22 & V_34 )
V_25 &= ~ ( 1 << V_3 ) ;
}
F_5 ( V_24 , V_5 -> V_11 + V_31 ) ;
F_5 ( V_25 , V_5 -> V_11 + V_27 ) ;
F_6 ( & V_5 -> V_20 , V_6 ) ;
return 0 ;
}
static void F_15 ( unsigned V_18 , struct V_35 * V_36 )
{
struct V_37 * V_38 = F_16 ( V_18 ) ;
struct V_37 * V_39 ;
struct V_4 * V_5 ;
V_36 -> V_16 . V_5 -> V_40 ( & V_36 -> V_16 ) ;
F_17 (ptr, chip_list) {
unsigned long V_41 ;
int V_3 ;
V_5 = F_18 ( V_39 , struct V_4 , V_42 ) ;
V_41 = F_4 ( V_5 -> V_11 + V_43 ) ;
F_5 ( V_41 , V_5 -> V_11 + V_44 ) ;
if ( V_41 == 0 )
continue;
F_19 (offset, &pending, PL061_GPIO_NR)
F_20 ( F_10 ( & V_5 -> V_2 , V_3 ) ) ;
}
V_36 -> V_16 . V_5 -> V_45 ( & V_36 -> V_16 ) ;
}
static int F_21 ( struct V_46 * V_47 , const struct V_48 * V_49 )
{
struct V_50 * V_51 ;
struct V_4 * V_5 ;
struct V_37 * V_38 ;
int V_52 , V_18 , V_53 ;
static F_22 ( V_54 , V_55 ) ;
V_5 = F_23 ( sizeof( * V_5 ) , V_56 ) ;
if ( V_5 == NULL )
return - V_57 ;
V_51 = V_47 -> V_47 . V_58 ;
if ( V_51 ) {
V_5 -> V_2 . V_11 = V_51 -> V_59 ;
V_5 -> V_14 = V_51 -> V_14 ;
} else if ( V_47 -> V_47 . V_60 ) {
V_5 -> V_2 . V_11 = - 1 ;
V_5 -> V_14 = V_15 ;
} else {
V_52 = - V_61 ;
goto V_62;
}
if ( ! F_24 ( V_47 -> V_63 . V_64 ,
F_25 ( & V_47 -> V_63 ) , L_1 ) ) {
V_52 = - V_65 ;
goto V_62;
}
V_5 -> V_11 = F_26 ( V_47 -> V_63 . V_64 , F_25 ( & V_47 -> V_63 ) ) ;
if ( V_5 -> V_11 == NULL ) {
V_52 = - V_57 ;
goto V_66;
}
F_27 ( & V_5 -> V_10 ) ;
F_27 ( & V_5 -> V_20 ) ;
F_28 ( & V_5 -> V_42 ) ;
V_5 -> V_2 . V_67 = F_1 ;
V_5 -> V_2 . V_68 = F_7 ;
V_5 -> V_2 . V_69 = F_8 ;
V_5 -> V_2 . V_70 = F_9 ;
V_5 -> V_2 . V_71 = F_10 ;
V_5 -> V_2 . V_8 = V_26 ;
V_5 -> V_2 . V_72 = F_29 ( & V_47 -> V_47 ) ;
V_5 -> V_2 . V_47 = & V_47 -> V_47 ;
V_5 -> V_2 . V_73 = V_74 ;
V_52 = F_30 ( & V_5 -> V_2 ) ;
if ( V_52 )
goto V_75;
if ( V_5 -> V_14 == V_15 )
return 0 ;
F_5 ( 0 , V_5 -> V_11 + V_21 ) ;
V_18 = V_47 -> V_18 [ 0 ] ;
if ( V_18 < 0 ) {
V_52 = - V_61 ;
goto V_75;
}
F_31 ( V_18 , F_15 ) ;
if ( ! F_32 ( V_18 , V_54 ) ) {
V_38 = F_33 ( sizeof( * V_38 ) , V_56 ) ;
if ( V_38 == NULL ) {
F_34 ( V_18 , V_54 ) ;
V_52 = - V_57 ;
goto V_75;
}
F_28 ( V_38 ) ;
F_35 ( V_18 , V_38 ) ;
} else
V_38 = F_16 ( V_18 ) ;
F_36 ( & V_5 -> V_42 , V_38 ) ;
for ( V_53 = 0 ; V_53 < V_26 ; V_53 ++ ) {
if ( V_51 ) {
if ( V_51 -> V_76 & ( 1 << V_53 ) )
F_7 ( & V_5 -> V_2 , V_53 ,
V_51 -> V_77 & ( 1 << V_53 ) ) ;
else
F_1 ( & V_5 -> V_2 , V_53 ) ;
}
F_37 ( V_53 + V_5 -> V_14 , & V_78 ,
V_79 ) ;
F_38 ( V_53 + V_5 -> V_14 , V_80 ) ;
F_39 ( V_53 + V_5 -> V_14 , V_5 ) ;
}
return 0 ;
V_75:
V_75 ( V_5 -> V_11 ) ;
V_66:
F_40 ( V_47 -> V_63 . V_64 , F_25 ( & V_47 -> V_63 ) ) ;
V_62:
F_41 ( V_5 ) ;
return V_52 ;
}
static int T_2 F_42 ( void )
{
return F_43 ( & V_81 ) ;
}
