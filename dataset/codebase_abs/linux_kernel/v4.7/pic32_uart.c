static inline void F_1 ( struct V_1 * V_2 )
{
while ( ! ( F_2 ( V_2 , V_3 ) & V_4 ) )
F_3 ( 1 ) ;
}
static inline int F_4 ( struct V_1 * V_2 )
{
int V_5 = F_5 ( V_2 -> V_6 ) ;
if ( V_5 )
return V_5 ;
V_2 -> V_7 ++ ;
return 0 ;
}
static inline void F_6 ( struct V_1 * V_2 )
{
V_2 -> V_7 -- ;
F_7 ( V_2 -> V_6 ) ;
}
static unsigned int F_8 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_1 V_10 = F_2 ( V_2 , V_3 ) ;
return ( V_10 & V_4 ) ? 1 : 0 ;
}
static void F_10 ( struct V_8 * V_9 , unsigned int V_11 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
if ( V_11 & V_12 )
F_11 ( V_2 , F_12 ( V_13 ) ,
V_14 ) ;
else
F_11 ( V_2 , F_13 ( V_13 ) ,
V_14 ) ;
}
static unsigned int F_14 ( struct V_1 * V_2 )
{
if ( F_15 ( V_2 -> V_15 ) )
return ! F_16 ( V_2 -> V_15 ) ;
return 1 ;
}
static unsigned int F_17 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
unsigned int V_11 = 0 ;
if ( ! V_2 -> V_16 )
V_11 |= V_17 ;
else if ( F_14 ( V_2 ) )
V_11 |= V_17 ;
V_11 |= V_18 ;
V_11 |= V_19 ;
return V_11 ;
}
static inline void F_18 ( struct V_1 * V_2 , T_2 V_20 )
{
if ( V_20 && ! F_19 ( V_2 ) ) {
F_20 ( V_2 -> V_21 ) ;
F_19 ( V_2 ) = 1 ;
} else if ( ! V_20 && F_19 ( V_2 ) ) {
F_21 ( V_2 -> V_21 ) ;
F_19 ( V_2 ) = 0 ;
}
}
static void F_22 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
if ( ! ( F_2 ( V_2 , V_13 ) & V_22 ) )
return;
if ( ! ( F_2 ( V_2 , V_3 ) & V_23 ) )
return;
F_1 ( V_2 ) ;
F_11 ( V_2 , F_13 ( V_3 ) ,
V_23 ) ;
F_18 ( V_2 , 0 ) ;
}
static void F_23 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
F_18 ( V_2 , 1 ) ;
F_11 ( V_2 , F_12 ( V_3 ) ,
V_23 ) ;
}
static void F_24 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
F_25 ( V_2 -> V_24 ) ;
F_11 ( V_2 , F_13 ( V_3 ) ,
V_25 ) ;
}
static void F_26 ( struct V_8 * V_9 , int V_26 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
unsigned long V_27 ;
F_27 ( & V_9 -> V_28 , V_27 ) ;
if ( V_26 )
F_11 ( V_2 , F_12 ( V_3 ) ,
V_29 ) ;
else
F_11 ( V_2 , F_13 ( V_3 ) ,
V_29 ) ;
F_28 ( & V_9 -> V_28 , V_27 ) ;
}
static const char * F_29 ( struct V_8 * V_9 )
{
return ( V_9 -> type == V_30 ) ? V_31 : NULL ;
}
static void F_30 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
struct V_32 * V_33 ;
unsigned int V_34 ;
V_34 = V_35 ;
F_31 ( & V_9 -> V_28 ) ;
V_33 = & V_9 -> V_36 -> V_9 ;
do {
T_1 V_37 , V_38 ;
char V_39 ;
V_37 = F_2 ( V_2 , V_3 ) ;
if ( F_32 ( V_37 & V_40 ) ) {
F_11 ( V_2 , F_13 ( V_3 ) ,
V_40 ) ;
V_9 -> V_41 . V_42 ++ ;
F_33 ( V_33 , 0 , V_43 ) ;
}
if ( ! ( V_37 & V_44 ) )
break;
V_38 = F_2 ( V_2 , V_45 ) ;
V_9 -> V_41 . V_46 ++ ;
V_39 = V_47 ;
V_38 &= 0xff ;
if ( F_32 ( ( V_37 & V_48 ) ||
( V_37 & V_49 ) ) ) {
if ( V_37 & V_48 )
V_9 -> V_41 . V_50 ++ ;
if ( V_37 & V_49 )
V_9 -> V_41 . V_51 ++ ;
V_37 &= V_9 -> V_52 ;
if ( V_37 & V_49 )
V_39 = V_53 ;
if ( V_37 & V_48 )
V_39 = V_54 ;
}
if ( F_34 ( V_9 , V_38 ) )
continue;
if ( ( V_37 & V_9 -> V_55 ) == 0 )
F_33 ( V_33 , V_38 , V_39 ) ;
} while ( -- V_34 );
F_35 ( & V_9 -> V_28 ) ;
F_36 ( V_33 ) ;
}
static void F_37 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
struct V_56 * V_57 = & V_9 -> V_36 -> V_57 ;
unsigned int V_34 = V_58 ;
if ( V_9 -> V_59 ) {
F_11 ( V_2 , V_60 , V_9 -> V_59 ) ;
V_9 -> V_41 . V_61 ++ ;
V_9 -> V_59 = 0 ;
return;
}
if ( F_38 ( V_9 ) ) {
F_22 ( V_9 ) ;
return;
}
if ( F_39 ( V_57 ) )
goto V_62;
while ( ! ( V_63 &
F_2 ( V_2 , V_3 ) ) ) {
unsigned int V_38 = V_57 -> V_64 [ V_57 -> V_65 ] ;
F_11 ( V_2 , V_60 , V_38 ) ;
V_57 -> V_65 = ( V_57 -> V_65 + 1 ) & ( V_66 - 1 ) ;
V_9 -> V_41 . V_61 ++ ;
if ( F_39 ( V_57 ) )
break;
if ( -- V_34 == 0 )
break;
}
if ( F_40 ( V_57 ) < V_67 )
F_41 ( V_9 ) ;
if ( F_39 ( V_57 ) )
goto V_62;
return;
V_62:
F_18 ( V_2 , 0 ) ;
}
static T_3 F_42 ( int V_68 , void * V_69 )
{
struct V_8 * V_9 = V_69 ;
F_30 ( V_9 ) ;
return V_70 ;
}
static T_3 F_43 ( int V_68 , void * V_69 )
{
struct V_8 * V_9 = V_69 ;
unsigned long V_27 ;
F_27 ( & V_9 -> V_28 , V_27 ) ;
F_37 ( V_9 ) ;
F_28 ( & V_9 -> V_28 , V_27 ) ;
return V_70 ;
}
static T_3 F_44 ( int V_68 , void * V_69 )
{
return V_70 ;
}
static void F_45 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
F_11 ( V_2 , F_12 ( V_3 ) ,
V_23 | V_25 ) ;
F_11 ( V_2 , F_12 ( V_13 ) ,
V_22 ) ;
}
static void F_46 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
F_1 ( V_2 ) ;
F_11 ( V_2 , F_13 ( V_3 ) ,
V_23 | V_25 ) ;
F_11 ( V_2 , F_13 ( V_13 ) ,
V_22 ) ;
}
static int F_47 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
T_1 V_71 = ( V_9 -> V_72 / V_73 / 16 ) - 1 ;
unsigned long V_27 ;
int V_5 ;
F_48 ( V_27 ) ;
V_5 = F_4 ( V_2 ) ;
if ( V_5 ) {
F_49 ( V_27 ) ;
goto V_74;
}
F_11 ( V_2 , V_13 , 0 ) ;
F_11 ( V_2 , V_3 , 0 ) ;
F_46 ( V_9 ) ;
F_11 ( V_2 , V_75 , V_71 ) ;
F_49 ( V_27 ) ;
F_19 ( V_2 ) = 0 ;
V_2 -> V_76 = F_50 ( V_77 , L_1 ,
F_29 ( V_9 ) ,
V_2 -> V_78 ) ;
if ( ! V_2 -> V_76 ) {
F_51 ( V_9 -> V_79 , L_2 , V_80 ) ;
V_5 = - V_81 ;
goto V_74;
}
F_52 ( V_2 -> V_82 , V_83 ) ;
V_5 = F_53 ( V_2 -> V_82 , F_44 ,
V_2 -> V_84 , V_2 -> V_76 , V_9 ) ;
if ( V_5 ) {
F_51 ( V_9 -> V_79 , L_3 ,
V_80 , V_2 -> V_82 , V_5 ,
F_29 ( V_9 ) ) ;
goto V_85;
}
V_2 -> V_86 = F_50 ( V_77 , L_4 ,
F_29 ( V_9 ) ,
V_2 -> V_78 ) ;
if ( ! V_2 -> V_86 ) {
F_51 ( V_9 -> V_79 , L_2 , V_80 ) ;
F_54 ( V_2 -> V_76 ) ;
V_5 = - V_81 ;
goto V_85;
}
F_52 ( V_2 -> V_24 , V_83 ) ;
V_5 = F_53 ( V_2 -> V_24 , F_42 ,
V_2 -> V_87 , V_2 -> V_86 , V_9 ) ;
if ( V_5 ) {
F_51 ( V_9 -> V_79 , L_3 ,
V_80 , V_2 -> V_24 , V_5 ,
F_29 ( V_9 ) ) ;
goto V_88;
}
V_2 -> V_89 = F_50 ( V_77 , L_5 ,
F_29 ( V_9 ) ,
V_2 -> V_78 ) ;
if ( ! V_2 -> V_89 ) {
F_51 ( V_9 -> V_79 , L_2 , V_80 ) ;
V_5 = - V_81 ;
goto V_88;
}
F_52 ( V_2 -> V_21 , V_83 ) ;
V_5 = F_53 ( V_2 -> V_21 , F_43 ,
V_2 -> V_90 , V_2 -> V_89 , V_9 ) ;
if ( V_5 ) {
F_51 ( V_9 -> V_79 , L_3 ,
V_80 , V_2 -> V_21 , V_5 ,
F_29 ( V_9 ) ) ;
goto V_91;
}
F_48 ( V_27 ) ;
F_11 ( V_2 , F_13 ( V_3 ) ,
V_92 | V_93 ) ;
F_11 ( V_2 , F_13 ( V_3 ) ,
V_94 ) ;
F_45 ( V_9 ) ;
F_20 ( V_2 -> V_24 ) ;
return 0 ;
V_91:
F_54 ( V_2 -> V_89 ) ;
F_55 ( V_2 -> V_21 , V_2 ) ;
V_88:
F_54 ( V_2 -> V_86 ) ;
F_55 ( V_2 -> V_24 , V_2 ) ;
V_85:
F_54 ( V_2 -> V_76 ) ;
F_55 ( V_2 -> V_82 , V_2 ) ;
V_74:
return V_5 ;
}
static void F_56 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
unsigned long V_27 ;
F_27 ( & V_9 -> V_28 , V_27 ) ;
F_46 ( V_9 ) ;
F_28 ( & V_9 -> V_28 , V_27 ) ;
F_6 ( V_2 ) ;
F_55 ( V_2 -> V_82 , V_9 ) ;
F_55 ( V_2 -> V_21 , V_9 ) ;
F_55 ( V_2 -> V_24 , V_9 ) ;
}
static void F_57 ( struct V_8 * V_9 ,
struct V_95 * V_96 ,
struct V_95 * V_97 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
unsigned int V_98 ;
unsigned int V_99 ;
unsigned long V_27 ;
F_27 ( & V_9 -> V_28 , V_27 ) ;
F_46 ( V_9 ) ;
if ( V_96 -> V_100 & V_101 )
F_11 ( V_2 , F_12 ( V_13 ) ,
V_102 ) ;
else
F_11 ( V_2 , F_13 ( V_13 ) ,
V_102 ) ;
if ( V_96 -> V_100 & V_103 ) {
if ( V_96 -> V_100 & V_104 ) {
F_11 ( V_2 , F_12 ( V_13 ) ,
V_105 ) ;
F_11 ( V_2 , F_13 ( V_13 ) ,
V_106 ) ;
} else {
F_11 ( V_2 , F_12 ( V_13 ) ,
V_106 ) ;
F_11 ( V_2 , F_13 ( V_13 ) ,
V_105 ) ;
}
} else {
F_11 ( V_2 , F_13 ( V_13 ) ,
V_105 |
V_106 ) ;
}
if ( ( V_96 -> V_100 & V_107 ) && V_2 -> V_16 ) {
F_11 ( V_2 , F_12 ( V_13 ) ,
V_108 ) ;
F_11 ( V_2 , F_13 ( V_13 ) ,
V_109 ) ;
F_11 ( V_2 , F_13 ( V_13 ) ,
V_110 ) ;
} else {
F_11 ( V_2 , F_13 ( V_13 ) ,
V_108 ) ;
F_11 ( V_2 , F_13 ( V_13 ) ,
V_109 ) ;
F_11 ( V_2 , F_13 ( V_13 ) ,
V_110 ) ;
}
V_96 -> V_100 |= V_111 ;
V_96 -> V_100 &= ~ V_112 ;
V_98 = F_58 ( V_9 , V_96 , V_97 , 0 , V_9 -> V_72 / 16 ) ;
V_99 = F_59 ( V_9 , V_98 ) - 1 ;
F_11 ( V_2 , V_75 , V_99 ) ;
F_60 ( V_9 , V_96 -> V_100 , V_98 ) ;
if ( F_61 ( V_96 ) )
F_62 ( V_96 , V_98 , V_98 ) ;
F_45 ( V_9 ) ;
F_28 ( & V_9 -> V_28 , V_27 ) ;
}
static int F_63 ( struct V_8 * V_9 )
{
struct V_113 * V_114 = F_64 ( V_9 -> V_79 ) ;
struct V_115 * V_116 ;
V_116 = F_65 ( V_114 , V_117 , 0 ) ;
if ( F_32 ( ! V_116 ) )
return - V_118 ;
if ( ! F_66 ( V_9 -> V_119 , F_67 ( V_116 ) ,
L_6 ) )
return - V_120 ;
V_9 -> V_121 = F_68 ( V_9 -> V_79 , V_9 -> V_119 ,
F_67 ( V_116 ) ) ;
if ( ! V_9 -> V_121 ) {
F_51 ( V_9 -> V_79 , L_7 ) ;
F_69 ( V_9 -> V_119 , F_67 ( V_116 ) ) ;
return - V_81 ;
}
return 0 ;
}
static void F_70 ( struct V_8 * V_9 )
{
struct V_113 * V_114 = F_64 ( V_9 -> V_79 ) ;
struct V_115 * V_116 ;
unsigned int V_122 ;
V_116 = F_65 ( V_114 , V_117 , 0 ) ;
if ( F_32 ( ! V_116 ) )
return;
V_122 = F_67 ( V_116 ) ;
F_69 ( V_9 -> V_119 , V_122 ) ;
}
static void F_71 ( struct V_8 * V_9 , int V_27 )
{
if ( V_27 & V_123 ) {
if ( F_63 ( V_9 ) )
return;
V_9 -> type = V_30 ;
}
}
static int F_72 ( struct V_8 * V_9 ,
struct V_124 * V_125 )
{
if ( V_9 -> type != V_30 )
return - V_118 ;
if ( V_9 -> V_68 != V_125 -> V_68 )
return - V_118 ;
if ( V_9 -> V_126 != V_125 -> V_127 )
return - V_118 ;
if ( V_9 -> V_119 != ( unsigned long ) V_125 -> V_128 )
return - V_118 ;
return 0 ;
}
static void F_73 ( struct V_8 * V_9 , int V_129 )
{
struct V_1 * V_2 = F_9 ( V_9 ) ;
if ( ! ( F_2 ( V_2 , V_13 ) & V_22 ) )
return;
if ( ! ( F_2 ( V_2 , V_3 ) & V_23 ) )
return;
F_1 ( V_2 ) ;
F_11 ( V_2 , V_60 , V_129 & 0xff ) ;
}
static void F_74 ( struct V_130 * V_131 , const char * V_132 ,
unsigned int V_133 )
{
struct V_1 * V_2 = V_134 [ V_131 -> V_135 ] ;
struct V_8 * V_9 = F_75 ( V_2 ) ;
F_76 ( V_9 , V_132 , V_133 , F_73 ) ;
}
static int F_77 ( struct V_130 * V_131 , char * V_136 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 = NULL ;
int V_98 = 115200 ;
int V_137 = 8 ;
int V_50 = 'n' ;
int V_138 = 'n' ;
int V_5 = 0 ;
if ( F_32 ( V_131 -> V_135 < 0 || V_131 -> V_135 >= V_139 ) )
return - V_140 ;
V_2 = V_134 [ V_131 -> V_135 ] ;
if ( ! V_2 )
return - V_140 ;
V_9 = F_75 ( V_2 ) ;
V_5 = F_4 ( V_2 ) ;
if ( V_5 )
return V_5 ;
if ( V_136 )
F_78 ( V_136 , & V_98 , & V_50 , & V_137 , & V_138 ) ;
return F_79 ( V_9 , V_131 , V_98 , V_50 , V_137 , V_138 ) ;
}
static int T_4 F_80 ( void )
{
F_81 ( & V_141 ) ;
return 0 ;
}
static inline bool F_82 ( struct V_8 * V_9 )
{
return V_9 -> V_142 && V_9 -> V_142 -> V_135 == V_9 -> line ;
}
static int T_4 F_83 ( void )
{
if ( ! ( V_141 . V_27 & V_143 ) )
F_81 ( & V_141 ) ;
return 0 ;
}
static int F_84 ( struct V_113 * V_114 )
{
struct V_144 * V_145 = V_114 -> V_79 . V_146 ;
struct V_1 * V_2 ;
int V_147 = 0 ;
struct V_115 * V_116 ;
struct V_8 * V_9 ;
int V_5 ;
V_147 = F_85 ( V_145 , L_8 ) ;
if ( V_147 < 0 || V_147 >= V_139 )
return - V_118 ;
V_116 = F_65 ( V_114 , V_117 , 0 ) ;
if ( ! V_116 )
return - V_118 ;
V_2 = F_86 ( & V_114 -> V_79 , sizeof( * V_2 ) , V_77 ) ;
if ( ! V_2 )
return - V_81 ;
V_2 -> V_78 = V_147 ;
V_2 -> V_82 = F_87 ( V_145 , 0 ) ;
V_2 -> V_84 = V_148 ;
V_2 -> V_24 = F_87 ( V_145 , 1 ) ;
V_2 -> V_87 = V_148 ;
V_2 -> V_21 = F_87 ( V_145 , 2 ) ;
V_2 -> V_90 = V_148 ;
V_2 -> V_6 = F_88 ( & V_114 -> V_79 , NULL ) ;
V_2 -> V_15 = - V_118 ;
V_2 -> V_79 = & V_114 -> V_79 ;
V_2 -> V_16 = false ;
V_2 -> V_15 = F_89 ( V_145 , L_9 , 0 ) ;
if ( F_15 ( V_2 -> V_15 ) ) {
V_2 -> V_16 = true ;
V_5 = F_90 ( V_2 -> V_79 ,
V_2 -> V_15 , L_10 ) ;
if ( V_5 ) {
F_51 ( & V_114 -> V_79 ,
L_11 ) ;
goto V_149;
}
V_5 = F_91 ( V_2 -> V_15 ) ;
if ( V_5 ) {
F_51 ( & V_114 -> V_79 , L_12 ) ;
goto V_149;
}
}
V_134 [ V_147 ] = V_2 ;
V_9 = & V_2 -> V_9 ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_126 = V_150 ;
V_9 -> V_119 = V_116 -> V_151 ;
V_9 -> V_152 = & V_153 ;
V_9 -> V_27 = V_154 ;
V_9 -> V_79 = & V_114 -> V_79 ;
V_9 -> V_155 = V_58 ;
V_9 -> V_72 = F_92 ( V_2 -> V_6 ) ;
V_9 -> line = V_147 ;
V_5 = F_93 ( & V_156 , V_9 ) ;
if ( V_5 ) {
V_9 -> V_121 = NULL ;
F_51 ( V_9 -> V_79 , L_13 , V_80 ) ;
goto V_149;
}
#ifdef F_94
if ( F_82 ( V_9 ) &&
( V_141 . V_27 & V_143 ) ) {
F_6 ( V_2 ) ;
}
#endif
F_95 ( V_114 , V_9 ) ;
F_96 ( & V_114 -> V_79 , L_14 ,
V_80 , V_147 ) ;
return 0 ;
V_149:
return V_5 ;
}
static int F_97 ( struct V_113 * V_114 )
{
struct V_8 * V_9 = F_98 ( V_114 ) ;
struct V_1 * V_2 = F_9 ( V_9 ) ;
F_99 ( & V_156 , V_9 ) ;
F_6 ( V_2 ) ;
F_95 ( V_114 , NULL ) ;
V_134 [ V_2 -> V_78 ] = NULL ;
return 0 ;
}
static int T_4 F_100 ( void )
{
int V_5 ;
V_5 = F_101 ( & V_156 ) ;
if ( V_5 ) {
F_102 ( L_15 ,
V_156 . V_157 , V_5 ) ;
return V_5 ;
}
V_5 = F_103 ( & V_158 ) ;
if ( V_5 ) {
F_102 ( L_16 ) ;
F_104 ( & V_156 ) ;
}
return V_5 ;
}
static void T_5 F_105 ( void )
{
#ifdef F_94
F_106 ( & V_141 ) ;
#endif
F_107 ( & V_158 ) ;
F_104 ( & V_156 ) ;
}
