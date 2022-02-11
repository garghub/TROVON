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
if ( V_2 -> V_10 . V_56 . V_57 . V_49 == V_50 ) {
V_31 = F_4 ( V_14 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_14 ) ;
}
F_32 ( V_14 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , int V_58 )
{
int V_31 ;
if ( V_2 -> V_59 && V_2 -> V_59 < F_34 ( 32 ) )
return 0 ;
if ( V_58 &&
! F_35 ( V_2 , F_34 ( 64 ) ) ) {
V_31 = F_36 ( V_2 , F_34 ( 64 ) ) ;
if ( V_31 ) {
V_31 = F_36 ( V_2 , F_34 ( 32 ) ) ;
if ( V_31 ) {
F_28 ( & V_2 -> V_10 ,
L_7 ) ;
return V_31 ;
}
}
} else {
V_31 = F_35 ( V_2 , F_34 ( 32 ) ) ;
if ( V_31 ) {
F_28 ( & V_2 -> V_10 , L_8 ) ;
return V_31 ;
}
V_31 = F_36 ( V_2 , F_34 ( 32 ) ) ;
if ( V_31 ) {
F_28 ( & V_2 -> V_10 ,
L_9 ) ;
return V_31 ;
}
}
return 0 ;
}
static void F_37 ( struct V_13 * V_14 )
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
F_38 ( V_14 , V_61 ) ;
}
static void F_39 ( struct V_13 * V_14 )
{
static struct V_65 V_66 [] = {
{
. V_67 = L_14 ,
. V_68 = {
F_40 ( V_69 ,
L_15 ) ,
F_40 ( V_70 , L_14 ) ,
} ,
} ,
{ }
} ;
struct V_1 * V_2 = F_5 ( V_14 -> V_10 ) ;
if ( V_2 -> V_71 -> V_72 == 0 && V_2 -> V_73 == F_41 ( 0x1f , 2 ) &&
F_42 ( V_66 ) ) {
struct V_28 * V_29 = V_14 -> V_74 [ 1 ] ;
F_2 ( & V_2 -> V_10 ,
L_16 ) ;
V_29 -> V_75 = & V_76 ;
V_29 -> V_25 . V_11 |= V_77 | V_78 ;
}
}
static bool F_43 ( struct V_1 * V_2 )
{
static const struct V_65 V_66 [] = {
{
. V_67 = L_17 ,
. V_68 = {
F_40 ( V_79 ,
L_18 ) ,
F_40 ( V_80 , L_19 ) ,
} ,
. V_81 = L_20 ,
} ,
{
. V_67 = L_21 ,
. V_68 = {
F_40 ( V_79 ,
L_22 ) ,
F_40 ( V_80 , L_23 ) ,
} ,
} ,
{
. V_67 = L_24 ,
. V_68 = {
F_40 ( V_79 ,
L_22 ) ,
F_40 ( V_80 , L_25 ) ,
} ,
} ,
{
. V_67 = L_26 ,
. V_68 = {
F_40 ( V_79 ,
L_18 ) ,
F_40 ( V_80 , L_27 ) ,
} ,
} ,
{ }
} ;
const struct V_65 * V_82 ;
int V_83 , V_84 , V_85 ;
char V_86 [ 9 ] ;
V_82 = F_44 ( V_66 ) ;
if ( V_2 -> V_71 -> V_72 != 0 || V_2 -> V_73 != F_41 ( 0x12 , 0 ) ||
! V_82 )
return false ;
if ( ! V_82 -> V_81 )
goto V_87;
F_45 ( V_88 , & V_83 , & V_84 , & V_85 ) ;
snprintf ( V_86 , sizeof( V_86 ) , L_28 , V_83 , V_84 , V_85 ) ;
if ( strcmp ( V_86 , V_82 -> V_81 ) >= 0 )
goto V_87;
else {
F_46 ( & V_2 -> V_10 ,
L_29 ,
V_82 -> V_67 ) ;
return false ;
}
V_87:
F_46 ( & V_2 -> V_10 , L_30 , V_82 -> V_67 ) ;
return true ;
}
static bool F_47 ( struct V_1 * V_2 )
{
static const struct V_65 V_89 [] = {
{
. V_67 = L_31 ,
. V_68 = {
F_40 ( V_69 , L_32 ) ,
F_40 ( V_70 , L_31 ) ,
} ,
. V_81 = ( void * ) 0x1FUL ,
} ,
{
. V_67 = L_33 ,
. V_68 = {
F_40 ( V_69 , L_32 ) ,
F_40 ( V_70 , L_33 ) ,
} ,
. V_81 = ( void * ) 0x1FUL ,
} ,
{ }
} ;
const struct V_65 * V_90 = F_44 ( V_89 ) ;
if ( V_90 ) {
unsigned long V_91 = ( unsigned long ) V_90 -> V_81 ;
return V_91 == F_48 ( V_2 -> V_73 ) ;
}
return false ;
}
static bool F_49 ( struct V_1 * V_2 )
{
static const struct V_65 V_66 [] = {
{
. V_67 = L_34 ,
. V_68 = {
F_40 ( V_69 , L_32 ) ,
F_40 ( V_70 ,
L_35 ) ,
} ,
. V_81 = L_36 ,
} ,
{
. V_67 = L_37 ,
. V_68 = {
F_40 ( V_69 , L_32 ) ,
F_40 ( V_70 ,
L_38 ) ,
} ,
. V_81 = L_39 ,
} ,
{
. V_67 = L_40 ,
. V_68 = {
F_40 ( V_69 , L_32 ) ,
F_40 ( V_70 ,
L_41 ) ,
} ,
. V_81 = L_42 ,
} ,
{
. V_67 = L_43 ,
. V_68 = {
F_40 ( V_69 , L_32 ) ,
F_40 ( V_70 ,
L_44 ) ,
} ,
. V_81 = L_45 ,
} ,
{
. V_67 = L_46 ,
. V_68 = {
F_40 ( V_69 , L_47 ) ,
F_40 ( V_70 , L_48 ) ,
} ,
. V_81 = L_49 ,
} ,
{ }
} ;
const struct V_65 * V_90 = F_44 ( V_66 ) ;
int V_83 , V_84 , V_85 ;
char V_86 [ 9 ] ;
if ( ! V_90 || V_2 -> V_71 -> V_72 || V_2 -> V_73 != F_41 ( 0x1f , 2 ) )
return false ;
F_45 ( V_88 , & V_83 , & V_84 , & V_85 ) ;
snprintf ( V_86 , sizeof( V_86 ) , L_28 , V_83 , V_84 , V_85 ) ;
return strcmp ( V_86 , V_90 -> V_81 ) < 0 ;
}
static bool F_50 ( struct V_1 * V_2 )
{
#define F_51 ( V_71 , V_91 , T_6 ) \
(void *)(unsigned long)(((bus) << 8) | PCI_DEVFN((slot), (func)))
static const struct V_65 V_66 [] = {
{
. V_67 = L_50 ,
. V_68 = {
F_40 ( V_79 ,
L_51 ) ,
F_40 ( V_80 , L_50 ) ,
} ,
. V_81 = F_51 ( 0x0a , 0x00 , 0 ) ,
} ,
{
. V_67 = L_52 ,
. V_68 = {
F_40 ( V_79 ,
L_51 ) ,
F_40 ( V_80 , L_52 ) ,
} ,
. V_81 = F_51 ( 0x03 , 0x00 , 0 ) ,
} ,
{ }
} ;
#undef F_51
const struct V_65 * V_90 = F_44 ( V_66 ) ;
unsigned int V_92 ;
if ( ! V_90 )
return false ;
V_92 = ( unsigned long ) V_90 -> V_81 ;
return V_2 -> V_71 -> V_72 == ( V_92 >> 8 ) && V_2 -> V_73 == ( V_92 & 0xff ) ;
}
static void F_52 ( struct V_13 * V_14 )
{
static const struct V_65 V_66 [] = {
{
. V_67 = L_53 ,
. V_68 = {
F_40 ( V_69 , L_54 ) ,
F_40 ( V_70 , L_53 ) ,
} ,
. V_81 = ( void * ) V_93 ,
} ,
{ }
} ;
const struct V_65 * V_90 = F_44 ( V_66 ) ;
unsigned int V_94 ;
int V_95 ;
if ( ! V_90 )
return;
V_94 = ( unsigned long ) V_90 -> V_81 ;
F_2 ( V_14 -> V_10 , L_55 ,
V_94 , V_90 -> V_67 ) ;
for ( V_95 = 0 ; V_95 < V_14 -> V_96 ; V_95 ++ ) {
struct V_28 * V_29 = V_14 -> V_74 [ V_95 ] ;
struct V_24 * V_25 ;
struct V_97 * V_10 ;
F_53 (link, ap, EDGE)
F_54 (dev, link, ALL)
V_10 -> V_98 |= V_94 ;
}
}
static inline void F_52 ( struct V_13 * V_14 )
{}
int F_55 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_31 ;
unsigned int V_99 ;
if ( ! ( V_4 -> V_11 & V_100 ) ) {
V_31 = F_56 ( V_2 , & V_99 ) ;
if ( V_31 > 0 ) {
if ( ( V_31 == V_99 ) || ( V_31 == 1 ) )
return V_31 ;
F_57 ( V_2 ) ;
if ( ! F_58 ( V_2 ) )
return 1 ;
}
}
F_59 ( V_2 , 1 ) ;
return 0 ;
}
int F_60 ( struct V_13 * V_14 , int V_101 , unsigned int V_102 )
{
int V_95 , V_31 ;
if ( V_102 < V_14 -> V_96 )
return - V_103 ;
V_31 = F_61 ( V_14 ) ;
if ( V_31 )
return V_31 ;
for ( V_95 = 0 ; V_95 < V_14 -> V_96 ; V_95 ++ ) {
const char * V_104 ;
struct V_34 * V_35 = V_14 -> V_74 [ V_95 ] -> V_16 ;
if ( V_35 )
V_104 = V_35 -> V_105 ;
else
V_104 = F_62 ( V_14 -> V_10 ) ;
V_31 = F_63 ( V_14 -> V_10 ,
V_101 + V_95 , V_106 , V_107 , V_108 ,
V_104 , V_14 -> V_74 [ V_95 ] ) ;
if ( V_31 )
goto V_109;
}
for ( V_95 = 0 ; V_95 < V_14 -> V_96 ; V_95 ++ )
F_64 ( V_14 -> V_74 [ V_95 ] , L_56 , V_101 + V_95 ) ;
V_31 = F_65 ( V_14 , & V_110 ) ;
if ( V_31 )
goto V_111;
return 0 ;
V_111:
V_95 = V_14 -> V_96 ;
V_109:
for ( V_95 -- ; V_95 >= 0 ; V_95 -- )
F_66 ( V_14 -> V_10 , V_101 + V_95 , V_14 -> V_74 [ V_95 ] ) ;
return V_31 ;
}
static int F_67 ( struct V_1 * V_2 , const struct V_112 * V_113 )
{
unsigned int V_114 = V_113 -> V_81 ;
struct V_115 V_116 = V_117 [ V_114 ] ;
const struct V_115 * V_118 [] = { & V_116 , NULL } ;
struct V_9 * V_10 = & V_2 -> V_10 ;
struct V_3 * V_4 ;
struct V_13 * V_14 ;
int V_96 , V_102 , V_95 , V_31 ;
int V_119 = V_120 ;
F_13 ( L_4 ) ;
F_68 ( ( int ) V_121 > V_122 ) ;
F_69 ( & V_2 -> V_10 , V_123 ) ;
if ( V_2 -> V_7 == V_124 && ! V_125 )
return - V_126 ;
if ( V_2 -> V_7 == V_127 &&
V_2 -> V_9 == V_128 &&
V_2 -> V_129 == V_130 &&
V_2 -> V_131 == 0xcb89 )
return - V_126 ;
if ( V_2 -> V_7 == V_132 )
F_2 ( & V_2 -> V_10 ,
L_57 ) ;
if ( V_2 -> V_7 == V_133 && V_2 -> V_9 == 0xCC06 )
V_119 = V_134 ;
else if ( V_2 -> V_7 == 0x1c44 && V_2 -> V_9 == 0x8000 )
V_119 = V_135 ;
V_31 = F_70 ( V_2 ) ;
if ( V_31 )
return V_31 ;
if ( V_2 -> V_7 == V_15 &&
( V_2 -> V_9 == 0x2652 || V_2 -> V_9 == 0x2653 ) ) {
T_4 V_136 ;
F_71 ( V_2 , V_137 , & V_136 ) ;
if ( V_136 & 0x3 ) {
F_2 ( & V_2 -> V_10 ,
L_58 ) ;
return - V_126 ;
}
}
V_31 = F_72 ( V_2 , 1 << V_119 , V_138 ) ;
if ( V_31 == - V_139 )
F_73 ( V_2 ) ;
if ( V_31 )
return V_31 ;
V_4 = F_74 ( V_10 , sizeof( * V_4 ) , V_140 ) ;
if ( ! V_4 )
return - V_141 ;
V_4 -> V_11 |= ( unsigned long ) V_116 . V_16 ;
if ( V_114 == V_142 &&
( V_2 -> V_143 == 0xa1 || V_2 -> V_143 == 0xa2 ) )
V_4 -> V_11 |= V_100 ;
if ( V_114 == V_144 && V_2 -> V_143 >= 0x40 )
V_4 -> V_11 &= ~ V_145 ;
if ( F_43 ( V_2 ) )
V_4 -> V_11 &= ~ V_146 ;
V_4 -> V_47 = F_75 ( V_2 ) [ V_119 ] ;
V_102 = F_55 ( V_2 , V_4 ) ;
if ( V_102 > 1 )
V_4 -> V_11 |= V_147 ;
F_1 ( V_2 , V_4 ) ;
if ( V_4 -> V_148 & V_149 ) {
V_116 . V_11 |= V_150 ;
if ( ! ( V_4 -> V_11 & V_151 ) )
V_116 . V_11 |= V_152 ;
V_116 . V_11 |= V_153 ;
}
if ( V_4 -> V_148 & V_154 )
V_116 . V_11 |= V_155 ;
F_76 ( V_4 , & V_116 ) ;
if ( F_47 ( V_2 ) ) {
V_116 . V_11 |= V_156 ;
F_2 ( & V_2 -> V_10 ,
L_59 ) ;
}
if ( F_49 ( V_2 ) ) {
V_4 -> V_11 |= V_51 ;
F_46 ( & V_2 -> V_10 ,
L_6 ) ;
}
if ( F_50 ( V_2 ) ) {
V_4 -> V_11 |= V_157 ;
F_2 ( & V_2 -> V_10 ,
L_60 ) ;
}
V_96 = F_77 ( F_78 ( V_4 -> V_148 ) , F_79 ( V_4 -> V_18 ) ) ;
V_14 = F_80 ( & V_2 -> V_10 , V_118 , V_96 ) ;
if ( ! V_14 )
return - V_141 ;
V_14 -> V_16 = V_4 ;
if ( ! ( V_4 -> V_148 & V_158 ) || V_159 )
V_14 -> V_11 |= V_160 ;
else
F_2 ( & V_2 -> V_10 , L_61 ) ;
if ( V_116 . V_11 & V_161 )
F_81 ( V_14 ) ;
for ( V_95 = 0 ; V_95 < V_14 -> V_96 ; V_95 ++ ) {
struct V_28 * V_29 = V_14 -> V_74 [ V_95 ] ;
F_82 ( V_29 , V_119 , - 1 , L_62 ) ;
F_82 ( V_29 , V_119 ,
0x100 + V_29 -> V_162 * 0x80 , L_63 ) ;
if ( V_29 -> V_11 & V_161 )
V_29 -> V_163 = V_4 -> V_164 ;
if ( ! ( V_4 -> V_18 & ( 1 << V_95 ) ) )
V_29 -> V_75 = & V_165 ;
}
F_39 ( V_14 ) ;
F_52 ( V_14 ) ;
V_31 = F_33 ( V_2 , V_4 -> V_148 & V_166 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_4 ( V_14 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_14 ) ;
F_37 ( V_14 ) ;
F_83 ( V_2 ) ;
if ( V_4 -> V_11 & V_147 )
return F_60 ( V_14 , V_2 -> V_101 , V_102 ) ;
return F_84 ( V_14 , V_2 -> V_101 , V_167 , V_108 ,
& V_110 ) ;
}
