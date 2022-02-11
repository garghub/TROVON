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
static int F_25 ( struct V_24 * V_25 , unsigned int * V_26 ,
unsigned long V_27 )
{
const unsigned long * V_47 = F_19 ( & V_25 -> V_32 ) ;
struct V_28 * V_29 = V_25 -> V_29 ;
struct V_35 * V_36 = V_29 -> V_16 ;
struct V_3 * V_4 = V_29 -> V_14 -> V_16 ;
T_4 * V_37 = V_36 -> V_38 + V_39 ;
unsigned long V_48 = V_27 - V_44 ;
struct V_40 V_41 ;
bool V_30 ;
int V_31 , V_49 ;
F_16 ( L_4 ) ;
F_17 ( V_29 ) ;
for ( V_49 = 0 ; V_49 < 2 ; V_49 ++ ) {
T_1 V_50 ;
T_3 V_51 ;
int V_52 = V_29 -> V_53 ;
struct V_13 * V_14 = V_29 -> V_14 ;
struct V_1 * V_2 = F_5 ( V_14 -> V_8 ) ;
F_21 ( V_25 -> V_7 , & V_41 ) ;
V_41 . V_42 = V_43 ;
F_22 ( & V_41 , 0 , 0 , V_37 ) ;
V_31 = F_18 ( V_25 , V_47 , V_27 , & V_30 ,
V_46 ) ;
if ( F_26 ( V_25 , V_54 , & V_51 ) != 0 ||
( V_51 & 0xf ) != 1 )
break;
F_27 ( V_25 , V_55 , L_6 ,
V_52 ) ;
F_7 ( V_2 , 0x92 , & V_50 ) ;
V_50 &= ~ ( 1 << V_52 ) ;
F_8 ( V_2 , 0x92 , V_50 ) ;
F_28 ( V_29 , 1000 ) ;
V_50 |= 1 << V_52 ;
F_8 ( V_2 , 0x92 , V_50 ) ;
V_27 += V_48 ;
}
V_4 -> V_33 ( V_29 ) ;
if ( V_30 )
* V_26 = F_29 ( V_29 ) ;
F_16 ( L_5 , V_31 , * V_26 ) ;
return V_31 ;
}
static int F_30 ( struct V_1 * V_2 , T_5 V_56 )
{
struct V_13 * V_14 = F_31 ( V_2 ) ;
struct V_3 * V_4 = V_14 -> V_16 ;
void T_2 * V_57 = V_4 -> V_57 ;
T_3 V_58 ;
if ( V_56 . V_59 & V_60 &&
V_4 -> V_10 & V_61 ) {
F_32 ( & V_2 -> V_8 ,
L_7 ) ;
return - V_62 ;
}
if ( V_56 . V_59 & V_63 ) {
V_58 = F_12 ( V_57 + V_64 ) ;
V_58 &= ~ V_65 ;
F_11 ( V_58 , V_57 + V_64 ) ;
F_12 ( V_57 + V_64 ) ;
}
return F_33 ( V_2 , V_56 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_31 ( V_2 ) ;
int V_31 ;
V_31 = F_35 ( V_2 ) ;
if ( V_31 )
return V_31 ;
if ( F_36 ( V_2 ) )
F_37 ( V_2 ) ;
if ( V_2 -> V_8 . V_66 . V_67 . V_59 == V_60 ) {
V_31 = F_4 ( V_14 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_14 ) ;
}
F_38 ( V_14 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , int V_68 )
{
int V_31 ;
if ( V_2 -> V_69 && V_2 -> V_69 < F_40 ( 32 ) )
return 0 ;
if ( V_68 &&
! F_41 ( & V_2 -> V_8 , F_40 ( 64 ) ) ) {
V_31 = F_42 ( & V_2 -> V_8 , F_40 ( 64 ) ) ;
if ( V_31 ) {
V_31 = F_42 ( & V_2 -> V_8 , F_40 ( 32 ) ) ;
if ( V_31 ) {
F_32 ( & V_2 -> V_8 ,
L_8 ) ;
return V_31 ;
}
}
} else {
V_31 = F_41 ( & V_2 -> V_8 , F_40 ( 32 ) ) ;
if ( V_31 ) {
F_32 ( & V_2 -> V_8 , L_9 ) ;
return V_31 ;
}
V_31 = F_42 ( & V_2 -> V_8 , F_40 ( 32 ) ) ;
if ( V_31 ) {
F_32 ( & V_2 -> V_8 ,
L_10 ) ;
return V_31 ;
}
}
return 0 ;
}
static void F_43 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_5 ( V_14 -> V_8 ) ;
T_1 V_70 ;
const char * V_71 ;
F_7 ( V_2 , 0x0a , & V_70 ) ;
if ( V_70 == V_72 )
V_71 = L_11 ;
else if ( V_70 == V_73 )
V_71 = L_12 ;
else if ( V_70 == V_74 )
V_71 = L_13 ;
else
V_71 = L_14 ;
F_44 ( V_14 , V_71 ) ;
}
static void F_45 ( struct V_13 * V_14 )
{
static const struct V_75 V_76 [] = {
{
. V_77 = L_15 ,
. V_78 = {
F_46 ( V_79 ,
L_16 ) ,
F_46 ( V_80 , L_15 ) ,
} ,
} ,
{ }
} ;
struct V_1 * V_2 = F_5 ( V_14 -> V_8 ) ;
if ( V_2 -> V_81 -> V_82 == 0 && V_2 -> V_83 == F_47 ( 0x1f , 2 ) &&
F_48 ( V_76 ) ) {
struct V_28 * V_29 = V_14 -> V_84 [ 1 ] ;
F_2 ( & V_2 -> V_8 ,
L_17 ) ;
V_29 -> V_85 = & V_86 ;
V_29 -> V_25 . V_10 |= V_87 | V_88 ;
}
}
static void F_37 ( struct V_1 * V_2 )
{
T_3 V_50 ;
F_49 ( V_55 L_18 ) ;
F_50 ( V_2 , 0xf8 , & V_50 ) ;
V_50 |= 1 << 0x1b ;
F_51 ( V_2 , 0xf8 , V_50 ) ;
F_50 ( V_2 , 0x54c , & V_50 ) ;
V_50 |= 1 << 0xc ;
F_51 ( V_2 , 0x54c , V_50 ) ;
F_50 ( V_2 , 0x4a4 , & V_50 ) ;
V_50 &= 0xff ;
V_50 |= 0x01060100 ;
F_51 ( V_2 , 0x4a4 , V_50 ) ;
F_50 ( V_2 , 0x54c , & V_50 ) ;
V_50 &= ~ ( 1 << 0xc ) ;
F_51 ( V_2 , 0x54c , V_50 ) ;
F_50 ( V_2 , 0xf8 , & V_50 ) ;
V_50 &= ~ ( 1 << 0x1b ) ;
F_51 ( V_2 , 0xf8 , V_50 ) ;
}
static bool F_36 ( struct V_1 * V_2 )
{
return V_2 -> V_5 == V_89 &&
V_2 -> V_7 == V_90 &&
V_2 -> V_91 == V_92 &&
V_2 -> V_93 == 0xcb89 ;
}
static bool F_52 ( struct V_1 * V_2 )
{
static const struct V_75 V_76 [] = {
{
. V_77 = L_19 ,
. V_78 = {
F_46 ( V_94 ,
L_20 ) ,
F_46 ( V_95 , L_21 ) ,
} ,
. V_96 = L_22 ,
} ,
{
. V_77 = L_23 ,
. V_78 = {
F_46 ( V_94 ,
L_24 ) ,
F_46 ( V_95 , L_25 ) ,
} ,
} ,
{
. V_77 = L_26 ,
. V_78 = {
F_46 ( V_94 ,
L_24 ) ,
F_46 ( V_95 , L_27 ) ,
} ,
} ,
{
. V_77 = L_28 ,
. V_78 = {
F_46 ( V_94 ,
L_20 ) ,
F_46 ( V_95 , L_29 ) ,
} ,
} ,
{ }
} ;
const struct V_75 * V_97 ;
int V_98 , V_99 , V_100 ;
char V_101 [ 9 ] ;
V_97 = F_53 ( V_76 ) ;
if ( V_2 -> V_81 -> V_82 != 0 || V_2 -> V_83 != F_47 ( 0x12 , 0 ) ||
! V_97 )
return false ;
if ( ! V_97 -> V_96 )
goto V_102;
F_54 ( V_103 , & V_98 , & V_99 , & V_100 ) ;
snprintf ( V_101 , sizeof( V_101 ) , L_30 , V_98 , V_99 , V_100 ) ;
if ( strcmp ( V_101 , V_97 -> V_96 ) >= 0 )
goto V_102;
else {
F_55 ( & V_2 -> V_8 ,
L_31 ,
V_97 -> V_77 ) ;
return false ;
}
V_102:
F_55 ( & V_2 -> V_8 , L_32 , V_97 -> V_77 ) ;
return true ;
}
static bool F_56 ( struct V_1 * V_2 )
{
static const struct V_75 V_104 [] = {
{
. V_77 = L_33 ,
. V_78 = {
F_46 ( V_79 , L_34 ) ,
F_46 ( V_80 , L_33 ) ,
} ,
. V_96 = ( void * ) 0x1FUL ,
} ,
{
. V_77 = L_35 ,
. V_78 = {
F_46 ( V_79 , L_34 ) ,
F_46 ( V_80 , L_35 ) ,
} ,
. V_96 = ( void * ) 0x1FUL ,
} ,
{ }
} ;
const struct V_75 * V_105 = F_53 ( V_104 ) ;
if ( V_105 ) {
unsigned long V_106 = ( unsigned long ) V_105 -> V_96 ;
return V_106 == F_57 ( V_2 -> V_83 ) ;
}
return false ;
}
static bool F_58 ( struct V_1 * V_2 )
{
static const struct V_75 V_76 [] = {
{
. V_77 = L_36 ,
. V_78 = {
F_46 ( V_79 , L_34 ) ,
F_46 ( V_80 ,
L_37 ) ,
} ,
. V_96 = L_38 ,
} ,
{
. V_77 = L_39 ,
. V_78 = {
F_46 ( V_79 , L_34 ) ,
F_46 ( V_80 ,
L_40 ) ,
} ,
. V_96 = L_41 ,
} ,
{
. V_77 = L_42 ,
. V_78 = {
F_46 ( V_79 , L_34 ) ,
F_46 ( V_80 ,
L_43 ) ,
} ,
. V_96 = L_44 ,
} ,
{
. V_77 = L_45 ,
. V_78 = {
F_46 ( V_79 , L_34 ) ,
F_46 ( V_80 ,
L_46 ) ,
} ,
. V_96 = L_47 ,
} ,
{
. V_77 = L_48 ,
. V_78 = {
F_46 ( V_79 , L_49 ) ,
F_46 ( V_80 , L_50 ) ,
} ,
. V_96 = L_51 ,
} ,
{ }
} ;
const struct V_75 * V_105 = F_53 ( V_76 ) ;
int V_98 , V_99 , V_100 ;
char V_101 [ 9 ] ;
if ( ! V_105 || V_2 -> V_81 -> V_82 || V_2 -> V_83 != F_47 ( 0x1f , 2 ) )
return false ;
F_54 ( V_103 , & V_98 , & V_99 , & V_100 ) ;
snprintf ( V_101 , sizeof( V_101 ) , L_30 , V_98 , V_99 , V_100 ) ;
return strcmp ( V_101 , V_105 -> V_96 ) < 0 ;
}
static bool F_59 ( struct V_1 * V_2 )
{
#define F_60 ( V_81 , V_106 , T_6 ) \
(void *)(unsigned long)(((bus) << 8) | PCI_DEVFN((slot), (func)))
static const struct V_75 V_76 [] = {
{
. V_77 = L_52 ,
. V_78 = {
F_46 ( V_94 ,
L_53 ) ,
F_46 ( V_95 , L_52 ) ,
} ,
. V_96 = F_60 ( 0x0a , 0x00 , 0 ) ,
} ,
{
. V_77 = L_54 ,
. V_78 = {
F_46 ( V_94 ,
L_53 ) ,
F_46 ( V_95 , L_54 ) ,
} ,
. V_96 = F_60 ( 0x03 , 0x00 , 0 ) ,
} ,
{ }
} ;
#undef F_60
const struct V_75 * V_105 = F_53 ( V_76 ) ;
unsigned int V_50 ;
if ( ! V_105 )
return false ;
V_50 = ( unsigned long ) V_105 -> V_96 ;
return V_2 -> V_81 -> V_82 == ( V_50 >> 8 ) && V_2 -> V_83 == ( V_50 & 0xff ) ;
}
static bool F_61 ( struct V_1 * V_2 )
{
static const struct V_107 V_108 [] = {
{ F_62 (INTEL, 0x0f23 ) } ,
{}
} ;
return F_63 ( V_108 , V_2 ) ;
}
static void F_64 ( struct V_13 * V_14 )
{
static const struct V_75 V_76 [] = {
{
. V_77 = L_55 ,
. V_78 = {
F_46 ( V_79 , L_56 ) ,
F_46 ( V_80 , L_55 ) ,
} ,
. V_96 = ( void * ) V_109 ,
} ,
{ }
} ;
const struct V_75 * V_105 = F_53 ( V_76 ) ;
unsigned int V_110 ;
int V_49 ;
if ( ! V_105 )
return;
V_110 = ( unsigned long ) V_105 -> V_96 ;
F_2 ( V_14 -> V_8 , L_57 ,
V_110 , V_105 -> V_77 ) ;
for ( V_49 = 0 ; V_49 < V_14 -> V_111 ; V_49 ++ ) {
struct V_28 * V_29 = V_14 -> V_84 [ V_49 ] ;
struct V_24 * V_25 ;
struct V_112 * V_8 ;
F_65 (link, ap, EDGE)
F_66 (dev, link, ALL)
V_8 -> V_113 |= V_110 ;
}
}
static inline void F_64 ( struct V_13 * V_14 )
{}
static int F_67 ( struct V_1 * V_2 , unsigned int V_111 ,
struct V_3 * V_4 )
{
int V_31 , V_114 ;
if ( V_4 -> V_10 & V_115 )
goto V_116;
V_114 = F_68 ( V_2 ) ;
if ( V_114 < 0 )
goto V_116;
if ( V_114 < V_111 )
goto V_117;
V_31 = F_69 ( V_2 , V_114 ) ;
if ( V_31 == - V_118 )
goto V_117;
else if ( V_31 < 0 )
goto V_116;
if ( F_12 ( V_4 -> V_57 + V_64 ) & V_119 ) {
F_70 ( V_2 ) ;
F_49 ( V_55 L_58 ) ;
goto V_117;
}
if ( V_114 > 1 )
V_4 -> V_10 |= V_120 ;
return V_114 ;
V_117:
if ( F_71 ( V_2 ) )
goto V_116;
return 1 ;
V_116:
F_72 ( V_2 , 1 ) ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 , const struct V_107 * V_121 )
{
unsigned int V_122 = V_121 -> V_96 ;
struct V_123 V_124 = V_125 [ V_122 ] ;
const struct V_123 * V_126 [] = { & V_124 , NULL } ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_3 * V_4 ;
struct V_13 * V_14 ;
int V_111 , V_49 , V_31 ;
int V_127 = V_128 ;
F_13 ( L_4 ) ;
F_74 ( ( int ) V_129 > V_130 ) ;
F_75 ( & V_2 -> V_8 , V_131 ) ;
if ( V_2 -> V_5 == V_132 && ! V_133 )
return - V_134 ;
if ( F_36 ( V_2 ) )
F_37 ( V_2 ) ;
if ( V_2 -> V_5 == V_135 )
F_2 ( & V_2 -> V_8 ,
L_59 ) ;
if ( V_2 -> V_5 == V_136 && V_2 -> V_7 == 0xCC06 )
V_127 = V_137 ;
else if ( V_2 -> V_5 == 0x1c44 && V_2 -> V_7 == 0x8000 )
V_127 = V_138 ;
if ( V_2 -> V_5 == V_6 &&
( V_2 -> V_7 == V_139 ||
V_2 -> V_7 == V_140 ) )
F_76 ( & V_2 -> V_8 ) ;
V_31 = F_77 ( V_2 ) ;
if ( V_31 )
return V_31 ;
if ( V_2 -> V_5 == V_15 &&
( V_2 -> V_7 == 0x2652 || V_2 -> V_7 == 0x2653 ) ) {
T_4 V_141 ;
F_78 ( V_2 , V_142 , & V_141 ) ;
if ( V_141 & 0x3 ) {
F_2 ( & V_2 -> V_8 ,
L_60 ) ;
return - V_134 ;
}
}
V_31 = F_79 ( V_2 , 1 << V_127 , V_143 ) ;
if ( V_31 == - V_144 )
F_80 ( V_2 ) ;
if ( V_31 )
return V_31 ;
V_4 = F_81 ( V_8 , sizeof( * V_4 ) , V_145 ) ;
if ( ! V_4 )
return - V_146 ;
V_4 -> V_10 |= ( unsigned long ) V_124 . V_16 ;
if ( V_122 == V_147 &&
( V_2 -> V_148 == 0xa1 || V_2 -> V_148 == 0xa2 ) )
V_4 -> V_10 |= V_115 ;
if ( V_122 == V_149 && V_2 -> V_148 >= 0x40 )
V_4 -> V_10 &= ~ V_150 ;
if ( F_52 ( V_2 ) )
V_4 -> V_10 &= ~ V_151 ;
V_4 -> V_57 = F_82 ( V_2 ) [ V_127 ] ;
if ( F_61 ( V_2 ) )
V_4 -> V_10 |= V_152 ;
F_1 ( V_2 , V_4 ) ;
if ( V_4 -> V_153 & V_154 ) {
V_124 . V_10 |= V_155 ;
if ( ! ( V_4 -> V_10 & V_156 ) )
V_124 . V_10 |= V_157 ;
V_124 . V_10 |= V_158 ;
}
if ( V_4 -> V_153 & V_159 )
V_124 . V_10 |= V_160 ;
F_83 ( V_4 , & V_124 ) ;
if ( F_56 ( V_2 ) ) {
V_124 . V_10 |= V_161 ;
F_2 ( & V_2 -> V_8 ,
L_61 ) ;
}
if ( F_58 ( V_2 ) ) {
V_4 -> V_10 |= V_61 ;
F_55 ( & V_2 -> V_8 ,
L_7 ) ;
}
if ( F_59 ( V_2 ) ) {
V_4 -> V_10 |= V_162 ;
F_2 ( & V_2 -> V_8 ,
L_62 ) ;
}
V_111 = F_84 ( F_85 ( V_4 -> V_153 ) , F_86 ( V_4 -> V_18 ) ) ;
F_67 ( V_2 , V_111 , V_4 ) ;
V_14 = F_87 ( & V_2 -> V_8 , V_126 , V_111 ) ;
if ( ! V_14 )
return - V_146 ;
V_14 -> V_16 = V_4 ;
if ( ! ( V_4 -> V_153 & V_163 ) || V_164 )
V_14 -> V_10 |= V_165 ;
else
F_2 ( & V_2 -> V_8 , L_63 ) ;
if ( V_124 . V_10 & V_166 )
F_88 ( V_14 ) ;
for ( V_49 = 0 ; V_49 < V_14 -> V_111 ; V_49 ++ ) {
struct V_28 * V_29 = V_14 -> V_84 [ V_49 ] ;
F_89 ( V_29 , V_127 , - 1 , L_64 ) ;
F_89 ( V_29 , V_127 ,
0x100 + V_29 -> V_53 * 0x80 , L_65 ) ;
if ( V_29 -> V_10 & V_166 )
V_29 -> V_167 = V_4 -> V_168 ;
if ( ! ( V_4 -> V_18 & ( 1 << V_49 ) ) )
V_29 -> V_85 = & V_169 ;
}
F_45 ( V_14 ) ;
F_64 ( V_14 ) ;
V_31 = F_39 ( V_2 , V_4 -> V_153 & V_170 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_4 ( V_14 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_14 ) ;
F_43 ( V_14 ) ;
F_90 ( V_2 ) ;
return F_91 ( V_14 , V_2 -> V_171 , & V_172 ) ;
}
