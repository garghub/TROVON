static int
F_1 ( void * V_1 , const char * V_2 , int V_3 , T_1 V_4 ,
T_2 V_5 , unsigned int V_6 )
{
struct V_7 T_3 * V_8 ;
struct V_9 * V_10 = (struct V_9 * ) V_1 ;
unsigned int V_11 = F_2 ( V_12 + V_3 + 1 , sizeof( V_13 ) ) ;
unsigned int V_14 ;
V_10 -> error = - V_15 ;
if ( V_11 > V_10 -> V_16 )
return - V_15 ;
V_14 = V_5 ;
if ( sizeof( V_14 ) < sizeof( V_5 ) && V_14 != V_5 ) {
V_10 -> error = - V_17 ;
return - V_17 ;
}
if ( V_10 -> V_18 ) {
if ( F_3 ( V_4 , V_10 -> V_18 ) )
goto V_19;
V_10 -> V_18 = NULL ;
}
V_8 = V_10 -> V_8 ;
if ( F_3 ( V_14 , & V_8 -> V_14 ) ||
F_3 ( V_3 , & V_8 -> V_20 ) ||
F_3 ( V_11 , & V_8 -> V_21 ) ||
F_4 ( V_8 -> V_22 , V_2 , V_3 ) ||
F_3 ( 0 , V_8 -> V_22 + V_3 ) )
goto V_19;
V_8 = ( void T_3 * ) V_8 + V_11 ;
V_10 -> V_8 = V_8 ;
V_10 -> V_16 -= V_11 ;
return 0 ;
V_19:
V_10 -> error = - V_23 ;
return - V_23 ;
}
static int
F_5 ( struct V_24 * V_25 , struct V_26 T_3 * V_26 )
{
struct V_26 V_27 = { 0 } ;
V_27 . V_28 = V_25 -> V_29 ;
V_27 . V_30 = V_25 -> V_31 ;
V_27 . V_32 = V_25 -> V_33 ;
V_27 . V_34 = V_25 -> V_35 ;
V_27 . V_36 = V_25 -> V_37 ;
V_27 . V_38 = V_25 -> V_39 ;
V_27 . V_40 = V_25 -> V_39 ;
V_27 . V_41 = V_25 -> V_42 ;
V_27 . V_43 = V_25 -> V_44 . V_45 / 1000 ;
V_27 . V_46 = V_25 -> V_47 . V_45 / 1000 ;
V_27 . V_48 = V_25 -> ctime . V_45 / 1000 ;
V_27 . V_49 = V_25 -> V_5 ;
V_27 . V_50 = V_25 -> V_44 . V_51 ;
V_27 . V_52 = V_25 -> V_47 . V_51 ;
V_27 . V_53 = V_25 -> ctime . V_51 ;
V_27 . V_54 = V_25 -> V_55 ;
V_27 . V_56 = V_25 -> V_57 ;
return F_4 ( V_26 , & V_27 , sizeof( V_27 ) ) ? - V_23 : 0 ;
}
static int
F_6 ( struct V_58 * V_59 , struct V_60 T_3 * V_26 ,
unsigned long V_61 )
{
struct V_60 V_62 ;
V_62 . V_63 = V_59 -> V_63 ;
V_62 . V_64 = 0 ;
V_62 . V_65 = V_59 -> V_66 ;
V_62 . V_67 = V_59 -> V_67 ;
V_62 . V_68 = V_59 -> V_68 ;
V_62 . V_69 = V_59 -> V_69 ;
V_62 . V_70 = V_59 -> V_70 ;
V_62 . V_71 = V_59 -> V_71 ;
V_62 . V_72 = V_59 -> V_72 ;
V_62 . V_73 = V_59 -> V_73 ;
if ( V_61 > sizeof( V_62 ) )
V_61 = sizeof( V_62 ) ;
return F_4 ( V_26 , & V_62 , V_61 ) ? - V_23 : 0 ;
}
static int
F_7 ( struct V_58 * V_59 , struct V_74 T_3 * V_26 ,
unsigned long V_61 )
{
struct V_74 V_62 = { 0 } ;
V_62 . V_63 = V_59 -> V_63 ;
V_62 . V_65 = V_59 -> V_66 ;
V_62 . V_67 = V_59 -> V_67 ;
V_62 . V_68 = V_59 -> V_68 ;
V_62 . V_69 = V_59 -> V_69 ;
V_62 . V_70 = V_59 -> V_70 ;
V_62 . V_71 = V_59 -> V_71 ;
V_62 . V_72 = V_59 -> V_72 ;
V_62 . V_73 = V_59 -> V_73 ;
if ( V_61 > sizeof( V_62 ) )
V_61 = sizeof( V_62 ) ;
return F_4 ( V_26 , & V_62 , V_61 ) ? - V_23 : 0 ;
}
static int
F_8 ( char * V_75 , struct V_76 T_3 * args , int V_77 )
{
int V_78 ;
struct V_79 V_27 ;
char * V_80 ;
V_78 = - V_23 ;
if ( F_9 ( & V_27 , args , sizeof( V_27 ) ) )
goto V_81;
V_80 = F_10 ( V_27 . V_80 ) ;
V_78 = F_11 ( V_80 ) ;
if ( F_12 ( V_80 ) )
goto V_81;
V_78 = F_13 ( V_80 , V_75 , L_1 , V_77 , NULL ) ;
F_14 ( V_80 ) ;
V_81:
return V_78 ;
}
static int
F_15 ( char * V_75 , struct V_79 T_3 * args , int V_77 )
{
int V_78 ;
struct V_79 V_27 ;
char * V_80 ;
V_78 = - V_23 ;
if ( F_9 ( & V_27 , args , sizeof( V_27 ) ) )
goto V_81;
V_80 = F_10 ( V_27 . V_80 ) ;
V_78 = F_11 ( V_80 ) ;
if ( F_12 ( V_80 ) )
goto V_81;
V_78 = F_13 ( V_80 , V_75 , L_2 , V_77 , NULL ) ;
F_14 ( V_80 ) ;
V_81:
return V_78 ;
}
static int
F_16 ( char * V_75 , struct V_82 T_3 * args , int V_77 )
{
struct V_82 V_27 ;
if ( F_9 ( & V_27 , args , sizeof( V_27 ) ) )
return - V_23 ;
return F_13 ( L_3 , V_75 , L_4 , V_77 , NULL ) ;
}
static inline long
F_17 ( struct V_83 * V_84 , struct V_85 T_3 * V_86 )
{
return ( ! F_18 ( V_87 , V_86 , sizeof( * V_86 ) ) ||
( F_19 ( V_84 -> V_51 , & V_86 -> V_51 ) |
F_19 ( V_84 -> V_88 , & V_86 -> V_88 ) ) ) ;
}
static inline long
F_20 ( struct V_85 T_3 * V_84 , struct V_83 * V_86 )
{
return ( ! F_18 ( V_89 , V_84 , sizeof( * V_84 ) ) ||
( F_21 ( V_86 -> V_51 , & V_84 -> V_51 ) |
F_21 ( V_86 -> V_88 , & V_84 -> V_88 ) ) ) ;
}
static inline long
F_22 ( struct V_90 * V_84 , struct V_91 T_3 * V_86 )
{
return ( ! F_18 ( V_87 , V_86 , sizeof( * V_86 ) ) ||
( F_19 ( V_84 -> V_92 . V_51 , & V_86 -> V_92 . V_51 ) |
F_19 ( V_84 -> V_92 . V_88 , & V_86 -> V_92 . V_88 ) |
F_19 ( V_84 -> V_93 . V_51 , & V_86 -> V_93 . V_51 ) |
F_19 ( V_84 -> V_93 . V_88 , & V_86 -> V_93 . V_88 ) ) ) ;
}
static inline long
F_23 ( struct V_91 T_3 * V_84 , struct V_90 * V_86 )
{
return ( ! F_18 ( V_89 , V_84 , sizeof( * V_84 ) ) ||
( F_21 ( V_86 -> V_92 . V_51 , & V_84 -> V_92 . V_51 ) |
F_21 ( V_86 -> V_92 . V_88 , & V_84 -> V_92 . V_88 ) |
F_21 ( V_86 -> V_93 . V_51 , & V_84 -> V_93 . V_51 ) |
F_21 ( V_86 -> V_93 . V_88 , & V_84 -> V_93 . V_88 ) ) ) ;
}
static inline void
F_24 ( unsigned long V_94 , struct V_85 * V_95 )
{
V_95 -> V_88 = ( V_94 % V_96 ) * ( 1000000L / V_96 ) ;
V_95 -> V_51 = V_94 / V_96 ;
}
static unsigned long
F_25 ( unsigned long V_97 , unsigned long V_98 ,
unsigned long V_99 )
{
struct V_100 * V_101 = F_26 ( V_102 -> V_103 , V_97 ) ;
while ( 1 ) {
if ( V_99 - V_98 < V_97 )
return - V_104 ;
if ( ! V_101 || V_97 + V_98 <= V_101 -> V_105 )
return V_97 ;
V_97 = V_101 -> V_106 ;
V_101 = V_101 -> V_107 ;
}
}
unsigned long
F_27 ( struct V_108 * V_109 , unsigned long V_97 ,
unsigned long V_98 , unsigned long V_110 ,
unsigned long V_77 )
{
unsigned long V_99 ;
if ( V_102 -> V_111 & V_112 )
V_99 = 0x80000000 ;
else
V_99 = V_113 ;
if ( V_98 > V_99 )
return - V_104 ;
if ( V_77 & V_114 )
return V_97 ;
if ( V_97 ) {
V_97 = F_25 ( F_28 ( V_97 ) , V_98 , V_99 ) ;
if ( V_97 != ( unsigned long ) - V_104 )
return V_97 ;
}
V_97 = F_25 ( F_28 ( V_115 ) ,
V_98 , V_99 ) ;
if ( V_97 != ( unsigned long ) - V_104 )
return V_97 ;
V_97 = F_25 ( V_116 , V_98 , V_99 ) ;
return V_97 ;
}
static int
F_29 ( const struct V_117 T_3 * V_118 , unsigned long V_16 )
{
unsigned long V_86 ;
for ( V_86 = 0 ; V_86 < V_16 ; V_86 ++ ) {
int T_3 * V_119 = ( int T_3 * ) & V_118 [ V_86 ] . V_120 + 1 ;
if ( F_3 ( 0 , V_119 ) )
return - V_23 ;
}
return 0 ;
}
