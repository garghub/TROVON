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
static inline T_3 F_6 ( T_3 V_1 , T_3 V_2 )
{
return ( V_1 * V_2 ) >> V_7 ;
}
static inline T_3 F_7 ( T_3 V_1 , T_3 V_2 )
{
return F_8 ( V_1 << V_7 , V_2 ) ;
}
static bool F_9 ( void )
{
if ( V_8 . V_9 == V_10 ||
V_8 . V_9 == V_11 )
return true ;
return V_12 ;
}
static void F_10 ( struct V_13 * V_14 )
{
F_11 () ;
}
static void F_12 ( int V_15 )
{
struct V_16 V_17 ;
static T_4 V_18 = 0 , V_19 = V_20 ;
int V_6 ;
V_6 = F_13 ( V_15 , & V_17 ) ;
if ( V_6 )
return;
F_14 ( V_17 . V_21 , V_15 ) ;
if ( V_18 <= V_19 ) {
if ( V_17 . V_21 > V_18 )
V_18 = V_17 . V_21 ;
if ( V_17 . V_21 < V_19 )
V_19 = V_17 . V_21 ;
if ( V_18 > V_19 ) {
F_15 ( & V_22 ) ;
}
}
}
static void F_12 ( int V_15 )
{
}
static void F_16 ( struct V_23 * V_24 )
{
struct V_25 * V_15 ;
int V_6 ;
int V_26 ;
if ( V_27 ) {
F_12 ( V_24 -> V_15 ) ;
return;
}
if ( ! F_9 () )
return;
V_15 = V_28 [ V_24 -> V_15 ] ;
V_6 = F_17 ( & V_15 -> V_29 ,
V_24 -> V_15 ) ;
if ( V_6 )
return;
if ( V_15 -> V_29 . V_30 . V_31 !=
V_32 )
goto V_33;
if ( V_15 -> V_29 . V_34 < 2 )
goto V_33;
F_18 ( L_1 , V_24 -> V_15 ) ;
for ( V_26 = 0 ; V_26 < V_15 -> V_29 . V_34 ; V_26 ++ ) {
F_18 ( L_2 ,
( V_26 == V_15 -> V_29 . V_35 ? '*' : ' ' ) , V_26 ,
( T_4 ) V_15 -> V_29 . V_36 [ V_26 ] . V_37 ,
( T_4 ) V_15 -> V_29 . V_36 [ V_26 ] . V_38 ,
( T_4 ) V_15 -> V_29 . V_36 [ V_26 ] . V_39 ) ;
}
if ( ! V_40 -> V_41 )
V_15 -> V_29 . V_36 [ 0 ] . V_37 =
V_24 -> V_42 . V_43 / 1000 ;
V_15 -> V_44 = true ;
F_18 ( L_3 ) ;
return;
V_33:
V_15 -> V_44 = false ;
F_19 ( V_24 -> V_15 ) ;
}
static void F_20 ( struct V_23 * V_24 )
{
struct V_25 * V_15 ;
V_15 = V_28 [ V_24 -> V_15 ] ;
if ( ! V_15 -> V_44 )
return;
F_19 ( V_24 -> V_15 ) ;
}
static inline void F_16 ( struct V_23 * V_24 )
{
}
static inline void F_20 ( struct V_23 * V_24 )
{
}
static inline void F_21 ( struct V_45 * V_46 , int V_47 , int V_48 ,
int V_49 , int V_50 ) {
V_46 -> V_47 = F_22 ( V_47 ) ;
V_46 -> V_49 = F_22 ( V_49 ) ;
V_46 -> V_50 = F_22 ( V_50 ) ;
V_46 -> V_51 = F_22 ( V_47 ) - F_22 ( V_48 ) ;
}
static inline void F_23 ( struct V_45 * V_46 , int V_52 )
{
V_46 -> V_53 = F_2 ( V_52 , 100 ) ;
}
static inline void F_24 ( struct V_45 * V_46 , int V_52 )
{
V_46 -> V_54 = F_2 ( V_52 , 100 ) ;
}
static inline void F_25 ( struct V_45 * V_46 , int V_52 )
{
V_46 -> V_55 = F_2 ( V_52 , 100 ) ;
}
static signed int F_26 ( struct V_45 * V_46 , T_1 V_48 )
{
signed int V_56 ;
T_1 V_57 , V_58 , V_59 ;
T_1 V_60 ;
V_59 = V_46 -> V_47 - V_48 ;
if ( abs ( V_59 ) <= V_46 -> V_49 )
return 0 ;
V_57 = F_1 ( V_46 -> V_53 , V_59 ) ;
V_46 -> V_50 += V_59 ;
V_60 = F_22 ( 30 ) ;
if ( V_46 -> V_50 > V_60 )
V_46 -> V_50 = V_60 ;
if ( V_46 -> V_50 < - V_60 )
V_46 -> V_50 = - V_60 ;
V_58 = F_1 ( V_46 -> V_55 , V_59 - V_46 -> V_51 ) ;
V_46 -> V_51 = V_59 ;
V_56 = V_57 + F_1 ( V_46 -> V_50 , V_46 -> V_54 ) + V_58 ;
V_56 = V_56 + ( 1 << ( V_4 - 1 ) ) ;
return ( signed int ) F_5 ( V_56 ) ;
}
static inline void F_27 ( struct V_25 * V_15 )
{
F_23 ( & V_15 -> V_46 , V_61 . V_62 ) ;
F_25 ( & V_15 -> V_46 , V_61 . V_63 ) ;
F_24 ( & V_15 -> V_46 , V_61 . V_64 ) ;
F_21 ( & V_15 -> V_46 , V_61 . V_47 , 100 , V_61 . V_49 , 0 ) ;
}
static inline void F_28 ( void )
{
unsigned int V_15 ;
F_29 (cpu) {
if ( V_28 [ V_15 ] )
F_27 ( V_28 [ V_15 ] ) ;
}
}
static inline void F_30 ( void )
{
T_3 V_65 ;
struct V_25 * V_15 ;
V_15 = V_28 [ 0 ] ;
F_31 ( V_66 , V_65 ) ;
V_40 -> V_41 =
( V_65 & V_67 ||
V_15 -> V_68 . V_69 == V_15 -> V_68 . V_70 ) ;
}
static T_5 F_32 ( struct V_25 * V_71 )
{
T_3 V_72 ;
int V_6 ;
if ( ! F_33 ( V_73 ) )
return - V_74 ;
V_6 = F_34 ( V_71 -> V_15 , V_75 , & V_72 ) ;
if ( V_6 )
return ( T_5 ) V_6 ;
return ( T_5 ) ( V_72 & 0x0f ) ;
}
static T_5 F_35 ( struct V_25 * V_71 , T_3 V_76 )
{
T_5 V_77 ;
if ( F_33 ( V_78 ) ) {
if ( ! V_76 ) {
V_77 = F_34 ( V_71 -> V_15 , V_79 ,
& V_76 ) ;
if ( V_77 )
return V_77 ;
}
V_77 = ( V_76 >> 24 ) & 0xff ;
} else {
V_77 = F_32 ( V_71 ) ;
}
return V_77 ;
}
static int F_36 ( int V_15 , T_5 V_80 )
{
T_3 V_72 ;
int V_6 ;
if ( ! F_33 ( V_73 ) )
return - V_74 ;
V_6 = F_34 ( V_15 , V_75 , & V_72 ) ;
if ( V_6 )
return V_6 ;
V_72 = ( V_72 & ~ 0x0f ) | V_80 ;
F_37 ( V_15 , V_75 , V_72 ) ;
return 0 ;
}
static int F_38 ( struct V_25 * V_71 )
{
T_5 V_77 ;
int V_81 = - V_82 ;
V_77 = F_35 ( V_71 , 0 ) ;
if ( V_77 < 0 )
return V_77 ;
if ( F_33 ( V_78 ) ) {
V_81 = ( V_77 >> 6 ) + 1 ;
} else if ( F_33 ( V_73 ) ) {
V_81 = ( V_77 >> 2 ) + 1 ;
}
return V_81 ;
}
static int F_39 ( struct V_25 * V_71 ,
int V_83 )
{
int V_77 = - V_82 ;
int V_6 ;
if ( ! V_83 )
V_77 = V_71 -> V_84 ;
F_40 ( & V_85 ) ;
if ( F_33 ( V_78 ) ) {
T_3 V_86 ;
V_6 = F_34 ( V_71 -> V_15 , V_79 , & V_86 ) ;
if ( V_6 )
goto V_87;
V_86 &= ~ F_41 ( 31 , 24 ) ;
if ( V_77 == - V_82 )
V_77 = ( V_83 - 1 ) << 6 ;
V_86 |= ( T_3 ) V_77 << 24 ;
V_6 = F_37 ( V_71 -> V_15 , V_79 , V_86 ) ;
} else {
if ( V_77 == - V_82 )
V_77 = ( V_83 - 1 ) << 2 ;
V_6 = F_36 ( V_71 -> V_15 , V_77 ) ;
}
V_87:
F_42 ( & V_85 ) ;
return V_6 ;
}
static T_6 F_43 (
struct V_23 * V_24 , char * V_88 )
{
int V_26 = 0 ;
int V_6 = 0 ;
while ( V_89 [ V_26 ] != NULL )
V_6 += sprintf ( & V_88 [ V_6 ] , L_4 , V_89 [ V_26 ++ ] ) ;
V_6 += sprintf ( & V_88 [ V_6 ] , L_5 ) ;
return V_6 ;
}
static T_6 F_44 (
struct V_23 * V_24 , const char * V_88 , T_7 V_90 )
{
struct V_25 * V_71 = V_28 [ V_24 -> V_15 ] ;
char V_91 [ 21 ] ;
int V_6 , V_26 = 0 ;
V_6 = sscanf ( V_88 , L_6 , V_91 ) ;
if ( V_6 != 1 )
return - V_82 ;
while ( V_89 [ V_26 ] != NULL ) {
if ( ! strcmp ( V_91 , V_89 [ V_26 ] ) ) {
F_39 ( V_71 , V_26 ) ;
return V_90 ;
}
++ V_26 ;
}
return - V_82 ;
}
static T_6 F_45 (
struct V_23 * V_24 , char * V_88 )
{
struct V_25 * V_71 = V_28 [ V_24 -> V_15 ] ;
int V_92 ;
V_92 = F_38 ( V_71 ) ;
if ( V_92 < 0 )
return V_92 ;
return sprintf ( V_88 , L_7 , V_89 [ V_92 ] ) ;
}
static void F_46 ( struct V_23 * V_24 )
{
int V_93 , V_94 , V_95 , V_96 , V_15 , V_97 , V_98 ;
struct V_99 * V_99 = V_40 ;
T_3 V_86 , V_100 ;
F_47 (cpu, policy->cpus) {
int V_101 , V_102 ;
struct V_25 * V_71 = V_28 [ V_15 ] ;
T_5 V_77 ;
if ( V_103 )
V_99 = V_28 [ V_15 ] -> V_99 ;
F_34 ( V_15 , V_104 , & V_100 ) ;
V_94 = F_48 ( V_100 ) ;
V_96 = F_49 ( V_100 ) ;
V_97 = V_96 - V_94 ;
V_101 = V_99 -> V_101 ;
V_102 = V_99 -> V_102 ;
F_34 ( V_15 , V_79 , & V_86 ) ;
V_98 = V_102 * V_97 / 100 ;
V_93 = V_94 + V_98 ;
V_86 &= ~ F_50 ( ~ 0L ) ;
V_86 |= F_50 ( V_93 ) ;
V_98 = V_101 * V_97 / 100 ;
V_95 = V_94 + V_98 ;
if ( V_40 -> V_105 ) {
V_96 = F_51 ( V_100 ) ;
if ( V_96 < V_95 )
V_95 = V_96 ;
}
V_86 &= ~ F_52 ( ~ 0L ) ;
V_86 |= F_52 ( V_95 ) ;
if ( V_71 -> V_106 == V_71 -> V_24 )
goto V_107;
V_71 -> V_106 = V_71 -> V_24 ;
if ( V_71 -> V_108 >= 0 ) {
V_77 = V_71 -> V_108 ;
V_71 -> V_108 = - V_82 ;
goto V_109;
}
if ( V_71 -> V_24 == V_110 ) {
V_77 = F_35 ( V_71 , V_86 ) ;
V_71 -> V_111 = V_77 ;
if ( V_77 < 0 )
goto V_107;
V_77 = 0 ;
} else {
if ( V_71 -> V_111 < 0 )
goto V_107;
V_77 = F_35 ( V_71 , V_86 ) ;
if ( V_77 )
goto V_107;
V_77 = V_71 -> V_111 ;
}
V_109:
if ( F_33 ( V_78 ) ) {
V_86 &= ~ F_41 ( 31 , 24 ) ;
V_86 |= ( T_3 ) V_77 << 24 ;
} else {
F_36 ( V_15 , V_77 ) ;
}
V_107:
F_37 ( V_15 , V_79 , V_86 ) ;
}
}
static int F_53 ( struct V_23 * V_24 )
{
if ( V_27 )
F_46 ( V_24 ) ;
return 0 ;
}
static int F_54 ( struct V_23 * V_24 )
{
struct V_25 * V_71 = V_28 [ V_24 -> V_15 ] ;
if ( ! V_27 )
return 0 ;
V_71 -> V_108 = F_35 ( V_71 , 0 ) ;
return 0 ;
}
static int F_55 ( struct V_23 * V_24 )
{
int V_6 ;
if ( ! V_27 )
return 0 ;
F_40 ( & V_85 ) ;
V_28 [ V_24 -> V_15 ] -> V_106 = 0 ;
V_6 = F_53 ( V_24 ) ;
F_42 ( & V_85 ) ;
return V_6 ;
}
static void F_56 ( void )
{
int V_15 ;
F_57 (cpu)
F_58 ( V_15 ) ;
}
static int F_59 ( void * V_112 , T_3 V_113 )
{
* ( T_4 * ) V_112 = V_113 ;
F_28 () ;
return 0 ;
}
static int F_60 ( void * V_112 , T_3 * V_113 )
{
* V_113 = * ( T_4 * ) V_112 ;
return 0 ;
}
static void T_8 F_61 ( void )
{
struct V_114 * V_115 ;
int V_26 = 0 ;
V_115 = F_62 ( L_8 , NULL ) ;
if ( F_63 ( V_115 ) )
return;
while ( V_116 [ V_26 ] . V_117 ) {
F_64 ( V_116 [ V_26 ] . V_117 , 0660 ,
V_115 , V_116 [ V_26 ] . V_86 ,
& V_118 ) ;
V_26 ++ ;
}
}
static T_6 F_65 ( struct V_119 * V_120 ,
struct V_121 * V_122 , char * V_88 )
{
struct V_25 * V_15 ;
int V_123 , V_105 , V_124 ;
T_9 V_125 ;
V_15 = V_28 [ 0 ] ;
V_123 = V_15 -> V_68 . V_70 - V_15 -> V_68 . V_126 + 1 ;
V_105 = V_15 -> V_68 . V_69 - V_15 -> V_68 . V_126 + 1 ;
V_125 = F_2 ( V_105 , V_123 ) ;
V_124 = 100 - F_5 ( F_1 ( V_125 , F_22 ( 100 ) ) ) ;
return sprintf ( V_88 , L_9 , V_124 ) ;
}
static T_6 F_66 ( struct V_119 * V_120 ,
struct V_121 * V_122 , char * V_88 )
{
struct V_25 * V_15 ;
int V_123 ;
V_15 = V_28 [ 0 ] ;
V_123 = V_15 -> V_68 . V_70 - V_15 -> V_68 . V_126 + 1 ;
return sprintf ( V_88 , L_9 , V_123 ) ;
}
static T_6 F_67 ( struct V_119 * V_120 ,
struct V_121 * V_122 , char * V_88 )
{
T_6 V_6 ;
F_30 () ;
if ( V_40 -> V_41 )
V_6 = sprintf ( V_88 , L_9 , V_40 -> V_41 ) ;
else
V_6 = sprintf ( V_88 , L_9 , V_40 -> V_105 ) ;
return V_6 ;
}
static T_6 F_68 ( struct V_119 * V_127 , struct V_121 * V_128 ,
const char * V_88 , T_7 V_90 )
{
unsigned int V_129 ;
int V_6 ;
V_6 = sscanf ( V_88 , L_10 , & V_129 ) ;
if ( V_6 != 1 )
return - V_82 ;
F_40 ( & V_85 ) ;
F_30 () ;
if ( V_40 -> V_41 ) {
F_69 ( L_11 ) ;
F_42 ( & V_85 ) ;
return - V_130 ;
}
V_40 -> V_105 = F_70 ( int , V_129 , 0 , 1 ) ;
F_42 ( & V_85 ) ;
F_56 () ;
return V_90 ;
}
static T_6 F_71 ( struct V_119 * V_127 , struct V_121 * V_128 ,
const char * V_88 , T_7 V_90 )
{
unsigned int V_129 ;
int V_6 ;
V_6 = sscanf ( V_88 , L_10 , & V_129 ) ;
if ( V_6 != 1 )
return - V_82 ;
F_40 ( & V_85 ) ;
V_40 -> V_131 = F_70 ( int , V_129 , 0 , 100 ) ;
V_40 -> V_101 = V_93 ( V_40 -> V_132 ,
V_40 -> V_131 ) ;
V_40 -> V_101 = V_95 ( V_40 -> V_133 ,
V_40 -> V_101 ) ;
V_40 -> V_101 = V_95 ( V_40 -> V_102 ,
V_40 -> V_101 ) ;
V_40 -> V_134 = F_7 ( V_40 -> V_101 , 100 ) ;
F_42 ( & V_85 ) ;
F_56 () ;
return V_90 ;
}
static T_6 F_72 ( struct V_119 * V_127 , struct V_121 * V_128 ,
const char * V_88 , T_7 V_90 )
{
unsigned int V_129 ;
int V_6 ;
V_6 = sscanf ( V_88 , L_10 , & V_129 ) ;
if ( V_6 != 1 )
return - V_82 ;
F_40 ( & V_85 ) ;
V_40 -> V_135 = F_70 ( int , V_129 , 0 , 100 ) ;
V_40 -> V_102 = V_95 ( V_40 -> V_133 ,
V_40 -> V_135 ) ;
V_40 -> V_102 = V_93 ( V_40 -> V_132 ,
V_40 -> V_102 ) ;
V_40 -> V_102 = V_93 ( V_40 -> V_101 ,
V_40 -> V_102 ) ;
V_40 -> V_136 = F_7 ( V_40 -> V_102 , 100 ) ;
F_42 ( & V_85 ) ;
F_56 () ;
return V_90 ;
}
static void T_8 F_73 ( void )
{
struct V_119 * V_137 ;
int V_138 ;
V_137 = F_74 ( L_12 ,
& V_139 . V_140 -> V_120 ) ;
if ( F_75 ( ! V_137 ) )
return;
V_138 = F_76 ( V_137 , & V_141 ) ;
if ( F_75 ( V_138 ) )
return;
if ( V_103 )
return;
V_138 = F_77 ( V_137 , & V_101 . V_122 ) ;
F_75 ( V_138 ) ;
V_138 = F_77 ( V_137 , & V_102 . V_122 ) ;
F_75 ( V_138 ) ;
}
static void F_78 ( struct V_25 * V_25 )
{
if ( F_33 ( V_142 ) )
F_37 ( V_25 -> V_15 , V_143 , 0x00 ) ;
F_37 ( V_25 -> V_15 , V_144 , 0x1 ) ;
V_25 -> V_106 = 0 ;
if ( V_25 -> V_84 == - V_82 )
V_25 -> V_84 = F_35 ( V_25 , 0 ) ;
}
static void F_79 ( int V_15 )
{
T_3 V_145 ;
int V_6 ;
V_6 = F_34 ( V_15 , V_146 , & V_145 ) ;
if ( V_6 )
return;
if ( ! ( V_145 & F_80 ( V_147 ) ) ) {
F_81 ( L_13 ) ;
V_145 |= F_80 ( V_147 ) ;
F_37 ( V_15 , V_146 , V_145 ) ;
}
}
static int F_82 ( void )
{
T_3 V_86 ;
F_31 ( V_148 , V_86 ) ;
return ( V_86 >> 8 ) & 0x7F ;
}
static int F_83 ( void )
{
T_3 V_86 ;
F_31 ( V_148 , V_86 ) ;
return ( V_86 >> 16 ) & 0x7F ;
}
static int F_84 ( void )
{
T_3 V_86 ;
F_31 ( V_149 , V_86 ) ;
return V_86 & 0x7F ;
}
static T_3 F_85 ( struct V_25 * V_25 , int V_68 )
{
T_3 V_113 ;
T_1 V_150 ;
T_4 V_151 ;
V_113 = ( T_3 ) V_68 << 8 ;
if ( V_40 -> V_105 && ! V_40 -> V_41 )
V_113 |= ( T_3 ) 1 << 32 ;
V_150 = V_25 -> V_151 . V_93 + F_1 (
F_22 ( V_68 - V_25 -> V_68 . V_126 ) ,
V_25 -> V_151 . V_152 ) ;
V_150 = F_70 ( T_1 , V_150 , V_25 -> V_151 . V_93 , V_25 -> V_151 . V_95 ) ;
V_151 = F_4 ( V_150 ) ;
if ( V_68 > V_25 -> V_68 . V_69 )
V_151 = V_25 -> V_151 . V_153 ;
return V_113 | V_151 ;
}
static int F_86 ( void )
{
T_3 V_86 ;
int V_26 ;
static int V_154 [] = {
83300 , 100000 , 133300 , 116700 , 80000 } ;
F_31 ( V_155 , V_86 ) ;
V_26 = V_86 & 0x7 ;
F_75 ( V_26 > 4 ) ;
return V_154 [ V_26 ] ;
}
static int F_87 ( void )
{
T_3 V_86 ;
int V_26 ;
static int V_156 [] = {
83300 , 100000 , 133300 , 116700 , 80000 ,
93300 , 90000 , 88900 , 87500 } ;
F_31 ( V_155 , V_86 ) ;
V_26 = V_86 & 0xF ;
F_75 ( V_26 > 8 ) ;
return V_156 [ V_26 ] ;
}
static void F_88 ( struct V_25 * V_25 )
{
T_3 V_86 ;
F_31 ( V_157 , V_86 ) ;
V_25 -> V_151 . V_93 = F_22 ( ( V_86 >> 8 ) & 0x7f ) ;
V_25 -> V_151 . V_95 = F_22 ( ( V_86 >> 16 ) & 0x7f ) ;
V_25 -> V_151 . V_152 = F_2 (
V_25 -> V_151 . V_95 - V_25 -> V_151 . V_93 ,
F_22 ( V_25 -> V_68 . V_69 -
V_25 -> V_68 . V_126 ) ) ;
F_31 ( V_158 , V_86 ) ;
V_25 -> V_151 . V_153 = V_86 & 0x7f ;
}
static int F_89 ( void )
{
T_3 V_86 ;
F_31 ( V_159 , V_86 ) ;
return ( V_86 >> 40 ) & 0xFF ;
}
static int F_90 ( void )
{
T_3 V_86 ;
F_31 ( V_159 , V_86 ) ;
return ( V_86 >> 8 ) & 0xFF ;
}
static int F_91 ( void )
{
T_3 V_160 ;
T_3 V_161 ;
int V_69 ;
int V_33 ;
F_31 ( V_159 , V_161 ) ;
V_69 = ( V_161 >> 8 ) & 0xFF ;
V_33 = F_92 ( V_162 , & V_160 ) ;
if ( ! V_33 ) {
if ( V_161 & 0x600000000 ) {
T_3 V_163 ;
T_3 V_164 ;
int V_165 ;
V_33 = F_92 ( V_166 , & V_163 ) ;
if ( V_33 )
goto V_167;
V_165 = V_168 + ( V_163 & 0x3 ) ;
V_33 = F_92 ( V_165 , & V_164 ) ;
if ( V_33 )
goto V_167;
if ( V_163 )
V_164 >>= 16 ;
V_164 &= 0xff ;
if ( V_164 - 1 == V_160 ) {
V_69 = V_160 ;
F_18 ( L_14 , V_69 ) ;
} else {
goto V_167;
}
}
}
V_167:
return V_69 ;
}
static int F_93 ( void )
{
T_3 V_86 ;
int V_169 , V_6 ;
F_31 ( V_170 , V_86 ) ;
V_169 = F_91 () ;
V_6 = ( V_86 ) & 255 ;
if ( V_6 <= V_169 )
V_6 = V_169 ;
return V_6 ;
}
static inline int F_94 ( void )
{
return 100000 ;
}
static T_3 F_95 ( struct V_25 * V_25 , int V_68 )
{
T_3 V_113 ;
V_113 = ( T_3 ) V_68 << 8 ;
if ( V_40 -> V_105 && ! V_40 -> V_41 )
V_113 |= ( T_3 ) 1 << 32 ;
return V_113 ;
}
static int F_96 ( void )
{
T_3 V_86 ;
int V_169 , V_6 ;
F_31 ( V_170 , V_86 ) ;
V_169 = F_91 () ;
V_6 = ( ( ( V_86 ) >> 8 ) & 0xFF ) ;
if ( V_6 <= V_169 )
V_6 = V_169 ;
return V_6 ;
}
static void F_97 ( struct V_25 * V_15 , int * V_93 , int * V_95 )
{
int V_134 = V_15 -> V_68 . V_70 ;
int V_171 ;
int V_136 ;
struct V_99 * V_99 = V_40 ;
if ( V_40 -> V_105 || V_40 -> V_41 )
V_134 = V_15 -> V_68 . V_69 ;
if ( V_103 )
V_99 = V_15 -> V_99 ;
V_171 = F_98 ( V_134 * V_99 -> V_134 ) ;
* V_95 = F_70 ( int , V_171 ,
V_15 -> V_68 . V_126 , V_15 -> V_68 . V_70 ) ;
V_136 = F_98 ( V_134 * V_99 -> V_136 ) ;
* V_93 = F_70 ( int , V_136 , V_15 -> V_68 . V_126 , V_134 ) ;
}
static void F_99 ( struct V_25 * V_15 , int V_68 )
{
F_100 ( V_68 * V_15 -> V_68 . V_172 , V_15 -> V_15 ) ;
V_15 -> V_68 . V_173 = V_68 ;
F_37 ( V_15 -> V_15 , V_174 ,
V_175 . V_176 ( V_15 , V_68 ) ) ;
}
static void F_101 ( struct V_25 * V_15 )
{
F_99 ( V_15 , V_15 -> V_68 . V_126 ) ;
}
static void F_102 ( struct V_25 * V_15 )
{
int V_126 , V_69 ;
F_30 () ;
F_97 ( V_15 , & V_126 , & V_69 ) ;
F_99 ( V_15 , V_69 ) ;
}
static void F_103 ( struct V_25 * V_15 )
{
V_15 -> V_68 . V_126 = V_175 . V_177 () ;
V_15 -> V_68 . V_69 = V_175 . V_178 () ;
V_15 -> V_68 . V_179 = V_175 . V_180 () ;
V_15 -> V_68 . V_70 = V_175 . V_181 () ;
V_15 -> V_68 . V_172 = V_175 . V_182 () ;
V_15 -> V_68 . V_43 = V_15 -> V_68 . V_69 * V_15 -> V_68 . V_172 ;
V_15 -> V_68 . V_183 = V_15 -> V_68 . V_70 * V_15 -> V_68 . V_172 ;
if ( V_175 . V_184 )
V_175 . V_184 ( V_15 ) ;
F_101 ( V_15 ) ;
}
static inline void F_104 ( struct V_25 * V_15 )
{
struct V_185 * V_185 = & V_15 -> V_185 ;
V_185 -> V_186 = F_7 ( V_185 -> V_187 , V_185 -> V_188 ) ;
}
static inline bool F_105 ( struct V_25 * V_15 , T_3 time )
{
T_3 V_187 , V_188 ;
unsigned long V_189 ;
T_3 V_190 ;
F_106 ( V_189 ) ;
F_31 ( V_191 , V_187 ) ;
F_31 ( V_192 , V_188 ) ;
V_190 = F_107 () ;
if ( V_15 -> V_193 == V_188 || V_15 -> V_194 == V_190 ) {
F_108 ( V_189 ) ;
return false ;
}
F_108 ( V_189 ) ;
V_15 -> V_195 = V_15 -> V_185 . time ;
V_15 -> V_185 . time = time ;
V_15 -> V_185 . V_187 = V_187 ;
V_15 -> V_185 . V_188 = V_188 ;
V_15 -> V_185 . V_190 = V_190 ;
V_15 -> V_185 . V_187 -= V_15 -> V_196 ;
V_15 -> V_185 . V_188 -= V_15 -> V_193 ;
V_15 -> V_185 . V_190 -= V_15 -> V_194 ;
V_15 -> V_196 = V_187 ;
V_15 -> V_193 = V_188 ;
V_15 -> V_194 = V_190 ;
return ! ! V_15 -> V_195 ;
}
static inline T_1 F_109 ( struct V_25 * V_15 )
{
return F_6 ( V_15 -> V_185 . V_186 ,
V_15 -> V_68 . V_179 * V_15 -> V_68 . V_172 ) ;
}
static inline T_1 F_110 ( struct V_25 * V_15 )
{
return F_6 ( V_15 -> V_68 . V_179 ,
V_15 -> V_185 . V_186 ) ;
}
static inline T_1 F_111 ( struct V_25 * V_15 )
{
struct V_185 * V_185 = & V_15 -> V_185 ;
T_1 V_197 , V_198 ;
int V_199 , V_200 ;
V_197 = F_2 ( V_185 -> V_188 , V_185 -> V_190 ) ;
V_198 = V_15 -> V_201 ;
V_15 -> V_201 >>= 1 ;
if ( V_197 < V_198 )
V_197 = V_198 ;
V_185 -> V_202 = V_197 * 100 ;
V_199 = V_40 -> V_105 || V_40 -> V_41 ?
V_15 -> V_68 . V_69 : V_15 -> V_68 . V_70 ;
V_199 += V_199 >> 2 ;
V_199 = F_1 ( V_199 , V_197 ) ;
if ( V_199 < V_15 -> V_68 . V_126 )
V_199 = V_15 -> V_68 . V_126 ;
V_200 = F_110 ( V_15 ) ;
if ( V_200 > V_199 )
V_199 += ( V_200 - V_199 ) >> 1 ;
return V_199 ;
}
static inline T_1 F_112 ( struct V_25 * V_15 )
{
T_1 V_203 , V_69 , V_173 , V_204 ;
T_3 V_205 ;
V_69 = V_15 -> V_68 . V_179 ;
V_173 = V_15 -> V_68 . V_173 ;
V_203 = F_6 ( V_15 -> V_185 . V_186 ,
F_2 ( 100 * V_69 , V_173 ) ) ;
V_205 = V_15 -> V_185 . time - V_15 -> V_195 ;
if ( ( T_2 ) V_205 > V_61 . V_206 * 3 ) {
V_204 = F_2 ( V_61 . V_206 , V_205 ) ;
V_203 = F_1 ( V_203 , V_204 ) ;
} else {
V_204 = F_2 ( 100 * V_15 -> V_185 . V_188 , V_15 -> V_185 . V_190 ) ;
if ( V_204 < F_22 ( 1 ) )
V_203 = 0 ;
}
V_15 -> V_185 . V_202 = V_203 ;
return V_15 -> V_68 . V_173 - F_26 ( & V_15 -> V_46 , V_203 ) ;
}
static int F_113 ( struct V_25 * V_15 , int V_68 )
{
int V_134 , V_136 ;
F_97 ( V_15 , & V_136 , & V_134 ) ;
V_68 = F_70 ( int , V_68 , V_136 , V_134 ) ;
F_100 ( V_68 * V_15 -> V_68 . V_172 , V_15 -> V_15 ) ;
return V_68 ;
}
static void F_114 ( struct V_25 * V_15 , int V_68 )
{
V_68 = F_113 ( V_15 , V_68 ) ;
if ( V_68 == V_15 -> V_68 . V_173 )
return;
V_15 -> V_68 . V_173 = V_68 ;
F_115 ( V_174 , V_175 . V_176 ( V_15 , V_68 ) ) ;
}
static inline void F_116 ( struct V_25 * V_15 )
{
int V_207 , V_208 ;
struct V_185 * V_185 ;
V_207 = V_15 -> V_68 . V_173 ;
V_208 = V_15 -> V_24 == V_110 ?
V_15 -> V_68 . V_70 : V_175 . V_209 ( V_15 ) ;
F_30 () ;
F_114 ( V_15 , V_208 ) ;
V_185 = & V_15 -> V_185 ;
F_117 ( F_6 ( 100 , V_185 -> V_186 ) ,
F_5 ( V_185 -> V_202 ) ,
V_207 ,
V_15 -> V_68 . V_173 ,
V_185 -> V_188 ,
V_185 -> V_187 ,
V_185 -> V_190 ,
F_109 ( V_15 ) ,
F_5 ( V_15 -> V_201 * 100 ) ) ;
}
static void F_118 ( struct V_210 * V_112 , T_3 time ,
unsigned int V_189 )
{
struct V_25 * V_15 = F_119 ( V_112 , struct V_25 , V_211 ) ;
T_3 V_212 ;
if ( V_175 . V_209 == F_111 ) {
if ( V_189 & V_213 ) {
V_15 -> V_201 = F_22 ( 1 ) ;
} else if ( V_15 -> V_201 ) {
V_212 = time - V_15 -> V_214 ;
if ( V_212 > V_215 )
V_15 -> V_201 = 0 ;
}
V_15 -> V_214 = time ;
}
V_212 = time - V_15 -> V_185 . time ;
if ( ( T_2 ) V_212 >= V_61 . V_206 ) {
bool V_216 = F_105 ( V_15 , time ) ;
if ( V_216 ) {
F_104 ( V_15 ) ;
if ( ! V_27 )
F_116 ( V_15 ) ;
}
}
}
static int F_120 ( unsigned int V_217 )
{
struct V_25 * V_15 ;
V_15 = V_28 [ V_217 ] ;
if ( ! V_15 ) {
unsigned int V_218 = sizeof( struct V_25 ) ;
if ( V_103 )
V_218 += sizeof( struct V_99 ) ;
V_15 = F_121 ( V_218 , V_219 ) ;
if ( ! V_15 )
return - V_220 ;
V_28 [ V_217 ] = V_15 ;
if ( V_103 )
V_15 -> V_99 = (struct V_99 * ) ( V_15 + 1 ) ;
V_15 -> V_84 = - V_82 ;
V_15 -> V_111 = - V_82 ;
V_15 -> V_108 = - V_82 ;
}
V_15 = V_28 [ V_217 ] ;
V_15 -> V_15 = V_217 ;
if ( V_27 ) {
const struct V_221 * V_222 ;
V_222 = F_122 ( V_223 ) ;
if ( V_222 )
F_79 ( V_217 ) ;
F_78 ( V_15 ) ;
V_61 . V_224 = 50 ;
V_61 . V_206 = 50 * V_225 ;
}
F_103 ( V_15 ) ;
F_27 ( V_15 ) ;
F_18 ( L_15 , V_217 ) ;
return 0 ;
}
static unsigned int F_123 ( unsigned int V_226 )
{
struct V_25 * V_15 = V_28 [ V_226 ] ;
return V_15 ? F_109 ( V_15 ) : 0 ;
}
static void F_124 ( unsigned int V_226 )
{
struct V_25 * V_15 = V_28 [ V_226 ] ;
if ( V_15 -> V_227 )
return;
V_15 -> V_185 . time = 0 ;
F_125 ( V_226 , & V_15 -> V_211 ,
F_118 ) ;
V_15 -> V_227 = true ;
}
static void F_126 ( unsigned int V_15 )
{
struct V_25 * V_71 = V_28 [ V_15 ] ;
if ( ! V_71 -> V_227 )
return;
F_127 ( V_15 ) ;
V_71 -> V_227 = false ;
F_128 () ;
}
static void F_129 ( struct V_99 * V_40 )
{
V_40 -> V_105 = 0 ;
V_40 -> V_41 = 0 ;
V_40 -> V_101 = 100 ;
V_40 -> V_134 = F_130 ( 1 ) ;
V_40 -> V_102 = 100 ;
V_40 -> V_136 = F_130 ( 1 ) ;
V_40 -> V_132 = 100 ;
V_40 -> V_131 = 100 ;
V_40 -> V_133 = 0 ;
V_40 -> V_135 = 0 ;
}
static void F_131 ( struct V_23 * V_24 ,
struct V_99 * V_40 )
{
V_40 -> V_132 = F_132 ( V_24 -> V_95 * 100 ,
V_24 -> V_42 . V_43 ) ;
V_40 -> V_132 = F_70 ( int , V_40 -> V_132 , 0 , 100 ) ;
if ( V_24 -> V_95 == V_24 -> V_93 ) {
V_40 -> V_133 = V_40 -> V_132 ;
} else {
V_40 -> V_133 = F_132 ( V_24 -> V_93 * 100 ,
V_24 -> V_42 . V_43 ) ;
V_40 -> V_133 = F_70 ( int , V_40 -> V_133 ,
0 , 100 ) ;
}
V_40 -> V_102 = V_95 ( V_40 -> V_133 ,
V_40 -> V_135 ) ;
V_40 -> V_102 = V_93 ( V_40 -> V_132 ,
V_40 -> V_102 ) ;
V_40 -> V_101 = V_93 ( V_40 -> V_132 ,
V_40 -> V_131 ) ;
V_40 -> V_101 = V_95 ( V_40 -> V_133 ,
V_40 -> V_101 ) ;
V_40 -> V_102 = V_93 ( V_40 -> V_101 , V_40 -> V_102 ) ;
V_40 -> V_136 = F_7 ( V_40 -> V_102 , 100 ) ;
V_40 -> V_134 = F_7 ( V_40 -> V_101 , 100 ) ;
V_40 -> V_134 = F_133 ( V_40 -> V_134 , V_7 ) ;
V_40 -> V_136 = F_133 ( V_40 -> V_136 , V_7 ) ;
F_18 ( L_16 , V_24 -> V_15 ,
V_40 -> V_101 , V_40 -> V_102 ) ;
}
static int F_134 ( struct V_23 * V_24 )
{
struct V_25 * V_15 ;
struct V_99 * V_99 = NULL ;
if ( ! V_24 -> V_42 . V_43 )
return - V_228 ;
F_18 ( L_17 ,
V_24 -> V_42 . V_43 , V_24 -> V_95 ) ;
V_15 = V_28 [ V_24 -> V_15 ] ;
V_15 -> V_24 = V_24 -> V_24 ;
if ( V_15 -> V_68 . V_179 > V_15 -> V_68 . V_69 &&
V_24 -> V_95 < V_24 -> V_42 . V_43 &&
V_24 -> V_95 > V_15 -> V_68 . V_69 * V_15 -> V_68 . V_172 ) {
F_18 ( L_18 ) ;
V_24 -> V_95 = V_24 -> V_42 . V_43 ;
}
if ( V_103 )
V_99 = V_15 -> V_99 ;
F_40 ( & V_85 ) ;
if ( V_24 -> V_24 == V_110 ) {
if ( ! V_99 ) {
V_40 = & V_229 ;
V_99 = V_40 ;
}
if ( V_24 -> V_95 >= V_24 -> V_42 . V_43 &&
! V_40 -> V_105 ) {
F_18 ( L_19 ) ;
F_129 ( V_99 ) ;
goto V_230;
}
} else {
F_18 ( L_20 ) ;
if ( ! V_99 ) {
V_40 = & V_231 ;
V_99 = V_40 ;
}
}
F_131 ( V_24 , V_99 ) ;
V_230:
if ( V_15 -> V_24 == V_110 ) {
F_126 ( V_24 -> V_15 ) ;
F_102 ( V_15 ) ;
}
F_124 ( V_24 -> V_15 ) ;
F_53 ( V_24 ) ;
F_42 ( & V_85 ) ;
return 0 ;
}
static int F_135 ( struct V_23 * V_24 )
{
F_136 ( V_24 ) ;
if ( V_24 -> V_24 != V_232 &&
V_24 -> V_24 != V_110 )
return - V_82 ;
if ( ! V_103 ) {
unsigned int V_43 , V_233 ;
V_43 = V_24 -> V_42 . V_43 *
V_40 -> V_131 / 100 ;
V_233 = V_24 -> V_42 . V_43 *
V_40 -> V_135 / 100 ;
F_137 ( V_24 , V_233 , V_43 ) ;
}
return 0 ;
}
static void F_138 ( struct V_23 * V_24 )
{
F_101 ( V_28 [ V_24 -> V_15 ] ) ;
}
static void F_139 ( struct V_23 * V_24 )
{
F_18 ( L_21 , V_24 -> V_15 ) ;
F_126 ( V_24 -> V_15 ) ;
if ( V_27 )
F_54 ( V_24 ) ;
else
F_138 ( V_24 ) ;
}
static int F_140 ( struct V_23 * V_24 )
{
F_20 ( V_24 ) ;
V_24 -> V_234 = false ;
return 0 ;
}
static int F_141 ( struct V_23 * V_24 )
{
struct V_25 * V_15 ;
int V_138 ;
V_138 = F_120 ( V_24 -> V_15 ) ;
if ( V_138 )
return V_138 ;
V_15 = V_28 [ V_24 -> V_15 ] ;
if ( V_103 )
memcpy ( V_15 -> V_99 , V_40 , sizeof( struct V_99 ) ) ;
V_24 -> V_93 = V_15 -> V_68 . V_126 * V_15 -> V_68 . V_172 ;
V_24 -> V_95 = V_15 -> V_68 . V_70 * V_15 -> V_68 . V_172 ;
V_24 -> V_42 . V_233 = V_15 -> V_68 . V_126 * V_15 -> V_68 . V_172 ;
F_30 () ;
V_24 -> V_42 . V_43 = V_40 -> V_41 ?
V_15 -> V_68 . V_69 : V_15 -> V_68 . V_70 ;
V_24 -> V_42 . V_43 *= V_15 -> V_68 . V_172 ;
F_16 ( V_24 ) ;
F_142 ( V_24 -> V_15 , V_24 -> V_235 ) ;
V_24 -> V_234 = true ;
return 0 ;
}
static int F_143 ( struct V_23 * V_24 )
{
int V_6 = F_141 ( V_24 ) ;
if ( V_6 )
return V_6 ;
V_24 -> V_42 . V_236 = V_237 ;
if ( V_40 -> V_102 == 100 && V_40 -> V_101 == 100 )
V_24 -> V_24 = V_110 ;
else
V_24 -> V_24 = V_232 ;
return 0 ;
}
static int F_144 ( struct V_23 * V_24 )
{
struct V_25 * V_15 = V_28 [ V_24 -> V_15 ] ;
struct V_99 * V_99 = V_40 ;
F_30 () ;
V_24 -> V_42 . V_43 = V_40 -> V_41 ?
V_15 -> V_68 . V_43 : V_15 -> V_68 . V_183 ;
F_136 ( V_24 ) ;
if ( V_103 )
V_99 = V_15 -> V_99 ;
F_40 ( & V_85 ) ;
F_131 ( V_24 , V_99 ) ;
F_42 ( & V_85 ) ;
return 0 ;
}
static unsigned int F_145 ( struct V_25 * V_15 ,
struct V_23 * V_24 ,
unsigned int V_238 )
{
unsigned int V_43 ;
F_30 () ;
V_43 = V_40 -> V_105 || V_40 -> V_41 ?
V_15 -> V_68 . V_43 : V_15 -> V_68 . V_183 ;
V_24 -> V_42 . V_43 = V_43 ;
if ( V_24 -> V_95 > V_43 )
V_24 -> V_95 = V_43 ;
if ( V_238 > V_43 )
V_238 = V_43 ;
return V_238 ;
}
static int F_146 ( struct V_23 * V_24 ,
unsigned int V_238 ,
unsigned int V_239 )
{
struct V_25 * V_15 = V_28 [ V_24 -> V_15 ] ;
struct V_240 V_241 ;
int V_208 ;
V_241 . V_242 = V_24 -> V_243 ;
V_241 . V_244 = F_145 ( V_15 , V_24 , V_238 ) ;
F_147 ( V_24 , & V_241 ) ;
switch ( V_239 ) {
case V_245 :
V_208 = F_132 ( V_241 . V_244 , V_15 -> V_68 . V_172 ) ;
break;
case V_246 :
V_208 = V_241 . V_244 / V_15 -> V_68 . V_172 ;
break;
default:
V_208 = F_148 ( V_241 . V_244 , V_15 -> V_68 . V_172 ) ;
break;
}
V_208 = F_113 ( V_15 , V_208 ) ;
if ( V_208 != V_15 -> V_68 . V_173 ) {
V_15 -> V_68 . V_173 = V_208 ;
F_37 ( V_24 -> V_15 , V_174 ,
V_175 . V_176 ( V_15 , V_208 ) ) ;
}
F_149 ( V_24 , & V_241 , false ) ;
return 0 ;
}
static unsigned int F_150 ( struct V_23 * V_24 ,
unsigned int V_238 )
{
struct V_25 * V_15 = V_28 [ V_24 -> V_15 ] ;
int V_208 ;
V_238 = F_145 ( V_15 , V_24 , V_238 ) ;
V_208 = F_132 ( V_238 , V_15 -> V_68 . V_172 ) ;
F_114 ( V_15 , V_208 ) ;
return V_238 ;
}
static int F_151 ( struct V_23 * V_24 )
{
int V_6 = F_141 ( V_24 ) ;
if ( V_6 )
return V_6 ;
V_24 -> V_42 . V_236 = V_247 ;
V_24 -> V_243 = V_24 -> V_42 . V_233 ;
return 0 ;
}
static int T_8 F_152 ( void )
{
if ( ! V_175 . V_178 () ||
! V_175 . V_177 () ||
! V_175 . V_181 () )
return - V_228 ;
return 0 ;
}
static void T_8 F_153 ( struct V_248 * V_24 )
{
V_61 . V_224 = V_24 -> V_224 ;
V_61 . V_206 = V_61 . V_224 * V_225 ;
V_61 . V_62 = V_24 -> V_62 ;
V_61 . V_64 = V_24 -> V_64 ;
V_61 . V_63 = V_24 -> V_63 ;
V_61 . V_49 = V_24 -> V_49 ;
V_61 . V_47 = V_24 -> V_47 ;
}
static void F_154 ( void )
{
if ( V_8 . V_9 == V_249 )
V_175 . V_209 =
F_111 ;
}
static void F_154 ( void )
{
}
static void T_8 F_155 ( struct V_175 * V_250 )
{
V_175 . V_178 = V_250 -> V_178 ;
V_175 . V_180 = V_250 -> V_180 ;
V_175 . V_177 = V_250 -> V_177 ;
V_175 . V_181 = V_250 -> V_181 ;
V_175 . V_182 = V_250 -> V_182 ;
V_175 . V_176 = V_250 -> V_176 ;
V_175 . V_184 = V_250 -> V_184 ;
V_175 . V_209 = V_250 -> V_209 ;
F_154 () ;
}
static bool T_8 F_156 ( void )
{
int V_26 ;
F_57 (i) {
T_10 V_251 ;
union V_252 * V_253 ;
struct V_254 V_255 = { V_256 , NULL } ;
struct V_257 * V_258 = F_157 ( V_259 , V_26 ) ;
if ( ! V_258 )
continue;
V_251 = F_158 ( V_258 -> V_260 , L_22 , NULL , & V_255 ) ;
if ( F_159 ( V_251 ) )
continue;
V_253 = V_255 . V_261 ;
if ( V_253 && V_253 -> type == V_262 ) {
F_160 ( V_253 ) ;
return false ;
}
F_160 ( V_253 ) ;
}
return true ;
}
static bool T_8 F_161 ( void )
{
int V_26 ;
F_57 (i) {
struct V_257 * V_258 = F_157 ( V_259 , V_26 ) ;
if ( ! V_258 )
continue;
if ( F_162 ( V_258 -> V_260 , L_23 ) )
return true ;
}
return false ;
}
static bool T_8 F_163 ( void )
{
struct V_263 V_264 ;
struct V_265 * V_266 ;
const struct V_221 * V_222 ;
T_3 V_267 ;
V_222 = F_122 ( V_268 ) ;
if ( V_222 ) {
F_31 ( V_269 , V_267 ) ;
if ( V_267 & ( 1 << 8 ) )
return true ;
}
if ( V_270 ||
F_159 ( F_164 ( V_271 , 0 , & V_264 ) ) )
return false ;
for ( V_266 = V_272 ; V_266 -> V_273 ; V_266 ++ ) {
if ( ! strncmp ( V_264 . V_274 , V_266 -> V_274 , V_275 ) &&
! strncmp ( V_264 . V_276 , V_266 -> V_276 ,
V_277 ) )
switch ( V_266 -> V_278 ) {
case V_279 :
return F_156 () ;
case V_280 :
return F_161 () &&
( ! V_281 ) ;
}
}
return false ;
}
static void F_165 ( void )
{
if ( V_12 )
F_166 () ;
}
static inline bool F_163 ( void ) { return false ; }
static inline bool F_161 ( void ) { return false ; }
static inline void F_165 ( void ) {}
static int T_8 F_167 ( void )
{
int V_15 , V_138 = 0 ;
const struct V_221 * V_222 ;
struct V_282 * V_283 ;
if ( V_284 )
return - V_228 ;
if ( F_122 ( V_285 ) && ! V_286 ) {
F_155 ( & V_287 . V_250 ) ;
V_27 ++ ;
V_288 . V_122 = V_289 ;
goto V_290;
}
V_222 = F_122 ( V_291 ) ;
if ( ! V_222 )
return - V_228 ;
V_283 = (struct V_282 * ) V_222 -> V_292 ;
F_153 ( & V_283 -> V_293 ) ;
F_155 ( & V_283 -> V_250 ) ;
if ( F_152 () )
return - V_228 ;
V_290:
if ( F_163 () )
return - V_228 ;
F_81 ( L_24 ) ;
V_28 = F_168 ( sizeof( void * ) * F_169 () ) ;
if ( ! V_28 )
return - V_220 ;
if ( ! V_27 && V_294 )
goto V_230;
F_165 () ;
V_138 = F_170 ( V_295 ) ;
if ( V_138 )
goto V_230;
if ( V_295 == & V_288 && ! V_27 &&
V_175 . V_209 != F_111 )
F_61 () ;
F_73 () ;
if ( V_27 )
F_81 ( L_25 ) ;
return V_138 ;
V_230:
F_171 () ;
F_29 (cpu) {
if ( V_28 [ V_15 ] ) {
if ( V_295 == & V_288 )
F_126 ( V_15 ) ;
F_160 ( V_28 [ V_15 ] ) ;
}
}
F_172 () ;
F_173 ( V_28 ) ;
return - V_228 ;
}
static int T_8 F_174 ( char * V_296 )
{
if ( ! V_296 )
return - V_82 ;
if ( ! strcmp ( V_296 , L_26 ) ) {
V_284 = 1 ;
} else if ( ! strcmp ( V_296 , L_27 ) ) {
F_81 ( L_28 ) ;
V_295 = & V_297 ;
V_286 = 1 ;
}
if ( ! strcmp ( V_296 , L_29 ) ) {
F_81 ( L_30 ) ;
V_286 = 1 ;
}
if ( ! strcmp ( V_296 , L_31 ) )
V_281 = 1 ;
if ( ! strcmp ( V_296 , L_32 ) )
V_294 = 1 ;
if ( ! strcmp ( V_296 , L_33 ) )
V_103 = true ;
#ifdef F_175
if ( ! strcmp ( V_296 , L_34 ) )
V_12 = true ;
#endif
return 0 ;
}
