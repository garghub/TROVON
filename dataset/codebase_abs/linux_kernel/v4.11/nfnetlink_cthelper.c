static int
F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
struct V_4 * V_5 , enum V_6 V_7 )
{
const struct V_8 * V_9 ;
struct V_10 * V_11 ;
V_9 = F_2 ( V_5 ) ;
if ( V_9 == NULL )
return V_12 ;
V_11 = F_3 ( V_9 -> V_11 ) ;
if ( V_11 == NULL )
return V_12 ;
if ( ( V_11 -> V_13 &
( V_14 | V_15 ) ) ==
V_14 )
return V_16 ;
return F_4 ( V_11 -> V_17 ) | V_18 ;
}
static int
F_5 ( struct V_19 * V_20 ,
const struct V_21 * V_22 )
{
int V_23 ;
struct V_21 * V_24 [ V_25 + 1 ] ;
V_23 = F_6 ( V_24 , V_25 , V_22 , V_26 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( ! V_24 [ V_27 ] || ! V_24 [ V_28 ] )
return - V_29 ;
memset ( V_20 , 0 , sizeof( struct V_19 ) ) ;
V_20 -> V_30 . V_31 = F_7 ( F_8 ( V_24 [ V_27 ] ) ) ;
V_20 -> V_32 . V_33 = F_9 ( V_24 [ V_28 ] ) ;
return 0 ;
}
static int
F_10 ( struct V_21 * V_22 , struct V_4 * V_5 )
{
struct V_8 * V_9 = F_2 ( V_5 ) ;
if ( V_22 == NULL )
return - V_29 ;
if ( V_9 -> V_11 -> V_34 == 0 )
return - V_29 ;
memcpy ( V_9 -> V_35 , F_11 ( V_22 ) , V_9 -> V_11 -> V_34 ) ;
return 0 ;
}
static int
F_12 ( struct V_1 * V_2 , const struct V_4 * V_5 )
{
const struct V_8 * V_9 = F_2 ( V_5 ) ;
if ( V_9 -> V_11 -> V_34 &&
F_13 ( V_2 , V_36 , V_9 -> V_11 -> V_34 , & V_9 -> V_35 ) )
goto V_37;
return 0 ;
V_37:
return - V_38 ;
}
static int
F_14 ( struct V_39 * V_40 ,
const struct V_21 * V_22 )
{
int V_23 ;
struct V_21 * V_24 [ V_41 + 1 ] ;
V_23 = F_6 ( V_24 , V_41 , V_22 , V_42 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( ! V_24 [ V_43 ] ||
! V_24 [ V_44 ] ||
! V_24 [ V_45 ] )
return - V_29 ;
strncpy ( V_40 -> V_46 ,
F_11 ( V_24 [ V_43 ] ) , V_47 ) ;
V_40 -> V_48 =
F_15 ( F_16 ( V_24 [ V_44 ] ) ) ;
V_40 -> V_49 =
F_15 ( F_16 ( V_24 [ V_45 ] ) ) ;
return 0 ;
}
static int
F_17 ( struct V_10 * V_11 ,
const struct V_21 * V_22 )
{
int V_50 , V_51 ;
struct V_39 * V_40 ;
struct V_21 * V_24 [ V_52 + 1 ] ;
unsigned int V_53 ;
V_51 = F_6 ( V_24 , V_52 , V_22 ,
V_54 ) ;
if ( V_51 < 0 )
return V_51 ;
if ( ! V_24 [ V_55 ] )
return - V_29 ;
V_53 = F_15 ( F_16 ( V_24 [ V_55 ] ) ) ;
if ( V_53 == 0 )
return - V_29 ;
if ( V_53 > V_56 )
return - V_57 ;
V_40 = F_18 ( sizeof( struct V_39 ) *
V_53 , V_58 ) ;
if ( V_40 == NULL )
return - V_59 ;
for ( V_50 = 0 ; V_50 < V_53 ; V_50 ++ ) {
if ( ! V_24 [ V_60 + V_50 ] )
goto V_23;
V_51 = F_14 ( & V_40 [ V_50 ] ,
V_24 [ V_60 + V_50 ] ) ;
if ( V_51 < 0 )
goto V_23;
}
V_11 -> V_61 = V_53 - 1 ;
V_11 -> V_40 = V_40 ;
return 0 ;
V_23:
F_19 ( V_40 ) ;
return - V_29 ;
}
static int
F_20 ( const struct V_21 * const V_24 [] ,
struct V_19 * V_20 )
{
struct V_10 * V_11 ;
struct V_62 * V_63 ;
int V_51 ;
if ( ! V_24 [ V_64 ] || ! V_24 [ V_65 ] || ! V_24 [ V_66 ] )
return - V_29 ;
V_63 = F_18 ( sizeof( * V_63 ) , V_58 ) ;
if ( V_63 == NULL )
return - V_59 ;
V_11 = & V_63 -> V_11 ;
V_51 = F_17 ( V_11 , V_24 [ V_65 ] ) ;
if ( V_51 < 0 )
goto V_67;
strncpy ( V_11 -> V_46 , F_11 ( V_24 [ V_68 ] ) , V_47 ) ;
V_11 -> V_34 = F_15 ( F_16 ( V_24 [ V_66 ] ) ) ;
V_11 -> V_13 |= V_14 ;
memcpy ( & V_11 -> V_20 , V_20 , sizeof( struct V_19 ) ) ;
V_11 -> V_69 = V_70 ;
V_11 -> V_9 = F_1 ;
V_11 -> V_71 = F_10 ;
V_11 -> V_72 = F_12 ;
if ( V_24 [ V_73 ] )
V_11 -> V_17 = F_15 ( F_16 ( V_24 [ V_73 ] ) ) ;
if ( V_24 [ V_74 ] ) {
int V_75 = F_15 ( F_16 ( V_24 [ V_74 ] ) ) ;
switch( V_75 ) {
case V_76 :
V_11 -> V_13 |= V_15 ;
break;
case V_77 :
V_11 -> V_13 &= ~ V_15 ;
break;
}
}
V_51 = F_21 ( V_11 ) ;
if ( V_51 < 0 )
goto V_78;
F_22 ( & V_63 -> V_79 , & V_80 ) ;
return 0 ;
V_78:
F_19 ( V_11 -> V_40 ) ;
V_67:
F_19 ( V_63 ) ;
return V_51 ;
}
static int
F_23 ( const struct V_39 * V_81 ,
struct V_39 * V_82 ,
const struct V_21 * V_22 )
{
struct V_21 * V_24 [ V_41 + 1 ] ;
int V_23 ;
V_23 = F_6 ( V_24 , V_41 , V_22 ,
V_42 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( ! V_24 [ V_43 ] ||
! V_24 [ V_44 ] ||
! V_24 [ V_45 ] )
return - V_29 ;
if ( F_24 ( V_24 [ V_43 ] , V_81 -> V_46 ) )
return - V_83 ;
V_82 -> V_48 =
F_15 ( F_16 ( V_24 [ V_44 ] ) ) ;
V_82 -> V_49 =
F_15 ( F_16 ( V_24 [ V_45 ] ) ) ;
return 0 ;
}
static int F_25 ( struct V_21 * V_24 [] ,
struct V_10 * V_11 )
{
struct V_39 V_82 [ V_11 -> V_61 + 1 ] ;
struct V_39 * V_81 ;
int V_50 , V_23 ;
for ( V_50 = 0 ; V_50 < V_11 -> V_61 + 1 ; V_50 ++ ) {
if ( ! V_24 [ V_60 + V_50 ] )
return - V_29 ;
V_23 = F_23 ( & V_11 -> V_40 [ V_50 ] ,
& V_82 [ V_50 ] ,
V_24 [ V_60 + V_50 ] ) ;
if ( V_23 < 0 )
return V_23 ;
}
for ( V_50 = 0 ; V_50 < V_11 -> V_61 + 1 ; V_50 ++ ) {
V_81 = (struct V_39 * )
& V_11 -> V_40 [ V_50 ] ;
V_81 -> V_48 = V_82 -> V_48 ;
V_81 -> V_49 = V_82 -> V_49 ;
}
return 0 ;
}
static int F_26 ( struct V_10 * V_11 ,
const struct V_21 * V_22 )
{
struct V_21 * V_24 [ V_52 + 1 ] ;
unsigned int V_53 ;
int V_23 ;
V_23 = F_6 ( V_24 , V_52 , V_22 ,
V_54 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( ! V_24 [ V_55 ] )
return - V_29 ;
V_53 = F_15 ( F_16 ( V_24 [ V_55 ] ) ) ;
if ( V_11 -> V_61 + 1 != V_53 )
return - V_83 ;
return F_25 ( V_24 , V_11 ) ;
}
static int
F_27 ( const struct V_21 * const V_24 [] ,
struct V_10 * V_11 )
{
int V_51 ;
if ( V_24 [ V_66 ] )
return - V_83 ;
if ( V_24 [ V_65 ] ) {
V_51 = F_26 ( V_11 , V_24 [ V_65 ] ) ;
if ( V_51 < 0 )
return V_51 ;
}
if ( V_24 [ V_73 ] )
V_11 -> V_17 = F_15 ( F_16 ( V_24 [ V_73 ] ) ) ;
if ( V_24 [ V_74 ] ) {
int V_75 = F_15 ( F_16 ( V_24 [ V_74 ] ) ) ;
switch( V_75 ) {
case V_76 :
V_11 -> V_13 |= V_15 ;
break;
case V_77 :
V_11 -> V_13 &= ~ V_15 ;
break;
}
}
return 0 ;
}
static int F_28 ( struct V_84 * V_84 , struct V_85 * V_86 ,
struct V_1 * V_2 , const struct V_87 * V_88 ,
const struct V_21 * const V_24 [] )
{
const char * V_89 ;
struct V_10 * V_90 , * V_11 = NULL ;
struct V_19 V_20 ;
struct V_62 * V_91 ;
int V_51 = 0 ;
if ( ! V_24 [ V_68 ] || ! V_24 [ V_64 ] )
return - V_29 ;
V_89 = F_11 ( V_24 [ V_68 ] ) ;
V_51 = F_5 ( & V_20 , V_24 [ V_64 ] ) ;
if ( V_51 < 0 )
return V_51 ;
F_29 (nlcth, &nfnl_cthelper_list, list) {
V_90 = & V_91 -> V_11 ;
if ( strncmp ( V_90 -> V_46 , V_89 , V_47 ) )
continue;
if ( ( V_20 . V_30 . V_31 != V_90 -> V_20 . V_30 . V_31 ||
V_20 . V_32 . V_33 != V_90 -> V_20 . V_32 . V_33 ) )
continue;
if ( V_88 -> V_92 & V_93 )
return - V_94 ;
V_11 = V_90 ;
break;
}
if ( V_11 == NULL )
V_51 = F_20 ( V_24 , & V_20 ) ;
else
V_51 = F_27 ( V_24 , V_11 ) ;
return V_51 ;
}
static int
F_30 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_21 * V_95 ;
V_95 = F_31 ( V_2 , V_64 | V_96 ) ;
if ( V_95 == NULL )
goto V_37;
if ( F_32 ( V_2 , V_27 ,
F_33 ( V_11 -> V_20 . V_30 . V_31 ) ) )
goto V_37;
if ( F_34 ( V_2 , V_28 , V_11 -> V_20 . V_32 . V_33 ) )
goto V_37;
F_35 ( V_2 , V_95 ) ;
return 0 ;
V_37:
return - 1 ;
}
static int
F_36 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
int V_50 ;
struct V_21 * V_97 , * V_98 ;
V_97 = F_31 ( V_2 , V_65 | V_96 ) ;
if ( V_97 == NULL )
goto V_37;
if ( F_37 ( V_2 , V_55 ,
F_38 ( V_11 -> V_61 + 1 ) ) )
goto V_37;
for ( V_50 = 0 ; V_50 < V_11 -> V_61 + 1 ; V_50 ++ ) {
V_98 = F_31 ( V_2 ,
( V_60 + V_50 ) | V_96 ) ;
if ( V_98 == NULL )
goto V_37;
if ( F_39 ( V_2 , V_43 ,
V_11 -> V_40 [ V_50 ] . V_46 ) )
goto V_37;
if ( F_37 ( V_2 , V_44 ,
F_38 ( V_11 -> V_40 [ V_50 ] . V_48 ) ) )
goto V_37;
if ( F_37 ( V_2 , V_45 ,
F_38 ( V_11 -> V_40 [ V_50 ] . V_49 ) ) )
goto V_37;
F_35 ( V_2 , V_98 ) ;
}
F_35 ( V_2 , V_97 ) ;
return 0 ;
V_37:
return - 1 ;
}
static int
F_40 ( struct V_1 * V_2 , T_1 V_99 , T_1 V_100 , T_1 type ,
int V_101 , struct V_10 * V_11 )
{
struct V_87 * V_88 ;
struct V_102 * V_103 ;
unsigned int V_13 = V_99 ? V_104 : 0 ;
int V_75 ;
V_101 |= V_105 << 8 ;
V_88 = F_41 ( V_2 , V_99 , V_100 , V_101 , sizeof( * V_103 ) , V_13 ) ;
if ( V_88 == NULL )
goto V_106;
V_103 = F_42 ( V_88 ) ;
V_103 -> V_107 = V_108 ;
V_103 -> V_109 = V_110 ;
V_103 -> V_111 = 0 ;
if ( F_39 ( V_2 , V_68 , V_11 -> V_46 ) )
goto V_37;
if ( F_37 ( V_2 , V_73 , F_38 ( V_11 -> V_17 ) ) )
goto V_37;
if ( F_30 ( V_2 , V_11 ) < 0 )
goto V_37;
if ( F_36 ( V_2 , V_11 ) < 0 )
goto V_37;
if ( F_37 ( V_2 , V_66 , F_38 ( V_11 -> V_34 ) ) )
goto V_37;
if ( V_11 -> V_13 & V_15 )
V_75 = V_76 ;
else
V_75 = V_77 ;
if ( F_37 ( V_2 , V_74 , F_38 ( V_75 ) ) )
goto V_37;
F_43 ( V_2 , V_88 ) ;
return V_2 -> V_112 ;
V_106:
V_37:
F_44 ( V_2 , V_88 ) ;
return - 1 ;
}
static int
F_45 ( struct V_1 * V_2 , struct V_113 * V_114 )
{
struct V_10 * V_90 , * V_115 ;
F_46 () ;
V_115 = (struct V_10 * ) V_114 -> args [ 1 ] ;
for (; V_114 -> args [ 0 ] < V_116 ; V_114 -> args [ 0 ] ++ ) {
V_117:
F_47 (cur,
&nf_ct_helper_hash[cb->args[0]], hnode) {
if ( ! ( V_90 -> V_13 & V_14 ) )
continue;
if ( V_114 -> args [ 1 ] ) {
if ( V_90 != V_115 )
continue;
V_114 -> args [ 1 ] = 0 ;
}
if ( F_40 ( V_2 ,
F_48 ( V_114 -> V_2 ) . V_99 ,
V_114 -> V_88 -> V_118 ,
F_49 ( V_114 -> V_88 -> V_119 ) ,
V_120 , V_90 ) < 0 ) {
V_114 -> args [ 1 ] = ( unsigned long ) V_90 ;
goto V_121;
}
}
}
if ( V_114 -> args [ 1 ] ) {
V_114 -> args [ 1 ] = 0 ;
goto V_117;
}
V_121:
F_50 () ;
return V_2 -> V_112 ;
}
static int F_51 ( struct V_84 * V_84 , struct V_85 * V_86 ,
struct V_1 * V_2 , const struct V_87 * V_88 ,
const struct V_21 * const V_24 [] )
{
int V_51 = - V_122 ;
struct V_10 * V_90 ;
struct V_1 * V_123 ;
char * V_89 = NULL ;
struct V_19 V_20 ;
struct V_62 * V_91 ;
bool V_124 = false ;
if ( V_88 -> V_92 & V_125 ) {
struct V_126 V_127 = {
. V_128 = F_45 ,
} ;
return F_52 ( V_86 , V_2 , V_88 , & V_127 ) ;
}
if ( V_24 [ V_68 ] )
V_89 = F_11 ( V_24 [ V_68 ] ) ;
if ( V_24 [ V_64 ] ) {
V_51 = F_5 ( & V_20 , V_24 [ V_64 ] ) ;
if ( V_51 < 0 )
return V_51 ;
V_124 = true ;
}
F_29 (nlcth, &nfnl_cthelper_list, list) {
V_90 = & V_91 -> V_11 ;
if ( V_89 &&
strncmp ( V_90 -> V_46 , V_89 , V_47 ) )
continue;
if ( V_124 &&
( V_20 . V_30 . V_31 != V_90 -> V_20 . V_30 . V_31 ||
V_20 . V_32 . V_33 != V_90 -> V_20 . V_32 . V_33 ) )
continue;
V_123 = F_53 ( V_129 , V_58 ) ;
if ( V_123 == NULL ) {
V_51 = - V_59 ;
break;
}
V_51 = F_40 ( V_123 , F_48 ( V_2 ) . V_99 ,
V_88 -> V_118 ,
F_49 ( V_88 -> V_119 ) ,
V_120 , V_90 ) ;
if ( V_51 <= 0 ) {
F_54 ( V_123 ) ;
break;
}
V_51 = F_55 ( V_86 , V_123 , F_48 ( V_2 ) . V_99 ,
V_130 ) ;
if ( V_51 > 0 )
V_51 = 0 ;
return V_51 == - V_131 ? - V_132 : V_51 ;
}
return V_51 ;
}
static int F_56 ( struct V_84 * V_84 , struct V_85 * V_86 ,
struct V_1 * V_2 , const struct V_87 * V_88 ,
const struct V_21 * const V_24 [] )
{
char * V_89 = NULL ;
struct V_10 * V_90 ;
struct V_19 V_20 ;
bool V_124 = false , V_133 = false ;
struct V_62 * V_91 , * V_134 ;
int V_135 = 0 , V_51 ;
if ( V_24 [ V_68 ] )
V_89 = F_11 ( V_24 [ V_68 ] ) ;
if ( V_24 [ V_64 ] ) {
V_51 = F_5 ( & V_20 , V_24 [ V_64 ] ) ;
if ( V_51 < 0 )
return V_51 ;
V_124 = true ;
}
F_57 (nlcth, n, &nfnl_cthelper_list, list) {
V_90 = & V_91 -> V_11 ;
V_135 ++ ;
if ( V_89 &&
strncmp ( V_90 -> V_46 , V_89 , V_47 ) )
continue;
if ( V_124 &&
( V_20 . V_30 . V_31 != V_90 -> V_20 . V_30 . V_31 ||
V_20 . V_32 . V_33 != V_90 -> V_20 . V_32 . V_33 ) )
continue;
V_133 = true ;
F_58 ( V_90 ) ;
F_19 ( V_90 -> V_40 ) ;
F_59 ( & V_91 -> V_79 ) ;
F_19 ( V_91 ) ;
}
return ( V_133 || V_135 == 0 ) ? 0 : - V_122 ;
}
static int T_2 F_60 ( void )
{
int V_51 ;
V_51 = F_61 ( & V_136 ) ;
if ( V_51 < 0 ) {
F_62 ( L_1 ) ;
goto V_137;
}
return 0 ;
V_137:
return V_51 ;
}
static void T_3 F_63 ( void )
{
struct V_10 * V_90 ;
struct V_62 * V_91 , * V_134 ;
F_64 ( & V_136 ) ;
F_57 (nlcth, n, &nfnl_cthelper_list, list) {
V_90 = & V_91 -> V_11 ;
F_58 ( V_90 ) ;
F_19 ( V_90 -> V_40 ) ;
F_19 ( V_91 ) ;
}
}
