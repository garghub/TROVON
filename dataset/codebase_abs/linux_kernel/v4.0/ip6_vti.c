static T_1 F_1 ( const struct V_1 * V_2 , const struct V_1 * V_3 )
{
T_1 V_4 = F_2 ( V_2 ) ^ F_2 ( V_3 ) ;
return F_3 ( V_4 , V_5 ) ;
}
static struct V_6 *
F_4 ( struct V_7 * V_7 , const struct V_1 * V_8 ,
const struct V_1 * V_9 )
{
unsigned int V_4 = F_1 ( V_8 , V_9 ) ;
struct V_6 * V_10 ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
struct V_1 V_14 ;
F_6 (ip6n->tnls_r_l[hash]) {
if ( F_7 ( V_9 , & V_10 -> V_15 . V_16 ) &&
F_7 ( V_8 , & V_10 -> V_15 . V_17 ) &&
( V_10 -> V_18 -> V_19 & V_20 ) )
return V_10 ;
}
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_4 = F_1 ( & V_14 , V_9 ) ;
F_6 (ip6n->tnls_r_l[hash]) {
if ( F_7 ( V_9 , & V_10 -> V_15 . V_16 ) &&
( V_10 -> V_18 -> V_19 & V_20 ) )
return V_10 ;
}
V_4 = F_1 ( V_8 , & V_14 ) ;
F_6 (ip6n->tnls_r_l[hash]) {
if ( F_7 ( V_8 , & V_10 -> V_15 . V_17 ) &&
( V_10 -> V_18 -> V_19 & V_20 ) )
return V_10 ;
}
V_10 = F_8 ( V_12 -> V_21 [ 0 ] ) ;
if ( V_10 && ( V_10 -> V_18 -> V_19 & V_20 ) )
return V_10 ;
return NULL ;
}
static struct V_6 T_2 * *
F_9 ( struct V_11 * V_12 , const struct V_22 * V_23 )
{
const struct V_1 * V_8 = & V_23 -> V_17 ;
const struct V_1 * V_9 = & V_23 -> V_16 ;
unsigned int V_24 = 0 ;
int V_25 = 0 ;
if ( ! F_10 ( V_8 ) || ! F_10 ( V_9 ) ) {
V_25 = 1 ;
V_24 = F_1 ( V_8 , V_9 ) ;
}
return & V_12 -> V_26 [ V_25 ] [ V_24 ] ;
}
static void
F_11 ( struct V_11 * V_12 , struct V_6 * V_10 )
{
struct V_6 T_2 * * V_27 = F_9 ( V_12 , & V_10 -> V_15 ) ;
F_12 ( V_10 -> V_28 , F_13 ( * V_27 ) ) ;
F_12 ( * V_27 , V_10 ) ;
}
static void
F_14 ( struct V_11 * V_12 , struct V_6 * V_10 )
{
struct V_6 T_2 * * V_27 ;
struct V_6 * V_29 ;
for ( V_27 = F_9 ( V_12 , & V_10 -> V_15 ) ;
( V_29 = F_13 ( * V_27 ) ) != NULL ;
V_27 = & V_29 -> V_28 ) {
if ( V_10 == V_29 ) {
F_12 ( * V_27 , V_10 -> V_28 ) ;
break;
}
}
}
static void F_15 ( struct V_30 * V_18 )
{
F_16 ( V_18 -> V_31 ) ;
F_17 ( V_18 ) ;
}
static int F_18 ( struct V_30 * V_18 )
{
struct V_6 * V_10 = F_19 ( V_18 ) ;
struct V_7 * V_7 = F_20 ( V_18 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
int V_32 ;
V_32 = F_21 ( V_18 ) ;
if ( V_32 < 0 )
goto V_33;
strcpy ( V_10 -> V_15 . V_34 , V_18 -> V_34 ) ;
V_18 -> V_35 = & V_36 ;
F_22 ( V_18 ) ;
F_11 ( V_12 , V_10 ) ;
return 0 ;
V_33:
return V_32 ;
}
static struct V_6 * F_23 ( struct V_7 * V_7 , struct V_22 * V_23 )
{
struct V_30 * V_18 ;
struct V_6 * V_10 ;
char V_34 [ V_37 ] ;
int V_32 ;
if ( V_23 -> V_34 [ 0 ] )
F_24 ( V_34 , V_23 -> V_34 , V_37 ) ;
else
sprintf ( V_34 , L_1 ) ;
V_18 = F_25 ( sizeof( * V_10 ) , V_34 , V_38 , V_39 ) ;
if ( V_18 == NULL )
goto V_40;
F_26 ( V_18 , V_7 ) ;
V_10 = F_19 ( V_18 ) ;
V_10 -> V_15 = * V_23 ;
V_10 -> V_7 = F_20 ( V_18 ) ;
V_32 = F_18 ( V_18 ) ;
if ( V_32 < 0 )
goto V_41;
return V_10 ;
V_41:
F_15 ( V_18 ) ;
V_40:
return NULL ;
}
static struct V_6 * F_27 ( struct V_7 * V_7 , struct V_22 * V_23 ,
int V_42 )
{
const struct V_1 * V_8 = & V_23 -> V_17 ;
const struct V_1 * V_9 = & V_23 -> V_16 ;
struct V_6 T_2 * * V_27 ;
struct V_6 * V_10 ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
for ( V_27 = F_9 ( V_12 , V_23 ) ;
( V_10 = F_13 ( * V_27 ) ) != NULL ;
V_27 = & V_10 -> V_28 ) {
if ( F_7 ( V_9 , & V_10 -> V_15 . V_16 ) &&
F_7 ( V_8 , & V_10 -> V_15 . V_17 ) ) {
if ( V_42 )
return NULL ;
return V_10 ;
}
}
if ( ! V_42 )
return NULL ;
return F_23 ( V_7 , V_23 ) ;
}
static void F_28 ( struct V_30 * V_18 )
{
struct V_6 * V_10 = F_19 ( V_18 ) ;
struct V_7 * V_7 = F_20 ( V_18 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
if ( V_18 == V_12 -> V_43 )
F_29 ( V_12 -> V_21 [ 0 ] , NULL ) ;
else
F_14 ( V_12 , V_10 ) ;
F_30 ( V_18 ) ;
}
static int F_31 ( struct V_44 * V_45 )
{
struct V_6 * V_10 ;
const struct V_46 * V_47 = F_32 ( V_45 ) ;
F_33 () ;
V_10 = F_4 ( F_20 ( V_45 -> V_18 ) , & V_47 -> V_48 , & V_47 -> V_49 ) ;
if ( V_10 != NULL ) {
if ( V_10 -> V_15 . V_50 != V_51 && V_10 -> V_15 . V_50 != 0 ) {
F_34 () ;
goto V_52;
}
if ( ! F_35 ( NULL , V_53 , V_45 ) ) {
F_34 () ;
return 0 ;
}
if ( ! F_36 ( V_10 , & V_47 -> V_49 , & V_47 -> V_48 ) ) {
V_10 -> V_18 -> V_54 . V_55 ++ ;
F_34 () ;
goto V_52;
}
F_37 ( V_45 ) -> V_56 . V_57 = V_10 ;
V_45 -> V_58 = F_38 ( V_10 -> V_15 . V_59 ) ;
F_34 () ;
return F_39 ( V_45 ) ;
}
F_34 () ;
return - V_60 ;
V_52:
F_40 ( V_45 ) ;
return 0 ;
}
static int F_41 ( struct V_44 * V_45 , int V_32 )
{
unsigned short V_61 ;
struct V_30 * V_18 ;
struct V_62 * V_31 ;
struct V_63 * V_64 ;
struct V_6 * V_10 = F_37 ( V_45 ) -> V_56 . V_57 ;
if ( ! V_10 )
return 1 ;
V_18 = V_10 -> V_18 ;
if ( V_32 ) {
V_18 -> V_54 . V_65 ++ ;
V_18 -> V_54 . V_55 ++ ;
return 0 ;
}
V_64 = F_42 ( V_45 ) ;
V_61 = V_64 -> V_66 -> V_67 -> V_61 ;
if ( ! F_43 ( NULL , V_53 , V_45 , V_61 ) )
return - V_68 ;
F_44 ( V_45 , ! F_45 ( V_10 -> V_7 , F_20 ( V_45 -> V_18 ) ) ) ;
V_45 -> V_18 = V_18 ;
V_31 = F_46 ( V_18 -> V_31 ) ;
F_47 ( & V_31 -> V_69 ) ;
V_31 -> V_70 ++ ;
V_31 -> V_71 += V_45 -> V_72 ;
F_48 ( & V_31 -> V_69 ) ;
return 0 ;
}
static inline bool
F_49 ( const struct V_6 * V_10 , const struct V_46 * V_73 )
{
return F_7 ( & V_10 -> V_15 . V_17 , & V_73 -> V_48 ) ;
}
static bool F_50 ( const struct V_63 * V_64 ,
const struct V_1 * V_74 ,
const struct V_1 * V_75 )
{
T_3 * V_49 = ( T_3 * ) V_74 ;
T_3 * V_48 = ( T_3 * ) V_75 ;
if ( ! V_64 || V_64 -> V_76 . V_77 != V_78 ||
V_64 -> V_76 . V_61 != V_79 )
return false ;
if ( F_10 ( V_74 ) )
return F_51 ( V_48 , & V_64 -> V_76 . V_48 , V_79 ) ;
if ( ! F_52 ( V_64 , V_49 , V_48 , V_79 ) )
return false ;
return true ;
}
static int
F_53 ( struct V_44 * V_45 , struct V_30 * V_18 , struct V_80 * V_81 )
{
struct V_6 * V_10 = F_19 ( V_18 ) ;
struct V_82 * V_54 = & V_10 -> V_18 -> V_54 ;
struct V_83 * V_74 = F_54 ( V_45 ) ;
struct V_30 * V_84 ;
struct V_63 * V_64 ;
int V_32 = - 1 ;
if ( ! V_74 )
goto V_85;
F_55 ( V_74 ) ;
V_74 = F_56 ( V_10 -> V_7 , V_74 , V_81 , NULL , 0 ) ;
if ( F_57 ( V_74 ) ) {
V_32 = F_58 ( V_74 ) ;
V_74 = NULL ;
goto V_85;
}
V_64 = V_74 -> V_86 ;
if ( ! F_50 ( V_64 , & V_10 -> V_15 . V_17 , & V_10 -> V_15 . V_16 ) )
goto V_85;
if ( ! F_59 ( V_10 , ( const struct V_1 * ) & V_64 -> V_76 . V_48 ,
( const struct V_1 * ) & V_64 -> V_87 . V_49 ) )
goto V_85;
V_84 = V_74 -> V_18 ;
if ( V_84 == V_18 ) {
V_54 -> V_88 ++ ;
F_60 ( L_2 ,
V_10 -> V_15 . V_34 ) ;
goto V_89;
}
F_44 ( V_45 , ! F_45 ( V_10 -> V_7 , F_20 ( V_18 ) ) ) ;
F_61 ( V_45 , V_74 ) ;
V_45 -> V_18 = F_54 ( V_45 ) -> V_18 ;
V_32 = F_62 ( V_45 ) ;
if ( F_63 ( V_32 ) == 0 ) {
struct V_62 * V_31 = F_46 ( V_18 -> V_31 ) ;
F_47 ( & V_31 -> V_69 ) ;
V_31 -> V_90 += V_45 -> V_72 ;
V_31 -> V_91 ++ ;
F_48 ( & V_31 -> V_69 ) ;
} else {
V_54 -> V_92 ++ ;
V_54 -> V_93 ++ ;
}
return 0 ;
V_85:
V_54 -> V_94 ++ ;
F_64 ( V_45 ) ;
V_89:
F_65 ( V_74 ) ;
return V_32 ;
}
static T_4
F_66 ( struct V_44 * V_45 , struct V_30 * V_18 )
{
struct V_6 * V_10 = F_19 ( V_18 ) ;
struct V_82 * V_54 = & V_10 -> V_18 -> V_54 ;
struct V_46 * V_47 ;
struct V_80 V_81 ;
int V_95 ;
memset ( & V_81 , 0 , sizeof( V_81 ) ) ;
V_45 -> V_58 = F_38 ( V_10 -> V_15 . V_96 ) ;
switch ( V_45 -> V_97 ) {
case F_67 ( V_98 ) :
V_47 = F_32 ( V_45 ) ;
if ( ( V_10 -> V_15 . V_50 != V_51 && V_10 -> V_15 . V_50 != 0 ) ||
F_49 ( V_10 , V_47 ) )
goto V_99;
F_68 ( V_45 , & V_81 , V_79 ) ;
memset ( F_69 ( V_45 ) , 0 , sizeof( * F_69 ( V_45 ) ) ) ;
break;
case F_67 ( V_100 ) :
F_68 ( V_45 , & V_81 , V_101 ) ;
memset ( F_70 ( V_45 ) , 0 , sizeof( * F_70 ( V_45 ) ) ) ;
break;
default:
goto V_99;
}
V_95 = F_53 ( V_45 , V_18 , & V_81 ) ;
if ( V_95 < 0 )
goto V_99;
return V_102 ;
V_99:
V_54 -> V_92 ++ ;
V_54 -> V_103 ++ ;
F_40 ( V_45 ) ;
return V_102 ;
}
static int F_71 ( struct V_44 * V_45 , struct V_104 * V_105 ,
T_5 type , T_5 V_106 , int V_107 , T_6 V_108 )
{
T_6 V_109 ;
T_7 V_58 ;
struct V_63 * V_64 ;
struct V_6 * V_10 ;
struct V_110 * V_111 ;
struct V_112 * V_113 ;
struct V_114 * V_115 ;
struct V_7 * V_7 = F_20 ( V_45 -> V_18 ) ;
const struct V_46 * V_116 = ( const struct V_46 * ) V_45 -> V_117 ;
int V_97 = V_116 -> V_118 ;
V_10 = F_4 ( F_20 ( V_45 -> V_18 ) , & V_116 -> V_49 , & V_116 -> V_48 ) ;
if ( ! V_10 )
return - 1 ;
V_58 = F_38 ( V_10 -> V_15 . V_96 ) ;
switch ( V_97 ) {
case V_119 :
V_111 = (struct V_110 * ) ( V_45 -> V_117 + V_107 ) ;
V_109 = V_111 -> V_109 ;
break;
case V_120 :
V_113 = (struct V_112 * ) ( V_45 -> V_117 + V_107 ) ;
V_109 = V_113 -> V_109 ;
break;
case V_121 :
V_115 = (struct V_114 * ) ( V_45 -> V_117 + V_107 ) ;
V_109 = F_72 ( F_73 ( V_115 -> V_122 ) ) ;
break;
default:
return 0 ;
}
if ( type != V_123 &&
type != V_124 )
return 0 ;
V_64 = F_74 ( V_7 , V_58 , ( const T_3 * ) & V_116 -> V_49 ,
V_109 , V_97 , V_79 ) ;
if ( ! V_64 )
return 0 ;
if ( type == V_124 )
F_75 ( V_45 , V_7 , V_45 -> V_18 -> V_125 , 0 ) ;
else
F_76 ( V_45 , V_7 , V_108 , 0 , 0 ) ;
F_77 ( V_64 ) ;
return 0 ;
}
static void F_78 ( struct V_6 * V_10 )
{
struct V_30 * V_18 = V_10 -> V_18 ;
struct V_22 * V_23 = & V_10 -> V_15 ;
memcpy ( V_18 -> V_126 , & V_23 -> V_16 , sizeof( struct V_1 ) ) ;
memcpy ( V_18 -> V_127 , & V_23 -> V_17 , sizeof( struct V_1 ) ) ;
V_23 -> V_19 &= ~ ( V_128 | V_129 |
V_130 ) ;
V_23 -> V_19 |= F_79 ( V_10 , & V_23 -> V_16 , & V_23 -> V_17 ) ;
if ( V_23 -> V_19 & V_128 && V_23 -> V_19 & V_129 )
V_18 -> V_19 |= V_131 ;
else
V_18 -> V_19 &= ~ V_131 ;
V_18 -> V_132 = V_23 -> V_133 ;
}
static int
F_80 ( struct V_6 * V_10 , const struct V_22 * V_23 )
{
V_10 -> V_15 . V_16 = V_23 -> V_16 ;
V_10 -> V_15 . V_17 = V_23 -> V_17 ;
V_10 -> V_15 . V_133 = V_23 -> V_133 ;
V_10 -> V_15 . V_59 = V_23 -> V_59 ;
V_10 -> V_15 . V_96 = V_23 -> V_96 ;
V_10 -> V_15 . V_50 = V_23 -> V_50 ;
F_81 ( V_10 ) ;
F_78 ( V_10 ) ;
return 0 ;
}
static int F_82 ( struct V_6 * V_10 , struct V_22 * V_23 )
{
struct V_7 * V_7 = F_20 ( V_10 -> V_18 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
int V_32 ;
F_14 ( V_12 , V_10 ) ;
F_83 () ;
V_32 = F_80 ( V_10 , V_23 ) ;
F_11 ( V_12 , V_10 ) ;
F_84 ( V_10 -> V_18 ) ;
return V_32 ;
}
static void
F_85 ( struct V_22 * V_23 , const struct V_134 * V_135 )
{
V_23 -> V_16 = V_135 -> V_16 ;
V_23 -> V_17 = V_135 -> V_17 ;
V_23 -> V_133 = V_135 -> V_133 ;
V_23 -> V_59 = V_135 -> V_59 ;
V_23 -> V_96 = V_135 -> V_96 ;
V_23 -> V_50 = V_135 -> V_50 ;
memcpy ( V_23 -> V_34 , V_135 -> V_34 , sizeof( V_135 -> V_34 ) ) ;
}
static void
F_86 ( struct V_134 * V_135 , const struct V_22 * V_23 )
{
V_135 -> V_16 = V_23 -> V_16 ;
V_135 -> V_17 = V_23 -> V_17 ;
V_135 -> V_133 = V_23 -> V_133 ;
V_135 -> V_59 = V_23 -> V_59 ;
V_135 -> V_96 = V_23 -> V_96 ;
V_135 -> V_50 = V_23 -> V_50 ;
memcpy ( V_135 -> V_34 , V_23 -> V_34 , sizeof( V_135 -> V_34 ) ) ;
}
static int
F_87 ( struct V_30 * V_18 , struct V_136 * V_137 , int V_138 )
{
int V_32 = 0 ;
struct V_134 V_23 ;
struct V_22 V_139 ;
struct V_6 * V_10 = NULL ;
struct V_7 * V_7 = F_20 ( V_18 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
switch ( V_138 ) {
case V_140 :
if ( V_18 == V_12 -> V_43 ) {
if ( F_88 ( & V_23 , V_137 -> V_141 . V_142 , sizeof( V_23 ) ) ) {
V_32 = - V_143 ;
break;
}
F_85 ( & V_139 , & V_23 ) ;
V_10 = F_27 ( V_7 , & V_139 , 0 ) ;
} else {
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
}
if ( V_10 == NULL )
V_10 = F_19 ( V_18 ) ;
F_86 ( & V_23 , & V_10 -> V_15 ) ;
if ( F_89 ( V_137 -> V_141 . V_142 , & V_23 , sizeof( V_23 ) ) )
V_32 = - V_143 ;
break;
case V_144 :
case V_145 :
V_32 = - V_68 ;
if ( ! F_90 ( V_7 -> V_146 , V_147 ) )
break;
V_32 = - V_143 ;
if ( F_88 ( & V_23 , V_137 -> V_141 . V_142 , sizeof( V_23 ) ) )
break;
V_32 = - V_60 ;
if ( V_23 . V_50 != V_51 && V_23 . V_50 != 0 )
break;
F_85 ( & V_139 , & V_23 ) ;
V_10 = F_27 ( V_7 , & V_139 , V_138 == V_144 ) ;
if ( V_18 != V_12 -> V_43 && V_138 == V_145 ) {
if ( V_10 != NULL ) {
if ( V_10 -> V_18 != V_18 ) {
V_32 = - V_148 ;
break;
}
} else
V_10 = F_19 ( V_18 ) ;
V_32 = F_82 ( V_10 , & V_139 ) ;
}
if ( V_10 ) {
V_32 = 0 ;
F_86 ( & V_23 , & V_10 -> V_15 ) ;
if ( F_89 ( V_137 -> V_141 . V_142 , & V_23 , sizeof( V_23 ) ) )
V_32 = - V_143 ;
} else
V_32 = ( V_138 == V_144 ? - V_149 : - V_150 ) ;
break;
case V_151 :
V_32 = - V_68 ;
if ( ! F_90 ( V_7 -> V_146 , V_147 ) )
break;
if ( V_18 == V_12 -> V_43 ) {
V_32 = - V_143 ;
if ( F_88 ( & V_23 , V_137 -> V_141 . V_142 , sizeof( V_23 ) ) )
break;
V_32 = - V_150 ;
F_85 ( & V_139 , & V_23 ) ;
V_10 = F_27 ( V_7 , & V_139 , 0 ) ;
if ( V_10 == NULL )
break;
V_32 = - V_68 ;
if ( V_10 -> V_18 == V_12 -> V_43 )
break;
V_18 = V_10 -> V_18 ;
}
V_32 = 0 ;
F_91 ( V_18 ) ;
break;
default:
V_32 = - V_60 ;
}
return V_32 ;
}
static int F_92 ( struct V_30 * V_18 , int V_152 )
{
if ( V_152 < V_153 )
return - V_60 ;
V_18 -> V_154 = V_152 ;
return 0 ;
}
static void V_39 ( struct V_30 * V_18 )
{
V_18 -> V_155 = & V_156 ;
V_18 -> V_157 = F_15 ;
V_18 -> type = V_158 ;
V_18 -> V_159 = V_160 + sizeof( struct V_46 ) ;
V_18 -> V_154 = V_161 ;
V_18 -> V_19 |= V_162 ;
V_18 -> V_163 = sizeof( struct V_1 ) ;
F_93 ( V_18 ) ;
}
static inline int F_94 ( struct V_30 * V_18 )
{
struct V_6 * V_10 = F_19 ( V_18 ) ;
V_10 -> V_18 = V_18 ;
V_10 -> V_7 = F_20 ( V_18 ) ;
V_18 -> V_31 = F_95 ( struct V_62 ) ;
if ( ! V_18 -> V_31 )
return - V_164 ;
return 0 ;
}
static int F_96 ( struct V_30 * V_18 )
{
struct V_6 * V_10 = F_19 ( V_18 ) ;
int V_32 = F_94 ( V_18 ) ;
if ( V_32 )
return V_32 ;
F_78 ( V_10 ) ;
return 0 ;
}
static int T_8 F_97 ( struct V_30 * V_18 )
{
struct V_6 * V_10 = F_19 ( V_18 ) ;
struct V_7 * V_7 = F_20 ( V_18 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
V_10 -> V_15 . V_50 = V_51 ;
F_22 ( V_18 ) ;
F_12 ( V_12 -> V_21 [ 0 ] , V_10 ) ;
return 0 ;
}
static int F_98 ( struct V_165 * V_166 [] , struct V_165 * V_117 [] )
{
return 0 ;
}
static void F_99 ( struct V_165 * V_117 [] ,
struct V_22 * V_15 )
{
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
if ( ! V_117 )
return;
if ( V_117 [ V_167 ] )
V_15 -> V_133 = F_100 ( V_117 [ V_167 ] ) ;
if ( V_117 [ V_168 ] )
F_101 ( & V_15 -> V_16 , V_117 [ V_168 ] ,
sizeof( struct V_1 ) ) ;
if ( V_117 [ V_169 ] )
F_101 ( & V_15 -> V_17 , V_117 [ V_169 ] ,
sizeof( struct V_1 ) ) ;
if ( V_117 [ V_170 ] )
V_15 -> V_59 = F_102 ( V_117 [ V_170 ] ) ;
if ( V_117 [ V_171 ] )
V_15 -> V_96 = F_102 ( V_117 [ V_171 ] ) ;
}
static int F_103 ( struct V_7 * V_172 , struct V_30 * V_18 ,
struct V_165 * V_166 [] , struct V_165 * V_117 [] )
{
struct V_7 * V_7 = F_20 ( V_18 ) ;
struct V_6 * V_173 ;
V_173 = F_19 ( V_18 ) ;
F_99 ( V_117 , & V_173 -> V_15 ) ;
V_173 -> V_15 . V_50 = V_51 ;
if ( F_27 ( V_7 , & V_173 -> V_15 , 0 ) )
return - V_148 ;
return F_18 ( V_18 ) ;
}
static void F_104 ( struct V_30 * V_18 , struct V_174 * V_175 )
{
struct V_7 * V_7 = F_20 ( V_18 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
if ( V_18 != V_12 -> V_43 )
F_105 ( V_18 , V_175 ) ;
}
static int F_106 ( struct V_30 * V_18 , struct V_165 * V_166 [] ,
struct V_165 * V_117 [] )
{
struct V_6 * V_10 ;
struct V_22 V_23 ;
struct V_7 * V_7 = F_20 ( V_18 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
if ( V_18 == V_12 -> V_43 )
return - V_60 ;
F_99 ( V_117 , & V_23 ) ;
V_10 = F_27 ( V_7 , & V_23 , 0 ) ;
if ( V_10 ) {
if ( V_10 -> V_18 != V_18 )
return - V_148 ;
} else
V_10 = F_19 ( V_18 ) ;
return F_82 ( V_10 , & V_23 ) ;
}
static T_9 F_107 ( const struct V_30 * V_18 )
{
return
F_108 ( 4 ) +
F_108 ( sizeof( struct V_1 ) ) +
F_108 ( sizeof( struct V_1 ) ) +
F_108 ( 4 ) +
F_108 ( 4 ) +
0 ;
}
static int F_109 ( struct V_44 * V_45 , const struct V_30 * V_18 )
{
struct V_6 * V_56 = F_19 ( V_18 ) ;
struct V_22 * V_176 = & V_56 -> V_15 ;
if ( F_110 ( V_45 , V_167 , V_176 -> V_133 ) ||
F_111 ( V_45 , V_168 , sizeof( struct V_1 ) ,
& V_176 -> V_16 ) ||
F_111 ( V_45 , V_169 , sizeof( struct V_1 ) ,
& V_176 -> V_17 ) ||
F_112 ( V_45 , V_170 , V_176 -> V_59 ) ||
F_112 ( V_45 , V_171 , V_176 -> V_96 ) )
goto V_177;
return 0 ;
V_177:
return - V_178 ;
}
static void T_10 F_113 ( struct V_11 * V_12 )
{
int V_24 ;
struct V_6 * V_10 ;
F_114 ( V_179 ) ;
for ( V_24 = 0 ; V_24 < V_180 ; V_24 ++ ) {
V_10 = F_13 ( V_12 -> V_181 [ V_24 ] ) ;
while ( V_10 != NULL ) {
F_105 ( V_10 -> V_18 , & V_179 ) ;
V_10 = F_13 ( V_10 -> V_28 ) ;
}
}
V_10 = F_13 ( V_12 -> V_21 [ 0 ] ) ;
F_105 ( V_10 -> V_18 , & V_179 ) ;
F_115 ( & V_179 ) ;
}
static int T_8 F_116 ( struct V_7 * V_7 )
{
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
struct V_6 * V_10 = NULL ;
int V_32 ;
V_12 -> V_26 [ 0 ] = V_12 -> V_21 ;
V_12 -> V_26 [ 1 ] = V_12 -> V_181 ;
V_32 = - V_164 ;
V_12 -> V_43 = F_25 ( sizeof( struct V_6 ) , L_3 ,
V_38 , V_39 ) ;
if ( ! V_12 -> V_43 )
goto V_182;
F_26 ( V_12 -> V_43 , V_7 ) ;
V_12 -> V_43 -> V_35 = & V_36 ;
V_32 = F_97 ( V_12 -> V_43 ) ;
if ( V_32 < 0 )
goto V_183;
V_32 = F_117 ( V_12 -> V_43 ) ;
if ( V_32 < 0 )
goto V_183;
V_10 = F_19 ( V_12 -> V_43 ) ;
strcpy ( V_10 -> V_15 . V_34 , V_12 -> V_43 -> V_34 ) ;
return 0 ;
V_183:
F_15 ( V_12 -> V_43 ) ;
V_182:
return V_32 ;
}
static void T_10 F_118 ( struct V_7 * V_7 )
{
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
F_119 () ;
F_113 ( V_12 ) ;
F_120 () ;
}
static int T_11 F_121 ( void )
{
const char * V_184 ;
int V_32 ;
V_184 = L_4 ;
V_32 = F_122 ( & V_185 ) ;
if ( V_32 < 0 )
goto V_186;
V_184 = L_5 ;
V_32 = F_123 ( & V_187 , V_119 ) ;
if ( V_32 < 0 )
goto V_188;
V_32 = F_123 ( & V_189 , V_120 ) ;
if ( V_32 < 0 )
goto V_190;
V_32 = F_123 ( & V_191 , V_121 ) ;
if ( V_32 < 0 )
goto V_192;
V_184 = L_6 ;
V_32 = F_124 ( & V_36 ) ;
if ( V_32 < 0 )
goto V_193;
return 0 ;
V_193:
F_125 ( & V_191 , V_121 ) ;
V_192:
F_125 ( & V_189 , V_120 ) ;
V_190:
F_125 ( & V_187 , V_119 ) ;
V_188:
F_126 ( & V_185 ) ;
V_186:
F_127 ( L_7 , V_184 ) ;
return V_32 ;
}
static void T_12 F_128 ( void )
{
F_129 ( & V_36 ) ;
F_125 ( & V_191 , V_121 ) ;
F_125 ( & V_189 , V_120 ) ;
F_125 ( & V_187 , V_119 ) ;
F_126 ( & V_185 ) ;
}
