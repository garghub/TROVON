static inline T_1 F_1 ( T_2 V_1 [ 3 ] )
{
T_1 V_2 ;
V_2 = ( V_1 [ 0 ] << 16 ) | ( V_1 [ 1 ] << 8 ) | V_1 [ 2 ] ;
return F_2 ( V_2 , V_3 ) ;
}
static void F_3 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_8 * V_9 = F_4 ( V_7 ) ;
struct V_10 * V_11 , * V_12 = NULL ;
struct V_13 * V_14 ;
struct V_15 * V_16 = NULL ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
int V_21 = 0 ;
T_1 V_22 ;
V_16 = F_5 ( V_7 ) ;
V_14 = V_5 -> V_23 ;
V_22 = F_1 ( V_9 -> V_1 ) ;
V_20 = & V_14 -> V_24 [ V_22 ] ;
F_6 (dummy, vni_list_head, hlist) {
if ( ! memcmp ( V_9 -> V_1 , V_11 -> V_1 , sizeof( V_11 -> V_1 ) ) &&
V_16 -> V_25 == V_11 -> V_26 . V_27 . V_28 ) {
V_12 = V_11 ;
break;
}
}
if ( ! V_12 )
goto V_29;
if ( V_9 -> V_30 )
goto V_29;
F_7 ( V_7 ) ;
F_8 ( V_7 , ! F_9 ( V_12 -> V_31 , F_10 ( V_12 -> V_32 ) ) ) ;
V_7 -> V_33 = F_11 ( V_7 , V_12 -> V_32 ) ;
F_12 ( V_7 , F_13 ( V_7 ) , V_34 ) ;
if ( F_14 ( F_13 ( V_7 ) -> V_35 , V_12 -> V_32 -> V_36 ) )
goto V_29;
F_15 ( V_7 ) ;
V_16 = F_5 ( V_7 ) ;
V_21 = F_16 ( V_16 , V_7 ) ;
if ( F_17 ( V_21 ) ) {
if ( V_37 )
F_18 ( L_1 ,
& V_16 -> V_25 , V_16 -> V_38 ) ;
if ( V_21 > 1 ) {
++ V_12 -> V_32 -> V_18 . V_39 ;
++ V_12 -> V_32 -> V_18 . V_40 ;
goto V_29;
}
}
V_18 = F_19 ( V_12 -> V_32 -> V_41 ) ;
F_20 ( & V_18 -> V_42 ) ;
V_18 -> V_43 ++ ;
V_18 -> V_44 += V_7 -> V_45 ;
F_21 ( & V_18 -> V_42 ) ;
F_22 ( V_7 ) ;
return;
V_29:
F_23 ( V_7 ) ;
}
static int F_24 ( struct V_46 * V_32 )
{
V_32 -> V_41 = F_25 ( struct V_17 ) ;
if ( ! V_32 -> V_41 )
return - V_47 ;
return 0 ;
}
static void F_26 ( struct V_46 * V_32 )
{
F_27 ( V_32 -> V_41 ) ;
}
static int F_28 ( struct V_46 * V_32 )
{
struct V_10 * V_12 = F_29 ( V_32 ) ;
struct V_31 * V_31 = V_12 -> V_31 ;
struct V_13 * V_14 = F_30 ( V_12 -> V_31 , V_48 ) ;
struct V_4 * V_5 ;
V_5 = F_31 ( V_31 , F_32 ( V_49 ) , F_3 , V_14 ,
false , false ) ;
if ( F_33 ( V_5 ) )
return F_34 ( V_5 ) ;
V_12 -> V_50 = V_5 ;
return 0 ;
}
static int F_35 ( struct V_46 * V_32 )
{
struct V_10 * V_12 = F_29 ( V_32 ) ;
struct V_4 * V_5 = V_12 -> V_50 ;
F_36 ( V_5 ) ;
return 0 ;
}
static T_3 F_37 ( struct V_6 * V_7 , struct V_46 * V_32 )
{
struct V_10 * V_12 = F_29 ( V_32 ) ;
struct V_4 * V_5 = V_12 -> V_50 ;
struct V_51 * V_52 = NULL ;
const struct V_15 * V_53 ;
struct V_54 V_55 ;
int V_21 ;
T_4 V_56 ;
T_5 V_38 , V_57 ;
V_53 = F_5 ( V_7 ) ;
F_7 ( V_7 ) ;
V_56 = F_38 ( F_10 ( V_32 ) , V_7 , 0 , 0 , true ) ;
V_38 = V_12 -> V_38 ;
if ( V_38 == 1 )
V_38 = F_39 ( V_53 , V_7 ) ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
V_55 . V_58 = F_40 ( V_38 ) ;
V_55 . V_59 = V_12 -> V_26 . V_27 . V_28 ;
V_52 = F_41 ( V_12 -> V_31 , & V_55 ) ;
if ( F_33 ( V_52 ) ) {
F_42 ( V_32 , L_2 , & V_55 . V_59 ) ;
V_32 -> V_18 . V_60 ++ ;
goto V_61;
}
if ( V_52 -> V_62 . V_32 == V_32 ) {
F_42 ( V_32 , L_3 , & V_55 . V_59 ) ;
V_32 -> V_18 . V_63 ++ ;
goto V_64;
}
V_38 = F_43 ( V_38 , V_53 , V_7 ) ;
V_57 = V_12 -> V_57 ;
if ( ! V_57 && F_44 ( F_45 ( V_55 . V_59 ) ) )
V_57 = 1 ;
V_57 = V_57 ? : F_46 ( & V_52 -> V_62 ) ;
V_21 = F_47 ( V_5 , V_52 , V_7 , V_55 . V_25 , V_55 . V_59 ,
V_38 , V_57 , 0 , V_56 , F_32 ( V_49 ) , 0 ,
V_12 -> V_1 , 0 , NULL , false ,
! F_9 ( V_12 -> V_31 , F_10 ( V_12 -> V_32 ) ) ) ;
if ( V_21 < 0 )
F_48 ( V_52 ) ;
F_49 ( V_21 , & V_32 -> V_18 , V_32 -> V_41 ) ;
return V_65 ;
V_64:
F_48 ( V_52 ) ;
V_61:
V_32 -> V_18 . V_66 ++ ;
F_50 ( V_7 ) ;
return V_65 ;
}
static void F_51 ( struct V_46 * V_32 ,
struct V_67 * V_68 )
{
F_52 ( V_68 -> V_69 , V_70 , sizeof( V_68 -> V_69 ) ) ;
F_52 ( V_68 -> V_71 , L_4 , sizeof( V_68 -> V_71 ) ) ;
}
static void F_53 ( struct V_46 * V_32 )
{
F_54 ( V_32 ) ;
V_32 -> V_72 = & V_73 ;
V_32 -> V_74 = & V_75 ;
V_32 -> V_76 = V_77 ;
F_55 ( V_32 , & V_78 ) ;
V_32 -> V_79 = 0 ;
V_32 -> V_80 |= V_81 ;
V_32 -> V_80 |= V_82 | V_83 ;
V_32 -> V_80 |= V_84 ;
V_32 -> V_80 |= V_85 ;
V_32 -> V_86 = V_32 -> V_80 ;
V_32 -> V_80 |= V_87 | V_88 ;
V_32 -> V_89 |= V_82 | V_83 | V_84 ;
V_32 -> V_89 |= V_85 ;
V_32 -> V_89 |= V_87 | V_88 ;
F_56 ( V_32 ) ;
V_32 -> V_90 |= V_91 ;
}
static int F_57 ( struct V_92 * V_93 [] , struct V_92 * V_94 [] )
{
if ( V_93 [ V_95 ] ) {
if ( F_58 ( V_93 [ V_95 ] ) != V_96 )
return - V_97 ;
if ( ! F_59 ( F_60 ( V_93 [ V_95 ] ) ) )
return - V_98 ;
}
if ( ! V_94 )
return - V_97 ;
if ( V_94 [ V_99 ] ) {
T_1 V_1 = F_61 ( V_94 [ V_99 ] ) ;
if ( V_1 >= V_100 )
return - V_101 ;
}
return 0 ;
}
static int F_62 ( struct V_31 * V_31 , struct V_46 * V_32 ,
struct V_92 * V_93 [] , struct V_92 * V_94 [] )
{
struct V_13 * V_14 = F_30 ( V_31 , V_48 ) ;
struct V_10 * V_11 , * V_12 = F_29 ( V_32 ) ;
struct V_19 * V_20 ;
struct V_102 V_26 ;
T_1 V_1 , V_22 ;
int V_21 ;
if ( ! V_94 [ V_99 ] || ! V_94 [ V_103 ] )
return - V_97 ;
V_12 -> V_31 = V_31 ;
V_12 -> V_32 = V_32 ;
V_1 = F_61 ( V_94 [ V_99 ] ) ;
V_12 -> V_1 [ 0 ] = ( V_1 & 0x00ff0000 ) >> 16 ;
V_12 -> V_1 [ 1 ] = ( V_1 & 0x0000ff00 ) >> 8 ;
V_12 -> V_1 [ 2 ] = V_1 & 0x000000ff ;
V_12 -> V_26 . V_27 . V_28 =
F_63 ( V_94 [ V_103 ] ) ;
if ( F_44 ( F_45 ( V_12 -> V_26 . V_27 . V_28 ) ) )
return - V_97 ;
V_26 = V_12 -> V_26 ;
V_22 = F_1 ( V_12 -> V_1 ) ;
V_20 = & V_14 -> V_24 [ V_22 ] ;
F_6 (dummy, vni_list_head, hlist) {
if ( ! memcmp ( V_12 -> V_1 , V_11 -> V_1 , sizeof( V_11 -> V_1 ) ) &&
! memcmp ( & V_26 , & V_11 -> V_26 , sizeof( V_11 -> V_26 ) ) )
return - V_104 ;
}
if ( V_93 [ V_95 ] == NULL )
F_64 ( V_32 ) ;
V_21 = F_65 ( V_32 ) ;
if ( V_21 )
return V_21 ;
if ( V_94 [ V_105 ] )
V_12 -> V_57 = F_66 ( V_94 [ V_105 ] ) ;
if ( V_94 [ V_106 ] )
V_12 -> V_38 = F_66 ( V_94 [ V_106 ] ) ;
F_67 ( & V_12 -> V_107 , & V_14 -> V_108 ) ;
F_68 ( & V_12 -> V_109 , & V_14 -> V_24 [ V_22 ] ) ;
return 0 ;
}
static void F_69 ( struct V_46 * V_32 , struct V_110 * V_111 )
{
struct V_10 * V_12 = F_29 ( V_32 ) ;
if ( ! F_70 ( & V_12 -> V_109 ) )
F_71 ( & V_12 -> V_109 ) ;
F_72 ( & V_12 -> V_107 ) ;
F_73 ( V_32 , V_111 ) ;
}
static T_6 F_74 ( const struct V_46 * V_32 )
{
return F_75 ( sizeof( T_1 ) ) +
F_75 ( sizeof( struct V_112 ) ) +
F_75 ( sizeof( T_5 ) ) +
F_75 ( sizeof( T_5 ) ) +
0 ;
}
static int F_76 ( struct V_6 * V_7 , const struct V_46 * V_32 )
{
struct V_10 * V_12 = F_29 ( V_32 ) ;
T_1 V_1 ;
V_1 = ( V_12 -> V_1 [ 0 ] << 16 ) | ( V_12 -> V_1 [ 1 ] << 8 ) | V_12 -> V_1 [ 2 ] ;
if ( F_77 ( V_7 , V_99 , V_1 ) )
goto V_113;
if ( F_78 ( V_7 , V_103 ,
V_12 -> V_26 . V_27 . V_28 ) )
goto V_113;
if ( F_79 ( V_7 , V_105 , V_12 -> V_57 ) ||
F_79 ( V_7 , V_106 , V_12 -> V_38 ) )
goto V_113;
return 0 ;
V_113:
return - V_114 ;
}
static T_7 int F_80 ( struct V_31 * V_31 )
{
struct V_13 * V_14 = F_30 ( V_31 , V_48 ) ;
unsigned int V_115 ;
F_81 ( & V_14 -> V_108 ) ;
for ( V_115 = 0 ; V_115 < V_116 ; ++ V_115 )
F_82 ( & V_14 -> V_24 [ V_115 ] ) ;
return 0 ;
}
static void T_8 F_83 ( struct V_31 * V_31 )
{
struct V_13 * V_14 = F_30 ( V_31 , V_48 ) ;
struct V_10 * V_12 , * V_107 ;
struct V_46 * V_32 , * V_117 ;
F_84 ( V_118 ) ;
F_85 () ;
F_86 (net, dev, aux)
if ( V_32 -> V_119 == & V_120 )
F_73 ( V_32 , & V_118 ) ;
F_87 (geneve, next, &gn->geneve_list, next) {
if ( ! F_9 ( F_10 ( V_12 -> V_32 ) , V_31 ) )
F_73 ( V_12 -> V_32 , & V_118 ) ;
}
F_88 ( & V_118 ) ;
F_89 () ;
}
static int T_9 F_90 ( void )
{
int V_121 ;
V_121 = F_91 ( & V_122 ) ;
if ( V_121 )
goto V_123;
V_121 = F_92 ( & V_120 ) ;
if ( V_121 )
goto V_124;
return 0 ;
V_124:
F_93 ( & V_122 ) ;
V_123:
return V_121 ;
}
static void T_10 F_94 ( void )
{
F_95 ( & V_120 ) ;
F_93 ( & V_122 ) ;
}
