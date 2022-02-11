static inline void
F_1 ( struct V_1 * V_2 , void * V_3 , const void * V_4 )
{
V_2 -> V_5 = V_3 ;
V_2 -> V_6 = V_4 ;
V_2 -> V_7 = false ;
}
static void F_2 ( const struct V_8 * V_9 ,
struct V_10 V_11 [ V_12 + 1 ] ,
const struct V_13 * V_14 )
{
void * V_15 = F_3 ( V_9 ) ;
struct V_16 * V_5 = V_9 -> V_17 -> V_11 ;
struct V_18 * V_19 = V_14 -> V_19 ;
int V_20 ;
F_1 ( (struct V_1 * ) & V_14 -> V_3 , V_5 , V_15 ) ;
V_20 = V_5 -> V_5 ( V_19 , & V_14 -> V_3 ) ;
if ( V_14 -> V_3 . V_7 )
V_20 = V_21 ;
switch( V_20 ) {
case V_22 :
V_11 [ V_23 ] . V_24 = V_25 ;
break;
default:
V_11 [ V_23 ] . V_24 = V_20 ;
break;
}
return;
}
static void
F_4 ( struct V_26 * V_2 ,
const struct V_27 * V_28 ,
struct V_16 * V_5 , void * V_15 ,
union V_29 * V_30 , T_1 V_31 , bool V_32 )
{
V_2 -> V_33 = & V_34 ;
V_2 -> V_35 = V_28 -> V_35 -> V_36 ;
switch ( V_28 -> V_37 -> V_38 ) {
case V_39 :
V_30 -> V_40 . V_41 . V_31 = V_31 ;
V_30 -> V_40 . V_41 . V_42 = V_32 ? V_43 : 0 ;
break;
case V_44 :
V_30 -> V_45 . V_46 . V_31 = V_31 ;
V_30 -> V_45 . V_46 . V_42 = V_32 ? V_47 : 0 ;
break;
}
V_2 -> V_48 = V_30 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = V_15 ;
if ( V_28 -> V_49 -> V_50 & V_51 ) {
const struct V_52 * V_53 =
V_52 ( V_28 -> V_49 ) ;
const struct V_54 * V_17 = & V_53 -> V_17 ;
V_2 -> V_55 = 1 << V_17 -> V_56 ;
}
V_2 -> V_38 = V_28 -> V_37 -> V_38 ;
}
static void F_5 ( struct V_16 * V_57 , void * V_58 , void * V_59 )
{
#ifdef F_6
if ( V_57 -> V_60 ) {
int V_61 ;
V_57 -> V_60 ( V_59 , V_58 ) ;
V_61 = F_7 ( V_57 -> V_62 ) - V_57 -> V_62 ;
if ( V_61 > 0 )
memset ( V_59 + V_57 -> V_62 , 0 , V_61 ) ;
} else
#endif
memcpy ( V_59 , V_58 , F_7 ( V_57 -> V_62 ) ) ;
}
static inline int F_8 ( struct V_16 * V_5 )
{
#ifdef F_6
return F_9 ( V_5 ) ;
#else
return 0 ;
#endif
}
static int F_10 ( const struct V_63 * V_64 , T_1 * V_31 , bool * V_32 )
{
struct V_63 * V_65 [ V_66 + 1 ] ;
T_2 V_50 ;
int V_67 ;
V_67 = F_11 ( V_65 , V_66 , V_64 ,
V_68 ) ;
if ( V_67 < 0 )
return V_67 ;
if ( ! V_65 [ V_69 ] || ! V_65 [ V_70 ] )
return - V_71 ;
V_50 = F_12 ( F_13 ( V_65 [ V_70 ] ) ) ;
if ( V_50 & ~ V_72 )
return - V_71 ;
if ( V_50 & V_73 )
* V_32 = true ;
* V_31 = F_12 ( F_13 ( V_65 [ V_69 ] ) ) ;
return 0 ;
}
static int
F_14 ( const struct V_27 * V_28 , const struct V_8 * V_9 ,
const struct V_63 * const V_65 [] )
{
void * V_15 = F_3 ( V_9 ) ;
struct V_16 * V_5 = V_9 -> V_17 -> V_11 ;
struct V_26 V_2 ;
T_3 V_74 = F_7 ( F_15 ( V_65 [ V_75 ] ) ) ;
T_1 V_31 = 0 ;
bool V_32 = false ;
union V_29 V_76 = {} ;
int V_20 ;
F_5 ( V_5 , F_16 ( V_65 [ V_75 ] ) , V_15 ) ;
if ( V_28 -> V_77 [ V_78 ] ) {
V_20 = F_10 ( V_28 -> V_77 [ V_78 ] , & V_31 , & V_32 ) ;
if ( V_20 < 0 )
goto V_67;
}
F_4 ( & V_2 , V_28 , V_5 , V_15 , & V_76 , V_31 , V_32 ) ;
V_20 = F_17 ( & V_2 , V_74 , V_31 , V_32 ) ;
if ( V_20 < 0 )
goto V_67;
if ( V_5 -> V_5 == NULL ) {
V_20 = - V_71 ;
goto V_67;
}
return 0 ;
V_67:
F_18 ( V_5 -> V_79 ) ;
return V_20 ;
}
static void
F_19 ( const struct V_8 * V_9 )
{
struct V_16 * V_5 = V_9 -> V_17 -> V_11 ;
F_18 ( V_5 -> V_79 ) ;
}
static int
F_20 ( struct V_18 * V_19 , const struct V_16 * V_57 , const void * V_58 )
{
int V_20 ;
#ifdef F_6
if ( V_57 -> V_80 ) {
T_4 V_81 ;
void * V_59 ;
V_59 = F_21 ( F_7 ( V_57 -> V_62 ) , V_82 ) ;
if ( V_59 == NULL )
return - V_83 ;
V_81 = F_22 () ;
F_23 ( V_84 ) ;
V_57 -> V_80 ( V_59 , V_58 ) ;
F_23 ( V_81 ) ;
V_20 = F_24 ( V_19 , V_75 , F_7 ( V_57 -> V_62 ) , V_59 ) ;
F_25 ( V_59 ) ;
} else
#endif
V_20 = F_24 ( V_19 , V_75 , F_7 ( V_57 -> V_62 ) , V_58 ) ;
return V_20 ;
}
static int F_26 ( struct V_18 * V_19 , const struct V_8 * V_9 )
{
const struct V_16 * V_5 = V_9 -> V_17 -> V_11 ;
void * V_15 = F_3 ( V_9 ) ;
if ( F_27 ( V_19 , V_85 , V_5 -> V_36 ) ||
F_28 ( V_19 , V_86 , F_29 ( V_5 -> V_87 ) ) ||
F_20 ( V_19 , V_5 , V_15 ) )
goto V_88;
return 0 ;
V_88:
return - 1 ;
}
static int F_30 ( const struct V_27 * V_28 ,
const struct V_8 * V_9 ,
const struct V_10 * * V_11 )
{
struct V_16 * V_5 = V_9 -> V_17 -> V_11 ;
unsigned int V_55 = 0 ;
if ( V_28 -> V_49 -> V_50 & V_51 ) {
const struct V_52 * V_53 =
V_52 ( V_28 -> V_49 ) ;
const struct V_54 * V_17 = & V_53 -> V_17 ;
V_55 = 1 << V_17 -> V_56 ;
if ( V_55 & V_5 -> V_89 )
return 0 ;
return - V_71 ;
}
return 0 ;
}
static void F_31 ( const struct V_8 * V_9 ,
struct V_10 V_11 [ V_12 + 1 ] ,
const struct V_13 * V_14 )
{
void * V_15 = F_3 ( V_9 ) ;
struct V_90 * V_91 = V_9 -> V_17 -> V_11 ;
struct V_18 * V_19 = V_14 -> V_19 ;
bool V_20 ;
F_1 ( (struct V_1 * ) & V_14 -> V_3 , V_91 , V_15 ) ;
V_20 = V_91 -> V_91 ( V_19 , (struct V_1 * ) & V_14 -> V_3 ) ;
if ( V_14 -> V_3 . V_7 ) {
V_11 [ V_23 ] . V_24 = V_21 ;
return;
}
switch( V_20 ) {
case true :
V_11 [ V_23 ] . V_24 = V_25 ;
break;
case false :
V_11 [ V_23 ] . V_24 = V_92 ;
break;
}
}
static void
F_32 ( struct V_93 * V_2 , const struct V_27 * V_28 ,
struct V_90 * V_91 , void * V_15 ,
union V_29 * V_30 , T_1 V_31 , bool V_32 )
{
V_2 -> V_33 = & V_34 ;
V_2 -> V_35 = V_28 -> V_35 -> V_36 ;
switch ( V_28 -> V_37 -> V_38 ) {
case V_39 :
V_30 -> V_40 . V_41 . V_31 = V_31 ;
V_30 -> V_40 . V_41 . V_42 = V_32 ? V_43 : 0 ;
break;
case V_44 :
V_30 -> V_45 . V_46 . V_31 = V_31 ;
V_30 -> V_45 . V_46 . V_42 = V_32 ? V_47 : 0 ;
break;
}
V_2 -> V_48 = V_30 ;
V_2 -> V_91 = V_91 ;
V_2 -> V_94 = V_15 ;
if ( V_28 -> V_49 -> V_50 & V_51 ) {
const struct V_52 * V_53 =
V_52 ( V_28 -> V_49 ) ;
const struct V_54 * V_17 = & V_53 -> V_17 ;
V_2 -> V_55 = 1 << V_17 -> V_56 ;
}
V_2 -> V_38 = V_28 -> V_37 -> V_38 ;
}
static void F_33 ( struct V_90 * V_95 , void * V_58 , void * V_59 )
{
#ifdef F_6
if ( V_95 -> V_60 ) {
int V_61 ;
V_95 -> V_60 ( V_59 , V_58 ) ;
V_61 = F_7 ( V_95 -> V_96 ) - V_95 -> V_96 ;
if ( V_61 > 0 )
memset ( V_59 + V_95 -> V_96 , 0 , V_61 ) ;
} else
#endif
memcpy ( V_59 , V_58 , F_7 ( V_95 -> V_96 ) ) ;
}
static int
F_34 ( const struct V_27 * V_28 , const struct V_8 * V_9 ,
const struct V_63 * const V_65 [] )
{
void * V_15 = F_3 ( V_9 ) ;
struct V_90 * V_91 = V_9 -> V_17 -> V_11 ;
struct V_93 V_2 ;
T_3 V_74 = F_7 ( F_15 ( V_65 [ V_97 ] ) ) ;
T_1 V_31 = 0 ;
bool V_32 = false ;
union V_29 V_76 = {} ;
int V_20 ;
F_33 ( V_91 , F_16 ( V_65 [ V_97 ] ) , V_15 ) ;
if ( V_28 -> V_77 [ V_78 ] ) {
V_20 = F_10 ( V_28 -> V_77 [ V_78 ] , & V_31 , & V_32 ) ;
if ( V_20 < 0 )
goto V_67;
}
F_32 ( & V_2 , V_28 , V_91 , V_15 , & V_76 , V_31 , V_32 ) ;
V_20 = F_35 ( & V_2 , V_74 , V_31 , V_32 ) ;
if ( V_20 < 0 )
goto V_67;
return 0 ;
V_67:
F_18 ( V_91 -> V_79 ) ;
return V_20 ;
}
static void
F_36 ( const struct V_8 * V_9 )
{
struct V_90 * V_91 = V_9 -> V_17 -> V_11 ;
F_18 ( V_91 -> V_79 ) ;
}
static int
F_37 ( struct V_18 * V_19 , const struct V_90 * V_95 , const void * V_58 )
{
int V_20 ;
#ifdef F_6
if ( V_95 -> V_80 ) {
T_4 V_81 ;
void * V_59 ;
V_59 = F_21 ( F_7 ( V_95 -> V_96 ) , V_82 ) ;
if ( V_59 == NULL )
return - V_83 ;
V_81 = F_22 () ;
F_23 ( V_84 ) ;
V_95 -> V_80 ( V_59 , V_58 ) ;
F_23 ( V_81 ) ;
V_20 = F_24 ( V_19 , V_97 , F_7 ( V_95 -> V_96 ) , V_59 ) ;
F_25 ( V_59 ) ;
} else
#endif
V_20 = F_24 ( V_19 , V_97 , F_7 ( V_95 -> V_96 ) , V_58 ) ;
return V_20 ;
}
static inline int F_38 ( struct V_90 * V_91 )
{
#ifdef F_6
return F_39 ( V_91 ) ;
#else
return 0 ;
#endif
}
static int F_40 ( struct V_18 * V_19 , const struct V_8 * V_9 )
{
void * V_15 = F_3 ( V_9 ) ;
struct V_90 * V_91 = V_9 -> V_17 -> V_11 ;
if ( F_27 ( V_19 , V_98 , V_91 -> V_36 ) ||
F_28 ( V_19 , V_99 , F_29 ( V_91 -> V_87 ) ) ||
F_37 ( V_19 , V_91 , V_15 ) )
goto V_88;
return 0 ;
V_88:
return - 1 ;
}
static int F_41 ( const struct V_27 * V_28 ,
const struct V_8 * V_9 ,
const struct V_10 * * V_11 )
{
struct V_90 * V_91 = V_9 -> V_17 -> V_11 ;
unsigned int V_55 = 0 ;
if ( V_28 -> V_49 -> V_50 & V_51 ) {
const struct V_52 * V_53 =
V_52 ( V_28 -> V_49 ) ;
const struct V_54 * V_17 = & V_53 -> V_17 ;
V_55 = 1 << V_17 -> V_56 ;
if ( V_55 & V_91 -> V_89 )
return 0 ;
return - V_71 ;
}
return 0 ;
}
static int
F_42 ( struct V_18 * V_19 , T_2 V_100 , T_2 V_101 , T_2 type ,
int V_102 , T_5 V_38 , const char * V_36 ,
int V_103 , int V_5 )
{
struct V_104 * V_105 ;
struct V_106 * V_107 ;
unsigned int V_50 = V_100 ? V_108 : 0 ;
V_102 |= V_109 << 8 ;
V_105 = F_43 ( V_19 , V_100 , V_101 , V_102 , sizeof( * V_107 ) , V_50 ) ;
if ( V_105 == NULL )
goto V_110;
V_107 = F_44 ( V_105 ) ;
V_107 -> V_111 = V_38 ;
V_107 -> V_112 = V_113 ;
V_107 -> V_114 = 0 ;
if ( F_27 ( V_19 , V_115 , V_36 ) ||
F_28 ( V_19 , V_116 , F_29 ( V_103 ) ) ||
F_28 ( V_19 , V_117 , F_29 ( V_5 ) ) )
goto V_88;
F_45 ( V_19 , V_105 ) ;
return V_19 -> V_118 ;
V_110:
V_88:
F_46 ( V_19 , V_105 ) ;
return - 1 ;
}
static int
F_47 ( struct V_119 * V_120 , struct V_18 * V_19 ,
const struct V_104 * V_105 , const struct V_63 * const V_65 [] )
{
int V_20 = 0 , V_5 ;
struct V_106 * V_107 ;
const char * V_121 ;
const char * V_36 ;
T_2 V_103 ;
struct V_18 * V_122 ;
if ( V_65 [ V_115 ] == NULL ||
V_65 [ V_116 ] == NULL ||
V_65 [ V_117 ] == NULL )
return - V_71 ;
V_36 = F_16 ( V_65 [ V_115 ] ) ;
V_103 = F_12 ( F_13 ( V_65 [ V_116 ] ) ) ;
V_5 = F_12 ( F_13 ( V_65 [ V_117 ] ) ) ;
V_107 = F_44 ( V_105 ) ;
switch( V_107 -> V_111 ) {
case V_39 :
V_121 = L_1 ;
break;
case V_44 :
V_121 = L_2 ;
break;
default:
F_48 ( L_3 ,
V_107 -> V_111 ) ;
return - V_71 ;
}
F_49 ( F_50 ( V_107 -> V_111 , V_36 ,
V_103 , V_5 , & V_20 ) ,
V_121 , V_36 ) ;
if ( V_20 < 0 )
return V_20 ;
V_122 = F_51 ( V_123 , V_124 ) ;
if ( V_122 == NULL )
return - V_83 ;
if ( F_42 ( V_122 , F_52 ( V_19 ) . V_100 ,
V_105 -> V_125 ,
F_53 ( V_105 -> V_126 ) ,
V_127 ,
V_107 -> V_111 ,
V_36 , V_20 , V_5 ) <= 0 ) {
F_54 ( V_122 ) ;
return - V_128 ;
}
V_20 = F_55 ( V_120 , V_122 , F_52 ( V_19 ) . V_100 ,
V_129 ) ;
if ( V_20 > 0 )
V_20 = 0 ;
return V_20 == - V_130 ? - V_131 : V_20 ;
}
static const struct V_132 *
F_56 ( const struct V_27 * V_28 ,
const struct V_63 * const V_65 [] )
{
struct V_133 * V_134 ;
struct V_90 * V_91 ;
char * V_135 ;
T_6 V_103 , V_38 ;
if ( V_65 [ V_98 ] == NULL ||
V_65 [ V_99 ] == NULL ||
V_65 [ V_97 ] == NULL )
return F_57 ( - V_71 ) ;
V_135 = F_16 ( V_65 [ V_98 ] ) ;
V_103 = F_12 ( F_13 ( V_65 [ V_99 ] ) ) ;
V_38 = V_28 -> V_37 -> V_38 ;
F_58 (nft_match, &nft_match_list, head) {
struct V_90 * V_91 = V_134 -> V_17 . V_11 ;
if ( strcmp ( V_91 -> V_36 , V_135 ) == 0 &&
V_91 -> V_87 == V_103 && V_91 -> V_38 == V_38 )
return & V_134 -> V_17 ;
}
V_91 = F_59 ( V_38 , V_135 , V_103 ) ;
if ( F_60 ( V_91 ) )
return F_57 ( - V_136 ) ;
V_134 = F_61 ( sizeof( struct V_133 ) , V_124 ) ;
if ( V_134 == NULL )
return F_57 ( - V_83 ) ;
V_134 -> V_17 . type = & V_137 ;
V_134 -> V_17 . V_74 = F_62 ( F_7 ( V_91 -> V_96 ) +
F_38 ( V_91 ) ) ;
V_134 -> V_17 . V_138 = F_31 ;
V_134 -> V_17 . V_139 = F_34 ;
V_134 -> V_17 . V_140 = F_36 ;
V_134 -> V_17 . V_141 = F_40 ;
V_134 -> V_17 . V_142 = F_41 ;
V_134 -> V_17 . V_11 = V_91 ;
F_63 ( & V_134 -> V_143 , & V_144 ) ;
return & V_134 -> V_17 ;
}
static void F_64 ( void )
{
struct V_133 * V_134 , * V_145 ;
F_65 (nft_match, tmp, &nft_match_list, head)
F_25 ( V_134 ) ;
}
static const struct V_132 *
F_66 ( const struct V_27 * V_28 ,
const struct V_63 * const V_65 [] )
{
struct V_133 * V_146 ;
struct V_16 * V_5 ;
char * V_147 ;
T_6 V_103 , V_38 ;
if ( V_65 [ V_85 ] == NULL ||
V_65 [ V_86 ] == NULL ||
V_65 [ V_75 ] == NULL )
return F_57 ( - V_71 ) ;
V_147 = F_16 ( V_65 [ V_85 ] ) ;
V_103 = F_12 ( F_13 ( V_65 [ V_86 ] ) ) ;
V_38 = V_28 -> V_37 -> V_38 ;
F_58 (nft_target, &nft_match_list, head) {
struct V_16 * V_5 = V_146 -> V_17 . V_11 ;
if ( strcmp ( V_5 -> V_36 , V_147 ) == 0 &&
V_5 -> V_87 == V_103 && V_5 -> V_38 == V_38 )
return & V_146 -> V_17 ;
}
V_5 = F_67 ( V_38 , V_147 , V_103 ) ;
if ( F_60 ( V_5 ) )
return F_57 ( - V_136 ) ;
V_146 = F_61 ( sizeof( struct V_133 ) , V_124 ) ;
if ( V_146 == NULL )
return F_57 ( - V_83 ) ;
V_146 -> V_17 . type = & V_148 ;
V_146 -> V_17 . V_74 = F_62 ( F_7 ( V_5 -> V_62 ) +
F_8 ( V_5 ) ) ;
V_146 -> V_17 . V_138 = F_2 ;
V_146 -> V_17 . V_139 = F_14 ;
V_146 -> V_17 . V_140 = F_19 ;
V_146 -> V_17 . V_141 = F_26 ;
V_146 -> V_17 . V_142 = F_30 ;
V_146 -> V_17 . V_11 = V_5 ;
F_63 ( & V_146 -> V_143 , & V_149 ) ;
return & V_146 -> V_17 ;
}
static void F_68 ( void )
{
struct V_133 * V_146 , * V_145 ;
F_65 (nft_target, tmp, &nft_target_list, head)
F_25 ( V_146 ) ;
}
static int T_7 F_69 ( void )
{
int V_20 ;
V_20 = F_70 ( & V_137 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_70 ( & V_148 ) ;
if ( V_20 < 0 )
goto V_150;
V_20 = F_71 ( & V_151 ) ;
if ( V_20 < 0 ) {
F_48 ( L_4 ) ;
goto V_152;
}
F_72 ( L_5 ) ;
return V_20 ;
V_152:
F_73 ( & V_148 ) ;
V_150:
F_73 ( & V_137 ) ;
return V_20 ;
}
static void T_8 F_74 ( void )
{
F_75 ( & V_151 ) ;
F_73 ( & V_148 ) ;
F_73 ( & V_137 ) ;
F_64 () ;
F_68 () ;
}
