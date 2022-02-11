static inline bool F_1 ( void )
{
return F_2 ( V_1 ) ;
}
static inline unsigned int F_3 ( struct V_2 * V_3 ,
int V_4 )
{
return F_4 ( V_3 -> V_5 . V_6 + V_4 ) ;
}
static inline void F_5 ( struct V_2 * V_3 ,
int V_4 , unsigned int V_7 )
{
F_6 ( V_7 , V_3 -> V_5 . V_6 + V_4 ) ;
}
static inline void F_7 ( struct V_2 * V_3 ,
unsigned int V_4 ,
unsigned int V_8 ,
unsigned int V_9 )
{
unsigned int V_10 ;
V_10 = F_3 ( V_3 , V_4 ) ;
V_10 &= ~ V_8 ;
V_10 |= V_9 ;
F_5 ( V_3 , V_4 , V_10 ) ;
}
static inline void F_8 ( struct V_2 * V_3 ,
unsigned int V_4 ,
unsigned int V_9 )
{
F_7 ( V_3 , V_4 , 0 , V_9 ) ;
}
static inline void F_9 ( struct V_2 * V_3 ,
unsigned int V_4 ,
unsigned int V_9 )
{
F_7 ( V_3 , V_4 , V_9 , 0 ) ;
}
static inline void F_10 ( struct V_2 * V_3 )
{
V_3 -> V_11 |= V_12 ;
F_5 ( V_3 , V_13 , V_3 -> V_11 ) ;
}
static inline void F_11 ( struct V_2 * V_3 )
{
V_3 -> V_11 &= ~ V_12 ;
F_5 ( V_3 , V_13 , V_3 -> V_11 ) ;
}
static inline void F_12 ( struct V_2 * V_3 , int V_14 )
{
unsigned int V_15 ;
V_15 = V_14 & V_16 ;
V_15 |= V_17 ;
F_5 ( V_3 , V_18 , V_15 ) ;
}
static unsigned int F_13 ( struct V_19 * V_5 )
{
struct V_2 * V_3 =
F_14 ( V_5 , struct V_2 , V_5 ) ;
unsigned long V_20 ;
unsigned int V_15 ;
F_15 ( & V_3 -> V_5 . V_21 , V_20 ) ;
V_15 = F_3 ( V_3 , V_18 ) ;
F_16 ( & V_3 -> V_5 . V_21 , V_20 ) ;
return ( V_15 & V_17 ) ? 0 : V_22 ;
}
static unsigned int F_17 ( struct V_19 * V_5 )
{
return V_23 ;
}
static void F_18 ( struct V_19 * V_5 , unsigned int V_24 )
{
}
static void F_19 ( struct V_19 * V_5 )
{
struct V_2 * V_3 =
F_14 ( V_5 , struct V_2 , V_5 ) ;
F_10 ( V_3 ) ;
}
static void F_20 ( struct V_19 * V_5 )
{
struct V_2 * V_3 =
F_14 ( V_5 , struct V_2 , V_5 ) ;
F_11 ( V_3 ) ;
}
static void F_21 ( struct V_19 * V_5 )
{
struct V_2 * V_3 =
F_14 ( V_5 , struct V_2 , V_5 ) ;
V_3 -> V_11 &= ~ V_25 ;
F_5 ( V_3 , V_13 , V_3 -> V_11 ) ;
}
static void F_22 ( struct V_19 * V_5 , int V_26 )
{
struct V_2 * V_3 =
F_14 ( V_5 , struct V_2 , V_5 ) ;
unsigned long V_20 ;
F_15 ( & V_3 -> V_5 . V_21 , V_20 ) ;
if ( V_26 == - 1 )
F_8 ( V_3 , V_27 ,
V_28 ) ;
else
F_9 ( V_3 , V_27 ,
V_28 ) ;
F_16 ( & V_3 -> V_5 . V_21 , V_20 ) ;
}
static unsigned long F_23 ( unsigned int V_29 ,
unsigned int V_30 ,
unsigned int V_31 )
{
T_1 V_10 ;
T_2 div ;
div = ( 2 << 16 ) * ( V_30 + 1 ) ;
V_10 = V_29 ;
V_10 *= V_31 ;
V_10 += ( div / 2 ) ;
F_24 ( V_10 , div ) ;
return V_10 ;
}
static void F_25 ( unsigned int V_29 ,
unsigned int V_32 ,
unsigned int * V_30 ,
unsigned int * V_31 )
{
unsigned int V_33 ;
long V_34 ;
* V_30 = 0 ;
* V_31 = 0 ;
V_34 = V_32 ;
for ( V_33 = 0 ; V_33 < V_35 ; V_33 ++ ) {
T_1 V_36 ;
int V_37 ;
V_36 = V_32 * ( V_33 + 1 ) ;
V_36 *= ( 2 << 16 ) ;
F_24 ( V_36 , V_29 ) ;
if ( V_36 > V_38 )
break;
V_37 = abs ( F_23 ( V_29 , V_33 , V_36 ) - V_32 ) ;
if ( V_37 < V_34 ) {
V_34 = V_37 ;
* V_30 = V_33 ;
* V_31 = V_36 ;
}
}
}
static void F_26 ( struct V_19 * V_5 ,
struct V_39 * V_40 ,
struct V_39 * V_41 )
{
struct V_2 * V_3 =
F_14 ( V_5 , struct V_2 , V_5 ) ;
unsigned int V_42 ;
unsigned long V_20 ;
unsigned int V_32 , V_30 , V_31 ;
V_40 -> V_43 &= ~ V_44 ;
V_40 -> V_43 |= V_45 ;
V_40 -> V_43 &= ~ V_46 ;
V_42 = 0 ;
if ( V_40 -> V_43 & V_47 ) {
if ( ! ( V_40 -> V_43 & V_48 ) )
V_42 |= V_49 ;
else
V_42 |= V_50 ;
} else {
V_42 |= V_51 ;
}
V_40 -> V_43 &= ~ V_52 ;
V_32 = F_27 ( V_5 , V_40 , V_41 , V_3 -> V_53 , V_3 -> V_54 ) ;
F_25 ( V_5 -> V_55 , V_32 , & V_30 , & V_31 ) ;
F_15 ( & V_3 -> V_5 . V_21 , V_20 ) ;
F_9 ( V_3 , V_27 ,
V_56 << V_57 ) ;
F_28 ( V_5 , V_40 -> V_43 , V_32 ) ;
V_3 -> V_5 . V_58 = 0 ;
if ( ( V_40 -> V_43 & V_59 ) == 0 )
V_3 -> V_5 . V_58 |= V_60 ;
F_5 ( V_3 , V_61 ,
V_30 << V_62 | V_31 ) ;
F_7 ( V_3 , V_27 , V_63 , V_42 ) ;
F_8 ( V_3 , V_27 ,
V_64 ) ;
F_7 ( V_3 , V_27 ,
V_56 << V_57 ,
V_65 << V_57 ) ;
F_16 ( & V_3 -> V_5 . V_21 , V_20 ) ;
if ( F_29 ( V_40 ) )
F_30 ( V_40 , V_32 , V_32 ) ;
}
static void F_31 ( struct V_2 * V_3 )
{
struct V_66 * V_5 = & V_3 -> V_5 . V_67 -> V_5 ;
int V_68 = 256 ;
do {
unsigned int V_15 ;
unsigned char V_14 ;
V_15 = F_3 ( V_3 , V_18 ) ;
if ( ( V_15 & V_69 ) == 0 )
break;
F_5 ( V_3 , V_18 ,
V_69 ) ;
V_3 -> V_5 . V_70 . V_71 ++ ;
V_14 = V_15 & V_16 ;
if ( F_32 ( & V_3 -> V_5 , V_14 ) )
continue;
if ( ( V_3 -> V_5 . V_58 & V_60 ) == 0 )
F_33 ( V_5 , V_14 , V_72 ) ;
} while ( V_68 -- > 0 );
F_34 ( & V_3 -> V_5 . V_21 ) ;
F_35 ( V_5 ) ;
F_36 ( & V_3 -> V_5 . V_21 ) ;
}
static void F_37 ( struct V_2 * V_3 )
{
struct V_73 * V_74 = & V_3 -> V_5 . V_67 -> V_74 ;
int V_75 ;
if ( F_38 ( & V_3 -> V_5 ) )
return;
V_75 = V_3 -> V_5 . V_76 ;
do {
unsigned int V_15 ;
V_15 = F_3 ( V_3 , V_18 ) ;
if ( ( V_15 & V_17 ) == 0 )
break;
if ( V_3 -> V_5 . V_77 ) {
F_12 ( V_3 , V_3 -> V_5 . V_77 ) ;
V_3 -> V_5 . V_70 . V_78 ++ ;
V_3 -> V_5 . V_77 = 0 ;
continue;
}
if ( F_39 ( V_74 ) )
break;
F_12 ( V_3 , V_74 -> V_79 [ V_74 -> V_80 ] ) ;
V_74 -> V_80 = ( V_74 -> V_80 + 1 ) & ( V_81 - 1 ) ;
V_3 -> V_5 . V_70 . V_78 ++ ;
} while ( -- V_75 > 0 );
if ( F_40 ( V_74 ) < V_82 )
F_41 ( & V_3 -> V_5 ) ;
if ( ! F_39 ( V_74 ) )
F_10 ( V_3 ) ;
}
static T_3 F_42 ( int V_83 , void * V_84 )
{
struct V_2 * V_3 = V_84 ;
unsigned int V_85 ;
V_85 = F_3 ( V_3 , V_27 ) ;
if ( ( V_85 & V_86 ) == 0 )
return V_87 ;
F_36 ( & V_3 -> V_5 . V_21 ) ;
V_85 = F_3 ( V_3 , V_88 ) ;
V_85 &= F_3 ( V_3 , V_13 ) ;
if ( V_85 & V_25 ) {
F_5 ( V_3 , V_88 ,
V_25 ) ;
F_31 ( V_3 ) ;
}
if ( V_85 & V_12 ) {
F_5 ( V_3 , V_88 ,
V_12 ) ;
F_11 ( V_3 ) ;
F_37 ( V_3 ) ;
}
F_34 ( & V_3 -> V_5 . V_21 ) ;
return V_89 ;
}
static int F_43 ( struct V_19 * V_5 )
{
struct V_2 * V_3 =
F_14 ( V_5 , struct V_2 , V_5 ) ;
unsigned long V_20 ;
int V_90 ;
V_90 = F_44 ( V_3 -> V_5 . V_83 , F_42 ,
V_3 -> V_5 . V_91 , F_45 ( V_3 -> V_5 . V_92 ) , V_3 ) ;
if ( V_90 )
return V_90 ;
F_15 ( & V_3 -> V_5 . V_21 , V_20 ) ;
F_8 ( V_3 , V_27 ,
V_64 ) ;
V_3 -> V_11 = V_25 ;
F_5 ( V_3 , V_13 , V_3 -> V_11 ) ;
F_16 ( & V_3 -> V_5 . V_21 , V_20 ) ;
return 0 ;
}
static void F_46 ( struct V_19 * V_5 )
{
struct V_2 * V_3 =
F_14 ( V_5 , struct V_2 , V_5 ) ;
V_3 -> V_11 = 0 ;
F_5 ( V_3 , V_13 , V_3 -> V_11 ) ;
F_9 ( V_3 , V_27 ,
V_28 ) ;
F_47 ( V_3 -> V_5 . V_83 , V_3 ) ;
}
static const char * F_48 ( struct V_19 * V_5 )
{
return ( V_5 -> type == V_93 ) ? L_1 : NULL ;
}
static void F_49 ( struct V_19 * V_5 )
{
}
static int F_50 ( struct V_19 * V_5 )
{
return 0 ;
}
static void F_51 ( struct V_19 * V_5 , int V_20 )
{
if ( V_20 & V_94 )
V_5 -> type = V_93 ;
}
static int F_52 ( struct V_19 * V_5 ,
struct V_95 * V_96 )
{
struct V_2 * V_3 =
F_14 ( V_5 , struct V_2 , V_5 ) ;
if ( V_96 -> type != V_97 &&
V_96 -> type != V_93 )
return - V_98 ;
if ( V_96 -> V_83 < 0 || V_96 -> V_83 >= V_99 )
return - V_98 ;
if ( V_96 -> V_100 < V_3 -> V_53 ||
V_96 -> V_100 > V_3 -> V_54 )
return - V_98 ;
return 0 ;
}
static void F_53 ( struct V_2 * V_3 )
{
unsigned int V_85 ;
unsigned int V_101 = 60000 ;
do {
V_85 = F_3 ( V_3 , V_18 ) ;
if ( -- V_101 == 0 )
break;
F_54 ( 1 ) ;
} while ( ( V_85 & V_17 ) == 0 );
}
static void F_55 ( struct V_19 * V_5 , int V_14 )
{
struct V_2 * V_3 =
F_14 ( V_5 , struct V_2 , V_5 ) ;
F_53 ( V_3 ) ;
F_12 ( V_3 , V_14 ) ;
}
static void F_56 ( struct V_102 * V_103 , const char * V_104 ,
unsigned int V_75 )
{
struct V_2 * V_3 = V_105 [ V_103 -> V_106 ] ;
unsigned long V_20 ;
unsigned int V_107 ;
int V_108 = 1 ;
F_57 ( V_20 ) ;
if ( V_3 -> V_5 . V_109 )
V_108 = 0 ;
else if ( V_110 )
V_108 = F_58 ( & V_3 -> V_5 . V_21 ) ;
else
F_36 ( & V_3 -> V_5 . V_21 ) ;
V_107 = F_3 ( V_3 , V_13 ) ;
F_5 ( V_3 , V_13 , 0 ) ;
F_59 ( & V_3 -> V_5 , V_104 , V_75 , F_55 ) ;
F_53 ( V_3 ) ;
F_5 ( V_3 , V_13 , V_107 ) ;
F_5 ( V_3 , V_88 , V_111 ) ;
if ( V_108 )
F_34 ( & V_3 -> V_5 . V_21 ) ;
F_60 ( V_20 ) ;
}
static int F_61 ( struct V_102 * V_103 , char * V_112 )
{
struct V_2 * V_3 ;
int V_32 = 115200 ;
int V_113 = 8 ;
int V_114 = 'n' ;
int V_115 = 'n' ;
if ( V_103 -> V_106 < 0 || V_103 -> V_106 >= V_116 )
return - V_98 ;
V_3 = V_105 [ V_103 -> V_106 ] ;
if ( ! V_3 )
return - V_117 ;
if ( V_112 )
F_62 ( V_112 , & V_32 , & V_114 , & V_113 , & V_115 ) ;
return F_63 ( & V_3 -> V_5 , V_103 , V_32 , V_114 , V_113 , V_115 ) ;
}
static void F_64 ( struct V_2 * V_3 )
{
if ( ! F_1 () )
return;
V_105 [ V_3 -> V_5 . line ] = V_3 ;
}
static int F_65 ( struct V_118 * V_119 )
{
struct V_2 * V_3 ;
struct V_19 * V_5 ;
struct V_120 * V_121 ;
struct V_120 * V_122 ;
struct V_123 * V_124 ;
unsigned int V_32 ;
int V_125 ;
int V_90 ;
V_124 = V_119 -> V_92 . V_126 ;
if ( F_2 ( V_127 ) && V_124 ) {
V_125 = F_66 ( V_124 , L_2 ) ;
if ( V_125 < 0 ) {
F_67 ( & V_119 -> V_92 , L_3 ,
V_125 ) ;
return V_125 ;
}
} else {
V_125 = V_119 -> V_125 ;
if ( V_125 == - 1 )
V_125 = 0 ;
}
if ( V_125 >= V_116 )
return - V_98 ;
V_122 = F_68 ( V_119 , V_128 , 0 ) ;
if ( ! V_122 ) {
F_67 ( & V_119 -> V_92 , L_4 ) ;
return - V_98 ;
}
V_3 = F_69 ( & V_119 -> V_92 , sizeof( struct V_2 ) ,
V_129 ) ;
if ( ! V_3 )
return - V_130 ;
V_3 -> V_29 = F_70 ( & V_119 -> V_92 , L_5 ) ;
if ( F_71 ( V_3 -> V_29 ) ) {
F_67 ( & V_119 -> V_92 , L_6 ) ;
return F_72 ( V_3 -> V_29 ) ;
}
V_5 = & V_3 -> V_5 ;
V_121 = F_68 ( V_119 , V_131 , 0 ) ;
V_5 -> V_6 = F_73 ( & V_119 -> V_92 , V_121 ) ;
if ( F_71 ( V_5 -> V_6 ) )
return F_72 ( V_5 -> V_6 ) ;
V_90 = F_74 ( V_3 -> V_29 ) ;
if ( V_90 )
return V_90 ;
V_5 -> V_55 = F_75 ( V_3 -> V_29 ) ;
if ( ! V_5 -> V_55 ) {
V_90 = - V_98 ;
goto V_132;
}
V_5 -> V_133 = V_121 -> V_134 ;
V_5 -> line = V_125 ;
V_5 -> V_83 = V_122 -> V_134 ;
V_5 -> V_92 = & V_119 -> V_92 ;
V_5 -> type = V_93 ;
V_5 -> V_135 = V_136 ;
V_5 -> V_137 = 2 ;
V_5 -> V_76 = V_138 ;
V_5 -> V_139 = & V_140 ;
V_32 = F_23 ( V_5 -> V_55 , V_35 , 1 ) ;
V_3 -> V_53 = F_76 (unsigned int, baud, AR933X_UART_MIN_BAUD) ;
V_32 = F_23 ( V_5 -> V_55 , 0 , V_38 ) ;
V_3 -> V_54 = F_77 (unsigned int, baud, AR933X_UART_MAX_BAUD) ;
F_64 ( V_3 ) ;
V_90 = F_78 ( & V_141 , & V_3 -> V_5 ) ;
if ( V_90 )
goto V_132;
F_79 ( V_119 , V_3 ) ;
return 0 ;
V_132:
F_80 ( V_3 -> V_29 ) ;
return V_90 ;
}
static int F_81 ( struct V_118 * V_119 )
{
struct V_2 * V_3 ;
V_3 = F_82 ( V_119 ) ;
if ( V_3 ) {
F_83 ( & V_141 , & V_3 -> V_5 ) ;
F_80 ( V_3 -> V_29 ) ;
}
return 0 ;
}
static int T_4 F_84 ( void )
{
int V_90 ;
if ( F_1 () )
V_141 . V_142 = & V_143 ;
V_90 = F_85 ( & V_141 ) ;
if ( V_90 )
goto V_144;
V_90 = F_86 ( & V_145 ) ;
if ( V_90 )
goto V_146;
return 0 ;
V_146:
F_87 ( & V_141 ) ;
V_144:
return V_90 ;
}
static void T_5 F_88 ( void )
{
F_89 ( & V_145 ) ;
F_87 ( & V_141 ) ;
}
