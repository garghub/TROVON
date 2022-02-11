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
F_13 ( V_19 -> V_38 , V_39 ,
L_7 ,
( unsigned long long ) V_36 ) ;
if ( V_37 & 0x03 )
F_13 ( V_19 -> V_38 , V_39 ,
L_8 , V_37 ) ;
if ( V_9 == ( V_35 - 1 ) &&
F_14 ( V_24 ) != NULL ) {
F_8 ( L_9 ) ;
V_30 = V_27 ;
V_27 -> V_40 = F_7 ( V_32 ) ;
V_31 = 0 ;
++ V_27 ;
++ V_9 ;
}
V_25 += V_37 ;
V_27 -> V_40 = F_7 ( V_36 ) ;
V_27 -> V_41 = F_7 ( V_22 | ( V_37 & ~ 0x03 ) ) ;
F_8 ( L_10 ,
V_25 , V_27 -> V_40 , V_27 -> V_41 ) ;
++ V_9 ;
++ V_27 ;
if ( V_30 )
V_31 += V_37 ;
}
if ( V_30 ) {
V_30 -> V_41 =
F_7 ( ( V_42 |
V_22 |
( V_31 & ~ 0x03 ) ) ) ;
}
* V_17 = V_25 ;
return V_9 ;
}
static void F_15 ( struct V_18 * V_19 )
{
struct V_43 * V_38 = V_19 -> V_38 ;
struct V_5 * V_6 = V_38 -> V_44 ;
struct V_45 * V_46 = V_38 -> V_47 -> V_44 ;
void T_1 * V_2 = V_46 -> V_2 ;
unsigned int V_1 = F_1 ( V_19 -> V_1 , V_2 ) ;
struct V_28 * V_48 ;
T_2 V_7 = V_49 | V_50 ;
T_2 V_9 = 0 ;
T_2 V_25 = 0 ;
T_4 V_51 ;
V_48 = (struct V_28 * ) V_6 -> V_52 + V_1 ;
V_51 = V_6 -> V_12 + V_1 * V_13 ;
F_16 ( & V_19 -> V_53 , V_19 -> V_54 -> V_55 -> V_56 , 1 , ( T_3 * ) & V_48 -> V_57 ) ;
F_8 ( L_11 ,
V_48 -> V_57 [ 0 ] , V_48 -> V_57 [ 1 ] , V_48 -> V_57 [ 2 ] ) ;
if ( V_19 -> V_53 . V_58 == V_59 ) {
F_8 ( L_12 ,
V_48 -> V_57 [ 3 ] , V_48 -> V_57 [ 11 ] ) ;
}
if ( F_17 ( V_19 -> V_53 . V_58 ) ) {
V_7 |= V_60 ;
memset ( ( void * ) & V_48 -> V_61 , 0 , 32 ) ;
memcpy ( ( void * ) & V_48 -> V_61 , V_19 -> V_62 , V_19 -> V_54 -> V_63 ) ;
}
if ( V_19 -> V_64 & V_65 )
V_9 = F_9 ( V_19 , ( void * ) V_48 ,
& V_25 , V_51 ,
V_46 -> V_22 ) ;
if ( V_19 -> V_53 . V_58 == V_59 )
V_7 |= V_66 ;
F_6 ( V_6 , V_1 , V_7 , V_25 ,
V_9 , 5 ) ;
F_8 ( L_13 ,
V_7 , V_25 , V_9 ) ;
}
static unsigned int F_18 ( struct V_18 * V_19 )
{
struct V_43 * V_38 = V_19 -> V_38 ;
struct V_45 * V_46 = V_38 -> V_47 -> V_44 ;
void T_1 * V_2 = V_46 -> V_2 ;
unsigned int V_1 = F_1 ( V_19 -> V_1 , V_2 ) ;
F_8 ( L_14 ,
F_5 ( V_4 + V_2 ) ,
F_5 ( V_67 + V_2 ) ,
F_5 ( V_68 + V_2 ) , F_5 ( V_69 + V_2 ) ) ;
F_19 ( V_19 -> V_54 -> V_55 -> V_56 , V_70 + V_2 ) ;
F_19 ( 1 << V_1 , V_4 + V_2 ) ;
F_8 ( L_15 ,
V_1 , F_5 ( V_4 + V_2 ) , F_5 ( V_67 + V_2 ) ) ;
F_8 ( L_16 ,
F_5 ( V_68 + V_2 ) ,
F_5 ( V_71 + V_2 ) ,
F_5 ( V_69 + V_2 ) ,
F_5 ( V_72 + V_46 -> V_73 ) ) ;
return 0 ;
}
static bool F_20 ( struct V_18 * V_19 )
{
struct V_5 * V_6 = V_19 -> V_38 -> V_44 ;
struct V_45 * V_46 = V_19 -> V_38 -> V_47 -> V_44 ;
void T_1 * V_2 = V_46 -> V_2 ;
unsigned int V_1 = F_1 ( V_19 -> V_1 , V_2 ) ;
struct V_28 * V_48 ;
V_48 = V_6 -> V_52 + V_1 ;
F_21 ( V_48 -> V_74 , & V_19 -> V_75 ) ;
return true ;
}
static int F_22 ( struct V_76 * V_55 ,
unsigned int V_77 , T_2 V_78 )
{
struct V_45 * V_46 = V_55 -> V_38 -> V_47 -> V_44 ;
void T_1 * V_79 = V_46 -> V_79 ;
unsigned int V_80 ;
switch ( V_77 ) {
case V_81 :
case V_82 :
case V_83 :
case V_84 :
V_80 = V_77 ;
break;
default:
return - V_85 ;
}
F_8 ( L_17 , V_80 ) ;
F_19 ( V_78 , V_79 + ( V_80 * 4 ) ) ;
return 0 ;
}
static int F_23 ( struct V_76 * V_55 ,
unsigned int V_77 , T_2 * V_78 )
{
struct V_45 * V_46 = V_55 -> V_38 -> V_47 -> V_44 ;
void T_1 * V_79 = V_46 -> V_79 ;
unsigned int V_80 ;
switch ( V_77 ) {
case V_81 :
case V_82 :
case V_83 :
case V_84 :
V_80 = V_77 ;
break;
default:
return - V_85 ;
}
F_8 ( L_18 , V_80 ) ;
* V_78 = F_5 ( V_79 + ( V_80 * 4 ) ) ;
return 0 ;
}
static void F_24 ( struct V_43 * V_38 )
{
struct V_45 * V_46 = V_38 -> V_47 -> V_44 ;
void T_1 * V_2 = V_46 -> V_2 ;
T_2 V_86 ;
F_8 ( L_19 ,
F_5 ( V_4 + V_2 ) ,
F_5 ( V_67 + V_2 ) ,
F_5 ( V_68 + V_2 ) , F_5 ( V_71 + V_2 ) ) ;
F_8 ( L_20 ,
F_5 ( V_46 -> V_73 + V_72 ) ) ;
V_86 = F_5 ( V_2 + V_87 ) ;
F_19 ( ( V_86 & ~ 0x3F ) , V_2 + V_87 ) ;
F_8 ( L_21 ,
F_5 ( V_2 + V_87 ) , F_5 ( V_2 + V_88 ) ) ;
}
static void F_25 ( struct V_43 * V_38 )
{
struct V_45 * V_46 = V_38 -> V_47 -> V_44 ;
void T_1 * V_2 = V_46 -> V_2 ;
T_2 V_86 ;
V_86 = F_5 ( V_2 + V_88 ) ;
F_8 ( L_22 , ( V_86 & 0x3F ) ) ;
if ( V_86 & 0x3F )
F_19 ( ( V_86 & 0x3F ) , V_2 + V_88 ) ;
V_86 = F_5 ( V_2 + V_87 ) ;
F_19 ( ( V_86 | V_89 ) , V_2 + V_87 ) ;
F_8 ( L_23 ,
F_5 ( V_2 + V_87 ) , F_5 ( V_2 + V_88 ) ) ;
}
static void F_26 ( struct V_43 * V_38 )
{
struct V_45 * V_46 = V_38 -> V_47 -> V_44 ;
void T_1 * V_2 = V_46 -> V_2 ;
T_2 V_86 ;
V_86 = F_5 ( V_2 + V_87 ) ;
F_19 ( ( V_86 | V_90 ) , V_2 + V_87 ) ;
}
static void F_27 ( struct V_43 * V_38 )
{
struct V_45 * V_46 = V_38 -> V_47 -> V_44 ;
void T_1 * V_2 = V_46 -> V_2 ;
T_2 V_86 ;
V_86 = F_5 ( V_2 + V_87 ) ;
V_86 &= ~ V_90 ;
F_19 ( V_86 , V_2 + V_87 ) ;
V_86 = F_5 ( V_2 + V_87 ) ;
F_19 ( ( V_86 | V_89 ) , V_2 + V_87 ) ;
}
static int F_28 ( struct V_43 * V_38 )
{
struct V_91 * V_54 = V_38 -> V_47 -> V_54 ;
struct V_5 * V_6 ;
void * V_92 ;
T_4 V_93 ;
struct V_45 * V_46 = V_38 -> V_47 -> V_44 ;
void T_1 * V_2 = V_46 -> V_2 ;
T_2 V_86 ;
V_6 = F_29 ( sizeof( * V_6 ) , V_94 ) ;
if ( ! V_6 )
return - V_95 ;
V_92 = F_30 ( V_54 , V_96 , & V_93 ,
V_94 ) ;
if ( ! V_92 ) {
F_31 ( V_6 ) ;
return - V_95 ;
}
memset ( V_92 , 0 , V_96 ) ;
V_6 -> V_14 = V_92 ;
V_6 -> V_97 = V_93 ;
V_92 += V_98 ;
V_93 += V_98 ;
V_6 -> V_52 = V_92 ;
V_6 -> V_12 = V_93 ;
V_38 -> V_44 = V_6 ;
F_8 ( L_24 ,
V_6 -> V_97 , V_6 -> V_12 ) ;
F_19 ( V_6 -> V_97 & 0xffffffff , V_2 + V_99 ) ;
V_86 = F_5 ( V_2 + V_87 ) ;
F_19 ( ( V_86 | V_100 ) , V_2 + V_87 ) ;
F_8 ( L_25 , F_5 ( V_2 + V_88 ) ) ;
F_8 ( L_26 , F_5 ( V_2 + V_87 ) ) ;
F_8 ( L_27 , F_5 ( V_2 + V_99 ) ) ;
#ifdef F_32
F_23 ( & V_38 -> V_55 , V_83 , & V_86 ) ;
V_86 &= ~ ( 0xF << 4 ) ;
V_86 |= ( 0x1 << 4 ) ;
F_22 ( & V_38 -> V_55 , V_83 , V_86 ) ;
F_23 ( & V_38 -> V_55 , V_83 , & V_86 ) ;
F_33 ( V_101 , V_54 , L_28 ,
V_86 ) ;
#endif
return 0 ;
}
static void F_34 ( struct V_43 * V_38 )
{
struct V_91 * V_54 = V_38 -> V_47 -> V_54 ;
struct V_5 * V_6 = V_38 -> V_44 ;
struct V_45 * V_46 = V_38 -> V_47 -> V_44 ;
void T_1 * V_2 = V_46 -> V_2 ;
T_2 V_86 ;
V_86 = F_5 ( V_2 + V_87 ) ;
V_86 &= ~ V_100 ;
V_86 |= V_102 ;
F_19 ( V_86 , V_2 + V_87 ) ;
F_35 ( V_38 , V_2 + V_88 , V_103 , V_103 , 1 , 1 ) ;
V_38 -> V_44 = NULL ;
F_36 ( V_54 , V_96 ,
V_6 -> V_14 , V_6 -> V_97 ) ;
F_31 ( V_6 ) ;
}
static unsigned int F_37 ( struct V_43 * V_38 )
{
struct V_45 * V_46 = V_38 -> V_47 -> V_44 ;
void T_1 * V_2 = V_46 -> V_2 ;
struct V_104 V_53 ;
T_2 V_86 ;
V_86 = F_5 ( V_2 + V_105 ) ;
F_8 ( L_29 , V_86 ) ;
F_8 ( L_25 , F_5 ( V_2 + V_88 ) ) ;
F_8 ( L_26 , F_5 ( V_2 + V_87 ) ) ;
V_53 . V_106 = ( V_86 >> 24 ) & 0xff ;
V_53 . V_107 = ( V_86 >> 16 ) & 0xff ;
V_53 . V_108 = ( V_86 >> 8 ) & 0xff ;
V_53 . V_109 = V_86 & 0xff ;
return F_38 ( & V_53 ) ;
}
static int F_39 ( struct V_76 * V_55 , unsigned int * V_110 ,
unsigned long V_111 )
{
struct V_43 * V_38 = V_55 -> V_38 ;
struct V_45 * V_46 = V_38 -> V_47 -> V_44 ;
void T_1 * V_2 = V_46 -> V_2 ;
T_2 V_86 ;
int V_112 = 0 ;
unsigned long V_113 ;
F_3 ( L_30 ) ;
V_114:
V_86 = F_5 ( V_2 + V_87 ) ;
V_86 &= ~ V_100 ;
F_19 ( V_86 , V_2 + V_87 ) ;
V_86 = F_35 ( V_38 , V_2 + V_88 , V_103 , V_103 ,
1 , 500 ) ;
if ( V_86 & V_103 ) {
F_13 ( V_38 , V_39 ,
L_31 , V_112 ) ;
V_112 ++ ;
if ( V_112 == 2 )
goto V_115;
else
goto V_114;
}
F_3 ( L_32 ) ;
F_8 ( L_25 , F_5 ( V_2 + V_88 ) ) ;
F_8 ( L_26 , F_5 ( V_2 + V_87 ) ) ;
F_40 ( V_38 , 1 ) ;
V_86 = F_5 ( V_2 + V_87 ) ;
V_86 |= ( V_100 | V_116 ) ;
V_86 |= V_90 ;
F_19 ( V_86 , V_2 + V_87 ) ;
V_86 = F_35 ( V_38 , V_2 + V_88 , V_103 , 0 , 1 , 500 ) ;
if ( ! ( V_86 & V_103 ) ) {
F_13 ( V_38 , V_39 ,
L_33 ) ;
goto V_115;
}
F_3 ( L_34 ) ;
F_8 ( L_25 , F_5 ( V_2 + V_88 ) ) ;
F_8 ( L_26 , F_5 ( V_2 + V_87 ) ) ;
V_86 = F_35 ( V_38 , V_2 + V_88 , 0xFF , 0 , 1 , 500 ) ;
if ( ( ! ( V_86 & 0x10 ) ) || F_41 ( V_55 ) ) {
F_13 ( V_38 , V_101 ,
L_35 ,
F_5 ( V_2 + V_88 ) ) ;
* V_110 = V_117 ;
return 0 ;
}
V_113 = V_118 ;
V_86 = F_35 ( V_38 , V_2 + V_88 , 0xFF , 0x10 ,
500 , F_42 ( V_111 - V_113 ) ) ;
if ( ( V_86 & 0xFF ) != 0x18 ) {
F_13 ( V_38 , V_101 , L_36 ) ;
* V_110 = V_117 ;
goto V_119;
} else {
F_13 ( V_38 , V_120 ,
L_37 ,
F_42 ( V_118 - V_113 ) ) ;
* V_110 = F_37 ( V_38 ) ;
return 0 ;
}
V_119:
return - V_121 ;
V_115:
return - V_122 ;
}
static int F_43 ( struct V_76 * V_55 , unsigned int * V_110 ,
unsigned long V_111 )
{
struct V_43 * V_38 = V_55 -> V_38 ;
struct V_5 * V_6 = V_38 -> V_44 ;
struct V_45 * V_46 = V_38 -> V_47 -> V_44 ;
void T_1 * V_2 = V_46 -> V_2 ;
int V_56 = F_44 ( V_55 ) ;
T_2 V_86 ;
struct V_104 V_53 ;
T_3 * V_57 ;
T_2 V_123 ;
F_3 ( L_38 ) ;
if ( F_41 ( V_55 ) ) {
F_3 ( L_39 ) ;
* V_110 = V_117 ;
return 0 ;
}
F_3 ( L_40 ) ;
F_45 ( V_55 -> V_91 , & V_53 ) ;
V_57 = ( T_3 * ) & V_6 -> V_52 -> V_57 ;
F_6 ( V_6 , 0 ,
V_124 | V_49 | V_50 , 0 , 0 , 5 ) ;
V_53 . V_125 |= V_126 ;
F_16 ( & V_53 , V_56 , 0 , V_57 ) ;
F_3 ( L_41 ,
V_57 [ 0 ] , V_57 [ 1 ] , V_57 [ 2 ] , V_57 [ 3 ] ) ;
F_3 ( L_42 ,
F_5 ( V_4 + V_2 ) ,
F_5 ( V_67 + V_2 ) , F_5 ( V_69 + V_2 ) ) ;
F_19 ( 0xFFFF , V_69 + V_2 ) ;
if ( V_56 != V_127 )
F_19 ( V_56 , V_70 + V_2 ) ;
F_19 ( 1 , V_4 + V_2 ) ;
V_86 = F_35 ( V_38 , V_4 + V_2 , 0x1 , 0x1 , 1 , 5000 ) ;
if ( V_86 & 0x1 ) {
F_13 ( V_38 , V_101 , L_43 ) ;
F_3 ( L_44 ,
F_5 ( V_4 + V_2 ) ,
F_5 ( V_67 + V_2 ) , F_5 ( V_69 + V_2 ) ) ;
F_23 ( & V_38 -> V_55 , V_82 , & V_123 ) ;
F_3 ( L_25 , F_5 ( V_2 + V_88 ) ) ;
F_3 ( L_26 , F_5 ( V_2 + V_87 ) ) ;
F_3 ( L_45 , V_123 ) ;
goto V_115;
}
F_40 ( V_38 , 1 ) ;
F_6 ( V_6 , 0 , V_49 | V_50 ,
0 , 0 , 5 ) ;
V_53 . V_125 &= ~ V_126 ;
F_16 ( & V_53 , V_56 , 0 , V_57 ) ;
if ( V_56 != V_127 )
F_19 ( V_56 , V_70 + V_2 ) ;
F_19 ( 1 , V_4 + V_2 ) ;
F_40 ( V_38 , 150 ) ;
F_19 ( 0x01 , V_69 + V_2 ) ;
F_3 ( L_46 ) ;
* V_110 = V_117 ;
if ( F_46 ( V_55 ) ) {
* V_110 = F_37 ( V_38 ) ;
F_3 ( L_47 , * V_110 ) ;
F_8 ( L_48 , F_5 ( V_2 + V_69 ) ) ;
F_8 ( L_49 , F_5 ( V_2 + V_68 ) ) ;
}
return 0 ;
V_115:
return - V_122 ;
}
static void F_47 ( struct V_43 * V_38 )
{
F_3 ( L_50 ) ;
F_48 ( V_38 ) ;
}
static void F_49 ( struct V_18 * V_19 )
{
if ( V_19 -> V_64 & V_128 )
V_19 -> V_129 |= V_130 ;
if ( V_19 -> V_129 ) {
}
}
static void F_50 ( struct V_43 * V_38 )
{
struct V_45 * V_46 = V_38 -> V_47 -> V_44 ;
void T_1 * V_2 = V_46 -> V_2 ;
T_2 V_131 , V_132 = 0 , V_133 = 0 , V_134 = 0 ;
unsigned int V_129 = 0 , V_135 = 0 ;
int V_136 = 0 , abort = 0 ;
struct V_76 * V_55 = NULL ;
struct V_18 * V_19 = NULL ;
struct V_137 * V_138 ;
V_131 = F_5 ( V_2 + V_88 ) ;
V_133 = F_5 ( V_2 + V_68 ) ;
V_55 = & V_38 -> V_55 ;
V_138 = & V_55 -> V_139 ;
F_51 ( V_138 ) ;
F_23 ( & V_38 -> V_55 , V_82 , & V_134 ) ;
if ( F_4 ( V_134 & 0xFFFF0000 ) )
F_22 ( & V_38 -> V_55 , V_82 , V_134 ) ;
F_3 ( L_51 ,
V_131 , V_133 , F_5 ( V_2 + V_71 ) , V_134 ) ;
if ( V_131 & V_140 ) {
V_138 -> V_129 |= V_141 ;
V_138 -> V_135 |= V_142 ;
V_136 = 1 ;
}
if ( V_131 & V_143 )
F_52 ( V_38 ) ;
if ( V_131 & V_144 ) {
F_3 ( L_52 ) ;
F_53 ( V_138 ) ;
F_54 ( V_138 , L_53 , L_54 ) ;
V_136 = 1 ;
}
if ( V_133 ) {
abort = 1 ;
F_3 ( L_55 ,
F_5 ( V_2 + V_68 ) , F_5 ( V_2 + V_71 ) ) ;
if ( V_38 -> V_145 ) {
unsigned int V_146 ;
V_132 = F_5 ( V_2 + V_71 ) ;
F_19 ( V_132 , V_2 + V_71 ) ;
F_19 ( V_133 , V_2 + V_68 ) ;
V_146 = F_55 ( V_132 ) - 1 ;
if ( V_146 < V_38 -> V_145 && V_132 != 0 ) {
V_55 = & V_38 -> V_147 [ V_146 ] ;
V_138 = & V_55 -> V_139 ;
V_19 = F_56 ( V_38 , V_55 -> V_148 ) ;
V_129 |= V_149 ;
} else {
V_129 |= V_150 ;
V_135 |= V_151 ;
V_136 = 1 ;
}
} else {
V_132 = F_5 ( V_2 + V_71 ) ;
F_19 ( V_132 , V_2 + V_71 ) ;
F_19 ( V_133 , V_2 + V_68 ) ;
V_19 = F_56 ( V_38 , V_55 -> V_148 ) ;
V_129 |= V_149 ;
}
}
if ( V_19 )
V_19 -> V_129 |= V_129 ;
else
V_138 -> V_129 |= V_129 ;
V_138 -> V_135 |= V_135 ;
if ( V_136 )
F_57 ( V_38 ) ;
else if ( abort ) {
if ( V_19 )
F_58 ( V_19 -> V_54 -> V_55 ) ;
else
F_59 ( V_38 ) ;
}
}
static void F_60 ( struct V_43 * V_38 )
{
struct V_45 * V_46 = V_38 -> V_47 -> V_44 ;
void T_1 * V_2 = V_46 -> V_2 ;
T_2 V_131 , V_152 = 0 ;
struct V_18 * V_19 ;
T_2 V_134 ;
V_131 = F_5 ( V_2 + V_88 ) ;
F_23 ( & V_38 -> V_55 , V_82 , & V_134 ) ;
if ( F_4 ( V_134 & 0xFFFF0000 ) ) {
F_3 ( L_56 , V_134 ) ;
F_50 ( V_38 ) ;
}
if ( F_4 ( V_131 & V_153 ) ) {
F_3 ( L_57 ) ;
F_50 ( V_38 ) ;
return;
}
V_152 = F_5 ( V_2 + V_69 ) ;
F_8 ( L_58 ) ;
F_8 ( L_59 ,
V_152 ,
F_5 ( V_2 + V_67 ) ,
F_5 ( V_2 + V_68 ) ,
F_5 ( V_2 + V_4 ) ,
V_38 -> V_154 ) ;
if ( V_152 & V_38 -> V_154 ) {
int V_112 ;
F_19 ( V_152 , V_2 + V_69 ) ;
F_3 ( L_58 ) ;
F_3 ( L_60 ,
V_152 , F_5 ( V_2 + V_67 ) ,
F_5 ( V_2 + V_68 ) ) ;
for ( V_112 = 0 ; V_112 < V_3 ; V_112 ++ ) {
if ( V_152 & ( 1 << V_112 ) )
F_3
( L_61 ,
V_112 , F_5 ( V_2 + V_69 ) ,
F_5 ( V_2 + V_67 ) ) ;
}
F_61 ( V_38 , V_38 -> V_154 ^ V_152 ) ;
return;
} else if ( ( V_38 -> V_154 & ( 1 << V_155 ) ) ) {
F_19 ( 1 , V_2 + V_69 ) ;
V_19 = F_56 ( V_38 , V_155 ) ;
F_3 ( L_62 ,
F_5 ( V_2 + V_69 ) ) ;
if ( V_19 ) {
F_62 ( V_19 ) ;
}
} else {
F_3 ( L_63 ,
F_5 ( V_2 + V_69 ) ) ;
F_19 ( V_152 , V_2 + V_69 ) ;
return;
}
}
static T_5 F_63 ( int V_156 , void * V_157 )
{
struct V_158 * V_47 = V_157 ;
struct V_45 * V_46 = V_47 -> V_44 ;
void T_1 * V_2 = V_46 -> V_2 ;
T_2 V_159 ;
unsigned V_160 = 0 ;
struct V_43 * V_38 ;
V_159 = F_5 ( V_2 + V_88 ) ;
V_159 &= 0x3F ;
F_3 ( L_64 , V_159 ) ;
if ( ! V_159 )
return V_161 ;
F_64 ( & V_47 -> V_162 ) ;
V_38 = V_47 -> V_163 [ 0 ] ;
if ( V_38 ) {
F_60 ( V_38 ) ;
} else {
F_33 ( V_101 , V_47 -> V_54 ,
L_65 ) ;
}
F_19 ( V_159 , V_2 + V_88 ) ;
V_160 = 1 ;
F_65 ( & V_47 -> V_162 ) ;
return F_66 ( V_160 ) ;
}
static int F_67 ( struct V_158 * V_47 )
{
struct V_45 * V_46 = V_47 -> V_44 ;
void T_1 * V_2 = V_46 -> V_2 ;
T_2 V_86 ;
V_86 = F_5 ( V_2 + V_88 ) ;
if ( V_86 & 0x3F )
F_19 ( ( V_86 & 0x3F ) , V_2 + V_88 ) ;
V_86 = F_5 ( V_2 + V_87 ) ;
F_19 ( ( V_86 & ~ 0x3F ) , V_2 + V_87 ) ;
F_3 ( L_66 , F_5 ( V_2 + V_164 ) ) ;
F_19 ( 0x01000000 , V_2 + V_164 ) ;
F_19 ( 0x00000FFFF , V_2 + V_68 ) ;
F_19 ( 0x00000FFFF , V_2 + V_71 ) ;
F_3 ( L_25 , F_5 ( V_2 + V_88 ) ) ;
F_3 ( L_26 , F_5 ( V_2 + V_87 ) ) ;
return 0 ;
}
static int F_68 ( struct V_165 * V_166 )
{
int V_167 = - V_168 ;
void T_1 * V_2 = NULL ;
void T_1 * V_79 = NULL ;
void T_1 * V_73 = NULL ;
struct V_45 * V_46 = NULL ;
int V_156 ;
struct V_158 * V_47 ;
T_2 V_86 ;
struct V_169 V_170 = V_171 [ 0 ] ;
const struct V_169 * V_172 [] = { & V_170 , NULL } ;
F_33 ( V_120 , & V_166 -> V_54 ,
L_67 ) ;
V_2 = F_69 ( V_166 -> V_54 . V_173 , 0 ) ;
if ( ! V_2 )
goto V_174;
V_79 = V_2 + 0x100 ;
V_73 = V_2 + 0x140 ;
if ( ! F_70 ( V_166 -> V_54 . V_173 , L_68 ) ) {
V_86 = F_5 ( V_73 + V_175 ) ;
V_86 = V_86 & 0xffffffe0 ;
F_19 ( V_86 | V_176 , V_73 + V_175 ) ;
}
F_3 ( L_69 , F_5 ( V_73 + V_175 ) ) ;
F_3 ( L_70 , sizeof( struct V_28 ) ) ;
F_3 ( L_71 , V_13 ) ;
V_46 = F_29 ( sizeof( struct V_45 ) , V_94 ) ;
if ( ! V_46 )
goto V_174;
V_46 -> V_2 = V_2 ;
V_46 -> V_79 = V_79 ;
V_46 -> V_73 = V_73 ;
V_156 = F_71 ( V_166 -> V_54 . V_173 , 0 ) ;
if ( V_156 < 0 ) {
F_33 ( V_39 , & V_166 -> V_54 , L_72 ) ;
goto V_174;
}
V_46 -> V_156 = V_156 ;
if ( F_70 ( V_166 -> V_54 . V_173 , L_73 ) )
V_46 -> V_22 = V_177 ;
else
V_46 -> V_22 = V_178 ;
V_47 = F_72 ( & V_166 -> V_54 , V_172 , V_179 ) ;
V_47 -> V_44 = V_46 ;
F_67 ( V_47 ) ;
F_73 ( V_47 , V_156 , F_63 , V_180 ,
& V_181 ) ;
F_74 ( & V_166 -> V_54 , V_47 ) ;
return 0 ;
V_174:
if ( V_2 )
F_75 ( V_2 ) ;
if ( V_46 )
F_31 ( V_46 ) ;
return V_167 ;
}
static int F_76 ( struct V_165 * V_166 )
{
struct V_158 * V_47 = F_77 ( & V_166 -> V_54 ) ;
struct V_45 * V_46 = V_47 -> V_44 ;
F_78 ( V_47 ) ;
F_74 ( & V_166 -> V_54 , NULL ) ;
F_79 ( V_46 -> V_156 ) ;
F_75 ( V_46 -> V_2 ) ;
F_31 ( V_46 ) ;
return 0 ;
}
static int F_80 ( struct V_165 * V_182 , T_6 V_183 )
{
struct V_158 * V_47 = F_77 ( & V_182 -> V_54 ) ;
return F_81 ( V_47 , V_183 ) ;
}
static int F_82 ( struct V_165 * V_182 )
{
struct V_158 * V_47 = F_77 ( & V_182 -> V_54 ) ;
struct V_45 * V_46 = V_47 -> V_44 ;
int V_184 ;
void T_1 * V_2 = V_46 -> V_2 ;
struct V_43 * V_38 = V_47 -> V_163 [ 0 ] ;
struct V_5 * V_6 = V_38 -> V_44 ;
V_184 = F_67 ( V_47 ) ;
if ( V_184 ) {
F_33 ( V_39 , & V_182 -> V_54 ,
L_74 ) ;
return V_184 ;
}
F_19 ( V_6 -> V_97 & 0xffffffff , V_2 + V_99 ) ;
F_83 ( V_47 ) ;
return 0 ;
}
static int T_7 F_84 ( void )
{
F_85 ( & V_185 ) ;
return 0 ;
}
static void T_8 F_86 ( void )
{
F_87 ( & V_185 ) ;
}
