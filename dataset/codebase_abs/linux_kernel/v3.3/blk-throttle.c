static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
if ( V_3 )
return F_2 ( V_3 , struct V_1 , V_3 ) ;
return NULL ;
}
static inline unsigned int F_3 ( struct V_4 * V_5 )
{
return V_5 -> V_6 [ 0 ] + V_5 -> V_6 [ 1 ] ;
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
if ( F_39 ( F_40 ( V_40 ) ) )
return NULL ;
F_41 () ;
V_28 = F_42 ( V_41 ) ;
V_7 = F_36 ( V_5 , V_28 ) ;
if ( V_7 ) {
F_43 () ;
return V_7 ;
}
F_43 () ;
F_26 ( V_40 -> V_26 ) ;
V_7 = F_33 ( V_5 ) ;
F_25 ( V_40 -> V_26 ) ;
if ( F_39 ( F_40 ( V_40 ) ) ) {
F_8 ( V_7 ) ;
return NULL ;
}
F_41 () ;
V_28 = F_42 ( V_41 ) ;
V_38 = F_36 ( V_5 , V_28 ) ;
if ( V_38 ) {
F_8 ( V_7 ) ;
F_43 () ;
return V_38 ;
}
if ( ! V_7 ) {
V_7 = V_5 -> V_37 ;
return V_7 ;
}
F_27 ( V_5 , V_7 , V_28 ) ;
F_43 () ;
return V_7 ;
}
static struct V_1 * F_44 ( struct V_42 * V_43 )
{
if ( ! V_43 -> V_44 )
return NULL ;
if ( ! V_43 -> V_45 )
V_43 -> V_45 = F_45 ( & V_43 -> V_46 ) ;
if ( V_43 -> V_45 )
return F_46 ( V_43 -> V_45 ) ;
return NULL ;
}
static void F_47 ( struct V_13 * V_47 , struct V_48 * V_43 )
{
F_48 ( V_47 , V_43 ) ;
F_16 ( V_47 ) ;
}
static void F_49 ( struct V_13 * V_47 , struct V_42 * V_43 )
{
if ( V_43 -> V_45 == V_47 )
V_43 -> V_45 = NULL ;
F_47 ( V_47 , & V_43 -> V_46 ) ;
-- V_43 -> V_44 ;
}
static void F_50 ( struct V_42 * V_49 )
{
struct V_1 * V_7 ;
V_7 = F_44 ( V_49 ) ;
if ( ! V_7 )
return;
V_49 -> V_50 = V_7 -> V_51 ;
}
static void
F_51 ( struct V_42 * V_49 , struct V_1 * V_7 )
{
struct V_13 * * V_34 = & V_49 -> V_46 . V_13 ;
struct V_13 * V_52 = NULL ;
struct V_1 * V_38 ;
unsigned long V_35 = V_7 -> V_51 ;
int V_45 = 1 ;
while ( * V_34 != NULL ) {
V_52 = * V_34 ;
V_38 = F_46 ( V_52 ) ;
if ( F_52 ( V_35 , V_38 -> V_51 ) )
V_34 = & V_52 -> V_53 ;
else {
V_34 = & V_52 -> V_54 ;
V_45 = 0 ;
}
}
if ( V_45 )
V_49 -> V_45 = & V_7 -> V_13 ;
F_53 ( & V_7 -> V_13 , V_52 , V_34 ) ;
F_54 ( & V_7 -> V_13 , & V_49 -> V_46 ) ;
}
static void F_55 ( struct V_4 * V_5 , struct V_1 * V_7 )
{
struct V_42 * V_49 = & V_5 -> V_55 ;
F_51 ( V_49 , V_7 ) ;
F_56 ( V_7 ) ;
V_49 -> V_44 ++ ;
}
static void F_57 ( struct V_4 * V_5 , struct V_1 * V_7 )
{
if ( ! F_58 ( V_7 ) )
F_55 ( V_5 , V_7 ) ;
}
static void F_59 ( struct V_4 * V_5 , struct V_1 * V_7 )
{
F_49 ( & V_7 -> V_13 , & V_5 -> V_55 ) ;
F_60 ( V_7 ) ;
}
static void F_61 ( struct V_4 * V_5 , struct V_1 * V_7 )
{
if ( F_58 ( V_7 ) )
F_59 ( V_5 , V_7 ) ;
}
static void F_62 ( struct V_4 * V_5 )
{
struct V_42 * V_49 = & V_5 -> V_55 ;
if ( ! F_3 ( V_5 ) )
return;
F_10 ( ! V_49 -> V_44 ) ;
F_50 ( V_49 ) ;
if ( F_63 ( V_49 -> V_50 , V_56 ) )
F_64 ( V_5 , 0 ) ;
else
F_64 ( V_5 , ( V_49 -> V_50 - V_56 ) ) ;
}
static inline void
F_65 ( struct V_4 * V_5 , struct V_1 * V_7 , bool V_57 )
{
V_7 -> V_58 [ V_57 ] = 0 ;
V_7 -> V_59 [ V_57 ] = 0 ;
V_7 -> V_60 [ V_57 ] = V_56 ;
V_7 -> V_61 [ V_57 ] = V_56 + V_62 ;
F_66 ( V_5 , V_7 , L_2 ,
V_57 == V_30 ? 'R' : 'W' , V_7 -> V_60 [ V_57 ] ,
V_7 -> V_61 [ V_57 ] , V_56 ) ;
}
static inline void F_67 ( struct V_4 * V_5 ,
struct V_1 * V_7 , bool V_57 , unsigned long V_63 )
{
V_7 -> V_61 [ V_57 ] = F_68 ( V_63 , V_62 ) ;
}
static inline void F_69 ( struct V_4 * V_5 ,
struct V_1 * V_7 , bool V_57 , unsigned long V_63 )
{
V_7 -> V_61 [ V_57 ] = F_68 ( V_63 , V_62 ) ;
F_66 ( V_5 , V_7 , L_3 ,
V_57 == V_30 ? 'R' : 'W' , V_7 -> V_60 [ V_57 ] ,
V_7 -> V_61 [ V_57 ] , V_56 ) ;
}
static bool
F_70 ( struct V_4 * V_5 , struct V_1 * V_7 , bool V_57 )
{
if ( F_71 ( V_56 , V_7 -> V_60 [ V_57 ] , V_7 -> V_61 [ V_57 ] ) )
return 0 ;
return 1 ;
}
static inline void
F_72 ( struct V_4 * V_5 , struct V_1 * V_7 , bool V_57 )
{
unsigned long V_64 , V_65 , V_66 ;
T_1 V_67 , V_68 ;
F_10 ( F_52 ( V_7 -> V_61 [ V_57 ] , V_7 -> V_60 [ V_57 ] ) ) ;
if ( F_70 ( V_5 , V_7 , V_57 ) )
return;
F_67 ( V_5 , V_7 , V_57 , V_56 + V_62 ) ;
V_65 = V_56 - V_7 -> V_60 [ V_57 ] ;
V_64 = V_65 / V_62 ;
if ( ! V_64 )
return;
V_68 = V_7 -> V_16 [ V_57 ] * V_62 * V_64 ;
F_73 ( V_68 , V_69 ) ;
V_67 = V_68 ;
V_66 = ( V_7 -> V_17 [ V_57 ] * V_62 * V_64 ) / V_69 ;
if ( ! V_67 && ! V_66 )
return;
if ( V_7 -> V_58 [ V_57 ] >= V_67 )
V_7 -> V_58 [ V_57 ] -= V_67 ;
else
V_7 -> V_58 [ V_57 ] = 0 ;
if ( V_7 -> V_59 [ V_57 ] >= V_66 )
V_7 -> V_59 [ V_57 ] -= V_66 ;
else
V_7 -> V_59 [ V_57 ] = 0 ;
V_7 -> V_60 [ V_57 ] += V_64 * V_62 ;
F_66 ( V_5 , V_7 , L_4
L_5 ,
V_57 == V_30 ? 'R' : 'W' , V_64 , V_67 , V_66 ,
V_7 -> V_60 [ V_57 ] , V_7 -> V_61 [ V_57 ] , V_56 ) ;
}
static bool F_74 ( struct V_4 * V_5 , struct V_1 * V_7 ,
struct V_70 * V_70 , unsigned long * V_71 )
{
bool V_57 = F_75 ( V_70 ) ;
unsigned int V_72 ;
unsigned long V_73 , V_74 , V_75 ;
T_1 V_68 ;
V_73 = V_75 = V_56 - V_7 -> V_60 [ V_57 ] ;
if ( ! V_73 )
V_75 = V_62 ;
V_75 = F_68 ( V_75 , V_62 ) ;
V_68 = ( T_1 ) V_7 -> V_17 [ V_57 ] * V_75 ;
F_73 ( V_68 , V_69 ) ;
if ( V_68 > V_76 )
V_72 = V_76 ;
else
V_72 = V_68 ;
if ( V_7 -> V_59 [ V_57 ] + 1 <= V_72 ) {
if ( V_71 )
* V_71 = 0 ;
return 1 ;
}
V_74 = ( ( V_7 -> V_59 [ V_57 ] + 1 ) * V_69 ) / V_7 -> V_17 [ V_57 ] + 1 ;
if ( V_74 > V_73 )
V_74 = V_74 - V_73 ;
else
V_74 = 1 ;
if ( V_71 )
* V_71 = V_74 ;
return 0 ;
}
static bool F_76 ( struct V_4 * V_5 , struct V_1 * V_7 ,
struct V_70 * V_70 , unsigned long * V_71 )
{
bool V_57 = F_75 ( V_70 ) ;
T_1 V_77 , V_78 , V_68 ;
unsigned long V_73 , V_74 , V_75 ;
V_73 = V_75 = V_56 - V_7 -> V_60 [ V_57 ] ;
if ( ! V_73 )
V_75 = V_62 ;
V_75 = F_68 ( V_75 , V_62 ) ;
V_68 = V_7 -> V_16 [ V_57 ] * V_75 ;
F_73 ( V_68 , V_69 ) ;
V_77 = V_68 ;
if ( V_7 -> V_58 [ V_57 ] + V_70 -> V_79 <= V_77 ) {
if ( V_71 )
* V_71 = 0 ;
return 1 ;
}
V_78 = V_7 -> V_58 [ V_57 ] + V_70 -> V_79 - V_77 ;
V_74 = F_77 ( V_78 * V_69 , V_7 -> V_16 [ V_57 ] ) ;
if ( ! V_74 )
V_74 = 1 ;
V_74 = V_74 + ( V_75 - V_73 ) ;
if ( V_71 )
* V_71 = V_74 ;
return 0 ;
}
static bool F_78 ( struct V_1 * V_7 , bool V_57 ) {
if ( V_7 -> V_16 [ V_57 ] == - 1 && V_7 -> V_17 [ V_57 ] == - 1 )
return 1 ;
return 0 ;
}
static bool F_79 ( struct V_4 * V_5 , struct V_1 * V_7 ,
struct V_70 * V_70 , unsigned long * V_71 )
{
bool V_57 = F_75 ( V_70 ) ;
unsigned long V_80 = 0 , V_81 = 0 , V_82 = 0 ;
F_10 ( V_7 -> V_6 [ V_57 ] && V_70 != F_80 ( & V_7 -> V_14 [ V_57 ] ) ) ;
if ( V_7 -> V_16 [ V_57 ] == - 1 && V_7 -> V_17 [ V_57 ] == - 1 ) {
if ( V_71 )
* V_71 = 0 ;
return 1 ;
}
if ( F_70 ( V_5 , V_7 , V_57 ) )
F_65 ( V_5 , V_7 , V_57 ) ;
else {
if ( F_52 ( V_7 -> V_61 [ V_57 ] , V_56 + V_62 ) )
F_69 ( V_5 , V_7 , V_57 , V_56 + V_62 ) ;
}
if ( F_76 ( V_5 , V_7 , V_70 , & V_80 )
&& F_74 ( V_5 , V_7 , V_70 , & V_81 ) ) {
if ( V_71 )
* V_71 = 0 ;
return 1 ;
}
V_82 = F_81 ( V_80 , V_81 ) ;
if ( V_71 )
* V_71 = V_82 ;
if ( F_52 ( V_7 -> V_61 [ V_57 ] , V_56 + V_82 ) )
F_69 ( V_5 , V_7 , V_57 , V_56 + V_82 ) ;
return 0 ;
}
static void F_82 ( struct V_1 * V_7 , struct V_70 * V_70 )
{
bool V_57 = F_75 ( V_70 ) ;
bool V_83 = F_83 ( V_70 -> V_84 ) ;
V_7 -> V_58 [ V_57 ] += V_70 -> V_79 ;
V_7 -> V_59 [ V_57 ] ++ ;
F_84 ( & V_7 -> V_3 , V_70 -> V_79 , V_57 , V_83 ) ;
}
static void F_85 ( struct V_4 * V_5 , struct V_1 * V_7 ,
struct V_70 * V_70 )
{
bool V_57 = F_75 ( V_70 ) ;
F_86 ( & V_7 -> V_14 [ V_57 ] , V_70 ) ;
F_4 ( V_7 ) ;
V_7 -> V_6 [ V_57 ] ++ ;
V_5 -> V_6 [ V_57 ] ++ ;
F_57 ( V_5 , V_7 ) ;
}
static void F_87 ( struct V_4 * V_5 , struct V_1 * V_7 )
{
unsigned long V_85 = - 1 , V_86 = - 1 , V_87 = - 1 , V_51 ;
struct V_70 * V_70 ;
if ( ( V_70 = F_80 ( & V_7 -> V_14 [ V_30 ] ) ) )
F_79 ( V_5 , V_7 , V_70 , & V_85 ) ;
if ( ( V_70 = F_80 ( & V_7 -> V_14 [ V_31 ] ) ) )
F_79 ( V_5 , V_7 , V_70 , & V_86 ) ;
V_87 = F_88 ( V_85 , V_86 ) ;
V_51 = V_56 + V_87 ;
F_61 ( V_5 , V_7 ) ;
V_7 -> V_51 = V_51 ;
F_57 ( V_5 , V_7 ) ;
}
static void F_89 ( struct V_4 * V_5 , struct V_1 * V_7 ,
bool V_57 , struct V_88 * V_89 )
{
struct V_70 * V_70 ;
V_70 = F_90 ( & V_7 -> V_14 [ V_57 ] ) ;
V_7 -> V_6 [ V_57 ] -- ;
F_9 ( V_7 ) ;
F_10 ( V_5 -> V_6 [ V_57 ] <= 0 ) ;
V_5 -> V_6 [ V_57 ] -- ;
F_82 ( V_7 , V_70 ) ;
F_86 ( V_89 , V_70 ) ;
V_70 -> V_84 |= V_90 ;
F_72 ( V_5 , V_7 , V_57 ) ;
}
static int F_91 ( struct V_4 * V_5 , struct V_1 * V_7 ,
struct V_88 * V_89 )
{
unsigned int V_91 = 0 , V_92 = 0 ;
unsigned int V_93 = V_94 * 3 / 4 ;
unsigned int V_95 = V_94 - V_93 ;
struct V_70 * V_70 ;
while ( ( V_70 = F_80 ( & V_7 -> V_14 [ V_30 ] ) )
&& F_79 ( V_5 , V_7 , V_70 , NULL ) ) {
F_89 ( V_5 , V_7 , F_75 ( V_70 ) , V_89 ) ;
V_91 ++ ;
if ( V_91 >= V_93 )
break;
}
while ( ( V_70 = F_80 ( & V_7 -> V_14 [ V_31 ] ) )
&& F_79 ( V_5 , V_7 , V_70 , NULL ) ) {
F_89 ( V_5 , V_7 , F_75 ( V_70 ) , V_89 ) ;
V_92 ++ ;
if ( V_92 >= V_95 )
break;
}
return V_91 + V_92 ;
}
static int F_92 ( struct V_4 * V_5 , struct V_88 * V_89 )
{
unsigned int V_96 = 0 ;
struct V_1 * V_7 ;
struct V_42 * V_49 = & V_5 -> V_55 ;
while ( 1 ) {
V_7 = F_44 ( V_49 ) ;
if ( ! V_7 )
break;
if ( F_52 ( V_56 , V_7 -> V_51 ) )
break;
F_61 ( V_5 , V_7 ) ;
V_96 += F_91 ( V_5 , V_7 , V_89 ) ;
if ( V_7 -> V_6 [ 0 ] || V_7 -> V_6 [ 1 ] ) {
F_87 ( V_5 , V_7 ) ;
F_57 ( V_5 , V_7 ) ;
}
if ( V_96 >= V_97 )
break;
}
return V_96 ;
}
static void F_93 ( struct V_4 * V_5 )
{
struct V_1 * V_7 ;
struct V_98 * V_99 , * V_47 ;
if ( ! V_5 -> V_15 )
return;
F_94 ( & V_5 -> V_15 , false ) ;
F_95 ( V_5 , L_6 ) ;
F_96 (tg, pos, n, &td->tg_list, tg_node) {
if ( ! V_7 -> V_15 )
continue;
if ( ! F_94 ( & V_7 -> V_15 , false ) )
continue;
F_66 ( V_5 , V_7 , L_7
L_8 , V_7 -> V_16 [ V_30 ] , V_7 -> V_16 [ V_31 ] ,
V_7 -> V_17 [ V_30 ] , V_7 -> V_17 [ V_31 ] ) ;
F_65 ( V_5 , V_7 , 0 ) ;
F_65 ( V_5 , V_7 , 1 ) ;
if ( F_58 ( V_7 ) )
F_87 ( V_5 , V_7 ) ;
}
}
static int F_97 ( struct V_39 * V_40 )
{
struct V_4 * V_5 = V_40 -> V_5 ;
unsigned int V_96 = 0 ;
struct V_88 V_100 ;
struct V_70 * V_70 ;
struct V_101 V_102 ;
F_25 ( V_40 -> V_26 ) ;
F_93 ( V_5 ) ;
if ( ! F_3 ( V_5 ) )
goto V_103;
F_17 ( & V_100 ) ;
F_95 ( V_5 , L_9 ,
F_3 ( V_5 ) , V_5 -> V_6 [ V_30 ] ,
V_5 -> V_6 [ V_31 ] ) ;
V_96 = F_92 ( V_5 , & V_100 ) ;
if ( V_96 )
F_95 ( V_5 , L_10 , V_96 ) ;
F_62 ( V_5 ) ;
V_103:
F_26 ( V_40 -> V_26 ) ;
if ( V_96 ) {
F_98 ( & V_102 ) ;
while( ( V_70 = F_90 ( & V_100 ) ) )
F_99 ( V_70 ) ;
F_100 ( & V_102 ) ;
}
return V_96 ;
}
void F_101 ( struct V_104 * V_105 )
{
struct V_4 * V_5 = F_2 ( V_105 , struct V_4 ,
V_106 . V_105 ) ;
struct V_39 * V_40 = V_5 -> V_22 ;
F_97 ( V_40 ) ;
}
static void
F_64 ( struct V_4 * V_5 , unsigned long V_107 )
{
struct V_108 * V_109 = & V_5 -> V_106 ;
if ( F_3 ( V_5 ) || V_5 -> V_15 ) {
F_102 ( V_109 ) ;
F_103 ( V_110 , V_109 , V_107 ) ;
F_95 ( V_5 , L_11 ,
V_107 , V_56 ) ;
}
}
static void
F_104 ( struct V_4 * V_5 , struct V_1 * V_7 )
{
F_10 ( F_105 ( & V_7 -> V_12 ) ) ;
F_106 ( & V_7 -> V_12 ) ;
F_9 ( V_7 ) ;
V_5 -> V_19 -- ;
}
static void F_107 ( struct V_4 * V_5 )
{
struct V_98 * V_99 , * V_47 ;
struct V_1 * V_7 ;
F_96 (tg, pos, n, &td->tg_list, tg_node) {
if ( ! F_108 ( & V_7 -> V_3 ) )
F_104 ( V_5 , V_7 ) ;
}
}
void F_109 ( void * V_35 , struct V_2 * V_3 )
{
unsigned long V_111 ;
struct V_4 * V_5 = V_35 ;
F_110 ( V_5 -> V_22 -> V_26 , V_111 ) ;
F_104 ( V_5 , F_1 ( V_3 ) ) ;
F_111 ( V_5 -> V_22 -> V_26 , V_111 ) ;
}
static void F_112 ( struct V_4 * V_5 ,
struct V_1 * V_7 )
{
F_94 ( & V_7 -> V_15 , true ) ;
F_94 ( & V_5 -> V_15 , true ) ;
F_64 ( V_5 , 0 ) ;
}
static void F_113 ( void * V_35 ,
struct V_2 * V_3 , T_1 V_112 )
{
struct V_4 * V_5 = V_35 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_7 -> V_16 [ V_30 ] = V_112 ;
F_112 ( V_5 , V_7 ) ;
}
static void F_114 ( void * V_35 ,
struct V_2 * V_3 , T_1 V_113 )
{
struct V_4 * V_5 = V_35 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_7 -> V_16 [ V_31 ] = V_113 ;
F_112 ( V_5 , V_7 ) ;
}
static void F_115 ( void * V_35 ,
struct V_2 * V_3 , unsigned int V_114 )
{
struct V_4 * V_5 = V_35 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_7 -> V_17 [ V_30 ] = V_114 ;
F_112 ( V_5 , V_7 ) ;
}
static void F_116 ( void * V_35 ,
struct V_2 * V_3 , unsigned int V_115 )
{
struct V_4 * V_5 = V_35 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_7 -> V_17 [ V_31 ] = V_115 ;
F_112 ( V_5 , V_7 ) ;
}
static void F_117 ( struct V_39 * V_40 )
{
struct V_4 * V_5 = V_40 -> V_5 ;
F_118 ( & V_5 -> V_106 ) ;
}
bool F_119 ( struct V_39 * V_40 , struct V_70 * V_70 )
{
struct V_4 * V_5 = V_40 -> V_5 ;
struct V_1 * V_7 ;
bool V_57 = F_75 ( V_70 ) , V_116 = true ;
struct V_27 * V_28 ;
bool V_117 = false ;
if ( V_70 -> V_84 & V_90 ) {
V_70 -> V_84 &= ~ V_90 ;
goto V_103;
}
F_41 () ;
V_28 = F_42 ( V_41 ) ;
V_7 = F_36 ( V_5 , V_28 ) ;
if ( V_7 ) {
F_24 ( V_5 , V_7 ) ;
if ( F_78 ( V_7 , V_57 ) ) {
F_84 ( & V_7 -> V_3 , V_70 -> V_79 ,
V_57 , F_83 ( V_70 -> V_84 ) ) ;
F_43 () ;
goto V_103;
}
}
F_43 () ;
F_25 ( V_40 -> V_26 ) ;
V_7 = F_38 ( V_5 ) ;
if ( F_39 ( ! V_7 ) )
goto V_118;
if ( V_7 -> V_6 [ V_57 ] ) {
V_116 = false ;
goto V_119;
}
if ( F_79 ( V_5 , V_7 , V_70 , NULL ) ) {
F_82 ( V_7 , V_70 ) ;
F_72 ( V_5 , V_7 , V_57 ) ;
goto V_118;
}
V_119:
F_66 ( V_5 , V_7 , L_12
L_13 ,
V_57 == V_30 ? 'R' : 'W' ,
V_7 -> V_58 [ V_57 ] , V_70 -> V_79 , V_7 -> V_16 [ V_57 ] ,
V_7 -> V_59 [ V_57 ] , V_7 -> V_17 [ V_57 ] ,
V_7 -> V_6 [ V_30 ] , V_7 -> V_6 [ V_31 ] ) ;
F_85 ( V_40 -> V_5 , V_7 , V_70 ) ;
V_117 = true ;
if ( V_116 ) {
F_87 ( V_5 , V_7 ) ;
F_62 ( V_5 ) ;
}
V_118:
F_26 ( V_40 -> V_26 ) ;
V_103:
return V_117 ;
}
void F_120 ( struct V_39 * V_40 )
__releases( V_40 -> V_26 ) __acquires( V_40 -> V_26 )
{
struct V_4 * V_5 = V_40 -> V_5 ;
struct V_42 * V_49 = & V_5 -> V_55 ;
struct V_1 * V_7 ;
struct V_88 V_89 ;
struct V_70 * V_70 ;
F_121 ( ! F_122 ( V_40 ) ) ;
F_17 ( & V_89 ) ;
while ( ( V_7 = F_44 ( V_49 ) ) ) {
F_61 ( V_5 , V_7 ) ;
while ( ( V_70 = F_80 ( & V_7 -> V_14 [ V_30 ] ) ) )
F_89 ( V_5 , V_7 , F_75 ( V_70 ) , & V_89 ) ;
while ( ( V_70 = F_80 ( & V_7 -> V_14 [ V_31 ] ) ) )
F_89 ( V_5 , V_7 , F_75 ( V_70 ) , & V_89 ) ;
}
F_26 ( V_40 -> V_26 ) ;
while ( ( V_70 = F_90 ( & V_89 ) ) )
F_99 ( V_70 ) ;
F_25 ( V_40 -> V_26 ) ;
}
int F_123 ( struct V_39 * V_40 )
{
struct V_4 * V_5 ;
struct V_1 * V_7 ;
V_5 = F_34 ( sizeof( * V_5 ) , V_120 , V_40 -> V_34 ) ;
if ( ! V_5 )
return - V_121 ;
F_124 ( & V_5 -> V_18 ) ;
V_5 -> V_55 = V_122 ;
V_5 -> V_15 = false ;
F_125 ( & V_5 -> V_106 , F_101 ) ;
V_5 -> V_22 = V_40 ;
V_7 = F_33 ( V_5 ) ;
if ( ! V_7 ) {
F_8 ( V_5 ) ;
return - V_121 ;
}
V_5 -> V_37 = V_7 ;
F_41 () ;
F_27 ( V_5 , V_7 , & V_36 ) ;
F_43 () ;
V_40 -> V_5 = V_5 ;
return 0 ;
}
void F_126 ( struct V_39 * V_40 )
{
struct V_4 * V_5 = V_40 -> V_5 ;
bool V_71 = false ;
F_10 ( ! V_5 ) ;
F_117 ( V_40 ) ;
F_25 ( V_40 -> V_26 ) ;
F_107 ( V_5 ) ;
if ( V_5 -> V_19 > 0 )
V_71 = true ;
F_26 ( V_40 -> V_26 ) ;
if ( V_71 )
F_127 () ;
F_117 ( V_40 ) ;
}
void F_128 ( struct V_39 * V_40 )
{
F_8 ( V_40 -> V_5 ) ;
}
static int T_2 F_129 ( void )
{
V_110 = F_130 ( L_14 , V_123 , 0 ) ;
if ( ! V_110 )
F_131 ( L_15 ) ;
F_132 ( & V_124 ) ;
return 0 ;
}
