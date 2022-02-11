static inline unsigned int F_1 ( unsigned int V_1 ,
void T_1 * V_2 )
{
if ( F_2 ( V_1 ) ) {
F_3 ( L_1 ) ;
return 0 ;
}
if ( F_4 ( V_1 >= V_3 ) ) {
F_3 ( L_2 , V_1 ) ;
return 0 ;
}
if ( F_4 ( ( F_5 ( V_2 + V_4 ) ) & ( 1 << V_1 ) ) ) {
F_3 ( L_3 , V_1 ) ;
return 0 ;
}
return V_1 ;
}
static void F_6 ( struct V_5 * V_6 ,
unsigned int V_1 , T_2 V_7 ,
T_2 V_8 , T_3 V_9 ,
T_3 V_10 )
{
T_4 V_11 ;
V_11 = V_6 -> V_12 +
V_1 * V_13 ;
V_6 -> V_14 [ V_1 ] . V_15 = F_7 ( V_11 ) ;
V_6 -> V_14 [ V_1 ] . V_16 =
F_7 ( ( V_9 << 16 ) | ( V_10 << 2 ) ) ;
V_6 -> V_14 [ V_1 ] . V_17 = F_7 ( V_8 & ~ 0x03 ) ;
V_6 -> V_14 [ V_1 ] . V_7 = F_7 ( V_7 | ( V_1 & 0x1F ) ) ;
F_8 ( L_4 ,
V_6 -> V_14 [ V_1 ] . V_15 ,
V_6 -> V_14 [ V_1 ] . V_16 ,
V_6 -> V_14 [ V_1 ] . V_17 , V_6 -> V_14 [ V_1 ] . V_7 ) ;
}
static unsigned int F_9 ( struct V_18 * V_19 , void * V_20 ,
T_2 * V_17 , T_4 V_21 ,
int V_22 )
{
struct V_23 * V_24 ;
unsigned int V_9 = 0 ;
T_2 V_25 = 0 ;
struct V_26 * V_27 = (struct V_26 * ) & ( (struct V_28 * )
V_20 ) -> V_29 ;
struct V_26 * V_30 = NULL ;
unsigned V_31 = 0 ;
T_4 V_32 ;
unsigned int V_33 ;
F_8 ( L_5 , V_20 , V_27 ) ;
V_32 = V_21 +
V_34 + V_35 * 16 ;
F_10 (qc->sg, sg, qc->n_elem, si) {
T_4 V_36 = F_11 ( V_24 ) ;
T_2 V_37 = F_12 ( V_24 ) ;
F_8 ( L_6 ,
( unsigned long long ) V_36 , V_37 ) ;
if ( V_36 & 0x03 )
F_13 ( V_19 -> V_38 , L_7 ,
( unsigned long long ) V_36 ) ;
if ( V_37 & 0x03 )
F_13 ( V_19 -> V_38 , L_8 ,
V_37 ) ;
if ( V_9 == ( V_35 - 1 ) &&
F_14 ( V_24 ) != NULL ) {
F_8 ( L_9 ) ;
V_30 = V_27 ;
V_27 -> V_39 = F_7 ( V_32 ) ;
V_31 = 0 ;
++ V_27 ;
++ V_9 ;
}
V_25 += V_37 ;
V_27 -> V_39 = F_7 ( V_36 ) ;
V_27 -> V_40 = F_7 ( V_22 | ( V_37 & ~ 0x03 ) ) ;
F_8 ( L_10 ,
V_25 , V_27 -> V_39 , V_27 -> V_40 ) ;
++ V_9 ;
++ V_27 ;
if ( V_30 )
V_31 += V_37 ;
}
if ( V_30 ) {
V_30 -> V_40 =
F_7 ( ( V_41 |
V_22 |
( V_31 & ~ 0x03 ) ) ) ;
}
* V_17 = V_25 ;
return V_9 ;
}
static void F_15 ( struct V_18 * V_19 )
{
struct V_42 * V_38 = V_19 -> V_38 ;
struct V_5 * V_6 = V_38 -> V_43 ;
struct V_44 * V_45 = V_38 -> V_46 -> V_43 ;
void T_1 * V_2 = V_45 -> V_2 ;
unsigned int V_1 = F_1 ( V_19 -> V_1 , V_2 ) ;
struct V_28 * V_47 ;
T_2 V_7 = V_48 | V_49 ;
T_2 V_9 = 0 ;
T_2 V_25 = 0 ;
T_4 V_50 ;
V_47 = (struct V_28 * ) V_6 -> V_51 + V_1 ;
V_50 = V_6 -> V_12 + V_1 * V_13 ;
F_16 ( & V_19 -> V_52 , V_19 -> V_53 -> V_54 -> V_55 , 1 , ( T_3 * ) & V_47 -> V_56 ) ;
F_8 ( L_11 ,
V_47 -> V_56 [ 0 ] , V_47 -> V_56 [ 1 ] , V_47 -> V_56 [ 2 ] ) ;
if ( V_19 -> V_52 . V_57 == V_58 ) {
F_8 ( L_12 ,
V_47 -> V_56 [ 3 ] , V_47 -> V_56 [ 11 ] ) ;
}
if ( F_17 ( V_19 -> V_52 . V_57 ) ) {
V_7 |= V_59 ;
memset ( ( void * ) & V_47 -> V_60 , 0 , 32 ) ;
memcpy ( ( void * ) & V_47 -> V_60 , V_19 -> V_61 , V_19 -> V_53 -> V_62 ) ;
}
if ( V_19 -> V_63 & V_64 )
V_9 = F_9 ( V_19 , ( void * ) V_47 ,
& V_25 , V_50 ,
V_45 -> V_22 ) ;
if ( V_19 -> V_52 . V_57 == V_58 )
V_7 |= V_65 ;
F_6 ( V_6 , V_1 , V_7 , V_25 ,
V_9 , 5 ) ;
F_8 ( L_13 ,
V_7 , V_25 , V_9 ) ;
}
static unsigned int F_18 ( struct V_18 * V_19 )
{
struct V_42 * V_38 = V_19 -> V_38 ;
struct V_44 * V_45 = V_38 -> V_46 -> V_43 ;
void T_1 * V_2 = V_45 -> V_2 ;
unsigned int V_1 = F_1 ( V_19 -> V_1 , V_2 ) ;
F_8 ( L_14 ,
F_5 ( V_4 + V_2 ) ,
F_5 ( V_66 + V_2 ) ,
F_5 ( V_67 + V_2 ) , F_5 ( V_68 + V_2 ) ) ;
F_19 ( V_19 -> V_53 -> V_54 -> V_55 , V_69 + V_2 ) ;
F_19 ( 1 << V_1 , V_4 + V_2 ) ;
F_8 ( L_15 ,
V_1 , F_5 ( V_4 + V_2 ) , F_5 ( V_66 + V_2 ) ) ;
F_8 ( L_16 ,
F_5 ( V_67 + V_2 ) ,
F_5 ( V_70 + V_2 ) ,
F_5 ( V_68 + V_2 ) ,
F_5 ( V_71 + V_45 -> V_72 ) ) ;
return 0 ;
}
static bool F_20 ( struct V_18 * V_19 )
{
struct V_5 * V_6 = V_19 -> V_38 -> V_43 ;
struct V_44 * V_45 = V_19 -> V_38 -> V_46 -> V_43 ;
void T_1 * V_2 = V_45 -> V_2 ;
unsigned int V_1 = F_1 ( V_19 -> V_1 , V_2 ) ;
struct V_28 * V_47 ;
V_47 = V_6 -> V_51 + V_1 ;
F_21 ( V_47 -> V_73 , & V_19 -> V_74 ) ;
return true ;
}
static int F_22 ( struct V_75 * V_54 ,
unsigned int V_76 , T_2 V_77 )
{
struct V_44 * V_45 = V_54 -> V_38 -> V_46 -> V_43 ;
void T_1 * V_78 = V_45 -> V_78 ;
unsigned int V_79 ;
switch ( V_76 ) {
case V_80 :
case V_81 :
case V_82 :
case V_83 :
V_79 = V_76 ;
break;
default:
return - V_84 ;
}
F_8 ( L_17 , V_79 ) ;
F_19 ( V_77 , V_78 + ( V_79 * 4 ) ) ;
return 0 ;
}
static int F_23 ( struct V_75 * V_54 ,
unsigned int V_76 , T_2 * V_77 )
{
struct V_44 * V_45 = V_54 -> V_38 -> V_46 -> V_43 ;
void T_1 * V_78 = V_45 -> V_78 ;
unsigned int V_79 ;
switch ( V_76 ) {
case V_80 :
case V_81 :
case V_82 :
case V_83 :
V_79 = V_76 ;
break;
default:
return - V_84 ;
}
F_8 ( L_18 , V_79 ) ;
* V_77 = F_5 ( V_78 + ( V_79 * 4 ) ) ;
return 0 ;
}
static void F_24 ( struct V_42 * V_38 )
{
struct V_44 * V_45 = V_38 -> V_46 -> V_43 ;
void T_1 * V_2 = V_45 -> V_2 ;
T_2 V_85 ;
F_8 ( L_19 ,
F_5 ( V_4 + V_2 ) ,
F_5 ( V_66 + V_2 ) ,
F_5 ( V_67 + V_2 ) , F_5 ( V_70 + V_2 ) ) ;
F_8 ( L_20 ,
F_5 ( V_45 -> V_72 + V_71 ) ) ;
V_85 = F_5 ( V_2 + V_86 ) ;
F_19 ( ( V_85 & ~ 0x3F ) , V_2 + V_86 ) ;
F_8 ( L_21 ,
F_5 ( V_2 + V_86 ) , F_5 ( V_2 + V_87 ) ) ;
}
static void F_25 ( struct V_42 * V_38 )
{
struct V_44 * V_45 = V_38 -> V_46 -> V_43 ;
void T_1 * V_2 = V_45 -> V_2 ;
T_2 V_85 ;
V_85 = F_5 ( V_2 + V_87 ) ;
F_8 ( L_22 , ( V_85 & 0x3F ) ) ;
if ( V_85 & 0x3F )
F_19 ( ( V_85 & 0x3F ) , V_2 + V_87 ) ;
V_85 = F_5 ( V_2 + V_86 ) ;
F_19 ( ( V_85 | V_88 ) , V_2 + V_86 ) ;
F_8 ( L_23 ,
F_5 ( V_2 + V_86 ) , F_5 ( V_2 + V_87 ) ) ;
}
static void F_26 ( struct V_42 * V_38 )
{
struct V_44 * V_45 = V_38 -> V_46 -> V_43 ;
void T_1 * V_2 = V_45 -> V_2 ;
T_2 V_85 ;
V_85 = F_5 ( V_2 + V_86 ) ;
F_19 ( ( V_85 | V_89 ) , V_2 + V_86 ) ;
}
static void F_27 ( struct V_42 * V_38 )
{
struct V_44 * V_45 = V_38 -> V_46 -> V_43 ;
void T_1 * V_2 = V_45 -> V_2 ;
T_2 V_85 ;
V_85 = F_5 ( V_2 + V_86 ) ;
V_85 &= ~ V_89 ;
F_19 ( V_85 , V_2 + V_86 ) ;
V_85 = F_5 ( V_2 + V_86 ) ;
F_19 ( ( V_85 | V_88 ) , V_2 + V_86 ) ;
}
static int F_28 ( struct V_42 * V_38 )
{
struct V_90 * V_53 = V_38 -> V_46 -> V_53 ;
struct V_5 * V_6 ;
void * V_91 ;
T_4 V_92 ;
struct V_44 * V_45 = V_38 -> V_46 -> V_43 ;
void T_1 * V_2 = V_45 -> V_2 ;
T_2 V_85 ;
V_6 = F_29 ( sizeof( * V_6 ) , V_93 ) ;
if ( ! V_6 )
return - V_94 ;
V_91 = F_30 ( V_53 , V_95 , & V_92 ,
V_93 ) ;
if ( ! V_91 ) {
F_31 ( V_6 ) ;
return - V_94 ;
}
memset ( V_91 , 0 , V_95 ) ;
V_6 -> V_14 = V_91 ;
V_6 -> V_96 = V_92 ;
V_91 += V_97 ;
V_92 += V_97 ;
V_6 -> V_51 = V_91 ;
V_6 -> V_12 = V_92 ;
V_38 -> V_43 = V_6 ;
F_8 ( L_24 ,
V_6 -> V_96 , V_6 -> V_12 ) ;
F_19 ( V_6 -> V_96 & 0xffffffff , V_2 + V_98 ) ;
V_85 = F_5 ( V_2 + V_86 ) ;
F_19 ( ( V_85 | V_99 ) , V_2 + V_86 ) ;
F_8 ( L_25 , F_5 ( V_2 + V_87 ) ) ;
F_8 ( L_26 , F_5 ( V_2 + V_86 ) ) ;
F_8 ( L_27 , F_5 ( V_2 + V_98 ) ) ;
#ifdef F_32
F_23 ( & V_38 -> V_54 , V_82 , & V_85 ) ;
V_85 &= ~ ( 0xF << 4 ) ;
V_85 |= ( 0x1 << 4 ) ;
F_22 ( & V_38 -> V_54 , V_82 , V_85 ) ;
F_23 ( & V_38 -> V_54 , V_82 , & V_85 ) ;
F_33 ( V_53 , L_28 , V_85 ) ;
#endif
return 0 ;
}
static void F_34 ( struct V_42 * V_38 )
{
struct V_90 * V_53 = V_38 -> V_46 -> V_53 ;
struct V_5 * V_6 = V_38 -> V_43 ;
struct V_44 * V_45 = V_38 -> V_46 -> V_43 ;
void T_1 * V_2 = V_45 -> V_2 ;
T_2 V_85 ;
V_85 = F_5 ( V_2 + V_86 ) ;
V_85 &= ~ V_99 ;
V_85 |= V_100 ;
F_19 ( V_85 , V_2 + V_86 ) ;
F_35 ( V_38 , V_2 + V_87 , V_101 , V_101 , 1 , 1 ) ;
V_38 -> V_43 = NULL ;
F_36 ( V_53 , V_95 ,
V_6 -> V_14 , V_6 -> V_96 ) ;
F_31 ( V_6 ) ;
}
static unsigned int F_37 ( struct V_42 * V_38 )
{
struct V_44 * V_45 = V_38 -> V_46 -> V_43 ;
void T_1 * V_2 = V_45 -> V_2 ;
struct V_102 V_52 ;
T_2 V_85 ;
V_85 = F_5 ( V_2 + V_103 ) ;
F_8 ( L_29 , V_85 ) ;
F_8 ( L_25 , F_5 ( V_2 + V_87 ) ) ;
F_8 ( L_26 , F_5 ( V_2 + V_86 ) ) ;
V_52 . V_104 = ( V_85 >> 24 ) & 0xff ;
V_52 . V_105 = ( V_85 >> 16 ) & 0xff ;
V_52 . V_106 = ( V_85 >> 8 ) & 0xff ;
V_52 . V_107 = V_85 & 0xff ;
return F_38 ( & V_52 ) ;
}
static int F_39 ( struct V_75 * V_54 , unsigned int * V_108 ,
unsigned long V_109 )
{
struct V_42 * V_38 = V_54 -> V_38 ;
struct V_44 * V_45 = V_38 -> V_46 -> V_43 ;
void T_1 * V_2 = V_45 -> V_2 ;
T_2 V_85 ;
int V_110 = 0 ;
unsigned long V_111 ;
F_3 ( L_30 ) ;
V_112:
V_85 = F_5 ( V_2 + V_86 ) ;
V_85 &= ~ V_99 ;
F_19 ( V_85 , V_2 + V_86 ) ;
V_85 = F_35 ( V_38 , V_2 + V_87 , V_101 , V_101 ,
1 , 500 ) ;
if ( V_85 & V_101 ) {
F_13 ( V_38 , L_31 , V_110 ) ;
V_110 ++ ;
if ( V_110 == 2 )
goto V_113;
else
goto V_112;
}
F_3 ( L_32 ) ;
F_8 ( L_25 , F_5 ( V_2 + V_87 ) ) ;
F_8 ( L_26 , F_5 ( V_2 + V_86 ) ) ;
F_40 ( V_38 , 1 ) ;
V_85 = F_5 ( V_2 + V_86 ) ;
V_85 |= ( V_99 | V_114 ) ;
V_85 |= V_89 ;
F_19 ( V_85 , V_2 + V_86 ) ;
V_85 = F_35 ( V_38 , V_2 + V_87 , V_101 , 0 , 1 , 500 ) ;
if ( ! ( V_85 & V_101 ) ) {
F_13 ( V_38 , L_33 ) ;
goto V_113;
}
F_3 ( L_34 ) ;
F_8 ( L_25 , F_5 ( V_2 + V_87 ) ) ;
F_8 ( L_26 , F_5 ( V_2 + V_86 ) ) ;
V_85 = F_35 ( V_38 , V_2 + V_87 , 0xFF , 0 , 1 , 500 ) ;
if ( ( ! ( V_85 & 0x10 ) ) || F_41 ( V_54 ) ) {
F_42 ( V_38 , L_35 ,
F_5 ( V_2 + V_87 ) ) ;
* V_108 = V_115 ;
return 0 ;
}
V_111 = V_116 ;
V_85 = F_35 ( V_38 , V_2 + V_87 , 0xFF , 0x10 ,
500 , F_43 ( V_109 - V_111 ) ) ;
if ( ( V_85 & 0xFF ) != 0x18 ) {
F_42 ( V_38 , L_36 ) ;
* V_108 = V_115 ;
goto V_117;
} else {
F_44 ( V_38 , L_37 ,
F_43 ( V_116 - V_111 ) ) ;
* V_108 = F_37 ( V_38 ) ;
return 0 ;
}
V_117:
return - V_118 ;
V_113:
return - V_119 ;
}
static int F_45 ( struct V_75 * V_54 , unsigned int * V_108 ,
unsigned long V_109 )
{
struct V_42 * V_38 = V_54 -> V_38 ;
struct V_5 * V_6 = V_38 -> V_43 ;
struct V_44 * V_45 = V_38 -> V_46 -> V_43 ;
void T_1 * V_2 = V_45 -> V_2 ;
int V_55 = F_46 ( V_54 ) ;
T_2 V_85 ;
struct V_102 V_52 ;
T_3 * V_56 ;
T_2 V_120 ;
F_3 ( L_38 ) ;
if ( F_41 ( V_54 ) ) {
F_3 ( L_39 ) ;
* V_108 = V_115 ;
return 0 ;
}
F_3 ( L_40 ) ;
F_47 ( V_54 -> V_90 , & V_52 ) ;
V_56 = ( T_3 * ) & V_6 -> V_51 -> V_56 ;
F_6 ( V_6 , 0 ,
V_121 | V_48 | V_49 , 0 , 0 , 5 ) ;
V_52 . V_122 |= V_123 ;
F_16 ( & V_52 , V_55 , 0 , V_56 ) ;
F_3 ( L_41 ,
V_56 [ 0 ] , V_56 [ 1 ] , V_56 [ 2 ] , V_56 [ 3 ] ) ;
F_3 ( L_42 ,
F_5 ( V_4 + V_2 ) ,
F_5 ( V_66 + V_2 ) , F_5 ( V_68 + V_2 ) ) ;
F_19 ( 0xFFFF , V_68 + V_2 ) ;
if ( V_55 != V_124 )
F_19 ( V_55 , V_69 + V_2 ) ;
F_19 ( 1 , V_4 + V_2 ) ;
V_85 = F_35 ( V_38 , V_4 + V_2 , 0x1 , 0x1 , 1 , 5000 ) ;
if ( V_85 & 0x1 ) {
F_42 ( V_38 , L_43 ) ;
F_3 ( L_44 ,
F_5 ( V_4 + V_2 ) ,
F_5 ( V_66 + V_2 ) , F_5 ( V_68 + V_2 ) ) ;
F_23 ( & V_38 -> V_54 , V_81 , & V_120 ) ;
F_3 ( L_25 , F_5 ( V_2 + V_87 ) ) ;
F_3 ( L_26 , F_5 ( V_2 + V_86 ) ) ;
F_3 ( L_45 , V_120 ) ;
goto V_113;
}
F_40 ( V_38 , 1 ) ;
F_6 ( V_6 , 0 , V_48 | V_49 ,
0 , 0 , 5 ) ;
V_52 . V_122 &= ~ V_123 ;
F_16 ( & V_52 , V_55 , 0 , V_56 ) ;
if ( V_55 != V_124 )
F_19 ( V_55 , V_69 + V_2 ) ;
F_19 ( 1 , V_4 + V_2 ) ;
F_40 ( V_38 , 150 ) ;
F_19 ( 0x01 , V_68 + V_2 ) ;
F_3 ( L_46 ) ;
* V_108 = V_115 ;
if ( F_48 ( V_54 ) ) {
* V_108 = F_37 ( V_38 ) ;
F_3 ( L_47 , * V_108 ) ;
F_8 ( L_48 , F_5 ( V_2 + V_68 ) ) ;
F_8 ( L_49 , F_5 ( V_2 + V_67 ) ) ;
}
return 0 ;
V_113:
return - V_119 ;
}
static void F_49 ( struct V_42 * V_38 )
{
F_3 ( L_50 ) ;
F_50 ( V_38 ) ;
}
static void F_51 ( struct V_18 * V_19 )
{
if ( V_19 -> V_63 & V_125 )
V_19 -> V_126 |= V_127 ;
if ( V_19 -> V_126 ) {
}
}
static void F_52 ( struct V_42 * V_38 )
{
struct V_44 * V_45 = V_38 -> V_46 -> V_43 ;
void T_1 * V_2 = V_45 -> V_2 ;
T_2 V_128 , V_129 = 0 , V_130 = 0 , V_131 = 0 ;
unsigned int V_126 = 0 , V_132 = 0 ;
int V_133 = 0 , abort = 0 ;
struct V_75 * V_54 = NULL ;
struct V_18 * V_19 = NULL ;
struct V_134 * V_135 ;
V_128 = F_5 ( V_2 + V_87 ) ;
V_130 = F_5 ( V_2 + V_67 ) ;
V_54 = & V_38 -> V_54 ;
V_135 = & V_54 -> V_136 ;
F_53 ( V_135 ) ;
F_23 ( & V_38 -> V_54 , V_81 , & V_131 ) ;
if ( F_4 ( V_131 & 0xFFFF0000 ) )
F_22 ( & V_38 -> V_54 , V_81 , V_131 ) ;
F_3 ( L_51 ,
V_128 , V_130 , F_5 ( V_2 + V_70 ) , V_131 ) ;
if ( V_128 & V_137 ) {
V_135 -> V_126 |= V_138 ;
V_135 -> V_132 |= V_139 ;
V_133 = 1 ;
}
if ( V_128 & V_140 )
F_54 ( V_38 ) ;
if ( V_128 & V_141 ) {
F_3 ( L_52 ) ;
F_55 ( V_135 ) ;
F_56 ( V_135 , L_53 , L_54 ) ;
V_133 = 1 ;
}
if ( V_130 ) {
abort = 1 ;
F_3 ( L_55 ,
F_5 ( V_2 + V_67 ) , F_5 ( V_2 + V_70 ) ) ;
if ( V_38 -> V_142 ) {
unsigned int V_143 ;
V_129 = F_5 ( V_2 + V_70 ) ;
F_19 ( V_129 , V_2 + V_70 ) ;
F_19 ( V_130 , V_2 + V_67 ) ;
V_143 = F_57 ( V_129 ) - 1 ;
if ( V_143 < V_38 -> V_142 && V_129 != 0 ) {
V_54 = & V_38 -> V_144 [ V_143 ] ;
V_135 = & V_54 -> V_136 ;
V_19 = F_58 ( V_38 , V_54 -> V_145 ) ;
V_126 |= V_146 ;
} else {
V_126 |= V_147 ;
V_132 |= V_148 ;
V_133 = 1 ;
}
} else {
V_129 = F_5 ( V_2 + V_70 ) ;
F_19 ( V_129 , V_2 + V_70 ) ;
F_19 ( V_130 , V_2 + V_67 ) ;
V_19 = F_58 ( V_38 , V_54 -> V_145 ) ;
V_126 |= V_146 ;
}
}
if ( V_19 )
V_19 -> V_126 |= V_126 ;
else
V_135 -> V_126 |= V_126 ;
V_135 -> V_132 |= V_132 ;
if ( V_133 )
F_59 ( V_38 ) ;
else if ( abort ) {
if ( V_19 )
F_60 ( V_19 -> V_53 -> V_54 ) ;
else
F_61 ( V_38 ) ;
}
}
static void F_62 ( struct V_42 * V_38 )
{
struct V_44 * V_45 = V_38 -> V_46 -> V_43 ;
void T_1 * V_2 = V_45 -> V_2 ;
T_2 V_128 , V_149 = 0 ;
struct V_18 * V_19 ;
T_2 V_131 ;
V_128 = F_5 ( V_2 + V_87 ) ;
F_23 ( & V_38 -> V_54 , V_81 , & V_131 ) ;
if ( F_4 ( V_131 & 0xFFFF0000 ) ) {
F_3 ( L_56 , V_131 ) ;
F_52 ( V_38 ) ;
}
if ( F_4 ( V_128 & V_150 ) ) {
F_3 ( L_57 ) ;
F_52 ( V_38 ) ;
return;
}
V_149 = F_5 ( V_2 + V_68 ) ;
F_8 ( L_58 ) ;
F_8 ( L_59 ,
V_149 ,
F_5 ( V_2 + V_66 ) ,
F_5 ( V_2 + V_67 ) ,
F_5 ( V_2 + V_4 ) ,
V_38 -> V_151 ) ;
if ( V_149 & V_38 -> V_151 ) {
int V_110 ;
F_19 ( V_149 , V_2 + V_68 ) ;
F_3 ( L_58 ) ;
F_3 ( L_60 ,
V_149 , F_5 ( V_2 + V_66 ) ,
F_5 ( V_2 + V_67 ) ) ;
for ( V_110 = 0 ; V_110 < V_3 ; V_110 ++ ) {
if ( V_149 & ( 1 << V_110 ) )
F_3
( L_61 ,
V_110 , F_5 ( V_2 + V_68 ) ,
F_5 ( V_2 + V_66 ) ) ;
}
F_63 ( V_38 , V_38 -> V_151 ^ V_149 ) ;
return;
} else if ( ( V_38 -> V_151 & ( 1 << V_152 ) ) ) {
F_19 ( 1 , V_2 + V_68 ) ;
V_19 = F_58 ( V_38 , V_152 ) ;
F_3 ( L_62 ,
F_5 ( V_2 + V_68 ) ) ;
if ( V_19 ) {
F_64 ( V_19 ) ;
}
} else {
F_3 ( L_63 ,
F_5 ( V_2 + V_68 ) ) ;
F_19 ( V_149 , V_2 + V_68 ) ;
return;
}
}
static T_5 F_65 ( int V_153 , void * V_154 )
{
struct V_155 * V_46 = V_154 ;
struct V_44 * V_45 = V_46 -> V_43 ;
void T_1 * V_2 = V_45 -> V_2 ;
T_2 V_156 ;
unsigned V_157 = 0 ;
struct V_42 * V_38 ;
V_156 = F_5 ( V_2 + V_87 ) ;
V_156 &= 0x3F ;
F_3 ( L_64 , V_156 ) ;
if ( ! V_156 )
return V_158 ;
F_66 ( & V_46 -> V_159 ) ;
V_38 = V_46 -> V_160 [ 0 ] ;
if ( V_38 ) {
F_62 ( V_38 ) ;
} else {
F_33 ( V_46 -> V_53 , L_65 ) ;
}
F_19 ( V_156 , V_2 + V_87 ) ;
V_157 = 1 ;
F_67 ( & V_46 -> V_159 ) ;
return F_68 ( V_157 ) ;
}
static int F_69 ( struct V_155 * V_46 )
{
struct V_44 * V_45 = V_46 -> V_43 ;
void T_1 * V_2 = V_45 -> V_2 ;
T_2 V_85 ;
V_85 = F_5 ( V_2 + V_86 ) ;
F_19 ( V_85 & ~ V_161 , V_2 + V_86 ) ;
V_85 = F_5 ( V_2 + V_87 ) ;
if ( V_85 & 0x3F )
F_19 ( ( V_85 & 0x3F ) , V_2 + V_87 ) ;
V_85 = F_5 ( V_2 + V_86 ) ;
F_19 ( ( V_85 & ~ 0x3F ) , V_2 + V_86 ) ;
F_3 ( L_66 , F_5 ( V_2 + V_162 ) ) ;
F_19 ( 0x01000000 , V_2 + V_162 ) ;
F_19 ( 0x00000FFFF , V_2 + V_67 ) ;
F_19 ( 0x00000FFFF , V_2 + V_70 ) ;
F_3 ( L_25 , F_5 ( V_2 + V_87 ) ) ;
F_3 ( L_26 , F_5 ( V_2 + V_86 ) ) ;
return 0 ;
}
static int F_70 ( struct V_163 * V_164 )
{
int V_165 = - V_166 ;
void T_1 * V_2 = NULL ;
void T_1 * V_78 = NULL ;
void T_1 * V_72 = NULL ;
struct V_44 * V_45 = NULL ;
int V_153 ;
struct V_155 * V_46 ;
T_2 V_85 ;
struct F_44 V_167 = V_168 [ 0 ] ;
const struct F_44 * V_169 [] = { & V_167 , NULL } ;
F_71 ( & V_164 -> V_53 , L_67 ) ;
V_2 = F_72 ( V_164 -> V_53 . V_170 , 0 ) ;
if ( ! V_2 )
goto V_171;
V_78 = V_2 + 0x100 ;
V_72 = V_2 + 0x140 ;
if ( ! F_73 ( V_164 -> V_53 . V_170 , L_68 ) ) {
V_85 = F_5 ( V_72 + V_172 ) ;
V_85 = V_85 & 0xffffffe0 ;
F_19 ( V_85 | V_173 , V_72 + V_172 ) ;
}
F_3 ( L_69 , F_5 ( V_72 + V_172 ) ) ;
F_3 ( L_70 , sizeof( struct V_28 ) ) ;
F_3 ( L_71 , V_13 ) ;
V_45 = F_29 ( sizeof( struct V_44 ) , V_93 ) ;
if ( ! V_45 )
goto V_171;
V_45 -> V_2 = V_2 ;
V_45 -> V_78 = V_78 ;
V_45 -> V_72 = V_72 ;
V_153 = F_74 ( V_164 -> V_53 . V_170 , 0 ) ;
if ( V_153 < 0 ) {
F_75 ( & V_164 -> V_53 , L_72 ) ;
goto V_171;
}
V_45 -> V_153 = V_153 ;
if ( F_73 ( V_164 -> V_53 . V_170 , L_73 ) )
V_45 -> V_22 = V_174 ;
else
V_45 -> V_22 = V_175 ;
V_46 = F_76 ( & V_164 -> V_53 , V_169 , V_176 ) ;
V_46 -> V_43 = V_45 ;
F_69 ( V_46 ) ;
F_77 ( V_46 , V_153 , F_65 , V_177 ,
& V_178 ) ;
F_78 ( & V_164 -> V_53 , V_46 ) ;
return 0 ;
V_171:
if ( V_2 )
F_79 ( V_2 ) ;
if ( V_45 )
F_31 ( V_45 ) ;
return V_165 ;
}
static int F_80 ( struct V_163 * V_164 )
{
struct V_155 * V_46 = F_81 ( & V_164 -> V_53 ) ;
struct V_44 * V_45 = V_46 -> V_43 ;
F_82 ( V_46 ) ;
F_78 ( & V_164 -> V_53 , NULL ) ;
F_83 ( V_45 -> V_153 ) ;
F_79 ( V_45 -> V_2 ) ;
F_31 ( V_45 ) ;
return 0 ;
}
static int F_84 ( struct V_163 * V_179 , T_6 V_180 )
{
struct V_155 * V_46 = F_81 ( & V_179 -> V_53 ) ;
return F_85 ( V_46 , V_180 ) ;
}
static int F_86 ( struct V_163 * V_179 )
{
struct V_155 * V_46 = F_81 ( & V_179 -> V_53 ) ;
struct V_44 * V_45 = V_46 -> V_43 ;
int V_181 ;
void T_1 * V_2 = V_45 -> V_2 ;
struct V_42 * V_38 = V_46 -> V_160 [ 0 ] ;
struct V_5 * V_6 = V_38 -> V_43 ;
V_181 = F_69 ( V_46 ) ;
if ( V_181 ) {
F_75 ( & V_179 -> V_53 , L_74 ) ;
return V_181 ;
}
F_19 ( V_6 -> V_96 & 0xffffffff , V_2 + V_98 ) ;
F_19 ( ( F_5 ( V_2 + V_86 )
| V_99
| V_114
| V_89 ) ,
V_2 + V_86 ) ;
F_87 ( V_46 ) ;
return 0 ;
}
