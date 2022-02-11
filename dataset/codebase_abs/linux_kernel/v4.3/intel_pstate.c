static inline T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
return ( ( V_3 ) V_1 * ( V_3 ) V_2 ) >> V_4 ;
}
static inline T_1 F_2 ( T_2 V_1 , T_2 V_2 )
{
return F_3 ( ( V_3 ) V_1 << V_4 , V_2 ) ;
}
static inline int F_4 ( T_1 V_1 )
{
int V_5 , V_6 ;
V_6 = F_5 ( V_1 ) ;
V_5 = ( 1 << V_4 ) - 1 ;
if ( V_1 & V_5 )
V_6 += 1 ;
return V_6 ;
}
static inline void F_6 ( struct V_7 * V_8 , int V_9 , int V_10 ,
int V_11 , int V_12 ) {
V_8 -> V_9 = V_9 ;
V_8 -> V_11 = V_11 ;
V_8 -> V_12 = F_7 ( V_12 ) ;
V_8 -> V_13 = F_7 ( V_9 ) - F_7 ( V_10 ) ;
}
static inline void F_8 ( struct V_7 * V_8 , int V_14 )
{
V_8 -> V_15 = F_2 ( F_7 ( V_14 ) , F_7 ( 100 ) ) ;
}
static inline void F_9 ( struct V_7 * V_8 , int V_14 )
{
V_8 -> V_16 = F_2 ( F_7 ( V_14 ) , F_7 ( 100 ) ) ;
}
static inline void F_10 ( struct V_7 * V_8 , int V_14 )
{
V_8 -> V_17 = F_2 ( F_7 ( V_14 ) , F_7 ( 100 ) ) ;
}
static signed int F_11 ( struct V_7 * V_8 , T_1 V_10 )
{
signed int V_18 ;
T_1 V_19 , V_20 , V_21 ;
T_1 V_22 ;
V_21 = F_7 ( V_8 -> V_9 ) - V_10 ;
if ( abs ( V_21 ) <= F_7 ( V_8 -> V_11 ) )
return 0 ;
V_19 = F_1 ( V_8 -> V_15 , V_21 ) ;
V_8 -> V_12 += V_21 ;
V_22 = F_7 ( 30 ) ;
if ( V_8 -> V_12 > V_22 )
V_8 -> V_12 = V_22 ;
if ( V_8 -> V_12 < - V_22 )
V_8 -> V_12 = - V_22 ;
V_20 = F_1 ( V_8 -> V_17 , V_21 - V_8 -> V_13 ) ;
V_8 -> V_13 = V_21 ;
V_18 = V_19 + F_1 ( V_8 -> V_12 , V_8 -> V_16 ) + V_20 ;
V_18 = V_18 + ( 1 << ( V_4 - 1 ) ) ;
return ( signed int ) F_5 ( V_18 ) ;
}
static inline void F_12 ( struct V_23 * V_24 )
{
F_8 ( & V_24 -> V_8 , V_25 . V_26 ) ;
F_10 ( & V_24 -> V_8 , V_25 . V_27 ) ;
F_9 ( & V_24 -> V_8 , V_25 . V_28 ) ;
F_6 ( & V_24 -> V_8 , V_25 . V_9 , 100 , V_25 . V_11 , 0 ) ;
}
static inline void F_13 ( void )
{
unsigned int V_24 ;
F_14 (cpu) {
if ( V_29 [ V_24 ] )
F_12 ( V_29 [ V_24 ] ) ;
}
}
static inline void F_15 ( void )
{
T_3 V_30 ;
struct V_23 * V_24 ;
V_24 = V_29 [ 0 ] ;
F_16 ( V_31 , V_30 ) ;
V_32 . V_33 =
( V_30 & V_34 ||
V_24 -> V_35 . V_36 == V_24 -> V_35 . V_37 ) ;
}
static void F_17 ( void )
{
int V_38 , V_39 , V_40 , V_41 , V_24 , V_42 , V_43 ;
T_3 V_44 , V_45 ;
F_16 ( V_46 , V_45 ) ;
V_39 = F_18 ( V_45 ) ;
V_41 = F_19 ( V_45 ) ;
V_42 = V_41 - V_39 ;
F_20 () ;
F_14 (cpu) {
F_21 ( V_24 , V_47 , & V_44 ) ;
V_43 = V_32 . V_48 * V_42 / 100 ;
V_38 = V_39 + V_43 ;
V_44 &= ~ F_22 ( ~ 0L ) ;
V_44 |= F_22 ( V_38 ) ;
V_43 = V_32 . V_49 * V_42 / 100 ;
V_40 = V_39 + V_43 ;
if ( V_32 . V_50 ) {
V_41 = F_23 ( V_45 ) ;
if ( V_41 < V_40 )
V_40 = V_41 ;
}
V_44 &= ~ F_24 ( ~ 0L ) ;
V_44 |= F_24 ( V_40 ) ;
F_25 ( V_24 , V_47 , V_44 ) ;
}
F_26 () ;
}
static int F_27 ( void * V_51 , T_3 V_52 )
{
* ( V_53 * ) V_51 = V_52 ;
F_13 () ;
return 0 ;
}
static int F_28 ( void * V_51 , T_3 * V_52 )
{
* V_52 = * ( V_53 * ) V_51 ;
return 0 ;
}
static void T_4 F_29 ( void )
{
struct V_54 * V_55 ;
int V_56 = 0 ;
if ( V_57 )
return;
V_55 = F_30 ( L_1 , NULL ) ;
if ( F_31 ( V_55 ) )
return;
while ( V_58 [ V_56 ] . V_59 ) {
F_32 ( V_58 [ V_56 ] . V_59 , 0660 ,
V_55 , V_58 [ V_56 ] . V_44 ,
& V_60 ) ;
V_56 ++ ;
}
}
static T_5 F_33 ( struct V_61 * V_62 ,
struct V_63 * V_64 , char * V_65 )
{
struct V_23 * V_24 ;
int V_66 , V_50 , V_67 ;
T_6 V_68 ;
V_24 = V_29 [ 0 ] ;
V_66 = V_24 -> V_35 . V_37 - V_24 -> V_35 . V_69 + 1 ;
V_50 = V_24 -> V_35 . V_36 - V_24 -> V_35 . V_69 + 1 ;
V_68 = F_2 ( F_7 ( V_50 ) , F_7 ( V_66 ) ) ;
V_67 = 100 - F_5 ( F_1 ( V_68 , F_7 ( 100 ) ) ) ;
return sprintf ( V_65 , L_2 , V_67 ) ;
}
static T_5 F_34 ( struct V_61 * V_62 ,
struct V_63 * V_64 , char * V_65 )
{
struct V_23 * V_24 ;
int V_66 ;
V_24 = V_29 [ 0 ] ;
V_66 = V_24 -> V_35 . V_37 - V_24 -> V_35 . V_69 + 1 ;
return sprintf ( V_65 , L_2 , V_66 ) ;
}
static T_5 F_35 ( struct V_61 * V_62 ,
struct V_63 * V_64 , char * V_65 )
{
T_5 V_6 ;
F_15 () ;
if ( V_32 . V_33 )
V_6 = sprintf ( V_65 , L_2 , V_32 . V_33 ) ;
else
V_6 = sprintf ( V_65 , L_2 , V_32 . V_50 ) ;
return V_6 ;
}
static T_5 F_36 ( struct V_61 * V_70 , struct V_63 * V_71 ,
const char * V_65 , T_7 V_72 )
{
unsigned int V_73 ;
int V_6 ;
V_6 = sscanf ( V_65 , L_3 , & V_73 ) ;
if ( V_6 != 1 )
return - V_74 ;
F_15 () ;
if ( V_32 . V_33 ) {
F_37 ( L_4 ) ;
return - V_75 ;
}
V_32 . V_50 = F_38 ( int , V_73 , 0 , 1 ) ;
if ( V_57 )
F_17 () ;
return V_72 ;
}
static T_5 F_39 ( struct V_61 * V_70 , struct V_63 * V_71 ,
const char * V_65 , T_7 V_72 )
{
unsigned int V_73 ;
int V_6 ;
V_6 = sscanf ( V_65 , L_3 , & V_73 ) ;
if ( V_6 != 1 )
return - V_74 ;
V_32 . V_76 = F_38 ( int , V_73 , 0 , 100 ) ;
V_32 . V_49 = V_38 ( V_32 . V_77 , V_32 . V_76 ) ;
V_32 . V_49 = V_40 ( V_32 . V_78 , V_32 . V_49 ) ;
V_32 . V_49 = V_40 ( V_32 . V_48 , V_32 . V_49 ) ;
V_32 . V_79 = F_2 ( F_7 ( V_32 . V_49 ) , F_7 ( 100 ) ) ;
if ( V_57 )
F_17 () ;
return V_72 ;
}
static T_5 F_40 ( struct V_61 * V_70 , struct V_63 * V_71 ,
const char * V_65 , T_7 V_72 )
{
unsigned int V_73 ;
int V_6 ;
V_6 = sscanf ( V_65 , L_3 , & V_73 ) ;
if ( V_6 != 1 )
return - V_74 ;
V_32 . V_80 = F_38 ( int , V_73 , 0 , 100 ) ;
V_32 . V_48 = V_40 ( V_32 . V_78 , V_32 . V_80 ) ;
V_32 . V_48 = V_38 ( V_32 . V_77 , V_32 . V_48 ) ;
V_32 . V_48 = V_38 ( V_32 . V_49 , V_32 . V_48 ) ;
V_32 . V_81 = F_2 ( F_7 ( V_32 . V_48 ) , F_7 ( 100 ) ) ;
if ( V_57 )
F_17 () ;
return V_72 ;
}
static void T_4 F_41 ( void )
{
struct V_61 * V_82 ;
int V_83 ;
V_82 = F_42 ( L_5 ,
& V_84 . V_85 -> V_62 ) ;
F_43 ( ! V_82 ) ;
V_83 = F_44 ( V_82 , & V_86 ) ;
F_43 ( V_83 ) ;
}
static void F_45 ( struct V_23 * V_23 )
{
F_46 ( L_6 ) ;
F_25 ( V_23 -> V_24 , V_87 , 0x1 ) ;
}
static int F_47 ( void )
{
T_3 V_44 ;
F_16 ( V_88 , V_44 ) ;
return ( V_44 >> 8 ) & 0x7F ;
}
static int F_48 ( void )
{
T_3 V_44 ;
F_16 ( V_88 , V_44 ) ;
return ( V_44 >> 16 ) & 0x7F ;
}
static int F_49 ( void )
{
T_3 V_44 ;
F_16 ( V_89 , V_44 ) ;
return V_44 & 0x7F ;
}
static void F_50 ( struct V_23 * V_23 , int V_35 )
{
T_3 V_52 ;
T_1 V_90 ;
V_53 V_91 ;
V_52 = ( T_3 ) V_35 << 8 ;
if ( V_32 . V_50 && ! V_32 . V_33 )
V_52 |= ( T_3 ) 1 << 32 ;
V_90 = V_23 -> V_91 . V_38 + F_1 (
F_7 ( V_35 - V_23 -> V_35 . V_69 ) ,
V_23 -> V_91 . V_92 ) ;
V_90 = F_38 ( T_1 , V_90 , V_23 -> V_91 . V_38 , V_23 -> V_91 . V_40 ) ;
V_91 = F_4 ( V_90 ) ;
if ( V_35 > V_23 -> V_35 . V_36 )
V_91 = V_23 -> V_91 . V_93 ;
V_52 |= V_91 ;
F_25 ( V_23 -> V_24 , V_94 , V_52 ) ;
}
static int F_51 ( void )
{
T_3 V_44 ;
int V_56 ;
F_16 ( V_95 , V_44 ) ;
V_56 = V_44 & 0x3 ;
F_43 ( V_56 > V_96 ) ;
return V_97 [ V_56 ] * 100 ;
}
static void F_52 ( struct V_23 * V_23 )
{
T_3 V_44 ;
F_16 ( V_98 , V_44 ) ;
V_23 -> V_91 . V_38 = F_7 ( ( V_44 >> 8 ) & 0x7f ) ;
V_23 -> V_91 . V_40 = F_7 ( ( V_44 >> 16 ) & 0x7f ) ;
V_23 -> V_91 . V_92 = F_2 (
V_23 -> V_91 . V_40 - V_23 -> V_91 . V_38 ,
F_7 ( V_23 -> V_35 . V_36 -
V_23 -> V_35 . V_69 ) ) ;
F_16 ( V_99 , V_44 ) ;
V_23 -> V_91 . V_93 = V_44 & 0x7f ;
}
static int F_53 ( void )
{
T_3 V_44 ;
F_16 ( V_100 , V_44 ) ;
return ( V_44 >> 40 ) & 0xFF ;
}
static int F_54 ( void )
{
T_3 V_44 ;
F_16 ( V_100 , V_44 ) ;
return ( V_44 >> 8 ) & 0xFF ;
}
static int F_55 ( void )
{
T_3 V_44 ;
int V_101 , V_6 ;
F_16 ( V_102 , V_44 ) ;
V_101 = F_54 () ;
V_6 = ( V_44 ) & 255 ;
if ( V_6 <= V_101 )
V_6 = V_101 ;
return V_6 ;
}
static inline int F_56 ( void )
{
return 100000 ;
}
static void F_57 ( struct V_23 * V_23 , int V_35 )
{
T_3 V_52 ;
V_52 = ( T_3 ) V_35 << 8 ;
if ( V_32 . V_50 && ! V_32 . V_33 )
V_52 |= ( T_3 ) 1 << 32 ;
F_25 ( V_23 -> V_24 , V_94 , V_52 ) ;
}
static int F_58 ( void )
{
T_3 V_44 ;
int V_101 , V_6 ;
F_16 ( V_102 , V_44 ) ;
V_101 = F_54 () ;
V_6 = ( ( ( V_44 ) >> 8 ) & 0xFF ) ;
if ( V_6 <= V_101 )
V_6 = V_101 ;
return V_6 ;
}
static void F_59 ( struct V_23 * V_24 , int * V_38 , int * V_40 )
{
int V_79 = V_24 -> V_35 . V_37 ;
int V_103 ;
int V_81 ;
if ( V_32 . V_50 || V_32 . V_33 )
V_79 = V_24 -> V_35 . V_36 ;
V_103 = F_5 ( F_1 ( F_7 ( V_79 ) , V_32 . V_79 ) ) ;
* V_40 = F_38 ( int , V_103 ,
V_24 -> V_35 . V_69 , V_24 -> V_35 . V_37 ) ;
V_81 = F_5 ( F_1 ( F_7 ( V_79 ) , V_32 . V_81 ) ) ;
* V_38 = F_38 ( int , V_81 , V_24 -> V_35 . V_69 , V_79 ) ;
}
static void F_60 ( struct V_23 * V_24 , int V_35 , bool V_104 )
{
int V_79 , V_81 ;
if ( V_104 ) {
F_15 () ;
F_59 ( V_24 , & V_81 , & V_79 ) ;
V_35 = F_38 ( int , V_35 , V_81 , V_79 ) ;
if ( V_35 == V_24 -> V_35 . V_105 )
return;
}
F_61 ( V_35 * V_24 -> V_35 . V_106 , V_24 -> V_24 ) ;
V_24 -> V_35 . V_105 = V_35 ;
V_107 . V_108 ( V_24 , V_35 ) ;
}
static void F_62 ( struct V_23 * V_24 )
{
V_24 -> V_35 . V_69 = V_107 . V_109 () ;
V_24 -> V_35 . V_36 = V_107 . V_110 () ;
V_24 -> V_35 . V_37 = V_107 . V_111 () ;
V_24 -> V_35 . V_106 = V_107 . V_112 () ;
if ( V_107 . V_113 )
V_107 . V_113 ( V_24 ) ;
F_60 ( V_24 , V_24 -> V_35 . V_69 , false ) ;
}
static inline void F_63 ( struct V_23 * V_24 )
{
struct V_114 * V_114 = & V_24 -> V_114 ;
V_3 V_115 ;
V_115 = F_7 ( V_114 -> V_116 ) * F_7 ( 100 ) ;
V_115 = F_64 ( V_115 , F_7 ( V_114 -> V_117 ) ) ;
V_114 -> V_118 = F_5 (
F_1 ( F_7 (
V_24 -> V_35 . V_36 * V_24 -> V_35 . V_106 / 100 ) ,
V_115 ) ) ;
V_114 -> V_119 = ( T_1 ) V_115 ;
}
static inline void F_65 ( struct V_23 * V_24 )
{
T_3 V_116 , V_117 ;
unsigned long V_120 ;
T_3 V_121 ;
F_66 ( V_120 ) ;
F_16 ( V_122 , V_116 ) ;
F_16 ( V_123 , V_117 ) ;
if ( V_24 -> V_124 == V_117 ) {
F_67 ( V_120 ) ;
return;
}
V_121 = F_68 () ;
F_67 ( V_120 ) ;
V_24 -> V_125 = V_24 -> V_114 . time ;
V_24 -> V_114 . time = F_69 () ;
V_24 -> V_114 . V_116 = V_116 ;
V_24 -> V_114 . V_117 = V_117 ;
V_24 -> V_114 . V_121 = V_121 ;
V_24 -> V_114 . V_116 -= V_24 -> V_126 ;
V_24 -> V_114 . V_117 -= V_24 -> V_124 ;
V_24 -> V_114 . V_121 -= V_24 -> V_127 ;
F_63 ( V_24 ) ;
V_24 -> V_126 = V_116 ;
V_24 -> V_124 = V_117 ;
V_24 -> V_127 = V_121 ;
}
static inline void F_70 ( struct V_23 * V_24 )
{
int V_128 ;
V_128 = F_71 ( 50 ) ;
F_72 ( & V_24 -> V_129 , V_130 + V_128 ) ;
}
static inline void F_73 ( struct V_23 * V_24 )
{
int V_128 ;
V_128 = F_71 ( V_25 . V_131 ) ;
F_72 ( & V_24 -> V_129 , V_130 + V_128 ) ;
}
static inline T_1 F_74 ( struct V_23 * V_24 )
{
T_1 V_132 , V_36 , V_105 , V_133 ;
T_2 V_134 ;
V_53 V_135 ;
V_132 = V_24 -> V_114 . V_119 ;
V_36 = F_7 ( V_24 -> V_35 . V_36 ) ;
V_105 = F_7 ( V_24 -> V_35 . V_105 ) ;
V_132 = F_1 ( V_132 , F_2 ( V_36 , V_105 ) ) ;
V_135 = V_25 . V_131 * V_136 ;
V_134 = F_75 ( V_24 -> V_114 . time ,
V_24 -> V_125 ) ;
if ( V_134 > V_135 * 3 ) {
V_133 = F_2 ( F_7 ( V_135 ) ,
F_7 ( V_134 ) ) ;
V_132 = F_1 ( V_132 , V_133 ) ;
}
return V_132 ;
}
static inline void F_76 ( struct V_23 * V_24 )
{
T_1 V_137 ;
struct V_7 * V_8 ;
signed int V_138 ;
int V_139 ;
struct V_114 * V_114 ;
V_139 = V_24 -> V_35 . V_105 ;
V_8 = & V_24 -> V_8 ;
V_137 = F_74 ( V_24 ) ;
V_138 = F_11 ( V_8 , V_137 ) ;
F_60 ( V_24 , V_24 -> V_35 . V_105 - V_138 , true ) ;
V_114 = & V_24 -> V_114 ;
F_77 ( F_5 ( V_114 -> V_119 ) ,
F_5 ( V_137 ) ,
V_139 ,
V_24 -> V_35 . V_105 ,
V_114 -> V_117 ,
V_114 -> V_116 ,
V_114 -> V_121 ,
V_114 -> V_118 ) ;
}
static void F_78 ( unsigned long V_140 )
{
struct V_23 * V_24 = (struct V_23 * ) V_140 ;
F_65 ( V_24 ) ;
F_70 ( V_24 ) ;
}
static void F_79 ( unsigned long V_140 )
{
struct V_23 * V_24 = (struct V_23 * ) V_140 ;
F_65 ( V_24 ) ;
F_76 ( V_24 ) ;
F_73 ( V_24 ) ;
}
static int F_80 ( unsigned int V_141 )
{
struct V_23 * V_24 ;
if ( ! V_29 [ V_141 ] )
V_29 [ V_141 ] = F_81 ( sizeof( struct V_23 ) ,
V_142 ) ;
if ( ! V_29 [ V_141 ] )
return - V_143 ;
V_24 = V_29 [ V_141 ] ;
V_24 -> V_24 = V_141 ;
if ( V_57 )
F_45 ( V_24 ) ;
F_62 ( V_24 ) ;
F_82 ( & V_24 -> V_129 ) ;
V_24 -> V_129 . V_51 = ( unsigned long ) V_24 ;
V_24 -> V_129 . V_144 = V_130 + V_145 / 100 ;
if ( ! V_57 )
V_24 -> V_129 . V_146 = F_79 ;
else
V_24 -> V_129 . V_146 = F_78 ;
F_12 ( V_24 ) ;
F_65 ( V_24 ) ;
F_83 ( & V_24 -> V_129 , V_141 ) ;
F_84 ( L_7 , V_141 ) ;
return 0 ;
}
static unsigned int F_85 ( unsigned int V_147 )
{
struct V_114 * V_114 ;
struct V_23 * V_24 ;
V_24 = V_29 [ V_147 ] ;
if ( ! V_24 )
return 0 ;
V_114 = & V_24 -> V_114 ;
return V_114 -> V_118 ;
}
static int F_86 ( struct V_148 * V_149 )
{
if ( ! V_149 -> V_150 . V_151 )
return - V_152 ;
if ( V_149 -> V_149 == V_153 &&
V_149 -> V_40 >= V_149 -> V_150 . V_151 ) {
V_32 . V_78 = 100 ;
V_32 . V_48 = 100 ;
V_32 . V_81 = F_7 ( 1 ) ;
V_32 . V_77 = 100 ;
V_32 . V_49 = 100 ;
V_32 . V_79 = F_7 ( 1 ) ;
V_32 . V_50 = 0 ;
return 0 ;
}
V_32 . V_78 = ( V_149 -> V_38 * 100 ) / V_149 -> V_150 . V_151 ;
V_32 . V_78 = F_38 ( int , V_32 . V_78 , 0 , 100 ) ;
V_32 . V_77 = ( V_149 -> V_40 * 100 ) / V_149 -> V_150 . V_151 ;
V_32 . V_77 = F_38 ( int , V_32 . V_77 , 0 , 100 ) ;
V_32 . V_48 = V_40 ( V_32 . V_78 , V_32 . V_80 ) ;
V_32 . V_48 = V_38 ( V_32 . V_77 , V_32 . V_48 ) ;
V_32 . V_49 = V_38 ( V_32 . V_77 , V_32 . V_76 ) ;
V_32 . V_49 = V_40 ( V_32 . V_78 , V_32 . V_49 ) ;
V_32 . V_48 = V_38 ( V_32 . V_49 , V_32 . V_48 ) ;
V_32 . V_81 = F_2 ( F_7 ( V_32 . V_48 ) , F_7 ( 100 ) ) ;
V_32 . V_79 = F_2 ( F_7 ( V_32 . V_49 ) , F_7 ( 100 ) ) ;
if ( V_57 )
F_17 () ;
return 0 ;
}
static int F_87 ( struct V_148 * V_149 )
{
F_88 ( V_149 ) ;
if ( V_149 -> V_149 != V_154 &&
V_149 -> V_149 != V_153 )
return - V_74 ;
return 0 ;
}
static void F_89 ( struct V_148 * V_149 )
{
int V_147 = V_149 -> V_24 ;
struct V_23 * V_24 = V_29 [ V_147 ] ;
F_84 ( L_8 , V_147 ) ;
F_90 ( & V_29 [ V_147 ] -> V_129 ) ;
if ( V_57 )
return;
F_60 ( V_24 , V_24 -> V_35 . V_69 , false ) ;
}
static int F_91 ( struct V_148 * V_149 )
{
struct V_23 * V_24 ;
int V_83 ;
V_83 = F_80 ( V_149 -> V_24 ) ;
if ( V_83 )
return V_83 ;
V_24 = V_29 [ V_149 -> V_24 ] ;
if ( V_32 . V_48 == 100 && V_32 . V_49 == 100 )
V_149 -> V_149 = V_153 ;
else
V_149 -> V_149 = V_154 ;
V_149 -> V_38 = V_24 -> V_35 . V_69 * V_24 -> V_35 . V_106 ;
V_149 -> V_40 = V_24 -> V_35 . V_37 * V_24 -> V_35 . V_106 ;
V_149 -> V_150 . V_155 = V_24 -> V_35 . V_69 * V_24 -> V_35 . V_106 ;
V_149 -> V_150 . V_151 =
V_24 -> V_35 . V_37 * V_24 -> V_35 . V_106 ;
V_149 -> V_150 . V_156 = V_157 ;
F_92 ( V_149 -> V_24 , V_149 -> V_158 ) ;
return 0 ;
}
static int F_93 ( void )
{
if ( ! V_107 . V_110 () ||
! V_107 . V_109 () ||
! V_107 . V_111 () )
return - V_152 ;
return 0 ;
}
static void F_94 ( struct V_159 * V_149 )
{
V_25 . V_131 = V_149 -> V_131 ;
V_25 . V_26 = V_149 -> V_26 ;
V_25 . V_28 = V_149 -> V_28 ;
V_25 . V_27 = V_149 -> V_27 ;
V_25 . V_11 = V_149 -> V_11 ;
V_25 . V_9 = V_149 -> V_9 ;
}
static void F_95 ( struct V_107 * V_160 )
{
V_107 . V_110 = V_160 -> V_110 ;
V_107 . V_109 = V_160 -> V_109 ;
V_107 . V_111 = V_160 -> V_111 ;
V_107 . V_112 = V_160 -> V_112 ;
V_107 . V_108 = V_160 -> V_108 ;
V_107 . V_113 = V_160 -> V_113 ;
}
static bool F_96 ( void )
{
int V_56 ;
F_97 (i) {
T_8 V_161 ;
union V_162 * V_163 ;
struct V_164 V_165 = { V_166 , NULL } ;
struct V_167 * V_168 = F_98 ( V_169 , V_56 ) ;
if ( ! V_168 )
continue;
V_161 = F_99 ( V_168 -> V_170 , L_9 , NULL , & V_165 ) ;
if ( F_100 ( V_161 ) )
continue;
V_163 = V_165 . V_171 ;
if ( V_163 && V_163 -> type == V_172 ) {
F_101 ( V_163 ) ;
return false ;
}
F_101 ( V_163 ) ;
}
return true ;
}
static bool F_102 ( void )
{
int V_56 ;
F_97 (i) {
struct V_167 * V_168 = F_98 ( V_169 , V_56 ) ;
if ( ! V_168 )
continue;
if ( F_103 ( V_168 -> V_170 , L_10 ) )
return true ;
}
return false ;
}
static bool F_104 ( void )
{
struct V_173 V_174 ;
struct V_175 * V_176 ;
const struct V_177 * V_178 ;
T_3 V_179 ;
V_178 = F_105 ( V_180 ) ;
if ( V_178 ) {
F_16 ( V_181 , V_179 ) ;
if ( V_179 & ( 1 << 8 ) )
return true ;
}
if ( V_182 ||
F_100 ( F_106 ( V_183 , 0 , & V_174 ) ) )
return false ;
for ( V_176 = V_184 ; V_176 -> V_185 ; V_176 ++ ) {
if ( ! strncmp ( V_174 . V_186 , V_176 -> V_186 , V_187 ) &&
! strncmp ( V_174 . V_188 , V_176 -> V_188 ,
V_189 ) )
switch ( V_176 -> V_190 ) {
case V_191 :
return F_96 () ;
case V_192 :
return F_102 () &&
( ! V_193 ) ;
}
}
return false ;
}
static inline bool F_104 ( void ) { return false ; }
static inline bool F_102 ( void ) { return false ; }
static int T_4 F_107 ( void )
{
int V_24 , V_83 = 0 ;
const struct V_177 * V_178 ;
struct V_194 * V_195 ;
if ( V_196 )
return - V_152 ;
V_178 = F_105 ( V_197 ) ;
if ( ! V_178 )
return - V_152 ;
if ( F_104 () )
return - V_152 ;
V_195 = (struct V_194 * ) V_178 -> V_198 ;
F_94 ( & V_195 -> V_199 ) ;
F_95 ( & V_195 -> V_160 ) ;
if ( F_93 () )
return - V_152 ;
F_46 ( L_11 ) ;
V_29 = F_108 ( sizeof( void * ) * F_109 () ) ;
if ( ! V_29 )
return - V_143 ;
if ( F_110 ( V_200 ) && ! V_201 )
V_57 ++ ;
if ( ! V_57 && V_202 )
goto V_203;
V_83 = F_111 ( & V_204 ) ;
if ( V_83 )
goto V_203;
F_29 () ;
F_41 () ;
return V_83 ;
V_203:
F_20 () ;
F_14 (cpu) {
if ( V_29 [ V_24 ] ) {
F_90 ( & V_29 [ V_24 ] -> V_129 ) ;
F_101 ( V_29 [ V_24 ] ) ;
}
}
F_26 () ;
F_112 ( V_29 ) ;
return - V_152 ;
}
static int T_4 F_113 ( char * V_205 )
{
if ( ! V_205 )
return - V_74 ;
if ( ! strcmp ( V_205 , L_12 ) )
V_196 = 1 ;
if ( ! strcmp ( V_205 , L_13 ) )
V_201 = 1 ;
if ( ! strcmp ( V_205 , L_14 ) )
V_193 = 1 ;
if ( ! strcmp ( V_205 , L_15 ) )
V_202 = 1 ;
return 0 ;
}
