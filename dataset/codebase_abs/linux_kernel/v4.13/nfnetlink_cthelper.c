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
V_23 = F_6 ( V_24 , V_25 , V_22 ,
V_26 , NULL ) ;
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
F_11 ( V_9 -> V_35 , F_12 ( V_22 ) , sizeof( V_9 -> V_35 ) ) ;
return 0 ;
}
static int
F_13 ( struct V_1 * V_2 , const struct V_4 * V_5 )
{
const struct V_8 * V_9 = F_2 ( V_5 ) ;
if ( V_9 -> V_11 -> V_34 &&
F_14 ( V_2 , V_36 , V_9 -> V_11 -> V_34 , & V_9 -> V_35 ) )
goto V_37;
return 0 ;
V_37:
return - V_38 ;
}
static int
F_15 ( struct V_39 * V_40 ,
const struct V_21 * V_22 )
{
int V_23 ;
struct V_21 * V_24 [ V_41 + 1 ] ;
V_23 = F_6 ( V_24 , V_41 , V_22 ,
V_42 , NULL ) ;
if ( V_23 < 0 )
return V_23 ;
if ( ! V_24 [ V_43 ] ||
! V_24 [ V_44 ] ||
! V_24 [ V_45 ] )
return - V_29 ;
strncpy ( V_40 -> V_46 ,
F_12 ( V_24 [ V_43 ] ) , V_47 ) ;
V_40 -> V_48 =
F_16 ( F_17 ( V_24 [ V_44 ] ) ) ;
if ( V_40 -> V_48 > V_49 )
return - V_29 ;
V_40 -> V_50 =
F_16 ( F_17 ( V_24 [ V_45 ] ) ) ;
return 0 ;
}
static int
F_18 ( struct V_10 * V_11 ,
const struct V_21 * V_22 )
{
int V_51 , V_52 ;
struct V_39 * V_40 ;
struct V_21 * V_24 [ V_53 + 1 ] ;
unsigned int V_54 ;
V_52 = F_6 ( V_24 , V_53 , V_22 ,
V_55 , NULL ) ;
if ( V_52 < 0 )
return V_52 ;
if ( ! V_24 [ V_56 ] )
return - V_29 ;
V_54 = F_16 ( F_17 ( V_24 [ V_56 ] ) ) ;
if ( V_54 == 0 )
return - V_29 ;
if ( V_54 > V_57 )
return - V_58 ;
V_40 = F_19 ( sizeof( struct V_39 ) *
V_54 , V_59 ) ;
if ( V_40 == NULL )
return - V_60 ;
for ( V_51 = 0 ; V_51 < V_54 ; V_51 ++ ) {
if ( ! V_24 [ V_61 + V_51 ] )
goto V_23;
V_52 = F_15 ( & V_40 [ V_51 ] ,
V_24 [ V_61 + V_51 ] ) ;
if ( V_52 < 0 )
goto V_23;
}
V_11 -> V_62 = V_54 - 1 ;
V_11 -> V_40 = V_40 ;
return 0 ;
V_23:
F_20 ( V_40 ) ;
return - V_29 ;
}
static int
F_21 ( const struct V_21 * const V_24 [] ,
struct V_19 * V_20 )
{
struct V_10 * V_11 ;
struct V_63 * V_64 ;
unsigned int V_65 ;
int V_52 ;
if ( ! V_24 [ V_66 ] || ! V_24 [ V_67 ] || ! V_24 [ V_68 ] )
return - V_29 ;
V_64 = F_19 ( sizeof( * V_64 ) , V_59 ) ;
if ( V_64 == NULL )
return - V_60 ;
V_11 = & V_64 -> V_11 ;
V_52 = F_18 ( V_11 , V_24 [ V_67 ] ) ;
if ( V_52 < 0 )
goto V_69;
strncpy ( V_11 -> V_46 , F_12 ( V_24 [ V_70 ] ) , V_47 ) ;
V_65 = F_16 ( F_17 ( V_24 [ V_68 ] ) ) ;
if ( V_65 > F_22 ( struct V_8 , V_35 ) ) {
V_52 = - V_60 ;
goto V_71;
}
V_11 -> V_13 |= V_14 ;
memcpy ( & V_11 -> V_20 , V_20 , sizeof( struct V_19 ) ) ;
V_11 -> V_72 = V_73 ;
V_11 -> V_9 = F_1 ;
V_11 -> V_74 = F_10 ;
V_11 -> V_75 = F_13 ;
if ( V_24 [ V_76 ] )
V_11 -> V_17 = F_16 ( F_17 ( V_24 [ V_76 ] ) ) ;
if ( V_24 [ V_77 ] ) {
int V_78 = F_16 ( F_17 ( V_24 [ V_77 ] ) ) ;
switch( V_78 ) {
case V_79 :
V_11 -> V_13 |= V_15 ;
break;
case V_80 :
V_11 -> V_13 &= ~ V_15 ;
break;
}
}
V_52 = F_23 ( V_11 ) ;
if ( V_52 < 0 )
goto V_71;
F_24 ( & V_64 -> V_81 , & V_82 ) ;
return 0 ;
V_71:
F_20 ( V_11 -> V_40 ) ;
V_69:
F_20 ( V_64 ) ;
return V_52 ;
}
static int
F_25 ( const struct V_39 * V_83 ,
struct V_39 * V_84 ,
const struct V_21 * V_22 )
{
struct V_21 * V_24 [ V_41 + 1 ] ;
int V_23 ;
V_23 = F_6 ( V_24 , V_41 , V_22 ,
V_42 , NULL ) ;
if ( V_23 < 0 )
return V_23 ;
if ( ! V_24 [ V_43 ] ||
! V_24 [ V_44 ] ||
! V_24 [ V_45 ] )
return - V_29 ;
if ( F_26 ( V_24 [ V_43 ] , V_83 -> V_46 ) )
return - V_85 ;
V_84 -> V_48 =
F_16 ( F_17 ( V_24 [ V_44 ] ) ) ;
if ( V_84 -> V_48 > V_49 )
return - V_29 ;
V_84 -> V_50 =
F_16 ( F_17 ( V_24 [ V_45 ] ) ) ;
return 0 ;
}
static int F_27 ( struct V_21 * V_24 [] ,
struct V_10 * V_11 )
{
struct V_39 V_84 [ V_11 -> V_62 + 1 ] ;
struct V_39 * V_83 ;
int V_51 , V_23 ;
for ( V_51 = 0 ; V_51 < V_11 -> V_62 + 1 ; V_51 ++ ) {
if ( ! V_24 [ V_61 + V_51 ] )
return - V_29 ;
V_23 = F_25 ( & V_11 -> V_40 [ V_51 ] ,
& V_84 [ V_51 ] ,
V_24 [ V_61 + V_51 ] ) ;
if ( V_23 < 0 )
return V_23 ;
}
for ( V_51 = 0 ; V_51 < V_11 -> V_62 + 1 ; V_51 ++ ) {
V_83 = (struct V_39 * )
& V_11 -> V_40 [ V_51 ] ;
V_83 -> V_48 = V_84 -> V_48 ;
V_83 -> V_50 = V_84 -> V_50 ;
}
return 0 ;
}
static int F_28 ( struct V_10 * V_11 ,
const struct V_21 * V_22 )
{
struct V_21 * V_24 [ V_53 + 1 ] ;
unsigned int V_54 ;
int V_23 ;
V_23 = F_6 ( V_24 , V_53 , V_22 ,
V_55 , NULL ) ;
if ( V_23 < 0 )
return V_23 ;
if ( ! V_24 [ V_56 ] )
return - V_29 ;
V_54 = F_16 ( F_17 ( V_24 [ V_56 ] ) ) ;
if ( V_11 -> V_62 + 1 != V_54 )
return - V_85 ;
return F_27 ( V_24 , V_11 ) ;
}
static int
F_29 ( const struct V_21 * const V_24 [] ,
struct V_10 * V_11 )
{
int V_52 ;
if ( V_24 [ V_68 ] )
return - V_85 ;
if ( V_24 [ V_67 ] ) {
V_52 = F_28 ( V_11 , V_24 [ V_67 ] ) ;
if ( V_52 < 0 )
return V_52 ;
}
if ( V_24 [ V_76 ] )
V_11 -> V_17 = F_16 ( F_17 ( V_24 [ V_76 ] ) ) ;
if ( V_24 [ V_77 ] ) {
int V_78 = F_16 ( F_17 ( V_24 [ V_77 ] ) ) ;
switch( V_78 ) {
case V_79 :
V_11 -> V_13 |= V_15 ;
break;
case V_80 :
V_11 -> V_13 &= ~ V_15 ;
break;
}
}
return 0 ;
}
static int F_30 ( struct V_86 * V_86 , struct V_87 * V_88 ,
struct V_1 * V_2 , const struct V_89 * V_90 ,
const struct V_21 * const V_24 [] ,
struct V_91 * V_92 )
{
const char * V_93 ;
struct V_10 * V_94 , * V_11 = NULL ;
struct V_19 V_20 ;
struct V_63 * V_95 ;
int V_52 = 0 ;
if ( ! V_24 [ V_70 ] || ! V_24 [ V_66 ] )
return - V_29 ;
V_93 = F_12 ( V_24 [ V_70 ] ) ;
V_52 = F_5 ( & V_20 , V_24 [ V_66 ] ) ;
if ( V_52 < 0 )
return V_52 ;
F_31 (nlcth, &nfnl_cthelper_list, list) {
V_94 = & V_95 -> V_11 ;
if ( strncmp ( V_94 -> V_46 , V_93 , V_47 ) )
continue;
if ( ( V_20 . V_30 . V_31 != V_94 -> V_20 . V_30 . V_31 ||
V_20 . V_32 . V_33 != V_94 -> V_20 . V_32 . V_33 ) )
continue;
if ( V_90 -> V_96 & V_97 )
return - V_98 ;
V_11 = V_94 ;
break;
}
if ( V_11 == NULL )
V_52 = F_21 ( V_24 , & V_20 ) ;
else
V_52 = F_29 ( V_24 , V_11 ) ;
return V_52 ;
}
static int
F_32 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_21 * V_99 ;
V_99 = F_33 ( V_2 , V_66 | V_100 ) ;
if ( V_99 == NULL )
goto V_37;
if ( F_34 ( V_2 , V_27 ,
F_35 ( V_11 -> V_20 . V_30 . V_31 ) ) )
goto V_37;
if ( F_36 ( V_2 , V_28 , V_11 -> V_20 . V_32 . V_33 ) )
goto V_37;
F_37 ( V_2 , V_99 ) ;
return 0 ;
V_37:
return - 1 ;
}
static int
F_38 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
int V_51 ;
struct V_21 * V_101 , * V_102 ;
V_101 = F_33 ( V_2 , V_67 | V_100 ) ;
if ( V_101 == NULL )
goto V_37;
if ( F_39 ( V_2 , V_56 ,
F_40 ( V_11 -> V_62 + 1 ) ) )
goto V_37;
for ( V_51 = 0 ; V_51 < V_11 -> V_62 + 1 ; V_51 ++ ) {
V_102 = F_33 ( V_2 ,
( V_61 + V_51 ) | V_100 ) ;
if ( V_102 == NULL )
goto V_37;
if ( F_41 ( V_2 , V_43 ,
V_11 -> V_40 [ V_51 ] . V_46 ) )
goto V_37;
if ( F_39 ( V_2 , V_44 ,
F_40 ( V_11 -> V_40 [ V_51 ] . V_48 ) ) )
goto V_37;
if ( F_39 ( V_2 , V_45 ,
F_40 ( V_11 -> V_40 [ V_51 ] . V_50 ) ) )
goto V_37;
F_37 ( V_2 , V_102 ) ;
}
F_37 ( V_2 , V_101 ) ;
return 0 ;
V_37:
return - 1 ;
}
static int
F_42 ( struct V_1 * V_2 , T_1 V_103 , T_1 V_104 , T_1 type ,
int V_105 , struct V_10 * V_11 )
{
struct V_89 * V_90 ;
struct V_106 * V_107 ;
unsigned int V_13 = V_103 ? V_108 : 0 ;
int V_78 ;
V_105 = F_43 ( V_109 , V_105 ) ;
V_90 = F_44 ( V_2 , V_103 , V_104 , V_105 , sizeof( * V_107 ) , V_13 ) ;
if ( V_90 == NULL )
goto V_110;
V_107 = F_45 ( V_90 ) ;
V_107 -> V_111 = V_112 ;
V_107 -> V_113 = V_114 ;
V_107 -> V_115 = 0 ;
if ( F_41 ( V_2 , V_70 , V_11 -> V_46 ) )
goto V_37;
if ( F_39 ( V_2 , V_76 , F_40 ( V_11 -> V_17 ) ) )
goto V_37;
if ( F_32 ( V_2 , V_11 ) < 0 )
goto V_37;
if ( F_38 ( V_2 , V_11 ) < 0 )
goto V_37;
if ( F_39 ( V_2 , V_68 , F_40 ( V_11 -> V_34 ) ) )
goto V_37;
if ( V_11 -> V_13 & V_15 )
V_78 = V_79 ;
else
V_78 = V_80 ;
if ( F_39 ( V_2 , V_77 , F_40 ( V_78 ) ) )
goto V_37;
F_46 ( V_2 , V_90 ) ;
return V_2 -> V_116 ;
V_110:
V_37:
F_47 ( V_2 , V_90 ) ;
return - 1 ;
}
static int
F_48 ( struct V_1 * V_2 , struct V_117 * V_118 )
{
struct V_10 * V_94 , * V_119 ;
F_49 () ;
V_119 = (struct V_10 * ) V_118 -> args [ 1 ] ;
for (; V_118 -> args [ 0 ] < V_120 ; V_118 -> args [ 0 ] ++ ) {
V_121:
F_50 (cur,
&nf_ct_helper_hash[cb->args[0]], hnode) {
if ( ! ( V_94 -> V_13 & V_14 ) )
continue;
if ( V_118 -> args [ 1 ] ) {
if ( V_94 != V_119 )
continue;
V_118 -> args [ 1 ] = 0 ;
}
if ( F_42 ( V_2 ,
F_51 ( V_118 -> V_2 ) . V_103 ,
V_118 -> V_90 -> V_122 ,
F_52 ( V_118 -> V_90 -> V_123 ) ,
V_124 , V_94 ) < 0 ) {
V_118 -> args [ 1 ] = ( unsigned long ) V_94 ;
goto V_125;
}
}
}
if ( V_118 -> args [ 1 ] ) {
V_118 -> args [ 1 ] = 0 ;
goto V_121;
}
V_125:
F_53 () ;
return V_2 -> V_116 ;
}
static int F_54 ( struct V_86 * V_86 , struct V_87 * V_88 ,
struct V_1 * V_2 , const struct V_89 * V_90 ,
const struct V_21 * const V_24 [] ,
struct V_91 * V_92 )
{
int V_52 = - V_126 ;
struct V_10 * V_94 ;
struct V_1 * V_127 ;
char * V_93 = NULL ;
struct V_19 V_20 ;
struct V_63 * V_95 ;
bool V_128 = false ;
if ( V_90 -> V_96 & V_129 ) {
struct V_130 V_131 = {
. V_132 = F_48 ,
} ;
return F_55 ( V_88 , V_2 , V_90 , & V_131 ) ;
}
if ( V_24 [ V_70 ] )
V_93 = F_12 ( V_24 [ V_70 ] ) ;
if ( V_24 [ V_66 ] ) {
V_52 = F_5 ( & V_20 , V_24 [ V_66 ] ) ;
if ( V_52 < 0 )
return V_52 ;
V_128 = true ;
}
F_31 (nlcth, &nfnl_cthelper_list, list) {
V_94 = & V_95 -> V_11 ;
if ( V_93 &&
strncmp ( V_94 -> V_46 , V_93 , V_47 ) )
continue;
if ( V_128 &&
( V_20 . V_30 . V_31 != V_94 -> V_20 . V_30 . V_31 ||
V_20 . V_32 . V_33 != V_94 -> V_20 . V_32 . V_33 ) )
continue;
V_127 = F_56 ( V_133 , V_59 ) ;
if ( V_127 == NULL ) {
V_52 = - V_60 ;
break;
}
V_52 = F_42 ( V_127 , F_51 ( V_2 ) . V_103 ,
V_90 -> V_122 ,
F_52 ( V_90 -> V_123 ) ,
V_124 , V_94 ) ;
if ( V_52 <= 0 ) {
F_57 ( V_127 ) ;
break;
}
V_52 = F_58 ( V_88 , V_127 , F_51 ( V_2 ) . V_103 ,
V_134 ) ;
if ( V_52 > 0 )
V_52 = 0 ;
return V_52 == - V_135 ? - V_136 : V_52 ;
}
return V_52 ;
}
static int F_59 ( struct V_86 * V_86 , struct V_87 * V_88 ,
struct V_1 * V_2 , const struct V_89 * V_90 ,
const struct V_21 * const V_24 [] ,
struct V_91 * V_92 )
{
char * V_93 = NULL ;
struct V_10 * V_94 ;
struct V_19 V_20 ;
bool V_128 = false , V_137 = false ;
struct V_63 * V_95 , * V_138 ;
int V_139 = 0 , V_52 ;
if ( V_24 [ V_70 ] )
V_93 = F_12 ( V_24 [ V_70 ] ) ;
if ( V_24 [ V_66 ] ) {
V_52 = F_5 ( & V_20 , V_24 [ V_66 ] ) ;
if ( V_52 < 0 )
return V_52 ;
V_128 = true ;
}
V_52 = - V_126 ;
F_60 (nlcth, n, &nfnl_cthelper_list, list) {
V_94 = & V_95 -> V_11 ;
V_139 ++ ;
if ( V_93 &&
strncmp ( V_94 -> V_46 , V_93 , V_47 ) )
continue;
if ( V_128 &&
( V_20 . V_30 . V_31 != V_94 -> V_20 . V_30 . V_31 ||
V_20 . V_32 . V_33 != V_94 -> V_20 . V_32 . V_33 ) )
continue;
if ( F_61 ( & V_94 -> V_140 ) ) {
V_137 = true ;
F_62 ( V_94 ) ;
F_20 ( V_94 -> V_40 ) ;
F_63 ( & V_95 -> V_81 ) ;
F_20 ( V_95 ) ;
} else {
V_52 = - V_85 ;
}
}
return ( V_137 || V_139 == 0 ) ? 0 : V_52 ;
}
static int T_2 F_64 ( void )
{
int V_52 ;
V_52 = F_65 ( & V_141 ) ;
if ( V_52 < 0 ) {
F_66 ( L_1 ) ;
goto V_142;
}
return 0 ;
V_142:
return V_52 ;
}
static void T_3 F_67 ( void )
{
struct V_10 * V_94 ;
struct V_63 * V_95 , * V_138 ;
F_68 ( & V_141 ) ;
F_60 (nlcth, n, &nfnl_cthelper_list, list) {
V_94 = & V_95 -> V_11 ;
F_62 ( V_94 ) ;
F_20 ( V_94 -> V_40 ) ;
F_20 ( V_95 ) ;
}
}
