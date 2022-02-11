static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_4 -> V_5 , V_6 ,
sizeof( V_4 -> V_5 ) ) ;
F_2 ( V_4 -> V_7 , V_8 , sizeof( V_4 -> V_7 ) ) ;
}
static void F_3 ( struct V_1 * V_2 ,
T_1 V_9 , T_2 * V_10 )
{
int V_11 ;
switch ( V_9 ) {
case V_12 :
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ )
strcpy ( V_10 + ( V_11 * V_14 ) ,
V_15 [ V_11 ] . V_16 ) ;
break;
}
}
static void F_4 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 -> V_18 . V_22 ;
struct V_23 * V_24 = V_18 -> V_25 ;
struct V_26 * V_27 = V_24 -> V_27 ;
struct V_28 * V_29 ;
struct V_30 V_31 ;
int V_32 ;
V_32 = F_5 ( V_20 , V_27 -> V_33 , & V_31 ) ;
if ( V_32 ) {
F_6 ( L_1 , V_27 -> V_33 , V_32 ) ;
return;
}
V_29 = & V_18 -> V_34 . V_35 ;
V_29 -> V_36 = V_31 . V_37 ;
V_29 -> V_38 = V_31 . V_39 ;
V_29 -> V_37 = V_31 . V_36 ;
V_29 -> V_39 = V_31 . V_38 ;
}
static void F_7 ( struct V_17 * V_18 )
{
struct V_40 * V_41 = & V_18 -> V_34 . V_42 ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
int V_11 , V_47 ;
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
for ( V_11 = 0 ; V_11 < V_18 -> V_48 . V_49 ; V_11 ++ ) {
struct V_50 * V_51 = V_18 -> V_48 . V_51 [ V_11 ] ;
V_44 = & V_51 -> V_52 . V_34 ;
V_41 -> V_36 += V_44 -> V_53 ;
V_41 -> V_38 += V_44 -> V_54 ;
for ( V_47 = 0 ; V_47 < V_18 -> V_48 . V_55 . V_56 ; V_47 ++ ) {
V_46 = & V_51 -> V_57 [ V_47 ] . V_34 ;
V_41 -> V_37 += V_46 -> V_53 ;
V_41 -> V_39 += V_46 -> V_54 ;
}
}
}
static void F_8 ( struct V_17 * V_18 )
{
F_7 ( V_18 ) ;
F_4 ( V_18 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_58 * V_34 , T_3 * V_10 )
{
struct V_17 * V_18 = F_10 ( V_2 ) ;
int V_11 ;
if ( ! V_10 )
return;
F_11 ( & V_18 -> V_59 ) ;
if ( F_12 ( V_60 , & V_18 -> V_61 ) )
F_7 ( V_18 ) ;
F_13 ( & V_18 -> V_59 ) ;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ )
V_10 [ V_11 ] = F_14 ( & V_18 -> V_34 . V_42 ,
V_15 , V_11 ) ;
}
static int F_15 ( struct V_1 * V_2 , int V_62 )
{
switch ( V_62 ) {
case V_12 :
return V_13 ;
default:
return - V_63 ;
}
}
int F_16 ( struct V_1 * V_2 , struct V_64 * V_65 )
{
struct V_17 * V_18 = F_10 ( V_2 ) ;
struct V_23 * V_24 = V_18 -> V_25 ;
struct V_26 * V_27 = V_24 -> V_27 ;
struct V_19 * V_20 = V_18 -> V_21 -> V_18 . V_22 ;
if ( V_20 -> V_66 == V_67 )
return - V_63 ;
switch ( V_65 -> V_68 ) {
case V_69 :
V_65 -> V_70 . V_71 . V_72 = V_73 ;
F_17 ( V_65 -> V_70 . V_71 . V_68 , V_27 -> V_74 ) ;
break;
default:
return - V_63 ;
}
return 0 ;
}
int F_18 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 -> V_18 . V_22 ;
struct V_23 * V_24 = V_18 -> V_25 ;
struct V_26 * V_27 = V_24 -> V_27 ;
struct V_50 * V_51 ;
int V_75 , V_76 , V_77 = 0 ;
int V_32 = - V_78 ;
T_4 * V_79 ;
V_79 = F_19 ( V_18 -> V_48 . V_49 * V_18 -> V_48 . V_55 . V_56 , sizeof( T_4 ) , V_80 ) ;
if ( ! V_79 )
goto V_81;
for ( V_75 = 0 ; V_75 < V_18 -> V_48 . V_49 ; V_75 ++ ) {
V_51 = V_18 -> V_48 . V_51 [ V_75 ] ;
for ( V_76 = 0 ; V_76 < V_51 -> V_56 ; V_76 ++ )
V_79 [ V_77 ++ ] = V_51 -> V_57 [ V_76 ] . V_82 ;
}
V_32 = F_20 ( V_20 , V_27 , V_79 , V_77 ) ;
F_21 ( V_79 ) ;
V_81:
if ( V_32 )
F_22 ( V_18 -> V_83 , L_2 , V_32 ) ;
return V_32 ;
}
void F_23 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 -> V_18 . V_22 ;
struct V_23 * V_24 = V_18 -> V_25 ;
struct V_26 * V_27 = V_24 -> V_27 ;
F_24 ( V_20 , V_27 ) ;
}
static void F_25 ( struct V_23 * V_24 )
{
#if F_26 ( V_84 )
unsigned long V_85 = F_27 ( & V_86 -> V_87 -> V_88 ,
V_89 ) ;
#else
unsigned long V_85 = ~ 0UL ;
#endif
unsigned long V_90 = F_27 ( & V_91 . V_88 ,
V_89 ) ;
struct V_1 * V_83 = V_24 -> V_27 -> V_83 ;
struct V_17 * V_18 = F_10 ( V_83 ) ;
V_24 -> V_92 . V_93 = F_28 (unsigned long, ipv6_interval, ipv4_interval) ;
F_29 ( V_18 -> V_21 , V_24 -> V_92 . V_93 ) ;
}
void F_30 ( struct V_17 * V_18 )
{
struct V_23 * V_24 = V_18 -> V_25 ;
struct V_94 * V_92 = & V_24 -> V_92 ;
F_31 ( V_18 -> V_21 ,
& V_92 -> V_95 ,
V_92 -> V_93 ) ;
}
static void F_32 ( struct V_96 * V_97 )
{
struct V_23 * V_24 = F_33 ( V_97 , struct V_23 ,
V_92 . V_95 . V_97 ) ;
struct V_1 * V_83 = V_24 -> V_27 -> V_83 ;
struct V_17 * V_18 = F_10 ( V_83 ) ;
struct V_98 * V_99 ;
F_34 () ;
if ( ! F_35 ( & V_24 -> V_92 . V_100 ) )
F_30 ( V_18 ) ;
F_36 (nhe, &rpriv->neigh_update.neigh_list, neigh_list)
F_37 ( V_99 ) ;
F_38 () ;
}
static void F_39 ( struct V_98 * V_99 )
{
F_40 ( & V_99 -> V_101 ) ;
}
static void F_41 ( struct V_98 * V_99 )
{
if ( F_42 ( & V_99 -> V_101 ) )
F_21 ( V_99 ) ;
}
static void F_43 ( struct V_17 * V_18 ,
struct V_102 * V_103 ,
bool V_104 ,
unsigned char V_105 [ V_73 ] )
{
struct V_106 * V_107 = (struct V_106 * ) V_103 -> V_108 ;
F_44 () ;
if ( ( ! V_104 && ( V_103 -> V_109 & V_110 ) ) ||
! F_45 ( V_103 -> V_111 , V_105 ) )
F_46 ( V_18 , V_103 ) ;
if ( V_104 && ! ( V_103 -> V_109 & V_110 ) ) {
F_17 ( V_103 -> V_111 , V_105 ) ;
F_17 ( V_107 -> V_111 , V_105 ) ;
F_47 ( V_18 , V_103 ) ;
}
}
static void F_48 ( struct V_96 * V_97 )
{
struct V_98 * V_99 =
F_33 ( V_97 , struct V_98 , V_112 ) ;
struct V_113 * V_75 = V_99 -> V_75 ;
struct V_102 * V_103 ;
unsigned char V_105 [ V_73 ] ;
struct V_17 * V_18 ;
bool V_104 ;
bool V_114 ;
T_5 V_115 , V_116 ;
F_34 () ;
F_49 ( & V_75 -> V_117 ) ;
memcpy ( V_105 , V_75 -> V_105 , V_73 ) ;
V_115 = V_75 -> V_115 ;
V_116 = V_75 -> V_116 ;
F_50 ( & V_75 -> V_117 ) ;
V_104 = ( V_115 & V_118 ) && ! V_116 ;
F_36 (e, &nhe->encap_list, encap_list) {
V_114 = ! ! ( V_103 -> V_109 & V_110 ) ;
V_18 = F_10 ( V_103 -> V_119 ) ;
if ( V_114 != V_104 ||
! F_45 ( V_103 -> V_111 , V_105 ) )
F_43 ( V_18 , V_103 , V_104 , V_105 ) ;
}
F_41 ( V_99 ) ;
F_38 () ;
F_51 ( V_75 ) ;
}
static int F_52 ( struct V_120 * V_121 ,
unsigned long V_122 , void * V_123 )
{
struct V_23 * V_24 = F_33 ( V_121 , struct V_23 ,
V_92 . V_124 ) ;
struct V_94 * V_92 = & V_24 -> V_92 ;
struct V_1 * V_83 = V_24 -> V_27 -> V_83 ;
struct V_17 * V_18 = F_10 ( V_83 ) ;
struct V_98 * V_99 = NULL ;
struct V_125 V_126 = {} ;
struct V_127 * V_128 ;
struct V_113 * V_75 ;
bool V_129 = false ;
switch ( V_122 ) {
case V_130 :
V_75 = V_123 ;
#if F_26 ( V_84 )
if ( V_75 -> V_131 != V_86 -> V_87 && V_75 -> V_131 != & V_91 )
#else
if ( V_75 -> V_131 != & V_91 )
#endif
return V_132 ;
V_126 . V_2 = V_75 -> V_2 ;
V_126 . V_133 = V_75 -> V_134 -> V_133 ;
memcpy ( & V_126 . V_135 , V_75 -> V_136 , V_75 -> V_131 -> V_137 ) ;
F_53 ( & V_92 -> V_138 ) ;
V_99 = F_54 ( V_18 , & V_126 ) ;
if ( ! V_99 ) {
F_55 ( & V_92 -> V_138 ) ;
return V_132 ;
}
V_99 -> V_75 = V_75 ;
F_56 ( V_75 ) ;
F_39 ( V_99 ) ;
if ( ! F_57 ( V_18 -> V_139 , & V_99 -> V_112 ) ) {
F_41 ( V_99 ) ;
F_51 ( V_75 ) ;
}
F_55 ( & V_92 -> V_138 ) ;
break;
case V_140 :
V_128 = V_123 ;
#if F_26 ( V_84 )
if ( ! V_128 -> V_2 || ( V_128 -> V_131 != V_86 -> V_87 && V_128 -> V_131 != & V_91 ) )
#else
if ( ! V_128 -> V_2 || V_128 -> V_131 != & V_91 )
#endif
return V_132 ;
F_53 ( & V_92 -> V_138 ) ;
F_36 (nhe, &neigh_update->neigh_list, neigh_list) {
if ( V_128 -> V_2 == V_99 -> V_126 . V_2 ) {
V_129 = true ;
break;
}
}
F_55 ( & V_92 -> V_138 ) ;
if ( ! V_129 )
return V_132 ;
V_92 -> V_93 = F_28 (unsigned long,
NEIGH_VAR(p, DELAY_PROBE_TIME),
neigh_update->min_interval) ;
F_29 ( V_18 -> V_21 ,
V_92 -> V_93 ) ;
break;
}
return V_132 ;
}
static int F_58 ( struct V_23 * V_24 )
{
struct V_94 * V_92 = & V_24 -> V_92 ;
int V_32 ;
V_32 = F_59 ( & V_92 -> V_141 , & V_142 ) ;
if ( V_32 )
return V_32 ;
F_60 ( & V_92 -> V_100 ) ;
F_61 ( & V_92 -> V_138 ) ;
F_62 ( & V_92 -> V_95 ,
F_32 ) ;
F_25 ( V_24 ) ;
V_24 -> V_92 . V_124 . V_143 = F_52 ;
V_32 = F_63 ( & V_24 -> V_92 . V_124 ) ;
if ( V_32 )
goto V_144;
return 0 ;
V_144:
F_64 ( & V_92 -> V_141 ) ;
return V_32 ;
}
static void F_65 ( struct V_23 * V_24 )
{
struct V_94 * V_92 = & V_24 -> V_92 ;
struct V_17 * V_18 = F_10 ( V_24 -> V_27 -> V_83 ) ;
F_66 ( & V_92 -> V_124 ) ;
F_67 ( V_18 -> V_139 ) ;
F_68 ( & V_24 -> V_92 . V_95 ) ;
F_64 ( & V_92 -> V_141 ) ;
}
static int F_69 ( struct V_17 * V_18 ,
struct V_98 * V_99 )
{
struct V_23 * V_24 = V_18 -> V_25 ;
int V_32 ;
V_32 = F_70 ( & V_24 -> V_92 . V_141 ,
& V_99 -> V_145 ,
V_142 ) ;
if ( V_32 )
return V_32 ;
F_71 ( & V_99 -> V_100 , & V_24 -> V_92 . V_100 ) ;
return V_32 ;
}
static void F_72 ( struct V_17 * V_18 ,
struct V_98 * V_99 )
{
struct V_23 * V_24 = V_18 -> V_25 ;
F_53 ( & V_24 -> V_92 . V_138 ) ;
F_73 ( & V_99 -> V_100 ) ;
F_74 ( & V_24 -> V_92 . V_141 ,
& V_99 -> V_145 ,
V_142 ) ;
F_55 ( & V_24 -> V_92 . V_138 ) ;
}
static struct V_98 *
F_54 ( struct V_17 * V_18 ,
struct V_125 * V_126 )
{
struct V_23 * V_24 = V_18 -> V_25 ;
struct V_94 * V_92 = & V_24 -> V_92 ;
return F_75 ( & V_92 -> V_141 , V_126 ,
V_142 ) ;
}
static int F_76 ( struct V_17 * V_18 ,
struct V_102 * V_103 ,
struct V_98 * * V_99 )
{
int V_32 ;
* V_99 = F_77 ( sizeof( * * V_99 ) , V_80 ) ;
if ( ! * V_99 )
return - V_78 ;
memcpy ( & ( * V_99 ) -> V_126 , & V_103 -> V_126 , sizeof( V_103 -> V_126 ) ) ;
F_78 ( & ( * V_99 ) -> V_112 , F_48 ) ;
F_60 ( & ( * V_99 ) -> V_146 ) ;
F_79 ( & ( * V_99 ) -> V_101 , 1 ) ;
V_32 = F_69 ( V_18 , * V_99 ) ;
if ( V_32 )
goto V_147;
return 0 ;
V_147:
F_21 ( * V_99 ) ;
return V_32 ;
}
static void F_80 ( struct V_17 * V_18 ,
struct V_98 * V_99 )
{
F_72 ( V_18 , V_99 ) ;
F_41 ( V_99 ) ;
}
int F_81 ( struct V_17 * V_18 ,
struct V_102 * V_103 )
{
struct V_98 * V_99 ;
int V_32 ;
V_99 = F_54 ( V_18 , & V_103 -> V_126 ) ;
if ( ! V_99 ) {
V_32 = F_76 ( V_18 , V_103 , & V_99 ) ;
if ( V_32 )
return V_32 ;
}
F_71 ( & V_103 -> V_146 , & V_99 -> V_146 ) ;
return 0 ;
}
void F_82 ( struct V_17 * V_18 ,
struct V_102 * V_103 )
{
struct V_98 * V_99 ;
F_73 ( & V_103 -> V_146 ) ;
V_99 = F_54 ( V_18 , & V_103 -> V_126 ) ;
if ( F_35 ( & V_99 -> V_146 ) )
F_80 ( V_18 , V_99 ) ;
}
static int F_83 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_10 ( V_2 ) ;
struct V_23 * V_24 = V_18 -> V_25 ;
struct V_26 * V_27 = V_24 -> V_27 ;
struct V_19 * V_20 = V_18 -> V_21 -> V_18 . V_22 ;
int V_32 ;
V_32 = F_84 ( V_2 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_85 ( V_20 , V_27 -> V_33 , V_148 ) ;
if ( ! V_32 )
F_86 ( V_2 ) ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_10 ( V_2 ) ;
struct V_23 * V_24 = V_18 -> V_25 ;
struct V_26 * V_27 = V_24 -> V_27 ;
struct V_19 * V_20 = V_18 -> V_21 -> V_18 . V_22 ;
( void ) F_85 ( V_20 , V_27 -> V_33 , V_149 ) ;
return F_88 ( V_2 ) ;
}
static int F_89 ( struct V_1 * V_2 ,
char * V_150 , T_6 V_151 )
{
struct V_17 * V_18 = F_10 ( V_2 ) ;
struct V_23 * V_24 = V_18 -> V_25 ;
struct V_26 * V_27 = V_24 -> V_27 ;
int V_152 ;
V_152 = snprintf ( V_150 , V_151 , L_3 , V_27 -> V_33 - 1 ) ;
if ( V_152 >= V_151 )
return - V_63 ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 , T_1 V_153 ,
T_7 V_154 , struct V_155 * V_76 )
{
struct V_17 * V_18 = F_10 ( V_2 ) ;
if ( F_91 ( V_153 ) != F_91 ( V_156 ) )
return - V_63 ;
if ( V_76 -> V_157 ) {
struct V_19 * V_20 = V_18 -> V_21 -> V_18 . V_22 ;
struct V_1 * V_158 = F_92 ( V_20 ) ;
return V_158 -> V_159 -> V_160 ( V_158 , V_153 ,
V_154 , V_76 ) ;
}
switch ( V_76 -> type ) {
case V_161 :
switch ( V_76 -> V_162 -> V_163 ) {
case V_164 :
return F_93 ( V_18 , V_154 , V_76 -> V_162 ) ;
case V_165 :
return F_94 ( V_18 , V_76 -> V_162 ) ;
case V_166 :
return F_95 ( V_18 , V_76 -> V_162 ) ;
}
default:
return - V_63 ;
}
}
bool F_96 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 -> V_18 . V_22 ;
struct V_23 * V_24 = V_18 -> V_25 ;
struct V_26 * V_27 ;
if ( ! F_97 ( V_18 -> V_21 , V_167 ) )
return false ;
V_27 = V_24 -> V_27 ;
if ( V_20 -> V_66 == V_168 &&
V_27 && V_27 -> V_33 == V_169 )
return true ;
return false ;
}
static bool F_98 ( struct V_17 * V_18 )
{
struct V_23 * V_24 = V_18 -> V_25 ;
struct V_26 * V_27 = V_24 -> V_27 ;
if ( V_27 && V_27 -> V_33 != V_169 )
return true ;
return false ;
}
bool F_99 ( const struct V_1 * V_2 , int V_170 )
{
struct V_17 * V_18 = F_10 ( V_2 ) ;
switch ( V_170 ) {
case V_171 :
if ( F_98 ( V_18 ) || F_96 ( V_18 ) )
return true ;
}
return false ;
}
static int
F_100 ( const struct V_1 * V_2 ,
struct V_28 * V_34 )
{
struct V_17 * V_18 = F_10 ( V_2 ) ;
struct V_40 * V_172 = & V_18 -> V_34 . V_42 ;
V_34 -> V_36 = V_172 -> V_36 ;
V_34 -> V_38 = V_172 -> V_38 ;
V_34 -> V_37 = V_172 -> V_37 ;
V_34 -> V_39 = V_172 -> V_39 ;
V_34 -> V_173 = V_172 -> V_174 ;
return 0 ;
}
int F_101 ( int V_170 , const struct V_1 * V_2 ,
void * V_175 )
{
switch ( V_170 ) {
case V_171 :
return F_100 ( V_2 , V_175 ) ;
}
return - V_176 ;
}
static void
F_102 ( struct V_1 * V_2 , struct V_28 * V_34 )
{
struct V_17 * V_18 = F_10 ( V_2 ) ;
memcpy ( V_34 , & V_18 -> V_34 . V_35 , sizeof( * V_34 ) ) ;
}
static void F_103 ( struct V_177 * V_21 ,
struct V_178 * V_55 )
{
T_5 V_179 = F_97 ( V_21 , V_180 ) ?
V_181 :
V_182 ;
V_55 -> V_183 = V_184 ;
V_55 -> V_185 = V_186 ;
V_55 -> V_187 = V_188 ;
V_55 -> V_189 = F_97 ( V_21 , V_190 ) ;
F_104 ( V_55 , V_179 ) ;
V_55 -> V_191 = F_105 ( V_21 ) ;
V_55 -> V_56 = 1 ;
V_55 -> V_192 = V_193 ;
F_106 ( V_21 , & V_55 -> V_194 ) ;
}
static void F_107 ( struct V_1 * V_83 )
{
V_83 -> V_159 = & V_195 ;
V_83 -> V_196 = 15 * V_197 ;
V_83 -> V_198 = & V_199 ;
#ifdef F_108
V_83 -> V_200 = & V_201 ;
#endif
V_83 -> V_202 |= V_203 | V_204 | V_205 ;
V_83 -> V_206 |= V_204 ;
F_109 ( V_83 ) ;
}
static void F_110 ( struct V_177 * V_21 ,
struct V_1 * V_83 ,
const struct V_207 * V_208 ,
void * V_25 )
{
struct V_17 * V_18 = F_10 ( V_83 ) ;
V_18 -> V_21 = V_21 ;
V_18 -> V_83 = V_83 ;
V_18 -> V_208 = V_208 ;
V_18 -> V_25 = V_25 ;
F_111 ( & V_18 -> V_59 ) ;
F_62 ( & V_18 -> V_209 , V_210 ) ;
V_18 -> V_48 . V_55 . V_211 = V_208 -> V_212 ( V_21 ) ;
F_103 ( V_21 , & V_18 -> V_48 . V_55 ) ;
F_107 ( V_83 ) ;
}
static int F_112 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 -> V_18 . V_22 ;
struct V_23 * V_24 = V_18 -> V_25 ;
struct V_26 * V_27 = V_24 -> V_27 ;
struct V_213 * V_214 ;
int V_32 ;
F_113 ( V_18 ) ;
V_32 = F_114 ( V_18 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_115 ( V_18 ) ;
if ( V_32 )
goto V_215;
V_214 = F_116 ( V_20 ,
V_27 -> V_33 ,
V_18 -> V_216 [ 0 ] . V_217 ) ;
if ( F_117 ( V_214 ) ) {
V_32 = F_118 ( V_214 ) ;
goto V_218;
}
V_27 -> V_219 = V_214 ;
V_32 = F_119 ( V_18 ) ;
if ( V_32 )
goto V_220;
return 0 ;
V_220:
F_120 ( V_27 -> V_219 ) ;
V_218:
F_121 ( V_18 ) ;
V_215:
F_122 ( V_18 ) ;
return V_32 ;
}
static void F_123 ( struct V_17 * V_18 )
{
struct V_23 * V_24 = V_18 -> V_25 ;
struct V_26 * V_27 = V_24 -> V_27 ;
F_124 ( V_18 ) ;
F_120 ( V_27 -> V_219 ) ;
F_121 ( V_18 ) ;
F_122 ( V_18 ) ;
}
static int F_125 ( struct V_17 * V_18 )
{
int V_32 ;
V_32 = F_126 ( V_18 ) ;
if ( V_32 ) {
F_127 ( V_18 -> V_21 , L_4 , V_32 ) ;
return V_32 ;
}
return 0 ;
}
static int F_128 ( struct V_177 * V_21 )
{
#define F_129 1
return F_129 ;
}
static int
F_130 ( struct V_19 * V_20 , struct V_26 * V_27 )
{
struct V_17 * V_18 = F_10 ( V_27 -> V_83 ) ;
struct V_23 * V_24 = V_18 -> V_25 ;
int V_32 ;
if ( F_12 ( V_60 , & V_18 -> V_61 ) ) {
V_32 = F_18 ( V_18 ) ;
if ( V_32 )
return V_32 ;
}
V_32 = F_58 ( V_24 ) ;
if ( V_32 )
goto V_221;
return 0 ;
V_221:
F_23 ( V_18 ) ;
return V_32 ;
}
static void
F_131 ( struct V_19 * V_20 , struct V_26 * V_27 )
{
struct V_17 * V_18 = F_10 ( V_27 -> V_83 ) ;
struct V_23 * V_24 = V_18 -> V_25 ;
if ( F_12 ( V_60 , & V_18 -> V_61 ) )
F_23 ( V_18 ) ;
F_124 ( V_18 ) ;
F_119 ( V_18 ) ;
F_65 ( V_24 ) ;
}
static int
F_132 ( struct V_19 * V_20 , struct V_26 * V_27 )
{
struct V_23 * V_24 ;
struct V_1 * V_83 ;
int V_32 ;
V_24 = F_77 ( sizeof( * V_24 ) , V_80 ) ;
if ( ! V_24 )
return - V_78 ;
V_83 = F_133 ( V_20 -> V_2 , & V_222 , V_24 ) ;
if ( ! V_83 ) {
F_6 ( L_5 ,
V_27 -> V_33 ) ;
F_21 ( V_24 ) ;
return - V_176 ;
}
V_27 -> V_83 = V_83 ;
V_24 -> V_27 = V_27 ;
V_32 = F_134 ( F_10 ( V_83 ) ) ;
if ( V_32 ) {
F_6 ( L_6 ,
V_27 -> V_33 ) ;
goto V_223;
}
V_32 = F_58 ( V_24 ) ;
if ( V_32 ) {
F_6 ( L_7 ,
V_27 -> V_33 ) ;
goto V_224;
}
V_32 = F_135 ( V_83 ) ;
if ( V_32 ) {
F_6 ( L_8 ,
V_27 -> V_33 ) ;
goto V_225;
}
return 0 ;
V_225:
F_65 ( V_24 ) ;
V_224:
F_136 ( F_10 ( V_83 ) ) ;
V_223:
F_137 ( F_10 ( V_83 ) ) ;
F_21 ( V_24 ) ;
return V_32 ;
}
static void
F_138 ( struct V_19 * V_20 , struct V_26 * V_27 )
{
struct V_1 * V_83 = V_27 -> V_83 ;
struct V_17 * V_18 = F_10 ( V_83 ) ;
struct V_23 * V_24 = V_18 -> V_25 ;
void * V_25 = V_18 -> V_25 ;
F_139 ( V_27 -> V_83 ) ;
F_65 ( V_24 ) ;
F_136 ( V_18 ) ;
F_137 ( V_18 ) ;
F_21 ( V_25 ) ;
}
static void F_140 ( struct V_17 * V_18 )
{
struct V_177 * V_21 = V_18 -> V_21 ;
struct V_19 * V_20 = V_21 -> V_18 . V_22 ;
int V_226 = F_141 ( V_21 ) ;
int V_33 ;
T_5 V_227 [ V_73 ] ;
F_142 ( V_21 , 0 , V_227 ) ;
for ( V_33 = 1 ; V_33 < V_226 ; V_33 ++ ) {
struct V_26 V_27 ;
V_27 . V_228 = F_132 ;
V_27 . V_229 = F_138 ;
V_27 . V_33 = V_33 ;
F_17 ( V_27 . V_74 , V_227 ) ;
F_143 ( V_20 , V_33 , & V_27 ) ;
}
}
static void F_144 ( struct V_17 * V_18 )
{
struct V_177 * V_21 = V_18 -> V_21 ;
struct V_19 * V_20 = V_21 -> V_18 . V_22 ;
int V_226 = F_141 ( V_21 ) ;
int V_33 ;
for ( V_33 = 1 ; V_33 < V_226 ; V_33 ++ )
F_145 ( V_20 , V_33 ) ;
}
void F_146 ( struct V_17 * V_18 )
{
struct V_177 * V_21 = V_18 -> V_21 ;
struct V_19 * V_20 = V_21 -> V_18 . V_22 ;
struct V_26 V_27 ;
F_142 ( V_21 , 0 , V_27 . V_74 ) ;
V_27 . V_228 = F_130 ;
V_27 . V_229 = F_131 ;
V_27 . V_33 = V_169 ;
V_27 . V_83 = V_18 -> V_83 ;
F_143 ( V_20 , 0 , & V_27 ) ;
F_140 ( V_18 ) ;
}
void F_147 ( struct V_17 * V_18 )
{
struct V_177 * V_21 = V_18 -> V_21 ;
struct V_19 * V_20 = V_21 -> V_18 . V_22 ;
F_144 ( V_18 ) ;
F_145 ( V_20 , 0 ) ;
}
