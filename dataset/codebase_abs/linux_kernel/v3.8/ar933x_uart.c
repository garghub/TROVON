static inline unsigned int F_1 ( struct V_1 * V_2 ,
int V_3 )
{
return F_2 ( V_2 -> V_4 . V_5 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
int V_3 , unsigned int V_6 )
{
F_4 ( V_6 , V_2 -> V_4 . V_5 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_7 ,
unsigned int V_8 )
{
unsigned int V_9 ;
V_9 = F_1 ( V_2 , V_3 ) ;
V_9 &= ~ V_7 ;
V_9 |= V_8 ;
F_3 ( V_2 , V_3 , V_9 ) ;
}
static inline void F_6 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_8 )
{
F_5 ( V_2 , V_3 , 0 , V_8 ) ;
}
static inline void F_7 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_8 )
{
F_5 ( V_2 , V_3 , V_8 , 0 ) ;
}
static inline void F_8 ( struct V_1 * V_2 )
{
V_2 -> V_10 |= V_11 ;
F_3 ( V_2 , V_12 , V_2 -> V_10 ) ;
}
static inline void F_9 ( struct V_1 * V_2 )
{
V_2 -> V_10 &= ~ V_11 ;
F_3 ( V_2 , V_12 , V_2 -> V_10 ) ;
}
static inline void F_10 ( struct V_1 * V_2 , int V_13 )
{
unsigned int V_14 ;
V_14 = V_13 & V_15 ;
V_14 |= V_16 ;
F_3 ( V_2 , V_17 , V_14 ) ;
}
static unsigned int F_11 ( struct V_18 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned long V_19 ;
unsigned int V_14 ;
F_12 ( & V_2 -> V_4 . V_20 , V_19 ) ;
V_14 = F_1 ( V_2 , V_17 ) ;
F_13 ( & V_2 -> V_4 . V_20 , V_19 ) ;
return ( V_14 & V_16 ) ? 0 : V_21 ;
}
static unsigned int F_14 ( struct V_18 * V_4 )
{
return V_22 ;
}
static void F_15 ( struct V_18 * V_4 , unsigned int V_23 )
{
}
static void F_16 ( struct V_18 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
F_8 ( V_2 ) ;
}
static void F_17 ( struct V_18 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
F_9 ( V_2 ) ;
}
static void F_18 ( struct V_18 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
V_2 -> V_10 &= ~ V_24 ;
F_3 ( V_2 , V_12 , V_2 -> V_10 ) ;
}
static void F_19 ( struct V_18 * V_4 , int V_25 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned long V_19 ;
F_12 ( & V_2 -> V_4 . V_20 , V_19 ) ;
if ( V_25 == - 1 )
F_6 ( V_2 , V_26 ,
V_27 ) ;
else
F_7 ( V_2 , V_26 ,
V_27 ) ;
F_13 ( & V_2 -> V_4 . V_20 , V_19 ) ;
}
static void F_20 ( struct V_18 * V_4 )
{
}
static unsigned long F_21 ( unsigned int V_28 ,
unsigned int V_29 ,
unsigned int V_30 )
{
T_1 V_9 ;
T_2 div ;
div = ( 2 << 16 ) * ( V_29 + 1 ) ;
V_9 = V_28 ;
V_9 *= V_30 ;
V_9 += ( div / 2 ) ;
F_22 ( V_9 , div ) ;
return V_9 ;
}
static void F_23 ( unsigned int V_28 ,
unsigned int V_31 ,
unsigned int * V_29 ,
unsigned int * V_30 )
{
unsigned int V_32 ;
long V_33 ;
* V_29 = 0 ;
* V_30 = 0 ;
V_33 = V_31 ;
for ( V_32 = 0 ; V_32 < V_34 ; V_32 ++ ) {
T_1 V_35 ;
int V_36 ;
V_35 = V_31 * ( V_32 + 1 ) ;
V_35 *= ( 2 << 16 ) ;
F_22 ( V_35 , V_28 ) ;
if ( V_35 > V_37 )
break;
V_36 = abs ( F_21 ( V_28 , V_32 , V_35 ) - V_31 ) ;
if ( V_36 < V_33 ) {
V_33 = V_36 ;
* V_29 = V_32 ;
* V_30 = V_35 ;
}
}
}
static void F_24 ( struct V_18 * V_4 ,
struct V_38 * V_39 ,
struct V_38 * V_40 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned int V_41 ;
unsigned long V_19 ;
unsigned int V_31 , V_29 , V_30 ;
V_39 -> V_42 &= ~ V_43 ;
V_39 -> V_42 |= V_44 ;
V_39 -> V_42 &= ~ V_45 ;
V_41 = 0 ;
if ( V_39 -> V_42 & V_46 ) {
if ( ! ( V_39 -> V_42 & V_47 ) )
V_41 |= V_48 ;
else
V_41 |= V_49 ;
} else {
V_41 |= V_50 ;
}
V_39 -> V_42 &= ~ V_51 ;
V_31 = F_25 ( V_4 , V_39 , V_40 , V_2 -> V_52 , V_2 -> V_53 ) ;
F_23 ( V_4 -> V_54 , V_31 , & V_29 , & V_30 ) ;
F_12 ( & V_2 -> V_4 . V_20 , V_19 ) ;
F_7 ( V_2 , V_26 ,
V_55 << V_56 ) ;
F_26 ( V_4 , V_39 -> V_42 , V_31 ) ;
V_2 -> V_4 . V_57 = 0 ;
if ( ( V_39 -> V_42 & V_58 ) == 0 )
V_2 -> V_4 . V_57 |= V_59 ;
F_3 ( V_2 , V_60 ,
V_29 << V_61 | V_30 ) ;
F_5 ( V_2 , V_26 , V_62 , V_41 ) ;
F_6 ( V_2 , V_26 ,
V_63 ) ;
F_5 ( V_2 , V_26 ,
V_55 << V_56 ,
V_64 << V_56 ) ;
F_13 ( & V_2 -> V_4 . V_20 , V_19 ) ;
if ( F_27 ( V_39 ) )
F_28 ( V_39 , V_31 , V_31 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_65 * V_66 ;
int V_67 = 256 ;
V_66 = F_30 ( & V_2 -> V_4 . V_68 -> V_4 ) ;
do {
unsigned int V_14 ;
unsigned char V_13 ;
V_14 = F_1 ( V_2 , V_17 ) ;
if ( ( V_14 & V_69 ) == 0 )
break;
F_3 ( V_2 , V_17 ,
V_69 ) ;
if ( ! V_66 ) {
continue;
}
V_2 -> V_4 . V_70 . V_71 ++ ;
V_13 = V_14 & V_15 ;
if ( F_31 ( & V_2 -> V_4 , V_13 ) )
continue;
if ( ( V_2 -> V_4 . V_57 & V_59 ) == 0 )
F_32 ( V_66 , V_13 , V_72 ) ;
} while ( V_67 -- > 0 );
if ( V_66 ) {
F_33 ( V_66 ) ;
F_34 ( V_66 ) ;
}
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_73 * V_74 = & V_2 -> V_4 . V_68 -> V_74 ;
int V_75 ;
if ( F_36 ( & V_2 -> V_4 ) )
return;
V_75 = V_2 -> V_4 . V_76 ;
do {
unsigned int V_14 ;
V_14 = F_1 ( V_2 , V_17 ) ;
if ( ( V_14 & V_16 ) == 0 )
break;
if ( V_2 -> V_4 . V_77 ) {
F_10 ( V_2 , V_2 -> V_4 . V_77 ) ;
V_2 -> V_4 . V_70 . V_78 ++ ;
V_2 -> V_4 . V_77 = 0 ;
continue;
}
if ( F_37 ( V_74 ) )
break;
F_10 ( V_2 , V_74 -> V_79 [ V_74 -> V_80 ] ) ;
V_74 -> V_80 = ( V_74 -> V_80 + 1 ) & ( V_81 - 1 ) ;
V_2 -> V_4 . V_70 . V_78 ++ ;
} while ( -- V_75 > 0 );
if ( F_38 ( V_74 ) < V_82 )
F_39 ( & V_2 -> V_4 ) ;
if ( ! F_37 ( V_74 ) )
F_8 ( V_2 ) ;
}
static T_3 F_40 ( int V_83 , void * V_84 )
{
struct V_1 * V_2 = V_84 ;
unsigned int V_85 ;
V_85 = F_1 ( V_2 , V_26 ) ;
if ( ( V_85 & V_86 ) == 0 )
return V_87 ;
F_41 ( & V_2 -> V_4 . V_20 ) ;
V_85 = F_1 ( V_2 , V_88 ) ;
V_85 &= F_1 ( V_2 , V_12 ) ;
if ( V_85 & V_24 ) {
F_3 ( V_2 , V_88 ,
V_24 ) ;
F_29 ( V_2 ) ;
}
if ( V_85 & V_11 ) {
F_3 ( V_2 , V_88 ,
V_11 ) ;
F_9 ( V_2 ) ;
F_35 ( V_2 ) ;
}
F_42 ( & V_2 -> V_4 . V_20 ) ;
return V_89 ;
}
static int F_43 ( struct V_18 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned long V_19 ;
int V_90 ;
V_90 = F_44 ( V_2 -> V_4 . V_83 , F_40 ,
V_2 -> V_4 . V_91 , F_45 ( V_2 -> V_4 . V_92 ) , V_2 ) ;
if ( V_90 )
return V_90 ;
F_12 ( & V_2 -> V_4 . V_20 , V_19 ) ;
F_6 ( V_2 , V_26 ,
V_63 ) ;
V_2 -> V_10 = V_24 ;
F_3 ( V_2 , V_12 , V_2 -> V_10 ) ;
F_13 ( & V_2 -> V_4 . V_20 , V_19 ) ;
return 0 ;
}
static void F_46 ( struct V_18 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
V_2 -> V_10 = 0 ;
F_3 ( V_2 , V_12 , V_2 -> V_10 ) ;
F_7 ( V_2 , V_26 ,
V_27 ) ;
F_47 ( V_2 -> V_4 . V_83 , V_2 ) ;
}
static const char * F_48 ( struct V_18 * V_4 )
{
return ( V_4 -> type == V_93 ) ? L_1 : NULL ;
}
static void F_49 ( struct V_18 * V_4 )
{
}
static int F_50 ( struct V_18 * V_4 )
{
return 0 ;
}
static void F_51 ( struct V_18 * V_4 , int V_19 )
{
if ( V_19 & V_94 )
V_4 -> type = V_93 ;
}
static int F_52 ( struct V_18 * V_4 ,
struct V_95 * V_96 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
if ( V_96 -> type != V_97 &&
V_96 -> type != V_93 )
return - V_98 ;
if ( V_96 -> V_83 < 0 || V_96 -> V_83 >= V_99 )
return - V_98 ;
if ( V_96 -> V_100 < V_2 -> V_52 ||
V_96 -> V_100 > V_2 -> V_53 )
return - V_98 ;
return 0 ;
}
static void F_53 ( struct V_1 * V_2 )
{
unsigned int V_85 ;
unsigned int V_101 = 60000 ;
do {
V_85 = F_1 ( V_2 , V_17 ) ;
if ( -- V_101 == 0 )
break;
F_54 ( 1 ) ;
} while ( ( V_85 & V_16 ) == 0 );
}
static void F_55 ( struct V_18 * V_4 , int V_13 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
F_53 ( V_2 ) ;
F_10 ( V_2 , V_13 ) ;
}
static void F_56 ( struct V_102 * V_103 , const char * V_104 ,
unsigned int V_75 )
{
struct V_1 * V_2 = V_105 [ V_103 -> V_106 ] ;
unsigned long V_19 ;
unsigned int V_107 ;
int V_108 = 1 ;
F_57 ( V_19 ) ;
if ( V_2 -> V_4 . V_109 )
V_108 = 0 ;
else if ( V_110 )
V_108 = F_58 ( & V_2 -> V_4 . V_20 ) ;
else
F_41 ( & V_2 -> V_4 . V_20 ) ;
V_107 = F_1 ( V_2 , V_12 ) ;
F_3 ( V_2 , V_12 , 0 ) ;
F_59 ( & V_2 -> V_4 , V_104 , V_75 , F_55 ) ;
F_53 ( V_2 ) ;
F_3 ( V_2 , V_12 , V_107 ) ;
F_3 ( V_2 , V_88 , V_111 ) ;
if ( V_108 )
F_42 ( & V_2 -> V_4 . V_20 ) ;
F_60 ( V_19 ) ;
}
static int F_61 ( struct V_102 * V_103 , char * V_112 )
{
struct V_1 * V_2 ;
int V_31 = 115200 ;
int V_113 = 8 ;
int V_114 = 'n' ;
int V_115 = 'n' ;
if ( V_103 -> V_106 < 0 || V_103 -> V_106 >= V_116 )
return - V_98 ;
V_2 = V_105 [ V_103 -> V_106 ] ;
if ( ! V_2 )
return - V_117 ;
if ( V_112 )
F_62 ( V_112 , & V_31 , & V_114 , & V_113 , & V_115 ) ;
return F_63 ( & V_2 -> V_4 , V_103 , V_31 , V_114 , V_113 , V_115 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
V_105 [ V_2 -> V_4 . line ] = V_2 ;
}
static inline void F_64 ( struct V_1 * V_2 ) {}
static int F_65 ( struct V_118 * V_119 )
{
struct V_120 * V_121 ;
struct V_1 * V_2 ;
struct V_18 * V_4 ;
struct V_122 * V_123 ;
struct V_122 * V_124 ;
unsigned int V_31 ;
int V_125 ;
int V_90 ;
V_121 = V_119 -> V_92 . V_126 ;
if ( ! V_121 )
return - V_98 ;
V_125 = V_119 -> V_125 ;
if ( V_125 == - 1 )
V_125 = 0 ;
if ( V_125 > V_116 )
return - V_98 ;
V_123 = F_66 ( V_119 , V_127 , 0 ) ;
if ( ! V_123 ) {
F_67 ( & V_119 -> V_92 , L_2 ) ;
return - V_98 ;
}
V_124 = F_66 ( V_119 , V_128 , 0 ) ;
if ( ! V_124 ) {
F_67 ( & V_119 -> V_92 , L_3 ) ;
return - V_98 ;
}
V_2 = F_68 ( sizeof( struct V_1 ) , V_129 ) ;
if ( ! V_2 )
return - V_130 ;
V_4 = & V_2 -> V_4 ;
V_4 -> V_131 = V_123 -> V_132 ;
V_4 -> V_5 = F_69 ( V_123 -> V_132 , V_133 ) ;
if ( ! V_4 -> V_5 ) {
V_90 = - V_130 ;
goto V_134;
}
V_4 -> line = V_125 ;
V_4 -> V_83 = V_124 -> V_132 ;
V_4 -> V_92 = & V_119 -> V_92 ;
V_4 -> type = V_93 ;
V_4 -> V_135 = V_136 ;
V_4 -> V_54 = V_121 -> V_54 ;
V_4 -> V_137 = 2 ;
V_4 -> V_76 = V_138 ;
V_4 -> V_139 = & V_140 ;
V_31 = F_21 ( V_4 -> V_54 , V_34 , 1 ) ;
V_2 -> V_52 = F_70 (unsigned int, baud, AR933X_UART_MIN_BAUD) ;
V_31 = F_21 ( V_4 -> V_54 , 0 , V_37 ) ;
V_2 -> V_53 = F_71 (unsigned int, baud, AR933X_UART_MAX_BAUD) ;
F_64 ( V_2 ) ;
V_90 = F_72 ( & V_141 , & V_2 -> V_4 ) ;
if ( V_90 )
goto V_142;
F_73 ( V_119 , V_2 ) ;
return 0 ;
V_142:
F_74 ( V_2 -> V_4 . V_5 ) ;
V_134:
F_75 ( V_2 ) ;
return V_90 ;
}
static int F_76 ( struct V_118 * V_119 )
{
struct V_1 * V_2 ;
V_2 = F_77 ( V_119 ) ;
F_73 ( V_119 , NULL ) ;
if ( V_2 ) {
F_78 ( & V_141 , & V_2 -> V_4 ) ;
F_74 ( V_2 -> V_4 . V_5 ) ;
F_75 ( V_2 ) ;
}
return 0 ;
}
static int T_4 F_79 ( void )
{
int V_90 ;
V_141 . V_143 = V_116 ;
V_90 = F_80 ( & V_141 ) ;
if ( V_90 )
goto V_144;
V_90 = F_81 ( & V_145 ) ;
if ( V_90 )
goto V_146;
return 0 ;
V_146:
F_82 ( & V_141 ) ;
V_144:
return V_90 ;
}
static void T_5 F_83 ( void )
{
F_84 ( & V_145 ) ;
F_82 ( & V_141 ) ;
}
