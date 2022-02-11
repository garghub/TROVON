static T_1 F_1 ( const struct V_1 * V_2 , const struct V_1 * V_3 )
{
T_1 V_4 = F_2 ( V_2 ) ^ F_2 ( V_3 ) ;
return F_3 ( V_4 , V_5 ) ;
}
static struct V_6 * F_4 ( struct V_7 * V_8 )
{
struct V_9 V_10 = { 0 } ;
int V_11 ;
F_5 (i) {
const struct V_9 * V_12 = F_6 ( V_8 -> V_12 , V_11 ) ;
V_10 . V_13 += V_12 -> V_13 ;
V_10 . V_14 += V_12 -> V_14 ;
V_10 . V_15 += V_12 -> V_15 ;
V_10 . V_16 += V_12 -> V_16 ;
}
V_8 -> V_17 . V_13 = V_10 . V_13 ;
V_8 -> V_17 . V_14 = V_10 . V_14 ;
V_8 -> V_17 . V_15 = V_10 . V_15 ;
V_8 -> V_17 . V_16 = V_10 . V_16 ;
return & V_8 -> V_17 ;
}
struct V_18 * F_7 ( struct V_19 * V_20 )
{
struct V_18 * V_21 = V_20 -> V_22 ;
if ( V_21 && V_21 -> V_23 &&
V_21 -> V_24 -> V_25 ( V_21 , V_20 -> V_26 ) == NULL ) {
V_20 -> V_22 = NULL ;
F_8 ( V_21 ) ;
return NULL ;
}
return V_21 ;
}
void F_9 ( struct V_19 * V_20 )
{
F_8 ( V_20 -> V_22 ) ;
V_20 -> V_22 = NULL ;
}
void F_10 ( struct V_19 * V_20 , struct V_18 * V_21 )
{
struct V_27 * V_28 = (struct V_27 * ) V_21 ;
V_20 -> V_26 = V_28 -> V_29 ? V_28 -> V_29 -> V_30 : 0 ;
F_8 ( V_20 -> V_22 ) ;
V_20 -> V_22 = V_21 ;
}
static struct V_19 *
F_11 ( struct V_31 * V_31 , const struct V_1 * V_32 , const struct V_1 * V_33 )
{
unsigned int V_4 = F_1 ( V_32 , V_33 ) ;
struct V_19 * V_20 ;
struct V_34 * V_35 = F_12 ( V_31 , V_36 ) ;
F_13 (ip6n->tnls_r_l[hash]) {
if ( F_14 ( V_33 , & V_20 -> V_37 . V_38 ) &&
F_14 ( V_32 , & V_20 -> V_37 . V_39 ) &&
( V_20 -> V_8 -> V_40 & V_41 ) )
return V_20 ;
}
V_20 = F_15 ( V_35 -> V_42 [ 0 ] ) ;
if ( V_20 && ( V_20 -> V_8 -> V_40 & V_41 ) )
return V_20 ;
return NULL ;
}
static struct V_19 T_2 * *
F_16 ( struct V_34 * V_35 , const struct V_43 * V_44 )
{
const struct V_1 * V_32 = & V_44 -> V_39 ;
const struct V_1 * V_33 = & V_44 -> V_38 ;
unsigned int V_45 = 0 ;
int V_46 = 0 ;
if ( ! F_17 ( V_32 ) || ! F_17 ( V_33 ) ) {
V_46 = 1 ;
V_45 = F_1 ( V_32 , V_33 ) ;
}
return & V_35 -> V_47 [ V_46 ] [ V_45 ] ;
}
static void
F_18 ( struct V_34 * V_35 , struct V_19 * V_20 )
{
struct V_19 T_2 * * V_48 = F_16 ( V_35 , & V_20 -> V_37 ) ;
F_19 ( V_20 -> V_49 , F_20 ( * V_48 ) ) ;
F_19 ( * V_48 , V_20 ) ;
}
static void
F_21 ( struct V_34 * V_35 , struct V_19 * V_20 )
{
struct V_19 T_2 * * V_48 ;
struct V_19 * V_50 ;
for ( V_48 = F_16 ( V_35 , & V_20 -> V_37 ) ;
( V_50 = F_20 ( * V_48 ) ) != NULL ;
V_48 = & V_50 -> V_49 ) {
if ( V_20 == V_50 ) {
F_19 ( * V_48 , V_20 -> V_49 ) ;
break;
}
}
}
static void F_22 ( struct V_7 * V_8 )
{
F_23 ( V_8 -> V_12 ) ;
F_24 ( V_8 ) ;
}
static int F_25 ( struct V_7 * V_8 )
{
struct V_19 * V_20 = F_26 ( V_8 ) ;
struct V_31 * V_31 = F_27 ( V_8 ) ;
struct V_34 * V_35 = F_12 ( V_31 , V_36 ) ;
int V_51 ;
V_20 = F_26 ( V_8 ) ;
V_51 = F_28 ( V_8 ) ;
if ( V_51 < 0 )
goto V_52;
V_51 = F_29 ( V_8 ) ;
if ( V_51 < 0 )
goto V_52;
strcpy ( V_20 -> V_37 . V_53 , V_8 -> V_53 ) ;
V_8 -> V_54 = & V_55 ;
F_30 ( V_8 ) ;
F_18 ( V_35 , V_20 ) ;
return 0 ;
V_52:
return V_51 ;
}
static struct V_19 * F_31 ( struct V_31 * V_31 , struct V_43 * V_44 )
{
struct V_7 * V_8 ;
struct V_19 * V_20 ;
char V_53 [ V_56 ] ;
int V_51 ;
if ( V_44 -> V_53 [ 0 ] )
F_32 ( V_53 , V_44 -> V_53 , V_56 ) ;
else
sprintf ( V_53 , L_1 ) ;
V_8 = F_33 ( sizeof ( * V_20 ) , V_53 , V_57 ) ;
if ( V_8 == NULL )
goto V_58;
F_34 ( V_8 , V_31 ) ;
V_20 = F_26 ( V_8 ) ;
V_20 -> V_37 = * V_44 ;
V_51 = F_25 ( V_8 ) ;
if ( V_51 < 0 )
goto V_59;
return V_20 ;
V_59:
F_22 ( V_8 ) ;
V_58:
return NULL ;
}
static struct V_19 * F_35 ( struct V_31 * V_31 ,
struct V_43 * V_44 , int V_60 )
{
const struct V_1 * V_32 = & V_44 -> V_39 ;
const struct V_1 * V_33 = & V_44 -> V_38 ;
struct V_19 T_2 * * V_48 ;
struct V_19 * V_20 ;
struct V_34 * V_35 = F_12 ( V_31 , V_36 ) ;
for ( V_48 = F_16 ( V_35 , V_44 ) ;
( V_20 = F_20 ( * V_48 ) ) != NULL ;
V_48 = & V_20 -> V_49 ) {
if ( F_14 ( V_33 , & V_20 -> V_37 . V_38 ) &&
F_14 ( V_32 , & V_20 -> V_37 . V_39 ) )
return V_20 ;
}
if ( ! V_60 )
return NULL ;
return F_31 ( V_31 , V_44 ) ;
}
static void
F_36 ( struct V_7 * V_8 )
{
struct V_19 * V_20 = F_26 ( V_8 ) ;
struct V_31 * V_31 = F_27 ( V_8 ) ;
struct V_34 * V_35 = F_12 ( V_31 , V_36 ) ;
if ( V_8 == V_35 -> V_61 )
F_37 ( V_35 -> V_42 [ 0 ] , NULL ) ;
else
F_21 ( V_35 , V_20 ) ;
F_9 ( V_20 ) ;
F_38 ( V_8 ) ;
}
T_3 F_39 ( struct V_62 * V_63 , T_4 * V_64 )
{
const struct V_65 * V_66 = ( const struct V_65 * ) V_64 ;
T_4 V_67 = V_66 -> V_67 ;
T_3 V_68 = sizeof ( * V_66 ) ;
while ( F_40 ( V_67 ) && V_67 != V_69 ) {
T_3 V_70 = 0 ;
struct V_71 * V_72 ;
if ( V_64 + V_68 + sizeof ( * V_72 ) > V_63 -> V_73 &&
! F_41 ( V_63 , V_64 - V_63 -> V_73 + V_68 + sizeof ( * V_72 ) ) )
break;
V_72 = (struct V_71 * ) ( V_64 + V_68 ) ;
if ( V_67 == V_74 ) {
struct V_75 * V_75 = (struct V_75 * ) V_72 ;
if ( V_75 -> V_76 )
break;
V_70 = 8 ;
} else if ( V_67 == V_77 ) {
V_70 = ( V_72 -> V_78 + 2 ) << 2 ;
} else {
V_70 = F_42 ( V_72 ) ;
}
if ( V_67 == V_79 ) {
T_3 V_11 = V_68 + 2 ;
while ( 1 ) {
struct V_80 * V_81 ;
if ( V_11 + sizeof ( * V_81 ) > V_68 + V_70 )
break;
V_81 = (struct V_80 * ) & V_64 [ V_11 ] ;
if ( V_81 -> type == V_82 &&
V_81 -> V_83 == 1 )
return V_11 ;
if ( V_81 -> type )
V_11 += V_81 -> V_83 + 2 ;
else
V_11 ++ ;
}
}
V_67 = V_72 -> V_67 ;
V_68 += V_70 ;
}
return 0 ;
}
static int
F_43 ( struct V_62 * V_63 , T_4 V_84 , struct V_85 * V_86 ,
T_5 * type , T_5 * V_87 , int * V_88 , T_6 * V_89 , int V_90 )
{
const struct V_65 * V_66 = ( const struct V_65 * ) V_63 -> V_73 ;
struct V_19 * V_20 ;
int V_91 = 0 ;
T_5 V_92 = V_93 ;
T_5 V_94 = V_95 ;
T_6 V_96 = 0 ;
T_3 V_97 ;
int V_51 = - V_98 ;
F_44 () ;
if ( ( V_20 = F_11 ( F_27 ( V_63 -> V_8 ) , & V_66 -> V_99 ,
& V_66 -> V_100 ) ) == NULL )
goto V_52;
if ( V_20 -> V_37 . V_101 != V_84 && V_20 -> V_37 . V_101 != 0 )
goto V_52;
V_51 = 0 ;
switch ( * type ) {
T_6 V_102 ;
struct V_80 * V_81 ;
T_6 V_103 ;
case V_93 :
F_45 ( L_2 ,
V_20 -> V_37 . V_53 ) ;
V_91 = 1 ;
break;
case V_104 :
if ( ( * V_87 ) == V_105 ) {
F_45 ( L_3 ,
V_20 -> V_37 . V_53 ) ;
V_91 = 1 ;
}
break;
case V_106 :
V_102 = 0 ;
if ( ( * V_87 ) == V_107 )
V_102 = F_39 ( V_63 , V_63 -> V_73 ) ;
if ( V_102 && V_102 == * V_89 - 2 ) {
V_81 = (struct V_80 * ) & V_63 -> V_73 [ V_102 ] ;
if ( V_81 -> V_108 == 0 ) {
F_45 ( L_4 ,
V_20 -> V_37 . V_53 ) ;
V_91 = 1 ;
}
} else {
F_45 ( L_5 ,
V_20 -> V_37 . V_53 ) ;
}
break;
case V_109 :
V_103 = * V_89 - V_90 ;
if ( V_103 < V_110 )
V_103 = V_110 ;
V_20 -> V_8 -> V_103 = V_103 ;
if ( ( V_97 = sizeof ( * V_66 ) + F_46 ( V_66 -> V_111 ) ) > V_103 ) {
V_92 = V_109 ;
V_94 = 0 ;
V_96 = V_103 ;
V_91 = 1 ;
}
break;
}
* type = V_92 ;
* V_87 = V_94 ;
* V_89 = V_96 ;
* V_88 = V_91 ;
V_52:
F_47 () ;
return V_51 ;
}
static int
F_48 ( struct V_62 * V_63 , struct V_85 * V_86 ,
T_5 type , T_5 V_87 , int V_90 , T_7 V_89 )
{
int V_91 = 0 ;
T_5 V_92 = type ;
T_5 V_94 = V_87 ;
T_6 V_96 = F_49 ( V_89 ) ;
int V_51 ;
struct V_62 * V_112 ;
const struct V_113 * V_114 ;
struct V_115 * V_28 ;
struct V_116 V_117 ;
V_51 = F_43 ( V_63 , V_118 , V_86 , & V_92 , & V_94 ,
& V_91 , & V_96 , V_90 ) ;
if ( V_51 < 0 )
return V_51 ;
if ( V_91 == 0 )
return 0 ;
switch ( V_92 ) {
case V_93 :
if ( V_94 != V_95 )
return 0 ;
V_92 = V_119 ;
V_94 = V_120 ;
break;
case V_109 :
if ( V_94 != 0 )
return 0 ;
V_92 = V_119 ;
V_94 = V_121 ;
break;
case V_122 :
V_92 = V_123 ;
V_94 = V_124 ;
default:
return 0 ;
}
if ( ! F_41 ( V_63 , V_90 + sizeof( struct V_113 ) ) )
return 0 ;
V_112 = F_50 ( V_63 , V_125 ) ;
if ( ! V_112 )
return 0 ;
F_51 ( V_112 ) ;
F_52 ( V_112 , V_90 ) ;
F_53 ( V_112 ) ;
V_114 = F_54 ( V_112 ) ;
V_28 = F_55 ( F_27 ( V_63 -> V_8 ) , & V_117 , NULL ,
V_114 -> V_100 , 0 ,
0 , 0 ,
V_118 , F_56 ( V_114 -> V_126 ) , 0 ) ;
if ( F_57 ( V_28 ) )
goto V_52;
V_112 -> V_8 = V_28 -> V_21 . V_8 ;
if ( V_28 -> V_127 & V_128 ) {
F_58 ( V_28 ) ;
V_28 = NULL ;
V_28 = F_55 ( F_27 ( V_63 -> V_8 ) , & V_117 , NULL ,
V_114 -> V_99 , V_114 -> V_100 ,
0 , 0 ,
V_118 ,
F_56 ( V_114 -> V_126 ) , 0 ) ;
if ( F_57 ( V_28 ) ||
V_28 -> V_21 . V_8 -> type != V_129 ) {
if ( ! F_57 ( V_28 ) )
F_58 ( V_28 ) ;
goto V_52;
}
F_59 ( V_112 , & V_28 -> V_21 ) ;
} else {
F_58 ( V_28 ) ;
if ( F_60 ( V_112 , V_114 -> V_99 , V_114 -> V_100 , V_114 -> V_126 ,
V_112 -> V_8 ) ||
F_61 ( V_112 ) -> V_8 -> type != V_129 )
goto V_52;
}
if ( V_92 == V_119 && V_94 == V_121 ) {
if ( V_96 > F_62 ( F_61 ( V_112 ) ) )
goto V_52;
F_61 ( V_112 ) -> V_24 -> V_130 ( F_61 ( V_112 ) , NULL , V_112 , V_96 ) ;
}
if ( V_92 == V_123 )
F_61 ( V_112 ) -> V_24 -> V_131 ( F_61 ( V_112 ) , NULL , V_112 ) ;
F_63 ( V_112 , V_92 , V_94 , F_64 ( V_96 ) ) ;
V_52:
F_65 ( V_112 ) ;
return 0 ;
}
static int
F_66 ( struct V_62 * V_63 , struct V_85 * V_86 ,
T_5 type , T_5 V_87 , int V_90 , T_7 V_89 )
{
int V_91 = 0 ;
T_5 V_92 = type ;
T_5 V_94 = V_87 ;
T_6 V_96 = F_49 ( V_89 ) ;
int V_51 ;
V_51 = F_43 ( V_63 , V_132 , V_86 , & V_92 , & V_94 ,
& V_91 , & V_96 , V_90 ) ;
if ( V_51 < 0 )
return V_51 ;
if ( V_91 && F_41 ( V_63 , V_90 + sizeof( struct V_65 ) ) ) {
struct V_27 * V_28 ;
struct V_62 * V_112 = F_50 ( V_63 , V_125 ) ;
if ( ! V_112 )
return 0 ;
F_51 ( V_112 ) ;
F_52 ( V_112 , V_90 ) ;
F_53 ( V_112 ) ;
V_28 = F_67 ( F_27 ( V_63 -> V_8 ) , & F_68 ( V_112 ) -> V_100 ,
NULL , 0 , 0 ) ;
if ( V_28 && V_28 -> V_21 . V_8 )
V_112 -> V_8 = V_28 -> V_21 . V_8 ;
F_69 ( V_112 , V_92 , V_94 , V_96 ) ;
F_70 ( V_28 ) ;
F_65 ( V_112 ) ;
}
return 0 ;
}
static int F_71 ( const struct V_19 * V_20 ,
const struct V_65 * V_66 ,
struct V_62 * V_63 )
{
T_4 V_133 = F_72 ( V_66 ) & ~ V_134 ;
if ( V_20 -> V_37 . V_40 & V_135 )
F_73 ( F_54 ( V_63 ) , V_134 , V_133 ) ;
return F_74 ( V_66 , V_63 ) ;
}
static int F_75 ( const struct V_19 * V_20 ,
const struct V_65 * V_66 ,
struct V_62 * V_63 )
{
if ( V_20 -> V_37 . V_40 & V_135 )
F_76 ( F_72 ( V_66 ) , F_68 ( V_63 ) ) ;
return F_74 ( V_66 , V_63 ) ;
}
T_6 F_77 ( struct V_19 * V_20 ,
const struct V_1 * V_38 ,
const struct V_1 * V_39 )
{
struct V_43 * V_44 = & V_20 -> V_37 ;
int V_136 = F_78 ( V_38 ) ;
int V_137 = F_78 ( V_39 ) ;
T_6 V_40 = 0 ;
if ( V_136 == V_138 || V_137 == V_138 ) {
V_40 = V_139 ;
} else if ( V_136 & ( V_140 | V_141 ) &&
V_137 & ( V_140 | V_141 ) &&
! ( ( V_136 | V_137 ) & V_142 ) &&
( ! ( ( V_136 | V_137 ) & V_143 ) || V_44 -> V_144 ) ) {
if ( V_136 & V_140 )
V_40 |= V_145 ;
if ( V_137 & V_140 )
V_40 |= V_146 ;
}
return V_40 ;
}
int F_79 ( struct V_19 * V_20 ,
const struct V_1 * V_38 ,
const struct V_1 * V_39 )
{
struct V_43 * V_44 = & V_20 -> V_37 ;
int V_147 = 0 ;
struct V_31 * V_31 = F_27 ( V_20 -> V_8 ) ;
if ( ( V_44 -> V_40 & V_146 ) ||
( ( V_44 -> V_40 & V_139 ) &&
( F_77 ( V_20 , V_38 , V_39 ) & V_146 ) ) ) {
struct V_7 * V_148 = NULL ;
if ( V_44 -> V_144 )
V_148 = F_80 ( V_31 , V_44 -> V_144 ) ;
if ( ( F_81 ( V_38 ) ||
F_82 ( F_83 ( V_31 , V_38 , V_148 , 0 ) ) ) &&
F_82 ( ! F_83 ( V_31 , V_39 , NULL , 0 ) ) )
V_147 = 1 ;
}
return V_147 ;
}
static int F_84 ( struct V_62 * V_63 , T_3 V_149 ,
T_4 V_84 ,
int (* F_85)( const struct V_19 * V_20 ,
const struct V_65 * V_66 ,
struct V_62 * V_63 ) )
{
struct V_19 * V_20 ;
const struct V_65 * V_66 = F_68 ( V_63 ) ;
int V_51 ;
F_44 () ;
if ( ( V_20 = F_11 ( F_27 ( V_63 -> V_8 ) , & V_66 -> V_100 ,
& V_66 -> V_99 ) ) != NULL ) {
struct V_9 * V_12 ;
if ( V_20 -> V_37 . V_101 != V_84 && V_20 -> V_37 . V_101 != 0 ) {
F_47 () ;
goto V_150;
}
if ( ! F_86 ( NULL , V_151 , V_63 ) ) {
F_47 () ;
goto V_150;
}
if ( ! F_79 ( V_20 , & V_66 -> V_99 , & V_66 -> V_100 ) ) {
V_20 -> V_8 -> V_17 . V_152 ++ ;
F_47 () ;
goto V_150;
}
F_87 ( V_63 ) ;
V_63 -> V_153 = V_63 -> V_154 ;
F_53 ( V_63 ) ;
V_63 -> V_149 = F_88 ( V_149 ) ;
V_63 -> V_155 = V_156 ;
memset ( V_63 -> V_157 , 0 , sizeof( struct V_85 ) ) ;
F_89 ( V_63 , V_20 -> V_8 ) ;
V_51 = F_85 ( V_20 , V_66 , V_63 ) ;
if ( F_90 ( V_51 ) ) {
if ( V_158 )
F_91 ( L_6 ,
& V_66 -> V_100 ,
F_72 ( V_66 ) ) ;
if ( V_51 > 1 ) {
++ V_20 -> V_8 -> V_17 . V_159 ;
++ V_20 -> V_8 -> V_17 . V_160 ;
F_47 () ;
goto V_150;
}
}
V_12 = F_92 ( V_20 -> V_8 -> V_12 ) ;
V_12 -> V_13 ++ ;
V_12 -> V_14 += V_63 -> V_97 ;
F_93 ( V_63 ) ;
F_47 () ;
return 0 ;
}
F_47 () ;
return 1 ;
V_150:
F_65 ( V_63 ) ;
return 0 ;
}
static int F_94 ( struct V_62 * V_63 )
{
return F_84 ( V_63 , V_161 , V_118 ,
F_71 ) ;
}
static int F_95 ( struct V_62 * V_63 )
{
return F_84 ( V_63 , V_162 , V_132 ,
F_75 ) ;
}
static void F_96 ( struct V_163 * V_86 , T_4 V_108 )
{
memset ( V_86 , 0 , sizeof( struct V_163 ) ) ;
V_86 -> V_164 [ 2 ] = V_82 ;
V_86 -> V_164 [ 3 ] = 1 ;
V_86 -> V_164 [ 4 ] = V_108 ;
V_86 -> V_164 [ 5 ] = V_165 ;
V_86 -> V_164 [ 6 ] = 1 ;
V_86 -> V_24 . V_166 = (struct V_71 * ) V_86 -> V_164 ;
V_86 -> V_24 . V_167 = 8 ;
}
static inline bool
F_97 ( const struct V_19 * V_20 , const struct V_65 * V_72 )
{
return F_14 ( & V_20 -> V_37 . V_39 , & V_72 -> V_100 ) ;
}
int F_98 ( struct V_19 * V_20 )
{
struct V_43 * V_44 = & V_20 -> V_37 ;
int V_147 = 0 ;
struct V_31 * V_31 = F_27 ( V_20 -> V_8 ) ;
if ( V_44 -> V_40 & V_145 ) {
struct V_7 * V_148 = NULL ;
F_44 () ;
if ( V_44 -> V_144 )
V_148 = F_80 ( V_31 , V_44 -> V_144 ) ;
if ( F_90 ( ! F_83 ( V_31 , & V_44 -> V_38 , V_148 , 0 ) ) )
F_99 ( L_7 ,
V_44 -> V_53 ) ;
else if ( ! F_81 ( & V_44 -> V_39 ) &&
F_90 ( F_83 ( V_31 , & V_44 -> V_39 , NULL , 0 ) ) )
F_99 ( L_8 ,
V_44 -> V_53 ) ;
else
V_147 = 1 ;
F_47 () ;
}
return V_147 ;
}
static int F_100 ( struct V_62 * V_63 ,
struct V_7 * V_8 ,
T_4 V_133 ,
struct V_168 * V_169 ,
int V_108 ,
T_6 * V_170 )
{
struct V_31 * V_31 = F_27 ( V_8 ) ;
struct V_19 * V_20 = F_26 ( V_8 ) ;
struct V_6 * V_17 = & V_20 -> V_8 -> V_17 ;
struct V_65 * V_66 = F_68 ( V_63 ) ;
struct V_163 V_86 ;
struct V_18 * V_21 = NULL , * V_171 = NULL ;
struct V_7 * V_172 ;
int V_103 ;
unsigned int V_173 = sizeof( struct V_65 ) ;
T_5 V_101 ;
int V_51 = - 1 ;
if ( ! V_169 -> V_174 )
V_21 = F_7 ( V_20 ) ;
if ( ! V_21 ) {
V_171 = F_101 ( V_31 , NULL , V_169 ) ;
if ( V_171 -> error )
goto V_175;
V_171 = F_102 ( V_31 , V_171 , F_103 ( V_169 ) , NULL , 0 ) ;
if ( F_57 ( V_171 ) ) {
V_51 = F_104 ( V_171 ) ;
V_171 = NULL ;
goto V_175;
}
V_21 = V_171 ;
}
V_172 = V_21 -> V_8 ;
if ( V_172 == V_8 ) {
V_17 -> V_176 ++ ;
F_45 ( L_9 ,
V_20 -> V_37 . V_53 ) ;
goto V_177;
}
V_103 = F_62 ( V_21 ) - sizeof ( * V_66 ) ;
if ( V_108 >= 0 ) {
V_173 += 8 ;
V_103 -= 8 ;
}
if ( V_103 < V_110 )
V_103 = V_110 ;
if ( F_61 ( V_63 ) )
F_61 ( V_63 ) -> V_24 -> V_130 ( F_61 ( V_63 ) , NULL , V_63 , V_103 ) ;
if ( V_63 -> V_97 > V_103 ) {
* V_170 = V_103 ;
V_51 = - V_178 ;
goto V_177;
}
V_173 += F_105 ( V_172 ) ;
if ( F_106 ( V_63 ) < V_173 || F_107 ( V_63 ) ||
( F_108 ( V_63 ) && ! F_109 ( V_63 , 0 ) ) ) {
struct V_62 * V_179 ;
if ( ! ( V_179 = F_110 ( V_63 , V_173 ) ) )
goto V_177;
if ( V_63 -> V_180 )
F_111 ( V_179 , V_63 -> V_180 ) ;
F_112 ( V_63 ) ;
V_63 = V_179 ;
}
F_51 ( V_63 ) ;
if ( V_169 -> V_174 ) {
F_59 ( V_63 , V_21 ) ;
V_171 = NULL ;
} else {
F_113 ( V_63 , V_21 ) ;
}
V_63 -> V_181 = V_63 -> V_154 ;
V_101 = V_169 -> V_182 ;
if ( V_108 >= 0 ) {
F_96 ( & V_86 , V_108 ) ;
F_114 ( V_63 , & V_86 . V_24 , & V_101 , NULL ) ;
}
F_115 ( V_63 , sizeof( struct V_65 ) ) ;
F_53 ( V_63 ) ;
V_66 = F_68 ( V_63 ) ;
F_116 ( V_66 , F_117 ( 0 , V_133 ) , V_169 -> V_183 ) ;
V_66 -> V_184 = V_20 -> V_37 . V_184 ;
V_66 -> V_67 = V_101 ;
V_66 -> V_100 = V_169 -> V_100 ;
V_66 -> V_99 = V_169 -> V_99 ;
F_118 ( V_63 , V_8 ) ;
if ( V_171 )
F_10 ( V_20 , V_171 ) ;
return 0 ;
V_175:
V_17 -> V_185 ++ ;
F_119 ( V_63 ) ;
V_177:
F_8 ( V_171 ) ;
return V_51 ;
}
static inline int
F_120 ( struct V_62 * V_63 , struct V_7 * V_8 )
{
struct V_19 * V_20 = F_26 ( V_8 ) ;
const struct V_113 * V_186 = F_54 ( V_63 ) ;
int V_108 = - 1 ;
struct V_168 V_169 ;
T_4 V_133 ;
T_6 V_103 ;
int V_51 ;
if ( ( V_20 -> V_37 . V_101 != V_118 && V_20 -> V_37 . V_101 != 0 ) ||
! F_98 ( V_20 ) )
return - 1 ;
if ( ! ( V_20 -> V_37 . V_40 & V_187 ) )
V_108 = V_20 -> V_37 . V_108 ;
memcpy ( & V_169 , & V_20 -> V_188 . V_189 . V_190 , sizeof ( V_169 ) ) ;
V_169 . V_182 = V_118 ;
V_133 = F_121 ( V_186 ) ;
if ( V_20 -> V_37 . V_40 & V_191 )
V_169 . V_183 |= F_64 ( ( T_6 ) V_186 -> V_126 << V_192 )
& V_193 ;
if ( V_20 -> V_37 . V_40 & V_194 )
V_169 . V_174 = V_63 -> V_195 ;
V_51 = F_100 ( V_63 , V_8 , V_133 , & V_169 , V_108 , & V_103 ) ;
if ( V_51 != 0 ) {
if ( V_51 == - V_178 )
F_63 ( V_63 , V_119 , V_121 ,
F_64 ( V_103 ) ) ;
return - 1 ;
}
return 0 ;
}
static inline int
F_122 ( struct V_62 * V_63 , struct V_7 * V_8 )
{
struct V_19 * V_20 = F_26 ( V_8 ) ;
struct V_65 * V_66 = F_68 ( V_63 ) ;
int V_108 = - 1 ;
T_3 V_90 ;
struct V_168 V_169 ;
T_4 V_133 ;
T_6 V_103 ;
int V_51 ;
if ( ( V_20 -> V_37 . V_101 != V_132 && V_20 -> V_37 . V_101 != 0 ) ||
! F_98 ( V_20 ) || F_97 ( V_20 , V_66 ) )
return - 1 ;
V_90 = F_39 ( V_63 , F_123 ( V_63 ) ) ;
if ( V_90 > 0 ) {
struct V_80 * V_81 ;
V_81 = (struct V_80 * ) & F_123 ( V_63 ) [ V_90 ] ;
if ( V_81 -> V_108 == 0 ) {
F_69 ( V_63 , V_106 ,
V_107 , V_90 + 2 ) ;
return - 1 ;
}
V_108 = V_81 -> V_108 - 1 ;
} else if ( ! ( V_20 -> V_37 . V_40 & V_187 ) )
V_108 = V_20 -> V_37 . V_108 ;
memcpy ( & V_169 , & V_20 -> V_188 . V_189 . V_190 , sizeof ( V_169 ) ) ;
V_169 . V_182 = V_132 ;
V_133 = F_72 ( V_66 ) ;
if ( V_20 -> V_37 . V_40 & V_191 )
V_169 . V_183 |= ( * ( T_7 * ) V_66 & V_193 ) ;
if ( V_20 -> V_37 . V_40 & V_196 )
V_169 . V_183 |= ( * ( T_7 * ) V_66 & V_197 ) ;
if ( V_20 -> V_37 . V_40 & V_194 )
V_169 . V_174 = V_63 -> V_195 ;
V_51 = F_100 ( V_63 , V_8 , V_133 , & V_169 , V_108 , & V_103 ) ;
if ( V_51 != 0 ) {
if ( V_51 == - V_178 )
F_69 ( V_63 , V_109 , 0 , V_103 ) ;
return - 1 ;
}
return 0 ;
}
static T_8
F_124 ( struct V_62 * V_63 , struct V_7 * V_8 )
{
struct V_19 * V_20 = F_26 ( V_8 ) ;
struct V_6 * V_17 = & V_20 -> V_8 -> V_17 ;
int V_147 ;
switch ( V_63 -> V_149 ) {
case F_88 ( V_161 ) :
V_147 = F_120 ( V_63 , V_8 ) ;
break;
case F_88 ( V_162 ) :
V_147 = F_122 ( V_63 , V_8 ) ;
break;
default:
goto V_198;
}
if ( V_147 < 0 )
goto V_198;
return V_199 ;
V_198:
V_17 -> V_200 ++ ;
V_17 -> V_201 ++ ;
F_65 ( V_63 ) ;
return V_199 ;
}
static void F_125 ( struct V_19 * V_20 )
{
struct V_7 * V_8 = V_20 -> V_8 ;
struct V_43 * V_44 = & V_20 -> V_37 ;
struct V_168 * V_169 = & V_20 -> V_188 . V_189 . V_190 ;
memcpy ( V_8 -> V_202 , & V_44 -> V_38 , sizeof( struct V_1 ) ) ;
memcpy ( V_8 -> V_203 , & V_44 -> V_39 , sizeof( struct V_1 ) ) ;
V_169 -> V_100 = V_44 -> V_38 ;
V_169 -> V_99 = V_44 -> V_39 ;
V_169 -> V_204 = V_44 -> V_144 ;
V_169 -> V_183 = 0 ;
if ( ! ( V_44 -> V_40 & V_191 ) )
V_169 -> V_183 |= V_193 & V_44 -> V_205 ;
if ( ! ( V_44 -> V_40 & V_196 ) )
V_169 -> V_183 |= V_197 & V_44 -> V_205 ;
V_44 -> V_40 &= ~ ( V_145 | V_146 | V_139 ) ;
V_44 -> V_40 |= F_77 ( V_20 , & V_44 -> V_38 , & V_44 -> V_39 ) ;
if ( V_44 -> V_40 & V_145 && V_44 -> V_40 & V_146 )
V_8 -> V_40 |= V_206 ;
else
V_8 -> V_40 &= ~ V_206 ;
V_8 -> V_207 = V_44 -> V_144 ;
if ( V_44 -> V_40 & V_145 ) {
int V_208 = ( F_78 ( & V_44 -> V_39 ) &
( V_141 | V_143 ) ) ;
struct V_27 * V_28 = F_67 ( F_27 ( V_8 ) ,
& V_44 -> V_39 , & V_44 -> V_38 ,
V_44 -> V_144 , V_208 ) ;
if ( V_28 == NULL )
return;
if ( V_28 -> V_21 . V_8 ) {
V_8 -> V_209 = V_28 -> V_21 . V_8 -> V_209 +
sizeof ( struct V_65 ) ;
V_8 -> V_103 = V_28 -> V_21 . V_8 -> V_103 - sizeof ( struct V_65 ) ;
if ( ! ( V_20 -> V_37 . V_40 & V_187 ) )
V_8 -> V_103 -= 8 ;
if ( V_8 -> V_103 < V_110 )
V_8 -> V_103 = V_110 ;
}
F_70 ( V_28 ) ;
}
}
static int
F_126 ( struct V_19 * V_20 , const struct V_43 * V_44 )
{
V_20 -> V_37 . V_38 = V_44 -> V_38 ;
V_20 -> V_37 . V_39 = V_44 -> V_39 ;
V_20 -> V_37 . V_40 = V_44 -> V_40 ;
V_20 -> V_37 . V_184 = V_44 -> V_184 ;
V_20 -> V_37 . V_108 = V_44 -> V_108 ;
V_20 -> V_37 . V_205 = V_44 -> V_205 ;
V_20 -> V_37 . V_144 = V_44 -> V_144 ;
V_20 -> V_37 . V_101 = V_44 -> V_101 ;
F_9 ( V_20 ) ;
F_125 ( V_20 ) ;
return 0 ;
}
static int F_127 ( struct V_19 * V_20 , struct V_43 * V_44 )
{
struct V_31 * V_31 = F_27 ( V_20 -> V_8 ) ;
struct V_34 * V_35 = F_12 ( V_31 , V_36 ) ;
int V_51 ;
F_21 ( V_35 , V_20 ) ;
F_128 () ;
V_51 = F_126 ( V_20 , V_44 ) ;
F_18 ( V_35 , V_20 ) ;
F_129 ( V_20 -> V_8 ) ;
return V_51 ;
}
static void
F_130 ( struct V_43 * V_44 , const struct V_210 * V_189 )
{
V_44 -> V_38 = V_189 -> V_38 ;
V_44 -> V_39 = V_189 -> V_39 ;
V_44 -> V_40 = V_189 -> V_40 ;
V_44 -> V_184 = V_189 -> V_184 ;
V_44 -> V_108 = V_189 -> V_108 ;
V_44 -> V_205 = V_189 -> V_205 ;
V_44 -> V_144 = V_189 -> V_144 ;
V_44 -> V_101 = V_189 -> V_101 ;
memcpy ( V_44 -> V_53 , V_189 -> V_53 , sizeof( V_189 -> V_53 ) ) ;
}
static void
F_131 ( struct V_210 * V_189 , const struct V_43 * V_44 )
{
V_189 -> V_38 = V_44 -> V_38 ;
V_189 -> V_39 = V_44 -> V_39 ;
V_189 -> V_40 = V_44 -> V_40 ;
V_189 -> V_184 = V_44 -> V_184 ;
V_189 -> V_108 = V_44 -> V_108 ;
V_189 -> V_205 = V_44 -> V_205 ;
V_189 -> V_144 = V_44 -> V_144 ;
V_189 -> V_101 = V_44 -> V_101 ;
memcpy ( V_189 -> V_53 , V_44 -> V_53 , sizeof( V_189 -> V_53 ) ) ;
}
static int
F_132 ( struct V_7 * V_8 , struct V_211 * V_212 , int V_213 )
{
int V_51 = 0 ;
struct V_210 V_44 ;
struct V_43 V_214 ;
struct V_19 * V_20 = NULL ;
struct V_31 * V_31 = F_27 ( V_8 ) ;
struct V_34 * V_35 = F_12 ( V_31 , V_36 ) ;
switch ( V_213 ) {
case V_215 :
if ( V_8 == V_35 -> V_61 ) {
if ( F_133 ( & V_44 , V_212 -> V_216 . V_217 , sizeof ( V_44 ) ) ) {
V_51 = - V_218 ;
break;
}
F_130 ( & V_214 , & V_44 ) ;
V_20 = F_35 ( V_31 , & V_214 , 0 ) ;
} else {
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
}
if ( V_20 == NULL )
V_20 = F_26 ( V_8 ) ;
F_131 ( & V_44 , & V_20 -> V_37 ) ;
if ( F_134 ( V_212 -> V_216 . V_217 , & V_44 , sizeof ( V_44 ) ) ) {
V_51 = - V_218 ;
}
break;
case V_219 :
case V_220 :
V_51 = - V_221 ;
if ( ! F_135 ( V_31 -> V_222 , V_223 ) )
break;
V_51 = - V_218 ;
if ( F_133 ( & V_44 , V_212 -> V_216 . V_217 , sizeof ( V_44 ) ) )
break;
V_51 = - V_224 ;
if ( V_44 . V_101 != V_132 && V_44 . V_101 != V_118 &&
V_44 . V_101 != 0 )
break;
F_130 ( & V_214 , & V_44 ) ;
V_20 = F_35 ( V_31 , & V_214 , V_213 == V_219 ) ;
if ( V_8 != V_35 -> V_61 && V_213 == V_220 ) {
if ( V_20 != NULL ) {
if ( V_20 -> V_8 != V_8 ) {
V_51 = - V_225 ;
break;
}
} else
V_20 = F_26 ( V_8 ) ;
V_51 = F_127 ( V_20 , & V_214 ) ;
}
if ( V_20 ) {
V_51 = 0 ;
F_131 ( & V_44 , & V_20 -> V_37 ) ;
if ( F_134 ( V_212 -> V_216 . V_217 , & V_44 , sizeof( V_44 ) ) )
V_51 = - V_218 ;
} else
V_51 = ( V_213 == V_219 ? - V_226 : - V_98 ) ;
break;
case V_227 :
V_51 = - V_221 ;
if ( ! F_135 ( V_31 -> V_222 , V_223 ) )
break;
if ( V_8 == V_35 -> V_61 ) {
V_51 = - V_218 ;
if ( F_133 ( & V_44 , V_212 -> V_216 . V_217 , sizeof ( V_44 ) ) )
break;
V_51 = - V_98 ;
F_130 ( & V_214 , & V_44 ) ;
V_20 = F_35 ( V_31 , & V_214 , 0 ) ;
if ( V_20 == NULL )
break;
V_51 = - V_221 ;
if ( V_20 -> V_8 == V_35 -> V_61 )
break;
V_8 = V_20 -> V_8 ;
}
V_51 = 0 ;
F_136 ( V_8 ) ;
break;
default:
V_51 = - V_224 ;
}
return V_51 ;
}
static int
F_137 ( struct V_7 * V_8 , int V_228 )
{
if ( V_228 < V_110 ) {
return - V_224 ;
}
V_8 -> V_103 = V_228 ;
return 0 ;
}
static void V_57 ( struct V_7 * V_8 )
{
struct V_19 * V_20 ;
V_8 -> V_229 = & V_230 ;
V_8 -> V_231 = F_22 ;
V_8 -> type = V_232 ;
V_8 -> V_209 = V_233 + sizeof ( struct V_65 ) ;
V_8 -> V_103 = V_234 - sizeof ( struct V_65 ) ;
V_20 = F_26 ( V_8 ) ;
if ( ! ( V_20 -> V_37 . V_40 & V_187 ) )
V_8 -> V_103 -= 8 ;
V_8 -> V_40 |= V_235 ;
V_8 -> V_236 = sizeof( struct V_1 ) ;
V_8 -> V_237 |= V_238 ;
V_8 -> V_239 &= ~ V_240 ;
}
static inline int
F_138 ( struct V_7 * V_8 )
{
struct V_19 * V_20 = F_26 ( V_8 ) ;
V_20 -> V_8 = V_8 ;
V_8 -> V_12 = F_139 ( struct V_9 ) ;
if ( ! V_8 -> V_12 )
return - V_241 ;
return 0 ;
}
static int F_28 ( struct V_7 * V_8 )
{
struct V_19 * V_20 = F_26 ( V_8 ) ;
int V_51 = F_138 ( V_8 ) ;
if ( V_51 )
return V_51 ;
F_125 ( V_20 ) ;
return 0 ;
}
static int T_9 F_140 ( struct V_7 * V_8 )
{
struct V_19 * V_20 = F_26 ( V_8 ) ;
struct V_31 * V_31 = F_27 ( V_8 ) ;
struct V_34 * V_35 = F_12 ( V_31 , V_36 ) ;
int V_51 = F_138 ( V_8 ) ;
if ( V_51 )
return V_51 ;
V_20 -> V_37 . V_101 = V_132 ;
F_30 ( V_8 ) ;
F_125 ( V_20 ) ;
F_19 ( V_35 -> V_42 [ 0 ] , V_20 ) ;
return 0 ;
}
static int F_141 ( struct V_242 * V_243 [] , struct V_242 * V_73 [] )
{
T_5 V_101 ;
if ( ! V_73 )
return 0 ;
V_101 = F_142 ( V_73 [ V_244 ] ) ;
if ( V_101 != V_132 &&
V_101 != V_118 &&
V_101 != 0 )
return - V_224 ;
return 0 ;
}
static void F_143 ( struct V_242 * V_73 [] ,
struct V_43 * V_37 )
{
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
if ( ! V_73 )
return;
if ( V_73 [ V_245 ] )
V_37 -> V_144 = F_144 ( V_73 [ V_245 ] ) ;
if ( V_73 [ V_246 ] )
F_145 ( & V_37 -> V_38 , V_73 [ V_246 ] ,
sizeof( struct V_1 ) ) ;
if ( V_73 [ V_247 ] )
F_145 ( & V_37 -> V_39 , V_73 [ V_247 ] ,
sizeof( struct V_1 ) ) ;
if ( V_73 [ V_248 ] )
V_37 -> V_184 = F_142 ( V_73 [ V_248 ] ) ;
if ( V_73 [ V_249 ] )
V_37 -> V_108 = F_142 ( V_73 [ V_249 ] ) ;
if ( V_73 [ V_250 ] )
V_37 -> V_205 = F_146 ( V_73 [ V_250 ] ) ;
if ( V_73 [ V_251 ] )
V_37 -> V_40 = F_144 ( V_73 [ V_251 ] ) ;
if ( V_73 [ V_244 ] )
V_37 -> V_101 = F_142 ( V_73 [ V_244 ] ) ;
}
static int F_147 ( struct V_31 * V_252 , struct V_7 * V_8 ,
struct V_242 * V_243 [] , struct V_242 * V_73 [] )
{
struct V_31 * V_31 = F_27 ( V_8 ) ;
struct V_19 * V_253 ;
V_253 = F_26 ( V_8 ) ;
F_143 ( V_73 , & V_253 -> V_37 ) ;
if ( F_35 ( V_31 , & V_253 -> V_37 , 0 ) )
return - V_225 ;
return F_25 ( V_8 ) ;
}
static int F_148 ( struct V_7 * V_8 , struct V_242 * V_243 [] ,
struct V_242 * V_73 [] )
{
struct V_19 * V_20 ;
struct V_43 V_44 ;
struct V_31 * V_31 = F_27 ( V_8 ) ;
struct V_34 * V_35 = F_12 ( V_31 , V_36 ) ;
if ( V_8 == V_35 -> V_61 )
return - V_224 ;
F_143 ( V_73 , & V_44 ) ;
V_20 = F_35 ( V_31 , & V_44 , 0 ) ;
if ( V_20 ) {
if ( V_20 -> V_8 != V_8 )
return - V_225 ;
} else
V_20 = F_26 ( V_8 ) ;
return F_127 ( V_20 , & V_44 ) ;
}
static T_10 F_149 ( const struct V_7 * V_8 )
{
return
F_150 ( 4 ) +
F_150 ( sizeof( struct V_1 ) ) +
F_150 ( sizeof( struct V_1 ) ) +
F_150 ( 1 ) +
F_150 ( 1 ) +
F_150 ( 4 ) +
F_150 ( 4 ) +
F_150 ( 1 ) +
0 ;
}
static int F_151 ( struct V_62 * V_63 , const struct V_7 * V_8 )
{
struct V_19 * V_254 = F_26 ( V_8 ) ;
struct V_43 * V_255 = & V_254 -> V_37 ;
if ( F_152 ( V_63 , V_245 , V_255 -> V_144 ) ||
F_153 ( V_63 , V_246 , sizeof( struct V_1 ) ,
& V_255 -> V_39 ) ||
F_153 ( V_63 , V_247 , sizeof( struct V_1 ) ,
& V_255 -> V_38 ) ||
F_154 ( V_63 , V_248 , V_255 -> V_184 ) ||
F_154 ( V_63 , V_249 , V_255 -> V_108 ) ||
F_155 ( V_63 , V_250 , V_255 -> V_205 ) ||
F_152 ( V_63 , V_251 , V_255 -> V_40 ) ||
F_154 ( V_63 , V_244 , V_255 -> V_101 ) )
goto V_256;
return 0 ;
V_256:
return - V_178 ;
}
static void T_11 F_156 ( struct V_34 * V_35 )
{
int V_45 ;
struct V_19 * V_20 ;
F_157 ( V_257 ) ;
for ( V_45 = 0 ; V_45 < V_258 ; V_45 ++ ) {
V_20 = F_20 ( V_35 -> V_259 [ V_45 ] ) ;
while ( V_20 != NULL ) {
F_158 ( V_20 -> V_8 , & V_257 ) ;
V_20 = F_20 ( V_20 -> V_49 ) ;
}
}
V_20 = F_20 ( V_35 -> V_42 [ 0 ] ) ;
F_158 ( V_20 -> V_8 , & V_257 ) ;
F_159 ( & V_257 ) ;
}
static int T_9 F_160 ( struct V_31 * V_31 )
{
struct V_34 * V_35 = F_12 ( V_31 , V_36 ) ;
struct V_19 * V_20 = NULL ;
int V_51 ;
V_35 -> V_47 [ 0 ] = V_35 -> V_42 ;
V_35 -> V_47 [ 1 ] = V_35 -> V_259 ;
V_51 = - V_241 ;
V_35 -> V_61 = F_33 ( sizeof( struct V_19 ) , L_10 ,
V_57 ) ;
if ( ! V_35 -> V_61 )
goto V_260;
F_34 ( V_35 -> V_61 , V_31 ) ;
V_51 = F_140 ( V_35 -> V_61 ) ;
if ( V_51 < 0 )
goto V_261;
V_51 = F_161 ( V_35 -> V_61 ) ;
if ( V_51 < 0 )
goto V_261;
V_20 = F_26 ( V_35 -> V_61 ) ;
strcpy ( V_20 -> V_37 . V_53 , V_35 -> V_61 -> V_53 ) ;
return 0 ;
V_261:
F_22 ( V_35 -> V_61 ) ;
V_260:
return V_51 ;
}
static void T_11 F_162 ( struct V_31 * V_31 )
{
struct V_34 * V_35 = F_12 ( V_31 , V_36 ) ;
F_163 () ;
F_156 ( V_35 ) ;
F_164 () ;
}
static int T_12 F_165 ( void )
{
int V_51 ;
V_51 = F_166 ( & V_262 ) ;
if ( V_51 < 0 )
goto V_263;
V_51 = F_167 ( & V_264 , V_265 ) ;
if ( V_51 < 0 ) {
F_168 ( L_11 , V_266 ) ;
goto V_267;
}
V_51 = F_167 ( & V_268 , V_269 ) ;
if ( V_51 < 0 ) {
F_168 ( L_12 , V_266 ) ;
goto V_270;
}
V_51 = F_169 ( & V_55 ) ;
if ( V_51 < 0 )
goto V_271;
return 0 ;
V_271:
F_170 ( & V_268 , V_269 ) ;
V_270:
F_170 ( & V_264 , V_265 ) ;
V_267:
F_171 ( & V_262 ) ;
V_263:
return V_51 ;
}
static void T_13 F_172 ( void )
{
F_173 ( & V_55 ) ;
if ( F_170 ( & V_264 , V_265 ) )
F_174 ( L_13 , V_266 ) ;
if ( F_170 ( & V_268 , V_269 ) )
F_174 ( L_14 , V_266 ) ;
F_171 ( & V_262 ) ;
}
