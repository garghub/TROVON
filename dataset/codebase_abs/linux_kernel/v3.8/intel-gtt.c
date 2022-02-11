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
F_16 ( V_1 ) ;
F_17 ( & V_27 -> V_28 ) ;
return V_1 ;
}
static void F_18 ( struct V_1 * V_1 )
{
if ( V_1 == NULL )
return;
F_14 ( V_1 , 4 ) ;
F_19 ( V_1 ) ;
F_15 ( V_1 , 2 ) ;
F_20 ( & V_27 -> V_28 ) ;
}
static int F_21 ( void )
{
T_1 V_29 ;
char * V_30 ;
V_30 = F_22 ( V_31 ) ;
if ( V_30 == NULL )
return - V_17 ;
V_12 . V_32 = V_30 ;
F_23 ( V_12 . V_13 , V_33 , & V_29 ) ;
V_29 &= 0xfff80000 ;
V_12 . V_34 = F_24 ( V_29 , F_25 ( 64 ) ) ;
if ( ! V_12 . V_34 )
return - V_17 ;
F_26 ( F_27 ( V_30 ) | V_35 ,
V_12 . V_34 + V_36 ) ;
V_12 . V_37 = V_29 + V_38 ;
if ( ( F_28 ( V_12 . V_34 + V_39 )
& V_40 ) == V_41 ) {
F_29 ( & V_12 . V_13 -> V_42 ,
L_3 ) ;
V_12 . V_43 = 1024 ;
}
return 0 ;
}
static void F_30 ( void )
{
F_26 ( 0 , V_12 . V_34 + V_36 ) ;
F_31 ( V_12 . V_32 , V_31 ) ;
}
static int F_32 ( struct V_44 * V_20 , T_2 V_45 ,
int type )
{
int V_8 ;
if ( ( V_45 + V_20 -> V_21 )
> V_12 . V_43 )
return - V_46 ;
if ( ! V_20 -> V_47 )
F_33 () ;
for ( V_8 = V_45 ; V_8 < ( V_45 + V_20 -> V_21 ) ; V_8 ++ ) {
T_3 V_48 = V_8 << V_49 ;
V_12 . V_50 -> V_51 ( V_48 ,
V_8 , type ) ;
}
F_28 ( V_12 . V_52 + V_8 - 1 ) ;
return 0 ;
}
static struct V_44 * F_34 ( T_4 V_53 , int type )
{
struct V_44 * V_54 ;
struct V_1 * V_1 ;
switch ( V_53 ) {
case 1 : V_1 = V_27 -> V_50 -> V_55 ( V_27 ) ;
break;
case 4 :
V_1 = F_11 () ;
break;
default:
return NULL ;
}
if ( V_1 == NULL )
return NULL ;
V_54 = F_35 ( V_53 ) ;
if ( V_54 == NULL )
return NULL ;
V_54 -> V_2 [ 0 ] = V_1 ;
if ( V_53 == 4 ) {
V_54 -> V_2 [ 1 ] = V_54 -> V_2 [ 0 ] + 1 ;
V_54 -> V_2 [ 2 ] = V_54 -> V_2 [ 1 ] + 1 ;
V_54 -> V_2 [ 3 ] = V_54 -> V_2 [ 2 ] + 1 ;
}
V_54 -> V_21 = V_53 ;
V_54 -> V_56 = V_53 ;
V_54 -> type = V_57 ;
V_54 -> V_58 = F_36 ( V_54 -> V_2 [ 0 ] ) ;
return V_54 ;
}
static void F_37 ( struct V_44 * V_59 )
{
F_38 ( V_59 -> V_60 ) ;
if ( V_59 -> type == V_57 ) {
if ( V_59 -> V_21 == 4 )
F_18 ( V_59 -> V_2 [ 0 ] ) ;
else {
V_27 -> V_50 -> V_61 ( V_59 -> V_2 [ 0 ] ,
V_62 ) ;
V_27 -> V_50 -> V_61 ( V_59 -> V_2 [ 0 ] ,
V_63 ) ;
}
F_39 ( V_59 ) ;
}
F_40 ( V_59 ) ;
}
static int F_41 ( void )
{
struct V_1 * V_1 ;
T_3 V_64 ;
V_1 = F_42 ( V_9 | V_26 | V_65 ) ;
if ( V_1 == NULL )
return - V_17 ;
F_16 ( V_1 ) ;
F_13 ( V_1 , 1 ) ;
if ( V_12 . V_66 . V_67 ) {
V_64 = F_43 ( V_12 . V_13 , V_1 , 0 ,
V_11 , V_16 ) ;
if ( F_44 ( V_12 . V_13 , V_64 ) )
return - V_46 ;
V_12 . V_66 . V_68 = V_64 ;
} else
V_12 . V_66 . V_68 = F_36 ( V_1 ) ;
V_12 . V_69 = V_1 ;
return 0 ;
}
static void F_45 ( T_3 V_48 , unsigned int V_70 ,
unsigned int V_71 )
{
T_1 V_72 = V_73 ;
switch ( V_71 ) {
case V_74 :
V_72 |= V_75 ;
break;
case V_76 :
V_72 |= V_77 ;
break;
}
F_26 ( V_48 | V_72 , V_12 . V_52 + V_70 ) ;
}
static unsigned int F_46 ( void )
{
T_5 V_78 ;
T_6 V_79 ;
int V_80 = 0 ;
static const int V_81 [ 4 ] = { 0 , 16 , 32 , 64 } ;
unsigned int V_82 = 0 ;
if ( V_83 == 1 )
return 0 ;
F_47 ( V_12 . V_84 ,
V_85 , & V_78 ) ;
if ( V_12 . V_84 -> V_86 == V_87 ||
V_12 . V_84 -> V_86 == V_88 ) {
switch ( V_78 & V_89 ) {
case V_90 :
V_82 = F_25 ( 512 ) ;
break;
case V_91 :
V_82 = F_48 ( 1 ) ;
break;
case V_92 :
V_82 = F_48 ( 8 ) ;
break;
case V_93 :
V_79 = F_49 ( V_12 . V_34 + V_94 ) ;
V_82 = ( F_50 ( V_79 ) + 1 ) *
F_48 ( V_81 [ F_51 ( V_79 ) ] ) ;
V_80 = 1 ;
break;
default:
V_82 = 0 ;
break;
}
} else {
switch ( V_78 & V_95 ) {
case V_96 :
V_82 = F_48 ( 1 ) ;
break;
case V_97 :
V_82 = F_48 ( 4 ) ;
break;
case V_98 :
V_82 = F_48 ( 8 ) ;
break;
case V_99 :
V_82 = F_48 ( 16 ) ;
break;
case V_100 :
V_82 = F_48 ( 32 ) ;
break;
case V_101 :
V_82 = F_48 ( 48 ) ;
break;
case V_102 :
V_82 = F_48 ( 64 ) ;
break;
case V_103 :
V_82 = F_48 ( 128 ) ;
break;
case V_104 :
V_82 = F_48 ( 256 ) ;
break;
case V_105 :
V_82 = F_48 ( 96 ) ;
break;
case V_106 :
V_82 = F_48 ( 160 ) ;
break;
case V_107 :
V_82 = F_48 ( 224 ) ;
break;
case V_108 :
V_82 = F_48 ( 352 ) ;
break;
default:
V_82 = 0 ;
break;
}
}
if ( V_82 > 0 ) {
F_29 ( & V_12 . V_84 -> V_42 , L_4 ,
V_82 / F_25 ( 1 ) , V_80 ? L_5 : L_6 ) ;
} else {
F_29 ( & V_12 . V_84 -> V_42 ,
L_7 ) ;
V_82 = 0 ;
}
return V_82 ;
}
static void F_52 ( unsigned int V_109 )
{
T_1 V_110 , V_111 ;
V_111 = F_28 ( V_12 . V_34 + V_112 ) ;
V_111 &= ~ V_35 ;
F_26 ( V_111 , V_12 . V_34 + V_112 ) ;
V_110 = F_28 ( V_12 . V_34 + V_36 ) ;
V_110 &= ~ V_113 ;
V_110 |= V_109 ;
F_26 ( V_110 , V_12 . V_34 + V_36 ) ;
}
static unsigned int F_53 ( void )
{
int V_114 ;
T_1 V_110 ;
T_5 V_115 ;
F_47 ( V_12 . V_84 ,
V_85 , & V_115 ) ;
if ( V_83 == 5 ) {
switch ( V_115 & V_116 ) {
case V_117 :
case V_118 :
F_52 ( V_119 ) ;
break;
case V_120 :
F_52 ( V_121 ) ;
break;
case V_122 :
case V_123 :
F_52 ( V_124 ) ;
break;
}
}
V_110 = F_28 ( V_12 . V_34 + V_36 ) ;
switch ( V_110 & V_113 ) {
case V_125 :
V_114 = F_25 ( 128 ) ;
break;
case V_126 :
V_114 = F_25 ( 256 ) ;
break;
case V_127 :
V_114 = F_25 ( 512 ) ;
break;
case V_119 :
V_114 = F_25 ( 1024 ) ;
break;
case V_124 :
V_114 = F_25 ( 2048 ) ;
break;
case V_121 :
V_114 = F_25 ( 1024 + 512 ) ;
break;
default:
F_29 ( & V_12 . V_13 -> V_42 ,
L_8 ) ;
V_114 = F_25 ( 512 ) ;
}
return V_114 / 4 ;
}
static unsigned int F_54 ( void )
{
if ( V_128 || V_83 == 4 || V_83 == 5 )
return F_53 () ;
else {
return V_12 . V_66 . V_129 ;
}
}
static unsigned int F_55 ( void )
{
unsigned int V_130 ;
if ( V_83 == 1 ) {
T_1 V_131 ;
F_23 ( V_12 . V_84 ,
V_132 , & V_131 ) ;
if ( ( V_131 & V_133 )
== V_134 )
V_130 = F_48 ( 32 ) ;
else
V_130 = F_48 ( 64 ) ;
} else if ( V_83 == 2 ) {
T_5 V_78 ;
F_47 ( V_12 . V_84 ,
V_85 , & V_78 ) ;
if ( ( V_78 & V_135 ) == V_136 )
V_130 = F_48 ( 64 ) ;
else
V_130 = F_48 ( 128 ) ;
} else {
V_130 = F_56 ( V_12 . V_13 , 2 ) ;
}
return V_130 >> V_49 ;
}
static void F_57 ( void )
{
F_14 ( V_12 . V_69 , 1 ) ;
F_58 ( V_12 . V_13 , V_12 . V_66 . V_68 ,
V_11 , V_16 ) ;
F_19 ( V_12 . V_69 ) ;
F_59 ( V_12 . V_69 ) ;
}
static void F_60 ( void )
{
V_12 . V_50 -> V_137 () ;
F_61 ( V_12 . V_52 ) ;
F_61 ( V_12 . V_34 ) ;
F_57 () ;
}
static int F_62 ( void )
{
T_1 V_138 ;
T_1 V_139 ;
int V_140 ;
V_140 = V_12 . V_50 -> V_141 () ;
if ( V_140 != 0 )
return V_140 ;
V_12 . V_66 . V_129 = F_55 () ;
V_12 . V_66 . V_142 = F_54 () ;
V_12 . V_143 =
F_28 ( V_12 . V_34 + V_36 )
& ~ V_35 ;
if ( V_144 )
V_12 . V_143 |= V_35 ;
F_29 ( & V_12 . V_84 -> V_42 ,
L_9 ,
V_12 . V_66 . V_142 * 4 ,
V_12 . V_66 . V_129 * 4 ) ;
V_139 = V_12 . V_66 . V_142 * 4 ;
V_12 . V_52 = NULL ;
if ( V_83 < 6 && V_83 > 2 )
V_12 . V_52 = F_63 ( V_12 . V_37 ,
V_139 ) ;
if ( V_12 . V_52 == NULL )
V_12 . V_52 = F_24 ( V_12 . V_37 ,
V_139 ) ;
if ( V_12 . V_52 == NULL ) {
V_12 . V_50 -> V_137 () ;
F_61 ( V_12 . V_34 ) ;
return - V_17 ;
}
V_12 . V_66 . V_52 = V_12 . V_52 ;
F_33 () ;
V_12 . V_66 . V_82 = F_46 () ;
V_12 . V_66 . V_67 = V_145 && V_83 > 2 ;
V_140 = F_41 () ;
if ( V_140 != 0 ) {
F_60 () ;
return V_140 ;
}
if ( V_83 <= 2 )
F_23 ( V_12 . V_13 , V_146 ,
& V_138 ) ;
else
F_23 ( V_12 . V_13 , V_147 ,
& V_138 ) ;
V_12 . V_66 . V_148 = ( V_138 & V_149 ) ;
return 0 ;
}
static int F_64 ( void )
{
int V_150 = F_65 ( V_151 ) ;
unsigned int V_152 ;
int V_8 ;
V_152 = ( V_12 . V_66 . V_129 << V_49 )
/ F_48 ( 1 ) ;
for ( V_8 = 0 ; V_8 < V_150 ; V_8 ++ ) {
if ( V_152 == V_151 [ V_8 ] . V_114 ) {
V_27 -> V_153 =
( void * ) ( V_151 + V_8 ) ;
return V_152 ;
}
}
return 0 ;
}
static void F_66 ( void )
{
}
static void F_67 ( void )
{
unsigned long V_154 = V_155 + F_68 ( 1000 ) ;
F_69 () ;
F_26 ( F_28 ( V_12 . V_34 + V_156 ) | ( 1 << 31 ) ,
V_12 . V_34 + V_156 ) ;
while ( F_28 ( V_12 . V_34 + V_156 ) & ( 1 << 31 ) ) {
if ( F_70 ( V_155 , V_154 ) )
break;
F_71 ( 50 ) ;
}
}
static void F_72 ( T_3 V_48 , unsigned int V_70 ,
unsigned int V_71 )
{
T_1 V_72 = V_73 ;
if ( V_71 == V_76 )
V_72 |= V_77 ;
F_26 ( V_48 | V_72 , V_12 . V_52 + V_70 ) ;
}
bool F_73 ( void )
{
T_6 T_7 * V_157 ;
if ( V_83 == 2 ) {
T_5 V_78 ;
F_47 ( V_12 . V_84 ,
V_85 , & V_78 ) ;
V_78 |= V_158 ;
F_74 ( V_12 . V_84 ,
V_85 , V_78 ) ;
F_47 ( V_12 . V_84 ,
V_85 , & V_78 ) ;
if ( ( V_78 & V_158 ) == 0 ) {
F_75 ( & V_12 . V_13 -> V_42 ,
L_10 ,
V_78 ) ;
return false ;
}
}
if ( V_83 >= 3 )
F_26 ( 0 , V_12 . V_34 + V_159 ) ;
V_157 = V_12 . V_34 + V_36 ;
F_26 ( V_12 . V_143 , V_157 ) ;
if ( V_144 && ( F_28 ( V_157 ) & V_35 ) == 0 ) {
F_75 ( & V_12 . V_13 -> V_42 ,
L_11 ,
F_28 ( V_157 ) , V_12 . V_143 ) ;
return false ;
}
if ( V_83 >= 3 )
F_26 ( 0 , V_12 . V_34 + V_159 ) ;
return true ;
}
static int F_76 ( void )
{
T_1 V_29 ;
F_23 ( V_12 . V_13 , V_33 , & V_29 ) ;
V_29 &= 0xfff80000 ;
V_12 . V_34 = F_24 ( V_29 , F_25 ( 64 ) ) ;
if ( ! V_12 . V_34 )
return - V_17 ;
V_12 . V_37 = V_29 + V_38 ;
return 0 ;
}
static int F_77 ( struct V_23 * V_24 )
{
V_27 -> V_160 = NULL ;
V_27 -> V_161 = NULL ;
V_27 -> V_162 = 0 ;
return 0 ;
}
static int F_78 ( struct V_23 * V_24 )
{
return 0 ;
}
static int F_79 ( void )
{
if ( ! F_73 () )
return - V_163 ;
V_12 . V_164 = true ;
V_27 -> V_165 = V_12 . V_66 . V_148 ;
return 0 ;
}
static bool F_80 ( unsigned int V_71 )
{
switch ( V_71 ) {
case 0 :
case V_57 :
case V_76 :
case V_166 :
return true ;
}
return false ;
}
void F_81 ( struct V_4 * V_5 ,
unsigned int V_45 ,
unsigned int V_71 )
{
struct V_6 * V_7 ;
unsigned int V_167 , V_168 ;
int V_8 , V_169 ;
V_169 = V_45 ;
F_4 (st->sgl, sg, st->nents, i) {
V_167 = F_82 ( V_7 ) >> V_49 ;
for ( V_168 = 0 ; V_168 < V_167 ; V_168 ++ ) {
T_3 V_48 = F_83 ( V_7 ) + ( V_168 << V_49 ) ;
V_12 . V_50 -> V_51 ( V_48 , V_169 , V_71 ) ;
V_169 ++ ;
}
}
F_28 ( V_12 . V_52 + V_169 - 1 ) ;
}
static void F_84 ( unsigned int V_170 ,
unsigned int V_3 ,
struct V_1 * * V_2 ,
unsigned int V_71 )
{
int V_8 , V_169 ;
for ( V_8 = 0 , V_169 = V_170 ; V_8 < V_3 ; V_8 ++ , V_169 ++ ) {
T_3 V_48 = F_36 ( V_2 [ V_8 ] ) ;
V_12 . V_50 -> V_51 ( V_48 ,
V_169 , V_71 ) ;
}
F_28 ( V_12 . V_52 + V_169 - 1 ) ;
}
static int F_85 ( struct V_44 * V_20 ,
T_2 V_45 , int type )
{
int V_140 = - V_46 ;
if ( V_12 . V_66 . V_171 )
return - V_172 ;
if ( V_12 . V_164 ) {
int V_173 = V_12 . V_66 . V_82 / V_11 ;
int V_174 = V_12 . V_66 . V_129 ;
F_86 ( V_173 , V_174 - V_173 ) ;
V_12 . V_164 = false ;
}
if ( V_83 == 1 && type == V_74 )
return F_32 ( V_20 , V_45 , type ) ;
if ( V_20 -> V_21 == 0 )
goto V_175;
if ( V_45 + V_20 -> V_21 > V_12 . V_66 . V_142 )
goto V_176;
if ( type != V_20 -> type )
goto V_176;
if ( ! V_12 . V_50 -> V_177 ( type ) )
goto V_176;
if ( ! V_20 -> V_47 )
F_33 () ;
if ( V_12 . V_66 . V_67 ) {
struct V_4 V_5 ;
V_140 = F_1 ( V_20 -> V_2 , V_20 -> V_21 , & V_5 ) ;
if ( V_140 != 0 )
return V_140 ;
F_81 ( & V_5 , V_45 , type ) ;
V_20 -> V_18 = V_5 . V_14 ;
V_20 -> V_19 = V_5 . V_15 ;
} else
F_84 ( V_45 , V_20 -> V_21 , V_20 -> V_2 ,
type ) ;
V_175:
V_140 = 0 ;
V_176:
V_20 -> V_47 = true ;
return V_140 ;
}
void F_86 ( unsigned int V_170 , unsigned int V_3 )
{
unsigned int V_8 ;
for ( V_8 = V_170 ; V_8 < ( V_170 + V_3 ) ; V_8 ++ ) {
V_12 . V_50 -> V_51 ( V_12 . V_66 . V_68 ,
V_8 , 0 ) ;
}
F_28 ( V_12 . V_52 + V_8 - 1 ) ;
}
static int F_87 ( struct V_44 * V_20 ,
T_2 V_45 , int type )
{
if ( V_20 -> V_21 == 0 )
return 0 ;
if ( V_12 . V_66 . V_171 )
return - V_172 ;
F_86 ( V_45 , V_20 -> V_21 ) ;
if ( V_12 . V_66 . V_67 ) {
F_8 ( V_20 -> V_18 , V_20 -> V_19 ) ;
V_20 -> V_18 = NULL ;
V_20 -> V_19 = 0 ;
}
return 0 ;
}
static struct V_44 * F_88 ( T_4 V_53 ,
int type )
{
struct V_44 * V_54 ;
if ( type == V_74 && V_83 == 1 ) {
if ( V_53 != V_12 . V_43 )
return NULL ;
V_54 = F_35 ( 1 ) ;
if ( V_54 == NULL )
return NULL ;
V_54 -> type = V_74 ;
V_54 -> V_21 = V_53 ;
V_54 -> V_56 = 0 ;
F_39 ( V_54 ) ;
return V_54 ;
}
if ( type == V_57 )
return F_34 ( V_53 , type ) ;
return NULL ;
}
static int F_89 ( void )
{
int V_140 ;
V_140 = F_90 ( V_12 . V_84 -> V_178 , & V_12 . V_179 , V_11 ,
V_11 , V_180 , 0 ,
V_181 , V_12 . V_84 ) ;
return V_140 ;
}
static void F_91 ( void )
{
int V_140 ;
T_1 V_182 ;
F_23 ( V_12 . V_84 , V_183 , & V_182 ) ;
if ( ! ( V_182 & 0x1 ) ) {
F_89 () ;
V_12 . V_184 = 1 ;
F_92 ( V_12 . V_84 , V_183 , ( V_12 . V_179 . V_173 & 0xffffffff ) | 0x1 ) ;
} else {
V_182 &= ~ 1 ;
V_12 . V_184 = 1 ;
V_12 . V_179 . V_173 = V_182 ;
V_12 . V_179 . V_174 = V_182 + V_11 ;
V_140 = F_93 ( & V_185 , & V_12 . V_179 ) ;
if ( V_140 )
V_12 . V_184 = 0 ;
}
}
static void F_94 ( void )
{
T_1 V_186 , V_187 ;
int V_140 ;
F_23 ( V_12 . V_84 , V_188 + 4 , & V_186 ) ;
F_23 ( V_12 . V_84 , V_188 , & V_187 ) ;
if ( ! ( V_187 & 0x1 ) ) {
F_89 () ;
V_12 . V_184 = 1 ;
F_92 ( V_12 . V_84 , V_188 + 4 ,
F_95 ( V_12 . V_179 . V_173 ) ) ;
F_92 ( V_12 . V_84 , V_188 , ( V_12 . V_179 . V_173 & 0xffffffff ) | 0x1 ) ;
} else {
T_8 V_189 ;
V_187 &= ~ 0x1 ;
V_189 = ( ( T_8 ) V_186 << 32 ) | V_187 ;
V_12 . V_184 = 1 ;
V_12 . V_179 . V_173 = V_189 ;
V_12 . V_179 . V_174 = V_189 + V_11 ;
V_140 = F_93 ( & V_185 , & V_12 . V_179 ) ;
if ( V_140 )
V_12 . V_184 = 0 ;
}
}
static void F_96 ( void )
{
if ( V_12 . V_179 . V_173 )
return;
if ( V_83 == 6 )
return;
V_12 . V_179 . V_190 = L_12 ;
V_12 . V_179 . V_71 = V_191 ;
if ( V_128 || V_83 >= 4 ) {
F_94 () ;
} else {
F_91 () ;
}
if ( V_12 . V_179 . V_173 )
V_12 . V_192 = F_97 ( V_12 . V_179 . V_173 , V_11 ) ;
if ( ! V_12 . V_192 )
F_75 ( & V_12 . V_13 -> V_42 ,
L_13 ) ;
}
static void F_98 ( void )
{
if ( V_12 . V_192 )
F_61 ( V_12 . V_192 ) ;
if ( V_12 . V_184 )
F_99 ( & V_12 . V_179 ) ;
V_12 . V_179 . V_173 = 0 ;
V_12 . V_184 = 0 ;
}
static void F_100 ( void )
{
if ( V_12 . V_192 )
F_26 ( 1 , V_12 . V_192 ) ;
}
static void F_101 ( T_3 V_48 ,
unsigned int V_70 ,
unsigned int V_71 )
{
T_1 V_72 ;
V_72 = V_73 ;
if ( V_71 == V_76 )
V_72 |= V_77 ;
V_48 |= ( V_48 >> 28 ) & 0xf0 ;
F_26 ( V_48 | V_72 , V_12 . V_52 + V_70 ) ;
}
static inline int F_102 ( void )
{
#ifdef F_103
const unsigned short V_193 = V_12 . V_13 -> V_86 ;
if ( ( V_193 == V_194 ||
V_193 == V_195 ) &&
V_196 )
return 1 ;
#endif
return 0 ;
}
static int F_104 ( void )
{
T_1 V_29 , V_197 ;
int V_114 = F_25 ( 512 ) ;
F_23 ( V_12 . V_13 , V_198 , & V_29 ) ;
V_29 &= 0xfff80000 ;
V_12 . V_34 = F_24 ( V_29 , V_114 ) ;
if ( ! V_12 . V_34 )
return - V_17 ;
switch ( V_83 ) {
case 3 :
F_23 ( V_12 . V_13 ,
V_199 , & V_197 ) ;
V_12 . V_37 = V_197 ;
break;
case 5 :
V_12 . V_37 = V_29 + F_48 ( 2 ) ;
break;
default:
V_12 . V_37 = V_29 + F_25 ( 512 ) ;
break;
}
if ( F_102 () )
V_12 . V_66 . V_171 = 1 ;
F_96 () ;
return 0 ;
}
static int F_105 ( T_5 V_86 )
{
struct V_200 * V_201 ;
V_201 = F_106 ( V_202 , V_86 , NULL ) ;
if ( V_201 && F_107 ( V_201 -> V_203 ) != 0 ) {
V_201 = F_106 ( V_202 ,
V_86 , V_201 ) ;
}
if ( ! V_201 )
return 0 ;
V_12 . V_13 = V_201 ;
return 1 ;
}
int F_108 ( struct V_200 * V_204 , struct V_200 * V_205 ,
struct V_23 * V_24 )
{
int V_8 , V_206 ;
if ( V_12 . V_50 ) {
V_12 . V_207 ++ ;
return 1 ;
}
for ( V_8 = 0 ; V_208 [ V_8 ] . V_190 != NULL ; V_8 ++ ) {
if ( V_205 ) {
if ( V_205 -> V_86 ==
V_208 [ V_8 ] . V_209 ) {
V_12 . V_13 = F_109 ( V_205 ) ;
V_12 . V_50 =
V_208 [ V_8 ] . V_210 ;
break;
}
} else if ( F_105 ( V_208 [ V_8 ] . V_209 ) ) {
V_12 . V_50 =
V_208 [ V_8 ] . V_210 ;
break;
}
}
if ( ! V_12 . V_50 )
return 0 ;
V_12 . V_207 ++ ;
if ( V_24 ) {
V_24 -> V_50 = & V_211 ;
V_24 -> V_212 = & V_12 ;
V_24 -> V_42 = V_204 ;
}
V_12 . V_84 = F_109 ( V_204 ) ;
F_29 ( & V_204 -> V_42 , L_14 , V_208 [ V_8 ] . V_190 ) ;
V_206 = V_12 . V_50 -> V_213 ;
if ( F_110 ( V_12 . V_13 , F_111 ( V_206 ) ) )
F_75 ( & V_12 . V_13 -> V_42 ,
L_15 , V_206 ) ;
else
F_112 ( V_12 . V_13 ,
F_111 ( V_206 ) ) ;
if ( F_62 () != 0 ) {
F_113 () ;
return 0 ;
}
return 1 ;
}
struct V_214 * F_114 ( void )
{
return & V_12 . V_66 ;
}
void F_115 ( void )
{
if ( V_12 . V_50 -> V_215 )
V_12 . V_50 -> V_215 () ;
}
void F_113 ( void )
{
if ( -- V_12 . V_207 )
return;
if ( V_12 . V_13 )
F_116 ( V_12 . V_13 ) ;
if ( V_12 . V_84 )
F_116 ( V_12 . V_84 ) ;
V_12 . V_50 = NULL ;
}
