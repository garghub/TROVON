static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
void T_1 * V_8 = V_6 -> V_8 ;
unsigned long V_9 ;
if ( V_3 > V_10 )
V_3 = V_10 ;
else if ( V_3 < V_11 )
V_3 = V_11 ;
if ( V_4 > V_12 )
V_4 = V_12 ;
else if ( ( V_13 == V_4 ) &&
( V_3 > V_11 ) )
V_4 = V_14 ;
F_2 ( & V_2 -> V_15 , V_9 ) ;
F_3 ( ( V_3 << 24 | V_4 ) , V_8 + V_16 ) ;
V_17 = V_3 ;
V_18 = V_4 ;
F_4 ( & V_2 -> V_15 , V_9 ) ;
F_5 ( L_1 ,
V_17 , V_18 ) ;
F_5 ( L_2 ,
V_8 , F_6 ( V_8 + V_16 ) ) ;
}
static T_2 F_7 ( struct V_19 * V_20 ,
struct V_21 * V_22 , char * V_23 )
{
return sprintf ( V_23 , L_3 ,
V_17 , V_18 ) ;
}
static T_2 F_8 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
const char * V_23 , T_3 V_3 )
{
unsigned int V_24 , V_25 ;
if ( sscanf ( V_23 , L_4 ,
& V_24 ,
& V_25 ) != 2 ) {
F_9 ( V_26 L_5 ) ;
return - V_27 ;
}
F_1 ( F_10 ( V_20 ) ,
V_24 , V_25 ) ;
return strlen ( V_23 ) ;
}
static T_2 F_11 ( struct V_19 * V_20 ,
struct V_21 * V_22 , char * V_23 )
{
unsigned int V_28 ;
unsigned long V_9 ;
struct V_1 * V_2 = F_10 ( V_20 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
void T_1 * V_29 = V_6 -> V_29 ;
F_2 ( & V_2 -> V_15 , V_9 ) ;
V_28 = F_6 ( V_29 + V_30 ) ;
V_28 &= 0x1f ;
F_4 ( & V_2 -> V_15 , V_9 ) ;
return sprintf ( V_23 , L_6 , V_28 ) ;
}
static T_2 F_12 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
const char * V_23 , T_3 V_3 )
{
unsigned int V_28 ;
unsigned long V_9 ;
struct V_1 * V_2 = F_10 ( V_20 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
void T_1 * V_29 = V_6 -> V_29 ;
T_4 V_31 ;
if ( sscanf ( V_23 , L_7 , & V_28 ) != 1 ) {
F_9 ( V_26 L_5 ) ;
return - V_27 ;
}
F_2 ( & V_2 -> V_15 , V_9 ) ;
V_31 = F_6 ( V_29 + V_30 ) ;
V_31 &= 0xffffffe0 ;
F_3 ( V_31 | V_28 , V_29 + V_30 ) ;
F_4 ( & V_2 -> V_15 , V_9 ) ;
return strlen ( V_23 ) ;
}
static inline unsigned int F_13 ( unsigned int V_32 ,
void T_1 * V_8 )
{
if ( F_14 ( V_32 ) ) {
F_5 ( L_8 ) ;
return 0 ;
}
if ( F_15 ( V_32 >= V_33 ) ) {
F_5 ( L_9 , V_32 ) ;
return 0 ;
}
if ( F_15 ( ( F_6 ( V_8 + V_34 ) ) & ( 1 << V_32 ) ) ) {
F_5 ( L_10 , V_32 ) ;
return 0 ;
}
return V_32 ;
}
static void F_16 ( struct V_35 * V_36 ,
unsigned int V_32 , T_4 V_37 ,
T_4 V_38 , T_5 V_39 ,
T_5 V_40 )
{
T_6 V_41 ;
V_41 = V_36 -> V_42 +
V_32 * V_43 ;
V_36 -> V_44 [ V_32 ] . V_45 = F_17 ( V_41 ) ;
V_36 -> V_44 [ V_32 ] . V_46 =
F_17 ( ( V_39 << 16 ) | ( V_40 << 2 ) ) ;
V_36 -> V_44 [ V_32 ] . V_47 = F_17 ( V_38 & ~ 0x03 ) ;
V_36 -> V_44 [ V_32 ] . V_37 = F_17 ( V_37 | ( V_32 & 0x1F ) ) ;
F_18 ( L_11 ,
V_36 -> V_44 [ V_32 ] . V_45 ,
V_36 -> V_44 [ V_32 ] . V_46 ,
V_36 -> V_44 [ V_32 ] . V_47 , V_36 -> V_44 [ V_32 ] . V_37 ) ;
}
static unsigned int F_19 ( struct V_48 * V_49 , void * V_50 ,
T_4 * V_47 , T_6 V_51 ,
int V_52 )
{
struct V_53 * V_54 ;
unsigned int V_39 = 0 ;
T_4 V_55 = 0 ;
struct V_56 * V_57 = (struct V_56 * ) & ( (struct V_58 * )
V_50 ) -> V_59 ;
struct V_56 * V_60 = NULL ;
unsigned V_61 = 0 ;
T_6 V_62 ;
unsigned int V_63 ;
F_18 ( L_12 , V_50 , V_57 ) ;
V_62 = V_51 +
V_64 + V_65 * 16 ;
F_20 (qc->sg, sg, qc->n_elem, si) {
T_6 V_66 = F_21 ( V_54 ) ;
T_4 V_67 = F_22 ( V_54 ) ;
F_18 ( L_13 ,
( unsigned long long ) V_66 , V_67 ) ;
if ( F_15 ( V_66 & 0x03 ) )
F_23 ( V_49 -> V_68 , L_14 ,
( unsigned long long ) V_66 ) ;
if ( F_15 ( V_67 & 0x03 ) )
F_23 ( V_49 -> V_68 , L_15 ,
V_67 ) ;
if ( V_39 == ( V_65 - 1 ) &&
F_24 ( V_54 ) != NULL ) {
F_18 ( L_16 ) ;
V_60 = V_57 ;
V_57 -> V_69 = F_17 ( V_62 ) ;
V_61 = 0 ;
++ V_57 ;
++ V_39 ;
}
V_55 += V_67 ;
V_57 -> V_69 = F_17 ( V_66 ) ;
V_57 -> V_70 = F_17 ( V_52 | ( V_67 & ~ 0x03 ) ) ;
F_18 ( L_17 ,
V_55 , V_57 -> V_69 , V_57 -> V_70 ) ;
++ V_39 ;
++ V_57 ;
if ( V_60 )
V_61 += V_67 ;
}
if ( V_60 ) {
V_60 -> V_70 =
F_17 ( ( V_71 |
V_52 |
( V_61 & ~ 0x03 ) ) ) ;
}
* V_47 = V_55 ;
return V_39 ;
}
static void F_25 ( struct V_48 * V_49 )
{
struct V_72 * V_68 = V_49 -> V_68 ;
struct V_35 * V_36 = V_68 -> V_7 ;
struct V_5 * V_6 = V_68 -> V_2 -> V_7 ;
void T_1 * V_8 = V_6 -> V_8 ;
unsigned int V_32 = F_13 ( V_49 -> V_32 , V_8 ) ;
struct V_58 * V_73 ;
T_4 V_37 = V_74 | V_75 ;
T_4 V_39 = 0 ;
T_4 V_55 = 0 ;
T_6 V_76 ;
V_73 = (struct V_58 * ) V_36 -> V_77 + V_32 ;
V_76 = V_36 -> V_42 + V_32 * V_43 ;
F_26 ( & V_49 -> V_78 , V_49 -> V_20 -> V_79 -> V_80 , 1 , ( T_5 * ) & V_73 -> V_81 ) ;
F_18 ( L_18 ,
V_73 -> V_81 [ 0 ] , V_73 -> V_81 [ 1 ] , V_73 -> V_81 [ 2 ] ) ;
if ( V_49 -> V_78 . V_82 == V_83 ) {
F_18 ( L_19 ,
V_73 -> V_81 [ 3 ] , V_73 -> V_81 [ 11 ] ) ;
}
if ( F_27 ( V_49 -> V_78 . V_82 ) ) {
V_37 |= V_84 ;
memset ( ( void * ) & V_73 -> V_85 , 0 , 32 ) ;
memcpy ( ( void * ) & V_73 -> V_85 , V_49 -> V_86 , V_49 -> V_20 -> V_87 ) ;
}
if ( V_49 -> V_9 & V_88 )
V_39 = F_19 ( V_49 , ( void * ) V_73 ,
& V_55 , V_76 ,
V_6 -> V_52 ) ;
if ( V_49 -> V_78 . V_82 == V_83 )
V_37 |= V_89 ;
F_16 ( V_36 , V_32 , V_37 , V_55 ,
V_39 , 5 ) ;
F_18 ( L_20 ,
V_37 , V_55 , V_39 ) ;
}
static unsigned int F_28 ( struct V_48 * V_49 )
{
struct V_72 * V_68 = V_49 -> V_68 ;
struct V_5 * V_6 = V_68 -> V_2 -> V_7 ;
void T_1 * V_8 = V_6 -> V_8 ;
unsigned int V_32 = F_13 ( V_49 -> V_32 , V_8 ) ;
F_18 ( L_21 ,
F_6 ( V_34 + V_8 ) ,
F_6 ( V_90 + V_8 ) ,
F_6 ( V_91 + V_8 ) , F_6 ( V_92 + V_8 ) ) ;
F_3 ( V_49 -> V_20 -> V_79 -> V_80 , V_93 + V_8 ) ;
F_3 ( 1 << V_32 , V_34 + V_8 ) ;
F_18 ( L_22 ,
V_32 , F_6 ( V_34 + V_8 ) , F_6 ( V_90 + V_8 ) ) ;
F_18 ( L_23 ,
F_6 ( V_91 + V_8 ) ,
F_6 ( V_94 + V_8 ) ,
F_6 ( V_92 + V_8 ) ,
F_6 ( V_95 + V_6 -> V_29 ) ) ;
return 0 ;
}
static bool F_29 ( struct V_48 * V_49 )
{
struct V_35 * V_36 = V_49 -> V_68 -> V_7 ;
struct V_5 * V_6 = V_49 -> V_68 -> V_2 -> V_7 ;
void T_1 * V_8 = V_6 -> V_8 ;
unsigned int V_32 = F_13 ( V_49 -> V_32 , V_8 ) ;
struct V_58 * V_73 ;
V_73 = V_36 -> V_77 + V_32 ;
F_30 ( V_73 -> V_96 , & V_49 -> V_97 ) ;
return true ;
}
static int F_31 ( struct V_98 * V_79 ,
unsigned int V_99 , T_4 V_100 )
{
struct V_5 * V_6 = V_79 -> V_68 -> V_2 -> V_7 ;
void T_1 * V_101 = V_6 -> V_101 ;
unsigned int V_102 ;
switch ( V_99 ) {
case V_103 :
case V_104 :
case V_105 :
case V_106 :
V_102 = V_99 ;
break;
default:
return - V_27 ;
}
F_18 ( L_24 , V_102 ) ;
F_3 ( V_100 , V_101 + ( V_102 * 4 ) ) ;
return 0 ;
}
static int F_32 ( struct V_98 * V_79 ,
unsigned int V_99 , T_4 * V_100 )
{
struct V_5 * V_6 = V_79 -> V_68 -> V_2 -> V_7 ;
void T_1 * V_101 = V_6 -> V_101 ;
unsigned int V_102 ;
switch ( V_99 ) {
case V_103 :
case V_104 :
case V_105 :
case V_106 :
V_102 = V_99 ;
break;
default:
return - V_27 ;
}
F_18 ( L_25 , V_102 ) ;
* V_100 = F_6 ( V_101 + ( V_102 * 4 ) ) ;
return 0 ;
}
static void F_33 ( struct V_72 * V_68 )
{
struct V_5 * V_6 = V_68 -> V_2 -> V_7 ;
void T_1 * V_8 = V_6 -> V_8 ;
T_4 V_31 ;
F_18 ( L_26 ,
F_6 ( V_34 + V_8 ) ,
F_6 ( V_90 + V_8 ) ,
F_6 ( V_91 + V_8 ) , F_6 ( V_94 + V_8 ) ) ;
F_18 ( L_27 ,
F_6 ( V_6 -> V_29 + V_95 ) ) ;
V_31 = F_6 ( V_8 + V_107 ) ;
F_3 ( ( V_31 & ~ 0x3F ) , V_8 + V_107 ) ;
F_18 ( L_28 ,
F_6 ( V_8 + V_107 ) , F_6 ( V_8 + V_108 ) ) ;
}
static void F_34 ( struct V_72 * V_68 )
{
struct V_5 * V_6 = V_68 -> V_2 -> V_7 ;
void T_1 * V_8 = V_6 -> V_8 ;
T_4 V_31 ;
V_31 = F_6 ( V_8 + V_108 ) ;
F_18 ( L_29 , ( V_31 & 0x3F ) ) ;
if ( V_31 & 0x3F )
F_3 ( ( V_31 & 0x3F ) , V_8 + V_108 ) ;
V_31 = F_6 ( V_8 + V_107 ) ;
F_3 ( ( V_31 | V_109 ) , V_8 + V_107 ) ;
F_18 ( L_30 ,
F_6 ( V_8 + V_107 ) , F_6 ( V_8 + V_108 ) ) ;
}
static void F_35 ( struct V_72 * V_68 )
{
struct V_5 * V_6 = V_68 -> V_2 -> V_7 ;
void T_1 * V_8 = V_6 -> V_8 ;
T_4 V_31 ;
V_31 = F_6 ( V_8 + V_107 ) ;
F_3 ( ( V_31 | V_110 ) , V_8 + V_107 ) ;
}
static void F_36 ( struct V_72 * V_68 )
{
struct V_5 * V_6 = V_68 -> V_2 -> V_7 ;
void T_1 * V_8 = V_6 -> V_8 ;
T_4 V_31 ;
V_31 = F_6 ( V_8 + V_107 ) ;
V_31 &= ~ V_110 ;
F_3 ( V_31 , V_8 + V_107 ) ;
V_31 = F_6 ( V_8 + V_107 ) ;
F_3 ( ( V_31 | V_109 ) , V_8 + V_107 ) ;
}
static int F_37 ( struct V_72 * V_68 )
{
struct V_19 * V_20 = V_68 -> V_2 -> V_20 ;
struct V_35 * V_36 ;
void * V_111 ;
T_6 V_112 ;
struct V_5 * V_6 = V_68 -> V_2 -> V_7 ;
void T_1 * V_8 = V_6 -> V_8 ;
T_4 V_31 ;
V_36 = F_38 ( sizeof( * V_36 ) , V_113 ) ;
if ( ! V_36 )
return - V_114 ;
V_111 = F_39 ( V_20 , V_115 , & V_112 ,
V_113 ) ;
if ( ! V_111 ) {
F_40 ( V_36 ) ;
return - V_114 ;
}
V_36 -> V_44 = V_111 ;
V_36 -> V_116 = V_112 ;
V_111 += V_117 ;
V_112 += V_117 ;
V_36 -> V_77 = V_111 ;
V_36 -> V_42 = V_112 ;
V_68 -> V_7 = V_36 ;
F_18 ( L_31 ,
V_36 -> V_116 , V_36 -> V_42 ) ;
F_3 ( V_36 -> V_116 & 0xffffffff , V_8 + V_118 ) ;
V_31 = F_6 ( V_8 + V_107 ) ;
F_3 ( ( V_31 | V_119 ) , V_8 + V_107 ) ;
F_18 ( L_32 , F_6 ( V_8 + V_108 ) ) ;
F_18 ( L_33 , F_6 ( V_8 + V_107 ) ) ;
F_18 ( L_34 , F_6 ( V_8 + V_118 ) ) ;
return 0 ;
}
static void F_41 ( struct V_72 * V_68 )
{
struct V_19 * V_20 = V_68 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_68 -> V_7 ;
struct V_5 * V_6 = V_68 -> V_2 -> V_7 ;
void T_1 * V_8 = V_6 -> V_8 ;
T_4 V_31 ;
V_31 = F_6 ( V_8 + V_107 ) ;
V_31 &= ~ V_119 ;
V_31 |= V_120 ;
F_3 ( V_31 , V_8 + V_107 ) ;
F_42 ( V_68 , V_8 + V_108 , V_121 , V_121 , 1 , 1 ) ;
V_68 -> V_7 = NULL ;
F_43 ( V_20 , V_115 ,
V_36 -> V_44 , V_36 -> V_116 ) ;
F_40 ( V_36 ) ;
}
static unsigned int F_44 ( struct V_72 * V_68 )
{
struct V_5 * V_6 = V_68 -> V_2 -> V_7 ;
void T_1 * V_8 = V_6 -> V_8 ;
struct V_122 V_78 ;
T_4 V_31 ;
V_31 = F_6 ( V_8 + V_123 ) ;
F_18 ( L_35 , V_31 ) ;
F_18 ( L_32 , F_6 ( V_8 + V_108 ) ) ;
F_18 ( L_33 , F_6 ( V_8 + V_107 ) ) ;
V_78 . V_124 = ( V_31 >> 24 ) & 0xff ;
V_78 . V_125 = ( V_31 >> 16 ) & 0xff ;
V_78 . V_126 = ( V_31 >> 8 ) & 0xff ;
V_78 . V_127 = V_31 & 0xff ;
return F_45 ( & V_78 ) ;
}
static int F_46 ( struct V_98 * V_79 , unsigned int * V_128 ,
unsigned long V_129 )
{
struct V_72 * V_68 = V_79 -> V_68 ;
struct V_5 * V_6 = V_68 -> V_2 -> V_7 ;
void T_1 * V_8 = V_6 -> V_8 ;
T_4 V_31 ;
int V_130 = 0 ;
unsigned long V_131 ;
F_5 ( L_36 ) ;
V_132:
V_31 = F_6 ( V_8 + V_107 ) ;
V_31 &= ~ V_119 ;
F_3 ( V_31 , V_8 + V_107 ) ;
V_31 = F_42 ( V_68 , V_8 + V_108 , V_121 , V_121 ,
1 , 500 ) ;
if ( V_31 & V_121 ) {
F_23 ( V_68 , L_37 , V_130 ) ;
V_130 ++ ;
if ( V_130 == 2 )
goto V_133;
else
goto V_132;
}
F_5 ( L_38 ) ;
F_18 ( L_32 , F_6 ( V_8 + V_108 ) ) ;
F_18 ( L_33 , F_6 ( V_8 + V_107 ) ) ;
F_47 ( V_68 , 1 ) ;
F_48 ( V_79 ) ;
V_31 = F_6 ( V_8 + V_107 ) ;
V_31 |= ( V_119 | V_134 ) ;
V_31 |= V_110 ;
F_3 ( V_31 , V_8 + V_107 ) ;
V_31 = F_42 ( V_68 , V_8 + V_108 , V_121 , 0 , 1 , 500 ) ;
if ( ! ( V_31 & V_121 ) ) {
F_23 ( V_68 , L_39 ) ;
goto V_133;
}
F_5 ( L_40 ) ;
F_18 ( L_32 , F_6 ( V_8 + V_108 ) ) ;
F_18 ( L_33 , F_6 ( V_8 + V_107 ) ) ;
V_31 = F_42 ( V_68 , V_8 + V_108 , 0xFF , 0 , 1 , 500 ) ;
if ( ( ! ( V_31 & 0x10 ) ) || F_49 ( V_79 ) ) {
F_50 ( V_68 , L_41 ,
F_6 ( V_8 + V_108 ) ) ;
* V_128 = V_135 ;
return 0 ;
}
V_131 = V_136 ;
V_31 = F_42 ( V_68 , V_8 + V_108 , 0xFF , 0x10 ,
500 , F_51 ( V_129 - V_131 ) ) ;
if ( ( V_31 & 0xFF ) != 0x18 ) {
F_50 ( V_68 , L_42 ) ;
* V_128 = V_135 ;
goto V_137;
} else {
F_52 ( V_68 , L_43 ,
F_51 ( V_136 - V_131 ) ) ;
* V_128 = F_44 ( V_68 ) ;
return 0 ;
}
V_137:
return - V_138 ;
V_133:
return - V_139 ;
}
static int F_53 ( struct V_98 * V_79 , unsigned int * V_128 ,
unsigned long V_129 )
{
struct V_72 * V_68 = V_79 -> V_68 ;
struct V_35 * V_36 = V_68 -> V_7 ;
struct V_5 * V_6 = V_68 -> V_2 -> V_7 ;
void T_1 * V_8 = V_6 -> V_8 ;
int V_80 = F_54 ( V_79 ) ;
T_4 V_31 ;
struct V_122 V_78 ;
T_5 * V_81 ;
T_4 V_140 ;
F_5 ( L_44 ) ;
if ( F_49 ( V_79 ) ) {
F_5 ( L_45 ) ;
* V_128 = V_135 ;
return 0 ;
}
F_5 ( L_46 ) ;
F_55 ( V_79 -> V_19 , & V_78 ) ;
V_81 = ( T_5 * ) & V_36 -> V_77 -> V_81 ;
F_16 ( V_36 , 0 ,
V_141 | V_74 | V_75 , 0 , 0 , 5 ) ;
V_78 . V_142 |= V_143 ;
F_26 ( & V_78 , V_80 , 0 , V_81 ) ;
F_5 ( L_47 ,
V_81 [ 0 ] , V_81 [ 1 ] , V_81 [ 2 ] , V_81 [ 3 ] ) ;
F_5 ( L_48 ,
F_6 ( V_34 + V_8 ) ,
F_6 ( V_90 + V_8 ) , F_6 ( V_92 + V_8 ) ) ;
F_3 ( 0xFFFF , V_92 + V_8 ) ;
if ( V_80 != V_144 )
F_3 ( V_80 , V_93 + V_8 ) ;
F_3 ( 1 , V_34 + V_8 ) ;
V_31 = F_42 ( V_68 , V_34 + V_8 , 0x1 , 0x1 , 1 , 5000 ) ;
if ( V_31 & 0x1 ) {
F_50 ( V_68 , L_49 ) ;
F_5 ( L_50 ,
F_6 ( V_34 + V_8 ) ,
F_6 ( V_90 + V_8 ) , F_6 ( V_92 + V_8 ) ) ;
F_32 ( & V_68 -> V_79 , V_104 , & V_140 ) ;
F_5 ( L_32 , F_6 ( V_8 + V_108 ) ) ;
F_5 ( L_33 , F_6 ( V_8 + V_107 ) ) ;
F_5 ( L_51 , V_140 ) ;
goto V_133;
}
F_47 ( V_68 , 1 ) ;
F_16 ( V_36 , 0 , V_74 | V_75 ,
0 , 0 , 5 ) ;
V_78 . V_142 &= ~ V_143 ;
F_26 ( & V_78 , V_80 , 0 , V_81 ) ;
if ( V_80 != V_144 )
F_3 ( V_80 , V_93 + V_8 ) ;
F_3 ( 1 , V_34 + V_8 ) ;
F_47 ( V_68 , 150 ) ;
F_3 ( 0x01 , V_92 + V_8 ) ;
F_5 ( L_52 ) ;
* V_128 = V_135 ;
if ( F_56 ( V_79 ) ) {
* V_128 = F_44 ( V_68 ) ;
F_5 ( L_53 , * V_128 ) ;
F_18 ( L_54 , F_6 ( V_8 + V_92 ) ) ;
F_18 ( L_55 , F_6 ( V_8 + V_91 ) ) ;
}
return 0 ;
V_133:
return - V_139 ;
}
static void F_57 ( struct V_72 * V_68 )
{
F_5 ( L_56 ) ;
F_58 ( V_68 ) ;
}
static void F_59 ( struct V_48 * V_49 )
{
if ( V_49 -> V_9 & V_145 )
V_49 -> V_146 |= V_147 ;
if ( V_49 -> V_146 ) {
}
}
static void F_60 ( struct V_72 * V_68 )
{
struct V_5 * V_6 = V_68 -> V_2 -> V_7 ;
void T_1 * V_8 = V_6 -> V_8 ;
T_4 V_148 , V_149 = 0 , V_150 = 0 , V_151 = 0 ;
unsigned int V_146 = 0 , V_152 = 0 ;
int V_153 = 0 , abort = 0 ;
struct V_98 * V_79 = NULL ;
struct V_48 * V_49 = NULL ;
struct V_154 * V_155 ;
V_148 = F_6 ( V_8 + V_108 ) ;
V_150 = F_6 ( V_8 + V_91 ) ;
V_79 = & V_68 -> V_79 ;
V_155 = & V_79 -> V_156 ;
F_61 ( V_155 ) ;
F_32 ( & V_68 -> V_79 , V_104 , & V_151 ) ;
if ( F_15 ( V_151 & 0xFFFF0000 ) )
F_31 ( & V_68 -> V_79 , V_104 , V_151 ) ;
F_5 ( L_57 ,
V_148 , V_150 , F_6 ( V_8 + V_94 ) , V_151 ) ;
if ( V_148 & V_157 ) {
V_155 -> V_146 |= V_158 ;
V_155 -> V_152 |= V_159 ;
V_153 = 1 ;
}
if ( V_148 & V_160 )
F_62 ( V_68 ) ;
if ( V_148 & V_161 ) {
F_5 ( L_58 ) ;
F_63 ( V_155 ) ;
F_64 ( V_155 , L_59 , L_60 ) ;
V_153 = 1 ;
}
if ( V_150 ) {
abort = 1 ;
F_5 ( L_61 ,
F_6 ( V_8 + V_91 ) , F_6 ( V_8 + V_94 ) ) ;
if ( V_68 -> V_162 ) {
unsigned int V_163 ;
V_149 = F_6 ( V_8 + V_94 ) ;
F_3 ( V_149 , V_8 + V_94 ) ;
F_3 ( V_150 , V_8 + V_91 ) ;
V_163 = F_65 ( V_149 ) - 1 ;
if ( V_163 < V_68 -> V_162 && V_149 != 0 ) {
V_79 = & V_68 -> V_164 [ V_163 ] ;
V_155 = & V_79 -> V_156 ;
V_49 = F_66 ( V_68 , V_79 -> V_165 ) ;
V_146 |= V_166 ;
} else {
V_146 |= V_167 ;
V_152 |= V_168 ;
V_153 = 1 ;
}
} else {
V_149 = F_6 ( V_8 + V_94 ) ;
F_3 ( V_149 , V_8 + V_94 ) ;
F_3 ( V_150 , V_8 + V_91 ) ;
V_49 = F_66 ( V_68 , V_79 -> V_165 ) ;
V_146 |= V_166 ;
}
}
if ( V_49 )
V_49 -> V_146 |= V_146 ;
else
V_155 -> V_146 |= V_146 ;
V_155 -> V_152 |= V_152 ;
if ( V_153 )
F_67 ( V_68 ) ;
else if ( abort ) {
if ( V_49 )
F_68 ( V_49 -> V_20 -> V_79 ) ;
else
F_69 ( V_68 ) ;
}
}
static void F_70 ( struct V_72 * V_68 )
{
struct V_5 * V_6 = V_68 -> V_2 -> V_7 ;
void T_1 * V_8 = V_6 -> V_8 ;
T_4 V_148 , V_169 = 0 ;
struct V_48 * V_49 ;
T_4 V_151 ;
T_4 V_32 ;
T_4 V_170 = V_171 ;
V_148 = F_6 ( V_8 + V_108 ) ;
F_32 ( & V_68 -> V_79 , V_104 , & V_151 ) ;
V_169 = F_6 ( V_8 + V_92 ) ;
if ( F_15 ( V_148 & V_172 ) ) {
for ( V_32 = 0 ; V_32 < V_173 ; V_32 ++ ) {
V_49 = F_66 ( V_68 , V_32 ) ;
if ( V_49 && F_27 ( V_49 -> V_78 . V_82 ) ) {
T_4 V_174 ;
V_174 = F_6 ( V_8 + V_107 ) ;
F_3 ( V_174 | V_175 ,
V_8 + V_107 ) ;
F_3 ( V_174 & ~ V_175 ,
V_8 + V_107 ) ;
F_31 ( & V_68 -> V_79 , V_104 ,
V_151 ) ;
V_170 &= ~ ( V_176
| V_177 ) ;
break;
}
}
}
if ( F_15 ( V_151 & 0xFFFF0000 ) ) {
F_5 ( L_62 , V_151 ) ;
F_60 ( V_68 ) ;
}
if ( F_15 ( V_148 & V_170 ) ) {
F_5 ( L_63 ) ;
F_60 ( V_68 ) ;
return;
}
F_18 ( L_64 ) ;
F_18 ( L_65 ,
V_169 ,
F_6 ( V_8 + V_90 ) ,
F_6 ( V_8 + V_91 ) ,
F_6 ( V_8 + V_34 ) ,
V_68 -> V_178 ) ;
if ( V_169 & V_68 -> V_178 ) {
int V_130 ;
F_3 ( V_169 , V_8 + V_92 ) ;
F_5 ( L_64 ) ;
F_5 ( L_66 ,
V_169 , F_6 ( V_8 + V_90 ) ,
F_6 ( V_8 + V_91 ) ) ;
for ( V_130 = 0 ; V_130 < V_33 ; V_130 ++ ) {
if ( V_169 & ( 1 << V_130 ) )
F_5
( L_67 ,
V_130 , F_6 ( V_8 + V_92 ) ,
F_6 ( V_8 + V_90 ) ) ;
}
F_71 ( V_68 , V_68 -> V_178 ^ V_169 ) ;
return;
} else if ( ( V_68 -> V_178 & ( 1 << V_179 ) ) ) {
F_3 ( 1 , V_8 + V_92 ) ;
V_49 = F_66 ( V_68 , V_179 ) ;
F_5 ( L_68 ,
F_6 ( V_8 + V_92 ) ) ;
if ( V_49 ) {
F_72 ( V_49 ) ;
}
} else {
F_5 ( L_69 ,
F_6 ( V_8 + V_92 ) ) ;
F_3 ( V_169 , V_8 + V_92 ) ;
return;
}
}
static T_7 F_73 ( int V_180 , void * V_181 )
{
struct V_1 * V_2 = V_181 ;
struct V_5 * V_6 = V_2 -> V_7 ;
void T_1 * V_8 = V_6 -> V_8 ;
T_4 V_182 ;
unsigned V_183 = 0 ;
struct V_72 * V_68 ;
V_182 = F_6 ( V_8 + V_108 ) ;
V_182 &= 0x3F ;
F_5 ( L_70 , V_182 ) ;
if ( ! V_182 )
return V_184 ;
F_74 ( & V_2 -> V_15 ) ;
V_68 = V_2 -> V_185 [ 0 ] ;
if ( V_68 ) {
F_70 ( V_68 ) ;
} else {
F_75 ( V_2 -> V_20 , L_71 ) ;
}
F_3 ( V_182 , V_8 + V_108 ) ;
V_183 = 1 ;
F_76 ( & V_2 -> V_15 ) ;
return F_77 ( V_183 ) ;
}
static int F_78 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
void T_1 * V_8 = V_6 -> V_8 ;
T_4 V_31 ;
V_31 = F_6 ( V_8 + V_107 ) ;
F_3 ( V_31 & ~ V_186 , V_8 + V_107 ) ;
V_31 = F_6 ( V_8 + V_108 ) ;
if ( V_31 & 0x3F )
F_3 ( ( V_31 & 0x3F ) , V_8 + V_108 ) ;
V_31 = F_6 ( V_8 + V_107 ) ;
F_3 ( ( V_31 & ~ 0x3F ) , V_8 + V_107 ) ;
F_5 ( L_72 , F_6 ( V_8 + V_16 ) ) ;
F_3 ( 0x01000000 , V_8 + V_16 ) ;
F_3 ( 0x00000FFFF , V_8 + V_91 ) ;
F_3 ( 0x00000FFFF , V_8 + V_94 ) ;
F_1 ( V_2 , V_17 ,
V_18 ) ;
F_5 ( L_32 , F_6 ( V_8 + V_108 ) ) ;
F_5 ( L_33 , F_6 ( V_8 + V_107 ) ) ;
return 0 ;
}
static int F_79 ( struct V_187 * V_188 )
{
int V_189 = - V_190 ;
void T_1 * V_8 = NULL ;
void T_1 * V_101 = NULL ;
void T_1 * V_29 = NULL ;
struct V_5 * V_6 = NULL ;
int V_180 ;
struct V_1 * V_2 = NULL ;
T_4 V_31 ;
struct F_52 V_191 = V_192 [ 0 ] ;
const struct F_52 * V_193 [] = { & V_191 , NULL } ;
F_80 ( & V_188 -> V_20 , L_73 ) ;
V_8 = F_81 ( V_188 -> V_20 . V_194 , 0 ) ;
if ( ! V_8 )
goto V_195;
V_101 = V_8 + 0x100 ;
V_29 = V_8 + 0x140 ;
if ( ! F_82 ( V_188 -> V_20 . V_194 , L_74 ) ) {
V_31 = F_6 ( V_29 + V_30 ) ;
V_31 = V_31 & 0xffffffe0 ;
F_3 ( V_31 | V_196 , V_29 + V_30 ) ;
}
F_5 ( L_75 , F_6 ( V_29 + V_30 ) ) ;
F_5 ( L_76 , sizeof( struct V_58 ) ) ;
F_5 ( L_77 , V_43 ) ;
V_6 = F_38 ( sizeof( struct V_5 ) , V_113 ) ;
if ( ! V_6 )
goto V_195;
V_6 -> V_8 = V_8 ;
V_6 -> V_101 = V_101 ;
V_6 -> V_29 = V_29 ;
V_180 = F_83 ( V_188 -> V_20 . V_194 , 0 ) ;
if ( ! V_180 ) {
F_84 ( & V_188 -> V_20 , L_78 ) ;
goto V_195;
}
V_6 -> V_180 = V_180 ;
if ( F_82 ( V_188 -> V_20 . V_194 , L_79 ) )
V_6 -> V_52 = V_197 ;
else
V_6 -> V_52 = V_198 ;
V_2 = F_85 ( & V_188 -> V_20 , V_193 , V_199 ) ;
if ( ! V_2 ) {
V_189 = - V_114 ;
goto V_195;
}
V_2 -> V_7 = V_6 ;
F_78 ( V_2 ) ;
F_86 ( V_2 , V_180 , F_73 , V_200 ,
& V_201 ) ;
V_6 -> V_202 . V_203 = F_7 ;
V_6 -> V_202 . V_204 = F_8 ;
F_87 ( & V_6 -> V_202 . V_22 ) ;
V_6 -> V_202 . V_22 . V_205 = L_80 ;
V_6 -> V_202 . V_22 . V_206 = V_207 | V_208 ;
V_189 = F_88 ( V_2 -> V_20 , & V_6 -> V_202 ) ;
if ( V_189 )
goto V_195;
V_6 -> V_28 . V_203 = F_11 ;
V_6 -> V_28 . V_204 = F_12 ;
F_87 ( & V_6 -> V_28 . V_22 ) ;
V_6 -> V_28 . V_22 . V_205 = L_81 ;
V_6 -> V_28 . V_22 . V_206 = V_207 | V_208 ;
V_189 = F_88 ( V_2 -> V_20 , & V_6 -> V_28 ) ;
if ( V_189 ) {
F_89 ( & V_188 -> V_20 , & V_6 -> V_202 ) ;
goto V_195;
}
return 0 ;
V_195:
if ( V_2 )
F_90 ( V_2 ) ;
if ( V_8 )
F_91 ( V_8 ) ;
F_40 ( V_6 ) ;
return V_189 ;
}
static int F_92 ( struct V_187 * V_188 )
{
struct V_1 * V_2 = F_93 ( V_188 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_89 ( & V_188 -> V_20 , & V_6 -> V_202 ) ;
F_89 ( & V_188 -> V_20 , & V_6 -> V_28 ) ;
F_90 ( V_2 ) ;
F_94 ( V_6 -> V_180 ) ;
F_91 ( V_6 -> V_8 ) ;
F_40 ( V_6 ) ;
return 0 ;
}
static int F_95 ( struct V_187 * V_209 , T_8 V_210 )
{
struct V_1 * V_2 = F_93 ( V_209 ) ;
return F_96 ( V_2 , V_210 ) ;
}
static int F_97 ( struct V_187 * V_209 )
{
struct V_1 * V_2 = F_93 ( V_209 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_211 ;
void T_1 * V_8 = V_6 -> V_8 ;
struct V_72 * V_68 = V_2 -> V_185 [ 0 ] ;
struct V_35 * V_36 = V_68 -> V_7 ;
V_211 = F_78 ( V_2 ) ;
if ( V_211 ) {
F_84 ( & V_209 -> V_20 , L_82 ) ;
return V_211 ;
}
F_3 ( V_36 -> V_116 & 0xffffffff , V_8 + V_118 ) ;
F_3 ( ( F_6 ( V_8 + V_107 )
| V_119
| V_134
| V_110 ) ,
V_8 + V_107 ) ;
F_98 ( V_2 ) ;
return 0 ;
}
