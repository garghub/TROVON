const char * F_1 ( int V_1 )
{
static char V_2 [ 16 ] ;
snprintf ( V_2 , sizeof V_2 , L_1 , V_1 ) ;
return V_2 ;
}
static inline void F_2 ( struct V_3 * V_4 , struct V_5 * V_6 ,
T_1 * V_7 , T_1 * V_8 )
{
int V_9 ;
V_9 = F_3 ( V_6 , V_10 , V_7 ) ;
if ( V_9 )
F_4 ( V_4 , L_2
L_3 , - V_9 ) ;
V_9 = F_3 ( V_6 , V_11 , V_8 ) ;
if ( V_9 )
F_4 ( V_4 , L_4
L_3 , - V_9 ) ;
F_5 ( L_5 , * V_7 , * V_8 ) ;
}
static void F_6 ( struct V_5 * V_12 ,
struct V_3 * V_4 )
{
unsigned long V_13 ;
F_7 ( V_12 , NULL ) ;
if ( V_4 -> V_14 != - 1 ) {
F_8 ( & V_15 , V_13 ) ;
F_9 ( & V_16 , V_4 -> V_14 ) ;
F_10 ( & V_4 -> V_17 ) ;
F_11 ( & V_15 , V_13 ) ;
}
F_12 ( V_4 ) ;
}
static struct V_3 * F_13 ( struct V_5 * V_12 )
{
unsigned long V_13 ;
struct V_3 * V_4 ;
int V_9 ;
V_4 = F_14 ( sizeof( * V_4 ) ) ;
if ( ! V_4 ) {
V_4 = F_15 ( - V_18 ) ;
goto V_19;
}
V_4 -> V_14 = - 1 ;
F_16 ( V_20 ) ;
F_8 ( & V_15 , V_13 ) ;
V_9 = F_17 ( & V_16 , V_4 , 0 , 0 , V_21 ) ;
if ( V_9 < 0 ) {
F_18 (KERN_ERR IPATH_DRV_NAME
L_6 , -ret) ;
F_6 ( V_12 , V_4 ) ;
V_4 = F_15 ( V_9 ) ;
goto V_22;
}
V_4 -> V_14 = V_9 ;
V_4 -> V_23 = V_12 ;
F_7 ( V_12 , V_4 ) ;
F_19 ( & V_4 -> V_17 , & V_24 ) ;
V_22:
F_11 ( & V_15 , V_13 ) ;
F_20 () ;
V_19:
return V_4 ;
}
static inline struct V_3 * F_21 ( int V_1 )
{
return F_22 ( & V_16 , V_1 ) ;
}
struct V_3 * F_23 ( int V_1 )
{
struct V_3 * V_4 ;
unsigned long V_13 ;
F_8 ( & V_15 , V_13 ) ;
V_4 = F_21 ( V_1 ) ;
F_11 ( & V_15 , V_13 ) ;
return V_4 ;
}
int F_24 ( int * V_25 , int * V_26 , int * V_27 )
{
int V_28 , V_29 , V_30 ;
struct V_3 * V_4 ;
unsigned long V_13 ;
int V_31 ;
V_28 = V_29 = V_30 = V_31 = 0 ;
F_8 ( & V_15 , V_13 ) ;
F_25 (dd, &ipath_dev_list, ipath_list) {
V_28 ++ ;
if ( ( V_4 -> V_32 & V_33 ) && V_4 -> V_34 )
V_29 ++ ;
if ( V_4 -> V_35 &&
! ( V_4 -> V_32 & ( V_36 | V_37
| V_38 ) ) )
V_30 ++ ;
if ( V_4 -> V_39 > V_31 )
V_31 = V_4 -> V_39 ;
}
F_11 ( & V_15 , V_13 ) ;
if ( V_25 )
* V_25 = V_29 ;
if ( V_26 )
* V_26 = V_30 ;
if ( V_27 )
* V_27 = V_31 ;
return V_28 ;
}
static void F_26 ( struct V_3 * V_4 )
{
T_1 V_40 , V_41 , V_42 ;
T_1 T_2 * V_43 ;
T_1 * V_44 ;
T_3 V_45 , V_46 ;
V_43 = F_27 ( V_4 , 0 , & V_40 ) ;
if ( ! V_43 ) {
F_28 ( & V_4 -> V_23 -> V_6 ,
L_7 ) ;
return;
}
V_41 = 1024 ;
V_44 = F_29 ( V_41 ) ;
if ( ! V_44 ) {
F_28 ( & V_4 -> V_23 -> V_6 ,
L_8
L_9 ) ;
goto V_47;
}
F_30 () ;
V_45 = 1 + F_31 ( V_48 ) ;
for ( V_42 = 0 ; V_42 < 10000U ; V_42 ++ ) {
if ( F_31 ( V_48 ) >= V_45 )
break;
F_32 ( 1 ) ;
}
F_33 ( V_4 ) ;
if ( ( V_4 -> V_32 & V_49 ) )
F_34 ( 1UL << 63 , V_43 ) ;
else
F_34 ( 0 , V_43 ) ;
F_35 () ;
V_45 = F_31 ( V_48 ) ;
for ( V_46 = V_42 = 0 ; V_46 <= 5UL ; V_42 ++ ) {
F_36 ( V_43 + 64 , V_44 , V_41 >> 2 ) ;
V_46 = F_31 ( V_48 ) - V_45 ;
}
if ( V_42 < ( V_46 * 1024U ) )
F_4 ( V_4 ,
L_10
L_11 ,
V_42 / ( T_1 ) V_46 ) ;
else
F_5 ( L_12 ,
V_42 / ( T_1 ) V_46 ) ;
F_37 () ;
F_12 ( V_44 ) ;
V_47:
F_38 ( V_4 , V_40 , 1 ) ;
F_39 ( V_4 ) ;
}
static int F_40 ( struct V_5 * V_12 , const struct V_50 * V_51 )
{
int V_9 , V_52 , V_53 ;
struct V_3 * V_4 ;
unsigned long long V_44 ;
T_1 V_7 = 0 , V_8 = 0 ;
V_4 = F_13 ( V_12 ) ;
if ( F_41 ( V_4 ) ) {
V_9 = F_42 ( V_4 ) ;
F_18 (KERN_ERR IPATH_DRV_NAME
L_13 , -ret) ;
goto V_19;
}
F_43 ( V_54 , L_14 , V_4 -> V_14 ) ;
V_9 = F_44 ( V_12 ) ;
if ( V_9 ) {
F_4 ( V_4 , L_15 ,
V_4 -> V_14 , - V_9 ) ;
goto V_55;
}
V_44 = F_45 ( V_12 , 0 ) ;
V_52 = F_46 ( V_12 , 0 ) ;
F_43 ( V_54 , L_16
L_17 , V_44 , V_52 , V_12 -> V_56 , V_51 -> V_57 ,
V_51 -> V_58 , V_51 -> V_59 ) ;
F_2 ( V_4 , V_12 , & V_7 , & V_8 ) ;
if ( ! V_8 && ! ( V_7 & ~ 0xf ) ) {
if ( V_44 ) {
F_28 ( & V_12 -> V_6 , L_18
L_19 , V_44 ) ;
V_9 = F_47 (
V_12 , V_10 , V_44 ) ;
if ( V_9 ) {
F_4 ( V_4 , L_20
L_21 , - V_9 ) ;
goto V_60;
}
V_9 = F_47 (
V_12 , V_11 , V_44 >> 32 ) ;
if ( V_9 ) {
F_4 ( V_4 , L_22
L_21 , - V_9 ) ;
goto V_60;
}
} else {
F_4 ( V_4 , L_18
L_23 ) ;
V_9 = - V_61 ;
goto V_60;
}
}
V_9 = F_48 ( V_12 , V_62 ) ;
if ( V_9 ) {
F_28 ( & V_12 -> V_6 , L_24
L_25 , V_4 -> V_14 , - V_9 ) ;
goto V_60;
}
V_9 = F_49 ( V_12 , F_50 ( 64 ) ) ;
if ( V_9 ) {
V_9 = F_49 ( V_12 , F_50 ( 32 ) ) ;
if ( V_9 ) {
F_28 ( & V_12 -> V_6 ,
L_26 ,
V_4 -> V_14 , V_9 ) ;
goto V_63;
}
else {
F_5 ( L_27 ) ;
V_9 = F_51 ( V_12 , F_50 ( 32 ) ) ;
if ( V_9 )
F_28 ( & V_12 -> V_6 ,
L_28
L_29 ,
V_4 -> V_14 , V_9 ) ;
}
}
else {
V_9 = F_51 ( V_12 , F_50 ( 64 ) ) ;
if ( V_9 )
F_28 ( & V_12 -> V_6 ,
L_28
L_29 ,
V_4 -> V_14 , V_9 ) ;
}
F_52 ( V_12 ) ;
V_4 -> V_64 = V_44 ;
V_4 -> V_65 = V_44 >> 32 ;
V_4 -> V_66 = V_51 -> V_58 ;
V_4 -> V_67 = V_51 -> V_57 ;
switch ( V_51 -> V_58 ) {
case V_68 :
F_53 ( V_4 ) ;
break;
default:
F_4 ( V_4 , L_30
L_31 , V_51 -> V_58 ) ;
return - V_61 ;
}
for ( V_53 = 0 ; V_53 < 6 ; V_53 ++ ) {
if ( ! V_12 -> V_69 [ V_53 ] . V_70 )
continue;
F_43 ( V_54 , L_32 ,
V_53 , & V_12 -> V_69 [ V_53 ] ,
( unsigned long long ) F_46 ( V_12 , V_53 ) ) ;
}
if ( ! V_44 ) {
F_4 ( V_4 , L_33 ) ;
V_9 = - V_61 ;
goto V_63;
}
V_4 -> V_71 = V_12 -> V_72 ;
#if F_54 ( V_73 )
V_4 -> V_34 = F_55 ( V_44 , V_52 ,
( V_74 | V_75 ) ) ;
#else
V_4 -> V_34 = F_56 ( V_44 , V_52 ) ;
#endif
if ( ! V_4 -> V_34 ) {
F_5 ( L_34 ,
V_44 ) ;
V_9 = - V_18 ;
goto V_76;
}
V_4 -> V_77 = ( T_3 T_2 * )
( ( void T_2 * ) V_4 -> V_34 + V_52 ) ;
V_4 -> V_78 = V_44 ;
F_43 ( V_54 , L_35 ,
V_44 , V_4 -> V_34 ) ;
if ( V_4 -> V_79 ( V_4 , V_12 ) )
F_4 ( V_4 , L_36
L_37 ) ;
if ( ! V_4 -> V_80 )
F_4 ( V_4 , L_38
L_39 ) ;
else {
V_9 = F_57 ( V_4 -> V_80 , V_81 , V_82 ,
V_62 , V_4 ) ;
if ( V_9 ) {
F_4 ( V_4 , L_40
L_41 , V_4 -> V_80 , V_9 ) ;
goto V_76;
}
}
V_9 = F_58 ( V_4 , 0 ) ;
if ( V_9 )
goto V_83;
V_9 = F_59 ( V_4 ) ;
if ( V_9 ) {
F_4 ( V_4 , L_42
L_43 ,
- V_9 ) ;
V_9 = 0 ;
}
F_26 ( V_4 ) ;
F_60 ( & V_12 -> V_6 , V_4 ) ;
F_61 ( V_4 ) ;
F_62 ( V_4 ) ;
F_63 ( V_4 ) ;
F_64 ( V_4 ) ;
goto V_19;
V_83:
F_65 ( V_4 ) ;
if ( V_4 -> V_80 )
V_4 -> V_84 ( V_4 ) ;
if ( V_4 -> V_85 )
V_4 -> V_85 ( V_4 ) ;
V_76:
F_66 ( ( volatile void T_2 * ) V_4 -> V_34 ) ;
V_63:
F_67 ( V_12 ) ;
V_60:
F_68 ( V_12 ) ;
V_55:
F_6 ( V_12 , V_4 ) ;
V_19:
return V_9 ;
}
static void F_65 ( struct V_3 * V_4 )
{
int V_86 ;
struct V_87 * * V_88 ;
unsigned long V_13 ;
if ( * V_4 -> V_89 & V_90 ) {
* V_4 -> V_89 &= ~ V_90 ;
if ( V_4 -> V_34 ) {
V_4 -> V_34 = NULL ;
V_4 -> V_91 = 0 ;
V_4 -> V_92 = 0 ;
V_4 -> V_93 = 0 ;
V_4 -> V_94 = 0 ;
}
F_69 ( V_4 ) ;
}
if ( V_4 -> V_95 )
F_28 ( & V_4 -> V_23 -> V_6 , L_44 ,
V_4 -> V_95 ) ;
if ( V_4 -> V_96 ) {
F_70 ( & V_4 -> V_23 -> V_6 , V_97 ,
( void * ) V_4 -> V_96 ,
V_4 -> V_98 ) ;
V_4 -> V_96 = NULL ;
}
if ( V_4 -> V_99 ) {
F_70 ( & V_4 -> V_23 -> V_6 ,
V_4 -> V_100 [ 0 ] -> V_101 ,
V_4 -> V_99 , V_4 -> V_102 ) ;
V_4 -> V_99 = NULL ;
}
if ( V_4 -> V_103 ) {
struct V_104 * * V_105 = V_4 -> V_103 ;
T_4 * V_106 = V_4 -> V_107 ;
int V_108 , V_41 = 0 ;
F_43 ( V_54 , L_45
L_46 ) ;
for ( V_86 = 0 ; V_86 < V_4 -> V_39 ; V_86 ++ ) {
int V_109 = V_86 * V_4 -> V_110 ;
int V_111 = V_109 + V_4 -> V_110 ;
for ( V_108 = V_109 ; V_108 < V_111 ; V_108 ++ ) {
if ( ! V_105 [ V_108 ] )
continue;
F_71 ( V_4 -> V_23 , V_106 [ V_108 ] ,
V_97 , V_112 ) ;
F_72 ( & V_105 [ V_108 ] , 1 ) ;
V_105 [ V_108 ] = NULL ;
V_41 ++ ;
}
}
if ( V_41 ) {
V_113 . V_114 += V_41 ;
F_43 ( V_54 , L_47
L_48 , V_41 ) ;
}
if ( V_113 . V_115 ||
V_113 . V_114 )
F_43 ( V_54 , L_49
L_50 ,
( unsigned long long )
V_113 . V_115 ,
( unsigned long long )
V_113 . V_114 ) ;
F_43 ( V_54 , L_51 ,
V_4 -> V_103 ) ;
V_105 = V_4 -> V_103 ;
V_4 -> V_103 = NULL ;
F_12 ( V_105 ) ;
V_4 -> V_116 = NULL ;
}
F_8 ( & V_4 -> V_117 , V_13 ) ;
V_88 = V_4 -> V_100 ;
V_4 -> V_100 = NULL ;
F_11 ( & V_4 -> V_117 , V_13 ) ;
for ( V_86 = 0 ; V_86 < V_4 -> V_118 ; V_86 ++ ) {
struct V_87 * V_119 = V_88 [ V_86 ] ;
V_88 [ V_86 ] = NULL ;
F_73 ( V_4 , V_119 ) ;
}
F_74 ( V_88 ) ;
}
static void F_75 ( struct V_5 * V_12 )
{
struct V_3 * V_4 = F_76 ( V_12 ) ;
F_43 ( V_54 , L_52 , V_12 , V_4 ) ;
F_77 ( V_4 ) ;
F_78 ( V_120 ) ;
if ( V_4 -> V_121 )
F_79 ( V_4 -> V_121 ) ;
F_80 ( V_4 ) ;
F_81 ( V_4 ) ;
F_82 ( V_4 ) ;
F_83 ( & V_12 -> V_6 , V_4 ) ;
F_43 ( V_54 , L_53
L_54 , V_4 , ( T_1 ) V_4 -> V_14 ) ;
F_65 ( V_4 ) ;
if ( V_4 -> V_80 ) {
F_43 ( V_54 , L_55 ,
V_4 -> V_14 , V_4 -> V_80 ) ;
V_4 -> V_84 ( V_4 ) ;
} else
F_5 ( L_56
L_57 , V_4 -> V_14 ) ;
if ( V_4 -> V_85 )
V_4 -> V_85 ( V_4 ) ;
F_43 ( V_54 , L_58 , V_4 -> V_34 ) ;
F_66 ( ( volatile void T_2 * ) V_4 -> V_34 ) ;
F_67 ( V_12 ) ;
F_43 ( V_54 , L_59 ) ;
F_68 ( V_12 ) ;
F_6 ( V_12 , V_4 ) ;
}
void F_38 ( struct V_3 * V_4 , unsigned V_122 ,
unsigned V_41 )
{
unsigned V_108 , V_123 = V_122 + V_41 ;
unsigned long V_13 ;
F_43 ( V_124 , L_60 , V_41 , V_122 ) ;
for ( V_108 = V_122 ; V_108 < V_123 ; V_108 ++ ) {
F_8 ( & V_4 -> V_125 , V_13 ) ;
F_84 ( V_4 , V_4 -> V_126 -> V_127 ,
V_4 -> V_128 | V_129 |
( V_108 << V_130 ) ) ;
F_85 ( V_4 , V_4 -> V_126 -> V_131 ) ;
F_11 ( & V_4 -> V_125 , V_13 ) ;
}
F_86 ( V_4 ) ;
}
int F_87 ( struct V_3 * V_4 , T_1 V_132 , int V_45 )
{
V_4 -> V_133 = V_132 ;
F_88 ( V_134 ,
( V_4 -> V_32 & V_132 ) ,
F_89 ( V_45 ) ) ;
V_4 -> V_133 = 0 ;
if ( ! ( V_4 -> V_32 & V_132 ) ) {
T_3 V_135 ;
F_43 ( V_54 , L_61
L_62 ,
( V_132 & V_136 ) ? L_63 :
( ( V_132 & V_37 ) ? L_64 :
( ( V_132 & V_137 ) ? L_65 : L_66 ) ) ,
V_45 ) ;
V_135 = F_85 ( V_4 , V_4 -> V_126 -> V_138 ) ;
F_43 ( V_54 , L_67 ,
( unsigned long long ) F_85 (
V_4 , V_4 -> V_126 -> V_139 ) ,
( unsigned long long ) V_135 ,
V_140 [ V_135 & V_4 -> V_141 ] ) ;
}
return ( V_4 -> V_32 & V_132 ) ? 0 : - V_142 ;
}
static void F_90 ( struct V_3 * V_4 , T_5 V_143 ,
char * V_144 , T_6 V_145 )
{
static const struct {
T_5 V_143 ;
const char * V_146 ;
} V_147 [] = {
{ V_148 , L_68 } ,
{ V_149 , L_69 } ,
{ V_150 , L_70 } ,
{ V_151 , L_71 } ,
{ V_152 , L_72 } ,
{ V_153 , L_73 } ,
{ V_154 , L_74 } ,
{ V_155 , L_75 } ,
{ V_156 , L_76 } ,
{ V_157 , L_77 } ,
{ V_158 , L_78 } ,
{ V_159 , L_79 } ,
} ;
int V_108 ;
int V_160 ;
T_6 V_161 = 0 ;
for ( V_108 = 0 ; V_108 < F_91 ( V_147 ) ; V_108 ++ ) {
V_160 = ( V_147 [ V_108 ] . V_143 != V_159 ) ? 0 :
F_92 ( V_162 , & V_4 -> V_163 ) ;
if ( ( V_143 & V_147 [ V_108 ] . V_143 ) && ! V_160 )
V_161 += snprintf ( V_144 + V_161 , V_145 - V_161 ,
L_80 , V_147 [ V_108 ] . V_146 ) ;
}
}
int F_93 ( struct V_3 * V_4 , char * V_144 , T_6 V_145 ,
T_5 V_143 )
{
int V_164 = 1 ;
* V_144 = '\0' ;
if ( V_143 & V_165 ) {
if ( ! ( V_143 & ~ V_165 ) )
V_164 = 0 ;
if ( V_166 & V_167 ) {
if ( V_143 & V_168 )
F_94 ( V_144 , L_81 , V_145 ) ;
if ( V_143 & V_169 )
F_94 ( V_144 , L_82 , V_145 ) ;
if ( V_143 & V_170 ) {
F_94 ( V_144 , L_83 , V_145 ) ;
V_143 &= V_170 ;
}
if ( V_143 & V_171 )
F_94 ( V_144 , L_84 , V_145 ) ;
if ( V_143 & V_172 )
F_94 ( V_144 , L_85 , V_145 ) ;
if ( V_143 & V_173 )
F_94 ( V_144 , L_86 , V_145 ) ;
}
if ( ( V_143 & V_170 ) &&
! ( V_143 & ( V_169 | V_168 ) ) )
F_94 ( V_144 , L_83 , V_145 ) ;
if ( ! V_164 )
goto V_47;
}
if ( V_143 & V_174 )
F_94 ( V_144 , L_87 , V_145 ) ;
if ( V_143 & V_175 )
F_94 ( V_144 , L_88 , V_145 ) ;
if ( V_143 & V_176 )
F_94 ( V_144 , L_89 , V_145 ) ;
if ( V_143 & V_177 )
F_94 ( V_144 , L_90 , V_145 ) ;
if ( V_143 & V_178 )
F_94 ( V_144 , L_91 , V_145 ) ;
if ( V_143 & V_179 )
F_94 ( V_144 , L_92 , V_145 ) ;
if ( V_143 & V_180 )
F_94 ( V_144 , L_93 , V_145 ) ;
if ( V_143 & V_181 )
F_94 ( V_144 , L_94 , V_145 ) ;
if ( V_143 & V_182 )
F_94 ( V_144 , L_95 , V_145 ) ;
if ( V_143 & V_183 )
F_94 ( V_144 , L_96 , V_145 ) ;
if ( V_143 & V_184 )
F_94 ( V_144 , L_97 , V_145 ) ;
if ( V_143 & V_185 )
F_94 ( V_144 , L_98 , V_145 ) ;
if ( V_143 & V_186 )
F_94 ( V_144 , L_99 , V_145 ) ;
if ( V_143 & V_187 )
F_94 ( V_144 , L_100 , V_145 ) ;
if ( V_143 & V_188 )
F_94 ( V_144 , L_101 , V_145 ) ;
if ( V_143 & V_189 )
F_94 ( V_144 , L_102 , V_145 ) ;
if ( V_143 & V_190 )
F_94 ( V_144 , L_103 , V_145 ) ;
if ( V_143 & V_191 )
F_94 ( V_144 , L_104 , V_145 ) ;
if ( V_143 & V_192 )
F_94 ( V_144 , L_105 , V_145 ) ;
if ( V_143 & V_193 )
F_94 ( V_144 , L_106 , V_145 ) ;
if ( V_143 & V_194 )
F_94 ( V_144 , L_107 , V_145 ) ;
if ( V_143 & V_195 )
F_94 ( V_144 , L_108 , V_145 ) ;
if ( V_143 & V_196 )
F_94 ( V_144 , L_109 , V_145 ) ;
if ( V_143 & V_197 )
F_94 ( V_144 , L_110 , V_145 ) ;
if ( V_143 & V_198 )
F_94 ( V_144 , L_111 , V_145 ) ;
if ( V_143 & V_199 )
F_94 ( V_144 , L_112 , V_145 ) ;
if ( V_143 & V_200 )
F_90 ( V_4 , V_143 , V_144 , V_145 ) ;
if ( V_143 & V_201 )
F_94 ( V_144 , L_113 , V_145 ) ;
V_47:
return V_164 ;
}
static void F_95 ( T_1 V_143 , char * V_146 , T_6 V_52 )
{
* V_146 = '\0' ;
if ( V_143 & V_202 )
F_94 ( V_146 , L_114 , V_52 ) ;
if ( V_143 & V_203 )
F_94 ( V_146 , L_115 , V_52 ) ;
if ( V_143 & V_204 )
F_94 ( V_146 , L_116 , V_52 ) ;
if ( V_143 & V_205 )
F_94 ( V_146 , L_117 , V_52 ) ;
if ( V_143 & V_206 )
F_94 ( V_146 , L_118 , V_52 ) ;
if ( V_143 & V_207 )
F_94 ( V_146 , L_119 , V_52 ) ;
if ( V_143 & V_208 )
F_94 ( V_146 , L_120 , V_52 ) ;
if ( V_143 & V_209 )
F_94 ( V_146 , L_121 , V_52 ) ;
if ( V_143 & V_210 )
F_94 ( V_146 , L_122 , V_52 ) ;
if ( V_143 & V_211 )
F_94 ( V_146 , L_123 , V_52 ) ;
if ( V_143 & V_212 )
F_94 ( V_146 , L_124 , V_52 ) ;
}
static inline void * F_96 ( struct V_3 * V_4 , T_1 V_213 )
{
return V_4 -> V_214 ?
( void * ) V_4 -> V_214 [ V_213 ] . V_215 -> V_216 : NULL ;
}
struct V_217 * F_97 ( struct V_3 * V_4 ,
T_7 V_218 )
{
struct V_217 * V_215 ;
T_1 V_52 ;
V_52 = V_4 -> V_219 + 4 ;
if ( V_4 -> V_32 & V_220 ) {
V_52 += 2047 ;
}
V_215 = F_98 ( V_52 , V_218 ) ;
if ( ! V_215 ) {
F_4 ( V_4 , L_125 ,
V_52 ) ;
goto V_19;
}
F_99 ( V_215 , 4 ) ;
if ( V_4 -> V_32 & V_220 ) {
T_1 V_221 = ( unsigned long ) V_215 -> V_216 & 2047 ;
if ( V_221 )
F_99 ( V_215 , 2048 - V_221 ) ;
}
V_19:
return V_215 ;
}
static void F_100 ( struct V_3 * V_4 ,
T_1 V_222 ,
T_1 V_223 ,
T_1 V_224 ,
T_8 * V_225 ,
struct V_226 * V_227 )
{
char V_228 [ 128 ] ;
F_95 ( V_222 , V_228 , sizeof V_228 ) ;
F_43 ( V_124 , L_126
L_127 ,
V_222 , V_223 ,
F_101 ( V_225 ) ,
F_102 ( V_225 ) ,
F_103 ( V_227 -> V_229 [ 0 ] ) >> 24 ,
V_224 , V_228 ) ;
if ( V_222 & ( V_202 | V_203 ) ) {
T_9 V_230 = ( V_4 -> V_231 >>
V_232 ) &
V_233 ;
if ( ++ V_4 -> V_234 > V_230 ) {
V_4 -> V_234 = 0 ;
V_4 -> V_235 ++ ;
}
}
}
void F_104 ( struct V_87 * V_119 )
{
struct V_3 * V_4 = V_119 -> V_236 ;
T_8 * V_225 ;
void * V_237 ;
const T_1 V_238 = V_4 -> V_239 ;
const T_1 V_240 = V_4 -> V_241 * V_238 ;
T_1 V_224 = - 1 , V_223 , V_242 ;
struct V_226 * V_227 ;
T_1 V_222 , V_108 , V_243 , V_244 , V_245 = 0 , V_246 = 0 , V_247 = 0 ;
static T_3 V_248 ;
int V_123 ;
V_223 = V_119 -> V_249 ;
V_225 = ( T_8 * ) V_119 -> V_250 + V_223 + V_4 -> V_251 ;
if ( V_4 -> V_32 & V_252 ) {
T_1 V_253 = F_105 ( V_225 ) ;
if ( V_253 != V_119 -> V_254 )
goto V_19;
V_242 = 0 ;
} else {
V_242 = F_106 ( V_119 ) ;
if ( V_223 == V_242 )
goto V_19;
F_107 () ;
}
V_247:
for ( V_123 = 0 , V_108 = 1 ; ! V_123 ; V_108 += ! V_123 ) {
V_227 = V_4 -> V_255 ( V_4 , V_225 ) ;
V_222 = F_108 ( V_225 ) ;
V_243 = F_101 ( V_225 ) ;
V_244 = F_102 ( V_225 ) ;
V_237 = NULL ;
if ( ( V_4 -> V_32 & V_252 ) ?
F_109 ( V_225 ) :
( V_243 != V_256 ) ) {
V_224 = F_110 ( V_225 ) ;
V_246 = 1 ;
if ( V_244 > sizeof( * V_227 ) ||
V_243 == V_257 )
V_237 = F_96 ( V_4 , V_224 ) ;
}
if ( V_243 != V_257 &&
V_243 != V_258 &&
F_111 ( V_227 -> V_259 . V_260 ) !=
V_261 )
F_43 ( V_124 , L_128
L_129 , V_243 ) ;
if ( F_112 ( V_222 ) )
F_100 ( V_4 , V_222 , V_223 , V_224 , V_225 , V_227 ) ;
else if ( V_243 == V_257 ) {
F_113 ( V_4 -> V_121 , ( T_1 * ) V_227 , V_237 , V_244 ) ;
if ( V_4 -> V_234 )
V_4 -> V_234 -- ;
} else if ( V_243 == V_262 ) {
T_9 V_263 = F_103 ( V_227 -> V_229 [ 0 ] ) >> 24 ;
T_1 V_264 = F_103 ( V_227 -> V_229 [ 1 ] ) & 0xffffff ;
F_43 ( V_124 , L_130
L_131 ,
V_243 , V_263 , V_264 , V_244 ) ;
}
else if ( V_243 == V_256 )
F_5 ( L_132 ,
F_103 ( V_227 -> V_229 [ 0 ] ) >> 24 ) ;
else {
F_43 ( V_265 , L_133
L_134 ,
V_224 , V_244 , V_223 , ( unsigned long long )
F_114 ( * ( V_266 * ) V_225 ) ) ;
if ( V_166 & V_167 ) {
T_1 V_53 , * V_267 , V_268 = V_238 - 2 ;
if ( V_238 > ( V_244 >> 2 ) )
V_268 = V_244 >> 2 ;
V_267 = ( T_1 * ) V_227 ;
F_18 ( V_269 L_135 ,
V_268 ) ;
for ( V_53 = 0 ; V_53 < V_268 ; V_53 ++ )
F_18 ( V_269 L_136 , V_267 [ V_53 ] ,
( V_53 % 8 ) == 7 ? L_137 : L_138 ) ;
F_18 ( V_269 L_139 ) ;
}
}
V_223 += V_238 ;
if ( V_223 >= V_240 )
V_223 = 0 ;
V_225 = ( T_8 * ) V_119 -> V_250 +
V_223 + V_4 -> V_251 ;
if ( V_4 -> V_32 & V_252 ) {
T_1 V_253 = F_105 ( V_225 ) ;
if ( ++ V_119 -> V_254 > 13 )
V_119 -> V_254 = 1 ;
if ( V_253 != V_119 -> V_254 )
V_123 = 1 ;
} else if ( V_223 == V_242 )
V_123 = 1 ;
if ( V_123 || ! ( V_108 & 0xf ) ) {
T_3 V_270 = V_223 ;
if ( V_123 )
V_270 |= V_4 -> V_271 ;
F_115 ( V_4 , V_272 , V_270 ,
V_119 -> V_273 ) ;
if ( V_246 ) {
F_115 ( V_4 , V_274 ,
V_224 , V_119 -> V_273 ) ;
V_246 = 0 ;
}
}
}
if ( ! V_4 -> V_271 && ! V_247 &&
! ( V_4 -> V_32 & V_252 ) ) {
T_1 V_275 = F_106 ( V_119 ) ;
if ( V_275 != V_242 ) {
V_242 = V_275 ;
V_247 = 1 ;
goto V_247;
}
}
V_245 += V_108 ;
V_119 -> V_249 = V_223 ;
if ( V_245 > V_113 . V_276 )
V_113 . V_276 = V_245 ;
V_113 . V_277 += V_245 ;
V_113 . V_278 =
V_113 . V_277 / ++ V_248 ;
V_19: ;
}
static void F_116 ( struct V_3 * V_4 )
{
unsigned long V_13 ;
int V_108 ;
const unsigned V_279 = ( unsigned ) V_4 -> V_280 ;
if ( ! V_4 -> V_96 ) {
F_5 ( L_140 ) ;
return;
}
if ( V_166 & V_281 ) {
volatile V_266 * V_282 = V_4 -> V_96 ;
unsigned long * V_283 = V_4 -> V_284 ;
F_43 ( V_124 , L_141
L_142
L_143 ,
( unsigned long long ) F_114 ( V_282 [ 0 ] ) ,
V_283 [ 0 ] ,
( unsigned long long ) F_114 ( V_282 [ 1 ] ) ,
V_283 [ 1 ] ,
( unsigned long long ) F_114 ( V_282 [ 2 ] ) ,
V_283 [ 2 ] ,
( unsigned long long ) F_114 ( V_282 [ 3 ] ) ,
V_283 [ 3 ] ) ;
if ( V_279 > 4 )
F_43 (
V_124 , L_144
L_145
L_146 ,
( unsigned long long ) F_114 ( V_282 [ 4 ] ) ,
V_283 [ 4 ] ,
( unsigned long long ) F_114 ( V_282 [ 5 ] ) ,
V_283 [ 5 ] ,
( unsigned long long ) F_114 ( V_282 [ 6 ] ) ,
V_283 [ 6 ] ,
( unsigned long long ) F_114 ( V_282 [ 7 ] ) ,
V_283 [ 7 ] ) ;
}
F_8 ( & V_285 , V_13 ) ;
for ( V_108 = 0 ; V_108 < V_279 ; V_108 ++ ) {
T_3 V_286 , V_287 , V_288 , V_289 ;
if ( V_108 > 3 && ( V_4 -> V_32 & V_290 ) )
V_288 = F_114 ( V_4 -> V_96 [ V_108 ^ 1 ] ) ;
else
V_288 = F_114 ( V_4 -> V_96 [ V_108 ] ) ;
V_287 = V_4 -> V_291 [ V_108 ] &
~ ( V_4 -> V_284 [ V_108 ] ^ V_288 ) ;
V_286 = V_287 << V_292 ;
if ( V_287 && ( V_286 & V_4 -> V_284 [ V_108 ] ) ) {
V_289 = V_4 -> V_284 [ V_108 ] & ~ V_286 ;
V_289 |= V_288 & V_286 ;
V_4 -> V_284 [ V_108 ] = V_289 ;
}
}
F_11 ( & V_285 , V_13 ) ;
}
static void F_117 ( struct V_3 * V_4 )
{
int V_108 , V_293 ;
unsigned long V_13 ;
F_8 ( & V_285 , V_13 ) ;
for ( V_108 = 0 ; V_108 < V_4 -> V_280 ; V_108 ++ ) {
T_3 V_135 , V_294 ;
V_293 = ( V_108 > 3 && ( V_4 -> V_32 & V_290 ) ) ?
V_108 ^ 1 : V_108 ;
V_135 = F_114 ( V_4 -> V_96 [ V_293 ] ) ;
V_294 = V_4 -> V_284 [ V_108 ] ;
V_4 -> V_284 [ V_108 ] = V_135 |
( ( ~ V_4 -> V_291 [ V_108 ] <<
V_292 ) &
0xaaaaaaaaaaaaaaaaULL ) ;
if ( V_294 != V_4 -> V_284 [ V_108 ] )
F_5 ( L_147 ,
V_108 , ( unsigned long long ) V_294 ,
V_4 -> V_284 [ V_108 ] ) ;
}
F_11 ( & V_285 , V_13 ) ;
}
int F_118 ( struct V_3 * V_4 , unsigned V_295 )
{
int V_9 = 0 ;
if ( V_4 -> V_32 & V_296 ) {
if ( V_4 -> V_297 != V_295 ) {
F_28 ( & V_4 -> V_23 -> V_6 ,
L_148
L_149 ,
V_295 , V_4 -> V_297 ) ;
V_9 = - V_298 ;
} else
F_43 ( V_54 , L_150
L_151 , V_4 -> V_297 ) ;
} else if ( V_295 > ( V_4 -> V_239 -
( sizeof( T_3 ) / sizeof( T_1 ) ) ) ) {
F_5 ( L_152
L_153 , V_295 ,
V_4 -> V_239 -
( T_1 ) ( sizeof( T_3 ) / sizeof( T_1 ) ) ) ;
V_9 = - V_299 ;
} else {
V_4 -> V_32 |= V_296 ;
V_4 -> V_297 = V_295 ;
F_84 ( V_4 , V_4 -> V_126 -> V_300 ,
V_4 -> V_297 ) ;
F_43 ( V_54 , L_154 ,
V_4 -> V_297 ) ;
}
return V_9 ;
}
static T_10 void F_119 ( struct V_3 * V_4 )
{
unsigned long * V_283 = V_4 -> V_284 ;
V_266 * V_282 = ( V_266 * ) V_4 -> V_96 ;
V_4 -> V_301 = 1 ;
V_113 . V_302 ++ ;
if ( ! ( ++ V_4 -> V_303 % 100000 ) ) {
F_86 ( V_4 ) ;
F_5 ( L_155
L_156
L_157 ,
V_4 -> V_303 ,
( unsigned long ) F_120 () ,
( unsigned long long ) F_114 ( V_282 [ 0 ] ) ,
( unsigned long long ) F_114 ( V_282 [ 1 ] ) ,
( unsigned long long ) F_114 ( V_282 [ 2 ] ) ,
( unsigned long long ) F_114 ( V_282 [ 3 ] ) ,
V_283 [ 0 ] , V_283 [ 1 ] , V_283 [ 2 ] , V_283 [ 3 ] ) ;
if ( ( V_4 -> V_304 + V_4 -> V_305 ) >
( sizeof( V_283 [ 0 ] ) * 4 * 4 ) )
F_5 ( L_158
L_156
L_157 ,
( unsigned long long ) F_114 ( V_282 [ 4 ] ) ,
( unsigned long long ) F_114 ( V_282 [ 5 ] ) ,
( unsigned long long ) F_114 ( V_282 [ 6 ] ) ,
( unsigned long long ) F_114 ( V_282 [ 7 ] ) ,
V_283 [ 4 ] , V_283 [ 5 ] , V_283 [ 6 ] , V_283 [ 7 ] ) ;
F_117 ( V_4 ) ;
}
}
static T_1 T_2 * F_121 ( struct V_3 * V_4 ,
T_1 * V_306 , T_1 V_122 , T_1 V_123 , T_1 V_307 )
{
int V_108 , V_53 , V_308 = 0 ;
unsigned V_309 ;
unsigned long V_13 ;
unsigned long * V_283 = V_4 -> V_284 ;
T_1 T_2 * V_144 ;
V_309 = V_123 - V_122 ;
if ( V_4 -> V_301 ) {
F_116 ( V_4 ) ;
V_308 ++ ;
V_108 = V_122 ;
} else
V_108 = V_307 ;
V_310:
F_8 ( & V_285 , V_13 ) ;
for ( V_53 = 0 ; V_53 < V_309 ; V_53 ++ , V_108 ++ ) {
if ( V_108 >= V_123 )
V_108 = V_122 ;
if ( F_122 ( ( 2 * V_108 ) + 1 , V_283 ) )
continue;
F_123 ( 2 * V_108 , V_283 ) ;
break;
}
F_11 ( & V_285 , V_13 ) ;
if ( V_53 == V_309 ) {
if ( ! V_308 ) {
F_116 ( V_4 ) ;
V_308 ++ ;
V_108 = V_122 ;
goto V_310;
} else if ( V_308 == 1 && V_309 <=
( ( V_4 -> V_128
>> V_311 ) &
V_312 ) ) {
F_86 ( V_4 ) ;
F_116 ( V_4 ) ;
V_308 ++ ;
V_108 = V_122 ;
goto V_310;
}
F_119 ( V_4 ) ;
V_144 = NULL ;
} else {
if ( V_108 < V_4 -> V_304 )
V_144 = ( T_1 T_2 * ) ( V_4 -> V_313 +
V_108 * V_4 -> V_314 ) ;
else
V_144 = ( T_1 T_2 * )
( V_4 -> V_315 +
( V_108 - V_4 -> V_304 ) * V_4 -> V_316 ) ;
if ( V_306 )
* V_306 = V_108 ;
}
return V_144 ;
}
T_1 T_2 * F_27 ( struct V_3 * V_4 , T_1 V_317 , T_1 * V_306 )
{
T_1 T_2 * V_144 ;
T_1 V_318 , V_319 ;
T_1 V_122 , V_320 ;
if ( V_317 + 1 >= V_321 ) {
V_122 = V_4 -> V_304 ;
V_320 = V_4 -> V_322 ;
} else {
V_122 = 0 ;
V_320 = V_4 -> V_323 ;
}
V_319 = V_4 -> V_304 + V_4 -> V_305 ;
V_144 = F_121 ( V_4 , & V_318 , V_122 , V_319 , V_320 ) ;
if ( V_144 ) {
if ( V_317 + 1 >= V_321 )
V_4 -> V_322 = V_318 + 1 ;
else
V_4 -> V_323 = V_318 + 1 ;
if ( V_4 -> V_301 )
V_4 -> V_301 = 0 ;
if ( V_4 -> V_303 )
V_4 -> V_303 = 0 ;
F_43 ( V_54 , L_159 ,
V_318 , ( V_318 < V_4 -> V_304 ) ? 2 : 4 , V_144 ) ;
if ( V_306 )
* V_306 = V_318 ;
}
return V_144 ;
}
void F_124 ( struct V_3 * V_4 , unsigned V_70 ,
unsigned V_52 , int V_324 )
{
unsigned long V_13 ;
unsigned V_325 , V_41 = 0 ;
V_70 *= 2 ;
V_325 = V_70 + V_52 * 2 ;
F_8 ( & V_285 , V_13 ) ;
while ( V_70 < V_325 ) {
if ( V_324 ) {
unsigned long V_282 ;
int V_108 , V_293 ;
V_108 = V_70 / V_326 ;
V_293 = ( V_108 > 3 && ( V_4 -> V_32 & V_290 ) ) ?
V_108 ^ 1 : V_108 ;
F_125 ( V_292
+ V_70 , V_4 -> V_284 ) ;
V_282 = ( unsigned long ) F_114 (
V_4 -> V_96 [ V_293 ] ) ;
if ( F_92 ( ( V_327
+ V_70 ) % V_326 , & V_282 ) )
F_126 ( V_327
+ V_70 , V_4 -> V_284 ) ;
else
F_125 ( V_327
+ V_70 , V_4 -> V_284 ) ;
F_126 ( V_70 , V_4 -> V_291 ) ;
} else {
F_126 ( V_70 + V_292 ,
V_4 -> V_284 ) ;
F_125 ( V_70 , V_4 -> V_291 ) ;
}
V_70 += 2 ;
}
if ( V_4 -> V_328 ) {
V_325 = 2 * ( V_4 -> V_304 + V_4 -> V_305 ) ;
V_41 = F_127 ( V_4 -> V_291 , V_325 ) ;
}
F_11 ( & V_285 , V_13 ) ;
if ( ! V_324 && V_52 < V_41 )
V_41 = V_52 ;
if ( V_41 < V_4 -> V_328 ) {
V_4 -> V_328 = V_41 ;
F_5 ( L_160 ,
V_4 -> V_328 ) ;
F_8 ( & V_4 -> V_125 , V_13 ) ;
V_4 -> V_128 &= ~ ( V_312
<< V_311 ) ;
V_4 -> V_128 |= V_4 -> V_328
<< V_311 ;
F_84 ( V_4 , V_4 -> V_126 -> V_127 ,
V_4 -> V_128 ) ;
F_11 ( & V_4 -> V_125 , V_13 ) ;
}
}
int F_128 ( struct V_3 * V_4 ,
struct V_87 * V_119 )
{
int V_9 = 0 ;
if ( ! V_119 -> V_250 ) {
T_4 V_329 ;
T_7 V_330 = V_331 | V_332 ;
int V_333 = F_129 ( V_4 -> V_241 * V_4 -> V_239 *
sizeof( T_1 ) , V_97 ) ;
V_119 -> V_250 = F_130 (
& V_4 -> V_23 -> V_6 , V_333 , & V_119 -> V_334 ,
V_330 ) ;
if ( ! V_119 -> V_250 ) {
F_4 ( V_4 , L_161
L_162 ,
V_333 , V_119 -> V_273 ) ;
V_9 = - V_18 ;
goto V_19;
}
if ( ! ( V_4 -> V_32 & V_252 ) ) {
V_119 -> V_335 = F_130 (
& V_4 -> V_23 -> V_6 , V_97 , & V_329 ,
V_20 ) ;
if ( ! V_119 -> V_335 ) {
F_4 ( V_4 , L_163
L_164
L_165 , V_119 -> V_273 ) ;
V_9 = - V_18 ;
F_70 ( & V_4 -> V_23 -> V_6 , V_333 ,
V_119 -> V_250 ,
V_119 -> V_334 ) ;
V_119 -> V_250 = NULL ;
goto V_19;
}
V_119 -> V_336 = V_329 ;
F_43 ( V_54 , L_166
L_167 , V_119 -> V_273 ,
( unsigned long long ) V_329 ) ;
}
V_119 -> V_101 = V_333 ;
F_43 ( V_54 , L_168
L_169 ,
V_333 >> V_337 , V_119 -> V_250 ,
( unsigned long ) V_119 -> V_334 ,
( unsigned long ) V_119 -> V_101 ,
V_119 -> V_273 ) ;
}
else
F_43 ( V_54 , L_170
L_171 ,
V_119 -> V_273 , V_119 -> V_250 ,
( unsigned long long ) V_119 -> V_334 ,
V_119 -> V_335 , ( unsigned long long )
V_119 -> V_336 ) ;
memset ( V_119 -> V_250 , 0 , V_119 -> V_101 ) ;
if ( V_119 -> V_335 )
memset ( V_119 -> V_335 , 0 , V_97 ) ;
F_131 ( V_4 , V_4 -> V_126 -> V_338 ,
V_119 -> V_273 , V_119 -> V_336 ) ;
F_131 ( V_4 , V_4 -> V_126 -> V_339 ,
V_119 -> V_273 , V_119 -> V_334 ) ;
V_19:
return V_9 ;
}
void F_132 ( struct V_3 * V_4 , int V_340 )
{
unsigned long V_13 ;
if ( V_4 -> V_32 & V_341 ) {
F_43 ( V_54 , L_172 ) ;
goto V_19;
}
if ( V_4 -> V_32 & V_342 ) {
int V_343 ;
unsigned long * V_344 = & V_4 -> V_163 ;
F_8 ( & V_4 -> V_345 , V_13 ) ;
V_343 =
F_133 ( V_162 , V_344 )
&& ! F_92 ( V_346 , V_344 ) ;
F_11 ( & V_4 -> V_345 , V_13 ) ;
if ( V_343 )
goto V_19;
}
F_5 ( L_173 ) ;
V_4 -> V_347 = V_48 + V_348 / 2 ;
F_8 ( & V_4 -> V_125 , V_13 ) ;
V_4 -> V_128 &= ~ ( V_349
| V_350 ) ;
F_84 ( V_4 , V_4 -> V_126 -> V_127 ,
V_4 -> V_128 | V_351 ) ;
F_85 ( V_4 , V_4 -> V_126 -> V_131 ) ;
F_11 ( & V_4 -> V_125 , V_13 ) ;
F_38 ( V_4 , 0 ,
V_4 -> V_304 + V_4 -> V_305 ) ;
if ( V_4 -> V_32 & V_342 )
F_134 ( V_352 , & V_4 -> V_163 ) ;
if ( V_340 ) {
F_8 ( & V_4 -> V_125 , V_13 ) ;
V_4 -> V_128 |= V_349 |
V_350 ;
F_84 ( V_4 , V_4 -> V_126 -> V_127 ,
V_4 -> V_128 ) ;
F_85 ( V_4 , V_4 -> V_126 -> V_131 ) ;
F_11 ( & V_4 -> V_125 , V_13 ) ;
}
if ( ( V_4 -> V_32 & V_342 ) &&
! F_92 ( V_346 , & V_4 -> V_163 ) &&
F_92 ( V_353 , & V_4 -> V_163 ) ) {
F_8 ( & V_4 -> V_345 , V_13 ) ;
V_4 -> V_354 = V_48 + V_348 ;
V_4 -> V_355 = 200 ;
if ( ! F_92 ( V_356 , & V_4 -> V_163 ) )
F_135 ( & V_4 -> V_357 ) ;
F_11 ( & V_4 -> V_345 , V_13 ) ;
}
V_19: ;
}
void F_86 ( struct V_3 * V_4 )
{
unsigned long V_13 ;
F_8 ( & V_4 -> V_125 , V_13 ) ;
if ( V_4 -> V_128 & V_349 ) {
F_84 ( V_4 , V_4 -> V_126 -> V_127 ,
V_4 -> V_128 & ~ V_349 ) ;
F_85 ( V_4 , V_4 -> V_126 -> V_131 ) ;
F_84 ( V_4 , V_4 -> V_126 -> V_127 ,
V_4 -> V_128 ) ;
F_85 ( V_4 , V_4 -> V_126 -> V_131 ) ;
}
F_11 ( & V_4 -> V_125 , V_13 ) ;
}
static void F_136 ( struct V_3 * V_4 , int V_358 ,
int V_359 )
{
T_3 V_360 ;
static const char * V_361 [ 4 ] = {
[ 0 ] = L_174 ,
[ V_362 ] = L_64 ,
[ V_363 ] = L_175 ,
[ V_364 ] = L_66
} ;
if ( V_359 == V_365 ) {
F_30 () ;
V_4 -> V_32 |= V_366 ;
F_37 () ;
} else if ( V_359 ) {
F_30 () ;
V_4 -> V_32 &= ~ V_366 ;
F_37 () ;
}
V_360 = ( V_358 << V_4 -> V_367 ) |
( V_359 << V_368 ) ;
F_43 ( V_54 ,
L_176 ,
V_4 -> V_14 , V_361 [ V_358 ] , V_359 ,
V_140 [ F_137 ( V_4 ,
F_85 ( V_4 , V_4 -> V_126 -> V_138 ) ) ] ) ;
F_84 ( V_4 , V_4 -> V_126 -> V_139 ,
V_4 -> V_231 | V_360 ) ;
( void ) F_85 ( V_4 , V_4 -> V_126 -> V_138 ) ;
}
int F_138 ( struct V_3 * V_4 , T_9 V_369 )
{
T_1 V_370 ;
int V_9 ;
switch ( V_369 ) {
case V_371 :
F_136 ( V_4 , V_362 , 0 ) ;
V_9 = 0 ;
goto V_19;
case V_372 :
F_136 ( V_4 , V_362 ,
V_373 ) ;
V_9 = 0 ;
goto V_19;
case V_374 :
F_136 ( V_4 , V_362 ,
V_375 ) ;
V_9 = 0 ;
goto V_19;
case V_376 :
F_136 ( V_4 , V_362 ,
V_365 ) ;
V_9 = 0 ;
goto V_19;
case V_377 :
if ( V_4 -> V_32 & V_137 ) {
V_9 = 0 ;
goto V_19;
}
if ( ! ( V_4 -> V_32 &
( V_136 | V_378 ) ) ) {
V_9 = - V_379 ;
goto V_19;
}
F_136 ( V_4 , V_363 , 0 ) ;
V_370 = V_137 | V_378 ;
break;
case V_380 :
if ( V_4 -> V_32 & V_378 ) {
V_9 = 0 ;
goto V_19;
}
if ( ! ( V_4 -> V_32 & V_137 ) ) {
V_9 = - V_379 ;
goto V_19;
}
F_136 ( V_4 , V_364 , 0 ) ;
V_370 = V_378 ;
break;
case V_381 :
F_28 ( & V_4 -> V_23 -> V_6 , L_177 ) ;
V_4 -> V_231 |= V_382 ;
F_84 ( V_4 , V_4 -> V_126 -> V_139 ,
V_4 -> V_231 ) ;
V_4 -> V_383 ( V_4 , V_384 ,
V_385 ) ;
V_9 = 0 ;
goto V_19;
case V_386 :
F_28 ( & V_4 -> V_23 -> V_6 ,
L_178 ) ;
V_4 -> V_383 ( V_4 , V_384 ,
V_387 ) ;
V_4 -> V_231 &= ~ V_382 ;
F_84 ( V_4 , V_4 -> V_126 -> V_139 ,
V_4 -> V_231 ) ;
V_9 = 0 ;
goto V_19;
case V_388 :
V_9 = V_4 -> V_383 ( V_4 , V_384 ,
V_387 ) ;
goto V_19;
case V_389 :
V_9 = V_4 -> V_383 ( V_4 , V_384 ,
V_385 ) ;
goto V_19;
default:
F_5 ( L_179 , V_369 ) ;
V_9 = - V_379 ;
goto V_19;
}
V_9 = F_87 ( V_4 , V_370 , 2000 ) ;
V_19:
return V_9 ;
}
int F_139 ( struct V_3 * V_4 , T_11 V_390 )
{
T_1 V_391 ;
int V_392 = 0 ;
int V_9 ;
if ( V_390 != 256 && V_390 != 512 && V_390 != 1024 && V_390 != 2048 &&
( V_390 != 4096 || ! V_393 ) ) {
F_5 ( L_180 , V_390 ) ;
V_9 = - V_379 ;
goto V_19;
}
if ( V_4 -> V_394 == V_390 ) {
V_9 = 0 ;
goto V_19;
}
V_391 = V_4 -> V_219 ;
V_4 -> V_394 = V_390 ;
if ( V_390 >= ( V_391 - V_395 ) ) {
if ( V_391 != V_4 -> V_396 ) {
if ( V_390 > V_391 && V_390 <= V_4 -> V_396 )
V_391 = V_4 -> V_396 ;
V_4 -> V_219 = V_391 ;
V_392 = 1 ;
}
} else if ( ( V_390 + V_395 ) != V_4 -> V_219 ) {
V_391 = V_390 + V_395 ;
F_43 ( V_54 , L_181
L_182 , V_4 -> V_219 , V_391 ,
V_390 ) ;
V_4 -> V_219 = V_391 ;
V_392 = 1 ;
}
if ( V_392 ) {
T_3 V_397 = V_4 -> V_231 , V_398 ;
V_4 -> V_219 = V_391 - 2 * sizeof( T_1 ) ;
V_398 = ( V_4 -> V_219 >> 2 ) + 1 ;
V_397 &= ~ ( V_399 <<
V_4 -> V_400 ) ;
V_397 |= V_398 << V_4 -> V_400 ;
V_4 -> V_231 = V_397 ;
F_84 ( V_4 , V_4 -> V_126 -> V_139 ,
V_4 -> V_231 ) ;
V_4 -> V_401 ( V_4 ) ;
}
V_9 = 0 ;
V_19:
return V_9 ;
}
int F_140 ( struct V_3 * V_4 , T_1 V_402 , T_9 V_403 )
{
V_4 -> V_35 = V_402 ;
V_4 -> V_404 = V_403 ;
V_4 -> V_383 ( V_4 , V_405 , V_402 |
( ~ ( ( 1U << V_403 ) - 1 ) ) << 16 ) ;
F_28 ( & V_4 -> V_23 -> V_6 , L_183 , V_402 ) ;
return 0 ;
}
void F_131 ( const struct V_3 * V_4 , T_12 V_406 ,
unsigned V_86 , T_3 V_407 )
{
T_11 V_408 ;
if ( V_86 < V_4 -> V_118 &&
( V_406 == V_4 -> V_126 -> V_339 ||
V_406 == V_4 -> V_126 -> V_338 ) )
V_408 = V_406 + V_86 ;
else
V_408 = - 1 ;
F_84 ( V_4 , V_408 , V_407 ) ;
}
static void F_141 ( unsigned long V_409 )
{
struct V_3 * V_4 = (struct V_3 * ) V_409 ;
int V_410 ;
int V_411 ;
T_3 V_370 , V_412 , V_135 ;
if ( ! ( V_4 -> V_32 & V_413 ) )
return;
V_411 = V_4 -> V_414 ++ & 1 ;
V_4 -> V_415 = V_4 -> V_416 [ V_411 ] ;
V_410 = V_4 -> V_417 ;
V_135 = F_85 ( V_4 , V_4 -> V_126 -> V_138 ) ;
V_412 = F_137 ( V_4 , V_135 ) ;
V_370 = F_142 ( V_4 , V_135 ) ;
V_4 -> V_418 ( V_4 , V_370 , V_412 ) ;
F_143 ( & V_4 -> V_419 , V_48 + V_410 ) ;
}
void F_144 ( struct V_3 * V_4 , unsigned int V_135 )
{
int V_410 , V_420 ;
if ( ! ( V_4 -> V_32 & V_413 ) )
return;
V_410 = V_348 ;
V_420 = ( V_135 & V_421 ) >> V_422 ;
if ( V_420 ) {
V_4 -> V_416 [ 0 ] = V_135 & 0xF ;
V_4 -> V_416 [ 1 ] = ( V_135 >> 4 ) & 0xF ;
V_410 = ( V_348 << 4 ) / V_420 ;
} else {
V_4 -> V_416 [ 0 ] = V_135 & 0xF ;
V_4 -> V_416 [ 1 ] = V_135 & 0xF ;
}
V_4 -> V_417 = V_410 ;
if ( F_145 ( & V_4 -> V_423 ) == 1 ) {
F_146 ( & V_4 -> V_419 ) ;
V_4 -> V_419 . V_424 =
F_141 ;
V_4 -> V_419 . V_216 = ( unsigned long ) V_4 ;
V_4 -> V_419 . V_425 = V_48 + 1 ;
F_147 ( & V_4 -> V_419 ) ;
} else
F_148 ( & V_4 -> V_423 ) ;
}
void F_77 ( struct V_3 * V_4 )
{
unsigned long V_13 ;
F_5 ( L_184 ) ;
F_149 ( V_4 ) ;
V_4 -> V_32 |= V_38 ;
V_4 -> V_32 &= ~ ( V_413 | V_37 |
V_136 | V_137 |
V_378 ) ;
* V_4 -> V_89 &= ~ ( V_426 |
V_427 ) ;
F_84 ( V_4 , V_4 -> V_126 -> V_428 , 0ULL ) ;
V_4 -> V_429 = 0 ;
F_84 ( V_4 , V_4 -> V_126 -> V_430 ,
V_4 -> V_429 ) ;
if ( V_4 -> V_32 & V_342 )
F_150 ( V_4 ) ;
F_8 ( & V_4 -> V_125 , V_13 ) ;
V_4 -> V_128 = 0 ;
F_84 ( V_4 , V_4 -> V_126 -> V_127 , V_4 -> V_128 ) ;
F_85 ( V_4 , V_4 -> V_126 -> V_131 ) ;
F_11 ( & V_4 -> V_125 , V_13 ) ;
F_32 ( 5 ) ;
V_4 -> V_418 ( V_4 , 0 , 0 ) ;
F_136 ( V_4 , 0 , V_365 ) ;
F_132 ( V_4 , 0 ) ;
F_151 ( V_4 , V_431 ) ;
V_4 -> V_432 &= ~ V_433 ;
F_84 ( V_4 , V_4 -> V_126 -> V_434 ,
V_4 -> V_432 | V_435 ) ;
V_4 -> V_436 ( V_4 ) ;
F_152 ( & V_4 -> V_437 ) ;
if ( V_4 -> V_438 ) {
F_152 ( & V_4 -> V_439 ) ;
V_4 -> V_438 = 0 ;
}
if ( V_4 -> V_440 . V_216 ) {
F_152 ( & V_4 -> V_440 ) ;
V_4 -> V_440 . V_216 = 0 ;
}
if ( F_153 ( & V_4 -> V_423 ) ) {
F_152 ( & V_4 -> V_419 ) ;
F_154 ( & V_4 -> V_423 , 0 ) ;
}
F_84 ( V_4 , V_4 -> V_126 -> V_441 ,
~ 0ULL & ~ V_442 ) ;
F_84 ( V_4 , V_4 -> V_126 -> V_443 , - 1LL ) ;
F_84 ( V_4 , V_4 -> V_126 -> V_444 , - 1LL ) ;
F_43 ( V_54 , L_185 ) ;
F_155 ( V_4 ) ;
}
void F_73 ( struct V_3 * V_4 , struct V_87 * V_119 )
{
if ( ! V_119 )
return;
if ( V_119 -> V_250 ) {
F_43 ( V_54 , L_186
L_187 , V_119 -> V_273 , V_119 -> V_250 ,
( unsigned long ) V_119 -> V_101 ) ;
F_70 ( & V_4 -> V_23 -> V_6 , V_119 -> V_101 ,
V_119 -> V_250 , V_119 -> V_334 ) ;
V_119 -> V_250 = NULL ;
if ( V_119 -> V_335 ) {
F_70 ( & V_4 -> V_23 -> V_6 , V_97 ,
V_119 -> V_335 ,
V_119 -> V_336 ) ;
V_119 -> V_335 = NULL ;
}
}
if ( V_119 -> V_273 && V_119 -> V_445 ) {
unsigned V_446 ;
for ( V_446 = 0 ; V_446 < V_119 -> V_447 ; V_446 ++ ) {
void * V_448 = V_119 -> V_445 [ V_446 ] ;
T_6 V_449 = V_119 -> V_450 ;
F_43 ( V_54 , L_188
L_189 , V_448 ,
( unsigned long ) V_449 ,
V_446 , V_119 -> V_447 ) ;
F_70 ( & V_4 -> V_23 -> V_6 , V_449 ,
V_448 , V_119 -> V_451 [ V_446 ] ) ;
}
F_74 ( V_119 -> V_445 ) ;
V_119 -> V_445 = NULL ;
F_74 ( V_119 -> V_451 ) ;
V_119 -> V_451 = NULL ;
V_119 -> V_447 = 0 ;
} else if ( V_119 -> V_273 == 0 && V_4 -> V_214 ) {
unsigned V_446 ;
struct V_452 * V_453 = V_4 -> V_214 ;
V_4 -> V_214 = NULL ;
F_43 ( V_54 , L_190
L_191 , V_119 -> V_273 ,
V_453 ) ;
for ( V_446 = 0 ; V_446 < V_4 -> V_454 ; V_446 ++ )
if ( V_453 [ V_446 ] . V_215 ) {
F_156 ( V_4 -> V_23 , V_453 [ V_446 ] . V_455 ,
V_4 -> V_219 ,
V_112 ) ;
F_157 ( V_453 [ V_446 ] . V_215 ) ;
}
F_12 ( V_453 ) ;
}
F_74 ( V_119 -> V_456 ) ;
F_12 ( V_119 -> V_457 ) ;
F_12 ( V_119 -> V_458 ) ;
F_12 ( V_119 -> V_459 ) ;
F_74 ( V_119 ) ;
}
static int T_13 F_158 ( void )
{
int V_9 ;
if ( V_166 & V_460 )
F_18 (KERN_INFO DRIVER_LOAD_MSG L_192 , ib_ipath_version) ;
F_159 ( & V_16 ) ;
V_9 = F_160 ( & V_461 ) ;
if ( V_9 < 0 ) {
F_18 (KERN_ERR IPATH_DRV_NAME
L_193 , -ret) ;
goto V_462;
}
V_9 = F_161 () ;
if ( V_9 < 0 ) {
F_18 (KERN_ERR IPATH_DRV_NAME L_194
L_195 , -ret) ;
goto V_463;
}
goto V_19;
V_463:
F_162 ( & V_461 ) ;
V_462:
F_163 ( & V_16 ) ;
V_19:
return V_9 ;
}
static void T_14 F_164 ( void )
{
F_165 () ;
F_43 ( V_54 , L_196 ) ;
F_162 ( & V_461 ) ;
F_163 ( & V_16 ) ;
}
int F_166 ( int V_1 )
{
int V_9 , V_108 ;
struct V_3 * V_4 = F_23 ( V_1 ) ;
unsigned long V_13 ;
if ( ! V_4 ) {
V_9 = - V_61 ;
goto V_19;
}
if ( F_153 ( & V_4 -> V_423 ) ) {
F_152 ( & V_4 -> V_419 ) ;
F_154 ( & V_4 -> V_423 , 0 ) ;
}
V_4 -> V_415 = V_464 ;
V_4 -> V_418 ( V_4 , 0 , 0 ) ;
F_28 ( & V_4 -> V_23 -> V_6 , L_197 , V_1 ) ;
if ( ! V_4 -> V_34 || ! ( V_4 -> V_32 & V_33 ) ) {
F_28 ( & V_4 -> V_23 -> V_6 , L_198
L_199 , V_1 ) ;
V_9 = - V_465 ;
goto V_19;
}
F_8 ( & V_4 -> V_117 , V_13 ) ;
if ( V_4 -> V_100 )
for ( V_108 = 1 ; V_108 < V_4 -> V_39 ; V_108 ++ ) {
if ( ! V_4 -> V_100 [ V_108 ] || ! V_4 -> V_100 [ V_108 ] -> V_466 )
continue;
F_11 ( & V_4 -> V_117 , V_13 ) ;
F_5 ( L_200
L_201 ,
V_1 , V_108 ,
F_167 ( V_4 -> V_100 [ V_108 ] -> V_467 ) ,
V_4 -> V_100 [ V_108 ] -> V_468 ) ;
V_9 = - V_469 ;
goto V_19;
}
F_11 ( & V_4 -> V_117 , V_13 ) ;
if ( V_4 -> V_32 & V_342 )
F_150 ( V_4 ) ;
V_4 -> V_32 &= ~ V_413 ;
F_84 ( V_4 , V_4 -> V_126 -> V_428 , 0ULL ) ;
V_9 = V_4 -> V_470 ( V_4 ) ;
if ( V_9 == 1 ) {
F_5 ( L_202 ,
V_1 ) ;
V_9 = F_58 ( V_4 , 1 ) ;
} else
V_9 = - V_298 ;
if ( V_9 )
F_4 ( V_4 , L_203
L_204 , V_1 , V_9 ) ;
else
F_28 ( & V_4 -> V_23 -> V_6 , L_205
L_206 , V_1 ) ;
V_19:
return V_9 ;
}
static int F_168 ( struct V_3 * V_4 , int V_471 )
{
int V_108 , V_472 , V_473 = 0 ;
struct V_474 * V_474 ;
unsigned long V_13 ;
if ( ! V_4 -> V_100 )
return 0 ;
F_8 ( & V_4 -> V_117 , V_13 ) ;
for ( V_108 = 1 ; V_108 < V_4 -> V_39 ; V_108 ++ ) {
if ( ! V_4 -> V_100 [ V_108 ] || ! V_4 -> V_100 [ V_108 ] -> V_466 )
continue;
V_474 = V_4 -> V_100 [ V_108 ] -> V_467 ;
if ( ! V_474 )
continue;
F_28 ( & V_4 -> V_23 -> V_6 , L_207
L_208 ,
V_108 , F_167 ( V_474 ) , V_471 ) ;
F_169 ( V_474 , V_471 , 1 ) ;
V_473 ++ ;
for ( V_472 = 0 ; V_472 < V_475 ; V_472 ++ ) {
V_474 = V_4 -> V_100 [ V_108 ] -> V_476 [ V_472 ] ;
if ( ! V_474 )
continue;
F_28 ( & V_4 -> V_23 -> V_6 , L_209
L_210
L_211 , V_108 , V_472 , F_167 ( V_474 ) , V_471 ) ;
F_169 ( V_474 , V_471 , 1 ) ;
V_473 ++ ;
}
}
F_11 ( & V_4 -> V_117 , V_13 ) ;
return V_473 ;
}
static void F_170 ( struct V_3 * V_4 )
{
if ( F_168 ( V_4 , V_477 ) )
F_5 ( L_212 ) ;
F_132 ( V_4 , 1 ) ;
}
static void F_171 ( struct V_3 * V_4 )
{
if ( F_168 ( V_4 , V_478 ) )
F_5 ( L_213 ) ;
}
void F_172 ( struct V_3 * V_4 )
{
V_4 -> V_479 = V_480 ;
F_170 ( V_4 ) ;
V_4 -> V_481 = V_482 ;
V_4 -> V_437 . V_425 = V_48 +
F_89 ( V_483 ) ;
F_143 ( & V_4 -> V_437 , V_4 -> V_437 . V_425 ) ;
}
void F_149 ( struct V_3 * V_4 )
{
F_171 ( V_4 ) ;
V_4 -> V_479 = V_484 ;
}
void F_173 ( unsigned long V_409 )
{
struct V_3 * V_4 = (struct V_3 * ) V_409 ;
if ( V_4 -> V_481 == V_485
&& V_4 -> V_479 != V_484 ) {
V_4 -> V_481 = V_482 ;
F_5 ( L_214 ) ;
F_170 ( V_4 ) ;
} else {
V_4 -> V_481 = V_485 ;
F_5 ( L_215 ) ;
F_171 ( V_4 ) ;
}
if ( V_4 -> V_479 == V_484 )
F_5 ( L_216 ) ;
else {
V_4 -> V_437 . V_425 = V_48 +
F_89 ( V_483 ) ;
F_143 ( & V_4 -> V_437 ,
V_4 -> V_437 . V_425 ) ;
}
}
int F_174 ( struct V_3 * V_4 , T_9 V_486 )
{
T_3 V_135 ;
if ( V_486 > V_487 )
return - 1 ;
if ( V_4 -> V_488 != V_486 ) {
V_4 -> V_488 = V_486 ;
V_135 = F_85 ( V_4 , V_4 -> V_126 -> V_489 ) ;
V_135 &= ~ ( V_487 <<
V_490 ) ;
V_135 |= ( ( T_3 ) V_4 -> V_488 ) <<
V_490 ;
F_84 ( V_4 , V_4 -> V_126 -> V_489 , V_135 ) ;
}
return 0 ;
}
void F_39 ( struct V_3 * V_4 )
{
V_4 -> V_491 &= ~ V_188 ;
F_84 ( V_4 , V_4 -> V_126 -> V_443 ,
V_188 ) ;
V_4 -> V_492 |= V_188 ;
F_84 ( V_4 , V_4 -> V_126 -> V_493 ,
V_4 -> V_492 ) ;
}
void F_33 ( struct V_3 * V_4 )
{
V_4 -> V_494 &= ~ V_188 ;
V_4 -> V_492 &= ~ V_188 ;
F_84 ( V_4 , V_4 -> V_126 -> V_493 ,
V_4 -> V_492 ) ;
}
