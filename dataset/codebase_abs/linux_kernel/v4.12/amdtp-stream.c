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
int V_26 ;
V_26 = F_13 ( V_25 ,
V_27 ,
5000 , V_28 ) ;
if ( V_26 < 0 )
goto V_29;
if ( ! ( V_2 -> V_8 & V_30 ) )
goto V_29;
V_26 = F_14 ( V_25 , 0 ,
V_31 , 32 ) ;
if ( V_26 < 0 )
goto V_29;
V_26 = F_14 ( V_25 , 0 ,
V_32 , 32 ) ;
V_29:
return V_26 ;
}
int F_15 ( struct V_1 * V_2 , unsigned int V_33 ,
unsigned int V_34 )
{
unsigned int V_35 ;
for ( V_35 = 0 ; V_35 < F_16 ( V_36 ) ; ++ V_35 ) {
if ( V_36 [ V_35 ] == V_33 )
break;
}
if ( V_35 == F_16 ( V_36 ) )
return - V_12 ;
V_2 -> V_35 = V_35 ;
V_2 -> V_34 = V_34 ;
V_2 -> V_37 = V_38 [ V_35 ] ;
V_2 -> V_39 = V_40 - V_41 ;
if ( V_2 -> V_8 & V_30 )
V_2 -> V_39 += V_42 * V_2 -> V_37 / V_33 ;
return 0 ;
}
unsigned int F_17 ( struct V_1 * V_2 )
{
unsigned int V_43 = 1 ;
unsigned int V_44 = 0 ;
if ( V_2 -> V_8 & V_45 )
V_43 = 5 ;
if ( ! ( V_2 -> V_8 & V_46 ) )
V_44 = 8 ;
return V_44 +
V_2 -> V_37 * V_2 -> V_34 * 4 * V_43 ;
}
void F_18 ( struct V_1 * V_2 )
{
F_19 ( & V_2 -> V_19 ) ;
V_2 -> V_47 = 0 ;
V_2 -> V_48 = 0 ;
}
static unsigned int F_20 ( struct V_1 * V_2 ,
unsigned int V_49 )
{
unsigned int V_50 , V_51 ;
if ( V_2 -> V_8 & V_30 ) {
if ( V_49 == V_52 )
V_51 = 0 ;
else
V_51 = V_2 -> V_37 ;
} else {
if ( ! F_21 ( V_2 -> V_35 ) ) {
V_51 = V_2 -> V_53 ;
} else {
V_50 = V_2 -> V_53 ;
if ( V_2 -> V_35 == V_54 )
V_51 = 5 + ( ( V_50 & 1 ) ^
( V_50 == 0 || V_50 >= 40 ) ) ;
else
V_51 = 11 * ( V_2 -> V_35 >> 1 ) + ( V_50 == 0 ) ;
if ( ++ V_50 >= ( 80 >> ( V_2 -> V_35 >> 1 ) ) )
V_50 = 0 ;
V_2 -> V_53 = V_50 ;
}
}
return V_51 ;
}
static unsigned int F_22 ( struct V_1 * V_2 ,
unsigned int V_55 )
{
unsigned int V_56 , V_50 , V_57 , V_49 ;
if ( V_2 -> V_58 < V_41 ) {
if ( ! F_21 ( V_2 -> V_35 ) )
V_56 = V_2 -> V_58 + V_2 -> V_59 ;
else {
V_50 = V_2 -> V_59 ;
V_57 = V_50 % 13 ;
V_56 = V_2 -> V_58 ;
V_56 += 1386 + ( ( V_57 && ! ( V_57 & 3 ) ) ||
V_50 == 146 ) ;
if ( ++ V_50 >= 147 )
V_50 = 0 ;
V_2 -> V_59 = V_50 ;
}
} else
V_56 = V_2 -> V_58 - V_41 ;
V_2 -> V_58 = V_56 ;
if ( V_56 < V_41 ) {
V_56 += V_2 -> V_39 ;
V_49 = ( V_55 + V_56 / V_41 ) << 12 ;
V_49 += V_56 % V_41 ;
return V_49 & V_60 ;
} else {
return V_52 ;
}
}
static void F_23 ( struct V_1 * V_2 ,
struct V_61 * V_62 ,
unsigned int V_63 )
{
unsigned int V_64 ;
V_64 = V_2 -> V_47 + V_63 ;
if ( V_64 >= V_62 -> V_25 -> V_65 )
V_64 -= V_62 -> V_25 -> V_65 ;
F_24 ( V_2 -> V_47 ) = V_64 ;
V_2 -> V_48 += V_63 ;
if ( V_2 -> V_48 >= V_62 -> V_25 -> V_66 ) {
V_2 -> V_48 -= V_62 -> V_25 -> V_66 ;
F_25 ( & V_2 -> V_19 ) ;
}
}
static void V_20 ( unsigned long V_67 )
{
struct V_1 * V_2 = ( void * ) V_67 ;
struct V_61 * V_62 = F_24 ( V_2 -> V_62 ) ;
if ( V_62 )
F_26 ( V_62 ) ;
}
static int F_27 ( struct V_1 * V_2 , unsigned int V_68 ,
unsigned int V_69 )
{
struct V_70 V_71 = { 0 } ;
int V_26 = 0 ;
if ( F_28 ( V_2 -> V_17 ) )
goto V_29;
V_71 . V_72 = F_29 ( V_2 -> V_21 + 1 , V_73 ) ;
V_71 . V_74 = V_2 -> V_74 ;
V_71 . V_68 = V_68 ;
if ( V_69 > 0 )
V_71 . V_69 = V_69 ;
else
V_71 . V_75 = true ;
V_26 = F_30 ( V_2 -> V_17 , & V_71 , & V_2 -> V_76 . V_77 ,
V_2 -> V_76 . V_78 [ V_2 -> V_21 ] . V_79 ) ;
if ( V_26 < 0 ) {
F_31 ( & V_2 -> V_4 -> V_80 , L_1 , V_26 ) ;
goto V_29;
}
if ( ++ V_2 -> V_21 >= V_81 )
V_2 -> V_21 = 0 ;
V_29:
return V_26 ;
}
static inline int F_32 ( struct V_1 * V_2 ,
unsigned int V_69 )
{
return F_27 ( V_2 , V_82 , V_69 ) ;
}
static inline int F_33 ( struct V_1 * V_2 )
{
return F_27 ( V_2 , V_83 , V_2 -> V_84 ) ;
}
static int F_34 ( struct V_1 * V_2 ,
unsigned int V_69 , unsigned int V_55 ,
unsigned int V_57 )
{
T_2 * V_76 ;
unsigned int V_49 ;
unsigned int V_51 ;
unsigned int V_85 ;
struct V_61 * V_62 ;
V_76 = V_2 -> V_76 . V_78 [ V_2 -> V_21 ] . V_76 ;
V_49 = F_22 ( V_2 , V_55 ) ;
V_51 = F_20 ( V_2 , V_49 ) ;
V_85 = V_2 -> V_10 ( V_2 , V_76 + 2 , V_51 , & V_49 ) ;
if ( V_2 -> V_8 & V_86 )
V_2 -> V_87 =
( V_2 -> V_87 + V_51 ) & 0xff ;
V_76 [ 0 ] = F_35 ( F_24 ( V_2 -> V_88 ) |
( V_2 -> V_34 << V_89 ) |
( ( V_2 -> V_90 << V_91 ) & V_92 ) |
V_2 -> V_87 ) ;
V_76 [ 1 ] = F_35 ( V_93 |
( ( V_2 -> V_9 << V_94 ) & V_95 ) |
( ( V_2 -> V_96 << V_97 ) & V_98 ) |
( V_49 & V_60 ) ) ;
if ( ! ( V_2 -> V_8 & V_86 ) )
V_2 -> V_87 =
( V_2 -> V_87 + V_51 ) & 0xff ;
V_69 = 8 + V_51 * 4 * V_2 -> V_34 ;
F_36 ( V_2 , V_55 , V_76 , V_69 , V_57 ) ;
if ( F_32 ( V_2 , V_69 ) < 0 )
return - V_99 ;
V_62 = F_24 ( V_2 -> V_62 ) ;
if ( V_62 && V_85 > 0 )
F_23 ( V_2 , V_62 , V_85 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
unsigned int V_69 , unsigned int V_55 ,
unsigned int V_57 )
{
T_2 * V_76 ;
unsigned int V_49 ;
unsigned int V_51 ;
unsigned int V_85 ;
struct V_61 * V_62 ;
V_76 = V_2 -> V_76 . V_78 [ V_2 -> V_21 ] . V_76 ;
V_49 = F_22 ( V_2 , V_55 ) ;
V_51 = F_20 ( V_2 , V_49 ) ;
V_85 = V_2 -> V_10 ( V_2 , V_76 , V_51 , & V_49 ) ;
V_2 -> V_87 = ( V_2 -> V_87 + V_51 ) & 0xff ;
V_69 = V_51 * 4 * V_2 -> V_34 ;
F_38 ( V_2 , V_55 , V_69 , V_51 ,
V_57 ) ;
if ( F_32 ( V_2 , V_69 ) < 0 )
return - V_99 ;
V_62 = F_24 ( V_2 -> V_62 ) ;
if ( V_62 && V_85 > 0 )
F_23 ( V_2 , V_62 , V_85 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
unsigned int V_69 , unsigned int V_55 ,
unsigned int V_57 )
{
T_2 * V_76 ;
T_3 V_100 [ 2 ] ;
unsigned int V_90 , V_9 , V_96 , V_49 ;
unsigned int V_34 , V_87 , V_101 ;
unsigned int V_51 ;
struct V_61 * V_62 ;
unsigned int V_85 ;
bool V_102 ;
V_76 = V_2 -> V_76 . V_78 [ V_2 -> V_21 ] . V_76 ;
V_100 [ 0 ] = F_40 ( V_76 [ 0 ] ) ;
V_100 [ 1 ] = F_40 ( V_76 [ 1 ] ) ;
F_41 ( V_2 , V_55 , V_100 , V_69 , V_57 ) ;
if ( ( ( ( V_100 [ 0 ] & V_103 ) == V_93 ) ||
( ( V_100 [ 1 ] & V_103 ) != V_93 ) ) &&
( ! ( V_2 -> V_8 & V_104 ) ) ) {
F_42 ( & V_2 -> V_4 -> V_80 ,
L_2 ,
V_100 [ 0 ] , V_100 [ 1 ] ) ;
V_51 = 0 ;
V_85 = 0 ;
goto V_29;
}
V_90 = ( V_100 [ 0 ] & V_92 ) >> V_91 ;
V_9 = ( V_100 [ 1 ] & V_95 ) >> V_94 ;
if ( V_90 != V_2 -> V_90 || V_9 != V_2 -> V_9 ) {
F_42 ( & V_2 -> V_4 -> V_80 ,
L_3 ,
V_100 [ 0 ] , V_100 [ 1 ] ) ;
V_51 = 0 ;
V_85 = 0 ;
goto V_29;
}
V_96 = ( V_100 [ 1 ] & V_98 ) >> V_97 ;
if ( V_69 < 12 ||
( V_9 == V_105 && V_96 == V_106 ) ) {
V_51 = 0 ;
} else {
V_34 =
( V_100 [ 0 ] & V_107 ) >> V_89 ;
if ( V_34 == 0 ) {
F_31 ( & V_2 -> V_4 -> V_80 ,
L_4 ,
V_100 [ 0 ] ) ;
return - V_108 ;
}
if ( V_2 -> V_8 & V_109 )
V_34 = V_2 -> V_34 ;
V_51 = ( V_69 / 4 - 2 ) /
V_34 ;
}
V_87 = V_100 [ 0 ] & V_110 ;
if ( V_51 == 0 && ( V_2 -> V_8 & V_111 ) &&
V_2 -> V_87 != V_28 )
V_87 = V_2 -> V_87 ;
if ( ( ( V_2 -> V_8 & V_112 ) &&
V_87 == V_2 -> V_113 ) ||
V_2 -> V_87 == V_28 ) {
V_102 = false ;
} else if ( ! ( V_2 -> V_8 & V_86 ) ) {
V_102 = V_87 != V_2 -> V_87 ;
} else {
if ( V_51 > 0 && V_2 -> V_114 > 0 )
V_101 = V_2 -> V_114 ;
else
V_101 = V_51 ;
V_102 = V_87 !=
( ( V_2 -> V_87 + V_101 ) & 0xff ) ;
}
if ( V_102 ) {
F_31 ( & V_2 -> V_4 -> V_80 ,
L_5 ,
V_2 -> V_87 , V_87 ) ;
return - V_99 ;
}
V_49 = F_40 ( V_76 [ 1 ] ) & V_60 ;
V_85 = V_2 -> V_10 ( V_2 , V_76 + 2 , V_51 , & V_49 ) ;
if ( V_2 -> V_8 & V_86 )
V_2 -> V_87 = V_87 ;
else
V_2 -> V_87 =
( V_87 + V_51 ) & 0xff ;
V_29:
if ( F_33 ( V_2 ) < 0 )
return - V_99 ;
V_62 = F_24 ( V_2 -> V_62 ) ;
if ( V_62 && V_85 > 0 )
F_23 ( V_2 , V_62 , V_85 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
unsigned int V_115 , unsigned int V_55 ,
unsigned int V_57 )
{
T_2 * V_76 ;
unsigned int V_51 ;
struct V_61 * V_62 ;
unsigned int V_85 ;
V_76 = V_2 -> V_76 . V_78 [ V_2 -> V_21 ] . V_76 ;
V_51 = V_115 / V_2 -> V_34 ;
F_44 ( V_2 , V_55 , V_115 , V_51 ,
V_57 ) ;
V_85 = V_2 -> V_10 ( V_2 , V_76 , V_51 , NULL ) ;
V_2 -> V_87 = ( V_2 -> V_87 + V_51 ) & 0xff ;
if ( F_33 ( V_2 ) < 0 )
return - V_99 ;
V_62 = F_24 ( V_2 -> V_62 ) ;
if ( V_62 && V_85 > 0 )
F_23 ( V_2 , V_62 , V_85 ) ;
return 0 ;
}
static inline T_3 F_45 ( T_3 V_116 )
{
return ( ( ( V_116 >> 13 ) & 0x07 ) * 8000 ) + ( V_116 & 0x1fff ) ;
}
static inline T_3 F_46 ( T_3 V_55 , unsigned int V_117 )
{
V_55 += V_117 ;
if ( V_55 >= 8 * V_118 )
V_55 -= 8 * V_118 ;
return V_55 ;
}
static inline T_3 F_47 ( T_3 V_55 , unsigned int V_119 )
{
if ( V_55 < V_119 )
V_55 += 8 * V_118 ;
return V_55 - V_119 ;
}
static void F_48 ( struct V_120 * V_17 , T_3 V_116 ,
T_4 V_68 , void * V_121 ,
void * V_122 )
{
struct V_1 * V_2 = V_122 ;
unsigned int V_123 , V_78 = V_68 / 4 ;
T_3 V_55 ;
if ( V_2 -> V_21 < 0 )
return;
V_55 = F_45 ( V_116 ) ;
V_55 = F_46 ( V_55 , V_81 - V_78 ) ;
for ( V_123 = 0 ; V_123 < V_78 ; ++ V_123 ) {
V_55 = F_46 ( V_55 , 1 ) ;
if ( V_2 -> V_124 ( V_2 , 0 , V_55 , V_123 ) < 0 ) {
V_2 -> V_21 = - 1 ;
if ( F_49 () )
F_50 ( V_2 ) ;
F_51 ( V_2 -> V_47 , V_125 ) ;
return;
}
}
F_52 ( V_2 -> V_17 ) ;
}
static void F_53 ( struct V_120 * V_17 , T_3 V_116 ,
T_4 V_68 , void * V_121 ,
void * V_122 )
{
struct V_1 * V_2 = V_122 ;
unsigned int V_123 , V_78 ;
unsigned int V_69 , V_84 ;
T_2 * V_126 = V_121 ;
T_3 V_55 ;
if ( V_2 -> V_21 < 0 )
return;
V_78 = V_68 / V_83 ;
V_55 = F_45 ( V_116 ) ;
V_55 = F_47 ( V_55 , V_78 ) ;
V_84 = V_2 -> V_84 ;
for ( V_123 = 0 ; V_123 < V_78 ; V_123 ++ ) {
V_55 = F_46 ( V_55 , 1 ) ;
V_69 =
( F_40 ( V_126 [ V_123 ] ) >> V_127 ) ;
if ( V_69 > V_84 ) {
F_31 ( & V_2 -> V_4 -> V_80 ,
L_6 ,
V_69 , V_84 ) ;
break;
}
if ( V_2 -> V_124 ( V_2 , V_69 , V_55 , V_123 ) < 0 )
break;
}
if ( V_123 < V_78 ) {
V_2 -> V_21 = - 1 ;
if ( F_49 () )
F_50 ( V_2 ) ;
F_51 ( V_2 -> V_47 , V_125 ) ;
return;
}
F_52 ( V_2 -> V_17 ) ;
}
static void F_54 ( struct V_120 * V_17 ,
T_3 V_116 , T_4 V_68 ,
void * V_121 , void * V_122 )
{
struct V_1 * V_2 = V_122 ;
T_3 V_55 ;
unsigned int V_78 ;
V_2 -> V_84 = F_17 ( V_2 ) ;
V_2 -> V_23 = true ;
F_55 ( & V_2 -> V_22 ) ;
V_55 = F_45 ( V_116 ) ;
if ( V_2 -> V_16 == V_128 ) {
V_78 = V_68 / V_83 ;
V_55 = F_47 ( V_55 , V_78 ) ;
V_17 -> V_129 . V_130 = F_53 ;
if ( V_2 -> V_8 & V_46 )
V_2 -> V_124 = F_43 ;
else
V_2 -> V_124 = F_39 ;
} else {
V_78 = V_68 / 4 ;
V_55 = F_46 ( V_55 , V_81 - V_78 ) ;
V_17 -> V_129 . V_130 = F_48 ;
if ( V_2 -> V_8 & V_46 )
V_2 -> V_124 = F_37 ;
else
V_2 -> V_124 = F_34 ;
}
V_2 -> V_131 = V_55 ;
V_17 -> V_129 . V_130 ( V_17 , V_116 , V_68 , V_121 , V_2 ) ;
}
int F_56 ( struct V_1 * V_2 , int V_132 , int V_133 )
{
static const struct {
unsigned int V_134 ;
unsigned int V_56 ;
} V_135 [] = {
[ V_136 ] = { 4 , 3072 } ,
[ V_137 ] = { 6 , 1024 } ,
[ V_138 ] = { 12 , 1024 } ,
[ V_139 ] = { 24 , 1024 } ,
[ V_54 ] = { 0 , 67 } ,
[ V_140 ] = { 0 , 67 } ,
[ V_141 ] = { 0 , 67 } ,
} ;
unsigned int V_44 ;
enum V_142 V_6 ;
int type , V_74 , V_26 ;
F_57 ( & V_2 -> V_18 ) ;
if ( F_8 ( F_9 ( V_2 ) ||
( V_2 -> V_34 < 1 ) ) ) {
V_26 = - V_143 ;
goto V_144;
}
if ( V_2 -> V_16 == V_128 )
V_2 -> V_87 = V_28 ;
else
V_2 -> V_87 = 0 ;
V_2 -> V_53 = V_135 [ V_2 -> V_35 ] . V_134 ;
V_2 -> V_59 = V_135 [ V_2 -> V_35 ] . V_56 ;
V_2 -> V_58 = V_41 ;
if ( V_2 -> V_16 == V_128 ) {
V_6 = V_145 ;
type = V_146 ;
V_44 = V_83 ;
} else {
V_6 = V_147 ;
type = V_148 ;
V_44 = V_82 ;
}
V_26 = F_58 ( & V_2 -> V_76 , V_2 -> V_4 , V_81 ,
F_17 ( V_2 ) , V_6 ) ;
if ( V_26 < 0 )
goto V_144;
V_2 -> V_17 = F_59 ( F_60 ( V_2 -> V_4 ) -> V_149 ,
type , V_132 , V_133 , V_44 ,
F_54 , V_2 ) ;
if ( F_28 ( V_2 -> V_17 ) ) {
V_26 = F_61 ( V_2 -> V_17 ) ;
if ( V_26 == - V_150 )
F_31 ( & V_2 -> V_4 -> V_80 ,
L_7 ) ;
goto V_151;
}
F_62 ( V_2 ) ;
if ( V_2 -> V_8 & V_46 )
V_2 -> V_74 = V_152 ;
else
V_2 -> V_74 = V_153 ;
V_2 -> V_21 = 0 ;
do {
if ( V_2 -> V_16 == V_128 )
V_26 = F_33 ( V_2 ) ;
else
V_26 = F_32 ( V_2 , 0 ) ;
if ( V_26 < 0 )
goto V_154;
} while ( V_2 -> V_21 > 0 );
V_74 = V_155 ;
if ( ( V_2 -> V_8 & V_156 ) || ( V_2 -> V_8 & V_46 ) )
V_74 |= V_157 ;
V_2 -> V_23 = false ;
V_26 = F_63 ( V_2 -> V_17 , - 1 , 0 , V_74 ) ;
if ( V_26 < 0 )
goto V_154;
F_64 ( & V_2 -> V_18 ) ;
return 0 ;
V_154:
F_65 ( V_2 -> V_17 ) ;
V_2 -> V_17 = F_3 ( - 1 ) ;
V_151:
F_66 ( & V_2 -> V_76 , V_2 -> V_4 ) ;
V_144:
F_64 ( & V_2 -> V_18 ) ;
return V_26 ;
}
unsigned long F_67 ( struct V_1 * V_2 )
{
if ( ! F_49 () && F_9 ( V_2 ) )
F_68 ( V_2 -> V_17 ) ;
return F_24 ( V_2 -> V_47 ) ;
}
void F_62 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_88 ) =
( F_60 ( V_2 -> V_4 ) -> V_149 -> V_158 << V_159 ) &
V_160 ;
}
void F_69 ( struct V_1 * V_2 )
{
F_57 ( & V_2 -> V_18 ) ;
if ( ! F_9 ( V_2 ) ) {
F_64 ( & V_2 -> V_18 ) ;
return;
}
F_19 ( & V_2 -> V_19 ) ;
F_70 ( V_2 -> V_17 ) ;
F_65 ( V_2 -> V_17 ) ;
V_2 -> V_17 = F_3 ( - 1 ) ;
F_66 ( & V_2 -> V_76 , V_2 -> V_4 ) ;
V_2 -> V_23 = false ;
F_64 ( & V_2 -> V_18 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
struct V_61 * V_62 ;
V_62 = F_24 ( V_2 -> V_62 ) ;
if ( V_62 )
F_71 ( V_62 ) ;
}
