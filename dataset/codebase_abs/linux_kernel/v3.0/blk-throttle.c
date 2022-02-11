static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
if ( V_3 )
return F_2 ( V_3 , struct V_1 , V_3 ) ;
return NULL ;
}
static inline int F_3 ( struct V_4 * V_5 )
{
return ( V_5 -> V_6 [ 0 ] + V_5 -> V_6 [ 1 ] ) ;
}
static inline struct V_1 * F_4 ( struct V_1 * V_7 )
{
F_5 ( & V_7 -> V_8 ) ;
return V_7 ;
}
static void F_6 ( struct V_9 * V_10 )
{
struct V_1 * V_7 ;
V_7 = F_2 ( V_10 , struct V_1 , V_9 ) ;
F_7 ( V_7 -> V_3 . V_11 ) ;
F_8 ( V_7 ) ;
}
static void F_9 ( struct V_1 * V_7 )
{
F_10 ( F_11 ( & V_7 -> V_8 ) <= 0 ) ;
if ( ! F_12 ( & V_7 -> V_8 ) )
return;
F_13 ( & V_7 -> V_9 , F_6 ) ;
}
static void F_14 ( struct V_1 * V_7 )
{
F_15 ( & V_7 -> V_12 ) ;
F_16 ( & V_7 -> V_13 ) ;
F_17 ( & V_7 -> V_14 [ 0 ] ) ;
F_17 ( & V_7 -> V_14 [ 1 ] ) ;
V_7 -> V_15 = false ;
V_7 -> V_16 [ 0 ] = V_7 -> V_16 [ 1 ] = - 1 ;
V_7 -> V_17 [ 0 ] = V_7 -> V_17 [ 1 ] = - 1 ;
F_18 ( & V_7 -> V_8 , 1 ) ;
}
static void
F_19 ( struct V_4 * V_5 , struct V_1 * V_7 )
{
F_20 ( & V_7 -> V_12 , & V_5 -> V_18 ) ;
V_5 -> V_19 ++ ;
}
static void
F_21 ( struct V_4 * V_5 , struct V_1 * V_7 )
{
struct V_20 * V_21 = & V_5 -> V_22 -> V_20 ;
unsigned int V_23 , V_24 ;
if ( ! V_7 || V_7 -> V_3 . V_25 )
return;
if ( V_21 -> V_25 && F_22 ( V_21 -> V_25 ) ) {
sscanf ( F_22 ( V_21 -> V_25 ) , L_1 , & V_23 , & V_24 ) ;
V_7 -> V_3 . V_25 = F_23 ( V_23 , V_24 ) ;
}
}
static void
F_24 ( struct V_4 * V_5 , struct V_1 * V_7 )
{
if ( ! V_7 || V_7 -> V_3 . V_25 )
return;
F_25 ( V_5 -> V_22 -> V_26 ) ;
F_21 ( V_5 , V_7 ) ;
F_26 ( V_5 -> V_22 -> V_26 ) ;
}
static void F_27 ( struct V_4 * V_5 ,
struct V_1 * V_7 , struct V_27 * V_28 )
{
F_21 ( V_5 , V_7 ) ;
F_28 ( V_28 , & V_7 -> V_3 , ( void * ) V_5 ,
V_7 -> V_3 . V_25 , V_29 ) ;
V_7 -> V_16 [ V_30 ] = F_29 ( V_28 , V_7 -> V_3 . V_25 ) ;
V_7 -> V_16 [ V_31 ] = F_30 ( V_28 , V_7 -> V_3 . V_25 ) ;
V_7 -> V_17 [ V_30 ] = F_31 ( V_28 , V_7 -> V_3 . V_25 ) ;
V_7 -> V_17 [ V_31 ] = F_32 ( V_28 , V_7 -> V_3 . V_25 ) ;
F_19 ( V_5 , V_7 ) ;
}
static struct V_1 * F_33 ( struct V_4 * V_5 )
{
struct V_1 * V_7 = NULL ;
int V_32 ;
V_7 = F_34 ( sizeof( * V_7 ) , V_33 , V_5 -> V_22 -> V_34 ) ;
if ( ! V_7 )
return NULL ;
V_32 = F_35 ( & V_7 -> V_3 ) ;
if ( V_32 ) {
F_8 ( V_7 ) ;
return NULL ;
}
F_14 ( V_7 ) ;
return V_7 ;
}
static struct
V_1 * F_36 ( struct V_4 * V_5 , struct V_27 * V_28 )
{
struct V_1 * V_7 = NULL ;
void * V_35 = V_5 ;
if ( V_28 == & V_36 )
V_7 = V_5 -> V_37 ;
else
V_7 = F_1 ( F_37 ( V_28 , V_35 ) ) ;
F_21 ( V_5 , V_7 ) ;
return V_7 ;
}
static struct V_1 * F_38 ( struct V_4 * V_5 )
{
struct V_1 * V_7 = NULL , * V_38 = NULL ;
struct V_27 * V_28 ;
struct V_39 * V_40 = V_5 -> V_22 ;
F_39 () ;
V_28 = F_40 ( V_41 ) ;
V_7 = F_36 ( V_5 , V_28 ) ;
if ( V_7 ) {
F_41 () ;
return V_7 ;
}
F_42 ( V_40 ) ;
F_41 () ;
F_26 ( V_40 -> V_26 ) ;
V_7 = F_33 ( V_5 ) ;
if ( F_43 ( F_44 ( V_42 , & V_40 -> V_43 ) ) ) {
F_45 ( V_40 ) ;
if ( V_7 )
F_8 ( V_7 ) ;
return F_46 ( - V_44 ) ;
}
F_45 ( V_40 ) ;
F_25 ( V_40 -> V_26 ) ;
F_39 () ;
V_28 = F_40 ( V_41 ) ;
V_38 = F_36 ( V_5 , V_28 ) ;
if ( V_38 ) {
F_8 ( V_7 ) ;
F_41 () ;
return V_38 ;
}
if ( ! V_7 ) {
V_7 = V_5 -> V_37 ;
return V_7 ;
}
F_27 ( V_5 , V_7 , V_28 ) ;
F_41 () ;
return V_7 ;
}
static struct V_1 * F_47 ( struct V_45 * V_46 )
{
if ( ! V_46 -> V_47 )
return NULL ;
if ( ! V_46 -> V_48 )
V_46 -> V_48 = F_48 ( & V_46 -> V_49 ) ;
if ( V_46 -> V_48 )
return F_49 ( V_46 -> V_48 ) ;
return NULL ;
}
static void F_50 ( struct V_13 * V_50 , struct V_51 * V_46 )
{
F_51 ( V_50 , V_46 ) ;
F_16 ( V_50 ) ;
}
static void F_52 ( struct V_13 * V_50 , struct V_45 * V_46 )
{
if ( V_46 -> V_48 == V_50 )
V_46 -> V_48 = NULL ;
F_50 ( V_50 , & V_46 -> V_49 ) ;
-- V_46 -> V_47 ;
}
static void F_53 ( struct V_45 * V_52 )
{
struct V_1 * V_7 ;
V_7 = F_47 ( V_52 ) ;
if ( ! V_7 )
return;
V_52 -> V_53 = V_7 -> V_54 ;
}
static void
F_54 ( struct V_45 * V_52 , struct V_1 * V_7 )
{
struct V_13 * * V_34 = & V_52 -> V_49 . V_13 ;
struct V_13 * V_55 = NULL ;
struct V_1 * V_38 ;
unsigned long V_35 = V_7 -> V_54 ;
int V_48 = 1 ;
while ( * V_34 != NULL ) {
V_55 = * V_34 ;
V_38 = F_49 ( V_55 ) ;
if ( F_55 ( V_35 , V_38 -> V_54 ) )
V_34 = & V_55 -> V_56 ;
else {
V_34 = & V_55 -> V_57 ;
V_48 = 0 ;
}
}
if ( V_48 )
V_52 -> V_48 = & V_7 -> V_13 ;
F_56 ( & V_7 -> V_13 , V_55 , V_34 ) ;
F_57 ( & V_7 -> V_13 , & V_52 -> V_49 ) ;
}
static void F_58 ( struct V_4 * V_5 , struct V_1 * V_7 )
{
struct V_45 * V_52 = & V_5 -> V_58 ;
F_54 ( V_52 , V_7 ) ;
F_59 ( V_7 ) ;
V_52 -> V_47 ++ ;
}
static void F_60 ( struct V_4 * V_5 , struct V_1 * V_7 )
{
if ( ! F_61 ( V_7 ) )
F_58 ( V_5 , V_7 ) ;
}
static void F_62 ( struct V_4 * V_5 , struct V_1 * V_7 )
{
F_52 ( & V_7 -> V_13 , & V_5 -> V_58 ) ;
F_63 ( V_7 ) ;
}
static void F_64 ( struct V_4 * V_5 , struct V_1 * V_7 )
{
if ( F_61 ( V_7 ) )
F_62 ( V_5 , V_7 ) ;
}
static void F_65 ( struct V_4 * V_5 )
{
struct V_45 * V_52 = & V_5 -> V_58 ;
if ( ! F_3 ( V_5 ) )
return;
F_10 ( ! V_52 -> V_47 ) ;
F_53 ( V_52 ) ;
if ( F_66 ( V_52 -> V_53 , V_59 ) )
F_67 ( V_5 , 0 ) ;
else
F_67 ( V_5 , ( V_52 -> V_53 - V_59 ) ) ;
}
static inline void
F_68 ( struct V_4 * V_5 , struct V_1 * V_7 , bool V_60 )
{
V_7 -> V_61 [ V_60 ] = 0 ;
V_7 -> V_62 [ V_60 ] = 0 ;
V_7 -> V_63 [ V_60 ] = V_59 ;
V_7 -> V_64 [ V_60 ] = V_59 + V_65 ;
F_69 ( V_5 , V_7 , L_2 ,
V_60 == V_30 ? 'R' : 'W' , V_7 -> V_63 [ V_60 ] ,
V_7 -> V_64 [ V_60 ] , V_59 ) ;
}
static inline void F_70 ( struct V_4 * V_5 ,
struct V_1 * V_7 , bool V_60 , unsigned long V_66 )
{
V_7 -> V_64 [ V_60 ] = F_71 ( V_66 , V_65 ) ;
}
static inline void F_72 ( struct V_4 * V_5 ,
struct V_1 * V_7 , bool V_60 , unsigned long V_66 )
{
V_7 -> V_64 [ V_60 ] = F_71 ( V_66 , V_65 ) ;
F_69 ( V_5 , V_7 , L_3 ,
V_60 == V_30 ? 'R' : 'W' , V_7 -> V_63 [ V_60 ] ,
V_7 -> V_64 [ V_60 ] , V_59 ) ;
}
static bool
F_73 ( struct V_4 * V_5 , struct V_1 * V_7 , bool V_60 )
{
if ( F_74 ( V_59 , V_7 -> V_63 [ V_60 ] , V_7 -> V_64 [ V_60 ] ) )
return 0 ;
return 1 ;
}
static inline void
F_75 ( struct V_4 * V_5 , struct V_1 * V_7 , bool V_60 )
{
unsigned long V_67 , V_68 , V_69 ;
T_1 V_70 , V_71 ;
F_10 ( F_55 ( V_7 -> V_64 [ V_60 ] , V_7 -> V_63 [ V_60 ] ) ) ;
if ( F_73 ( V_5 , V_7 , V_60 ) )
return;
F_70 ( V_5 , V_7 , V_60 , V_59 + V_65 ) ;
V_68 = V_59 - V_7 -> V_63 [ V_60 ] ;
V_67 = V_68 / V_65 ;
if ( ! V_67 )
return;
V_71 = V_7 -> V_16 [ V_60 ] * V_65 * V_67 ;
F_76 ( V_71 , V_72 ) ;
V_70 = V_71 ;
V_69 = ( V_7 -> V_17 [ V_60 ] * V_65 * V_67 ) / V_72 ;
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
F_69 ( V_5 , V_7 , L_4
L_5 ,
V_60 == V_30 ? 'R' : 'W' , V_67 , V_70 , V_69 ,
V_7 -> V_63 [ V_60 ] , V_7 -> V_64 [ V_60 ] , V_59 ) ;
}
static bool F_77 ( struct V_4 * V_5 , struct V_1 * V_7 ,
struct V_73 * V_73 , unsigned long * V_74 )
{
bool V_60 = F_78 ( V_73 ) ;
unsigned int V_75 ;
unsigned long V_76 , V_77 , V_78 ;
T_1 V_71 ;
V_76 = V_78 = V_59 - V_7 -> V_63 [ V_60 ] ;
if ( ! V_76 )
V_78 = V_65 ;
V_78 = F_71 ( V_78 , V_65 ) ;
V_71 = ( T_1 ) V_7 -> V_17 [ V_60 ] * V_78 ;
F_76 ( V_71 , V_72 ) ;
if ( V_71 > V_79 )
V_75 = V_79 ;
else
V_75 = V_71 ;
if ( V_7 -> V_62 [ V_60 ] + 1 <= V_75 ) {
if ( V_74 )
* V_74 = 0 ;
return 1 ;
}
V_77 = ( ( V_7 -> V_62 [ V_60 ] + 1 ) * V_72 ) / V_7 -> V_17 [ V_60 ] + 1 ;
if ( V_77 > V_76 )
V_77 = V_77 - V_76 ;
else
V_77 = 1 ;
if ( V_74 )
* V_74 = V_77 ;
return 0 ;
}
static bool F_79 ( struct V_4 * V_5 , struct V_1 * V_7 ,
struct V_73 * V_73 , unsigned long * V_74 )
{
bool V_60 = F_78 ( V_73 ) ;
T_1 V_80 , V_81 , V_71 ;
unsigned long V_76 , V_77 , V_78 ;
V_76 = V_78 = V_59 - V_7 -> V_63 [ V_60 ] ;
if ( ! V_76 )
V_78 = V_65 ;
V_78 = F_71 ( V_78 , V_65 ) ;
V_71 = V_7 -> V_16 [ V_60 ] * V_78 ;
F_76 ( V_71 , V_72 ) ;
V_80 = V_71 ;
if ( V_7 -> V_61 [ V_60 ] + V_73 -> V_82 <= V_80 ) {
if ( V_74 )
* V_74 = 0 ;
return 1 ;
}
V_81 = V_7 -> V_61 [ V_60 ] + V_73 -> V_82 - V_80 ;
V_77 = F_80 ( V_81 * V_72 , V_7 -> V_16 [ V_60 ] ) ;
if ( ! V_77 )
V_77 = 1 ;
V_77 = V_77 + ( V_78 - V_76 ) ;
if ( V_74 )
* V_74 = V_77 ;
return 0 ;
}
static bool F_81 ( struct V_1 * V_7 , bool V_60 ) {
if ( V_7 -> V_16 [ V_60 ] == - 1 && V_7 -> V_17 [ V_60 ] == - 1 )
return 1 ;
return 0 ;
}
static bool F_82 ( struct V_4 * V_5 , struct V_1 * V_7 ,
struct V_73 * V_73 , unsigned long * V_74 )
{
bool V_60 = F_78 ( V_73 ) ;
unsigned long V_83 = 0 , V_84 = 0 , V_85 = 0 ;
F_10 ( V_7 -> V_6 [ V_60 ] && V_73 != F_83 ( & V_7 -> V_14 [ V_60 ] ) ) ;
if ( V_7 -> V_16 [ V_60 ] == - 1 && V_7 -> V_17 [ V_60 ] == - 1 ) {
if ( V_74 )
* V_74 = 0 ;
return 1 ;
}
if ( F_73 ( V_5 , V_7 , V_60 ) )
F_68 ( V_5 , V_7 , V_60 ) ;
else {
if ( F_55 ( V_7 -> V_64 [ V_60 ] , V_59 + V_65 ) )
F_72 ( V_5 , V_7 , V_60 , V_59 + V_65 ) ;
}
if ( F_79 ( V_5 , V_7 , V_73 , & V_83 )
&& F_77 ( V_5 , V_7 , V_73 , & V_84 ) ) {
if ( V_74 )
* V_74 = 0 ;
return 1 ;
}
V_85 = F_84 ( V_83 , V_84 ) ;
if ( V_74 )
* V_74 = V_85 ;
if ( F_55 ( V_7 -> V_64 [ V_60 ] , V_59 + V_85 ) )
F_72 ( V_5 , V_7 , V_60 , V_59 + V_85 ) ;
return 0 ;
}
static void F_85 ( struct V_1 * V_7 , struct V_73 * V_73 )
{
bool V_60 = F_78 ( V_73 ) ;
bool V_86 = V_73 -> V_87 & V_88 ;
V_7 -> V_61 [ V_60 ] += V_73 -> V_82 ;
V_7 -> V_62 [ V_60 ] ++ ;
F_86 ( & V_7 -> V_3 , V_73 -> V_82 , V_60 , V_86 ) ;
}
static void F_87 ( struct V_4 * V_5 , struct V_1 * V_7 ,
struct V_73 * V_73 )
{
bool V_60 = F_78 ( V_73 ) ;
F_88 ( & V_7 -> V_14 [ V_60 ] , V_73 ) ;
F_4 ( V_7 ) ;
V_7 -> V_6 [ V_60 ] ++ ;
V_5 -> V_6 [ V_60 ] ++ ;
F_60 ( V_5 , V_7 ) ;
}
static void F_89 ( struct V_4 * V_5 , struct V_1 * V_7 )
{
unsigned long V_89 = - 1 , V_90 = - 1 , V_91 = - 1 , V_54 ;
struct V_73 * V_73 ;
if ( ( V_73 = F_83 ( & V_7 -> V_14 [ V_30 ] ) ) )
F_82 ( V_5 , V_7 , V_73 , & V_89 ) ;
if ( ( V_73 = F_83 ( & V_7 -> V_14 [ V_31 ] ) ) )
F_82 ( V_5 , V_7 , V_73 , & V_90 ) ;
V_91 = F_90 ( V_89 , V_90 ) ;
V_54 = V_59 + V_91 ;
F_64 ( V_5 , V_7 ) ;
V_7 -> V_54 = V_54 ;
F_60 ( V_5 , V_7 ) ;
}
static void F_91 ( struct V_4 * V_5 , struct V_1 * V_7 ,
bool V_60 , struct V_92 * V_93 )
{
struct V_73 * V_73 ;
V_73 = F_92 ( & V_7 -> V_14 [ V_60 ] ) ;
V_7 -> V_6 [ V_60 ] -- ;
F_9 ( V_7 ) ;
F_10 ( V_5 -> V_6 [ V_60 ] <= 0 ) ;
V_5 -> V_6 [ V_60 ] -- ;
F_85 ( V_7 , V_73 ) ;
F_88 ( V_93 , V_73 ) ;
V_73 -> V_87 |= V_94 ;
F_75 ( V_5 , V_7 , V_60 ) ;
}
static int F_93 ( struct V_4 * V_5 , struct V_1 * V_7 ,
struct V_92 * V_93 )
{
unsigned int V_95 = 0 , V_96 = 0 ;
unsigned int V_97 = V_98 * 3 / 4 ;
unsigned int V_99 = V_98 - V_97 ;
struct V_73 * V_73 ;
while ( ( V_73 = F_83 ( & V_7 -> V_14 [ V_30 ] ) )
&& F_82 ( V_5 , V_7 , V_73 , NULL ) ) {
F_91 ( V_5 , V_7 , F_78 ( V_73 ) , V_93 ) ;
V_95 ++ ;
if ( V_95 >= V_97 )
break;
}
while ( ( V_73 = F_83 ( & V_7 -> V_14 [ V_31 ] ) )
&& F_82 ( V_5 , V_7 , V_73 , NULL ) ) {
F_91 ( V_5 , V_7 , F_78 ( V_73 ) , V_93 ) ;
V_96 ++ ;
if ( V_96 >= V_99 )
break;
}
return V_95 + V_96 ;
}
static int F_94 ( struct V_4 * V_5 , struct V_92 * V_93 )
{
unsigned int V_100 = 0 ;
struct V_1 * V_7 ;
struct V_45 * V_52 = & V_5 -> V_58 ;
while ( 1 ) {
V_7 = F_47 ( V_52 ) ;
if ( ! V_7 )
break;
if ( F_55 ( V_59 , V_7 -> V_54 ) )
break;
F_64 ( V_5 , V_7 ) ;
V_100 += F_93 ( V_5 , V_7 , V_93 ) ;
if ( V_7 -> V_6 [ 0 ] || V_7 -> V_6 [ 1 ] ) {
F_89 ( V_5 , V_7 ) ;
F_60 ( V_5 , V_7 ) ;
}
if ( V_100 >= V_101 )
break;
}
return V_100 ;
}
static void F_95 ( struct V_4 * V_5 )
{
struct V_1 * V_7 ;
struct V_102 * V_103 , * V_50 ;
if ( ! V_5 -> V_15 )
return;
F_96 ( & V_5 -> V_15 , false ) ;
F_97 ( V_5 , L_6 ) ;
F_98 (tg, pos, n, &td->tg_list, tg_node) {
if ( ! V_7 -> V_15 )
continue;
if ( ! F_96 ( & V_7 -> V_15 , false ) )
continue;
F_69 ( V_5 , V_7 , L_7
L_8 , V_7 -> V_16 [ V_30 ] , V_7 -> V_16 [ V_31 ] ,
V_7 -> V_17 [ V_30 ] , V_7 -> V_17 [ V_31 ] ) ;
F_68 ( V_5 , V_7 , 0 ) ;
F_68 ( V_5 , V_7 , 1 ) ;
if ( F_61 ( V_7 ) )
F_89 ( V_5 , V_7 ) ;
}
}
static int F_99 ( struct V_39 * V_40 )
{
struct V_4 * V_5 = V_40 -> V_5 ;
unsigned int V_100 = 0 ;
struct V_92 V_104 ;
struct V_73 * V_73 ;
struct V_105 V_106 ;
F_25 ( V_40 -> V_26 ) ;
F_95 ( V_5 ) ;
if ( ! F_3 ( V_5 ) )
goto V_107;
F_17 ( & V_104 ) ;
F_97 ( V_5 , L_9 ,
F_3 ( V_5 ) , V_5 -> V_6 [ V_30 ] ,
V_5 -> V_6 [ V_31 ] ) ;
V_100 = F_94 ( V_5 , & V_104 ) ;
if ( V_100 )
F_97 ( V_5 , L_10 , V_100 ) ;
F_65 ( V_5 ) ;
V_107:
F_26 ( V_40 -> V_26 ) ;
if ( V_100 ) {
F_100 ( & V_106 ) ;
while( ( V_73 = F_92 ( & V_104 ) ) )
F_101 ( V_73 ) ;
F_102 ( & V_106 ) ;
}
return V_100 ;
}
void F_103 ( struct V_108 * V_109 )
{
struct V_4 * V_5 = F_2 ( V_109 , struct V_4 ,
V_110 . V_109 ) ;
struct V_39 * V_40 = V_5 -> V_22 ;
F_99 ( V_40 ) ;
}
static void
F_67 ( struct V_4 * V_5 , unsigned long V_111 )
{
struct V_112 * V_113 = & V_5 -> V_110 ;
if ( F_3 ( V_5 ) > 0 || V_5 -> V_15 ) {
F_104 ( V_113 ) ;
F_105 ( V_114 , V_113 , V_111 ) ;
F_97 ( V_5 , L_11 ,
V_111 , V_59 ) ;
}
}
static void
F_106 ( struct V_4 * V_5 , struct V_1 * V_7 )
{
F_10 ( F_107 ( & V_7 -> V_12 ) ) ;
F_108 ( & V_7 -> V_12 ) ;
F_9 ( V_7 ) ;
V_5 -> V_19 -- ;
}
static void F_109 ( struct V_4 * V_5 )
{
struct V_102 * V_103 , * V_50 ;
struct V_1 * V_7 ;
F_98 (tg, pos, n, &td->tg_list, tg_node) {
if ( ! F_110 ( & V_7 -> V_3 ) )
F_106 ( V_5 , V_7 ) ;
}
}
static void F_111 ( struct V_4 * V_5 )
{
F_8 ( V_5 ) ;
}
void F_112 ( void * V_35 , struct V_2 * V_3 )
{
unsigned long V_115 ;
struct V_4 * V_5 = V_35 ;
F_113 ( V_5 -> V_22 -> V_26 , V_115 ) ;
F_106 ( V_5 , F_1 ( V_3 ) ) ;
F_114 ( V_5 -> V_22 -> V_26 , V_115 ) ;
}
static void F_115 ( struct V_4 * V_5 ,
struct V_1 * V_7 )
{
F_96 ( & V_7 -> V_15 , true ) ;
F_96 ( & V_5 -> V_15 , true ) ;
F_67 ( V_5 , 0 ) ;
}
static void F_116 ( void * V_35 ,
struct V_2 * V_3 , T_1 V_116 )
{
struct V_4 * V_5 = V_35 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_7 -> V_16 [ V_30 ] = V_116 ;
F_115 ( V_5 , V_7 ) ;
}
static void F_117 ( void * V_35 ,
struct V_2 * V_3 , T_1 V_117 )
{
struct V_4 * V_5 = V_35 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_7 -> V_16 [ V_31 ] = V_117 ;
F_115 ( V_5 , V_7 ) ;
}
static void F_118 ( void * V_35 ,
struct V_2 * V_3 , unsigned int V_118 )
{
struct V_4 * V_5 = V_35 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_7 -> V_17 [ V_30 ] = V_118 ;
F_115 ( V_5 , V_7 ) ;
}
static void F_119 ( void * V_35 ,
struct V_2 * V_3 , unsigned int V_119 )
{
struct V_4 * V_5 = V_35 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_7 -> V_17 [ V_31 ] = V_119 ;
F_115 ( V_5 , V_7 ) ;
}
static void F_120 ( struct V_39 * V_40 )
{
struct V_4 * V_5 = V_40 -> V_5 ;
F_121 ( & V_5 -> V_110 ) ;
}
int F_122 ( struct V_39 * V_40 , struct V_73 * * V_120 )
{
struct V_4 * V_5 = V_40 -> V_5 ;
struct V_1 * V_7 ;
struct V_73 * V_73 = * V_120 ;
bool V_60 = F_78 ( V_73 ) , V_121 = true ;
struct V_27 * V_28 ;
if ( V_73 -> V_87 & V_94 ) {
V_73 -> V_87 &= ~ V_94 ;
return 0 ;
}
F_39 () ;
V_28 = F_40 ( V_41 ) ;
V_7 = F_36 ( V_5 , V_28 ) ;
if ( V_7 ) {
F_24 ( V_5 , V_7 ) ;
if ( F_81 ( V_7 , V_60 ) ) {
F_86 ( & V_7 -> V_3 , V_73 -> V_82 ,
V_60 , V_73 -> V_87 & V_88 ) ;
F_41 () ;
return 0 ;
}
}
F_41 () ;
F_25 ( V_40 -> V_26 ) ;
V_7 = F_38 ( V_5 ) ;
if ( F_123 ( V_7 ) ) {
if ( F_124 ( V_7 ) == - V_44 ) {
return - V_44 ;
}
}
if ( V_7 -> V_6 [ V_60 ] ) {
V_121 = false ;
goto V_122;
}
if ( F_82 ( V_5 , V_7 , V_73 , NULL ) ) {
F_85 ( V_7 , V_73 ) ;
F_75 ( V_5 , V_7 , V_60 ) ;
goto V_107;
}
V_122:
F_69 ( V_5 , V_7 , L_12
L_13 ,
V_60 == V_30 ? 'R' : 'W' ,
V_7 -> V_61 [ V_60 ] , V_73 -> V_82 , V_7 -> V_16 [ V_60 ] ,
V_7 -> V_62 [ V_60 ] , V_7 -> V_17 [ V_60 ] ,
V_7 -> V_6 [ V_30 ] , V_7 -> V_6 [ V_31 ] ) ;
F_87 ( V_40 -> V_5 , V_7 , V_73 ) ;
* V_120 = NULL ;
if ( V_121 ) {
F_89 ( V_5 , V_7 ) ;
F_65 ( V_5 ) ;
}
V_107:
F_26 ( V_40 -> V_26 ) ;
return 0 ;
}
int F_125 ( struct V_39 * V_40 )
{
struct V_4 * V_5 ;
struct V_1 * V_7 ;
V_5 = F_34 ( sizeof( * V_5 ) , V_123 , V_40 -> V_34 ) ;
if ( ! V_5 )
return - V_124 ;
F_126 ( & V_5 -> V_18 ) ;
V_5 -> V_58 = V_125 ;
V_5 -> V_15 = false ;
F_127 ( & V_5 -> V_110 , F_103 ) ;
V_5 -> V_22 = V_40 ;
V_7 = F_33 ( V_5 ) ;
if ( ! V_7 ) {
F_8 ( V_5 ) ;
return - V_124 ;
}
V_5 -> V_37 = V_7 ;
F_39 () ;
F_27 ( V_5 , V_7 , & V_36 ) ;
F_41 () ;
V_40 -> V_5 = V_5 ;
return 0 ;
}
void F_128 ( struct V_39 * V_40 )
{
struct V_4 * V_5 = V_40 -> V_5 ;
bool V_74 = false ;
F_10 ( ! V_5 ) ;
F_120 ( V_40 ) ;
F_25 ( V_40 -> V_26 ) ;
F_109 ( V_5 ) ;
if ( V_5 -> V_19 > 0 )
V_74 = true ;
F_26 ( V_40 -> V_26 ) ;
if ( V_74 )
F_129 () ;
F_120 ( V_40 ) ;
F_111 ( V_5 ) ;
}
static int T_2 F_130 ( void )
{
V_114 = F_131 ( L_14 , V_126 , 0 ) ;
if ( ! V_114 )
F_132 ( L_15 ) ;
F_133 ( & V_127 ) ;
return 0 ;
}
