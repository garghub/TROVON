static T_1 F_1 ( const struct V_1 * V_2 , const struct V_1 * V_3 )
{
T_1 V_4 = F_2 ( V_2 ) ^ F_2 ( V_3 ) ;
return F_3 ( V_4 , V_5 ) ;
}
static struct V_6 * F_4 ( struct V_7 * V_8 )
{
struct V_9 V_10 , V_11 = { 0 } ;
int V_12 ;
F_5 (i) {
unsigned int V_13 ;
const struct V_9 * V_14 =
F_6 ( V_8 -> V_14 , V_12 ) ;
do {
V_13 = F_7 ( & V_14 -> V_15 ) ;
V_10 . V_16 = V_14 -> V_16 ;
V_10 . V_17 = V_14 -> V_17 ;
V_10 . V_18 = V_14 -> V_18 ;
V_10 . V_19 = V_14 -> V_19 ;
} while ( F_8 ( & V_14 -> V_15 , V_13 ) );
V_11 . V_16 += V_10 . V_16 ;
V_11 . V_17 += V_10 . V_17 ;
V_11 . V_18 += V_10 . V_18 ;
V_11 . V_19 += V_10 . V_19 ;
}
V_8 -> V_20 . V_16 = V_11 . V_16 ;
V_8 -> V_20 . V_17 = V_11 . V_17 ;
V_8 -> V_20 . V_18 = V_11 . V_18 ;
V_8 -> V_20 . V_19 = V_11 . V_19 ;
return & V_8 -> V_20 ;
}
static struct V_21 *
F_9 ( struct V_22 * V_22 , const struct V_1 * V_23 , const struct V_1 * V_24 )
{
unsigned int V_4 = F_1 ( V_23 , V_24 ) ;
struct V_21 * V_25 ;
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
struct V_1 V_29 ;
F_11 (ip6n->tnls_r_l[hash]) {
if ( F_12 ( V_24 , & V_25 -> V_30 . V_31 ) &&
F_12 ( V_23 , & V_25 -> V_30 . V_32 ) &&
( V_25 -> V_8 -> V_33 & V_34 ) )
return V_25 ;
}
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
V_4 = F_1 ( & V_29 , V_24 ) ;
F_11 (ip6n->tnls_r_l[hash]) {
if ( F_12 ( V_24 , & V_25 -> V_30 . V_31 ) &&
F_13 ( & V_25 -> V_30 . V_32 ) &&
( V_25 -> V_8 -> V_33 & V_34 ) )
return V_25 ;
}
V_4 = F_1 ( V_23 , & V_29 ) ;
F_11 (ip6n->tnls_r_l[hash]) {
if ( F_12 ( V_23 , & V_25 -> V_30 . V_32 ) &&
F_13 ( & V_25 -> V_30 . V_31 ) &&
( V_25 -> V_8 -> V_33 & V_34 ) )
return V_25 ;
}
V_25 = F_14 ( V_27 -> V_35 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_14 ( V_27 -> V_36 [ 0 ] ) ;
if ( V_25 && ( V_25 -> V_8 -> V_33 & V_34 ) )
return V_25 ;
return NULL ;
}
static struct V_21 T_2 * *
F_15 ( struct V_26 * V_27 , const struct V_37 * V_38 )
{
const struct V_1 * V_23 = & V_38 -> V_32 ;
const struct V_1 * V_24 = & V_38 -> V_31 ;
unsigned int V_39 = 0 ;
int V_40 = 0 ;
if ( ! F_13 ( V_23 ) || ! F_13 ( V_24 ) ) {
V_40 = 1 ;
V_39 = F_1 ( V_23 , V_24 ) ;
}
return & V_27 -> V_41 [ V_40 ] [ V_39 ] ;
}
static void
F_16 ( struct V_26 * V_27 , struct V_21 * V_25 )
{
struct V_21 T_2 * * V_42 = F_15 ( V_27 , & V_25 -> V_30 ) ;
if ( V_25 -> V_30 . V_43 )
F_17 ( V_27 -> V_35 , V_25 ) ;
F_17 ( V_25 -> V_44 , F_18 ( * V_42 ) ) ;
F_17 ( * V_42 , V_25 ) ;
}
static void
F_19 ( struct V_26 * V_27 , struct V_21 * V_25 )
{
struct V_21 T_2 * * V_42 ;
struct V_21 * V_45 ;
if ( V_25 -> V_30 . V_43 )
F_17 ( V_27 -> V_35 , NULL ) ;
for ( V_42 = F_15 ( V_27 , & V_25 -> V_30 ) ;
( V_45 = F_18 ( * V_42 ) ) != NULL ;
V_42 = & V_45 -> V_44 ) {
if ( V_25 == V_45 ) {
F_17 ( * V_42 , V_25 -> V_44 ) ;
break;
}
}
}
static void F_20 ( struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
F_22 ( & V_25 -> V_46 ) ;
F_23 ( & V_25 -> V_47 ) ;
F_24 ( V_8 -> V_14 ) ;
F_25 ( V_8 ) ;
}
static int F_26 ( struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
struct V_22 * V_22 = F_27 ( V_8 ) ;
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
int V_48 ;
V_25 = F_21 ( V_8 ) ;
V_8 -> V_49 = & V_50 ;
V_48 = F_28 ( V_8 ) ;
if ( V_48 < 0 )
goto V_51;
strcpy ( V_25 -> V_30 . V_52 , V_8 -> V_52 ) ;
F_29 ( V_8 ) ;
F_16 ( V_27 , V_25 ) ;
return 0 ;
V_51:
return V_48 ;
}
static struct V_21 * F_30 ( struct V_22 * V_22 , struct V_37 * V_38 )
{
struct V_7 * V_8 ;
struct V_21 * V_25 ;
char V_52 [ V_53 ] ;
int V_48 = - V_54 ;
if ( V_38 -> V_52 [ 0 ] )
F_31 ( V_52 , V_38 -> V_52 , V_53 ) ;
else
sprintf ( V_52 , L_1 ) ;
V_8 = F_32 ( sizeof( * V_25 ) , V_52 , V_55 ,
V_56 ) ;
if ( ! V_8 )
goto V_57;
F_33 ( V_8 , V_22 ) ;
V_25 = F_21 ( V_8 ) ;
V_25 -> V_30 = * V_38 ;
V_25 -> V_22 = F_27 ( V_8 ) ;
V_48 = F_26 ( V_8 ) ;
if ( V_48 < 0 )
goto V_58;
return V_25 ;
V_58:
F_20 ( V_8 ) ;
V_57:
return F_34 ( V_48 ) ;
}
static struct V_21 * F_35 ( struct V_22 * V_22 ,
struct V_37 * V_38 , int V_59 )
{
const struct V_1 * V_23 = & V_38 -> V_32 ;
const struct V_1 * V_24 = & V_38 -> V_31 ;
struct V_21 T_2 * * V_42 ;
struct V_21 * V_25 ;
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
for ( V_42 = F_15 ( V_27 , V_38 ) ;
( V_25 = F_18 ( * V_42 ) ) != NULL ;
V_42 = & V_25 -> V_44 ) {
if ( F_12 ( V_24 , & V_25 -> V_30 . V_31 ) &&
F_12 ( V_23 , & V_25 -> V_30 . V_32 ) ) {
if ( V_59 )
return F_34 ( - V_60 ) ;
return V_25 ;
}
}
if ( ! V_59 )
return F_34 ( - V_61 ) ;
return F_30 ( V_22 , V_38 ) ;
}
static void
F_36 ( struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
struct V_22 * V_22 = V_25 -> V_22 ;
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
if ( V_8 == V_27 -> V_62 )
F_37 ( V_27 -> V_36 [ 0 ] , NULL ) ;
else
F_19 ( V_27 , V_25 ) ;
F_38 ( & V_25 -> V_47 ) ;
F_39 ( V_8 ) ;
}
T_3 F_40 ( struct V_63 * V_64 , T_4 * V_65 )
{
const struct V_66 * V_67 = ( const struct V_66 * ) V_65 ;
unsigned int V_68 = V_65 - V_64 -> V_69 ;
unsigned int V_70 = V_68 + sizeof( * V_67 ) ;
T_5 V_44 , V_71 = V_67 -> V_71 ;
while ( F_41 ( V_71 ) && V_71 != V_72 ) {
struct V_73 * V_74 ;
T_6 V_75 ;
if ( ! F_42 ( V_64 , V_70 + sizeof( * V_74 ) ) )
break;
V_74 = (struct V_73 * ) ( V_64 -> V_69 + V_70 ) ;
if ( V_71 == V_76 ) {
struct V_77 * V_77 = (struct V_77 * ) V_74 ;
if ( V_77 -> V_78 )
break;
V_75 = 8 ;
} else if ( V_71 == V_79 ) {
V_75 = ( V_74 -> V_80 + 2 ) << 2 ;
} else {
V_75 = F_43 ( V_74 ) ;
}
V_44 = V_74 -> V_71 ;
if ( V_71 == V_81 ) {
T_6 V_12 = 2 ;
if ( ! F_42 ( V_64 , V_70 + V_75 ) )
break;
while ( 1 ) {
struct V_82 * V_83 ;
if ( V_12 + sizeof( * V_83 ) > V_75 )
break;
V_83 = (struct V_82 * ) ( V_64 -> V_69 + V_70 + V_12 ) ;
if ( V_83 -> type == V_84 &&
V_83 -> V_85 == 1 )
return V_12 + V_70 - V_68 ;
if ( V_83 -> type )
V_12 += V_83 -> V_85 + 2 ;
else
V_12 ++ ;
}
}
V_71 = V_44 ;
V_70 += V_75 ;
}
return 0 ;
}
static int
F_44 ( struct V_63 * V_64 , T_4 V_86 , struct V_87 * V_88 ,
T_5 * type , T_5 * V_89 , int * V_90 , T_7 * V_91 , int V_92 )
{
const struct V_66 * V_67 = ( const struct V_66 * ) V_64 -> V_69 ;
struct V_21 * V_25 ;
int V_93 = 0 ;
T_5 V_94 = V_95 ;
T_5 V_96 = V_97 ;
T_5 V_98 ;
T_7 V_99 = 0 ;
T_3 V_100 ;
int V_48 = - V_101 ;
F_45 () ;
V_25 = F_9 ( F_27 ( V_64 -> V_8 ) , & V_67 -> V_102 , & V_67 -> V_103 ) ;
if ( ! V_25 )
goto V_51;
V_98 = F_46 ( V_25 -> V_30 . V_104 ) ;
if ( V_98 != V_86 && V_98 != 0 )
goto V_51;
V_48 = 0 ;
switch ( * type ) {
T_7 V_105 ;
struct V_82 * V_83 ;
T_7 V_106 ;
case V_95 :
F_47 ( L_2 ,
V_25 -> V_30 . V_52 ) ;
V_93 = 1 ;
break;
case V_107 :
if ( ( * V_89 ) == V_108 ) {
F_47 ( L_3 ,
V_25 -> V_30 . V_52 ) ;
V_93 = 1 ;
}
break;
case V_109 :
V_105 = 0 ;
if ( ( * V_89 ) == V_110 )
V_105 = F_40 ( V_64 , V_64 -> V_69 ) ;
if ( V_105 && V_105 == * V_91 - 2 ) {
V_83 = (struct V_82 * ) & V_64 -> V_69 [ V_105 ] ;
if ( V_83 -> V_111 == 0 ) {
F_47 ( L_4 ,
V_25 -> V_30 . V_52 ) ;
V_93 = 1 ;
}
} else {
F_47 ( L_5 ,
V_25 -> V_30 . V_52 ) ;
}
break;
case V_112 :
V_106 = * V_91 - V_92 ;
if ( V_106 < V_113 )
V_106 = V_113 ;
V_25 -> V_8 -> V_106 = V_106 ;
V_100 = sizeof( * V_67 ) + F_48 ( V_67 -> V_114 ) ;
if ( V_100 > V_106 ) {
V_94 = V_112 ;
V_96 = 0 ;
V_99 = V_106 ;
V_93 = 1 ;
}
break;
}
* type = V_94 ;
* V_89 = V_96 ;
* V_91 = V_99 ;
* V_90 = V_93 ;
V_51:
F_49 () ;
return V_48 ;
}
static int
F_50 ( struct V_63 * V_64 , struct V_87 * V_88 ,
T_5 type , T_5 V_89 , int V_92 , T_8 V_91 )
{
int V_93 = 0 ;
T_5 V_94 = type ;
T_5 V_96 = V_89 ;
T_7 V_99 = F_51 ( V_91 ) ;
int V_48 ;
struct V_63 * V_115 ;
const struct V_116 * V_117 ;
struct V_118 * V_119 ;
struct V_120 V_121 ;
V_48 = F_44 ( V_64 , V_122 , V_88 , & V_94 , & V_96 ,
& V_93 , & V_99 , V_92 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_93 == 0 )
return 0 ;
switch ( V_94 ) {
case V_95 :
if ( V_96 != V_97 )
return 0 ;
V_94 = V_123 ;
V_96 = V_124 ;
break;
case V_112 :
if ( V_96 != 0 )
return 0 ;
V_94 = V_123 ;
V_96 = V_125 ;
break;
case V_126 :
V_94 = V_127 ;
V_96 = V_128 ;
default:
return 0 ;
}
if ( ! F_42 ( V_64 , V_92 + sizeof( struct V_116 ) ) )
return 0 ;
V_115 = F_52 ( V_64 , V_129 ) ;
if ( ! V_115 )
return 0 ;
F_53 ( V_115 ) ;
F_54 ( V_115 , V_92 ) ;
F_55 ( V_115 ) ;
V_117 = F_56 ( V_115 ) ;
V_119 = F_57 ( F_27 ( V_64 -> V_8 ) , & V_121 , NULL ,
V_117 -> V_103 , 0 ,
0 , 0 ,
V_122 , F_58 ( V_117 -> V_130 ) , 0 ) ;
if ( F_59 ( V_119 ) )
goto V_51;
V_115 -> V_8 = V_119 -> V_131 . V_8 ;
if ( V_119 -> V_132 & V_133 ) {
F_60 ( V_119 ) ;
V_119 = NULL ;
V_119 = F_57 ( F_27 ( V_64 -> V_8 ) , & V_121 , NULL ,
V_117 -> V_102 , V_117 -> V_103 ,
0 , 0 ,
V_122 ,
F_58 ( V_117 -> V_130 ) , 0 ) ;
if ( F_59 ( V_119 ) ||
V_119 -> V_131 . V_8 -> type != V_134 ) {
if ( ! F_59 ( V_119 ) )
F_60 ( V_119 ) ;
goto V_51;
}
F_61 ( V_115 , & V_119 -> V_131 ) ;
} else {
F_60 ( V_119 ) ;
if ( F_62 ( V_115 , V_117 -> V_102 , V_117 -> V_103 , V_117 -> V_130 ,
V_115 -> V_8 ) ||
F_63 ( V_115 ) -> V_8 -> type != V_134 )
goto V_51;
}
if ( V_94 == V_123 && V_96 == V_125 ) {
if ( V_99 > F_64 ( F_63 ( V_115 ) ) )
goto V_51;
F_63 ( V_115 ) -> V_135 -> V_136 ( F_63 ( V_115 ) , NULL , V_115 , V_99 ) ;
}
if ( V_94 == V_127 )
F_63 ( V_115 ) -> V_135 -> V_137 ( F_63 ( V_115 ) , NULL , V_115 ) ;
F_65 ( V_115 , V_94 , V_96 , F_66 ( V_99 ) ) ;
V_51:
F_67 ( V_115 ) ;
return 0 ;
}
static int
F_68 ( struct V_63 * V_64 , struct V_87 * V_88 ,
T_5 type , T_5 V_89 , int V_92 , T_8 V_91 )
{
int V_93 = 0 ;
T_5 V_94 = type ;
T_5 V_96 = V_89 ;
T_7 V_99 = F_51 ( V_91 ) ;
int V_48 ;
V_48 = F_44 ( V_64 , V_138 , V_88 , & V_94 , & V_96 ,
& V_93 , & V_99 , V_92 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_93 && F_42 ( V_64 , V_92 + sizeof( struct V_66 ) ) ) {
struct V_139 * V_119 ;
struct V_63 * V_115 = F_52 ( V_64 , V_129 ) ;
if ( ! V_115 )
return 0 ;
F_53 ( V_115 ) ;
F_54 ( V_115 , V_92 ) ;
F_55 ( V_115 ) ;
V_119 = F_69 ( F_27 ( V_64 -> V_8 ) , & F_70 ( V_115 ) -> V_103 ,
NULL , 0 , 0 ) ;
if ( V_119 && V_119 -> V_131 . V_8 )
V_115 -> V_8 = V_119 -> V_131 . V_8 ;
F_71 ( V_115 , V_94 , V_96 , V_99 ) ;
F_72 ( V_119 ) ;
F_67 ( V_115 ) ;
}
return 0 ;
}
static int F_73 ( const struct V_21 * V_25 ,
const struct V_66 * V_67 ,
struct V_63 * V_64 )
{
T_4 V_140 = F_74 ( V_67 ) & ~ V_141 ;
if ( V_25 -> V_30 . V_33 & V_142 )
F_75 ( F_56 ( V_64 ) , V_141 , V_140 ) ;
return F_76 ( V_67 , V_64 ) ;
}
static int F_77 ( const struct V_21 * V_25 ,
const struct V_66 * V_67 ,
struct V_63 * V_64 )
{
if ( V_25 -> V_30 . V_33 & V_142 )
F_78 ( F_74 ( V_67 ) , F_70 ( V_64 ) ) ;
return F_76 ( V_67 , V_64 ) ;
}
T_7 F_79 ( struct V_21 * V_25 ,
const struct V_1 * V_31 ,
const struct V_1 * V_32 )
{
struct V_37 * V_38 = & V_25 -> V_30 ;
int V_143 = F_80 ( V_31 ) ;
int V_144 = F_80 ( V_32 ) ;
T_7 V_33 = 0 ;
if ( V_143 == V_145 || V_144 == V_145 ) {
V_33 = V_146 ;
} else if ( V_143 & ( V_147 | V_148 ) &&
V_144 & ( V_147 | V_148 ) &&
! ( ( V_143 | V_144 ) & V_149 ) &&
( ! ( ( V_143 | V_144 ) & V_150 ) || V_38 -> V_151 ) ) {
if ( V_143 & V_147 )
V_33 |= V_152 ;
if ( V_144 & V_147 )
V_33 |= V_153 ;
}
return V_33 ;
}
int F_81 ( struct V_21 * V_25 ,
const struct V_1 * V_31 ,
const struct V_1 * V_32 )
{
struct V_37 * V_38 = & V_25 -> V_30 ;
int V_154 = 0 ;
struct V_22 * V_22 = V_25 -> V_22 ;
if ( ( V_38 -> V_33 & V_153 ) ||
( ( V_38 -> V_33 & V_146 ) &&
( F_79 ( V_25 , V_31 , V_32 ) & V_153 ) ) ) {
struct V_7 * V_155 = NULL ;
if ( V_38 -> V_151 )
V_155 = F_82 ( V_22 , V_38 -> V_151 ) ;
if ( ( F_83 ( V_31 ) ||
F_84 ( F_85 ( V_22 , V_31 , V_155 , 0 ) ) ) &&
F_84 ( ! F_85 ( V_22 , V_32 , NULL , 0 ) ) )
V_154 = 1 ;
}
return V_154 ;
}
static int F_86 ( struct V_21 * V_156 , struct V_63 * V_64 ,
const struct V_157 * V_158 ,
struct V_159 * V_160 ,
int (* F_87)( const struct V_21 * V_25 ,
const struct V_66 * V_67 ,
struct V_63 * V_64 ) ,
bool V_161 )
{
struct V_9 * V_14 ;
const struct V_66 * V_67 = F_70 ( V_64 ) ;
int V_48 ;
if ( ( ! ( V_158 -> V_33 & V_162 ) &&
( V_156 -> V_30 . V_163 & V_162 ) ) ||
( ( V_158 -> V_33 & V_162 ) &&
! ( V_156 -> V_30 . V_163 & V_162 ) ) ) {
V_156 -> V_8 -> V_20 . V_164 ++ ;
V_156 -> V_8 -> V_20 . V_165 ++ ;
goto V_166;
}
if ( V_156 -> V_30 . V_163 & V_167 ) {
if ( ! ( V_158 -> V_33 & V_167 ) ||
( V_156 -> V_168 &&
( V_169 ) ( F_51 ( V_158 -> V_170 ) - V_156 -> V_168 ) < 0 ) ) {
V_156 -> V_8 -> V_20 . V_171 ++ ;
V_156 -> V_8 -> V_20 . V_165 ++ ;
goto V_166;
}
V_156 -> V_168 = F_51 ( V_158 -> V_170 ) + 1 ;
}
V_64 -> V_172 = V_158 -> V_104 ;
if ( V_156 -> V_8 -> type == V_173 ) {
if ( ! F_42 ( V_64 , V_174 ) ) {
V_156 -> V_8 -> V_20 . V_175 ++ ;
V_156 -> V_8 -> V_20 . V_165 ++ ;
goto V_166;
}
V_67 = F_70 ( V_64 ) ;
V_64 -> V_172 = F_88 ( V_64 , V_156 -> V_8 ) ;
F_89 ( V_64 , F_90 ( V_64 ) , V_174 ) ;
} else {
V_64 -> V_8 = V_156 -> V_8 ;
}
F_55 ( V_64 ) ;
memset ( V_64 -> V_176 , 0 , sizeof( struct V_87 ) ) ;
F_91 ( V_64 , V_156 -> V_8 , V_156 -> V_22 ) ;
V_48 = F_87 ( V_156 , V_67 , V_64 ) ;
if ( F_92 ( V_48 ) ) {
if ( V_161 )
F_93 ( L_6 ,
& V_67 -> V_103 ,
F_74 ( V_67 ) ) ;
if ( V_48 > 1 ) {
++ V_156 -> V_8 -> V_20 . V_177 ;
++ V_156 -> V_8 -> V_20 . V_165 ;
goto V_166;
}
}
V_14 = F_94 ( V_156 -> V_8 -> V_14 ) ;
F_95 ( & V_14 -> V_15 ) ;
V_14 -> V_16 ++ ;
V_14 -> V_17 += V_64 -> V_100 ;
F_96 ( & V_14 -> V_15 ) ;
F_97 ( V_64 , ! F_98 ( V_156 -> V_22 , F_27 ( V_156 -> V_8 ) ) ) ;
if ( V_160 )
F_61 ( V_64 , (struct V_178 * ) V_160 ) ;
F_99 ( & V_156 -> V_46 , V_64 ) ;
return 0 ;
V_166:
F_67 ( V_64 ) ;
return 0 ;
}
int F_100 ( struct V_21 * V_25 , struct V_63 * V_64 ,
const struct V_157 * V_158 ,
struct V_159 * V_160 ,
bool V_161 )
{
return F_86 ( V_25 , V_64 , V_158 , NULL , F_77 ,
V_161 ) ;
}
static int F_101 ( struct V_63 * V_64 , T_5 V_86 ,
const struct V_157 * V_158 ,
int (* F_87)( const struct V_21 * V_25 ,
const struct V_66 * V_67 ,
struct V_63 * V_64 ) )
{
struct V_21 * V_25 ;
const struct V_66 * V_67 = F_70 ( V_64 ) ;
struct V_159 * V_160 = NULL ;
int V_154 = - 1 ;
F_45 () ;
V_25 = F_9 ( F_27 ( V_64 -> V_8 ) , & V_67 -> V_103 , & V_67 -> V_102 ) ;
if ( V_25 ) {
T_5 V_98 = F_46 ( V_25 -> V_30 . V_104 ) ;
if ( V_98 != V_86 && V_98 != 0 )
goto V_166;
if ( ! F_102 ( NULL , V_179 , V_64 ) )
goto V_166;
if ( ! F_81 ( V_25 , & V_67 -> V_102 , & V_67 -> V_103 ) )
goto V_166;
if ( F_103 ( V_64 , 0 , V_158 -> V_104 , false ) )
goto V_166;
if ( V_25 -> V_30 . V_43 ) {
V_160 = F_104 ( V_64 , 0 , 0 , 0 ) ;
if ( ! V_160 )
return 0 ;
}
V_154 = F_86 ( V_25 , V_64 , V_158 , V_160 , F_87 ,
V_180 ) ;
}
F_49 () ;
return V_154 ;
V_166:
F_49 () ;
F_67 ( V_64 ) ;
return 0 ;
}
static int F_105 ( struct V_63 * V_64 )
{
return F_101 ( V_64 , V_122 , & V_181 ,
F_73 ) ;
}
static int F_106 ( struct V_63 * V_64 )
{
return F_101 ( V_64 , V_138 , & V_182 ,
F_77 ) ;
}
static void F_107 ( struct V_183 * V_88 , T_4 V_111 )
{
memset ( V_88 , 0 , sizeof( struct V_183 ) ) ;
V_88 -> V_184 [ 2 ] = V_84 ;
V_88 -> V_184 [ 3 ] = 1 ;
V_88 -> V_184 [ 4 ] = V_111 ;
V_88 -> V_184 [ 5 ] = V_185 ;
V_88 -> V_184 [ 6 ] = 1 ;
V_88 -> V_135 . V_186 = (struct V_73 * ) V_88 -> V_184 ;
V_88 -> V_135 . V_187 = 8 ;
}
static inline bool
F_108 ( const struct V_21 * V_25 , const struct V_66 * V_74 )
{
return F_12 ( & V_25 -> V_30 . V_32 , & V_74 -> V_103 ) ;
}
int F_109 ( struct V_21 * V_25 ,
const struct V_1 * V_31 ,
const struct V_1 * V_32 )
{
struct V_37 * V_38 = & V_25 -> V_30 ;
int V_154 = 0 ;
struct V_22 * V_22 = V_25 -> V_22 ;
if ( ( V_38 -> V_33 & V_152 ) ||
( ( V_38 -> V_33 & V_146 ) &&
( F_79 ( V_25 , V_31 , V_32 ) & V_152 ) ) ) {
struct V_7 * V_155 = NULL ;
F_45 () ;
if ( V_38 -> V_151 )
V_155 = F_82 ( V_22 , V_38 -> V_151 ) ;
if ( F_92 ( ! F_85 ( V_22 , V_31 , V_155 , 0 ) ) )
F_110 ( L_7 ,
V_38 -> V_52 ) ;
else if ( ! F_83 ( V_32 ) &&
F_92 ( F_85 ( V_22 , V_32 , NULL , 0 ) ) )
F_110 ( L_8 ,
V_38 -> V_52 ) ;
else
V_154 = 1 ;
F_49 () ;
}
return V_154 ;
}
int F_111 ( struct V_63 * V_64 , struct V_7 * V_8 , T_4 V_140 ,
struct V_188 * V_189 , int V_111 , T_7 * V_190 ,
T_4 V_104 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
struct V_22 * V_22 = V_25 -> V_22 ;
struct V_6 * V_20 = & V_25 -> V_8 -> V_20 ;
struct V_66 * V_67 ;
struct V_183 V_88 ;
struct V_178 * V_131 = NULL , * V_191 = NULL ;
struct V_7 * V_192 ;
int V_106 ;
unsigned int V_193 = sizeof( struct V_66 ) + V_25 -> V_194 ;
unsigned int V_195 = V_193 ;
bool V_196 = false ;
T_5 V_197 ;
int V_48 = - 1 ;
if ( V_25 -> V_30 . V_43 ) {
V_197 = F_112 ( V_64 ) -> V_198 . V_199 ;
goto V_200;
} else {
V_197 = V_25 -> V_30 . V_197 ;
}
if ( F_13 ( & V_25 -> V_30 . V_32 ) ) {
if ( V_64 -> V_172 == F_113 ( V_201 ) ) {
struct V_1 * V_202 ;
struct V_203 * V_204 ;
int V_205 ;
if ( ! F_63 ( V_64 ) )
goto V_206;
V_204 = F_114 ( F_63 ( V_64 ) ,
& F_70 ( V_64 ) -> V_102 ) ;
if ( ! V_204 )
goto V_206;
V_202 = (struct V_1 * ) & V_204 -> V_207 ;
V_205 = F_80 ( V_202 ) ;
if ( V_205 == V_145 )
V_202 = & F_70 ( V_64 ) -> V_102 ;
memcpy ( & V_189 -> V_102 , V_202 , sizeof( V_189 -> V_102 ) ) ;
F_115 ( V_204 ) ;
}
} else if ( ! ( V_25 -> V_30 . V_33 &
( V_208 | V_209 ) ) ) {
V_196 = true ;
}
if ( V_196 )
V_131 = F_116 ( & V_25 -> V_47 ) ;
if ( ! F_109 ( V_25 , & V_189 -> V_103 , & V_189 -> V_102 ) )
goto V_206;
if ( ! V_131 ) {
V_200:
V_131 = F_117 ( V_22 , NULL , V_189 ) ;
if ( V_131 -> error )
goto V_206;
V_131 = F_118 ( V_22 , V_131 , F_119 ( V_189 ) , NULL , 0 ) ;
if ( F_59 ( V_131 ) ) {
V_48 = F_120 ( V_131 ) ;
V_131 = NULL ;
goto V_206;
}
if ( V_25 -> V_30 . V_43 &&
F_121 ( V_22 , F_122 ( V_131 ) -> V_8 ,
& V_189 -> V_102 , 0 , & V_189 -> V_103 ) )
goto V_206;
V_191 = V_131 ;
}
V_192 = V_131 -> V_8 ;
if ( V_192 == V_8 ) {
V_20 -> V_210 ++ ;
F_123 ( L_9 ,
V_25 -> V_30 . V_52 ) ;
goto V_211;
}
V_106 = F_64 ( V_131 ) - V_193 - V_25 -> V_212 ;
if ( V_111 >= 0 ) {
V_195 += 8 ;
V_106 -= 8 ;
}
if ( V_106 < V_113 )
V_106 = V_113 ;
if ( F_63 ( V_64 ) && ! V_25 -> V_30 . V_43 )
F_63 ( V_64 ) -> V_135 -> V_136 ( F_63 ( V_64 ) , NULL , V_64 , V_106 ) ;
if ( V_64 -> V_100 - V_25 -> V_212 > V_106 && ! F_124 ( V_64 ) ) {
* V_190 = V_106 ;
V_48 = - V_213 ;
goto V_211;
}
if ( V_25 -> V_214 > 0 ) {
if ( F_125 ( V_215 ,
V_25 -> V_216 + V_217 ) ) {
V_25 -> V_214 -- ;
F_126 ( V_64 ) ;
} else {
V_25 -> V_214 = 0 ;
}
}
F_97 ( V_64 , ! F_98 ( V_25 -> V_22 , F_27 ( V_8 ) ) ) ;
V_195 += F_127 ( V_192 ) ;
if ( F_128 ( V_64 ) < V_195 || F_129 ( V_64 ) ||
( F_130 ( V_64 ) && ! F_131 ( V_64 , 0 ) ) ) {
struct V_63 * V_218 ;
V_218 = F_132 ( V_64 , V_195 ) ;
if ( ! V_218 )
goto V_211;
if ( V_64 -> V_219 )
F_133 ( V_218 , V_64 -> V_219 ) ;
F_134 ( V_64 ) ;
V_64 = V_218 ;
}
if ( V_25 -> V_30 . V_43 ) {
if ( V_25 -> V_220 . type != V_221 )
goto V_211;
} else {
if ( V_196 && V_191 )
F_135 ( & V_25 -> V_47 , V_191 , & V_189 -> V_103 ) ;
}
F_61 ( V_64 , V_131 ) ;
if ( V_111 >= 0 ) {
F_107 ( & V_88 , V_111 ) ;
F_136 ( V_64 , & V_88 . V_135 , & V_104 , NULL , NULL ) ;
}
V_195 = F_127 ( V_131 -> V_8 ) + sizeof( struct V_66 )
+ V_131 -> V_222 + V_25 -> V_223 ;
if ( V_195 > V_8 -> V_224 )
V_8 -> V_224 = V_195 ;
V_48 = F_137 ( V_64 , V_25 , & V_104 , V_189 ) ;
if ( V_48 )
return V_48 ;
F_138 ( V_64 , sizeof( struct V_66 ) ) ;
F_55 ( V_64 ) ;
V_67 = F_70 ( V_64 ) ;
F_139 ( V_67 , F_140 ( 0 , V_140 ) ,
F_141 ( V_22 , V_64 , V_189 -> V_225 , true , V_189 ) ) ;
V_67 -> V_197 = V_197 ;
V_67 -> V_71 = V_104 ;
V_67 -> V_103 = V_189 -> V_103 ;
V_67 -> V_102 = V_189 -> V_102 ;
F_142 ( NULL , V_64 , V_8 ) ;
return 0 ;
V_206:
V_20 -> V_226 ++ ;
F_126 ( V_64 ) ;
V_211:
F_143 ( V_131 ) ;
return V_48 ;
}
static inline int
F_144 ( struct V_63 * V_64 , struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
const struct V_116 * V_227 = F_56 ( V_64 ) ;
int V_111 = - 1 ;
struct V_188 V_189 ;
T_4 V_140 ;
T_7 V_106 ;
T_5 V_98 ;
int V_48 ;
memset ( & ( F_145 ( V_64 ) -> V_88 ) , 0 , sizeof( F_145 ( V_64 ) -> V_88 ) ) ;
V_98 = F_46 ( V_25 -> V_30 . V_104 ) ;
if ( V_98 != V_122 && V_98 != 0 )
return - 1 ;
V_140 = F_146 ( V_227 ) ;
if ( V_25 -> V_30 . V_43 ) {
struct V_228 * V_229 ;
const struct V_230 * V_198 ;
V_229 = F_112 ( V_64 ) ;
if ( F_92 ( ! V_229 || ! ( V_229 -> V_231 & V_232 ) ||
F_147 ( V_229 ) != V_233 ) )
return - 1 ;
V_198 = & V_229 -> V_198 ;
memset ( & V_189 , 0 , sizeof( V_189 ) ) ;
V_189 . V_234 = V_122 ;
V_189 . V_102 = V_198 -> V_235 . V_236 . V_131 ;
V_189 . V_225 = V_198 -> V_237 ;
} else {
if ( ! ( V_25 -> V_30 . V_33 & V_238 ) )
V_111 = V_25 -> V_30 . V_111 ;
memcpy ( & V_189 , & V_25 -> V_239 . V_235 . V_240 , sizeof( V_189 ) ) ;
V_189 . V_234 = V_122 ;
if ( V_25 -> V_30 . V_33 & V_208 )
V_189 . V_225 |= F_66 ( ( T_7 ) V_227 -> V_130 << V_241 )
& V_242 ;
if ( V_25 -> V_30 . V_33 & V_209 )
V_189 . V_243 = V_64 -> V_244 ;
}
V_189 . V_245 = F_148 ( F_27 ( V_8 ) , NULL ) ;
if ( F_149 ( V_64 , V_246 ) )
return - 1 ;
F_150 ( V_64 , V_122 ) ;
V_48 = F_111 ( V_64 , V_8 , V_140 , & V_189 , V_111 , & V_106 ,
V_122 ) ;
if ( V_48 != 0 ) {
if ( V_48 == - V_213 )
F_65 ( V_64 , V_123 , V_125 ,
F_66 ( V_106 ) ) ;
return - 1 ;
}
return 0 ;
}
static inline int
F_151 ( struct V_63 * V_64 , struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
struct V_66 * V_67 = F_70 ( V_64 ) ;
int V_111 = - 1 ;
T_3 V_92 ;
struct V_188 V_189 ;
T_4 V_140 ;
T_7 V_106 ;
T_5 V_98 ;
int V_48 ;
V_98 = F_46 ( V_25 -> V_30 . V_104 ) ;
if ( ( V_98 != V_138 && V_98 != 0 ) ||
F_108 ( V_25 , V_67 ) )
return - 1 ;
V_140 = F_74 ( V_67 ) ;
if ( V_25 -> V_30 . V_43 ) {
struct V_228 * V_229 ;
const struct V_230 * V_198 ;
V_229 = F_112 ( V_64 ) ;
if ( F_92 ( ! V_229 || ! ( V_229 -> V_231 & V_232 ) ||
F_147 ( V_229 ) != V_233 ) )
return - 1 ;
V_198 = & V_229 -> V_198 ;
memset ( & V_189 , 0 , sizeof( V_189 ) ) ;
V_189 . V_234 = V_138 ;
V_189 . V_102 = V_198 -> V_235 . V_236 . V_131 ;
V_189 . V_225 = V_198 -> V_237 ;
} else {
V_92 = F_40 ( V_64 , F_152 ( V_64 ) ) ;
V_67 = F_70 ( V_64 ) ;
if ( V_92 > 0 ) {
struct V_82 * V_83 ;
V_83 = ( void * ) & F_152 ( V_64 ) [ V_92 ] ;
if ( V_83 -> V_111 == 0 ) {
F_71 ( V_64 , V_109 ,
V_110 , V_92 + 2 ) ;
return - 1 ;
}
V_111 = V_83 -> V_111 - 1 ;
} else if ( ! ( V_25 -> V_30 . V_33 & V_238 ) ) {
V_111 = V_25 -> V_30 . V_111 ;
}
memcpy ( & V_189 , & V_25 -> V_239 . V_235 . V_240 , sizeof( V_189 ) ) ;
V_189 . V_234 = V_138 ;
if ( V_25 -> V_30 . V_33 & V_208 )
V_189 . V_225 |= ( * ( T_8 * ) V_67 & V_242 ) ;
if ( V_25 -> V_30 . V_33 & V_247 )
V_189 . V_225 |= F_153 ( V_67 ) ;
if ( V_25 -> V_30 . V_33 & V_209 )
V_189 . V_243 = V_64 -> V_244 ;
}
V_189 . V_245 = F_148 ( F_27 ( V_8 ) , NULL ) ;
if ( F_149 ( V_64 , V_246 ) )
return - 1 ;
F_150 ( V_64 , V_138 ) ;
V_48 = F_111 ( V_64 , V_8 , V_140 , & V_189 , V_111 , & V_106 ,
V_138 ) ;
if ( V_48 != 0 ) {
if ( V_48 == - V_213 )
F_71 ( V_64 , V_112 , 0 , V_106 ) ;
return - 1 ;
}
return 0 ;
}
static T_9
F_154 ( struct V_63 * V_64 , struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
struct V_6 * V_20 = & V_25 -> V_8 -> V_20 ;
int V_154 ;
switch ( V_64 -> V_172 ) {
case F_113 ( V_248 ) :
V_154 = F_144 ( V_64 , V_8 ) ;
break;
case F_113 ( V_201 ) :
V_154 = F_151 ( V_64 , V_8 ) ;
break;
default:
goto V_249;
}
if ( V_154 < 0 )
goto V_249;
return V_250 ;
V_249:
V_20 -> V_251 ++ ;
V_20 -> V_252 ++ ;
F_67 ( V_64 ) ;
return V_250 ;
}
static void F_155 ( struct V_21 * V_25 )
{
struct V_7 * V_8 = V_25 -> V_8 ;
struct V_37 * V_38 = & V_25 -> V_30 ;
struct V_188 * V_189 = & V_25 -> V_239 . V_235 . V_240 ;
int V_253 ;
memcpy ( V_8 -> V_254 , & V_38 -> V_31 , sizeof( struct V_1 ) ) ;
memcpy ( V_8 -> V_255 , & V_38 -> V_32 , sizeof( struct V_1 ) ) ;
V_189 -> V_103 = V_38 -> V_31 ;
V_189 -> V_102 = V_38 -> V_32 ;
V_189 -> V_256 = V_38 -> V_151 ;
V_189 -> V_225 = 0 ;
if ( ! ( V_38 -> V_33 & V_208 ) )
V_189 -> V_225 |= V_242 & V_38 -> V_257 ;
if ( ! ( V_38 -> V_33 & V_247 ) )
V_189 -> V_225 |= V_258 & V_38 -> V_257 ;
V_38 -> V_33 &= ~ ( V_152 | V_153 | V_146 ) ;
V_38 -> V_33 |= F_79 ( V_25 , & V_38 -> V_31 , & V_38 -> V_32 ) ;
if ( V_38 -> V_33 & V_152 && V_38 -> V_33 & V_153 )
V_8 -> V_33 |= V_259 ;
else
V_8 -> V_33 &= ~ V_259 ;
V_25 -> V_212 = 0 ;
V_25 -> V_223 = V_25 -> V_194 + V_25 -> V_212 ;
V_253 = V_25 -> V_223 + sizeof( struct V_66 ) ;
if ( V_38 -> V_33 & V_152 ) {
int V_260 = ( F_80 ( & V_38 -> V_32 ) &
( V_148 | V_150 ) ) ;
struct V_139 * V_119 = F_69 ( V_25 -> V_22 ,
& V_38 -> V_32 , & V_38 -> V_31 ,
V_38 -> V_151 , V_260 ) ;
if ( ! V_119 )
return;
if ( V_119 -> V_131 . V_8 ) {
V_8 -> V_261 = V_119 -> V_131 . V_8 -> V_261 +
V_253 ;
V_8 -> V_106 = V_119 -> V_131 . V_8 -> V_106 - V_253 ;
if ( ! ( V_25 -> V_30 . V_33 & V_238 ) )
V_8 -> V_106 -= 8 ;
if ( V_8 -> V_106 < V_113 )
V_8 -> V_106 = V_113 ;
}
F_72 ( V_119 ) ;
}
}
static int
F_156 ( struct V_21 * V_25 , const struct V_37 * V_38 )
{
V_25 -> V_30 . V_31 = V_38 -> V_31 ;
V_25 -> V_30 . V_32 = V_38 -> V_32 ;
V_25 -> V_30 . V_33 = V_38 -> V_33 ;
V_25 -> V_30 . V_197 = V_38 -> V_197 ;
V_25 -> V_30 . V_111 = V_38 -> V_111 ;
V_25 -> V_30 . V_257 = V_38 -> V_257 ;
V_25 -> V_30 . V_151 = V_38 -> V_151 ;
V_25 -> V_30 . V_104 = V_38 -> V_104 ;
F_38 ( & V_25 -> V_47 ) ;
F_155 ( V_25 ) ;
return 0 ;
}
static int F_157 ( struct V_21 * V_25 , struct V_37 * V_38 )
{
struct V_22 * V_22 = V_25 -> V_22 ;
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
int V_48 ;
F_19 ( V_27 , V_25 ) ;
F_158 () ;
V_48 = F_156 ( V_25 , V_38 ) ;
F_16 ( V_27 , V_25 ) ;
F_159 ( V_25 -> V_8 ) ;
return V_48 ;
}
static int F_160 ( struct V_21 * V_25 , struct V_37 * V_38 )
{
V_25 -> V_30 . V_104 = V_38 -> V_104 ;
F_159 ( V_25 -> V_8 ) ;
return 0 ;
}
static void
F_161 ( struct V_37 * V_38 , const struct V_262 * V_235 )
{
V_38 -> V_31 = V_235 -> V_31 ;
V_38 -> V_32 = V_235 -> V_32 ;
V_38 -> V_33 = V_235 -> V_33 ;
V_38 -> V_197 = V_235 -> V_197 ;
V_38 -> V_111 = V_235 -> V_111 ;
V_38 -> V_257 = V_235 -> V_257 ;
V_38 -> V_151 = V_235 -> V_151 ;
V_38 -> V_104 = V_235 -> V_104 ;
memcpy ( V_38 -> V_52 , V_235 -> V_52 , sizeof( V_235 -> V_52 ) ) ;
}
static void
F_162 ( struct V_262 * V_235 , const struct V_37 * V_38 )
{
V_235 -> V_31 = V_38 -> V_31 ;
V_235 -> V_32 = V_38 -> V_32 ;
V_235 -> V_33 = V_38 -> V_33 ;
V_235 -> V_197 = V_38 -> V_197 ;
V_235 -> V_111 = V_38 -> V_111 ;
V_235 -> V_257 = V_38 -> V_257 ;
V_235 -> V_151 = V_38 -> V_151 ;
V_235 -> V_104 = V_38 -> V_104 ;
memcpy ( V_235 -> V_52 , V_38 -> V_52 , sizeof( V_235 -> V_52 ) ) ;
}
static int
F_163 ( struct V_7 * V_8 , struct V_263 * V_264 , int V_265 )
{
int V_48 = 0 ;
struct V_262 V_38 ;
struct V_37 V_266 ;
struct V_21 * V_25 = F_21 ( V_8 ) ;
struct V_22 * V_22 = V_25 -> V_22 ;
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
memset ( & V_266 , 0 , sizeof( V_266 ) ) ;
switch ( V_265 ) {
case V_267 :
if ( V_8 == V_27 -> V_62 ) {
if ( F_164 ( & V_38 , V_264 -> V_268 . V_269 , sizeof( V_38 ) ) ) {
V_48 = - V_270 ;
break;
}
F_161 ( & V_266 , & V_38 ) ;
V_25 = F_35 ( V_22 , & V_266 , 0 ) ;
if ( F_59 ( V_25 ) )
V_25 = F_21 ( V_8 ) ;
} else {
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
}
F_162 ( & V_38 , & V_25 -> V_30 ) ;
if ( F_165 ( V_264 -> V_268 . V_269 , & V_38 , sizeof( V_38 ) ) ) {
V_48 = - V_270 ;
}
break;
case V_271 :
case V_272 :
V_48 = - V_273 ;
if ( ! F_166 ( V_22 -> V_274 , V_275 ) )
break;
V_48 = - V_270 ;
if ( F_164 ( & V_38 , V_264 -> V_268 . V_269 , sizeof( V_38 ) ) )
break;
V_48 = - V_276 ;
if ( V_38 . V_104 != V_138 && V_38 . V_104 != V_122 &&
V_38 . V_104 != 0 )
break;
F_161 ( & V_266 , & V_38 ) ;
V_25 = F_35 ( V_22 , & V_266 , V_265 == V_271 ) ;
if ( V_265 == V_272 ) {
if ( ! F_59 ( V_25 ) ) {
if ( V_25 -> V_8 != V_8 ) {
V_48 = - V_60 ;
break;
}
} else
V_25 = F_21 ( V_8 ) ;
if ( V_8 == V_27 -> V_62 )
V_48 = F_160 ( V_25 , & V_266 ) ;
else
V_48 = F_157 ( V_25 , & V_266 ) ;
}
if ( ! F_59 ( V_25 ) ) {
V_48 = 0 ;
F_162 ( & V_38 , & V_25 -> V_30 ) ;
if ( F_165 ( V_264 -> V_268 . V_269 , & V_38 , sizeof( V_38 ) ) )
V_48 = - V_270 ;
} else {
V_48 = F_120 ( V_25 ) ;
}
break;
case V_277 :
V_48 = - V_273 ;
if ( ! F_166 ( V_22 -> V_274 , V_275 ) )
break;
if ( V_8 == V_27 -> V_62 ) {
V_48 = - V_270 ;
if ( F_164 ( & V_38 , V_264 -> V_268 . V_269 , sizeof( V_38 ) ) )
break;
V_48 = - V_101 ;
F_161 ( & V_266 , & V_38 ) ;
V_25 = F_35 ( V_22 , & V_266 , 0 ) ;
if ( F_59 ( V_25 ) )
break;
V_48 = - V_273 ;
if ( V_25 -> V_8 == V_27 -> V_62 )
break;
V_8 = V_25 -> V_8 ;
}
V_48 = 0 ;
F_167 ( V_8 ) ;
break;
default:
V_48 = - V_276 ;
}
return V_48 ;
}
int F_168 ( struct V_7 * V_8 , int V_278 )
{
struct V_21 * V_279 = F_21 ( V_8 ) ;
if ( V_279 -> V_30 . V_104 == V_122 ) {
if ( V_278 < V_280 )
return - V_276 ;
} else {
if ( V_278 < V_113 )
return - V_276 ;
}
if ( V_278 > 0xFFF8 - V_8 -> V_261 )
return - V_276 ;
V_8 -> V_106 = V_278 ;
return 0 ;
}
int F_169 ( const struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
return V_25 -> V_30 . V_151 ;
}
int F_170 ( const struct V_281 * V_135 ,
unsigned int V_282 )
{
if ( V_282 >= V_283 )
return - V_284 ;
return ! F_171 ( ( const struct V_281 * * )
& V_285 [ V_282 ] ,
NULL , V_135 ) ? 0 : - 1 ;
}
int F_172 ( const struct V_281 * V_135 ,
unsigned int V_282 )
{
int V_154 ;
if ( V_282 >= V_283 )
return - V_284 ;
V_154 = ( F_171 ( ( const struct V_281 * * )
& V_285 [ V_282 ] ,
V_135 , NULL ) == V_135 ) ? 0 : - 1 ;
F_158 () ;
return V_154 ;
}
int F_173 ( struct V_21 * V_25 ,
struct V_286 * V_287 )
{
int V_223 ;
memset ( & V_25 -> V_220 , 0 , sizeof( V_25 -> V_220 ) ) ;
V_223 = F_174 ( V_287 ) ;
if ( V_223 < 0 )
return V_223 ;
V_25 -> V_220 . type = V_287 -> type ;
V_25 -> V_220 . V_288 = V_287 -> V_288 ;
V_25 -> V_220 . V_289 = V_287 -> V_289 ;
V_25 -> V_220 . V_33 = V_287 -> V_33 ;
V_25 -> V_194 = V_223 ;
V_25 -> V_223 = V_25 -> V_194 + V_25 -> V_212 ;
return 0 ;
}
static void V_56 ( struct V_7 * V_8 )
{
V_8 -> V_290 = & V_291 ;
V_8 -> V_292 = F_20 ;
V_8 -> type = V_293 ;
V_8 -> V_33 |= V_294 ;
V_8 -> V_295 = sizeof( struct V_1 ) ;
V_8 -> V_296 |= V_297 ;
F_175 ( V_8 ) ;
V_8 -> V_296 |= V_298 ;
V_8 -> V_299 |= V_298 ;
V_8 -> V_300 = V_301 ;
F_176 ( V_8 -> V_302 ) ;
}
static inline int
F_177 ( struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
int V_154 ;
int V_253 ;
V_25 -> V_8 = V_8 ;
V_25 -> V_22 = F_27 ( V_8 ) ;
V_8 -> V_14 = F_178 ( struct V_9 ) ;
if ( ! V_8 -> V_14 )
return - V_54 ;
V_154 = F_179 ( & V_25 -> V_47 , V_303 ) ;
if ( V_154 )
goto V_304;
V_154 = F_180 ( & V_25 -> V_46 , V_8 ) ;
if ( V_154 )
goto V_305;
V_25 -> V_212 = 0 ;
V_25 -> V_223 = V_25 -> V_194 + V_25 -> V_212 ;
V_253 = V_25 -> V_223 + sizeof( struct V_66 ) ;
V_8 -> type = V_293 ;
V_8 -> V_261 = V_306 + V_253 ;
V_8 -> V_106 = V_307 - V_253 ;
if ( ! ( V_25 -> V_30 . V_33 & V_238 ) )
V_8 -> V_106 -= 8 ;
V_8 -> V_308 = V_280 ;
V_8 -> V_309 = 0xFFF8 - V_8 -> V_261 ;
return 0 ;
V_305:
F_23 ( & V_25 -> V_47 ) ;
V_304:
F_24 ( V_8 -> V_14 ) ;
V_8 -> V_14 = NULL ;
return V_154 ;
}
static int F_181 ( struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
int V_48 = F_177 ( V_8 ) ;
if ( V_48 )
return V_48 ;
F_155 ( V_25 ) ;
if ( V_25 -> V_30 . V_43 ) {
V_8 -> V_296 |= V_310 ;
F_175 ( V_8 ) ;
}
return 0 ;
}
static int T_10 F_182 ( struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
struct V_22 * V_22 = F_27 ( V_8 ) ;
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
V_25 -> V_30 . V_104 = V_138 ;
F_29 ( V_8 ) ;
F_17 ( V_27 -> V_36 [ 0 ] , V_25 ) ;
return 0 ;
}
static int F_183 ( struct V_311 * V_312 [] , struct V_311 * V_69 [] )
{
T_5 V_104 ;
if ( ! V_69 || ! V_69 [ V_313 ] )
return 0 ;
V_104 = F_184 ( V_69 [ V_313 ] ) ;
if ( V_104 != V_138 &&
V_104 != V_122 &&
V_104 != 0 )
return - V_276 ;
return 0 ;
}
static void F_185 ( struct V_311 * V_69 [] ,
struct V_37 * V_30 )
{
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
if ( ! V_69 )
return;
if ( V_69 [ V_314 ] )
V_30 -> V_151 = F_186 ( V_69 [ V_314 ] ) ;
if ( V_69 [ V_315 ] )
V_30 -> V_31 = F_187 ( V_69 [ V_315 ] ) ;
if ( V_69 [ V_316 ] )
V_30 -> V_32 = F_187 ( V_69 [ V_316 ] ) ;
if ( V_69 [ V_317 ] )
V_30 -> V_197 = F_184 ( V_69 [ V_317 ] ) ;
if ( V_69 [ V_318 ] )
V_30 -> V_111 = F_184 ( V_69 [ V_318 ] ) ;
if ( V_69 [ V_319 ] )
V_30 -> V_257 = F_188 ( V_69 [ V_319 ] ) ;
if ( V_69 [ V_320 ] )
V_30 -> V_33 = F_186 ( V_69 [ V_320 ] ) ;
if ( V_69 [ V_313 ] )
V_30 -> V_104 = F_184 ( V_69 [ V_313 ] ) ;
if ( V_69 [ V_321 ] )
V_30 -> V_43 = true ;
}
static bool F_189 ( struct V_311 * V_69 [] ,
struct V_286 * V_287 )
{
bool V_154 = false ;
memset ( V_287 , 0 , sizeof( * V_287 ) ) ;
if ( ! V_69 )
return V_154 ;
if ( V_69 [ V_322 ] ) {
V_154 = true ;
V_287 -> type = F_190 ( V_69 [ V_322 ] ) ;
}
if ( V_69 [ V_323 ] ) {
V_154 = true ;
V_287 -> V_33 = F_190 ( V_69 [ V_323 ] ) ;
}
if ( V_69 [ V_324 ] ) {
V_154 = true ;
V_287 -> V_288 = F_191 ( V_69 [ V_324 ] ) ;
}
if ( V_69 [ V_325 ] ) {
V_154 = true ;
V_287 -> V_289 = F_191 ( V_69 [ V_325 ] ) ;
}
return V_154 ;
}
static int F_192 ( struct V_22 * V_326 , struct V_7 * V_8 ,
struct V_311 * V_312 [] , struct V_311 * V_69 [] )
{
struct V_22 * V_22 = F_27 ( V_8 ) ;
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
struct V_21 * V_327 , * V_25 ;
struct V_286 V_287 ;
V_327 = F_21 ( V_8 ) ;
if ( F_189 ( V_69 , & V_287 ) ) {
int V_48 = F_173 ( V_327 , & V_287 ) ;
if ( V_48 < 0 )
return V_48 ;
}
F_185 ( V_69 , & V_327 -> V_30 ) ;
if ( V_327 -> V_30 . V_43 ) {
if ( F_18 ( V_27 -> V_35 ) )
return - V_60 ;
} else {
V_25 = F_35 ( V_22 , & V_327 -> V_30 , 0 ) ;
if ( ! F_59 ( V_25 ) )
return - V_60 ;
}
return F_26 ( V_8 ) ;
}
static int F_193 ( struct V_7 * V_8 , struct V_311 * V_312 [] ,
struct V_311 * V_69 [] )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
struct V_37 V_38 ;
struct V_22 * V_22 = V_25 -> V_22 ;
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
struct V_286 V_287 ;
if ( V_8 == V_27 -> V_62 )
return - V_276 ;
if ( F_189 ( V_69 , & V_287 ) ) {
int V_48 = F_173 ( V_25 , & V_287 ) ;
if ( V_48 < 0 )
return V_48 ;
}
F_185 ( V_69 , & V_38 ) ;
if ( V_38 . V_43 )
return - V_276 ;
V_25 = F_35 ( V_22 , & V_38 , 0 ) ;
if ( ! F_59 ( V_25 ) ) {
if ( V_25 -> V_8 != V_8 )
return - V_60 ;
} else
V_25 = F_21 ( V_8 ) ;
return F_157 ( V_25 , & V_38 ) ;
}
static void F_194 ( struct V_7 * V_8 , struct V_328 * V_329 )
{
struct V_22 * V_22 = F_27 ( V_8 ) ;
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
if ( V_8 != V_27 -> V_62 )
F_195 ( V_8 , V_329 ) ;
}
static T_11 F_196 ( const struct V_7 * V_8 )
{
return
F_197 ( 4 ) +
F_197 ( sizeof( struct V_1 ) ) +
F_197 ( sizeof( struct V_1 ) ) +
F_197 ( 1 ) +
F_197 ( 1 ) +
F_197 ( 4 ) +
F_197 ( 4 ) +
F_197 ( 1 ) +
F_197 ( 2 ) +
F_197 ( 2 ) +
F_197 ( 2 ) +
F_197 ( 2 ) +
F_197 ( 0 ) +
0 ;
}
static int F_198 ( struct V_63 * V_64 , const struct V_7 * V_8 )
{
struct V_21 * V_156 = F_21 ( V_8 ) ;
struct V_37 * V_330 = & V_156 -> V_30 ;
if ( F_199 ( V_64 , V_314 , V_330 -> V_151 ) ||
F_200 ( V_64 , V_315 , & V_330 -> V_31 ) ||
F_200 ( V_64 , V_316 , & V_330 -> V_32 ) ||
F_201 ( V_64 , V_317 , V_330 -> V_197 ) ||
F_201 ( V_64 , V_318 , V_330 -> V_111 ) ||
F_202 ( V_64 , V_319 , V_330 -> V_257 ) ||
F_199 ( V_64 , V_320 , V_330 -> V_33 ) ||
F_201 ( V_64 , V_313 , V_330 -> V_104 ) )
goto V_331;
if ( F_203 ( V_64 , V_322 , V_156 -> V_220 . type ) ||
F_204 ( V_64 , V_324 , V_156 -> V_220 . V_288 ) ||
F_204 ( V_64 , V_325 , V_156 -> V_220 . V_289 ) ||
F_203 ( V_64 , V_323 , V_156 -> V_220 . V_33 ) )
goto V_331;
if ( V_330 -> V_43 )
if ( F_205 ( V_64 , V_321 ) )
goto V_331;
return 0 ;
V_331:
return - V_213 ;
}
struct V_22 * F_206 ( const struct V_7 * V_8 )
{
struct V_21 * V_156 = F_21 ( V_8 ) ;
return V_156 -> V_22 ;
}
static void T_12 F_207 ( struct V_22 * V_22 )
{
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
struct V_7 * V_8 , * V_332 ;
int V_39 ;
struct V_21 * V_25 ;
F_208 ( V_333 ) ;
F_209 (net, dev, aux)
if ( V_8 -> V_49 == & V_50 )
F_195 ( V_8 , & V_333 ) ;
for ( V_39 = 0 ; V_39 < V_334 ; V_39 ++ ) {
V_25 = F_18 ( V_27 -> V_335 [ V_39 ] ) ;
while ( V_25 ) {
if ( ! F_98 ( F_27 ( V_25 -> V_8 ) , V_22 ) )
F_195 ( V_25 -> V_8 , & V_333 ) ;
V_25 = F_18 ( V_25 -> V_44 ) ;
}
}
F_210 ( & V_333 ) ;
}
static int T_10 F_211 ( struct V_22 * V_22 )
{
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
struct V_21 * V_25 = NULL ;
int V_48 ;
V_27 -> V_41 [ 0 ] = V_27 -> V_36 ;
V_27 -> V_41 [ 1 ] = V_27 -> V_335 ;
V_48 = - V_54 ;
V_27 -> V_62 = F_32 ( sizeof( struct V_21 ) , L_10 ,
V_55 , V_56 ) ;
if ( ! V_27 -> V_62 )
goto V_336;
F_33 ( V_27 -> V_62 , V_22 ) ;
V_27 -> V_62 -> V_49 = & V_50 ;
V_27 -> V_62 -> V_296 |= V_310 ;
V_48 = F_182 ( V_27 -> V_62 ) ;
if ( V_48 < 0 )
goto V_337;
V_48 = F_212 ( V_27 -> V_62 ) ;
if ( V_48 < 0 )
goto V_337;
V_25 = F_21 ( V_27 -> V_62 ) ;
strcpy ( V_25 -> V_30 . V_52 , V_27 -> V_62 -> V_52 ) ;
return 0 ;
V_337:
F_20 ( V_27 -> V_62 ) ;
V_336:
return V_48 ;
}
static void T_12 F_213 ( struct V_22 * V_22 )
{
F_214 () ;
F_207 ( V_22 ) ;
F_215 () ;
}
static int T_13 F_216 ( void )
{
int V_48 ;
V_48 = F_217 ( & V_338 ) ;
if ( V_48 < 0 )
goto V_339;
V_48 = F_218 ( & V_340 , V_341 ) ;
if ( V_48 < 0 ) {
F_219 ( L_11 , V_342 ) ;
goto V_343;
}
V_48 = F_218 ( & V_344 , V_233 ) ;
if ( V_48 < 0 ) {
F_219 ( L_12 , V_342 ) ;
goto V_345;
}
V_48 = F_220 ( & V_50 ) ;
if ( V_48 < 0 )
goto V_346;
return 0 ;
V_346:
F_221 ( & V_344 , V_233 ) ;
V_345:
F_221 ( & V_340 , V_341 ) ;
V_343:
F_222 ( & V_338 ) ;
V_339:
return V_48 ;
}
static void T_14 F_223 ( void )
{
F_224 ( & V_50 ) ;
if ( F_221 ( & V_340 , V_341 ) )
F_225 ( L_13 , V_342 ) ;
if ( F_221 ( & V_344 , V_233 ) )
F_225 ( L_14 , V_342 ) ;
F_222 ( & V_338 ) ;
}
