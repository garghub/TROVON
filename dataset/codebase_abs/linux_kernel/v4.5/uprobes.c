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
struct V_28 * V_29 ;
V_24 = F_5 ( V_18 , V_2 -> V_21 , V_30 , & V_29 ,
false ) ;
if ( V_24 )
return V_24 ;
F_6 ( V_17 ) ;
F_7 ( V_20 , V_25 , V_26 ) ;
V_24 = - V_31 ;
V_23 = F_8 ( V_17 , V_20 , V_16 , & V_22 , 0 ) ;
if ( ! V_23 )
goto V_32;
F_9 ( V_18 ) ;
F_10 ( V_18 , V_2 , V_16 , false ) ;
F_11 ( V_18 , V_29 , false , false ) ;
F_12 ( V_18 , V_2 ) ;
if ( ! F_13 ( V_17 ) ) {
F_14 ( V_20 , F_15 ( V_17 ) ) ;
F_16 ( V_20 , V_33 ) ;
}
F_17 ( V_2 , V_16 , F_18 ( * V_23 ) ) ;
F_19 ( V_2 , V_16 , V_23 ) ;
F_20 ( V_20 , V_16 , V_23 , F_21 ( V_18 , V_2 -> V_34 ) ) ;
F_22 ( V_17 , false ) ;
if ( ! F_23 ( V_17 ) )
F_24 ( V_17 ) ;
F_25 ( V_23 , V_22 ) ;
if ( V_2 -> V_10 & V_35 )
F_26 ( V_17 ) ;
F_27 ( V_17 ) ;
V_24 = 0 ;
V_32:
F_28 ( V_18 , V_29 , false ) ;
F_29 ( V_20 , V_25 , V_26 ) ;
F_30 ( V_17 ) ;
return V_24 ;
}
bool __weak F_31 ( T_5 * V_36 )
{
return * V_36 == V_37 ;
}
bool __weak F_32 ( T_5 * V_36 )
{
return F_31 ( V_36 ) ;
}
static void F_33 ( struct V_17 * V_17 , unsigned long V_15 , void * V_38 , int V_39 )
{
void * V_40 = F_34 ( V_17 ) ;
memcpy ( V_38 , V_40 + ( V_15 & ~ V_41 ) , V_39 ) ;
F_35 ( V_40 ) ;
}
static void F_36 ( struct V_17 * V_17 , unsigned long V_15 , const void * V_42 , int V_39 )
{
void * V_40 = F_34 ( V_17 ) ;
memcpy ( V_40 + ( V_15 & ~ V_41 ) , V_42 , V_39 ) ;
F_35 ( V_40 ) ;
}
static int F_37 ( struct V_17 * V_17 , unsigned long V_15 , T_5 * V_43 )
{
T_5 V_44 ;
bool V_45 ;
F_33 ( V_17 , V_15 , & V_44 , V_46 ) ;
V_45 = F_31 ( & V_44 ) ;
if ( F_31 ( V_43 ) ) {
if ( V_45 )
return 0 ;
} else {
if ( ! V_45 )
return 0 ;
}
return 1 ;
}
int F_38 ( struct V_19 * V_20 , unsigned long V_15 ,
T_5 V_47 )
{
struct V_17 * V_48 , * V_49 ;
struct V_1 * V_2 ;
int V_50 ;
V_51:
V_50 = F_39 ( NULL , V_20 , V_15 , 1 , 0 , 1 , & V_48 , & V_2 ) ;
if ( V_50 <= 0 )
return V_50 ;
V_50 = F_37 ( V_48 , V_15 , & V_47 ) ;
if ( V_50 <= 0 )
goto V_52;
V_50 = F_40 ( V_2 ) ;
if ( V_50 )
goto V_52;
V_50 = - V_53 ;
V_49 = F_41 ( V_54 , V_2 , V_15 ) ;
if ( ! V_49 )
goto V_52;
F_42 ( V_49 ) ;
F_43 ( V_49 , V_48 ) ;
F_36 ( V_49 , V_15 , & V_47 , V_46 ) ;
V_50 = F_4 ( V_2 , V_15 , V_48 , V_49 ) ;
F_44 ( V_49 ) ;
V_52:
F_27 ( V_48 ) ;
if ( F_45 ( V_50 == - V_31 ) )
goto V_51;
return V_50 ;
}
int __weak F_46 ( struct V_55 * V_56 , struct V_19 * V_20 , unsigned long V_15 )
{
return F_38 ( V_20 , V_15 , V_37 ) ;
}
int __weak
F_47 ( struct V_55 * V_56 , struct V_19 * V_20 , unsigned long V_15 )
{
return F_38 ( V_20 , V_15 , * ( T_5 * ) & V_56 -> V_36 ) ;
}
static struct V_57 * F_48 ( struct V_57 * V_57 )
{
F_49 ( & V_57 -> V_58 ) ;
return V_57 ;
}
static void F_50 ( struct V_57 * V_57 )
{
if ( F_51 ( & V_57 -> V_58 ) )
F_52 ( V_57 ) ;
}
static int F_53 ( struct V_57 * V_59 , struct V_57 * V_60 )
{
if ( V_59 -> V_61 < V_60 -> V_61 )
return - 1 ;
if ( V_59 -> V_61 > V_60 -> V_61 )
return 1 ;
if ( V_59 -> V_11 < V_60 -> V_11 )
return - 1 ;
if ( V_59 -> V_11 > V_60 -> V_11 )
return 1 ;
return 0 ;
}
static struct V_57 * F_54 ( struct V_61 * V_61 , T_2 V_11 )
{
struct V_57 V_62 = { . V_61 = V_61 , . V_11 = V_11 } ;
struct V_63 * V_64 = V_65 . V_63 ;
struct V_57 * V_57 ;
int V_66 ;
while ( V_64 ) {
V_57 = F_55 ( V_64 , struct V_57 , V_63 ) ;
V_66 = F_53 ( & V_62 , V_57 ) ;
if ( ! V_66 )
return F_48 ( V_57 ) ;
if ( V_66 < 0 )
V_64 = V_64 -> V_67 ;
else
V_64 = V_64 -> V_68 ;
}
return NULL ;
}
static struct V_57 * F_56 ( struct V_61 * V_61 , T_2 V_11 )
{
struct V_57 * V_57 ;
F_57 ( & V_69 ) ;
V_57 = F_54 ( V_61 , V_11 ) ;
F_58 ( & V_69 ) ;
return V_57 ;
}
static struct V_57 * F_59 ( struct V_57 * V_57 )
{
struct V_63 * * V_70 = & V_65 . V_63 ;
struct V_63 * V_71 = NULL ;
struct V_57 * V_62 ;
int V_66 ;
while ( * V_70 ) {
V_71 = * V_70 ;
V_62 = F_55 ( V_71 , struct V_57 , V_63 ) ;
V_66 = F_53 ( V_57 , V_62 ) ;
if ( ! V_66 )
return F_48 ( V_62 ) ;
if ( V_66 < 0 )
V_70 = & V_71 -> V_67 ;
else
V_70 = & V_71 -> V_68 ;
}
V_62 = NULL ;
F_60 ( & V_57 -> V_63 , V_71 , V_70 ) ;
F_61 ( & V_57 -> V_63 , & V_65 ) ;
F_62 ( & V_57 -> V_58 , 2 ) ;
return V_62 ;
}
static struct V_57 * F_63 ( struct V_57 * V_57 )
{
struct V_57 * V_62 ;
F_57 ( & V_69 ) ;
V_62 = F_59 ( V_57 ) ;
F_58 ( & V_69 ) ;
return V_62 ;
}
static struct V_57 * F_64 ( struct V_61 * V_61 , T_2 V_11 )
{
struct V_57 * V_57 , * V_72 ;
V_57 = F_65 ( sizeof( struct V_57 ) , V_30 ) ;
if ( ! V_57 )
return NULL ;
V_57 -> V_61 = F_66 ( V_61 ) ;
V_57 -> V_11 = V_11 ;
F_67 ( & V_57 -> V_73 ) ;
F_67 ( & V_57 -> V_74 ) ;
V_72 = F_63 ( V_57 ) ;
if ( V_72 ) {
F_52 ( V_57 ) ;
V_57 = V_72 ;
F_68 ( V_61 ) ;
}
return V_57 ;
}
static void F_69 ( struct V_57 * V_57 , struct V_75 * V_76 )
{
F_70 ( & V_57 -> V_74 ) ;
V_76 -> V_77 = V_57 -> V_78 ;
V_57 -> V_78 = V_76 ;
F_71 ( & V_57 -> V_74 ) ;
}
static bool F_72 ( struct V_57 * V_57 , struct V_75 * V_76 )
{
struct V_75 * * V_79 ;
bool V_50 = false ;
F_70 ( & V_57 -> V_74 ) ;
for ( V_79 = & V_57 -> V_78 ; * V_79 ; V_79 = & ( * V_79 ) -> V_77 ) {
if ( * V_79 == V_76 ) {
* V_79 = V_76 -> V_77 ;
V_50 = true ;
break;
}
}
F_71 ( & V_57 -> V_74 ) ;
return V_50 ;
}
static int F_73 ( struct V_80 * V_81 , struct V_82 * V_83 ,
void * V_36 , int V_84 , T_2 V_11 )
{
struct V_17 * V_17 ;
if ( V_81 -> V_85 -> V_86 )
V_17 = F_74 ( V_81 , V_11 >> V_87 , V_83 ) ;
else
V_17 = F_75 ( V_81 , V_11 >> V_87 ) ;
if ( F_76 ( V_17 ) )
return F_77 ( V_17 ) ;
F_33 ( V_17 , V_11 , V_36 , V_84 ) ;
F_44 ( V_17 ) ;
return 0 ;
}
static int F_78 ( struct V_57 * V_57 , struct V_82 * V_83 )
{
struct V_80 * V_81 = V_57 -> V_61 -> V_88 ;
T_2 V_89 = V_57 -> V_11 ;
void * V_36 = & V_57 -> V_90 . V_36 ;
int V_91 = sizeof( V_57 -> V_90 . V_36 ) ;
int V_39 , V_24 = - V_92 ;
do {
if ( V_89 >= F_79 ( V_57 -> V_61 ) )
break;
V_39 = F_80 ( int , V_91 , V_27 - ( V_89 & ~ V_41 ) ) ;
V_24 = F_73 ( V_81 , V_83 , V_36 , V_39 , V_89 ) ;
if ( V_24 )
break;
V_36 += V_39 ;
V_89 += V_39 ;
V_91 -= V_39 ;
} while ( V_91 );
return V_24 ;
}
static int F_81 ( struct V_57 * V_57 , struct V_82 * V_82 ,
struct V_19 * V_20 , unsigned long V_15 )
{
int V_50 = 0 ;
if ( F_82 ( V_93 , & V_57 -> V_4 ) )
return V_50 ;
F_70 ( & V_57 -> V_74 ) ;
if ( F_82 ( V_93 , & V_57 -> V_4 ) )
goto V_94;
V_50 = F_78 ( V_57 , V_82 ) ;
if ( V_50 )
goto V_94;
V_50 = - V_95 ;
if ( F_32 ( ( T_5 * ) & V_57 -> V_90 . V_36 ) )
goto V_94;
V_50 = F_83 ( & V_57 -> V_90 , V_20 , V_15 ) ;
if ( V_50 )
goto V_94;
F_84 ( ( V_57 -> V_11 & ~ V_41 ) +
V_46 > V_27 ) ;
F_85 () ;
F_86 ( V_93 , & V_57 -> V_4 ) ;
V_94:
F_71 ( & V_57 -> V_74 ) ;
return V_50 ;
}
static inline bool F_87 ( struct V_75 * V_76 ,
enum V_96 V_97 , struct V_19 * V_20 )
{
return ! V_76 -> V_98 || V_76 -> V_98 ( V_76 , V_97 , V_20 ) ;
}
static bool F_88 ( struct V_57 * V_57 ,
enum V_96 V_97 , struct V_19 * V_20 )
{
struct V_75 * V_76 ;
bool V_50 = false ;
F_89 ( & V_57 -> V_74 ) ;
for ( V_76 = V_57 -> V_78 ; V_76 ; V_76 = V_76 -> V_77 ) {
V_50 = F_87 ( V_76 , V_97 , V_20 ) ;
if ( V_50 )
break;
}
F_90 ( & V_57 -> V_74 ) ;
return V_50 ;
}
static int
F_91 ( struct V_57 * V_57 , struct V_19 * V_20 ,
struct V_1 * V_2 , unsigned long V_15 )
{
bool V_99 ;
int V_50 ;
V_50 = F_81 ( V_57 , V_2 -> V_9 , V_20 , V_15 ) ;
if ( V_50 )
return V_50 ;
V_99 = ! F_82 ( V_100 , & V_20 -> V_4 ) ;
if ( V_99 )
F_86 ( V_100 , & V_20 -> V_4 ) ;
V_50 = F_46 ( & V_57 -> V_90 , V_20 , V_15 ) ;
if ( ! V_50 )
F_92 ( V_101 , & V_20 -> V_4 ) ;
else if ( V_99 )
F_92 ( V_100 , & V_20 -> V_4 ) ;
return V_50 ;
}
static int
F_93 ( struct V_57 * V_57 , struct V_19 * V_20 , unsigned long V_15 )
{
F_86 ( V_101 , & V_20 -> V_4 ) ;
return F_47 ( & V_57 -> V_90 , V_20 , V_15 ) ;
}
static inline bool F_94 ( struct V_57 * V_57 )
{
return ! F_95 ( & V_57 -> V_63 ) ;
}
static void F_96 ( struct V_57 * V_57 )
{
if ( F_97 ( ! F_94 ( V_57 ) ) )
return;
F_57 ( & V_69 ) ;
F_98 ( & V_57 -> V_63 , & V_65 ) ;
F_58 ( & V_69 ) ;
F_99 ( & V_57 -> V_63 ) ;
F_68 ( V_57 -> V_61 ) ;
F_50 ( V_57 ) ;
}
static inline struct V_102 * F_100 ( struct V_102 * V_103 )
{
struct V_102 * V_77 = V_103 -> V_77 ;
F_52 ( V_103 ) ;
return V_77 ;
}
static struct V_102 *
F_101 ( struct V_80 * V_81 , T_2 V_11 , bool V_3 )
{
unsigned long V_104 = V_11 >> V_14 ;
struct V_1 * V_2 ;
struct V_102 * V_105 = NULL ;
struct V_102 * V_106 = NULL ;
struct V_102 * V_103 ;
int V_107 = 0 ;
V_108:
F_102 ( V_81 ) ;
F_103 (vma, &mapping->i_mmap, pgoff, pgoff) {
if ( ! F_1 ( V_2 , V_3 ) )
continue;
if ( ! V_106 && ! V_107 ) {
V_106 = F_104 ( sizeof( struct V_102 ) ,
V_109 | V_110 | V_111 ) ;
if ( V_106 )
V_106 -> V_77 = NULL ;
}
if ( ! V_106 ) {
V_107 ++ ;
continue;
}
if ( ! F_105 ( & V_2 -> V_21 -> V_112 ) )
continue;
V_103 = V_106 ;
V_106 = V_106 -> V_77 ;
V_103 -> V_77 = V_105 ;
V_105 = V_103 ;
V_103 -> V_20 = V_2 -> V_21 ;
V_103 -> V_15 = F_2 ( V_2 , V_11 ) ;
}
F_106 ( V_81 ) ;
if ( ! V_107 )
goto V_94;
V_106 = V_105 ;
while ( V_105 ) {
F_107 ( V_105 -> V_20 ) ;
V_105 = V_105 -> V_77 ;
}
do {
V_103 = F_104 ( sizeof( struct V_102 ) , V_30 ) ;
if ( ! V_103 ) {
V_105 = F_108 ( - V_53 ) ;
goto V_94;
}
V_103 -> V_77 = V_106 ;
V_106 = V_103 ;
} while ( -- V_107 );
goto V_108;
V_94:
while ( V_106 )
V_106 = F_100 ( V_106 ) ;
return V_105 ;
}
static int
F_109 ( struct V_57 * V_57 , struct V_75 * V_113 )
{
bool V_3 = ! ! V_113 ;
struct V_102 * V_103 ;
int V_24 = 0 ;
F_110 ( & V_114 ) ;
V_103 = F_101 ( V_57 -> V_61 -> V_88 ,
V_57 -> V_11 , V_3 ) ;
if ( F_76 ( V_103 ) ) {
V_24 = F_77 ( V_103 ) ;
goto V_94;
}
while ( V_103 ) {
struct V_19 * V_20 = V_103 -> V_20 ;
struct V_1 * V_2 ;
if ( V_24 && V_3 )
goto free;
F_70 ( & V_20 -> V_115 ) ;
V_2 = F_111 ( V_20 , V_103 -> V_15 ) ;
if ( ! V_2 || ! F_1 ( V_2 , V_3 ) ||
F_112 ( V_2 -> V_9 ) != V_57 -> V_61 )
goto V_32;
if ( V_2 -> V_12 > V_103 -> V_15 ||
F_3 ( V_2 , V_103 -> V_15 ) != V_57 -> V_11 )
goto V_32;
if ( V_3 ) {
if ( F_87 ( V_113 ,
V_116 , V_20 ) )
V_24 = F_91 ( V_57 , V_20 , V_2 , V_103 -> V_15 ) ;
} else if ( F_82 ( V_100 , & V_20 -> V_4 ) ) {
if ( ! F_88 ( V_57 ,
V_117 , V_20 ) )
V_24 |= F_93 ( V_57 , V_20 , V_103 -> V_15 ) ;
}
V_32:
F_71 ( & V_20 -> V_115 ) ;
free:
F_107 ( V_20 ) ;
V_103 = F_100 ( V_103 ) ;
}
V_94:
F_113 ( & V_114 ) ;
return V_24 ;
}
static int F_114 ( struct V_57 * V_57 , struct V_75 * V_76 )
{
F_69 ( V_57 , V_76 ) ;
return F_109 ( V_57 , V_76 ) ;
}
static void F_115 ( struct V_57 * V_57 , struct V_75 * V_76 )
{
int V_24 ;
if ( F_97 ( ! F_72 ( V_57 , V_76 ) ) )
return;
V_24 = F_109 ( V_57 , NULL ) ;
if ( ! V_57 -> V_78 && ! V_24 )
F_96 ( V_57 ) ;
}
int F_116 ( struct V_61 * V_61 , T_2 V_11 , struct V_75 * V_76 )
{
struct V_57 * V_57 ;
int V_50 ;
if ( ! V_76 -> V_118 && ! V_76 -> V_119 )
return - V_120 ;
if ( ! V_61 -> V_88 -> V_85 -> V_86 && ! F_117 ( V_61 -> V_88 ) )
return - V_92 ;
if ( V_11 > F_79 ( V_61 ) )
return - V_120 ;
V_51:
V_57 = F_64 ( V_61 , V_11 ) ;
if ( ! V_57 )
return - V_53 ;
F_70 ( & V_57 -> V_73 ) ;
V_50 = - V_31 ;
if ( F_118 ( F_94 ( V_57 ) ) ) {
V_50 = F_114 ( V_57 , V_76 ) ;
if ( V_50 )
F_115 ( V_57 , V_76 ) ;
}
F_71 ( & V_57 -> V_73 ) ;
F_50 ( V_57 ) ;
if ( F_45 ( V_50 == - V_31 ) )
goto V_51;
return V_50 ;
}
int F_119 ( struct V_61 * V_61 , T_2 V_11 ,
struct V_75 * V_76 , bool V_121 )
{
struct V_57 * V_57 ;
struct V_75 * V_79 ;
int V_50 = - V_122 ;
V_57 = F_56 ( V_61 , V_11 ) ;
if ( F_97 ( ! V_57 ) )
return V_50 ;
F_70 ( & V_57 -> V_73 ) ;
for ( V_79 = V_57 -> V_78 ; V_79 && V_79 != V_76 ; V_79 = V_79 -> V_77 )
;
if ( V_79 )
V_50 = F_109 ( V_57 , V_121 ? V_76 : NULL ) ;
F_71 ( & V_57 -> V_73 ) ;
F_50 ( V_57 ) ;
return V_50 ;
}
void F_120 ( struct V_61 * V_61 , T_2 V_11 , struct V_75 * V_76 )
{
struct V_57 * V_57 ;
V_57 = F_56 ( V_61 , V_11 ) ;
if ( F_97 ( ! V_57 ) )
return;
F_70 ( & V_57 -> V_73 ) ;
F_115 ( V_57 , V_76 ) ;
F_71 ( & V_57 -> V_73 ) ;
F_50 ( V_57 ) ;
}
static int F_121 ( struct V_57 * V_57 , struct V_19 * V_20 )
{
struct V_1 * V_2 ;
int V_24 = 0 ;
F_89 ( & V_20 -> V_115 ) ;
for ( V_2 = V_20 -> V_123 ; V_2 ; V_2 = V_2 -> V_124 ) {
unsigned long V_15 ;
T_2 V_11 ;
if ( ! F_1 ( V_2 , false ) ||
F_112 ( V_2 -> V_9 ) != V_57 -> V_61 )
continue;
V_11 = ( T_2 ) V_2 -> V_13 << V_14 ;
if ( V_57 -> V_11 < V_11 ||
V_57 -> V_11 >= V_11 + V_2 -> V_125 - V_2 -> V_12 )
continue;
V_15 = F_2 ( V_2 , V_57 -> V_11 ) ;
V_24 |= F_93 ( V_57 , V_20 , V_15 ) ;
}
F_90 ( & V_20 -> V_115 ) ;
return V_24 ;
}
static struct V_63 *
F_122 ( struct V_61 * V_61 , T_2 V_126 , T_2 V_127 )
{
struct V_63 * V_64 = V_65 . V_63 ;
while ( V_64 ) {
struct V_57 * V_62 = F_55 ( V_64 , struct V_57 , V_63 ) ;
if ( V_61 < V_62 -> V_61 ) {
V_64 = V_64 -> V_67 ;
} else if ( V_61 > V_62 -> V_61 ) {
V_64 = V_64 -> V_68 ;
} else {
if ( V_127 < V_62 -> V_11 )
V_64 = V_64 -> V_67 ;
else if ( V_126 > V_62 -> V_11 )
V_64 = V_64 -> V_68 ;
else
break;
}
}
return V_64 ;
}
static void F_123 ( struct V_61 * V_61 ,
struct V_1 * V_2 ,
unsigned long V_128 , unsigned long V_129 ,
struct V_130 * V_131 )
{
T_2 V_126 , V_127 ;
struct V_63 * V_64 , * V_132 ;
struct V_57 * V_62 ;
F_124 ( V_131 ) ;
V_126 = F_3 ( V_2 , V_128 ) ;
V_127 = V_126 + ( V_129 - V_128 ) - 1 ;
F_57 ( & V_69 ) ;
V_64 = F_122 ( V_61 , V_126 , V_127 ) ;
if ( V_64 ) {
for ( V_132 = V_64 ; V_132 ; V_132 = F_125 ( V_132 ) ) {
V_62 = F_55 ( V_132 , struct V_57 , V_63 ) ;
if ( V_62 -> V_61 != V_61 || V_62 -> V_11 < V_126 )
break;
F_126 ( & V_62 -> V_133 , V_131 ) ;
F_48 ( V_62 ) ;
}
for ( V_132 = V_64 ; ( V_132 = F_127 ( V_132 ) ) ; ) {
V_62 = F_55 ( V_132 , struct V_57 , V_63 ) ;
if ( V_62 -> V_61 != V_61 || V_62 -> V_11 > V_127 )
break;
F_126 ( & V_62 -> V_133 , V_131 ) ;
F_48 ( V_62 ) ;
}
}
F_58 ( & V_69 ) ;
}
int F_128 ( struct V_1 * V_2 )
{
struct V_130 V_134 ;
struct V_57 * V_57 , * V_62 ;
struct V_61 * V_61 ;
if ( F_129 () || ! F_1 ( V_2 , true ) )
return 0 ;
V_61 = F_112 ( V_2 -> V_9 ) ;
if ( ! V_61 )
return 0 ;
F_130 ( F_131 ( V_61 ) ) ;
F_123 ( V_61 , V_2 , V_2 -> V_12 , V_2 -> V_125 , & V_134 ) ;
F_132 (uprobe, u, &tmp_list, pending_list) {
if ( ! F_133 ( V_135 ) &&
F_88 ( V_57 , V_136 , V_2 -> V_21 ) ) {
unsigned long V_15 = F_2 ( V_2 , V_57 -> V_11 ) ;
F_91 ( V_57 , V_2 -> V_21 , V_2 , V_15 ) ;
}
F_50 ( V_57 ) ;
}
F_134 ( F_131 ( V_61 ) ) ;
return 0 ;
}
static bool
F_135 ( struct V_1 * V_2 , unsigned long V_128 , unsigned long V_129 )
{
T_2 V_126 , V_127 ;
struct V_61 * V_61 ;
struct V_63 * V_64 ;
V_61 = F_112 ( V_2 -> V_9 ) ;
V_126 = F_3 ( V_2 , V_128 ) ;
V_127 = V_126 + ( V_129 - V_128 ) - 1 ;
F_57 ( & V_69 ) ;
V_64 = F_122 ( V_61 , V_126 , V_127 ) ;
F_58 ( & V_69 ) ;
return ! ! V_64 ;
}
void F_136 ( struct V_1 * V_2 , unsigned long V_128 , unsigned long V_129 )
{
if ( F_129 () || ! F_1 ( V_2 , false ) )
return;
if ( ! F_137 ( & V_2 -> V_21 -> V_112 ) )
return;
if ( ! F_82 ( V_100 , & V_2 -> V_21 -> V_4 ) ||
F_82 ( V_101 , & V_2 -> V_21 -> V_4 ) )
return;
if ( F_135 ( V_2 , V_128 , V_129 ) )
F_86 ( V_101 , & V_2 -> V_21 -> V_4 ) ;
}
static int F_138 ( struct V_19 * V_20 , struct V_137 * V_138 )
{
struct V_1 * V_2 ;
int V_50 ;
F_70 ( & V_20 -> V_115 ) ;
if ( V_20 -> V_139 . V_137 ) {
V_50 = - V_140 ;
goto V_141;
}
if ( ! V_138 -> V_15 ) {
V_138 -> V_15 = F_139 ( NULL , V_142 - V_27 ,
V_27 , 0 , 0 ) ;
if ( V_138 -> V_15 & ~ V_41 ) {
V_50 = V_138 -> V_15 ;
goto V_141;
}
}
V_2 = F_140 ( V_20 , V_138 -> V_15 , V_27 ,
V_143 | V_6 | V_144 | V_145 ,
& V_138 -> V_146 ) ;
if ( F_76 ( V_2 ) ) {
V_50 = F_77 ( V_2 ) ;
goto V_141;
}
V_50 = 0 ;
F_85 () ;
V_20 -> V_139 . V_137 = V_138 ;
V_141:
F_71 ( & V_20 -> V_115 ) ;
return V_50 ;
}
static struct V_137 * F_141 ( unsigned long V_15 )
{
struct V_19 * V_20 = V_135 -> V_20 ;
T_5 V_36 = V_37 ;
struct V_137 * V_138 ;
V_138 = F_104 ( sizeof( * V_138 ) , V_30 ) ;
if ( F_45 ( ! V_138 ) )
goto V_94;
V_138 -> V_147 = F_65 ( F_142 ( V_148 ) * sizeof( long ) , V_30 ) ;
if ( ! V_138 -> V_147 )
goto V_149;
V_138 -> V_146 . V_150 = L_1 ;
V_138 -> V_146 . V_151 = V_138 -> V_151 ;
V_138 -> V_151 [ 0 ] = F_143 ( V_152 ) ;
if ( ! V_138 -> V_151 [ 0 ] )
goto V_153;
V_138 -> V_151 [ 1 ] = NULL ;
V_138 -> V_15 = V_15 ;
F_144 ( & V_138 -> V_154 ) ;
F_86 ( 0 , V_138 -> V_147 ) ;
F_62 ( & V_138 -> V_155 , 1 ) ;
F_36 ( V_138 -> V_151 [ 0 ] , 0 , & V_36 , V_46 ) ;
if ( ! F_138 ( V_20 , V_138 ) )
return V_138 ;
F_145 ( V_138 -> V_151 [ 0 ] ) ;
V_153:
F_52 ( V_138 -> V_147 ) ;
V_149:
F_52 ( V_138 ) ;
V_94:
return NULL ;
}
static struct V_137 * F_146 ( void )
{
struct V_19 * V_20 = V_135 -> V_20 ;
struct V_137 * V_138 ;
if ( ! V_20 -> V_139 . V_137 )
F_141 ( 0 ) ;
V_138 = V_20 -> V_139 . V_137 ;
F_147 () ;
return V_138 ;
}
void F_148 ( struct V_19 * V_20 )
{
struct V_137 * V_138 = V_20 -> V_139 . V_137 ;
if ( ! V_138 )
return;
F_27 ( V_138 -> V_151 [ 0 ] ) ;
F_52 ( V_138 -> V_147 ) ;
F_52 ( V_138 ) ;
}
void F_149 ( void )
{
F_150 ( & V_114 ) ;
}
void F_151 ( void )
{
F_152 ( & V_114 ) ;
}
void F_153 ( struct V_19 * V_156 , struct V_19 * V_157 )
{
V_157 -> V_139 . V_137 = NULL ;
if ( F_82 ( V_100 , & V_156 -> V_4 ) ) {
F_86 ( V_100 , & V_157 -> V_4 ) ;
F_86 ( V_101 , & V_157 -> V_4 ) ;
}
}
static unsigned long F_154 ( struct V_137 * V_138 )
{
unsigned long V_158 ;
int V_159 ;
do {
V_159 = F_155 ( V_138 -> V_147 , V_148 ) ;
if ( V_159 < V_148 ) {
if ( ! F_156 ( V_159 , V_138 -> V_147 ) )
break;
V_159 = V_148 ;
continue;
}
F_157 ( V_138 -> V_154 , ( F_137 ( & V_138 -> V_155 ) < V_148 ) ) ;
} while ( V_159 >= V_148 );
V_158 = V_138 -> V_15 + ( V_159 * V_160 ) ;
F_49 ( & V_138 -> V_155 ) ;
return V_158 ;
}
static unsigned long F_158 ( struct V_57 * V_57 )
{
struct V_137 * V_138 ;
unsigned long V_161 ;
V_138 = F_146 () ;
if ( ! V_138 )
return 0 ;
V_161 = F_154 ( V_138 ) ;
if ( F_45 ( ! V_161 ) )
return 0 ;
F_159 ( V_138 -> V_151 [ 0 ] , V_161 ,
& V_57 -> V_90 . V_162 , sizeof( V_57 -> V_90 . V_162 ) ) ;
return V_161 ;
}
static void F_160 ( struct V_163 * V_164 )
{
struct V_137 * V_138 ;
unsigned long V_165 ;
unsigned long V_158 ;
if ( ! V_164 -> V_20 || ! V_164 -> V_20 -> V_139 . V_137 || ! V_164 -> V_166 )
return;
V_158 = V_164 -> V_166 -> V_161 ;
if ( F_45 ( ! V_158 ) )
return;
V_138 = V_164 -> V_20 -> V_139 . V_137 ;
V_165 = V_138 -> V_15 + V_27 ;
if ( V_138 -> V_15 <= V_158 && V_158 < V_165 ) {
unsigned long V_11 ;
int V_159 ;
V_11 = V_158 - V_138 -> V_15 ;
V_159 = V_11 / V_160 ;
if ( V_159 >= V_148 )
return;
F_92 ( V_159 , V_138 -> V_147 ) ;
F_161 ( & V_138 -> V_155 ) ;
F_162 () ;
if ( F_163 ( & V_138 -> V_154 ) )
F_164 ( & V_138 -> V_154 ) ;
V_164 -> V_166 -> V_161 = 0 ;
}
}
void __weak F_159 ( struct V_17 * V_17 , unsigned long V_15 ,
void * V_42 , unsigned long V_39 )
{
F_36 ( V_17 , V_15 , V_42 , V_39 ) ;
F_165 ( V_17 ) ;
}
unsigned long __weak F_166 ( struct V_167 * V_168 )
{
return F_167 ( V_168 ) - V_46 ;
}
unsigned long F_168 ( struct V_167 * V_168 )
{
struct V_169 * V_166 = V_135 -> V_166 ;
if ( F_45 ( V_166 && V_166 -> V_170 ) )
return V_166 -> V_15 ;
return F_167 ( V_168 ) ;
}
static struct V_171 * F_169 ( struct V_171 * V_172 )
{
struct V_171 * V_77 = V_172 -> V_77 ;
F_50 ( V_172 -> V_57 ) ;
F_52 ( V_172 ) ;
return V_77 ;
}
void F_170 ( struct V_163 * V_132 )
{
struct V_169 * V_166 = V_132 -> V_166 ;
struct V_171 * V_172 ;
if ( ! V_166 )
return;
if ( V_166 -> V_170 )
F_50 ( V_166 -> V_170 ) ;
V_172 = V_166 -> V_173 ;
while ( V_172 )
V_172 = F_169 ( V_172 ) ;
F_160 ( V_132 ) ;
F_52 ( V_166 ) ;
V_132 -> V_166 = NULL ;
}
static struct V_169 * F_171 ( void )
{
if ( ! V_135 -> V_166 )
V_135 -> V_166 = F_65 ( sizeof( struct V_169 ) , V_30 ) ;
return V_135 -> V_166 ;
}
static int F_172 ( struct V_163 * V_132 , struct V_169 * V_174 )
{
struct V_169 * V_175 ;
struct V_171 * * V_70 , * V_176 , * V_64 ;
V_175 = F_65 ( sizeof( struct V_169 ) , V_30 ) ;
if ( ! V_175 )
return - V_53 ;
V_132 -> V_166 = V_175 ;
V_70 = & V_175 -> V_173 ;
for ( V_176 = V_174 -> V_173 ; V_176 ; V_176 = V_176 -> V_77 ) {
V_64 = F_104 ( sizeof( struct V_171 ) , V_30 ) ;
if ( ! V_64 )
return - V_53 ;
* V_64 = * V_176 ;
F_48 ( V_64 -> V_57 ) ;
V_64 -> V_77 = NULL ;
* V_70 = V_64 ;
V_70 = & V_64 -> V_77 ;
V_175 -> V_177 ++ ;
}
return 0 ;
}
static void F_173 ( struct V_163 * V_132 , const char * V_178 )
{
F_174 ( L_2 ,
V_135 -> V_179 , V_135 -> V_180 , V_178 ) ;
}
static void F_175 ( struct V_181 * V_182 )
{
if ( V_135 -> V_4 & V_183 )
return;
if ( ! F_141 ( V_135 -> V_166 -> V_184 ) )
F_173 ( V_135 , L_3 ) ;
}
void F_176 ( struct V_163 * V_132 , unsigned long V_4 )
{
struct V_169 * V_166 = V_135 -> V_166 ;
struct V_19 * V_20 = V_135 -> V_20 ;
struct V_137 * V_138 ;
V_132 -> V_166 = NULL ;
if ( ! V_166 || ! V_166 -> V_173 )
return;
if ( V_20 == V_132 -> V_20 && ! ( V_4 & V_185 ) )
return;
if ( F_172 ( V_132 , V_166 ) )
return F_173 ( V_132 , L_4 ) ;
V_138 = V_20 -> V_139 . V_137 ;
if ( ! V_138 )
return F_173 ( V_132 , L_3 ) ;
if ( V_20 == V_132 -> V_20 )
return;
V_132 -> V_166 -> V_184 = V_138 -> V_15 ;
F_177 ( & V_132 -> V_166 -> F_175 , F_175 ) ;
F_178 ( V_132 , & V_132 -> V_166 -> F_175 , true ) ;
}
static unsigned long F_179 ( void )
{
struct V_137 * V_138 ;
unsigned long V_186 = - 1 ;
V_138 = V_135 -> V_20 -> V_139 . V_137 ;
F_147 () ;
if ( V_138 )
V_186 = V_138 -> V_15 ;
return V_186 ;
}
static void F_180 ( struct V_169 * V_166 , bool V_187 ,
struct V_167 * V_168 )
{
struct V_171 * V_172 = V_166 -> V_173 ;
enum V_188 V_97 = V_187 ? V_189 : V_190 ;
while ( V_172 && ! F_181 ( V_172 , V_97 , V_168 ) ) {
V_172 = F_169 ( V_172 ) ;
V_166 -> V_177 -- ;
}
V_166 -> V_173 = V_172 ;
}
static void F_182 ( struct V_57 * V_57 , struct V_167 * V_168 )
{
struct V_171 * V_172 ;
struct V_169 * V_166 ;
unsigned long V_191 , V_186 ;
bool V_187 ;
if ( ! F_146 () )
return;
V_166 = F_171 () ;
if ( ! V_166 )
return;
if ( V_166 -> V_177 >= V_192 ) {
F_183 ( V_193 L_5
L_6 ,
V_135 -> V_180 , V_135 -> V_194 ) ;
return;
}
V_172 = F_104 ( sizeof( struct V_171 ) , V_30 ) ;
if ( ! V_172 )
return;
V_186 = F_179 () ;
V_191 = F_184 ( V_186 , V_168 ) ;
if ( V_191 == - 1 )
goto V_141;
V_187 = ( V_191 == V_186 ) ;
F_180 ( V_166 , V_187 , V_168 ) ;
if ( V_187 ) {
if ( ! V_166 -> V_173 ) {
F_173 ( V_135 , L_7 ) ;
goto V_141;
}
V_191 = V_166 -> V_173 -> V_191 ;
}
V_172 -> V_57 = F_48 ( V_57 ) ;
V_172 -> V_195 = F_167 ( V_168 ) ;
V_172 -> V_196 = F_185 ( V_168 ) ;
V_172 -> V_191 = V_191 ;
V_172 -> V_187 = V_187 ;
V_166 -> V_177 ++ ;
V_172 -> V_77 = V_166 -> V_173 ;
V_166 -> V_173 = V_172 ;
return;
V_141:
F_52 ( V_172 ) ;
}
static int
F_186 ( struct V_57 * V_57 , struct V_167 * V_168 , unsigned long V_197 )
{
struct V_169 * V_166 ;
unsigned long V_161 ;
int V_24 ;
V_166 = F_171 () ;
if ( ! V_166 )
return - V_53 ;
V_161 = F_158 ( V_57 ) ;
if ( ! V_161 )
return - V_53 ;
V_166 -> V_161 = V_161 ;
V_166 -> V_15 = V_197 ;
V_24 = F_187 ( & V_57 -> V_90 , V_168 ) ;
if ( F_45 ( V_24 ) ) {
F_160 ( V_135 ) ;
return V_24 ;
}
V_166 -> V_170 = V_57 ;
V_166 -> V_198 = V_199 ;
return 0 ;
}
bool F_188 ( void )
{
struct V_163 * V_132 = V_135 ;
struct V_169 * V_166 = V_132 -> V_166 ;
if ( F_118 ( ! V_166 || ! V_166 -> V_170 ) )
return false ;
F_189 ( V_166 -> V_198 != V_199 ) ;
if ( F_190 ( V_132 ) ) {
F_191 ( & V_132 -> V_200 -> V_201 ) ;
F_192 ( V_132 , V_202 ) ;
F_193 ( & V_132 -> V_200 -> V_201 ) ;
if ( F_194 ( V_132 ) || F_195 ( V_132 ) ) {
V_166 -> V_198 = V_203 ;
F_196 ( V_132 , V_204 ) ;
}
}
return true ;
}
static void F_197 ( struct V_19 * V_20 )
{
struct V_1 * V_2 ;
for ( V_2 = V_20 -> V_123 ; V_2 ; V_2 = V_2 -> V_124 ) {
if ( ! F_1 ( V_2 , false ) )
continue;
if ( F_135 ( V_2 , V_2 -> V_12 , V_2 -> V_125 ) )
return;
}
F_92 ( V_100 , & V_20 -> V_4 ) ;
}
static int F_198 ( struct V_19 * V_20 , unsigned long V_15 )
{
struct V_17 * V_17 ;
T_5 V_47 ;
int V_205 ;
F_199 () ;
V_205 = F_200 ( & V_47 , ( void V_206 * ) V_15 ,
sizeof( V_47 ) ) ;
F_201 () ;
if ( F_118 ( V_205 == 0 ) )
goto V_94;
V_205 = F_39 ( NULL , V_20 , V_15 , 1 , 0 , 1 , & V_17 , NULL ) ;
if ( V_205 < 0 )
return V_205 ;
F_33 ( V_17 , V_15 , & V_47 , V_46 ) ;
F_27 ( V_17 ) ;
V_94:
return F_32 ( & V_47 ) ;
}
static struct V_57 * F_202 ( unsigned long V_197 , int * V_45 )
{
struct V_19 * V_20 = V_135 -> V_20 ;
struct V_57 * V_57 = NULL ;
struct V_1 * V_2 ;
F_89 ( & V_20 -> V_115 ) ;
V_2 = F_111 ( V_20 , V_197 ) ;
if ( V_2 && V_2 -> V_12 <= V_197 ) {
if ( F_1 ( V_2 , false ) ) {
struct V_61 * V_61 = F_112 ( V_2 -> V_9 ) ;
T_2 V_11 = F_3 ( V_2 , V_197 ) ;
V_57 = F_56 ( V_61 , V_11 ) ;
}
if ( ! V_57 )
* V_45 = F_198 ( V_20 , V_197 ) ;
} else {
* V_45 = - V_207 ;
}
if ( ! V_57 && F_203 ( V_101 , & V_20 -> V_4 ) )
F_197 ( V_20 ) ;
F_90 ( & V_20 -> V_115 ) ;
return V_57 ;
}
static void F_204 ( struct V_57 * V_57 , struct V_167 * V_168 )
{
struct V_75 * V_76 ;
int remove = V_208 ;
bool V_209 = false ;
F_89 ( & V_57 -> V_73 ) ;
for ( V_76 = V_57 -> V_78 ; V_76 ; V_76 = V_76 -> V_77 ) {
int V_210 = 0 ;
if ( V_76 -> V_118 ) {
V_210 = V_76 -> V_118 ( V_76 , V_168 ) ;
F_205 ( V_210 & ~ V_211 ,
L_8 , V_210 , V_76 -> V_118 ) ;
}
if ( V_76 -> V_119 )
V_209 = true ;
remove &= V_210 ;
}
if ( V_209 && ! remove )
F_182 ( V_57 , V_168 ) ;
if ( remove && V_57 -> V_78 ) {
F_97 ( ! F_94 ( V_57 ) ) ;
F_121 ( V_57 , V_135 -> V_20 ) ;
}
F_90 ( & V_57 -> V_73 ) ;
}
static void
F_206 ( struct V_171 * V_172 , struct V_167 * V_168 )
{
struct V_57 * V_57 = V_172 -> V_57 ;
struct V_75 * V_76 ;
F_89 ( & V_57 -> V_73 ) ;
for ( V_76 = V_57 -> V_78 ; V_76 ; V_76 = V_76 -> V_77 ) {
if ( V_76 -> V_119 )
V_76 -> V_119 ( V_76 , V_172 -> V_195 , V_168 ) ;
}
F_90 ( & V_57 -> V_73 ) ;
}
static struct V_171 * F_207 ( struct V_171 * V_172 )
{
bool V_187 ;
do {
V_187 = V_172 -> V_187 ;
V_172 = V_172 -> V_77 ;
} while ( V_187 );
return V_172 ;
}
static void F_208 ( struct V_167 * V_168 )
{
struct V_169 * V_166 ;
struct V_171 * V_172 , * V_77 ;
bool V_212 ;
V_166 = V_135 -> V_166 ;
if ( ! V_166 )
goto V_213;
V_172 = V_166 -> V_173 ;
if ( ! V_172 )
goto V_213;
do {
V_77 = F_207 ( V_172 ) ;
V_212 = ! V_77 || F_181 ( V_77 , V_214 , V_168 ) ;
F_209 ( V_168 , V_172 -> V_191 ) ;
do {
if ( V_212 )
F_206 ( V_172 , V_168 ) ;
V_172 = F_169 ( V_172 ) ;
V_166 -> V_177 -- ;
} while ( V_172 != V_77 );
} while ( ! V_212 );
V_166 -> V_173 = V_172 ;
return;
V_213:
F_173 ( V_135 , L_9 ) ;
F_210 ( V_215 , V_216 , V_135 ) ;
}
bool __weak F_211 ( struct V_55 * V_217 , struct V_167 * V_168 )
{
return false ;
}
bool __weak F_181 ( struct V_171 * V_50 , enum V_188 V_97 ,
struct V_167 * V_168 )
{
return true ;
}
static void F_212 ( struct V_167 * V_168 )
{
struct V_57 * V_57 ;
unsigned long V_197 ;
int V_218 ( V_45 ) ;
V_197 = F_166 ( V_168 ) ;
if ( V_197 == F_179 () )
return F_208 ( V_168 ) ;
V_57 = F_202 ( V_197 , & V_45 ) ;
if ( ! V_57 ) {
if ( V_45 > 0 ) {
F_213 ( V_219 , V_135 , 0 ) ;
} else {
F_209 ( V_168 , V_197 ) ;
}
return;
}
F_209 ( V_168 , V_197 ) ;
F_214 () ;
if ( F_45 ( ! F_82 ( V_93 , & V_57 -> V_4 ) ) )
goto V_94;
if ( ! F_171 () )
goto V_94;
if ( F_211 ( & V_57 -> V_90 , V_168 ) )
goto V_94;
F_204 ( V_57 , V_168 ) ;
if ( F_215 ( & V_57 -> V_90 , V_168 ) )
goto V_94;
if ( ! F_186 ( V_57 , V_168 , V_197 ) )
return;
V_94:
F_50 ( V_57 ) ;
}
static void F_216 ( struct V_169 * V_166 , struct V_167 * V_168 )
{
struct V_57 * V_57 ;
int V_24 = 0 ;
V_57 = V_166 -> V_170 ;
if ( V_166 -> V_198 == V_220 )
V_24 = F_217 ( & V_57 -> V_90 , V_168 ) ;
else if ( V_166 -> V_198 == V_203 )
F_218 ( & V_57 -> V_90 , V_168 ) ;
else
F_189 ( 1 ) ;
F_50 ( V_57 ) ;
V_166 -> V_170 = NULL ;
V_166 -> V_198 = V_221 ;
F_160 ( V_135 ) ;
F_191 ( & V_135 -> V_200 -> V_201 ) ;
F_219 () ;
F_193 ( & V_135 -> V_200 -> V_201 ) ;
if ( F_45 ( V_24 ) ) {
F_173 ( V_135 , L_10 ) ;
F_210 ( V_215 , V_216 , V_135 ) ;
}
}
void F_220 ( struct V_167 * V_168 )
{
struct V_169 * V_166 ;
F_221 ( V_204 ) ;
V_166 = V_135 -> V_166 ;
if ( V_166 && V_166 -> V_170 )
F_216 ( V_166 , V_168 ) ;
else
F_212 ( V_168 ) ;
}
int F_222 ( struct V_167 * V_168 )
{
if ( ! V_135 -> V_20 )
return 0 ;
if ( ! F_82 ( V_100 , & V_135 -> V_20 -> V_4 ) &&
( ! V_135 -> V_166 || ! V_135 -> V_166 -> V_173 ) )
return 0 ;
F_223 ( V_204 ) ;
return 1 ;
}
int F_224 ( struct V_167 * V_168 )
{
struct V_169 * V_166 = V_135 -> V_166 ;
if ( ! V_135 -> V_20 || ! V_166 || ! V_166 -> V_170 )
return 0 ;
V_166 -> V_198 = V_220 ;
F_223 ( V_204 ) ;
return 1 ;
}
static int T_6 F_225 ( void )
{
int V_222 ;
for ( V_222 = 0 ; V_222 < V_223 ; V_222 ++ )
F_226 ( & V_224 [ V_222 ] ) ;
if ( F_227 ( & V_114 ) )
return - V_53 ;
return F_228 ( & V_225 ) ;
}
