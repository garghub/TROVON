static inline T_1 F_1 ( T_2 V_1 , T_3 V_2 )
{
return ( T_1 ) ( ( V_1 & 0xff ) ^ ( ( V_1 >> 40 ) & 0xff ) ^ ( V_2 & 0xff ) ) ;
}
static inline T_4 F_2 ( struct V_3 * V_4 ,
T_3 V_5 , T_1 V_6 )
{
if ( F_3 ( V_4 ) )
return V_5 | ( V_6 << 15 ) ;
else
return V_5 ;
}
static inline int F_4 ( T_2 V_7 )
{
return ( F_5 ( V_7 ) == V_8 ) ? 1 : 0 ;
}
static void F_6 ( struct V_3 * V_4 ,
struct V_9 * V_10 ,
void * V_11 , T_3 V_12 )
{
int V_13 ;
T_1 V_14 ;
V_14 = V_12 ? V_15 : V_16 ;
V_13 = F_7 ( V_4 , V_11 , V_12 , V_14 ) ;
if ( V_13 )
return;
V_14 = V_12 ? V_17 : V_18 ;
V_13 = F_7 ( V_4 , V_11 , V_12 , V_14 ) ;
if ( ! V_13 ) {
F_8 ( & V_10 -> V_19 ) ;
V_4 -> V_20 . V_21 -- ;
}
}
static struct V_9 * F_9 ( struct V_22 * V_23 ,
void * V_11 , T_3 V_12 )
{
struct V_9 * V_24 = NULL ;
struct V_25 * V_26 ;
F_10 (tmp_fil, n, head, fnode) {
if ( F_11 ( V_24 -> V_27 , V_11 ) &&
V_24 -> V_12 == V_12 )
return V_24 ;
}
return NULL ;
}
static void F_12 ( struct V_3 * V_4 ,
struct V_28 * V_29 , int V_30 , T_3 V_12 )
{
struct V_31 * V_32 = (struct V_31 * ) ( V_29 -> V_33 ) ;
struct V_9 * V_10 , * V_24 ;
struct V_22 * V_23 ;
unsigned long time ;
T_2 V_34 = 0 ;
T_1 V_35 , V_14 ;
int V_13 ;
if ( ! F_13 ( V_4 ) || ( V_12 == 0xffff ) )
V_12 = 0 ;
memcpy ( & V_34 , V_32 -> V_36 , V_37 ) ;
V_35 = F_1 ( V_34 , V_12 ) &
( V_4 -> V_38 . V_39 - 1 ) ;
if ( V_30 ) {
if ( V_4 -> V_20 . V_21 >= V_4 -> V_20 . V_40 )
return;
V_23 = & ( V_4 -> V_20 . V_41 [ V_35 ] ) ;
V_24 = F_9 ( V_23 , & V_34 , V_12 ) ;
if ( V_24 ) {
time = V_24 -> V_42 ;
if ( F_14 ( V_43 , V_44 * V_45 + time ) )
V_24 -> V_42 = V_43 ;
return;
}
V_10 = F_15 ( sizeof( struct V_9 ) , V_46 ) ;
if ( ! V_10 )
return;
V_10 -> V_42 = V_43 ;
memcpy ( V_10 -> V_27 , & V_34 , V_37 ) ;
V_10 -> V_12 = V_12 ;
F_16 ( & V_4 -> V_47 ) ;
F_17 ( & ( V_10 -> V_19 ) , V_23 ) ;
V_4 -> V_20 . V_21 ++ ;
F_18 ( & V_4 -> V_47 ) ;
} else {
V_23 = & V_4 -> V_38 . V_41 [ V_35 ] ;
F_16 ( & V_4 -> V_48 ) ;
V_24 = F_9 ( V_23 , & V_34 , V_12 ) ;
if ( V_24 ) {
V_14 = V_12 ? V_17 : V_18 ;
V_13 = F_7 ( V_4 ,
( T_1 * ) & V_34 ,
V_12 , V_14 ) ;
if ( ! V_13 ) {
F_8 ( & V_24 -> V_19 ) ;
V_4 -> V_38 . V_21 -- ;
}
F_18 ( & V_4 -> V_48 ) ;
return;
}
F_18 ( & V_4 -> V_48 ) ;
V_23 = & V_4 -> V_20 . V_41 [ V_35 ] ;
F_16 ( & V_4 -> V_47 ) ;
V_24 = F_9 ( V_23 , & V_34 , V_12 ) ;
if ( V_24 )
F_6 ( V_4 , V_24 , & V_34 ,
V_12 ) ;
F_18 ( & V_4 -> V_47 ) ;
}
}
void F_19 ( struct V_3 * V_4 , T_2 * V_49 ,
T_3 V_12 )
{
struct V_50 * V_51 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
struct V_58 * V_59 = V_4 -> V_59 ;
T_4 V_60 ;
T_2 V_61 ;
V_60 = V_59 -> V_60 ;
V_51 = & V_59 -> V_62 [ V_59 -> V_60 ] ;
V_53 = (struct V_52 * ) V_51 ;
memset ( V_53 , 0 , sizeof( struct V_52 ) ) ;
V_53 -> V_63 = F_20 ( V_64 << 23 ) ;
V_61 = V_65 | ( ( T_2 ) ( V_4 -> V_66 ) << 16 ) ;
V_53 -> V_67 = F_20 ( V_61 ) ;
V_55 = (struct V_54 * ) & ( V_53 -> V_68 [ 0 ] ) ;
V_55 -> V_14 = V_12 ? V_15 : V_16 ;
memcpy ( V_55 -> V_69 , V_49 , V_37 ) ;
V_57 = (struct V_56 * ) & V_53 -> V_68 [ 1 ] ;
V_57 -> V_12 = F_21 ( V_12 ) ;
V_59 -> V_60 = F_22 ( V_60 , V_59 -> V_70 ) ;
F_23 () ;
}
static void F_24 ( struct V_3 * V_4 ,
struct V_50 * V_71 ,
struct V_28 * V_29 )
{
struct V_72 * V_73 = (struct V_72 * ) ( V_29 -> V_33 ) ;
struct V_31 * V_32 = (struct V_31 * ) ( V_29 -> V_33 ) ;
struct V_74 * V_75 = V_4 -> V_75 ;
T_3 V_76 = F_25 ( V_29 -> V_76 ) ;
struct V_9 * V_10 , * V_24 ;
struct V_22 * V_23 ;
struct V_25 * V_26 ;
T_2 V_34 = 0 ;
T_3 V_12 = 0 ;
T_1 V_35 , V_77 ;
if ( ! F_13 ( V_4 ) ) {
if ( F_11 ( V_32 -> V_36 , V_4 -> V_69 ) )
return;
} else {
if ( V_76 == V_78 ) {
V_73 = (struct V_72 * ) V_29 -> V_33 ;
V_12 = F_25 ( V_73 -> V_79 ) ;
} else if ( F_26 ( V_29 ) ) {
V_12 = F_27 ( V_29 ) ;
}
if ( F_11 ( V_32 -> V_36 , V_4 -> V_69 ) &&
! V_12 )
return;
}
if ( V_4 -> V_38 . V_21 >= V_4 -> V_38 . V_40 ) {
V_4 -> V_80 . V_81 ++ ;
F_28 ( V_75 , L_1 ,
V_4 -> V_38 . V_40 , V_4 -> V_38 . V_21 ) ;
return;
}
memcpy ( & V_34 , V_32 -> V_36 , V_37 ) ;
V_77 = F_1 ( V_34 , V_12 ) ;
V_35 = V_77 & ( V_4 -> V_38 . V_39 - 1 ) ;
V_23 = & ( V_4 -> V_38 . V_41 [ V_35 ] ) ;
F_10 (tmp_fil, n, head, fnode) {
if ( F_11 ( V_24 -> V_27 , ( T_1 * ) & V_34 ) &&
V_24 -> V_12 == V_12 ) {
if ( V_43 > ( V_44 * V_45 + V_24 -> V_42 ) )
F_29 ( V_4 , & V_34 ,
V_12 ) ;
V_24 -> V_42 = V_43 ;
return;
}
}
V_10 = F_15 ( sizeof( struct V_9 ) , V_46 ) ;
if ( ! V_10 )
return;
F_29 ( V_4 , & V_34 , V_12 ) ;
V_10 -> V_42 = V_43 ;
V_10 -> V_12 = V_12 ;
memcpy ( V_10 -> V_27 , & V_34 , V_37 ) ;
F_16 ( & V_4 -> V_48 ) ;
F_17 ( & ( V_10 -> V_19 ) , V_23 ) ;
V_4 -> V_38 . V_21 ++ ;
F_18 ( & V_4 -> V_48 ) ;
}
static int F_30 ( struct V_3 * V_4 ,
struct V_50 * V_71 , struct V_28 * V_29 ,
struct V_58 * V_59 )
{
T_1 V_82 , V_83 = 0 , V_84 = 0 ;
T_3 V_85 = 0 , V_86 = 0 ;
int V_87 , V_88 , V_89 , V_90 ;
struct V_50 * V_51 ;
struct V_72 * V_73 ;
T_3 V_76 = F_25 ( V_29 -> V_76 ) ;
T_4 V_60 = V_59 -> V_60 ;
if ( V_76 == V_78 ) {
V_73 = (struct V_72 * ) V_29 -> V_33 ;
V_85 = V_91 ;
V_86 = F_25 ( V_73 -> V_79 ) ;
V_76 = F_25 ( V_73 -> V_92 ) ;
} else if ( F_26 ( V_29 ) ) {
V_85 = V_93 ;
V_86 = F_27 ( V_29 ) ;
}
if ( F_31 ( V_4 -> V_94 ) ) {
if ( V_86 && ! ( V_4 -> V_85 & V_95 ) )
return - V_96 ;
if ( V_86 && ( V_4 -> V_85 & V_95 ) )
goto V_97;
V_85 = V_93 ;
V_86 = V_4 -> V_94 ;
}
V_97:
F_32 ( V_71 , V_86 ) ;
F_33 ( V_71 , V_85 , V_83 ) ;
if ( * ( V_29 -> V_33 ) & V_98 ) {
V_85 |= V_98 ;
memcpy ( & V_71 -> V_99 , V_29 -> V_33 , V_37 ) ;
}
V_83 = V_100 ;
if ( F_34 ( V_29 ) ) {
V_84 = F_35 ( V_29 ) + F_36 ( V_29 ) ;
V_71 -> V_101 = F_21 ( F_37 ( V_29 ) -> V_102 ) ;
V_71 -> V_103 = V_84 ;
V_83 = ( V_76 == V_104 ) ? V_105 : V_106 ;
V_87 = 0 ;
V_88 = 2 ;
if ( V_85 & V_93 ) {
V_71 -> V_103 += V_107 ;
V_71 -> V_108 = V_107 ;
V_71 -> V_109 = V_107 ;
V_85 |= V_91 ;
V_51 = & V_59 -> V_62 [ V_60 ] ;
V_59 -> V_110 [ V_60 ] . V_29 = NULL ;
V_89 = F_38 ( ( int ) sizeof( struct V_50 ) -
V_88 , V_84 + V_107 ) ;
V_73 = (struct V_72 * ) ( ( char * ) V_51 + 2 ) ;
F_39 ( V_29 , V_73 , 12 ) ;
V_73 -> V_111 = F_40 ( V_78 ) ;
V_73 -> V_79 = F_40 ( V_86 ) ;
F_41 ( V_29 , 12 ,
( char * ) V_73 + 16 ,
V_89 - 16 ) ;
V_87 = V_89 - V_107 ;
V_88 = 0 ;
V_60 = F_22 ( V_60 , V_59 -> V_70 ) ;
}
while ( V_87 < V_84 ) {
V_90 = ( int ) sizeof( struct V_50 ) - V_88 ;
V_89 = F_38 ( V_90 , ( V_84 - V_87 ) ) ;
V_51 = & V_59 -> V_62 [ V_60 ] ;
V_59 -> V_110 [ V_60 ] . V_29 = NULL ;
F_41 ( V_29 , V_87 ,
( char * ) V_51 +
V_88 , V_89 ) ;
V_87 += V_89 ;
V_88 = 0 ;
V_60 = F_22 ( V_60 , V_59 -> V_70 ) ;
}
V_59 -> V_60 = V_60 ;
F_23 () ;
V_4 -> V_80 . V_112 ++ ;
} else if ( V_29 -> V_113 == V_114 ) {
if ( V_76 == V_115 ) {
V_82 = F_42 ( V_29 ) -> V_76 ;
if ( V_82 == V_116 )
V_83 = V_117 ;
else if ( V_82 == V_118 )
V_83 = V_119 ;
} else if ( V_76 == V_104 ) {
V_82 = F_43 ( V_29 ) -> V_120 ;
if ( V_82 == V_116 )
V_83 = V_121 ;
else if ( V_82 == V_118 )
V_83 = V_122 ;
}
}
V_71 -> V_108 += F_35 ( V_29 ) ;
V_71 -> V_109 += F_44 ( V_29 ) ;
F_33 ( V_71 , V_85 , V_83 ) ;
return 0 ;
}
static int F_45 ( struct V_123 * V_124 , struct V_28 * V_29 ,
struct V_125 * V_126 )
{
struct V_127 * V_128 ;
struct V_129 * V_130 ;
int V_131 , V_132 ;
T_5 V_133 ;
V_132 = F_37 ( V_29 ) -> V_132 ;
V_128 = & V_126 -> V_134 [ 0 ] ;
V_133 = F_46 ( V_124 , V_29 -> V_33 , F_47 ( V_29 ) ,
V_135 ) ;
if ( F_48 ( V_124 , V_133 ) )
goto V_136;
V_128 -> V_137 = V_133 ;
V_128 -> V_138 = F_47 ( V_29 ) ;
for ( V_131 = 0 ; V_131 < V_132 ; V_131 ++ ) {
V_130 = & F_37 ( V_29 ) -> V_139 [ V_131 ] ;
V_128 = & V_126 -> V_134 [ V_131 + 1 ] ;
V_133 = F_49 ( & V_124 -> V_140 , V_130 , 0 , F_50 ( V_130 ) ,
V_141 ) ;
if ( F_51 ( & V_124 -> V_140 , V_133 ) )
goto V_142;
V_128 -> V_137 = V_133 ;
V_128 -> V_138 = F_50 ( V_130 ) ;
}
return 0 ;
V_142:
while ( -- V_131 >= 0 ) {
V_128 = & V_126 -> V_134 [ V_131 + 1 ] ;
F_52 ( V_124 , V_128 -> V_137 , V_128 -> V_138 , V_135 ) ;
}
V_128 = & V_126 -> V_134 [ 0 ] ;
F_53 ( V_124 , V_128 -> V_137 , F_47 ( V_29 ) , V_135 ) ;
V_136:
return - V_143 ;
}
static void F_54 ( struct V_123 * V_124 , struct V_28 * V_29 ,
struct V_125 * V_126 )
{
struct V_127 * V_128 = & V_126 -> V_134 [ 0 ] ;
int V_131 , V_132 = F_37 ( V_29 ) -> V_132 ;
for ( V_131 = 0 ; V_131 < V_132 ; V_131 ++ ) {
V_128 = & V_126 -> V_134 [ V_131 + 1 ] ;
F_52 ( V_124 , V_128 -> V_137 , V_128 -> V_138 , V_135 ) ;
}
V_128 = & V_126 -> V_134 [ 0 ] ;
F_53 ( V_124 , V_128 -> V_137 , F_47 ( V_29 ) , V_135 ) ;
V_126 -> V_29 = NULL ;
}
static inline void F_55 ( T_2 * V_144 )
{
V_144 [ 0 ] = 0ULL ;
V_144 [ 2 ] = 0ULL ;
V_144 [ 7 ] = 0ULL ;
}
T_6 F_56 ( struct V_28 * V_29 , struct V_74 * V_75 )
{
struct V_3 * V_4 = F_57 ( V_75 ) ;
struct V_58 * V_59 ;
struct V_125 * V_126 ;
struct V_127 * V_145 ;
struct V_50 * V_51 , * V_71 ;
struct V_123 * V_124 ;
struct V_31 * V_32 ;
int V_131 , V_146 , V_147 , V_148 = 0 ;
T_4 V_60 , V_149 ;
if ( ! F_58 ( V_150 , & V_4 -> V_151 ) ) {
F_59 ( V_75 ) ;
return V_152 ;
}
if ( V_4 -> V_85 & V_153 ) {
V_32 = (struct V_31 * ) V_29 -> V_33 ;
if ( ! F_11 ( V_32 -> V_36 , V_4 -> V_69 ) )
goto V_154;
}
V_59 = & V_4 -> V_59 [ F_60 ( V_29 ) ] ;
V_149 = V_59 -> V_70 ;
V_147 = F_37 ( V_29 ) -> V_132 + 1 ;
if ( ! F_34 ( V_29 ) && V_147 > V_155 ) {
for ( V_131 = 0 ; V_131 < ( V_147 - V_155 ) ; V_131 ++ )
V_148 += F_50 ( & F_37 ( V_29 ) -> V_139 [ V_131 ] ) ;
if ( ! F_61 ( V_29 , V_148 ) )
goto V_154;
V_147 = 1 + F_37 ( V_29 ) -> V_132 ;
}
if ( F_31 ( F_62 ( V_59 ) <= V_156 ) ) {
F_63 ( V_59 -> V_157 ) ;
if ( F_62 ( V_59 ) > V_156 ) {
F_64 ( V_59 -> V_157 ) ;
} else {
V_59 -> V_158 . V_159 ++ ;
return V_152 ;
}
}
V_60 = V_59 -> V_60 ;
V_126 = & V_59 -> V_110 [ V_60 ] ;
V_124 = V_4 -> V_124 ;
V_71 = & V_59 -> V_62 [ V_60 ] ;
V_51 = & V_59 -> V_62 [ V_60 ] ;
F_55 ( ( T_2 * ) V_51 ) ;
if ( F_45 ( V_124 , V_29 , V_126 ) ) {
V_4 -> V_80 . V_160 ++ ;
goto V_154;
}
V_126 -> V_29 = V_29 ;
V_126 -> V_147 = V_147 ;
F_65 ( V_71 , V_147 , V_29 -> V_161 ) ;
F_66 ( V_71 , V_4 -> V_66 ) ;
for ( V_131 = 0 ; V_131 < V_147 ; V_131 ++ ) {
V_146 = V_131 % 4 ;
if ( ( V_146 == 0 ) && ( V_131 > 0 ) ) {
V_60 = F_22 ( V_60 , V_149 ) ;
V_51 = & V_59 -> V_62 [ V_60 ] ;
F_55 ( ( T_2 * ) V_51 ) ;
V_59 -> V_110 [ V_60 ] . V_29 = NULL ;
}
V_145 = & V_126 -> V_134 [ V_131 ] ;
V_51 -> V_162 [ V_146 ] = F_21 ( V_145 -> V_138 ) ;
switch ( V_146 ) {
case 0 :
V_51 -> V_163 = F_20 ( V_145 -> V_137 ) ;
break;
case 1 :
V_51 -> V_164 = F_20 ( V_145 -> V_137 ) ;
break;
case 2 :
V_51 -> V_165 = F_20 ( V_145 -> V_137 ) ;
break;
case 3 :
V_51 -> V_166 = F_20 ( V_145 -> V_137 ) ;
break;
}
}
V_59 -> V_60 = F_22 ( V_60 , V_149 ) ;
F_23 () ;
if ( F_31 ( F_30 ( V_4 , V_71 , V_29 , V_59 ) ) )
goto V_167;
if ( V_4 -> V_168 )
F_24 ( V_4 , V_71 , V_29 ) ;
V_59 -> V_158 . V_169 += V_29 -> V_161 ;
V_59 -> V_158 . V_170 ++ ;
F_67 ( V_59 ) ;
return V_171 ;
V_167:
F_54 ( V_124 , V_29 , V_126 ) ;
V_154:
V_4 -> V_80 . V_172 ++ ;
F_68 ( V_29 ) ;
return V_171 ;
}
void F_69 ( struct V_3 * V_4 , int V_173 )
{
struct V_74 * V_75 = V_4 -> V_75 ;
if ( V_4 -> V_174 -> V_173 && ! V_173 ) {
F_28 ( V_75 , L_2 ) ;
V_4 -> V_174 -> V_173 = 0 ;
F_70 ( V_75 ) ;
} else if ( ! V_4 -> V_174 -> V_173 && V_173 ) {
V_4 -> V_174 -> V_173 = 1 ;
if ( F_3 ( V_4 ) && V_4 -> V_174 -> V_175 ) {
F_28 ( V_75 , L_3 ) ;
return;
}
F_28 ( V_75 , L_4 ) ;
F_71 ( V_75 ) ;
}
}
static int F_72 ( struct V_3 * V_4 ,
struct V_176 * V_177 ,
struct V_178 * V_179 )
{
struct V_28 * V_29 ;
T_5 V_137 ;
struct V_123 * V_124 = V_4 -> V_124 ;
V_29 = F_73 ( V_4 -> V_75 , V_177 -> V_180 ) ;
if ( ! V_29 ) {
V_4 -> V_80 . V_181 ++ ;
return - V_143 ;
}
F_74 ( V_29 , V_182 ) ;
V_137 = F_46 ( V_124 , V_29 -> V_33 ,
V_177 -> V_183 , V_184 ) ;
if ( F_48 ( V_124 , V_137 ) ) {
V_4 -> V_80 . V_185 ++ ;
F_68 ( V_29 ) ;
return - V_143 ;
}
V_179 -> V_29 = V_29 ;
V_179 -> V_137 = V_137 ;
return 0 ;
}
static void F_75 ( struct V_3 * V_4 ,
struct V_176 * V_177 ,
T_1 V_6 )
{
struct V_186 * V_187 ;
struct V_178 * V_179 ;
int V_188 = 0 ;
T_7 V_60 , V_5 ;
struct V_189 * V_23 ;
if ( ! F_76 ( & V_177 -> V_190 ) )
return;
V_60 = V_177 -> V_60 ;
V_23 = & V_177 -> V_191 ;
while ( ! F_77 ( V_23 ) ) {
V_179 = F_78 ( V_23 -> V_192 , struct V_178 , V_193 ) ;
if ( ! V_179 -> V_29 ) {
if ( F_72 ( V_4 , V_177 , V_179 ) )
break;
}
V_188 ++ ;
F_79 ( & V_179 -> V_193 ) ;
V_187 = & V_177 -> V_62 [ V_60 ] ;
V_5 = F_2 ( V_4 ,
V_179 -> V_194 , V_6 ) ;
V_187 -> V_195 = F_21 ( V_5 ) ;
V_187 -> V_162 = F_80 ( V_177 -> V_183 ) ;
V_187 -> V_196 = F_20 ( V_179 -> V_137 ) ;
V_60 = F_22 ( V_60 , V_177 -> V_70 ) ;
}
if ( V_188 ) {
V_177 -> V_60 = V_60 ;
F_81 ( ( V_60 - 1 ) & ( V_177 -> V_70 - 1 ) ,
V_177 -> V_197 ) ;
}
F_18 ( & V_177 -> V_190 ) ;
}
static int F_82 ( struct V_3 * V_4 ,
struct V_58 * V_59 ,
int V_198 )
{
T_4 V_199 , V_200 ;
int V_131 , V_201 , V_188 = 0 ;
struct V_125 * V_179 ;
struct V_123 * V_124 = V_4 -> V_124 ;
struct V_74 * V_75 = V_4 -> V_75 ;
struct V_127 * V_130 ;
if ( ! F_76 ( & V_59 -> V_202 ) )
return 1 ;
V_199 = V_59 -> V_199 ;
V_200 = F_83 ( * ( V_59 -> V_200 ) ) ;
while ( V_199 != V_200 ) {
V_179 = & V_59 -> V_110 [ V_199 ] ;
if ( V_179 -> V_29 ) {
V_130 = & V_179 -> V_134 [ 0 ] ;
F_53 ( V_124 , V_130 -> V_137 , V_130 -> V_138 ,
V_135 ) ;
V_130 -> V_137 = 0ULL ;
for ( V_131 = 1 ; V_131 < V_179 -> V_147 ; V_131 ++ ) {
V_130 ++ ;
F_52 ( V_124 , V_130 -> V_137 , V_130 -> V_138 ,
V_135 ) ;
V_130 -> V_137 = 0ULL ;
}
V_59 -> V_158 . V_203 ++ ;
F_68 ( V_179 -> V_29 ) ;
V_179 -> V_29 = NULL ;
}
V_199 = F_22 ( V_199 , V_59 -> V_70 ) ;
if ( ++ V_188 >= V_198 )
break;
}
V_59 -> V_199 = V_199 ;
if ( V_188 && F_84 ( V_75 ) ) {
F_23 () ;
if ( F_85 ( V_59 -> V_157 ) &&
F_86 ( V_75 ) ) {
if ( F_62 ( V_59 ) > V_156 ) {
F_87 ( V_59 -> V_157 ) ;
V_59 -> V_158 . V_204 ++ ;
}
}
V_4 -> V_205 = 0 ;
}
V_200 = F_83 ( * ( V_59 -> V_200 ) ) ;
V_201 = ( V_199 == V_200 ) ;
F_18 ( & V_59 -> V_202 ) ;
return V_201 ;
}
static int F_88 ( struct V_206 * V_207 , int V_198 )
{
int V_208 , V_209 ;
struct V_210 * V_211 ;
struct V_3 * V_4 ;
struct V_58 * V_59 ;
V_211 = F_89 ( V_207 , struct V_210 , V_207 ) ;
V_4 = V_211 -> V_4 ;
V_59 = V_211 -> V_59 ;
V_208 = F_82 ( V_4 , V_59 ,
V_198 ) ;
V_209 = F_90 ( V_211 , V_198 ) ;
if ( ( V_209 < V_198 ) && V_208 ) {
F_91 ( & V_211 -> V_207 ) ;
if ( F_58 ( V_150 , & V_4 -> V_151 ) ) {
F_92 ( V_4 , V_211 ) ;
F_93 ( V_4 , V_59 ) ;
}
}
return V_209 ;
}
static int F_94 ( struct V_206 * V_207 , int V_198 )
{
struct V_58 * V_59 ;
struct V_3 * V_4 ;
int V_209 ;
V_59 = F_89 ( V_207 , struct V_58 , V_207 ) ;
V_4 = V_59 -> V_4 ;
V_209 = F_82 ( V_4 , V_59 , V_198 ) ;
if ( V_209 ) {
F_91 ( & V_59 -> V_207 ) ;
if ( F_58 ( V_150 , & V_4 -> V_151 ) )
F_93 ( V_4 , V_59 ) ;
}
return V_209 ;
}
static int F_95 ( struct V_206 * V_207 , int V_198 )
{
struct V_210 * V_211 ;
struct V_3 * V_4 ;
int V_209 ;
V_211 = F_89 ( V_207 , struct V_210 , V_207 ) ;
V_4 = V_211 -> V_4 ;
V_209 = F_90 ( V_211 , V_198 ) ;
if ( V_209 < V_198 ) {
F_91 ( & V_211 -> V_207 ) ;
if ( F_58 ( V_150 , & V_4 -> V_151 ) )
F_92 ( V_4 , V_211 ) ;
}
return V_209 ;
}
static void F_96 ( struct V_3 * V_4 ,
struct V_212 * V_213 )
{
T_4 V_214 ;
T_3 V_215 , V_216 ;
T_1 V_217 , V_218 , V_219 , V_220 , V_221 = 0 ;
struct V_74 * V_75 = V_4 -> V_75 ;
V_4 -> V_174 -> V_222 = 1 ;
V_214 = V_213 -> V_223 [ 1 ] & 0xffffffff ;
V_215 = ( V_213 -> V_223 [ 1 ] >> 32 ) & 0xffff ;
V_216 = ( V_213 -> V_223 [ 1 ] >> 48 ) & 0xffff ;
V_217 = V_213 -> V_223 [ 2 ] & 0xff ;
V_219 = ( V_213 -> V_223 [ 2 ] >> 16 ) & 0xff ;
V_220 = ( V_213 -> V_223 [ 2 ] >> 24 ) & 0xff ;
V_221 = ( V_213 -> V_223 [ 2 ] >> 32 ) & 0x3 ;
V_218 = ( V_213 -> V_223 [ 2 ] >> 8 ) & 0xff ;
if ( V_218 == V_224 )
F_97 ( & V_75 -> V_140 ,
L_5 ,
V_214 , V_215 ) ;
else if ( V_218 == V_225 )
F_97 ( & V_75 -> V_140 , L_6 ,
V_215 ) ;
if ( ! V_217 && ( V_221 == V_226 ||
V_221 == V_227 ) )
V_4 -> V_174 -> V_228 |= V_229 ;
F_69 ( V_4 , V_217 ) ;
if ( V_219 == V_230 )
V_4 -> V_174 -> V_231 = V_232 ;
else
V_4 -> V_174 -> V_231 = V_233 ;
V_4 -> V_174 -> V_234 = V_218 ;
V_4 -> V_174 -> V_235 = V_220 ;
if ( V_217 ) {
V_4 -> V_174 -> V_216 = V_216 ;
} else {
V_4 -> V_174 -> V_216 = V_236 ;
V_4 -> V_174 -> V_231 = V_237 ;
}
}
static void F_98 ( int V_238 , int V_239 ,
struct V_210 * V_211 )
{
struct V_212 V_213 ;
struct V_240 * V_144 ;
struct V_3 * V_4 ;
struct V_241 * V_140 ;
int V_131 = 0 , V_83 , V_13 ;
while ( V_238 > 0 && V_131 < 8 ) {
V_144 = & V_211 -> V_62 [ V_239 ] ;
V_213 . V_68 [ V_131 ++ ] = F_99 ( V_144 -> V_242 [ 0 ] ) ;
V_213 . V_68 [ V_131 ++ ] = F_99 ( V_144 -> V_242 [ 1 ] ) ;
V_239 = F_22 ( V_239 , V_211 -> V_70 ) ;
V_238 -- ;
}
V_4 = V_211 -> V_4 ;
V_140 = & V_4 -> V_124 -> V_140 ;
V_83 = F_100 ( V_213 . V_223 [ 0 ] ) ;
switch ( V_83 ) {
case V_243 :
F_96 ( V_4 , & V_213 ) ;
break;
case V_244 :
V_13 = ( T_4 ) ( V_213 . V_223 [ 1 ] ) ;
switch ( V_13 ) {
case 0 :
V_4 -> V_174 -> V_228 |= V_245 ;
break;
case 1 :
F_97 ( V_140 , L_7 ) ;
V_4 -> V_174 -> V_246 = - V_247 ;
break;
case 2 :
F_97 ( V_140 , L_8 ) ;
V_4 -> V_174 -> V_246 = - V_248 ;
break;
default:
F_97 ( V_140 ,
L_9 ,
V_13 ) ;
V_4 -> V_174 -> V_246 = - V_96 ;
break;
}
break;
case V_249 :
F_101 ( V_4 -> V_250 , ( void * ) & V_213 ) ;
break;
default:
break;
}
}
static struct V_28 * F_102 ( struct V_3 * V_4 ,
struct V_176 * V_251 ,
T_3 V_239 , T_3 V_252 )
{
struct V_178 * V_179 ;
struct V_28 * V_29 ;
V_179 = & V_251 -> V_253 [ V_239 ] ;
if ( F_31 ( V_179 -> V_29 == NULL ) ) {
F_103 ( 1 ) ;
return NULL ;
}
F_53 ( V_4 -> V_124 , V_179 -> V_137 , V_251 -> V_183 ,
V_184 ) ;
V_29 = V_179 -> V_29 ;
if ( F_104 ( ( V_4 -> V_75 -> V_254 & V_255 ) &&
( V_252 == V_256 || V_252 == V_8 ) ) ) {
V_4 -> V_80 . V_257 ++ ;
V_29 -> V_113 = V_258 ;
} else {
F_105 ( V_29 ) ;
}
V_179 -> V_29 = NULL ;
return V_29 ;
}
static inline int F_106 ( struct V_3 * V_4 ,
struct V_28 * V_29 , T_3 * V_259 )
{
struct V_31 * V_260 ;
if ( ! F_107 ( V_29 , V_259 ) ) {
V_260 = (struct V_31 * ) V_29 -> V_33 ;
memmove ( V_29 -> V_33 + V_107 , V_260 , V_37 * 2 ) ;
F_108 ( V_29 , V_107 ) ;
}
if ( ! V_4 -> V_261 )
return 0 ;
if ( * V_259 == V_4 -> V_261 ) {
* V_259 = 0xffff ;
return 0 ;
}
if ( V_4 -> V_85 & V_95 )
return 0 ;
return - V_262 ;
}
static struct V_178 *
F_109 ( struct V_3 * V_4 ,
struct V_210 * V_211 , int V_251 ,
T_2 V_263 )
{
struct V_74 * V_75 = V_4 -> V_75 ;
struct V_264 * V_265 = V_4 -> V_265 ;
struct V_178 * V_179 ;
struct V_28 * V_29 ;
struct V_176 * V_177 ;
int V_239 , V_138 , V_252 , V_266 , V_267 ;
T_3 V_268 = 0xffff , V_269 ;
if ( F_31 ( V_251 >= V_4 -> V_270 ) )
return NULL ;
V_177 = & V_265 -> V_271 [ V_251 ] ;
V_239 = F_110 ( V_263 ) ;
if ( F_31 ( V_239 >= V_177 -> V_70 ) )
return NULL ;
V_179 = & V_177 -> V_253 [ V_239 ] ;
V_138 = F_111 ( V_263 ) ;
V_252 = F_5 ( V_263 ) ;
V_266 = F_112 ( V_263 ) ;
V_29 = F_102 ( V_4 , V_177 , V_239 , V_252 ) ;
if ( ! V_29 )
return V_179 ;
if ( V_4 -> V_168 &&
( V_4 -> V_85 & V_272 ) ) {
V_269 = 0 ;
V_267 = F_4 ( V_263 ) ;
F_12 ( V_4 , V_29 , V_267 , V_269 ) ;
}
if ( V_138 > V_177 -> V_180 )
F_113 ( V_29 , V_177 -> V_180 ) ;
else
F_113 ( V_29 , V_138 ) ;
if ( V_266 )
F_108 ( V_29 , V_266 ) ;
if ( F_31 ( F_106 ( V_4 , V_29 , & V_268 ) ) ) {
V_4 -> V_80 . V_273 ++ ;
F_114 ( V_29 ) ;
return V_179 ;
}
V_29 -> V_76 = F_115 ( V_29 , V_75 ) ;
if ( V_268 != 0xffff )
F_116 ( V_29 , F_40 ( V_78 ) , V_268 ) ;
F_117 ( & V_211 -> V_207 , V_29 ) ;
V_4 -> V_80 . V_274 ++ ;
V_4 -> V_80 . V_275 += V_138 ;
return V_179 ;
}
static struct V_178 *
F_118 ( struct V_3 * V_4 ,
int V_251 , T_2 V_263 , T_2 V_276 )
{
struct V_74 * V_75 = V_4 -> V_75 ;
struct V_264 * V_265 = V_4 -> V_265 ;
struct V_178 * V_179 ;
struct V_28 * V_29 ;
struct V_176 * V_177 ;
struct V_277 * V_278 ;
struct V_279 * V_280 ;
struct V_281 * V_282 ;
bool V_283 , V_284 ;
int V_239 , V_285 , V_286 , V_267 ;
T_3 V_287 , V_138 , V_288 , V_269 , V_268 = 0xffff ;
T_4 V_289 ;
if ( F_31 ( V_251 >= V_4 -> V_270 ) )
return NULL ;
V_177 = & V_265 -> V_271 [ V_251 ] ;
V_239 = F_119 ( V_263 ) ;
if ( F_31 ( V_239 >= V_177 -> V_70 ) )
return NULL ;
V_179 = & V_177 -> V_253 [ V_239 ] ;
V_284 = F_120 ( V_263 ) ;
V_287 = F_121 ( V_263 ) ;
V_285 = F_122 ( V_263 ) ;
V_286 = F_123 ( V_263 ) ;
V_283 = F_124 ( V_263 ) ;
V_289 = F_125 ( V_276 ) ;
V_29 = F_102 ( V_4 , V_177 , V_239 , V_256 ) ;
if ( ! V_29 )
return V_179 ;
if ( V_4 -> V_168 &&
( V_4 -> V_85 & V_272 ) ) {
V_269 = 0 ;
V_267 = F_4 ( V_263 ) ;
F_12 ( V_4 , V_29 , V_267 , V_269 ) ;
}
if ( V_284 )
V_288 = V_286 + V_290 ;
else
V_288 = V_286 + V_291 ;
F_113 ( V_29 , V_287 + V_288 ) ;
F_108 ( V_29 , V_285 ) ;
if ( F_31 ( F_106 ( V_4 , V_29 , & V_268 ) ) ) {
V_4 -> V_80 . V_273 ++ ;
F_114 ( V_29 ) ;
return V_179 ;
}
V_29 -> V_76 = F_115 ( V_29 , V_75 ) ;
if ( F_25 ( V_29 -> V_76 ) == V_104 ) {
V_280 = (struct V_279 * ) V_29 -> V_33 ;
V_282 = (struct V_281 * ) ( V_29 -> V_33 + sizeof( struct V_279 ) ) ;
V_138 = ( V_282 -> V_292 << 2 ) + V_287 ;
V_280 -> V_293 = F_40 ( V_138 ) ;
} else {
V_278 = (struct V_277 * ) V_29 -> V_33 ;
V_282 = (struct V_281 * ) ( V_29 -> V_33 + ( V_278 -> V_294 << 2 ) ) ;
V_138 = ( V_278 -> V_294 << 2 ) + ( V_282 -> V_292 << 2 ) + V_287 ;
F_126 ( & V_278 -> V_295 , V_278 -> V_296 , F_40 ( V_138 ) ) ;
V_278 -> V_296 = F_40 ( V_138 ) ;
}
V_282 -> V_297 = V_283 ;
V_282 -> V_298 = F_127 ( V_289 ) ;
V_138 = V_29 -> V_161 ;
if ( V_4 -> V_85 & V_299 ) {
F_37 ( V_29 ) -> V_102 = F_128 ( V_276 ) ;
if ( V_29 -> V_76 == F_40 ( V_104 ) )
F_37 ( V_29 ) -> V_300 = V_301 ;
else
F_37 ( V_29 ) -> V_300 = V_302 ;
}
if ( V_268 != 0xffff )
F_116 ( V_29 , F_40 ( V_78 ) , V_268 ) ;
F_129 ( V_29 ) ;
V_4 -> V_80 . V_303 ++ ;
V_4 -> V_80 . V_304 += V_138 ;
return V_179 ;
}
static int F_90 ( struct V_210 * V_211 , int V_305 )
{
struct V_176 * V_177 ;
struct V_3 * V_4 = V_211 -> V_4 ;
struct V_189 * V_306 ;
struct V_240 * V_144 ;
struct V_178 * V_307 ;
int V_83 , V_238 , V_188 = 0 ;
T_2 V_263 , V_276 ;
T_1 V_251 ;
T_4 V_308 = V_211 -> V_308 ;
while ( V_188 < V_305 ) {
V_144 = & V_211 -> V_62 [ V_308 ] ;
V_263 = F_99 ( V_144 -> V_242 [ 0 ] ) ;
if ( ! ( V_263 & V_309 ) )
break;
V_238 = F_130 ( V_263 ) ;
V_83 = F_131 ( V_263 ) ;
switch ( V_83 ) {
case V_310 :
case V_311 :
case V_312 :
V_251 = F_132 ( V_263 ) ;
V_307 = F_109 ( V_4 , V_211 , V_251 ,
V_263 ) ;
break;
case V_313 :
V_251 = F_133 ( V_263 ) ;
V_276 = F_99 ( V_144 -> V_242 [ 1 ] ) ;
V_307 = F_118 ( V_4 , V_251 , V_263 ,
V_276 ) ;
break;
case V_314 :
F_98 ( V_238 , V_308 , V_211 ) ;
default:
goto V_315;
}
F_103 ( V_238 > 1 ) ;
if ( F_104 ( V_307 ) )
F_134 ( & V_307 -> V_193 , & V_211 -> V_191 [ V_251 ] ) ;
else
V_4 -> V_80 . V_316 ++ ;
V_315:
for (; V_238 > 0 ; V_238 -- ) {
V_144 = & V_211 -> V_62 [ V_308 ] ;
V_144 -> V_242 [ 0 ] = V_317 ;
V_308 = F_22 ( V_308 , V_211 -> V_70 ) ;
}
V_188 ++ ;
}
for ( V_251 = 0 ; V_251 < V_4 -> V_270 ; V_251 ++ ) {
V_177 = & V_4 -> V_265 -> V_271 [ V_251 ] ;
if ( ! F_77 ( & V_211 -> V_191 [ V_251 ] ) ) {
F_135 (cur, &sds_ring->free_list[ring]) {
V_307 = F_78 ( V_306 , struct V_178 ,
V_193 ) ;
F_72 ( V_4 , V_177 , V_307 ) ;
}
F_16 ( & V_177 -> V_190 ) ;
F_136 ( & V_211 -> V_191 [ V_251 ] ,
& V_177 -> V_191 ) ;
F_18 ( & V_177 -> V_190 ) ;
}
F_75 ( V_4 , V_177 , V_251 ) ;
}
if ( V_188 ) {
V_211 -> V_308 = V_308 ;
F_81 ( V_308 , V_211 -> V_318 ) ;
}
return V_188 ;
}
void F_137 ( struct V_3 * V_4 ,
struct V_176 * V_177 , T_1 V_6 )
{
struct V_186 * V_187 ;
struct V_178 * V_179 ;
int V_188 = 0 ;
T_4 V_60 , V_5 ;
struct V_189 * V_23 ;
V_60 = V_177 -> V_60 ;
V_23 = & V_177 -> V_191 ;
while ( ! F_77 ( V_23 ) ) {
V_179 = F_78 ( V_23 -> V_192 , struct V_178 , V_193 ) ;
if ( ! V_179 -> V_29 ) {
if ( F_72 ( V_4 , V_177 , V_179 ) )
break;
}
V_188 ++ ;
F_79 ( & V_179 -> V_193 ) ;
V_187 = & V_177 -> V_62 [ V_60 ] ;
V_187 -> V_196 = F_20 ( V_179 -> V_137 ) ;
V_5 = F_2 ( V_4 , V_179 -> V_194 ,
V_6 ) ;
V_187 -> V_195 = F_21 ( V_5 ) ;
V_187 -> V_162 = F_80 ( V_177 -> V_183 ) ;
V_60 = F_22 ( V_60 , V_177 -> V_70 ) ;
}
if ( V_188 ) {
V_177 -> V_60 = V_60 ;
F_81 ( ( V_60 - 1 ) & ( V_177 -> V_70 - 1 ) ,
V_177 -> V_197 ) ;
}
}
static void F_138 ( struct V_28 * V_29 , struct V_3 * V_4 )
{
int V_131 ;
unsigned char * V_33 = V_29 -> V_33 ;
F_139 ( V_319 L_10 ) ;
for ( V_131 = 0 ; V_131 < V_29 -> V_161 ; V_131 ++ ) {
F_140 ( V_4 , V_320 , L_11 , V_33 [ V_131 ] ) ;
if ( ( V_131 & 0x0f ) == 8 )
F_139 ( V_319 L_10 ) ;
}
}
static void F_141 ( struct V_3 * V_4 , int V_251 ,
T_2 V_263 )
{
struct V_264 * V_265 = V_4 -> V_265 ;
struct V_28 * V_29 ;
struct V_176 * V_177 ;
int V_239 , V_138 , V_252 , V_266 ;
if ( F_31 ( V_251 >= V_4 -> V_270 ) )
return;
V_177 = & V_265 -> V_271 [ V_251 ] ;
V_239 = F_110 ( V_263 ) ;
V_138 = F_111 ( V_263 ) ;
if ( F_31 ( V_239 >= V_177 -> V_70 ) )
return;
V_252 = F_5 ( V_263 ) ;
V_266 = F_112 ( V_263 ) ;
V_29 = F_102 ( V_4 , V_177 , V_239 , V_252 ) ;
if ( ! V_29 )
return;
if ( V_138 > V_177 -> V_180 )
F_113 ( V_29 , V_177 -> V_180 ) ;
else
F_113 ( V_29 , V_138 ) ;
if ( V_266 )
F_108 ( V_29 , V_266 ) ;
if ( ! F_142 ( V_29 -> V_33 , V_4 -> V_69 ) )
V_4 -> V_174 -> V_246 ++ ;
else
F_138 ( V_29 , V_4 ) ;
F_68 ( V_29 ) ;
V_4 -> V_80 . V_274 ++ ;
V_4 -> V_80 . V_275 += V_138 ;
return;
}
void F_143 ( struct V_210 * V_211 )
{
struct V_3 * V_4 = V_211 -> V_4 ;
struct V_240 * V_144 ;
T_2 V_263 ;
int V_251 , V_83 , V_238 ;
T_4 V_308 = V_211 -> V_308 ;
V_144 = & V_211 -> V_62 [ V_308 ] ;
V_263 = F_99 ( V_144 -> V_242 [ 0 ] ) ;
if ( ! ( V_263 & V_309 ) )
return;
V_238 = F_130 ( V_263 ) ;
V_83 = F_131 ( V_263 ) ;
switch ( V_83 ) {
case V_314 :
F_98 ( V_238 , V_308 , V_211 ) ;
break;
default:
V_251 = F_132 ( V_263 ) ;
F_141 ( V_4 , V_251 , V_263 ) ;
break;
}
for (; V_238 > 0 ; V_238 -- ) {
V_144 = & V_211 -> V_62 [ V_308 ] ;
V_144 -> V_242 [ 0 ] = F_20 ( V_321 ) ;
V_308 = F_22 ( V_308 , V_211 -> V_70 ) ;
}
V_211 -> V_308 = V_308 ;
F_81 ( V_308 , V_211 -> V_318 ) ;
}
int F_144 ( struct V_3 * V_4 ,
struct V_74 * V_75 )
{
int V_251 ;
struct V_210 * V_211 ;
struct V_264 * V_265 = V_4 -> V_265 ;
struct V_58 * V_59 ;
if ( F_145 ( V_265 , V_4 -> V_322 ) )
return - V_143 ;
for ( V_251 = 0 ; V_251 < V_4 -> V_322 ; V_251 ++ ) {
V_211 = & V_265 -> V_323 [ V_251 ] ;
if ( F_146 ( V_4 ) &&
! V_4 -> V_174 -> V_324 ) {
F_147 ( V_75 , & V_211 -> V_207 , F_95 ,
V_325 ) ;
} else {
if ( V_251 == ( V_4 -> V_322 - 1 ) )
F_147 ( V_75 , & V_211 -> V_207 ,
F_88 ,
V_325 ) ;
else
F_147 ( V_75 , & V_211 -> V_207 ,
F_95 ,
V_325 ) ;
}
}
if ( F_148 ( V_4 , V_75 ) ) {
F_149 ( V_265 ) ;
return - V_143 ;
}
if ( F_146 ( V_4 ) && ! V_4 -> V_174 -> V_324 ) {
for ( V_251 = 0 ; V_251 < V_4 -> V_326 ; V_251 ++ ) {
V_59 = & V_4 -> V_59 [ V_251 ] ;
F_147 ( V_75 , & V_59 -> V_207 , F_94 ,
V_325 ) ;
}
}
return 0 ;
}
void F_150 ( struct V_3 * V_4 )
{
int V_251 ;
struct V_210 * V_211 ;
struct V_264 * V_265 = V_4 -> V_265 ;
struct V_58 * V_59 ;
for ( V_251 = 0 ; V_251 < V_4 -> V_322 ; V_251 ++ ) {
V_211 = & V_265 -> V_323 [ V_251 ] ;
F_151 ( & V_211 -> V_207 ) ;
}
F_149 ( V_4 -> V_265 ) ;
if ( F_146 ( V_4 ) && ! V_4 -> V_174 -> V_324 ) {
for ( V_251 = 0 ; V_251 < V_4 -> V_326 ; V_251 ++ ) {
V_59 = & V_4 -> V_59 [ V_251 ] ;
F_151 ( & V_59 -> V_207 ) ;
}
}
F_152 ( V_4 ) ;
}
void F_153 ( struct V_3 * V_4 )
{
int V_251 ;
struct V_210 * V_211 ;
struct V_58 * V_59 ;
struct V_264 * V_265 = V_4 -> V_265 ;
if ( V_4 -> V_327 != V_328 )
return;
for ( V_251 = 0 ; V_251 < V_4 -> V_322 ; V_251 ++ ) {
V_211 = & V_265 -> V_323 [ V_251 ] ;
F_154 ( & V_211 -> V_207 ) ;
F_92 ( V_4 , V_211 ) ;
}
if ( F_146 ( V_4 ) &&
( V_4 -> V_85 & V_329 ) &&
! V_4 -> V_174 -> V_324 ) {
for ( V_251 = 0 ; V_251 < V_4 -> V_326 ; V_251 ++ ) {
V_59 = & V_4 -> V_59 [ V_251 ] ;
F_154 ( & V_59 -> V_207 ) ;
F_93 ( V_4 , V_59 ) ;
}
}
}
void F_155 ( struct V_3 * V_4 )
{
int V_251 ;
struct V_210 * V_211 ;
struct V_58 * V_59 ;
struct V_264 * V_265 = V_4 -> V_265 ;
if ( V_4 -> V_327 != V_328 )
return;
for ( V_251 = 0 ; V_251 < V_4 -> V_322 ; V_251 ++ ) {
V_211 = & V_265 -> V_323 [ V_251 ] ;
F_156 ( V_4 , V_211 ) ;
F_157 ( & V_211 -> V_207 ) ;
F_158 ( & V_211 -> V_207 ) ;
}
if ( ( V_4 -> V_85 & V_329 ) &&
! V_4 -> V_174 -> V_324 &&
F_146 ( V_4 ) ) {
for ( V_251 = 0 ; V_251 < V_4 -> V_326 ; V_251 ++ ) {
V_59 = & V_4 -> V_59 [ V_251 ] ;
F_159 ( V_4 , V_59 ) ;
F_157 ( & V_59 -> V_207 ) ;
F_158 ( & V_59 -> V_207 ) ;
}
}
}
static inline int F_160 ( T_2 V_7 , int V_330 )
{
if ( V_330 )
return ( V_7 & V_331 ) ? 1 : 0 ;
else
return ( V_7 & V_332 ) ? 1 : 0 ;
}
static struct V_178 *
F_161 ( struct V_3 * V_4 ,
struct V_210 * V_211 ,
T_1 V_251 , T_2 V_7 [] )
{
struct V_74 * V_75 = V_4 -> V_75 ;
struct V_264 * V_265 = V_4 -> V_265 ;
struct V_178 * V_179 ;
struct V_28 * V_29 ;
struct V_176 * V_177 ;
int V_239 , V_138 , V_252 , V_267 ;
T_3 V_268 = 0xffff ;
int V_333 ;
if ( F_31 ( V_251 >= V_4 -> V_270 ) )
return NULL ;
V_177 = & V_265 -> V_271 [ V_251 ] ;
V_239 = F_162 ( V_7 [ 0 ] ) ;
if ( F_31 ( V_239 >= V_177 -> V_70 ) )
return NULL ;
V_179 = & V_177 -> V_253 [ V_239 ] ;
V_138 = F_163 ( V_7 [ 0 ] ) ;
V_252 = F_164 ( V_7 [ 1 ] ) ;
V_29 = F_102 ( V_4 , V_177 , V_239 , V_252 ) ;
if ( ! V_29 )
return V_179 ;
if ( V_138 > V_177 -> V_180 )
F_113 ( V_29 , V_177 -> V_180 ) ;
else
F_113 ( V_29 , V_138 ) ;
V_333 = F_106 ( V_4 , V_29 , & V_268 ) ;
if ( V_4 -> V_334 ) {
V_267 = F_160 ( V_7 [ 1 ] , 0 ) ;
F_12 ( V_4 , V_29 , V_267 , V_268 ) ;
}
if ( F_31 ( V_333 ) ) {
V_4 -> V_80 . V_273 ++ ;
F_114 ( V_29 ) ;
return V_179 ;
}
V_29 -> V_76 = F_115 ( V_29 , V_75 ) ;
if ( V_268 != 0xffff )
F_116 ( V_29 , F_40 ( V_78 ) , V_268 ) ;
F_117 ( & V_211 -> V_207 , V_29 ) ;
V_4 -> V_80 . V_274 ++ ;
V_4 -> V_80 . V_275 += V_138 ;
return V_179 ;
}
static struct V_178 *
F_165 ( struct V_3 * V_4 ,
T_1 V_251 , T_2 V_7 [] )
{
struct V_74 * V_75 = V_4 -> V_75 ;
struct V_264 * V_265 = V_4 -> V_265 ;
struct V_178 * V_179 ;
struct V_28 * V_29 ;
struct V_176 * V_177 ;
struct V_277 * V_278 ;
struct V_279 * V_280 ;
struct V_281 * V_282 ;
bool V_283 ;
int V_285 , V_286 ;
int V_239 , V_267 ;
T_3 V_287 , V_138 , V_288 , V_102 ;
T_3 V_268 = 0xffff ;
int V_333 ;
if ( F_31 ( V_251 >= V_4 -> V_270 ) )
return NULL ;
V_177 = & V_265 -> V_271 [ V_251 ] ;
V_239 = F_162 ( V_7 [ 0 ] ) ;
if ( F_31 ( V_239 >= V_177 -> V_70 ) )
return NULL ;
V_179 = & V_177 -> V_253 [ V_239 ] ;
V_287 = F_166 ( V_7 [ 0 ] ) ;
V_285 = F_167 ( V_7 [ 1 ] ) ;
V_286 = F_168 ( V_7 [ 1 ] ) ;
V_283 = F_169 ( V_7 [ 1 ] ) ;
V_29 = F_102 ( V_4 , V_177 , V_239 , V_256 ) ;
if ( ! V_29 )
return V_179 ;
if ( F_170 ( V_7 [ 1 ] ) )
V_288 = V_286 + V_335 ;
else
V_288 = V_286 + V_336 ;
F_113 ( V_29 , V_287 + V_288 ) ;
F_108 ( V_29 , V_285 ) ;
V_333 = F_106 ( V_4 , V_29 , & V_268 ) ;
if ( V_4 -> V_334 ) {
V_267 = F_160 ( V_7 [ 1 ] , 1 ) ;
F_12 ( V_4 , V_29 , V_267 , V_268 ) ;
}
if ( F_31 ( V_333 ) ) {
V_4 -> V_80 . V_273 ++ ;
F_114 ( V_29 ) ;
return V_179 ;
}
V_29 -> V_76 = F_115 ( V_29 , V_75 ) ;
if ( F_25 ( V_29 -> V_76 ) == V_104 ) {
V_280 = (struct V_279 * ) V_29 -> V_33 ;
V_282 = (struct V_281 * ) ( V_29 -> V_33 + sizeof( struct V_279 ) ) ;
V_138 = ( V_282 -> V_292 << 2 ) + V_287 ;
V_280 -> V_293 = F_40 ( V_138 ) ;
} else {
V_278 = (struct V_277 * ) V_29 -> V_33 ;
V_282 = (struct V_281 * ) ( V_29 -> V_33 + ( V_278 -> V_294 << 2 ) ) ;
V_138 = ( V_278 -> V_294 << 2 ) + ( V_282 -> V_292 << 2 ) + V_287 ;
F_126 ( & V_278 -> V_295 , V_278 -> V_296 , F_40 ( V_138 ) ) ;
V_278 -> V_296 = F_40 ( V_138 ) ;
}
V_282 -> V_297 = V_283 ;
V_138 = V_29 -> V_161 ;
if ( V_4 -> V_85 & V_299 ) {
V_102 = F_171 ( V_7 [ 0 ] ) ;
F_37 ( V_29 ) -> V_102 = V_102 ;
if ( V_29 -> V_76 == F_40 ( V_104 ) )
F_37 ( V_29 ) -> V_300 = V_301 ;
else
F_37 ( V_29 ) -> V_300 = V_302 ;
}
if ( V_268 != 0xffff )
F_116 ( V_29 , F_40 ( V_78 ) , V_268 ) ;
F_129 ( V_29 ) ;
V_4 -> V_80 . V_303 ++ ;
V_4 -> V_80 . V_304 += V_138 ;
return V_179 ;
}
static int F_172 ( struct V_210 * V_211 ,
int V_305 )
{
struct V_176 * V_177 ;
struct V_3 * V_4 = V_211 -> V_4 ;
struct V_189 * V_306 ;
struct V_240 * V_144 ;
struct V_178 * V_307 = NULL ;
T_1 V_251 ;
T_2 V_7 [ 2 ] ;
int V_188 = 0 , V_83 ;
T_4 V_308 = V_211 -> V_308 ;
while ( V_188 < V_305 ) {
V_144 = & V_211 -> V_62 [ V_308 ] ;
V_7 [ 1 ] = F_99 ( V_144 -> V_242 [ 1 ] ) ;
V_83 = F_173 ( V_7 [ 1 ] ) ;
if ( ! V_83 )
break;
V_7 [ 0 ] = F_99 ( V_144 -> V_242 [ 0 ] ) ;
V_251 = F_174 ( V_7 [ 0 ] ) ;
switch ( V_83 ) {
case V_337 :
V_307 = F_161 ( V_4 , V_211 ,
V_251 , V_7 ) ;
break;
case V_338 :
V_307 = F_165 ( V_4 , V_251 ,
V_7 ) ;
break;
default:
F_97 ( & V_4 -> V_124 -> V_140 ,
L_12 , V_83 ) ;
goto V_315;
}
if ( F_104 ( V_307 ) )
F_134 ( & V_307 -> V_193 , & V_211 -> V_191 [ V_251 ] ) ;
else
V_4 -> V_80 . V_316 ++ ;
V_315:
V_144 = & V_211 -> V_62 [ V_308 ] ;
V_144 -> V_242 [ 1 ] = 0 ;
V_308 = F_22 ( V_308 , V_211 -> V_70 ) ;
V_188 ++ ;
}
for ( V_251 = 0 ; V_251 < V_4 -> V_270 ; V_251 ++ ) {
V_177 = & V_4 -> V_265 -> V_271 [ V_251 ] ;
if ( ! F_77 ( & V_211 -> V_191 [ V_251 ] ) ) {
F_135 (cur, &sds_ring->free_list[ring]) {
V_307 = F_78 ( V_306 , struct V_178 ,
V_193 ) ;
F_72 ( V_4 , V_177 , V_307 ) ;
}
F_16 ( & V_177 -> V_190 ) ;
F_136 ( & V_211 -> V_191 [ V_251 ] ,
& V_177 -> V_191 ) ;
F_18 ( & V_177 -> V_190 ) ;
}
F_75 ( V_4 , V_177 , V_251 ) ;
}
if ( V_188 ) {
V_211 -> V_308 = V_308 ;
F_81 ( V_308 , V_211 -> V_318 ) ;
}
return V_188 ;
}
static int F_175 ( struct V_206 * V_207 , int V_198 )
{
int V_208 ;
int V_209 ;
struct V_210 * V_211 ;
struct V_3 * V_4 ;
struct V_58 * V_59 ;
V_211 = F_89 ( V_207 , struct V_210 , V_207 ) ;
V_4 = V_211 -> V_4 ;
V_59 = V_4 -> V_59 ;
V_208 = F_82 ( V_4 , V_59 , V_198 ) ;
V_209 = F_172 ( V_211 , V_198 ) ;
if ( ( V_209 < V_198 ) && V_208 ) {
F_91 ( & V_211 -> V_207 ) ;
F_92 ( V_4 , V_211 ) ;
}
return V_209 ;
}
static int F_176 ( struct V_206 * V_207 , int V_198 )
{
int V_208 ;
int V_209 ;
struct V_210 * V_211 ;
struct V_3 * V_4 ;
struct V_58 * V_59 ;
V_211 = F_89 ( V_207 , struct V_210 , V_207 ) ;
V_4 = V_211 -> V_4 ;
V_59 = V_4 -> V_59 ;
V_208 = F_82 ( V_4 , V_59 , V_198 ) ;
V_209 = F_172 ( V_211 , V_198 ) ;
if ( ( V_209 < V_198 ) && V_208 ) {
F_91 ( & V_211 -> V_207 ) ;
F_92 ( V_4 , V_211 ) ;
}
return V_209 ;
}
static int F_177 ( struct V_206 * V_207 , int V_198 )
{
int V_209 ;
struct V_58 * V_59 ;
struct V_3 * V_4 ;
V_198 = V_339 ;
V_59 = F_89 ( V_207 , struct V_58 , V_207 ) ;
V_4 = V_59 -> V_4 ;
V_209 = F_82 ( V_4 , V_59 , V_198 ) ;
if ( V_209 ) {
F_91 ( & V_59 -> V_207 ) ;
if ( F_58 ( V_150 , & V_4 -> V_151 ) )
F_93 ( V_4 , V_59 ) ;
}
return V_209 ;
}
static int F_178 ( struct V_206 * V_207 , int V_198 )
{
int V_209 ;
struct V_210 * V_211 ;
struct V_3 * V_4 ;
V_211 = F_89 ( V_207 , struct V_210 , V_207 ) ;
V_4 = V_211 -> V_4 ;
V_209 = F_172 ( V_211 , V_198 ) ;
if ( V_209 < V_198 ) {
F_91 ( & V_211 -> V_207 ) ;
if ( F_58 ( V_150 , & V_4 -> V_151 ) )
F_92 ( V_4 , V_211 ) ;
}
return V_209 ;
}
void F_179 ( struct V_3 * V_4 )
{
int V_251 ;
struct V_210 * V_211 ;
struct V_58 * V_59 ;
struct V_264 * V_265 = V_4 -> V_265 ;
if ( V_4 -> V_327 != V_328 )
return;
for ( V_251 = 0 ; V_251 < V_4 -> V_322 ; V_251 ++ ) {
V_211 = & V_265 -> V_323 [ V_251 ] ;
F_154 ( & V_211 -> V_207 ) ;
if ( V_4 -> V_85 & V_329 )
F_92 ( V_4 , V_211 ) ;
}
if ( ( V_4 -> V_85 & V_329 ) &&
! ( V_4 -> V_85 & V_340 ) ) {
for ( V_251 = 0 ; V_251 < V_4 -> V_326 ; V_251 ++ ) {
V_59 = & V_4 -> V_59 [ V_251 ] ;
F_154 ( & V_59 -> V_207 ) ;
F_93 ( V_4 , V_59 ) ;
}
}
}
void F_180 ( struct V_3 * V_4 )
{
int V_251 ;
struct V_210 * V_211 ;
struct V_264 * V_265 = V_4 -> V_265 ;
struct V_58 * V_59 ;
if ( V_4 -> V_327 != V_328 )
return;
for ( V_251 = 0 ; V_251 < V_4 -> V_322 ; V_251 ++ ) {
V_211 = & V_265 -> V_323 [ V_251 ] ;
if ( V_4 -> V_85 & V_329 )
F_156 ( V_4 , V_211 ) ;
F_157 ( & V_211 -> V_207 ) ;
F_158 ( & V_211 -> V_207 ) ;
}
if ( ( V_4 -> V_85 & V_329 ) &&
! ( V_4 -> V_85 & V_340 ) ) {
for ( V_251 = 0 ; V_251 < V_4 -> V_326 ; V_251 ++ ) {
V_59 = & V_4 -> V_59 [ V_251 ] ;
F_159 ( V_4 , V_59 ) ;
F_157 ( & V_59 -> V_207 ) ;
F_158 ( & V_59 -> V_207 ) ;
}
}
}
int F_181 ( struct V_3 * V_4 ,
struct V_74 * V_75 )
{
int V_251 ;
struct V_210 * V_211 ;
struct V_58 * V_59 ;
struct V_264 * V_265 = V_4 -> V_265 ;
if ( F_145 ( V_265 , V_4 -> V_322 ) )
return - V_143 ;
for ( V_251 = 0 ; V_251 < V_4 -> V_322 ; V_251 ++ ) {
V_211 = & V_265 -> V_323 [ V_251 ] ;
if ( V_4 -> V_85 & V_329 ) {
if ( ! ( V_4 -> V_85 & V_340 ) )
F_147 ( V_75 , & V_211 -> V_207 ,
F_178 ,
V_325 ) ;
else
F_147 ( V_75 , & V_211 -> V_207 ,
F_175 ,
V_325 ) ;
} else {
F_147 ( V_75 , & V_211 -> V_207 ,
F_176 ,
V_325 ) ;
}
}
if ( F_148 ( V_4 , V_75 ) ) {
F_149 ( V_265 ) ;
return - V_143 ;
}
if ( ( V_4 -> V_85 & V_329 ) &&
! ( V_4 -> V_85 & V_340 ) ) {
for ( V_251 = 0 ; V_251 < V_4 -> V_326 ; V_251 ++ ) {
V_59 = & V_4 -> V_59 [ V_251 ] ;
F_147 ( V_75 , & V_59 -> V_207 ,
F_177 ,
V_325 ) ;
}
}
return 0 ;
}
void F_182 ( struct V_3 * V_4 )
{
int V_251 ;
struct V_210 * V_211 ;
struct V_264 * V_265 = V_4 -> V_265 ;
struct V_58 * V_59 ;
for ( V_251 = 0 ; V_251 < V_4 -> V_322 ; V_251 ++ ) {
V_211 = & V_265 -> V_323 [ V_251 ] ;
F_151 ( & V_211 -> V_207 ) ;
}
F_149 ( V_4 -> V_265 ) ;
if ( ( V_4 -> V_85 & V_329 ) &&
! ( V_4 -> V_85 & V_340 ) ) {
for ( V_251 = 0 ; V_251 < V_4 -> V_326 ; V_251 ++ ) {
V_59 = & V_4 -> V_59 [ V_251 ] ;
F_151 ( & V_59 -> V_207 ) ;
}
}
F_152 ( V_4 ) ;
}
static void F_183 ( struct V_3 * V_4 ,
int V_251 , T_2 V_7 [] )
{
struct V_264 * V_265 = V_4 -> V_265 ;
struct V_28 * V_29 ;
struct V_176 * V_177 ;
int V_239 , V_138 ;
if ( F_31 ( V_251 >= V_4 -> V_270 ) )
return;
V_177 = & V_265 -> V_271 [ V_251 ] ;
V_239 = F_162 ( V_7 [ 0 ] ) ;
if ( F_31 ( V_239 >= V_177 -> V_70 ) )
return;
V_138 = F_163 ( V_7 [ 0 ] ) ;
V_29 = F_102 ( V_4 , V_177 , V_239 , V_256 ) ;
if ( ! V_29 )
return;
if ( V_138 > V_177 -> V_180 )
F_113 ( V_29 , V_177 -> V_180 ) ;
else
F_113 ( V_29 , V_138 ) ;
if ( ! F_142 ( V_29 -> V_33 , V_4 -> V_69 ) )
V_4 -> V_174 -> V_246 ++ ;
else
F_138 ( V_29 , V_4 ) ;
F_68 ( V_29 ) ;
return;
}
void F_184 ( struct V_210 * V_211 )
{
struct V_3 * V_4 = V_211 -> V_4 ;
struct V_240 * V_144 ;
T_2 V_7 [ 2 ] ;
int V_251 , V_83 ;
T_4 V_308 = V_211 -> V_308 ;
V_144 = & V_211 -> V_62 [ V_308 ] ;
V_7 [ 0 ] = F_99 ( V_144 -> V_242 [ 0 ] ) ;
V_7 [ 1 ] = F_99 ( V_144 -> V_242 [ 1 ] ) ;
V_83 = F_173 ( V_7 [ 1 ] ) ;
if ( ! V_83 )
return;
V_251 = F_174 ( F_162 ( V_7 [ 0 ] ) ) ;
F_183 ( V_4 , V_251 , V_7 ) ;
V_144 = & V_211 -> V_62 [ V_308 ] ;
V_144 -> V_242 [ 0 ] = F_20 ( V_321 ) ;
V_308 = F_22 ( V_308 , V_211 -> V_70 ) ;
V_211 -> V_308 = V_308 ;
F_81 ( V_308 , V_211 -> V_318 ) ;
}
