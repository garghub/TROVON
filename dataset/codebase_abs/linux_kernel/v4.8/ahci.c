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
static void F_30 ( struct V_13 * V_14 )
{
struct V_3 * V_4 = V_14 -> V_16 ;
void T_2 * V_56 = V_4 -> V_56 ;
T_3 V_57 ;
V_57 = F_12 ( V_56 + V_58 ) ;
V_57 &= ~ V_59 ;
F_11 ( V_57 , V_56 + V_58 ) ;
F_12 ( V_56 + V_58 ) ;
}
static int F_31 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_5 ( V_8 ) ;
struct V_13 * V_14 = F_32 ( V_2 ) ;
F_30 ( V_14 ) ;
return 0 ;
}
static int F_33 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_5 ( V_8 ) ;
struct V_13 * V_14 = F_32 ( V_2 ) ;
int V_31 ;
V_31 = F_4 ( V_14 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_14 ) ;
return 0 ;
}
static int F_34 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_5 ( V_8 ) ;
struct V_13 * V_14 = F_32 ( V_2 ) ;
struct V_3 * V_4 = V_14 -> V_16 ;
if ( V_4 -> V_10 & V_60 ) {
F_35 ( & V_2 -> V_8 ,
L_7 ) ;
return - V_61 ;
}
F_30 ( V_14 ) ;
return F_36 ( V_14 , V_62 ) ;
}
static int F_37 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_5 ( V_8 ) ;
struct V_13 * V_14 = F_32 ( V_2 ) ;
int V_31 ;
if ( F_38 ( V_2 ) )
F_39 ( V_2 ) ;
if ( V_2 -> V_8 . V_63 . V_64 . V_65 == V_66 ) {
V_31 = F_4 ( V_14 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_14 ) ;
}
F_40 ( V_14 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , int V_67 )
{
int V_31 ;
if ( V_2 -> V_68 && V_2 -> V_68 < F_42 ( 32 ) )
return 0 ;
if ( V_67 &&
! F_43 ( & V_2 -> V_8 , F_42 ( 64 ) ) ) {
V_31 = F_44 ( & V_2 -> V_8 , F_42 ( 64 ) ) ;
if ( V_31 ) {
V_31 = F_44 ( & V_2 -> V_8 , F_42 ( 32 ) ) ;
if ( V_31 ) {
F_35 ( & V_2 -> V_8 ,
L_8 ) ;
return V_31 ;
}
}
} else {
V_31 = F_43 ( & V_2 -> V_8 , F_42 ( 32 ) ) ;
if ( V_31 ) {
F_35 ( & V_2 -> V_8 , L_9 ) ;
return V_31 ;
}
V_31 = F_44 ( & V_2 -> V_8 , F_42 ( 32 ) ) ;
if ( V_31 ) {
F_35 ( & V_2 -> V_8 ,
L_10 ) ;
return V_31 ;
}
}
return 0 ;
}
static void F_45 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_5 ( V_14 -> V_8 ) ;
T_1 V_69 ;
const char * V_70 ;
F_7 ( V_2 , 0x0a , & V_69 ) ;
if ( V_69 == V_71 )
V_70 = L_11 ;
else if ( V_69 == V_72 )
V_70 = L_12 ;
else if ( V_69 == V_73 )
V_70 = L_13 ;
else
V_70 = L_14 ;
F_46 ( V_14 , V_70 ) ;
}
static void F_47 ( struct V_13 * V_14 )
{
static const struct V_74 V_75 [] = {
{
. V_76 = L_15 ,
. V_77 = {
F_48 ( V_78 ,
L_16 ) ,
F_48 ( V_79 , L_15 ) ,
} ,
} ,
{ }
} ;
struct V_1 * V_2 = F_5 ( V_14 -> V_8 ) ;
if ( V_2 -> V_80 -> V_81 == 0 && V_2 -> V_82 == F_49 ( 0x1f , 2 ) &&
F_50 ( V_75 ) ) {
struct V_28 * V_29 = V_14 -> V_83 [ 1 ] ;
F_2 ( & V_2 -> V_8 ,
L_17 ) ;
V_29 -> V_84 = & V_85 ;
V_29 -> V_25 . V_10 |= V_86 | V_87 ;
}
}
static void F_39 ( struct V_1 * V_2 )
{
T_3 V_50 ;
F_51 ( V_55 L_18 ) ;
F_52 ( V_2 , 0xf8 , & V_50 ) ;
V_50 |= 1 << 0x1b ;
F_53 ( V_2 , 0xf8 , V_50 ) ;
F_52 ( V_2 , 0x54c , & V_50 ) ;
V_50 |= 1 << 0xc ;
F_53 ( V_2 , 0x54c , V_50 ) ;
F_52 ( V_2 , 0x4a4 , & V_50 ) ;
V_50 &= 0xff ;
V_50 |= 0x01060100 ;
F_53 ( V_2 , 0x4a4 , V_50 ) ;
F_52 ( V_2 , 0x54c , & V_50 ) ;
V_50 &= ~ ( 1 << 0xc ) ;
F_53 ( V_2 , 0x54c , V_50 ) ;
F_52 ( V_2 , 0xf8 , & V_50 ) ;
V_50 &= ~ ( 1 << 0x1b ) ;
F_53 ( V_2 , 0xf8 , V_50 ) ;
}
static bool F_38 ( struct V_1 * V_2 )
{
return V_2 -> V_5 == V_88 &&
V_2 -> V_7 == V_89 &&
V_2 -> V_90 == V_91 &&
V_2 -> V_92 == 0xcb89 ;
}
static bool F_54 ( struct V_1 * V_2 )
{
static const struct V_74 V_75 [] = {
{
. V_76 = L_19 ,
. V_77 = {
F_48 ( V_93 ,
L_20 ) ,
F_48 ( V_94 , L_21 ) ,
} ,
. V_95 = L_22 ,
} ,
{
. V_76 = L_23 ,
. V_77 = {
F_48 ( V_93 ,
L_24 ) ,
F_48 ( V_94 , L_25 ) ,
} ,
} ,
{
. V_76 = L_26 ,
. V_77 = {
F_48 ( V_93 ,
L_24 ) ,
F_48 ( V_94 , L_27 ) ,
} ,
} ,
{
. V_76 = L_28 ,
. V_77 = {
F_48 ( V_93 ,
L_20 ) ,
F_48 ( V_94 , L_29 ) ,
} ,
} ,
{ }
} ;
const struct V_74 * V_96 ;
int V_97 , V_98 , V_99 ;
char V_100 [ 9 ] ;
V_96 = F_55 ( V_75 ) ;
if ( V_2 -> V_80 -> V_81 != 0 || V_2 -> V_82 != F_49 ( 0x12 , 0 ) ||
! V_96 )
return false ;
if ( ! V_96 -> V_95 )
goto V_101;
F_56 ( V_102 , & V_97 , & V_98 , & V_99 ) ;
snprintf ( V_100 , sizeof( V_100 ) , L_30 , V_97 , V_98 , V_99 ) ;
if ( strcmp ( V_100 , V_96 -> V_95 ) >= 0 )
goto V_101;
else {
F_57 ( & V_2 -> V_8 ,
L_31 ,
V_96 -> V_76 ) ;
return false ;
}
V_101:
F_57 ( & V_2 -> V_8 , L_32 , V_96 -> V_76 ) ;
return true ;
}
static bool F_58 ( struct V_1 * V_2 )
{
static const struct V_74 V_103 [] = {
{
. V_76 = L_33 ,
. V_77 = {
F_48 ( V_78 , L_34 ) ,
F_48 ( V_79 , L_33 ) ,
} ,
. V_95 = ( void * ) 0x1FUL ,
} ,
{
. V_76 = L_35 ,
. V_77 = {
F_48 ( V_78 , L_34 ) ,
F_48 ( V_79 , L_35 ) ,
} ,
. V_95 = ( void * ) 0x1FUL ,
} ,
{ }
} ;
const struct V_74 * V_104 = F_55 ( V_103 ) ;
if ( V_104 ) {
unsigned long V_105 = ( unsigned long ) V_104 -> V_95 ;
return V_105 == F_59 ( V_2 -> V_82 ) ;
}
return false ;
}
static bool F_60 ( struct V_1 * V_2 )
{
static const struct V_74 V_75 [] = {
{
. V_76 = L_36 ,
. V_77 = {
F_48 ( V_78 , L_34 ) ,
F_48 ( V_79 ,
L_37 ) ,
} ,
. V_95 = L_38 ,
} ,
{
. V_76 = L_39 ,
. V_77 = {
F_48 ( V_78 , L_34 ) ,
F_48 ( V_79 ,
L_40 ) ,
} ,
. V_95 = L_41 ,
} ,
{
. V_76 = L_42 ,
. V_77 = {
F_48 ( V_78 , L_34 ) ,
F_48 ( V_79 ,
L_43 ) ,
} ,
. V_95 = L_44 ,
} ,
{
. V_76 = L_45 ,
. V_77 = {
F_48 ( V_78 , L_34 ) ,
F_48 ( V_79 ,
L_46 ) ,
} ,
. V_95 = L_47 ,
} ,
{
. V_76 = L_48 ,
. V_77 = {
F_48 ( V_78 , L_49 ) ,
F_48 ( V_79 , L_50 ) ,
} ,
. V_95 = L_51 ,
} ,
{ }
} ;
const struct V_74 * V_104 = F_55 ( V_75 ) ;
int V_97 , V_98 , V_99 ;
char V_100 [ 9 ] ;
if ( ! V_104 || V_2 -> V_80 -> V_81 || V_2 -> V_82 != F_49 ( 0x1f , 2 ) )
return false ;
F_56 ( V_102 , & V_97 , & V_98 , & V_99 ) ;
snprintf ( V_100 , sizeof( V_100 ) , L_30 , V_97 , V_98 , V_99 ) ;
return strcmp ( V_100 , V_104 -> V_95 ) < 0 ;
}
static bool F_61 ( struct V_1 * V_2 )
{
#define F_62 ( V_80 , V_105 , T_5 ) \
(void *)(unsigned long)(((bus) << 8) | PCI_DEVFN((slot), (func)))
static const struct V_74 V_75 [] = {
{
. V_76 = L_52 ,
. V_77 = {
F_48 ( V_93 ,
L_53 ) ,
F_48 ( V_94 , L_52 ) ,
} ,
. V_95 = F_62 ( 0x0a , 0x00 , 0 ) ,
} ,
{
. V_76 = L_54 ,
. V_77 = {
F_48 ( V_93 ,
L_53 ) ,
F_48 ( V_94 , L_54 ) ,
} ,
. V_95 = F_62 ( 0x03 , 0x00 , 0 ) ,
} ,
{ }
} ;
#undef F_62
const struct V_74 * V_104 = F_55 ( V_75 ) ;
unsigned int V_50 ;
if ( ! V_104 )
return false ;
V_50 = ( unsigned long ) V_104 -> V_95 ;
return V_2 -> V_80 -> V_81 == ( V_50 >> 8 ) && V_2 -> V_82 == ( V_50 & 0xff ) ;
}
static bool F_63 ( struct V_1 * V_2 )
{
static const struct V_106 V_107 [] = {
{ F_64 (INTEL, 0x0f23 ) } ,
{}
} ;
return F_65 ( V_107 , V_2 ) ;
}
static void F_66 ( struct V_13 * V_14 )
{
static const struct V_74 V_75 [] = {
{
. V_76 = L_55 ,
. V_77 = {
F_48 ( V_78 , L_56 ) ,
F_48 ( V_79 , L_55 ) ,
} ,
. V_95 = ( void * ) V_108 ,
} ,
{ }
} ;
const struct V_74 * V_104 = F_55 ( V_75 ) ;
unsigned int V_109 ;
int V_49 ;
if ( ! V_104 )
return;
V_109 = ( unsigned long ) V_104 -> V_95 ;
F_2 ( V_14 -> V_8 , L_57 ,
V_109 , V_104 -> V_76 ) ;
for ( V_49 = 0 ; V_49 < V_14 -> V_110 ; V_49 ++ ) {
struct V_28 * V_29 = V_14 -> V_83 [ V_49 ] ;
struct V_24 * V_25 ;
struct V_111 * V_8 ;
F_67 (link, ap, EDGE)
F_68 (dev, link, ALL)
V_8 -> V_112 |= V_109 ;
}
}
static inline void F_66 ( struct V_13 * V_14 )
{}
static T_6 F_69 ( int V_113 , void * V_114 )
{
struct V_13 * V_14 = V_114 ;
struct V_3 * V_4 ;
unsigned int V_31 = 0 ;
void T_2 * V_56 ;
T_3 V_115 , V_116 ;
unsigned int V_117 = 1 ;
F_13 ( L_4 ) ;
V_4 = V_14 -> V_16 ;
V_56 = V_4 -> V_56 ;
V_115 = F_12 ( V_56 + V_118 ) ;
if ( ! V_115 )
return V_119 ;
do {
V_116 = V_115 & V_4 -> V_18 ;
F_70 ( & V_14 -> V_120 ) ;
V_31 = F_71 ( V_14 , V_116 ) ;
if ( ! V_31 )
V_117 = 0 ;
F_11 ( V_115 , V_56 + V_118 ) ;
V_115 = F_12 ( V_56 + V_118 ) ;
F_72 ( & V_14 -> V_120 ) ;
} while ( V_115 );
F_13 ( L_58 ) ;
return F_73 ( V_117 ) ;
}
static int F_74 ( struct V_1 * V_2 , unsigned int V_110 ,
struct V_3 * V_4 , unsigned long V_10 )
{
int V_121 , V_49 , V_31 ;
if ( V_4 -> V_10 & V_122 )
return - V_123 ;
V_121 = F_75 ( V_2 ) ;
if ( V_121 < 0 )
return V_121 ;
if ( V_10 & V_124 ) {
if ( V_121 < V_110 )
return - V_123 ;
V_121 = V_110 ;
} else if ( V_121 ) {
V_121 = 1 ;
} else {
V_31 = - V_123 ;
goto V_125;
}
for ( V_49 = 0 ; V_49 < V_121 ; V_49 ++ )
V_4 -> V_126 [ V_49 ] . V_127 = V_49 ;
V_31 = F_76 ( V_2 , V_4 -> V_126 , V_121 ) ;
if ( V_31 < 0 )
goto V_125;
if ( V_121 > 1 )
V_4 -> V_10 |= V_124 ;
V_4 -> V_113 = V_4 -> V_126 [ 0 ] . V_128 ;
return V_121 ;
V_125:
F_35 ( & V_2 -> V_8 ,
L_59 ,
V_31 , V_121 ) ;
return V_31 ;
}
static int F_77 ( struct V_1 * V_2 , unsigned int V_110 ,
struct V_3 * V_4 )
{
int V_31 , V_121 ;
if ( V_4 -> V_10 & V_122 )
return - V_123 ;
V_121 = F_78 ( V_2 ) ;
if ( V_121 < 0 )
return V_121 ;
if ( V_121 < V_110 )
goto V_129;
V_31 = F_79 ( V_2 , V_121 ) ;
if ( V_31 == - V_130 )
goto V_129;
if ( V_31 < 0 )
return V_31 ;
if ( F_12 ( V_4 -> V_56 + V_58 ) & V_131 ) {
F_80 ( V_2 ) ;
F_51 ( V_55 L_60 ) ;
goto V_129;
}
if ( V_121 > 1 )
V_4 -> V_10 |= V_132 ;
goto V_133;
V_129:
V_121 = 1 ;
V_31 = F_81 ( V_2 ) ;
if ( V_31 < 0 )
return V_31 ;
V_133:
V_4 -> V_113 = V_2 -> V_113 ;
return V_121 ;
}
static int F_82 ( struct V_1 * V_2 , unsigned int V_110 ,
struct V_3 * V_4 )
{
int V_121 ;
V_121 = F_74 ( V_2 , V_110 , V_4 , V_124 ) ;
if ( V_121 >= 0 )
return V_121 ;
V_121 = F_77 ( V_2 , V_110 , V_4 ) ;
if ( V_121 >= 0 )
return V_121 ;
V_121 = F_74 ( V_2 , V_110 , V_4 , 0 ) ;
if ( V_121 >= 0 )
return V_121 ;
F_83 ( V_2 , 1 ) ;
V_4 -> V_113 = V_2 -> V_113 ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 , const struct V_106 * V_134 )
{
unsigned int V_135 = V_134 -> V_95 ;
struct V_136 V_137 = V_138 [ V_135 ] ;
const struct V_136 * V_139 [] = { & V_137 , NULL } ;
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_3 * V_4 ;
struct V_13 * V_14 ;
int V_110 , V_49 , V_31 ;
int V_140 = V_141 ;
F_13 ( L_4 ) ;
F_85 ( ( int ) V_142 > V_143 ) ;
F_86 ( & V_2 -> V_8 , V_144 ) ;
if ( V_2 -> V_5 == V_145 && ! V_146 )
return - V_123 ;
if ( F_38 ( V_2 ) )
F_39 ( V_2 ) ;
if ( V_2 -> V_5 == V_147 )
F_2 ( & V_2 -> V_8 ,
L_61 ) ;
if ( V_2 -> V_5 == V_148 && V_2 -> V_7 == 0xCC06 )
V_140 = V_149 ;
else if ( V_2 -> V_5 == 0x1c44 && V_2 -> V_7 == 0x8000 )
V_140 = V_150 ;
else if ( V_2 -> V_5 == 0x177d && V_2 -> V_7 == 0xa01c )
V_140 = V_151 ;
V_31 = F_87 ( V_2 ) ;
if ( V_31 )
return V_31 ;
if ( V_2 -> V_5 == V_15 &&
( V_2 -> V_7 == 0x2652 || V_2 -> V_7 == 0x2653 ) ) {
T_4 V_152 ;
F_88 ( V_2 , V_153 , & V_152 ) ;
if ( V_152 & 0x3 ) {
F_2 ( & V_2 -> V_8 ,
L_62 ) ;
return - V_123 ;
}
}
V_31 = F_89 ( V_2 , 1 << V_140 , V_154 ) ;
if ( V_31 == - V_155 )
F_90 ( V_2 ) ;
if ( V_31 )
return V_31 ;
V_4 = F_91 ( V_8 , sizeof( * V_4 ) , V_156 ) ;
if ( ! V_4 )
return - V_157 ;
V_4 -> V_10 |= ( unsigned long ) V_137 . V_16 ;
if ( V_135 == V_158 &&
( V_2 -> V_159 == 0xa1 || V_2 -> V_159 == 0xa2 ) )
V_4 -> V_10 |= V_122 ;
if ( V_135 == V_160 && V_2 -> V_159 >= 0x40 )
V_4 -> V_10 &= ~ V_161 ;
if ( F_54 ( V_2 ) )
V_4 -> V_10 &= ~ V_162 ;
V_4 -> V_56 = F_92 ( V_2 ) [ V_140 ] ;
if ( F_63 ( V_2 ) )
V_4 -> V_10 |= V_163 ;
#ifdef F_93
if ( V_2 -> V_5 == 0x177d && V_2 -> V_7 == 0xa01c )
V_4 -> V_164 = F_69 ;
#endif
F_1 ( V_2 , V_4 ) ;
if ( V_4 -> V_165 & V_166 ) {
V_137 . V_10 |= V_167 ;
if ( ! ( V_4 -> V_10 & V_168 ) )
V_137 . V_10 |= V_169 ;
V_137 . V_10 |= V_170 ;
}
if ( V_4 -> V_165 & V_171 )
V_137 . V_10 |= V_172 ;
F_94 ( V_4 , & V_137 ) ;
if ( F_58 ( V_2 ) ) {
V_137 . V_10 |= V_173 ;
F_2 ( & V_2 -> V_8 ,
L_63 ) ;
}
if ( F_60 ( V_2 ) ) {
V_4 -> V_10 |= V_60 ;
F_57 ( & V_2 -> V_8 ,
L_7 ) ;
}
if ( F_61 ( V_2 ) ) {
V_4 -> V_10 |= V_174 ;
F_2 ( & V_2 -> V_8 ,
L_64 ) ;
}
V_110 = F_95 ( F_96 ( V_4 -> V_165 ) , F_97 ( V_4 -> V_18 ) ) ;
V_14 = F_98 ( & V_2 -> V_8 , V_139 , V_110 ) ;
if ( ! V_14 )
return - V_157 ;
V_14 -> V_16 = V_4 ;
V_4 -> V_126 = F_91 ( & V_2 -> V_8 ,
sizeof( struct V_175 ) * V_110 , V_156 ) ;
if ( ! V_4 -> V_126 )
return - V_157 ;
F_82 ( V_2 , V_110 , V_4 ) ;
if ( ! ( V_4 -> V_165 & V_176 ) || V_177 )
V_14 -> V_10 |= V_178 ;
else
F_2 ( & V_2 -> V_8 , L_65 ) ;
if ( V_137 . V_10 & V_179 )
F_99 ( V_14 ) ;
for ( V_49 = 0 ; V_49 < V_14 -> V_110 ; V_49 ++ ) {
struct V_28 * V_29 = V_14 -> V_83 [ V_49 ] ;
F_100 ( V_29 , V_140 , - 1 , L_66 ) ;
F_100 ( V_29 , V_140 ,
0x100 + V_29 -> V_53 * 0x80 , L_67 ) ;
if ( V_29 -> V_10 & V_179 )
V_29 -> V_180 = V_4 -> V_181 ;
if ( ! ( V_4 -> V_18 & ( 1 << V_49 ) ) )
V_29 -> V_84 = & V_182 ;
}
F_47 ( V_14 ) ;
F_66 ( V_14 ) ;
V_31 = F_41 ( V_2 , V_4 -> V_165 & V_183 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_4 ( V_14 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_14 ) ;
F_45 ( V_14 ) ;
F_101 ( V_2 ) ;
V_31 = F_102 ( V_14 , & V_184 ) ;
if ( V_31 )
return V_31 ;
F_103 ( & V_2 -> V_8 ) ;
return 0 ;
}
static void F_104 ( struct V_1 * V_2 )
{
F_105 ( & V_2 -> V_8 ) ;
F_106 ( V_2 ) ;
}
