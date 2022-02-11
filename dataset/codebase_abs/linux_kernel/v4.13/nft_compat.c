static void F_1 ( struct V_1 * V_2 )
{
if ( -- V_2 -> V_3 == 0 ) {
F_2 ( & V_2 -> V_4 ) ;
F_3 ( V_2 ) ;
}
}
static int F_4 ( const char * V_5 ,
const struct V_6 * V_7 )
{
const struct V_8 * V_9 ;
if ( ! V_5 ||
! F_5 ( V_7 ) )
return 0 ;
V_9 = V_8 ( V_7 ) ;
if ( strcmp ( V_5 , L_1 ) == 0 &&
V_9 -> type -> type != V_10 )
return - V_11 ;
return 0 ;
}
static inline void
F_6 ( struct V_12 * V_13 , void * V_2 , const void * V_14 )
{
V_13 -> V_15 = V_2 ;
V_13 -> V_16 = V_14 ;
V_13 -> V_17 = false ;
}
static void F_7 ( const struct V_18 * V_19 ,
struct V_20 * V_21 ,
const struct V_22 * V_23 )
{
void * V_24 = F_8 ( V_19 ) ;
struct V_25 * V_15 = V_19 -> V_26 -> V_27 ;
struct V_28 * V_29 = V_23 -> V_29 ;
int V_30 ;
F_6 ( (struct V_12 * ) & V_23 -> V_2 , V_15 , V_24 ) ;
V_30 = V_15 -> V_15 ( V_29 , & V_23 -> V_2 ) ;
if ( V_23 -> V_2 . V_17 )
V_30 = V_31 ;
switch ( V_30 ) {
case V_32 :
V_21 -> V_33 . V_34 = V_35 ;
break;
default:
V_21 -> V_33 . V_34 = V_30 ;
break;
}
}
static void F_9 ( const struct V_18 * V_19 ,
struct V_20 * V_21 ,
const struct V_22 * V_23 )
{
void * V_24 = F_8 ( V_19 ) ;
struct V_25 * V_15 = V_19 -> V_26 -> V_27 ;
struct V_28 * V_29 = V_23 -> V_29 ;
int V_30 ;
F_6 ( (struct V_12 * ) & V_23 -> V_2 , V_15 , V_24 ) ;
V_30 = V_15 -> V_15 ( V_29 , & V_23 -> V_2 ) ;
if ( V_23 -> V_2 . V_17 )
V_30 = V_31 ;
switch ( V_30 ) {
case V_36 :
V_21 -> V_33 . V_34 = V_37 ;
break;
case V_38 :
V_21 -> V_33 . V_34 = V_31 ;
break;
case V_39 :
V_21 -> V_33 . V_34 = V_35 ;
break;
case V_40 :
V_21 -> V_33 . V_34 = V_41 ;
break;
default:
V_21 -> V_33 . V_34 = V_30 ;
break;
}
}
static void
F_10 ( struct V_42 * V_13 ,
const struct V_43 * V_44 ,
struct V_25 * V_15 , void * V_24 ,
union V_45 * V_46 , T_1 V_47 , bool V_48 )
{
V_13 -> V_49 = V_44 -> V_49 ;
V_13 -> V_50 = V_44 -> V_50 -> V_51 ;
switch ( V_44 -> V_52 -> V_53 ) {
case V_54 :
V_46 -> V_55 . V_56 . V_47 = V_47 ;
V_46 -> V_55 . V_56 . V_57 = V_48 ? V_58 : 0 ;
break;
case V_59 :
if ( V_47 )
V_46 -> V_60 . V_61 . V_62 |= V_63 ;
V_46 -> V_60 . V_61 . V_47 = V_47 ;
V_46 -> V_60 . V_61 . V_57 = V_48 ? V_64 : 0 ;
break;
case V_65 :
V_46 -> V_66 . V_67 = ( V_68 V_69 ) V_47 ;
V_46 -> V_66 . V_57 = V_48 ? V_70 : 0 ;
break;
case V_71 :
break;
}
V_13 -> V_72 = V_46 ;
V_13 -> V_15 = V_15 ;
V_13 -> V_16 = V_24 ;
if ( F_5 ( V_44 -> V_7 ) ) {
const struct V_8 * V_9 =
V_8 ( V_44 -> V_7 ) ;
const struct V_73 * V_26 = & V_9 -> V_26 [ 0 ] ;
V_13 -> V_74 = 1 << V_26 -> V_75 ;
} else {
V_13 -> V_74 = 0 ;
}
V_13 -> V_53 = V_44 -> V_52 -> V_53 ;
V_13 -> V_76 = true ;
}
static void F_11 ( struct V_25 * V_77 , void * V_78 , void * V_79 )
{
int V_80 ;
memcpy ( V_79 , V_78 , V_77 -> V_81 ) ;
V_80 = F_12 ( V_77 -> V_81 ) - V_77 -> V_81 ;
if ( V_80 > 0 )
memset ( V_79 + V_77 -> V_81 , 0 , V_80 ) ;
}
static int F_13 ( const struct V_82 * V_83 , T_1 * V_47 , bool * V_48 )
{
struct V_82 * V_84 [ V_85 + 1 ] ;
T_2 V_62 ;
int V_86 ;
V_86 = F_14 ( V_84 , V_85 , V_83 ,
V_87 , NULL ) ;
if ( V_86 < 0 )
return V_86 ;
if ( ! V_84 [ V_88 ] || ! V_84 [ V_89 ] )
return - V_11 ;
V_62 = F_15 ( F_16 ( V_84 [ V_89 ] ) ) ;
if ( V_62 & ~ V_90 )
return - V_11 ;
if ( V_62 & V_91 )
* V_48 = true ;
* V_47 = F_15 ( F_16 ( V_84 [ V_88 ] ) ) ;
return 0 ;
}
static int
F_17 ( const struct V_43 * V_44 , const struct V_18 * V_19 ,
const struct V_82 * const V_84 [] )
{
void * V_24 = F_8 ( V_19 ) ;
struct V_25 * V_15 = V_19 -> V_26 -> V_27 ;
struct V_42 V_13 ;
T_3 V_92 = F_12 ( F_18 ( V_84 [ V_93 ] ) ) ;
T_1 V_47 = 0 ;
bool V_48 = false ;
union V_45 V_94 = {} ;
int V_30 ;
F_11 ( V_15 , F_19 ( V_84 [ V_93 ] ) , V_24 ) ;
if ( V_44 -> V_95 [ V_96 ] ) {
V_30 = F_13 ( V_44 -> V_95 [ V_96 ] , & V_47 , & V_48 ) ;
if ( V_30 < 0 )
goto V_86;
}
F_10 ( & V_13 , V_44 , V_15 , V_24 , & V_94 , V_47 , V_48 ) ;
V_30 = F_20 ( & V_13 , V_92 , V_47 , V_48 ) ;
if ( V_30 < 0 )
goto V_86;
if ( V_15 -> V_15 == NULL ) {
V_30 = - V_11 ;
goto V_86;
}
return 0 ;
V_86:
F_21 ( V_15 -> V_97 ) ;
return V_30 ;
}
static void
F_22 ( const struct V_43 * V_44 , const struct V_18 * V_19 )
{
struct V_25 * V_15 = V_19 -> V_26 -> V_27 ;
void * V_24 = F_8 ( V_19 ) ;
struct V_98 V_13 ;
V_13 . V_49 = V_44 -> V_49 ;
V_13 . V_15 = V_15 ;
V_13 . V_16 = V_24 ;
V_13 . V_53 = V_44 -> V_52 -> V_53 ;
if ( V_13 . V_15 -> V_99 != NULL )
V_13 . V_15 -> V_99 ( & V_13 ) ;
F_1 ( F_23 ( V_19 -> V_26 , struct V_1 , V_26 ) ) ;
F_21 ( V_15 -> V_97 ) ;
}
static int F_24 ( struct V_28 * V_29 , const struct V_18 * V_19 )
{
const struct V_25 * V_15 = V_19 -> V_26 -> V_27 ;
void * V_24 = F_8 ( V_19 ) ;
if ( F_25 ( V_29 , V_100 , V_15 -> V_51 ) ||
F_26 ( V_29 , V_101 , F_27 ( V_15 -> V_102 ) ) ||
F_28 ( V_29 , V_93 , F_12 ( V_15 -> V_81 ) , V_24 ) )
goto V_103;
return 0 ;
V_103:
return - 1 ;
}
static int F_29 ( const struct V_43 * V_44 ,
const struct V_18 * V_19 ,
const struct V_104 * * V_27 )
{
struct V_25 * V_15 = V_19 -> V_26 -> V_27 ;
unsigned int V_74 = 0 ;
int V_30 ;
if ( F_5 ( V_44 -> V_7 ) ) {
const struct V_8 * V_9 =
V_8 ( V_44 -> V_7 ) ;
const struct V_73 * V_26 = & V_9 -> V_26 [ 0 ] ;
V_74 = 1 << V_26 -> V_75 ;
if ( V_15 -> V_105 && ! ( V_74 & V_15 -> V_105 ) )
return - V_11 ;
V_30 = F_4 ( V_15 -> V_50 ,
V_44 -> V_7 ) ;
if ( V_30 < 0 )
return V_30 ;
}
return 0 ;
}
static void F_30 ( const struct V_18 * V_19 ,
struct V_20 * V_21 ,
const struct V_22 * V_23 )
{
void * V_24 = F_8 ( V_19 ) ;
struct V_106 * V_107 = V_19 -> V_26 -> V_27 ;
struct V_28 * V_29 = V_23 -> V_29 ;
bool V_30 ;
F_6 ( (struct V_12 * ) & V_23 -> V_2 , V_107 , V_24 ) ;
V_30 = V_107 -> V_107 ( V_29 , (struct V_12 * ) & V_23 -> V_2 ) ;
if ( V_23 -> V_2 . V_17 ) {
V_21 -> V_33 . V_34 = V_31 ;
return;
}
switch ( V_30 ? 1 : 0 ) {
case 1 :
V_21 -> V_33 . V_34 = V_35 ;
break;
case 0 :
V_21 -> V_33 . V_34 = V_108 ;
break;
}
}
static void
F_31 ( struct V_109 * V_13 , const struct V_43 * V_44 ,
struct V_106 * V_107 , void * V_24 ,
union V_45 * V_46 , T_1 V_47 , bool V_48 )
{
V_13 -> V_49 = V_44 -> V_49 ;
V_13 -> V_50 = V_44 -> V_50 -> V_51 ;
switch ( V_44 -> V_52 -> V_53 ) {
case V_54 :
V_46 -> V_55 . V_56 . V_47 = V_47 ;
V_46 -> V_55 . V_56 . V_57 = V_48 ? V_58 : 0 ;
break;
case V_59 :
if ( V_47 )
V_46 -> V_60 . V_61 . V_62 |= V_63 ;
V_46 -> V_60 . V_61 . V_47 = V_47 ;
V_46 -> V_60 . V_61 . V_57 = V_48 ? V_64 : 0 ;
break;
case V_65 :
V_46 -> V_66 . V_67 = ( V_68 V_69 ) V_47 ;
V_46 -> V_66 . V_57 = V_48 ? V_70 : 0 ;
break;
case V_71 :
break;
}
V_13 -> V_72 = V_46 ;
V_13 -> V_107 = V_107 ;
V_13 -> V_110 = V_24 ;
if ( F_5 ( V_44 -> V_7 ) ) {
const struct V_8 * V_9 =
V_8 ( V_44 -> V_7 ) ;
const struct V_73 * V_26 = & V_9 -> V_26 [ 0 ] ;
V_13 -> V_74 = 1 << V_26 -> V_75 ;
} else {
V_13 -> V_74 = 0 ;
}
V_13 -> V_53 = V_44 -> V_52 -> V_53 ;
V_13 -> V_76 = true ;
}
static void F_32 ( struct V_106 * V_111 , void * V_78 , void * V_79 )
{
int V_80 ;
memcpy ( V_79 , V_78 , V_111 -> V_112 ) ;
V_80 = F_12 ( V_111 -> V_112 ) - V_111 -> V_112 ;
if ( V_80 > 0 )
memset ( V_79 + V_111 -> V_112 , 0 , V_80 ) ;
}
static int
F_33 ( const struct V_43 * V_44 , const struct V_18 * V_19 ,
const struct V_82 * const V_84 [] )
{
void * V_24 = F_8 ( V_19 ) ;
struct V_106 * V_107 = V_19 -> V_26 -> V_27 ;
struct V_109 V_13 ;
T_3 V_92 = F_12 ( F_18 ( V_84 [ V_113 ] ) ) ;
T_1 V_47 = 0 ;
bool V_48 = false ;
union V_45 V_94 = {} ;
int V_30 ;
F_32 ( V_107 , F_19 ( V_84 [ V_113 ] ) , V_24 ) ;
if ( V_44 -> V_95 [ V_96 ] ) {
V_30 = F_13 ( V_44 -> V_95 [ V_96 ] , & V_47 , & V_48 ) ;
if ( V_30 < 0 )
goto V_86;
}
F_31 ( & V_13 , V_44 , V_107 , V_24 , & V_94 , V_47 , V_48 ) ;
V_30 = F_34 ( & V_13 , V_92 , V_47 , V_48 ) ;
if ( V_30 < 0 )
goto V_86;
return 0 ;
V_86:
F_21 ( V_107 -> V_97 ) ;
return V_30 ;
}
static void
F_35 ( const struct V_43 * V_44 , const struct V_18 * V_19 )
{
struct V_106 * V_107 = V_19 -> V_26 -> V_27 ;
void * V_24 = F_8 ( V_19 ) ;
struct V_114 V_13 ;
V_13 . V_49 = V_44 -> V_49 ;
V_13 . V_107 = V_107 ;
V_13 . V_110 = V_24 ;
V_13 . V_53 = V_44 -> V_52 -> V_53 ;
if ( V_13 . V_107 -> V_99 != NULL )
V_13 . V_107 -> V_99 ( & V_13 ) ;
F_1 ( F_23 ( V_19 -> V_26 , struct V_1 , V_26 ) ) ;
F_21 ( V_107 -> V_97 ) ;
}
static int F_36 ( struct V_28 * V_29 , const struct V_18 * V_19 )
{
void * V_24 = F_8 ( V_19 ) ;
struct V_106 * V_107 = V_19 -> V_26 -> V_27 ;
if ( F_25 ( V_29 , V_115 , V_107 -> V_51 ) ||
F_26 ( V_29 , V_116 , F_27 ( V_107 -> V_102 ) ) ||
F_28 ( V_29 , V_113 , F_12 ( V_107 -> V_112 ) , V_24 ) )
goto V_103;
return 0 ;
V_103:
return - 1 ;
}
static int F_37 ( const struct V_43 * V_44 ,
const struct V_18 * V_19 ,
const struct V_104 * * V_27 )
{
struct V_106 * V_107 = V_19 -> V_26 -> V_27 ;
unsigned int V_74 = 0 ;
int V_30 ;
if ( F_5 ( V_44 -> V_7 ) ) {
const struct V_8 * V_9 =
V_8 ( V_44 -> V_7 ) ;
const struct V_73 * V_26 = & V_9 -> V_26 [ 0 ] ;
V_74 = 1 << V_26 -> V_75 ;
if ( V_107 -> V_105 && ! ( V_74 & V_107 -> V_105 ) )
return - V_11 ;
V_30 = F_4 ( V_107 -> V_50 ,
V_44 -> V_7 ) ;
if ( V_30 < 0 )
return V_30 ;
}
return 0 ;
}
static int
F_38 ( struct V_28 * V_29 , T_2 V_117 , T_2 V_118 , T_2 type ,
int V_119 , T_1 V_53 , const char * V_51 ,
int V_120 , int V_15 )
{
struct V_121 * V_122 ;
struct V_123 * V_124 ;
unsigned int V_62 = V_117 ? V_125 : 0 ;
V_119 = F_39 ( V_126 , V_119 ) ;
V_122 = F_40 ( V_29 , V_117 , V_118 , V_119 , sizeof( * V_124 ) , V_62 ) ;
if ( V_122 == NULL )
goto V_127;
V_124 = F_41 ( V_122 ) ;
V_124 -> V_128 = V_53 ;
V_124 -> V_129 = V_130 ;
V_124 -> V_131 = 0 ;
if ( F_25 ( V_29 , V_132 , V_51 ) ||
F_26 ( V_29 , V_133 , F_27 ( V_120 ) ) ||
F_26 ( V_29 , V_134 , F_27 ( V_15 ) ) )
goto V_103;
F_42 ( V_29 , V_122 ) ;
return V_29 -> V_135 ;
V_127:
V_103:
F_43 ( V_29 , V_122 ) ;
return - 1 ;
}
static int F_44 ( struct V_49 * V_49 , struct V_136 * V_137 ,
struct V_28 * V_29 , const struct V_121 * V_122 ,
const struct V_82 * const V_84 [] ,
struct V_138 * V_139 )
{
int V_30 = 0 , V_15 ;
struct V_123 * V_124 ;
const char * V_140 ;
const char * V_51 ;
T_2 V_120 ;
struct V_28 * V_141 ;
if ( V_84 [ V_132 ] == NULL ||
V_84 [ V_133 ] == NULL ||
V_84 [ V_134 ] == NULL )
return - V_11 ;
V_51 = F_19 ( V_84 [ V_132 ] ) ;
V_120 = F_15 ( F_16 ( V_84 [ V_133 ] ) ) ;
V_15 = F_15 ( F_16 ( V_84 [ V_134 ] ) ) ;
V_124 = F_41 ( V_122 ) ;
switch( V_124 -> V_128 ) {
case V_54 :
V_140 = L_2 ;
break;
case V_59 :
V_140 = L_3 ;
break;
case V_65 :
V_140 = L_4 ;
break;
case V_71 :
V_140 = L_5 ;
break;
default:
F_45 ( L_6 ,
V_124 -> V_128 ) ;
return - V_11 ;
}
F_46 ( F_47 ( V_124 -> V_128 , V_51 ,
V_120 , V_15 , & V_30 ) ,
V_140 , V_51 ) ;
if ( V_30 < 0 )
return V_30 ;
V_141 = F_48 ( V_142 , V_143 ) ;
if ( V_141 == NULL )
return - V_144 ;
if ( F_38 ( V_141 , F_49 ( V_29 ) . V_117 ,
V_122 -> V_145 ,
F_50 ( V_122 -> V_146 ) ,
V_147 ,
V_124 -> V_128 ,
V_51 , V_30 , V_15 ) <= 0 ) {
F_51 ( V_141 ) ;
return - V_148 ;
}
V_30 = F_52 ( V_137 , V_141 , F_49 ( V_29 ) . V_117 ,
V_149 ) ;
if ( V_30 > 0 )
V_30 = 0 ;
return V_30 == - V_150 ? - V_151 : V_30 ;
}
static bool F_53 ( const struct V_106 * V_107 ,
const char * V_51 , T_2 V_120 , T_2 V_53 )
{
return strcmp ( V_107 -> V_51 , V_51 ) == 0 && V_107 -> V_102 == V_120 &&
( V_107 -> V_53 == V_152 || V_107 -> V_53 == V_53 ) ;
}
static const struct V_153 *
F_54 ( const struct V_43 * V_44 ,
const struct V_82 * const V_84 [] )
{
struct V_1 * V_154 ;
struct V_106 * V_107 ;
char * V_155 ;
T_2 V_120 , V_53 ;
int V_86 ;
if ( V_84 [ V_115 ] == NULL ||
V_84 [ V_116 ] == NULL ||
V_84 [ V_113 ] == NULL )
return F_55 ( - V_11 ) ;
V_155 = F_19 ( V_84 [ V_115 ] ) ;
V_120 = F_15 ( F_16 ( V_84 [ V_116 ] ) ) ;
V_53 = V_44 -> V_52 -> V_53 ;
F_56 (nft_match, &nft_match_list, head) {
struct V_106 * V_107 = V_154 -> V_26 . V_27 ;
if ( F_53 ( V_107 , V_155 , V_120 , V_53 ) ) {
if ( ! F_57 ( V_107 -> V_97 ) )
return F_55 ( - V_156 ) ;
V_154 -> V_3 ++ ;
return & V_154 -> V_26 ;
}
}
V_107 = F_58 ( V_53 , V_155 , V_120 ) ;
if ( F_59 ( V_107 ) )
return F_55 ( - V_156 ) ;
if ( V_107 -> V_112 > F_18 ( V_84 [ V_113 ] ) ) {
V_86 = - V_11 ;
goto V_86;
}
V_154 = F_60 ( sizeof( struct V_1 ) , V_143 ) ;
if ( V_154 == NULL ) {
V_86 = - V_144 ;
goto V_86;
}
V_154 -> V_3 = 1 ;
V_154 -> V_26 . type = & V_157 ;
V_154 -> V_26 . V_92 = F_61 ( F_12 ( V_107 -> V_112 ) ) ;
V_154 -> V_26 . V_158 = F_30 ;
V_154 -> V_26 . V_159 = F_33 ;
V_154 -> V_26 . V_99 = F_35 ;
V_154 -> V_26 . V_160 = F_36 ;
V_154 -> V_26 . V_161 = F_37 ;
V_154 -> V_26 . V_27 = V_107 ;
F_62 ( & V_154 -> V_4 , & V_162 ) ;
return & V_154 -> V_26 ;
V_86:
F_21 ( V_107 -> V_97 ) ;
return F_55 ( V_86 ) ;
}
static bool F_63 ( const struct V_25 * V_163 ,
const char * V_51 , T_2 V_120 , T_2 V_53 )
{
return strcmp ( V_163 -> V_51 , V_51 ) == 0 && V_163 -> V_102 == V_120 &&
( V_163 -> V_53 == V_152 || V_163 -> V_53 == V_53 ) ;
}
static const struct V_153 *
F_64 ( const struct V_43 * V_44 ,
const struct V_82 * const V_84 [] )
{
struct V_1 * V_164 ;
struct V_25 * V_15 ;
char * V_165 ;
T_2 V_120 , V_53 ;
int V_86 ;
if ( V_84 [ V_100 ] == NULL ||
V_84 [ V_101 ] == NULL ||
V_84 [ V_93 ] == NULL )
return F_55 ( - V_11 ) ;
V_165 = F_19 ( V_84 [ V_100 ] ) ;
V_120 = F_15 ( F_16 ( V_84 [ V_101 ] ) ) ;
V_53 = V_44 -> V_52 -> V_53 ;
F_56 (nft_target, &nft_target_list, head) {
struct V_25 * V_15 = V_164 -> V_26 . V_27 ;
if ( F_63 ( V_15 , V_165 , V_120 , V_53 ) ) {
if ( ! F_57 ( V_15 -> V_97 ) )
return F_55 ( - V_156 ) ;
V_164 -> V_3 ++ ;
return & V_164 -> V_26 ;
}
}
V_15 = F_65 ( V_53 , V_165 , V_120 ) ;
if ( F_59 ( V_15 ) )
return F_55 ( - V_156 ) ;
if ( V_15 -> V_81 > F_18 ( V_84 [ V_93 ] ) ) {
V_86 = - V_11 ;
goto V_86;
}
V_164 = F_60 ( sizeof( struct V_1 ) , V_143 ) ;
if ( V_164 == NULL ) {
V_86 = - V_144 ;
goto V_86;
}
V_164 -> V_3 = 1 ;
V_164 -> V_26 . type = & V_166 ;
V_164 -> V_26 . V_92 = F_61 ( F_12 ( V_15 -> V_81 ) ) ;
V_164 -> V_26 . V_159 = F_17 ;
V_164 -> V_26 . V_99 = F_22 ;
V_164 -> V_26 . V_160 = F_24 ;
V_164 -> V_26 . V_161 = F_29 ;
V_164 -> V_26 . V_27 = V_15 ;
if ( V_53 == V_65 )
V_164 -> V_26 . V_158 = F_9 ;
else
V_164 -> V_26 . V_158 = F_7 ;
F_62 ( & V_164 -> V_4 , & V_167 ) ;
return & V_164 -> V_26 ;
V_86:
F_21 ( V_15 -> V_97 ) ;
return F_55 ( V_86 ) ;
}
static int T_4 F_66 ( void )
{
int V_30 ;
V_30 = F_67 ( & V_157 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_67 ( & V_166 ) ;
if ( V_30 < 0 )
goto V_168;
V_30 = F_68 ( & V_169 ) ;
if ( V_30 < 0 ) {
F_45 ( L_7 ) ;
goto V_170;
}
F_69 ( L_8 ) ;
return V_30 ;
V_170:
F_70 ( & V_166 ) ;
V_168:
F_70 ( & V_157 ) ;
return V_30 ;
}
static void T_5 F_71 ( void )
{
F_72 ( & V_169 ) ;
F_70 ( & V_166 ) ;
F_70 ( & V_157 ) ;
}
