static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
}
static unsigned int F_2 ( struct V_1 * V_2 )
{
return V_4 ;
}
static unsigned int F_3 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_4 ( V_2 -> V_6 + V_7 ) ;
V_5 &= ( V_8 | V_9 ) ;
return ( V_5 == V_8 ) ? V_10 : 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_4 ( V_2 -> V_6 + V_11 ) ;
V_5 &= ~ V_12 ;
F_6 ( V_5 , V_2 -> V_6 + V_11 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_4 ( V_2 -> V_6 + V_11 ) ;
V_5 &= ~ V_13 ;
F_6 ( V_5 , V_2 -> V_6 + V_11 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
unsigned long V_14 ;
T_1 V_5 ;
F_9 ( V_2 -> V_15 , V_2 ) ;
F_10 ( & V_2 -> V_16 , V_14 ) ;
V_5 = F_4 ( V_2 -> V_6 + V_11 ) ;
V_5 &= ~ V_13 ;
V_5 &= ~ ( V_17 | V_12 ) ;
F_6 ( V_5 , V_2 -> V_6 + V_11 ) ;
F_11 ( & V_2 -> V_16 , V_14 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = & V_2 -> V_20 -> V_19 ;
unsigned int V_21 ;
T_1 V_5 ;
if ( F_13 ( V_2 ) ) {
F_5 ( V_2 ) ;
return;
}
while ( ! ( F_4 ( V_2 -> V_6 + V_7 ) & V_22 ) ) {
if ( V_2 -> V_23 ) {
F_6 ( V_2 -> V_23 , V_2 -> V_6 + V_24 ) ;
V_2 -> V_25 . V_26 ++ ;
V_2 -> V_23 = 0 ;
continue;
}
if ( F_14 ( V_19 ) )
break;
V_21 = V_19 -> V_27 [ V_19 -> V_28 ] ;
F_6 ( V_21 , V_2 -> V_6 + V_24 ) ;
V_19 -> V_28 = ( V_19 -> V_28 + 1 ) & ( V_29 - 1 ) ;
V_2 -> V_25 . V_26 ++ ;
}
if ( ! F_14 ( V_19 ) ) {
V_5 = F_4 ( V_2 -> V_6 + V_11 ) ;
V_5 |= V_12 ;
F_6 ( V_5 , V_2 -> V_6 + V_11 ) ;
}
if ( F_15 ( V_19 ) < V_30 )
F_16 ( V_2 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = & V_2 -> V_20 -> V_2 ;
char V_33 ;
T_1 V_34 , V_21 , V_35 ;
do {
V_33 = V_36 ;
V_2 -> V_25 . V_37 ++ ;
V_34 = F_4 ( V_2 -> V_6 + V_7 ) ;
if ( V_34 & V_38 ) {
if ( V_34 & V_39 )
V_2 -> V_25 . V_40 ++ ;
else if ( V_34 & V_41 )
V_2 -> V_25 . V_42 ++ ;
else if ( V_34 & V_43 )
V_2 -> V_25 . V_42 ++ ;
V_35 = F_4 ( V_2 -> V_6 + V_11 ) ;
V_35 |= V_44 ;
F_6 ( V_35 , V_2 -> V_6 + V_11 ) ;
V_35 &= ~ V_44 ;
F_6 ( V_35 , V_2 -> V_6 + V_11 ) ;
V_34 &= V_2 -> V_45 ;
if ( V_34 & V_41 )
V_33 = V_46 ;
else if ( V_34 & V_43 )
V_33 = V_47 ;
}
V_21 = F_4 ( V_2 -> V_6 + V_48 ) ;
V_21 &= 0xff ;
if ( ( V_34 & V_2 -> V_49 ) == 0 )
F_18 ( V_32 , V_21 , V_33 ) ;
if ( V_34 & V_39 )
F_18 ( V_32 , 0 , V_50 ) ;
} while ( ! ( F_4 ( V_2 -> V_6 + V_7 ) & V_51 ) );
F_19 ( & V_2 -> V_16 ) ;
F_20 ( V_32 ) ;
F_21 ( & V_2 -> V_16 ) ;
}
static T_2 F_22 ( int V_15 , void * V_52 )
{
struct V_1 * V_2 = (struct V_1 * ) V_52 ;
F_21 ( & V_2 -> V_16 ) ;
if ( ! ( F_4 ( V_2 -> V_6 + V_7 ) & V_51 ) )
F_17 ( V_2 ) ;
if ( ! ( F_4 ( V_2 -> V_6 + V_7 ) & V_22 ) ) {
if ( F_4 ( V_2 -> V_6 + V_11 ) & V_12 )
F_12 ( V_2 ) ;
}
F_19 ( & V_2 -> V_16 ) ;
return V_53 ;
}
static const char * F_23 ( struct V_1 * V_2 )
{
return ( V_2 -> type == V_54 ) ? L_1 : NULL ;
}
static void F_24 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_4 ( V_2 -> V_6 + V_11 ) ;
V_5 |= ( V_55 | V_56 | V_57 ) ;
F_6 ( V_5 , V_2 -> V_6 + V_11 ) ;
V_5 &= ~ ( V_55 | V_56 | V_57 ) ;
F_6 ( V_5 , V_2 -> V_6 + V_11 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
T_1 V_5 ;
int V_58 = 0 ;
V_5 = F_4 ( V_2 -> V_6 + V_11 ) ;
V_5 |= V_57 ;
F_6 ( V_5 , V_2 -> V_6 + V_11 ) ;
V_5 &= ~ V_57 ;
F_6 ( V_5 , V_2 -> V_6 + V_11 ) ;
V_5 |= ( V_13 | V_59 ) ;
F_6 ( V_5 , V_2 -> V_6 + V_11 ) ;
V_5 |= ( V_17 | V_12 ) ;
F_6 ( V_5 , V_2 -> V_6 + V_11 ) ;
V_5 = ( F_26 ( 1 ) | F_27 ( V_2 -> V_60 / 2 ) ) ;
F_6 ( V_5 , V_2 -> V_6 + V_61 ) ;
V_58 = F_28 ( V_2 -> V_15 , F_22 , 0 ,
F_23 ( V_2 ) , V_2 ) ;
return V_58 ;
}
static void F_29 ( struct V_1 * V_2 , unsigned long V_62 )
{
T_1 V_5 ;
while ( ! F_3 ( V_2 ) )
F_30 () ;
V_5 = F_4 ( V_2 -> V_6 + V_63 ) ;
V_5 &= ~ V_64 ;
V_5 = ( ( V_2 -> V_65 * 10 / ( V_62 * 4 ) + 5 ) / 10 ) - 1 ;
V_5 |= V_66 ;
F_6 ( V_5 , V_2 -> V_6 + V_63 ) ;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
struct V_67 * V_69 )
{
unsigned int V_70 , V_71 , V_62 ;
unsigned long V_14 ;
T_1 V_5 ;
F_10 ( & V_2 -> V_16 , V_14 ) ;
V_70 = V_68 -> V_72 ;
V_71 = V_68 -> V_73 ;
V_5 = F_4 ( V_2 -> V_6 + V_11 ) ;
V_5 &= ~ V_74 ;
switch ( V_70 & V_75 ) {
case V_76 :
V_5 |= V_77 ;
break;
case V_78 :
V_5 |= V_79 ;
break;
case V_80 :
V_5 |= V_81 ;
break;
case V_82 :
V_5 |= V_83 ;
break;
}
if ( V_70 & V_84 )
V_5 |= V_85 ;
else
V_5 &= ~ V_85 ;
if ( V_70 & V_86 )
V_5 |= V_87 ;
else
V_5 &= ~ V_87 ;
V_5 &= ~ V_88 ;
if ( V_70 & V_89 )
V_5 |= V_90 ;
else
V_5 &= ~ V_91 ;
if ( V_70 & V_92 )
V_5 &= ~ V_93 ;
else
V_5 |= V_93 ;
F_6 ( V_5 , V_2 -> V_6 + V_11 ) ;
V_62 = F_32 ( V_2 , V_68 , V_69 , 9600 , 115200 ) ;
F_29 ( V_2 , V_62 ) ;
V_2 -> V_45 = V_39 ;
if ( V_71 & V_94 )
V_2 -> V_45 |= V_43 |
V_41 ;
V_2 -> V_49 = 0 ;
if ( V_71 & V_95 )
V_2 -> V_49 |= V_43 |
V_41 ;
F_33 ( V_2 , V_68 -> V_72 , V_62 ) ;
F_11 ( & V_2 -> V_16 , V_14 ) ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_96 * V_97 )
{
int V_58 = 0 ;
if ( V_2 -> type != V_54 )
V_58 = - V_98 ;
if ( V_2 -> V_15 != V_97 -> V_15 )
V_58 = - V_98 ;
if ( V_97 -> V_99 < 9600 )
V_58 = - V_98 ;
return V_58 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_100 * V_101 = F_36 ( V_2 -> V_102 ) ;
struct V_103 * V_104 ;
V_104 = F_37 ( V_101 , V_105 , 0 ) ;
if ( ! V_104 ) {
F_38 ( V_2 -> V_102 , L_2 ) ;
return - V_106 ;
}
return F_39 ( V_104 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
int V_107 = F_35 ( V_2 ) ;
if ( V_2 -> V_14 & V_108 ) {
F_41 ( V_2 -> V_102 , V_2 -> V_109 , V_107 ) ;
F_42 ( V_2 -> V_102 , V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
}
}
static int F_43 ( struct V_1 * V_2 )
{
int V_107 = F_35 ( V_2 ) ;
if ( V_107 < 0 )
return V_107 ;
if ( ! F_44 ( V_2 -> V_102 , V_2 -> V_109 , V_107 ,
F_45 ( V_2 -> V_102 ) ) ) {
F_38 ( V_2 -> V_102 , L_3 ) ;
return - V_110 ;
}
if ( V_2 -> V_14 & V_108 ) {
V_2 -> V_6 = F_46 ( V_2 -> V_102 ,
V_2 -> V_109 ,
V_107 ) ;
if ( V_2 -> V_6 == NULL )
return - V_111 ;
}
return 0 ;
}
static void F_47 ( struct V_1 * V_2 , int V_14 )
{
if ( V_14 & V_112 ) {
V_2 -> type = V_54 ;
F_43 ( V_2 ) ;
}
}
static void F_48 ( struct V_1 * V_2 , int V_21 )
{
if ( ! V_2 -> V_6 )
return;
while ( F_4 ( V_2 -> V_6 + V_7 ) & V_22 )
F_30 () ;
F_6 ( V_21 , V_2 -> V_6 + V_24 ) ;
}
static void F_49 ( struct V_113 * V_114 , const char * V_115 ,
T_3 V_116 )
{
struct V_1 * V_2 ;
unsigned long V_14 ;
int V_117 ;
T_1 V_5 , V_118 ;
V_2 = V_119 [ V_114 -> V_120 ] ;
if ( ! V_2 )
return;
F_50 ( V_14 ) ;
if ( V_2 -> V_121 ) {
V_117 = 0 ;
} else if ( V_122 ) {
V_117 = F_51 ( & V_2 -> V_16 ) ;
} else {
F_21 ( & V_2 -> V_16 ) ;
V_117 = 1 ;
}
V_5 = F_4 ( V_2 -> V_6 + V_11 ) ;
V_5 |= V_59 ;
V_118 = V_5 & ~ ( V_12 | V_17 ) ;
F_6 ( V_118 , V_2 -> V_6 + V_11 ) ;
F_52 ( V_2 , V_115 , V_116 , F_48 ) ;
F_6 ( V_5 , V_2 -> V_6 + V_11 ) ;
if ( V_117 )
F_19 ( & V_2 -> V_16 ) ;
F_53 ( V_14 ) ;
}
static int F_54 ( struct V_113 * V_114 , char * V_123 )
{
struct V_1 * V_2 ;
int V_62 = 115200 ;
int V_124 = 8 ;
int V_125 = 'n' ;
int V_126 = 'n' ;
if ( V_114 -> V_120 < 0 || V_114 -> V_120 >= V_127 )
return - V_98 ;
V_2 = V_119 [ V_114 -> V_120 ] ;
if ( ! V_2 || ! V_2 -> V_6 )
return - V_106 ;
if ( V_123 )
F_55 ( V_123 , & V_62 , & V_125 , & V_124 , & V_126 ) ;
return F_56 ( V_2 , V_114 , V_62 , V_125 , V_124 , V_126 ) ;
}
static int T_4 F_57 ( void )
{
F_58 ( & V_128 ) ;
return 0 ;
}
static int F_59 ( struct V_100 * V_101 )
{
struct V_103 * V_129 , * V_130 ;
struct V_1 * V_2 ;
struct V_131 * V_131 ;
int V_58 = 0 ;
if ( V_101 -> V_102 . V_132 )
V_101 -> V_133 = F_60 ( V_101 -> V_102 . V_132 , L_4 ) ;
if ( V_101 -> V_133 < 0 || V_101 -> V_133 >= V_127 )
return - V_98 ;
V_129 = F_37 ( V_101 , V_105 , 0 ) ;
if ( ! V_129 )
return - V_106 ;
V_130 = F_37 ( V_101 , V_134 , 0 ) ;
if ( ! V_130 )
return - V_106 ;
if ( V_119 [ V_101 -> V_133 ] ) {
F_38 ( & V_101 -> V_102 , L_5 , V_101 -> V_133 ) ;
return - V_110 ;
}
V_2 = F_61 ( & V_101 -> V_102 , sizeof( struct V_1 ) , V_135 ) ;
if ( ! V_2 )
return - V_111 ;
V_131 = F_62 ( & V_101 -> V_102 , NULL ) ;
if ( F_63 ( V_131 ) )
return F_64 ( V_131 ) ;
V_2 -> V_65 = F_65 ( V_131 ) ;
V_2 -> V_136 = V_137 ;
V_2 -> V_109 = V_129 -> V_138 ;
V_2 -> V_15 = V_130 -> V_138 ;
V_2 -> V_14 = V_139 | V_108 | V_140 ;
V_2 -> V_102 = & V_101 -> V_102 ;
V_2 -> line = V_101 -> V_133 ;
V_2 -> type = V_54 ;
V_2 -> V_23 = 0 ;
V_2 -> V_141 = & V_142 ;
V_2 -> V_60 = 64 ;
V_119 [ V_101 -> V_133 ] = V_2 ;
F_66 ( V_101 , V_2 ) ;
if ( F_43 ( V_2 ) >= 0 ) {
F_24 ( V_2 ) ;
F_40 ( V_2 ) ;
}
V_58 = F_67 ( & V_143 , V_2 ) ;
if ( V_58 )
V_119 [ V_101 -> V_133 ] = NULL ;
return V_58 ;
}
static int F_68 ( struct V_100 * V_101 )
{
struct V_1 * V_2 ;
V_2 = F_69 ( V_101 ) ;
F_70 ( & V_143 , V_2 ) ;
V_119 [ V_101 -> V_133 ] = NULL ;
return 0 ;
}
static int T_4 F_71 ( void )
{
int V_58 ;
V_58 = F_72 ( & V_143 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_73 ( & V_144 ) ;
if ( V_58 )
F_74 ( & V_143 ) ;
return V_58 ;
}
static void T_5 F_75 ( void )
{
F_76 ( & V_144 ) ;
F_74 ( & V_143 ) ;
}
