static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_6 ) ;
F_3 ( V_4 & ~ V_3 , V_2 -> V_5 + V_6 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_6 ) ;
F_3 ( V_4 | V_3 , V_2 -> V_5 + V_6 ) ;
}
static T_1 F_5 ( T_2 V_7 , T_1 V_8 )
{
return F_6 ( V_7 * V_8 , 1000 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
T_1 V_9 = F_8 ( V_2 -> V_10 ) / V_2 -> V_11 ;
T_1 V_8 = F_8 ( V_2 -> V_10 ) / 1000000 ;
T_1 V_12 ;
T_1 V_13 , V_14 ;
T_1 V_15 ;
T_1 V_16 ;
unsigned long V_17 ;
F_9 ( V_2 -> V_18 , L_1 ,
V_2 -> V_11 , V_8 , V_9 ) ;
F_3 ( 0x01 , V_2 -> V_5 + V_19 ) ;
V_17 = V_20 + F_10 ( 100 ) ;
while ( F_2 ( V_2 -> V_5 + V_19 ) & 1 ) {
if ( F_11 ( V_20 , V_17 ) ) {
F_12 ( V_2 -> V_18 , L_2 ) ;
break;
}
}
F_3 ( 0x1 , V_2 -> V_5 + V_21 ) ;
if ( V_2 -> V_11 <= 100000 ) {
V_13 = V_9 * 1 / 2 ;
V_14 = V_9 * 1 / 2 ;
V_12 = F_5 ( 250 , V_8 ) ;
} else {
V_13 = V_9 * 1 / 3 ;
V_14 = V_9 * 2 / 3 ;
V_12 = F_5 ( 100 , V_8 ) ;
}
F_3 ( V_13 , V_2 -> V_5 + V_22 ) ;
F_3 ( V_14 , V_2 -> V_5 + V_23 ) ;
F_3 ( V_12 , V_2 -> V_5 + V_24 ) ;
F_3 ( F_5 ( 300 , V_8 ) , V_2 -> V_5 + V_25 ) ;
F_3 ( F_5 ( 50 , V_8 ) , V_2 -> V_5 + V_26 ) ;
V_15 = F_5 ( V_27 , V_8 ) ;
for ( V_16 = 0 ; V_16 < 15 ; ++ V_16 ) {
if ( V_15 <= 0x7fff )
break;
V_15 >>= 1 ;
}
if ( V_15 > 0x7fff )
V_15 = 0x7fff ;
F_3 ( V_16 , V_2 -> V_5 + V_28 ) ;
F_3 ( V_29 | F_13 ( V_15 ) , V_2 -> V_5 + V_30 ) ;
F_1 ( V_2 , ~ 0 ) ;
F_3 ( 0x01 , V_2 -> V_5 + V_31 ) ;
return 0 ;
}
static int F_14 ( const struct V_32 * V_33 )
{
return ( V_33 -> V_34 & V_35 ) != 0 ;
}
static int F_15 ( const struct V_32 * V_33 )
{
return ( V_33 -> V_34 & V_36 ) != 0 ;
}
static int F_16 ( const struct V_32 * V_33 )
{
return ( V_33 -> V_34 & V_37 ) != 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = V_2 -> V_33 ;
T_3 V_38 = F_2 ( V_2 -> V_5 + V_39 ) ;
int V_40 = F_18 ( V_38 , V_33 -> V_41 - V_2 -> V_42 ) ;
while ( V_40 -- > 0 ) {
int V_43 = F_2 ( V_2 -> V_5 + V_44 ) ;
if ( V_2 -> V_42 == 0 && F_16 ( V_33 ) ) {
if ( V_43 <= 0 || V_43 > V_45 ) {
V_2 -> V_46 = - V_47 ;
F_1 ( V_2 , ~ 0 ) ;
F_19 ( & V_2 -> V_48 ) ;
break;
}
V_33 -> V_41 = 1 + V_43 ;
F_3 ( V_33 -> V_41 , V_2 -> V_5 + V_49 ) ;
}
V_33 -> V_50 [ V_2 -> V_42 ++ ] = V_43 ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = V_2 -> V_33 ;
T_3 V_51 = V_52 - F_2 ( V_2 -> V_5 + V_53 ) ;
int V_40 = F_18 ( V_51 , V_33 -> V_41 - V_2 -> V_42 ) ;
int V_54 = V_33 -> V_41 - V_2 -> V_42 - V_40 ;
while ( V_40 -- > 0 )
F_3 ( V_33 -> V_50 [ V_2 -> V_42 ++ ] , V_2 -> V_5 + V_44 ) ;
return V_54 ;
}
static T_4 F_21 ( int V_55 , void * V_56 )
{
struct V_1 * V_2 = V_56 ;
T_1 V_57 ;
if ( ! ( F_2 ( V_2 -> V_5 + V_58 ) & V_59 ) )
return V_60 ;
V_57 = F_2 ( V_2 -> V_5 + V_61 ) ;
if ( ! V_2 -> V_33 ) {
F_12 ( V_2 -> V_18 , L_3 ) ;
goto V_62;
}
if ( F_14 ( V_2 -> V_33 ) && ( V_57 & V_63 ) )
F_17 ( V_2 ) ;
if ( ! F_14 ( V_2 -> V_33 ) && ( V_57 & V_64 ) ) {
if ( F_20 ( V_2 ) == 0 )
F_1 ( V_2 , V_64 ) ;
}
if ( V_57 & V_65 ) {
F_1 ( V_2 , ~ 0 ) ;
F_19 ( & V_2 -> V_48 ) ;
} else if ( V_57 & V_66 ) {
F_1 ( V_2 , ~ 0 ) ;
if ( F_14 ( V_2 -> V_33 ) && V_2 -> V_42 < V_2 -> V_33 -> V_41 )
F_17 ( V_2 ) ;
F_19 ( & V_2 -> V_48 ) ;
} else if ( F_22 ( V_57 & V_67 ) ) {
F_1 ( V_2 , ~ 0 ) ;
if ( V_57 & V_68 )
V_2 -> V_46 = - V_69 ;
else if ( V_57 & V_70 )
V_2 -> V_46 = - V_71 ;
else
V_2 -> V_46 = - V_72 ;
F_9 ( V_2 -> V_18 , L_4 ,
V_57 ,
V_2 -> V_33 -> V_73 ,
F_2 ( V_2 -> V_5 + V_74 ) ,
F_2 ( V_2 -> V_5 + V_49 ) ,
F_2 ( V_2 -> V_5 + V_75 ) ,
F_2 ( V_2 -> V_5 + V_76 ) ) ;
F_19 ( & V_2 -> V_48 ) ;
}
V_62:
F_3 ( V_59 , V_2 -> V_5 + V_58 ) ;
return V_77 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
T_1 V_78 = V_67 | V_66 ;
T_1 V_79 , V_80 ;
T_1 V_81 , V_82 ;
unsigned long V_83 ;
V_2 -> V_33 = V_33 ;
V_2 -> V_42 = 0 ;
V_2 -> V_46 = 0 ;
F_24 ( & V_2 -> V_48 ) ;
if ( F_15 ( V_33 ) ) {
V_81 = 0xF0 | ( ( V_33 -> V_73 >> 7 ) & 0x06 ) ;
V_82 = V_33 -> V_73 & 0xFF ;
} else {
V_81 = ( V_33 -> V_73 << 1 ) & 0xFF ;
V_82 = 0 ;
}
if ( F_14 ( V_33 ) ) {
V_79 = F_16 ( V_33 ) ? V_45 : V_33 -> V_41 ;
V_80 = 0 ;
V_81 |= 1 ;
} else {
V_79 = 0 ;
V_80 = V_33 -> V_41 ;
}
F_3 ( V_79 , V_2 -> V_5 + V_49 ) ;
F_3 ( V_80 , V_2 -> V_5 + V_76 ) ;
F_3 ( V_81 , V_2 -> V_5 + V_84 ) ;
F_3 ( V_82 , V_2 -> V_5 + V_85 ) ;
if ( F_14 ( V_33 ) )
V_78 |= V_63 ;
else if ( F_20 ( V_2 ) != 0 )
V_78 |= V_64 ;
F_3 ( V_86 , V_2 -> V_5 + V_87 ) ;
F_4 ( V_2 , V_78 ) ;
V_83 = F_25 ( & V_2 -> V_48 ,
V_88 ) ;
F_1 ( V_2 , V_78 ) ;
if ( F_2 ( V_2 -> V_5 + V_87 ) & V_89 )
F_12 ( V_2 -> V_18 , L_5 ) ;
if ( V_83 == 0 )
V_2 -> V_46 = - V_90 ;
if ( V_2 -> V_46 == - V_90 )
F_26 ( & V_2 -> V_91 ) ;
if ( F_22 ( V_2 -> V_46 ) && V_2 -> V_46 != - V_71 )
F_7 ( V_2 ) ;
return V_2 -> V_46 ;
}
static int F_27 ( struct V_1 * V_2 )
{
T_1 V_78 = V_67 | V_65 ;
unsigned long V_83 ;
F_24 ( & V_2 -> V_48 ) ;
F_3 ( 0xb , V_2 -> V_5 + V_87 ) ;
F_4 ( V_2 , V_78 ) ;
V_83 = F_25 ( & V_2 -> V_48 ,
V_92 ) ;
F_1 ( V_2 , V_78 ) ;
if ( V_83 == 0 )
return - V_90 ;
if ( F_2 ( V_2 -> V_5 + V_87 ) & V_89 )
F_12 ( V_2 -> V_18 , L_6 ) ;
return 0 ;
}
static int
F_28 ( struct V_93 * V_94 , struct V_32 V_95 [] , int V_96 )
{
struct V_1 * V_2 = F_29 ( V_94 ) ;
int V_97 ;
int V_54 = 0 ;
for ( V_97 = 0 ; V_54 == 0 && V_97 < V_96 ; ++ V_97 )
V_54 = F_23 ( V_2 , & V_95 [ V_97 ] ) ;
F_27 ( V_2 ) ;
return V_54 ? : V_97 ;
}
static int F_30 ( struct V_93 * V_94 )
{
struct V_1 * V_2 = F_29 ( V_94 ) ;
return ! ! ( F_2 ( V_2 -> V_5 + V_98 ) & V_99 ) ;
}
static void F_31 ( struct V_93 * V_94 , int V_100 )
{
struct V_1 * V_2 = F_29 ( V_94 ) ;
T_1 V_101 ;
V_101 = F_2 ( V_2 -> V_5 + V_98 ) & V_102 ;
if ( ! V_100 )
V_101 |= V_103 ;
F_3 ( V_101 , V_2 -> V_5 + V_98 ) ;
}
static int F_32 ( struct V_93 * V_94 )
{
struct V_1 * V_2 = F_29 ( V_94 ) ;
return ! ! ( F_2 ( V_2 -> V_5 + V_98 ) & V_104 ) ;
}
static T_1 F_33 ( struct V_93 * V_94 )
{
T_1 V_105 = ( V_106 | V_107 |
V_108 | V_109 ) ;
return V_105 ;
}
static int F_34 ( struct V_110 * V_111 )
{
struct V_112 * V_113 = V_111 -> V_18 . V_114 ;
struct V_1 * V_2 = NULL ;
struct V_115 * V_116 ;
void T_5 * V_5 ;
int V_55 ;
int V_54 = 0 ;
V_2 = F_35 ( & V_111 -> V_18 , sizeof( * V_2 ) , V_117 ) ;
if ( ! V_2 )
return - V_118 ;
V_116 = F_36 ( V_111 , V_119 , 0 ) ;
V_5 = F_37 ( & V_111 -> V_18 , V_116 ) ;
if ( F_38 ( V_5 ) )
return F_39 ( V_5 ) ;
V_55 = F_40 ( V_111 , 0 ) ;
if ( V_55 < 0 ) {
F_41 ( & V_111 -> V_18 , L_7 ) ;
return V_55 ;
}
V_2 -> V_10 = F_42 ( & V_111 -> V_18 , L_8 ) ;
if ( F_38 ( V_2 -> V_10 ) ) {
F_41 ( & V_111 -> V_18 , L_9 ) ;
return F_39 ( V_2 -> V_10 ) ;
}
V_2 -> V_5 = V_5 ;
V_2 -> V_18 = & V_111 -> V_18 ;
F_43 ( & V_2 -> V_48 ) ;
F_44 ( V_113 , L_10 , & V_2 -> V_11 ) ;
if ( V_2 -> V_11 == 0 )
V_2 -> V_11 = 100000 ;
V_54 = F_7 ( V_2 ) ;
if ( V_54 ) {
F_41 ( & V_111 -> V_18 , L_11 ) ;
return V_54 ;
}
V_54 = F_45 ( & V_111 -> V_18 , V_55 , F_21 , 0 ,
V_111 -> V_120 , V_2 ) ;
if ( V_54 ) {
F_41 ( & V_111 -> V_18 , L_12 , V_55 ) ;
return V_54 ;
}
F_46 ( V_2 -> V_10 ) ;
F_47 ( & V_2 -> V_91 , V_2 ) ;
F_48 ( V_2 -> V_91 . V_120 , V_111 -> V_120 , sizeof( V_2 -> V_91 . V_120 ) ) ;
V_2 -> V_91 . V_121 = V_122 ;
V_2 -> V_91 . V_123 = & V_124 ;
V_2 -> V_91 . V_125 = & V_126 ;
V_2 -> V_91 . V_127 = & V_128 ;
V_2 -> V_91 . V_18 . V_129 = & V_111 -> V_18 ;
V_2 -> V_91 . V_18 . V_114 = V_111 -> V_18 . V_114 ;
F_49 ( V_111 , V_2 ) ;
V_54 = F_50 ( & V_2 -> V_91 ) ;
if ( V_54 ) {
F_41 ( & V_111 -> V_18 , L_13 ) ;
return V_54 ;
}
return 0 ;
}
static int F_51 ( struct V_110 * V_111 )
{
struct V_1 * V_2 = F_52 ( V_111 ) ;
F_53 ( V_2 -> V_10 ) ;
F_54 ( & V_2 -> V_91 ) ;
return 0 ;
}
