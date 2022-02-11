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
V_40 . V_41 = 0x80 ;
F_23 ( & V_40 , 0 , 0 , V_36 ) ;
V_31 = F_18 ( V_25 , F_19 ( & V_25 -> V_32 ) ,
V_27 , & V_30 , NULL ) ;
F_20 ( V_29 ) ;
if ( V_30 ) {
V_31 = F_24 ( V_25 , V_42 + 2 * V_43 ,
V_44 ) ;
if ( V_31 )
F_25 ( V_29 ) ;
}
return V_31 ;
}
static int F_26 ( struct V_1 * V_2 , T_5 V_45 )
{
struct V_13 * V_14 = F_27 ( & V_2 -> V_10 ) ;
struct V_3 * V_4 = V_14 -> V_16 ;
void T_2 * V_46 = V_4 -> V_46 ;
T_3 V_47 ;
if ( V_45 . V_48 & V_49 &&
V_4 -> V_11 & V_50 ) {
F_28 ( & V_2 -> V_10 ,
L_6 ) ;
return - V_51 ;
}
if ( V_45 . V_48 & V_52 ) {
V_47 = F_12 ( V_46 + V_53 ) ;
V_47 &= ~ V_54 ;
F_11 ( V_47 , V_46 + V_53 ) ;
F_12 ( V_46 + V_53 ) ;
}
return F_29 ( V_2 , V_45 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_27 ( & V_2 -> V_10 ) ;
int V_31 ;
V_31 = F_31 ( V_2 ) ;
if ( V_31 )
return V_31 ;
if ( V_2 -> V_10 . V_55 . V_56 . V_48 == V_49 ) {
V_31 = F_4 ( V_14 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_14 ) ;
}
F_32 ( V_14 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , int V_57 )
{
int V_31 ;
if ( V_2 -> V_58 && V_2 -> V_58 < F_34 ( 32 ) )
return 0 ;
if ( V_57 &&
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
T_1 V_59 ;
const char * V_60 ;
F_7 ( V_2 , 0x0a , & V_59 ) ;
if ( V_59 == V_61 )
V_60 = L_10 ;
else if ( V_59 == V_62 )
V_60 = L_11 ;
else if ( V_59 == V_63 )
V_60 = L_12 ;
else
V_60 = L_13 ;
F_38 ( V_14 , V_60 ) ;
}
static void F_39 ( struct V_13 * V_14 )
{
static struct V_64 V_65 [] = {
{
. V_66 = L_14 ,
. V_67 = {
F_40 ( V_68 ,
L_15 ) ,
F_40 ( V_69 , L_14 ) ,
} ,
} ,
{ }
} ;
struct V_1 * V_2 = F_5 ( V_14 -> V_10 ) ;
if ( V_2 -> V_70 -> V_71 == 0 && V_2 -> V_72 == F_41 ( 0x1f , 2 ) &&
F_42 ( V_65 ) ) {
struct V_28 * V_29 = V_14 -> V_73 [ 1 ] ;
F_2 ( & V_2 -> V_10 ,
L_16 ) ;
V_29 -> V_74 = & V_75 ;
V_29 -> V_25 . V_11 |= V_76 | V_77 ;
}
}
static bool F_43 ( struct V_1 * V_2 )
{
static const struct V_64 V_65 [] = {
{
. V_66 = L_17 ,
. V_67 = {
F_40 ( V_78 ,
L_18 ) ,
F_40 ( V_79 , L_19 ) ,
} ,
. V_80 = L_20 ,
} ,
{
. V_66 = L_21 ,
. V_67 = {
F_40 ( V_78 ,
L_22 ) ,
F_40 ( V_79 , L_23 ) ,
} ,
} ,
{
. V_66 = L_24 ,
. V_67 = {
F_40 ( V_78 ,
L_22 ) ,
F_40 ( V_79 , L_25 ) ,
} ,
} ,
{
. V_66 = L_26 ,
. V_67 = {
F_40 ( V_78 ,
L_18 ) ,
F_40 ( V_79 , L_27 ) ,
} ,
} ,
{ }
} ;
const struct V_64 * V_81 ;
int V_82 , V_83 , V_84 ;
char V_85 [ 9 ] ;
V_81 = F_44 ( V_65 ) ;
if ( V_2 -> V_70 -> V_71 != 0 || V_2 -> V_72 != F_41 ( 0x12 , 0 ) ||
! V_81 )
return false ;
if ( ! V_81 -> V_80 )
goto V_86;
F_45 ( V_87 , & V_82 , & V_83 , & V_84 ) ;
snprintf ( V_85 , sizeof( V_85 ) , L_28 , V_82 , V_83 , V_84 ) ;
if ( strcmp ( V_85 , V_81 -> V_80 ) >= 0 )
goto V_86;
else {
F_46 ( & V_2 -> V_10 ,
L_29 ,
V_81 -> V_66 ) ;
return false ;
}
V_86:
F_46 ( & V_2 -> V_10 , L_30 , V_81 -> V_66 ) ;
return true ;
}
static bool F_47 ( struct V_1 * V_2 )
{
static const struct V_64 V_88 [] = {
{
. V_66 = L_31 ,
. V_67 = {
F_40 ( V_68 , L_32 ) ,
F_40 ( V_69 , L_31 ) ,
} ,
. V_80 = ( void * ) 0x1FUL ,
} ,
{
. V_66 = L_33 ,
. V_67 = {
F_40 ( V_68 , L_32 ) ,
F_40 ( V_69 , L_33 ) ,
} ,
. V_80 = ( void * ) 0x1FUL ,
} ,
{ }
} ;
const struct V_64 * V_89 = F_44 ( V_88 ) ;
if ( V_89 ) {
unsigned long V_90 = ( unsigned long ) V_89 -> V_80 ;
return V_90 == F_48 ( V_2 -> V_72 ) ;
}
return false ;
}
static bool F_49 ( struct V_1 * V_2 )
{
static const struct V_64 V_65 [] = {
{
. V_66 = L_34 ,
. V_67 = {
F_40 ( V_68 , L_32 ) ,
F_40 ( V_69 ,
L_35 ) ,
} ,
. V_80 = L_36 ,
} ,
{
. V_66 = L_37 ,
. V_67 = {
F_40 ( V_68 , L_32 ) ,
F_40 ( V_69 ,
L_38 ) ,
} ,
. V_80 = L_39 ,
} ,
{
. V_66 = L_40 ,
. V_67 = {
F_40 ( V_68 , L_32 ) ,
F_40 ( V_69 ,
L_41 ) ,
} ,
. V_80 = L_42 ,
} ,
{
. V_66 = L_43 ,
. V_67 = {
F_40 ( V_68 , L_32 ) ,
F_40 ( V_69 ,
L_44 ) ,
} ,
. V_80 = L_45 ,
} ,
{
. V_66 = L_46 ,
. V_67 = {
F_40 ( V_68 , L_47 ) ,
F_40 ( V_69 , L_48 ) ,
} ,
. V_80 = L_49 ,
} ,
{ }
} ;
const struct V_64 * V_89 = F_44 ( V_65 ) ;
int V_82 , V_83 , V_84 ;
char V_85 [ 9 ] ;
if ( ! V_89 || V_2 -> V_70 -> V_71 || V_2 -> V_72 != F_41 ( 0x1f , 2 ) )
return false ;
F_45 ( V_87 , & V_82 , & V_83 , & V_84 ) ;
snprintf ( V_85 , sizeof( V_85 ) , L_28 , V_82 , V_83 , V_84 ) ;
return strcmp ( V_85 , V_89 -> V_80 ) < 0 ;
}
static bool F_50 ( struct V_1 * V_2 )
{
#define F_51 ( V_70 , V_90 , T_6 ) \
(void *)(unsigned long)(((bus) << 8) | PCI_DEVFN((slot), (func)))
static const struct V_64 V_65 [] = {
{
. V_66 = L_50 ,
. V_67 = {
F_40 ( V_78 ,
L_51 ) ,
F_40 ( V_79 , L_50 ) ,
} ,
. V_80 = F_51 ( 0x0a , 0x00 , 0 ) ,
} ,
{
. V_66 = L_52 ,
. V_67 = {
F_40 ( V_78 ,
L_51 ) ,
F_40 ( V_79 , L_52 ) ,
} ,
. V_80 = F_51 ( 0x03 , 0x00 , 0 ) ,
} ,
{ }
} ;
#undef F_51
const struct V_64 * V_89 = F_44 ( V_65 ) ;
unsigned int V_91 ;
if ( ! V_89 )
return false ;
V_91 = ( unsigned long ) V_89 -> V_80 ;
return V_2 -> V_70 -> V_71 == ( V_91 >> 8 ) && V_2 -> V_72 == ( V_91 & 0xff ) ;
}
static void F_52 ( struct V_13 * V_14 )
{
static const struct V_64 V_65 [] = {
{
. V_66 = L_53 ,
. V_67 = {
F_40 ( V_68 , L_54 ) ,
F_40 ( V_69 , L_53 ) ,
} ,
. V_80 = ( void * ) V_92 ,
} ,
{ }
} ;
const struct V_64 * V_89 = F_44 ( V_65 ) ;
unsigned int V_93 ;
int V_94 ;
if ( ! V_89 )
return;
V_93 = ( unsigned long ) V_89 -> V_80 ;
F_2 ( V_14 -> V_10 , L_55 ,
V_93 , V_89 -> V_66 ) ;
for ( V_94 = 0 ; V_94 < V_14 -> V_95 ; V_94 ++ ) {
struct V_28 * V_29 = V_14 -> V_73 [ V_94 ] ;
struct V_24 * V_25 ;
struct V_96 * V_10 ;
F_53 (link, ap, EDGE)
F_54 (dev, link, ALL)
V_10 -> V_97 |= V_93 ;
}
}
static inline void F_52 ( struct V_13 * V_14 )
{}
static int F_55 ( struct V_1 * V_2 , const struct V_98 * V_99 )
{
unsigned int V_100 = V_99 -> V_80 ;
struct V_101 V_102 = V_103 [ V_100 ] ;
const struct V_101 * V_104 [] = { & V_102 , NULL } ;
struct V_9 * V_10 = & V_2 -> V_10 ;
struct V_3 * V_4 ;
struct V_13 * V_14 ;
int V_95 , V_94 , V_31 ;
int V_105 = V_106 ;
F_13 ( L_4 ) ;
F_56 ( ( int ) V_107 > V_108 ) ;
F_57 ( & V_2 -> V_10 , V_109 ) ;
if ( V_2 -> V_7 == V_110 && ! V_111 )
return - V_112 ;
if ( V_2 -> V_7 == V_113 &&
V_2 -> V_9 == V_114 &&
V_2 -> V_115 == V_116 &&
V_2 -> V_117 == 0xcb89 )
return - V_112 ;
if ( V_2 -> V_7 == V_118 )
F_2 ( & V_2 -> V_10 ,
L_56 ) ;
if ( V_2 -> V_7 == V_119 && V_2 -> V_9 == 0xCC06 )
V_105 = V_120 ;
V_31 = F_58 ( V_2 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_59 ( V_2 , 1 << V_105 , V_121 ) ;
if ( V_31 == - V_122 )
F_60 ( V_2 ) ;
if ( V_31 )
return V_31 ;
if ( V_2 -> V_7 == V_15 &&
( V_2 -> V_9 == 0x2652 || V_2 -> V_9 == 0x2653 ) ) {
T_4 V_123 ;
F_61 ( V_2 , V_124 , & V_123 ) ;
if ( V_123 & 0x3 ) {
F_2 ( & V_2 -> V_10 ,
L_57 ) ;
return - V_112 ;
}
}
V_4 = F_62 ( V_10 , sizeof( * V_4 ) , V_125 ) ;
if ( ! V_4 )
return - V_126 ;
V_4 -> V_11 |= ( unsigned long ) V_102 . V_16 ;
if ( V_100 == V_127 &&
( V_2 -> V_128 == 0xa1 || V_2 -> V_128 == 0xa2 ) )
V_4 -> V_11 |= V_129 ;
if ( V_100 == V_130 && V_2 -> V_128 >= 0x40 )
V_4 -> V_11 &= ~ V_131 ;
if ( F_43 ( V_2 ) )
V_4 -> V_11 &= ~ V_132 ;
if ( ( V_4 -> V_11 & V_129 ) || F_63 ( V_2 ) )
F_64 ( V_2 , 1 ) ;
V_4 -> V_46 = F_65 ( V_2 ) [ V_105 ] ;
F_1 ( V_2 , V_4 ) ;
if ( V_4 -> V_133 & V_134 ) {
V_102 . V_11 |= V_135 ;
if ( ! ( V_4 -> V_11 & V_136 ) )
V_102 . V_11 |= V_137 ;
}
if ( V_4 -> V_133 & V_138 )
V_102 . V_11 |= V_139 ;
F_66 ( V_4 , & V_102 ) ;
if ( F_47 ( V_2 ) ) {
V_102 . V_11 |= V_140 ;
F_2 ( & V_2 -> V_10 ,
L_58 ) ;
}
if ( F_49 ( V_2 ) ) {
V_4 -> V_11 |= V_50 ;
F_46 ( & V_2 -> V_10 ,
L_6 ) ;
}
if ( F_50 ( V_2 ) ) {
V_4 -> V_11 |= V_141 ;
F_2 ( & V_2 -> V_10 ,
L_59 ) ;
}
V_95 = F_67 ( F_68 ( V_4 -> V_133 ) , F_69 ( V_4 -> V_18 ) ) ;
V_14 = F_70 ( & V_2 -> V_10 , V_104 , V_95 ) ;
if ( ! V_14 )
return - V_126 ;
V_14 -> V_16 = V_4 ;
if ( ! ( V_4 -> V_133 & V_142 ) || V_143 )
V_14 -> V_11 |= V_144 ;
else
F_71 ( V_145 L_60 ) ;
if ( V_102 . V_11 & V_146 )
F_72 ( V_14 ) ;
for ( V_94 = 0 ; V_94 < V_14 -> V_95 ; V_94 ++ ) {
struct V_28 * V_29 = V_14 -> V_73 [ V_94 ] ;
F_73 ( V_29 , V_105 , - 1 , L_61 ) ;
F_73 ( V_29 , V_105 ,
0x100 + V_29 -> V_147 * 0x80 , L_62 ) ;
if ( V_29 -> V_11 & V_146 )
V_29 -> V_148 = V_4 -> V_149 ;
if ( ! ( V_4 -> V_18 & ( 1 << V_94 ) ) )
V_29 -> V_74 = & V_150 ;
}
F_39 ( V_14 ) ;
F_52 ( V_14 ) ;
V_31 = F_33 ( V_2 , V_4 -> V_133 & V_151 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_4 ( V_14 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_14 ) ;
F_37 ( V_14 ) ;
F_74 ( V_2 ) ;
return F_75 ( V_14 , V_2 -> V_152 , V_153 , V_154 ,
& V_155 ) ;
}
