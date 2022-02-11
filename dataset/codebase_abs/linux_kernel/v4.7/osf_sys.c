static int
F_1 ( struct V_1 * V_2 , const char * V_3 , int V_4 ,
T_1 V_5 , T_2 V_6 , unsigned int V_7 )
{
struct V_8 T_3 * V_9 ;
struct V_10 * V_11 =
F_2 ( V_2 , struct V_10 , V_2 ) ;
unsigned int V_12 = F_3 ( V_13 + V_4 + 1 , sizeof( V_14 ) ) ;
unsigned int V_15 ;
V_11 -> error = - V_16 ;
if ( V_12 > V_11 -> V_17 )
return - V_16 ;
V_15 = V_6 ;
if ( sizeof( V_15 ) < sizeof( V_6 ) && V_15 != V_6 ) {
V_11 -> error = - V_18 ;
return - V_18 ;
}
if ( V_11 -> V_19 ) {
if ( F_4 ( V_5 , V_11 -> V_19 ) )
goto V_20;
V_11 -> V_19 = NULL ;
}
V_9 = V_11 -> V_9 ;
if ( F_4 ( V_15 , & V_9 -> V_15 ) ||
F_4 ( V_4 , & V_9 -> V_21 ) ||
F_4 ( V_12 , & V_9 -> V_22 ) ||
F_5 ( V_9 -> V_23 , V_3 , V_4 ) ||
F_4 ( 0 , V_9 -> V_23 + V_4 ) )
goto V_20;
V_9 = ( void T_3 * ) V_9 + V_12 ;
V_11 -> V_9 = V_9 ;
V_11 -> V_17 -= V_12 ;
return 0 ;
V_20:
V_11 -> error = - V_24 ;
return - V_24 ;
}
static int
F_6 ( struct V_25 * V_26 , struct V_27 T_3 * V_27 )
{
struct V_27 V_28 = { 0 } ;
V_28 . V_29 = V_26 -> V_30 ;
V_28 . V_31 = V_26 -> V_32 ;
V_28 . V_33 = V_26 -> V_34 ;
V_28 . V_35 = F_7 ( F_8 () , V_26 -> V_36 ) ;
V_28 . V_37 = F_9 ( F_8 () , V_26 -> V_38 ) ;
V_28 . V_39 = V_26 -> V_40 ;
V_28 . V_41 = V_26 -> V_40 ;
V_28 . V_42 = V_26 -> V_43 ;
V_28 . V_44 = V_26 -> V_45 . V_46 / 1000 ;
V_28 . V_47 = V_26 -> V_48 . V_46 / 1000 ;
V_28 . V_49 = V_26 -> ctime . V_46 / 1000 ;
V_28 . V_50 = V_26 -> V_6 ;
V_28 . V_51 = V_26 -> V_45 . V_52 ;
V_28 . V_53 = V_26 -> V_48 . V_52 ;
V_28 . V_54 = V_26 -> ctime . V_52 ;
V_28 . V_55 = V_26 -> V_56 ;
V_28 . V_57 = V_26 -> V_58 ;
return F_5 ( V_27 , & V_28 , sizeof( V_28 ) ) ? - V_24 : 0 ;
}
static int
F_10 ( struct V_59 * V_60 , struct V_61 T_3 * V_27 ,
unsigned long V_62 )
{
struct V_61 V_63 ;
V_63 . V_64 = V_60 -> V_64 ;
V_63 . V_65 = 0 ;
V_63 . V_66 = V_60 -> V_67 ;
V_63 . V_68 = V_60 -> V_68 ;
V_63 . V_69 = V_60 -> V_69 ;
V_63 . V_70 = V_60 -> V_70 ;
V_63 . V_71 = V_60 -> V_71 ;
V_63 . V_72 = V_60 -> V_72 ;
V_63 . V_73 = V_60 -> V_73 ;
V_63 . V_74 = V_60 -> V_74 ;
if ( V_62 > sizeof( V_63 ) )
V_62 = sizeof( V_63 ) ;
return F_5 ( V_27 , & V_63 , V_62 ) ? - V_24 : 0 ;
}
static int
F_11 ( struct V_59 * V_60 , struct V_75 T_3 * V_27 ,
unsigned long V_62 )
{
struct V_75 V_63 = { 0 } ;
V_63 . V_64 = V_60 -> V_64 ;
V_63 . V_66 = V_60 -> V_67 ;
V_63 . V_68 = V_60 -> V_68 ;
V_63 . V_69 = V_60 -> V_69 ;
V_63 . V_70 = V_60 -> V_70 ;
V_63 . V_71 = V_60 -> V_71 ;
V_63 . V_72 = V_60 -> V_72 ;
V_63 . V_73 = V_60 -> V_73 ;
V_63 . V_74 = V_60 -> V_74 ;
if ( V_62 > sizeof( V_63 ) )
V_62 = sizeof( V_63 ) ;
return F_5 ( V_27 , & V_63 , V_62 ) ? - V_24 : 0 ;
}
static int
F_12 ( const char T_3 * V_76 ,
struct V_77 T_3 * args , int V_78 )
{
int V_79 ;
struct V_80 V_28 ;
struct V_81 * V_82 ;
V_79 = - V_24 ;
if ( F_13 ( & V_28 , args , sizeof( V_28 ) ) )
goto V_83;
V_82 = F_14 ( V_28 . V_82 ) ;
V_79 = F_15 ( V_82 ) ;
if ( F_16 ( V_82 ) )
goto V_83;
V_79 = F_17 ( V_82 -> V_3 , V_76 , L_1 , V_78 , NULL ) ;
F_18 ( V_82 ) ;
V_83:
return V_79 ;
}
static int
F_19 ( const char T_3 * V_76 ,
struct V_80 T_3 * args , int V_78 )
{
int V_79 ;
struct V_80 V_28 ;
struct V_81 * V_82 ;
V_79 = - V_24 ;
if ( F_13 ( & V_28 , args , sizeof( V_28 ) ) )
goto V_83;
V_82 = F_14 ( V_28 . V_82 ) ;
V_79 = F_15 ( V_82 ) ;
if ( F_16 ( V_82 ) )
goto V_83;
V_79 = F_17 ( V_82 -> V_3 , V_76 , L_2 , V_78 , NULL ) ;
F_18 ( V_82 ) ;
V_83:
return V_79 ;
}
static int
F_20 ( const char T_3 * V_76 ,
struct V_84 T_3 * args , int V_78 )
{
struct V_84 V_28 ;
if ( F_13 ( & V_28 , args , sizeof( V_28 ) ) )
return - V_24 ;
return F_17 ( L_3 , V_76 , L_4 , V_78 , NULL ) ;
}
static inline long
F_21 ( struct V_85 * V_86 , struct V_87 T_3 * V_88 )
{
return ( ! F_22 ( V_89 , V_88 , sizeof( * V_88 ) ) ||
( F_23 ( V_86 -> V_52 , & V_88 -> V_52 ) |
F_23 ( V_86 -> V_90 , & V_88 -> V_90 ) ) ) ;
}
static inline long
F_24 ( struct V_87 T_3 * V_86 , struct V_85 * V_88 )
{
return ( ! F_22 ( V_91 , V_86 , sizeof( * V_86 ) ) ||
( F_25 ( V_88 -> V_52 , & V_86 -> V_52 ) |
F_25 ( V_88 -> V_90 , & V_86 -> V_90 ) ) ) ;
}
static inline long
F_26 ( struct V_92 * V_86 , struct V_93 T_3 * V_88 )
{
return ( ! F_22 ( V_89 , V_88 , sizeof( * V_88 ) ) ||
( F_23 ( V_86 -> V_94 . V_52 , & V_88 -> V_94 . V_52 ) |
F_23 ( V_86 -> V_94 . V_90 , & V_88 -> V_94 . V_90 ) |
F_23 ( V_86 -> V_95 . V_52 , & V_88 -> V_95 . V_52 ) |
F_23 ( V_86 -> V_95 . V_90 , & V_88 -> V_95 . V_90 ) ) ) ;
}
static inline long
F_27 ( struct V_93 T_3 * V_86 , struct V_92 * V_88 )
{
return ( ! F_22 ( V_91 , V_86 , sizeof( * V_86 ) ) ||
( F_25 ( V_88 -> V_94 . V_52 , & V_86 -> V_94 . V_52 ) |
F_25 ( V_88 -> V_94 . V_90 , & V_86 -> V_94 . V_90 ) |
F_25 ( V_88 -> V_95 . V_52 , & V_86 -> V_95 . V_52 ) |
F_25 ( V_88 -> V_95 . V_90 , & V_86 -> V_95 . V_90 ) ) ) ;
}
static inline void
F_28 ( unsigned long V_96 , struct V_87 * V_97 )
{
V_97 -> V_90 = ( V_96 % V_98 ) * ( 1000000L / V_98 ) ;
V_97 -> V_52 = V_96 / V_98 ;
}
static unsigned long
F_29 ( unsigned long V_99 , unsigned long V_100 ,
unsigned long V_101 )
{
struct V_102 V_103 ;
V_103 . V_78 = 0 ;
V_103 . V_104 = V_100 ;
V_103 . V_105 = V_99 ;
V_103 . V_106 = V_101 ;
V_103 . V_107 = 0 ;
V_103 . V_108 = 0 ;
return F_30 ( & V_103 ) ;
}
unsigned long
F_31 ( struct V_109 * V_110 , unsigned long V_99 ,
unsigned long V_100 , unsigned long V_111 ,
unsigned long V_78 )
{
unsigned long V_101 ;
if ( V_112 -> V_113 & V_114 )
V_101 = 0x80000000 ;
else
V_101 = V_115 ;
if ( V_100 > V_101 )
return - V_116 ;
if ( V_78 & V_117 )
return V_99 ;
if ( V_99 ) {
V_99 = F_29 ( F_32 ( V_99 ) , V_100 , V_101 ) ;
if ( V_99 != ( unsigned long ) - V_116 )
return V_99 ;
}
V_99 = F_29 ( F_32 ( V_118 ) ,
V_100 , V_101 ) ;
if ( V_99 != ( unsigned long ) - V_116 )
return V_99 ;
V_99 = F_29 ( V_119 , V_100 , V_101 ) ;
return V_99 ;
}
static int
F_33 ( const struct V_120 T_3 * V_121 , unsigned long V_17 )
{
unsigned long V_88 ;
for ( V_88 = 0 ; V_88 < V_17 ; V_88 ++ ) {
int T_3 * V_122 = ( int T_3 * ) & V_121 [ V_88 ] . V_123 + 1 ;
if ( F_4 ( 0 , V_122 ) )
return - V_24 ;
}
return 0 ;
}
