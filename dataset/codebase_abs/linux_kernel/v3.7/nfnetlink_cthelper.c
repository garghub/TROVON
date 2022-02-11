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
struct V_21 * V_23 [ V_24 + 1 ] ;
F_6 ( V_23 , V_24 , V_22 , V_25 ) ;
if ( ! V_23 [ V_26 ] || ! V_23 [ V_27 ] )
return - V_28 ;
V_20 -> V_29 . V_30 = F_7 ( F_8 ( V_23 [ V_26 ] ) ) ;
V_20 -> V_31 . V_32 = F_9 ( V_23 [ V_27 ] ) ;
return 0 ;
}
static int
F_10 ( struct V_21 * V_22 , struct V_4 * V_5 )
{
const struct V_8 * V_9 = F_2 ( V_5 ) ;
if ( V_22 == NULL )
return - V_28 ;
if ( V_9 -> V_11 -> V_33 == 0 )
return - V_28 ;
memcpy ( & V_9 -> V_34 , F_11 ( V_22 ) , V_9 -> V_11 -> V_33 ) ;
return 0 ;
}
static int
F_12 ( struct V_1 * V_2 , const struct V_4 * V_5 )
{
const struct V_8 * V_9 = F_2 ( V_5 ) ;
if ( V_9 -> V_11 -> V_33 &&
F_13 ( V_2 , V_35 , V_9 -> V_11 -> V_33 , & V_9 -> V_34 ) )
goto V_36;
return 0 ;
V_36:
return - V_37 ;
}
static int
F_14 ( struct V_38 * V_39 ,
const struct V_21 * V_22 )
{
struct V_21 * V_23 [ V_40 + 1 ] ;
F_6 ( V_23 , V_40 , V_22 , V_41 ) ;
if ( ! V_23 [ V_42 ] ||
! V_23 [ V_43 ] ||
! V_23 [ V_44 ] )
return - V_28 ;
strncpy ( V_39 -> V_45 ,
F_11 ( V_23 [ V_42 ] ) , V_46 ) ;
V_39 -> V_47 =
F_15 ( F_16 ( V_23 [ V_43 ] ) ) ;
V_39 -> V_48 =
F_15 ( F_16 ( V_23 [ V_44 ] ) ) ;
return 0 ;
}
static int
F_17 ( struct V_10 * V_11 ,
const struct V_21 * V_22 )
{
int V_49 , V_50 ;
struct V_38 * V_39 ;
struct V_21 * V_23 [ V_51 + 1 ] ;
F_6 ( V_23 , V_51 , V_22 ,
V_52 ) ;
if ( ! V_23 [ V_53 ] )
return - V_28 ;
V_11 -> V_54 =
F_15 ( F_16 ( V_23 [ V_53 ] ) ) ;
if ( V_11 -> V_54 != 0 &&
V_11 -> V_54 > V_55 )
return - V_56 ;
V_39 = F_18 ( sizeof( struct V_38 ) *
V_11 -> V_54 , V_57 ) ;
if ( V_39 == NULL )
return - V_58 ;
for ( V_49 = 0 ; V_49 < V_11 -> V_54 ; V_49 ++ ) {
if ( ! V_23 [ V_59 + V_49 ] )
goto V_60;
V_50 = F_14 ( & V_39 [ V_49 ] ,
V_23 [ V_59 + V_49 ] ) ;
if ( V_50 < 0 )
goto V_60;
}
V_11 -> V_39 = V_39 ;
return 0 ;
V_60:
F_19 ( V_39 ) ;
return - V_28 ;
}
static int
F_20 ( const struct V_21 * const V_23 [] ,
struct V_19 * V_20 )
{
struct V_10 * V_11 ;
int V_50 ;
if ( ! V_23 [ V_61 ] || ! V_23 [ V_62 ] || ! V_23 [ V_63 ] )
return - V_28 ;
V_11 = F_18 ( sizeof( struct V_10 ) , V_57 ) ;
if ( V_11 == NULL )
return - V_58 ;
V_50 = F_17 ( V_11 , V_23 [ V_62 ] ) ;
if ( V_50 < 0 )
goto V_60;
strncpy ( V_11 -> V_45 , F_11 ( V_23 [ V_64 ] ) , V_46 ) ;
V_11 -> V_33 = F_15 ( F_16 ( V_23 [ V_63 ] ) ) ;
V_11 -> V_13 |= V_14 ;
memcpy ( & V_11 -> V_20 , V_20 , sizeof( struct V_19 ) ) ;
V_11 -> V_65 = V_66 ;
V_11 -> V_9 = F_1 ;
V_11 -> V_67 = F_10 ;
V_11 -> V_68 = F_12 ;
if ( V_23 [ V_69 ] )
V_11 -> V_17 = F_15 ( F_16 ( V_23 [ V_69 ] ) ) ;
if ( V_23 [ V_70 ] ) {
int V_71 = F_15 ( F_16 ( V_23 [ V_70 ] ) ) ;
switch( V_71 ) {
case V_72 :
V_11 -> V_13 |= V_15 ;
break;
case V_73 :
V_11 -> V_13 &= ~ V_15 ;
break;
}
}
V_50 = F_21 ( V_11 ) ;
if ( V_50 < 0 )
goto V_60;
return 0 ;
V_60:
F_19 ( V_11 ) ;
return V_50 ;
}
static int
F_22 ( const struct V_21 * const V_23 [] ,
struct V_10 * V_11 )
{
int V_50 ;
if ( V_23 [ V_63 ] )
return - V_74 ;
if ( V_23 [ V_62 ] ) {
V_50 = F_17 ( V_11 ,
V_23 [ V_62 ] ) ;
if ( V_50 < 0 )
return V_50 ;
}
if ( V_23 [ V_69 ] )
V_11 -> V_17 = F_15 ( F_16 ( V_23 [ V_69 ] ) ) ;
if ( V_23 [ V_70 ] ) {
int V_71 = F_15 ( F_16 ( V_23 [ V_70 ] ) ) ;
switch( V_71 ) {
case V_72 :
V_11 -> V_13 |= V_15 ;
break;
case V_73 :
V_11 -> V_13 &= ~ V_15 ;
break;
}
}
return 0 ;
}
static int
F_23 ( struct V_75 * V_76 , struct V_1 * V_2 ,
const struct V_77 * V_78 , const struct V_21 * const V_23 [] )
{
const char * V_79 ;
struct V_10 * V_80 , * V_11 = NULL ;
struct V_19 V_20 ;
struct V_81 * V_82 ;
int V_50 = 0 , V_49 ;
if ( ! V_23 [ V_64 ] || ! V_23 [ V_61 ] )
return - V_28 ;
V_79 = F_11 ( V_23 [ V_64 ] ) ;
V_50 = F_5 ( & V_20 , V_23 [ V_61 ] ) ;
if ( V_50 < 0 )
return V_50 ;
F_24 () ;
for ( V_49 = 0 ; V_49 < V_83 && ! V_11 ; V_49 ++ ) {
F_25 (cur, n, &nf_ct_helper_hash[i], hnode) {
if ( ! ( V_80 -> V_13 & V_14 ) )
continue;
if ( strncmp ( V_80 -> V_45 , V_79 ,
V_46 ) != 0 )
continue;
if ( ( V_20 . V_29 . V_30 != V_80 -> V_20 . V_29 . V_30 ||
V_20 . V_31 . V_32 != V_80 -> V_20 . V_31 . V_32 ) )
continue;
if ( V_78 -> V_84 & V_85 ) {
V_50 = - V_86 ;
goto V_60;
}
V_11 = V_80 ;
break;
}
}
F_26 () ;
if ( V_11 == NULL )
V_50 = F_20 ( V_23 , & V_20 ) ;
else
V_50 = F_22 ( V_23 , V_11 ) ;
return V_50 ;
V_60:
F_26 () ;
return V_50 ;
}
static int
F_27 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_21 * V_87 ;
V_87 = F_28 ( V_2 , V_61 | V_88 ) ;
if ( V_87 == NULL )
goto V_36;
if ( F_29 ( V_2 , V_26 ,
F_30 ( V_11 -> V_20 . V_29 . V_30 ) ) )
goto V_36;
if ( F_31 ( V_2 , V_27 , V_11 -> V_20 . V_31 . V_32 ) )
goto V_36;
F_32 ( V_2 , V_87 ) ;
return 0 ;
V_36:
return - 1 ;
}
static int
F_33 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
int V_49 ;
struct V_21 * V_89 , * V_90 ;
V_89 = F_28 ( V_2 , V_62 | V_88 ) ;
if ( V_89 == NULL )
goto V_36;
if ( F_34 ( V_2 , V_53 ,
F_35 ( V_11 -> V_54 ) ) )
goto V_36;
for ( V_49 = 0 ; V_49 < V_11 -> V_54 ; V_49 ++ ) {
V_90 = F_28 ( V_2 ,
( V_59 + V_49 ) | V_88 ) ;
if ( V_90 == NULL )
goto V_36;
if ( F_36 ( V_2 , V_42 ,
V_11 -> V_39 [ V_49 ] . V_45 ) )
goto V_36;
if ( F_34 ( V_2 , V_43 ,
F_35 ( V_11 -> V_39 [ V_49 ] . V_47 ) ) )
goto V_36;
if ( F_34 ( V_2 , V_44 ,
F_35 ( V_11 -> V_39 [ V_49 ] . V_48 ) ) )
goto V_36;
F_32 ( V_2 , V_90 ) ;
}
F_32 ( V_2 , V_89 ) ;
return 0 ;
V_36:
return - 1 ;
}
static int
F_37 ( struct V_1 * V_2 , T_1 V_91 , T_1 V_92 , T_1 type ,
int V_93 , struct V_10 * V_11 )
{
struct V_77 * V_78 ;
struct V_94 * V_95 ;
unsigned int V_13 = V_91 ? V_96 : 0 ;
int V_71 ;
V_93 |= V_97 << 8 ;
V_78 = F_38 ( V_2 , V_91 , V_92 , V_93 , sizeof( * V_95 ) , V_13 ) ;
if ( V_78 == NULL )
goto V_98;
V_95 = F_39 ( V_78 ) ;
V_95 -> V_99 = V_100 ;
V_95 -> V_101 = V_102 ;
V_95 -> V_103 = 0 ;
if ( F_36 ( V_2 , V_64 , V_11 -> V_45 ) )
goto V_36;
if ( F_34 ( V_2 , V_69 , F_35 ( V_11 -> V_17 ) ) )
goto V_36;
if ( F_27 ( V_2 , V_11 ) < 0 )
goto V_36;
if ( F_33 ( V_2 , V_11 ) < 0 )
goto V_36;
if ( F_34 ( V_2 , V_63 , F_35 ( V_11 -> V_33 ) ) )
goto V_36;
if ( V_11 -> V_13 & V_15 )
V_71 = V_72 ;
else
V_71 = V_73 ;
if ( F_34 ( V_2 , V_70 , F_35 ( V_71 ) ) )
goto V_36;
F_40 ( V_2 , V_78 ) ;
return V_2 -> V_104 ;
V_98:
V_36:
F_41 ( V_2 , V_78 ) ;
return - 1 ;
}
static int
F_42 ( struct V_1 * V_2 , struct V_105 * V_106 )
{
struct V_10 * V_80 , * V_107 ;
struct V_81 * V_82 ;
F_24 () ;
V_107 = (struct V_10 * ) V_106 -> args [ 1 ] ;
for (; V_106 -> args [ 0 ] < V_83 ; V_106 -> args [ 0 ] ++ ) {
V_108:
F_25 (cur, n,
&nf_ct_helper_hash[cb->args[0]], hnode) {
if ( ! ( V_80 -> V_13 & V_14 ) )
continue;
if ( V_106 -> args [ 1 ] ) {
if ( V_80 != V_107 )
continue;
V_106 -> args [ 1 ] = 0 ;
}
if ( F_37 ( V_2 ,
F_43 ( V_106 -> V_2 ) . V_91 ,
V_106 -> V_78 -> V_109 ,
F_44 ( V_106 -> V_78 -> V_110 ) ,
V_111 , V_80 ) < 0 ) {
V_106 -> args [ 1 ] = ( unsigned long ) V_80 ;
goto V_112;
}
}
}
if ( V_106 -> args [ 1 ] ) {
V_106 -> args [ 1 ] = 0 ;
goto V_108;
}
V_112:
F_26 () ;
return V_2 -> V_104 ;
}
static int
F_45 ( struct V_75 * V_76 , struct V_1 * V_2 ,
const struct V_77 * V_78 , const struct V_21 * const V_23 [] )
{
int V_50 = - V_113 , V_49 ;
struct V_10 * V_80 ;
struct V_81 * V_82 ;
struct V_1 * V_114 ;
char * V_79 = NULL ;
struct V_19 V_20 ;
bool V_115 = false ;
if ( V_78 -> V_84 & V_116 ) {
struct V_117 V_118 = {
. V_119 = F_42 ,
} ;
return F_46 ( V_76 , V_2 , V_78 , & V_118 ) ;
}
if ( V_23 [ V_64 ] )
V_79 = F_11 ( V_23 [ V_64 ] ) ;
if ( V_23 [ V_61 ] ) {
V_50 = F_5 ( & V_20 , V_23 [ V_61 ] ) ;
if ( V_50 < 0 )
return V_50 ;
V_115 = true ;
}
for ( V_49 = 0 ; V_49 < V_83 ; V_49 ++ ) {
F_25 (cur, n, &nf_ct_helper_hash[i], hnode) {
if ( ! ( V_80 -> V_13 & V_14 ) )
continue;
if ( V_79 && strncmp ( V_80 -> V_45 , V_79 ,
V_46 ) != 0 ) {
continue;
}
if ( V_115 &&
( V_20 . V_29 . V_30 != V_80 -> V_20 . V_29 . V_30 ||
V_20 . V_31 . V_32 != V_80 -> V_20 . V_31 . V_32 ) )
continue;
V_114 = F_47 ( V_120 , V_57 ) ;
if ( V_114 == NULL ) {
V_50 = - V_58 ;
break;
}
V_50 = F_37 ( V_114 , F_43 ( V_2 ) . V_91 ,
V_78 -> V_109 ,
F_44 ( V_78 -> V_110 ) ,
V_111 , V_80 ) ;
if ( V_50 <= 0 ) {
F_48 ( V_114 ) ;
break;
}
V_50 = F_49 ( V_76 , V_114 , F_43 ( V_2 ) . V_91 ,
V_121 ) ;
if ( V_50 > 0 )
V_50 = 0 ;
return V_50 == - V_122 ? - V_123 : V_50 ;
}
}
return V_50 ;
}
static int
F_50 ( struct V_75 * V_76 , struct V_1 * V_2 ,
const struct V_77 * V_78 , const struct V_21 * const V_23 [] )
{
char * V_79 = NULL ;
struct V_10 * V_80 ;
struct V_81 * V_82 , * V_124 ;
struct V_19 V_20 ;
bool V_115 = false , V_125 = false ;
int V_49 , V_126 = 0 , V_50 ;
if ( V_23 [ V_64 ] )
V_79 = F_11 ( V_23 [ V_64 ] ) ;
if ( V_23 [ V_61 ] ) {
V_50 = F_5 ( & V_20 , V_23 [ V_61 ] ) ;
if ( V_50 < 0 )
return V_50 ;
V_115 = true ;
}
for ( V_49 = 0 ; V_49 < V_83 ; V_49 ++ ) {
F_51 (cur, n, tmp, &nf_ct_helper_hash[i],
hnode) {
if ( ! ( V_80 -> V_13 & V_14 ) )
continue;
V_126 ++ ;
if ( V_79 && strncmp ( V_80 -> V_45 , V_79 ,
V_46 ) != 0 ) {
continue;
}
if ( V_115 &&
( V_20 . V_29 . V_30 != V_80 -> V_20 . V_29 . V_30 ||
V_20 . V_31 . V_32 != V_80 -> V_20 . V_31 . V_32 ) )
continue;
V_125 = true ;
F_52 ( V_80 ) ;
}
}
return ( V_125 || V_126 == 0 ) ? 0 : - V_113 ;
}
static int T_2 F_53 ( void )
{
int V_50 ;
V_50 = F_54 ( & V_127 ) ;
if ( V_50 < 0 ) {
F_55 ( L_1 ) ;
goto V_128;
}
return 0 ;
V_128:
return V_50 ;
}
static void T_3 F_56 ( void )
{
struct V_10 * V_80 ;
struct V_81 * V_82 , * V_124 ;
int V_49 ;
F_57 ( & V_127 ) ;
for ( V_49 = 0 ; V_49 < V_83 ; V_49 ++ ) {
F_51 (cur, n, tmp, &nf_ct_helper_hash[i],
hnode) {
if ( ! ( V_80 -> V_13 & V_14 ) )
continue;
F_52 ( V_80 ) ;
}
}
}
