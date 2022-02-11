static inline T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
return ( ( V_3 ) V_1 * ( V_3 ) V_2 ) >> V_4 ;
}
static inline T_1 F_2 ( T_1 V_1 , T_1 V_2 )
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
T_2 V_30 ;
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
T_2 V_40 , V_41 ;
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
static int F_26 ( void * V_47 , T_2 V_48 )
{
* ( V_49 * ) V_47 = V_48 ;
F_13 () ;
return 0 ;
}
static int F_27 ( void * V_47 , T_2 * V_48 )
{
* V_48 = * ( V_49 * ) V_47 ;
return 0 ;
}
static void T_3 F_28 ( void )
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
static T_4 F_32 ( struct V_57 * V_58 ,
struct V_59 * V_60 , char * V_61 )
{
struct V_23 * V_24 ;
int V_62 , V_45 , V_63 ;
T_5 V_64 ;
V_24 = V_29 [ 0 ] ;
V_62 = V_24 -> V_35 . V_37 - V_24 -> V_35 . V_65 + 1 ;
V_45 = V_24 -> V_35 . V_36 - V_24 -> V_35 . V_65 + 1 ;
V_64 = F_2 ( F_7 ( V_45 ) , F_7 ( V_62 ) ) ;
V_63 = 100 - F_5 ( F_1 ( V_64 , F_7 ( 100 ) ) ) ;
return sprintf ( V_61 , L_2 , V_63 ) ;
}
static T_4 F_33 ( struct V_57 * V_58 ,
struct V_59 * V_60 , char * V_61 )
{
struct V_23 * V_24 ;
int V_62 ;
V_24 = V_29 [ 0 ] ;
V_62 = V_24 -> V_35 . V_37 - V_24 -> V_35 . V_65 + 1 ;
return sprintf ( V_61 , L_2 , V_62 ) ;
}
static T_4 F_34 ( struct V_57 * V_58 ,
struct V_59 * V_60 , char * V_61 )
{
T_4 V_6 ;
F_15 () ;
if ( V_32 . V_33 )
V_6 = sprintf ( V_61 , L_2 , V_32 . V_33 ) ;
else
V_6 = sprintf ( V_61 , L_2 , V_32 . V_45 ) ;
return V_6 ;
}
static T_4 F_35 ( struct V_57 * V_66 , struct V_59 * V_67 ,
const char * V_61 , T_6 V_68 )
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
static T_4 F_38 ( struct V_57 * V_66 , struct V_59 * V_67 ,
const char * V_61 , T_6 V_68 )
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
static T_4 F_39 ( struct V_57 * V_66 , struct V_59 * V_67 ,
const char * V_61 , T_6 V_68 )
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
static void T_3 F_40 ( void )
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
T_2 V_40 ;
F_16 ( V_84 , V_40 ) ;
return ( V_40 >> 8 ) & 0x7F ;
}
static int F_48 ( void )
{
T_2 V_40 ;
F_16 ( V_84 , V_40 ) ;
return ( V_40 >> 16 ) & 0x7F ;
}
static int F_49 ( void )
{
T_2 V_40 ;
F_16 ( V_85 , V_40 ) ;
return V_40 & 0x7F ;
}
static void F_50 ( struct V_23 * V_23 , int V_35 )
{
T_2 V_48 ;
T_1 V_86 ;
V_49 V_87 ;
V_48 = V_35 << 8 ;
if ( V_32 . V_45 && ! V_32 . V_33 )
V_48 |= ( T_2 ) 1 << 32 ;
V_86 = V_23 -> V_87 . V_38 + F_1 (
F_7 ( V_35 - V_23 -> V_35 . V_65 ) ,
V_23 -> V_87 . V_88 ) ;
V_86 = F_37 ( T_1 , V_86 , V_23 -> V_87 . V_38 , V_23 -> V_87 . V_39 ) ;
V_87 = F_4 ( V_86 ) ;
if ( V_35 > V_23 -> V_35 . V_36 )
V_87 = V_23 -> V_87 . V_89 ;
V_48 |= V_87 ;
F_46 ( V_90 , V_48 ) ;
}
static int F_51 ( void )
{
T_2 V_40 ;
int V_52 ;
F_16 ( V_91 , V_40 ) ;
V_52 = V_40 & 0x3 ;
F_42 ( V_52 > V_92 ) ;
return V_93 [ V_52 ] * 100 ;
}
static void F_52 ( struct V_23 * V_23 )
{
T_2 V_40 ;
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
T_2 V_40 ;
F_16 ( V_96 , V_40 ) ;
return ( V_40 >> 40 ) & 0xFF ;
}
static int F_54 ( void )
{
T_2 V_40 ;
F_16 ( V_96 , V_40 ) ;
return ( V_40 >> 8 ) & 0xFF ;
}
static int F_55 ( void )
{
T_2 V_40 ;
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
T_2 V_48 ;
V_48 = V_35 << 8 ;
if ( V_32 . V_45 && ! V_32 . V_33 )
V_48 |= ( T_2 ) 1 << 32 ;
F_24 ( V_23 -> V_24 , V_90 , V_48 ) ;
}
static int F_58 ( void )
{
T_2 V_40 ;
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
static void F_60 ( struct V_23 * V_24 , int V_35 )
{
int V_74 , V_77 ;
F_15 () ;
F_59 ( V_24 , & V_77 , & V_74 ) ;
V_35 = F_37 ( int , V_35 , V_77 , V_74 ) ;
if ( V_35 == V_24 -> V_35 . V_100 )
return;
F_61 ( V_35 * V_24 -> V_35 . V_101 , V_24 -> V_24 ) ;
V_24 -> V_35 . V_100 = V_35 ;
V_102 . V_103 ( V_24 , V_35 ) ;
}
static void F_62 ( struct V_23 * V_24 )
{
V_24 -> V_35 . V_65 = V_102 . V_104 () ;
V_24 -> V_35 . V_36 = V_102 . V_105 () ;
V_24 -> V_35 . V_37 = V_102 . V_106 () ;
V_24 -> V_35 . V_101 = V_102 . V_107 () ;
if ( V_102 . V_108 )
V_102 . V_108 ( V_24 ) ;
F_60 ( V_24 , V_24 -> V_35 . V_65 ) ;
}
static inline void F_63 ( struct V_23 * V_24 )
{
struct V_109 * V_109 = & V_24 -> V_109 ;
V_3 V_110 ;
V_110 = F_7 ( V_109 -> V_111 ) * F_7 ( 100 ) ;
V_110 = F_64 ( V_110 , F_7 ( V_109 -> V_112 ) ) ;
V_109 -> V_41 = F_5 (
F_1 ( F_7 (
V_24 -> V_35 . V_36 * V_24 -> V_35 . V_101 / 100 ) ,
V_110 ) ) ;
V_109 -> V_113 = ( T_1 ) V_110 ;
}
static inline void F_65 ( struct V_23 * V_24 )
{
T_2 V_111 , V_112 ;
unsigned long V_114 ;
F_66 ( V_114 ) ;
F_16 ( V_115 , V_111 ) ;
F_16 ( V_116 , V_112 ) ;
F_67 ( V_114 ) ;
V_24 -> V_117 = V_24 -> V_109 . time ;
V_24 -> V_109 . time = F_68 () ;
V_24 -> V_109 . V_111 = V_111 ;
V_24 -> V_109 . V_112 = V_112 ;
V_24 -> V_109 . V_111 -= V_24 -> V_118 ;
V_24 -> V_109 . V_112 -= V_24 -> V_119 ;
F_63 ( V_24 ) ;
V_24 -> V_118 = V_111 ;
V_24 -> V_119 = V_112 ;
}
static inline void F_69 ( struct V_23 * V_24 )
{
int V_120 ;
V_120 = F_70 ( 50 ) ;
F_71 ( & V_24 -> V_121 , V_122 + V_120 ) ;
}
static inline void F_72 ( struct V_23 * V_24 )
{
int V_120 ;
V_120 = F_70 ( V_25 . V_123 ) ;
F_71 ( & V_24 -> V_121 , V_122 + V_120 ) ;
}
static inline T_1 F_73 ( struct V_23 * V_24 )
{
T_1 V_124 , V_36 , V_100 , V_125 ;
V_49 V_126 ;
V_49 V_127 ;
V_124 = V_24 -> V_109 . V_113 ;
V_36 = F_7 ( V_24 -> V_35 . V_36 ) ;
V_100 = F_7 ( V_24 -> V_35 . V_100 ) ;
V_124 = F_1 ( V_124 , F_2 ( V_36 , V_100 ) ) ;
V_127 = V_25 . V_123 * V_128 ;
V_126 = ( V_49 ) F_74 ( V_24 -> V_109 . time ,
V_24 -> V_117 ) ;
if ( V_126 > V_127 * 3 ) {
V_125 = F_2 ( F_7 ( V_127 ) ,
F_7 ( V_126 ) ) ;
V_124 = F_1 ( V_124 , V_125 ) ;
}
return V_124 ;
}
static inline void F_75 ( struct V_23 * V_24 )
{
T_1 V_129 ;
struct V_7 * V_8 ;
signed int V_130 ;
V_8 = & V_24 -> V_8 ;
V_129 = F_73 ( V_24 ) ;
V_130 = F_11 ( V_8 , V_129 ) ;
F_60 ( V_24 , V_24 -> V_35 . V_100 - V_130 ) ;
}
static void F_76 ( unsigned long V_131 )
{
struct V_23 * V_24 = (struct V_23 * ) V_131 ;
F_65 ( V_24 ) ;
F_69 ( V_24 ) ;
}
static void F_77 ( unsigned long V_131 )
{
struct V_23 * V_24 = (struct V_23 * ) V_131 ;
struct V_109 * V_109 ;
F_65 ( V_24 ) ;
V_109 = & V_24 -> V_109 ;
F_75 ( V_24 ) ;
F_78 ( F_5 ( V_109 -> V_113 ) ,
F_5 ( F_73 ( V_24 ) ) ,
V_24 -> V_35 . V_100 ,
V_109 -> V_112 ,
V_109 -> V_111 ,
V_109 -> V_41 ) ;
F_72 ( V_24 ) ;
}
static int F_79 ( unsigned int V_132 )
{
struct V_23 * V_24 ;
if ( ! V_29 [ V_132 ] )
V_29 [ V_132 ] = F_80 ( sizeof( struct V_23 ) ,
V_133 ) ;
if ( ! V_29 [ V_132 ] )
return - V_134 ;
V_24 = V_29 [ V_132 ] ;
V_24 -> V_24 = V_132 ;
F_62 ( V_24 ) ;
F_81 ( & V_24 -> V_121 ) ;
V_24 -> V_121 . V_47 = ( unsigned long ) V_24 ;
V_24 -> V_121 . V_135 = V_122 + V_136 / 100 ;
if ( ! V_53 )
V_24 -> V_121 . V_137 = F_77 ;
else
V_24 -> V_121 . V_137 = F_76 ;
F_12 ( V_24 ) ;
F_65 ( V_24 ) ;
F_82 ( & V_24 -> V_121 , V_132 ) ;
F_83 ( L_7 , V_132 ) ;
return 0 ;
}
static unsigned int F_84 ( unsigned int V_138 )
{
struct V_109 * V_109 ;
struct V_23 * V_24 ;
V_24 = V_29 [ V_138 ] ;
if ( ! V_24 )
return 0 ;
V_109 = & V_24 -> V_109 ;
return V_109 -> V_41 ;
}
static int F_85 ( struct V_139 * V_140 )
{
if ( ! V_140 -> V_141 . V_142 )
return - V_143 ;
if ( V_140 -> V_140 == V_144 &&
V_140 -> V_39 >= V_140 -> V_141 . V_142 ) {
V_32 . V_76 = 100 ;
V_32 . V_43 = 100 ;
V_32 . V_77 = F_7 ( 1 ) ;
V_32 . V_73 = 100 ;
V_32 . V_44 = 100 ;
V_32 . V_74 = F_7 ( 1 ) ;
V_32 . V_45 = 0 ;
return 0 ;
}
V_32 . V_76 = ( V_140 -> V_38 * 100 ) / V_140 -> V_141 . V_142 ;
V_32 . V_76 = F_37 ( int , V_32 . V_76 , 0 , 100 ) ;
V_32 . V_43 = V_39 ( V_32 . V_76 , V_32 . V_75 ) ;
V_32 . V_77 = F_2 ( F_7 ( V_32 . V_43 ) , F_7 ( 100 ) ) ;
V_32 . V_73 = ( V_140 -> V_39 * 100 ) / V_140 -> V_141 . V_142 ;
V_32 . V_73 = F_37 ( int , V_32 . V_73 , 0 , 100 ) ;
V_32 . V_44 = V_38 ( V_32 . V_73 , V_32 . V_72 ) ;
V_32 . V_74 = F_2 ( F_7 ( V_32 . V_44 ) , F_7 ( 100 ) ) ;
if ( V_53 )
F_17 () ;
return 0 ;
}
static int F_86 ( struct V_139 * V_140 )
{
F_87 ( V_140 ) ;
if ( V_140 -> V_140 != V_145 &&
V_140 -> V_140 != V_144 )
return - V_70 ;
return 0 ;
}
static void F_88 ( struct V_139 * V_140 )
{
int V_138 = V_140 -> V_24 ;
struct V_23 * V_24 = V_29 [ V_138 ] ;
F_45 ( L_8 , V_138 ) ;
F_89 ( & V_29 [ V_138 ] -> V_121 ) ;
if ( V_53 )
return;
F_60 ( V_24 , V_24 -> V_35 . V_65 ) ;
}
static int F_90 ( struct V_139 * V_140 )
{
struct V_23 * V_24 ;
int V_79 ;
V_79 = F_79 ( V_140 -> V_24 ) ;
if ( V_79 )
return V_79 ;
V_24 = V_29 [ V_140 -> V_24 ] ;
if ( V_32 . V_43 == 100 && V_32 . V_44 == 100 )
V_140 -> V_140 = V_144 ;
else
V_140 -> V_140 = V_145 ;
V_140 -> V_38 = V_24 -> V_35 . V_65 * V_24 -> V_35 . V_101 ;
V_140 -> V_39 = V_24 -> V_35 . V_37 * V_24 -> V_35 . V_101 ;
V_140 -> V_141 . V_146 = V_24 -> V_35 . V_65 * V_24 -> V_35 . V_101 ;
V_140 -> V_141 . V_142 =
V_24 -> V_35 . V_37 * V_24 -> V_35 . V_101 ;
V_140 -> V_141 . V_147 = V_148 ;
F_91 ( V_140 -> V_24 , V_140 -> V_149 ) ;
return 0 ;
}
static int F_92 ( void )
{
if ( ! V_102 . V_105 () ||
! V_102 . V_104 () ||
! V_102 . V_106 () )
return - V_143 ;
return 0 ;
}
static void F_93 ( struct V_150 * V_140 )
{
V_25 . V_123 = V_140 -> V_123 ;
V_25 . V_26 = V_140 -> V_26 ;
V_25 . V_28 = V_140 -> V_28 ;
V_25 . V_27 = V_140 -> V_27 ;
V_25 . V_11 = V_140 -> V_11 ;
V_25 . V_9 = V_140 -> V_9 ;
}
static void F_94 ( struct V_102 * V_151 )
{
V_102 . V_105 = V_151 -> V_105 ;
V_102 . V_104 = V_151 -> V_104 ;
V_102 . V_106 = V_151 -> V_106 ;
V_102 . V_107 = V_151 -> V_107 ;
V_102 . V_103 = V_151 -> V_103 ;
V_102 . V_108 = V_151 -> V_108 ;
}
static bool F_95 ( void )
{
int V_52 ;
F_96 (i) {
T_7 V_152 ;
union V_153 * V_154 ;
struct V_155 V_156 = { V_157 , NULL } ;
struct V_158 * V_159 = F_97 ( V_160 , V_52 ) ;
if ( ! V_159 )
continue;
V_152 = F_98 ( V_159 -> V_161 , L_9 , NULL , & V_156 ) ;
if ( F_99 ( V_152 ) )
continue;
V_154 = V_156 . V_162 ;
if ( V_154 && V_154 -> type == V_163 ) {
F_100 ( V_154 ) ;
return false ;
}
F_100 ( V_154 ) ;
}
return true ;
}
static bool F_101 ( void )
{
int V_52 ;
F_96 (i) {
struct V_158 * V_159 = F_97 ( V_160 , V_52 ) ;
if ( ! V_159 )
continue;
if ( F_102 ( V_159 -> V_161 , L_10 ) )
return true ;
}
return false ;
}
static bool F_103 ( void )
{
struct V_164 V_165 ;
struct V_166 * V_167 ;
const struct V_168 * V_169 ;
T_2 V_170 ;
V_169 = F_104 ( V_171 ) ;
if ( V_169 ) {
F_16 ( V_172 , V_170 ) ;
if ( V_170 & ( 1 << 8 ) )
return true ;
}
if ( V_173 ||
F_99 ( F_105 ( V_174 , 0 , & V_165 ) ) )
return false ;
for ( V_167 = V_175 ; V_167 -> V_176 ; V_167 ++ ) {
if ( ! strncmp ( V_165 . V_177 , V_167 -> V_177 , V_178 ) &&
! strncmp ( V_165 . V_179 , V_167 -> V_179 ,
V_180 ) )
switch ( V_167 -> V_181 ) {
case V_182 :
return F_95 () ;
case V_183 :
return F_101 () &&
( ! V_184 ) ;
}
}
return false ;
}
static inline bool F_103 ( void ) { return false ; }
static inline bool F_101 ( void ) { return false ; }
static int T_3 F_106 ( void )
{
int V_24 , V_79 = 0 ;
const struct V_168 * V_169 ;
struct V_185 * V_186 ;
if ( V_187 )
return - V_143 ;
V_169 = F_104 ( V_188 ) ;
if ( ! V_169 )
return - V_143 ;
if ( F_103 () )
return - V_143 ;
V_186 = (struct V_185 * ) V_169 -> V_189 ;
F_93 ( & V_186 -> V_190 ) ;
F_94 ( & V_186 -> V_151 ) ;
if ( F_92 () )
return - V_143 ;
F_45 ( L_11 ) ;
V_29 = F_107 ( sizeof( void * ) * F_108 () ) ;
if ( ! V_29 )
return - V_134 ;
if ( F_109 ( V_191 ) && ! V_192 )
F_44 () ;
if ( ! V_53 && V_193 )
goto V_194;
V_79 = F_110 ( & V_195 ) ;
if ( V_79 )
goto V_194;
F_28 () ;
F_40 () ;
return V_79 ;
V_194:
F_18 () ;
F_14 (cpu) {
if ( V_29 [ V_24 ] ) {
F_89 ( & V_29 [ V_24 ] -> V_121 ) ;
F_100 ( V_29 [ V_24 ] ) ;
}
}
F_25 () ;
F_111 ( V_29 ) ;
return - V_143 ;
}
static int T_3 F_112 ( char * V_196 )
{
if ( ! V_196 )
return - V_70 ;
if ( ! strcmp ( V_196 , L_12 ) )
V_187 = 1 ;
if ( ! strcmp ( V_196 , L_13 ) )
V_192 = 1 ;
if ( ! strcmp ( V_196 , L_14 ) )
V_184 = 1 ;
if ( ! strcmp ( V_196 , L_15 ) )
V_193 = 1 ;
return 0 ;
}
