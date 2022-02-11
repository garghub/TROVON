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
F_12 ( V_18 , F_13 ( 10 ) ) ;
return;
}
}
F_14 ( & V_21 ) ;
if ( ! F_15 ( & V_22 ) ) {
struct V_1 * V_7 = F_16 ( & V_22 ,
struct V_1 ,
V_23 ) ;
F_17 ( V_7 -> V_16 , V_16 ) ;
F_18 ( & V_7 -> V_23 ) ;
}
V_19 = F_15 ( & V_22 ) ;
F_19 ( & V_21 ) ;
if ( ! V_19 )
goto V_20;
}
static void F_20 ( struct V_4 * V_5 )
{
struct V_1 * V_7 = F_3 ( V_5 ) ;
unsigned long V_24 ;
F_21 ( & V_7 -> V_25 ) ;
F_22 ( & V_7 -> V_26 [ 0 ] ) ;
F_22 ( & V_7 -> V_26 [ 1 ] ) ;
V_7 -> V_27 = false ;
V_7 -> V_28 [ V_29 ] = - 1 ;
V_7 -> V_28 [ V_30 ] = - 1 ;
V_7 -> V_31 [ V_29 ] = - 1 ;
V_7 -> V_31 [ V_30 ] = - 1 ;
F_23 ( & V_21 , V_24 ) ;
F_24 ( & V_7 -> V_23 , & V_22 ) ;
F_12 ( & V_32 , 0 ) ;
F_25 ( & V_21 , V_24 ) ;
}
static void F_26 ( struct V_4 * V_5 )
{
struct V_1 * V_7 = F_3 ( V_5 ) ;
unsigned long V_24 ;
F_23 ( & V_21 , V_24 ) ;
F_18 ( & V_7 -> V_23 ) ;
F_25 ( & V_21 , V_24 ) ;
F_27 ( V_7 -> V_16 ) ;
}
static void F_28 ( struct V_4 * V_5 )
{
struct V_1 * V_7 = F_3 ( V_5 ) ;
int V_33 ;
if ( V_7 -> V_16 == NULL )
return;
F_29 (cpu) {
struct V_15 * V_34 = F_30 ( V_7 -> V_16 , V_33 ) ;
F_31 ( & V_34 -> V_35 ) ;
F_31 ( & V_34 -> V_36 ) ;
}
}
static struct V_1 * F_32 ( struct V_8 * V_9 ,
struct V_37 * V_37 )
{
if ( V_37 == & V_38 )
return F_7 ( V_9 ) ;
return F_3 ( F_33 ( V_37 , V_9 -> V_10 ) ) ;
}
static struct V_1 * F_34 ( struct V_8 * V_9 ,
struct V_37 * V_37 )
{
struct V_39 * V_40 = V_9 -> V_10 ;
struct V_1 * V_7 = NULL ;
if ( V_37 == & V_38 ) {
V_7 = F_7 ( V_9 ) ;
} else {
struct V_4 * V_5 ;
V_5 = F_35 ( V_37 , V_40 ) ;
if ( ! F_36 ( V_5 ) )
V_7 = F_3 ( V_5 ) ;
else if ( ! F_37 ( V_40 ) )
V_7 = F_7 ( V_9 ) ;
}
return V_7 ;
}
static struct V_1 * F_38 ( struct V_41 * V_42 )
{
if ( ! V_42 -> V_43 )
return NULL ;
if ( ! V_42 -> V_44 )
V_42 -> V_44 = F_39 ( & V_42 -> V_45 ) ;
if ( V_42 -> V_44 )
return F_40 ( V_42 -> V_44 ) ;
return NULL ;
}
static void F_41 ( struct V_25 * V_46 , struct V_47 * V_42 )
{
F_42 ( V_46 , V_42 ) ;
F_21 ( V_46 ) ;
}
static void F_43 ( struct V_25 * V_46 , struct V_41 * V_42 )
{
if ( V_42 -> V_44 == V_46 )
V_42 -> V_44 = NULL ;
F_41 ( V_46 , & V_42 -> V_45 ) ;
-- V_42 -> V_43 ;
}
static void F_44 ( struct V_41 * V_48 )
{
struct V_1 * V_7 ;
V_7 = F_38 ( V_48 ) ;
if ( ! V_7 )
return;
V_48 -> V_49 = V_7 -> V_50 ;
}
static void
F_45 ( struct V_41 * V_48 , struct V_1 * V_7 )
{
struct V_25 * * V_51 = & V_48 -> V_45 . V_25 ;
struct V_25 * V_52 = NULL ;
struct V_1 * V_53 ;
unsigned long V_54 = V_7 -> V_50 ;
int V_44 = 1 ;
while ( * V_51 != NULL ) {
V_52 = * V_51 ;
V_53 = F_40 ( V_52 ) ;
if ( F_46 ( V_54 , V_53 -> V_50 ) )
V_51 = & V_52 -> V_55 ;
else {
V_51 = & V_52 -> V_56 ;
V_44 = 0 ;
}
}
if ( V_44 )
V_48 -> V_44 = & V_7 -> V_25 ;
F_47 ( & V_7 -> V_25 , V_52 , V_51 ) ;
F_48 ( & V_7 -> V_25 , & V_48 -> V_45 ) ;
}
static void F_49 ( struct V_8 * V_9 , struct V_1 * V_7 )
{
struct V_41 * V_48 = & V_9 -> V_57 ;
F_45 ( V_48 , V_7 ) ;
F_50 ( V_7 ) ;
V_48 -> V_43 ++ ;
}
static void F_51 ( struct V_8 * V_9 , struct V_1 * V_7 )
{
if ( ! F_52 ( V_7 ) )
F_49 ( V_9 , V_7 ) ;
}
static void F_53 ( struct V_8 * V_9 , struct V_1 * V_7 )
{
F_43 ( & V_7 -> V_25 , & V_9 -> V_57 ) ;
F_54 ( V_7 ) ;
}
static void F_55 ( struct V_8 * V_9 , struct V_1 * V_7 )
{
if ( F_52 ( V_7 ) )
F_53 ( V_9 , V_7 ) ;
}
static void F_56 ( struct V_8 * V_9 )
{
struct V_41 * V_48 = & V_9 -> V_57 ;
if ( ! F_8 ( V_9 ) )
return;
F_57 ( ! V_48 -> V_43 ) ;
F_44 ( V_48 ) ;
if ( F_58 ( V_48 -> V_49 , V_58 ) )
F_59 ( V_9 , 0 ) ;
else
F_59 ( V_9 , ( V_48 -> V_49 - V_58 ) ) ;
}
static inline void
F_60 ( struct V_8 * V_9 , struct V_1 * V_7 , bool V_59 )
{
V_7 -> V_60 [ V_59 ] = 0 ;
V_7 -> V_61 [ V_59 ] = 0 ;
V_7 -> V_62 [ V_59 ] = V_58 ;
V_7 -> V_63 [ V_59 ] = V_58 + V_64 ;
F_61 ( V_9 , V_7 , L_1 ,
V_59 == V_29 ? 'R' : 'W' , V_7 -> V_62 [ V_59 ] ,
V_7 -> V_63 [ V_59 ] , V_58 ) ;
}
static inline void F_62 ( struct V_8 * V_9 ,
struct V_1 * V_7 , bool V_59 , unsigned long V_65 )
{
V_7 -> V_63 [ V_59 ] = F_63 ( V_65 , V_64 ) ;
}
static inline void F_64 ( struct V_8 * V_9 ,
struct V_1 * V_7 , bool V_59 , unsigned long V_65 )
{
V_7 -> V_63 [ V_59 ] = F_63 ( V_65 , V_64 ) ;
F_61 ( V_9 , V_7 , L_2 ,
V_59 == V_29 ? 'R' : 'W' , V_7 -> V_62 [ V_59 ] ,
V_7 -> V_63 [ V_59 ] , V_58 ) ;
}
static bool
F_65 ( struct V_8 * V_9 , struct V_1 * V_7 , bool V_59 )
{
if ( F_66 ( V_58 , V_7 -> V_62 [ V_59 ] , V_7 -> V_63 [ V_59 ] ) )
return 0 ;
return 1 ;
}
static inline void
F_67 ( struct V_8 * V_9 , struct V_1 * V_7 , bool V_59 )
{
unsigned long V_66 , V_67 , V_68 ;
T_1 V_69 , V_70 ;
F_57 ( F_46 ( V_7 -> V_63 [ V_59 ] , V_7 -> V_62 [ V_59 ] ) ) ;
if ( F_65 ( V_9 , V_7 , V_59 ) )
return;
F_62 ( V_9 , V_7 , V_59 , V_58 + V_64 ) ;
V_67 = V_58 - V_7 -> V_62 [ V_59 ] ;
V_66 = V_67 / V_64 ;
if ( ! V_66 )
return;
V_70 = V_7 -> V_28 [ V_59 ] * V_64 * V_66 ;
F_68 ( V_70 , V_71 ) ;
V_69 = V_70 ;
V_68 = ( V_7 -> V_31 [ V_59 ] * V_64 * V_66 ) / V_71 ;
if ( ! V_69 && ! V_68 )
return;
if ( V_7 -> V_60 [ V_59 ] >= V_69 )
V_7 -> V_60 [ V_59 ] -= V_69 ;
else
V_7 -> V_60 [ V_59 ] = 0 ;
if ( V_7 -> V_61 [ V_59 ] >= V_68 )
V_7 -> V_61 [ V_59 ] -= V_68 ;
else
V_7 -> V_61 [ V_59 ] = 0 ;
V_7 -> V_62 [ V_59 ] += V_66 * V_64 ;
F_61 ( V_9 , V_7 , L_3
L_4 ,
V_59 == V_29 ? 'R' : 'W' , V_66 , V_69 , V_68 ,
V_7 -> V_62 [ V_59 ] , V_7 -> V_63 [ V_59 ] , V_58 ) ;
}
static bool F_69 ( struct V_8 * V_9 , struct V_1 * V_7 ,
struct V_72 * V_72 , unsigned long * V_73 )
{
bool V_59 = F_70 ( V_72 ) ;
unsigned int V_74 ;
unsigned long V_75 , V_76 , V_77 ;
T_1 V_70 ;
V_75 = V_77 = V_58 - V_7 -> V_62 [ V_59 ] ;
if ( ! V_75 )
V_77 = V_64 ;
V_77 = F_63 ( V_77 , V_64 ) ;
V_70 = ( T_1 ) V_7 -> V_31 [ V_59 ] * V_77 ;
F_68 ( V_70 , V_71 ) ;
if ( V_70 > V_78 )
V_74 = V_78 ;
else
V_74 = V_70 ;
if ( V_7 -> V_61 [ V_59 ] + 1 <= V_74 ) {
if ( V_73 )
* V_73 = 0 ;
return 1 ;
}
V_76 = ( ( V_7 -> V_61 [ V_59 ] + 1 ) * V_71 ) / V_7 -> V_31 [ V_59 ] + 1 ;
if ( V_76 > V_75 )
V_76 = V_76 - V_75 ;
else
V_76 = 1 ;
if ( V_73 )
* V_73 = V_76 ;
return 0 ;
}
static bool F_71 ( struct V_8 * V_9 , struct V_1 * V_7 ,
struct V_72 * V_72 , unsigned long * V_73 )
{
bool V_59 = F_70 ( V_72 ) ;
T_1 V_79 , V_80 , V_70 ;
unsigned long V_75 , V_76 , V_77 ;
V_75 = V_77 = V_58 - V_7 -> V_62 [ V_59 ] ;
if ( ! V_75 )
V_77 = V_64 ;
V_77 = F_63 ( V_77 , V_64 ) ;
V_70 = V_7 -> V_28 [ V_59 ] * V_77 ;
F_68 ( V_70 , V_71 ) ;
V_79 = V_70 ;
if ( V_7 -> V_60 [ V_59 ] + V_72 -> V_81 <= V_79 ) {
if ( V_73 )
* V_73 = 0 ;
return 1 ;
}
V_80 = V_7 -> V_60 [ V_59 ] + V_72 -> V_81 - V_79 ;
V_76 = F_72 ( V_80 * V_71 , V_7 -> V_28 [ V_59 ] ) ;
if ( ! V_76 )
V_76 = 1 ;
V_76 = V_76 + ( V_77 - V_75 ) ;
if ( V_73 )
* V_73 = V_76 ;
return 0 ;
}
static bool F_73 ( struct V_1 * V_7 , bool V_59 ) {
if ( V_7 -> V_28 [ V_59 ] == - 1 && V_7 -> V_31 [ V_59 ] == - 1 )
return 1 ;
return 0 ;
}
static bool F_74 ( struct V_8 * V_9 , struct V_1 * V_7 ,
struct V_72 * V_72 , unsigned long * V_73 )
{
bool V_59 = F_70 ( V_72 ) ;
unsigned long V_82 = 0 , V_83 = 0 , V_84 = 0 ;
F_57 ( V_7 -> V_12 [ V_59 ] && V_72 != F_75 ( & V_7 -> V_26 [ V_59 ] ) ) ;
if ( V_7 -> V_28 [ V_59 ] == - 1 && V_7 -> V_31 [ V_59 ] == - 1 ) {
if ( V_73 )
* V_73 = 0 ;
return 1 ;
}
if ( F_65 ( V_9 , V_7 , V_59 ) )
F_60 ( V_9 , V_7 , V_59 ) ;
else {
if ( F_46 ( V_7 -> V_63 [ V_59 ] , V_58 + V_64 ) )
F_64 ( V_9 , V_7 , V_59 , V_58 + V_64 ) ;
}
if ( F_71 ( V_9 , V_7 , V_72 , & V_82 )
&& F_69 ( V_9 , V_7 , V_72 , & V_83 ) ) {
if ( V_73 )
* V_73 = 0 ;
return 1 ;
}
V_84 = F_76 ( V_82 , V_83 ) ;
if ( V_73 )
* V_73 = V_84 ;
if ( F_46 ( V_7 -> V_63 [ V_59 ] , V_58 + V_84 ) )
F_64 ( V_9 , V_7 , V_59 , V_58 + V_84 ) ;
return 0 ;
}
static void F_77 ( struct V_4 * V_5 , T_1 V_85 ,
int V_59 )
{
struct V_1 * V_7 = F_3 ( V_5 ) ;
struct V_15 * V_16 ;
unsigned long V_24 ;
if ( V_7 -> V_16 == NULL )
return;
F_78 ( V_24 ) ;
V_16 = F_79 ( V_7 -> V_16 ) ;
F_80 ( & V_16 -> V_36 , V_59 , 1 ) ;
F_80 ( & V_16 -> V_35 , V_59 , V_85 ) ;
F_81 ( V_24 ) ;
}
static void F_82 ( struct V_1 * V_7 , struct V_72 * V_72 )
{
bool V_59 = F_70 ( V_72 ) ;
V_7 -> V_60 [ V_59 ] += V_72 -> V_81 ;
V_7 -> V_61 [ V_59 ] ++ ;
F_77 ( F_5 ( V_7 ) , V_72 -> V_81 , V_72 -> V_86 ) ;
}
static void F_83 ( struct V_8 * V_9 , struct V_1 * V_7 ,
struct V_72 * V_72 )
{
bool V_59 = F_70 ( V_72 ) ;
F_84 ( & V_7 -> V_26 [ V_59 ] , V_72 ) ;
F_85 ( F_5 ( V_7 ) ) ;
V_7 -> V_12 [ V_59 ] ++ ;
V_9 -> V_12 [ V_59 ] ++ ;
F_51 ( V_9 , V_7 ) ;
}
static void F_86 ( struct V_8 * V_9 , struct V_1 * V_7 )
{
unsigned long V_87 = - 1 , V_88 = - 1 , V_89 = - 1 , V_50 ;
struct V_72 * V_72 ;
if ( ( V_72 = F_75 ( & V_7 -> V_26 [ V_29 ] ) ) )
F_74 ( V_9 , V_7 , V_72 , & V_87 ) ;
if ( ( V_72 = F_75 ( & V_7 -> V_26 [ V_30 ] ) ) )
F_74 ( V_9 , V_7 , V_72 , & V_88 ) ;
V_89 = F_87 ( V_87 , V_88 ) ;
V_50 = V_58 + V_89 ;
F_55 ( V_9 , V_7 ) ;
V_7 -> V_50 = V_50 ;
F_51 ( V_9 , V_7 ) ;
}
static void F_88 ( struct V_8 * V_9 , struct V_1 * V_7 ,
bool V_59 , struct V_90 * V_91 )
{
struct V_72 * V_72 ;
V_72 = F_89 ( & V_7 -> V_26 [ V_59 ] ) ;
V_7 -> V_12 [ V_59 ] -- ;
F_90 ( F_5 ( V_7 ) ) ;
F_57 ( V_9 -> V_12 [ V_59 ] <= 0 ) ;
V_9 -> V_12 [ V_59 ] -- ;
F_82 ( V_7 , V_72 ) ;
F_84 ( V_91 , V_72 ) ;
V_72 -> V_86 |= V_92 ;
F_67 ( V_9 , V_7 , V_59 ) ;
}
static int F_91 ( struct V_8 * V_9 , struct V_1 * V_7 ,
struct V_90 * V_91 )
{
unsigned int V_93 = 0 , V_94 = 0 ;
unsigned int V_95 = V_96 * 3 / 4 ;
unsigned int V_97 = V_96 - V_95 ;
struct V_72 * V_72 ;
while ( ( V_72 = F_75 ( & V_7 -> V_26 [ V_29 ] ) )
&& F_74 ( V_9 , V_7 , V_72 , NULL ) ) {
F_88 ( V_9 , V_7 , F_70 ( V_72 ) , V_91 ) ;
V_93 ++ ;
if ( V_93 >= V_95 )
break;
}
while ( ( V_72 = F_75 ( & V_7 -> V_26 [ V_30 ] ) )
&& F_74 ( V_9 , V_7 , V_72 , NULL ) ) {
F_88 ( V_9 , V_7 , F_70 ( V_72 ) , V_91 ) ;
V_94 ++ ;
if ( V_94 >= V_97 )
break;
}
return V_93 + V_94 ;
}
static int F_92 ( struct V_8 * V_9 , struct V_90 * V_91 )
{
unsigned int V_98 = 0 ;
struct V_1 * V_7 ;
struct V_41 * V_48 = & V_9 -> V_57 ;
while ( 1 ) {
V_7 = F_38 ( V_48 ) ;
if ( ! V_7 )
break;
if ( F_46 ( V_58 , V_7 -> V_50 ) )
break;
F_55 ( V_9 , V_7 ) ;
V_98 += F_91 ( V_9 , V_7 , V_91 ) ;
if ( V_7 -> V_12 [ 0 ] || V_7 -> V_12 [ 1 ] ) {
F_86 ( V_9 , V_7 ) ;
F_51 ( V_9 , V_7 ) ;
}
if ( V_98 >= V_99 )
break;
}
return V_98 ;
}
static void F_93 ( struct V_8 * V_9 )
{
struct V_39 * V_40 = V_9 -> V_10 ;
struct V_4 * V_5 , * V_46 ;
if ( ! V_9 -> V_27 )
return;
F_94 ( & V_9 -> V_27 , false ) ;
F_95 ( V_9 , L_5 ) ;
F_96 (blkg, n, &q->blkg_list, q_node) {
struct V_1 * V_7 = F_3 ( V_5 ) ;
if ( ! V_7 -> V_27 )
continue;
if ( ! F_94 ( & V_7 -> V_27 , false ) )
continue;
F_61 ( V_9 , V_7 , L_6
L_7 , V_7 -> V_28 [ V_29 ] , V_7 -> V_28 [ V_30 ] ,
V_7 -> V_31 [ V_29 ] , V_7 -> V_31 [ V_30 ] ) ;
F_60 ( V_9 , V_7 , 0 ) ;
F_60 ( V_9 , V_7 , 1 ) ;
if ( F_52 ( V_7 ) )
F_86 ( V_9 , V_7 ) ;
}
}
static int F_97 ( struct V_39 * V_40 )
{
struct V_8 * V_9 = V_40 -> V_9 ;
unsigned int V_98 = 0 ;
struct V_90 V_100 ;
struct V_72 * V_72 ;
struct V_101 V_102 ;
F_14 ( V_40 -> V_103 ) ;
F_93 ( V_9 ) ;
if ( ! F_8 ( V_9 ) )
goto V_104;
F_22 ( & V_100 ) ;
F_95 ( V_9 , L_8 ,
F_8 ( V_9 ) , V_9 -> V_12 [ V_29 ] ,
V_9 -> V_12 [ V_30 ] ) ;
V_98 = F_92 ( V_9 , & V_100 ) ;
if ( V_98 )
F_95 ( V_9 , L_9 , V_98 ) ;
F_56 ( V_9 ) ;
V_104:
F_19 ( V_40 -> V_103 ) ;
if ( V_98 ) {
F_98 ( & V_102 ) ;
while( ( V_72 = F_89 ( & V_100 ) ) )
F_99 ( V_72 ) ;
F_100 ( & V_102 ) ;
}
return V_98 ;
}
void F_101 ( struct V_13 * V_14 )
{
struct V_8 * V_9 = F_2 ( V_14 , struct V_8 ,
V_105 . V_14 ) ;
struct V_39 * V_40 = V_9 -> V_10 ;
F_97 ( V_40 ) ;
}
static void
F_59 ( struct V_8 * V_9 , unsigned long V_106 )
{
struct V_17 * V_18 = & V_9 -> V_105 ;
if ( F_8 ( V_9 ) || V_9 -> V_27 ) {
F_102 ( V_107 , V_18 , V_106 ) ;
F_95 ( V_9 , L_10 ,
V_106 , V_58 ) ;
}
}
static T_1 F_103 ( struct V_108 * V_109 ,
struct V_2 * V_3 , int V_110 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_111 V_112 = { } , V_70 ;
int V_113 , V_33 ;
F_29 (cpu) {
struct V_15 * V_34 = F_30 ( V_7 -> V_16 , V_33 ) ;
V_70 = F_104 ( ( void * ) V_34 + V_110 ) ;
for ( V_113 = 0 ; V_113 < V_114 ; V_113 ++ )
V_112 . V_115 [ V_113 ] += V_70 . V_115 [ V_113 ] ;
}
return F_105 ( V_109 , V_3 , & V_112 ) ;
}
static int F_106 ( struct V_116 * V_117 , struct V_118 * V_119 ,
struct V_108 * V_109 )
{
struct V_37 * V_37 = F_107 ( V_117 ) ;
F_108 ( V_109 , V_37 , F_103 , & V_6 ,
V_119 -> V_120 , true ) ;
return 0 ;
}
static T_1 F_109 ( struct V_108 * V_109 , struct V_2 * V_3 ,
int V_110 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
T_1 V_121 = * ( T_1 * ) ( ( void * ) V_7 + V_110 ) ;
if ( V_121 == - 1 )
return 0 ;
return F_110 ( V_109 , V_3 , V_121 ) ;
}
static T_1 F_111 ( struct V_108 * V_109 , struct V_2 * V_3 ,
int V_110 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned int V_121 = * ( unsigned int * ) ( ( void * ) V_7 + V_110 ) ;
if ( V_121 == - 1 )
return 0 ;
return F_110 ( V_109 , V_3 , V_121 ) ;
}
static int F_112 ( struct V_116 * V_117 , struct V_118 * V_119 ,
struct V_108 * V_109 )
{
F_108 ( V_109 , F_107 ( V_117 ) , F_109 ,
& V_6 , V_119 -> V_120 , false ) ;
return 0 ;
}
static int F_113 ( struct V_116 * V_117 , struct V_118 * V_119 ,
struct V_108 * V_109 )
{
F_108 ( V_109 , F_107 ( V_117 ) , F_111 ,
& V_6 , V_119 -> V_120 , false ) ;
return 0 ;
}
static int F_114 ( struct V_116 * V_117 , struct V_118 * V_119 , const char * V_122 ,
bool V_123 )
{
struct V_37 * V_37 = F_107 ( V_117 ) ;
struct V_124 V_125 ;
struct V_1 * V_7 ;
struct V_8 * V_9 ;
int V_126 ;
V_126 = F_115 ( V_37 , & V_6 , V_122 , & V_125 ) ;
if ( V_126 )
return V_126 ;
V_7 = F_3 ( V_125 . V_5 ) ;
V_9 = V_125 . V_5 -> V_40 -> V_9 ;
if ( ! V_125 . V_121 )
V_125 . V_121 = - 1 ;
if ( V_123 )
* ( T_1 * ) ( ( void * ) V_7 + V_119 -> V_120 ) = V_125 . V_121 ;
else
* ( unsigned int * ) ( ( void * ) V_7 + V_119 -> V_120 ) = V_125 . V_121 ;
F_94 ( & V_7 -> V_27 , true ) ;
F_94 ( & V_9 -> V_27 , true ) ;
F_59 ( V_9 , 0 ) ;
F_116 ( & V_125 ) ;
return 0 ;
}
static int F_117 ( struct V_116 * V_117 , struct V_118 * V_119 ,
const char * V_122 )
{
return F_114 ( V_117 , V_119 , V_122 , true ) ;
}
static int F_118 ( struct V_116 * V_117 , struct V_118 * V_119 ,
const char * V_122 )
{
return F_114 ( V_117 , V_119 , V_122 , false ) ;
}
static void F_119 ( struct V_39 * V_40 )
{
struct V_8 * V_9 = V_40 -> V_9 ;
F_120 ( & V_9 -> V_105 ) ;
}
bool F_121 ( struct V_39 * V_40 , struct V_72 * V_72 )
{
struct V_8 * V_9 = V_40 -> V_9 ;
struct V_1 * V_7 ;
bool V_59 = F_70 ( V_72 ) , V_127 = true ;
struct V_37 * V_37 ;
bool V_128 = false ;
if ( V_72 -> V_86 & V_92 ) {
V_72 -> V_86 &= ~ V_92 ;
goto V_104;
}
F_122 () ;
V_37 = F_123 ( V_72 ) ;
V_7 = F_32 ( V_9 , V_37 ) ;
if ( V_7 ) {
if ( F_73 ( V_7 , V_59 ) ) {
F_77 ( F_5 ( V_7 ) ,
V_72 -> V_81 , V_72 -> V_86 ) ;
goto V_129;
}
}
F_14 ( V_40 -> V_103 ) ;
V_7 = F_34 ( V_9 , V_37 ) ;
if ( F_124 ( ! V_7 ) )
goto V_130;
if ( V_7 -> V_12 [ V_59 ] ) {
V_127 = false ;
goto V_131;
}
if ( F_74 ( V_9 , V_7 , V_72 , NULL ) ) {
F_82 ( V_7 , V_72 ) ;
F_67 ( V_9 , V_7 , V_59 ) ;
goto V_130;
}
V_131:
F_61 ( V_9 , V_7 , L_11
L_12 ,
V_59 == V_29 ? 'R' : 'W' ,
V_7 -> V_60 [ V_59 ] , V_72 -> V_81 , V_7 -> V_28 [ V_59 ] ,
V_7 -> V_61 [ V_59 ] , V_7 -> V_31 [ V_59 ] ,
V_7 -> V_12 [ V_29 ] , V_7 -> V_12 [ V_30 ] ) ;
F_125 ( V_72 ) ;
F_83 ( V_40 -> V_9 , V_7 , V_72 ) ;
V_128 = true ;
if ( V_127 ) {
F_86 ( V_9 , V_7 ) ;
F_56 ( V_9 ) ;
}
V_130:
F_19 ( V_40 -> V_103 ) ;
V_129:
F_126 () ;
V_104:
return V_128 ;
}
void F_127 ( struct V_39 * V_40 )
__releases( V_40 -> V_103 ) __acquires( V_40 -> V_103 )
{
struct V_8 * V_9 = V_40 -> V_9 ;
struct V_41 * V_48 = & V_9 -> V_57 ;
struct V_1 * V_7 ;
struct V_90 V_91 ;
struct V_72 * V_72 ;
F_128 ( V_40 ) ;
F_22 ( & V_91 ) ;
while ( ( V_7 = F_38 ( V_48 ) ) ) {
F_55 ( V_9 , V_7 ) ;
while ( ( V_72 = F_75 ( & V_7 -> V_26 [ V_29 ] ) ) )
F_88 ( V_9 , V_7 , F_70 ( V_72 ) , & V_91 ) ;
while ( ( V_72 = F_75 ( & V_7 -> V_26 [ V_30 ] ) ) )
F_88 ( V_9 , V_7 , F_70 ( V_72 ) , & V_91 ) ;
}
F_19 ( V_40 -> V_103 ) ;
while ( ( V_72 = F_89 ( & V_91 ) ) )
F_99 ( V_72 ) ;
F_14 ( V_40 -> V_103 ) ;
}
int F_129 ( struct V_39 * V_40 )
{
struct V_8 * V_9 ;
int V_126 ;
V_9 = F_130 ( sizeof( * V_9 ) , V_132 , V_40 -> V_51 ) ;
if ( ! V_9 )
return - V_133 ;
V_9 -> V_57 = V_134 ;
V_9 -> V_27 = false ;
F_131 ( & V_9 -> V_105 , F_101 ) ;
V_40 -> V_9 = V_9 ;
V_9 -> V_10 = V_40 ;
V_126 = F_132 ( V_40 , & V_6 ) ;
if ( V_126 )
F_133 ( V_9 ) ;
return V_126 ;
}
void F_134 ( struct V_39 * V_40 )
{
F_57 ( ! V_40 -> V_9 ) ;
F_119 ( V_40 ) ;
F_135 ( V_40 , & V_6 ) ;
F_133 ( V_40 -> V_9 ) ;
}
static int T_2 F_136 ( void )
{
V_107 = F_137 ( L_13 , V_135 , 0 ) ;
if ( ! V_107 )
F_138 ( L_14 ) ;
return F_139 ( & V_6 ) ;
}
