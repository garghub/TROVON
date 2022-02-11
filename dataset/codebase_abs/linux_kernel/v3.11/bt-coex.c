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
struct V_15 V_16 = {
. V_17 = 5 ,
. V_18 = 1 ,
. V_19 = 2 ,
. V_20 = 0xc ,
} ;
int V_13 ;
V_16 . V_21 = V_1 . V_22 ?
V_23 : V_24 ;
V_16 . V_21 |= V_25 | V_26 ;
V_16 . V_27 = F_7 ( V_28 |
V_29 |
V_30 |
V_31 |
V_32 |
V_33 |
V_34 |
V_35 ) ;
if ( V_5 -> V_36 -> V_37 )
memcpy ( & V_16 . V_38 , V_39 ,
sizeof( V_39 ) ) ;
else if ( F_1 () )
memcpy ( & V_16 . V_38 , V_40 ,
sizeof( V_41 ) ) ;
else
memcpy ( & V_16 . V_38 , V_41 ,
sizeof( V_41 ) ) ;
V_16 . V_42 = F_8 ( V_43 ) ;
V_16 . V_44 =
F_8 ( V_45 [ V_46 ] ) ;
V_16 . V_47 =
F_8 ( V_48 [ V_46 ] ) ;
memset ( & V_5 -> V_49 , 0 , sizeof( V_5 -> V_49 ) ) ;
V_13 = F_4 ( V_5 , V_50 ,
V_51 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_4 ( V_5 , V_52 ,
V_51 ) ;
if ( V_13 )
return V_13 ;
return F_3 ( V_5 , V_53 , V_7 ,
sizeof( V_16 ) , & V_16 ) ;
}
static int F_9 ( struct V_4 * V_5 ,
bool V_54 )
{
enum V_55 V_56 ;
struct V_15 V_16 = {} ;
struct V_57 * V_58 = & V_5 -> V_49 ;
F_10 ( & V_5 -> V_59 ) ;
if ( V_54 ) {
V_56 = V_60 ;
} else {
if ( F_11 ( V_58 , 3 , V_61 ) ||
F_11 ( V_58 , 3 , V_62 ) ||
F_11 ( V_58 , 3 , V_63 ) )
V_56 = V_64 ;
else
V_56 = V_46 ;
}
F_12 ( V_5 ,
L_2 ,
V_56 ,
F_11 ( V_58 , 3 , V_61 ) ? L_3 : L_4 ,
F_11 ( V_58 , 3 , V_62 ) ? L_3 : L_4 ,
F_11 ( V_58 , 3 , V_63 ) ? L_3 : L_4 ) ;
if ( V_56 == V_5 -> V_56 )
return 0 ;
V_5 -> V_56 = V_56 ;
V_16 . V_44 = F_8 ( V_45 [ V_56 ] ) ;
V_16 . V_47 = F_8 ( V_48 [ V_56 ] ) ;
V_16 . V_27 = F_7 ( V_32 | V_33 ) ;
F_12 ( V_5 , L_5 , V_56 ) ;
return F_3 ( V_5 , V_53 , V_7 ,
sizeof( V_16 ) , & V_16 ) ;
}
static int F_13 ( struct V_4 * V_5 , T_1 V_65 ,
bool V_66 )
{
struct V_15 V_16 = {
. V_27 = F_7 ( V_34 ) ,
. V_67 = V_65 ,
} ;
struct V_68 * V_69 ;
struct V_70 * V_71 ;
if ( V_65 == V_72 )
return 0 ;
V_69 = F_14 ( V_5 -> V_73 [ V_65 ] ,
F_15 ( & V_5 -> V_59 ) ) ;
V_71 = ( void * ) V_69 -> V_74 ;
if ( V_71 -> V_75 == V_66 )
return 0 ;
if ( V_66 )
V_16 . V_67 |= V_76 ;
F_12 ( V_5 , L_6 ,
V_66 ? L_7 : L_8 , V_65 ) ;
V_71 -> V_75 = V_66 ;
return F_3 ( V_5 , V_53 , V_77 ,
sizeof( V_16 ) , & V_16 ) ;
}
static void F_16 ( void * V_78 , T_1 * V_79 ,
struct V_80 * V_81 )
{
struct V_82 * V_83 = F_17 ( V_81 ) ;
struct V_84 * V_85 = V_78 ;
struct V_4 * V_5 = V_85 -> V_5 ;
struct V_86 * V_87 ;
enum V_88 V_89 ;
enum V_90 V_91 ;
int V_92 ;
F_10 ( & V_5 -> V_59 ) ;
if ( V_81 -> type != V_93 )
return;
F_18 () ;
V_87 = F_19 ( V_81 -> V_87 ) ;
if ( V_87 && V_87 -> V_94 . V_95 )
V_91 = V_87 -> V_94 . V_95 -> V_91 ;
else
V_91 = - 1 ;
F_20 () ;
V_89 = V_96 ;
if ( V_91 != V_97 ) {
F_21 ( V_5 , V_81 , V_98 ,
V_89 ) ;
return;
}
if ( V_85 -> V_58 -> V_99 )
V_89 = V_100 ;
if ( V_85 -> V_58 -> V_101 >= V_102 )
V_89 = V_103 ;
F_12 ( V_85 -> V_5 ,
L_9 ,
V_83 -> V_104 , V_85 -> V_58 -> V_99 ,
V_85 -> V_58 -> V_101 , V_89 ) ;
F_21 ( V_5 , V_81 , V_98 , V_89 ) ;
if ( F_1 () )
return;
V_85 -> V_105 ++ ;
if ( ! F_11 ( V_85 -> V_58 , 3 , V_106 ) ) {
if ( F_13 ( V_5 , V_83 -> V_107 , false ) )
F_5 ( V_5 , L_10 ) ;
V_85 -> V_54 = false ;
F_22 ( V_81 ) ;
return;
}
V_92 = F_23 ( V_81 ) ;
if ( ! V_92 )
V_92 = - 100 ;
if ( V_92 > V_108 ) {
if ( F_13 ( V_5 , V_83 -> V_107 , true ) )
F_5 ( V_5 , L_10 ) ;
} else if ( V_92 < V_109 ) {
if ( F_13 ( V_5 , V_83 -> V_107 , false ) )
F_5 ( V_5 , L_10 ) ;
V_85 -> V_54 = false ;
}
F_24 ( V_81 , V_109 ,
V_108 ) ;
}
static void F_25 ( struct V_4 * V_5 )
{
struct V_84 V_85 = {
. V_5 = V_5 ,
. V_58 = & V_5 -> V_49 ,
. V_54 = true ,
} ;
F_26 (
V_5 -> V_110 , V_111 ,
F_16 , & V_85 ) ;
V_85 . V_54 = V_85 . V_54 && V_85 . V_105 ;
if ( F_9 ( V_5 , V_85 . V_54 ) )
F_5 ( V_5 , L_11 ) ;
}
int F_27 ( struct V_4 * V_5 ,
struct V_112 * V_113 ,
struct V_114 * V_115 )
{
struct V_116 * V_117 = F_28 ( V_113 ) ;
struct V_57 * V_58 = ( void * ) V_117 -> V_85 ;
F_12 ( V_5 , L_12 ) ;
F_12 ( V_5 , L_13 , V_58 -> V_99 ? L_3 : L_14 ) ;
F_12 ( V_5 , L_15 , V_58 -> V_118 ) ;
F_12 ( V_5 , L_16 , V_58 -> V_101 ) ;
F_12 ( V_5 , L_17 ,
V_58 -> V_119 ) ;
F_12 ( V_5 , L_18 , V_58 -> V_120 ) ;
memcpy ( & V_5 -> V_49 , V_58 , sizeof( V_5 -> V_49 ) ) ;
F_25 ( V_5 ) ;
return 0 ;
}
static void F_29 ( void * V_78 , T_1 * V_79 ,
struct V_80 * V_81 )
{
struct V_82 * V_83 = ( void * ) V_81 -> V_74 ;
struct V_84 * V_85 = V_78 ;
struct V_4 * V_5 = V_85 -> V_5 ;
struct V_68 * V_69 ;
struct V_70 * V_71 ;
if ( V_81 -> type != V_93 ||
V_83 -> V_107 == V_72 )
return;
V_69 = F_14 ( V_5 -> V_73 [ V_83 -> V_107 ] ,
F_15 ( & V_5 -> V_59 ) ) ;
V_71 = ( void * ) V_69 -> V_74 ;
if ( ! V_71 -> V_75 )
V_85 -> V_54 = false ;
}
void F_30 ( struct V_4 * V_5 , struct V_80 * V_81 ,
enum V_121 V_122 )
{
struct V_82 * V_83 = ( void * ) V_81 -> V_74 ;
struct V_84 V_85 = {
. V_5 = V_5 ,
. V_54 = true ,
} ;
int V_13 ;
F_31 ( & V_5 -> V_59 ) ;
if ( F_32 ( V_83 -> V_107 == V_72 ) )
goto V_123;
if ( ! F_11 ( & V_5 -> V_49 , 3 , V_106 ) )
goto V_123;
F_12 ( V_5 , L_19 , V_81 -> V_124 . V_125 ,
V_122 == V_126 ? L_20 : L_21 ) ;
if ( V_122 == V_127 || F_1 () )
V_13 = F_13 ( V_5 , V_83 -> V_107 ,
false ) ;
else
V_13 = F_13 ( V_5 , V_83 -> V_107 , true ) ;
if ( V_13 )
F_5 ( V_5 , L_22 ) ;
F_26 (
V_5 -> V_110 , V_111 ,
F_29 , & V_85 ) ;
V_85 . V_54 = V_85 . V_54 && V_85 . V_105 ;
if ( F_9 ( V_5 , V_85 . V_54 ) )
F_5 ( V_5 , L_11 ) ;
V_123:
F_33 ( & V_5 -> V_59 ) ;
}
void F_34 ( struct V_4 * V_5 , struct V_80 * V_81 )
{
struct V_86 * V_87 ;
enum V_90 V_91 ;
F_18 () ;
V_87 = F_19 ( V_81 -> V_87 ) ;
if ( V_87 && V_87 -> V_94 . V_95 )
V_91 = V_87 -> V_94 . V_95 -> V_91 ;
else
V_91 = - 1 ;
F_20 () ;
if ( V_91 == V_97 )
return;
memset ( & V_5 -> V_49 , 0 , sizeof( V_5 -> V_49 ) ) ;
F_25 ( V_5 ) ;
}
