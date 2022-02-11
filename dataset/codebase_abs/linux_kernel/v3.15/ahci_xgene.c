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
static unsigned int F_7 ( struct V_8 * V_3 ,
struct V_9 * V_10 , T_1 * V_11 )
{
T_2 V_12 ;
void T_3 * V_13 = F_8 ( V_3 -> V_14 -> V_15 ) ;
V_12 = F_9 ( V_3 , V_10 , V_11 ) ;
if ( V_12 )
return V_12 ;
V_11 [ V_16 ] &= ~ ( 1 << 8 ) ;
if ( ! F_4 ( V_13 + V_17 ) ) {
F_3 ( V_18 , V_13 + V_19 ) ;
F_4 ( V_13 + V_19 ) ;
F_3 ( V_18 | V_20 , V_13 + V_19 ) ;
F_4 ( V_13 + V_19 ) ;
}
return 0 ;
}
static void F_10 ( struct V_1 * V_2 , int V_21 )
{
void T_3 * V_22 = V_2 -> V_23 -> V_22 ;
T_2 V_24 ;
F_2 ( V_2 -> V_3 , L_3 ,
V_22 , V_21 ) ;
V_24 = F_4 ( V_22 + V_25 ) ;
V_24 = F_11 ( V_24 , V_21 == 0 ? 2 : 3 ) ;
F_3 ( V_24 , V_22 + V_25 ) ;
F_4 ( V_22 + V_25 ) ;
F_3 ( 0x0001fffe , V_22 + V_26 ) ;
F_4 ( V_22 + V_26 ) ;
F_3 ( 0x5018461c , V_22 + V_27 ) ;
F_4 ( V_22 + V_27 ) ;
F_3 ( 0x1c081907 , V_22 + V_28 ) ;
F_4 ( V_22 + V_28 ) ;
F_3 ( 0x1c080815 , V_22 + V_29 ) ;
F_4 ( V_22 + V_29 ) ;
V_24 = F_4 ( V_22 + V_30 ) ;
V_24 = F_12 ( V_24 , 0x300 ) ;
F_3 ( V_24 , V_22 + V_30 ) ;
F_4 ( V_22 + V_30 ) ;
V_24 = F_4 ( V_22 + V_31 ) ;
V_24 = F_13 ( V_24 , 0x1 ) ;
V_24 = F_14 ( V_24 , 0xe ) ;
F_3 ( V_24 , V_22 + V_31 ) ;
F_4 ( V_22 + V_31 ) ;
}
static int F_15 ( struct V_32 * V_14 ,
unsigned long V_33 , bool * V_34 )
{
const unsigned long * V_35 = F_16 ( & V_14 -> V_36 ) ;
struct V_37 * V_15 = V_14 -> V_15 ;
struct V_38 * V_23 = V_15 -> V_39 -> V_40 ;
struct V_1 * V_2 = V_23 -> V_41 ;
struct V_42 * V_43 = V_15 -> V_40 ;
T_4 * V_44 = V_43 -> V_45 + V_46 ;
void T_3 * V_13 = F_8 ( V_15 ) ;
struct V_9 V_10 ;
int V_47 ;
T_2 V_24 ;
F_17 ( V_14 -> V_48 , & V_10 ) ;
V_10 . V_49 = V_50 ;
F_18 ( & V_10 , 0 , 0 , V_44 ) ;
V_47 = F_19 ( V_14 , V_35 , V_33 , V_34 ,
V_51 ) ;
V_24 = F_4 ( V_13 + V_52 ) ;
if ( V_24 & ( V_53 | V_54 ) )
F_20 ( V_2 -> V_3 , L_4 ) ;
V_24 = F_4 ( V_13 + V_52 ) ;
F_3 ( V_24 , V_13 + V_52 ) ;
return V_47 ;
}
static int F_21 ( struct V_32 * V_14 , unsigned int * V_55 ,
unsigned long V_33 )
{
struct V_37 * V_15 = V_14 -> V_15 ;
struct V_38 * V_23 = V_15 -> V_39 -> V_40 ;
void T_3 * V_13 = F_8 ( V_15 ) ;
bool V_34 ;
int V_47 ;
T_2 V_56 ;
T_2 V_57 ;
T_2 V_58 ;
T_2 V_59 ;
T_2 V_60 ;
V_56 = F_4 ( V_13 + V_19 ) ;
V_57 = F_4 ( V_13 + V_61 ) ;
V_58 = F_4 ( V_13 + V_62 ) ;
V_59 = F_4 ( V_13 + V_63 ) ;
V_60 = F_4 ( V_13 + V_64 ) ;
F_22 ( V_15 ) ;
V_47 = F_15 ( V_14 , V_33 , & V_34 ) ;
F_3 ( V_56 , V_13 + V_19 ) ;
F_3 ( V_57 , V_13 + V_61 ) ;
F_3 ( V_58 , V_13 + V_62 ) ;
F_3 ( V_59 , V_13 + V_63 ) ;
F_3 ( V_60 , V_13 + V_64 ) ;
V_23 -> V_65 ( V_15 ) ;
if ( V_34 )
* V_55 = F_23 ( V_15 ) ;
return V_47 ;
}
static void F_24 ( struct V_66 * V_39 )
{
struct V_38 * V_23 = V_39 -> V_40 ;
F_25 ( V_23 ) ;
}
static int F_26 ( struct V_38 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_41 ;
int V_67 ;
int V_47 ;
T_2 V_24 ;
V_47 = F_1 ( V_2 ) ;
if ( V_47 )
return V_47 ;
for ( V_67 = 0 ; V_67 < V_68 ; V_67 ++ )
F_10 ( V_2 , V_67 ) ;
F_3 ( 0xffffffff , V_23 -> V_22 + V_69 ) ;
F_4 ( V_23 -> V_22 + V_69 ) ;
F_3 ( 0 , V_2 -> V_70 + V_71 ) ;
V_24 = F_4 ( V_2 -> V_70 + V_71 ) ;
F_2 ( V_2 -> V_3 , L_5 ,
V_71 , V_24 ) ;
F_3 ( 0x0 , V_2 -> V_70 + V_72 ) ;
F_4 ( V_2 -> V_70 + V_72 ) ;
F_3 ( 0x0 , V_2 -> V_73 + V_74 ) ;
F_4 ( V_2 -> V_73 + V_74 ) ;
F_3 ( 0xffffffff , V_2 -> V_70 + V_75 ) ;
F_3 ( 0xffffffff , V_2 -> V_70 + V_76 ) ;
F_3 ( 0xffffffff , V_2 -> V_70 + V_77 ) ;
F_3 ( 0xffffffff , V_2 -> V_70 + V_78 ) ;
V_24 = F_4 ( V_2 -> V_70 + V_79 ) ;
V_24 &= ~ 0x00000002 ;
V_24 &= ~ 0x00000001 ;
F_3 ( V_24 , V_2 -> V_70 + V_79 ) ;
V_24 = F_4 ( V_2 -> V_70 + V_80 ) ;
V_24 |= ( 1 << 3 ) ;
V_24 |= ( 1 << 9 ) ;
F_3 ( V_24 , V_2 -> V_70 + V_80 ) ;
V_24 = F_4 ( V_2 -> V_70 + V_80 ) ;
F_2 ( V_2 -> V_3 , L_6 ,
V_80 , V_24 ) ;
return V_47 ;
}
static int F_27 ( struct V_1 * V_2 )
{
T_2 V_24 ;
if ( F_28 ( V_2 -> V_81 ) )
return 0 ;
V_24 = F_4 ( V_2 -> V_81 + V_82 ) ;
V_24 &= ~ V_83 ;
F_3 ( V_24 , V_2 -> V_81 + V_82 ) ;
V_24 = F_4 ( V_2 -> V_81 + V_82 ) ;
return V_24 & V_83 ? - 1 : 0 ;
}
static int F_29 ( struct V_84 * V_85 )
{
struct V_48 * V_3 = & V_85 -> V_3 ;
struct V_38 * V_23 ;
struct V_1 * V_2 ;
struct V_86 * V_87 ;
int V_47 ;
V_23 = F_30 ( V_85 ) ;
if ( F_28 ( V_23 ) )
return F_31 ( V_23 ) ;
V_2 = F_32 ( V_3 , sizeof( * V_2 ) , V_88 ) ;
if ( ! V_2 )
return - V_89 ;
V_23 -> V_41 = V_2 ;
V_2 -> V_23 = V_23 ;
V_2 -> V_3 = V_3 ;
V_87 = F_33 ( V_85 , V_90 , 1 ) ;
V_2 -> V_70 = F_34 ( V_3 , V_87 ) ;
if ( F_28 ( V_2 -> V_70 ) )
return F_31 ( V_2 -> V_70 ) ;
V_87 = F_33 ( V_85 , V_90 , 2 ) ;
V_2 -> V_4 = F_34 ( V_3 , V_87 ) ;
if ( F_28 ( V_2 -> V_4 ) )
return F_31 ( V_2 -> V_4 ) ;
V_87 = F_33 ( V_85 , V_90 , 3 ) ;
V_2 -> V_73 = F_34 ( V_3 , V_87 ) ;
if ( F_28 ( V_2 -> V_73 ) )
return F_31 ( V_2 -> V_73 ) ;
V_87 = F_33 ( V_85 , V_90 , 4 ) ;
V_2 -> V_81 = F_34 ( V_3 , V_87 ) ;
F_2 ( V_3 , L_7 , V_2 -> V_70 ,
V_23 -> V_22 ) ;
if ( ( V_47 = F_27 ( V_2 ) ) ) {
F_6 ( V_3 , L_8 , V_47 ) ;
return - V_7 ;
}
V_47 = F_35 ( V_23 ) ;
if ( V_47 )
goto V_91;
F_36 ( V_23 ) ;
V_47 = F_37 ( V_23 ) ;
if ( V_47 )
goto V_91;
F_26 ( V_23 ) ;
V_47 = F_38 ( V_3 , F_39 ( 64 ) ) ;
if ( V_47 ) {
F_6 ( V_3 , L_9 ) ;
goto V_91;
}
V_47 = F_40 ( V_85 , V_23 , & V_92 , 0 , 0 ) ;
if ( V_47 )
goto V_91;
F_2 ( V_3 , L_10 ) ;
return 0 ;
V_91:
F_25 ( V_23 ) ;
return V_47 ;
}
