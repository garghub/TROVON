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
static void F_35 ( struct V_8 * V_9 )
{
unsigned long V_36 [ V_37 ] ;
struct V_38 V_19 ;
int V_31 = 0 ;
long V_39 ;
F_36 ( V_36 ) ;
F_37 ( & V_19 ) ;
V_39 = F_38 () ;
F_32 ( V_9 , V_31 ++ , V_40 ,
F_39 ( V_36 [ V_41 ] ) ) ;
F_32 ( V_9 , V_31 ++ , V_42 ,
F_39 ( V_36 [ V_43 ] ) ) ;
F_32 ( V_9 , V_31 ++ , V_44 , V_36 [ V_45 ] ) ;
F_32 ( V_9 , V_31 ++ , V_46 , V_36 [ V_47 ] ) ;
F_32 ( V_9 , V_31 ++ , V_48 ,
F_39 ( V_19 . V_49 ) ) ;
F_32 ( V_9 , V_31 ++ , V_50 ,
F_39 ( V_19 . V_51 ) ) ;
F_32 ( V_9 , V_31 ++ , V_52 ,
F_39 ( V_39 ) ) ;
}
static void F_40 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 -> V_11 ;
F_41 ( & V_9 -> V_53 ) ;
if ( ! V_9 -> V_54 )
F_42 ( V_55 , & V_9 -> V_56 ) ;
F_43 ( & V_9 -> V_53 ) ;
}
static void F_44 ( struct V_8 * V_9 )
{
struct V_6 * V_7 ;
struct V_13 V_14 ;
unsigned int V_15 ;
F_35 ( V_9 ) ;
V_7 = V_9 -> V_57 ;
if ( ! F_14 ( V_7 , & V_15 ) )
return;
F_10 ( & V_14 , V_9 -> V_35 , sizeof( V_9 -> V_35 ) ) ;
F_11 ( V_7 , & V_14 , 1 , V_9 , V_18 ) ;
F_12 ( V_7 ) ;
}
static void F_45 ( struct V_58 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
unsigned long V_59 ;
F_46 ( & V_9 -> V_53 , V_59 ) ;
if ( ! V_9 -> V_54 )
F_42 ( V_55 , & V_9 -> V_60 ) ;
F_47 ( & V_9 -> V_53 , V_59 ) ;
}
static inline T_6 F_48 ( struct V_8 * V_9 )
{
T_6 V_61 ;
T_1 V_26 ;
F_49 ( V_9 -> V_10 , struct V_62 , V_26 ,
& V_26 ) ;
if ( ! F_24 ( V_9 -> V_10 , V_63 ) )
V_26 = F_50 ( ( V_64 V_65 ) V_26 ) ;
V_61 = V_26 ;
return V_61 - V_9 -> V_26 ;
}
static void F_51 ( struct V_8 * V_9 )
{
T_1 V_66 = V_9 -> V_26 ;
if ( ! F_24 ( V_9 -> V_10 , V_63 ) )
V_66 = ( V_64 T_1 ) F_52 ( V_66 ) ;
F_53 ( V_9 -> V_10 , struct V_62 , V_66 ,
& V_66 ) ;
}
static int F_54 ( struct V_67 * V_68 ,
unsigned long V_69 , void * V_70 )
{
struct V_8 * V_9 ;
unsigned long * V_71 ;
unsigned V_29 ;
V_9 = F_55 ( V_68 , struct V_8 , V_72 ) ;
if ( ! F_24 ( V_9 -> V_10 , V_27 ) )
return V_73 ;
V_71 = V_70 ;
V_29 = F_30 ( V_9 , V_74 ) ;
F_51 ( V_9 ) ;
* V_71 += V_29 ;
return V_73 ;
}
static void F_56 ( struct V_75 * V_76 )
{
struct V_8 * V_9 ;
V_9 = F_55 ( V_76 , struct V_8 ,
V_56 ) ;
F_44 ( V_9 ) ;
}
static void F_57 ( struct V_75 * V_76 )
{
struct V_8 * V_9 ;
T_6 V_77 ;
V_9 = F_55 ( V_76 , struct V_8 ,
V_60 ) ;
V_77 = F_48 ( V_9 ) ;
if ( V_77 > 0 )
V_77 -= F_17 ( V_9 , V_77 ) ;
else if ( V_77 < 0 )
V_77 += F_30 ( V_9 , - V_77 ) ;
F_51 ( V_9 ) ;
if ( V_77 )
F_42 ( V_55 , V_76 ) ;
}
static int F_58 ( struct V_8 * V_9 )
{
struct V_6 * V_78 [ 3 ] ;
T_7 * V_79 [] = { F_7 , F_7 , F_40 } ;
static const char * const V_80 [] = { L_2 , L_3 , L_4 } ;
int V_81 , V_82 ;
V_82 = F_24 ( V_9 -> V_10 , V_83 ) ? 3 : 2 ;
V_81 = V_9 -> V_10 -> V_84 -> V_85 ( V_9 -> V_10 , V_82 , V_78 , V_79 , V_80 ) ;
if ( V_81 )
return V_81 ;
V_9 -> V_28 = V_78 [ 0 ] ;
V_9 -> V_30 = V_78 [ 1 ] ;
if ( F_24 ( V_9 -> V_10 , V_83 ) ) {
struct V_13 V_14 ;
V_9 -> V_57 = V_78 [ 2 ] ;
F_10 ( & V_14 , V_9 -> V_35 , sizeof V_9 -> V_35 ) ;
if ( F_11 ( V_9 -> V_57 , & V_14 , 1 , V_9 , V_18 )
< 0 )
F_59 () ;
F_12 ( V_9 -> V_57 ) ;
}
return 0 ;
}
static int F_60 ( struct V_21 * V_22 ,
struct V_1 * V_86 , struct V_1 * V_1 , enum V_87 V_88 )
{
struct V_8 * V_9 = F_55 ( V_22 ,
struct V_8 , V_22 ) ;
unsigned long V_59 ;
if ( ! F_61 ( & V_9 -> V_24 ) )
return - V_89 ;
F_62 ( V_86 ) ;
F_46 ( & V_22 -> V_90 , V_59 ) ;
F_63 ( V_22 , V_86 ) ;
V_22 -> V_91 -- ;
F_64 ( V_92 ) ;
F_47 ( & V_22 -> V_90 , V_59 ) ;
V_9 -> V_17 = V_5 ;
F_15 ( V_9 , V_9 -> V_16 , V_86 ) ;
F_9 ( V_9 , V_9 -> V_28 ) ;
F_65 ( V_1 ) ;
V_9 -> V_17 = V_5 ;
F_15 ( V_9 , V_9 -> V_16 , V_1 ) ;
F_9 ( V_9 , V_9 -> V_30 ) ;
F_26 ( & V_9 -> V_24 ) ;
F_29 ( V_1 ) ;
return V_93 ;
}
static struct V_94 * F_66 ( struct V_95 * V_96 ,
int V_59 , const char * V_97 , void * V_98 )
{
static const struct V_99 V_100 = {
. V_101 = V_102 ,
} ;
return F_67 ( V_96 , L_5 , NULL , & V_100 ,
V_103 ) ;
}
static int F_68 ( struct V_58 * V_10 )
{
struct V_8 * V_9 ;
int V_81 ;
if ( ! V_10 -> V_84 -> V_104 ) {
F_69 ( & V_10 -> V_25 , L_6 ,
V_105 ) ;
return - V_106 ;
}
V_10 -> V_11 = V_9 = F_70 ( sizeof( * V_9 ) , V_18 ) ;
if ( ! V_9 ) {
V_81 = - V_107 ;
goto V_108;
}
F_71 ( & V_9 -> V_56 , F_56 ) ;
F_71 ( & V_9 -> V_60 , F_57 ) ;
F_72 ( & V_9 -> V_53 ) ;
V_9 -> V_54 = false ;
V_9 -> V_26 = 0 ;
F_73 ( & V_9 -> V_24 ) ;
F_74 ( & V_9 -> V_12 ) ;
V_9 -> V_10 = V_10 ;
F_75 ( & V_9 -> V_22 ) ;
V_81 = F_58 ( V_9 ) ;
if ( V_81 )
goto V_109;
V_9 -> V_72 . V_110 = F_54 ;
V_9 -> V_72 . V_111 = V_112 ;
V_81 = F_76 ( & V_9 -> V_72 ) ;
if ( V_81 < 0 )
goto V_113;
#ifdef F_77
V_114 = F_78 ( & V_115 ) ;
if ( F_79 ( V_114 ) ) {
V_81 = F_80 ( V_114 ) ;
F_81 ( & V_9 -> V_72 ) ;
goto V_113;
}
V_9 -> V_22 . V_116 = F_60 ;
V_9 -> V_22 . V_117 = F_82 ( V_114 -> V_118 ) ;
if ( F_79 ( V_9 -> V_22 . V_117 ) ) {
V_81 = F_80 ( V_9 -> V_22 . V_117 ) ;
F_83 ( V_114 ) ;
F_81 ( & V_9 -> V_72 ) ;
V_9 -> V_22 . V_117 = NULL ;
goto V_113;
}
V_9 -> V_22 . V_117 -> V_119 -> V_120 = & V_121 ;
#endif
F_84 ( V_10 ) ;
return 0 ;
V_113:
V_10 -> V_84 -> V_122 ( V_10 ) ;
V_109:
F_85 ( V_9 ) ;
V_108:
return V_81 ;
}
static void F_86 ( struct V_8 * V_9 )
{
while ( V_9 -> V_26 )
F_30 ( V_9 , V_9 -> V_26 ) ;
F_51 ( V_9 ) ;
V_9 -> V_10 -> V_84 -> V_123 ( V_9 -> V_10 ) ;
V_9 -> V_10 -> V_84 -> V_122 ( V_9 -> V_10 ) ;
}
static void F_87 ( struct V_58 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
F_81 ( & V_9 -> V_72 ) ;
F_88 ( & V_9 -> V_53 ) ;
V_9 -> V_54 = true ;
F_89 ( & V_9 -> V_53 ) ;
F_90 ( & V_9 -> V_60 ) ;
F_90 ( & V_9 -> V_56 ) ;
F_86 ( V_9 ) ;
if ( V_9 -> V_22 . V_117 )
F_91 ( V_9 -> V_22 . V_117 ) ;
F_85 ( V_9 ) ;
}
static int F_92 ( struct V_58 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
F_86 ( V_9 ) ;
return 0 ;
}
static int F_93 ( struct V_58 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_11 ;
int V_124 ;
V_124 = F_58 ( V_10 -> V_11 ) ;
if ( V_124 )
return V_124 ;
F_84 ( V_10 ) ;
if ( F_48 ( V_9 ) )
F_45 ( V_10 ) ;
F_51 ( V_9 ) ;
return 0 ;
}
