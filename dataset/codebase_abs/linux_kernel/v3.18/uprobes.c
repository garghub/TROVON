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
F_100 ( & V_82 -> V_110 ) ;
F_101 (vma, &mapping->i_mmap, pgoff, pgoff) {
if ( ! F_1 ( V_2 , V_3 ) )
continue;
if ( ! V_107 && ! V_108 ) {
V_107 = F_102 ( sizeof( struct V_103 ) ,
V_111 | V_112 | V_113 ) ;
if ( V_107 )
V_107 -> V_78 = NULL ;
}
if ( ! V_107 ) {
V_108 ++ ;
continue;
}
if ( ! F_103 ( & V_2 -> V_21 -> V_114 ) )
continue;
V_104 = V_107 ;
V_107 = V_107 -> V_78 ;
V_104 -> V_78 = V_106 ;
V_106 = V_104 ;
V_104 -> V_20 = V_2 -> V_21 ;
V_104 -> V_15 = F_2 ( V_2 , V_11 ) ;
}
F_104 ( & V_82 -> V_110 ) ;
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
F_107 ( struct V_58 * V_58 , struct V_76 * V_115 )
{
bool V_3 = ! ! V_115 ;
struct V_103 * V_104 ;
int V_24 = 0 ;
F_108 ( & V_116 ) ;
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
F_68 ( & V_20 -> V_117 ) ;
V_2 = F_109 ( V_20 , V_104 -> V_15 ) ;
if ( ! V_2 || ! F_1 ( V_2 , V_3 ) ||
F_110 ( V_2 -> V_9 ) != V_58 -> V_61 )
goto V_32;
if ( V_2 -> V_12 > V_104 -> V_15 ||
F_3 ( V_2 , V_104 -> V_15 ) != V_58 -> V_11 )
goto V_32;
if ( V_3 ) {
if ( F_85 ( V_115 ,
V_118 , V_20 ) )
V_24 = F_89 ( V_58 , V_20 , V_2 , V_104 -> V_15 ) ;
} else if ( F_80 ( V_101 , & V_20 -> V_4 ) ) {
if ( ! F_86 ( V_58 ,
V_119 , V_20 ) )
V_24 |= F_91 ( V_58 , V_20 , V_104 -> V_15 ) ;
}
V_32:
F_69 ( & V_20 -> V_117 ) ;
free:
F_105 ( V_20 ) ;
V_104 = F_98 ( V_104 ) ;
}
V_95:
F_111 ( & V_116 ) ;
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
if ( ! V_77 -> V_120 && ! V_77 -> V_121 )
return - V_122 ;
if ( ! V_61 -> V_89 -> V_86 -> V_87 && ! F_115 ( V_61 -> V_89 ) )
return - V_93 ;
if ( V_11 > F_77 ( V_61 ) )
return - V_122 ;
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
struct V_76 * V_77 , bool V_123 )
{
struct V_58 * V_58 ;
struct V_76 * V_80 ;
int V_51 = - V_124 ;
V_58 = F_51 ( V_61 , V_11 ) ;
if ( F_95 ( ! V_58 ) )
return V_51 ;
F_68 ( & V_58 -> V_74 ) ;
for ( V_80 = V_58 -> V_79 ; V_80 && V_80 != V_77 ; V_80 = V_80 -> V_78 )
;
if ( V_80 )
V_51 = F_107 ( V_58 , V_123 ? V_77 : NULL ) ;
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
F_87 ( & V_20 -> V_117 ) ;
for ( V_2 = V_20 -> V_125 ; V_2 ; V_2 = V_2 -> V_126 ) {
unsigned long V_15 ;
T_2 V_11 ;
if ( ! F_1 ( V_2 , false ) ||
F_110 ( V_2 -> V_9 ) != V_58 -> V_61 )
continue;
V_11 = ( T_2 ) V_2 -> V_13 << V_14 ;
if ( V_58 -> V_11 < V_11 ||
V_58 -> V_11 >= V_11 + V_2 -> V_127 - V_2 -> V_12 )
continue;
V_15 = F_2 ( V_2 , V_58 -> V_11 ) ;
V_24 |= F_91 ( V_58 , V_20 , V_15 ) ;
}
F_88 ( & V_20 -> V_117 ) ;
return V_24 ;
}
static struct V_63 *
F_120 ( struct V_61 * V_61 , T_2 V_128 , T_2 V_129 )
{
struct V_63 * V_64 = V_65 . V_63 ;
while ( V_64 ) {
struct V_58 * V_62 = F_49 ( V_64 , struct V_58 , V_63 ) ;
if ( V_61 < V_62 -> V_61 ) {
V_64 = V_64 -> V_68 ;
} else if ( V_61 > V_62 -> V_61 ) {
V_64 = V_64 -> V_69 ;
} else {
if ( V_129 < V_62 -> V_11 )
V_64 = V_64 -> V_68 ;
else if ( V_128 > V_62 -> V_11 )
V_64 = V_64 -> V_69 ;
else
break;
}
}
return V_64 ;
}
static void F_121 ( struct V_61 * V_61 ,
struct V_1 * V_2 ,
unsigned long V_130 , unsigned long V_131 ,
struct V_132 * V_133 )
{
T_2 V_128 , V_129 ;
struct V_63 * V_64 , * V_134 ;
struct V_58 * V_62 ;
F_122 ( V_133 ) ;
V_128 = F_3 ( V_2 , V_130 ) ;
V_129 = V_128 + ( V_131 - V_130 ) - 1 ;
F_52 ( & V_70 ) ;
V_64 = F_120 ( V_61 , V_128 , V_129 ) ;
if ( V_64 ) {
for ( V_134 = V_64 ; V_134 ; V_134 = F_123 ( V_134 ) ) {
V_62 = F_49 ( V_134 , struct V_58 , V_63 ) ;
if ( V_62 -> V_61 != V_61 || V_62 -> V_11 < V_128 )
break;
F_124 ( & V_62 -> V_135 , V_133 ) ;
F_50 ( & V_62 -> V_67 ) ;
}
for ( V_134 = V_64 ; ( V_134 = F_125 ( V_134 ) ) ; ) {
V_62 = F_49 ( V_134 , struct V_58 , V_63 ) ;
if ( V_62 -> V_61 != V_61 || V_62 -> V_11 > V_129 )
break;
F_124 ( & V_62 -> V_135 , V_133 ) ;
F_50 ( & V_62 -> V_67 ) ;
}
}
F_53 ( & V_70 ) ;
}
int F_126 ( struct V_1 * V_2 )
{
struct V_132 V_136 ;
struct V_58 * V_58 , * V_62 ;
struct V_61 * V_61 ;
if ( F_127 () || ! F_1 ( V_2 , true ) )
return 0 ;
V_61 = F_110 ( V_2 -> V_9 ) ;
if ( ! V_61 )
return 0 ;
F_100 ( F_128 ( V_61 ) ) ;
F_121 ( V_61 , V_2 , V_2 -> V_12 , V_2 -> V_127 , & V_136 ) ;
F_129 (uprobe, u, &tmp_list, pending_list) {
if ( ! F_130 ( V_137 ) &&
F_86 ( V_58 , V_138 , V_2 -> V_21 ) ) {
unsigned long V_15 = F_2 ( V_2 , V_58 -> V_11 ) ;
F_89 ( V_58 , V_2 -> V_21 , V_2 , V_15 ) ;
}
F_59 ( V_58 ) ;
}
F_104 ( F_128 ( V_61 ) ) ;
return 0 ;
}
static bool
F_131 ( struct V_1 * V_2 , unsigned long V_130 , unsigned long V_131 )
{
T_2 V_128 , V_129 ;
struct V_61 * V_61 ;
struct V_63 * V_64 ;
V_61 = F_110 ( V_2 -> V_9 ) ;
V_128 = F_3 ( V_2 , V_130 ) ;
V_129 = V_128 + ( V_131 - V_130 ) - 1 ;
F_52 ( & V_70 ) ;
V_64 = F_120 ( V_61 , V_128 , V_129 ) ;
F_53 ( & V_70 ) ;
return ! ! V_64 ;
}
void F_132 ( struct V_1 * V_2 , unsigned long V_130 , unsigned long V_131 )
{
if ( F_127 () || ! F_1 ( V_2 , false ) )
return;
if ( ! F_133 ( & V_2 -> V_21 -> V_114 ) )
return;
if ( ! F_80 ( V_101 , & V_2 -> V_21 -> V_4 ) ||
F_80 ( V_102 , & V_2 -> V_21 -> V_4 ) )
return;
if ( F_131 ( V_2 , V_130 , V_131 ) )
F_84 ( V_102 , & V_2 -> V_21 -> V_4 ) ;
}
static int F_134 ( struct V_19 * V_20 , struct V_139 * V_140 )
{
int V_51 = - V_141 ;
F_68 ( & V_20 -> V_117 ) ;
if ( V_20 -> V_142 . V_139 )
goto V_143;
if ( ! V_140 -> V_15 ) {
V_140 -> V_15 = F_135 ( NULL , V_144 - V_27 ,
V_27 , 0 , 0 ) ;
if ( V_140 -> V_15 & ~ V_42 ) {
V_51 = V_140 -> V_15 ;
goto V_143;
}
}
V_51 = F_136 ( V_20 , V_140 -> V_15 , V_27 ,
V_145 | V_6 | V_146 | V_147 , & V_140 -> V_17 ) ;
if ( V_51 )
goto V_143;
F_83 () ;
V_20 -> V_142 . V_139 = V_140 ;
V_143:
F_69 ( & V_20 -> V_117 ) ;
return V_51 ;
}
static struct V_139 * F_137 ( unsigned long V_15 )
{
struct V_19 * V_20 = V_137 -> V_20 ;
T_5 V_37 = V_38 ;
struct V_139 * V_140 ;
V_140 = F_102 ( sizeof( * V_140 ) , V_30 ) ;
if ( F_44 ( ! V_140 ) )
goto V_95;
V_140 -> V_148 = F_63 ( F_138 ( V_149 ) * sizeof( long ) , V_30 ) ;
if ( ! V_140 -> V_148 )
goto V_150;
V_140 -> V_17 = F_139 ( V_151 ) ;
if ( ! V_140 -> V_17 )
goto V_152;
V_140 -> V_15 = V_15 ;
F_140 ( & V_140 -> V_153 ) ;
F_84 ( 0 , V_140 -> V_148 ) ;
F_57 ( & V_140 -> V_154 , 1 ) ;
F_35 ( V_140 -> V_17 , 0 , & V_37 , V_47 ) ;
if ( ! F_134 ( V_20 , V_140 ) )
return V_140 ;
F_141 ( V_140 -> V_17 ) ;
V_152:
F_61 ( V_140 -> V_148 ) ;
V_150:
F_61 ( V_140 ) ;
V_95:
return NULL ;
}
static struct V_139 * F_142 ( void )
{
struct V_19 * V_20 = V_137 -> V_20 ;
struct V_139 * V_140 ;
if ( ! V_20 -> V_142 . V_139 )
F_137 ( 0 ) ;
V_140 = V_20 -> V_142 . V_139 ;
F_143 () ;
return V_140 ;
}
void F_144 ( struct V_19 * V_20 )
{
struct V_139 * V_140 = V_20 -> V_142 . V_139 ;
if ( ! V_140 )
return;
F_26 ( V_140 -> V_17 ) ;
F_61 ( V_140 -> V_148 ) ;
F_61 ( V_140 ) ;
}
void F_145 ( void )
{
F_146 ( & V_116 ) ;
}
void F_147 ( void )
{
F_148 ( & V_116 ) ;
}
void F_149 ( struct V_19 * V_155 , struct V_19 * V_156 )
{
V_156 -> V_142 . V_139 = NULL ;
if ( F_80 ( V_101 , & V_155 -> V_4 ) ) {
F_84 ( V_101 , & V_156 -> V_4 ) ;
F_84 ( V_102 , & V_156 -> V_4 ) ;
}
}
static unsigned long F_150 ( struct V_139 * V_140 )
{
unsigned long V_157 ;
int V_158 ;
do {
V_158 = F_151 ( V_140 -> V_148 , V_149 ) ;
if ( V_158 < V_149 ) {
if ( ! F_152 ( V_158 , V_140 -> V_148 ) )
break;
V_158 = V_149 ;
continue;
}
F_153 ( V_140 -> V_153 , ( F_133 ( & V_140 -> V_154 ) < V_149 ) ) ;
} while ( V_158 >= V_149 );
V_157 = V_140 -> V_15 + ( V_158 * V_159 ) ;
F_50 ( & V_140 -> V_154 ) ;
return V_157 ;
}
static unsigned long F_154 ( struct V_58 * V_58 )
{
struct V_139 * V_140 ;
unsigned long V_160 ;
V_140 = F_142 () ;
if ( ! V_140 )
return 0 ;
V_160 = F_150 ( V_140 ) ;
if ( F_44 ( ! V_160 ) )
return 0 ;
F_155 ( V_140 -> V_17 , V_160 ,
& V_58 -> V_91 . V_161 , sizeof( V_58 -> V_91 . V_161 ) ) ;
return V_160 ;
}
static void F_156 ( struct V_162 * V_163 )
{
struct V_139 * V_140 ;
unsigned long V_164 ;
unsigned long V_157 ;
if ( ! V_163 -> V_20 || ! V_163 -> V_20 -> V_142 . V_139 || ! V_163 -> V_165 )
return;
V_157 = V_163 -> V_165 -> V_160 ;
if ( F_44 ( ! V_157 ) )
return;
V_140 = V_163 -> V_20 -> V_142 . V_139 ;
V_164 = V_140 -> V_15 + V_27 ;
if ( V_140 -> V_15 <= V_157 && V_157 < V_164 ) {
unsigned long V_11 ;
int V_158 ;
V_11 = V_157 - V_140 -> V_15 ;
V_158 = V_11 / V_159 ;
if ( V_158 >= V_149 )
return;
F_90 ( V_158 , V_140 -> V_148 ) ;
F_157 ( & V_140 -> V_154 ) ;
if ( F_158 ( & V_140 -> V_153 ) )
F_159 ( & V_140 -> V_153 ) ;
V_163 -> V_165 -> V_160 = 0 ;
}
}
void __weak F_155 ( struct V_17 * V_17 , unsigned long V_15 ,
void * V_43 , unsigned long V_40 )
{
F_35 ( V_17 , V_15 , V_43 , V_40 ) ;
F_160 ( V_17 ) ;
}
unsigned long __weak F_161 ( struct V_166 * V_167 )
{
return F_162 ( V_167 ) - V_47 ;
}
unsigned long F_163 ( struct V_166 * V_167 )
{
struct V_168 * V_165 = V_137 -> V_165 ;
if ( F_44 ( V_165 && V_165 -> V_169 ) )
return V_165 -> V_15 ;
return F_162 ( V_167 ) ;
}
void F_164 ( struct V_162 * V_134 )
{
struct V_168 * V_165 = V_134 -> V_165 ;
struct V_170 * V_171 , * V_172 ;
if ( ! V_165 )
return;
if ( V_165 -> V_169 )
F_59 ( V_165 -> V_169 ) ;
V_171 = V_165 -> V_173 ;
while ( V_171 ) {
V_172 = V_171 ;
V_171 = V_171 -> V_78 ;
F_59 ( V_172 -> V_58 ) ;
F_61 ( V_172 ) ;
}
F_156 ( V_134 ) ;
F_61 ( V_165 ) ;
V_134 -> V_165 = NULL ;
}
static struct V_168 * F_165 ( void )
{
if ( ! V_137 -> V_165 )
V_137 -> V_165 = F_63 ( sizeof( struct V_168 ) , V_30 ) ;
return V_137 -> V_165 ;
}
static int F_166 ( struct V_162 * V_134 , struct V_168 * V_174 )
{
struct V_168 * V_175 ;
struct V_170 * * V_71 , * V_176 , * V_64 ;
V_175 = F_63 ( sizeof( struct V_168 ) , V_30 ) ;
if ( ! V_175 )
return - V_54 ;
V_134 -> V_165 = V_175 ;
V_71 = & V_175 -> V_173 ;
for ( V_176 = V_174 -> V_173 ; V_176 ; V_176 = V_176 -> V_78 ) {
V_64 = F_102 ( sizeof( struct V_170 ) , V_30 ) ;
if ( ! V_64 )
return - V_54 ;
* V_64 = * V_176 ;
F_50 ( & V_64 -> V_58 -> V_67 ) ;
V_64 -> V_78 = NULL ;
* V_71 = V_64 ;
V_71 = & V_64 -> V_78 ;
V_175 -> V_177 ++ ;
}
return 0 ;
}
static void F_167 ( struct V_162 * V_134 , const char * V_178 )
{
F_168 ( L_1 ,
V_137 -> V_179 , V_137 -> V_180 , V_178 ) ;
}
static void F_169 ( struct V_181 * V_182 )
{
if ( V_137 -> V_4 & V_183 )
return;
if ( ! F_137 ( V_137 -> V_165 -> V_184 ) )
F_167 ( V_137 , L_2 ) ;
}
void F_170 ( struct V_162 * V_134 , unsigned long V_4 )
{
struct V_168 * V_165 = V_137 -> V_165 ;
struct V_19 * V_20 = V_137 -> V_20 ;
struct V_139 * V_140 ;
V_134 -> V_165 = NULL ;
if ( ! V_165 || ! V_165 -> V_173 )
return;
if ( V_20 == V_134 -> V_20 && ! ( V_4 & V_185 ) )
return;
if ( F_166 ( V_134 , V_165 ) )
return F_167 ( V_134 , L_3 ) ;
V_140 = V_20 -> V_142 . V_139 ;
if ( ! V_140 )
return F_167 ( V_134 , L_2 ) ;
if ( V_20 == V_134 -> V_20 )
return;
V_134 -> V_165 -> V_184 = V_140 -> V_15 ;
F_171 ( & V_134 -> V_165 -> F_169 , F_169 ) ;
F_172 ( V_134 , & V_134 -> V_165 -> F_169 , true ) ;
}
static unsigned long F_173 ( void )
{
struct V_139 * V_140 ;
unsigned long V_186 = - 1 ;
V_140 = V_137 -> V_20 -> V_142 . V_139 ;
F_143 () ;
if ( V_140 )
V_186 = V_140 -> V_15 ;
return V_186 ;
}
static void F_174 ( struct V_58 * V_58 , struct V_166 * V_167 )
{
struct V_170 * V_171 ;
struct V_168 * V_165 ;
unsigned long V_187 , V_186 ;
bool V_188 = false ;
if ( ! F_142 () )
return;
V_165 = F_165 () ;
if ( ! V_165 )
return;
if ( V_165 -> V_177 >= V_189 ) {
F_175 ( V_190 L_4
L_5 ,
V_137 -> V_180 , V_137 -> V_191 ) ;
return;
}
V_171 = F_63 ( sizeof( struct V_170 ) , V_30 ) ;
if ( ! V_171 )
goto V_143;
V_186 = F_173 () ;
V_187 = F_176 ( V_186 , V_167 ) ;
if ( V_187 == - 1 )
goto V_143;
if ( V_187 == V_186 ) {
if ( ! V_165 -> V_173 ) {
F_168 ( L_6 ,
V_137 -> V_180 , V_137 -> V_191 ) ;
goto V_143;
}
V_188 = true ;
V_187 = V_165 -> V_173 -> V_187 ;
}
F_50 ( & V_58 -> V_67 ) ;
V_171 -> V_58 = V_58 ;
V_171 -> V_192 = F_162 ( V_167 ) ;
V_171 -> V_187 = V_187 ;
V_171 -> V_188 = V_188 ;
V_165 -> V_177 ++ ;
V_171 -> V_78 = V_165 -> V_173 ;
V_165 -> V_173 = V_171 ;
return;
V_143:
F_61 ( V_171 ) ;
}
static int
F_177 ( struct V_58 * V_58 , struct V_166 * V_167 , unsigned long V_193 )
{
struct V_168 * V_165 ;
unsigned long V_160 ;
int V_24 ;
V_165 = F_165 () ;
if ( ! V_165 )
return - V_54 ;
V_160 = F_154 ( V_58 ) ;
if ( ! V_160 )
return - V_54 ;
V_165 -> V_160 = V_160 ;
V_165 -> V_15 = V_193 ;
V_24 = F_178 ( & V_58 -> V_91 , V_167 ) ;
if ( F_44 ( V_24 ) ) {
F_156 ( V_137 ) ;
return V_24 ;
}
V_165 -> V_169 = V_58 ;
V_165 -> V_194 = V_195 ;
return 0 ;
}
bool F_179 ( void )
{
struct V_162 * V_134 = V_137 ;
struct V_168 * V_165 = V_134 -> V_165 ;
if ( F_116 ( ! V_165 || ! V_165 -> V_169 ) )
return false ;
F_180 ( V_165 -> V_194 != V_195 ) ;
if ( F_181 ( V_134 ) ) {
F_182 ( & V_134 -> V_196 -> V_197 ) ;
F_183 ( V_134 , V_198 ) ;
F_184 ( & V_134 -> V_196 -> V_197 ) ;
if ( F_185 ( V_134 ) || F_186 ( V_134 ) ) {
V_165 -> V_194 = V_199 ;
F_187 ( V_134 , V_200 ) ;
}
}
return true ;
}
static void F_188 ( struct V_19 * V_20 )
{
struct V_1 * V_2 ;
for ( V_2 = V_20 -> V_125 ; V_2 ; V_2 = V_2 -> V_126 ) {
if ( ! F_1 ( V_2 , false ) )
continue;
if ( F_131 ( V_2 , V_2 -> V_12 , V_2 -> V_127 ) )
return;
}
F_90 ( V_101 , & V_20 -> V_4 ) ;
}
static int F_189 ( struct V_19 * V_20 , unsigned long V_15 )
{
struct V_17 * V_17 ;
T_5 V_48 ;
int V_201 ;
F_190 () ;
V_201 = F_191 ( & V_48 , ( void V_202 * ) V_15 ,
sizeof( V_48 ) ) ;
F_192 () ;
if ( F_116 ( V_201 == 0 ) )
goto V_95;
V_201 = F_38 ( NULL , V_20 , V_15 , 1 , 0 , 1 , & V_17 , NULL ) ;
if ( V_201 < 0 )
return V_201 ;
F_32 ( V_17 , V_15 , & V_48 , V_47 ) ;
F_26 ( V_17 ) ;
V_95:
return F_31 ( & V_48 ) ;
}
static struct V_58 * F_193 ( unsigned long V_193 , int * V_46 )
{
struct V_19 * V_20 = V_137 -> V_20 ;
struct V_58 * V_58 = NULL ;
struct V_1 * V_2 ;
F_87 ( & V_20 -> V_117 ) ;
V_2 = F_109 ( V_20 , V_193 ) ;
if ( V_2 && V_2 -> V_12 <= V_193 ) {
if ( F_1 ( V_2 , false ) ) {
struct V_61 * V_61 = F_110 ( V_2 -> V_9 ) ;
T_2 V_11 = F_3 ( V_2 , V_193 ) ;
V_58 = F_51 ( V_61 , V_11 ) ;
}
if ( ! V_58 )
* V_46 = F_189 ( V_20 , V_193 ) ;
} else {
* V_46 = - V_203 ;
}
if ( ! V_58 && F_194 ( V_102 , & V_20 -> V_4 ) )
F_188 ( V_20 ) ;
F_88 ( & V_20 -> V_117 ) ;
return V_58 ;
}
static void F_195 ( struct V_58 * V_58 , struct V_166 * V_167 )
{
struct V_76 * V_77 ;
int remove = V_204 ;
bool V_205 = false ;
F_87 ( & V_58 -> V_74 ) ;
for ( V_77 = V_58 -> V_79 ; V_77 ; V_77 = V_77 -> V_78 ) {
int V_206 = 0 ;
if ( V_77 -> V_120 ) {
V_206 = V_77 -> V_120 ( V_77 , V_167 ) ;
F_196 ( V_206 & ~ V_207 ,
L_7 , V_206 , V_77 -> V_120 ) ;
}
if ( V_77 -> V_121 )
V_205 = true ;
remove &= V_206 ;
}
if ( V_205 && ! remove )
F_174 ( V_58 , V_167 ) ;
if ( remove && V_58 -> V_79 ) {
F_95 ( ! F_92 ( V_58 ) ) ;
F_119 ( V_58 , V_137 -> V_20 ) ;
}
F_88 ( & V_58 -> V_74 ) ;
}
static void
F_197 ( struct V_170 * V_171 , struct V_166 * V_167 )
{
struct V_58 * V_58 = V_171 -> V_58 ;
struct V_76 * V_77 ;
F_87 ( & V_58 -> V_74 ) ;
for ( V_77 = V_58 -> V_79 ; V_77 ; V_77 = V_77 -> V_78 ) {
if ( V_77 -> V_121 )
V_77 -> V_121 ( V_77 , V_171 -> V_192 , V_167 ) ;
}
F_88 ( & V_58 -> V_74 ) ;
}
static bool F_198 ( struct V_166 * V_167 )
{
struct V_168 * V_165 ;
struct V_170 * V_171 , * V_172 ;
bool V_188 ;
V_165 = V_137 -> V_165 ;
if ( ! V_165 )
return false ;
V_171 = V_165 -> V_173 ;
if ( ! V_171 )
return false ;
F_199 ( V_167 , V_171 -> V_187 ) ;
for (; ; ) {
F_197 ( V_171 , V_167 ) ;
V_188 = V_171 -> V_188 ;
F_59 ( V_171 -> V_58 ) ;
V_172 = V_171 ;
V_171 = V_171 -> V_78 ;
F_61 ( V_172 ) ;
V_165 -> V_177 -- ;
if ( ! V_188 )
break;
F_82 ( ! V_171 ) ;
}
V_165 -> V_173 = V_171 ;
return true ;
}
bool __weak F_200 ( struct V_56 * V_208 , struct V_166 * V_167 )
{
return false ;
}
static void F_201 ( struct V_166 * V_167 )
{
struct V_58 * V_58 ;
unsigned long V_193 ;
int V_209 ( V_46 ) ;
V_193 = F_161 ( V_167 ) ;
if ( V_193 == F_173 () ) {
if ( F_198 ( V_167 ) )
return;
F_168 ( L_8 ,
V_137 -> V_180 , V_137 -> V_191 ) ;
}
V_58 = F_193 ( V_193 , & V_46 ) ;
if ( ! V_58 ) {
if ( V_46 > 0 ) {
F_202 ( V_210 , V_137 , 0 ) ;
} else {
F_199 ( V_167 , V_193 ) ;
}
return;
}
F_199 ( V_167 , V_193 ) ;
F_203 () ;
if ( F_44 ( ! F_80 ( V_94 , & V_58 -> V_4 ) ) )
goto V_95;
if ( ! F_165 () )
goto V_95;
if ( F_200 ( & V_58 -> V_91 , V_167 ) )
goto V_95;
F_195 ( V_58 , V_167 ) ;
if ( F_204 ( & V_58 -> V_91 , V_167 ) )
goto V_95;
if ( ! F_177 ( V_58 , V_167 , V_193 ) )
return;
V_95:
F_59 ( V_58 ) ;
}
static void F_205 ( struct V_168 * V_165 , struct V_166 * V_167 )
{
struct V_58 * V_58 ;
int V_24 = 0 ;
V_58 = V_165 -> V_169 ;
if ( V_165 -> V_194 == V_211 )
V_24 = F_206 ( & V_58 -> V_91 , V_167 ) ;
else if ( V_165 -> V_194 == V_199 )
F_207 ( & V_58 -> V_91 , V_167 ) ;
else
F_180 ( 1 ) ;
F_59 ( V_58 ) ;
V_165 -> V_169 = NULL ;
V_165 -> V_194 = V_212 ;
F_156 ( V_137 ) ;
F_182 ( & V_137 -> V_196 -> V_197 ) ;
F_208 () ;
F_184 ( & V_137 -> V_196 -> V_197 ) ;
if ( F_44 ( V_24 ) ) {
F_167 ( V_137 , L_9 ) ;
F_209 ( V_213 , V_214 , V_137 ) ;
}
}
void F_210 ( struct V_166 * V_167 )
{
struct V_168 * V_165 ;
F_211 ( V_200 ) ;
V_165 = V_137 -> V_165 ;
if ( V_165 && V_165 -> V_169 )
F_205 ( V_165 , V_167 ) ;
else
F_201 ( V_167 ) ;
}
int F_212 ( struct V_166 * V_167 )
{
if ( ! V_137 -> V_20 )
return 0 ;
if ( ! F_80 ( V_101 , & V_137 -> V_20 -> V_4 ) &&
( ! V_137 -> V_165 || ! V_137 -> V_165 -> V_173 ) )
return 0 ;
F_213 ( V_200 ) ;
return 1 ;
}
int F_214 ( struct V_166 * V_167 )
{
struct V_168 * V_165 = V_137 -> V_165 ;
if ( ! V_137 -> V_20 || ! V_165 || ! V_165 -> V_169 )
return 0 ;
V_165 -> V_194 = V_211 ;
F_213 ( V_200 ) ;
return 1 ;
}
static int T_6 F_215 ( void )
{
int V_215 ;
for ( V_215 = 0 ; V_215 < V_216 ; V_215 ++ )
F_216 ( & V_217 [ V_215 ] ) ;
if ( F_217 ( & V_116 ) )
return - V_54 ;
return F_218 ( & V_218 ) ;
}
