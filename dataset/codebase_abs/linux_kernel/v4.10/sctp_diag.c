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
const struct V_76 * V_77 ,
bool V_78 )
{
struct V_79 * V_80 = F_15 ( V_4 ) -> V_80 ;
struct V_56 * V_81 ;
struct V_1 * V_2 ;
struct V_76 * V_82 ;
int V_83 = V_70 -> V_84 ;
struct V_85 V_86 ;
void * V_62 = NULL ;
V_82 = F_16 ( V_55 , V_73 , V_74 , V_77 -> V_87 , sizeof( * V_2 ) ,
V_75 ) ;
if ( ! V_82 )
return - V_64 ;
V_2 = F_17 ( V_82 ) ;
F_18 ( ! F_19 ( V_4 ) ) ;
if ( V_6 ) {
F_1 ( V_2 , V_4 , V_6 ) ;
} else {
F_20 ( V_2 , V_4 ) ;
V_2 -> V_45 = V_4 -> V_88 ;
V_2 -> V_47 = 0 ;
V_2 -> V_49 = 0 ;
}
if ( F_21 ( V_4 , V_55 , V_2 , V_83 , V_72 , V_78 ) )
goto V_89;
if ( V_83 & ( 1 << ( V_90 - 1 ) ) ) {
T_1 V_91 [ V_92 ] ;
int V_93 ;
if ( V_6 && V_6 -> V_80 -> V_94 )
V_93 = V_6 -> V_95 ;
else
V_93 = F_22 ( V_4 ) ;
V_91 [ V_96 ] = V_93 ;
if ( V_6 && V_6 -> V_80 -> V_97 )
V_93 = F_23 ( & V_6 -> V_98 ) ;
else
V_93 = F_24 ( V_4 ) ;
V_91 [ V_99 ] = V_93 ;
V_91 [ V_100 ] = V_4 -> V_101 ;
V_91 [ V_102 ] = V_4 -> V_103 ;
V_91 [ V_104 ] = V_4 -> V_105 ;
V_91 [ V_106 ] = V_4 -> V_107 ;
V_91 [ V_108 ] = F_23 ( & V_4 -> V_109 ) ;
V_91 [ V_110 ] = V_4 -> V_111 . V_112 ;
V_91 [ V_113 ] = F_23 ( & V_4 -> V_114 ) ;
if ( F_25 ( V_55 , V_90 , sizeof( V_91 ) , & V_91 ) < 0 )
goto V_89;
}
if ( V_83 & ( 1 << ( V_115 - 1 ) ) ) {
struct V_60 * V_61 ;
V_61 = F_26 ( V_55 , V_115 ,
sizeof( struct V_116 ) ,
V_117 ) ;
if ( ! V_61 )
goto V_89;
V_62 = F_11 ( V_61 ) ;
}
V_86 . V_118 = (struct V_116 * ) V_62 ;
V_86 . V_6 = V_6 ;
F_27 ( V_4 , V_2 , & V_86 ) ;
V_81 = V_6 ? & V_6 -> V_17 . V_18 . V_19
: & V_80 -> V_17 . V_18 . V_19 ;
if ( F_8 ( V_55 , V_81 ) )
goto V_89;
if ( V_6 && ( V_83 & ( 1 << ( V_119 - 1 ) ) ) )
if ( F_28 ( V_55 , V_119 , L_1 ) < 0 )
goto V_89;
if ( V_6 && F_12 ( V_55 , V_6 ) )
goto V_89;
F_29 ( V_55 , V_82 ) ;
return 0 ;
V_89:
F_30 ( V_55 , V_82 ) ;
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
return F_32 ( sizeof( struct V_116 ) )
+ F_32 ( 1 )
+ F_32 ( 1 )
+ F_32 ( 1 )
+ F_32 ( 4 )
+ F_32 ( V_57 * V_6 -> V_14 . V_68 )
+ F_32 ( V_57 * V_59 )
+ F_32 ( sizeof( struct V_120 ) )
+ F_32 ( sizeof( struct V_1 ) )
+ 64 ;
}
static int F_33 ( struct V_65 * V_121 , void * V_122 )
{
struct V_5 * V_123 = V_121 -> V_6 ;
struct V_3 * V_4 = V_121 -> V_6 -> V_17 . V_4 ;
struct V_124 * V_125 = V_122 ;
struct V_54 * V_126 = V_125 -> V_55 ;
const struct V_69 * V_70 = V_125 -> V_2 ;
const struct V_76 * V_82 = V_125 -> V_82 ;
struct V_127 * V_127 = F_34 ( V_126 -> V_4 ) ;
struct V_54 * V_128 ;
int V_129 ;
V_129 = F_35 ( V_4 , V_70 -> V_27 . V_34 ) ;
if ( V_129 )
goto V_130;
V_129 = - V_131 ;
V_128 = F_36 ( F_31 ( V_123 ) , V_132 ) ;
if ( ! V_128 )
goto V_130;
F_37 ( V_4 ) ;
if ( V_4 != V_123 -> V_17 . V_4 ) {
F_38 ( V_4 ) ;
V_4 = V_123 -> V_17 . V_4 ;
F_37 ( V_4 ) ;
}
V_129 = F_14 ( V_4 , V_123 , V_128 , V_70 ,
F_39 ( F_40 ( V_126 ) . V_4 ) ,
F_40 ( V_126 ) . V_73 ,
V_82 -> V_133 , 0 , V_82 ,
V_125 -> V_78 ) ;
F_38 ( V_4 ) ;
if ( V_129 < 0 ) {
F_41 ( V_129 == - V_64 ) ;
F_42 ( V_128 ) ;
goto V_130;
}
V_129 = F_43 ( V_127 -> V_134 , V_128 , F_40 ( V_126 ) . V_73 ,
V_135 ) ;
if ( V_129 > 0 )
V_129 = 0 ;
V_130:
return V_129 ;
}
static int F_44 ( struct V_3 * V_4 , void * V_122 )
{
struct V_79 * V_80 = F_15 ( V_4 ) -> V_80 ;
struct V_124 * V_125 = V_122 ;
struct V_54 * V_55 = V_125 -> V_55 ;
struct V_136 * V_137 = V_125 -> V_137 ;
const struct V_69 * V_2 = V_125 -> V_2 ;
struct V_5 * V_123 ;
int V_129 = 0 ;
F_37 ( V_4 ) ;
F_13 (assoc, &ep->asocs, asocs) {
if ( V_137 -> args [ 4 ] < V_137 -> args [ 1 ] )
goto V_20;
if ( V_2 -> V_27 . V_28 != F_3 ( V_123 -> V_17 . V_18 . V_29 ) &&
V_2 -> V_27 . V_28 )
goto V_20;
if ( V_2 -> V_27 . V_30 != F_3 ( V_123 -> V_14 . V_29 ) &&
V_2 -> V_27 . V_30 )
goto V_20;
if ( ! V_137 -> args [ 3 ] &&
F_14 ( V_4 , NULL , V_55 , V_2 ,
F_39 ( F_40 ( V_137 -> V_55 ) . V_4 ) ,
F_40 ( V_137 -> V_55 ) . V_73 ,
V_137 -> V_82 -> V_133 ,
V_138 , V_137 -> V_82 ,
V_125 -> V_78 ) < 0 ) {
V_137 -> args [ 3 ] = 1 ;
V_129 = 1 ;
goto V_139;
}
V_137 -> args [ 3 ] = 1 ;
if ( F_14 ( V_4 , V_123 , V_55 , V_2 ,
F_39 ( F_40 ( V_137 -> V_55 ) . V_4 ) ,
F_40 ( V_137 -> V_55 ) . V_73 ,
V_137 -> V_82 -> V_133 , 0 , V_137 -> V_82 ,
V_125 -> V_78 ) < 0 ) {
V_129 = 1 ;
goto V_139;
}
V_20:
V_137 -> args [ 4 ] ++ ;
}
V_137 -> args [ 1 ] = 0 ;
V_137 -> args [ 2 ] ++ ;
V_137 -> args [ 3 ] = 0 ;
V_137 -> args [ 4 ] = 0 ;
V_139:
F_38 ( V_4 ) ;
F_45 ( V_4 ) ;
return V_129 ;
}
static int F_46 ( struct V_65 * V_121 , void * V_122 )
{
struct V_79 * V_80 = V_121 -> V_6 -> V_80 ;
struct V_124 * V_125 = V_122 ;
struct V_3 * V_4 = V_80 -> V_17 . V_4 ;
struct V_136 * V_137 = V_125 -> V_137 ;
const struct V_69 * V_2 = V_125 -> V_2 ;
struct V_5 * V_123 =
F_2 ( V_80 -> V_140 . V_20 , struct V_5 , V_140 ) ;
if ( V_121 -> V_6 != V_123 )
goto V_130;
if ( V_2 -> V_141 != V_142 && V_4 -> V_26 != V_2 -> V_141 )
goto V_130;
F_47 ( V_4 ) ;
V_137 -> args [ 5 ] = ( long ) V_4 ;
return 1 ;
V_130:
V_137 -> args [ 2 ] ++ ;
return 0 ;
}
static int F_48 ( struct V_79 * V_80 , void * V_122 )
{
struct V_124 * V_125 = V_122 ;
struct V_3 * V_4 = V_80 -> V_17 . V_4 ;
struct V_54 * V_55 = V_125 -> V_55 ;
struct V_136 * V_137 = V_125 -> V_137 ;
const struct V_69 * V_2 = V_125 -> V_2 ;
struct V_127 * V_127 = F_34 ( V_55 -> V_4 ) ;
struct V_143 * V_144 = F_49 ( V_4 ) ;
int V_129 = 0 ;
if ( ! F_50 ( F_34 ( V_4 ) , V_127 ) )
goto V_130;
if ( V_137 -> args [ 4 ] < V_137 -> args [ 1 ] )
goto V_20;
if ( ! ( V_2 -> V_145 & V_146 ) && ! F_51 ( & V_80 -> V_140 ) )
goto V_20;
if ( V_2 -> V_141 != V_142 &&
V_4 -> V_26 != V_2 -> V_141 )
goto V_20;
if ( V_2 -> V_27 . V_28 != V_144 -> V_147 &&
V_2 -> V_27 . V_28 )
goto V_20;
if ( V_2 -> V_27 . V_30 != V_144 -> V_148 &&
V_2 -> V_27 . V_30 )
goto V_20;
if ( F_14 ( V_4 , NULL , V_55 , V_2 ,
F_39 ( F_40 ( V_137 -> V_55 ) . V_4 ) ,
F_40 ( V_137 -> V_55 ) . V_73 ,
V_137 -> V_82 -> V_133 , V_138 ,
V_137 -> V_82 , V_125 -> V_78 ) < 0 ) {
V_129 = 2 ;
goto V_130;
}
V_20:
V_137 -> args [ 4 ] ++ ;
V_130:
return V_129 ;
}
static void F_27 ( struct V_3 * V_4 , struct V_1 * V_2 ,
void * V_62 )
{
struct V_85 * V_86 = (struct V_85 * ) V_62 ;
if ( V_86 -> V_6 ) {
V_2 -> V_149 = F_23 ( & V_86 -> V_6 -> V_98 ) ;
V_2 -> V_150 = V_86 -> V_6 -> V_95 ;
} else {
V_2 -> V_149 = V_4 -> V_151 ;
V_2 -> V_150 = V_4 -> V_152 ;
}
if ( V_86 -> V_118 )
F_52 ( V_4 , V_86 -> V_6 , V_86 -> V_118 ) ;
}
static int F_53 ( struct V_54 * V_126 ,
const struct V_76 * V_82 ,
const struct V_69 * V_70 )
{
struct V_127 * V_127 = F_34 ( V_126 -> V_4 ) ;
union V_7 V_8 , V_9 ;
struct V_124 V_125 = {
. V_55 = V_126 ,
. V_2 = V_70 ,
. V_82 = V_82 ,
. V_78 = F_54 ( V_126 , V_153 ) ,
} ;
if ( V_70 -> V_141 == V_154 ) {
V_8 . V_42 . V_155 = V_70 -> V_27 . V_28 ;
V_8 . V_42 . V_43 . V_44 = V_70 -> V_27 . V_38 [ 0 ] ;
V_8 . V_42 . V_156 = V_154 ;
V_9 . V_42 . V_155 = V_70 -> V_27 . V_30 ;
V_9 . V_42 . V_43 . V_44 = V_70 -> V_27 . V_41 [ 0 ] ;
V_9 . V_42 . V_156 = V_154 ;
} else {
V_8 . V_39 . V_157 = V_70 -> V_27 . V_28 ;
memcpy ( & V_8 . V_39 . V_40 , V_70 -> V_27 . V_38 ,
sizeof( V_8 . V_39 . V_40 ) ) ;
V_8 . V_39 . V_158 = V_36 ;
V_9 . V_39 . V_157 = V_70 -> V_27 . V_30 ;
memcpy ( & V_9 . V_39 . V_40 , V_70 -> V_27 . V_41 ,
sizeof( V_9 . V_39 . V_40 ) ) ;
V_9 . V_39 . V_158 = V_36 ;
}
return F_55 ( F_33 ,
V_127 , & V_8 , & V_9 , & V_125 ) ;
}
static void F_56 ( struct V_54 * V_55 , struct V_136 * V_137 ,
const struct V_69 * V_2 , struct V_60 * V_159 )
{
T_1 V_145 = V_2 -> V_145 ;
struct V_127 * V_127 = F_34 ( V_55 -> V_4 ) ;
struct V_124 V_125 = {
. V_55 = V_55 ,
. V_137 = V_137 ,
. V_2 = V_2 ,
. V_78 = F_54 ( V_137 -> V_55 , V_153 ) ,
} ;
if ( V_137 -> args [ 0 ] == 0 ) {
if ( ! ( V_145 & V_146 ) )
goto V_160;
if ( F_57 ( F_48 , & V_125 ) )
goto V_161;
V_160:
V_137 -> args [ 0 ] = 1 ;
V_137 -> args [ 1 ] = 0 ;
V_137 -> args [ 4 ] = 0 ;
}
if ( ! ( V_145 & ~ ( V_146 | V_162 ) ) )
goto V_161;
V_20:
V_137 -> args [ 5 ] = 0 ;
F_58 ( F_46 , V_127 , V_137 -> args [ 2 ] , & V_125 ) ;
if ( V_137 -> args [ 5 ] && ! F_44 ( (struct V_3 * ) V_137 -> args [ 5 ] , & V_125 ) )
goto V_20;
V_161:
V_137 -> args [ 1 ] = V_137 -> args [ 4 ] ;
V_137 -> args [ 4 ] = 0 ;
}
static int T_4 F_59 ( void )
{
return F_60 ( & V_163 ) ;
}
static void T_5 F_61 ( void )
{
F_62 ( & V_163 ) ;
}
