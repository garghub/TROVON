static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
struct V_7 * V_8 = V_5 -> V_9 ;
void T_2 * V_10 = V_8 -> V_10 ;
T_3 V_11 ;
if ( V_3 . V_12 & V_13 &&
V_8 -> V_14 & V_15 ) {
F_3 ( V_16 , & V_2 -> V_6 ,
L_1 ) ;
return - V_17 ;
}
if ( V_3 . V_12 & V_18 ) {
V_11 = F_4 ( V_10 + V_19 ) ;
V_11 &= ~ V_20 ;
F_5 ( V_11 , V_10 + V_19 ) ;
F_4 ( V_10 + V_19 ) ;
}
return F_6 ( V_2 , V_3 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( & V_2 -> V_6 ) ;
int V_21 ;
V_21 = F_8 ( V_2 ) ;
if ( V_21 )
return V_21 ;
if ( V_2 -> V_6 . V_22 . V_23 . V_12 == V_13 ) {
V_21 = F_9 ( V_5 ) ;
if ( V_21 )
return V_21 ;
F_10 ( V_5 ) ;
}
F_11 ( V_5 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , int V_24 )
{
int V_21 ;
if ( V_24 &&
! F_13 ( V_2 , F_14 ( 64 ) ) ) {
V_21 = F_15 ( V_2 , F_14 ( 64 ) ) ;
if ( V_21 ) {
V_21 = F_15 ( V_2 , F_14 ( 32 ) ) ;
if ( V_21 ) {
F_3 ( V_16 , & V_2 -> V_6 ,
L_2 ) ;
return V_21 ;
}
}
} else {
V_21 = F_13 ( V_2 , F_14 ( 32 ) ) ;
if ( V_21 ) {
F_3 ( V_16 , & V_2 -> V_6 ,
L_3 ) ;
return V_21 ;
}
V_21 = F_15 ( V_2 , F_14 ( 32 ) ) ;
if ( V_21 ) {
F_3 ( V_16 , & V_2 -> V_6 ,
L_4 ) ;
return V_21 ;
}
}
return 0 ;
}
static void F_16 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_17 ( V_5 -> V_6 ) ;
T_4 V_25 ;
const char * V_26 ;
F_18 ( V_2 , 0x0a , & V_25 ) ;
if ( V_25 == V_27 )
V_26 = L_5 ;
else if ( V_25 == V_28 )
V_26 = L_6 ;
else if ( V_25 == V_29 )
V_26 = L_7 ;
else
V_26 = L_8 ;
F_19 ( V_5 , V_26 ) ;
}
static unsigned int F_20 ( struct V_30 * V_31 , void * V_32 )
{
struct V_33 * V_34 ;
struct V_35 * V_35 = V_32 + V_36 ;
unsigned int V_37 , V_38 = 0 ;
F_21 ( L_9 ) ;
F_22 (qc->sg, sg, qc->n_elem, si) {
T_5 V_39 = F_23 ( V_34 ) ;
T_3 V_40 = F_24 ( V_34 ) ;
V_35 [ V_37 ] . V_39 = F_25 ( V_39 & 0xffffffff ) ;
V_35 [ V_37 ] . V_41 = F_25 ( ( V_39 >> 16 ) >> 16 ) ;
V_35 [ V_37 ] . V_42 = F_25 ( V_40 ) ;
V_38 = V_37 ;
}
V_35 [ V_38 ] . V_42 |= F_25 ( 1 << 31 ) ;
return V_37 ;
}
static void F_26 ( struct V_30 * V_31 )
{
struct V_43 * V_44 = V_31 -> V_44 ;
struct V_45 * V_46 = V_44 -> V_9 ;
int V_47 = F_27 ( V_31 -> V_48 . V_49 ) ;
void * V_32 ;
T_3 V_50 ;
const T_3 V_51 = 5 ;
unsigned int V_52 ;
V_32 = V_46 -> V_32 + V_31 -> V_53 * V_54 ;
F_28 ( & V_31 -> V_48 , V_31 -> V_6 -> V_55 -> V_56 , 1 , V_32 ) ;
if ( V_47 ) {
memset ( V_32 + V_57 , 0 , 32 ) ;
memcpy ( V_32 + V_57 , V_31 -> V_58 , V_31 -> V_6 -> V_59 ) ;
}
V_52 = 0 ;
if ( V_31 -> V_14 & V_60 )
V_52 = F_20 ( V_31 , V_32 ) ;
V_50 = V_51 | ( V_31 -> V_6 -> V_55 -> V_56 << 12 ) ;
if ( V_31 -> V_48 . V_14 & V_61 )
V_50 |= V_62 ;
if ( V_47 )
V_50 |= V_63 | V_64 ;
F_29 ( V_46 , V_31 -> V_53 , V_50 ) ;
}
static bool F_30 ( struct V_30 * V_31 )
{
struct V_45 * V_46 = V_31 -> V_44 -> V_9 ;
T_6 * V_65 = V_46 -> V_65 ;
if ( V_46 -> V_66 )
V_65 += V_31 -> V_6 -> V_55 -> V_56 * V_67 ;
if ( V_31 -> V_48 . V_49 == V_68 && V_31 -> V_69 == V_70 &&
! ( V_31 -> V_14 & V_71 ) ) {
F_31 ( V_65 + V_72 , & V_31 -> V_73 ) ;
V_31 -> V_73 . V_74 = ( V_65 + V_72 ) [ 15 ] ;
} else
F_31 ( V_65 + V_75 , & V_31 -> V_73 ) ;
return true ;
}
static int F_32 ( struct V_43 * V_44 )
{
struct V_7 * V_8 = V_44 -> V_5 -> V_9 ;
struct V_76 * V_6 = V_44 -> V_5 -> V_6 ;
struct V_45 * V_46 ;
void * V_77 ;
T_5 V_78 ;
T_7 V_79 , V_80 ;
V_46 = F_33 ( V_6 , sizeof( * V_46 ) , V_81 ) ;
if ( ! V_46 )
return - V_82 ;
if ( ( V_8 -> V_83 & V_84 ) && F_34 ( V_44 ) ) {
void T_2 * V_85 = F_35 ( V_44 ) ;
T_3 V_86 = F_4 ( V_85 + V_87 ) ;
if ( V_86 & V_88 )
V_46 -> V_89 = true ;
else if ( V_8 -> V_14 & V_90 ) {
F_3 ( V_91 , V_6 ,
L_10 ,
V_44 -> V_92 ) ;
V_46 -> V_89 = true ;
} else
F_3 ( V_93 , V_6 ,
L_11 ,
V_44 -> V_92 ) ;
}
if ( V_46 -> V_89 ) {
V_79 = V_94 ;
V_80 = V_67 * 16 ;
} else {
V_79 = V_95 ;
V_80 = V_67 ;
}
V_77 = F_36 ( V_6 , V_79 , & V_78 , V_81 ) ;
if ( ! V_77 )
return - V_82 ;
memset ( V_77 , 0 , V_79 ) ;
V_46 -> V_96 = V_77 ;
V_46 -> V_97 = V_78 ;
V_77 += V_98 ;
V_78 += V_98 ;
V_46 -> V_65 = V_77 ;
V_46 -> V_99 = V_78 ;
V_77 += V_80 ;
V_78 += V_80 ;
V_46 -> V_32 = V_77 ;
V_46 -> V_100 = V_78 ;
V_46 -> V_101 = V_102 ;
V_44 -> V_9 = V_46 ;
return F_37 ( V_44 ) ;
}
static int F_38 ( struct V_1 * V_2 , const struct V_103 * V_104 )
{
static int V_105 ;
unsigned int V_106 = V_104 -> V_107 ;
struct V_108 V_109 = V_110 [ V_106 ] ;
const struct V_108 * V_111 [] = { & V_109 , NULL } ;
struct V_76 * V_6 = & V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_4 * V_5 ;
int V_112 , V_113 , V_21 ;
F_21 ( L_9 ) ;
F_39 ( ( int ) V_114 > V_115 ) ;
if ( ! V_105 ++ )
F_3 ( V_116 , & V_2 -> V_6 , L_12 V_117 L_13 ) ;
V_21 = F_40 ( V_2 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_41 ( V_2 , 1 << V_118 , V_119 ) ;
if ( V_21 == - V_120 )
F_42 ( V_2 ) ;
if ( V_21 )
return V_21 ;
V_8 = F_33 ( V_6 , sizeof( * V_8 ) , V_81 ) ;
if ( ! V_8 )
return - V_82 ;
V_8 -> V_14 |= ( unsigned long ) V_109 . V_9 ;
if ( ! ( V_8 -> V_14 & V_121 ) )
F_43 ( V_2 ) ;
V_8 -> V_10 = F_44 ( V_2 ) [ V_118 ] ;
F_45 ( & V_2 -> V_6 , V_8 , 0 , 0 ) ;
if ( V_8 -> V_83 & V_122 )
V_109 . V_14 |= V_123 ;
if ( V_8 -> V_83 & V_124 )
V_109 . V_14 |= V_125 ;
F_46 ( V_8 , & V_109 ) ;
V_112 = F_47 ( F_48 ( V_8 -> V_83 ) , F_49 ( V_8 -> V_126 ) ) ;
V_5 = F_50 ( & V_2 -> V_6 , V_111 , V_112 ) ;
if ( ! V_5 )
return - V_82 ;
V_5 -> V_9 = V_8 ;
if ( ! ( V_8 -> V_83 & V_127 ) || V_128 )
V_5 -> V_14 |= V_129 ;
else
F_51 ( V_91 L_14 ) ;
for ( V_113 = 0 ; V_113 < V_5 -> V_112 ; V_113 ++ ) {
struct V_43 * V_44 = V_5 -> V_130 [ V_113 ] ;
F_52 ( V_44 , V_118 , - 1 , L_15 ) ;
F_52 ( V_44 , V_118 ,
0x100 + V_44 -> V_92 * 0x80 , L_16 ) ;
if ( ! ( V_8 -> V_126 & ( 1 << V_113 ) ) )
V_44 -> V_131 = & V_132 ;
}
V_21 = F_12 ( V_2 , V_8 -> V_83 & V_133 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_9 ( V_5 ) ;
if ( V_21 )
return V_21 ;
F_10 ( V_5 ) ;
F_16 ( V_5 ) ;
F_53 ( V_2 ) ;
return F_54 ( V_5 , V_2 -> V_134 , V_135 , V_136 ,
& V_137 ) ;
}
static int T_8 F_55 ( void )
{
return F_56 ( & V_138 ) ;
}
static void T_9 F_57 ( void )
{
F_58 ( & V_138 ) ;
}
