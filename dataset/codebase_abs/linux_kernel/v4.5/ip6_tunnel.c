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
static void F_9 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
F_10 ( & V_22 -> V_25 ) ;
F_11 ( F_12 (
V_22 -> V_24 ,
F_13 ( & V_22 -> V_25 . V_25 ) ) ) ;
if ( V_24 ) {
F_14 ( V_24 ) ;
V_22 -> V_26 = F_15 ( (struct V_27 * ) V_24 ) ;
} else {
V_22 -> V_26 = 0 ;
}
F_16 ( V_22 -> V_24 , V_24 ) ;
F_17 ( & V_22 -> V_25 ) ;
}
struct V_23 * F_18 ( struct V_28 * V_29 )
{
struct V_21 * V_22 ;
struct V_23 * V_24 ;
unsigned int V_30 ;
T_1 V_26 ;
V_22 = F_19 ( V_29 -> V_31 ) ;
F_20 () ;
do {
V_30 = F_21 ( & V_22 -> V_25 ) ;
V_24 = F_22 ( V_22 -> V_24 ) ;
V_26 = V_22 -> V_26 ;
} while ( F_23 ( & V_22 -> V_25 , V_30 ) );
if ( V_24 && ! F_24 ( & V_24 -> V_32 ) )
V_24 = NULL ;
F_25 () ;
if ( V_24 && V_24 -> V_33 && ! V_24 -> V_34 -> V_35 ( V_24 , V_26 ) ) {
F_9 ( V_22 , NULL ) ;
F_11 ( V_24 ) ;
V_24 = NULL ;
}
return V_24 ;
}
void F_26 ( struct V_28 * V_29 )
{
int V_12 ;
F_5 (i)
F_9 ( F_6 ( V_29 -> V_31 , V_12 ) , NULL ) ;
}
void F_27 ( struct V_28 * V_29 , struct V_23 * V_24 )
{
F_9 ( F_19 ( V_29 -> V_31 ) , V_24 ) ;
}
void F_28 ( struct V_28 * V_29 )
{
if ( ! V_29 -> V_31 )
return;
F_26 ( V_29 ) ;
F_29 ( V_29 -> V_31 ) ;
}
int F_30 ( struct V_28 * V_29 )
{
int V_12 ;
V_29 -> V_31 = F_31 ( struct V_21 ) ;
if ( ! V_29 -> V_31 )
return - V_36 ;
F_5 (i)
F_32 ( & F_6 ( V_29 -> V_31 , V_12 ) -> V_25 ) ;
return 0 ;
}
static struct V_28 *
F_33 ( struct V_37 * V_37 , const struct V_1 * V_38 , const struct V_1 * V_39 )
{
unsigned int V_4 = F_1 ( V_38 , V_39 ) ;
struct V_28 * V_29 ;
struct V_40 * V_41 = F_34 ( V_37 , V_42 ) ;
struct V_1 V_43 ;
F_35 (ip6n->tnls_r_l[hash]) {
if ( F_36 ( V_39 , & V_29 -> V_44 . V_45 ) &&
F_36 ( V_38 , & V_29 -> V_44 . V_46 ) &&
( V_29 -> V_8 -> V_47 & V_48 ) )
return V_29 ;
}
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_4 = F_1 ( & V_43 , V_39 ) ;
F_35 (ip6n->tnls_r_l[hash]) {
if ( F_36 ( V_39 , & V_29 -> V_44 . V_45 ) &&
( V_29 -> V_8 -> V_47 & V_48 ) )
return V_29 ;
}
V_4 = F_1 ( V_38 , & V_43 ) ;
F_35 (ip6n->tnls_r_l[hash]) {
if ( F_36 ( V_38 , & V_29 -> V_44 . V_46 ) &&
( V_29 -> V_8 -> V_47 & V_48 ) )
return V_29 ;
}
V_29 = F_22 ( V_41 -> V_49 [ 0 ] ) ;
if ( V_29 && ( V_29 -> V_8 -> V_47 & V_48 ) )
return V_29 ;
return NULL ;
}
static struct V_28 T_2 * *
F_37 ( struct V_40 * V_41 , const struct V_50 * V_51 )
{
const struct V_1 * V_38 = & V_51 -> V_46 ;
const struct V_1 * V_39 = & V_51 -> V_45 ;
unsigned int V_52 = 0 ;
int V_53 = 0 ;
if ( ! F_38 ( V_38 ) || ! F_38 ( V_39 ) ) {
V_53 = 1 ;
V_52 = F_1 ( V_38 , V_39 ) ;
}
return & V_41 -> V_54 [ V_53 ] [ V_52 ] ;
}
static void
F_39 ( struct V_40 * V_41 , struct V_28 * V_29 )
{
struct V_28 T_2 * * V_55 = F_37 ( V_41 , & V_29 -> V_44 ) ;
F_16 ( V_29 -> V_56 , F_40 ( * V_55 ) ) ;
F_16 ( * V_55 , V_29 ) ;
}
static void
F_41 ( struct V_40 * V_41 , struct V_28 * V_29 )
{
struct V_28 T_2 * * V_55 ;
struct V_28 * V_57 ;
for ( V_55 = F_37 ( V_41 , & V_29 -> V_44 ) ;
( V_57 = F_40 ( * V_55 ) ) != NULL ;
V_55 = & V_57 -> V_56 ) {
if ( V_29 == V_57 ) {
F_16 ( * V_55 , V_29 -> V_56 ) ;
break;
}
}
}
static void F_42 ( struct V_7 * V_8 )
{
struct V_28 * V_29 = F_43 ( V_8 ) ;
F_28 ( V_29 ) ;
F_29 ( V_8 -> V_14 ) ;
F_44 ( V_8 ) ;
}
static int F_45 ( struct V_7 * V_8 )
{
struct V_28 * V_29 = F_43 ( V_8 ) ;
struct V_37 * V_37 = F_46 ( V_8 ) ;
struct V_40 * V_41 = F_34 ( V_37 , V_42 ) ;
int V_58 ;
V_29 = F_43 ( V_8 ) ;
V_58 = F_47 ( V_8 ) ;
if ( V_58 < 0 )
goto V_59;
strcpy ( V_29 -> V_44 . V_60 , V_8 -> V_60 ) ;
V_8 -> V_61 = & V_62 ;
F_48 ( V_8 ) ;
F_39 ( V_41 , V_29 ) ;
return 0 ;
V_59:
return V_58 ;
}
static struct V_28 * F_49 ( struct V_37 * V_37 , struct V_50 * V_51 )
{
struct V_7 * V_8 ;
struct V_28 * V_29 ;
char V_60 [ V_63 ] ;
int V_58 = - V_36 ;
if ( V_51 -> V_60 [ 0 ] )
F_50 ( V_60 , V_51 -> V_60 , V_63 ) ;
else
sprintf ( V_60 , L_1 ) ;
V_8 = F_51 ( sizeof( * V_29 ) , V_60 , V_64 ,
V_65 ) ;
if ( ! V_8 )
goto V_66;
F_52 ( V_8 , V_37 ) ;
V_29 = F_43 ( V_8 ) ;
V_29 -> V_44 = * V_51 ;
V_29 -> V_37 = F_46 ( V_8 ) ;
V_58 = F_45 ( V_8 ) ;
if ( V_58 < 0 )
goto V_67;
return V_29 ;
V_67:
F_42 ( V_8 ) ;
V_66:
return F_53 ( V_58 ) ;
}
static struct V_28 * F_54 ( struct V_37 * V_37 ,
struct V_50 * V_51 , int V_68 )
{
const struct V_1 * V_38 = & V_51 -> V_46 ;
const struct V_1 * V_39 = & V_51 -> V_45 ;
struct V_28 T_2 * * V_55 ;
struct V_28 * V_29 ;
struct V_40 * V_41 = F_34 ( V_37 , V_42 ) ;
for ( V_55 = F_37 ( V_41 , V_51 ) ;
( V_29 = F_40 ( * V_55 ) ) != NULL ;
V_55 = & V_29 -> V_56 ) {
if ( F_36 ( V_39 , & V_29 -> V_44 . V_45 ) &&
F_36 ( V_38 , & V_29 -> V_44 . V_46 ) ) {
if ( V_68 )
return F_53 ( - V_69 ) ;
return V_29 ;
}
}
if ( ! V_68 )
return F_53 ( - V_70 ) ;
return F_49 ( V_37 , V_51 ) ;
}
static void
F_55 ( struct V_7 * V_8 )
{
struct V_28 * V_29 = F_43 ( V_8 ) ;
struct V_37 * V_37 = V_29 -> V_37 ;
struct V_40 * V_41 = F_34 ( V_37 , V_42 ) ;
if ( V_8 == V_41 -> V_71 )
F_56 ( V_41 -> V_49 [ 0 ] , NULL ) ;
else
F_41 ( V_41 , V_29 ) ;
F_26 ( V_29 ) ;
F_57 ( V_8 ) ;
}
T_3 F_58 ( struct V_72 * V_73 , T_4 * V_74 )
{
const struct V_75 * V_76 = ( const struct V_75 * ) V_74 ;
T_4 V_77 = V_76 -> V_77 ;
T_3 V_78 = sizeof( * V_76 ) ;
while ( F_59 ( V_77 ) && V_77 != V_79 ) {
T_3 V_80 = 0 ;
struct V_81 * V_82 ;
if ( V_74 + V_78 + sizeof( * V_82 ) > V_73 -> V_83 &&
! F_60 ( V_73 , V_74 - V_73 -> V_83 + V_78 + sizeof ( * V_82 ) ) )
break;
V_82 = (struct V_81 * ) ( V_74 + V_78 ) ;
if ( V_77 == V_84 ) {
struct V_85 * V_85 = (struct V_85 * ) V_82 ;
if ( V_85 -> V_86 )
break;
V_80 = 8 ;
} else if ( V_77 == V_87 ) {
V_80 = ( V_82 -> V_88 + 2 ) << 2 ;
} else {
V_80 = F_61 ( V_82 ) ;
}
if ( V_77 == V_89 ) {
T_3 V_12 = V_78 + 2 ;
while ( 1 ) {
struct V_90 * V_91 ;
if ( V_12 + sizeof ( * V_91 ) > V_78 + V_80 )
break;
V_91 = (struct V_90 * ) & V_74 [ V_12 ] ;
if ( V_91 -> type == V_92 &&
V_91 -> V_93 == 1 )
return V_12 ;
if ( V_91 -> type )
V_12 += V_91 -> V_93 + 2 ;
else
V_12 ++ ;
}
}
V_77 = V_82 -> V_77 ;
V_78 += V_80 ;
}
return 0 ;
}
static int
F_62 ( struct V_72 * V_73 , T_4 V_94 , struct V_95 * V_96 ,
T_5 * type , T_5 * V_97 , int * V_98 , T_6 * V_99 , int V_100 )
{
const struct V_75 * V_76 = ( const struct V_75 * ) V_73 -> V_83 ;
struct V_28 * V_29 ;
int V_101 = 0 ;
T_5 V_102 = V_103 ;
T_5 V_104 = V_105 ;
T_5 V_106 ;
T_6 V_107 = 0 ;
T_3 V_108 ;
int V_58 = - V_109 ;
F_20 () ;
V_29 = F_33 ( F_46 ( V_73 -> V_8 ) , & V_76 -> V_110 , & V_76 -> V_111 ) ;
if ( ! V_29 )
goto V_59;
V_106 = F_63 ( V_29 -> V_44 . V_112 ) ;
if ( V_106 != V_94 && V_106 != 0 )
goto V_59;
V_58 = 0 ;
switch ( * type ) {
T_6 V_113 ;
struct V_90 * V_91 ;
T_6 V_114 ;
case V_103 :
F_64 ( L_2 ,
V_29 -> V_44 . V_60 ) ;
V_101 = 1 ;
break;
case V_115 :
if ( ( * V_97 ) == V_116 ) {
F_64 ( L_3 ,
V_29 -> V_44 . V_60 ) ;
V_101 = 1 ;
}
break;
case V_117 :
V_113 = 0 ;
if ( ( * V_97 ) == V_118 )
V_113 = F_58 ( V_73 , V_73 -> V_83 ) ;
if ( V_113 && V_113 == * V_99 - 2 ) {
V_91 = (struct V_90 * ) & V_73 -> V_83 [ V_113 ] ;
if ( V_91 -> V_119 == 0 ) {
F_64 ( L_4 ,
V_29 -> V_44 . V_60 ) ;
V_101 = 1 ;
}
} else {
F_64 ( L_5 ,
V_29 -> V_44 . V_60 ) ;
}
break;
case V_120 :
V_114 = * V_99 - V_100 ;
if ( V_114 < V_121 )
V_114 = V_121 ;
V_29 -> V_8 -> V_114 = V_114 ;
V_108 = sizeof( * V_76 ) + F_65 ( V_76 -> V_122 ) ;
if ( V_108 > V_114 ) {
V_102 = V_120 ;
V_104 = 0 ;
V_107 = V_114 ;
V_101 = 1 ;
}
break;
}
* type = V_102 ;
* V_97 = V_104 ;
* V_99 = V_107 ;
* V_98 = V_101 ;
V_59:
F_25 () ;
return V_58 ;
}
static int
F_66 ( struct V_72 * V_73 , struct V_95 * V_96 ,
T_5 type , T_5 V_97 , int V_100 , T_7 V_99 )
{
int V_101 = 0 ;
T_5 V_102 = type ;
T_5 V_104 = V_97 ;
T_6 V_107 = F_67 ( V_99 ) ;
int V_58 ;
struct V_72 * V_123 ;
const struct V_124 * V_125 ;
struct V_126 * V_127 ;
struct V_128 V_129 ;
V_58 = F_62 ( V_73 , V_130 , V_96 , & V_102 , & V_104 ,
& V_101 , & V_107 , V_100 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_101 == 0 )
return 0 ;
switch ( V_102 ) {
case V_103 :
if ( V_104 != V_105 )
return 0 ;
V_102 = V_131 ;
V_104 = V_132 ;
break;
case V_120 :
if ( V_104 != 0 )
return 0 ;
V_102 = V_131 ;
V_104 = V_133 ;
break;
case V_134 :
V_102 = V_135 ;
V_104 = V_136 ;
default:
return 0 ;
}
if ( ! F_60 ( V_73 , V_100 + sizeof( struct V_124 ) ) )
return 0 ;
V_123 = F_68 ( V_73 , V_137 ) ;
if ( ! V_123 )
return 0 ;
F_69 ( V_123 ) ;
F_70 ( V_123 , V_100 ) ;
F_71 ( V_123 ) ;
V_125 = F_72 ( V_123 ) ;
V_127 = F_73 ( F_46 ( V_73 -> V_8 ) , & V_129 , NULL ,
V_125 -> V_111 , 0 ,
0 , 0 ,
V_130 , F_74 ( V_125 -> V_138 ) , 0 ) ;
if ( F_75 ( V_127 ) )
goto V_59;
V_123 -> V_8 = V_127 -> V_24 . V_8 ;
if ( V_127 -> V_139 & V_140 ) {
F_76 ( V_127 ) ;
V_127 = NULL ;
V_127 = F_73 ( F_46 ( V_73 -> V_8 ) , & V_129 , NULL ,
V_125 -> V_110 , V_125 -> V_111 ,
0 , 0 ,
V_130 ,
F_74 ( V_125 -> V_138 ) , 0 ) ;
if ( F_75 ( V_127 ) ||
V_127 -> V_24 . V_8 -> type != V_141 ) {
if ( ! F_75 ( V_127 ) )
F_76 ( V_127 ) ;
goto V_59;
}
F_77 ( V_123 , & V_127 -> V_24 ) ;
} else {
F_76 ( V_127 ) ;
if ( F_78 ( V_123 , V_125 -> V_110 , V_125 -> V_111 , V_125 -> V_138 ,
V_123 -> V_8 ) ||
F_79 ( V_123 ) -> V_8 -> type != V_141 )
goto V_59;
}
if ( V_102 == V_131 && V_104 == V_133 ) {
if ( V_107 > F_80 ( F_79 ( V_123 ) ) )
goto V_59;
F_79 ( V_123 ) -> V_34 -> V_142 ( F_79 ( V_123 ) , NULL , V_123 , V_107 ) ;
}
if ( V_102 == V_135 )
F_79 ( V_123 ) -> V_34 -> V_143 ( F_79 ( V_123 ) , NULL , V_123 ) ;
F_81 ( V_123 , V_102 , V_104 , F_82 ( V_107 ) ) ;
V_59:
F_83 ( V_123 ) ;
return 0 ;
}
static int
F_84 ( struct V_72 * V_73 , struct V_95 * V_96 ,
T_5 type , T_5 V_97 , int V_100 , T_7 V_99 )
{
int V_101 = 0 ;
T_5 V_102 = type ;
T_5 V_104 = V_97 ;
T_6 V_107 = F_67 ( V_99 ) ;
int V_58 ;
V_58 = F_62 ( V_73 , V_144 , V_96 , & V_102 , & V_104 ,
& V_101 , & V_107 , V_100 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_101 && F_60 ( V_73 , V_100 + sizeof( struct V_75 ) ) ) {
struct V_27 * V_127 ;
struct V_72 * V_123 = F_68 ( V_73 , V_137 ) ;
if ( ! V_123 )
return 0 ;
F_69 ( V_123 ) ;
F_70 ( V_123 , V_100 ) ;
F_71 ( V_123 ) ;
V_127 = F_85 ( F_46 ( V_73 -> V_8 ) , & F_86 ( V_123 ) -> V_111 ,
NULL , 0 , 0 ) ;
if ( V_127 && V_127 -> V_24 . V_8 )
V_123 -> V_8 = V_127 -> V_24 . V_8 ;
F_87 ( V_123 , V_102 , V_104 , V_107 ) ;
F_88 ( V_127 ) ;
F_83 ( V_123 ) ;
}
return 0 ;
}
static int F_89 ( const struct V_28 * V_29 ,
const struct V_75 * V_76 ,
struct V_72 * V_73 )
{
T_4 V_145 = F_90 ( V_76 ) & ~ V_146 ;
if ( V_29 -> V_44 . V_47 & V_147 )
F_91 ( F_72 ( V_73 ) , V_146 , V_145 ) ;
return F_92 ( V_76 , V_73 ) ;
}
static int F_93 ( const struct V_28 * V_29 ,
const struct V_75 * V_76 ,
struct V_72 * V_73 )
{
if ( V_29 -> V_44 . V_47 & V_147 )
F_94 ( F_90 ( V_76 ) , F_86 ( V_73 ) ) ;
return F_92 ( V_76 , V_73 ) ;
}
T_6 F_95 ( struct V_28 * V_29 ,
const struct V_1 * V_45 ,
const struct V_1 * V_46 )
{
struct V_50 * V_51 = & V_29 -> V_44 ;
int V_148 = F_96 ( V_45 ) ;
int V_149 = F_96 ( V_46 ) ;
T_6 V_47 = 0 ;
if ( V_148 == V_150 || V_149 == V_150 ) {
V_47 = V_151 ;
} else if ( V_148 & ( V_152 | V_153 ) &&
V_149 & ( V_152 | V_153 ) &&
! ( ( V_148 | V_149 ) & V_154 ) &&
( ! ( ( V_148 | V_149 ) & V_155 ) || V_51 -> V_156 ) ) {
if ( V_148 & V_152 )
V_47 |= V_157 ;
if ( V_149 & V_152 )
V_47 |= V_158 ;
}
return V_47 ;
}
int F_97 ( struct V_28 * V_29 ,
const struct V_1 * V_45 ,
const struct V_1 * V_46 )
{
struct V_50 * V_51 = & V_29 -> V_44 ;
int V_159 = 0 ;
struct V_37 * V_37 = V_29 -> V_37 ;
if ( ( V_51 -> V_47 & V_158 ) ||
( ( V_51 -> V_47 & V_151 ) &&
( F_95 ( V_29 , V_45 , V_46 ) & V_158 ) ) ) {
struct V_7 * V_160 = NULL ;
if ( V_51 -> V_156 )
V_160 = F_98 ( V_37 , V_51 -> V_156 ) ;
if ( ( F_99 ( V_45 ) ||
F_100 ( F_101 ( V_37 , V_45 , V_160 , 0 ) ) ) &&
F_100 ( ! F_101 ( V_37 , V_46 , NULL , 0 ) ) )
V_159 = 1 ;
}
return V_159 ;
}
static int F_102 ( struct V_72 * V_73 , T_3 V_161 ,
T_4 V_94 ,
int (* F_103)( const struct V_28 * V_29 ,
const struct V_75 * V_76 ,
struct V_72 * V_73 ) )
{
struct V_28 * V_29 ;
const struct V_75 * V_76 = F_86 ( V_73 ) ;
T_5 V_106 ;
int V_58 ;
F_20 () ;
V_29 = F_33 ( F_46 ( V_73 -> V_8 ) , & V_76 -> V_111 , & V_76 -> V_110 ) ;
if ( V_29 ) {
struct V_9 * V_14 ;
V_106 = F_63 ( V_29 -> V_44 . V_112 ) ;
if ( V_106 != V_94 && V_106 != 0 ) {
F_25 () ;
goto V_162;
}
if ( ! F_104 ( NULL , V_163 , V_73 ) ) {
F_25 () ;
goto V_162;
}
if ( ! F_97 ( V_29 , & V_76 -> V_110 , & V_76 -> V_111 ) ) {
V_29 -> V_8 -> V_20 . V_164 ++ ;
F_25 () ;
goto V_162;
}
V_73 -> V_165 = V_73 -> V_166 ;
F_71 ( V_73 ) ;
V_73 -> V_161 = F_105 ( V_161 ) ;
memset ( V_73 -> V_167 , 0 , sizeof( struct V_95 ) ) ;
F_106 ( V_73 , V_29 -> V_8 , V_29 -> V_37 ) ;
V_58 = F_103 ( V_29 , V_76 , V_73 ) ;
if ( F_107 ( V_58 ) ) {
if ( V_168 )
F_108 ( L_6 ,
& V_76 -> V_111 ,
F_90 ( V_76 ) ) ;
if ( V_58 > 1 ) {
++ V_29 -> V_8 -> V_20 . V_169 ;
++ V_29 -> V_8 -> V_20 . V_170 ;
F_25 () ;
goto V_162;
}
}
V_14 = F_109 ( V_29 -> V_8 -> V_14 ) ;
F_110 ( & V_14 -> V_15 ) ;
V_14 -> V_16 ++ ;
V_14 -> V_17 += V_73 -> V_108 ;
F_111 ( & V_14 -> V_15 ) ;
F_112 ( V_73 ) ;
F_25 () ;
return 0 ;
}
F_25 () ;
return 1 ;
V_162:
F_83 ( V_73 ) ;
return 0 ;
}
static int F_113 ( struct V_72 * V_73 )
{
return F_102 ( V_73 , V_171 , V_130 ,
F_89 ) ;
}
static int F_114 ( struct V_72 * V_73 )
{
return F_102 ( V_73 , V_172 , V_144 ,
F_93 ) ;
}
static void F_115 ( struct V_173 * V_96 , T_4 V_119 )
{
memset ( V_96 , 0 , sizeof( struct V_173 ) ) ;
V_96 -> V_174 [ 2 ] = V_92 ;
V_96 -> V_174 [ 3 ] = 1 ;
V_96 -> V_174 [ 4 ] = V_119 ;
V_96 -> V_174 [ 5 ] = V_175 ;
V_96 -> V_174 [ 6 ] = 1 ;
V_96 -> V_34 . V_176 = (struct V_81 * ) V_96 -> V_174 ;
V_96 -> V_34 . V_177 = 8 ;
}
static inline bool
F_116 ( const struct V_28 * V_29 , const struct V_75 * V_82 )
{
return F_36 ( & V_29 -> V_44 . V_46 , & V_82 -> V_111 ) ;
}
int F_117 ( struct V_28 * V_29 ,
const struct V_1 * V_45 ,
const struct V_1 * V_46 )
{
struct V_50 * V_51 = & V_29 -> V_44 ;
int V_159 = 0 ;
struct V_37 * V_37 = V_29 -> V_37 ;
if ( ( V_51 -> V_47 & V_157 ) ||
( ( V_51 -> V_47 & V_151 ) &&
( F_95 ( V_29 , V_45 , V_46 ) & V_157 ) ) ) {
struct V_7 * V_160 = NULL ;
F_20 () ;
if ( V_51 -> V_156 )
V_160 = F_98 ( V_37 , V_51 -> V_156 ) ;
if ( F_107 ( ! F_101 ( V_37 , V_45 , V_160 , 0 ) ) )
F_118 ( L_7 ,
V_51 -> V_60 ) ;
else if ( ! F_99 ( V_46 ) &&
F_107 ( F_101 ( V_37 , V_46 , NULL , 0 ) ) )
F_118 ( L_8 ,
V_51 -> V_60 ) ;
else
V_159 = 1 ;
F_25 () ;
}
return V_159 ;
}
static int F_119 ( struct V_72 * V_73 ,
struct V_7 * V_8 ,
T_4 V_145 ,
struct V_178 * V_179 ,
int V_119 ,
T_6 * V_180 )
{
struct V_28 * V_29 = F_43 ( V_8 ) ;
struct V_37 * V_37 = V_29 -> V_37 ;
struct V_6 * V_20 = & V_29 -> V_8 -> V_20 ;
struct V_75 * V_76 = F_86 ( V_73 ) ;
struct V_173 V_96 ;
struct V_23 * V_24 = NULL , * V_181 = NULL ;
struct V_7 * V_182 ;
int V_114 ;
unsigned int V_183 = sizeof( struct V_75 ) ;
T_5 V_112 ;
int V_58 = - 1 ;
if ( F_38 ( & V_29 -> V_44 . V_46 ) ) {
struct V_1 * V_184 ;
struct V_185 * V_186 ;
int V_187 ;
if ( ! F_79 ( V_73 ) )
goto V_188;
V_186 = F_120 ( F_79 ( V_73 ) ,
& F_86 ( V_73 ) -> V_110 ) ;
if ( ! V_186 )
goto V_188;
V_184 = (struct V_1 * ) & V_186 -> V_189 ;
V_187 = F_96 ( V_184 ) ;
if ( V_187 == V_150 )
V_184 = & F_86 ( V_73 ) -> V_110 ;
memcpy ( & V_179 -> V_110 , V_184 , sizeof( V_179 -> V_110 ) ) ;
F_121 ( V_186 ) ;
} else if ( ! V_179 -> V_190 )
V_24 = F_18 ( V_29 ) ;
if ( ! F_117 ( V_29 , & V_179 -> V_111 , & V_179 -> V_110 ) )
goto V_188;
if ( ! V_24 ) {
V_24 = F_122 ( V_37 , NULL , V_179 ) ;
if ( V_24 -> error )
goto V_188;
V_24 = F_123 ( V_37 , V_24 , F_124 ( V_179 ) , NULL , 0 ) ;
if ( F_75 ( V_24 ) ) {
V_58 = F_125 ( V_24 ) ;
V_24 = NULL ;
goto V_188;
}
V_181 = V_24 ;
}
V_182 = V_24 -> V_8 ;
if ( V_182 == V_8 ) {
V_20 -> V_191 ++ ;
F_126 ( L_9 ,
V_29 -> V_44 . V_60 ) ;
goto V_192;
}
V_114 = F_80 ( V_24 ) - sizeof( * V_76 ) ;
if ( V_119 >= 0 ) {
V_183 += 8 ;
V_114 -= 8 ;
}
if ( V_114 < V_121 )
V_114 = V_121 ;
if ( F_79 ( V_73 ) )
F_79 ( V_73 ) -> V_34 -> V_142 ( F_79 ( V_73 ) , NULL , V_73 , V_114 ) ;
if ( V_73 -> V_108 > V_114 ) {
* V_180 = V_114 ;
V_58 = - V_193 ;
goto V_192;
}
F_127 ( V_73 , ! F_128 ( V_29 -> V_37 , F_46 ( V_8 ) ) ) ;
V_183 += F_129 ( V_182 ) ;
if ( F_130 ( V_73 ) < V_183 || F_131 ( V_73 ) ||
( F_132 ( V_73 ) && ! F_133 ( V_73 , 0 ) ) ) {
struct V_72 * V_194 ;
V_194 = F_134 ( V_73 , V_183 ) ;
if ( ! V_194 )
goto V_192;
if ( V_73 -> V_195 )
F_135 ( V_194 , V_73 -> V_195 ) ;
F_136 ( V_73 ) ;
V_73 = V_194 ;
}
if ( ! V_179 -> V_190 && V_181 )
F_27 ( V_29 , V_181 ) ;
F_77 ( V_73 , V_24 ) ;
V_73 -> V_196 = V_73 -> V_166 ;
V_112 = V_179 -> V_197 ;
if ( V_119 >= 0 ) {
F_115 ( & V_96 , V_119 ) ;
F_137 ( V_73 , & V_96 . V_34 , & V_112 , NULL ) ;
}
if ( F_100 ( ! V_73 -> V_198 ) ) {
F_138 ( V_73 ) ;
V_73 -> V_198 = 1 ;
}
F_139 ( V_73 , sizeof( struct V_75 ) ) ;
F_71 ( V_73 ) ;
V_76 = F_86 ( V_73 ) ;
F_140 ( V_76 , F_141 ( 0 , V_145 ) ,
F_142 ( V_37 , V_73 , V_179 -> V_199 , true , V_179 ) ) ;
V_76 -> V_200 = V_29 -> V_44 . V_200 ;
V_76 -> V_77 = V_112 ;
V_76 -> V_111 = V_179 -> V_111 ;
V_76 -> V_110 = V_179 -> V_110 ;
F_143 ( NULL , V_73 , V_8 ) ;
return 0 ;
V_188:
V_20 -> V_201 ++ ;
F_144 ( V_73 ) ;
V_192:
F_11 ( V_24 ) ;
return V_58 ;
}
static inline int
F_145 ( struct V_72 * V_73 , struct V_7 * V_8 )
{
struct V_28 * V_29 = F_43 ( V_8 ) ;
const struct V_124 * V_202 = F_72 ( V_73 ) ;
int V_119 = - 1 ;
struct V_178 V_179 ;
T_4 V_145 ;
T_6 V_114 ;
T_5 V_106 ;
int V_58 ;
memset ( & ( F_146 ( V_73 ) -> V_96 ) , 0 , sizeof( F_146 ( V_73 ) -> V_96 ) ) ;
V_106 = F_63 ( V_29 -> V_44 . V_112 ) ;
if ( V_106 != V_130 && V_106 != 0 )
return - 1 ;
if ( ! ( V_29 -> V_44 . V_47 & V_203 ) )
V_119 = V_29 -> V_44 . V_119 ;
memcpy ( & V_179 , & V_29 -> V_204 . V_205 . V_206 , sizeof( V_179 ) ) ;
V_179 . V_197 = V_130 ;
V_145 = F_147 ( V_202 ) ;
if ( V_29 -> V_44 . V_47 & V_207 )
V_179 . V_199 |= F_82 ( ( T_6 ) V_202 -> V_138 << V_208 )
& V_209 ;
if ( V_29 -> V_44 . V_47 & V_210 )
V_179 . V_190 = V_73 -> V_211 ;
V_58 = F_119 ( V_73 , V_8 , V_145 , & V_179 , V_119 , & V_114 ) ;
if ( V_58 != 0 ) {
if ( V_58 == - V_193 )
F_81 ( V_73 , V_131 , V_133 ,
F_82 ( V_114 ) ) ;
return - 1 ;
}
return 0 ;
}
static inline int
F_148 ( struct V_72 * V_73 , struct V_7 * V_8 )
{
struct V_28 * V_29 = F_43 ( V_8 ) ;
struct V_75 * V_76 = F_86 ( V_73 ) ;
int V_119 = - 1 ;
T_3 V_100 ;
struct V_178 V_179 ;
T_4 V_145 ;
T_6 V_114 ;
T_5 V_106 ;
int V_58 ;
V_106 = F_63 ( V_29 -> V_44 . V_112 ) ;
if ( ( V_106 != V_144 && V_106 != 0 ) ||
F_116 ( V_29 , V_76 ) )
return - 1 ;
V_100 = F_58 ( V_73 , F_149 ( V_73 ) ) ;
if ( V_100 > 0 ) {
struct V_90 * V_91 ;
V_91 = (struct V_90 * ) & F_149 ( V_73 ) [ V_100 ] ;
if ( V_91 -> V_119 == 0 ) {
F_87 ( V_73 , V_117 ,
V_118 , V_100 + 2 ) ;
return - 1 ;
}
V_119 = V_91 -> V_119 - 1 ;
} else if ( ! ( V_29 -> V_44 . V_47 & V_203 ) )
V_119 = V_29 -> V_44 . V_119 ;
memcpy ( & V_179 , & V_29 -> V_204 . V_205 . V_206 , sizeof( V_179 ) ) ;
V_179 . V_197 = V_144 ;
V_145 = F_90 ( V_76 ) ;
if ( V_29 -> V_44 . V_47 & V_207 )
V_179 . V_199 |= ( * ( T_7 * ) V_76 & V_209 ) ;
if ( V_29 -> V_44 . V_47 & V_212 )
V_179 . V_199 |= F_150 ( V_76 ) ;
if ( V_29 -> V_44 . V_47 & V_210 )
V_179 . V_190 = V_73 -> V_211 ;
V_58 = F_119 ( V_73 , V_8 , V_145 , & V_179 , V_119 , & V_114 ) ;
if ( V_58 != 0 ) {
if ( V_58 == - V_193 )
F_87 ( V_73 , V_120 , 0 , V_114 ) ;
return - 1 ;
}
return 0 ;
}
static T_8
F_151 ( struct V_72 * V_73 , struct V_7 * V_8 )
{
struct V_28 * V_29 = F_43 ( V_8 ) ;
struct V_6 * V_20 = & V_29 -> V_8 -> V_20 ;
int V_159 ;
switch ( V_73 -> V_161 ) {
case F_105 ( V_171 ) :
V_159 = F_145 ( V_73 , V_8 ) ;
break;
case F_105 ( V_172 ) :
V_159 = F_148 ( V_73 , V_8 ) ;
break;
default:
goto V_213;
}
if ( V_159 < 0 )
goto V_213;
return V_214 ;
V_213:
V_20 -> V_215 ++ ;
V_20 -> V_216 ++ ;
F_83 ( V_73 ) ;
return V_214 ;
}
static void F_152 ( struct V_28 * V_29 )
{
struct V_7 * V_8 = V_29 -> V_8 ;
struct V_50 * V_51 = & V_29 -> V_44 ;
struct V_178 * V_179 = & V_29 -> V_204 . V_205 . V_206 ;
memcpy ( V_8 -> V_217 , & V_51 -> V_45 , sizeof( struct V_1 ) ) ;
memcpy ( V_8 -> V_218 , & V_51 -> V_46 , sizeof( struct V_1 ) ) ;
V_179 -> V_111 = V_51 -> V_45 ;
V_179 -> V_110 = V_51 -> V_46 ;
V_179 -> V_219 = V_51 -> V_156 ;
V_179 -> V_199 = 0 ;
if ( ! ( V_51 -> V_47 & V_207 ) )
V_179 -> V_199 |= V_209 & V_51 -> V_220 ;
if ( ! ( V_51 -> V_47 & V_212 ) )
V_179 -> V_199 |= V_221 & V_51 -> V_220 ;
V_51 -> V_47 &= ~ ( V_157 | V_158 | V_151 ) ;
V_51 -> V_47 |= F_95 ( V_29 , & V_51 -> V_45 , & V_51 -> V_46 ) ;
if ( V_51 -> V_47 & V_157 && V_51 -> V_47 & V_158 )
V_8 -> V_47 |= V_222 ;
else
V_8 -> V_47 &= ~ V_222 ;
if ( V_51 -> V_47 & V_157 ) {
int V_223 = ( F_96 ( & V_51 -> V_46 ) &
( V_153 | V_155 ) ) ;
struct V_27 * V_127 = F_85 ( V_29 -> V_37 ,
& V_51 -> V_46 , & V_51 -> V_45 ,
V_51 -> V_156 , V_223 ) ;
if ( ! V_127 )
return;
if ( V_127 -> V_24 . V_8 ) {
V_8 -> V_224 = V_127 -> V_24 . V_8 -> V_224 +
sizeof( struct V_75 ) ;
V_8 -> V_114 = V_127 -> V_24 . V_8 -> V_114 - sizeof( struct V_75 ) ;
if ( ! ( V_29 -> V_44 . V_47 & V_203 ) )
V_8 -> V_114 -= 8 ;
if ( V_8 -> V_114 < V_121 )
V_8 -> V_114 = V_121 ;
}
F_88 ( V_127 ) ;
}
}
static int
F_153 ( struct V_28 * V_29 , const struct V_50 * V_51 )
{
V_29 -> V_44 . V_45 = V_51 -> V_45 ;
V_29 -> V_44 . V_46 = V_51 -> V_46 ;
V_29 -> V_44 . V_47 = V_51 -> V_47 ;
V_29 -> V_44 . V_200 = V_51 -> V_200 ;
V_29 -> V_44 . V_119 = V_51 -> V_119 ;
V_29 -> V_44 . V_220 = V_51 -> V_220 ;
V_29 -> V_44 . V_156 = V_51 -> V_156 ;
V_29 -> V_44 . V_112 = V_51 -> V_112 ;
F_26 ( V_29 ) ;
F_152 ( V_29 ) ;
return 0 ;
}
static int F_154 ( struct V_28 * V_29 , struct V_50 * V_51 )
{
struct V_37 * V_37 = V_29 -> V_37 ;
struct V_40 * V_41 = F_34 ( V_37 , V_42 ) ;
int V_58 ;
F_41 ( V_41 , V_29 ) ;
F_155 () ;
V_58 = F_153 ( V_29 , V_51 ) ;
F_39 ( V_41 , V_29 ) ;
F_156 ( V_29 -> V_8 ) ;
return V_58 ;
}
static int F_157 ( struct V_28 * V_29 , struct V_50 * V_51 )
{
V_29 -> V_44 . V_112 = V_51 -> V_112 ;
F_156 ( V_29 -> V_8 ) ;
return 0 ;
}
static void
F_158 ( struct V_50 * V_51 , const struct V_225 * V_205 )
{
V_51 -> V_45 = V_205 -> V_45 ;
V_51 -> V_46 = V_205 -> V_46 ;
V_51 -> V_47 = V_205 -> V_47 ;
V_51 -> V_200 = V_205 -> V_200 ;
V_51 -> V_119 = V_205 -> V_119 ;
V_51 -> V_220 = V_205 -> V_220 ;
V_51 -> V_156 = V_205 -> V_156 ;
V_51 -> V_112 = V_205 -> V_112 ;
memcpy ( V_51 -> V_60 , V_205 -> V_60 , sizeof( V_205 -> V_60 ) ) ;
}
static void
F_159 ( struct V_225 * V_205 , const struct V_50 * V_51 )
{
V_205 -> V_45 = V_51 -> V_45 ;
V_205 -> V_46 = V_51 -> V_46 ;
V_205 -> V_47 = V_51 -> V_47 ;
V_205 -> V_200 = V_51 -> V_200 ;
V_205 -> V_119 = V_51 -> V_119 ;
V_205 -> V_220 = V_51 -> V_220 ;
V_205 -> V_156 = V_51 -> V_156 ;
V_205 -> V_112 = V_51 -> V_112 ;
memcpy ( V_205 -> V_60 , V_51 -> V_60 , sizeof( V_205 -> V_60 ) ) ;
}
static int
F_160 ( struct V_7 * V_8 , struct V_226 * V_227 , int V_228 )
{
int V_58 = 0 ;
struct V_225 V_51 ;
struct V_50 V_229 ;
struct V_28 * V_29 = F_43 ( V_8 ) ;
struct V_37 * V_37 = V_29 -> V_37 ;
struct V_40 * V_41 = F_34 ( V_37 , V_42 ) ;
switch ( V_228 ) {
case V_230 :
if ( V_8 == V_41 -> V_71 ) {
if ( F_161 ( & V_51 , V_227 -> V_231 . V_232 , sizeof( V_51 ) ) ) {
V_58 = - V_233 ;
break;
}
F_158 ( & V_229 , & V_51 ) ;
V_29 = F_54 ( V_37 , & V_229 , 0 ) ;
if ( F_75 ( V_29 ) )
V_29 = F_43 ( V_8 ) ;
} else {
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
}
F_159 ( & V_51 , & V_29 -> V_44 ) ;
if ( F_162 ( V_227 -> V_231 . V_232 , & V_51 , sizeof( V_51 ) ) ) {
V_58 = - V_233 ;
}
break;
case V_234 :
case V_235 :
V_58 = - V_236 ;
if ( ! F_163 ( V_37 -> V_237 , V_238 ) )
break;
V_58 = - V_233 ;
if ( F_161 ( & V_51 , V_227 -> V_231 . V_232 , sizeof( V_51 ) ) )
break;
V_58 = - V_239 ;
if ( V_51 . V_112 != V_144 && V_51 . V_112 != V_130 &&
V_51 . V_112 != 0 )
break;
F_158 ( & V_229 , & V_51 ) ;
V_29 = F_54 ( V_37 , & V_229 , V_228 == V_234 ) ;
if ( V_228 == V_235 ) {
if ( ! F_75 ( V_29 ) ) {
if ( V_29 -> V_8 != V_8 ) {
V_58 = - V_69 ;
break;
}
} else
V_29 = F_43 ( V_8 ) ;
if ( V_8 == V_41 -> V_71 )
V_58 = F_157 ( V_29 , & V_229 ) ;
else
V_58 = F_154 ( V_29 , & V_229 ) ;
}
if ( ! F_75 ( V_29 ) ) {
V_58 = 0 ;
F_159 ( & V_51 , & V_29 -> V_44 ) ;
if ( F_162 ( V_227 -> V_231 . V_232 , & V_51 , sizeof( V_51 ) ) )
V_58 = - V_233 ;
} else {
V_58 = F_125 ( V_29 ) ;
}
break;
case V_240 :
V_58 = - V_236 ;
if ( ! F_163 ( V_37 -> V_237 , V_238 ) )
break;
if ( V_8 == V_41 -> V_71 ) {
V_58 = - V_233 ;
if ( F_161 ( & V_51 , V_227 -> V_231 . V_232 , sizeof( V_51 ) ) )
break;
V_58 = - V_109 ;
F_158 ( & V_229 , & V_51 ) ;
V_29 = F_54 ( V_37 , & V_229 , 0 ) ;
if ( F_75 ( V_29 ) )
break;
V_58 = - V_236 ;
if ( V_29 -> V_8 == V_41 -> V_71 )
break;
V_8 = V_29 -> V_8 ;
}
V_58 = 0 ;
F_164 ( V_8 ) ;
break;
default:
V_58 = - V_239 ;
}
return V_58 ;
}
static int
F_165 ( struct V_7 * V_8 , int V_241 )
{
struct V_28 * V_242 = F_43 ( V_8 ) ;
if ( V_242 -> V_44 . V_112 == V_130 ) {
if ( V_241 < 68 )
return - V_239 ;
} else {
if ( V_241 < V_121 )
return - V_239 ;
}
if ( V_241 > 0xFFF8 - V_8 -> V_224 )
return - V_239 ;
V_8 -> V_114 = V_241 ;
return 0 ;
}
int F_166 ( const struct V_7 * V_8 )
{
struct V_28 * V_29 = F_43 ( V_8 ) ;
return V_29 -> V_44 . V_156 ;
}
static void V_65 ( struct V_7 * V_8 )
{
struct V_28 * V_29 ;
V_8 -> V_243 = & V_244 ;
V_8 -> V_245 = F_42 ;
V_8 -> type = V_246 ;
V_8 -> V_224 = V_247 + sizeof( struct V_75 ) ;
V_8 -> V_114 = V_248 - sizeof( struct V_75 ) ;
V_29 = F_43 ( V_8 ) ;
if ( ! ( V_29 -> V_44 . V_47 & V_203 ) )
V_8 -> V_114 -= 8 ;
V_8 -> V_47 |= V_249 ;
V_8 -> V_250 = sizeof( struct V_1 ) ;
F_167 ( V_8 ) ;
V_8 -> V_251 = V_252 ;
F_168 ( V_8 -> V_253 ) ;
}
static inline int
F_169 ( struct V_7 * V_8 )
{
struct V_28 * V_29 = F_43 ( V_8 ) ;
int V_159 ;
V_29 -> V_8 = V_8 ;
V_29 -> V_37 = F_46 ( V_8 ) ;
V_8 -> V_14 = F_170 ( struct V_9 ) ;
if ( ! V_8 -> V_14 )
return - V_36 ;
V_159 = F_30 ( V_29 ) ;
if ( V_159 ) {
F_29 ( V_8 -> V_14 ) ;
V_8 -> V_14 = NULL ;
return V_159 ;
}
return 0 ;
}
static int F_171 ( struct V_7 * V_8 )
{
struct V_28 * V_29 = F_43 ( V_8 ) ;
int V_58 = F_169 ( V_8 ) ;
if ( V_58 )
return V_58 ;
F_152 ( V_29 ) ;
return 0 ;
}
static int T_9 F_172 ( struct V_7 * V_8 )
{
struct V_28 * V_29 = F_43 ( V_8 ) ;
struct V_37 * V_37 = F_46 ( V_8 ) ;
struct V_40 * V_41 = F_34 ( V_37 , V_42 ) ;
V_29 -> V_44 . V_112 = V_144 ;
F_48 ( V_8 ) ;
F_16 ( V_41 -> V_49 [ 0 ] , V_29 ) ;
return 0 ;
}
static int F_173 ( struct V_254 * V_255 [] , struct V_254 * V_83 [] )
{
T_5 V_112 ;
if ( ! V_83 || ! V_83 [ V_256 ] )
return 0 ;
V_112 = F_174 ( V_83 [ V_256 ] ) ;
if ( V_112 != V_144 &&
V_112 != V_130 &&
V_112 != 0 )
return - V_239 ;
return 0 ;
}
static void F_175 ( struct V_254 * V_83 [] ,
struct V_50 * V_44 )
{
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
if ( ! V_83 )
return;
if ( V_83 [ V_257 ] )
V_44 -> V_156 = F_176 ( V_83 [ V_257 ] ) ;
if ( V_83 [ V_258 ] )
V_44 -> V_45 = F_177 ( V_83 [ V_258 ] ) ;
if ( V_83 [ V_259 ] )
V_44 -> V_46 = F_177 ( V_83 [ V_259 ] ) ;
if ( V_83 [ V_260 ] )
V_44 -> V_200 = F_174 ( V_83 [ V_260 ] ) ;
if ( V_83 [ V_261 ] )
V_44 -> V_119 = F_174 ( V_83 [ V_261 ] ) ;
if ( V_83 [ V_262 ] )
V_44 -> V_220 = F_178 ( V_83 [ V_262 ] ) ;
if ( V_83 [ V_263 ] )
V_44 -> V_47 = F_176 ( V_83 [ V_263 ] ) ;
if ( V_83 [ V_256 ] )
V_44 -> V_112 = F_174 ( V_83 [ V_256 ] ) ;
}
static int F_179 ( struct V_37 * V_264 , struct V_7 * V_8 ,
struct V_254 * V_255 [] , struct V_254 * V_83 [] )
{
struct V_37 * V_37 = F_46 ( V_8 ) ;
struct V_28 * V_265 , * V_29 ;
V_265 = F_43 ( V_8 ) ;
F_175 ( V_83 , & V_265 -> V_44 ) ;
V_29 = F_54 ( V_37 , & V_265 -> V_44 , 0 ) ;
if ( ! F_75 ( V_29 ) )
return - V_69 ;
return F_45 ( V_8 ) ;
}
static int F_180 ( struct V_7 * V_8 , struct V_254 * V_255 [] ,
struct V_254 * V_83 [] )
{
struct V_28 * V_29 = F_43 ( V_8 ) ;
struct V_50 V_51 ;
struct V_37 * V_37 = V_29 -> V_37 ;
struct V_40 * V_41 = F_34 ( V_37 , V_42 ) ;
if ( V_8 == V_41 -> V_71 )
return - V_239 ;
F_175 ( V_83 , & V_51 ) ;
V_29 = F_54 ( V_37 , & V_51 , 0 ) ;
if ( ! F_75 ( V_29 ) ) {
if ( V_29 -> V_8 != V_8 )
return - V_69 ;
} else
V_29 = F_43 ( V_8 ) ;
return F_154 ( V_29 , & V_51 ) ;
}
static void F_181 ( struct V_7 * V_8 , struct V_266 * V_267 )
{
struct V_37 * V_37 = F_46 ( V_8 ) ;
struct V_40 * V_41 = F_34 ( V_37 , V_42 ) ;
if ( V_8 != V_41 -> V_71 )
F_182 ( V_8 , V_267 ) ;
}
static T_10 F_183 ( const struct V_7 * V_8 )
{
return
F_184 ( 4 ) +
F_184 ( sizeof( struct V_1 ) ) +
F_184 ( sizeof( struct V_1 ) ) +
F_184 ( 1 ) +
F_184 ( 1 ) +
F_184 ( 4 ) +
F_184 ( 4 ) +
F_184 ( 1 ) +
0 ;
}
static int F_185 ( struct V_72 * V_73 , const struct V_7 * V_8 )
{
struct V_28 * V_268 = F_43 ( V_8 ) ;
struct V_50 * V_269 = & V_268 -> V_44 ;
if ( F_186 ( V_73 , V_257 , V_269 -> V_156 ) ||
F_187 ( V_73 , V_258 , & V_269 -> V_45 ) ||
F_187 ( V_73 , V_259 , & V_269 -> V_46 ) ||
F_188 ( V_73 , V_260 , V_269 -> V_200 ) ||
F_188 ( V_73 , V_261 , V_269 -> V_119 ) ||
F_189 ( V_73 , V_262 , V_269 -> V_220 ) ||
F_186 ( V_73 , V_263 , V_269 -> V_47 ) ||
F_188 ( V_73 , V_256 , V_269 -> V_112 ) )
goto V_270;
return 0 ;
V_270:
return - V_193 ;
}
struct V_37 * F_190 ( const struct V_7 * V_8 )
{
struct V_28 * V_268 = F_43 ( V_8 ) ;
return V_268 -> V_37 ;
}
static void T_11 F_191 ( struct V_37 * V_37 )
{
struct V_40 * V_41 = F_34 ( V_37 , V_42 ) ;
struct V_7 * V_8 , * V_271 ;
int V_52 ;
struct V_28 * V_29 ;
F_192 ( V_272 ) ;
F_193 (net, dev, aux)
if ( V_8 -> V_61 == & V_62 )
F_182 ( V_8 , & V_272 ) ;
for ( V_52 = 0 ; V_52 < V_273 ; V_52 ++ ) {
V_29 = F_40 ( V_41 -> V_274 [ V_52 ] ) ;
while ( V_29 ) {
if ( ! F_128 ( F_46 ( V_29 -> V_8 ) , V_37 ) )
F_182 ( V_29 -> V_8 , & V_272 ) ;
V_29 = F_40 ( V_29 -> V_56 ) ;
}
}
F_194 ( & V_272 ) ;
}
static int T_9 F_195 ( struct V_37 * V_37 )
{
struct V_40 * V_41 = F_34 ( V_37 , V_42 ) ;
struct V_28 * V_29 = NULL ;
int V_58 ;
V_41 -> V_54 [ 0 ] = V_41 -> V_49 ;
V_41 -> V_54 [ 1 ] = V_41 -> V_274 ;
V_58 = - V_36 ;
V_41 -> V_71 = F_51 ( sizeof( struct V_28 ) , L_10 ,
V_64 , V_65 ) ;
if ( ! V_41 -> V_71 )
goto V_275;
F_52 ( V_41 -> V_71 , V_37 ) ;
V_41 -> V_71 -> V_61 = & V_62 ;
V_41 -> V_71 -> V_276 |= V_277 ;
V_58 = F_172 ( V_41 -> V_71 ) ;
if ( V_58 < 0 )
goto V_278;
V_58 = F_196 ( V_41 -> V_71 ) ;
if ( V_58 < 0 )
goto V_278;
V_29 = F_43 ( V_41 -> V_71 ) ;
strcpy ( V_29 -> V_44 . V_60 , V_41 -> V_71 -> V_60 ) ;
return 0 ;
V_278:
F_42 ( V_41 -> V_71 ) ;
V_275:
return V_58 ;
}
static void T_11 F_197 ( struct V_37 * V_37 )
{
F_198 () ;
F_191 ( V_37 ) ;
F_199 () ;
}
static int T_12 F_200 ( void )
{
int V_58 ;
V_58 = F_201 ( & V_279 ) ;
if ( V_58 < 0 )
goto V_280;
V_58 = F_202 ( & V_281 , V_282 ) ;
if ( V_58 < 0 ) {
F_203 ( L_11 , V_283 ) ;
goto V_284;
}
V_58 = F_202 ( & V_285 , V_286 ) ;
if ( V_58 < 0 ) {
F_203 ( L_12 , V_283 ) ;
goto V_287;
}
V_58 = F_204 ( & V_62 ) ;
if ( V_58 < 0 )
goto V_288;
return 0 ;
V_288:
F_205 ( & V_285 , V_286 ) ;
V_287:
F_205 ( & V_281 , V_282 ) ;
V_284:
F_206 ( & V_279 ) ;
V_280:
return V_58 ;
}
static void T_13 F_207 ( void )
{
F_208 ( & V_62 ) ;
if ( F_205 ( & V_281 , V_282 ) )
F_209 ( L_13 , V_283 ) ;
if ( F_205 ( & V_285 , V_286 ) )
F_209 ( L_14 , V_283 ) ;
F_206 ( & V_279 ) ;
}
