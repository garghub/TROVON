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
struct V_65 * V_4 = & V_2 -> V_4 . V_66 -> V_4 ;
int V_67 = 256 ;
do {
unsigned int V_14 ;
unsigned char V_13 ;
V_14 = F_1 ( V_2 , V_17 ) ;
if ( ( V_14 & V_68 ) == 0 )
break;
F_3 ( V_2 , V_17 ,
V_68 ) ;
V_2 -> V_4 . V_69 . V_70 ++ ;
V_13 = V_14 & V_15 ;
if ( F_30 ( & V_2 -> V_4 , V_13 ) )
continue;
if ( ( V_2 -> V_4 . V_57 & V_59 ) == 0 )
F_31 ( V_4 , V_13 , V_71 ) ;
} while ( V_67 -- > 0 );
F_32 ( V_4 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_72 * V_73 = & V_2 -> V_4 . V_66 -> V_73 ;
int V_74 ;
if ( F_34 ( & V_2 -> V_4 ) )
return;
V_74 = V_2 -> V_4 . V_75 ;
do {
unsigned int V_14 ;
V_14 = F_1 ( V_2 , V_17 ) ;
if ( ( V_14 & V_16 ) == 0 )
break;
if ( V_2 -> V_4 . V_76 ) {
F_10 ( V_2 , V_2 -> V_4 . V_76 ) ;
V_2 -> V_4 . V_69 . V_77 ++ ;
V_2 -> V_4 . V_76 = 0 ;
continue;
}
if ( F_35 ( V_73 ) )
break;
F_10 ( V_2 , V_73 -> V_78 [ V_73 -> V_79 ] ) ;
V_73 -> V_79 = ( V_73 -> V_79 + 1 ) & ( V_80 - 1 ) ;
V_2 -> V_4 . V_69 . V_77 ++ ;
} while ( -- V_74 > 0 );
if ( F_36 ( V_73 ) < V_81 )
F_37 ( & V_2 -> V_4 ) ;
if ( ! F_35 ( V_73 ) )
F_8 ( V_2 ) ;
}
static T_3 F_38 ( int V_82 , void * V_83 )
{
struct V_1 * V_2 = V_83 ;
unsigned int V_84 ;
V_84 = F_1 ( V_2 , V_26 ) ;
if ( ( V_84 & V_85 ) == 0 )
return V_86 ;
F_39 ( & V_2 -> V_4 . V_20 ) ;
V_84 = F_1 ( V_2 , V_87 ) ;
V_84 &= F_1 ( V_2 , V_12 ) ;
if ( V_84 & V_24 ) {
F_3 ( V_2 , V_87 ,
V_24 ) ;
F_29 ( V_2 ) ;
}
if ( V_84 & V_11 ) {
F_3 ( V_2 , V_87 ,
V_11 ) ;
F_9 ( V_2 ) ;
F_33 ( V_2 ) ;
}
F_40 ( & V_2 -> V_4 . V_20 ) ;
return V_88 ;
}
static int F_41 ( struct V_18 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned long V_19 ;
int V_89 ;
V_89 = F_42 ( V_2 -> V_4 . V_82 , F_38 ,
V_2 -> V_4 . V_90 , F_43 ( V_2 -> V_4 . V_91 ) , V_2 ) ;
if ( V_89 )
return V_89 ;
F_12 ( & V_2 -> V_4 . V_20 , V_19 ) ;
F_6 ( V_2 , V_26 ,
V_63 ) ;
V_2 -> V_10 = V_24 ;
F_3 ( V_2 , V_12 , V_2 -> V_10 ) ;
F_13 ( & V_2 -> V_4 . V_20 , V_19 ) ;
return 0 ;
}
static void F_44 ( struct V_18 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
V_2 -> V_10 = 0 ;
F_3 ( V_2 , V_12 , V_2 -> V_10 ) ;
F_7 ( V_2 , V_26 ,
V_27 ) ;
F_45 ( V_2 -> V_4 . V_82 , V_2 ) ;
}
static const char * F_46 ( struct V_18 * V_4 )
{
return ( V_4 -> type == V_92 ) ? L_1 : NULL ;
}
static void F_47 ( struct V_18 * V_4 )
{
}
static int F_48 ( struct V_18 * V_4 )
{
return 0 ;
}
static void F_49 ( struct V_18 * V_4 , int V_19 )
{
if ( V_19 & V_93 )
V_4 -> type = V_92 ;
}
static int F_50 ( struct V_18 * V_4 ,
struct V_94 * V_95 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
if ( V_95 -> type != V_96 &&
V_95 -> type != V_92 )
return - V_97 ;
if ( V_95 -> V_82 < 0 || V_95 -> V_82 >= V_98 )
return - V_97 ;
if ( V_95 -> V_99 < V_2 -> V_52 ||
V_95 -> V_99 > V_2 -> V_53 )
return - V_97 ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 )
{
unsigned int V_84 ;
unsigned int V_100 = 60000 ;
do {
V_84 = F_1 ( V_2 , V_17 ) ;
if ( -- V_100 == 0 )
break;
F_52 ( 1 ) ;
} while ( ( V_84 & V_16 ) == 0 );
}
static void F_53 ( struct V_18 * V_4 , int V_13 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
F_51 ( V_2 ) ;
F_10 ( V_2 , V_13 ) ;
}
static void F_54 ( struct V_101 * V_102 , const char * V_103 ,
unsigned int V_74 )
{
struct V_1 * V_2 = V_104 [ V_102 -> V_105 ] ;
unsigned long V_19 ;
unsigned int V_106 ;
int V_107 = 1 ;
F_55 ( V_19 ) ;
if ( V_2 -> V_4 . V_108 )
V_107 = 0 ;
else if ( V_109 )
V_107 = F_56 ( & V_2 -> V_4 . V_20 ) ;
else
F_39 ( & V_2 -> V_4 . V_20 ) ;
V_106 = F_1 ( V_2 , V_12 ) ;
F_3 ( V_2 , V_12 , 0 ) ;
F_57 ( & V_2 -> V_4 , V_103 , V_74 , F_53 ) ;
F_51 ( V_2 ) ;
F_3 ( V_2 , V_12 , V_106 ) ;
F_3 ( V_2 , V_87 , V_110 ) ;
if ( V_107 )
F_40 ( & V_2 -> V_4 . V_20 ) ;
F_58 ( V_19 ) ;
}
static int F_59 ( struct V_101 * V_102 , char * V_111 )
{
struct V_1 * V_2 ;
int V_31 = 115200 ;
int V_112 = 8 ;
int V_113 = 'n' ;
int V_114 = 'n' ;
if ( V_102 -> V_105 < 0 || V_102 -> V_105 >= V_115 )
return - V_97 ;
V_2 = V_104 [ V_102 -> V_105 ] ;
if ( ! V_2 )
return - V_116 ;
if ( V_111 )
F_60 ( V_111 , & V_31 , & V_113 , & V_112 , & V_114 ) ;
return F_61 ( & V_2 -> V_4 , V_102 , V_31 , V_113 , V_112 , V_114 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
V_104 [ V_2 -> V_4 . line ] = V_2 ;
}
static inline void F_62 ( struct V_1 * V_2 ) {}
static int F_63 ( struct V_117 * V_118 )
{
struct V_119 * V_120 ;
struct V_1 * V_2 ;
struct V_18 * V_4 ;
struct V_121 * V_122 ;
struct V_121 * V_123 ;
unsigned int V_31 ;
int V_124 ;
int V_89 ;
V_120 = V_118 -> V_91 . V_125 ;
if ( ! V_120 )
return - V_97 ;
V_124 = V_118 -> V_124 ;
if ( V_124 == - 1 )
V_124 = 0 ;
if ( V_124 > V_115 )
return - V_97 ;
V_122 = F_64 ( V_118 , V_126 , 0 ) ;
if ( ! V_122 ) {
F_65 ( & V_118 -> V_91 , L_2 ) ;
return - V_97 ;
}
V_123 = F_64 ( V_118 , V_127 , 0 ) ;
if ( ! V_123 ) {
F_65 ( & V_118 -> V_91 , L_3 ) ;
return - V_97 ;
}
V_2 = F_66 ( sizeof( struct V_1 ) , V_128 ) ;
if ( ! V_2 )
return - V_129 ;
V_4 = & V_2 -> V_4 ;
V_4 -> V_130 = V_122 -> V_131 ;
V_4 -> V_5 = F_67 ( V_122 -> V_131 , V_132 ) ;
if ( ! V_4 -> V_5 ) {
V_89 = - V_129 ;
goto V_133;
}
V_4 -> line = V_124 ;
V_4 -> V_82 = V_123 -> V_131 ;
V_4 -> V_91 = & V_118 -> V_91 ;
V_4 -> type = V_92 ;
V_4 -> V_134 = V_135 ;
V_4 -> V_54 = V_120 -> V_54 ;
V_4 -> V_136 = 2 ;
V_4 -> V_75 = V_137 ;
V_4 -> V_138 = & V_139 ;
V_31 = F_21 ( V_4 -> V_54 , V_34 , 1 ) ;
V_2 -> V_52 = F_68 (unsigned int, baud, AR933X_UART_MIN_BAUD) ;
V_31 = F_21 ( V_4 -> V_54 , 0 , V_37 ) ;
V_2 -> V_53 = F_69 (unsigned int, baud, AR933X_UART_MAX_BAUD) ;
F_62 ( V_2 ) ;
V_89 = F_70 ( & V_140 , & V_2 -> V_4 ) ;
if ( V_89 )
goto V_141;
F_71 ( V_118 , V_2 ) ;
return 0 ;
V_141:
F_72 ( V_2 -> V_4 . V_5 ) ;
V_133:
F_73 ( V_2 ) ;
return V_89 ;
}
static int F_74 ( struct V_117 * V_118 )
{
struct V_1 * V_2 ;
V_2 = F_75 ( V_118 ) ;
F_71 ( V_118 , NULL ) ;
if ( V_2 ) {
F_76 ( & V_140 , & V_2 -> V_4 ) ;
F_72 ( V_2 -> V_4 . V_5 ) ;
F_73 ( V_2 ) ;
}
return 0 ;
}
static int T_4 F_77 ( void )
{
int V_89 ;
V_140 . V_142 = V_115 ;
V_89 = F_78 ( & V_140 ) ;
if ( V_89 )
goto V_143;
V_89 = F_79 ( & V_144 ) ;
if ( V_89 )
goto V_145;
return 0 ;
V_145:
F_80 ( & V_140 ) ;
V_143:
return V_89 ;
}
static void T_5 F_81 ( void )
{
F_82 ( & V_144 ) ;
F_80 ( & V_140 ) ;
}
