static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , L_1 ) ;
F_3 ( 0x0 , V_2 -> V_4 + V_5 ) ;
F_4 ( V_2 -> V_4 + V_5 ) ;
F_5 ( 1 ) ;
if ( F_4 ( V_2 -> V_4 + V_6 ) != 0xFFFFFFFF ) {
F_6 ( V_2 -> V_3 , L_2 ) ;
return - V_7 ;
}
return 0 ;
}
static int F_7 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 -> V_13 ;
F_8 ( V_9 ) ;
F_9 ( V_9 ) ;
V_11 -> V_14 ( V_9 ) ;
return 0 ;
}
static unsigned int F_10 ( struct V_15 * V_16 )
{
struct V_8 * V_9 = V_16 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 -> V_13 ;
struct V_1 * V_2 = V_11 -> V_17 ;
int V_18 = 0 ;
if ( F_11 ( V_2 -> V_19 [ V_9 -> V_20 ] == V_21 ) )
F_7 ( V_9 ) ;
V_18 = F_12 ( V_16 ) ;
V_2 -> V_19 [ V_9 -> V_20 ] = V_16 -> V_22 . V_23 ;
return V_18 ;
}
static unsigned int F_13 ( struct V_24 * V_3 ,
struct V_25 * V_22 , T_1 * V_26 )
{
T_2 V_27 ;
V_27 = F_14 ( V_3 , V_22 , V_26 ) ;
if ( V_27 )
return V_27 ;
V_26 [ V_28 ] &= ~ ( 1 << 8 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 , int V_29 )
{
void T_3 * V_30 = V_2 -> V_11 -> V_30 ;
T_2 V_31 ;
F_2 ( V_2 -> V_3 , L_3 ,
V_30 , V_29 ) ;
V_31 = F_4 ( V_30 + V_32 ) ;
V_31 = F_16 ( V_31 , V_29 == 0 ? 2 : 3 ) ;
F_3 ( V_31 , V_30 + V_32 ) ;
F_4 ( V_30 + V_32 ) ;
F_3 ( 0x0001fffe , V_30 + V_33 ) ;
F_4 ( V_30 + V_33 ) ;
F_3 ( 0x5018461c , V_30 + V_34 ) ;
F_4 ( V_30 + V_34 ) ;
F_3 ( 0x1c081907 , V_30 + V_35 ) ;
F_4 ( V_30 + V_35 ) ;
F_3 ( 0x1c080815 , V_30 + V_36 ) ;
F_4 ( V_30 + V_36 ) ;
V_31 = F_4 ( V_30 + V_37 ) ;
V_31 = F_17 ( V_31 , 0x300 ) ;
F_3 ( V_31 , V_30 + V_37 ) ;
F_4 ( V_30 + V_37 ) ;
V_31 = F_4 ( V_30 + V_38 ) ;
V_31 = F_18 ( V_31 , 0x1 ) ;
V_31 = F_19 ( V_31 , 0xe ) ;
F_3 ( V_31 , V_30 + V_38 ) ;
F_4 ( V_30 + V_38 ) ;
}
static int F_20 ( struct V_39 * V_40 ,
unsigned long V_41 , bool * V_42 )
{
const unsigned long * V_43 = F_21 ( & V_40 -> V_44 ) ;
struct V_8 * V_9 = V_40 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 -> V_13 ;
struct V_1 * V_2 = V_11 -> V_17 ;
struct V_45 * V_46 = V_9 -> V_13 ;
T_4 * V_47 = V_46 -> V_48 + V_49 ;
void T_3 * V_50 = F_22 ( V_9 ) ;
struct V_25 V_22 ;
int V_18 ;
T_2 V_31 ;
F_23 ( V_40 -> V_51 , & V_22 ) ;
V_22 . V_23 = V_52 ;
F_24 ( & V_22 , 0 , 0 , V_47 ) ;
V_18 = F_25 ( V_40 , V_43 , V_41 , V_42 ,
V_53 ) ;
V_31 = F_4 ( V_50 + V_54 ) ;
if ( V_31 & ( V_55 | V_56 ) )
F_26 ( V_2 -> V_3 , L_4 ) ;
V_31 = F_4 ( V_50 + V_54 ) ;
F_3 ( V_31 , V_50 + V_54 ) ;
return V_18 ;
}
static int F_27 ( struct V_39 * V_40 , unsigned int * V_57 ,
unsigned long V_41 )
{
struct V_8 * V_9 = V_40 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 -> V_13 ;
void T_3 * V_50 = F_22 ( V_9 ) ;
bool V_42 ;
int V_18 ;
T_2 V_58 ;
T_2 V_59 ;
T_2 V_60 ;
T_2 V_61 ;
T_2 V_62 ;
V_58 = F_4 ( V_50 + V_63 ) ;
V_59 = F_4 ( V_50 + V_64 ) ;
V_60 = F_4 ( V_50 + V_65 ) ;
V_61 = F_4 ( V_50 + V_66 ) ;
V_62 = F_4 ( V_50 + V_67 ) ;
F_8 ( V_9 ) ;
V_18 = F_20 ( V_40 , V_41 , & V_42 ) ;
F_3 ( V_58 , V_50 + V_63 ) ;
F_3 ( V_59 , V_50 + V_64 ) ;
F_3 ( V_60 , V_50 + V_65 ) ;
F_3 ( V_61 , V_50 + V_66 ) ;
F_3 ( V_62 , V_50 + V_67 ) ;
V_11 -> V_14 ( V_9 ) ;
if ( V_42 )
* V_57 = F_28 ( V_9 ) ;
return V_18 ;
}
static void F_29 ( struct V_68 * V_12 )
{
struct V_10 * V_11 = V_12 -> V_13 ;
F_30 ( V_11 ) ;
}
static int F_31 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_17 ;
int V_69 ;
int V_18 ;
T_2 V_31 ;
V_18 = F_1 ( V_2 ) ;
if ( V_18 )
return V_18 ;
for ( V_69 = 0 ; V_69 < V_70 ; V_69 ++ )
F_15 ( V_2 , V_69 ) ;
F_3 ( 0xffffffff , V_11 -> V_30 + V_71 ) ;
F_4 ( V_11 -> V_30 + V_71 ) ;
F_3 ( 0 , V_2 -> V_72 + V_73 ) ;
V_31 = F_4 ( V_2 -> V_72 + V_73 ) ;
F_2 ( V_2 -> V_3 , L_5 ,
V_73 , V_31 ) ;
F_3 ( 0x0 , V_2 -> V_72 + V_74 ) ;
F_4 ( V_2 -> V_72 + V_74 ) ;
F_3 ( 0x0 , V_2 -> V_75 + V_76 ) ;
F_4 ( V_2 -> V_75 + V_76 ) ;
F_3 ( 0xffffffff , V_2 -> V_72 + V_77 ) ;
F_3 ( 0xffffffff , V_2 -> V_72 + V_78 ) ;
F_3 ( 0xffffffff , V_2 -> V_72 + V_79 ) ;
F_3 ( 0xffffffff , V_2 -> V_72 + V_80 ) ;
V_31 = F_4 ( V_2 -> V_72 + V_81 ) ;
V_31 &= ~ 0x00000002 ;
V_31 &= ~ 0x00000001 ;
F_3 ( V_31 , V_2 -> V_72 + V_81 ) ;
V_31 = F_4 ( V_2 -> V_72 + V_82 ) ;
V_31 |= ( 1 << 3 ) ;
V_31 |= ( 1 << 9 ) ;
F_3 ( V_31 , V_2 -> V_72 + V_82 ) ;
V_31 = F_4 ( V_2 -> V_72 + V_82 ) ;
F_2 ( V_2 -> V_3 , L_6 ,
V_82 , V_31 ) ;
return V_18 ;
}
static int F_32 ( struct V_1 * V_2 )
{
T_2 V_31 ;
if ( F_33 ( V_2 -> V_83 ) )
return 0 ;
V_31 = F_4 ( V_2 -> V_83 + V_84 ) ;
V_31 &= ~ V_85 ;
F_3 ( V_31 , V_2 -> V_83 + V_84 ) ;
V_31 = F_4 ( V_2 -> V_83 + V_84 ) ;
return V_31 & V_85 ? - 1 : 0 ;
}
static int F_34 ( struct V_86 * V_87 )
{
struct V_51 * V_3 = & V_87 -> V_3 ;
struct V_10 * V_11 ;
struct V_1 * V_2 ;
struct V_88 * V_89 ;
unsigned long V_90 ;
int V_18 ;
V_11 = F_35 ( V_87 ) ;
if ( F_33 ( V_11 ) )
return F_36 ( V_11 ) ;
V_2 = F_37 ( V_3 , sizeof( * V_2 ) , V_91 ) ;
if ( ! V_2 )
return - V_92 ;
V_11 -> V_17 = V_2 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_3 = V_3 ;
V_89 = F_38 ( V_87 , V_93 , 1 ) ;
V_2 -> V_72 = F_39 ( V_3 , V_89 ) ;
if ( F_33 ( V_2 -> V_72 ) )
return F_36 ( V_2 -> V_72 ) ;
V_89 = F_38 ( V_87 , V_93 , 2 ) ;
V_2 -> V_4 = F_39 ( V_3 , V_89 ) ;
if ( F_33 ( V_2 -> V_4 ) )
return F_36 ( V_2 -> V_4 ) ;
V_89 = F_38 ( V_87 , V_93 , 3 ) ;
V_2 -> V_75 = F_39 ( V_3 , V_89 ) ;
if ( F_33 ( V_2 -> V_75 ) )
return F_36 ( V_2 -> V_75 ) ;
V_89 = F_38 ( V_87 , V_93 , 4 ) ;
V_2 -> V_83 = F_39 ( V_3 , V_89 ) ;
F_2 ( V_3 , L_7 , V_2 -> V_72 ,
V_11 -> V_30 ) ;
if ( ( V_18 = F_32 ( V_2 ) ) ) {
F_6 ( V_3 , L_8 , V_18 ) ;
return - V_7 ;
}
V_18 = F_40 ( V_11 ) ;
if ( V_18 )
goto V_94;
F_41 ( V_11 ) ;
V_18 = F_42 ( V_11 ) ;
if ( V_18 )
goto V_94;
F_31 ( V_11 ) ;
V_18 = F_43 ( V_3 , F_44 ( 64 ) ) ;
if ( V_18 ) {
F_6 ( V_3 , L_9 ) ;
goto V_94;
}
V_90 = V_95 | V_96 ;
V_18 = F_45 ( V_87 , V_11 , & V_97 ,
V_90 , 0 , 0 ) ;
if ( V_18 )
goto V_94;
F_2 ( V_3 , L_10 ) ;
return 0 ;
V_94:
F_30 ( V_11 ) ;
return V_18 ;
}
