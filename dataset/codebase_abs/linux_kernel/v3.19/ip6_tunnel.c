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
struct V_21 * F_9 ( struct V_22 * V_23 )
{
struct V_21 * V_24 = V_23 -> V_25 ;
if ( V_24 && V_24 -> V_26 &&
V_24 -> V_27 -> V_28 ( V_24 , V_23 -> V_29 ) == NULL ) {
V_23 -> V_25 = NULL ;
F_10 ( V_24 ) ;
return NULL ;
}
return V_24 ;
}
void F_11 ( struct V_22 * V_23 )
{
F_10 ( V_23 -> V_25 ) ;
V_23 -> V_25 = NULL ;
}
void F_12 ( struct V_22 * V_23 , struct V_21 * V_24 )
{
struct V_30 * V_31 = (struct V_30 * ) V_24 ;
V_23 -> V_29 = V_31 -> V_32 ? V_31 -> V_32 -> V_33 : 0 ;
F_10 ( V_23 -> V_25 ) ;
V_23 -> V_25 = V_24 ;
}
static struct V_22 *
F_13 ( struct V_34 * V_34 , const struct V_1 * V_35 , const struct V_1 * V_36 )
{
unsigned int V_4 = F_1 ( V_35 , V_36 ) ;
struct V_22 * V_23 ;
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
struct V_1 V_40 ;
F_15 (ip6n->tnls_r_l[hash]) {
if ( F_16 ( V_36 , & V_23 -> V_41 . V_42 ) &&
F_16 ( V_35 , & V_23 -> V_41 . V_43 ) &&
( V_23 -> V_8 -> V_44 & V_45 ) )
return V_23 ;
}
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_4 = F_1 ( & V_40 , V_36 ) ;
F_15 (ip6n->tnls_r_l[hash]) {
if ( F_16 ( V_36 , & V_23 -> V_41 . V_42 ) &&
( V_23 -> V_8 -> V_44 & V_45 ) )
return V_23 ;
}
V_4 = F_1 ( V_35 , & V_40 ) ;
F_15 (ip6n->tnls_r_l[hash]) {
if ( F_16 ( V_35 , & V_23 -> V_41 . V_43 ) &&
( V_23 -> V_8 -> V_44 & V_45 ) )
return V_23 ;
}
V_23 = F_17 ( V_38 -> V_46 [ 0 ] ) ;
if ( V_23 && ( V_23 -> V_8 -> V_44 & V_45 ) )
return V_23 ;
return NULL ;
}
static struct V_22 T_2 * *
F_18 ( struct V_37 * V_38 , const struct V_47 * V_48 )
{
const struct V_1 * V_35 = & V_48 -> V_43 ;
const struct V_1 * V_36 = & V_48 -> V_42 ;
unsigned int V_49 = 0 ;
int V_50 = 0 ;
if ( ! F_19 ( V_35 ) || ! F_19 ( V_36 ) ) {
V_50 = 1 ;
V_49 = F_1 ( V_35 , V_36 ) ;
}
return & V_38 -> V_51 [ V_50 ] [ V_49 ] ;
}
static void
F_20 ( struct V_37 * V_38 , struct V_22 * V_23 )
{
struct V_22 T_2 * * V_52 = F_18 ( V_38 , & V_23 -> V_41 ) ;
F_21 ( V_23 -> V_53 , F_22 ( * V_52 ) ) ;
F_21 ( * V_52 , V_23 ) ;
}
static void
F_23 ( struct V_37 * V_38 , struct V_22 * V_23 )
{
struct V_22 T_2 * * V_52 ;
struct V_22 * V_54 ;
for ( V_52 = F_18 ( V_38 , & V_23 -> V_41 ) ;
( V_54 = F_22 ( * V_52 ) ) != NULL ;
V_52 = & V_54 -> V_53 ) {
if ( V_23 == V_54 ) {
F_21 ( * V_52 , V_23 -> V_53 ) ;
break;
}
}
}
static void F_24 ( struct V_7 * V_8 )
{
F_25 ( V_8 -> V_14 ) ;
F_26 ( V_8 ) ;
}
static int F_27 ( struct V_7 * V_8 )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
struct V_34 * V_34 = F_29 ( V_8 ) ;
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
int V_55 ;
V_23 = F_28 ( V_8 ) ;
V_55 = F_30 ( V_8 ) ;
if ( V_55 < 0 )
goto V_56;
strcpy ( V_23 -> V_41 . V_57 , V_8 -> V_57 ) ;
V_8 -> V_58 = & V_59 ;
F_31 ( V_8 ) ;
F_20 ( V_38 , V_23 ) ;
return 0 ;
V_56:
return V_55 ;
}
static struct V_22 * F_32 ( struct V_34 * V_34 , struct V_47 * V_48 )
{
struct V_7 * V_8 ;
struct V_22 * V_23 ;
char V_57 [ V_60 ] ;
int V_55 ;
if ( V_48 -> V_57 [ 0 ] )
F_33 ( V_57 , V_48 -> V_57 , V_60 ) ;
else
sprintf ( V_57 , L_1 ) ;
V_8 = F_34 ( sizeof( * V_23 ) , V_57 , V_61 ,
V_62 ) ;
if ( V_8 == NULL )
goto V_63;
F_35 ( V_8 , V_34 ) ;
V_23 = F_28 ( V_8 ) ;
V_23 -> V_41 = * V_48 ;
V_23 -> V_34 = F_29 ( V_8 ) ;
V_55 = F_27 ( V_8 ) ;
if ( V_55 < 0 )
goto V_64;
return V_23 ;
V_64:
F_24 ( V_8 ) ;
V_63:
return NULL ;
}
static struct V_22 * F_36 ( struct V_34 * V_34 ,
struct V_47 * V_48 , int V_65 )
{
const struct V_1 * V_35 = & V_48 -> V_43 ;
const struct V_1 * V_36 = & V_48 -> V_42 ;
struct V_22 T_2 * * V_52 ;
struct V_22 * V_23 ;
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
for ( V_52 = F_18 ( V_38 , V_48 ) ;
( V_23 = F_22 ( * V_52 ) ) != NULL ;
V_52 = & V_23 -> V_53 ) {
if ( F_16 ( V_36 , & V_23 -> V_41 . V_42 ) &&
F_16 ( V_35 , & V_23 -> V_41 . V_43 ) ) {
if ( V_65 )
return NULL ;
return V_23 ;
}
}
if ( ! V_65 )
return NULL ;
return F_32 ( V_34 , V_48 ) ;
}
static void
F_37 ( struct V_7 * V_8 )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
struct V_34 * V_34 = V_23 -> V_34 ;
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
if ( V_8 == V_38 -> V_66 )
F_38 ( V_38 -> V_46 [ 0 ] , NULL ) ;
else
F_23 ( V_38 , V_23 ) ;
F_11 ( V_23 ) ;
F_39 ( V_8 ) ;
}
T_3 F_40 ( struct V_67 * V_68 , T_4 * V_69 )
{
const struct V_70 * V_71 = ( const struct V_70 * ) V_69 ;
T_4 V_72 = V_71 -> V_72 ;
T_3 V_73 = sizeof( * V_71 ) ;
while ( F_41 ( V_72 ) && V_72 != V_74 ) {
T_3 V_75 = 0 ;
struct V_76 * V_77 ;
if ( V_69 + V_73 + sizeof( * V_77 ) > V_68 -> V_78 &&
! F_42 ( V_68 , V_69 - V_68 -> V_78 + V_73 + sizeof ( * V_77 ) ) )
break;
V_77 = (struct V_76 * ) ( V_69 + V_73 ) ;
if ( V_72 == V_79 ) {
struct V_80 * V_80 = (struct V_80 * ) V_77 ;
if ( V_80 -> V_81 )
break;
V_75 = 8 ;
} else if ( V_72 == V_82 ) {
V_75 = ( V_77 -> V_83 + 2 ) << 2 ;
} else {
V_75 = F_43 ( V_77 ) ;
}
if ( V_72 == V_84 ) {
T_3 V_12 = V_73 + 2 ;
while ( 1 ) {
struct V_85 * V_86 ;
if ( V_12 + sizeof ( * V_86 ) > V_73 + V_75 )
break;
V_86 = (struct V_85 * ) & V_69 [ V_12 ] ;
if ( V_86 -> type == V_87 &&
V_86 -> V_88 == 1 )
return V_12 ;
if ( V_86 -> type )
V_12 += V_86 -> V_88 + 2 ;
else
V_12 ++ ;
}
}
V_72 = V_77 -> V_72 ;
V_73 += V_75 ;
}
return 0 ;
}
static int
F_44 ( struct V_67 * V_68 , T_4 V_89 , struct V_90 * V_91 ,
T_5 * type , T_5 * V_92 , int * V_93 , T_6 * V_94 , int V_95 )
{
const struct V_70 * V_71 = ( const struct V_70 * ) V_68 -> V_78 ;
struct V_22 * V_23 ;
int V_96 = 0 ;
T_5 V_97 = V_98 ;
T_5 V_99 = V_100 ;
T_5 V_101 ;
T_6 V_102 = 0 ;
T_3 V_103 ;
int V_55 = - V_104 ;
F_45 () ;
V_23 = F_13 ( F_29 ( V_68 -> V_8 ) , & V_71 -> V_105 , & V_71 -> V_106 ) ;
if ( V_23 == NULL )
goto V_56;
V_101 = F_46 ( V_23 -> V_41 . V_107 ) ;
if ( V_101 != V_89 && V_101 != 0 )
goto V_56;
V_55 = 0 ;
switch ( * type ) {
T_6 V_108 ;
struct V_85 * V_86 ;
T_6 V_109 ;
case V_98 :
F_47 ( L_2 ,
V_23 -> V_41 . V_57 ) ;
V_96 = 1 ;
break;
case V_110 :
if ( ( * V_92 ) == V_111 ) {
F_47 ( L_3 ,
V_23 -> V_41 . V_57 ) ;
V_96 = 1 ;
}
break;
case V_112 :
V_108 = 0 ;
if ( ( * V_92 ) == V_113 )
V_108 = F_40 ( V_68 , V_68 -> V_78 ) ;
if ( V_108 && V_108 == * V_94 - 2 ) {
V_86 = (struct V_85 * ) & V_68 -> V_78 [ V_108 ] ;
if ( V_86 -> V_114 == 0 ) {
F_47 ( L_4 ,
V_23 -> V_41 . V_57 ) ;
V_96 = 1 ;
}
} else {
F_47 ( L_5 ,
V_23 -> V_41 . V_57 ) ;
}
break;
case V_115 :
V_109 = * V_94 - V_95 ;
if ( V_109 < V_116 )
V_109 = V_116 ;
V_23 -> V_8 -> V_109 = V_109 ;
V_103 = sizeof( * V_71 ) + F_48 ( V_71 -> V_117 ) ;
if ( V_103 > V_109 ) {
V_97 = V_115 ;
V_99 = 0 ;
V_102 = V_109 ;
V_96 = 1 ;
}
break;
}
* type = V_97 ;
* V_92 = V_99 ;
* V_94 = V_102 ;
* V_93 = V_96 ;
V_56:
F_49 () ;
return V_55 ;
}
static int
F_50 ( struct V_67 * V_68 , struct V_90 * V_91 ,
T_5 type , T_5 V_92 , int V_95 , T_7 V_94 )
{
int V_96 = 0 ;
T_5 V_97 = type ;
T_5 V_99 = V_92 ;
T_6 V_102 = F_51 ( V_94 ) ;
int V_55 ;
struct V_67 * V_118 ;
const struct V_119 * V_120 ;
struct V_121 * V_31 ;
struct V_122 V_123 ;
V_55 = F_44 ( V_68 , V_124 , V_91 , & V_97 , & V_99 ,
& V_96 , & V_102 , V_95 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( V_96 == 0 )
return 0 ;
switch ( V_97 ) {
case V_98 :
if ( V_99 != V_100 )
return 0 ;
V_97 = V_125 ;
V_99 = V_126 ;
break;
case V_115 :
if ( V_99 != 0 )
return 0 ;
V_97 = V_125 ;
V_99 = V_127 ;
break;
case V_128 :
V_97 = V_129 ;
V_99 = V_130 ;
default:
return 0 ;
}
if ( ! F_42 ( V_68 , V_95 + sizeof( struct V_119 ) ) )
return 0 ;
V_118 = F_52 ( V_68 , V_131 ) ;
if ( ! V_118 )
return 0 ;
F_53 ( V_118 ) ;
F_54 ( V_118 , V_95 ) ;
F_55 ( V_118 ) ;
V_120 = F_56 ( V_118 ) ;
V_31 = F_57 ( F_29 ( V_68 -> V_8 ) , & V_123 , NULL ,
V_120 -> V_106 , 0 ,
0 , 0 ,
V_124 , F_58 ( V_120 -> V_132 ) , 0 ) ;
if ( F_59 ( V_31 ) )
goto V_56;
V_118 -> V_8 = V_31 -> V_24 . V_8 ;
if ( V_31 -> V_133 & V_134 ) {
F_60 ( V_31 ) ;
V_31 = NULL ;
V_31 = F_57 ( F_29 ( V_68 -> V_8 ) , & V_123 , NULL ,
V_120 -> V_105 , V_120 -> V_106 ,
0 , 0 ,
V_124 ,
F_58 ( V_120 -> V_132 ) , 0 ) ;
if ( F_59 ( V_31 ) ||
V_31 -> V_24 . V_8 -> type != V_135 ) {
if ( ! F_59 ( V_31 ) )
F_60 ( V_31 ) ;
goto V_56;
}
F_61 ( V_118 , & V_31 -> V_24 ) ;
} else {
F_60 ( V_31 ) ;
if ( F_62 ( V_118 , V_120 -> V_105 , V_120 -> V_106 , V_120 -> V_132 ,
V_118 -> V_8 ) ||
F_63 ( V_118 ) -> V_8 -> type != V_135 )
goto V_56;
}
if ( V_97 == V_125 && V_99 == V_127 ) {
if ( V_102 > F_64 ( F_63 ( V_118 ) ) )
goto V_56;
F_63 ( V_118 ) -> V_27 -> V_136 ( F_63 ( V_118 ) , NULL , V_118 , V_102 ) ;
}
if ( V_97 == V_129 )
F_63 ( V_118 ) -> V_27 -> V_137 ( F_63 ( V_118 ) , NULL , V_118 ) ;
F_65 ( V_118 , V_97 , V_99 , F_66 ( V_102 ) ) ;
V_56:
F_67 ( V_118 ) ;
return 0 ;
}
static int
F_68 ( struct V_67 * V_68 , struct V_90 * V_91 ,
T_5 type , T_5 V_92 , int V_95 , T_7 V_94 )
{
int V_96 = 0 ;
T_5 V_97 = type ;
T_5 V_99 = V_92 ;
T_6 V_102 = F_51 ( V_94 ) ;
int V_55 ;
V_55 = F_44 ( V_68 , V_138 , V_91 , & V_97 , & V_99 ,
& V_96 , & V_102 , V_95 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( V_96 && F_42 ( V_68 , V_95 + sizeof( struct V_70 ) ) ) {
struct V_30 * V_31 ;
struct V_67 * V_118 = F_52 ( V_68 , V_131 ) ;
if ( ! V_118 )
return 0 ;
F_53 ( V_118 ) ;
F_54 ( V_118 , V_95 ) ;
F_55 ( V_118 ) ;
V_31 = F_69 ( F_29 ( V_68 -> V_8 ) , & F_70 ( V_118 ) -> V_106 ,
NULL , 0 , 0 ) ;
if ( V_31 && V_31 -> V_24 . V_8 )
V_118 -> V_8 = V_31 -> V_24 . V_8 ;
F_71 ( V_118 , V_97 , V_99 , V_102 ) ;
F_72 ( V_31 ) ;
F_67 ( V_118 ) ;
}
return 0 ;
}
static int F_73 ( const struct V_22 * V_23 ,
const struct V_70 * V_71 ,
struct V_67 * V_68 )
{
T_4 V_139 = F_74 ( V_71 ) & ~ V_140 ;
if ( V_23 -> V_41 . V_44 & V_141 )
F_75 ( F_56 ( V_68 ) , V_140 , V_139 ) ;
return F_76 ( V_71 , V_68 ) ;
}
static int F_77 ( const struct V_22 * V_23 ,
const struct V_70 * V_71 ,
struct V_67 * V_68 )
{
if ( V_23 -> V_41 . V_44 & V_141 )
F_78 ( F_74 ( V_71 ) , F_70 ( V_68 ) ) ;
return F_76 ( V_71 , V_68 ) ;
}
T_6 F_79 ( struct V_22 * V_23 ,
const struct V_1 * V_42 ,
const struct V_1 * V_43 )
{
struct V_47 * V_48 = & V_23 -> V_41 ;
int V_142 = F_80 ( V_42 ) ;
int V_143 = F_80 ( V_43 ) ;
T_6 V_44 = 0 ;
if ( V_142 == V_144 || V_143 == V_144 ) {
V_44 = V_145 ;
} else if ( V_142 & ( V_146 | V_147 ) &&
V_143 & ( V_146 | V_147 ) &&
! ( ( V_142 | V_143 ) & V_148 ) &&
( ! ( ( V_142 | V_143 ) & V_149 ) || V_48 -> V_150 ) ) {
if ( V_142 & V_146 )
V_44 |= V_151 ;
if ( V_143 & V_146 )
V_44 |= V_152 ;
}
return V_44 ;
}
int F_81 ( struct V_22 * V_23 ,
const struct V_1 * V_42 ,
const struct V_1 * V_43 )
{
struct V_47 * V_48 = & V_23 -> V_41 ;
int V_153 = 0 ;
struct V_34 * V_34 = V_23 -> V_34 ;
if ( ( V_48 -> V_44 & V_152 ) ||
( ( V_48 -> V_44 & V_145 ) &&
( F_79 ( V_23 , V_42 , V_43 ) & V_152 ) ) ) {
struct V_7 * V_154 = NULL ;
if ( V_48 -> V_150 )
V_154 = F_82 ( V_34 , V_48 -> V_150 ) ;
if ( ( F_83 ( V_42 ) ||
F_84 ( F_85 ( V_34 , V_42 , V_154 , 0 ) ) ) &&
F_84 ( ! F_85 ( V_34 , V_43 , NULL , 0 ) ) )
V_153 = 1 ;
}
return V_153 ;
}
static int F_86 ( struct V_67 * V_68 , T_3 V_155 ,
T_4 V_89 ,
int (* F_87)( const struct V_22 * V_23 ,
const struct V_70 * V_71 ,
struct V_67 * V_68 ) )
{
struct V_22 * V_23 ;
const struct V_70 * V_71 = F_70 ( V_68 ) ;
T_5 V_101 ;
int V_55 ;
F_45 () ;
V_23 = F_13 ( F_29 ( V_68 -> V_8 ) , & V_71 -> V_106 , & V_71 -> V_105 ) ;
if ( V_23 != NULL ) {
struct V_9 * V_14 ;
V_101 = F_46 ( V_23 -> V_41 . V_107 ) ;
if ( V_101 != V_89 && V_101 != 0 ) {
F_49 () ;
goto V_156;
}
if ( ! F_88 ( NULL , V_157 , V_68 ) ) {
F_49 () ;
goto V_156;
}
if ( ! F_81 ( V_23 , & V_71 -> V_105 , & V_71 -> V_106 ) ) {
V_23 -> V_8 -> V_20 . V_158 ++ ;
F_49 () ;
goto V_156;
}
V_68 -> V_159 = V_68 -> V_160 ;
F_55 ( V_68 ) ;
V_68 -> V_155 = F_89 ( V_155 ) ;
memset ( V_68 -> V_161 , 0 , sizeof( struct V_90 ) ) ;
F_90 ( V_68 , V_23 -> V_8 , V_23 -> V_34 ) ;
V_55 = F_87 ( V_23 , V_71 , V_68 ) ;
if ( F_91 ( V_55 ) ) {
if ( V_162 )
F_92 ( L_6 ,
& V_71 -> V_106 ,
F_74 ( V_71 ) ) ;
if ( V_55 > 1 ) {
++ V_23 -> V_8 -> V_20 . V_163 ;
++ V_23 -> V_8 -> V_20 . V_164 ;
F_49 () ;
goto V_156;
}
}
V_14 = F_93 ( V_23 -> V_8 -> V_14 ) ;
F_94 ( & V_14 -> V_15 ) ;
V_14 -> V_16 ++ ;
V_14 -> V_17 += V_68 -> V_103 ;
F_95 ( & V_14 -> V_15 ) ;
F_96 ( V_68 ) ;
F_49 () ;
return 0 ;
}
F_49 () ;
return 1 ;
V_156:
F_67 ( V_68 ) ;
return 0 ;
}
static int F_97 ( struct V_67 * V_68 )
{
return F_86 ( V_68 , V_165 , V_124 ,
F_73 ) ;
}
static int F_98 ( struct V_67 * V_68 )
{
return F_86 ( V_68 , V_166 , V_138 ,
F_77 ) ;
}
static void F_99 ( struct V_167 * V_91 , T_4 V_114 )
{
memset ( V_91 , 0 , sizeof( struct V_167 ) ) ;
V_91 -> V_168 [ 2 ] = V_87 ;
V_91 -> V_168 [ 3 ] = 1 ;
V_91 -> V_168 [ 4 ] = V_114 ;
V_91 -> V_168 [ 5 ] = V_169 ;
V_91 -> V_168 [ 6 ] = 1 ;
V_91 -> V_27 . V_170 = (struct V_76 * ) V_91 -> V_168 ;
V_91 -> V_27 . V_171 = 8 ;
}
static inline bool
F_100 ( const struct V_22 * V_23 , const struct V_70 * V_77 )
{
return F_16 ( & V_23 -> V_41 . V_43 , & V_77 -> V_106 ) ;
}
int F_101 ( struct V_22 * V_23 ,
const struct V_1 * V_42 ,
const struct V_1 * V_43 )
{
struct V_47 * V_48 = & V_23 -> V_41 ;
int V_153 = 0 ;
struct V_34 * V_34 = V_23 -> V_34 ;
if ( ( V_48 -> V_44 & V_151 ) ||
( ( V_48 -> V_44 & V_145 ) &&
( F_79 ( V_23 , V_42 , V_43 ) & V_151 ) ) ) {
struct V_7 * V_154 = NULL ;
F_45 () ;
if ( V_48 -> V_150 )
V_154 = F_82 ( V_34 , V_48 -> V_150 ) ;
if ( F_91 ( ! F_85 ( V_34 , V_42 , V_154 , 0 ) ) )
F_102 ( L_7 ,
V_48 -> V_57 ) ;
else if ( ! F_83 ( V_43 ) &&
F_91 ( F_85 ( V_34 , V_43 , NULL , 0 ) ) )
F_102 ( L_8 ,
V_48 -> V_57 ) ;
else
V_153 = 1 ;
F_49 () ;
}
return V_153 ;
}
static int F_103 ( struct V_67 * V_68 ,
struct V_7 * V_8 ,
T_4 V_139 ,
struct V_172 * V_173 ,
int V_114 ,
T_6 * V_174 )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
struct V_34 * V_34 = V_23 -> V_34 ;
struct V_6 * V_20 = & V_23 -> V_8 -> V_20 ;
struct V_70 * V_71 = F_70 ( V_68 ) ;
struct V_167 V_91 ;
struct V_21 * V_24 = NULL , * V_175 = NULL ;
struct V_7 * V_176 ;
int V_109 ;
unsigned int V_177 = sizeof( struct V_70 ) ;
T_5 V_107 ;
int V_55 = - 1 ;
if ( F_19 ( & V_23 -> V_41 . V_43 ) ) {
struct V_1 * V_178 ;
struct V_179 * V_180 ;
int V_181 ;
if ( ! F_63 ( V_68 ) )
goto V_182;
V_180 = F_104 ( F_63 ( V_68 ) ,
& F_70 ( V_68 ) -> V_105 ) ;
if ( ! V_180 )
goto V_182;
V_178 = (struct V_1 * ) & V_180 -> V_183 ;
V_181 = F_80 ( V_178 ) ;
if ( V_181 == V_144 )
V_178 = & F_70 ( V_68 ) -> V_105 ;
memcpy ( & V_173 -> V_105 , V_178 , sizeof( V_173 -> V_105 ) ) ;
F_105 ( V_180 ) ;
} else if ( ! V_173 -> V_184 )
V_24 = F_9 ( V_23 ) ;
if ( ! F_101 ( V_23 , & V_173 -> V_106 , & V_173 -> V_105 ) )
goto V_182;
if ( ! V_24 ) {
V_175 = F_106 ( V_34 , NULL , V_173 ) ;
if ( V_175 -> error )
goto V_182;
V_175 = F_107 ( V_34 , V_175 , F_108 ( V_173 ) , NULL , 0 ) ;
if ( F_59 ( V_175 ) ) {
V_55 = F_109 ( V_175 ) ;
V_175 = NULL ;
goto V_182;
}
V_24 = V_175 ;
}
V_176 = V_24 -> V_8 ;
if ( V_176 == V_8 ) {
V_20 -> V_185 ++ ;
F_47 ( L_9 ,
V_23 -> V_41 . V_57 ) ;
goto V_186;
}
V_109 = F_64 ( V_24 ) - sizeof( * V_71 ) ;
if ( V_114 >= 0 ) {
V_177 += 8 ;
V_109 -= 8 ;
}
if ( V_109 < V_116 )
V_109 = V_116 ;
if ( F_63 ( V_68 ) )
F_63 ( V_68 ) -> V_27 -> V_136 ( F_63 ( V_68 ) , NULL , V_68 , V_109 ) ;
if ( V_68 -> V_103 > V_109 ) {
* V_174 = V_109 ;
V_55 = - V_187 ;
goto V_186;
}
F_110 ( V_68 , ! F_111 ( V_23 -> V_34 , F_29 ( V_8 ) ) ) ;
V_177 += F_112 ( V_176 ) ;
if ( F_113 ( V_68 ) < V_177 || F_114 ( V_68 ) ||
( F_115 ( V_68 ) && ! F_116 ( V_68 , 0 ) ) ) {
struct V_67 * V_188 ;
V_188 = F_117 ( V_68 , V_177 ) ;
if ( ! V_188 )
goto V_186;
if ( V_68 -> V_189 )
F_118 ( V_188 , V_68 -> V_189 ) ;
F_119 ( V_68 ) ;
V_68 = V_188 ;
}
if ( V_173 -> V_184 ) {
F_61 ( V_68 , V_24 ) ;
V_175 = NULL ;
} else {
F_120 ( V_68 , V_24 ) ;
}
V_68 -> V_190 = V_68 -> V_160 ;
V_107 = V_173 -> V_191 ;
if ( V_114 >= 0 ) {
F_99 ( & V_91 , V_114 ) ;
F_121 ( V_68 , & V_91 . V_27 , & V_107 , NULL ) ;
}
if ( F_84 ( ! V_68 -> V_192 ) ) {
F_122 ( V_68 ) ;
V_68 -> V_192 = 1 ;
}
F_123 ( V_68 , sizeof( struct V_70 ) ) ;
F_55 ( V_68 ) ;
V_71 = F_70 ( V_68 ) ;
F_124 ( V_71 , F_125 ( 0 , V_139 ) ,
F_126 ( V_34 , V_68 , V_173 -> V_193 , false ) ) ;
V_71 -> V_194 = V_23 -> V_41 . V_194 ;
V_71 -> V_72 = V_107 ;
V_71 -> V_106 = V_173 -> V_106 ;
V_71 -> V_105 = V_173 -> V_105 ;
F_127 ( V_68 , V_8 ) ;
if ( V_175 )
F_12 ( V_23 , V_175 ) ;
return 0 ;
V_182:
V_20 -> V_195 ++ ;
F_128 ( V_68 ) ;
V_186:
F_10 ( V_175 ) ;
return V_55 ;
}
static inline int
F_129 ( struct V_67 * V_68 , struct V_7 * V_8 )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
const struct V_119 * V_196 = F_56 ( V_68 ) ;
int V_114 = - 1 ;
struct V_172 V_173 ;
T_4 V_139 ;
T_6 V_109 ;
T_5 V_101 ;
int V_55 ;
V_101 = F_46 ( V_23 -> V_41 . V_107 ) ;
if ( V_101 != V_124 && V_101 != 0 )
return - 1 ;
if ( ! ( V_23 -> V_41 . V_44 & V_197 ) )
V_114 = V_23 -> V_41 . V_114 ;
memcpy ( & V_173 , & V_23 -> V_198 . V_199 . V_200 , sizeof( V_173 ) ) ;
V_173 . V_191 = V_124 ;
V_139 = F_130 ( V_196 ) ;
if ( V_23 -> V_41 . V_44 & V_201 )
V_173 . V_193 |= F_66 ( ( T_6 ) V_196 -> V_132 << V_202 )
& V_203 ;
if ( V_23 -> V_41 . V_44 & V_204 )
V_173 . V_184 = V_68 -> V_205 ;
V_55 = F_103 ( V_68 , V_8 , V_139 , & V_173 , V_114 , & V_109 ) ;
if ( V_55 != 0 ) {
if ( V_55 == - V_187 )
F_65 ( V_68 , V_125 , V_127 ,
F_66 ( V_109 ) ) ;
return - 1 ;
}
return 0 ;
}
static inline int
F_131 ( struct V_67 * V_68 , struct V_7 * V_8 )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
struct V_70 * V_71 = F_70 ( V_68 ) ;
int V_114 = - 1 ;
T_3 V_95 ;
struct V_172 V_173 ;
T_4 V_139 ;
T_6 V_109 ;
T_5 V_101 ;
int V_55 ;
V_101 = F_46 ( V_23 -> V_41 . V_107 ) ;
if ( ( V_101 != V_138 && V_101 != 0 ) ||
F_100 ( V_23 , V_71 ) )
return - 1 ;
V_95 = F_40 ( V_68 , F_132 ( V_68 ) ) ;
if ( V_95 > 0 ) {
struct V_85 * V_86 ;
V_86 = (struct V_85 * ) & F_132 ( V_68 ) [ V_95 ] ;
if ( V_86 -> V_114 == 0 ) {
F_71 ( V_68 , V_112 ,
V_113 , V_95 + 2 ) ;
return - 1 ;
}
V_114 = V_86 -> V_114 - 1 ;
} else if ( ! ( V_23 -> V_41 . V_44 & V_197 ) )
V_114 = V_23 -> V_41 . V_114 ;
memcpy ( & V_173 , & V_23 -> V_198 . V_199 . V_200 , sizeof( V_173 ) ) ;
V_173 . V_191 = V_138 ;
V_139 = F_74 ( V_71 ) ;
if ( V_23 -> V_41 . V_44 & V_201 )
V_173 . V_193 |= ( * ( T_7 * ) V_71 & V_203 ) ;
if ( V_23 -> V_41 . V_44 & V_206 )
V_173 . V_193 |= F_133 ( V_71 ) ;
if ( V_23 -> V_41 . V_44 & V_204 )
V_173 . V_184 = V_68 -> V_205 ;
V_55 = F_103 ( V_68 , V_8 , V_139 , & V_173 , V_114 , & V_109 ) ;
if ( V_55 != 0 ) {
if ( V_55 == - V_187 )
F_71 ( V_68 , V_115 , 0 , V_109 ) ;
return - 1 ;
}
return 0 ;
}
static T_8
F_134 ( struct V_67 * V_68 , struct V_7 * V_8 )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
struct V_6 * V_20 = & V_23 -> V_8 -> V_20 ;
int V_153 ;
switch ( V_68 -> V_155 ) {
case F_89 ( V_165 ) :
V_153 = F_129 ( V_68 , V_8 ) ;
break;
case F_89 ( V_166 ) :
V_153 = F_131 ( V_68 , V_8 ) ;
break;
default:
goto V_207;
}
if ( V_153 < 0 )
goto V_207;
return V_208 ;
V_207:
V_20 -> V_209 ++ ;
V_20 -> V_210 ++ ;
F_67 ( V_68 ) ;
return V_208 ;
}
static void F_135 ( struct V_22 * V_23 )
{
struct V_7 * V_8 = V_23 -> V_8 ;
struct V_47 * V_48 = & V_23 -> V_41 ;
struct V_172 * V_173 = & V_23 -> V_198 . V_199 . V_200 ;
memcpy ( V_8 -> V_211 , & V_48 -> V_42 , sizeof( struct V_1 ) ) ;
memcpy ( V_8 -> V_212 , & V_48 -> V_43 , sizeof( struct V_1 ) ) ;
V_173 -> V_106 = V_48 -> V_42 ;
V_173 -> V_105 = V_48 -> V_43 ;
V_173 -> V_213 = V_48 -> V_150 ;
V_173 -> V_193 = 0 ;
if ( ! ( V_48 -> V_44 & V_201 ) )
V_173 -> V_193 |= V_203 & V_48 -> V_214 ;
if ( ! ( V_48 -> V_44 & V_206 ) )
V_173 -> V_193 |= V_215 & V_48 -> V_214 ;
V_48 -> V_44 &= ~ ( V_151 | V_152 | V_145 ) ;
V_48 -> V_44 |= F_79 ( V_23 , & V_48 -> V_42 , & V_48 -> V_43 ) ;
if ( V_48 -> V_44 & V_151 && V_48 -> V_44 & V_152 )
V_8 -> V_44 |= V_216 ;
else
V_8 -> V_44 &= ~ V_216 ;
V_8 -> V_217 = V_48 -> V_150 ;
if ( V_48 -> V_44 & V_151 ) {
int V_218 = ( F_80 ( & V_48 -> V_43 ) &
( V_147 | V_149 ) ) ;
struct V_30 * V_31 = F_69 ( V_23 -> V_34 ,
& V_48 -> V_43 , & V_48 -> V_42 ,
V_48 -> V_150 , V_218 ) ;
if ( V_31 == NULL )
return;
if ( V_31 -> V_24 . V_8 ) {
V_8 -> V_219 = V_31 -> V_24 . V_8 -> V_219 +
sizeof( struct V_70 ) ;
V_8 -> V_109 = V_31 -> V_24 . V_8 -> V_109 - sizeof( struct V_70 ) ;
if ( ! ( V_23 -> V_41 . V_44 & V_197 ) )
V_8 -> V_109 -= 8 ;
if ( V_8 -> V_109 < V_116 )
V_8 -> V_109 = V_116 ;
}
F_72 ( V_31 ) ;
}
}
static int
F_136 ( struct V_22 * V_23 , const struct V_47 * V_48 )
{
V_23 -> V_41 . V_42 = V_48 -> V_42 ;
V_23 -> V_41 . V_43 = V_48 -> V_43 ;
V_23 -> V_41 . V_44 = V_48 -> V_44 ;
V_23 -> V_41 . V_194 = V_48 -> V_194 ;
V_23 -> V_41 . V_114 = V_48 -> V_114 ;
V_23 -> V_41 . V_214 = V_48 -> V_214 ;
V_23 -> V_41 . V_150 = V_48 -> V_150 ;
V_23 -> V_41 . V_107 = V_48 -> V_107 ;
F_11 ( V_23 ) ;
F_135 ( V_23 ) ;
return 0 ;
}
static int F_137 ( struct V_22 * V_23 , struct V_47 * V_48 )
{
struct V_34 * V_34 = V_23 -> V_34 ;
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
int V_55 ;
F_23 ( V_38 , V_23 ) ;
F_138 () ;
V_55 = F_136 ( V_23 , V_48 ) ;
F_20 ( V_38 , V_23 ) ;
F_139 ( V_23 -> V_8 ) ;
return V_55 ;
}
static int F_140 ( struct V_22 * V_23 , struct V_47 * V_48 )
{
V_23 -> V_41 . V_107 = V_48 -> V_107 ;
F_139 ( V_23 -> V_8 ) ;
return 0 ;
}
static void
F_141 ( struct V_47 * V_48 , const struct V_220 * V_199 )
{
V_48 -> V_42 = V_199 -> V_42 ;
V_48 -> V_43 = V_199 -> V_43 ;
V_48 -> V_44 = V_199 -> V_44 ;
V_48 -> V_194 = V_199 -> V_194 ;
V_48 -> V_114 = V_199 -> V_114 ;
V_48 -> V_214 = V_199 -> V_214 ;
V_48 -> V_150 = V_199 -> V_150 ;
V_48 -> V_107 = V_199 -> V_107 ;
memcpy ( V_48 -> V_57 , V_199 -> V_57 , sizeof( V_199 -> V_57 ) ) ;
}
static void
F_142 ( struct V_220 * V_199 , const struct V_47 * V_48 )
{
V_199 -> V_42 = V_48 -> V_42 ;
V_199 -> V_43 = V_48 -> V_43 ;
V_199 -> V_44 = V_48 -> V_44 ;
V_199 -> V_194 = V_48 -> V_194 ;
V_199 -> V_114 = V_48 -> V_114 ;
V_199 -> V_214 = V_48 -> V_214 ;
V_199 -> V_150 = V_48 -> V_150 ;
V_199 -> V_107 = V_48 -> V_107 ;
memcpy ( V_199 -> V_57 , V_48 -> V_57 , sizeof( V_199 -> V_57 ) ) ;
}
static int
F_143 ( struct V_7 * V_8 , struct V_221 * V_222 , int V_223 )
{
int V_55 = 0 ;
struct V_220 V_48 ;
struct V_47 V_224 ;
struct V_22 * V_23 = F_28 ( V_8 ) ;
struct V_34 * V_34 = V_23 -> V_34 ;
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
switch ( V_223 ) {
case V_225 :
if ( V_8 == V_38 -> V_66 ) {
if ( F_144 ( & V_48 , V_222 -> V_226 . V_227 , sizeof( V_48 ) ) ) {
V_55 = - V_228 ;
break;
}
F_141 ( & V_224 , & V_48 ) ;
V_23 = F_36 ( V_34 , & V_224 , 0 ) ;
if ( V_23 == NULL )
V_23 = F_28 ( V_8 ) ;
} else {
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
}
F_142 ( & V_48 , & V_23 -> V_41 ) ;
if ( F_145 ( V_222 -> V_226 . V_227 , & V_48 , sizeof( V_48 ) ) ) {
V_55 = - V_228 ;
}
break;
case V_229 :
case V_230 :
V_55 = - V_231 ;
if ( ! F_146 ( V_34 -> V_232 , V_233 ) )
break;
V_55 = - V_228 ;
if ( F_144 ( & V_48 , V_222 -> V_226 . V_227 , sizeof( V_48 ) ) )
break;
V_55 = - V_234 ;
if ( V_48 . V_107 != V_138 && V_48 . V_107 != V_124 &&
V_48 . V_107 != 0 )
break;
F_141 ( & V_224 , & V_48 ) ;
V_23 = F_36 ( V_34 , & V_224 , V_223 == V_229 ) ;
if ( V_223 == V_230 ) {
if ( V_23 != NULL ) {
if ( V_23 -> V_8 != V_8 ) {
V_55 = - V_235 ;
break;
}
} else
V_23 = F_28 ( V_8 ) ;
if ( V_8 == V_38 -> V_66 )
V_55 = F_140 ( V_23 , & V_224 ) ;
else
V_55 = F_137 ( V_23 , & V_224 ) ;
}
if ( V_23 ) {
V_55 = 0 ;
F_142 ( & V_48 , & V_23 -> V_41 ) ;
if ( F_145 ( V_222 -> V_226 . V_227 , & V_48 , sizeof( V_48 ) ) )
V_55 = - V_228 ;
} else
V_55 = ( V_223 == V_229 ? - V_236 : - V_104 ) ;
break;
case V_237 :
V_55 = - V_231 ;
if ( ! F_146 ( V_34 -> V_232 , V_233 ) )
break;
if ( V_8 == V_38 -> V_66 ) {
V_55 = - V_228 ;
if ( F_144 ( & V_48 , V_222 -> V_226 . V_227 , sizeof( V_48 ) ) )
break;
V_55 = - V_104 ;
F_141 ( & V_224 , & V_48 ) ;
V_23 = F_36 ( V_34 , & V_224 , 0 ) ;
if ( V_23 == NULL )
break;
V_55 = - V_231 ;
if ( V_23 -> V_8 == V_38 -> V_66 )
break;
V_8 = V_23 -> V_8 ;
}
V_55 = 0 ;
F_147 ( V_8 ) ;
break;
default:
V_55 = - V_234 ;
}
return V_55 ;
}
static int
F_148 ( struct V_7 * V_8 , int V_238 )
{
struct V_22 * V_239 = F_28 ( V_8 ) ;
if ( V_239 -> V_41 . V_107 == V_124 ) {
if ( V_238 < 68 )
return - V_234 ;
} else {
if ( V_238 < V_116 )
return - V_234 ;
}
if ( V_238 > 0xFFF8 - V_8 -> V_219 )
return - V_234 ;
V_8 -> V_109 = V_238 ;
return 0 ;
}
static void V_62 ( struct V_7 * V_8 )
{
struct V_22 * V_23 ;
V_8 -> V_240 = & V_241 ;
V_8 -> V_242 = F_24 ;
V_8 -> type = V_243 ;
V_8 -> V_219 = V_244 + sizeof( struct V_70 ) ;
V_8 -> V_109 = V_245 - sizeof( struct V_70 ) ;
V_23 = F_28 ( V_8 ) ;
if ( ! ( V_23 -> V_41 . V_44 & V_197 ) )
V_8 -> V_109 -= 8 ;
V_8 -> V_44 |= V_246 ;
V_8 -> V_247 = sizeof( struct V_1 ) ;
F_149 ( V_8 ) ;
V_8 -> V_248 = V_249 ;
F_150 ( V_8 -> V_250 ) ;
}
static inline int
F_151 ( struct V_7 * V_8 )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
V_23 -> V_8 = V_8 ;
V_23 -> V_34 = F_29 ( V_8 ) ;
V_8 -> V_14 = F_152 ( struct V_9 ) ;
if ( ! V_8 -> V_14 )
return - V_251 ;
return 0 ;
}
static int F_153 ( struct V_7 * V_8 )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
int V_55 = F_151 ( V_8 ) ;
if ( V_55 )
return V_55 ;
F_135 ( V_23 ) ;
return 0 ;
}
static int T_9 F_154 ( struct V_7 * V_8 )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
struct V_34 * V_34 = F_29 ( V_8 ) ;
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
V_23 -> V_41 . V_107 = V_138 ;
F_31 ( V_8 ) ;
F_21 ( V_38 -> V_46 [ 0 ] , V_23 ) ;
return 0 ;
}
static int F_155 ( struct V_252 * V_253 [] , struct V_252 * V_78 [] )
{
T_5 V_107 ;
if ( ! V_78 || ! V_78 [ V_254 ] )
return 0 ;
V_107 = F_156 ( V_78 [ V_254 ] ) ;
if ( V_107 != V_138 &&
V_107 != V_124 &&
V_107 != 0 )
return - V_234 ;
return 0 ;
}
static void F_157 ( struct V_252 * V_78 [] ,
struct V_47 * V_41 )
{
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
if ( ! V_78 )
return;
if ( V_78 [ V_255 ] )
V_41 -> V_150 = F_158 ( V_78 [ V_255 ] ) ;
if ( V_78 [ V_256 ] )
F_159 ( & V_41 -> V_42 , V_78 [ V_256 ] ,
sizeof( struct V_1 ) ) ;
if ( V_78 [ V_257 ] )
F_159 ( & V_41 -> V_43 , V_78 [ V_257 ] ,
sizeof( struct V_1 ) ) ;
if ( V_78 [ V_258 ] )
V_41 -> V_194 = F_156 ( V_78 [ V_258 ] ) ;
if ( V_78 [ V_259 ] )
V_41 -> V_114 = F_156 ( V_78 [ V_259 ] ) ;
if ( V_78 [ V_260 ] )
V_41 -> V_214 = F_160 ( V_78 [ V_260 ] ) ;
if ( V_78 [ V_261 ] )
V_41 -> V_44 = F_158 ( V_78 [ V_261 ] ) ;
if ( V_78 [ V_254 ] )
V_41 -> V_107 = F_156 ( V_78 [ V_254 ] ) ;
}
static int F_161 ( struct V_34 * V_262 , struct V_7 * V_8 ,
struct V_252 * V_253 [] , struct V_252 * V_78 [] )
{
struct V_34 * V_34 = F_29 ( V_8 ) ;
struct V_22 * V_263 ;
V_263 = F_28 ( V_8 ) ;
F_157 ( V_78 , & V_263 -> V_41 ) ;
if ( F_36 ( V_34 , & V_263 -> V_41 , 0 ) )
return - V_235 ;
return F_27 ( V_8 ) ;
}
static int F_162 ( struct V_7 * V_8 , struct V_252 * V_253 [] ,
struct V_252 * V_78 [] )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
struct V_47 V_48 ;
struct V_34 * V_34 = V_23 -> V_34 ;
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
if ( V_8 == V_38 -> V_66 )
return - V_234 ;
F_157 ( V_78 , & V_48 ) ;
V_23 = F_36 ( V_34 , & V_48 , 0 ) ;
if ( V_23 ) {
if ( V_23 -> V_8 != V_8 )
return - V_235 ;
} else
V_23 = F_28 ( V_8 ) ;
return F_137 ( V_23 , & V_48 ) ;
}
static void F_163 ( struct V_7 * V_8 , struct V_264 * V_265 )
{
struct V_34 * V_34 = F_29 ( V_8 ) ;
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
if ( V_8 != V_38 -> V_66 )
F_164 ( V_8 , V_265 ) ;
}
static T_10 F_165 ( const struct V_7 * V_8 )
{
return
F_166 ( 4 ) +
F_166 ( sizeof( struct V_1 ) ) +
F_166 ( sizeof( struct V_1 ) ) +
F_166 ( 1 ) +
F_166 ( 1 ) +
F_166 ( 4 ) +
F_166 ( 4 ) +
F_166 ( 1 ) +
0 ;
}
static int F_167 ( struct V_67 * V_68 , const struct V_7 * V_8 )
{
struct V_22 * V_266 = F_28 ( V_8 ) ;
struct V_47 * V_267 = & V_266 -> V_41 ;
if ( F_168 ( V_68 , V_255 , V_267 -> V_150 ) ||
F_169 ( V_68 , V_256 , sizeof( struct V_1 ) ,
& V_267 -> V_42 ) ||
F_169 ( V_68 , V_257 , sizeof( struct V_1 ) ,
& V_267 -> V_43 ) ||
F_170 ( V_68 , V_258 , V_267 -> V_194 ) ||
F_170 ( V_68 , V_259 , V_267 -> V_114 ) ||
F_171 ( V_68 , V_260 , V_267 -> V_214 ) ||
F_168 ( V_68 , V_261 , V_267 -> V_44 ) ||
F_170 ( V_68 , V_254 , V_267 -> V_107 ) )
goto V_268;
return 0 ;
V_268:
return - V_187 ;
}
static void T_11 F_172 ( struct V_34 * V_34 )
{
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
struct V_7 * V_8 , * V_269 ;
int V_49 ;
struct V_22 * V_23 ;
F_173 ( V_270 ) ;
F_174 (net, dev, aux)
if ( V_8 -> V_58 == & V_59 )
F_164 ( V_8 , & V_270 ) ;
for ( V_49 = 0 ; V_49 < V_271 ; V_49 ++ ) {
V_23 = F_22 ( V_38 -> V_272 [ V_49 ] ) ;
while ( V_23 != NULL ) {
if ( ! F_111 ( F_29 ( V_23 -> V_8 ) , V_34 ) )
F_164 ( V_23 -> V_8 , & V_270 ) ;
V_23 = F_22 ( V_23 -> V_53 ) ;
}
}
F_175 ( & V_270 ) ;
}
static int T_9 F_176 ( struct V_34 * V_34 )
{
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
struct V_22 * V_23 = NULL ;
int V_55 ;
V_38 -> V_51 [ 0 ] = V_38 -> V_46 ;
V_38 -> V_51 [ 1 ] = V_38 -> V_272 ;
V_55 = - V_251 ;
V_38 -> V_66 = F_34 ( sizeof( struct V_22 ) , L_10 ,
V_61 , V_62 ) ;
if ( ! V_38 -> V_66 )
goto V_273;
F_35 ( V_38 -> V_66 , V_34 ) ;
V_38 -> V_66 -> V_58 = & V_59 ;
V_38 -> V_66 -> V_274 |= V_275 ;
V_55 = F_154 ( V_38 -> V_66 ) ;
if ( V_55 < 0 )
goto V_276;
V_55 = F_177 ( V_38 -> V_66 ) ;
if ( V_55 < 0 )
goto V_276;
V_23 = F_28 ( V_38 -> V_66 ) ;
strcpy ( V_23 -> V_41 . V_57 , V_38 -> V_66 -> V_57 ) ;
return 0 ;
V_276:
F_24 ( V_38 -> V_66 ) ;
V_273:
return V_55 ;
}
static void T_11 F_178 ( struct V_34 * V_34 )
{
F_179 () ;
F_172 ( V_34 ) ;
F_180 () ;
}
static int T_12 F_181 ( void )
{
int V_55 ;
V_55 = F_182 ( & V_277 ) ;
if ( V_55 < 0 )
goto V_278;
V_55 = F_183 ( & V_279 , V_280 ) ;
if ( V_55 < 0 ) {
F_184 ( L_11 , V_281 ) ;
goto V_282;
}
V_55 = F_183 ( & V_283 , V_284 ) ;
if ( V_55 < 0 ) {
F_184 ( L_12 , V_281 ) ;
goto V_285;
}
V_55 = F_185 ( & V_59 ) ;
if ( V_55 < 0 )
goto V_286;
return 0 ;
V_286:
F_186 ( & V_283 , V_284 ) ;
V_285:
F_186 ( & V_279 , V_280 ) ;
V_282:
F_187 ( & V_277 ) ;
V_278:
return V_55 ;
}
static void T_13 F_188 ( void )
{
F_189 ( & V_59 ) ;
if ( F_186 ( & V_279 , V_280 ) )
F_190 ( L_13 , V_281 ) ;
if ( F_186 ( & V_283 , V_284 ) )
F_190 ( L_14 , V_281 ) ;
F_187 ( & V_277 ) ;
}
