static int F_1 ( const char * V_1 , const struct V_2 * V_3 )
{
int V_4 = 0 ;
unsigned long * V_5 = ( unsigned long * ) V_3 -> V_6 ,
V_7 = * V_5 , V_8 , V_9 ,
V_10 = ( ( V_11 << V_12 ) |
V_11 ) ;
V_4 = F_2 ( V_1 , 0 , & V_8 ) ;
if ( V_4 ) {
F_3 ( L_1 ) ;
goto V_13;
}
V_9 = V_8 ^ ( V_7 & ~ V_14 ) ;
if ( F_4 () && ( V_9 & ~ V_10 ) ) {
F_3 ( L_2 ,
V_9 & ~ V_10 ) ;
V_9 &= V_10 ;
}
V_9 &= ~ V_15 ;
V_7 &= ~ V_9 ;
V_7 |= ( V_8 & V_9 ) ;
V_9 = ( V_7 & ( V_16 << V_12 ) ) ^
( ( V_7 & V_16 ) << V_12 ) ;
V_7 &= ~ V_9 ;
* V_5 = V_7 ;
V_13:
return V_4 ;
}
static int F_5 ( char * V_17 , const struct V_2 * V_3 )
{
unsigned long V_7 = * ( unsigned long * ) V_3 -> V_6 ;
V_7 &= ~ V_14 ;
V_7 |= ( ( V_7 & V_18 ) << V_12 ) ;
return F_6 ( V_17 , V_19 , L_3 , V_7 ) ;
}
const char * F_7 ( int V_20 )
{
static char V_21 [ 16 ] ;
snprintf ( V_21 , sizeof( V_21 ) , V_22 L_4 , V_20 ) ;
return V_21 ;
}
const char * F_8 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = F_9 ( V_24 , struct V_25 , V_24 ) ;
struct V_27 * V_28 = F_9 ( V_26 ,
struct V_27 , V_29 ) ;
return F_7 ( V_28 -> V_20 ) ;
}
struct V_30 * F_10 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = F_9 ( V_24 , struct V_25 , V_24 ) ;
struct V_27 * V_28 = F_9 ( V_26 ,
struct V_27 , V_29 ) ;
return V_28 -> V_31 ;
}
int F_11 ( void )
{
struct V_27 * V_28 ;
struct V_32 * V_33 ;
unsigned long V_34 ;
int V_35 , V_36 = 0 ;
F_12 ( & V_37 , V_34 ) ;
F_13 (dd, &hfi1_dev_list, list) {
if ( ! ( V_28 -> V_34 & V_38 ) || ! V_28 -> V_39 )
continue;
for ( V_35 = 0 ; V_35 < V_28 -> V_40 ; ++ V_35 ) {
V_33 = V_28 -> V_41 + V_35 ;
if ( V_33 -> V_42 && V_33 -> V_43 ) {
V_36 ++ ;
break;
}
}
}
F_14 ( & V_37 , V_34 ) ;
return V_36 ;
}
static inline void * F_15 ( const struct V_44 * V_45 , T_1 V_46 ,
T_2 * V_47 )
{
T_3 V_48 = F_16 ( V_46 ) , V_49 = F_17 ( V_46 ) ;
* V_47 |= ! ( V_48 & ( V_45 -> V_50 . V_51 - 1 ) ) && ! V_49 ;
return ( void * ) ( ( ( T_1 ) ( V_45 -> V_50 . V_52 [ V_48 ] . V_53 ) ) +
( V_49 * V_54 ) ) ;
}
int F_18 ( T_3 V_55 , T_2 type , T_4 * V_56 )
{
if ( F_19 ( ! F_20 ( V_55 ) ) )
return 0 ;
if ( F_19 ( V_55 < V_57 ) )
return 0 ;
if ( V_55 >
( type == V_58 ? V_59 : V_60 ) )
return 0 ;
if ( V_56 )
* V_56 = F_21 ( V_55 / V_19 ) + 1 ;
return 1 ;
}
static void F_22 ( struct V_44 * V_45 , struct V_32 * V_33 ,
struct V_61 * V_62 )
{
struct V_63 * V_64 = V_62 -> V_65 ;
T_3 V_66 = F_23 ( V_62 -> V_46 ) ;
int V_67 = F_24 ( V_64 ) ;
struct V_68 * V_69 = F_25 ( V_45 ) ;
struct V_27 * V_28 = V_33 -> V_28 ;
struct V_23 * V_24 = & V_28 -> V_29 . V_24 ;
if ( V_62 -> V_46 & ( V_70 | V_71 ) )
return;
if ( V_62 -> V_46 & V_72 ) {
struct V_73 * V_74 = NULL ;
T_3 V_75 = F_26 ( V_62 -> V_46 ) ;
T_4 V_42 = F_27 ( V_64 ) ;
T_3 V_76 ;
T_3 V_77 = 0 ;
if ( V_75 < 24 )
goto V_78;
if ( V_67 == V_79 ) {
V_74 = & V_64 -> V_80 . V_81 ;
} else if ( V_67 == V_82 ) {
T_3 V_83 ;
V_74 = & V_64 -> V_80 . V_84 . V_81 ;
if ( V_64 -> V_80 . V_84 . V_85 . V_86 != V_87 )
goto V_78;
V_83 = F_28 ( V_64 -> V_80 . V_84 . V_85 . V_88 ) ;
if ( ( V_83 >> V_89 ) != V_90 )
goto V_78;
V_77 |= V_91 ;
} else {
goto V_78;
}
V_76 = F_28 ( V_74 -> V_92 [ 1 ] ) & V_93 ;
if ( V_42 < F_29 ( V_94 ) ) {
struct V_95 * V_96 ;
unsigned long V_34 ;
F_30 () ;
V_96 = F_31 ( V_24 , & V_69 -> V_97 , V_76 ) ;
if ( ! V_96 ) {
F_32 () ;
goto V_78;
}
F_12 ( & V_96 -> V_98 , V_34 ) ;
if ( ! ( V_99 [ V_96 -> V_100 ] &
V_101 ) ) {
V_69 -> V_97 . V_102 ++ ;
}
switch ( V_96 -> V_103 . V_104 ) {
case V_105 :
F_33 (
V_45 ,
V_64 ,
V_77 ,
V_96 ) ;
break;
default:
break;
}
F_14 ( & V_96 -> V_98 , V_34 ) ;
F_32 () ;
}
}
switch ( V_66 ) {
case V_106 :
{
T_3 V_107 ;
void * V_108 = NULL ;
T_5 * V_92 = NULL ;
if ( F_34 ( V_62 -> V_46 ) )
V_108 = V_62 -> V_108 ;
if ( ! V_108 )
goto V_78;
if ( V_67 == V_79 )
V_92 = ( T_5 * ) V_108 ;
else if ( V_67 == V_82 )
V_92 = ( T_5 * ) ( ( char * ) V_108 + sizeof( struct V_109 ) ) ;
else
goto V_78;
V_107 = F_28 ( V_92 [ 0 ] ) >> 24 ;
V_107 &= 0xff ;
if ( V_107 == V_110 ) {
struct V_95 * V_96 = NULL ;
T_3 V_111 , V_112 ;
T_4 V_113 ;
T_2 V_114 , V_115 , V_116 ;
V_116 = F_35 ( V_64 , V_62 -> V_46 ) ;
V_115 = V_69 -> V_117 [ V_116 ] ;
V_111 = F_28 ( V_92 [ 1 ] ) & V_93 ;
F_30 () ;
V_96 = F_31 ( V_24 , & V_69 -> V_97 , V_111 ) ;
if ( ! V_96 ) {
F_32 () ;
goto V_78;
}
switch ( V_96 -> V_103 . V_104 ) {
case V_118 :
V_113 = 0 ;
V_112 = 0 ;
V_114 = V_119 ;
break;
case V_120 :
V_113 = F_36 ( V_64 ) ;
V_112 = V_96 -> V_121 ;
V_114 = V_122 ;
break;
default:
goto V_78;
}
F_37 ( V_33 , V_115 , V_113 , V_111 , V_112 , V_114 ) ;
F_32 () ;
}
V_62 -> V_46 &= ~ V_123 ;
break;
}
default:
break;
}
V_78:
return;
}
static inline void F_38 ( struct V_44 * V_45 ,
struct V_61 * V_62 )
{
V_62 -> V_124 = V_45 -> V_125 ;
V_62 -> V_126 = V_45 -> V_127 * V_62 -> V_124 ;
V_62 -> V_45 = V_45 ;
V_62 -> V_128 = 0 ;
V_62 -> V_129 = - 1 ;
V_62 -> V_130 = F_39 ( V_45 ) ;
V_62 -> V_46 = F_40 ( V_62 -> V_130 ) ;
V_62 -> V_131 = V_45 -> V_132 ;
V_62 -> V_133 = 0 ;
V_62 -> V_77 = 0 ;
}
void F_41 ( struct V_95 * V_96 , struct V_61 * V_134 ,
bool V_135 )
{
struct V_68 * V_69 = F_42 ( V_96 -> V_103 . V_136 , V_96 -> V_137 ) ;
struct V_63 * V_65 = V_134 -> V_65 ;
struct V_73 * V_74 = V_134 -> V_74 ;
struct V_109 * V_85 = NULL ;
T_3 V_112 = 0 , V_138 ;
T_4 V_113 , V_139 = F_27 ( V_65 ) ;
T_2 V_140 , V_114 ;
bool V_141 = false ;
if ( V_134 -> V_77 & V_91 )
V_85 = & V_65 -> V_80 . V_84 . V_85 ;
switch ( V_96 -> V_103 . V_104 ) {
case V_142 :
case V_143 :
case V_118 :
V_113 = F_36 ( V_65 ) ;
V_112 = F_28 ( V_74 -> V_80 . V_144 . V_145 [ 1 ] ) & V_93 ;
V_114 = V_119 ;
V_141 = ( V_139 > F_29 ( V_94 ) ) &&
( V_139 != F_29 ( V_146 ) ) ;
break;
case V_120 :
V_113 = F_43 ( & V_96 -> V_147 ) ;
V_112 = V_96 -> V_121 ;
V_114 = V_122 ;
break;
case V_105 :
V_113 = F_43 ( & V_96 -> V_147 ) ;
V_112 = V_96 -> V_121 ;
V_114 = V_148 ;
break;
default:
return;
}
V_140 = F_35 ( V_65 , V_134 -> V_46 ) ;
V_138 = F_28 ( V_74 -> V_92 [ 1 ] ) ;
if ( V_135 && ( V_138 & V_149 ) ) {
T_4 V_150 = ( T_4 ) F_28 ( V_74 -> V_92 [ 0 ] ) ;
F_44 ( V_69 , V_96 , V_112 , V_150 , V_139 , V_113 , V_140 , V_85 ) ;
}
if ( ! V_141 && ( V_138 & V_151 ) ) {
struct V_32 * V_33 = F_45 ( V_69 ) ;
T_3 V_111 = V_138 & V_93 ;
T_2 V_115 = V_69 -> V_117 [ V_140 ] ;
F_37 ( V_33 , V_115 , V_113 , V_111 , V_112 , V_114 ) ;
}
}
static inline void F_46 ( struct V_152 * V_153 ,
struct V_61 * V_62 )
{
struct V_44 * V_45 = V_62 -> V_45 ;
V_153 -> V_45 = V_45 ;
V_153 -> V_124 = V_62 -> V_124 ;
V_153 -> V_126 = V_62 -> V_126 ;
V_153 -> V_154 = V_62 -> V_131 ;
if ( F_47 ( V_45 -> V_34 , V_155 ) ) {
V_153 -> V_156 = F_48 ( V_45 ) ;
if ( V_45 -> V_157 == V_158 )
V_153 -> V_159 = V_45 -> V_160 ;
else
V_153 -> V_159 = 0 ;
} else {
V_153 -> V_156 = 0 ;
V_153 -> V_159 = V_45 -> V_160 ;
}
}
static inline int F_49 ( struct V_152 * V_153 , T_1 V_46 ,
struct V_44 * V_45 )
{
if ( F_47 ( V_45 -> V_34 , V_155 ) )
return V_153 -> V_154 == V_153 -> V_156 ;
return V_153 -> V_159 != F_50 ( V_46 ) ;
}
static inline int F_51 ( struct V_152 * V_153 , T_1 V_46 ,
struct V_44 * V_45 )
{
if ( ( V_45 -> V_157 == V_158 ) && ( V_153 -> V_154 != V_153 -> V_156 ) )
return V_153 -> V_159 != F_50 ( V_46 ) ;
return 0 ;
}
static inline void F_52 ( struct V_152 * V_153 ,
struct V_44 * V_45 )
{
V_153 -> V_154 += V_153 -> V_124 ;
if ( V_153 -> V_154 >= V_153 -> V_126 )
V_153 -> V_154 = 0 ;
if ( ! F_47 ( V_45 -> V_34 , V_155 ) ||
( V_45 -> V_157 == V_158 ) ) {
if ( ++ V_153 -> V_159 > 13 )
V_153 -> V_159 = 1 ;
}
}
static void F_53 ( struct V_61 * V_62 )
{
struct V_44 * V_45 = V_62 -> V_45 ;
struct V_152 V_153 ;
F_46 ( & V_153 , V_62 ) ;
while ( 1 ) {
struct V_27 * V_28 = V_45 -> V_28 ;
struct V_68 * V_69 = F_25 ( V_45 ) ;
T_6 * V_130 = ( T_6 * ) V_45 -> V_161 + V_153 . V_154 +
V_28 -> V_162 ;
struct V_95 * V_96 ;
struct V_63 * V_65 ;
struct V_23 * V_24 = & V_28 -> V_29 . V_24 ;
T_1 V_46 = F_40 ( V_130 ) ;
T_3 V_163 = F_54 ( V_46 ) , V_164 , V_138 ;
int V_165 = 0 ;
T_2 V_67 ;
if ( F_49 ( & V_153 , V_46 , V_45 ) )
break;
if ( F_51 ( & V_153 , V_46 , V_45 ) )
goto V_166;
if ( V_163 != V_167 )
goto V_166;
V_62 -> V_65 = F_55 ( V_28 , V_130 ) ;
V_65 = V_62 -> V_65 ;
V_67 = F_24 ( V_65 ) ;
if ( V_67 == V_79 ) {
V_62 -> V_74 = & V_65 -> V_80 . V_81 ;
} else if ( V_67 == V_82 ) {
V_62 -> V_74 = & V_65 -> V_80 . V_84 . V_81 ;
V_62 -> V_77 |= V_91 ;
} else {
goto V_166;
}
V_138 = F_28 ( V_62 -> V_74 -> V_92 [ 1 ] ) ;
V_165 = ! ! ( V_138 & ( V_149 | V_151 ) ) ;
if ( ! V_165 )
goto V_166;
V_164 = V_138 & V_93 ;
F_30 () ;
V_96 = F_31 ( V_24 , & V_69 -> V_97 , V_164 ) ;
if ( ! V_96 ) {
F_32 () ;
goto V_166;
}
F_56 ( V_96 , V_62 , true ) ;
F_32 () ;
V_138 &= ~ ( V_149 | V_151 ) ;
V_62 -> V_74 -> V_92 [ 1 ] = F_57 ( V_138 ) ;
V_166:
F_52 ( & V_153 , V_45 ) ;
}
}
static void F_58 ( struct V_44 * V_45 )
{
struct V_95 * V_96 , * V_168 ;
F_59 (qp, nqp, &rcd->qp_wait_list, rspwait) {
F_60 ( & V_96 -> V_169 ) ;
if ( V_96 -> V_170 & V_171 ) {
V_96 -> V_170 &= ~ V_171 ;
F_61 ( V_45 , V_96 , 0 ) ;
}
if ( V_96 -> V_170 & V_172 ) {
unsigned long V_34 ;
V_96 -> V_170 &= ~ V_172 ;
F_12 ( & V_96 -> V_173 , V_34 ) ;
if ( V_99 [ V_96 -> V_100 ] &
V_174 )
F_62 ( V_96 ) ;
F_14 ( & V_96 -> V_173 , V_34 ) ;
}
F_63 ( V_96 ) ;
}
}
static T_7 int F_64 ( struct V_61 * V_62 , int V_175 )
{
if ( V_175 ) {
if ( ( V_62 -> V_133 & ( V_176 - 1 ) ) == 0 )
F_58 ( V_62 -> V_45 ) ;
F_65 () ;
return V_177 ;
} else {
F_66 ( * V_62 -> V_45 -> V_28 -> V_178 ) ;
return V_179 ;
}
}
static inline int F_67 ( struct V_61 * V_62 , int V_175 )
{
int V_4 = V_177 ;
if ( F_19 ( ( V_62 -> V_133 & ( V_180 - 1 ) ) == 0 ) )
V_4 = F_64 ( V_62 , V_175 ) ;
return V_4 ;
}
static T_7 int F_68 ( struct V_61 * V_62 , int V_175 )
{
int V_4 ;
V_62 -> V_131 += V_62 -> V_124 ;
if ( V_62 -> V_131 >= V_62 -> V_126 )
V_62 -> V_131 = 0 ;
V_62 -> V_133 ++ ;
V_4 = F_67 ( V_62 , V_175 ) ;
V_62 -> V_130 = ( T_6 * ) V_62 -> V_45 -> V_161 + V_62 -> V_131 +
V_62 -> V_45 -> V_28 -> V_162 ;
V_62 -> V_46 = F_40 ( V_62 -> V_130 ) ;
return V_4 ;
}
static inline int F_69 ( struct V_61 * V_62 , int V_175 )
{
int V_4 ;
V_62 -> V_65 = F_55 ( V_62 -> V_45 -> V_28 ,
V_62 -> V_130 ) ;
V_62 -> V_181 = ( T_2 * ) V_62 -> V_130 - ( T_2 * ) V_62 -> V_65 ;
V_62 -> V_163 = F_54 ( V_62 -> V_46 ) ;
V_62 -> V_75 = F_26 ( V_62 -> V_46 ) ;
V_62 -> V_108 = NULL ;
if ( F_34 ( V_62 -> V_46 ) ) {
V_62 -> V_129 = F_16 ( V_62 -> V_46 ) ;
V_62 -> V_108 = F_15 ( V_62 -> V_45 , V_62 -> V_46 ,
& V_62 -> V_128 ) ;
F_70 ( V_62 -> V_108 ,
V_62 -> V_75 - ( ( V_62 -> V_45 -> V_125 -
( F_71 ( V_62 -> V_46 )
+ 2 ) ) * 4 ) ) ;
}
V_62 -> V_45 -> V_28 -> V_182 [ V_62 -> V_163 ] ( V_62 ) ;
V_62 -> V_133 ++ ;
V_62 -> V_131 += V_62 -> V_124 ;
if ( V_62 -> V_131 >= V_62 -> V_126 )
V_62 -> V_131 = 0 ;
V_4 = F_67 ( V_62 , V_175 ) ;
V_62 -> V_130 = ( T_6 * ) V_62 -> V_45 -> V_161 + V_62 -> V_131 +
V_62 -> V_45 -> V_28 -> V_162 ;
V_62 -> V_46 = F_40 ( V_62 -> V_130 ) ;
return V_4 ;
}
static inline void F_72 ( int V_183 , struct V_61 * V_62 )
{
if ( ! V_183 && ! ( V_62 -> V_133 & 0xf ) ) {
F_73 ( V_62 -> V_45 , V_62 -> V_131 , V_62 -> V_128 ,
V_62 -> V_129 , 0 , 0 ) ;
V_62 -> V_128 = 0 ;
}
V_62 -> V_77 = 0 ;
}
static inline void F_74 ( struct V_61 * V_62 )
{
F_73 ( V_62 -> V_45 , V_62 -> V_45 -> V_132 , V_62 -> V_128 ,
V_62 -> V_129 , V_184 , V_62 -> V_133 ) ;
}
int F_75 ( struct V_44 * V_45 , int V_175 )
{
T_3 V_185 ;
int V_183 = V_177 ;
struct V_61 V_62 ;
F_38 ( V_45 , & V_62 ) ;
V_185 = F_50 ( V_62 . V_46 ) ;
if ( V_185 != V_45 -> V_160 ) {
V_183 = V_186 ;
goto V_187;
}
F_76 ( V_45 , & V_62 ) ;
while ( V_183 == V_177 ) {
V_183 = F_69 ( & V_62 , V_175 ) ;
V_185 = F_50 ( V_62 . V_46 ) ;
if ( ++ V_45 -> V_160 > 13 )
V_45 -> V_160 = 1 ;
if ( V_185 != V_45 -> V_160 )
V_183 = V_186 ;
F_72 ( V_183 , & V_62 ) ;
}
F_58 ( V_45 ) ;
V_45 -> V_132 = V_62 . V_131 ;
V_187:
F_74 ( & V_62 ) ;
return V_183 ;
}
int F_77 ( struct V_44 * V_45 , int V_175 )
{
T_3 V_188 ;
int V_183 = V_177 ;
struct V_61 V_62 ;
F_38 ( V_45 , & V_62 ) ;
V_188 = F_48 ( V_45 ) ;
if ( V_62 . V_131 == V_188 ) {
V_183 = V_186 ;
goto V_187;
}
F_78 () ;
F_76 ( V_45 , & V_62 ) ;
while ( V_183 == V_177 ) {
V_183 = F_69 ( & V_62 , V_175 ) ;
if ( V_62 . V_131 == V_188 )
V_183 = V_186 ;
F_72 ( V_183 , & V_62 ) ;
}
F_58 ( V_45 ) ;
V_45 -> V_132 = V_62 . V_131 ;
V_187:
F_74 ( & V_62 ) ;
return V_183 ;
}
static inline void F_79 ( struct V_27 * V_28 , T_2 V_157 )
{
int V_189 ;
if ( V_157 >= V_28 -> V_190 ) {
V_28 -> V_45 [ V_157 ] -> V_191 =
& F_75 ;
return;
}
for ( V_189 = V_158 + 1 ; V_189 < V_28 -> V_190 ; V_189 ++ )
V_28 -> V_45 [ V_189 ] -> V_191 =
& F_75 ;
}
static inline void F_80 ( struct V_27 * V_28 , T_2 V_157 )
{
int V_189 ;
if ( V_157 >= V_28 -> V_190 ) {
V_28 -> V_45 [ V_157 ] -> V_191 =
& F_77 ;
return;
}
for ( V_189 = V_158 + 1 ; V_189 < V_28 -> V_190 ; V_189 ++ )
V_28 -> V_45 [ V_189 ] -> V_191 =
& F_77 ;
}
void F_81 ( struct V_27 * V_28 )
{
int V_189 ;
for ( V_189 = V_158 + 1 ; V_189 < V_28 -> V_192 ; V_189 ++ ) {
struct V_44 * V_45 = V_28 -> V_45 [ V_189 ] ;
if ( ( V_189 < V_28 -> V_190 ) ||
( V_45 && V_45 -> V_140 && ( V_45 -> V_140 -> type == V_193 ) ) )
V_45 -> V_191 = & V_194 ;
}
}
static inline int F_82 ( struct V_44 * V_45 ,
struct V_61 * V_62 ,
struct V_27 * V_28 )
{
struct V_195 * V_196 = & V_45 -> V_33 -> V_197 ;
struct V_63 * V_65 = F_55 ( V_62 -> V_45 -> V_28 ,
V_62 -> V_130 ) ;
T_2 V_163 = F_54 ( V_62 -> V_46 ) ;
if ( V_163 == V_167 &&
F_35 ( V_65 , V_62 -> V_46 ) != 0xf ) {
int V_198 = F_83 ( V_28 ) ;
if ( V_198 != V_199 ) {
F_84 ( V_28 , L_5 , V_198 ) ;
return 0 ;
}
F_85 ( V_45 -> V_33 -> V_200 , V_196 ) ;
return 1 ;
}
return 0 ;
}
int V_194 ( struct V_44 * V_45 , int V_175 )
{
struct V_27 * V_28 = V_45 -> V_28 ;
T_3 V_188 ;
int V_201 , V_183 = V_177 ;
struct V_61 V_62 ;
int V_202 = 0 ;
V_201 = ( V_45 -> V_157 == V_158 ) ? 0 : 1 ;
F_38 ( V_45 , & V_62 ) ;
if ( ! F_47 ( V_45 -> V_34 , V_155 ) ) {
T_3 V_185 = F_50 ( V_62 . V_46 ) ;
if ( V_185 != V_45 -> V_160 ) {
V_183 = V_186 ;
goto V_187;
}
V_188 = 0 ;
} else {
V_188 = F_48 ( V_45 ) ;
if ( V_62 . V_131 == V_188 ) {
V_183 = V_186 ;
goto V_187;
}
F_78 () ;
if ( V_45 -> V_157 == V_158 ) {
T_3 V_185 = F_50 ( V_62 . V_46 ) ;
if ( V_185 != V_45 -> V_160 )
V_202 = 1 ;
}
}
F_76 ( V_45 , & V_62 ) ;
while ( V_183 == V_177 ) {
if ( F_19 ( V_28 -> V_203 &&
F_86 ( & V_28 -> V_204 , V_205 ) ==
V_206 ) ) {
V_28 -> V_203 = 0 ;
V_62 . V_131 += V_62 . V_124 ;
V_62 . V_130 = ( T_6 * ) V_45 -> V_161 +
V_62 . V_131 +
V_28 -> V_162 ;
V_62 . V_46 = F_40 ( V_62 . V_130 ) ;
} else if ( V_202 ) {
V_183 = F_68 ( & V_62 , V_175 ) ;
V_202 = 0 ;
} else {
if ( F_19 ( V_45 -> V_33 -> V_207 ==
V_208 ) &&
F_82 ( V_45 , & V_62 , V_28 ) )
goto V_187;
V_183 = F_69 ( & V_62 , V_175 ) ;
}
if ( ! F_47 ( V_45 -> V_34 , V_155 ) ) {
T_3 V_185 = F_50 ( V_62 . V_46 ) ;
if ( ++ V_45 -> V_160 > 13 )
V_45 -> V_160 = 1 ;
if ( V_185 != V_45 -> V_160 )
V_183 = V_186 ;
if ( V_201 ) {
F_84 ( V_28 , L_6 ) ;
F_79 ( V_28 , V_45 -> V_157 ) ;
V_201 = 0 ;
}
} else {
if ( V_62 . V_131 == V_188 )
V_183 = V_186 ;
if ( V_45 -> V_157 == V_158 ) {
T_3 V_185 = F_50 ( V_62 . V_46 ) ;
if ( ++ V_45 -> V_160 > 13 )
V_45 -> V_160 = 1 ;
if ( ! V_183 && ( V_185 != V_45 -> V_160 ) )
V_202 = 1 ;
}
if ( V_201 ) {
F_84 ( V_28 ,
L_7 ) ;
F_80 ( V_28 , V_45 -> V_157 ) ;
V_201 = 0 ;
}
}
F_72 ( V_183 , & V_62 ) ;
}
F_58 ( V_45 ) ;
V_45 -> V_132 = V_62 . V_131 ;
V_187:
F_74 ( & V_62 ) ;
return V_183 ;
}
void F_87 ( struct V_195 * V_209 )
{
struct V_32 * V_33 = F_9 ( V_209 , struct V_32 ,
V_197 ) ;
struct V_27 * V_28 = V_33 -> V_28 ;
int V_189 ;
V_33 -> V_210 = 1 ;
F_88 ( V_33 , V_211 ) ;
for ( V_189 = V_158 ; V_189 < V_28 -> V_190 ; V_189 ++ )
F_89 ( V_28 -> V_45 [ V_189 ] ) ;
}
int F_90 ( T_3 V_212 , int V_213 )
{
switch ( V_212 ) {
case 0 : return V_214 ;
case 256 : return V_215 ;
case 512 : return V_216 ;
case 1024 : return V_217 ;
case 2048 : return V_218 ;
case 4096 : return V_219 ;
case 8192 : return V_220 ;
case 10240 : return V_221 ;
}
return V_213 ;
}
T_4 F_91 ( int V_212 )
{
switch ( V_212 ) {
case V_214 : return 0 ;
case V_215 : return 256 ;
case V_216 : return 512 ;
case V_217 : return 1024 ;
case V_218 : return 2048 ;
case V_219 : return 4096 ;
case V_220 : return 8192 ;
case V_221 : return 10240 ;
default: return 0xffff ;
}
}
int F_92 ( struct V_32 * V_33 )
{
struct V_27 * V_28 = V_33 -> V_28 ;
int V_189 , V_222 , V_4 = 0 , V_223 = 0 ;
V_33 -> V_224 = 0 ;
for ( V_189 = 0 ; V_189 < V_33 -> V_225 ; V_189 ++ )
if ( V_33 -> V_224 < V_28 -> V_226 [ V_189 ] . V_212 )
V_33 -> V_224 = V_28 -> V_226 [ V_189 ] . V_212 ;
V_33 -> V_227 = V_33 -> V_224 + F_93 ( V_33 -> V_28 ) ;
F_94 ( & V_33 -> V_228 ) ;
if ( V_33 -> V_207 == V_229 ||
V_33 -> V_207 == V_208 ||
V_33 -> V_207 == V_211 )
V_223 = 1 ;
V_222 = ! F_95 ( V_28 ) && V_223 ;
if ( V_222 )
V_4 = F_96 ( V_28 ) ;
if ( V_4 ) {
F_97 ( V_28 , L_8 ,
V_230 ) ;
goto V_231;
}
F_98 ( V_33 , V_232 , 0 ) ;
if ( V_222 )
F_99 ( V_28 ) ;
V_231:
F_100 ( & V_33 -> V_228 ) ;
return V_4 ;
}
int F_101 ( struct V_32 * V_33 , T_3 V_42 , T_2 V_233 )
{
struct V_27 * V_28 = V_33 -> V_28 ;
V_33 -> V_42 = V_42 ;
V_33 -> V_233 = V_233 ;
F_98 ( V_33 , V_234 , 0 ) ;
F_84 ( V_28 , L_9 , V_33 -> V_235 , V_42 ) ;
return 0 ;
}
void F_102 ( struct V_32 * V_33 )
{
struct V_27 * V_28 = V_33 -> V_28 ;
F_78 () ;
if ( F_103 ( & V_33 -> V_236 ) ) {
F_104 ( & V_33 -> V_237 ) ;
F_105 ( & V_33 -> V_236 , 0 ) ;
F_106 () ;
}
F_107 ( V_28 , V_238 , 0 ) ;
}
static void F_108 ( unsigned long V_239 )
{
struct V_32 * V_33 = (struct V_32 * ) V_239 ;
struct V_27 * V_28 = V_33 -> V_28 ;
unsigned long V_240 ;
int V_241 ;
if ( ! ( V_28 -> V_34 & V_242 ) )
return;
V_241 = V_33 -> V_243 & 1 ;
F_109 ( V_28 , V_241 ) ;
V_240 = V_33 -> V_244 [ V_241 ] ;
V_33 -> V_243 = ! V_33 -> V_243 ;
F_110 ( & V_33 -> V_237 , V_245 + V_240 ) ;
}
void F_111 ( struct V_32 * V_33 , unsigned int V_246 ,
unsigned int V_247 )
{
if ( ! ( V_33 -> V_28 -> V_34 & V_242 ) )
return;
V_33 -> V_244 [ 0 ] = F_112 ( V_247 ) ;
V_33 -> V_244 [ 1 ] = F_112 ( V_246 ) ;
V_33 -> V_243 = 1 ;
if ( ! F_113 ( & V_33 -> V_237 ) ) {
F_114 ( & V_33 -> V_237 , F_108 ,
( unsigned long ) V_33 ) ;
V_33 -> V_237 . V_248 = V_245 + 1 ;
F_115 ( & V_33 -> V_237 ) ;
F_105 ( & V_33 -> V_236 , 1 ) ;
F_106 () ;
}
}
int F_116 ( int V_20 )
{
int V_4 , V_189 ;
struct V_27 * V_28 = F_117 ( V_20 ) ;
struct V_32 * V_33 ;
unsigned long V_34 ;
int V_35 ;
if ( ! V_28 ) {
V_4 = - V_249 ;
goto V_187;
}
F_84 ( V_28 , L_10 , V_20 ) ;
if ( ! V_28 -> V_39 || ! ( V_28 -> V_34 & V_38 ) ) {
F_84 ( V_28 ,
L_11 ,
V_20 ) ;
V_4 = - V_250 ;
goto V_187;
}
F_12 ( & V_28 -> V_251 , V_34 ) ;
if ( V_28 -> V_45 )
for ( V_189 = V_28 -> V_190 ;
V_189 < V_28 -> V_192 ; V_189 ++ ) {
if ( ! V_28 -> V_45 [ V_189 ] )
continue;
F_14 ( & V_28 -> V_251 , V_34 ) ;
V_4 = - V_252 ;
goto V_187;
}
F_14 ( & V_28 -> V_251 , V_34 ) ;
for ( V_35 = 0 ; V_35 < V_28 -> V_40 ; ++ V_35 ) {
V_33 = V_28 -> V_41 + V_35 ;
F_102 ( V_33 ) ;
}
if ( V_28 -> V_34 & V_253 )
F_118 ( V_28 ) ;
F_119 ( V_28 ) ;
V_4 = F_120 ( V_28 , 1 ) ;
if ( V_4 )
F_97 ( V_28 ,
L_12 ,
V_20 , V_4 ) ;
else
F_84 ( V_28 , L_13 ,
V_20 ) ;
V_187:
return V_4 ;
}
void F_121 ( struct V_61 * V_62 )
{
struct V_44 * V_45 = V_62 -> V_45 ;
T_3 V_66 = F_23 ( V_62 -> V_46 ) ;
F_22 ( V_45 , V_45 -> V_33 , V_62 ) ;
if ( F_122 ( V_62 -> V_46 ) )
F_97 ( V_45 -> V_28 ,
L_14 ,
V_45 -> V_157 , V_62 -> V_46 ,
V_62 -> V_46 & V_254 ? L_15 : L_16 ,
V_62 -> V_46 & V_255 ? L_17 : L_16 ,
V_62 -> V_46 & V_256 ? L_18 : L_16 ,
V_62 -> V_46 & V_72 ? L_19 : L_16 ,
V_62 -> V_46 & V_257 ? L_20 : L_16 ,
V_62 -> V_46 & V_258 ? L_21 : L_16 ,
V_62 -> V_46 & V_70 ? L_22 : L_16 ,
V_62 -> V_46 & V_71 ? L_23 : L_16 ,
V_66 ) ;
}
int F_123 ( struct V_61 * V_62 )
{
if ( F_19 ( F_124 ( V_62 ) ) )
return V_259 ;
F_125 ( V_62 -> V_45 -> V_33 -> V_28 ,
V_62 -> V_45 -> V_157 ,
F_122 ( V_62 -> V_46 ) ,
V_167 ,
V_62 -> V_181 ,
V_62 -> V_75 ,
V_62 -> V_128 ,
F_16 ( V_62 -> V_46 ) ) ;
if ( F_19 (
( F_126 ( & V_62 -> V_45 -> V_28 -> V_29 ) &&
( V_62 -> V_46 & V_256 ) ) ) )
return V_259 ;
if ( F_19 ( F_122 ( V_62 -> V_46 ) ) ) {
F_121 ( V_62 ) ;
return V_259 ;
}
F_127 ( V_62 ) ;
return V_259 ;
}
static inline bool F_128 ( struct V_61 * V_62 )
{
if ( V_62 -> V_45 -> V_260 )
return true ;
if ( ( F_129 ( V_62 -> V_108 ) == V_261 ) &&
( F_130 ( V_62 -> V_108 ) == V_262 ) )
return true ;
return false ;
}
int F_131 ( struct V_61 * V_62 )
{
struct V_27 * V_28 = V_62 -> V_45 -> V_28 ;
if ( F_19 ( F_122 ( V_62 -> V_46 ) ) ) {
F_121 ( V_62 ) ;
} else if ( F_128 ( V_62 ) ) {
F_132 ( V_62 ) ;
return V_259 ;
}
F_97 ( V_28 , L_24 ) ;
F_133 ( & V_28 -> V_263 ) ;
if ( ! ( V_28 -> V_264 . V_265 & V_266 ) ) {
T_1 * V_267 = V_62 -> V_108 ;
if ( V_267 && ! ( V_62 -> V_46 & V_257 ) ) {
V_28 -> V_264 . V_268 = V_267 [ 0 ] ;
V_28 -> V_264 . V_269 =
V_62 -> V_75 > sizeof( V_267 [ 0 ] ) ? V_267 [ 1 ] : 0 ;
}
V_28 -> V_264 . V_265 |=
( V_266 | V_270 ) ;
}
return V_259 ;
}
int F_134 ( struct V_61 * V_62 )
{
if ( F_19 (
F_126 ( & V_62 -> V_45 -> V_28 -> V_29 ) &&
F_23 ( V_62 -> V_46 ) == 3 ) )
return V_259 ;
F_121 ( V_62 ) ;
if ( F_19 ( F_122 ( V_62 -> V_46 ) ) )
F_97 ( V_62 -> V_45 -> V_28 ,
L_25 ) ;
return V_259 ;
}
int F_135 ( struct V_61 * V_62 )
{
if ( F_19 ( F_124 ( V_62 ) ) )
return V_259 ;
if ( F_19 ( F_122 ( V_62 -> V_46 ) ) )
F_121 ( V_62 ) ;
F_97 ( V_62 -> V_45 -> V_28 ,
L_26 ) ;
return V_259 ;
}
int F_136 ( struct V_61 * V_62 )
{
if ( F_19 ( F_122 ( V_62 -> V_46 ) ) )
F_121 ( V_62 ) ;
if ( F_19 ( F_124 ( V_62 ) ) )
return V_259 ;
F_97 ( V_62 -> V_45 -> V_28 ,
L_27 ) ;
return V_259 ;
}
int F_137 ( struct V_61 * V_62 )
{
F_97 ( V_62 -> V_45 -> V_28 , L_28 ,
F_54 ( V_62 -> V_46 ) ) ;
return V_259 ;
}
