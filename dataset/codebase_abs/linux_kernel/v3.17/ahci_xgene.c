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
static bool F_13 ( struct V_1 * V_2 )
{
void T_1 * V_24 = V_2 -> V_4 ;
return ( F_4 ( V_24 + V_5 ) == 0 &&
F_4 ( V_24 + V_6 ) == 0xFFFFFFFF ) ;
}
static unsigned int F_14 ( struct V_25 * V_3 ,
struct V_26 * V_22 , T_2 * V_27 )
{
T_3 V_28 ;
V_28 = F_15 ( V_3 , V_22 , V_27 ) ;
if ( V_28 )
return V_28 ;
V_27 [ V_29 ] &= ~ ( 1 << 8 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 , int V_30 )
{
void T_1 * V_31 = V_2 -> V_11 -> V_31 ;
T_3 V_32 ;
F_2 ( V_2 -> V_3 , L_3 ,
V_31 , V_30 ) ;
V_32 = F_4 ( V_31 + V_33 ) ;
V_32 = F_17 ( V_32 , V_30 == 0 ? 2 : 3 ) ;
F_3 ( V_32 , V_31 + V_33 ) ;
F_4 ( V_31 + V_33 ) ;
F_3 ( 0x0001fffe , V_31 + V_34 ) ;
F_4 ( V_31 + V_34 ) ;
F_3 ( 0x28183219 , V_31 + V_35 ) ;
F_4 ( V_31 + V_35 ) ;
F_3 ( 0x13081008 , V_31 + V_36 ) ;
F_4 ( V_31 + V_36 ) ;
F_3 ( 0x00480815 , V_31 + V_37 ) ;
F_4 ( V_31 + V_37 ) ;
V_32 = F_4 ( V_31 + V_38 ) ;
V_32 = F_18 ( V_32 , 0x300 ) ;
F_3 ( V_32 , V_31 + V_38 ) ;
F_4 ( V_31 + V_38 ) ;
V_32 = F_4 ( V_31 + V_39 ) ;
V_32 = F_19 ( V_32 , 0x1 ) ;
V_32 = F_20 ( V_32 , 0xe ) ;
F_3 ( V_32 , V_31 + V_39 ) ;
F_4 ( V_31 + V_39 ) ;
V_32 = F_4 ( V_31 + V_40 ) ;
V_32 = F_21 ( V_32 , 0x30 ) ;
F_3 ( V_32 , V_31 + V_40 ) ;
}
static int F_22 ( struct V_41 * V_42 ,
unsigned long V_43 , bool * V_44 )
{
const unsigned long * V_45 = F_23 ( & V_42 -> V_46 ) ;
struct V_8 * V_9 = V_42 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 -> V_13 ;
struct V_1 * V_2 = V_11 -> V_17 ;
struct V_47 * V_48 = V_9 -> V_13 ;
T_4 * V_49 = V_48 -> V_50 + V_51 ;
void T_1 * V_52 = F_24 ( V_9 ) ;
struct V_26 V_22 ;
int V_53 = 0 ;
int V_18 ;
T_3 V_32 , V_54 ;
do {
F_25 ( V_42 -> V_55 , & V_22 ) ;
V_22 . V_23 = V_56 ;
F_26 ( & V_22 , 0 , 0 , V_49 ) ;
V_18 = F_27 ( V_42 , V_45 , V_43 , V_44 ,
V_57 ) ;
if ( * V_44 ) {
V_32 = F_4 ( V_52 + V_58 ) ;
if ( V_32 & ( V_59 | V_60 ) )
F_28 ( V_2 -> V_3 , L_4 ) ;
break;
}
F_29 ( V_42 , V_61 , & V_54 ) ;
} while ( V_53 ++ < V_62 &&
( V_54 & 0xff ) == 0x1 );
V_32 = F_4 ( V_52 + V_58 ) ;
F_3 ( V_32 , V_52 + V_58 ) ;
return V_18 ;
}
static int F_30 ( struct V_41 * V_42 , unsigned int * V_63 ,
unsigned long V_43 )
{
struct V_8 * V_9 = V_42 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 -> V_13 ;
void T_1 * V_52 = F_24 ( V_9 ) ;
bool V_44 ;
int V_18 ;
T_3 V_64 ;
T_3 V_65 ;
T_3 V_66 ;
T_3 V_67 ;
T_3 V_68 ;
V_64 = F_4 ( V_52 + V_69 ) ;
V_65 = F_4 ( V_52 + V_70 ) ;
V_66 = F_4 ( V_52 + V_71 ) ;
V_67 = F_4 ( V_52 + V_72 ) ;
V_68 = F_4 ( V_52 + V_73 ) ;
F_8 ( V_9 ) ;
V_18 = F_22 ( V_42 , V_43 , & V_44 ) ;
F_3 ( V_64 , V_52 + V_69 ) ;
F_3 ( V_65 , V_52 + V_70 ) ;
F_3 ( V_66 , V_52 + V_71 ) ;
F_3 ( V_67 , V_52 + V_72 ) ;
F_3 ( V_68 , V_52 + V_73 ) ;
V_11 -> V_14 ( V_9 ) ;
if ( V_44 )
* V_63 = F_31 ( V_9 ) ;
return V_18 ;
}
static void F_32 ( struct V_74 * V_12 )
{
struct V_10 * V_11 = V_12 -> V_13 ;
F_33 ( V_11 ) ;
}
static int F_34 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_17 ;
int V_75 ;
int V_18 ;
T_3 V_32 ;
V_18 = F_1 ( V_2 ) ;
if ( V_18 )
return V_18 ;
for ( V_75 = 0 ; V_75 < V_76 ; V_75 ++ )
F_16 ( V_2 , V_75 ) ;
F_3 ( 0xffffffff , V_11 -> V_31 + V_77 ) ;
F_4 ( V_11 -> V_31 + V_77 ) ;
F_3 ( 0 , V_2 -> V_78 + V_79 ) ;
V_32 = F_4 ( V_2 -> V_78 + V_79 ) ;
F_2 ( V_2 -> V_3 , L_5 ,
V_79 , V_32 ) ;
F_3 ( 0x0 , V_2 -> V_78 + V_80 ) ;
F_4 ( V_2 -> V_78 + V_80 ) ;
F_3 ( 0x0 , V_2 -> V_81 + V_82 ) ;
F_4 ( V_2 -> V_81 + V_82 ) ;
F_3 ( 0xffffffff , V_2 -> V_78 + V_83 ) ;
F_3 ( 0xffffffff , V_2 -> V_78 + V_84 ) ;
F_3 ( 0xffffffff , V_2 -> V_78 + V_85 ) ;
F_3 ( 0xffffffff , V_2 -> V_78 + V_86 ) ;
V_32 = F_4 ( V_2 -> V_78 + V_87 ) ;
V_32 &= ~ 0x00000002 ;
V_32 &= ~ 0x00000001 ;
F_3 ( V_32 , V_2 -> V_78 + V_87 ) ;
V_32 = F_4 ( V_2 -> V_78 + V_88 ) ;
V_32 |= ( 1 << 3 ) ;
V_32 |= ( 1 << 9 ) ;
F_3 ( V_32 , V_2 -> V_78 + V_88 ) ;
V_32 = F_4 ( V_2 -> V_78 + V_88 ) ;
F_2 ( V_2 -> V_3 , L_6 ,
V_88 , V_32 ) ;
return V_18 ;
}
static int F_35 ( struct V_1 * V_2 )
{
T_3 V_32 ;
if ( F_36 ( V_2 -> V_89 ) )
return 0 ;
V_32 = F_4 ( V_2 -> V_89 + V_90 ) ;
V_32 &= ~ V_91 ;
F_3 ( V_32 , V_2 -> V_89 + V_90 ) ;
V_32 = F_4 ( V_2 -> V_89 + V_90 ) ;
return V_32 & V_91 ? - 1 : 0 ;
}
static int F_37 ( struct V_92 * V_93 )
{
struct V_55 * V_3 = & V_93 -> V_3 ;
struct V_10 * V_11 ;
struct V_1 * V_2 ;
struct V_94 * V_95 ;
int V_18 ;
V_11 = F_38 ( V_93 ) ;
if ( F_36 ( V_11 ) )
return F_39 ( V_11 ) ;
V_2 = F_40 ( V_3 , sizeof( * V_2 ) , V_96 ) ;
if ( ! V_2 )
return - V_97 ;
V_11 -> V_17 = V_2 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_3 = V_3 ;
V_95 = F_41 ( V_93 , V_98 , 1 ) ;
V_2 -> V_78 = F_42 ( V_3 , V_95 ) ;
if ( F_36 ( V_2 -> V_78 ) )
return F_39 ( V_2 -> V_78 ) ;
V_95 = F_41 ( V_93 , V_98 , 2 ) ;
V_2 -> V_4 = F_42 ( V_3 , V_95 ) ;
if ( F_36 ( V_2 -> V_4 ) )
return F_39 ( V_2 -> V_4 ) ;
V_95 = F_41 ( V_93 , V_98 , 3 ) ;
V_2 -> V_81 = F_42 ( V_3 , V_95 ) ;
if ( F_36 ( V_2 -> V_81 ) )
return F_39 ( V_2 -> V_81 ) ;
V_95 = F_41 ( V_93 , V_98 , 4 ) ;
V_2 -> V_89 = F_42 ( V_3 , V_95 ) ;
F_2 ( V_3 , L_7 , V_2 -> V_78 ,
V_11 -> V_31 ) ;
if ( ( V_18 = F_35 ( V_2 ) ) ) {
F_6 ( V_3 , L_8 , V_18 ) ;
return - V_7 ;
}
if ( F_13 ( V_2 ) ) {
F_43 ( V_3 , L_9 ) ;
goto V_99;
}
V_18 = F_44 ( V_11 ) ;
if ( V_18 )
goto V_100;
F_45 ( V_11 ) ;
V_18 = F_46 ( V_11 ) ;
if ( V_18 )
goto V_100;
F_34 ( V_11 ) ;
V_99:
V_11 -> V_101 = V_102 | V_103 ;
V_18 = F_47 ( V_93 , V_11 , & V_104 ) ;
if ( V_18 )
goto V_100;
F_2 ( V_3 , L_10 ) ;
return 0 ;
V_100:
F_33 ( V_11 ) ;
return V_18 ;
}
