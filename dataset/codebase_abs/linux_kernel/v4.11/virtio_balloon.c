static T_1 F_1 ( struct V_1 * V_1 )
{
unsigned long V_2 = F_2 ( V_1 ) ;
F_3 ( V_3 < V_4 ) ;
return V_2 * V_5 ;
}
static struct V_1 * F_4 ( T_1 V_2 )
{
F_5 ( V_2 % V_5 ) ;
return F_6 ( V_2 / V_5 ) ;
}
static void F_7 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 -> V_11 ;
F_8 ( & V_9 -> V_12 ) ;
}
static void F_9 ( struct V_8 * V_9 , struct V_6 * V_7 )
{
struct V_13 V_14 ;
unsigned int V_15 ;
F_10 ( & V_14 , V_9 -> V_16 , sizeof( V_9 -> V_16 [ 0 ] ) * V_9 -> V_17 ) ;
F_11 ( V_7 , & V_14 , 1 , V_9 , V_18 ) ;
F_12 ( V_7 ) ;
F_13 ( V_9 -> V_12 , F_14 ( V_7 , & V_15 ) ) ;
}
static void F_15 ( struct V_8 * V_9 ,
T_2 V_16 [] , struct V_1 * V_1 )
{
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_5 ; V_19 ++ )
V_16 [ V_19 ] = F_16 ( V_9 -> V_10 ,
F_1 ( V_1 ) + V_19 ) ;
}
static unsigned F_17 ( struct V_8 * V_9 , T_3 V_20 )
{
struct V_21 * V_22 = & V_9 -> V_22 ;
unsigned V_23 ;
V_20 = F_18 ( V_20 , F_19 ( V_9 -> V_16 ) ) ;
F_20 ( & V_9 -> V_24 ) ;
for ( V_9 -> V_17 = 0 ; V_9 -> V_17 < V_20 ;
V_9 -> V_17 += V_5 ) {
struct V_1 * V_1 = F_21 ( V_22 ) ;
if ( ! V_1 ) {
F_22 ( & V_9 -> V_10 -> V_25 ,
L_1 ,
V_5 ) ;
F_23 ( 200 ) ;
break;
}
F_15 ( V_9 , V_9 -> V_16 + V_9 -> V_17 , V_1 ) ;
V_9 -> V_26 += V_5 ;
if ( ! F_24 ( V_9 -> V_10 ,
V_27 ) )
F_25 ( V_1 , - 1 ) ;
}
V_23 = V_9 -> V_17 ;
if ( V_9 -> V_17 != 0 )
F_9 ( V_9 , V_9 -> V_28 ) ;
F_26 ( & V_9 -> V_24 ) ;
return V_23 ;
}
static void F_27 ( struct V_8 * V_9 )
{
unsigned int V_19 ;
struct V_1 * V_1 ;
for ( V_19 = 0 ; V_19 < V_9 -> V_17 ; V_19 += V_5 ) {
V_1 = F_4 ( F_28 ( V_9 -> V_10 ,
V_9 -> V_16 [ V_19 ] ) ) ;
if ( ! F_24 ( V_9 -> V_10 ,
V_27 ) )
F_25 ( V_1 , 1 ) ;
F_29 ( V_1 ) ;
}
}
static unsigned F_30 ( struct V_8 * V_9 , T_3 V_20 )
{
unsigned V_29 ;
struct V_1 * V_1 ;
struct V_21 * V_22 = & V_9 -> V_22 ;
V_20 = F_18 ( V_20 , F_19 ( V_9 -> V_16 ) ) ;
F_20 ( & V_9 -> V_24 ) ;
V_20 = F_18 ( V_20 , ( T_3 ) V_9 -> V_26 ) ;
for ( V_9 -> V_17 = 0 ; V_9 -> V_17 < V_20 ;
V_9 -> V_17 += V_5 ) {
V_1 = F_31 ( V_22 ) ;
if ( ! V_1 )
break;
F_15 ( V_9 , V_9 -> V_16 + V_9 -> V_17 , V_1 ) ;
V_9 -> V_26 -= V_5 ;
}
V_29 = V_9 -> V_17 ;
if ( V_9 -> V_17 != 0 )
F_9 ( V_9 , V_9 -> V_30 ) ;
F_27 ( V_9 ) ;
F_26 ( & V_9 -> V_24 ) ;
return V_29 ;
}
static inline void F_32 ( struct V_8 * V_9 , int V_31 ,
T_4 V_32 , T_5 V_33 )
{
F_5 ( V_31 >= V_34 ) ;
V_9 -> V_35 [ V_31 ] . V_32 = F_33 ( V_9 -> V_10 , V_32 ) ;
V_9 -> V_35 [ V_31 ] . V_33 = F_34 ( V_9 -> V_10 , V_33 ) ;
}
static unsigned int F_35 ( struct V_8 * V_9 )
{
unsigned long V_36 [ V_37 ] ;
struct V_38 V_19 ;
unsigned int V_31 = 0 ;
long V_39 ;
F_36 ( V_36 ) ;
F_37 ( & V_19 ) ;
V_39 = F_38 () ;
#ifdef F_39
F_32 ( V_9 , V_31 ++ , V_40 ,
F_40 ( V_36 [ V_41 ] ) ) ;
F_32 ( V_9 , V_31 ++ , V_42 ,
F_40 ( V_36 [ V_43 ] ) ) ;
F_32 ( V_9 , V_31 ++ , V_44 , V_36 [ V_45 ] ) ;
F_32 ( V_9 , V_31 ++ , V_46 , V_36 [ V_47 ] ) ;
#endif
F_32 ( V_9 , V_31 ++ , V_48 ,
F_40 ( V_19 . V_49 ) ) ;
F_32 ( V_9 , V_31 ++ , V_50 ,
F_40 ( V_19 . V_51 ) ) ;
F_32 ( V_9 , V_31 ++ , V_52 ,
F_40 ( V_39 ) ) ;
return V_31 ;
}
static void F_41 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 -> V_11 ;
F_42 ( & V_9 -> V_53 ) ;
if ( ! V_9 -> V_54 )
F_43 ( V_55 , & V_9 -> V_56 ) ;
F_44 ( & V_9 -> V_53 ) ;
}
static void F_45 ( struct V_8 * V_9 )
{
struct V_6 * V_7 ;
struct V_13 V_14 ;
unsigned int V_15 , V_57 ;
V_57 = F_35 ( V_9 ) ;
V_7 = V_9 -> V_58 ;
if ( ! F_14 ( V_7 , & V_15 ) )
return;
F_10 ( & V_14 , V_9 -> V_35 , sizeof( V_9 -> V_35 [ 0 ] ) * V_57 ) ;
F_11 ( V_7 , & V_14 , 1 , V_9 , V_18 ) ;
F_12 ( V_7 ) ;
}
static void F_46 ( struct V_59 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
unsigned long V_60 ;
F_47 ( & V_9 -> V_53 , V_60 ) ;
if ( ! V_9 -> V_54 )
F_43 ( V_55 , & V_9 -> V_61 ) ;
F_48 ( & V_9 -> V_53 , V_60 ) ;
}
static inline T_6 F_49 ( struct V_8 * V_9 )
{
T_6 V_62 ;
T_1 V_26 ;
F_50 ( V_9 -> V_10 , struct V_63 , V_26 ,
& V_26 ) ;
if ( ! F_24 ( V_9 -> V_10 , V_64 ) )
V_26 = F_51 ( ( V_65 V_66 ) V_26 ) ;
V_62 = V_26 ;
return V_62 - V_9 -> V_26 ;
}
static void F_52 ( struct V_8 * V_9 )
{
T_1 V_67 = V_9 -> V_26 ;
if ( ! F_24 ( V_9 -> V_10 , V_64 ) )
V_67 = ( V_65 T_1 ) F_53 ( V_67 ) ;
F_54 ( V_9 -> V_10 , struct V_63 , V_67 ,
& V_67 ) ;
}
static int F_55 ( struct V_68 * V_69 ,
unsigned long V_70 , void * V_71 )
{
struct V_8 * V_9 ;
unsigned long * V_72 ;
unsigned V_29 ;
V_9 = F_56 ( V_69 , struct V_8 , V_73 ) ;
if ( ! F_24 ( V_9 -> V_10 , V_27 ) )
return V_74 ;
V_72 = V_71 ;
V_29 = F_30 ( V_9 , V_75 ) ;
F_52 ( V_9 ) ;
* V_72 += V_29 ;
return V_74 ;
}
static void F_57 ( struct V_76 * V_77 )
{
struct V_8 * V_9 ;
V_9 = F_56 ( V_77 , struct V_8 ,
V_56 ) ;
F_45 ( V_9 ) ;
}
static void F_58 ( struct V_76 * V_77 )
{
struct V_8 * V_9 ;
T_6 V_78 ;
V_9 = F_56 ( V_77 , struct V_8 ,
V_61 ) ;
V_78 = F_49 ( V_9 ) ;
if ( V_78 > 0 )
V_78 -= F_17 ( V_9 , V_78 ) ;
else if ( V_78 < 0 )
V_78 += F_30 ( V_9 , - V_78 ) ;
F_52 ( V_9 ) ;
if ( V_78 )
F_43 ( V_55 , V_77 ) ;
}
static int F_59 ( struct V_8 * V_9 )
{
struct V_6 * V_79 [ 3 ] ;
T_7 * V_80 [] = { F_7 , F_7 , F_41 } ;
static const char * const V_81 [] = { L_2 , L_3 , L_4 } ;
int V_82 , V_83 ;
V_83 = F_24 ( V_9 -> V_10 , V_84 ) ? 3 : 2 ;
V_82 = V_9 -> V_10 -> V_85 -> V_86 ( V_9 -> V_10 , V_83 , V_79 , V_80 , V_81 ,
NULL ) ;
if ( V_82 )
return V_82 ;
V_9 -> V_28 = V_79 [ 0 ] ;
V_9 -> V_30 = V_79 [ 1 ] ;
if ( F_24 ( V_9 -> V_10 , V_84 ) ) {
struct V_13 V_14 ;
unsigned int V_57 ;
V_9 -> V_58 = V_79 [ 2 ] ;
V_57 = F_35 ( V_9 ) ;
F_10 ( & V_14 , V_9 -> V_35 , sizeof( V_9 -> V_35 [ 0 ] ) * V_57 ) ;
if ( F_11 ( V_9 -> V_58 , & V_14 , 1 , V_9 , V_18 )
< 0 )
F_60 () ;
F_12 ( V_9 -> V_58 ) ;
}
return 0 ;
}
static int F_61 ( struct V_21 * V_22 ,
struct V_1 * V_87 , struct V_1 * V_1 , enum V_88 V_89 )
{
struct V_8 * V_9 = F_56 ( V_22 ,
struct V_8 , V_22 ) ;
unsigned long V_60 ;
if ( ! F_62 ( & V_9 -> V_24 ) )
return - V_90 ;
F_63 ( V_87 ) ;
F_47 ( & V_22 -> V_91 , V_60 ) ;
F_64 ( V_22 , V_87 ) ;
V_22 -> V_92 -- ;
F_65 ( V_93 ) ;
F_48 ( & V_22 -> V_91 , V_60 ) ;
V_9 -> V_17 = V_5 ;
F_15 ( V_9 , V_9 -> V_16 , V_87 ) ;
F_9 ( V_9 , V_9 -> V_28 ) ;
F_66 ( V_1 ) ;
V_9 -> V_17 = V_5 ;
F_15 ( V_9 , V_9 -> V_16 , V_1 ) ;
F_9 ( V_9 , V_9 -> V_30 ) ;
F_26 ( & V_9 -> V_24 ) ;
F_29 ( V_1 ) ;
return V_94 ;
}
static struct V_95 * F_67 ( struct V_96 * V_97 ,
int V_60 , const char * V_98 , void * V_99 )
{
static const struct V_100 V_101 = {
. V_102 = V_103 ,
} ;
return F_68 ( V_97 , L_5 , NULL , & V_101 ,
V_104 ) ;
}
static int F_69 ( struct V_59 * V_10 )
{
struct V_8 * V_9 ;
int V_82 ;
if ( ! V_10 -> V_85 -> V_105 ) {
F_70 ( & V_10 -> V_25 , L_6 ,
V_106 ) ;
return - V_107 ;
}
V_10 -> V_11 = V_9 = F_71 ( sizeof( * V_9 ) , V_18 ) ;
if ( ! V_9 ) {
V_82 = - V_108 ;
goto V_109;
}
F_72 ( & V_9 -> V_56 , F_57 ) ;
F_72 ( & V_9 -> V_61 , F_58 ) ;
F_73 ( & V_9 -> V_53 ) ;
V_9 -> V_54 = false ;
V_9 -> V_26 = 0 ;
F_74 ( & V_9 -> V_24 ) ;
F_75 ( & V_9 -> V_12 ) ;
V_9 -> V_10 = V_10 ;
F_76 ( & V_9 -> V_22 ) ;
V_82 = F_59 ( V_9 ) ;
if ( V_82 )
goto V_110;
V_9 -> V_73 . V_111 = F_55 ;
V_9 -> V_73 . V_112 = V_113 ;
V_82 = F_77 ( & V_9 -> V_73 ) ;
if ( V_82 < 0 )
goto V_114;
#ifdef F_78
V_115 = F_79 ( & V_116 ) ;
if ( F_80 ( V_115 ) ) {
V_82 = F_81 ( V_115 ) ;
F_82 ( & V_9 -> V_73 ) ;
goto V_114;
}
V_9 -> V_22 . V_117 = F_61 ;
V_9 -> V_22 . V_118 = F_83 ( V_115 -> V_119 ) ;
if ( F_80 ( V_9 -> V_22 . V_118 ) ) {
V_82 = F_81 ( V_9 -> V_22 . V_118 ) ;
F_84 ( V_115 ) ;
F_82 ( & V_9 -> V_73 ) ;
V_9 -> V_22 . V_118 = NULL ;
goto V_114;
}
V_9 -> V_22 . V_118 -> V_120 -> V_121 = & V_122 ;
#endif
F_85 ( V_10 ) ;
if ( F_49 ( V_9 ) )
F_46 ( V_10 ) ;
return 0 ;
V_114:
V_10 -> V_85 -> V_123 ( V_10 ) ;
V_110:
F_86 ( V_9 ) ;
V_109:
return V_82 ;
}
static void F_87 ( struct V_8 * V_9 )
{
while ( V_9 -> V_26 )
F_30 ( V_9 , V_9 -> V_26 ) ;
F_52 ( V_9 ) ;
V_9 -> V_10 -> V_85 -> V_124 ( V_9 -> V_10 ) ;
V_9 -> V_10 -> V_85 -> V_123 ( V_9 -> V_10 ) ;
}
static void F_88 ( struct V_59 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
F_82 ( & V_9 -> V_73 ) ;
F_89 ( & V_9 -> V_53 ) ;
V_9 -> V_54 = true ;
F_90 ( & V_9 -> V_53 ) ;
F_91 ( & V_9 -> V_61 ) ;
F_91 ( & V_9 -> V_56 ) ;
F_87 ( V_9 ) ;
#ifdef F_78
if ( V_9 -> V_22 . V_118 )
F_92 ( V_9 -> V_22 . V_118 ) ;
F_84 ( V_115 ) ;
#endif
F_86 ( V_9 ) ;
}
static int F_93 ( struct V_59 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
F_87 ( V_9 ) ;
return 0 ;
}
static int F_94 ( struct V_59 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
int V_125 ;
V_125 = F_59 ( V_10 -> V_11 ) ;
if ( V_125 )
return V_125 ;
F_85 ( V_10 ) ;
if ( F_49 ( V_9 ) )
F_46 ( V_10 ) ;
F_52 ( V_9 ) ;
return 0 ;
}
