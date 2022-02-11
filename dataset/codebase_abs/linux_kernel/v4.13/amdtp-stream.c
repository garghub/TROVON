int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_5 V_6 , enum V_7 V_8 ,
unsigned int V_9 ,
T_1 V_10 ,
unsigned int V_11 )
{
if ( V_10 == NULL )
return - V_12 ;
V_2 -> V_13 = F_2 ( V_11 , V_14 ) ;
if ( ! V_2 -> V_13 )
return - V_15 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_16 = V_6 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_17 = F_3 ( - 1 ) ;
F_4 ( & V_2 -> V_18 ) ;
F_5 ( & V_2 -> V_19 , V_20 , ( unsigned long ) V_2 ) ;
V_2 -> V_21 = 0 ;
F_6 ( & V_2 -> V_22 ) ;
V_2 -> V_23 = false ;
V_2 -> V_9 = V_9 ;
V_2 -> V_10 = V_10 ;
return 0 ;
}
void F_7 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 == NULL )
return;
F_8 ( F_9 ( V_2 ) ) ;
F_10 ( V_2 -> V_13 ) ;
F_11 ( & V_2 -> V_18 ) ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 = & V_25 -> V_27 ;
int V_28 ;
V_27 -> V_29 = V_30 |
V_31 |
V_32 |
V_33 |
V_34 |
V_35 ;
V_27 -> V_36 = 2 ;
V_27 -> V_37 = V_38 ;
V_27 -> V_39 = 4 * V_27 -> V_40 ;
V_27 -> V_41 = V_27 -> V_39 * 2048 ;
V_27 -> V_42 = V_27 -> V_41 * V_27 -> V_36 ;
V_28 = F_13 ( V_25 ,
V_43 ,
5000 , V_38 ) ;
if ( V_28 < 0 )
goto V_44;
if ( ! ( V_2 -> V_8 & V_45 ) )
goto V_44;
V_28 = F_14 ( V_25 , 0 ,
V_46 , 32 ) ;
if ( V_28 < 0 )
goto V_44;
V_28 = F_14 ( V_25 , 0 ,
V_47 , 32 ) ;
V_44:
return V_28 ;
}
int F_15 ( struct V_1 * V_2 , unsigned int V_48 ,
unsigned int V_49 )
{
unsigned int V_50 ;
for ( V_50 = 0 ; V_50 < F_16 ( V_51 ) ; ++ V_50 ) {
if ( V_51 [ V_50 ] == V_48 )
break;
}
if ( V_50 == F_16 ( V_51 ) )
return - V_12 ;
V_2 -> V_50 = V_50 ;
V_2 -> V_49 = V_49 ;
V_2 -> V_52 = V_53 [ V_50 ] ;
V_2 -> V_54 = V_55 - V_56 ;
if ( V_2 -> V_8 & V_45 )
V_2 -> V_54 += V_57 * V_2 -> V_52 / V_48 ;
return 0 ;
}
unsigned int F_17 ( struct V_1 * V_2 )
{
unsigned int V_58 = 1 ;
unsigned int V_59 = 0 ;
if ( V_2 -> V_8 & V_60 )
V_58 = 5 ;
if ( ! ( V_2 -> V_8 & V_61 ) )
V_59 = 8 ;
return V_59 +
V_2 -> V_52 * V_2 -> V_49 * 4 * V_58 ;
}
void F_18 ( struct V_1 * V_2 )
{
F_19 ( & V_2 -> V_19 ) ;
V_2 -> V_62 = 0 ;
V_2 -> V_63 = 0 ;
}
static unsigned int F_20 ( struct V_1 * V_2 ,
unsigned int V_64 )
{
unsigned int V_65 , V_66 ;
if ( V_2 -> V_8 & V_45 ) {
if ( V_64 == V_67 )
V_66 = 0 ;
else
V_66 = V_2 -> V_52 ;
} else {
if ( ! F_21 ( V_2 -> V_50 ) ) {
V_66 = V_2 -> V_68 ;
} else {
V_65 = V_2 -> V_68 ;
if ( V_2 -> V_50 == V_69 )
V_66 = 5 + ( ( V_65 & 1 ) ^
( V_65 == 0 || V_65 >= 40 ) ) ;
else
V_66 = 11 * ( V_2 -> V_50 >> 1 ) + ( V_65 == 0 ) ;
if ( ++ V_65 >= ( 80 >> ( V_2 -> V_50 >> 1 ) ) )
V_65 = 0 ;
V_2 -> V_68 = V_65 ;
}
}
return V_66 ;
}
static unsigned int F_22 ( struct V_1 * V_2 ,
unsigned int V_70 )
{
unsigned int V_71 , V_65 , V_72 , V_64 ;
if ( V_2 -> V_73 < V_56 ) {
if ( ! F_21 ( V_2 -> V_50 ) )
V_71 = V_2 -> V_73 + V_2 -> V_74 ;
else {
V_65 = V_2 -> V_74 ;
V_72 = V_65 % 13 ;
V_71 = V_2 -> V_73 ;
V_71 += 1386 + ( ( V_72 && ! ( V_72 & 3 ) ) ||
V_65 == 146 ) ;
if ( ++ V_65 >= 147 )
V_65 = 0 ;
V_2 -> V_74 = V_65 ;
}
} else
V_71 = V_2 -> V_73 - V_56 ;
V_2 -> V_73 = V_71 ;
if ( V_71 < V_56 ) {
V_71 += V_2 -> V_54 ;
V_64 = ( V_70 + V_71 / V_56 ) << 12 ;
V_64 += V_71 % V_56 ;
return V_64 & V_75 ;
} else {
return V_67 ;
}
}
static void F_23 ( struct V_1 * V_2 ,
struct V_76 * V_77 ,
unsigned int V_78 )
{
unsigned int V_79 ;
V_79 = V_2 -> V_62 + V_78 ;
if ( V_79 >= V_77 -> V_25 -> V_80 )
V_79 -= V_77 -> V_25 -> V_80 ;
F_24 ( V_2 -> V_62 ) = V_79 ;
V_2 -> V_63 += V_78 ;
if ( V_2 -> V_63 >= V_77 -> V_25 -> V_81 ) {
V_2 -> V_63 -= V_77 -> V_25 -> V_81 ;
F_25 ( & V_2 -> V_19 ) ;
}
}
static void V_20 ( unsigned long V_82 )
{
struct V_1 * V_2 = ( void * ) V_82 ;
struct V_76 * V_77 = F_24 ( V_2 -> V_77 ) ;
if ( V_77 )
F_26 ( V_77 ) ;
}
static int F_27 ( struct V_1 * V_2 , unsigned int V_83 ,
unsigned int V_84 )
{
struct V_85 V_86 = { 0 } ;
int V_28 = 0 ;
if ( F_28 ( V_2 -> V_17 ) )
goto V_44;
V_86 . V_87 = F_29 ( V_2 -> V_21 + 1 , V_88 ) ;
V_86 . V_89 = V_2 -> V_89 ;
V_86 . V_83 = V_83 ;
if ( V_84 > 0 )
V_86 . V_84 = V_84 ;
else
V_86 . V_90 = true ;
V_28 = F_30 ( V_2 -> V_17 , & V_86 , & V_2 -> V_91 . V_92 ,
V_2 -> V_91 . V_93 [ V_2 -> V_21 ] . V_94 ) ;
if ( V_28 < 0 ) {
F_31 ( & V_2 -> V_4 -> V_95 , L_1 , V_28 ) ;
goto V_44;
}
if ( ++ V_2 -> V_21 >= V_96 )
V_2 -> V_21 = 0 ;
V_44:
return V_28 ;
}
static inline int F_32 ( struct V_1 * V_2 ,
unsigned int V_84 )
{
return F_27 ( V_2 , V_97 , V_84 ) ;
}
static inline int F_33 ( struct V_1 * V_2 )
{
return F_27 ( V_2 , V_98 , V_2 -> V_99 ) ;
}
static int F_34 ( struct V_1 * V_2 ,
unsigned int V_84 , unsigned int V_70 ,
unsigned int V_72 )
{
T_2 * V_91 ;
unsigned int V_64 ;
unsigned int V_66 ;
unsigned int V_100 ;
struct V_76 * V_77 ;
V_91 = V_2 -> V_91 . V_93 [ V_2 -> V_21 ] . V_91 ;
V_64 = F_22 ( V_2 , V_70 ) ;
V_66 = F_20 ( V_2 , V_64 ) ;
V_100 = V_2 -> V_10 ( V_2 , V_91 + 2 , V_66 , & V_64 ) ;
if ( V_2 -> V_8 & V_101 )
V_2 -> V_102 =
( V_2 -> V_102 + V_66 ) & 0xff ;
V_91 [ 0 ] = F_35 ( F_24 ( V_2 -> V_103 ) |
( V_2 -> V_49 << V_104 ) |
( ( V_2 -> V_105 << V_106 ) & V_107 ) |
V_2 -> V_102 ) ;
V_91 [ 1 ] = F_35 ( V_108 |
( ( V_2 -> V_9 << V_109 ) & V_110 ) |
( ( V_2 -> V_111 << V_112 ) & V_113 ) |
( V_64 & V_75 ) ) ;
if ( ! ( V_2 -> V_8 & V_101 ) )
V_2 -> V_102 =
( V_2 -> V_102 + V_66 ) & 0xff ;
V_84 = 8 + V_66 * 4 * V_2 -> V_49 ;
F_36 ( V_2 , V_70 , V_91 , V_84 , V_72 ) ;
if ( F_32 ( V_2 , V_84 ) < 0 )
return - V_114 ;
V_77 = F_24 ( V_2 -> V_77 ) ;
if ( V_77 && V_100 > 0 )
F_23 ( V_2 , V_77 , V_100 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
unsigned int V_84 , unsigned int V_70 ,
unsigned int V_72 )
{
T_2 * V_91 ;
unsigned int V_64 ;
unsigned int V_66 ;
unsigned int V_100 ;
struct V_76 * V_77 ;
V_91 = V_2 -> V_91 . V_93 [ V_2 -> V_21 ] . V_91 ;
V_64 = F_22 ( V_2 , V_70 ) ;
V_66 = F_20 ( V_2 , V_64 ) ;
V_100 = V_2 -> V_10 ( V_2 , V_91 , V_66 , & V_64 ) ;
V_2 -> V_102 = ( V_2 -> V_102 + V_66 ) & 0xff ;
V_84 = V_66 * 4 * V_2 -> V_49 ;
F_38 ( V_2 , V_70 , V_84 , V_66 ,
V_72 ) ;
if ( F_32 ( V_2 , V_84 ) < 0 )
return - V_114 ;
V_77 = F_24 ( V_2 -> V_77 ) ;
if ( V_77 && V_100 > 0 )
F_23 ( V_2 , V_77 , V_100 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
unsigned int V_84 , unsigned int V_70 ,
unsigned int V_72 )
{
T_2 * V_91 ;
T_3 V_115 [ 2 ] ;
unsigned int V_105 , V_9 , V_111 , V_64 ;
unsigned int V_49 , V_102 , V_116 ;
unsigned int V_66 ;
struct V_76 * V_77 ;
unsigned int V_100 ;
bool V_117 ;
V_91 = V_2 -> V_91 . V_93 [ V_2 -> V_21 ] . V_91 ;
V_115 [ 0 ] = F_40 ( V_91 [ 0 ] ) ;
V_115 [ 1 ] = F_40 ( V_91 [ 1 ] ) ;
F_41 ( V_2 , V_70 , V_115 , V_84 , V_72 ) ;
if ( ( ( ( V_115 [ 0 ] & V_118 ) == V_108 ) ||
( ( V_115 [ 1 ] & V_118 ) != V_108 ) ) &&
( ! ( V_2 -> V_8 & V_119 ) ) ) {
F_42 ( & V_2 -> V_4 -> V_95 ,
L_2 ,
V_115 [ 0 ] , V_115 [ 1 ] ) ;
V_66 = 0 ;
V_100 = 0 ;
goto V_44;
}
V_105 = ( V_115 [ 0 ] & V_107 ) >> V_106 ;
V_9 = ( V_115 [ 1 ] & V_110 ) >> V_109 ;
if ( V_105 != V_2 -> V_105 || V_9 != V_2 -> V_9 ) {
F_42 ( & V_2 -> V_4 -> V_95 ,
L_3 ,
V_115 [ 0 ] , V_115 [ 1 ] ) ;
V_66 = 0 ;
V_100 = 0 ;
goto V_44;
}
V_111 = ( V_115 [ 1 ] & V_113 ) >> V_112 ;
if ( V_84 < 12 ||
( V_9 == V_120 && V_111 == V_121 ) ) {
V_66 = 0 ;
} else {
V_49 =
( V_115 [ 0 ] & V_122 ) >> V_104 ;
if ( V_49 == 0 ) {
F_31 ( & V_2 -> V_4 -> V_95 ,
L_4 ,
V_115 [ 0 ] ) ;
return - V_123 ;
}
if ( V_2 -> V_8 & V_124 )
V_49 = V_2 -> V_49 ;
V_66 = ( V_84 / 4 - 2 ) /
V_49 ;
}
V_102 = V_115 [ 0 ] & V_125 ;
if ( V_66 == 0 && ( V_2 -> V_8 & V_126 ) &&
V_2 -> V_102 != V_38 )
V_102 = V_2 -> V_102 ;
if ( ( ( V_2 -> V_8 & V_127 ) &&
V_102 == V_2 -> V_128 ) ||
V_2 -> V_102 == V_38 ) {
V_117 = false ;
} else if ( ! ( V_2 -> V_8 & V_101 ) ) {
V_117 = V_102 != V_2 -> V_102 ;
} else {
if ( V_66 > 0 && V_2 -> V_129 > 0 )
V_116 = V_2 -> V_129 ;
else
V_116 = V_66 ;
V_117 = V_102 !=
( ( V_2 -> V_102 + V_116 ) & 0xff ) ;
}
if ( V_117 ) {
F_31 ( & V_2 -> V_4 -> V_95 ,
L_5 ,
V_2 -> V_102 , V_102 ) ;
return - V_114 ;
}
V_64 = F_40 ( V_91 [ 1 ] ) & V_75 ;
V_100 = V_2 -> V_10 ( V_2 , V_91 + 2 , V_66 , & V_64 ) ;
if ( V_2 -> V_8 & V_101 )
V_2 -> V_102 = V_102 ;
else
V_2 -> V_102 =
( V_102 + V_66 ) & 0xff ;
V_44:
if ( F_33 ( V_2 ) < 0 )
return - V_114 ;
V_77 = F_24 ( V_2 -> V_77 ) ;
if ( V_77 && V_100 > 0 )
F_23 ( V_2 , V_77 , V_100 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
unsigned int V_130 , unsigned int V_70 ,
unsigned int V_72 )
{
T_2 * V_91 ;
unsigned int V_66 ;
struct V_76 * V_77 ;
unsigned int V_100 ;
V_91 = V_2 -> V_91 . V_93 [ V_2 -> V_21 ] . V_91 ;
V_66 = V_130 / V_2 -> V_49 ;
F_44 ( V_2 , V_70 , V_130 , V_66 ,
V_72 ) ;
V_100 = V_2 -> V_10 ( V_2 , V_91 , V_66 , NULL ) ;
V_2 -> V_102 = ( V_2 -> V_102 + V_66 ) & 0xff ;
if ( F_33 ( V_2 ) < 0 )
return - V_114 ;
V_77 = F_24 ( V_2 -> V_77 ) ;
if ( V_77 && V_100 > 0 )
F_23 ( V_2 , V_77 , V_100 ) ;
return 0 ;
}
static inline T_3 F_45 ( T_3 V_131 )
{
return ( ( ( V_131 >> 13 ) & 0x07 ) * 8000 ) + ( V_131 & 0x1fff ) ;
}
static inline T_3 F_46 ( T_3 V_70 , unsigned int V_132 )
{
V_70 += V_132 ;
if ( V_70 >= 8 * V_133 )
V_70 -= 8 * V_133 ;
return V_70 ;
}
static inline T_3 F_47 ( T_3 V_70 , unsigned int V_134 )
{
if ( V_70 < V_134 )
V_70 += 8 * V_133 ;
return V_70 - V_134 ;
}
static void F_48 ( struct V_135 * V_17 , T_3 V_131 ,
T_4 V_83 , void * V_136 ,
void * V_137 )
{
struct V_1 * V_2 = V_137 ;
unsigned int V_138 , V_93 = V_83 / 4 ;
T_3 V_70 ;
if ( V_2 -> V_21 < 0 )
return;
V_70 = F_45 ( V_131 ) ;
V_70 = F_46 ( V_70 , V_96 - V_93 ) ;
for ( V_138 = 0 ; V_138 < V_93 ; ++ V_138 ) {
V_70 = F_46 ( V_70 , 1 ) ;
if ( V_2 -> V_139 ( V_2 , 0 , V_70 , V_138 ) < 0 ) {
V_2 -> V_21 = - 1 ;
if ( F_49 () )
F_50 ( V_2 ) ;
F_51 ( V_2 -> V_62 , V_140 ) ;
return;
}
}
F_52 ( V_2 -> V_17 ) ;
}
static void F_53 ( struct V_135 * V_17 , T_3 V_131 ,
T_4 V_83 , void * V_136 ,
void * V_137 )
{
struct V_1 * V_2 = V_137 ;
unsigned int V_138 , V_93 ;
unsigned int V_84 , V_99 ;
T_2 * V_141 = V_136 ;
T_3 V_70 ;
if ( V_2 -> V_21 < 0 )
return;
V_93 = V_83 / V_98 ;
V_70 = F_45 ( V_131 ) ;
V_70 = F_47 ( V_70 , V_93 ) ;
V_99 = V_2 -> V_99 ;
for ( V_138 = 0 ; V_138 < V_93 ; V_138 ++ ) {
V_70 = F_46 ( V_70 , 1 ) ;
V_84 =
( F_40 ( V_141 [ V_138 ] ) >> V_142 ) ;
if ( V_84 > V_99 ) {
F_31 ( & V_2 -> V_4 -> V_95 ,
L_6 ,
V_84 , V_99 ) ;
break;
}
if ( V_2 -> V_139 ( V_2 , V_84 , V_70 , V_138 ) < 0 )
break;
}
if ( V_138 < V_93 ) {
V_2 -> V_21 = - 1 ;
if ( F_49 () )
F_50 ( V_2 ) ;
F_51 ( V_2 -> V_62 , V_140 ) ;
return;
}
F_52 ( V_2 -> V_17 ) ;
}
static void F_54 ( struct V_135 * V_17 ,
T_3 V_131 , T_4 V_83 ,
void * V_136 , void * V_137 )
{
struct V_1 * V_2 = V_137 ;
T_3 V_70 ;
unsigned int V_93 ;
V_2 -> V_99 = F_17 ( V_2 ) ;
V_2 -> V_23 = true ;
F_55 ( & V_2 -> V_22 ) ;
V_70 = F_45 ( V_131 ) ;
if ( V_2 -> V_16 == V_143 ) {
V_93 = V_83 / V_98 ;
V_70 = F_47 ( V_70 , V_93 ) ;
V_17 -> V_144 . V_145 = F_53 ;
if ( V_2 -> V_8 & V_61 )
V_2 -> V_139 = F_43 ;
else
V_2 -> V_139 = F_39 ;
} else {
V_93 = V_83 / 4 ;
V_70 = F_46 ( V_70 , V_96 - V_93 ) ;
V_17 -> V_144 . V_145 = F_48 ;
if ( V_2 -> V_8 & V_61 )
V_2 -> V_139 = F_37 ;
else
V_2 -> V_139 = F_34 ;
}
V_2 -> V_146 = V_70 ;
V_17 -> V_144 . V_145 ( V_17 , V_131 , V_83 , V_136 , V_2 ) ;
}
int F_56 ( struct V_1 * V_2 , int V_147 , int V_148 )
{
static const struct {
unsigned int V_149 ;
unsigned int V_71 ;
} V_150 [] = {
[ V_151 ] = { 4 , 3072 } ,
[ V_152 ] = { 6 , 1024 } ,
[ V_153 ] = { 12 , 1024 } ,
[ V_154 ] = { 24 , 1024 } ,
[ V_69 ] = { 0 , 67 } ,
[ V_155 ] = { 0 , 67 } ,
[ V_156 ] = { 0 , 67 } ,
} ;
unsigned int V_59 ;
enum V_157 V_6 ;
int type , V_89 , V_28 ;
F_57 ( & V_2 -> V_18 ) ;
if ( F_8 ( F_9 ( V_2 ) ||
( V_2 -> V_49 < 1 ) ) ) {
V_28 = - V_158 ;
goto V_159;
}
if ( V_2 -> V_16 == V_143 )
V_2 -> V_102 = V_38 ;
else
V_2 -> V_102 = 0 ;
V_2 -> V_68 = V_150 [ V_2 -> V_50 ] . V_149 ;
V_2 -> V_74 = V_150 [ V_2 -> V_50 ] . V_71 ;
V_2 -> V_73 = V_56 ;
if ( V_2 -> V_16 == V_143 ) {
V_6 = V_160 ;
type = V_161 ;
V_59 = V_98 ;
} else {
V_6 = V_162 ;
type = V_163 ;
V_59 = V_97 ;
}
V_28 = F_58 ( & V_2 -> V_91 , V_2 -> V_4 , V_96 ,
F_17 ( V_2 ) , V_6 ) ;
if ( V_28 < 0 )
goto V_159;
V_2 -> V_17 = F_59 ( F_60 ( V_2 -> V_4 ) -> V_164 ,
type , V_147 , V_148 , V_59 ,
F_54 , V_2 ) ;
if ( F_28 ( V_2 -> V_17 ) ) {
V_28 = F_61 ( V_2 -> V_17 ) ;
if ( V_28 == - V_165 )
F_31 ( & V_2 -> V_4 -> V_95 ,
L_7 ) ;
goto V_166;
}
F_62 ( V_2 ) ;
if ( V_2 -> V_8 & V_61 )
V_2 -> V_89 = V_167 ;
else
V_2 -> V_89 = V_168 ;
V_2 -> V_21 = 0 ;
do {
if ( V_2 -> V_16 == V_143 )
V_28 = F_33 ( V_2 ) ;
else
V_28 = F_32 ( V_2 , 0 ) ;
if ( V_28 < 0 )
goto V_169;
} while ( V_2 -> V_21 > 0 );
V_89 = V_170 ;
if ( ( V_2 -> V_8 & V_171 ) || ( V_2 -> V_8 & V_61 ) )
V_89 |= V_172 ;
V_2 -> V_23 = false ;
V_28 = F_63 ( V_2 -> V_17 , - 1 , 0 , V_89 ) ;
if ( V_28 < 0 )
goto V_169;
F_64 ( & V_2 -> V_18 ) ;
return 0 ;
V_169:
F_65 ( V_2 -> V_17 ) ;
V_2 -> V_17 = F_3 ( - 1 ) ;
V_166:
F_66 ( & V_2 -> V_91 , V_2 -> V_4 ) ;
V_159:
F_64 ( & V_2 -> V_18 ) ;
return V_28 ;
}
unsigned long F_67 ( struct V_1 * V_2 )
{
if ( ! F_49 () && F_9 ( V_2 ) )
F_68 ( V_2 -> V_17 ) ;
return F_24 ( V_2 -> V_62 ) ;
}
int F_69 ( struct V_1 * V_2 )
{
if ( F_9 ( V_2 ) )
F_68 ( V_2 -> V_17 ) ;
return 0 ;
}
void F_62 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_103 ) =
( F_60 ( V_2 -> V_4 ) -> V_164 -> V_173 << V_174 ) &
V_175 ;
}
void F_70 ( struct V_1 * V_2 )
{
F_57 ( & V_2 -> V_18 ) ;
if ( ! F_9 ( V_2 ) ) {
F_64 ( & V_2 -> V_18 ) ;
return;
}
F_19 ( & V_2 -> V_19 ) ;
F_71 ( V_2 -> V_17 ) ;
F_65 ( V_2 -> V_17 ) ;
V_2 -> V_17 = F_3 ( - 1 ) ;
F_66 ( & V_2 -> V_91 , V_2 -> V_4 ) ;
V_2 -> V_23 = false ;
F_64 ( & V_2 -> V_18 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
struct V_76 * V_77 ;
V_77 = F_24 ( V_2 -> V_77 ) ;
if ( V_77 )
F_72 ( V_77 ) ;
}
