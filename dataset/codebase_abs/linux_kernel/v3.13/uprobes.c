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
V_48 = - V_51 ;
V_47 = F_35 ( V_52 , V_2 , V_15 ) ;
if ( ! V_47 )
goto V_50;
F_36 ( V_47 ) ;
F_37 ( V_47 , V_46 ) ;
F_31 ( V_47 , V_15 , & V_45 , V_44 ) ;
V_48 = F_38 ( V_2 ) ;
if ( V_48 )
goto V_53;
V_48 = F_4 ( V_2 , V_15 , V_46 , V_47 ) ;
V_53:
F_39 ( V_47 ) ;
V_50:
F_23 ( V_46 ) ;
if ( F_40 ( V_48 == - V_28 ) )
goto V_49;
return V_48 ;
}
int __weak F_41 ( struct V_54 * V_55 , struct V_19 * V_20 , unsigned long V_15 )
{
return F_33 ( V_20 , V_15 , V_35 ) ;
}
int __weak
F_42 ( struct V_54 * V_55 , struct V_19 * V_20 , unsigned long V_15 )
{
return F_33 ( V_20 , V_15 , * ( T_5 * ) V_55 -> V_34 ) ;
}
static int F_43 ( struct V_56 * V_57 , struct V_56 * V_58 )
{
if ( V_57 -> V_59 < V_58 -> V_59 )
return - 1 ;
if ( V_57 -> V_59 > V_58 -> V_59 )
return 1 ;
if ( V_57 -> V_11 < V_58 -> V_11 )
return - 1 ;
if ( V_57 -> V_11 > V_58 -> V_11 )
return 1 ;
return 0 ;
}
static struct V_56 * F_44 ( struct V_59 * V_59 , T_2 V_11 )
{
struct V_56 V_60 = { . V_59 = V_59 , . V_11 = V_11 } ;
struct V_61 * V_62 = V_63 . V_61 ;
struct V_56 * V_56 ;
int V_64 ;
while ( V_62 ) {
V_56 = F_45 ( V_62 , struct V_56 , V_61 ) ;
V_64 = F_43 ( & V_60 , V_56 ) ;
if ( ! V_64 ) {
F_46 ( & V_56 -> V_65 ) ;
return V_56 ;
}
if ( V_64 < 0 )
V_62 = V_62 -> V_66 ;
else
V_62 = V_62 -> V_67 ;
}
return NULL ;
}
static struct V_56 * F_47 ( struct V_59 * V_59 , T_2 V_11 )
{
struct V_56 * V_56 ;
F_48 ( & V_68 ) ;
V_56 = F_44 ( V_59 , V_11 ) ;
F_49 ( & V_68 ) ;
return V_56 ;
}
static struct V_56 * F_50 ( struct V_56 * V_56 )
{
struct V_61 * * V_69 = & V_63 . V_61 ;
struct V_61 * V_70 = NULL ;
struct V_56 * V_60 ;
int V_64 ;
while ( * V_69 ) {
V_70 = * V_69 ;
V_60 = F_45 ( V_70 , struct V_56 , V_61 ) ;
V_64 = F_43 ( V_56 , V_60 ) ;
if ( ! V_64 ) {
F_46 ( & V_60 -> V_65 ) ;
return V_60 ;
}
if ( V_64 < 0 )
V_69 = & V_70 -> V_66 ;
else
V_69 = & V_70 -> V_67 ;
}
V_60 = NULL ;
F_51 ( & V_56 -> V_61 , V_70 , V_69 ) ;
F_52 ( & V_56 -> V_61 , & V_63 ) ;
F_53 ( & V_56 -> V_65 , 2 ) ;
return V_60 ;
}
static struct V_56 * F_54 ( struct V_56 * V_56 )
{
struct V_56 * V_60 ;
F_48 ( & V_68 ) ;
V_60 = F_50 ( V_56 ) ;
F_49 ( & V_68 ) ;
return V_60 ;
}
static void F_55 ( struct V_56 * V_56 )
{
if ( F_56 ( & V_56 -> V_65 ) )
F_57 ( V_56 ) ;
}
static struct V_56 * F_58 ( struct V_59 * V_59 , T_2 V_11 )
{
struct V_56 * V_56 , * V_71 ;
V_56 = F_59 ( sizeof( struct V_56 ) , V_72 ) ;
if ( ! V_56 )
return NULL ;
V_56 -> V_59 = F_60 ( V_59 ) ;
V_56 -> V_11 = V_11 ;
F_61 ( & V_56 -> V_73 ) ;
F_61 ( & V_56 -> V_74 ) ;
F_62 ( V_75 , & V_56 -> V_4 ) ;
V_71 = F_54 ( V_56 ) ;
if ( V_71 ) {
F_57 ( V_56 ) ;
V_56 = V_71 ;
F_63 ( V_59 ) ;
}
return V_56 ;
}
static void F_64 ( struct V_56 * V_56 , struct V_76 * V_77 )
{
F_65 ( & V_56 -> V_74 ) ;
V_77 -> V_78 = V_56 -> V_79 ;
V_56 -> V_79 = V_77 ;
F_66 ( & V_56 -> V_74 ) ;
}
static bool F_67 ( struct V_56 * V_56 , struct V_76 * V_77 )
{
struct V_76 * * V_80 ;
bool V_48 = false ;
F_65 ( & V_56 -> V_74 ) ;
for ( V_80 = & V_56 -> V_79 ; * V_80 ; V_80 = & ( * V_80 ) -> V_78 ) {
if ( * V_80 == V_77 ) {
* V_80 = V_77 -> V_78 ;
V_48 = true ;
break;
}
}
F_66 ( & V_56 -> V_74 ) ;
return V_48 ;
}
static int F_68 ( struct V_81 * V_82 , struct V_83 * V_84 ,
void * V_34 , int V_85 , T_2 V_11 )
{
struct V_17 * V_17 ;
if ( ! V_82 -> V_86 -> V_87 )
return - V_88 ;
V_17 = F_69 ( V_82 , V_11 >> V_89 , V_84 ) ;
if ( F_70 ( V_17 ) )
return F_71 ( V_17 ) ;
F_28 ( V_17 , V_11 , V_34 , V_85 ) ;
F_39 ( V_17 ) ;
return 0 ;
}
static int F_72 ( struct V_56 * V_56 , struct V_83 * V_84 )
{
struct V_81 * V_82 = V_56 -> V_59 -> V_90 ;
T_2 V_91 = V_56 -> V_11 ;
void * V_34 = V_56 -> V_92 . V_34 ;
int V_93 = V_94 ;
int V_37 , V_24 = - V_88 ;
do {
if ( V_91 >= F_73 ( V_56 -> V_59 ) )
break;
V_37 = F_74 ( int , V_93 , V_27 - ( V_91 & ~ V_39 ) ) ;
V_24 = F_68 ( V_82 , V_84 , V_34 , V_37 , V_91 ) ;
if ( V_24 )
break;
V_34 += V_37 ;
V_91 += V_37 ;
V_93 -= V_37 ;
} while ( V_93 );
return V_24 ;
}
static int F_75 ( struct V_56 * V_56 , struct V_83 * V_83 ,
struct V_19 * V_20 , unsigned long V_15 )
{
int V_48 = 0 ;
if ( F_76 ( V_95 , & V_56 -> V_4 ) )
return V_48 ;
F_65 ( & V_56 -> V_74 ) ;
if ( F_76 ( V_95 , & V_56 -> V_4 ) )
goto V_96;
V_48 = F_72 ( V_56 , V_83 ) ;
if ( V_48 )
goto V_96;
V_48 = - V_97 ;
if ( F_27 ( ( T_5 * ) V_56 -> V_92 . V_34 ) )
goto V_96;
V_48 = F_77 ( & V_56 -> V_92 , V_20 , V_15 ) ;
if ( V_48 )
goto V_96;
F_78 ( ( V_56 -> V_11 & ~ V_39 ) +
V_44 > V_27 ) ;
F_79 () ;
F_80 ( V_95 , & V_56 -> V_4 ) ;
V_96:
F_66 ( & V_56 -> V_74 ) ;
return V_48 ;
}
static inline bool F_81 ( struct V_76 * V_77 ,
enum V_98 V_99 , struct V_19 * V_20 )
{
return ! V_77 -> V_100 || V_77 -> V_100 ( V_77 , V_99 , V_20 ) ;
}
static bool F_82 ( struct V_56 * V_56 ,
enum V_98 V_99 , struct V_19 * V_20 )
{
struct V_76 * V_77 ;
bool V_48 = false ;
F_83 ( & V_56 -> V_74 ) ;
for ( V_77 = V_56 -> V_79 ; V_77 ; V_77 = V_77 -> V_78 ) {
V_48 = F_81 ( V_77 , V_99 , V_20 ) ;
if ( V_48 )
break;
}
F_84 ( & V_56 -> V_74 ) ;
return V_48 ;
}
static int
F_85 ( struct V_56 * V_56 , struct V_19 * V_20 ,
struct V_1 * V_2 , unsigned long V_15 )
{
bool V_101 ;
int V_48 ;
V_48 = F_75 ( V_56 , V_2 -> V_9 , V_20 , V_15 ) ;
if ( V_48 )
return V_48 ;
V_101 = ! F_76 ( V_102 , & V_20 -> V_4 ) ;
if ( V_101 )
F_80 ( V_102 , & V_20 -> V_4 ) ;
V_48 = F_41 ( & V_56 -> V_92 , V_20 , V_15 ) ;
if ( ! V_48 )
F_86 ( V_103 , & V_20 -> V_4 ) ;
else if ( V_101 )
F_86 ( V_102 , & V_20 -> V_4 ) ;
return V_48 ;
}
static int
F_87 ( struct V_56 * V_56 , struct V_19 * V_20 , unsigned long V_15 )
{
F_80 ( V_103 , & V_20 -> V_4 ) ;
return F_42 ( & V_56 -> V_92 , V_20 , V_15 ) ;
}
static inline bool F_88 ( struct V_56 * V_56 )
{
return ! F_89 ( & V_56 -> V_61 ) ;
}
static void F_90 ( struct V_56 * V_56 )
{
if ( F_91 ( ! F_88 ( V_56 ) ) )
return;
F_48 ( & V_68 ) ;
F_92 ( & V_56 -> V_61 , & V_63 ) ;
F_49 ( & V_68 ) ;
F_93 ( & V_56 -> V_61 ) ;
F_63 ( V_56 -> V_59 ) ;
F_55 ( V_56 ) ;
}
static inline struct V_104 * F_94 ( struct V_104 * V_105 )
{
struct V_104 * V_78 = V_105 -> V_78 ;
F_57 ( V_105 ) ;
return V_78 ;
}
static struct V_104 *
F_95 ( struct V_81 * V_82 , T_2 V_11 , bool V_3 )
{
unsigned long V_106 = V_11 >> V_14 ;
struct V_1 * V_2 ;
struct V_104 * V_107 = NULL ;
struct V_104 * V_108 = NULL ;
struct V_104 * V_105 ;
int V_109 = 0 ;
V_110:
F_96 ( & V_82 -> V_111 ) ;
F_97 (vma, &mapping->i_mmap, pgoff, pgoff) {
if ( ! F_1 ( V_2 , V_3 ) )
continue;
if ( ! V_108 && ! V_109 ) {
V_108 = F_98 ( sizeof( struct V_104 ) ,
V_112 | V_113 | V_114 ) ;
if ( V_108 )
V_108 -> V_78 = NULL ;
}
if ( ! V_108 ) {
V_109 ++ ;
continue;
}
if ( ! F_99 ( & V_2 -> V_21 -> V_115 ) )
continue;
V_105 = V_108 ;
V_108 = V_108 -> V_78 ;
V_105 -> V_78 = V_107 ;
V_107 = V_105 ;
V_105 -> V_20 = V_2 -> V_21 ;
V_105 -> V_15 = F_2 ( V_2 , V_11 ) ;
}
F_100 ( & V_82 -> V_111 ) ;
if ( ! V_109 )
goto V_96;
V_108 = V_107 ;
while ( V_107 ) {
F_101 ( V_107 -> V_20 ) ;
V_107 = V_107 -> V_78 ;
}
do {
V_105 = F_98 ( sizeof( struct V_104 ) , V_72 ) ;
if ( ! V_105 ) {
V_107 = F_102 ( - V_51 ) ;
goto V_96;
}
V_105 -> V_78 = V_108 ;
V_108 = V_105 ;
} while ( -- V_109 );
goto V_110;
V_96:
while ( V_108 )
V_108 = F_94 ( V_108 ) ;
return V_107 ;
}
static int
F_103 ( struct V_56 * V_56 , struct V_76 * V_116 )
{
bool V_3 = ! ! V_116 ;
struct V_104 * V_105 ;
int V_24 = 0 ;
F_104 ( & V_117 ) ;
V_105 = F_95 ( V_56 -> V_59 -> V_90 ,
V_56 -> V_11 , V_3 ) ;
if ( F_70 ( V_105 ) ) {
V_24 = F_71 ( V_105 ) ;
goto V_96;
}
while ( V_105 ) {
struct V_19 * V_20 = V_105 -> V_20 ;
struct V_1 * V_2 ;
if ( V_24 && V_3 )
goto free;
F_65 ( & V_20 -> V_118 ) ;
V_2 = F_105 ( V_20 , V_105 -> V_15 ) ;
if ( ! V_2 || ! F_1 ( V_2 , V_3 ) ||
F_106 ( V_2 -> V_9 ) != V_56 -> V_59 )
goto V_29;
if ( V_2 -> V_12 > V_105 -> V_15 ||
F_3 ( V_2 , V_105 -> V_15 ) != V_56 -> V_11 )
goto V_29;
if ( V_3 ) {
if ( F_81 ( V_116 ,
V_119 , V_20 ) )
V_24 = F_85 ( V_56 , V_20 , V_2 , V_105 -> V_15 ) ;
} else if ( F_76 ( V_102 , & V_20 -> V_4 ) ) {
if ( ! F_82 ( V_56 ,
V_120 , V_20 ) )
V_24 |= F_87 ( V_56 , V_20 , V_105 -> V_15 ) ;
}
V_29:
F_66 ( & V_20 -> V_118 ) ;
free:
F_101 ( V_20 ) ;
V_105 = F_94 ( V_105 ) ;
}
V_96:
F_107 ( & V_117 ) ;
return V_24 ;
}
static int F_108 ( struct V_56 * V_56 , struct V_76 * V_77 )
{
F_64 ( V_56 , V_77 ) ;
return F_103 ( V_56 , V_77 ) ;
}
static void F_109 ( struct V_56 * V_56 , struct V_76 * V_77 )
{
int V_24 ;
if ( ! F_67 ( V_56 , V_77 ) )
return;
V_24 = F_103 ( V_56 , NULL ) ;
if ( ! V_56 -> V_79 && ! V_24 )
F_90 ( V_56 ) ;
}
int F_110 ( struct V_59 * V_59 , T_2 V_11 , struct V_76 * V_77 )
{
struct V_56 * V_56 ;
int V_48 ;
if ( ! V_77 -> V_121 && ! V_77 -> V_122 )
return - V_123 ;
if ( V_11 > F_73 ( V_59 ) )
return - V_123 ;
V_49:
V_56 = F_58 ( V_59 , V_11 ) ;
if ( ! V_56 )
return - V_51 ;
F_65 ( & V_56 -> V_73 ) ;
V_48 = - V_28 ;
if ( F_111 ( F_88 ( V_56 ) ) ) {
V_48 = F_108 ( V_56 , V_77 ) ;
if ( V_48 )
F_109 ( V_56 , V_77 ) ;
}
F_66 ( & V_56 -> V_73 ) ;
F_55 ( V_56 ) ;
if ( F_40 ( V_48 == - V_28 ) )
goto V_49;
return V_48 ;
}
int F_112 ( struct V_59 * V_59 , T_2 V_11 ,
struct V_76 * V_77 , bool V_124 )
{
struct V_56 * V_56 ;
struct V_76 * V_80 ;
int V_48 = - V_125 ;
V_56 = F_47 ( V_59 , V_11 ) ;
if ( ! V_56 )
return V_48 ;
F_65 ( & V_56 -> V_73 ) ;
for ( V_80 = V_56 -> V_79 ; V_80 && V_80 != V_77 ; V_80 = V_80 -> V_78 )
;
if ( V_80 )
V_48 = F_103 ( V_56 , V_124 ? V_77 : NULL ) ;
F_66 ( & V_56 -> V_73 ) ;
F_55 ( V_56 ) ;
return V_48 ;
}
void F_113 ( struct V_59 * V_59 , T_2 V_11 , struct V_76 * V_77 )
{
struct V_56 * V_56 ;
V_56 = F_47 ( V_59 , V_11 ) ;
if ( ! V_56 )
return;
F_65 ( & V_56 -> V_73 ) ;
F_109 ( V_56 , V_77 ) ;
F_66 ( & V_56 -> V_73 ) ;
F_55 ( V_56 ) ;
}
static int F_114 ( struct V_56 * V_56 , struct V_19 * V_20 )
{
struct V_1 * V_2 ;
int V_24 = 0 ;
F_83 ( & V_20 -> V_118 ) ;
for ( V_2 = V_20 -> V_126 ; V_2 ; V_2 = V_2 -> V_127 ) {
unsigned long V_15 ;
T_2 V_11 ;
if ( ! F_1 ( V_2 , false ) ||
F_106 ( V_2 -> V_9 ) != V_56 -> V_59 )
continue;
V_11 = ( T_2 ) V_2 -> V_13 << V_14 ;
if ( V_56 -> V_11 < V_11 ||
V_56 -> V_11 >= V_11 + V_2 -> V_128 - V_2 -> V_12 )
continue;
V_15 = F_2 ( V_2 , V_56 -> V_11 ) ;
V_24 |= F_87 ( V_56 , V_20 , V_15 ) ;
}
F_84 ( & V_20 -> V_118 ) ;
return V_24 ;
}
static struct V_61 *
F_115 ( struct V_59 * V_59 , T_2 V_129 , T_2 V_130 )
{
struct V_61 * V_62 = V_63 . V_61 ;
while ( V_62 ) {
struct V_56 * V_60 = F_45 ( V_62 , struct V_56 , V_61 ) ;
if ( V_59 < V_60 -> V_59 ) {
V_62 = V_62 -> V_66 ;
} else if ( V_59 > V_60 -> V_59 ) {
V_62 = V_62 -> V_67 ;
} else {
if ( V_130 < V_60 -> V_11 )
V_62 = V_62 -> V_66 ;
else if ( V_129 > V_60 -> V_11 )
V_62 = V_62 -> V_67 ;
else
break;
}
}
return V_62 ;
}
static void F_116 ( struct V_59 * V_59 ,
struct V_1 * V_2 ,
unsigned long V_131 , unsigned long V_132 ,
struct V_133 * V_134 )
{
T_2 V_129 , V_130 ;
struct V_61 * V_62 , * V_135 ;
struct V_56 * V_60 ;
F_117 ( V_134 ) ;
V_129 = F_3 ( V_2 , V_131 ) ;
V_130 = V_129 + ( V_132 - V_131 ) - 1 ;
F_48 ( & V_68 ) ;
V_62 = F_115 ( V_59 , V_129 , V_130 ) ;
if ( V_62 ) {
for ( V_135 = V_62 ; V_135 ; V_135 = F_118 ( V_135 ) ) {
V_60 = F_45 ( V_135 , struct V_56 , V_61 ) ;
if ( V_60 -> V_59 != V_59 || V_60 -> V_11 < V_129 )
break;
F_119 ( & V_60 -> V_136 , V_134 ) ;
F_46 ( & V_60 -> V_65 ) ;
}
for ( V_135 = V_62 ; ( V_135 = F_120 ( V_135 ) ) ; ) {
V_60 = F_45 ( V_135 , struct V_56 , V_61 ) ;
if ( V_60 -> V_59 != V_59 || V_60 -> V_11 > V_130 )
break;
F_119 ( & V_60 -> V_136 , V_134 ) ;
F_46 ( & V_60 -> V_65 ) ;
}
}
F_49 ( & V_68 ) ;
}
int F_121 ( struct V_1 * V_2 )
{
struct V_133 V_137 ;
struct V_56 * V_56 , * V_60 ;
struct V_59 * V_59 ;
if ( F_122 () || ! F_1 ( V_2 , true ) )
return 0 ;
V_59 = F_106 ( V_2 -> V_9 ) ;
if ( ! V_59 )
return 0 ;
F_96 ( F_123 ( V_59 ) ) ;
F_116 ( V_59 , V_2 , V_2 -> V_12 , V_2 -> V_128 , & V_137 ) ;
F_124 (uprobe, u, &tmp_list, pending_list) {
if ( ! F_125 ( V_138 ) &&
F_82 ( V_56 , V_139 , V_2 -> V_21 ) ) {
unsigned long V_15 = F_2 ( V_2 , V_56 -> V_11 ) ;
F_85 ( V_56 , V_2 -> V_21 , V_2 , V_15 ) ;
}
F_55 ( V_56 ) ;
}
F_100 ( F_123 ( V_59 ) ) ;
return 0 ;
}
static bool
F_126 ( struct V_1 * V_2 , unsigned long V_131 , unsigned long V_132 )
{
T_2 V_129 , V_130 ;
struct V_59 * V_59 ;
struct V_61 * V_62 ;
V_59 = F_106 ( V_2 -> V_9 ) ;
V_129 = F_3 ( V_2 , V_131 ) ;
V_130 = V_129 + ( V_132 - V_131 ) - 1 ;
F_48 ( & V_68 ) ;
V_62 = F_115 ( V_59 , V_129 , V_130 ) ;
F_49 ( & V_68 ) ;
return ! ! V_62 ;
}
void F_127 ( struct V_1 * V_2 , unsigned long V_131 , unsigned long V_132 )
{
if ( F_122 () || ! F_1 ( V_2 , false ) )
return;
if ( ! F_128 ( & V_2 -> V_21 -> V_115 ) )
return;
if ( ! F_76 ( V_102 , & V_2 -> V_21 -> V_4 ) ||
F_76 ( V_103 , & V_2 -> V_21 -> V_4 ) )
return;
if ( F_126 ( V_2 , V_131 , V_132 ) )
F_80 ( V_103 , & V_2 -> V_21 -> V_4 ) ;
}
static int F_129 ( struct V_19 * V_20 , struct V_140 * V_141 )
{
int V_48 = - V_142 ;
F_65 ( & V_20 -> V_118 ) ;
if ( V_20 -> V_143 . V_140 )
goto V_144;
if ( ! V_141 -> V_15 ) {
V_141 -> V_15 = F_130 ( NULL , V_145 - V_27 ,
V_27 , 0 , 0 ) ;
if ( V_141 -> V_15 & ~ V_39 ) {
V_48 = V_141 -> V_15 ;
goto V_144;
}
}
V_48 = F_131 ( V_20 , V_141 -> V_15 , V_27 ,
V_146 | V_6 | V_147 | V_148 , & V_141 -> V_17 ) ;
if ( V_48 )
goto V_144;
F_79 () ;
V_20 -> V_143 . V_140 = V_141 ;
V_144:
F_66 ( & V_20 -> V_118 ) ;
return V_48 ;
}
static struct V_140 * F_132 ( unsigned long V_15 )
{
struct V_19 * V_20 = V_138 -> V_20 ;
T_5 V_34 = V_35 ;
struct V_140 * V_141 ;
V_141 = F_98 ( sizeof( * V_141 ) , V_72 ) ;
if ( F_40 ( ! V_141 ) )
goto V_96;
V_141 -> V_149 = F_59 ( F_133 ( V_150 ) * sizeof( long ) , V_72 ) ;
if ( ! V_141 -> V_149 )
goto V_151;
V_141 -> V_17 = F_134 ( V_152 ) ;
if ( ! V_141 -> V_17 )
goto V_153;
V_141 -> V_15 = V_15 ;
F_135 ( & V_141 -> V_154 ) ;
F_80 ( 0 , V_141 -> V_149 ) ;
F_53 ( & V_141 -> V_155 , 1 ) ;
F_31 ( V_141 -> V_17 , 0 , & V_34 , V_44 ) ;
if ( ! F_129 ( V_20 , V_141 ) )
return V_141 ;
F_136 ( V_141 -> V_17 ) ;
V_153:
F_57 ( V_141 -> V_149 ) ;
V_151:
F_57 ( V_141 ) ;
V_96:
return NULL ;
}
static struct V_140 * F_137 ( void )
{
struct V_19 * V_20 = V_138 -> V_20 ;
struct V_140 * V_141 ;
if ( ! V_20 -> V_143 . V_140 )
F_132 ( 0 ) ;
V_141 = V_20 -> V_143 . V_140 ;
F_138 () ;
return V_141 ;
}
void F_139 ( struct V_19 * V_20 )
{
struct V_140 * V_141 = V_20 -> V_143 . V_140 ;
if ( ! V_141 )
return;
F_23 ( V_141 -> V_17 ) ;
F_57 ( V_141 -> V_149 ) ;
F_57 ( V_141 ) ;
}
void F_140 ( void )
{
F_141 ( & V_117 ) ;
}
void F_142 ( void )
{
F_143 ( & V_117 ) ;
}
void F_144 ( struct V_19 * V_156 , struct V_19 * V_157 )
{
V_157 -> V_143 . V_140 = NULL ;
if ( F_76 ( V_102 , & V_156 -> V_4 ) ) {
F_80 ( V_102 , & V_157 -> V_4 ) ;
F_80 ( V_103 , & V_157 -> V_4 ) ;
}
}
static unsigned long F_145 ( struct V_140 * V_141 )
{
unsigned long V_158 ;
int V_159 ;
do {
V_159 = F_146 ( V_141 -> V_149 , V_150 ) ;
if ( V_159 < V_150 ) {
if ( ! F_147 ( V_159 , V_141 -> V_149 ) )
break;
V_159 = V_150 ;
continue;
}
F_148 ( V_141 -> V_154 , ( F_128 ( & V_141 -> V_155 ) < V_150 ) ) ;
} while ( V_159 >= V_150 );
V_158 = V_141 -> V_15 + ( V_159 * V_160 ) ;
F_46 ( & V_141 -> V_155 ) ;
return V_158 ;
}
static unsigned long F_149 ( struct V_56 * V_56 )
{
struct V_140 * V_141 ;
unsigned long V_161 ;
V_141 = F_137 () ;
if ( ! V_141 )
return 0 ;
V_161 = F_145 ( V_141 ) ;
if ( F_40 ( ! V_161 ) )
return 0 ;
F_31 ( V_141 -> V_17 , V_161 ,
V_56 -> V_92 . V_162 , sizeof( V_56 -> V_92 . V_162 ) ) ;
F_150 ( V_141 -> V_17 ) ;
return V_161 ;
}
static void F_151 ( struct V_163 * V_164 )
{
struct V_140 * V_141 ;
unsigned long V_165 ;
unsigned long V_158 ;
if ( ! V_164 -> V_20 || ! V_164 -> V_20 -> V_143 . V_140 || ! V_164 -> V_166 )
return;
V_158 = V_164 -> V_166 -> V_161 ;
if ( F_40 ( ! V_158 ) )
return;
V_141 = V_164 -> V_20 -> V_143 . V_140 ;
V_165 = V_141 -> V_15 + V_27 ;
if ( V_141 -> V_15 <= V_158 && V_158 < V_165 ) {
unsigned long V_11 ;
int V_159 ;
V_11 = V_158 - V_141 -> V_15 ;
V_159 = V_11 / V_160 ;
if ( V_159 >= V_150 )
return;
F_86 ( V_159 , V_141 -> V_149 ) ;
F_152 ( & V_141 -> V_155 ) ;
if ( F_153 ( & V_141 -> V_154 ) )
F_154 ( & V_141 -> V_154 ) ;
V_164 -> V_166 -> V_161 = 0 ;
}
}
unsigned long __weak F_155 ( struct V_167 * V_168 )
{
return F_156 ( V_168 ) - V_44 ;
}
void F_157 ( struct V_163 * V_135 )
{
struct V_169 * V_166 = V_135 -> V_166 ;
struct V_170 * V_171 , * V_172 ;
if ( ! V_166 )
return;
if ( V_166 -> V_173 )
F_55 ( V_166 -> V_173 ) ;
V_171 = V_166 -> V_174 ;
while ( V_171 ) {
V_172 = V_171 ;
V_171 = V_171 -> V_78 ;
F_55 ( V_172 -> V_56 ) ;
F_57 ( V_172 ) ;
}
F_151 ( V_135 ) ;
F_57 ( V_166 ) ;
V_135 -> V_166 = NULL ;
}
static struct V_169 * F_158 ( void )
{
if ( ! V_138 -> V_166 )
V_138 -> V_166 = F_59 ( sizeof( struct V_169 ) , V_72 ) ;
return V_138 -> V_166 ;
}
static int F_159 ( struct V_163 * V_135 , struct V_169 * V_175 )
{
struct V_169 * V_176 ;
struct V_170 * * V_69 , * V_177 , * V_62 ;
V_176 = F_59 ( sizeof( struct V_169 ) , V_72 ) ;
if ( ! V_176 )
return - V_51 ;
V_135 -> V_166 = V_176 ;
V_69 = & V_176 -> V_174 ;
for ( V_177 = V_175 -> V_174 ; V_177 ; V_177 = V_177 -> V_78 ) {
V_62 = F_98 ( sizeof( struct V_170 ) , V_72 ) ;
if ( ! V_62 )
return - V_51 ;
* V_62 = * V_177 ;
F_46 ( & V_62 -> V_56 -> V_65 ) ;
V_62 -> V_78 = NULL ;
* V_69 = V_62 ;
V_69 = & V_62 -> V_78 ;
V_176 -> V_178 ++ ;
}
return 0 ;
}
static void F_160 ( struct V_163 * V_135 , const char * V_179 )
{
F_161 ( L_1 ,
V_138 -> V_180 , V_138 -> V_181 , V_179 ) ;
}
static void F_162 ( struct V_182 * V_183 )
{
F_57 ( V_183 ) ;
if ( V_138 -> V_4 & V_184 )
return;
if ( ! F_132 ( V_138 -> V_166 -> V_15 ) )
F_160 ( V_138 , L_2 ) ;
}
void F_163 ( struct V_163 * V_135 , unsigned long V_4 )
{
struct V_169 * V_166 = V_138 -> V_166 ;
struct V_19 * V_20 = V_138 -> V_20 ;
struct V_182 * V_183 ;
struct V_140 * V_141 ;
V_135 -> V_166 = NULL ;
if ( ! V_166 || ! V_166 -> V_174 )
return;
if ( V_20 == V_135 -> V_20 && ! ( V_4 & V_185 ) )
return;
if ( F_159 ( V_135 , V_166 ) )
return F_160 ( V_135 , L_3 ) ;
V_141 = V_20 -> V_143 . V_140 ;
if ( ! V_141 )
return F_160 ( V_135 , L_2 ) ;
if ( V_20 == V_135 -> V_20 )
return;
V_183 = F_98 ( sizeof( * V_183 ) , V_72 ) ;
if ( ! V_183 )
return F_160 ( V_135 , L_2 ) ;
V_135 -> V_166 -> V_15 = V_141 -> V_15 ;
F_164 ( V_183 , F_162 ) ;
F_165 ( V_135 , V_183 , true ) ;
}
static unsigned long F_166 ( void )
{
struct V_140 * V_141 ;
unsigned long V_186 = - 1 ;
V_141 = V_138 -> V_20 -> V_143 . V_140 ;
F_138 () ;
if ( V_141 )
V_186 = V_141 -> V_15 ;
return V_186 ;
}
static void F_167 ( struct V_56 * V_56 , struct V_167 * V_168 )
{
struct V_170 * V_171 ;
struct V_169 * V_166 ;
unsigned long V_187 , V_186 ;
bool V_188 = false ;
if ( ! F_137 () )
return;
V_166 = F_158 () ;
if ( ! V_166 )
return;
if ( V_166 -> V_178 >= V_189 ) {
F_168 ( V_190 L_4
L_5 ,
V_138 -> V_181 , V_138 -> V_191 ) ;
return;
}
V_171 = F_59 ( sizeof( struct V_170 ) , V_72 ) ;
if ( ! V_171 )
goto V_144;
V_186 = F_166 () ;
V_187 = F_169 ( V_186 , V_168 ) ;
if ( V_187 == - 1 )
goto V_144;
if ( V_187 == V_186 ) {
if ( ! V_166 -> V_174 ) {
F_161 ( L_6 ,
V_138 -> V_181 , V_138 -> V_191 ) ;
goto V_144;
}
V_188 = true ;
V_187 = V_166 -> V_174 -> V_187 ;
}
F_46 ( & V_56 -> V_65 ) ;
V_171 -> V_56 = V_56 ;
V_171 -> V_192 = F_156 ( V_168 ) ;
V_171 -> V_187 = V_187 ;
V_171 -> V_188 = V_188 ;
V_166 -> V_178 ++ ;
V_171 -> V_78 = V_166 -> V_174 ;
V_166 -> V_174 = V_171 ;
return;
V_144:
F_57 ( V_171 ) ;
}
static int
F_170 ( struct V_56 * V_56 , struct V_167 * V_168 , unsigned long V_193 )
{
struct V_169 * V_166 ;
unsigned long V_161 ;
int V_24 ;
V_166 = F_158 () ;
if ( ! V_166 )
return - V_51 ;
V_161 = F_149 ( V_56 ) ;
if ( ! V_161 )
return - V_51 ;
V_166 -> V_161 = V_161 ;
V_166 -> V_15 = V_193 ;
V_24 = F_171 ( & V_56 -> V_92 , V_168 ) ;
if ( F_40 ( V_24 ) ) {
F_151 ( V_138 ) ;
return V_24 ;
}
V_166 -> V_173 = V_56 ;
V_166 -> V_194 = V_195 ;
return 0 ;
}
bool F_172 ( void )
{
struct V_163 * V_135 = V_138 ;
struct V_169 * V_166 = V_135 -> V_166 ;
if ( F_111 ( ! V_166 || ! V_166 -> V_173 ) )
return false ;
F_173 ( V_166 -> V_194 != V_195 ) ;
if ( F_174 ( V_135 ) ) {
F_175 ( & V_135 -> V_196 -> V_197 ) ;
F_176 ( V_135 , V_198 ) ;
F_177 ( & V_135 -> V_196 -> V_197 ) ;
if ( F_178 ( V_135 ) || F_179 ( V_135 ) ) {
V_166 -> V_194 = V_199 ;
F_180 ( V_135 , V_200 ) ;
F_180 ( V_135 , V_201 ) ;
}
}
return true ;
}
static bool F_181 ( struct V_56 * V_56 , struct V_167 * V_168 )
{
if ( F_76 ( V_75 , & V_56 -> V_4 ) ) {
if ( F_182 ( & V_56 -> V_92 , V_168 ) )
return true ;
F_86 ( V_75 , & V_56 -> V_4 ) ;
}
return false ;
}
static void F_183 ( struct V_19 * V_20 )
{
struct V_1 * V_2 ;
for ( V_2 = V_20 -> V_126 ; V_2 ; V_2 = V_2 -> V_127 ) {
if ( ! F_1 ( V_2 , false ) )
continue;
if ( F_126 ( V_2 , V_2 -> V_12 , V_2 -> V_128 ) )
return;
}
F_86 ( V_102 , & V_20 -> V_4 ) ;
}
static int F_184 ( struct V_19 * V_20 , unsigned long V_15 )
{
struct V_17 * V_17 ;
T_5 V_45 ;
int V_202 ;
F_185 () ;
V_202 = F_186 ( & V_45 , ( void V_203 * ) V_15 ,
sizeof( V_45 ) ) ;
F_187 () ;
if ( F_111 ( V_202 == 0 ) )
goto V_96;
V_202 = F_34 ( NULL , V_20 , V_15 , 1 , 0 , 1 , & V_17 , NULL ) ;
if ( V_202 < 0 )
return V_202 ;
F_28 ( V_17 , V_15 , & V_45 , V_44 ) ;
F_23 ( V_17 ) ;
V_96:
return F_27 ( & V_45 ) ;
}
static struct V_56 * F_188 ( unsigned long V_193 , int * V_43 )
{
struct V_19 * V_20 = V_138 -> V_20 ;
struct V_56 * V_56 = NULL ;
struct V_1 * V_2 ;
F_83 ( & V_20 -> V_118 ) ;
V_2 = F_105 ( V_20 , V_193 ) ;
if ( V_2 && V_2 -> V_12 <= V_193 ) {
if ( F_1 ( V_2 , false ) ) {
struct V_59 * V_59 = F_106 ( V_2 -> V_9 ) ;
T_2 V_11 = F_3 ( V_2 , V_193 ) ;
V_56 = F_47 ( V_59 , V_11 ) ;
}
if ( ! V_56 )
* V_43 = F_184 ( V_20 , V_193 ) ;
} else {
* V_43 = - V_204 ;
}
if ( ! V_56 && F_189 ( V_103 , & V_20 -> V_4 ) )
F_183 ( V_20 ) ;
F_84 ( & V_20 -> V_118 ) ;
return V_56 ;
}
static void F_190 ( struct V_56 * V_56 , struct V_167 * V_168 )
{
struct V_76 * V_77 ;
int remove = V_205 ;
bool V_206 = false ;
F_83 ( & V_56 -> V_73 ) ;
for ( V_77 = V_56 -> V_79 ; V_77 ; V_77 = V_77 -> V_78 ) {
int V_207 = 0 ;
if ( V_77 -> V_121 ) {
V_207 = V_77 -> V_121 ( V_77 , V_168 ) ;
F_191 ( V_207 & ~ V_208 ,
L_7 , V_207 , V_77 -> V_121 ) ;
}
if ( V_77 -> V_122 )
V_206 = true ;
remove &= V_207 ;
}
if ( V_206 && ! remove )
F_167 ( V_56 , V_168 ) ;
if ( remove && V_56 -> V_79 ) {
F_91 ( ! F_88 ( V_56 ) ) ;
F_114 ( V_56 , V_138 -> V_20 ) ;
}
F_84 ( & V_56 -> V_73 ) ;
}
static void
F_192 ( struct V_170 * V_171 , struct V_167 * V_168 )
{
struct V_56 * V_56 = V_171 -> V_56 ;
struct V_76 * V_77 ;
F_83 ( & V_56 -> V_73 ) ;
for ( V_77 = V_56 -> V_79 ; V_77 ; V_77 = V_77 -> V_78 ) {
if ( V_77 -> V_122 )
V_77 -> V_122 ( V_77 , V_171 -> V_192 , V_168 ) ;
}
F_84 ( & V_56 -> V_73 ) ;
}
static bool F_193 ( struct V_167 * V_168 )
{
struct V_169 * V_166 ;
struct V_170 * V_171 , * V_172 ;
bool V_188 ;
V_166 = V_138 -> V_166 ;
if ( ! V_166 )
return false ;
V_171 = V_166 -> V_174 ;
if ( ! V_171 )
return false ;
F_194 ( V_168 , V_171 -> V_187 ) ;
for (; ; ) {
F_192 ( V_171 , V_168 ) ;
V_188 = V_171 -> V_188 ;
F_55 ( V_171 -> V_56 ) ;
V_172 = V_171 ;
V_171 = V_171 -> V_78 ;
F_57 ( V_172 ) ;
V_166 -> V_178 -- ;
if ( ! V_188 )
break;
F_78 ( ! V_171 ) ;
}
V_166 -> V_174 = V_171 ;
return true ;
}
static void F_195 ( struct V_167 * V_168 )
{
struct V_56 * V_56 ;
unsigned long V_193 ;
int V_209 ( V_43 ) ;
V_193 = F_155 ( V_168 ) ;
if ( V_193 == F_166 () ) {
if ( F_193 ( V_168 ) )
return;
F_161 ( L_8 ,
V_138 -> V_181 , V_138 -> V_191 ) ;
}
V_56 = F_188 ( V_193 , & V_43 ) ;
if ( ! V_56 ) {
if ( V_43 > 0 ) {
F_196 ( V_210 , V_138 , 0 ) ;
} else {
F_194 ( V_168 , V_193 ) ;
}
return;
}
F_194 ( V_168 , V_193 ) ;
F_197 () ;
if ( F_40 ( ! F_76 ( V_95 , & V_56 -> V_4 ) ) )
goto V_96;
F_190 ( V_56 , V_168 ) ;
if ( F_181 ( V_56 , V_168 ) )
goto V_96;
if ( ! F_170 ( V_56 , V_168 , V_193 ) )
return;
V_96:
F_55 ( V_56 ) ;
}
static void F_198 ( struct V_169 * V_166 , struct V_167 * V_168 )
{
struct V_56 * V_56 ;
V_56 = V_166 -> V_173 ;
if ( V_166 -> V_194 == V_211 )
F_199 ( & V_56 -> V_92 , V_168 ) ;
else if ( V_166 -> V_194 == V_199 )
F_200 ( & V_56 -> V_92 , V_168 ) ;
else
F_173 ( 1 ) ;
F_55 ( V_56 ) ;
V_166 -> V_173 = NULL ;
V_166 -> V_194 = V_212 ;
F_151 ( V_138 ) ;
F_175 ( & V_138 -> V_196 -> V_197 ) ;
F_201 () ;
F_177 ( & V_138 -> V_196 -> V_197 ) ;
}
void F_202 ( struct V_167 * V_168 )
{
struct V_169 * V_166 ;
F_203 ( V_200 ) ;
V_166 = V_138 -> V_166 ;
if ( V_166 && V_166 -> V_173 )
F_198 ( V_166 , V_168 ) ;
else
F_195 ( V_168 ) ;
}
int F_204 ( struct V_167 * V_168 )
{
if ( ! V_138 -> V_20 )
return 0 ;
if ( ! F_76 ( V_102 , & V_138 -> V_20 -> V_4 ) &&
( ! V_138 -> V_166 || ! V_138 -> V_166 -> V_174 ) )
return 0 ;
F_205 ( V_200 ) ;
return 1 ;
}
int F_206 ( struct V_167 * V_168 )
{
struct V_169 * V_166 = V_138 -> V_166 ;
if ( ! V_138 -> V_20 || ! V_166 || ! V_166 -> V_173 )
return 0 ;
V_166 -> V_194 = V_211 ;
F_205 ( V_200 ) ;
return 1 ;
}
static int T_6 F_207 ( void )
{
int V_213 ;
for ( V_213 = 0 ; V_213 < V_214 ; V_213 ++ )
F_208 ( & V_215 [ V_213 ] ) ;
if ( F_209 ( & V_117 ) )
return - V_51 ;
return F_210 ( & V_216 ) ;
}
