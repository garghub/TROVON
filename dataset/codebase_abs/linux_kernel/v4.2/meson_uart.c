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
return ( V_5 & V_8 ) ? V_9 : 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_4 ( V_2 -> V_6 + V_10 ) ;
V_5 &= ~ V_11 ;
F_6 ( V_5 , V_2 -> V_6 + V_10 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_4 ( V_2 -> V_6 + V_10 ) ;
V_5 &= ~ V_12 ;
F_6 ( V_5 , V_2 -> V_6 + V_10 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
unsigned long V_13 ;
T_1 V_5 ;
F_9 ( V_2 -> V_14 , V_2 ) ;
F_10 ( & V_2 -> V_15 , V_13 ) ;
V_5 = F_4 ( V_2 -> V_6 + V_10 ) ;
V_5 &= ~ ( V_12 | V_11 ) ;
V_5 &= ~ ( V_16 | V_17 ) ;
F_6 ( V_5 , V_2 -> V_6 + V_10 ) ;
F_11 ( & V_2 -> V_15 , V_13 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = & V_2 -> V_20 -> V_19 ;
unsigned int V_21 ;
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
V_35 = F_4 ( V_2 -> V_6 + V_10 ) ;
V_35 |= V_44 ;
F_6 ( V_35 , V_2 -> V_6 + V_10 ) ;
V_35 &= ~ V_44 ;
F_6 ( V_35 , V_2 -> V_6 + V_10 ) ;
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
F_19 ( & V_2 -> V_15 ) ;
F_20 ( V_32 ) ;
F_21 ( & V_2 -> V_15 ) ;
}
static T_2 F_22 ( int V_14 , void * V_52 )
{
struct V_1 * V_2 = (struct V_1 * ) V_52 ;
F_21 ( & V_2 -> V_15 ) ;
if ( ! ( F_4 ( V_2 -> V_6 + V_7 ) & V_51 ) )
F_17 ( V_2 ) ;
if ( ! ( F_4 ( V_2 -> V_6 + V_7 ) & V_22 ) )
F_12 ( V_2 ) ;
F_19 ( & V_2 -> V_15 ) ;
return V_53 ;
}
static const char * F_23 ( struct V_1 * V_2 )
{
return ( V_2 -> type == V_54 ) ? L_1 : NULL ;
}
static int F_24 ( struct V_1 * V_2 )
{
T_1 V_5 ;
int V_55 = 0 ;
V_5 = F_4 ( V_2 -> V_6 + V_10 ) ;
V_5 |= ( V_56 | V_57 | V_58 ) ;
F_6 ( V_5 , V_2 -> V_6 + V_10 ) ;
V_5 &= ~ ( V_56 | V_57 | V_58 ) ;
F_6 ( V_5 , V_2 -> V_6 + V_10 ) ;
V_5 |= ( V_12 | V_11 ) ;
F_6 ( V_5 , V_2 -> V_6 + V_10 ) ;
V_5 |= ( V_16 | V_17 ) ;
F_6 ( V_5 , V_2 -> V_6 + V_10 ) ;
V_5 = ( F_25 ( 1 ) | F_26 ( V_2 -> V_59 / 2 ) ) ;
F_6 ( V_5 , V_2 -> V_6 + V_60 ) ;
V_55 = F_27 ( V_2 -> V_14 , F_22 , 0 ,
F_23 ( V_2 ) , V_2 ) ;
return V_55 ;
}
static void F_28 ( struct V_1 * V_2 , unsigned long V_61 )
{
T_1 V_5 ;
while ( ! ( F_4 ( V_2 -> V_6 + V_7 ) & V_8 ) )
F_29 () ;
V_5 = F_4 ( V_2 -> V_6 + V_62 ) ;
V_5 &= ~ V_63 ;
V_5 = ( ( V_2 -> V_64 * 10 / ( V_61 * 4 ) + 5 ) / 10 ) - 1 ;
V_5 |= V_65 ;
F_6 ( V_5 , V_2 -> V_6 + V_62 ) ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_66 * V_67 ,
struct V_66 * V_68 )
{
unsigned int V_69 , V_70 , V_61 ;
unsigned long V_13 ;
T_1 V_5 ;
F_10 ( & V_2 -> V_15 , V_13 ) ;
V_69 = V_67 -> V_71 ;
V_70 = V_67 -> V_72 ;
V_5 = F_4 ( V_2 -> V_6 + V_10 ) ;
V_5 &= ~ V_73 ;
switch ( V_69 & V_74 ) {
case V_75 :
V_5 |= V_76 ;
break;
case V_77 :
V_5 |= V_78 ;
break;
case V_79 :
V_5 |= V_80 ;
break;
case V_81 :
V_5 |= V_82 ;
break;
}
if ( V_69 & V_83 )
V_5 |= V_84 ;
else
V_5 &= ~ V_84 ;
if ( V_69 & V_85 )
V_5 |= V_86 ;
else
V_5 &= ~ V_86 ;
V_5 &= ~ V_87 ;
if ( V_69 & V_88 )
V_5 |= V_89 ;
else
V_5 &= ~ V_90 ;
if ( V_69 & V_91 )
V_5 &= ~ V_92 ;
else
V_5 |= V_92 ;
F_6 ( V_5 , V_2 -> V_6 + V_10 ) ;
V_61 = F_31 ( V_2 , V_67 , V_68 , 9600 , 115200 ) ;
F_28 ( V_2 , V_61 ) ;
V_2 -> V_45 = V_39 ;
if ( V_70 & V_93 )
V_2 -> V_45 |= V_43 |
V_41 ;
V_2 -> V_49 = 0 ;
if ( V_70 & V_94 )
V_2 -> V_49 |= V_43 |
V_41 ;
F_32 ( V_2 , V_67 -> V_71 , V_61 ) ;
F_11 ( & V_2 -> V_15 , V_13 ) ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_95 * V_96 )
{
int V_55 = 0 ;
if ( V_2 -> type != V_54 )
V_55 = - V_97 ;
if ( V_2 -> V_14 != V_96 -> V_14 )
V_55 = - V_97 ;
if ( V_96 -> V_98 < 9600 )
V_55 = - V_97 ;
return V_55 ;
}
static void F_34 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 & V_99 ) {
F_35 ( V_2 -> V_100 , V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
}
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_101 * V_102 = F_37 ( V_2 -> V_100 ) ;
struct V_103 * V_104 ;
int V_105 ;
V_104 = F_38 ( V_102 , V_106 , 0 ) ;
if ( ! V_104 ) {
F_39 ( & V_102 -> V_100 , L_2 ) ;
return - V_107 ;
}
V_105 = F_40 ( V_104 ) ;
if ( ! F_41 ( V_2 -> V_100 , V_2 -> V_108 , V_105 ,
F_42 ( V_2 -> V_100 ) ) ) {
F_39 ( V_2 -> V_100 , L_3 ) ;
return - V_109 ;
}
if ( V_2 -> V_13 & V_99 ) {
V_2 -> V_6 = F_43 ( V_2 -> V_100 ,
V_2 -> V_108 ,
V_105 ) ;
if ( V_2 -> V_6 == NULL )
return - V_110 ;
}
return 0 ;
}
static void F_44 ( struct V_1 * V_2 , int V_13 )
{
if ( V_13 & V_111 ) {
V_2 -> type = V_54 ;
F_36 ( V_2 ) ;
}
}
static void F_45 ( struct V_1 * V_2 , int V_21 )
{
if ( ! V_2 -> V_6 )
return;
while ( F_4 ( V_2 -> V_6 + V_7 ) & V_22 )
F_29 () ;
F_6 ( V_21 , V_2 -> V_6 + V_24 ) ;
}
static void F_46 ( struct V_112 * V_113 , const char * V_114 ,
T_3 V_115 )
{
struct V_1 * V_2 ;
unsigned long V_13 ;
int V_116 ;
V_2 = V_117 [ V_113 -> V_118 ] ;
if ( ! V_2 )
return;
F_47 ( V_13 ) ;
if ( V_2 -> V_119 ) {
V_116 = 0 ;
} else if ( V_120 ) {
V_116 = F_48 ( & V_2 -> V_15 ) ;
} else {
F_21 ( & V_2 -> V_15 ) ;
V_116 = 1 ;
}
F_49 ( V_2 , V_114 , V_115 , F_45 ) ;
if ( V_116 )
F_19 ( & V_2 -> V_15 ) ;
F_50 ( V_13 ) ;
}
static int F_51 ( struct V_112 * V_113 , char * V_121 )
{
struct V_1 * V_2 ;
int V_61 = 115200 ;
int V_122 = 8 ;
int V_123 = 'n' ;
int V_124 = 'n' ;
if ( V_113 -> V_118 < 0 || V_113 -> V_118 >= V_125 )
return - V_97 ;
V_2 = V_117 [ V_113 -> V_118 ] ;
if ( ! V_2 || ! V_2 -> V_6 )
return - V_107 ;
if ( V_121 )
F_52 ( V_121 , & V_61 , & V_123 , & V_122 , & V_124 ) ;
return F_53 ( V_2 , V_113 , V_61 , V_123 , V_122 , V_124 ) ;
}
static int T_4 F_54 ( void )
{
F_55 ( & V_126 ) ;
return 0 ;
}
static int F_56 ( struct V_101 * V_102 )
{
struct V_103 * V_127 , * V_128 ;
struct V_1 * V_2 ;
struct V_129 * V_129 ;
int V_55 = 0 ;
if ( V_102 -> V_100 . V_130 )
V_102 -> V_131 = F_57 ( V_102 -> V_100 . V_130 , L_4 ) ;
if ( V_102 -> V_131 < 0 || V_102 -> V_131 >= V_125 )
return - V_97 ;
V_127 = F_38 ( V_102 , V_106 , 0 ) ;
if ( ! V_127 )
return - V_107 ;
V_128 = F_38 ( V_102 , V_132 , 0 ) ;
if ( ! V_128 )
return - V_107 ;
if ( V_117 [ V_102 -> V_131 ] ) {
F_39 ( & V_102 -> V_100 , L_5 , V_102 -> V_131 ) ;
return - V_109 ;
}
V_2 = F_58 ( & V_102 -> V_100 , sizeof( struct V_1 ) , V_133 ) ;
if ( ! V_2 )
return - V_110 ;
V_129 = F_59 ( & V_102 -> V_100 , NULL ) ;
if ( F_60 ( V_129 ) )
return F_61 ( V_129 ) ;
V_2 -> V_64 = F_62 ( V_129 ) ;
V_2 -> V_134 = V_135 ;
V_2 -> V_108 = V_127 -> V_136 ;
V_2 -> V_14 = V_128 -> V_136 ;
V_2 -> V_13 = V_137 | V_99 | V_138 ;
V_2 -> V_100 = & V_102 -> V_100 ;
V_2 -> line = V_102 -> V_131 ;
V_2 -> type = V_54 ;
V_2 -> V_23 = 0 ;
V_2 -> V_139 = & V_140 ;
V_2 -> V_59 = 64 ;
V_117 [ V_102 -> V_131 ] = V_2 ;
F_63 ( V_102 , V_2 ) ;
V_55 = F_64 ( & V_141 , V_2 ) ;
if ( V_55 )
V_117 [ V_102 -> V_131 ] = NULL ;
return V_55 ;
}
static int F_65 ( struct V_101 * V_102 )
{
struct V_1 * V_2 ;
V_2 = F_66 ( V_102 ) ;
F_67 ( & V_141 , V_2 ) ;
V_117 [ V_102 -> V_131 ] = NULL ;
return 0 ;
}
static int T_4 F_68 ( void )
{
int V_55 ;
V_55 = F_69 ( & V_141 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_70 ( & V_142 ) ;
if ( V_55 )
F_71 ( & V_141 ) ;
return V_55 ;
}
static void T_5 F_72 ( void )
{
F_73 ( & V_142 ) ;
F_71 ( & V_141 ) ;
}
