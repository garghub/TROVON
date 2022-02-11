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
static int F_7 ( struct V_8 * V_9 ,
void T_1 * V_10 , unsigned
int V_11 , unsigned long V_12 ,
unsigned long V_13 )
{
unsigned long V_14 ;
unsigned int V_15 ;
V_15 = F_8 ( V_10 ) ;
V_14 = F_9 ( V_16 , V_13 ) ;
while ( V_15 != V_11 && F_10 ( V_16 , V_14 ) ) {
F_11 ( V_9 , V_12 ) ;
V_15 = F_8 ( V_10 ) ;
}
return V_15 ;
}
static int F_12 ( struct V_8 * V_9 )
{
struct V_17 * V_18 = V_9 -> V_19 -> V_20 ;
struct V_21 * V_22 = V_9 -> V_20 ;
void T_1 * V_23 = F_13 ( V_9 ) ;
T_2 V_24 ;
if ( F_7 ( V_9 , V_23 +
V_25 , 0x0 , 1 , 100 ) )
return - V_26 ;
F_14 ( V_9 ) ;
F_15 ( V_9 ) ;
if ( V_22 -> V_27 ) {
V_24 = F_4 ( V_23 + V_28 ) ;
F_3 ( V_24 | V_29 , V_23 + V_28 ) ;
V_24 = F_4 ( V_23 + V_28 ) ;
}
V_18 -> V_30 ( V_9 ) ;
return 0 ;
}
static unsigned int F_16 ( struct V_31 * V_32 )
{
struct V_8 * V_9 = V_32 -> V_9 ;
struct V_17 * V_18 = V_9 -> V_19 -> V_20 ;
struct V_1 * V_2 = V_18 -> V_33 ;
int V_34 = 0 ;
T_2 V_35 ;
void * V_23 = F_13 ( V_9 ) ;
if ( V_2 -> V_36 [ V_9 -> V_37 ] == V_38 ) {
V_35 = F_4 ( V_23 + V_28 ) ;
V_35 &= ~ V_39 ;
V_35 |= V_32 -> V_3 -> V_40 -> V_41 << V_42 ;
F_3 ( V_35 , V_23 + V_28 ) ;
}
if ( F_17 ( ( V_2 -> V_43 [ V_9 -> V_37 ] == V_44 ) ||
( V_2 -> V_43 [ V_9 -> V_37 ] == V_45 ) ||
( V_2 -> V_43 [ V_9 -> V_37 ] == V_46 ) ) )
F_12 ( V_9 ) ;
V_34 = F_18 ( V_32 ) ;
V_2 -> V_43 [ V_9 -> V_37 ] = V_32 -> V_47 . V_48 ;
return V_34 ;
}
static bool F_19 ( struct V_1 * V_2 )
{
void T_1 * V_49 = V_2 -> V_4 ;
return ( F_4 ( V_49 + V_5 ) == 0 &&
F_4 ( V_49 + V_6 ) == 0xFFFFFFFF ) ;
}
static unsigned int F_20 ( struct V_50 * V_3 ,
struct V_51 * V_47 , T_3 * V_52 )
{
T_2 V_53 ;
V_53 = F_21 ( V_3 , V_47 , V_52 ) ;
if ( V_53 )
return V_53 ;
V_52 [ V_54 ] &= F_22 ( ~ ( 1 << 8 ) ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 , int V_55 )
{
void T_1 * V_56 = V_2 -> V_18 -> V_56 ;
T_2 V_11 ;
F_2 ( V_2 -> V_3 , L_3 ,
V_56 , V_55 ) ;
V_11 = F_4 ( V_56 + V_57 ) ;
V_11 = F_24 ( V_11 , V_55 == 0 ? 2 : 3 ) ;
F_3 ( V_11 , V_56 + V_57 ) ;
F_4 ( V_56 + V_57 ) ;
F_3 ( 0x0001fffe , V_56 + V_58 ) ;
F_4 ( V_56 + V_58 ) ;
F_3 ( 0x28183219 , V_56 + V_59 ) ;
F_4 ( V_56 + V_59 ) ;
F_3 ( 0x13081008 , V_56 + V_60 ) ;
F_4 ( V_56 + V_60 ) ;
F_3 ( 0x00480815 , V_56 + V_61 ) ;
F_4 ( V_56 + V_61 ) ;
V_11 = F_4 ( V_56 + V_62 ) ;
V_11 = F_25 ( V_11 , 0x300 ) ;
F_3 ( V_11 , V_56 + V_62 ) ;
F_4 ( V_56 + V_62 ) ;
V_11 = F_4 ( V_56 + V_63 ) ;
V_11 = F_26 ( V_11 , 0x1 ) ;
V_11 = F_27 ( V_11 , 0xe ) ;
F_3 ( V_11 , V_56 + V_63 ) ;
F_4 ( V_56 + V_63 ) ;
V_11 = F_4 ( V_56 + V_64 ) ;
V_11 = F_28 ( V_11 , 0x30 ) ;
F_3 ( V_11 , V_56 + V_64 ) ;
}
static int F_29 ( struct V_65 * V_40 ,
unsigned long V_14 , bool * V_66 )
{
const unsigned long * V_67 = F_30 ( & V_40 -> V_68 ) ;
struct V_8 * V_9 = V_40 -> V_9 ;
struct V_17 * V_18 = V_9 -> V_19 -> V_20 ;
struct V_1 * V_2 = V_18 -> V_33 ;
struct V_21 * V_22 = V_9 -> V_20 ;
T_4 * V_69 = V_22 -> V_70 + V_71 ;
void T_1 * V_23 = F_13 ( V_9 ) ;
struct V_51 V_47 ;
int V_72 = 0 ;
int V_34 ;
T_2 V_11 , V_73 ;
do {
F_31 ( V_40 -> V_74 , & V_47 ) ;
V_47 . V_48 = V_75 ;
F_32 ( & V_47 , 0 , 0 , V_69 ) ;
V_34 = F_33 ( V_40 , V_67 , V_14 , V_66 ,
V_76 ) ;
if ( * V_66 ) {
V_11 = F_4 ( V_23 + V_77 ) ;
if ( V_11 & ( V_78 | V_79 ) )
F_34 ( V_2 -> V_3 , L_4 ) ;
break;
}
F_35 ( V_40 , V_80 , & V_73 ) ;
} while ( V_72 ++ < V_81 &&
( V_73 & 0xff ) == 0x1 );
V_11 = F_4 ( V_23 + V_77 ) ;
F_3 ( V_11 , V_23 + V_77 ) ;
return V_34 ;
}
static int F_36 ( struct V_65 * V_40 , unsigned int * V_36 ,
unsigned long V_14 )
{
struct V_8 * V_9 = V_40 -> V_9 ;
struct V_17 * V_18 = V_9 -> V_19 -> V_20 ;
void T_1 * V_23 = F_13 ( V_9 ) ;
bool V_66 ;
int V_34 ;
T_2 V_82 ;
T_2 V_83 ;
T_2 V_84 ;
T_2 V_85 ;
T_2 V_86 ;
V_82 = F_4 ( V_23 + V_87 ) ;
V_83 = F_4 ( V_23 + V_88 ) ;
V_84 = F_4 ( V_23 + V_89 ) ;
V_85 = F_4 ( V_23 + V_90 ) ;
V_86 = F_4 ( V_23 + V_91 ) ;
F_14 ( V_9 ) ;
V_34 = F_29 ( V_40 , V_14 , & V_66 ) ;
F_3 ( V_82 , V_23 + V_87 ) ;
F_3 ( V_83 , V_23 + V_88 ) ;
F_3 ( V_84 , V_23 + V_89 ) ;
F_3 ( V_85 , V_23 + V_90 ) ;
F_3 ( V_86 , V_23 + V_91 ) ;
V_18 -> V_30 ( V_9 ) ;
if ( V_66 )
* V_36 = F_37 ( V_9 ) ;
return V_34 ;
}
static void F_38 ( struct V_92 * V_19 )
{
struct V_17 * V_18 = V_19 -> V_20 ;
F_39 ( V_18 ) ;
}
static int F_40 ( struct V_65 * V_40 , unsigned int * V_36 ,
unsigned long V_14 )
{
int V_41 = F_41 ( V_40 ) ;
struct V_8 * V_9 = V_40 -> V_9 ;
T_2 V_34 ;
void * V_23 = F_13 ( V_9 ) ;
T_2 V_35 ;
V_35 = F_4 ( V_23 + V_28 ) ;
V_35 &= ~ V_39 ;
V_35 |= V_41 << V_42 ;
F_3 ( V_35 , V_23 + V_28 ) ;
V_34 = F_42 ( V_40 , V_36 , V_41 , V_14 , V_76 ) ;
return V_34 ;
}
static int F_43 ( struct V_65 * V_40 , unsigned int * V_36 ,
unsigned long V_14 )
{
int V_41 = F_41 ( V_40 ) ;
struct V_8 * V_9 = V_40 -> V_9 ;
struct V_17 * V_18 = V_9 -> V_19 -> V_20 ;
struct V_1 * V_2 = V_18 -> V_33 ;
void * V_23 = F_13 ( V_9 ) ;
T_2 V_35 ;
T_2 V_93 ;
T_2 V_94 = 1 ;
T_2 V_34 ;
V_93 = F_4 ( V_23 + V_28 ) ;
V_35 = F_4 ( V_23 + V_28 ) ;
V_35 &= ~ V_39 ;
V_35 |= V_41 << V_42 ;
F_3 ( V_35 , V_23 + V_28 ) ;
V_95:
V_34 = F_42 ( V_40 , V_36 , V_41 ,
V_14 , V_76 ) ;
V_2 -> V_36 [ V_9 -> V_37 ] = * V_36 ;
if ( * V_36 != V_38 ) {
if ( V_94 -- ) {
F_3 ( V_93 , V_23 + V_28 ) ;
goto V_95;
}
}
return V_34 ;
}
static int F_44 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_33 ;
int V_96 ;
int V_34 ;
T_2 V_11 ;
V_34 = F_1 ( V_2 ) ;
if ( V_34 )
return V_34 ;
for ( V_96 = 0 ; V_96 < V_97 ; V_96 ++ )
F_23 ( V_2 , V_96 ) ;
F_3 ( 0xffffffff , V_18 -> V_56 + V_98 ) ;
F_4 ( V_18 -> V_56 + V_98 ) ;
F_3 ( 0 , V_2 -> V_99 + V_100 ) ;
V_11 = F_4 ( V_2 -> V_99 + V_100 ) ;
F_2 ( V_2 -> V_3 , L_5 ,
V_100 , V_11 ) ;
F_3 ( 0x0 , V_2 -> V_99 + V_101 ) ;
F_4 ( V_2 -> V_99 + V_101 ) ;
F_3 ( 0x0 , V_2 -> V_102 + V_103 ) ;
F_4 ( V_2 -> V_102 + V_103 ) ;
F_3 ( 0xffffffff , V_2 -> V_99 + V_104 ) ;
F_3 ( 0xffffffff , V_2 -> V_99 + V_105 ) ;
F_3 ( 0xffffffff , V_2 -> V_99 + V_106 ) ;
F_3 ( 0xffffffff , V_2 -> V_99 + V_107 ) ;
V_11 = F_4 ( V_2 -> V_99 + V_108 ) ;
V_11 &= ~ 0x00000002 ;
V_11 &= ~ 0x00000001 ;
F_3 ( V_11 , V_2 -> V_99 + V_108 ) ;
V_11 = F_4 ( V_2 -> V_99 + V_109 ) ;
V_11 |= ( 1 << 3 ) ;
V_11 |= ( 1 << 9 ) ;
F_3 ( V_11 , V_2 -> V_99 + V_109 ) ;
V_11 = F_4 ( V_2 -> V_99 + V_109 ) ;
F_2 ( V_2 -> V_3 , L_6 ,
V_109 , V_11 ) ;
return V_34 ;
}
static int F_45 ( struct V_1 * V_2 )
{
T_2 V_11 ;
if ( ! V_2 -> V_110 )
return 0 ;
V_11 = F_4 ( V_2 -> V_110 + V_111 ) ;
V_11 &= ~ V_112 ;
F_3 ( V_11 , V_2 -> V_110 + V_111 ) ;
V_11 = F_4 ( V_2 -> V_110 + V_111 ) ;
return V_11 & V_112 ? - 1 : 0 ;
}
static int F_46 ( struct V_113 * V_114 )
{
struct V_74 * V_3 = & V_114 -> V_3 ;
struct V_17 * V_18 ;
struct V_1 * V_2 ;
struct V_115 * V_116 ;
int V_34 ;
V_18 = F_47 ( V_114 ) ;
if ( F_48 ( V_18 ) )
return F_49 ( V_18 ) ;
V_2 = F_50 ( V_3 , sizeof( * V_2 ) , V_117 ) ;
if ( ! V_2 )
return - V_118 ;
V_18 -> V_33 = V_2 ;
V_2 -> V_18 = V_18 ;
V_2 -> V_3 = V_3 ;
V_116 = F_51 ( V_114 , V_119 , 1 ) ;
V_2 -> V_99 = F_52 ( V_3 , V_116 ) ;
if ( F_48 ( V_2 -> V_99 ) )
return F_49 ( V_2 -> V_99 ) ;
V_116 = F_51 ( V_114 , V_119 , 2 ) ;
V_2 -> V_4 = F_52 ( V_3 , V_116 ) ;
if ( F_48 ( V_2 -> V_4 ) )
return F_49 ( V_2 -> V_4 ) ;
V_116 = F_51 ( V_114 , V_119 , 3 ) ;
V_2 -> V_102 = F_52 ( V_3 , V_116 ) ;
if ( F_48 ( V_2 -> V_102 ) )
return F_49 ( V_2 -> V_102 ) ;
V_116 = F_51 ( V_114 , V_119 , 4 ) ;
if ( V_116 ) {
void T_1 * V_120 = F_52 ( V_3 , V_116 ) ;
if ( F_48 ( V_120 ) )
return F_49 ( V_120 ) ;
V_2 -> V_110 = V_120 ;
}
F_2 ( V_3 , L_7 , V_2 -> V_99 ,
V_18 -> V_56 ) ;
if ( ( V_34 = F_45 ( V_2 ) ) ) {
F_6 ( V_3 , L_8 , V_34 ) ;
return - V_7 ;
}
if ( F_19 ( V_2 ) ) {
F_53 ( V_3 , L_9 ) ;
goto V_121;
}
V_34 = F_54 ( V_18 ) ;
if ( V_34 )
goto V_122;
F_55 ( V_18 ) ;
V_34 = F_56 ( V_18 ) ;
if ( V_34 )
goto V_122;
F_44 ( V_18 ) ;
V_121:
V_18 -> V_123 = V_124 | V_125 ;
V_34 = F_57 ( V_114 , V_18 , & V_126 ,
& V_127 ) ;
if ( V_34 )
goto V_122;
F_2 ( V_3 , L_10 ) ;
return 0 ;
V_122:
F_39 ( V_18 ) ;
return V_34 ;
}
