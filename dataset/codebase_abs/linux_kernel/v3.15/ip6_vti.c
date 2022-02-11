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
F_6 (ip6n->tnls_r_l[hash]) {
if ( F_7 ( V_9 , & V_10 -> V_14 . V_15 ) &&
F_7 ( V_8 , & V_10 -> V_14 . V_16 ) &&
( V_10 -> V_17 -> V_18 & V_19 ) )
return V_10 ;
}
V_10 = F_8 ( V_12 -> V_20 [ 0 ] ) ;
if ( V_10 && ( V_10 -> V_17 -> V_18 & V_19 ) )
return V_10 ;
return NULL ;
}
static struct V_6 T_2 * *
F_9 ( struct V_11 * V_12 , const struct V_21 * V_22 )
{
const struct V_1 * V_8 = & V_22 -> V_16 ;
const struct V_1 * V_9 = & V_22 -> V_15 ;
unsigned int V_23 = 0 ;
int V_24 = 0 ;
if ( ! F_10 ( V_8 ) || ! F_10 ( V_9 ) ) {
V_24 = 1 ;
V_23 = F_1 ( V_8 , V_9 ) ;
}
return & V_12 -> V_25 [ V_24 ] [ V_23 ] ;
}
static void
F_11 ( struct V_11 * V_12 , struct V_6 * V_10 )
{
struct V_6 T_2 * * V_26 = F_9 ( V_12 , & V_10 -> V_14 ) ;
F_12 ( V_10 -> V_27 , F_13 ( * V_26 ) ) ;
F_12 ( * V_26 , V_10 ) ;
}
static void
F_14 ( struct V_11 * V_12 , struct V_6 * V_10 )
{
struct V_6 T_2 * * V_26 ;
struct V_6 * V_28 ;
for ( V_26 = F_9 ( V_12 , & V_10 -> V_14 ) ;
( V_28 = F_13 ( * V_26 ) ) != NULL ;
V_26 = & V_28 -> V_27 ) {
if ( V_10 == V_28 ) {
F_12 ( * V_26 , V_10 -> V_27 ) ;
break;
}
}
}
static void F_15 ( struct V_29 * V_17 )
{
F_16 ( V_17 -> V_30 ) ;
F_17 ( V_17 ) ;
}
static int F_18 ( struct V_29 * V_17 )
{
struct V_6 * V_10 = F_19 ( V_17 ) ;
struct V_7 * V_7 = F_20 ( V_17 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
int V_31 ;
V_31 = F_21 ( V_17 ) ;
if ( V_31 < 0 )
goto V_32;
V_31 = F_22 ( V_17 ) ;
if ( V_31 < 0 )
goto V_32;
strcpy ( V_10 -> V_14 . V_33 , V_17 -> V_33 ) ;
V_17 -> V_34 = & V_35 ;
F_23 ( V_17 ) ;
F_11 ( V_12 , V_10 ) ;
return 0 ;
V_32:
return V_31 ;
}
static struct V_6 * F_24 ( struct V_7 * V_7 , struct V_21 * V_22 )
{
struct V_29 * V_17 ;
struct V_6 * V_10 ;
char V_33 [ V_36 ] ;
int V_31 ;
if ( V_22 -> V_33 [ 0 ] )
F_25 ( V_33 , V_22 -> V_33 , V_36 ) ;
else
sprintf ( V_33 , L_1 ) ;
V_17 = F_26 ( sizeof( * V_10 ) , V_33 , V_37 ) ;
if ( V_17 == NULL )
goto V_38;
F_27 ( V_17 , V_7 ) ;
V_10 = F_19 ( V_17 ) ;
V_10 -> V_14 = * V_22 ;
V_10 -> V_7 = F_20 ( V_17 ) ;
V_31 = F_18 ( V_17 ) ;
if ( V_31 < 0 )
goto V_39;
return V_10 ;
V_39:
F_15 ( V_17 ) ;
V_38:
return NULL ;
}
static struct V_6 * F_28 ( struct V_7 * V_7 , struct V_21 * V_22 ,
int V_40 )
{
const struct V_1 * V_8 = & V_22 -> V_16 ;
const struct V_1 * V_9 = & V_22 -> V_15 ;
struct V_6 T_2 * * V_26 ;
struct V_6 * V_10 ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
for ( V_26 = F_9 ( V_12 , V_22 ) ;
( V_10 = F_13 ( * V_26 ) ) != NULL ;
V_26 = & V_10 -> V_27 ) {
if ( F_7 ( V_9 , & V_10 -> V_14 . V_15 ) &&
F_7 ( V_8 , & V_10 -> V_14 . V_16 ) )
return V_10 ;
}
if ( ! V_40 )
return NULL ;
return F_24 ( V_7 , V_22 ) ;
}
static void F_29 ( struct V_29 * V_17 )
{
struct V_6 * V_10 = F_19 ( V_17 ) ;
struct V_7 * V_7 = F_20 ( V_17 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
if ( V_17 == V_12 -> V_41 )
F_30 ( V_12 -> V_20 [ 0 ] , NULL ) ;
else
F_14 ( V_12 , V_10 ) ;
F_31 ( V_17 ) ;
}
static int F_32 ( struct V_42 * V_43 )
{
struct V_6 * V_10 ;
const struct V_44 * V_45 = F_33 ( V_43 ) ;
F_34 () ;
if ( ( V_10 = F_4 ( F_20 ( V_43 -> V_17 ) , & V_45 -> V_46 ,
& V_45 -> V_47 ) ) != NULL ) {
if ( V_10 -> V_14 . V_48 != V_49 && V_10 -> V_14 . V_48 != 0 ) {
F_35 () ;
goto V_50;
}
if ( ! F_36 ( NULL , V_51 , V_43 ) ) {
F_35 () ;
return 0 ;
}
if ( ! F_37 ( V_10 , & V_45 -> V_47 , & V_45 -> V_46 ) ) {
V_10 -> V_17 -> V_52 . V_53 ++ ;
F_35 () ;
goto V_50;
}
F_38 ( V_43 ) -> V_54 . V_55 = V_10 ;
V_43 -> V_56 = F_39 ( V_10 -> V_14 . V_57 ) ;
F_35 () ;
return F_40 ( V_43 ) ;
}
F_35 () ;
return - V_58 ;
V_50:
F_41 ( V_43 ) ;
return 0 ;
}
static int F_42 ( struct V_42 * V_43 , int V_31 )
{
unsigned short V_59 ;
struct V_29 * V_17 ;
struct V_60 * V_30 ;
struct V_61 * V_62 ;
struct V_6 * V_10 = F_38 ( V_43 ) -> V_54 . V_55 ;
if ( ! V_10 )
return 1 ;
V_17 = V_10 -> V_17 ;
if ( V_31 ) {
V_17 -> V_52 . V_63 ++ ;
V_17 -> V_52 . V_53 ++ ;
return 0 ;
}
V_62 = F_43 ( V_43 ) ;
V_59 = V_62 -> V_64 -> V_65 -> V_59 ;
if ( ! F_44 ( NULL , V_51 , V_43 , V_59 ) )
return - V_66 ;
F_45 ( V_43 , ! F_46 ( V_10 -> V_7 , F_20 ( V_43 -> V_17 ) ) ) ;
V_43 -> V_17 = V_17 ;
V_30 = F_47 ( V_17 -> V_30 ) ;
F_48 ( & V_30 -> V_67 ) ;
V_30 -> V_68 ++ ;
V_30 -> V_69 += V_43 -> V_70 ;
F_49 ( & V_30 -> V_67 ) ;
return 0 ;
}
static inline bool
F_50 ( const struct V_6 * V_10 , const struct V_44 * V_71 )
{
return F_7 ( & V_10 -> V_14 . V_16 , & V_71 -> V_46 ) ;
}
static bool F_51 ( const struct V_61 * V_62 ,
const struct V_1 * V_72 ,
const struct V_1 * V_73 )
{
T_3 * V_47 = ( T_3 * ) V_72 ;
T_3 * V_46 = ( T_3 * ) V_73 ;
if ( ! V_62 || V_62 -> V_74 . V_75 != V_76 ||
V_62 -> V_74 . V_59 != V_77 )
return false ;
if ( F_10 ( V_72 ) )
return F_52 ( V_46 , & V_62 -> V_74 . V_46 , V_77 ) ;
if ( ! F_53 ( V_62 , V_47 , V_46 , V_77 ) )
return false ;
return true ;
}
static int
F_54 ( struct V_42 * V_43 , struct V_29 * V_17 , struct V_78 * V_79 )
{
struct V_6 * V_10 = F_19 ( V_17 ) ;
struct V_80 * V_52 = & V_10 -> V_17 -> V_52 ;
struct V_81 * V_72 = F_55 ( V_43 ) ;
struct V_29 * V_82 ;
int V_31 = - 1 ;
if ( ! V_72 )
goto V_83;
F_56 ( V_72 ) ;
V_72 = F_57 ( V_10 -> V_7 , V_72 , V_79 , NULL , 0 ) ;
if ( F_58 ( V_72 ) ) {
V_31 = F_59 ( V_72 ) ;
V_72 = NULL ;
goto V_83;
}
if ( ! F_51 ( V_72 -> V_84 , & V_10 -> V_14 . V_16 , & V_10 -> V_14 . V_15 ) )
goto V_83;
V_82 = V_72 -> V_17 ;
if ( V_82 == V_17 ) {
V_52 -> V_85 ++ ;
F_60 ( L_2 ,
V_10 -> V_14 . V_33 ) ;
goto V_86;
}
F_45 ( V_43 , ! F_46 ( V_10 -> V_7 , F_20 ( V_17 ) ) ) ;
F_61 ( V_43 , V_72 ) ;
V_43 -> V_17 = F_55 ( V_43 ) -> V_17 ;
V_31 = F_62 ( V_43 ) ;
if ( F_63 ( V_31 ) == 0 ) {
struct V_60 * V_30 = F_47 ( V_17 -> V_30 ) ;
F_48 ( & V_30 -> V_67 ) ;
V_30 -> V_87 += V_43 -> V_70 ;
V_30 -> V_88 ++ ;
F_49 ( & V_30 -> V_67 ) ;
} else {
V_52 -> V_89 ++ ;
V_52 -> V_90 ++ ;
}
return 0 ;
V_83:
V_52 -> V_91 ++ ;
F_64 ( V_43 ) ;
V_86:
F_65 ( V_72 ) ;
return V_31 ;
}
static T_4
F_66 ( struct V_42 * V_43 , struct V_29 * V_17 )
{
struct V_6 * V_10 = F_19 ( V_17 ) ;
struct V_80 * V_52 = & V_10 -> V_17 -> V_52 ;
struct V_44 * V_45 ;
struct V_78 V_79 ;
int V_92 ;
memset ( & V_79 , 0 , sizeof( V_79 ) ) ;
V_43 -> V_56 = F_39 ( V_10 -> V_14 . V_93 ) ;
switch ( V_43 -> V_94 ) {
case F_67 ( V_95 ) :
V_45 = F_33 ( V_43 ) ;
if ( ( V_10 -> V_14 . V_48 != V_49 && V_10 -> V_14 . V_48 != 0 ) ||
! F_68 ( V_10 ) || F_50 ( V_10 , V_45 ) )
goto V_96;
F_69 ( V_43 , & V_79 , V_77 ) ;
memset ( F_70 ( V_43 ) , 0 , sizeof( * F_70 ( V_43 ) ) ) ;
break;
case F_67 ( V_97 ) :
F_69 ( V_43 , & V_79 , V_98 ) ;
memset ( F_71 ( V_43 ) , 0 , sizeof( * F_71 ( V_43 ) ) ) ;
break;
default:
goto V_96;
}
V_92 = F_54 ( V_43 , V_17 , & V_79 ) ;
if ( V_92 < 0 )
goto V_96;
return V_99 ;
V_96:
V_52 -> V_89 ++ ;
V_52 -> V_100 ++ ;
F_41 ( V_43 ) ;
return V_99 ;
}
static int F_72 ( struct V_42 * V_43 , struct V_101 * V_102 ,
T_5 type , T_5 V_103 , int V_104 , T_6 V_105 )
{
T_6 V_106 ;
T_7 V_56 ;
struct V_61 * V_62 ;
struct V_6 * V_10 ;
struct V_107 * V_108 ;
struct V_109 * V_110 ;
struct V_111 * V_112 ;
struct V_7 * V_7 = F_20 ( V_43 -> V_17 ) ;
const struct V_44 * V_113 = ( const struct V_44 * ) V_43 -> V_114 ;
int V_94 = V_113 -> V_115 ;
V_10 = F_4 ( F_20 ( V_43 -> V_17 ) , & V_113 -> V_47 , & V_113 -> V_46 ) ;
if ( ! V_10 )
return - 1 ;
V_56 = F_39 ( V_10 -> V_14 . V_93 ) ;
switch ( V_94 ) {
case V_116 :
V_108 = (struct V_107 * ) ( V_43 -> V_114 + V_104 ) ;
V_106 = V_108 -> V_106 ;
break;
case V_117 :
V_110 = (struct V_109 * ) ( V_43 -> V_114 + V_104 ) ;
V_106 = V_110 -> V_106 ;
break;
case V_118 :
V_112 = (struct V_111 * ) ( V_43 -> V_114 + V_104 ) ;
V_106 = F_73 ( F_74 ( V_112 -> V_119 ) ) ;
break;
default:
return 0 ;
}
if ( type != V_120 &&
type != V_121 )
return 0 ;
V_62 = F_75 ( V_7 , V_56 , ( const T_3 * ) & V_113 -> V_47 ,
V_106 , V_94 , V_77 ) ;
if ( ! V_62 )
return 0 ;
if ( type == V_121 )
F_76 ( V_43 , V_7 , V_43 -> V_17 -> V_122 , 0 ) ;
else
F_77 ( V_43 , V_7 , V_105 , 0 , 0 ) ;
F_78 ( V_62 ) ;
return 0 ;
}
static void F_79 ( struct V_6 * V_10 )
{
struct V_29 * V_17 = V_10 -> V_17 ;
struct V_21 * V_22 = & V_10 -> V_14 ;
memcpy ( V_17 -> V_123 , & V_22 -> V_15 , sizeof( struct V_1 ) ) ;
memcpy ( V_17 -> V_124 , & V_22 -> V_16 , sizeof( struct V_1 ) ) ;
V_22 -> V_18 &= ~ ( V_125 | V_126 |
V_127 ) ;
V_22 -> V_18 |= F_80 ( V_10 , & V_22 -> V_15 , & V_22 -> V_16 ) ;
if ( V_22 -> V_18 & V_125 && V_22 -> V_18 & V_126 )
V_17 -> V_18 |= V_128 ;
else
V_17 -> V_18 &= ~ V_128 ;
V_17 -> V_129 = V_22 -> V_130 ;
}
static int
F_81 ( struct V_6 * V_10 , const struct V_21 * V_22 )
{
V_10 -> V_14 . V_15 = V_22 -> V_15 ;
V_10 -> V_14 . V_16 = V_22 -> V_16 ;
V_10 -> V_14 . V_130 = V_22 -> V_130 ;
V_10 -> V_14 . V_57 = V_22 -> V_57 ;
V_10 -> V_14 . V_93 = V_22 -> V_93 ;
V_10 -> V_14 . V_48 = V_22 -> V_48 ;
F_82 ( V_10 ) ;
F_79 ( V_10 ) ;
return 0 ;
}
static int F_83 ( struct V_6 * V_10 , struct V_21 * V_22 )
{
struct V_7 * V_7 = F_20 ( V_10 -> V_17 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
int V_31 ;
F_14 ( V_12 , V_10 ) ;
F_84 () ;
V_31 = F_81 ( V_10 , V_22 ) ;
F_11 ( V_12 , V_10 ) ;
F_85 ( V_10 -> V_17 ) ;
return V_31 ;
}
static void
F_86 ( struct V_21 * V_22 , const struct V_131 * V_132 )
{
V_22 -> V_15 = V_132 -> V_15 ;
V_22 -> V_16 = V_132 -> V_16 ;
V_22 -> V_130 = V_132 -> V_130 ;
V_22 -> V_57 = V_132 -> V_57 ;
V_22 -> V_93 = V_132 -> V_93 ;
V_22 -> V_48 = V_132 -> V_48 ;
memcpy ( V_22 -> V_33 , V_132 -> V_33 , sizeof( V_132 -> V_33 ) ) ;
}
static void
F_87 ( struct V_131 * V_132 , const struct V_21 * V_22 )
{
V_132 -> V_15 = V_22 -> V_15 ;
V_132 -> V_16 = V_22 -> V_16 ;
V_132 -> V_130 = V_22 -> V_130 ;
V_132 -> V_57 = V_22 -> V_57 ;
V_132 -> V_93 = V_22 -> V_93 ;
V_132 -> V_48 = V_22 -> V_48 ;
memcpy ( V_132 -> V_33 , V_22 -> V_33 , sizeof( V_132 -> V_33 ) ) ;
}
static int
F_88 ( struct V_29 * V_17 , struct V_133 * V_134 , int V_135 )
{
int V_31 = 0 ;
struct V_131 V_22 ;
struct V_21 V_136 ;
struct V_6 * V_10 = NULL ;
struct V_7 * V_7 = F_20 ( V_17 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
switch ( V_135 ) {
case V_137 :
if ( V_17 == V_12 -> V_41 ) {
if ( F_89 ( & V_22 , V_134 -> V_138 . V_139 , sizeof( V_22 ) ) ) {
V_31 = - V_140 ;
break;
}
F_86 ( & V_136 , & V_22 ) ;
V_10 = F_28 ( V_7 , & V_136 , 0 ) ;
} else {
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
}
if ( V_10 == NULL )
V_10 = F_19 ( V_17 ) ;
F_87 ( & V_22 , & V_10 -> V_14 ) ;
if ( F_90 ( V_134 -> V_138 . V_139 , & V_22 , sizeof( V_22 ) ) )
V_31 = - V_140 ;
break;
case V_141 :
case V_142 :
V_31 = - V_66 ;
if ( ! F_91 ( V_7 -> V_143 , V_144 ) )
break;
V_31 = - V_140 ;
if ( F_89 ( & V_22 , V_134 -> V_138 . V_139 , sizeof( V_22 ) ) )
break;
V_31 = - V_58 ;
if ( V_22 . V_48 != V_49 && V_22 . V_48 != 0 )
break;
F_86 ( & V_136 , & V_22 ) ;
V_10 = F_28 ( V_7 , & V_136 , V_135 == V_141 ) ;
if ( V_17 != V_12 -> V_41 && V_135 == V_142 ) {
if ( V_10 != NULL ) {
if ( V_10 -> V_17 != V_17 ) {
V_31 = - V_145 ;
break;
}
} else
V_10 = F_19 ( V_17 ) ;
V_31 = F_83 ( V_10 , & V_136 ) ;
}
if ( V_10 ) {
V_31 = 0 ;
F_87 ( & V_22 , & V_10 -> V_14 ) ;
if ( F_90 ( V_134 -> V_138 . V_139 , & V_22 , sizeof( V_22 ) ) )
V_31 = - V_140 ;
} else
V_31 = ( V_135 == V_141 ? - V_146 : - V_147 ) ;
break;
case V_148 :
V_31 = - V_66 ;
if ( ! F_91 ( V_7 -> V_143 , V_144 ) )
break;
if ( V_17 == V_12 -> V_41 ) {
V_31 = - V_140 ;
if ( F_89 ( & V_22 , V_134 -> V_138 . V_139 , sizeof( V_22 ) ) )
break;
V_31 = - V_147 ;
F_86 ( & V_136 , & V_22 ) ;
V_10 = F_28 ( V_7 , & V_136 , 0 ) ;
if ( V_10 == NULL )
break;
V_31 = - V_66 ;
if ( V_10 -> V_17 == V_12 -> V_41 )
break;
V_17 = V_10 -> V_17 ;
}
V_31 = 0 ;
F_92 ( V_17 ) ;
break;
default:
V_31 = - V_58 ;
}
return V_31 ;
}
static int F_93 ( struct V_29 * V_17 , int V_149 )
{
if ( V_149 < V_150 )
return - V_58 ;
V_17 -> V_151 = V_149 ;
return 0 ;
}
static void V_37 ( struct V_29 * V_17 )
{
struct V_6 * V_10 ;
V_17 -> V_152 = & V_153 ;
V_17 -> V_154 = F_15 ;
V_17 -> type = V_155 ;
V_17 -> V_156 = V_157 + sizeof( struct V_44 ) ;
V_17 -> V_151 = V_158 ;
V_10 = F_19 ( V_17 ) ;
V_17 -> V_18 |= V_159 ;
V_17 -> V_160 = sizeof( struct V_1 ) ;
V_17 -> V_161 &= ~ V_162 ;
}
static inline int F_94 ( struct V_29 * V_17 )
{
struct V_6 * V_10 = F_19 ( V_17 ) ;
V_10 -> V_17 = V_17 ;
V_10 -> V_7 = F_20 ( V_17 ) ;
V_17 -> V_30 = F_95 ( struct V_60 ) ;
if ( ! V_17 -> V_30 )
return - V_163 ;
return 0 ;
}
static int F_21 ( struct V_29 * V_17 )
{
struct V_6 * V_10 = F_19 ( V_17 ) ;
int V_31 = F_94 ( V_17 ) ;
if ( V_31 )
return V_31 ;
F_79 ( V_10 ) ;
return 0 ;
}
static int T_8 F_96 ( struct V_29 * V_17 )
{
struct V_6 * V_10 = F_19 ( V_17 ) ;
struct V_7 * V_7 = F_20 ( V_17 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
int V_31 = F_94 ( V_17 ) ;
if ( V_31 )
return V_31 ;
V_10 -> V_14 . V_48 = V_49 ;
F_23 ( V_17 ) ;
F_79 ( V_10 ) ;
F_12 ( V_12 -> V_20 [ 0 ] , V_10 ) ;
return 0 ;
}
static int F_97 ( struct V_164 * V_165 [] , struct V_164 * V_114 [] )
{
return 0 ;
}
static void F_98 ( struct V_164 * V_114 [] ,
struct V_21 * V_14 )
{
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
if ( ! V_114 )
return;
if ( V_114 [ V_166 ] )
V_14 -> V_130 = F_99 ( V_114 [ V_166 ] ) ;
if ( V_114 [ V_167 ] )
F_100 ( & V_14 -> V_15 , V_114 [ V_167 ] ,
sizeof( struct V_1 ) ) ;
if ( V_114 [ V_168 ] )
F_100 ( & V_14 -> V_16 , V_114 [ V_168 ] ,
sizeof( struct V_1 ) ) ;
if ( V_114 [ V_169 ] )
V_14 -> V_57 = F_101 ( V_114 [ V_169 ] ) ;
if ( V_114 [ V_170 ] )
V_14 -> V_93 = F_101 ( V_114 [ V_170 ] ) ;
}
static int F_102 ( struct V_7 * V_171 , struct V_29 * V_17 ,
struct V_164 * V_165 [] , struct V_164 * V_114 [] )
{
struct V_7 * V_7 = F_20 ( V_17 ) ;
struct V_6 * V_172 ;
V_172 = F_19 ( V_17 ) ;
F_98 ( V_114 , & V_172 -> V_14 ) ;
V_172 -> V_14 . V_48 = V_49 ;
if ( F_28 ( V_7 , & V_172 -> V_14 , 0 ) )
return - V_145 ;
return F_18 ( V_17 ) ;
}
static int F_103 ( struct V_29 * V_17 , struct V_164 * V_165 [] ,
struct V_164 * V_114 [] )
{
struct V_6 * V_10 ;
struct V_21 V_22 ;
struct V_7 * V_7 = F_20 ( V_17 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
if ( V_17 == V_12 -> V_41 )
return - V_58 ;
F_98 ( V_114 , & V_22 ) ;
V_10 = F_28 ( V_7 , & V_22 , 0 ) ;
if ( V_10 ) {
if ( V_10 -> V_17 != V_17 )
return - V_145 ;
} else
V_10 = F_19 ( V_17 ) ;
return F_83 ( V_10 , & V_22 ) ;
}
static T_9 F_104 ( const struct V_29 * V_17 )
{
return
F_105 ( 4 ) +
F_105 ( sizeof( struct V_1 ) ) +
F_105 ( sizeof( struct V_1 ) ) +
F_105 ( 4 ) +
F_105 ( 4 ) +
0 ;
}
static int F_106 ( struct V_42 * V_43 , const struct V_29 * V_17 )
{
struct V_6 * V_54 = F_19 ( V_17 ) ;
struct V_21 * V_173 = & V_54 -> V_14 ;
if ( F_107 ( V_43 , V_166 , V_173 -> V_130 ) ||
F_108 ( V_43 , V_167 , sizeof( struct V_1 ) ,
& V_173 -> V_15 ) ||
F_108 ( V_43 , V_168 , sizeof( struct V_1 ) ,
& V_173 -> V_16 ) ||
F_109 ( V_43 , V_169 , V_173 -> V_57 ) ||
F_109 ( V_43 , V_170 , V_173 -> V_93 ) )
goto V_174;
return 0 ;
V_174:
return - V_175 ;
}
static void T_10 F_110 ( struct V_11 * V_12 )
{
int V_23 ;
struct V_6 * V_10 ;
F_111 ( V_176 ) ;
for ( V_23 = 0 ; V_23 < V_177 ; V_23 ++ ) {
V_10 = F_13 ( V_12 -> V_178 [ V_23 ] ) ;
while ( V_10 != NULL ) {
F_112 ( V_10 -> V_17 , & V_176 ) ;
V_10 = F_13 ( V_10 -> V_27 ) ;
}
}
V_10 = F_13 ( V_12 -> V_20 [ 0 ] ) ;
F_112 ( V_10 -> V_17 , & V_176 ) ;
F_113 ( & V_176 ) ;
}
static int T_8 F_114 ( struct V_7 * V_7 )
{
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
struct V_6 * V_10 = NULL ;
int V_31 ;
V_12 -> V_25 [ 0 ] = V_12 -> V_20 ;
V_12 -> V_25 [ 1 ] = V_12 -> V_178 ;
V_31 = - V_163 ;
V_12 -> V_41 = F_26 ( sizeof( struct V_6 ) , L_3 ,
V_37 ) ;
if ( ! V_12 -> V_41 )
goto V_179;
F_27 ( V_12 -> V_41 , V_7 ) ;
V_31 = F_96 ( V_12 -> V_41 ) ;
if ( V_31 < 0 )
goto V_180;
V_31 = F_115 ( V_12 -> V_41 ) ;
if ( V_31 < 0 )
goto V_180;
V_10 = F_19 ( V_12 -> V_41 ) ;
strcpy ( V_10 -> V_14 . V_33 , V_12 -> V_41 -> V_33 ) ;
return 0 ;
V_180:
F_15 ( V_12 -> V_41 ) ;
V_179:
return V_31 ;
}
static void T_10 F_116 ( struct V_7 * V_7 )
{
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
F_117 () ;
F_110 ( V_12 ) ;
F_118 () ;
}
static int T_11 F_119 ( void )
{
int V_31 ;
V_31 = F_120 ( & V_181 ) ;
if ( V_31 < 0 )
goto V_182;
V_31 = F_121 ( & V_183 , V_116 ) ;
if ( V_31 < 0 ) {
F_122 ( L_4 , V_184 ) ;
goto V_32;
}
V_31 = F_121 ( & V_185 , V_117 ) ;
if ( V_31 < 0 ) {
F_123 ( & V_183 , V_116 ) ;
F_122 ( L_4 , V_184 ) ;
goto V_32;
}
V_31 = F_121 ( & V_186 , V_118 ) ;
if ( V_31 < 0 ) {
F_123 ( & V_185 , V_117 ) ;
F_123 ( & V_183 , V_116 ) ;
F_122 ( L_4 , V_184 ) ;
goto V_32;
}
V_31 = F_124 ( & V_35 ) ;
if ( V_31 < 0 )
goto V_187;
return 0 ;
V_187:
F_123 ( & V_186 , V_118 ) ;
F_123 ( & V_185 , V_117 ) ;
F_123 ( & V_183 , V_116 ) ;
V_32:
F_125 ( & V_181 ) ;
V_182:
return V_31 ;
}
static void T_12 F_126 ( void )
{
F_127 ( & V_35 ) ;
if ( F_123 ( & V_186 , V_118 ) )
F_128 ( L_5 , V_184 ) ;
if ( F_123 ( & V_185 , V_117 ) )
F_128 ( L_5 , V_184 ) ;
if ( F_123 ( & V_183 , V_116 ) )
F_128 ( L_5 , V_184 ) ;
F_125 ( & V_181 ) ;
}
