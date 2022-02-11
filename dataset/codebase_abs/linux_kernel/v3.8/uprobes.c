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
F_52 ( V_70 , & V_55 -> V_4 ) ;
return V_59 ;
}
static void F_53 ( struct V_55 * V_55 )
{
if ( F_54 ( & V_55 -> V_64 ) )
F_55 ( V_55 ) ;
}
static struct V_55 * F_56 ( struct V_58 * V_58 , T_2 V_11 )
{
struct V_55 * V_55 , * V_71 ;
V_55 = F_57 ( sizeof( struct V_55 ) , V_72 ) ;
if ( ! V_55 )
return NULL ;
V_55 -> V_58 = F_58 ( V_58 ) ;
V_55 -> V_11 = V_11 ;
F_59 ( & V_55 -> V_73 ) ;
F_60 ( & V_55 -> V_74 ) ;
V_71 = F_51 ( V_55 ) ;
if ( V_71 ) {
F_55 ( V_55 ) ;
V_55 = V_71 ;
F_61 ( V_58 ) ;
} else {
F_43 ( & V_75 ) ;
}
return V_55 ;
}
static void F_62 ( struct V_55 * V_55 , struct V_76 * V_77 )
{
struct V_78 * V_79 ;
if ( ! F_63 ( V_80 , & V_55 -> V_4 ) )
return;
F_64 ( & V_55 -> V_73 ) ;
for ( V_79 = V_55 -> V_81 ; V_79 ; V_79 = V_79 -> V_82 ) {
if ( ! V_79 -> V_83 || V_79 -> V_83 ( V_79 , V_84 ) )
V_79 -> V_85 ( V_79 , V_77 ) ;
}
F_65 ( & V_55 -> V_73 ) ;
}
static struct V_78 *
F_66 ( struct V_55 * V_55 , struct V_78 * V_79 )
{
F_67 ( & V_55 -> V_73 ) ;
V_79 -> V_82 = V_55 -> V_81 ;
V_55 -> V_81 = V_79 ;
F_68 ( & V_55 -> V_73 ) ;
return V_79 -> V_82 ;
}
static bool F_69 ( struct V_55 * V_55 , struct V_78 * V_79 )
{
struct V_78 * * V_86 ;
bool V_47 = false ;
F_67 ( & V_55 -> V_73 ) ;
for ( V_86 = & V_55 -> V_81 ; * V_86 ; V_86 = & ( * V_86 ) -> V_82 ) {
if ( * V_86 == V_79 ) {
* V_86 = V_79 -> V_82 ;
V_47 = true ;
break;
}
}
F_68 ( & V_55 -> V_73 ) ;
return V_47 ;
}
static int
F_70 ( struct V_87 * V_88 , struct V_89 * V_90 , char * V_34 ,
unsigned long V_91 , T_2 V_11 )
{
struct V_17 * V_17 ;
void * V_15 ;
unsigned long V_92 ;
T_6 V_93 ;
if ( ! V_90 )
return - V_94 ;
if ( ! V_88 -> V_95 -> V_96 )
return - V_97 ;
V_93 = V_11 >> V_98 ;
V_92 = V_11 & ~ V_38 ;
V_17 = F_71 ( V_88 , V_93 , V_90 ) ;
if ( F_72 ( V_17 ) )
return F_73 ( V_17 ) ;
V_15 = F_28 ( V_17 ) ;
memcpy ( V_34 , V_15 + V_92 , V_91 ) ;
F_29 ( V_15 ) ;
F_36 ( V_17 ) ;
return 0 ;
}
static int F_74 ( struct V_55 * V_55 , struct V_89 * V_90 )
{
struct V_87 * V_88 ;
unsigned long V_91 ;
int V_99 ;
V_91 = V_27 - ( V_55 -> V_11 & ~ V_38 ) ;
V_88 = V_55 -> V_58 -> V_100 ;
if ( V_55 -> V_11 + V_101 > V_55 -> V_58 -> V_102 )
V_99 = V_55 -> V_58 -> V_102 - V_55 -> V_11 ;
else
V_99 = V_101 ;
if ( V_91 < V_99 ) {
int V_24 = F_70 ( V_88 , V_90 , V_55 -> V_103 . V_34 + V_91 ,
V_99 - V_91 , V_55 -> V_11 + V_91 ) ;
if ( V_24 )
return V_24 ;
V_99 = V_91 ;
}
return F_70 ( V_88 , V_90 , V_55 -> V_103 . V_34 , V_99 , V_55 -> V_11 ) ;
}
static int F_75 ( struct V_55 * V_55 , struct V_89 * V_89 ,
struct V_19 * V_20 , unsigned long V_15 )
{
int V_47 = 0 ;
if ( F_63 ( V_104 , & V_55 -> V_4 ) )
return V_47 ;
F_76 ( & V_55 -> V_74 ) ;
if ( F_63 ( V_104 , & V_55 -> V_4 ) )
goto V_105;
V_47 = F_74 ( V_55 , V_89 ) ;
if ( V_47 )
goto V_105;
V_47 = - V_106 ;
if ( F_26 ( ( T_5 * ) V_55 -> V_103 . V_34 ) )
goto V_105;
V_47 = F_77 ( & V_55 -> V_103 , V_20 , V_15 ) ;
if ( V_47 )
goto V_105;
F_78 ( ( V_55 -> V_11 & ~ V_38 ) +
V_39 > V_27 ) ;
F_79 () ;
F_80 ( V_104 , & V_55 -> V_4 ) ;
V_105:
F_81 ( & V_55 -> V_74 ) ;
return V_47 ;
}
static int
F_82 ( struct V_55 * V_55 , struct V_19 * V_20 ,
struct V_1 * V_2 , unsigned long V_15 )
{
bool V_107 ;
int V_47 ;
if ( ! V_55 -> V_81 )
return 0 ;
V_47 = F_75 ( V_55 , V_2 -> V_9 , V_20 , V_15 ) ;
if ( V_47 )
return V_47 ;
V_107 = ! F_63 ( V_108 , & V_20 -> V_4 ) ;
if ( V_107 )
F_80 ( V_108 , & V_20 -> V_4 ) ;
V_47 = F_38 ( & V_55 -> V_103 , V_20 , V_15 ) ;
if ( ! V_47 )
F_83 ( V_109 , & V_20 -> V_4 ) ;
else if ( V_107 )
F_83 ( V_108 , & V_20 -> V_4 ) ;
return V_47 ;
}
static int
F_84 ( struct V_55 * V_55 , struct V_19 * V_20 , unsigned long V_15 )
{
if ( ! F_63 ( V_108 , & V_20 -> V_4 ) )
return 0 ;
F_80 ( V_109 , & V_20 -> V_4 ) ;
return F_39 ( & V_55 -> V_103 , V_20 , V_15 ) ;
}
static void F_85 ( struct V_55 * V_55 )
{
F_45 ( & V_67 ) ;
F_86 ( & V_55 -> V_60 , & V_62 ) ;
F_46 ( & V_67 ) ;
F_61 ( V_55 -> V_58 ) ;
F_53 ( V_55 ) ;
F_87 ( & V_75 ) ;
}
static inline struct V_110 * F_88 ( struct V_110 * V_111 )
{
struct V_110 * V_82 = V_111 -> V_82 ;
F_55 ( V_111 ) ;
return V_82 ;
}
static struct V_110 *
F_89 ( struct V_87 * V_88 , T_2 V_11 , bool V_3 )
{
unsigned long V_112 = V_11 >> V_14 ;
struct V_1 * V_2 ;
struct V_110 * V_113 = NULL ;
struct V_110 * V_114 = NULL ;
struct V_110 * V_111 ;
int V_115 = 0 ;
V_116:
F_76 ( & V_88 -> V_117 ) ;
F_90 (vma, &mapping->i_mmap, pgoff, pgoff) {
if ( ! F_1 ( V_2 , V_3 ) )
continue;
if ( ! V_114 && ! V_115 ) {
V_114 = F_91 ( sizeof( struct V_110 ) ,
V_118 | V_119 | V_120 ) ;
if ( V_114 )
V_114 -> V_82 = NULL ;
}
if ( ! V_114 ) {
V_115 ++ ;
continue;
}
if ( ! F_92 ( & V_2 -> V_21 -> V_121 ) )
continue;
V_111 = V_114 ;
V_114 = V_114 -> V_82 ;
V_111 -> V_82 = V_113 ;
V_113 = V_111 ;
V_111 -> V_20 = V_2 -> V_21 ;
V_111 -> V_15 = F_2 ( V_2 , V_11 ) ;
}
F_81 ( & V_88 -> V_117 ) ;
if ( ! V_115 )
goto V_105;
V_114 = V_113 ;
while ( V_113 ) {
F_93 ( V_113 -> V_20 ) ;
V_113 = V_113 -> V_82 ;
}
do {
V_111 = F_91 ( sizeof( struct V_110 ) , V_72 ) ;
if ( ! V_111 ) {
V_113 = F_94 ( - V_50 ) ;
goto V_105;
}
V_111 -> V_82 = V_114 ;
V_114 = V_111 ;
} while ( -- V_115 );
goto V_116;
V_105:
while ( V_114 )
V_114 = F_88 ( V_114 ) ;
return V_113 ;
}
static int F_95 ( struct V_55 * V_55 , bool V_3 )
{
struct V_110 * V_111 ;
int V_24 = 0 ;
F_96 ( & V_122 ) ;
V_111 = F_89 ( V_55 -> V_58 -> V_100 ,
V_55 -> V_11 , V_3 ) ;
if ( F_72 ( V_111 ) ) {
V_24 = F_73 ( V_111 ) ;
goto V_105;
}
while ( V_111 ) {
struct V_19 * V_20 = V_111 -> V_20 ;
struct V_1 * V_2 ;
if ( V_24 && V_3 )
goto free;
F_67 ( & V_20 -> V_123 ) ;
V_2 = F_97 ( V_20 , V_111 -> V_15 ) ;
if ( ! V_2 || ! F_1 ( V_2 , V_3 ) ||
V_2 -> V_9 -> V_124 -> V_125 != V_55 -> V_58 )
goto V_29;
if ( V_2 -> V_12 > V_111 -> V_15 ||
F_3 ( V_2 , V_111 -> V_15 ) != V_55 -> V_11 )
goto V_29;
if ( V_3 )
V_24 = F_82 ( V_55 , V_20 , V_2 , V_111 -> V_15 ) ;
else
V_24 |= F_84 ( V_55 , V_20 , V_111 -> V_15 ) ;
V_29:
F_68 ( & V_20 -> V_123 ) ;
free:
F_93 ( V_20 ) ;
V_111 = F_88 ( V_111 ) ;
}
V_105:
F_98 ( & V_122 ) ;
return V_24 ;
}
static int F_99 ( struct V_55 * V_55 )
{
return F_95 ( V_55 , true ) ;
}
static void F_100 ( struct V_55 * V_55 )
{
if ( ! F_95 ( V_55 , false ) )
F_85 ( V_55 ) ;
}
int F_101 ( struct V_58 * V_58 , T_2 V_11 , struct V_78 * V_79 )
{
struct V_55 * V_55 ;
int V_47 ;
if ( ! V_58 || ! V_79 || V_79 -> V_82 )
return - V_94 ;
if ( V_11 > F_102 ( V_58 ) )
return - V_94 ;
V_47 = 0 ;
F_76 ( F_103 ( V_58 ) ) ;
V_55 = F_56 ( V_58 , V_11 ) ;
if ( ! V_55 ) {
V_47 = - V_50 ;
} else if ( ! F_66 ( V_55 , V_79 ) ) {
V_47 = F_99 ( V_55 ) ;
if ( V_47 ) {
V_55 -> V_81 = NULL ;
F_100 ( V_55 ) ;
} else {
F_80 ( V_80 , & V_55 -> V_4 ) ;
}
}
F_81 ( F_103 ( V_58 ) ) ;
if ( V_55 )
F_53 ( V_55 ) ;
return V_47 ;
}
void F_104 ( struct V_58 * V_58 , T_2 V_11 , struct V_78 * V_79 )
{
struct V_55 * V_55 ;
if ( ! V_58 || ! V_79 )
return;
V_55 = F_44 ( V_58 , V_11 ) ;
if ( ! V_55 )
return;
F_76 ( F_103 ( V_58 ) ) ;
if ( F_69 ( V_55 , V_79 ) ) {
if ( ! V_55 -> V_81 ) {
F_100 ( V_55 ) ;
F_83 ( V_80 , & V_55 -> V_4 ) ;
}
}
F_81 ( F_103 ( V_58 ) ) ;
if ( V_55 )
F_53 ( V_55 ) ;
}
static struct V_60 *
F_105 ( struct V_58 * V_58 , T_2 V_126 , T_2 V_127 )
{
struct V_60 * V_61 = V_62 . V_60 ;
while ( V_61 ) {
struct V_55 * V_59 = F_42 ( V_61 , struct V_55 , V_60 ) ;
if ( V_58 < V_59 -> V_58 ) {
V_61 = V_61 -> V_65 ;
} else if ( V_58 > V_59 -> V_58 ) {
V_61 = V_61 -> V_66 ;
} else {
if ( V_127 < V_59 -> V_11 )
V_61 = V_61 -> V_65 ;
else if ( V_126 > V_59 -> V_11 )
V_61 = V_61 -> V_66 ;
else
break;
}
}
return V_61 ;
}
static void F_106 ( struct V_58 * V_58 ,
struct V_1 * V_2 ,
unsigned long V_128 , unsigned long V_129 ,
struct V_130 * V_131 )
{
T_2 V_126 , V_127 ;
struct V_60 * V_61 , * V_132 ;
struct V_55 * V_59 ;
F_107 ( V_131 ) ;
V_126 = F_3 ( V_2 , V_128 ) ;
V_127 = V_126 + ( V_129 - V_128 ) - 1 ;
F_45 ( & V_67 ) ;
V_61 = F_105 ( V_58 , V_126 , V_127 ) ;
if ( V_61 ) {
for ( V_132 = V_61 ; V_132 ; V_132 = F_108 ( V_132 ) ) {
V_59 = F_42 ( V_132 , struct V_55 , V_60 ) ;
if ( V_59 -> V_58 != V_58 || V_59 -> V_11 < V_126 )
break;
F_109 ( & V_59 -> V_133 , V_131 ) ;
F_43 ( & V_59 -> V_64 ) ;
}
for ( V_132 = V_61 ; ( V_132 = F_110 ( V_132 ) ) ; ) {
V_59 = F_42 ( V_132 , struct V_55 , V_60 ) ;
if ( V_59 -> V_58 != V_58 || V_59 -> V_11 > V_127 )
break;
F_109 ( & V_59 -> V_133 , V_131 ) ;
F_43 ( & V_59 -> V_64 ) ;
}
}
F_46 ( & V_67 ) ;
}
int F_111 ( struct V_1 * V_2 )
{
struct V_130 V_134 ;
struct V_55 * V_55 , * V_59 ;
struct V_58 * V_58 ;
if ( ! F_112 ( & V_75 ) || ! F_1 ( V_2 , true ) )
return 0 ;
V_58 = V_2 -> V_9 -> V_124 -> V_125 ;
if ( ! V_58 )
return 0 ;
F_76 ( F_113 ( V_58 ) ) ;
F_106 ( V_58 , V_2 , V_2 -> V_12 , V_2 -> V_135 , & V_134 ) ;
F_114 (uprobe, u, &tmp_list, pending_list) {
if ( ! F_115 ( V_84 ) ) {
unsigned long V_15 = F_2 ( V_2 , V_55 -> V_11 ) ;
F_82 ( V_55 , V_2 -> V_21 , V_2 , V_15 ) ;
}
F_53 ( V_55 ) ;
}
F_81 ( F_113 ( V_58 ) ) ;
return 0 ;
}
static bool
F_116 ( struct V_1 * V_2 , unsigned long V_128 , unsigned long V_129 )
{
T_2 V_126 , V_127 ;
struct V_58 * V_58 ;
struct V_60 * V_61 ;
V_58 = V_2 -> V_9 -> V_124 -> V_125 ;
V_126 = F_3 ( V_2 , V_128 ) ;
V_127 = V_126 + ( V_129 - V_128 ) - 1 ;
F_45 ( & V_67 ) ;
V_61 = F_105 ( V_58 , V_126 , V_127 ) ;
F_46 ( & V_67 ) ;
return ! ! V_61 ;
}
void F_117 ( struct V_1 * V_2 , unsigned long V_128 , unsigned long V_129 )
{
if ( ! F_112 ( & V_75 ) || ! F_1 ( V_2 , false ) )
return;
if ( ! F_112 ( & V_2 -> V_21 -> V_121 ) )
return;
if ( ! F_63 ( V_108 , & V_2 -> V_21 -> V_4 ) ||
F_63 ( V_109 , & V_2 -> V_21 -> V_4 ) )
return;
if ( F_116 ( V_2 , V_128 , V_129 ) )
F_80 ( V_109 , & V_2 -> V_21 -> V_4 ) ;
}
static int F_118 ( struct V_136 * V_137 )
{
struct V_19 * V_20 ;
int V_47 ;
V_137 -> V_17 = F_119 ( V_138 ) ;
if ( ! V_137 -> V_17 )
return - V_50 ;
V_47 = - V_139 ;
V_20 = V_84 -> V_20 ;
F_67 ( & V_20 -> V_123 ) ;
if ( V_20 -> V_140 . V_136 )
goto V_141;
V_47 = - V_50 ;
V_137 -> V_15 = F_120 ( NULL , V_142 - V_27 , V_27 , 0 , 0 ) ;
if ( V_137 -> V_15 & ~ V_38 ) {
V_47 = V_137 -> V_15 ;
goto V_141;
}
V_47 = F_121 ( V_20 , V_137 -> V_15 , V_27 ,
V_143 | V_6 | V_144 | V_145 , & V_137 -> V_17 ) ;
if ( V_47 )
goto V_141;
F_79 () ;
V_20 -> V_140 . V_136 = V_137 ;
V_47 = 0 ;
V_141:
F_68 ( & V_20 -> V_123 ) ;
if ( V_47 )
F_122 ( V_137 -> V_17 ) ;
return V_47 ;
}
static struct V_136 * F_123 ( struct V_19 * V_20 )
{
struct V_136 * V_137 ;
V_137 = V_20 -> V_140 . V_136 ;
F_124 () ;
return V_137 ;
}
static struct V_136 * F_125 ( void )
{
struct V_136 * V_137 ;
V_137 = F_57 ( sizeof( * V_137 ) , V_72 ) ;
if ( F_37 ( ! V_137 ) )
return NULL ;
V_137 -> V_146 = F_57 ( F_126 ( V_147 ) * sizeof( long ) , V_72 ) ;
if ( ! V_137 -> V_146 )
goto V_141;
F_127 ( & V_137 -> V_148 ) ;
if ( ! F_118 ( V_137 ) )
return V_137 ;
V_141:
F_55 ( V_137 -> V_146 ) ;
F_55 ( V_137 ) ;
return F_123 ( V_84 -> V_20 ) ;
}
void F_128 ( struct V_19 * V_20 )
{
struct V_136 * V_137 = V_20 -> V_140 . V_136 ;
if ( ! V_137 )
return;
F_23 ( V_137 -> V_17 ) ;
F_55 ( V_137 -> V_146 ) ;
F_55 ( V_137 ) ;
}
void F_129 ( void )
{
F_130 ( & V_122 ) ;
}
void F_131 ( void )
{
F_132 ( & V_122 ) ;
}
void F_133 ( struct V_19 * V_149 , struct V_19 * V_150 )
{
V_150 -> V_140 . V_136 = NULL ;
if ( F_63 ( V_108 , & V_149 -> V_4 ) ) {
F_80 ( V_108 , & V_150 -> V_4 ) ;
F_80 ( V_109 , & V_150 -> V_4 ) ;
}
}
static unsigned long F_134 ( struct V_136 * V_137 )
{
unsigned long V_151 ;
int V_152 ;
do {
V_152 = F_135 ( V_137 -> V_146 , V_147 ) ;
if ( V_152 < V_147 ) {
if ( ! F_136 ( V_152 , V_137 -> V_146 ) )
break;
V_152 = V_147 ;
continue;
}
F_137 ( V_137 -> V_148 , ( F_112 ( & V_137 -> V_153 ) < V_147 ) ) ;
} while ( V_152 >= V_147 );
V_151 = V_137 -> V_15 + ( V_152 * V_154 ) ;
F_43 ( & V_137 -> V_153 ) ;
return V_151 ;
}
static unsigned long F_138 ( struct V_55 * V_55 , unsigned long V_151 )
{
struct V_136 * V_137 ;
unsigned long V_11 ;
void * V_15 ;
V_137 = F_123 ( V_84 -> V_20 ) ;
if ( ! V_137 ) {
V_137 = F_125 () ;
if ( ! V_137 )
return 0 ;
}
V_84 -> V_155 -> V_156 = F_134 ( V_137 ) ;
if ( F_37 ( ! V_84 -> V_155 -> V_156 ) )
return 0 ;
V_84 -> V_155 -> V_15 = V_151 ;
V_11 = V_84 -> V_155 -> V_156 & ~ V_38 ;
V_15 = F_28 ( V_137 -> V_17 ) ;
memcpy ( V_15 + V_11 , V_55 -> V_103 . V_34 , V_101 ) ;
F_29 ( V_15 ) ;
F_139 ( V_137 -> V_17 ) ;
return V_84 -> V_155 -> V_156 ;
}
static void F_140 ( struct V_157 * V_158 )
{
struct V_136 * V_137 ;
unsigned long V_159 ;
unsigned long V_151 ;
if ( ! V_158 -> V_20 || ! V_158 -> V_20 -> V_140 . V_136 || ! V_158 -> V_155 )
return;
V_151 = V_158 -> V_155 -> V_156 ;
if ( F_37 ( ! V_151 || F_141 ( V_151 ) ) )
return;
V_137 = V_158 -> V_20 -> V_140 . V_136 ;
V_159 = V_137 -> V_15 + V_27 ;
if ( V_137 -> V_15 <= V_151 && V_151 < V_159 ) {
unsigned long V_11 ;
int V_152 ;
V_11 = V_151 - V_137 -> V_15 ;
V_152 = V_11 / V_154 ;
if ( V_152 >= V_147 )
return;
F_83 ( V_152 , V_137 -> V_146 ) ;
F_87 ( & V_137 -> V_153 ) ;
if ( F_142 ( & V_137 -> V_148 ) )
F_143 ( & V_137 -> V_148 ) ;
V_158 -> V_155 -> V_156 = 0 ;
}
}
unsigned long __weak F_144 ( struct V_76 * V_77 )
{
return F_145 ( V_77 ) - V_39 ;
}
void F_146 ( struct V_157 * V_132 )
{
struct V_160 * V_155 = V_132 -> V_155 ;
if ( ! V_155 )
return;
if ( V_155 -> V_161 )
F_53 ( V_155 -> V_161 ) ;
F_140 ( V_132 ) ;
F_55 ( V_155 ) ;
V_132 -> V_155 = NULL ;
}
void F_147 ( struct V_157 * V_132 )
{
V_132 -> V_155 = NULL ;
}
static struct V_160 * F_148 ( void )
{
struct V_160 * V_155 ;
V_155 = F_57 ( sizeof *V_155 , V_72 ) ;
if ( F_37 ( ! V_155 ) )
return NULL ;
V_84 -> V_155 = V_155 ;
return V_155 ;
}
static int
F_149 ( struct V_55 * V_55 , struct V_76 * V_77 , unsigned long V_15 )
{
if ( F_138 ( V_55 , V_15 ) && ! F_150 ( & V_55 -> V_103 , V_77 ) )
return 0 ;
return - V_162 ;
}
bool F_151 ( void )
{
struct V_157 * V_132 = V_84 ;
struct V_160 * V_155 = V_132 -> V_155 ;
if ( F_152 ( ! V_155 || ! V_155 -> V_161 ) )
return false ;
F_153 ( V_155 -> V_163 != V_164 ) ;
if ( F_154 ( V_132 ) ) {
F_155 ( & V_132 -> V_165 -> V_166 ) ;
F_156 ( V_132 , V_167 ) ;
F_157 ( & V_132 -> V_165 -> V_166 ) ;
if ( F_158 ( V_132 ) || F_159 ( V_132 ) ) {
V_155 -> V_163 = V_168 ;
F_160 ( V_132 , V_169 ) ;
F_160 ( V_132 , V_170 ) ;
}
}
return true ;
}
static bool F_161 ( struct V_55 * V_55 , struct V_76 * V_77 )
{
if ( F_63 ( V_70 , & V_55 -> V_4 ) ) {
if ( F_162 ( & V_55 -> V_103 , V_77 ) )
return true ;
F_83 ( V_70 , & V_55 -> V_4 ) ;
}
return false ;
}
static void F_163 ( struct V_19 * V_20 )
{
struct V_1 * V_2 ;
for ( V_2 = V_20 -> V_171 ; V_2 ; V_2 = V_2 -> V_172 ) {
if ( ! F_1 ( V_2 , false ) )
continue;
if ( F_116 ( V_2 , V_2 -> V_12 , V_2 -> V_135 ) )
return;
}
F_83 ( V_108 , & V_20 -> V_4 ) ;
}
static int F_164 ( struct V_19 * V_20 , unsigned long V_15 )
{
struct V_17 * V_17 ;
T_5 V_36 ;
int V_173 ;
F_165 () ;
V_173 = F_166 ( & V_36 , ( void V_174 * ) V_15 ,
sizeof( V_36 ) ) ;
F_167 () ;
if ( F_152 ( V_173 == 0 ) )
goto V_105;
V_173 = F_32 ( NULL , V_20 , V_15 , 1 , 0 , 1 , & V_17 , NULL ) ;
if ( V_173 < 0 )
return V_173 ;
F_27 ( V_17 , V_15 , & V_36 ) ;
F_23 ( V_17 ) ;
V_105:
return F_26 ( & V_36 ) ;
}
static struct V_55 * F_168 ( unsigned long V_175 , int * V_42 )
{
struct V_19 * V_20 = V_84 -> V_20 ;
struct V_55 * V_55 = NULL ;
struct V_1 * V_2 ;
F_64 ( & V_20 -> V_123 ) ;
V_2 = F_97 ( V_20 , V_175 ) ;
if ( V_2 && V_2 -> V_12 <= V_175 ) {
if ( F_1 ( V_2 , false ) ) {
struct V_58 * V_58 = V_2 -> V_9 -> V_124 -> V_125 ;
T_2 V_11 = F_3 ( V_2 , V_175 ) ;
V_55 = F_44 ( V_58 , V_11 ) ;
}
if ( ! V_55 )
* V_42 = F_164 ( V_20 , V_175 ) ;
} else {
* V_42 = - V_162 ;
}
if ( ! V_55 && F_169 ( V_109 , & V_20 -> V_4 ) )
F_163 ( V_20 ) ;
F_65 ( & V_20 -> V_123 ) ;
return V_55 ;
}
static void F_170 ( struct V_76 * V_77 )
{
struct V_160 * V_155 ;
struct V_55 * V_55 ;
unsigned long V_175 ;
int V_176 ( V_42 ) ;
V_175 = F_144 ( V_77 ) ;
V_55 = F_168 ( V_175 , & V_42 ) ;
if ( ! V_55 ) {
if ( V_42 > 0 ) {
F_171 ( V_177 , V_84 , 0 ) ;
} else {
F_172 ( V_77 , V_175 ) ;
}
return;
}
F_173 () ;
if ( F_37 ( ! F_63 ( V_104 , & V_55 -> V_4 ) ) )
goto V_178;
V_155 = V_84 -> V_155 ;
if ( ! V_155 ) {
V_155 = F_148 () ;
if ( ! V_155 )
goto V_178;
}
F_62 ( V_55 , V_77 ) ;
if ( F_161 ( V_55 , V_77 ) )
goto V_105;
if ( ! F_149 ( V_55 , V_77 , V_175 ) ) {
V_155 -> V_161 = V_55 ;
V_155 -> V_163 = V_164 ;
return;
}
V_178:
F_172 ( V_77 , V_175 ) ;
V_105:
F_53 ( V_55 ) ;
}
static void F_174 ( struct V_160 * V_155 , struct V_76 * V_77 )
{
struct V_55 * V_55 ;
V_55 = V_155 -> V_161 ;
if ( V_155 -> V_163 == V_179 )
F_175 ( & V_55 -> V_103 , V_77 ) ;
else if ( V_155 -> V_163 == V_168 )
F_176 ( & V_55 -> V_103 , V_77 ) ;
else
F_153 ( 1 ) ;
F_53 ( V_55 ) ;
V_155 -> V_161 = NULL ;
V_155 -> V_163 = V_180 ;
F_140 ( V_84 ) ;
F_155 ( & V_84 -> V_165 -> V_166 ) ;
F_177 () ;
F_157 ( & V_84 -> V_165 -> V_166 ) ;
}
void F_178 ( struct V_76 * V_77 )
{
struct V_160 * V_155 ;
F_179 ( V_169 ) ;
V_155 = V_84 -> V_155 ;
if ( V_155 && V_155 -> V_161 )
F_174 ( V_155 , V_77 ) ;
else
F_170 ( V_77 ) ;
}
int F_180 ( struct V_76 * V_77 )
{
if ( ! V_84 -> V_20 || ! F_63 ( V_108 , & V_84 -> V_20 -> V_4 ) )
return 0 ;
F_181 ( V_169 ) ;
return 1 ;
}
int F_182 ( struct V_76 * V_77 )
{
struct V_160 * V_155 = V_84 -> V_155 ;
if ( ! V_84 -> V_20 || ! V_155 || ! V_155 -> V_161 )
return 0 ;
V_155 -> V_163 = V_179 ;
F_181 ( V_169 ) ;
return 1 ;
}
static int T_7 F_183 ( void )
{
int V_181 ;
for ( V_181 = 0 ; V_181 < V_182 ; V_181 ++ ) {
F_60 ( & V_183 [ V_181 ] ) ;
F_60 ( & V_184 [ V_181 ] ) ;
}
if ( F_184 ( & V_122 ) )
return - V_50 ;
return F_185 ( & V_185 ) ;
}
static void T_8 F_186 ( void )
{
}
