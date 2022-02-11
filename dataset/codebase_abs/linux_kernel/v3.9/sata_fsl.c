static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
void T_1 * V_8 = V_6 -> V_8 ;
if ( V_3 > V_9 )
V_3 = V_9 ;
else if ( V_3 < V_10 )
V_3 = V_10 ;
if ( V_4 > V_11 )
V_4 = V_11 ;
else if ( ( V_12 == V_4 ) &&
( V_3 > V_10 ) )
V_4 = V_13 ;
F_2 ( & V_2 -> V_14 ) ;
F_3 ( ( V_3 << 24 | V_4 ) , V_8 + V_15 ) ;
V_16 = V_3 ;
V_17 = V_4 ;
F_4 ( & V_2 -> V_14 ) ;
F_5 ( L_1 ,
V_16 , V_17 ) ;
F_5 ( L_2 ,
V_8 , F_6 ( V_8 + V_15 ) ) ;
}
static T_2 F_7 ( struct V_18 * V_19 ,
struct V_20 * V_21 , char * V_22 )
{
return sprintf ( V_22 , L_3 ,
V_16 , V_17 ) ;
}
static T_2 F_8 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
const char * V_22 , T_3 V_3 )
{
unsigned int V_23 , V_24 ;
if ( sscanf ( V_22 , L_4 ,
& V_23 ,
& V_24 ) != 2 ) {
F_9 ( V_25 L_5 ) ;
return - V_26 ;
}
F_1 ( F_10 ( V_19 ) ,
V_23 , V_24 ) ;
return strlen ( V_22 ) ;
}
static inline unsigned int F_11 ( unsigned int V_27 ,
void T_1 * V_8 )
{
if ( F_12 ( V_27 ) ) {
F_5 ( L_6 ) ;
return 0 ;
}
if ( F_13 ( V_27 >= V_28 ) ) {
F_5 ( L_7 , V_27 ) ;
return 0 ;
}
if ( F_13 ( ( F_6 ( V_8 + V_29 ) ) & ( 1 << V_27 ) ) ) {
F_5 ( L_8 , V_27 ) ;
return 0 ;
}
return V_27 ;
}
static void F_14 ( struct V_30 * V_31 ,
unsigned int V_27 , T_4 V_32 ,
T_4 V_33 , T_5 V_34 ,
T_5 V_35 )
{
T_6 V_36 ;
V_36 = V_31 -> V_37 +
V_27 * V_38 ;
V_31 -> V_39 [ V_27 ] . V_40 = F_15 ( V_36 ) ;
V_31 -> V_39 [ V_27 ] . V_41 =
F_15 ( ( V_34 << 16 ) | ( V_35 << 2 ) ) ;
V_31 -> V_39 [ V_27 ] . V_42 = F_15 ( V_33 & ~ 0x03 ) ;
V_31 -> V_39 [ V_27 ] . V_32 = F_15 ( V_32 | ( V_27 & 0x1F ) ) ;
F_16 ( L_9 ,
V_31 -> V_39 [ V_27 ] . V_40 ,
V_31 -> V_39 [ V_27 ] . V_41 ,
V_31 -> V_39 [ V_27 ] . V_42 , V_31 -> V_39 [ V_27 ] . V_32 ) ;
}
static unsigned int F_17 ( struct V_43 * V_44 , void * V_45 ,
T_4 * V_42 , T_6 V_46 ,
int V_47 )
{
struct V_48 * V_49 ;
unsigned int V_34 = 0 ;
T_4 V_50 = 0 ;
struct V_51 * V_52 = (struct V_51 * ) & ( (struct V_53 * )
V_45 ) -> V_54 ;
struct V_51 * V_55 = NULL ;
unsigned V_56 = 0 ;
T_6 V_57 ;
unsigned int V_58 ;
F_16 ( L_10 , V_45 , V_52 ) ;
V_57 = V_46 +
V_59 + V_60 * 16 ;
F_18 (qc->sg, sg, qc->n_elem, si) {
T_6 V_61 = F_19 ( V_49 ) ;
T_4 V_62 = F_20 ( V_49 ) ;
F_16 ( L_11 ,
( unsigned long long ) V_61 , V_62 ) ;
if ( F_13 ( V_61 & 0x03 ) )
F_21 ( V_44 -> V_63 , L_12 ,
( unsigned long long ) V_61 ) ;
if ( F_13 ( V_62 & 0x03 ) )
F_21 ( V_44 -> V_63 , L_13 ,
V_62 ) ;
if ( V_34 == ( V_60 - 1 ) &&
F_22 ( V_49 ) != NULL ) {
F_16 ( L_14 ) ;
V_55 = V_52 ;
V_52 -> V_64 = F_15 ( V_57 ) ;
V_56 = 0 ;
++ V_52 ;
++ V_34 ;
}
V_50 += V_62 ;
V_52 -> V_64 = F_15 ( V_61 ) ;
V_52 -> V_65 = F_15 ( V_47 | ( V_62 & ~ 0x03 ) ) ;
F_16 ( L_15 ,
V_50 , V_52 -> V_64 , V_52 -> V_65 ) ;
++ V_34 ;
++ V_52 ;
if ( V_55 )
V_56 += V_62 ;
}
if ( V_55 ) {
V_55 -> V_65 =
F_15 ( ( V_66 |
V_47 |
( V_56 & ~ 0x03 ) ) ) ;
}
* V_42 = V_50 ;
return V_34 ;
}
static void F_23 ( struct V_43 * V_44 )
{
struct V_67 * V_63 = V_44 -> V_63 ;
struct V_30 * V_31 = V_63 -> V_7 ;
struct V_5 * V_6 = V_63 -> V_2 -> V_7 ;
void T_1 * V_8 = V_6 -> V_8 ;
unsigned int V_27 = F_11 ( V_44 -> V_27 , V_8 ) ;
struct V_53 * V_68 ;
T_4 V_32 = V_69 | V_70 ;
T_4 V_34 = 0 ;
T_4 V_50 = 0 ;
T_6 V_71 ;
V_68 = (struct V_53 * ) V_31 -> V_72 + V_27 ;
V_71 = V_31 -> V_37 + V_27 * V_38 ;
F_24 ( & V_44 -> V_73 , V_44 -> V_19 -> V_74 -> V_75 , 1 , ( T_5 * ) & V_68 -> V_76 ) ;
F_16 ( L_16 ,
V_68 -> V_76 [ 0 ] , V_68 -> V_76 [ 1 ] , V_68 -> V_76 [ 2 ] ) ;
if ( V_44 -> V_73 . V_77 == V_78 ) {
F_16 ( L_17 ,
V_68 -> V_76 [ 3 ] , V_68 -> V_76 [ 11 ] ) ;
}
if ( F_25 ( V_44 -> V_73 . V_77 ) ) {
V_32 |= V_79 ;
memset ( ( void * ) & V_68 -> V_80 , 0 , 32 ) ;
memcpy ( ( void * ) & V_68 -> V_80 , V_44 -> V_81 , V_44 -> V_19 -> V_82 ) ;
}
if ( V_44 -> V_83 & V_84 )
V_34 = F_17 ( V_44 , ( void * ) V_68 ,
& V_50 , V_71 ,
V_6 -> V_47 ) ;
if ( V_44 -> V_73 . V_77 == V_78 )
V_32 |= V_85 ;
F_14 ( V_31 , V_27 , V_32 , V_50 ,
V_34 , 5 ) ;
F_16 ( L_18 ,
V_32 , V_50 , V_34 ) ;
}
static unsigned int F_26 ( struct V_43 * V_44 )
{
struct V_67 * V_63 = V_44 -> V_63 ;
struct V_5 * V_6 = V_63 -> V_2 -> V_7 ;
void T_1 * V_8 = V_6 -> V_8 ;
unsigned int V_27 = F_11 ( V_44 -> V_27 , V_8 ) ;
F_16 ( L_19 ,
F_6 ( V_29 + V_8 ) ,
F_6 ( V_86 + V_8 ) ,
F_6 ( V_87 + V_8 ) , F_6 ( V_88 + V_8 ) ) ;
F_3 ( V_44 -> V_19 -> V_74 -> V_75 , V_89 + V_8 ) ;
F_3 ( 1 << V_27 , V_29 + V_8 ) ;
F_16 ( L_20 ,
V_27 , F_6 ( V_29 + V_8 ) , F_6 ( V_86 + V_8 ) ) ;
F_16 ( L_21 ,
F_6 ( V_87 + V_8 ) ,
F_6 ( V_90 + V_8 ) ,
F_6 ( V_88 + V_8 ) ,
F_6 ( V_91 + V_6 -> V_92 ) ) ;
return 0 ;
}
static bool F_27 ( struct V_43 * V_44 )
{
struct V_30 * V_31 = V_44 -> V_63 -> V_7 ;
struct V_5 * V_6 = V_44 -> V_63 -> V_2 -> V_7 ;
void T_1 * V_8 = V_6 -> V_8 ;
unsigned int V_27 = F_11 ( V_44 -> V_27 , V_8 ) ;
struct V_53 * V_68 ;
V_68 = V_31 -> V_72 + V_27 ;
F_28 ( V_68 -> V_93 , & V_44 -> V_94 ) ;
return true ;
}
static int F_29 ( struct V_95 * V_74 ,
unsigned int V_96 , T_4 V_97 )
{
struct V_5 * V_6 = V_74 -> V_63 -> V_2 -> V_7 ;
void T_1 * V_98 = V_6 -> V_98 ;
unsigned int V_99 ;
switch ( V_96 ) {
case V_100 :
case V_101 :
case V_102 :
case V_103 :
V_99 = V_96 ;
break;
default:
return - V_26 ;
}
F_16 ( L_22 , V_99 ) ;
F_3 ( V_97 , V_98 + ( V_99 * 4 ) ) ;
return 0 ;
}
static int F_30 ( struct V_95 * V_74 ,
unsigned int V_96 , T_4 * V_97 )
{
struct V_5 * V_6 = V_74 -> V_63 -> V_2 -> V_7 ;
void T_1 * V_98 = V_6 -> V_98 ;
unsigned int V_99 ;
switch ( V_96 ) {
case V_100 :
case V_101 :
case V_102 :
case V_103 :
V_99 = V_96 ;
break;
default:
return - V_26 ;
}
F_16 ( L_23 , V_99 ) ;
* V_97 = F_6 ( V_98 + ( V_99 * 4 ) ) ;
return 0 ;
}
static void F_31 ( struct V_67 * V_63 )
{
struct V_5 * V_6 = V_63 -> V_2 -> V_7 ;
void T_1 * V_8 = V_6 -> V_8 ;
T_4 V_104 ;
F_16 ( L_24 ,
F_6 ( V_29 + V_8 ) ,
F_6 ( V_86 + V_8 ) ,
F_6 ( V_87 + V_8 ) , F_6 ( V_90 + V_8 ) ) ;
F_16 ( L_25 ,
F_6 ( V_6 -> V_92 + V_91 ) ) ;
V_104 = F_6 ( V_8 + V_105 ) ;
F_3 ( ( V_104 & ~ 0x3F ) , V_8 + V_105 ) ;
F_16 ( L_26 ,
F_6 ( V_8 + V_105 ) , F_6 ( V_8 + V_106 ) ) ;
}
static void F_32 ( struct V_67 * V_63 )
{
struct V_5 * V_6 = V_63 -> V_2 -> V_7 ;
void T_1 * V_8 = V_6 -> V_8 ;
T_4 V_104 ;
V_104 = F_6 ( V_8 + V_106 ) ;
F_16 ( L_27 , ( V_104 & 0x3F ) ) ;
if ( V_104 & 0x3F )
F_3 ( ( V_104 & 0x3F ) , V_8 + V_106 ) ;
V_104 = F_6 ( V_8 + V_105 ) ;
F_3 ( ( V_104 | V_107 ) , V_8 + V_105 ) ;
F_16 ( L_28 ,
F_6 ( V_8 + V_105 ) , F_6 ( V_8 + V_106 ) ) ;
}
static void F_33 ( struct V_67 * V_63 )
{
struct V_5 * V_6 = V_63 -> V_2 -> V_7 ;
void T_1 * V_8 = V_6 -> V_8 ;
T_4 V_104 ;
V_104 = F_6 ( V_8 + V_105 ) ;
F_3 ( ( V_104 | V_108 ) , V_8 + V_105 ) ;
}
static void F_34 ( struct V_67 * V_63 )
{
struct V_5 * V_6 = V_63 -> V_2 -> V_7 ;
void T_1 * V_8 = V_6 -> V_8 ;
T_4 V_104 ;
V_104 = F_6 ( V_8 + V_105 ) ;
V_104 &= ~ V_108 ;
F_3 ( V_104 , V_8 + V_105 ) ;
V_104 = F_6 ( V_8 + V_105 ) ;
F_3 ( ( V_104 | V_107 ) , V_8 + V_105 ) ;
}
static int F_35 ( struct V_67 * V_63 )
{
struct V_18 * V_19 = V_63 -> V_2 -> V_19 ;
struct V_30 * V_31 ;
void * V_109 ;
T_6 V_110 ;
struct V_5 * V_6 = V_63 -> V_2 -> V_7 ;
void T_1 * V_8 = V_6 -> V_8 ;
T_4 V_104 ;
V_31 = F_36 ( sizeof( * V_31 ) , V_111 ) ;
if ( ! V_31 )
return - V_112 ;
V_109 = F_37 ( V_19 , V_113 , & V_110 ,
V_111 ) ;
if ( ! V_109 ) {
F_38 ( V_31 ) ;
return - V_112 ;
}
memset ( V_109 , 0 , V_113 ) ;
V_31 -> V_39 = V_109 ;
V_31 -> V_114 = V_110 ;
V_109 += V_115 ;
V_110 += V_115 ;
V_31 -> V_72 = V_109 ;
V_31 -> V_37 = V_110 ;
V_63 -> V_7 = V_31 ;
F_16 ( L_29 ,
V_31 -> V_114 , V_31 -> V_37 ) ;
F_3 ( V_31 -> V_114 & 0xffffffff , V_8 + V_116 ) ;
V_104 = F_6 ( V_8 + V_105 ) ;
F_3 ( ( V_104 | V_117 ) , V_8 + V_105 ) ;
F_16 ( L_30 , F_6 ( V_8 + V_106 ) ) ;
F_16 ( L_31 , F_6 ( V_8 + V_105 ) ) ;
F_16 ( L_32 , F_6 ( V_8 + V_116 ) ) ;
#ifdef F_39
F_30 ( & V_63 -> V_74 , V_102 , & V_104 ) ;
V_104 &= ~ ( 0xF << 4 ) ;
V_104 |= ( 0x1 << 4 ) ;
F_29 ( & V_63 -> V_74 , V_102 , V_104 ) ;
F_30 ( & V_63 -> V_74 , V_102 , & V_104 ) ;
F_40 ( V_19 , L_33 , V_104 ) ;
#endif
return 0 ;
}
static void F_41 ( struct V_67 * V_63 )
{
struct V_18 * V_19 = V_63 -> V_2 -> V_19 ;
struct V_30 * V_31 = V_63 -> V_7 ;
struct V_5 * V_6 = V_63 -> V_2 -> V_7 ;
void T_1 * V_8 = V_6 -> V_8 ;
T_4 V_104 ;
V_104 = F_6 ( V_8 + V_105 ) ;
V_104 &= ~ V_117 ;
V_104 |= V_118 ;
F_3 ( V_104 , V_8 + V_105 ) ;
F_42 ( V_63 , V_8 + V_106 , V_119 , V_119 , 1 , 1 ) ;
V_63 -> V_7 = NULL ;
F_43 ( V_19 , V_113 ,
V_31 -> V_39 , V_31 -> V_114 ) ;
F_38 ( V_31 ) ;
}
static unsigned int F_44 ( struct V_67 * V_63 )
{
struct V_5 * V_6 = V_63 -> V_2 -> V_7 ;
void T_1 * V_8 = V_6 -> V_8 ;
struct V_120 V_73 ;
T_4 V_104 ;
V_104 = F_6 ( V_8 + V_121 ) ;
F_16 ( L_34 , V_104 ) ;
F_16 ( L_30 , F_6 ( V_8 + V_106 ) ) ;
F_16 ( L_31 , F_6 ( V_8 + V_105 ) ) ;
V_73 . V_122 = ( V_104 >> 24 ) & 0xff ;
V_73 . V_123 = ( V_104 >> 16 ) & 0xff ;
V_73 . V_124 = ( V_104 >> 8 ) & 0xff ;
V_73 . V_125 = V_104 & 0xff ;
return F_45 ( & V_73 ) ;
}
static int F_46 ( struct V_95 * V_74 , unsigned int * V_126 ,
unsigned long V_127 )
{
struct V_67 * V_63 = V_74 -> V_63 ;
struct V_5 * V_6 = V_63 -> V_2 -> V_7 ;
void T_1 * V_8 = V_6 -> V_8 ;
T_4 V_104 ;
int V_128 = 0 ;
unsigned long V_129 ;
F_5 ( L_35 ) ;
V_130:
V_104 = F_6 ( V_8 + V_105 ) ;
V_104 &= ~ V_117 ;
F_3 ( V_104 , V_8 + V_105 ) ;
V_104 = F_42 ( V_63 , V_8 + V_106 , V_119 , V_119 ,
1 , 500 ) ;
if ( V_104 & V_119 ) {
F_21 ( V_63 , L_36 , V_128 ) ;
V_128 ++ ;
if ( V_128 == 2 )
goto V_131;
else
goto V_130;
}
F_5 ( L_37 ) ;
F_16 ( L_30 , F_6 ( V_8 + V_106 ) ) ;
F_16 ( L_31 , F_6 ( V_8 + V_105 ) ) ;
F_47 ( V_63 , 1 ) ;
V_104 = F_6 ( V_8 + V_105 ) ;
V_104 |= ( V_117 | V_132 ) ;
V_104 |= V_108 ;
F_3 ( V_104 , V_8 + V_105 ) ;
V_104 = F_42 ( V_63 , V_8 + V_106 , V_119 , 0 , 1 , 500 ) ;
if ( ! ( V_104 & V_119 ) ) {
F_21 ( V_63 , L_38 ) ;
goto V_131;
}
F_5 ( L_39 ) ;
F_16 ( L_30 , F_6 ( V_8 + V_106 ) ) ;
F_16 ( L_31 , F_6 ( V_8 + V_105 ) ) ;
V_104 = F_42 ( V_63 , V_8 + V_106 , 0xFF , 0 , 1 , 500 ) ;
if ( ( ! ( V_104 & 0x10 ) ) || F_48 ( V_74 ) ) {
F_49 ( V_63 , L_40 ,
F_6 ( V_8 + V_106 ) ) ;
* V_126 = V_133 ;
return 0 ;
}
V_129 = V_134 ;
V_104 = F_42 ( V_63 , V_8 + V_106 , 0xFF , 0x10 ,
500 , F_50 ( V_127 - V_129 ) ) ;
if ( ( V_104 & 0xFF ) != 0x18 ) {
F_49 ( V_63 , L_41 ) ;
* V_126 = V_133 ;
goto V_135;
} else {
F_51 ( V_63 , L_42 ,
F_50 ( V_134 - V_129 ) ) ;
* V_126 = F_44 ( V_63 ) ;
return 0 ;
}
V_135:
return - V_136 ;
V_131:
return - V_137 ;
}
static int F_52 ( struct V_95 * V_74 , unsigned int * V_126 ,
unsigned long V_127 )
{
struct V_67 * V_63 = V_74 -> V_63 ;
struct V_30 * V_31 = V_63 -> V_7 ;
struct V_5 * V_6 = V_63 -> V_2 -> V_7 ;
void T_1 * V_8 = V_6 -> V_8 ;
int V_75 = F_53 ( V_74 ) ;
T_4 V_104 ;
struct V_120 V_73 ;
T_5 * V_76 ;
T_4 V_138 ;
F_5 ( L_43 ) ;
if ( F_48 ( V_74 ) ) {
F_5 ( L_44 ) ;
* V_126 = V_133 ;
return 0 ;
}
F_5 ( L_45 ) ;
F_54 ( V_74 -> V_18 , & V_73 ) ;
V_76 = ( T_5 * ) & V_31 -> V_72 -> V_76 ;
F_14 ( V_31 , 0 ,
V_139 | V_69 | V_70 , 0 , 0 , 5 ) ;
V_73 . V_140 |= V_141 ;
F_24 ( & V_73 , V_75 , 0 , V_76 ) ;
F_5 ( L_46 ,
V_76 [ 0 ] , V_76 [ 1 ] , V_76 [ 2 ] , V_76 [ 3 ] ) ;
F_5 ( L_47 ,
F_6 ( V_29 + V_8 ) ,
F_6 ( V_86 + V_8 ) , F_6 ( V_88 + V_8 ) ) ;
F_3 ( 0xFFFF , V_88 + V_8 ) ;
if ( V_75 != V_142 )
F_3 ( V_75 , V_89 + V_8 ) ;
F_3 ( 1 , V_29 + V_8 ) ;
V_104 = F_42 ( V_63 , V_29 + V_8 , 0x1 , 0x1 , 1 , 5000 ) ;
if ( V_104 & 0x1 ) {
F_49 ( V_63 , L_48 ) ;
F_5 ( L_49 ,
F_6 ( V_29 + V_8 ) ,
F_6 ( V_86 + V_8 ) , F_6 ( V_88 + V_8 ) ) ;
F_30 ( & V_63 -> V_74 , V_101 , & V_138 ) ;
F_5 ( L_30 , F_6 ( V_8 + V_106 ) ) ;
F_5 ( L_31 , F_6 ( V_8 + V_105 ) ) ;
F_5 ( L_50 , V_138 ) ;
goto V_131;
}
F_47 ( V_63 , 1 ) ;
F_14 ( V_31 , 0 , V_69 | V_70 ,
0 , 0 , 5 ) ;
V_73 . V_140 &= ~ V_141 ;
F_24 ( & V_73 , V_75 , 0 , V_76 ) ;
if ( V_75 != V_142 )
F_3 ( V_75 , V_89 + V_8 ) ;
F_3 ( 1 , V_29 + V_8 ) ;
F_47 ( V_63 , 150 ) ;
F_3 ( 0x01 , V_88 + V_8 ) ;
F_5 ( L_51 ) ;
* V_126 = V_133 ;
if ( F_55 ( V_74 ) ) {
* V_126 = F_44 ( V_63 ) ;
F_5 ( L_52 , * V_126 ) ;
F_16 ( L_53 , F_6 ( V_8 + V_88 ) ) ;
F_16 ( L_54 , F_6 ( V_8 + V_87 ) ) ;
}
return 0 ;
V_131:
return - V_137 ;
}
static void F_56 ( struct V_67 * V_63 )
{
F_5 ( L_55 ) ;
F_57 ( V_63 ) ;
}
static void F_58 ( struct V_43 * V_44 )
{
if ( V_44 -> V_83 & V_143 )
V_44 -> V_144 |= V_145 ;
if ( V_44 -> V_144 ) {
}
}
static void F_59 ( struct V_67 * V_63 )
{
struct V_5 * V_6 = V_63 -> V_2 -> V_7 ;
void T_1 * V_8 = V_6 -> V_8 ;
T_4 V_146 , V_147 = 0 , V_148 = 0 , V_149 = 0 ;
unsigned int V_144 = 0 , V_150 = 0 ;
int V_151 = 0 , abort = 0 ;
struct V_95 * V_74 = NULL ;
struct V_43 * V_44 = NULL ;
struct V_152 * V_153 ;
V_146 = F_6 ( V_8 + V_106 ) ;
V_148 = F_6 ( V_8 + V_87 ) ;
V_74 = & V_63 -> V_74 ;
V_153 = & V_74 -> V_154 ;
F_60 ( V_153 ) ;
F_30 ( & V_63 -> V_74 , V_101 , & V_149 ) ;
if ( F_13 ( V_149 & 0xFFFF0000 ) )
F_29 ( & V_63 -> V_74 , V_101 , V_149 ) ;
F_5 ( L_56 ,
V_146 , V_148 , F_6 ( V_8 + V_90 ) , V_149 ) ;
if ( V_146 & V_155 ) {
V_153 -> V_144 |= V_156 ;
V_153 -> V_150 |= V_157 ;
V_151 = 1 ;
}
if ( V_146 & V_158 )
F_61 ( V_63 ) ;
if ( V_146 & V_159 ) {
F_5 ( L_57 ) ;
F_62 ( V_153 ) ;
F_63 ( V_153 , L_58 , L_59 ) ;
V_151 = 1 ;
}
if ( V_148 ) {
abort = 1 ;
F_5 ( L_60 ,
F_6 ( V_8 + V_87 ) , F_6 ( V_8 + V_90 ) ) ;
if ( V_63 -> V_160 ) {
unsigned int V_161 ;
V_147 = F_6 ( V_8 + V_90 ) ;
F_3 ( V_147 , V_8 + V_90 ) ;
F_3 ( V_148 , V_8 + V_87 ) ;
V_161 = F_64 ( V_147 ) - 1 ;
if ( V_161 < V_63 -> V_160 && V_147 != 0 ) {
V_74 = & V_63 -> V_162 [ V_161 ] ;
V_153 = & V_74 -> V_154 ;
V_44 = F_65 ( V_63 , V_74 -> V_163 ) ;
V_144 |= V_164 ;
} else {
V_144 |= V_165 ;
V_150 |= V_166 ;
V_151 = 1 ;
}
} else {
V_147 = F_6 ( V_8 + V_90 ) ;
F_3 ( V_147 , V_8 + V_90 ) ;
F_3 ( V_148 , V_8 + V_87 ) ;
V_44 = F_65 ( V_63 , V_74 -> V_163 ) ;
V_144 |= V_164 ;
}
}
if ( V_44 )
V_44 -> V_144 |= V_144 ;
else
V_153 -> V_144 |= V_144 ;
V_153 -> V_150 |= V_150 ;
if ( V_151 )
F_66 ( V_63 ) ;
else if ( abort ) {
if ( V_44 )
F_67 ( V_44 -> V_19 -> V_74 ) ;
else
F_68 ( V_63 ) ;
}
}
static void F_69 ( struct V_67 * V_63 )
{
struct V_5 * V_6 = V_63 -> V_2 -> V_7 ;
void T_1 * V_8 = V_6 -> V_8 ;
T_4 V_146 , V_167 = 0 ;
struct V_43 * V_44 ;
T_4 V_149 ;
T_4 V_27 ;
T_4 V_168 = V_169 ;
V_146 = F_6 ( V_8 + V_106 ) ;
F_30 ( & V_63 -> V_74 , V_101 , & V_149 ) ;
V_167 = F_6 ( V_8 + V_88 ) ;
if ( F_13 ( V_146 & V_170 ) ) {
for ( V_27 = 0 ; V_27 < V_171 ; V_27 ++ ) {
V_44 = F_65 ( V_63 , V_27 ) ;
if ( V_44 && F_25 ( V_44 -> V_73 . V_77 ) ) {
T_4 V_172 ;
V_172 = F_6 ( V_8 + V_105 ) ;
F_3 ( V_172 | V_173 ,
V_8 + V_105 ) ;
F_3 ( V_172 & ~ V_173 ,
V_8 + V_105 ) ;
F_29 ( & V_63 -> V_74 , V_101 ,
V_149 ) ;
V_168 &= ~ ( V_174
| V_175 ) ;
break;
}
}
}
if ( F_13 ( V_149 & 0xFFFF0000 ) ) {
F_5 ( L_61 , V_149 ) ;
F_59 ( V_63 ) ;
}
if ( F_13 ( V_146 & V_168 ) ) {
F_5 ( L_62 ) ;
F_59 ( V_63 ) ;
return;
}
F_16 ( L_63 ) ;
F_16 ( L_64 ,
V_167 ,
F_6 ( V_8 + V_86 ) ,
F_6 ( V_8 + V_87 ) ,
F_6 ( V_8 + V_29 ) ,
V_63 -> V_176 ) ;
if ( V_167 & V_63 -> V_176 ) {
int V_128 ;
F_3 ( V_167 , V_8 + V_88 ) ;
F_5 ( L_63 ) ;
F_5 ( L_65 ,
V_167 , F_6 ( V_8 + V_86 ) ,
F_6 ( V_8 + V_87 ) ) ;
for ( V_128 = 0 ; V_128 < V_28 ; V_128 ++ ) {
if ( V_167 & ( 1 << V_128 ) )
F_5
( L_66 ,
V_128 , F_6 ( V_8 + V_88 ) ,
F_6 ( V_8 + V_86 ) ) ;
}
F_70 ( V_63 , V_63 -> V_176 ^ V_167 ) ;
return;
} else if ( ( V_63 -> V_176 & ( 1 << V_177 ) ) ) {
F_3 ( 1 , V_8 + V_88 ) ;
V_44 = F_65 ( V_63 , V_177 ) ;
F_5 ( L_67 ,
F_6 ( V_8 + V_88 ) ) ;
if ( V_44 ) {
F_71 ( V_44 ) ;
}
} else {
F_5 ( L_68 ,
F_6 ( V_8 + V_88 ) ) ;
F_3 ( V_167 , V_8 + V_88 ) ;
return;
}
}
static T_7 F_72 ( int V_178 , void * V_179 )
{
struct V_1 * V_2 = V_179 ;
struct V_5 * V_6 = V_2 -> V_7 ;
void T_1 * V_8 = V_6 -> V_8 ;
T_4 V_180 ;
unsigned V_181 = 0 ;
struct V_67 * V_63 ;
V_180 = F_6 ( V_8 + V_106 ) ;
V_180 &= 0x3F ;
F_5 ( L_69 , V_180 ) ;
if ( ! V_180 )
return V_182 ;
F_2 ( & V_2 -> V_14 ) ;
V_63 = V_2 -> V_183 [ 0 ] ;
if ( V_63 ) {
F_69 ( V_63 ) ;
} else {
F_40 ( V_2 -> V_19 , L_70 ) ;
}
F_3 ( V_180 , V_8 + V_106 ) ;
V_181 = 1 ;
F_4 ( & V_2 -> V_14 ) ;
return F_73 ( V_181 ) ;
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
void T_1 * V_8 = V_6 -> V_8 ;
T_4 V_104 ;
V_104 = F_6 ( V_8 + V_105 ) ;
F_3 ( V_104 & ~ V_184 , V_8 + V_105 ) ;
V_104 = F_6 ( V_8 + V_106 ) ;
if ( V_104 & 0x3F )
F_3 ( ( V_104 & 0x3F ) , V_8 + V_106 ) ;
V_104 = F_6 ( V_8 + V_105 ) ;
F_3 ( ( V_104 & ~ 0x3F ) , V_8 + V_105 ) ;
F_5 ( L_71 , F_6 ( V_8 + V_15 ) ) ;
F_3 ( 0x01000000 , V_8 + V_15 ) ;
F_3 ( 0x00000FFFF , V_8 + V_87 ) ;
F_3 ( 0x00000FFFF , V_8 + V_90 ) ;
F_1 ( V_2 , V_16 ,
V_17 ) ;
F_5 ( L_30 , F_6 ( V_8 + V_106 ) ) ;
F_5 ( L_31 , F_6 ( V_8 + V_105 ) ) ;
return 0 ;
}
static int F_75 ( struct V_185 * V_186 )
{
int V_187 = - V_188 ;
void T_1 * V_8 = NULL ;
void T_1 * V_98 = NULL ;
void T_1 * V_92 = NULL ;
struct V_5 * V_6 = NULL ;
int V_178 ;
struct V_1 * V_2 = NULL ;
T_4 V_104 ;
struct F_51 V_189 = V_190 [ 0 ] ;
const struct F_51 * V_191 [] = { & V_189 , NULL } ;
F_76 ( & V_186 -> V_19 , L_72 ) ;
V_8 = F_77 ( V_186 -> V_19 . V_192 , 0 ) ;
if ( ! V_8 )
goto V_193;
V_98 = V_8 + 0x100 ;
V_92 = V_8 + 0x140 ;
if ( ! F_78 ( V_186 -> V_19 . V_192 , L_73 ) ) {
V_104 = F_6 ( V_92 + V_194 ) ;
V_104 = V_104 & 0xffffffe0 ;
F_3 ( V_104 | V_195 , V_92 + V_194 ) ;
}
F_5 ( L_74 , F_6 ( V_92 + V_194 ) ) ;
F_5 ( L_75 , sizeof( struct V_53 ) ) ;
F_5 ( L_76 , V_38 ) ;
V_6 = F_36 ( sizeof( struct V_5 ) , V_111 ) ;
if ( ! V_6 )
goto V_193;
V_6 -> V_8 = V_8 ;
V_6 -> V_98 = V_98 ;
V_6 -> V_92 = V_92 ;
V_178 = F_79 ( V_186 -> V_19 . V_192 , 0 ) ;
if ( V_178 < 0 ) {
F_80 ( & V_186 -> V_19 , L_77 ) ;
goto V_193;
}
V_6 -> V_178 = V_178 ;
if ( F_78 ( V_186 -> V_19 . V_192 , L_78 ) )
V_6 -> V_47 = V_196 ;
else
V_6 -> V_47 = V_197 ;
V_2 = F_81 ( & V_186 -> V_19 , V_191 , V_198 ) ;
if ( ! V_2 ) {
V_187 = - V_112 ;
goto V_193;
}
V_2 -> V_7 = V_6 ;
F_74 ( V_2 ) ;
F_82 ( V_2 , V_178 , F_72 , V_199 ,
& V_200 ) ;
F_83 ( & V_186 -> V_19 , V_2 ) ;
V_6 -> V_201 . V_202 = F_7 ;
V_6 -> V_201 . V_203 = F_8 ;
F_84 ( & V_6 -> V_201 . V_21 ) ;
V_6 -> V_201 . V_21 . V_204 = L_79 ;
V_6 -> V_201 . V_21 . V_205 = V_206 | V_207 ;
V_187 = F_85 ( V_2 -> V_19 , & V_6 -> V_201 ) ;
if ( V_187 )
goto V_193;
return 0 ;
V_193:
if ( V_2 ) {
F_83 ( & V_186 -> V_19 , NULL ) ;
F_86 ( V_2 ) ;
}
if ( V_8 )
F_87 ( V_8 ) ;
F_38 ( V_6 ) ;
return V_187 ;
}
static int F_88 ( struct V_185 * V_186 )
{
struct V_1 * V_2 = F_10 ( & V_186 -> V_19 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_89 ( & V_186 -> V_19 , & V_6 -> V_201 ) ;
F_86 ( V_2 ) ;
F_83 ( & V_186 -> V_19 , NULL ) ;
F_90 ( V_6 -> V_178 ) ;
F_87 ( V_6 -> V_8 ) ;
F_38 ( V_6 ) ;
return 0 ;
}
static int F_91 ( struct V_185 * V_208 , T_8 V_209 )
{
struct V_1 * V_2 = F_10 ( & V_208 -> V_19 ) ;
return F_92 ( V_2 , V_209 ) ;
}
static int F_93 ( struct V_185 * V_208 )
{
struct V_1 * V_2 = F_10 ( & V_208 -> V_19 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_210 ;
void T_1 * V_8 = V_6 -> V_8 ;
struct V_67 * V_63 = V_2 -> V_183 [ 0 ] ;
struct V_30 * V_31 = V_63 -> V_7 ;
V_210 = F_74 ( V_2 ) ;
if ( V_210 ) {
F_80 ( & V_208 -> V_19 , L_80 ) ;
return V_210 ;
}
F_3 ( V_31 -> V_114 & 0xffffffff , V_8 + V_116 ) ;
F_3 ( ( F_6 ( V_8 + V_105 )
| V_117
| V_132
| V_108 ) ,
V_8 + V_105 ) ;
F_94 ( V_2 ) ;
return 0 ;
}
