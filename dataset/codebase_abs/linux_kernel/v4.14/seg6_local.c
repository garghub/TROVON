static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 -> V_4 ;
}
static struct V_5 * F_2 ( struct V_6 * V_7 )
{
struct V_5 * V_8 ;
int V_9 , V_10 = 0 ;
if ( F_3 ( V_7 , & V_10 , V_11 , NULL , NULL ) < 0 )
return NULL ;
if ( ! F_4 ( V_7 , V_10 + sizeof( * V_8 ) ) )
return NULL ;
V_8 = (struct V_5 * ) ( V_7 -> V_4 + V_10 ) ;
V_9 = ( V_8 -> V_12 + 1 ) << 3 ;
if ( ! F_4 ( V_7 , V_10 + V_9 ) )
return NULL ;
if ( ! F_5 ( V_8 , V_9 ) )
return NULL ;
return V_8 ;
}
static struct V_5 * F_6 ( struct V_6 * V_7 )
{
struct V_5 * V_8 ;
V_8 = F_2 ( V_7 ) ;
if ( ! V_8 )
return NULL ;
if ( V_8 -> V_13 == 0 )
return NULL ;
#ifdef F_7
if ( ! F_8 ( V_7 ) )
return NULL ;
#endif
return V_8 ;
}
static bool F_9 ( struct V_6 * V_7 , int V_14 )
{
struct V_5 * V_8 ;
unsigned int V_15 = 0 ;
V_8 = F_2 ( V_7 ) ;
if ( V_8 && V_8 -> V_13 > 0 )
return false ;
#ifdef F_7
if ( V_8 && ! F_8 ( V_7 ) )
return false ;
#endif
if ( F_3 ( V_7 , & V_15 , V_14 , NULL , NULL ) < 0 )
return false ;
if ( ! F_10 ( V_7 , V_15 ) )
return false ;
F_11 ( V_7 , F_12 ( V_7 ) , V_15 ) ;
F_13 ( V_7 ) ;
F_14 ( V_7 ) ;
V_7 -> V_16 = 0 ;
return true ;
}
static void F_15 ( struct V_5 * V_8 , struct V_17 * V_18 )
{
struct V_17 * V_19 ;
V_8 -> V_13 -- ;
V_19 = V_8 -> V_20 + V_8 -> V_13 ;
* V_18 = * V_19 ;
}
static void F_16 ( struct V_6 * V_7 , struct V_17 * V_21 ,
T_1 V_22 )
{
struct V_23 * V_23 = F_17 ( V_7 -> V_24 ) ;
struct V_25 * V_26 = F_18 ( V_7 ) ;
int V_27 = V_28 ;
struct V_29 * V_30 = NULL ;
struct V_31 * V_32 ;
struct V_33 V_34 ;
V_34 . V_35 = V_7 -> V_24 -> V_36 ;
V_34 . V_18 = V_21 ? * V_21 : V_26 -> V_18 ;
V_34 . V_37 = V_26 -> V_37 ;
V_34 . V_38 = F_19 ( V_26 ) ;
V_34 . V_39 = V_7 -> V_40 ;
V_34 . V_41 = V_26 -> V_42 ;
if ( V_21 )
V_34 . V_43 = V_44 ;
if ( ! V_22 ) {
V_30 = F_20 ( V_23 , V_7 -> V_24 , & V_34 , V_27 ) ;
} else {
struct V_45 * V_46 ;
V_46 = F_21 ( V_23 , V_22 ) ;
if ( ! V_46 )
goto V_47;
V_32 = F_22 ( V_23 , V_46 , 0 , & V_34 , V_27 ) ;
V_30 = & V_32 -> V_30 ;
}
if ( V_30 && V_30 -> V_24 -> V_27 & V_48 && ! V_30 -> error ) {
F_23 ( V_30 ) ;
V_30 = NULL ;
}
V_47:
if ( ! V_30 ) {
V_32 = V_23 -> V_49 . V_50 ;
V_30 = & V_32 -> V_30 ;
F_24 ( V_30 ) ;
}
F_25 ( V_7 ) ;
F_26 ( V_7 , V_30 ) ;
}
static int F_27 ( struct V_6 * V_7 , struct V_1 * V_51 )
{
struct V_5 * V_8 ;
V_8 = F_6 ( V_7 ) ;
if ( ! V_8 )
goto V_52;
F_15 ( V_8 , & F_18 ( V_7 ) -> V_18 ) ;
F_16 ( V_7 , NULL , 0 ) ;
return F_28 ( V_7 ) ;
V_52:
F_29 ( V_7 ) ;
return - V_53 ;
}
static int F_30 ( struct V_6 * V_7 , struct V_1 * V_51 )
{
struct V_5 * V_8 ;
V_8 = F_6 ( V_7 ) ;
if ( ! V_8 )
goto V_52;
F_15 ( V_8 , & F_18 ( V_7 ) -> V_18 ) ;
F_16 ( V_7 , & V_51 -> V_54 , 0 ) ;
return F_28 ( V_7 ) ;
V_52:
F_29 ( V_7 ) ;
return - V_53 ;
}
static int F_31 ( struct V_6 * V_7 , struct V_1 * V_51 )
{
struct V_5 * V_8 ;
V_8 = F_6 ( V_7 ) ;
if ( ! V_8 )
goto V_52;
F_15 ( V_8 , & F_18 ( V_7 ) -> V_18 ) ;
F_16 ( V_7 , NULL , V_51 -> V_46 ) ;
return F_28 ( V_7 ) ;
V_52:
F_29 ( V_7 ) ;
return - V_53 ;
}
static int F_32 ( struct V_6 * V_7 ,
struct V_1 * V_51 )
{
struct V_23 * V_23 = F_17 ( V_7 -> V_24 ) ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
if ( ! F_9 ( V_7 , V_59 ) )
goto V_52;
if ( ! F_4 ( V_7 , V_60 ) )
goto V_52;
F_33 ( V_7 ) ;
V_58 = (struct V_57 * ) V_7 -> V_4 ;
if ( ! F_34 ( V_58 -> V_61 ) )
goto V_52;
V_56 = F_35 ( V_23 , V_51 -> V_62 ) ;
if ( ! V_56 )
goto V_52;
if ( V_56 -> type != V_63 )
goto V_52;
if ( ! ( V_56 -> V_27 & V_64 ) || ! F_36 ( V_56 ) )
goto V_52;
F_37 ( V_7 ) ;
if ( F_38 ( V_7 ) )
goto V_52;
F_39 ( V_7 ) ;
if ( V_7 -> V_9 - V_60 > V_56 -> V_65 )
goto V_52;
V_7 -> V_24 = V_56 ;
V_7 -> V_66 = V_58 -> V_61 ;
return F_40 ( V_7 ) ;
V_52:
F_29 ( V_7 ) ;
return - V_53 ;
}
static int F_41 ( struct V_6 * V_7 ,
struct V_1 * V_51 )
{
struct V_17 * V_21 = NULL ;
if ( ! F_9 ( V_7 , V_67 ) )
goto V_52;
if ( ! F_4 ( V_7 , sizeof( struct V_25 ) ) )
goto V_52;
if ( ! F_42 ( & V_51 -> V_54 ) )
V_21 = & V_51 -> V_54 ;
F_16 ( V_7 , V_21 , 0 ) ;
return F_28 ( V_7 ) ;
V_52:
F_29 ( V_7 ) ;
return - V_53 ;
}
static int F_43 ( struct V_6 * V_7 ,
struct V_1 * V_51 )
{
struct V_68 * V_69 ;
T_2 V_21 ;
int V_70 ;
if ( ! F_9 ( V_7 , V_71 ) )
goto V_52;
if ( ! F_4 ( V_7 , sizeof( struct V_68 ) ) )
goto V_52;
V_7 -> V_66 = F_44 ( V_72 ) ;
V_69 = F_45 ( V_7 ) ;
V_21 = V_51 -> V_73 . V_74 ? : V_69 -> V_18 ;
F_25 ( V_7 ) ;
V_70 = F_46 ( V_7 , V_21 , V_69 -> V_37 , 0 , V_7 -> V_24 ) ;
if ( V_70 )
goto V_52;
return F_28 ( V_7 ) ;
V_52:
F_29 ( V_7 ) ;
return - V_53 ;
}
static int F_47 ( struct V_6 * V_7 ,
struct V_1 * V_51 )
{
if ( ! F_9 ( V_7 , V_67 ) )
goto V_52;
if ( ! F_4 ( V_7 , sizeof( struct V_25 ) ) )
goto V_52;
F_16 ( V_7 , NULL , V_51 -> V_46 ) ;
return F_28 ( V_7 ) ;
V_52:
F_29 ( V_7 ) ;
return - V_53 ;
}
static int F_48 ( struct V_6 * V_7 , struct V_1 * V_51 )
{
struct V_5 * V_8 ;
int V_70 = - V_53 ;
V_8 = F_6 ( V_7 ) ;
if ( ! V_8 )
goto V_52;
V_70 = F_49 ( V_7 , V_51 -> V_8 ) ;
if ( V_70 )
goto V_52;
F_18 ( V_7 ) -> V_75 = F_44 ( V_7 -> V_9 - sizeof( struct V_25 ) ) ;
F_50 ( V_7 , sizeof( struct V_25 ) ) ;
F_16 ( V_7 , NULL , 0 ) ;
return F_28 ( V_7 ) ;
V_52:
F_29 ( V_7 ) ;
return V_70 ;
}
static int F_51 ( struct V_6 * V_7 ,
struct V_1 * V_51 )
{
struct V_5 * V_8 ;
int V_70 = - V_53 ;
V_8 = F_6 ( V_7 ) ;
if ( ! V_8 )
goto V_52;
F_15 ( V_8 , & F_18 ( V_7 ) -> V_18 ) ;
F_52 ( V_7 ) ;
V_7 -> V_16 = 1 ;
V_70 = F_53 ( V_7 , V_51 -> V_8 , V_67 ) ;
if ( V_70 )
goto V_52;
F_18 ( V_7 ) -> V_75 = F_44 ( V_7 -> V_9 - sizeof( struct V_25 ) ) ;
F_50 ( V_7 , sizeof( struct V_25 ) ) ;
F_16 ( V_7 , NULL , 0 ) ;
return F_28 ( V_7 ) ;
V_52:
F_29 ( V_7 ) ;
return V_70 ;
}
static struct V_76 * F_54 ( int V_77 )
{
struct V_76 * V_78 ;
int V_79 , V_80 ;
V_80 = sizeof( V_81 ) / sizeof( struct V_76 ) ;
for ( V_79 = 0 ; V_79 < V_80 ; V_79 ++ ) {
V_78 = & V_81 [ V_79 ] ;
if ( V_78 -> V_77 == V_77 )
return V_78 ;
}
return NULL ;
}
static int F_55 ( struct V_6 * V_7 )
{
struct V_29 * V_82 = F_56 ( V_7 ) ;
struct V_76 * V_78 ;
struct V_1 * V_51 ;
if ( V_7 -> V_66 != F_44 ( V_83 ) ) {
F_29 ( V_7 ) ;
return - V_53 ;
}
V_51 = F_1 ( V_82 -> V_84 ) ;
V_78 = V_51 -> V_78 ;
return V_78 -> V_85 ( V_7 , V_51 ) ;
}
static int F_57 ( struct V_86 * * V_87 , struct V_1 * V_51 )
{
struct V_5 * V_8 ;
int V_9 ;
V_8 = F_58 ( V_87 [ V_88 ] ) ;
V_9 = F_59 ( V_87 [ V_88 ] ) ;
if ( V_9 < sizeof( * V_8 ) + sizeof( struct V_17 ) )
return - V_53 ;
if ( ! F_5 ( V_8 , V_9 ) )
return - V_53 ;
V_51 -> V_8 = F_60 ( V_9 , V_89 ) ;
if ( ! V_51 -> V_8 )
return - V_90 ;
memcpy ( V_51 -> V_8 , V_8 , V_9 ) ;
V_51 -> V_91 += V_9 ;
return 0 ;
}
static int F_61 ( struct V_6 * V_7 , struct V_1 * V_51 )
{
struct V_5 * V_8 ;
struct V_86 * V_92 ;
int V_9 ;
V_8 = V_51 -> V_8 ;
V_9 = ( V_8 -> V_12 + 1 ) << 3 ;
V_92 = F_62 ( V_7 , V_88 , V_9 ) ;
if ( ! V_92 )
return - V_93 ;
memcpy ( F_58 ( V_92 ) , V_8 , V_9 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_94 , struct V_1 * V_95 )
{
int V_9 = ( V_94 -> V_8 -> V_12 + 1 ) << 3 ;
if ( V_9 != ( ( V_95 -> V_8 -> V_12 + 1 ) << 3 ) )
return 1 ;
return memcmp ( V_94 -> V_8 , V_95 -> V_8 , V_9 ) ;
}
static int F_64 ( struct V_86 * * V_87 , struct V_1 * V_51 )
{
V_51 -> V_46 = F_65 ( V_87 [ V_96 ] ) ;
return 0 ;
}
static int F_66 ( struct V_6 * V_7 , struct V_1 * V_51 )
{
if ( F_67 ( V_7 , V_96 , V_51 -> V_46 ) )
return - V_93 ;
return 0 ;
}
static int F_68 ( struct V_1 * V_94 , struct V_1 * V_95 )
{
if ( V_94 -> V_46 != V_95 -> V_46 )
return 1 ;
return 0 ;
}
static int F_69 ( struct V_86 * * V_87 , struct V_1 * V_51 )
{
memcpy ( & V_51 -> V_73 , F_58 ( V_87 [ V_97 ] ) ,
sizeof( struct V_98 ) ) ;
return 0 ;
}
static int F_70 ( struct V_6 * V_7 , struct V_1 * V_51 )
{
struct V_86 * V_92 ;
V_92 = F_62 ( V_7 , V_97 , sizeof( struct V_98 ) ) ;
if ( ! V_92 )
return - V_93 ;
memcpy ( F_58 ( V_92 ) , & V_51 -> V_73 , sizeof( struct V_98 ) ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_94 , struct V_1 * V_95 )
{
return memcmp ( & V_94 -> V_73 , & V_95 -> V_73 , sizeof( struct V_98 ) ) ;
}
static int F_72 ( struct V_86 * * V_87 , struct V_1 * V_51 )
{
memcpy ( & V_51 -> V_54 , F_58 ( V_87 [ V_99 ] ) ,
sizeof( struct V_17 ) ) ;
return 0 ;
}
static int F_73 ( struct V_6 * V_7 , struct V_1 * V_51 )
{
struct V_86 * V_92 ;
V_92 = F_62 ( V_7 , V_99 , sizeof( struct V_17 ) ) ;
if ( ! V_92 )
return - V_93 ;
memcpy ( F_58 ( V_92 ) , & V_51 -> V_54 , sizeof( struct V_17 ) ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_94 , struct V_1 * V_95 )
{
return memcmp ( & V_94 -> V_54 , & V_95 -> V_54 , sizeof( struct V_17 ) ) ;
}
static int F_75 ( struct V_86 * * V_87 , struct V_1 * V_51 )
{
V_51 -> V_100 = F_65 ( V_87 [ V_101 ] ) ;
return 0 ;
}
static int F_76 ( struct V_6 * V_7 , struct V_1 * V_51 )
{
if ( F_67 ( V_7 , V_101 , V_51 -> V_100 ) )
return - V_93 ;
return 0 ;
}
static int F_77 ( struct V_1 * V_94 , struct V_1 * V_95 )
{
if ( V_94 -> V_100 != V_95 -> V_100 )
return 1 ;
return 0 ;
}
static int F_78 ( struct V_86 * * V_87 , struct V_1 * V_51 )
{
V_51 -> V_62 = F_65 ( V_87 [ V_102 ] ) ;
return 0 ;
}
static int F_79 ( struct V_6 * V_7 , struct V_1 * V_51 )
{
if ( F_67 ( V_7 , V_102 , V_51 -> V_62 ) )
return - V_93 ;
return 0 ;
}
static int F_80 ( struct V_1 * V_94 , struct V_1 * V_95 )
{
if ( V_94 -> V_62 != V_95 -> V_62 )
return 1 ;
return 0 ;
}
static int F_81 ( struct V_86 * * V_87 , struct V_1 * V_51 )
{
struct V_103 * V_104 ;
struct V_76 * V_78 ;
int V_79 , V_70 ;
V_78 = F_54 ( V_51 -> V_77 ) ;
if ( ! V_78 )
return - V_53 ;
if ( ! V_78 -> V_85 )
return - V_105 ;
V_51 -> V_78 = V_78 ;
V_51 -> V_91 += V_78 -> V_106 ;
for ( V_79 = 0 ; V_79 < V_107 + 1 ; V_79 ++ ) {
if ( V_78 -> V_87 & ( 1 << V_79 ) ) {
if ( ! V_87 [ V_79 ] )
return - V_53 ;
V_104 = & V_108 [ V_79 ] ;
V_70 = V_104 -> V_109 ( V_87 , V_51 ) ;
if ( V_70 < 0 )
return V_70 ;
}
}
return 0 ;
}
static int F_82 ( struct V_86 * V_92 , unsigned int V_110 ,
const void * V_111 , struct V_2 * * V_112 ,
struct V_113 * V_114 )
{
struct V_86 * V_115 [ V_107 + 1 ] ;
struct V_2 * V_116 ;
struct V_1 * V_51 ;
int V_70 ;
if ( V_110 != V_117 )
return - V_53 ;
V_70 = F_83 ( V_115 , V_107 , V_92 , V_118 ,
V_114 ) ;
if ( V_70 < 0 )
return V_70 ;
if ( ! V_115 [ V_119 ] )
return - V_53 ;
V_116 = F_84 ( sizeof( * V_51 ) ) ;
if ( ! V_116 )
return - V_90 ;
V_51 = F_1 ( V_116 ) ;
V_51 -> V_77 = F_65 ( V_115 [ V_119 ] ) ;
V_70 = F_81 ( V_115 , V_51 ) ;
if ( V_70 < 0 )
goto V_120;
V_116 -> type = V_121 ;
V_116 -> V_27 = V_122 ;
V_116 -> V_91 = V_51 -> V_91 ;
* V_112 = V_116 ;
return 0 ;
V_120:
F_85 ( V_51 -> V_8 ) ;
F_85 ( V_116 ) ;
return V_70 ;
}
static void F_86 ( struct V_2 * V_3 )
{
struct V_1 * V_51 = F_1 ( V_3 ) ;
F_85 ( V_51 -> V_8 ) ;
}
static int F_87 ( struct V_6 * V_7 ,
struct V_2 * V_3 )
{
struct V_1 * V_51 = F_1 ( V_3 ) ;
struct V_103 * V_104 ;
int V_79 , V_70 ;
if ( F_67 ( V_7 , V_119 , V_51 -> V_77 ) )
return - V_93 ;
for ( V_79 = 0 ; V_79 < V_107 + 1 ; V_79 ++ ) {
if ( V_51 -> V_78 -> V_87 & ( 1 << V_79 ) ) {
V_104 = & V_108 [ V_79 ] ;
V_70 = V_104 -> V_123 ( V_7 , V_51 ) ;
if ( V_70 < 0 )
return V_70 ;
}
}
return 0 ;
}
static int F_88 ( struct V_2 * V_3 )
{
struct V_1 * V_51 = F_1 ( V_3 ) ;
unsigned long V_87 ;
int V_124 ;
V_124 = F_89 ( 4 ) ;
V_87 = V_51 -> V_78 -> V_87 ;
if ( V_87 & ( 1 << V_88 ) )
V_124 += F_89 ( ( V_51 -> V_8 -> V_12 + 1 ) << 3 ) ;
if ( V_87 & ( 1 << V_96 ) )
V_124 += F_89 ( 4 ) ;
if ( V_87 & ( 1 << V_97 ) )
V_124 += F_89 ( 4 ) ;
if ( V_87 & ( 1 << V_99 ) )
V_124 += F_89 ( 16 ) ;
if ( V_87 & ( 1 << V_101 ) )
V_124 += F_89 ( 4 ) ;
if ( V_87 & ( 1 << V_102 ) )
V_124 += F_89 ( 4 ) ;
return V_124 ;
}
static int F_90 ( struct V_2 * V_94 ,
struct V_2 * V_95 )
{
struct V_1 * V_125 , * V_126 ;
struct V_103 * V_104 ;
int V_79 ;
V_125 = F_1 ( V_94 ) ;
V_126 = F_1 ( V_95 ) ;
if ( V_125 -> V_77 != V_126 -> V_77 )
return 1 ;
if ( V_125 -> V_78 -> V_87 != V_126 -> V_78 -> V_87 )
return 1 ;
for ( V_79 = 0 ; V_79 < V_107 + 1 ; V_79 ++ ) {
if ( V_125 -> V_78 -> V_87 & ( 1 << V_79 ) ) {
V_104 = & V_108 [ V_79 ] ;
if ( V_104 -> V_127 ( V_125 , V_126 ) )
return 1 ;
}
}
return 0 ;
}
int T_3 F_91 ( void )
{
return F_92 ( & V_128 ,
V_121 ) ;
}
void F_93 ( void )
{
F_94 ( & V_128 , V_121 ) ;
}
