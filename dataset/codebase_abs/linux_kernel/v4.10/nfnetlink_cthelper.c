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
V_51 = F_6 ( V_24 , V_52 , V_22 ,
V_53 ) ;
if ( V_51 < 0 )
return V_51 ;
if ( ! V_24 [ V_54 ] )
return - V_29 ;
V_11 -> V_55 =
F_15 ( F_16 ( V_24 [ V_54 ] ) ) ;
if ( V_11 -> V_55 != 0 &&
V_11 -> V_55 > V_56 )
return - V_57 ;
V_40 = F_18 ( sizeof( struct V_39 ) *
V_11 -> V_55 , V_58 ) ;
if ( V_40 == NULL )
return - V_59 ;
for ( V_50 = 0 ; V_50 < V_11 -> V_55 ; V_50 ++ ) {
if ( ! V_24 [ V_60 + V_50 ] )
goto V_23;
V_51 = F_14 ( & V_40 [ V_50 ] ,
V_24 [ V_60 + V_50 ] ) ;
if ( V_51 < 0 )
goto V_23;
}
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
int V_51 ;
if ( ! V_24 [ V_61 ] || ! V_24 [ V_62 ] || ! V_24 [ V_63 ] )
return - V_29 ;
V_11 = F_18 ( sizeof( struct V_10 ) , V_58 ) ;
if ( V_11 == NULL )
return - V_59 ;
V_51 = F_17 ( V_11 , V_24 [ V_62 ] ) ;
if ( V_51 < 0 )
goto V_23;
strncpy ( V_11 -> V_46 , F_11 ( V_24 [ V_64 ] ) , V_47 ) ;
V_11 -> V_34 = F_15 ( F_16 ( V_24 [ V_63 ] ) ) ;
V_11 -> V_13 |= V_14 ;
memcpy ( & V_11 -> V_20 , V_20 , sizeof( struct V_19 ) ) ;
V_11 -> V_65 = V_66 ;
V_11 -> V_9 = F_1 ;
V_11 -> V_67 = F_10 ;
V_11 -> V_68 = F_12 ;
if ( V_24 [ V_69 ] )
V_11 -> V_17 = F_15 ( F_16 ( V_24 [ V_69 ] ) ) ;
if ( V_24 [ V_70 ] ) {
int V_71 = F_15 ( F_16 ( V_24 [ V_70 ] ) ) ;
switch( V_71 ) {
case V_72 :
V_11 -> V_13 |= V_15 ;
break;
case V_73 :
V_11 -> V_13 &= ~ V_15 ;
break;
}
}
V_51 = F_21 ( V_11 ) ;
if ( V_51 < 0 )
goto V_23;
return 0 ;
V_23:
F_19 ( V_11 ) ;
return V_51 ;
}
static int
F_22 ( const struct V_21 * const V_24 [] ,
struct V_10 * V_11 )
{
int V_51 ;
if ( V_24 [ V_63 ] )
return - V_74 ;
if ( V_24 [ V_62 ] ) {
V_51 = F_17 ( V_11 ,
V_24 [ V_62 ] ) ;
if ( V_51 < 0 )
return V_51 ;
}
if ( V_24 [ V_69 ] )
V_11 -> V_17 = F_15 ( F_16 ( V_24 [ V_69 ] ) ) ;
if ( V_24 [ V_70 ] ) {
int V_71 = F_15 ( F_16 ( V_24 [ V_70 ] ) ) ;
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
static int F_23 ( struct V_75 * V_75 , struct V_76 * V_77 ,
struct V_1 * V_2 , const struct V_78 * V_79 ,
const struct V_21 * const V_24 [] )
{
const char * V_80 ;
struct V_10 * V_81 , * V_11 = NULL ;
struct V_19 V_20 ;
int V_51 = 0 , V_50 ;
if ( ! V_24 [ V_64 ] || ! V_24 [ V_61 ] )
return - V_29 ;
V_80 = F_11 ( V_24 [ V_64 ] ) ;
V_51 = F_5 ( & V_20 , V_24 [ V_61 ] ) ;
if ( V_51 < 0 )
return V_51 ;
F_24 () ;
for ( V_50 = 0 ; V_50 < V_82 && ! V_11 ; V_50 ++ ) {
F_25 (cur, &nf_ct_helper_hash[i], hnode) {
if ( ! ( V_81 -> V_13 & V_14 ) )
continue;
if ( strncmp ( V_81 -> V_46 , V_80 ,
V_47 ) != 0 )
continue;
if ( ( V_20 . V_30 . V_31 != V_81 -> V_20 . V_30 . V_31 ||
V_20 . V_32 . V_33 != V_81 -> V_20 . V_32 . V_33 ) )
continue;
if ( V_79 -> V_83 & V_84 ) {
V_51 = - V_85 ;
goto V_23;
}
V_11 = V_81 ;
break;
}
}
F_26 () ;
if ( V_11 == NULL )
V_51 = F_20 ( V_24 , & V_20 ) ;
else
V_51 = F_22 ( V_24 , V_11 ) ;
return V_51 ;
V_23:
F_26 () ;
return V_51 ;
}
static int
F_27 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_21 * V_86 ;
V_86 = F_28 ( V_2 , V_61 | V_87 ) ;
if ( V_86 == NULL )
goto V_37;
if ( F_29 ( V_2 , V_27 ,
F_30 ( V_11 -> V_20 . V_30 . V_31 ) ) )
goto V_37;
if ( F_31 ( V_2 , V_28 , V_11 -> V_20 . V_32 . V_33 ) )
goto V_37;
F_32 ( V_2 , V_86 ) ;
return 0 ;
V_37:
return - 1 ;
}
static int
F_33 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
int V_50 ;
struct V_21 * V_88 , * V_89 ;
V_88 = F_28 ( V_2 , V_62 | V_87 ) ;
if ( V_88 == NULL )
goto V_37;
if ( F_34 ( V_2 , V_54 ,
F_35 ( V_11 -> V_55 ) ) )
goto V_37;
for ( V_50 = 0 ; V_50 < V_11 -> V_55 ; V_50 ++ ) {
V_89 = F_28 ( V_2 ,
( V_60 + V_50 ) | V_87 ) ;
if ( V_89 == NULL )
goto V_37;
if ( F_36 ( V_2 , V_43 ,
V_11 -> V_40 [ V_50 ] . V_46 ) )
goto V_37;
if ( F_34 ( V_2 , V_44 ,
F_35 ( V_11 -> V_40 [ V_50 ] . V_48 ) ) )
goto V_37;
if ( F_34 ( V_2 , V_45 ,
F_35 ( V_11 -> V_40 [ V_50 ] . V_49 ) ) )
goto V_37;
F_32 ( V_2 , V_89 ) ;
}
F_32 ( V_2 , V_88 ) ;
return 0 ;
V_37:
return - 1 ;
}
static int
F_37 ( struct V_1 * V_2 , T_1 V_90 , T_1 V_91 , T_1 type ,
int V_92 , struct V_10 * V_11 )
{
struct V_78 * V_79 ;
struct V_93 * V_94 ;
unsigned int V_13 = V_90 ? V_95 : 0 ;
int V_71 ;
V_92 |= V_96 << 8 ;
V_79 = F_38 ( V_2 , V_90 , V_91 , V_92 , sizeof( * V_94 ) , V_13 ) ;
if ( V_79 == NULL )
goto V_97;
V_94 = F_39 ( V_79 ) ;
V_94 -> V_98 = V_99 ;
V_94 -> V_100 = V_101 ;
V_94 -> V_102 = 0 ;
if ( F_36 ( V_2 , V_64 , V_11 -> V_46 ) )
goto V_37;
if ( F_34 ( V_2 , V_69 , F_35 ( V_11 -> V_17 ) ) )
goto V_37;
if ( F_27 ( V_2 , V_11 ) < 0 )
goto V_37;
if ( F_33 ( V_2 , V_11 ) < 0 )
goto V_37;
if ( F_34 ( V_2 , V_63 , F_35 ( V_11 -> V_34 ) ) )
goto V_37;
if ( V_11 -> V_13 & V_15 )
V_71 = V_72 ;
else
V_71 = V_73 ;
if ( F_34 ( V_2 , V_70 , F_35 ( V_71 ) ) )
goto V_37;
F_40 ( V_2 , V_79 ) ;
return V_2 -> V_103 ;
V_97:
V_37:
F_41 ( V_2 , V_79 ) ;
return - 1 ;
}
static int
F_42 ( struct V_1 * V_2 , struct V_104 * V_105 )
{
struct V_10 * V_81 , * V_106 ;
F_24 () ;
V_106 = (struct V_10 * ) V_105 -> args [ 1 ] ;
for (; V_105 -> args [ 0 ] < V_82 ; V_105 -> args [ 0 ] ++ ) {
V_107:
F_25 (cur,
&nf_ct_helper_hash[cb->args[0]], hnode) {
if ( ! ( V_81 -> V_13 & V_14 ) )
continue;
if ( V_105 -> args [ 1 ] ) {
if ( V_81 != V_106 )
continue;
V_105 -> args [ 1 ] = 0 ;
}
if ( F_37 ( V_2 ,
F_43 ( V_105 -> V_2 ) . V_90 ,
V_105 -> V_79 -> V_108 ,
F_44 ( V_105 -> V_79 -> V_109 ) ,
V_110 , V_81 ) < 0 ) {
V_105 -> args [ 1 ] = ( unsigned long ) V_81 ;
goto V_111;
}
}
}
if ( V_105 -> args [ 1 ] ) {
V_105 -> args [ 1 ] = 0 ;
goto V_107;
}
V_111:
F_26 () ;
return V_2 -> V_103 ;
}
static int F_45 ( struct V_75 * V_75 , struct V_76 * V_77 ,
struct V_1 * V_2 , const struct V_78 * V_79 ,
const struct V_21 * const V_24 [] )
{
int V_51 = - V_112 , V_50 ;
struct V_10 * V_81 ;
struct V_1 * V_113 ;
char * V_80 = NULL ;
struct V_19 V_20 ;
bool V_114 = false ;
if ( V_79 -> V_83 & V_115 ) {
struct V_116 V_117 = {
. V_118 = F_42 ,
} ;
return F_46 ( V_77 , V_2 , V_79 , & V_117 ) ;
}
if ( V_24 [ V_64 ] )
V_80 = F_11 ( V_24 [ V_64 ] ) ;
if ( V_24 [ V_61 ] ) {
V_51 = F_5 ( & V_20 , V_24 [ V_61 ] ) ;
if ( V_51 < 0 )
return V_51 ;
V_114 = true ;
}
for ( V_50 = 0 ; V_50 < V_82 ; V_50 ++ ) {
F_25 (cur, &nf_ct_helper_hash[i], hnode) {
if ( ! ( V_81 -> V_13 & V_14 ) )
continue;
if ( V_80 && strncmp ( V_81 -> V_46 , V_80 ,
V_47 ) != 0 ) {
continue;
}
if ( V_114 &&
( V_20 . V_30 . V_31 != V_81 -> V_20 . V_30 . V_31 ||
V_20 . V_32 . V_33 != V_81 -> V_20 . V_32 . V_33 ) )
continue;
V_113 = F_47 ( V_119 , V_58 ) ;
if ( V_113 == NULL ) {
V_51 = - V_59 ;
break;
}
V_51 = F_37 ( V_113 , F_43 ( V_2 ) . V_90 ,
V_79 -> V_108 ,
F_44 ( V_79 -> V_109 ) ,
V_110 , V_81 ) ;
if ( V_51 <= 0 ) {
F_48 ( V_113 ) ;
break;
}
V_51 = F_49 ( V_77 , V_113 , F_43 ( V_2 ) . V_90 ,
V_120 ) ;
if ( V_51 > 0 )
V_51 = 0 ;
return V_51 == - V_121 ? - V_122 : V_51 ;
}
}
return V_51 ;
}
static int F_50 ( struct V_75 * V_75 , struct V_76 * V_77 ,
struct V_1 * V_2 , const struct V_78 * V_79 ,
const struct V_21 * const V_24 [] )
{
char * V_80 = NULL ;
struct V_10 * V_81 ;
struct V_123 * V_124 ;
struct V_19 V_20 ;
bool V_114 = false , V_125 = false ;
int V_50 , V_126 = 0 , V_51 ;
if ( V_24 [ V_64 ] )
V_80 = F_11 ( V_24 [ V_64 ] ) ;
if ( V_24 [ V_61 ] ) {
V_51 = F_5 ( & V_20 , V_24 [ V_61 ] ) ;
if ( V_51 < 0 )
return V_51 ;
V_114 = true ;
}
for ( V_50 = 0 ; V_50 < V_82 ; V_50 ++ ) {
F_51 (cur, tmp, &nf_ct_helper_hash[i],
hnode) {
if ( ! ( V_81 -> V_13 & V_14 ) )
continue;
V_126 ++ ;
if ( V_80 && strncmp ( V_81 -> V_46 , V_80 ,
V_47 ) != 0 ) {
continue;
}
if ( V_114 &&
( V_20 . V_30 . V_31 != V_81 -> V_20 . V_30 . V_31 ||
V_20 . V_32 . V_33 != V_81 -> V_20 . V_32 . V_33 ) )
continue;
V_125 = true ;
F_52 ( V_81 ) ;
}
}
return ( V_125 || V_126 == 0 ) ? 0 : - V_112 ;
}
static int T_2 F_53 ( void )
{
int V_51 ;
V_51 = F_54 ( & V_127 ) ;
if ( V_51 < 0 ) {
F_55 ( L_1 ) ;
goto V_128;
}
return 0 ;
V_128:
return V_51 ;
}
static void T_3 F_56 ( void )
{
struct V_10 * V_81 ;
struct V_123 * V_124 ;
int V_50 ;
F_57 ( & V_127 ) ;
for ( V_50 = 0 ; V_50 < V_82 ; V_50 ++ ) {
F_51 (cur, tmp, &nf_ct_helper_hash[i],
hnode) {
if ( ! ( V_81 -> V_13 & V_14 ) )
continue;
F_52 ( V_81 ) ;
}
}
}
