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
if ( F_1 () )
memcpy ( & V_16 . V_36 , V_37 ,
sizeof( V_38 ) ) ;
else
memcpy ( & V_16 . V_36 , V_38 ,
sizeof( V_38 ) ) ;
V_16 . V_39 = F_8 ( V_40 ) ;
V_16 . V_41 =
F_8 ( V_42 [ V_43 ] ) ;
V_16 . V_44 =
F_8 ( V_45 [ V_43 ] ) ;
memset ( & V_5 -> V_46 , 0 , sizeof( V_5 -> V_46 ) ) ;
V_13 = F_4 ( V_5 , V_47 ,
V_48 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_4 ( V_5 , V_49 ,
V_48 ) ;
if ( V_13 )
return V_13 ;
return F_3 ( V_5 , V_50 , V_7 ,
sizeof( V_16 ) , & V_16 ) ;
}
static int F_9 ( struct V_4 * V_5 ,
bool V_51 )
{
enum V_52 V_53 ;
struct V_15 V_16 = {} ;
struct V_54 * V_55 = & V_5 -> V_46 ;
F_10 ( & V_5 -> V_56 ) ;
if ( V_51 ) {
V_53 = V_57 ;
} else {
if ( F_11 ( V_55 , 3 , V_58 ) ||
F_11 ( V_55 , 3 , V_59 ) ||
F_11 ( V_55 , 3 , V_60 ) )
V_53 = V_61 ;
else
V_53 = V_43 ;
}
F_12 ( V_5 ,
L_2 ,
V_53 ,
F_11 ( V_55 , 3 , V_58 ) ? L_3 : L_4 ,
F_11 ( V_55 , 3 , V_59 ) ? L_3 : L_4 ,
F_11 ( V_55 , 3 , V_60 ) ? L_3 : L_4 ) ;
if ( V_53 == V_5 -> V_53 )
return 0 ;
V_5 -> V_53 = V_53 ;
V_16 . V_41 = F_8 ( V_42 [ V_53 ] ) ;
V_16 . V_44 = F_8 ( V_45 [ V_53 ] ) ;
V_16 . V_27 = F_7 ( V_32 | V_33 ) ;
F_12 ( V_5 , L_5 , V_53 ) ;
return F_3 ( V_5 , V_50 , V_7 ,
sizeof( V_16 ) , & V_16 ) ;
}
static int F_13 ( struct V_4 * V_5 , T_1 V_62 ,
bool V_63 )
{
struct V_15 V_16 = {
. V_27 = F_7 ( V_34 ) ,
. V_64 = V_62 ,
} ;
struct V_65 * V_66 ;
struct V_67 * V_68 ;
if ( V_62 == V_69 )
return 0 ;
V_66 = F_14 ( V_5 -> V_70 [ V_62 ] ,
F_15 ( & V_5 -> V_56 ) ) ;
V_68 = ( void * ) V_66 -> V_71 ;
if ( V_68 -> V_72 == V_63 )
return 0 ;
if ( V_63 )
V_16 . V_64 |= V_73 ;
F_12 ( V_5 , L_6 ,
V_63 ? L_7 : L_8 , V_62 ) ;
V_68 -> V_72 = V_63 ;
return F_3 ( V_5 , V_50 , V_74 ,
sizeof( V_16 ) , & V_16 ) ;
}
static void F_16 ( void * V_75 , T_1 * V_76 ,
struct V_77 * V_78 )
{
struct V_79 * V_80 = F_17 ( V_78 ) ;
struct V_81 * V_82 = V_75 ;
struct V_4 * V_5 = V_82 -> V_5 ;
struct V_83 * V_84 ;
enum V_85 V_86 ;
enum V_87 V_88 ;
int V_89 ;
if ( V_78 -> type != V_90 )
return;
F_18 () ;
V_84 = F_19 ( V_78 -> V_84 ) ;
if ( V_84 && V_84 -> V_91 . V_92 )
V_88 = V_84 -> V_91 . V_92 -> V_88 ;
else
V_88 = - 1 ;
F_20 () ;
V_86 = V_93 ;
if ( V_88 != V_94 ) {
F_21 ( V_78 , V_86 ) ;
return;
}
if ( V_82 -> V_55 -> V_95 )
V_86 = V_96 ;
if ( V_82 -> V_55 -> V_97 >= V_98 )
V_86 = V_99 ;
F_12 ( V_82 -> V_5 ,
L_9 ,
V_80 -> V_100 , V_82 -> V_55 -> V_95 ,
V_82 -> V_55 -> V_97 , V_86 ) ;
F_21 ( V_78 , V_86 ) ;
if ( F_1 () )
return;
V_82 -> V_101 ++ ;
if ( ! F_11 ( V_82 -> V_55 , 3 , V_102 ) ) {
if ( F_13 ( V_5 , V_80 -> V_103 , false ) )
F_5 ( V_5 , L_10 ) ;
V_82 -> V_51 = false ;
F_22 ( V_78 ) ;
return;
}
V_89 = F_23 ( V_78 ) ;
if ( ! V_89 )
V_89 = - 100 ;
if ( V_89 > V_104 ) {
if ( F_13 ( V_5 , V_80 -> V_103 , true ) )
F_5 ( V_5 , L_10 ) ;
} else if ( V_89 < V_105 ) {
if ( F_13 ( V_5 , V_80 -> V_103 , false ) )
F_5 ( V_5 , L_10 ) ;
V_82 -> V_51 = false ;
}
F_24 ( V_78 , V_105 ,
V_104 ) ;
}
static void F_25 ( struct V_4 * V_5 )
{
struct V_81 V_82 = {
. V_5 = V_5 ,
. V_55 = & V_5 -> V_46 ,
. V_51 = true ,
} ;
F_26 (
V_5 -> V_106 , V_107 ,
F_16 , & V_82 ) ;
V_82 . V_51 = V_82 . V_51 && V_82 . V_101 ;
if ( F_9 ( V_5 , V_82 . V_51 ) )
F_5 ( V_5 , L_11 ) ;
}
int F_27 ( struct V_4 * V_5 ,
struct V_108 * V_109 ,
struct V_110 * V_111 )
{
struct V_112 * V_113 = F_28 ( V_109 ) ;
struct V_54 * V_55 = ( void * ) V_113 -> V_82 ;
F_12 ( V_5 , L_12 ) ;
F_12 ( V_5 , L_13 , V_55 -> V_95 ? L_3 : L_14 ) ;
F_12 ( V_5 , L_15 , V_55 -> V_114 ) ;
F_12 ( V_5 , L_16 , V_55 -> V_97 ) ;
F_12 ( V_5 , L_17 ,
V_55 -> V_115 ) ;
F_12 ( V_5 , L_18 , V_55 -> V_116 ) ;
memcpy ( & V_5 -> V_46 , V_55 , sizeof( V_5 -> V_46 ) ) ;
F_25 ( V_5 ) ;
return 0 ;
}
static void F_29 ( void * V_75 , T_1 * V_76 ,
struct V_77 * V_78 )
{
struct V_79 * V_80 = ( void * ) V_78 -> V_71 ;
struct V_81 * V_82 = V_75 ;
struct V_4 * V_5 = V_82 -> V_5 ;
struct V_65 * V_66 ;
struct V_67 * V_68 ;
if ( V_78 -> type != V_90 ||
V_80 -> V_103 == V_69 )
return;
V_66 = F_14 ( V_5 -> V_70 [ V_80 -> V_103 ] ,
F_15 ( & V_5 -> V_56 ) ) ;
V_68 = ( void * ) V_66 -> V_71 ;
if ( ! V_68 -> V_72 )
V_82 -> V_51 = false ;
}
void F_30 ( struct V_4 * V_5 , struct V_77 * V_78 ,
enum V_117 V_118 )
{
struct V_79 * V_80 = ( void * ) V_78 -> V_71 ;
struct V_81 V_82 = {
. V_5 = V_5 ,
. V_51 = true ,
} ;
int V_13 ;
F_31 ( & V_5 -> V_56 ) ;
if ( F_32 ( V_80 -> V_103 == V_69 ) )
goto V_119;
if ( ! F_11 ( & V_5 -> V_46 , 3 , V_102 ) )
goto V_119;
F_12 ( V_5 , L_19 , V_78 -> V_120 . V_121 ,
V_118 == V_122 ? L_20 : L_21 ) ;
if ( V_118 == V_123 || F_1 () )
V_13 = F_13 ( V_5 , V_80 -> V_103 ,
false ) ;
else
V_13 = F_13 ( V_5 , V_80 -> V_103 , true ) ;
if ( V_13 )
F_5 ( V_5 , L_22 ) ;
F_26 (
V_5 -> V_106 , V_107 ,
F_29 , & V_82 ) ;
V_82 . V_51 = V_82 . V_51 && V_82 . V_101 ;
if ( F_9 ( V_5 , V_82 . V_51 ) )
F_5 ( V_5 , L_11 ) ;
V_119:
F_33 ( & V_5 -> V_56 ) ;
}
void F_34 ( struct V_4 * V_5 , struct V_77 * V_78 )
{
struct V_83 * V_84 ;
enum V_87 V_88 ;
F_18 () ;
V_84 = F_19 ( V_78 -> V_84 ) ;
if ( V_84 && V_84 -> V_91 . V_92 )
V_88 = V_84 -> V_91 . V_92 -> V_88 ;
else
V_88 = - 1 ;
F_20 () ;
if ( V_88 == V_94 )
return;
memset ( & V_5 -> V_46 , 0 , sizeof( V_5 -> V_46 ) ) ;
F_25 ( V_5 ) ;
}
