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
T_4 V_68 = V_67 -> V_68 ;
T_3 V_69 = sizeof( * V_67 ) ;
while ( F_41 ( V_68 ) && V_68 != V_70 ) {
T_3 V_71 = 0 ;
struct V_72 * V_73 ;
if ( V_65 + V_69 + sizeof( * V_73 ) > V_64 -> V_74 &&
! F_42 ( V_64 , V_65 - V_64 -> V_74 + V_69 + sizeof ( * V_73 ) ) )
break;
V_73 = (struct V_72 * ) ( V_65 + V_69 ) ;
if ( V_68 == V_75 ) {
struct V_76 * V_76 = (struct V_76 * ) V_73 ;
if ( V_76 -> V_77 )
break;
V_71 = 8 ;
} else if ( V_68 == V_78 ) {
V_71 = ( V_73 -> V_79 + 2 ) << 2 ;
} else {
V_71 = F_43 ( V_73 ) ;
}
if ( V_68 == V_80 ) {
T_3 V_12 = V_69 + 2 ;
while ( 1 ) {
struct V_81 * V_82 ;
if ( V_12 + sizeof ( * V_82 ) > V_69 + V_71 )
break;
V_82 = (struct V_81 * ) & V_65 [ V_12 ] ;
if ( V_82 -> type == V_83 &&
V_82 -> V_84 == 1 )
return V_12 ;
if ( V_82 -> type )
V_12 += V_82 -> V_84 + 2 ;
else
V_12 ++ ;
}
}
V_68 = V_73 -> V_68 ;
V_69 += V_71 ;
}
return 0 ;
}
static int
F_44 ( struct V_63 * V_64 , T_4 V_85 , struct V_86 * V_87 ,
T_5 * type , T_5 * V_88 , int * V_89 , T_6 * V_90 , int V_91 )
{
const struct V_66 * V_67 = ( const struct V_66 * ) V_64 -> V_74 ;
struct V_21 * V_25 ;
int V_92 = 0 ;
T_5 V_93 = V_94 ;
T_5 V_95 = V_96 ;
T_5 V_97 ;
T_6 V_98 = 0 ;
T_3 V_99 ;
int V_48 = - V_100 ;
F_45 () ;
V_25 = F_9 ( F_27 ( V_64 -> V_8 ) , & V_67 -> V_101 , & V_67 -> V_102 ) ;
if ( ! V_25 )
goto V_51;
V_97 = F_46 ( V_25 -> V_30 . V_103 ) ;
if ( V_97 != V_85 && V_97 != 0 )
goto V_51;
V_48 = 0 ;
switch ( * type ) {
T_6 V_104 ;
struct V_81 * V_82 ;
T_6 V_105 ;
case V_94 :
F_47 ( L_2 ,
V_25 -> V_30 . V_52 ) ;
V_92 = 1 ;
break;
case V_106 :
if ( ( * V_88 ) == V_107 ) {
F_47 ( L_3 ,
V_25 -> V_30 . V_52 ) ;
V_92 = 1 ;
}
break;
case V_108 :
V_104 = 0 ;
if ( ( * V_88 ) == V_109 )
V_104 = F_40 ( V_64 , V_64 -> V_74 ) ;
if ( V_104 && V_104 == * V_90 - 2 ) {
V_82 = (struct V_81 * ) & V_64 -> V_74 [ V_104 ] ;
if ( V_82 -> V_110 == 0 ) {
F_47 ( L_4 ,
V_25 -> V_30 . V_52 ) ;
V_92 = 1 ;
}
} else {
F_47 ( L_5 ,
V_25 -> V_30 . V_52 ) ;
}
break;
case V_111 :
V_105 = * V_90 - V_91 ;
if ( V_105 < V_112 )
V_105 = V_112 ;
V_25 -> V_8 -> V_105 = V_105 ;
V_99 = sizeof( * V_67 ) + F_48 ( V_67 -> V_113 ) ;
if ( V_99 > V_105 ) {
V_93 = V_111 ;
V_95 = 0 ;
V_98 = V_105 ;
V_92 = 1 ;
}
break;
}
* type = V_93 ;
* V_88 = V_95 ;
* V_90 = V_98 ;
* V_89 = V_92 ;
V_51:
F_49 () ;
return V_48 ;
}
static int
F_50 ( struct V_63 * V_64 , struct V_86 * V_87 ,
T_5 type , T_5 V_88 , int V_91 , T_7 V_90 )
{
int V_92 = 0 ;
T_5 V_93 = type ;
T_5 V_95 = V_88 ;
T_6 V_98 = F_51 ( V_90 ) ;
int V_48 ;
struct V_63 * V_114 ;
const struct V_115 * V_116 ;
struct V_117 * V_118 ;
struct V_119 V_120 ;
V_48 = F_44 ( V_64 , V_121 , V_87 , & V_93 , & V_95 ,
& V_92 , & V_98 , V_91 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_92 == 0 )
return 0 ;
switch ( V_93 ) {
case V_94 :
if ( V_95 != V_96 )
return 0 ;
V_93 = V_122 ;
V_95 = V_123 ;
break;
case V_111 :
if ( V_95 != 0 )
return 0 ;
V_93 = V_122 ;
V_95 = V_124 ;
break;
case V_125 :
V_93 = V_126 ;
V_95 = V_127 ;
default:
return 0 ;
}
if ( ! F_42 ( V_64 , V_91 + sizeof( struct V_115 ) ) )
return 0 ;
V_114 = F_52 ( V_64 , V_128 ) ;
if ( ! V_114 )
return 0 ;
F_53 ( V_114 ) ;
F_54 ( V_114 , V_91 ) ;
F_55 ( V_114 ) ;
V_116 = F_56 ( V_114 ) ;
V_118 = F_57 ( F_27 ( V_64 -> V_8 ) , & V_120 , NULL ,
V_116 -> V_102 , 0 ,
0 , 0 ,
V_121 , F_58 ( V_116 -> V_129 ) , 0 ) ;
if ( F_59 ( V_118 ) )
goto V_51;
V_114 -> V_8 = V_118 -> V_130 . V_8 ;
if ( V_118 -> V_131 & V_132 ) {
F_60 ( V_118 ) ;
V_118 = NULL ;
V_118 = F_57 ( F_27 ( V_64 -> V_8 ) , & V_120 , NULL ,
V_116 -> V_101 , V_116 -> V_102 ,
0 , 0 ,
V_121 ,
F_58 ( V_116 -> V_129 ) , 0 ) ;
if ( F_59 ( V_118 ) ||
V_118 -> V_130 . V_8 -> type != V_133 ) {
if ( ! F_59 ( V_118 ) )
F_60 ( V_118 ) ;
goto V_51;
}
F_61 ( V_114 , & V_118 -> V_130 ) ;
} else {
F_60 ( V_118 ) ;
if ( F_62 ( V_114 , V_116 -> V_101 , V_116 -> V_102 , V_116 -> V_129 ,
V_114 -> V_8 ) ||
F_63 ( V_114 ) -> V_8 -> type != V_133 )
goto V_51;
}
if ( V_93 == V_122 && V_95 == V_124 ) {
if ( V_98 > F_64 ( F_63 ( V_114 ) ) )
goto V_51;
F_63 ( V_114 ) -> V_134 -> V_135 ( F_63 ( V_114 ) , NULL , V_114 , V_98 ) ;
}
if ( V_93 == V_126 )
F_63 ( V_114 ) -> V_134 -> V_136 ( F_63 ( V_114 ) , NULL , V_114 ) ;
F_65 ( V_114 , V_93 , V_95 , F_66 ( V_98 ) ) ;
V_51:
F_67 ( V_114 ) ;
return 0 ;
}
static int
F_68 ( struct V_63 * V_64 , struct V_86 * V_87 ,
T_5 type , T_5 V_88 , int V_91 , T_7 V_90 )
{
int V_92 = 0 ;
T_5 V_93 = type ;
T_5 V_95 = V_88 ;
T_6 V_98 = F_51 ( V_90 ) ;
int V_48 ;
V_48 = F_44 ( V_64 , V_137 , V_87 , & V_93 , & V_95 ,
& V_92 , & V_98 , V_91 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_92 && F_42 ( V_64 , V_91 + sizeof( struct V_66 ) ) ) {
struct V_138 * V_118 ;
struct V_63 * V_114 = F_52 ( V_64 , V_128 ) ;
if ( ! V_114 )
return 0 ;
F_53 ( V_114 ) ;
F_54 ( V_114 , V_91 ) ;
F_55 ( V_114 ) ;
V_118 = F_69 ( F_27 ( V_64 -> V_8 ) , & F_70 ( V_114 ) -> V_102 ,
NULL , 0 , 0 ) ;
if ( V_118 && V_118 -> V_130 . V_8 )
V_114 -> V_8 = V_118 -> V_130 . V_8 ;
F_71 ( V_114 , V_93 , V_95 , V_98 ) ;
F_72 ( V_118 ) ;
F_67 ( V_114 ) ;
}
return 0 ;
}
static int F_73 ( const struct V_21 * V_25 ,
const struct V_66 * V_67 ,
struct V_63 * V_64 )
{
T_4 V_139 = F_74 ( V_67 ) & ~ V_140 ;
if ( V_25 -> V_30 . V_33 & V_141 )
F_75 ( F_56 ( V_64 ) , V_140 , V_139 ) ;
return F_76 ( V_67 , V_64 ) ;
}
static int F_77 ( const struct V_21 * V_25 ,
const struct V_66 * V_67 ,
struct V_63 * V_64 )
{
if ( V_25 -> V_30 . V_33 & V_141 )
F_78 ( F_74 ( V_67 ) , F_70 ( V_64 ) ) ;
return F_76 ( V_67 , V_64 ) ;
}
T_6 F_79 ( struct V_21 * V_25 ,
const struct V_1 * V_31 ,
const struct V_1 * V_32 )
{
struct V_37 * V_38 = & V_25 -> V_30 ;
int V_142 = F_80 ( V_31 ) ;
int V_143 = F_80 ( V_32 ) ;
T_6 V_33 = 0 ;
if ( V_142 == V_144 || V_143 == V_144 ) {
V_33 = V_145 ;
} else if ( V_142 & ( V_146 | V_147 ) &&
V_143 & ( V_146 | V_147 ) &&
! ( ( V_142 | V_143 ) & V_148 ) &&
( ! ( ( V_142 | V_143 ) & V_149 ) || V_38 -> V_150 ) ) {
if ( V_142 & V_146 )
V_33 |= V_151 ;
if ( V_143 & V_146 )
V_33 |= V_152 ;
}
return V_33 ;
}
int F_81 ( struct V_21 * V_25 ,
const struct V_1 * V_31 ,
const struct V_1 * V_32 )
{
struct V_37 * V_38 = & V_25 -> V_30 ;
int V_153 = 0 ;
struct V_22 * V_22 = V_25 -> V_22 ;
if ( ( V_38 -> V_33 & V_152 ) ||
( ( V_38 -> V_33 & V_145 ) &&
( F_79 ( V_25 , V_31 , V_32 ) & V_152 ) ) ) {
struct V_7 * V_154 = NULL ;
if ( V_38 -> V_150 )
V_154 = F_82 ( V_22 , V_38 -> V_150 ) ;
if ( ( F_83 ( V_31 ) ||
F_84 ( F_85 ( V_22 , V_31 , V_154 , 0 ) ) ) &&
F_84 ( ! F_85 ( V_22 , V_32 , NULL , 0 ) ) )
V_153 = 1 ;
}
return V_153 ;
}
static int F_86 ( struct V_21 * V_155 , struct V_63 * V_64 ,
const struct V_156 * V_157 ,
struct V_158 * V_159 ,
int (* F_87)( const struct V_21 * V_25 ,
const struct V_66 * V_67 ,
struct V_63 * V_64 ) ,
bool V_160 )
{
struct V_9 * V_14 ;
const struct V_66 * V_67 = F_70 ( V_64 ) ;
int V_48 ;
if ( ( ! ( V_157 -> V_33 & V_161 ) &&
( V_155 -> V_30 . V_162 & V_161 ) ) ||
( ( V_157 -> V_33 & V_161 ) &&
! ( V_155 -> V_30 . V_162 & V_161 ) ) ) {
V_155 -> V_8 -> V_20 . V_163 ++ ;
V_155 -> V_8 -> V_20 . V_164 ++ ;
goto V_165;
}
if ( V_155 -> V_30 . V_162 & V_166 ) {
if ( ! ( V_157 -> V_33 & V_166 ) ||
( V_155 -> V_167 &&
( V_168 ) ( F_51 ( V_157 -> V_169 ) - V_155 -> V_167 ) < 0 ) ) {
V_155 -> V_8 -> V_20 . V_170 ++ ;
V_155 -> V_8 -> V_20 . V_164 ++ ;
goto V_165;
}
V_155 -> V_167 = F_51 ( V_157 -> V_169 ) + 1 ;
}
V_64 -> V_171 = V_157 -> V_103 ;
if ( V_155 -> V_8 -> type == V_172 ) {
if ( ! F_42 ( V_64 , V_173 ) ) {
V_155 -> V_8 -> V_20 . V_174 ++ ;
V_155 -> V_8 -> V_20 . V_164 ++ ;
goto V_165;
}
V_67 = F_70 ( V_64 ) ;
V_64 -> V_171 = F_88 ( V_64 , V_155 -> V_8 ) ;
F_89 ( V_64 , F_90 ( V_64 ) , V_173 ) ;
} else {
V_64 -> V_8 = V_155 -> V_8 ;
}
F_55 ( V_64 ) ;
memset ( V_64 -> V_175 , 0 , sizeof( struct V_86 ) ) ;
F_91 ( V_64 , V_155 -> V_8 , V_155 -> V_22 ) ;
V_48 = F_87 ( V_155 , V_67 , V_64 ) ;
if ( F_92 ( V_48 ) ) {
if ( V_160 )
F_93 ( L_6 ,
& V_67 -> V_102 ,
F_74 ( V_67 ) ) ;
if ( V_48 > 1 ) {
++ V_155 -> V_8 -> V_20 . V_176 ;
++ V_155 -> V_8 -> V_20 . V_164 ;
goto V_165;
}
}
V_14 = F_94 ( V_155 -> V_8 -> V_14 ) ;
F_95 ( & V_14 -> V_15 ) ;
V_14 -> V_16 ++ ;
V_14 -> V_17 += V_64 -> V_99 ;
F_96 ( & V_14 -> V_15 ) ;
F_97 ( V_64 , ! F_98 ( V_155 -> V_22 , F_27 ( V_155 -> V_8 ) ) ) ;
if ( V_159 )
F_61 ( V_64 , (struct V_177 * ) V_159 ) ;
F_99 ( & V_155 -> V_46 , V_64 ) ;
return 0 ;
V_165:
F_67 ( V_64 ) ;
return 0 ;
}
int F_100 ( struct V_21 * V_25 , struct V_63 * V_64 ,
const struct V_156 * V_157 ,
struct V_158 * V_159 ,
bool V_160 )
{
return F_86 ( V_25 , V_64 , V_157 , NULL , F_77 ,
V_160 ) ;
}
static int F_101 ( struct V_63 * V_64 , T_5 V_85 ,
const struct V_156 * V_157 ,
int (* F_87)( const struct V_21 * V_25 ,
const struct V_66 * V_67 ,
struct V_63 * V_64 ) )
{
struct V_21 * V_25 ;
const struct V_66 * V_67 = F_70 ( V_64 ) ;
struct V_158 * V_159 = NULL ;
int V_153 = - 1 ;
F_45 () ;
V_25 = F_9 ( F_27 ( V_64 -> V_8 ) , & V_67 -> V_102 , & V_67 -> V_101 ) ;
if ( V_25 ) {
T_5 V_97 = F_46 ( V_25 -> V_30 . V_103 ) ;
if ( V_97 != V_85 && V_97 != 0 )
goto V_165;
if ( ! F_102 ( NULL , V_178 , V_64 ) )
goto V_165;
if ( ! F_81 ( V_25 , & V_67 -> V_101 , & V_67 -> V_102 ) )
goto V_165;
if ( F_103 ( V_64 , 0 , V_157 -> V_103 , false ) )
goto V_165;
if ( V_25 -> V_30 . V_43 ) {
V_159 = F_104 ( V_64 , 0 , 0 , 0 ) ;
if ( ! V_159 )
return 0 ;
}
V_153 = F_86 ( V_25 , V_64 , V_157 , V_159 , F_87 ,
V_179 ) ;
}
F_49 () ;
return V_153 ;
V_165:
F_49 () ;
F_67 ( V_64 ) ;
return 0 ;
}
static int F_105 ( struct V_63 * V_64 )
{
return F_101 ( V_64 , V_121 , & V_180 ,
F_73 ) ;
}
static int F_106 ( struct V_63 * V_64 )
{
return F_101 ( V_64 , V_137 , & V_181 ,
F_77 ) ;
}
static void F_107 ( struct V_182 * V_87 , T_4 V_110 )
{
memset ( V_87 , 0 , sizeof( struct V_182 ) ) ;
V_87 -> V_183 [ 2 ] = V_83 ;
V_87 -> V_183 [ 3 ] = 1 ;
V_87 -> V_183 [ 4 ] = V_110 ;
V_87 -> V_183 [ 5 ] = V_184 ;
V_87 -> V_183 [ 6 ] = 1 ;
V_87 -> V_134 . V_185 = (struct V_72 * ) V_87 -> V_183 ;
V_87 -> V_134 . V_186 = 8 ;
}
static inline bool
F_108 ( const struct V_21 * V_25 , const struct V_66 * V_73 )
{
return F_12 ( & V_25 -> V_30 . V_32 , & V_73 -> V_102 ) ;
}
int F_109 ( struct V_21 * V_25 ,
const struct V_1 * V_31 ,
const struct V_1 * V_32 )
{
struct V_37 * V_38 = & V_25 -> V_30 ;
int V_153 = 0 ;
struct V_22 * V_22 = V_25 -> V_22 ;
if ( ( V_38 -> V_33 & V_151 ) ||
( ( V_38 -> V_33 & V_145 ) &&
( F_79 ( V_25 , V_31 , V_32 ) & V_151 ) ) ) {
struct V_7 * V_154 = NULL ;
F_45 () ;
if ( V_38 -> V_150 )
V_154 = F_82 ( V_22 , V_38 -> V_150 ) ;
if ( F_92 ( ! F_85 ( V_22 , V_31 , V_154 , 0 ) ) )
F_110 ( L_7 ,
V_38 -> V_52 ) ;
else if ( ! F_83 ( V_32 ) &&
F_92 ( F_85 ( V_22 , V_32 , NULL , 0 ) ) )
F_110 ( L_8 ,
V_38 -> V_52 ) ;
else
V_153 = 1 ;
F_49 () ;
}
return V_153 ;
}
int F_111 ( struct V_63 * V_64 , struct V_7 * V_8 , T_4 V_139 ,
struct V_187 * V_188 , int V_110 , T_6 * V_189 ,
T_4 V_103 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
struct V_22 * V_22 = V_25 -> V_22 ;
struct V_6 * V_20 = & V_25 -> V_8 -> V_20 ;
struct V_66 * V_67 = F_70 ( V_64 ) ;
struct V_182 V_87 ;
struct V_177 * V_130 = NULL , * V_190 = NULL ;
struct V_7 * V_191 ;
int V_105 ;
unsigned int V_192 = sizeof( struct V_66 ) + V_25 -> V_193 ;
unsigned int V_194 = V_192 ;
bool V_195 = false ;
T_5 V_196 ;
int V_48 = - 1 ;
if ( V_25 -> V_30 . V_43 ) {
V_196 = F_112 ( V_64 ) -> V_197 . V_198 ;
goto V_199;
} else {
V_196 = V_25 -> V_30 . V_196 ;
}
if ( F_13 ( & V_25 -> V_30 . V_32 ) ) {
struct V_1 * V_200 ;
struct V_201 * V_202 ;
int V_203 ;
if ( ! F_63 ( V_64 ) )
goto V_204;
V_202 = F_113 ( F_63 ( V_64 ) ,
& F_70 ( V_64 ) -> V_101 ) ;
if ( ! V_202 )
goto V_204;
V_200 = (struct V_1 * ) & V_202 -> V_205 ;
V_203 = F_80 ( V_200 ) ;
if ( V_203 == V_144 )
V_200 = & F_70 ( V_64 ) -> V_101 ;
memcpy ( & V_188 -> V_101 , V_200 , sizeof( V_188 -> V_101 ) ) ;
F_114 ( V_202 ) ;
} else if ( ! ( V_25 -> V_30 . V_33 &
( V_206 | V_207 ) ) ) {
V_195 = true ;
}
if ( V_195 )
V_130 = F_115 ( & V_25 -> V_47 ) ;
if ( ! F_109 ( V_25 , & V_188 -> V_102 , & V_188 -> V_101 ) )
goto V_204;
if ( ! V_130 ) {
V_199:
V_130 = F_116 ( V_22 , NULL , V_188 ) ;
if ( V_130 -> error )
goto V_204;
V_130 = F_117 ( V_22 , V_130 , F_118 ( V_188 ) , NULL , 0 ) ;
if ( F_59 ( V_130 ) ) {
V_48 = F_119 ( V_130 ) ;
V_130 = NULL ;
goto V_204;
}
if ( V_25 -> V_30 . V_43 &&
F_120 ( V_22 , F_121 ( V_130 ) -> V_8 ,
& V_188 -> V_101 , 0 , & V_188 -> V_102 ) )
goto V_204;
V_190 = V_130 ;
}
V_191 = V_130 -> V_8 ;
if ( V_191 == V_8 ) {
V_20 -> V_208 ++ ;
F_122 ( L_9 ,
V_25 -> V_30 . V_52 ) ;
goto V_209;
}
V_105 = F_64 ( V_130 ) - V_192 ;
if ( V_110 >= 0 ) {
V_194 += 8 ;
V_105 -= 8 ;
}
if ( V_105 < V_112 )
V_105 = V_112 ;
if ( F_63 ( V_64 ) && ! V_25 -> V_30 . V_43 )
F_63 ( V_64 ) -> V_134 -> V_135 ( F_63 ( V_64 ) , NULL , V_64 , V_105 ) ;
if ( V_64 -> V_99 > V_105 && ! F_123 ( V_64 ) ) {
* V_189 = V_105 ;
V_48 = - V_210 ;
goto V_209;
}
if ( V_25 -> V_211 > 0 ) {
if ( F_124 ( V_212 ,
V_25 -> V_213 + V_214 ) ) {
V_25 -> V_211 -- ;
F_125 ( V_64 ) ;
} else {
V_25 -> V_211 = 0 ;
}
}
F_97 ( V_64 , ! F_98 ( V_25 -> V_22 , F_27 ( V_8 ) ) ) ;
V_194 += F_126 ( V_191 ) ;
if ( F_127 ( V_64 ) < V_194 || F_128 ( V_64 ) ||
( F_129 ( V_64 ) && ! F_130 ( V_64 , 0 ) ) ) {
struct V_63 * V_215 ;
V_215 = F_131 ( V_64 , V_194 ) ;
if ( ! V_215 )
goto V_209;
if ( V_64 -> V_216 )
F_132 ( V_215 , V_64 -> V_216 ) ;
F_133 ( V_64 ) ;
V_64 = V_215 ;
}
if ( V_25 -> V_30 . V_43 ) {
if ( V_25 -> V_217 . type != V_218 )
goto V_209;
} else {
if ( V_195 && V_190 )
F_134 ( & V_25 -> V_47 , V_190 , & V_188 -> V_102 ) ;
}
F_61 ( V_64 , V_130 ) ;
if ( V_110 >= 0 ) {
F_107 ( & V_87 , V_110 ) ;
F_135 ( V_64 , & V_87 . V_134 , & V_103 , NULL ) ;
}
V_194 = F_126 ( V_130 -> V_8 ) + sizeof( struct V_66 )
+ V_130 -> V_219 + V_25 -> V_220 ;
if ( V_194 > V_8 -> V_221 )
V_8 -> V_221 = V_194 ;
V_48 = F_136 ( V_64 , V_25 , & V_103 , V_188 ) ;
if ( V_48 )
return V_48 ;
F_137 ( V_64 , sizeof( struct V_66 ) ) ;
F_55 ( V_64 ) ;
V_67 = F_70 ( V_64 ) ;
F_138 ( V_67 , F_139 ( 0 , V_139 ) ,
F_140 ( V_22 , V_64 , V_188 -> V_222 , true , V_188 ) ) ;
V_67 -> V_196 = V_196 ;
V_67 -> V_68 = V_103 ;
V_67 -> V_102 = V_188 -> V_102 ;
V_67 -> V_101 = V_188 -> V_101 ;
F_141 ( NULL , V_64 , V_8 ) ;
return 0 ;
V_204:
V_20 -> V_223 ++ ;
F_125 ( V_64 ) ;
V_209:
F_142 ( V_130 ) ;
return V_48 ;
}
static inline int
F_143 ( struct V_63 * V_64 , struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
const struct V_115 * V_224 = F_56 ( V_64 ) ;
int V_110 = - 1 ;
struct V_187 V_188 ;
T_4 V_139 ;
T_6 V_105 ;
T_5 V_97 ;
int V_48 ;
memset ( & ( F_144 ( V_64 ) -> V_87 ) , 0 , sizeof( F_144 ( V_64 ) -> V_87 ) ) ;
V_97 = F_46 ( V_25 -> V_30 . V_103 ) ;
if ( V_97 != V_121 && V_97 != 0 )
return - 1 ;
V_139 = F_145 ( V_224 ) ;
if ( V_25 -> V_30 . V_43 ) {
struct V_225 * V_226 ;
const struct V_227 * V_197 ;
V_226 = F_112 ( V_64 ) ;
if ( F_92 ( ! V_226 || ! ( V_226 -> V_228 & V_229 ) ||
F_146 ( V_226 ) != V_230 ) )
return - 1 ;
V_197 = & V_226 -> V_197 ;
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
V_188 . V_231 = V_121 ;
V_188 . V_101 = V_197 -> V_232 . V_233 . V_130 ;
V_188 . V_222 = V_197 -> V_234 ;
} else {
if ( ! ( V_25 -> V_30 . V_33 & V_235 ) )
V_110 = V_25 -> V_30 . V_110 ;
memcpy ( & V_188 , & V_25 -> V_236 . V_232 . V_237 , sizeof( V_188 ) ) ;
V_188 . V_231 = V_121 ;
if ( V_25 -> V_30 . V_33 & V_206 )
V_188 . V_222 |= F_66 ( ( T_6 ) V_224 -> V_129 << V_238 )
& V_239 ;
if ( V_25 -> V_30 . V_33 & V_207 )
V_188 . V_240 = V_64 -> V_241 ;
}
if ( F_147 ( V_64 , V_242 ) )
return - 1 ;
F_148 ( V_64 , V_121 ) ;
V_48 = F_111 ( V_64 , V_8 , V_139 , & V_188 , V_110 , & V_105 ,
V_121 ) ;
if ( V_48 != 0 ) {
if ( V_48 == - V_210 )
F_65 ( V_64 , V_122 , V_124 ,
F_66 ( V_105 ) ) ;
return - 1 ;
}
return 0 ;
}
static inline int
F_149 ( struct V_63 * V_64 , struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
struct V_66 * V_67 = F_70 ( V_64 ) ;
int V_110 = - 1 ;
T_3 V_91 ;
struct V_187 V_188 ;
T_4 V_139 ;
T_6 V_105 ;
T_5 V_97 ;
int V_48 ;
V_97 = F_46 ( V_25 -> V_30 . V_103 ) ;
if ( ( V_97 != V_137 && V_97 != 0 ) ||
F_108 ( V_25 , V_67 ) )
return - 1 ;
V_139 = F_74 ( V_67 ) ;
if ( V_25 -> V_30 . V_43 ) {
struct V_225 * V_226 ;
const struct V_227 * V_197 ;
V_226 = F_112 ( V_64 ) ;
if ( F_92 ( ! V_226 || ! ( V_226 -> V_228 & V_229 ) ||
F_146 ( V_226 ) != V_230 ) )
return - 1 ;
V_197 = & V_226 -> V_197 ;
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
V_188 . V_231 = V_137 ;
V_188 . V_101 = V_197 -> V_232 . V_233 . V_130 ;
V_188 . V_222 = V_197 -> V_234 ;
} else {
V_91 = F_40 ( V_64 , F_150 ( V_64 ) ) ;
if ( V_91 > 0 ) {
struct V_81 * V_82 ;
V_82 = ( void * ) & F_150 ( V_64 ) [ V_91 ] ;
if ( V_82 -> V_110 == 0 ) {
F_71 ( V_64 , V_108 ,
V_109 , V_91 + 2 ) ;
return - 1 ;
}
V_110 = V_82 -> V_110 - 1 ;
} else if ( ! ( V_25 -> V_30 . V_33 & V_235 ) ) {
V_110 = V_25 -> V_30 . V_110 ;
}
memcpy ( & V_188 , & V_25 -> V_236 . V_232 . V_237 , sizeof( V_188 ) ) ;
V_188 . V_231 = V_137 ;
if ( V_25 -> V_30 . V_33 & V_206 )
V_188 . V_222 |= ( * ( T_7 * ) V_67 & V_239 ) ;
if ( V_25 -> V_30 . V_33 & V_243 )
V_188 . V_222 |= F_151 ( V_67 ) ;
if ( V_25 -> V_30 . V_33 & V_207 )
V_188 . V_240 = V_64 -> V_241 ;
}
if ( F_147 ( V_64 , V_242 ) )
return - 1 ;
F_148 ( V_64 , V_137 ) ;
V_48 = F_111 ( V_64 , V_8 , V_139 , & V_188 , V_110 , & V_105 ,
V_137 ) ;
if ( V_48 != 0 ) {
if ( V_48 == - V_210 )
F_71 ( V_64 , V_111 , 0 , V_105 ) ;
return - 1 ;
}
return 0 ;
}
static T_8
F_152 ( struct V_63 * V_64 , struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
struct V_6 * V_20 = & V_25 -> V_8 -> V_20 ;
int V_153 ;
switch ( V_64 -> V_171 ) {
case F_153 ( V_244 ) :
V_153 = F_143 ( V_64 , V_8 ) ;
break;
case F_153 ( V_245 ) :
V_153 = F_149 ( V_64 , V_8 ) ;
break;
default:
goto V_246;
}
if ( V_153 < 0 )
goto V_246;
return V_247 ;
V_246:
V_20 -> V_248 ++ ;
V_20 -> V_249 ++ ;
F_67 ( V_64 ) ;
return V_247 ;
}
static void F_154 ( struct V_21 * V_25 )
{
struct V_7 * V_8 = V_25 -> V_8 ;
struct V_37 * V_38 = & V_25 -> V_30 ;
struct V_187 * V_188 = & V_25 -> V_236 . V_232 . V_237 ;
int V_250 ;
memcpy ( V_8 -> V_251 , & V_38 -> V_31 , sizeof( struct V_1 ) ) ;
memcpy ( V_8 -> V_252 , & V_38 -> V_32 , sizeof( struct V_1 ) ) ;
V_188 -> V_102 = V_38 -> V_31 ;
V_188 -> V_101 = V_38 -> V_32 ;
V_188 -> V_253 = V_38 -> V_150 ;
V_188 -> V_222 = 0 ;
if ( ! ( V_38 -> V_33 & V_206 ) )
V_188 -> V_222 |= V_239 & V_38 -> V_254 ;
if ( ! ( V_38 -> V_33 & V_243 ) )
V_188 -> V_222 |= V_255 & V_38 -> V_254 ;
V_38 -> V_33 &= ~ ( V_151 | V_152 | V_145 ) ;
V_38 -> V_33 |= F_79 ( V_25 , & V_38 -> V_31 , & V_38 -> V_32 ) ;
if ( V_38 -> V_33 & V_151 && V_38 -> V_33 & V_152 )
V_8 -> V_33 |= V_256 ;
else
V_8 -> V_33 &= ~ V_256 ;
V_25 -> V_257 = 0 ;
V_25 -> V_220 = V_25 -> V_193 + V_25 -> V_257 ;
V_250 = V_25 -> V_220 + sizeof( struct V_66 ) ;
if ( V_38 -> V_33 & V_151 ) {
int V_258 = ( F_80 ( & V_38 -> V_32 ) &
( V_147 | V_149 ) ) ;
struct V_138 * V_118 = F_69 ( V_25 -> V_22 ,
& V_38 -> V_32 , & V_38 -> V_31 ,
V_38 -> V_150 , V_258 ) ;
if ( ! V_118 )
return;
if ( V_118 -> V_130 . V_8 ) {
V_8 -> V_259 = V_118 -> V_130 . V_8 -> V_259 +
V_250 ;
V_8 -> V_105 = V_118 -> V_130 . V_8 -> V_105 - V_250 ;
if ( ! ( V_25 -> V_30 . V_33 & V_235 ) )
V_8 -> V_105 -= 8 ;
if ( V_8 -> V_105 < V_112 )
V_8 -> V_105 = V_112 ;
}
F_72 ( V_118 ) ;
}
}
static int
F_155 ( struct V_21 * V_25 , const struct V_37 * V_38 )
{
V_25 -> V_30 . V_31 = V_38 -> V_31 ;
V_25 -> V_30 . V_32 = V_38 -> V_32 ;
V_25 -> V_30 . V_33 = V_38 -> V_33 ;
V_25 -> V_30 . V_196 = V_38 -> V_196 ;
V_25 -> V_30 . V_110 = V_38 -> V_110 ;
V_25 -> V_30 . V_254 = V_38 -> V_254 ;
V_25 -> V_30 . V_150 = V_38 -> V_150 ;
V_25 -> V_30 . V_103 = V_38 -> V_103 ;
F_38 ( & V_25 -> V_47 ) ;
F_154 ( V_25 ) ;
return 0 ;
}
static int F_156 ( struct V_21 * V_25 , struct V_37 * V_38 )
{
struct V_22 * V_22 = V_25 -> V_22 ;
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
int V_48 ;
F_19 ( V_27 , V_25 ) ;
F_157 () ;
V_48 = F_155 ( V_25 , V_38 ) ;
F_16 ( V_27 , V_25 ) ;
F_158 ( V_25 -> V_8 ) ;
return V_48 ;
}
static int F_159 ( struct V_21 * V_25 , struct V_37 * V_38 )
{
V_25 -> V_30 . V_103 = V_38 -> V_103 ;
F_158 ( V_25 -> V_8 ) ;
return 0 ;
}
static void
F_160 ( struct V_37 * V_38 , const struct V_260 * V_232 )
{
V_38 -> V_31 = V_232 -> V_31 ;
V_38 -> V_32 = V_232 -> V_32 ;
V_38 -> V_33 = V_232 -> V_33 ;
V_38 -> V_196 = V_232 -> V_196 ;
V_38 -> V_110 = V_232 -> V_110 ;
V_38 -> V_254 = V_232 -> V_254 ;
V_38 -> V_150 = V_232 -> V_150 ;
V_38 -> V_103 = V_232 -> V_103 ;
memcpy ( V_38 -> V_52 , V_232 -> V_52 , sizeof( V_232 -> V_52 ) ) ;
}
static void
F_161 ( struct V_260 * V_232 , const struct V_37 * V_38 )
{
V_232 -> V_31 = V_38 -> V_31 ;
V_232 -> V_32 = V_38 -> V_32 ;
V_232 -> V_33 = V_38 -> V_33 ;
V_232 -> V_196 = V_38 -> V_196 ;
V_232 -> V_110 = V_38 -> V_110 ;
V_232 -> V_254 = V_38 -> V_254 ;
V_232 -> V_150 = V_38 -> V_150 ;
V_232 -> V_103 = V_38 -> V_103 ;
memcpy ( V_232 -> V_52 , V_38 -> V_52 , sizeof( V_232 -> V_52 ) ) ;
}
static int
F_162 ( struct V_7 * V_8 , struct V_261 * V_262 , int V_263 )
{
int V_48 = 0 ;
struct V_260 V_38 ;
struct V_37 V_264 ;
struct V_21 * V_25 = F_21 ( V_8 ) ;
struct V_22 * V_22 = V_25 -> V_22 ;
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
memset ( & V_264 , 0 , sizeof( V_264 ) ) ;
switch ( V_263 ) {
case V_265 :
if ( V_8 == V_27 -> V_62 ) {
if ( F_163 ( & V_38 , V_262 -> V_266 . V_267 , sizeof( V_38 ) ) ) {
V_48 = - V_268 ;
break;
}
F_160 ( & V_264 , & V_38 ) ;
V_25 = F_35 ( V_22 , & V_264 , 0 ) ;
if ( F_59 ( V_25 ) )
V_25 = F_21 ( V_8 ) ;
} else {
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
}
F_161 ( & V_38 , & V_25 -> V_30 ) ;
if ( F_164 ( V_262 -> V_266 . V_267 , & V_38 , sizeof( V_38 ) ) ) {
V_48 = - V_268 ;
}
break;
case V_269 :
case V_270 :
V_48 = - V_271 ;
if ( ! F_165 ( V_22 -> V_272 , V_273 ) )
break;
V_48 = - V_268 ;
if ( F_163 ( & V_38 , V_262 -> V_266 . V_267 , sizeof( V_38 ) ) )
break;
V_48 = - V_274 ;
if ( V_38 . V_103 != V_137 && V_38 . V_103 != V_121 &&
V_38 . V_103 != 0 )
break;
F_160 ( & V_264 , & V_38 ) ;
V_25 = F_35 ( V_22 , & V_264 , V_263 == V_269 ) ;
if ( V_263 == V_270 ) {
if ( ! F_59 ( V_25 ) ) {
if ( V_25 -> V_8 != V_8 ) {
V_48 = - V_60 ;
break;
}
} else
V_25 = F_21 ( V_8 ) ;
if ( V_8 == V_27 -> V_62 )
V_48 = F_159 ( V_25 , & V_264 ) ;
else
V_48 = F_156 ( V_25 , & V_264 ) ;
}
if ( ! F_59 ( V_25 ) ) {
V_48 = 0 ;
F_161 ( & V_38 , & V_25 -> V_30 ) ;
if ( F_164 ( V_262 -> V_266 . V_267 , & V_38 , sizeof( V_38 ) ) )
V_48 = - V_268 ;
} else {
V_48 = F_119 ( V_25 ) ;
}
break;
case V_275 :
V_48 = - V_271 ;
if ( ! F_165 ( V_22 -> V_272 , V_273 ) )
break;
if ( V_8 == V_27 -> V_62 ) {
V_48 = - V_268 ;
if ( F_163 ( & V_38 , V_262 -> V_266 . V_267 , sizeof( V_38 ) ) )
break;
V_48 = - V_100 ;
F_160 ( & V_264 , & V_38 ) ;
V_25 = F_35 ( V_22 , & V_264 , 0 ) ;
if ( F_59 ( V_25 ) )
break;
V_48 = - V_271 ;
if ( V_25 -> V_8 == V_27 -> V_62 )
break;
V_8 = V_25 -> V_8 ;
}
V_48 = 0 ;
F_166 ( V_8 ) ;
break;
default:
V_48 = - V_274 ;
}
return V_48 ;
}
int F_167 ( struct V_7 * V_8 , int V_276 )
{
struct V_21 * V_277 = F_21 ( V_8 ) ;
if ( V_277 -> V_30 . V_103 == V_121 ) {
if ( V_276 < 68 )
return - V_274 ;
} else {
if ( V_276 < V_112 )
return - V_274 ;
}
if ( V_276 > 0xFFF8 - V_8 -> V_259 )
return - V_274 ;
V_8 -> V_105 = V_276 ;
return 0 ;
}
int F_168 ( const struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
return V_25 -> V_30 . V_150 ;
}
int F_169 ( const struct V_278 * V_134 ,
unsigned int V_279 )
{
if ( V_279 >= V_280 )
return - V_281 ;
return ! F_170 ( ( const struct V_278 * * )
& V_282 [ V_279 ] ,
NULL , V_134 ) ? 0 : - 1 ;
}
int F_171 ( const struct V_278 * V_134 ,
unsigned int V_279 )
{
int V_153 ;
if ( V_279 >= V_280 )
return - V_281 ;
V_153 = ( F_170 ( ( const struct V_278 * * )
& V_282 [ V_279 ] ,
V_134 , NULL ) == V_134 ) ? 0 : - 1 ;
F_157 () ;
return V_153 ;
}
int F_172 ( struct V_21 * V_25 ,
struct V_283 * V_284 )
{
int V_220 ;
memset ( & V_25 -> V_217 , 0 , sizeof( V_25 -> V_217 ) ) ;
V_220 = F_173 ( V_284 ) ;
if ( V_220 < 0 )
return V_220 ;
V_25 -> V_217 . type = V_284 -> type ;
V_25 -> V_217 . V_285 = V_284 -> V_285 ;
V_25 -> V_217 . V_286 = V_284 -> V_286 ;
V_25 -> V_217 . V_33 = V_284 -> V_33 ;
V_25 -> V_193 = V_220 ;
V_25 -> V_220 = V_25 -> V_193 + V_25 -> V_257 ;
return 0 ;
}
static void V_56 ( struct V_7 * V_8 )
{
V_8 -> V_287 = & V_288 ;
V_8 -> V_289 = F_20 ;
V_8 -> type = V_290 ;
V_8 -> V_33 |= V_291 ;
V_8 -> V_292 = sizeof( struct V_1 ) ;
V_8 -> V_293 |= V_294 ;
F_174 ( V_8 ) ;
V_8 -> V_293 |= V_295 ;
V_8 -> V_296 |= V_295 ;
V_8 -> V_297 = V_298 ;
F_175 ( V_8 -> V_299 ) ;
}
static inline int
F_176 ( struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
int V_153 ;
int V_250 ;
V_25 -> V_8 = V_8 ;
V_25 -> V_22 = F_27 ( V_8 ) ;
V_8 -> V_14 = F_177 ( struct V_9 ) ;
if ( ! V_8 -> V_14 )
return - V_54 ;
V_153 = F_178 ( & V_25 -> V_47 , V_300 ) ;
if ( V_153 )
goto V_301;
V_153 = F_179 ( & V_25 -> V_46 , V_8 ) ;
if ( V_153 )
goto V_302;
V_25 -> V_257 = 0 ;
V_25 -> V_220 = V_25 -> V_193 + V_25 -> V_257 ;
V_250 = V_25 -> V_220 + sizeof( struct V_66 ) ;
V_8 -> type = V_290 ;
V_8 -> V_259 = V_303 + V_250 ;
V_8 -> V_105 = V_304 - V_250 ;
if ( ! ( V_25 -> V_30 . V_33 & V_235 ) )
V_8 -> V_105 -= 8 ;
return 0 ;
V_302:
F_23 ( & V_25 -> V_47 ) ;
V_301:
F_24 ( V_8 -> V_14 ) ;
V_8 -> V_14 = NULL ;
return V_153 ;
}
static int F_180 ( struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
int V_48 = F_176 ( V_8 ) ;
if ( V_48 )
return V_48 ;
F_154 ( V_25 ) ;
if ( V_25 -> V_30 . V_43 ) {
V_8 -> V_293 |= V_305 ;
F_174 ( V_8 ) ;
}
return 0 ;
}
static int T_9 F_181 ( struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
struct V_22 * V_22 = F_27 ( V_8 ) ;
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
V_25 -> V_30 . V_103 = V_137 ;
F_29 ( V_8 ) ;
F_17 ( V_27 -> V_36 [ 0 ] , V_25 ) ;
return 0 ;
}
static int F_182 ( struct V_306 * V_307 [] , struct V_306 * V_74 [] )
{
T_5 V_103 ;
if ( ! V_74 || ! V_74 [ V_308 ] )
return 0 ;
V_103 = F_183 ( V_74 [ V_308 ] ) ;
if ( V_103 != V_137 &&
V_103 != V_121 &&
V_103 != 0 )
return - V_274 ;
return 0 ;
}
static void F_184 ( struct V_306 * V_74 [] ,
struct V_37 * V_30 )
{
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
if ( ! V_74 )
return;
if ( V_74 [ V_309 ] )
V_30 -> V_150 = F_185 ( V_74 [ V_309 ] ) ;
if ( V_74 [ V_310 ] )
V_30 -> V_31 = F_186 ( V_74 [ V_310 ] ) ;
if ( V_74 [ V_311 ] )
V_30 -> V_32 = F_186 ( V_74 [ V_311 ] ) ;
if ( V_74 [ V_312 ] )
V_30 -> V_196 = F_183 ( V_74 [ V_312 ] ) ;
if ( V_74 [ V_313 ] )
V_30 -> V_110 = F_183 ( V_74 [ V_313 ] ) ;
if ( V_74 [ V_314 ] )
V_30 -> V_254 = F_187 ( V_74 [ V_314 ] ) ;
if ( V_74 [ V_315 ] )
V_30 -> V_33 = F_185 ( V_74 [ V_315 ] ) ;
if ( V_74 [ V_308 ] )
V_30 -> V_103 = F_183 ( V_74 [ V_308 ] ) ;
if ( V_74 [ V_316 ] )
V_30 -> V_43 = true ;
}
static bool F_188 ( struct V_306 * V_74 [] ,
struct V_283 * V_284 )
{
bool V_153 = false ;
memset ( V_284 , 0 , sizeof( * V_284 ) ) ;
if ( ! V_74 )
return V_153 ;
if ( V_74 [ V_317 ] ) {
V_153 = true ;
V_284 -> type = F_189 ( V_74 [ V_317 ] ) ;
}
if ( V_74 [ V_318 ] ) {
V_153 = true ;
V_284 -> V_33 = F_189 ( V_74 [ V_318 ] ) ;
}
if ( V_74 [ V_319 ] ) {
V_153 = true ;
V_284 -> V_285 = F_190 ( V_74 [ V_319 ] ) ;
}
if ( V_74 [ V_320 ] ) {
V_153 = true ;
V_284 -> V_286 = F_190 ( V_74 [ V_320 ] ) ;
}
return V_153 ;
}
static int F_191 ( struct V_22 * V_321 , struct V_7 * V_8 ,
struct V_306 * V_307 [] , struct V_306 * V_74 [] )
{
struct V_22 * V_22 = F_27 ( V_8 ) ;
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
struct V_21 * V_322 , * V_25 ;
struct V_283 V_284 ;
V_322 = F_21 ( V_8 ) ;
if ( F_188 ( V_74 , & V_284 ) ) {
int V_48 = F_172 ( V_322 , & V_284 ) ;
if ( V_48 < 0 )
return V_48 ;
}
F_184 ( V_74 , & V_322 -> V_30 ) ;
if ( V_322 -> V_30 . V_43 ) {
if ( F_18 ( V_27 -> V_35 ) )
return - V_60 ;
} else {
V_25 = F_35 ( V_22 , & V_322 -> V_30 , 0 ) ;
if ( ! F_59 ( V_25 ) )
return - V_60 ;
}
return F_26 ( V_8 ) ;
}
static int F_192 ( struct V_7 * V_8 , struct V_306 * V_307 [] ,
struct V_306 * V_74 [] )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
struct V_37 V_38 ;
struct V_22 * V_22 = V_25 -> V_22 ;
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
struct V_283 V_284 ;
if ( V_8 == V_27 -> V_62 )
return - V_274 ;
if ( F_188 ( V_74 , & V_284 ) ) {
int V_48 = F_172 ( V_25 , & V_284 ) ;
if ( V_48 < 0 )
return V_48 ;
}
F_184 ( V_74 , & V_38 ) ;
if ( V_38 . V_43 )
return - V_274 ;
V_25 = F_35 ( V_22 , & V_38 , 0 ) ;
if ( ! F_59 ( V_25 ) ) {
if ( V_25 -> V_8 != V_8 )
return - V_60 ;
} else
V_25 = F_21 ( V_8 ) ;
return F_156 ( V_25 , & V_38 ) ;
}
static void F_193 ( struct V_7 * V_8 , struct V_323 * V_324 )
{
struct V_22 * V_22 = F_27 ( V_8 ) ;
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
if ( V_8 != V_27 -> V_62 )
F_194 ( V_8 , V_324 ) ;
}
static T_10 F_195 ( const struct V_7 * V_8 )
{
return
F_196 ( 4 ) +
F_196 ( sizeof( struct V_1 ) ) +
F_196 ( sizeof( struct V_1 ) ) +
F_196 ( 1 ) +
F_196 ( 1 ) +
F_196 ( 4 ) +
F_196 ( 4 ) +
F_196 ( 1 ) +
F_196 ( 2 ) +
F_196 ( 2 ) +
F_196 ( 2 ) +
F_196 ( 2 ) +
F_196 ( 0 ) +
0 ;
}
static int F_197 ( struct V_63 * V_64 , const struct V_7 * V_8 )
{
struct V_21 * V_155 = F_21 ( V_8 ) ;
struct V_37 * V_325 = & V_155 -> V_30 ;
if ( F_198 ( V_64 , V_309 , V_325 -> V_150 ) ||
F_199 ( V_64 , V_310 , & V_325 -> V_31 ) ||
F_199 ( V_64 , V_311 , & V_325 -> V_32 ) ||
F_200 ( V_64 , V_312 , V_325 -> V_196 ) ||
F_200 ( V_64 , V_313 , V_325 -> V_110 ) ||
F_201 ( V_64 , V_314 , V_325 -> V_254 ) ||
F_198 ( V_64 , V_315 , V_325 -> V_33 ) ||
F_200 ( V_64 , V_308 , V_325 -> V_103 ) )
goto V_326;
if ( F_202 ( V_64 , V_317 , V_155 -> V_217 . type ) ||
F_203 ( V_64 , V_319 , V_155 -> V_217 . V_285 ) ||
F_203 ( V_64 , V_320 , V_155 -> V_217 . V_286 ) ||
F_202 ( V_64 , V_318 , V_155 -> V_217 . V_33 ) )
goto V_326;
if ( V_325 -> V_43 )
if ( F_204 ( V_64 , V_316 ) )
goto V_326;
return 0 ;
V_326:
return - V_210 ;
}
struct V_22 * F_205 ( const struct V_7 * V_8 )
{
struct V_21 * V_155 = F_21 ( V_8 ) ;
return V_155 -> V_22 ;
}
static void T_11 F_206 ( struct V_22 * V_22 )
{
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
struct V_7 * V_8 , * V_327 ;
int V_39 ;
struct V_21 * V_25 ;
F_207 ( V_328 ) ;
F_208 (net, dev, aux)
if ( V_8 -> V_49 == & V_50 )
F_194 ( V_8 , & V_328 ) ;
for ( V_39 = 0 ; V_39 < V_329 ; V_39 ++ ) {
V_25 = F_18 ( V_27 -> V_330 [ V_39 ] ) ;
while ( V_25 ) {
if ( ! F_98 ( F_27 ( V_25 -> V_8 ) , V_22 ) )
F_194 ( V_25 -> V_8 , & V_328 ) ;
V_25 = F_18 ( V_25 -> V_44 ) ;
}
}
F_209 ( & V_328 ) ;
}
static int T_9 F_210 ( struct V_22 * V_22 )
{
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
struct V_21 * V_25 = NULL ;
int V_48 ;
V_27 -> V_41 [ 0 ] = V_27 -> V_36 ;
V_27 -> V_41 [ 1 ] = V_27 -> V_330 ;
V_48 = - V_54 ;
V_27 -> V_62 = F_32 ( sizeof( struct V_21 ) , L_10 ,
V_55 , V_56 ) ;
if ( ! V_27 -> V_62 )
goto V_331;
F_33 ( V_27 -> V_62 , V_22 ) ;
V_27 -> V_62 -> V_49 = & V_50 ;
V_27 -> V_62 -> V_293 |= V_305 ;
V_48 = F_181 ( V_27 -> V_62 ) ;
if ( V_48 < 0 )
goto V_332;
V_48 = F_211 ( V_27 -> V_62 ) ;
if ( V_48 < 0 )
goto V_332;
V_25 = F_21 ( V_27 -> V_62 ) ;
strcpy ( V_25 -> V_30 . V_52 , V_27 -> V_62 -> V_52 ) ;
return 0 ;
V_332:
F_20 ( V_27 -> V_62 ) ;
V_331:
return V_48 ;
}
static void T_11 F_212 ( struct V_22 * V_22 )
{
F_213 () ;
F_206 ( V_22 ) ;
F_214 () ;
}
static int T_12 F_215 ( void )
{
int V_48 ;
V_48 = F_216 ( & V_333 ) ;
if ( V_48 < 0 )
goto V_334;
V_48 = F_217 ( & V_335 , V_336 ) ;
if ( V_48 < 0 ) {
F_218 ( L_11 , V_337 ) ;
goto V_338;
}
V_48 = F_217 ( & V_339 , V_230 ) ;
if ( V_48 < 0 ) {
F_218 ( L_12 , V_337 ) ;
goto V_340;
}
V_48 = F_219 ( & V_50 ) ;
if ( V_48 < 0 )
goto V_341;
return 0 ;
V_341:
F_220 ( & V_339 , V_230 ) ;
V_340:
F_220 ( & V_335 , V_336 ) ;
V_338:
F_221 ( & V_333 ) ;
V_334:
return V_48 ;
}
static void T_13 F_222 ( void )
{
F_223 ( & V_50 ) ;
if ( F_220 ( & V_335 , V_336 ) )
F_224 ( L_13 , V_337 ) ;
if ( F_220 ( & V_339 , V_230 ) )
F_224 ( L_14 , V_337 ) ;
F_221 ( & V_333 ) ;
}
