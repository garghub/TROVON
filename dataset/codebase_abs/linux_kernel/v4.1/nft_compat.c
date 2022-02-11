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
}
static void F_7 ( struct V_24 * V_74 , void * V_75 , void * V_76 )
{
int V_77 ;
memcpy ( V_76 , V_75 , V_74 -> V_78 ) ;
V_77 = F_8 ( V_74 -> V_78 ) - V_74 -> V_78 ;
if ( V_77 > 0 )
memset ( V_76 + V_74 -> V_78 , 0 , V_77 ) ;
}
static int F_9 ( const struct V_79 * V_80 , T_1 * V_46 , bool * V_47 )
{
struct V_79 * V_81 [ V_82 + 1 ] ;
T_2 V_6 ;
int V_83 ;
V_83 = F_10 ( V_81 , V_82 , V_80 ,
V_84 ) ;
if ( V_83 < 0 )
return V_83 ;
if ( ! V_81 [ V_85 ] || ! V_81 [ V_86 ] )
return - V_9 ;
V_6 = F_11 ( F_12 ( V_81 [ V_86 ] ) ) ;
if ( V_6 & ~ V_87 )
return - V_9 ;
if ( V_6 & V_88 )
* V_47 = true ;
* V_46 = F_11 ( F_12 ( V_81 [ V_85 ] ) ) ;
return 0 ;
}
static int
F_13 ( const struct V_42 * V_43 , const struct V_17 * V_18 ,
const struct V_79 * const V_81 [] )
{
void * V_23 = F_4 ( V_18 ) ;
struct V_24 * V_14 = V_18 -> V_25 -> V_26 ;
struct V_41 V_11 ;
T_3 V_89 = F_8 ( F_14 ( V_81 [ V_90 ] ) ) ;
T_1 V_46 = 0 ;
bool V_47 = false ;
union V_44 V_91 = {} ;
int V_29 ;
V_29 = F_1 ( V_14 -> V_49 , V_43 -> V_3 ) ;
if ( V_29 < 0 )
goto V_83;
F_7 ( V_14 , F_15 ( V_81 [ V_90 ] ) , V_23 ) ;
if ( V_43 -> V_92 [ V_93 ] ) {
V_29 = F_9 ( V_43 -> V_92 [ V_93 ] , & V_46 , & V_47 ) ;
if ( V_29 < 0 )
goto V_83;
}
F_6 ( & V_11 , V_43 , V_14 , V_23 , & V_91 , V_46 , V_47 ) ;
V_29 = F_16 ( & V_11 , V_89 , V_46 , V_47 ) ;
if ( V_29 < 0 )
goto V_83;
if ( V_14 -> V_14 == NULL ) {
V_29 = - V_9 ;
goto V_83;
}
return 0 ;
V_83:
F_17 ( V_14 -> V_94 ) ;
return V_29 ;
}
static void
F_18 ( const struct V_42 * V_43 , const struct V_17 * V_18 )
{
struct V_24 * V_14 = V_18 -> V_25 -> V_26 ;
void * V_23 = F_4 ( V_18 ) ;
struct V_95 V_11 ;
V_11 . V_48 = V_43 -> V_48 ;
V_11 . V_14 = V_14 ;
V_11 . V_15 = V_23 ;
V_11 . V_52 = V_43 -> V_51 -> V_52 ;
if ( V_11 . V_14 -> V_96 != NULL )
V_11 . V_14 -> V_96 ( & V_11 ) ;
F_17 ( V_14 -> V_94 ) ;
}
static int F_19 ( struct V_27 * V_28 , const struct V_17 * V_18 )
{
const struct V_24 * V_14 = V_18 -> V_25 -> V_26 ;
void * V_23 = F_4 ( V_18 ) ;
if ( F_20 ( V_28 , V_97 , V_14 -> V_50 ) ||
F_21 ( V_28 , V_98 , F_22 ( V_14 -> V_99 ) ) ||
F_23 ( V_28 , V_90 , F_8 ( V_14 -> V_78 ) , V_23 ) )
goto V_100;
return 0 ;
V_100:
return - 1 ;
}
static int F_24 ( const struct V_42 * V_43 ,
const struct V_17 * V_18 ,
const struct V_101 * * V_26 )
{
struct V_24 * V_14 = V_18 -> V_25 -> V_26 ;
unsigned int V_72 = 0 ;
int V_29 ;
if ( V_43 -> V_3 -> V_6 & V_7 ) {
const struct V_4 * V_5 =
V_4 ( V_43 -> V_3 ) ;
const struct V_71 * V_25 = & V_5 -> V_25 [ 0 ] ;
V_72 = 1 << V_25 -> V_73 ;
if ( ! ( V_72 & V_14 -> V_102 ) )
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
struct V_103 * V_104 = V_18 -> V_25 -> V_26 ;
struct V_27 * V_28 = V_22 -> V_28 ;
bool V_29 ;
F_2 ( (struct V_10 * ) & V_22 -> V_12 , V_104 , V_23 ) ;
V_29 = V_104 -> V_104 ( V_28 , (struct V_10 * ) & V_22 -> V_12 ) ;
if ( V_22 -> V_12 . V_16 ) {
V_20 -> V_32 . V_33 = V_30 ;
return;
}
switch ( V_29 ? 1 : 0 ) {
case 1 :
V_20 -> V_32 . V_33 = V_34 ;
break;
case 0 :
V_20 -> V_32 . V_33 = V_105 ;
break;
}
}
static void
F_26 ( struct V_106 * V_11 , const struct V_42 * V_43 ,
struct V_103 * V_104 , void * V_23 ,
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
V_11 -> V_104 = V_104 ;
V_11 -> V_107 = V_23 ;
if ( V_43 -> V_3 -> V_6 & V_7 ) {
const struct V_4 * V_5 =
V_4 ( V_43 -> V_3 ) ;
const struct V_71 * V_25 = & V_5 -> V_25 [ 0 ] ;
V_11 -> V_72 = 1 << V_25 -> V_73 ;
} else {
V_11 -> V_72 = 0 ;
}
V_11 -> V_52 = V_43 -> V_51 -> V_52 ;
}
static void F_27 ( struct V_103 * V_108 , void * V_75 , void * V_76 )
{
int V_77 ;
memcpy ( V_76 , V_75 , V_108 -> V_109 ) ;
V_77 = F_8 ( V_108 -> V_109 ) - V_108 -> V_109 ;
if ( V_77 > 0 )
memset ( V_76 + V_108 -> V_109 , 0 , V_77 ) ;
}
static int
F_28 ( const struct V_42 * V_43 , const struct V_17 * V_18 ,
const struct V_79 * const V_81 [] )
{
void * V_23 = F_4 ( V_18 ) ;
struct V_103 * V_104 = V_18 -> V_25 -> V_26 ;
struct V_106 V_11 ;
T_3 V_89 = F_8 ( F_14 ( V_81 [ V_110 ] ) ) ;
T_1 V_46 = 0 ;
bool V_47 = false ;
union V_44 V_91 = {} ;
int V_29 ;
V_29 = F_1 ( V_104 -> V_49 , V_43 -> V_3 ) ;
if ( V_29 < 0 )
goto V_83;
F_27 ( V_104 , F_15 ( V_81 [ V_110 ] ) , V_23 ) ;
if ( V_43 -> V_92 [ V_93 ] ) {
V_29 = F_9 ( V_43 -> V_92 [ V_93 ] , & V_46 , & V_47 ) ;
if ( V_29 < 0 )
goto V_83;
}
F_26 ( & V_11 , V_43 , V_104 , V_23 , & V_91 , V_46 , V_47 ) ;
V_29 = F_29 ( & V_11 , V_89 , V_46 , V_47 ) ;
if ( V_29 < 0 )
goto V_83;
return 0 ;
V_83:
F_17 ( V_104 -> V_94 ) ;
return V_29 ;
}
static void
F_30 ( const struct V_42 * V_43 , const struct V_17 * V_18 )
{
struct V_103 * V_104 = V_18 -> V_25 -> V_26 ;
void * V_23 = F_4 ( V_18 ) ;
struct V_111 V_11 ;
V_11 . V_48 = V_43 -> V_48 ;
V_11 . V_104 = V_104 ;
V_11 . V_107 = V_23 ;
V_11 . V_52 = V_43 -> V_51 -> V_52 ;
if ( V_11 . V_104 -> V_96 != NULL )
V_11 . V_104 -> V_96 ( & V_11 ) ;
F_17 ( V_104 -> V_94 ) ;
}
static int F_31 ( struct V_27 * V_28 , const struct V_17 * V_18 )
{
void * V_23 = F_4 ( V_18 ) ;
struct V_103 * V_104 = V_18 -> V_25 -> V_26 ;
if ( F_20 ( V_28 , V_112 , V_104 -> V_50 ) ||
F_21 ( V_28 , V_113 , F_22 ( V_104 -> V_99 ) ) ||
F_23 ( V_28 , V_110 , F_8 ( V_104 -> V_109 ) , V_23 ) )
goto V_100;
return 0 ;
V_100:
return - 1 ;
}
static int F_32 ( const struct V_42 * V_43 ,
const struct V_17 * V_18 ,
const struct V_101 * * V_26 )
{
struct V_103 * V_104 = V_18 -> V_25 -> V_26 ;
unsigned int V_72 = 0 ;
int V_29 ;
if ( V_43 -> V_3 -> V_6 & V_7 ) {
const struct V_4 * V_5 =
V_4 ( V_43 -> V_3 ) ;
const struct V_71 * V_25 = & V_5 -> V_25 [ 0 ] ;
V_72 = 1 << V_25 -> V_73 ;
if ( ! ( V_72 & V_104 -> V_102 ) )
return - V_9 ;
V_29 = F_1 ( V_104 -> V_49 ,
V_43 -> V_3 ) ;
if ( V_29 < 0 )
return V_29 ;
}
return 0 ;
}
static int
F_33 ( struct V_27 * V_28 , T_2 V_114 , T_2 V_115 , T_2 type ,
int V_116 , T_1 V_52 , const char * V_50 ,
int V_117 , int V_14 )
{
struct V_118 * V_119 ;
struct V_120 * V_121 ;
unsigned int V_6 = V_114 ? V_122 : 0 ;
V_116 |= V_123 << 8 ;
V_119 = F_34 ( V_28 , V_114 , V_115 , V_116 , sizeof( * V_121 ) , V_6 ) ;
if ( V_119 == NULL )
goto V_124;
V_121 = F_35 ( V_119 ) ;
V_121 -> V_125 = V_52 ;
V_121 -> V_126 = V_127 ;
V_121 -> V_128 = 0 ;
if ( F_20 ( V_28 , V_129 , V_50 ) ||
F_21 ( V_28 , V_130 , F_22 ( V_117 ) ) ||
F_21 ( V_28 , V_131 , F_22 ( V_14 ) ) )
goto V_100;
F_36 ( V_28 , V_119 ) ;
return V_28 -> V_132 ;
V_124:
V_100:
F_37 ( V_28 , V_119 ) ;
return - 1 ;
}
static int
F_38 ( struct V_133 * V_134 , struct V_27 * V_28 ,
const struct V_118 * V_119 , const struct V_79 * const V_81 [] )
{
int V_29 = 0 , V_14 ;
struct V_120 * V_121 ;
const char * V_135 ;
const char * V_50 ;
T_2 V_117 ;
struct V_27 * V_136 ;
if ( V_81 [ V_129 ] == NULL ||
V_81 [ V_130 ] == NULL ||
V_81 [ V_131 ] == NULL )
return - V_9 ;
V_50 = F_15 ( V_81 [ V_129 ] ) ;
V_117 = F_11 ( F_12 ( V_81 [ V_130 ] ) ) ;
V_14 = F_11 ( F_12 ( V_81 [ V_131 ] ) ) ;
V_121 = F_35 ( V_119 ) ;
switch( V_121 -> V_125 ) {
case V_53 :
V_135 = L_2 ;
break;
case V_58 :
V_135 = L_3 ;
break;
case V_63 :
V_135 = L_4 ;
break;
case V_69 :
V_135 = L_5 ;
break;
default:
F_39 ( L_6 ,
V_121 -> V_125 ) ;
return - V_9 ;
}
F_40 ( F_41 ( V_121 -> V_125 , V_50 ,
V_117 , V_14 , & V_29 ) ,
V_135 , V_50 ) ;
if ( V_29 < 0 )
return V_29 ;
V_136 = F_42 ( V_137 , V_138 ) ;
if ( V_136 == NULL )
return - V_139 ;
if ( F_33 ( V_136 , F_43 ( V_28 ) . V_114 ,
V_119 -> V_140 ,
F_44 ( V_119 -> V_141 ) ,
V_142 ,
V_121 -> V_125 ,
V_50 , V_29 , V_14 ) <= 0 ) {
F_45 ( V_136 ) ;
return - V_143 ;
}
V_29 = F_46 ( V_134 , V_136 , F_43 ( V_28 ) . V_114 ,
V_144 ) ;
if ( V_29 > 0 )
V_29 = 0 ;
return V_29 == - V_145 ? - V_146 : V_29 ;
}
static const struct V_147 *
F_47 ( const struct V_42 * V_43 ,
const struct V_79 * const V_81 [] )
{
struct V_148 * V_149 ;
struct V_103 * V_104 ;
char * V_150 ;
T_4 V_117 , V_52 ;
if ( V_81 [ V_112 ] == NULL ||
V_81 [ V_113 ] == NULL ||
V_81 [ V_110 ] == NULL )
return F_48 ( - V_9 ) ;
V_150 = F_15 ( V_81 [ V_112 ] ) ;
V_117 = F_11 ( F_12 ( V_81 [ V_113 ] ) ) ;
V_52 = V_43 -> V_51 -> V_52 ;
F_49 (nft_match, &nft_match_list, head) {
struct V_103 * V_104 = V_149 -> V_25 . V_26 ;
if ( strcmp ( V_104 -> V_50 , V_150 ) == 0 &&
V_104 -> V_99 == V_117 && V_104 -> V_52 == V_52 ) {
if ( ! F_50 ( V_104 -> V_94 ) )
return F_48 ( - V_151 ) ;
return & V_149 -> V_25 ;
}
}
V_104 = F_51 ( V_52 , V_150 , V_117 ) ;
if ( F_52 ( V_104 ) )
return F_48 ( - V_151 ) ;
V_149 = F_53 ( sizeof( struct V_148 ) , V_138 ) ;
if ( V_149 == NULL )
return F_48 ( - V_139 ) ;
V_149 -> V_25 . type = & V_152 ;
V_149 -> V_25 . V_89 = F_54 ( F_8 ( V_104 -> V_109 ) ) ;
V_149 -> V_25 . V_153 = F_25 ;
V_149 -> V_25 . V_154 = F_28 ;
V_149 -> V_25 . V_96 = F_30 ;
V_149 -> V_25 . V_155 = F_31 ;
V_149 -> V_25 . V_156 = F_32 ;
V_149 -> V_25 . V_26 = V_104 ;
F_55 ( & V_149 -> V_157 , & V_158 ) ;
return & V_149 -> V_25 ;
}
static void F_56 ( void )
{
struct V_148 * V_149 , * V_159 ;
F_57 (nft_match, tmp, &nft_match_list, head)
F_58 ( V_149 ) ;
}
static const struct V_147 *
F_59 ( const struct V_42 * V_43 ,
const struct V_79 * const V_81 [] )
{
struct V_148 * V_160 ;
struct V_24 * V_14 ;
char * V_161 ;
T_4 V_117 , V_52 ;
if ( V_81 [ V_97 ] == NULL ||
V_81 [ V_98 ] == NULL ||
V_81 [ V_90 ] == NULL )
return F_48 ( - V_9 ) ;
V_161 = F_15 ( V_81 [ V_97 ] ) ;
V_117 = F_11 ( F_12 ( V_81 [ V_98 ] ) ) ;
V_52 = V_43 -> V_51 -> V_52 ;
F_49 (nft_target, &nft_target_list, head) {
struct V_24 * V_14 = V_160 -> V_25 . V_26 ;
if ( strcmp ( V_14 -> V_50 , V_161 ) == 0 &&
V_14 -> V_99 == V_117 && V_14 -> V_52 == V_52 ) {
if ( ! F_50 ( V_14 -> V_94 ) )
return F_48 ( - V_151 ) ;
return & V_160 -> V_25 ;
}
}
V_14 = F_60 ( V_52 , V_161 , V_117 ) ;
if ( F_52 ( V_14 ) )
return F_48 ( - V_151 ) ;
V_160 = F_53 ( sizeof( struct V_148 ) , V_138 ) ;
if ( V_160 == NULL )
return F_48 ( - V_139 ) ;
V_160 -> V_25 . type = & V_162 ;
V_160 -> V_25 . V_89 = F_54 ( F_8 ( V_14 -> V_78 ) ) ;
V_160 -> V_25 . V_154 = F_13 ;
V_160 -> V_25 . V_96 = F_18 ;
V_160 -> V_25 . V_155 = F_19 ;
V_160 -> V_25 . V_156 = F_24 ;
V_160 -> V_25 . V_26 = V_14 ;
if ( V_52 == V_63 )
V_160 -> V_25 . V_153 = F_5 ;
else
V_160 -> V_25 . V_153 = F_3 ;
F_55 ( & V_160 -> V_157 , & V_163 ) ;
return & V_160 -> V_25 ;
}
static void F_61 ( void )
{
struct V_148 * V_160 , * V_159 ;
F_57 (nft_target, tmp, &nft_target_list, head)
F_58 ( V_160 ) ;
}
static int T_5 F_62 ( void )
{
int V_29 ;
V_29 = F_63 ( & V_152 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_63 ( & V_162 ) ;
if ( V_29 < 0 )
goto V_164;
V_29 = F_64 ( & V_165 ) ;
if ( V_29 < 0 ) {
F_39 ( L_7 ) ;
goto V_166;
}
F_65 ( L_8 ) ;
return V_29 ;
V_166:
F_66 ( & V_162 ) ;
V_164:
F_66 ( & V_152 ) ;
return V_29 ;
}
static void T_6 F_67 ( void )
{
F_68 ( & V_165 ) ;
F_66 ( & V_162 ) ;
F_66 ( & V_152 ) ;
F_56 () ;
F_61 () ;
}
