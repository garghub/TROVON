static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_6 ; V_5 ++ ) {
V_4 = & V_2 -> V_7 [ V_5 ] ;
V_4 -> V_8 = F_2 ( V_5 |
F_3 ( V_9 , V_2 -> V_10 ) |
F_3 ( V_11 , 3 ) ) ;
}
}
static int F_4 ( struct V_1 * V_2 ,
T_1 V_12 )
{
struct V_13 * V_14 ;
struct V_3 * V_4 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
T_2 V_21 ;
T_1 V_22 = V_2 -> V_22 ;
T_1 V_6 = V_2 -> V_6 - 1 ;
T_3 V_23 , V_24 ;
int V_5 ;
V_18 = V_2 -> V_18 ;
V_20 = F_5 ( V_2 -> V_18 ) ;
V_16 = F_6 ( V_18 ) ;
V_23 = V_25 | ( V_26 & F_7 ( 11 , 0 ) ) ;
V_24 = V_27 ;
for ( V_5 = 0 ; V_5 < V_12 ; V_5 ++ ) {
V_4 = & V_2 -> V_7 [ V_22 ] ;
V_14 = F_8 ( V_18 , V_24 ) ;
if ( F_9 ( ! V_14 ) )
return - V_28 ;
V_21 = F_10 ( V_20 , V_14 -> V_29 , V_24 , V_30 ) ;
if ( F_11 ( V_20 , V_21 ) ) {
F_12 ( V_18 , L_1 ) ;
F_13 ( V_14 ) ;
return - V_31 ;
}
V_2 -> V_32 [ V_22 ] = V_14 ;
V_4 -> V_33 = F_2 ( F_3 ( V_34 , V_21 ) |
F_3 ( V_35 , V_23 ) |
F_14 ( V_36 ) ) ;
V_22 = ( V_22 + 1 ) & V_6 ;
}
V_16 -> V_37 -> V_38 ( V_2 , V_12 ) ;
V_2 -> V_22 = V_22 ;
return 0 ;
}
static T_4 F_15 ( const void * V_29 )
{
const struct V_39 * V_40 = V_29 ;
return ( V_40 -> V_41 == F_16 ( V_42 ) ) ? V_43 : V_44 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = F_5 ( V_2 -> V_18 ) ;
struct V_3 * V_4 ;
T_2 V_21 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_6 ; V_5 ++ ) {
if ( V_2 -> V_32 [ V_5 ] ) {
F_13 ( V_2 -> V_32 [ V_5 ] ) ;
V_4 = & V_2 -> V_7 [ V_5 ] ;
V_21 = F_18 ( V_34 , F_19 ( V_4 -> V_33 ) ) ;
F_20 ( V_20 , V_21 , V_27 ,
V_30 ) ;
}
}
}
static T_5 F_21 ( const int V_45 , void * V_29 )
{
struct V_1 * V_46 = V_29 ;
if ( F_22 ( & V_46 -> V_47 ) ) {
F_23 ( V_45 ) ;
F_24 ( & V_46 -> V_47 ) ;
}
return V_48 ;
}
static int F_25 ( struct V_1 * V_49 ,
struct V_50 * V_4 )
{
struct V_15 * V_16 = F_6 ( V_49 -> V_18 ) ;
struct V_13 * V_14 ;
struct V_19 * V_20 ;
T_6 * V_51 ;
T_2 * V_52 ;
T_3 V_53 ;
T_4 V_54 ;
int V_5 , V_55 = 0 ;
T_4 V_56 ;
V_53 = F_18 ( V_57 , F_19 ( V_4 -> V_8 ) ) ;
V_14 = V_49 -> V_58 [ V_53 ] ;
V_52 = & V_49 -> V_52 [ V_53 * V_59 ] ;
V_20 = F_5 ( V_49 -> V_18 ) ;
F_20 ( V_20 , F_18 ( V_34 , F_19 ( V_4 -> V_33 ) ) ,
F_26 ( V_14 ) ,
V_60 ) ;
for ( V_5 = 0 ; V_5 < F_27 ( V_14 ) -> V_61 ; V_5 ++ ) {
V_51 = & F_27 ( V_14 ) -> V_62 [ V_5 ] ;
F_28 ( V_20 , V_52 [ V_5 ] , F_29 ( V_51 ) ,
V_60 ) ;
}
if ( F_30 ( V_63 , F_19 ( V_4 -> V_64 ) ) ) {
V_56 = F_18 ( V_65 , F_19 ( V_4 -> V_64 ) ) ;
F_31 ( & V_16 -> V_66 ) ;
V_16 -> V_67 [ V_56 ] -- ;
F_32 ( & V_16 -> V_66 ) ;
}
V_54 = F_18 ( V_68 , F_19 ( V_4 -> V_8 ) ) ;
if ( F_9 ( V_54 > 2 ) ) {
F_33 ( V_49 , F_6 ( V_49 -> V_18 ) ,
V_54 ) ;
V_55 = - V_69 ;
}
if ( F_34 ( V_14 ) ) {
F_13 ( V_14 ) ;
} else {
F_12 ( V_49 -> V_18 , L_2 ) ;
V_55 = - V_69 ;
}
return V_55 ;
}
static int F_35 ( struct V_17 * V_18 , T_1 V_70 )
{
struct V_15 * V_16 = F_6 ( V_18 ) ;
bool V_71 = false ;
int V_56 ;
int V_5 ;
F_31 ( & V_16 -> V_66 ) ;
for ( V_5 = 0 ; ! V_71 && V_5 < V_72 ; V_5 ++ ) {
if ( V_16 -> V_70 [ V_5 ] == V_70 ) {
V_16 -> V_67 [ V_5 ] ++ ;
V_56 = V_5 ;
V_71 = true ;
}
}
for ( V_5 = 0 ; ! V_71 && V_5 < V_72 ; V_5 ++ ) {
if ( ! V_16 -> V_67 [ V_5 ] ) {
V_16 -> V_67 [ V_5 ] ++ ;
V_16 -> V_73 -> V_74 ( V_16 , V_70 , V_5 ) ;
V_16 -> V_70 [ V_5 ] = V_70 ;
V_56 = V_5 ;
V_71 = true ;
}
}
F_32 ( & V_16 -> V_66 ) ;
if ( ! V_71 )
return - V_75 ;
return V_56 ;
}
static int F_36 ( struct V_13 * V_14 , T_7 * V_76 )
{
struct V_17 * V_18 = V_14 -> V_20 ;
struct V_77 * V_78 ;
T_4 V_79 = 0 , V_80 = 0 ;
T_4 V_39 , V_81 = 0 , V_82 = 0 ;
T_1 V_83 , V_70 = 0 ;
T_1 V_5 , V_24 , V_61 ;
int V_56 ;
V_39 = F_15 ( V_14 -> V_29 ) ;
if ( F_9 ( V_14 -> V_84 != F_16 ( V_85 ) ) &&
F_9 ( V_14 -> V_84 != F_16 ( V_42 ) ) )
goto V_86;
if ( F_9 ( ! ( V_14 -> V_20 -> V_87 & V_88 ) ) )
goto V_86;
V_78 = F_37 ( V_14 ) ;
if ( F_9 ( F_38 ( V_78 ) ) )
goto V_86;
if ( F_34 ( V_78 -> V_84 == V_89 ) ) {
V_80 = F_39 ( V_14 ) >> 2 ;
V_82 = 1 ;
V_81 = V_90 ;
if ( V_18 -> V_87 & V_91 ) {
V_83 = V_39 + F_40 ( V_14 ) + F_39 ( V_14 ) ;
V_70 = F_27 ( V_14 ) -> V_92 ;
if ( F_41 ( V_14 ) ) {
V_24 = F_26 ( V_14 ) ;
V_61 = F_27 ( V_14 ) -> V_61 ;
for ( V_5 = 0 ; V_5 < 2 && V_5 < V_61 ; V_5 ++ )
V_24 += F_27 ( V_14 ) -> V_62 [ V_5 ] . V_93 ;
if ( F_9 ( V_83 > V_24 ) ) {
if ( F_42 ( V_14 ) )
return 0 ;
}
}
if ( ! V_70 || ( ( V_14 -> V_24 - V_83 ) <= V_70 ) )
goto V_86;
V_56 = F_35 ( V_18 , V_70 ) ;
if ( F_9 ( V_56 < 0 ) )
return - V_75 ;
* V_76 |= F_14 ( V_63 ) | F_3 ( V_65 , V_56 ) ;
}
} else if ( V_78 -> V_84 == V_94 ) {
V_80 = V_95 ;
V_82 = 1 ;
}
V_86:
V_79 = F_40 ( V_14 ) >> 2 ;
* V_76 |= F_3 ( V_96 , V_80 ) |
F_3 ( V_97 , V_79 ) |
F_3 ( V_98 , V_39 ) |
F_3 ( V_99 , V_82 ) |
F_3 ( V_100 , V_81 ) |
F_14 ( V_101 ) |
F_14 ( V_102 ) ;
return 0 ;
}
static T_3 F_43 ( T_3 V_24 )
{
return ( V_24 == V_103 ) ? 0 : V_24 ;
}
static void F_44 ( T_8 * V_104 , T_1 V_105 , T_2 V_106 , T_1 V_24 )
{
V_104 [ V_105 ^ 1 ] = F_2 ( F_3 ( V_34 , V_106 ) |
F_3 ( V_35 , V_24 ) ) ;
}
static T_8 * F_45 ( struct V_1 * V_107 )
{
T_8 * V_108 ;
V_108 = & V_107 -> V_108 [ V_107 -> V_109 * V_110 ] ;
memset ( V_108 , 0 , sizeof( T_8 ) * V_110 ) ;
V_107 -> V_109 = ( V_107 -> V_109 + 1 ) & ( ( V_107 -> V_6 / 2 ) - 1 ) ;
return V_108 ;
}
static T_2 * F_46 ( struct V_1 * V_107 )
{
return & V_107 -> V_49 -> V_52 [ V_107 -> V_22 * V_59 ] ;
}
static int F_47 ( struct V_1 * V_111 ,
struct V_13 * V_14 )
{
struct V_19 * V_20 = F_5 ( V_111 -> V_18 ) ;
struct V_15 * V_16 = F_6 ( V_111 -> V_18 ) ;
struct V_50 * V_4 ;
T_8 * V_112 = NULL , * V_108 = NULL ;
T_2 V_21 , V_113 , * V_52 ;
T_6 * V_51 ;
T_3 V_22 = V_111 -> V_22 ;
T_7 V_76 = 0 ;
T_1 V_24 , V_114 ;
T_4 V_115 = 0 , V_116 = 0 , V_105 = 0 ;
bool V_117 = false ;
T_1 V_93 , V_118 , V_119 = 0 ;
T_1 V_5 , V_120 , V_61 , V_121 = 1 ;
int V_55 ;
V_4 = & V_111 -> V_4 [ V_22 ] ;
V_22 = ( V_22 + 1 ) & ( V_111 -> V_6 - 1 ) ;
memset ( V_4 , 0 , sizeof( struct V_50 ) ) ;
V_55 = F_36 ( V_14 , & V_76 ) ;
if ( V_55 )
return V_55 ;
V_4 -> V_64 = F_2 ( F_3 ( V_122 , V_111 -> V_10 ) |
V_76 ) ;
V_24 = F_26 ( V_14 ) ;
V_114 = F_43 ( V_24 ) ;
V_21 = F_10 ( V_20 , V_14 -> V_29 , V_24 , V_60 ) ;
if ( F_11 ( V_20 , V_21 ) ) {
F_12 ( V_111 -> V_18 , L_1 ) ;
return - V_31 ;
}
V_4 -> V_33 = F_2 ( F_3 ( V_34 , V_21 ) |
F_3 ( V_35 , V_114 ) |
F_14 ( V_36 ) ) ;
if ( ! F_41 ( V_14 ) )
goto V_86;
V_116 = 1 ;
V_112 = ( void * ) & V_111 -> V_4 [ V_22 ] ;
V_22 = ( V_22 + 1 ) & ( V_111 -> V_6 - 1 ) ;
memset ( V_112 , 0 , sizeof( struct V_50 ) ) ;
V_61 = F_27 ( V_14 ) -> V_61 ;
for ( V_5 = V_61 ; V_5 < 4 ; V_5 ++ )
V_112 [ V_5 ^ 1 ] = F_2 ( V_123 ) ;
V_52 = F_46 ( V_111 ) ;
for ( V_5 = 0 , V_120 = 0 ; V_117 || ( V_120 < V_61 ) ; V_5 ++ ) {
if ( ! V_117 ) {
V_51 = & F_27 ( V_14 ) -> V_62 [ V_120 ] ;
V_93 = F_29 ( V_51 ) ;
V_118 = 0 ;
V_113 = F_48 ( V_20 , V_51 , 0 , V_93 ,
V_60 ) ;
if ( F_11 ( V_20 , V_113 ) )
return - V_31 ;
V_52 [ V_120 ] = V_113 ;
V_120 ++ ;
if ( V_93 > V_103 )
V_117 = true ;
}
if ( V_93 > V_103 ) {
V_24 = V_103 ;
V_93 -= V_103 ;
} else {
V_24 = V_93 ;
V_117 = false ;
}
V_21 = V_113 + V_118 ;
V_114 = F_43 ( V_24 ) ;
switch ( V_5 ) {
case 0 :
case 1 :
case 2 :
F_44 ( V_112 , V_5 , V_21 , V_114 ) ;
break;
case 3 :
if ( V_117 || ( V_120 != V_61 ) ) {
V_108 = F_45 ( V_111 ) ;
F_44 ( V_108 , V_105 , V_21 ,
V_114 ) ;
V_105 ++ ;
V_119 += V_24 ;
} else {
F_44 ( V_112 , V_5 , V_21 ,
V_114 ) ;
}
break;
default:
F_44 ( V_108 , V_105 , V_21 , V_114 ) ;
V_105 ++ ;
V_119 += V_24 ;
break;
}
if ( V_117 )
V_118 += V_103 ;
}
V_121 ++ ;
if ( V_105 ) {
V_115 = 1 ;
V_21 = F_10 ( V_20 , V_108 ,
sizeof( T_7 ) * V_110 ,
V_60 ) ;
if ( F_11 ( V_20 , V_21 ) ) {
F_13 ( V_14 ) ;
return - V_31 ;
}
V_5 = V_119 >> V_124 ;
V_112 [ 2 ] = F_2 ( F_3 ( V_34 , V_21 ) |
F_3 ( V_125 , V_5 ) |
F_3 ( V_126 , V_105 ) ) ;
V_4 -> V_127 = F_2 ( F_3 ( V_128 , V_119 ) ) ;
}
V_86:
V_4 -> V_8 = F_2 ( F_3 ( V_129 , V_115 ) | F_3 ( V_130 , V_116 ) |
F_3 ( V_57 , V_111 -> V_22 ) ) ;
V_111 -> V_49 -> V_58 [ V_111 -> V_22 ] = V_14 ;
V_16 -> V_131 [ V_111 -> V_49 -> V_132 ] += V_121 ;
V_111 -> V_22 = V_22 ;
return V_121 ;
}
static T_9 F_49 ( struct V_13 * V_14 ,
struct V_17 * V_18 )
{
struct V_15 * V_16 = F_6 ( V_18 ) ;
struct V_1 * V_111 ;
int V_132 = V_14 -> V_133 ;
T_1 V_131 = V_16 -> V_131 [ V_132 ] ;
int V_121 ;
V_111 = V_16 -> V_111 [ V_132 ] ;
if ( V_131 < V_16 -> V_134 [ V_132 ] )
V_131 += ( ( F_50 ( V_16 -> V_131 [ V_132 ] ) ) ~ 0U ) ;
if ( ( V_131 - V_16 -> V_134 [ V_132 ] ) > V_16 -> V_135 ) {
F_51 ( V_18 , V_132 ) ;
return V_136 ;
}
if ( F_52 ( V_14 , V_137 ) )
return V_138 ;
V_121 = F_47 ( V_111 , V_14 ) ;
if ( V_121 == - V_75 )
return V_136 ;
if ( V_121 <= 0 ) {
F_13 ( V_14 ) ;
return V_138 ;
}
F_53 ( V_14 ) ;
V_111 -> V_139 ++ ;
V_111 -> V_140 += V_14 -> V_24 ;
V_16 -> V_37 -> V_38 ( V_111 , V_121 ) ;
return V_138 ;
}
static void F_54 ( struct V_13 * V_14 )
{
struct V_77 * V_78 = F_37 ( V_14 ) ;
if ( ! F_38 ( V_78 ) ||
( V_78 -> V_84 != V_89 && V_78 -> V_84 != V_94 ) ) {
V_14 -> V_141 = V_142 ;
}
}
static int F_55 ( struct V_1 * V_46 ,
struct V_50 * V_4 )
{
struct V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_1 * V_2 ;
T_1 V_143 , V_53 ;
struct V_13 * V_14 ;
T_4 V_54 ;
int V_55 = 0 ;
V_18 = V_46 -> V_18 ;
V_20 = F_5 ( V_46 -> V_18 ) ;
V_2 = V_46 -> V_2 ;
F_20 ( V_20 , F_18 ( V_34 , F_19 ( V_4 -> V_33 ) ) ,
V_27 , V_30 ) ;
V_53 = F_18 ( V_57 , F_19 ( V_4 -> V_8 ) ) ;
V_14 = V_2 -> V_32 [ V_53 ] ;
V_2 -> V_32 [ V_53 ] = NULL ;
V_54 = ( F_18 ( V_144 , F_19 ( V_4 -> V_8 ) ) << V_145 ) ||
F_18 ( V_68 , F_19 ( V_4 -> V_8 ) ) ;
if ( F_9 ( V_54 > 2 ) ) {
F_13 ( V_14 ) ;
F_33 ( V_46 , F_6 ( V_46 -> V_18 ) ,
V_54 ) ;
V_55 = - V_69 ;
goto V_86;
}
V_143 = F_18 ( V_35 , F_19 ( V_4 -> V_33 ) ) ;
V_143 = ( V_143 & V_146 ) - 4 ;
F_56 ( V_14 -> V_29 - V_147 ) ;
F_57 ( V_14 , V_143 ) ;
F_58 ( V_14 ) ;
V_14 -> V_84 = F_59 ( V_14 , V_18 ) ;
if ( F_34 ( ( V_18 -> V_87 & V_88 ) &&
V_14 -> V_84 == F_16 ( V_85 ) ) ) {
F_54 ( V_14 ) ;
}
V_46 -> V_148 ++ ;
V_46 -> V_149 += V_143 ;
F_60 ( & V_46 -> V_47 , V_14 ) ;
V_86:
if ( -- V_46 -> V_150 == 0 ) {
V_55 = F_4 ( V_2 , V_151 ) ;
V_46 -> V_150 = V_151 ;
}
return V_55 ;
}
static bool F_61 ( struct V_50 * V_4 )
{
return F_18 ( V_9 , F_19 ( V_4 -> V_8 ) ) ? true : false ;
}
static int F_62 ( struct V_1 * V_107 ,
int V_152 )
{
struct V_17 * V_18 = V_107 -> V_18 ;
struct V_15 * V_16 = F_6 ( V_18 ) ;
struct V_50 * V_4 , * V_112 ;
T_3 V_153 = V_107 -> V_153 ;
T_3 V_6 = V_107 -> V_6 - 1 ;
int V_55 , V_154 , V_121 = 0 , V_155 = 0 ;
bool V_156 ;
do {
V_4 = & V_107 -> V_4 [ V_153 ] ;
V_154 = 0 ;
V_156 = false ;
V_112 = NULL ;
if ( F_9 ( F_63 ( V_4 ) ) )
break;
F_64 () ;
if ( F_30 ( V_130 , F_19 ( V_4 -> V_8 ) ) ) {
V_153 = ( V_153 + 1 ) & V_6 ;
V_112 = & V_107 -> V_4 [ V_153 ] ;
if ( F_9 ( F_63 ( V_112 ) ) ) {
V_153 = ( V_153 - 1 ) & V_6 ;
break;
}
F_64 () ;
V_121 ++ ;
V_154 ++ ;
}
if ( F_61 ( V_4 ) ) {
V_55 = F_55 ( V_107 , V_4 ) ;
} else {
V_55 = F_25 ( V_107 , V_4 ) ;
V_156 = true ;
}
F_65 ( V_4 ) ;
if ( V_112 )
F_65 ( V_112 ) ;
V_153 = ( V_153 + 1 ) & V_6 ;
V_121 ++ ;
V_154 ++ ;
V_155 ++ ;
if ( V_156 )
V_16 -> V_134 [ V_107 -> V_132 ] += V_154 ;
if ( V_55 )
break;
} while ( -- V_152 );
if ( F_34 ( V_121 ) ) {
V_16 -> V_37 -> V_38 ( V_107 , - V_121 ) ;
V_107 -> V_153 = V_153 ;
if ( F_66 ( V_18 , V_107 -> V_132 ) )
F_67 ( V_18 , V_107 -> V_132 ) ;
}
return V_155 ;
}
static int F_68 ( struct V_157 * V_47 , const int V_152 )
{
struct V_1 * V_107 ;
int V_155 ;
V_107 = F_69 ( V_47 , struct V_1 , V_47 ) ;
V_155 = F_62 ( V_107 , V_152 ) ;
if ( V_155 != V_152 ) {
F_70 ( V_47 ) ;
F_71 ( V_107 -> V_45 ) ;
}
return V_155 ;
}
static void F_72 ( struct V_17 * V_18 )
{
struct V_15 * V_16 = F_6 ( V_18 ) ;
struct V_158 * V_159 ;
int V_5 ;
V_16 -> V_73 -> V_160 ( V_16 ) ;
for ( V_5 = 0 ; V_5 < V_16 -> V_161 ; V_5 ++ ) {
V_159 = F_73 ( V_18 , V_5 ) ;
V_159 -> V_162 = V_163 ;
F_74 ( V_159 ) ;
}
}
static void F_75 ( struct V_17 * V_18 )
{
struct V_15 * V_16 = F_6 ( V_18 ) ;
struct V_1 * V_107 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_16 -> V_164 ; V_5 ++ ) {
V_107 = V_16 -> V_46 [ V_5 ] ;
if ( ! V_16 -> V_165 ) {
snprintf ( V_107 -> V_166 , V_167 , L_3 ,
V_18 -> V_168 ) ;
} else {
snprintf ( V_107 -> V_166 , V_167 , L_4 ,
V_18 -> V_168 , V_5 ) ;
}
}
for ( V_5 = 0 ; V_5 < V_16 -> V_165 ; V_5 ++ ) {
V_107 = V_16 -> V_111 [ V_5 ] -> V_49 ;
snprintf ( V_107 -> V_166 , V_167 , L_5 ,
V_18 -> V_168 , V_5 ) ;
}
}
static int F_76 ( struct V_17 * V_18 )
{
struct V_15 * V_16 = F_6 ( V_18 ) ;
struct V_19 * V_20 = F_5 ( V_18 ) ;
struct V_1 * V_107 ;
int V_55 = 0 , V_5 ;
F_75 ( V_18 ) ;
for ( V_5 = 0 ; V_5 < V_16 -> V_164 ; V_5 ++ ) {
V_107 = V_16 -> V_46 [ V_5 ] ;
F_77 ( V_107 -> V_45 , V_169 ) ;
V_55 = F_78 ( V_20 , V_107 -> V_45 , F_21 ,
0 , V_107 -> V_166 , V_107 ) ;
if ( V_55 ) {
F_12 ( V_18 , L_6 ,
V_107 -> V_166 ) ;
}
}
for ( V_5 = 0 ; V_5 < V_16 -> V_165 ; V_5 ++ ) {
V_107 = V_16 -> V_111 [ V_5 ] -> V_49 ;
F_77 ( V_107 -> V_45 , V_169 ) ;
V_55 = F_78 ( V_20 , V_107 -> V_45 , F_21 ,
0 , V_107 -> V_166 , V_107 ) ;
if ( V_55 ) {
F_12 ( V_18 , L_6 ,
V_107 -> V_166 ) ;
}
}
return V_55 ;
}
static void F_79 ( struct V_17 * V_18 )
{
struct V_15 * V_16 ;
struct V_1 * V_107 ;
struct V_19 * V_20 ;
int V_5 ;
V_16 = F_6 ( V_18 ) ;
V_20 = F_5 ( V_18 ) ;
for ( V_5 = 0 ; V_5 < V_16 -> V_164 ; V_5 ++ ) {
V_107 = V_16 -> V_46 [ V_5 ] ;
F_80 ( V_107 -> V_45 , V_169 ) ;
F_81 ( V_20 , V_107 -> V_45 , V_107 ) ;
}
for ( V_5 = 0 ; V_5 < V_16 -> V_165 ; V_5 ++ ) {
V_107 = V_16 -> V_111 [ V_5 ] -> V_49 ;
F_80 ( V_107 -> V_45 , V_169 ) ;
F_81 ( V_20 , V_107 -> V_45 , V_107 ) ;
}
}
static void F_82 ( struct V_15 * V_16 )
{
struct V_157 * V_47 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_16 -> V_164 ; V_5 ++ ) {
V_47 = & V_16 -> V_46 [ V_5 ] -> V_47 ;
F_83 ( V_47 ) ;
}
for ( V_5 = 0 ; V_5 < V_16 -> V_165 ; V_5 ++ ) {
V_47 = & V_16 -> V_111 [ V_5 ] -> V_49 -> V_47 ;
F_83 ( V_47 ) ;
}
}
static void F_84 ( struct V_15 * V_16 )
{
struct V_157 * V_47 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_16 -> V_164 ; V_5 ++ ) {
V_47 = & V_16 -> V_46 [ V_5 ] -> V_47 ;
F_85 ( V_47 ) ;
}
for ( V_5 = 0 ; V_5 < V_16 -> V_165 ; V_5 ++ ) {
V_47 = & V_16 -> V_111 [ V_5 ] -> V_49 -> V_47 ;
F_85 ( V_47 ) ;
}
}
static int F_86 ( struct V_17 * V_18 )
{
struct V_15 * V_16 = F_6 ( V_18 ) ;
const struct V_170 * V_73 = V_16 -> V_73 ;
int V_55 ;
V_55 = F_87 ( V_18 , V_16 -> V_161 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_88 ( V_18 , V_16 -> V_164 ) ;
if ( V_55 )
return V_55 ;
F_82 ( V_16 ) ;
V_55 = F_76 ( V_18 ) ;
if ( V_55 )
return V_55 ;
if ( V_18 -> V_171 ) {
F_89 ( V_18 -> V_171 ) ;
} else {
F_90 ( & V_16 -> V_172 , V_173 ) ;
F_91 ( V_18 ) ;
}
V_73 -> V_174 ( V_16 ) ;
V_73 -> V_175 ( V_16 ) ;
F_92 ( V_18 ) ;
return V_55 ;
}
static int F_93 ( struct V_17 * V_18 )
{
struct V_15 * V_16 = F_6 ( V_18 ) ;
const struct V_170 * V_73 = V_16 -> V_73 ;
int V_5 ;
F_94 ( V_18 ) ;
V_73 -> V_176 ( V_16 ) ;
V_73 -> V_177 ( V_16 ) ;
if ( V_18 -> V_171 )
F_95 ( V_18 -> V_171 ) ;
else
F_96 ( & V_16 -> V_172 ) ;
F_79 ( V_18 ) ;
F_84 ( V_16 ) ;
for ( V_5 = 0 ; V_5 < V_16 -> V_164 ; V_5 ++ )
F_62 ( V_16 -> V_46 [ V_5 ] , - 1 ) ;
return 0 ;
}
static void F_97 ( struct V_1 * V_107 )
{
struct V_15 * V_16 ;
struct V_19 * V_20 ;
V_16 = F_6 ( V_107 -> V_18 ) ;
V_20 = F_5 ( V_107 -> V_18 ) ;
V_16 -> V_37 -> V_178 ( V_107 ) ;
F_98 ( V_20 , V_107 -> V_93 , V_107 -> V_179 , V_107 -> V_180 ) ;
}
static void F_99 ( struct V_15 * V_16 )
{
struct V_1 * V_2 ;
struct V_1 * V_107 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_16 -> V_161 ; V_5 ++ ) {
V_107 = V_16 -> V_111 [ V_5 ] ;
if ( V_107 ) {
F_97 ( V_107 ) ;
V_16 -> V_181 -> V_178 ( V_16 , V_107 ) ;
if ( V_16 -> V_165 )
F_97 ( V_107 -> V_49 ) ;
V_16 -> V_111 [ V_5 ] = NULL ;
}
}
for ( V_5 = 0 ; V_5 < V_16 -> V_164 ; V_5 ++ ) {
V_107 = V_16 -> V_46 [ V_5 ] ;
if ( V_107 ) {
V_2 = V_107 -> V_2 ;
F_17 ( V_2 ) ;
F_97 ( V_2 ) ;
V_16 -> V_181 -> V_178 ( V_16 , V_2 ) ;
F_97 ( V_107 ) ;
V_16 -> V_46 [ V_5 ] = NULL ;
}
}
}
static int F_100 ( struct V_19 * V_20 ,
enum V_182 V_183 )
{
int V_93 = - V_31 ;
switch ( V_183 ) {
case V_184 :
V_93 = 0x200 ;
break;
case V_185 :
V_93 = 0x800 ;
break;
case V_186 :
V_93 = 0x4000 ;
break;
case V_187 :
V_93 = 0x10000 ;
break;
case V_188 :
V_93 = 0x80000 ;
break;
default:
F_101 ( V_20 , L_7 , V_183 ) ;
break;
}
return V_93 ;
}
static void F_102 ( struct V_1 * V_107 )
{
struct V_15 * V_16 ;
struct V_19 * V_20 ;
if ( ! V_107 )
return;
V_20 = F_5 ( V_107 -> V_18 ) ;
V_16 = F_6 ( V_107 -> V_18 ) ;
if ( V_107 -> V_179 ) {
V_16 -> V_37 -> V_178 ( V_107 ) ;
F_98 ( V_20 , V_107 -> V_93 , V_107 -> V_179 , V_107 -> V_180 ) ;
}
F_103 ( V_20 , V_107 ) ;
}
static void F_104 ( struct V_15 * V_16 )
{
struct V_19 * V_20 = & V_16 -> V_189 -> V_20 ;
struct V_1 * V_107 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_16 -> V_161 ; V_5 ++ ) {
V_107 = V_16 -> V_111 [ V_5 ] ;
if ( V_107 ) {
if ( V_107 -> V_49 && V_107 -> V_49 -> V_58 )
F_103 ( V_20 , V_107 -> V_49 -> V_58 ) ;
if ( V_107 -> V_49 && V_16 -> V_165 )
F_102 ( V_107 -> V_49 ) ;
F_102 ( V_107 ) ;
}
}
for ( V_5 = 0 ; V_5 < V_16 -> V_164 ; V_5 ++ ) {
V_107 = V_16 -> V_46 [ V_5 ] ;
if ( V_107 ) {
if ( V_107 -> V_2 ) {
if ( V_107 -> V_2 -> V_32 )
F_103 ( V_20 , V_107 -> V_2 -> V_32 ) ;
F_102 ( V_107 -> V_2 ) ;
}
F_102 ( V_107 ) ;
}
}
}
static bool F_105 ( struct V_15 * V_16 ,
struct V_1 * V_107 )
{
if ( ( V_16 -> V_190 == V_191 ) &&
( F_106 ( V_107 -> V_192 ) == V_193 ) ) {
return true ;
}
return false ;
}
static void T_10 * F_107 ( struct V_15 * V_16 ,
struct V_1 * V_107 )
{
T_4 V_194 = V_16 -> V_37 -> V_194 ;
return V_16 -> V_195 + ( V_107 -> V_196 << V_194 ) ;
}
static struct V_1 * F_108 (
struct V_17 * V_18 , T_1 V_197 ,
enum V_182 V_183 , T_1 V_198 )
{
struct V_15 * V_16 = F_6 ( V_18 ) ;
struct V_19 * V_20 = F_5 ( V_18 ) ;
struct V_1 * V_107 ;
void * V_199 ;
int V_93 ;
V_93 = F_100 ( V_20 , V_183 ) ;
if ( V_93 < 0 )
return NULL ;
V_107 = F_109 ( V_20 , sizeof( struct V_1 ) ,
V_200 ) ;
if ( ! V_107 )
return NULL ;
V_107 -> V_18 = V_18 ;
V_107 -> V_196 = V_197 ;
V_107 -> V_183 = V_183 ;
V_107 -> V_192 = V_198 ;
V_107 -> V_179 = F_110 ( V_20 , V_93 , & V_107 -> V_180 ,
V_200 | V_201 ) ;
if ( ! V_107 -> V_179 ) {
F_103 ( V_20 , V_107 ) ;
return NULL ;
}
V_107 -> V_93 = V_93 ;
if ( F_105 ( V_16 , V_107 ) ) {
V_199 = F_110 ( V_20 , V_202 ,
& V_107 -> V_203 ,
V_200 | V_201 ) ;
if ( ! V_199 ) {
F_98 ( V_20 , V_93 , V_107 -> V_179 ,
V_107 -> V_180 ) ;
F_103 ( V_20 , V_107 ) ;
return NULL ;
}
V_107 -> V_199 = V_199 ;
}
V_107 -> V_204 = F_107 ( V_16 , V_107 ) ;
V_107 -> V_205 = V_107 -> V_204 + V_206 ;
V_107 = V_16 -> V_37 -> V_207 ( V_107 ) ;
F_111 ( V_18 , L_8 ,
V_107 -> V_196 , V_107 -> V_93 , V_107 -> V_192 , V_107 -> V_6 ) ;
return V_107 ;
}
static T_3 F_112 ( enum V_208 V_209 , T_4 V_210 )
{
return ( V_209 << 6 ) | ( V_210 & F_7 ( 5 , 0 ) ) ;
}
static enum V_208 F_113 ( struct V_15 * V_211 )
{
enum V_208 V_209 ;
if ( V_211 -> V_190 == V_212 ) {
switch ( V_211 -> V_213 ) {
case V_214 :
V_209 = V_215 ;
break;
default:
V_209 = ( ! V_211 -> V_216 ) ? V_215 :
V_217 ;
break;
}
} else {
V_209 = ( ! V_211 -> V_216 ) ? V_215 : V_217 ;
}
return V_209 ;
}
static T_4 F_114 ( struct V_15 * V_16 )
{
struct V_19 * V_20 = & V_16 -> V_189 -> V_20 ;
T_1 V_218 ;
int V_55 ;
V_55 = F_115 ( V_20 , L_9 , & V_218 ) ;
return ( ! V_55 ) ? V_218 : V_16 -> V_218 ;
}
static int F_116 ( struct V_17 * V_18 )
{
struct V_15 * V_16 = F_6 ( V_18 ) ;
struct V_19 * V_20 = F_5 ( V_18 ) ;
struct V_1 * V_46 , * V_111 , * V_49 ;
struct V_1 * V_2 = NULL ;
enum V_208 V_209 ;
T_2 V_219 ;
T_4 V_218 ;
T_4 V_220 = V_16 -> V_220 ;
T_4 V_221 = V_16 -> V_221 ;
T_3 V_197 = V_16 -> V_197 ;
T_8 * V_108 ;
T_3 V_198 ;
int V_5 , V_55 , V_93 ;
V_218 = F_114 ( V_16 ) ;
for ( V_5 = 0 ; V_5 < V_16 -> V_164 ; V_5 ++ ) {
V_209 = F_113 ( V_16 ) ;
V_198 = F_112 ( V_193 , V_218 ++ ) ;
V_46 = F_108 ( V_18 , V_197 ++ ,
V_186 ,
V_198 ) ;
if ( ! V_46 ) {
V_55 = - V_28 ;
goto V_222;
}
V_209 = F_113 ( V_16 ) ;
V_198 = F_112 ( V_209 , V_221 ++ ) ;
V_2 = F_108 ( V_18 , V_197 ++ ,
V_185 ,
V_198 ) ;
if ( ! V_2 ) {
V_55 = - V_28 ;
goto V_222;
}
V_46 -> V_150 = V_151 ;
V_46 -> V_2 = V_2 ;
V_46 -> V_45 = V_16 -> V_223 [ V_5 ] ;
V_2 -> V_32 = F_117 ( V_20 , V_2 -> V_6 ,
sizeof( struct V_13 * ) ,
V_200 ) ;
if ( ! V_2 -> V_32 ) {
V_55 = - V_28 ;
goto V_222;
}
V_2 -> V_10 = F_118 ( V_2 ) ;
V_46 -> V_2 = V_2 ;
V_16 -> V_46 [ V_5 ] = V_46 ;
}
for ( V_5 = 0 ; V_5 < V_16 -> V_161 ; V_5 ++ ) {
V_209 = F_113 ( V_16 ) ;
V_198 = F_112 ( V_209 , V_220 ++ ) ;
V_111 = F_108 ( V_18 , V_197 ++ ,
V_186 ,
V_198 ) ;
if ( ! V_111 ) {
V_55 = - V_28 ;
goto V_222;
}
V_93 = ( V_111 -> V_6 / 2 ) * sizeof( T_8 ) * V_110 ;
V_108 = F_110 ( V_20 , V_93 , & V_219 ,
V_200 | V_201 ) ;
if ( ! V_108 ) {
V_55 = - V_28 ;
goto V_222;
}
V_111 -> V_108 = V_108 ;
V_16 -> V_111 [ V_5 ] = V_111 ;
if ( ! V_16 -> V_165 ) {
V_49 = V_16 -> V_46 [ V_5 ] ;
} else {
V_198 = F_112 ( V_193 ,
V_218 ++ ) ;
V_49 = F_108 ( V_18 , V_197 ++ ,
V_186 ,
V_198 ) ;
if ( ! V_49 ) {
V_55 = - V_28 ;
goto V_222;
}
V_49 -> V_45 = V_16 -> V_223 [ V_16 -> V_164 + V_5 ] ;
V_49 -> V_132 = V_5 ;
}
V_49 -> V_58 = F_117 ( V_20 , V_111 -> V_6 ,
sizeof( struct V_13 * ) ,
V_200 ) ;
if ( ! V_49 -> V_58 ) {
V_55 = - V_28 ;
goto V_222;
}
V_93 = sizeof( T_2 ) * V_59 ;
V_49 -> V_52 = F_117 ( V_20 , V_111 -> V_6 ,
V_93 , V_200 ) ;
if ( ! V_49 -> V_52 ) {
F_103 ( V_20 , V_49 -> V_58 ) ;
V_55 = - V_28 ;
goto V_222;
}
V_111 -> V_49 = V_49 ;
V_111 -> V_10 = F_118 ( V_49 ) ;
}
if ( V_16 -> V_37 -> V_224 )
V_16 -> V_37 -> V_224 ( V_16 -> V_111 [ 0 ] ) ;
V_16 -> V_135 = V_16 -> V_111 [ 0 ] -> V_6 - 128 ;
return 0 ;
V_222:
F_104 ( V_16 ) ;
return V_55 ;
}
static struct V_225 * F_119 (
struct V_17 * V_18 ,
struct V_225 * V_226 )
{
struct V_15 * V_16 = F_6 ( V_18 ) ;
struct V_225 * V_227 = & V_16 -> V_227 ;
struct V_1 * V_107 ;
int V_5 ;
memset ( V_227 , 0 , sizeof( struct V_225 ) ) ;
for ( V_5 = 0 ; V_5 < V_16 -> V_161 ; V_5 ++ ) {
V_107 = V_16 -> V_111 [ V_5 ] ;
if ( V_107 ) {
V_227 -> V_139 += V_107 -> V_139 ;
V_227 -> V_140 += V_107 -> V_140 ;
}
}
for ( V_5 = 0 ; V_5 < V_16 -> V_164 ; V_5 ++ ) {
V_107 = V_16 -> V_46 [ V_5 ] ;
if ( V_107 ) {
V_227 -> V_148 += V_107 -> V_148 ;
V_227 -> V_149 += V_107 -> V_149 ;
V_227 -> V_228 += V_107 -> V_229 +
V_107 -> V_230 +
V_107 -> V_231 +
V_107 -> V_232 ;
V_227 -> V_233 += V_107 -> V_233 ;
}
}
memcpy ( V_226 , V_227 , sizeof( struct V_225 ) ) ;
return V_226 ;
}
static int F_120 ( struct V_17 * V_18 , void * V_106 )
{
struct V_15 * V_16 = F_6 ( V_18 ) ;
int V_55 ;
V_55 = F_121 ( V_18 , V_106 ) ;
if ( V_55 )
return V_55 ;
V_16 -> V_73 -> V_234 ( V_16 ) ;
return V_55 ;
}
static void F_122 ( struct V_19 * V_20 ,
struct V_15 * V_16 )
{
T_11 V_54 ;
T_7 V_235 ;
V_54 = F_123 ( F_124 ( V_20 ) , L_10 , NULL , & V_235 ) ;
if ( F_125 ( V_54 ) ) {
V_16 -> V_216 = 0 ;
} else {
V_16 -> V_216 = V_235 ;
}
return;
}
static void F_126 ( struct V_19 * V_20 , struct V_15 * V_16 )
{
T_1 V_192 = 0 ;
F_127 ( V_20 -> V_236 , L_11 , & V_192 ) ;
V_16 -> V_216 = V_192 & F_128 ( 0 ) ;
return;
}
static int F_129 ( struct V_15 * V_16 )
{
struct V_19 * V_20 = & V_16 -> V_189 -> V_20 ;
int V_237 , V_55 ;
V_55 = F_127 ( V_20 -> V_236 , L_12 , & V_237 ) ;
if ( V_55 ) {
V_16 -> V_238 = 4 ;
return 0 ;
}
if ( V_237 < 0 || V_237 > 7 ) {
F_101 ( V_20 , L_13 ) ;
return - V_31 ;
}
V_16 -> V_238 = V_237 ;
return 0 ;
}
static int F_130 ( struct V_15 * V_16 )
{
struct V_19 * V_20 = & V_16 -> V_189 -> V_20 ;
int V_237 , V_55 ;
V_55 = F_127 ( V_20 -> V_236 , L_14 , & V_237 ) ;
if ( V_55 ) {
V_16 -> V_239 = 2 ;
return 0 ;
}
if ( V_237 < 0 || V_237 > 7 ) {
F_101 ( V_20 , L_15 ) ;
return - V_31 ;
}
V_16 -> V_239 = V_237 ;
return 0 ;
}
static int F_131 ( struct V_15 * V_16 )
{
struct V_240 * V_189 = V_16 -> V_189 ;
struct V_19 * V_20 = & V_189 -> V_20 ;
int V_5 , V_55 , V_241 ;
if ( V_16 -> V_213 == V_242 )
V_241 = 1 ;
else if ( V_16 -> V_213 == V_214 )
V_241 = 2 ;
else
V_241 = V_243 ;
for ( V_5 = 0 ; V_5 < V_241 ; V_5 ++ ) {
V_55 = F_132 ( V_189 , V_5 ) ;
if ( V_55 <= 0 ) {
if ( V_16 -> V_213 == V_244 ) {
V_241 = V_5 ;
V_16 -> V_164 = V_241 / 2 ;
V_16 -> V_161 = V_241 / 2 ;
V_16 -> V_165 = V_241 / 2 ;
break;
}
F_101 ( V_20 , L_16 ) ;
V_55 = V_55 ? : - V_245 ;
return V_55 ;
}
V_16 -> V_223 [ V_5 ] = V_55 ;
}
return 0 ;
}
static int F_133 ( struct V_15 * V_16 )
{
int V_55 ;
if ( V_16 -> V_213 == V_244 )
return 0 ;
if ( ! F_134 ( V_246 ) )
return 0 ;
V_55 = F_135 ( V_16 -> V_18 ) ;
if ( ! V_55 )
V_16 -> V_247 = true ;
return 0 ;
}
static void F_136 ( struct V_15 * V_16 )
{
struct V_19 * V_20 = & V_16 -> V_189 -> V_20 ;
if ( V_16 -> V_213 != V_244 )
return;
V_16 -> V_248 = F_137 ( V_20 , L_17 , V_249 ) ;
if ( F_138 ( V_16 -> V_248 ) )
V_16 -> V_248 = F_137 ( V_20 , L_18 , V_249 ) ;
}
static int F_139 ( struct V_15 * V_16 )
{
struct V_240 * V_189 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_250 * V_251 ;
void T_10 * V_252 ;
T_1 V_118 ;
int V_55 = 0 ;
V_189 = V_16 -> V_189 ;
V_20 = & V_189 -> V_20 ;
V_18 = V_16 -> V_18 ;
V_251 = F_140 ( V_189 , V_253 , V_254 ) ;
if ( ! V_251 ) {
F_101 ( V_20 , L_19 ) ;
return - V_255 ;
}
V_16 -> V_252 = F_141 ( V_20 , V_251 -> V_256 , F_142 ( V_251 ) ) ;
if ( ! V_16 -> V_252 ) {
F_101 ( V_20 , L_20 ) ;
return - V_28 ;
}
V_251 = F_140 ( V_189 , V_253 , V_257 ) ;
if ( ! V_251 ) {
F_101 ( V_20 , L_21 ) ;
return - V_255 ;
}
V_16 -> V_258 = F_141 ( V_20 , V_251 -> V_256 ,
F_142 ( V_251 ) ) ;
if ( ! V_16 -> V_258 ) {
F_101 ( V_20 , L_22 ) ;
return - V_28 ;
}
V_251 = F_140 ( V_189 , V_253 , V_259 ) ;
if ( ! V_251 ) {
F_101 ( V_20 , L_23 ) ;
return - V_255 ;
}
V_16 -> V_195 = F_141 ( V_20 , V_251 -> V_256 ,
F_142 ( V_251 ) ) ;
if ( ! V_16 -> V_195 ) {
F_101 ( V_20 , L_24 ) ;
return - V_28 ;
}
if ( V_20 -> V_236 )
F_126 ( V_20 , V_16 ) ;
#ifdef F_143
else
F_122 ( V_20 , V_16 ) ;
#endif
if ( ! F_144 ( V_20 , V_18 -> V_260 , V_261 ) )
F_145 ( V_18 ) ;
memcpy ( V_18 -> V_262 , V_18 -> V_260 , V_18 -> V_263 ) ;
V_16 -> V_213 = F_146 ( V_20 ) ;
if ( V_16 -> V_213 < 0 ) {
F_101 ( V_20 , L_25 ) ;
return V_16 -> V_213 ;
}
if ( V_16 -> V_213 != V_242 &&
V_16 -> V_213 != V_214 &&
V_16 -> V_213 != V_244 ) {
F_101 ( V_20 , L_26 ) ;
return - V_255 ;
}
V_55 = F_129 ( V_16 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_130 ( V_16 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_131 ( V_16 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_133 ( V_16 ) ;
if ( V_55 )
return V_55 ;
F_136 ( V_16 ) ;
V_16 -> V_264 = F_147 ( & V_189 -> V_20 , NULL ) ;
if ( F_138 ( V_16 -> V_264 ) ) {
F_148 ( V_20 , L_27 ) ;
}
if ( V_16 -> V_213 != V_244 )
V_252 = V_16 -> V_252 - ( V_16 -> V_216 * V_265 ) ;
else
V_252 = V_16 -> V_252 ;
V_16 -> V_266 = V_252 + V_267 ;
V_16 -> V_268 . V_269 = V_252 + V_270 ;
V_16 -> V_271 = V_252 + V_272 ;
V_16 -> V_273 = V_252 + V_274 ;
if ( V_16 -> V_213 == V_242 ||
V_16 -> V_213 == V_214 ) {
V_16 -> V_275 = V_16 -> V_252 + V_276 ;
V_118 = ( V_16 -> V_190 == V_212 ) ?
V_277 :
V_278 ;
V_16 -> V_279 = V_252 + V_118 ;
} else {
V_16 -> V_275 = V_252 + V_280 ;
V_16 -> V_279 = V_252 + V_281 ;
V_16 -> V_282 = V_252 + V_283 ;
}
V_16 -> V_284 = V_285 ;
return 0 ;
}
static int F_149 ( struct V_15 * V_16 )
{
struct V_286 * V_287 = & V_16 -> V_268 ;
struct V_17 * V_18 = V_16 -> V_18 ;
struct V_1 * V_2 ;
T_3 V_10 ;
int V_5 , V_55 ;
V_55 = V_16 -> V_181 -> V_160 ( V_16 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_116 ( V_18 ) ;
if ( V_55 ) {
F_12 ( V_18 , L_28 ) ;
return V_55 ;
}
for ( V_5 = 0 ; V_5 < V_16 -> V_164 ; V_5 ++ ) {
V_2 = V_16 -> V_46 [ V_5 ] -> V_2 ;
F_1 ( V_2 ) ;
V_55 = F_4 ( V_2 , V_16 -> V_284 ) ;
if ( V_55 )
goto V_222;
}
V_10 = F_118 ( V_16 -> V_46 [ 0 ] ) ;
V_2 = V_16 -> V_46 [ 0 ] -> V_2 ;
if ( V_16 -> V_213 == V_244 ) {
V_287 -> V_288 = 512 ;
V_287 -> V_289 = 1024 ;
V_287 -> V_290 = 3 ;
V_287 -> V_291 = V_292 ;
V_287 -> V_293 . V_294 = 0 ;
V_287 -> V_293 . V_295 = 0 ;
V_287 -> V_296 = 8 ;
V_55 = V_16 -> V_297 -> V_298 ( V_16 ) ;
if ( V_55 ) {
F_12 ( V_18 , L_29 ) ;
goto V_222;
}
} else {
V_16 -> V_181 -> V_299 ( V_16 , V_10 , V_2 -> V_192 ) ;
}
V_16 -> V_300 = V_301 ;
V_16 -> V_73 -> V_302 ( V_16 ) ;
return V_55 ;
V_222:
F_99 ( V_16 ) ;
return V_55 ;
}
static void F_150 ( struct V_15 * V_16 )
{
switch ( V_16 -> V_213 ) {
case V_242 :
V_16 -> V_73 = & V_303 ;
V_16 -> V_181 = & V_304 ;
V_16 -> V_305 = V_306 ;
V_16 -> V_164 = 1 ;
V_16 -> V_161 = 1 ;
V_16 -> V_165 = 0 ;
break;
case V_214 :
V_16 -> V_73 = & V_307 ;
V_16 -> V_181 = & V_308 ;
V_16 -> V_305 = V_309 ;
V_16 -> V_164 = 1 ;
V_16 -> V_161 = 1 ;
V_16 -> V_165 = 1 ;
break;
default:
V_16 -> V_73 = & V_310 ;
V_16 -> V_181 = & V_311 ;
V_16 -> V_297 = & V_312 ;
V_16 -> V_305 = V_313 ;
if ( ! V_16 -> V_164 ) {
V_16 -> V_164 = V_314 ;
V_16 -> V_161 = V_315 ;
V_16 -> V_165 = V_316 ;
}
break;
}
if ( V_16 -> V_190 == V_212 ) {
switch ( V_16 -> V_216 ) {
case 0 :
if ( V_16 -> V_213 == V_244 ) {
V_16 -> V_218 = V_317 ;
V_16 -> V_220 = V_318 ;
V_16 -> V_221 = V_319 ;
V_16 -> V_197 = V_320 ;
} else {
V_16 -> V_218 = V_321 ;
V_16 -> V_220 = V_322 ;
V_16 -> V_221 = V_323 ;
V_16 -> V_197 = V_320 ;
}
break;
case 1 :
if ( V_16 -> V_213 == V_244 ) {
V_16 -> V_218 = V_324 ;
V_16 -> V_220 = V_325 ;
V_16 -> V_221 = V_326 ;
V_16 -> V_197 = V_327 ;
} else {
V_16 -> V_218 = V_328 ;
V_16 -> V_220 = V_329 ;
V_16 -> V_221 = V_330 ;
V_16 -> V_197 = V_331 ;
}
break;
default:
break;
}
V_16 -> V_37 = & V_332 ;
} else {
switch ( V_16 -> V_216 ) {
case 0 :
V_16 -> V_218 = V_317 ;
V_16 -> V_220 = V_318 ;
V_16 -> V_221 = V_319 ;
V_16 -> V_197 = V_333 ;
break;
case 1 :
V_16 -> V_218 = V_334 ;
V_16 -> V_220 = V_335 ;
V_16 -> V_221 = V_336 ;
V_16 -> V_197 = V_337 ;
break;
default:
break;
}
V_16 -> V_305 = V_313 ;
V_16 -> V_37 = & V_338 ;
}
}
static void F_151 ( struct V_15 * V_16 )
{
struct V_157 * V_47 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_16 -> V_164 ; V_5 ++ ) {
V_47 = & V_16 -> V_46 [ V_5 ] -> V_47 ;
F_152 ( V_16 -> V_18 , V_47 , F_68 ,
V_339 ) ;
}
for ( V_5 = 0 ; V_5 < V_16 -> V_165 ; V_5 ++ ) {
V_47 = & V_16 -> V_111 [ V_5 ] -> V_49 -> V_47 ;
F_152 ( V_16 -> V_18 , V_47 , F_68 ,
V_339 ) ;
}
}
static int F_153 ( struct V_240 * V_189 )
{
struct V_17 * V_18 ;
struct V_15 * V_16 ;
struct V_19 * V_20 = & V_189 -> V_20 ;
void (* F_154)( struct V_340 * );
const struct V_341 * V_342 ;
int V_55 ;
V_18 = F_155 ( sizeof( struct V_15 ) ,
V_314 , V_315 ) ;
if ( ! V_18 )
return - V_28 ;
V_16 = F_6 ( V_18 ) ;
V_16 -> V_189 = V_189 ;
V_16 -> V_18 = V_18 ;
F_156 ( V_18 , V_20 ) ;
F_157 ( V_189 , V_16 ) ;
V_18 -> V_343 = & V_344 ;
F_158 ( V_18 ) ;
V_18 -> V_87 |= V_88 |
V_345 |
V_346 |
V_347 ;
V_342 = F_159 ( V_348 , & V_189 -> V_20 ) ;
if ( V_342 ) {
V_16 -> V_190 = (enum V_349 ) V_342 -> V_29 ;
}
#ifdef F_143
else {
const struct V_350 * V_351 ;
V_351 = F_160 ( V_352 , & V_189 -> V_20 ) ;
if ( V_351 )
V_16 -> V_190 = (enum V_349 ) V_351 -> V_353 ;
}
#endif
if ( ! V_16 -> V_190 ) {
V_55 = - V_255 ;
goto V_222;
}
V_55 = F_139 ( V_16 ) ;
if ( V_55 )
goto V_222;
F_150 ( V_16 ) ;
if ( V_16 -> V_213 == V_244 ) {
V_18 -> V_87 |= V_91 ;
F_161 ( & V_16 -> V_66 ) ;
}
V_18 -> V_354 = V_18 -> V_87 ;
V_55 = F_162 ( V_20 , F_163 ( 64 ) ) ;
if ( V_55 ) {
F_12 ( V_18 , L_30 ) ;
goto V_222;
}
V_55 = F_149 ( V_16 ) ;
if ( V_55 )
goto V_222;
F_154 = V_16 -> V_73 -> F_154 ;
if ( V_16 -> V_213 == V_244 ) {
F_164 ( & V_16 -> V_172 , F_154 ) ;
} else if ( ! V_16 -> V_247 ) {
if ( V_16 -> V_213 == V_242 )
V_55 = F_165 ( V_16 ) ;
else
F_164 ( & V_16 -> V_172 , F_154 ) ;
if ( V_55 )
goto V_355;
}
F_151 ( V_16 ) ;
V_55 = F_166 ( V_18 ) ;
if ( V_55 ) {
F_12 ( V_18 , L_31 ) ;
goto V_356;
}
return 0 ;
V_356:
if ( V_16 -> V_247 )
F_167 ( V_16 ) ;
else if ( V_16 -> V_213 == V_242 )
F_168 ( V_16 ) ;
V_355:
F_99 ( V_16 ) ;
V_222:
F_169 ( V_18 ) ;
return V_55 ;
}
static int F_170 ( struct V_240 * V_189 )
{
struct V_15 * V_16 ;
struct V_17 * V_18 ;
V_16 = F_171 ( V_189 ) ;
V_18 = V_16 -> V_18 ;
F_172 () ;
if ( F_173 ( V_18 ) )
F_174 ( V_18 ) ;
F_175 () ;
if ( V_16 -> V_247 )
F_167 ( V_16 ) ;
else if ( V_16 -> V_213 == V_242 )
F_168 ( V_16 ) ;
F_176 ( V_18 ) ;
V_16 -> V_181 -> V_357 ( V_16 ) ;
F_99 ( V_16 ) ;
F_169 ( V_18 ) ;
return 0 ;
}
static void F_177 ( struct V_240 * V_189 )
{
struct V_15 * V_16 ;
V_16 = F_171 ( V_189 ) ;
if ( ! V_16 )
return;
if ( ! V_16 -> V_18 )
return;
F_170 ( V_189 ) ;
}
