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
static bool F_2 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
const T_2 * V_12 ,
T_3 V_13 )
{
const struct V_14 * V_15 = ( const void * ) V_12 ;
int V_16 ;
T_1 V_17 ;
T_1 V_18 ;
unsigned int V_19 ;
if ( V_13 < V_20 )
return false ;
if ( ! V_11 )
return true ;
if ( V_2 -> V_21 & V_22 && V_2 -> V_23 ) {
V_17 = F_3 ( V_15 -> V_3 ) ;
V_16 = F_4 ( V_2 , V_17 ) ;
if ( V_16 < 0 ) {
F_5 ( & V_2 -> V_24 , L_1 ,
V_17 ) ;
return false ;
}
V_18 = V_2 -> V_25 [ V_16 ] ;
V_19 =
4 * ( ( V_18 >> V_26 ) & F_6 ( 2 , 0 ) ) ;
if ( V_13 < V_20 + 4 * V_19 )
goto V_27;
}
return true ;
V_27:
F_5 ( & V_2 -> V_24 ,
L_2 , V_28 , V_13 ) ;
return false ;
}
T_4 F_7 ( struct V_1 * V_2 , struct V_10 * V_11 ,
T_2 * V_29 , T_3 V_30 , unsigned int V_21 )
{
struct V_31 * V_15 = ( void * ) V_29 ;
int V_32 ;
T_4 V_13 = 0 ;
T_1 V_33 , V_3 ;
unsigned long V_34 ;
bool V_35 ;
if ( ! F_2 ( V_2 , V_11 , V_29 , V_30 ) )
return - V_36 ;
if ( V_30 > V_37 )
V_30 = V_37 ;
V_33 = F_3 ( * ( ( V_38 * ) ( V_29 + 2 ) ) ) ;
V_3 = F_3 ( * ( ( V_38 * ) ( V_29 + 6 ) ) ) ;
if ( V_33 == 0 )
return - V_39 ;
if ( V_33 > V_30 ) {
F_8 ( & V_2 -> V_24 ,
L_3 , V_33 , V_30 ) ;
return - V_40 ;
}
if ( ! ( V_21 & V_41 ) )
F_9 ( & V_2 -> V_42 ) ;
if ( V_2 -> V_24 . V_43 )
F_10 ( V_2 -> V_24 . V_43 ) ;
V_35 = V_2 -> V_44 == - 1 ;
if ( V_35 && V_2 -> V_45 -> V_46 ) {
V_32 = V_2 -> V_45 -> V_46 ( V_2 , 0 ) ;
if ( V_32 < 0 )
goto V_47;
V_2 -> V_44 = V_32 ;
}
V_32 = F_11 ( V_2 , V_11 , V_3 , V_29 ) ;
if ( V_32 )
goto V_48;
V_32 = V_2 -> V_45 -> V_49 ( V_2 , ( T_2 * ) V_29 , V_33 ) ;
if ( V_32 < 0 ) {
F_8 ( & V_2 -> V_24 ,
L_4 , V_32 ) ;
goto V_48;
}
if ( V_2 -> V_21 & V_50 )
goto V_51;
if ( V_2 -> V_21 & V_22 )
V_34 = V_52 + F_12 ( V_2 , V_3 ) ;
else
V_34 = V_52 + F_1 ( V_2 , V_3 ) ;
do {
T_2 V_53 = V_2 -> V_45 -> V_53 ( V_2 ) ;
if ( ( V_53 & V_2 -> V_45 -> V_54 ) ==
V_2 -> V_45 -> V_55 )
goto V_51;
if ( V_2 -> V_45 -> V_56 ( V_2 , V_53 ) ) {
F_8 ( & V_2 -> V_24 , L_5 ) ;
V_32 = - V_57 ;
goto V_48;
}
F_13 ( V_58 ) ;
F_14 () ;
} while ( F_15 ( V_52 , V_34 ) );
V_2 -> V_45 -> V_59 ( V_2 ) ;
F_8 ( & V_2 -> V_24 , L_6 ) ;
V_32 = - V_60 ;
goto V_48;
V_51:
V_13 = V_2 -> V_45 -> V_61 ( V_2 , ( T_2 * ) V_29 , V_30 ) ;
if ( V_13 < 0 ) {
V_32 = V_13 ;
F_8 ( & V_2 -> V_24 ,
L_7 , V_32 ) ;
goto V_48;
} else if ( V_13 < V_20 ) {
V_32 = - V_62 ;
goto V_48;
}
if ( V_13 != F_3 ( V_15 -> V_63 ) ) {
V_32 = - V_62 ;
goto V_48;
}
V_32 = F_16 ( V_2 , V_11 , V_3 , V_29 , & V_13 ) ;
V_48:
if ( V_35 && V_2 -> V_45 -> V_64 ) {
V_2 -> V_45 -> V_64 ( V_2 , V_2 -> V_44 ) ;
V_2 -> V_44 = - 1 ;
}
V_47:
if ( V_2 -> V_24 . V_43 )
F_17 ( V_2 -> V_24 . V_43 ) ;
if ( ! ( V_21 & V_41 ) )
F_18 ( & V_2 -> V_42 ) ;
return V_32 ? V_32 : V_13 ;
}
T_4 F_19 ( struct V_1 * V_2 , struct V_10 * V_11 ,
const void * V_29 , T_3 V_30 ,
T_3 V_65 , unsigned int V_21 ,
const char * V_66 )
{
const struct V_31 * V_15 = V_29 ;
int V_67 ;
T_4 V_13 ;
V_13 = F_7 ( V_2 , V_11 , ( T_2 * ) V_29 , V_30 , V_21 ) ;
if ( V_13 < 0 )
return V_13 ;
V_67 = F_3 ( V_15 -> V_68 ) ;
if ( V_67 != 0 && V_66 )
F_8 ( & V_2 -> V_24 , L_8 , V_67 ,
V_66 ) ;
if ( V_67 )
return V_67 ;
if ( V_13 < V_65 + V_20 )
return - V_62 ;
return 0 ;
}
T_4 F_20 ( struct V_1 * V_2 , T_1 V_69 , T_5 * V_70 ,
const char * V_66 , T_3 V_71 )
{
struct V_72 V_73 ;
int V_32 ;
V_73 . V_15 . V_74 = V_75 ;
if ( V_69 == V_76 ||
V_69 == V_77 ) {
V_73 . V_78 . V_79 . V_70 = F_21 ( V_69 ) ;
V_73 . V_78 . V_79 . V_80 = F_21 ( 0 ) ;
V_73 . V_15 . V_74 . V_63 -= F_21 ( sizeof( V_38 ) ) ;
} else {
if ( V_69 == V_81 ||
V_69 == V_82 )
V_73 . V_78 . V_79 . V_70 =
F_21 ( V_83 ) ;
else
V_73 . V_78 . V_79 . V_70 =
F_21 ( V_84 ) ;
V_73 . V_78 . V_79 . V_80 = F_21 ( 4 ) ;
V_73 . V_78 . V_79 . V_85 = F_21 ( V_69 ) ;
}
V_32 = F_19 ( V_2 , NULL , & V_73 , V_86 ,
V_71 , 0 , V_66 ) ;
if ( ! V_32 )
* V_70 = V_73 . V_78 . V_87 . V_70 ;
return V_32 ;
}
static int F_22 ( struct V_1 * V_2 , T_6 V_88 )
{
struct V_72 V_89 ;
V_89 . V_15 . V_74 = V_90 ;
V_89 . V_78 . V_91 . V_88 = V_88 ;
return F_19 ( V_2 , NULL , & V_89 ,
V_86 , 0 ,
0 , L_9 ) ;
}
int F_23 ( struct V_1 * V_2 )
{
T_5 V_70 ;
unsigned long V_92 [ 4 ] , V_93 [ 4 ] , V_94 [ 4 ] ;
T_4 V_32 ;
if ( V_2 -> V_21 & V_95 )
return 0 ;
if ( V_2 -> V_21 & V_22 ) {
V_2 -> V_96 = F_24 ( V_97 ) ;
V_2 -> V_98 = F_24 ( V_99 ) ;
V_2 -> V_100 = F_24 ( V_101 ) ;
V_2 -> V_102 = F_24 ( V_103 ) ;
V_2 -> V_6 [ V_104 ] =
F_24 ( V_105 ) ;
V_2 -> V_6 [ V_106 ] =
F_24 ( V_107 ) ;
V_2 -> V_6 [ V_108 ] =
F_24 ( V_109 ) ;
V_2 -> V_21 |= V_95 ;
return 0 ;
}
V_32 = F_20 ( V_2 , V_110 , & V_70 , NULL ,
sizeof( V_70 . V_111 ) ) ;
if ( V_32 == V_112 ) {
F_25 ( & V_2 -> V_24 , L_10 ) ;
if ( F_22 ( V_2 , V_113 ) )
return V_32 ;
V_32 = F_20 ( V_2 , V_110 , & V_70 ,
L_11 ,
sizeof( V_70 . V_111 ) ) ;
}
if ( V_32 ) {
F_8 ( & V_2 -> V_24 ,
L_12 ,
V_32 ) ;
return V_32 ;
}
V_92 [ 0 ] = F_26 ( V_2 -> V_96 ) ;
V_92 [ 1 ] = F_26 ( V_2 -> V_98 ) ;
V_92 [ 2 ] = F_26 ( V_2 -> V_100 ) ;
V_92 [ 3 ] = F_26 ( V_2 -> V_102 ) ;
V_93 [ 0 ] = F_3 ( V_70 . V_111 . V_114 ) ;
V_93 [ 1 ] = F_3 ( V_70 . V_111 . V_115 ) ;
V_93 [ 2 ] = F_3 ( V_70 . V_111 . V_116 ) ;
V_93 [ 3 ] = F_3 ( V_70 . V_111 . V_117 ) ;
memcpy ( V_94 , V_93 , sizeof( V_94 ) ) ;
if ( V_2 -> V_45 -> V_118 != NULL )
V_2 -> V_119 =
V_2 -> V_45 -> V_118 ( V_2 , V_94 ) ;
if ( ! V_2 -> V_119 ) {
int V_16 ;
for ( V_16 = 0 ; V_16 < F_27 ( V_94 ) ; V_16 ++ ) {
if ( V_94 [ V_16 ] )
continue;
V_94 [ V_16 ] = V_92 [ V_16 ] ;
V_2 -> V_119 = true ;
}
if ( V_94 [ 0 ] != 0 && V_94 [ 0 ] < 1000 ) {
for ( V_16 = 0 ; V_16 != F_27 ( V_94 ) ; V_16 ++ )
V_94 [ V_16 ] *= 1000 ;
V_2 -> V_119 = true ;
}
}
if ( V_2 -> V_119 ) {
F_25 ( & V_2 -> V_24 ,
V_120 L_13 ,
V_93 [ 0 ] , V_94 [ 0 ] ,
V_93 [ 1 ] , V_94 [ 1 ] ,
V_93 [ 2 ] , V_94 [ 2 ] ,
V_93 [ 3 ] , V_94 [ 3 ] ) ;
}
V_2 -> V_96 = F_28 ( V_94 [ 0 ] ) ;
V_2 -> V_98 = F_28 ( V_94 [ 1 ] ) ;
V_2 -> V_100 = F_28 ( V_94 [ 2 ] ) ;
V_2 -> V_102 = F_28 ( V_94 [ 3 ] ) ;
V_32 = F_20 ( V_2 , V_121 , & V_70 ,
L_14 ,
sizeof( V_70 . V_6 ) ) ;
if ( V_32 )
return V_32 ;
V_2 -> V_6 [ V_104 ] =
F_28 ( F_3 ( V_70 . V_6 . V_122 ) ) ;
V_2 -> V_6 [ V_106 ] =
F_28 ( F_3 ( V_70 . V_6 . V_123 ) ) ;
V_2 -> V_6 [ V_108 ] =
F_28 ( F_3 ( V_70 . V_6 . V_124 ) ) ;
if ( V_2 -> V_6 [ V_104 ] < ( V_9 / 100 ) ) {
V_2 -> V_6 [ V_104 ] = V_9 ;
V_2 -> V_6 [ V_106 ] *= 1000 ;
V_2 -> V_6 [ V_108 ] *= 1000 ;
V_2 -> V_125 = true ;
F_25 ( & V_2 -> V_24 , L_15 ) ;
}
V_2 -> V_21 |= V_95 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_32 ;
struct V_72 V_12 ;
V_12 . V_15 . V_74 = V_126 ;
V_32 = F_19 ( V_2 , NULL , & V_12 , V_127 ,
0 , 0 , L_16 ) ;
return V_32 ;
}
int F_30 ( struct V_1 * V_2 , int V_128 , T_2 * V_129 )
{
int V_32 ;
struct V_72 V_12 ;
V_12 . V_15 . V_74 = V_130 ;
V_12 . V_78 . V_131 . V_128 = F_21 ( V_128 ) ;
V_32 = F_19 ( V_2 , NULL , & V_12 , V_132 ,
V_133 , 0 ,
L_17 ) ;
if ( V_32 == 0 )
memcpy ( V_129 , V_12 . V_78 . V_134 . V_135 ,
V_136 ) ;
return V_32 ;
}
int F_31 ( T_1 V_137 )
{
struct V_1 * V_2 ;
int V_32 ;
V_2 = F_32 ( V_137 ) ;
if ( V_2 == NULL )
return - V_138 ;
V_32 = ( V_2 -> V_21 & V_22 ) != 0 ;
F_33 ( V_2 ) ;
return V_32 ;
}
int F_34 ( T_1 V_137 , int V_128 , T_2 * V_129 )
{
struct V_1 * V_2 ;
int V_32 ;
V_2 = F_32 ( V_137 ) ;
if ( V_2 == NULL )
return - V_138 ;
if ( V_2 -> V_21 & V_22 )
V_32 = F_35 ( V_2 , V_128 , V_129 ) ;
else
V_32 = F_30 ( V_2 , V_128 , V_129 ) ;
F_33 ( V_2 ) ;
return V_32 ;
}
int F_36 ( T_1 V_137 , int V_128 , const T_2 * V_139 )
{
struct V_72 V_12 ;
int V_32 ;
struct V_1 * V_2 ;
struct V_140 V_141 [ F_27 ( V_2 -> V_142 ) ] ;
T_1 V_33 = 0 ;
int V_16 ;
V_2 = F_32 ( V_137 ) ;
if ( V_2 == NULL )
return - V_138 ;
if ( V_2 -> V_21 & V_22 ) {
memset ( V_141 , 0 , sizeof( V_141 ) ) ;
for ( V_16 = 0 ; V_16 < F_27 ( V_2 -> V_142 ) &&
V_2 -> V_142 [ V_16 ] != V_143 ; V_16 ++ ) {
V_141 [ V_16 ] . V_144 = V_2 -> V_142 [ V_16 ] ;
memcpy ( V_141 [ V_16 ] . V_145 , V_139 , V_136 ) ;
V_33 ++ ;
}
V_32 = F_37 ( V_2 , V_128 , V_33 , V_141 ) ;
F_33 ( V_2 ) ;
return V_32 ;
}
V_12 . V_15 . V_74 = V_146 ;
V_12 . V_78 . V_147 . V_128 = F_21 ( V_128 ) ;
memcpy ( V_12 . V_78 . V_147 . V_139 , V_139 , V_136 ) ;
V_32 = F_19 ( V_2 , NULL , & V_12 , V_148 ,
V_149 , 0 ,
L_18 ) ;
F_33 ( V_2 ) ;
return V_32 ;
}
int F_38 ( struct V_1 * V_2 )
{
int V_32 ;
unsigned int V_150 ;
unsigned int V_151 = 100 ;
unsigned long V_6 ;
T_2 V_152 [ V_136 ] ;
V_6 = F_1 ( V_2 , V_153 ) ;
V_150 = F_39 ( V_6 ) / V_151 ;
V_32 = F_29 ( V_2 ) ;
if ( V_32 )
return V_32 ;
do {
V_32 = F_30 ( V_2 , 0 , V_152 ) ;
if ( V_32 == - V_60 ) {
F_25 (
& V_2 -> V_24 , V_120
L_19 ) ;
F_13 ( V_151 ) ;
continue;
}
if ( V_32 == V_154 || V_32 == V_155 ) {
F_25 ( & V_2 -> V_24 ,
L_20 , V_32 ) ;
return 0 ;
}
if ( V_32 != V_156 )
return V_32 ;
F_13 ( V_151 ) ;
} while ( -- V_150 > 0 );
return V_32 ;
}
int F_40 ( struct V_1 * V_2 )
{
int V_32 ;
V_32 = F_23 ( V_2 ) ;
if ( V_32 )
goto V_48;
V_32 = F_38 ( V_2 ) ;
if ( V_32 ) {
F_8 ( & V_2 -> V_24 , L_21 ) ;
goto V_48;
}
return V_32 ;
V_48:
if ( V_32 > 0 )
V_32 = - V_138 ;
return V_32 ;
}
int F_41 ( T_1 V_137 , void * V_12 , T_3 V_157 )
{
struct V_1 * V_2 ;
int V_32 ;
V_2 = F_32 ( V_137 ) ;
if ( V_2 == NULL )
return - V_138 ;
V_32 = F_19 ( V_2 , NULL , V_12 , V_157 , 0 , 0 ,
L_22 ) ;
F_33 ( V_2 ) ;
return V_32 ;
}
static bool F_42 ( struct V_1 * V_2 , T_2 V_158 ,
bool V_159 , bool * V_160 )
{
T_2 V_53 = V_2 -> V_45 -> V_53 ( V_2 ) ;
* V_160 = false ;
if ( ( V_53 & V_158 ) == V_158 )
return true ;
if ( V_159 && V_2 -> V_45 -> V_56 ( V_2 , V_53 ) ) {
* V_160 = true ;
return true ;
}
return false ;
}
int F_43 ( struct V_1 * V_2 , T_2 V_158 , unsigned long V_111 ,
T_7 * V_161 , bool V_159 )
{
unsigned long V_34 ;
long V_32 ;
T_2 V_53 ;
bool V_160 = false ;
V_53 = V_2 -> V_45 -> V_53 ( V_2 ) ;
if ( ( V_53 & V_158 ) == V_158 )
return 0 ;
V_34 = V_52 + V_111 ;
if ( V_2 -> V_21 & V_50 ) {
V_162:
V_111 = V_34 - V_52 ;
if ( ( long ) V_111 <= 0 )
return - V_60 ;
V_32 = F_44 ( * V_161 ,
F_42 ( V_2 , V_158 , V_159 ,
& V_160 ) ,
V_111 ) ;
if ( V_32 > 0 ) {
if ( V_160 )
return - V_57 ;
return 0 ;
}
if ( V_32 == - V_163 && F_45 ( V_164 ) ) {
F_46 ( V_165 ) ;
goto V_162;
}
} else {
do {
F_13 ( V_58 ) ;
V_53 = V_2 -> V_45 -> V_53 ( V_2 ) ;
if ( ( V_53 & V_158 ) == V_158 )
return 0 ;
} while ( F_15 ( V_52 , V_34 ) );
}
return - V_60 ;
}
int F_47 ( struct V_166 * V_24 )
{
struct V_1 * V_2 = F_48 ( V_24 ) ;
struct V_72 V_12 ;
int V_32 , V_167 ;
T_2 V_168 [ V_136 ] = { 0 } ;
if ( V_2 == NULL )
return - V_138 ;
if ( V_2 -> V_21 & V_22 ) {
F_49 ( V_2 , V_169 ) ;
return 0 ;
}
if ( V_170 ) {
V_12 . V_15 . V_74 = V_146 ;
V_12 . V_78 . V_147 . V_128 = F_21 ( V_170 ) ;
memcpy ( V_12 . V_78 . V_147 . V_139 , V_168 ,
V_136 ) ;
V_32 = F_19 ( V_2 , NULL , & V_12 , V_148 ,
V_149 , 0 ,
L_23 ) ;
}
for ( V_167 = 0 ; V_167 < V_171 ; V_167 ++ ) {
V_12 . V_15 . V_74 = V_172 ;
V_32 = F_19 ( V_2 , NULL , & V_12 , V_173 ,
0 , 0 , NULL ) ;
if ( V_32 != V_174 )
break;
F_13 ( V_175 ) ;
}
if ( V_32 )
F_8 ( & V_2 -> V_24 ,
L_24 , V_32 ) ;
else if ( V_167 > 0 )
F_50 ( & V_2 -> V_24 , L_25 ,
V_167 * V_175 ) ;
return V_32 ;
}
int F_51 ( struct V_166 * V_24 )
{
struct V_1 * V_2 = F_48 ( V_24 ) ;
if ( V_2 == NULL )
return - V_138 ;
return 0 ;
}
int F_52 ( T_1 V_137 , T_2 * V_48 , T_3 V_176 )
{
struct V_1 * V_2 ;
struct V_72 V_73 ;
T_1 V_177 , V_178 = F_53 ( T_1 , V_176 , V_179 ) , V_180 ;
int V_67 , V_181 = 0 , V_182 = 5 ;
T_2 * V_183 = V_48 ;
if ( ! V_48 || ! V_178 || V_176 > V_179 )
return - V_36 ;
V_2 = F_32 ( V_137 ) ;
if ( V_2 == NULL )
return - V_138 ;
if ( V_2 -> V_21 & V_22 ) {
V_67 = F_54 ( V_2 , V_48 , V_176 ) ;
F_33 ( V_2 ) ;
return V_67 ;
}
do {
V_73 . V_15 . V_74 = V_184 ;
V_73 . V_78 . V_185 . V_178 = F_21 ( V_178 ) ;
V_67 = F_19 ( V_2 , NULL , & V_73 ,
V_186 + V_178 ,
F_55 ( struct V_187 ,
V_188 ) ,
0 , L_26 ) ;
if ( V_67 )
break;
V_177 = F_3 ( V_73 . V_78 . V_189 . V_190 ) ;
V_180 = F_3 ( V_73 . V_15 . V_48 . V_63 ) ;
if ( V_180 < F_55 ( struct V_187 , V_188 ) +
V_177 ) {
V_181 = - V_62 ;
break;
}
memcpy ( V_183 , V_73 . V_78 . V_189 . V_188 , V_177 ) ;
V_183 += V_177 ;
V_181 += V_177 ;
V_178 -= V_177 ;
} while ( V_182 -- && V_181 < V_176 );
F_33 ( V_2 ) ;
return V_181 ? V_181 : - V_191 ;
}
int F_56 ( T_1 V_137 , struct V_192 * V_193 ,
struct V_194 * V_195 )
{
struct V_1 * V_2 ;
int V_32 ;
V_2 = F_32 ( V_137 ) ;
if ( V_2 == NULL || ! ( V_2 -> V_21 & V_22 ) )
return - V_138 ;
V_32 = F_57 ( V_2 , V_193 , V_195 ) ;
F_33 ( V_2 ) ;
return V_32 ;
}
int F_58 ( T_1 V_137 , struct V_192 * V_193 ,
struct V_194 * V_195 )
{
struct V_1 * V_2 ;
int V_32 ;
V_2 = F_32 ( V_137 ) ;
if ( V_2 == NULL || ! ( V_2 -> V_21 & V_22 ) )
return - V_138 ;
V_32 = F_59 ( V_2 , V_193 , V_195 ) ;
F_33 ( V_2 ) ;
return V_32 ;
}
static int T_8 F_60 ( void )
{
int V_32 ;
V_196 = F_61 ( V_197 , L_27 ) ;
if ( F_62 ( V_196 ) ) {
F_63 ( L_28 ) ;
return F_64 ( V_196 ) ;
}
V_198 = F_61 ( V_197 , L_29 ) ;
if ( F_62 ( V_198 ) ) {
F_63 ( L_30 ) ;
F_65 ( V_196 ) ;
return F_64 ( V_198 ) ;
}
V_32 = F_66 ( & V_199 , 0 , 2 * V_200 , L_27 ) ;
if ( V_32 < 0 ) {
F_63 ( L_31 ) ;
F_65 ( V_198 ) ;
F_65 ( V_196 ) ;
return V_32 ;
}
return 0 ;
}
static void T_9 F_67 ( void )
{
F_68 ( & V_201 ) ;
F_65 ( V_196 ) ;
F_65 ( V_198 ) ;
F_69 ( V_199 , 2 * V_200 ) ;
}
