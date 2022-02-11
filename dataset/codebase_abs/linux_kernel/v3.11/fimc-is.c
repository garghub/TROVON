static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
if ( F_2 ( V_2 -> V_5 [ V_3 ] ) )
continue;
F_3 ( V_2 -> V_5 [ V_3 ] ) ;
V_2 -> V_5 [ V_3 ] = F_4 ( - V_6 ) ;
}
}
static int F_5 ( struct V_1 * V_2 )
{
int V_3 , V_7 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ )
V_2 -> V_5 [ V_3 ] = F_4 ( - V_6 ) ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
V_2 -> V_5 [ V_3 ] = F_6 ( & V_2 -> V_8 -> V_9 , V_10 [ V_3 ] ) ;
if ( F_2 ( V_2 -> V_5 [ V_3 ] ) ) {
V_7 = F_7 ( V_2 -> V_5 [ V_3 ] ) ;
goto V_11;
}
}
return 0 ;
V_11:
F_1 ( V_2 ) ;
F_8 ( & V_2 -> V_8 -> V_9 , L_1 ,
V_10 [ V_3 ] ) ;
return V_7 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_7 ;
V_7 = F_10 ( V_2 -> V_5 [ V_12 ] ,
V_2 -> V_5 [ V_13 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_10 ( V_2 -> V_5 [ V_14 ] ,
V_2 -> V_5 [ V_15 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_11 ( V_2 -> V_5 [ V_16 ] , V_17 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_11 ( V_2 -> V_5 [ V_18 ] , V_17 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_11 ( V_2 -> V_5 [ V_19 ] ,
V_20 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_11 ( V_2 -> V_5 [ V_21 ] ,
V_20 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_3 , V_7 ;
for ( V_3 = 0 ; V_3 < V_22 ; V_3 ++ ) {
if ( F_2 ( V_2 -> V_5 [ V_3 ] ) )
continue;
V_7 = F_13 ( V_2 -> V_5 [ V_3 ] ) ;
if ( V_7 < 0 ) {
F_8 ( & V_2 -> V_8 -> V_9 , L_2 ,
V_10 [ V_3 ] ) ;
for ( -- V_3 ; V_3 >= 0 ; V_3 -- )
F_14 ( V_2 -> V_5 [ V_3 ] ) ;
return V_7 ;
}
F_15 ( L_3 , V_10 [ V_3 ] ) ;
}
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_22 ; V_3 ++ ) {
if ( ! F_2 ( V_2 -> V_5 [ V_3 ] ) ) {
F_17 ( V_2 -> V_5 [ V_3 ] ) ;
F_15 ( L_4 , V_10 [ V_3 ] ) ;
}
}
}
static int F_18 ( struct V_23 * V_24 ,
struct V_25 * V_26 )
{
T_1 V_27 = 0 ;
int V_7 ;
V_26 = F_19 ( V_26 , NULL ) ;
if ( ! V_26 )
return - V_28 ;
V_26 = F_20 ( V_26 ) ;
if ( ! V_26 )
return - V_28 ;
V_7 = F_21 ( V_26 , L_5 , & V_27 ) ;
V_24 -> V_29 = V_27 - V_30 ;
return V_7 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_25 * V_31 , * V_32 ;
int V_7 ;
V_7 = F_23 ( & V_2 -> V_33 ) ;
if ( V_7 < 0 )
return V_7 ;
F_24 (adapter, NULL, FIMC_IS_I2C_COMPATIBLE) {
if ( ! F_25 ( V_31 ) ) {
F_26 ( V_31 ) ;
return - V_34 ;
}
F_27 (adapter, child) {
struct V_35 * V_36 ;
struct V_37 * V_38 ;
V_36 = F_28 ( V_32 ) ;
if ( ! V_36 )
goto V_39;
V_38 = F_29 ( V_36 ) ;
if ( ! V_38 )
goto V_39;
if ( F_30 ( V_2 -> V_24 ) )
continue;
V_2 -> V_24 = F_31 ( V_38 ) ;
if ( F_18 ( V_2 -> V_24 , V_32 ) ) {
F_32 ( & V_2 -> V_8 -> V_9 , L_6 ,
V_32 -> V_40 ) ;
}
F_15 ( L_7 ,
V_41 , V_38 -> V_42 ) ;
}
}
return 0 ;
V_39:
F_26 ( V_32 ) ;
return - V_34 ;
}
static int F_33 ( struct V_1 * V_2 )
{
F_34 ( & V_2 -> V_33 ) ;
V_2 -> V_24 = NULL ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , char * V_43 )
{
const struct V_44 * V_45 ;
void * V_46 ;
int V_7 ;
V_7 = F_36 ( & V_45 , V_43 , & V_2 -> V_8 -> V_9 ) ;
if ( V_7 < 0 ) {
F_8 ( & V_2 -> V_8 -> V_9 , L_8 , V_7 ) ;
return V_7 ;
}
V_46 = V_2 -> V_47 . V_48 + V_2 -> V_49 . V_50 ;
memcpy ( V_46 , V_45 -> V_51 , V_45 -> V_52 ) ;
F_37 () ;
V_2 -> V_49 . V_52 = V_45 -> V_52 ;
F_15 ( L_9 , V_2 -> V_47 . V_48 , V_46 ) ;
memcpy ( V_2 -> V_45 . V_53 ,
V_45 -> V_51 + V_45 -> V_52 - V_54 ,
V_54 - 1 ) ;
V_2 -> V_45 . V_53 [ V_54 - 1 ] = '\0' ;
V_2 -> V_49 . V_55 = 1 ;
F_15 ( L_10 ,
V_2 -> V_49 . V_50 , V_45 -> V_52 ) ;
F_38 ( V_45 ) ;
return V_7 ;
}
int F_39 ( struct V_1 * V_2 , int V_56 )
{
unsigned int V_57 = V_58 ;
if ( V_56 ) {
F_40 ( 0 , V_2 , V_59 ) ;
F_40 ( V_2 -> V_47 . V_60 , V_2 , V_61 ) ;
F_41 ( 0x18000 , V_2 , V_62 ) ;
F_41 ( 0x1 , V_2 , V_63 ) ;
} else {
F_41 ( 0x10000 , V_2 , V_62 ) ;
F_41 ( 0x0 , V_2 , V_63 ) ;
while ( F_42 ( V_2 , V_64 ) & 1 ) {
if ( V_57 == 0 )
return - V_65 ;
V_57 -- ;
F_43 ( 1 ) ;
}
}
return 0 ;
}
int F_44 ( struct V_1 * V_2 , unsigned long V_66 ,
unsigned int V_55 , unsigned int V_57 )
{
int V_7 = F_45 ( V_2 -> V_67 ,
! V_55 ^ F_46 ( V_66 , & V_2 -> V_55 ) ,
V_57 ) ;
if ( V_7 == 0 ) {
F_47 ( & V_2 -> V_8 -> V_9 , L_11 , V_41 ) ;
return - V_65 ;
}
return 0 ;
}
int F_48 ( struct V_1 * V_2 )
{
struct V_68 * V_9 = & V_2 -> V_8 -> V_9 ;
int V_7 ;
if ( V_2 -> V_45 . V_69 == NULL ) {
F_8 ( V_9 , L_12 ) ;
return - V_6 ;
}
memcpy ( V_2 -> V_47 . V_48 , V_2 -> V_45 . V_69 -> V_51 , V_2 -> V_45 . V_69 -> V_52 ) ;
F_49 () ;
V_7 = F_39 ( V_2 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_44 ( V_2 , V_70 , 1 ,
F_50 ( V_71 ) ) ;
if ( V_7 < 0 )
F_8 ( V_9 , L_13 ) ;
return V_7 ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_68 * V_9 = & V_2 -> V_8 -> V_9 ;
V_2 -> V_47 . V_48 = F_52 ( V_9 , V_72 ,
& V_2 -> V_47 . V_60 , V_73 ) ;
if ( V_2 -> V_47 . V_48 == NULL )
return - V_74 ;
V_2 -> V_47 . V_52 = V_72 ;
memset ( V_2 -> V_47 . V_48 , 0 , V_2 -> V_47 . V_52 ) ;
F_53 ( V_9 , L_14 , ( T_1 ) V_2 -> V_47 . V_60 ) ;
if ( ( ( T_1 ) V_2 -> V_47 . V_60 ) & V_75 ) {
F_8 ( V_9 , L_15 ,
( T_1 ) V_2 -> V_47 . V_60 ) ;
F_54 ( V_9 , V_2 -> V_47 . V_52 , V_2 -> V_47 . V_48 ,
V_2 -> V_47 . V_60 ) ;
return - V_76 ;
}
V_2 -> V_77 = (struct V_78 * ) ( V_2 -> V_47 . V_48 +
V_72 - V_79 ) ;
V_2 -> V_80 = V_2 -> V_47 . V_60 +
V_72 - V_79 ;
V_2 -> V_81 = (struct V_82 * ) ( V_2 -> V_47 . V_48 +
V_83 ) ;
return 0 ;
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_68 * V_9 = & V_2 -> V_8 -> V_9 ;
F_54 ( V_9 , V_2 -> V_47 . V_52 , V_2 -> V_47 . V_48 ,
V_2 -> V_47 . V_60 ) ;
}
static void F_56 ( const struct V_44 * V_45 , void * V_84 )
{
struct V_1 * V_2 = V_84 ;
struct V_68 * V_9 = & V_2 -> V_8 -> V_9 ;
void * V_46 ;
int V_7 ;
if ( V_45 == NULL ) {
F_8 ( V_9 , L_16 ) ;
return;
}
F_57 ( & V_2 -> V_85 ) ;
if ( V_45 -> V_52 < V_86 || V_45 -> V_52 > V_87 ) {
F_8 ( V_9 , L_17 , V_45 -> V_52 ) ;
goto V_88;
}
V_2 -> V_45 . V_52 = V_45 -> V_52 ;
V_7 = F_51 ( V_2 ) ;
if ( V_7 < 0 ) {
F_8 ( V_9 , L_18 ) ;
goto V_88;
}
memcpy ( V_2 -> V_47 . V_48 , V_45 -> V_51 , V_45 -> V_52 ) ;
F_49 () ;
V_46 = ( void * ) ( V_2 -> V_47 . V_48 + V_45 -> V_52 - V_89 ) ;
memcpy ( & V_2 -> V_45 . V_90 , V_46 , V_91 ) ;
V_2 -> V_45 . V_90 [ V_91 ] = 0 ;
V_46 = ( void * ) ( V_2 -> V_47 . V_48 + V_45 -> V_52 - V_92 ) ;
memcpy ( & V_2 -> V_45 . V_93 , V_46 , V_92 ) ;
V_2 -> V_45 . V_93 [ V_92 - 1 ] = 0 ;
V_2 -> V_45 . V_55 = 1 ;
F_53 ( V_9 , L_19 ,
V_2 -> V_45 . V_90 , V_2 -> V_45 . V_93 ) ;
F_58 ( V_9 , L_20 , V_45 -> V_52 , V_2 -> V_47 . V_60 ) ;
V_2 -> V_81 -> V_94 = 0xe4412 ;
V_2 -> V_81 -> V_95 = 1 ;
F_37 () ;
if ( V_2 -> V_45 . V_69 )
F_38 ( V_2 -> V_45 . V_69 ) ;
V_2 -> V_45 . V_69 = V_45 ;
V_88:
F_59 ( & V_2 -> V_85 ) ;
}
static int F_60 ( struct V_1 * V_2 , const char * V_96 )
{
return F_61 ( V_97 ,
V_98 , V_96 , & V_2 -> V_8 -> V_9 ,
V_73 , V_2 , F_56 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
V_2 -> V_99 . V_100 = F_63 ( V_2 , F_64 ( 10 ) ) ;
switch ( V_2 -> V_99 . V_100 ) {
case V_101 :
F_65 ( V_2 , 1 ) ;
F_66 ( V_2 ) ;
F_67 ( V_2 ) ;
F_15 ( L_21 , V_2 -> V_99 . args [ 0 ] ) ;
break;
case V_102 :
case V_103 :
F_65 ( V_2 , 2 ) ;
break;
case V_104 :
case V_105 :
case V_106 :
F_65 ( V_2 , 3 ) ;
break;
case V_107 :
F_65 ( V_2 , 4 ) ;
break;
case V_108 :
break;
default:
F_68 ( L_22 , V_2 -> V_99 . V_100 ) ;
}
F_69 ( V_2 , V_109 ) ;
switch ( V_2 -> V_99 . V_100 ) {
case V_101 :
F_70 ( V_2 ) ;
F_71 ( V_70 , & V_2 -> V_55 ) ;
break;
case V_104 :
break;
case V_102 :
V_2 -> V_110 . V_111 = V_2 -> V_99 . args [ 0 ] ;
V_2 -> V_110 . V_112 = V_2 -> V_99 . args [ 1 ] ;
V_2 -> V_110 . V_113 = 0 ;
break;
case V_103 :
break;
case V_105 :
F_15 ( L_23 , V_2 -> V_99 . args [ 0 ] ,
V_2 -> V_99 . args [ 1 ] , V_2 -> V_99 . args [ 2 ] ) ;
break;
case V_106 :
F_15 ( L_24 , V_2 -> V_99 . args [ 0 ] ) ;
switch ( V_2 -> V_99 . args [ 0 ] ) {
case V_114 ... V_115 :
F_71 ( V_116 , & V_2 -> V_55 ) ;
V_2 -> V_33 . V_117 = V_2 -> V_99 . args [ 1 ] ;
V_2 -> V_33 . V_118 = V_2 -> V_99 . args [ 2 ] ;
F_15 ( L_25 ,
V_2 -> V_33 . V_117 , V_2 -> V_33 . V_118 ) ;
break;
case V_119 :
F_72 ( V_120 , & V_2 -> V_55 ) ;
F_71 ( V_121 , & V_2 -> V_55 ) ;
break;
case V_122 :
F_72 ( V_121 , & V_2 -> V_55 ) ;
F_71 ( V_120 , & V_2 -> V_55 ) ;
break;
case V_123 :
V_2 -> V_124 [ V_2 -> V_125 ] . V_126 [ 0 ] = 0 ;
V_2 -> V_124 [ V_2 -> V_125 ] . V_126 [ 1 ] = 0 ;
F_71 ( V_127 , & V_2 -> V_55 ) ;
F_15 ( L_26 ) ;
break;
case V_128 :
break;
case V_129 :
break;
case V_130 :
break;
case V_131 :
F_71 ( V_132 , & V_2 -> V_55 ) ;
F_15 ( L_27 ,
V_2 -> V_99 . args [ 2 ] , V_2 -> V_99 . args [ 1 ] ) ;
break;
case V_133 :
F_72 ( V_132 , & V_2 -> V_55 ) ;
V_2 -> V_134 = 0 ;
break;
case V_135 :
F_15 ( L_28 ) ;
break;
case V_136 :
F_72 ( V_137 , & V_2 -> V_55 ) ;
break;
case V_138 :
V_2 -> V_49 . V_50 = V_2 -> V_99 . args [ 1 ] ;
F_71 ( V_139 , & V_2 -> V_55 ) ;
break;
case V_140 :
F_71 ( V_139 , & V_2 -> V_55 ) ;
break;
}
break;
case V_107 :
F_73 ( L_29 , V_2 -> V_99 . args [ 0 ] ,
V_2 -> V_99 . args [ 1 ] ,
F_74 ( V_2 -> V_99 . args [ 1 ] ) ) ;
if ( V_2 -> V_99 . args [ 1 ] & V_141 )
F_73 ( L_30 ) ;
switch ( V_2 -> V_99 . args [ 1 ] ) {
case V_142 :
F_37 () ;
}
switch ( V_2 -> V_99 . args [ 0 ] ) {
case V_123 :
V_2 -> V_124 [ V_2 -> V_125 ] . V_126 [ 0 ] = 0 ;
V_2 -> V_124 [ V_2 -> V_125 ] . V_126 [ 1 ] = 0 ;
F_71 ( V_127 , & V_2 -> V_55 ) ;
break;
}
break;
case V_108 :
F_73 ( L_31 ) ;
break;
}
F_75 ( & V_2 -> V_67 ) ;
}
static T_2 F_76 ( int V_143 , void * V_144 )
{
struct V_1 * V_2 = V_144 ;
unsigned long V_145 ;
T_1 V_146 ;
F_77 ( & V_2 -> V_147 , V_145 ) ;
V_146 = F_63 ( V_2 , V_148 ) ;
if ( V_146 & ( 1UL << V_109 ) )
F_62 ( V_2 ) ;
if ( V_146 & ( 1UL << V_149 ) )
F_78 ( V_2 ) ;
F_79 ( & V_2 -> V_147 , V_145 ) ;
return V_150 ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_151 * V_152 = ( void * ) & V_2 -> V_77 -> V_153 ;
F_66 ( V_2 ) ;
V_152 -> V_154 = 1 ;
V_152 -> V_155 = 0 ;
V_152 -> V_156 = 0 ;
V_152 -> V_157 = 0 ;
V_152 -> V_158 = 0 ;
V_152 -> V_159 = 0 ;
V_152 -> V_160 = 88000000 ;
F_37 () ;
F_40 ( V_131 , V_2 , F_64 ( 0 ) ) ;
F_40 ( V_2 -> V_134 , V_2 , F_64 ( 1 ) ) ;
F_40 ( V_24 -> V_161 -> V_162 , V_2 , F_64 ( 2 ) ) ;
F_40 ( V_24 -> V_29 , V_2 , F_64 ( 3 ) ) ;
F_40 ( V_2 -> V_80 , V_2 , F_64 ( 4 ) ) ;
F_70 ( V_2 ) ;
return F_44 ( V_2 , V_132 , 1 ,
V_163 ) ;
}
int F_81 ( struct V_1 * V_2 )
{
const int V_164 [] = {
V_165 , V_166 ,
V_167 , V_168
} ;
struct V_68 * V_9 = & V_2 -> V_8 -> V_9 ;
T_1 V_169 ;
int V_3 , V_7 ;
V_7 = F_80 ( V_2 , V_2 -> V_24 ) ;
if ( V_7 < 0 )
return V_7 ;
F_82 ( V_2 ) ;
V_7 = F_44 ( V_2 , V_139 , 1 ,
V_170 ) ;
if ( V_7 < 0 ) {
F_8 ( V_9 , L_32 ) ;
return V_7 ;
}
F_15 ( L_33 , V_2 -> V_49 . V_50 ) ;
F_35 ( V_2 , V_171 ) ;
F_72 ( V_139 , & V_2 -> V_55 ) ;
F_83 ( V_2 ) ;
V_7 = F_44 ( V_2 , V_139 , 1 ,
V_170 ) ;
if ( V_7 < 0 ) {
F_8 ( V_9 , L_34 ) ;
return V_7 ;
}
F_15 ( L_35 ,
V_2 -> V_49 . V_50 , V_2 -> V_49 . V_52 ) ;
F_68 ( L_36 , V_2 -> V_45 . V_53 ) ;
if ( V_2 -> V_77 -> V_153 [ V_172 - 1 ] !=
V_173 ) {
F_8 ( V_9 , L_37 ) ;
return - V_76 ;
}
F_15 ( L_38 ,
V_2 -> V_47 . V_60 + V_83 ,
V_2 -> V_80 ) ;
V_2 -> V_49 . V_174 = 0 ;
F_84 ( V_2 ) ;
V_7 = F_44 ( V_2 , V_120 , 1 ,
V_170 ) ;
if ( V_7 < 0 ) {
F_8 ( V_9 , L_39 ) ;
return V_7 ;
}
V_169 = V_2 -> V_125 ;
for ( V_3 = 0 ; V_3 < F_85 ( V_164 ) ; V_3 ++ ) {
V_2 -> V_125 = V_164 [ V_3 ] ;
F_86 ( V_2 ) ;
V_7 = F_87 ( V_2 , true ) ;
if ( V_7 < 0 ) {
V_2 -> V_125 = V_169 ;
return V_7 ;
}
}
V_2 -> V_125 = V_169 ;
F_71 ( V_175 , & V_2 -> V_55 ) ;
F_53 ( V_9 , L_40 ,
V_2 -> V_125 ) ;
return 0 ;
}
static int F_88 ( struct V_176 * V_177 , void * V_51 )
{
struct V_1 * V_2 = V_177 -> V_178 ;
const T_3 * V_46 = V_2 -> V_47 . V_48 + V_179 ;
if ( V_2 -> V_47 . V_48 == NULL ) {
F_8 ( & V_2 -> V_8 -> V_9 , L_41 ) ;
return - V_76 ;
}
F_89 ( V_177 , L_42 , V_46 ) ;
return 0 ;
}
static int F_90 ( struct V_180 * V_180 , struct V_181 * V_181 )
{
return F_91 ( V_181 , F_88 , V_180 -> V_182 ) ;
}
static void F_92 ( struct V_1 * V_2 )
{
F_93 ( V_2 -> V_183 ) ;
V_2 -> V_183 = NULL ;
}
static int F_94 ( struct V_1 * V_2 )
{
struct V_184 * V_184 ;
V_2 -> V_183 = F_95 ( L_43 , NULL ) ;
V_184 = F_96 ( L_44 , V_185 , V_2 -> V_183 ,
V_2 , & V_186 ) ;
if ( ! V_184 )
F_92 ( V_2 ) ;
return V_2 -> V_183 == NULL ? - V_76 : 0 ;
}
static int F_97 ( struct V_187 * V_8 )
{
struct V_68 * V_9 = & V_8 -> V_9 ;
struct V_1 * V_2 ;
struct V_188 V_189 ;
struct V_25 * V_190 ;
int V_7 ;
V_2 = F_98 ( & V_8 -> V_9 , sizeof( * V_2 ) , V_73 ) ;
if ( ! V_2 )
return - V_74 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_33 . V_8 = V_8 ;
F_99 ( & V_2 -> V_67 ) ;
F_100 ( & V_2 -> V_147 ) ;
F_101 ( & V_2 -> V_85 ) ;
V_7 = F_102 ( V_9 -> V_191 , 0 , & V_189 ) ;
if ( V_7 < 0 )
return V_7 ;
V_2 -> V_192 = F_103 ( V_9 , & V_189 ) ;
if ( F_2 ( V_2 -> V_192 ) )
return F_7 ( V_2 -> V_192 ) ;
V_190 = F_104 ( V_9 -> V_191 , L_45 ) ;
if ( ! V_190 )
return - V_193 ;
V_2 -> V_194 = F_105 ( V_190 , 0 ) ;
if ( ! V_2 -> V_194 )
return - V_74 ;
V_2 -> V_143 = F_106 ( V_9 -> V_191 , 0 ) ;
if ( V_2 -> V_143 < 0 ) {
F_8 ( V_9 , L_46 ) ;
return V_2 -> V_143 ;
}
V_7 = F_5 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
F_107 ( V_8 , V_2 ) ;
V_7 = F_108 ( V_2 -> V_143 , F_76 , 0 , F_109 ( V_9 ) , V_2 ) ;
if ( V_7 < 0 ) {
F_8 ( V_9 , L_47 ) ;
goto V_195;
}
F_110 ( V_9 ) ;
V_7 = F_111 ( V_9 ) ;
if ( V_7 < 0 )
goto V_196;
V_2 -> V_197 = F_112 ( V_9 ) ;
if ( F_2 ( V_2 -> V_197 ) ) {
V_7 = F_7 ( V_2 -> V_197 ) ;
goto V_196;
}
V_7 = F_22 ( V_2 ) ;
if ( V_7 < 0 )
goto V_198;
V_7 = F_94 ( V_2 ) ;
if ( V_7 < 0 )
goto V_199;
V_7 = F_60 ( V_2 , V_200 ) ;
if ( V_7 < 0 )
goto V_201;
F_113 ( V_9 ) ;
F_58 ( V_9 , L_48 ) ;
return 0 ;
V_201:
F_92 ( V_2 ) ;
V_198:
F_114 ( V_2 -> V_197 ) ;
V_199:
F_33 ( V_2 ) ;
V_196:
F_115 ( V_2 -> V_143 , V_2 ) ;
V_195:
F_1 ( V_2 ) ;
return V_7 ;
}
static int F_116 ( struct V_68 * V_9 )
{
struct V_1 * V_2 = F_117 ( V_9 ) ;
int V_7 ;
V_7 = F_9 ( V_2 ) ;
if ( V_7 )
return V_7 ;
return F_12 ( V_2 ) ;
}
static int F_118 ( struct V_68 * V_9 )
{
struct V_1 * V_2 = F_117 ( V_9 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
static int F_119 ( struct V_68 * V_9 )
{
return 0 ;
}
static int F_120 ( struct V_68 * V_9 )
{
struct V_1 * V_2 = F_117 ( V_9 ) ;
if ( F_46 ( V_70 , & V_2 -> V_55 ) )
return - V_202 ;
return 0 ;
}
static int F_121 ( struct V_187 * V_8 )
{
struct V_1 * V_2 = F_122 ( V_8 ) ;
F_123 ( & V_8 -> V_9 ) ;
F_124 ( & V_8 -> V_9 ) ;
F_115 ( V_2 -> V_143 , V_2 ) ;
F_33 ( V_2 ) ;
F_114 ( V_2 -> V_197 ) ;
F_1 ( V_2 ) ;
F_92 ( V_2 ) ;
if ( V_2 -> V_45 . V_69 )
F_38 ( V_2 -> V_45 . V_69 ) ;
F_55 ( V_2 ) ;
return 0 ;
}
static int F_125 ( void )
{
int V_7 ;
V_7 = F_126 () ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_127 () ;
if ( V_7 < 0 )
goto V_203;
V_7 = F_128 ( & V_204 ) ;
if ( ! V_7 )
return V_7 ;
F_129 () ;
V_203:
F_130 () ;
return V_7 ;
}
static void F_131 ( void )
{
F_130 () ;
F_129 () ;
F_132 ( & V_204 ) ;
}
