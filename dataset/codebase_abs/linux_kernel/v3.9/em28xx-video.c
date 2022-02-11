static inline void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( L_1 , V_4 , V_4 -> V_5 ) ;
V_4 -> V_6 . V_7 . V_8 = V_2 -> V_9 ++ ;
V_4 -> V_6 . V_7 . V_10 = V_11 ;
F_3 ( & V_4 -> V_6 . V_7 . V_12 ) ;
F_4 ( & V_4 -> V_6 , V_13 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned char * V_14 ,
unsigned long V_15 )
{
void * V_16 , * V_17 , * V_18 ;
int V_19 , V_20 , V_21 , V_22 , V_23 ;
int V_24 = V_2 -> V_25 << 1 ;
if ( V_4 -> V_26 + V_15 > V_4 -> V_27 )
V_15 = V_4 -> V_27 - V_4 -> V_26 ;
V_18 = V_14 ;
V_23 = V_15 ;
if ( V_2 -> V_28 || V_4 -> V_5 )
V_16 = V_4 -> V_29 ;
else
V_16 = V_4 -> V_29 + V_24 ;
V_19 = V_4 -> V_26 / V_24 ;
V_20 = V_4 -> V_26 % V_24 ;
if ( V_2 -> V_28 )
V_21 = V_19 * V_24 + V_20 ;
else
V_21 = V_19 * V_24 * 2 + V_20 ;
V_17 = V_16 + V_21 ;
V_22 = V_24 - V_20 ;
V_22 = V_22 > V_23 ? V_23 : V_22 ;
if ( ( char * ) V_17 + V_22 > ( char * ) V_4 -> V_29 + V_4 -> V_27 ) {
F_2 ( L_2 ,
( ( char * ) V_17 + V_22 ) -
( ( char * ) V_4 -> V_29 + V_4 -> V_27 ) ) ;
V_23 = ( char * ) V_4 -> V_29 + V_4 -> V_27 -
( char * ) V_17 ;
V_22 = V_23 ;
}
if ( V_22 <= 0 )
return;
memcpy ( V_17 , V_18 , V_22 ) ;
V_23 -= V_22 ;
while ( V_23 > 0 ) {
if ( V_2 -> V_28 )
V_17 += V_22 ;
else
V_17 += V_22 + V_24 ;
V_18 += V_22 ;
if ( V_24 > V_23 )
V_22 = V_23 ;
else
V_22 = V_24 ;
if ( ( char * ) V_17 + V_22 > ( char * ) V_4 -> V_29 +
V_4 -> V_27 ) {
F_2 ( L_3
L_4 ,
( ( char * ) V_17 + V_22 ) -
( ( char * ) V_4 -> V_29 + V_4 -> V_27 ) ) ;
V_22 = V_23 = ( char * ) V_4 -> V_29 + V_4 -> V_27 -
( char * ) V_17 ;
}
if ( V_22 <= 0 )
break;
memcpy ( V_17 , V_18 , V_22 ) ;
V_23 -= V_22 ;
}
V_4 -> V_26 += V_15 ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned char * V_14 ,
unsigned long V_15 )
{
unsigned int V_21 ;
if ( V_4 -> V_26 + V_15 > V_4 -> V_27 )
V_15 = V_4 -> V_27 - V_4 -> V_26 ;
V_21 = V_4 -> V_26 ;
if ( V_4 -> V_5 == 0 )
V_21 += V_2 -> V_30 * V_2 -> V_31 ;
memcpy ( V_4 -> V_29 + V_21 , V_14 , V_15 ) ;
V_4 -> V_26 += V_15 ;
}
static inline void F_7 ( struct V_1 * V_2 ,
int V_32 , int V_33 )
{
char * V_34 = L_5 ;
switch ( V_33 ) {
case - V_35 :
V_34 = L_6 ;
break;
case - V_36 :
V_34 = L_7 ;
break;
case - V_37 :
V_34 = L_8 ;
break;
case - V_38 :
V_34 = L_9 ;
break;
case - V_39 :
V_34 = L_10 ;
break;
case - V_40 :
V_34 = L_11 ;
break;
case - V_41 :
V_34 = L_12 ;
break;
case - V_42 :
V_34 = L_13 ;
break;
}
if ( V_32 < 0 ) {
F_2 ( L_14 , V_33 , V_34 ) ;
} else {
F_2 ( L_15 ,
V_32 , V_33 , V_34 ) ;
}
}
static inline struct V_3 * F_8 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
struct V_3 * V_4 ;
if ( F_9 ( & V_44 -> V_45 ) ) {
F_2 ( L_16 ) ;
return NULL ;
}
V_4 = F_10 ( V_44 -> V_45 . V_46 , struct V_3 , V_47 ) ;
F_11 ( & V_4 -> V_47 ) ;
V_4 -> V_26 = 0 ;
V_4 -> V_29 = V_4 -> V_48 ;
return V_4 ;
}
static struct V_3 *
F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_43 * V_44 )
{
if ( V_2 -> V_28 || V_2 -> V_5 ) {
if ( V_4 != NULL )
F_1 ( V_2 , V_4 ) ;
V_4 = F_8 ( V_2 , V_44 ) ;
}
if ( V_4 != NULL ) {
V_4 -> V_5 = V_2 -> V_5 ;
V_4 -> V_26 = 0 ;
}
return V_4 ;
}
static inline void F_13 ( struct V_1 * V_2 ,
unsigned char * V_49 ,
unsigned int V_50 )
{
struct V_3 * V_4 = V_2 -> V_51 . V_52 ;
struct V_3 * V_53 = V_2 -> V_51 . V_53 ;
struct V_43 * V_44 = & V_2 -> V_54 ;
struct V_43 * V_55 = & V_2 -> V_56 ;
if ( V_50 >= 4 ) {
if ( V_49 [ 0 ] == 0x88 && V_49 [ 1 ] == 0x88 &&
V_49 [ 2 ] == 0x88 && V_49 [ 3 ] == 0x88 ) {
V_49 += 4 ;
V_50 -= 4 ;
} else if ( V_49 [ 0 ] == 0x33 && V_49 [ 1 ] == 0x95 ) {
V_2 -> V_57 = 0 ;
V_2 -> V_58 = 0 ;
F_2 ( L_17 ) ;
V_2 -> V_5 = ! ( V_49 [ 2 ] & 1 ) ;
V_49 += 4 ;
V_50 -= 4 ;
} else if ( V_49 [ 0 ] == 0x22 && V_49 [ 1 ] == 0x5a ) {
V_2 -> V_57 = 2 ;
F_2 ( L_18 ) ;
V_2 -> V_5 = ! ( V_49 [ 2 ] & 1 ) ;
V_49 += 4 ;
V_50 -= 4 ;
}
}
if ( V_2 -> V_57 == 0 ) {
V_53 = F_12 ( V_2 , V_53 , V_55 ) ;
V_2 -> V_51 . V_53 = V_53 ;
V_2 -> V_57 = 1 ;
}
if ( V_2 -> V_57 == 1 ) {
int V_59 = V_2 -> V_30 * V_2 -> V_31 ;
int V_60 = ( ( V_2 -> V_58 + V_50 ) > V_59 ) ?
( V_59 - V_2 -> V_58 ) : V_50 ;
if ( V_53 != NULL )
F_6 ( V_2 , V_53 , V_49 , V_60 ) ;
V_2 -> V_58 += V_60 ;
if ( V_60 < V_50 ) {
V_2 -> V_57 = 2 ;
V_49 += V_60 ;
V_50 -= V_60 ;
}
}
if ( V_2 -> V_57 == 2 ) {
V_4 = F_12 ( V_2 , V_4 , V_44 ) ;
V_2 -> V_51 . V_52 = V_4 ;
V_2 -> V_57 = 3 ;
}
if ( V_2 -> V_57 == 3 && V_4 != NULL && V_50 > 0 )
F_5 ( V_2 , V_4 , V_49 , V_50 ) ;
}
static inline int F_14 ( struct V_1 * V_2 , struct V_61 * V_61 )
{
int V_62 , V_63 , V_64 ;
unsigned char * V_65 ;
unsigned int V_66 ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_67 )
return 0 ;
if ( V_61 -> V_33 < 0 )
F_7 ( V_2 , - 1 , V_61 -> V_33 ) ;
V_62 = F_15 ( V_61 -> V_68 ) ;
if ( V_62 )
V_63 = 1 ;
else
V_63 = V_61 -> V_69 ;
for ( V_64 = 0 ; V_64 < V_63 ; V_64 ++ ) {
if ( V_62 ) {
V_66 = V_61 -> V_70 ;
V_65 = V_61 -> V_71 ;
} else {
if ( V_61 -> V_72 [ V_64 ] . V_33 < 0 ) {
F_7 ( V_2 , V_64 ,
V_61 -> V_72 [ V_64 ] . V_33 ) ;
if ( V_61 -> V_72 [ V_64 ] . V_33 != - V_40 )
continue;
}
V_66 = V_61 -> V_72 [ V_64 ] . V_70 ;
if ( V_66 > V_2 -> V_73 ) {
F_2 ( L_19 ) ;
continue;
}
V_65 = V_61 -> V_71 +
V_61 -> V_72 [ V_64 ] . V_21 ;
}
if ( V_66 == 0 ) {
continue;
}
F_13 ( V_2 , V_65 , V_66 ) ;
}
return 1 ;
}
static int F_16 ( enum V_74 V_75 )
{
switch ( V_75 ) {
case V_76 :
return V_77 ;
case V_78 :
return V_79 ;
default:
F_17 () ;
return 0 ;
}
}
static int F_18 ( struct V_1 * V_2 , enum V_74 V_75 )
{
int V_80 = F_16 ( V_75 ) ;
if ( V_2 -> V_81 & V_80 ) {
return - V_82 ;
}
V_2 -> V_81 |= V_80 ;
F_19 ( L_20 , V_80 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 , enum V_74 V_75 )
{
int V_80 = F_16 ( V_75 ) ;
V_2 -> V_81 &= ~ V_80 ;
F_19 ( L_21 , V_80 ) ;
}
static int F_21 ( struct V_83 * V_84 , const struct V_85 * V_86 ,
unsigned int * V_87 , unsigned int * V_88 ,
unsigned int V_89 [] , void * V_90 [] )
{
struct V_1 * V_2 = F_22 ( V_84 ) ;
unsigned long V_91 ;
if ( V_86 )
V_91 = V_86 -> V_86 . V_92 . V_93 ;
else
V_91 = ( V_2 -> V_25 * V_2 -> V_94 * V_2 -> V_95 -> V_96 + 7 ) >> 3 ;
if ( V_91 == 0 )
return - V_97 ;
if ( 0 == * V_87 )
* V_87 = 32 ;
* V_88 = 1 ;
V_89 [ 0 ] = V_91 ;
return 0 ;
}
static int
F_23 ( struct V_98 * V_6 )
{
struct V_1 * V_2 = F_22 ( V_6 -> V_83 ) ;
struct V_3 * V_4 = F_24 ( V_6 , struct V_3 , V_6 ) ;
unsigned long V_91 ;
F_19 ( L_22 , V_99 , V_6 -> V_7 . V_10 ) ;
V_91 = ( V_2 -> V_25 * V_2 -> V_94 * V_2 -> V_95 -> V_96 + 7 ) >> 3 ;
if ( F_25 ( V_6 , 0 ) < V_91 ) {
F_19 ( L_23 ,
V_99 , F_25 ( V_6 , 0 ) , V_91 ) ;
return - V_97 ;
}
F_26 ( & V_4 -> V_6 , 0 , V_91 ) ;
return 0 ;
}
int F_27 ( struct V_83 * V_84 , unsigned int V_100 )
{
struct V_1 * V_2 = F_22 ( V_84 ) ;
struct V_101 V_102 ;
int V_103 = 0 ;
F_19 ( L_24 , V_99 ) ;
V_103 = F_18 ( V_2 , V_84 -> type ) ;
if ( V_103 )
return V_103 ;
if ( V_2 -> V_104 ++ == 0 ) {
F_28 ( V_2 ) ;
F_29 ( V_2 ) ;
V_2 -> V_57 = - 1 ;
V_103 = F_30 ( V_2 , V_105 ,
V_2 -> V_106 ,
V_107 ,
V_2 -> V_73 ,
V_2 -> V_108 ,
F_14 ) ;
if ( V_103 < 0 )
goto V_109;
memset ( & V_102 , 0 , sizeof( V_102 ) ) ;
V_102 . V_110 = V_2 -> V_111 ;
if ( V_84 -> V_112 && V_84 -> V_112 -> V_113 -> V_114 == V_115 )
V_102 . type = V_116 ;
else
V_102 . type = V_117 ;
F_31 ( & V_2 -> V_118 , 0 , V_119 , V_120 , & V_102 ) ;
}
V_109:
return V_103 ;
}
static int F_32 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_22 ( V_84 ) ;
struct V_43 * V_54 = & V_2 -> V_54 ;
unsigned long V_121 = 0 ;
F_19 ( L_24 , V_99 ) ;
F_20 ( V_2 , V_84 -> type ) ;
if ( V_2 -> V_104 -- == 1 ) {
F_33 ( V_2 , V_105 ) ;
}
F_34 ( & V_2 -> V_122 , V_121 ) ;
while ( ! F_9 ( & V_54 -> V_45 ) ) {
struct V_3 * V_4 ;
V_4 = F_10 ( V_54 -> V_45 . V_46 , struct V_3 , V_47 ) ;
F_11 ( & V_4 -> V_47 ) ;
F_4 ( & V_4 -> V_6 , V_123 ) ;
}
V_2 -> V_51 . V_52 = NULL ;
F_35 ( & V_2 -> V_122 , V_121 ) ;
return 0 ;
}
int F_36 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_22 ( V_84 ) ;
struct V_43 * V_56 = & V_2 -> V_56 ;
unsigned long V_121 = 0 ;
F_19 ( L_24 , V_99 ) ;
F_20 ( V_2 , V_84 -> type ) ;
if ( V_2 -> V_104 -- == 1 ) {
F_33 ( V_2 , V_105 ) ;
}
F_34 ( & V_2 -> V_122 , V_121 ) ;
while ( ! F_9 ( & V_56 -> V_45 ) ) {
struct V_3 * V_4 ;
V_4 = F_10 ( V_56 -> V_45 . V_46 , struct V_3 , V_47 ) ;
F_11 ( & V_4 -> V_47 ) ;
F_4 ( & V_4 -> V_6 , V_123 ) ;
}
V_2 -> V_51 . V_53 = NULL ;
F_35 ( & V_2 -> V_122 , V_121 ) ;
return 0 ;
}
static void
F_37 ( struct V_98 * V_6 )
{
struct V_1 * V_2 = F_22 ( V_6 -> V_83 ) ;
struct V_3 * V_4 = F_24 ( V_6 , struct V_3 , V_6 ) ;
struct V_43 * V_54 = & V_2 -> V_54 ;
unsigned long V_121 = 0 ;
F_19 ( L_24 , V_99 ) ;
V_4 -> V_48 = F_38 ( V_6 , 0 ) ;
V_4 -> V_27 = F_25 ( V_6 , 0 ) ;
F_34 ( & V_2 -> V_122 , V_121 ) ;
F_39 ( & V_4 -> V_47 , & V_54 -> V_45 ) ;
F_35 ( & V_2 -> V_122 , V_121 ) ;
}
int F_40 ( struct V_1 * V_2 )
{
int V_103 ;
struct V_83 * V_124 ;
V_124 = & V_2 -> V_125 ;
V_124 -> type = V_76 ;
V_124 -> V_126 = V_127 | V_128 | V_129 | V_130 ;
V_124 -> V_131 = V_2 ;
V_124 -> V_132 = sizeof( struct V_3 ) ;
V_124 -> V_133 = & V_134 ;
V_124 -> V_135 = & V_136 ;
V_103 = F_41 ( V_124 ) ;
if ( V_103 < 0 )
return V_103 ;
V_124 = & V_2 -> V_137 ;
V_124 -> type = V_78 ;
V_124 -> V_126 = V_127 | V_128 | V_129 ;
V_124 -> V_131 = V_2 ;
V_124 -> V_132 = sizeof( struct V_3 ) ;
V_124 -> V_133 = & V_138 ;
V_124 -> V_135 = & V_136 ;
V_103 = F_41 ( V_124 ) ;
if ( V_103 < 0 )
return V_103 ;
return 0 ;
}
static void F_42 ( struct V_1 * V_2 , int V_139 )
{
V_2 -> V_140 = V_139 ;
V_2 -> V_141 = F_43 ( V_139 ) -> V_142 ;
V_2 -> V_143 = F_43 ( V_139 ) -> V_144 ;
if ( ! V_2 -> V_143 )
V_2 -> V_143 = V_145 ;
F_31 ( & V_2 -> V_118 , 0 , V_146 , V_147 ,
F_43 ( V_139 ) -> V_148 , 0 , 0 ) ;
if ( V_2 -> V_149 . V_150 ) {
if ( V_2 -> V_151 ) {
F_31 ( & V_2 -> V_118 , 0 , V_152 ,
V_153 , V_2 -> V_151 ) ;
}
F_31 ( & V_2 -> V_118 , 0 , V_152 , V_147 ,
V_2 -> V_141 , F_44 ( V_154 ) , 0 ) ;
}
if ( V_2 -> V_149 . V_155 != V_156 ) {
F_31 ( & V_2 -> V_118 , 0 , V_152 , V_147 ,
V_2 -> V_141 , V_2 -> V_143 , 0 ) ;
}
F_45 ( V_2 ) ;
}
void F_46 ( struct V_157 * V_158 , void * V_159 )
{
struct V_1 * V_2 = V_159 ;
switch ( V_158 -> V_160 ) {
case V_161 :
V_2 -> V_162 = V_158 -> V_163 ;
F_45 ( V_2 ) ;
break;
case V_164 :
V_2 -> V_165 = V_158 -> V_163 ;
F_45 ( V_2 ) ;
break;
}
}
static int F_47 ( struct V_157 * V_158 )
{
struct V_1 * V_2 = F_24 ( V_158 -> V_166 , struct V_1 , V_167 ) ;
switch ( V_158 -> V_160 ) {
case V_161 :
V_2 -> V_162 = V_158 -> V_163 ;
break;
case V_164 :
V_2 -> V_165 = V_158 -> V_163 ;
break;
}
return F_45 ( V_2 ) ;
}
static int F_48 ( struct V_1 * V_2 )
{
if ( V_2 -> V_67 ) {
F_49 ( L_25 ) ;
return - V_168 ;
}
return 0 ;
}
static void F_50 ( struct V_1 * V_2 ,
unsigned int V_25 , unsigned int V_94 ,
unsigned int * V_169 , unsigned int * V_170 )
{
unsigned int V_171 = F_51 ( V_2 ) ;
unsigned int V_172 = F_52 ( V_2 ) ;
* V_169 = ( ( ( unsigned long ) V_171 ) << 12 ) / V_25 - 4096L ;
if ( * V_169 >= 0x4000 )
* V_169 = 0x3fff ;
* V_170 = ( ( ( unsigned long ) V_172 ) << 12 ) / V_94 - 4096L ;
if ( * V_170 >= 0x4000 )
* V_170 = 0x3fff ;
}
static int F_53 ( struct V_173 * V_173 , void * V_159 ,
struct V_85 * V_102 )
{
struct V_174 * V_175 = V_159 ;
struct V_1 * V_2 = V_175 -> V_2 ;
V_102 -> V_86 . V_92 . V_25 = V_2 -> V_25 ;
V_102 -> V_86 . V_92 . V_94 = V_2 -> V_94 ;
V_102 -> V_86 . V_92 . V_176 = V_2 -> V_95 -> V_177 ;
V_102 -> V_86 . V_92 . V_24 = ( V_2 -> V_25 * V_2 -> V_95 -> V_96 + 7 ) >> 3 ;
V_102 -> V_86 . V_92 . V_93 = V_102 -> V_86 . V_92 . V_24 * V_2 -> V_94 ;
V_102 -> V_86 . V_92 . V_178 = V_179 ;
if ( V_2 -> V_28 )
V_102 -> V_86 . V_92 . V_10 = V_180 ;
else
V_102 -> V_86 . V_92 . V_10 = V_2 -> V_181 ?
V_11 : V_182 ;
return 0 ;
}
static struct V_183 * F_54 ( unsigned int V_177 )
{
unsigned int V_64 ;
for ( V_64 = 0 ; V_64 < F_55 ( V_95 ) ; V_64 ++ )
if ( V_95 [ V_64 ] . V_177 == V_177 )
return & V_95 [ V_64 ] ;
return NULL ;
}
static int F_56 ( struct V_173 * V_173 , void * V_159 ,
struct V_85 * V_102 )
{
struct V_174 * V_175 = V_159 ;
struct V_1 * V_2 = V_175 -> V_2 ;
unsigned int V_25 = V_102 -> V_86 . V_92 . V_25 ;
unsigned int V_94 = V_102 -> V_86 . V_92 . V_94 ;
unsigned int V_171 = F_51 ( V_2 ) ;
unsigned int V_172 = F_52 ( V_2 ) ;
unsigned int V_169 , V_170 ;
struct V_183 * V_86 ;
V_86 = F_54 ( V_102 -> V_86 . V_92 . V_176 ) ;
if ( ! V_86 ) {
F_19 ( L_26 ,
V_102 -> V_86 . V_92 . V_176 ) ;
return - V_97 ;
}
if ( V_2 -> V_149 . V_184 ) {
V_94 = V_94 > ( 3 * V_172 / 4 ) ? V_172 : V_172 / 2 ;
V_25 = V_25 > ( 3 * V_171 / 4 ) ? V_171 : V_171 / 2 ;
if ( V_25 == V_171 && V_94 == V_172 )
V_25 /= 2 ;
} else {
F_57 ( & V_25 , 48 , V_171 , 1 , & V_94 , 32 , V_172 ,
1 , 0 ) ;
}
F_50 ( V_2 , V_25 , V_94 , & V_169 , & V_170 ) ;
V_25 = ( ( ( unsigned long ) V_171 ) << 12 ) / ( V_169 + 4096L ) ;
V_94 = ( ( ( unsigned long ) V_172 ) << 12 ) / ( V_170 + 4096L ) ;
V_102 -> V_86 . V_92 . V_25 = V_25 ;
V_102 -> V_86 . V_92 . V_94 = V_94 ;
V_102 -> V_86 . V_92 . V_176 = V_86 -> V_177 ;
V_102 -> V_86 . V_92 . V_24 = ( V_25 * V_86 -> V_96 + 7 ) >> 3 ;
V_102 -> V_86 . V_92 . V_93 = V_102 -> V_86 . V_92 . V_24 * V_94 ;
V_102 -> V_86 . V_92 . V_178 = V_179 ;
if ( V_2 -> V_28 )
V_102 -> V_86 . V_92 . V_10 = V_180 ;
else
V_102 -> V_86 . V_92 . V_10 = V_2 -> V_181 ?
V_11 : V_182 ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , unsigned int V_177 ,
unsigned V_25 , unsigned V_94 )
{
struct V_183 * V_86 ;
V_86 = F_54 ( V_177 ) ;
if ( ! V_86 )
return - V_97 ;
V_2 -> V_95 = V_86 ;
V_2 -> V_25 = V_25 ;
V_2 -> V_94 = V_94 ;
F_50 ( V_2 , V_2 -> V_25 , V_2 -> V_94 , & V_2 -> V_169 , & V_2 -> V_170 ) ;
F_59 ( V_2 ) ;
return 0 ;
}
static int F_60 ( struct V_173 * V_173 , void * V_159 ,
struct V_85 * V_102 )
{
struct V_1 * V_2 = F_61 ( V_173 ) ;
if ( V_2 -> V_104 > 0 )
return - V_82 ;
F_56 ( V_173 , V_159 , V_102 ) ;
return F_58 ( V_2 , V_102 -> V_86 . V_92 . V_176 ,
V_102 -> V_86 . V_92 . V_25 , V_102 -> V_86 . V_92 . V_94 ) ;
}
static int F_62 ( struct V_173 * V_173 , void * V_159 , T_1 * V_185 )
{
struct V_174 * V_175 = V_159 ;
struct V_1 * V_2 = V_175 -> V_2 ;
int V_103 ;
if ( V_2 -> V_149 . V_186 )
return - V_187 ;
V_103 = F_48 ( V_2 ) ;
if ( V_103 < 0 )
return V_103 ;
* V_185 = V_2 -> V_185 ;
return 0 ;
}
static int F_63 ( struct V_173 * V_173 , void * V_159 , T_1 * V_185 )
{
struct V_174 * V_175 = V_159 ;
struct V_1 * V_2 = V_175 -> V_2 ;
int V_103 ;
if ( V_2 -> V_149 . V_186 )
return - V_187 ;
V_103 = F_48 ( V_2 ) ;
if ( V_103 < 0 )
return V_103 ;
F_31 ( & V_2 -> V_118 , 0 , V_146 , V_188 , V_185 ) ;
return 0 ;
}
static int F_64 ( struct V_173 * V_173 , void * V_159 , T_1 * V_185 )
{
struct V_174 * V_175 = V_159 ;
struct V_1 * V_2 = V_175 -> V_2 ;
struct V_85 V_102 ;
int V_103 ;
if ( V_2 -> V_149 . V_186 )
return - V_187 ;
if ( * V_185 == V_2 -> V_185 )
return 0 ;
V_103 = F_48 ( V_2 ) ;
if ( V_103 < 0 )
return V_103 ;
if ( V_2 -> V_104 > 0 )
return - V_82 ;
V_2 -> V_185 = * V_185 ;
V_102 . V_86 . V_92 . V_25 = 720 ;
V_102 . V_86 . V_92 . V_94 = ( * V_185 & V_189 ) ? 480 : 576 ;
F_56 ( V_173 , V_159 , & V_102 ) ;
V_2 -> V_25 = V_102 . V_86 . V_92 . V_25 ;
V_2 -> V_94 = V_102 . V_86 . V_92 . V_94 ;
F_50 ( V_2 , V_2 -> V_25 , V_2 -> V_94 , & V_2 -> V_169 , & V_2 -> V_170 ) ;
F_59 ( V_2 ) ;
F_31 ( & V_2 -> V_118 , 0 , V_190 , V_191 , V_2 -> V_185 ) ;
return 0 ;
}
static int F_65 ( struct V_173 * V_173 , void * V_159 ,
struct V_192 * V_193 )
{
struct V_174 * V_175 = V_159 ;
struct V_1 * V_2 = V_175 -> V_2 ;
int V_103 = 0 ;
if ( V_193 -> type != V_76 )
return - V_97 ;
V_193 -> V_194 . V_195 . V_196 = V_197 ;
if ( V_2 -> V_149 . V_186 )
V_103 = F_66 ( & V_2 -> V_118 , 0 ,
V_146 , V_198 , V_193 ) ;
else
F_67 ( V_2 -> V_185 ,
& V_193 -> V_194 . V_195 . V_199 ) ;
return V_103 ;
}
static int F_68 ( struct V_173 * V_173 , void * V_159 ,
struct V_192 * V_193 )
{
struct V_174 * V_175 = V_159 ;
struct V_1 * V_2 = V_175 -> V_2 ;
if ( ! V_2 -> V_149 . V_186 )
return - V_187 ;
if ( V_193 -> type != V_76 )
return - V_97 ;
V_193 -> V_194 . V_195 . V_196 = V_197 ;
return F_66 ( & V_2 -> V_118 , 0 , V_146 , V_200 , V_193 ) ;
}
static int F_69 ( struct V_173 * V_173 , void * V_159 ,
struct V_201 * V_64 )
{
struct V_174 * V_175 = V_159 ;
struct V_1 * V_2 = V_175 -> V_2 ;
unsigned int V_202 ;
V_202 = V_64 -> V_139 ;
if ( V_202 >= V_203 )
return - V_97 ;
if ( 0 == F_43 ( V_202 ) -> type )
return - V_97 ;
V_64 -> V_139 = V_202 ;
V_64 -> type = V_204 ;
strcpy ( V_64 -> V_205 , V_206 [ F_43 ( V_202 ) -> type ] ) ;
if ( ( V_207 == F_43 ( V_202 ) -> type ) ||
( V_208 == F_43 ( V_202 ) -> type ) )
V_64 -> type = V_209 ;
V_64 -> V_210 = V_2 -> V_113 -> V_211 ;
if ( V_2 -> V_149 . V_186 )
V_64 -> V_212 = 0 ;
return 0 ;
}
static int F_70 ( struct V_173 * V_173 , void * V_159 , unsigned int * V_64 )
{
struct V_174 * V_175 = V_159 ;
struct V_1 * V_2 = V_175 -> V_2 ;
* V_64 = V_2 -> V_140 ;
return 0 ;
}
static int F_71 ( struct V_173 * V_173 , void * V_159 , unsigned int V_64 )
{
struct V_174 * V_175 = V_159 ;
struct V_1 * V_2 = V_175 -> V_2 ;
int V_103 ;
V_103 = F_48 ( V_2 ) ;
if ( V_103 < 0 )
return V_103 ;
if ( V_64 >= V_203 )
return - V_97 ;
if ( 0 == F_43 ( V_64 ) -> type )
return - V_97 ;
F_42 ( V_2 , V_64 ) ;
return 0 ;
}
static int F_72 ( struct V_173 * V_173 , void * V_159 , struct V_213 * V_214 )
{
struct V_174 * V_175 = V_159 ;
struct V_1 * V_2 = V_175 -> V_2 ;
if ( ! V_2 -> V_215 . V_216 )
return - V_97 ;
switch ( V_214 -> V_139 ) {
case V_217 :
strcpy ( V_214 -> V_205 , L_27 ) ;
break;
case V_218 :
strcpy ( V_214 -> V_205 , L_28 ) ;
break;
case V_219 :
strcpy ( V_214 -> V_205 , L_29 ) ;
break;
case V_220 :
strcpy ( V_214 -> V_205 , L_30 ) ;
break;
case V_221 :
strcpy ( V_214 -> V_205 , L_31 ) ;
break;
case V_222 :
strcpy ( V_214 -> V_205 , L_32 ) ;
break;
case V_223 :
strcpy ( V_214 -> V_205 , L_33 ) ;
break;
case V_224 :
strcpy ( V_214 -> V_205 , L_34 ) ;
break;
default:
return - V_97 ;
}
V_214 -> V_139 = V_2 -> V_141 ;
V_214 -> V_225 = V_226 ;
return 0 ;
}
static int F_73 ( struct V_173 * V_173 , void * V_159 , const struct V_213 * V_214 )
{
struct V_174 * V_175 = V_159 ;
struct V_1 * V_2 = V_175 -> V_2 ;
if ( ! V_2 -> V_215 . V_216 )
return - V_97 ;
if ( V_214 -> V_139 >= V_203 )
return - V_97 ;
if ( 0 == F_43 ( V_214 -> V_139 ) -> type )
return - V_97 ;
V_2 -> V_141 = F_43 ( V_214 -> V_139 ) -> V_142 ;
V_2 -> V_143 = F_43 ( V_214 -> V_139 ) -> V_144 ;
if ( ! V_2 -> V_143 )
V_2 -> V_143 = V_145 ;
return 0 ;
}
static int F_74 ( struct V_173 * V_173 , void * V_159 ,
struct V_227 * V_228 )
{
struct V_174 * V_175 = V_159 ;
struct V_1 * V_2 = V_175 -> V_2 ;
int V_103 ;
V_103 = F_48 ( V_2 ) ;
if ( V_103 < 0 )
return V_103 ;
if ( 0 != V_228 -> V_139 )
return - V_97 ;
strcpy ( V_228 -> V_205 , L_35 ) ;
F_31 ( & V_2 -> V_118 , 0 , V_119 , V_229 , V_228 ) ;
return 0 ;
}
static int F_75 ( struct V_173 * V_173 , void * V_159 ,
struct V_227 * V_228 )
{
struct V_174 * V_175 = V_159 ;
struct V_1 * V_2 = V_175 -> V_2 ;
int V_103 ;
V_103 = F_48 ( V_2 ) ;
if ( V_103 < 0 )
return V_103 ;
if ( 0 != V_228 -> V_139 )
return - V_97 ;
F_31 ( & V_2 -> V_118 , 0 , V_119 , V_230 , V_228 ) ;
return 0 ;
}
static int F_76 ( struct V_173 * V_173 , void * V_159 ,
struct V_101 * V_102 )
{
struct V_174 * V_175 = V_159 ;
struct V_1 * V_2 = V_175 -> V_2 ;
if ( 0 != V_102 -> V_119 )
return - V_97 ;
V_102 -> V_110 = V_2 -> V_111 ;
return 0 ;
}
static int F_77 ( struct V_173 * V_173 , void * V_159 ,
struct V_101 * V_102 )
{
struct V_174 * V_175 = V_159 ;
struct V_1 * V_2 = V_175 -> V_2 ;
int V_103 ;
V_103 = F_48 ( V_2 ) ;
if ( V_103 < 0 )
return V_103 ;
if ( 0 != V_102 -> V_119 )
return - V_97 ;
F_31 ( & V_2 -> V_118 , 0 , V_119 , V_120 , V_102 ) ;
F_31 ( & V_2 -> V_118 , 0 , V_119 , V_231 , V_102 ) ;
V_2 -> V_111 = V_102 -> V_110 ;
return 0 ;
}
static int F_78 ( int V_232 )
{
switch ( V_232 ) {
case V_233 :
case V_234 :
case V_235 :
return 2 ;
default:
return 1 ;
}
}
static int F_79 ( struct V_173 * V_173 , void * V_159 ,
struct V_236 * V_237 )
{
struct V_174 * V_175 = V_159 ;
struct V_1 * V_2 = V_175 -> V_2 ;
V_237 -> V_238 = V_239 ;
V_237 -> V_240 = 0 ;
if ( V_237 -> V_241 . type == V_242 ) {
if ( F_80 ( & V_237 -> V_241 ) )
V_237 -> V_238 = V_239 ;
return 0 ;
}
if ( V_237 -> V_241 . type != V_243 &&
V_237 -> V_241 . type != V_244 )
return - V_97 ;
F_31 ( & V_2 -> V_118 , 0 , V_190 , V_245 , V_237 ) ;
return 0 ;
}
static int F_81 ( struct V_173 * V_173 , void * V_159 ,
struct V_246 * V_232 )
{
struct V_174 * V_175 = V_159 ;
struct V_1 * V_2 = V_175 -> V_2 ;
int V_247 ;
switch ( V_232 -> V_241 . type ) {
case V_248 :
V_247 = F_82 ( V_2 , V_232 -> V_232 ) ;
if ( V_247 < 0 )
return V_247 ;
V_232 -> V_163 = V_247 ;
V_232 -> V_91 = 1 ;
return 0 ;
case V_243 :
F_31 ( & V_2 -> V_118 , 0 , V_190 , V_249 , V_232 ) ;
return 0 ;
case V_244 :
F_31 ( & V_2 -> V_118 , 0 , V_190 , V_249 , V_232 ) ;
return 0 ;
default:
if ( ! F_80 ( & V_232 -> V_241 ) )
return - V_97 ;
}
V_232 -> V_91 = F_78 ( V_232 -> V_232 ) ;
if ( V_232 -> V_91 == 1 ) {
V_247 = F_83 ( V_2 , V_232 -> V_232 ) ;
if ( V_247 < 0 )
return V_247 ;
V_232 -> V_163 = V_247 ;
} else {
T_2 V_163 = 0 ;
V_247 = F_84 ( V_2 , V_250 ,
V_232 -> V_232 , ( char * ) & V_163 , 2 ) ;
if ( V_247 < 0 )
return V_247 ;
V_232 -> V_163 = F_85 ( V_163 ) ;
}
return 0 ;
}
static int F_86 ( struct V_173 * V_173 , void * V_159 ,
struct V_246 * V_232 )
{
struct V_174 * V_175 = V_159 ;
struct V_1 * V_2 = V_175 -> V_2 ;
T_2 V_4 ;
switch ( V_232 -> V_241 . type ) {
case V_248 :
return F_87 ( V_2 , V_232 -> V_232 , V_232 -> V_163 ) ;
case V_243 :
F_31 ( & V_2 -> V_118 , 0 , V_190 , V_251 , V_232 ) ;
return 0 ;
case V_244 :
F_31 ( & V_2 -> V_118 , 0 , V_190 , V_251 , V_232 ) ;
return 0 ;
default:
if ( ! F_80 ( & V_232 -> V_241 ) )
return - V_97 ;
}
V_4 = F_88 ( V_232 -> V_163 ) ;
return F_89 ( V_2 , V_232 -> V_232 , ( char * ) & V_4 ,
F_78 ( V_232 -> V_232 ) ) ;
}
static int F_90 ( struct V_173 * V_173 , void * V_159 ,
struct V_252 * V_253 )
{
struct V_174 * V_175 = V_159 ;
struct V_1 * V_2 = V_175 -> V_2 ;
if ( V_253 -> type != V_76 )
return - V_97 ;
V_253 -> V_254 . V_255 = 0 ;
V_253 -> V_254 . V_256 = 0 ;
V_253 -> V_254 . V_25 = V_2 -> V_25 ;
V_253 -> V_254 . V_94 = V_2 -> V_94 ;
V_253 -> V_257 = V_253 -> V_254 ;
V_253 -> V_258 . V_259 = 54 ;
V_253 -> V_258 . V_260 = 59 ;
return 0 ;
}
static int F_91 ( struct V_173 * V_173 , void * V_159 ,
struct V_261 * V_262 )
{
struct V_263 * V_113 = F_92 ( V_173 ) ;
struct V_174 * V_175 = V_159 ;
struct V_1 * V_2 = V_175 -> V_2 ;
F_93 ( V_262 -> V_264 , L_36 , sizeof( V_262 -> V_264 ) ) ;
F_93 ( V_262 -> V_265 , V_266 [ V_2 -> V_267 ] . V_205 , sizeof( V_262 -> V_265 ) ) ;
F_94 ( V_2 -> V_268 , V_262 -> V_269 , sizeof( V_262 -> V_269 ) ) ;
if ( V_113 -> V_114 == V_270 )
V_262 -> V_271 = V_272 |
V_273 | V_274 ;
else if ( V_113 -> V_114 == V_115 )
V_262 -> V_271 = V_275 ;
else
V_262 -> V_271 = V_272 | V_276 ;
if ( V_2 -> V_215 . V_216 )
V_262 -> V_271 |= V_277 ;
if ( V_2 -> V_278 != V_279 )
V_262 -> V_271 |= V_280 ;
V_262 -> V_212 = V_262 -> V_271 | V_281 |
V_272 | V_273 | V_274 ;
if ( V_2 -> V_282 )
V_262 -> V_212 |= V_276 ;
if ( V_2 -> V_283 )
V_262 -> V_212 |= V_275 ;
return 0 ;
}
static int F_95 ( struct V_173 * V_173 , void * V_159 ,
struct V_284 * V_102 )
{
if ( F_96 ( V_102 -> V_139 >= F_55 ( V_95 ) ) )
return - V_97 ;
F_93 ( V_102 -> V_285 , V_95 [ V_102 -> V_139 ] . V_205 , sizeof( V_102 -> V_285 ) ) ;
V_102 -> V_176 = V_95 [ V_102 -> V_139 ] . V_177 ;
return 0 ;
}
static int F_97 ( struct V_173 * V_173 , void * V_159 ,
struct V_286 * V_287 )
{
struct V_174 * V_175 = V_159 ;
struct V_1 * V_2 = V_175 -> V_2 ;
struct V_183 * V_86 ;
unsigned int V_171 = F_51 ( V_2 ) ;
unsigned int V_172 = F_52 ( V_2 ) ;
V_86 = F_54 ( V_287 -> V_288 ) ;
if ( ! V_86 ) {
F_19 ( L_26 ,
V_287 -> V_288 ) ;
return - V_97 ;
}
if ( V_2 -> V_149 . V_184 ) {
if ( V_287 -> V_139 > 1 )
return - V_97 ;
V_287 -> type = V_289 ;
V_287 -> V_290 . V_25 = V_171 / ( 1 + V_287 -> V_139 ) ;
V_287 -> V_290 . V_94 = V_172 / ( 1 + V_287 -> V_139 ) ;
return 0 ;
}
if ( V_287 -> V_139 != 0 )
return - V_97 ;
V_287 -> type = V_291 ;
V_287 -> V_292 . V_293 = 48 ;
V_287 -> V_292 . V_294 = 32 ;
V_287 -> V_292 . V_295 = V_171 ;
V_287 -> V_292 . V_296 = V_172 ;
V_287 -> V_292 . V_297 = 1 ;
V_287 -> V_292 . V_298 = 1 ;
return 0 ;
}
static int F_98 ( struct V_173 * V_173 , void * V_159 ,
struct V_85 * V_95 )
{
struct V_174 * V_175 = V_159 ;
struct V_1 * V_2 = V_175 -> V_2 ;
V_95 -> V_86 . V_299 . V_300 = V_2 -> V_30 ;
V_95 -> V_86 . V_299 . V_301 = V_302 ;
V_95 -> V_86 . V_299 . V_21 = 0 ;
V_95 -> V_86 . V_299 . V_121 = 0 ;
V_95 -> V_86 . V_299 . V_303 = 6750000 * 4 / 2 ;
V_95 -> V_86 . V_299 . V_100 [ 0 ] = V_2 -> V_31 ;
V_95 -> V_86 . V_299 . V_100 [ 1 ] = V_2 -> V_31 ;
memset ( V_95 -> V_86 . V_299 . V_304 , 0 , sizeof( V_95 -> V_86 . V_299 . V_304 ) ) ;
if ( V_2 -> V_185 & V_189 ) {
V_95 -> V_86 . V_299 . V_305 [ 0 ] = 10 ;
V_95 -> V_86 . V_299 . V_305 [ 1 ] = 273 ;
} else if ( V_2 -> V_185 & V_306 ) {
V_95 -> V_86 . V_299 . V_305 [ 0 ] = 6 ;
V_95 -> V_86 . V_299 . V_305 [ 1 ] = 318 ;
}
return 0 ;
}
static int F_99 ( struct V_173 * V_173 , void * V_159 ,
struct V_85 * V_95 )
{
struct V_174 * V_175 = V_159 ;
struct V_1 * V_2 = V_175 -> V_2 ;
V_95 -> V_86 . V_299 . V_300 = V_2 -> V_30 ;
V_95 -> V_86 . V_299 . V_301 = V_302 ;
V_95 -> V_86 . V_299 . V_21 = 0 ;
V_95 -> V_86 . V_299 . V_121 = 0 ;
V_95 -> V_86 . V_299 . V_303 = 6750000 * 4 / 2 ;
V_95 -> V_86 . V_299 . V_100 [ 0 ] = V_2 -> V_31 ;
V_95 -> V_86 . V_299 . V_100 [ 1 ] = V_2 -> V_31 ;
memset ( V_95 -> V_86 . V_299 . V_304 , 0 , sizeof( V_95 -> V_86 . V_299 . V_304 ) ) ;
if ( V_2 -> V_185 & V_189 ) {
V_95 -> V_86 . V_299 . V_305 [ 0 ] = 10 ;
V_95 -> V_86 . V_299 . V_305 [ 1 ] = 273 ;
} else if ( V_2 -> V_185 & V_306 ) {
V_95 -> V_86 . V_299 . V_305 [ 0 ] = 6 ;
V_95 -> V_86 . V_299 . V_305 [ 1 ] = 318 ;
}
return 0 ;
}
static int F_100 ( struct V_173 * V_173 , void * V_159 ,
struct V_227 * V_228 )
{
struct V_1 * V_2 = ( (struct V_174 * ) V_159 ) -> V_2 ;
if ( F_96 ( V_228 -> V_139 > 0 ) )
return - V_97 ;
strcpy ( V_228 -> V_205 , L_37 ) ;
V_228 -> type = V_116 ;
F_31 ( & V_2 -> V_118 , 0 , V_119 , V_229 , V_228 ) ;
return 0 ;
}
static int F_101 ( struct V_173 * V_173 , void * V_159 ,
struct V_227 * V_228 )
{
struct V_1 * V_2 = ( (struct V_174 * ) V_159 ) -> V_2 ;
if ( 0 != V_228 -> V_139 )
return - V_97 ;
F_31 ( & V_2 -> V_118 , 0 , V_119 , V_230 , V_228 ) ;
return 0 ;
}
static int F_102 ( struct V_173 * V_307 )
{
struct V_263 * V_113 = F_92 ( V_307 ) ;
struct V_1 * V_2 = F_61 ( V_307 ) ;
enum V_74 V_308 = 0 ;
struct V_174 * V_175 ;
switch ( V_113 -> V_114 ) {
case V_270 :
V_308 = V_76 ;
break;
case V_309 :
V_308 = V_78 ;
break;
}
F_19 ( L_38 ,
F_103 ( V_113 ) , V_310 [ V_308 ] ,
V_2 -> V_311 ) ;
if ( F_104 ( & V_2 -> V_312 ) )
return - V_313 ;
V_175 = F_105 ( sizeof( struct V_174 ) , V_314 ) ;
if ( ! V_175 ) {
F_49 ( L_39 ) ;
F_106 ( & V_2 -> V_312 ) ;
return - V_315 ;
}
F_107 ( & V_175 -> V_175 , V_113 ) ;
V_175 -> V_2 = V_2 ;
V_175 -> type = V_308 ;
V_307 -> V_316 = V_175 ;
if ( V_175 -> type == V_76 && V_2 -> V_311 == 0 ) {
F_108 ( V_2 , V_105 ) ;
F_59 ( V_2 ) ;
F_29 ( V_2 ) ;
}
if ( V_113 -> V_114 == V_115 ) {
F_19 ( L_40 ) ;
F_31 ( & V_2 -> V_118 , 0 , V_119 , V_317 ) ;
}
V_2 -> V_311 ++ ;
F_106 ( & V_2 -> V_312 ) ;
F_109 ( & V_175 -> V_175 ) ;
return 0 ;
}
void F_110 ( struct V_1 * V_2 )
{
if ( V_2 -> V_283 ) {
if ( F_111 ( V_2 -> V_283 ) )
F_112 ( V_2 -> V_283 ) ;
else
F_113 ( V_2 -> V_283 ) ;
V_2 -> V_283 = NULL ;
}
if ( V_2 -> V_282 ) {
F_114 ( L_41 ,
F_103 ( V_2 -> V_282 ) ) ;
if ( F_111 ( V_2 -> V_282 ) )
F_112 ( V_2 -> V_282 ) ;
else
F_113 ( V_2 -> V_282 ) ;
V_2 -> V_282 = NULL ;
}
if ( V_2 -> V_113 ) {
F_114 ( L_41 ,
F_103 ( V_2 -> V_113 ) ) ;
if ( F_111 ( V_2 -> V_113 ) )
F_112 ( V_2 -> V_113 ) ;
else
F_113 ( V_2 -> V_113 ) ;
V_2 -> V_113 = NULL ;
}
}
static int F_115 ( struct V_173 * V_307 )
{
struct V_174 * V_175 = V_307 -> V_316 ;
struct V_1 * V_2 = V_175 -> V_2 ;
int V_318 ;
F_19 ( L_42 , V_2 -> V_311 ) ;
F_116 ( & V_2 -> V_312 ) ;
F_117 ( V_307 ) ;
if ( V_2 -> V_311 == 1 ) {
if ( V_2 -> V_67 ) {
F_118 ( V_2 ) ;
F_119 ( V_2 -> V_319 ) ;
F_106 ( & V_2 -> V_312 ) ;
F_119 ( V_2 ) ;
return 0 ;
}
F_31 ( & V_2 -> V_118 , 0 , V_190 , V_320 , 0 ) ;
F_108 ( V_2 , V_321 ) ;
V_2 -> V_322 = 0 ;
F_19 ( L_43 ) ;
V_318 = F_120 ( V_2 -> V_268 , 0 , 0 ) ;
if ( V_318 < 0 ) {
F_49 ( L_44
L_45 , V_318 ) ;
}
}
V_2 -> V_311 -- ;
F_106 ( & V_2 -> V_312 ) ;
return 0 ;
}
static struct V_263 * F_121 ( struct V_1 * V_2 ,
const struct V_263 * V_323 ,
const char * V_324 )
{
struct V_263 * V_325 ;
V_325 = F_122 () ;
if ( NULL == V_325 )
return NULL ;
* V_325 = * V_323 ;
V_325 -> V_118 = & V_2 -> V_118 ;
V_325 -> V_326 = V_327 ;
V_325 -> V_312 = & V_2 -> V_312 ;
F_123 ( V_328 , & V_325 -> V_121 ) ;
if ( V_2 -> V_149 . V_186 )
V_325 -> V_211 = 0 ;
snprintf ( V_325 -> V_205 , sizeof( V_325 -> V_205 ) , L_46 ,
V_2 -> V_205 , V_324 ) ;
F_124 ( V_325 , V_2 ) ;
return V_325 ;
}
int F_125 ( struct V_1 * V_2 )
{
T_3 V_163 ;
int V_247 ;
unsigned int V_171 ;
F_126 ( V_329 L_47 ,
V_2 -> V_205 , V_330 ) ;
V_2 -> V_185 = V_331 ;
F_31 ( & V_2 -> V_118 , 0 , V_190 , V_191 , V_2 -> V_185 ) ;
V_2 -> V_181 = V_332 ;
V_2 -> V_95 = & V_95 [ 0 ] ;
V_171 = F_51 ( V_2 ) ;
if ( V_2 -> V_149 . V_184 )
V_171 /= 2 ;
F_58 ( V_2 , V_95 [ 0 ] . V_177 ,
V_171 , F_52 ( V_2 ) ) ;
F_42 ( V_2 , 0 ) ;
V_2 -> V_162 = 1 ;
V_2 -> V_165 = 0x1f ;
V_163 = ( T_3 ) F_83 ( V_2 , V_333 ) ;
F_127 ( V_2 , V_333 ,
( V_334 | V_163 ) ) ;
F_128 ( V_2 ) ;
F_129 ( V_2 ) ;
F_130 ( V_2 ) ;
V_2 -> V_113 = F_121 ( V_2 , & V_335 , L_48 ) ;
if ( ! V_2 -> V_113 ) {
F_49 ( L_49 ) ;
return - V_168 ;
}
V_2 -> V_113 -> V_336 = & V_2 -> V_125 ;
V_2 -> V_113 -> V_336 -> V_312 = & V_2 -> V_337 ;
V_247 = F_131 ( V_2 -> V_113 , V_270 ,
V_338 [ V_2 -> V_339 ] ) ;
if ( V_247 ) {
F_49 ( L_50 ,
V_247 ) ;
return V_247 ;
}
if ( F_132 ( V_2 ) == 1 ) {
V_2 -> V_282 = F_121 ( V_2 , & V_335 ,
L_51 ) ;
V_2 -> V_282 -> V_336 = & V_2 -> V_137 ;
V_2 -> V_282 -> V_336 -> V_312 = & V_2 -> V_340 ;
V_247 = F_131 ( V_2 -> V_282 , V_309 ,
V_341 [ V_2 -> V_339 ] ) ;
if ( V_247 < 0 ) {
F_49 ( L_52 ) ;
return V_247 ;
}
}
if ( V_266 [ V_2 -> V_267 ] . V_342 . type == V_343 ) {
V_2 -> V_283 = F_121 ( V_2 , & V_344 ,
L_53 ) ;
if ( ! V_2 -> V_283 ) {
F_49 ( L_49 ) ;
return - V_168 ;
}
V_247 = F_131 ( V_2 -> V_283 , V_115 ,
V_345 [ V_2 -> V_339 ] ) ;
if ( V_247 < 0 ) {
F_49 ( L_54 ) ;
return V_247 ;
}
F_114 ( L_55 ,
F_103 ( V_2 -> V_283 ) ) ;
}
F_114 ( L_56 ,
F_103 ( V_2 -> V_113 ) ) ;
if ( V_2 -> V_282 )
F_114 ( L_57 ,
F_103 ( V_2 -> V_282 ) ) ;
return 0 ;
}
