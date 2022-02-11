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
if ( V_57 &&
! F_34 ( V_2 , F_35 ( 64 ) ) ) {
V_31 = F_36 ( V_2 , F_35 ( 64 ) ) ;
if ( V_31 ) {
V_31 = F_36 ( V_2 , F_35 ( 32 ) ) ;
if ( V_31 ) {
F_28 ( & V_2 -> V_10 ,
L_7 ) ;
return V_31 ;
}
}
} else {
V_31 = F_34 ( V_2 , F_35 ( 32 ) ) ;
if ( V_31 ) {
F_28 ( & V_2 -> V_10 , L_8 ) ;
return V_31 ;
}
V_31 = F_36 ( V_2 , F_35 ( 32 ) ) ;
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
T_1 V_58 ;
const char * V_59 ;
F_7 ( V_2 , 0x0a , & V_58 ) ;
if ( V_58 == V_60 )
V_59 = L_10 ;
else if ( V_58 == V_61 )
V_59 = L_11 ;
else if ( V_58 == V_62 )
V_59 = L_12 ;
else
V_59 = L_13 ;
F_38 ( V_14 , V_59 ) ;
}
static void F_39 ( struct V_13 * V_14 )
{
static struct V_63 V_64 [] = {
{
. V_65 = L_14 ,
. V_66 = {
F_40 ( V_67 ,
L_15 ) ,
F_40 ( V_68 , L_14 ) ,
} ,
} ,
{ }
} ;
struct V_1 * V_2 = F_5 ( V_14 -> V_10 ) ;
if ( V_2 -> V_69 -> V_70 == 0 && V_2 -> V_71 == F_41 ( 0x1f , 2 ) &&
F_42 ( V_64 ) ) {
struct V_28 * V_29 = V_14 -> V_72 [ 1 ] ;
F_2 ( & V_2 -> V_10 ,
L_16 ) ;
V_29 -> V_73 = & V_74 ;
V_29 -> V_25 . V_11 |= V_75 | V_76 ;
}
}
static bool F_43 ( struct V_1 * V_2 )
{
static const struct V_63 V_64 [] = {
{
. V_65 = L_17 ,
. V_66 = {
F_40 ( V_77 ,
L_18 ) ,
F_40 ( V_78 , L_19 ) ,
} ,
. V_79 = L_20 ,
} ,
{
. V_65 = L_21 ,
. V_66 = {
F_40 ( V_77 ,
L_22 ) ,
F_40 ( V_78 , L_23 ) ,
} ,
} ,
{
. V_65 = L_24 ,
. V_66 = {
F_40 ( V_77 ,
L_18 ) ,
F_40 ( V_78 , L_25 ) ,
} ,
} ,
{ }
} ;
const struct V_63 * V_80 ;
int V_81 , V_82 , V_83 ;
char V_84 [ 9 ] ;
V_80 = F_44 ( V_64 ) ;
if ( V_2 -> V_69 -> V_70 != 0 || V_2 -> V_71 != F_41 ( 0x12 , 0 ) ||
! V_80 )
return false ;
if ( ! V_80 -> V_79 )
goto V_85;
F_45 ( V_86 , & V_81 , & V_82 , & V_83 ) ;
snprintf ( V_84 , sizeof( V_84 ) , L_26 , V_81 , V_82 , V_83 ) ;
if ( strcmp ( V_84 , V_80 -> V_79 ) >= 0 )
goto V_85;
else {
F_46 ( & V_2 -> V_10 ,
L_27 ,
V_80 -> V_65 ) ;
return false ;
}
V_85:
F_46 ( & V_2 -> V_10 , L_28 , V_80 -> V_65 ) ;
return true ;
}
static bool F_47 ( struct V_1 * V_2 )
{
static const struct V_63 V_87 [] = {
{
. V_65 = L_29 ,
. V_66 = {
F_40 ( V_67 , L_30 ) ,
F_40 ( V_68 , L_29 ) ,
} ,
. V_79 = ( void * ) 0x1FUL ,
} ,
{
. V_65 = L_31 ,
. V_66 = {
F_40 ( V_67 , L_30 ) ,
F_40 ( V_68 , L_31 ) ,
} ,
. V_79 = ( void * ) 0x1FUL ,
} ,
{ }
} ;
const struct V_63 * V_88 = F_44 ( V_87 ) ;
if ( V_88 ) {
unsigned long V_89 = ( unsigned long ) V_88 -> V_79 ;
return V_89 == F_48 ( V_2 -> V_71 ) ;
}
return false ;
}
static bool F_49 ( struct V_1 * V_2 )
{
static const struct V_63 V_64 [] = {
{
. V_65 = L_32 ,
. V_66 = {
F_40 ( V_67 , L_30 ) ,
F_40 ( V_68 ,
L_33 ) ,
} ,
. V_79 = L_34 ,
} ,
{
. V_65 = L_35 ,
. V_66 = {
F_40 ( V_67 , L_30 ) ,
F_40 ( V_68 ,
L_36 ) ,
} ,
. V_79 = L_37 ,
} ,
{
. V_65 = L_38 ,
. V_66 = {
F_40 ( V_67 , L_30 ) ,
F_40 ( V_68 ,
L_39 ) ,
} ,
. V_79 = L_40 ,
} ,
{
. V_65 = L_41 ,
. V_66 = {
F_40 ( V_67 , L_30 ) ,
F_40 ( V_68 ,
L_42 ) ,
} ,
. V_79 = L_43 ,
} ,
{
. V_65 = L_44 ,
. V_66 = {
F_40 ( V_67 , L_45 ) ,
F_40 ( V_68 , L_46 ) ,
} ,
. V_79 = L_47 ,
} ,
{ }
} ;
const struct V_63 * V_88 = F_44 ( V_64 ) ;
int V_81 , V_82 , V_83 ;
char V_84 [ 9 ] ;
if ( ! V_88 || V_2 -> V_69 -> V_70 || V_2 -> V_71 != F_41 ( 0x1f , 2 ) )
return false ;
F_45 ( V_86 , & V_81 , & V_82 , & V_83 ) ;
snprintf ( V_84 , sizeof( V_84 ) , L_26 , V_81 , V_82 , V_83 ) ;
return strcmp ( V_84 , V_88 -> V_79 ) < 0 ;
}
static bool F_50 ( struct V_1 * V_2 )
{
#define F_51 ( V_69 , V_89 , T_6 ) \
(void *)(unsigned long)(((bus) << 8) | PCI_DEVFN((slot), (func)))
static const struct V_63 V_64 [] = {
{
. V_65 = L_48 ,
. V_66 = {
F_40 ( V_77 ,
L_49 ) ,
F_40 ( V_78 , L_48 ) ,
} ,
. V_79 = F_51 ( 0x0a , 0x00 , 0 ) ,
} ,
{
. V_65 = L_50 ,
. V_66 = {
F_40 ( V_77 ,
L_49 ) ,
F_40 ( V_78 , L_50 ) ,
} ,
. V_79 = F_51 ( 0x03 , 0x00 , 0 ) ,
} ,
{ }
} ;
#undef F_51
const struct V_63 * V_88 = F_44 ( V_64 ) ;
unsigned int V_90 ;
if ( ! V_88 )
return false ;
V_90 = ( unsigned long ) V_88 -> V_79 ;
return V_2 -> V_69 -> V_70 == ( V_90 >> 8 ) && V_2 -> V_71 == ( V_90 & 0xff ) ;
}
static void F_52 ( struct V_13 * V_14 )
{
static const struct V_63 V_64 [] = {
{
. V_65 = L_51 ,
. V_66 = {
F_40 ( V_67 , L_52 ) ,
F_40 ( V_68 , L_51 ) ,
} ,
. V_79 = ( void * ) V_91 ,
} ,
{ }
} ;
const struct V_63 * V_88 = F_44 ( V_64 ) ;
unsigned int V_92 ;
int V_93 ;
if ( ! V_88 )
return;
V_92 = ( unsigned long ) V_88 -> V_79 ;
F_2 ( V_14 -> V_10 , L_53 ,
V_92 , V_88 -> V_65 ) ;
for ( V_93 = 0 ; V_93 < V_14 -> V_94 ; V_93 ++ ) {
struct V_28 * V_29 = V_14 -> V_72 [ V_93 ] ;
struct V_24 * V_25 ;
struct V_95 * V_10 ;
F_53 (link, ap, EDGE)
F_54 (dev, link, ALL)
V_10 -> V_96 |= V_92 ;
}
}
static inline void F_52 ( struct V_13 * V_14 )
{}
static int F_55 ( struct V_1 * V_2 , const struct V_97 * V_98 )
{
unsigned int V_99 = V_98 -> V_79 ;
struct V_100 V_101 = V_102 [ V_99 ] ;
const struct V_100 * V_103 [] = { & V_101 , NULL } ;
struct V_9 * V_10 = & V_2 -> V_10 ;
struct V_3 * V_4 ;
struct V_13 * V_14 ;
int V_94 , V_93 , V_31 ;
F_13 ( L_4 ) ;
F_56 ( ( int ) V_104 > V_105 ) ;
F_57 ( & V_2 -> V_10 , V_106 ) ;
if ( V_2 -> V_7 == V_107 && ! V_108 )
return - V_109 ;
if ( V_2 -> V_7 == V_110 &&
V_2 -> V_9 == V_111 &&
V_2 -> V_112 == V_113 &&
V_2 -> V_114 == 0xcb89 )
return - V_109 ;
if ( V_2 -> V_7 == V_115 )
F_2 ( & V_2 -> V_10 ,
L_54 ) ;
V_31 = F_58 ( V_2 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_59 ( V_2 , 1 << V_116 , V_117 ) ;
if ( V_31 == - V_118 )
F_60 ( V_2 ) ;
if ( V_31 )
return V_31 ;
if ( V_2 -> V_7 == V_15 &&
( V_2 -> V_9 == 0x2652 || V_2 -> V_9 == 0x2653 ) ) {
T_4 V_119 ;
F_61 ( V_2 , V_120 , & V_119 ) ;
if ( V_119 & 0x3 ) {
F_2 ( & V_2 -> V_10 ,
L_55 ) ;
return - V_109 ;
}
}
V_4 = F_62 ( V_10 , sizeof( * V_4 ) , V_121 ) ;
if ( ! V_4 )
return - V_122 ;
V_4 -> V_11 |= ( unsigned long ) V_101 . V_16 ;
if ( V_99 == V_123 &&
( V_2 -> V_124 == 0xa1 || V_2 -> V_124 == 0xa2 ) )
V_4 -> V_11 |= V_125 ;
if ( V_99 == V_126 && V_2 -> V_124 >= 0x40 )
V_4 -> V_11 &= ~ V_127 ;
if ( F_43 ( V_2 ) )
V_4 -> V_11 &= ~ V_128 ;
if ( ( V_4 -> V_11 & V_125 ) || F_63 ( V_2 ) )
F_64 ( V_2 , 1 ) ;
V_4 -> V_46 = F_65 ( V_2 ) [ V_116 ] ;
F_1 ( V_2 , V_4 ) ;
if ( V_4 -> V_129 & V_130 ) {
V_101 . V_11 |= V_131 ;
if ( ! ( V_4 -> V_11 & V_132 ) )
V_101 . V_11 |= V_133 ;
}
if ( V_4 -> V_129 & V_134 )
V_101 . V_11 |= V_135 ;
F_66 ( V_4 , & V_101 ) ;
if ( F_47 ( V_2 ) ) {
V_101 . V_11 |= V_136 ;
F_2 ( & V_2 -> V_10 ,
L_56 ) ;
}
if ( F_49 ( V_2 ) ) {
V_4 -> V_11 |= V_50 ;
F_46 ( & V_2 -> V_10 ,
L_6 ) ;
}
if ( F_50 ( V_2 ) ) {
V_4 -> V_11 |= V_137 ;
F_2 ( & V_2 -> V_10 ,
L_57 ) ;
}
V_94 = F_67 ( F_68 ( V_4 -> V_129 ) , F_69 ( V_4 -> V_18 ) ) ;
V_14 = F_70 ( & V_2 -> V_10 , V_103 , V_94 ) ;
if ( ! V_14 )
return - V_122 ;
V_14 -> V_16 = V_4 ;
if ( ! ( V_4 -> V_129 & V_138 ) || V_139 )
V_14 -> V_11 |= V_140 ;
else
F_71 ( V_141 L_58 ) ;
if ( V_101 . V_11 & V_142 )
F_72 ( V_14 ) ;
for ( V_93 = 0 ; V_93 < V_14 -> V_94 ; V_93 ++ ) {
struct V_28 * V_29 = V_14 -> V_72 [ V_93 ] ;
F_73 ( V_29 , V_116 , - 1 , L_59 ) ;
F_73 ( V_29 , V_116 ,
0x100 + V_29 -> V_143 * 0x80 , L_60 ) ;
if ( V_29 -> V_11 & V_142 )
V_29 -> V_144 = V_4 -> V_145 ;
if ( ! ( V_4 -> V_18 & ( 1 << V_93 ) ) )
V_29 -> V_73 = & V_146 ;
}
F_39 ( V_14 ) ;
F_52 ( V_14 ) ;
V_31 = F_33 ( V_2 , V_4 -> V_129 & V_147 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_4 ( V_14 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_14 ) ;
F_37 ( V_14 ) ;
F_74 ( V_2 ) ;
return F_75 ( V_14 , V_2 -> V_148 , V_149 , V_150 ,
& V_151 ) ;
}
static int T_7 F_76 ( void )
{
return F_77 ( & V_152 ) ;
}
static void T_8 F_78 ( void )
{
F_79 ( & V_152 ) ;
}
