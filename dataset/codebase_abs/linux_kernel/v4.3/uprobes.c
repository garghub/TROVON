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
static struct V_58 * F_47 ( struct V_58 * V_58 )
{
F_48 ( & V_58 -> V_59 ) ;
return V_58 ;
}
static void F_49 ( struct V_58 * V_58 )
{
if ( F_50 ( & V_58 -> V_59 ) )
F_51 ( V_58 ) ;
}
static int F_52 ( struct V_58 * V_60 , struct V_58 * V_61 )
{
if ( V_60 -> V_62 < V_61 -> V_62 )
return - 1 ;
if ( V_60 -> V_62 > V_61 -> V_62 )
return 1 ;
if ( V_60 -> V_11 < V_61 -> V_11 )
return - 1 ;
if ( V_60 -> V_11 > V_61 -> V_11 )
return 1 ;
return 0 ;
}
static struct V_58 * F_53 ( struct V_62 * V_62 , T_2 V_11 )
{
struct V_58 V_63 = { . V_62 = V_62 , . V_11 = V_11 } ;
struct V_64 * V_65 = V_66 . V_64 ;
struct V_58 * V_58 ;
int V_67 ;
while ( V_65 ) {
V_58 = F_54 ( V_65 , struct V_58 , V_64 ) ;
V_67 = F_52 ( & V_63 , V_58 ) ;
if ( ! V_67 )
return F_47 ( V_58 ) ;
if ( V_67 < 0 )
V_65 = V_65 -> V_68 ;
else
V_65 = V_65 -> V_69 ;
}
return NULL ;
}
static struct V_58 * F_55 ( struct V_62 * V_62 , T_2 V_11 )
{
struct V_58 * V_58 ;
F_56 ( & V_70 ) ;
V_58 = F_53 ( V_62 , V_11 ) ;
F_57 ( & V_70 ) ;
return V_58 ;
}
static struct V_58 * F_58 ( struct V_58 * V_58 )
{
struct V_64 * * V_71 = & V_66 . V_64 ;
struct V_64 * V_72 = NULL ;
struct V_58 * V_63 ;
int V_67 ;
while ( * V_71 ) {
V_72 = * V_71 ;
V_63 = F_54 ( V_72 , struct V_58 , V_64 ) ;
V_67 = F_52 ( V_58 , V_63 ) ;
if ( ! V_67 )
return F_47 ( V_63 ) ;
if ( V_67 < 0 )
V_71 = & V_72 -> V_68 ;
else
V_71 = & V_72 -> V_69 ;
}
V_63 = NULL ;
F_59 ( & V_58 -> V_64 , V_72 , V_71 ) ;
F_60 ( & V_58 -> V_64 , & V_66 ) ;
F_61 ( & V_58 -> V_59 , 2 ) ;
return V_63 ;
}
static struct V_58 * F_62 ( struct V_58 * V_58 )
{
struct V_58 * V_63 ;
F_56 ( & V_70 ) ;
V_63 = F_58 ( V_58 ) ;
F_57 ( & V_70 ) ;
return V_63 ;
}
static struct V_58 * F_63 ( struct V_62 * V_62 , T_2 V_11 )
{
struct V_58 * V_58 , * V_73 ;
V_58 = F_64 ( sizeof( struct V_58 ) , V_30 ) ;
if ( ! V_58 )
return NULL ;
V_58 -> V_62 = F_65 ( V_62 ) ;
V_58 -> V_11 = V_11 ;
F_66 ( & V_58 -> V_74 ) ;
F_66 ( & V_58 -> V_75 ) ;
V_73 = F_62 ( V_58 ) ;
if ( V_73 ) {
F_51 ( V_58 ) ;
V_58 = V_73 ;
F_67 ( V_62 ) ;
}
return V_58 ;
}
static void F_68 ( struct V_58 * V_58 , struct V_76 * V_77 )
{
F_69 ( & V_58 -> V_75 ) ;
V_77 -> V_78 = V_58 -> V_79 ;
V_58 -> V_79 = V_77 ;
F_70 ( & V_58 -> V_75 ) ;
}
static bool F_71 ( struct V_58 * V_58 , struct V_76 * V_77 )
{
struct V_76 * * V_80 ;
bool V_51 = false ;
F_69 ( & V_58 -> V_75 ) ;
for ( V_80 = & V_58 -> V_79 ; * V_80 ; V_80 = & ( * V_80 ) -> V_78 ) {
if ( * V_80 == V_77 ) {
* V_80 = V_77 -> V_78 ;
V_51 = true ;
break;
}
}
F_70 ( & V_58 -> V_75 ) ;
return V_51 ;
}
static int F_72 ( struct V_81 * V_82 , struct V_83 * V_84 ,
void * V_37 , int V_85 , T_2 V_11 )
{
struct V_17 * V_17 ;
if ( V_82 -> V_86 -> V_87 )
V_17 = F_73 ( V_82 , V_11 >> V_88 , V_84 ) ;
else
V_17 = F_74 ( V_82 , V_11 >> V_88 ) ;
if ( F_75 ( V_17 ) )
return F_76 ( V_17 ) ;
F_32 ( V_17 , V_11 , V_37 , V_85 ) ;
F_43 ( V_17 ) ;
return 0 ;
}
static int F_77 ( struct V_58 * V_58 , struct V_83 * V_84 )
{
struct V_81 * V_82 = V_58 -> V_62 -> V_89 ;
T_2 V_90 = V_58 -> V_11 ;
void * V_37 = & V_58 -> V_91 . V_37 ;
int V_92 = sizeof( V_58 -> V_91 . V_37 ) ;
int V_40 , V_24 = - V_93 ;
do {
if ( V_90 >= F_78 ( V_58 -> V_62 ) )
break;
V_40 = F_79 ( int , V_92 , V_27 - ( V_90 & ~ V_42 ) ) ;
V_24 = F_72 ( V_82 , V_84 , V_37 , V_40 , V_90 ) ;
if ( V_24 )
break;
V_37 += V_40 ;
V_90 += V_40 ;
V_92 -= V_40 ;
} while ( V_92 );
return V_24 ;
}
static int F_80 ( struct V_58 * V_58 , struct V_83 * V_83 ,
struct V_19 * V_20 , unsigned long V_15 )
{
int V_51 = 0 ;
if ( F_81 ( V_94 , & V_58 -> V_4 ) )
return V_51 ;
F_69 ( & V_58 -> V_75 ) ;
if ( F_81 ( V_94 , & V_58 -> V_4 ) )
goto V_95;
V_51 = F_77 ( V_58 , V_83 ) ;
if ( V_51 )
goto V_95;
V_51 = - V_96 ;
if ( F_31 ( ( T_5 * ) & V_58 -> V_91 . V_37 ) )
goto V_95;
V_51 = F_82 ( & V_58 -> V_91 , V_20 , V_15 ) ;
if ( V_51 )
goto V_95;
F_83 ( ( V_58 -> V_11 & ~ V_42 ) +
V_47 > V_27 ) ;
F_84 () ;
F_85 ( V_94 , & V_58 -> V_4 ) ;
V_95:
F_70 ( & V_58 -> V_75 ) ;
return V_51 ;
}
static inline bool F_86 ( struct V_76 * V_77 ,
enum V_97 V_98 , struct V_19 * V_20 )
{
return ! V_77 -> V_99 || V_77 -> V_99 ( V_77 , V_98 , V_20 ) ;
}
static bool F_87 ( struct V_58 * V_58 ,
enum V_97 V_98 , struct V_19 * V_20 )
{
struct V_76 * V_77 ;
bool V_51 = false ;
F_88 ( & V_58 -> V_75 ) ;
for ( V_77 = V_58 -> V_79 ; V_77 ; V_77 = V_77 -> V_78 ) {
V_51 = F_86 ( V_77 , V_98 , V_20 ) ;
if ( V_51 )
break;
}
F_89 ( & V_58 -> V_75 ) ;
return V_51 ;
}
static int
F_90 ( struct V_58 * V_58 , struct V_19 * V_20 ,
struct V_1 * V_2 , unsigned long V_15 )
{
bool V_100 ;
int V_51 ;
V_51 = F_80 ( V_58 , V_2 -> V_9 , V_20 , V_15 ) ;
if ( V_51 )
return V_51 ;
V_100 = ! F_81 ( V_101 , & V_20 -> V_4 ) ;
if ( V_100 )
F_85 ( V_101 , & V_20 -> V_4 ) ;
V_51 = F_45 ( & V_58 -> V_91 , V_20 , V_15 ) ;
if ( ! V_51 )
F_91 ( V_102 , & V_20 -> V_4 ) ;
else if ( V_100 )
F_91 ( V_101 , & V_20 -> V_4 ) ;
return V_51 ;
}
static int
F_92 ( struct V_58 * V_58 , struct V_19 * V_20 , unsigned long V_15 )
{
F_85 ( V_102 , & V_20 -> V_4 ) ;
return F_46 ( & V_58 -> V_91 , V_20 , V_15 ) ;
}
static inline bool F_93 ( struct V_58 * V_58 )
{
return ! F_94 ( & V_58 -> V_64 ) ;
}
static void F_95 ( struct V_58 * V_58 )
{
if ( F_96 ( ! F_93 ( V_58 ) ) )
return;
F_56 ( & V_70 ) ;
F_97 ( & V_58 -> V_64 , & V_66 ) ;
F_57 ( & V_70 ) ;
F_98 ( & V_58 -> V_64 ) ;
F_67 ( V_58 -> V_62 ) ;
F_49 ( V_58 ) ;
}
static inline struct V_103 * F_99 ( struct V_103 * V_104 )
{
struct V_103 * V_78 = V_104 -> V_78 ;
F_51 ( V_104 ) ;
return V_78 ;
}
static struct V_103 *
F_100 ( struct V_81 * V_82 , T_2 V_11 , bool V_3 )
{
unsigned long V_105 = V_11 >> V_14 ;
struct V_1 * V_2 ;
struct V_103 * V_106 = NULL ;
struct V_103 * V_107 = NULL ;
struct V_103 * V_104 ;
int V_108 = 0 ;
V_109:
F_101 ( V_82 ) ;
F_102 (vma, &mapping->i_mmap, pgoff, pgoff) {
if ( ! F_1 ( V_2 , V_3 ) )
continue;
if ( ! V_107 && ! V_108 ) {
V_107 = F_103 ( sizeof( struct V_103 ) ,
V_110 | V_111 | V_112 ) ;
if ( V_107 )
V_107 -> V_78 = NULL ;
}
if ( ! V_107 ) {
V_108 ++ ;
continue;
}
if ( ! F_104 ( & V_2 -> V_21 -> V_113 ) )
continue;
V_104 = V_107 ;
V_107 = V_107 -> V_78 ;
V_104 -> V_78 = V_106 ;
V_106 = V_104 ;
V_104 -> V_20 = V_2 -> V_21 ;
V_104 -> V_15 = F_2 ( V_2 , V_11 ) ;
}
F_105 ( V_82 ) ;
if ( ! V_108 )
goto V_95;
V_107 = V_106 ;
while ( V_106 ) {
F_106 ( V_106 -> V_20 ) ;
V_106 = V_106 -> V_78 ;
}
do {
V_104 = F_103 ( sizeof( struct V_103 ) , V_30 ) ;
if ( ! V_104 ) {
V_106 = F_107 ( - V_54 ) ;
goto V_95;
}
V_104 -> V_78 = V_107 ;
V_107 = V_104 ;
} while ( -- V_108 );
goto V_109;
V_95:
while ( V_107 )
V_107 = F_99 ( V_107 ) ;
return V_106 ;
}
static int
F_108 ( struct V_58 * V_58 , struct V_76 * V_114 )
{
bool V_3 = ! ! V_114 ;
struct V_103 * V_104 ;
int V_24 = 0 ;
F_109 ( & V_115 ) ;
V_104 = F_100 ( V_58 -> V_62 -> V_89 ,
V_58 -> V_11 , V_3 ) ;
if ( F_75 ( V_104 ) ) {
V_24 = F_76 ( V_104 ) ;
goto V_95;
}
while ( V_104 ) {
struct V_19 * V_20 = V_104 -> V_20 ;
struct V_1 * V_2 ;
if ( V_24 && V_3 )
goto free;
F_69 ( & V_20 -> V_116 ) ;
V_2 = F_110 ( V_20 , V_104 -> V_15 ) ;
if ( ! V_2 || ! F_1 ( V_2 , V_3 ) ||
F_111 ( V_2 -> V_9 ) != V_58 -> V_62 )
goto V_32;
if ( V_2 -> V_12 > V_104 -> V_15 ||
F_3 ( V_2 , V_104 -> V_15 ) != V_58 -> V_11 )
goto V_32;
if ( V_3 ) {
if ( F_86 ( V_114 ,
V_117 , V_20 ) )
V_24 = F_90 ( V_58 , V_20 , V_2 , V_104 -> V_15 ) ;
} else if ( F_81 ( V_101 , & V_20 -> V_4 ) ) {
if ( ! F_87 ( V_58 ,
V_118 , V_20 ) )
V_24 |= F_92 ( V_58 , V_20 , V_104 -> V_15 ) ;
}
V_32:
F_70 ( & V_20 -> V_116 ) ;
free:
F_106 ( V_20 ) ;
V_104 = F_99 ( V_104 ) ;
}
V_95:
F_112 ( & V_115 ) ;
return V_24 ;
}
static int F_113 ( struct V_58 * V_58 , struct V_76 * V_77 )
{
F_68 ( V_58 , V_77 ) ;
return F_108 ( V_58 , V_77 ) ;
}
static void F_114 ( struct V_58 * V_58 , struct V_76 * V_77 )
{
int V_24 ;
if ( F_96 ( ! F_71 ( V_58 , V_77 ) ) )
return;
V_24 = F_108 ( V_58 , NULL ) ;
if ( ! V_58 -> V_79 && ! V_24 )
F_95 ( V_58 ) ;
}
int F_115 ( struct V_62 * V_62 , T_2 V_11 , struct V_76 * V_77 )
{
struct V_58 * V_58 ;
int V_51 ;
if ( ! V_77 -> V_119 && ! V_77 -> V_120 )
return - V_121 ;
if ( ! V_62 -> V_89 -> V_86 -> V_87 && ! F_116 ( V_62 -> V_89 ) )
return - V_93 ;
if ( V_11 > F_78 ( V_62 ) )
return - V_121 ;
V_52:
V_58 = F_63 ( V_62 , V_11 ) ;
if ( ! V_58 )
return - V_54 ;
F_69 ( & V_58 -> V_74 ) ;
V_51 = - V_31 ;
if ( F_117 ( F_93 ( V_58 ) ) ) {
V_51 = F_113 ( V_58 , V_77 ) ;
if ( V_51 )
F_114 ( V_58 , V_77 ) ;
}
F_70 ( & V_58 -> V_74 ) ;
F_49 ( V_58 ) ;
if ( F_44 ( V_51 == - V_31 ) )
goto V_52;
return V_51 ;
}
int F_118 ( struct V_62 * V_62 , T_2 V_11 ,
struct V_76 * V_77 , bool V_122 )
{
struct V_58 * V_58 ;
struct V_76 * V_80 ;
int V_51 = - V_123 ;
V_58 = F_55 ( V_62 , V_11 ) ;
if ( F_96 ( ! V_58 ) )
return V_51 ;
F_69 ( & V_58 -> V_74 ) ;
for ( V_80 = V_58 -> V_79 ; V_80 && V_80 != V_77 ; V_80 = V_80 -> V_78 )
;
if ( V_80 )
V_51 = F_108 ( V_58 , V_122 ? V_77 : NULL ) ;
F_70 ( & V_58 -> V_74 ) ;
F_49 ( V_58 ) ;
return V_51 ;
}
void F_119 ( struct V_62 * V_62 , T_2 V_11 , struct V_76 * V_77 )
{
struct V_58 * V_58 ;
V_58 = F_55 ( V_62 , V_11 ) ;
if ( F_96 ( ! V_58 ) )
return;
F_69 ( & V_58 -> V_74 ) ;
F_114 ( V_58 , V_77 ) ;
F_70 ( & V_58 -> V_74 ) ;
F_49 ( V_58 ) ;
}
static int F_120 ( struct V_58 * V_58 , struct V_19 * V_20 )
{
struct V_1 * V_2 ;
int V_24 = 0 ;
F_88 ( & V_20 -> V_116 ) ;
for ( V_2 = V_20 -> V_124 ; V_2 ; V_2 = V_2 -> V_125 ) {
unsigned long V_15 ;
T_2 V_11 ;
if ( ! F_1 ( V_2 , false ) ||
F_111 ( V_2 -> V_9 ) != V_58 -> V_62 )
continue;
V_11 = ( T_2 ) V_2 -> V_13 << V_14 ;
if ( V_58 -> V_11 < V_11 ||
V_58 -> V_11 >= V_11 + V_2 -> V_126 - V_2 -> V_12 )
continue;
V_15 = F_2 ( V_2 , V_58 -> V_11 ) ;
V_24 |= F_92 ( V_58 , V_20 , V_15 ) ;
}
F_89 ( & V_20 -> V_116 ) ;
return V_24 ;
}
static struct V_64 *
F_121 ( struct V_62 * V_62 , T_2 V_127 , T_2 V_128 )
{
struct V_64 * V_65 = V_66 . V_64 ;
while ( V_65 ) {
struct V_58 * V_63 = F_54 ( V_65 , struct V_58 , V_64 ) ;
if ( V_62 < V_63 -> V_62 ) {
V_65 = V_65 -> V_68 ;
} else if ( V_62 > V_63 -> V_62 ) {
V_65 = V_65 -> V_69 ;
} else {
if ( V_128 < V_63 -> V_11 )
V_65 = V_65 -> V_68 ;
else if ( V_127 > V_63 -> V_11 )
V_65 = V_65 -> V_69 ;
else
break;
}
}
return V_65 ;
}
static void F_122 ( struct V_62 * V_62 ,
struct V_1 * V_2 ,
unsigned long V_129 , unsigned long V_130 ,
struct V_131 * V_132 )
{
T_2 V_127 , V_128 ;
struct V_64 * V_65 , * V_133 ;
struct V_58 * V_63 ;
F_123 ( V_132 ) ;
V_127 = F_3 ( V_2 , V_129 ) ;
V_128 = V_127 + ( V_130 - V_129 ) - 1 ;
F_56 ( & V_70 ) ;
V_65 = F_121 ( V_62 , V_127 , V_128 ) ;
if ( V_65 ) {
for ( V_133 = V_65 ; V_133 ; V_133 = F_124 ( V_133 ) ) {
V_63 = F_54 ( V_133 , struct V_58 , V_64 ) ;
if ( V_63 -> V_62 != V_62 || V_63 -> V_11 < V_127 )
break;
F_125 ( & V_63 -> V_134 , V_132 ) ;
F_47 ( V_63 ) ;
}
for ( V_133 = V_65 ; ( V_133 = F_126 ( V_133 ) ) ; ) {
V_63 = F_54 ( V_133 , struct V_58 , V_64 ) ;
if ( V_63 -> V_62 != V_62 || V_63 -> V_11 > V_128 )
break;
F_125 ( & V_63 -> V_134 , V_132 ) ;
F_47 ( V_63 ) ;
}
}
F_57 ( & V_70 ) ;
}
int F_127 ( struct V_1 * V_2 )
{
struct V_131 V_135 ;
struct V_58 * V_58 , * V_63 ;
struct V_62 * V_62 ;
if ( F_128 () || ! F_1 ( V_2 , true ) )
return 0 ;
V_62 = F_111 ( V_2 -> V_9 ) ;
if ( ! V_62 )
return 0 ;
F_129 ( F_130 ( V_62 ) ) ;
F_122 ( V_62 , V_2 , V_2 -> V_12 , V_2 -> V_126 , & V_135 ) ;
F_131 (uprobe, u, &tmp_list, pending_list) {
if ( ! F_132 ( V_136 ) &&
F_87 ( V_58 , V_137 , V_2 -> V_21 ) ) {
unsigned long V_15 = F_2 ( V_2 , V_58 -> V_11 ) ;
F_90 ( V_58 , V_2 -> V_21 , V_2 , V_15 ) ;
}
F_49 ( V_58 ) ;
}
F_133 ( F_130 ( V_62 ) ) ;
return 0 ;
}
static bool
F_134 ( struct V_1 * V_2 , unsigned long V_129 , unsigned long V_130 )
{
T_2 V_127 , V_128 ;
struct V_62 * V_62 ;
struct V_64 * V_65 ;
V_62 = F_111 ( V_2 -> V_9 ) ;
V_127 = F_3 ( V_2 , V_129 ) ;
V_128 = V_127 + ( V_130 - V_129 ) - 1 ;
F_56 ( & V_70 ) ;
V_65 = F_121 ( V_62 , V_127 , V_128 ) ;
F_57 ( & V_70 ) ;
return ! ! V_65 ;
}
void F_135 ( struct V_1 * V_2 , unsigned long V_129 , unsigned long V_130 )
{
if ( F_128 () || ! F_1 ( V_2 , false ) )
return;
if ( ! F_136 ( & V_2 -> V_21 -> V_113 ) )
return;
if ( ! F_81 ( V_101 , & V_2 -> V_21 -> V_4 ) ||
F_81 ( V_102 , & V_2 -> V_21 -> V_4 ) )
return;
if ( F_134 ( V_2 , V_129 , V_130 ) )
F_85 ( V_102 , & V_2 -> V_21 -> V_4 ) ;
}
static int F_137 ( struct V_19 * V_20 , struct V_138 * V_139 )
{
struct V_1 * V_2 ;
int V_51 ;
F_69 ( & V_20 -> V_116 ) ;
if ( V_20 -> V_140 . V_138 ) {
V_51 = - V_141 ;
goto V_142;
}
if ( ! V_139 -> V_15 ) {
V_139 -> V_15 = F_138 ( NULL , V_143 - V_27 ,
V_27 , 0 , 0 ) ;
if ( V_139 -> V_15 & ~ V_42 ) {
V_51 = V_139 -> V_15 ;
goto V_142;
}
}
V_2 = F_139 ( V_20 , V_139 -> V_15 , V_27 ,
V_144 | V_6 | V_145 | V_146 ,
& V_139 -> V_147 ) ;
if ( F_75 ( V_2 ) ) {
V_51 = F_76 ( V_2 ) ;
goto V_142;
}
V_51 = 0 ;
F_84 () ;
V_20 -> V_140 . V_138 = V_139 ;
V_142:
F_70 ( & V_20 -> V_116 ) ;
return V_51 ;
}
static struct V_138 * F_140 ( unsigned long V_15 )
{
struct V_19 * V_20 = V_136 -> V_20 ;
T_5 V_37 = V_38 ;
struct V_138 * V_139 ;
V_139 = F_103 ( sizeof( * V_139 ) , V_30 ) ;
if ( F_44 ( ! V_139 ) )
goto V_95;
V_139 -> V_148 = F_64 ( F_141 ( V_149 ) * sizeof( long ) , V_30 ) ;
if ( ! V_139 -> V_148 )
goto V_150;
V_139 -> V_147 . V_151 = L_1 ;
V_139 -> V_147 . V_152 = V_139 -> V_152 ;
V_139 -> V_152 [ 0 ] = F_142 ( V_153 ) ;
if ( ! V_139 -> V_152 [ 0 ] )
goto V_154;
V_139 -> V_152 [ 1 ] = NULL ;
V_139 -> V_15 = V_15 ;
F_143 ( & V_139 -> V_155 ) ;
F_85 ( 0 , V_139 -> V_148 ) ;
F_61 ( & V_139 -> V_156 , 1 ) ;
F_35 ( V_139 -> V_152 [ 0 ] , 0 , & V_37 , V_47 ) ;
if ( ! F_137 ( V_20 , V_139 ) )
return V_139 ;
F_144 ( V_139 -> V_152 [ 0 ] ) ;
V_154:
F_51 ( V_139 -> V_148 ) ;
V_150:
F_51 ( V_139 ) ;
V_95:
return NULL ;
}
static struct V_138 * F_145 ( void )
{
struct V_19 * V_20 = V_136 -> V_20 ;
struct V_138 * V_139 ;
if ( ! V_20 -> V_140 . V_138 )
F_140 ( 0 ) ;
V_139 = V_20 -> V_140 . V_138 ;
F_146 () ;
return V_139 ;
}
void F_147 ( struct V_19 * V_20 )
{
struct V_138 * V_139 = V_20 -> V_140 . V_138 ;
if ( ! V_139 )
return;
F_26 ( V_139 -> V_152 [ 0 ] ) ;
F_51 ( V_139 -> V_148 ) ;
F_51 ( V_139 ) ;
}
void F_148 ( void )
{
F_149 ( & V_115 ) ;
}
void F_150 ( void )
{
F_151 ( & V_115 ) ;
}
void F_152 ( struct V_19 * V_157 , struct V_19 * V_158 )
{
V_158 -> V_140 . V_138 = NULL ;
if ( F_81 ( V_101 , & V_157 -> V_4 ) ) {
F_85 ( V_101 , & V_158 -> V_4 ) ;
F_85 ( V_102 , & V_158 -> V_4 ) ;
}
}
static unsigned long F_153 ( struct V_138 * V_139 )
{
unsigned long V_159 ;
int V_160 ;
do {
V_160 = F_154 ( V_139 -> V_148 , V_149 ) ;
if ( V_160 < V_149 ) {
if ( ! F_155 ( V_160 , V_139 -> V_148 ) )
break;
V_160 = V_149 ;
continue;
}
F_156 ( V_139 -> V_155 , ( F_136 ( & V_139 -> V_156 ) < V_149 ) ) ;
} while ( V_160 >= V_149 );
V_159 = V_139 -> V_15 + ( V_160 * V_161 ) ;
F_48 ( & V_139 -> V_156 ) ;
return V_159 ;
}
static unsigned long F_157 ( struct V_58 * V_58 )
{
struct V_138 * V_139 ;
unsigned long V_162 ;
V_139 = F_145 () ;
if ( ! V_139 )
return 0 ;
V_162 = F_153 ( V_139 ) ;
if ( F_44 ( ! V_162 ) )
return 0 ;
F_158 ( V_139 -> V_152 [ 0 ] , V_162 ,
& V_58 -> V_91 . V_163 , sizeof( V_58 -> V_91 . V_163 ) ) ;
return V_162 ;
}
static void F_159 ( struct V_164 * V_165 )
{
struct V_138 * V_139 ;
unsigned long V_166 ;
unsigned long V_159 ;
if ( ! V_165 -> V_20 || ! V_165 -> V_20 -> V_140 . V_138 || ! V_165 -> V_167 )
return;
V_159 = V_165 -> V_167 -> V_162 ;
if ( F_44 ( ! V_159 ) )
return;
V_139 = V_165 -> V_20 -> V_140 . V_138 ;
V_166 = V_139 -> V_15 + V_27 ;
if ( V_139 -> V_15 <= V_159 && V_159 < V_166 ) {
unsigned long V_11 ;
int V_160 ;
V_11 = V_159 - V_139 -> V_15 ;
V_160 = V_11 / V_161 ;
if ( V_160 >= V_149 )
return;
F_91 ( V_160 , V_139 -> V_148 ) ;
F_160 ( & V_139 -> V_156 ) ;
F_161 () ;
if ( F_162 ( & V_139 -> V_155 ) )
F_163 ( & V_139 -> V_155 ) ;
V_165 -> V_167 -> V_162 = 0 ;
}
}
void __weak F_158 ( struct V_17 * V_17 , unsigned long V_15 ,
void * V_43 , unsigned long V_40 )
{
F_35 ( V_17 , V_15 , V_43 , V_40 ) ;
F_164 ( V_17 ) ;
}
unsigned long __weak F_165 ( struct V_168 * V_169 )
{
return F_166 ( V_169 ) - V_47 ;
}
unsigned long F_167 ( struct V_168 * V_169 )
{
struct V_170 * V_167 = V_136 -> V_167 ;
if ( F_44 ( V_167 && V_167 -> V_171 ) )
return V_167 -> V_15 ;
return F_166 ( V_169 ) ;
}
static struct V_172 * F_168 ( struct V_172 * V_173 )
{
struct V_172 * V_78 = V_173 -> V_78 ;
F_49 ( V_173 -> V_58 ) ;
F_51 ( V_173 ) ;
return V_78 ;
}
void F_169 ( struct V_164 * V_133 )
{
struct V_170 * V_167 = V_133 -> V_167 ;
struct V_172 * V_173 ;
if ( ! V_167 )
return;
if ( V_167 -> V_171 )
F_49 ( V_167 -> V_171 ) ;
V_173 = V_167 -> V_174 ;
while ( V_173 )
V_173 = F_168 ( V_173 ) ;
F_159 ( V_133 ) ;
F_51 ( V_167 ) ;
V_133 -> V_167 = NULL ;
}
static struct V_170 * F_170 ( void )
{
if ( ! V_136 -> V_167 )
V_136 -> V_167 = F_64 ( sizeof( struct V_170 ) , V_30 ) ;
return V_136 -> V_167 ;
}
static int F_171 ( struct V_164 * V_133 , struct V_170 * V_175 )
{
struct V_170 * V_176 ;
struct V_172 * * V_71 , * V_177 , * V_65 ;
V_176 = F_64 ( sizeof( struct V_170 ) , V_30 ) ;
if ( ! V_176 )
return - V_54 ;
V_133 -> V_167 = V_176 ;
V_71 = & V_176 -> V_174 ;
for ( V_177 = V_175 -> V_174 ; V_177 ; V_177 = V_177 -> V_78 ) {
V_65 = F_103 ( sizeof( struct V_172 ) , V_30 ) ;
if ( ! V_65 )
return - V_54 ;
* V_65 = * V_177 ;
F_47 ( V_65 -> V_58 ) ;
V_65 -> V_78 = NULL ;
* V_71 = V_65 ;
V_71 = & V_65 -> V_78 ;
V_176 -> V_178 ++ ;
}
return 0 ;
}
static void F_172 ( struct V_164 * V_133 , const char * V_179 )
{
F_173 ( L_2 ,
V_136 -> V_180 , V_136 -> V_181 , V_179 ) ;
}
static void F_174 ( struct V_182 * V_183 )
{
if ( V_136 -> V_4 & V_184 )
return;
if ( ! F_140 ( V_136 -> V_167 -> V_185 ) )
F_172 ( V_136 , L_3 ) ;
}
void F_175 ( struct V_164 * V_133 , unsigned long V_4 )
{
struct V_170 * V_167 = V_136 -> V_167 ;
struct V_19 * V_20 = V_136 -> V_20 ;
struct V_138 * V_139 ;
V_133 -> V_167 = NULL ;
if ( ! V_167 || ! V_167 -> V_174 )
return;
if ( V_20 == V_133 -> V_20 && ! ( V_4 & V_186 ) )
return;
if ( F_171 ( V_133 , V_167 ) )
return F_172 ( V_133 , L_4 ) ;
V_139 = V_20 -> V_140 . V_138 ;
if ( ! V_139 )
return F_172 ( V_133 , L_3 ) ;
if ( V_20 == V_133 -> V_20 )
return;
V_133 -> V_167 -> V_185 = V_139 -> V_15 ;
F_176 ( & V_133 -> V_167 -> F_174 , F_174 ) ;
F_177 ( V_133 , & V_133 -> V_167 -> F_174 , true ) ;
}
static unsigned long F_178 ( void )
{
struct V_138 * V_139 ;
unsigned long V_187 = - 1 ;
V_139 = V_136 -> V_20 -> V_140 . V_138 ;
F_146 () ;
if ( V_139 )
V_187 = V_139 -> V_15 ;
return V_187 ;
}
static void F_179 ( struct V_170 * V_167 , bool V_188 ,
struct V_168 * V_169 )
{
struct V_172 * V_173 = V_167 -> V_174 ;
enum V_189 V_98 = V_188 ? V_190 : V_191 ;
while ( V_173 && ! F_180 ( V_173 , V_98 , V_169 ) ) {
V_173 = F_168 ( V_173 ) ;
V_167 -> V_178 -- ;
}
V_167 -> V_174 = V_173 ;
}
static void F_181 ( struct V_58 * V_58 , struct V_168 * V_169 )
{
struct V_172 * V_173 ;
struct V_170 * V_167 ;
unsigned long V_192 , V_187 ;
bool V_188 ;
if ( ! F_145 () )
return;
V_167 = F_170 () ;
if ( ! V_167 )
return;
if ( V_167 -> V_178 >= V_193 ) {
F_182 ( V_194 L_5
L_6 ,
V_136 -> V_181 , V_136 -> V_195 ) ;
return;
}
V_173 = F_103 ( sizeof( struct V_172 ) , V_30 ) ;
if ( ! V_173 )
return;
V_187 = F_178 () ;
V_192 = F_183 ( V_187 , V_169 ) ;
if ( V_192 == - 1 )
goto V_142;
V_188 = ( V_192 == V_187 ) ;
F_179 ( V_167 , V_188 , V_169 ) ;
if ( V_188 ) {
if ( ! V_167 -> V_174 ) {
F_172 ( V_136 , L_7 ) ;
goto V_142;
}
V_192 = V_167 -> V_174 -> V_192 ;
}
V_173 -> V_58 = F_47 ( V_58 ) ;
V_173 -> V_196 = F_166 ( V_169 ) ;
V_173 -> V_197 = F_184 ( V_169 ) ;
V_173 -> V_192 = V_192 ;
V_173 -> V_188 = V_188 ;
V_167 -> V_178 ++ ;
V_173 -> V_78 = V_167 -> V_174 ;
V_167 -> V_174 = V_173 ;
return;
V_142:
F_51 ( V_173 ) ;
}
static int
F_185 ( struct V_58 * V_58 , struct V_168 * V_169 , unsigned long V_198 )
{
struct V_170 * V_167 ;
unsigned long V_162 ;
int V_24 ;
V_167 = F_170 () ;
if ( ! V_167 )
return - V_54 ;
V_162 = F_157 ( V_58 ) ;
if ( ! V_162 )
return - V_54 ;
V_167 -> V_162 = V_162 ;
V_167 -> V_15 = V_198 ;
V_24 = F_186 ( & V_58 -> V_91 , V_169 ) ;
if ( F_44 ( V_24 ) ) {
F_159 ( V_136 ) ;
return V_24 ;
}
V_167 -> V_171 = V_58 ;
V_167 -> V_199 = V_200 ;
return 0 ;
}
bool F_187 ( void )
{
struct V_164 * V_133 = V_136 ;
struct V_170 * V_167 = V_133 -> V_167 ;
if ( F_117 ( ! V_167 || ! V_167 -> V_171 ) )
return false ;
F_188 ( V_167 -> V_199 != V_200 ) ;
if ( F_189 ( V_133 ) ) {
F_190 ( & V_133 -> V_201 -> V_202 ) ;
F_191 ( V_133 , V_203 ) ;
F_192 ( & V_133 -> V_201 -> V_202 ) ;
if ( F_193 ( V_133 ) || F_194 ( V_133 ) ) {
V_167 -> V_199 = V_204 ;
F_195 ( V_133 , V_205 ) ;
}
}
return true ;
}
static void F_196 ( struct V_19 * V_20 )
{
struct V_1 * V_2 ;
for ( V_2 = V_20 -> V_124 ; V_2 ; V_2 = V_2 -> V_125 ) {
if ( ! F_1 ( V_2 , false ) )
continue;
if ( F_134 ( V_2 , V_2 -> V_12 , V_2 -> V_126 ) )
return;
}
F_91 ( V_101 , & V_20 -> V_4 ) ;
}
static int F_197 ( struct V_19 * V_20 , unsigned long V_15 )
{
struct V_17 * V_17 ;
T_5 V_48 ;
int V_206 ;
F_198 () ;
V_206 = F_199 ( & V_48 , ( void V_207 * ) V_15 ,
sizeof( V_48 ) ) ;
F_200 () ;
if ( F_117 ( V_206 == 0 ) )
goto V_95;
V_206 = F_38 ( NULL , V_20 , V_15 , 1 , 0 , 1 , & V_17 , NULL ) ;
if ( V_206 < 0 )
return V_206 ;
F_32 ( V_17 , V_15 , & V_48 , V_47 ) ;
F_26 ( V_17 ) ;
V_95:
return F_31 ( & V_48 ) ;
}
static struct V_58 * F_201 ( unsigned long V_198 , int * V_46 )
{
struct V_19 * V_20 = V_136 -> V_20 ;
struct V_58 * V_58 = NULL ;
struct V_1 * V_2 ;
F_88 ( & V_20 -> V_116 ) ;
V_2 = F_110 ( V_20 , V_198 ) ;
if ( V_2 && V_2 -> V_12 <= V_198 ) {
if ( F_1 ( V_2 , false ) ) {
struct V_62 * V_62 = F_111 ( V_2 -> V_9 ) ;
T_2 V_11 = F_3 ( V_2 , V_198 ) ;
V_58 = F_55 ( V_62 , V_11 ) ;
}
if ( ! V_58 )
* V_46 = F_197 ( V_20 , V_198 ) ;
} else {
* V_46 = - V_208 ;
}
if ( ! V_58 && F_202 ( V_102 , & V_20 -> V_4 ) )
F_196 ( V_20 ) ;
F_89 ( & V_20 -> V_116 ) ;
return V_58 ;
}
static void F_203 ( struct V_58 * V_58 , struct V_168 * V_169 )
{
struct V_76 * V_77 ;
int remove = V_209 ;
bool V_210 = false ;
F_88 ( & V_58 -> V_74 ) ;
for ( V_77 = V_58 -> V_79 ; V_77 ; V_77 = V_77 -> V_78 ) {
int V_211 = 0 ;
if ( V_77 -> V_119 ) {
V_211 = V_77 -> V_119 ( V_77 , V_169 ) ;
F_204 ( V_211 & ~ V_212 ,
L_8 , V_211 , V_77 -> V_119 ) ;
}
if ( V_77 -> V_120 )
V_210 = true ;
remove &= V_211 ;
}
if ( V_210 && ! remove )
F_181 ( V_58 , V_169 ) ;
if ( remove && V_58 -> V_79 ) {
F_96 ( ! F_93 ( V_58 ) ) ;
F_120 ( V_58 , V_136 -> V_20 ) ;
}
F_89 ( & V_58 -> V_74 ) ;
}
static void
F_205 ( struct V_172 * V_173 , struct V_168 * V_169 )
{
struct V_58 * V_58 = V_173 -> V_58 ;
struct V_76 * V_77 ;
F_88 ( & V_58 -> V_74 ) ;
for ( V_77 = V_58 -> V_79 ; V_77 ; V_77 = V_77 -> V_78 ) {
if ( V_77 -> V_120 )
V_77 -> V_120 ( V_77 , V_173 -> V_196 , V_169 ) ;
}
F_89 ( & V_58 -> V_74 ) ;
}
static struct V_172 * F_206 ( struct V_172 * V_173 )
{
bool V_188 ;
do {
V_188 = V_173 -> V_188 ;
V_173 = V_173 -> V_78 ;
} while ( V_188 );
return V_173 ;
}
static void F_207 ( struct V_168 * V_169 )
{
struct V_170 * V_167 ;
struct V_172 * V_173 , * V_78 ;
bool V_213 ;
V_167 = V_136 -> V_167 ;
if ( ! V_167 )
goto V_214;
V_173 = V_167 -> V_174 ;
if ( ! V_173 )
goto V_214;
do {
V_78 = F_206 ( V_173 ) ;
V_213 = ! V_78 || F_180 ( V_78 , V_215 , V_169 ) ;
F_208 ( V_169 , V_173 -> V_192 ) ;
do {
if ( V_213 )
F_205 ( V_173 , V_169 ) ;
V_173 = F_168 ( V_173 ) ;
V_167 -> V_178 -- ;
} while ( V_173 != V_78 );
} while ( ! V_213 );
V_167 -> V_174 = V_173 ;
return;
V_214:
F_172 ( V_136 , L_9 ) ;
F_209 ( V_216 , V_217 , V_136 ) ;
}
bool __weak F_210 ( struct V_56 * V_218 , struct V_168 * V_169 )
{
return false ;
}
bool __weak F_180 ( struct V_172 * V_51 , enum V_189 V_98 ,
struct V_168 * V_169 )
{
return true ;
}
static void F_211 ( struct V_168 * V_169 )
{
struct V_58 * V_58 ;
unsigned long V_198 ;
int V_219 ( V_46 ) ;
V_198 = F_165 ( V_169 ) ;
if ( V_198 == F_178 () )
return F_207 ( V_169 ) ;
V_58 = F_201 ( V_198 , & V_46 ) ;
if ( ! V_58 ) {
if ( V_46 > 0 ) {
F_212 ( V_220 , V_136 , 0 ) ;
} else {
F_208 ( V_169 , V_198 ) ;
}
return;
}
F_208 ( V_169 , V_198 ) ;
F_213 () ;
if ( F_44 ( ! F_81 ( V_94 , & V_58 -> V_4 ) ) )
goto V_95;
if ( ! F_170 () )
goto V_95;
if ( F_210 ( & V_58 -> V_91 , V_169 ) )
goto V_95;
F_203 ( V_58 , V_169 ) ;
if ( F_214 ( & V_58 -> V_91 , V_169 ) )
goto V_95;
if ( ! F_185 ( V_58 , V_169 , V_198 ) )
return;
V_95:
F_49 ( V_58 ) ;
}
static void F_215 ( struct V_170 * V_167 , struct V_168 * V_169 )
{
struct V_58 * V_58 ;
int V_24 = 0 ;
V_58 = V_167 -> V_171 ;
if ( V_167 -> V_199 == V_221 )
V_24 = F_216 ( & V_58 -> V_91 , V_169 ) ;
else if ( V_167 -> V_199 == V_204 )
F_217 ( & V_58 -> V_91 , V_169 ) ;
else
F_188 ( 1 ) ;
F_49 ( V_58 ) ;
V_167 -> V_171 = NULL ;
V_167 -> V_199 = V_222 ;
F_159 ( V_136 ) ;
F_190 ( & V_136 -> V_201 -> V_202 ) ;
F_218 () ;
F_192 ( & V_136 -> V_201 -> V_202 ) ;
if ( F_44 ( V_24 ) ) {
F_172 ( V_136 , L_10 ) ;
F_209 ( V_216 , V_217 , V_136 ) ;
}
}
void F_219 ( struct V_168 * V_169 )
{
struct V_170 * V_167 ;
F_220 ( V_205 ) ;
V_167 = V_136 -> V_167 ;
if ( V_167 && V_167 -> V_171 )
F_215 ( V_167 , V_169 ) ;
else
F_211 ( V_169 ) ;
}
int F_221 ( struct V_168 * V_169 )
{
if ( ! V_136 -> V_20 )
return 0 ;
if ( ! F_81 ( V_101 , & V_136 -> V_20 -> V_4 ) &&
( ! V_136 -> V_167 || ! V_136 -> V_167 -> V_174 ) )
return 0 ;
F_222 ( V_205 ) ;
return 1 ;
}
int F_223 ( struct V_168 * V_169 )
{
struct V_170 * V_167 = V_136 -> V_167 ;
if ( ! V_136 -> V_20 || ! V_167 || ! V_167 -> V_171 )
return 0 ;
V_167 -> V_199 = V_221 ;
F_222 ( V_205 ) ;
return 1 ;
}
static int T_6 F_224 ( void )
{
int V_223 ;
for ( V_223 = 0 ; V_223 < V_224 ; V_223 ++ )
F_225 ( & V_225 [ V_223 ] ) ;
if ( F_226 ( & V_115 ) )
return - V_54 ;
return F_227 ( & V_226 ) ;
}
