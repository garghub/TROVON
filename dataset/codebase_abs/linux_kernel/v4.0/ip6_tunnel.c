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
int V_55 = - V_61 ;
if ( V_48 -> V_57 [ 0 ] )
F_33 ( V_57 , V_48 -> V_57 , V_60 ) ;
else
sprintf ( V_57 , L_1 ) ;
V_8 = F_34 ( sizeof( * V_23 ) , V_57 , V_62 ,
V_63 ) ;
if ( V_8 == NULL )
goto V_64;
F_35 ( V_8 , V_34 ) ;
V_23 = F_28 ( V_8 ) ;
V_23 -> V_41 = * V_48 ;
V_23 -> V_34 = F_29 ( V_8 ) ;
V_55 = F_27 ( V_8 ) ;
if ( V_55 < 0 )
goto V_65;
return V_23 ;
V_65:
F_24 ( V_8 ) ;
V_64:
return F_36 ( V_55 ) ;
}
static struct V_22 * F_37 ( struct V_34 * V_34 ,
struct V_47 * V_48 , int V_66 )
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
if ( V_66 )
return F_36 ( - V_67 ) ;
return V_23 ;
}
}
if ( ! V_66 )
return F_36 ( - V_68 ) ;
return F_32 ( V_34 , V_48 ) ;
}
static void
F_38 ( struct V_7 * V_8 )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
struct V_34 * V_34 = V_23 -> V_34 ;
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
if ( V_8 == V_38 -> V_69 )
F_39 ( V_38 -> V_46 [ 0 ] , NULL ) ;
else
F_23 ( V_38 , V_23 ) ;
F_11 ( V_23 ) ;
F_40 ( V_8 ) ;
}
T_3 F_41 ( struct V_70 * V_71 , T_4 * V_72 )
{
const struct V_73 * V_74 = ( const struct V_73 * ) V_72 ;
T_4 V_75 = V_74 -> V_75 ;
T_3 V_76 = sizeof( * V_74 ) ;
while ( F_42 ( V_75 ) && V_75 != V_77 ) {
T_3 V_78 = 0 ;
struct V_79 * V_80 ;
if ( V_72 + V_76 + sizeof( * V_80 ) > V_71 -> V_81 &&
! F_43 ( V_71 , V_72 - V_71 -> V_81 + V_76 + sizeof ( * V_80 ) ) )
break;
V_80 = (struct V_79 * ) ( V_72 + V_76 ) ;
if ( V_75 == V_82 ) {
struct V_83 * V_83 = (struct V_83 * ) V_80 ;
if ( V_83 -> V_84 )
break;
V_78 = 8 ;
} else if ( V_75 == V_85 ) {
V_78 = ( V_80 -> V_86 + 2 ) << 2 ;
} else {
V_78 = F_44 ( V_80 ) ;
}
if ( V_75 == V_87 ) {
T_3 V_12 = V_76 + 2 ;
while ( 1 ) {
struct V_88 * V_89 ;
if ( V_12 + sizeof ( * V_89 ) > V_76 + V_78 )
break;
V_89 = (struct V_88 * ) & V_72 [ V_12 ] ;
if ( V_89 -> type == V_90 &&
V_89 -> V_91 == 1 )
return V_12 ;
if ( V_89 -> type )
V_12 += V_89 -> V_91 + 2 ;
else
V_12 ++ ;
}
}
V_75 = V_80 -> V_75 ;
V_76 += V_78 ;
}
return 0 ;
}
static int
F_45 ( struct V_70 * V_71 , T_4 V_92 , struct V_93 * V_94 ,
T_5 * type , T_5 * V_95 , int * V_96 , T_6 * V_97 , int V_98 )
{
const struct V_73 * V_74 = ( const struct V_73 * ) V_71 -> V_81 ;
struct V_22 * V_23 ;
int V_99 = 0 ;
T_5 V_100 = V_101 ;
T_5 V_102 = V_103 ;
T_5 V_104 ;
T_6 V_105 = 0 ;
T_3 V_106 ;
int V_55 = - V_107 ;
F_46 () ;
V_23 = F_13 ( F_29 ( V_71 -> V_8 ) , & V_74 -> V_108 , & V_74 -> V_109 ) ;
if ( V_23 == NULL )
goto V_56;
V_104 = F_47 ( V_23 -> V_41 . V_110 ) ;
if ( V_104 != V_92 && V_104 != 0 )
goto V_56;
V_55 = 0 ;
switch ( * type ) {
T_6 V_111 ;
struct V_88 * V_89 ;
T_6 V_112 ;
case V_101 :
F_48 ( L_2 ,
V_23 -> V_41 . V_57 ) ;
V_99 = 1 ;
break;
case V_113 :
if ( ( * V_95 ) == V_114 ) {
F_48 ( L_3 ,
V_23 -> V_41 . V_57 ) ;
V_99 = 1 ;
}
break;
case V_115 :
V_111 = 0 ;
if ( ( * V_95 ) == V_116 )
V_111 = F_41 ( V_71 , V_71 -> V_81 ) ;
if ( V_111 && V_111 == * V_97 - 2 ) {
V_89 = (struct V_88 * ) & V_71 -> V_81 [ V_111 ] ;
if ( V_89 -> V_117 == 0 ) {
F_48 ( L_4 ,
V_23 -> V_41 . V_57 ) ;
V_99 = 1 ;
}
} else {
F_48 ( L_5 ,
V_23 -> V_41 . V_57 ) ;
}
break;
case V_118 :
V_112 = * V_97 - V_98 ;
if ( V_112 < V_119 )
V_112 = V_119 ;
V_23 -> V_8 -> V_112 = V_112 ;
V_106 = sizeof( * V_74 ) + F_49 ( V_74 -> V_120 ) ;
if ( V_106 > V_112 ) {
V_100 = V_118 ;
V_102 = 0 ;
V_105 = V_112 ;
V_99 = 1 ;
}
break;
}
* type = V_100 ;
* V_95 = V_102 ;
* V_97 = V_105 ;
* V_96 = V_99 ;
V_56:
F_50 () ;
return V_55 ;
}
static int
F_51 ( struct V_70 * V_71 , struct V_93 * V_94 ,
T_5 type , T_5 V_95 , int V_98 , T_7 V_97 )
{
int V_99 = 0 ;
T_5 V_100 = type ;
T_5 V_102 = V_95 ;
T_6 V_105 = F_52 ( V_97 ) ;
int V_55 ;
struct V_70 * V_121 ;
const struct V_122 * V_123 ;
struct V_124 * V_31 ;
struct V_125 V_126 ;
V_55 = F_45 ( V_71 , V_127 , V_94 , & V_100 , & V_102 ,
& V_99 , & V_105 , V_98 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( V_99 == 0 )
return 0 ;
switch ( V_100 ) {
case V_101 :
if ( V_102 != V_103 )
return 0 ;
V_100 = V_128 ;
V_102 = V_129 ;
break;
case V_118 :
if ( V_102 != 0 )
return 0 ;
V_100 = V_128 ;
V_102 = V_130 ;
break;
case V_131 :
V_100 = V_132 ;
V_102 = V_133 ;
default:
return 0 ;
}
if ( ! F_43 ( V_71 , V_98 + sizeof( struct V_122 ) ) )
return 0 ;
V_121 = F_53 ( V_71 , V_134 ) ;
if ( ! V_121 )
return 0 ;
F_54 ( V_121 ) ;
F_55 ( V_121 , V_98 ) ;
F_56 ( V_121 ) ;
V_123 = F_57 ( V_121 ) ;
V_31 = F_58 ( F_29 ( V_71 -> V_8 ) , & V_126 , NULL ,
V_123 -> V_109 , 0 ,
0 , 0 ,
V_127 , F_59 ( V_123 -> V_135 ) , 0 ) ;
if ( F_60 ( V_31 ) )
goto V_56;
V_121 -> V_8 = V_31 -> V_24 . V_8 ;
if ( V_31 -> V_136 & V_137 ) {
F_61 ( V_31 ) ;
V_31 = NULL ;
V_31 = F_58 ( F_29 ( V_71 -> V_8 ) , & V_126 , NULL ,
V_123 -> V_108 , V_123 -> V_109 ,
0 , 0 ,
V_127 ,
F_59 ( V_123 -> V_135 ) , 0 ) ;
if ( F_60 ( V_31 ) ||
V_31 -> V_24 . V_8 -> type != V_138 ) {
if ( ! F_60 ( V_31 ) )
F_61 ( V_31 ) ;
goto V_56;
}
F_62 ( V_121 , & V_31 -> V_24 ) ;
} else {
F_61 ( V_31 ) ;
if ( F_63 ( V_121 , V_123 -> V_108 , V_123 -> V_109 , V_123 -> V_135 ,
V_121 -> V_8 ) ||
F_64 ( V_121 ) -> V_8 -> type != V_138 )
goto V_56;
}
if ( V_100 == V_128 && V_102 == V_130 ) {
if ( V_105 > F_65 ( F_64 ( V_121 ) ) )
goto V_56;
F_64 ( V_121 ) -> V_27 -> V_139 ( F_64 ( V_121 ) , NULL , V_121 , V_105 ) ;
}
if ( V_100 == V_132 )
F_64 ( V_121 ) -> V_27 -> V_140 ( F_64 ( V_121 ) , NULL , V_121 ) ;
F_66 ( V_121 , V_100 , V_102 , F_67 ( V_105 ) ) ;
V_56:
F_68 ( V_121 ) ;
return 0 ;
}
static int
F_69 ( struct V_70 * V_71 , struct V_93 * V_94 ,
T_5 type , T_5 V_95 , int V_98 , T_7 V_97 )
{
int V_99 = 0 ;
T_5 V_100 = type ;
T_5 V_102 = V_95 ;
T_6 V_105 = F_52 ( V_97 ) ;
int V_55 ;
V_55 = F_45 ( V_71 , V_141 , V_94 , & V_100 , & V_102 ,
& V_99 , & V_105 , V_98 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( V_99 && F_43 ( V_71 , V_98 + sizeof( struct V_73 ) ) ) {
struct V_30 * V_31 ;
struct V_70 * V_121 = F_53 ( V_71 , V_134 ) ;
if ( ! V_121 )
return 0 ;
F_54 ( V_121 ) ;
F_55 ( V_121 , V_98 ) ;
F_56 ( V_121 ) ;
V_31 = F_70 ( F_29 ( V_71 -> V_8 ) , & F_71 ( V_121 ) -> V_109 ,
NULL , 0 , 0 ) ;
if ( V_31 && V_31 -> V_24 . V_8 )
V_121 -> V_8 = V_31 -> V_24 . V_8 ;
F_72 ( V_121 , V_100 , V_102 , V_105 ) ;
F_73 ( V_31 ) ;
F_68 ( V_121 ) ;
}
return 0 ;
}
static int F_74 ( const struct V_22 * V_23 ,
const struct V_73 * V_74 ,
struct V_70 * V_71 )
{
T_4 V_142 = F_75 ( V_74 ) & ~ V_143 ;
if ( V_23 -> V_41 . V_44 & V_144 )
F_76 ( F_57 ( V_71 ) , V_143 , V_142 ) ;
return F_77 ( V_74 , V_71 ) ;
}
static int F_78 ( const struct V_22 * V_23 ,
const struct V_73 * V_74 ,
struct V_70 * V_71 )
{
if ( V_23 -> V_41 . V_44 & V_144 )
F_79 ( F_75 ( V_74 ) , F_71 ( V_71 ) ) ;
return F_77 ( V_74 , V_71 ) ;
}
T_6 F_80 ( struct V_22 * V_23 ,
const struct V_1 * V_42 ,
const struct V_1 * V_43 )
{
struct V_47 * V_48 = & V_23 -> V_41 ;
int V_145 = F_81 ( V_42 ) ;
int V_146 = F_81 ( V_43 ) ;
T_6 V_44 = 0 ;
if ( V_145 == V_147 || V_146 == V_147 ) {
V_44 = V_148 ;
} else if ( V_145 & ( V_149 | V_150 ) &&
V_146 & ( V_149 | V_150 ) &&
! ( ( V_145 | V_146 ) & V_151 ) &&
( ! ( ( V_145 | V_146 ) & V_152 ) || V_48 -> V_153 ) ) {
if ( V_145 & V_149 )
V_44 |= V_154 ;
if ( V_146 & V_149 )
V_44 |= V_155 ;
}
return V_44 ;
}
int F_82 ( struct V_22 * V_23 ,
const struct V_1 * V_42 ,
const struct V_1 * V_43 )
{
struct V_47 * V_48 = & V_23 -> V_41 ;
int V_156 = 0 ;
struct V_34 * V_34 = V_23 -> V_34 ;
if ( ( V_48 -> V_44 & V_155 ) ||
( ( V_48 -> V_44 & V_148 ) &&
( F_80 ( V_23 , V_42 , V_43 ) & V_155 ) ) ) {
struct V_7 * V_157 = NULL ;
if ( V_48 -> V_153 )
V_157 = F_83 ( V_34 , V_48 -> V_153 ) ;
if ( ( F_84 ( V_42 ) ||
F_85 ( F_86 ( V_34 , V_42 , V_157 , 0 ) ) ) &&
F_85 ( ! F_86 ( V_34 , V_43 , NULL , 0 ) ) )
V_156 = 1 ;
}
return V_156 ;
}
static int F_87 ( struct V_70 * V_71 , T_3 V_158 ,
T_4 V_92 ,
int (* F_88)( const struct V_22 * V_23 ,
const struct V_73 * V_74 ,
struct V_70 * V_71 ) )
{
struct V_22 * V_23 ;
const struct V_73 * V_74 = F_71 ( V_71 ) ;
T_5 V_104 ;
int V_55 ;
F_46 () ;
V_23 = F_13 ( F_29 ( V_71 -> V_8 ) , & V_74 -> V_109 , & V_74 -> V_108 ) ;
if ( V_23 != NULL ) {
struct V_9 * V_14 ;
V_104 = F_47 ( V_23 -> V_41 . V_110 ) ;
if ( V_104 != V_92 && V_104 != 0 ) {
F_50 () ;
goto V_159;
}
if ( ! F_89 ( NULL , V_160 , V_71 ) ) {
F_50 () ;
goto V_159;
}
if ( ! F_82 ( V_23 , & V_74 -> V_108 , & V_74 -> V_109 ) ) {
V_23 -> V_8 -> V_20 . V_161 ++ ;
F_50 () ;
goto V_159;
}
V_71 -> V_162 = V_71 -> V_163 ;
F_56 ( V_71 ) ;
V_71 -> V_158 = F_90 ( V_158 ) ;
memset ( V_71 -> V_164 , 0 , sizeof( struct V_93 ) ) ;
F_91 ( V_71 , V_23 -> V_8 , V_23 -> V_34 ) ;
V_55 = F_88 ( V_23 , V_74 , V_71 ) ;
if ( F_92 ( V_55 ) ) {
if ( V_165 )
F_93 ( L_6 ,
& V_74 -> V_109 ,
F_75 ( V_74 ) ) ;
if ( V_55 > 1 ) {
++ V_23 -> V_8 -> V_20 . V_166 ;
++ V_23 -> V_8 -> V_20 . V_167 ;
F_50 () ;
goto V_159;
}
}
V_14 = F_94 ( V_23 -> V_8 -> V_14 ) ;
F_95 ( & V_14 -> V_15 ) ;
V_14 -> V_16 ++ ;
V_14 -> V_17 += V_71 -> V_106 ;
F_96 ( & V_14 -> V_15 ) ;
F_97 ( V_71 ) ;
F_50 () ;
return 0 ;
}
F_50 () ;
return 1 ;
V_159:
F_68 ( V_71 ) ;
return 0 ;
}
static int F_98 ( struct V_70 * V_71 )
{
return F_87 ( V_71 , V_168 , V_127 ,
F_74 ) ;
}
static int F_99 ( struct V_70 * V_71 )
{
return F_87 ( V_71 , V_169 , V_141 ,
F_78 ) ;
}
static void F_100 ( struct V_170 * V_94 , T_4 V_117 )
{
memset ( V_94 , 0 , sizeof( struct V_170 ) ) ;
V_94 -> V_171 [ 2 ] = V_90 ;
V_94 -> V_171 [ 3 ] = 1 ;
V_94 -> V_171 [ 4 ] = V_117 ;
V_94 -> V_171 [ 5 ] = V_172 ;
V_94 -> V_171 [ 6 ] = 1 ;
V_94 -> V_27 . V_173 = (struct V_79 * ) V_94 -> V_171 ;
V_94 -> V_27 . V_174 = 8 ;
}
static inline bool
F_101 ( const struct V_22 * V_23 , const struct V_73 * V_80 )
{
return F_16 ( & V_23 -> V_41 . V_43 , & V_80 -> V_109 ) ;
}
int F_102 ( struct V_22 * V_23 ,
const struct V_1 * V_42 ,
const struct V_1 * V_43 )
{
struct V_47 * V_48 = & V_23 -> V_41 ;
int V_156 = 0 ;
struct V_34 * V_34 = V_23 -> V_34 ;
if ( ( V_48 -> V_44 & V_154 ) ||
( ( V_48 -> V_44 & V_148 ) &&
( F_80 ( V_23 , V_42 , V_43 ) & V_154 ) ) ) {
struct V_7 * V_157 = NULL ;
F_46 () ;
if ( V_48 -> V_153 )
V_157 = F_83 ( V_34 , V_48 -> V_153 ) ;
if ( F_92 ( ! F_86 ( V_34 , V_42 , V_157 , 0 ) ) )
F_103 ( L_7 ,
V_48 -> V_57 ) ;
else if ( ! F_84 ( V_43 ) &&
F_92 ( F_86 ( V_34 , V_43 , NULL , 0 ) ) )
F_103 ( L_8 ,
V_48 -> V_57 ) ;
else
V_156 = 1 ;
F_50 () ;
}
return V_156 ;
}
static int F_104 ( struct V_70 * V_71 ,
struct V_7 * V_8 ,
T_4 V_142 ,
struct V_175 * V_176 ,
int V_117 ,
T_6 * V_177 )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
struct V_34 * V_34 = V_23 -> V_34 ;
struct V_6 * V_20 = & V_23 -> V_8 -> V_20 ;
struct V_73 * V_74 = F_71 ( V_71 ) ;
struct V_170 V_94 ;
struct V_21 * V_24 = NULL , * V_178 = NULL ;
struct V_7 * V_179 ;
int V_112 ;
unsigned int V_180 = sizeof( struct V_73 ) ;
T_5 V_110 ;
int V_55 = - 1 ;
if ( F_19 ( & V_23 -> V_41 . V_43 ) ) {
struct V_1 * V_181 ;
struct V_182 * V_183 ;
int V_184 ;
if ( ! F_64 ( V_71 ) )
goto V_185;
V_183 = F_105 ( F_64 ( V_71 ) ,
& F_71 ( V_71 ) -> V_108 ) ;
if ( ! V_183 )
goto V_185;
V_181 = (struct V_1 * ) & V_183 -> V_186 ;
V_184 = F_81 ( V_181 ) ;
if ( V_184 == V_147 )
V_181 = & F_71 ( V_71 ) -> V_108 ;
memcpy ( & V_176 -> V_108 , V_181 , sizeof( V_176 -> V_108 ) ) ;
F_106 ( V_183 ) ;
} else if ( ! V_176 -> V_187 )
V_24 = F_9 ( V_23 ) ;
if ( ! F_102 ( V_23 , & V_176 -> V_109 , & V_176 -> V_108 ) )
goto V_185;
if ( ! V_24 ) {
V_178 = F_107 ( V_34 , NULL , V_176 ) ;
if ( V_178 -> error )
goto V_185;
V_178 = F_108 ( V_34 , V_178 , F_109 ( V_176 ) , NULL , 0 ) ;
if ( F_60 ( V_178 ) ) {
V_55 = F_110 ( V_178 ) ;
V_178 = NULL ;
goto V_185;
}
V_24 = V_178 ;
}
V_179 = V_24 -> V_8 ;
if ( V_179 == V_8 ) {
V_20 -> V_188 ++ ;
F_48 ( L_9 ,
V_23 -> V_41 . V_57 ) ;
goto V_189;
}
V_112 = F_65 ( V_24 ) - sizeof( * V_74 ) ;
if ( V_117 >= 0 ) {
V_180 += 8 ;
V_112 -= 8 ;
}
if ( V_112 < V_119 )
V_112 = V_119 ;
if ( F_64 ( V_71 ) )
F_64 ( V_71 ) -> V_27 -> V_139 ( F_64 ( V_71 ) , NULL , V_71 , V_112 ) ;
if ( V_71 -> V_106 > V_112 ) {
* V_177 = V_112 ;
V_55 = - V_190 ;
goto V_189;
}
F_111 ( V_71 , ! F_112 ( V_23 -> V_34 , F_29 ( V_8 ) ) ) ;
V_180 += F_113 ( V_179 ) ;
if ( F_114 ( V_71 ) < V_180 || F_115 ( V_71 ) ||
( F_116 ( V_71 ) && ! F_117 ( V_71 , 0 ) ) ) {
struct V_70 * V_191 ;
V_191 = F_118 ( V_71 , V_180 ) ;
if ( ! V_191 )
goto V_189;
if ( V_71 -> V_192 )
F_119 ( V_191 , V_71 -> V_192 ) ;
F_120 ( V_71 ) ;
V_71 = V_191 ;
}
if ( V_176 -> V_187 ) {
F_62 ( V_71 , V_24 ) ;
V_178 = NULL ;
} else {
F_121 ( V_71 , V_24 ) ;
}
V_71 -> V_193 = V_71 -> V_163 ;
V_110 = V_176 -> V_194 ;
if ( V_117 >= 0 ) {
F_100 ( & V_94 , V_117 ) ;
F_122 ( V_71 , & V_94 . V_27 , & V_110 , NULL ) ;
}
if ( F_85 ( ! V_71 -> V_195 ) ) {
F_123 ( V_71 ) ;
V_71 -> V_195 = 1 ;
}
F_124 ( V_71 , sizeof( struct V_73 ) ) ;
F_56 ( V_71 ) ;
V_74 = F_71 ( V_71 ) ;
F_125 ( V_74 , F_126 ( 0 , V_142 ) ,
F_127 ( V_34 , V_71 , V_176 -> V_196 , false ) ) ;
V_74 -> V_197 = V_23 -> V_41 . V_197 ;
V_74 -> V_75 = V_110 ;
V_74 -> V_109 = V_176 -> V_109 ;
V_74 -> V_108 = V_176 -> V_108 ;
F_128 ( V_71 , V_8 ) ;
if ( V_178 )
F_12 ( V_23 , V_178 ) ;
return 0 ;
V_185:
V_20 -> V_198 ++ ;
F_129 ( V_71 ) ;
V_189:
F_10 ( V_178 ) ;
return V_55 ;
}
static inline int
F_130 ( struct V_70 * V_71 , struct V_7 * V_8 )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
const struct V_122 * V_199 = F_57 ( V_71 ) ;
int V_117 = - 1 ;
struct V_175 V_176 ;
T_4 V_142 ;
T_6 V_112 ;
T_5 V_104 ;
int V_55 ;
V_104 = F_47 ( V_23 -> V_41 . V_110 ) ;
if ( V_104 != V_127 && V_104 != 0 )
return - 1 ;
if ( ! ( V_23 -> V_41 . V_44 & V_200 ) )
V_117 = V_23 -> V_41 . V_117 ;
memcpy ( & V_176 , & V_23 -> V_201 . V_202 . V_203 , sizeof( V_176 ) ) ;
V_176 . V_194 = V_127 ;
V_142 = F_131 ( V_199 ) ;
if ( V_23 -> V_41 . V_44 & V_204 )
V_176 . V_196 |= F_67 ( ( T_6 ) V_199 -> V_135 << V_205 )
& V_206 ;
if ( V_23 -> V_41 . V_44 & V_207 )
V_176 . V_187 = V_71 -> V_208 ;
V_55 = F_104 ( V_71 , V_8 , V_142 , & V_176 , V_117 , & V_112 ) ;
if ( V_55 != 0 ) {
if ( V_55 == - V_190 )
F_66 ( V_71 , V_128 , V_130 ,
F_67 ( V_112 ) ) ;
return - 1 ;
}
return 0 ;
}
static inline int
F_132 ( struct V_70 * V_71 , struct V_7 * V_8 )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
struct V_73 * V_74 = F_71 ( V_71 ) ;
int V_117 = - 1 ;
T_3 V_98 ;
struct V_175 V_176 ;
T_4 V_142 ;
T_6 V_112 ;
T_5 V_104 ;
int V_55 ;
V_104 = F_47 ( V_23 -> V_41 . V_110 ) ;
if ( ( V_104 != V_141 && V_104 != 0 ) ||
F_101 ( V_23 , V_74 ) )
return - 1 ;
V_98 = F_41 ( V_71 , F_133 ( V_71 ) ) ;
if ( V_98 > 0 ) {
struct V_88 * V_89 ;
V_89 = (struct V_88 * ) & F_133 ( V_71 ) [ V_98 ] ;
if ( V_89 -> V_117 == 0 ) {
F_72 ( V_71 , V_115 ,
V_116 , V_98 + 2 ) ;
return - 1 ;
}
V_117 = V_89 -> V_117 - 1 ;
} else if ( ! ( V_23 -> V_41 . V_44 & V_200 ) )
V_117 = V_23 -> V_41 . V_117 ;
memcpy ( & V_176 , & V_23 -> V_201 . V_202 . V_203 , sizeof( V_176 ) ) ;
V_176 . V_194 = V_141 ;
V_142 = F_75 ( V_74 ) ;
if ( V_23 -> V_41 . V_44 & V_204 )
V_176 . V_196 |= ( * ( T_7 * ) V_74 & V_206 ) ;
if ( V_23 -> V_41 . V_44 & V_209 )
V_176 . V_196 |= F_134 ( V_74 ) ;
if ( V_23 -> V_41 . V_44 & V_207 )
V_176 . V_187 = V_71 -> V_208 ;
V_55 = F_104 ( V_71 , V_8 , V_142 , & V_176 , V_117 , & V_112 ) ;
if ( V_55 != 0 ) {
if ( V_55 == - V_190 )
F_72 ( V_71 , V_118 , 0 , V_112 ) ;
return - 1 ;
}
return 0 ;
}
static T_8
F_135 ( struct V_70 * V_71 , struct V_7 * V_8 )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
struct V_6 * V_20 = & V_23 -> V_8 -> V_20 ;
int V_156 ;
switch ( V_71 -> V_158 ) {
case F_90 ( V_168 ) :
V_156 = F_130 ( V_71 , V_8 ) ;
break;
case F_90 ( V_169 ) :
V_156 = F_132 ( V_71 , V_8 ) ;
break;
default:
goto V_210;
}
if ( V_156 < 0 )
goto V_210;
return V_211 ;
V_210:
V_20 -> V_212 ++ ;
V_20 -> V_213 ++ ;
F_68 ( V_71 ) ;
return V_211 ;
}
static void F_136 ( struct V_22 * V_23 )
{
struct V_7 * V_8 = V_23 -> V_8 ;
struct V_47 * V_48 = & V_23 -> V_41 ;
struct V_175 * V_176 = & V_23 -> V_201 . V_202 . V_203 ;
memcpy ( V_8 -> V_214 , & V_48 -> V_42 , sizeof( struct V_1 ) ) ;
memcpy ( V_8 -> V_215 , & V_48 -> V_43 , sizeof( struct V_1 ) ) ;
V_176 -> V_109 = V_48 -> V_42 ;
V_176 -> V_108 = V_48 -> V_43 ;
V_176 -> V_216 = V_48 -> V_153 ;
V_176 -> V_196 = 0 ;
if ( ! ( V_48 -> V_44 & V_204 ) )
V_176 -> V_196 |= V_206 & V_48 -> V_217 ;
if ( ! ( V_48 -> V_44 & V_209 ) )
V_176 -> V_196 |= V_218 & V_48 -> V_217 ;
V_48 -> V_44 &= ~ ( V_154 | V_155 | V_148 ) ;
V_48 -> V_44 |= F_80 ( V_23 , & V_48 -> V_42 , & V_48 -> V_43 ) ;
if ( V_48 -> V_44 & V_154 && V_48 -> V_44 & V_155 )
V_8 -> V_44 |= V_219 ;
else
V_8 -> V_44 &= ~ V_219 ;
V_8 -> V_220 = V_48 -> V_153 ;
if ( V_48 -> V_44 & V_154 ) {
int V_221 = ( F_81 ( & V_48 -> V_43 ) &
( V_150 | V_152 ) ) ;
struct V_30 * V_31 = F_70 ( V_23 -> V_34 ,
& V_48 -> V_43 , & V_48 -> V_42 ,
V_48 -> V_153 , V_221 ) ;
if ( V_31 == NULL )
return;
if ( V_31 -> V_24 . V_8 ) {
V_8 -> V_222 = V_31 -> V_24 . V_8 -> V_222 +
sizeof( struct V_73 ) ;
V_8 -> V_112 = V_31 -> V_24 . V_8 -> V_112 - sizeof( struct V_73 ) ;
if ( ! ( V_23 -> V_41 . V_44 & V_200 ) )
V_8 -> V_112 -= 8 ;
if ( V_8 -> V_112 < V_119 )
V_8 -> V_112 = V_119 ;
}
F_73 ( V_31 ) ;
}
}
static int
F_137 ( struct V_22 * V_23 , const struct V_47 * V_48 )
{
V_23 -> V_41 . V_42 = V_48 -> V_42 ;
V_23 -> V_41 . V_43 = V_48 -> V_43 ;
V_23 -> V_41 . V_44 = V_48 -> V_44 ;
V_23 -> V_41 . V_197 = V_48 -> V_197 ;
V_23 -> V_41 . V_117 = V_48 -> V_117 ;
V_23 -> V_41 . V_217 = V_48 -> V_217 ;
V_23 -> V_41 . V_153 = V_48 -> V_153 ;
V_23 -> V_41 . V_110 = V_48 -> V_110 ;
F_11 ( V_23 ) ;
F_136 ( V_23 ) ;
return 0 ;
}
static int F_138 ( struct V_22 * V_23 , struct V_47 * V_48 )
{
struct V_34 * V_34 = V_23 -> V_34 ;
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
int V_55 ;
F_23 ( V_38 , V_23 ) ;
F_139 () ;
V_55 = F_137 ( V_23 , V_48 ) ;
F_20 ( V_38 , V_23 ) ;
F_140 ( V_23 -> V_8 ) ;
return V_55 ;
}
static int F_141 ( struct V_22 * V_23 , struct V_47 * V_48 )
{
V_23 -> V_41 . V_110 = V_48 -> V_110 ;
F_140 ( V_23 -> V_8 ) ;
return 0 ;
}
static void
F_142 ( struct V_47 * V_48 , const struct V_223 * V_202 )
{
V_48 -> V_42 = V_202 -> V_42 ;
V_48 -> V_43 = V_202 -> V_43 ;
V_48 -> V_44 = V_202 -> V_44 ;
V_48 -> V_197 = V_202 -> V_197 ;
V_48 -> V_117 = V_202 -> V_117 ;
V_48 -> V_217 = V_202 -> V_217 ;
V_48 -> V_153 = V_202 -> V_153 ;
V_48 -> V_110 = V_202 -> V_110 ;
memcpy ( V_48 -> V_57 , V_202 -> V_57 , sizeof( V_202 -> V_57 ) ) ;
}
static void
F_143 ( struct V_223 * V_202 , const struct V_47 * V_48 )
{
V_202 -> V_42 = V_48 -> V_42 ;
V_202 -> V_43 = V_48 -> V_43 ;
V_202 -> V_44 = V_48 -> V_44 ;
V_202 -> V_197 = V_48 -> V_197 ;
V_202 -> V_117 = V_48 -> V_117 ;
V_202 -> V_217 = V_48 -> V_217 ;
V_202 -> V_153 = V_48 -> V_153 ;
V_202 -> V_110 = V_48 -> V_110 ;
memcpy ( V_202 -> V_57 , V_48 -> V_57 , sizeof( V_202 -> V_57 ) ) ;
}
static int
F_144 ( struct V_7 * V_8 , struct V_224 * V_225 , int V_226 )
{
int V_55 = 0 ;
struct V_223 V_48 ;
struct V_47 V_227 ;
struct V_22 * V_23 = F_28 ( V_8 ) ;
struct V_34 * V_34 = V_23 -> V_34 ;
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
switch ( V_226 ) {
case V_228 :
if ( V_8 == V_38 -> V_69 ) {
if ( F_145 ( & V_48 , V_225 -> V_229 . V_230 , sizeof( V_48 ) ) ) {
V_55 = - V_231 ;
break;
}
F_142 ( & V_227 , & V_48 ) ;
V_23 = F_37 ( V_34 , & V_227 , 0 ) ;
if ( F_60 ( V_23 ) )
V_23 = F_28 ( V_8 ) ;
} else {
memset ( & V_48 , 0 , sizeof( V_48 ) ) ;
}
F_143 ( & V_48 , & V_23 -> V_41 ) ;
if ( F_146 ( V_225 -> V_229 . V_230 , & V_48 , sizeof( V_48 ) ) ) {
V_55 = - V_231 ;
}
break;
case V_232 :
case V_233 :
V_55 = - V_234 ;
if ( ! F_147 ( V_34 -> V_235 , V_236 ) )
break;
V_55 = - V_231 ;
if ( F_145 ( & V_48 , V_225 -> V_229 . V_230 , sizeof( V_48 ) ) )
break;
V_55 = - V_237 ;
if ( V_48 . V_110 != V_141 && V_48 . V_110 != V_127 &&
V_48 . V_110 != 0 )
break;
F_142 ( & V_227 , & V_48 ) ;
V_23 = F_37 ( V_34 , & V_227 , V_226 == V_232 ) ;
if ( V_226 == V_233 ) {
if ( ! F_60 ( V_23 ) ) {
if ( V_23 -> V_8 != V_8 ) {
V_55 = - V_67 ;
break;
}
} else
V_23 = F_28 ( V_8 ) ;
if ( V_8 == V_38 -> V_69 )
V_55 = F_141 ( V_23 , & V_227 ) ;
else
V_55 = F_138 ( V_23 , & V_227 ) ;
}
if ( ! F_60 ( V_23 ) ) {
V_55 = 0 ;
F_143 ( & V_48 , & V_23 -> V_41 ) ;
if ( F_146 ( V_225 -> V_229 . V_230 , & V_48 , sizeof( V_48 ) ) )
V_55 = - V_231 ;
} else {
V_55 = F_110 ( V_23 ) ;
}
break;
case V_238 :
V_55 = - V_234 ;
if ( ! F_147 ( V_34 -> V_235 , V_236 ) )
break;
if ( V_8 == V_38 -> V_69 ) {
V_55 = - V_231 ;
if ( F_145 ( & V_48 , V_225 -> V_229 . V_230 , sizeof( V_48 ) ) )
break;
V_55 = - V_107 ;
F_142 ( & V_227 , & V_48 ) ;
V_23 = F_37 ( V_34 , & V_227 , 0 ) ;
if ( F_60 ( V_23 ) )
break;
V_55 = - V_234 ;
if ( V_23 -> V_8 == V_38 -> V_69 )
break;
V_8 = V_23 -> V_8 ;
}
V_55 = 0 ;
F_148 ( V_8 ) ;
break;
default:
V_55 = - V_237 ;
}
return V_55 ;
}
static int
F_149 ( struct V_7 * V_8 , int V_239 )
{
struct V_22 * V_240 = F_28 ( V_8 ) ;
if ( V_240 -> V_41 . V_110 == V_127 ) {
if ( V_239 < 68 )
return - V_237 ;
} else {
if ( V_239 < V_119 )
return - V_237 ;
}
if ( V_239 > 0xFFF8 - V_8 -> V_222 )
return - V_237 ;
V_8 -> V_112 = V_239 ;
return 0 ;
}
static void V_63 ( struct V_7 * V_8 )
{
struct V_22 * V_23 ;
V_8 -> V_241 = & V_242 ;
V_8 -> V_243 = F_24 ;
V_8 -> type = V_244 ;
V_8 -> V_222 = V_245 + sizeof( struct V_73 ) ;
V_8 -> V_112 = V_246 - sizeof( struct V_73 ) ;
V_23 = F_28 ( V_8 ) ;
if ( ! ( V_23 -> V_41 . V_44 & V_200 ) )
V_8 -> V_112 -= 8 ;
V_8 -> V_44 |= V_247 ;
V_8 -> V_248 = sizeof( struct V_1 ) ;
F_150 ( V_8 ) ;
V_8 -> V_249 = V_250 ;
F_151 ( V_8 -> V_251 ) ;
}
static inline int
F_152 ( struct V_7 * V_8 )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
V_23 -> V_8 = V_8 ;
V_23 -> V_34 = F_29 ( V_8 ) ;
V_8 -> V_14 = F_153 ( struct V_9 ) ;
if ( ! V_8 -> V_14 )
return - V_61 ;
return 0 ;
}
static int F_154 ( struct V_7 * V_8 )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
int V_55 = F_152 ( V_8 ) ;
if ( V_55 )
return V_55 ;
F_136 ( V_23 ) ;
return 0 ;
}
static int T_9 F_155 ( struct V_7 * V_8 )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
struct V_34 * V_34 = F_29 ( V_8 ) ;
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
V_23 -> V_41 . V_110 = V_141 ;
F_31 ( V_8 ) ;
F_21 ( V_38 -> V_46 [ 0 ] , V_23 ) ;
return 0 ;
}
static int F_156 ( struct V_252 * V_253 [] , struct V_252 * V_81 [] )
{
T_5 V_110 ;
if ( ! V_81 || ! V_81 [ V_254 ] )
return 0 ;
V_110 = F_157 ( V_81 [ V_254 ] ) ;
if ( V_110 != V_141 &&
V_110 != V_127 &&
V_110 != 0 )
return - V_237 ;
return 0 ;
}
static void F_158 ( struct V_252 * V_81 [] ,
struct V_47 * V_41 )
{
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
if ( ! V_81 )
return;
if ( V_81 [ V_255 ] )
V_41 -> V_153 = F_159 ( V_81 [ V_255 ] ) ;
if ( V_81 [ V_256 ] )
F_160 ( & V_41 -> V_42 , V_81 [ V_256 ] ,
sizeof( struct V_1 ) ) ;
if ( V_81 [ V_257 ] )
F_160 ( & V_41 -> V_43 , V_81 [ V_257 ] ,
sizeof( struct V_1 ) ) ;
if ( V_81 [ V_258 ] )
V_41 -> V_197 = F_157 ( V_81 [ V_258 ] ) ;
if ( V_81 [ V_259 ] )
V_41 -> V_117 = F_157 ( V_81 [ V_259 ] ) ;
if ( V_81 [ V_260 ] )
V_41 -> V_217 = F_161 ( V_81 [ V_260 ] ) ;
if ( V_81 [ V_261 ] )
V_41 -> V_44 = F_159 ( V_81 [ V_261 ] ) ;
if ( V_81 [ V_254 ] )
V_41 -> V_110 = F_157 ( V_81 [ V_254 ] ) ;
}
static int F_162 ( struct V_34 * V_262 , struct V_7 * V_8 ,
struct V_252 * V_253 [] , struct V_252 * V_81 [] )
{
struct V_34 * V_34 = F_29 ( V_8 ) ;
struct V_22 * V_263 , * V_23 ;
V_263 = F_28 ( V_8 ) ;
F_158 ( V_81 , & V_263 -> V_41 ) ;
V_23 = F_37 ( V_34 , & V_263 -> V_41 , 0 ) ;
if ( ! F_60 ( V_23 ) )
return - V_67 ;
return F_27 ( V_8 ) ;
}
static int F_163 ( struct V_7 * V_8 , struct V_252 * V_253 [] ,
struct V_252 * V_81 [] )
{
struct V_22 * V_23 = F_28 ( V_8 ) ;
struct V_47 V_48 ;
struct V_34 * V_34 = V_23 -> V_34 ;
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
if ( V_8 == V_38 -> V_69 )
return - V_237 ;
F_158 ( V_81 , & V_48 ) ;
V_23 = F_37 ( V_34 , & V_48 , 0 ) ;
if ( ! F_60 ( V_23 ) ) {
if ( V_23 -> V_8 != V_8 )
return - V_67 ;
} else
V_23 = F_28 ( V_8 ) ;
return F_138 ( V_23 , & V_48 ) ;
}
static void F_164 ( struct V_7 * V_8 , struct V_264 * V_265 )
{
struct V_34 * V_34 = F_29 ( V_8 ) ;
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
if ( V_8 != V_38 -> V_69 )
F_165 ( V_8 , V_265 ) ;
}
static T_10 F_166 ( const struct V_7 * V_8 )
{
return
F_167 ( 4 ) +
F_167 ( sizeof( struct V_1 ) ) +
F_167 ( sizeof( struct V_1 ) ) +
F_167 ( 1 ) +
F_167 ( 1 ) +
F_167 ( 4 ) +
F_167 ( 4 ) +
F_167 ( 1 ) +
0 ;
}
static int F_168 ( struct V_70 * V_71 , const struct V_7 * V_8 )
{
struct V_22 * V_266 = F_28 ( V_8 ) ;
struct V_47 * V_267 = & V_266 -> V_41 ;
if ( F_169 ( V_71 , V_255 , V_267 -> V_153 ) ||
F_170 ( V_71 , V_256 , sizeof( struct V_1 ) ,
& V_267 -> V_42 ) ||
F_170 ( V_71 , V_257 , sizeof( struct V_1 ) ,
& V_267 -> V_43 ) ||
F_171 ( V_71 , V_258 , V_267 -> V_197 ) ||
F_171 ( V_71 , V_259 , V_267 -> V_117 ) ||
F_172 ( V_71 , V_260 , V_267 -> V_217 ) ||
F_169 ( V_71 , V_261 , V_267 -> V_44 ) ||
F_171 ( V_71 , V_254 , V_267 -> V_110 ) )
goto V_268;
return 0 ;
V_268:
return - V_190 ;
}
struct V_34 * F_173 ( const struct V_7 * V_8 )
{
struct V_22 * V_266 = F_28 ( V_8 ) ;
return V_266 -> V_34 ;
}
static void T_11 F_174 ( struct V_34 * V_34 )
{
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
struct V_7 * V_8 , * V_269 ;
int V_49 ;
struct V_22 * V_23 ;
F_175 ( V_270 ) ;
F_176 (net, dev, aux)
if ( V_8 -> V_58 == & V_59 )
F_165 ( V_8 , & V_270 ) ;
for ( V_49 = 0 ; V_49 < V_271 ; V_49 ++ ) {
V_23 = F_22 ( V_38 -> V_272 [ V_49 ] ) ;
while ( V_23 != NULL ) {
if ( ! F_112 ( F_29 ( V_23 -> V_8 ) , V_34 ) )
F_165 ( V_23 -> V_8 , & V_270 ) ;
V_23 = F_22 ( V_23 -> V_53 ) ;
}
}
F_177 ( & V_270 ) ;
}
static int T_9 F_178 ( struct V_34 * V_34 )
{
struct V_37 * V_38 = F_14 ( V_34 , V_39 ) ;
struct V_22 * V_23 = NULL ;
int V_55 ;
V_38 -> V_51 [ 0 ] = V_38 -> V_46 ;
V_38 -> V_51 [ 1 ] = V_38 -> V_272 ;
V_55 = - V_61 ;
V_38 -> V_69 = F_34 ( sizeof( struct V_22 ) , L_10 ,
V_62 , V_63 ) ;
if ( ! V_38 -> V_69 )
goto V_273;
F_35 ( V_38 -> V_69 , V_34 ) ;
V_38 -> V_69 -> V_58 = & V_59 ;
V_38 -> V_69 -> V_274 |= V_275 ;
V_55 = F_155 ( V_38 -> V_69 ) ;
if ( V_55 < 0 )
goto V_276;
V_55 = F_179 ( V_38 -> V_69 ) ;
if ( V_55 < 0 )
goto V_276;
V_23 = F_28 ( V_38 -> V_69 ) ;
strcpy ( V_23 -> V_41 . V_57 , V_38 -> V_69 -> V_57 ) ;
return 0 ;
V_276:
F_24 ( V_38 -> V_69 ) ;
V_273:
return V_55 ;
}
static void T_11 F_180 ( struct V_34 * V_34 )
{
F_181 () ;
F_174 ( V_34 ) ;
F_182 () ;
}
static int T_12 F_183 ( void )
{
int V_55 ;
V_55 = F_184 ( & V_277 ) ;
if ( V_55 < 0 )
goto V_278;
V_55 = F_185 ( & V_279 , V_280 ) ;
if ( V_55 < 0 ) {
F_186 ( L_11 , V_281 ) ;
goto V_282;
}
V_55 = F_185 ( & V_283 , V_284 ) ;
if ( V_55 < 0 ) {
F_186 ( L_12 , V_281 ) ;
goto V_285;
}
V_55 = F_187 ( & V_59 ) ;
if ( V_55 < 0 )
goto V_286;
return 0 ;
V_286:
F_188 ( & V_283 , V_284 ) ;
V_285:
F_188 ( & V_279 , V_280 ) ;
V_282:
F_189 ( & V_277 ) ;
V_278:
return V_55 ;
}
static void T_13 F_190 ( void )
{
F_191 ( & V_59 ) ;
if ( F_188 ( & V_279 , V_280 ) )
F_192 ( L_13 , V_281 ) ;
if ( F_188 ( & V_283 , V_284 ) )
F_192 ( L_14 , V_281 ) ;
F_189 ( & V_277 ) ;
}
