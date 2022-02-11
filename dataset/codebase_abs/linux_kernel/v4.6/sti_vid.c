static void F_1 ( struct V_1 * V_2 , int V_3 )
{
V_3 = V_3 >> 30 ;
F_2 ( V_2 , L_1 ) ;
if ( ! ( V_3 & 1 ) )
F_2 ( V_2 , L_2 ) ;
F_2 ( V_2 , L_3 ) ;
if ( ! ( V_3 & 2 ) )
F_2 ( V_2 , L_2 ) ;
F_2 ( V_2 , L_4 ) ;
}
static void F_3 ( struct V_1 * V_2 , int V_3 )
{
F_4 ( V_2 , L_5 , V_3 & 0x0FFF , ( V_3 >> 16 ) & 0x0FFF ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_3 )
{
F_4 ( V_2 , L_6 , V_3 & 0x0FFF , ( V_3 >> 16 ) & 0x0FFF ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 & 1 )
F_2 ( V_2 , L_7 ) ;
}
static int F_7 ( struct V_1 * V_2 , void * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = (struct V_8 * ) V_6 -> V_10 -> V_11 ;
struct V_12 * V_13 = V_6 -> V_14 -> V_13 ;
int V_15 ;
V_15 = F_8 ( & V_13 -> V_16 ) ;
if ( V_15 )
return V_15 ;
F_4 ( V_2 , L_8 , V_9 -> V_17 ) ;
F_9 ( V_18 ) ;
F_1 ( V_2 , F_10 ( V_9 -> V_17 + V_18 ) ) ;
F_9 ( V_19 ) ;
F_9 ( V_20 ) ;
F_9 ( V_21 ) ;
F_3 ( V_2 , F_10 ( V_9 -> V_17 + V_21 ) ) ;
F_9 ( V_22 ) ;
F_5 ( V_2 , F_10 ( V_9 -> V_17 + V_22 ) ) ;
F_9 ( V_23 ) ;
F_9 ( V_24 ) ;
F_9 ( V_25 ) ;
F_9 ( V_26 ) ;
F_9 ( V_27 ) ;
F_9 ( V_28 ) ;
F_9 ( V_29 ) ;
F_6 ( V_2 , F_10 ( V_9 -> V_17 + V_29 ) ) ;
F_9 ( V_30 ) ;
F_9 ( V_31 ) ;
F_9 ( V_32 ) ;
F_2 ( V_2 , L_9 ) ;
F_11 ( & V_13 -> V_16 ) ;
return 0 ;
}
static int F_12 ( struct V_8 * V_9 , struct V_33 * V_14 )
{
unsigned int V_34 ;
for ( V_34 = 0 ; V_34 < F_13 ( V_35 ) ; V_34 ++ )
V_35 [ V_34 ] . V_11 = V_9 ;
return F_14 ( V_35 ,
F_13 ( V_35 ) ,
V_14 -> V_36 , V_14 ) ;
}
void F_15 ( struct V_8 * V_9 ,
struct V_37 * V_38 )
{
struct V_39 * V_40 = V_38 -> V_40 ;
struct V_41 * V_42 = & V_40 -> V_42 ;
int V_43 = V_38 -> V_44 ;
int V_45 = V_38 -> V_46 ;
int V_47 = F_16 ( V_38 -> V_48 , 0 , V_42 -> V_49 - V_43 ) ;
int V_50 = F_16 ( V_38 -> V_51 , 0 , V_42 -> V_52 - V_45 ) ;
int V_53 = V_38 -> V_53 >> 16 ;
T_1 V_3 , V_54 , V_55 , V_56 , V_57 ;
V_47 = F_17 ( V_47 , 2 ) ;
V_50 = F_17 ( V_50 , 2 ) ;
V_3 = F_10 ( V_9 -> V_17 + V_18 ) ;
V_3 &= ~ V_58 ;
F_18 ( V_3 , V_9 -> V_17 + V_18 ) ;
V_54 = F_19 ( * V_42 , V_45 ) ;
V_56 = F_19 ( * V_42 , V_45 + V_50 - 1 ) ;
V_55 = F_20 ( * V_42 , V_43 ) ;
V_57 = F_20 ( * V_42 , V_43 + V_47 - 1 ) ;
F_18 ( ( V_54 << 16 ) | V_55 , V_9 -> V_17 + V_21 ) ;
F_18 ( ( V_56 << 16 ) | V_57 , V_9 -> V_17 + V_22 ) ;
if ( V_53 >= V_59 ) {
F_18 ( V_60 , V_9 -> V_17 + V_25 ) ;
F_18 ( V_61 , V_9 -> V_17 + V_26 ) ;
F_18 ( V_62 , V_9 -> V_17 + V_27 ) ;
F_18 ( V_63 , V_9 -> V_17 + V_28 ) ;
} else {
F_18 ( V_64 , V_9 -> V_17 + V_25 ) ;
F_18 ( V_65 , V_9 -> V_17 + V_26 ) ;
F_18 ( V_66 , V_9 -> V_17 + V_27 ) ;
F_18 ( V_67 , V_9 -> V_17 + V_28 ) ;
}
}
void F_21 ( struct V_8 * V_9 )
{
T_1 V_3 ;
V_3 = F_10 ( V_9 -> V_17 + V_18 ) ;
V_3 |= V_58 ;
F_18 ( V_3 , V_9 -> V_17 + V_18 ) ;
}
static void F_22 ( struct V_8 * V_9 )
{
F_18 ( V_68 | V_58 , V_9 -> V_17 + V_18 ) ;
F_18 ( V_69 , V_9 -> V_17 + V_19 ) ;
F_18 ( V_70 , V_9 -> V_17 + V_30 ) ;
F_18 ( V_71 , V_9 -> V_17 + V_31 ) ;
F_18 ( V_72 , V_9 -> V_17 + V_32 ) ;
}
struct V_8 * F_23 ( struct V_73 * V_13 , struct V_12 * V_74 ,
int V_75 , void T_2 * V_76 )
{
struct V_8 * V_9 ;
V_9 = F_24 ( V_13 , sizeof( * V_9 ) , V_77 ) ;
if ( ! V_9 ) {
F_25 ( L_10 ) ;
return NULL ;
}
V_9 -> V_13 = V_13 ;
V_9 -> V_17 = V_76 ;
V_9 -> V_75 = V_75 ;
F_22 ( V_9 ) ;
if ( F_12 ( V_9 , V_74 -> V_78 ) )
F_25 ( L_11 ) ;
return V_9 ;
}
