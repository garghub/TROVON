static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_2 -> V_5 == V_6 && V_2 -> V_7 == 0x2361 ) {
F_2 ( & V_2 -> V_8 , L_1 ) ;
V_4 -> V_9 = 1 ;
}
if ( V_4 -> V_10 & V_11 ) {
if ( V_2 -> V_7 == 0x6121 )
V_4 -> V_12 = 0x3 ;
else
V_4 -> V_12 = 0xf ;
F_2 ( & V_2 -> V_8 ,
L_2 ) ;
}
F_3 ( & V_2 -> V_8 , V_4 ) ;
}
static int F_4 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_5 ( V_14 -> V_8 ) ;
F_6 ( V_14 ) ;
if ( V_2 -> V_5 == V_15 ) {
struct V_3 * V_4 = V_14 -> V_16 ;
T_1 V_17 ;
F_7 ( V_2 , 0x92 , & V_17 ) ;
if ( ( V_17 & V_4 -> V_18 ) != V_4 -> V_18 ) {
V_17 |= V_4 -> V_18 ;
F_8 ( V_2 , 0x92 , V_17 ) ;
}
}
return 0 ;
}
static void F_9 ( struct V_13 * V_14 )
{
struct V_3 * V_4 = V_14 -> V_16 ;
struct V_1 * V_2 = F_5 ( V_14 -> V_8 ) ;
void T_2 * V_19 ;
T_3 V_20 ;
int V_21 ;
if ( V_4 -> V_10 & V_11 ) {
if ( V_2 -> V_7 == 0x6121 )
V_21 = 2 ;
else
V_21 = 4 ;
V_19 = F_10 ( V_14 , V_21 ) ;
F_11 ( 0 , V_19 + V_22 ) ;
V_20 = F_12 ( V_19 + V_23 ) ;
F_13 ( L_3 , V_20 ) ;
if ( V_20 )
F_11 ( V_20 , V_19 + V_23 ) ;
}
F_14 ( V_14 ) ;
}
static int F_15 ( struct V_24 * V_25 , unsigned int * V_26 ,
unsigned long V_27 )
{
struct V_28 * V_29 = V_25 -> V_29 ;
struct V_3 * V_4 = V_29 -> V_14 -> V_16 ;
bool V_30 ;
int V_31 ;
F_16 ( L_4 ) ;
F_17 ( V_29 ) ;
V_31 = F_18 ( V_25 , F_19 ( & V_25 -> V_32 ) ,
V_27 , & V_30 , NULL ) ;
V_4 -> V_33 ( V_29 ) ;
F_16 ( L_5 , V_31 , * V_26 ) ;
return V_30 ? - V_34 : V_31 ;
}
static int F_20 ( struct V_24 * V_25 , unsigned int * V_26 ,
unsigned long V_27 )
{
struct V_28 * V_29 = V_25 -> V_29 ;
struct V_35 * V_36 = V_29 -> V_16 ;
struct V_3 * V_4 = V_29 -> V_14 -> V_16 ;
T_4 * V_37 = V_36 -> V_38 + V_39 ;
struct V_40 V_41 ;
bool V_30 ;
int V_31 ;
F_17 ( V_29 ) ;
F_21 ( V_25 -> V_7 , & V_41 ) ;
V_41 . V_42 = V_43 ;
F_22 ( & V_41 , 0 , 0 , V_37 ) ;
V_31 = F_18 ( V_25 , F_19 ( & V_25 -> V_32 ) ,
V_27 , & V_30 , NULL ) ;
V_4 -> V_33 ( V_29 ) ;
if ( V_30 ) {
V_31 = F_23 ( V_25 , V_44 + 2 * V_45 ,
V_46 ) ;
if ( V_31 )
F_24 ( V_29 ) ;
}
return V_31 ;
}
static int F_25 ( struct V_1 * V_2 , T_5 V_47 )
{
struct V_13 * V_14 = F_26 ( V_2 ) ;
struct V_3 * V_4 = V_14 -> V_16 ;
void T_2 * V_48 = V_4 -> V_48 ;
T_3 V_49 ;
if ( V_47 . V_50 & V_51 &&
V_4 -> V_10 & V_52 ) {
F_27 ( & V_2 -> V_8 ,
L_6 ) ;
return - V_53 ;
}
if ( V_47 . V_50 & V_54 ) {
V_49 = F_12 ( V_48 + V_55 ) ;
V_49 &= ~ V_56 ;
F_11 ( V_49 , V_48 + V_55 ) ;
F_12 ( V_48 + V_55 ) ;
}
return F_28 ( V_2 , V_47 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_26 ( V_2 ) ;
int V_31 ;
V_31 = F_30 ( V_2 ) ;
if ( V_31 )
return V_31 ;
if ( F_31 ( V_2 ) )
F_32 ( V_2 ) ;
if ( V_2 -> V_8 . V_57 . V_58 . V_50 == V_51 ) {
V_31 = F_4 ( V_14 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_14 ) ;
}
F_33 ( V_14 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , int V_59 )
{
int V_31 ;
if ( V_2 -> V_60 && V_2 -> V_60 < F_35 ( 32 ) )
return 0 ;
if ( V_59 &&
! F_36 ( V_2 , F_35 ( 64 ) ) ) {
V_31 = F_37 ( V_2 , F_35 ( 64 ) ) ;
if ( V_31 ) {
V_31 = F_37 ( V_2 , F_35 ( 32 ) ) ;
if ( V_31 ) {
F_27 ( & V_2 -> V_8 ,
L_7 ) ;
return V_31 ;
}
}
} else {
V_31 = F_36 ( V_2 , F_35 ( 32 ) ) ;
if ( V_31 ) {
F_27 ( & V_2 -> V_8 , L_8 ) ;
return V_31 ;
}
V_31 = F_37 ( V_2 , F_35 ( 32 ) ) ;
if ( V_31 ) {
F_27 ( & V_2 -> V_8 ,
L_9 ) ;
return V_31 ;
}
}
return 0 ;
}
static void F_38 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_5 ( V_14 -> V_8 ) ;
T_1 V_61 ;
const char * V_62 ;
F_7 ( V_2 , 0x0a , & V_61 ) ;
if ( V_61 == V_63 )
V_62 = L_10 ;
else if ( V_61 == V_64 )
V_62 = L_11 ;
else if ( V_61 == V_65 )
V_62 = L_12 ;
else
V_62 = L_13 ;
F_39 ( V_14 , V_62 ) ;
}
static void F_40 ( struct V_13 * V_14 )
{
static const struct V_66 V_67 [] = {
{
. V_68 = L_14 ,
. V_69 = {
F_41 ( V_70 ,
L_15 ) ,
F_41 ( V_71 , L_14 ) ,
} ,
} ,
{ }
} ;
struct V_1 * V_2 = F_5 ( V_14 -> V_8 ) ;
if ( V_2 -> V_72 -> V_73 == 0 && V_2 -> V_74 == F_42 ( 0x1f , 2 ) &&
F_43 ( V_67 ) ) {
struct V_28 * V_29 = V_14 -> V_75 [ 1 ] ;
F_2 ( & V_2 -> V_8 ,
L_16 ) ;
V_29 -> V_76 = & V_77 ;
V_29 -> V_25 . V_10 |= V_78 | V_79 ;
}
}
static void F_32 ( struct V_1 * V_2 )
{
T_3 V_80 ;
F_44 ( V_81 L_17 ) ;
F_45 ( V_2 , 0xf8 , & V_80 ) ;
V_80 |= 1 << 0x1b ;
F_46 ( V_2 , 0xf8 , V_80 ) ;
F_45 ( V_2 , 0x54c , & V_80 ) ;
V_80 |= 1 << 0xc ;
F_46 ( V_2 , 0x54c , V_80 ) ;
F_45 ( V_2 , 0x4a4 , & V_80 ) ;
V_80 &= 0xff ;
V_80 |= 0x01060100 ;
F_46 ( V_2 , 0x4a4 , V_80 ) ;
F_45 ( V_2 , 0x54c , & V_80 ) ;
V_80 &= ~ ( 1 << 0xc ) ;
F_46 ( V_2 , 0x54c , V_80 ) ;
F_45 ( V_2 , 0xf8 , & V_80 ) ;
V_80 &= ~ ( 1 << 0x1b ) ;
F_46 ( V_2 , 0xf8 , V_80 ) ;
}
static bool F_31 ( struct V_1 * V_2 )
{
return V_2 -> V_5 == V_82 &&
V_2 -> V_7 == V_83 &&
V_2 -> V_84 == V_85 &&
V_2 -> V_86 == 0xcb89 ;
}
static bool F_47 ( struct V_1 * V_2 )
{
static const struct V_66 V_67 [] = {
{
. V_68 = L_18 ,
. V_69 = {
F_41 ( V_87 ,
L_19 ) ,
F_41 ( V_88 , L_20 ) ,
} ,
. V_89 = L_21 ,
} ,
{
. V_68 = L_22 ,
. V_69 = {
F_41 ( V_87 ,
L_23 ) ,
F_41 ( V_88 , L_24 ) ,
} ,
} ,
{
. V_68 = L_25 ,
. V_69 = {
F_41 ( V_87 ,
L_23 ) ,
F_41 ( V_88 , L_26 ) ,
} ,
} ,
{
. V_68 = L_27 ,
. V_69 = {
F_41 ( V_87 ,
L_19 ) ,
F_41 ( V_88 , L_28 ) ,
} ,
} ,
{ }
} ;
const struct V_66 * V_90 ;
int V_91 , V_92 , V_93 ;
char V_94 [ 9 ] ;
V_90 = F_48 ( V_67 ) ;
if ( V_2 -> V_72 -> V_73 != 0 || V_2 -> V_74 != F_42 ( 0x12 , 0 ) ||
! V_90 )
return false ;
if ( ! V_90 -> V_89 )
goto V_95;
F_49 ( V_96 , & V_91 , & V_92 , & V_93 ) ;
snprintf ( V_94 , sizeof( V_94 ) , L_29 , V_91 , V_92 , V_93 ) ;
if ( strcmp ( V_94 , V_90 -> V_89 ) >= 0 )
goto V_95;
else {
F_50 ( & V_2 -> V_8 ,
L_30 ,
V_90 -> V_68 ) ;
return false ;
}
V_95:
F_50 ( & V_2 -> V_8 , L_31 , V_90 -> V_68 ) ;
return true ;
}
static bool F_51 ( struct V_1 * V_2 )
{
static const struct V_66 V_97 [] = {
{
. V_68 = L_32 ,
. V_69 = {
F_41 ( V_70 , L_33 ) ,
F_41 ( V_71 , L_32 ) ,
} ,
. V_89 = ( void * ) 0x1FUL ,
} ,
{
. V_68 = L_34 ,
. V_69 = {
F_41 ( V_70 , L_33 ) ,
F_41 ( V_71 , L_34 ) ,
} ,
. V_89 = ( void * ) 0x1FUL ,
} ,
{ }
} ;
const struct V_66 * V_98 = F_48 ( V_97 ) ;
if ( V_98 ) {
unsigned long V_99 = ( unsigned long ) V_98 -> V_89 ;
return V_99 == F_52 ( V_2 -> V_74 ) ;
}
return false ;
}
static bool F_53 ( struct V_1 * V_2 )
{
static const struct V_66 V_67 [] = {
{
. V_68 = L_35 ,
. V_69 = {
F_41 ( V_70 , L_33 ) ,
F_41 ( V_71 ,
L_36 ) ,
} ,
. V_89 = L_37 ,
} ,
{
. V_68 = L_38 ,
. V_69 = {
F_41 ( V_70 , L_33 ) ,
F_41 ( V_71 ,
L_39 ) ,
} ,
. V_89 = L_40 ,
} ,
{
. V_68 = L_41 ,
. V_69 = {
F_41 ( V_70 , L_33 ) ,
F_41 ( V_71 ,
L_42 ) ,
} ,
. V_89 = L_43 ,
} ,
{
. V_68 = L_44 ,
. V_69 = {
F_41 ( V_70 , L_33 ) ,
F_41 ( V_71 ,
L_45 ) ,
} ,
. V_89 = L_46 ,
} ,
{
. V_68 = L_47 ,
. V_69 = {
F_41 ( V_70 , L_48 ) ,
F_41 ( V_71 , L_49 ) ,
} ,
. V_89 = L_50 ,
} ,
{ }
} ;
const struct V_66 * V_98 = F_48 ( V_67 ) ;
int V_91 , V_92 , V_93 ;
char V_94 [ 9 ] ;
if ( ! V_98 || V_2 -> V_72 -> V_73 || V_2 -> V_74 != F_42 ( 0x1f , 2 ) )
return false ;
F_49 ( V_96 , & V_91 , & V_92 , & V_93 ) ;
snprintf ( V_94 , sizeof( V_94 ) , L_29 , V_91 , V_92 , V_93 ) ;
return strcmp ( V_94 , V_98 -> V_89 ) < 0 ;
}
static bool F_54 ( struct V_1 * V_2 )
{
#define F_55 ( V_72 , V_99 , T_6 ) \
(void *)(unsigned long)(((bus) << 8) | PCI_DEVFN((slot), (func)))
static const struct V_66 V_67 [] = {
{
. V_68 = L_51 ,
. V_69 = {
F_41 ( V_87 ,
L_52 ) ,
F_41 ( V_88 , L_51 ) ,
} ,
. V_89 = F_55 ( 0x0a , 0x00 , 0 ) ,
} ,
{
. V_68 = L_53 ,
. V_69 = {
F_41 ( V_87 ,
L_52 ) ,
F_41 ( V_88 , L_53 ) ,
} ,
. V_89 = F_55 ( 0x03 , 0x00 , 0 ) ,
} ,
{ }
} ;
#undef F_55
const struct V_66 * V_98 = F_48 ( V_67 ) ;
unsigned int V_80 ;
if ( ! V_98 )
return false ;
V_80 = ( unsigned long ) V_98 -> V_89 ;
return V_2 -> V_72 -> V_73 == ( V_80 >> 8 ) && V_2 -> V_74 == ( V_80 & 0xff ) ;
}
static bool F_56 ( struct V_1 * V_2 )
{
static const struct V_100 V_101 [] = {
{ F_57 (INTEL, 0x0f23 ) } ,
{}
} ;
return F_58 ( V_101 , V_2 ) ;
}
static void F_59 ( struct V_13 * V_14 )
{
static const struct V_66 V_67 [] = {
{
. V_68 = L_54 ,
. V_69 = {
F_41 ( V_70 , L_55 ) ,
F_41 ( V_71 , L_54 ) ,
} ,
. V_89 = ( void * ) V_102 ,
} ,
{ }
} ;
const struct V_66 * V_98 = F_48 ( V_67 ) ;
unsigned int V_103 ;
int V_104 ;
if ( ! V_98 )
return;
V_103 = ( unsigned long ) V_98 -> V_89 ;
F_2 ( V_14 -> V_8 , L_56 ,
V_103 , V_98 -> V_68 ) ;
for ( V_104 = 0 ; V_104 < V_14 -> V_105 ; V_104 ++ ) {
struct V_28 * V_29 = V_14 -> V_75 [ V_104 ] ;
struct V_24 * V_25 ;
struct V_106 * V_8 ;
F_60 (link, ap, EDGE)
F_61 (dev, link, ALL)
V_8 -> V_107 |= V_103 ;
}
}
static inline void F_59 ( struct V_13 * V_14 )
{}
static int F_62 ( struct V_1 * V_2 , unsigned int V_105 ,
struct V_3 * V_4 )
{
int V_31 , V_108 ;
if ( V_4 -> V_10 & V_109 )
goto V_110;
V_108 = F_63 ( V_2 ) ;
if ( V_108 < 0 )
goto V_110;
if ( V_108 < V_105 )
goto V_111;
V_31 = F_64 ( V_2 , V_108 ) ;
if ( V_31 == - V_112 )
goto V_111;
else if ( V_31 < 0 )
goto V_110;
if ( F_12 ( V_4 -> V_48 + V_55 ) & V_113 ) {
F_65 ( V_2 ) ;
F_44 ( V_81 L_57 ) ;
goto V_111;
}
if ( V_108 > 1 )
V_4 -> V_10 |= V_114 ;
return V_108 ;
V_111:
if ( F_66 ( V_2 ) )
goto V_110;
return 1 ;
V_110:
F_67 ( V_2 , 1 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , const struct V_100 * V_115 )
{
unsigned int V_116 = V_115 -> V_89 ;
struct V_117 V_118 = V_119 [ V_116 ] ;
const struct V_117 * V_120 [] = { & V_118 , NULL } ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_3 * V_4 ;
struct V_13 * V_14 ;
int V_105 , V_104 , V_31 ;
int V_121 = V_122 ;
F_13 ( L_4 ) ;
F_69 ( ( int ) V_123 > V_124 ) ;
F_70 ( & V_2 -> V_8 , V_125 ) ;
if ( V_2 -> V_5 == V_126 && ! V_127 )
return - V_128 ;
if ( F_31 ( V_2 ) )
F_32 ( V_2 ) ;
if ( V_2 -> V_5 == V_129 )
F_2 ( & V_2 -> V_8 ,
L_58 ) ;
if ( V_2 -> V_5 == V_130 && V_2 -> V_7 == 0xCC06 )
V_121 = V_131 ;
else if ( V_2 -> V_5 == 0x1c44 && V_2 -> V_7 == 0x8000 )
V_121 = V_132 ;
if ( V_2 -> V_5 == V_6 &&
( V_2 -> V_7 == V_133 ||
V_2 -> V_7 == V_134 ) )
F_71 ( & V_2 -> V_8 ) ;
V_31 = F_72 ( V_2 ) ;
if ( V_31 )
return V_31 ;
if ( V_2 -> V_5 == V_15 &&
( V_2 -> V_7 == 0x2652 || V_2 -> V_7 == 0x2653 ) ) {
T_4 V_135 ;
F_73 ( V_2 , V_136 , & V_135 ) ;
if ( V_135 & 0x3 ) {
F_2 ( & V_2 -> V_8 ,
L_59 ) ;
return - V_128 ;
}
}
V_31 = F_74 ( V_2 , 1 << V_121 , V_137 ) ;
if ( V_31 == - V_138 )
F_75 ( V_2 ) ;
if ( V_31 )
return V_31 ;
V_4 = F_76 ( V_8 , sizeof( * V_4 ) , V_139 ) ;
if ( ! V_4 )
return - V_140 ;
V_4 -> V_10 |= ( unsigned long ) V_118 . V_16 ;
if ( V_116 == V_141 &&
( V_2 -> V_142 == 0xa1 || V_2 -> V_142 == 0xa2 ) )
V_4 -> V_10 |= V_109 ;
if ( V_116 == V_143 && V_2 -> V_142 >= 0x40 )
V_4 -> V_10 &= ~ V_144 ;
if ( F_47 ( V_2 ) )
V_4 -> V_10 &= ~ V_145 ;
V_4 -> V_48 = F_77 ( V_2 ) [ V_121 ] ;
if ( F_56 ( V_2 ) )
V_4 -> V_10 |= V_146 ;
F_1 ( V_2 , V_4 ) ;
if ( V_4 -> V_147 & V_148 ) {
V_118 . V_10 |= V_149 ;
if ( ! ( V_4 -> V_10 & V_150 ) )
V_118 . V_10 |= V_151 ;
V_118 . V_10 |= V_152 ;
}
if ( V_4 -> V_147 & V_153 )
V_118 . V_10 |= V_154 ;
F_78 ( V_4 , & V_118 ) ;
if ( F_51 ( V_2 ) ) {
V_118 . V_10 |= V_155 ;
F_2 ( & V_2 -> V_8 ,
L_60 ) ;
}
if ( F_53 ( V_2 ) ) {
V_4 -> V_10 |= V_52 ;
F_50 ( & V_2 -> V_8 ,
L_6 ) ;
}
if ( F_54 ( V_2 ) ) {
V_4 -> V_10 |= V_156 ;
F_2 ( & V_2 -> V_8 ,
L_61 ) ;
}
V_105 = F_79 ( F_80 ( V_4 -> V_147 ) , F_81 ( V_4 -> V_18 ) ) ;
F_62 ( V_2 , V_105 , V_4 ) ;
V_14 = F_82 ( & V_2 -> V_8 , V_120 , V_105 ) ;
if ( ! V_14 )
return - V_140 ;
V_14 -> V_16 = V_4 ;
if ( ! ( V_4 -> V_147 & V_157 ) || V_158 )
V_14 -> V_10 |= V_159 ;
else
F_2 ( & V_2 -> V_8 , L_62 ) ;
if ( V_118 . V_10 & V_160 )
F_83 ( V_14 ) ;
for ( V_104 = 0 ; V_104 < V_14 -> V_105 ; V_104 ++ ) {
struct V_28 * V_29 = V_14 -> V_75 [ V_104 ] ;
F_84 ( V_29 , V_121 , - 1 , L_63 ) ;
F_84 ( V_29 , V_121 ,
0x100 + V_29 -> V_161 * 0x80 , L_64 ) ;
if ( V_29 -> V_10 & V_160 )
V_29 -> V_162 = V_4 -> V_163 ;
if ( ! ( V_4 -> V_18 & ( 1 << V_104 ) ) )
V_29 -> V_76 = & V_164 ;
}
F_40 ( V_14 ) ;
F_59 ( V_14 ) ;
V_31 = F_34 ( V_2 , V_4 -> V_147 & V_165 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_4 ( V_14 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_14 ) ;
F_38 ( V_14 ) ;
F_85 ( V_2 ) ;
return F_86 ( V_14 , V_2 -> V_166 , & V_167 ) ;
}
