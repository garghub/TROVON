static unsigned int F_1 ( unsigned int V_1 )
{
unsigned int V_2 ;
V_2 = V_3 ;
V_1 += 2 ;
V_2 = V_1 * sizeof( struct V_4 ) ;
V_2 += sizeof( V_5 ) ;
V_2 += sizeof( struct V_6 ) ;
V_2 += sizeof( V_5 ) ;
F_2 ( L_1 ,
V_7 , V_2 ) ;
return V_2 ;
}
static unsigned int F_3 ( unsigned int V_1 )
{
unsigned int V_2 ;
V_2 = V_3 ;
V_1 += 2 ;
V_2 = sizeof( V_5 ) ;
V_2 += V_1 * sizeof( struct V_6 ) ;
V_2 += sizeof( V_5 ) ;
F_2 ( L_2 ,
V_7 , V_2 ) ;
return V_2 ;
}
void F_4 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_12 ;
struct V_13 * V_14 = & V_9 -> V_15 ;
unsigned int V_1 = V_14 -> V_16 ;
V_14 -> V_17 = V_11 -> V_18 -
F_1 ( V_1 ) ;
V_14 -> V_19 = V_11 -> V_20 -
F_3 ( V_1 ) ;
}
static bool F_5 ( struct V_8 * V_9 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = & V_22 -> V_25 ;
unsigned int V_26 , V_27 , V_28 ;
if ( V_24 -> V_29 > V_9 -> V_15 . V_17 )
return false ;
if ( V_24 -> V_30 ) {
V_27 = V_24 -> V_30 ;
V_28 = F_6 ( V_24 -> V_31 ) ;
V_26 = 0 ;
while ( V_27 ) {
V_27 -= F_7 (unsigned int,
PAGE_SIZE - offset, remaining) ;
V_28 = 0 ;
if ( ++ V_26 > V_9 -> V_15 . V_32 )
return false ;
}
}
return true ;
}
static bool F_8 ( struct V_8 * V_9 ,
struct V_21 * V_22 )
{
struct V_13 * V_14 = & V_9 -> V_15 ;
return V_22 -> V_33 . V_34 <= V_14 -> V_19 ;
}
static int
F_9 ( struct V_35 * V_36 , struct V_37 * V_38 , int V_39 )
{
T_1 V_40 ;
T_2 V_27 ;
char * V_41 ;
V_41 = V_36 -> V_42 ;
V_40 = F_6 ( V_41 ) ;
V_27 = V_36 -> V_43 ;
while ( V_27 && V_39 < V_44 ) {
V_38 [ V_39 ] . V_45 = NULL ;
V_38 [ V_39 ] . V_46 = V_41 ;
V_38 [ V_39 ] . V_47 = F_7 ( T_2 , V_48 - V_40 , V_27 ) ;
V_27 -= V_38 [ V_39 ] . V_47 ;
V_41 += V_38 [ V_39 ] . V_47 ;
++ V_39 ;
V_40 = 0 ;
}
return V_39 ;
}
static int
F_10 ( struct V_8 * V_9 , struct V_23 * V_49 ,
unsigned int V_50 , enum V_51 type ,
struct V_37 * V_38 )
{
int V_29 , V_39 , V_52 , V_31 ;
struct V_53 * * V_54 ;
V_39 = 0 ;
if ( V_50 == 0 ) {
V_39 = F_9 ( & V_49 -> V_55 [ 0 ] , V_38 , V_39 ) ;
if ( V_39 == V_44 )
goto V_56;
}
V_29 = V_49 -> V_30 ;
V_54 = V_49 -> V_57 + ( V_49 -> V_31 >> V_58 ) ;
V_31 = F_6 ( V_49 -> V_31 ) ;
V_52 = 0 ;
while ( V_29 && V_39 < V_44 ) {
if ( ! V_54 [ V_52 ] ) {
V_54 [ V_52 ] = F_11 ( V_59 ) ;
if ( ! V_54 [ V_52 ] )
return - V_60 ;
}
V_38 [ V_39 ] . V_45 = V_54 [ V_52 ] ;
V_38 [ V_39 ] . V_46 = ( void * ) ( unsigned long ) V_31 ;
V_38 [ V_39 ] . V_47 = F_7 ( T_2 , V_48 - V_31 , V_29 ) ;
if ( V_38 [ V_39 ] . V_47 > V_48 )
goto V_56;
V_29 -= V_38 [ V_39 ] . V_47 ;
++ V_39 ;
++ V_52 ;
V_31 = 0 ;
}
if ( V_29 && V_39 == V_44 )
goto V_56;
if ( type == V_61 && V_9 -> V_15 . V_62 )
return V_39 ;
if ( type == V_63 && V_9 -> V_15 . V_62 )
return V_39 ;
if ( V_49 -> V_64 [ 0 ] . V_43 ) {
V_39 = F_9 ( & V_49 -> V_64 [ 0 ] , V_38 , V_39 ) ;
if ( V_39 == V_44 )
goto V_56;
}
return V_39 ;
V_56:
F_12 ( L_3 ) ;
return - V_65 ;
}
static inline V_5 *
F_13 ( V_5 * V_66 , struct V_67 * V_68 )
{
* V_66 ++ = F_14 ( V_68 -> V_69 ) ;
* V_66 ++ = F_14 ( V_68 -> V_70 ) ;
return F_15 ( V_66 , V_68 -> V_71 ) ;
}
static V_5 *
F_16 ( struct V_8 * V_9 ,
struct V_72 * V_73 , struct V_21 * V_22 ,
V_5 * V_66 , enum V_51 V_74 )
{
struct V_37 * V_38 ;
struct V_67 * V_68 ;
unsigned int V_50 ;
int V_39 , V_75 ;
if ( V_74 == V_76 ) {
* V_66 ++ = V_77 ;
return V_66 ;
}
V_50 = V_22 -> V_25 . V_55 [ 0 ] . V_43 ;
if ( V_74 == V_78 )
V_50 = 0 ;
V_38 = V_73 -> V_79 ;
V_75 = F_10 ( V_9 , & V_22 -> V_25 , V_50 ,
V_74 , V_38 ) ;
if ( V_75 < 0 )
return F_17 ( V_75 ) ;
do {
V_39 = V_9 -> V_15 . V_80 -> V_81 ( V_9 , V_38 , V_75 ,
false , & V_68 ) ;
if ( V_39 < 0 )
return F_17 ( V_39 ) ;
F_18 ( V_68 , & V_73 -> V_82 ) ;
* V_66 ++ = V_83 ;
* V_66 ++ = F_14 ( V_50 ) ;
V_66 = F_13 ( V_66 , V_68 ) ;
F_2 ( L_4 ,
V_22 -> V_84 -> V_85 , V_7 , V_50 ,
V_68 -> V_70 , ( unsigned long long ) V_68 -> V_71 ,
V_68 -> V_69 , V_39 < V_75 ? L_5 : L_6 ) ;
V_9 -> V_86 . V_87 ++ ;
V_38 += V_39 ;
V_75 -= V_39 ;
} while ( V_75 );
* V_66 ++ = V_77 ;
return V_66 ;
}
static V_5 *
F_19 ( struct V_8 * V_9 , struct V_72 * V_73 ,
struct V_21 * V_22 , V_5 * V_66 ,
enum V_51 V_88 )
{
struct V_37 * V_38 ;
struct V_67 * V_68 ;
int V_39 , V_75 , V_89 ;
V_5 * V_90 ;
if ( V_88 != V_63 ) {
* V_66 ++ = V_77 ;
return V_66 ;
}
V_38 = V_73 -> V_79 ;
V_75 = F_10 ( V_9 , & V_22 -> V_33 ,
V_22 -> V_33 . V_55 [ 0 ] . V_43 ,
V_88 , V_38 ) ;
if ( V_75 < 0 )
return F_17 ( V_75 ) ;
* V_66 ++ = V_83 ;
V_90 = V_66 ++ ;
V_89 = 0 ;
do {
V_39 = V_9 -> V_15 . V_80 -> V_81 ( V_9 , V_38 , V_75 ,
true , & V_68 ) ;
if ( V_39 < 0 )
return F_17 ( V_39 ) ;
F_18 ( V_68 , & V_73 -> V_82 ) ;
V_66 = F_13 ( V_66 , V_68 ) ;
F_2 ( L_7 ,
V_22 -> V_84 -> V_85 , V_7 ,
V_68 -> V_70 , ( unsigned long long ) V_68 -> V_71 ,
V_68 -> V_69 , V_39 < V_75 ? L_5 : L_6 ) ;
V_9 -> V_86 . V_91 ++ ;
V_9 -> V_86 . V_92 += V_38 -> V_47 ;
V_89 ++ ;
V_38 += V_39 ;
V_75 -= V_39 ;
} while ( V_75 );
* V_90 = F_14 ( V_89 ) ;
* V_66 ++ = V_77 ;
return V_66 ;
}
static V_5 *
F_20 ( struct V_8 * V_9 ,
struct V_72 * V_73 , struct V_21 * V_22 ,
V_5 * V_66 , enum V_51 V_88 )
{
struct V_37 * V_38 ;
struct V_67 * V_68 ;
int V_39 , V_75 , V_89 ;
V_5 * V_90 ;
if ( V_88 != V_93 ) {
* V_66 ++ = V_77 ;
return V_66 ;
}
V_38 = V_73 -> V_79 ;
V_75 = F_10 ( V_9 , & V_22 -> V_33 , 0 , V_88 , V_38 ) ;
if ( V_75 < 0 )
return F_17 ( V_75 ) ;
* V_66 ++ = V_83 ;
V_90 = V_66 ++ ;
V_89 = 0 ;
do {
V_39 = V_9 -> V_15 . V_80 -> V_81 ( V_9 , V_38 , V_75 ,
true , & V_68 ) ;
if ( V_39 < 0 )
return F_17 ( V_39 ) ;
F_18 ( V_68 , & V_73 -> V_82 ) ;
V_66 = F_13 ( V_66 , V_68 ) ;
F_2 ( L_8 ,
V_22 -> V_84 -> V_85 , V_7 ,
V_68 -> V_70 , ( unsigned long long ) V_68 -> V_71 ,
V_68 -> V_69 , V_39 < V_75 ? L_5 : L_6 ) ;
V_9 -> V_86 . V_94 ++ ;
V_9 -> V_86 . V_92 += V_38 -> V_47 ;
V_89 ++ ;
V_38 += V_39 ;
V_75 -= V_39 ;
} while ( V_75 );
* V_90 = F_14 ( V_89 ) ;
return V_66 ;
}
static bool
F_21 ( struct V_13 * V_14 , struct V_72 * V_73 ,
T_2 V_29 )
{
struct V_95 * V_96 = V_73 -> V_97 ;
struct V_98 * V_99 = & V_73 -> V_100 [ 0 ] ;
if ( F_22 ( ! F_23 ( V_96 ) ) ) {
if ( ! F_24 ( V_14 , V_96 ) )
return false ;
V_99 -> V_101 = F_25 ( V_96 ) ;
V_99 -> V_102 = F_26 ( V_96 ) ;
}
V_99 -> V_103 = V_29 ;
F_27 ( F_28 ( V_96 ) , V_99 -> V_101 ,
V_99 -> V_103 , V_104 ) ;
V_73 -> V_105 . V_106 ++ ;
return true ;
}
static bool
F_29 ( struct V_13 * V_14 , struct V_72 * V_73 ,
struct V_23 * V_24 , enum V_51 V_74 )
{
unsigned int V_107 , V_31 , V_29 , V_27 ;
struct V_95 * V_96 = V_73 -> V_108 ;
struct V_109 * V_110 = V_14 -> V_111 ;
struct V_98 * V_99 = V_73 -> V_100 ;
T_2 V_102 = V_14 -> V_112 -> V_113 ;
struct V_53 * V_53 , * * V_54 ;
if ( ! F_30 ( V_14 , V_96 ) )
return false ;
V_107 = 1 ;
V_99 [ V_107 ] . V_101 = F_25 ( V_96 ) ;
V_99 [ V_107 ] . V_103 = V_24 -> V_55 [ 0 ] . V_43 ;
V_99 [ V_107 ] . V_102 = F_26 ( V_96 ) ;
F_27 ( F_28 ( V_96 ) , V_99 [ V_107 ] . V_101 ,
V_99 [ V_107 ] . V_103 , V_104 ) ;
if ( V_74 == V_61 ) {
V_29 = V_24 -> V_64 [ 0 ] . V_43 ;
if ( V_29 < 4 )
goto V_114;
V_53 = F_31 ( V_24 -> V_64 [ 0 ] . V_42 ) ;
V_31 = F_6 ( V_24 -> V_64 [ 0 ] . V_42 ) ;
V_31 += V_29 & 3 ;
V_29 -= V_29 & 3 ;
goto V_115;
}
if ( V_24 -> V_30 ) {
V_54 = V_24 -> V_57 + ( V_24 -> V_31 >> V_58 ) ;
V_31 = F_6 ( V_24 -> V_31 ) ;
V_27 = V_24 -> V_30 ;
while ( V_27 ) {
V_107 ++ ;
if ( V_107 > V_116 - 2 )
goto V_117;
V_29 = F_7 ( T_2 , V_48 - V_31 , V_27 ) ;
V_99 [ V_107 ] . V_101 = F_32 ( V_110 , * V_54 ,
V_31 , V_29 ,
V_104 ) ;
if ( F_33 ( V_110 , V_99 [ V_107 ] . V_101 ) )
goto V_118;
V_99 [ V_107 ] . V_103 = V_29 ;
V_99 [ V_107 ] . V_102 = V_102 ;
V_73 -> V_119 ++ ;
V_54 ++ ;
V_27 -= V_29 ;
V_31 = 0 ;
}
}
if ( V_24 -> V_64 [ 0 ] . V_43 ) {
V_53 = F_31 ( V_24 -> V_64 [ 0 ] . V_42 ) ;
V_31 = F_6 ( V_24 -> V_64 [ 0 ] . V_42 ) ;
V_29 = V_24 -> V_64 [ 0 ] . V_43 ;
V_115:
V_107 ++ ;
V_99 [ V_107 ] . V_101 = F_32 ( V_110 , V_53 ,
V_31 , V_29 ,
V_104 ) ;
if ( F_33 ( V_110 , V_99 [ V_107 ] . V_101 ) )
goto V_118;
V_99 [ V_107 ] . V_103 = V_29 ;
V_99 [ V_107 ] . V_102 = V_102 ;
V_73 -> V_119 ++ ;
}
V_114:
V_73 -> V_105 . V_106 = V_107 + 1 ;
return true ;
V_117:
F_12 ( L_9 , V_107 ) ;
return false ;
V_118:
F_12 ( L_10 ) ;
return false ;
}
bool
F_34 ( struct V_13 * V_14 , struct V_72 * V_73 ,
T_2 V_120 , struct V_23 * V_24 ,
enum V_51 V_74 )
{
V_73 -> V_105 . V_106 = 0 ;
V_73 -> V_119 = 0 ;
if ( ! F_21 ( V_14 , V_73 , V_120 ) )
goto V_121;
if ( V_74 != V_78 )
if ( ! F_29 ( V_14 , V_73 , V_24 , V_74 ) )
goto V_121;
return true ;
V_121:
F_12 ( L_11 ) ;
return false ;
}
void
F_35 ( struct V_13 * V_14 , struct V_72 * V_73 )
{
struct V_109 * V_110 = V_14 -> V_111 ;
struct V_98 * V_99 ;
int V_26 ;
V_99 = & V_73 -> V_100 [ 2 ] ;
for ( V_26 = V_73 -> V_119 ; V_26 -- ; V_99 ++ )
F_36 ( V_110 , V_99 -> V_101 , V_99 -> V_103 ,
V_104 ) ;
V_73 -> V_119 = 0 ;
}
int
F_37 ( struct V_21 * V_22 )
{
struct V_122 * V_123 = V_22 -> V_124 ;
struct V_8 * V_9 = F_38 ( V_123 ) ;
struct V_72 * V_73 = F_39 ( V_22 ) ;
enum V_51 V_74 , V_88 ;
struct V_125 * V_126 ;
bool V_127 ;
T_3 V_120 ;
T_1 V_128 ;
V_5 * V_66 ;
#if F_40 ( V_129 )
if ( F_41 ( V_130 , & V_22 -> V_131 ) )
return F_42 ( V_22 ) ;
#endif
V_126 = F_43 ( V_73 -> V_97 ) ;
V_126 -> V_132 = V_22 -> V_133 ;
V_126 -> V_134 = V_135 ;
V_126 -> V_136 = F_14 ( V_9 -> V_137 . V_138 ) ;
V_126 -> V_139 = V_140 ;
V_127 = ! ( V_22 -> V_141 -> V_142 -> V_143 &
V_144 ) ;
if ( F_8 ( V_9 , V_22 ) )
V_88 = V_76 ;
else if ( V_127 && V_22 -> V_33 . V_145 & V_146 )
V_88 = V_63 ;
else
V_88 = V_93 ;
if ( F_5 ( V_9 , V_22 ) ) {
V_74 = V_76 ;
V_128 = V_22 -> V_25 . V_29 ;
} else if ( V_127 && V_22 -> V_25 . V_145 & V_147 ) {
V_74 = V_61 ;
V_128 = V_22 -> V_25 . V_55 [ 0 ] . V_43 +
V_22 -> V_25 . V_64 [ 0 ] . V_43 ;
} else {
V_9 -> V_86 . V_148 ++ ;
V_126 -> V_139 = F_44 ( V_149 ) ;
V_74 = V_78 ;
V_128 = 0 ;
}
V_73 -> V_150 = V_22 -> V_133 ;
F_45 ( & V_9 -> V_137 , V_73 ) ;
V_66 = V_126 -> V_151 . V_152 ;
V_66 = F_16 ( V_9 , V_73 , V_22 , V_66 , V_74 ) ;
if ( F_46 ( V_66 ) )
goto V_153;
V_66 = F_19 ( V_9 , V_73 , V_22 , V_66 , V_88 ) ;
if ( F_46 ( V_66 ) )
goto V_153;
V_66 = F_20 ( V_9 , V_73 , V_22 , V_66 , V_88 ) ;
if ( F_46 ( V_66 ) )
goto V_153;
V_120 = ( unsigned char * ) V_66 - ( unsigned char * ) V_126 ;
F_2 ( L_12 ,
V_22 -> V_84 -> V_85 , V_7 ,
V_154 [ V_74 ] , V_154 [ V_88 ] ,
V_120 , V_128 ) ;
if ( ! F_34 ( & V_9 -> V_15 , V_73 , V_120 ,
& V_22 -> V_25 , V_74 ) ) {
V_66 = F_17 ( - V_65 ) ;
goto V_153;
}
return 0 ;
V_153:
if ( F_47 ( V_66 ) != - V_155 ) {
F_12 ( L_13 ,
F_47 ( V_66 ) ) ;
V_9 -> V_86 . V_156 ++ ;
}
return F_47 ( V_66 ) ;
}
static int
F_48 ( struct V_157 * V_158 , int V_159 , V_5 * * V_160 )
{
unsigned int V_161 , V_162 ;
struct V_163 * V_164 ;
char * V_41 = ( char * ) F_43 ( V_158 -> V_165 ) ;
V_161 = F_49 ( * * V_160 ) ;
V_164 = (struct V_163 * ) ( * V_160 + 1 ) ;
V_162 = 0 ;
while ( V_161 -- ) {
struct V_6 * V_38 = & V_164 -> V_166 ;
F_50 (FACILITY) {
T_4 V_167 ;
F_51 ( ( V_5 * ) & V_38 -> V_168 , & V_167 ) ;
F_2 ( L_14 ,
V_7 ,
F_49 ( V_38 -> V_169 ) ,
( unsigned long long ) V_167 ,
F_49 ( V_38 -> V_170 ) ) ;
}
V_162 += F_49 ( V_38 -> V_169 ) ;
++ V_164 ;
}
if ( V_159 ) {
V_5 * V_171 = ( V_5 * ) V_164 ;
if ( * V_171 ++ != V_77 )
return - 1 ;
V_164 = (struct V_163 * ) V_171 ;
}
if ( ( char * ) V_164 > V_41 + V_158 -> V_172 )
return - 1 ;
* V_160 = ( V_5 * ) V_164 ;
return V_162 ;
}
static unsigned long
F_52 ( struct V_21 * V_22 , char * V_173 , int V_174 , int V_175 )
{
unsigned long V_176 ;
int V_161 , V_177 , V_178 ;
char * V_179 ;
struct V_53 * * V_54 ;
int V_31 ;
V_22 -> V_33 . V_55 [ 0 ] . V_42 = V_173 ;
V_22 -> V_180 . V_55 [ 0 ] . V_42 = V_173 ;
V_178 = V_22 -> V_33 . V_55 [ 0 ] . V_43 ;
if ( V_178 > V_174 )
V_178 = V_174 ;
F_2 ( L_15 ,
V_7 , V_173 , V_174 , V_178 ) ;
V_173 += V_178 ;
V_174 -= V_178 ;
V_54 = V_22 -> V_33 . V_57 +
( V_22 -> V_33 . V_31 >> V_58 ) ;
V_31 = F_6 ( V_22 -> V_33 . V_31 ) ;
V_176 = 0 ;
if ( V_174 && V_22 -> V_33 . V_30 ) {
int V_181 ;
V_181 = V_22 -> V_33 . V_30 ;
if ( V_181 > V_174 )
V_181 = V_174 ;
V_177 = F_53 ( V_31 + V_181 ) >> V_58 ;
for ( V_161 = 0 ; V_161 < V_177 ; V_161 ++ ) {
V_178 = V_48 - V_31 ;
if ( V_178 > V_181 )
V_178 = V_181 ;
F_2 ( L_16
L_17 ,
V_7 , V_161 , V_173 , V_174 , V_178 ) ;
V_179 = F_54 ( V_54 [ V_161 ] ) ;
memcpy ( V_179 + V_31 , V_173 , V_178 ) ;
F_55 ( V_54 [ V_161 ] ) ;
F_56 ( V_179 ) ;
V_173 += V_178 ;
V_174 -= V_178 ;
V_176 += V_178 ;
V_181 -= V_178 ;
if ( ! V_181 )
break;
V_31 = 0 ;
}
if ( V_175 )
V_173 -= V_175 ;
}
if ( V_174 || V_175 ) {
V_22 -> V_33 . V_64 [ 0 ] . V_42 = V_173 ;
V_22 -> V_180 . V_64 [ 0 ] . V_42 = V_173 ;
}
return V_176 ;
}
static void
F_57 ( struct V_182 * V_183 ,
struct V_157 * V_158 )
{
struct V_67 * V_68 ;
if ( ! ( V_158 -> V_184 & V_185 ) )
return;
F_58 (mw, mws, mw_list)
if ( V_68 -> V_69 == V_158 -> V_186 ) {
V_68 -> V_187 = V_188 ;
break;
}
}
static bool
F_59 ( struct V_125 * V_126 )
{
V_5 * V_52 = ( V_5 * ) V_126 ;
if ( V_126 -> V_139 != V_140 )
return false ;
if ( V_126 -> V_151 . V_152 [ 0 ] != V_77 )
return false ;
if ( V_126 -> V_151 . V_152 [ 1 ] != V_77 )
return false ;
if ( V_126 -> V_151 . V_152 [ 2 ] != V_77 )
return false ;
if ( V_52 [ 7 ] != V_126 -> V_132 )
return false ;
if ( V_52 [ 8 ] != F_14 ( V_189 ) )
return false ;
return true ;
}
void
F_60 ( struct V_190 * V_191 )
{
struct V_157 * V_158 =
F_61 ( V_191 , struct V_157 , V_192 ) ;
struct V_8 * V_9 = V_158 -> V_193 ;
struct V_194 * V_195 = & V_9 -> V_137 ;
struct V_122 * V_123 = & V_9 -> V_196 ;
struct V_125 * V_126 ;
struct V_72 * V_73 ;
struct V_21 * V_22 ;
V_5 * V_66 ;
int V_197 , V_198 , V_199 ;
unsigned long V_200 ;
struct V_182 V_183 ;
F_2 ( L_18 , V_7 , V_158 ) ;
if ( V_158 -> V_172 == V_201 )
goto V_202;
if ( V_158 -> V_172 < V_203 )
goto V_204;
V_126 = F_43 ( V_158 -> V_165 ) ;
#if F_40 ( V_129 )
if ( F_59 ( V_126 ) )
goto V_205;
#endif
F_62 ( & V_195 -> V_206 ) ;
V_73 = F_63 ( & V_9 -> V_137 ,
V_126 -> V_132 ) ;
if ( ! V_73 )
goto V_207;
if ( V_73 -> V_208 )
goto V_209;
F_64 ( & V_73 -> V_82 , & V_183 ) ;
F_57 ( & V_183 , V_158 ) ;
V_73 -> V_208 = V_158 ;
F_65 ( & V_195 -> V_206 ) ;
F_2 ( L_19 ,
V_7 , V_158 , V_73 , F_49 ( V_126 -> V_132 ) ) ;
if ( ! F_66 ( & V_183 ) )
V_9 -> V_15 . V_80 -> V_210 ( V_9 , & V_183 ) ;
F_67 ( & V_123 -> V_211 ) ;
V_22 = F_68 ( V_123 , V_126 -> V_132 ) ;
if ( ! V_22 )
goto V_212;
V_123 -> V_213 = 0 ;
if ( V_126 -> V_134 != V_135 )
goto V_214;
switch ( V_126 -> V_139 ) {
case V_140 :
if ( V_126 -> V_151 . V_152 [ 0 ] != V_77 ||
( V_126 -> V_151 . V_152 [ 1 ] == V_77 &&
V_126 -> V_151 . V_152 [ 2 ] != V_77 ) )
goto V_215;
if ( V_126 -> V_151 . V_152 [ 1 ] != V_77 ) {
V_66 = & V_126 -> V_151 . V_152 [ 2 ] ;
V_197 = F_48 ( V_158 , 1 , & V_66 ) ;
if ( V_197 < 0 || * V_66 ++ != V_77 )
goto V_215;
V_158 -> V_172 -=
( ( unsigned char * ) V_66 - ( unsigned char * ) V_126 ) ;
V_198 = V_158 -> V_172 + V_197 ;
V_9 -> V_86 . V_216 += V_197 ;
if ( V_197 &= 3 ) {
V_197 = 4 - V_197 ;
V_198 += V_197 ;
}
} else {
V_197 = 0 ;
V_66 = ( V_5 * ) ( ( unsigned char * ) V_126 +
V_3 ) ;
V_158 -> V_172 -= V_3 ;
V_198 = V_158 -> V_172 ;
}
V_9 -> V_86 . V_176 +=
F_52 ( V_22 , ( char * ) V_66 , V_158 -> V_172 ,
V_197 ) ;
break;
case V_217 :
if ( V_126 -> V_151 . V_152 [ 0 ] != V_77 ||
V_126 -> V_151 . V_152 [ 1 ] != V_77 ||
V_126 -> V_151 . V_152 [ 2 ] != V_83 )
goto V_215;
V_66 = ( V_5 * ) ( ( unsigned char * ) V_126 +
V_3 ) ;
V_197 = F_48 ( V_158 , 0 , & V_66 ) ;
if ( V_197 < 0 )
goto V_215;
V_9 -> V_86 . V_216 += V_197 ;
V_198 = V_197 ;
break;
case V_218 :
goto V_219;
V_215:
default:
F_2 ( L_20 ,
V_22 -> V_84 -> V_85 , V_7 ,
F_49 ( V_126 -> V_139 ) ) ;
V_198 = - V_65 ;
V_9 -> V_86 . V_220 ++ ;
break;
}
V_114:
V_200 = V_123 -> V_200 ;
V_123 -> V_200 = F_69 ( & V_9 -> V_137 . V_221 ) << V_222 ;
if ( V_123 -> V_200 > V_200 )
F_70 ( V_22 -> V_84 ) ;
F_71 ( V_22 -> V_84 , V_198 ) ;
F_72 ( & V_123 -> V_211 ) ;
F_2 ( L_21 ,
V_7 , V_123 , V_22 , V_198 ) ;
return;
V_202:
F_73 ( V_158 ) ;
if ( V_9 -> V_223 . V_224 == 1 ) {
V_9 -> V_223 . V_224 = - V_65 ;
F_74 ( & V_9 -> V_223 ) ;
}
return;
#if F_40 ( V_129 )
V_205:
F_75 ( V_9 , V_158 ) ;
return;
#endif
V_214:
F_2 ( L_22 ,
V_7 , F_49 ( V_126 -> V_134 ) ) ;
V_198 = - V_65 ;
V_9 -> V_86 . V_220 ++ ;
goto V_114;
V_219:
V_199 = F_49 ( V_126 -> V_151 . V_225 . V_226 ) ;
switch ( V_199 ) {
case V_227 :
F_12 ( L_23 ,
V_7 ,
F_49 ( V_126 -> V_151 . V_225 . V_228 ) ,
F_49 ( V_126 -> V_151 . V_225 . V_229 ) ) ;
break;
case V_230 :
F_12 ( L_24 ,
V_7 ) ;
break;
default:
F_12 ( L_25 ,
V_7 , V_199 ) ;
}
V_198 = - V_231 ;
V_9 -> V_86 . V_220 ++ ;
goto V_114;
V_212:
F_72 ( & V_123 -> V_211 ) ;
F_76 ( V_73 ) ;
F_2 ( L_26 ,
V_7 , V_73 ) ;
return;
V_204:
F_2 ( L_27 , V_7 ) ;
goto V_232;
V_207:
F_65 ( & V_195 -> V_206 ) ;
F_2 ( L_28 ,
V_7 , F_49 ( V_126 -> V_132 ) ,
V_158 -> V_172 ) ;
goto V_232;
V_209:
F_65 ( & V_195 -> V_206 ) ;
F_2 ( L_29
L_30 ,
V_7 , V_158 , V_73 , F_49 ( V_126 -> V_132 ) ) ;
V_232:
V_9 -> V_86 . V_220 ++ ;
if ( F_77 ( & V_9 -> V_15 , V_158 ) )
F_73 ( V_158 ) ;
}
