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
switch( V_29 ) {
case V_31 :
V_20 [ V_32 ] . V_33 = V_34 ;
break;
default:
V_20 [ V_32 ] . V_33 = V_29 ;
break;
}
return;
}
static void
F_5 ( struct V_35 * V_11 ,
const struct V_36 * V_37 ,
struct V_25 * V_14 , void * V_24 ,
union V_38 * V_39 , T_1 V_40 , bool V_41 )
{
V_11 -> V_42 = V_37 -> V_42 ;
V_11 -> V_43 = V_37 -> V_43 -> V_44 ;
switch ( V_37 -> V_45 -> V_46 ) {
case V_47 :
V_39 -> V_48 . V_49 . V_40 = V_40 ;
V_39 -> V_48 . V_49 . V_50 = V_41 ? V_51 : 0 ;
break;
case V_52 :
V_39 -> V_53 . V_54 . V_40 = V_40 ;
V_39 -> V_53 . V_54 . V_50 = V_41 ? V_55 : 0 ;
break;
}
V_11 -> V_56 = V_39 ;
V_11 -> V_14 = V_14 ;
V_11 -> V_15 = V_24 ;
if ( V_37 -> V_3 -> V_6 & V_7 ) {
const struct V_4 * V_5 =
V_4 ( V_37 -> V_3 ) ;
const struct V_57 * V_26 = & V_5 -> V_26 [ 0 ] ;
V_11 -> V_58 = 1 << V_26 -> V_59 ;
} else {
V_11 -> V_58 = 0 ;
}
V_11 -> V_46 = V_37 -> V_45 -> V_46 ;
}
static void F_6 ( struct V_25 * V_60 , void * V_61 , void * V_62 )
{
int V_63 ;
memcpy ( V_62 , V_61 , V_60 -> V_64 ) ;
V_63 = F_7 ( V_60 -> V_64 ) - V_60 -> V_64 ;
if ( V_63 > 0 )
memset ( V_62 + V_60 -> V_64 , 0 , V_63 ) ;
}
static int F_8 ( const struct V_65 * V_66 , T_1 * V_40 , bool * V_41 )
{
struct V_65 * V_67 [ V_68 + 1 ] ;
T_2 V_6 ;
int V_69 ;
V_69 = F_9 ( V_67 , V_68 , V_66 ,
V_70 ) ;
if ( V_69 < 0 )
return V_69 ;
if ( ! V_67 [ V_71 ] || ! V_67 [ V_72 ] )
return - V_9 ;
V_6 = F_10 ( F_11 ( V_67 [ V_72 ] ) ) ;
if ( V_6 & ~ V_73 )
return - V_9 ;
if ( V_6 & V_74 )
* V_41 = true ;
* V_40 = F_10 ( F_11 ( V_67 [ V_71 ] ) ) ;
return 0 ;
}
static int
F_12 ( const struct V_36 * V_37 , const struct V_17 * V_18 ,
const struct V_65 * const V_67 [] )
{
void * V_24 = F_4 ( V_18 ) ;
struct V_25 * V_14 = V_18 -> V_26 -> V_20 ;
struct V_35 V_11 ;
T_3 V_75 = F_7 ( F_13 ( V_67 [ V_76 ] ) ) ;
T_1 V_40 = 0 ;
bool V_41 = false ;
union V_38 V_77 = {} ;
int V_29 ;
V_29 = F_1 ( V_14 -> V_43 , V_37 -> V_3 ) ;
if ( V_29 < 0 )
goto V_69;
F_6 ( V_14 , F_14 ( V_67 [ V_76 ] ) , V_24 ) ;
if ( V_37 -> V_78 [ V_79 ] ) {
V_29 = F_8 ( V_37 -> V_78 [ V_79 ] , & V_40 , & V_41 ) ;
if ( V_29 < 0 )
goto V_69;
}
F_5 ( & V_11 , V_37 , V_14 , V_24 , & V_77 , V_40 , V_41 ) ;
V_29 = F_15 ( & V_11 , V_75 , V_40 , V_41 ) ;
if ( V_29 < 0 )
goto V_69;
if ( V_14 -> V_14 == NULL ) {
V_29 = - V_9 ;
goto V_69;
}
return 0 ;
V_69:
F_16 ( V_14 -> V_80 ) ;
return V_29 ;
}
static void
F_17 ( const struct V_36 * V_37 , const struct V_17 * V_18 )
{
struct V_25 * V_14 = V_18 -> V_26 -> V_20 ;
void * V_24 = F_4 ( V_18 ) ;
struct V_81 V_11 ;
V_11 . V_42 = V_37 -> V_42 ;
V_11 . V_14 = V_14 ;
V_11 . V_15 = V_24 ;
V_11 . V_46 = V_37 -> V_45 -> V_46 ;
if ( V_11 . V_14 -> V_82 != NULL )
V_11 . V_14 -> V_82 ( & V_11 ) ;
F_16 ( V_14 -> V_80 ) ;
}
static int F_18 ( struct V_27 * V_28 , const struct V_17 * V_18 )
{
const struct V_25 * V_14 = V_18 -> V_26 -> V_20 ;
void * V_24 = F_4 ( V_18 ) ;
if ( F_19 ( V_28 , V_83 , V_14 -> V_44 ) ||
F_20 ( V_28 , V_84 , F_21 ( V_14 -> V_85 ) ) ||
F_22 ( V_28 , V_76 , F_7 ( V_14 -> V_64 ) , V_24 ) )
goto V_86;
return 0 ;
V_86:
return - 1 ;
}
static int F_23 ( const struct V_36 * V_37 ,
const struct V_17 * V_18 ,
const struct V_19 * * V_20 )
{
struct V_25 * V_14 = V_18 -> V_26 -> V_20 ;
unsigned int V_58 = 0 ;
int V_29 ;
if ( V_37 -> V_3 -> V_6 & V_7 ) {
const struct V_4 * V_5 =
V_4 ( V_37 -> V_3 ) ;
const struct V_57 * V_26 = & V_5 -> V_26 [ 0 ] ;
V_58 = 1 << V_26 -> V_59 ;
if ( ! ( V_58 & V_14 -> V_87 ) )
return - V_9 ;
V_29 = F_1 ( V_14 -> V_43 ,
V_37 -> V_3 ) ;
if ( V_29 < 0 )
return V_29 ;
}
return 0 ;
}
static void F_24 ( const struct V_17 * V_18 ,
struct V_19 V_20 [ V_21 + 1 ] ,
const struct V_22 * V_23 )
{
void * V_24 = F_4 ( V_18 ) ;
struct V_88 * V_89 = V_18 -> V_26 -> V_20 ;
struct V_27 * V_28 = V_23 -> V_28 ;
bool V_29 ;
F_2 ( (struct V_10 * ) & V_23 -> V_12 , V_89 , V_24 ) ;
V_29 = V_89 -> V_89 ( V_28 , (struct V_10 * ) & V_23 -> V_12 ) ;
if ( V_23 -> V_12 . V_16 ) {
V_20 [ V_32 ] . V_33 = V_30 ;
return;
}
switch( V_29 ) {
case true :
V_20 [ V_32 ] . V_33 = V_34 ;
break;
case false :
V_20 [ V_32 ] . V_33 = V_90 ;
break;
}
}
static void
F_25 ( struct V_91 * V_11 , const struct V_36 * V_37 ,
struct V_88 * V_89 , void * V_24 ,
union V_38 * V_39 , T_1 V_40 , bool V_41 )
{
V_11 -> V_42 = V_37 -> V_42 ;
V_11 -> V_43 = V_37 -> V_43 -> V_44 ;
switch ( V_37 -> V_45 -> V_46 ) {
case V_47 :
V_39 -> V_48 . V_49 . V_40 = V_40 ;
V_39 -> V_48 . V_49 . V_50 = V_41 ? V_51 : 0 ;
break;
case V_52 :
V_39 -> V_53 . V_54 . V_40 = V_40 ;
V_39 -> V_53 . V_54 . V_50 = V_41 ? V_55 : 0 ;
break;
}
V_11 -> V_56 = V_39 ;
V_11 -> V_89 = V_89 ;
V_11 -> V_92 = V_24 ;
if ( V_37 -> V_3 -> V_6 & V_7 ) {
const struct V_4 * V_5 =
V_4 ( V_37 -> V_3 ) ;
const struct V_57 * V_26 = & V_5 -> V_26 [ 0 ] ;
V_11 -> V_58 = 1 << V_26 -> V_59 ;
} else {
V_11 -> V_58 = 0 ;
}
V_11 -> V_46 = V_37 -> V_45 -> V_46 ;
}
static void F_26 ( struct V_88 * V_93 , void * V_61 , void * V_62 )
{
int V_63 ;
memcpy ( V_62 , V_61 , V_93 -> V_94 ) ;
V_63 = F_7 ( V_93 -> V_94 ) - V_93 -> V_94 ;
if ( V_63 > 0 )
memset ( V_62 + V_93 -> V_94 , 0 , V_63 ) ;
}
static int
F_27 ( const struct V_36 * V_37 , const struct V_17 * V_18 ,
const struct V_65 * const V_67 [] )
{
void * V_24 = F_4 ( V_18 ) ;
struct V_88 * V_89 = V_18 -> V_26 -> V_20 ;
struct V_91 V_11 ;
T_3 V_75 = F_7 ( F_13 ( V_67 [ V_95 ] ) ) ;
T_1 V_40 = 0 ;
bool V_41 = false ;
union V_38 V_77 = {} ;
int V_29 ;
V_29 = F_1 ( V_89 -> V_43 , V_37 -> V_3 ) ;
if ( V_29 < 0 )
goto V_69;
F_26 ( V_89 , F_14 ( V_67 [ V_95 ] ) , V_24 ) ;
if ( V_37 -> V_78 [ V_79 ] ) {
V_29 = F_8 ( V_37 -> V_78 [ V_79 ] , & V_40 , & V_41 ) ;
if ( V_29 < 0 )
goto V_69;
}
F_25 ( & V_11 , V_37 , V_89 , V_24 , & V_77 , V_40 , V_41 ) ;
V_29 = F_28 ( & V_11 , V_75 , V_40 , V_41 ) ;
if ( V_29 < 0 )
goto V_69;
return 0 ;
V_69:
F_16 ( V_89 -> V_80 ) ;
return V_29 ;
}
static void
F_29 ( const struct V_36 * V_37 , const struct V_17 * V_18 )
{
struct V_88 * V_89 = V_18 -> V_26 -> V_20 ;
void * V_24 = F_4 ( V_18 ) ;
struct V_96 V_11 ;
V_11 . V_42 = V_37 -> V_42 ;
V_11 . V_89 = V_89 ;
V_11 . V_92 = V_24 ;
V_11 . V_46 = V_37 -> V_45 -> V_46 ;
if ( V_11 . V_89 -> V_82 != NULL )
V_11 . V_89 -> V_82 ( & V_11 ) ;
F_16 ( V_89 -> V_80 ) ;
}
static int F_30 ( struct V_27 * V_28 , const struct V_17 * V_18 )
{
void * V_24 = F_4 ( V_18 ) ;
struct V_88 * V_89 = V_18 -> V_26 -> V_20 ;
if ( F_19 ( V_28 , V_97 , V_89 -> V_44 ) ||
F_20 ( V_28 , V_98 , F_21 ( V_89 -> V_85 ) ) ||
F_22 ( V_28 , V_95 , F_7 ( V_89 -> V_94 ) , V_24 ) )
goto V_86;
return 0 ;
V_86:
return - 1 ;
}
static int F_31 ( const struct V_36 * V_37 ,
const struct V_17 * V_18 ,
const struct V_19 * * V_20 )
{
struct V_88 * V_89 = V_18 -> V_26 -> V_20 ;
unsigned int V_58 = 0 ;
int V_29 ;
if ( V_37 -> V_3 -> V_6 & V_7 ) {
const struct V_4 * V_5 =
V_4 ( V_37 -> V_3 ) ;
const struct V_57 * V_26 = & V_5 -> V_26 [ 0 ] ;
V_58 = 1 << V_26 -> V_59 ;
if ( ! ( V_58 & V_89 -> V_87 ) )
return - V_9 ;
V_29 = F_1 ( V_89 -> V_43 ,
V_37 -> V_3 ) ;
if ( V_29 < 0 )
return V_29 ;
}
return 0 ;
}
static int
F_32 ( struct V_27 * V_28 , T_2 V_99 , T_2 V_100 , T_2 type ,
int V_101 , T_4 V_46 , const char * V_44 ,
int V_102 , int V_14 )
{
struct V_103 * V_104 ;
struct V_105 * V_106 ;
unsigned int V_6 = V_99 ? V_107 : 0 ;
V_101 |= V_108 << 8 ;
V_104 = F_33 ( V_28 , V_99 , V_100 , V_101 , sizeof( * V_106 ) , V_6 ) ;
if ( V_104 == NULL )
goto V_109;
V_106 = F_34 ( V_104 ) ;
V_106 -> V_110 = V_46 ;
V_106 -> V_111 = V_112 ;
V_106 -> V_113 = 0 ;
if ( F_19 ( V_28 , V_114 , V_44 ) ||
F_20 ( V_28 , V_115 , F_21 ( V_102 ) ) ||
F_20 ( V_28 , V_116 , F_21 ( V_14 ) ) )
goto V_86;
F_35 ( V_28 , V_104 ) ;
return V_28 -> V_117 ;
V_109:
V_86:
F_36 ( V_28 , V_104 ) ;
return - 1 ;
}
static int
F_37 ( struct V_118 * V_119 , struct V_27 * V_28 ,
const struct V_103 * V_104 , const struct V_65 * const V_67 [] )
{
int V_29 = 0 , V_14 ;
struct V_105 * V_106 ;
const char * V_120 ;
const char * V_44 ;
T_2 V_102 ;
struct V_27 * V_121 ;
if ( V_67 [ V_114 ] == NULL ||
V_67 [ V_115 ] == NULL ||
V_67 [ V_116 ] == NULL )
return - V_9 ;
V_44 = F_14 ( V_67 [ V_114 ] ) ;
V_102 = F_10 ( F_11 ( V_67 [ V_115 ] ) ) ;
V_14 = F_10 ( F_11 ( V_67 [ V_116 ] ) ) ;
V_106 = F_34 ( V_104 ) ;
switch( V_106 -> V_110 ) {
case V_47 :
V_120 = L_2 ;
break;
case V_52 :
V_120 = L_3 ;
break;
default:
F_38 ( L_4 ,
V_106 -> V_110 ) ;
return - V_9 ;
}
F_39 ( F_40 ( V_106 -> V_110 , V_44 ,
V_102 , V_14 , & V_29 ) ,
V_120 , V_44 ) ;
if ( V_29 < 0 )
return V_29 ;
V_121 = F_41 ( V_122 , V_123 ) ;
if ( V_121 == NULL )
return - V_124 ;
if ( F_32 ( V_121 , F_42 ( V_28 ) . V_99 ,
V_104 -> V_125 ,
F_43 ( V_104 -> V_126 ) ,
V_127 ,
V_106 -> V_110 ,
V_44 , V_29 , V_14 ) <= 0 ) {
F_44 ( V_121 ) ;
return - V_128 ;
}
V_29 = F_45 ( V_119 , V_121 , F_42 ( V_28 ) . V_99 ,
V_129 ) ;
if ( V_29 > 0 )
V_29 = 0 ;
return V_29 == - V_130 ? - V_131 : V_29 ;
}
static const struct V_132 *
F_46 ( const struct V_36 * V_37 ,
const struct V_65 * const V_67 [] )
{
struct V_133 * V_134 ;
struct V_88 * V_89 ;
char * V_135 ;
T_5 V_102 , V_46 ;
if ( V_67 [ V_97 ] == NULL ||
V_67 [ V_98 ] == NULL ||
V_67 [ V_95 ] == NULL )
return F_47 ( - V_9 ) ;
V_135 = F_14 ( V_67 [ V_97 ] ) ;
V_102 = F_10 ( F_11 ( V_67 [ V_98 ] ) ) ;
V_46 = V_37 -> V_45 -> V_46 ;
F_48 (nft_match, &nft_match_list, head) {
struct V_88 * V_89 = V_134 -> V_26 . V_20 ;
if ( strcmp ( V_89 -> V_44 , V_135 ) == 0 &&
V_89 -> V_85 == V_102 && V_89 -> V_46 == V_46 )
return & V_134 -> V_26 ;
}
V_89 = F_49 ( V_46 , V_135 , V_102 ) ;
if ( F_50 ( V_89 ) )
return F_47 ( - V_136 ) ;
V_134 = F_51 ( sizeof( struct V_133 ) , V_123 ) ;
if ( V_134 == NULL )
return F_47 ( - V_124 ) ;
V_134 -> V_26 . type = & V_137 ;
V_134 -> V_26 . V_75 = F_52 ( F_7 ( V_89 -> V_94 ) ) ;
V_134 -> V_26 . V_138 = F_24 ;
V_134 -> V_26 . V_139 = F_27 ;
V_134 -> V_26 . V_82 = F_29 ;
V_134 -> V_26 . V_140 = F_30 ;
V_134 -> V_26 . V_141 = F_31 ;
V_134 -> V_26 . V_20 = V_89 ;
F_53 ( & V_134 -> V_142 , & V_143 ) ;
return & V_134 -> V_26 ;
}
static void F_54 ( void )
{
struct V_133 * V_134 , * V_144 ;
F_55 (nft_match, tmp, &nft_match_list, head)
F_56 ( V_134 ) ;
}
static const struct V_132 *
F_57 ( const struct V_36 * V_37 ,
const struct V_65 * const V_67 [] )
{
struct V_133 * V_145 ;
struct V_25 * V_14 ;
char * V_146 ;
T_5 V_102 , V_46 ;
if ( V_67 [ V_83 ] == NULL ||
V_67 [ V_84 ] == NULL ||
V_67 [ V_76 ] == NULL )
return F_47 ( - V_9 ) ;
V_146 = F_14 ( V_67 [ V_83 ] ) ;
V_102 = F_10 ( F_11 ( V_67 [ V_84 ] ) ) ;
V_46 = V_37 -> V_45 -> V_46 ;
F_48 (nft_target, &nft_target_list, head) {
struct V_25 * V_14 = V_145 -> V_26 . V_20 ;
if ( strcmp ( V_14 -> V_44 , V_146 ) == 0 &&
V_14 -> V_85 == V_102 && V_14 -> V_46 == V_46 )
return & V_145 -> V_26 ;
}
V_14 = F_58 ( V_46 , V_146 , V_102 ) ;
if ( F_50 ( V_14 ) )
return F_47 ( - V_136 ) ;
V_145 = F_51 ( sizeof( struct V_133 ) , V_123 ) ;
if ( V_145 == NULL )
return F_47 ( - V_124 ) ;
V_145 -> V_26 . type = & V_147 ;
V_145 -> V_26 . V_75 = F_52 ( F_7 ( V_14 -> V_64 ) ) ;
V_145 -> V_26 . V_138 = F_3 ;
V_145 -> V_26 . V_139 = F_12 ;
V_145 -> V_26 . V_82 = F_17 ;
V_145 -> V_26 . V_140 = F_18 ;
V_145 -> V_26 . V_141 = F_23 ;
V_145 -> V_26 . V_20 = V_14 ;
F_53 ( & V_145 -> V_142 , & V_148 ) ;
return & V_145 -> V_26 ;
}
static void F_59 ( void )
{
struct V_133 * V_145 , * V_144 ;
F_55 (nft_target, tmp, &nft_target_list, head)
F_56 ( V_145 ) ;
}
static int T_6 F_60 ( void )
{
int V_29 ;
V_29 = F_61 ( & V_137 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_61 ( & V_147 ) ;
if ( V_29 < 0 )
goto V_149;
V_29 = F_62 ( & V_150 ) ;
if ( V_29 < 0 ) {
F_38 ( L_5 ) ;
goto V_151;
}
F_63 ( L_6 ) ;
return V_29 ;
V_151:
F_64 ( & V_147 ) ;
V_149:
F_64 ( & V_137 ) ;
return V_29 ;
}
static void T_7 F_65 ( void )
{
F_66 ( & V_150 ) ;
F_64 ( & V_147 ) ;
F_64 ( & V_137 ) ;
F_54 () ;
F_59 () ;
}
