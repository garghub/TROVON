static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
int V_5 = 0 ;
F_2 ( ! V_3 ) ;
F_3 ( & V_6 , V_4 ) ;
if ( V_7 & V_3 ) {
F_4 ( V_8 L_1 ,
V_7 , V_3 ) ;
V_5 = - 1 ;
}
if ( ! V_7 ) {
if ( V_9 )
F_5 ( V_9 ) ;
F_6 ( V_2 -> V_10 ) ;
}
V_7 |= V_3 ;
F_7 ( & V_6 , V_4 ) ;
return V_5 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( ! ( V_7 & V_3 ) ) {
F_4 ( V_8 L_2 ,
V_7 , V_3 ) ;
return - 1 ;
}
V_7 &= ~ ( V_3 ) ;
if ( ! V_7 ) {
F_9 ( V_2 -> V_10 ) ;
if ( V_9 )
F_10 ( V_9 ) ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
int V_5 ;
F_3 ( & V_6 , V_4 ) ;
V_5 = F_8 ( V_2 , V_3 ) ;
F_7 ( & V_6 , V_4 ) ;
return V_5 ;
}
static T_2 F_12 ( int V_10 , void * V_11 )
{
T_1 V_12 ;
unsigned long V_4 ;
struct V_1 * V_2 = V_11 ;
F_3 ( & V_6 , V_4 ) ;
V_12 = F_13 ( V_2 , V_13 ) ;
F_14 ( V_2 , V_12 , V_14 ) ;
V_12 &= V_7 ;
if ( V_12 & V_15 ) {
if ( V_16 ) {
V_16 -> V_17 ( V_16 ) ;
V_16 = NULL ;
}
F_15 ( & V_18 ) ;
}
if ( V_12 & V_19 )
F_15 ( & V_20 ) ;
if ( V_12 )
F_8 ( V_2 , V_12 ) ;
F_7 ( & V_6 , V_4 ) ;
return V_21 ;
}
static T_1 F_16 ( T_1 V_3 )
{
T_1 V_5 ;
unsigned long V_4 ;
F_3 ( & V_6 , V_4 ) ;
V_5 = V_7 & V_3 ;
F_7 ( & V_6 , V_4 ) ;
return V_5 ;
}
static int F_17 ( struct V_1 * V_2 , T_1 V_3 , T_3 * V_22 )
{
int V_5 = 0 ;
unsigned long V_4 ;
F_18 ( * V_22 , ! F_16 ( V_3 ) , V_23 ) ;
F_3 ( & V_6 , V_4 ) ;
if ( V_7 & V_3 ) {
F_8 ( V_2 , V_3 ) ;
F_4 ( V_24 L_3 ,
V_3 ) ;
V_5 = - V_25 ;
}
F_7 ( & V_6 , V_4 ) ;
return V_5 ;
}
void F_19 ( struct V_26 * V_27 )
{
#define F_20 20
static int V_28 ;
struct V_1 * V_2 = F_21 ( V_27 , struct V_1 , V_27 ) ;
if ( F_17 ( V_2 , V_15 , & V_18 ) == - V_25 )
V_28 ++ ;
else
V_28 = 0 ;
if ( V_28 > F_20 ) {
F_4 ( V_8 L_4 ,
F_20 ) ;
F_22 () ;
}
}
static int F_23 ( struct V_1 * V_2 )
{
return F_17 ( V_2 , V_19 , & V_20 ) ;
}
void F_24 ( struct V_1 * V_2 , T_1 V_29 , T_1 V_30 ,
T_1 V_31 , T_1 V_32 , T_1 V_33 , T_1 V_34 ,
struct V_35 * V_36 )
{
T_1 V_37 ;
T_4 V_38 = 0 ;
if ( F_1 ( V_2 , V_15 ) ) {
F_4 ( V_8 L_5 ) ;
return;
}
V_16 = V_36 ;
V_37 = V_39 |
V_40 |
V_41 |
V_42 |
V_43 ;
V_37 |= V_44 ;
V_37 |= V_45 ;
V_37 |= V_46 ;
V_37 |= V_47 ;
F_14 ( V_2 , ( V_32 << 16 ) | ( V_31 ) ,
V_48 + 0x0184 ) ;
F_14 ( V_2 , V_29 , V_48 + 0x0188 ) ;
F_14 ( V_2 , V_30 , V_48 + 0x018C ) ;
V_37 |= V_49 | V_50 | V_51 ;
F_14 ( V_2 , ( V_34 << 16 ) | ( V_33 ) , V_48 + 0x0194 ) ;
F_14 ( V_2 , V_38 , V_48 + 0x01a0 ) ;
F_14 ( V_2 , ( V_52 << 16 ) | V_53 ,
V_48 + 0x01a4 ) ;
F_14 ( V_2 , V_37 , V_48 + 0x0180 ) ;
F_14 ( V_2 , 0 , V_48 + 0x0044 ) ;
}
void F_25 ( struct V_26 * V_27 , T_1 V_29 , T_1 V_30 ,
T_1 V_31 , T_1 V_32 , T_1 V_33 , T_1 V_34 ,
struct V_35 * V_36 , int V_54 )
{
struct V_1 * V_2 = F_21 ( V_27 , struct V_1 , V_27 ) ;
if ( V_54 == V_55 ) {
F_24 ( V_2 , V_29 , V_30 , V_31 , V_32 , V_33 , V_34 ,
V_36 ) ;
}
}
int F_26 ( struct V_56 * V_57 , struct V_58 * V_59 ,
unsigned long * V_60 , unsigned long * V_61 ,
struct V_62 * * V_63 )
{
int V_5 = 0 ;
struct V_64 V_65 = F_27 ( V_57 -> V_66 ) ;
if ( V_65 . V_62 == NULL )
return - 1 ;
if ( F_28 ( F_29 ( V_65 . V_62 ) -> V_67 ) == V_68 ) {
* V_60 = V_59 -> V_69 . V_70 ;
* V_61 = V_59 -> V_69 . V_71 ;
} else
V_5 = - 1 ;
F_30 ( V_65 ) ;
return V_5 ;
}
void F_31 ( struct V_62 * V_72 , struct V_62 * V_73 )
{
}
int F_32 ( struct V_26 * V_27 , struct V_58 * V_74 ,
struct V_75 * V_76 )
{
int V_5 ;
unsigned long V_77 = 0 , V_78 = 0 , V_79 = 0 , V_80 = 0 ;
struct V_1 * V_2 = F_21 ( V_27 , struct V_1 , V_27 ) ;
struct V_62 * V_72 = 0 , * V_73 = 0 ;
if ( F_33 ( V_76 -> V_81 . V_82 == 0 ||
V_76 -> V_81 . V_83 == 0 ) ) {
F_4 ( V_8 L_6 ) ;
return - V_84 ;
}
if ( F_33 ( V_76 -> V_85 . V_82 == 0 ||
V_76 -> V_85 . V_83 == 0 ) )
return - V_84 ;
if ( F_33 ( F_26 ( & V_76 -> V_86 , V_74 , & V_77 , & V_78 , & V_72 ) ) ) {
F_4 ( V_8 L_7
L_8 ) ;
return - V_84 ;
}
if ( F_33 ( F_26 ( & V_76 -> V_87 , V_74 , & V_79 , & V_80 , & V_73 ) ) ) {
F_4 ( V_8 L_9
L_8 ) ;
return - V_84 ;
}
F_34 ( & V_88 ) ;
V_76 -> V_89 = V_90 ;
if ( F_33 ( ( V_76 -> V_89 != V_90 ||
V_76 -> V_91 != V_92 ||
F_35 ( V_76 -> V_86 . V_93 ) ) &&
( V_76 -> V_94 & V_95 &&
V_76 -> V_85 . V_83 <= 16 && V_76 -> V_85 . V_82 >= 16 ) ) ) {
int V_96 ;
unsigned int V_97 = V_76 -> V_85 . V_82 / 16 ;
unsigned int V_98 = V_76 -> V_85 . V_82 % 16 ;
V_76 -> V_81 . V_83 = 16 * V_76 -> V_81 . V_83 / V_76 -> V_85 . V_82 ;
V_76 -> V_85 . V_82 = 16 ;
for ( V_96 = 0 ; V_96 < V_97 ; V_96 ++ ) {
F_1 ( V_2 , V_19 ) ;
V_5 = F_36 ( V_2 , V_76 , V_72 , V_77 ,
V_78 , V_73 , V_79 ,
V_80 ) ;
if ( V_5 )
goto V_99;
V_5 = F_23 ( V_2 ) ;
if ( V_5 )
goto V_100;
V_76 -> V_85 . V_34 += 16 ;
V_76 -> V_81 . V_33 += V_76 -> V_81 . V_83 ;
}
if ( ! V_98 )
goto V_101;
V_76 -> V_81 . V_83 = V_98 * V_76 -> V_81 . V_83 / V_76 -> V_85 . V_82 ;
V_76 -> V_85 . V_82 = V_98 ;
}
F_1 ( V_2 , V_19 ) ;
V_5 = F_36 ( V_2 , V_76 , V_72 , V_77 , V_78 , V_73 ,
V_79 ,
V_80 ) ;
if ( V_5 )
goto V_99;
V_5 = F_23 ( V_2 ) ;
if ( V_5 )
goto V_100;
V_101:
F_31 ( V_72 , V_73 ) ;
F_37 ( & V_88 ) ;
return 0 ;
V_99:
F_11 ( V_2 , V_19 ) ;
V_100:
F_31 ( V_72 , V_73 ) ;
F_37 ( & V_88 ) ;
return V_5 ;
}
void F_38 ( struct V_26 * V_27 , unsigned V_102 )
{
struct V_1 * V_2 = F_21 ( V_27 , struct V_1 , V_27 ) ;
V_102 &= 0xf ;
F_14 ( V_2 , V_102 , V_103 ) ;
}
int F_39 ( struct V_104 * V_105 )
{
if ( ! V_106 ) {
F_40 ( L_10 ) ;
return - V_107 ;
}
V_105 -> V_108 = V_106 ;
return F_41 ( V_105 ) ;
}
int F_42 ( struct V_109 * V_110 )
{
struct V_111 * V_111 ;
int V_5 ;
int V_112 ;
struct V_1 * V_2 ;
V_111 = F_43 ( V_110 , V_113 , 0 ) ;
if ( ! V_111 ) {
F_40 ( L_11 ) ;
return - V_114 ;
}
V_2 = F_44 ( sizeof( struct V_1 ) , V_115 ) ;
if ( ! V_2 )
return - V_114 ;
V_2 -> V_10 = F_45 ( V_110 , 0 ) ;
if ( V_2 -> V_10 < 0 ) {
F_40 ( L_12 ) ;
V_5 = V_2 -> V_10 ;
goto V_116;
}
V_2 -> V_117 = F_46 ( V_111 -> V_60 , F_47 ( V_111 ) ) ;
if ( V_2 -> V_117 == 0 ) {
F_4 ( V_8 L_13 ) ;
V_5 = - V_114 ;
goto V_118;
}
V_2 -> V_27 . V_119 = F_25 ;
V_2 -> V_27 . V_120 = F_19 ;
V_2 -> V_27 . V_121 = F_32 ;
V_2 -> V_27 . V_122 = F_38 ;
V_9 = F_48 ( & V_110 -> V_123 , L_14 ) ;
if ( F_49 ( V_9 ) ) {
F_4 ( V_124 L_15 ) ;
V_5 = F_50 ( V_9 ) ;
goto V_125;
}
V_5 = F_51 ( V_2 -> V_10 , F_12 , 0 , L_16 , V_2 ) ;
if ( V_5 )
goto V_126;
F_52 ( V_2 -> V_10 ) ;
V_7 = 0 ;
F_14 ( V_2 , 1 , 0x60 ) ;
F_14 ( V_2 , V_127 , V_128 ) ;
F_14 ( V_2 , 1 , V_129 ) ;
F_14 ( V_2 , 0 , V_48 + 0x01f8 ) ;
F_14 ( V_2 , 0 , V_48 + 0x01fc ) ;
for ( V_112 = 0 ; V_112 < F_53 ( V_130 ) ; V_112 ++ )
F_14 ( V_2 , V_130 [ V_112 ] . V_131 , V_130 [ V_112 ] . V_132 ) ;
F_14 ( V_2 , 0 , V_48 + 0x0120 ) ;
F_14 ( V_2 , 0 , V_48 + 0x012c ) ;
F_14 ( V_2 , 0 , V_48 + 0x0130 ) ;
F_14 ( V_2 , 0 , V_48 + 0x0134 ) ;
F_14 ( V_2 , 0 , V_48 + 0x0158 ) ;
F_14 ( V_2 , 0 , V_48 + 0x015c ) ;
F_14 ( V_2 , 0 , V_48 + 0x0160 ) ;
F_14 ( V_2 , 0 , V_48 + 0x0170 ) ;
F_14 ( V_2 , 0 , V_48 + 0x0174 ) ;
F_14 ( V_2 , 0 , V_48 + 0x017c ) ;
F_14 ( V_2 , 0 , V_48 + 0x0114 ) ;
F_14 ( V_2 , 0 , V_48 + 0x0118 ) ;
F_14 ( V_2 , 0 , V_48 + 0x01c8 ) ;
F_14 ( V_2 , 0 , V_48 + 0x01d0 ) ;
F_14 ( V_2 , 0 , V_48 + 0x01dc ) ;
F_14 ( V_2 , 0 , V_48 + 0x01e0 ) ;
F_14 ( V_2 , 0 , V_48 + 0x01e4 ) ;
for ( V_112 = 0 ; V_112 < F_53 ( V_133 ) ; V_112 ++ )
F_14 ( V_2 , V_133 [ V_112 ] . V_131 ,
V_133 [ V_112 ] . V_132 ) ;
for ( V_112 = 0 ; V_112 < 9 ; V_112 ++ )
F_14 ( V_2 , V_134 [ V_112 ] , 0x40440 + 4 * V_112 ) ;
F_14 ( V_2 , V_134 [ 9 ] , 0x40500 + 4 * 0 ) ;
F_14 ( V_2 , V_134 [ 10 ] , 0x40500 + 4 * 0 ) ;
F_14 ( V_2 , V_134 [ 11 ] , 0x40500 + 4 * 0 ) ;
V_2 -> V_27 . V_123 . V_135 = & V_110 -> V_123 ;
V_2 -> V_27 . V_123 . V_108 = V_106 ;
F_54 ( & V_2 -> V_27 . V_123 , L_17 , V_110 -> V_136 ) ;
V_5 = F_55 ( & V_2 -> V_27 . V_123 ) ;
if ( V_5 )
goto V_137;
return 0 ;
V_137:
F_56 ( V_2 -> V_10 , V_2 ) ;
V_126:
V_125:
F_57 ( V_2 -> V_117 ) ;
V_116:
V_118:
F_58 ( V_2 ) ;
return V_5 ;
}
static int T_5 F_59 ( void )
{
V_106 = F_60 ( V_138 , L_16 ) ;
if ( F_49 ( V_106 ) ) {
F_4 ( V_8 L_18 ) ;
return F_50 ( V_106 ) ;
}
return F_61 ( & V_139 ) ;
}
