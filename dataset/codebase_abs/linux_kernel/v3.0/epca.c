static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
V_2 -> F_1 ( V_2 , V_3 ) ;
}
static void F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
V_2 -> F_2 ( V_2 , V_3 ) ;
}
static void F_3 ( struct V_4 * V_5 )
{
V_5 -> V_6 -> F_3 ( V_5 ) ;
}
static void F_4 ( struct V_4 * V_5 )
{
V_5 -> V_6 -> F_4 ( V_5 ) ;
}
static void F_5 ( struct V_4 * V_5 )
{
V_5 -> V_6 -> F_5 ( V_5 ) ;
}
static void F_6 ( struct V_4 * V_5 )
{
V_5 -> V_6 -> F_6 ( V_5 ) ;
}
static void F_7 ( struct V_4 * V_5 )
{
V_5 -> V_6 -> F_7 ( V_5 ) ;
}
static void F_8 ( struct V_4 * V_5 )
{
V_5 -> V_6 -> F_8 ( V_5 ) ;
}
static void F_9 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_10 ( V_7 | V_3 , V_2 -> V_8 + 1 ) ;
}
static void F_11 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_10 ( 0 , V_2 -> V_8 + 1 ) ;
}
static void F_12 ( struct V_4 * V_5 )
{
F_10 ( V_7 , ( int ) V_5 -> V_6 -> V_8 + 1 ) ;
}
static void F_13 ( struct V_4 * V_5 )
{
F_10 ( V_5 -> V_9 , ( int ) V_5 -> V_6 -> V_8 + 1 ) ;
}
static void F_14 ( struct V_4 * V_5 )
{
F_10 ( V_5 -> V_10 , ( int ) V_5 -> V_6 -> V_8 + 1 ) ;
}
static void F_15 ( struct V_4 * V_5 )
{
F_10 ( 0 , ( int ) V_5 -> V_6 -> V_8 + 1 ) ;
}
static void F_16 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_10 ( V_7 | V_3 , V_2 -> V_8 + 1 ) ;
}
static void F_17 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_10 ( F_18 ( V_2 -> V_8 ) & ~ V_11 , V_2 -> V_8 + 1 ) ;
F_10 ( 0 , V_2 -> V_8 + 1 ) ;
}
static void F_19 ( struct V_4 * V_5 )
{
F_10 ( V_7 , ( int ) V_5 -> V_6 -> V_8 + 1 ) ;
}
static void F_20 ( struct V_4 * V_5 )
{
F_10 ( V_5 -> V_9 , ( int ) V_5 -> V_6 -> V_8 + 1 ) ;
}
static void F_21 ( struct V_4 * V_5 )
{
F_10 ( V_5 -> V_10 , ( int ) V_5 -> V_6 -> V_8 + 1 ) ;
}
static void F_22 ( struct V_4 * V_5 )
{
F_10 ( 0 , ( int ) V_5 -> V_6 -> V_8 ) ;
F_10 ( 0 , ( int ) V_5 -> V_6 -> V_8 + 1 ) ;
}
static void F_23 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_10 ( F_18 ( V_2 -> V_8 ) | V_11 , V_2 -> V_8 ) ;
}
static void F_24 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_10 ( F_18 ( V_2 -> V_8 ) & ~ V_11 , V_2 -> V_8 ) ;
}
static void F_25 ( struct V_4 * V_5 )
{
F_10 ( V_11 , V_5 -> V_6 -> V_8 ) ;
}
static void F_26 ( struct V_4 * V_5 )
{
F_10 ( V_11 , V_5 -> V_6 -> V_8 ) ;
}
static void F_27 ( struct V_4 * V_5 )
{
F_10 ( V_11 , V_5 -> V_6 -> V_8 ) ;
}
static void F_28 ( struct V_4 * V_5 )
{
F_10 ( 0 , V_5 -> V_6 -> V_8 ) ;
}
static void F_29 ( struct V_4 * V_5 )
{
F_30 ( F_18 ( V_5 -> V_6 -> V_8 ) & V_11 , L_1 ) ;
}
static void F_31 ( struct V_4 * V_5 )
{
F_30 ( ! ( F_18 ( V_5 -> V_6 -> V_8 ) & V_11 ) , L_2 ) ;
}
static void F_32 ( struct V_1 * V_2 , unsigned int V_3 )
{
}
static void F_33 ( struct V_1 * V_2 , unsigned int V_3 )
{
}
static void F_34 ( struct V_4 * V_5 )
{
}
static void F_35 ( struct V_4 * V_5 )
{
}
static void F_36 ( struct V_4 * V_5 )
{
}
static void F_37 ( struct V_4 * V_5 )
{
}
static void F_38 ( struct V_4 * V_5 )
{
}
static void F_39 ( struct V_4 * V_5 )
{
}
static struct V_4 * F_40 ( struct V_12 * V_13 )
{
if ( V_13 ) {
struct V_4 * V_5 = V_13 -> V_14 ;
if ( V_5 >= & V_15 [ 0 ] && V_5 < & V_15 [ V_16 ] ) {
if ( V_5 -> V_17 == V_18 )
return V_5 ;
}
}
return NULL ;
}
static void F_41 ( struct V_4 * V_5 , int V_19 )
{
V_5 -> V_19 |= 1 << V_19 ;
F_42 ( & V_5 -> V_20 ) ;
}
static void F_43 ( int line , char * V_21 )
{
F_44 ( V_22 L_3 , line , V_21 ) ;
}
static void F_45 ( struct V_12 * V_13 , struct V_23 * V_24 )
{
struct V_4 * V_5 ;
struct V_25 * V_8 ;
V_5 = F_40 ( V_13 ) ;
if ( V_5 == NULL )
return;
V_8 = & V_5 -> V_8 ;
if ( F_46 ( V_8 , V_13 , V_24 ) == 0 )
return;
F_47 ( V_13 ) ;
F_48 ( V_5 , V_13 ) ;
F_49 ( V_8 , V_13 ) ;
V_5 -> V_19 = 0 ;
F_50 ( V_8 , NULL ) ;
}
static void F_48 ( struct V_4 * V_5 , struct V_12 * V_13 )
{
unsigned long V_26 ;
struct V_27 T_1 * V_28 ;
struct V_25 * V_8 = & V_5 -> V_8 ;
if ( ! ( V_8 -> V_26 & V_29 ) )
return;
F_51 ( & V_30 , V_26 ) ;
F_3 ( V_5 ) ;
V_28 = V_5 -> V_31 ;
if ( V_28 )
F_52 ( 0 , & V_28 -> V_32 ) ;
if ( V_13 -> V_33 -> V_34 & V_35 ) {
V_5 -> V_36 &= ~ ( V_5 -> V_37 | V_5 -> V_38 ) ;
F_53 ( V_5 , V_39 , 0 , V_5 -> V_38 | V_5 -> V_37 , 10 , 1 ) ;
}
F_6 ( V_5 ) ;
V_8 -> V_26 &= ~ V_29 ;
F_54 ( & V_30 , V_26 ) ;
}
static void F_55 ( struct V_12 * V_13 )
{
struct V_4 * V_5 ;
V_5 = F_40 ( V_13 ) ;
if ( V_5 != NULL ) {
F_47 ( V_13 ) ;
F_56 ( V_13 ) ;
F_48 ( V_5 , V_13 ) ;
V_5 -> V_19 = 0 ;
F_57 ( & V_5 -> V_8 ) ;
}
}
static int F_58 ( struct V_12 * V_13 ,
const unsigned char * V_40 , int V_41 )
{
unsigned int V_42 , V_43 ;
int V_44 ;
int V_45 ;
int V_46 ;
struct V_4 * V_5 ;
unsigned long V_26 ;
int V_47 ;
struct V_27 T_1 * V_28 ;
V_5 = F_40 ( V_13 ) ;
if ( V_5 == NULL )
return 0 ;
V_28 = V_5 -> V_31 ;
V_45 = V_5 -> V_48 ;
V_46 = 0 ;
F_51 ( & V_30 , V_26 ) ;
F_3 ( V_5 ) ;
V_42 = F_59 ( & V_28 -> V_49 ) & ( V_45 - 1 ) ;
V_43 = F_59 ( & V_28 -> V_50 ) ;
if ( V_43 != F_59 ( & V_28 -> V_50 ) )
V_43 = F_59 ( & V_28 -> V_50 ) ;
V_43 &= ( V_45 - 1 ) ;
if ( V_42 >= V_43 ) {
V_44 = V_45 - V_42 ;
V_47 = V_45 - ( V_42 - V_43 ) - 1 ;
} else {
V_47 = V_43 - V_42 - 1 ;
V_44 = V_47 ;
}
V_41 = F_60 ( V_47 , V_41 ) ;
F_5 ( V_5 ) ;
while ( V_41 > 0 ) {
V_44 = F_60 ( V_41 , V_44 ) ;
F_61 ( V_5 -> V_51 + V_42 , V_40 , V_44 ) ;
V_40 += V_44 ;
V_42 += V_44 ;
V_46 += V_44 ;
V_41 -= V_44 ;
if ( V_42 >= V_45 ) {
V_42 = 0 ;
V_44 = V_43 ;
}
}
V_5 -> V_52 |= V_53 ;
F_3 ( V_5 ) ;
F_62 ( V_42 , & V_28 -> V_49 ) ;
if ( ( V_5 -> V_52 & V_54 ) == 0 ) {
V_5 -> V_52 |= V_54 ;
F_52 ( 1 , & V_28 -> V_55 ) ;
}
F_6 ( V_5 ) ;
F_54 ( & V_30 , V_26 ) ;
return V_46 ;
}
static int F_63 ( struct V_12 * V_13 )
{
int V_47 = 0 ;
struct V_4 * V_5 ;
unsigned long V_26 ;
unsigned int V_42 , V_43 ;
struct V_27 T_1 * V_28 ;
V_5 = F_40 ( V_13 ) ;
if ( V_5 != NULL ) {
F_51 ( & V_30 , V_26 ) ;
F_3 ( V_5 ) ;
V_28 = V_5 -> V_31 ;
V_42 = F_59 ( & V_28 -> V_49 ) & ( V_5 -> V_48 - 1 ) ;
V_43 = F_59 ( & V_28 -> V_50 ) ;
if ( V_43 != F_59 ( & V_28 -> V_50 ) )
V_43 = F_59 ( & V_28 -> V_50 ) ;
V_43 &= ( V_5 -> V_48 - 1 ) ;
V_47 = V_43 - V_42 - 1 ;
if ( V_47 < 0 )
V_47 += V_5 -> V_48 ;
if ( V_47 && ( V_5 -> V_52 & V_54 ) == 0 ) {
V_5 -> V_52 |= V_54 ;
F_52 ( 1 , & V_28 -> V_55 ) ;
}
F_6 ( V_5 ) ;
F_54 ( & V_30 , V_26 ) ;
}
return V_47 ;
}
static int F_64 ( struct V_12 * V_13 )
{
int V_56 ;
unsigned int V_57 , V_42 , V_43 ;
int V_47 ;
unsigned long V_26 ;
struct V_4 * V_5 ;
struct V_27 T_1 * V_28 ;
V_5 = F_40 ( V_13 ) ;
if ( V_5 == NULL )
return 0 ;
F_51 ( & V_30 , V_26 ) ;
F_3 ( V_5 ) ;
V_28 = V_5 -> V_31 ;
V_43 = F_59 ( & V_28 -> V_50 ) ;
V_42 = F_59 ( & V_28 -> V_49 ) ;
V_57 = F_59 ( & V_5 -> V_58 -> V_59 ) ;
if ( V_43 == V_42 && F_59 ( & V_5 -> V_58 -> V_60 ) == V_57 &&
F_65 ( & V_28 -> V_61 ) == 0 )
V_56 = 0 ;
else {
V_42 = F_59 ( & V_28 -> V_49 ) & ( V_5 -> V_48 - 1 ) ;
V_43 &= ( V_5 -> V_48 - 1 ) ;
V_47 = V_43 - V_42 - 1 ;
if ( V_47 < 0 )
V_47 += V_5 -> V_48 ;
V_56 = ( int ) ( V_5 -> V_48 - V_47 ) ;
if ( ! ( V_5 -> V_52 & V_62 ) )
F_66 ( V_13 , V_5 ) ;
}
F_6 ( V_5 ) ;
F_54 ( & V_30 , V_26 ) ;
return V_56 ;
}
static void F_47 ( struct V_12 * V_13 )
{
unsigned int V_43 ;
unsigned long V_26 ;
struct V_4 * V_5 ;
struct V_27 T_1 * V_28 ;
V_5 = F_40 ( V_13 ) ;
if ( V_5 == NULL )
return;
F_51 ( & V_30 , V_26 ) ;
F_3 ( V_5 ) ;
V_28 = V_5 -> V_31 ;
V_43 = F_59 ( & V_28 -> V_50 ) ;
F_53 ( V_5 , V_63 , ( unsigned ) V_43 , 0 , 0 , 0 ) ;
F_6 ( V_5 ) ;
F_54 ( & V_30 , V_26 ) ;
F_67 ( V_13 ) ;
}
static void F_68 ( struct V_12 * V_13 )
{
struct V_4 * V_5 ;
V_5 = F_40 ( V_13 ) ;
if ( V_5 != NULL ) {
unsigned long V_26 ;
F_51 ( & V_30 , V_26 ) ;
if ( ( V_5 -> V_52 & V_53 ) &&
! ( V_5 -> V_52 & V_62 ) )
F_66 ( V_13 , V_5 ) ;
F_54 ( & V_30 , V_26 ) ;
}
}
static int F_69 ( struct V_25 * V_8 )
{
struct V_4 * V_5 = F_70 ( V_8 , struct V_4 , V_8 ) ;
if ( V_5 -> V_64 & V_5 -> V_65 )
return 1 ;
return 0 ;
}
static void F_71 ( struct V_25 * V_8 , int V_66 )
{
}
static int F_72 ( struct V_12 * V_13 , struct V_23 * V_24 )
{
struct V_4 * V_5 ;
struct V_25 * V_8 ;
unsigned long V_26 ;
int line , V_67 , V_68 ;
struct V_27 T_1 * V_28 ;
unsigned int V_42 ;
line = V_13 -> V_69 ;
if ( line < 0 || line >= V_16 )
return - V_70 ;
V_5 = & V_15 [ line ] ;
V_8 = & V_5 -> V_8 ;
V_68 = V_5 -> V_68 ;
if ( V_71 ) {
if ( V_72 & V_73 )
F_44 ( V_22 L_4 ) ;
if ( V_72 & V_74 )
F_44 ( V_22 L_5 ) ;
if ( V_72 & V_75 )
F_44 ( V_22 L_6 ) ;
if ( V_72 & V_76 )
F_44 ( V_22 L_7 ) ;
if ( V_72 & V_77 )
F_44 ( V_22 L_8 ) ;
if ( V_72 & V_78 )
F_44 ( V_22 L_9 ) ;
V_13 -> V_14 = NULL ;
return - V_70 ;
}
if ( V_68 >= V_79 || V_80 [ V_68 ] . V_81 == V_82 ) {
V_13 -> V_14 = NULL ;
return ( - V_70 ) ;
}
V_28 = V_5 -> V_31 ;
if ( V_28 == NULL ) {
V_13 -> V_14 = NULL ;
return - V_70 ;
}
F_51 ( & V_8 -> V_83 , V_26 ) ;
V_8 -> V_84 ++ ;
V_13 -> V_14 = V_5 ;
V_8 -> V_13 = V_13 ;
F_73 ( & V_30 ) ;
F_3 ( V_5 ) ;
V_5 -> V_52 = 0 ;
V_5 -> V_64 = F_65 ( & V_28 -> V_85 ) ;
V_42 = F_59 ( & V_28 -> V_86 ) ;
F_62 ( V_42 , & V_28 -> V_87 ) ;
F_74 ( V_13 , V_5 ) ;
F_6 ( V_5 ) ;
F_75 ( & V_30 ) ;
V_8 -> V_26 |= V_29 ;
F_54 ( & V_8 -> V_83 , V_26 ) ;
V_67 = F_76 ( V_8 , V_13 , V_24 ) ;
if ( V_67 )
return V_67 ;
F_51 ( & V_8 -> V_83 , V_26 ) ;
V_8 -> V_13 = V_13 ;
F_73 ( & V_30 ) ;
F_3 ( V_5 ) ;
F_52 ( 1 , & V_28 -> V_32 ) ;
F_6 ( V_5 ) ;
F_75 ( & V_30 ) ;
F_54 ( & V_8 -> V_83 , V_26 ) ;
return 0 ;
}
static int T_2 F_77 ( void )
{
return F_78 () ;
}
static void T_3 F_79 ( void )
{
int V_84 , V_88 ;
struct V_1 * V_89 ;
struct V_4 * V_5 ;
F_80 ( & V_90 ) ;
if ( F_81 ( V_91 ) ||
F_81 ( V_92 ) ) {
F_44 ( V_93 L_10 ) ;
return;
}
F_82 ( V_91 ) ;
F_82 ( V_92 ) ;
for ( V_88 = 0 ; V_88 < V_79 ; V_88 ++ ) {
V_89 = & V_80 [ V_88 ] ;
if ( ! V_89 ) {
F_44 ( V_22 L_11 ) ;
return;
}
V_5 = V_94 [ V_88 ] ;
for ( V_84 = 0 ; V_84 < V_89 -> V_95 ; V_84 ++ , V_5 ++ ) {
struct V_12 * V_13 = F_83 ( & V_5 -> V_8 ) ;
if ( V_13 ) {
F_84 ( V_13 ) ;
F_85 ( V_13 ) ;
}
}
}
F_86 ( & V_96 ) ;
}
static int F_87 ( struct V_12 * V_13 , struct V_23 * V_24 )
{
return 0 ;
}
static int T_2 F_78 ( void )
{
int V_88 ;
struct V_1 * V_89 ;
unsigned char V_97 = 0 ;
int V_98 = - V_99 ;
int V_100 , V_101 ;
V_101 = 0 ;
V_91 = F_88 ( V_102 ) ;
if ( ! V_91 )
goto V_103;
V_92 = F_88 ( V_102 ) ;
if ( ! V_92 )
goto V_104;
if ( ! V_105 ) {
V_16 = V_106 ;
V_79 = V_107 ;
memcpy ( & V_80 , & V_108 ,
sizeof( struct V_1 ) * V_107 ) ;
}
F_44 ( V_109 L_12 , V_110 ) ;
V_100 = 0 ;
if ( V_79 < V_111 )
V_100 += F_89 () ;
V_79 += V_100 ;
V_91 -> V_112 = V_113 ;
V_91 -> V_114 = L_13 ;
V_91 -> V_115 = V_116 ;
V_91 -> V_117 = 0 ;
V_91 -> type = V_118 ;
V_91 -> V_119 = V_120 ;
V_91 -> V_121 = V_122 ;
V_91 -> V_121 . V_123 = 0 ;
V_91 -> V_121 . V_124 = 0 ;
V_91 -> V_121 . V_34 = V_125 | V_126 | V_127 | V_128 | V_35 ;
V_91 -> V_121 . V_129 = 0 ;
V_91 -> V_121 . V_130 = 9600 ;
V_91 -> V_121 . V_131 = 9600 ;
V_91 -> V_26 = V_132 | V_133 ;
F_90 ( V_91 , & V_134 ) ;
V_92 -> V_112 = V_113 ;
V_92 -> V_114 = L_14 ;
V_92 -> V_115 = V_135 ;
V_92 -> V_117 = 0 ;
V_92 -> type = V_118 ;
V_92 -> V_119 = V_136 ;
V_92 -> V_121 = V_122 ;
V_92 -> V_121 . V_123 = 0 ;
V_92 -> V_121 . V_124 = 0 ;
V_92 -> V_121 . V_129 = 0 ;
V_92 -> V_121 . V_34 = V_125 | V_126 | V_127 | V_35 ;
V_92 -> V_121 . V_130 = 9600 ;
V_92 -> V_121 . V_131 = 9600 ;
V_92 -> V_26 = V_132 ;
F_90 ( V_92 , & V_137 ) ;
for ( V_88 = 0 ; V_88 < V_79 ; V_88 ++ ) {
V_89 = & V_80 [ V_88 ] ;
switch ( V_89 -> type ) {
case V_138 :
case V_139 :
V_89 -> F_1 = F_9 ;
V_89 -> F_2 = F_11 ;
V_89 -> F_3 = F_12 ;
V_89 -> F_5 = F_14 ;
V_89 -> F_4 = F_13 ;
V_89 -> F_6 = F_15 ;
V_89 -> F_7 = F_38 ;
V_89 -> F_8 = F_39 ;
break;
case V_140 :
case V_141 :
case V_142 :
V_89 -> F_1 = F_32 ;
V_89 -> F_2 = F_33 ;
V_89 -> F_3 = F_34 ;
V_89 -> F_5 = F_36 ;
V_89 -> F_4 = F_35 ;
V_89 -> F_6 = F_37 ;
V_89 -> F_7 = F_38 ;
V_89 -> F_8 = F_39 ;
break;
case V_143 :
case V_144 :
V_89 -> F_1 = F_16 ;
V_89 -> F_2 = F_17 ;
V_89 -> F_3 = F_19 ;
V_89 -> F_5 = F_21 ;
V_89 -> F_4 = F_20 ;
V_89 -> F_6 = F_22 ;
V_89 -> F_7 = F_38 ;
V_89 -> F_8 = F_39 ;
break;
case V_145 :
case V_146 :
V_89 -> F_1 = F_23 ;
V_89 -> F_2 = F_24 ;
V_89 -> F_3 = F_25 ;
V_89 -> F_5 = F_27 ;
V_89 -> F_4 = F_26 ;
V_89 -> F_6 = F_28 ;
V_89 -> F_7 = F_29 ;
V_89 -> F_8 = F_31 ;
break;
default:
break;
}
switch ( V_89 -> type ) {
case V_143 :
case V_144 :
case V_146 :
V_89 -> V_147 = 0xf000 ;
break;
case V_145 :
V_97 = F_18 ( ( int ) V_89 -> V_8 ) ;
if ( ( V_97 & 0x1 ) == 0x1 ) {
if ( ( V_97 & 0x30 ) == 0 )
V_89 -> V_147 = 0xf000 ;
if ( ( V_97 & 0x30 ) == 0x10 )
V_89 -> V_147 = 0xe000 ;
if ( ( V_97 & 0x30 ) == 0x20 )
V_89 -> V_147 = 0xc000 ;
if ( ( V_97 & 0x30 ) == 0x30 )
V_89 -> V_147 = 0x8000 ;
} else
F_44 ( V_22 L_15 , ( int ) V_89 -> V_8 ) ;
break;
}
}
V_98 = F_91 ( V_91 ) ;
if ( V_98 ) {
F_44 ( V_22 L_16 ) ;
goto V_148;
}
V_98 = F_91 ( V_92 ) ;
if ( V_98 ) {
F_44 ( V_22 L_17 ) ;
goto V_149;
}
F_92 ( & V_90 ) ;
V_90 . V_150 = V_151 ;
F_93 ( & V_90 , V_152 + V_153 / 25 ) ;
return 0 ;
V_149:
F_81 ( V_91 ) ;
V_148:
F_82 ( V_92 ) ;
V_104:
F_82 ( V_91 ) ;
V_103:
return V_98 ;
}
static void F_94 ( unsigned int V_88 )
{
int V_154 ;
void T_1 * V_155 ;
struct V_156 T_1 * V_157 ;
struct V_1 * V_89 ;
struct V_27 T_1 * V_28 ;
struct V_4 * V_5 ;
int V_158 = 0 , V_159 ;
V_89 = & V_80 [ V_88 ] ;
if ( V_89 -> type >= V_140 ) {
V_89 -> V_95 = F_59 ( V_89 -> V_160 + V_161 ) ;
F_30 ( V_89 -> V_95 <= 64 , L_18 ) ;
V_16 += ( V_89 -> V_95 ) ;
} else {
V_89 -> V_160 = F_95 ( V_89 -> V_162 , 0x10000 ) ;
}
if ( V_88 != 0 )
V_94 [ V_88 ] = V_94 [ V_88 - 1 ] + V_80 [ V_88 - 1 ] . V_95 ;
else
V_94 [ V_88 ] = & V_15 [ V_88 ] ;
V_5 = V_94 [ V_88 ] ;
F_30 ( V_5 <= & V_15 [ V_16 - 1 ] , L_19 ) ;
V_155 = V_89 -> V_160 ;
V_28 = V_155 + V_163 ;
V_157 = V_155 + V_164 ;
if ( ( V_89 -> type == V_144 || V_89 -> type == V_143 ) &&
( F_59 ( V_155 + V_165 ) < 3 ) )
V_158 = 1 ;
if ( V_89 -> type < V_140 )
if ( ! F_96 ( ( int ) V_89 -> V_8 , 4 , V_166 [ V_89 -> type ] ) )
return;
F_1 ( V_89 , 0 ) ;
for ( V_154 = 0 ; V_154 < V_89 -> V_95 ; V_154 ++ , V_5 ++ , V_28 ++ ) {
unsigned long V_26 ;
T_4 V_167 , V_168 ;
F_97 ( & V_5 -> V_8 ) ;
V_5 -> V_8 . V_169 = & V_170 ;
V_5 -> V_31 = V_28 ;
V_5 -> V_58 = V_157 ;
F_98 ( & V_5 -> V_20 , V_171 ) ;
V_5 -> V_6 = & V_80 [ V_88 ] ;
F_51 ( & V_30 , V_26 ) ;
switch ( V_89 -> type ) {
case V_139 :
case V_138 :
case V_140 :
case V_141 :
case V_142 :
V_5 -> V_37 = 0x02 ;
V_5 -> V_172 = 0x80 ;
V_5 -> V_173 = 0x20 ;
V_5 -> V_174 = 0x10 ;
V_5 -> V_175 = 0x40 ;
V_5 -> V_38 = 0x01 ;
break;
case V_143 :
case V_144 :
case V_145 :
case V_146 :
V_5 -> V_37 = 0x02 ;
V_5 -> V_172 = 0x08 ;
V_5 -> V_173 = 0x10 ;
V_5 -> V_174 = 0x20 ;
V_5 -> V_175 = 0x40 ;
V_5 -> V_38 = 0x80 ;
break;
}
if ( V_80 [ V_88 ] . V_176 ) {
V_5 -> V_177 = V_5 -> V_172 ;
V_5 -> V_65 = V_5 -> V_173 ;
V_5 -> V_178 . V_179 |= V_180 ;
} else {
V_5 -> V_65 = V_5 -> V_172 ;
V_5 -> V_177 = V_5 -> V_173 ;
}
V_5 -> V_68 = V_88 ;
V_5 -> V_181 = V_154 ;
V_5 -> V_17 = V_18 ;
F_50 ( & V_5 -> V_8 , NULL ) ;
if ( V_158 ) {
F_53 ( V_5 , V_182 , 32 , 0 , 0 , 0 ) ;
V_158 = 0 ;
}
V_167 = F_59 ( & V_28 -> V_167 ) ;
V_168 = F_59 ( & V_28 -> V_168 ) ;
switch ( V_89 -> type ) {
case V_140 :
case V_141 :
case V_142 :
V_5 -> V_51 = V_155 + ( ( V_167 << 4 ) & 0x1fffff ) ;
V_5 -> V_183 = V_155 + ( ( V_168 << 4 ) & 0x1fffff ) ;
V_5 -> V_10 = V_7 | ( V_167 >> 11 ) ;
V_5 -> V_9 = V_7 | ( V_168 >> 11 ) ;
break;
case V_138 :
case V_139 :
V_5 -> V_51 = V_155 + ( ( V_167 << 4 ) & 0x7fff ) ;
V_5 -> V_183 = V_155 + ( ( V_168 << 4 ) & 0x7fff ) ;
V_5 -> V_10 = V_7 | ( V_167 >> 11 ) ;
V_5 -> V_9 = V_7 | ( V_168 >> 11 ) ;
break;
case V_144 :
case V_143 :
V_5 -> V_51 = V_155 + ( ( ( V_167 - V_89 -> V_147 ) << 4 )
& 0x1fff ) ;
V_5 -> V_10 = V_7 | ( ( V_167 - V_89 -> V_147 ) >> 9 ) ;
V_5 -> V_183 = V_155 + ( ( ( V_168 - V_89 -> V_147 ) << 4 )
& 0x1fff ) ;
V_5 -> V_9 = V_7 | ( ( V_168 - V_89 -> V_147 ) >> 9 ) ;
break;
case V_145 :
case V_146 :
V_5 -> V_51 = V_155 + ( ( V_167 - V_89 -> V_147 ) << 4 ) ;
V_5 -> V_183 = V_155 + ( ( V_168 - V_89 -> V_147 ) << 4 ) ;
V_5 -> V_10 = V_5 -> V_9 = 0 ;
break;
}
V_5 -> V_184 = 0 ;
V_5 -> V_48 = F_59 ( & V_28 -> V_185 ) + 1 ;
V_5 -> V_186 = 0 ;
V_5 -> V_187 = F_59 ( & V_28 -> V_188 ) + 1 ;
V_159 = V_5 -> V_48 >= 2000 ? 1024 : ( V_5 -> V_48 / 2 ) ;
F_53 ( V_5 , V_189 , V_159 , 0 , 10 , 0 ) ;
F_53 ( V_5 , V_190 , ( V_5 -> V_187 / 4 ) , 0 , 10 , 0 ) ;
F_53 ( V_5 , V_191 , ( 3 * V_5 -> V_187 / 4 ) , 0 , 10 , 0 ) ;
F_62 ( 100 , & V_28 -> V_192 ) ;
F_52 ( 1 , & V_28 -> V_32 ) ;
V_5 -> V_193 = F_65 ( & V_28 -> V_193 ) ;
V_5 -> V_194 = F_65 ( & V_28 -> V_194 ) ;
V_5 -> V_195 = F_65 ( & V_28 -> V_195 ) ;
V_5 -> V_196 = F_65 ( & V_28 -> V_196 ) ;
V_5 -> V_197 = 0 ;
V_5 -> V_198 = 0 ;
V_5 -> V_199 = 0 ;
V_5 -> V_200 = 0 ;
V_5 -> V_201 = 0 ;
V_5 -> V_202 = 0 ;
V_5 -> V_203 = 0 ;
V_5 -> V_8 . V_204 = 50 ;
F_54 ( & V_30 , V_26 ) ;
}
F_44 ( V_109
L_20 ,
V_110 , V_166 [ V_89 -> type ] , ( long ) V_89 -> V_8 ,
( long ) V_89 -> V_162 , V_89 -> V_95 ) ;
F_2 ( V_89 , 0 ) ;
}
static void V_151 ( unsigned long V_205 )
{
unsigned long V_26 ;
int V_88 ;
unsigned int V_42 , V_43 ;
struct V_4 * V_5 ;
struct V_1 * V_89 ;
for ( V_88 = 0 ; V_88 < V_79 ; V_88 ++ ) {
V_89 = & V_80 [ V_88 ] ;
V_5 = V_94 [ V_88 ] ;
if ( ( V_89 -> V_81 == V_82 ) || V_206 )
continue;
F_51 ( & V_30 , V_26 ) ;
F_8 ( V_5 ) ;
F_3 ( V_5 ) ;
V_42 = F_59 ( & V_5 -> V_58 -> V_207 ) ;
V_43 = F_59 ( & V_5 -> V_58 -> V_208 ) ;
if ( V_42 != V_43 )
F_99 ( V_88 ) ;
F_6 ( V_5 ) ;
F_54 ( & V_30 , V_26 ) ;
}
F_93 ( & V_90 , V_152 + ( V_153 / 25 ) ) ;
}
static void F_99 ( int V_88 )
{
void T_1 * V_209 ;
struct V_4 * V_5 , * V_210 ;
static struct V_12 * V_13 ;
struct V_1 * V_89 ;
struct V_27 T_1 * V_28 ;
unsigned int V_43 , V_42 ;
int V_19 , V_4 ;
int V_85 , V_211 ;
V_89 = & V_80 [ V_88 ] ;
V_210 = V_94 [ V_88 ] ;
F_30 ( V_210 <= & V_15 [ V_16 - 1 ] , L_19 ) ;
F_7 ( V_210 ) ;
while ( ( V_43 = F_59 ( & V_210 -> V_58 -> V_208 ) ) !=
( V_42 = F_59 ( & V_210 -> V_58 -> V_207 ) ) ) {
F_7 ( V_210 ) ;
V_209 = V_89 -> V_160 + V_43 + V_212 ;
V_4 = F_65 ( V_209 ) ;
V_19 = F_65 ( V_209 + 1 ) ;
V_85 = F_65 ( V_209 + 2 ) ;
V_211 = F_65 ( V_209 + 3 ) ;
V_5 = V_210 + V_4 ;
if ( ( unsigned ) V_4 >= V_89 -> V_95 || ! V_5 ) {
if ( V_4 >= V_89 -> V_95 )
V_5 = V_210 ;
V_28 = V_5 -> V_31 ;
goto V_213;
}
V_28 = V_5 -> V_31 ;
if ( V_28 == NULL )
goto V_213;
V_13 = F_83 ( & V_5 -> V_8 ) ;
if ( V_19 & V_214 ) {
F_100 ( V_5 , V_13 ) ;
F_7 ( V_5 ) ;
}
if ( V_19 & V_215 ) {
V_5 -> V_64 = V_85 ;
if ( F_101 ( V_216 , & V_5 -> V_8 . V_26 ) ) {
if ( V_85 & V_5 -> V_65 )
F_102 ( & V_5 -> V_8 . V_217 ) ;
else
F_41 ( V_5 , V_218 ) ;
}
}
if ( V_13 ) {
if ( V_19 & V_219 ) {
F_103 ( V_13 , 0 , V_220 ) ;
F_104 ( V_13 ) ;
} else if ( V_19 & V_221 ) {
if ( V_5 -> V_52 & V_54 ) {
V_5 -> V_52 &= ~ V_54 ;
F_67 ( V_13 ) ;
}
} else if ( V_19 & V_222 ) {
V_5 -> V_52 &= ~ V_53 ;
if ( V_5 -> V_52 & V_62 ) {
V_5 -> V_52 &= ~ V_62 ;
F_67 ( V_13 ) ;
}
}
F_85 ( V_13 ) ;
}
V_213:
F_3 ( V_5 ) ;
F_105 ( ! V_28 ) ;
F_62 ( 1 , & V_28 -> V_32 ) ;
F_62 ( ( V_43 + 4 ) & ( V_223 - V_212 - 4 ) , & V_210 -> V_58 -> V_208 ) ;
F_3 ( V_210 ) ;
}
}
static void F_53 ( struct V_4 * V_5 , int V_224 , int V_225 ,
int V_226 , int V_227 , int V_228 )
{
T_5 T_1 * V_155 ;
unsigned int V_42 , V_229 , V_230 , V_231 ;
long V_84 ;
int V_232 ;
if ( V_5 -> V_6 -> V_81 == V_82 )
return;
F_7 ( V_5 ) ;
V_42 = F_59 ( & V_5 -> V_58 -> V_60 ) ;
V_230 = F_59 ( & V_5 -> V_58 -> V_233 ) ;
V_231 = ( V_230 + 4 + F_59 ( & V_5 -> V_58 -> V_234 ) ) ;
V_155 = V_5 -> V_6 -> V_160 ;
if ( V_42 >= ( V_231 - V_230 ) || ( V_42 & 03 ) ) {
F_44 ( V_22 L_21 ,
__LINE__ , V_224 , V_42 ) ;
F_44 ( V_22 L_22 ,
__LINE__ , V_231 , V_230 ) ;
return;
}
if ( V_228 ) {
F_52 ( V_224 , V_155 + V_42 + V_230 + 0 ) ;
F_52 ( V_5 -> V_181 , V_155 + V_42 + V_230 + 1 ) ;
F_52 ( V_225 , V_155 + V_42 + V_230 + 2 ) ;
F_52 ( V_226 , V_155 + V_42 + V_230 + 3 ) ;
} else {
F_52 ( V_224 , V_155 + V_42 + V_230 + 0 ) ;
F_52 ( V_5 -> V_181 , V_155 + V_42 + V_230 + 1 ) ;
F_52 ( V_225 , V_155 + V_42 + V_230 + 2 ) ;
}
V_42 = ( V_42 + 4 ) & ( V_231 - V_230 - 4 ) ;
F_62 ( V_42 , & V_5 -> V_58 -> V_60 ) ;
V_84 = V_235 ;
for (; ; ) {
V_84 -- ;
if ( V_84 == 0 ) {
F_44 ( V_22 L_23 ) ;
return;
}
V_42 = F_59 ( & V_5 -> V_58 -> V_60 ) ;
V_229 = F_59 ( & V_5 -> V_58 -> V_59 ) ;
V_232 = ( V_42 - V_229 ) & ( V_231 - V_230 - 4 ) ;
if ( V_232 <= V_227 * ( sizeof( short ) * 4 ) )
break;
}
}
static unsigned F_106 ( struct V_4 * V_5 , unsigned V_236 )
{
unsigned V_237 = 0 ;
if ( V_236 & V_238 ) {
V_5 -> V_178 . V_179 |= ( V_239 | V_240 ) ;
V_237 |= ( ( V_5 -> V_174 ) | ( V_5 -> V_37 ) ) ;
}
if ( V_5 -> V_178 . V_179 & V_239 )
V_237 |= V_5 -> V_37 ;
if ( V_5 -> V_178 . V_179 & V_241 )
V_237 |= V_5 -> V_38 ;
if ( V_5 -> V_178 . V_179 & V_240 )
V_237 |= V_5 -> V_174 ;
if ( V_5 -> V_178 . V_179 & V_242 )
V_237 |= V_5 -> V_177 ;
if ( V_5 -> V_178 . V_179 & V_243 )
V_237 |= V_5 -> V_65 ;
if ( V_237 & ( V_5 -> V_37 ) )
V_5 -> V_178 . V_179 |= V_239 ;
if ( V_237 & ( V_5 -> V_174 ) )
V_5 -> V_178 . V_179 |= V_240 ;
return V_237 ;
}
static unsigned F_107 ( struct V_4 * V_5 , unsigned V_244 )
{
unsigned V_237 = V_244 & ( V_245 | V_246 | V_247 | V_248 |
V_249 | V_250 | V_251 | V_252 | V_253 ) ;
if ( V_5 -> V_178 . V_179 & V_254 )
V_237 |= V_255 ;
return V_237 ;
}
static unsigned F_108 ( struct V_4 * V_5 , unsigned V_236 )
{
unsigned V_237 = 0 ;
if ( V_236 & V_256 ) {
V_5 -> V_178 . V_179 |= V_257 ;
V_237 |= V_258 ;
} else
V_5 -> V_178 . V_179 &= ~ V_257 ;
V_237 |= V_236 & ( ( V_259 ^ V_256 ) | V_260 | V_261 | V_262 | V_263 ) ;
if ( V_236 & V_256 ) {
if ( ( ! ( ( V_236 & 0x7 ) ^ ( V_264 & ~ V_256 ) ) ) ||
( ! ( ( V_236 & 0x7 ) ^ ( V_265 & ~ V_256 ) ) ) )
V_237 += 1 ;
}
return V_237 ;
}
static void F_74 ( struct V_12 * V_13 , struct V_4 * V_5 )
{
unsigned int V_266 ;
struct V_267 * V_268 ;
struct V_27 T_1 * V_28 ;
unsigned V_269 , V_270 , V_236 , V_244 ;
V_28 = V_5 -> V_31 ;
F_30 ( V_28 != NULL , L_24 ) ;
F_7 ( V_5 ) ;
V_268 = V_13 -> V_33 ;
if ( ( V_268 -> V_34 & V_259 ) == 0 ) {
V_266 = F_59 ( & V_28 -> V_86 ) ;
F_62 ( V_266 , & V_28 -> V_87 ) ;
V_266 = F_59 ( & V_28 -> V_49 ) ;
F_53 ( V_5 , V_63 , ( unsigned ) V_266 , 0 , 0 , 0 ) ;
V_269 = 0 ;
} else {
V_236 = F_108 ( V_5 , V_268 -> V_34 ) ;
if ( V_236 != V_5 -> V_197 ) {
V_5 -> V_197 = V_236 ;
F_53 ( V_5 , V_271 , ( unsigned ) V_236 , 0 , 0 , 0 ) ;
}
if ( V_268 -> V_34 & V_128 )
F_109 ( V_216 , & V_5 -> V_8 . V_26 ) ;
else
F_110 ( V_216 , & V_5 -> V_8 . V_26 ) ;
V_269 = V_5 -> V_38 | V_5 -> V_37 ;
}
V_244 = F_107 ( V_5 , V_268 -> V_123 ) ;
if ( V_244 != V_5 -> V_198 ) {
V_5 -> V_198 = V_244 ;
F_53 ( V_5 , V_272 , ( unsigned int ) V_5 -> V_198 , 0 , 0 , 0 ) ;
}
F_52 ( V_5 -> V_65 , & V_28 -> V_273 ) ;
if ( ( V_268 -> V_34 & V_128 ) || ( V_5 -> V_178 . V_179 & V_274 ) )
if ( V_5 -> V_178 . V_179 & V_274 )
F_52 ( 0 , & V_28 -> V_273 ) ;
V_5 -> V_64 = F_65 ( & V_28 -> V_85 ) ;
V_270 = F_106 ( V_5 , V_268 -> V_34 ) ;
if ( V_270 != V_5 -> V_270 ) {
V_5 -> V_270 = V_270 ;
F_53 ( V_5 , V_275 , V_270 , 0xff , 0 , 1 ) ;
}
V_269 ^= V_5 -> V_276 & ( V_269 ^ V_5 -> V_277 ) ;
if ( V_5 -> V_36 ^ V_269 ) {
V_5 -> V_36 = V_269 ;
F_53 ( V_5 , V_39 , 0 , ( ( V_5 -> V_38 ) | ( V_5 -> V_37 ) ) , 0 , 1 ) ;
F_53 ( V_5 , V_39 , V_269 , 0 , 0 , 1 ) ;
}
if ( V_5 -> V_193 != V_5 -> V_200 || V_5 -> V_194 != V_5 -> V_201 ) {
V_5 -> V_200 = V_5 -> V_193 ;
V_5 -> V_201 = V_5 -> V_194 ;
F_53 ( V_5 , V_278 , V_5 -> V_200 , V_5 -> V_201 , 0 , 1 ) ;
}
if ( V_5 -> V_195 != V_5 -> V_202 || V_5 -> V_196 != V_5 -> V_203 ) {
V_5 -> V_202 = V_5 -> V_195 ;
V_5 -> V_203 = V_5 -> V_196 ;
F_53 ( V_5 , V_279 , V_5 -> V_202 , V_5 -> V_203 , 0 , 1 ) ;
}
}
static void F_100 ( struct V_4 * V_5 , struct V_12 * V_13 )
{
T_5 * V_280 ;
struct V_267 * V_268 = NULL ;
struct V_27 T_1 * V_28 ;
int V_281 , V_282 , V_41 ;
unsigned int V_43 , V_42 ;
unsigned int V_283 ;
F_3 ( V_5 ) ;
if ( V_5 -> V_52 & V_284 )
return;
if ( V_13 )
V_268 = V_13 -> V_33 ;
V_28 = V_5 -> V_31 ;
F_105 ( ! V_28 ) ;
V_283 = V_5 -> V_187 - 1 ;
V_42 = F_59 ( & V_28 -> V_86 ) ;
V_42 &= V_283 ;
V_43 = F_59 ( & V_28 -> V_87 ) & V_283 ;
V_41 = ( V_42 - V_43 ) & V_283 ;
if ( V_41 == 0 )
return;
if ( ! V_13 || ! V_268 || ! ( V_268 -> V_34 & V_127 ) ) {
F_62 ( V_42 , & V_28 -> V_87 ) ;
return;
}
if ( F_111 ( V_13 , V_41 + 1 ) == 0 )
return;
if ( F_65 ( & V_28 -> V_285 ) ) {
F_52 ( 0 , & V_28 -> V_285 ) ;
F_44 ( V_93 L_25 ,
V_13 -> V_114 ) ;
F_103 ( V_13 , 0 , V_286 ) ;
}
F_4 ( V_5 ) ;
while ( V_41 > 0 ) {
V_282 = ( V_42 >= V_43 ) ? V_42 - V_43 : V_5 -> V_187 - V_43 ;
V_281 = ( V_282 < V_41 ) ? V_282
: V_41 ;
V_281 = F_112 ( V_13 , & V_280 , V_281 ) ;
if ( V_281 == 0 )
break;
F_113 ( V_280 , V_5 -> V_183 + V_43 , V_281 ) ;
V_43 = ( V_43 + V_281 ) & V_283 ;
V_41 -= V_281 ;
}
F_3 ( V_5 ) ;
F_62 ( V_43 , & V_28 -> V_87 ) ;
F_104 ( V_13 ) ;
}
static int F_114 ( struct V_12 * V_13 ,
unsigned int V_224 , unsigned long V_287 )
{
switch ( V_224 ) {
case V_288 :
{
struct V_289 V_290 ;
int V_291 ;
if ( F_115 ( V_291 , ( unsigned int V_292 * ) V_287 ) )
return - V_293 ;
if ( V_291 < 0 || V_291 >= V_79 || V_79 == 0 )
return - V_70 ;
memset ( & V_290 , 0 , sizeof( V_290 ) ) ;
V_290 . V_6 = V_291 ;
V_290 . V_81 = V_80 [ V_291 ] . V_81 ;
V_290 . type = V_80 [ V_291 ] . type ;
V_290 . V_95 = V_80 [ V_291 ] . V_95 ;
V_290 . V_8 = ( unsigned char * ) V_80 [ V_291 ] . V_8 ;
V_290 . V_162 = ( unsigned char * ) V_80 [ V_291 ] . V_162 ;
if ( F_116 ( ( void V_292 * ) V_287 , & V_290 , sizeof( V_290 ) ) )
return - V_293 ;
break;
}
case V_294 :
{
int V_291 = V_287 & 0xff000000 >> 16 ;
unsigned char V_295 = V_287 & 0xff ;
if ( V_291 < 0 || V_291 >= V_79 ) {
F_44 ( V_22 L_26 ) ;
return - V_70 ;
}
V_206 = V_295 ;
break;
}
case V_296 :
{
int V_88 ;
for ( V_88 = 0 ; V_88 < V_79 ; V_88 ++ )
F_94 ( V_88 ) ;
break;
}
default:
return - V_297 ;
}
return 0 ;
}
static int F_117 ( struct V_12 * V_13 )
{
struct V_4 * V_5 = V_13 -> V_14 ;
struct V_27 T_1 * V_28 ;
unsigned int V_85 , V_298 = 0 ;
unsigned long V_26 ;
if ( V_5 )
V_28 = V_5 -> V_31 ;
else
return - V_299 ;
F_51 ( & V_30 , V_26 ) ;
F_3 ( V_5 ) ;
V_85 = F_65 ( & V_28 -> V_85 ) ;
F_6 ( V_5 ) ;
F_54 ( & V_30 , V_26 ) ;
if ( V_85 & V_5 -> V_38 )
V_298 |= V_300 ;
if ( V_85 & V_5 -> V_37 )
V_298 |= V_301 ;
if ( V_85 & V_5 -> V_174 )
V_298 |= V_302 ;
if ( V_85 & V_5 -> V_177 )
V_298 |= V_303 ;
if ( V_85 & V_5 -> V_175 )
V_298 |= V_304 ;
if ( V_85 & V_5 -> V_65 )
V_298 |= V_305 ;
return V_298 ;
}
static int F_118 ( struct V_12 * V_13 ,
unsigned int V_306 , unsigned int V_307 )
{
struct V_4 * V_5 = V_13 -> V_14 ;
unsigned long V_26 ;
if ( ! V_5 )
return - V_299 ;
F_51 ( & V_30 , V_26 ) ;
if ( V_306 & V_301 ) {
V_5 -> V_276 |= V_5 -> V_37 ;
V_5 -> V_277 |= V_5 -> V_37 ;
}
if ( V_306 & V_300 ) {
V_5 -> V_276 |= V_5 -> V_38 ;
V_5 -> V_277 |= V_5 -> V_38 ;
}
if ( V_307 & V_301 ) {
V_5 -> V_276 |= V_5 -> V_37 ;
V_5 -> V_277 &= ~ V_5 -> V_37 ;
}
if ( V_307 & V_300 ) {
V_5 -> V_276 |= V_5 -> V_38 ;
V_5 -> V_277 &= ~ V_5 -> V_38 ;
}
F_3 ( V_5 ) ;
F_74 ( V_13 , V_5 ) ;
F_6 ( V_5 ) ;
F_54 ( & V_30 , V_26 ) ;
return 0 ;
}
static int F_119 ( struct V_12 * V_13 ,
unsigned int V_224 , unsigned long V_287 )
{
T_6 V_308 ;
unsigned long V_26 ;
unsigned int V_298 , V_85 ;
unsigned char V_193 , V_194 ;
struct V_27 T_1 * V_28 ;
struct V_4 * V_5 = V_13 -> V_14 ;
void V_292 * V_309 = ( void V_292 * ) V_287 ;
if ( V_5 )
V_28 = V_5 -> V_31 ;
else
return - V_299 ;
switch ( V_224 ) {
case V_310 :
V_298 = F_117 ( V_13 ) ;
if ( F_120 ( V_298 , ( unsigned long V_292 * ) V_309 ) )
return - V_293 ;
break;
case V_311 :
if ( F_115 ( V_85 , ( unsigned V_292 * ) V_309 ) )
return - V_293 ;
return F_118 ( V_13 , V_85 , ~ V_85 ) ;
case V_312 :
F_51 ( & V_30 , V_26 ) ;
V_5 -> V_36 |= V_5 -> V_38 ;
F_3 ( V_5 ) ;
F_53 ( V_5 , V_39 , V_5 -> V_38 , 0 , 10 , 1 ) ;
F_6 ( V_5 ) ;
F_54 ( & V_30 , V_26 ) ;
break;
case V_313 :
F_51 ( & V_30 , V_26 ) ;
V_5 -> V_36 &= ~ V_5 -> V_38 ;
F_3 ( V_5 ) ;
F_53 ( V_5 , V_39 , 0 , V_5 -> V_38 , 10 , 1 ) ;
F_6 ( V_5 ) ;
F_54 ( & V_30 , V_26 ) ;
break;
case V_314 :
if ( F_116 ( V_309 , & V_5 -> V_178 , sizeof( V_315 ) ) )
return - V_293 ;
break;
case V_316 :
case V_317 :
if ( V_224 == V_316 ) {
F_51 ( & V_30 , V_26 ) ;
F_66 ( V_13 , V_5 ) ;
F_54 ( & V_30 , V_26 ) ;
F_121 ( V_13 , 0 ) ;
} else {
if ( V_13 -> V_318 -> V_169 -> V_319 )
V_13 -> V_318 -> V_169 -> V_319 ( V_13 ) ;
}
case V_320 :
if ( F_122 ( & V_5 -> V_178 , V_309 , sizeof( V_315 ) ) )
return - V_293 ;
if ( V_5 -> V_178 . V_179 & V_180 ) {
V_5 -> V_65 = V_5 -> V_173 ;
V_5 -> V_177 = V_5 -> V_172 ;
} else {
V_5 -> V_65 = V_5 -> V_172 ;
V_5 -> V_177 = V_5 -> V_173 ;
}
F_51 ( & V_30 , V_26 ) ;
F_3 ( V_5 ) ;
F_74 ( V_13 , V_5 ) ;
F_6 ( V_5 ) ;
F_54 ( & V_30 , V_26 ) ;
break;
case V_321 :
case V_322 :
F_51 ( & V_30 , V_26 ) ;
F_3 ( V_5 ) ;
if ( V_224 == V_321 ) {
V_308 . V_193 = F_65 ( & V_28 -> V_193 ) ;
V_308 . V_194 = F_65 ( & V_28 -> V_194 ) ;
} else {
V_308 . V_193 = F_65 ( & V_28 -> V_195 ) ;
V_308 . V_194 = F_65 ( & V_28 -> V_196 ) ;
}
F_6 ( V_5 ) ;
F_54 ( & V_30 , V_26 ) ;
if ( F_116 ( V_309 , & V_308 , sizeof( V_308 ) ) )
return - V_293 ;
break;
case V_323 :
case V_324 :
if ( V_224 == V_324 ) {
V_193 = V_5 -> V_193 ;
V_194 = V_5 -> V_194 ;
} else {
V_193 = V_5 -> V_195 ;
V_194 = V_5 -> V_196 ;
}
if ( F_122 ( & V_308 , V_309 , sizeof( V_308 ) ) )
return - V_293 ;
if ( V_308 . V_193 != V_193 || V_308 . V_194 != V_194 ) {
F_51 ( & V_30 , V_26 ) ;
F_3 ( V_5 ) ;
if ( V_224 == V_324 ) {
V_5 -> V_200 = V_5 -> V_193 = V_308 . V_193 ;
V_5 -> V_201 = V_5 -> V_194 = V_308 . V_194 ;
F_53 ( V_5 , V_278 , V_5 -> V_200 ,
V_5 -> V_201 , 0 , 1 ) ;
} else {
V_5 -> V_202 = V_5 -> V_195 = V_308 . V_193 ;
V_5 -> V_203 = V_5 -> V_196 = V_308 . V_194 ;
F_53 ( V_5 , V_279 , V_5 -> V_202 ,
V_5 -> V_203 , 0 , 1 ) ;
}
if ( V_5 -> V_52 & V_325 )
F_123 ( V_13 ) ;
F_6 ( V_5 ) ;
F_54 ( & V_30 , V_26 ) ;
}
break;
default:
return - V_326 ;
}
return 0 ;
}
static void F_124 ( struct V_12 * V_13 , struct V_267 * V_327 )
{
struct V_4 * V_5 ;
unsigned long V_26 ;
V_5 = F_40 ( V_13 ) ;
if ( V_5 != NULL ) {
F_51 ( & V_30 , V_26 ) ;
F_3 ( V_5 ) ;
F_74 ( V_13 , V_5 ) ;
F_6 ( V_5 ) ;
F_54 ( & V_30 , V_26 ) ;
if ( ( V_327 -> V_34 & V_238 ) &&
( ( V_13 -> V_33 -> V_34 & V_238 ) == 0 ) )
V_13 -> V_328 = 0 ;
if ( ! ( V_327 -> V_34 & V_128 ) &&
( V_13 -> V_33 -> V_34 & V_128 ) )
F_102 ( & V_5 -> V_8 . V_217 ) ;
}
}
static void V_171 ( struct V_329 * V_330 )
{
struct V_4 * V_5 = F_70 ( V_330 , struct V_4 , V_20 ) ;
if ( V_5 && V_5 -> V_17 == V_18 ) {
struct V_12 * V_13 = F_83 ( & V_5 -> V_8 ) ;
if ( V_13 && V_13 -> V_14 ) {
if ( F_125 ( V_218 , & V_5 -> V_19 ) ) {
F_84 ( V_13 ) ;
F_102 ( & V_5 -> V_8 . V_217 ) ;
F_109 ( V_331 ,
& V_5 -> V_8 . V_26 ) ;
}
}
F_85 ( V_13 ) ;
}
}
static void F_126 ( struct V_12 * V_13 )
{
struct V_4 * V_5 ;
unsigned long V_26 ;
V_5 = F_40 ( V_13 ) ;
if ( V_5 != NULL ) {
F_51 ( & V_30 , V_26 ) ;
if ( ( V_5 -> V_52 & V_325 ) == 0 ) {
F_3 ( V_5 ) ;
F_53 ( V_5 , V_332 , 0 , 0 , 0 , 0 ) ;
V_5 -> V_52 |= V_325 ;
F_6 ( V_5 ) ;
}
F_54 ( & V_30 , V_26 ) ;
}
}
static void F_123 ( struct V_12 * V_13 )
{
struct V_4 * V_5 ;
V_5 = F_40 ( V_13 ) ;
if ( V_5 != NULL ) {
unsigned long V_26 ;
F_51 ( & V_30 , V_26 ) ;
if ( V_5 -> V_52 & V_325 ) {
struct V_27 T_1 * V_28 ;
F_3 ( V_5 ) ;
V_28 = V_5 -> V_31 ;
if ( V_5 -> V_52 & V_54 )
F_52 ( 1 , & V_28 -> V_55 ) ;
F_53 ( V_5 , V_333 , 0 , 0 , 0 , 0 ) ;
V_5 -> V_52 &= ~ V_325 ;
F_6 ( V_5 ) ;
}
F_54 ( & V_30 , V_26 ) ;
}
}
static void F_127 ( struct V_12 * V_13 )
{
struct V_4 * V_5 ;
unsigned long V_26 ;
V_5 = F_40 ( V_13 ) ;
if ( V_5 != NULL ) {
F_51 ( & V_30 , V_26 ) ;
if ( ( V_5 -> V_52 & V_284 ) == 0 ) {
F_3 ( V_5 ) ;
F_53 ( V_5 , V_334 , 0 , 0 , 0 , 0 ) ;
V_5 -> V_52 |= V_284 ;
F_6 ( V_5 ) ;
}
F_54 ( & V_30 , V_26 ) ;
}
}
static void F_128 ( struct V_12 * V_13 )
{
struct V_4 * V_5 ;
unsigned long V_26 ;
V_5 = F_40 ( V_13 ) ;
if ( V_5 != NULL ) {
F_51 ( & V_30 , V_26 ) ;
if ( V_5 -> V_52 & V_284 ) {
F_3 ( V_5 ) ;
F_53 ( V_5 , V_335 , 0 , 0 , 0 , 0 ) ;
V_5 -> V_52 &= ~ V_284 ;
F_6 ( V_5 ) ;
}
F_54 ( & V_30 , V_26 ) ;
}
}
static int F_129 ( struct V_12 * V_13 , int V_336 )
{
struct V_4 * V_5 = V_13 -> V_14 ;
unsigned long V_26 ;
if ( V_336 == - 1 )
V_336 = 0xFFFF ;
else if ( V_336 > 0xFFFE )
V_336 = 0xFFFE ;
else if ( V_336 < 1 )
V_336 = 1 ;
F_51 ( & V_30 , V_26 ) ;
F_3 ( V_5 ) ;
F_53 ( V_5 , V_337 , V_336 , 0 , 10 , 0 ) ;
F_6 ( V_5 ) ;
F_54 ( & V_30 , V_26 ) ;
return 0 ;
}
static void F_66 ( struct V_12 * V_13 , struct V_4 * V_5 )
{
struct V_27 T_1 * V_28 = V_5 -> V_31 ;
F_3 ( V_5 ) ;
V_5 -> V_52 |= V_62 ;
F_52 ( 1 , & V_28 -> V_338 ) ;
F_6 ( V_5 ) ;
}
static void T_2 F_130 ( char * V_339 , int * V_340 )
{
struct V_1 V_6 ;
int V_69 , V_341 , V_342 ;
char * V_343 , * V_344 ;
unsigned V_345 ;
if ( ! V_105 )
V_105 = 1 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
for ( V_342 = 0 , V_69 = 1 ; V_69 <= V_340 [ 0 ] ; V_69 ++ )
switch ( V_69 ) {
case 1 :
V_6 . V_81 = V_340 [ V_69 ] ;
if ( V_6 . V_81 == 2 ) {
V_16 = 0 ;
V_79 = 0 ;
return;
}
if ( V_6 . V_81 > 2 ) {
F_44 ( V_22 L_27 ,
V_6 . V_81 ) ;
V_71 = 1 ;
V_72 |= V_77 ;
return;
}
V_342 = V_69 ;
break;
case 2 :
V_6 . type = V_340 [ V_69 ] ;
if ( V_6 . type >= V_140 ) {
F_44 ( V_22 L_28 , V_6 . type ) ;
V_71 = 1 ;
V_72 |= V_73 ;
return;
}
V_342 = V_69 ;
break;
case 3 :
V_6 . V_176 = V_340 [ V_69 ] ;
if ( V_6 . V_176 > 1 ) {
F_44 ( V_22 L_29 , V_6 . V_176 ) ;
V_71 = 1 ;
V_72 |= V_78 ;
return;
}
V_342 = V_69 ;
break;
case 4 :
V_6 . V_95 = V_340 [ V_69 ] ;
if ( V_6 . V_95 < 2 || V_6 . V_95 > 256 ) {
F_44 ( V_22 L_30 , V_6 . V_95 ) ;
V_71 = 1 ;
V_72 |= V_74 ;
return;
}
V_16 += V_6 . V_95 ;
V_342 = V_69 ;
break;
case 5 :
V_6 . V_8 = V_340 [ V_69 ] ;
if ( V_340 [ V_69 ] <= 0 ) {
F_44 ( V_22 L_31 , ( unsigned int ) V_6 . V_8 ) ;
V_71 = 1 ;
V_72 |= V_76 ;
return;
}
V_342 = V_69 ;
break;
case 6 :
V_6 . V_162 = V_340 [ V_69 ] ;
if ( V_340 [ V_69 ] <= 0 ) {
F_44 ( V_22 L_32 ,
( unsigned int ) V_6 . V_162 ) ;
V_71 = 1 ;
V_72 |= V_75 ;
return;
}
V_342 = V_69 ;
break;
default:
F_44 ( V_22 L_33 ) ;
return;
}
while ( V_339 && * V_339 ) {
V_343 = V_339 ;
while ( * V_343 && ( * V_343 != ',' ) )
V_343 ++ ;
if ( ! * V_343 )
V_343 = NULL ;
else
* V_343 ++ = 0 ;
V_69 = V_342 + 1 ;
switch ( V_69 ) {
case 1 :
V_345 = strlen ( V_339 ) ;
if ( strncmp ( L_34 , V_339 , V_345 ) == 0 )
V_6 . V_81 = 0 ;
else if ( strncmp ( L_35 , V_339 , V_345 ) == 0 )
V_6 . V_81 = 1 ;
else {
F_44 ( V_22 L_36 , V_339 ) ;
V_71 = 1 ;
V_72 |= V_77 ;
return;
}
V_342 = V_69 ;
break;
case 2 :
for ( V_341 = 0 ; V_341 < V_346 ; V_341 ++ )
if ( strcmp ( V_166 [ V_341 ] , V_339 ) == 0 )
break;
if ( V_69 < V_346 )
V_6 . type = V_341 ;
else {
F_44 ( V_22 L_37 , V_339 ) ;
V_71 = 1 ;
V_72 |= V_73 ;
return;
}
V_342 = V_69 ;
break;
case 3 :
V_345 = strlen ( V_339 ) ;
if ( strncmp ( L_34 , V_339 , V_345 ) == 0 )
V_6 . V_176 = 0 ;
else if ( strncmp ( L_35 , V_339 , V_345 ) == 0 )
V_6 . V_176 = 1 ;
else {
F_44 ( V_22 L_38 , V_339 ) ;
V_71 = 1 ;
V_72 |= V_78 ;
return;
}
V_342 = V_69 ;
break;
case 4 :
V_344 = V_339 ;
while ( isdigit ( * V_344 ) )
V_344 ++ ;
if ( * V_344 ) {
F_44 ( V_22 L_39 , V_339 ) ;
V_71 = 1 ;
V_72 |= V_74 ;
return;
}
V_6 . V_95 = F_131 ( V_339 , NULL , 0 ) ;
V_16 += V_6 . V_95 ;
V_342 = V_69 ;
break;
case 5 :
V_344 = V_339 ;
while ( isxdigit ( * V_344 ) )
V_344 ++ ;
if ( * V_344 ) {
F_44 ( V_22 L_40 , V_339 ) ;
V_71 = 1 ;
V_72 |= V_76 ;
return;
}
V_6 . V_8 = F_131 ( V_339 , NULL , 16 ) ;
V_342 = V_69 ;
break;
case 6 :
V_344 = V_339 ;
while ( isxdigit ( * V_344 ) )
V_344 ++ ;
if ( * V_344 ) {
F_44 ( V_22 L_41 , V_339 ) ;
V_71 = 1 ;
V_72 |= V_75 ;
return;
}
V_6 . V_162 = F_131 ( V_339 , NULL , 16 ) ;
V_342 = V_69 ;
break;
default:
F_44 ( V_22 L_42 ) ;
return;
}
V_339 = V_343 ;
}
if ( V_342 < 6 ) {
F_44 ( V_22 L_43 ) ;
return;
}
memcpy ( ( void * ) & V_80 [ V_79 ] , ( void * ) & V_6 , sizeof( V_6 ) ) ;
F_44 ( V_109 L_44 ,
V_79 , V_166 [ V_6 . type ] ,
V_6 . V_95 , ( int ) V_6 . V_8 , ( unsigned int ) V_6 . V_162 ) ;
V_79 ++ ;
}
static int T_2 F_132 ( char * V_339 )
{
int V_340 [ 11 ] ;
F_130 ( F_133 ( V_339 , 11 , V_340 ) , V_340 ) ;
return 1 ;
}
static int T_7 F_134 ( struct V_347 * V_348 ,
const struct V_349 * V_350 )
{
static int V_351 = - 1 ;
int V_352 , V_353 = V_350 -> V_14 ;
unsigned long V_354 ;
if ( F_135 ( V_348 ) )
return - V_355 ;
V_351 ++ ;
V_352 = V_351 + V_79 ;
if ( V_352 >= V_111 )
goto V_356;
V_354 = F_136 ( V_348 , V_357 [ V_353 ] . V_358 ) ;
if ( ! V_354 ) {
F_44 (KERN_ERR PFX L_45 ,
epca_info_tbl[info_idx].bar_idx) ;
goto V_356;
}
V_80 [ V_352 ] . V_81 = V_359 ;
V_80 [ V_352 ] . type = V_357 [ V_353 ] . V_360 ;
V_80 [ V_352 ] . V_95 = 0x0 ;
V_80 [ V_352 ] . V_8 = V_354 + V_361 ;
V_80 [ V_352 ] . V_162 = V_354 ;
if ( ! F_137 ( V_354 + V_361 , 0x200000 , L_46 ) ) {
F_44 (KERN_ERR PFX L_47 ,
0x200000 , addr + PCI_IO_OFFSET) ;
goto V_356;
}
V_80 [ V_352 ] . V_362 = F_95 ( V_354 + V_361 ,
0x200000 ) ;
if ( ! V_80 [ V_352 ] . V_362 ) {
F_44 (KERN_ERR PFX L_48 ,
0x200000 , addr + PCI_IO_OFFSET) ;
goto V_363;
}
if ( ! F_137 ( V_354 , 0x200000 , L_46 ) ) {
F_44 (KERN_ERR PFX L_47 ,
0x200000 , addr) ;
goto V_364;
}
V_80 [ V_352 ] . V_160 = F_95 ( V_354 , 0x200000 ) ;
if ( ! V_80 [ V_352 ] . V_160 ) {
F_44 (KERN_ERR PFX L_48 ,
0x200000 , addr + PCI_IO_OFFSET) ;
goto V_365;
}
if ( V_353 != V_366 ) {
F_138 ( V_348 , 0x40 , 0 ) ;
F_138 ( V_348 , 0x46 , 0 ) ;
}
return 0 ;
V_365:
F_139 ( V_354 , 0x200000 ) ;
V_364:
F_140 ( V_80 [ V_352 ] . V_362 ) ;
V_363:
F_139 ( V_354 + V_361 , 0x200000 ) ;
V_356:
return - V_70 ;
}
static int T_2 F_89 ( void )
{
memset ( & V_96 , 0 , sizeof( V_96 ) ) ;
V_96 . V_114 = L_46 ;
V_96 . V_367 = V_368 ;
V_96 . V_369 = F_134 ;
return F_141 ( & V_96 ) ;
}
