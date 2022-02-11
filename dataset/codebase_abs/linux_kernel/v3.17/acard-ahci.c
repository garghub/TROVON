static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
void T_2 * V_9 = V_7 -> V_9 ;
T_3 V_10 ;
if ( V_3 . V_11 & V_12 &&
V_7 -> V_13 & V_14 ) {
F_3 ( & V_2 -> V_15 ,
L_1 ) ;
return - V_16 ;
}
if ( V_3 . V_11 & V_17 ) {
V_10 = F_4 ( V_9 + V_18 ) ;
V_10 &= ~ V_19 ;
F_5 ( V_10 , V_9 + V_18 ) ;
F_4 ( V_9 + V_18 ) ;
}
return F_6 ( V_2 , V_3 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_20 ;
V_20 = F_8 ( V_2 ) ;
if ( V_20 )
return V_20 ;
if ( V_2 -> V_15 . V_21 . V_22 . V_11 == V_12 ) {
V_20 = F_9 ( V_5 ) ;
if ( V_20 )
return V_20 ;
F_10 ( V_5 ) ;
}
F_11 ( V_5 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , int V_23 )
{
int V_20 ;
if ( V_23 &&
! F_13 ( V_2 , F_14 ( 64 ) ) ) {
V_20 = F_15 ( V_2 , F_14 ( 64 ) ) ;
if ( V_20 ) {
V_20 = F_15 ( V_2 , F_14 ( 32 ) ) ;
if ( V_20 ) {
F_3 ( & V_2 -> V_15 ,
L_2 ) ;
return V_20 ;
}
}
} else {
V_20 = F_13 ( V_2 , F_14 ( 32 ) ) ;
if ( V_20 ) {
F_3 ( & V_2 -> V_15 , L_3 ) ;
return V_20 ;
}
V_20 = F_15 ( V_2 , F_14 ( 32 ) ) ;
if ( V_20 ) {
F_3 ( & V_2 -> V_15 ,
L_4 ) ;
return V_20 ;
}
}
return 0 ;
}
static void F_16 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_17 ( V_5 -> V_15 ) ;
T_4 V_24 ;
const char * V_25 ;
F_18 ( V_2 , 0x0a , & V_24 ) ;
if ( V_24 == V_26 )
V_25 = L_5 ;
else if ( V_24 == V_27 )
V_25 = L_6 ;
else if ( V_24 == V_28 )
V_25 = L_7 ;
else
V_25 = L_8 ;
F_19 ( V_5 , V_25 ) ;
}
static unsigned int F_20 ( struct V_29 * V_30 , void * V_31 )
{
struct V_32 * V_33 ;
struct V_34 * V_34 = V_31 + V_35 ;
unsigned int V_36 , V_37 = 0 ;
F_21 ( L_9 ) ;
F_22 (qc->sg, sg, qc->n_elem, si) {
T_5 V_38 = F_23 ( V_33 ) ;
T_3 V_39 = F_24 ( V_33 ) ;
V_34 [ V_36 ] . V_38 = F_25 ( V_38 & 0xffffffff ) ;
V_34 [ V_36 ] . V_40 = F_25 ( ( V_38 >> 16 ) >> 16 ) ;
V_34 [ V_36 ] . V_41 = F_25 ( V_39 ) ;
V_37 = V_36 ;
}
V_34 [ V_37 ] . V_41 |= F_25 ( 1 << 31 ) ;
return V_36 ;
}
static void F_26 ( struct V_29 * V_30 )
{
struct V_42 * V_43 = V_30 -> V_43 ;
struct V_44 * V_45 = V_43 -> V_8 ;
int V_46 = F_27 ( V_30 -> V_47 . V_48 ) ;
void * V_31 ;
T_3 V_49 ;
const T_3 V_50 = 5 ;
unsigned int V_51 ;
V_31 = V_45 -> V_31 + V_30 -> V_52 * V_53 ;
F_28 ( & V_30 -> V_47 , V_30 -> V_15 -> V_54 -> V_55 , 1 , V_31 ) ;
if ( V_46 ) {
memset ( V_31 + V_56 , 0 , 32 ) ;
memcpy ( V_31 + V_56 , V_30 -> V_57 , V_30 -> V_15 -> V_58 ) ;
}
V_51 = 0 ;
if ( V_30 -> V_13 & V_59 )
V_51 = F_20 ( V_30 , V_31 ) ;
V_49 = V_50 | ( V_30 -> V_15 -> V_54 -> V_55 << 12 ) ;
if ( V_30 -> V_47 . V_13 & V_60 )
V_49 |= V_61 ;
if ( V_46 )
V_49 |= V_62 | V_63 ;
F_29 ( V_45 , V_30 -> V_52 , V_49 ) ;
}
static bool F_30 ( struct V_29 * V_30 )
{
struct V_44 * V_45 = V_30 -> V_43 -> V_8 ;
T_6 * V_64 = V_45 -> V_64 ;
if ( V_45 -> V_65 )
V_64 += V_30 -> V_15 -> V_54 -> V_55 * V_66 ;
if ( V_30 -> V_47 . V_48 == V_67 && V_30 -> V_68 == V_69 &&
! ( V_30 -> V_13 & V_70 ) ) {
F_31 ( V_64 + V_71 , & V_30 -> V_72 ) ;
V_30 -> V_72 . V_73 = ( V_64 + V_71 ) [ 15 ] ;
} else
F_31 ( V_64 + V_74 , & V_30 -> V_72 ) ;
return true ;
}
static int F_32 ( struct V_42 * V_43 )
{
struct V_6 * V_7 = V_43 -> V_5 -> V_8 ;
struct V_75 * V_15 = V_43 -> V_5 -> V_15 ;
struct V_44 * V_45 ;
void * V_76 ;
T_5 V_77 ;
T_7 V_78 , V_79 ;
V_45 = F_33 ( V_15 , sizeof( * V_45 ) , V_80 ) ;
if ( ! V_45 )
return - V_81 ;
if ( ( V_7 -> V_82 & V_83 ) && F_34 ( V_43 ) ) {
void T_2 * V_84 = F_35 ( V_43 ) ;
T_3 V_85 = F_4 ( V_84 + V_86 ) ;
if ( V_85 & V_87 )
V_45 -> V_88 = true ;
else if ( V_7 -> V_13 & V_89 ) {
F_36 ( V_15 , L_10 ,
V_43 -> V_90 ) ;
V_45 -> V_88 = true ;
} else
F_37 ( V_15 , L_11 ,
V_43 -> V_90 ) ;
}
if ( V_45 -> V_88 ) {
V_78 = V_91 ;
V_79 = V_66 * 16 ;
} else {
V_78 = V_92 ;
V_79 = V_66 ;
}
V_76 = F_38 ( V_15 , V_78 , & V_77 , V_80 ) ;
if ( ! V_76 )
return - V_81 ;
memset ( V_76 , 0 , V_78 ) ;
V_45 -> V_93 = V_76 ;
V_45 -> V_94 = V_77 ;
V_76 += V_95 ;
V_77 += V_95 ;
V_45 -> V_64 = V_76 ;
V_45 -> V_96 = V_77 ;
V_76 += V_79 ;
V_77 += V_79 ;
V_45 -> V_31 = V_76 ;
V_45 -> V_97 = V_77 ;
V_45 -> V_98 = V_99 ;
V_43 -> V_8 = V_45 ;
return F_39 ( V_43 ) ;
}
static int F_40 ( struct V_1 * V_2 , const struct V_100 * V_101 )
{
unsigned int V_102 = V_101 -> V_103 ;
struct V_104 V_105 = V_106 [ V_102 ] ;
const struct V_104 * V_107 [] = { & V_105 , NULL } ;
struct V_75 * V_15 = & V_2 -> V_15 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
int V_108 , V_109 , V_20 ;
F_21 ( L_9 ) ;
F_41 ( ( int ) V_110 > V_111 ) ;
F_42 ( & V_2 -> V_15 , V_112 ) ;
V_20 = F_43 ( V_2 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_44 ( V_2 , 1 << V_113 , V_114 ) ;
if ( V_20 == - V_115 )
F_45 ( V_2 ) ;
if ( V_20 )
return V_20 ;
V_7 = F_33 ( V_15 , sizeof( * V_7 ) , V_80 ) ;
if ( ! V_7 )
return - V_81 ;
V_7 -> V_13 |= ( unsigned long ) V_105 . V_8 ;
if ( ! ( V_7 -> V_13 & V_116 ) )
F_46 ( V_2 ) ;
V_7 -> V_9 = F_47 ( V_2 ) [ V_113 ] ;
F_48 ( & V_2 -> V_15 , V_7 ) ;
if ( V_7 -> V_82 & V_117 )
V_105 . V_13 |= V_118 ;
if ( V_7 -> V_82 & V_119 )
V_105 . V_13 |= V_120 ;
F_49 ( V_7 , & V_105 ) ;
V_108 = F_50 ( F_51 ( V_7 -> V_82 ) , F_52 ( V_7 -> V_121 ) ) ;
V_5 = F_53 ( & V_2 -> V_15 , V_107 , V_108 ) ;
if ( ! V_5 )
return - V_81 ;
V_5 -> V_8 = V_7 ;
if ( ! ( V_7 -> V_82 & V_122 ) || V_123 )
V_5 -> V_13 |= V_124 ;
else
F_54 ( V_125 L_12 ) ;
for ( V_109 = 0 ; V_109 < V_5 -> V_108 ; V_109 ++ ) {
struct V_42 * V_43 = V_5 -> V_126 [ V_109 ] ;
F_55 ( V_43 , V_113 , - 1 , L_13 ) ;
F_55 ( V_43 , V_113 ,
0x100 + V_43 -> V_90 * 0x80 , L_14 ) ;
if ( ! ( V_7 -> V_121 & ( 1 << V_109 ) ) )
V_43 -> V_127 = & V_128 ;
}
V_20 = F_12 ( V_2 , V_7 -> V_82 & V_129 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_9 ( V_5 ) ;
if ( V_20 )
return V_20 ;
F_10 ( V_5 ) ;
F_16 ( V_5 ) ;
F_56 ( V_2 ) ;
return F_57 ( V_5 , V_2 -> V_130 , V_131 , V_132 ,
& V_133 ) ;
}
