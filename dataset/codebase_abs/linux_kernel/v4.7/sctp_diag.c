static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
union V_7 V_8 , V_9 ;
struct V_10 * V_11 ;
V_8 = F_2 ( V_6 -> V_12 . V_13 . V_14 . V_15 ,
struct V_16 , V_17 ) -> V_18 ;
V_9 = V_6 -> V_19 . V_20 -> V_21 ;
V_11 = V_6 -> V_19 . V_20 -> V_11 ;
V_2 -> V_22 = V_4 -> V_23 ;
V_2 -> V_24 . V_25 = F_3 ( V_6 -> V_12 . V_13 . V_26 ) ;
V_2 -> V_24 . V_27 = F_3 ( V_6 -> V_19 . V_26 ) ;
V_2 -> V_24 . V_28 = V_11 ? V_11 -> V_29 -> V_30 : 0 ;
F_4 ( V_4 , V_2 -> V_24 . V_31 ) ;
#if F_5 ( V_32 )
if ( V_4 -> V_23 == V_33 ) {
* (struct V_34 * ) V_2 -> V_24 . V_35 = V_8 . V_36 . V_37 ;
* (struct V_34 * ) V_2 -> V_24 . V_38 = V_9 . V_36 . V_37 ;
} else
#endif
{
memset ( & V_2 -> V_24 . V_35 , 0 , sizeof( V_2 -> V_24 . V_35 ) ) ;
memset ( & V_2 -> V_24 . V_38 , 0 , sizeof( V_2 -> V_24 . V_38 ) ) ;
V_2 -> V_24 . V_35 [ 0 ] = V_8 . V_39 . V_40 . V_41 ;
V_2 -> V_24 . V_38 [ 0 ] = V_9 . V_39 . V_40 . V_41 ;
}
V_2 -> V_42 = V_6 -> V_43 ;
V_2 -> V_44 = V_45 ;
V_2 -> V_46 = V_6 -> V_47 ;
V_2 -> V_48 = F_6 (
V_6 -> V_49 [ V_45 ] - V_50 ) ;
}
static int F_7 ( struct V_51 * V_52 ,
struct V_53 * V_14 )
{
struct V_16 * V_8 ;
int V_54 = sizeof( struct V_55 ) ;
int V_56 = 0 ;
struct V_57 * V_58 ;
void * V_59 = NULL ;
F_8 (laddr, address_list, list)
V_56 ++ ;
V_58 = F_9 ( V_52 , V_60 , V_54 * V_56 ) ;
if ( ! V_58 )
return - V_61 ;
V_59 = F_10 ( V_58 ) ;
F_8 (laddr, address_list, list) {
memcpy ( V_59 , & V_8 -> V_18 , V_54 ) ;
V_59 += V_54 ;
}
return 0 ;
}
static int F_11 ( struct V_51 * V_52 ,
struct V_5 * V_6 )
{
int V_54 = sizeof( struct V_55 ) ;
struct V_62 * V_63 ;
struct V_57 * V_58 ;
void * V_59 = NULL ;
V_58 = F_9 ( V_52 , V_64 ,
V_54 * V_6 -> V_19 . V_65 ) ;
if ( ! V_58 )
return - V_61 ;
V_59 = F_10 ( V_58 ) ;
F_12 (from, &asoc->peer.transport_addr_list,
transports) {
memcpy ( V_59 , & V_63 -> V_21 , V_54 ) ;
V_59 += V_54 ;
}
return 0 ;
}
static int F_13 ( struct V_3 * V_4 , struct V_5 * V_6 ,
struct V_51 * V_52 ,
const struct V_66 * V_67 ,
struct V_68 * V_69 ,
int V_70 , T_1 V_71 , T_2 V_72 ,
const struct V_73 * V_74 )
{
struct V_75 * V_76 = F_14 ( V_4 ) -> V_76 ;
struct V_53 * V_77 ;
struct V_1 * V_2 ;
struct V_73 * V_78 ;
int V_79 = V_67 -> V_80 ;
struct V_81 V_82 ;
void * V_59 = NULL ;
V_78 = F_15 ( V_52 , V_70 , V_71 , V_74 -> V_83 , sizeof( * V_2 ) ,
V_72 ) ;
if ( ! V_78 )
return - V_61 ;
V_2 = F_16 ( V_78 ) ;
F_17 ( ! F_18 ( V_4 ) ) ;
if ( V_6 ) {
F_1 ( V_2 , V_4 , V_6 ) ;
} else {
F_19 ( V_2 , V_4 ) ;
V_2 -> V_42 = V_4 -> V_84 ;
V_2 -> V_44 = 0 ;
V_2 -> V_46 = 0 ;
}
if ( F_20 ( V_4 , V_52 , V_2 , V_79 , V_69 ) )
goto V_85;
if ( V_79 & ( 1 << ( V_86 - 1 ) ) ) {
T_1 V_87 [ V_88 ] ;
int V_89 ;
if ( V_6 && V_6 -> V_76 -> V_90 )
V_89 = V_6 -> V_91 ;
else
V_89 = F_21 ( V_4 ) ;
V_87 [ V_92 ] = V_89 ;
if ( V_6 && V_6 -> V_76 -> V_93 )
V_89 = F_22 ( & V_6 -> V_94 ) ;
else
V_89 = F_23 ( V_4 ) ;
V_87 [ V_95 ] = V_89 ;
V_87 [ V_96 ] = V_4 -> V_97 ;
V_87 [ V_98 ] = V_4 -> V_99 ;
V_87 [ V_100 ] = V_4 -> V_101 ;
V_87 [ V_102 ] = V_4 -> V_103 ;
V_87 [ V_104 ] = F_22 ( & V_4 -> V_105 ) ;
V_87 [ V_106 ] = V_4 -> V_107 . V_108 ;
V_87 [ V_109 ] = F_22 ( & V_4 -> V_110 ) ;
if ( F_24 ( V_52 , V_86 , sizeof( V_87 ) , & V_87 ) < 0 )
goto V_85;
}
if ( V_79 & ( 1 << ( V_111 - 1 ) ) ) {
struct V_57 * V_58 ;
V_58 = F_25 ( V_52 , V_111 ,
sizeof( struct V_112 ) ,
V_113 ) ;
if ( ! V_58 )
goto V_85;
V_59 = F_10 ( V_58 ) ;
}
V_82 . V_114 = (struct V_112 * ) V_59 ;
V_82 . V_6 = V_6 ;
F_26 ( V_4 , V_2 , & V_82 ) ;
V_77 = V_6 ? & V_6 -> V_12 . V_13 . V_14
: & V_76 -> V_12 . V_13 . V_14 ;
if ( F_7 ( V_52 , V_77 ) )
goto V_85;
if ( V_6 && ( V_79 & ( 1 << ( V_115 - 1 ) ) ) )
if ( F_27 ( V_52 , V_115 , L_1 ) < 0 )
goto V_85;
if ( V_6 && F_11 ( V_52 , V_6 ) )
goto V_85;
F_28 ( V_52 , V_78 ) ;
return 0 ;
V_85:
F_29 ( V_52 , V_78 ) ;
return - V_61 ;
}
static T_3 F_30 ( struct V_5 * V_6 )
{
int V_54 = sizeof( struct V_55 ) ;
int V_56 = 0 ;
struct V_16 * V_8 ;
F_8 (laddr, &asoc->base.bind_addr.address_list,
list)
V_56 ++ ;
return F_31 ( sizeof( struct V_112 ) )
+ F_31 ( 1 )
+ F_31 ( 1 )
+ F_31 ( 1 )
+ F_31 ( V_54 * V_6 -> V_19 . V_65 )
+ F_31 ( V_54 * V_56 )
+ F_31 ( sizeof( struct V_116 ) )
+ F_31 ( sizeof( struct V_1 ) )
+ 64 ;
}
static int F_32 ( struct V_62 * V_117 , void * V_118 )
{
struct V_5 * V_119 = V_117 -> V_6 ;
struct V_3 * V_4 = V_117 -> V_6 -> V_12 . V_4 ;
struct V_120 * V_121 = V_118 ;
struct V_51 * V_122 = V_121 -> V_52 ;
const struct V_66 * V_67 = V_121 -> V_2 ;
const struct V_73 * V_78 = V_121 -> V_78 ;
struct V_123 * V_123 = F_33 ( V_122 -> V_4 ) ;
struct V_51 * V_124 ;
int V_125 ;
V_125 = F_34 ( V_4 , V_67 -> V_24 . V_31 ) ;
if ( V_125 )
goto V_126;
V_125 = - V_127 ;
V_124 = F_35 ( F_30 ( V_119 ) , V_128 ) ;
if ( ! V_124 )
goto V_126;
F_36 ( V_4 ) ;
if ( V_4 != V_119 -> V_12 . V_4 ) {
F_37 ( V_4 ) ;
V_4 = V_119 -> V_12 . V_4 ;
F_36 ( V_4 ) ;
}
V_125 = F_13 ( V_4 , V_119 , V_124 , V_67 ,
F_38 ( F_39 ( V_122 ) . V_4 ) ,
F_39 ( V_122 ) . V_70 ,
V_78 -> V_129 , 0 , V_78 ) ;
F_37 ( V_4 ) ;
if ( V_125 < 0 ) {
F_40 ( V_125 == - V_61 ) ;
F_41 ( V_124 ) ;
goto V_126;
}
V_125 = F_42 ( V_123 -> V_130 , V_124 , F_39 ( V_122 ) . V_70 ,
V_131 ) ;
if ( V_125 > 0 )
V_125 = 0 ;
V_126:
return V_125 ;
}
static int F_43 ( struct V_62 * V_117 , void * V_118 )
{
struct V_75 * V_76 = V_117 -> V_6 -> V_76 ;
struct V_120 * V_121 = V_118 ;
struct V_3 * V_4 = V_76 -> V_12 . V_4 ;
struct V_51 * V_52 = V_121 -> V_52 ;
struct V_132 * V_133 = V_121 -> V_133 ;
const struct V_66 * V_2 = V_121 -> V_2 ;
struct V_5 * V_119 =
F_2 ( V_76 -> V_134 . V_15 , struct V_5 , V_134 ) ;
int V_125 = 0 ;
if ( V_117 -> V_6 != V_119 )
goto V_126;
if ( V_2 -> V_135 != V_136 && V_4 -> V_23 != V_2 -> V_135 )
goto V_126;
F_36 ( V_4 ) ;
if ( V_4 != V_119 -> V_12 . V_4 )
goto V_137;
F_12 (assoc, &ep->asocs, asocs) {
if ( V_133 -> args [ 4 ] < V_133 -> args [ 1 ] )
goto V_15;
if ( V_2 -> V_24 . V_25 != F_3 ( V_119 -> V_12 . V_13 . V_26 ) &&
V_2 -> V_24 . V_25 )
goto V_15;
if ( V_2 -> V_24 . V_27 != F_3 ( V_119 -> V_19 . V_26 ) &&
V_2 -> V_24 . V_27 )
goto V_15;
if ( ! V_133 -> args [ 3 ] &&
F_13 ( V_4 , NULL , V_52 , V_2 ,
F_38 ( F_39 ( V_133 -> V_52 ) . V_4 ) ,
F_39 ( V_133 -> V_52 ) . V_70 ,
V_133 -> V_78 -> V_129 ,
V_138 , V_133 -> V_78 ) < 0 ) {
V_133 -> args [ 3 ] = 1 ;
V_125 = 2 ;
goto V_137;
}
V_133 -> args [ 3 ] = 1 ;
if ( F_13 ( V_4 , V_119 , V_52 , V_2 ,
F_38 ( F_39 ( V_133 -> V_52 ) . V_4 ) ,
F_39 ( V_133 -> V_52 ) . V_70 ,
V_133 -> V_78 -> V_129 , 0 , V_133 -> V_78 ) < 0 ) {
V_125 = 2 ;
goto V_137;
}
V_15:
V_133 -> args [ 4 ] ++ ;
}
V_133 -> args [ 1 ] = 0 ;
V_133 -> args [ 2 ] ++ ;
V_133 -> args [ 3 ] = 0 ;
V_133 -> args [ 4 ] = 0 ;
V_137:
F_37 ( V_4 ) ;
return V_125 ;
V_126:
V_133 -> args [ 2 ] ++ ;
return V_125 ;
}
static int F_44 ( struct V_75 * V_76 , void * V_118 )
{
struct V_120 * V_121 = V_118 ;
struct V_3 * V_4 = V_76 -> V_12 . V_4 ;
struct V_51 * V_52 = V_121 -> V_52 ;
struct V_132 * V_133 = V_121 -> V_133 ;
const struct V_66 * V_2 = V_121 -> V_2 ;
struct V_123 * V_123 = F_33 ( V_52 -> V_4 ) ;
struct V_139 * V_140 = F_45 ( V_4 ) ;
int V_125 = 0 ;
if ( ! F_46 ( F_33 ( V_4 ) , V_123 ) )
goto V_126;
if ( V_133 -> args [ 4 ] < V_133 -> args [ 1 ] )
goto V_15;
if ( ( V_2 -> V_141 & ~ V_142 ) && ! F_47 ( & V_76 -> V_134 ) )
goto V_15;
if ( V_2 -> V_135 != V_136 &&
V_4 -> V_23 != V_2 -> V_135 )
goto V_15;
if ( V_2 -> V_24 . V_25 != V_140 -> V_143 &&
V_2 -> V_24 . V_25 )
goto V_15;
if ( V_2 -> V_24 . V_27 != V_140 -> V_144 &&
V_2 -> V_24 . V_27 )
goto V_15;
if ( F_13 ( V_4 , NULL , V_52 , V_2 ,
F_38 ( F_39 ( V_133 -> V_52 ) . V_4 ) ,
F_39 ( V_133 -> V_52 ) . V_70 ,
V_133 -> V_78 -> V_129 , V_138 ,
V_133 -> V_78 ) < 0 ) {
V_125 = 2 ;
goto V_126;
}
V_15:
V_133 -> args [ 4 ] ++ ;
V_126:
return V_125 ;
}
static void F_26 ( struct V_3 * V_4 , struct V_1 * V_2 ,
void * V_59 )
{
struct V_81 * V_82 = (struct V_81 * ) V_59 ;
if ( V_82 -> V_6 ) {
V_2 -> V_145 = F_22 ( & V_82 -> V_6 -> V_94 ) ;
V_2 -> V_146 = V_82 -> V_6 -> V_91 ;
} else {
V_2 -> V_145 = V_4 -> V_147 ;
V_2 -> V_146 = V_4 -> V_148 ;
}
if ( V_82 -> V_114 )
F_48 ( V_4 , V_82 -> V_6 , V_82 -> V_114 ) ;
}
static int F_49 ( struct V_51 * V_122 ,
const struct V_73 * V_78 ,
const struct V_66 * V_67 )
{
struct V_123 * V_123 = F_33 ( V_122 -> V_4 ) ;
union V_7 V_8 , V_9 ;
struct V_120 V_121 = {
. V_52 = V_122 ,
. V_2 = V_67 ,
. V_78 = V_78 ,
} ;
if ( V_67 -> V_135 == V_149 ) {
V_8 . V_39 . V_150 = V_67 -> V_24 . V_25 ;
V_8 . V_39 . V_40 . V_41 = V_67 -> V_24 . V_35 [ 0 ] ;
V_8 . V_39 . V_151 = V_149 ;
V_9 . V_39 . V_150 = V_67 -> V_24 . V_27 ;
V_9 . V_39 . V_40 . V_41 = V_67 -> V_24 . V_38 [ 0 ] ;
V_9 . V_39 . V_151 = V_149 ;
} else {
V_8 . V_36 . V_152 = V_67 -> V_24 . V_25 ;
memcpy ( & V_8 . V_36 . V_37 , V_67 -> V_24 . V_35 , 64 ) ;
V_8 . V_36 . V_153 = V_33 ;
V_9 . V_36 . V_152 = V_67 -> V_24 . V_27 ;
memcpy ( & V_9 . V_36 . V_37 , V_67 -> V_24 . V_38 , 64 ) ;
V_9 . V_36 . V_153 = V_33 ;
}
return F_50 ( F_32 ,
V_123 , & V_8 , & V_9 , & V_121 ) ;
}
static void F_51 ( struct V_51 * V_52 , struct V_132 * V_133 ,
const struct V_66 * V_2 , struct V_57 * V_154 )
{
T_1 V_141 = V_2 -> V_141 ;
struct V_123 * V_123 = F_33 ( V_52 -> V_4 ) ;
struct V_120 V_121 = {
. V_52 = V_52 ,
. V_133 = V_133 ,
. V_2 = V_2 ,
} ;
if ( V_133 -> args [ 0 ] == 0 ) {
if ( ! ( V_141 & V_142 ) )
goto V_155;
if ( F_52 ( F_44 , & V_121 ) )
goto V_156;
V_155:
V_133 -> args [ 0 ] = 1 ;
V_133 -> args [ 1 ] = 0 ;
V_133 -> args [ 4 ] = 0 ;
}
if ( ! ( V_141 & ~ V_142 ) )
goto V_156;
F_53 ( F_43 , V_123 , V_133 -> args [ 2 ] , & V_121 ) ;
V_156:
V_133 -> args [ 1 ] = V_133 -> args [ 4 ] ;
V_133 -> args [ 4 ] = 0 ;
}
static int T_4 F_54 ( void )
{
return F_55 ( & V_157 ) ;
}
static void T_5 F_56 ( void )
{
F_57 ( & V_157 ) ;
}
