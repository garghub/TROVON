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
static int F_33 ( struct V_19 * V_20 , unsigned long V_15 ,
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
static int
F_68 ( struct V_81 * V_82 , struct V_83 * V_84 , char * V_34 ,
unsigned long V_85 , T_2 V_11 )
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
struct V_81 * V_82 ;
unsigned long V_85 ;
int V_90 ;
V_85 = V_27 - ( V_56 -> V_11 & ~ V_39 ) ;
V_82 = V_56 -> V_59 -> V_91 ;
if ( V_56 -> V_11 + V_92 > V_56 -> V_59 -> V_93 )
V_90 = V_56 -> V_59 -> V_93 - V_56 -> V_11 ;
else
V_90 = V_92 ;
if ( V_85 < V_90 ) {
int V_24 = F_68 ( V_82 , V_84 , V_56 -> V_94 . V_34 + V_85 ,
V_90 - V_85 , V_56 -> V_11 + V_85 ) ;
if ( V_24 )
return V_24 ;
V_90 = V_85 ;
}
return F_68 ( V_82 , V_84 , V_56 -> V_94 . V_34 , V_90 , V_56 -> V_11 ) ;
}
static int F_73 ( struct V_56 * V_56 , struct V_83 * V_83 ,
struct V_19 * V_20 , unsigned long V_15 )
{
int V_48 = 0 ;
if ( F_74 ( V_95 , & V_56 -> V_4 ) )
return V_48 ;
F_65 ( & V_56 -> V_74 ) ;
if ( F_74 ( V_95 , & V_56 -> V_4 ) )
goto V_96;
V_48 = F_72 ( V_56 , V_83 ) ;
if ( V_48 )
goto V_96;
V_48 = - V_97 ;
if ( F_27 ( ( T_5 * ) V_56 -> V_94 . V_34 ) )
goto V_96;
V_48 = F_75 ( & V_56 -> V_94 , V_20 , V_15 ) ;
if ( V_48 )
goto V_96;
F_76 ( ( V_56 -> V_11 & ~ V_39 ) +
V_44 > V_27 ) ;
F_77 () ;
F_78 ( V_95 , & V_56 -> V_4 ) ;
V_96:
F_66 ( & V_56 -> V_74 ) ;
return V_48 ;
}
static inline bool F_79 ( struct V_76 * V_77 ,
enum V_98 V_99 , struct V_19 * V_20 )
{
return ! V_77 -> V_100 || V_77 -> V_100 ( V_77 , V_99 , V_20 ) ;
}
static bool F_80 ( struct V_56 * V_56 ,
enum V_98 V_99 , struct V_19 * V_20 )
{
struct V_76 * V_77 ;
bool V_48 = false ;
F_81 ( & V_56 -> V_74 ) ;
for ( V_77 = V_56 -> V_79 ; V_77 ; V_77 = V_77 -> V_78 ) {
V_48 = F_79 ( V_77 , V_99 , V_20 ) ;
if ( V_48 )
break;
}
F_82 ( & V_56 -> V_74 ) ;
return V_48 ;
}
static int
F_83 ( struct V_56 * V_56 , struct V_19 * V_20 ,
struct V_1 * V_2 , unsigned long V_15 )
{
bool V_101 ;
int V_48 ;
V_48 = F_73 ( V_56 , V_2 -> V_9 , V_20 , V_15 ) ;
if ( V_48 )
return V_48 ;
V_101 = ! F_74 ( V_102 , & V_20 -> V_4 ) ;
if ( V_101 )
F_78 ( V_102 , & V_20 -> V_4 ) ;
V_48 = F_41 ( & V_56 -> V_94 , V_20 , V_15 ) ;
if ( ! V_48 )
F_84 ( V_103 , & V_20 -> V_4 ) ;
else if ( V_101 )
F_84 ( V_102 , & V_20 -> V_4 ) ;
return V_48 ;
}
static int
F_85 ( struct V_56 * V_56 , struct V_19 * V_20 , unsigned long V_15 )
{
F_78 ( V_103 , & V_20 -> V_4 ) ;
return F_42 ( & V_56 -> V_94 , V_20 , V_15 ) ;
}
static inline bool F_86 ( struct V_56 * V_56 )
{
return ! F_87 ( & V_56 -> V_61 ) ;
}
static void F_88 ( struct V_56 * V_56 )
{
if ( F_89 ( ! F_86 ( V_56 ) ) )
return;
F_48 ( & V_68 ) ;
F_90 ( & V_56 -> V_61 , & V_63 ) ;
F_49 ( & V_68 ) ;
F_91 ( & V_56 -> V_61 ) ;
F_63 ( V_56 -> V_59 ) ;
F_55 ( V_56 ) ;
}
static inline struct V_104 * F_92 ( struct V_104 * V_105 )
{
struct V_104 * V_78 = V_105 -> V_78 ;
F_57 ( V_105 ) ;
return V_78 ;
}
static struct V_104 *
F_93 ( struct V_81 * V_82 , T_2 V_11 , bool V_3 )
{
unsigned long V_106 = V_11 >> V_14 ;
struct V_1 * V_2 ;
struct V_104 * V_107 = NULL ;
struct V_104 * V_108 = NULL ;
struct V_104 * V_105 ;
int V_109 = 0 ;
V_110:
F_94 ( & V_82 -> V_111 ) ;
F_95 (vma, &mapping->i_mmap, pgoff, pgoff) {
if ( ! F_1 ( V_2 , V_3 ) )
continue;
if ( ! V_108 && ! V_109 ) {
V_108 = F_96 ( sizeof( struct V_104 ) ,
V_112 | V_113 | V_114 ) ;
if ( V_108 )
V_108 -> V_78 = NULL ;
}
if ( ! V_108 ) {
V_109 ++ ;
continue;
}
if ( ! F_97 ( & V_2 -> V_21 -> V_115 ) )
continue;
V_105 = V_108 ;
V_108 = V_108 -> V_78 ;
V_105 -> V_78 = V_107 ;
V_107 = V_105 ;
V_105 -> V_20 = V_2 -> V_21 ;
V_105 -> V_15 = F_2 ( V_2 , V_11 ) ;
}
F_98 ( & V_82 -> V_111 ) ;
if ( ! V_109 )
goto V_96;
V_108 = V_107 ;
while ( V_107 ) {
F_99 ( V_107 -> V_20 ) ;
V_107 = V_107 -> V_78 ;
}
do {
V_105 = F_96 ( sizeof( struct V_104 ) , V_72 ) ;
if ( ! V_105 ) {
V_107 = F_100 ( - V_51 ) ;
goto V_96;
}
V_105 -> V_78 = V_108 ;
V_108 = V_105 ;
} while ( -- V_109 );
goto V_110;
V_96:
while ( V_108 )
V_108 = F_92 ( V_108 ) ;
return V_107 ;
}
static int
F_101 ( struct V_56 * V_56 , struct V_76 * V_116 )
{
bool V_3 = ! ! V_116 ;
struct V_104 * V_105 ;
int V_24 = 0 ;
F_102 ( & V_117 ) ;
V_105 = F_93 ( V_56 -> V_59 -> V_91 ,
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
V_2 = F_103 ( V_20 , V_105 -> V_15 ) ;
if ( ! V_2 || ! F_1 ( V_2 , V_3 ) ||
F_104 ( V_2 -> V_9 ) != V_56 -> V_59 )
goto V_29;
if ( V_2 -> V_12 > V_105 -> V_15 ||
F_3 ( V_2 , V_105 -> V_15 ) != V_56 -> V_11 )
goto V_29;
if ( V_3 ) {
if ( F_79 ( V_116 ,
V_119 , V_20 ) )
V_24 = F_83 ( V_56 , V_20 , V_2 , V_105 -> V_15 ) ;
} else if ( F_74 ( V_102 , & V_20 -> V_4 ) ) {
if ( ! F_80 ( V_56 ,
V_120 , V_20 ) )
V_24 |= F_85 ( V_56 , V_20 , V_105 -> V_15 ) ;
}
V_29:
F_66 ( & V_20 -> V_118 ) ;
free:
F_99 ( V_20 ) ;
V_105 = F_92 ( V_105 ) ;
}
V_96:
F_105 ( & V_117 ) ;
return V_24 ;
}
static int F_106 ( struct V_56 * V_56 , struct V_76 * V_77 )
{
F_64 ( V_56 , V_77 ) ;
return F_101 ( V_56 , V_77 ) ;
}
static void F_107 ( struct V_56 * V_56 , struct V_76 * V_77 )
{
int V_24 ;
if ( ! F_67 ( V_56 , V_77 ) )
return;
V_24 = F_101 ( V_56 , NULL ) ;
if ( ! V_56 -> V_79 && ! V_24 )
F_88 ( V_56 ) ;
}
int F_108 ( struct V_59 * V_59 , T_2 V_11 , struct V_76 * V_77 )
{
struct V_56 * V_56 ;
int V_48 ;
if ( ! V_77 -> V_121 && ! V_77 -> V_122 )
return - V_123 ;
if ( V_11 > F_109 ( V_59 ) )
return - V_123 ;
V_49:
V_56 = F_58 ( V_59 , V_11 ) ;
if ( ! V_56 )
return - V_51 ;
F_65 ( & V_56 -> V_73 ) ;
V_48 = - V_28 ;
if ( F_110 ( F_86 ( V_56 ) ) ) {
V_48 = F_106 ( V_56 , V_77 ) ;
if ( V_48 )
F_107 ( V_56 , V_77 ) ;
}
F_66 ( & V_56 -> V_73 ) ;
F_55 ( V_56 ) ;
if ( F_40 ( V_48 == - V_28 ) )
goto V_49;
return V_48 ;
}
int F_111 ( struct V_59 * V_59 , T_2 V_11 ,
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
V_48 = F_101 ( V_56 , V_124 ? V_77 : NULL ) ;
F_66 ( & V_56 -> V_73 ) ;
F_55 ( V_56 ) ;
return V_48 ;
}
void F_112 ( struct V_59 * V_59 , T_2 V_11 , struct V_76 * V_77 )
{
struct V_56 * V_56 ;
V_56 = F_47 ( V_59 , V_11 ) ;
if ( ! V_56 )
return;
F_65 ( & V_56 -> V_73 ) ;
F_107 ( V_56 , V_77 ) ;
F_66 ( & V_56 -> V_73 ) ;
F_55 ( V_56 ) ;
}
static int F_113 ( struct V_56 * V_56 , struct V_19 * V_20 )
{
struct V_1 * V_2 ;
int V_24 = 0 ;
F_81 ( & V_20 -> V_118 ) ;
for ( V_2 = V_20 -> V_126 ; V_2 ; V_2 = V_2 -> V_127 ) {
unsigned long V_15 ;
T_2 V_11 ;
if ( ! F_1 ( V_2 , false ) ||
F_104 ( V_2 -> V_9 ) != V_56 -> V_59 )
continue;
V_11 = ( T_2 ) V_2 -> V_13 << V_14 ;
if ( V_56 -> V_11 < V_11 ||
V_56 -> V_11 >= V_11 + V_2 -> V_128 - V_2 -> V_12 )
continue;
V_15 = F_2 ( V_2 , V_56 -> V_11 ) ;
V_24 |= F_85 ( V_56 , V_20 , V_15 ) ;
}
F_82 ( & V_20 -> V_118 ) ;
return V_24 ;
}
static struct V_61 *
F_114 ( struct V_59 * V_59 , T_2 V_129 , T_2 V_130 )
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
static void F_115 ( struct V_59 * V_59 ,
struct V_1 * V_2 ,
unsigned long V_131 , unsigned long V_132 ,
struct V_133 * V_134 )
{
T_2 V_129 , V_130 ;
struct V_61 * V_62 , * V_135 ;
struct V_56 * V_60 ;
F_116 ( V_134 ) ;
V_129 = F_3 ( V_2 , V_131 ) ;
V_130 = V_129 + ( V_132 - V_131 ) - 1 ;
F_48 ( & V_68 ) ;
V_62 = F_114 ( V_59 , V_129 , V_130 ) ;
if ( V_62 ) {
for ( V_135 = V_62 ; V_135 ; V_135 = F_117 ( V_135 ) ) {
V_60 = F_45 ( V_135 , struct V_56 , V_61 ) ;
if ( V_60 -> V_59 != V_59 || V_60 -> V_11 < V_129 )
break;
F_118 ( & V_60 -> V_136 , V_134 ) ;
F_46 ( & V_60 -> V_65 ) ;
}
for ( V_135 = V_62 ; ( V_135 = F_119 ( V_135 ) ) ; ) {
V_60 = F_45 ( V_135 , struct V_56 , V_61 ) ;
if ( V_60 -> V_59 != V_59 || V_60 -> V_11 > V_130 )
break;
F_118 ( & V_60 -> V_136 , V_134 ) ;
F_46 ( & V_60 -> V_65 ) ;
}
}
F_49 ( & V_68 ) ;
}
int F_120 ( struct V_1 * V_2 )
{
struct V_133 V_137 ;
struct V_56 * V_56 , * V_60 ;
struct V_59 * V_59 ;
if ( F_121 () || ! F_1 ( V_2 , true ) )
return 0 ;
V_59 = F_104 ( V_2 -> V_9 ) ;
if ( ! V_59 )
return 0 ;
F_94 ( F_122 ( V_59 ) ) ;
F_115 ( V_59 , V_2 , V_2 -> V_12 , V_2 -> V_128 , & V_137 ) ;
F_123 (uprobe, u, &tmp_list, pending_list) {
if ( ! F_124 ( V_138 ) &&
F_80 ( V_56 , V_139 , V_2 -> V_21 ) ) {
unsigned long V_15 = F_2 ( V_2 , V_56 -> V_11 ) ;
F_83 ( V_56 , V_2 -> V_21 , V_2 , V_15 ) ;
}
F_55 ( V_56 ) ;
}
F_98 ( F_122 ( V_59 ) ) ;
return 0 ;
}
static bool
F_125 ( struct V_1 * V_2 , unsigned long V_131 , unsigned long V_132 )
{
T_2 V_129 , V_130 ;
struct V_59 * V_59 ;
struct V_61 * V_62 ;
V_59 = F_104 ( V_2 -> V_9 ) ;
V_129 = F_3 ( V_2 , V_131 ) ;
V_130 = V_129 + ( V_132 - V_131 ) - 1 ;
F_48 ( & V_68 ) ;
V_62 = F_114 ( V_59 , V_129 , V_130 ) ;
F_49 ( & V_68 ) ;
return ! ! V_62 ;
}
void F_126 ( struct V_1 * V_2 , unsigned long V_131 , unsigned long V_132 )
{
if ( F_121 () || ! F_1 ( V_2 , false ) )
return;
if ( ! F_127 ( & V_2 -> V_21 -> V_115 ) )
return;
if ( ! F_74 ( V_102 , & V_2 -> V_21 -> V_4 ) ||
F_74 ( V_103 , & V_2 -> V_21 -> V_4 ) )
return;
if ( F_125 ( V_2 , V_131 , V_132 ) )
F_78 ( V_103 , & V_2 -> V_21 -> V_4 ) ;
}
static int F_128 ( struct V_140 * V_141 )
{
struct V_19 * V_20 = V_138 -> V_20 ;
int V_48 = - V_142 ;
F_65 ( & V_20 -> V_118 ) ;
if ( V_20 -> V_143 . V_140 )
goto V_144;
V_48 = - V_51 ;
V_141 -> V_15 = F_129 ( NULL , V_145 - V_27 , V_27 , 0 , 0 ) ;
if ( V_141 -> V_15 & ~ V_39 ) {
V_48 = V_141 -> V_15 ;
goto V_144;
}
V_48 = F_130 ( V_20 , V_141 -> V_15 , V_27 ,
V_146 | V_6 | V_147 | V_148 , & V_141 -> V_17 ) ;
if ( V_48 )
goto V_144;
F_77 () ;
V_20 -> V_143 . V_140 = V_141 ;
V_48 = 0 ;
V_144:
F_66 ( & V_20 -> V_118 ) ;
return V_48 ;
}
static struct V_140 * F_131 ( void )
{
struct V_19 * V_20 = V_138 -> V_20 ;
struct V_140 * V_141 ;
T_5 V_34 = V_35 ;
V_141 = V_20 -> V_143 . V_140 ;
if ( V_141 )
goto V_48;
V_141 = F_59 ( sizeof( * V_141 ) , V_72 ) ;
if ( F_40 ( ! V_141 ) )
goto V_96;
V_141 -> V_149 = F_59 ( F_132 ( V_150 ) * sizeof( long ) , V_72 ) ;
if ( ! V_141 -> V_149 )
goto V_151;
V_141 -> V_17 = F_133 ( V_152 ) ;
if ( ! V_141 -> V_17 )
goto V_153;
F_78 ( 0 , V_141 -> V_149 ) ;
F_31 ( V_141 -> V_17 , 0 , & V_34 , V_44 ) ;
F_53 ( & V_141 -> V_154 , 1 ) ;
F_134 ( & V_141 -> V_155 ) ;
if ( ! F_128 ( V_141 ) )
return V_141 ;
F_135 ( V_141 -> V_17 ) ;
V_153:
F_57 ( V_141 -> V_149 ) ;
V_151:
F_57 ( V_141 ) ;
V_96:
V_141 = V_20 -> V_143 . V_140 ;
V_48:
F_136 () ;
return V_141 ;
}
void F_137 ( struct V_19 * V_20 )
{
struct V_140 * V_141 = V_20 -> V_143 . V_140 ;
if ( ! V_141 )
return;
F_23 ( V_141 -> V_17 ) ;
F_57 ( V_141 -> V_149 ) ;
F_57 ( V_141 ) ;
}
void F_138 ( void )
{
F_139 ( & V_117 ) ;
}
void F_140 ( void )
{
F_141 ( & V_117 ) ;
}
void F_142 ( struct V_19 * V_156 , struct V_19 * V_157 )
{
V_157 -> V_143 . V_140 = NULL ;
if ( F_74 ( V_102 , & V_156 -> V_4 ) ) {
F_78 ( V_102 , & V_157 -> V_4 ) ;
F_78 ( V_103 , & V_157 -> V_4 ) ;
}
}
static unsigned long F_143 ( struct V_140 * V_141 )
{
unsigned long V_158 ;
int V_159 ;
do {
V_159 = F_144 ( V_141 -> V_149 , V_150 ) ;
if ( V_159 < V_150 ) {
if ( ! F_145 ( V_159 , V_141 -> V_149 ) )
break;
V_159 = V_150 ;
continue;
}
F_146 ( V_141 -> V_155 , ( F_127 ( & V_141 -> V_154 ) < V_150 ) ) ;
} while ( V_159 >= V_150 );
V_158 = V_141 -> V_15 + ( V_159 * V_160 ) ;
F_46 ( & V_141 -> V_154 ) ;
return V_158 ;
}
static unsigned long F_147 ( struct V_56 * V_56 )
{
struct V_140 * V_141 ;
unsigned long V_161 ;
V_141 = F_131 () ;
if ( ! V_141 )
return 0 ;
V_161 = F_143 ( V_141 ) ;
if ( F_40 ( ! V_161 ) )
return 0 ;
F_31 ( V_141 -> V_17 , V_161 , V_56 -> V_94 . V_34 , V_92 ) ;
F_148 ( V_141 -> V_17 ) ;
return V_161 ;
}
static void F_149 ( struct V_162 * V_163 )
{
struct V_140 * V_141 ;
unsigned long V_164 ;
unsigned long V_158 ;
if ( ! V_163 -> V_20 || ! V_163 -> V_20 -> V_143 . V_140 || ! V_163 -> V_165 )
return;
V_158 = V_163 -> V_165 -> V_161 ;
if ( F_40 ( ! V_158 ) )
return;
V_141 = V_163 -> V_20 -> V_143 . V_140 ;
V_164 = V_141 -> V_15 + V_27 ;
if ( V_141 -> V_15 <= V_158 && V_158 < V_164 ) {
unsigned long V_11 ;
int V_159 ;
V_11 = V_158 - V_141 -> V_15 ;
V_159 = V_11 / V_160 ;
if ( V_159 >= V_150 )
return;
F_84 ( V_159 , V_141 -> V_149 ) ;
F_150 ( & V_141 -> V_154 ) ;
if ( F_151 ( & V_141 -> V_155 ) )
F_152 ( & V_141 -> V_155 ) ;
V_163 -> V_165 -> V_161 = 0 ;
}
}
unsigned long __weak F_153 ( struct V_166 * V_167 )
{
return F_154 ( V_167 ) - V_44 ;
}
void F_155 ( struct V_162 * V_135 )
{
struct V_168 * V_165 = V_135 -> V_165 ;
struct V_169 * V_170 , * V_171 ;
if ( ! V_165 )
return;
if ( V_165 -> V_172 )
F_55 ( V_165 -> V_172 ) ;
V_170 = V_165 -> V_173 ;
while ( V_170 ) {
V_171 = V_170 ;
V_170 = V_170 -> V_78 ;
F_55 ( V_171 -> V_56 ) ;
F_57 ( V_171 ) ;
}
F_149 ( V_135 ) ;
F_57 ( V_165 ) ;
V_135 -> V_165 = NULL ;
}
void F_156 ( struct V_162 * V_135 )
{
V_135 -> V_165 = NULL ;
}
static struct V_168 * F_157 ( void )
{
if ( ! V_138 -> V_165 )
V_138 -> V_165 = F_59 ( sizeof( struct V_168 ) , V_72 ) ;
return V_138 -> V_165 ;
}
static unsigned long F_158 ( void )
{
struct V_140 * V_141 ;
unsigned long V_174 = - 1 ;
V_141 = V_138 -> V_20 -> V_143 . V_140 ;
F_136 () ;
if ( V_141 )
V_174 = V_141 -> V_15 ;
return V_174 ;
}
static void F_159 ( struct V_56 * V_56 , struct V_166 * V_167 )
{
struct V_169 * V_170 ;
struct V_168 * V_165 ;
unsigned long V_175 , V_174 ;
bool V_176 = false ;
if ( ! F_131 () )
return;
V_165 = F_157 () ;
if ( ! V_165 )
return;
if ( V_165 -> V_177 >= V_178 ) {
F_160 ( V_179 L_1
L_2 ,
V_138 -> V_180 , V_138 -> V_181 ) ;
return;
}
V_170 = F_59 ( sizeof( struct V_169 ) , V_72 ) ;
if ( ! V_170 )
goto V_144;
V_174 = F_158 () ;
V_175 = F_161 ( V_174 , V_167 ) ;
if ( V_175 == - 1 )
goto V_144;
if ( V_175 == V_174 ) {
if ( ! V_165 -> V_173 ) {
F_162 ( L_3 ,
V_138 -> V_180 , V_138 -> V_181 ) ;
goto V_144;
}
V_176 = true ;
V_175 = V_165 -> V_173 -> V_175 ;
}
F_46 ( & V_56 -> V_65 ) ;
V_170 -> V_56 = V_56 ;
V_170 -> V_182 = F_154 ( V_167 ) ;
V_170 -> V_175 = V_175 ;
V_170 -> V_176 = V_176 ;
V_165 -> V_177 ++ ;
V_170 -> V_78 = V_165 -> V_173 ;
V_165 -> V_173 = V_170 ;
return;
V_144:
F_57 ( V_170 ) ;
}
static int
F_163 ( struct V_56 * V_56 , struct V_166 * V_167 , unsigned long V_183 )
{
struct V_168 * V_165 ;
unsigned long V_161 ;
int V_24 ;
V_165 = F_157 () ;
if ( ! V_165 )
return - V_51 ;
V_161 = F_147 ( V_56 ) ;
if ( ! V_161 )
return - V_51 ;
V_165 -> V_161 = V_161 ;
V_165 -> V_15 = V_183 ;
V_24 = F_164 ( & V_56 -> V_94 , V_167 ) ;
if ( F_40 ( V_24 ) ) {
F_149 ( V_138 ) ;
return V_24 ;
}
V_165 -> V_172 = V_56 ;
V_165 -> V_184 = V_185 ;
return 0 ;
}
bool F_165 ( void )
{
struct V_162 * V_135 = V_138 ;
struct V_168 * V_165 = V_135 -> V_165 ;
if ( F_110 ( ! V_165 || ! V_165 -> V_172 ) )
return false ;
F_166 ( V_165 -> V_184 != V_185 ) ;
if ( F_167 ( V_135 ) ) {
F_168 ( & V_135 -> V_186 -> V_187 ) ;
F_169 ( V_135 , V_188 ) ;
F_170 ( & V_135 -> V_186 -> V_187 ) ;
if ( F_171 ( V_135 ) || F_172 ( V_135 ) ) {
V_165 -> V_184 = V_189 ;
F_173 ( V_135 , V_190 ) ;
F_173 ( V_135 , V_191 ) ;
}
}
return true ;
}
static bool F_174 ( struct V_56 * V_56 , struct V_166 * V_167 )
{
if ( F_74 ( V_75 , & V_56 -> V_4 ) ) {
if ( F_175 ( & V_56 -> V_94 , V_167 ) )
return true ;
F_84 ( V_75 , & V_56 -> V_4 ) ;
}
return false ;
}
static void F_176 ( struct V_19 * V_20 )
{
struct V_1 * V_2 ;
for ( V_2 = V_20 -> V_126 ; V_2 ; V_2 = V_2 -> V_127 ) {
if ( ! F_1 ( V_2 , false ) )
continue;
if ( F_125 ( V_2 , V_2 -> V_12 , V_2 -> V_128 ) )
return;
}
F_84 ( V_102 , & V_20 -> V_4 ) ;
}
static int F_177 ( struct V_19 * V_20 , unsigned long V_15 )
{
struct V_17 * V_17 ;
T_5 V_45 ;
int V_192 ;
F_178 () ;
V_192 = F_179 ( & V_45 , ( void V_193 * ) V_15 ,
sizeof( V_45 ) ) ;
F_180 () ;
if ( F_110 ( V_192 == 0 ) )
goto V_96;
V_192 = F_34 ( NULL , V_20 , V_15 , 1 , 0 , 1 , & V_17 , NULL ) ;
if ( V_192 < 0 )
return V_192 ;
F_28 ( V_17 , V_15 , & V_45 , V_44 ) ;
F_23 ( V_17 ) ;
V_96:
return F_27 ( & V_45 ) ;
}
static struct V_56 * F_181 ( unsigned long V_183 , int * V_43 )
{
struct V_19 * V_20 = V_138 -> V_20 ;
struct V_56 * V_56 = NULL ;
struct V_1 * V_2 ;
F_81 ( & V_20 -> V_118 ) ;
V_2 = F_103 ( V_20 , V_183 ) ;
if ( V_2 && V_2 -> V_12 <= V_183 ) {
if ( F_1 ( V_2 , false ) ) {
struct V_59 * V_59 = F_104 ( V_2 -> V_9 ) ;
T_2 V_11 = F_3 ( V_2 , V_183 ) ;
V_56 = F_47 ( V_59 , V_11 ) ;
}
if ( ! V_56 )
* V_43 = F_177 ( V_20 , V_183 ) ;
} else {
* V_43 = - V_194 ;
}
if ( ! V_56 && F_182 ( V_103 , & V_20 -> V_4 ) )
F_176 ( V_20 ) ;
F_82 ( & V_20 -> V_118 ) ;
return V_56 ;
}
static void F_183 ( struct V_56 * V_56 , struct V_166 * V_167 )
{
struct V_76 * V_77 ;
int remove = V_195 ;
bool V_196 = false ;
F_81 ( & V_56 -> V_73 ) ;
for ( V_77 = V_56 -> V_79 ; V_77 ; V_77 = V_77 -> V_78 ) {
int V_197 = 0 ;
if ( V_77 -> V_121 ) {
V_197 = V_77 -> V_121 ( V_77 , V_167 ) ;
F_184 ( V_197 & ~ V_198 ,
L_4 , V_197 , V_77 -> V_121 ) ;
}
if ( V_77 -> V_122 )
V_196 = true ;
remove &= V_197 ;
}
if ( V_196 && ! remove )
F_159 ( V_56 , V_167 ) ;
if ( remove && V_56 -> V_79 ) {
F_89 ( ! F_86 ( V_56 ) ) ;
F_113 ( V_56 , V_138 -> V_20 ) ;
}
F_82 ( & V_56 -> V_73 ) ;
}
static void
F_185 ( struct V_169 * V_170 , struct V_166 * V_167 )
{
struct V_56 * V_56 = V_170 -> V_56 ;
struct V_76 * V_77 ;
F_81 ( & V_56 -> V_73 ) ;
for ( V_77 = V_56 -> V_79 ; V_77 ; V_77 = V_77 -> V_78 ) {
if ( V_77 -> V_122 )
V_77 -> V_122 ( V_77 , V_170 -> V_182 , V_167 ) ;
}
F_82 ( & V_56 -> V_73 ) ;
}
static bool F_186 ( struct V_166 * V_167 )
{
struct V_168 * V_165 ;
struct V_169 * V_170 , * V_171 ;
bool V_176 ;
V_165 = V_138 -> V_165 ;
if ( ! V_165 )
return false ;
V_170 = V_165 -> V_173 ;
if ( ! V_170 )
return false ;
F_187 ( V_167 , V_170 -> V_175 ) ;
for (; ; ) {
F_185 ( V_170 , V_167 ) ;
V_176 = V_170 -> V_176 ;
F_55 ( V_170 -> V_56 ) ;
V_171 = V_170 ;
V_170 = V_170 -> V_78 ;
F_57 ( V_171 ) ;
if ( ! V_176 )
break;
V_165 -> V_177 -- ;
F_76 ( ! V_170 ) ;
}
V_165 -> V_173 = V_170 ;
return true ;
}
static void F_188 ( struct V_166 * V_167 )
{
struct V_56 * V_56 ;
unsigned long V_183 ;
int V_199 ( V_43 ) ;
V_183 = F_153 ( V_167 ) ;
if ( V_183 == F_158 () ) {
if ( F_186 ( V_167 ) )
return;
F_162 ( L_5 ,
V_138 -> V_180 , V_138 -> V_181 ) ;
}
V_56 = F_181 ( V_183 , & V_43 ) ;
if ( ! V_56 ) {
if ( V_43 > 0 ) {
F_189 ( V_200 , V_138 , 0 ) ;
} else {
F_187 ( V_167 , V_183 ) ;
}
return;
}
F_187 ( V_167 , V_183 ) ;
F_190 () ;
if ( F_40 ( ! F_74 ( V_95 , & V_56 -> V_4 ) ) )
goto V_96;
F_183 ( V_56 , V_167 ) ;
if ( F_174 ( V_56 , V_167 ) )
goto V_96;
if ( ! F_163 ( V_56 , V_167 , V_183 ) )
return;
V_96:
F_55 ( V_56 ) ;
}
static void F_191 ( struct V_168 * V_165 , struct V_166 * V_167 )
{
struct V_56 * V_56 ;
V_56 = V_165 -> V_172 ;
if ( V_165 -> V_184 == V_201 )
F_192 ( & V_56 -> V_94 , V_167 ) ;
else if ( V_165 -> V_184 == V_189 )
F_193 ( & V_56 -> V_94 , V_167 ) ;
else
F_166 ( 1 ) ;
F_55 ( V_56 ) ;
V_165 -> V_172 = NULL ;
V_165 -> V_184 = V_202 ;
F_149 ( V_138 ) ;
F_168 ( & V_138 -> V_186 -> V_187 ) ;
F_194 () ;
F_170 ( & V_138 -> V_186 -> V_187 ) ;
}
void F_195 ( struct V_166 * V_167 )
{
struct V_168 * V_165 ;
F_196 ( V_190 ) ;
V_165 = V_138 -> V_165 ;
if ( V_165 && V_165 -> V_172 )
F_191 ( V_165 , V_167 ) ;
else
F_188 ( V_167 ) ;
}
int F_197 ( struct V_166 * V_167 )
{
if ( ! V_138 -> V_20 )
return 0 ;
if ( ! F_74 ( V_102 , & V_138 -> V_20 -> V_4 ) &&
( ! V_138 -> V_165 || ! V_138 -> V_165 -> V_173 ) )
return 0 ;
F_198 ( V_190 ) ;
return 1 ;
}
int F_199 ( struct V_166 * V_167 )
{
struct V_168 * V_165 = V_138 -> V_165 ;
if ( ! V_138 -> V_20 || ! V_165 || ! V_165 -> V_172 )
return 0 ;
V_165 -> V_184 = V_201 ;
F_198 ( V_190 ) ;
return 1 ;
}
static int T_6 F_200 ( void )
{
int V_203 ;
for ( V_203 = 0 ; V_203 < V_204 ; V_203 ++ )
F_201 ( & V_205 [ V_203 ] ) ;
if ( F_202 ( & V_117 ) )
return - V_51 ;
return F_203 ( & V_206 ) ;
}
static void T_7 F_204 ( void )
{
}
