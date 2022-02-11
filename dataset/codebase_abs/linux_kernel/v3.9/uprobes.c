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
static void F_27 ( struct V_17 * V_17 , unsigned long V_15 , T_5 * V_36 )
{
void * V_37 = F_28 ( V_17 ) ;
memcpy ( V_36 , V_37 + ( V_15 & ~ V_38 ) , V_39 ) ;
F_29 ( V_37 ) ;
}
static int F_30 ( struct V_17 * V_17 , unsigned long V_15 , T_5 * V_40 )
{
T_5 V_41 ;
bool V_42 ;
F_27 ( V_17 , V_15 , & V_41 ) ;
V_42 = F_26 ( & V_41 ) ;
if ( F_26 ( V_40 ) ) {
if ( V_42 )
return 0 ;
} else {
if ( ! V_42 )
return 0 ;
}
return 1 ;
}
static int F_31 ( struct V_19 * V_20 , unsigned long V_15 ,
T_5 V_36 )
{
struct V_17 * V_43 , * V_44 ;
void * V_45 , * V_46 ;
struct V_1 * V_2 ;
int V_47 ;
V_48:
V_47 = F_32 ( NULL , V_20 , V_15 , 1 , 0 , 1 , & V_43 , & V_2 ) ;
if ( V_47 <= 0 )
return V_47 ;
V_47 = F_30 ( V_43 , V_15 , & V_36 ) ;
if ( V_47 <= 0 )
goto V_49;
V_47 = - V_50 ;
V_44 = F_33 ( V_51 , V_2 , V_15 ) ;
if ( ! V_44 )
goto V_49;
F_34 ( V_44 ) ;
V_45 = F_28 ( V_43 ) ;
V_46 = F_28 ( V_44 ) ;
memcpy ( V_46 , V_45 , V_27 ) ;
memcpy ( V_46 + ( V_15 & ~ V_38 ) , & V_36 , V_39 ) ;
F_29 ( V_46 ) ;
F_29 ( V_45 ) ;
V_47 = F_35 ( V_2 ) ;
if ( V_47 )
goto V_52;
V_47 = F_4 ( V_2 , V_15 , V_43 , V_44 ) ;
V_52:
F_36 ( V_44 ) ;
V_49:
F_23 ( V_43 ) ;
if ( F_37 ( V_47 == - V_28 ) )
goto V_48;
return V_47 ;
}
int __weak F_38 ( struct V_53 * V_54 , struct V_19 * V_20 , unsigned long V_15 )
{
return F_31 ( V_20 , V_15 , V_35 ) ;
}
int __weak
F_39 ( struct V_53 * V_54 , struct V_19 * V_20 , unsigned long V_15 )
{
return F_31 ( V_20 , V_15 , * ( T_5 * ) V_54 -> V_34 ) ;
}
static int F_40 ( struct V_55 * V_56 , struct V_55 * V_57 )
{
if ( V_56 -> V_58 < V_57 -> V_58 )
return - 1 ;
if ( V_56 -> V_58 > V_57 -> V_58 )
return 1 ;
if ( V_56 -> V_11 < V_57 -> V_11 )
return - 1 ;
if ( V_56 -> V_11 > V_57 -> V_11 )
return 1 ;
return 0 ;
}
static struct V_55 * F_41 ( struct V_58 * V_58 , T_2 V_11 )
{
struct V_55 V_59 = { . V_58 = V_58 , . V_11 = V_11 } ;
struct V_60 * V_61 = V_62 . V_60 ;
struct V_55 * V_55 ;
int V_63 ;
while ( V_61 ) {
V_55 = F_42 ( V_61 , struct V_55 , V_60 ) ;
V_63 = F_40 ( & V_59 , V_55 ) ;
if ( ! V_63 ) {
F_43 ( & V_55 -> V_64 ) ;
return V_55 ;
}
if ( V_63 < 0 )
V_61 = V_61 -> V_65 ;
else
V_61 = V_61 -> V_66 ;
}
return NULL ;
}
static struct V_55 * F_44 ( struct V_58 * V_58 , T_2 V_11 )
{
struct V_55 * V_55 ;
F_45 ( & V_67 ) ;
V_55 = F_41 ( V_58 , V_11 ) ;
F_46 ( & V_67 ) ;
return V_55 ;
}
static struct V_55 * F_47 ( struct V_55 * V_55 )
{
struct V_60 * * V_68 = & V_62 . V_60 ;
struct V_60 * V_69 = NULL ;
struct V_55 * V_59 ;
int V_63 ;
while ( * V_68 ) {
V_69 = * V_68 ;
V_59 = F_42 ( V_69 , struct V_55 , V_60 ) ;
V_63 = F_40 ( V_55 , V_59 ) ;
if ( ! V_63 ) {
F_43 ( & V_59 -> V_64 ) ;
return V_59 ;
}
if ( V_63 < 0 )
V_68 = & V_69 -> V_65 ;
else
V_68 = & V_69 -> V_66 ;
}
V_59 = NULL ;
F_48 ( & V_55 -> V_60 , V_69 , V_68 ) ;
F_49 ( & V_55 -> V_60 , & V_62 ) ;
F_50 ( & V_55 -> V_64 , 2 ) ;
return V_59 ;
}
static struct V_55 * F_51 ( struct V_55 * V_55 )
{
struct V_55 * V_59 ;
F_45 ( & V_67 ) ;
V_59 = F_47 ( V_55 ) ;
F_46 ( & V_67 ) ;
return V_59 ;
}
static void F_52 ( struct V_55 * V_55 )
{
if ( F_53 ( & V_55 -> V_64 ) )
F_54 ( V_55 ) ;
}
static struct V_55 * F_55 ( struct V_58 * V_58 , T_2 V_11 )
{
struct V_55 * V_55 , * V_70 ;
V_55 = F_56 ( sizeof( struct V_55 ) , V_71 ) ;
if ( ! V_55 )
return NULL ;
V_55 -> V_58 = F_57 ( V_58 ) ;
V_55 -> V_11 = V_11 ;
F_58 ( & V_55 -> V_72 ) ;
F_58 ( & V_55 -> V_73 ) ;
F_59 ( V_74 , & V_55 -> V_4 ) ;
V_70 = F_51 ( V_55 ) ;
if ( V_70 ) {
F_54 ( V_55 ) ;
V_55 = V_70 ;
F_60 ( V_58 ) ;
}
return V_55 ;
}
static void F_61 ( struct V_55 * V_55 , struct V_75 * V_76 )
{
F_62 ( & V_55 -> V_73 ) ;
V_76 -> V_77 = V_55 -> V_78 ;
V_55 -> V_78 = V_76 ;
F_63 ( & V_55 -> V_73 ) ;
}
static bool F_64 ( struct V_55 * V_55 , struct V_75 * V_76 )
{
struct V_75 * * V_79 ;
bool V_47 = false ;
F_62 ( & V_55 -> V_73 ) ;
for ( V_79 = & V_55 -> V_78 ; * V_79 ; V_79 = & ( * V_79 ) -> V_77 ) {
if ( * V_79 == V_76 ) {
* V_79 = V_76 -> V_77 ;
V_47 = true ;
break;
}
}
F_63 ( & V_55 -> V_73 ) ;
return V_47 ;
}
static int
F_65 ( struct V_80 * V_81 , struct V_82 * V_83 , char * V_34 ,
unsigned long V_84 , T_2 V_11 )
{
struct V_17 * V_17 ;
void * V_15 ;
unsigned long V_85 ;
T_6 V_86 ;
if ( ! V_83 )
return - V_87 ;
if ( ! V_81 -> V_88 -> V_89 )
return - V_90 ;
V_86 = V_11 >> V_91 ;
V_85 = V_11 & ~ V_38 ;
V_17 = F_66 ( V_81 , V_86 , V_83 ) ;
if ( F_67 ( V_17 ) )
return F_68 ( V_17 ) ;
V_15 = F_28 ( V_17 ) ;
memcpy ( V_34 , V_15 + V_85 , V_84 ) ;
F_29 ( V_15 ) ;
F_36 ( V_17 ) ;
return 0 ;
}
static int F_69 ( struct V_55 * V_55 , struct V_82 * V_83 )
{
struct V_80 * V_81 ;
unsigned long V_84 ;
int V_92 ;
V_84 = V_27 - ( V_55 -> V_11 & ~ V_38 ) ;
V_81 = V_55 -> V_58 -> V_93 ;
if ( V_55 -> V_11 + V_94 > V_55 -> V_58 -> V_95 )
V_92 = V_55 -> V_58 -> V_95 - V_55 -> V_11 ;
else
V_92 = V_94 ;
if ( V_84 < V_92 ) {
int V_24 = F_65 ( V_81 , V_83 , V_55 -> V_96 . V_34 + V_84 ,
V_92 - V_84 , V_55 -> V_11 + V_84 ) ;
if ( V_24 )
return V_24 ;
V_92 = V_84 ;
}
return F_65 ( V_81 , V_83 , V_55 -> V_96 . V_34 , V_92 , V_55 -> V_11 ) ;
}
static int F_70 ( struct V_55 * V_55 , struct V_82 * V_82 ,
struct V_19 * V_20 , unsigned long V_15 )
{
int V_47 = 0 ;
if ( F_71 ( V_97 , & V_55 -> V_4 ) )
return V_47 ;
F_62 ( & V_55 -> V_73 ) ;
if ( F_71 ( V_97 , & V_55 -> V_4 ) )
goto V_98;
V_47 = F_69 ( V_55 , V_82 ) ;
if ( V_47 )
goto V_98;
V_47 = - V_99 ;
if ( F_26 ( ( T_5 * ) V_55 -> V_96 . V_34 ) )
goto V_98;
V_47 = F_72 ( & V_55 -> V_96 , V_20 , V_15 ) ;
if ( V_47 )
goto V_98;
F_73 ( ( V_55 -> V_11 & ~ V_38 ) +
V_39 > V_27 ) ;
F_74 () ;
F_75 ( V_97 , & V_55 -> V_4 ) ;
V_98:
F_63 ( & V_55 -> V_73 ) ;
return V_47 ;
}
static inline bool F_76 ( struct V_75 * V_76 ,
enum V_100 V_101 , struct V_19 * V_20 )
{
return ! V_76 -> V_102 || V_76 -> V_102 ( V_76 , V_101 , V_20 ) ;
}
static bool F_77 ( struct V_55 * V_55 ,
enum V_100 V_101 , struct V_19 * V_20 )
{
struct V_75 * V_76 ;
bool V_47 = false ;
F_78 ( & V_55 -> V_73 ) ;
for ( V_76 = V_55 -> V_78 ; V_76 ; V_76 = V_76 -> V_77 ) {
V_47 = F_76 ( V_76 , V_101 , V_20 ) ;
if ( V_47 )
break;
}
F_79 ( & V_55 -> V_73 ) ;
return V_47 ;
}
static int
F_80 ( struct V_55 * V_55 , struct V_19 * V_20 ,
struct V_1 * V_2 , unsigned long V_15 )
{
bool V_103 ;
int V_47 ;
V_47 = F_70 ( V_55 , V_2 -> V_9 , V_20 , V_15 ) ;
if ( V_47 )
return V_47 ;
V_103 = ! F_71 ( V_104 , & V_20 -> V_4 ) ;
if ( V_103 )
F_75 ( V_104 , & V_20 -> V_4 ) ;
V_47 = F_38 ( & V_55 -> V_96 , V_20 , V_15 ) ;
if ( ! V_47 )
F_81 ( V_105 , & V_20 -> V_4 ) ;
else if ( V_103 )
F_81 ( V_104 , & V_20 -> V_4 ) ;
return V_47 ;
}
static int
F_82 ( struct V_55 * V_55 , struct V_19 * V_20 , unsigned long V_15 )
{
F_75 ( V_105 , & V_20 -> V_4 ) ;
return F_39 ( & V_55 -> V_96 , V_20 , V_15 ) ;
}
static inline bool F_83 ( struct V_55 * V_55 )
{
return ! F_84 ( & V_55 -> V_60 ) ;
}
static void F_85 ( struct V_55 * V_55 )
{
if ( F_86 ( ! F_83 ( V_55 ) ) )
return;
F_45 ( & V_67 ) ;
F_87 ( & V_55 -> V_60 , & V_62 ) ;
F_46 ( & V_67 ) ;
F_88 ( & V_55 -> V_60 ) ;
F_60 ( V_55 -> V_58 ) ;
F_52 ( V_55 ) ;
}
static inline struct V_106 * F_89 ( struct V_106 * V_107 )
{
struct V_106 * V_77 = V_107 -> V_77 ;
F_54 ( V_107 ) ;
return V_77 ;
}
static struct V_106 *
F_90 ( struct V_80 * V_81 , T_2 V_11 , bool V_3 )
{
unsigned long V_108 = V_11 >> V_14 ;
struct V_1 * V_2 ;
struct V_106 * V_109 = NULL ;
struct V_106 * V_110 = NULL ;
struct V_106 * V_107 ;
int V_111 = 0 ;
V_112:
F_91 ( & V_81 -> V_113 ) ;
F_92 (vma, &mapping->i_mmap, pgoff, pgoff) {
if ( ! F_1 ( V_2 , V_3 ) )
continue;
if ( ! V_110 && ! V_111 ) {
V_110 = F_93 ( sizeof( struct V_106 ) ,
V_114 | V_115 | V_116 ) ;
if ( V_110 )
V_110 -> V_77 = NULL ;
}
if ( ! V_110 ) {
V_111 ++ ;
continue;
}
if ( ! F_94 ( & V_2 -> V_21 -> V_117 ) )
continue;
V_107 = V_110 ;
V_110 = V_110 -> V_77 ;
V_107 -> V_77 = V_109 ;
V_109 = V_107 ;
V_107 -> V_20 = V_2 -> V_21 ;
V_107 -> V_15 = F_2 ( V_2 , V_11 ) ;
}
F_95 ( & V_81 -> V_113 ) ;
if ( ! V_111 )
goto V_98;
V_110 = V_109 ;
while ( V_109 ) {
F_96 ( V_109 -> V_20 ) ;
V_109 = V_109 -> V_77 ;
}
do {
V_107 = F_93 ( sizeof( struct V_106 ) , V_71 ) ;
if ( ! V_107 ) {
V_109 = F_97 ( - V_50 ) ;
goto V_98;
}
V_107 -> V_77 = V_110 ;
V_110 = V_107 ;
} while ( -- V_111 );
goto V_112;
V_98:
while ( V_110 )
V_110 = F_89 ( V_110 ) ;
return V_109 ;
}
static int
F_98 ( struct V_55 * V_55 , struct V_75 * V_118 )
{
bool V_3 = ! ! V_118 ;
struct V_106 * V_107 ;
int V_24 = 0 ;
F_99 ( & V_119 ) ;
V_107 = F_90 ( V_55 -> V_58 -> V_93 ,
V_55 -> V_11 , V_3 ) ;
if ( F_67 ( V_107 ) ) {
V_24 = F_68 ( V_107 ) ;
goto V_98;
}
while ( V_107 ) {
struct V_19 * V_20 = V_107 -> V_20 ;
struct V_1 * V_2 ;
if ( V_24 && V_3 )
goto free;
F_62 ( & V_20 -> V_120 ) ;
V_2 = F_100 ( V_20 , V_107 -> V_15 ) ;
if ( ! V_2 || ! F_1 ( V_2 , V_3 ) ||
V_2 -> V_9 -> V_121 -> V_122 != V_55 -> V_58 )
goto V_29;
if ( V_2 -> V_12 > V_107 -> V_15 ||
F_3 ( V_2 , V_107 -> V_15 ) != V_55 -> V_11 )
goto V_29;
if ( V_3 ) {
if ( F_76 ( V_118 ,
V_123 , V_20 ) )
V_24 = F_80 ( V_55 , V_20 , V_2 , V_107 -> V_15 ) ;
} else if ( F_71 ( V_104 , & V_20 -> V_4 ) ) {
if ( ! F_77 ( V_55 ,
V_124 , V_20 ) )
V_24 |= F_82 ( V_55 , V_20 , V_107 -> V_15 ) ;
}
V_29:
F_63 ( & V_20 -> V_120 ) ;
free:
F_96 ( V_20 ) ;
V_107 = F_89 ( V_107 ) ;
}
V_98:
F_101 ( & V_119 ) ;
return V_24 ;
}
static int F_102 ( struct V_55 * V_55 , struct V_75 * V_76 )
{
F_61 ( V_55 , V_76 ) ;
return F_98 ( V_55 , V_76 ) ;
}
static void F_103 ( struct V_55 * V_55 , struct V_75 * V_76 )
{
int V_24 ;
if ( ! F_64 ( V_55 , V_76 ) )
return;
V_24 = F_98 ( V_55 , NULL ) ;
if ( ! V_55 -> V_78 && ! V_24 )
F_85 ( V_55 ) ;
}
int F_104 ( struct V_58 * V_58 , T_2 V_11 , struct V_75 * V_76 )
{
struct V_55 * V_55 ;
int V_47 ;
if ( V_11 > F_105 ( V_58 ) )
return - V_87 ;
V_48:
V_55 = F_55 ( V_58 , V_11 ) ;
if ( ! V_55 )
return - V_50 ;
F_62 ( & V_55 -> V_72 ) ;
V_47 = - V_28 ;
if ( F_106 ( F_83 ( V_55 ) ) ) {
V_47 = F_102 ( V_55 , V_76 ) ;
if ( V_47 )
F_103 ( V_55 , V_76 ) ;
}
F_63 ( & V_55 -> V_72 ) ;
F_52 ( V_55 ) ;
if ( F_37 ( V_47 == - V_28 ) )
goto V_48;
return V_47 ;
}
int F_107 ( struct V_58 * V_58 , T_2 V_11 ,
struct V_75 * V_76 , bool V_125 )
{
struct V_55 * V_55 ;
struct V_75 * V_79 ;
int V_47 = - V_126 ;
V_55 = F_44 ( V_58 , V_11 ) ;
if ( ! V_55 )
return V_47 ;
F_62 ( & V_55 -> V_72 ) ;
for ( V_79 = V_55 -> V_78 ; V_79 && V_79 != V_76 ; V_79 = V_79 -> V_77 )
;
if ( V_79 )
V_47 = F_98 ( V_55 , V_125 ? V_76 : NULL ) ;
F_63 ( & V_55 -> V_72 ) ;
F_52 ( V_55 ) ;
return V_47 ;
}
void F_108 ( struct V_58 * V_58 , T_2 V_11 , struct V_75 * V_76 )
{
struct V_55 * V_55 ;
V_55 = F_44 ( V_58 , V_11 ) ;
if ( ! V_55 )
return;
F_62 ( & V_55 -> V_72 ) ;
F_103 ( V_55 , V_76 ) ;
F_63 ( & V_55 -> V_72 ) ;
F_52 ( V_55 ) ;
}
static int F_109 ( struct V_55 * V_55 , struct V_19 * V_20 )
{
struct V_1 * V_2 ;
int V_24 = 0 ;
F_78 ( & V_20 -> V_120 ) ;
for ( V_2 = V_20 -> V_127 ; V_2 ; V_2 = V_2 -> V_128 ) {
unsigned long V_15 ;
T_2 V_11 ;
if ( ! F_1 ( V_2 , false ) ||
V_2 -> V_9 -> V_121 -> V_122 != V_55 -> V_58 )
continue;
V_11 = ( T_2 ) V_2 -> V_13 << V_14 ;
if ( V_55 -> V_11 < V_11 ||
V_55 -> V_11 >= V_11 + V_2 -> V_129 - V_2 -> V_12 )
continue;
V_15 = F_2 ( V_2 , V_55 -> V_11 ) ;
V_24 |= F_82 ( V_55 , V_20 , V_15 ) ;
}
F_79 ( & V_20 -> V_120 ) ;
return V_24 ;
}
static struct V_60 *
F_110 ( struct V_58 * V_58 , T_2 V_130 , T_2 V_131 )
{
struct V_60 * V_61 = V_62 . V_60 ;
while ( V_61 ) {
struct V_55 * V_59 = F_42 ( V_61 , struct V_55 , V_60 ) ;
if ( V_58 < V_59 -> V_58 ) {
V_61 = V_61 -> V_65 ;
} else if ( V_58 > V_59 -> V_58 ) {
V_61 = V_61 -> V_66 ;
} else {
if ( V_131 < V_59 -> V_11 )
V_61 = V_61 -> V_65 ;
else if ( V_130 > V_59 -> V_11 )
V_61 = V_61 -> V_66 ;
else
break;
}
}
return V_61 ;
}
static void F_111 ( struct V_58 * V_58 ,
struct V_1 * V_2 ,
unsigned long V_132 , unsigned long V_133 ,
struct V_134 * V_135 )
{
T_2 V_130 , V_131 ;
struct V_60 * V_61 , * V_136 ;
struct V_55 * V_59 ;
F_112 ( V_135 ) ;
V_130 = F_3 ( V_2 , V_132 ) ;
V_131 = V_130 + ( V_133 - V_132 ) - 1 ;
F_45 ( & V_67 ) ;
V_61 = F_110 ( V_58 , V_130 , V_131 ) ;
if ( V_61 ) {
for ( V_136 = V_61 ; V_136 ; V_136 = F_113 ( V_136 ) ) {
V_59 = F_42 ( V_136 , struct V_55 , V_60 ) ;
if ( V_59 -> V_58 != V_58 || V_59 -> V_11 < V_130 )
break;
F_114 ( & V_59 -> V_137 , V_135 ) ;
F_43 ( & V_59 -> V_64 ) ;
}
for ( V_136 = V_61 ; ( V_136 = F_115 ( V_136 ) ) ; ) {
V_59 = F_42 ( V_136 , struct V_55 , V_60 ) ;
if ( V_59 -> V_58 != V_58 || V_59 -> V_11 > V_131 )
break;
F_114 ( & V_59 -> V_137 , V_135 ) ;
F_43 ( & V_59 -> V_64 ) ;
}
}
F_46 ( & V_67 ) ;
}
int F_116 ( struct V_1 * V_2 )
{
struct V_134 V_138 ;
struct V_55 * V_55 , * V_59 ;
struct V_58 * V_58 ;
if ( F_117 () || ! F_1 ( V_2 , true ) )
return 0 ;
V_58 = V_2 -> V_9 -> V_121 -> V_122 ;
if ( ! V_58 )
return 0 ;
F_91 ( F_118 ( V_58 ) ) ;
F_111 ( V_58 , V_2 , V_2 -> V_12 , V_2 -> V_129 , & V_138 ) ;
F_119 (uprobe, u, &tmp_list, pending_list) {
if ( ! F_120 ( V_139 ) &&
F_77 ( V_55 , V_140 , V_2 -> V_21 ) ) {
unsigned long V_15 = F_2 ( V_2 , V_55 -> V_11 ) ;
F_80 ( V_55 , V_2 -> V_21 , V_2 , V_15 ) ;
}
F_52 ( V_55 ) ;
}
F_95 ( F_118 ( V_58 ) ) ;
return 0 ;
}
static bool
F_121 ( struct V_1 * V_2 , unsigned long V_132 , unsigned long V_133 )
{
T_2 V_130 , V_131 ;
struct V_58 * V_58 ;
struct V_60 * V_61 ;
V_58 = V_2 -> V_9 -> V_121 -> V_122 ;
V_130 = F_3 ( V_2 , V_132 ) ;
V_131 = V_130 + ( V_133 - V_132 ) - 1 ;
F_45 ( & V_67 ) ;
V_61 = F_110 ( V_58 , V_130 , V_131 ) ;
F_46 ( & V_67 ) ;
return ! ! V_61 ;
}
void F_122 ( struct V_1 * V_2 , unsigned long V_132 , unsigned long V_133 )
{
if ( F_117 () || ! F_1 ( V_2 , false ) )
return;
if ( ! F_123 ( & V_2 -> V_21 -> V_117 ) )
return;
if ( ! F_71 ( V_104 , & V_2 -> V_21 -> V_4 ) ||
F_71 ( V_105 , & V_2 -> V_21 -> V_4 ) )
return;
if ( F_121 ( V_2 , V_132 , V_133 ) )
F_75 ( V_105 , & V_2 -> V_21 -> V_4 ) ;
}
static int F_124 ( struct V_141 * V_142 )
{
struct V_19 * V_20 = V_139 -> V_20 ;
int V_47 = - V_143 ;
F_62 ( & V_20 -> V_120 ) ;
if ( V_20 -> V_144 . V_141 )
goto V_145;
V_47 = - V_50 ;
V_142 -> V_15 = F_125 ( NULL , V_146 - V_27 , V_27 , 0 , 0 ) ;
if ( V_142 -> V_15 & ~ V_38 ) {
V_47 = V_142 -> V_15 ;
goto V_145;
}
V_47 = F_126 ( V_20 , V_142 -> V_15 , V_27 ,
V_147 | V_6 | V_148 | V_149 , & V_142 -> V_17 ) ;
if ( V_47 )
goto V_145;
F_74 () ;
V_20 -> V_144 . V_141 = V_142 ;
V_47 = 0 ;
V_145:
F_63 ( & V_20 -> V_120 ) ;
return V_47 ;
}
static struct V_141 * F_127 ( void )
{
struct V_19 * V_20 = V_139 -> V_20 ;
struct V_141 * V_142 ;
V_142 = V_20 -> V_144 . V_141 ;
if ( V_142 )
goto V_47;
V_142 = F_56 ( sizeof( * V_142 ) , V_71 ) ;
if ( F_37 ( ! V_142 ) )
goto V_98;
V_142 -> V_150 = F_56 ( F_128 ( V_151 ) * sizeof( long ) , V_71 ) ;
if ( ! V_142 -> V_150 )
goto V_152;
V_142 -> V_17 = F_129 ( V_153 ) ;
if ( ! V_142 -> V_17 )
goto V_154;
F_130 ( & V_142 -> V_155 ) ;
if ( ! F_124 ( V_142 ) )
return V_142 ;
F_131 ( V_142 -> V_17 ) ;
V_154:
F_54 ( V_142 -> V_150 ) ;
V_152:
F_54 ( V_142 ) ;
V_98:
V_142 = V_20 -> V_144 . V_141 ;
V_47:
F_132 () ;
return V_142 ;
}
void F_133 ( struct V_19 * V_20 )
{
struct V_141 * V_142 = V_20 -> V_144 . V_141 ;
if ( ! V_142 )
return;
F_23 ( V_142 -> V_17 ) ;
F_54 ( V_142 -> V_150 ) ;
F_54 ( V_142 ) ;
}
void F_134 ( void )
{
F_135 ( & V_119 ) ;
}
void F_136 ( void )
{
F_137 ( & V_119 ) ;
}
void F_138 ( struct V_19 * V_156 , struct V_19 * V_157 )
{
V_157 -> V_144 . V_141 = NULL ;
if ( F_71 ( V_104 , & V_156 -> V_4 ) ) {
F_75 ( V_104 , & V_157 -> V_4 ) ;
F_75 ( V_105 , & V_157 -> V_4 ) ;
}
}
static unsigned long F_139 ( struct V_141 * V_142 )
{
unsigned long V_158 ;
int V_159 ;
do {
V_159 = F_140 ( V_142 -> V_150 , V_151 ) ;
if ( V_159 < V_151 ) {
if ( ! F_141 ( V_159 , V_142 -> V_150 ) )
break;
V_159 = V_151 ;
continue;
}
F_142 ( V_142 -> V_155 , ( F_123 ( & V_142 -> V_160 ) < V_151 ) ) ;
} while ( V_159 >= V_151 );
V_158 = V_142 -> V_15 + ( V_159 * V_161 ) ;
F_43 ( & V_142 -> V_160 ) ;
return V_158 ;
}
static unsigned long F_143 ( struct V_55 * V_55 )
{
struct V_141 * V_142 ;
unsigned long V_11 ;
unsigned long V_162 ;
void * V_15 ;
V_142 = F_127 () ;
if ( ! V_142 )
return 0 ;
V_162 = F_139 ( V_142 ) ;
if ( F_37 ( ! V_162 ) )
return 0 ;
V_11 = V_162 & ~ V_38 ;
V_15 = F_28 ( V_142 -> V_17 ) ;
memcpy ( V_15 + V_11 , V_55 -> V_96 . V_34 , V_94 ) ;
F_29 ( V_15 ) ;
F_144 ( V_142 -> V_17 ) ;
return V_162 ;
}
static void F_145 ( struct V_163 * V_164 )
{
struct V_141 * V_142 ;
unsigned long V_165 ;
unsigned long V_158 ;
if ( ! V_164 -> V_20 || ! V_164 -> V_20 -> V_144 . V_141 || ! V_164 -> V_166 )
return;
V_158 = V_164 -> V_166 -> V_162 ;
if ( F_37 ( ! V_158 ) )
return;
V_142 = V_164 -> V_20 -> V_144 . V_141 ;
V_165 = V_142 -> V_15 + V_27 ;
if ( V_142 -> V_15 <= V_158 && V_158 < V_165 ) {
unsigned long V_11 ;
int V_159 ;
V_11 = V_158 - V_142 -> V_15 ;
V_159 = V_11 / V_161 ;
if ( V_159 >= V_151 )
return;
F_81 ( V_159 , V_142 -> V_150 ) ;
F_146 ( & V_142 -> V_160 ) ;
if ( F_147 ( & V_142 -> V_155 ) )
F_148 ( & V_142 -> V_155 ) ;
V_164 -> V_166 -> V_162 = 0 ;
}
}
unsigned long __weak F_149 ( struct V_167 * V_168 )
{
return F_150 ( V_168 ) - V_39 ;
}
void F_151 ( struct V_163 * V_136 )
{
struct V_169 * V_166 = V_136 -> V_166 ;
if ( ! V_166 )
return;
if ( V_166 -> V_170 )
F_52 ( V_166 -> V_170 ) ;
F_145 ( V_136 ) ;
F_54 ( V_166 ) ;
V_136 -> V_166 = NULL ;
}
void F_152 ( struct V_163 * V_136 )
{
V_136 -> V_166 = NULL ;
}
static struct V_169 * F_153 ( void )
{
if ( ! V_139 -> V_166 )
V_139 -> V_166 = F_56 ( sizeof( struct V_169 ) , V_71 ) ;
return V_139 -> V_166 ;
}
static int
F_154 ( struct V_55 * V_55 , struct V_167 * V_168 , unsigned long V_171 )
{
struct V_169 * V_166 ;
unsigned long V_162 ;
int V_24 ;
V_166 = F_153 () ;
if ( ! V_166 )
return - V_50 ;
V_162 = F_143 ( V_55 ) ;
if ( ! V_162 )
return - V_50 ;
V_166 -> V_162 = V_162 ;
V_166 -> V_15 = V_171 ;
V_24 = F_155 ( & V_55 -> V_96 , V_168 ) ;
if ( F_37 ( V_24 ) ) {
F_145 ( V_139 ) ;
return V_24 ;
}
V_166 -> V_170 = V_55 ;
V_166 -> V_172 = V_173 ;
return 0 ;
}
bool F_156 ( void )
{
struct V_163 * V_136 = V_139 ;
struct V_169 * V_166 = V_136 -> V_166 ;
if ( F_106 ( ! V_166 || ! V_166 -> V_170 ) )
return false ;
F_157 ( V_166 -> V_172 != V_173 ) ;
if ( F_158 ( V_136 ) ) {
F_159 ( & V_136 -> V_174 -> V_175 ) ;
F_160 ( V_136 , V_176 ) ;
F_161 ( & V_136 -> V_174 -> V_175 ) ;
if ( F_162 ( V_136 ) || F_163 ( V_136 ) ) {
V_166 -> V_172 = V_177 ;
F_164 ( V_136 , V_178 ) ;
F_164 ( V_136 , V_179 ) ;
}
}
return true ;
}
static bool F_165 ( struct V_55 * V_55 , struct V_167 * V_168 )
{
if ( F_71 ( V_74 , & V_55 -> V_4 ) ) {
if ( F_166 ( & V_55 -> V_96 , V_168 ) )
return true ;
F_81 ( V_74 , & V_55 -> V_4 ) ;
}
return false ;
}
static void F_167 ( struct V_19 * V_20 )
{
struct V_1 * V_2 ;
for ( V_2 = V_20 -> V_127 ; V_2 ; V_2 = V_2 -> V_128 ) {
if ( ! F_1 ( V_2 , false ) )
continue;
if ( F_121 ( V_2 , V_2 -> V_12 , V_2 -> V_129 ) )
return;
}
F_81 ( V_104 , & V_20 -> V_4 ) ;
}
static int F_168 ( struct V_19 * V_20 , unsigned long V_15 )
{
struct V_17 * V_17 ;
T_5 V_36 ;
int V_180 ;
F_169 () ;
V_180 = F_170 ( & V_36 , ( void V_181 * ) V_15 ,
sizeof( V_36 ) ) ;
F_171 () ;
if ( F_106 ( V_180 == 0 ) )
goto V_98;
V_180 = F_32 ( NULL , V_20 , V_15 , 1 , 0 , 1 , & V_17 , NULL ) ;
if ( V_180 < 0 )
return V_180 ;
F_27 ( V_17 , V_15 , & V_36 ) ;
F_23 ( V_17 ) ;
V_98:
return F_26 ( & V_36 ) ;
}
static struct V_55 * F_172 ( unsigned long V_171 , int * V_42 )
{
struct V_19 * V_20 = V_139 -> V_20 ;
struct V_55 * V_55 = NULL ;
struct V_1 * V_2 ;
F_78 ( & V_20 -> V_120 ) ;
V_2 = F_100 ( V_20 , V_171 ) ;
if ( V_2 && V_2 -> V_12 <= V_171 ) {
if ( F_1 ( V_2 , false ) ) {
struct V_58 * V_58 = V_2 -> V_9 -> V_121 -> V_122 ;
T_2 V_11 = F_3 ( V_2 , V_171 ) ;
V_55 = F_44 ( V_58 , V_11 ) ;
}
if ( ! V_55 )
* V_42 = F_168 ( V_20 , V_171 ) ;
} else {
* V_42 = - V_182 ;
}
if ( ! V_55 && F_173 ( V_105 , & V_20 -> V_4 ) )
F_167 ( V_20 ) ;
F_79 ( & V_20 -> V_120 ) ;
return V_55 ;
}
static void F_174 ( struct V_55 * V_55 , struct V_167 * V_168 )
{
struct V_75 * V_76 ;
int remove = V_183 ;
F_78 ( & V_55 -> V_72 ) ;
for ( V_76 = V_55 -> V_78 ; V_76 ; V_76 = V_76 -> V_77 ) {
int V_184 = V_76 -> V_185 ( V_76 , V_168 ) ;
F_175 ( V_184 & ~ V_186 ,
L_1 , V_184 , V_76 -> V_185 ) ;
remove &= V_184 ;
}
if ( remove && V_55 -> V_78 ) {
F_86 ( ! F_83 ( V_55 ) ) ;
F_109 ( V_55 , V_139 -> V_20 ) ;
}
F_79 ( & V_55 -> V_72 ) ;
}
static void F_176 ( struct V_167 * V_168 )
{
struct V_55 * V_55 ;
unsigned long V_171 ;
int V_187 ( V_42 ) ;
V_171 = F_149 ( V_168 ) ;
V_55 = F_172 ( V_171 , & V_42 ) ;
if ( ! V_55 ) {
if ( V_42 > 0 ) {
F_177 ( V_188 , V_139 , 0 ) ;
} else {
F_178 ( V_168 , V_171 ) ;
}
return;
}
F_178 ( V_168 , V_171 ) ;
F_179 () ;
if ( F_37 ( ! F_71 ( V_97 , & V_55 -> V_4 ) ) )
goto V_98;
F_174 ( V_55 , V_168 ) ;
if ( F_165 ( V_55 , V_168 ) )
goto V_98;
if ( ! F_154 ( V_55 , V_168 , V_171 ) )
return;
V_98:
F_52 ( V_55 ) ;
}
static void F_180 ( struct V_169 * V_166 , struct V_167 * V_168 )
{
struct V_55 * V_55 ;
V_55 = V_166 -> V_170 ;
if ( V_166 -> V_172 == V_189 )
F_181 ( & V_55 -> V_96 , V_168 ) ;
else if ( V_166 -> V_172 == V_177 )
F_182 ( & V_55 -> V_96 , V_168 ) ;
else
F_157 ( 1 ) ;
F_52 ( V_55 ) ;
V_166 -> V_170 = NULL ;
V_166 -> V_172 = V_190 ;
F_145 ( V_139 ) ;
F_159 ( & V_139 -> V_174 -> V_175 ) ;
F_183 () ;
F_161 ( & V_139 -> V_174 -> V_175 ) ;
}
void F_184 ( struct V_167 * V_168 )
{
struct V_169 * V_166 ;
F_185 ( V_178 ) ;
V_166 = V_139 -> V_166 ;
if ( V_166 && V_166 -> V_170 )
F_180 ( V_166 , V_168 ) ;
else
F_176 ( V_168 ) ;
}
int F_186 ( struct V_167 * V_168 )
{
if ( ! V_139 -> V_20 || ! F_71 ( V_104 , & V_139 -> V_20 -> V_4 ) )
return 0 ;
F_187 ( V_178 ) ;
return 1 ;
}
int F_188 ( struct V_167 * V_168 )
{
struct V_169 * V_166 = V_139 -> V_166 ;
if ( ! V_139 -> V_20 || ! V_166 || ! V_166 -> V_170 )
return 0 ;
V_166 -> V_172 = V_189 ;
F_187 ( V_178 ) ;
return 1 ;
}
static int T_7 F_189 ( void )
{
int V_191 ;
for ( V_191 = 0 ; V_191 < V_192 ; V_191 ++ )
F_190 ( & V_193 [ V_191 ] ) ;
if ( F_191 ( & V_119 ) )
return - V_50 ;
return F_192 ( & V_194 ) ;
}
static void T_8 F_193 ( void )
{
}
