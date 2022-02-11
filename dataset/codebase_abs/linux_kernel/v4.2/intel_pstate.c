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
int V_38 , V_39 , V_24 ;
T_3 V_40 , V_41 ;
F_18 () ;
F_14 (cpu) {
F_19 ( V_24 , V_42 , & V_40 ) ;
V_38 = F_20 ( V_32 . V_43 ) ;
V_40 &= ~ F_21 ( ~ 0L ) ;
V_40 |= F_21 ( V_38 ) ;
V_39 = F_20 ( V_32 . V_44 ) ;
if ( V_32 . V_45 ) {
F_16 ( V_46 , V_41 ) ;
V_39 = F_22 ( V_41 ) ;
}
V_40 &= ~ F_23 ( ~ 0L ) ;
V_40 |= F_23 ( V_39 ) ;
F_24 ( V_24 , V_42 , V_40 ) ;
}
F_25 () ;
}
static int F_26 ( void * V_47 , T_3 V_48 )
{
* ( V_49 * ) V_47 = V_48 ;
F_13 () ;
return 0 ;
}
static int F_27 ( void * V_47 , T_3 * V_48 )
{
* V_48 = * ( V_49 * ) V_47 ;
return 0 ;
}
static void T_4 F_28 ( void )
{
struct V_50 * V_51 ;
int V_52 = 0 ;
if ( V_53 )
return;
V_51 = F_29 ( L_1 , NULL ) ;
if ( F_30 ( V_51 ) )
return;
while ( V_54 [ V_52 ] . V_55 ) {
F_31 ( V_54 [ V_52 ] . V_55 , 0660 ,
V_51 , V_54 [ V_52 ] . V_40 ,
& V_56 ) ;
V_52 ++ ;
}
}
static T_5 F_32 ( struct V_57 * V_58 ,
struct V_59 * V_60 , char * V_61 )
{
struct V_23 * V_24 ;
int V_62 , V_45 , V_63 ;
T_6 V_64 ;
V_24 = V_29 [ 0 ] ;
V_62 = V_24 -> V_35 . V_37 - V_24 -> V_35 . V_65 + 1 ;
V_45 = V_24 -> V_35 . V_36 - V_24 -> V_35 . V_65 + 1 ;
V_64 = F_2 ( F_7 ( V_45 ) , F_7 ( V_62 ) ) ;
V_63 = 100 - F_5 ( F_1 ( V_64 , F_7 ( 100 ) ) ) ;
return sprintf ( V_61 , L_2 , V_63 ) ;
}
static T_5 F_33 ( struct V_57 * V_58 ,
struct V_59 * V_60 , char * V_61 )
{
struct V_23 * V_24 ;
int V_62 ;
V_24 = V_29 [ 0 ] ;
V_62 = V_24 -> V_35 . V_37 - V_24 -> V_35 . V_65 + 1 ;
return sprintf ( V_61 , L_2 , V_62 ) ;
}
static T_5 F_34 ( struct V_57 * V_58 ,
struct V_59 * V_60 , char * V_61 )
{
T_5 V_6 ;
F_15 () ;
if ( V_32 . V_33 )
V_6 = sprintf ( V_61 , L_2 , V_32 . V_33 ) ;
else
V_6 = sprintf ( V_61 , L_2 , V_32 . V_45 ) ;
return V_6 ;
}
static T_5 F_35 ( struct V_57 * V_66 , struct V_59 * V_67 ,
const char * V_61 , T_7 V_68 )
{
unsigned int V_69 ;
int V_6 ;
V_6 = sscanf ( V_61 , L_3 , & V_69 ) ;
if ( V_6 != 1 )
return - V_70 ;
F_15 () ;
if ( V_32 . V_33 ) {
F_36 ( L_4 ) ;
return - V_71 ;
}
V_32 . V_45 = F_37 ( int , V_69 , 0 , 1 ) ;
if ( V_53 )
F_17 () ;
return V_68 ;
}
static T_5 F_38 ( struct V_57 * V_66 , struct V_59 * V_67 ,
const char * V_61 , T_7 V_68 )
{
unsigned int V_69 ;
int V_6 ;
V_6 = sscanf ( V_61 , L_3 , & V_69 ) ;
if ( V_6 != 1 )
return - V_70 ;
V_32 . V_72 = F_37 ( int , V_69 , 0 , 100 ) ;
V_32 . V_44 = V_38 ( V_32 . V_73 , V_32 . V_72 ) ;
V_32 . V_74 = F_2 ( F_7 ( V_32 . V_44 ) , F_7 ( 100 ) ) ;
if ( V_53 )
F_17 () ;
return V_68 ;
}
static T_5 F_39 ( struct V_57 * V_66 , struct V_59 * V_67 ,
const char * V_61 , T_7 V_68 )
{
unsigned int V_69 ;
int V_6 ;
V_6 = sscanf ( V_61 , L_3 , & V_69 ) ;
if ( V_6 != 1 )
return - V_70 ;
V_32 . V_75 = F_37 ( int , V_69 , 0 , 100 ) ;
V_32 . V_43 = V_39 ( V_32 . V_76 , V_32 . V_75 ) ;
V_32 . V_77 = F_2 ( F_7 ( V_32 . V_43 ) , F_7 ( 100 ) ) ;
if ( V_53 )
F_17 () ;
return V_68 ;
}
static void T_4 F_40 ( void )
{
struct V_57 * V_78 ;
int V_79 ;
V_78 = F_41 ( L_5 ,
& V_80 . V_81 -> V_58 ) ;
F_42 ( ! V_78 ) ;
V_79 = F_43 ( V_78 , & V_82 ) ;
F_42 ( V_79 ) ;
}
static void F_44 ( void )
{
V_53 ++ ;
F_45 ( L_6 ) ;
F_46 ( V_83 , 0x1 ) ;
}
static int F_47 ( void )
{
T_3 V_40 ;
F_16 ( V_84 , V_40 ) ;
return ( V_40 >> 8 ) & 0x7F ;
}
static int F_48 ( void )
{
T_3 V_40 ;
F_16 ( V_84 , V_40 ) ;
return ( V_40 >> 16 ) & 0x7F ;
}
static int F_49 ( void )
{
T_3 V_40 ;
F_16 ( V_85 , V_40 ) ;
return V_40 & 0x7F ;
}
static void F_50 ( struct V_23 * V_23 , int V_35 )
{
T_3 V_48 ;
T_1 V_86 ;
V_49 V_87 ;
V_48 = V_35 << 8 ;
if ( V_32 . V_45 && ! V_32 . V_33 )
V_48 |= ( T_3 ) 1 << 32 ;
V_86 = V_23 -> V_87 . V_38 + F_1 (
F_7 ( V_35 - V_23 -> V_35 . V_65 ) ,
V_23 -> V_87 . V_88 ) ;
V_86 = F_37 ( T_1 , V_86 , V_23 -> V_87 . V_38 , V_23 -> V_87 . V_39 ) ;
V_87 = F_4 ( V_86 ) ;
if ( V_35 > V_23 -> V_35 . V_36 )
V_87 = V_23 -> V_87 . V_89 ;
V_48 |= V_87 ;
F_24 ( V_23 -> V_24 , V_90 , V_48 ) ;
}
static int F_51 ( void )
{
T_3 V_40 ;
int V_52 ;
F_16 ( V_91 , V_40 ) ;
V_52 = V_40 & 0x3 ;
F_42 ( V_52 > V_92 ) ;
return V_93 [ V_52 ] * 100 ;
}
static void F_52 ( struct V_23 * V_23 )
{
T_3 V_40 ;
F_16 ( V_94 , V_40 ) ;
V_23 -> V_87 . V_38 = F_7 ( ( V_40 >> 8 ) & 0x7f ) ;
V_23 -> V_87 . V_39 = F_7 ( ( V_40 >> 16 ) & 0x7f ) ;
V_23 -> V_87 . V_88 = F_2 (
V_23 -> V_87 . V_39 - V_23 -> V_87 . V_38 ,
F_7 ( V_23 -> V_35 . V_36 -
V_23 -> V_35 . V_65 ) ) ;
F_16 ( V_95 , V_40 ) ;
V_23 -> V_87 . V_89 = V_40 & 0x7f ;
}
static int F_53 ( void )
{
T_3 V_40 ;
F_16 ( V_96 , V_40 ) ;
return ( V_40 >> 40 ) & 0xFF ;
}
static int F_54 ( void )
{
T_3 V_40 ;
F_16 ( V_96 , V_40 ) ;
return ( V_40 >> 8 ) & 0xFF ;
}
static int F_55 ( void )
{
T_3 V_40 ;
int V_97 , V_6 ;
F_16 ( V_98 , V_40 ) ;
V_97 = F_54 () ;
V_6 = ( V_40 ) & 255 ;
if ( V_6 <= V_97 )
V_6 = V_97 ;
return V_6 ;
}
static inline int F_56 ( void )
{
return 100000 ;
}
static void F_57 ( struct V_23 * V_23 , int V_35 )
{
T_3 V_48 ;
V_48 = V_35 << 8 ;
if ( V_32 . V_45 && ! V_32 . V_33 )
V_48 |= ( T_3 ) 1 << 32 ;
F_24 ( V_23 -> V_24 , V_90 , V_48 ) ;
}
static int F_58 ( void )
{
T_3 V_40 ;
int V_97 , V_6 ;
F_16 ( V_98 , V_40 ) ;
V_97 = F_54 () ;
V_6 = ( ( ( V_40 ) >> 8 ) & 0xFF ) ;
if ( V_6 <= V_97 )
V_6 = V_97 ;
return V_6 ;
}
static void F_59 ( struct V_23 * V_24 , int * V_38 , int * V_39 )
{
int V_74 = V_24 -> V_35 . V_37 ;
int V_99 ;
int V_77 ;
if ( V_32 . V_45 || V_32 . V_33 )
V_74 = V_24 -> V_35 . V_36 ;
V_99 = F_5 ( F_1 ( F_7 ( V_74 ) , V_32 . V_74 ) ) ;
* V_39 = F_37 ( int , V_99 ,
V_24 -> V_35 . V_65 , V_24 -> V_35 . V_37 ) ;
V_77 = F_5 ( F_1 ( F_7 ( V_74 ) , V_32 . V_77 ) ) ;
* V_38 = F_37 ( int , V_77 , V_24 -> V_35 . V_65 , V_74 ) ;
}
static void F_60 ( struct V_23 * V_24 , int V_35 , bool V_100 )
{
int V_74 , V_77 ;
if ( V_100 ) {
F_15 () ;
F_59 ( V_24 , & V_77 , & V_74 ) ;
V_35 = F_37 ( int , V_35 , V_77 , V_74 ) ;
if ( V_35 == V_24 -> V_35 . V_101 )
return;
}
F_61 ( V_35 * V_24 -> V_35 . V_102 , V_24 -> V_24 ) ;
V_24 -> V_35 . V_101 = V_35 ;
V_103 . V_104 ( V_24 , V_35 ) ;
}
static void F_62 ( struct V_23 * V_24 )
{
V_24 -> V_35 . V_65 = V_103 . V_105 () ;
V_24 -> V_35 . V_36 = V_103 . V_106 () ;
V_24 -> V_35 . V_37 = V_103 . V_107 () ;
V_24 -> V_35 . V_102 = V_103 . V_108 () ;
if ( V_103 . V_109 )
V_103 . V_109 ( V_24 ) ;
F_60 ( V_24 , V_24 -> V_35 . V_65 , false ) ;
}
static inline void F_63 ( struct V_23 * V_24 )
{
struct V_110 * V_110 = & V_24 -> V_110 ;
V_3 V_111 ;
V_111 = F_7 ( V_110 -> V_112 ) * F_7 ( 100 ) ;
V_111 = F_64 ( V_111 , F_7 ( V_110 -> V_113 ) ) ;
V_110 -> V_41 = F_5 (
F_1 ( F_7 (
V_24 -> V_35 . V_36 * V_24 -> V_35 . V_102 / 100 ) ,
V_111 ) ) ;
V_110 -> V_114 = ( T_1 ) V_111 ;
}
static inline void F_65 ( struct V_23 * V_24 )
{
T_3 V_112 , V_113 ;
unsigned long V_115 ;
T_3 V_116 ;
F_66 ( V_115 ) ;
F_16 ( V_117 , V_112 ) ;
F_16 ( V_118 , V_113 ) ;
V_116 = F_67 () ;
F_68 ( V_115 ) ;
V_24 -> V_119 = V_24 -> V_110 . time ;
V_24 -> V_110 . time = F_69 () ;
V_24 -> V_110 . V_112 = V_112 ;
V_24 -> V_110 . V_113 = V_113 ;
V_24 -> V_110 . V_116 = V_116 ;
V_24 -> V_110 . V_112 -= V_24 -> V_120 ;
V_24 -> V_110 . V_113 -= V_24 -> V_121 ;
V_24 -> V_110 . V_116 -= V_24 -> V_122 ;
F_63 ( V_24 ) ;
V_24 -> V_120 = V_112 ;
V_24 -> V_121 = V_113 ;
V_24 -> V_122 = V_116 ;
}
static inline void F_70 ( struct V_23 * V_24 )
{
int V_123 ;
V_123 = F_71 ( 50 ) ;
F_72 ( & V_24 -> V_124 , V_125 + V_123 ) ;
}
static inline void F_73 ( struct V_23 * V_24 )
{
int V_123 ;
V_123 = F_71 ( V_25 . V_126 ) ;
F_72 ( & V_24 -> V_124 , V_125 + V_123 ) ;
}
static inline T_1 F_74 ( struct V_23 * V_24 )
{
T_1 V_127 , V_36 , V_101 , V_128 ;
T_2 V_129 ;
V_49 V_130 ;
V_127 = V_24 -> V_110 . V_114 ;
V_36 = F_7 ( V_24 -> V_35 . V_36 ) ;
V_101 = F_7 ( V_24 -> V_35 . V_101 ) ;
V_127 = F_1 ( V_127 , F_2 ( V_36 , V_101 ) ) ;
V_130 = V_25 . V_126 * V_131 ;
V_129 = F_75 ( V_24 -> V_110 . time ,
V_24 -> V_119 ) ;
if ( V_129 > V_130 * 3 ) {
V_128 = F_2 ( F_7 ( V_130 ) ,
F_7 ( V_129 ) ) ;
V_127 = F_1 ( V_127 , V_128 ) ;
}
return V_127 ;
}
static inline void F_76 ( struct V_23 * V_24 )
{
T_1 V_132 ;
struct V_7 * V_8 ;
signed int V_133 ;
int V_134 ;
struct V_110 * V_110 ;
V_134 = V_24 -> V_35 . V_101 ;
V_8 = & V_24 -> V_8 ;
V_132 = F_74 ( V_24 ) ;
V_133 = F_11 ( V_8 , V_132 ) ;
F_60 ( V_24 , V_24 -> V_35 . V_101 - V_133 , true ) ;
V_110 = & V_24 -> V_110 ;
F_77 ( F_5 ( V_110 -> V_114 ) ,
F_5 ( V_132 ) ,
V_134 ,
V_24 -> V_35 . V_101 ,
V_110 -> V_113 ,
V_110 -> V_112 ,
V_110 -> V_116 ,
V_110 -> V_41 ) ;
}
static void F_78 ( unsigned long V_135 )
{
struct V_23 * V_24 = (struct V_23 * ) V_135 ;
F_65 ( V_24 ) ;
F_70 ( V_24 ) ;
}
static void F_79 ( unsigned long V_135 )
{
struct V_23 * V_24 = (struct V_23 * ) V_135 ;
F_65 ( V_24 ) ;
F_76 ( V_24 ) ;
F_73 ( V_24 ) ;
}
static int F_80 ( unsigned int V_136 )
{
struct V_23 * V_24 ;
if ( ! V_29 [ V_136 ] )
V_29 [ V_136 ] = F_81 ( sizeof( struct V_23 ) ,
V_137 ) ;
if ( ! V_29 [ V_136 ] )
return - V_138 ;
V_24 = V_29 [ V_136 ] ;
V_24 -> V_24 = V_136 ;
F_62 ( V_24 ) ;
F_82 ( & V_24 -> V_124 ) ;
V_24 -> V_124 . V_47 = ( unsigned long ) V_24 ;
V_24 -> V_124 . V_139 = V_125 + V_140 / 100 ;
if ( ! V_53 )
V_24 -> V_124 . V_141 = F_79 ;
else
V_24 -> V_124 . V_141 = F_78 ;
F_12 ( V_24 ) ;
F_65 ( V_24 ) ;
F_83 ( & V_24 -> V_124 , V_136 ) ;
F_84 ( L_7 , V_136 ) ;
return 0 ;
}
static unsigned int F_85 ( unsigned int V_142 )
{
struct V_110 * V_110 ;
struct V_23 * V_24 ;
V_24 = V_29 [ V_142 ] ;
if ( ! V_24 )
return 0 ;
V_110 = & V_24 -> V_110 ;
return V_110 -> V_41 ;
}
static int F_86 ( struct V_143 * V_144 )
{
if ( ! V_144 -> V_145 . V_146 )
return - V_147 ;
if ( V_144 -> V_144 == V_148 &&
V_144 -> V_39 >= V_144 -> V_145 . V_146 ) {
V_32 . V_76 = 100 ;
V_32 . V_43 = 100 ;
V_32 . V_77 = F_7 ( 1 ) ;
V_32 . V_73 = 100 ;
V_32 . V_44 = 100 ;
V_32 . V_74 = F_7 ( 1 ) ;
V_32 . V_45 = 0 ;
return 0 ;
}
V_32 . V_76 = ( V_144 -> V_38 * 100 ) / V_144 -> V_145 . V_146 ;
V_32 . V_76 = F_37 ( int , V_32 . V_76 , 0 , 100 ) ;
V_32 . V_43 = V_39 ( V_32 . V_76 , V_32 . V_75 ) ;
V_32 . V_77 = F_2 ( F_7 ( V_32 . V_43 ) , F_7 ( 100 ) ) ;
V_32 . V_73 = ( V_144 -> V_39 * 100 ) / V_144 -> V_145 . V_146 ;
V_32 . V_73 = F_37 ( int , V_32 . V_73 , 0 , 100 ) ;
V_32 . V_44 = V_38 ( V_32 . V_73 , V_32 . V_72 ) ;
V_32 . V_74 = F_2 ( F_7 ( V_32 . V_44 ) , F_7 ( 100 ) ) ;
if ( V_53 )
F_17 () ;
return 0 ;
}
static int F_87 ( struct V_143 * V_144 )
{
F_88 ( V_144 ) ;
if ( V_144 -> V_144 != V_149 &&
V_144 -> V_144 != V_148 )
return - V_70 ;
return 0 ;
}
static void F_89 ( struct V_143 * V_144 )
{
int V_142 = V_144 -> V_24 ;
struct V_23 * V_24 = V_29 [ V_142 ] ;
F_84 ( L_8 , V_142 ) ;
F_90 ( & V_29 [ V_142 ] -> V_124 ) ;
if ( V_53 )
return;
F_60 ( V_24 , V_24 -> V_35 . V_65 , false ) ;
}
static int F_91 ( struct V_143 * V_144 )
{
struct V_23 * V_24 ;
int V_79 ;
V_79 = F_80 ( V_144 -> V_24 ) ;
if ( V_79 )
return V_79 ;
V_24 = V_29 [ V_144 -> V_24 ] ;
if ( V_32 . V_43 == 100 && V_32 . V_44 == 100 )
V_144 -> V_144 = V_148 ;
else
V_144 -> V_144 = V_149 ;
V_144 -> V_38 = V_24 -> V_35 . V_65 * V_24 -> V_35 . V_102 ;
V_144 -> V_39 = V_24 -> V_35 . V_37 * V_24 -> V_35 . V_102 ;
V_144 -> V_145 . V_150 = V_24 -> V_35 . V_65 * V_24 -> V_35 . V_102 ;
V_144 -> V_145 . V_146 =
V_24 -> V_35 . V_37 * V_24 -> V_35 . V_102 ;
V_144 -> V_145 . V_151 = V_152 ;
F_92 ( V_144 -> V_24 , V_144 -> V_153 ) ;
return 0 ;
}
static int F_93 ( void )
{
if ( ! V_103 . V_106 () ||
! V_103 . V_105 () ||
! V_103 . V_107 () )
return - V_147 ;
return 0 ;
}
static void F_94 ( struct V_154 * V_144 )
{
V_25 . V_126 = V_144 -> V_126 ;
V_25 . V_26 = V_144 -> V_26 ;
V_25 . V_28 = V_144 -> V_28 ;
V_25 . V_27 = V_144 -> V_27 ;
V_25 . V_11 = V_144 -> V_11 ;
V_25 . V_9 = V_144 -> V_9 ;
}
static void F_95 ( struct V_103 * V_155 )
{
V_103 . V_106 = V_155 -> V_106 ;
V_103 . V_105 = V_155 -> V_105 ;
V_103 . V_107 = V_155 -> V_107 ;
V_103 . V_108 = V_155 -> V_108 ;
V_103 . V_104 = V_155 -> V_104 ;
V_103 . V_109 = V_155 -> V_109 ;
}
static bool F_96 ( void )
{
int V_52 ;
F_97 (i) {
T_8 V_156 ;
union V_157 * V_158 ;
struct V_159 V_160 = { V_161 , NULL } ;
struct V_162 * V_163 = F_98 ( V_164 , V_52 ) ;
if ( ! V_163 )
continue;
V_156 = F_99 ( V_163 -> V_165 , L_9 , NULL , & V_160 ) ;
if ( F_100 ( V_156 ) )
continue;
V_158 = V_160 . V_166 ;
if ( V_158 && V_158 -> type == V_167 ) {
F_101 ( V_158 ) ;
return false ;
}
F_101 ( V_158 ) ;
}
return true ;
}
static bool F_102 ( void )
{
int V_52 ;
F_97 (i) {
struct V_162 * V_163 = F_98 ( V_164 , V_52 ) ;
if ( ! V_163 )
continue;
if ( F_103 ( V_163 -> V_165 , L_10 ) )
return true ;
}
return false ;
}
static bool F_104 ( void )
{
struct V_168 V_169 ;
struct V_170 * V_171 ;
const struct V_172 * V_173 ;
T_3 V_174 ;
V_173 = F_105 ( V_175 ) ;
if ( V_173 ) {
F_16 ( V_176 , V_174 ) ;
if ( V_174 & ( 1 << 8 ) )
return true ;
}
if ( V_177 ||
F_100 ( F_106 ( V_178 , 0 , & V_169 ) ) )
return false ;
for ( V_171 = V_179 ; V_171 -> V_180 ; V_171 ++ ) {
if ( ! strncmp ( V_169 . V_181 , V_171 -> V_181 , V_182 ) &&
! strncmp ( V_169 . V_183 , V_171 -> V_183 ,
V_184 ) )
switch ( V_171 -> V_185 ) {
case V_186 :
return F_96 () ;
case V_187 :
return F_102 () &&
( ! V_188 ) ;
}
}
return false ;
}
static inline bool F_104 ( void ) { return false ; }
static inline bool F_102 ( void ) { return false ; }
static int T_4 F_107 ( void )
{
int V_24 , V_79 = 0 ;
const struct V_172 * V_173 ;
struct V_189 * V_190 ;
if ( V_191 )
return - V_147 ;
V_173 = F_105 ( V_192 ) ;
if ( ! V_173 )
return - V_147 ;
if ( F_104 () )
return - V_147 ;
V_190 = (struct V_189 * ) V_173 -> V_193 ;
F_94 ( & V_190 -> V_194 ) ;
F_95 ( & V_190 -> V_155 ) ;
if ( F_93 () )
return - V_147 ;
F_45 ( L_11 ) ;
V_29 = F_108 ( sizeof( void * ) * F_109 () ) ;
if ( ! V_29 )
return - V_138 ;
if ( F_110 ( V_195 ) && ! V_196 )
F_44 () ;
if ( ! V_53 && V_197 )
goto V_198;
V_79 = F_111 ( & V_199 ) ;
if ( V_79 )
goto V_198;
F_28 () ;
F_40 () ;
return V_79 ;
V_198:
F_18 () ;
F_14 (cpu) {
if ( V_29 [ V_24 ] ) {
F_90 ( & V_29 [ V_24 ] -> V_124 ) ;
F_101 ( V_29 [ V_24 ] ) ;
}
}
F_25 () ;
F_112 ( V_29 ) ;
return - V_147 ;
}
static int T_4 F_113 ( char * V_200 )
{
if ( ! V_200 )
return - V_70 ;
if ( ! strcmp ( V_200 , L_12 ) )
V_191 = 1 ;
if ( ! strcmp ( V_200 , L_13 ) )
V_196 = 1 ;
if ( ! strcmp ( V_200 , L_14 ) )
V_188 = 1 ;
if ( ! strcmp ( V_200 , L_15 ) )
V_197 = 1 ;
return 0 ;
}
