static inline bool F_1 ( void )
{
return V_1 . V_2 >
V_3 ;
}
int F_2 ( struct V_4 * V_5 )
{
return F_3 ( V_5 , V_6 , V_7 ,
sizeof( struct V_8 ) ,
& V_9 ) ;
}
static int F_4 ( struct V_4 * V_5 , T_1 V_10 , T_1 type )
{
struct V_11 V_12 ;
int V_13 ;
V_12 . V_10 = V_10 ;
V_12 . type = type ;
V_13 = F_3 ( V_5 , V_14 , V_7 ,
sizeof( V_12 ) , & V_12 ) ;
if ( V_13 )
F_5 ( V_5 , L_1 ) ;
return V_13 ;
}
int F_6 ( struct V_4 * V_5 )
{
struct V_15 * V_16 ;
struct V_17 V_18 = {
. V_19 = V_20 ,
. V_21 = { sizeof( * V_16 ) , } ,
. V_22 = { V_23 , } ,
. V_24 = V_7 ,
} ;
int V_13 ;
V_13 = F_4 ( V_5 , V_25 ,
V_26 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_4 ( V_5 , V_27 ,
V_26 ) ;
if ( V_13 )
return V_13 ;
V_16 = F_7 ( sizeof( * V_16 ) , V_28 ) ;
if ( ! V_16 )
return - V_29 ;
V_18 . V_30 [ 0 ] = V_16 ;
V_16 -> V_31 = 5 ;
V_16 -> V_32 = 1 ;
V_16 -> V_33 = 2 ;
V_16 -> V_34 = 0xc ;
V_16 -> V_24 = V_1 . V_35 ?
V_36 : V_37 ;
V_16 -> V_24 |= V_38 | V_39 ;
V_16 -> V_40 = F_8 ( V_41 |
V_42 |
V_43 |
V_44 |
V_45 |
V_46 |
V_47 |
V_48 ) ;
if ( V_5 -> V_49 -> V_50 )
memcpy ( & V_16 -> V_51 , V_52 ,
sizeof( V_52 ) ) ;
else if ( F_1 () )
memcpy ( & V_16 -> V_51 , V_53 ,
sizeof( V_54 ) ) ;
else
memcpy ( & V_16 -> V_51 , V_54 ,
sizeof( V_54 ) ) ;
V_16 -> V_55 = F_9 ( V_56 ) ;
V_16 -> V_57 =
F_9 ( V_58 [ V_59 ] ) ;
V_16 -> V_60 =
F_9 ( V_61 [ V_59 ] ) ;
memset ( & V_5 -> V_62 , 0 , sizeof( V_5 -> V_62 ) ) ;
V_13 = F_10 ( V_5 , & V_18 ) ;
F_11 ( V_16 ) ;
return V_13 ;
}
static int F_12 ( struct V_4 * V_5 ,
bool V_63 )
{
enum V_64 V_65 ;
struct V_15 * V_16 ;
struct V_66 * V_67 = & V_5 -> V_62 ;
struct V_17 V_18 = {
. V_19 = V_20 ,
. V_30 [ 0 ] = & V_16 ,
. V_21 = { sizeof( * V_16 ) , } ,
. V_22 = { V_23 , } ,
. V_24 = V_7 ,
} ;
int V_13 = 0 ;
F_13 ( & V_5 -> V_68 ) ;
if ( V_63 ) {
V_65 = V_69 ;
} else {
if ( F_14 ( V_67 , 3 , V_70 ) ||
F_14 ( V_67 , 3 , V_71 ) ||
F_14 ( V_67 , 3 , V_72 ) )
V_65 = V_73 ;
else
V_65 = V_59 ;
}
F_15 ( V_5 ,
L_2 ,
V_65 ,
F_14 ( V_67 , 3 , V_70 ) ? L_3 : L_4 ,
F_14 ( V_67 , 3 , V_71 ) ? L_3 : L_4 ,
F_14 ( V_67 , 3 , V_72 ) ? L_3 : L_4 ) ;
if ( V_65 == V_5 -> V_65 )
return 0 ;
V_5 -> V_65 = V_65 ;
V_16 = F_7 ( sizeof( * V_16 ) , V_28 ) ;
if ( ! V_16 )
return - V_29 ;
V_18 . V_30 [ 0 ] = V_16 ;
V_16 -> V_57 = F_9 ( V_58 [ V_65 ] ) ;
V_16 -> V_60 = F_9 ( V_61 [ V_65 ] ) ;
V_16 -> V_40 =
F_8 ( V_45 | V_46 ) ;
F_15 ( V_5 , L_5 , V_65 ) ;
V_13 = F_10 ( V_5 , & V_18 ) ;
F_11 ( V_16 ) ;
return V_13 ;
}
static int F_16 ( struct V_4 * V_5 , T_1 V_74 ,
bool V_75 )
{
struct V_15 * V_16 ;
struct V_17 V_18 = {
. V_19 = V_20 ,
. V_21 = { sizeof( * V_16 ) , } ,
. V_22 = { V_76 , } ,
. V_24 = V_77 ,
} ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
int V_13 ;
if ( V_74 == V_82 )
return 0 ;
V_79 = F_17 ( V_5 -> V_83 [ V_74 ] ,
F_18 ( & V_5 -> V_68 ) ) ;
V_81 = ( void * ) V_79 -> V_84 ;
if ( V_81 -> V_85 == V_75 )
return 0 ;
V_16 = F_7 ( sizeof( * V_16 ) , V_86 ) ;
if ( ! V_16 )
return - V_29 ;
V_18 . V_30 [ 0 ] = V_16 ;
V_16 -> V_40 = F_8 ( V_47 ) ,
V_16 -> V_87 = V_74 ;
if ( V_75 )
V_16 -> V_87 |= V_88 ;
F_15 ( V_5 , L_6 ,
V_75 ? L_7 : L_8 , V_74 ) ;
V_81 -> V_85 = V_75 ;
V_13 = F_10 ( V_5 , & V_18 ) ;
F_11 ( V_16 ) ;
return V_13 ;
}
static void F_19 ( void * V_89 , T_1 * V_90 ,
struct V_91 * V_92 )
{
struct V_93 * V_94 = F_20 ( V_92 ) ;
struct V_95 * V_30 = V_89 ;
struct V_4 * V_5 = V_30 -> V_5 ;
struct V_96 * V_97 ;
enum V_98 V_99 ;
enum V_100 V_101 ;
int V_102 ;
F_13 ( & V_5 -> V_68 ) ;
if ( V_92 -> type != V_103 )
return;
F_21 () ;
V_97 = F_22 ( V_92 -> V_97 ) ;
if ( V_97 && V_97 -> V_104 . V_105 )
V_101 = V_97 -> V_104 . V_105 -> V_101 ;
else
V_101 = - 1 ;
F_23 () ;
V_99 = V_106 ;
if ( ! V_92 -> V_107 . V_108 )
return;
if ( V_101 != V_109 ) {
F_24 ( V_5 , V_92 , V_110 ,
V_99 ) ;
return;
}
if ( V_30 -> V_67 -> V_111 )
V_99 = V_112 ;
if ( V_30 -> V_67 -> V_113 >= V_114 )
V_99 = V_115 ;
F_15 ( V_30 -> V_5 ,
L_9 ,
V_94 -> V_19 , V_30 -> V_67 -> V_111 ,
V_30 -> V_67 -> V_113 , V_99 ) ;
F_24 ( V_5 , V_92 , V_110 , V_99 ) ;
if ( F_1 () )
return;
V_30 -> V_116 ++ ;
if ( ! F_14 ( V_30 -> V_67 , 3 , V_117 ) ) {
if ( F_16 ( V_5 , V_94 -> V_118 , false ) )
F_5 ( V_5 , L_10 ) ;
V_30 -> V_63 = false ;
F_25 ( V_92 ) ;
return;
}
V_102 = F_26 ( V_92 ) ;
if ( ! V_102 )
V_102 = - 100 ;
if ( V_102 > V_119 ) {
if ( F_16 ( V_5 , V_94 -> V_118 , true ) )
F_5 ( V_5 , L_10 ) ;
} else if ( V_102 < V_120 ) {
if ( F_16 ( V_5 , V_94 -> V_118 , false ) )
F_5 ( V_5 , L_10 ) ;
V_30 -> V_63 = false ;
}
F_27 ( V_92 , V_120 ,
V_119 ) ;
}
static void F_28 ( struct V_4 * V_5 )
{
struct V_95 V_30 = {
. V_5 = V_5 ,
. V_67 = & V_5 -> V_62 ,
. V_63 = true ,
} ;
F_29 (
V_5 -> V_121 , V_122 ,
F_19 , & V_30 ) ;
V_30 . V_63 = V_30 . V_63 && V_30 . V_116 ;
if ( F_12 ( V_5 , V_30 . V_63 ) )
F_5 ( V_5 , L_11 ) ;
}
int F_30 ( struct V_4 * V_5 ,
struct V_123 * V_124 ,
struct V_125 * V_126 )
{
struct V_127 * V_128 = F_31 ( V_124 ) ;
struct V_66 * V_67 = ( void * ) V_128 -> V_30 ;
F_15 ( V_5 , L_12 ) ;
F_15 ( V_5 , L_13 , V_67 -> V_111 ? L_3 : L_14 ) ;
F_15 ( V_5 , L_15 , V_67 -> V_129 ) ;
F_15 ( V_5 , L_16 , V_67 -> V_113 ) ;
F_15 ( V_5 , L_17 ,
V_67 -> V_130 ) ;
F_15 ( V_5 , L_18 , V_67 -> V_131 ) ;
memcpy ( & V_5 -> V_62 , V_67 , sizeof( V_5 -> V_62 ) ) ;
F_28 ( V_5 ) ;
return 0 ;
}
static void F_32 ( void * V_89 , T_1 * V_90 ,
struct V_91 * V_92 )
{
struct V_93 * V_94 = ( void * ) V_92 -> V_84 ;
struct V_95 * V_30 = V_89 ;
struct V_4 * V_5 = V_30 -> V_5 ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
if ( V_92 -> type != V_103 ||
V_94 -> V_118 == V_82 )
return;
V_79 = F_17 ( V_5 -> V_83 [ V_94 -> V_118 ] ,
F_18 ( & V_5 -> V_68 ) ) ;
V_81 = ( void * ) V_79 -> V_84 ;
V_30 -> V_116 ++ ;
if ( ! V_81 -> V_85 )
V_30 -> V_63 = false ;
}
void F_33 ( struct V_4 * V_5 , struct V_91 * V_92 ,
enum V_132 V_133 )
{
struct V_93 * V_94 = ( void * ) V_92 -> V_84 ;
struct V_95 V_30 = {
. V_5 = V_5 ,
. V_63 = true ,
} ;
int V_13 ;
F_34 ( & V_5 -> V_68 ) ;
if ( F_35 ( V_94 -> V_118 == V_82 ) )
goto V_134;
if ( ! F_14 ( & V_5 -> V_62 , 3 , V_117 ) )
goto V_134;
F_15 ( V_5 , L_19 , V_92 -> V_107 . V_135 ,
V_133 == V_136 ? L_20 : L_21 ) ;
if ( V_133 == V_137 || F_1 () )
V_13 = F_16 ( V_5 , V_94 -> V_118 ,
false ) ;
else
V_13 = F_16 ( V_5 , V_94 -> V_118 , true ) ;
if ( V_13 )
F_5 ( V_5 , L_22 ) ;
F_29 (
V_5 -> V_121 , V_122 ,
F_32 , & V_30 ) ;
V_30 . V_63 = V_30 . V_63 && V_30 . V_116 ;
if ( F_12 ( V_5 , V_30 . V_63 ) )
F_5 ( V_5 , L_11 ) ;
V_134:
F_36 ( & V_5 -> V_68 ) ;
}
void F_37 ( struct V_4 * V_5 , struct V_91 * V_92 )
{
F_28 ( V_5 ) ;
}
