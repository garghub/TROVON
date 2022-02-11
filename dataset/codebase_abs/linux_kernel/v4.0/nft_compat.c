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
struct V_19 V_20 [ V_21 + 1 ] ,
const struct V_22 * V_23 )
{
void * V_24 = F_4 ( V_18 ) ;
struct V_25 * V_14 = V_18 -> V_26 -> V_20 ;
struct V_27 * V_28 = V_23 -> V_28 ;
int V_29 ;
F_2 ( (struct V_10 * ) & V_23 -> V_12 , V_14 , V_24 ) ;
V_29 = V_14 -> V_14 ( V_28 , & V_23 -> V_12 ) ;
if ( V_23 -> V_12 . V_16 )
V_29 = V_30 ;
switch ( V_29 ) {
case V_31 :
V_20 [ V_32 ] . V_33 = V_34 ;
break;
default:
V_20 [ V_32 ] . V_33 = V_29 ;
break;
}
}
static void F_5 ( const struct V_17 * V_18 ,
struct V_19 V_20 [ V_21 + 1 ] ,
const struct V_22 * V_23 )
{
void * V_24 = F_4 ( V_18 ) ;
struct V_25 * V_14 = V_18 -> V_26 -> V_20 ;
struct V_27 * V_28 = V_23 -> V_28 ;
int V_29 ;
F_2 ( (struct V_10 * ) & V_23 -> V_12 , V_14 , V_24 ) ;
V_29 = V_14 -> V_14 ( V_28 , & V_23 -> V_12 ) ;
if ( V_23 -> V_12 . V_16 )
V_29 = V_30 ;
switch ( V_29 ) {
case V_35 :
V_20 [ V_32 ] . V_33 = V_36 ;
break;
case V_37 :
V_20 [ V_32 ] . V_33 = V_30 ;
break;
case V_38 :
V_20 [ V_32 ] . V_33 = V_34 ;
break;
case V_39 :
V_20 [ V_32 ] . V_33 = V_40 ;
break;
default:
V_20 [ V_32 ] . V_33 = V_29 ;
break;
}
}
static void
F_6 ( struct V_41 * V_11 ,
const struct V_42 * V_43 ,
struct V_25 * V_14 , void * V_24 ,
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
}
V_11 -> V_69 = V_45 ;
V_11 -> V_14 = V_14 ;
V_11 -> V_15 = V_24 ;
if ( V_43 -> V_3 -> V_6 & V_7 ) {
const struct V_4 * V_5 =
V_4 ( V_43 -> V_3 ) ;
const struct V_70 * V_26 = & V_5 -> V_26 [ 0 ] ;
V_11 -> V_71 = 1 << V_26 -> V_72 ;
} else {
V_11 -> V_71 = 0 ;
}
V_11 -> V_52 = V_43 -> V_51 -> V_52 ;
}
static void F_7 ( struct V_25 * V_73 , void * V_74 , void * V_75 )
{
int V_76 ;
memcpy ( V_75 , V_74 , V_73 -> V_77 ) ;
V_76 = F_8 ( V_73 -> V_77 ) - V_73 -> V_77 ;
if ( V_76 > 0 )
memset ( V_75 + V_73 -> V_77 , 0 , V_76 ) ;
}
static int F_9 ( const struct V_78 * V_79 , T_1 * V_46 , bool * V_47 )
{
struct V_78 * V_80 [ V_81 + 1 ] ;
T_2 V_6 ;
int V_82 ;
V_82 = F_10 ( V_80 , V_81 , V_79 ,
V_83 ) ;
if ( V_82 < 0 )
return V_82 ;
if ( ! V_80 [ V_84 ] || ! V_80 [ V_85 ] )
return - V_9 ;
V_6 = F_11 ( F_12 ( V_80 [ V_85 ] ) ) ;
if ( V_6 & ~ V_86 )
return - V_9 ;
if ( V_6 & V_87 )
* V_47 = true ;
* V_46 = F_11 ( F_12 ( V_80 [ V_84 ] ) ) ;
return 0 ;
}
static int
F_13 ( const struct V_42 * V_43 , const struct V_17 * V_18 ,
const struct V_78 * const V_80 [] )
{
void * V_24 = F_4 ( V_18 ) ;
struct V_25 * V_14 = V_18 -> V_26 -> V_20 ;
struct V_41 V_11 ;
T_3 V_88 = F_8 ( F_14 ( V_80 [ V_89 ] ) ) ;
T_1 V_46 = 0 ;
bool V_47 = false ;
union V_44 V_90 = {} ;
int V_29 ;
V_29 = F_1 ( V_14 -> V_49 , V_43 -> V_3 ) ;
if ( V_29 < 0 )
goto V_82;
F_7 ( V_14 , F_15 ( V_80 [ V_89 ] ) , V_24 ) ;
if ( V_43 -> V_91 [ V_92 ] ) {
V_29 = F_9 ( V_43 -> V_91 [ V_92 ] , & V_46 , & V_47 ) ;
if ( V_29 < 0 )
goto V_82;
}
F_6 ( & V_11 , V_43 , V_14 , V_24 , & V_90 , V_46 , V_47 ) ;
V_29 = F_16 ( & V_11 , V_88 , V_46 , V_47 ) ;
if ( V_29 < 0 )
goto V_82;
if ( V_14 -> V_14 == NULL ) {
V_29 = - V_9 ;
goto V_82;
}
return 0 ;
V_82:
F_17 ( V_14 -> V_93 ) ;
return V_29 ;
}
static void
F_18 ( const struct V_42 * V_43 , const struct V_17 * V_18 )
{
struct V_25 * V_14 = V_18 -> V_26 -> V_20 ;
void * V_24 = F_4 ( V_18 ) ;
struct V_94 V_11 ;
V_11 . V_48 = V_43 -> V_48 ;
V_11 . V_14 = V_14 ;
V_11 . V_15 = V_24 ;
V_11 . V_52 = V_43 -> V_51 -> V_52 ;
if ( V_11 . V_14 -> V_95 != NULL )
V_11 . V_14 -> V_95 ( & V_11 ) ;
F_17 ( V_14 -> V_93 ) ;
}
static int F_19 ( struct V_27 * V_28 , const struct V_17 * V_18 )
{
const struct V_25 * V_14 = V_18 -> V_26 -> V_20 ;
void * V_24 = F_4 ( V_18 ) ;
if ( F_20 ( V_28 , V_96 , V_14 -> V_50 ) ||
F_21 ( V_28 , V_97 , F_22 ( V_14 -> V_98 ) ) ||
F_23 ( V_28 , V_89 , F_8 ( V_14 -> V_77 ) , V_24 ) )
goto V_99;
return 0 ;
V_99:
return - 1 ;
}
static int F_24 ( const struct V_42 * V_43 ,
const struct V_17 * V_18 ,
const struct V_19 * * V_20 )
{
struct V_25 * V_14 = V_18 -> V_26 -> V_20 ;
unsigned int V_71 = 0 ;
int V_29 ;
if ( V_43 -> V_3 -> V_6 & V_7 ) {
const struct V_4 * V_5 =
V_4 ( V_43 -> V_3 ) ;
const struct V_70 * V_26 = & V_5 -> V_26 [ 0 ] ;
V_71 = 1 << V_26 -> V_72 ;
if ( ! ( V_71 & V_14 -> V_100 ) )
return - V_9 ;
V_29 = F_1 ( V_14 -> V_49 ,
V_43 -> V_3 ) ;
if ( V_29 < 0 )
return V_29 ;
}
return 0 ;
}
static void F_25 ( const struct V_17 * V_18 ,
struct V_19 V_20 [ V_21 + 1 ] ,
const struct V_22 * V_23 )
{
void * V_24 = F_4 ( V_18 ) ;
struct V_101 * V_102 = V_18 -> V_26 -> V_20 ;
struct V_27 * V_28 = V_23 -> V_28 ;
bool V_29 ;
F_2 ( (struct V_10 * ) & V_23 -> V_12 , V_102 , V_24 ) ;
V_29 = V_102 -> V_102 ( V_28 , (struct V_10 * ) & V_23 -> V_12 ) ;
if ( V_23 -> V_12 . V_16 ) {
V_20 [ V_32 ] . V_33 = V_30 ;
return;
}
switch( V_29 ) {
case true :
V_20 [ V_32 ] . V_33 = V_34 ;
break;
case false :
V_20 [ V_32 ] . V_33 = V_103 ;
break;
}
}
static void
F_26 ( struct V_104 * V_11 , const struct V_42 * V_43 ,
struct V_101 * V_102 , void * V_24 ,
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
}
V_11 -> V_69 = V_45 ;
V_11 -> V_102 = V_102 ;
V_11 -> V_105 = V_24 ;
if ( V_43 -> V_3 -> V_6 & V_7 ) {
const struct V_4 * V_5 =
V_4 ( V_43 -> V_3 ) ;
const struct V_70 * V_26 = & V_5 -> V_26 [ 0 ] ;
V_11 -> V_71 = 1 << V_26 -> V_72 ;
} else {
V_11 -> V_71 = 0 ;
}
V_11 -> V_52 = V_43 -> V_51 -> V_52 ;
}
static void F_27 ( struct V_101 * V_106 , void * V_74 , void * V_75 )
{
int V_76 ;
memcpy ( V_75 , V_74 , V_106 -> V_107 ) ;
V_76 = F_8 ( V_106 -> V_107 ) - V_106 -> V_107 ;
if ( V_76 > 0 )
memset ( V_75 + V_106 -> V_107 , 0 , V_76 ) ;
}
static int
F_28 ( const struct V_42 * V_43 , const struct V_17 * V_18 ,
const struct V_78 * const V_80 [] )
{
void * V_24 = F_4 ( V_18 ) ;
struct V_101 * V_102 = V_18 -> V_26 -> V_20 ;
struct V_104 V_11 ;
T_3 V_88 = F_8 ( F_14 ( V_80 [ V_108 ] ) ) ;
T_1 V_46 = 0 ;
bool V_47 = false ;
union V_44 V_90 = {} ;
int V_29 ;
V_29 = F_1 ( V_102 -> V_49 , V_43 -> V_3 ) ;
if ( V_29 < 0 )
goto V_82;
F_27 ( V_102 , F_15 ( V_80 [ V_108 ] ) , V_24 ) ;
if ( V_43 -> V_91 [ V_92 ] ) {
V_29 = F_9 ( V_43 -> V_91 [ V_92 ] , & V_46 , & V_47 ) ;
if ( V_29 < 0 )
goto V_82;
}
F_26 ( & V_11 , V_43 , V_102 , V_24 , & V_90 , V_46 , V_47 ) ;
V_29 = F_29 ( & V_11 , V_88 , V_46 , V_47 ) ;
if ( V_29 < 0 )
goto V_82;
return 0 ;
V_82:
F_17 ( V_102 -> V_93 ) ;
return V_29 ;
}
static void
F_30 ( const struct V_42 * V_43 , const struct V_17 * V_18 )
{
struct V_101 * V_102 = V_18 -> V_26 -> V_20 ;
void * V_24 = F_4 ( V_18 ) ;
struct V_109 V_11 ;
V_11 . V_48 = V_43 -> V_48 ;
V_11 . V_102 = V_102 ;
V_11 . V_105 = V_24 ;
V_11 . V_52 = V_43 -> V_51 -> V_52 ;
if ( V_11 . V_102 -> V_95 != NULL )
V_11 . V_102 -> V_95 ( & V_11 ) ;
F_17 ( V_102 -> V_93 ) ;
}
static int F_31 ( struct V_27 * V_28 , const struct V_17 * V_18 )
{
void * V_24 = F_4 ( V_18 ) ;
struct V_101 * V_102 = V_18 -> V_26 -> V_20 ;
if ( F_20 ( V_28 , V_110 , V_102 -> V_50 ) ||
F_21 ( V_28 , V_111 , F_22 ( V_102 -> V_98 ) ) ||
F_23 ( V_28 , V_108 , F_8 ( V_102 -> V_107 ) , V_24 ) )
goto V_99;
return 0 ;
V_99:
return - 1 ;
}
static int F_32 ( const struct V_42 * V_43 ,
const struct V_17 * V_18 ,
const struct V_19 * * V_20 )
{
struct V_101 * V_102 = V_18 -> V_26 -> V_20 ;
unsigned int V_71 = 0 ;
int V_29 ;
if ( V_43 -> V_3 -> V_6 & V_7 ) {
const struct V_4 * V_5 =
V_4 ( V_43 -> V_3 ) ;
const struct V_70 * V_26 = & V_5 -> V_26 [ 0 ] ;
V_71 = 1 << V_26 -> V_72 ;
if ( ! ( V_71 & V_102 -> V_100 ) )
return - V_9 ;
V_29 = F_1 ( V_102 -> V_49 ,
V_43 -> V_3 ) ;
if ( V_29 < 0 )
return V_29 ;
}
return 0 ;
}
static int
F_33 ( struct V_27 * V_28 , T_2 V_112 , T_2 V_113 , T_2 type ,
int V_114 , T_1 V_52 , const char * V_50 ,
int V_115 , int V_14 )
{
struct V_116 * V_117 ;
struct V_118 * V_119 ;
unsigned int V_6 = V_112 ? V_120 : 0 ;
V_114 |= V_121 << 8 ;
V_117 = F_34 ( V_28 , V_112 , V_113 , V_114 , sizeof( * V_119 ) , V_6 ) ;
if ( V_117 == NULL )
goto V_122;
V_119 = F_35 ( V_117 ) ;
V_119 -> V_123 = V_52 ;
V_119 -> V_124 = V_125 ;
V_119 -> V_126 = 0 ;
if ( F_20 ( V_28 , V_127 , V_50 ) ||
F_21 ( V_28 , V_128 , F_22 ( V_115 ) ) ||
F_21 ( V_28 , V_129 , F_22 ( V_14 ) ) )
goto V_99;
F_36 ( V_28 , V_117 ) ;
return V_28 -> V_130 ;
V_122:
V_99:
F_37 ( V_28 , V_117 ) ;
return - 1 ;
}
static int
F_38 ( struct V_131 * V_132 , struct V_27 * V_28 ,
const struct V_116 * V_117 , const struct V_78 * const V_80 [] )
{
int V_29 = 0 , V_14 ;
struct V_118 * V_119 ;
const char * V_133 ;
const char * V_50 ;
T_2 V_115 ;
struct V_27 * V_134 ;
if ( V_80 [ V_127 ] == NULL ||
V_80 [ V_128 ] == NULL ||
V_80 [ V_129 ] == NULL )
return - V_9 ;
V_50 = F_15 ( V_80 [ V_127 ] ) ;
V_115 = F_11 ( F_12 ( V_80 [ V_128 ] ) ) ;
V_14 = F_11 ( F_12 ( V_80 [ V_129 ] ) ) ;
V_119 = F_35 ( V_117 ) ;
switch( V_119 -> V_123 ) {
case V_53 :
V_133 = L_2 ;
break;
case V_58 :
V_133 = L_3 ;
break;
case V_63 :
V_133 = L_4 ;
break;
default:
F_39 ( L_5 ,
V_119 -> V_123 ) ;
return - V_9 ;
}
F_40 ( F_41 ( V_119 -> V_123 , V_50 ,
V_115 , V_14 , & V_29 ) ,
V_133 , V_50 ) ;
if ( V_29 < 0 )
return V_29 ;
V_134 = F_42 ( V_135 , V_136 ) ;
if ( V_134 == NULL )
return - V_137 ;
if ( F_33 ( V_134 , F_43 ( V_28 ) . V_112 ,
V_117 -> V_138 ,
F_44 ( V_117 -> V_139 ) ,
V_140 ,
V_119 -> V_123 ,
V_50 , V_29 , V_14 ) <= 0 ) {
F_45 ( V_134 ) ;
return - V_141 ;
}
V_29 = F_46 ( V_132 , V_134 , F_43 ( V_28 ) . V_112 ,
V_142 ) ;
if ( V_29 > 0 )
V_29 = 0 ;
return V_29 == - V_143 ? - V_144 : V_29 ;
}
static const struct V_145 *
F_47 ( const struct V_42 * V_43 ,
const struct V_78 * const V_80 [] )
{
struct V_146 * V_147 ;
struct V_101 * V_102 ;
char * V_148 ;
T_4 V_115 , V_52 ;
if ( V_80 [ V_110 ] == NULL ||
V_80 [ V_111 ] == NULL ||
V_80 [ V_108 ] == NULL )
return F_48 ( - V_9 ) ;
V_148 = F_15 ( V_80 [ V_110 ] ) ;
V_115 = F_11 ( F_12 ( V_80 [ V_111 ] ) ) ;
V_52 = V_43 -> V_51 -> V_52 ;
F_49 (nft_match, &nft_match_list, head) {
struct V_101 * V_102 = V_147 -> V_26 . V_20 ;
if ( strcmp ( V_102 -> V_50 , V_148 ) == 0 &&
V_102 -> V_98 == V_115 && V_102 -> V_52 == V_52 ) {
if ( ! F_50 ( V_102 -> V_93 ) )
return F_48 ( - V_149 ) ;
return & V_147 -> V_26 ;
}
}
V_102 = F_51 ( V_52 , V_148 , V_115 ) ;
if ( F_52 ( V_102 ) )
return F_48 ( - V_149 ) ;
V_147 = F_53 ( sizeof( struct V_146 ) , V_136 ) ;
if ( V_147 == NULL )
return F_48 ( - V_137 ) ;
V_147 -> V_26 . type = & V_150 ;
V_147 -> V_26 . V_88 = F_54 ( F_8 ( V_102 -> V_107 ) ) ;
V_147 -> V_26 . V_151 = F_25 ;
V_147 -> V_26 . V_152 = F_28 ;
V_147 -> V_26 . V_95 = F_30 ;
V_147 -> V_26 . V_153 = F_31 ;
V_147 -> V_26 . V_154 = F_32 ;
V_147 -> V_26 . V_20 = V_102 ;
F_55 ( & V_147 -> V_155 , & V_156 ) ;
return & V_147 -> V_26 ;
}
static void F_56 ( void )
{
struct V_146 * V_147 , * V_157 ;
F_57 (nft_match, tmp, &nft_match_list, head)
F_58 ( V_147 ) ;
}
static const struct V_145 *
F_59 ( const struct V_42 * V_43 ,
const struct V_78 * const V_80 [] )
{
struct V_146 * V_158 ;
struct V_25 * V_14 ;
char * V_159 ;
T_4 V_115 , V_52 ;
if ( V_80 [ V_96 ] == NULL ||
V_80 [ V_97 ] == NULL ||
V_80 [ V_89 ] == NULL )
return F_48 ( - V_9 ) ;
V_159 = F_15 ( V_80 [ V_96 ] ) ;
V_115 = F_11 ( F_12 ( V_80 [ V_97 ] ) ) ;
V_52 = V_43 -> V_51 -> V_52 ;
F_49 (nft_target, &nft_target_list, head) {
struct V_25 * V_14 = V_158 -> V_26 . V_20 ;
if ( strcmp ( V_14 -> V_50 , V_159 ) == 0 &&
V_14 -> V_98 == V_115 && V_14 -> V_52 == V_52 ) {
if ( ! F_50 ( V_14 -> V_93 ) )
return F_48 ( - V_149 ) ;
return & V_158 -> V_26 ;
}
}
V_14 = F_60 ( V_52 , V_159 , V_115 ) ;
if ( F_52 ( V_14 ) )
return F_48 ( - V_149 ) ;
V_158 = F_53 ( sizeof( struct V_146 ) , V_136 ) ;
if ( V_158 == NULL )
return F_48 ( - V_137 ) ;
V_158 -> V_26 . type = & V_160 ;
V_158 -> V_26 . V_88 = F_54 ( F_8 ( V_14 -> V_77 ) ) ;
V_158 -> V_26 . V_152 = F_13 ;
V_158 -> V_26 . V_95 = F_18 ;
V_158 -> V_26 . V_153 = F_19 ;
V_158 -> V_26 . V_154 = F_24 ;
V_158 -> V_26 . V_20 = V_14 ;
if ( V_52 == V_63 )
V_158 -> V_26 . V_151 = F_5 ;
else
V_158 -> V_26 . V_151 = F_3 ;
F_55 ( & V_158 -> V_155 , & V_161 ) ;
return & V_158 -> V_26 ;
}
static void F_61 ( void )
{
struct V_146 * V_158 , * V_157 ;
F_57 (nft_target, tmp, &nft_target_list, head)
F_58 ( V_158 ) ;
}
static int T_5 F_62 ( void )
{
int V_29 ;
V_29 = F_63 ( & V_150 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_63 ( & V_160 ) ;
if ( V_29 < 0 )
goto V_162;
V_29 = F_64 ( & V_163 ) ;
if ( V_29 < 0 ) {
F_39 ( L_6 ) ;
goto V_164;
}
F_65 ( L_7 ) ;
return V_29 ;
V_164:
F_66 ( & V_160 ) ;
V_162:
F_66 ( & V_150 ) ;
return V_29 ;
}
static void T_6 F_67 ( void )
{
F_68 ( & V_163 ) ;
F_66 ( & V_160 ) ;
F_66 ( & V_150 ) ;
F_56 () ;
F_61 () ;
}
