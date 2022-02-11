static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_7 * V_8 = & V_6 -> V_9 -> V_10 ;
unsigned long V_11 = 0 ;
int V_12 , V_13 ;
F_3 ( V_8 ) ;
V_13 = F_4 ( V_4 , V_14 ) ;
if ( V_13 < 0 ) {
F_5 ( V_8 ) ;
return V_15 ;
}
V_12 = F_4 ( V_4 , V_16 ) ;
if ( V_12 <= 0 ) {
F_5 ( V_8 ) ;
return V_15 ;
}
if ( V_12 & V_17 ) {
V_12 &= ~ V_17 ;
V_13 &= ~ V_18 ;
V_11 |= V_19 ;
}
if ( V_11 ) {
F_6 ( V_6 -> V_9 , 1 , V_11 ) ;
F_7 ( V_4 , V_16 , V_12 ) ;
F_7 ( V_4 , V_14 ,
V_13 ) ;
}
F_5 ( V_8 ) ;
return V_20 ;
}
static int F_8 ( struct V_3 * V_4 ,
struct V_21 * V_22 )
{
unsigned char V_23 [ 8 ] ;
int V_24 , V_12 ;
V_12 = F_4 ( V_4 , V_16 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_12 & V_25 ) {
F_9 ( & V_4 -> V_26 , L_1 ) ;
return - V_27 ;
}
V_24 = F_10 ( V_4 , V_28 ,
sizeof( V_23 ) , V_23 ) ;
if ( V_24 < 0 ) {
F_9 ( & V_4 -> V_26 , L_2 ) ;
return - V_29 ;
}
V_22 -> V_30 = F_11 ( V_23 [ V_31 ] & 0x7f ) ;
V_22 -> V_32 = F_11 ( V_23 [ V_33 ] & 0x7f ) ;
V_22 -> V_34 = F_11 ( V_23 [ V_35 ] & 0x3f ) ;
V_22 -> V_36 = F_11 ( V_23 [ V_37 ] & 0x3f ) ;
V_22 -> V_38 = V_23 [ V_39 ] & 0x07 ;
V_22 -> V_40 = F_11 ( V_23 [ V_41 ] & 0x1f ) - 1 ;
V_22 -> V_42 = F_11 ( V_23 [ V_43 ] ) + 100 ;
return F_12 ( V_22 ) ;
}
static int F_13 ( struct V_3 * V_4 , struct V_21 * V_22 )
{
unsigned char V_23 [ 8 ] ;
int V_24 , V_12 ;
if ( V_22 -> V_42 < 100 || V_22 -> V_42 > 199 )
return - V_27 ;
V_23 [ V_28 ] = 0 ;
V_23 [ V_31 ] = F_14 ( V_22 -> V_30 ) ;
V_23 [ V_33 ] = F_14 ( V_22 -> V_32 ) ;
V_23 [ V_35 ] = F_14 ( V_22 -> V_34 ) ;
V_23 [ V_37 ] = F_14 ( V_22 -> V_36 ) ;
V_23 [ V_41 ] = F_14 ( V_22 -> V_40 + 1 ) ;
V_23 [ V_43 ] = F_14 ( V_22 -> V_42 - 100 ) ;
V_23 [ V_39 ] = V_22 -> V_38 ;
V_24 = F_15 ( V_4 , V_28 ,
sizeof( V_23 ) , V_23 ) ;
if ( V_24 < 0 ) {
F_9 ( & V_4 -> V_26 , L_3 ) ;
return V_24 ;
}
V_12 = F_4 ( V_4 , V_16 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( F_7 ( V_4 , V_16 ,
V_12 & ~ V_25 ) ) {
F_9 ( & V_4 -> V_26 , L_4 ) ;
return - V_29 ;
}
return V_24 ;
}
static int F_16 ( struct V_44 * V_26 , struct V_45 * V_46 )
{
struct V_3 * V_4 = F_17 ( V_26 ) ;
struct V_5 * V_47 = F_2 ( V_4 ) ;
T_2 V_48 ;
if ( V_47 -> V_49 & V_50 ) {
V_48 = F_4 ( V_4 , V_16 ) ;
F_18 ( V_46 , L_5 ,
( V_48 & V_51 ) ? L_6 : L_7 ) ;
}
return 0 ;
}
static int F_19 ( struct V_44 * V_26 , struct V_21 * V_22 )
{
return F_8 ( F_17 ( V_26 ) , V_22 ) ;
}
static int F_20 ( struct V_44 * V_26 , struct V_21 * V_22 )
{
return F_13 ( F_17 ( V_26 ) , V_22 ) ;
}
static int F_21 ( struct V_44 * V_26 , unsigned int V_52 )
{
struct V_3 * V_4 = F_17 ( V_26 ) ;
int V_12 , V_53 ;
V_12 = F_4 ( V_4 , V_14 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_52 )
V_12 |= V_18 ;
else
V_12 &= ~ V_18 ;
V_53 = F_7 ( V_4 , V_14 , V_12 ) ;
if ( V_53 < 0 ) {
F_22 ( V_26 , L_8 , V_53 ) ;
return V_53 ;
}
return 0 ;
}
static int F_23 ( struct V_44 * V_26 , struct V_54 * V_55 )
{
struct V_3 * V_4 = F_17 ( V_26 ) ;
T_2 V_56 [ 5 ] ;
int V_57 , V_24 ;
V_56 [ 0 ] = F_14 ( V_55 -> time . V_40 + 1 ) ;
V_56 [ 1 ] = F_14 ( V_55 -> time . V_36 ) ;
V_56 [ 2 ] = F_14 ( V_55 -> time . V_34 ) ;
V_56 [ 3 ] = F_14 ( V_55 -> time . V_32 ) ;
V_56 [ 4 ] = F_14 ( V_55 -> time . V_30 ) ;
V_57 = F_4 ( V_4 , V_14 ) ;
if ( V_57 < 0 )
return V_57 ;
V_24 = F_7 ( V_4 , V_14 ,
V_57 & ~ ( V_18 ) ) ;
if ( V_24 < 0 ) {
F_9 ( V_26 , L_9 ) ;
return V_24 ;
}
V_57 = F_4 ( V_4 , V_16 ) ;
if ( V_57 < 0 )
return V_57 ;
V_24 = F_7 ( V_4 , V_16 ,
V_57 & ~ ( V_17 ) ) ;
if ( V_24 < 0 ) {
F_9 ( V_26 , L_10 ) ;
return V_24 ;
}
V_24 = F_15 ( V_4 , V_14 ,
5 , V_56 ) ;
if ( V_24 )
return V_24 ;
if ( V_55 -> V_52 ) {
V_56 [ 0 ] |= V_18 ;
V_24 = F_7 ( V_4 , V_14 ,
V_56 [ 0 ] ) ;
if ( V_24 )
return V_24 ;
}
return 0 ;
}
static int F_24 ( struct V_44 * V_26 , struct V_54 * V_55 )
{
struct V_3 * V_4 = F_17 ( V_26 ) ;
T_2 V_56 [ 5 ] ;
int V_12 , V_57 ;
V_57 = F_10 ( V_4 , V_14 ,
5 , V_56 ) ;
if ( V_57 != 5 )
return V_57 < 0 ? V_57 : - V_29 ;
V_12 = F_4 ( V_4 , V_16 ) ;
if ( V_12 < 0 )
return V_12 ;
V_55 -> time . V_30 = F_11 ( V_56 [ 4 ] & 0x7f ) ;
V_55 -> time . V_32 = F_11 ( V_56 [ 3 ] & 0x7f ) ;
V_55 -> time . V_34 = F_11 ( V_56 [ 2 ] & 0x3f ) ;
V_55 -> time . V_38 = - 1 ;
V_55 -> time . V_36 = F_11 ( V_56 [ 1 ] & 0x3f ) ;
V_55 -> time . V_40 = F_11 ( V_56 [ 0 ] & 0x3f ) ;
V_55 -> time . V_42 = - 1 ;
V_55 -> V_52 = ! ! ( V_56 [ 0 ] & V_18 ) ;
V_55 -> V_58 = ( V_12 & V_17 ) && V_55 -> V_52 ;
return 0 ;
}
static T_3 F_25 ( struct V_44 * V_26 ,
struct V_59 * V_60 , char * V_23 )
{
struct V_3 * V_4 = F_17 ( V_26 ) ;
int V_61 ;
V_61 = F_4 ( V_4 , V_16 ) ;
if ( V_61 < 0 )
return V_61 ;
return sprintf ( V_23 , L_11 , V_61 ) ;
}
static T_3 F_26 ( struct V_44 * V_26 ,
struct V_59 * V_60 , char * V_23 )
{
struct V_3 * V_4 = F_17 ( V_26 ) ;
struct V_5 * V_47 = F_2 ( V_4 ) ;
int V_61 , V_62 ;
if ( ! ( V_47 -> V_49 & V_63 ) )
return - V_27 ;
V_62 = V_64 ;
if ( V_47 -> V_49 & V_65 )
V_62 = V_39 ;
V_61 = F_4 ( V_4 , V_62 ) ;
if ( V_61 < 0 )
return V_61 ;
V_61 = ( V_61 >> 4 ) & 0xf ;
switch ( V_61 ) {
case 0 :
break;
case 1 :
V_61 = 32768 ;
break;
default:
V_61 = 32768 >> V_61 ;
}
return sprintf ( V_23 , L_12 , V_61 ) ;
}
static T_3 F_27 ( struct V_44 * V_26 ,
struct V_59 * V_60 ,
const char * V_23 , T_4 V_66 )
{
struct V_3 * V_4 = F_17 ( V_26 ) ;
struct V_5 * V_47 = F_2 ( V_4 ) ;
int V_67 , V_68 , V_62 , V_69 ;
unsigned long V_61 ;
V_69 = F_28 ( V_23 , 0 , & V_61 ) ;
if ( V_69 < 0 )
return V_69 ;
if ( ! ( V_47 -> V_49 & V_63 ) )
return - V_27 ;
if ( V_61 ) {
if ( ! F_29 ( V_61 ) )
return - V_27 ;
V_61 = F_30 ( V_61 ) ;
if ( V_61 == 15 )
V_61 = 1 ;
else if ( V_61 < 14 )
V_61 = 15 - V_61 ;
else
return - V_27 ;
}
V_67 = F_4 ( V_4 , V_14 ) ;
if ( V_67 < 0 )
return V_67 ;
V_62 = V_64 ;
if ( V_47 -> V_49 & V_65 )
V_62 = V_39 ;
V_68 = F_4 ( V_4 , V_62 ) ;
if ( V_68 < 0 )
return V_68 ;
V_68 = ( V_68 & 0x0f ) | ( V_61 << 4 ) ;
V_69 = F_7 ( V_4 , V_14 ,
V_67 & ~ V_70 ) ;
if ( V_69 < 0 )
return V_69 ;
if ( V_61 ) {
V_69 = F_7 ( V_4 , V_62 , V_68 ) ;
if ( V_69 < 0 )
return V_69 ;
V_69 = F_7 ( V_4 , V_14 ,
V_67 | V_70 ) ;
if ( V_69 < 0 )
return V_69 ;
}
return V_66 ;
}
static void F_31 ( void )
{
unsigned char V_71 [ 2 ] ;
struct V_72 V_73 [ 1 ] = {
{
. V_74 = V_75 -> V_74 ,
. V_12 = 0 ,
. V_76 = 2 ,
. V_23 = V_71 ,
} ,
} ;
struct V_5 * V_47 = F_2 ( V_75 ) ;
V_71 [ 0 ] = 0x09 ;
if ( V_77 > 31 )
V_71 [ 1 ] = ( V_77 & 0xFC ) | 0x83 ;
else
V_71 [ 1 ] = V_77 << 2 | 0x82 ;
if ( V_47 -> V_49 & V_78 )
V_71 [ 1 ] &= ~ V_79 ;
F_32 ( V_75 -> V_80 , V_73 , 1 ) ;
}
static void F_33 ( void )
{
unsigned char V_71 [ 2 ] , V_81 [ 0x10 ] ;
struct V_72 V_82 [ 2 ] = {
{
. V_74 = V_75 -> V_74 ,
. V_12 = 0 ,
. V_76 = 1 ,
. V_23 = V_71 ,
} ,
{
. V_74 = V_75 -> V_74 ,
. V_12 = V_83 ,
. V_76 = 1 ,
. V_23 = V_81 ,
} ,
} ;
struct V_72 V_73 [ 1 ] = {
{
. V_74 = V_75 -> V_74 ,
. V_12 = 0 ,
. V_76 = 2 ,
. V_23 = V_71 ,
} ,
} ;
V_71 [ 0 ] = 0x09 ;
F_32 ( V_75 -> V_80 , V_82 , 2 ) ;
V_71 [ 0 ] = 0x09 ;
V_71 [ 1 ] = 0x00 ;
F_32 ( V_75 -> V_80 , V_73 , 1 ) ;
}
static T_3 F_34 ( struct V_84 * V_84 , const char T_5 * V_23 ,
T_4 V_66 , T_6 * V_85 )
{
if ( V_66 ) {
F_31 () ;
return 1 ;
}
return 0 ;
}
static T_3 F_35 ( struct V_84 * V_84 , char T_5 * V_23 ,
T_4 V_66 , T_6 * V_85 )
{
return 0 ;
}
static int F_36 ( struct V_84 * V_84 , unsigned int V_86 ,
unsigned long V_87 )
{
int V_88 , V_89 ;
static struct V_90 V_91 = {
. V_92 = V_93 | V_94 |
V_95 ,
. V_96 = 1 ,
. V_97 = L_13
} ;
switch ( V_86 ) {
case V_98 :
return F_37 ( (struct V_90 T_5 * ) V_87 , & V_91 ,
sizeof( V_91 ) ) ? - V_99 : 0 ;
case V_100 :
case V_101 :
return F_38 ( V_102 , ( int T_5 * ) V_87 ) ;
case V_103 :
F_31 () ;
return 0 ;
case V_104 :
if ( F_39 ( V_88 , ( int T_5 * ) V_87 ) )
return - V_99 ;
if ( V_88 < 1 || V_88 > 124 )
return - V_27 ;
V_77 = V_88 ;
F_31 () ;
case V_105 :
return F_38 ( V_77 , ( int T_5 * ) V_87 ) ;
case V_106 :
if ( F_40 ( & V_89 , ( int T_5 * ) V_87 , sizeof( int ) ) )
return - V_99 ;
if ( V_89 & V_107 ) {
F_41 ( L_14 ) ;
F_33 () ;
}
if ( V_89 & V_108 ) {
F_41 ( L_15 ) ;
F_31 () ;
}
return - V_27 ;
}
return - V_109 ;
}
static long F_42 ( struct V_84 * V_84 , unsigned int V_86 ,
unsigned long V_87 )
{
int V_57 ;
F_3 ( & V_110 ) ;
V_57 = F_36 ( V_84 , V_86 , V_87 ) ;
F_5 ( & V_110 ) ;
return V_57 ;
}
static int F_43 ( struct V_111 * V_111 , struct V_84 * V_84 )
{
if ( F_44 ( V_111 -> V_112 ) == V_113 ) {
F_3 ( & V_110 ) ;
if ( F_45 ( 0 , & V_114 ) ) {
F_5 ( & V_110 ) ;
return - V_115 ;
}
V_114 = 1 ;
F_5 ( & V_110 ) ;
return F_46 ( V_111 , V_84 ) ;
}
return - V_116 ;
}
static int F_47 ( struct V_111 * V_111 , struct V_84 * V_84 )
{
if ( F_44 ( V_111 -> V_112 ) == V_113 )
F_48 ( 0 , & V_114 ) ;
return 0 ;
}
static int F_49 ( struct V_117 * V_118 , unsigned long V_119 ,
void * V_120 )
{
if ( V_119 == V_121 || V_119 == V_122 )
F_33 () ;
return V_123 ;
}
static void F_50 ( void * V_124 )
{
struct V_44 * V_26 = V_124 ;
F_51 ( & V_26 -> V_125 , & V_126 ) ;
}
static int F_52 ( struct V_3 * V_4 ,
const struct V_127 * V_128 )
{
struct V_129 * V_80 = F_53 ( V_4 -> V_26 . V_130 ) ;
int V_69 = 0 ;
struct V_131 * V_9 = NULL ;
struct V_21 V_22 ;
struct V_5 * V_5 = NULL ;
if ( ! F_54 ( V_4 -> V_80 , V_132 |
V_133 ) ) {
F_9 ( & V_80 -> V_26 , L_16 ) ;
return - V_116 ;
}
V_5 = F_55 ( & V_4 -> V_26 , sizeof( * V_5 ) ,
V_134 ) ;
if ( ! V_5 )
return - V_135 ;
V_5 -> V_49 = V_128 -> V_136 ;
F_56 ( V_4 , V_5 ) ;
if ( V_4 -> V_1 > 0 ) {
V_69 = F_57 ( & V_4 -> V_26 , V_4 -> V_1 ,
NULL , F_1 ,
V_137 | V_138 ,
L_17 , V_4 ) ;
if ( V_69 ) {
F_58 ( & V_4 -> V_26 , L_18 ) ;
V_4 -> V_1 = 0 ;
} else {
V_139 . V_140 = F_24 ;
V_139 . V_141 = F_23 ;
V_139 . V_142 = F_21 ;
F_59 ( & V_4 -> V_26 , true ) ;
}
}
V_9 = F_60 ( & V_4 -> V_26 , V_4 -> V_143 ,
& V_139 , V_144 ) ;
if ( F_61 ( V_9 ) )
return F_62 ( V_9 ) ;
V_5 -> V_9 = V_9 ;
V_69 = F_4 ( V_4 , V_145 ) ;
if ( V_69 >= 0 && V_69 & V_146 ) {
if ( V_5 -> V_49 & V_147 ) {
F_8 ( V_4 , & V_22 ) ;
F_22 ( & V_4 -> V_26 , L_19 ) ;
F_22 ( & V_4 -> V_26 ,
L_20 ,
V_22 . V_42 + 1900 ,
V_22 . V_40 + 1 , V_22 . V_36 , V_22 . V_34 ,
V_22 . V_32 , V_22 . V_30 ) ;
}
V_69 = F_7 ( V_4 , V_145 ,
V_69 & ~ V_146 ) ;
}
if ( V_69 < 0 ) {
F_9 ( & V_4 -> V_26 , L_21 ) ;
return V_69 ;
}
V_69 = F_4 ( V_4 , V_31 ) ;
if ( V_69 >= 0 && V_69 & V_148 )
V_69 = F_7 ( V_4 , V_31 ,
V_69 & ~ V_148 ) ;
if ( V_69 < 0 ) {
F_9 ( & V_4 -> V_26 , L_22 ) ;
return V_69 ;
}
V_69 = F_63 ( & ( & V_4 -> V_26 ) -> V_125 , & V_126 ) ;
if ( V_69 ) {
F_9 ( & V_4 -> V_26 , L_23 , V_69 ) ;
return V_69 ;
}
V_69 = F_64 ( & V_4 -> V_26 , F_50 ,
& V_4 -> V_26 ) ;
if ( V_69 ) {
F_50 ( & V_4 -> V_26 ) ;
F_9 ( & V_4 -> V_26 ,
L_24 , V_69 ) ;
return V_69 ;
}
#ifdef F_65
if ( V_5 -> V_49 & V_147 ) {
V_75 = V_4 ;
V_69 = F_66 ( & V_149 ) ;
if ( V_69 )
return V_69 ;
V_69 = F_67 ( & V_150 ) ;
if ( V_69 ) {
F_68 ( & V_149 ) ;
return V_69 ;
}
}
#endif
return 0 ;
}
static int F_69 ( struct V_3 * V_4 )
{
#ifdef F_65
struct V_5 * V_47 = F_2 ( V_4 ) ;
if ( V_47 -> V_49 & V_147 ) {
F_68 ( & V_149 ) ;
F_70 ( & V_150 ) ;
}
#endif
return 0 ;
}
