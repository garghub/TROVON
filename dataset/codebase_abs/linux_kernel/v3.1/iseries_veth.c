static inline void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_5 = V_2 -> V_6 ;
V_2 -> V_6 = V_4 ;
}
static inline struct V_3 * F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = V_2 -> V_6 ;
if ( V_4 )
V_2 -> V_6 = V_2 -> V_6 -> V_5 ;
return V_4 ;
}
static inline int F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_6 == NULL ;
}
static inline T_1
F_4 ( struct V_1 * V_2 , T_2 V_7 ,
T_3 V_8 , T_4 V_9 ,
T_5 V_10 ,
T_5 V_11 , T_5 V_12 , T_5 V_13 , T_5 V_14 , T_5 V_15 )
{
return F_5 ( V_2 -> V_16 ,
V_17 ,
V_7 , V_8 , V_9 ,
V_2 -> V_18 ,
V_2 -> V_19 ,
V_10 , V_11 , V_12 , V_13 ,
V_14 , V_15 ) ;
}
static inline T_1 F_6 ( struct V_1 * V_2 ,
T_2 V_7 , T_5 V_10 , void * V_20 )
{
T_5 * V_21 = ( T_5 * ) V_20 ;
return F_4 ( V_2 , V_7 , V_22 ,
V_23 ,
V_10 , V_21 [ 0 ] , V_21 [ 1 ] , V_21 [ 2 ] , V_21 [ 3 ] , V_21 [ 4 ] ) ;
}
static void F_7 ( void * V_24 , int V_25 )
{
struct V_26 * V_27 = (struct V_26 * ) V_24 ;
V_27 -> V_28 = V_25 ;
F_8 ( & V_27 -> V_29 ) ;
}
static int F_9 ( T_6 V_30 , int V_25 )
{
struct V_26 V_27 =
{ F_10 ( V_27 . V_29 ) , 0 } ;
F_11 ( V_30 , V_17 ,
sizeof( struct V_31 ) , V_25 ,
& F_7 , & V_27 ) ;
F_12 ( & V_27 . V_29 ) ;
return V_27 . V_28 ;
}
static T_7 F_13 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 )
{
struct V_37 * V_38 ;
struct V_1 * V_2 ;
V_38 = F_14 ( V_35 , struct V_37 , V_35 ) ;
V_2 = F_14 ( V_33 , struct V_1 , V_32 ) ;
if ( ! V_38 -> V_39 )
return - V_40 ;
return V_38 -> V_39 ( V_2 , V_36 ) ;
}
static T_7 F_15 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 )
{
struct V_41 * V_42 ;
struct V_43 * V_44 ;
V_42 = F_14 ( V_35 , struct V_41 , V_35 ) ;
V_44 = F_14 ( V_33 , struct V_43 , V_32 ) ;
if ( ! V_42 -> V_39 )
return - V_40 ;
return V_42 -> V_39 ( V_44 , V_36 ) ;
}
static inline void F_16 ( struct V_1 * V_2 )
{
F_17 ( & V_2 -> V_45 , 0 ) ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_31 * V_46 )
{
unsigned long V_47 ;
F_19 ( & V_2 -> V_48 , V_47 ) ;
V_2 -> V_19 =
F_20 ( V_2 -> V_16 ,
V_17 ) ;
if ( V_2 -> V_49 & V_50 ) {
F_21 ( L_1 ,
V_2 -> V_16 ) ;
V_46 -> V_51 . V_52 = V_53 ;
F_22 ( (struct V_54 * ) V_46 ) ;
} else {
memcpy ( & V_2 -> V_55 , V_46 , sizeof( V_2 -> V_55 ) ) ;
V_2 -> V_49 |= V_50 ;
F_16 ( V_2 ) ;
}
F_23 ( & V_2 -> V_48 , V_47 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_31 * V_46 )
{
unsigned long V_47 ;
F_19 ( & V_2 -> V_48 , V_47 ) ;
if ( V_2 -> V_49 & V_56 ) {
F_21 ( L_2 ,
V_2 -> V_16 ) ;
} else {
memcpy ( & V_2 -> V_57 , V_46 ,
sizeof( V_2 -> V_57 ) ) ;
V_2 -> V_49 |= V_56 ;
F_16 ( V_2 ) ;
}
F_23 ( & V_2 -> V_48 , V_47 ) ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_31 * V_46 )
{
unsigned long V_47 ;
F_19 ( & V_2 -> V_48 , V_47 ) ;
F_26 ( L_3 , V_2 -> V_16 ) ;
if ( ! ( V_2 -> V_49 & V_58 ) ) {
V_2 -> V_49 |= V_59 ;
F_16 ( V_2 ) ;
}
F_23 ( & V_2 -> V_48 , V_47 ) ;
}
static void F_27 ( struct V_31 * V_46 )
{
T_6 V_30 = V_46 -> V_51 . V_60 ;
struct V_1 * V_2 = V_61 [ V_30 ] ;
F_28 ( ! V_2 ) ;
switch ( V_46 -> V_51 . V_62 ) {
case V_63 :
F_24 ( V_2 , V_46 ) ;
break;
case V_64 :
F_25 ( V_2 , V_46 ) ;
break;
default:
F_21 ( L_4 ,
V_46 -> V_51 . V_62 , V_30 ) ;
}
}
static void F_29 ( struct V_31 * V_46 )
{
T_6 V_30 = V_46 -> V_51 . V_65 ;
struct V_1 * V_2 = V_61 [ V_30 ] ;
unsigned long V_47 ;
int V_66 , V_67 = 0 ;
F_28 ( ! V_2 ) ;
switch ( V_46 -> V_51 . V_62 ) {
case V_63 :
F_18 ( V_2 , V_46 ) ;
break;
case V_64 :
break;
case V_68 :
F_19 ( & V_2 -> V_48 , V_47 ) ;
for ( V_66 = 0 ; V_66 < V_69 ; ++ V_66 ) {
T_2 V_70 = V_46 -> V_71 . V_72 . V_10 [ V_66 ] ;
if ( V_70 < V_73 ) {
F_30 ( V_2 , V_2 -> V_74 + V_70 ) ;
V_2 -> V_75 -- ;
V_67 ++ ;
}
}
if ( V_67 > 0 ) {
V_2 -> V_76 = V_77 ;
F_31 ( V_2 ) ;
}
F_23 ( & V_2 -> V_48 , V_47 ) ;
break;
case V_78 :
F_32 ( V_2 , V_46 ) ;
break;
default:
F_21 ( L_5 ,
V_46 -> V_51 . V_62 , V_30 ) ;
}
}
static void F_33 ( struct V_54 * V_46 )
{
struct V_31 * V_79 = (struct V_31 * ) V_46 ;
if ( F_34 ( V_46 ) )
F_27 ( V_79 ) ;
else
F_29 ( V_79 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_80 * V_81 = & V_2 -> V_81 ;
int V_82 ;
V_2 -> V_83 = V_81 -> V_83 * V_84 / 1000000 ;
if ( ( V_81 -> V_85 == 0 ) ||
( V_81 -> V_86 > V_69 ) ||
( V_81 -> V_86 == 0 ) ||
( V_2 -> V_83 == 0 ) ) {
F_21 ( L_6 ,
V_2 -> V_16 ) ;
return V_87 ;
}
V_82 = ( V_81 -> V_85
/ V_81 -> V_86 ) + 1 ;
if ( V_2 -> V_88 < V_82 ) {
int V_28 ;
V_28 = F_9 ( V_2 -> V_16 ,
V_82 - V_2 -> V_88 ) ;
if ( V_28 > 0 )
V_2 -> V_88 += V_28 ;
if ( V_2 -> V_88 < V_82 ) {
F_21 ( L_7
L_8 , V_2 -> V_16 ) ;
return V_53 ;
}
}
return V_89 ;
}
static void F_36 ( struct V_90 * V_91 )
{
struct V_1 * V_2 =
F_14 ( V_91 , struct V_1 ,
V_45 . V_91 ) ;
int V_30 = V_2 -> V_16 ;
int V_92 ;
F_37 ( & V_2 -> V_48 ) ;
V_93:
if ( V_2 -> V_49 & V_59 ) {
if ( V_2 -> V_49 & V_94 )
F_38 ( V_2 -> V_16 ,
V_17 ) ;
memset ( & V_2 -> V_95 , 0xff , sizeof ( V_2 -> V_95 ) ) ;
V_2 -> V_96 = 0 ;
V_2 -> V_49 &= ~ ( V_59 | V_97
| V_94 | V_98
| V_56 | V_50
| V_99 | V_100 ) ;
if ( V_2 -> V_74 ) {
int V_66 ;
for ( V_66 = 0 ; V_66 < V_73 ; ++ V_66 )
F_30 ( V_2 , V_2 -> V_74 + V_66 ) ;
}
V_2 -> V_75 = 0 ;
F_31 ( V_2 ) ;
F_39 ( & V_2 -> V_48 ) ;
F_40 ( & V_2 -> V_101 ) ;
F_40 ( & V_2 -> V_102 ) ;
F_37 ( & V_2 -> V_48 ) ;
if ( V_2 -> V_49 & V_59 )
goto V_93;
if ( ! ( V_2 -> V_49 & V_58 ) ) {
F_17 ( & V_2 -> V_45 , 5 * V_84 ) ;
goto V_103;
}
}
if ( V_2 -> V_49 & V_58 )
goto V_103;
if ( ! ( V_2 -> V_49 & V_94 ) ) {
if ( ! V_2 -> V_74 || ( V_2 -> V_104 < ( 2 + V_73 ) ) )
goto V_105;
F_41 ( V_30 , V_17 ) ;
V_2 -> V_18 =
F_42 ( V_30 ,
V_17 ) ;
V_2 -> V_19 =
F_20 ( V_30 ,
V_17 ) ;
V_2 -> V_49 |= V_94 ;
}
if ( ( V_2 -> V_49 & V_94 ) &&
! ( V_2 -> V_49 & V_97 ) ) {
V_92 = F_4 ( V_2 , V_64 ,
V_106 ,
V_107 ,
0 , 0 , 0 , 0 , 0 , 0 ) ;
if ( V_92 == V_89 ) {
V_2 -> V_49 |= V_97 ;
} else {
if ( ( V_92 != V_108 ) &&
( V_92 != V_109 ) )
F_21 ( L_9
L_10 , V_30 , V_92 ) ;
goto V_103;
}
}
if ( ( V_2 -> V_49 & V_94 ) &&
! ( V_2 -> V_49 & V_98 ) ) {
T_5 * V_110 = ( T_5 * ) & V_2 -> V_111 ;
V_92 = F_4 ( V_2 , V_63 ,
V_106 ,
V_23 ,
0 , V_110 [ 0 ] , V_110 [ 1 ] , V_110 [ 2 ] ,
V_110 [ 3 ] , V_110 [ 4 ] ) ;
if ( V_92 == V_89 ) {
V_2 -> V_49 |= V_98 ;
} else {
if ( ( V_92 != V_108 ) &&
( V_92 != V_109 ) )
F_21 ( L_11
L_10 , V_30 , V_92 ) ;
goto V_103;
}
}
if ( ( V_2 -> V_49 & V_50 ) &&
! ( V_2 -> V_49 & V_99 ) ) {
struct V_80 * V_81 = & V_2 -> V_81 ;
memcpy ( V_81 , & V_2 -> V_55 . V_71 . V_112 ,
sizeof( * V_81 ) ) ;
F_39 ( & V_2 -> V_48 ) ;
V_92 = F_35 ( V_2 ) ;
F_37 ( & V_2 -> V_48 ) ;
if ( V_2 -> V_49 & ( V_59 | V_58 ) )
goto V_93;
V_2 -> V_55 . V_51 . V_52 = V_92 ;
F_22 ( (struct V_54 * ) & V_2 -> V_55 ) ;
if ( V_92 == V_89 )
V_2 -> V_49 |= V_99 ;
else
goto V_105;
}
if ( ( V_2 -> V_49 & V_56 ) &&
( V_2 -> V_49 & V_50 ) &&
! ( V_2 -> V_49 & V_100 ) ) {
if ( V_2 -> V_57 . V_51 . V_52 == V_89 ) {
V_2 -> V_101 . V_113 = V_77 + V_2 -> V_83 ;
F_43 ( & V_2 -> V_101 ) ;
V_2 -> V_49 |= V_100 ;
} else {
F_21 ( L_12 ,
V_30 , V_2 -> V_57 . V_51 . V_52 ) ;
goto V_105;
}
}
V_103:
F_39 ( & V_2 -> V_48 ) ;
return;
V_105:
F_21 ( L_13
L_14 , V_30 , V_2 -> V_49 ) ;
V_2 -> V_49 |= V_58 ;
F_39 ( & V_2 -> V_48 ) ;
}
static int F_44 ( T_8 V_30 )
{
struct V_1 * V_2 ;
struct V_3 * V_74 ;
int V_66 ;
if ( ( V_30 == V_114 ) ||
! F_45 ( V_114 , V_30 ) )
return 0 ;
V_2 = F_46 ( sizeof( * V_2 ) , V_115 ) ;
if ( ! V_2 )
return - V_116 ;
V_2 -> V_16 = V_30 ;
F_47 ( & V_2 -> V_48 ) ;
F_48 ( & V_2 -> V_45 , F_36 ) ;
F_49 ( & V_2 -> V_101 ) ;
V_2 -> V_101 . V_117 = V_118 ;
V_2 -> V_101 . V_20 = ( unsigned long ) V_2 ;
F_49 ( & V_2 -> V_102 ) ;
V_2 -> V_102 . V_117 = V_119 ;
V_2 -> V_102 . V_20 = ( unsigned long ) V_2 ;
V_2 -> V_120 = 5 * V_84 * ( V_121 / 1000000 ) ;
memset ( & V_2 -> V_95 , 0xff , sizeof ( V_2 -> V_95 ) ) ;
V_61 [ V_30 ] = V_2 ;
F_50 ( & V_2 -> V_32 , & V_122 ) ;
V_74 = F_51 ( V_73 , sizeof( struct V_3 ) , V_115 ) ;
if ( ! V_74 ) {
F_21 ( L_15 , V_30 ) ;
return - V_116 ;
}
V_2 -> V_74 = V_74 ;
for ( V_66 = 0 ; V_66 < V_73 ; V_66 ++ ) {
V_74 [ V_66 ] . V_10 = V_66 ;
F_1 ( V_2 , V_74 + V_66 ) ;
}
V_2 -> V_104 = F_9 ( V_30 , 2 + V_73 ) ;
if ( V_2 -> V_104 < ( 2 + V_73 ) ) {
F_21 ( L_16 , V_30 ) ;
return - V_116 ;
}
V_2 -> V_111 . V_85 = V_73 ;
V_2 -> V_111 . V_86 = V_123 ;
V_2 -> V_111 . V_83 = V_121 ;
return 0 ;
}
static void F_52 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_37 ( & V_2 -> V_48 ) ;
V_2 -> V_49 |= V_59 | V_58 ;
F_16 ( V_2 ) ;
F_39 ( & V_2 -> V_48 ) ;
F_53 ( & V_2 -> V_45 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( V_2 -> V_104 > 0 )
F_55 ( V_2 -> V_16 ,
V_17 ,
V_2 -> V_104 ,
NULL , NULL ) ;
if ( V_2 -> V_88 > 0 )
F_55 ( V_2 -> V_16 ,
V_17 ,
V_2 -> V_88 ,
NULL , NULL ) ;
F_56 ( V_2 -> V_74 ) ;
V_61 [ V_2 -> V_16 ] = NULL ;
F_56 ( V_2 ) ;
}
static void F_57 ( struct V_32 * V_33 )
{
struct V_1 * V_2 ;
V_2 = F_14 ( V_33 , struct V_1 , V_32 ) ;
F_52 ( V_2 ) ;
F_54 ( V_2 ) ;
}
static int F_58 ( struct V_124 * V_125 )
{
F_59 ( V_125 ) ;
return 0 ;
}
static int F_60 ( struct V_124 * V_125 )
{
F_61 ( V_125 ) ;
return 0 ;
}
static int F_62 ( struct V_124 * V_125 , int V_126 )
{
if ( ( V_126 < 68 ) || ( V_126 > V_127 ) )
return - V_128 ;
V_125 -> V_129 = V_126 ;
return 0 ;
}
static void F_63 ( struct V_124 * V_125 )
{
struct V_43 * V_44 = F_64 ( V_125 ) ;
unsigned long V_47 ;
F_65 ( & V_44 -> V_130 , V_47 ) ;
if ( ( V_125 -> V_47 & V_131 ) || ( V_125 -> V_47 & V_132 ) ||
( F_66 ( V_125 ) > V_133 ) ) {
V_44 -> V_134 = 1 ;
} else {
struct V_135 * V_136 ;
V_44 -> V_134 = 0 ;
V_44 -> V_137 = 0 ;
F_67 (ha, dev) {
T_8 * V_138 = V_136 -> V_138 ;
T_5 V_139 = 0 ;
memcpy ( & V_139 , V_138 , V_140 ) ;
V_44 -> V_141 [ V_44 -> V_137 ] = V_139 ;
V_44 -> V_137 ++ ;
}
}
F_68 ( & V_44 -> V_130 , V_47 ) ;
}
static void F_69 ( struct V_124 * V_125 , struct V_142 * V_143 )
{
strncpy ( V_143 -> V_144 , V_145 , sizeof( V_143 -> V_144 ) - 1 ) ;
V_143 -> V_144 [ sizeof( V_143 -> V_144 ) - 1 ] = '\0' ;
strncpy ( V_143 -> V_146 , V_147 , sizeof( V_143 -> V_146 ) - 1 ) ;
V_143 -> V_146 [ sizeof( V_143 -> V_146 ) - 1 ] = '\0' ;
}
static int F_70 ( struct V_124 * V_125 , struct V_148 * V_149 )
{
V_149 -> V_150 = ( V_151
| V_152 | V_153 ) ;
V_149 -> V_154 = ( V_151
| V_152 | V_153 ) ;
V_149 -> V_44 = V_155 ;
V_149 -> V_156 = V_157 ;
V_149 -> V_158 = 0 ;
V_149 -> V_159 = V_160 ;
V_149 -> V_161 = V_162 ;
V_149 -> V_163 = V_164 ;
V_149 -> V_165 = 120 ;
V_149 -> V_166 = 120 ;
return 0 ;
}
static struct V_124 * F_71 ( int V_167 ,
struct V_168 * V_168 )
{
struct V_124 * V_125 ;
struct V_43 * V_44 ;
struct V_169 * V_170 = & V_168 -> V_125 ;
int V_66 , V_92 ;
const unsigned char * V_171 ;
V_171 = F_72 ( V_168 , L_17 , NULL ) ;
if ( V_171 == NULL )
V_171 = F_72 ( V_168 , L_18 , NULL ) ;
if ( V_171 == NULL ) {
F_21 ( L_19 ) ;
return NULL ;
}
V_125 = F_73 ( sizeof ( struct V_43 ) ) ;
if ( ! V_125 ) {
F_21 ( L_20 ) ;
return NULL ;
}
V_44 = F_64 ( V_125 ) ;
F_47 ( & V_44 -> V_172 ) ;
F_74 ( & V_44 -> V_130 ) ;
V_44 -> V_173 = 0 ;
for ( V_66 = 0 ; V_66 < V_174 ; V_66 ++ ) {
T_9 V_175 ;
if ( V_66 == V_114 )
continue;
V_175 = F_75 ( V_66 ) ;
if ( V_175 & ( 0x8000 >> V_167 ) )
V_44 -> V_176 |= ( 1 << V_66 ) ;
}
V_44 -> V_125 = V_170 ;
memcpy ( V_125 -> V_177 , V_171 , V_140 ) ;
V_125 -> V_129 = V_127 ;
memcpy ( & V_44 -> V_171 , V_171 , V_140 ) ;
V_125 -> V_178 = & V_179 ;
F_76 ( V_125 , & V_180 ) ;
F_77 ( V_125 , V_170 ) ;
V_92 = F_78 ( V_125 ) ;
if ( V_92 != 0 ) {
F_21 ( L_21 , V_167 ) ;
F_79 ( V_125 ) ;
return NULL ;
}
F_50 ( & V_44 -> V_32 , & V_181 ) ;
if ( 0 != F_80 ( & V_44 -> V_32 , & V_125 -> V_125 . V_33 , L_22 ) )
F_21 ( L_23 , V_125 -> V_182 ) ;
F_81 ( L_24 ,
V_125 -> V_182 , V_167 , V_44 -> V_176 ) ;
return V_125 ;
}
static int F_82 ( struct V_183 * V_184 , T_6 V_30 ,
struct V_124 * V_125 )
{
struct V_1 * V_2 = V_61 [ V_30 ] ;
struct V_43 * V_44 = F_64 ( V_125 ) ;
T_1 V_92 ;
struct V_3 * V_4 = NULL ;
unsigned long V_47 ;
if ( ! V_2 )
return 0 ;
F_19 ( & V_2 -> V_48 , V_47 ) ;
if ( ! ( V_2 -> V_49 & V_100 ) )
goto V_185;
if ( ( V_184 -> V_186 - V_187 ) > V_127 )
goto V_188;
V_4 = F_2 ( V_2 ) ;
if ( ! V_4 )
goto V_188;
V_4 -> V_189 = 1 ;
V_4 -> V_184 = F_83 ( V_184 ) ;
V_4 -> V_20 . V_138 [ 0 ] = F_84 ( V_44 -> V_125 , V_184 -> V_20 ,
V_184 -> V_186 , V_190 ) ;
if ( F_85 ( V_44 -> V_125 , V_4 -> V_20 . V_138 [ 0 ] ) )
goto V_191;
V_4 -> V_125 = V_44 -> V_125 ;
V_4 -> V_20 . V_186 [ 0 ] = V_184 -> V_186 ;
V_4 -> V_20 . V_192 = 1 << V_193 ;
V_92 = F_6 ( V_2 , V_78 , V_4 -> V_10 , & V_4 -> V_20 ) ;
if ( V_92 != V_89 )
goto V_191;
if ( 0 == V_2 -> V_75 )
F_86 ( & V_2 -> V_102 , V_77 + V_2 -> V_120 ) ;
V_2 -> V_76 = V_77 ;
V_2 -> V_75 ++ ;
if ( F_3 ( V_2 ) )
F_87 ( V_2 ) ;
V_185:
F_23 ( & V_2 -> V_48 , V_47 ) ;
return 0 ;
V_191:
F_30 ( V_2 , V_4 ) ;
V_188:
F_23 ( & V_2 -> V_48 , V_47 ) ;
return 1 ;
}
static void F_88 ( struct V_183 * V_184 ,
T_10 V_194 ,
struct V_124 * V_125 )
{
int V_66 , V_195 , error ;
V_195 = error = 0 ;
for ( V_66 = 0 ; V_66 < V_174 ; V_66 ++ ) {
if ( ( V_194 & ( 1 << V_66 ) ) == 0 )
continue;
if ( F_82 ( V_184 , V_66 , V_125 ) )
error = 1 ;
else
V_195 = 1 ;
}
if ( error )
V_125 -> V_196 . V_197 ++ ;
if ( V_195 ) {
V_125 -> V_196 . V_198 ++ ;
V_125 -> V_196 . V_199 += V_184 -> V_186 ;
}
}
static int F_89 ( struct V_183 * V_184 , struct V_124 * V_125 )
{
unsigned char * V_200 = V_184 -> V_20 ;
struct V_43 * V_44 = F_64 ( V_125 ) ;
T_10 V_194 ;
if ( F_90 ( V_200 ) ) {
T_6 V_30 = V_200 [ 5 ] ;
if ( ! ( ( 1 << V_30 ) & V_44 -> V_176 ) ) {
F_91 ( V_184 ) ;
return V_201 ;
}
V_194 = 1 << V_30 ;
} else {
V_194 = V_44 -> V_176 ;
}
F_88 ( V_184 , V_194 , V_125 ) ;
F_91 ( V_184 ) ;
return V_201 ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_11 V_202 , V_203 ;
if ( V_4 -> V_189 ) {
V_4 -> V_189 = 0 ;
V_202 = V_4 -> V_20 . V_138 [ 0 ] ;
V_203 = V_4 -> V_20 . V_186 [ 0 ] ;
if ( ! F_85 ( V_4 -> V_125 , V_202 ) )
F_92 ( V_4 -> V_125 , V_202 , V_203 ,
V_190 ) ;
if ( V_4 -> V_184 ) {
F_93 ( V_4 -> V_184 ) ;
V_4 -> V_184 = NULL ;
}
memset ( & V_4 -> V_20 , 0 , sizeof( V_4 -> V_20 ) ) ;
F_1 ( V_2 , V_4 ) ;
} else if ( V_2 -> V_49 & V_94 ) {
F_21 ( L_25 ,
V_2 -> V_16 , V_4 -> V_10 ) ;
}
}
static void F_31 ( struct V_1 * V_2 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_204 ; V_66 ++ ) {
struct V_124 * V_125 = V_205 [ V_66 ] ;
struct V_43 * V_44 ;
unsigned long V_47 ;
if ( ! V_125 )
continue;
V_44 = F_64 ( V_125 ) ;
if ( ! ( V_44 -> V_176 & ( 1 << V_2 -> V_16 ) ) )
continue;
F_19 ( & V_44 -> V_172 , V_47 ) ;
V_44 -> V_173 &= ~ ( 1 << V_2 -> V_16 ) ;
if ( 0 == V_44 -> V_173 && F_94 ( V_125 ) ) {
F_26 ( L_26 ,
V_2 -> V_16 , V_125 -> V_182 ) ;
F_95 ( V_125 ) ;
}
F_23 ( & V_44 -> V_172 , V_47 ) ;
}
}
static void F_87 ( struct V_1 * V_2 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_204 ; V_66 ++ ) {
struct V_124 * V_125 = V_205 [ V_66 ] ;
struct V_43 * V_44 ;
if ( ! V_125 )
continue;
V_44 = F_64 ( V_125 ) ;
if ( ! ( V_44 -> V_176 & ( 1 << V_2 -> V_16 ) ) )
continue;
F_96 ( & V_44 -> V_172 ) ;
F_61 ( V_125 ) ;
V_44 -> V_173 |= ( 1 << V_2 -> V_16 ) ;
F_26 ( L_27 ,
V_2 -> V_16 , V_125 -> V_182 , V_44 -> V_173 ) ;
F_97 ( & V_44 -> V_172 ) ;
}
}
static void V_119 ( unsigned long V_206 )
{
struct V_1 * V_2 = (struct V_1 * ) V_206 ;
unsigned long V_207 , V_47 ;
F_19 ( & V_2 -> V_48 , V_47 ) ;
if ( V_2 -> V_75 > 0 ) {
V_207 = V_2 -> V_76 + V_2 -> V_120 ;
if ( V_207 < V_77 ) {
V_2 -> V_49 |= V_59 ;
F_16 ( V_2 ) ;
F_21 ( L_28
L_29 ,
V_2 -> V_75 , V_2 -> V_16 ,
V_2 -> V_120 / V_84 ) ;
} else {
V_207 = V_77 + V_2 -> V_120 ;
F_86 ( & V_2 -> V_102 , V_207 ) ;
}
}
F_23 ( & V_2 -> V_48 , V_47 ) ;
}
static inline int F_98 ( struct V_43 * V_44 , T_5 V_171 )
{
int V_208 = 0 ;
int V_66 ;
unsigned long V_47 ;
if ( ( V_171 == V_44 -> V_171 ) || ( V_171 == 0xffffffffffff0000 ) )
return 1 ;
F_99 ( & V_44 -> V_130 , V_47 ) ;
if ( V_44 -> V_134 ) {
V_208 = 1 ;
goto V_103;
}
for ( V_66 = 0 ; V_66 < V_44 -> V_137 ; ++ V_66 ) {
if ( V_44 -> V_141 [ V_66 ] == V_171 ) {
V_208 = 1 ;
break;
}
}
V_103:
F_100 ( & V_44 -> V_130 , V_47 ) ;
return V_208 ;
}
static inline void F_101 ( struct V_209 * V_210 ,
unsigned char * V_21 , unsigned long V_211 )
{
unsigned long V_212 ;
int V_66 = 1 ;
V_210 [ 0 ] . V_138 = F_102 ( V_21 ) ;
V_210 [ 0 ] . V_213 = F_103 ( V_211 ,
V_214 - ( ( unsigned long ) V_21 & ~ V_215 ) ) ;
V_212 = V_210 [ 0 ] . V_213 ;
while ( V_212 < V_211 ) {
V_210 [ V_66 ] . V_138 = F_102 ( V_21 + V_212 ) ;
V_210 [ V_66 ] . V_213 = F_103 ( V_211 - V_212 , V_214 ) ;
V_212 += V_210 [ V_66 ] . V_213 ;
V_66 ++ ;
}
}
static void F_104 ( struct V_1 * V_2 )
{
T_1 V_92 ;
V_92 = F_6 ( V_2 , V_68 ,
0 , & V_2 -> V_95 ) ;
if ( V_92 != V_89 )
F_21 ( L_30 ,
V_2 -> V_16 , ( int ) V_92 ) ;
V_2 -> V_96 = 0 ;
memset ( & V_2 -> V_95 , 0xff , sizeof( V_2 -> V_95 ) ) ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_31 * V_46 )
{
struct V_216 * V_217 = & V_46 -> V_71 . V_218 ;
int V_219 = 0 ;
int V_220 ;
unsigned long V_47 ;
T_12 V_92 ;
do {
T_2 V_211 = 0 ;
struct V_183 * V_184 ;
struct V_209 V_221 [ V_222 ] ;
struct V_209 V_223 [ V_224 ] ;
T_5 V_225 ;
T_13 V_167 ;
struct V_124 * V_125 ;
struct V_43 * V_44 ;
memset ( V_221 , 0 , sizeof( V_221 ) ) ;
memset ( V_223 , 0 , sizeof( V_224 ) ) ;
if ( V_217 -> V_138 [ V_219 ] == 0 )
break;
if ( ! ( V_217 -> V_192 >> ( V_219 + V_193 ) ) ) {
F_21 ( L_31
L_32 ,
( unsigned ) V_217 -> V_192 ,
V_219 ) ;
break;
}
V_220 = 0 ;
do {
V_223 [ V_220 ] . V_138 =
( T_5 ) V_217 -> V_138 [ V_219 + V_220 ] << 32 ;
V_223 [ V_220 ] . V_213 =
V_217 -> V_186 [ V_219 + V_220 ] ;
V_211 += V_223 [ V_220 ] . V_213 ;
} while ( ! ( V_217 -> V_192 &
( 1 << ( V_193 + V_219 + V_220 ++ ) ) ) );
if ( ( V_211 - V_187 ) > V_127 ) {
F_21 ( L_33
L_34 ,
V_2 -> V_16 , V_211 ) ;
continue;
}
V_184 = F_105 ( V_211 , V_226 ) ;
if ( ! V_184 )
continue;
F_101 ( V_221 , V_184 -> V_20 , V_211 ) ;
V_92 = F_106 ( V_17 ,
V_46 -> V_51 . V_65 ,
V_227 ,
V_2 -> V_18 ,
V_2 -> V_19 ,
V_228 ,
V_229 ,
F_102 ( & V_221 ) ,
F_102 ( & V_223 ) ,
V_211 ) ;
if ( V_92 != V_230 ) {
F_107 ( V_184 ) ;
continue;
}
V_167 = V_184 -> V_20 [ 9 ] ;
V_125 = V_205 [ V_167 ] ;
if ( ! V_125 ) {
F_107 ( V_184 ) ;
continue;
}
V_44 = F_64 ( V_125 ) ;
V_225 = * ( ( T_5 * ) V_184 -> V_20 ) & 0xFFFFFFFFFFFF0000 ;
if ( ( V_167 > V_204 ) || ! V_44 ) {
F_107 ( V_184 ) ;
continue;
}
if ( ! F_98 ( V_44 , V_225 ) ) {
F_107 ( V_184 ) ;
continue;
}
F_108 ( V_184 , V_211 ) ;
V_184 -> V_231 = F_109 ( V_184 , V_125 ) ;
F_110 ( V_184 ) ;
F_111 ( V_184 ) ;
V_125 -> V_196 . V_232 ++ ;
V_125 -> V_196 . V_233 += V_211 ;
} while ( V_219 += V_220 , V_219 < V_224 );
F_19 ( & V_2 -> V_48 , V_47 ) ;
F_28 ( V_2 -> V_96 > V_69 ) ;
V_2 -> V_95 [ V_2 -> V_96 ++ ] =
V_46 -> V_51 . V_234 ;
if ( ( V_2 -> V_96 >= V_2 -> V_81 . V_86 ) ||
( V_2 -> V_96 >= V_69 ) )
F_104 ( V_2 ) ;
F_23 ( & V_2 -> V_48 , V_47 ) ;
}
static void V_118 ( unsigned long V_206 )
{
struct V_1 * V_2 = (struct V_1 * ) V_206 ;
unsigned long V_47 ;
F_19 ( & V_2 -> V_48 , V_47 ) ;
if ( V_2 -> V_96 > 0 )
F_104 ( V_2 ) ;
V_2 -> V_101 . V_113 = V_77 + V_2 -> V_83 ;
F_43 ( & V_2 -> V_101 ) ;
F_23 ( & V_2 -> V_48 , V_47 ) ;
}
static int F_112 ( struct V_168 * V_170 )
{
struct V_1 * V_2 ;
struct V_124 * V_125 ;
struct V_43 * V_44 ;
int V_66 ;
V_125 = V_205 [ V_170 -> V_235 ] ;
if ( ! V_125 )
return 0 ;
V_44 = F_64 ( V_125 ) ;
for ( V_66 = 0 ; V_66 < V_174 ; V_66 ++ ) {
V_2 = V_61 [ V_66 ] ;
if ( V_2 && ( V_44 -> V_176 & ( 1 << V_66 ) ) ) {
F_113 ( & V_2 -> V_32 ) ;
}
}
V_205 [ V_170 -> V_235 ] = NULL ;
F_114 ( & V_44 -> V_32 ) ;
F_113 ( & V_44 -> V_32 ) ;
F_115 ( V_125 ) ;
F_79 ( V_125 ) ;
return 0 ;
}
static int F_116 ( struct V_168 * V_170 , const struct V_236 * V_237 )
{
int V_66 = V_170 -> V_235 ;
struct V_124 * V_125 ;
struct V_43 * V_44 ;
V_125 = F_71 ( V_66 , V_170 ) ;
if ( V_125 == NULL ) {
F_112 ( V_170 ) ;
return 1 ;
}
V_205 [ V_66 ] = V_125 ;
V_44 = F_64 ( V_125 ) ;
for ( V_66 = 0 ; V_66 < V_174 ; V_66 ++ ) {
struct V_1 * V_2 ;
if ( ! ( V_44 -> V_176 & ( 1 << V_66 ) ) )
continue;
V_2 = V_61 [ V_66 ] ;
if ( ! V_2 )
continue;
F_117 ( & V_2 -> V_32 ) ;
F_16 ( V_2 ) ;
}
return 0 ;
}
static void T_14 F_118 ( void )
{
int V_66 ;
struct V_1 * V_2 ;
F_119 ( V_17 ) ;
for ( V_66 = 0 ; V_66 < V_174 ; ++ V_66 ) {
V_2 = V_61 [ V_66 ] ;
if ( ! V_2 )
continue;
F_120 ( & V_2 -> V_45 ) ;
F_114 ( & V_2 -> V_32 ) ;
F_113 ( & V_2 -> V_32 ) ;
}
F_121 ( & V_238 ) ;
}
static int T_15 F_122 ( void )
{
int V_66 ;
int V_92 ;
if ( ! F_123 ( V_239 ) )
return - V_240 ;
V_114 = F_124 () ;
for ( V_66 = 0 ; V_66 < V_174 ; ++ V_66 ) {
V_92 = F_44 ( V_66 ) ;
if ( V_92 != 0 )
goto error;
}
F_125 ( V_17 ,
& F_33 ) ;
V_92 = F_126 ( & V_238 ) ;
if ( V_92 != 0 )
goto error;
for ( V_66 = 0 ; V_66 < V_174 ; ++ V_66 ) {
struct V_32 * V_33 ;
if ( ! V_61 [ V_66 ] )
continue;
V_33 = & V_61 [ V_66 ] -> V_32 ;
if ( 0 != F_127 ( & V_238 . V_144 , V_33 ,
L_35 , V_61 [ V_66 ] -> V_16 ) )
F_21 ( L_36 , V_66 ) ;
}
return 0 ;
error:
for ( V_66 = 0 ; V_66 < V_174 ; ++ V_66 ) {
F_54 ( V_61 [ V_66 ] ) ;
}
return V_92 ;
}
