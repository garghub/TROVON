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
if ( V_5 -> V_14 == ( unsigned ) - 1 )
return - V_9 ;
return V_5 -> V_14 + V_3 ;
}
static void F_11 ( struct V_15 * V_16 )
{
struct V_4 * V_5 = F_12 ( V_16 ) ;
int V_3 = V_16 -> V_17 - V_5 -> V_14 ;
unsigned long V_6 ;
T_1 V_18 ;
F_3 ( & V_5 -> V_19 , V_6 ) ;
V_18 = F_4 ( V_5 -> V_11 + V_20 ) ;
V_18 &= ~ ( 1 << V_3 ) ;
F_5 ( V_18 , V_5 -> V_11 + V_20 ) ;
F_6 ( & V_5 -> V_19 , V_6 ) ;
}
static void F_13 ( struct V_15 * V_16 )
{
struct V_4 * V_5 = F_12 ( V_16 ) ;
int V_3 = V_16 -> V_17 - V_5 -> V_14 ;
unsigned long V_6 ;
T_1 V_18 ;
F_3 ( & V_5 -> V_19 , V_6 ) ;
V_18 = F_4 ( V_5 -> V_11 + V_20 ) ;
V_18 |= 1 << V_3 ;
F_5 ( V_18 , V_5 -> V_11 + V_20 ) ;
F_6 ( & V_5 -> V_19 , V_6 ) ;
}
static int F_14 ( struct V_15 * V_16 , unsigned V_21 )
{
struct V_4 * V_5 = F_12 ( V_16 ) ;
int V_3 = V_16 -> V_17 - V_5 -> V_14 ;
unsigned long V_6 ;
T_1 V_22 , V_23 , V_24 ;
if ( V_3 < 0 || V_3 >= V_25 )
return - V_9 ;
F_3 ( & V_5 -> V_19 , V_6 ) ;
V_24 = F_4 ( V_5 -> V_11 + V_26 ) ;
V_22 = F_4 ( V_5 -> V_11 + V_27 ) ;
if ( V_21 & ( V_28 | V_29 ) ) {
V_22 |= 1 << V_3 ;
if ( V_21 & V_28 )
V_24 |= 1 << V_3 ;
else
V_24 &= ~ ( 1 << V_3 ) ;
} else
V_22 &= ~ ( 1 << V_3 ) ;
F_5 ( V_22 , V_5 -> V_11 + V_27 ) ;
V_23 = F_4 ( V_5 -> V_11 + V_30 ) ;
if ( ( V_21 & V_31 ) == V_31 )
V_23 |= 1 << V_3 ;
else {
V_23 &= ~ ( 1 << V_3 ) ;
if ( V_21 & V_32 )
V_24 |= 1 << V_3 ;
else if ( V_21 & V_33 )
V_24 &= ~ ( 1 << V_3 ) ;
}
F_5 ( V_23 , V_5 -> V_11 + V_30 ) ;
F_5 ( V_24 , V_5 -> V_11 + V_26 ) ;
F_6 ( & V_5 -> V_19 , V_6 ) ;
return 0 ;
}
static void F_15 ( unsigned V_17 , struct V_34 * V_35 )
{
struct V_36 * V_37 = F_16 ( V_17 ) ;
struct V_36 * V_38 ;
struct V_4 * V_5 ;
V_35 -> V_15 . V_5 -> V_39 ( & V_35 -> V_15 ) ;
F_17 (ptr, chip_list) {
unsigned long V_40 ;
int V_3 ;
V_5 = F_18 ( V_38 , struct V_4 , V_41 ) ;
V_40 = F_4 ( V_5 -> V_11 + V_42 ) ;
F_5 ( V_40 , V_5 -> V_11 + V_43 ) ;
if ( V_40 == 0 )
continue;
F_19 (offset, &pending, PL061_GPIO_NR)
F_20 ( F_10 ( & V_5 -> V_2 , V_3 ) ) ;
}
V_35 -> V_15 . V_5 -> V_44 ( & V_35 -> V_15 ) ;
}
static int F_21 ( struct V_45 * V_46 , const struct V_47 * V_48 )
{
struct V_49 * V_50 ;
struct V_4 * V_5 ;
struct V_36 * V_37 ;
int V_51 , V_17 , V_52 ;
static F_22 ( V_53 , V_54 ) ;
V_50 = V_46 -> V_46 . V_55 ;
if ( V_50 == NULL )
return - V_56 ;
V_5 = F_23 ( sizeof( * V_5 ) , V_57 ) ;
if ( V_5 == NULL )
return - V_58 ;
if ( ! F_24 ( V_46 -> V_59 . V_60 ,
F_25 ( & V_46 -> V_59 ) , L_1 ) ) {
V_51 = - V_61 ;
goto V_62;
}
V_5 -> V_11 = F_26 ( V_46 -> V_59 . V_60 , F_25 ( & V_46 -> V_59 ) ) ;
if ( V_5 -> V_11 == NULL ) {
V_51 = - V_58 ;
goto V_63;
}
F_27 ( & V_5 -> V_10 ) ;
F_27 ( & V_5 -> V_19 ) ;
F_28 ( & V_5 -> V_41 ) ;
V_5 -> V_2 . V_64 = F_1 ;
V_5 -> V_2 . V_65 = F_7 ;
V_5 -> V_2 . V_66 = F_8 ;
V_5 -> V_2 . V_67 = F_9 ;
V_5 -> V_2 . V_68 = F_10 ;
V_5 -> V_2 . V_11 = V_50 -> V_69 ;
V_5 -> V_2 . V_8 = V_25 ;
V_5 -> V_2 . V_70 = F_29 ( & V_46 -> V_46 ) ;
V_5 -> V_2 . V_46 = & V_46 -> V_46 ;
V_5 -> V_2 . V_71 = V_72 ;
V_5 -> V_14 = V_50 -> V_14 ;
V_51 = F_30 ( & V_5 -> V_2 ) ;
if ( V_51 )
goto V_73;
if ( V_5 -> V_14 == ( unsigned ) - 1 )
return 0 ;
F_5 ( 0 , V_5 -> V_11 + V_20 ) ;
V_17 = V_46 -> V_17 [ 0 ] ;
if ( V_17 < 0 ) {
V_51 = - V_56 ;
goto V_73;
}
F_31 ( V_17 , F_15 ) ;
if ( ! F_32 ( V_17 , V_53 ) ) {
V_37 = F_33 ( sizeof( * V_37 ) , V_57 ) ;
if ( V_37 == NULL ) {
F_34 ( V_17 , V_53 ) ;
V_51 = - V_58 ;
goto V_73;
}
F_28 ( V_37 ) ;
F_35 ( V_17 , V_37 ) ;
} else
V_37 = F_16 ( V_17 ) ;
F_36 ( & V_5 -> V_41 , V_37 ) ;
for ( V_52 = 0 ; V_52 < V_25 ; V_52 ++ ) {
if ( V_50 -> V_74 & ( 1 << V_52 ) )
F_7 ( & V_5 -> V_2 , V_52 ,
V_50 -> V_75 & ( 1 << V_52 ) ) ;
else
F_1 ( & V_5 -> V_2 , V_52 ) ;
F_37 ( V_52 + V_5 -> V_14 , & V_76 ,
V_77 ) ;
F_38 ( V_52 + V_5 -> V_14 , V_78 ) ;
F_39 ( V_52 + V_5 -> V_14 , V_5 ) ;
}
return 0 ;
V_73:
V_73 ( V_5 -> V_11 ) ;
V_63:
F_40 ( V_46 -> V_59 . V_60 , F_25 ( & V_46 -> V_59 ) ) ;
V_62:
F_41 ( V_5 ) ;
return V_51 ;
}
static int T_2 F_42 ( void )
{
return F_43 ( & V_79 ) ;
}
