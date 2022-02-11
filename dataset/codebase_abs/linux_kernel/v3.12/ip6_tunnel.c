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
V_20 -> V_31 = F_27 ( V_8 ) ;
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
struct V_31 * V_31 = V_20 -> V_31 ;
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
struct V_31 * V_31 = V_20 -> V_31 ;
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
V_63 -> V_153 = V_63 -> V_154 ;
F_53 ( V_63 ) ;
V_63 -> V_149 = F_87 ( V_149 ) ;
memset ( V_63 -> V_155 , 0 , sizeof( struct V_85 ) ) ;
F_88 ( V_63 , V_20 -> V_8 , V_20 -> V_31 ) ;
V_51 = F_85 ( V_20 , V_66 , V_63 ) ;
if ( F_89 ( V_51 ) ) {
if ( V_156 )
F_90 ( L_6 ,
& V_66 -> V_100 ,
F_72 ( V_66 ) ) ;
if ( V_51 > 1 ) {
++ V_20 -> V_8 -> V_17 . V_157 ;
++ V_20 -> V_8 -> V_17 . V_158 ;
F_47 () ;
goto V_150;
}
}
V_12 = F_91 ( V_20 -> V_8 -> V_12 ) ;
V_12 -> V_13 ++ ;
V_12 -> V_14 += V_63 -> V_97 ;
F_92 ( V_63 ) ;
F_47 () ;
return 0 ;
}
F_47 () ;
return 1 ;
V_150:
F_65 ( V_63 ) ;
return 0 ;
}
static int F_93 ( struct V_62 * V_63 )
{
return F_84 ( V_63 , V_159 , V_118 ,
F_71 ) ;
}
static int F_94 ( struct V_62 * V_63 )
{
return F_84 ( V_63 , V_160 , V_132 ,
F_75 ) ;
}
static void F_95 ( struct V_161 * V_86 , T_4 V_108 )
{
memset ( V_86 , 0 , sizeof( struct V_161 ) ) ;
V_86 -> V_162 [ 2 ] = V_82 ;
V_86 -> V_162 [ 3 ] = 1 ;
V_86 -> V_162 [ 4 ] = V_108 ;
V_86 -> V_162 [ 5 ] = V_163 ;
V_86 -> V_162 [ 6 ] = 1 ;
V_86 -> V_24 . V_164 = (struct V_71 * ) V_86 -> V_162 ;
V_86 -> V_24 . V_165 = 8 ;
}
static inline bool
F_96 ( const struct V_19 * V_20 , const struct V_65 * V_72 )
{
return F_14 ( & V_20 -> V_37 . V_39 , & V_72 -> V_100 ) ;
}
int F_97 ( struct V_19 * V_20 )
{
struct V_43 * V_44 = & V_20 -> V_37 ;
int V_147 = 0 ;
struct V_31 * V_31 = V_20 -> V_31 ;
if ( V_44 -> V_40 & V_145 ) {
struct V_7 * V_148 = NULL ;
F_44 () ;
if ( V_44 -> V_144 )
V_148 = F_80 ( V_31 , V_44 -> V_144 ) ;
if ( F_89 ( ! F_83 ( V_31 , & V_44 -> V_38 , V_148 , 0 ) ) )
F_98 ( L_7 ,
V_44 -> V_53 ) ;
else if ( ! F_81 ( & V_44 -> V_39 ) &&
F_89 ( F_83 ( V_31 , & V_44 -> V_39 , NULL , 0 ) ) )
F_98 ( L_8 ,
V_44 -> V_53 ) ;
else
V_147 = 1 ;
F_47 () ;
}
return V_147 ;
}
static int F_99 ( struct V_62 * V_63 ,
struct V_7 * V_8 ,
T_4 V_133 ,
struct V_166 * V_167 ,
int V_108 ,
T_6 * V_168 )
{
struct V_19 * V_20 = F_26 ( V_8 ) ;
struct V_31 * V_31 = V_20 -> V_31 ;
struct V_6 * V_17 = & V_20 -> V_8 -> V_17 ;
struct V_65 * V_66 = F_68 ( V_63 ) ;
struct V_161 V_86 ;
struct V_18 * V_21 = NULL , * V_169 = NULL ;
struct V_7 * V_170 ;
int V_103 ;
unsigned int V_171 = sizeof( struct V_65 ) ;
T_5 V_101 ;
int V_51 = - 1 ;
if ( ! V_167 -> V_172 )
V_21 = F_7 ( V_20 ) ;
if ( ! V_21 ) {
V_169 = F_100 ( V_31 , NULL , V_167 ) ;
if ( V_169 -> error )
goto V_173;
V_169 = F_101 ( V_31 , V_169 , F_102 ( V_167 ) , NULL , 0 ) ;
if ( F_57 ( V_169 ) ) {
V_51 = F_103 ( V_169 ) ;
V_169 = NULL ;
goto V_173;
}
V_21 = V_169 ;
}
V_170 = V_21 -> V_8 ;
if ( V_170 == V_8 ) {
V_17 -> V_174 ++ ;
F_45 ( L_9 ,
V_20 -> V_37 . V_53 ) ;
goto V_175;
}
V_103 = F_62 ( V_21 ) - sizeof ( * V_66 ) ;
if ( V_108 >= 0 ) {
V_171 += 8 ;
V_103 -= 8 ;
}
if ( V_103 < V_110 )
V_103 = V_110 ;
if ( F_61 ( V_63 ) )
F_61 ( V_63 ) -> V_24 -> V_130 ( F_61 ( V_63 ) , NULL , V_63 , V_103 ) ;
if ( V_63 -> V_97 > V_103 ) {
* V_168 = V_103 ;
V_51 = - V_176 ;
goto V_175;
}
F_104 ( V_63 , ! F_105 ( V_20 -> V_31 , F_27 ( V_8 ) ) ) ;
V_171 += F_106 ( V_170 ) ;
if ( F_107 ( V_63 ) < V_171 || F_108 ( V_63 ) ||
( F_109 ( V_63 ) && ! F_110 ( V_63 , 0 ) ) ) {
struct V_62 * V_177 ;
if ( ! ( V_177 = F_111 ( V_63 , V_171 ) ) )
goto V_175;
if ( V_63 -> V_178 )
F_112 ( V_177 , V_63 -> V_178 ) ;
F_113 ( V_63 ) ;
V_63 = V_177 ;
}
if ( V_167 -> V_172 ) {
F_59 ( V_63 , V_21 ) ;
V_169 = NULL ;
} else {
F_114 ( V_63 , V_21 ) ;
}
V_63 -> V_179 = V_63 -> V_154 ;
V_101 = V_167 -> V_180 ;
if ( V_108 >= 0 ) {
F_95 ( & V_86 , V_108 ) ;
F_115 ( V_63 , & V_86 . V_24 , & V_101 , NULL ) ;
}
if ( F_82 ( ! V_63 -> V_181 ) ) {
F_116 ( V_63 ) ;
V_63 -> V_181 = 1 ;
}
F_117 ( V_63 , sizeof( struct V_65 ) ) ;
F_53 ( V_63 ) ;
V_66 = F_68 ( V_63 ) ;
F_118 ( V_66 , F_119 ( 0 , V_133 ) , V_167 -> V_182 ) ;
V_66 -> V_183 = V_20 -> V_37 . V_183 ;
V_66 -> V_67 = V_101 ;
V_66 -> V_100 = V_167 -> V_100 ;
V_66 -> V_99 = V_167 -> V_99 ;
F_120 ( V_63 , V_8 ) ;
if ( V_169 )
F_10 ( V_20 , V_169 ) ;
return 0 ;
V_173:
V_17 -> V_184 ++ ;
F_121 ( V_63 ) ;
V_175:
F_8 ( V_169 ) ;
return V_51 ;
}
static inline int
F_122 ( struct V_62 * V_63 , struct V_7 * V_8 )
{
struct V_19 * V_20 = F_26 ( V_8 ) ;
const struct V_113 * V_185 = F_54 ( V_63 ) ;
int V_108 = - 1 ;
struct V_166 V_167 ;
T_4 V_133 ;
T_6 V_103 ;
int V_51 ;
if ( ( V_20 -> V_37 . V_101 != V_118 && V_20 -> V_37 . V_101 != 0 ) ||
! F_97 ( V_20 ) )
return - 1 ;
if ( ! ( V_20 -> V_37 . V_40 & V_186 ) )
V_108 = V_20 -> V_37 . V_108 ;
memcpy ( & V_167 , & V_20 -> V_187 . V_188 . V_189 , sizeof ( V_167 ) ) ;
V_167 . V_180 = V_118 ;
V_133 = F_123 ( V_185 ) ;
if ( V_20 -> V_37 . V_40 & V_190 )
V_167 . V_182 |= F_64 ( ( T_6 ) V_185 -> V_126 << V_191 )
& V_192 ;
if ( V_20 -> V_37 . V_40 & V_193 )
V_167 . V_172 = V_63 -> V_194 ;
V_51 = F_99 ( V_63 , V_8 , V_133 , & V_167 , V_108 , & V_103 ) ;
if ( V_51 != 0 ) {
if ( V_51 == - V_176 )
F_63 ( V_63 , V_119 , V_121 ,
F_64 ( V_103 ) ) ;
return - 1 ;
}
return 0 ;
}
static inline int
F_124 ( struct V_62 * V_63 , struct V_7 * V_8 )
{
struct V_19 * V_20 = F_26 ( V_8 ) ;
struct V_65 * V_66 = F_68 ( V_63 ) ;
int V_108 = - 1 ;
T_3 V_90 ;
struct V_166 V_167 ;
T_4 V_133 ;
T_6 V_103 ;
int V_51 ;
if ( ( V_20 -> V_37 . V_101 != V_132 && V_20 -> V_37 . V_101 != 0 ) ||
! F_97 ( V_20 ) || F_96 ( V_20 , V_66 ) )
return - 1 ;
V_90 = F_39 ( V_63 , F_125 ( V_63 ) ) ;
if ( V_90 > 0 ) {
struct V_80 * V_81 ;
V_81 = (struct V_80 * ) & F_125 ( V_63 ) [ V_90 ] ;
if ( V_81 -> V_108 == 0 ) {
F_69 ( V_63 , V_106 ,
V_107 , V_90 + 2 ) ;
return - 1 ;
}
V_108 = V_81 -> V_108 - 1 ;
} else if ( ! ( V_20 -> V_37 . V_40 & V_186 ) )
V_108 = V_20 -> V_37 . V_108 ;
memcpy ( & V_167 , & V_20 -> V_187 . V_188 . V_189 , sizeof ( V_167 ) ) ;
V_167 . V_180 = V_132 ;
V_133 = F_72 ( V_66 ) ;
if ( V_20 -> V_37 . V_40 & V_190 )
V_167 . V_182 |= ( * ( T_7 * ) V_66 & V_192 ) ;
if ( V_20 -> V_37 . V_40 & V_195 )
V_167 . V_182 |= ( * ( T_7 * ) V_66 & V_196 ) ;
if ( V_20 -> V_37 . V_40 & V_193 )
V_167 . V_172 = V_63 -> V_194 ;
V_51 = F_99 ( V_63 , V_8 , V_133 , & V_167 , V_108 , & V_103 ) ;
if ( V_51 != 0 ) {
if ( V_51 == - V_176 )
F_69 ( V_63 , V_109 , 0 , V_103 ) ;
return - 1 ;
}
return 0 ;
}
static T_8
F_126 ( struct V_62 * V_63 , struct V_7 * V_8 )
{
struct V_19 * V_20 = F_26 ( V_8 ) ;
struct V_6 * V_17 = & V_20 -> V_8 -> V_17 ;
int V_147 ;
switch ( V_63 -> V_149 ) {
case F_87 ( V_159 ) :
V_147 = F_122 ( V_63 , V_8 ) ;
break;
case F_87 ( V_160 ) :
V_147 = F_124 ( V_63 , V_8 ) ;
break;
default:
goto V_197;
}
if ( V_147 < 0 )
goto V_197;
return V_198 ;
V_197:
V_17 -> V_199 ++ ;
V_17 -> V_200 ++ ;
F_65 ( V_63 ) ;
return V_198 ;
}
static void F_127 ( struct V_19 * V_20 )
{
struct V_7 * V_8 = V_20 -> V_8 ;
struct V_43 * V_44 = & V_20 -> V_37 ;
struct V_166 * V_167 = & V_20 -> V_187 . V_188 . V_189 ;
memcpy ( V_8 -> V_201 , & V_44 -> V_38 , sizeof( struct V_1 ) ) ;
memcpy ( V_8 -> V_202 , & V_44 -> V_39 , sizeof( struct V_1 ) ) ;
V_167 -> V_100 = V_44 -> V_38 ;
V_167 -> V_99 = V_44 -> V_39 ;
V_167 -> V_203 = V_44 -> V_144 ;
V_167 -> V_182 = 0 ;
if ( ! ( V_44 -> V_40 & V_190 ) )
V_167 -> V_182 |= V_192 & V_44 -> V_204 ;
if ( ! ( V_44 -> V_40 & V_195 ) )
V_167 -> V_182 |= V_196 & V_44 -> V_204 ;
V_44 -> V_40 &= ~ ( V_145 | V_146 | V_139 ) ;
V_44 -> V_40 |= F_77 ( V_20 , & V_44 -> V_38 , & V_44 -> V_39 ) ;
if ( V_44 -> V_40 & V_145 && V_44 -> V_40 & V_146 )
V_8 -> V_40 |= V_205 ;
else
V_8 -> V_40 &= ~ V_205 ;
V_8 -> V_206 = V_44 -> V_144 ;
if ( V_44 -> V_40 & V_145 ) {
int V_207 = ( F_78 ( & V_44 -> V_39 ) &
( V_141 | V_143 ) ) ;
struct V_27 * V_28 = F_67 ( V_20 -> V_31 ,
& V_44 -> V_39 , & V_44 -> V_38 ,
V_44 -> V_144 , V_207 ) ;
if ( V_28 == NULL )
return;
if ( V_28 -> V_21 . V_8 ) {
V_8 -> V_208 = V_28 -> V_21 . V_8 -> V_208 +
sizeof ( struct V_65 ) ;
V_8 -> V_103 = V_28 -> V_21 . V_8 -> V_103 - sizeof ( struct V_65 ) ;
if ( ! ( V_20 -> V_37 . V_40 & V_186 ) )
V_8 -> V_103 -= 8 ;
if ( V_8 -> V_103 < V_110 )
V_8 -> V_103 = V_110 ;
}
F_70 ( V_28 ) ;
}
}
static int
F_128 ( struct V_19 * V_20 , const struct V_43 * V_44 )
{
V_20 -> V_37 . V_38 = V_44 -> V_38 ;
V_20 -> V_37 . V_39 = V_44 -> V_39 ;
V_20 -> V_37 . V_40 = V_44 -> V_40 ;
V_20 -> V_37 . V_183 = V_44 -> V_183 ;
V_20 -> V_37 . V_108 = V_44 -> V_108 ;
V_20 -> V_37 . V_204 = V_44 -> V_204 ;
V_20 -> V_37 . V_144 = V_44 -> V_144 ;
V_20 -> V_37 . V_101 = V_44 -> V_101 ;
F_9 ( V_20 ) ;
F_127 ( V_20 ) ;
return 0 ;
}
static int F_129 ( struct V_19 * V_20 , struct V_43 * V_44 )
{
struct V_31 * V_31 = V_20 -> V_31 ;
struct V_34 * V_35 = F_12 ( V_31 , V_36 ) ;
int V_51 ;
F_21 ( V_35 , V_20 ) ;
F_130 () ;
V_51 = F_128 ( V_20 , V_44 ) ;
F_18 ( V_35 , V_20 ) ;
F_131 ( V_20 -> V_8 ) ;
return V_51 ;
}
static void
F_132 ( struct V_43 * V_44 , const struct V_209 * V_188 )
{
V_44 -> V_38 = V_188 -> V_38 ;
V_44 -> V_39 = V_188 -> V_39 ;
V_44 -> V_40 = V_188 -> V_40 ;
V_44 -> V_183 = V_188 -> V_183 ;
V_44 -> V_108 = V_188 -> V_108 ;
V_44 -> V_204 = V_188 -> V_204 ;
V_44 -> V_144 = V_188 -> V_144 ;
V_44 -> V_101 = V_188 -> V_101 ;
memcpy ( V_44 -> V_53 , V_188 -> V_53 , sizeof( V_188 -> V_53 ) ) ;
}
static void
F_133 ( struct V_209 * V_188 , const struct V_43 * V_44 )
{
V_188 -> V_38 = V_44 -> V_38 ;
V_188 -> V_39 = V_44 -> V_39 ;
V_188 -> V_40 = V_44 -> V_40 ;
V_188 -> V_183 = V_44 -> V_183 ;
V_188 -> V_108 = V_44 -> V_108 ;
V_188 -> V_204 = V_44 -> V_204 ;
V_188 -> V_144 = V_44 -> V_144 ;
V_188 -> V_101 = V_44 -> V_101 ;
memcpy ( V_188 -> V_53 , V_44 -> V_53 , sizeof( V_188 -> V_53 ) ) ;
}
static int
F_134 ( struct V_7 * V_8 , struct V_210 * V_211 , int V_212 )
{
int V_51 = 0 ;
struct V_209 V_44 ;
struct V_43 V_213 ;
struct V_19 * V_20 = NULL ;
struct V_31 * V_31 = F_27 ( V_8 ) ;
struct V_34 * V_35 = F_12 ( V_31 , V_36 ) ;
switch ( V_212 ) {
case V_214 :
if ( V_8 == V_35 -> V_61 ) {
if ( F_135 ( & V_44 , V_211 -> V_215 . V_216 , sizeof ( V_44 ) ) ) {
V_51 = - V_217 ;
break;
}
F_132 ( & V_213 , & V_44 ) ;
V_20 = F_35 ( V_31 , & V_213 , 0 ) ;
} else {
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
}
if ( V_20 == NULL )
V_20 = F_26 ( V_8 ) ;
F_133 ( & V_44 , & V_20 -> V_37 ) ;
if ( F_136 ( V_211 -> V_215 . V_216 , & V_44 , sizeof ( V_44 ) ) ) {
V_51 = - V_217 ;
}
break;
case V_218 :
case V_219 :
V_51 = - V_220 ;
if ( ! F_137 ( V_31 -> V_221 , V_222 ) )
break;
V_51 = - V_217 ;
if ( F_135 ( & V_44 , V_211 -> V_215 . V_216 , sizeof ( V_44 ) ) )
break;
V_51 = - V_223 ;
if ( V_44 . V_101 != V_132 && V_44 . V_101 != V_118 &&
V_44 . V_101 != 0 )
break;
F_132 ( & V_213 , & V_44 ) ;
V_20 = F_35 ( V_31 , & V_213 , V_212 == V_218 ) ;
if ( V_8 != V_35 -> V_61 && V_212 == V_219 ) {
if ( V_20 != NULL ) {
if ( V_20 -> V_8 != V_8 ) {
V_51 = - V_224 ;
break;
}
} else
V_20 = F_26 ( V_8 ) ;
V_51 = F_129 ( V_20 , & V_213 ) ;
}
if ( V_20 ) {
V_51 = 0 ;
F_133 ( & V_44 , & V_20 -> V_37 ) ;
if ( F_136 ( V_211 -> V_215 . V_216 , & V_44 , sizeof( V_44 ) ) )
V_51 = - V_217 ;
} else
V_51 = ( V_212 == V_218 ? - V_225 : - V_98 ) ;
break;
case V_226 :
V_51 = - V_220 ;
if ( ! F_137 ( V_31 -> V_221 , V_222 ) )
break;
if ( V_8 == V_35 -> V_61 ) {
V_51 = - V_217 ;
if ( F_135 ( & V_44 , V_211 -> V_215 . V_216 , sizeof ( V_44 ) ) )
break;
V_51 = - V_98 ;
F_132 ( & V_213 , & V_44 ) ;
V_20 = F_35 ( V_31 , & V_213 , 0 ) ;
if ( V_20 == NULL )
break;
V_51 = - V_220 ;
if ( V_20 -> V_8 == V_35 -> V_61 )
break;
V_8 = V_20 -> V_8 ;
}
V_51 = 0 ;
F_138 ( V_8 ) ;
break;
default:
V_51 = - V_223 ;
}
return V_51 ;
}
static int
F_139 ( struct V_7 * V_8 , int V_227 )
{
struct V_19 * V_228 = F_26 ( V_8 ) ;
if ( V_228 -> V_37 . V_101 == V_118 ) {
if ( V_227 < 68 )
return - V_223 ;
} else {
if ( V_227 < V_110 )
return - V_223 ;
}
if ( V_227 > 0xFFF8 - V_8 -> V_208 )
return - V_223 ;
V_8 -> V_103 = V_227 ;
return 0 ;
}
static void V_57 ( struct V_7 * V_8 )
{
struct V_19 * V_20 ;
V_8 -> V_229 = & V_230 ;
V_8 -> V_231 = F_22 ;
V_8 -> type = V_232 ;
V_8 -> V_208 = V_233 + sizeof ( struct V_65 ) ;
V_8 -> V_103 = V_234 - sizeof ( struct V_65 ) ;
V_20 = F_26 ( V_8 ) ;
if ( ! ( V_20 -> V_37 . V_40 & V_186 ) )
V_8 -> V_103 -= 8 ;
V_8 -> V_40 |= V_235 ;
V_8 -> V_236 = sizeof( struct V_1 ) ;
V_8 -> V_237 &= ~ V_238 ;
V_8 -> V_239 = V_240 ;
F_140 ( V_8 -> V_241 ) ;
}
static inline int
F_141 ( struct V_7 * V_8 )
{
struct V_19 * V_20 = F_26 ( V_8 ) ;
V_20 -> V_8 = V_8 ;
V_20 -> V_31 = F_27 ( V_8 ) ;
V_8 -> V_12 = F_142 ( struct V_9 ) ;
if ( ! V_8 -> V_12 )
return - V_242 ;
return 0 ;
}
static int F_28 ( struct V_7 * V_8 )
{
struct V_19 * V_20 = F_26 ( V_8 ) ;
int V_51 = F_141 ( V_8 ) ;
if ( V_51 )
return V_51 ;
F_127 ( V_20 ) ;
return 0 ;
}
static int T_9 F_143 ( struct V_7 * V_8 )
{
struct V_19 * V_20 = F_26 ( V_8 ) ;
struct V_31 * V_31 = F_27 ( V_8 ) ;
struct V_34 * V_35 = F_12 ( V_31 , V_36 ) ;
int V_51 = F_141 ( V_8 ) ;
if ( V_51 )
return V_51 ;
V_20 -> V_37 . V_101 = V_132 ;
F_30 ( V_8 ) ;
F_127 ( V_20 ) ;
F_19 ( V_35 -> V_42 [ 0 ] , V_20 ) ;
return 0 ;
}
static int F_144 ( struct V_243 * V_244 [] , struct V_243 * V_73 [] )
{
T_5 V_101 ;
if ( ! V_73 )
return 0 ;
V_101 = F_145 ( V_73 [ V_245 ] ) ;
if ( V_101 != V_132 &&
V_101 != V_118 &&
V_101 != 0 )
return - V_223 ;
return 0 ;
}
static void F_146 ( struct V_243 * V_73 [] ,
struct V_43 * V_37 )
{
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
if ( ! V_73 )
return;
if ( V_73 [ V_246 ] )
V_37 -> V_144 = F_147 ( V_73 [ V_246 ] ) ;
if ( V_73 [ V_247 ] )
F_148 ( & V_37 -> V_38 , V_73 [ V_247 ] ,
sizeof( struct V_1 ) ) ;
if ( V_73 [ V_248 ] )
F_148 ( & V_37 -> V_39 , V_73 [ V_248 ] ,
sizeof( struct V_1 ) ) ;
if ( V_73 [ V_249 ] )
V_37 -> V_183 = F_145 ( V_73 [ V_249 ] ) ;
if ( V_73 [ V_250 ] )
V_37 -> V_108 = F_145 ( V_73 [ V_250 ] ) ;
if ( V_73 [ V_251 ] )
V_37 -> V_204 = F_149 ( V_73 [ V_251 ] ) ;
if ( V_73 [ V_252 ] )
V_37 -> V_40 = F_147 ( V_73 [ V_252 ] ) ;
if ( V_73 [ V_245 ] )
V_37 -> V_101 = F_145 ( V_73 [ V_245 ] ) ;
}
static int F_150 ( struct V_31 * V_253 , struct V_7 * V_8 ,
struct V_243 * V_244 [] , struct V_243 * V_73 [] )
{
struct V_31 * V_31 = F_27 ( V_8 ) ;
struct V_19 * V_254 ;
V_254 = F_26 ( V_8 ) ;
F_146 ( V_73 , & V_254 -> V_37 ) ;
if ( F_35 ( V_31 , & V_254 -> V_37 , 0 ) )
return - V_224 ;
return F_25 ( V_8 ) ;
}
static int F_151 ( struct V_7 * V_8 , struct V_243 * V_244 [] ,
struct V_243 * V_73 [] )
{
struct V_19 * V_20 = F_26 ( V_8 ) ;
struct V_43 V_44 ;
struct V_31 * V_31 = V_20 -> V_31 ;
struct V_34 * V_35 = F_12 ( V_31 , V_36 ) ;
if ( V_8 == V_35 -> V_61 )
return - V_223 ;
F_146 ( V_73 , & V_44 ) ;
V_20 = F_35 ( V_31 , & V_44 , 0 ) ;
if ( V_20 ) {
if ( V_20 -> V_8 != V_8 )
return - V_224 ;
} else
V_20 = F_26 ( V_8 ) ;
return F_129 ( V_20 , & V_44 ) ;
}
static T_10 F_152 ( const struct V_7 * V_8 )
{
return
F_153 ( 4 ) +
F_153 ( sizeof( struct V_1 ) ) +
F_153 ( sizeof( struct V_1 ) ) +
F_153 ( 1 ) +
F_153 ( 1 ) +
F_153 ( 4 ) +
F_153 ( 4 ) +
F_153 ( 1 ) +
0 ;
}
static int F_154 ( struct V_62 * V_63 , const struct V_7 * V_8 )
{
struct V_19 * V_255 = F_26 ( V_8 ) ;
struct V_43 * V_256 = & V_255 -> V_37 ;
if ( F_155 ( V_63 , V_246 , V_256 -> V_144 ) ||
F_156 ( V_63 , V_247 , sizeof( struct V_1 ) ,
& V_256 -> V_38 ) ||
F_156 ( V_63 , V_248 , sizeof( struct V_1 ) ,
& V_256 -> V_39 ) ||
F_157 ( V_63 , V_249 , V_256 -> V_183 ) ||
F_157 ( V_63 , V_250 , V_256 -> V_108 ) ||
F_158 ( V_63 , V_251 , V_256 -> V_204 ) ||
F_155 ( V_63 , V_252 , V_256 -> V_40 ) ||
F_157 ( V_63 , V_245 , V_256 -> V_101 ) )
goto V_257;
return 0 ;
V_257:
return - V_176 ;
}
static void T_11 F_159 ( struct V_34 * V_35 )
{
struct V_31 * V_31 = F_27 ( V_35 -> V_61 ) ;
struct V_7 * V_8 , * V_258 ;
int V_45 ;
struct V_19 * V_20 ;
F_160 ( V_259 ) ;
F_161 (net, dev, aux)
if ( V_8 -> V_54 == & V_55 )
F_162 ( V_8 , & V_259 ) ;
for ( V_45 = 0 ; V_45 < V_260 ; V_45 ++ ) {
V_20 = F_20 ( V_35 -> V_261 [ V_45 ] ) ;
while ( V_20 != NULL ) {
if ( ! F_105 ( F_27 ( V_20 -> V_8 ) , V_31 ) )
F_162 ( V_20 -> V_8 , & V_259 ) ;
V_20 = F_20 ( V_20 -> V_49 ) ;
}
}
F_163 ( & V_259 ) ;
}
static int T_9 F_164 ( struct V_31 * V_31 )
{
struct V_34 * V_35 = F_12 ( V_31 , V_36 ) ;
struct V_19 * V_20 = NULL ;
int V_51 ;
V_35 -> V_47 [ 0 ] = V_35 -> V_42 ;
V_35 -> V_47 [ 1 ] = V_35 -> V_261 ;
V_51 = - V_242 ;
V_35 -> V_61 = F_33 ( sizeof( struct V_19 ) , L_10 ,
V_57 ) ;
if ( ! V_35 -> V_61 )
goto V_262;
F_34 ( V_35 -> V_61 , V_31 ) ;
V_35 -> V_61 -> V_54 = & V_55 ;
V_35 -> V_61 -> V_263 |= V_264 ;
V_51 = F_143 ( V_35 -> V_61 ) ;
if ( V_51 < 0 )
goto V_265;
V_51 = F_165 ( V_35 -> V_61 ) ;
if ( V_51 < 0 )
goto V_265;
V_20 = F_26 ( V_35 -> V_61 ) ;
strcpy ( V_20 -> V_37 . V_53 , V_35 -> V_61 -> V_53 ) ;
return 0 ;
V_265:
F_22 ( V_35 -> V_61 ) ;
V_262:
return V_51 ;
}
static void T_11 F_166 ( struct V_31 * V_31 )
{
struct V_34 * V_35 = F_12 ( V_31 , V_36 ) ;
F_167 () ;
F_159 ( V_35 ) ;
F_168 () ;
}
static int T_12 F_169 ( void )
{
int V_51 ;
V_51 = F_170 ( & V_266 ) ;
if ( V_51 < 0 )
goto V_267;
V_51 = F_171 ( & V_268 , V_269 ) ;
if ( V_51 < 0 ) {
F_172 ( L_11 , V_270 ) ;
goto V_271;
}
V_51 = F_171 ( & V_272 , V_273 ) ;
if ( V_51 < 0 ) {
F_172 ( L_12 , V_270 ) ;
goto V_274;
}
V_51 = F_173 ( & V_55 ) ;
if ( V_51 < 0 )
goto V_275;
return 0 ;
V_275:
F_174 ( & V_272 , V_273 ) ;
V_274:
F_174 ( & V_268 , V_269 ) ;
V_271:
F_175 ( & V_266 ) ;
V_267:
return V_51 ;
}
static void T_13 F_176 ( void )
{
F_177 ( & V_55 ) ;
if ( F_174 ( & V_268 , V_269 ) )
F_178 ( L_13 , V_270 ) ;
if ( F_174 ( & V_272 , V_273 ) )
F_178 ( L_14 , V_270 ) ;
F_175 ( & V_266 ) ;
}
