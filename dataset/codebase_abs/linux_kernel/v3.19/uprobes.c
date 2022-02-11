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
V_24 = F_5 ( V_18 , V_2 -> V_21 , V_30 , & V_29 ) ;
if ( V_24 )
return V_24 ;
F_6 ( V_17 ) ;
F_7 ( V_20 , V_25 , V_26 ) ;
V_24 = - V_31 ;
V_23 = F_8 ( V_17 , V_20 , V_16 , & V_22 , 0 ) ;
if ( ! V_23 )
goto V_32;
F_9 ( V_18 ) ;
F_10 ( V_18 , V_2 , V_16 ) ;
F_11 ( V_18 , V_29 , false ) ;
F_12 ( V_18 , V_2 ) ;
if ( ! F_13 ( V_17 ) ) {
F_14 ( V_20 , V_33 ) ;
F_15 ( V_20 , V_34 ) ;
}
F_16 ( V_2 , V_16 , F_17 ( * V_23 ) ) ;
F_18 ( V_2 , V_16 , V_23 ) ;
F_19 ( V_20 , V_16 , V_23 , F_20 ( V_18 , V_2 -> V_35 ) ) ;
F_21 ( V_17 ) ;
if ( ! F_22 ( V_17 ) )
F_23 ( V_17 ) ;
F_24 ( V_23 , V_22 ) ;
if ( V_2 -> V_10 & V_36 )
F_25 ( V_17 ) ;
F_26 ( V_17 ) ;
V_24 = 0 ;
V_32:
F_27 ( V_18 , V_29 ) ;
F_28 ( V_20 , V_25 , V_26 ) ;
F_29 ( V_17 ) ;
return V_24 ;
}
bool __weak F_30 ( T_5 * V_37 )
{
return * V_37 == V_38 ;
}
bool __weak F_31 ( T_5 * V_37 )
{
return F_30 ( V_37 ) ;
}
static void F_32 ( struct V_17 * V_17 , unsigned long V_15 , void * V_39 , int V_40 )
{
void * V_41 = F_33 ( V_17 ) ;
memcpy ( V_39 , V_41 + ( V_15 & ~ V_42 ) , V_40 ) ;
F_34 ( V_41 ) ;
}
static void F_35 ( struct V_17 * V_17 , unsigned long V_15 , const void * V_43 , int V_40 )
{
void * V_41 = F_33 ( V_17 ) ;
memcpy ( V_41 + ( V_15 & ~ V_42 ) , V_43 , V_40 ) ;
F_34 ( V_41 ) ;
}
static int F_36 ( struct V_17 * V_17 , unsigned long V_15 , T_5 * V_44 )
{
T_5 V_45 ;
bool V_46 ;
F_32 ( V_17 , V_15 , & V_45 , V_47 ) ;
V_46 = F_30 ( & V_45 ) ;
if ( F_30 ( V_44 ) ) {
if ( V_46 )
return 0 ;
} else {
if ( ! V_46 )
return 0 ;
}
return 1 ;
}
int F_37 ( struct V_19 * V_20 , unsigned long V_15 ,
T_5 V_48 )
{
struct V_17 * V_49 , * V_50 ;
struct V_1 * V_2 ;
int V_51 ;
V_52:
V_51 = F_38 ( NULL , V_20 , V_15 , 1 , 0 , 1 , & V_49 , & V_2 ) ;
if ( V_51 <= 0 )
return V_51 ;
V_51 = F_36 ( V_49 , V_15 , & V_48 ) ;
if ( V_51 <= 0 )
goto V_53;
V_51 = F_39 ( V_2 ) ;
if ( V_51 )
goto V_53;
V_51 = - V_54 ;
V_50 = F_40 ( V_55 , V_2 , V_15 ) ;
if ( ! V_50 )
goto V_53;
F_41 ( V_50 ) ;
F_42 ( V_50 , V_49 ) ;
F_35 ( V_50 , V_15 , & V_48 , V_47 ) ;
V_51 = F_4 ( V_2 , V_15 , V_49 , V_50 ) ;
F_43 ( V_50 ) ;
V_53:
F_26 ( V_49 ) ;
if ( F_44 ( V_51 == - V_31 ) )
goto V_52;
return V_51 ;
}
int __weak F_45 ( struct V_56 * V_57 , struct V_19 * V_20 , unsigned long V_15 )
{
return F_37 ( V_20 , V_15 , V_38 ) ;
}
int __weak
F_46 ( struct V_56 * V_57 , struct V_19 * V_20 , unsigned long V_15 )
{
return F_37 ( V_20 , V_15 , * ( T_5 * ) & V_57 -> V_37 ) ;
}
static int F_47 ( struct V_58 * V_59 , struct V_58 * V_60 )
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
static struct V_58 * F_48 ( struct V_61 * V_61 , T_2 V_11 )
{
struct V_58 V_62 = { . V_61 = V_61 , . V_11 = V_11 } ;
struct V_63 * V_64 = V_65 . V_63 ;
struct V_58 * V_58 ;
int V_66 ;
while ( V_64 ) {
V_58 = F_49 ( V_64 , struct V_58 , V_63 ) ;
V_66 = F_47 ( & V_62 , V_58 ) ;
if ( ! V_66 ) {
F_50 ( & V_58 -> V_67 ) ;
return V_58 ;
}
if ( V_66 < 0 )
V_64 = V_64 -> V_68 ;
else
V_64 = V_64 -> V_69 ;
}
return NULL ;
}
static struct V_58 * F_51 ( struct V_61 * V_61 , T_2 V_11 )
{
struct V_58 * V_58 ;
F_52 ( & V_70 ) ;
V_58 = F_48 ( V_61 , V_11 ) ;
F_53 ( & V_70 ) ;
return V_58 ;
}
static struct V_58 * F_54 ( struct V_58 * V_58 )
{
struct V_63 * * V_71 = & V_65 . V_63 ;
struct V_63 * V_72 = NULL ;
struct V_58 * V_62 ;
int V_66 ;
while ( * V_71 ) {
V_72 = * V_71 ;
V_62 = F_49 ( V_72 , struct V_58 , V_63 ) ;
V_66 = F_47 ( V_58 , V_62 ) ;
if ( ! V_66 ) {
F_50 ( & V_62 -> V_67 ) ;
return V_62 ;
}
if ( V_66 < 0 )
V_71 = & V_72 -> V_68 ;
else
V_71 = & V_72 -> V_69 ;
}
V_62 = NULL ;
F_55 ( & V_58 -> V_63 , V_72 , V_71 ) ;
F_56 ( & V_58 -> V_63 , & V_65 ) ;
F_57 ( & V_58 -> V_67 , 2 ) ;
return V_62 ;
}
static struct V_58 * F_58 ( struct V_58 * V_58 )
{
struct V_58 * V_62 ;
F_52 ( & V_70 ) ;
V_62 = F_54 ( V_58 ) ;
F_53 ( & V_70 ) ;
return V_62 ;
}
static void F_59 ( struct V_58 * V_58 )
{
if ( F_60 ( & V_58 -> V_67 ) )
F_61 ( V_58 ) ;
}
static struct V_58 * F_62 ( struct V_61 * V_61 , T_2 V_11 )
{
struct V_58 * V_58 , * V_73 ;
V_58 = F_63 ( sizeof( struct V_58 ) , V_30 ) ;
if ( ! V_58 )
return NULL ;
V_58 -> V_61 = F_64 ( V_61 ) ;
V_58 -> V_11 = V_11 ;
F_65 ( & V_58 -> V_74 ) ;
F_65 ( & V_58 -> V_75 ) ;
V_73 = F_58 ( V_58 ) ;
if ( V_73 ) {
F_61 ( V_58 ) ;
V_58 = V_73 ;
F_66 ( V_61 ) ;
}
return V_58 ;
}
static void F_67 ( struct V_58 * V_58 , struct V_76 * V_77 )
{
F_68 ( & V_58 -> V_75 ) ;
V_77 -> V_78 = V_58 -> V_79 ;
V_58 -> V_79 = V_77 ;
F_69 ( & V_58 -> V_75 ) ;
}
static bool F_70 ( struct V_58 * V_58 , struct V_76 * V_77 )
{
struct V_76 * * V_80 ;
bool V_51 = false ;
F_68 ( & V_58 -> V_75 ) ;
for ( V_80 = & V_58 -> V_79 ; * V_80 ; V_80 = & ( * V_80 ) -> V_78 ) {
if ( * V_80 == V_77 ) {
* V_80 = V_77 -> V_78 ;
V_51 = true ;
break;
}
}
F_69 ( & V_58 -> V_75 ) ;
return V_51 ;
}
static int F_71 ( struct V_81 * V_82 , struct V_83 * V_84 ,
void * V_37 , int V_85 , T_2 V_11 )
{
struct V_17 * V_17 ;
if ( V_82 -> V_86 -> V_87 )
V_17 = F_72 ( V_82 , V_11 >> V_88 , V_84 ) ;
else
V_17 = F_73 ( V_82 , V_11 >> V_88 ) ;
if ( F_74 ( V_17 ) )
return F_75 ( V_17 ) ;
F_32 ( V_17 , V_11 , V_37 , V_85 ) ;
F_43 ( V_17 ) ;
return 0 ;
}
static int F_76 ( struct V_58 * V_58 , struct V_83 * V_84 )
{
struct V_81 * V_82 = V_58 -> V_61 -> V_89 ;
T_2 V_90 = V_58 -> V_11 ;
void * V_37 = & V_58 -> V_91 . V_37 ;
int V_92 = sizeof( V_58 -> V_91 . V_37 ) ;
int V_40 , V_24 = - V_93 ;
do {
if ( V_90 >= F_77 ( V_58 -> V_61 ) )
break;
V_40 = F_78 ( int , V_92 , V_27 - ( V_90 & ~ V_42 ) ) ;
V_24 = F_71 ( V_82 , V_84 , V_37 , V_40 , V_90 ) ;
if ( V_24 )
break;
V_37 += V_40 ;
V_90 += V_40 ;
V_92 -= V_40 ;
} while ( V_92 );
return V_24 ;
}
static int F_79 ( struct V_58 * V_58 , struct V_83 * V_83 ,
struct V_19 * V_20 , unsigned long V_15 )
{
int V_51 = 0 ;
if ( F_80 ( V_94 , & V_58 -> V_4 ) )
return V_51 ;
F_68 ( & V_58 -> V_75 ) ;
if ( F_80 ( V_94 , & V_58 -> V_4 ) )
goto V_95;
V_51 = F_76 ( V_58 , V_83 ) ;
if ( V_51 )
goto V_95;
V_51 = - V_96 ;
if ( F_31 ( ( T_5 * ) & V_58 -> V_91 . V_37 ) )
goto V_95;
V_51 = F_81 ( & V_58 -> V_91 , V_20 , V_15 ) ;
if ( V_51 )
goto V_95;
F_82 ( ( V_58 -> V_11 & ~ V_42 ) +
V_47 > V_27 ) ;
F_83 () ;
F_84 ( V_94 , & V_58 -> V_4 ) ;
V_95:
F_69 ( & V_58 -> V_75 ) ;
return V_51 ;
}
static inline bool F_85 ( struct V_76 * V_77 ,
enum V_97 V_98 , struct V_19 * V_20 )
{
return ! V_77 -> V_99 || V_77 -> V_99 ( V_77 , V_98 , V_20 ) ;
}
static bool F_86 ( struct V_58 * V_58 ,
enum V_97 V_98 , struct V_19 * V_20 )
{
struct V_76 * V_77 ;
bool V_51 = false ;
F_87 ( & V_58 -> V_75 ) ;
for ( V_77 = V_58 -> V_79 ; V_77 ; V_77 = V_77 -> V_78 ) {
V_51 = F_85 ( V_77 , V_98 , V_20 ) ;
if ( V_51 )
break;
}
F_88 ( & V_58 -> V_75 ) ;
return V_51 ;
}
static int
F_89 ( struct V_58 * V_58 , struct V_19 * V_20 ,
struct V_1 * V_2 , unsigned long V_15 )
{
bool V_100 ;
int V_51 ;
V_51 = F_79 ( V_58 , V_2 -> V_9 , V_20 , V_15 ) ;
if ( V_51 )
return V_51 ;
V_100 = ! F_80 ( V_101 , & V_20 -> V_4 ) ;
if ( V_100 )
F_84 ( V_101 , & V_20 -> V_4 ) ;
V_51 = F_45 ( & V_58 -> V_91 , V_20 , V_15 ) ;
if ( ! V_51 )
F_90 ( V_102 , & V_20 -> V_4 ) ;
else if ( V_100 )
F_90 ( V_101 , & V_20 -> V_4 ) ;
return V_51 ;
}
static int
F_91 ( struct V_58 * V_58 , struct V_19 * V_20 , unsigned long V_15 )
{
F_84 ( V_102 , & V_20 -> V_4 ) ;
return F_46 ( & V_58 -> V_91 , V_20 , V_15 ) ;
}
static inline bool F_92 ( struct V_58 * V_58 )
{
return ! F_93 ( & V_58 -> V_63 ) ;
}
static void F_94 ( struct V_58 * V_58 )
{
if ( F_95 ( ! F_92 ( V_58 ) ) )
return;
F_52 ( & V_70 ) ;
F_96 ( & V_58 -> V_63 , & V_65 ) ;
F_53 ( & V_70 ) ;
F_97 ( & V_58 -> V_63 ) ;
F_66 ( V_58 -> V_61 ) ;
F_59 ( V_58 ) ;
}
static inline struct V_103 * F_98 ( struct V_103 * V_104 )
{
struct V_103 * V_78 = V_104 -> V_78 ;
F_61 ( V_104 ) ;
return V_78 ;
}
static struct V_103 *
F_99 ( struct V_81 * V_82 , T_2 V_11 , bool V_3 )
{
unsigned long V_105 = V_11 >> V_14 ;
struct V_1 * V_2 ;
struct V_103 * V_106 = NULL ;
struct V_103 * V_107 = NULL ;
struct V_103 * V_104 ;
int V_108 = 0 ;
V_109:
F_100 ( V_82 ) ;
F_101 (vma, &mapping->i_mmap, pgoff, pgoff) {
if ( ! F_1 ( V_2 , V_3 ) )
continue;
if ( ! V_107 && ! V_108 ) {
V_107 = F_102 ( sizeof( struct V_103 ) ,
V_110 | V_111 | V_112 ) ;
if ( V_107 )
V_107 -> V_78 = NULL ;
}
if ( ! V_107 ) {
V_108 ++ ;
continue;
}
if ( ! F_103 ( & V_2 -> V_21 -> V_113 ) )
continue;
V_104 = V_107 ;
V_107 = V_107 -> V_78 ;
V_104 -> V_78 = V_106 ;
V_106 = V_104 ;
V_104 -> V_20 = V_2 -> V_21 ;
V_104 -> V_15 = F_2 ( V_2 , V_11 ) ;
}
F_104 ( V_82 ) ;
if ( ! V_108 )
goto V_95;
V_107 = V_106 ;
while ( V_106 ) {
F_105 ( V_106 -> V_20 ) ;
V_106 = V_106 -> V_78 ;
}
do {
V_104 = F_102 ( sizeof( struct V_103 ) , V_30 ) ;
if ( ! V_104 ) {
V_106 = F_106 ( - V_54 ) ;
goto V_95;
}
V_104 -> V_78 = V_107 ;
V_107 = V_104 ;
} while ( -- V_108 );
goto V_109;
V_95:
while ( V_107 )
V_107 = F_98 ( V_107 ) ;
return V_106 ;
}
static int
F_107 ( struct V_58 * V_58 , struct V_76 * V_114 )
{
bool V_3 = ! ! V_114 ;
struct V_103 * V_104 ;
int V_24 = 0 ;
F_108 ( & V_115 ) ;
V_104 = F_99 ( V_58 -> V_61 -> V_89 ,
V_58 -> V_11 , V_3 ) ;
if ( F_74 ( V_104 ) ) {
V_24 = F_75 ( V_104 ) ;
goto V_95;
}
while ( V_104 ) {
struct V_19 * V_20 = V_104 -> V_20 ;
struct V_1 * V_2 ;
if ( V_24 && V_3 )
goto free;
F_68 ( & V_20 -> V_116 ) ;
V_2 = F_109 ( V_20 , V_104 -> V_15 ) ;
if ( ! V_2 || ! F_1 ( V_2 , V_3 ) ||
F_110 ( V_2 -> V_9 ) != V_58 -> V_61 )
goto V_32;
if ( V_2 -> V_12 > V_104 -> V_15 ||
F_3 ( V_2 , V_104 -> V_15 ) != V_58 -> V_11 )
goto V_32;
if ( V_3 ) {
if ( F_85 ( V_114 ,
V_117 , V_20 ) )
V_24 = F_89 ( V_58 , V_20 , V_2 , V_104 -> V_15 ) ;
} else if ( F_80 ( V_101 , & V_20 -> V_4 ) ) {
if ( ! F_86 ( V_58 ,
V_118 , V_20 ) )
V_24 |= F_91 ( V_58 , V_20 , V_104 -> V_15 ) ;
}
V_32:
F_69 ( & V_20 -> V_116 ) ;
free:
F_105 ( V_20 ) ;
V_104 = F_98 ( V_104 ) ;
}
V_95:
F_111 ( & V_115 ) ;
return V_24 ;
}
static int F_112 ( struct V_58 * V_58 , struct V_76 * V_77 )
{
F_67 ( V_58 , V_77 ) ;
return F_107 ( V_58 , V_77 ) ;
}
static void F_113 ( struct V_58 * V_58 , struct V_76 * V_77 )
{
int V_24 ;
if ( F_95 ( ! F_70 ( V_58 , V_77 ) ) )
return;
V_24 = F_107 ( V_58 , NULL ) ;
if ( ! V_58 -> V_79 && ! V_24 )
F_94 ( V_58 ) ;
}
int F_114 ( struct V_61 * V_61 , T_2 V_11 , struct V_76 * V_77 )
{
struct V_58 * V_58 ;
int V_51 ;
if ( ! V_77 -> V_119 && ! V_77 -> V_120 )
return - V_121 ;
if ( ! V_61 -> V_89 -> V_86 -> V_87 && ! F_115 ( V_61 -> V_89 ) )
return - V_93 ;
if ( V_11 > F_77 ( V_61 ) )
return - V_121 ;
V_52:
V_58 = F_62 ( V_61 , V_11 ) ;
if ( ! V_58 )
return - V_54 ;
F_68 ( & V_58 -> V_74 ) ;
V_51 = - V_31 ;
if ( F_116 ( F_92 ( V_58 ) ) ) {
V_51 = F_112 ( V_58 , V_77 ) ;
if ( V_51 )
F_113 ( V_58 , V_77 ) ;
}
F_69 ( & V_58 -> V_74 ) ;
F_59 ( V_58 ) ;
if ( F_44 ( V_51 == - V_31 ) )
goto V_52;
return V_51 ;
}
int F_117 ( struct V_61 * V_61 , T_2 V_11 ,
struct V_76 * V_77 , bool V_122 )
{
struct V_58 * V_58 ;
struct V_76 * V_80 ;
int V_51 = - V_123 ;
V_58 = F_51 ( V_61 , V_11 ) ;
if ( F_95 ( ! V_58 ) )
return V_51 ;
F_68 ( & V_58 -> V_74 ) ;
for ( V_80 = V_58 -> V_79 ; V_80 && V_80 != V_77 ; V_80 = V_80 -> V_78 )
;
if ( V_80 )
V_51 = F_107 ( V_58 , V_122 ? V_77 : NULL ) ;
F_69 ( & V_58 -> V_74 ) ;
F_59 ( V_58 ) ;
return V_51 ;
}
void F_118 ( struct V_61 * V_61 , T_2 V_11 , struct V_76 * V_77 )
{
struct V_58 * V_58 ;
V_58 = F_51 ( V_61 , V_11 ) ;
if ( F_95 ( ! V_58 ) )
return;
F_68 ( & V_58 -> V_74 ) ;
F_113 ( V_58 , V_77 ) ;
F_69 ( & V_58 -> V_74 ) ;
F_59 ( V_58 ) ;
}
static int F_119 ( struct V_58 * V_58 , struct V_19 * V_20 )
{
struct V_1 * V_2 ;
int V_24 = 0 ;
F_87 ( & V_20 -> V_116 ) ;
for ( V_2 = V_20 -> V_124 ; V_2 ; V_2 = V_2 -> V_125 ) {
unsigned long V_15 ;
T_2 V_11 ;
if ( ! F_1 ( V_2 , false ) ||
F_110 ( V_2 -> V_9 ) != V_58 -> V_61 )
continue;
V_11 = ( T_2 ) V_2 -> V_13 << V_14 ;
if ( V_58 -> V_11 < V_11 ||
V_58 -> V_11 >= V_11 + V_2 -> V_126 - V_2 -> V_12 )
continue;
V_15 = F_2 ( V_2 , V_58 -> V_11 ) ;
V_24 |= F_91 ( V_58 , V_20 , V_15 ) ;
}
F_88 ( & V_20 -> V_116 ) ;
return V_24 ;
}
static struct V_63 *
F_120 ( struct V_61 * V_61 , T_2 V_127 , T_2 V_128 )
{
struct V_63 * V_64 = V_65 . V_63 ;
while ( V_64 ) {
struct V_58 * V_62 = F_49 ( V_64 , struct V_58 , V_63 ) ;
if ( V_61 < V_62 -> V_61 ) {
V_64 = V_64 -> V_68 ;
} else if ( V_61 > V_62 -> V_61 ) {
V_64 = V_64 -> V_69 ;
} else {
if ( V_128 < V_62 -> V_11 )
V_64 = V_64 -> V_68 ;
else if ( V_127 > V_62 -> V_11 )
V_64 = V_64 -> V_69 ;
else
break;
}
}
return V_64 ;
}
static void F_121 ( struct V_61 * V_61 ,
struct V_1 * V_2 ,
unsigned long V_129 , unsigned long V_130 ,
struct V_131 * V_132 )
{
T_2 V_127 , V_128 ;
struct V_63 * V_64 , * V_133 ;
struct V_58 * V_62 ;
F_122 ( V_132 ) ;
V_127 = F_3 ( V_2 , V_129 ) ;
V_128 = V_127 + ( V_130 - V_129 ) - 1 ;
F_52 ( & V_70 ) ;
V_64 = F_120 ( V_61 , V_127 , V_128 ) ;
if ( V_64 ) {
for ( V_133 = V_64 ; V_133 ; V_133 = F_123 ( V_133 ) ) {
V_62 = F_49 ( V_133 , struct V_58 , V_63 ) ;
if ( V_62 -> V_61 != V_61 || V_62 -> V_11 < V_127 )
break;
F_124 ( & V_62 -> V_134 , V_132 ) ;
F_50 ( & V_62 -> V_67 ) ;
}
for ( V_133 = V_64 ; ( V_133 = F_125 ( V_133 ) ) ; ) {
V_62 = F_49 ( V_133 , struct V_58 , V_63 ) ;
if ( V_62 -> V_61 != V_61 || V_62 -> V_11 > V_128 )
break;
F_124 ( & V_62 -> V_134 , V_132 ) ;
F_50 ( & V_62 -> V_67 ) ;
}
}
F_53 ( & V_70 ) ;
}
int F_126 ( struct V_1 * V_2 )
{
struct V_131 V_135 ;
struct V_58 * V_58 , * V_62 ;
struct V_61 * V_61 ;
if ( F_127 () || ! F_1 ( V_2 , true ) )
return 0 ;
V_61 = F_110 ( V_2 -> V_9 ) ;
if ( ! V_61 )
return 0 ;
F_128 ( F_129 ( V_61 ) ) ;
F_121 ( V_61 , V_2 , V_2 -> V_12 , V_2 -> V_126 , & V_135 ) ;
F_130 (uprobe, u, &tmp_list, pending_list) {
if ( ! F_131 ( V_136 ) &&
F_86 ( V_58 , V_137 , V_2 -> V_21 ) ) {
unsigned long V_15 = F_2 ( V_2 , V_58 -> V_11 ) ;
F_89 ( V_58 , V_2 -> V_21 , V_2 , V_15 ) ;
}
F_59 ( V_58 ) ;
}
F_132 ( F_129 ( V_61 ) ) ;
return 0 ;
}
static bool
F_133 ( struct V_1 * V_2 , unsigned long V_129 , unsigned long V_130 )
{
T_2 V_127 , V_128 ;
struct V_61 * V_61 ;
struct V_63 * V_64 ;
V_61 = F_110 ( V_2 -> V_9 ) ;
V_127 = F_3 ( V_2 , V_129 ) ;
V_128 = V_127 + ( V_130 - V_129 ) - 1 ;
F_52 ( & V_70 ) ;
V_64 = F_120 ( V_61 , V_127 , V_128 ) ;
F_53 ( & V_70 ) ;
return ! ! V_64 ;
}
void F_134 ( struct V_1 * V_2 , unsigned long V_129 , unsigned long V_130 )
{
if ( F_127 () || ! F_1 ( V_2 , false ) )
return;
if ( ! F_135 ( & V_2 -> V_21 -> V_113 ) )
return;
if ( ! F_80 ( V_101 , & V_2 -> V_21 -> V_4 ) ||
F_80 ( V_102 , & V_2 -> V_21 -> V_4 ) )
return;
if ( F_133 ( V_2 , V_129 , V_130 ) )
F_84 ( V_102 , & V_2 -> V_21 -> V_4 ) ;
}
static int F_136 ( struct V_19 * V_20 , struct V_138 * V_139 )
{
int V_51 = - V_140 ;
F_68 ( & V_20 -> V_116 ) ;
if ( V_20 -> V_141 . V_138 )
goto V_142;
if ( ! V_139 -> V_15 ) {
V_139 -> V_15 = F_137 ( NULL , V_143 - V_27 ,
V_27 , 0 , 0 ) ;
if ( V_139 -> V_15 & ~ V_42 ) {
V_51 = V_139 -> V_15 ;
goto V_142;
}
}
V_51 = F_138 ( V_20 , V_139 -> V_15 , V_27 ,
V_144 | V_6 | V_145 | V_146 , & V_139 -> V_17 ) ;
if ( V_51 )
goto V_142;
F_83 () ;
V_20 -> V_141 . V_138 = V_139 ;
V_142:
F_69 ( & V_20 -> V_116 ) ;
return V_51 ;
}
static struct V_138 * F_139 ( unsigned long V_15 )
{
struct V_19 * V_20 = V_136 -> V_20 ;
T_5 V_37 = V_38 ;
struct V_138 * V_139 ;
V_139 = F_102 ( sizeof( * V_139 ) , V_30 ) ;
if ( F_44 ( ! V_139 ) )
goto V_95;
V_139 -> V_147 = F_63 ( F_140 ( V_148 ) * sizeof( long ) , V_30 ) ;
if ( ! V_139 -> V_147 )
goto V_149;
V_139 -> V_17 = F_141 ( V_150 ) ;
if ( ! V_139 -> V_17 )
goto V_151;
V_139 -> V_15 = V_15 ;
F_142 ( & V_139 -> V_152 ) ;
F_84 ( 0 , V_139 -> V_147 ) ;
F_57 ( & V_139 -> V_153 , 1 ) ;
F_35 ( V_139 -> V_17 , 0 , & V_37 , V_47 ) ;
if ( ! F_136 ( V_20 , V_139 ) )
return V_139 ;
F_143 ( V_139 -> V_17 ) ;
V_151:
F_61 ( V_139 -> V_147 ) ;
V_149:
F_61 ( V_139 ) ;
V_95:
return NULL ;
}
static struct V_138 * F_144 ( void )
{
struct V_19 * V_20 = V_136 -> V_20 ;
struct V_138 * V_139 ;
if ( ! V_20 -> V_141 . V_138 )
F_139 ( 0 ) ;
V_139 = V_20 -> V_141 . V_138 ;
F_145 () ;
return V_139 ;
}
void F_146 ( struct V_19 * V_20 )
{
struct V_138 * V_139 = V_20 -> V_141 . V_138 ;
if ( ! V_139 )
return;
F_26 ( V_139 -> V_17 ) ;
F_61 ( V_139 -> V_147 ) ;
F_61 ( V_139 ) ;
}
void F_147 ( void )
{
F_148 ( & V_115 ) ;
}
void F_149 ( void )
{
F_150 ( & V_115 ) ;
}
void F_151 ( struct V_19 * V_154 , struct V_19 * V_155 )
{
V_155 -> V_141 . V_138 = NULL ;
if ( F_80 ( V_101 , & V_154 -> V_4 ) ) {
F_84 ( V_101 , & V_155 -> V_4 ) ;
F_84 ( V_102 , & V_155 -> V_4 ) ;
}
}
static unsigned long F_152 ( struct V_138 * V_139 )
{
unsigned long V_156 ;
int V_157 ;
do {
V_157 = F_153 ( V_139 -> V_147 , V_148 ) ;
if ( V_157 < V_148 ) {
if ( ! F_154 ( V_157 , V_139 -> V_147 ) )
break;
V_157 = V_148 ;
continue;
}
F_155 ( V_139 -> V_152 , ( F_135 ( & V_139 -> V_153 ) < V_148 ) ) ;
} while ( V_157 >= V_148 );
V_156 = V_139 -> V_15 + ( V_157 * V_158 ) ;
F_50 ( & V_139 -> V_153 ) ;
return V_156 ;
}
static unsigned long F_156 ( struct V_58 * V_58 )
{
struct V_138 * V_139 ;
unsigned long V_159 ;
V_139 = F_144 () ;
if ( ! V_139 )
return 0 ;
V_159 = F_152 ( V_139 ) ;
if ( F_44 ( ! V_159 ) )
return 0 ;
F_157 ( V_139 -> V_17 , V_159 ,
& V_58 -> V_91 . V_160 , sizeof( V_58 -> V_91 . V_160 ) ) ;
return V_159 ;
}
static void F_158 ( struct V_161 * V_162 )
{
struct V_138 * V_139 ;
unsigned long V_163 ;
unsigned long V_156 ;
if ( ! V_162 -> V_20 || ! V_162 -> V_20 -> V_141 . V_138 || ! V_162 -> V_164 )
return;
V_156 = V_162 -> V_164 -> V_159 ;
if ( F_44 ( ! V_156 ) )
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
F_90 ( V_157 , V_139 -> V_147 ) ;
F_159 ( & V_139 -> V_153 ) ;
if ( F_160 ( & V_139 -> V_152 ) )
F_161 ( & V_139 -> V_152 ) ;
V_162 -> V_164 -> V_159 = 0 ;
}
}
void __weak F_157 ( struct V_17 * V_17 , unsigned long V_15 ,
void * V_43 , unsigned long V_40 )
{
F_35 ( V_17 , V_15 , V_43 , V_40 ) ;
F_162 ( V_17 ) ;
}
unsigned long __weak F_163 ( struct V_165 * V_166 )
{
return F_164 ( V_166 ) - V_47 ;
}
unsigned long F_165 ( struct V_165 * V_166 )
{
struct V_167 * V_164 = V_136 -> V_164 ;
if ( F_44 ( V_164 && V_164 -> V_168 ) )
return V_164 -> V_15 ;
return F_164 ( V_166 ) ;
}
void F_166 ( struct V_161 * V_133 )
{
struct V_167 * V_164 = V_133 -> V_164 ;
struct V_169 * V_170 , * V_171 ;
if ( ! V_164 )
return;
if ( V_164 -> V_168 )
F_59 ( V_164 -> V_168 ) ;
V_170 = V_164 -> V_172 ;
while ( V_170 ) {
V_171 = V_170 ;
V_170 = V_170 -> V_78 ;
F_59 ( V_171 -> V_58 ) ;
F_61 ( V_171 ) ;
}
F_158 ( V_133 ) ;
F_61 ( V_164 ) ;
V_133 -> V_164 = NULL ;
}
static struct V_167 * F_167 ( void )
{
if ( ! V_136 -> V_164 )
V_136 -> V_164 = F_63 ( sizeof( struct V_167 ) , V_30 ) ;
return V_136 -> V_164 ;
}
static int F_168 ( struct V_161 * V_133 , struct V_167 * V_173 )
{
struct V_167 * V_174 ;
struct V_169 * * V_71 , * V_175 , * V_64 ;
V_174 = F_63 ( sizeof( struct V_167 ) , V_30 ) ;
if ( ! V_174 )
return - V_54 ;
V_133 -> V_164 = V_174 ;
V_71 = & V_174 -> V_172 ;
for ( V_175 = V_173 -> V_172 ; V_175 ; V_175 = V_175 -> V_78 ) {
V_64 = F_102 ( sizeof( struct V_169 ) , V_30 ) ;
if ( ! V_64 )
return - V_54 ;
* V_64 = * V_175 ;
F_50 ( & V_64 -> V_58 -> V_67 ) ;
V_64 -> V_78 = NULL ;
* V_71 = V_64 ;
V_71 = & V_64 -> V_78 ;
V_174 -> V_176 ++ ;
}
return 0 ;
}
static void F_169 ( struct V_161 * V_133 , const char * V_177 )
{
F_170 ( L_1 ,
V_136 -> V_178 , V_136 -> V_179 , V_177 ) ;
}
static void F_171 ( struct V_180 * V_181 )
{
if ( V_136 -> V_4 & V_182 )
return;
if ( ! F_139 ( V_136 -> V_164 -> V_183 ) )
F_169 ( V_136 , L_2 ) ;
}
void F_172 ( struct V_161 * V_133 , unsigned long V_4 )
{
struct V_167 * V_164 = V_136 -> V_164 ;
struct V_19 * V_20 = V_136 -> V_20 ;
struct V_138 * V_139 ;
V_133 -> V_164 = NULL ;
if ( ! V_164 || ! V_164 -> V_172 )
return;
if ( V_20 == V_133 -> V_20 && ! ( V_4 & V_184 ) )
return;
if ( F_168 ( V_133 , V_164 ) )
return F_169 ( V_133 , L_3 ) ;
V_139 = V_20 -> V_141 . V_138 ;
if ( ! V_139 )
return F_169 ( V_133 , L_2 ) ;
if ( V_20 == V_133 -> V_20 )
return;
V_133 -> V_164 -> V_183 = V_139 -> V_15 ;
F_173 ( & V_133 -> V_164 -> F_171 , F_171 ) ;
F_174 ( V_133 , & V_133 -> V_164 -> F_171 , true ) ;
}
static unsigned long F_175 ( void )
{
struct V_138 * V_139 ;
unsigned long V_185 = - 1 ;
V_139 = V_136 -> V_20 -> V_141 . V_138 ;
F_145 () ;
if ( V_139 )
V_185 = V_139 -> V_15 ;
return V_185 ;
}
static void F_176 ( struct V_58 * V_58 , struct V_165 * V_166 )
{
struct V_169 * V_170 ;
struct V_167 * V_164 ;
unsigned long V_186 , V_185 ;
bool V_187 = false ;
if ( ! F_144 () )
return;
V_164 = F_167 () ;
if ( ! V_164 )
return;
if ( V_164 -> V_176 >= V_188 ) {
F_177 ( V_189 L_4
L_5 ,
V_136 -> V_179 , V_136 -> V_190 ) ;
return;
}
V_170 = F_63 ( sizeof( struct V_169 ) , V_30 ) ;
if ( ! V_170 )
goto V_142;
V_185 = F_175 () ;
V_186 = F_178 ( V_185 , V_166 ) ;
if ( V_186 == - 1 )
goto V_142;
if ( V_186 == V_185 ) {
if ( ! V_164 -> V_172 ) {
F_170 ( L_6 ,
V_136 -> V_179 , V_136 -> V_190 ) ;
goto V_142;
}
V_187 = true ;
V_186 = V_164 -> V_172 -> V_186 ;
}
F_50 ( & V_58 -> V_67 ) ;
V_170 -> V_58 = V_58 ;
V_170 -> V_191 = F_164 ( V_166 ) ;
V_170 -> V_186 = V_186 ;
V_170 -> V_187 = V_187 ;
V_164 -> V_176 ++ ;
V_170 -> V_78 = V_164 -> V_172 ;
V_164 -> V_172 = V_170 ;
return;
V_142:
F_61 ( V_170 ) ;
}
static int
F_179 ( struct V_58 * V_58 , struct V_165 * V_166 , unsigned long V_192 )
{
struct V_167 * V_164 ;
unsigned long V_159 ;
int V_24 ;
V_164 = F_167 () ;
if ( ! V_164 )
return - V_54 ;
V_159 = F_156 ( V_58 ) ;
if ( ! V_159 )
return - V_54 ;
V_164 -> V_159 = V_159 ;
V_164 -> V_15 = V_192 ;
V_24 = F_180 ( & V_58 -> V_91 , V_166 ) ;
if ( F_44 ( V_24 ) ) {
F_158 ( V_136 ) ;
return V_24 ;
}
V_164 -> V_168 = V_58 ;
V_164 -> V_193 = V_194 ;
return 0 ;
}
bool F_181 ( void )
{
struct V_161 * V_133 = V_136 ;
struct V_167 * V_164 = V_133 -> V_164 ;
if ( F_116 ( ! V_164 || ! V_164 -> V_168 ) )
return false ;
F_182 ( V_164 -> V_193 != V_194 ) ;
if ( F_183 ( V_133 ) ) {
F_184 ( & V_133 -> V_195 -> V_196 ) ;
F_185 ( V_133 , V_197 ) ;
F_186 ( & V_133 -> V_195 -> V_196 ) ;
if ( F_187 ( V_133 ) || F_188 ( V_133 ) ) {
V_164 -> V_193 = V_198 ;
F_189 ( V_133 , V_199 ) ;
}
}
return true ;
}
static void F_190 ( struct V_19 * V_20 )
{
struct V_1 * V_2 ;
for ( V_2 = V_20 -> V_124 ; V_2 ; V_2 = V_2 -> V_125 ) {
if ( ! F_1 ( V_2 , false ) )
continue;
if ( F_133 ( V_2 , V_2 -> V_12 , V_2 -> V_126 ) )
return;
}
F_90 ( V_101 , & V_20 -> V_4 ) ;
}
static int F_191 ( struct V_19 * V_20 , unsigned long V_15 )
{
struct V_17 * V_17 ;
T_5 V_48 ;
int V_200 ;
F_192 () ;
V_200 = F_193 ( & V_48 , ( void V_201 * ) V_15 ,
sizeof( V_48 ) ) ;
F_194 () ;
if ( F_116 ( V_200 == 0 ) )
goto V_95;
V_200 = F_38 ( NULL , V_20 , V_15 , 1 , 0 , 1 , & V_17 , NULL ) ;
if ( V_200 < 0 )
return V_200 ;
F_32 ( V_17 , V_15 , & V_48 , V_47 ) ;
F_26 ( V_17 ) ;
V_95:
return F_31 ( & V_48 ) ;
}
static struct V_58 * F_195 ( unsigned long V_192 , int * V_46 )
{
struct V_19 * V_20 = V_136 -> V_20 ;
struct V_58 * V_58 = NULL ;
struct V_1 * V_2 ;
F_87 ( & V_20 -> V_116 ) ;
V_2 = F_109 ( V_20 , V_192 ) ;
if ( V_2 && V_2 -> V_12 <= V_192 ) {
if ( F_1 ( V_2 , false ) ) {
struct V_61 * V_61 = F_110 ( V_2 -> V_9 ) ;
T_2 V_11 = F_3 ( V_2 , V_192 ) ;
V_58 = F_51 ( V_61 , V_11 ) ;
}
if ( ! V_58 )
* V_46 = F_191 ( V_20 , V_192 ) ;
} else {
* V_46 = - V_202 ;
}
if ( ! V_58 && F_196 ( V_102 , & V_20 -> V_4 ) )
F_190 ( V_20 ) ;
F_88 ( & V_20 -> V_116 ) ;
return V_58 ;
}
static void F_197 ( struct V_58 * V_58 , struct V_165 * V_166 )
{
struct V_76 * V_77 ;
int remove = V_203 ;
bool V_204 = false ;
F_87 ( & V_58 -> V_74 ) ;
for ( V_77 = V_58 -> V_79 ; V_77 ; V_77 = V_77 -> V_78 ) {
int V_205 = 0 ;
if ( V_77 -> V_119 ) {
V_205 = V_77 -> V_119 ( V_77 , V_166 ) ;
F_198 ( V_205 & ~ V_206 ,
L_7 , V_205 , V_77 -> V_119 ) ;
}
if ( V_77 -> V_120 )
V_204 = true ;
remove &= V_205 ;
}
if ( V_204 && ! remove )
F_176 ( V_58 , V_166 ) ;
if ( remove && V_58 -> V_79 ) {
F_95 ( ! F_92 ( V_58 ) ) ;
F_119 ( V_58 , V_136 -> V_20 ) ;
}
F_88 ( & V_58 -> V_74 ) ;
}
static void
F_199 ( struct V_169 * V_170 , struct V_165 * V_166 )
{
struct V_58 * V_58 = V_170 -> V_58 ;
struct V_76 * V_77 ;
F_87 ( & V_58 -> V_74 ) ;
for ( V_77 = V_58 -> V_79 ; V_77 ; V_77 = V_77 -> V_78 ) {
if ( V_77 -> V_120 )
V_77 -> V_120 ( V_77 , V_170 -> V_191 , V_166 ) ;
}
F_88 ( & V_58 -> V_74 ) ;
}
static bool F_200 ( struct V_165 * V_166 )
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
F_201 ( V_166 , V_170 -> V_186 ) ;
for (; ; ) {
F_199 ( V_170 , V_166 ) ;
V_187 = V_170 -> V_187 ;
F_59 ( V_170 -> V_58 ) ;
V_171 = V_170 ;
V_170 = V_170 -> V_78 ;
F_61 ( V_171 ) ;
V_164 -> V_176 -- ;
if ( ! V_187 )
break;
F_82 ( ! V_170 ) ;
}
V_164 -> V_172 = V_170 ;
return true ;
}
bool __weak F_202 ( struct V_56 * V_207 , struct V_165 * V_166 )
{
return false ;
}
static void F_203 ( struct V_165 * V_166 )
{
struct V_58 * V_58 ;
unsigned long V_192 ;
int V_208 ( V_46 ) ;
V_192 = F_163 ( V_166 ) ;
if ( V_192 == F_175 () ) {
if ( F_200 ( V_166 ) )
return;
F_170 ( L_8 ,
V_136 -> V_179 , V_136 -> V_190 ) ;
}
V_58 = F_195 ( V_192 , & V_46 ) ;
if ( ! V_58 ) {
if ( V_46 > 0 ) {
F_204 ( V_209 , V_136 , 0 ) ;
} else {
F_201 ( V_166 , V_192 ) ;
}
return;
}
F_201 ( V_166 , V_192 ) ;
F_205 () ;
if ( F_44 ( ! F_80 ( V_94 , & V_58 -> V_4 ) ) )
goto V_95;
if ( ! F_167 () )
goto V_95;
if ( F_202 ( & V_58 -> V_91 , V_166 ) )
goto V_95;
F_197 ( V_58 , V_166 ) ;
if ( F_206 ( & V_58 -> V_91 , V_166 ) )
goto V_95;
if ( ! F_179 ( V_58 , V_166 , V_192 ) )
return;
V_95:
F_59 ( V_58 ) ;
}
static void F_207 ( struct V_167 * V_164 , struct V_165 * V_166 )
{
struct V_58 * V_58 ;
int V_24 = 0 ;
V_58 = V_164 -> V_168 ;
if ( V_164 -> V_193 == V_210 )
V_24 = F_208 ( & V_58 -> V_91 , V_166 ) ;
else if ( V_164 -> V_193 == V_198 )
F_209 ( & V_58 -> V_91 , V_166 ) ;
else
F_182 ( 1 ) ;
F_59 ( V_58 ) ;
V_164 -> V_168 = NULL ;
V_164 -> V_193 = V_211 ;
F_158 ( V_136 ) ;
F_184 ( & V_136 -> V_195 -> V_196 ) ;
F_210 () ;
F_186 ( & V_136 -> V_195 -> V_196 ) ;
if ( F_44 ( V_24 ) ) {
F_169 ( V_136 , L_9 ) ;
F_211 ( V_212 , V_213 , V_136 ) ;
}
}
void F_212 ( struct V_165 * V_166 )
{
struct V_167 * V_164 ;
F_213 ( V_199 ) ;
V_164 = V_136 -> V_164 ;
if ( V_164 && V_164 -> V_168 )
F_207 ( V_164 , V_166 ) ;
else
F_203 ( V_166 ) ;
}
int F_214 ( struct V_165 * V_166 )
{
if ( ! V_136 -> V_20 )
return 0 ;
if ( ! F_80 ( V_101 , & V_136 -> V_20 -> V_4 ) &&
( ! V_136 -> V_164 || ! V_136 -> V_164 -> V_172 ) )
return 0 ;
F_215 ( V_199 ) ;
return 1 ;
}
int F_216 ( struct V_165 * V_166 )
{
struct V_167 * V_164 = V_136 -> V_164 ;
if ( ! V_136 -> V_20 || ! V_164 || ! V_164 -> V_168 )
return 0 ;
V_164 -> V_193 = V_210 ;
F_215 ( V_199 ) ;
return 1 ;
}
static int T_6 F_217 ( void )
{
int V_214 ;
for ( V_214 = 0 ; V_214 < V_215 ; V_214 ++ )
F_218 ( & V_216 [ V_214 ] ) ;
if ( F_219 ( & V_115 ) )
return - V_54 ;
return F_220 ( & V_217 ) ;
}
