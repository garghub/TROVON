static inline bool F_1 ( void ) { return false ; }
void F_2 ( struct V_1 * V_2 ,
const T_1 * V_3 ,
const T_1 V_4 )
{
T_1 V_5 , V_6 , V_7 , V_8 ;
int V_9 ;
if ( V_4 % 3 )
return;
for ( V_9 = 0 ; V_9 < V_4 ; V_9 += 3 ) {
V_6 = V_3 [ V_9 + 0 ] ;
V_7 = V_3 [ V_9 + 1 ] ;
V_8 = V_3 [ V_9 + 2 ] ;
if ( V_7 == 0xffffffff ) {
V_5 = V_8 ;
} else {
V_5 = F_3 ( V_6 ) ;
V_5 &= ~ V_7 ;
V_5 |= V_8 ;
}
F_4 ( V_6 , V_5 ) ;
}
}
void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_10 , 0x7c , V_11 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 < V_13 ) {
int V_9 ;
for ( V_9 = 0 ; V_9 < V_14 ; V_9 ++ ) {
if ( V_2 -> V_15 [ V_9 ] . V_16 )
F_8 ( V_2 -> V_15 [ V_9 ] . V_16 ) ;
else
F_9 ( V_2 , V_9 ) ;
}
F_4 ( V_17 , 0 ) ;
}
}
void F_10 ( struct V_1 * V_2 )
{
int V_9 ;
if ( V_2 -> V_12 < V_18 ) {
V_2 -> V_19 . V_20 = 5 ;
} else {
V_2 -> V_19 . V_20 = 7 ;
}
V_2 -> V_19 . V_21 = V_22 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_19 . V_20 ; V_9 ++ ) {
V_2 -> V_19 . free [ V_9 ] = true ;
V_2 -> V_19 . V_6 [ V_9 ] = V_2 -> V_19 . V_21 + ( V_9 * 4 ) ;
}
}
int F_11 ( struct V_1 * V_2 , T_2 * V_6 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_19 . V_20 ; V_9 ++ ) {
if ( V_2 -> V_19 . free [ V_9 ] ) {
V_2 -> V_19 . free [ V_9 ] = false ;
* V_6 = V_2 -> V_19 . V_6 [ V_9 ] ;
return 0 ;
}
}
return - V_23 ;
}
void F_12 ( struct V_1 * V_2 , T_2 V_6 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_19 . V_20 ; V_9 ++ ) {
if ( V_2 -> V_19 . V_6 [ V_9 ] == V_6 ) {
V_2 -> V_19 . free [ V_9 ] = true ;
return;
}
}
}
static int F_13 ( struct V_1 * V_2 )
{
V_2 -> V_24 . V_25 = F_14 ( V_2 -> V_10 , 2 ) ;
V_2 -> V_24 . V_26 = F_15 ( V_2 -> V_10 , 2 ) ;
V_2 -> V_24 . V_27 = F_16 ( T_1 , V_2 -> V_24 . V_26 / sizeof( T_1 ) , V_28 ) ;
if ( V_2 -> V_24 . V_27 == 0 )
return - V_23 ;
V_2 -> V_24 . V_29 = F_17 ( V_2 -> V_24 . V_25 , V_2 -> V_24 . V_27 * sizeof( T_1 ) ) ;
if ( V_2 -> V_24 . V_29 == NULL ) {
return - V_30 ;
}
F_18 ( L_1 , ( T_2 ) V_2 -> V_24 . V_25 ) ;
F_18 ( L_2 , ( unsigned ) V_2 -> V_24 . V_26 ) ;
memset ( & V_2 -> V_24 . V_31 , 0 , sizeof( V_2 -> V_24 . V_31 ) ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_20 ( V_2 -> V_24 . V_29 ) ;
V_2 -> V_24 . V_29 = NULL ;
}
int F_21 ( struct V_1 * V_2 , T_1 * V_24 )
{
unsigned long V_32 = F_22 ( V_2 -> V_24 . V_31 , V_2 -> V_24 . V_27 ) ;
if ( V_32 < V_2 -> V_24 . V_27 ) {
F_23 ( V_32 , V_2 -> V_24 . V_31 ) ;
* V_24 = V_32 ;
return 0 ;
} else {
return - V_23 ;
}
}
void F_24 ( struct V_1 * V_2 , T_1 V_24 )
{
if ( V_24 < V_2 -> V_24 . V_27 )
F_25 ( V_24 , V_2 -> V_24 . V_31 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
V_2 -> V_33 . V_34 = false ;
}
void F_27 ( struct V_1 * V_2 )
{
F_26 ( V_2 ) ;
if ( V_2 -> V_33 . V_35 ) {
if ( ! F_28 ( V_2 -> V_33 . V_35 , false ) ) {
F_29 ( V_2 -> V_33 . V_35 ) ;
F_30 ( V_2 -> V_33 . V_35 ) ;
F_31 ( V_2 -> V_33 . V_35 ) ;
}
F_32 ( & V_2 -> V_33 . V_35 ) ;
V_2 -> V_33 . V_33 = NULL ;
V_2 -> V_33 . V_35 = NULL ;
}
}
int F_33 ( struct V_1 * V_2 )
{
int V_36 ;
if ( V_2 -> V_33 . V_35 == NULL ) {
V_36 = F_34 ( V_2 , V_37 , V_38 , true ,
V_39 , NULL , & V_2 -> V_33 . V_35 ) ;
if ( V_36 ) {
F_35 ( V_2 -> V_40 , L_3 , V_36 ) ;
return V_36 ;
}
V_36 = F_28 ( V_2 -> V_33 . V_35 , false ) ;
if ( F_36 ( V_36 != 0 ) ) {
F_27 ( V_2 ) ;
return V_36 ;
}
V_36 = F_37 ( V_2 -> V_33 . V_35 , V_39 ,
& V_2 -> V_33 . V_41 ) ;
if ( V_36 ) {
F_31 ( V_2 -> V_33 . V_35 ) ;
F_35 ( V_2 -> V_40 , L_4 , V_36 ) ;
F_27 ( V_2 ) ;
return V_36 ;
}
V_36 = F_38 ( V_2 -> V_33 . V_35 , ( void * * ) & V_2 -> V_33 . V_33 ) ;
F_31 ( V_2 -> V_33 . V_35 ) ;
if ( V_36 ) {
F_35 ( V_2 -> V_40 , L_5 , V_36 ) ;
F_27 ( V_2 ) ;
return V_36 ;
}
}
memset ( ( char * ) V_2 -> V_33 . V_33 , 0 , V_37 ) ;
V_2 -> V_33 . V_42 = false ;
if ( V_43 == 1 ) {
V_2 -> V_33 . V_34 = false ;
} else {
if ( V_2 -> V_44 & V_45 ) {
V_2 -> V_33 . V_34 = false ;
} else if ( V_2 -> V_12 < V_18 ) {
V_2 -> V_33 . V_34 = false ;
} else {
V_2 -> V_33 . V_34 = true ;
if ( V_2 -> V_12 >= V_13 ) {
V_2 -> V_33 . V_42 = true ;
}
}
}
if ( V_2 -> V_12 >= V_46 ) {
V_2 -> V_33 . V_34 = true ;
V_2 -> V_33 . V_42 = true ;
}
F_39 ( V_2 -> V_40 , L_6 , V_2 -> V_33 . V_34 ? L_7 : L_8 ) ;
return 0 ;
}
void F_40 ( struct V_1 * V_2 , struct V_47 * V_48 , T_3 V_25 )
{
T_4 V_49 = ( T_4 ) V_50 << 20 ;
V_48 -> V_51 = V_25 ;
if ( V_48 -> V_52 > ( V_2 -> V_48 . V_53 - V_25 + 1 ) ) {
F_35 ( V_2 -> V_40 , L_9 ) ;
V_48 -> V_54 = V_48 -> V_55 ;
V_48 -> V_52 = V_48 -> V_55 ;
}
V_48 -> V_56 = V_48 -> V_51 + V_48 -> V_52 - 1 ;
if ( V_2 -> V_44 & V_45 && V_48 -> V_56 > V_48 -> V_57 && V_48 -> V_51 <= V_48 -> V_58 ) {
F_35 ( V_2 -> V_40 , L_9 ) ;
V_48 -> V_54 = V_48 -> V_55 ;
V_48 -> V_52 = V_48 -> V_55 ;
}
V_48 -> V_56 = V_48 -> V_51 + V_48 -> V_52 - 1 ;
if ( V_49 && V_49 < V_48 -> V_54 )
V_48 -> V_54 = V_49 ;
F_39 ( V_2 -> V_40 , L_10 ,
V_48 -> V_52 >> 20 , V_48 -> V_51 ,
V_48 -> V_56 , V_48 -> V_54 >> 20 ) ;
}
void F_41 ( struct V_1 * V_2 , struct V_47 * V_48 )
{
T_3 V_59 , V_60 ;
V_59 = ( ( V_2 -> V_48 . V_53 - V_48 -> V_56 ) + V_48 -> V_61 ) & ~ V_48 -> V_61 ;
V_60 = V_48 -> V_51 & ~ V_48 -> V_61 ;
if ( V_60 > V_59 ) {
if ( V_48 -> V_62 > V_60 ) {
F_35 ( V_2 -> V_40 , L_11 ) ;
V_48 -> V_62 = V_60 ;
}
V_48 -> V_57 = ( V_48 -> V_51 & ~ V_48 -> V_61 ) - V_48 -> V_62 ;
} else {
if ( V_48 -> V_62 > V_59 ) {
F_35 ( V_2 -> V_40 , L_11 ) ;
V_48 -> V_62 = V_59 ;
}
V_48 -> V_57 = ( V_48 -> V_56 + 1 + V_48 -> V_61 ) & ~ V_48 -> V_61 ;
}
V_48 -> V_58 = V_48 -> V_57 + V_48 -> V_62 - 1 ;
F_39 ( V_2 -> V_40 , L_12 ,
V_48 -> V_62 >> 20 , V_48 -> V_57 , V_48 -> V_58 ) ;
}
bool F_42 ( struct V_1 * V_2 )
{
T_2 V_6 ;
if ( F_43 ( V_63 ) &&
( V_2 -> V_10 -> V_64 == V_65 ) &&
( V_2 -> V_12 < V_13 ) )
return false ;
if ( F_44 ( V_2 ) )
goto V_66;
if ( F_45 ( V_2 ) ) {
V_6 = F_3 ( V_67 + V_68 ) |
F_3 ( V_67 + V_69 ) ;
if ( V_2 -> V_70 >= 4 ) {
V_6 |= F_3 ( V_67 + V_71 ) |
F_3 ( V_67 + V_72 ) ;
}
if ( V_2 -> V_70 >= 6 ) {
V_6 |= F_3 ( V_67 + V_73 ) |
F_3 ( V_67 + V_74 ) ;
}
if ( V_6 & V_75 )
return true ;
} else if ( F_46 ( V_2 ) ) {
V_6 = F_3 ( V_76 ) |
F_3 ( V_77 ) ;
if ( V_6 & V_78 ) {
return true ;
}
} else {
V_6 = F_3 ( V_79 ) |
F_3 ( V_80 ) ;
if ( V_6 & V_81 ) {
return true ;
}
}
V_66:
if ( V_2 -> V_12 >= V_13 )
V_6 = F_3 ( V_82 ) ;
else
V_6 = F_3 ( V_83 ) ;
if ( V_6 )
return true ;
return false ;
}
void F_47 ( struct V_1 * V_2 )
{
T_5 V_84 ;
T_1 V_85 = V_2 -> V_86 . V_87 ;
T_1 V_88 = V_2 -> V_86 . V_89 ;
V_84 . V_90 = F_48 ( 100 ) ;
V_2 -> V_86 . V_85 . V_90 = F_48 ( V_85 ) ;
V_2 -> V_86 . V_85 . V_90 = F_49 ( V_2 -> V_86 . V_85 , V_84 ) ;
V_2 -> V_86 . V_88 . V_90 = F_48 ( V_88 ) ;
V_2 -> V_86 . V_88 . V_90 = F_49 ( V_2 -> V_86 . V_88 , V_84 ) ;
if ( V_2 -> V_44 & V_91 ) {
V_84 . V_90 = F_48 ( 16 ) ;
V_2 -> V_86 . V_92 . V_90 = F_49 ( V_2 -> V_86 . V_85 , V_84 ) ;
}
}
bool F_50 ( struct V_1 * V_2 )
{
if ( F_42 ( V_2 ) )
return true ;
if ( V_2 -> V_93 ) {
F_18 ( L_13 ) ;
if ( V_2 -> V_94 )
F_51 ( V_2 -> V_95 . V_96 ) ;
else
F_52 ( V_2 -> V_97 ) ;
return true ;
} else {
F_53 ( V_2 -> V_40 , L_14 ) ;
return false ;
}
}
int F_54 ( struct V_1 * V_2 )
{
if ( V_2 -> V_98 . V_99 )
return 0 ;
V_2 -> V_98 . V_99 = F_55 ( V_100 | V_101 | V_102 ) ;
if ( V_2 -> V_98 . V_99 == NULL )
return - V_30 ;
V_2 -> V_98 . V_103 = F_56 ( V_2 -> V_10 , V_2 -> V_98 . V_99 ,
0 , V_38 , V_104 ) ;
if ( F_57 ( V_2 -> V_10 , V_2 -> V_98 . V_103 ) ) {
F_53 ( & V_2 -> V_10 -> V_40 , L_15 ) ;
F_58 ( V_2 -> V_98 . V_99 ) ;
V_2 -> V_98 . V_99 = NULL ;
return - V_30 ;
}
return 0 ;
}
void F_59 ( struct V_1 * V_2 )
{
if ( V_2 -> V_98 . V_99 == NULL )
return;
F_60 ( V_2 -> V_10 , V_2 -> V_98 . V_103 ,
V_38 , V_104 ) ;
F_58 ( V_2 -> V_98 . V_99 ) ;
V_2 -> V_98 . V_99 = NULL ;
}
static T_2 F_61 ( struct V_105 * V_106 , T_2 V_6 )
{
struct V_1 * V_2 = V_106 -> V_40 -> V_107 ;
T_2 V_36 ;
V_36 = V_2 -> V_108 ( V_2 , V_6 ) ;
return V_36 ;
}
static void F_62 ( struct V_105 * V_106 , T_2 V_6 , T_2 V_109 )
{
struct V_1 * V_2 = V_106 -> V_40 -> V_107 ;
V_2 -> V_110 ( V_2 , V_6 , V_109 ) ;
}
static T_2 F_63 ( struct V_105 * V_106 , T_2 V_6 )
{
struct V_1 * V_2 = V_106 -> V_40 -> V_107 ;
T_2 V_36 ;
V_36 = V_2 -> V_111 ( V_2 , V_6 ) ;
return V_36 ;
}
static void F_64 ( struct V_105 * V_106 , T_2 V_6 , T_2 V_109 )
{
struct V_1 * V_2 = V_106 -> V_40 -> V_107 ;
V_2 -> V_112 ( V_2 , V_6 , V_109 ) ;
}
static void F_65 ( struct V_105 * V_106 , T_2 V_6 , T_2 V_109 )
{
struct V_1 * V_2 = V_106 -> V_40 -> V_107 ;
F_4 ( V_6 * 4 , V_109 ) ;
}
static T_2 F_66 ( struct V_105 * V_106 , T_2 V_6 )
{
struct V_1 * V_2 = V_106 -> V_40 -> V_107 ;
T_2 V_36 ;
V_36 = F_3 ( V_6 * 4 ) ;
return V_36 ;
}
static void F_67 ( struct V_105 * V_106 , T_2 V_6 , T_2 V_109 )
{
struct V_1 * V_2 = V_106 -> V_40 -> V_107 ;
F_68 ( V_6 * 4 , V_109 ) ;
}
static T_2 F_69 ( struct V_105 * V_106 , T_2 V_6 )
{
struct V_1 * V_2 = V_106 -> V_40 -> V_107 ;
T_2 V_36 ;
V_36 = F_70 ( V_6 * 4 ) ;
return V_36 ;
}
int F_71 ( struct V_1 * V_2 )
{
struct V_105 * V_113 =
F_72 ( sizeof( struct V_105 ) , V_101 ) ;
if ( ! V_113 )
return - V_30 ;
V_2 -> V_95 . V_113 = V_113 ;
V_113 -> V_40 = V_2 -> V_97 ;
V_113 -> V_114 = F_66 ;
V_113 -> V_115 = F_65 ;
if ( V_2 -> V_116 ) {
V_113 -> V_117 = F_69 ;
V_113 -> V_118 = F_67 ;
} else {
F_73 ( L_16 ) ;
V_113 -> V_117 = F_66 ;
V_113 -> V_118 = F_65 ;
}
V_113 -> V_119 = F_63 ;
V_113 -> V_120 = F_64 ;
V_113 -> V_121 = F_61 ;
V_113 -> V_122 = F_62 ;
V_2 -> V_95 . V_96 = F_74 ( V_113 , V_2 -> V_93 ) ;
if ( ! V_2 -> V_95 . V_96 ) {
F_75 ( V_2 ) ;
return - V_30 ;
}
F_76 ( & V_2 -> V_95 . V_96 -> V_123 ) ;
F_77 ( V_2 -> V_97 ) ;
F_78 ( V_2 -> V_95 . V_96 ) ;
return 0 ;
}
void F_75 ( struct V_1 * V_2 )
{
if ( V_2 -> V_95 . V_96 ) {
F_79 ( V_2 -> V_95 . V_96 -> V_19 ) ;
}
F_79 ( V_2 -> V_95 . V_96 ) ;
V_2 -> V_95 . V_96 = NULL ;
F_79 ( V_2 -> V_95 . V_113 ) ;
V_2 -> V_95 . V_113 = NULL ;
}
int F_80 ( struct V_1 * V_2 )
{
F_81 ( V_2 -> V_97 ) ;
return 0 ;
}
void F_82 ( struct V_1 * V_2 )
{
}
static unsigned int F_83 ( void * V_124 , bool V_125 )
{
struct V_1 * V_2 = V_124 ;
F_84 ( V_2 , V_125 ) ;
if ( V_125 )
return V_126 | V_127 |
V_128 | V_129 ;
else
return V_128 | V_129 ;
}
static bool F_85 ( int V_130 )
{
return ( V_130 & ( V_130 - 1 ) ) == 0 ;
}
static void F_86 ( struct V_1 * V_2 )
{
if ( ! F_85 ( V_50 ) ) {
F_35 ( V_2 -> V_40 , L_17 ,
V_50 ) ;
V_50 = 0 ;
}
if ( V_131 == - 1 ) {
if ( V_2 -> V_12 >= V_132 )
V_131 = 1024 ;
else
V_131 = 512 ;
}
if ( V_131 < 32 ) {
F_35 ( V_2 -> V_40 , L_18 ,
V_131 ) ;
if ( V_2 -> V_12 >= V_132 )
V_131 = 1024 ;
else
V_131 = 512 ;
} else if ( ! F_85 ( V_131 ) ) {
F_35 ( V_2 -> V_40 , L_19 ,
V_131 ) ;
if ( V_2 -> V_12 >= V_132 )
V_131 = 1024 ;
else
V_131 = 512 ;
}
V_2 -> V_48 . V_62 = ( T_4 ) V_131 << 20 ;
switch ( V_133 ) {
case - 1 :
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
F_35 ( V_2 -> V_40 , L_20
L_21 , V_133 ) ;
V_133 = 0 ;
break;
}
}
static bool F_87 ( struct V_134 * V_10 )
{
if ( V_10 -> V_64 == V_65 &&
V_10 -> V_135 == 0x00e2 ) {
F_88 ( V_136 L_22 ) ;
return true ;
}
return false ;
}
static void F_89 ( struct V_134 * V_10 , enum V_137 V_125 )
{
struct V_138 * V_40 = F_90 ( V_10 ) ;
if ( F_1 () && V_125 == V_139 )
return;
if ( V_125 == V_140 ) {
unsigned V_141 = V_40 -> V_10 -> V_141 ;
F_88 ( V_136 L_23 ) ;
V_40 -> V_142 = V_143 ;
if ( V_141 < 20 && F_87 ( V_10 ) )
V_40 -> V_10 -> V_141 = 20 ;
F_91 ( V_40 , true , true ) ;
V_40 -> V_10 -> V_141 = V_141 ;
V_40 -> V_142 = V_144 ;
F_92 ( V_40 ) ;
} else {
F_88 ( V_136 L_24 ) ;
F_93 ( V_40 ) ;
V_40 -> V_142 = V_143 ;
F_94 ( V_40 , true , true ) ;
V_40 -> V_142 = V_145 ;
}
}
static bool F_95 ( struct V_134 * V_10 )
{
struct V_138 * V_40 = F_90 ( V_10 ) ;
bool V_146 ;
F_96 ( & V_40 -> V_147 ) ;
V_146 = ( V_40 -> V_148 == 0 ) ;
F_97 ( & V_40 -> V_147 ) ;
return V_146 ;
}
int F_98 ( struct V_1 * V_2 ,
struct V_138 * V_97 ,
struct V_134 * V_10 ,
T_2 V_44 )
{
int V_36 , V_9 ;
int V_149 ;
bool V_150 = false ;
V_2 -> V_151 = false ;
V_2 -> V_40 = & V_10 -> V_40 ;
V_2 -> V_97 = V_97 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_44 = V_44 ;
V_2 -> V_12 = V_44 & V_152 ;
V_2 -> V_94 = false ;
V_2 -> V_153 = V_154 ;
V_2 -> V_48 . V_62 = 512 * 1024 * 1024 ;
V_2 -> V_155 = false ;
for ( V_9 = 0 ; V_9 < V_156 ; V_9 ++ ) {
V_2 -> V_157 [ V_9 ] . V_158 = V_9 ;
}
F_18 ( L_25 ,
V_159 [ V_2 -> V_12 ] , V_10 -> V_160 , V_10 -> V_161 ,
V_10 -> V_64 , V_10 -> V_135 ) ;
F_76 ( & V_2 -> V_162 ) ;
F_76 ( & V_2 -> V_163 ) ;
F_99 ( & V_2 -> V_164 . V_165 , 0 ) ;
F_76 ( & V_2 -> V_166 . V_123 ) ;
F_76 ( & V_2 -> V_86 . V_123 ) ;
F_76 ( & V_2 -> V_167 ) ;
F_76 ( & V_2 -> V_168 ) ;
F_100 ( & V_2 -> V_86 . V_169 ) ;
F_100 ( & V_2 -> V_170 ) ;
F_101 ( & V_2 -> V_171 . V_172 ) ;
V_36 = F_102 ( V_2 ) ;
if ( V_36 )
return V_36 ;
F_76 ( & V_2 -> V_173 . V_165 ) ;
V_2 -> V_173 . V_174 = 1 << 20 ;
F_103 ( & V_2 -> V_173 . V_175 ) ;
V_36 = F_104 ( V_2 ) ;
if ( V_36 )
return V_36 ;
F_86 ( V_2 ) ;
if ( ( V_2 -> V_12 >= V_176 ) &&
( V_2 -> V_44 & V_91 ) ) {
V_2 -> V_44 &= ~ V_45 ;
}
if ( V_2 -> V_44 & V_45 && V_133 == - 1 ) {
F_105 ( V_2 ) ;
}
if ( V_2 -> V_12 >= V_177 )
V_2 -> V_48 . V_53 = 0xffffffffffULL ;
else if ( V_2 -> V_12 >= V_178 )
V_2 -> V_48 . V_53 = 0xfffffffffULL ;
else
V_2 -> V_48 . V_53 = 0xffffffffULL ;
V_2 -> V_179 = false ;
if ( V_2 -> V_44 & V_45 )
V_2 -> V_179 = true ;
if ( ( V_2 -> V_44 & V_180 ) &&
( V_2 -> V_12 <= V_181 ) )
V_2 -> V_179 = true ;
V_149 = V_2 -> V_179 ? 32 : 40 ;
V_36 = F_106 ( V_2 -> V_10 , F_107 ( V_149 ) ) ;
if ( V_36 ) {
V_2 -> V_179 = true ;
V_149 = 32 ;
F_88 ( V_182 L_26 ) ;
}
V_36 = F_108 ( V_2 -> V_10 , F_107 ( V_149 ) ) ;
if ( V_36 ) {
F_108 ( V_2 -> V_10 , F_107 ( 32 ) ) ;
F_88 ( V_182 L_27 ) ;
}
F_109 ( & V_2 -> V_183 ) ;
F_109 ( & V_2 -> V_184 ) ;
F_109 ( & V_2 -> V_185 ) ;
F_109 ( & V_2 -> V_186 ) ;
F_109 ( & V_2 -> V_187 ) ;
F_109 ( & V_2 -> V_188 ) ;
F_109 ( & V_2 -> V_189 ) ;
F_109 ( & V_2 -> V_190 ) ;
F_109 ( & V_2 -> V_191 ) ;
F_109 ( & V_2 -> V_192 ) ;
F_109 ( & V_2 -> V_193 ) ;
F_109 ( & V_2 -> V_194 ) ;
if ( V_2 -> V_12 >= V_195 ) {
V_2 -> V_196 = F_14 ( V_2 -> V_10 , 5 ) ;
V_2 -> V_197 = F_15 ( V_2 -> V_10 , 5 ) ;
} else {
V_2 -> V_196 = F_14 ( V_2 -> V_10 , 2 ) ;
V_2 -> V_197 = F_15 ( V_2 -> V_10 , 2 ) ;
}
V_2 -> V_198 = F_17 ( V_2 -> V_196 , V_2 -> V_197 ) ;
if ( V_2 -> V_198 == NULL ) {
return - V_30 ;
}
F_18 ( L_28 , ( T_2 ) V_2 -> V_196 ) ;
F_18 ( L_29 , ( unsigned ) V_2 -> V_197 ) ;
if ( V_2 -> V_12 >= V_195 )
F_13 ( V_2 ) ;
for ( V_9 = 0 ; V_9 < V_199 ; V_9 ++ ) {
if ( F_110 ( V_2 -> V_10 , V_9 ) & V_200 ) {
V_2 -> V_201 = F_15 ( V_2 -> V_10 , V_9 ) ;
V_2 -> V_116 = F_111 ( V_2 -> V_10 , V_9 , V_2 -> V_201 ) ;
break;
}
}
if ( V_2 -> V_116 == NULL )
F_73 ( L_30 ) ;
F_112 ( V_2 -> V_10 , V_2 , NULL , F_83 ) ;
if ( V_202 == 1 )
V_150 = true ;
if ( ( V_202 == - 1 ) && F_1 () )
V_150 = true ;
F_113 ( V_2 -> V_10 , & V_203 , V_150 ) ;
if ( V_150 )
F_114 ( V_2 -> V_40 , & V_2 -> V_204 ) ;
V_36 = F_115 ( V_2 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_116 ( V_2 ) ;
if ( V_36 )
F_73 ( L_31 , V_36 ) ;
V_36 = F_117 ( V_2 ) ;
if ( V_36 ) {
F_73 ( L_32 , V_36 ) ;
}
if ( V_2 -> V_44 & V_45 && ! V_2 -> V_155 ) {
F_118 ( V_2 ) ;
F_119 ( V_2 ) ;
F_105 ( V_2 ) ;
V_36 = F_115 ( V_2 ) ;
if ( V_36 )
return V_36 ;
}
if ( ( V_205 & 1 ) ) {
if ( V_2 -> V_155 )
F_120 ( V_2 ) ;
else
F_18 ( L_33 ) ;
}
if ( ( V_205 & 2 ) ) {
if ( V_2 -> V_155 )
F_121 ( V_2 ) ;
else
F_18 ( L_34 ) ;
}
if ( V_206 ) {
if ( V_2 -> V_155 )
F_122 ( V_2 , V_206 ) ;
else
F_18 ( L_35 ) ;
}
return 0 ;
}
void F_123 ( struct V_1 * V_2 )
{
F_18 ( L_36 ) ;
V_2 -> V_151 = true ;
F_124 ( V_2 ) ;
F_119 ( V_2 ) ;
F_125 ( V_2 -> V_10 ) ;
F_112 ( V_2 -> V_10 , NULL , NULL , NULL ) ;
if ( V_2 -> V_116 )
F_126 ( V_2 -> V_10 , V_2 -> V_116 ) ;
V_2 -> V_116 = NULL ;
F_20 ( V_2 -> V_198 ) ;
V_2 -> V_198 = NULL ;
if ( V_2 -> V_12 >= V_195 )
F_19 ( V_2 ) ;
F_127 ( V_2 ) ;
}
int F_94 ( struct V_138 * V_40 , bool V_207 , bool V_208 )
{
struct V_1 * V_2 ;
struct V_209 * V_210 ;
struct V_211 * V_212 ;
int V_9 , V_36 ;
bool V_213 = false ;
if ( V_40 == NULL || V_40 -> V_107 == NULL ) {
return - V_214 ;
}
V_2 = V_40 -> V_107 ;
if ( V_40 -> V_142 == V_145 )
return 0 ;
F_93 ( V_40 ) ;
F_128 (connector, &dev->mode_config.connector_list, head) {
F_129 ( V_212 , V_215 ) ;
}
F_128 (crtc, &dev->mode_config.crtc_list, head) {
struct V_216 * V_217 = F_130 ( V_210 -> V_218 ) ;
struct V_219 * V_220 ;
if ( V_217 == NULL || V_217 -> V_221 == NULL ) {
continue;
}
V_220 = F_131 ( V_217 -> V_221 ) ;
if ( ! F_132 ( V_2 , V_220 ) ) {
V_36 = F_28 ( V_220 , false ) ;
if ( V_36 == 0 ) {
F_30 ( V_220 ) ;
F_31 ( V_220 ) ;
}
}
}
F_124 ( V_2 ) ;
F_133 ( & V_2 -> V_162 ) ;
for ( V_9 = 0 ; V_9 < V_156 ; V_9 ++ ) {
V_36 = F_134 ( V_2 , V_9 ) ;
if ( V_36 ) {
V_213 = true ;
}
}
if ( V_213 ) {
F_135 ( V_2 ) ;
}
F_136 ( & V_2 -> V_162 ) ;
F_137 ( V_2 ) ;
F_138 ( V_2 ) ;
F_139 ( V_2 ) ;
F_124 ( V_2 ) ;
F_140 ( V_2 ) ;
F_141 ( V_40 -> V_10 ) ;
if ( V_207 ) {
F_142 ( V_40 -> V_10 ) ;
F_143 ( V_40 -> V_10 , V_222 ) ;
}
if ( V_208 ) {
F_144 () ;
F_145 ( V_2 , 1 ) ;
F_146 () ;
}
return 0 ;
}
int F_91 ( struct V_138 * V_40 , bool V_223 , bool V_208 )
{
struct V_211 * V_212 ;
struct V_1 * V_2 = V_40 -> V_107 ;
int V_36 ;
if ( V_40 -> V_142 == V_145 )
return 0 ;
if ( V_208 ) {
F_144 () ;
}
if ( V_223 ) {
F_143 ( V_40 -> V_10 , V_224 ) ;
F_147 ( V_40 -> V_10 ) ;
if ( F_148 ( V_40 -> V_10 ) ) {
if ( V_208 )
F_146 () ;
return - 1 ;
}
}
F_149 ( V_2 ) ;
F_150 ( V_2 ) ;
V_36 = F_116 ( V_2 ) ;
if ( V_36 )
F_73 ( L_31 , V_36 ) ;
if ( ( V_2 -> V_86 . V_225 == V_226 ) && V_2 -> V_86 . V_227 ) {
V_36 = F_151 ( V_2 ) ;
if ( V_36 ) {
V_2 -> V_86 . V_227 = false ;
F_73 ( L_37 ) ;
}
} else {
F_152 ( V_2 ) ;
}
F_153 ( V_2 ) ;
if ( V_208 ) {
F_145 ( V_2 , 0 ) ;
F_146 () ;
}
if ( V_2 -> V_94 ) {
F_154 ( V_2 ) ;
F_155 ( V_2 ) ;
if ( V_2 -> V_95 . V_228 ) {
T_6 V_229 = F_156 ( V_2 ,
V_2 -> V_95 . V_228 ) ;
F_157 ( V_2 , V_2 -> V_95 . V_228 ,
V_229 ) ;
}
}
F_158 ( V_2 ) ;
F_159 ( V_40 ) ;
F_128 (connector, &dev->mode_config.connector_list, head) {
F_129 ( V_212 , V_230 ) ;
}
F_92 ( V_40 ) ;
return 0 ;
}
int F_160 ( struct V_1 * V_2 )
{
unsigned V_231 [ V_156 ] ;
T_2 * V_232 [ V_156 ] ;
bool V_233 = false ;
int V_9 , V_36 ;
int V_234 ;
F_161 ( & V_2 -> V_170 ) ;
if ( ! V_2 -> V_235 ) {
F_162 ( & V_2 -> V_170 ) ;
return 0 ;
}
V_2 -> V_235 = false ;
F_137 ( V_2 ) ;
V_234 = F_163 ( & V_2 -> V_236 . V_237 ) ;
F_164 ( V_2 ) ;
F_138 ( V_2 ) ;
for ( V_9 = 0 ; V_9 < V_156 ; ++ V_9 ) {
V_231 [ V_9 ] = F_165 ( V_2 , & V_2 -> V_157 [ V_9 ] ,
& V_232 [ V_9 ] ) ;
if ( V_231 [ V_9 ] ) {
V_233 = true ;
F_39 ( V_2 -> V_40 , L_38
L_39 , V_231 [ V_9 ] , V_9 ) ;
}
}
V_238:
V_36 = F_118 ( V_2 ) ;
if ( ! V_36 ) {
F_39 ( V_2 -> V_40 , L_40 ) ;
F_150 ( V_2 ) ;
}
F_153 ( V_2 ) ;
if ( ! V_36 ) {
for ( V_9 = 0 ; V_9 < V_156 ; ++ V_9 ) {
F_166 ( V_2 , & V_2 -> V_157 [ V_9 ] ,
V_231 [ V_9 ] , V_232 [ V_9 ] ) ;
V_231 [ V_9 ] = 0 ;
V_232 [ V_9 ] = NULL ;
}
V_36 = F_116 ( V_2 ) ;
if ( V_36 ) {
F_53 ( V_2 -> V_40 , L_31 , V_36 ) ;
if ( V_233 ) {
V_233 = false ;
F_138 ( V_2 ) ;
goto V_238;
}
}
} else {
F_135 ( V_2 ) ;
for ( V_9 = 0 ; V_9 < V_156 ; ++ V_9 ) {
F_79 ( V_232 [ V_9 ] ) ;
}
}
F_152 ( V_2 ) ;
F_159 ( V_2 -> V_97 ) ;
F_167 ( & V_2 -> V_236 . V_237 , V_234 ) ;
if ( V_36 ) {
F_39 ( V_2 -> V_40 , L_41 ) ;
}
F_162 ( & V_2 -> V_170 ) ;
return V_36 ;
}
int F_168 ( struct V_1 * V_2 ,
struct V_239 * V_240 ,
unsigned V_241 )
{
unsigned V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_242 ; V_9 ++ ) {
if ( V_2 -> V_243 [ V_9 ] . V_240 == V_240 ) {
return 0 ;
}
}
V_9 = V_2 -> V_242 + 1 ;
if ( V_9 > V_244 ) {
F_73 ( L_42 ) ;
F_73 ( L_43
L_44 ) ;
return - V_23 ;
}
V_2 -> V_243 [ V_2 -> V_242 ] . V_240 = V_240 ;
V_2 -> V_243 [ V_2 -> V_242 ] . V_245 = V_241 ;
V_2 -> V_242 = V_9 ;
#if F_169 ( V_246 )
F_170 ( V_240 , V_241 ,
V_2 -> V_97 -> V_247 -> V_248 ,
V_2 -> V_97 -> V_247 ) ;
F_170 ( V_240 , V_241 ,
V_2 -> V_97 -> V_249 -> V_248 ,
V_2 -> V_97 -> V_249 ) ;
#endif
return 0 ;
}
static void F_127 ( struct V_1 * V_2 )
{
#if F_169 ( V_246 )
unsigned V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_242 ; V_9 ++ ) {
F_171 ( V_2 -> V_243 [ V_9 ] . V_240 ,
V_2 -> V_243 [ V_9 ] . V_245 ,
V_2 -> V_97 -> V_247 ) ;
F_171 ( V_2 -> V_243 [ V_9 ] . V_240 ,
V_2 -> V_243 [ V_9 ] . V_245 ,
V_2 -> V_97 -> V_249 ) ;
}
#endif
}
int F_172 ( struct V_250 * V_251 )
{
return 0 ;
}
void F_173 ( struct V_250 * V_251 )
{
}
