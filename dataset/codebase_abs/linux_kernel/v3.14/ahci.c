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
static int F_15 ( struct V_24 * V_25 , unsigned int * V_26 ,
unsigned long V_27 )
{
struct V_28 * V_29 = V_25 -> V_29 ;
bool V_30 ;
int V_31 ;
F_16 ( L_4 ) ;
F_17 ( V_29 ) ;
V_31 = F_18 ( V_25 , F_19 ( & V_25 -> V_32 ) ,
V_27 , & V_30 , NULL ) ;
F_20 ( V_29 ) ;
F_16 ( L_5 , V_31 , * V_26 ) ;
return V_30 ? - V_33 : V_31 ;
}
static int F_21 ( struct V_24 * V_25 , unsigned int * V_26 ,
unsigned long V_27 )
{
struct V_28 * V_29 = V_25 -> V_29 ;
struct V_34 * V_35 = V_29 -> V_16 ;
T_4 * V_36 = V_35 -> V_37 + V_38 ;
struct V_39 V_40 ;
bool V_30 ;
int V_31 ;
F_17 ( V_29 ) ;
F_22 ( V_25 -> V_9 , & V_40 ) ;
V_40 . V_41 = V_42 ;
F_23 ( & V_40 , 0 , 0 , V_36 ) ;
V_31 = F_18 ( V_25 , F_19 ( & V_25 -> V_32 ) ,
V_27 , & V_30 , NULL ) ;
F_20 ( V_29 ) ;
if ( V_30 ) {
V_31 = F_24 ( V_25 , V_43 + 2 * V_44 ,
V_45 ) ;
if ( V_31 )
F_25 ( V_29 ) ;
}
return V_31 ;
}
static int F_26 ( struct V_1 * V_2 , T_5 V_46 )
{
struct V_13 * V_14 = F_27 ( V_2 ) ;
struct V_3 * V_4 = V_14 -> V_16 ;
void T_2 * V_47 = V_4 -> V_47 ;
T_3 V_48 ;
if ( V_46 . V_49 & V_50 &&
V_4 -> V_11 & V_51 ) {
F_28 ( & V_2 -> V_10 ,
L_6 ) ;
return - V_52 ;
}
if ( V_46 . V_49 & V_53 ) {
V_48 = F_12 ( V_47 + V_54 ) ;
V_48 &= ~ V_55 ;
F_11 ( V_48 , V_47 + V_54 ) ;
F_12 ( V_47 + V_54 ) ;
}
return F_29 ( V_2 , V_46 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_27 ( V_2 ) ;
int V_31 ;
V_31 = F_31 ( V_2 ) ;
if ( V_31 )
return V_31 ;
if ( F_32 ( V_2 ) )
F_33 ( V_2 ) ;
if ( V_2 -> V_10 . V_56 . V_57 . V_49 == V_50 ) {
V_31 = F_4 ( V_14 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_14 ) ;
}
F_34 ( V_14 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , int V_58 )
{
int V_31 ;
if ( V_2 -> V_59 && V_2 -> V_59 < F_36 ( 32 ) )
return 0 ;
if ( V_58 &&
! F_37 ( V_2 , F_36 ( 64 ) ) ) {
V_31 = F_38 ( V_2 , F_36 ( 64 ) ) ;
if ( V_31 ) {
V_31 = F_38 ( V_2 , F_36 ( 32 ) ) ;
if ( V_31 ) {
F_28 ( & V_2 -> V_10 ,
L_7 ) ;
return V_31 ;
}
}
} else {
V_31 = F_37 ( V_2 , F_36 ( 32 ) ) ;
if ( V_31 ) {
F_28 ( & V_2 -> V_10 , L_8 ) ;
return V_31 ;
}
V_31 = F_38 ( V_2 , F_36 ( 32 ) ) ;
if ( V_31 ) {
F_28 ( & V_2 -> V_10 ,
L_9 ) ;
return V_31 ;
}
}
return 0 ;
}
static void F_39 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_5 ( V_14 -> V_10 ) ;
T_1 V_60 ;
const char * V_61 ;
F_7 ( V_2 , 0x0a , & V_60 ) ;
if ( V_60 == V_62 )
V_61 = L_10 ;
else if ( V_60 == V_63 )
V_61 = L_11 ;
else if ( V_60 == V_64 )
V_61 = L_12 ;
else
V_61 = L_13 ;
F_40 ( V_14 , V_61 ) ;
}
static void F_41 ( struct V_13 * V_14 )
{
static struct V_65 V_66 [] = {
{
. V_67 = L_14 ,
. V_68 = {
F_42 ( V_69 ,
L_15 ) ,
F_42 ( V_70 , L_14 ) ,
} ,
} ,
{ }
} ;
struct V_1 * V_2 = F_5 ( V_14 -> V_10 ) ;
if ( V_2 -> V_71 -> V_72 == 0 && V_2 -> V_73 == F_43 ( 0x1f , 2 ) &&
F_44 ( V_66 ) ) {
struct V_28 * V_29 = V_14 -> V_74 [ 1 ] ;
F_2 ( & V_2 -> V_10 ,
L_16 ) ;
V_29 -> V_75 = & V_76 ;
V_29 -> V_25 . V_11 |= V_77 | V_78 ;
}
}
static void F_33 ( struct V_1 * V_2 )
{
T_3 V_79 ;
F_45 ( V_80 L_17 ) ;
F_46 ( V_2 , 0xf8 , & V_79 ) ;
V_79 |= 1 << 0x1b ;
F_47 ( V_2 , 0xf8 , V_79 ) ;
F_46 ( V_2 , 0x54c , & V_79 ) ;
V_79 |= 1 << 0xc ;
F_47 ( V_2 , 0x54c , V_79 ) ;
F_46 ( V_2 , 0x4a4 , & V_79 ) ;
V_79 &= 0xff ;
V_79 |= 0x01060100 ;
F_47 ( V_2 , 0x4a4 , V_79 ) ;
F_46 ( V_2 , 0x54c , & V_79 ) ;
V_79 &= ~ ( 1 << 0xc ) ;
F_47 ( V_2 , 0x54c , V_79 ) ;
F_46 ( V_2 , 0xf8 , & V_79 ) ;
V_79 &= ~ ( 1 << 0x1b ) ;
F_47 ( V_2 , 0xf8 , V_79 ) ;
}
static bool F_32 ( struct V_1 * V_2 )
{
return V_2 -> V_7 == V_81 &&
V_2 -> V_9 == V_82 &&
V_2 -> V_83 == V_84 &&
V_2 -> V_85 == 0xcb89 ;
}
static bool F_48 ( struct V_1 * V_2 )
{
static const struct V_65 V_66 [] = {
{
. V_67 = L_18 ,
. V_68 = {
F_42 ( V_86 ,
L_19 ) ,
F_42 ( V_87 , L_20 ) ,
} ,
. V_88 = L_21 ,
} ,
{
. V_67 = L_22 ,
. V_68 = {
F_42 ( V_86 ,
L_23 ) ,
F_42 ( V_87 , L_24 ) ,
} ,
} ,
{
. V_67 = L_25 ,
. V_68 = {
F_42 ( V_86 ,
L_23 ) ,
F_42 ( V_87 , L_26 ) ,
} ,
} ,
{
. V_67 = L_27 ,
. V_68 = {
F_42 ( V_86 ,
L_19 ) ,
F_42 ( V_87 , L_28 ) ,
} ,
} ,
{ }
} ;
const struct V_65 * V_89 ;
int V_90 , V_91 , V_92 ;
char V_93 [ 9 ] ;
V_89 = F_49 ( V_66 ) ;
if ( V_2 -> V_71 -> V_72 != 0 || V_2 -> V_73 != F_43 ( 0x12 , 0 ) ||
! V_89 )
return false ;
if ( ! V_89 -> V_88 )
goto V_94;
F_50 ( V_95 , & V_90 , & V_91 , & V_92 ) ;
snprintf ( V_93 , sizeof( V_93 ) , L_29 , V_90 , V_91 , V_92 ) ;
if ( strcmp ( V_93 , V_89 -> V_88 ) >= 0 )
goto V_94;
else {
F_51 ( & V_2 -> V_10 ,
L_30 ,
V_89 -> V_67 ) ;
return false ;
}
V_94:
F_51 ( & V_2 -> V_10 , L_31 , V_89 -> V_67 ) ;
return true ;
}
static bool F_52 ( struct V_1 * V_2 )
{
static const struct V_65 V_96 [] = {
{
. V_67 = L_32 ,
. V_68 = {
F_42 ( V_69 , L_33 ) ,
F_42 ( V_70 , L_32 ) ,
} ,
. V_88 = ( void * ) 0x1FUL ,
} ,
{
. V_67 = L_34 ,
. V_68 = {
F_42 ( V_69 , L_33 ) ,
F_42 ( V_70 , L_34 ) ,
} ,
. V_88 = ( void * ) 0x1FUL ,
} ,
{ }
} ;
const struct V_65 * V_97 = F_49 ( V_96 ) ;
if ( V_97 ) {
unsigned long V_98 = ( unsigned long ) V_97 -> V_88 ;
return V_98 == F_53 ( V_2 -> V_73 ) ;
}
return false ;
}
static bool F_54 ( struct V_1 * V_2 )
{
static const struct V_65 V_66 [] = {
{
. V_67 = L_35 ,
. V_68 = {
F_42 ( V_69 , L_33 ) ,
F_42 ( V_70 ,
L_36 ) ,
} ,
. V_88 = L_37 ,
} ,
{
. V_67 = L_38 ,
. V_68 = {
F_42 ( V_69 , L_33 ) ,
F_42 ( V_70 ,
L_39 ) ,
} ,
. V_88 = L_40 ,
} ,
{
. V_67 = L_41 ,
. V_68 = {
F_42 ( V_69 , L_33 ) ,
F_42 ( V_70 ,
L_42 ) ,
} ,
. V_88 = L_43 ,
} ,
{
. V_67 = L_44 ,
. V_68 = {
F_42 ( V_69 , L_33 ) ,
F_42 ( V_70 ,
L_45 ) ,
} ,
. V_88 = L_46 ,
} ,
{
. V_67 = L_47 ,
. V_68 = {
F_42 ( V_69 , L_48 ) ,
F_42 ( V_70 , L_49 ) ,
} ,
. V_88 = L_50 ,
} ,
{ }
} ;
const struct V_65 * V_97 = F_49 ( V_66 ) ;
int V_90 , V_91 , V_92 ;
char V_93 [ 9 ] ;
if ( ! V_97 || V_2 -> V_71 -> V_72 || V_2 -> V_73 != F_43 ( 0x1f , 2 ) )
return false ;
F_50 ( V_95 , & V_90 , & V_91 , & V_92 ) ;
snprintf ( V_93 , sizeof( V_93 ) , L_29 , V_90 , V_91 , V_92 ) ;
return strcmp ( V_93 , V_97 -> V_88 ) < 0 ;
}
static bool F_55 ( struct V_1 * V_2 )
{
#define F_56 ( V_71 , V_98 , T_6 ) \
(void *)(unsigned long)(((bus) << 8) | PCI_DEVFN((slot), (func)))
static const struct V_65 V_66 [] = {
{
. V_67 = L_51 ,
. V_68 = {
F_42 ( V_86 ,
L_52 ) ,
F_42 ( V_87 , L_51 ) ,
} ,
. V_88 = F_56 ( 0x0a , 0x00 , 0 ) ,
} ,
{
. V_67 = L_53 ,
. V_68 = {
F_42 ( V_86 ,
L_52 ) ,
F_42 ( V_87 , L_53 ) ,
} ,
. V_88 = F_56 ( 0x03 , 0x00 , 0 ) ,
} ,
{ }
} ;
#undef F_56
const struct V_65 * V_97 = F_49 ( V_66 ) ;
unsigned int V_79 ;
if ( ! V_97 )
return false ;
V_79 = ( unsigned long ) V_97 -> V_88 ;
return V_2 -> V_71 -> V_72 == ( V_79 >> 8 ) && V_2 -> V_73 == ( V_79 & 0xff ) ;
}
static void F_57 ( struct V_13 * V_14 )
{
static const struct V_65 V_66 [] = {
{
. V_67 = L_54 ,
. V_68 = {
F_42 ( V_69 , L_55 ) ,
F_42 ( V_70 , L_54 ) ,
} ,
. V_88 = ( void * ) V_99 ,
} ,
{ }
} ;
const struct V_65 * V_97 = F_49 ( V_66 ) ;
unsigned int V_100 ;
int V_101 ;
if ( ! V_97 )
return;
V_100 = ( unsigned long ) V_97 -> V_88 ;
F_2 ( V_14 -> V_10 , L_56 ,
V_100 , V_97 -> V_67 ) ;
for ( V_101 = 0 ; V_101 < V_14 -> V_102 ; V_101 ++ ) {
struct V_28 * V_29 = V_14 -> V_74 [ V_101 ] ;
struct V_24 * V_25 ;
struct V_103 * V_10 ;
F_58 (link, ap, EDGE)
F_59 (dev, link, ALL)
V_10 -> V_104 |= V_100 ;
}
}
static inline void F_57 ( struct V_13 * V_14 )
{}
static int F_60 ( struct V_1 * V_2 , unsigned int V_102 ,
struct V_3 * V_4 )
{
int V_31 , V_105 ;
if ( V_4 -> V_11 & V_106 )
goto V_107;
V_31 = F_61 ( V_2 ) ;
if ( V_31 < 0 )
goto V_107;
if ( V_31 < V_102 )
goto V_108;
V_105 = V_31 ;
V_31 = F_62 ( V_2 , V_105 ) ;
if ( V_31 < 0 )
goto V_107;
else if ( V_31 > 0 )
goto V_108;
return V_105 ;
V_108:
V_31 = F_63 ( V_2 ) ;
if ( V_31 )
goto V_107;
return 1 ;
V_107:
F_64 ( V_2 , 1 ) ;
return 0 ;
}
int F_65 ( struct V_13 * V_14 , int V_109 , unsigned int V_110 )
{
int V_101 , V_31 ;
if ( V_110 < V_14 -> V_102 )
return - V_111 ;
V_31 = F_66 ( V_14 ) ;
if ( V_31 )
return V_31 ;
for ( V_101 = 0 ; V_101 < V_14 -> V_102 ; V_101 ++ ) {
const char * V_112 ;
struct V_34 * V_35 = V_14 -> V_74 [ V_101 ] -> V_16 ;
if ( V_35 )
V_112 = V_35 -> V_113 ;
else
V_112 = F_67 ( V_14 -> V_10 ) ;
V_31 = F_68 ( V_14 -> V_10 ,
V_109 + V_101 , V_114 , V_115 , V_116 ,
V_112 , V_14 -> V_74 [ V_101 ] ) ;
if ( V_31 )
goto V_117;
}
for ( V_101 = 0 ; V_101 < V_14 -> V_102 ; V_101 ++ )
F_69 ( V_14 -> V_74 [ V_101 ] , L_57 , V_109 + V_101 ) ;
V_31 = F_70 ( V_14 , & V_118 ) ;
if ( V_31 )
goto V_119;
return 0 ;
V_119:
V_101 = V_14 -> V_102 ;
V_117:
for ( V_101 -- ; V_101 >= 0 ; V_101 -- )
F_71 ( V_14 -> V_10 , V_109 + V_101 , V_14 -> V_74 [ V_101 ] ) ;
return V_31 ;
}
static int F_72 ( struct V_1 * V_2 , const struct V_120 * V_121 )
{
unsigned int V_122 = V_121 -> V_88 ;
struct V_123 V_124 = V_125 [ V_122 ] ;
const struct V_123 * V_126 [] = { & V_124 , NULL } ;
struct V_9 * V_10 = & V_2 -> V_10 ;
struct V_3 * V_4 ;
struct V_13 * V_14 ;
int V_102 , V_110 , V_101 , V_31 ;
int V_127 = V_128 ;
F_13 ( L_4 ) ;
F_73 ( ( int ) V_129 > V_130 ) ;
F_74 ( & V_2 -> V_10 , V_131 ) ;
if ( V_2 -> V_7 == V_132 && ! V_133 )
return - V_134 ;
if ( F_32 ( V_2 ) )
F_33 ( V_2 ) ;
if ( V_2 -> V_7 == V_135 )
F_2 ( & V_2 -> V_10 ,
L_58 ) ;
if ( V_2 -> V_7 == V_136 && V_2 -> V_9 == 0xCC06 )
V_127 = V_137 ;
else if ( V_2 -> V_7 == 0x1c44 && V_2 -> V_9 == 0x8000 )
V_127 = V_138 ;
V_31 = F_75 ( V_2 ) ;
if ( V_31 )
return V_31 ;
if ( V_2 -> V_7 == V_15 &&
( V_2 -> V_9 == 0x2652 || V_2 -> V_9 == 0x2653 ) ) {
T_4 V_139 ;
F_76 ( V_2 , V_140 , & V_139 ) ;
if ( V_139 & 0x3 ) {
F_2 ( & V_2 -> V_10 ,
L_59 ) ;
return - V_134 ;
}
}
V_31 = F_77 ( V_2 , 1 << V_127 , V_141 ) ;
if ( V_31 == - V_142 )
F_78 ( V_2 ) ;
if ( V_31 )
return V_31 ;
V_4 = F_79 ( V_10 , sizeof( * V_4 ) , V_143 ) ;
if ( ! V_4 )
return - V_144 ;
V_4 -> V_11 |= ( unsigned long ) V_124 . V_16 ;
if ( V_122 == V_145 &&
( V_2 -> V_146 == 0xa1 || V_2 -> V_146 == 0xa2 ) )
V_4 -> V_11 |= V_106 ;
if ( V_122 == V_147 && V_2 -> V_146 >= 0x40 )
V_4 -> V_11 &= ~ V_148 ;
if ( F_48 ( V_2 ) )
V_4 -> V_11 &= ~ V_149 ;
V_4 -> V_47 = F_80 ( V_2 ) [ V_127 ] ;
F_1 ( V_2 , V_4 ) ;
if ( V_4 -> V_150 & V_151 ) {
V_124 . V_11 |= V_152 ;
if ( ! ( V_4 -> V_11 & V_153 ) )
V_124 . V_11 |= V_154 ;
V_124 . V_11 |= V_155 ;
}
if ( V_4 -> V_150 & V_156 )
V_124 . V_11 |= V_157 ;
F_81 ( V_4 , & V_124 ) ;
if ( F_52 ( V_2 ) ) {
V_124 . V_11 |= V_158 ;
F_2 ( & V_2 -> V_10 ,
L_60 ) ;
}
if ( F_54 ( V_2 ) ) {
V_4 -> V_11 |= V_51 ;
F_51 ( & V_2 -> V_10 ,
L_6 ) ;
}
if ( F_55 ( V_2 ) ) {
V_4 -> V_11 |= V_159 ;
F_2 ( & V_2 -> V_10 ,
L_61 ) ;
}
V_102 = F_82 ( F_83 ( V_4 -> V_150 ) , F_84 ( V_4 -> V_18 ) ) ;
V_110 = F_60 ( V_2 , V_102 , V_4 ) ;
if ( V_110 > 1 )
V_4 -> V_11 |= V_160 ;
V_14 = F_85 ( & V_2 -> V_10 , V_126 , V_102 ) ;
if ( ! V_14 )
return - V_144 ;
V_14 -> V_16 = V_4 ;
if ( ! ( V_4 -> V_150 & V_161 ) || V_162 )
V_14 -> V_11 |= V_163 ;
else
F_2 ( & V_2 -> V_10 , L_62 ) ;
if ( V_124 . V_11 & V_164 )
F_86 ( V_14 ) ;
for ( V_101 = 0 ; V_101 < V_14 -> V_102 ; V_101 ++ ) {
struct V_28 * V_29 = V_14 -> V_74 [ V_101 ] ;
F_87 ( V_29 , V_127 , - 1 , L_63 ) ;
F_87 ( V_29 , V_127 ,
0x100 + V_29 -> V_165 * 0x80 , L_64 ) ;
if ( V_29 -> V_11 & V_164 )
V_29 -> V_166 = V_4 -> V_167 ;
if ( ! ( V_4 -> V_18 & ( 1 << V_101 ) ) )
V_29 -> V_75 = & V_168 ;
}
F_41 ( V_14 ) ;
F_57 ( V_14 ) ;
V_31 = F_35 ( V_2 , V_4 -> V_150 & V_169 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_4 ( V_14 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_14 ) ;
F_39 ( V_14 ) ;
F_88 ( V_2 ) ;
if ( V_4 -> V_11 & V_160 )
return F_65 ( V_14 , V_2 -> V_109 , V_110 ) ;
return F_89 ( V_14 , V_2 -> V_109 , V_170 , V_116 ,
& V_118 ) ;
}
