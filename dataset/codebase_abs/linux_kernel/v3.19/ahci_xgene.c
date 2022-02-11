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
if ( F_11 ( ( V_2 -> V_19 [ V_9 -> V_20 ] == V_21 ) ||
( V_2 -> V_19 [ V_9 -> V_20 ] == V_22 ) ) )
F_7 ( V_9 ) ;
V_18 = F_12 ( V_16 ) ;
V_2 -> V_19 [ V_9 -> V_20 ] = V_16 -> V_23 . V_24 ;
return V_18 ;
}
static bool F_13 ( struct V_1 * V_2 )
{
void T_1 * V_25 = V_2 -> V_4 ;
return ( F_4 ( V_25 + V_5 ) == 0 &&
F_4 ( V_25 + V_6 ) == 0xFFFFFFFF ) ;
}
static unsigned int F_14 ( struct V_26 * V_3 ,
struct V_27 * V_23 , T_2 * V_28 )
{
T_3 V_29 ;
V_29 = F_15 ( V_3 , V_23 , V_28 ) ;
if ( V_29 )
return V_29 ;
V_28 [ V_30 ] &= F_16 ( ~ ( 1 << 8 ) ) ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 , int V_31 )
{
void T_1 * V_32 = V_2 -> V_11 -> V_32 ;
T_3 V_33 ;
F_2 ( V_2 -> V_3 , L_3 ,
V_32 , V_31 ) ;
V_33 = F_4 ( V_32 + V_34 ) ;
V_33 = F_18 ( V_33 , V_31 == 0 ? 2 : 3 ) ;
F_3 ( V_33 , V_32 + V_34 ) ;
F_4 ( V_32 + V_34 ) ;
F_3 ( 0x0001fffe , V_32 + V_35 ) ;
F_4 ( V_32 + V_35 ) ;
F_3 ( 0x28183219 , V_32 + V_36 ) ;
F_4 ( V_32 + V_36 ) ;
F_3 ( 0x13081008 , V_32 + V_37 ) ;
F_4 ( V_32 + V_37 ) ;
F_3 ( 0x00480815 , V_32 + V_38 ) ;
F_4 ( V_32 + V_38 ) ;
V_33 = F_4 ( V_32 + V_39 ) ;
V_33 = F_19 ( V_33 , 0x300 ) ;
F_3 ( V_33 , V_32 + V_39 ) ;
F_4 ( V_32 + V_39 ) ;
V_33 = F_4 ( V_32 + V_40 ) ;
V_33 = F_20 ( V_33 , 0x1 ) ;
V_33 = F_21 ( V_33 , 0xe ) ;
F_3 ( V_33 , V_32 + V_40 ) ;
F_4 ( V_32 + V_40 ) ;
V_33 = F_4 ( V_32 + V_41 ) ;
V_33 = F_22 ( V_33 , 0x30 ) ;
F_3 ( V_33 , V_32 + V_41 ) ;
}
static int F_23 ( struct V_42 * V_43 ,
unsigned long V_44 , bool * V_45 )
{
const unsigned long * V_46 = F_24 ( & V_43 -> V_47 ) ;
struct V_8 * V_9 = V_43 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 -> V_13 ;
struct V_1 * V_2 = V_11 -> V_17 ;
struct V_48 * V_49 = V_9 -> V_13 ;
T_4 * V_50 = V_49 -> V_51 + V_52 ;
void T_1 * V_53 = F_25 ( V_9 ) ;
struct V_27 V_23 ;
int V_54 = 0 ;
int V_18 ;
T_3 V_33 , V_55 ;
do {
F_26 ( V_43 -> V_56 , & V_23 ) ;
V_23 . V_24 = V_57 ;
F_27 ( & V_23 , 0 , 0 , V_50 ) ;
V_18 = F_28 ( V_43 , V_46 , V_44 , V_45 ,
V_58 ) ;
if ( * V_45 ) {
V_33 = F_4 ( V_53 + V_59 ) ;
if ( V_33 & ( V_60 | V_61 ) )
F_29 ( V_2 -> V_3 , L_4 ) ;
break;
}
F_30 ( V_43 , V_62 , & V_55 ) ;
} while ( V_54 ++ < V_63 &&
( V_55 & 0xff ) == 0x1 );
V_33 = F_4 ( V_53 + V_59 ) ;
F_3 ( V_33 , V_53 + V_59 ) ;
return V_18 ;
}
static int F_31 ( struct V_42 * V_43 , unsigned int * V_64 ,
unsigned long V_44 )
{
struct V_8 * V_9 = V_43 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 -> V_13 ;
void T_1 * V_53 = F_25 ( V_9 ) ;
bool V_45 ;
int V_18 ;
T_3 V_65 ;
T_3 V_66 ;
T_3 V_67 ;
T_3 V_68 ;
T_3 V_69 ;
V_65 = F_4 ( V_53 + V_70 ) ;
V_66 = F_4 ( V_53 + V_71 ) ;
V_67 = F_4 ( V_53 + V_72 ) ;
V_68 = F_4 ( V_53 + V_73 ) ;
V_69 = F_4 ( V_53 + V_74 ) ;
F_8 ( V_9 ) ;
V_18 = F_23 ( V_43 , V_44 , & V_45 ) ;
F_3 ( V_65 , V_53 + V_70 ) ;
F_3 ( V_66 , V_53 + V_71 ) ;
F_3 ( V_67 , V_53 + V_72 ) ;
F_3 ( V_68 , V_53 + V_73 ) ;
F_3 ( V_69 , V_53 + V_74 ) ;
V_11 -> V_14 ( V_9 ) ;
if ( V_45 )
* V_64 = F_32 ( V_9 ) ;
return V_18 ;
}
static void F_33 ( struct V_75 * V_12 )
{
struct V_10 * V_11 = V_12 -> V_13 ;
F_34 ( V_11 ) ;
}
static int F_35 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_17 ;
int V_76 ;
int V_18 ;
T_3 V_33 ;
V_18 = F_1 ( V_2 ) ;
if ( V_18 )
return V_18 ;
for ( V_76 = 0 ; V_76 < V_77 ; V_76 ++ )
F_17 ( V_2 , V_76 ) ;
F_3 ( 0xffffffff , V_11 -> V_32 + V_78 ) ;
F_4 ( V_11 -> V_32 + V_78 ) ;
F_3 ( 0 , V_2 -> V_79 + V_80 ) ;
V_33 = F_4 ( V_2 -> V_79 + V_80 ) ;
F_2 ( V_2 -> V_3 , L_5 ,
V_80 , V_33 ) ;
F_3 ( 0x0 , V_2 -> V_79 + V_81 ) ;
F_4 ( V_2 -> V_79 + V_81 ) ;
F_3 ( 0x0 , V_2 -> V_82 + V_83 ) ;
F_4 ( V_2 -> V_82 + V_83 ) ;
F_3 ( 0xffffffff , V_2 -> V_79 + V_84 ) ;
F_3 ( 0xffffffff , V_2 -> V_79 + V_85 ) ;
F_3 ( 0xffffffff , V_2 -> V_79 + V_86 ) ;
F_3 ( 0xffffffff , V_2 -> V_79 + V_87 ) ;
V_33 = F_4 ( V_2 -> V_79 + V_88 ) ;
V_33 &= ~ 0x00000002 ;
V_33 &= ~ 0x00000001 ;
F_3 ( V_33 , V_2 -> V_79 + V_88 ) ;
V_33 = F_4 ( V_2 -> V_79 + V_89 ) ;
V_33 |= ( 1 << 3 ) ;
V_33 |= ( 1 << 9 ) ;
F_3 ( V_33 , V_2 -> V_79 + V_89 ) ;
V_33 = F_4 ( V_2 -> V_79 + V_89 ) ;
F_2 ( V_2 -> V_3 , L_6 ,
V_89 , V_33 ) ;
return V_18 ;
}
static int F_36 ( struct V_1 * V_2 )
{
T_3 V_33 ;
if ( ! V_2 -> V_90 )
return 0 ;
V_33 = F_4 ( V_2 -> V_90 + V_91 ) ;
V_33 &= ~ V_92 ;
F_3 ( V_33 , V_2 -> V_90 + V_91 ) ;
V_33 = F_4 ( V_2 -> V_90 + V_91 ) ;
return V_33 & V_92 ? - 1 : 0 ;
}
static int F_37 ( struct V_93 * V_94 )
{
struct V_56 * V_3 = & V_94 -> V_3 ;
struct V_10 * V_11 ;
struct V_1 * V_2 ;
struct V_95 * V_96 ;
int V_18 ;
V_11 = F_38 ( V_94 ) ;
if ( F_39 ( V_11 ) )
return F_40 ( V_11 ) ;
V_2 = F_41 ( V_3 , sizeof( * V_2 ) , V_97 ) ;
if ( ! V_2 )
return - V_98 ;
V_11 -> V_17 = V_2 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_3 = V_3 ;
V_96 = F_42 ( V_94 , V_99 , 1 ) ;
V_2 -> V_79 = F_43 ( V_3 , V_96 ) ;
if ( F_39 ( V_2 -> V_79 ) )
return F_40 ( V_2 -> V_79 ) ;
V_96 = F_42 ( V_94 , V_99 , 2 ) ;
V_2 -> V_4 = F_43 ( V_3 , V_96 ) ;
if ( F_39 ( V_2 -> V_4 ) )
return F_40 ( V_2 -> V_4 ) ;
V_96 = F_42 ( V_94 , V_99 , 3 ) ;
V_2 -> V_82 = F_43 ( V_3 , V_96 ) ;
if ( F_39 ( V_2 -> V_82 ) )
return F_40 ( V_2 -> V_82 ) ;
V_96 = F_42 ( V_94 , V_99 , 4 ) ;
if ( V_96 ) {
void T_1 * V_100 = F_43 ( V_3 , V_96 ) ;
if ( F_39 ( V_100 ) )
return F_40 ( V_100 ) ;
V_2 -> V_90 = V_100 ;
}
F_2 ( V_3 , L_7 , V_2 -> V_79 ,
V_11 -> V_32 ) ;
if ( ( V_18 = F_36 ( V_2 ) ) ) {
F_6 ( V_3 , L_8 , V_18 ) ;
return - V_7 ;
}
if ( F_13 ( V_2 ) ) {
F_44 ( V_3 , L_9 ) ;
goto V_101;
}
V_18 = F_45 ( V_11 ) ;
if ( V_18 )
goto V_102;
F_46 ( V_11 ) ;
V_18 = F_47 ( V_11 ) ;
if ( V_18 )
goto V_102;
F_35 ( V_11 ) ;
V_101:
V_11 -> V_103 = V_104 | V_105 ;
V_18 = F_48 ( V_94 , V_11 , & V_106 ) ;
if ( V_18 )
goto V_102;
F_2 ( V_3 , L_10 ) ;
return 0 ;
V_102:
F_34 ( V_11 ) ;
return V_18 ;
}
