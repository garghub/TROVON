unsigned long F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
int V_4 = V_5 ;
int V_6 = 0 ;
if ( V_3 < V_7 )
V_4 = V_8 [ V_3 ] ;
if ( V_4 != V_5 )
V_6 = V_2 -> V_6 [ V_4 ] ;
if ( V_6 <= 0 )
return 2 * 60 * V_9 ;
else
return V_6 ;
}
T_2 F_2 ( struct V_1 * V_2 , const T_3 * V_10 , T_4 V_11 ,
unsigned int V_12 )
{
T_2 V_13 ;
T_1 V_14 , V_3 ;
unsigned long V_15 ;
if ( V_11 < V_16 )
return - V_17 ;
if ( V_11 > V_18 )
V_11 = V_18 ;
V_14 = F_3 ( * ( ( V_19 * ) ( V_10 + 2 ) ) ) ;
V_3 = F_3 ( * ( ( V_19 * ) ( V_10 + 6 ) ) ) ;
if ( V_14 == 0 )
return - V_20 ;
if ( V_14 > V_11 ) {
F_4 ( & V_2 -> V_21 ,
L_1 , V_14 , V_11 ) ;
return - V_22 ;
}
if ( ! ( V_12 & V_23 ) )
F_5 ( & V_2 -> V_24 ) ;
if ( V_2 -> V_21 . V_25 )
F_6 ( V_2 -> V_21 . V_25 ) ;
V_13 = V_2 -> V_26 -> V_27 ( V_2 , ( T_3 * ) V_10 , V_14 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_2 -> V_21 ,
L_2 , V_13 ) ;
goto V_28;
}
if ( V_2 -> V_12 & V_29 )
goto V_30;
if ( V_2 -> V_12 & V_31 )
V_15 = V_32 + F_7 ( V_2 , V_3 ) ;
else
V_15 = V_32 + F_1 ( V_2 , V_3 ) ;
do {
T_3 V_33 = V_2 -> V_26 -> V_33 ( V_2 ) ;
if ( ( V_33 & V_2 -> V_26 -> V_34 ) ==
V_2 -> V_26 -> V_35 )
goto V_30;
if ( V_2 -> V_26 -> V_36 ( V_2 , V_33 ) ) {
F_4 ( & V_2 -> V_21 , L_3 ) ;
V_13 = - V_37 ;
goto V_28;
}
F_8 ( V_38 ) ;
F_9 () ;
} while ( F_10 ( V_32 , V_15 ) );
V_2 -> V_26 -> V_39 ( V_2 ) ;
F_4 ( & V_2 -> V_21 , L_4 ) ;
V_13 = - V_40 ;
goto V_28;
V_30:
V_13 = V_2 -> V_26 -> V_41 ( V_2 , ( T_3 * ) V_10 , V_11 ) ;
if ( V_13 < 0 )
F_4 ( & V_2 -> V_21 ,
L_5 , V_13 ) ;
V_28:
if ( V_2 -> V_21 . V_25 )
F_11 ( V_2 -> V_21 . V_25 ) ;
if ( ! ( V_12 & V_23 ) )
F_12 ( & V_2 -> V_24 ) ;
return V_13 ;
}
T_2 F_13 ( struct V_1 * V_2 , const void * V_10 ,
T_4 V_11 , T_4 V_42 ,
unsigned int V_12 , const char * V_43 )
{
const struct V_44 * V_45 ;
int V_46 ;
T_2 V_47 ;
V_47 = F_2 ( V_2 , ( const T_3 * ) V_10 , V_11 , V_12 ) ;
if ( V_47 < 0 )
return V_47 ;
else if ( V_47 < V_16 )
return - V_48 ;
V_45 = V_10 ;
if ( V_47 != F_3 ( V_45 -> V_49 ) )
return - V_48 ;
V_46 = F_3 ( V_45 -> V_50 ) ;
if ( V_46 != 0 && V_43 )
F_4 ( & V_2 -> V_21 , L_6 , V_46 ,
V_43 ) ;
if ( V_46 )
return V_46 ;
if ( V_47 < V_42 + V_16 )
return - V_48 ;
return 0 ;
}
T_2 F_14 ( struct V_1 * V_2 , T_1 V_51 , T_5 * V_52 ,
const char * V_43 , T_4 V_53 )
{
struct V_54 V_55 ;
int V_13 ;
V_55 . V_45 . V_56 = V_57 ;
if ( V_51 == V_58 ||
V_51 == V_59 ) {
V_55 . V_60 . V_61 . V_52 = F_15 ( V_51 ) ;
V_55 . V_60 . V_61 . V_62 = F_15 ( 0 ) ;
V_55 . V_45 . V_56 . V_49 -= F_15 ( sizeof( V_19 ) ) ;
} else {
if ( V_51 == V_63 ||
V_51 == V_64 )
V_55 . V_60 . V_61 . V_52 =
F_15 ( V_65 ) ;
else
V_55 . V_60 . V_61 . V_52 =
F_15 ( V_66 ) ;
V_55 . V_60 . V_61 . V_62 = F_15 ( 4 ) ;
V_55 . V_60 . V_61 . V_67 = F_15 ( V_51 ) ;
}
V_13 = F_13 ( V_2 , & V_55 , V_68 ,
V_53 , 0 , V_43 ) ;
if ( ! V_13 )
* V_52 = V_55 . V_60 . V_69 . V_52 ;
return V_13 ;
}
static int F_16 ( struct V_1 * V_2 , T_6 V_70 )
{
struct V_54 V_71 ;
V_71 . V_45 . V_56 = V_72 ;
V_71 . V_60 . V_73 . V_70 = V_70 ;
return F_13 ( V_2 , & V_71 , V_68 , 0 ,
0 , L_7 ) ;
}
int F_17 ( struct V_1 * V_2 )
{
T_5 V_52 ;
unsigned long V_74 [ 4 ] , V_75 [ 4 ] , V_76 [ 4 ] ;
T_2 V_13 ;
if ( V_2 -> V_12 & V_77 )
return 0 ;
if ( V_2 -> V_12 & V_31 ) {
V_2 -> V_78 = F_18 ( V_79 ) ;
V_2 -> V_80 = F_18 ( V_81 ) ;
V_2 -> V_82 = F_18 ( V_83 ) ;
V_2 -> V_84 = F_18 ( V_85 ) ;
V_2 -> V_6 [ V_86 ] =
F_18 ( V_87 ) ;
V_2 -> V_6 [ V_88 ] =
F_18 ( V_89 ) ;
V_2 -> V_6 [ V_90 ] =
F_18 ( V_91 ) ;
V_2 -> V_12 |= V_77 ;
return 0 ;
}
V_13 = F_14 ( V_2 , V_92 , & V_52 , NULL ,
sizeof( V_52 . V_93 ) ) ;
if ( V_13 == V_94 ) {
F_19 ( & V_2 -> V_21 , L_8 ) ;
if ( F_16 ( V_2 , V_95 ) )
return V_13 ;
V_13 = F_14 ( V_2 , V_92 , & V_52 ,
L_9 ,
sizeof( V_52 . V_93 ) ) ;
}
if ( V_13 ) {
F_4 ( & V_2 -> V_21 ,
L_10 ,
V_13 ) ;
return V_13 ;
}
V_74 [ 0 ] = F_20 ( V_2 -> V_78 ) ;
V_74 [ 1 ] = F_20 ( V_2 -> V_80 ) ;
V_74 [ 2 ] = F_20 ( V_2 -> V_82 ) ;
V_74 [ 3 ] = F_20 ( V_2 -> V_84 ) ;
V_75 [ 0 ] = F_3 ( V_52 . V_93 . V_96 ) ;
V_75 [ 1 ] = F_3 ( V_52 . V_93 . V_97 ) ;
V_75 [ 2 ] = F_3 ( V_52 . V_93 . V_98 ) ;
V_75 [ 3 ] = F_3 ( V_52 . V_93 . V_99 ) ;
memcpy ( V_76 , V_75 , sizeof( V_76 ) ) ;
if ( V_2 -> V_26 -> V_100 != NULL )
V_2 -> V_101 =
V_2 -> V_26 -> V_100 ( V_2 , V_76 ) ;
if ( ! V_2 -> V_101 ) {
int V_102 ;
for ( V_102 = 0 ; V_102 < F_21 ( V_76 ) ; V_102 ++ ) {
if ( V_76 [ V_102 ] )
continue;
V_76 [ V_102 ] = V_74 [ V_102 ] ;
V_2 -> V_101 = true ;
}
if ( V_76 [ 0 ] != 0 && V_76 [ 0 ] < 1000 ) {
for ( V_102 = 0 ; V_102 != F_21 ( V_76 ) ; V_102 ++ )
V_76 [ V_102 ] *= 1000 ;
V_2 -> V_101 = true ;
}
}
if ( V_2 -> V_101 ) {
F_19 ( & V_2 -> V_21 ,
V_103 L_11 ,
V_75 [ 0 ] , V_76 [ 0 ] ,
V_75 [ 1 ] , V_76 [ 1 ] ,
V_75 [ 2 ] , V_76 [ 2 ] ,
V_75 [ 3 ] , V_76 [ 3 ] ) ;
}
V_2 -> V_78 = F_22 ( V_76 [ 0 ] ) ;
V_2 -> V_80 = F_22 ( V_76 [ 1 ] ) ;
V_2 -> V_82 = F_22 ( V_76 [ 2 ] ) ;
V_2 -> V_84 = F_22 ( V_76 [ 3 ] ) ;
V_13 = F_14 ( V_2 , V_104 , & V_52 ,
L_12 ,
sizeof( V_52 . V_6 ) ) ;
if ( V_13 )
return V_13 ;
V_2 -> V_6 [ V_86 ] =
F_22 ( F_3 ( V_52 . V_6 . V_105 ) ) ;
V_2 -> V_6 [ V_88 ] =
F_22 ( F_3 ( V_52 . V_6 . V_106 ) ) ;
V_2 -> V_6 [ V_90 ] =
F_22 ( F_3 ( V_52 . V_6 . V_107 ) ) ;
if ( V_2 -> V_6 [ V_86 ] < ( V_9 / 100 ) ) {
V_2 -> V_6 [ V_86 ] = V_9 ;
V_2 -> V_6 [ V_88 ] *= 1000 ;
V_2 -> V_6 [ V_90 ] *= 1000 ;
V_2 -> V_108 = true ;
F_19 ( & V_2 -> V_21 , L_13 ) ;
}
V_2 -> V_12 |= V_77 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_13 ;
struct V_54 V_109 ;
V_109 . V_45 . V_56 = V_110 ;
V_13 = F_13 ( V_2 , & V_109 , V_111 , 0 , 0 ,
L_14 ) ;
return V_13 ;
}
int F_24 ( struct V_1 * V_2 , int V_112 , T_3 * V_113 )
{
int V_13 ;
struct V_54 V_109 ;
V_109 . V_45 . V_56 = V_114 ;
V_109 . V_60 . V_115 . V_112 = F_15 ( V_112 ) ;
V_13 = F_13 ( V_2 , & V_109 , V_116 ,
V_117 , 0 ,
L_15 ) ;
if ( V_13 == 0 )
memcpy ( V_113 , V_109 . V_60 . V_118 . V_119 ,
V_120 ) ;
return V_13 ;
}
int F_25 ( T_1 V_121 )
{
struct V_1 * V_2 ;
int V_13 ;
V_2 = F_26 ( V_121 ) ;
if ( V_2 == NULL )
return - V_122 ;
V_13 = ( V_2 -> V_12 & V_31 ) != 0 ;
F_27 ( V_2 ) ;
return V_13 ;
}
int F_28 ( T_1 V_121 , int V_112 , T_3 * V_113 )
{
struct V_1 * V_2 ;
int V_13 ;
V_2 = F_26 ( V_121 ) ;
if ( V_2 == NULL )
return - V_122 ;
if ( V_2 -> V_12 & V_31 )
V_13 = F_29 ( V_2 , V_112 , V_113 ) ;
else
V_13 = F_24 ( V_2 , V_112 , V_113 ) ;
F_27 ( V_2 ) ;
return V_13 ;
}
int F_30 ( T_1 V_121 , int V_112 , const T_3 * V_123 )
{
struct V_54 V_109 ;
int V_13 ;
struct V_1 * V_2 ;
struct V_124 V_125 [ F_21 ( V_2 -> V_126 ) ] ;
T_1 V_14 = 0 ;
int V_102 ;
V_2 = F_26 ( V_121 ) ;
if ( V_2 == NULL )
return - V_122 ;
if ( V_2 -> V_12 & V_31 ) {
memset ( V_125 , 0 , sizeof( V_125 ) ) ;
for ( V_102 = 0 ; V_102 < F_21 ( V_2 -> V_126 ) &&
V_2 -> V_126 [ V_102 ] != V_127 ; V_102 ++ ) {
V_125 [ V_102 ] . V_128 = V_2 -> V_126 [ V_102 ] ;
memcpy ( V_125 [ V_102 ] . V_129 , V_123 , V_120 ) ;
V_14 ++ ;
}
V_13 = F_31 ( V_2 , V_112 , V_14 , V_125 ) ;
F_27 ( V_2 ) ;
return V_13 ;
}
V_109 . V_45 . V_56 = V_130 ;
V_109 . V_60 . V_131 . V_112 = F_15 ( V_112 ) ;
memcpy ( V_109 . V_60 . V_131 . V_123 , V_123 , V_120 ) ;
V_13 = F_13 ( V_2 , & V_109 , V_132 ,
V_133 , 0 ,
L_16 ) ;
F_27 ( V_2 ) ;
return V_13 ;
}
int F_32 ( struct V_1 * V_2 )
{
int V_13 ;
unsigned int V_134 ;
unsigned int V_135 = 100 ;
unsigned long V_6 ;
T_3 V_136 [ V_120 ] ;
V_6 = F_1 ( V_2 , V_137 ) ;
V_134 = F_33 ( V_6 ) / V_135 ;
V_13 = F_23 ( V_2 ) ;
if ( V_13 )
return V_13 ;
do {
V_13 = F_24 ( V_2 , 0 , V_136 ) ;
if ( V_13 == - V_40 ) {
F_19 (
& V_2 -> V_21 , V_103
L_17 ) ;
F_8 ( V_135 ) ;
continue;
}
if ( V_13 == V_138 || V_13 == V_139 ) {
F_19 ( & V_2 -> V_21 ,
L_18 , V_13 ) ;
return 0 ;
}
if ( V_13 != V_140 )
return V_13 ;
F_8 ( V_135 ) ;
} while ( -- V_134 > 0 );
return V_13 ;
}
int F_34 ( struct V_1 * V_2 )
{
int V_13 ;
V_13 = F_17 ( V_2 ) ;
if ( V_13 )
goto V_28;
V_13 = F_32 ( V_2 ) ;
if ( V_13 ) {
F_4 ( & V_2 -> V_21 , L_19 ) ;
goto V_28;
}
return V_13 ;
V_28:
if ( V_13 > 0 )
V_13 = - V_122 ;
return V_13 ;
}
int F_35 ( T_1 V_121 , void * V_109 , T_4 V_141 )
{
struct V_1 * V_2 ;
int V_13 ;
V_2 = F_26 ( V_121 ) ;
if ( V_2 == NULL )
return - V_122 ;
V_13 = F_13 ( V_2 , V_109 , V_141 , 0 , 0 , L_20 ) ;
F_27 ( V_2 ) ;
return V_13 ;
}
static bool F_36 ( struct V_1 * V_2 , T_3 V_142 ,
bool V_143 , bool * V_144 )
{
T_3 V_33 = V_2 -> V_26 -> V_33 ( V_2 ) ;
* V_144 = false ;
if ( ( V_33 & V_142 ) == V_142 )
return true ;
if ( V_143 && V_2 -> V_26 -> V_36 ( V_2 , V_33 ) ) {
* V_144 = true ;
return true ;
}
return false ;
}
int F_37 ( struct V_1 * V_2 , T_3 V_142 , unsigned long V_93 ,
T_7 * V_145 , bool V_143 )
{
unsigned long V_15 ;
long V_13 ;
T_3 V_33 ;
bool V_144 = false ;
V_33 = V_2 -> V_26 -> V_33 ( V_2 ) ;
if ( ( V_33 & V_142 ) == V_142 )
return 0 ;
V_15 = V_32 + V_93 ;
if ( V_2 -> V_12 & V_29 ) {
V_146:
V_93 = V_15 - V_32 ;
if ( ( long ) V_93 <= 0 )
return - V_40 ;
V_13 = F_38 ( * V_145 ,
F_36 ( V_2 , V_142 , V_143 ,
& V_144 ) ,
V_93 ) ;
if ( V_13 > 0 ) {
if ( V_144 )
return - V_37 ;
return 0 ;
}
if ( V_13 == - V_147 && F_39 ( V_148 ) ) {
F_40 ( V_149 ) ;
goto V_146;
}
} else {
do {
F_8 ( V_38 ) ;
V_33 = V_2 -> V_26 -> V_33 ( V_2 ) ;
if ( ( V_33 & V_142 ) == V_142 )
return 0 ;
} while ( F_10 ( V_32 , V_15 ) );
}
return - V_40 ;
}
int F_41 ( struct V_150 * V_21 )
{
struct V_1 * V_2 = F_42 ( V_21 ) ;
struct V_54 V_109 ;
int V_13 , V_151 ;
T_3 V_152 [ V_120 ] = { 0 } ;
if ( V_2 == NULL )
return - V_122 ;
if ( V_2 -> V_12 & V_31 ) {
F_43 ( V_2 , V_153 ) ;
return 0 ;
}
if ( V_154 ) {
V_109 . V_45 . V_56 = V_130 ;
V_109 . V_60 . V_131 . V_112 = F_15 ( V_154 ) ;
memcpy ( V_109 . V_60 . V_131 . V_123 , V_152 ,
V_120 ) ;
V_13 = F_13 ( V_2 , & V_109 , V_132 ,
V_133 , 0 ,
L_21 ) ;
}
for ( V_151 = 0 ; V_151 < V_155 ; V_151 ++ ) {
V_109 . V_45 . V_56 = V_156 ;
V_13 = F_13 ( V_2 , & V_109 , V_157 , 0 ,
0 , NULL ) ;
if ( V_13 != V_158 )
break;
F_8 ( V_159 ) ;
}
if ( V_13 )
F_4 ( & V_2 -> V_21 ,
L_22 , V_13 ) ;
else if ( V_151 > 0 )
F_44 ( & V_2 -> V_21 , L_23 ,
V_151 * V_159 ) ;
return V_13 ;
}
int F_45 ( struct V_150 * V_21 )
{
struct V_1 * V_2 = F_42 ( V_21 ) ;
if ( V_2 == NULL )
return - V_122 ;
return 0 ;
}
int F_46 ( T_1 V_121 , T_3 * V_28 , T_4 V_160 )
{
struct V_1 * V_2 ;
struct V_54 V_55 ;
T_1 V_161 , V_162 = F_47 ( T_1 , V_160 , V_163 ) , V_164 ;
int V_46 , V_165 = 0 , V_166 = 5 ;
T_3 * V_167 = V_28 ;
if ( ! V_28 || ! V_162 || V_160 > V_163 )
return - V_17 ;
V_2 = F_26 ( V_121 ) ;
if ( V_2 == NULL )
return - V_122 ;
if ( V_2 -> V_12 & V_31 ) {
V_46 = F_48 ( V_2 , V_28 , V_160 ) ;
F_27 ( V_2 ) ;
return V_46 ;
}
do {
V_55 . V_45 . V_56 = V_168 ;
V_55 . V_60 . V_169 . V_162 = F_15 ( V_162 ) ;
V_46 = F_13 ( V_2 , & V_55 ,
V_170 + V_162 ,
F_49 ( struct V_171 ,
V_172 ) ,
0 , L_24 ) ;
if ( V_46 )
break;
V_161 = F_3 ( V_55 . V_60 . V_173 . V_174 ) ;
V_164 = F_3 ( V_55 . V_45 . V_28 . V_49 ) ;
if ( V_164 < F_49 ( struct V_171 , V_172 ) +
V_161 ) {
V_165 = - V_48 ;
break;
}
memcpy ( V_167 , V_55 . V_60 . V_173 . V_172 , V_161 ) ;
V_167 += V_161 ;
V_165 += V_161 ;
V_162 -= V_161 ;
} while ( V_166 -- && V_165 < V_160 );
F_27 ( V_2 ) ;
return V_165 ? V_165 : - V_175 ;
}
int F_50 ( T_1 V_121 , struct V_176 * V_177 ,
struct V_178 * V_179 )
{
struct V_1 * V_2 ;
int V_13 ;
V_2 = F_26 ( V_121 ) ;
if ( V_2 == NULL || ! ( V_2 -> V_12 & V_31 ) )
return - V_122 ;
V_13 = F_51 ( V_2 , V_177 , V_179 ) ;
F_27 ( V_2 ) ;
return V_13 ;
}
int F_52 ( T_1 V_121 , struct V_176 * V_177 ,
struct V_178 * V_179 )
{
struct V_1 * V_2 ;
int V_13 ;
V_2 = F_26 ( V_121 ) ;
if ( V_2 == NULL || ! ( V_2 -> V_12 & V_31 ) )
return - V_122 ;
V_13 = F_53 ( V_2 , V_177 , V_179 ) ;
F_27 ( V_2 ) ;
return V_13 ;
}
static int T_8 F_54 ( void )
{
int V_13 ;
V_180 = F_55 ( V_181 , L_25 ) ;
if ( F_56 ( V_180 ) ) {
F_57 ( L_26 ) ;
return F_58 ( V_180 ) ;
}
V_13 = F_59 ( & V_182 , 0 , V_183 , L_25 ) ;
if ( V_13 < 0 ) {
F_57 ( L_27 ) ;
F_60 ( V_180 ) ;
return V_13 ;
}
return 0 ;
}
static void T_9 F_61 ( void )
{
F_62 ( & V_184 ) ;
F_60 ( V_180 ) ;
F_63 ( V_182 , V_183 ) ;
}
