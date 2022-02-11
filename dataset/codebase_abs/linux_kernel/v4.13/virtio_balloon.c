static T_1 F_1 ( struct V_1 * V_1 )
{
unsigned long V_2 = F_2 ( V_1 ) ;
F_3 ( V_3 < V_4 ) ;
return V_2 * V_5 ;
}
static void F_4 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 -> V_11 ;
F_5 ( & V_9 -> V_12 ) ;
}
static void F_6 ( struct V_8 * V_9 , struct V_6 * V_7 )
{
struct V_13 V_14 ;
unsigned int V_15 ;
F_7 ( & V_14 , V_9 -> V_16 , sizeof( V_9 -> V_16 [ 0 ] ) * V_9 -> V_17 ) ;
F_8 ( V_7 , & V_14 , 1 , V_9 , V_18 ) ;
F_9 ( V_7 ) ;
F_10 ( V_9 -> V_12 , F_11 ( V_7 , & V_15 ) ) ;
}
static void F_12 ( struct V_8 * V_9 ,
T_2 V_16 [] , struct V_1 * V_1 )
{
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_5 ; V_19 ++ )
V_16 [ V_19 ] = F_13 ( V_9 -> V_10 ,
F_1 ( V_1 ) + V_19 ) ;
}
static unsigned F_14 ( struct V_8 * V_9 , T_3 V_20 )
{
struct V_21 * V_22 = & V_9 -> V_22 ;
unsigned V_23 ;
V_20 = F_15 ( V_20 , F_16 ( V_9 -> V_16 ) ) ;
F_17 ( & V_9 -> V_24 ) ;
for ( V_9 -> V_17 = 0 ; V_9 -> V_17 < V_20 ;
V_9 -> V_17 += V_5 ) {
struct V_1 * V_1 = F_18 ( V_22 ) ;
if ( ! V_1 ) {
F_19 ( & V_9 -> V_10 -> V_25 ,
L_1 ,
V_5 ) ;
F_20 ( 200 ) ;
break;
}
F_12 ( V_9 , V_9 -> V_16 + V_9 -> V_17 , V_1 ) ;
V_9 -> V_26 += V_5 ;
if ( ! F_21 ( V_9 -> V_10 ,
V_27 ) )
F_22 ( V_1 , - 1 ) ;
}
V_23 = V_9 -> V_17 ;
if ( V_9 -> V_17 != 0 )
F_6 ( V_9 , V_9 -> V_28 ) ;
F_23 ( & V_9 -> V_24 ) ;
return V_23 ;
}
static void F_24 ( struct V_8 * V_9 ,
struct V_29 * V_30 )
{
struct V_1 * V_1 , * V_31 ;
F_25 (page, next, pages, lru) {
if ( ! F_21 ( V_9 -> V_10 ,
V_27 ) )
F_22 ( V_1 , 1 ) ;
F_26 ( & V_1 -> V_32 ) ;
F_27 ( V_1 ) ;
}
}
static unsigned F_28 ( struct V_8 * V_9 , T_3 V_20 )
{
unsigned V_33 ;
struct V_1 * V_1 ;
struct V_21 * V_22 = & V_9 -> V_22 ;
F_29 ( V_30 ) ;
V_20 = F_15 ( V_20 , F_16 ( V_9 -> V_16 ) ) ;
F_17 ( & V_9 -> V_24 ) ;
V_20 = F_15 ( V_20 , ( T_3 ) V_9 -> V_26 ) ;
for ( V_9 -> V_17 = 0 ; V_9 -> V_17 < V_20 ;
V_9 -> V_17 += V_5 ) {
V_1 = F_30 ( V_22 ) ;
if ( ! V_1 )
break;
F_12 ( V_9 , V_9 -> V_16 + V_9 -> V_17 , V_1 ) ;
F_31 ( & V_1 -> V_32 , & V_30 ) ;
V_9 -> V_26 -= V_5 ;
}
V_33 = V_9 -> V_17 ;
if ( V_9 -> V_17 != 0 )
F_6 ( V_9 , V_9 -> V_34 ) ;
F_24 ( V_9 , & V_30 ) ;
F_23 ( & V_9 -> V_24 ) ;
return V_33 ;
}
static inline void F_32 ( struct V_8 * V_9 , int V_35 ,
T_4 V_36 , T_5 V_37 )
{
F_33 ( V_35 >= V_38 ) ;
V_9 -> V_39 [ V_35 ] . V_36 = F_34 ( V_9 -> V_10 , V_36 ) ;
V_9 -> V_39 [ V_35 ] . V_37 = F_35 ( V_9 -> V_10 , V_37 ) ;
}
static unsigned int F_36 ( struct V_8 * V_9 )
{
unsigned long V_40 [ V_41 ] ;
struct V_42 V_19 ;
unsigned int V_35 = 0 ;
long V_43 ;
F_37 ( V_40 ) ;
F_38 ( & V_19 ) ;
V_43 = F_39 () ;
#ifdef F_40
F_32 ( V_9 , V_35 ++ , V_44 ,
F_41 ( V_40 [ V_45 ] ) ) ;
F_32 ( V_9 , V_35 ++ , V_46 ,
F_41 ( V_40 [ V_47 ] ) ) ;
F_32 ( V_9 , V_35 ++ , V_48 , V_40 [ V_49 ] ) ;
F_32 ( V_9 , V_35 ++ , V_50 , V_40 [ V_51 ] ) ;
#endif
F_32 ( V_9 , V_35 ++ , V_52 ,
F_41 ( V_19 . V_53 ) ) ;
F_32 ( V_9 , V_35 ++ , V_54 ,
F_41 ( V_19 . V_55 ) ) ;
F_32 ( V_9 , V_35 ++ , V_56 ,
F_41 ( V_43 ) ) ;
return V_35 ;
}
static void F_42 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 -> V_11 ;
F_43 ( & V_9 -> V_57 ) ;
if ( ! V_9 -> V_58 )
F_44 ( V_59 , & V_9 -> V_60 ) ;
F_45 ( & V_9 -> V_57 ) ;
}
static void F_46 ( struct V_8 * V_9 )
{
struct V_6 * V_7 ;
struct V_13 V_14 ;
unsigned int V_15 , V_61 ;
V_61 = F_36 ( V_9 ) ;
V_7 = V_9 -> V_62 ;
if ( ! F_11 ( V_7 , & V_15 ) )
return;
F_7 ( & V_14 , V_9 -> V_39 , sizeof( V_9 -> V_39 [ 0 ] ) * V_61 ) ;
F_8 ( V_7 , & V_14 , 1 , V_9 , V_18 ) ;
F_9 ( V_7 ) ;
}
static void F_47 ( struct V_63 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
unsigned long V_64 ;
F_48 ( & V_9 -> V_57 , V_64 ) ;
if ( ! V_9 -> V_58 )
F_44 ( V_59 , & V_9 -> V_65 ) ;
F_49 ( & V_9 -> V_57 , V_64 ) ;
}
static inline T_6 F_50 ( struct V_8 * V_9 )
{
T_6 V_66 ;
T_1 V_26 ;
F_51 ( V_9 -> V_10 , struct V_67 , V_26 ,
& V_26 ) ;
if ( ! F_21 ( V_9 -> V_10 , V_68 ) )
V_26 = F_52 ( ( V_69 V_70 ) V_26 ) ;
V_66 = V_26 ;
return V_66 - V_9 -> V_26 ;
}
static void F_53 ( struct V_8 * V_9 )
{
T_1 V_71 = V_9 -> V_26 ;
if ( ! F_21 ( V_9 -> V_10 , V_68 ) )
V_71 = ( V_69 T_1 ) F_54 ( V_71 ) ;
F_55 ( V_9 -> V_10 , struct V_67 , V_71 ,
& V_71 ) ;
}
static int F_56 ( struct V_72 * V_73 ,
unsigned long V_74 , void * V_75 )
{
struct V_8 * V_9 ;
unsigned long * V_76 ;
unsigned V_33 ;
V_9 = F_57 ( V_73 , struct V_8 , V_77 ) ;
if ( ! F_21 ( V_9 -> V_10 , V_27 ) )
return V_78 ;
V_76 = V_75 ;
V_33 = F_28 ( V_9 , V_79 ) ;
F_53 ( V_9 ) ;
* V_76 += V_33 ;
return V_78 ;
}
static void F_58 ( struct V_80 * V_81 )
{
struct V_8 * V_9 ;
V_9 = F_57 ( V_81 , struct V_8 ,
V_60 ) ;
F_46 ( V_9 ) ;
}
static void F_59 ( struct V_80 * V_81 )
{
struct V_8 * V_9 ;
T_6 V_82 ;
V_9 = F_57 ( V_81 , struct V_8 ,
V_65 ) ;
V_82 = F_50 ( V_9 ) ;
if ( V_82 > 0 )
V_82 -= F_14 ( V_9 , V_82 ) ;
else if ( V_82 < 0 )
V_82 += F_28 ( V_9 , - V_82 ) ;
F_53 ( V_9 ) ;
if ( V_82 )
F_44 ( V_59 , V_81 ) ;
}
static int F_60 ( struct V_8 * V_9 )
{
struct V_6 * V_83 [ 3 ] ;
T_7 * V_84 [] = { F_4 , F_4 , F_42 } ;
static const char * const V_85 [] = { L_2 , L_3 , L_4 } ;
int V_86 , V_87 ;
V_87 = F_21 ( V_9 -> V_10 , V_88 ) ? 3 : 2 ;
V_86 = F_61 ( V_9 -> V_10 , V_87 , V_83 , V_84 , V_85 , NULL ) ;
if ( V_86 )
return V_86 ;
V_9 -> V_28 = V_83 [ 0 ] ;
V_9 -> V_34 = V_83 [ 1 ] ;
if ( F_21 ( V_9 -> V_10 , V_88 ) ) {
struct V_13 V_14 ;
unsigned int V_61 ;
V_9 -> V_62 = V_83 [ 2 ] ;
V_61 = F_36 ( V_9 ) ;
F_7 ( & V_14 , V_9 -> V_39 , sizeof( V_9 -> V_39 [ 0 ] ) * V_61 ) ;
if ( F_8 ( V_9 -> V_62 , & V_14 , 1 , V_9 , V_18 )
< 0 )
F_62 () ;
F_9 ( V_9 -> V_62 ) ;
}
return 0 ;
}
static int F_63 ( struct V_21 * V_22 ,
struct V_1 * V_89 , struct V_1 * V_1 , enum V_90 V_91 )
{
struct V_8 * V_9 = F_57 ( V_22 ,
struct V_8 , V_22 ) ;
unsigned long V_64 ;
if ( ! F_64 ( & V_9 -> V_24 ) )
return - V_92 ;
F_65 ( V_89 ) ;
F_48 ( & V_22 -> V_93 , V_64 ) ;
F_66 ( V_22 , V_89 ) ;
V_22 -> V_94 -- ;
F_67 ( V_95 ) ;
F_49 ( & V_22 -> V_93 , V_64 ) ;
V_9 -> V_17 = V_5 ;
F_12 ( V_9 , V_9 -> V_16 , V_89 ) ;
F_6 ( V_9 , V_9 -> V_28 ) ;
F_68 ( V_1 ) ;
V_9 -> V_17 = V_5 ;
F_12 ( V_9 , V_9 -> V_16 , V_1 ) ;
F_6 ( V_9 , V_9 -> V_34 ) ;
F_23 ( & V_9 -> V_24 ) ;
F_27 ( V_1 ) ;
return V_96 ;
}
static struct V_97 * F_69 ( struct V_98 * V_99 ,
int V_64 , const char * V_100 , void * V_101 )
{
static const struct V_102 V_103 = {
. V_104 = V_105 ,
} ;
return F_70 ( V_99 , L_5 , NULL , & V_103 ,
V_106 ) ;
}
static int F_71 ( struct V_63 * V_10 )
{
struct V_8 * V_9 ;
int V_86 ;
if ( ! V_10 -> V_107 -> V_108 ) {
F_72 ( & V_10 -> V_25 , L_6 ,
V_109 ) ;
return - V_110 ;
}
V_10 -> V_11 = V_9 = F_73 ( sizeof( * V_9 ) , V_18 ) ;
if ( ! V_9 ) {
V_86 = - V_111 ;
goto V_112;
}
F_74 ( & V_9 -> V_60 , F_58 ) ;
F_74 ( & V_9 -> V_65 , F_59 ) ;
F_75 ( & V_9 -> V_57 ) ;
V_9 -> V_58 = false ;
V_9 -> V_26 = 0 ;
F_76 ( & V_9 -> V_24 ) ;
F_77 ( & V_9 -> V_12 ) ;
V_9 -> V_10 = V_10 ;
F_78 ( & V_9 -> V_22 ) ;
V_86 = F_60 ( V_9 ) ;
if ( V_86 )
goto V_113;
V_9 -> V_77 . V_114 = F_56 ;
V_9 -> V_77 . V_115 = V_116 ;
V_86 = F_79 ( & V_9 -> V_77 ) ;
if ( V_86 < 0 )
goto V_117;
#ifdef F_80
V_118 = F_81 ( & V_119 ) ;
if ( F_82 ( V_118 ) ) {
V_86 = F_83 ( V_118 ) ;
F_84 ( & V_9 -> V_77 ) ;
goto V_117;
}
V_9 -> V_22 . V_120 = F_63 ;
V_9 -> V_22 . V_121 = F_85 ( V_118 -> V_122 ) ;
if ( F_82 ( V_9 -> V_22 . V_121 ) ) {
V_86 = F_83 ( V_9 -> V_22 . V_121 ) ;
F_86 ( V_118 ) ;
F_84 ( & V_9 -> V_77 ) ;
V_9 -> V_22 . V_121 = NULL ;
goto V_117;
}
V_9 -> V_22 . V_121 -> V_123 -> V_124 = & V_125 ;
#endif
F_87 ( V_10 ) ;
if ( F_50 ( V_9 ) )
F_47 ( V_10 ) ;
return 0 ;
V_117:
V_10 -> V_107 -> V_126 ( V_10 ) ;
V_113:
F_88 ( V_9 ) ;
V_112:
return V_86 ;
}
static void F_89 ( struct V_8 * V_9 )
{
while ( V_9 -> V_26 )
F_28 ( V_9 , V_9 -> V_26 ) ;
F_53 ( V_9 ) ;
V_9 -> V_10 -> V_107 -> V_127 ( V_9 -> V_10 ) ;
V_9 -> V_10 -> V_107 -> V_126 ( V_9 -> V_10 ) ;
}
static void F_90 ( struct V_63 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
F_84 ( & V_9 -> V_77 ) ;
F_91 ( & V_9 -> V_57 ) ;
V_9 -> V_58 = true ;
F_92 ( & V_9 -> V_57 ) ;
F_93 ( & V_9 -> V_65 ) ;
F_93 ( & V_9 -> V_60 ) ;
F_89 ( V_9 ) ;
#ifdef F_80
if ( V_9 -> V_22 . V_121 )
F_94 ( V_9 -> V_22 . V_121 ) ;
F_86 ( V_118 ) ;
#endif
F_88 ( V_9 ) ;
}
static int F_95 ( struct V_63 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
F_89 ( V_9 ) ;
return 0 ;
}
static int F_96 ( struct V_63 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
int V_128 ;
V_128 = F_60 ( V_10 -> V_11 ) ;
if ( V_128 )
return V_128 ;
F_87 ( V_10 ) ;
if ( F_50 ( V_9 ) )
F_47 ( V_10 ) ;
F_53 ( V_9 ) ;
return 0 ;
}
static int F_97 ( struct V_63 * V_10 )
{
F_98 ( V_10 , V_129 ) ;
return 0 ;
}
