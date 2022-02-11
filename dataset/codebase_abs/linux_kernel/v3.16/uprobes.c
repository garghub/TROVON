static bool F_1 ( struct V_1 * V_2 , bool V_3 )
{
T_1 V_4 = V_5 | V_6 | V_7 ;
if ( V_3 )
V_4 |= V_8 ;
return V_2 -> V_9 && ( V_2 -> V_10 & V_4 ) == V_6 ;
}
static unsigned long F_2 ( struct V_1 * V_2 , T_2 V_11 )
{
return V_2 -> V_12 + V_11 - ( ( T_2 ) V_2 -> V_13 << V_14 ) ;
}
static T_2 F_3 ( struct V_1 * V_2 , unsigned long V_15 )
{
return ( ( T_2 ) V_2 -> V_13 << V_14 ) + ( V_15 - V_2 -> V_12 ) ;
}
static int F_4 ( struct V_1 * V_2 , unsigned long V_16 ,
struct V_17 * V_17 , struct V_17 * V_18 )
{
struct V_19 * V_20 = V_2 -> V_21 ;
T_3 * V_22 ;
T_4 * V_23 ;
int V_24 ;
const unsigned long V_25 = V_16 ;
const unsigned long V_26 = V_16 + V_27 ;
F_5 ( V_17 ) ;
F_6 ( V_20 , V_25 , V_26 ) ;
V_24 = - V_28 ;
V_23 = F_7 ( V_17 , V_20 , V_16 , & V_22 , 0 ) ;
if ( ! V_23 )
goto V_29;
F_8 ( V_18 ) ;
F_9 ( V_18 , V_2 , V_16 ) ;
if ( ! F_10 ( V_17 ) ) {
F_11 ( V_20 , V_30 ) ;
F_12 ( V_20 , V_31 ) ;
}
F_13 ( V_2 , V_16 , F_14 ( * V_23 ) ) ;
F_15 ( V_2 , V_16 , V_23 ) ;
F_16 ( V_20 , V_16 , V_23 , F_17 ( V_18 , V_2 -> V_32 ) ) ;
F_18 ( V_17 ) ;
if ( ! F_19 ( V_17 ) )
F_20 ( V_17 ) ;
F_21 ( V_23 , V_22 ) ;
if ( V_2 -> V_10 & V_33 )
F_22 ( V_17 ) ;
F_23 ( V_17 ) ;
V_24 = 0 ;
V_29:
F_24 ( V_20 , V_25 , V_26 ) ;
F_25 ( V_17 ) ;
return V_24 ;
}
bool __weak F_26 ( T_5 * V_34 )
{
return * V_34 == V_35 ;
}
bool __weak F_27 ( T_5 * V_34 )
{
return F_26 ( V_34 ) ;
}
static void F_28 ( struct V_17 * V_17 , unsigned long V_15 , void * V_36 , int V_37 )
{
void * V_38 = F_29 ( V_17 ) ;
memcpy ( V_36 , V_38 + ( V_15 & ~ V_39 ) , V_37 ) ;
F_30 ( V_38 ) ;
}
static void F_31 ( struct V_17 * V_17 , unsigned long V_15 , const void * V_40 , int V_37 )
{
void * V_38 = F_29 ( V_17 ) ;
memcpy ( V_38 + ( V_15 & ~ V_39 ) , V_40 , V_37 ) ;
F_30 ( V_38 ) ;
}
static int F_32 ( struct V_17 * V_17 , unsigned long V_15 , T_5 * V_41 )
{
T_5 V_42 ;
bool V_43 ;
F_28 ( V_17 , V_15 , & V_42 , V_44 ) ;
V_43 = F_26 ( & V_42 ) ;
if ( F_26 ( V_41 ) ) {
if ( V_43 )
return 0 ;
} else {
if ( ! V_43 )
return 0 ;
}
return 1 ;
}
int F_33 ( struct V_19 * V_20 , unsigned long V_15 ,
T_5 V_45 )
{
struct V_17 * V_46 , * V_47 ;
struct V_1 * V_2 ;
int V_48 ;
V_49:
V_48 = F_34 ( NULL , V_20 , V_15 , 1 , 0 , 1 , & V_46 , & V_2 ) ;
if ( V_48 <= 0 )
return V_48 ;
V_48 = F_32 ( V_46 , V_15 , & V_45 ) ;
if ( V_48 <= 0 )
goto V_50;
V_48 = F_35 ( V_2 ) ;
if ( V_48 )
goto V_50;
V_48 = - V_51 ;
V_47 = F_36 ( V_52 , V_2 , V_15 ) ;
if ( ! V_47 )
goto V_50;
if ( F_37 ( V_47 , V_20 , V_53 ) )
goto V_54;
F_38 ( V_47 ) ;
F_39 ( V_47 , V_46 ) ;
F_31 ( V_47 , V_15 , & V_45 , V_44 ) ;
V_48 = F_4 ( V_2 , V_15 , V_46 , V_47 ) ;
if ( V_48 )
F_40 ( V_47 ) ;
V_54:
F_41 ( V_47 ) ;
V_50:
F_23 ( V_46 ) ;
if ( F_42 ( V_48 == - V_28 ) )
goto V_49;
return V_48 ;
}
int __weak F_43 ( struct V_55 * V_56 , struct V_19 * V_20 , unsigned long V_15 )
{
return F_33 ( V_20 , V_15 , V_35 ) ;
}
int __weak
F_44 ( struct V_55 * V_56 , struct V_19 * V_20 , unsigned long V_15 )
{
return F_33 ( V_20 , V_15 , * ( T_5 * ) & V_56 -> V_34 ) ;
}
static int F_45 ( struct V_57 * V_58 , struct V_57 * V_59 )
{
if ( V_58 -> V_60 < V_59 -> V_60 )
return - 1 ;
if ( V_58 -> V_60 > V_59 -> V_60 )
return 1 ;
if ( V_58 -> V_11 < V_59 -> V_11 )
return - 1 ;
if ( V_58 -> V_11 > V_59 -> V_11 )
return 1 ;
return 0 ;
}
static struct V_57 * F_46 ( struct V_60 * V_60 , T_2 V_11 )
{
struct V_57 V_61 = { . V_60 = V_60 , . V_11 = V_11 } ;
struct V_62 * V_63 = V_64 . V_62 ;
struct V_57 * V_57 ;
int V_65 ;
while ( V_63 ) {
V_57 = F_47 ( V_63 , struct V_57 , V_62 ) ;
V_65 = F_45 ( & V_61 , V_57 ) ;
if ( ! V_65 ) {
F_48 ( & V_57 -> V_66 ) ;
return V_57 ;
}
if ( V_65 < 0 )
V_63 = V_63 -> V_67 ;
else
V_63 = V_63 -> V_68 ;
}
return NULL ;
}
static struct V_57 * F_49 ( struct V_60 * V_60 , T_2 V_11 )
{
struct V_57 * V_57 ;
F_50 ( & V_69 ) ;
V_57 = F_46 ( V_60 , V_11 ) ;
F_51 ( & V_69 ) ;
return V_57 ;
}
static struct V_57 * F_52 ( struct V_57 * V_57 )
{
struct V_62 * * V_70 = & V_64 . V_62 ;
struct V_62 * V_71 = NULL ;
struct V_57 * V_61 ;
int V_65 ;
while ( * V_70 ) {
V_71 = * V_70 ;
V_61 = F_47 ( V_71 , struct V_57 , V_62 ) ;
V_65 = F_45 ( V_57 , V_61 ) ;
if ( ! V_65 ) {
F_48 ( & V_61 -> V_66 ) ;
return V_61 ;
}
if ( V_65 < 0 )
V_70 = & V_71 -> V_67 ;
else
V_70 = & V_71 -> V_68 ;
}
V_61 = NULL ;
F_53 ( & V_57 -> V_62 , V_71 , V_70 ) ;
F_54 ( & V_57 -> V_62 , & V_64 ) ;
F_55 ( & V_57 -> V_66 , 2 ) ;
return V_61 ;
}
static struct V_57 * F_56 ( struct V_57 * V_57 )
{
struct V_57 * V_61 ;
F_50 ( & V_69 ) ;
V_61 = F_52 ( V_57 ) ;
F_51 ( & V_69 ) ;
return V_61 ;
}
static void F_57 ( struct V_57 * V_57 )
{
if ( F_58 ( & V_57 -> V_66 ) )
F_59 ( V_57 ) ;
}
static struct V_57 * F_60 ( struct V_60 * V_60 , T_2 V_11 )
{
struct V_57 * V_57 , * V_72 ;
V_57 = F_61 ( sizeof( struct V_57 ) , V_53 ) ;
if ( ! V_57 )
return NULL ;
V_57 -> V_60 = F_62 ( V_60 ) ;
V_57 -> V_11 = V_11 ;
F_63 ( & V_57 -> V_73 ) ;
F_63 ( & V_57 -> V_74 ) ;
V_72 = F_56 ( V_57 ) ;
if ( V_72 ) {
F_59 ( V_57 ) ;
V_57 = V_72 ;
F_64 ( V_60 ) ;
}
return V_57 ;
}
static void F_65 ( struct V_57 * V_57 , struct V_75 * V_76 )
{
F_66 ( & V_57 -> V_74 ) ;
V_76 -> V_77 = V_57 -> V_78 ;
V_57 -> V_78 = V_76 ;
F_67 ( & V_57 -> V_74 ) ;
}
static bool F_68 ( struct V_57 * V_57 , struct V_75 * V_76 )
{
struct V_75 * * V_79 ;
bool V_48 = false ;
F_66 ( & V_57 -> V_74 ) ;
for ( V_79 = & V_57 -> V_78 ; * V_79 ; V_79 = & ( * V_79 ) -> V_77 ) {
if ( * V_79 == V_76 ) {
* V_79 = V_76 -> V_77 ;
V_48 = true ;
break;
}
}
F_67 ( & V_57 -> V_74 ) ;
return V_48 ;
}
static int F_69 ( struct V_80 * V_81 , struct V_82 * V_83 ,
void * V_34 , int V_84 , T_2 V_11 )
{
struct V_17 * V_17 ;
if ( V_81 -> V_85 -> V_86 )
V_17 = F_70 ( V_81 , V_11 >> V_87 , V_83 ) ;
else
V_17 = F_71 ( V_81 , V_11 >> V_87 ) ;
if ( F_72 ( V_17 ) )
return F_73 ( V_17 ) ;
F_28 ( V_17 , V_11 , V_34 , V_84 ) ;
F_41 ( V_17 ) ;
return 0 ;
}
static int F_74 ( struct V_57 * V_57 , struct V_82 * V_83 )
{
struct V_80 * V_81 = V_57 -> V_60 -> V_88 ;
T_2 V_89 = V_57 -> V_11 ;
void * V_34 = & V_57 -> V_90 . V_34 ;
int V_91 = sizeof( V_57 -> V_90 . V_34 ) ;
int V_37 , V_24 = - V_92 ;
do {
if ( V_89 >= F_75 ( V_57 -> V_60 ) )
break;
V_37 = F_76 ( int , V_91 , V_27 - ( V_89 & ~ V_39 ) ) ;
V_24 = F_69 ( V_81 , V_83 , V_34 , V_37 , V_89 ) ;
if ( V_24 )
break;
V_34 += V_37 ;
V_89 += V_37 ;
V_91 -= V_37 ;
} while ( V_91 );
return V_24 ;
}
static int F_77 ( struct V_57 * V_57 , struct V_82 * V_82 ,
struct V_19 * V_20 , unsigned long V_15 )
{
int V_48 = 0 ;
if ( F_78 ( V_93 , & V_57 -> V_4 ) )
return V_48 ;
F_66 ( & V_57 -> V_74 ) ;
if ( F_78 ( V_93 , & V_57 -> V_4 ) )
goto V_94;
V_48 = F_74 ( V_57 , V_82 ) ;
if ( V_48 )
goto V_94;
V_48 = - V_95 ;
if ( F_27 ( ( T_5 * ) & V_57 -> V_90 . V_34 ) )
goto V_94;
V_48 = F_79 ( & V_57 -> V_90 , V_20 , V_15 ) ;
if ( V_48 )
goto V_94;
F_80 ( ( V_57 -> V_11 & ~ V_39 ) +
V_44 > V_27 ) ;
F_81 () ;
F_82 ( V_93 , & V_57 -> V_4 ) ;
V_94:
F_67 ( & V_57 -> V_74 ) ;
return V_48 ;
}
static inline bool F_83 ( struct V_75 * V_76 ,
enum V_96 V_97 , struct V_19 * V_20 )
{
return ! V_76 -> V_98 || V_76 -> V_98 ( V_76 , V_97 , V_20 ) ;
}
static bool F_84 ( struct V_57 * V_57 ,
enum V_96 V_97 , struct V_19 * V_20 )
{
struct V_75 * V_76 ;
bool V_48 = false ;
F_85 ( & V_57 -> V_74 ) ;
for ( V_76 = V_57 -> V_78 ; V_76 ; V_76 = V_76 -> V_77 ) {
V_48 = F_83 ( V_76 , V_97 , V_20 ) ;
if ( V_48 )
break;
}
F_86 ( & V_57 -> V_74 ) ;
return V_48 ;
}
static int
F_87 ( struct V_57 * V_57 , struct V_19 * V_20 ,
struct V_1 * V_2 , unsigned long V_15 )
{
bool V_99 ;
int V_48 ;
V_48 = F_77 ( V_57 , V_2 -> V_9 , V_20 , V_15 ) ;
if ( V_48 )
return V_48 ;
V_99 = ! F_78 ( V_100 , & V_20 -> V_4 ) ;
if ( V_99 )
F_82 ( V_100 , & V_20 -> V_4 ) ;
V_48 = F_43 ( & V_57 -> V_90 , V_20 , V_15 ) ;
if ( ! V_48 )
F_88 ( V_101 , & V_20 -> V_4 ) ;
else if ( V_99 )
F_88 ( V_100 , & V_20 -> V_4 ) ;
return V_48 ;
}
static int
F_89 ( struct V_57 * V_57 , struct V_19 * V_20 , unsigned long V_15 )
{
F_82 ( V_101 , & V_20 -> V_4 ) ;
return F_44 ( & V_57 -> V_90 , V_20 , V_15 ) ;
}
static inline bool F_90 ( struct V_57 * V_57 )
{
return ! F_91 ( & V_57 -> V_62 ) ;
}
static void F_92 ( struct V_57 * V_57 )
{
if ( F_93 ( ! F_90 ( V_57 ) ) )
return;
F_50 ( & V_69 ) ;
F_94 ( & V_57 -> V_62 , & V_64 ) ;
F_51 ( & V_69 ) ;
F_95 ( & V_57 -> V_62 ) ;
F_64 ( V_57 -> V_60 ) ;
F_57 ( V_57 ) ;
}
static inline struct V_102 * F_96 ( struct V_102 * V_103 )
{
struct V_102 * V_77 = V_103 -> V_77 ;
F_59 ( V_103 ) ;
return V_77 ;
}
static struct V_102 *
F_97 ( struct V_80 * V_81 , T_2 V_11 , bool V_3 )
{
unsigned long V_104 = V_11 >> V_14 ;
struct V_1 * V_2 ;
struct V_102 * V_105 = NULL ;
struct V_102 * V_106 = NULL ;
struct V_102 * V_103 ;
int V_107 = 0 ;
V_108:
F_98 ( & V_81 -> V_109 ) ;
F_99 (vma, &mapping->i_mmap, pgoff, pgoff) {
if ( ! F_1 ( V_2 , V_3 ) )
continue;
if ( ! V_106 && ! V_107 ) {
V_106 = F_100 ( sizeof( struct V_102 ) ,
V_110 | V_111 | V_112 ) ;
if ( V_106 )
V_106 -> V_77 = NULL ;
}
if ( ! V_106 ) {
V_107 ++ ;
continue;
}
if ( ! F_101 ( & V_2 -> V_21 -> V_113 ) )
continue;
V_103 = V_106 ;
V_106 = V_106 -> V_77 ;
V_103 -> V_77 = V_105 ;
V_105 = V_103 ;
V_103 -> V_20 = V_2 -> V_21 ;
V_103 -> V_15 = F_2 ( V_2 , V_11 ) ;
}
F_102 ( & V_81 -> V_109 ) ;
if ( ! V_107 )
goto V_94;
V_106 = V_105 ;
while ( V_105 ) {
F_103 ( V_105 -> V_20 ) ;
V_105 = V_105 -> V_77 ;
}
do {
V_103 = F_100 ( sizeof( struct V_102 ) , V_53 ) ;
if ( ! V_103 ) {
V_105 = F_104 ( - V_51 ) ;
goto V_94;
}
V_103 -> V_77 = V_106 ;
V_106 = V_103 ;
} while ( -- V_107 );
goto V_108;
V_94:
while ( V_106 )
V_106 = F_96 ( V_106 ) ;
return V_105 ;
}
static int
F_105 ( struct V_57 * V_57 , struct V_75 * V_114 )
{
bool V_3 = ! ! V_114 ;
struct V_102 * V_103 ;
int V_24 = 0 ;
F_106 ( & V_115 ) ;
V_103 = F_97 ( V_57 -> V_60 -> V_88 ,
V_57 -> V_11 , V_3 ) ;
if ( F_72 ( V_103 ) ) {
V_24 = F_73 ( V_103 ) ;
goto V_94;
}
while ( V_103 ) {
struct V_19 * V_20 = V_103 -> V_20 ;
struct V_1 * V_2 ;
if ( V_24 && V_3 )
goto free;
F_66 ( & V_20 -> V_116 ) ;
V_2 = F_107 ( V_20 , V_103 -> V_15 ) ;
if ( ! V_2 || ! F_1 ( V_2 , V_3 ) ||
F_108 ( V_2 -> V_9 ) != V_57 -> V_60 )
goto V_29;
if ( V_2 -> V_12 > V_103 -> V_15 ||
F_3 ( V_2 , V_103 -> V_15 ) != V_57 -> V_11 )
goto V_29;
if ( V_3 ) {
if ( F_83 ( V_114 ,
V_117 , V_20 ) )
V_24 = F_87 ( V_57 , V_20 , V_2 , V_103 -> V_15 ) ;
} else if ( F_78 ( V_100 , & V_20 -> V_4 ) ) {
if ( ! F_84 ( V_57 ,
V_118 , V_20 ) )
V_24 |= F_89 ( V_57 , V_20 , V_103 -> V_15 ) ;
}
V_29:
F_67 ( & V_20 -> V_116 ) ;
free:
F_103 ( V_20 ) ;
V_103 = F_96 ( V_103 ) ;
}
V_94:
F_109 ( & V_115 ) ;
return V_24 ;
}
static int F_110 ( struct V_57 * V_57 , struct V_75 * V_76 )
{
F_65 ( V_57 , V_76 ) ;
return F_105 ( V_57 , V_76 ) ;
}
static void F_111 ( struct V_57 * V_57 , struct V_75 * V_76 )
{
int V_24 ;
if ( F_93 ( ! F_68 ( V_57 , V_76 ) ) )
return;
V_24 = F_105 ( V_57 , NULL ) ;
if ( ! V_57 -> V_78 && ! V_24 )
F_92 ( V_57 ) ;
}
int F_112 ( struct V_60 * V_60 , T_2 V_11 , struct V_75 * V_76 )
{
struct V_57 * V_57 ;
int V_48 ;
if ( ! V_76 -> V_119 && ! V_76 -> V_120 )
return - V_121 ;
if ( ! V_60 -> V_88 -> V_85 -> V_86 && ! F_113 ( V_60 -> V_88 ) )
return - V_92 ;
if ( V_11 > F_75 ( V_60 ) )
return - V_121 ;
V_49:
V_57 = F_60 ( V_60 , V_11 ) ;
if ( ! V_57 )
return - V_51 ;
F_66 ( & V_57 -> V_73 ) ;
V_48 = - V_28 ;
if ( F_114 ( F_90 ( V_57 ) ) ) {
V_48 = F_110 ( V_57 , V_76 ) ;
if ( V_48 )
F_111 ( V_57 , V_76 ) ;
}
F_67 ( & V_57 -> V_73 ) ;
F_57 ( V_57 ) ;
if ( F_42 ( V_48 == - V_28 ) )
goto V_49;
return V_48 ;
}
int F_115 ( struct V_60 * V_60 , T_2 V_11 ,
struct V_75 * V_76 , bool V_122 )
{
struct V_57 * V_57 ;
struct V_75 * V_79 ;
int V_48 = - V_123 ;
V_57 = F_49 ( V_60 , V_11 ) ;
if ( F_93 ( ! V_57 ) )
return V_48 ;
F_66 ( & V_57 -> V_73 ) ;
for ( V_79 = V_57 -> V_78 ; V_79 && V_79 != V_76 ; V_79 = V_79 -> V_77 )
;
if ( V_79 )
V_48 = F_105 ( V_57 , V_122 ? V_76 : NULL ) ;
F_67 ( & V_57 -> V_73 ) ;
F_57 ( V_57 ) ;
return V_48 ;
}
void F_116 ( struct V_60 * V_60 , T_2 V_11 , struct V_75 * V_76 )
{
struct V_57 * V_57 ;
V_57 = F_49 ( V_60 , V_11 ) ;
if ( F_93 ( ! V_57 ) )
return;
F_66 ( & V_57 -> V_73 ) ;
F_111 ( V_57 , V_76 ) ;
F_67 ( & V_57 -> V_73 ) ;
F_57 ( V_57 ) ;
}
static int F_117 ( struct V_57 * V_57 , struct V_19 * V_20 )
{
struct V_1 * V_2 ;
int V_24 = 0 ;
F_85 ( & V_20 -> V_116 ) ;
for ( V_2 = V_20 -> V_124 ; V_2 ; V_2 = V_2 -> V_125 ) {
unsigned long V_15 ;
T_2 V_11 ;
if ( ! F_1 ( V_2 , false ) ||
F_108 ( V_2 -> V_9 ) != V_57 -> V_60 )
continue;
V_11 = ( T_2 ) V_2 -> V_13 << V_14 ;
if ( V_57 -> V_11 < V_11 ||
V_57 -> V_11 >= V_11 + V_2 -> V_126 - V_2 -> V_12 )
continue;
V_15 = F_2 ( V_2 , V_57 -> V_11 ) ;
V_24 |= F_89 ( V_57 , V_20 , V_15 ) ;
}
F_86 ( & V_20 -> V_116 ) ;
return V_24 ;
}
static struct V_62 *
F_118 ( struct V_60 * V_60 , T_2 V_127 , T_2 V_128 )
{
struct V_62 * V_63 = V_64 . V_62 ;
while ( V_63 ) {
struct V_57 * V_61 = F_47 ( V_63 , struct V_57 , V_62 ) ;
if ( V_60 < V_61 -> V_60 ) {
V_63 = V_63 -> V_67 ;
} else if ( V_60 > V_61 -> V_60 ) {
V_63 = V_63 -> V_68 ;
} else {
if ( V_128 < V_61 -> V_11 )
V_63 = V_63 -> V_67 ;
else if ( V_127 > V_61 -> V_11 )
V_63 = V_63 -> V_68 ;
else
break;
}
}
return V_63 ;
}
static void F_119 ( struct V_60 * V_60 ,
struct V_1 * V_2 ,
unsigned long V_129 , unsigned long V_130 ,
struct V_131 * V_132 )
{
T_2 V_127 , V_128 ;
struct V_62 * V_63 , * V_133 ;
struct V_57 * V_61 ;
F_120 ( V_132 ) ;
V_127 = F_3 ( V_2 , V_129 ) ;
V_128 = V_127 + ( V_130 - V_129 ) - 1 ;
F_50 ( & V_69 ) ;
V_63 = F_118 ( V_60 , V_127 , V_128 ) ;
if ( V_63 ) {
for ( V_133 = V_63 ; V_133 ; V_133 = F_121 ( V_133 ) ) {
V_61 = F_47 ( V_133 , struct V_57 , V_62 ) ;
if ( V_61 -> V_60 != V_60 || V_61 -> V_11 < V_127 )
break;
F_122 ( & V_61 -> V_134 , V_132 ) ;
F_48 ( & V_61 -> V_66 ) ;
}
for ( V_133 = V_63 ; ( V_133 = F_123 ( V_133 ) ) ; ) {
V_61 = F_47 ( V_133 , struct V_57 , V_62 ) ;
if ( V_61 -> V_60 != V_60 || V_61 -> V_11 > V_128 )
break;
F_122 ( & V_61 -> V_134 , V_132 ) ;
F_48 ( & V_61 -> V_66 ) ;
}
}
F_51 ( & V_69 ) ;
}
int F_124 ( struct V_1 * V_2 )
{
struct V_131 V_135 ;
struct V_57 * V_57 , * V_61 ;
struct V_60 * V_60 ;
if ( F_125 () || ! F_1 ( V_2 , true ) )
return 0 ;
V_60 = F_108 ( V_2 -> V_9 ) ;
if ( ! V_60 )
return 0 ;
F_98 ( F_126 ( V_60 ) ) ;
F_119 ( V_60 , V_2 , V_2 -> V_12 , V_2 -> V_126 , & V_135 ) ;
F_127 (uprobe, u, &tmp_list, pending_list) {
if ( ! F_128 ( V_136 ) &&
F_84 ( V_57 , V_137 , V_2 -> V_21 ) ) {
unsigned long V_15 = F_2 ( V_2 , V_57 -> V_11 ) ;
F_87 ( V_57 , V_2 -> V_21 , V_2 , V_15 ) ;
}
F_57 ( V_57 ) ;
}
F_102 ( F_126 ( V_60 ) ) ;
return 0 ;
}
static bool
F_129 ( struct V_1 * V_2 , unsigned long V_129 , unsigned long V_130 )
{
T_2 V_127 , V_128 ;
struct V_60 * V_60 ;
struct V_62 * V_63 ;
V_60 = F_108 ( V_2 -> V_9 ) ;
V_127 = F_3 ( V_2 , V_129 ) ;
V_128 = V_127 + ( V_130 - V_129 ) - 1 ;
F_50 ( & V_69 ) ;
V_63 = F_118 ( V_60 , V_127 , V_128 ) ;
F_51 ( & V_69 ) ;
return ! ! V_63 ;
}
void F_130 ( struct V_1 * V_2 , unsigned long V_129 , unsigned long V_130 )
{
if ( F_125 () || ! F_1 ( V_2 , false ) )
return;
if ( ! F_131 ( & V_2 -> V_21 -> V_113 ) )
return;
if ( ! F_78 ( V_100 , & V_2 -> V_21 -> V_4 ) ||
F_78 ( V_101 , & V_2 -> V_21 -> V_4 ) )
return;
if ( F_129 ( V_2 , V_129 , V_130 ) )
F_82 ( V_101 , & V_2 -> V_21 -> V_4 ) ;
}
static int F_132 ( struct V_19 * V_20 , struct V_138 * V_139 )
{
int V_48 = - V_140 ;
F_66 ( & V_20 -> V_116 ) ;
if ( V_20 -> V_141 . V_138 )
goto V_142;
if ( ! V_139 -> V_15 ) {
V_139 -> V_15 = F_133 ( NULL , V_143 - V_27 ,
V_27 , 0 , 0 ) ;
if ( V_139 -> V_15 & ~ V_39 ) {
V_48 = V_139 -> V_15 ;
goto V_142;
}
}
V_48 = F_134 ( V_20 , V_139 -> V_15 , V_27 ,
V_144 | V_6 | V_145 | V_146 , & V_139 -> V_17 ) ;
if ( V_48 )
goto V_142;
F_81 () ;
V_20 -> V_141 . V_138 = V_139 ;
V_142:
F_67 ( & V_20 -> V_116 ) ;
return V_48 ;
}
static struct V_138 * F_135 ( unsigned long V_15 )
{
struct V_19 * V_20 = V_136 -> V_20 ;
T_5 V_34 = V_35 ;
struct V_138 * V_139 ;
V_139 = F_100 ( sizeof( * V_139 ) , V_53 ) ;
if ( F_42 ( ! V_139 ) )
goto V_94;
V_139 -> V_147 = F_61 ( F_136 ( V_148 ) * sizeof( long ) , V_53 ) ;
if ( ! V_139 -> V_147 )
goto V_149;
V_139 -> V_17 = F_137 ( V_150 ) ;
if ( ! V_139 -> V_17 )
goto V_151;
V_139 -> V_15 = V_15 ;
F_138 ( & V_139 -> V_152 ) ;
F_82 ( 0 , V_139 -> V_147 ) ;
F_55 ( & V_139 -> V_153 , 1 ) ;
F_31 ( V_139 -> V_17 , 0 , & V_34 , V_44 ) ;
if ( ! F_132 ( V_20 , V_139 ) )
return V_139 ;
F_139 ( V_139 -> V_17 ) ;
V_151:
F_59 ( V_139 -> V_147 ) ;
V_149:
F_59 ( V_139 ) ;
V_94:
return NULL ;
}
static struct V_138 * F_140 ( void )
{
struct V_19 * V_20 = V_136 -> V_20 ;
struct V_138 * V_139 ;
if ( ! V_20 -> V_141 . V_138 )
F_135 ( 0 ) ;
V_139 = V_20 -> V_141 . V_138 ;
F_141 () ;
return V_139 ;
}
void F_142 ( struct V_19 * V_20 )
{
struct V_138 * V_139 = V_20 -> V_141 . V_138 ;
if ( ! V_139 )
return;
F_23 ( V_139 -> V_17 ) ;
F_59 ( V_139 -> V_147 ) ;
F_59 ( V_139 ) ;
}
void F_143 ( void )
{
F_144 ( & V_115 ) ;
}
void F_145 ( void )
{
F_146 ( & V_115 ) ;
}
void F_147 ( struct V_19 * V_154 , struct V_19 * V_155 )
{
V_155 -> V_141 . V_138 = NULL ;
if ( F_78 ( V_100 , & V_154 -> V_4 ) ) {
F_82 ( V_100 , & V_155 -> V_4 ) ;
F_82 ( V_101 , & V_155 -> V_4 ) ;
}
}
static unsigned long F_148 ( struct V_138 * V_139 )
{
unsigned long V_156 ;
int V_157 ;
do {
V_157 = F_149 ( V_139 -> V_147 , V_148 ) ;
if ( V_157 < V_148 ) {
if ( ! F_150 ( V_157 , V_139 -> V_147 ) )
break;
V_157 = V_148 ;
continue;
}
F_151 ( V_139 -> V_152 , ( F_131 ( & V_139 -> V_153 ) < V_148 ) ) ;
} while ( V_157 >= V_148 );
V_156 = V_139 -> V_15 + ( V_157 * V_158 ) ;
F_48 ( & V_139 -> V_153 ) ;
return V_156 ;
}
static unsigned long F_152 ( struct V_57 * V_57 )
{
struct V_138 * V_139 ;
unsigned long V_159 ;
V_139 = F_140 () ;
if ( ! V_139 )
return 0 ;
V_159 = F_148 ( V_139 ) ;
if ( F_42 ( ! V_159 ) )
return 0 ;
F_153 ( V_139 -> V_17 , V_159 ,
& V_57 -> V_90 . V_160 , sizeof( V_57 -> V_90 . V_160 ) ) ;
return V_159 ;
}
static void F_154 ( struct V_161 * V_162 )
{
struct V_138 * V_139 ;
unsigned long V_163 ;
unsigned long V_156 ;
if ( ! V_162 -> V_20 || ! V_162 -> V_20 -> V_141 . V_138 || ! V_162 -> V_164 )
return;
V_156 = V_162 -> V_164 -> V_159 ;
if ( F_42 ( ! V_156 ) )
return;
V_139 = V_162 -> V_20 -> V_141 . V_138 ;
V_163 = V_139 -> V_15 + V_27 ;
if ( V_139 -> V_15 <= V_156 && V_156 < V_163 ) {
unsigned long V_11 ;
int V_157 ;
V_11 = V_156 - V_139 -> V_15 ;
V_157 = V_11 / V_158 ;
if ( V_157 >= V_148 )
return;
F_88 ( V_157 , V_139 -> V_147 ) ;
F_155 ( & V_139 -> V_153 ) ;
if ( F_156 ( & V_139 -> V_152 ) )
F_157 ( & V_139 -> V_152 ) ;
V_162 -> V_164 -> V_159 = 0 ;
}
}
void __weak F_153 ( struct V_17 * V_17 , unsigned long V_15 ,
void * V_40 , unsigned long V_37 )
{
F_31 ( V_17 , V_15 , V_40 , V_37 ) ;
F_158 ( V_17 ) ;
}
unsigned long __weak F_159 ( struct V_165 * V_166 )
{
return F_160 ( V_166 ) - V_44 ;
}
unsigned long F_161 ( struct V_165 * V_166 )
{
struct V_167 * V_164 = V_136 -> V_164 ;
if ( F_42 ( V_164 && V_164 -> V_168 ) )
return V_164 -> V_15 ;
return F_160 ( V_166 ) ;
}
void F_162 ( struct V_161 * V_133 )
{
struct V_167 * V_164 = V_133 -> V_164 ;
struct V_169 * V_170 , * V_171 ;
if ( ! V_164 )
return;
if ( V_164 -> V_168 )
F_57 ( V_164 -> V_168 ) ;
V_170 = V_164 -> V_172 ;
while ( V_170 ) {
V_171 = V_170 ;
V_170 = V_170 -> V_77 ;
F_57 ( V_171 -> V_57 ) ;
F_59 ( V_171 ) ;
}
F_154 ( V_133 ) ;
F_59 ( V_164 ) ;
V_133 -> V_164 = NULL ;
}
static struct V_167 * F_163 ( void )
{
if ( ! V_136 -> V_164 )
V_136 -> V_164 = F_61 ( sizeof( struct V_167 ) , V_53 ) ;
return V_136 -> V_164 ;
}
static int F_164 ( struct V_161 * V_133 , struct V_167 * V_173 )
{
struct V_167 * V_174 ;
struct V_169 * * V_70 , * V_175 , * V_63 ;
V_174 = F_61 ( sizeof( struct V_167 ) , V_53 ) ;
if ( ! V_174 )
return - V_51 ;
V_133 -> V_164 = V_174 ;
V_70 = & V_174 -> V_172 ;
for ( V_175 = V_173 -> V_172 ; V_175 ; V_175 = V_175 -> V_77 ) {
V_63 = F_100 ( sizeof( struct V_169 ) , V_53 ) ;
if ( ! V_63 )
return - V_51 ;
* V_63 = * V_175 ;
F_48 ( & V_63 -> V_57 -> V_66 ) ;
V_63 -> V_77 = NULL ;
* V_70 = V_63 ;
V_70 = & V_63 -> V_77 ;
V_174 -> V_176 ++ ;
}
return 0 ;
}
static void F_165 ( struct V_161 * V_133 , const char * V_177 )
{
F_166 ( L_1 ,
V_136 -> V_178 , V_136 -> V_179 , V_177 ) ;
}
static void F_167 ( struct V_180 * V_181 )
{
if ( V_136 -> V_4 & V_182 )
return;
if ( ! F_135 ( V_136 -> V_164 -> V_183 ) )
F_165 ( V_136 , L_2 ) ;
}
void F_168 ( struct V_161 * V_133 , unsigned long V_4 )
{
struct V_167 * V_164 = V_136 -> V_164 ;
struct V_19 * V_20 = V_136 -> V_20 ;
struct V_138 * V_139 ;
V_133 -> V_164 = NULL ;
if ( ! V_164 || ! V_164 -> V_172 )
return;
if ( V_20 == V_133 -> V_20 && ! ( V_4 & V_184 ) )
return;
if ( F_164 ( V_133 , V_164 ) )
return F_165 ( V_133 , L_3 ) ;
V_139 = V_20 -> V_141 . V_138 ;
if ( ! V_139 )
return F_165 ( V_133 , L_2 ) ;
if ( V_20 == V_133 -> V_20 )
return;
V_133 -> V_164 -> V_183 = V_139 -> V_15 ;
F_169 ( & V_133 -> V_164 -> F_167 , F_167 ) ;
F_170 ( V_133 , & V_133 -> V_164 -> F_167 , true ) ;
}
static unsigned long F_171 ( void )
{
struct V_138 * V_139 ;
unsigned long V_185 = - 1 ;
V_139 = V_136 -> V_20 -> V_141 . V_138 ;
F_141 () ;
if ( V_139 )
V_185 = V_139 -> V_15 ;
return V_185 ;
}
static void F_172 ( struct V_57 * V_57 , struct V_165 * V_166 )
{
struct V_169 * V_170 ;
struct V_167 * V_164 ;
unsigned long V_186 , V_185 ;
bool V_187 = false ;
if ( ! F_140 () )
return;
V_164 = F_163 () ;
if ( ! V_164 )
return;
if ( V_164 -> V_176 >= V_188 ) {
F_173 ( V_189 L_4
L_5 ,
V_136 -> V_179 , V_136 -> V_190 ) ;
return;
}
V_170 = F_61 ( sizeof( struct V_169 ) , V_53 ) ;
if ( ! V_170 )
goto V_142;
V_185 = F_171 () ;
V_186 = F_174 ( V_185 , V_166 ) ;
if ( V_186 == - 1 )
goto V_142;
if ( V_186 == V_185 ) {
if ( ! V_164 -> V_172 ) {
F_166 ( L_6 ,
V_136 -> V_179 , V_136 -> V_190 ) ;
goto V_142;
}
V_187 = true ;
V_186 = V_164 -> V_172 -> V_186 ;
}
F_48 ( & V_57 -> V_66 ) ;
V_170 -> V_57 = V_57 ;
V_170 -> V_191 = F_160 ( V_166 ) ;
V_170 -> V_186 = V_186 ;
V_170 -> V_187 = V_187 ;
V_164 -> V_176 ++ ;
V_170 -> V_77 = V_164 -> V_172 ;
V_164 -> V_172 = V_170 ;
return;
V_142:
F_59 ( V_170 ) ;
}
static int
F_175 ( struct V_57 * V_57 , struct V_165 * V_166 , unsigned long V_192 )
{
struct V_167 * V_164 ;
unsigned long V_159 ;
int V_24 ;
V_164 = F_163 () ;
if ( ! V_164 )
return - V_51 ;
V_159 = F_152 ( V_57 ) ;
if ( ! V_159 )
return - V_51 ;
V_164 -> V_159 = V_159 ;
V_164 -> V_15 = V_192 ;
V_24 = F_176 ( & V_57 -> V_90 , V_166 ) ;
if ( F_42 ( V_24 ) ) {
F_154 ( V_136 ) ;
return V_24 ;
}
V_164 -> V_168 = V_57 ;
V_164 -> V_193 = V_194 ;
return 0 ;
}
bool F_177 ( void )
{
struct V_161 * V_133 = V_136 ;
struct V_167 * V_164 = V_133 -> V_164 ;
if ( F_114 ( ! V_164 || ! V_164 -> V_168 ) )
return false ;
F_178 ( V_164 -> V_193 != V_194 ) ;
if ( F_179 ( V_133 ) ) {
F_180 ( & V_133 -> V_195 -> V_196 ) ;
F_181 ( V_133 , V_197 ) ;
F_182 ( & V_133 -> V_195 -> V_196 ) ;
if ( F_183 ( V_133 ) || F_184 ( V_133 ) ) {
V_164 -> V_193 = V_198 ;
F_185 ( V_133 , V_199 ) ;
F_185 ( V_133 , V_200 ) ;
}
}
return true ;
}
static void F_186 ( struct V_19 * V_20 )
{
struct V_1 * V_2 ;
for ( V_2 = V_20 -> V_124 ; V_2 ; V_2 = V_2 -> V_125 ) {
if ( ! F_1 ( V_2 , false ) )
continue;
if ( F_129 ( V_2 , V_2 -> V_12 , V_2 -> V_126 ) )
return;
}
F_88 ( V_100 , & V_20 -> V_4 ) ;
}
static int F_187 ( struct V_19 * V_20 , unsigned long V_15 )
{
struct V_17 * V_17 ;
T_5 V_45 ;
int V_201 ;
F_188 () ;
V_201 = F_189 ( & V_45 , ( void V_202 * ) V_15 ,
sizeof( V_45 ) ) ;
F_190 () ;
if ( F_114 ( V_201 == 0 ) )
goto V_94;
V_201 = F_34 ( NULL , V_20 , V_15 , 1 , 0 , 1 , & V_17 , NULL ) ;
if ( V_201 < 0 )
return V_201 ;
F_28 ( V_17 , V_15 , & V_45 , V_44 ) ;
F_23 ( V_17 ) ;
V_94:
return F_27 ( & V_45 ) ;
}
static struct V_57 * F_191 ( unsigned long V_192 , int * V_43 )
{
struct V_19 * V_20 = V_136 -> V_20 ;
struct V_57 * V_57 = NULL ;
struct V_1 * V_2 ;
F_85 ( & V_20 -> V_116 ) ;
V_2 = F_107 ( V_20 , V_192 ) ;
if ( V_2 && V_2 -> V_12 <= V_192 ) {
if ( F_1 ( V_2 , false ) ) {
struct V_60 * V_60 = F_108 ( V_2 -> V_9 ) ;
T_2 V_11 = F_3 ( V_2 , V_192 ) ;
V_57 = F_49 ( V_60 , V_11 ) ;
}
if ( ! V_57 )
* V_43 = F_187 ( V_20 , V_192 ) ;
} else {
* V_43 = - V_203 ;
}
if ( ! V_57 && F_192 ( V_101 , & V_20 -> V_4 ) )
F_186 ( V_20 ) ;
F_86 ( & V_20 -> V_116 ) ;
return V_57 ;
}
static void F_193 ( struct V_57 * V_57 , struct V_165 * V_166 )
{
struct V_75 * V_76 ;
int remove = V_204 ;
bool V_205 = false ;
F_85 ( & V_57 -> V_73 ) ;
for ( V_76 = V_57 -> V_78 ; V_76 ; V_76 = V_76 -> V_77 ) {
int V_206 = 0 ;
if ( V_76 -> V_119 ) {
V_206 = V_76 -> V_119 ( V_76 , V_166 ) ;
F_194 ( V_206 & ~ V_207 ,
L_7 , V_206 , V_76 -> V_119 ) ;
}
if ( V_76 -> V_120 )
V_205 = true ;
remove &= V_206 ;
}
if ( V_205 && ! remove )
F_172 ( V_57 , V_166 ) ;
if ( remove && V_57 -> V_78 ) {
F_93 ( ! F_90 ( V_57 ) ) ;
F_117 ( V_57 , V_136 -> V_20 ) ;
}
F_86 ( & V_57 -> V_73 ) ;
}
static void
F_195 ( struct V_169 * V_170 , struct V_165 * V_166 )
{
struct V_57 * V_57 = V_170 -> V_57 ;
struct V_75 * V_76 ;
F_85 ( & V_57 -> V_73 ) ;
for ( V_76 = V_57 -> V_78 ; V_76 ; V_76 = V_76 -> V_77 ) {
if ( V_76 -> V_120 )
V_76 -> V_120 ( V_76 , V_170 -> V_191 , V_166 ) ;
}
F_86 ( & V_57 -> V_73 ) ;
}
static bool F_196 ( struct V_165 * V_166 )
{
struct V_167 * V_164 ;
struct V_169 * V_170 , * V_171 ;
bool V_187 ;
V_164 = V_136 -> V_164 ;
if ( ! V_164 )
return false ;
V_170 = V_164 -> V_172 ;
if ( ! V_170 )
return false ;
F_197 ( V_166 , V_170 -> V_186 ) ;
for (; ; ) {
F_195 ( V_170 , V_166 ) ;
V_187 = V_170 -> V_187 ;
F_57 ( V_170 -> V_57 ) ;
V_171 = V_170 ;
V_170 = V_170 -> V_77 ;
F_59 ( V_171 ) ;
V_164 -> V_176 -- ;
if ( ! V_187 )
break;
F_80 ( ! V_170 ) ;
}
V_164 -> V_172 = V_170 ;
return true ;
}
bool __weak F_198 ( struct V_55 * V_208 , struct V_165 * V_166 )
{
return false ;
}
static void F_199 ( struct V_165 * V_166 )
{
struct V_57 * V_57 ;
unsigned long V_192 ;
int V_209 ( V_43 ) ;
V_192 = F_159 ( V_166 ) ;
if ( V_192 == F_171 () ) {
if ( F_196 ( V_166 ) )
return;
F_166 ( L_8 ,
V_136 -> V_179 , V_136 -> V_190 ) ;
}
V_57 = F_191 ( V_192 , & V_43 ) ;
if ( ! V_57 ) {
if ( V_43 > 0 ) {
F_200 ( V_210 , V_136 , 0 ) ;
} else {
F_197 ( V_166 , V_192 ) ;
}
return;
}
F_197 ( V_166 , V_192 ) ;
F_201 () ;
if ( F_42 ( ! F_78 ( V_93 , & V_57 -> V_4 ) ) )
goto V_94;
if ( ! F_163 () )
goto V_94;
if ( F_198 ( & V_57 -> V_90 , V_166 ) )
goto V_94;
F_193 ( V_57 , V_166 ) ;
if ( F_202 ( & V_57 -> V_90 , V_166 ) )
goto V_94;
if ( ! F_175 ( V_57 , V_166 , V_192 ) )
return;
V_94:
F_57 ( V_57 ) ;
}
static void F_203 ( struct V_167 * V_164 , struct V_165 * V_166 )
{
struct V_57 * V_57 ;
int V_24 = 0 ;
V_57 = V_164 -> V_168 ;
if ( V_164 -> V_193 == V_211 )
V_24 = F_204 ( & V_57 -> V_90 , V_166 ) ;
else if ( V_164 -> V_193 == V_198 )
F_205 ( & V_57 -> V_90 , V_166 ) ;
else
F_178 ( 1 ) ;
F_57 ( V_57 ) ;
V_164 -> V_168 = NULL ;
V_164 -> V_193 = V_212 ;
F_154 ( V_136 ) ;
F_180 ( & V_136 -> V_195 -> V_196 ) ;
F_206 () ;
F_182 ( & V_136 -> V_195 -> V_196 ) ;
if ( F_42 ( V_24 ) ) {
F_165 ( V_136 , L_9 ) ;
F_207 ( V_213 , V_214 , V_136 ) ;
}
}
void F_208 ( struct V_165 * V_166 )
{
struct V_167 * V_164 ;
F_209 ( V_199 ) ;
V_164 = V_136 -> V_164 ;
if ( V_164 && V_164 -> V_168 )
F_203 ( V_164 , V_166 ) ;
else
F_199 ( V_166 ) ;
}
int F_210 ( struct V_165 * V_166 )
{
if ( ! V_136 -> V_20 )
return 0 ;
if ( ! F_78 ( V_100 , & V_136 -> V_20 -> V_4 ) &&
( ! V_136 -> V_164 || ! V_136 -> V_164 -> V_172 ) )
return 0 ;
F_211 ( V_199 ) ;
return 1 ;
}
int F_212 ( struct V_165 * V_166 )
{
struct V_167 * V_164 = V_136 -> V_164 ;
if ( ! V_136 -> V_20 || ! V_164 || ! V_164 -> V_168 )
return 0 ;
V_164 -> V_193 = V_211 ;
F_211 ( V_199 ) ;
return 1 ;
}
static int T_6 F_213 ( void )
{
int V_215 ;
for ( V_215 = 0 ; V_215 < V_216 ; V_215 ++ )
F_214 ( & V_217 [ V_215 ] ) ;
if ( F_215 ( & V_115 ) )
return - V_51 ;
return F_216 ( & V_218 ) ;
}
