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
if ( ! V_23 ) {
F_9 ( V_18 , V_29 , false ) ;
goto V_32;
}
F_10 ( V_18 ) ;
F_11 ( V_18 , V_2 , V_16 , false ) ;
F_12 ( V_18 , V_29 , false , false ) ;
F_13 ( V_18 , V_2 ) ;
if ( ! F_14 ( V_17 ) ) {
F_15 ( V_20 , F_16 ( V_17 ) ) ;
F_17 ( V_20 , V_33 ) ;
}
F_18 ( V_2 , V_16 , F_19 ( * V_23 ) ) ;
F_20 ( V_2 , V_16 , V_23 ) ;
F_21 ( V_20 , V_16 , V_23 , F_22 ( V_18 , V_2 -> V_34 ) ) ;
F_23 ( V_17 , false ) ;
if ( ! F_24 ( V_17 ) )
F_25 ( V_17 ) ;
F_26 ( V_23 , V_22 ) ;
if ( V_2 -> V_10 & V_35 )
F_27 ( V_17 ) ;
F_28 ( V_17 ) ;
V_24 = 0 ;
V_32:
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
F_28 ( V_49 ) ;
V_52:
F_28 ( V_48 ) ;
if ( F_44 ( V_50 == - V_31 ) )
goto V_51;
return V_50 ;
}
int __weak F_45 ( struct V_55 * V_56 , struct V_19 * V_20 , unsigned long V_15 )
{
return F_38 ( V_20 , V_15 , V_37 ) ;
}
int __weak
F_46 ( struct V_55 * V_56 , struct V_19 * V_20 , unsigned long V_15 )
{
return F_38 ( V_20 , V_15 , * ( T_5 * ) & V_56 -> V_36 ) ;
}
static struct V_57 * F_47 ( struct V_57 * V_57 )
{
F_48 ( & V_57 -> V_58 ) ;
return V_57 ;
}
static void F_49 ( struct V_57 * V_57 )
{
if ( F_50 ( & V_57 -> V_58 ) )
F_51 ( V_57 ) ;
}
static int F_52 ( struct V_57 * V_59 , struct V_57 * V_60 )
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
static struct V_57 * F_53 ( struct V_61 * V_61 , T_2 V_11 )
{
struct V_57 V_62 = { . V_61 = V_61 , . V_11 = V_11 } ;
struct V_63 * V_64 = V_65 . V_63 ;
struct V_57 * V_57 ;
int V_66 ;
while ( V_64 ) {
V_57 = F_54 ( V_64 , struct V_57 , V_63 ) ;
V_66 = F_52 ( & V_62 , V_57 ) ;
if ( ! V_66 )
return F_47 ( V_57 ) ;
if ( V_66 < 0 )
V_64 = V_64 -> V_67 ;
else
V_64 = V_64 -> V_68 ;
}
return NULL ;
}
static struct V_57 * F_55 ( struct V_61 * V_61 , T_2 V_11 )
{
struct V_57 * V_57 ;
F_56 ( & V_69 ) ;
V_57 = F_53 ( V_61 , V_11 ) ;
F_57 ( & V_69 ) ;
return V_57 ;
}
static struct V_57 * F_58 ( struct V_57 * V_57 )
{
struct V_63 * * V_70 = & V_65 . V_63 ;
struct V_63 * V_71 = NULL ;
struct V_57 * V_62 ;
int V_66 ;
while ( * V_70 ) {
V_71 = * V_70 ;
V_62 = F_54 ( V_71 , struct V_57 , V_63 ) ;
V_66 = F_52 ( V_57 , V_62 ) ;
if ( ! V_66 )
return F_47 ( V_62 ) ;
if ( V_66 < 0 )
V_70 = & V_71 -> V_67 ;
else
V_70 = & V_71 -> V_68 ;
}
V_62 = NULL ;
F_59 ( & V_57 -> V_63 , V_71 , V_70 ) ;
F_60 ( & V_57 -> V_63 , & V_65 ) ;
F_61 ( & V_57 -> V_58 , 2 ) ;
return V_62 ;
}
static struct V_57 * F_62 ( struct V_57 * V_57 )
{
struct V_57 * V_62 ;
F_56 ( & V_69 ) ;
V_62 = F_58 ( V_57 ) ;
F_57 ( & V_69 ) ;
return V_62 ;
}
static struct V_57 * F_63 ( struct V_61 * V_61 , T_2 V_11 )
{
struct V_57 * V_57 , * V_72 ;
V_57 = F_64 ( sizeof( struct V_57 ) , V_30 ) ;
if ( ! V_57 )
return NULL ;
V_57 -> V_61 = F_65 ( V_61 ) ;
V_57 -> V_11 = V_11 ;
F_66 ( & V_57 -> V_73 ) ;
F_66 ( & V_57 -> V_74 ) ;
V_72 = F_62 ( V_57 ) ;
if ( V_72 ) {
F_51 ( V_57 ) ;
V_57 = V_72 ;
F_67 ( V_61 ) ;
}
return V_57 ;
}
static void F_68 ( struct V_57 * V_57 , struct V_75 * V_76 )
{
F_69 ( & V_57 -> V_74 ) ;
V_76 -> V_77 = V_57 -> V_78 ;
V_57 -> V_78 = V_76 ;
F_70 ( & V_57 -> V_74 ) ;
}
static bool F_71 ( struct V_57 * V_57 , struct V_75 * V_76 )
{
struct V_75 * * V_79 ;
bool V_50 = false ;
F_69 ( & V_57 -> V_74 ) ;
for ( V_79 = & V_57 -> V_78 ; * V_79 ; V_79 = & ( * V_79 ) -> V_77 ) {
if ( * V_79 == V_76 ) {
* V_79 = V_76 -> V_77 ;
V_50 = true ;
break;
}
}
F_70 ( & V_57 -> V_74 ) ;
return V_50 ;
}
static int F_72 ( struct V_80 * V_81 , struct V_82 * V_83 ,
void * V_36 , int V_84 , T_2 V_11 )
{
struct V_17 * V_17 ;
if ( V_81 -> V_85 -> V_86 )
V_17 = F_73 ( V_81 , V_11 >> V_14 , V_83 ) ;
else
V_17 = F_74 ( V_81 , V_11 >> V_14 ) ;
if ( F_75 ( V_17 ) )
return F_76 ( V_17 ) ;
F_33 ( V_17 , V_11 , V_36 , V_84 ) ;
F_28 ( V_17 ) ;
return 0 ;
}
static int F_77 ( struct V_57 * V_57 , struct V_82 * V_83 )
{
struct V_80 * V_81 = V_57 -> V_61 -> V_87 ;
T_2 V_88 = V_57 -> V_11 ;
void * V_36 = & V_57 -> V_89 . V_36 ;
int V_90 = sizeof( V_57 -> V_89 . V_36 ) ;
int V_39 , V_24 = - V_91 ;
do {
if ( V_88 >= F_78 ( V_57 -> V_61 ) )
break;
V_39 = F_79 ( int , V_90 , V_27 - ( V_88 & ~ V_41 ) ) ;
V_24 = F_72 ( V_81 , V_83 , V_36 , V_39 , V_88 ) ;
if ( V_24 )
break;
V_36 += V_39 ;
V_88 += V_39 ;
V_90 -= V_39 ;
} while ( V_90 );
return V_24 ;
}
static int F_80 ( struct V_57 * V_57 , struct V_82 * V_82 ,
struct V_19 * V_20 , unsigned long V_15 )
{
int V_50 = 0 ;
if ( F_81 ( V_92 , & V_57 -> V_4 ) )
return V_50 ;
F_69 ( & V_57 -> V_74 ) ;
if ( F_81 ( V_92 , & V_57 -> V_4 ) )
goto V_93;
V_50 = F_77 ( V_57 , V_82 ) ;
if ( V_50 )
goto V_93;
V_50 = - V_94 ;
if ( F_32 ( ( T_5 * ) & V_57 -> V_89 . V_36 ) )
goto V_93;
V_50 = F_82 ( & V_57 -> V_89 , V_20 , V_15 ) ;
if ( V_50 )
goto V_93;
F_83 ( ( V_57 -> V_11 & ~ V_41 ) +
V_46 > V_27 ) ;
F_84 () ;
F_85 ( V_92 , & V_57 -> V_4 ) ;
V_93:
F_70 ( & V_57 -> V_74 ) ;
return V_50 ;
}
static inline bool F_86 ( struct V_75 * V_76 ,
enum V_95 V_96 , struct V_19 * V_20 )
{
return ! V_76 -> V_97 || V_76 -> V_97 ( V_76 , V_96 , V_20 ) ;
}
static bool F_87 ( struct V_57 * V_57 ,
enum V_95 V_96 , struct V_19 * V_20 )
{
struct V_75 * V_76 ;
bool V_50 = false ;
F_88 ( & V_57 -> V_74 ) ;
for ( V_76 = V_57 -> V_78 ; V_76 ; V_76 = V_76 -> V_77 ) {
V_50 = F_86 ( V_76 , V_96 , V_20 ) ;
if ( V_50 )
break;
}
F_89 ( & V_57 -> V_74 ) ;
return V_50 ;
}
static int
F_90 ( struct V_57 * V_57 , struct V_19 * V_20 ,
struct V_1 * V_2 , unsigned long V_15 )
{
bool V_98 ;
int V_50 ;
V_50 = F_80 ( V_57 , V_2 -> V_9 , V_20 , V_15 ) ;
if ( V_50 )
return V_50 ;
V_98 = ! F_81 ( V_99 , & V_20 -> V_4 ) ;
if ( V_98 )
F_85 ( V_99 , & V_20 -> V_4 ) ;
V_50 = F_45 ( & V_57 -> V_89 , V_20 , V_15 ) ;
if ( ! V_50 )
F_91 ( V_100 , & V_20 -> V_4 ) ;
else if ( V_98 )
F_91 ( V_99 , & V_20 -> V_4 ) ;
return V_50 ;
}
static int
F_92 ( struct V_57 * V_57 , struct V_19 * V_20 , unsigned long V_15 )
{
F_85 ( V_100 , & V_20 -> V_4 ) ;
return F_46 ( & V_57 -> V_89 , V_20 , V_15 ) ;
}
static inline bool F_93 ( struct V_57 * V_57 )
{
return ! F_94 ( & V_57 -> V_63 ) ;
}
static void F_95 ( struct V_57 * V_57 )
{
if ( F_96 ( ! F_93 ( V_57 ) ) )
return;
F_56 ( & V_69 ) ;
F_97 ( & V_57 -> V_63 , & V_65 ) ;
F_57 ( & V_69 ) ;
F_98 ( & V_57 -> V_63 ) ;
F_67 ( V_57 -> V_61 ) ;
F_49 ( V_57 ) ;
}
static inline struct V_101 * F_99 ( struct V_101 * V_102 )
{
struct V_101 * V_77 = V_102 -> V_77 ;
F_51 ( V_102 ) ;
return V_77 ;
}
static struct V_101 *
F_100 ( struct V_80 * V_81 , T_2 V_11 , bool V_3 )
{
unsigned long V_103 = V_11 >> V_14 ;
struct V_1 * V_2 ;
struct V_101 * V_104 = NULL ;
struct V_101 * V_105 = NULL ;
struct V_101 * V_102 ;
int V_106 = 0 ;
V_107:
F_101 ( V_81 ) ;
F_102 (vma, &mapping->i_mmap, pgoff, pgoff) {
if ( ! F_1 ( V_2 , V_3 ) )
continue;
if ( ! V_105 && ! V_106 ) {
V_105 = F_103 ( sizeof( struct V_101 ) ,
V_108 | V_109 | V_110 ) ;
if ( V_105 )
V_105 -> V_77 = NULL ;
}
if ( ! V_105 ) {
V_106 ++ ;
continue;
}
if ( ! F_104 ( & V_2 -> V_21 -> V_111 ) )
continue;
V_102 = V_105 ;
V_105 = V_105 -> V_77 ;
V_102 -> V_77 = V_104 ;
V_104 = V_102 ;
V_102 -> V_20 = V_2 -> V_21 ;
V_102 -> V_15 = F_2 ( V_2 , V_11 ) ;
}
F_105 ( V_81 ) ;
if ( ! V_106 )
goto V_93;
V_105 = V_104 ;
while ( V_104 ) {
F_106 ( V_104 -> V_20 ) ;
V_104 = V_104 -> V_77 ;
}
do {
V_102 = F_103 ( sizeof( struct V_101 ) , V_30 ) ;
if ( ! V_102 ) {
V_104 = F_107 ( - V_53 ) ;
goto V_93;
}
V_102 -> V_77 = V_105 ;
V_105 = V_102 ;
} while ( -- V_106 );
goto V_107;
V_93:
while ( V_105 )
V_105 = F_99 ( V_105 ) ;
return V_104 ;
}
static int
F_108 ( struct V_57 * V_57 , struct V_75 * V_112 )
{
bool V_3 = ! ! V_112 ;
struct V_101 * V_102 ;
int V_24 = 0 ;
F_109 ( & V_113 ) ;
V_102 = F_100 ( V_57 -> V_61 -> V_87 ,
V_57 -> V_11 , V_3 ) ;
if ( F_75 ( V_102 ) ) {
V_24 = F_76 ( V_102 ) ;
goto V_93;
}
while ( V_102 ) {
struct V_19 * V_20 = V_102 -> V_20 ;
struct V_1 * V_2 ;
if ( V_24 && V_3 )
goto free;
F_69 ( & V_20 -> V_114 ) ;
V_2 = F_110 ( V_20 , V_102 -> V_15 ) ;
if ( ! V_2 || ! F_1 ( V_2 , V_3 ) ||
F_111 ( V_2 -> V_9 ) != V_57 -> V_61 )
goto V_32;
if ( V_2 -> V_12 > V_102 -> V_15 ||
F_3 ( V_2 , V_102 -> V_15 ) != V_57 -> V_11 )
goto V_32;
if ( V_3 ) {
if ( F_86 ( V_112 ,
V_115 , V_20 ) )
V_24 = F_90 ( V_57 , V_20 , V_2 , V_102 -> V_15 ) ;
} else if ( F_81 ( V_99 , & V_20 -> V_4 ) ) {
if ( ! F_87 ( V_57 ,
V_116 , V_20 ) )
V_24 |= F_92 ( V_57 , V_20 , V_102 -> V_15 ) ;
}
V_32:
F_70 ( & V_20 -> V_114 ) ;
free:
F_106 ( V_20 ) ;
V_102 = F_99 ( V_102 ) ;
}
V_93:
F_112 ( & V_113 ) ;
return V_24 ;
}
static int F_113 ( struct V_57 * V_57 , struct V_75 * V_76 )
{
F_68 ( V_57 , V_76 ) ;
return F_108 ( V_57 , V_76 ) ;
}
static void F_114 ( struct V_57 * V_57 , struct V_75 * V_76 )
{
int V_24 ;
if ( F_96 ( ! F_71 ( V_57 , V_76 ) ) )
return;
V_24 = F_108 ( V_57 , NULL ) ;
if ( ! V_57 -> V_78 && ! V_24 )
F_95 ( V_57 ) ;
}
int F_115 ( struct V_61 * V_61 , T_2 V_11 , struct V_75 * V_76 )
{
struct V_57 * V_57 ;
int V_50 ;
if ( ! V_76 -> V_117 && ! V_76 -> V_118 )
return - V_119 ;
if ( ! V_61 -> V_87 -> V_85 -> V_86 && ! F_116 ( V_61 -> V_87 ) )
return - V_91 ;
if ( V_11 > F_78 ( V_61 ) )
return - V_119 ;
V_51:
V_57 = F_63 ( V_61 , V_11 ) ;
if ( ! V_57 )
return - V_53 ;
F_69 ( & V_57 -> V_73 ) ;
V_50 = - V_31 ;
if ( F_117 ( F_93 ( V_57 ) ) ) {
V_50 = F_113 ( V_57 , V_76 ) ;
if ( V_50 )
F_114 ( V_57 , V_76 ) ;
}
F_70 ( & V_57 -> V_73 ) ;
F_49 ( V_57 ) ;
if ( F_44 ( V_50 == - V_31 ) )
goto V_51;
return V_50 ;
}
int F_118 ( struct V_61 * V_61 , T_2 V_11 ,
struct V_75 * V_76 , bool V_120 )
{
struct V_57 * V_57 ;
struct V_75 * V_79 ;
int V_50 = - V_121 ;
V_57 = F_55 ( V_61 , V_11 ) ;
if ( F_96 ( ! V_57 ) )
return V_50 ;
F_69 ( & V_57 -> V_73 ) ;
for ( V_79 = V_57 -> V_78 ; V_79 && V_79 != V_76 ; V_79 = V_79 -> V_77 )
;
if ( V_79 )
V_50 = F_108 ( V_57 , V_120 ? V_76 : NULL ) ;
F_70 ( & V_57 -> V_73 ) ;
F_49 ( V_57 ) ;
return V_50 ;
}
void F_119 ( struct V_61 * V_61 , T_2 V_11 , struct V_75 * V_76 )
{
struct V_57 * V_57 ;
V_57 = F_55 ( V_61 , V_11 ) ;
if ( F_96 ( ! V_57 ) )
return;
F_69 ( & V_57 -> V_73 ) ;
F_114 ( V_57 , V_76 ) ;
F_70 ( & V_57 -> V_73 ) ;
F_49 ( V_57 ) ;
}
static int F_120 ( struct V_57 * V_57 , struct V_19 * V_20 )
{
struct V_1 * V_2 ;
int V_24 = 0 ;
F_88 ( & V_20 -> V_114 ) ;
for ( V_2 = V_20 -> V_122 ; V_2 ; V_2 = V_2 -> V_123 ) {
unsigned long V_15 ;
T_2 V_11 ;
if ( ! F_1 ( V_2 , false ) ||
F_111 ( V_2 -> V_9 ) != V_57 -> V_61 )
continue;
V_11 = ( T_2 ) V_2 -> V_13 << V_14 ;
if ( V_57 -> V_11 < V_11 ||
V_57 -> V_11 >= V_11 + V_2 -> V_124 - V_2 -> V_12 )
continue;
V_15 = F_2 ( V_2 , V_57 -> V_11 ) ;
V_24 |= F_92 ( V_57 , V_20 , V_15 ) ;
}
F_89 ( & V_20 -> V_114 ) ;
return V_24 ;
}
static struct V_63 *
F_121 ( struct V_61 * V_61 , T_2 V_125 , T_2 V_126 )
{
struct V_63 * V_64 = V_65 . V_63 ;
while ( V_64 ) {
struct V_57 * V_62 = F_54 ( V_64 , struct V_57 , V_63 ) ;
if ( V_61 < V_62 -> V_61 ) {
V_64 = V_64 -> V_67 ;
} else if ( V_61 > V_62 -> V_61 ) {
V_64 = V_64 -> V_68 ;
} else {
if ( V_126 < V_62 -> V_11 )
V_64 = V_64 -> V_67 ;
else if ( V_125 > V_62 -> V_11 )
V_64 = V_64 -> V_68 ;
else
break;
}
}
return V_64 ;
}
static void F_122 ( struct V_61 * V_61 ,
struct V_1 * V_2 ,
unsigned long V_127 , unsigned long V_128 ,
struct V_129 * V_130 )
{
T_2 V_125 , V_126 ;
struct V_63 * V_64 , * V_131 ;
struct V_57 * V_62 ;
F_123 ( V_130 ) ;
V_125 = F_3 ( V_2 , V_127 ) ;
V_126 = V_125 + ( V_128 - V_127 ) - 1 ;
F_56 ( & V_69 ) ;
V_64 = F_121 ( V_61 , V_125 , V_126 ) ;
if ( V_64 ) {
for ( V_131 = V_64 ; V_131 ; V_131 = F_124 ( V_131 ) ) {
V_62 = F_54 ( V_131 , struct V_57 , V_63 ) ;
if ( V_62 -> V_61 != V_61 || V_62 -> V_11 < V_125 )
break;
F_125 ( & V_62 -> V_132 , V_130 ) ;
F_47 ( V_62 ) ;
}
for ( V_131 = V_64 ; ( V_131 = F_126 ( V_131 ) ) ; ) {
V_62 = F_54 ( V_131 , struct V_57 , V_63 ) ;
if ( V_62 -> V_61 != V_61 || V_62 -> V_11 > V_126 )
break;
F_125 ( & V_62 -> V_132 , V_130 ) ;
F_47 ( V_62 ) ;
}
}
F_57 ( & V_69 ) ;
}
int F_127 ( struct V_1 * V_2 )
{
struct V_129 V_133 ;
struct V_57 * V_57 , * V_62 ;
struct V_61 * V_61 ;
if ( F_128 () || ! F_1 ( V_2 , true ) )
return 0 ;
V_61 = F_111 ( V_2 -> V_9 ) ;
if ( ! V_61 )
return 0 ;
F_129 ( F_130 ( V_61 ) ) ;
F_122 ( V_61 , V_2 , V_2 -> V_12 , V_2 -> V_124 , & V_133 ) ;
F_131 (uprobe, u, &tmp_list, pending_list) {
if ( ! F_132 ( V_134 ) &&
F_87 ( V_57 , V_135 , V_2 -> V_21 ) ) {
unsigned long V_15 = F_2 ( V_2 , V_57 -> V_11 ) ;
F_90 ( V_57 , V_2 -> V_21 , V_2 , V_15 ) ;
}
F_49 ( V_57 ) ;
}
F_133 ( F_130 ( V_61 ) ) ;
return 0 ;
}
static bool
F_134 ( struct V_1 * V_2 , unsigned long V_127 , unsigned long V_128 )
{
T_2 V_125 , V_126 ;
struct V_61 * V_61 ;
struct V_63 * V_64 ;
V_61 = F_111 ( V_2 -> V_9 ) ;
V_125 = F_3 ( V_2 , V_127 ) ;
V_126 = V_125 + ( V_128 - V_127 ) - 1 ;
F_56 ( & V_69 ) ;
V_64 = F_121 ( V_61 , V_125 , V_126 ) ;
F_57 ( & V_69 ) ;
return ! ! V_64 ;
}
void F_135 ( struct V_1 * V_2 , unsigned long V_127 , unsigned long V_128 )
{
if ( F_128 () || ! F_1 ( V_2 , false ) )
return;
if ( ! F_136 ( & V_2 -> V_21 -> V_111 ) )
return;
if ( ! F_81 ( V_99 , & V_2 -> V_21 -> V_4 ) ||
F_81 ( V_100 , & V_2 -> V_21 -> V_4 ) )
return;
if ( F_134 ( V_2 , V_127 , V_128 ) )
F_85 ( V_100 , & V_2 -> V_21 -> V_4 ) ;
}
static int F_137 ( struct V_19 * V_20 , struct V_136 * V_137 )
{
struct V_1 * V_2 ;
int V_50 ;
if ( F_138 ( & V_20 -> V_114 ) )
return - V_138 ;
if ( V_20 -> V_139 . V_136 ) {
V_50 = - V_140 ;
goto V_141;
}
if ( ! V_137 -> V_15 ) {
V_137 -> V_15 = F_139 ( NULL , V_142 - V_27 ,
V_27 , 0 , 0 ) ;
if ( V_137 -> V_15 & ~ V_41 ) {
V_50 = V_137 -> V_15 ;
goto V_141;
}
}
V_2 = F_140 ( V_20 , V_137 -> V_15 , V_27 ,
V_143 | V_6 | V_144 | V_145 ,
& V_137 -> V_146 ) ;
if ( F_75 ( V_2 ) ) {
V_50 = F_76 ( V_2 ) ;
goto V_141;
}
V_50 = 0 ;
F_84 () ;
V_20 -> V_139 . V_136 = V_137 ;
V_141:
F_70 ( & V_20 -> V_114 ) ;
return V_50 ;
}
static struct V_136 * F_141 ( unsigned long V_15 )
{
struct V_19 * V_20 = V_134 -> V_20 ;
T_5 V_36 = V_37 ;
struct V_136 * V_137 ;
V_137 = F_103 ( sizeof( * V_137 ) , V_30 ) ;
if ( F_44 ( ! V_137 ) )
goto V_93;
V_137 -> V_147 = F_64 ( F_142 ( V_148 ) * sizeof( long ) , V_30 ) ;
if ( ! V_137 -> V_147 )
goto V_149;
V_137 -> V_146 . V_150 = L_1 ;
V_137 -> V_146 . V_151 = NULL ;
V_137 -> V_146 . V_152 = V_137 -> V_152 ;
V_137 -> V_152 [ 0 ] = F_143 ( V_153 ) ;
if ( ! V_137 -> V_152 [ 0 ] )
goto V_154;
V_137 -> V_152 [ 1 ] = NULL ;
V_137 -> V_15 = V_15 ;
F_144 ( & V_137 -> V_155 ) ;
F_85 ( 0 , V_137 -> V_147 ) ;
F_61 ( & V_137 -> V_156 , 1 ) ;
F_36 ( V_137 -> V_152 [ 0 ] , 0 , & V_36 , V_46 ) ;
if ( ! F_137 ( V_20 , V_137 ) )
return V_137 ;
F_145 ( V_137 -> V_152 [ 0 ] ) ;
V_154:
F_51 ( V_137 -> V_147 ) ;
V_149:
F_51 ( V_137 ) ;
V_93:
return NULL ;
}
static struct V_136 * F_146 ( void )
{
struct V_19 * V_20 = V_134 -> V_20 ;
struct V_136 * V_137 ;
if ( ! V_20 -> V_139 . V_136 )
F_141 ( 0 ) ;
V_137 = V_20 -> V_139 . V_136 ;
F_147 () ;
return V_137 ;
}
void F_148 ( struct V_19 * V_20 )
{
struct V_136 * V_137 = V_20 -> V_139 . V_136 ;
if ( ! V_137 )
return;
F_28 ( V_137 -> V_152 [ 0 ] ) ;
F_51 ( V_137 -> V_147 ) ;
F_51 ( V_137 ) ;
}
void F_149 ( void )
{
F_150 ( & V_113 ) ;
}
void F_151 ( void )
{
F_152 ( & V_113 ) ;
}
void F_153 ( struct V_19 * V_157 , struct V_19 * V_158 )
{
V_158 -> V_139 . V_136 = NULL ;
if ( F_81 ( V_99 , & V_157 -> V_4 ) ) {
F_85 ( V_99 , & V_158 -> V_4 ) ;
F_85 ( V_100 , & V_158 -> V_4 ) ;
}
}
static unsigned long F_154 ( struct V_136 * V_137 )
{
unsigned long V_159 ;
int V_160 ;
do {
V_160 = F_155 ( V_137 -> V_147 , V_148 ) ;
if ( V_160 < V_148 ) {
if ( ! F_156 ( V_160 , V_137 -> V_147 ) )
break;
V_160 = V_148 ;
continue;
}
F_157 ( V_137 -> V_155 , ( F_136 ( & V_137 -> V_156 ) < V_148 ) ) ;
} while ( V_160 >= V_148 );
V_159 = V_137 -> V_15 + ( V_160 * V_161 ) ;
F_48 ( & V_137 -> V_156 ) ;
return V_159 ;
}
static unsigned long F_158 ( struct V_57 * V_57 )
{
struct V_136 * V_137 ;
unsigned long V_162 ;
V_137 = F_146 () ;
if ( ! V_137 )
return 0 ;
V_162 = F_154 ( V_137 ) ;
if ( F_44 ( ! V_162 ) )
return 0 ;
F_159 ( V_137 -> V_152 [ 0 ] , V_162 ,
& V_57 -> V_89 . V_163 , sizeof( V_57 -> V_89 . V_163 ) ) ;
return V_162 ;
}
static void F_160 ( struct V_164 * V_165 )
{
struct V_136 * V_137 ;
unsigned long V_166 ;
unsigned long V_159 ;
if ( ! V_165 -> V_20 || ! V_165 -> V_20 -> V_139 . V_136 || ! V_165 -> V_167 )
return;
V_159 = V_165 -> V_167 -> V_162 ;
if ( F_44 ( ! V_159 ) )
return;
V_137 = V_165 -> V_20 -> V_139 . V_136 ;
V_166 = V_137 -> V_15 + V_27 ;
if ( V_137 -> V_15 <= V_159 && V_159 < V_166 ) {
unsigned long V_11 ;
int V_160 ;
V_11 = V_159 - V_137 -> V_15 ;
V_160 = V_11 / V_161 ;
if ( V_160 >= V_148 )
return;
F_91 ( V_160 , V_137 -> V_147 ) ;
F_161 ( & V_137 -> V_156 ) ;
F_162 () ;
if ( F_163 ( & V_137 -> V_155 ) )
F_164 ( & V_137 -> V_155 ) ;
V_165 -> V_167 -> V_162 = 0 ;
}
}
void __weak F_159 ( struct V_17 * V_17 , unsigned long V_15 ,
void * V_42 , unsigned long V_39 )
{
F_36 ( V_17 , V_15 , V_42 , V_39 ) ;
F_165 ( V_17 ) ;
}
unsigned long __weak F_166 ( struct V_168 * V_169 )
{
return F_167 ( V_169 ) - V_46 ;
}
unsigned long F_168 ( struct V_168 * V_169 )
{
struct V_170 * V_167 = V_134 -> V_167 ;
if ( F_44 ( V_167 && V_167 -> V_171 ) )
return V_167 -> V_15 ;
return F_167 ( V_169 ) ;
}
static struct V_172 * F_169 ( struct V_172 * V_173 )
{
struct V_172 * V_77 = V_173 -> V_77 ;
F_49 ( V_173 -> V_57 ) ;
F_51 ( V_173 ) ;
return V_77 ;
}
void F_170 ( struct V_164 * V_131 )
{
struct V_170 * V_167 = V_131 -> V_167 ;
struct V_172 * V_173 ;
if ( ! V_167 )
return;
if ( V_167 -> V_171 )
F_49 ( V_167 -> V_171 ) ;
V_173 = V_167 -> V_174 ;
while ( V_173 )
V_173 = F_169 ( V_173 ) ;
F_160 ( V_131 ) ;
F_51 ( V_167 ) ;
V_131 -> V_167 = NULL ;
}
static struct V_170 * F_171 ( void )
{
if ( ! V_134 -> V_167 )
V_134 -> V_167 = F_64 ( sizeof( struct V_170 ) , V_30 ) ;
return V_134 -> V_167 ;
}
static int F_172 ( struct V_164 * V_131 , struct V_170 * V_175 )
{
struct V_170 * V_176 ;
struct V_172 * * V_70 , * V_177 , * V_64 ;
V_176 = F_64 ( sizeof( struct V_170 ) , V_30 ) ;
if ( ! V_176 )
return - V_53 ;
V_131 -> V_167 = V_176 ;
V_70 = & V_176 -> V_174 ;
for ( V_177 = V_175 -> V_174 ; V_177 ; V_177 = V_177 -> V_77 ) {
V_64 = F_103 ( sizeof( struct V_172 ) , V_30 ) ;
if ( ! V_64 )
return - V_53 ;
* V_64 = * V_177 ;
F_47 ( V_64 -> V_57 ) ;
V_64 -> V_77 = NULL ;
* V_70 = V_64 ;
V_70 = & V_64 -> V_77 ;
V_176 -> V_178 ++ ;
}
return 0 ;
}
static void F_173 ( struct V_164 * V_131 , const char * V_179 )
{
F_174 ( L_2 ,
V_134 -> V_180 , V_134 -> V_181 , V_179 ) ;
}
static void F_175 ( struct V_182 * V_183 )
{
if ( V_134 -> V_4 & V_184 )
return;
if ( ! F_141 ( V_134 -> V_167 -> V_185 ) &&
! F_132 ( V_134 ) )
F_173 ( V_134 , L_3 ) ;
}
void F_176 ( struct V_164 * V_131 , unsigned long V_4 )
{
struct V_170 * V_167 = V_134 -> V_167 ;
struct V_19 * V_20 = V_134 -> V_20 ;
struct V_136 * V_137 ;
V_131 -> V_167 = NULL ;
if ( ! V_167 || ! V_167 -> V_174 )
return;
if ( V_20 == V_131 -> V_20 && ! ( V_4 & V_186 ) )
return;
if ( F_172 ( V_131 , V_167 ) )
return F_173 ( V_131 , L_4 ) ;
V_137 = V_20 -> V_139 . V_136 ;
if ( ! V_137 )
return F_173 ( V_131 , L_3 ) ;
if ( V_20 == V_131 -> V_20 )
return;
V_131 -> V_167 -> V_185 = V_137 -> V_15 ;
F_177 ( & V_131 -> V_167 -> F_175 , F_175 ) ;
F_178 ( V_131 , & V_131 -> V_167 -> F_175 , true ) ;
}
static unsigned long F_179 ( void )
{
struct V_136 * V_137 ;
unsigned long V_187 = - 1 ;
V_137 = V_134 -> V_20 -> V_139 . V_136 ;
F_147 () ;
if ( V_137 )
V_187 = V_137 -> V_15 ;
return V_187 ;
}
static void F_180 ( struct V_170 * V_167 , bool V_188 ,
struct V_168 * V_169 )
{
struct V_172 * V_173 = V_167 -> V_174 ;
enum V_189 V_96 = V_188 ? V_190 : V_191 ;
while ( V_173 && ! F_181 ( V_173 , V_96 , V_169 ) ) {
V_173 = F_169 ( V_173 ) ;
V_167 -> V_178 -- ;
}
V_167 -> V_174 = V_173 ;
}
static void F_182 ( struct V_57 * V_57 , struct V_168 * V_169 )
{
struct V_172 * V_173 ;
struct V_170 * V_167 ;
unsigned long V_192 , V_187 ;
bool V_188 ;
if ( ! F_146 () )
return;
V_167 = F_171 () ;
if ( ! V_167 )
return;
if ( V_167 -> V_178 >= V_193 ) {
F_183 ( V_194 L_5
L_6 ,
V_134 -> V_181 , V_134 -> V_195 ) ;
return;
}
V_173 = F_103 ( sizeof( struct V_172 ) , V_30 ) ;
if ( ! V_173 )
return;
V_187 = F_179 () ;
V_192 = F_184 ( V_187 , V_169 ) ;
if ( V_192 == - 1 )
goto V_141;
V_188 = ( V_192 == V_187 ) ;
F_180 ( V_167 , V_188 , V_169 ) ;
if ( V_188 ) {
if ( ! V_167 -> V_174 ) {
F_173 ( V_134 , L_7 ) ;
goto V_141;
}
V_192 = V_167 -> V_174 -> V_192 ;
}
V_173 -> V_57 = F_47 ( V_57 ) ;
V_173 -> V_196 = F_167 ( V_169 ) ;
V_173 -> V_197 = F_185 ( V_169 ) ;
V_173 -> V_192 = V_192 ;
V_173 -> V_188 = V_188 ;
V_167 -> V_178 ++ ;
V_173 -> V_77 = V_167 -> V_174 ;
V_167 -> V_174 = V_173 ;
return;
V_141:
F_51 ( V_173 ) ;
}
static int
F_186 ( struct V_57 * V_57 , struct V_168 * V_169 , unsigned long V_198 )
{
struct V_170 * V_167 ;
unsigned long V_162 ;
int V_24 ;
V_167 = F_171 () ;
if ( ! V_167 )
return - V_53 ;
V_162 = F_158 ( V_57 ) ;
if ( ! V_162 )
return - V_53 ;
V_167 -> V_162 = V_162 ;
V_167 -> V_15 = V_198 ;
V_24 = F_187 ( & V_57 -> V_89 , V_169 ) ;
if ( F_44 ( V_24 ) ) {
F_160 ( V_134 ) ;
return V_24 ;
}
V_167 -> V_171 = V_57 ;
V_167 -> V_199 = V_200 ;
return 0 ;
}
bool F_188 ( void )
{
struct V_164 * V_131 = V_134 ;
struct V_170 * V_167 = V_131 -> V_167 ;
if ( F_117 ( ! V_167 || ! V_167 -> V_171 ) )
return false ;
F_189 ( V_167 -> V_199 != V_200 ) ;
if ( F_190 ( V_131 ) ) {
F_191 ( & V_131 -> V_201 -> V_202 ) ;
F_192 ( V_131 , V_203 ) ;
F_193 ( & V_131 -> V_201 -> V_202 ) ;
if ( F_194 ( V_131 ) || F_195 ( V_131 ) ) {
V_167 -> V_199 = V_204 ;
F_196 ( V_131 , V_205 ) ;
}
}
return true ;
}
static void F_197 ( struct V_19 * V_20 )
{
struct V_1 * V_2 ;
for ( V_2 = V_20 -> V_122 ; V_2 ; V_2 = V_2 -> V_123 ) {
if ( ! F_1 ( V_2 , false ) )
continue;
if ( F_134 ( V_2 , V_2 -> V_12 , V_2 -> V_124 ) )
return;
}
F_91 ( V_99 , & V_20 -> V_4 ) ;
}
static int F_198 ( struct V_19 * V_20 , unsigned long V_15 )
{
struct V_17 * V_17 ;
T_5 V_47 ;
int V_206 ;
F_199 () ;
V_206 = F_200 ( V_47 , ( T_5 V_207 * ) V_15 ) ;
F_201 () ;
if ( F_117 ( V_206 == 0 ) )
goto V_93;
V_206 = F_39 ( NULL , V_20 , V_15 , 1 , 0 , 1 , & V_17 , NULL ) ;
if ( V_206 < 0 )
return V_206 ;
F_33 ( V_17 , V_15 , & V_47 , V_46 ) ;
F_28 ( V_17 ) ;
V_93:
return F_32 ( & V_47 ) ;
}
static struct V_57 * F_202 ( unsigned long V_198 , int * V_45 )
{
struct V_19 * V_20 = V_134 -> V_20 ;
struct V_57 * V_57 = NULL ;
struct V_1 * V_2 ;
F_88 ( & V_20 -> V_114 ) ;
V_2 = F_110 ( V_20 , V_198 ) ;
if ( V_2 && V_2 -> V_12 <= V_198 ) {
if ( F_1 ( V_2 , false ) ) {
struct V_61 * V_61 = F_111 ( V_2 -> V_9 ) ;
T_2 V_11 = F_3 ( V_2 , V_198 ) ;
V_57 = F_55 ( V_61 , V_11 ) ;
}
if ( ! V_57 )
* V_45 = F_198 ( V_20 , V_198 ) ;
} else {
* V_45 = - V_208 ;
}
if ( ! V_57 && F_203 ( V_100 , & V_20 -> V_4 ) )
F_197 ( V_20 ) ;
F_89 ( & V_20 -> V_114 ) ;
return V_57 ;
}
static void F_204 ( struct V_57 * V_57 , struct V_168 * V_169 )
{
struct V_75 * V_76 ;
int remove = V_209 ;
bool V_210 = false ;
F_88 ( & V_57 -> V_73 ) ;
for ( V_76 = V_57 -> V_78 ; V_76 ; V_76 = V_76 -> V_77 ) {
int V_211 = 0 ;
if ( V_76 -> V_117 ) {
V_211 = V_76 -> V_117 ( V_76 , V_169 ) ;
F_205 ( V_211 & ~ V_212 ,
L_8 , V_211 , V_76 -> V_117 ) ;
}
if ( V_76 -> V_118 )
V_210 = true ;
remove &= V_211 ;
}
if ( V_210 && ! remove )
F_182 ( V_57 , V_169 ) ;
if ( remove && V_57 -> V_78 ) {
F_96 ( ! F_93 ( V_57 ) ) ;
F_120 ( V_57 , V_134 -> V_20 ) ;
}
F_89 ( & V_57 -> V_73 ) ;
}
static void
F_206 ( struct V_172 * V_173 , struct V_168 * V_169 )
{
struct V_57 * V_57 = V_173 -> V_57 ;
struct V_75 * V_76 ;
F_88 ( & V_57 -> V_73 ) ;
for ( V_76 = V_57 -> V_78 ; V_76 ; V_76 = V_76 -> V_77 ) {
if ( V_76 -> V_118 )
V_76 -> V_118 ( V_76 , V_173 -> V_196 , V_169 ) ;
}
F_89 ( & V_57 -> V_73 ) ;
}
static struct V_172 * F_207 ( struct V_172 * V_173 )
{
bool V_188 ;
do {
V_188 = V_173 -> V_188 ;
V_173 = V_173 -> V_77 ;
} while ( V_188 );
return V_173 ;
}
static void F_208 ( struct V_168 * V_169 )
{
struct V_170 * V_167 ;
struct V_172 * V_173 , * V_77 ;
bool V_213 ;
V_167 = V_134 -> V_167 ;
if ( ! V_167 )
goto V_214;
V_173 = V_167 -> V_174 ;
if ( ! V_173 )
goto V_214;
do {
V_77 = F_207 ( V_173 ) ;
V_213 = ! V_77 || F_181 ( V_77 , V_215 , V_169 ) ;
F_209 ( V_169 , V_173 -> V_192 ) ;
do {
if ( V_213 )
F_206 ( V_173 , V_169 ) ;
V_173 = F_169 ( V_173 ) ;
V_167 -> V_178 -- ;
} while ( V_173 != V_77 );
} while ( ! V_213 );
V_167 -> V_174 = V_173 ;
return;
V_214:
F_173 ( V_134 , L_9 ) ;
F_210 ( V_216 , V_217 , V_134 ) ;
}
bool __weak F_211 ( struct V_55 * V_218 , struct V_168 * V_169 )
{
return false ;
}
bool __weak F_181 ( struct V_172 * V_50 , enum V_189 V_96 ,
struct V_168 * V_169 )
{
return true ;
}
static void F_212 ( struct V_168 * V_169 )
{
struct V_57 * V_57 ;
unsigned long V_198 ;
int V_219 ( V_45 ) ;
V_198 = F_166 ( V_169 ) ;
if ( V_198 == F_179 () )
return F_208 ( V_169 ) ;
V_57 = F_202 ( V_198 , & V_45 ) ;
if ( ! V_57 ) {
if ( V_45 > 0 ) {
F_213 ( V_220 , V_134 , 0 ) ;
} else {
F_209 ( V_169 , V_198 ) ;
}
return;
}
F_209 ( V_169 , V_198 ) ;
F_214 () ;
if ( F_44 ( ! F_81 ( V_92 , & V_57 -> V_4 ) ) )
goto V_93;
if ( ! F_171 () )
goto V_93;
if ( F_211 ( & V_57 -> V_89 , V_169 ) )
goto V_93;
F_204 ( V_57 , V_169 ) ;
if ( F_215 ( & V_57 -> V_89 , V_169 ) )
goto V_93;
if ( ! F_186 ( V_57 , V_169 , V_198 ) )
return;
V_93:
F_49 ( V_57 ) ;
}
static void F_216 ( struct V_170 * V_167 , struct V_168 * V_169 )
{
struct V_57 * V_57 ;
int V_24 = 0 ;
V_57 = V_167 -> V_171 ;
if ( V_167 -> V_199 == V_221 )
V_24 = F_217 ( & V_57 -> V_89 , V_169 ) ;
else if ( V_167 -> V_199 == V_204 )
F_218 ( & V_57 -> V_89 , V_169 ) ;
else
F_189 ( 1 ) ;
F_49 ( V_57 ) ;
V_167 -> V_171 = NULL ;
V_167 -> V_199 = V_222 ;
F_160 ( V_134 ) ;
F_191 ( & V_134 -> V_201 -> V_202 ) ;
F_219 () ;
F_193 ( & V_134 -> V_201 -> V_202 ) ;
if ( F_44 ( V_24 ) ) {
F_173 ( V_134 , L_10 ) ;
F_210 ( V_216 , V_217 , V_134 ) ;
}
}
void F_220 ( struct V_168 * V_169 )
{
struct V_170 * V_167 ;
F_221 ( V_205 ) ;
V_167 = V_134 -> V_167 ;
if ( V_167 && V_167 -> V_171 )
F_216 ( V_167 , V_169 ) ;
else
F_212 ( V_169 ) ;
}
int F_222 ( struct V_168 * V_169 )
{
if ( ! V_134 -> V_20 )
return 0 ;
if ( ! F_81 ( V_99 , & V_134 -> V_20 -> V_4 ) &&
( ! V_134 -> V_167 || ! V_134 -> V_167 -> V_174 ) )
return 0 ;
F_223 ( V_205 ) ;
return 1 ;
}
int F_224 ( struct V_168 * V_169 )
{
struct V_170 * V_167 = V_134 -> V_167 ;
if ( ! V_134 -> V_20 || ! V_167 || ! V_167 -> V_171 )
return 0 ;
V_167 -> V_199 = V_221 ;
F_223 ( V_205 ) ;
return 1 ;
}
static int T_6 F_225 ( void )
{
int V_223 ;
for ( V_223 = 0 ; V_223 < V_224 ; V_223 ++ )
F_226 ( & V_225 [ V_223 ] ) ;
if ( F_227 ( & V_113 ) )
return - V_53 ;
return F_228 ( & V_226 ) ;
}
