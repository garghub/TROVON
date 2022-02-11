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
int F_15 ( int * V_44 , int * V_45 )
{
int V_46 = 0 , V_47 = 0 , V_48 = 0 ;
struct V_27 * V_28 ;
unsigned long V_34 ;
int V_35 ;
struct V_32 * V_33 ;
F_12 ( & V_37 , V_34 ) ;
F_13 (dd, &hfi1_dev_list, list) {
V_46 ++ ;
if ( ( V_28 -> V_34 & V_38 ) && V_28 -> V_39 )
V_47 ++ ;
for ( V_35 = 0 ; V_35 < V_28 -> V_40 ; ++ V_35 ) {
V_33 = V_28 -> V_41 + V_35 ;
if ( V_33 -> V_42 && V_33 -> V_43 )
V_48 ++ ;
}
}
F_14 ( & V_37 , V_34 ) ;
if ( V_44 )
* V_44 = V_47 ;
if ( V_45 )
* V_45 = V_48 ;
return V_46 ;
}
static inline void * F_16 ( const struct V_49 * V_50 , T_1 V_51 ,
T_2 * V_52 )
{
T_3 V_53 = F_17 ( V_51 ) , V_54 = F_18 ( V_51 ) ;
* V_52 |= ! ( V_53 & ( V_50 -> V_55 . V_56 - 1 ) ) && ! V_54 ;
return ( void * ) ( ( ( T_1 ) ( V_50 -> V_55 . V_57 [ V_53 ] . V_58 ) ) +
( V_54 * V_59 ) ) ;
}
inline int F_19 ( T_3 V_60 , T_2 type , T_4 * V_61 )
{
if ( F_20 ( ! F_21 ( V_60 ) ) )
return 0 ;
if ( F_20 ( V_60 < V_62 ) )
return 0 ;
if ( V_60 >
( type == V_63 ? V_64 : V_65 ) )
return 0 ;
if ( V_61 )
* V_61 = F_22 ( V_60 / V_19 ) + 1 ;
return 1 ;
}
static void F_23 ( struct V_49 * V_50 , struct V_32 * V_33 ,
struct V_66 * V_67 )
{
struct V_68 * V_69 = V_67 -> V_70 ;
T_3 V_71 = F_24 ( V_67 -> V_51 ) ;
int V_72 = F_25 ( V_69 -> V_73 [ 0 ] ) & 3 ;
struct V_74 * V_75 = & V_33 -> V_76 ;
struct V_27 * V_28 = V_33 -> V_28 ;
struct V_23 * V_24 = & V_28 -> V_29 . V_24 ;
if ( V_67 -> V_51 & ( V_77 | V_78 ) )
return;
if ( V_67 -> V_51 & V_79 ) {
struct V_80 * V_70 = (struct V_80 * ) V_69 ;
struct V_81 * V_82 = NULL ;
T_3 V_83 = F_26 ( V_67 -> V_51 ) ;
T_4 V_42 = F_25 ( V_70 -> V_73 [ 1 ] ) ;
T_3 V_84 ;
T_3 V_85 = 0 ;
if ( V_83 < 24 )
goto V_86;
if ( V_72 == V_87 ) {
V_82 = & V_70 -> V_88 . V_89 ;
} else if ( V_72 == V_90 ) {
T_3 V_91 ;
V_82 = & V_70 -> V_88 . V_92 . V_89 ;
if ( V_70 -> V_88 . V_92 . V_93 . V_94 != V_95 )
goto V_86;
V_91 = F_27 ( V_70 -> V_88 . V_92 . V_93 . V_96 ) ;
if ( ( V_91 >> V_97 ) != V_98 )
goto V_86;
V_85 |= V_99 ;
} else {
goto V_86;
}
V_84 = F_27 ( V_82 -> V_100 [ 1 ] ) & V_101 ;
if ( V_42 < F_25 ( V_102 ) ) {
struct V_103 * V_104 ;
unsigned long V_34 ;
F_28 () ;
V_104 = F_29 ( V_24 , & V_75 -> V_105 , V_84 ) ;
if ( ! V_104 ) {
F_30 () ;
goto V_86;
}
F_12 ( & V_104 -> V_106 , V_34 ) ;
if ( ! ( V_107 [ V_104 -> V_108 ] &
V_109 ) ) {
V_75 -> V_105 . V_110 ++ ;
}
switch ( V_104 -> V_111 . V_112 ) {
case V_113 :
F_31 (
V_50 ,
V_70 ,
V_85 ,
V_104 ) ;
break;
default:
break;
}
F_14 ( & V_104 -> V_106 , V_34 ) ;
F_30 () ;
}
}
switch ( V_71 ) {
case V_114 :
{
T_3 V_115 ;
void * V_116 = NULL ;
T_5 * V_100 = NULL ;
if ( F_32 ( V_67 -> V_51 ) )
V_116 = V_67 -> V_116 ;
if ( ! V_116 )
goto V_86;
if ( V_72 == V_87 )
V_100 = ( T_5 * ) V_116 ;
else if ( V_72 == V_90 )
V_100 = ( T_5 * ) ( ( char * ) V_116 + sizeof( struct V_117 ) ) ;
else
goto V_86;
V_115 = F_27 ( V_100 [ 0 ] ) >> 24 ;
V_115 &= 0xff ;
if ( V_115 == V_118 ) {
struct V_103 * V_104 = NULL ;
T_3 V_119 , V_120 ;
T_4 V_121 ;
T_2 V_122 , V_123 , V_124 ;
V_124 = ( F_25 ( V_69 -> V_73 [ 0 ] ) >> 12 ) & 0xf ;
if ( F_33 ( V_67 -> V_51 ) )
V_124 |= 0x10 ;
V_123 = V_75 -> V_125 [ V_124 ] ;
V_119 = F_27 ( V_100 [ 1 ] ) & V_101 ;
F_28 () ;
V_104 = F_29 ( V_24 , & V_75 -> V_105 , V_119 ) ;
if ( ! V_104 ) {
F_30 () ;
goto V_86;
}
switch ( V_104 -> V_111 . V_112 ) {
case V_126 :
V_121 = 0 ;
V_120 = 0 ;
V_122 = V_127 ;
break;
case V_128 :
V_121 = F_25 ( V_69 -> V_73 [ 3 ] ) ;
V_120 = V_104 -> V_129 ;
V_122 = V_130 ;
break;
default:
goto V_86;
}
F_34 ( V_33 , V_123 , V_121 , V_119 , V_120 , V_122 ) ;
F_30 () ;
}
V_67 -> V_51 &= ~ V_131 ;
break;
}
default:
break;
}
V_86:
return;
}
static inline void F_35 ( struct V_49 * V_50 ,
struct V_66 * V_67 )
{
V_67 -> V_132 = V_50 -> V_133 ;
V_67 -> V_134 = V_50 -> V_135 * V_67 -> V_132 ;
V_67 -> V_50 = V_50 ;
V_67 -> V_136 = 0 ;
V_67 -> V_137 = - 1 ;
V_67 -> V_138 = F_36 ( V_50 ) ;
V_67 -> V_51 = F_37 ( V_67 -> V_138 ) ;
V_67 -> V_139 = V_50 -> V_140 ;
V_67 -> V_141 = 0 ;
V_67 -> V_85 = 0 ;
}
static void F_38 ( struct V_103 * V_104 , struct V_80 * V_70 ,
struct V_81 * V_82 ,
T_1 V_51 , T_3 V_142 , struct V_117 * V_93 )
{
struct V_74 * V_75 = F_39 ( V_104 -> V_111 . V_143 , V_104 -> V_144 ) ;
T_3 V_120 = 0 ;
T_4 V_121 ;
T_2 V_124 , V_122 ;
switch ( V_104 -> V_111 . V_112 ) {
case V_145 :
case V_146 :
case V_126 :
V_121 = F_25 ( V_70 -> V_73 [ 3 ] ) ;
V_120 = F_27 ( V_82 -> V_88 . V_147 . V_148 [ 1 ] ) & V_101 ;
V_122 = V_127 ;
break;
case V_128 :
V_121 = V_104 -> V_149 . V_150 ;
V_120 = V_104 -> V_129 ;
V_122 = V_130 ;
break;
case V_113 :
V_121 = V_104 -> V_149 . V_150 ;
V_120 = V_104 -> V_129 ;
V_122 = V_151 ;
break;
default:
return;
}
V_124 = ( F_25 ( V_70 -> V_73 [ 0 ] ) >> 12 ) & 0xf ;
if ( F_33 ( V_51 ) )
V_124 |= 0x10 ;
if ( V_142 & V_152 ) {
T_4 V_153 = ( T_4 ) F_27 ( V_82 -> V_100 [ 0 ] ) ;
T_4 V_150 = F_25 ( V_70 -> V_73 [ 1 ] ) ;
F_40 ( V_75 , V_104 , V_120 , V_153 , V_150 , V_121 , V_124 , V_93 ) ;
}
if ( V_142 & V_154 ) {
struct V_32 * V_33 = F_41 ( V_75 ) ;
T_3 V_119 = V_142 & V_101 ;
T_2 V_123 = V_75 -> V_125 [ V_124 ] ;
F_34 ( V_33 , V_123 , V_121 , V_119 , V_120 , V_122 ) ;
}
}
static inline void F_42 ( struct V_155 * V_156 ,
struct V_66 * V_67 )
{
struct V_49 * V_50 = V_67 -> V_50 ;
V_156 -> V_50 = V_50 ;
V_156 -> V_132 = V_67 -> V_132 ;
V_156 -> V_134 = V_67 -> V_134 ;
V_156 -> V_157 = V_67 -> V_139 ;
if ( F_43 ( V_50 -> V_34 , V_158 ) ) {
V_156 -> V_159 = F_44 ( V_50 ) ;
if ( V_50 -> V_160 == V_161 )
V_156 -> V_162 = V_50 -> V_163 ;
else
V_156 -> V_162 = 0 ;
} else {
V_156 -> V_159 = 0 ;
V_156 -> V_162 = V_50 -> V_163 ;
}
}
static inline int F_45 ( struct V_155 * V_156 , T_1 V_51 ,
struct V_49 * V_50 )
{
if ( F_43 ( V_50 -> V_34 , V_158 ) )
return V_156 -> V_157 == V_156 -> V_159 ;
return V_156 -> V_162 != F_46 ( V_51 ) ;
}
static inline int F_47 ( struct V_155 * V_156 , T_1 V_51 ,
struct V_49 * V_50 )
{
if ( ( V_50 -> V_160 == V_161 ) && ( V_156 -> V_157 != V_156 -> V_159 ) )
return V_156 -> V_162 != F_46 ( V_51 ) ;
return 0 ;
}
static inline void F_48 ( struct V_155 * V_156 ,
struct V_49 * V_50 )
{
V_156 -> V_157 += V_156 -> V_132 ;
if ( V_156 -> V_157 >= V_156 -> V_134 )
V_156 -> V_157 = 0 ;
if ( ! F_43 ( V_50 -> V_34 , V_158 ) ||
( V_50 -> V_160 == V_161 ) ) {
if ( ++ V_156 -> V_162 > 13 )
V_156 -> V_162 = 1 ;
}
}
static void F_49 ( struct V_66 * V_67 )
{
struct V_49 * V_50 = V_67 -> V_50 ;
struct V_155 V_156 ;
F_42 ( & V_156 , V_67 ) ;
while ( 1 ) {
struct V_27 * V_28 = V_50 -> V_28 ;
struct V_74 * V_75 = & V_50 -> V_33 -> V_76 ;
T_6 * V_138 = ( T_6 * ) V_50 -> V_164 + V_156 . V_157 +
V_28 -> V_165 ;
struct V_103 * V_104 ;
struct V_80 * V_70 ;
struct V_81 * V_82 ;
struct V_117 * V_93 = NULL ;
struct V_23 * V_24 = & V_28 -> V_29 . V_24 ;
T_1 V_51 = F_37 ( V_138 ) ;
T_3 V_166 = F_50 ( V_51 ) , V_167 , V_142 ;
int V_168 = 0 ;
T_2 V_72 ;
if ( F_45 ( & V_156 , V_51 , V_50 ) )
break;
if ( F_47 ( & V_156 , V_51 , V_50 ) )
goto V_169;
if ( V_166 != V_170 )
goto V_169;
V_70 = (struct V_80 * )
F_51 ( V_28 , V_138 ) ;
V_72 = F_25 ( V_70 -> V_73 [ 0 ] ) & 3 ;
if ( V_72 == V_87 ) {
V_82 = & V_70 -> V_88 . V_89 ;
} else if ( V_72 == V_90 ) {
V_82 = & V_70 -> V_88 . V_92 . V_89 ;
V_93 = & V_70 -> V_88 . V_92 . V_93 ;
} else {
goto V_169;
}
V_142 = F_27 ( V_82 -> V_100 [ 1 ] ) ;
V_168 = ! ! ( V_142 & ( V_152 | V_154 ) ) ;
if ( ! V_168 )
goto V_169;
V_167 = V_142 & V_101 ;
F_28 () ;
V_104 = F_29 ( V_24 , & V_75 -> V_105 , V_167 ) ;
if ( ! V_104 ) {
F_30 () ;
goto V_169;
}
F_38 ( V_104 , V_70 , V_82 , V_51 , V_142 , V_93 ) ;
F_30 () ;
V_142 &= ~ ( V_152 | V_154 ) ;
V_82 -> V_100 [ 1 ] = F_52 ( V_142 ) ;
V_169:
F_48 ( & V_156 , V_50 ) ;
}
}
static inline int F_53 ( struct V_66 * V_67 , int V_171 )
{
int V_4 = V_172 ;
V_67 -> V_139 += V_67 -> V_132 ;
if ( V_67 -> V_139 >= V_67 -> V_134 )
V_67 -> V_139 = 0 ;
V_67 -> V_141 ++ ;
if ( F_20 ( ( V_67 -> V_141 & ( V_173 - 1 ) ) == 0 ) ) {
if ( V_171 ) {
F_54 () ;
} else {
V_4 = V_174 ;
F_55 ( * V_67 -> V_50 -> V_28 -> V_175 ) ;
}
}
V_67 -> V_138 = ( T_6 * ) V_67 -> V_50 -> V_164 + V_67 -> V_139 +
V_67 -> V_50 -> V_28 -> V_165 ;
V_67 -> V_51 = F_37 ( V_67 -> V_138 ) ;
return V_4 ;
}
static inline int F_56 ( struct V_66 * V_67 , int V_171 )
{
int V_4 = V_172 ;
V_67 -> V_70 = F_51 ( V_67 -> V_50 -> V_28 ,
V_67 -> V_138 ) ;
V_67 -> V_176 = ( T_2 * ) V_67 -> V_138 - ( T_2 * ) V_67 -> V_70 ;
V_67 -> V_166 = F_50 ( V_67 -> V_51 ) ;
V_67 -> V_83 = F_26 ( V_67 -> V_51 ) ;
V_67 -> V_116 = NULL ;
if ( F_32 ( V_67 -> V_51 ) ) {
V_67 -> V_137 = F_17 ( V_67 -> V_51 ) ;
V_67 -> V_116 = F_16 ( V_67 -> V_50 , V_67 -> V_51 ,
& V_67 -> V_136 ) ;
F_57 ( V_67 -> V_116 ,
V_67 -> V_83 - ( ( V_67 -> V_50 -> V_133 -
( F_58 ( V_67 -> V_51 )
+ 2 ) ) * 4 ) ) ;
}
V_67 -> V_50 -> V_28 -> V_177 [ V_67 -> V_166 ] ( V_67 ) ;
V_67 -> V_141 ++ ;
V_67 -> V_139 += V_67 -> V_132 ;
if ( V_67 -> V_139 >= V_67 -> V_134 )
V_67 -> V_139 = 0 ;
if ( F_20 ( ( V_67 -> V_141 & ( V_173 - 1 ) ) == 0 ) ) {
if ( V_171 ) {
F_54 () ;
} else {
V_4 = V_174 ;
F_55 ( * V_67 -> V_50 -> V_28 -> V_175 ) ;
}
}
V_67 -> V_138 = ( T_6 * ) V_67 -> V_50 -> V_164 + V_67 -> V_139 +
V_67 -> V_50 -> V_28 -> V_165 ;
V_67 -> V_51 = F_37 ( V_67 -> V_138 ) ;
return V_4 ;
}
static inline void F_59 ( int V_178 , struct V_66 * V_67 )
{
if ( ! V_178 && ! ( V_67 -> V_141 & 0xf ) ) {
F_60 ( V_67 -> V_50 , V_67 -> V_139 , V_67 -> V_136 ,
V_67 -> V_137 , 0 , 0 ) ;
V_67 -> V_136 = 0 ;
}
V_67 -> V_85 = 0 ;
}
static inline void F_61 ( struct V_66 * V_67 )
{
F_60 ( V_67 -> V_50 , V_67 -> V_50 -> V_140 , V_67 -> V_136 ,
V_67 -> V_137 , V_179 , V_67 -> V_141 ) ;
}
static inline void F_62 ( struct V_66 * V_67 )
{
struct V_49 * V_50 ;
struct V_103 * V_104 , * V_180 ;
V_50 = V_67 -> V_50 ;
V_50 -> V_140 = V_67 -> V_139 ;
F_63 (qp, nqp, &rcd->qp_wait_list, rspwait) {
F_64 ( & V_104 -> V_181 ) ;
if ( V_104 -> V_182 & V_183 ) {
V_104 -> V_182 &= ~ V_183 ;
F_65 ( V_50 , V_104 , 0 ) ;
}
if ( V_104 -> V_182 & V_184 ) {
unsigned long V_34 ;
V_104 -> V_182 &= ~ V_184 ;
F_12 ( & V_104 -> V_185 , V_34 ) ;
if ( V_107 [ V_104 -> V_108 ] &
V_186 )
F_66 ( V_104 ) ;
F_14 ( & V_104 -> V_185 , V_34 ) ;
}
if ( F_67 ( & V_104 -> V_187 ) )
F_68 ( & V_104 -> V_188 ) ;
}
}
int F_69 ( struct V_49 * V_50 , int V_171 )
{
T_3 V_189 ;
int V_178 = V_172 ;
struct V_66 V_67 ;
F_35 ( V_50 , & V_67 ) ;
V_189 = F_46 ( V_67 . V_51 ) ;
if ( V_189 != V_50 -> V_163 ) {
V_178 = V_190 ;
goto V_191;
}
F_70 ( V_50 , & V_67 ) ;
while ( V_178 == V_172 ) {
V_178 = F_56 ( & V_67 , V_171 ) ;
V_189 = F_46 ( V_67 . V_51 ) ;
if ( ++ V_50 -> V_163 > 13 )
V_50 -> V_163 = 1 ;
if ( V_189 != V_50 -> V_163 )
V_178 = V_190 ;
F_59 ( V_178 , & V_67 ) ;
}
F_62 ( & V_67 ) ;
V_191:
F_61 ( & V_67 ) ;
return V_178 ;
}
int F_71 ( struct V_49 * V_50 , int V_171 )
{
T_3 V_192 ;
int V_178 = V_172 ;
struct V_66 V_67 ;
F_35 ( V_50 , & V_67 ) ;
V_192 = F_44 ( V_50 ) ;
if ( V_67 . V_139 == V_192 ) {
V_178 = V_190 ;
goto V_191;
}
F_72 () ;
F_70 ( V_50 , & V_67 ) ;
while ( V_178 == V_172 ) {
V_178 = F_56 ( & V_67 , V_171 ) ;
if ( V_67 . V_139 == V_192 )
V_178 = V_190 ;
F_59 ( V_178 , & V_67 ) ;
}
F_62 ( & V_67 ) ;
V_191:
F_61 ( & V_67 ) ;
return V_178 ;
}
static inline void F_73 ( struct V_27 * V_28 )
{
int V_193 ;
for ( V_193 = V_161 + 1 ; V_193 < V_28 -> V_194 ; V_193 ++ )
V_28 -> V_50 [ V_193 ] -> V_195 =
& F_69 ;
}
static inline void F_74 ( struct V_27 * V_28 )
{
int V_193 ;
for ( V_193 = V_161 + 1 ; V_193 < V_28 -> V_194 ; V_193 ++ )
V_28 -> V_50 [ V_193 ] -> V_195 =
& F_71 ;
}
void F_75 ( struct V_27 * V_28 )
{
int V_193 ;
for ( V_193 = V_161 + 1 ; V_193 < V_28 -> V_194 ; V_193 ++ )
V_28 -> V_50 [ V_193 ] -> V_195 = & V_196 ;
}
static inline int F_76 ( struct V_49 * V_50 ,
struct V_66 V_67 ,
struct V_27 * V_28 )
{
struct V_197 * V_198 = & V_50 -> V_33 -> V_199 ;
struct V_68 * V_70 = F_51 ( V_67 . V_50 -> V_28 ,
V_67 . V_138 ) ;
if ( F_77 ( V_70 , V_67 . V_51 ) != 0xf ) {
int V_200 = F_78 ( V_28 ) ;
if ( V_200 != V_201 ) {
F_79 ( V_28 , L_5 , V_200 ) ;
return 0 ;
}
F_80 ( V_50 -> V_33 -> V_202 , V_198 ) ;
return 1 ;
}
return 0 ;
}
int V_196 ( struct V_49 * V_50 , int V_171 )
{
struct V_27 * V_28 = V_50 -> V_28 ;
T_3 V_192 ;
int V_203 , V_178 = V_172 ;
struct V_66 V_67 ;
int V_204 = 0 ;
V_203 = ( V_50 -> V_160 == V_161 ) ? 0 : 1 ;
F_35 ( V_50 , & V_67 ) ;
if ( ! F_43 ( V_50 -> V_34 , V_158 ) ) {
T_3 V_189 = F_46 ( V_67 . V_51 ) ;
if ( V_189 != V_50 -> V_163 ) {
V_178 = V_190 ;
goto V_191;
}
V_192 = 0 ;
} else {
V_192 = F_44 ( V_50 ) ;
if ( V_67 . V_139 == V_192 ) {
V_178 = V_190 ;
goto V_191;
}
F_72 () ;
if ( V_50 -> V_160 == V_161 ) {
T_3 V_189 = F_46 ( V_67 . V_51 ) ;
if ( V_189 != V_50 -> V_163 )
V_204 = 1 ;
}
}
F_70 ( V_50 , & V_67 ) ;
while ( V_178 == V_172 ) {
if ( F_20 ( V_28 -> V_205 &&
F_81 ( & V_28 -> V_206 , V_207 ) ==
V_208 ) ) {
V_28 -> V_205 = 0 ;
V_67 . V_139 += V_67 . V_132 ;
V_67 . V_138 = ( T_6 * ) V_50 -> V_164 +
V_67 . V_139 +
V_28 -> V_165 ;
V_67 . V_51 = F_37 ( V_67 . V_138 ) ;
} else if ( V_204 ) {
V_178 = F_53 ( & V_67 , V_171 ) ;
V_204 = 0 ;
} else {
if ( F_20 ( V_50 -> V_33 -> V_209 ==
V_210 ) &&
F_76 ( V_50 , V_67 , V_28 ) )
goto V_191;
V_178 = F_56 ( & V_67 , V_171 ) ;
}
if ( ! F_43 ( V_50 -> V_34 , V_158 ) ) {
T_3 V_189 = F_46 ( V_67 . V_51 ) ;
if ( ++ V_50 -> V_163 > 13 )
V_50 -> V_163 = 1 ;
if ( V_189 != V_50 -> V_163 )
V_178 = V_190 ;
if ( V_203 ) {
F_79 ( V_28 , L_6 ) ;
F_73 ( V_28 ) ;
V_203 = 0 ;
}
} else {
if ( V_67 . V_139 == V_192 )
V_178 = V_190 ;
if ( V_50 -> V_160 == V_161 ) {
T_3 V_189 = F_46 ( V_67 . V_51 ) ;
if ( ++ V_50 -> V_163 > 13 )
V_50 -> V_163 = 1 ;
if ( ! V_178 && ( V_189 != V_50 -> V_163 ) )
V_204 = 1 ;
}
if ( V_203 ) {
F_79 ( V_28 ,
L_7 ) ;
F_74 ( V_28 ) ;
V_203 = 0 ;
}
}
F_59 ( V_178 , & V_67 ) ;
}
F_62 ( & V_67 ) ;
V_191:
F_61 ( & V_67 ) ;
return V_178 ;
}
void F_82 ( struct V_197 * V_211 )
{
struct V_32 * V_33 = F_9 ( V_211 , struct V_32 ,
V_199 ) ;
struct V_27 * V_28 = V_33 -> V_28 ;
int V_193 ;
V_33 -> V_212 = 1 ;
F_83 ( V_33 , V_213 ) ;
for ( V_193 = V_161 ; V_193 < V_28 -> V_194 ; V_193 ++ )
F_84 ( V_28 -> V_50 [ V_193 ] ) ;
}
int F_85 ( T_3 V_214 , int V_215 )
{
switch ( V_214 ) {
case 0 : return V_216 ;
case 256 : return V_217 ;
case 512 : return V_218 ;
case 1024 : return V_219 ;
case 2048 : return V_220 ;
case 4096 : return V_221 ;
case 8192 : return V_222 ;
case 10240 : return V_223 ;
}
return V_215 ;
}
T_4 F_86 ( int V_214 )
{
switch ( V_214 ) {
case V_216 : return 0 ;
case V_217 : return 256 ;
case V_218 : return 512 ;
case V_219 : return 1024 ;
case V_220 : return 2048 ;
case V_221 : return 4096 ;
case V_222 : return 8192 ;
case V_223 : return 10240 ;
default: return 0xffff ;
}
}
int F_87 ( struct V_32 * V_33 )
{
struct V_27 * V_28 = V_33 -> V_28 ;
int V_193 , V_224 , V_4 = 0 , V_225 = 0 ;
V_33 -> V_226 = 0 ;
for ( V_193 = 0 ; V_193 < V_33 -> V_227 ; V_193 ++ )
if ( V_33 -> V_226 < V_28 -> V_228 [ V_193 ] . V_214 )
V_33 -> V_226 = V_28 -> V_228 [ V_193 ] . V_214 ;
V_33 -> V_229 = V_33 -> V_226 + F_88 ( V_33 -> V_28 ) ;
F_89 ( & V_33 -> V_230 ) ;
if ( V_33 -> V_209 == V_231 ||
V_33 -> V_209 == V_210 ||
V_33 -> V_209 == V_213 )
V_225 = 1 ;
V_224 = ! F_90 ( V_28 ) && V_225 ;
if ( V_224 )
V_4 = F_91 ( V_28 ) ;
if ( V_4 ) {
F_92 ( V_28 , L_8 ,
V_232 ) ;
goto V_233;
}
F_93 ( V_33 , V_234 , 0 ) ;
if ( V_224 )
F_94 ( V_28 ) ;
V_233:
F_95 ( & V_33 -> V_230 ) ;
return V_4 ;
}
int F_96 ( struct V_32 * V_33 , T_3 V_42 , T_2 V_235 )
{
struct V_27 * V_28 = V_33 -> V_28 ;
V_33 -> V_42 = V_42 ;
V_33 -> V_235 = V_235 ;
F_93 ( V_33 , V_236 , 0 ) ;
F_79 ( V_28 , L_9 , V_33 -> V_237 , V_42 ) ;
return 0 ;
}
void F_97 ( struct V_32 * V_33 )
{
struct V_27 * V_28 = V_33 -> V_28 ;
F_72 () ;
if ( F_98 ( & V_33 -> V_238 ) ) {
F_99 ( & V_33 -> V_239 ) ;
F_100 ( & V_33 -> V_238 , 0 ) ;
F_101 () ;
}
F_102 ( V_28 , V_240 , 0 ) ;
}
static void F_103 ( unsigned long V_241 )
{
struct V_32 * V_33 = (struct V_32 * ) V_241 ;
struct V_27 * V_28 = V_33 -> V_28 ;
unsigned long V_242 ;
int V_243 ;
if ( ! ( V_28 -> V_34 & V_244 ) )
return;
V_243 = V_33 -> V_245 & 1 ;
F_104 ( V_28 , V_243 ) ;
V_242 = V_33 -> V_246 [ V_243 ] ;
V_33 -> V_245 = ! V_33 -> V_245 ;
F_105 ( & V_33 -> V_239 , V_247 + V_242 ) ;
}
void F_106 ( struct V_32 * V_33 , unsigned int V_248 ,
unsigned int V_249 )
{
if ( ! ( V_33 -> V_28 -> V_34 & V_244 ) )
return;
V_33 -> V_246 [ 0 ] = F_107 ( V_249 ) ;
V_33 -> V_246 [ 1 ] = F_107 ( V_248 ) ;
V_33 -> V_245 = 1 ;
if ( ! F_108 ( & V_33 -> V_239 ) ) {
F_109 ( & V_33 -> V_239 , F_103 ,
( unsigned long ) V_33 ) ;
V_33 -> V_239 . V_250 = V_247 + 1 ;
F_110 ( & V_33 -> V_239 ) ;
F_100 ( & V_33 -> V_238 , 1 ) ;
F_101 () ;
}
}
int F_111 ( int V_20 )
{
int V_4 , V_193 ;
struct V_27 * V_28 = F_112 ( V_20 ) ;
struct V_32 * V_33 ;
unsigned long V_34 ;
int V_35 ;
if ( ! V_28 ) {
V_4 = - V_251 ;
goto V_191;
}
F_79 ( V_28 , L_10 , V_20 ) ;
if ( ! V_28 -> V_39 || ! ( V_28 -> V_34 & V_38 ) ) {
F_79 ( V_28 ,
L_11 ,
V_20 ) ;
V_4 = - V_252 ;
goto V_191;
}
F_12 ( & V_28 -> V_253 , V_34 ) ;
if ( V_28 -> V_50 )
for ( V_193 = V_28 -> V_194 ; V_193 < V_28 -> V_254 ; V_193 ++ ) {
if ( ! V_28 -> V_50 [ V_193 ] || ! V_28 -> V_50 [ V_193 ] -> V_255 )
continue;
F_14 ( & V_28 -> V_253 , V_34 ) ;
V_4 = - V_256 ;
goto V_191;
}
F_14 ( & V_28 -> V_253 , V_34 ) ;
for ( V_35 = 0 ; V_35 < V_28 -> V_40 ; ++ V_35 ) {
V_33 = V_28 -> V_41 + V_35 ;
F_97 ( V_33 ) ;
}
if ( V_28 -> V_34 & V_257 )
F_113 ( V_28 ) ;
F_114 ( V_28 ) ;
V_4 = F_115 ( V_28 , 1 ) ;
if ( V_4 )
F_92 ( V_28 ,
L_12 ,
V_20 , V_4 ) ;
else
F_79 ( V_28 , L_13 ,
V_20 ) ;
V_191:
return V_4 ;
}
void F_116 ( struct V_66 * V_67 )
{
struct V_49 * V_50 = V_67 -> V_50 ;
T_3 V_71 = F_24 ( V_67 -> V_51 ) ;
F_23 ( V_50 , V_50 -> V_33 , V_67 ) ;
if ( F_117 ( V_67 -> V_51 ) )
F_92 ( V_50 -> V_28 ,
L_14 ,
V_50 -> V_160 , V_67 -> V_51 ,
V_67 -> V_51 & V_258 ? L_15 : L_16 ,
V_67 -> V_51 & V_259 ? L_17 : L_16 ,
V_67 -> V_51 & V_260 ? L_18 : L_16 ,
V_67 -> V_51 & V_79 ? L_19 : L_16 ,
V_67 -> V_51 & V_261 ? L_20 : L_16 ,
V_67 -> V_51 & V_262 ? L_21 : L_16 ,
V_67 -> V_51 & V_77 ? L_22 : L_16 ,
V_67 -> V_51 & V_78 ? L_23 : L_16 ,
V_71 ) ;
}
int F_118 ( struct V_66 * V_67 )
{
F_119 ( V_67 -> V_50 -> V_33 -> V_28 ,
V_67 -> V_50 -> V_160 ,
F_117 ( V_67 -> V_51 ) ,
V_170 ,
V_67 -> V_176 ,
V_67 -> V_83 ,
V_67 -> V_136 ,
F_17 ( V_67 -> V_51 ) ) ;
if ( F_20 ( F_117 ( V_67 -> V_51 ) ) ) {
F_116 ( V_67 ) ;
return V_263 ;
}
F_120 ( V_67 ) ;
return V_263 ;
}
int F_121 ( struct V_66 * V_67 )
{
if ( F_20 ( F_117 ( V_67 -> V_51 ) ) )
F_116 ( V_67 ) ;
F_92 ( V_67 -> V_50 -> V_28 ,
L_24 ) ;
return V_263 ;
}
int F_122 ( struct V_66 * V_67 )
{
F_116 ( V_67 ) ;
if ( F_20 ( F_117 ( V_67 -> V_51 ) ) )
F_92 ( V_67 -> V_50 -> V_28 ,
L_25 ) ;
return V_263 ;
}
int F_123 ( struct V_66 * V_67 )
{
if ( F_20 ( F_117 ( V_67 -> V_51 ) ) )
F_116 ( V_67 ) ;
F_92 ( V_67 -> V_50 -> V_28 ,
L_26 ) ;
return V_263 ;
}
int F_124 ( struct V_66 * V_67 )
{
if ( F_20 ( F_117 ( V_67 -> V_51 ) ) )
F_116 ( V_67 ) ;
F_92 ( V_67 -> V_50 -> V_28 ,
L_27 ) ;
return V_263 ;
}
int F_125 ( struct V_66 * V_67 )
{
F_92 ( V_67 -> V_50 -> V_28 , L_28 ,
F_50 ( V_67 -> V_51 ) ) ;
return V_263 ;
}
