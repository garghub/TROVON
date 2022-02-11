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
T_4 V_6 ;
F_15 () ;
if ( V_32 . V_33 )
V_6 = sprintf ( V_61 , L_2 , V_32 . V_33 ) ;
else
V_6 = sprintf ( V_61 , L_2 , V_32 . V_45 ) ;
return V_6 ;
}
static T_4 F_33 ( struct V_57 * V_62 , struct V_59 * V_63 ,
const char * V_61 , T_5 V_64 )
{
unsigned int V_65 ;
int V_6 ;
V_6 = sscanf ( V_61 , L_3 , & V_65 ) ;
if ( V_6 != 1 )
return - V_66 ;
F_15 () ;
if ( V_32 . V_33 ) {
F_34 ( L_4 ) ;
return - V_67 ;
}
V_32 . V_45 = F_35 ( int , V_65 , 0 , 1 ) ;
if ( V_53 )
F_17 () ;
return V_64 ;
}
static T_4 F_36 ( struct V_57 * V_62 , struct V_59 * V_63 ,
const char * V_61 , T_5 V_64 )
{
unsigned int V_65 ;
int V_6 ;
V_6 = sscanf ( V_61 , L_3 , & V_65 ) ;
if ( V_6 != 1 )
return - V_66 ;
V_32 . V_68 = F_35 ( int , V_65 , 0 , 100 ) ;
V_32 . V_44 = V_38 ( V_32 . V_69 , V_32 . V_68 ) ;
V_32 . V_70 = F_2 ( F_7 ( V_32 . V_44 ) , F_7 ( 100 ) ) ;
if ( V_53 )
F_17 () ;
return V_64 ;
}
static T_4 F_37 ( struct V_57 * V_62 , struct V_59 * V_63 ,
const char * V_61 , T_5 V_64 )
{
unsigned int V_65 ;
int V_6 ;
V_6 = sscanf ( V_61 , L_3 , & V_65 ) ;
if ( V_6 != 1 )
return - V_66 ;
V_32 . V_43 = F_35 ( int , V_65 , 0 , 100 ) ;
V_32 . V_71 = F_2 ( F_7 ( V_32 . V_43 ) , F_7 ( 100 ) ) ;
if ( V_53 )
F_17 () ;
return V_64 ;
}
static void T_3 F_38 ( void )
{
struct V_57 * V_72 ;
int V_73 ;
V_72 = F_39 ( L_5 ,
& V_74 . V_75 -> V_58 ) ;
F_40 ( ! V_72 ) ;
V_73 = F_41 ( V_72 , & V_76 ) ;
F_40 ( V_73 ) ;
}
static void F_42 ( void )
{
V_53 ++ ;
F_43 ( L_6 ) ;
F_44 ( V_77 , 0x1 ) ;
}
static int F_45 ( void )
{
T_2 V_40 ;
F_16 ( V_78 , V_40 ) ;
return ( V_40 >> 8 ) & 0x7F ;
}
static int F_46 ( void )
{
T_2 V_40 ;
F_16 ( V_78 , V_40 ) ;
return ( V_40 >> 16 ) & 0x7F ;
}
static int F_47 ( void )
{
T_2 V_40 ;
F_16 ( V_79 , V_40 ) ;
return V_40 & 0x7F ;
}
static void F_48 ( struct V_23 * V_23 , int V_35 )
{
T_2 V_48 ;
T_1 V_80 ;
V_49 V_81 ;
V_48 = V_35 << 8 ;
if ( V_32 . V_45 && ! V_32 . V_33 )
V_48 |= ( T_2 ) 1 << 32 ;
V_80 = V_23 -> V_81 . V_38 + F_1 (
F_7 ( V_35 - V_23 -> V_35 . V_82 ) ,
V_23 -> V_81 . V_83 ) ;
V_80 = F_35 ( T_1 , V_80 , V_23 -> V_81 . V_38 , V_23 -> V_81 . V_39 ) ;
V_81 = F_4 ( V_80 ) ;
if ( V_35 > V_23 -> V_35 . V_36 )
V_81 = V_23 -> V_81 . V_84 ;
V_48 |= V_81 ;
F_44 ( V_85 , V_48 ) ;
}
static int F_49 ( void )
{
T_2 V_40 ;
int V_52 ;
F_16 ( V_86 , V_40 ) ;
V_52 = V_40 & 0x3 ;
F_40 ( V_52 > V_87 ) ;
return V_88 [ V_52 ] * 100 ;
}
static void F_50 ( struct V_23 * V_23 )
{
T_2 V_40 ;
F_16 ( V_89 , V_40 ) ;
V_23 -> V_81 . V_38 = F_7 ( ( V_40 >> 8 ) & 0x7f ) ;
V_23 -> V_81 . V_39 = F_7 ( ( V_40 >> 16 ) & 0x7f ) ;
V_23 -> V_81 . V_83 = F_2 (
V_23 -> V_81 . V_39 - V_23 -> V_81 . V_38 ,
F_7 ( V_23 -> V_35 . V_36 -
V_23 -> V_35 . V_82 ) ) ;
F_16 ( V_90 , V_40 ) ;
V_23 -> V_81 . V_84 = V_40 & 0x7f ;
}
static int F_51 ( void )
{
T_2 V_40 ;
F_16 ( V_91 , V_40 ) ;
return ( V_40 >> 40 ) & 0xFF ;
}
static int F_52 ( void )
{
T_2 V_40 ;
F_16 ( V_91 , V_40 ) ;
return ( V_40 >> 8 ) & 0xFF ;
}
static int F_53 ( void )
{
T_2 V_40 ;
int V_92 , V_6 ;
F_16 ( V_93 , V_40 ) ;
V_92 = F_52 () ;
V_6 = ( V_40 ) & 255 ;
if ( V_6 <= V_92 )
V_6 = V_92 ;
return V_6 ;
}
static inline int F_54 ( void )
{
return 100000 ;
}
static void F_55 ( struct V_23 * V_23 , int V_35 )
{
T_2 V_48 ;
V_48 = V_35 << 8 ;
if ( V_32 . V_45 && ! V_32 . V_33 )
V_48 |= ( T_2 ) 1 << 32 ;
F_24 ( V_23 -> V_24 , V_85 , V_48 ) ;
}
static void F_56 ( struct V_23 * V_24 , int * V_38 , int * V_39 )
{
int V_70 = V_24 -> V_35 . V_37 ;
int V_94 ;
int V_71 ;
if ( V_32 . V_45 || V_32 . V_33 )
V_70 = V_24 -> V_35 . V_36 ;
V_94 = F_5 ( F_1 ( F_7 ( V_70 ) , V_32 . V_70 ) ) ;
* V_39 = F_35 ( int , V_94 ,
V_24 -> V_35 . V_82 , V_24 -> V_35 . V_37 ) ;
V_71 = F_5 ( F_1 ( F_7 ( V_70 ) , V_32 . V_71 ) ) ;
* V_38 = F_35 ( int , V_71 , V_24 -> V_35 . V_82 , V_70 ) ;
}
static void F_57 ( struct V_23 * V_24 , int V_35 )
{
int V_70 , V_71 ;
F_15 () ;
F_56 ( V_24 , & V_71 , & V_70 ) ;
V_35 = F_35 ( int , V_35 , V_71 , V_70 ) ;
if ( V_35 == V_24 -> V_35 . V_95 )
return;
F_58 ( V_35 * V_24 -> V_35 . V_96 , V_24 -> V_24 ) ;
V_24 -> V_35 . V_95 = V_35 ;
V_97 . V_98 ( V_24 , V_35 ) ;
}
static void F_59 ( struct V_23 * V_24 )
{
V_24 -> V_35 . V_82 = V_97 . V_99 () ;
V_24 -> V_35 . V_36 = V_97 . V_100 () ;
V_24 -> V_35 . V_37 = V_97 . V_101 () ;
V_24 -> V_35 . V_96 = V_97 . V_102 () ;
if ( V_97 . V_103 )
V_97 . V_103 ( V_24 ) ;
F_57 ( V_24 , V_24 -> V_35 . V_82 ) ;
}
static inline void F_60 ( struct V_23 * V_24 )
{
struct V_104 * V_104 = & V_24 -> V_104 ;
V_3 V_105 ;
V_105 = F_7 ( V_104 -> V_106 ) * F_7 ( 100 ) ;
V_105 = F_61 ( V_105 , F_7 ( V_104 -> V_107 ) ) ;
V_104 -> V_41 = F_5 (
F_1 ( F_7 (
V_24 -> V_35 . V_36 * V_24 -> V_35 . V_96 / 100 ) ,
V_105 ) ) ;
V_104 -> V_108 = ( T_1 ) V_105 ;
}
static inline void F_62 ( struct V_23 * V_24 )
{
T_2 V_106 , V_107 ;
unsigned long V_109 ;
F_63 ( V_109 ) ;
F_16 ( V_110 , V_106 ) ;
F_16 ( V_111 , V_107 ) ;
F_64 ( V_109 ) ;
V_24 -> V_112 = V_24 -> V_104 . time ;
V_24 -> V_104 . time = F_65 () ;
V_24 -> V_104 . V_106 = V_106 ;
V_24 -> V_104 . V_107 = V_107 ;
V_24 -> V_104 . V_106 -= V_24 -> V_113 ;
V_24 -> V_104 . V_107 -= V_24 -> V_114 ;
F_60 ( V_24 ) ;
V_24 -> V_113 = V_106 ;
V_24 -> V_114 = V_107 ;
}
static inline void F_66 ( struct V_23 * V_24 )
{
int V_115 ;
V_115 = F_67 ( 50 ) ;
F_68 ( & V_24 -> V_116 , V_117 + V_115 ) ;
}
static inline void F_69 ( struct V_23 * V_24 )
{
int V_115 ;
V_115 = F_67 ( V_25 . V_118 ) ;
F_68 ( & V_24 -> V_116 , V_117 + V_115 ) ;
}
static inline T_1 F_70 ( struct V_23 * V_24 )
{
T_1 V_119 , V_36 , V_95 , V_120 ;
V_49 V_121 ;
V_49 V_122 ;
V_119 = V_24 -> V_104 . V_108 ;
V_36 = F_7 ( V_24 -> V_35 . V_36 ) ;
V_95 = F_7 ( V_24 -> V_35 . V_95 ) ;
V_119 = F_1 ( V_119 , F_2 ( V_36 , V_95 ) ) ;
V_122 = V_25 . V_118 * V_123 ;
V_121 = ( V_49 ) F_71 ( V_24 -> V_104 . time ,
V_24 -> V_112 ) ;
if ( V_121 > V_122 * 3 ) {
V_120 = F_2 ( F_7 ( V_122 ) ,
F_7 ( V_121 ) ) ;
V_119 = F_1 ( V_119 , V_120 ) ;
}
return V_119 ;
}
static inline void F_72 ( struct V_23 * V_24 )
{
T_1 V_124 ;
struct V_7 * V_8 ;
signed int V_125 ;
V_8 = & V_24 -> V_8 ;
V_124 = F_70 ( V_24 ) ;
V_125 = F_11 ( V_8 , V_124 ) ;
F_57 ( V_24 , V_24 -> V_35 . V_95 - V_125 ) ;
}
static void F_73 ( unsigned long V_126 )
{
struct V_23 * V_24 = (struct V_23 * ) V_126 ;
F_62 ( V_24 ) ;
F_66 ( V_24 ) ;
}
static void F_74 ( unsigned long V_126 )
{
struct V_23 * V_24 = (struct V_23 * ) V_126 ;
struct V_104 * V_104 ;
F_62 ( V_24 ) ;
V_104 = & V_24 -> V_104 ;
F_72 ( V_24 ) ;
F_75 ( F_5 ( V_104 -> V_108 ) ,
F_5 ( F_70 ( V_24 ) ) ,
V_24 -> V_35 . V_95 ,
V_104 -> V_107 ,
V_104 -> V_106 ,
V_104 -> V_41 ) ;
F_69 ( V_24 ) ;
}
static int F_76 ( unsigned int V_127 )
{
struct V_23 * V_24 ;
if ( ! V_29 [ V_127 ] )
V_29 [ V_127 ] = F_77 ( sizeof( struct V_23 ) ,
V_128 ) ;
if ( ! V_29 [ V_127 ] )
return - V_129 ;
V_24 = V_29 [ V_127 ] ;
V_24 -> V_24 = V_127 ;
F_59 ( V_24 ) ;
F_78 ( & V_24 -> V_116 ) ;
V_24 -> V_116 . V_47 = ( unsigned long ) V_24 ;
V_24 -> V_116 . V_130 = V_117 + V_131 / 100 ;
if ( ! V_53 )
V_24 -> V_116 . V_132 = F_74 ;
else
V_24 -> V_116 . V_132 = F_73 ;
F_12 ( V_24 ) ;
F_62 ( V_24 ) ;
F_79 ( & V_24 -> V_116 , V_127 ) ;
F_80 ( L_7 , V_127 ) ;
return 0 ;
}
static unsigned int F_81 ( unsigned int V_133 )
{
struct V_104 * V_104 ;
struct V_23 * V_24 ;
V_24 = V_29 [ V_133 ] ;
if ( ! V_24 )
return 0 ;
V_104 = & V_24 -> V_104 ;
return V_104 -> V_41 ;
}
static int F_82 ( struct V_134 * V_135 )
{
if ( ! V_135 -> V_136 . V_137 )
return - V_138 ;
if ( V_135 -> V_135 == V_139 ) {
V_32 . V_43 = 100 ;
V_32 . V_71 = F_7 ( 1 ) ;
V_32 . V_69 = 100 ;
V_32 . V_44 = 100 ;
V_32 . V_70 = F_7 ( 1 ) ;
V_32 . V_45 = 0 ;
return 0 ;
}
V_32 . V_43 = ( V_135 -> V_38 * 100 ) / V_135 -> V_136 . V_137 ;
V_32 . V_43 = F_35 ( int , V_32 . V_43 , 0 , 100 ) ;
V_32 . V_71 = F_2 ( F_7 ( V_32 . V_43 ) , F_7 ( 100 ) ) ;
V_32 . V_69 = ( V_135 -> V_39 * 100 ) / V_135 -> V_136 . V_137 ;
V_32 . V_69 = F_35 ( int , V_32 . V_69 , 0 , 100 ) ;
V_32 . V_44 = V_38 ( V_32 . V_69 , V_32 . V_68 ) ;
V_32 . V_70 = F_2 ( F_7 ( V_32 . V_44 ) , F_7 ( 100 ) ) ;
if ( V_53 )
F_17 () ;
return 0 ;
}
static int F_83 ( struct V_134 * V_135 )
{
F_84 ( V_135 ) ;
if ( V_135 -> V_135 != V_140 &&
V_135 -> V_135 != V_139 )
return - V_66 ;
return 0 ;
}
static void F_85 ( struct V_134 * V_135 )
{
int V_133 = V_135 -> V_24 ;
struct V_23 * V_24 = V_29 [ V_133 ] ;
F_43 ( L_8 , V_133 ) ;
F_86 ( & V_29 [ V_133 ] -> V_116 ) ;
if ( V_53 )
return;
F_57 ( V_24 , V_24 -> V_35 . V_82 ) ;
}
static int F_87 ( struct V_134 * V_135 )
{
struct V_23 * V_24 ;
int V_73 ;
V_73 = F_76 ( V_135 -> V_24 ) ;
if ( V_73 )
return V_73 ;
V_24 = V_29 [ V_135 -> V_24 ] ;
if ( V_32 . V_43 == 100 && V_32 . V_44 == 100 )
V_135 -> V_135 = V_139 ;
else
V_135 -> V_135 = V_140 ;
V_135 -> V_38 = V_24 -> V_35 . V_82 * V_24 -> V_35 . V_96 ;
V_135 -> V_39 = V_24 -> V_35 . V_37 * V_24 -> V_35 . V_96 ;
V_135 -> V_136 . V_141 = V_24 -> V_35 . V_82 * V_24 -> V_35 . V_96 ;
V_135 -> V_136 . V_137 =
V_24 -> V_35 . V_37 * V_24 -> V_35 . V_96 ;
V_135 -> V_136 . V_142 = V_143 ;
F_88 ( V_135 -> V_24 , V_135 -> V_144 ) ;
return 0 ;
}
static int F_89 ( void )
{
T_2 V_106 , V_107 , V_145 ;
F_16 ( V_110 , V_106 ) ;
F_16 ( V_111 , V_107 ) ;
if ( ! V_97 . V_100 () ||
! V_97 . V_99 () ||
! V_97 . V_101 () )
return - V_138 ;
F_16 ( V_110 , V_145 ) ;
if ( ! ( V_145 - V_106 ) )
return - V_138 ;
F_16 ( V_111 , V_145 ) ;
if ( ! ( V_145 - V_107 ) )
return - V_138 ;
return 0 ;
}
static void F_90 ( struct V_146 * V_135 )
{
V_25 . V_118 = V_135 -> V_118 ;
V_25 . V_26 = V_135 -> V_26 ;
V_25 . V_28 = V_135 -> V_28 ;
V_25 . V_27 = V_135 -> V_27 ;
V_25 . V_11 = V_135 -> V_11 ;
V_25 . V_9 = V_135 -> V_9 ;
}
static void F_91 ( struct V_97 * V_147 )
{
V_97 . V_100 = V_147 -> V_100 ;
V_97 . V_99 = V_147 -> V_99 ;
V_97 . V_101 = V_147 -> V_101 ;
V_97 . V_102 = V_147 -> V_102 ;
V_97 . V_98 = V_147 -> V_98 ;
V_97 . V_103 = V_147 -> V_103 ;
}
static bool F_92 ( void )
{
int V_52 ;
F_93 (i) {
T_6 V_148 ;
union V_149 * V_150 ;
struct V_151 V_152 = { V_153 , NULL } ;
struct V_154 * V_155 = F_94 ( V_156 , V_52 ) ;
if ( ! V_155 )
continue;
V_148 = F_95 ( V_155 -> V_157 , L_9 , NULL , & V_152 ) ;
if ( F_96 ( V_148 ) )
continue;
V_150 = V_152 . V_158 ;
if ( V_150 && V_150 -> type == V_159 ) {
F_97 ( V_150 ) ;
return false ;
}
F_97 ( V_150 ) ;
}
return true ;
}
static bool F_98 ( void )
{
int V_52 ;
F_93 (i) {
struct V_154 * V_155 = F_94 ( V_156 , V_52 ) ;
if ( ! V_155 )
continue;
if ( F_99 ( V_155 -> V_157 , L_10 ) )
return true ;
}
return false ;
}
static bool F_100 ( void )
{
struct V_160 V_161 ;
struct V_162 * V_163 ;
const struct V_164 * V_165 ;
T_2 V_166 ;
V_165 = F_101 ( V_167 ) ;
if ( V_165 ) {
F_16 ( V_168 , V_166 ) ;
if ( V_166 & ( 1 << 8 ) )
return true ;
}
if ( V_169 ||
F_96 ( F_102 ( V_170 , 0 , & V_161 ) ) )
return false ;
for ( V_163 = V_171 ; V_163 -> V_172 ; V_163 ++ ) {
if ( ! strncmp ( V_161 . V_173 , V_163 -> V_173 , V_174 ) &&
! strncmp ( V_161 . V_175 , V_163 -> V_175 ,
V_176 ) )
switch ( V_163 -> V_177 ) {
case V_178 :
return F_92 () ;
case V_179 :
return F_98 () &&
( ! V_180 ) ;
}
}
return false ;
}
static inline bool F_100 ( void ) { return false ; }
static inline bool F_98 ( void ) { return false ; }
static int T_3 F_103 ( void )
{
int V_24 , V_73 = 0 ;
const struct V_164 * V_165 ;
struct V_181 * V_182 ;
struct V_183 * V_184 = & V_185 ;
if ( V_186 )
return - V_138 ;
V_165 = F_101 ( V_187 ) ;
if ( ! V_165 )
return - V_138 ;
if ( F_100 () )
return - V_138 ;
V_182 = (struct V_181 * ) V_165 -> V_188 ;
F_90 ( & V_182 -> V_189 ) ;
F_91 ( & V_182 -> V_147 ) ;
if ( F_89 () )
return - V_138 ;
F_43 ( L_11 ) ;
V_29 = F_104 ( sizeof( void * ) * F_105 () ) ;
if ( ! V_29 )
return - V_129 ;
if ( F_106 ( V_184 , V_190 ) && ! V_191 )
F_42 () ;
V_73 = F_107 ( & V_192 ) ;
if ( V_73 )
goto V_193;
F_28 () ;
F_38 () ;
return V_73 ;
V_193:
F_18 () ;
F_14 (cpu) {
if ( V_29 [ V_24 ] ) {
F_86 ( & V_29 [ V_24 ] -> V_116 ) ;
F_97 ( V_29 [ V_24 ] ) ;
}
}
F_25 () ;
F_108 ( V_29 ) ;
return - V_138 ;
}
static int T_3 F_109 ( char * V_194 )
{
if ( ! V_194 )
return - V_66 ;
if ( ! strcmp ( V_194 , L_12 ) )
V_186 = 1 ;
if ( ! strcmp ( V_194 , L_13 ) )
V_191 = 1 ;
if ( ! strcmp ( V_194 , L_14 ) )
V_180 = 1 ;
return 0 ;
}
