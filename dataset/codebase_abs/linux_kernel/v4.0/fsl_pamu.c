T_1 F_1 ( void )
{
return V_1 ;
}
static struct V_2 * F_2 ( int V_3 )
{
if ( ! V_4 || V_3 >= V_5 ) {
F_3 ( L_1 ) ;
return NULL ;
}
return & V_4 [ V_3 ] ;
}
int F_4 ( int V_3 )
{
struct V_2 * V_6 ;
V_6 = F_2 ( V_3 ) ;
if ( ! V_6 ) {
F_3 ( L_2 ) ;
return - V_7 ;
}
if ( ! F_5 ( V_6 -> V_8 , V_9 ) ) {
F_3 ( L_3 , V_3 ) ;
return - V_10 ;
}
F_6 () ;
F_7 ( V_6 -> V_8 , V_11 , V_12 ) ;
F_6 () ;
return 0 ;
}
int F_8 ( int V_3 )
{
struct V_2 * V_6 ;
V_6 = F_2 ( V_3 ) ;
if ( ! V_6 ) {
F_3 ( L_2 ) ;
return - V_7 ;
}
F_7 ( V_6 -> V_8 , V_11 , V_13 ) ;
F_6 () ;
return 0 ;
}
static unsigned int F_9 ( T_2 V_14 )
{
F_10 ( V_14 & ( V_14 - 1 ) ) ;
return F_11 ( V_14 ) - 2 ;
}
static unsigned int F_12 ( T_1 V_15 )
{
return F_13 ( V_15 ) - 1 ;
}
static void F_14 ( struct V_2 * V_6 )
{
F_7 ( V_6 -> V_8 , V_16 , V_17 ) ;
F_7 ( V_6 -> V_18 . V_19 . V_20 , V_21 ,
V_22 ) ;
}
static void F_15 ( struct V_2 * V_23 )
{
F_7 ( V_23 -> V_8 , V_16 , V_24 ) ;
F_7 ( V_23 -> V_18 . V_19 . V_20 , V_21 ,
V_22 ) ;
}
static struct V_2 * F_16 ( struct V_2 * V_2 , T_1 V_25 )
{
T_1 V_26 ;
struct V_2 * V_23 = NULL ;
V_26 = 1UL << ( F_5 ( V_2 -> V_27 , V_28 ) + 1 ) ;
if ( V_25 < V_26 )
V_23 = & V_29 [ V_2 -> V_30 + V_25 ] ;
else
F_3 ( L_4 ) ;
return V_23 ;
}
static unsigned long F_17 ( T_1 V_26 )
{
unsigned long V_31 ;
V_31 = F_18 ( V_32 , V_26 * sizeof( struct V_2 ) ) ;
if ( ! V_31 )
return V_33 ;
return ( V_31 - ( unsigned long ) V_29 ) / ( sizeof( struct V_2 ) ) ;
}
void F_19 ( int V_3 )
{
struct V_2 * V_6 ;
T_1 V_26 , V_34 ;
V_6 = F_2 ( V_3 ) ;
if ( ! V_6 ) {
F_3 ( L_5 ) ;
return;
}
if ( F_5 ( V_6 -> V_8 , V_35 ) ) {
V_26 = 1UL << ( F_5 ( V_6 -> V_27 , V_28 ) + 1 ) ;
V_34 = ( V_26 - 1 ) * sizeof( struct V_2 ) ;
F_20 ( V_32 , ( unsigned long ) & V_29 [ V_6 -> V_30 ] , V_34 ) ;
F_7 ( V_6 -> V_8 , V_35 , 0 ) ;
}
}
int F_21 ( int V_3 , T_1 V_36 , T_1 V_37 )
{
struct V_2 * V_2 ;
V_2 = F_2 ( V_3 ) ;
if ( ! V_2 ) {
F_3 ( L_5 ) ;
return - V_7 ;
}
if ( V_36 ) {
V_2 = F_16 ( V_2 , V_36 - 1 ) ;
if ( ! V_2 )
return - V_7 ;
}
F_7 ( V_2 -> V_27 , V_38 , V_37 ) ;
F_6 () ;
return 0 ;
}
int F_22 ( int V_3 , T_1 V_36 )
{
struct V_2 * V_2 ;
V_2 = F_2 ( V_3 ) ;
if ( ! V_2 ) {
F_3 ( L_5 ) ;
return - V_7 ;
}
if ( V_36 ) {
V_2 = F_16 ( V_2 , V_36 - 1 ) ;
if ( ! V_2 )
return - V_7 ;
F_7 ( V_2 -> V_8 , V_11 , V_13 ) ;
} else {
F_7 ( V_2 -> V_8 , V_39 ,
V_40 ) ;
}
F_6 () ;
return 0 ;
}
int F_23 ( int V_3 , T_2 V_41 , T_2 V_42 ,
T_1 V_43 , unsigned long V_44 , T_1 V_45 , T_1 V_46 ,
T_1 V_26 , int V_47 )
{
struct V_2 * V_6 ;
unsigned long V_30 ;
if ( ( V_42 & ( V_42 - 1 ) ) || V_42 < V_48 ) {
F_3 ( L_6 ,
& V_42 ) ;
return - V_10 ;
}
if ( V_41 & ( V_42 - 1 ) ) {
F_3 ( L_7 ) ;
return - V_10 ;
}
V_6 = F_2 ( V_3 ) ;
if ( ! V_6 )
return - V_7 ;
F_7 ( V_6 -> V_8 , V_9 ,
F_9 ( V_42 ) ) ;
F_14 ( V_6 ) ;
V_6 -> V_49 = V_41 >> ( V_50 + 20 ) ;
F_7 ( V_6 -> V_8 , V_51 ,
( V_41 >> V_50 ) ) ;
if ( V_43 < V_52 ) {
F_7 ( V_6 -> V_27 , V_53 , V_54 ) ;
V_6 -> V_55 . V_56 . V_43 = V_43 ;
} else if ( ~ V_43 != 0 ) {
F_3 ( L_8 , V_43 ) ;
return - V_10 ;
}
if ( ~ V_46 != 0 )
F_7 ( V_6 -> V_27 , V_38 , V_46 ) ;
if ( ~ V_45 != 0 )
V_6 -> V_18 . V_19 . V_57 = V_45 ;
if ( V_26 ) {
V_30 = F_17 ( V_26 - 1 ) ;
if ( V_30 == V_33 ) {
F_3 ( L_9 ) ;
return - V_10 ;
}
F_7 ( V_6 -> V_27 , V_28 ,
F_12 ( V_26 ) ) ;
F_7 ( V_6 -> V_8 , V_35 , 0x1 ) ;
V_6 -> V_30 = V_30 ;
} else {
F_7 ( V_6 -> V_27 , V_58 , V_59 ) ;
V_6 -> V_60 = V_44 >> 20 ;
F_7 ( V_6 -> V_61 , V_62 , V_44 ) ;
F_7 ( V_6 -> V_8 , V_39 , V_47 ) ;
F_7 ( V_6 -> V_27 , V_28 , 0 ) ;
F_7 ( V_6 -> V_8 , V_35 , 0 ) ;
}
F_6 () ;
return 0 ;
}
int F_24 ( int V_3 , T_1 V_26 , T_1 V_36 ,
T_2 V_63 , T_1 V_43 , unsigned long V_44 ,
T_1 V_45 , T_1 V_46 , int V_64 , int V_47 )
{
struct V_2 * V_2 ;
if ( ! V_26 ) {
F_3 ( L_10 ) ;
return - V_10 ;
}
V_2 = F_2 ( V_3 ) ;
if ( V_36 > 0 && V_36 < V_26 && V_2 ) {
V_2 = F_16 ( V_2 , V_36 - 1 ) ;
if ( V_2 && ! ( V_2 -> V_8 & V_12 ) ) {
F_15 ( V_2 ) ;
F_7 ( V_2 -> V_8 , V_65 , V_3 ) ;
}
}
if ( ! V_2 ) {
F_3 ( L_5 ) ;
return - V_7 ;
}
if ( ( V_63 & ( V_63 - 1 ) ) || V_63 < V_48 ) {
F_3 ( L_11 ) ;
return - V_10 ;
}
if ( V_44 == V_33 ) {
F_3 ( L_12 ) ;
return - V_10 ;
}
F_7 ( V_2 -> V_61 , V_66 ,
F_9 ( V_63 ) ) ;
F_7 ( V_2 -> V_27 , V_58 , V_59 ) ;
V_2 -> V_60 = V_44 >> 20 ;
F_7 ( V_2 -> V_61 , V_62 , V_44 ) ;
F_7 ( V_2 -> V_8 , V_39 , V_47 ) ;
if ( ~ V_45 != 0 )
V_2 -> V_18 . V_19 . V_57 = V_45 ;
if ( V_43 < V_52 ) {
F_7 ( V_2 -> V_27 , V_53 , V_54 ) ;
V_2 -> V_55 . V_56 . V_43 = V_43 ;
} else if ( ~ V_43 != 0 ) {
F_3 ( L_8 , V_43 ) ;
return - V_10 ;
}
if ( ~ V_46 != 0 )
F_7 ( V_2 -> V_27 , V_38 , V_46 ) ;
F_25 () ;
if ( V_64 )
F_7 ( V_2 -> V_8 , V_11 , V_12 ) ;
F_6 () ;
return 0 ;
}
void F_26 ( T_1 * V_67 , struct V_68 * V_69 )
{
if ( F_27 ( V_69 -> V_70 , L_13 ) )
* V_67 = V_71 ;
if ( F_27 ( V_69 -> V_70 , L_14 ) )
* V_67 = V_72 ;
}
T_1 F_28 ( T_1 V_73 , T_1 V_74 )
{
const T_1 * V_75 ;
struct V_76 * V_77 ;
T_1 V_78 ;
int V_79 , V_80 = 0 ;
int V_81 ;
if ( V_73 == V_82 ) {
V_77 = F_29 ( NULL , V_83 ) ;
if ( V_77 ) {
V_75 = F_30 ( V_77 , L_15 , NULL ) ;
if ( ! V_75 ) {
F_3 ( L_16 ,
V_77 -> V_84 ) ;
F_31 ( V_77 ) ;
return ~ ( T_1 ) 0 ;
}
F_31 ( V_77 ) ;
return F_32 ( V_75 ) ;
}
return ~ ( T_1 ) 0 ;
}
F_33 (node, L_17 ) {
V_75 = F_30 ( V_77 , L_18 , & V_79 ) ;
for ( V_81 = 0 ; V_81 < V_79 / sizeof( T_1 ) ; V_81 ++ ) {
if ( F_32 ( & V_75 [ V_81 ] ) == V_74 ) {
V_80 = 1 ;
goto V_85;
}
}
}
V_85:
for ( V_78 = V_86 ; ( V_78 < V_82 ) && V_80 ; V_78 ++ ) {
if ( V_73 == V_78 ) {
V_75 = F_30 ( V_77 , L_15 , NULL ) ;
if ( ! V_75 ) {
F_3 ( L_16 ,
V_77 -> V_84 ) ;
F_31 ( V_77 ) ;
return ~ ( T_1 ) 0 ;
}
F_31 ( V_77 ) ;
return F_32 ( V_75 ) ;
}
V_75 = F_30 ( V_77 , L_19 , NULL ) ;
if ( ! V_75 ) {
F_3 ( L_20 ,
V_77 -> V_84 ) ;
F_31 ( V_77 ) ;
return ~ ( T_1 ) 0 ;
}
F_31 ( V_77 ) ;
V_77 = F_34 ( * V_75 ) ;
if ( ! V_77 ) {
F_3 ( L_21 ) ;
return ~ ( T_1 ) 0 ;
}
}
F_3 ( L_22 ,
V_73 , V_74 ) ;
return ~ ( T_1 ) 0 ;
}
static void T_3 F_35 ( struct V_2 * V_6 , int V_87 )
{
switch ( V_87 ) {
case V_88 :
F_7 ( V_6 -> V_27 , V_53 , V_54 ) ;
V_6 -> V_55 . V_56 . V_43 = V_72 ;
F_7 ( V_6 -> V_27 , V_38 , F_28 ( V_82 , 0 ) ) ;
F_7 ( V_6 -> V_18 . V_19 . V_20 , V_21 ,
0 ) ;
break;
case V_89 :
F_7 ( V_6 -> V_27 , V_53 , V_54 ) ;
V_6 -> V_55 . V_56 . V_43 = V_71 ;
F_7 ( V_6 -> V_27 , V_38 , F_28 ( V_82 , 0 ) ) ;
break;
case V_90 :
F_7 ( V_6 -> V_18 . V_19 . V_20 , V_21 ,
0 ) ;
break;
}
}
static void T_3 F_36 ( struct V_91 * V_92 )
{
struct V_91 * V_91 ;
V_91 = & V_92 [ V_71 ] ;
V_91 -> V_93 [ V_94 ] = V_95 | V_96 ;
V_91 -> V_93 [ V_97 ] = V_95 | V_98 ;
V_91 -> V_93 [ V_99 ] = V_95 | V_100 ;
V_91 -> V_93 [ V_101 ] = V_95 | V_102 ;
V_91 -> V_93 [ V_103 ] = V_95 | V_104 ;
V_91 -> V_93 [ V_105 ] = V_95 | V_106 ;
V_91 = & V_92 [ V_107 ] ;
V_91 -> V_93 [ V_94 ] = V_95 | V_108 ;
V_91 -> V_93 [ V_99 ] = V_95 | V_100 ;
V_91 = & V_92 [ V_72 ] ;
V_91 -> V_93 [ V_94 ] = V_95 | V_96 ;
V_91 -> V_93 [ V_99 ] = V_95 | V_100 ;
V_91 -> V_93 [ V_97 ] = V_95 | V_98 ;
V_91 -> V_93 [ V_101 ] = V_95 | V_109 ;
V_91 = & V_92 [ V_110 ] ;
V_91 -> V_93 [ V_94 ] = V_95 | V_108 ;
V_91 -> V_93 [ V_99 ] = V_95 | V_100 ;
}
static void T_3 F_37 ( unsigned long V_111 )
{
T_1 V_112 ;
V_112 = F_38 ( ( T_1 * ) ( V_111 + V_113 ) ) ;
V_1 = 1 << ( 1 + F_39 ( V_112 ) ) ;
}
static int T_3 F_40 ( unsigned long V_111 , unsigned long V_114 ,
T_2 V_115 , T_2 V_116 ,
T_2 V_117 )
{
T_1 * V_118 ;
struct V_119 * V_120 ;
V_118 = ( T_1 * ) ( V_111 + V_121 ) ;
V_120 = (struct V_119 * )
( V_111 + V_122 ) ;
F_41 ( & V_120 -> V_123 , F_42 ( V_115 ) ) ;
F_41 ( & V_120 -> V_124 , F_43 ( V_115 ) ) ;
V_115 = V_115 + V_125 ;
F_41 ( & V_120 -> V_126 , F_42 ( V_115 ) ) ;
F_41 ( & V_120 -> V_127 , F_43 ( V_115 ) ) ;
F_41 ( & V_120 -> V_128 , F_42 ( V_116 ) ) ;
F_41 ( & V_120 -> V_129 , F_43 ( V_116 ) ) ;
V_116 = V_116 + V_130 ;
F_41 ( & V_120 -> V_131 , F_42 ( V_116 ) ) ;
F_41 ( & V_120 -> V_132 , F_43 ( V_116 ) ) ;
F_41 ( & V_120 -> V_133 , F_42 ( V_117 ) ) ;
F_41 ( & V_120 -> V_134 , F_43 ( V_117 ) ) ;
V_117 = V_117 + V_135 ;
F_41 ( & V_120 -> V_136 , F_42 ( V_117 ) ) ;
F_41 ( & V_120 -> V_137 , F_43 ( V_117 ) ) ;
F_41 ( ( T_1 * ) ( V_111 + V_138 ) ,
V_139 ) ;
F_41 ( V_118 , V_140 | V_141 | V_142 | V_143 ) ;
return 0 ;
}
static void T_3 F_44 ( void )
{
int V_81 , V_79 ;
struct V_2 * V_6 ;
struct V_76 * V_77 = NULL ;
const T_1 * V_75 ;
F_45 (node, L_23 ) {
V_75 = F_30 ( V_77 , L_23 , & V_79 ) ;
for ( V_81 = 0 ; V_81 < V_79 / sizeof( T_1 ) ; V_81 ++ ) {
int V_3 ;
V_3 = F_32 ( & V_75 [ V_81 ] ) ;
if ( V_3 >= V_5 ) {
F_3 ( L_24 , V_3 ) ;
continue;
}
V_6 = F_2 ( V_3 ) ;
F_14 ( V_6 ) ;
F_7 ( V_6 -> V_8 , V_9 , 35 ) ;
V_6 -> V_49 = 0 ;
F_7 ( V_6 -> V_8 , V_51 , 0 ) ;
F_7 ( V_6 -> V_27 , V_58 ,
V_144 ) ;
F_7 ( V_6 -> V_8 , V_39 ,
V_145 ) ;
if ( F_27 ( V_77 , L_13 ) )
F_35 ( V_6 , V_89 ) ;
if ( F_27 ( V_77 , L_14 ) )
F_35 ( V_6 , V_88 ) ;
if ( F_27 ( V_77 , L_25 ) )
F_35 ( V_6 , V_90 ) ;
F_6 () ;
F_4 ( V_3 ) ;
}
}
}
static T_4 F_46 ( int V_146 , void * V_147 )
{
struct V_148 * V_149 = V_147 ;
T_2 V_150 ;
unsigned int V_81 , V_151 , V_152 ;
F_47 ( L_26 ) ;
for ( V_81 = 0 ; V_81 < V_149 -> V_153 ; V_81 ++ ) {
void T_5 * V_154 = V_149 -> V_111 + V_81 * V_155 ;
T_1 V_156 = F_38 ( V_154 + V_138 ) ;
if ( V_156 & V_157 ) {
T_1 V_158 = F_38 ( V_154 + V_159 ) ;
struct V_2 * V_2 ;
F_47 ( L_27 , F_38 ( V_154 + V_160 ) ) ;
F_47 ( L_28 , F_38 ( V_154 + V_161 ) ) ;
F_47 ( L_29 , V_158 ) ;
F_47 ( L_30 , F_38 ( V_154 + V_162 ) ) ;
F_47 ( L_31 ,
F_48 ( F_38 ( V_154 + V_163 ) ,
F_38 ( V_154 + V_164 ) ) ) ;
F_47 ( L_32 , F_38 ( V_154 + V_165 ) ) ;
F_47 ( L_33 ,
F_48 ( F_38 ( V_154 + V_166 ) ,
F_38 ( V_154 + V_167 ) ) ) ;
V_150 = F_48 ( F_38 ( V_154 + V_166 ) ,
F_38 ( V_154 + V_167 ) ) ;
if ( V_150 ) {
T_1 * V_2 = F_49 ( V_150 ) ;
for ( V_151 = 0 ; V_151 < 4 ; V_151 ++ )
F_47 ( L_34 ,
V_151 , F_38 ( V_2 + V_151 ) ) ;
}
F_41 ( V_154 + V_159 , V_158 & V_168 ) ;
V_2 = F_2 ( V_158 >> V_169 ) ;
F_10 ( ! V_2 ) ;
if ( ! F_5 ( V_2 -> V_8 , V_11 ) ) {
V_156 &= ~ V_139 ;
} else {
V_152 = F_8 ( V_158 >> V_169 ) ;
F_10 ( V_152 ) ;
F_47 ( L_35 ,
V_158 >> V_169 ) ;
}
F_41 ( ( V_154 + V_138 ) , V_156 ) ;
}
}
return V_170 ;
}
static int T_3 F_50 ( T_2 V_150 , T_6 V_34 , T_1 V_171 )
{
struct V_76 * V_172 ;
const T_7 * V_173 ;
void T_5 * V_174 = NULL ;
struct V_175 T_5 * V_176 ;
void T_5 * V_177 = NULL ;
T_1 T_5 * V_178 ;
unsigned int V_81 , V_179 , V_180 ;
T_1 V_181 = 0 ;
T_1 V_182 = 0 ;
int V_152 = 0 ;
V_172 = F_51 ( NULL , NULL , L_36 ) ;
if ( ! V_172 )
return - V_183 ;
V_173 = F_30 ( V_172 , L_37 , NULL ) ;
if ( ! V_173 ) {
V_152 = - V_183 ;
goto error;
}
V_179 = F_32 ( V_173 ) ;
if ( ! V_179 ) {
V_152 = - V_183 ;
goto error;
}
V_174 = F_52 ( V_172 , 0 ) ;
if ( ! V_174 ) {
V_152 = - V_183 ;
goto error;
}
V_176 = V_174 + 0xC00 ;
F_31 ( V_172 ) ;
V_172 = F_51 ( NULL , NULL , L_38 ) ;
if ( ! V_172 ) {
V_152 = - V_183 ;
goto error;
}
V_173 = F_30 ( V_172 , L_39 , NULL ) ;
if ( ! V_173 ) {
V_152 = - V_183 ;
goto error;
}
V_180 = F_32 ( V_173 ) ;
if ( ! V_180 ) {
V_152 = - V_183 ;
goto error;
}
V_177 = F_52 ( V_172 , 0 ) ;
if ( ! V_177 ) {
V_152 = - V_184 ;
goto error;
}
V_178 = V_177 + 0x600 ;
F_31 ( V_172 ) ;
V_172 = NULL ;
for ( V_182 = 0 ; V_182 < V_180 ; V_182 ++ ) {
if ( ! V_178 [ V_182 ] )
break;
}
V_178 [ V_182 ] = V_171 ;
for ( V_81 = 0 ; V_81 < V_179 ; V_81 ++ ) {
if ( V_176 [ V_81 ] . V_185 & V_186 ) {
T_2 V_187 , V_188 ;
V_187 = F_48 ( V_176 [ V_81 ] . V_189 , V_176 [ V_81 ] . V_190 ) ;
V_188 = V_187 +
( 2ULL << ( V_176 [ V_81 ] . V_185 & V_191 ) ) ;
if ( V_187 <= V_150 && V_150 < V_188 ) {
V_181 = V_176 [ V_81 ] . V_185 & V_192 ;
break;
}
}
}
if ( V_81 == 0 || V_81 == V_179 ) {
V_152 = - V_7 ;
goto error;
}
while ( V_176 [ -- V_81 ] . V_185 & V_186 ) {
if ( V_81 == 0 ) {
V_152 = - V_7 ;
goto error;
}
}
V_176 [ V_81 ] . V_189 = F_42 ( V_150 ) ;
V_176 [ V_81 ] . V_190 = F_43 ( V_150 ) ;
F_53 () ;
V_176 [ V_81 ] . V_185 = V_186 | V_181 | ( V_182 << V_193 ) |
( V_194 + F_54 ( V_34 ) ) ;
F_53 () ;
error:
if ( V_177 )
F_55 ( V_177 ) ;
if ( V_174 )
F_55 ( V_174 ) ;
if ( V_172 )
F_31 ( V_172 ) ;
return V_152 ;
}
static int T_3 F_56 ( struct V_195 * V_196 )
{
struct V_68 * V_69 = & V_196 -> V_69 ;
void T_5 * V_120 = NULL ;
struct V_197 T_5 * V_198 = NULL ;
T_1 V_199 , V_200 ;
unsigned long V_201 ;
unsigned long V_111 ;
struct V_148 * V_149 = NULL ;
struct V_76 * V_202 ;
T_8 V_34 ;
struct V_203 * V_154 ;
int V_152 = 0 ;
int V_146 ;
T_2 V_115 ;
T_2 V_116 ;
T_2 V_117 ;
T_6 V_204 = 0 ;
unsigned int V_205 = 0 ;
T_1 V_171 = 0 ;
unsigned V_81 ;
V_120 = F_52 ( V_69 -> V_70 , 0 ) ;
if ( ! V_120 ) {
F_57 ( V_69 , L_40 ) ;
return - V_184 ;
}
F_58 ( V_69 -> V_70 , 0 , & V_34 , NULL ) ;
V_146 = F_59 ( V_69 -> V_70 , 0 ) ;
if ( V_146 == V_206 ) {
F_60 ( V_69 , L_41 ) ;
goto error;
}
V_149 = F_61 ( sizeof( * V_149 ) , V_207 ) ;
if ( ! V_149 ) {
V_152 = - V_184 ;
goto error;
}
V_149 -> V_111 = V_120 ;
V_149 -> V_153 = V_34 / V_155 ;
V_152 = F_62 ( V_146 , F_46 , 0 , L_42 , V_149 ) ;
if ( V_152 < 0 ) {
F_57 ( V_69 , L_43 , V_152 , V_146 ) ;
goto error;
}
V_202 = F_29 ( NULL , V_208 ) ;
if ( ! V_202 ) {
F_57 ( V_69 , L_44 ,
V_69 -> V_70 -> V_84 ) ;
V_152 = - V_183 ;
goto error;
}
V_198 = F_52 ( V_202 , 0 ) ;
F_31 ( V_202 ) ;
if ( ! V_198 ) {
F_57 ( V_69 , L_45 ) ;
V_152 = - V_183 ;
goto error;
}
F_37 ( ( unsigned long ) V_120 ) ;
V_204 = ( V_209 << F_54 ( V_125 ) ) +
( V_209 << F_54 ( V_130 ) ) +
( V_209 << F_54 ( V_135 ) ) ;
V_205 = F_54 ( V_204 ) ;
V_154 = F_63 ( V_207 | V_210 , V_205 ) ;
if ( ! V_154 ) {
F_57 ( V_69 , L_46 ) ;
V_152 = - V_184 ;
goto error;
}
V_4 = F_64 ( V_154 ) ;
V_115 = F_65 ( V_154 ) ;
if ( V_115 & ( ( V_209 << V_205 ) - 1 ) ) {
F_57 ( V_69 , L_47 ) ;
V_152 = - V_184 ;
goto error;
}
V_29 = ( void * ) V_4 + ( V_209 << F_54 ( V_125 ) ) ;
V_92 = ( void * ) V_29 + ( V_209 << F_54 ( V_130 ) ) ;
F_66 ( V_69 , L_48 , V_4 , & V_115 ) ;
for ( V_81 = 0 ; V_81 < F_67 ( V_211 ) ; V_81 ++ ) {
if ( V_211 [ V_81 ] . V_212 == ( F_68 ( V_213 ) & ~ V_214 ) ) {
V_171 = V_211 [ V_81 ] . V_215 ;
F_66 ( V_69 , L_49 ,
V_211 [ V_81 ] . V_212 ) ;
break;
}
}
if ( V_171 ) {
F_66 ( V_69 , L_50 ,
& V_115 , V_204 , V_171 ) ;
V_152 = F_50 ( V_115 , V_204 , V_171 ) ;
if ( V_152 ) {
F_57 ( V_69 , L_51 ) ;
return V_152 ;
}
}
V_116 = F_69 ( V_29 ) ;
V_117 = F_69 ( V_92 ) ;
V_32 = F_70 ( F_71 ( sizeof( struct V_2 ) ) , - 1 ) ;
if ( ! V_32 ) {
V_152 = - V_184 ;
F_57 ( V_69 , L_52 ) ;
goto error;
}
V_152 = F_72 ( V_32 , ( unsigned long ) V_29 , V_130 , - 1 ) ;
if ( V_152 )
goto V_216;
V_199 = F_38 ( & V_198 -> V_199 ) ;
for ( V_201 = 0 , V_200 = 0x80000000 ; V_201 < V_34 ;
V_201 += V_155 , V_200 >>= 1 ) {
V_111 = ( unsigned long ) V_120 + V_201 ;
F_40 ( V_111 , V_201 , V_115 ,
V_116 , V_117 ) ;
V_199 &= ~ V_200 ;
}
F_36 ( V_92 ) ;
F_41 ( & V_198 -> V_199 , V_199 ) ;
F_55 ( V_198 ) ;
F_44 () ;
return 0 ;
V_216:
F_73 ( V_32 ) ;
error:
if ( V_146 != V_206 )
F_74 ( V_146 , V_149 ) ;
if ( V_149 ) {
memset ( V_149 , 0 , sizeof( struct V_148 ) ) ;
F_75 ( V_149 ) ;
}
if ( V_120 )
F_55 ( V_120 ) ;
if ( V_198 )
F_55 ( V_198 ) ;
if ( V_4 )
F_76 ( ( unsigned long ) V_4 , V_205 ) ;
V_4 = NULL ;
return V_152 ;
}
static T_3 int F_77 ( void )
{
struct V_195 * V_196 = NULL ;
struct V_76 * V_172 ;
int V_152 ;
V_172 = F_51 ( NULL , NULL , L_53 ) ;
if ( ! V_172 ) {
F_78 ( L_54 ) ;
return - V_183 ;
}
V_152 = F_79 ( & V_217 ) ;
if ( V_152 ) {
F_78 ( L_55 , V_152 ) ;
goto V_218;
}
V_196 = F_80 ( L_56 , 0 ) ;
if ( ! V_196 ) {
F_78 ( L_57 ,
V_172 -> V_84 ) ;
V_152 = - V_184 ;
goto V_219;
}
V_196 -> V_69 . V_70 = F_81 ( V_172 ) ;
V_152 = F_82 () ;
if ( V_152 )
goto V_220;
V_152 = F_83 ( V_196 ) ;
if ( V_152 ) {
F_78 ( L_58 ,
V_172 -> V_84 , V_152 ) ;
goto V_220;
}
return 0 ;
V_220:
F_31 ( V_196 -> V_69 . V_70 ) ;
V_196 -> V_69 . V_70 = NULL ;
F_84 ( V_196 ) ;
V_219:
F_85 ( & V_217 ) ;
V_218:
F_31 ( V_172 ) ;
return V_152 ;
}
