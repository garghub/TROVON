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
if ( V_2 -> V_10 < V_11 ) {
int V_9 ;
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ ) {
if ( V_2 -> V_13 [ V_9 ] . V_14 )
F_6 ( V_2 -> V_13 [ V_9 ] . V_14 ) ;
else
F_7 ( V_2 , V_9 ) ;
}
F_4 ( V_15 , 0 ) ;
}
}
void F_8 ( struct V_1 * V_2 )
{
int V_9 ;
if ( V_2 -> V_10 < V_16 ) {
V_2 -> V_17 . V_18 = 5 ;
} else {
V_2 -> V_17 . V_18 = 7 ;
}
V_2 -> V_17 . V_19 = V_20 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_17 . V_18 ; V_9 ++ ) {
V_2 -> V_17 . free [ V_9 ] = true ;
V_2 -> V_17 . V_6 [ V_9 ] = V_2 -> V_17 . V_19 + ( V_9 * 4 ) ;
}
}
int F_9 ( struct V_1 * V_2 , T_2 * V_6 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_17 . V_18 ; V_9 ++ ) {
if ( V_2 -> V_17 . free [ V_9 ] ) {
V_2 -> V_17 . free [ V_9 ] = false ;
* V_6 = V_2 -> V_17 . V_6 [ V_9 ] ;
return 0 ;
}
}
return - V_21 ;
}
void F_10 ( struct V_1 * V_2 , T_2 V_6 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_17 . V_18 ; V_9 ++ ) {
if ( V_2 -> V_17 . V_6 [ V_9 ] == V_6 ) {
V_2 -> V_17 . free [ V_9 ] = true ;
return;
}
}
}
int F_11 ( struct V_1 * V_2 )
{
V_2 -> V_22 . V_23 = F_12 ( V_2 -> V_24 , 2 ) ;
V_2 -> V_22 . V_25 = F_13 ( V_2 -> V_24 , 2 ) ;
V_2 -> V_22 . V_26 = F_14 ( T_1 , V_2 -> V_22 . V_25 / sizeof( T_1 ) , V_27 ) ;
if ( V_2 -> V_22 . V_26 == 0 )
return - V_21 ;
V_2 -> V_22 . V_28 = F_15 ( V_2 -> V_22 . V_23 , V_2 -> V_22 . V_26 * sizeof( T_1 ) ) ;
if ( V_2 -> V_22 . V_28 == NULL ) {
return - V_29 ;
}
F_16 ( L_1 , ( T_2 ) V_2 -> V_22 . V_23 ) ;
F_16 ( L_2 , ( unsigned ) V_2 -> V_22 . V_25 ) ;
memset ( & V_2 -> V_22 . V_30 , 0 , sizeof( V_2 -> V_22 . V_30 ) ) ;
return 0 ;
}
void F_17 ( struct V_1 * V_2 )
{
F_18 ( V_2 -> V_22 . V_28 ) ;
V_2 -> V_22 . V_28 = NULL ;
}
int F_19 ( struct V_1 * V_2 , T_1 * V_22 )
{
unsigned long V_31 = F_20 ( V_2 -> V_22 . V_30 , V_2 -> V_22 . V_26 ) ;
if ( V_31 < V_2 -> V_22 . V_26 ) {
F_21 ( V_31 , V_2 -> V_22 . V_30 ) ;
* V_22 = V_31 ;
return 0 ;
} else {
return - V_21 ;
}
}
void F_22 ( struct V_1 * V_2 , T_1 V_22 )
{
if ( V_22 < V_2 -> V_22 . V_26 )
F_23 ( V_22 , V_2 -> V_22 . V_30 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
V_2 -> V_32 . V_33 = false ;
}
void F_25 ( struct V_1 * V_2 )
{
F_24 ( V_2 ) ;
if ( V_2 -> V_32 . V_34 ) {
if ( ! F_26 ( V_2 -> V_32 . V_34 , false ) ) {
F_27 ( V_2 -> V_32 . V_34 ) ;
F_28 ( V_2 -> V_32 . V_34 ) ;
F_29 ( V_2 -> V_32 . V_34 ) ;
}
F_30 ( & V_2 -> V_32 . V_34 ) ;
V_2 -> V_32 . V_32 = NULL ;
V_2 -> V_32 . V_34 = NULL ;
}
}
int F_31 ( struct V_1 * V_2 )
{
int V_35 ;
if ( V_2 -> V_32 . V_34 == NULL ) {
V_35 = F_32 ( V_2 , V_36 , V_37 , true ,
V_38 , NULL , & V_2 -> V_32 . V_34 ) ;
if ( V_35 ) {
F_33 ( V_2 -> V_39 , L_3 , V_35 ) ;
return V_35 ;
}
V_35 = F_26 ( V_2 -> V_32 . V_34 , false ) ;
if ( F_34 ( V_35 != 0 ) ) {
F_25 ( V_2 ) ;
return V_35 ;
}
V_35 = F_35 ( V_2 -> V_32 . V_34 , V_38 ,
& V_2 -> V_32 . V_40 ) ;
if ( V_35 ) {
F_29 ( V_2 -> V_32 . V_34 ) ;
F_33 ( V_2 -> V_39 , L_4 , V_35 ) ;
F_25 ( V_2 ) ;
return V_35 ;
}
V_35 = F_36 ( V_2 -> V_32 . V_34 , ( void * * ) & V_2 -> V_32 . V_32 ) ;
F_29 ( V_2 -> V_32 . V_34 ) ;
if ( V_35 ) {
F_33 ( V_2 -> V_39 , L_5 , V_35 ) ;
F_25 ( V_2 ) ;
return V_35 ;
}
}
memset ( ( char * ) V_2 -> V_32 . V_32 , 0 , V_36 ) ;
V_2 -> V_32 . V_41 = false ;
if ( V_42 == 1 ) {
V_2 -> V_32 . V_33 = false ;
} else {
if ( V_2 -> V_43 & V_44 ) {
V_2 -> V_32 . V_33 = false ;
} else if ( V_2 -> V_10 < V_16 ) {
V_2 -> V_32 . V_33 = false ;
} else {
V_2 -> V_32 . V_33 = true ;
if ( V_2 -> V_10 >= V_11 ) {
V_2 -> V_32 . V_41 = true ;
}
}
}
if ( V_2 -> V_10 >= V_45 ) {
V_2 -> V_32 . V_33 = true ;
V_2 -> V_32 . V_41 = true ;
}
F_37 ( V_2 -> V_39 , L_6 , V_2 -> V_32 . V_33 ? L_7 : L_8 ) ;
return 0 ;
}
void F_38 ( struct V_1 * V_2 , struct V_46 * V_47 , T_3 V_23 )
{
T_4 V_48 = ( T_4 ) V_49 << 20 ;
V_47 -> V_50 = V_23 ;
if ( V_47 -> V_51 > ( V_2 -> V_47 . V_52 - V_23 + 1 ) ) {
F_33 ( V_2 -> V_39 , L_9 ) ;
V_47 -> V_53 = V_47 -> V_54 ;
V_47 -> V_51 = V_47 -> V_54 ;
}
V_47 -> V_55 = V_47 -> V_50 + V_47 -> V_51 - 1 ;
if ( V_2 -> V_43 & V_44 && V_47 -> V_55 > V_47 -> V_56 && V_47 -> V_50 <= V_47 -> V_57 ) {
F_33 ( V_2 -> V_39 , L_9 ) ;
V_47 -> V_53 = V_47 -> V_54 ;
V_47 -> V_51 = V_47 -> V_54 ;
}
V_47 -> V_55 = V_47 -> V_50 + V_47 -> V_51 - 1 ;
if ( V_48 && V_48 < V_47 -> V_53 )
V_47 -> V_53 = V_48 ;
F_37 ( V_2 -> V_39 , L_10 ,
V_47 -> V_51 >> 20 , V_47 -> V_50 ,
V_47 -> V_55 , V_47 -> V_53 >> 20 ) ;
}
void F_39 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
T_3 V_58 , V_59 ;
V_58 = ( ( V_2 -> V_47 . V_52 - V_47 -> V_55 ) + V_47 -> V_60 ) & ~ V_47 -> V_60 ;
V_59 = V_47 -> V_50 & ~ V_47 -> V_60 ;
if ( V_59 > V_58 ) {
if ( V_47 -> V_61 > V_59 ) {
F_33 ( V_2 -> V_39 , L_11 ) ;
V_47 -> V_61 = V_59 ;
}
V_47 -> V_56 = ( V_47 -> V_50 & ~ V_47 -> V_60 ) - V_47 -> V_61 ;
} else {
if ( V_47 -> V_61 > V_58 ) {
F_33 ( V_2 -> V_39 , L_11 ) ;
V_47 -> V_61 = V_58 ;
}
V_47 -> V_56 = ( V_47 -> V_55 + 1 + V_47 -> V_60 ) & ~ V_47 -> V_60 ;
}
V_47 -> V_57 = V_47 -> V_56 + V_47 -> V_61 - 1 ;
F_37 ( V_2 -> V_39 , L_12 ,
V_47 -> V_61 >> 20 , V_47 -> V_56 , V_47 -> V_57 ) ;
}
bool F_40 ( struct V_1 * V_2 )
{
T_2 V_6 ;
if ( F_41 ( V_62 ) &&
( V_2 -> V_24 -> V_63 == V_64 ) &&
( V_2 -> V_10 < V_11 ) )
return false ;
if ( F_42 ( V_2 ) )
goto V_65;
if ( F_43 ( V_2 ) ) {
V_6 = F_3 ( V_66 + V_67 ) |
F_3 ( V_66 + V_68 ) ;
if ( V_2 -> V_69 >= 4 ) {
V_6 |= F_3 ( V_66 + V_70 ) |
F_3 ( V_66 + V_71 ) ;
}
if ( V_2 -> V_69 >= 6 ) {
V_6 |= F_3 ( V_66 + V_72 ) |
F_3 ( V_66 + V_73 ) ;
}
if ( V_6 & V_74 )
return true ;
} else if ( F_44 ( V_2 ) ) {
V_6 = F_3 ( V_75 ) |
F_3 ( V_76 ) ;
if ( V_6 & V_77 ) {
return true ;
}
} else {
V_6 = F_3 ( V_78 ) |
F_3 ( V_79 ) ;
if ( V_6 & V_80 ) {
return true ;
}
}
V_65:
if ( V_2 -> V_10 >= V_11 )
V_6 = F_3 ( V_81 ) ;
else
V_6 = F_3 ( V_82 ) ;
if ( V_6 )
return true ;
return false ;
}
void F_45 ( struct V_1 * V_2 )
{
T_5 V_83 ;
T_1 V_84 = V_2 -> V_85 . V_86 ;
T_1 V_87 = V_2 -> V_85 . V_88 ;
V_83 . V_89 = F_46 ( 100 ) ;
V_2 -> V_85 . V_84 . V_89 = F_46 ( V_84 ) ;
V_2 -> V_85 . V_84 . V_89 = F_47 ( V_2 -> V_85 . V_84 , V_83 ) ;
V_2 -> V_85 . V_87 . V_89 = F_46 ( V_87 ) ;
V_2 -> V_85 . V_87 . V_89 = F_47 ( V_2 -> V_85 . V_87 , V_83 ) ;
if ( V_2 -> V_43 & V_90 ) {
V_83 . V_89 = F_46 ( 16 ) ;
V_2 -> V_85 . V_91 . V_89 = F_47 ( V_2 -> V_85 . V_84 , V_83 ) ;
}
}
bool F_48 ( struct V_1 * V_2 )
{
if ( F_40 ( V_2 ) )
return true ;
if ( V_2 -> V_92 ) {
F_16 ( L_13 ) ;
if ( V_2 -> V_93 )
F_49 ( V_2 -> V_94 . V_95 ) ;
else
F_50 ( V_2 -> V_96 ) ;
return true ;
} else {
F_51 ( V_2 -> V_39 , L_14 ) ;
return false ;
}
}
int F_52 ( struct V_1 * V_2 )
{
if ( V_2 -> V_97 . V_98 )
return 0 ;
V_2 -> V_97 . V_98 = F_53 ( V_99 | V_100 | V_101 ) ;
if ( V_2 -> V_97 . V_98 == NULL )
return - V_29 ;
V_2 -> V_97 . V_102 = F_54 ( V_2 -> V_24 , V_2 -> V_97 . V_98 ,
0 , V_37 , V_103 ) ;
if ( F_55 ( V_2 -> V_24 , V_2 -> V_97 . V_102 ) ) {
F_51 ( & V_2 -> V_24 -> V_39 , L_15 ) ;
F_56 ( V_2 -> V_97 . V_98 ) ;
V_2 -> V_97 . V_98 = NULL ;
return - V_29 ;
}
return 0 ;
}
void F_57 ( struct V_1 * V_2 )
{
if ( V_2 -> V_97 . V_98 == NULL )
return;
F_58 ( V_2 -> V_24 , V_2 -> V_97 . V_102 ,
V_37 , V_103 ) ;
F_56 ( V_2 -> V_97 . V_98 ) ;
V_2 -> V_97 . V_98 = NULL ;
}
static T_2 F_59 ( struct V_104 * V_105 , T_2 V_6 )
{
struct V_1 * V_2 = V_105 -> V_39 -> V_106 ;
T_2 V_35 ;
V_35 = V_2 -> V_107 ( V_2 , V_6 ) ;
return V_35 ;
}
static void F_60 ( struct V_104 * V_105 , T_2 V_6 , T_2 V_108 )
{
struct V_1 * V_2 = V_105 -> V_39 -> V_106 ;
V_2 -> V_109 ( V_2 , V_6 , V_108 ) ;
}
static T_2 F_61 ( struct V_104 * V_105 , T_2 V_6 )
{
struct V_1 * V_2 = V_105 -> V_39 -> V_106 ;
T_2 V_35 ;
V_35 = V_2 -> V_110 ( V_2 , V_6 ) ;
return V_35 ;
}
static void F_62 ( struct V_104 * V_105 , T_2 V_6 , T_2 V_108 )
{
struct V_1 * V_2 = V_105 -> V_39 -> V_106 ;
V_2 -> V_111 ( V_2 , V_6 , V_108 ) ;
}
static void F_63 ( struct V_104 * V_105 , T_2 V_6 , T_2 V_108 )
{
struct V_1 * V_2 = V_105 -> V_39 -> V_106 ;
F_4 ( V_6 * 4 , V_108 ) ;
}
static T_2 F_64 ( struct V_104 * V_105 , T_2 V_6 )
{
struct V_1 * V_2 = V_105 -> V_39 -> V_106 ;
T_2 V_35 ;
V_35 = F_3 ( V_6 * 4 ) ;
return V_35 ;
}
static void F_65 ( struct V_104 * V_105 , T_2 V_6 , T_2 V_108 )
{
struct V_1 * V_2 = V_105 -> V_39 -> V_106 ;
F_66 ( V_6 * 4 , V_108 ) ;
}
static T_2 F_67 ( struct V_104 * V_105 , T_2 V_6 )
{
struct V_1 * V_2 = V_105 -> V_39 -> V_106 ;
T_2 V_35 ;
V_35 = F_68 ( V_6 * 4 ) ;
return V_35 ;
}
int F_69 ( struct V_1 * V_2 )
{
struct V_104 * V_112 =
F_70 ( sizeof( struct V_104 ) , V_100 ) ;
if ( ! V_112 )
return - V_29 ;
V_2 -> V_94 . V_112 = V_112 ;
V_112 -> V_39 = V_2 -> V_96 ;
V_112 -> V_113 = F_64 ;
V_112 -> V_114 = F_63 ;
if ( V_2 -> V_115 ) {
V_112 -> V_116 = F_67 ;
V_112 -> V_117 = F_65 ;
} else {
F_71 ( L_16 ) ;
V_112 -> V_116 = F_64 ;
V_112 -> V_117 = F_63 ;
}
V_112 -> V_118 = F_61 ;
V_112 -> V_119 = F_62 ;
V_112 -> V_120 = F_59 ;
V_112 -> V_121 = F_60 ;
V_2 -> V_94 . V_95 = F_72 ( V_112 , V_2 -> V_92 ) ;
if ( ! V_2 -> V_94 . V_95 ) {
F_73 ( V_2 ) ;
return - V_29 ;
}
F_74 ( & V_2 -> V_94 . V_95 -> V_122 ) ;
F_75 ( V_2 -> V_96 ) ;
F_76 ( V_2 -> V_94 . V_95 ) ;
return 0 ;
}
void F_73 ( struct V_1 * V_2 )
{
if ( V_2 -> V_94 . V_95 ) {
F_77 ( V_2 -> V_94 . V_95 -> V_17 ) ;
}
F_77 ( V_2 -> V_94 . V_95 ) ;
V_2 -> V_94 . V_95 = NULL ;
F_77 ( V_2 -> V_94 . V_112 ) ;
V_2 -> V_94 . V_112 = NULL ;
}
int F_78 ( struct V_1 * V_2 )
{
F_79 ( V_2 -> V_96 ) ;
return 0 ;
}
void F_80 ( struct V_1 * V_2 )
{
}
static unsigned int F_81 ( void * V_123 , bool V_124 )
{
struct V_1 * V_2 = V_123 ;
F_82 ( V_2 , V_124 ) ;
if ( V_124 )
return V_125 | V_126 |
V_127 | V_128 ;
else
return V_127 | V_128 ;
}
static bool F_83 ( int V_129 )
{
return ( V_129 & ( V_129 - 1 ) ) == 0 ;
}
static void F_84 ( struct V_1 * V_2 )
{
if ( ! F_83 ( V_49 ) ) {
F_33 ( V_2 -> V_39 , L_17 ,
V_49 ) ;
V_49 = 0 ;
}
if ( V_130 == - 1 ) {
if ( V_2 -> V_10 >= V_131 )
V_130 = 1024 ;
else
V_130 = 512 ;
}
if ( V_130 < 32 ) {
F_33 ( V_2 -> V_39 , L_18 ,
V_130 ) ;
if ( V_2 -> V_10 >= V_131 )
V_130 = 1024 ;
else
V_130 = 512 ;
} else if ( ! F_83 ( V_130 ) ) {
F_33 ( V_2 -> V_39 , L_19 ,
V_130 ) ;
if ( V_2 -> V_10 >= V_131 )
V_130 = 1024 ;
else
V_130 = 512 ;
}
V_2 -> V_47 . V_61 = ( T_4 ) V_130 << 20 ;
switch ( V_132 ) {
case - 1 :
case 0 :
case 1 :
case 2 :
case 4 :
case 8 :
break;
default:
F_33 ( V_2 -> V_39 , L_20
L_21 , V_132 ) ;
V_132 = 0 ;
break;
}
}
static bool F_85 ( struct V_133 * V_24 )
{
if ( V_24 -> V_63 == V_64 &&
V_24 -> V_134 == 0x00e2 ) {
F_86 ( V_135 L_22 ) ;
return true ;
}
return false ;
}
static void F_87 ( struct V_133 * V_24 , enum V_136 V_124 )
{
struct V_137 * V_39 = F_88 ( V_24 ) ;
if ( F_1 () && V_124 == V_138 )
return;
if ( V_124 == V_139 ) {
unsigned V_140 = V_39 -> V_24 -> V_140 ;
F_86 ( V_135 L_23 ) ;
V_39 -> V_141 = V_142 ;
if ( V_140 < 20 && F_85 ( V_24 ) )
V_39 -> V_24 -> V_140 = 20 ;
F_89 ( V_39 , true , true ) ;
V_39 -> V_24 -> V_140 = V_140 ;
V_39 -> V_141 = V_143 ;
F_90 ( V_39 ) ;
} else {
F_86 ( V_135 L_24 ) ;
F_91 ( V_39 ) ;
V_39 -> V_141 = V_142 ;
F_92 ( V_39 , true , true ) ;
V_39 -> V_141 = V_144 ;
}
}
static bool F_93 ( struct V_133 * V_24 )
{
struct V_137 * V_39 = F_88 ( V_24 ) ;
bool V_145 ;
F_94 ( & V_39 -> V_146 ) ;
V_145 = ( V_39 -> V_147 == 0 ) ;
F_95 ( & V_39 -> V_146 ) ;
return V_145 ;
}
int F_96 ( struct V_1 * V_2 ,
struct V_137 * V_96 ,
struct V_133 * V_24 ,
T_2 V_43 )
{
int V_35 , V_9 ;
int V_148 ;
bool V_149 = false ;
V_2 -> V_150 = false ;
V_2 -> V_39 = & V_24 -> V_39 ;
V_2 -> V_96 = V_96 ;
V_2 -> V_24 = V_24 ;
V_2 -> V_43 = V_43 ;
V_2 -> V_10 = V_43 & V_151 ;
V_2 -> V_93 = false ;
V_2 -> V_152 = V_153 ;
V_2 -> V_47 . V_61 = 512 * 1024 * 1024 ;
V_2 -> V_154 = false ;
for ( V_9 = 0 ; V_9 < V_155 ; V_9 ++ ) {
V_2 -> V_156 [ V_9 ] . V_157 = V_9 ;
}
F_16 ( L_25 ,
V_158 [ V_2 -> V_10 ] , V_24 -> V_159 , V_24 -> V_160 ,
V_24 -> V_63 , V_24 -> V_134 ) ;
F_74 ( & V_2 -> V_161 ) ;
F_74 ( & V_2 -> V_162 ) ;
F_97 ( & V_2 -> V_163 . V_164 , 0 ) ;
F_74 ( & V_2 -> V_165 . V_122 ) ;
F_74 ( & V_2 -> V_85 . V_122 ) ;
F_74 ( & V_2 -> V_166 ) ;
F_74 ( & V_2 -> V_167 ) ;
F_98 ( & V_2 -> V_85 . V_168 ) ;
F_98 ( & V_2 -> V_169 ) ;
F_99 ( & V_2 -> V_170 . V_171 ) ;
V_35 = F_100 ( V_2 ) ;
if ( V_35 )
return V_35 ;
F_74 ( & V_2 -> V_172 . V_164 ) ;
V_2 -> V_172 . V_173 = 1 << 20 ;
F_101 ( & V_2 -> V_172 . V_174 ) ;
V_35 = F_102 ( V_2 ) ;
if ( V_35 )
return V_35 ;
F_84 ( V_2 ) ;
if ( ( V_2 -> V_10 >= V_175 ) &&
( V_2 -> V_43 & V_90 ) ) {
V_2 -> V_43 &= ~ V_44 ;
}
if ( V_2 -> V_43 & V_44 && V_132 == - 1 ) {
F_103 ( V_2 ) ;
}
if ( V_2 -> V_10 >= V_176 )
V_2 -> V_47 . V_52 = 0xffffffffffULL ;
else if ( V_2 -> V_10 >= V_177 )
V_2 -> V_47 . V_52 = 0xfffffffffULL ;
else
V_2 -> V_47 . V_52 = 0xffffffffULL ;
V_2 -> V_178 = false ;
if ( V_2 -> V_43 & V_44 )
V_2 -> V_178 = true ;
if ( ( V_2 -> V_43 & V_179 ) &&
( V_2 -> V_10 <= V_180 ) )
V_2 -> V_178 = true ;
V_148 = V_2 -> V_178 ? 32 : 40 ;
V_35 = F_104 ( V_2 -> V_24 , F_105 ( V_148 ) ) ;
if ( V_35 ) {
V_2 -> V_178 = true ;
V_148 = 32 ;
F_86 ( V_181 L_26 ) ;
}
V_35 = F_106 ( V_2 -> V_24 , F_105 ( V_148 ) ) ;
if ( V_35 ) {
F_106 ( V_2 -> V_24 , F_105 ( 32 ) ) ;
F_86 ( V_181 L_27 ) ;
}
F_107 ( & V_2 -> V_182 ) ;
F_107 ( & V_2 -> V_183 ) ;
F_107 ( & V_2 -> V_184 ) ;
F_107 ( & V_2 -> V_185 ) ;
F_107 ( & V_2 -> V_186 ) ;
F_107 ( & V_2 -> V_187 ) ;
F_107 ( & V_2 -> V_188 ) ;
F_107 ( & V_2 -> V_189 ) ;
F_107 ( & V_2 -> V_190 ) ;
F_107 ( & V_2 -> V_191 ) ;
F_107 ( & V_2 -> V_192 ) ;
F_107 ( & V_2 -> V_193 ) ;
if ( V_2 -> V_10 >= V_194 ) {
V_2 -> V_195 = F_12 ( V_2 -> V_24 , 5 ) ;
V_2 -> V_196 = F_13 ( V_2 -> V_24 , 5 ) ;
} else {
V_2 -> V_195 = F_12 ( V_2 -> V_24 , 2 ) ;
V_2 -> V_196 = F_13 ( V_2 -> V_24 , 2 ) ;
}
V_2 -> V_197 = F_15 ( V_2 -> V_195 , V_2 -> V_196 ) ;
if ( V_2 -> V_197 == NULL ) {
return - V_29 ;
}
F_16 ( L_28 , ( T_2 ) V_2 -> V_195 ) ;
F_16 ( L_29 , ( unsigned ) V_2 -> V_196 ) ;
if ( V_2 -> V_10 >= V_194 )
F_11 ( V_2 ) ;
for ( V_9 = 0 ; V_9 < V_198 ; V_9 ++ ) {
if ( F_108 ( V_2 -> V_24 , V_9 ) & V_199 ) {
V_2 -> V_200 = F_13 ( V_2 -> V_24 , V_9 ) ;
V_2 -> V_115 = F_109 ( V_2 -> V_24 , V_9 , V_2 -> V_200 ) ;
break;
}
}
if ( V_2 -> V_115 == NULL )
F_71 ( L_30 ) ;
F_110 ( V_2 -> V_24 , V_2 , NULL , F_81 ) ;
if ( V_201 == 1 )
V_149 = true ;
if ( ( V_201 == - 1 ) && F_1 () )
V_149 = true ;
F_111 ( V_2 -> V_24 , & V_202 , V_149 ) ;
if ( V_149 )
F_112 ( V_2 -> V_39 , & V_2 -> V_203 ) ;
V_35 = F_113 ( V_2 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_114 ( V_2 ) ;
if ( V_35 )
F_71 ( L_31 , V_35 ) ;
V_35 = F_115 ( V_2 ) ;
if ( V_35 ) {
F_71 ( L_32 , V_35 ) ;
}
if ( V_2 -> V_43 & V_44 && ! V_2 -> V_154 ) {
F_116 ( V_2 ) ;
F_117 ( V_2 ) ;
F_103 ( V_2 ) ;
V_35 = F_113 ( V_2 ) ;
if ( V_35 )
return V_35 ;
}
if ( ( V_204 & 1 ) ) {
if ( V_2 -> V_154 )
F_118 ( V_2 ) ;
else
F_16 ( L_33 ) ;
}
if ( ( V_204 & 2 ) ) {
if ( V_2 -> V_154 )
F_119 ( V_2 ) ;
else
F_16 ( L_34 ) ;
}
if ( V_205 ) {
if ( V_2 -> V_154 )
F_120 ( V_2 , V_205 ) ;
else
F_16 ( L_35 ) ;
}
return 0 ;
}
void F_121 ( struct V_1 * V_2 )
{
F_16 ( L_36 ) ;
V_2 -> V_150 = true ;
F_122 ( V_2 ) ;
F_117 ( V_2 ) ;
F_123 ( V_2 -> V_24 ) ;
F_110 ( V_2 -> V_24 , NULL , NULL , NULL ) ;
if ( V_2 -> V_115 )
F_124 ( V_2 -> V_24 , V_2 -> V_115 ) ;
V_2 -> V_115 = NULL ;
F_18 ( V_2 -> V_197 ) ;
V_2 -> V_197 = NULL ;
if ( V_2 -> V_10 >= V_194 )
F_17 ( V_2 ) ;
F_125 ( V_2 ) ;
}
int F_92 ( struct V_137 * V_39 , bool V_206 , bool V_207 )
{
struct V_1 * V_2 ;
struct V_208 * V_209 ;
struct V_210 * V_211 ;
int V_9 , V_35 ;
bool V_212 = false ;
if ( V_39 == NULL || V_39 -> V_106 == NULL ) {
return - V_213 ;
}
V_2 = V_39 -> V_106 ;
if ( V_39 -> V_141 == V_144 )
return 0 ;
F_91 ( V_39 ) ;
F_126 (connector, &dev->mode_config.connector_list, head) {
F_127 ( V_211 , V_214 ) ;
}
F_126 (crtc, &dev->mode_config.crtc_list, head) {
struct V_215 * V_216 = F_128 ( V_209 -> V_217 ) ;
struct V_218 * V_219 ;
if ( V_216 == NULL || V_216 -> V_220 == NULL ) {
continue;
}
V_219 = F_129 ( V_216 -> V_220 ) ;
if ( ! F_130 ( V_2 , V_219 ) ) {
V_35 = F_26 ( V_219 , false ) ;
if ( V_35 == 0 ) {
F_28 ( V_219 ) ;
F_29 ( V_219 ) ;
}
}
}
F_122 ( V_2 ) ;
F_131 ( & V_2 -> V_161 ) ;
for ( V_9 = 0 ; V_9 < V_155 ; V_9 ++ ) {
V_35 = F_132 ( V_2 , V_9 ) ;
if ( V_35 ) {
V_212 = true ;
}
}
if ( V_212 ) {
F_133 ( V_2 ) ;
}
F_134 ( & V_2 -> V_161 ) ;
F_135 ( V_2 ) ;
F_136 ( V_2 ) ;
F_137 ( V_2 ) ;
F_138 ( V_2 ) ;
F_122 ( V_2 ) ;
F_139 ( V_2 ) ;
F_140 ( V_39 -> V_24 ) ;
if ( V_206 ) {
F_141 ( V_39 -> V_24 ) ;
F_142 ( V_39 -> V_24 , V_221 ) ;
}
if ( V_207 ) {
F_143 () ;
F_144 ( V_2 , 1 ) ;
F_145 () ;
}
return 0 ;
}
int F_89 ( struct V_137 * V_39 , bool V_222 , bool V_207 )
{
struct V_210 * V_211 ;
struct V_1 * V_2 = V_39 -> V_106 ;
int V_35 ;
if ( V_39 -> V_141 == V_144 )
return 0 ;
if ( V_207 ) {
F_143 () ;
}
if ( V_222 ) {
F_142 ( V_39 -> V_24 , V_223 ) ;
F_146 ( V_39 -> V_24 ) ;
if ( F_147 ( V_39 -> V_24 ) ) {
if ( V_207 )
F_145 () ;
return - 1 ;
}
}
F_148 ( V_2 ) ;
F_149 ( V_2 ) ;
V_35 = F_114 ( V_2 ) ;
if ( V_35 )
F_71 ( L_31 , V_35 ) ;
F_150 ( V_2 ) ;
F_151 ( V_2 ) ;
if ( V_207 ) {
F_144 ( V_2 , 0 ) ;
F_145 () ;
}
if ( V_2 -> V_93 ) {
F_152 ( V_2 ) ;
F_153 ( V_2 ) ;
if ( V_2 -> V_94 . V_224 ) {
T_6 V_225 = F_154 ( V_2 ,
V_2 -> V_94 . V_224 ) ;
F_155 ( V_2 , V_2 -> V_94 . V_224 ,
V_225 ) ;
}
}
F_156 ( V_2 ) ;
F_157 ( V_39 ) ;
F_126 (connector, &dev->mode_config.connector_list, head) {
F_127 ( V_211 , V_226 ) ;
}
F_90 ( V_39 ) ;
return 0 ;
}
int F_158 ( struct V_1 * V_2 )
{
unsigned V_227 [ V_155 ] ;
T_2 * V_228 [ V_155 ] ;
bool V_229 = false ;
int V_9 , V_35 ;
int V_230 ;
F_159 ( & V_2 -> V_169 ) ;
if ( ! V_2 -> V_231 ) {
F_160 ( & V_2 -> V_169 ) ;
return 0 ;
}
V_2 -> V_231 = false ;
F_135 ( V_2 ) ;
V_230 = F_161 ( & V_2 -> V_232 . V_233 ) ;
F_136 ( V_2 ) ;
F_137 ( V_2 ) ;
for ( V_9 = 0 ; V_9 < V_155 ; ++ V_9 ) {
V_227 [ V_9 ] = F_162 ( V_2 , & V_2 -> V_156 [ V_9 ] ,
& V_228 [ V_9 ] ) ;
if ( V_227 [ V_9 ] ) {
V_229 = true ;
F_37 ( V_2 -> V_39 , L_37
L_38 , V_227 [ V_9 ] , V_9 ) ;
}
}
V_234:
V_35 = F_116 ( V_2 ) ;
if ( ! V_35 ) {
F_37 ( V_2 -> V_39 , L_39 ) ;
F_149 ( V_2 ) ;
}
F_151 ( V_2 ) ;
if ( ! V_35 ) {
for ( V_9 = 0 ; V_9 < V_155 ; ++ V_9 ) {
F_163 ( V_2 , & V_2 -> V_156 [ V_9 ] ,
V_227 [ V_9 ] , V_228 [ V_9 ] ) ;
V_227 [ V_9 ] = 0 ;
V_228 [ V_9 ] = NULL ;
}
V_35 = F_114 ( V_2 ) ;
if ( V_35 ) {
F_51 ( V_2 -> V_39 , L_31 , V_35 ) ;
if ( V_229 ) {
V_229 = false ;
F_137 ( V_2 ) ;
goto V_234;
}
}
} else {
F_133 ( V_2 ) ;
for ( V_9 = 0 ; V_9 < V_155 ; ++ V_9 ) {
F_77 ( V_228 [ V_9 ] ) ;
}
}
F_150 ( V_2 ) ;
F_157 ( V_2 -> V_96 ) ;
F_164 ( & V_2 -> V_232 . V_233 , V_230 ) ;
if ( V_35 ) {
F_37 ( V_2 -> V_39 , L_40 ) ;
}
F_160 ( & V_2 -> V_169 ) ;
return V_35 ;
}
int F_165 ( struct V_1 * V_2 ,
struct V_235 * V_236 ,
unsigned V_237 )
{
unsigned V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_238 ; V_9 ++ ) {
if ( V_2 -> V_239 [ V_9 ] . V_236 == V_236 ) {
return 0 ;
}
}
V_9 = V_2 -> V_238 + 1 ;
if ( V_9 > V_240 ) {
F_71 ( L_41 ) ;
F_71 ( L_42
L_43 ) ;
return - V_21 ;
}
V_2 -> V_239 [ V_2 -> V_238 ] . V_236 = V_236 ;
V_2 -> V_239 [ V_2 -> V_238 ] . V_241 = V_237 ;
V_2 -> V_238 = V_9 ;
#if F_166 ( V_242 )
F_167 ( V_236 , V_237 ,
V_2 -> V_96 -> V_243 -> V_244 ,
V_2 -> V_96 -> V_243 ) ;
F_167 ( V_236 , V_237 ,
V_2 -> V_96 -> V_245 -> V_244 ,
V_2 -> V_96 -> V_245 ) ;
#endif
return 0 ;
}
static void F_125 ( struct V_1 * V_2 )
{
#if F_166 ( V_242 )
unsigned V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_238 ; V_9 ++ ) {
F_168 ( V_2 -> V_239 [ V_9 ] . V_236 ,
V_2 -> V_239 [ V_9 ] . V_241 ,
V_2 -> V_96 -> V_243 ) ;
F_168 ( V_2 -> V_239 [ V_9 ] . V_236 ,
V_2 -> V_239 [ V_9 ] . V_241 ,
V_2 -> V_96 -> V_245 ) ;
}
#endif
}
int F_169 ( struct V_246 * V_247 )
{
return 0 ;
}
void F_170 ( struct V_246 * V_247 )
{
}
