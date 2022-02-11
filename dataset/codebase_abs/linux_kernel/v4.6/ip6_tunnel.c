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
( V_25 -> V_8 -> V_33 & V_34 ) )
return V_25 ;
}
V_4 = F_1 ( V_23 , & V_29 ) ;
F_11 (ip6n->tnls_r_l[hash]) {
if ( F_12 ( V_23 , & V_25 -> V_30 . V_32 ) &&
( V_25 -> V_8 -> V_33 & V_34 ) )
return V_25 ;
}
V_25 = F_13 ( V_27 -> V_35 [ 0 ] ) ;
if ( V_25 && ( V_25 -> V_8 -> V_33 & V_34 ) )
return V_25 ;
return NULL ;
}
static struct V_21 T_2 * *
F_14 ( struct V_26 * V_27 , const struct V_36 * V_37 )
{
const struct V_1 * V_23 = & V_37 -> V_32 ;
const struct V_1 * V_24 = & V_37 -> V_31 ;
unsigned int V_38 = 0 ;
int V_39 = 0 ;
if ( ! F_15 ( V_23 ) || ! F_15 ( V_24 ) ) {
V_39 = 1 ;
V_38 = F_1 ( V_23 , V_24 ) ;
}
return & V_27 -> V_40 [ V_39 ] [ V_38 ] ;
}
static void
F_16 ( struct V_26 * V_27 , struct V_21 * V_25 )
{
struct V_21 T_2 * * V_41 = F_14 ( V_27 , & V_25 -> V_30 ) ;
F_17 ( V_25 -> V_42 , F_18 ( * V_41 ) ) ;
F_17 ( * V_41 , V_25 ) ;
}
static void
F_19 ( struct V_26 * V_27 , struct V_21 * V_25 )
{
struct V_21 T_2 * * V_41 ;
struct V_21 * V_43 ;
for ( V_41 = F_14 ( V_27 , & V_25 -> V_30 ) ;
( V_43 = F_18 ( * V_41 ) ) != NULL ;
V_41 = & V_43 -> V_42 ) {
if ( V_25 == V_43 ) {
F_17 ( * V_41 , V_25 -> V_42 ) ;
break;
}
}
}
static void F_20 ( struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
F_22 ( & V_25 -> V_44 ) ;
F_23 ( V_8 -> V_14 ) ;
F_24 ( V_8 ) ;
}
static int F_25 ( struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
struct V_22 * V_22 = F_26 ( V_8 ) ;
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
int V_45 ;
V_25 = F_21 ( V_8 ) ;
V_8 -> V_46 = & V_47 ;
V_45 = F_27 ( V_8 ) ;
if ( V_45 < 0 )
goto V_48;
strcpy ( V_25 -> V_30 . V_49 , V_8 -> V_49 ) ;
F_28 ( V_8 ) ;
F_16 ( V_27 , V_25 ) ;
return 0 ;
V_48:
return V_45 ;
}
static struct V_21 * F_29 ( struct V_22 * V_22 , struct V_36 * V_37 )
{
struct V_7 * V_8 ;
struct V_21 * V_25 ;
char V_49 [ V_50 ] ;
int V_45 = - V_51 ;
if ( V_37 -> V_49 [ 0 ] )
F_30 ( V_49 , V_37 -> V_49 , V_50 ) ;
else
sprintf ( V_49 , L_1 ) ;
V_8 = F_31 ( sizeof( * V_25 ) , V_49 , V_52 ,
V_53 ) ;
if ( ! V_8 )
goto V_54;
F_32 ( V_8 , V_22 ) ;
V_25 = F_21 ( V_8 ) ;
V_25 -> V_30 = * V_37 ;
V_25 -> V_22 = F_26 ( V_8 ) ;
V_45 = F_25 ( V_8 ) ;
if ( V_45 < 0 )
goto V_55;
return V_25 ;
V_55:
F_20 ( V_8 ) ;
V_54:
return F_33 ( V_45 ) ;
}
static struct V_21 * F_34 ( struct V_22 * V_22 ,
struct V_36 * V_37 , int V_56 )
{
const struct V_1 * V_23 = & V_37 -> V_32 ;
const struct V_1 * V_24 = & V_37 -> V_31 ;
struct V_21 T_2 * * V_41 ;
struct V_21 * V_25 ;
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
for ( V_41 = F_14 ( V_27 , V_37 ) ;
( V_25 = F_18 ( * V_41 ) ) != NULL ;
V_41 = & V_25 -> V_42 ) {
if ( F_12 ( V_24 , & V_25 -> V_30 . V_31 ) &&
F_12 ( V_23 , & V_25 -> V_30 . V_32 ) ) {
if ( V_56 )
return F_33 ( - V_57 ) ;
return V_25 ;
}
}
if ( ! V_56 )
return F_33 ( - V_58 ) ;
return F_29 ( V_22 , V_37 ) ;
}
static void
F_35 ( struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
struct V_22 * V_22 = V_25 -> V_22 ;
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
if ( V_8 == V_27 -> V_59 )
F_36 ( V_27 -> V_35 [ 0 ] , NULL ) ;
else
F_19 ( V_27 , V_25 ) ;
F_37 ( & V_25 -> V_44 ) ;
F_38 ( V_8 ) ;
}
T_3 F_39 ( struct V_60 * V_61 , T_4 * V_62 )
{
const struct V_63 * V_64 = ( const struct V_63 * ) V_62 ;
T_4 V_65 = V_64 -> V_65 ;
T_3 V_66 = sizeof( * V_64 ) ;
while ( F_40 ( V_65 ) && V_65 != V_67 ) {
T_3 V_68 = 0 ;
struct V_69 * V_70 ;
if ( V_62 + V_66 + sizeof( * V_70 ) > V_61 -> V_71 &&
! F_41 ( V_61 , V_62 - V_61 -> V_71 + V_66 + sizeof ( * V_70 ) ) )
break;
V_70 = (struct V_69 * ) ( V_62 + V_66 ) ;
if ( V_65 == V_72 ) {
struct V_73 * V_73 = (struct V_73 * ) V_70 ;
if ( V_73 -> V_74 )
break;
V_68 = 8 ;
} else if ( V_65 == V_75 ) {
V_68 = ( V_70 -> V_76 + 2 ) << 2 ;
} else {
V_68 = F_42 ( V_70 ) ;
}
if ( V_65 == V_77 ) {
T_3 V_12 = V_66 + 2 ;
while ( 1 ) {
struct V_78 * V_79 ;
if ( V_12 + sizeof ( * V_79 ) > V_66 + V_68 )
break;
V_79 = (struct V_78 * ) & V_62 [ V_12 ] ;
if ( V_79 -> type == V_80 &&
V_79 -> V_81 == 1 )
return V_12 ;
if ( V_79 -> type )
V_12 += V_79 -> V_81 + 2 ;
else
V_12 ++ ;
}
}
V_65 = V_70 -> V_65 ;
V_66 += V_68 ;
}
return 0 ;
}
static int
F_43 ( struct V_60 * V_61 , T_4 V_82 , struct V_83 * V_84 ,
T_5 * type , T_5 * V_85 , int * V_86 , T_6 * V_87 , int V_88 )
{
const struct V_63 * V_64 = ( const struct V_63 * ) V_61 -> V_71 ;
struct V_21 * V_25 ;
int V_89 = 0 ;
T_5 V_90 = V_91 ;
T_5 V_92 = V_93 ;
T_5 V_94 ;
T_6 V_95 = 0 ;
T_3 V_96 ;
int V_45 = - V_97 ;
F_44 () ;
V_25 = F_9 ( F_26 ( V_61 -> V_8 ) , & V_64 -> V_98 , & V_64 -> V_99 ) ;
if ( ! V_25 )
goto V_48;
V_94 = F_45 ( V_25 -> V_30 . V_100 ) ;
if ( V_94 != V_82 && V_94 != 0 )
goto V_48;
V_45 = 0 ;
switch ( * type ) {
T_6 V_101 ;
struct V_78 * V_79 ;
T_6 V_102 ;
case V_91 :
F_46 ( L_2 ,
V_25 -> V_30 . V_49 ) ;
V_89 = 1 ;
break;
case V_103 :
if ( ( * V_85 ) == V_104 ) {
F_46 ( L_3 ,
V_25 -> V_30 . V_49 ) ;
V_89 = 1 ;
}
break;
case V_105 :
V_101 = 0 ;
if ( ( * V_85 ) == V_106 )
V_101 = F_39 ( V_61 , V_61 -> V_71 ) ;
if ( V_101 && V_101 == * V_87 - 2 ) {
V_79 = (struct V_78 * ) & V_61 -> V_71 [ V_101 ] ;
if ( V_79 -> V_107 == 0 ) {
F_46 ( L_4 ,
V_25 -> V_30 . V_49 ) ;
V_89 = 1 ;
}
} else {
F_46 ( L_5 ,
V_25 -> V_30 . V_49 ) ;
}
break;
case V_108 :
V_102 = * V_87 - V_88 ;
if ( V_102 < V_109 )
V_102 = V_109 ;
V_25 -> V_8 -> V_102 = V_102 ;
V_96 = sizeof( * V_64 ) + F_47 ( V_64 -> V_110 ) ;
if ( V_96 > V_102 ) {
V_90 = V_108 ;
V_92 = 0 ;
V_95 = V_102 ;
V_89 = 1 ;
}
break;
}
* type = V_90 ;
* V_85 = V_92 ;
* V_87 = V_95 ;
* V_86 = V_89 ;
V_48:
F_48 () ;
return V_45 ;
}
static int
F_49 ( struct V_60 * V_61 , struct V_83 * V_84 ,
T_5 type , T_5 V_85 , int V_88 , T_7 V_87 )
{
int V_89 = 0 ;
T_5 V_90 = type ;
T_5 V_92 = V_85 ;
T_6 V_95 = F_50 ( V_87 ) ;
int V_45 ;
struct V_60 * V_111 ;
const struct V_112 * V_113 ;
struct V_114 * V_115 ;
struct V_116 V_117 ;
V_45 = F_43 ( V_61 , V_118 , V_84 , & V_90 , & V_92 ,
& V_89 , & V_95 , V_88 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_89 == 0 )
return 0 ;
switch ( V_90 ) {
case V_91 :
if ( V_92 != V_93 )
return 0 ;
V_90 = V_119 ;
V_92 = V_120 ;
break;
case V_108 :
if ( V_92 != 0 )
return 0 ;
V_90 = V_119 ;
V_92 = V_121 ;
break;
case V_122 :
V_90 = V_123 ;
V_92 = V_124 ;
default:
return 0 ;
}
if ( ! F_41 ( V_61 , V_88 + sizeof( struct V_112 ) ) )
return 0 ;
V_111 = F_51 ( V_61 , V_125 ) ;
if ( ! V_111 )
return 0 ;
F_52 ( V_111 ) ;
F_53 ( V_111 , V_88 ) ;
F_54 ( V_111 ) ;
V_113 = F_55 ( V_111 ) ;
V_115 = F_56 ( F_26 ( V_61 -> V_8 ) , & V_117 , NULL ,
V_113 -> V_99 , 0 ,
0 , 0 ,
V_118 , F_57 ( V_113 -> V_126 ) , 0 ) ;
if ( F_58 ( V_115 ) )
goto V_48;
V_111 -> V_8 = V_115 -> V_127 . V_8 ;
if ( V_115 -> V_128 & V_129 ) {
F_59 ( V_115 ) ;
V_115 = NULL ;
V_115 = F_56 ( F_26 ( V_61 -> V_8 ) , & V_117 , NULL ,
V_113 -> V_98 , V_113 -> V_99 ,
0 , 0 ,
V_118 ,
F_57 ( V_113 -> V_126 ) , 0 ) ;
if ( F_58 ( V_115 ) ||
V_115 -> V_127 . V_8 -> type != V_130 ) {
if ( ! F_58 ( V_115 ) )
F_59 ( V_115 ) ;
goto V_48;
}
F_60 ( V_111 , & V_115 -> V_127 ) ;
} else {
F_59 ( V_115 ) ;
if ( F_61 ( V_111 , V_113 -> V_98 , V_113 -> V_99 , V_113 -> V_126 ,
V_111 -> V_8 ) ||
F_62 ( V_111 ) -> V_8 -> type != V_130 )
goto V_48;
}
if ( V_90 == V_119 && V_92 == V_121 ) {
if ( V_95 > F_63 ( F_62 ( V_111 ) ) )
goto V_48;
F_62 ( V_111 ) -> V_131 -> V_132 ( F_62 ( V_111 ) , NULL , V_111 , V_95 ) ;
}
if ( V_90 == V_123 )
F_62 ( V_111 ) -> V_131 -> V_133 ( F_62 ( V_111 ) , NULL , V_111 ) ;
F_64 ( V_111 , V_90 , V_92 , F_65 ( V_95 ) ) ;
V_48:
F_66 ( V_111 ) ;
return 0 ;
}
static int
F_67 ( struct V_60 * V_61 , struct V_83 * V_84 ,
T_5 type , T_5 V_85 , int V_88 , T_7 V_87 )
{
int V_89 = 0 ;
T_5 V_90 = type ;
T_5 V_92 = V_85 ;
T_6 V_95 = F_50 ( V_87 ) ;
int V_45 ;
V_45 = F_43 ( V_61 , V_134 , V_84 , & V_90 , & V_92 ,
& V_89 , & V_95 , V_88 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_89 && F_41 ( V_61 , V_88 + sizeof( struct V_63 ) ) ) {
struct V_135 * V_115 ;
struct V_60 * V_111 = F_51 ( V_61 , V_125 ) ;
if ( ! V_111 )
return 0 ;
F_52 ( V_111 ) ;
F_53 ( V_111 , V_88 ) ;
F_54 ( V_111 ) ;
V_115 = F_68 ( F_26 ( V_61 -> V_8 ) , & F_69 ( V_111 ) -> V_99 ,
NULL , 0 , 0 ) ;
if ( V_115 && V_115 -> V_127 . V_8 )
V_111 -> V_8 = V_115 -> V_127 . V_8 ;
F_70 ( V_111 , V_90 , V_92 , V_95 ) ;
F_71 ( V_115 ) ;
F_66 ( V_111 ) ;
}
return 0 ;
}
static int F_72 ( const struct V_21 * V_25 ,
const struct V_63 * V_64 ,
struct V_60 * V_61 )
{
T_4 V_136 = F_73 ( V_64 ) & ~ V_137 ;
if ( V_25 -> V_30 . V_33 & V_138 )
F_74 ( F_55 ( V_61 ) , V_137 , V_136 ) ;
return F_75 ( V_64 , V_61 ) ;
}
static int F_76 ( const struct V_21 * V_25 ,
const struct V_63 * V_64 ,
struct V_60 * V_61 )
{
if ( V_25 -> V_30 . V_33 & V_138 )
F_77 ( F_73 ( V_64 ) , F_69 ( V_61 ) ) ;
return F_75 ( V_64 , V_61 ) ;
}
T_6 F_78 ( struct V_21 * V_25 ,
const struct V_1 * V_31 ,
const struct V_1 * V_32 )
{
struct V_36 * V_37 = & V_25 -> V_30 ;
int V_139 = F_79 ( V_31 ) ;
int V_140 = F_79 ( V_32 ) ;
T_6 V_33 = 0 ;
if ( V_139 == V_141 || V_140 == V_141 ) {
V_33 = V_142 ;
} else if ( V_139 & ( V_143 | V_144 ) &&
V_140 & ( V_143 | V_144 ) &&
! ( ( V_139 | V_140 ) & V_145 ) &&
( ! ( ( V_139 | V_140 ) & V_146 ) || V_37 -> V_147 ) ) {
if ( V_139 & V_143 )
V_33 |= V_148 ;
if ( V_140 & V_143 )
V_33 |= V_149 ;
}
return V_33 ;
}
int F_80 ( struct V_21 * V_25 ,
const struct V_1 * V_31 ,
const struct V_1 * V_32 )
{
struct V_36 * V_37 = & V_25 -> V_30 ;
int V_150 = 0 ;
struct V_22 * V_22 = V_25 -> V_22 ;
if ( ( V_37 -> V_33 & V_149 ) ||
( ( V_37 -> V_33 & V_142 ) &&
( F_78 ( V_25 , V_31 , V_32 ) & V_149 ) ) ) {
struct V_7 * V_151 = NULL ;
if ( V_37 -> V_147 )
V_151 = F_81 ( V_22 , V_37 -> V_147 ) ;
if ( ( F_82 ( V_31 ) ||
F_83 ( F_84 ( V_22 , V_31 , V_151 , 0 ) ) ) &&
F_83 ( ! F_84 ( V_22 , V_32 , NULL , 0 ) ) )
V_150 = 1 ;
}
return V_150 ;
}
static int F_85 ( struct V_60 * V_61 , T_3 V_152 ,
T_4 V_82 ,
int (* F_86)( const struct V_21 * V_25 ,
const struct V_63 * V_64 ,
struct V_60 * V_61 ) )
{
struct V_21 * V_25 ;
const struct V_63 * V_64 = F_69 ( V_61 ) ;
T_5 V_94 ;
int V_45 ;
F_44 () ;
V_25 = F_9 ( F_26 ( V_61 -> V_8 ) , & V_64 -> V_99 , & V_64 -> V_98 ) ;
if ( V_25 ) {
struct V_9 * V_14 ;
V_94 = F_45 ( V_25 -> V_30 . V_100 ) ;
if ( V_94 != V_82 && V_94 != 0 ) {
F_48 () ;
goto V_153;
}
if ( ! F_87 ( NULL , V_154 , V_61 ) ) {
F_48 () ;
goto V_153;
}
if ( ! F_80 ( V_25 , & V_64 -> V_98 , & V_64 -> V_99 ) ) {
V_25 -> V_8 -> V_20 . V_155 ++ ;
F_48 () ;
goto V_153;
}
V_61 -> V_156 = V_61 -> V_157 ;
F_54 ( V_61 ) ;
V_61 -> V_152 = F_88 ( V_152 ) ;
memset ( V_61 -> V_158 , 0 , sizeof( struct V_83 ) ) ;
F_89 ( V_61 , V_25 -> V_8 , V_25 -> V_22 ) ;
V_45 = F_86 ( V_25 , V_64 , V_61 ) ;
if ( F_90 ( V_45 ) ) {
if ( V_159 )
F_91 ( L_6 ,
& V_64 -> V_99 ,
F_73 ( V_64 ) ) ;
if ( V_45 > 1 ) {
++ V_25 -> V_8 -> V_20 . V_160 ;
++ V_25 -> V_8 -> V_20 . V_161 ;
F_48 () ;
goto V_153;
}
}
V_14 = F_92 ( V_25 -> V_8 -> V_14 ) ;
F_93 ( & V_14 -> V_15 ) ;
V_14 -> V_16 ++ ;
V_14 -> V_17 += V_61 -> V_96 ;
F_94 ( & V_14 -> V_15 ) ;
F_95 ( V_61 ) ;
F_48 () ;
return 0 ;
}
F_48 () ;
return 1 ;
V_153:
F_66 ( V_61 ) ;
return 0 ;
}
static int F_96 ( struct V_60 * V_61 )
{
return F_85 ( V_61 , V_162 , V_118 ,
F_72 ) ;
}
static int F_97 ( struct V_60 * V_61 )
{
return F_85 ( V_61 , V_163 , V_134 ,
F_76 ) ;
}
static void F_98 ( struct V_164 * V_84 , T_4 V_107 )
{
memset ( V_84 , 0 , sizeof( struct V_164 ) ) ;
V_84 -> V_165 [ 2 ] = V_80 ;
V_84 -> V_165 [ 3 ] = 1 ;
V_84 -> V_165 [ 4 ] = V_107 ;
V_84 -> V_165 [ 5 ] = V_166 ;
V_84 -> V_165 [ 6 ] = 1 ;
V_84 -> V_131 . V_167 = (struct V_69 * ) V_84 -> V_165 ;
V_84 -> V_131 . V_168 = 8 ;
}
static inline bool
F_99 ( const struct V_21 * V_25 , const struct V_63 * V_70 )
{
return F_12 ( & V_25 -> V_30 . V_32 , & V_70 -> V_99 ) ;
}
int F_100 ( struct V_21 * V_25 ,
const struct V_1 * V_31 ,
const struct V_1 * V_32 )
{
struct V_36 * V_37 = & V_25 -> V_30 ;
int V_150 = 0 ;
struct V_22 * V_22 = V_25 -> V_22 ;
if ( ( V_37 -> V_33 & V_148 ) ||
( ( V_37 -> V_33 & V_142 ) &&
( F_78 ( V_25 , V_31 , V_32 ) & V_148 ) ) ) {
struct V_7 * V_151 = NULL ;
F_44 () ;
if ( V_37 -> V_147 )
V_151 = F_81 ( V_22 , V_37 -> V_147 ) ;
if ( F_90 ( ! F_84 ( V_22 , V_31 , V_151 , 0 ) ) )
F_101 ( L_7 ,
V_37 -> V_49 ) ;
else if ( ! F_82 ( V_32 ) &&
F_90 ( F_84 ( V_22 , V_32 , NULL , 0 ) ) )
F_101 ( L_8 ,
V_37 -> V_49 ) ;
else
V_150 = 1 ;
F_48 () ;
}
return V_150 ;
}
static int F_102 ( struct V_60 * V_61 ,
struct V_7 * V_8 ,
T_4 V_136 ,
struct V_169 * V_170 ,
int V_107 ,
T_6 * V_171 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
struct V_22 * V_22 = V_25 -> V_22 ;
struct V_6 * V_20 = & V_25 -> V_8 -> V_20 ;
struct V_63 * V_64 = F_69 ( V_61 ) ;
struct V_164 V_84 ;
struct V_172 * V_127 = NULL , * V_173 = NULL ;
struct V_7 * V_174 ;
int V_102 ;
unsigned int V_175 = sizeof( struct V_63 ) ;
T_5 V_100 ;
int V_45 = - 1 ;
if ( F_15 ( & V_25 -> V_30 . V_32 ) ) {
struct V_1 * V_176 ;
struct V_177 * V_178 ;
int V_179 ;
if ( ! F_62 ( V_61 ) )
goto V_180;
V_178 = F_103 ( F_62 ( V_61 ) ,
& F_69 ( V_61 ) -> V_98 ) ;
if ( ! V_178 )
goto V_180;
V_176 = (struct V_1 * ) & V_178 -> V_181 ;
V_179 = F_79 ( V_176 ) ;
if ( V_179 == V_141 )
V_176 = & F_69 ( V_61 ) -> V_98 ;
memcpy ( & V_170 -> V_98 , V_176 , sizeof( V_170 -> V_98 ) ) ;
F_104 ( V_178 ) ;
} else if ( ! V_170 -> V_182 )
V_127 = F_105 ( & V_25 -> V_44 ) ;
if ( ! F_100 ( V_25 , & V_170 -> V_99 , & V_170 -> V_98 ) )
goto V_180;
if ( ! V_127 ) {
V_127 = F_106 ( V_22 , NULL , V_170 ) ;
if ( V_127 -> error )
goto V_180;
V_127 = F_107 ( V_22 , V_127 , F_108 ( V_170 ) , NULL , 0 ) ;
if ( F_58 ( V_127 ) ) {
V_45 = F_109 ( V_127 ) ;
V_127 = NULL ;
goto V_180;
}
V_173 = V_127 ;
}
V_174 = V_127 -> V_8 ;
if ( V_174 == V_8 ) {
V_20 -> V_183 ++ ;
F_110 ( L_9 ,
V_25 -> V_30 . V_49 ) ;
goto V_184;
}
V_102 = F_63 ( V_127 ) - sizeof( * V_64 ) ;
if ( V_107 >= 0 ) {
V_175 += 8 ;
V_102 -= 8 ;
}
if ( V_102 < V_109 )
V_102 = V_109 ;
if ( F_62 ( V_61 ) )
F_62 ( V_61 ) -> V_131 -> V_132 ( F_62 ( V_61 ) , NULL , V_61 , V_102 ) ;
if ( V_61 -> V_96 > V_102 ) {
* V_171 = V_102 ;
V_45 = - V_185 ;
goto V_184;
}
F_111 ( V_61 , ! F_112 ( V_25 -> V_22 , F_26 ( V_8 ) ) ) ;
V_175 += F_113 ( V_174 ) ;
if ( F_114 ( V_61 ) < V_175 || F_115 ( V_61 ) ||
( F_116 ( V_61 ) && ! F_117 ( V_61 , 0 ) ) ) {
struct V_60 * V_186 ;
V_186 = F_118 ( V_61 , V_175 ) ;
if ( ! V_186 )
goto V_184;
if ( V_61 -> V_187 )
F_119 ( V_186 , V_61 -> V_187 ) ;
F_120 ( V_61 ) ;
V_61 = V_186 ;
}
if ( ! V_170 -> V_182 && V_173 )
F_121 ( & V_25 -> V_44 , V_173 , & V_170 -> V_99 ) ;
F_60 ( V_61 , V_127 ) ;
V_61 -> V_188 = V_61 -> V_157 ;
V_100 = V_170 -> V_189 ;
if ( V_107 >= 0 ) {
F_98 ( & V_84 , V_107 ) ;
F_122 ( V_61 , & V_84 . V_131 , & V_100 , NULL ) ;
}
if ( F_83 ( ! V_61 -> V_190 ) ) {
F_123 ( V_61 ) ;
V_61 -> V_190 = 1 ;
}
F_124 ( V_61 , sizeof( struct V_63 ) ) ;
F_54 ( V_61 ) ;
V_64 = F_69 ( V_61 ) ;
F_125 ( V_64 , F_126 ( 0 , V_136 ) ,
F_127 ( V_22 , V_61 , V_170 -> V_191 , true , V_170 ) ) ;
V_64 -> V_192 = V_25 -> V_30 . V_192 ;
V_64 -> V_65 = V_100 ;
V_64 -> V_99 = V_170 -> V_99 ;
V_64 -> V_98 = V_170 -> V_98 ;
F_128 ( NULL , V_61 , V_8 ) ;
return 0 ;
V_180:
V_20 -> V_193 ++ ;
F_129 ( V_61 ) ;
V_184:
F_130 ( V_127 ) ;
return V_45 ;
}
static inline int
F_131 ( struct V_60 * V_61 , struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
const struct V_112 * V_194 = F_55 ( V_61 ) ;
int V_107 = - 1 ;
struct V_169 V_170 ;
T_4 V_136 ;
T_6 V_102 ;
T_5 V_94 ;
int V_45 ;
memset ( & ( F_132 ( V_61 ) -> V_84 ) , 0 , sizeof( F_132 ( V_61 ) -> V_84 ) ) ;
V_94 = F_45 ( V_25 -> V_30 . V_100 ) ;
if ( V_94 != V_118 && V_94 != 0 )
return - 1 ;
if ( ! ( V_25 -> V_30 . V_33 & V_195 ) )
V_107 = V_25 -> V_30 . V_107 ;
memcpy ( & V_170 , & V_25 -> V_196 . V_197 . V_198 , sizeof( V_170 ) ) ;
V_170 . V_189 = V_118 ;
V_136 = F_133 ( V_194 ) ;
if ( V_25 -> V_30 . V_33 & V_199 )
V_170 . V_191 |= F_65 ( ( T_6 ) V_194 -> V_126 << V_200 )
& V_201 ;
if ( V_25 -> V_30 . V_33 & V_202 )
V_170 . V_182 = V_61 -> V_203 ;
V_45 = F_102 ( V_61 , V_8 , V_136 , & V_170 , V_107 , & V_102 ) ;
if ( V_45 != 0 ) {
if ( V_45 == - V_185 )
F_64 ( V_61 , V_119 , V_121 ,
F_65 ( V_102 ) ) ;
return - 1 ;
}
return 0 ;
}
static inline int
F_134 ( struct V_60 * V_61 , struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
struct V_63 * V_64 = F_69 ( V_61 ) ;
int V_107 = - 1 ;
T_3 V_88 ;
struct V_169 V_170 ;
T_4 V_136 ;
T_6 V_102 ;
T_5 V_94 ;
int V_45 ;
V_94 = F_45 ( V_25 -> V_30 . V_100 ) ;
if ( ( V_94 != V_134 && V_94 != 0 ) ||
F_99 ( V_25 , V_64 ) )
return - 1 ;
V_88 = F_39 ( V_61 , F_135 ( V_61 ) ) ;
if ( V_88 > 0 ) {
struct V_78 * V_79 ;
V_79 = (struct V_78 * ) & F_135 ( V_61 ) [ V_88 ] ;
if ( V_79 -> V_107 == 0 ) {
F_70 ( V_61 , V_105 ,
V_106 , V_88 + 2 ) ;
return - 1 ;
}
V_107 = V_79 -> V_107 - 1 ;
} else if ( ! ( V_25 -> V_30 . V_33 & V_195 ) )
V_107 = V_25 -> V_30 . V_107 ;
memcpy ( & V_170 , & V_25 -> V_196 . V_197 . V_198 , sizeof( V_170 ) ) ;
V_170 . V_189 = V_134 ;
V_136 = F_73 ( V_64 ) ;
if ( V_25 -> V_30 . V_33 & V_199 )
V_170 . V_191 |= ( * ( T_7 * ) V_64 & V_201 ) ;
if ( V_25 -> V_30 . V_33 & V_204 )
V_170 . V_191 |= F_136 ( V_64 ) ;
if ( V_25 -> V_30 . V_33 & V_202 )
V_170 . V_182 = V_61 -> V_203 ;
V_45 = F_102 ( V_61 , V_8 , V_136 , & V_170 , V_107 , & V_102 ) ;
if ( V_45 != 0 ) {
if ( V_45 == - V_185 )
F_70 ( V_61 , V_108 , 0 , V_102 ) ;
return - 1 ;
}
return 0 ;
}
static T_8
F_137 ( struct V_60 * V_61 , struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
struct V_6 * V_20 = & V_25 -> V_8 -> V_20 ;
int V_150 ;
switch ( V_61 -> V_152 ) {
case F_88 ( V_162 ) :
V_150 = F_131 ( V_61 , V_8 ) ;
break;
case F_88 ( V_163 ) :
V_150 = F_134 ( V_61 , V_8 ) ;
break;
default:
goto V_205;
}
if ( V_150 < 0 )
goto V_205;
return V_206 ;
V_205:
V_20 -> V_207 ++ ;
V_20 -> V_208 ++ ;
F_66 ( V_61 ) ;
return V_206 ;
}
static void F_138 ( struct V_21 * V_25 )
{
struct V_7 * V_8 = V_25 -> V_8 ;
struct V_36 * V_37 = & V_25 -> V_30 ;
struct V_169 * V_170 = & V_25 -> V_196 . V_197 . V_198 ;
memcpy ( V_8 -> V_209 , & V_37 -> V_31 , sizeof( struct V_1 ) ) ;
memcpy ( V_8 -> V_210 , & V_37 -> V_32 , sizeof( struct V_1 ) ) ;
V_170 -> V_99 = V_37 -> V_31 ;
V_170 -> V_98 = V_37 -> V_32 ;
V_170 -> V_211 = V_37 -> V_147 ;
V_170 -> V_191 = 0 ;
if ( ! ( V_37 -> V_33 & V_199 ) )
V_170 -> V_191 |= V_201 & V_37 -> V_212 ;
if ( ! ( V_37 -> V_33 & V_204 ) )
V_170 -> V_191 |= V_213 & V_37 -> V_212 ;
V_37 -> V_33 &= ~ ( V_148 | V_149 | V_142 ) ;
V_37 -> V_33 |= F_78 ( V_25 , & V_37 -> V_31 , & V_37 -> V_32 ) ;
if ( V_37 -> V_33 & V_148 && V_37 -> V_33 & V_149 )
V_8 -> V_33 |= V_214 ;
else
V_8 -> V_33 &= ~ V_214 ;
if ( V_37 -> V_33 & V_148 ) {
int V_215 = ( F_79 ( & V_37 -> V_32 ) &
( V_144 | V_146 ) ) ;
struct V_135 * V_115 = F_68 ( V_25 -> V_22 ,
& V_37 -> V_32 , & V_37 -> V_31 ,
V_37 -> V_147 , V_215 ) ;
if ( ! V_115 )
return;
if ( V_115 -> V_127 . V_8 ) {
V_8 -> V_216 = V_115 -> V_127 . V_8 -> V_216 +
sizeof( struct V_63 ) ;
V_8 -> V_102 = V_115 -> V_127 . V_8 -> V_102 - sizeof( struct V_63 ) ;
if ( ! ( V_25 -> V_30 . V_33 & V_195 ) )
V_8 -> V_102 -= 8 ;
if ( V_8 -> V_102 < V_109 )
V_8 -> V_102 = V_109 ;
}
F_71 ( V_115 ) ;
}
}
static int
F_139 ( struct V_21 * V_25 , const struct V_36 * V_37 )
{
V_25 -> V_30 . V_31 = V_37 -> V_31 ;
V_25 -> V_30 . V_32 = V_37 -> V_32 ;
V_25 -> V_30 . V_33 = V_37 -> V_33 ;
V_25 -> V_30 . V_192 = V_37 -> V_192 ;
V_25 -> V_30 . V_107 = V_37 -> V_107 ;
V_25 -> V_30 . V_212 = V_37 -> V_212 ;
V_25 -> V_30 . V_147 = V_37 -> V_147 ;
V_25 -> V_30 . V_100 = V_37 -> V_100 ;
F_37 ( & V_25 -> V_44 ) ;
F_138 ( V_25 ) ;
return 0 ;
}
static int F_140 ( struct V_21 * V_25 , struct V_36 * V_37 )
{
struct V_22 * V_22 = V_25 -> V_22 ;
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
int V_45 ;
F_19 ( V_27 , V_25 ) ;
F_141 () ;
V_45 = F_139 ( V_25 , V_37 ) ;
F_16 ( V_27 , V_25 ) ;
F_142 ( V_25 -> V_8 ) ;
return V_45 ;
}
static int F_143 ( struct V_21 * V_25 , struct V_36 * V_37 )
{
V_25 -> V_30 . V_100 = V_37 -> V_100 ;
F_142 ( V_25 -> V_8 ) ;
return 0 ;
}
static void
F_144 ( struct V_36 * V_37 , const struct V_217 * V_197 )
{
V_37 -> V_31 = V_197 -> V_31 ;
V_37 -> V_32 = V_197 -> V_32 ;
V_37 -> V_33 = V_197 -> V_33 ;
V_37 -> V_192 = V_197 -> V_192 ;
V_37 -> V_107 = V_197 -> V_107 ;
V_37 -> V_212 = V_197 -> V_212 ;
V_37 -> V_147 = V_197 -> V_147 ;
V_37 -> V_100 = V_197 -> V_100 ;
memcpy ( V_37 -> V_49 , V_197 -> V_49 , sizeof( V_197 -> V_49 ) ) ;
}
static void
F_145 ( struct V_217 * V_197 , const struct V_36 * V_37 )
{
V_197 -> V_31 = V_37 -> V_31 ;
V_197 -> V_32 = V_37 -> V_32 ;
V_197 -> V_33 = V_37 -> V_33 ;
V_197 -> V_192 = V_37 -> V_192 ;
V_197 -> V_107 = V_37 -> V_107 ;
V_197 -> V_212 = V_37 -> V_212 ;
V_197 -> V_147 = V_37 -> V_147 ;
V_197 -> V_100 = V_37 -> V_100 ;
memcpy ( V_197 -> V_49 , V_37 -> V_49 , sizeof( V_197 -> V_49 ) ) ;
}
static int
F_146 ( struct V_7 * V_8 , struct V_218 * V_219 , int V_220 )
{
int V_45 = 0 ;
struct V_217 V_37 ;
struct V_36 V_221 ;
struct V_21 * V_25 = F_21 ( V_8 ) ;
struct V_22 * V_22 = V_25 -> V_22 ;
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
switch ( V_220 ) {
case V_222 :
if ( V_8 == V_27 -> V_59 ) {
if ( F_147 ( & V_37 , V_219 -> V_223 . V_224 , sizeof( V_37 ) ) ) {
V_45 = - V_225 ;
break;
}
F_144 ( & V_221 , & V_37 ) ;
V_25 = F_34 ( V_22 , & V_221 , 0 ) ;
if ( F_58 ( V_25 ) )
V_25 = F_21 ( V_8 ) ;
} else {
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
}
F_145 ( & V_37 , & V_25 -> V_30 ) ;
if ( F_148 ( V_219 -> V_223 . V_224 , & V_37 , sizeof( V_37 ) ) ) {
V_45 = - V_225 ;
}
break;
case V_226 :
case V_227 :
V_45 = - V_228 ;
if ( ! F_149 ( V_22 -> V_229 , V_230 ) )
break;
V_45 = - V_225 ;
if ( F_147 ( & V_37 , V_219 -> V_223 . V_224 , sizeof( V_37 ) ) )
break;
V_45 = - V_231 ;
if ( V_37 . V_100 != V_134 && V_37 . V_100 != V_118 &&
V_37 . V_100 != 0 )
break;
F_144 ( & V_221 , & V_37 ) ;
V_25 = F_34 ( V_22 , & V_221 , V_220 == V_226 ) ;
if ( V_220 == V_227 ) {
if ( ! F_58 ( V_25 ) ) {
if ( V_25 -> V_8 != V_8 ) {
V_45 = - V_57 ;
break;
}
} else
V_25 = F_21 ( V_8 ) ;
if ( V_8 == V_27 -> V_59 )
V_45 = F_143 ( V_25 , & V_221 ) ;
else
V_45 = F_140 ( V_25 , & V_221 ) ;
}
if ( ! F_58 ( V_25 ) ) {
V_45 = 0 ;
F_145 ( & V_37 , & V_25 -> V_30 ) ;
if ( F_148 ( V_219 -> V_223 . V_224 , & V_37 , sizeof( V_37 ) ) )
V_45 = - V_225 ;
} else {
V_45 = F_109 ( V_25 ) ;
}
break;
case V_232 :
V_45 = - V_228 ;
if ( ! F_149 ( V_22 -> V_229 , V_230 ) )
break;
if ( V_8 == V_27 -> V_59 ) {
V_45 = - V_225 ;
if ( F_147 ( & V_37 , V_219 -> V_223 . V_224 , sizeof( V_37 ) ) )
break;
V_45 = - V_97 ;
F_144 ( & V_221 , & V_37 ) ;
V_25 = F_34 ( V_22 , & V_221 , 0 ) ;
if ( F_58 ( V_25 ) )
break;
V_45 = - V_228 ;
if ( V_25 -> V_8 == V_27 -> V_59 )
break;
V_8 = V_25 -> V_8 ;
}
V_45 = 0 ;
F_150 ( V_8 ) ;
break;
default:
V_45 = - V_231 ;
}
return V_45 ;
}
static int
F_151 ( struct V_7 * V_8 , int V_233 )
{
struct V_21 * V_234 = F_21 ( V_8 ) ;
if ( V_234 -> V_30 . V_100 == V_118 ) {
if ( V_233 < 68 )
return - V_231 ;
} else {
if ( V_233 < V_109 )
return - V_231 ;
}
if ( V_233 > 0xFFF8 - V_8 -> V_216 )
return - V_231 ;
V_8 -> V_102 = V_233 ;
return 0 ;
}
int F_152 ( const struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
return V_25 -> V_30 . V_147 ;
}
static void V_53 ( struct V_7 * V_8 )
{
struct V_21 * V_25 ;
V_8 -> V_235 = & V_236 ;
V_8 -> V_237 = F_20 ;
V_8 -> type = V_238 ;
V_8 -> V_216 = V_239 + sizeof( struct V_63 ) ;
V_8 -> V_102 = V_240 - sizeof( struct V_63 ) ;
V_25 = F_21 ( V_8 ) ;
if ( ! ( V_25 -> V_30 . V_33 & V_195 ) )
V_8 -> V_102 -= 8 ;
V_8 -> V_33 |= V_241 ;
V_8 -> V_242 = sizeof( struct V_1 ) ;
F_153 ( V_8 ) ;
V_8 -> V_243 = V_244 ;
F_154 ( V_8 -> V_245 ) ;
}
static inline int
F_155 ( struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
int V_150 ;
V_25 -> V_8 = V_8 ;
V_25 -> V_22 = F_26 ( V_8 ) ;
V_8 -> V_14 = F_156 ( struct V_9 ) ;
if ( ! V_8 -> V_14 )
return - V_51 ;
V_150 = F_157 ( & V_25 -> V_44 , V_246 ) ;
if ( V_150 ) {
F_23 ( V_8 -> V_14 ) ;
V_8 -> V_14 = NULL ;
return V_150 ;
}
return 0 ;
}
static int F_158 ( struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
int V_45 = F_155 ( V_8 ) ;
if ( V_45 )
return V_45 ;
F_138 ( V_25 ) ;
return 0 ;
}
static int T_9 F_159 ( struct V_7 * V_8 )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
struct V_22 * V_22 = F_26 ( V_8 ) ;
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
V_25 -> V_30 . V_100 = V_134 ;
F_28 ( V_8 ) ;
F_17 ( V_27 -> V_35 [ 0 ] , V_25 ) ;
return 0 ;
}
static int F_160 ( struct V_247 * V_248 [] , struct V_247 * V_71 [] )
{
T_5 V_100 ;
if ( ! V_71 || ! V_71 [ V_249 ] )
return 0 ;
V_100 = F_161 ( V_71 [ V_249 ] ) ;
if ( V_100 != V_134 &&
V_100 != V_118 &&
V_100 != 0 )
return - V_231 ;
return 0 ;
}
static void F_162 ( struct V_247 * V_71 [] ,
struct V_36 * V_30 )
{
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
if ( ! V_71 )
return;
if ( V_71 [ V_250 ] )
V_30 -> V_147 = F_163 ( V_71 [ V_250 ] ) ;
if ( V_71 [ V_251 ] )
V_30 -> V_31 = F_164 ( V_71 [ V_251 ] ) ;
if ( V_71 [ V_252 ] )
V_30 -> V_32 = F_164 ( V_71 [ V_252 ] ) ;
if ( V_71 [ V_253 ] )
V_30 -> V_192 = F_161 ( V_71 [ V_253 ] ) ;
if ( V_71 [ V_254 ] )
V_30 -> V_107 = F_161 ( V_71 [ V_254 ] ) ;
if ( V_71 [ V_255 ] )
V_30 -> V_212 = F_165 ( V_71 [ V_255 ] ) ;
if ( V_71 [ V_256 ] )
V_30 -> V_33 = F_163 ( V_71 [ V_256 ] ) ;
if ( V_71 [ V_249 ] )
V_30 -> V_100 = F_161 ( V_71 [ V_249 ] ) ;
}
static int F_166 ( struct V_22 * V_257 , struct V_7 * V_8 ,
struct V_247 * V_248 [] , struct V_247 * V_71 [] )
{
struct V_22 * V_22 = F_26 ( V_8 ) ;
struct V_21 * V_258 , * V_25 ;
V_258 = F_21 ( V_8 ) ;
F_162 ( V_71 , & V_258 -> V_30 ) ;
V_25 = F_34 ( V_22 , & V_258 -> V_30 , 0 ) ;
if ( ! F_58 ( V_25 ) )
return - V_57 ;
return F_25 ( V_8 ) ;
}
static int F_167 ( struct V_7 * V_8 , struct V_247 * V_248 [] ,
struct V_247 * V_71 [] )
{
struct V_21 * V_25 = F_21 ( V_8 ) ;
struct V_36 V_37 ;
struct V_22 * V_22 = V_25 -> V_22 ;
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
if ( V_8 == V_27 -> V_59 )
return - V_231 ;
F_162 ( V_71 , & V_37 ) ;
V_25 = F_34 ( V_22 , & V_37 , 0 ) ;
if ( ! F_58 ( V_25 ) ) {
if ( V_25 -> V_8 != V_8 )
return - V_57 ;
} else
V_25 = F_21 ( V_8 ) ;
return F_140 ( V_25 , & V_37 ) ;
}
static void F_168 ( struct V_7 * V_8 , struct V_259 * V_260 )
{
struct V_22 * V_22 = F_26 ( V_8 ) ;
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
if ( V_8 != V_27 -> V_59 )
F_169 ( V_8 , V_260 ) ;
}
static T_10 F_170 ( const struct V_7 * V_8 )
{
return
F_171 ( 4 ) +
F_171 ( sizeof( struct V_1 ) ) +
F_171 ( sizeof( struct V_1 ) ) +
F_171 ( 1 ) +
F_171 ( 1 ) +
F_171 ( 4 ) +
F_171 ( 4 ) +
F_171 ( 1 ) +
0 ;
}
static int F_172 ( struct V_60 * V_61 , const struct V_7 * V_8 )
{
struct V_21 * V_261 = F_21 ( V_8 ) ;
struct V_36 * V_262 = & V_261 -> V_30 ;
if ( F_173 ( V_61 , V_250 , V_262 -> V_147 ) ||
F_174 ( V_61 , V_251 , & V_262 -> V_31 ) ||
F_174 ( V_61 , V_252 , & V_262 -> V_32 ) ||
F_175 ( V_61 , V_253 , V_262 -> V_192 ) ||
F_175 ( V_61 , V_254 , V_262 -> V_107 ) ||
F_176 ( V_61 , V_255 , V_262 -> V_212 ) ||
F_173 ( V_61 , V_256 , V_262 -> V_33 ) ||
F_175 ( V_61 , V_249 , V_262 -> V_100 ) )
goto V_263;
return 0 ;
V_263:
return - V_185 ;
}
struct V_22 * F_177 ( const struct V_7 * V_8 )
{
struct V_21 * V_261 = F_21 ( V_8 ) ;
return V_261 -> V_22 ;
}
static void T_11 F_178 ( struct V_22 * V_22 )
{
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
struct V_7 * V_8 , * V_264 ;
int V_38 ;
struct V_21 * V_25 ;
F_179 ( V_265 ) ;
F_180 (net, dev, aux)
if ( V_8 -> V_46 == & V_47 )
F_169 ( V_8 , & V_265 ) ;
for ( V_38 = 0 ; V_38 < V_266 ; V_38 ++ ) {
V_25 = F_18 ( V_27 -> V_267 [ V_38 ] ) ;
while ( V_25 ) {
if ( ! F_112 ( F_26 ( V_25 -> V_8 ) , V_22 ) )
F_169 ( V_25 -> V_8 , & V_265 ) ;
V_25 = F_18 ( V_25 -> V_42 ) ;
}
}
F_181 ( & V_265 ) ;
}
static int T_9 F_182 ( struct V_22 * V_22 )
{
struct V_26 * V_27 = F_10 ( V_22 , V_28 ) ;
struct V_21 * V_25 = NULL ;
int V_45 ;
V_27 -> V_40 [ 0 ] = V_27 -> V_35 ;
V_27 -> V_40 [ 1 ] = V_27 -> V_267 ;
V_45 = - V_51 ;
V_27 -> V_59 = F_31 ( sizeof( struct V_21 ) , L_10 ,
V_52 , V_53 ) ;
if ( ! V_27 -> V_59 )
goto V_268;
F_32 ( V_27 -> V_59 , V_22 ) ;
V_27 -> V_59 -> V_46 = & V_47 ;
V_27 -> V_59 -> V_269 |= V_270 ;
V_45 = F_159 ( V_27 -> V_59 ) ;
if ( V_45 < 0 )
goto V_271;
V_45 = F_183 ( V_27 -> V_59 ) ;
if ( V_45 < 0 )
goto V_271;
V_25 = F_21 ( V_27 -> V_59 ) ;
strcpy ( V_25 -> V_30 . V_49 , V_27 -> V_59 -> V_49 ) ;
return 0 ;
V_271:
F_20 ( V_27 -> V_59 ) ;
V_268:
return V_45 ;
}
static void T_11 F_184 ( struct V_22 * V_22 )
{
F_185 () ;
F_178 ( V_22 ) ;
F_186 () ;
}
static int T_12 F_187 ( void )
{
int V_45 ;
V_45 = F_188 ( & V_272 ) ;
if ( V_45 < 0 )
goto V_273;
V_45 = F_189 ( & V_274 , V_275 ) ;
if ( V_45 < 0 ) {
F_190 ( L_11 , V_276 ) ;
goto V_277;
}
V_45 = F_189 ( & V_278 , V_279 ) ;
if ( V_45 < 0 ) {
F_190 ( L_12 , V_276 ) ;
goto V_280;
}
V_45 = F_191 ( & V_47 ) ;
if ( V_45 < 0 )
goto V_281;
return 0 ;
V_281:
F_192 ( & V_278 , V_279 ) ;
V_280:
F_192 ( & V_274 , V_275 ) ;
V_277:
F_193 ( & V_272 ) ;
V_273:
return V_45 ;
}
static void T_13 F_194 ( void )
{
F_195 ( & V_47 ) ;
if ( F_192 ( & V_274 , V_275 ) )
F_196 ( L_13 , V_276 ) ;
if ( F_192 ( & V_278 , V_279 ) )
F_196 ( L_14 , V_276 ) ;
F_193 ( & V_272 ) ;
}
