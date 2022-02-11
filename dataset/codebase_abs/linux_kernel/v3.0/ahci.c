static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_5 = 0 ;
unsigned int V_6 = 0 ;
if ( V_2 -> V_7 == V_8 && V_2 -> V_9 == 0x2361 ) {
F_2 ( & V_2 -> V_10 , L_1 ) ;
V_5 = 1 ;
}
if ( V_4 -> V_11 & V_12 ) {
if ( V_2 -> V_9 == 0x6121 )
V_6 = 0x3 ;
else
V_6 = 0xf ;
F_2 ( & V_2 -> V_10 ,
L_2 ) ;
}
F_3 ( & V_2 -> V_10 , V_4 , V_5 ,
V_6 ) ;
}
static int F_4 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_5 ( V_14 -> V_10 ) ;
F_6 ( V_14 ) ;
if ( V_2 -> V_7 == V_15 ) {
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
struct V_1 * V_2 = F_5 ( V_14 -> V_10 ) ;
void T_2 * V_19 ;
T_3 V_20 ;
int V_21 ;
if ( V_4 -> V_11 & V_12 ) {
if ( V_2 -> V_9 == 0x6121 )
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
static int F_15 ( struct V_24 * V_25 )
{
void T_2 * V_19 = F_16 ( V_25 -> V_26 ) ;
T_4 V_27 = F_12 ( V_19 + V_28 ) & 0xFF ;
T_3 V_29 = F_12 ( V_19 + V_23 ) ;
if ( V_29 & V_30 )
return - V_31 ;
return F_17 ( V_27 ) ;
}
static int F_18 ( struct V_24 * V_25 , unsigned int * V_32 ,
unsigned long V_33 )
{
struct V_34 * V_26 = V_25 -> V_26 ;
void T_2 * V_19 = F_16 ( V_26 ) ;
int V_35 = F_19 ( V_25 ) ;
int V_36 ;
T_3 V_37 ;
F_20 ( L_4 ) ;
V_36 = F_21 ( V_25 , V_32 , V_35 , V_33 ,
F_15 ) ;
if ( V_36 == - V_31 ) {
V_37 = F_12 ( V_19 + V_23 ) ;
if ( V_37 & V_30 ) {
F_22 ( V_25 , V_38 ,
L_5
L_6 ) ;
V_36 = F_21 ( V_25 , V_32 , 0 , V_33 ,
V_39 ) ;
}
}
return V_36 ;
}
static int F_23 ( struct V_24 * V_25 , unsigned int * V_32 ,
unsigned long V_33 )
{
struct V_34 * V_26 = V_25 -> V_26 ;
bool V_40 ;
int V_36 ;
F_20 ( L_4 ) ;
F_24 ( V_26 ) ;
V_36 = F_25 ( V_25 , F_26 ( & V_25 -> V_41 ) ,
V_33 , & V_40 , NULL ) ;
F_27 ( V_26 ) ;
F_20 ( L_7 , V_36 , * V_32 ) ;
return V_40 ? - V_42 : V_36 ;
}
static int F_28 ( struct V_24 * V_25 , unsigned int * V_32 ,
unsigned long V_33 )
{
struct V_34 * V_26 = V_25 -> V_26 ;
struct V_43 * V_44 = V_26 -> V_16 ;
T_4 * V_45 = V_44 -> V_46 + V_47 ;
struct V_48 V_49 ;
bool V_40 ;
int V_36 ;
F_24 ( V_26 ) ;
F_29 ( V_25 -> V_9 , & V_49 ) ;
V_49 . V_50 = 0x80 ;
F_30 ( & V_49 , 0 , 0 , V_45 ) ;
V_36 = F_25 ( V_25 , F_26 ( & V_25 -> V_41 ) ,
V_33 , & V_40 , NULL ) ;
F_27 ( V_26 ) ;
if ( V_40 ) {
V_36 = F_31 ( V_25 , V_51 + 2 * V_52 ,
V_39 ) ;
if ( V_36 )
F_32 ( V_26 ) ;
}
return V_36 ;
}
static int F_33 ( struct V_1 * V_2 , T_5 V_53 )
{
struct V_13 * V_14 = F_34 ( & V_2 -> V_10 ) ;
struct V_3 * V_4 = V_14 -> V_16 ;
void T_2 * V_54 = V_4 -> V_54 ;
T_3 V_55 ;
if ( V_53 . V_56 & V_57 &&
V_4 -> V_11 & V_58 ) {
F_35 ( V_59 , & V_2 -> V_10 ,
L_8 ) ;
return - V_31 ;
}
if ( V_53 . V_56 & V_60 ) {
V_55 = F_12 ( V_54 + V_61 ) ;
V_55 &= ~ V_62 ;
F_11 ( V_55 , V_54 + V_61 ) ;
F_12 ( V_54 + V_61 ) ;
}
return F_36 ( V_2 , V_53 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_34 ( & V_2 -> V_10 ) ;
int V_36 ;
V_36 = F_38 ( V_2 ) ;
if ( V_36 )
return V_36 ;
if ( V_2 -> V_10 . V_63 . V_64 . V_56 == V_57 ) {
V_36 = F_4 ( V_14 ) ;
if ( V_36 )
return V_36 ;
F_9 ( V_14 ) ;
}
F_39 ( V_14 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , int V_65 )
{
int V_36 ;
if ( V_65 &&
! F_41 ( V_2 , F_42 ( 64 ) ) ) {
V_36 = F_43 ( V_2 , F_42 ( 64 ) ) ;
if ( V_36 ) {
V_36 = F_43 ( V_2 , F_42 ( 32 ) ) ;
if ( V_36 ) {
F_35 ( V_59 , & V_2 -> V_10 ,
L_9 ) ;
return V_36 ;
}
}
} else {
V_36 = F_41 ( V_2 , F_42 ( 32 ) ) ;
if ( V_36 ) {
F_35 ( V_59 , & V_2 -> V_10 ,
L_10 ) ;
return V_36 ;
}
V_36 = F_43 ( V_2 , F_42 ( 32 ) ) ;
if ( V_36 ) {
F_35 ( V_59 , & V_2 -> V_10 ,
L_11 ) ;
return V_36 ;
}
}
return 0 ;
}
static void F_44 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_5 ( V_14 -> V_10 ) ;
T_1 V_66 ;
const char * V_67 ;
F_7 ( V_2 , 0x0a , & V_66 ) ;
if ( V_66 == V_68 )
V_67 = L_12 ;
else if ( V_66 == V_69 )
V_67 = L_13 ;
else if ( V_66 == V_70 )
V_67 = L_14 ;
else
V_67 = L_15 ;
F_45 ( V_14 , V_67 ) ;
}
static void F_46 ( struct V_13 * V_14 )
{
static struct V_71 V_72 [] = {
{
. V_73 = L_16 ,
. V_74 = {
F_47 ( V_75 ,
L_17 ) ,
F_47 ( V_76 , L_16 ) ,
} ,
} ,
{ }
} ;
struct V_1 * V_2 = F_5 ( V_14 -> V_10 ) ;
if ( V_2 -> V_77 -> V_78 == 0 && V_2 -> V_79 == F_48 ( 0x1f , 2 ) &&
F_49 ( V_72 ) ) {
struct V_34 * V_26 = V_14 -> V_80 [ 1 ] ;
F_35 ( V_81 , & V_2 -> V_10 , L_18
L_19 ) ;
V_26 -> V_82 = & V_83 ;
V_26 -> V_25 . V_11 |= V_84 | V_85 ;
}
}
static bool F_50 ( struct V_1 * V_2 )
{
static const struct V_71 V_72 [] = {
{
. V_73 = L_20 ,
. V_74 = {
F_47 ( V_86 ,
L_21 ) ,
F_47 ( V_87 , L_22 ) ,
} ,
. V_88 = L_23 ,
} ,
{
. V_73 = L_24 ,
. V_74 = {
F_47 ( V_86 ,
L_25 ) ,
F_47 ( V_87 , L_26 ) ,
} ,
} ,
{ }
} ;
const struct V_71 * V_89 ;
int V_90 , V_91 , V_92 ;
char V_93 [ 9 ] ;
V_89 = F_51 ( V_72 ) ;
if ( V_2 -> V_77 -> V_78 != 0 || V_2 -> V_79 != F_48 ( 0x12 , 0 ) ||
! V_89 )
return false ;
if ( ! V_89 -> V_88 )
goto V_94;
F_52 ( V_95 , & V_90 , & V_91 , & V_92 ) ;
snprintf ( V_93 , sizeof( V_93 ) , L_27 , V_90 , V_91 , V_92 ) ;
if ( strcmp ( V_93 , V_89 -> V_88 ) >= 0 )
goto V_94;
else {
F_35 ( V_38 , & V_2 -> V_10 , L_28
L_29 , V_89 -> V_73 ) ;
return false ;
}
V_94:
F_35 ( V_38 , & V_2 -> V_10 , L_30 ,
V_89 -> V_73 ) ;
return true ;
}
static bool F_53 ( struct V_1 * V_2 )
{
static const struct V_71 V_96 [] = {
{
. V_73 = L_31 ,
. V_74 = {
F_47 ( V_75 , L_32 ) ,
F_47 ( V_76 , L_31 ) ,
} ,
. V_88 = ( void * ) 0x1FUL ,
} ,
{
. V_73 = L_33 ,
. V_74 = {
F_47 ( V_75 , L_32 ) ,
F_47 ( V_76 , L_33 ) ,
} ,
. V_88 = ( void * ) 0x1FUL ,
} ,
{ }
} ;
const struct V_71 * V_97 = F_51 ( V_96 ) ;
if ( V_97 ) {
unsigned long V_98 = ( unsigned long ) V_97 -> V_88 ;
return V_98 == F_54 ( V_2 -> V_79 ) ;
}
return false ;
}
static bool F_55 ( struct V_1 * V_2 )
{
static const struct V_71 V_72 [] = {
{
. V_73 = L_34 ,
. V_74 = {
F_47 ( V_75 , L_32 ) ,
F_47 ( V_76 ,
L_35 ) ,
} ,
. V_88 = L_36 ,
} ,
{
. V_73 = L_37 ,
. V_74 = {
F_47 ( V_75 , L_32 ) ,
F_47 ( V_76 ,
L_38 ) ,
} ,
. V_88 = L_39 ,
} ,
{
. V_73 = L_40 ,
. V_74 = {
F_47 ( V_75 , L_32 ) ,
F_47 ( V_76 ,
L_41 ) ,
} ,
. V_88 = L_42 ,
} ,
{
. V_73 = L_43 ,
. V_74 = {
F_47 ( V_75 , L_32 ) ,
F_47 ( V_76 ,
L_44 ) ,
} ,
. V_88 = L_45 ,
} ,
{
. V_73 = L_46 ,
. V_74 = {
F_47 ( V_75 , L_47 ) ,
F_47 ( V_76 , L_48 ) ,
} ,
. V_88 = L_49 ,
} ,
{ }
} ;
const struct V_71 * V_97 = F_51 ( V_72 ) ;
int V_90 , V_91 , V_92 ;
char V_93 [ 9 ] ;
if ( ! V_97 || V_2 -> V_77 -> V_78 || V_2 -> V_79 != F_48 ( 0x1f , 2 ) )
return false ;
F_52 ( V_95 , & V_90 , & V_91 , & V_92 ) ;
snprintf ( V_93 , sizeof( V_93 ) , L_27 , V_90 , V_91 , V_92 ) ;
return strcmp ( V_93 , V_97 -> V_88 ) < 0 ;
}
static bool F_56 ( struct V_1 * V_2 )
{
#define F_57 ( V_77 , V_98 , T_6 ) \
(void *)(unsigned long)(((bus) << 8) | PCI_DEVFN((slot), (func)))
static const struct V_71 V_72 [] = {
{
. V_73 = L_50 ,
. V_74 = {
F_47 ( V_86 ,
L_51 ) ,
F_47 ( V_87 , L_50 ) ,
} ,
. V_88 = F_57 ( 0x0a , 0x00 , 0 ) ,
} ,
{
. V_73 = L_52 ,
. V_74 = {
F_47 ( V_86 ,
L_51 ) ,
F_47 ( V_87 , L_52 ) ,
} ,
. V_88 = F_57 ( 0x03 , 0x00 , 0 ) ,
} ,
{ }
} ;
#undef F_57
const struct V_71 * V_97 = F_51 ( V_72 ) ;
unsigned int V_99 ;
if ( ! V_97 )
return false ;
V_99 = ( unsigned long ) V_97 -> V_88 ;
return V_2 -> V_77 -> V_78 == ( V_99 >> 8 ) && V_2 -> V_79 == ( V_99 & 0xff ) ;
}
static void F_58 ( struct V_13 * V_14 )
{
static const struct V_71 V_72 [] = {
{
. V_73 = L_53 ,
. V_74 = {
F_47 ( V_75 , L_54 ) ,
F_47 ( V_76 , L_53 ) ,
} ,
. V_88 = ( void * ) V_100 ,
} ,
{ }
} ;
const struct V_71 * V_97 = F_51 ( V_72 ) ;
unsigned int V_101 ;
int V_102 ;
if ( ! V_97 )
return;
V_101 = ( unsigned long ) V_97 -> V_88 ;
F_35 ( V_81 , V_14 -> V_10 ,
L_55 ,
V_101 , V_97 -> V_73 ) ;
for ( V_102 = 0 ; V_102 < V_14 -> V_103 ; V_102 ++ ) {
struct V_34 * V_26 = V_14 -> V_80 [ V_102 ] ;
struct V_24 * V_25 ;
struct V_104 * V_10 ;
F_59 (link, ap, EDGE)
F_60 (dev, link, ALL)
V_10 -> V_105 |= V_101 ;
}
}
static inline void F_58 ( struct V_13 * V_14 )
{}
static int F_61 ( struct V_1 * V_2 , const struct V_106 * V_107 )
{
static int V_108 ;
unsigned int V_109 = V_107 -> V_88 ;
struct V_110 V_111 = V_112 [ V_109 ] ;
const struct V_110 * V_113 [] = { & V_111 , NULL } ;
struct V_9 * V_10 = & V_2 -> V_10 ;
struct V_3 * V_4 ;
struct V_13 * V_14 ;
int V_103 , V_102 , V_36 ;
F_13 ( L_4 ) ;
F_62 ( ( int ) V_114 > V_115 ) ;
if ( ! V_108 ++ )
F_35 ( V_116 , & V_2 -> V_10 , L_56 V_117 L_57 ) ;
if ( V_2 -> V_7 == V_118 && ! V_119 )
return - V_120 ;
if ( V_2 -> V_7 == V_121 &&
V_2 -> V_9 == V_122 &&
V_2 -> V_123 == V_124 &&
V_2 -> V_125 == 0xcb89 )
return - V_120 ;
if ( V_2 -> V_7 == V_126 )
F_35 ( V_81 , & V_2 -> V_10 , L_58
L_59 ) ;
V_36 = F_63 ( V_2 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_64 ( V_2 , 1 << V_127 , V_128 ) ;
if ( V_36 == - V_129 )
F_65 ( V_2 ) ;
if ( V_36 )
return V_36 ;
if ( V_2 -> V_7 == V_15 &&
( V_2 -> V_9 == 0x2652 || V_2 -> V_9 == 0x2653 ) ) {
T_4 V_130 ;
F_66 ( V_2 , V_131 , & V_130 ) ;
if ( V_130 & 0x3 ) {
F_35 ( V_81 , & V_2 -> V_10 , L_60
L_61 ) ;
return - V_120 ;
}
}
V_4 = F_67 ( V_10 , sizeof( * V_4 ) , V_132 ) ;
if ( ! V_4 )
return - V_133 ;
V_4 -> V_11 |= ( unsigned long ) V_111 . V_16 ;
if ( V_109 == V_134 &&
( V_2 -> V_135 == 0xa1 || V_2 -> V_135 == 0xa2 ) )
V_4 -> V_11 |= V_136 ;
if ( V_109 == V_137 && V_2 -> V_135 >= 0x40 )
V_4 -> V_11 &= ~ V_138 ;
if ( F_50 ( V_2 ) )
V_4 -> V_11 &= ~ V_139 ;
if ( ( V_4 -> V_11 & V_136 ) || F_68 ( V_2 ) )
F_69 ( V_2 , 1 ) ;
V_4 -> V_54 = F_70 ( V_2 ) [ V_127 ] ;
F_1 ( V_2 , V_4 ) ;
if ( V_4 -> V_140 & V_141 ) {
V_111 . V_11 |= V_142 ;
if ( ! ( V_4 -> V_11 & V_143 ) )
V_111 . V_11 |= V_144 ;
}
if ( V_4 -> V_140 & V_145 )
V_111 . V_11 |= V_146 ;
F_71 ( V_4 , & V_111 ) ;
if ( F_53 ( V_2 ) ) {
V_111 . V_11 |= V_147 ;
F_2 ( & V_2 -> V_10 ,
L_62 ) ;
}
if ( F_55 ( V_2 ) ) {
V_4 -> V_11 |= V_58 ;
F_35 ( V_38 , & V_2 -> V_10 ,
L_8 ) ;
}
if ( F_56 ( V_2 ) ) {
V_4 -> V_11 |= V_148 ;
F_2 ( & V_2 -> V_10 ,
L_63 ) ;
}
V_103 = F_72 ( F_73 ( V_4 -> V_140 ) , F_74 ( V_4 -> V_18 ) ) ;
V_14 = F_75 ( & V_2 -> V_10 , V_113 , V_103 ) ;
if ( ! V_14 )
return - V_133 ;
V_14 -> V_16 = V_4 ;
if ( ! ( V_4 -> V_140 & V_149 ) || V_150 )
V_14 -> V_11 |= V_151 ;
else
F_76 ( V_81 L_64 ) ;
if ( V_111 . V_11 & V_152 )
F_77 ( V_14 ) ;
for ( V_102 = 0 ; V_102 < V_14 -> V_103 ; V_102 ++ ) {
struct V_34 * V_26 = V_14 -> V_80 [ V_102 ] ;
F_78 ( V_26 , V_127 , - 1 , L_65 ) ;
F_78 ( V_26 , V_127 ,
0x100 + V_26 -> V_153 * 0x80 , L_66 ) ;
if ( V_26 -> V_11 & V_152 )
V_26 -> V_154 = V_4 -> V_155 ;
if ( ! ( V_4 -> V_18 & ( 1 << V_102 ) ) )
V_26 -> V_82 = & V_156 ;
}
F_46 ( V_14 ) ;
F_58 ( V_14 ) ;
V_36 = F_40 ( V_2 , V_4 -> V_140 & V_157 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_4 ( V_14 ) ;
if ( V_36 )
return V_36 ;
F_9 ( V_14 ) ;
F_44 ( V_14 ) ;
F_79 ( V_2 ) ;
return F_80 ( V_14 , V_2 -> V_158 , V_159 , V_160 ,
& V_161 ) ;
}
static int T_7 F_81 ( void )
{
return F_82 ( & V_162 ) ;
}
static void T_8 F_83 ( void )
{
F_84 ( & V_162 ) ;
}
