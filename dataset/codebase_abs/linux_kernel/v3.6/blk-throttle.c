static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 ? F_2 ( V_3 , struct V_1 , V_3 ) : NULL ;
}
static inline struct V_1 * F_3 ( struct V_4 * V_5 )
{
return F_1 ( F_4 ( V_5 , & V_6 ) ) ;
}
static inline struct V_4 * F_5 ( struct V_1 * V_7 )
{
return F_6 ( & V_7 -> V_3 ) ;
}
static inline struct V_1 * F_7 ( struct V_8 * V_9 )
{
return F_3 ( V_9 -> V_10 -> V_11 ) ;
}
static inline unsigned int F_8 ( struct V_8 * V_9 )
{
return V_9 -> V_12 [ 0 ] + V_9 -> V_12 [ 1 ] ;
}
static void F_9 ( struct V_13 * V_14 )
{
static struct V_15 * V_16 ;
struct V_17 * V_18 = F_10 ( V_14 ) ;
bool V_19 = false ;
V_20:
if ( ! V_16 ) {
V_16 = F_11 ( struct V_15 ) ;
if ( ! V_16 ) {
F_12 ( V_21 , V_18 ,
F_13 ( 10 ) ) ;
return;
}
}
F_14 ( & V_22 ) ;
if ( ! F_15 ( & V_23 ) ) {
struct V_1 * V_7 = F_16 ( & V_23 ,
struct V_1 ,
V_24 ) ;
F_17 ( V_7 -> V_16 , V_16 ) ;
F_18 ( & V_7 -> V_24 ) ;
}
V_19 = F_15 ( & V_23 ) ;
F_19 ( & V_22 ) ;
if ( ! V_19 )
goto V_20;
}
static void F_20 ( struct V_4 * V_5 )
{
struct V_1 * V_7 = F_3 ( V_5 ) ;
unsigned long V_25 ;
F_21 ( & V_7 -> V_26 ) ;
F_22 ( & V_7 -> V_27 [ 0 ] ) ;
F_22 ( & V_7 -> V_27 [ 1 ] ) ;
V_7 -> V_28 = false ;
V_7 -> V_29 [ V_30 ] = - 1 ;
V_7 -> V_29 [ V_31 ] = - 1 ;
V_7 -> V_32 [ V_30 ] = - 1 ;
V_7 -> V_32 [ V_31 ] = - 1 ;
F_23 ( & V_22 , V_25 ) ;
F_24 ( & V_7 -> V_24 , & V_23 ) ;
F_12 ( V_21 , & V_33 , 0 ) ;
F_25 ( & V_22 , V_25 ) ;
}
static void F_26 ( struct V_4 * V_5 )
{
struct V_1 * V_7 = F_3 ( V_5 ) ;
unsigned long V_25 ;
F_23 ( & V_22 , V_25 ) ;
F_18 ( & V_7 -> V_24 ) ;
F_25 ( & V_22 , V_25 ) ;
F_27 ( V_7 -> V_16 ) ;
}
static void F_28 ( struct V_4 * V_5 )
{
struct V_1 * V_7 = F_3 ( V_5 ) ;
int V_34 ;
if ( V_7 -> V_16 == NULL )
return;
F_29 (cpu) {
struct V_15 * V_35 = F_30 ( V_7 -> V_16 , V_34 ) ;
F_31 ( & V_35 -> V_36 ) ;
F_31 ( & V_35 -> V_37 ) ;
}
}
static struct V_1 * F_32 ( struct V_8 * V_9 ,
struct V_38 * V_38 )
{
if ( V_38 == & V_39 )
return F_7 ( V_9 ) ;
return F_3 ( F_33 ( V_38 , V_9 -> V_10 ) ) ;
}
static struct V_1 * F_34 ( struct V_8 * V_9 ,
struct V_38 * V_38 )
{
struct V_40 * V_41 = V_9 -> V_10 ;
struct V_1 * V_7 = NULL ;
if ( V_38 == & V_39 ) {
V_7 = F_7 ( V_9 ) ;
} else {
struct V_4 * V_5 ;
V_5 = F_35 ( V_38 , V_41 ) ;
if ( ! F_36 ( V_5 ) )
V_7 = F_3 ( V_5 ) ;
else if ( ! F_37 ( V_41 ) )
V_7 = F_7 ( V_9 ) ;
}
return V_7 ;
}
static struct V_1 * F_38 ( struct V_42 * V_43 )
{
if ( ! V_43 -> V_44 )
return NULL ;
if ( ! V_43 -> V_45 )
V_43 -> V_45 = F_39 ( & V_43 -> V_46 ) ;
if ( V_43 -> V_45 )
return F_40 ( V_43 -> V_45 ) ;
return NULL ;
}
static void F_41 ( struct V_26 * V_47 , struct V_48 * V_43 )
{
F_42 ( V_47 , V_43 ) ;
F_21 ( V_47 ) ;
}
static void F_43 ( struct V_26 * V_47 , struct V_42 * V_43 )
{
if ( V_43 -> V_45 == V_47 )
V_43 -> V_45 = NULL ;
F_41 ( V_47 , & V_43 -> V_46 ) ;
-- V_43 -> V_44 ;
}
static void F_44 ( struct V_42 * V_49 )
{
struct V_1 * V_7 ;
V_7 = F_38 ( V_49 ) ;
if ( ! V_7 )
return;
V_49 -> V_50 = V_7 -> V_51 ;
}
static void
F_45 ( struct V_42 * V_49 , struct V_1 * V_7 )
{
struct V_26 * * V_52 = & V_49 -> V_46 . V_26 ;
struct V_26 * V_53 = NULL ;
struct V_1 * V_54 ;
unsigned long V_55 = V_7 -> V_51 ;
int V_45 = 1 ;
while ( * V_52 != NULL ) {
V_53 = * V_52 ;
V_54 = F_40 ( V_53 ) ;
if ( F_46 ( V_55 , V_54 -> V_51 ) )
V_52 = & V_53 -> V_56 ;
else {
V_52 = & V_53 -> V_57 ;
V_45 = 0 ;
}
}
if ( V_45 )
V_49 -> V_45 = & V_7 -> V_26 ;
F_47 ( & V_7 -> V_26 , V_53 , V_52 ) ;
F_48 ( & V_7 -> V_26 , & V_49 -> V_46 ) ;
}
static void F_49 ( struct V_8 * V_9 , struct V_1 * V_7 )
{
struct V_42 * V_49 = & V_9 -> V_58 ;
F_45 ( V_49 , V_7 ) ;
F_50 ( V_7 ) ;
V_49 -> V_44 ++ ;
}
static void F_51 ( struct V_8 * V_9 , struct V_1 * V_7 )
{
if ( ! F_52 ( V_7 ) )
F_49 ( V_9 , V_7 ) ;
}
static void F_53 ( struct V_8 * V_9 , struct V_1 * V_7 )
{
F_43 ( & V_7 -> V_26 , & V_9 -> V_58 ) ;
F_54 ( V_7 ) ;
}
static void F_55 ( struct V_8 * V_9 , struct V_1 * V_7 )
{
if ( F_52 ( V_7 ) )
F_53 ( V_9 , V_7 ) ;
}
static void F_56 ( struct V_8 * V_9 )
{
struct V_42 * V_49 = & V_9 -> V_58 ;
if ( ! F_8 ( V_9 ) )
return;
F_57 ( ! V_49 -> V_44 ) ;
F_44 ( V_49 ) ;
if ( F_58 ( V_49 -> V_50 , V_59 ) )
F_59 ( V_9 , 0 ) ;
else
F_59 ( V_9 , ( V_49 -> V_50 - V_59 ) ) ;
}
static inline void
F_60 ( struct V_8 * V_9 , struct V_1 * V_7 , bool V_60 )
{
V_7 -> V_61 [ V_60 ] = 0 ;
V_7 -> V_62 [ V_60 ] = 0 ;
V_7 -> V_63 [ V_60 ] = V_59 ;
V_7 -> V_64 [ V_60 ] = V_59 + V_65 ;
F_61 ( V_9 , V_7 , L_1 ,
V_60 == V_30 ? 'R' : 'W' , V_7 -> V_63 [ V_60 ] ,
V_7 -> V_64 [ V_60 ] , V_59 ) ;
}
static inline void F_62 ( struct V_8 * V_9 ,
struct V_1 * V_7 , bool V_60 , unsigned long V_66 )
{
V_7 -> V_64 [ V_60 ] = F_63 ( V_66 , V_65 ) ;
}
static inline void F_64 ( struct V_8 * V_9 ,
struct V_1 * V_7 , bool V_60 , unsigned long V_66 )
{
V_7 -> V_64 [ V_60 ] = F_63 ( V_66 , V_65 ) ;
F_61 ( V_9 , V_7 , L_2 ,
V_60 == V_30 ? 'R' : 'W' , V_7 -> V_63 [ V_60 ] ,
V_7 -> V_64 [ V_60 ] , V_59 ) ;
}
static bool
F_65 ( struct V_8 * V_9 , struct V_1 * V_7 , bool V_60 )
{
if ( F_66 ( V_59 , V_7 -> V_63 [ V_60 ] , V_7 -> V_64 [ V_60 ] ) )
return 0 ;
return 1 ;
}
static inline void
F_67 ( struct V_8 * V_9 , struct V_1 * V_7 , bool V_60 )
{
unsigned long V_67 , V_68 , V_69 ;
T_1 V_70 , V_71 ;
F_57 ( F_46 ( V_7 -> V_64 [ V_60 ] , V_7 -> V_63 [ V_60 ] ) ) ;
if ( F_65 ( V_9 , V_7 , V_60 ) )
return;
F_62 ( V_9 , V_7 , V_60 , V_59 + V_65 ) ;
V_68 = V_59 - V_7 -> V_63 [ V_60 ] ;
V_67 = V_68 / V_65 ;
if ( ! V_67 )
return;
V_71 = V_7 -> V_29 [ V_60 ] * V_65 * V_67 ;
F_68 ( V_71 , V_72 ) ;
V_70 = V_71 ;
V_69 = ( V_7 -> V_32 [ V_60 ] * V_65 * V_67 ) / V_72 ;
if ( ! V_70 && ! V_69 )
return;
if ( V_7 -> V_61 [ V_60 ] >= V_70 )
V_7 -> V_61 [ V_60 ] -= V_70 ;
else
V_7 -> V_61 [ V_60 ] = 0 ;
if ( V_7 -> V_62 [ V_60 ] >= V_69 )
V_7 -> V_62 [ V_60 ] -= V_69 ;
else
V_7 -> V_62 [ V_60 ] = 0 ;
V_7 -> V_63 [ V_60 ] += V_67 * V_65 ;
F_61 ( V_9 , V_7 , L_3
L_4 ,
V_60 == V_30 ? 'R' : 'W' , V_67 , V_70 , V_69 ,
V_7 -> V_63 [ V_60 ] , V_7 -> V_64 [ V_60 ] , V_59 ) ;
}
static bool F_69 ( struct V_8 * V_9 , struct V_1 * V_7 ,
struct V_73 * V_73 , unsigned long * V_74 )
{
bool V_60 = F_70 ( V_73 ) ;
unsigned int V_75 ;
unsigned long V_76 , V_77 , V_78 ;
T_1 V_71 ;
V_76 = V_78 = V_59 - V_7 -> V_63 [ V_60 ] ;
if ( ! V_76 )
V_78 = V_65 ;
V_78 = F_63 ( V_78 , V_65 ) ;
V_71 = ( T_1 ) V_7 -> V_32 [ V_60 ] * V_78 ;
F_68 ( V_71 , V_72 ) ;
if ( V_71 > V_79 )
V_75 = V_79 ;
else
V_75 = V_71 ;
if ( V_7 -> V_62 [ V_60 ] + 1 <= V_75 ) {
if ( V_74 )
* V_74 = 0 ;
return 1 ;
}
V_77 = ( ( V_7 -> V_62 [ V_60 ] + 1 ) * V_72 ) / V_7 -> V_32 [ V_60 ] + 1 ;
if ( V_77 > V_76 )
V_77 = V_77 - V_76 ;
else
V_77 = 1 ;
if ( V_74 )
* V_74 = V_77 ;
return 0 ;
}
static bool F_71 ( struct V_8 * V_9 , struct V_1 * V_7 ,
struct V_73 * V_73 , unsigned long * V_74 )
{
bool V_60 = F_70 ( V_73 ) ;
T_1 V_80 , V_81 , V_71 ;
unsigned long V_76 , V_77 , V_78 ;
V_76 = V_78 = V_59 - V_7 -> V_63 [ V_60 ] ;
if ( ! V_76 )
V_78 = V_65 ;
V_78 = F_63 ( V_78 , V_65 ) ;
V_71 = V_7 -> V_29 [ V_60 ] * V_78 ;
F_68 ( V_71 , V_72 ) ;
V_80 = V_71 ;
if ( V_7 -> V_61 [ V_60 ] + V_73 -> V_82 <= V_80 ) {
if ( V_74 )
* V_74 = 0 ;
return 1 ;
}
V_81 = V_7 -> V_61 [ V_60 ] + V_73 -> V_82 - V_80 ;
V_77 = F_72 ( V_81 * V_72 , V_7 -> V_29 [ V_60 ] ) ;
if ( ! V_77 )
V_77 = 1 ;
V_77 = V_77 + ( V_78 - V_76 ) ;
if ( V_74 )
* V_74 = V_77 ;
return 0 ;
}
static bool F_73 ( struct V_1 * V_7 , bool V_60 ) {
if ( V_7 -> V_29 [ V_60 ] == - 1 && V_7 -> V_32 [ V_60 ] == - 1 )
return 1 ;
return 0 ;
}
static bool F_74 ( struct V_8 * V_9 , struct V_1 * V_7 ,
struct V_73 * V_73 , unsigned long * V_74 )
{
bool V_60 = F_70 ( V_73 ) ;
unsigned long V_83 = 0 , V_84 = 0 , V_85 = 0 ;
F_57 ( V_7 -> V_12 [ V_60 ] && V_73 != F_75 ( & V_7 -> V_27 [ V_60 ] ) ) ;
if ( V_7 -> V_29 [ V_60 ] == - 1 && V_7 -> V_32 [ V_60 ] == - 1 ) {
if ( V_74 )
* V_74 = 0 ;
return 1 ;
}
if ( F_65 ( V_9 , V_7 , V_60 ) )
F_60 ( V_9 , V_7 , V_60 ) ;
else {
if ( F_46 ( V_7 -> V_64 [ V_60 ] , V_59 + V_65 ) )
F_64 ( V_9 , V_7 , V_60 , V_59 + V_65 ) ;
}
if ( F_71 ( V_9 , V_7 , V_73 , & V_83 )
&& F_69 ( V_9 , V_7 , V_73 , & V_84 ) ) {
if ( V_74 )
* V_74 = 0 ;
return 1 ;
}
V_85 = F_76 ( V_83 , V_84 ) ;
if ( V_74 )
* V_74 = V_85 ;
if ( F_46 ( V_7 -> V_64 [ V_60 ] , V_59 + V_85 ) )
F_64 ( V_9 , V_7 , V_60 , V_59 + V_85 ) ;
return 0 ;
}
static void F_77 ( struct V_4 * V_5 , T_1 V_86 ,
int V_60 )
{
struct V_1 * V_7 = F_3 ( V_5 ) ;
struct V_15 * V_16 ;
unsigned long V_25 ;
if ( V_7 -> V_16 == NULL )
return;
F_78 ( V_25 ) ;
V_16 = F_79 ( V_7 -> V_16 ) ;
F_80 ( & V_16 -> V_37 , V_60 , 1 ) ;
F_80 ( & V_16 -> V_36 , V_60 , V_86 ) ;
F_81 ( V_25 ) ;
}
static void F_82 ( struct V_1 * V_7 , struct V_73 * V_73 )
{
bool V_60 = F_70 ( V_73 ) ;
V_7 -> V_61 [ V_60 ] += V_73 -> V_82 ;
V_7 -> V_62 [ V_60 ] ++ ;
F_77 ( F_5 ( V_7 ) , V_73 -> V_82 , V_73 -> V_87 ) ;
}
static void F_83 ( struct V_8 * V_9 , struct V_1 * V_7 ,
struct V_73 * V_73 )
{
bool V_60 = F_70 ( V_73 ) ;
F_84 ( & V_7 -> V_27 [ V_60 ] , V_73 ) ;
F_85 ( F_5 ( V_7 ) ) ;
V_7 -> V_12 [ V_60 ] ++ ;
V_9 -> V_12 [ V_60 ] ++ ;
F_51 ( V_9 , V_7 ) ;
}
static void F_86 ( struct V_8 * V_9 , struct V_1 * V_7 )
{
unsigned long V_88 = - 1 , V_89 = - 1 , V_90 = - 1 , V_51 ;
struct V_73 * V_73 ;
if ( ( V_73 = F_75 ( & V_7 -> V_27 [ V_30 ] ) ) )
F_74 ( V_9 , V_7 , V_73 , & V_88 ) ;
if ( ( V_73 = F_75 ( & V_7 -> V_27 [ V_31 ] ) ) )
F_74 ( V_9 , V_7 , V_73 , & V_89 ) ;
V_90 = F_87 ( V_88 , V_89 ) ;
V_51 = V_59 + V_90 ;
F_55 ( V_9 , V_7 ) ;
V_7 -> V_51 = V_51 ;
F_51 ( V_9 , V_7 ) ;
}
static void F_88 ( struct V_8 * V_9 , struct V_1 * V_7 ,
bool V_60 , struct V_91 * V_92 )
{
struct V_73 * V_73 ;
V_73 = F_89 ( & V_7 -> V_27 [ V_60 ] ) ;
V_7 -> V_12 [ V_60 ] -- ;
F_90 ( F_5 ( V_7 ) ) ;
F_57 ( V_9 -> V_12 [ V_60 ] <= 0 ) ;
V_9 -> V_12 [ V_60 ] -- ;
F_82 ( V_7 , V_73 ) ;
F_84 ( V_92 , V_73 ) ;
V_73 -> V_87 |= V_93 ;
F_67 ( V_9 , V_7 , V_60 ) ;
}
static int F_91 ( struct V_8 * V_9 , struct V_1 * V_7 ,
struct V_91 * V_92 )
{
unsigned int V_94 = 0 , V_95 = 0 ;
unsigned int V_96 = V_97 * 3 / 4 ;
unsigned int V_98 = V_97 - V_96 ;
struct V_73 * V_73 ;
while ( ( V_73 = F_75 ( & V_7 -> V_27 [ V_30 ] ) )
&& F_74 ( V_9 , V_7 , V_73 , NULL ) ) {
F_88 ( V_9 , V_7 , F_70 ( V_73 ) , V_92 ) ;
V_94 ++ ;
if ( V_94 >= V_96 )
break;
}
while ( ( V_73 = F_75 ( & V_7 -> V_27 [ V_31 ] ) )
&& F_74 ( V_9 , V_7 , V_73 , NULL ) ) {
F_88 ( V_9 , V_7 , F_70 ( V_73 ) , V_92 ) ;
V_95 ++ ;
if ( V_95 >= V_98 )
break;
}
return V_94 + V_95 ;
}
static int F_92 ( struct V_8 * V_9 , struct V_91 * V_92 )
{
unsigned int V_99 = 0 ;
struct V_1 * V_7 ;
struct V_42 * V_49 = & V_9 -> V_58 ;
while ( 1 ) {
V_7 = F_38 ( V_49 ) ;
if ( ! V_7 )
break;
if ( F_46 ( V_59 , V_7 -> V_51 ) )
break;
F_55 ( V_9 , V_7 ) ;
V_99 += F_91 ( V_9 , V_7 , V_92 ) ;
if ( V_7 -> V_12 [ 0 ] || V_7 -> V_12 [ 1 ] ) {
F_86 ( V_9 , V_7 ) ;
F_51 ( V_9 , V_7 ) ;
}
if ( V_99 >= V_100 )
break;
}
return V_99 ;
}
static void F_93 ( struct V_8 * V_9 )
{
struct V_40 * V_41 = V_9 -> V_10 ;
struct V_4 * V_5 , * V_47 ;
if ( ! V_9 -> V_28 )
return;
F_94 ( & V_9 -> V_28 , false ) ;
F_95 ( V_9 , L_5 ) ;
F_96 (blkg, n, &q->blkg_list, q_node) {
struct V_1 * V_7 = F_3 ( V_5 ) ;
if ( ! V_7 -> V_28 )
continue;
if ( ! F_94 ( & V_7 -> V_28 , false ) )
continue;
F_61 ( V_9 , V_7 , L_6
L_7 , V_7 -> V_29 [ V_30 ] , V_7 -> V_29 [ V_31 ] ,
V_7 -> V_32 [ V_30 ] , V_7 -> V_32 [ V_31 ] ) ;
F_60 ( V_9 , V_7 , 0 ) ;
F_60 ( V_9 , V_7 , 1 ) ;
if ( F_52 ( V_7 ) )
F_86 ( V_9 , V_7 ) ;
}
}
static int F_97 ( struct V_40 * V_41 )
{
struct V_8 * V_9 = V_41 -> V_9 ;
unsigned int V_99 = 0 ;
struct V_91 V_101 ;
struct V_73 * V_73 ;
struct V_102 V_103 ;
F_14 ( V_41 -> V_104 ) ;
F_93 ( V_9 ) ;
if ( ! F_8 ( V_9 ) )
goto V_105;
F_22 ( & V_101 ) ;
F_95 ( V_9 , L_8 ,
F_8 ( V_9 ) , V_9 -> V_12 [ V_30 ] ,
V_9 -> V_12 [ V_31 ] ) ;
V_99 = F_92 ( V_9 , & V_101 ) ;
if ( V_99 )
F_95 ( V_9 , L_9 , V_99 ) ;
F_56 ( V_9 ) ;
V_105:
F_19 ( V_41 -> V_104 ) ;
if ( V_99 ) {
F_98 ( & V_103 ) ;
while( ( V_73 = F_89 ( & V_101 ) ) )
F_99 ( V_73 ) ;
F_100 ( & V_103 ) ;
}
return V_99 ;
}
void F_101 ( struct V_13 * V_14 )
{
struct V_8 * V_9 = F_2 ( V_14 , struct V_8 ,
V_106 . V_14 ) ;
struct V_40 * V_41 = V_9 -> V_10 ;
F_97 ( V_41 ) ;
}
static void
F_59 ( struct V_8 * V_9 , unsigned long V_107 )
{
struct V_17 * V_18 = & V_9 -> V_106 ;
if ( F_8 ( V_9 ) || V_9 -> V_28 ) {
F_102 ( V_18 ) ;
F_12 ( V_108 , V_18 , V_107 ) ;
F_95 ( V_9 , L_10 ,
V_107 , V_59 ) ;
}
}
static T_1 F_103 ( struct V_109 * V_110 ,
struct V_2 * V_3 , int V_111 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_112 V_113 = { } , V_71 ;
int V_114 , V_34 ;
F_29 (cpu) {
struct V_15 * V_35 = F_30 ( V_7 -> V_16 , V_34 ) ;
V_71 = F_104 ( ( void * ) V_35 + V_111 ) ;
for ( V_114 = 0 ; V_114 < V_115 ; V_114 ++ )
V_113 . V_116 [ V_114 ] += V_71 . V_116 [ V_114 ] ;
}
return F_105 ( V_110 , V_3 , & V_113 ) ;
}
static int F_106 ( struct V_117 * V_118 , struct V_119 * V_120 ,
struct V_109 * V_110 )
{
struct V_38 * V_38 = F_107 ( V_118 ) ;
F_108 ( V_110 , V_38 , F_103 , & V_6 ,
V_120 -> V_121 , true ) ;
return 0 ;
}
static T_1 F_109 ( struct V_109 * V_110 , struct V_2 * V_3 ,
int V_111 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_1 V_122 = * ( T_1 * ) ( ( void * ) V_7 + V_111 ) ;
if ( V_122 == - 1 )
return 0 ;
return F_110 ( V_110 , V_3 , V_122 ) ;
}
static T_1 F_111 ( struct V_109 * V_110 , struct V_2 * V_3 ,
int V_111 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned int V_122 = * ( unsigned int * ) ( ( void * ) V_7 + V_111 ) ;
if ( V_122 == - 1 )
return 0 ;
return F_110 ( V_110 , V_3 , V_122 ) ;
}
static int F_112 ( struct V_117 * V_118 , struct V_119 * V_120 ,
struct V_109 * V_110 )
{
F_108 ( V_110 , F_107 ( V_118 ) , F_109 ,
& V_6 , V_120 -> V_121 , false ) ;
return 0 ;
}
static int F_113 ( struct V_117 * V_118 , struct V_119 * V_120 ,
struct V_109 * V_110 )
{
F_108 ( V_110 , F_107 ( V_118 ) , F_111 ,
& V_6 , V_120 -> V_121 , false ) ;
return 0 ;
}
static int F_114 ( struct V_117 * V_118 , struct V_119 * V_120 , const char * V_123 ,
bool V_124 )
{
struct V_38 * V_38 = F_107 ( V_118 ) ;
struct V_125 V_126 ;
struct V_1 * V_7 ;
struct V_8 * V_9 ;
int V_127 ;
V_127 = F_115 ( V_38 , & V_6 , V_123 , & V_126 ) ;
if ( V_127 )
return V_127 ;
V_7 = F_3 ( V_126 . V_5 ) ;
V_9 = V_126 . V_5 -> V_41 -> V_9 ;
if ( ! V_126 . V_122 )
V_126 . V_122 = - 1 ;
if ( V_124 )
* ( T_1 * ) ( ( void * ) V_7 + V_120 -> V_121 ) = V_126 . V_122 ;
else
* ( unsigned int * ) ( ( void * ) V_7 + V_120 -> V_121 ) = V_126 . V_122 ;
F_94 ( & V_7 -> V_28 , true ) ;
F_94 ( & V_9 -> V_28 , true ) ;
F_59 ( V_9 , 0 ) ;
F_116 ( & V_126 ) ;
return 0 ;
}
static int F_117 ( struct V_117 * V_118 , struct V_119 * V_120 ,
const char * V_123 )
{
return F_114 ( V_118 , V_120 , V_123 , true ) ;
}
static int F_118 ( struct V_117 * V_118 , struct V_119 * V_120 ,
const char * V_123 )
{
return F_114 ( V_118 , V_120 , V_123 , false ) ;
}
static void F_119 ( struct V_40 * V_41 )
{
struct V_8 * V_9 = V_41 -> V_9 ;
F_120 ( & V_9 -> V_106 ) ;
}
bool F_121 ( struct V_40 * V_41 , struct V_73 * V_73 )
{
struct V_8 * V_9 = V_41 -> V_9 ;
struct V_1 * V_7 ;
bool V_60 = F_70 ( V_73 ) , V_128 = true ;
struct V_38 * V_38 ;
bool V_129 = false ;
if ( V_73 -> V_87 & V_93 ) {
V_73 -> V_87 &= ~ V_93 ;
goto V_105;
}
F_122 () ;
V_38 = F_123 ( V_73 ) ;
V_7 = F_32 ( V_9 , V_38 ) ;
if ( V_7 ) {
if ( F_73 ( V_7 , V_60 ) ) {
F_77 ( F_5 ( V_7 ) ,
V_73 -> V_82 , V_73 -> V_87 ) ;
goto V_130;
}
}
F_14 ( V_41 -> V_104 ) ;
V_7 = F_34 ( V_9 , V_38 ) ;
if ( F_124 ( ! V_7 ) )
goto V_131;
if ( V_7 -> V_12 [ V_60 ] ) {
V_128 = false ;
goto V_132;
}
if ( F_74 ( V_9 , V_7 , V_73 , NULL ) ) {
F_82 ( V_7 , V_73 ) ;
F_67 ( V_9 , V_7 , V_60 ) ;
goto V_131;
}
V_132:
F_61 ( V_9 , V_7 , L_11
L_12 ,
V_60 == V_30 ? 'R' : 'W' ,
V_7 -> V_61 [ V_60 ] , V_73 -> V_82 , V_7 -> V_29 [ V_60 ] ,
V_7 -> V_62 [ V_60 ] , V_7 -> V_32 [ V_60 ] ,
V_7 -> V_12 [ V_30 ] , V_7 -> V_12 [ V_31 ] ) ;
F_125 ( V_73 ) ;
F_83 ( V_41 -> V_9 , V_7 , V_73 ) ;
V_129 = true ;
if ( V_128 ) {
F_86 ( V_9 , V_7 ) ;
F_56 ( V_9 ) ;
}
V_131:
F_19 ( V_41 -> V_104 ) ;
V_130:
F_126 () ;
V_105:
return V_129 ;
}
void F_127 ( struct V_40 * V_41 )
__releases( V_41 -> V_104 ) __acquires( V_41 -> V_104 )
{
struct V_8 * V_9 = V_41 -> V_9 ;
struct V_42 * V_49 = & V_9 -> V_58 ;
struct V_1 * V_7 ;
struct V_91 V_92 ;
struct V_73 * V_73 ;
F_128 ( V_41 ) ;
F_22 ( & V_92 ) ;
while ( ( V_7 = F_38 ( V_49 ) ) ) {
F_55 ( V_9 , V_7 ) ;
while ( ( V_73 = F_75 ( & V_7 -> V_27 [ V_30 ] ) ) )
F_88 ( V_9 , V_7 , F_70 ( V_73 ) , & V_92 ) ;
while ( ( V_73 = F_75 ( & V_7 -> V_27 [ V_31 ] ) ) )
F_88 ( V_9 , V_7 , F_70 ( V_73 ) , & V_92 ) ;
}
F_19 ( V_41 -> V_104 ) ;
while ( ( V_73 = F_89 ( & V_92 ) ) )
F_99 ( V_73 ) ;
F_14 ( V_41 -> V_104 ) ;
}
int F_129 ( struct V_40 * V_41 )
{
struct V_8 * V_9 ;
int V_127 ;
V_9 = F_130 ( sizeof( * V_9 ) , V_133 , V_41 -> V_52 ) ;
if ( ! V_9 )
return - V_134 ;
V_9 -> V_58 = V_135 ;
V_9 -> V_28 = false ;
F_131 ( & V_9 -> V_106 , F_101 ) ;
V_41 -> V_9 = V_9 ;
V_9 -> V_10 = V_41 ;
V_127 = F_132 ( V_41 , & V_6 ) ;
if ( V_127 )
F_133 ( V_9 ) ;
return V_127 ;
}
void F_134 ( struct V_40 * V_41 )
{
F_57 ( ! V_41 -> V_9 ) ;
F_119 ( V_41 ) ;
F_135 ( V_41 , & V_6 ) ;
F_133 ( V_41 -> V_9 ) ;
}
static int T_2 F_136 ( void )
{
V_108 = F_137 ( L_13 , V_136 , 0 ) ;
if ( ! V_108 )
F_138 ( L_14 ) ;
return F_139 ( & V_6 ) ;
}
