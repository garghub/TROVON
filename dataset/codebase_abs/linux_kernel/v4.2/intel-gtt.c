static int F_1 ( struct V_1 * * V_2 ,
unsigned int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 ;
int V_8 ;
F_2 ( L_1 , ( unsigned long ) V_3 ) ;
if ( F_3 ( V_5 , V_3 , V_9 ) )
goto V_10;
F_4 (st->sgl, sg, num_entries, i)
F_5 ( V_7 , V_2 [ V_8 ] , V_11 , 0 ) ;
if ( ! F_6 ( V_12 . V_13 ,
V_5 -> V_14 , V_5 -> V_15 , V_16 ) )
goto V_10;
return 0 ;
V_10:
F_7 ( V_5 ) ;
return - V_17 ;
}
static void F_8 ( struct V_6 * V_18 , int V_19 )
{
struct V_4 V_5 ;
F_2 ( L_2 , ( unsigned long ) V_20 -> V_21 ) ;
F_9 ( V_12 . V_13 , V_18 ,
V_19 , V_16 ) ;
V_5 . V_14 = V_18 ;
V_5 . V_22 = V_5 . V_15 = V_19 ;
F_7 ( & V_5 ) ;
}
static void F_10 ( struct V_23 * V_24 , T_1 V_25 )
{
return;
}
static struct V_1 * F_11 ( void )
{
struct V_1 * V_1 ;
V_1 = F_12 ( V_9 | V_26 , 2 ) ;
if ( V_1 == NULL )
return NULL ;
if ( F_13 ( V_1 , 4 ) < 0 ) {
F_14 ( V_1 , 4 ) ;
F_15 ( V_1 , 2 ) ;
return NULL ;
}
F_16 ( & V_27 -> V_28 ) ;
return V_1 ;
}
static void F_17 ( struct V_1 * V_1 )
{
if ( V_1 == NULL )
return;
F_14 ( V_1 , 4 ) ;
F_15 ( V_1 , 2 ) ;
F_18 ( & V_27 -> V_28 ) ;
}
static int F_19 ( void )
{
T_2 V_29 ;
char * V_30 ;
V_30 = F_20 ( V_31 ) ;
if ( V_30 == NULL )
return - V_17 ;
V_12 . V_32 = V_30 ;
V_29 = F_21 ( V_12 . V_13 , V_33 ) ;
V_12 . V_34 = F_22 ( V_29 , F_23 ( 64 ) ) ;
if ( ! V_12 . V_34 )
return - V_17 ;
F_24 ( F_25 ( V_30 ) | V_35 ,
V_12 . V_34 + V_36 ) ;
V_12 . V_37 = V_29 + V_38 ;
if ( ( F_26 ( V_12 . V_34 + V_39 )
& V_40 ) == V_41 ) {
F_27 ( & V_12 . V_13 -> V_42 ,
L_3 ) ;
V_12 . V_43 = 1024 ;
}
return 0 ;
}
static void F_28 ( void )
{
F_24 ( 0 , V_12 . V_34 + V_36 ) ;
F_29 ( V_12 . V_32 , V_31 ) ;
}
static int F_30 ( struct V_44 * V_20 , T_3 V_45 ,
int type )
{
int V_8 ;
if ( ( V_45 + V_20 -> V_21 )
> V_12 . V_43 )
return - V_46 ;
if ( ! V_20 -> V_47 )
F_31 () ;
for ( V_8 = V_45 ; V_8 < ( V_45 + V_20 -> V_21 ) ; V_8 ++ ) {
T_4 V_48 = V_8 << V_49 ;
V_12 . V_50 -> V_51 ( V_48 ,
V_8 , type ) ;
}
F_32 () ;
return 0 ;
}
static struct V_44 * F_33 ( T_5 V_52 , int type )
{
struct V_44 * V_53 ;
struct V_1 * V_1 ;
switch ( V_52 ) {
case 1 : V_1 = V_27 -> V_50 -> V_54 ( V_27 ) ;
break;
case 4 :
V_1 = F_11 () ;
break;
default:
return NULL ;
}
if ( V_1 == NULL )
return NULL ;
V_53 = F_34 ( V_52 ) ;
if ( V_53 == NULL )
return NULL ;
V_53 -> V_2 [ 0 ] = V_1 ;
if ( V_52 == 4 ) {
V_53 -> V_2 [ 1 ] = V_53 -> V_2 [ 0 ] + 1 ;
V_53 -> V_2 [ 2 ] = V_53 -> V_2 [ 1 ] + 1 ;
V_53 -> V_2 [ 3 ] = V_53 -> V_2 [ 2 ] + 1 ;
}
V_53 -> V_21 = V_52 ;
V_53 -> V_55 = V_52 ;
V_53 -> type = V_56 ;
V_53 -> V_57 = F_35 ( V_53 -> V_2 [ 0 ] ) ;
return V_53 ;
}
static void F_36 ( struct V_44 * V_58 )
{
F_37 ( V_58 -> V_59 ) ;
if ( V_58 -> type == V_56 ) {
if ( V_58 -> V_21 == 4 )
F_17 ( V_58 -> V_2 [ 0 ] ) ;
else {
V_27 -> V_50 -> V_60 ( V_58 -> V_2 [ 0 ] ,
V_61 ) ;
V_27 -> V_50 -> V_60 ( V_58 -> V_2 [ 0 ] ,
V_62 ) ;
}
F_38 ( V_58 ) ;
}
F_39 ( V_58 ) ;
}
static int F_40 ( void )
{
struct V_1 * V_1 ;
T_4 V_63 ;
V_1 = F_41 ( V_9 | V_26 | V_64 ) ;
if ( V_1 == NULL )
return - V_17 ;
F_13 ( V_1 , 1 ) ;
if ( V_12 . V_65 ) {
V_63 = F_42 ( V_12 . V_13 , V_1 , 0 ,
V_11 , V_16 ) ;
if ( F_43 ( V_12 . V_13 , V_63 ) )
return - V_46 ;
V_12 . V_66 = V_63 ;
} else
V_12 . V_66 = F_35 ( V_1 ) ;
V_12 . V_67 = V_1 ;
return 0 ;
}
static void F_44 ( T_4 V_48 , unsigned int V_68 ,
unsigned int V_69 )
{
T_1 V_70 = V_71 ;
switch ( V_69 ) {
case V_72 :
V_70 |= V_73 ;
break;
case V_74 :
V_70 |= V_75 ;
break;
}
F_45 ( V_48 | V_70 , V_12 . V_76 + V_68 ) ;
}
static unsigned int F_46 ( void )
{
T_6 V_77 ;
T_7 V_78 ;
int V_79 = 0 ;
static const int V_80 [ 4 ] = { 0 , 16 , 32 , 64 } ;
unsigned int V_81 = 0 ;
if ( V_82 == 1 )
return 0 ;
F_47 ( V_12 . V_83 ,
V_84 , & V_77 ) ;
if ( V_12 . V_83 -> V_85 == V_86 ||
V_12 . V_83 -> V_85 == V_87 ) {
switch ( V_77 & V_88 ) {
case V_89 :
V_81 = F_23 ( 512 ) ;
break;
case V_90 :
V_81 = F_48 ( 1 ) ;
break;
case V_91 :
V_81 = F_48 ( 8 ) ;
break;
case V_92 :
V_78 = F_49 ( V_12 . V_34 + V_93 ) ;
V_81 = ( F_50 ( V_78 ) + 1 ) *
F_48 ( V_80 [ F_51 ( V_78 ) ] ) ;
V_79 = 1 ;
break;
default:
V_81 = 0 ;
break;
}
} else {
switch ( V_77 & V_94 ) {
case V_95 :
V_81 = F_48 ( 1 ) ;
break;
case V_96 :
V_81 = F_48 ( 4 ) ;
break;
case V_97 :
V_81 = F_48 ( 8 ) ;
break;
case V_98 :
V_81 = F_48 ( 16 ) ;
break;
case V_99 :
V_81 = F_48 ( 32 ) ;
break;
case V_100 :
V_81 = F_48 ( 48 ) ;
break;
case V_101 :
V_81 = F_48 ( 64 ) ;
break;
case V_102 :
V_81 = F_48 ( 128 ) ;
break;
case V_103 :
V_81 = F_48 ( 256 ) ;
break;
case V_104 :
V_81 = F_48 ( 96 ) ;
break;
case V_105 :
V_81 = F_48 ( 160 ) ;
break;
case V_106 :
V_81 = F_48 ( 224 ) ;
break;
case V_107 :
V_81 = F_48 ( 352 ) ;
break;
default:
V_81 = 0 ;
break;
}
}
if ( V_81 > 0 ) {
F_27 ( & V_12 . V_83 -> V_42 , L_4 ,
V_81 / F_23 ( 1 ) , V_79 ? L_5 : L_6 ) ;
} else {
F_27 ( & V_12 . V_83 -> V_42 ,
L_7 ) ;
V_81 = 0 ;
}
return V_81 ;
}
static void F_52 ( unsigned int V_108 )
{
T_1 V_109 , V_110 ;
V_110 = F_26 ( V_12 . V_34 + V_111 ) ;
V_110 &= ~ V_35 ;
F_24 ( V_110 , V_12 . V_34 + V_111 ) ;
V_109 = F_26 ( V_12 . V_34 + V_36 ) ;
V_109 &= ~ V_112 ;
V_109 |= V_108 ;
F_24 ( V_109 , V_12 . V_34 + V_36 ) ;
}
static unsigned int F_53 ( void )
{
int V_113 ;
T_1 V_109 ;
T_6 V_114 ;
F_47 ( V_12 . V_83 ,
V_84 , & V_114 ) ;
if ( V_82 == 5 ) {
switch ( V_114 & V_115 ) {
case V_116 :
case V_117 :
F_52 ( V_118 ) ;
break;
case V_119 :
F_52 ( V_120 ) ;
break;
case V_121 :
case V_122 :
F_52 ( V_123 ) ;
break;
}
}
V_109 = F_26 ( V_12 . V_34 + V_36 ) ;
switch ( V_109 & V_112 ) {
case V_124 :
V_113 = F_23 ( 128 ) ;
break;
case V_125 :
V_113 = F_23 ( 256 ) ;
break;
case V_126 :
V_113 = F_23 ( 512 ) ;
break;
case V_118 :
V_113 = F_23 ( 1024 ) ;
break;
case V_123 :
V_113 = F_23 ( 2048 ) ;
break;
case V_120 :
V_113 = F_23 ( 1024 + 512 ) ;
break;
default:
F_27 ( & V_12 . V_13 -> V_42 ,
L_8 ) ;
V_113 = F_23 ( 512 ) ;
}
return V_113 / 4 ;
}
static unsigned int F_54 ( void )
{
if ( V_127 || V_82 == 4 || V_82 == 5 )
return F_53 () ;
else {
return V_12 . V_128 ;
}
}
static unsigned int F_55 ( void )
{
unsigned int V_129 ;
if ( V_82 == 1 ) {
T_1 V_130 ;
F_56 ( V_12 . V_83 ,
V_131 , & V_130 ) ;
if ( ( V_130 & V_132 )
== V_133 )
V_129 = F_48 ( 32 ) ;
else
V_129 = F_48 ( 64 ) ;
} else if ( V_82 == 2 ) {
T_6 V_77 ;
F_47 ( V_12 . V_83 ,
V_84 , & V_77 ) ;
if ( ( V_77 & V_134 ) == V_135 )
V_129 = F_48 ( 64 ) ;
else
V_129 = F_48 ( 128 ) ;
} else {
V_129 = F_57 ( V_12 . V_13 , 2 ) ;
}
return V_129 >> V_49 ;
}
static void F_58 ( void )
{
F_14 ( V_12 . V_67 , 1 ) ;
F_59 ( V_12 . V_13 , V_12 . V_66 ,
V_11 , V_16 ) ;
F_60 ( V_12 . V_67 ) ;
}
static void F_61 ( void )
{
V_12 . V_50 -> V_136 () ;
F_62 ( V_12 . V_76 ) ;
F_62 ( V_12 . V_34 ) ;
F_58 () ;
}
static inline int F_63 ( void )
{
#ifdef F_64
const unsigned short V_137 = V_12 . V_13 -> V_85 ;
if ( ( V_137 == V_138 ||
V_137 == V_139 ) &&
V_140 )
return 1 ;
#endif
return 0 ;
}
static bool F_65 ( void )
{
if ( V_82 <= 2 )
return false ;
if ( V_82 >= 6 )
return false ;
if ( F_63 () )
return false ;
return true ;
}
static int F_66 ( void )
{
T_1 V_141 ;
int V_142 , V_143 ;
V_142 = V_12 . V_50 -> V_144 () ;
if ( V_142 != 0 )
return V_142 ;
V_12 . V_128 = F_55 () ;
V_12 . V_145 = F_54 () ;
V_12 . V_146 =
F_26 ( V_12 . V_34 + V_36 )
& ~ V_35 ;
if ( V_147 )
V_12 . V_146 |= V_35 ;
F_27 ( & V_12 . V_83 -> V_42 ,
L_9 ,
V_12 . V_145 * 4 ,
V_12 . V_128 * 4 ) ;
V_141 = V_12 . V_145 * 4 ;
V_12 . V_76 = NULL ;
if ( F_65 () )
V_12 . V_76 = F_67 ( V_12 . V_37 ,
V_141 ) ;
if ( V_12 . V_76 == NULL )
V_12 . V_76 = F_22 ( V_12 . V_37 ,
V_141 ) ;
if ( V_12 . V_76 == NULL ) {
V_12 . V_50 -> V_136 () ;
F_62 ( V_12 . V_34 ) ;
return - V_17 ;
}
#if F_68 ( V_148 )
F_31 () ;
#endif
V_12 . V_81 = F_46 () ;
V_12 . V_65 = V_149 && V_82 > 2 ;
V_142 = F_40 () ;
if ( V_142 != 0 ) {
F_61 () ;
return V_142 ;
}
if ( V_82 <= 2 )
V_143 = V_150 ;
else
V_143 = V_151 ;
V_12 . V_152 = F_69 ( V_12 . V_13 , V_143 ) ;
return 0 ;
}
static int F_70 ( void )
{
int V_153 = F_71 ( V_154 ) ;
unsigned int V_155 ;
int V_8 ;
V_155 = ( V_12 . V_128 << V_49 ) / F_48 ( 1 ) ;
for ( V_8 = 0 ; V_8 < V_153 ; V_8 ++ ) {
if ( V_155 == V_154 [ V_8 ] . V_113 ) {
V_27 -> V_156 =
( void * ) ( V_154 + V_8 ) ;
return V_155 ;
}
}
return 0 ;
}
static void F_72 ( void )
{
}
static void F_73 ( void )
{
unsigned long V_157 = V_158 + F_74 ( 1000 ) ;
F_75 () ;
F_24 ( F_26 ( V_12 . V_34 + V_159 ) | ( 1 << 31 ) ,
V_12 . V_34 + V_159 ) ;
while ( F_26 ( V_12 . V_34 + V_159 ) & ( 1 << 31 ) ) {
if ( F_76 ( V_158 , V_157 ) )
break;
F_77 ( 50 ) ;
}
}
static void F_78 ( T_4 V_48 , unsigned int V_68 ,
unsigned int V_69 )
{
T_1 V_70 = V_71 ;
if ( V_69 == V_74 )
V_70 |= V_75 ;
F_45 ( V_48 | V_70 , V_12 . V_76 + V_68 ) ;
}
bool F_79 ( void )
{
T_7 T_8 * V_160 ;
if ( V_82 == 2 ) {
T_6 V_77 ;
F_47 ( V_12 . V_83 ,
V_84 , & V_77 ) ;
V_77 |= V_161 ;
F_80 ( V_12 . V_83 ,
V_84 , V_77 ) ;
F_47 ( V_12 . V_83 ,
V_84 , & V_77 ) ;
if ( ( V_77 & V_161 ) == 0 ) {
F_81 ( & V_12 . V_13 -> V_42 ,
L_10 ,
V_77 ) ;
return false ;
}
}
if ( V_82 >= 3 )
F_24 ( 0 , V_12 . V_34 + V_162 ) ;
V_160 = V_12 . V_34 + V_36 ;
F_24 ( V_12 . V_146 , V_160 ) ;
if ( V_147 && ( F_26 ( V_160 ) & V_35 ) == 0 ) {
F_81 ( & V_12 . V_13 -> V_42 ,
L_11 ,
F_26 ( V_160 ) , V_12 . V_146 ) ;
return false ;
}
if ( V_82 >= 3 )
F_24 ( 0 , V_12 . V_34 + V_162 ) ;
return true ;
}
static int F_82 ( void )
{
T_2 V_29 ;
V_29 = F_21 ( V_12 . V_13 , V_33 ) ;
V_12 . V_34 = F_22 ( V_29 , F_23 ( 64 ) ) ;
if ( ! V_12 . V_34 )
return - V_17 ;
V_12 . V_37 = V_29 + V_38 ;
return 0 ;
}
static int F_83 ( struct V_23 * V_24 )
{
V_27 -> V_163 = NULL ;
V_27 -> V_164 = NULL ;
V_27 -> V_165 = 0 ;
return 0 ;
}
static int F_84 ( struct V_23 * V_24 )
{
return 0 ;
}
static int F_85 ( void )
{
if ( ! F_79 () )
return - V_166 ;
V_12 . V_167 = true ;
V_27 -> V_168 = V_12 . V_152 ;
return 0 ;
}
static bool F_86 ( unsigned int V_69 )
{
switch ( V_69 ) {
case 0 :
case V_56 :
case V_74 :
case V_169 :
return true ;
}
return false ;
}
void F_87 ( struct V_4 * V_5 ,
unsigned int V_45 ,
unsigned int V_69 )
{
struct V_6 * V_7 ;
unsigned int V_170 , V_171 ;
int V_8 , V_172 ;
V_172 = V_45 ;
F_4 (st->sgl, sg, st->nents, i) {
V_170 = F_88 ( V_7 ) >> V_49 ;
for ( V_171 = 0 ; V_171 < V_170 ; V_171 ++ ) {
T_4 V_48 = F_89 ( V_7 ) + ( V_171 << V_49 ) ;
V_12 . V_50 -> V_51 ( V_48 , V_172 , V_69 ) ;
V_172 ++ ;
}
}
F_32 () ;
}
static void F_90 ( unsigned int V_173 ,
unsigned int V_3 ,
struct V_1 * * V_2 ,
unsigned int V_69 )
{
int V_8 , V_172 ;
for ( V_8 = 0 , V_172 = V_173 ; V_8 < V_3 ; V_8 ++ , V_172 ++ ) {
T_4 V_48 = F_35 ( V_2 [ V_8 ] ) ;
V_12 . V_50 -> V_51 ( V_48 ,
V_172 , V_69 ) ;
}
F_32 () ;
}
static int F_91 ( struct V_44 * V_20 ,
T_3 V_45 , int type )
{
int V_142 = - V_46 ;
if ( V_12 . V_167 ) {
int V_174 = V_12 . V_81 / V_11 ;
int V_175 = V_12 . V_128 ;
F_92 ( V_174 , V_175 - V_174 ) ;
V_12 . V_167 = false ;
}
if ( V_82 == 1 && type == V_72 )
return F_30 ( V_20 , V_45 , type ) ;
if ( V_20 -> V_21 == 0 )
goto V_176;
if ( V_45 + V_20 -> V_21 > V_12 . V_145 )
goto V_177;
if ( type != V_20 -> type )
goto V_177;
if ( ! V_12 . V_50 -> V_178 ( type ) )
goto V_177;
if ( ! V_20 -> V_47 )
F_31 () ;
if ( V_12 . V_65 ) {
struct V_4 V_5 ;
V_142 = F_1 ( V_20 -> V_2 , V_20 -> V_21 , & V_5 ) ;
if ( V_142 != 0 )
return V_142 ;
F_87 ( & V_5 , V_45 , type ) ;
V_20 -> V_18 = V_5 . V_14 ;
V_20 -> V_19 = V_5 . V_15 ;
} else
F_90 ( V_45 , V_20 -> V_21 , V_20 -> V_2 ,
type ) ;
V_176:
V_142 = 0 ;
V_177:
V_20 -> V_47 = true ;
return V_142 ;
}
void F_92 ( unsigned int V_173 , unsigned int V_3 )
{
unsigned int V_8 ;
for ( V_8 = V_173 ; V_8 < ( V_173 + V_3 ) ; V_8 ++ ) {
V_12 . V_50 -> V_51 ( V_12 . V_66 ,
V_8 , 0 ) ;
}
F_32 () ;
}
static int F_93 ( struct V_44 * V_20 ,
T_3 V_45 , int type )
{
if ( V_20 -> V_21 == 0 )
return 0 ;
F_92 ( V_45 , V_20 -> V_21 ) ;
if ( V_12 . V_65 ) {
F_8 ( V_20 -> V_18 , V_20 -> V_19 ) ;
V_20 -> V_18 = NULL ;
V_20 -> V_19 = 0 ;
}
return 0 ;
}
static struct V_44 * F_94 ( T_5 V_52 ,
int type )
{
struct V_44 * V_53 ;
if ( type == V_72 && V_82 == 1 ) {
if ( V_52 != V_12 . V_43 )
return NULL ;
V_53 = F_34 ( 1 ) ;
if ( V_53 == NULL )
return NULL ;
V_53 -> type = V_72 ;
V_53 -> V_21 = V_52 ;
V_53 -> V_55 = 0 ;
F_38 ( V_53 ) ;
return V_53 ;
}
if ( type == V_56 )
return F_33 ( V_52 , type ) ;
return NULL ;
}
static int F_95 ( void )
{
int V_142 ;
V_142 = F_96 ( V_12 . V_83 -> V_179 , & V_12 . V_180 , V_11 ,
V_11 , V_181 , 0 ,
V_182 , V_12 . V_83 ) ;
return V_142 ;
}
static void F_97 ( void )
{
int V_142 ;
T_1 V_183 ;
F_56 ( V_12 . V_83 , V_184 , & V_183 ) ;
if ( ! ( V_183 & 0x1 ) ) {
F_95 () ;
V_12 . V_185 = 1 ;
F_98 ( V_12 . V_83 , V_184 , ( V_12 . V_180 . V_174 & 0xffffffff ) | 0x1 ) ;
} else {
V_183 &= ~ 1 ;
V_12 . V_185 = 1 ;
V_12 . V_180 . V_174 = V_183 ;
V_12 . V_180 . V_175 = V_183 + V_11 ;
V_142 = F_99 ( & V_186 , & V_12 . V_180 ) ;
if ( V_142 )
V_12 . V_185 = 0 ;
}
}
static void F_100 ( void )
{
T_1 V_187 , V_188 ;
int V_142 ;
F_56 ( V_12 . V_83 , V_189 + 4 , & V_187 ) ;
F_56 ( V_12 . V_83 , V_189 , & V_188 ) ;
if ( ! ( V_188 & 0x1 ) ) {
F_95 () ;
V_12 . V_185 = 1 ;
F_98 ( V_12 . V_83 , V_189 + 4 ,
F_101 ( V_12 . V_180 . V_174 ) ) ;
F_98 ( V_12 . V_83 , V_189 , ( V_12 . V_180 . V_174 & 0xffffffff ) | 0x1 ) ;
} else {
T_9 V_190 ;
V_188 &= ~ 0x1 ;
V_190 = ( ( T_9 ) V_187 << 32 ) | V_188 ;
V_12 . V_185 = 1 ;
V_12 . V_180 . V_174 = V_190 ;
V_12 . V_180 . V_175 = V_190 + V_11 ;
V_142 = F_99 ( & V_186 , & V_12 . V_180 ) ;
if ( V_142 )
V_12 . V_185 = 0 ;
}
}
static void F_102 ( void )
{
if ( V_12 . V_180 . V_174 )
return;
if ( V_82 == 6 )
return;
V_12 . V_180 . V_191 = L_12 ;
V_12 . V_180 . V_69 = V_192 ;
if ( V_127 || V_82 >= 4 ) {
F_100 () ;
} else {
F_97 () ;
}
if ( V_12 . V_180 . V_174 )
V_12 . V_193 = F_103 ( V_12 . V_180 . V_174 , V_11 ) ;
if ( ! V_12 . V_193 )
F_81 ( & V_12 . V_13 -> V_42 ,
L_13 ) ;
}
static void F_104 ( void )
{
if ( V_12 . V_193 )
F_62 ( V_12 . V_193 ) ;
if ( V_12 . V_185 )
F_105 ( & V_12 . V_180 ) ;
V_12 . V_180 . V_174 = 0 ;
V_12 . V_185 = 0 ;
}
static void F_106 ( void )
{
if ( V_12 . V_193 )
F_24 ( 1 , V_12 . V_193 ) ;
}
static void F_107 ( T_4 V_48 ,
unsigned int V_68 ,
unsigned int V_69 )
{
T_1 V_70 ;
V_70 = V_71 ;
if ( V_69 == V_74 )
V_70 |= V_75 ;
V_48 |= ( V_48 >> 28 ) & 0xf0 ;
F_45 ( V_48 | V_70 , V_12 . V_76 + V_68 ) ;
}
static int F_108 ( void )
{
T_2 V_29 ;
int V_113 = F_23 ( 512 ) ;
V_29 = F_21 ( V_12 . V_13 , V_194 ) ;
V_12 . V_34 = F_22 ( V_29 , V_113 ) ;
if ( ! V_12 . V_34 )
return - V_17 ;
switch ( V_82 ) {
case 3 :
V_12 . V_37 =
F_21 ( V_12 . V_13 , V_195 ) ;
break;
case 5 :
V_12 . V_37 = V_29 + F_48 ( 2 ) ;
break;
default:
V_12 . V_37 = V_29 + F_23 ( 512 ) ;
break;
}
F_102 () ;
return 0 ;
}
static int F_109 ( T_6 V_85 )
{
struct V_196 * V_197 ;
V_197 = F_110 ( V_198 , V_85 , NULL ) ;
if ( V_197 && F_111 ( V_197 -> V_199 ) != 0 ) {
V_197 = F_110 ( V_198 ,
V_85 , V_197 ) ;
}
if ( ! V_197 )
return 0 ;
V_12 . V_13 = V_197 ;
return 1 ;
}
int F_112 ( struct V_196 * V_200 , struct V_196 * V_201 ,
struct V_23 * V_24 )
{
int V_8 , V_202 ;
if ( V_12 . V_50 ) {
V_12 . V_203 ++ ;
return 1 ;
}
for ( V_8 = 0 ; V_204 [ V_8 ] . V_191 != NULL ; V_8 ++ ) {
if ( V_201 ) {
if ( V_201 -> V_85 ==
V_204 [ V_8 ] . V_205 ) {
V_12 . V_13 = F_113 ( V_201 ) ;
V_12 . V_50 =
V_204 [ V_8 ] . V_206 ;
break;
}
} else if ( F_109 ( V_204 [ V_8 ] . V_205 ) ) {
V_12 . V_50 =
V_204 [ V_8 ] . V_206 ;
break;
}
}
if ( ! V_12 . V_50 )
return 0 ;
V_12 . V_203 ++ ;
#if F_68 ( V_148 )
if ( V_24 ) {
V_24 -> V_50 = & V_207 ;
V_24 -> V_208 = & V_12 ;
V_24 -> V_42 = V_200 ;
}
#endif
V_12 . V_83 = F_113 ( V_200 ) ;
F_27 ( & V_200 -> V_42 , L_14 , V_204 [ V_8 ] . V_191 ) ;
V_202 = V_12 . V_50 -> V_209 ;
if ( F_114 ( V_12 . V_13 , F_115 ( V_202 ) ) )
F_81 ( & V_12 . V_13 -> V_42 ,
L_15 , V_202 ) ;
else
F_116 ( V_12 . V_13 ,
F_115 ( V_202 ) ) ;
if ( F_66 () != 0 ) {
F_117 () ;
return 0 ;
}
return 1 ;
}
void F_118 ( T_5 * V_210 , T_5 * V_81 ,
T_2 * V_211 , unsigned long * V_212 )
{
* V_210 = V_12 . V_145 << V_49 ;
* V_81 = V_12 . V_81 ;
* V_211 = V_12 . V_152 ;
* V_212 = V_12 . V_128 << V_49 ;
}
void F_119 ( void )
{
if ( V_12 . V_50 -> V_213 )
V_12 . V_50 -> V_213 () ;
}
void F_117 ( void )
{
if ( -- V_12 . V_203 )
return;
if ( V_12 . V_13 )
F_120 ( V_12 . V_13 ) ;
if ( V_12 . V_83 )
F_120 ( V_12 . V_83 ) ;
V_12 . V_50 = NULL ;
}
