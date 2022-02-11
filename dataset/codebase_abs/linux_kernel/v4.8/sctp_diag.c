static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
union V_7 V_8 , V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 = & V_6 -> V_14 . V_15 -> V_16 ;
V_8 = F_2 ( V_6 -> V_17 . V_18 . V_19 . V_20 ,
struct V_21 , V_22 ) -> V_23 ;
V_9 = V_6 -> V_14 . V_15 -> V_24 ;
V_11 = V_6 -> V_14 . V_15 -> V_11 ;
V_2 -> V_25 = V_4 -> V_26 ;
V_2 -> V_27 . V_28 = F_3 ( V_6 -> V_17 . V_18 . V_29 ) ;
V_2 -> V_27 . V_30 = F_3 ( V_6 -> V_14 . V_29 ) ;
V_2 -> V_27 . V_31 = V_11 ? V_11 -> V_32 -> V_33 : 0 ;
F_4 ( V_4 , V_2 -> V_27 . V_34 ) ;
#if F_5 ( V_35 )
if ( V_4 -> V_26 == V_36 ) {
* (struct V_37 * ) V_2 -> V_27 . V_38 = V_8 . V_39 . V_40 ;
* (struct V_37 * ) V_2 -> V_27 . V_41 = V_9 . V_39 . V_40 ;
} else
#endif
{
memset ( & V_2 -> V_27 . V_38 , 0 , sizeof( V_2 -> V_27 . V_38 ) ) ;
memset ( & V_2 -> V_27 . V_41 , 0 , sizeof( V_2 -> V_27 . V_41 ) ) ;
V_2 -> V_27 . V_38 [ 0 ] = V_8 . V_42 . V_43 . V_44 ;
V_2 -> V_27 . V_41 [ 0 ] = V_9 . V_42 . V_43 . V_44 ;
}
V_2 -> V_45 = V_6 -> V_46 ;
if ( F_6 ( V_13 ) ) {
V_2 -> V_47 = V_48 ;
V_2 -> V_49 = V_6 -> V_50 ;
V_2 -> V_51 = F_7 ( V_13 -> V_52 - V_53 ) ;
} else {
V_2 -> V_47 = 0 ;
V_2 -> V_49 = 0 ;
V_2 -> V_51 = 0 ;
}
}
static int F_8 ( struct V_54 * V_55 ,
struct V_56 * V_19 )
{
struct V_21 * V_8 ;
int V_57 = sizeof( struct V_58 ) ;
int V_59 = 0 ;
struct V_60 * V_61 ;
void * V_62 = NULL ;
F_9 (laddr, address_list, list)
V_59 ++ ;
V_61 = F_10 ( V_55 , V_63 , V_57 * V_59 ) ;
if ( ! V_61 )
return - V_64 ;
V_62 = F_11 ( V_61 ) ;
F_9 (laddr, address_list, list) {
memcpy ( V_62 , & V_8 -> V_23 , V_57 ) ;
V_62 += V_57 ;
}
return 0 ;
}
static int F_12 ( struct V_54 * V_55 ,
struct V_5 * V_6 )
{
int V_57 = sizeof( struct V_58 ) ;
struct V_65 * V_66 ;
struct V_60 * V_61 ;
void * V_62 = NULL ;
V_61 = F_10 ( V_55 , V_67 ,
V_57 * V_6 -> V_14 . V_68 ) ;
if ( ! V_61 )
return - V_64 ;
V_62 = F_11 ( V_61 ) ;
F_13 (from, &asoc->peer.transport_addr_list,
transports) {
memcpy ( V_62 , & V_66 -> V_24 , V_57 ) ;
V_62 += V_57 ;
}
return 0 ;
}
static int F_14 ( struct V_3 * V_4 , struct V_5 * V_6 ,
struct V_54 * V_55 ,
const struct V_69 * V_70 ,
struct V_71 * V_72 ,
int V_73 , T_1 V_74 , T_2 V_75 ,
const struct V_76 * V_77 )
{
struct V_78 * V_79 = F_15 ( V_4 ) -> V_79 ;
struct V_56 * V_80 ;
struct V_1 * V_2 ;
struct V_76 * V_81 ;
int V_82 = V_70 -> V_83 ;
struct V_84 V_85 ;
void * V_62 = NULL ;
V_81 = F_16 ( V_55 , V_73 , V_74 , V_77 -> V_86 , sizeof( * V_2 ) ,
V_75 ) ;
if ( ! V_81 )
return - V_64 ;
V_2 = F_17 ( V_81 ) ;
F_18 ( ! F_19 ( V_4 ) ) ;
if ( V_6 ) {
F_1 ( V_2 , V_4 , V_6 ) ;
} else {
F_20 ( V_2 , V_4 ) ;
V_2 -> V_45 = V_4 -> V_87 ;
V_2 -> V_47 = 0 ;
V_2 -> V_49 = 0 ;
}
if ( F_21 ( V_4 , V_55 , V_2 , V_82 , V_72 ) )
goto V_88;
if ( V_82 & ( 1 << ( V_89 - 1 ) ) ) {
T_1 V_90 [ V_91 ] ;
int V_92 ;
if ( V_6 && V_6 -> V_79 -> V_93 )
V_92 = V_6 -> V_94 ;
else
V_92 = F_22 ( V_4 ) ;
V_90 [ V_95 ] = V_92 ;
if ( V_6 && V_6 -> V_79 -> V_96 )
V_92 = F_23 ( & V_6 -> V_97 ) ;
else
V_92 = F_24 ( V_4 ) ;
V_90 [ V_98 ] = V_92 ;
V_90 [ V_99 ] = V_4 -> V_100 ;
V_90 [ V_101 ] = V_4 -> V_102 ;
V_90 [ V_103 ] = V_4 -> V_104 ;
V_90 [ V_105 ] = V_4 -> V_106 ;
V_90 [ V_107 ] = F_23 ( & V_4 -> V_108 ) ;
V_90 [ V_109 ] = V_4 -> V_110 . V_111 ;
V_90 [ V_112 ] = F_23 ( & V_4 -> V_113 ) ;
if ( F_25 ( V_55 , V_89 , sizeof( V_90 ) , & V_90 ) < 0 )
goto V_88;
}
if ( V_82 & ( 1 << ( V_114 - 1 ) ) ) {
struct V_60 * V_61 ;
V_61 = F_26 ( V_55 , V_114 ,
sizeof( struct V_115 ) ,
V_116 ) ;
if ( ! V_61 )
goto V_88;
V_62 = F_11 ( V_61 ) ;
}
V_85 . V_117 = (struct V_115 * ) V_62 ;
V_85 . V_6 = V_6 ;
F_27 ( V_4 , V_2 , & V_85 ) ;
V_80 = V_6 ? & V_6 -> V_17 . V_18 . V_19
: & V_79 -> V_17 . V_18 . V_19 ;
if ( F_8 ( V_55 , V_80 ) )
goto V_88;
if ( V_6 && ( V_82 & ( 1 << ( V_118 - 1 ) ) ) )
if ( F_28 ( V_55 , V_118 , L_1 ) < 0 )
goto V_88;
if ( V_6 && F_12 ( V_55 , V_6 ) )
goto V_88;
F_29 ( V_55 , V_81 ) ;
return 0 ;
V_88:
F_30 ( V_55 , V_81 ) ;
return - V_64 ;
}
static T_3 F_31 ( struct V_5 * V_6 )
{
int V_57 = sizeof( struct V_58 ) ;
int V_59 = 0 ;
struct V_21 * V_8 ;
F_9 (laddr, &asoc->base.bind_addr.address_list,
list)
V_59 ++ ;
return F_32 ( sizeof( struct V_115 ) )
+ F_32 ( 1 )
+ F_32 ( 1 )
+ F_32 ( 1 )
+ F_32 ( V_57 * V_6 -> V_14 . V_68 )
+ F_32 ( V_57 * V_59 )
+ F_32 ( sizeof( struct V_119 ) )
+ F_32 ( sizeof( struct V_1 ) )
+ 64 ;
}
static int F_33 ( struct V_65 * V_120 , void * V_121 )
{
struct V_5 * V_122 = V_120 -> V_6 ;
struct V_3 * V_4 = V_120 -> V_6 -> V_17 . V_4 ;
struct V_123 * V_124 = V_121 ;
struct V_54 * V_125 = V_124 -> V_55 ;
const struct V_69 * V_70 = V_124 -> V_2 ;
const struct V_76 * V_81 = V_124 -> V_81 ;
struct V_126 * V_126 = F_34 ( V_125 -> V_4 ) ;
struct V_54 * V_127 ;
int V_128 ;
V_128 = F_35 ( V_4 , V_70 -> V_27 . V_34 ) ;
if ( V_128 )
goto V_129;
V_128 = - V_130 ;
V_127 = F_36 ( F_31 ( V_122 ) , V_131 ) ;
if ( ! V_127 )
goto V_129;
F_37 ( V_4 ) ;
if ( V_4 != V_122 -> V_17 . V_4 ) {
F_38 ( V_4 ) ;
V_4 = V_122 -> V_17 . V_4 ;
F_37 ( V_4 ) ;
}
V_128 = F_14 ( V_4 , V_122 , V_127 , V_70 ,
F_39 ( F_40 ( V_125 ) . V_4 ) ,
F_40 ( V_125 ) . V_73 ,
V_81 -> V_132 , 0 , V_81 ) ;
F_38 ( V_4 ) ;
if ( V_128 < 0 ) {
F_41 ( V_128 == - V_64 ) ;
F_42 ( V_127 ) ;
goto V_129;
}
V_128 = F_43 ( V_126 -> V_133 , V_127 , F_40 ( V_125 ) . V_73 ,
V_134 ) ;
if ( V_128 > 0 )
V_128 = 0 ;
V_129:
return V_128 ;
}
static int F_44 ( struct V_3 * V_4 , void * V_121 )
{
struct V_78 * V_79 = F_15 ( V_4 ) -> V_79 ;
struct V_123 * V_124 = V_121 ;
struct V_54 * V_55 = V_124 -> V_55 ;
struct V_135 * V_136 = V_124 -> V_136 ;
const struct V_69 * V_2 = V_124 -> V_2 ;
struct V_5 * V_122 ;
int V_128 = 0 ;
F_37 ( V_4 ) ;
F_13 (assoc, &ep->asocs, asocs) {
if ( V_136 -> args [ 4 ] < V_136 -> args [ 1 ] )
goto V_20;
if ( V_2 -> V_27 . V_28 != F_3 ( V_122 -> V_17 . V_18 . V_29 ) &&
V_2 -> V_27 . V_28 )
goto V_20;
if ( V_2 -> V_27 . V_30 != F_3 ( V_122 -> V_14 . V_29 ) &&
V_2 -> V_27 . V_30 )
goto V_20;
if ( ! V_136 -> args [ 3 ] &&
F_14 ( V_4 , NULL , V_55 , V_2 ,
F_39 ( F_40 ( V_136 -> V_55 ) . V_4 ) ,
F_40 ( V_136 -> V_55 ) . V_73 ,
V_136 -> V_81 -> V_132 ,
V_137 , V_136 -> V_81 ) < 0 ) {
V_136 -> args [ 3 ] = 1 ;
V_128 = 1 ;
goto V_138;
}
V_136 -> args [ 3 ] = 1 ;
if ( F_14 ( V_4 , V_122 , V_55 , V_2 ,
F_39 ( F_40 ( V_136 -> V_55 ) . V_4 ) ,
F_40 ( V_136 -> V_55 ) . V_73 ,
V_136 -> V_81 -> V_132 , 0 , V_136 -> V_81 ) < 0 ) {
V_128 = 1 ;
goto V_138;
}
V_20:
V_136 -> args [ 4 ] ++ ;
}
V_136 -> args [ 1 ] = 0 ;
V_136 -> args [ 2 ] ++ ;
V_136 -> args [ 3 ] = 0 ;
V_136 -> args [ 4 ] = 0 ;
V_138:
F_38 ( V_4 ) ;
F_45 ( V_4 ) ;
return V_128 ;
}
static int F_46 ( struct V_65 * V_120 , void * V_121 )
{
struct V_78 * V_79 = V_120 -> V_6 -> V_79 ;
struct V_123 * V_124 = V_121 ;
struct V_3 * V_4 = V_79 -> V_17 . V_4 ;
struct V_135 * V_136 = V_124 -> V_136 ;
const struct V_69 * V_2 = V_124 -> V_2 ;
struct V_5 * V_122 =
F_2 ( V_79 -> V_139 . V_20 , struct V_5 , V_139 ) ;
if ( V_120 -> V_6 != V_122 )
goto V_129;
if ( V_2 -> V_140 != V_141 && V_4 -> V_26 != V_2 -> V_140 )
goto V_129;
F_47 ( V_4 ) ;
V_136 -> args [ 5 ] = ( long ) V_4 ;
return 1 ;
V_129:
V_136 -> args [ 2 ] ++ ;
return 0 ;
}
static int F_48 ( struct V_78 * V_79 , void * V_121 )
{
struct V_123 * V_124 = V_121 ;
struct V_3 * V_4 = V_79 -> V_17 . V_4 ;
struct V_54 * V_55 = V_124 -> V_55 ;
struct V_135 * V_136 = V_124 -> V_136 ;
const struct V_69 * V_2 = V_124 -> V_2 ;
struct V_126 * V_126 = F_34 ( V_55 -> V_4 ) ;
struct V_142 * V_143 = F_49 ( V_4 ) ;
int V_128 = 0 ;
if ( ! F_50 ( F_34 ( V_4 ) , V_126 ) )
goto V_129;
if ( V_136 -> args [ 4 ] < V_136 -> args [ 1 ] )
goto V_20;
if ( ! ( V_2 -> V_144 & V_145 ) && ! F_51 ( & V_79 -> V_139 ) )
goto V_20;
if ( V_2 -> V_140 != V_141 &&
V_4 -> V_26 != V_2 -> V_140 )
goto V_20;
if ( V_2 -> V_27 . V_28 != V_143 -> V_146 &&
V_2 -> V_27 . V_28 )
goto V_20;
if ( V_2 -> V_27 . V_30 != V_143 -> V_147 &&
V_2 -> V_27 . V_30 )
goto V_20;
if ( F_14 ( V_4 , NULL , V_55 , V_2 ,
F_39 ( F_40 ( V_136 -> V_55 ) . V_4 ) ,
F_40 ( V_136 -> V_55 ) . V_73 ,
V_136 -> V_81 -> V_132 , V_137 ,
V_136 -> V_81 ) < 0 ) {
V_128 = 2 ;
goto V_129;
}
V_20:
V_136 -> args [ 4 ] ++ ;
V_129:
return V_128 ;
}
static void F_27 ( struct V_3 * V_4 , struct V_1 * V_2 ,
void * V_62 )
{
struct V_84 * V_85 = (struct V_84 * ) V_62 ;
if ( V_85 -> V_6 ) {
V_2 -> V_148 = F_23 ( & V_85 -> V_6 -> V_97 ) ;
V_2 -> V_149 = V_85 -> V_6 -> V_94 ;
} else {
V_2 -> V_148 = V_4 -> V_150 ;
V_2 -> V_149 = V_4 -> V_151 ;
}
if ( V_85 -> V_117 )
F_52 ( V_4 , V_85 -> V_6 , V_85 -> V_117 ) ;
}
static int F_53 ( struct V_54 * V_125 ,
const struct V_76 * V_81 ,
const struct V_69 * V_70 )
{
struct V_126 * V_126 = F_34 ( V_125 -> V_4 ) ;
union V_7 V_8 , V_9 ;
struct V_123 V_124 = {
. V_55 = V_125 ,
. V_2 = V_70 ,
. V_81 = V_81 ,
} ;
if ( V_70 -> V_140 == V_152 ) {
V_8 . V_42 . V_153 = V_70 -> V_27 . V_28 ;
V_8 . V_42 . V_43 . V_44 = V_70 -> V_27 . V_38 [ 0 ] ;
V_8 . V_42 . V_154 = V_152 ;
V_9 . V_42 . V_153 = V_70 -> V_27 . V_30 ;
V_9 . V_42 . V_43 . V_44 = V_70 -> V_27 . V_41 [ 0 ] ;
V_9 . V_42 . V_154 = V_152 ;
} else {
V_8 . V_39 . V_155 = V_70 -> V_27 . V_28 ;
memcpy ( & V_8 . V_39 . V_40 , V_70 -> V_27 . V_38 ,
sizeof( V_8 . V_39 . V_40 ) ) ;
V_8 . V_39 . V_156 = V_36 ;
V_9 . V_39 . V_155 = V_70 -> V_27 . V_30 ;
memcpy ( & V_9 . V_39 . V_40 , V_70 -> V_27 . V_41 ,
sizeof( V_9 . V_39 . V_40 ) ) ;
V_9 . V_39 . V_156 = V_36 ;
}
return F_54 ( F_33 ,
V_126 , & V_8 , & V_9 , & V_124 ) ;
}
static void F_55 ( struct V_54 * V_55 , struct V_135 * V_136 ,
const struct V_69 * V_2 , struct V_60 * V_157 )
{
T_1 V_144 = V_2 -> V_144 ;
struct V_126 * V_126 = F_34 ( V_55 -> V_4 ) ;
struct V_123 V_124 = {
. V_55 = V_55 ,
. V_136 = V_136 ,
. V_2 = V_2 ,
} ;
if ( V_136 -> args [ 0 ] == 0 ) {
if ( ! ( V_144 & V_145 ) )
goto V_158;
if ( F_56 ( F_48 , & V_124 ) )
goto V_159;
V_158:
V_136 -> args [ 0 ] = 1 ;
V_136 -> args [ 1 ] = 0 ;
V_136 -> args [ 4 ] = 0 ;
}
if ( ! ( V_144 & ~ ( V_145 | V_160 ) ) )
goto V_159;
V_20:
V_136 -> args [ 5 ] = 0 ;
F_57 ( F_46 , V_126 , V_136 -> args [ 2 ] , & V_124 ) ;
if ( V_136 -> args [ 5 ] && ! F_44 ( (struct V_3 * ) V_136 -> args [ 5 ] , & V_124 ) )
goto V_20;
V_159:
V_136 -> args [ 1 ] = V_136 -> args [ 4 ] ;
V_136 -> args [ 4 ] = 0 ;
}
static int T_4 F_58 ( void )
{
return F_59 ( & V_161 ) ;
}
static void T_5 F_60 ( void )
{
F_61 ( & V_161 ) ;
}
