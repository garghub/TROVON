static bool F_1 ( struct V_1 * V_2 )
{
return ! ! ( F_2 ( V_2 -> V_3 + V_4 ) &
V_5 ) ;
}
static bool F_3 ( struct V_1 * V_2 )
{
return ! ! ( F_2 ( V_2 -> V_3 + V_4 ) &
V_6 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
T_1 V_7 = F_2 ( V_2 -> V_3 + V_8 ) ;
V_7 &= ~ V_9 ;
F_5 ( V_7 , V_2 -> V_3 + V_8 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
T_1 V_7 = F_2 ( V_2 -> V_3 + V_8 ) ;
V_7 |= V_9 ;
F_5 ( V_7 , V_2 -> V_3 + V_8 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_7 = F_2 ( V_2 -> V_3 + V_8 ) ;
V_7 &= ~ V_10 ;
F_5 ( V_7 , V_2 -> V_3 + V_8 ) ;
}
static void F_8 ( struct V_11 * V_12 )
{
struct V_13 * V_14 =
F_9 ( F_10 ( V_12 ) ,
struct V_13 , V_15 ) ;
if ( ! F_3 ( & V_14 -> V_2 ) )
F_5 ( V_10 , V_14 -> V_2 . V_3 + V_16 ) ;
F_11 ( & V_14 -> V_15 , F_12 ( 100 ) ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
unsigned long V_17 ;
F_14 ( & V_2 -> V_18 , V_17 ) ;
while ( 1 ) {
T_1 V_19 , V_20 ;
unsigned int V_21 ;
if ( F_3 ( V_2 ) )
break;
V_20 = F_2 ( V_2 -> V_3 + V_22 ) ;
V_19 = F_2 ( V_2 -> V_3 + V_23 ) ;
V_2 -> V_24 . V_25 ++ ;
V_21 = V_26 ;
if ( V_19 ) {
if ( V_19 & V_27 )
V_2 -> V_24 . V_28 ++ ;
else if ( V_19 & V_29 )
V_2 -> V_24 . V_30 ++ ;
else if ( V_19 & V_31 )
V_2 -> V_24 . V_32 ++ ;
V_19 &= V_2 -> V_33 ;
if ( V_19 & V_27 )
V_21 = V_34 ;
else if ( V_19 & V_29 )
V_21 = V_35 ;
else if ( V_19 & V_31 )
V_21 = V_36 ;
}
if ( V_19 & V_2 -> V_37 )
continue;
F_15 ( V_2 , V_19 , V_31 , V_20 ,
V_21 ) ;
}
F_16 ( & V_2 -> V_18 , V_17 ) ;
F_17 ( & V_2 -> V_38 -> V_2 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = & V_2 -> V_38 -> V_40 ;
unsigned long V_17 ;
if ( F_1 ( V_2 ) )
return;
F_14 ( & V_2 -> V_18 , V_17 ) ;
if ( V_2 -> V_41 ) {
F_5 ( V_2 -> V_41 , V_2 -> V_3 + V_22 ) ;
V_2 -> V_24 . V_42 ++ ;
V_2 -> V_41 = 0 ;
goto V_43;
}
if ( F_19 ( V_40 ) || F_20 ( V_2 ) ) {
F_4 ( V_2 ) ;
goto V_43;
}
while ( ! F_19 ( V_40 ) ) {
F_21 ( V_40 -> V_44 [ V_40 -> V_45 ] , V_2 -> V_3 + V_22 ) ;
V_40 -> V_45 = ( V_40 -> V_45 + 1 ) & ( V_46 - 1 ) ;
V_2 -> V_24 . V_42 ++ ;
if ( F_1 ( V_2 ) )
break;
}
if ( F_22 ( V_40 ) < V_47 )
F_23 ( V_2 ) ;
V_43:
F_16 ( & V_2 -> V_18 , V_17 ) ;
}
static T_2 F_24 ( int V_48 , void * V_49 )
{
struct V_1 * V_2 = V_49 ;
T_1 V_50 = F_2 ( V_2 -> V_3 + V_51 ) ;
F_5 ( V_10 | V_9 ,
V_2 -> V_3 + V_52 ) ;
if ( V_50 & V_10 )
F_13 ( V_2 ) ;
if ( V_50 & V_9 )
F_18 ( V_2 ) ;
return V_53 ;
}
static unsigned int F_25 ( struct V_1 * V_2 )
{
T_1 V_19 = F_2 ( V_2 -> V_3 + V_23 ) ;
return ( V_19 & V_54 ) ? V_55 : 0 ;
}
static unsigned int F_26 ( struct V_1 * V_2 )
{
return V_56 ;
}
static void F_27 ( struct V_1 * V_2 , unsigned int V_57 )
{
}
static void F_28 ( struct V_1 * V_2 , int V_38 )
{
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_13 * V_14 =
F_9 ( V_2 , struct V_13 , V_2 ) ;
F_5 ( V_58 , V_2 -> V_3 + V_59 ) ;
F_5 ( V_60 , V_2 -> V_3 + V_61 ) ;
F_5 ( 0 , V_2 -> V_3 + V_61 ) ;
F_5 ( V_62
| V_63 | V_64 ,
V_2 -> V_3 + V_65 ) ;
F_5 ( V_66 ,
V_2 -> V_3 + V_4 ) ;
F_5 ( V_67 | V_68 ,
V_2 -> V_3 + V_61 ) ;
F_5 ( V_9 | V_10 ,
V_2 -> V_3 + V_8 ) ;
F_11 ( & V_14 -> V_15 , F_12 ( 100 ) ) ;
return 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_13 * V_14 =
F_9 ( V_2 , struct V_13 , V_2 ) ;
F_5 ( 0 , V_2 -> V_3 + V_59 ) ;
F_31 ( & V_14 -> V_15 ) ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_69 * V_71 )
{
unsigned int V_72 , V_73 ;
T_1 V_74 = 0 ;
unsigned long V_17 ;
V_70 -> V_75 &= ~ V_76 ;
V_70 -> V_77 &= ~ ( V_78 | V_79 ) ;
V_72 = F_33 ( V_2 , V_70 , V_71 ,
V_2 -> V_80 / ( 0x10000 * 16 ) ,
V_2 -> V_80 / 256 ) ;
V_73 = F_34 ( V_2 , V_72 ) - 1 ;
switch ( V_70 -> V_75 & V_81 ) {
case V_82 :
break;
case V_83 :
default:
V_74 |= V_84 ;
break;
}
if ( V_70 -> V_75 & V_85 )
V_74 |= V_86 ;
if ( V_70 -> V_75 & V_87 ) {
V_74 |= V_88 ;
if ( V_70 -> V_75 & V_89 )
V_74 |= V_90 ;
}
V_2 -> V_33 = V_31 ;
if ( V_70 -> V_77 & V_91 )
V_2 -> V_33 |= V_27
| V_29 ;
V_2 -> V_37 = 0 ;
if ( ! ( V_70 -> V_75 & V_92 ) )
V_2 -> V_37 |= V_31
| V_27 | V_29 ;
F_14 ( & V_2 -> V_18 , V_17 ) ;
F_35 ( V_2 , V_70 -> V_75 , V_72 ) ;
F_5 ( V_74 , V_2 -> V_3 + V_93 ) ;
F_5 ( V_73 & 0xff , V_2 -> V_3 + V_94 ) ;
F_5 ( V_73 >> 8 , V_2 -> V_3 + V_95 ) ;
F_16 ( & V_2 -> V_18 , V_17 ) ;
}
static const char * F_36 ( struct V_1 * V_2 )
{
return ( V_2 -> type == V_96 ) ? L_1 : NULL ;
}
static void F_37 ( struct V_1 * V_2 , int V_17 )
{
if ( V_17 & V_97 )
V_2 -> type = V_96 ;
}
static void F_38 ( struct V_1 * V_2 )
{
}
static int F_39 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_40 ( struct V_1 * V_2 , int V_20 )
{
while ( F_1 ( V_2 ) )
F_41 () ;
F_5 ( V_20 , V_2 -> V_3 + V_22 ) ;
}
static void F_42 ( struct V_98 * V_99 , const char * V_100 ,
unsigned V_101 )
{
struct V_1 * V_2 = V_102 [ V_99 -> V_103 ] ;
T_1 V_19 ;
unsigned long V_17 ;
int V_104 = 1 ;
if ( V_105 )
V_104 = F_43 ( & V_2 -> V_18 , V_17 ) ;
else
F_14 ( & V_2 -> V_18 , V_17 ) ;
F_44 ( V_2 , V_100 , V_101 , F_40 ) ;
if ( V_104 )
F_16 ( & V_2 -> V_18 , V_17 ) ;
do {
V_19 = F_2 ( V_2 -> V_3 + V_23 ) ;
} while ( ( V_19 & V_54 ) == 0 );
}
static int F_45 ( struct V_98 * V_99 , char * V_106 )
{
int V_72 = 115200 , V_107 = 8 , V_28 = 'n' , V_108 = 'n' ;
struct V_1 * V_2 ;
if ( V_99 -> V_103 < 0 || V_99 -> V_103 >= V_109 )
return - V_110 ;
V_2 = V_102 [ V_99 -> V_103 ] ;
if ( ! V_2 )
return - V_111 ;
if ( V_106 )
F_46 ( V_106 , & V_72 , & V_28 , & V_107 , & V_108 ) ;
return F_47 ( V_2 , V_99 , V_72 , V_28 , V_107 , V_108 ) ;
}
static int F_48 ( struct V_112 * V_113 )
{
struct V_114 * V_115 = V_113 -> V_116 . V_117 ;
int V_48 , V_118 , V_103 ;
struct V_13 * V_14 ;
struct V_119 * V_120 ;
struct V_121 * V_122 ;
if ( ! V_115 ) {
F_49 ( & V_113 -> V_116 , L_2 ) ;
return - V_123 ;
}
V_103 = F_50 ( V_115 , L_3 ) ;
if ( V_103 < 0 || V_103 >= V_109 )
return - V_110 ;
V_14 = F_51 ( & V_113 -> V_116 , sizeof( * V_14 ) , V_124 ) ;
if ( ! V_14 )
return - V_125 ;
V_122 = F_52 ( & V_113 -> V_116 , NULL ) ;
if ( F_53 ( V_122 ) )
return F_54 ( V_122 ) ;
V_120 = F_55 ( V_113 , V_126 , 0 ) ;
V_14 -> V_2 . V_127 = V_120 -> V_128 ;
V_14 -> V_2 . V_3 = F_56 ( & V_113 -> V_116 , V_120 ) ;
if ( F_53 ( V_14 -> V_2 . V_3 ) )
return F_54 ( V_14 -> V_2 . V_3 ) ;
V_48 = F_57 ( V_113 , 0 ) ;
if ( V_48 < 0 )
return V_48 ;
V_14 -> V_2 . V_48 = V_48 ;
V_14 -> V_2 . V_129 = V_130 ;
V_14 -> V_2 . V_80 = F_58 ( V_122 ) ;
V_14 -> V_2 . V_131 = 16 ;
V_14 -> V_2 . V_116 = & V_113 -> V_116 ;
V_14 -> V_2 . V_132 = & V_133 ;
V_14 -> V_2 . line = V_103 ;
V_14 -> V_2 . type = V_96 ;
F_59 ( & V_14 -> V_2 . V_18 ) ;
V_102 [ V_103 ] = & V_14 -> V_2 ;
F_60 ( V_113 , & V_14 -> V_2 ) ;
F_61 ( & V_14 -> V_15 , F_8 ) ;
V_118 = F_62 ( & V_113 -> V_116 , V_14 -> V_2 . V_48 , F_24 , 0 ,
F_63 ( & V_113 -> V_116 ) , & V_14 -> V_2 ) ;
if ( V_118 )
return V_118 ;
return F_64 ( & V_134 , & V_14 -> V_2 ) ;
}
static int F_65 ( struct V_112 * V_113 )
{
struct V_1 * V_2 = F_66 ( V_113 ) ;
F_67 ( & V_134 , V_2 ) ;
return 0 ;
}
static int T_3 F_68 ( void )
{
int V_118 ;
if ( F_69 ( V_135 ) ) {
V_134 . V_136 = & V_137 ;
V_137 . V_138 = & V_134 ;
}
V_118 = F_70 ( & V_134 ) ;
if ( V_118 )
return V_118 ;
return F_71 ( & V_139 ) ;
}
static void T_4 F_72 ( void )
{
F_73 ( & V_139 ) ;
F_74 ( & V_134 ) ;
}
