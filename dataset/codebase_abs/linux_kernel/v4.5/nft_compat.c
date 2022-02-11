static int F_1 ( const char * V_1 ,
const struct V_2 * V_3 )
{
const struct V_4 * V_5 ;
if ( ! V_1 || ! ( V_3 -> V_6 & V_7 ) )
return 0 ;
V_5 = V_4 ( V_3 ) ;
if ( strcmp ( V_1 , L_1 ) == 0 &&
V_5 -> type -> type != V_8 )
return - V_9 ;
return 0 ;
}
static inline void
F_2 ( struct V_10 * V_11 , void * V_12 , const void * V_13 )
{
V_11 -> V_14 = V_12 ;
V_11 -> V_15 = V_13 ;
V_11 -> V_16 = false ;
}
static void F_3 ( const struct V_17 * V_18 ,
struct V_19 * V_20 ,
const struct V_21 * V_22 )
{
void * V_23 = F_4 ( V_18 ) ;
struct V_24 * V_14 = V_18 -> V_25 -> V_26 ;
struct V_27 * V_28 = V_22 -> V_28 ;
int V_29 ;
F_2 ( (struct V_10 * ) & V_22 -> V_12 , V_14 , V_23 ) ;
V_29 = V_14 -> V_14 ( V_28 , & V_22 -> V_12 ) ;
if ( V_22 -> V_12 . V_16 )
V_29 = V_30 ;
switch ( V_29 ) {
case V_31 :
V_20 -> V_32 . V_33 = V_34 ;
break;
default:
V_20 -> V_32 . V_33 = V_29 ;
break;
}
}
static void F_5 ( const struct V_17 * V_18 ,
struct V_19 * V_20 ,
const struct V_21 * V_22 )
{
void * V_23 = F_4 ( V_18 ) ;
struct V_24 * V_14 = V_18 -> V_25 -> V_26 ;
struct V_27 * V_28 = V_22 -> V_28 ;
int V_29 ;
F_2 ( (struct V_10 * ) & V_22 -> V_12 , V_14 , V_23 ) ;
V_29 = V_14 -> V_14 ( V_28 , & V_22 -> V_12 ) ;
if ( V_22 -> V_12 . V_16 )
V_29 = V_30 ;
switch ( V_29 ) {
case V_35 :
V_20 -> V_32 . V_33 = V_36 ;
break;
case V_37 :
V_20 -> V_32 . V_33 = V_30 ;
break;
case V_38 :
V_20 -> V_32 . V_33 = V_34 ;
break;
case V_39 :
V_20 -> V_32 . V_33 = V_40 ;
break;
default:
V_20 -> V_32 . V_33 = V_29 ;
break;
}
}
static void
F_6 ( struct V_41 * V_11 ,
const struct V_42 * V_43 ,
struct V_24 * V_14 , void * V_23 ,
union V_44 * V_45 , T_1 V_46 , bool V_47 )
{
V_11 -> V_48 = V_43 -> V_48 ;
V_11 -> V_49 = V_43 -> V_49 -> V_50 ;
switch ( V_43 -> V_51 -> V_52 ) {
case V_53 :
V_45 -> V_54 . V_55 . V_46 = V_46 ;
V_45 -> V_54 . V_55 . V_56 = V_47 ? V_57 : 0 ;
break;
case V_58 :
if ( V_46 )
V_45 -> V_59 . V_60 . V_6 |= V_61 ;
V_45 -> V_59 . V_60 . V_46 = V_46 ;
V_45 -> V_59 . V_60 . V_56 = V_47 ? V_62 : 0 ;
break;
case V_63 :
V_45 -> V_64 . V_65 = ( V_66 V_67 ) V_46 ;
V_45 -> V_64 . V_56 = V_47 ? V_68 : 0 ;
break;
case V_69 :
break;
}
V_11 -> V_70 = V_45 ;
V_11 -> V_14 = V_14 ;
V_11 -> V_15 = V_23 ;
if ( V_43 -> V_3 -> V_6 & V_7 ) {
const struct V_4 * V_5 =
V_4 ( V_43 -> V_3 ) ;
const struct V_71 * V_25 = & V_5 -> V_25 [ 0 ] ;
V_11 -> V_72 = 1 << V_25 -> V_73 ;
} else {
V_11 -> V_72 = 0 ;
}
V_11 -> V_52 = V_43 -> V_51 -> V_52 ;
V_11 -> V_74 = true ;
}
static void F_7 ( struct V_24 * V_75 , void * V_76 , void * V_77 )
{
int V_78 ;
memcpy ( V_77 , V_76 , V_75 -> V_79 ) ;
V_78 = F_8 ( V_75 -> V_79 ) - V_75 -> V_79 ;
if ( V_78 > 0 )
memset ( V_77 + V_75 -> V_79 , 0 , V_78 ) ;
}
static int F_9 ( const struct V_80 * V_81 , T_1 * V_46 , bool * V_47 )
{
struct V_80 * V_82 [ V_83 + 1 ] ;
T_2 V_6 ;
int V_84 ;
V_84 = F_10 ( V_82 , V_83 , V_81 ,
V_85 ) ;
if ( V_84 < 0 )
return V_84 ;
if ( ! V_82 [ V_86 ] || ! V_82 [ V_87 ] )
return - V_9 ;
V_6 = F_11 ( F_12 ( V_82 [ V_87 ] ) ) ;
if ( V_6 & ~ V_88 )
return - V_9 ;
if ( V_6 & V_89 )
* V_47 = true ;
* V_46 = F_11 ( F_12 ( V_82 [ V_86 ] ) ) ;
return 0 ;
}
static int
F_13 ( const struct V_42 * V_43 , const struct V_17 * V_18 ,
const struct V_80 * const V_82 [] )
{
void * V_23 = F_4 ( V_18 ) ;
struct V_24 * V_14 = V_18 -> V_25 -> V_26 ;
struct V_41 V_11 ;
T_3 V_90 = F_8 ( F_14 ( V_82 [ V_91 ] ) ) ;
T_1 V_46 = 0 ;
bool V_47 = false ;
union V_44 V_92 = {} ;
int V_29 ;
V_29 = F_1 ( V_14 -> V_49 , V_43 -> V_3 ) ;
if ( V_29 < 0 )
goto V_84;
F_7 ( V_14 , F_15 ( V_82 [ V_91 ] ) , V_23 ) ;
if ( V_43 -> V_93 [ V_94 ] ) {
V_29 = F_9 ( V_43 -> V_93 [ V_94 ] , & V_46 , & V_47 ) ;
if ( V_29 < 0 )
goto V_84;
}
F_6 ( & V_11 , V_43 , V_14 , V_23 , & V_92 , V_46 , V_47 ) ;
V_29 = F_16 ( & V_11 , V_90 , V_46 , V_47 ) ;
if ( V_29 < 0 )
goto V_84;
if ( V_14 -> V_14 == NULL ) {
V_29 = - V_9 ;
goto V_84;
}
return 0 ;
V_84:
F_17 ( V_14 -> V_95 ) ;
return V_29 ;
}
static void
F_18 ( const struct V_42 * V_43 , const struct V_17 * V_18 )
{
struct V_24 * V_14 = V_18 -> V_25 -> V_26 ;
void * V_23 = F_4 ( V_18 ) ;
struct V_96 V_11 ;
V_11 . V_48 = V_43 -> V_48 ;
V_11 . V_14 = V_14 ;
V_11 . V_15 = V_23 ;
V_11 . V_52 = V_43 -> V_51 -> V_52 ;
if ( V_11 . V_14 -> V_97 != NULL )
V_11 . V_14 -> V_97 ( & V_11 ) ;
F_17 ( V_14 -> V_95 ) ;
}
static int F_19 ( struct V_27 * V_28 , const struct V_17 * V_18 )
{
const struct V_24 * V_14 = V_18 -> V_25 -> V_26 ;
void * V_23 = F_4 ( V_18 ) ;
if ( F_20 ( V_28 , V_98 , V_14 -> V_50 ) ||
F_21 ( V_28 , V_99 , F_22 ( V_14 -> V_100 ) ) ||
F_23 ( V_28 , V_91 , F_8 ( V_14 -> V_79 ) , V_23 ) )
goto V_101;
return 0 ;
V_101:
return - 1 ;
}
static int F_24 ( const struct V_42 * V_43 ,
const struct V_17 * V_18 ,
const struct V_102 * * V_26 )
{
struct V_24 * V_14 = V_18 -> V_25 -> V_26 ;
unsigned int V_72 = 0 ;
int V_29 ;
if ( V_43 -> V_3 -> V_6 & V_7 ) {
const struct V_4 * V_5 =
V_4 ( V_43 -> V_3 ) ;
const struct V_71 * V_25 = & V_5 -> V_25 [ 0 ] ;
V_72 = 1 << V_25 -> V_73 ;
if ( ! ( V_72 & V_14 -> V_103 ) )
return - V_9 ;
V_29 = F_1 ( V_14 -> V_49 ,
V_43 -> V_3 ) ;
if ( V_29 < 0 )
return V_29 ;
}
return 0 ;
}
static void F_25 ( const struct V_17 * V_18 ,
struct V_19 * V_20 ,
const struct V_21 * V_22 )
{
void * V_23 = F_4 ( V_18 ) ;
struct V_104 * V_105 = V_18 -> V_25 -> V_26 ;
struct V_27 * V_28 = V_22 -> V_28 ;
bool V_29 ;
F_2 ( (struct V_10 * ) & V_22 -> V_12 , V_105 , V_23 ) ;
V_29 = V_105 -> V_105 ( V_28 , (struct V_10 * ) & V_22 -> V_12 ) ;
if ( V_22 -> V_12 . V_16 ) {
V_20 -> V_32 . V_33 = V_30 ;
return;
}
switch ( V_29 ? 1 : 0 ) {
case 1 :
V_20 -> V_32 . V_33 = V_34 ;
break;
case 0 :
V_20 -> V_32 . V_33 = V_106 ;
break;
}
}
static void
F_26 ( struct V_107 * V_11 , const struct V_42 * V_43 ,
struct V_104 * V_105 , void * V_23 ,
union V_44 * V_45 , T_1 V_46 , bool V_47 )
{
V_11 -> V_48 = V_43 -> V_48 ;
V_11 -> V_49 = V_43 -> V_49 -> V_50 ;
switch ( V_43 -> V_51 -> V_52 ) {
case V_53 :
V_45 -> V_54 . V_55 . V_46 = V_46 ;
V_45 -> V_54 . V_55 . V_56 = V_47 ? V_57 : 0 ;
break;
case V_58 :
if ( V_46 )
V_45 -> V_59 . V_60 . V_6 |= V_61 ;
V_45 -> V_59 . V_60 . V_46 = V_46 ;
V_45 -> V_59 . V_60 . V_56 = V_47 ? V_62 : 0 ;
break;
case V_63 :
V_45 -> V_64 . V_65 = ( V_66 V_67 ) V_46 ;
V_45 -> V_64 . V_56 = V_47 ? V_68 : 0 ;
break;
case V_69 :
break;
}
V_11 -> V_70 = V_45 ;
V_11 -> V_105 = V_105 ;
V_11 -> V_108 = V_23 ;
if ( V_43 -> V_3 -> V_6 & V_7 ) {
const struct V_4 * V_5 =
V_4 ( V_43 -> V_3 ) ;
const struct V_71 * V_25 = & V_5 -> V_25 [ 0 ] ;
V_11 -> V_72 = 1 << V_25 -> V_73 ;
} else {
V_11 -> V_72 = 0 ;
}
V_11 -> V_52 = V_43 -> V_51 -> V_52 ;
V_11 -> V_74 = true ;
}
static void F_27 ( struct V_104 * V_109 , void * V_76 , void * V_77 )
{
int V_78 ;
memcpy ( V_77 , V_76 , V_109 -> V_110 ) ;
V_78 = F_8 ( V_109 -> V_110 ) - V_109 -> V_110 ;
if ( V_78 > 0 )
memset ( V_77 + V_109 -> V_110 , 0 , V_78 ) ;
}
static int
F_28 ( const struct V_42 * V_43 , const struct V_17 * V_18 ,
const struct V_80 * const V_82 [] )
{
void * V_23 = F_4 ( V_18 ) ;
struct V_104 * V_105 = V_18 -> V_25 -> V_26 ;
struct V_107 V_11 ;
T_3 V_90 = F_8 ( F_14 ( V_82 [ V_111 ] ) ) ;
T_1 V_46 = 0 ;
bool V_47 = false ;
union V_44 V_92 = {} ;
int V_29 ;
V_29 = F_1 ( V_105 -> V_49 , V_43 -> V_3 ) ;
if ( V_29 < 0 )
goto V_84;
F_27 ( V_105 , F_15 ( V_82 [ V_111 ] ) , V_23 ) ;
if ( V_43 -> V_93 [ V_94 ] ) {
V_29 = F_9 ( V_43 -> V_93 [ V_94 ] , & V_46 , & V_47 ) ;
if ( V_29 < 0 )
goto V_84;
}
F_26 ( & V_11 , V_43 , V_105 , V_23 , & V_92 , V_46 , V_47 ) ;
V_29 = F_29 ( & V_11 , V_90 , V_46 , V_47 ) ;
if ( V_29 < 0 )
goto V_84;
return 0 ;
V_84:
F_17 ( V_105 -> V_95 ) ;
return V_29 ;
}
static void
F_30 ( const struct V_42 * V_43 , const struct V_17 * V_18 )
{
struct V_104 * V_105 = V_18 -> V_25 -> V_26 ;
void * V_23 = F_4 ( V_18 ) ;
struct V_112 V_11 ;
V_11 . V_48 = V_43 -> V_48 ;
V_11 . V_105 = V_105 ;
V_11 . V_108 = V_23 ;
V_11 . V_52 = V_43 -> V_51 -> V_52 ;
if ( V_11 . V_105 -> V_97 != NULL )
V_11 . V_105 -> V_97 ( & V_11 ) ;
F_17 ( V_105 -> V_95 ) ;
}
static int F_31 ( struct V_27 * V_28 , const struct V_17 * V_18 )
{
void * V_23 = F_4 ( V_18 ) ;
struct V_104 * V_105 = V_18 -> V_25 -> V_26 ;
if ( F_20 ( V_28 , V_113 , V_105 -> V_50 ) ||
F_21 ( V_28 , V_114 , F_22 ( V_105 -> V_100 ) ) ||
F_23 ( V_28 , V_111 , F_8 ( V_105 -> V_110 ) , V_23 ) )
goto V_101;
return 0 ;
V_101:
return - 1 ;
}
static int F_32 ( const struct V_42 * V_43 ,
const struct V_17 * V_18 ,
const struct V_102 * * V_26 )
{
struct V_104 * V_105 = V_18 -> V_25 -> V_26 ;
unsigned int V_72 = 0 ;
int V_29 ;
if ( V_43 -> V_3 -> V_6 & V_7 ) {
const struct V_4 * V_5 =
V_4 ( V_43 -> V_3 ) ;
const struct V_71 * V_25 = & V_5 -> V_25 [ 0 ] ;
V_72 = 1 << V_25 -> V_73 ;
if ( ! ( V_72 & V_105 -> V_103 ) )
return - V_9 ;
V_29 = F_1 ( V_105 -> V_49 ,
V_43 -> V_3 ) ;
if ( V_29 < 0 )
return V_29 ;
}
return 0 ;
}
static int
F_33 ( struct V_27 * V_28 , T_2 V_115 , T_2 V_116 , T_2 type ,
int V_117 , T_1 V_52 , const char * V_50 ,
int V_118 , int V_14 )
{
struct V_119 * V_120 ;
struct V_121 * V_122 ;
unsigned int V_6 = V_115 ? V_123 : 0 ;
V_117 |= V_124 << 8 ;
V_120 = F_34 ( V_28 , V_115 , V_116 , V_117 , sizeof( * V_122 ) , V_6 ) ;
if ( V_120 == NULL )
goto V_125;
V_122 = F_35 ( V_120 ) ;
V_122 -> V_126 = V_52 ;
V_122 -> V_127 = V_128 ;
V_122 -> V_129 = 0 ;
if ( F_20 ( V_28 , V_130 , V_50 ) ||
F_21 ( V_28 , V_131 , F_22 ( V_118 ) ) ||
F_21 ( V_28 , V_132 , F_22 ( V_14 ) ) )
goto V_101;
F_36 ( V_28 , V_120 ) ;
return V_28 -> V_133 ;
V_125:
V_101:
F_37 ( V_28 , V_120 ) ;
return - 1 ;
}
static int F_38 ( struct V_48 * V_48 , struct V_134 * V_135 ,
struct V_27 * V_28 , const struct V_119 * V_120 ,
const struct V_80 * const V_82 [] )
{
int V_29 = 0 , V_14 ;
struct V_121 * V_122 ;
const char * V_136 ;
const char * V_50 ;
T_2 V_118 ;
struct V_27 * V_137 ;
if ( V_82 [ V_130 ] == NULL ||
V_82 [ V_131 ] == NULL ||
V_82 [ V_132 ] == NULL )
return - V_9 ;
V_50 = F_15 ( V_82 [ V_130 ] ) ;
V_118 = F_11 ( F_12 ( V_82 [ V_131 ] ) ) ;
V_14 = F_11 ( F_12 ( V_82 [ V_132 ] ) ) ;
V_122 = F_35 ( V_120 ) ;
switch( V_122 -> V_126 ) {
case V_53 :
V_136 = L_2 ;
break;
case V_58 :
V_136 = L_3 ;
break;
case V_63 :
V_136 = L_4 ;
break;
case V_69 :
V_136 = L_5 ;
break;
default:
F_39 ( L_6 ,
V_122 -> V_126 ) ;
return - V_9 ;
}
F_40 ( F_41 ( V_122 -> V_126 , V_50 ,
V_118 , V_14 , & V_29 ) ,
V_136 , V_50 ) ;
if ( V_29 < 0 )
return V_29 ;
V_137 = F_42 ( V_138 , V_139 ) ;
if ( V_137 == NULL )
return - V_140 ;
if ( F_33 ( V_137 , F_43 ( V_28 ) . V_115 ,
V_120 -> V_141 ,
F_44 ( V_120 -> V_142 ) ,
V_143 ,
V_122 -> V_126 ,
V_50 , V_29 , V_14 ) <= 0 ) {
F_45 ( V_137 ) ;
return - V_144 ;
}
V_29 = F_46 ( V_135 , V_137 , F_43 ( V_28 ) . V_115 ,
V_145 ) ;
if ( V_29 > 0 )
V_29 = 0 ;
return V_29 == - V_146 ? - V_147 : V_29 ;
}
static bool F_47 ( const struct V_104 * V_105 ,
const char * V_50 , T_2 V_118 , T_2 V_52 )
{
return strcmp ( V_105 -> V_50 , V_50 ) == 0 && V_105 -> V_100 == V_118 &&
( V_105 -> V_52 == V_148 || V_105 -> V_52 == V_52 ) ;
}
static const struct V_149 *
F_48 ( const struct V_42 * V_43 ,
const struct V_80 * const V_82 [] )
{
struct V_150 * V_151 ;
struct V_104 * V_105 ;
char * V_152 ;
T_2 V_118 , V_52 ;
if ( V_82 [ V_113 ] == NULL ||
V_82 [ V_114 ] == NULL ||
V_82 [ V_111 ] == NULL )
return F_49 ( - V_9 ) ;
V_152 = F_15 ( V_82 [ V_113 ] ) ;
V_118 = F_11 ( F_12 ( V_82 [ V_114 ] ) ) ;
V_52 = V_43 -> V_51 -> V_52 ;
F_50 (nft_match, &nft_match_list, head) {
struct V_104 * V_105 = V_151 -> V_25 . V_26 ;
if ( F_47 ( V_105 , V_152 , V_118 , V_52 ) ) {
if ( ! F_51 ( V_105 -> V_95 ) )
return F_49 ( - V_153 ) ;
return & V_151 -> V_25 ;
}
}
V_105 = F_52 ( V_52 , V_152 , V_118 ) ;
if ( F_53 ( V_105 ) )
return F_49 ( - V_153 ) ;
V_151 = F_54 ( sizeof( struct V_150 ) , V_139 ) ;
if ( V_151 == NULL )
return F_49 ( - V_140 ) ;
V_151 -> V_25 . type = & V_154 ;
V_151 -> V_25 . V_90 = F_55 ( F_8 ( V_105 -> V_110 ) ) ;
V_151 -> V_25 . V_155 = F_25 ;
V_151 -> V_25 . V_156 = F_28 ;
V_151 -> V_25 . V_97 = F_30 ;
V_151 -> V_25 . V_157 = F_31 ;
V_151 -> V_25 . V_158 = F_32 ;
V_151 -> V_25 . V_26 = V_105 ;
F_56 ( & V_151 -> V_159 , & V_160 ) ;
return & V_151 -> V_25 ;
}
static void F_57 ( void )
{
struct V_150 * V_151 , * V_161 ;
F_58 (nft_match, tmp, &nft_match_list, head)
F_59 ( V_151 ) ;
}
static bool F_60 ( const struct V_24 * V_162 ,
const char * V_50 , T_2 V_118 , T_2 V_52 )
{
return strcmp ( V_162 -> V_50 , V_50 ) == 0 && V_162 -> V_100 == V_118 &&
( V_162 -> V_52 == V_148 || V_162 -> V_52 == V_52 ) ;
}
static const struct V_149 *
F_61 ( const struct V_42 * V_43 ,
const struct V_80 * const V_82 [] )
{
struct V_150 * V_163 ;
struct V_24 * V_14 ;
char * V_164 ;
T_2 V_118 , V_52 ;
if ( V_82 [ V_98 ] == NULL ||
V_82 [ V_99 ] == NULL ||
V_82 [ V_91 ] == NULL )
return F_49 ( - V_9 ) ;
V_164 = F_15 ( V_82 [ V_98 ] ) ;
V_118 = F_11 ( F_12 ( V_82 [ V_99 ] ) ) ;
V_52 = V_43 -> V_51 -> V_52 ;
F_50 (nft_target, &nft_target_list, head) {
struct V_24 * V_14 = V_163 -> V_25 . V_26 ;
if ( F_60 ( V_14 , V_164 , V_118 , V_52 ) ) {
if ( ! F_51 ( V_14 -> V_95 ) )
return F_49 ( - V_153 ) ;
return & V_163 -> V_25 ;
}
}
V_14 = F_62 ( V_52 , V_164 , V_118 ) ;
if ( F_53 ( V_14 ) )
return F_49 ( - V_153 ) ;
V_163 = F_54 ( sizeof( struct V_150 ) , V_139 ) ;
if ( V_163 == NULL )
return F_49 ( - V_140 ) ;
V_163 -> V_25 . type = & V_165 ;
V_163 -> V_25 . V_90 = F_55 ( F_8 ( V_14 -> V_79 ) ) ;
V_163 -> V_25 . V_156 = F_13 ;
V_163 -> V_25 . V_97 = F_18 ;
V_163 -> V_25 . V_157 = F_19 ;
V_163 -> V_25 . V_158 = F_24 ;
V_163 -> V_25 . V_26 = V_14 ;
if ( V_52 == V_63 )
V_163 -> V_25 . V_155 = F_5 ;
else
V_163 -> V_25 . V_155 = F_3 ;
F_56 ( & V_163 -> V_159 , & V_166 ) ;
return & V_163 -> V_25 ;
}
static void F_63 ( void )
{
struct V_150 * V_163 , * V_161 ;
F_58 (nft_target, tmp, &nft_target_list, head)
F_59 ( V_163 ) ;
}
static int T_4 F_64 ( void )
{
int V_29 ;
V_29 = F_65 ( & V_154 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_65 ( & V_165 ) ;
if ( V_29 < 0 )
goto V_167;
V_29 = F_66 ( & V_168 ) ;
if ( V_29 < 0 ) {
F_39 ( L_7 ) ;
goto V_169;
}
F_67 ( L_8 ) ;
return V_29 ;
V_169:
F_68 ( & V_165 ) ;
V_167:
F_68 ( & V_154 ) ;
return V_29 ;
}
static void T_5 F_69 ( void )
{
F_70 ( & V_168 ) ;
F_68 ( & V_165 ) ;
F_68 ( & V_154 ) ;
F_57 () ;
F_63 () ;
}
