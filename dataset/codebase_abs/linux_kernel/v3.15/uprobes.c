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
return F_33 ( V_20 , V_15 , * ( T_5 * ) & V_55 -> V_34 ) ;
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
void * V_34 = & V_56 -> V_92 . V_34 ;
int V_93 = sizeof( V_56 -> V_92 . V_34 ) ;
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
if ( F_76 ( V_94 , & V_56 -> V_4 ) )
return V_48 ;
F_65 ( & V_56 -> V_74 ) ;
if ( F_76 ( V_94 , & V_56 -> V_4 ) )
goto V_95;
V_48 = F_72 ( V_56 , V_83 ) ;
if ( V_48 )
goto V_95;
V_48 = - V_96 ;
if ( F_27 ( ( T_5 * ) & V_56 -> V_92 . V_34 ) )
goto V_95;
V_48 = F_77 ( & V_56 -> V_92 , V_20 , V_15 ) ;
if ( V_48 )
goto V_95;
F_78 ( ( V_56 -> V_11 & ~ V_39 ) +
V_44 > V_27 ) ;
F_79 () ;
F_80 ( V_94 , & V_56 -> V_4 ) ;
V_95:
F_66 ( & V_56 -> V_74 ) ;
return V_48 ;
}
static inline bool F_81 ( struct V_76 * V_77 ,
enum V_97 V_98 , struct V_19 * V_20 )
{
return ! V_77 -> V_99 || V_77 -> V_99 ( V_77 , V_98 , V_20 ) ;
}
static bool F_82 ( struct V_56 * V_56 ,
enum V_97 V_98 , struct V_19 * V_20 )
{
struct V_76 * V_77 ;
bool V_48 = false ;
F_83 ( & V_56 -> V_74 ) ;
for ( V_77 = V_56 -> V_79 ; V_77 ; V_77 = V_77 -> V_78 ) {
V_48 = F_81 ( V_77 , V_98 , V_20 ) ;
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
bool V_100 ;
int V_48 ;
V_48 = F_75 ( V_56 , V_2 -> V_9 , V_20 , V_15 ) ;
if ( V_48 )
return V_48 ;
V_100 = ! F_76 ( V_101 , & V_20 -> V_4 ) ;
if ( V_100 )
F_80 ( V_101 , & V_20 -> V_4 ) ;
V_48 = F_41 ( & V_56 -> V_92 , V_20 , V_15 ) ;
if ( ! V_48 )
F_86 ( V_102 , & V_20 -> V_4 ) ;
else if ( V_100 )
F_86 ( V_101 , & V_20 -> V_4 ) ;
return V_48 ;
}
static int
F_87 ( struct V_56 * V_56 , struct V_19 * V_20 , unsigned long V_15 )
{
F_80 ( V_102 , & V_20 -> V_4 ) ;
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
static inline struct V_103 * F_94 ( struct V_103 * V_104 )
{
struct V_103 * V_78 = V_104 -> V_78 ;
F_57 ( V_104 ) ;
return V_78 ;
}
static struct V_103 *
F_95 ( struct V_81 * V_82 , T_2 V_11 , bool V_3 )
{
unsigned long V_105 = V_11 >> V_14 ;
struct V_1 * V_2 ;
struct V_103 * V_106 = NULL ;
struct V_103 * V_107 = NULL ;
struct V_103 * V_104 ;
int V_108 = 0 ;
V_109:
F_96 ( & V_82 -> V_110 ) ;
F_97 (vma, &mapping->i_mmap, pgoff, pgoff) {
if ( ! F_1 ( V_2 , V_3 ) )
continue;
if ( ! V_107 && ! V_108 ) {
V_107 = F_98 ( sizeof( struct V_103 ) ,
V_111 | V_112 | V_113 ) ;
if ( V_107 )
V_107 -> V_78 = NULL ;
}
if ( ! V_107 ) {
V_108 ++ ;
continue;
}
if ( ! F_99 ( & V_2 -> V_21 -> V_114 ) )
continue;
V_104 = V_107 ;
V_107 = V_107 -> V_78 ;
V_104 -> V_78 = V_106 ;
V_106 = V_104 ;
V_104 -> V_20 = V_2 -> V_21 ;
V_104 -> V_15 = F_2 ( V_2 , V_11 ) ;
}
F_100 ( & V_82 -> V_110 ) ;
if ( ! V_108 )
goto V_95;
V_107 = V_106 ;
while ( V_106 ) {
F_101 ( V_106 -> V_20 ) ;
V_106 = V_106 -> V_78 ;
}
do {
V_104 = F_98 ( sizeof( struct V_103 ) , V_72 ) ;
if ( ! V_104 ) {
V_106 = F_102 ( - V_51 ) ;
goto V_95;
}
V_104 -> V_78 = V_107 ;
V_107 = V_104 ;
} while ( -- V_108 );
goto V_109;
V_95:
while ( V_107 )
V_107 = F_94 ( V_107 ) ;
return V_106 ;
}
static int
F_103 ( struct V_56 * V_56 , struct V_76 * V_115 )
{
bool V_3 = ! ! V_115 ;
struct V_103 * V_104 ;
int V_24 = 0 ;
F_104 ( & V_116 ) ;
V_104 = F_95 ( V_56 -> V_59 -> V_90 ,
V_56 -> V_11 , V_3 ) ;
if ( F_70 ( V_104 ) ) {
V_24 = F_71 ( V_104 ) ;
goto V_95;
}
while ( V_104 ) {
struct V_19 * V_20 = V_104 -> V_20 ;
struct V_1 * V_2 ;
if ( V_24 && V_3 )
goto free;
F_65 ( & V_20 -> V_117 ) ;
V_2 = F_105 ( V_20 , V_104 -> V_15 ) ;
if ( ! V_2 || ! F_1 ( V_2 , V_3 ) ||
F_106 ( V_2 -> V_9 ) != V_56 -> V_59 )
goto V_29;
if ( V_2 -> V_12 > V_104 -> V_15 ||
F_3 ( V_2 , V_104 -> V_15 ) != V_56 -> V_11 )
goto V_29;
if ( V_3 ) {
if ( F_81 ( V_115 ,
V_118 , V_20 ) )
V_24 = F_85 ( V_56 , V_20 , V_2 , V_104 -> V_15 ) ;
} else if ( F_76 ( V_101 , & V_20 -> V_4 ) ) {
if ( ! F_82 ( V_56 ,
V_119 , V_20 ) )
V_24 |= F_87 ( V_56 , V_20 , V_104 -> V_15 ) ;
}
V_29:
F_66 ( & V_20 -> V_117 ) ;
free:
F_101 ( V_20 ) ;
V_104 = F_94 ( V_104 ) ;
}
V_95:
F_107 ( & V_116 ) ;
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
if ( ! V_77 -> V_120 && ! V_77 -> V_121 )
return - V_122 ;
if ( V_11 > F_73 ( V_59 ) )
return - V_122 ;
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
struct V_76 * V_77 , bool V_123 )
{
struct V_56 * V_56 ;
struct V_76 * V_80 ;
int V_48 = - V_124 ;
V_56 = F_47 ( V_59 , V_11 ) ;
if ( ! V_56 )
return V_48 ;
F_65 ( & V_56 -> V_73 ) ;
for ( V_80 = V_56 -> V_79 ; V_80 && V_80 != V_77 ; V_80 = V_80 -> V_78 )
;
if ( V_80 )
V_48 = F_103 ( V_56 , V_123 ? V_77 : NULL ) ;
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
F_83 ( & V_20 -> V_117 ) ;
for ( V_2 = V_20 -> V_125 ; V_2 ; V_2 = V_2 -> V_126 ) {
unsigned long V_15 ;
T_2 V_11 ;
if ( ! F_1 ( V_2 , false ) ||
F_106 ( V_2 -> V_9 ) != V_56 -> V_59 )
continue;
V_11 = ( T_2 ) V_2 -> V_13 << V_14 ;
if ( V_56 -> V_11 < V_11 ||
V_56 -> V_11 >= V_11 + V_2 -> V_127 - V_2 -> V_12 )
continue;
V_15 = F_2 ( V_2 , V_56 -> V_11 ) ;
V_24 |= F_87 ( V_56 , V_20 , V_15 ) ;
}
F_84 ( & V_20 -> V_117 ) ;
return V_24 ;
}
static struct V_61 *
F_115 ( struct V_59 * V_59 , T_2 V_128 , T_2 V_129 )
{
struct V_61 * V_62 = V_63 . V_61 ;
while ( V_62 ) {
struct V_56 * V_60 = F_45 ( V_62 , struct V_56 , V_61 ) ;
if ( V_59 < V_60 -> V_59 ) {
V_62 = V_62 -> V_66 ;
} else if ( V_59 > V_60 -> V_59 ) {
V_62 = V_62 -> V_67 ;
} else {
if ( V_129 < V_60 -> V_11 )
V_62 = V_62 -> V_66 ;
else if ( V_128 > V_60 -> V_11 )
V_62 = V_62 -> V_67 ;
else
break;
}
}
return V_62 ;
}
static void F_116 ( struct V_59 * V_59 ,
struct V_1 * V_2 ,
unsigned long V_130 , unsigned long V_131 ,
struct V_132 * V_133 )
{
T_2 V_128 , V_129 ;
struct V_61 * V_62 , * V_134 ;
struct V_56 * V_60 ;
F_117 ( V_133 ) ;
V_128 = F_3 ( V_2 , V_130 ) ;
V_129 = V_128 + ( V_131 - V_130 ) - 1 ;
F_48 ( & V_68 ) ;
V_62 = F_115 ( V_59 , V_128 , V_129 ) ;
if ( V_62 ) {
for ( V_134 = V_62 ; V_134 ; V_134 = F_118 ( V_134 ) ) {
V_60 = F_45 ( V_134 , struct V_56 , V_61 ) ;
if ( V_60 -> V_59 != V_59 || V_60 -> V_11 < V_128 )
break;
F_119 ( & V_60 -> V_135 , V_133 ) ;
F_46 ( & V_60 -> V_65 ) ;
}
for ( V_134 = V_62 ; ( V_134 = F_120 ( V_134 ) ) ; ) {
V_60 = F_45 ( V_134 , struct V_56 , V_61 ) ;
if ( V_60 -> V_59 != V_59 || V_60 -> V_11 > V_129 )
break;
F_119 ( & V_60 -> V_135 , V_133 ) ;
F_46 ( & V_60 -> V_65 ) ;
}
}
F_49 ( & V_68 ) ;
}
int F_121 ( struct V_1 * V_2 )
{
struct V_132 V_136 ;
struct V_56 * V_56 , * V_60 ;
struct V_59 * V_59 ;
if ( F_122 () || ! F_1 ( V_2 , true ) )
return 0 ;
V_59 = F_106 ( V_2 -> V_9 ) ;
if ( ! V_59 )
return 0 ;
F_96 ( F_123 ( V_59 ) ) ;
F_116 ( V_59 , V_2 , V_2 -> V_12 , V_2 -> V_127 , & V_136 ) ;
F_124 (uprobe, u, &tmp_list, pending_list) {
if ( ! F_125 ( V_137 ) &&
F_82 ( V_56 , V_138 , V_2 -> V_21 ) ) {
unsigned long V_15 = F_2 ( V_2 , V_56 -> V_11 ) ;
F_85 ( V_56 , V_2 -> V_21 , V_2 , V_15 ) ;
}
F_55 ( V_56 ) ;
}
F_100 ( F_123 ( V_59 ) ) ;
return 0 ;
}
static bool
F_126 ( struct V_1 * V_2 , unsigned long V_130 , unsigned long V_131 )
{
T_2 V_128 , V_129 ;
struct V_59 * V_59 ;
struct V_61 * V_62 ;
V_59 = F_106 ( V_2 -> V_9 ) ;
V_128 = F_3 ( V_2 , V_130 ) ;
V_129 = V_128 + ( V_131 - V_130 ) - 1 ;
F_48 ( & V_68 ) ;
V_62 = F_115 ( V_59 , V_128 , V_129 ) ;
F_49 ( & V_68 ) ;
return ! ! V_62 ;
}
void F_127 ( struct V_1 * V_2 , unsigned long V_130 , unsigned long V_131 )
{
if ( F_122 () || ! F_1 ( V_2 , false ) )
return;
if ( ! F_128 ( & V_2 -> V_21 -> V_114 ) )
return;
if ( ! F_76 ( V_101 , & V_2 -> V_21 -> V_4 ) ||
F_76 ( V_102 , & V_2 -> V_21 -> V_4 ) )
return;
if ( F_126 ( V_2 , V_130 , V_131 ) )
F_80 ( V_102 , & V_2 -> V_21 -> V_4 ) ;
}
static int F_129 ( struct V_19 * V_20 , struct V_139 * V_140 )
{
int V_48 = - V_141 ;
F_65 ( & V_20 -> V_117 ) ;
if ( V_20 -> V_142 . V_139 )
goto V_143;
if ( ! V_140 -> V_15 ) {
V_140 -> V_15 = F_130 ( NULL , V_144 - V_27 ,
V_27 , 0 , 0 ) ;
if ( V_140 -> V_15 & ~ V_39 ) {
V_48 = V_140 -> V_15 ;
goto V_143;
}
}
V_48 = F_131 ( V_20 , V_140 -> V_15 , V_27 ,
V_145 | V_6 | V_146 | V_147 , & V_140 -> V_17 ) ;
if ( V_48 )
goto V_143;
F_79 () ;
V_20 -> V_142 . V_139 = V_140 ;
V_143:
F_66 ( & V_20 -> V_117 ) ;
return V_48 ;
}
static struct V_139 * F_132 ( unsigned long V_15 )
{
struct V_19 * V_20 = V_137 -> V_20 ;
T_5 V_34 = V_35 ;
struct V_139 * V_140 ;
V_140 = F_98 ( sizeof( * V_140 ) , V_72 ) ;
if ( F_40 ( ! V_140 ) )
goto V_95;
V_140 -> V_148 = F_59 ( F_133 ( V_149 ) * sizeof( long ) , V_72 ) ;
if ( ! V_140 -> V_148 )
goto V_150;
V_140 -> V_17 = F_134 ( V_151 ) ;
if ( ! V_140 -> V_17 )
goto V_152;
V_140 -> V_15 = V_15 ;
F_135 ( & V_140 -> V_153 ) ;
F_80 ( 0 , V_140 -> V_148 ) ;
F_53 ( & V_140 -> V_154 , 1 ) ;
F_31 ( V_140 -> V_17 , 0 , & V_34 , V_44 ) ;
if ( ! F_129 ( V_20 , V_140 ) )
return V_140 ;
F_136 ( V_140 -> V_17 ) ;
V_152:
F_57 ( V_140 -> V_148 ) ;
V_150:
F_57 ( V_140 ) ;
V_95:
return NULL ;
}
static struct V_139 * F_137 ( void )
{
struct V_19 * V_20 = V_137 -> V_20 ;
struct V_139 * V_140 ;
if ( ! V_20 -> V_142 . V_139 )
F_132 ( 0 ) ;
V_140 = V_20 -> V_142 . V_139 ;
F_138 () ;
return V_140 ;
}
void F_139 ( struct V_19 * V_20 )
{
struct V_139 * V_140 = V_20 -> V_142 . V_139 ;
if ( ! V_140 )
return;
F_23 ( V_140 -> V_17 ) ;
F_57 ( V_140 -> V_148 ) ;
F_57 ( V_140 ) ;
}
void F_140 ( void )
{
F_141 ( & V_116 ) ;
}
void F_142 ( void )
{
F_143 ( & V_116 ) ;
}
void F_144 ( struct V_19 * V_155 , struct V_19 * V_156 )
{
V_156 -> V_142 . V_139 = NULL ;
if ( F_76 ( V_101 , & V_155 -> V_4 ) ) {
F_80 ( V_101 , & V_156 -> V_4 ) ;
F_80 ( V_102 , & V_156 -> V_4 ) ;
}
}
static unsigned long F_145 ( struct V_139 * V_140 )
{
unsigned long V_157 ;
int V_158 ;
do {
V_158 = F_146 ( V_140 -> V_148 , V_149 ) ;
if ( V_158 < V_149 ) {
if ( ! F_147 ( V_158 , V_140 -> V_148 ) )
break;
V_158 = V_149 ;
continue;
}
F_148 ( V_140 -> V_153 , ( F_128 ( & V_140 -> V_154 ) < V_149 ) ) ;
} while ( V_158 >= V_149 );
V_157 = V_140 -> V_15 + ( V_158 * V_159 ) ;
F_46 ( & V_140 -> V_154 ) ;
return V_157 ;
}
static unsigned long F_149 ( struct V_56 * V_56 )
{
struct V_139 * V_140 ;
unsigned long V_160 ;
V_140 = F_137 () ;
if ( ! V_140 )
return 0 ;
V_160 = F_145 ( V_140 ) ;
if ( F_40 ( ! V_160 ) )
return 0 ;
F_31 ( V_140 -> V_17 , V_160 ,
& V_56 -> V_92 . V_161 , sizeof( V_56 -> V_92 . V_161 ) ) ;
F_150 ( V_140 -> V_17 ) ;
return V_160 ;
}
static void F_151 ( struct V_162 * V_163 )
{
struct V_139 * V_140 ;
unsigned long V_164 ;
unsigned long V_157 ;
if ( ! V_163 -> V_20 || ! V_163 -> V_20 -> V_142 . V_139 || ! V_163 -> V_165 )
return;
V_157 = V_163 -> V_165 -> V_160 ;
if ( F_40 ( ! V_157 ) )
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
F_86 ( V_158 , V_140 -> V_148 ) ;
F_152 ( & V_140 -> V_154 ) ;
if ( F_153 ( & V_140 -> V_153 ) )
F_154 ( & V_140 -> V_153 ) ;
V_163 -> V_165 -> V_160 = 0 ;
}
}
unsigned long __weak F_155 ( struct V_166 * V_167 )
{
return F_156 ( V_167 ) - V_44 ;
}
void F_157 ( struct V_162 * V_134 )
{
struct V_168 * V_165 = V_134 -> V_165 ;
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
F_151 ( V_134 ) ;
F_57 ( V_165 ) ;
V_134 -> V_165 = NULL ;
}
static struct V_168 * F_158 ( void )
{
if ( ! V_137 -> V_165 )
V_137 -> V_165 = F_59 ( sizeof( struct V_168 ) , V_72 ) ;
return V_137 -> V_165 ;
}
static int F_159 ( struct V_162 * V_134 , struct V_168 * V_174 )
{
struct V_168 * V_175 ;
struct V_169 * * V_69 , * V_176 , * V_62 ;
V_175 = F_59 ( sizeof( struct V_168 ) , V_72 ) ;
if ( ! V_175 )
return - V_51 ;
V_134 -> V_165 = V_175 ;
V_69 = & V_175 -> V_173 ;
for ( V_176 = V_174 -> V_173 ; V_176 ; V_176 = V_176 -> V_78 ) {
V_62 = F_98 ( sizeof( struct V_169 ) , V_72 ) ;
if ( ! V_62 )
return - V_51 ;
* V_62 = * V_176 ;
F_46 ( & V_62 -> V_56 -> V_65 ) ;
V_62 -> V_78 = NULL ;
* V_69 = V_62 ;
V_69 = & V_62 -> V_78 ;
V_175 -> V_177 ++ ;
}
return 0 ;
}
static void F_160 ( struct V_162 * V_134 , const char * V_178 )
{
F_161 ( L_1 ,
V_137 -> V_179 , V_137 -> V_180 , V_178 ) ;
}
static void F_162 ( struct V_181 * V_182 )
{
if ( V_137 -> V_4 & V_183 )
return;
if ( ! F_132 ( V_137 -> V_165 -> V_184 ) )
F_160 ( V_137 , L_2 ) ;
}
void F_163 ( struct V_162 * V_134 , unsigned long V_4 )
{
struct V_168 * V_165 = V_137 -> V_165 ;
struct V_19 * V_20 = V_137 -> V_20 ;
struct V_139 * V_140 ;
V_134 -> V_165 = NULL ;
if ( ! V_165 || ! V_165 -> V_173 )
return;
if ( V_20 == V_134 -> V_20 && ! ( V_4 & V_185 ) )
return;
if ( F_159 ( V_134 , V_165 ) )
return F_160 ( V_134 , L_3 ) ;
V_140 = V_20 -> V_142 . V_139 ;
if ( ! V_140 )
return F_160 ( V_134 , L_2 ) ;
if ( V_20 == V_134 -> V_20 )
return;
V_134 -> V_165 -> V_184 = V_140 -> V_15 ;
F_164 ( & V_134 -> V_165 -> F_162 , F_162 ) ;
F_165 ( V_134 , & V_134 -> V_165 -> F_162 , true ) ;
}
static unsigned long F_166 ( void )
{
struct V_139 * V_140 ;
unsigned long V_186 = - 1 ;
V_140 = V_137 -> V_20 -> V_142 . V_139 ;
F_138 () ;
if ( V_140 )
V_186 = V_140 -> V_15 ;
return V_186 ;
}
static void F_167 ( struct V_56 * V_56 , struct V_166 * V_167 )
{
struct V_169 * V_170 ;
struct V_168 * V_165 ;
unsigned long V_187 , V_186 ;
bool V_188 = false ;
if ( ! F_137 () )
return;
V_165 = F_158 () ;
if ( ! V_165 )
return;
if ( V_165 -> V_177 >= V_189 ) {
F_168 ( V_190 L_4
L_5 ,
V_137 -> V_180 , V_137 -> V_191 ) ;
return;
}
V_170 = F_59 ( sizeof( struct V_169 ) , V_72 ) ;
if ( ! V_170 )
goto V_143;
V_186 = F_166 () ;
V_187 = F_169 ( V_186 , V_167 ) ;
if ( V_187 == - 1 )
goto V_143;
if ( V_187 == V_186 ) {
if ( ! V_165 -> V_173 ) {
F_161 ( L_6 ,
V_137 -> V_180 , V_137 -> V_191 ) ;
goto V_143;
}
V_188 = true ;
V_187 = V_165 -> V_173 -> V_187 ;
}
F_46 ( & V_56 -> V_65 ) ;
V_170 -> V_56 = V_56 ;
V_170 -> V_192 = F_156 ( V_167 ) ;
V_170 -> V_187 = V_187 ;
V_170 -> V_188 = V_188 ;
V_165 -> V_177 ++ ;
V_170 -> V_78 = V_165 -> V_173 ;
V_165 -> V_173 = V_170 ;
return;
V_143:
F_57 ( V_170 ) ;
}
static int
F_170 ( struct V_56 * V_56 , struct V_166 * V_167 , unsigned long V_193 )
{
struct V_168 * V_165 ;
unsigned long V_160 ;
int V_24 ;
V_165 = F_158 () ;
if ( ! V_165 )
return - V_51 ;
V_160 = F_149 ( V_56 ) ;
if ( ! V_160 )
return - V_51 ;
V_165 -> V_160 = V_160 ;
V_165 -> V_15 = V_193 ;
V_24 = F_171 ( & V_56 -> V_92 , V_167 ) ;
if ( F_40 ( V_24 ) ) {
F_151 ( V_137 ) ;
return V_24 ;
}
V_165 -> V_172 = V_56 ;
V_165 -> V_194 = V_195 ;
return 0 ;
}
bool F_172 ( void )
{
struct V_162 * V_134 = V_137 ;
struct V_168 * V_165 = V_134 -> V_165 ;
if ( F_111 ( ! V_165 || ! V_165 -> V_172 ) )
return false ;
F_173 ( V_165 -> V_194 != V_195 ) ;
if ( F_174 ( V_134 ) ) {
F_175 ( & V_134 -> V_196 -> V_197 ) ;
F_176 ( V_134 , V_198 ) ;
F_177 ( & V_134 -> V_196 -> V_197 ) ;
if ( F_178 ( V_134 ) || F_179 ( V_134 ) ) {
V_165 -> V_194 = V_199 ;
F_180 ( V_134 , V_200 ) ;
F_180 ( V_134 , V_201 ) ;
}
}
return true ;
}
static bool F_181 ( struct V_56 * V_56 , struct V_166 * V_167 )
{
if ( F_76 ( V_75 , & V_56 -> V_4 ) ) {
if ( F_182 ( & V_56 -> V_92 , V_167 ) )
return true ;
F_86 ( V_75 , & V_56 -> V_4 ) ;
}
return false ;
}
static void F_183 ( struct V_19 * V_20 )
{
struct V_1 * V_2 ;
for ( V_2 = V_20 -> V_125 ; V_2 ; V_2 = V_2 -> V_126 ) {
if ( ! F_1 ( V_2 , false ) )
continue;
if ( F_126 ( V_2 , V_2 -> V_12 , V_2 -> V_127 ) )
return;
}
F_86 ( V_101 , & V_20 -> V_4 ) ;
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
goto V_95;
V_202 = F_34 ( NULL , V_20 , V_15 , 1 , 0 , 1 , & V_17 , NULL ) ;
if ( V_202 < 0 )
return V_202 ;
F_28 ( V_17 , V_15 , & V_45 , V_44 ) ;
F_23 ( V_17 ) ;
V_95:
return F_27 ( & V_45 ) ;
}
static struct V_56 * F_188 ( unsigned long V_193 , int * V_43 )
{
struct V_19 * V_20 = V_137 -> V_20 ;
struct V_56 * V_56 = NULL ;
struct V_1 * V_2 ;
F_83 ( & V_20 -> V_117 ) ;
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
if ( ! V_56 && F_189 ( V_102 , & V_20 -> V_4 ) )
F_183 ( V_20 ) ;
F_84 ( & V_20 -> V_117 ) ;
return V_56 ;
}
static void F_190 ( struct V_56 * V_56 , struct V_166 * V_167 )
{
struct V_76 * V_77 ;
int remove = V_205 ;
bool V_206 = false ;
F_83 ( & V_56 -> V_73 ) ;
for ( V_77 = V_56 -> V_79 ; V_77 ; V_77 = V_77 -> V_78 ) {
int V_207 = 0 ;
if ( V_77 -> V_120 ) {
V_207 = V_77 -> V_120 ( V_77 , V_167 ) ;
F_191 ( V_207 & ~ V_208 ,
L_7 , V_207 , V_77 -> V_120 ) ;
}
if ( V_77 -> V_121 )
V_206 = true ;
remove &= V_207 ;
}
if ( V_206 && ! remove )
F_167 ( V_56 , V_167 ) ;
if ( remove && V_56 -> V_79 ) {
F_91 ( ! F_88 ( V_56 ) ) ;
F_114 ( V_56 , V_137 -> V_20 ) ;
}
F_84 ( & V_56 -> V_73 ) ;
}
static void
F_192 ( struct V_169 * V_170 , struct V_166 * V_167 )
{
struct V_56 * V_56 = V_170 -> V_56 ;
struct V_76 * V_77 ;
F_83 ( & V_56 -> V_73 ) ;
for ( V_77 = V_56 -> V_79 ; V_77 ; V_77 = V_77 -> V_78 ) {
if ( V_77 -> V_121 )
V_77 -> V_121 ( V_77 , V_170 -> V_192 , V_167 ) ;
}
F_84 ( & V_56 -> V_73 ) ;
}
static bool F_193 ( struct V_166 * V_167 )
{
struct V_168 * V_165 ;
struct V_169 * V_170 , * V_171 ;
bool V_188 ;
V_165 = V_137 -> V_165 ;
if ( ! V_165 )
return false ;
V_170 = V_165 -> V_173 ;
if ( ! V_170 )
return false ;
F_194 ( V_167 , V_170 -> V_187 ) ;
for (; ; ) {
F_192 ( V_170 , V_167 ) ;
V_188 = V_170 -> V_188 ;
F_55 ( V_170 -> V_56 ) ;
V_171 = V_170 ;
V_170 = V_170 -> V_78 ;
F_57 ( V_171 ) ;
V_165 -> V_177 -- ;
if ( ! V_188 )
break;
F_78 ( ! V_170 ) ;
}
V_165 -> V_173 = V_170 ;
return true ;
}
bool __weak F_195 ( struct V_54 * V_209 , struct V_166 * V_167 )
{
return false ;
}
static void F_196 ( struct V_166 * V_167 )
{
struct V_56 * V_56 ;
unsigned long V_193 ;
int V_210 ( V_43 ) ;
V_193 = F_155 ( V_167 ) ;
if ( V_193 == F_166 () ) {
if ( F_193 ( V_167 ) )
return;
F_161 ( L_8 ,
V_137 -> V_180 , V_137 -> V_191 ) ;
}
V_56 = F_188 ( V_193 , & V_43 ) ;
if ( ! V_56 ) {
if ( V_43 > 0 ) {
F_197 ( V_211 , V_137 , 0 ) ;
} else {
F_194 ( V_167 , V_193 ) ;
}
return;
}
F_194 ( V_167 , V_193 ) ;
F_198 () ;
if ( F_40 ( ! F_76 ( V_94 , & V_56 -> V_4 ) ) )
goto V_95;
if ( ! F_158 () )
goto V_95;
if ( F_195 ( & V_56 -> V_92 , V_167 ) )
goto V_95;
F_190 ( V_56 , V_167 ) ;
if ( F_181 ( V_56 , V_167 ) )
goto V_95;
if ( ! F_170 ( V_56 , V_167 , V_193 ) )
return;
V_95:
F_55 ( V_56 ) ;
}
static void F_199 ( struct V_168 * V_165 , struct V_166 * V_167 )
{
struct V_56 * V_56 ;
V_56 = V_165 -> V_172 ;
if ( V_165 -> V_194 == V_212 )
F_200 ( & V_56 -> V_92 , V_167 ) ;
else if ( V_165 -> V_194 == V_199 )
F_201 ( & V_56 -> V_92 , V_167 ) ;
else
F_173 ( 1 ) ;
F_55 ( V_56 ) ;
V_165 -> V_172 = NULL ;
V_165 -> V_194 = V_213 ;
F_151 ( V_137 ) ;
F_175 ( & V_137 -> V_196 -> V_197 ) ;
F_202 () ;
F_177 ( & V_137 -> V_196 -> V_197 ) ;
}
void F_203 ( struct V_166 * V_167 )
{
struct V_168 * V_165 ;
F_204 ( V_200 ) ;
V_165 = V_137 -> V_165 ;
if ( V_165 && V_165 -> V_172 )
F_199 ( V_165 , V_167 ) ;
else
F_196 ( V_167 ) ;
}
int F_205 ( struct V_166 * V_167 )
{
if ( ! V_137 -> V_20 )
return 0 ;
if ( ! F_76 ( V_101 , & V_137 -> V_20 -> V_4 ) &&
( ! V_137 -> V_165 || ! V_137 -> V_165 -> V_173 ) )
return 0 ;
F_206 ( V_200 ) ;
return 1 ;
}
int F_207 ( struct V_166 * V_167 )
{
struct V_168 * V_165 = V_137 -> V_165 ;
if ( ! V_137 -> V_20 || ! V_165 || ! V_165 -> V_172 )
return 0 ;
V_165 -> V_194 = V_212 ;
F_206 ( V_200 ) ;
return 1 ;
}
static int T_6 F_208 ( void )
{
int V_214 ;
for ( V_214 = 0 ; V_214 < V_215 ; V_214 ++ )
F_209 ( & V_216 [ V_214 ] ) ;
if ( F_210 ( & V_116 ) )
return - V_51 ;
return F_211 ( & V_217 ) ;
}
