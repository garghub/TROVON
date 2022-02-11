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
static void F_21 ( struct V_18 * V_4 ,
struct V_28 * V_29 ,
struct V_28 * V_30 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned int V_31 ;
unsigned long V_19 ;
unsigned int V_32 , V_33 ;
V_29 -> V_34 &= ~ V_35 ;
V_29 -> V_34 |= V_36 ;
V_29 -> V_34 &= ~ V_37 ;
V_31 = 0 ;
if ( V_29 -> V_34 & V_38 ) {
if ( ! ( V_29 -> V_34 & V_39 ) )
V_31 |= V_40 ;
else
V_31 |= V_41 ;
} else {
V_31 |= V_42 ;
}
V_29 -> V_34 &= ~ V_43 ;
V_32 = F_22 ( V_4 , V_29 , V_30 , 0 , V_4 -> V_44 / 16 ) ;
V_33 = ( V_4 -> V_44 / ( 16 * V_32 ) ) - 1 ;
F_12 ( & V_2 -> V_4 . V_20 , V_19 ) ;
F_23 ( V_4 , V_29 -> V_34 , V_32 ) ;
V_2 -> V_4 . V_45 = 0 ;
if ( ( V_29 -> V_34 & V_46 ) == 0 )
V_2 -> V_4 . V_45 |= V_47 ;
F_3 ( V_2 , V_48 ,
V_33 << V_49 | 8192 ) ;
F_5 ( V_2 , V_26 , V_50 , V_31 ) ;
F_6 ( V_2 , V_26 ,
V_51 ) ;
F_13 ( & V_2 -> V_4 . V_20 , V_19 ) ;
if ( F_24 ( V_29 ) )
F_25 ( V_29 , V_32 , V_32 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_52 * V_53 ;
int V_54 = 256 ;
V_53 = F_27 ( & V_2 -> V_4 . V_55 -> V_4 ) ;
do {
unsigned int V_14 ;
unsigned char V_13 ;
V_14 = F_1 ( V_2 , V_17 ) ;
if ( ( V_14 & V_56 ) == 0 )
break;
F_3 ( V_2 , V_17 ,
V_56 ) ;
if ( ! V_53 ) {
continue;
}
V_2 -> V_4 . V_57 . V_58 ++ ;
V_13 = V_14 & V_15 ;
if ( F_28 ( & V_2 -> V_4 , V_13 ) )
continue;
if ( ( V_2 -> V_4 . V_45 & V_47 ) == 0 )
F_29 ( V_53 , V_13 , V_59 ) ;
} while ( V_54 -- > 0 );
if ( V_53 ) {
F_30 ( V_53 ) ;
F_31 ( V_53 ) ;
}
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_60 * V_61 = & V_2 -> V_4 . V_55 -> V_61 ;
int V_62 ;
if ( F_33 ( & V_2 -> V_4 ) )
return;
V_62 = V_2 -> V_4 . V_63 ;
do {
unsigned int V_14 ;
V_14 = F_1 ( V_2 , V_17 ) ;
if ( ( V_14 & V_16 ) == 0 )
break;
if ( V_2 -> V_4 . V_64 ) {
F_10 ( V_2 , V_2 -> V_4 . V_64 ) ;
V_2 -> V_4 . V_57 . V_65 ++ ;
V_2 -> V_4 . V_64 = 0 ;
continue;
}
if ( F_34 ( V_61 ) )
break;
F_10 ( V_2 , V_61 -> V_66 [ V_61 -> V_67 ] ) ;
V_61 -> V_67 = ( V_61 -> V_67 + 1 ) & ( V_68 - 1 ) ;
V_2 -> V_4 . V_57 . V_65 ++ ;
} while ( -- V_62 > 0 );
if ( F_35 ( V_61 ) < V_69 )
F_36 ( & V_2 -> V_4 ) ;
if ( ! F_34 ( V_61 ) )
F_8 ( V_2 ) ;
}
static T_1 F_37 ( int V_70 , void * V_71 )
{
struct V_1 * V_2 = V_71 ;
unsigned int V_72 ;
V_72 = F_1 ( V_2 , V_26 ) ;
if ( ( V_72 & V_73 ) == 0 )
return V_74 ;
F_38 ( & V_2 -> V_4 . V_20 ) ;
V_72 = F_1 ( V_2 , V_75 ) ;
V_72 &= F_1 ( V_2 , V_12 ) ;
if ( V_72 & V_24 ) {
F_3 ( V_2 , V_75 ,
V_24 ) ;
F_26 ( V_2 ) ;
}
if ( V_72 & V_11 ) {
F_3 ( V_2 , V_75 ,
V_11 ) ;
F_9 ( V_2 ) ;
F_32 ( V_2 ) ;
}
F_39 ( & V_2 -> V_4 . V_20 ) ;
return V_76 ;
}
static int F_40 ( struct V_18 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned long V_19 ;
int V_77 ;
V_77 = F_41 ( V_2 -> V_4 . V_70 , F_37 ,
V_2 -> V_4 . V_78 , F_42 ( V_2 -> V_4 . V_79 ) , V_2 ) ;
if ( V_77 )
return V_77 ;
F_12 ( & V_2 -> V_4 . V_20 , V_19 ) ;
F_6 ( V_2 , V_26 ,
V_51 ) ;
V_2 -> V_10 = V_24 ;
F_3 ( V_2 , V_12 , V_2 -> V_10 ) ;
F_13 ( & V_2 -> V_4 . V_20 , V_19 ) ;
return 0 ;
}
static void F_43 ( struct V_18 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
V_2 -> V_10 = 0 ;
F_3 ( V_2 , V_12 , V_2 -> V_10 ) ;
F_7 ( V_2 , V_26 ,
V_27 ) ;
F_44 ( V_2 -> V_4 . V_70 , V_2 ) ;
}
static const char * F_45 ( struct V_18 * V_4 )
{
return ( V_4 -> type == V_80 ) ? L_1 : NULL ;
}
static void F_46 ( struct V_18 * V_4 )
{
}
static int F_47 ( struct V_18 * V_4 )
{
return 0 ;
}
static void F_48 ( struct V_18 * V_4 , int V_19 )
{
if ( V_19 & V_81 )
V_4 -> type = V_80 ;
}
static int F_49 ( struct V_18 * V_4 ,
struct V_82 * V_83 )
{
if ( V_83 -> type != V_84 &&
V_83 -> type != V_80 )
return - V_85 ;
if ( V_83 -> V_70 < 0 || V_83 -> V_70 >= V_86 )
return - V_85 ;
if ( V_83 -> V_87 < 28800 )
return - V_85 ;
return 0 ;
}
static void F_50 ( struct V_1 * V_2 )
{
unsigned int V_72 ;
unsigned int V_88 = 60000 ;
do {
V_72 = F_1 ( V_2 , V_17 ) ;
if ( -- V_88 == 0 )
break;
F_51 ( 1 ) ;
} while ( ( V_72 & V_16 ) == 0 );
}
static void F_52 ( struct V_18 * V_4 , int V_13 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
F_50 ( V_2 ) ;
F_10 ( V_2 , V_13 ) ;
}
static void F_53 ( struct V_89 * V_90 , const char * V_91 ,
unsigned int V_62 )
{
struct V_1 * V_2 = V_92 [ V_90 -> V_93 ] ;
unsigned long V_19 ;
unsigned int V_94 ;
int V_95 = 1 ;
F_54 ( V_19 ) ;
if ( V_2 -> V_4 . V_96 )
V_95 = 0 ;
else if ( V_97 )
V_95 = F_55 ( & V_2 -> V_4 . V_20 ) ;
else
F_38 ( & V_2 -> V_4 . V_20 ) ;
V_94 = F_1 ( V_2 , V_12 ) ;
F_3 ( V_2 , V_12 , 0 ) ;
F_56 ( & V_2 -> V_4 , V_91 , V_62 , F_52 ) ;
F_50 ( V_2 ) ;
F_3 ( V_2 , V_12 , V_94 ) ;
F_3 ( V_2 , V_75 , V_98 ) ;
if ( V_95 )
F_39 ( & V_2 -> V_4 . V_20 ) ;
F_57 ( V_19 ) ;
}
static int F_58 ( struct V_89 * V_90 , char * V_99 )
{
struct V_1 * V_2 ;
int V_32 = 115200 ;
int V_100 = 8 ;
int V_101 = 'n' ;
int V_102 = 'n' ;
if ( V_90 -> V_93 < 0 || V_90 -> V_93 >= V_103 )
return - V_85 ;
V_2 = V_92 [ V_90 -> V_93 ] ;
if ( ! V_2 )
return - V_104 ;
if ( V_99 )
F_59 ( V_99 , & V_32 , & V_101 , & V_100 , & V_102 ) ;
return F_60 ( & V_2 -> V_4 , V_90 , V_32 , V_101 , V_100 , V_102 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
V_92 [ V_2 -> V_4 . line ] = V_2 ;
}
static inline void F_61 ( struct V_1 * V_2 ) {}
static int T_2 F_62 ( struct V_105 * V_106 )
{
struct V_107 * V_108 ;
struct V_1 * V_2 ;
struct V_18 * V_4 ;
struct V_109 * V_110 ;
struct V_109 * V_111 ;
int V_112 ;
int V_77 ;
V_108 = V_106 -> V_79 . V_113 ;
if ( ! V_108 )
return - V_85 ;
V_112 = V_106 -> V_112 ;
if ( V_112 == - 1 )
V_112 = 0 ;
if ( V_112 > V_103 )
return - V_85 ;
V_110 = F_63 ( V_106 , V_114 , 0 ) ;
if ( ! V_110 ) {
F_64 ( & V_106 -> V_79 , L_2 ) ;
return - V_85 ;
}
V_111 = F_63 ( V_106 , V_115 , 0 ) ;
if ( ! V_111 ) {
F_64 ( & V_106 -> V_79 , L_3 ) ;
return - V_85 ;
}
V_2 = F_65 ( sizeof( struct V_1 ) , V_116 ) ;
if ( ! V_2 )
return - V_117 ;
V_4 = & V_2 -> V_4 ;
V_4 -> V_118 = V_110 -> V_119 ;
V_4 -> V_5 = F_66 ( V_110 -> V_119 , V_120 ) ;
if ( ! V_4 -> V_5 ) {
V_77 = - V_117 ;
goto V_121;
}
V_4 -> line = V_112 ;
V_4 -> V_70 = V_111 -> V_119 ;
V_4 -> V_79 = & V_106 -> V_79 ;
V_4 -> type = V_80 ;
V_4 -> V_122 = V_123 ;
V_4 -> V_44 = V_108 -> V_44 ;
V_4 -> V_124 = 2 ;
V_4 -> V_63 = V_125 ;
V_4 -> V_126 = & V_127 ;
F_61 ( V_2 ) ;
V_77 = F_67 ( & V_128 , & V_2 -> V_4 ) ;
if ( V_77 )
goto V_129;
F_68 ( V_106 , V_2 ) ;
return 0 ;
V_129:
F_69 ( V_2 -> V_4 . V_5 ) ;
V_121:
F_70 ( V_2 ) ;
return V_77 ;
}
static int T_3 F_71 ( struct V_105 * V_106 )
{
struct V_1 * V_2 ;
V_2 = F_72 ( V_106 ) ;
F_68 ( V_106 , NULL ) ;
if ( V_2 ) {
F_73 ( & V_128 , & V_2 -> V_4 ) ;
F_69 ( V_2 -> V_4 . V_5 ) ;
F_70 ( V_2 ) ;
}
return 0 ;
}
static int T_4 F_74 ( void )
{
int V_77 ;
V_128 . V_130 = V_103 ;
V_77 = F_75 ( & V_128 ) ;
if ( V_77 )
goto V_131;
V_77 = F_76 ( & V_132 ) ;
if ( V_77 )
goto V_133;
return 0 ;
V_133:
F_77 ( & V_128 ) ;
V_131:
return V_77 ;
}
static void T_5 F_78 ( void )
{
F_79 ( & V_132 ) ;
F_77 ( & V_128 ) ;
}
