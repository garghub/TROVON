static bool F_1 ( struct V_1 * V_2 , bool V_3 )
{
if ( ! V_2 -> V_4 )
return false ;
if ( ! V_3 )
return true ;
if ( ( V_2 -> V_5 & ( V_6 | V_7 | V_8 | V_9 | V_10 ) )
== ( V_7 | V_9 ) )
return true ;
return false ;
}
static unsigned long F_2 ( struct V_1 * V_2 , T_1 V_11 )
{
return V_2 -> V_12 + V_11 - ( ( T_1 ) V_2 -> V_13 << V_14 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , unsigned long V_15 )
{
return ( ( T_1 ) V_2 -> V_13 << V_14 ) + ( V_15 - V_2 -> V_12 ) ;
}
static int F_4 ( struct V_1 * V_2 , unsigned long V_16 ,
struct V_17 * V_17 , struct V_17 * V_18 )
{
struct V_19 * V_20 = V_2 -> V_21 ;
T_2 * V_22 ;
T_3 * V_23 ;
int V_24 ;
F_5 ( V_17 ) ;
V_24 = - V_25 ;
V_23 = F_6 ( V_17 , V_20 , V_16 , & V_22 , 0 ) ;
if ( ! V_23 )
goto V_26;
F_7 ( V_18 ) ;
F_8 ( V_18 , V_2 , V_16 ) ;
if ( ! F_9 ( V_17 ) ) {
F_10 ( V_20 , V_27 ) ;
F_11 ( V_20 , V_28 ) ;
}
F_12 ( V_2 , V_16 , F_13 ( * V_23 ) ) ;
F_14 ( V_2 , V_16 , V_23 ) ;
F_15 ( V_20 , V_16 , V_23 , F_16 ( V_18 , V_2 -> V_29 ) ) ;
F_17 ( V_17 ) ;
if ( ! F_18 ( V_17 ) )
F_19 ( V_17 ) ;
F_20 ( V_23 , V_22 ) ;
if ( V_2 -> V_5 & V_30 )
F_21 ( V_17 ) ;
F_22 ( V_17 ) ;
V_24 = 0 ;
V_26:
F_23 ( V_17 ) ;
return V_24 ;
}
bool __weak F_24 ( T_4 * V_31 )
{
return * V_31 == V_32 ;
}
static int F_25 ( struct V_33 * V_34 , struct V_19 * V_20 ,
unsigned long V_15 , T_4 V_35 )
{
struct V_17 * V_36 , * V_37 ;
void * V_38 , * V_39 ;
struct V_1 * V_2 ;
int V_40 ;
V_41:
V_40 = F_26 ( NULL , V_20 , V_15 , 1 , 0 , 0 , & V_36 , & V_2 ) ;
if ( V_40 <= 0 )
return V_40 ;
V_40 = - V_42 ;
V_37 = F_27 ( V_43 , V_2 , V_15 ) ;
if ( ! V_37 )
goto V_44;
F_28 ( V_37 ) ;
V_38 = F_29 ( V_36 ) ;
V_39 = F_29 ( V_37 ) ;
memcpy ( V_39 , V_38 , V_45 ) ;
memcpy ( V_39 + ( V_15 & ~ V_46 ) , & V_35 , V_47 ) ;
F_30 ( V_39 ) ;
F_30 ( V_38 ) ;
V_40 = F_31 ( V_2 ) ;
if ( V_40 )
goto V_48;
V_40 = F_4 ( V_2 , V_15 , V_36 , V_37 ) ;
V_48:
F_32 ( V_37 ) ;
V_44:
F_22 ( V_36 ) ;
if ( F_33 ( V_40 == - V_25 ) )
goto V_41;
return V_40 ;
}
static int F_34 ( struct V_19 * V_20 , unsigned long V_15 , T_4 * V_35 )
{
struct V_17 * V_17 ;
void * V_39 ;
int V_40 ;
V_40 = F_26 ( NULL , V_20 , V_15 , 1 , 0 , 1 , & V_17 , NULL ) ;
if ( V_40 <= 0 )
return V_40 ;
F_5 ( V_17 ) ;
V_39 = F_29 ( V_17 ) ;
V_15 &= ~ V_46 ;
memcpy ( V_35 , V_39 + V_15 , V_47 ) ;
F_30 ( V_39 ) ;
F_23 ( V_17 ) ;
F_22 ( V_17 ) ;
return 0 ;
}
static int F_35 ( struct V_19 * V_20 , unsigned long V_15 )
{
T_4 V_35 ;
int V_49 ;
if ( V_50 -> V_20 == V_20 ) {
F_36 () ;
V_49 = F_37 ( & V_35 , ( void V_51 * ) V_15 ,
sizeof( V_35 ) ) ;
F_38 () ;
if ( F_39 ( V_49 == 0 ) )
goto V_52;
}
V_49 = F_34 ( V_20 , V_15 , & V_35 ) ;
if ( V_49 )
return V_49 ;
V_52:
if ( F_24 ( & V_35 ) )
return 1 ;
return 0 ;
}
int __weak F_40 ( struct V_33 * V_34 , struct V_19 * V_20 , unsigned long V_15 )
{
int V_49 ;
V_49 = F_35 ( V_20 , V_15 ) ;
if ( V_49 == 1 )
return - V_53 ;
if ( V_49 )
return V_49 ;
return F_25 ( V_34 , V_20 , V_15 , V_32 ) ;
}
int __weak
F_41 ( struct V_33 * V_34 , struct V_19 * V_20 , unsigned long V_15 , bool V_54 )
{
if ( V_54 ) {
int V_49 ;
V_49 = F_35 ( V_20 , V_15 ) ;
if ( ! V_49 )
return - V_55 ;
if ( V_49 != 1 )
return V_49 ;
}
return F_25 ( V_34 , V_20 , V_15 , * ( T_4 * ) V_34 -> V_31 ) ;
}
static int F_42 ( struct V_56 * V_57 , struct V_56 * V_58 )
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
static struct V_56 * F_43 ( struct V_59 * V_59 , T_1 V_11 )
{
struct V_56 V_60 = { . V_59 = V_59 , . V_11 = V_11 } ;
struct V_61 * V_62 = V_63 . V_61 ;
struct V_56 * V_56 ;
int V_64 ;
while ( V_62 ) {
V_56 = F_44 ( V_62 , struct V_56 , V_61 ) ;
V_64 = F_42 ( & V_60 , V_56 ) ;
if ( ! V_64 ) {
F_45 ( & V_56 -> V_65 ) ;
return V_56 ;
}
if ( V_64 < 0 )
V_62 = V_62 -> V_66 ;
else
V_62 = V_62 -> V_67 ;
}
return NULL ;
}
static struct V_56 * F_46 ( struct V_59 * V_59 , T_1 V_11 )
{
struct V_56 * V_56 ;
unsigned long V_68 ;
F_47 ( & V_69 , V_68 ) ;
V_56 = F_43 ( V_59 , V_11 ) ;
F_48 ( & V_69 , V_68 ) ;
return V_56 ;
}
static struct V_56 * F_49 ( struct V_56 * V_56 )
{
struct V_61 * * V_70 = & V_63 . V_61 ;
struct V_61 * V_71 = NULL ;
struct V_56 * V_60 ;
int V_64 ;
while ( * V_70 ) {
V_71 = * V_70 ;
V_60 = F_44 ( V_71 , struct V_56 , V_61 ) ;
V_64 = F_42 ( V_56 , V_60 ) ;
if ( ! V_64 ) {
F_45 ( & V_60 -> V_65 ) ;
return V_60 ;
}
if ( V_64 < 0 )
V_70 = & V_71 -> V_66 ;
else
V_70 = & V_71 -> V_67 ;
}
V_60 = NULL ;
F_50 ( & V_56 -> V_61 , V_71 , V_70 ) ;
F_51 ( & V_56 -> V_61 , & V_63 ) ;
F_52 ( & V_56 -> V_65 , 2 ) ;
return V_60 ;
}
static struct V_56 * F_53 ( struct V_56 * V_56 )
{
unsigned long V_68 ;
struct V_56 * V_60 ;
F_47 ( & V_69 , V_68 ) ;
V_60 = F_49 ( V_56 ) ;
F_48 ( & V_69 , V_68 ) ;
V_56 -> V_68 |= V_72 ;
return V_60 ;
}
static void F_54 ( struct V_56 * V_56 )
{
if ( F_55 ( & V_56 -> V_65 ) )
F_56 ( V_56 ) ;
}
static struct V_56 * F_57 ( struct V_59 * V_59 , T_1 V_11 )
{
struct V_56 * V_56 , * V_73 ;
V_56 = F_58 ( sizeof( struct V_56 ) , V_74 ) ;
if ( ! V_56 )
return NULL ;
V_56 -> V_59 = F_59 ( V_59 ) ;
V_56 -> V_11 = V_11 ;
F_60 ( & V_56 -> V_75 ) ;
V_73 = F_53 ( V_56 ) ;
if ( V_73 ) {
F_56 ( V_56 ) ;
V_56 = V_73 ;
F_61 ( V_59 ) ;
} else {
F_45 ( & V_76 ) ;
}
return V_56 ;
}
static void F_62 ( struct V_56 * V_56 , struct V_77 * V_78 )
{
struct V_79 * V_80 ;
if ( ! ( V_56 -> V_68 & V_81 ) )
return;
F_63 ( & V_56 -> V_75 ) ;
for ( V_80 = V_56 -> V_82 ; V_80 ; V_80 = V_80 -> V_83 ) {
if ( ! V_80 -> V_84 || V_80 -> V_84 ( V_80 , V_50 ) )
V_80 -> V_85 ( V_80 , V_78 ) ;
}
F_64 ( & V_56 -> V_75 ) ;
}
static struct V_79 *
F_65 ( struct V_56 * V_56 , struct V_79 * V_80 )
{
F_66 ( & V_56 -> V_75 ) ;
V_80 -> V_83 = V_56 -> V_82 ;
V_56 -> V_82 = V_80 ;
F_67 ( & V_56 -> V_75 ) ;
return V_80 -> V_83 ;
}
static bool F_68 ( struct V_56 * V_56 , struct V_79 * V_80 )
{
struct V_79 * * V_86 ;
bool V_40 = false ;
F_66 ( & V_56 -> V_75 ) ;
for ( V_86 = & V_56 -> V_82 ; * V_86 ; V_86 = & ( * V_86 ) -> V_83 ) {
if ( * V_86 == V_80 ) {
* V_86 = V_80 -> V_83 ;
V_40 = true ;
break;
}
}
F_67 ( & V_56 -> V_75 ) ;
return V_40 ;
}
static int
F_69 ( struct V_87 * V_88 , struct V_89 * V_90 , char * V_31 ,
unsigned long V_91 , T_1 V_11 )
{
struct V_17 * V_17 ;
void * V_15 ;
unsigned long V_92 ;
T_5 V_93 ;
if ( ! V_90 )
return - V_55 ;
if ( ! V_88 -> V_94 -> V_95 )
return - V_96 ;
V_93 = V_11 >> V_97 ;
V_92 = V_11 & ~ V_46 ;
V_17 = F_70 ( V_88 , V_93 , V_90 ) ;
if ( F_71 ( V_17 ) )
return F_72 ( V_17 ) ;
V_15 = F_29 ( V_17 ) ;
memcpy ( V_31 , V_15 + V_92 , V_91 ) ;
F_30 ( V_15 ) ;
F_32 ( V_17 ) ;
return 0 ;
}
static int F_73 ( struct V_56 * V_56 , struct V_89 * V_90 )
{
struct V_87 * V_88 ;
unsigned long V_91 ;
int V_98 ;
V_91 = V_45 - ( V_56 -> V_11 & ~ V_46 ) ;
V_88 = V_56 -> V_59 -> V_99 ;
if ( V_56 -> V_11 + V_100 > V_56 -> V_59 -> V_101 )
V_98 = V_56 -> V_59 -> V_101 - V_56 -> V_11 ;
else
V_98 = V_100 ;
if ( V_91 < V_98 ) {
int V_24 = F_69 ( V_88 , V_90 , V_56 -> V_102 . V_31 + V_91 ,
V_98 - V_91 , V_56 -> V_11 + V_91 ) ;
if ( V_24 )
return V_24 ;
V_98 = V_91 ;
}
return F_69 ( V_88 , V_90 , V_56 -> V_102 . V_31 , V_98 , V_56 -> V_11 ) ;
}
static int
F_74 ( struct V_56 * V_56 , struct V_19 * V_20 ,
struct V_1 * V_2 , unsigned long V_15 )
{
int V_40 ;
if ( ! V_56 -> V_82 )
return - V_53 ;
if ( ! ( V_56 -> V_68 & V_103 ) ) {
V_40 = F_73 ( V_56 , V_2 -> V_4 ) ;
if ( V_40 )
return V_40 ;
if ( F_24 ( ( T_4 * ) V_56 -> V_102 . V_31 ) )
return - V_104 ;
V_40 = F_75 ( & V_56 -> V_102 , V_20 , V_15 ) ;
if ( V_40 )
return V_40 ;
F_76 ( ( V_56 -> V_11 & ~ V_46 ) +
V_47 > V_45 ) ;
V_56 -> V_68 |= V_103 ;
}
F_45 ( & V_20 -> V_105 . V_106 ) ;
V_40 = F_40 ( & V_56 -> V_102 , V_20 , V_15 ) ;
if ( V_40 )
F_77 ( & V_20 -> V_105 . V_106 ) ;
return V_40 ;
}
static void
F_78 ( struct V_56 * V_56 , struct V_19 * V_20 , unsigned long V_15 )
{
if ( ! F_41 ( & V_56 -> V_102 , V_20 , V_15 , true ) )
F_77 ( & V_20 -> V_105 . V_106 ) ;
}
static void F_79 ( struct V_56 * V_56 )
{
unsigned long V_68 ;
F_47 ( & V_69 , V_68 ) ;
F_80 ( & V_56 -> V_61 , & V_63 ) ;
F_48 ( & V_69 , V_68 ) ;
F_61 ( V_56 -> V_59 ) ;
F_54 ( V_56 ) ;
F_77 ( & V_76 ) ;
}
static inline struct V_107 * F_81 ( struct V_107 * V_108 )
{
struct V_107 * V_83 = V_108 -> V_83 ;
F_56 ( V_108 ) ;
return V_83 ;
}
static struct V_107 *
F_82 ( struct V_87 * V_88 , T_1 V_11 , bool V_3 )
{
unsigned long V_109 = V_11 >> V_14 ;
struct V_110 V_111 ;
struct V_1 * V_2 ;
struct V_107 * V_112 = NULL ;
struct V_107 * V_113 = NULL ;
struct V_107 * V_108 ;
int V_114 = 0 ;
V_115:
F_83 ( & V_88 -> V_116 ) ;
F_84 (vma, &iter, &mapping->i_mmap, pgoff, pgoff) {
if ( ! F_1 ( V_2 , V_3 ) )
continue;
if ( ! V_113 && ! V_114 ) {
V_113 = F_85 ( sizeof( struct V_107 ) ,
V_117 | V_118 | V_119 ) ;
if ( V_113 )
V_113 -> V_83 = NULL ;
}
if ( ! V_113 ) {
V_114 ++ ;
continue;
}
if ( ! F_86 ( & V_2 -> V_21 -> V_120 ) )
continue;
V_108 = V_113 ;
V_113 = V_113 -> V_83 ;
V_108 -> V_83 = V_112 ;
V_112 = V_108 ;
V_108 -> V_20 = V_2 -> V_21 ;
V_108 -> V_15 = F_2 ( V_2 , V_11 ) ;
}
F_87 ( & V_88 -> V_116 ) ;
if ( ! V_114 )
goto V_52;
V_113 = V_112 ;
while ( V_112 ) {
F_88 ( V_112 -> V_20 ) ;
V_112 = V_112 -> V_83 ;
}
do {
V_108 = F_85 ( sizeof( struct V_107 ) , V_74 ) ;
if ( ! V_108 ) {
V_112 = F_89 ( - V_42 ) ;
goto V_52;
}
V_108 -> V_83 = V_113 ;
V_113 = V_108 ;
} while ( -- V_114 );
goto V_115;
V_52:
while ( V_113 )
V_113 = F_81 ( V_113 ) ;
return V_112 ;
}
static int F_90 ( struct V_56 * V_56 , bool V_3 )
{
struct V_107 * V_108 ;
int V_24 = 0 ;
V_108 = F_82 ( V_56 -> V_59 -> V_99 ,
V_56 -> V_11 , V_3 ) ;
if ( F_71 ( V_108 ) )
return F_72 ( V_108 ) ;
while ( V_108 ) {
struct V_19 * V_20 = V_108 -> V_20 ;
struct V_1 * V_2 ;
if ( V_24 )
goto free;
F_66 ( & V_20 -> V_121 ) ;
V_2 = F_91 ( V_20 , V_108 -> V_15 ) ;
if ( ! V_2 || ! F_1 ( V_2 , V_3 ) ||
V_2 -> V_4 -> V_122 -> V_123 != V_56 -> V_59 )
goto V_26;
if ( V_2 -> V_12 > V_108 -> V_15 ||
F_3 ( V_2 , V_108 -> V_15 ) != V_56 -> V_11 )
goto V_26;
if ( V_3 ) {
V_24 = F_74 ( V_56 , V_20 , V_2 , V_108 -> V_15 ) ;
if ( V_24 == - V_53 )
V_24 = 0 ;
} else {
F_78 ( V_56 , V_20 , V_108 -> V_15 ) ;
}
V_26:
F_67 ( & V_20 -> V_121 ) ;
free:
F_88 ( V_20 ) ;
V_108 = F_81 ( V_108 ) ;
}
return V_24 ;
}
static int F_92 ( struct V_56 * V_56 )
{
return F_90 ( V_56 , true ) ;
}
static void F_93 ( struct V_56 * V_56 )
{
if ( ! F_90 ( V_56 , false ) )
F_79 ( V_56 ) ;
}
int F_94 ( struct V_59 * V_59 , T_1 V_11 , struct V_79 * V_80 )
{
struct V_56 * V_56 ;
int V_40 ;
if ( ! V_59 || ! V_80 || V_80 -> V_83 )
return - V_55 ;
if ( V_11 > F_95 ( V_59 ) )
return - V_55 ;
V_40 = 0 ;
F_83 ( F_96 ( V_59 ) ) ;
V_56 = F_57 ( V_59 , V_11 ) ;
if ( V_56 && ! F_65 ( V_56 , V_80 ) ) {
V_40 = F_92 ( V_56 ) ;
if ( V_40 ) {
V_56 -> V_82 = NULL ;
F_93 ( V_56 ) ;
} else {
V_56 -> V_68 |= V_81 ;
}
}
F_87 ( F_96 ( V_59 ) ) ;
F_54 ( V_56 ) ;
return V_40 ;
}
void F_97 ( struct V_59 * V_59 , T_1 V_11 , struct V_79 * V_80 )
{
struct V_56 * V_56 ;
if ( ! V_59 || ! V_80 )
return;
V_56 = F_46 ( V_59 , V_11 ) ;
if ( ! V_56 )
return;
F_83 ( F_96 ( V_59 ) ) ;
if ( F_68 ( V_56 , V_80 ) ) {
if ( ! V_56 -> V_82 ) {
F_93 ( V_56 ) ;
V_56 -> V_68 &= ~ V_81 ;
}
}
F_87 ( F_96 ( V_59 ) ) ;
if ( V_56 )
F_54 ( V_56 ) ;
}
static struct V_61 *
F_98 ( struct V_59 * V_59 , T_1 V_124 , T_1 V_125 )
{
struct V_61 * V_62 = V_63 . V_61 ;
while ( V_62 ) {
struct V_56 * V_60 = F_44 ( V_62 , struct V_56 , V_61 ) ;
if ( V_59 < V_60 -> V_59 ) {
V_62 = V_62 -> V_66 ;
} else if ( V_59 > V_60 -> V_59 ) {
V_62 = V_62 -> V_67 ;
} else {
if ( V_125 < V_60 -> V_11 )
V_62 = V_62 -> V_66 ;
else if ( V_124 > V_60 -> V_11 )
V_62 = V_62 -> V_67 ;
else
break;
}
}
return V_62 ;
}
static void F_99 ( struct V_59 * V_59 ,
struct V_1 * V_2 ,
unsigned long V_126 , unsigned long V_127 ,
struct V_128 * V_129 )
{
T_1 V_124 , V_125 ;
unsigned long V_68 ;
struct V_61 * V_62 , * V_130 ;
struct V_56 * V_60 ;
F_100 ( V_129 ) ;
V_124 = F_3 ( V_2 , V_126 ) ;
V_125 = V_124 + ( V_127 - V_126 ) - 1 ;
F_47 ( & V_69 , V_68 ) ;
V_62 = F_98 ( V_59 , V_124 , V_125 ) ;
if ( V_62 ) {
for ( V_130 = V_62 ; V_130 ; V_130 = F_101 ( V_130 ) ) {
V_60 = F_44 ( V_130 , struct V_56 , V_61 ) ;
if ( V_60 -> V_59 != V_59 || V_60 -> V_11 < V_124 )
break;
F_102 ( & V_60 -> V_131 , V_129 ) ;
F_45 ( & V_60 -> V_65 ) ;
}
for ( V_130 = V_62 ; ( V_130 = F_103 ( V_130 ) ) ; ) {
V_60 = F_44 ( V_130 , struct V_56 , V_61 ) ;
if ( V_60 -> V_59 != V_59 || V_60 -> V_11 > V_125 )
break;
F_102 ( & V_60 -> V_131 , V_129 ) ;
F_45 ( & V_60 -> V_65 ) ;
}
}
F_48 ( & V_69 , V_68 ) ;
}
int F_104 ( struct V_1 * V_2 )
{
struct V_128 V_132 ;
struct V_56 * V_56 , * V_60 ;
struct V_59 * V_59 ;
int V_40 , V_106 ;
if ( ! F_105 ( & V_76 ) || ! F_1 ( V_2 , true ) )
return 0 ;
V_59 = V_2 -> V_4 -> V_122 -> V_123 ;
if ( ! V_59 )
return 0 ;
F_83 ( F_106 ( V_59 ) ) ;
F_99 ( V_59 , V_2 , V_2 -> V_12 , V_2 -> V_133 , & V_132 ) ;
V_40 = 0 ;
V_106 = 0 ;
F_107 (uprobe, u, &tmp_list, pending_list) {
if ( ! V_40 ) {
unsigned long V_15 = F_2 ( V_2 , V_56 -> V_11 ) ;
V_40 = F_74 ( V_56 , V_2 -> V_21 , V_2 , V_15 ) ;
if ( V_40 == - V_53 ) {
V_40 = 0 ;
if ( ! F_35 ( V_2 -> V_21 , V_15 ) )
continue;
F_45 ( & V_2 -> V_21 -> V_105 . V_106 ) ;
}
if ( ! V_40 )
V_106 ++ ;
}
F_54 ( V_56 ) ;
}
F_87 ( F_106 ( V_59 ) ) ;
if ( V_40 )
F_108 ( V_106 , & V_2 -> V_21 -> V_105 . V_106 ) ;
return V_40 ;
}
void F_109 ( struct V_1 * V_2 , unsigned long V_126 , unsigned long V_127 )
{
struct V_128 V_132 ;
struct V_56 * V_56 , * V_60 ;
struct V_59 * V_59 ;
if ( ! F_105 ( & V_76 ) || ! F_1 ( V_2 , false ) )
return;
if ( ! F_105 ( & V_2 -> V_21 -> V_120 ) )
return;
if ( ! F_105 ( & V_2 -> V_21 -> V_105 . V_106 ) )
return;
V_59 = V_2 -> V_4 -> V_122 -> V_123 ;
if ( ! V_59 )
return;
F_83 ( F_106 ( V_59 ) ) ;
F_99 ( V_59 , V_2 , V_126 , V_127 , & V_132 ) ;
F_107 (uprobe, u, &tmp_list, pending_list) {
unsigned long V_15 = F_2 ( V_2 , V_56 -> V_11 ) ;
if ( F_35 ( V_2 -> V_21 , V_15 ) == 1 )
F_77 ( & V_2 -> V_21 -> V_105 . V_106 ) ;
F_54 ( V_56 ) ;
}
F_87 ( F_106 ( V_59 ) ) ;
}
static int F_110 ( struct V_134 * V_135 )
{
struct V_19 * V_20 ;
int V_40 ;
V_135 -> V_17 = F_111 ( V_136 ) ;
if ( ! V_135 -> V_17 )
return - V_42 ;
V_40 = - V_137 ;
V_20 = V_50 -> V_20 ;
F_66 ( & V_20 -> V_121 ) ;
if ( V_20 -> V_105 . V_134 )
goto V_138;
V_40 = - V_42 ;
V_135 -> V_15 = F_112 ( NULL , V_139 - V_45 , V_45 , 0 , 0 ) ;
if ( V_135 -> V_15 & ~ V_46 ) {
V_40 = V_135 -> V_15 ;
goto V_138;
}
V_40 = F_113 ( V_20 , V_135 -> V_15 , V_45 ,
V_9 | V_140 | V_141 | V_142 , & V_135 -> V_17 ) ;
if ( V_40 )
goto V_138;
F_114 () ;
V_20 -> V_105 . V_134 = V_135 ;
V_40 = 0 ;
V_138:
F_67 ( & V_20 -> V_121 ) ;
if ( V_40 )
F_115 ( V_135 -> V_17 ) ;
return V_40 ;
}
static struct V_134 * F_116 ( struct V_19 * V_20 )
{
struct V_134 * V_135 ;
V_135 = V_20 -> V_105 . V_134 ;
F_117 () ;
return V_135 ;
}
static struct V_134 * F_118 ( void )
{
struct V_134 * V_135 ;
V_135 = F_58 ( sizeof( * V_135 ) , V_74 ) ;
if ( F_33 ( ! V_135 ) )
return NULL ;
V_135 -> V_143 = F_58 ( F_119 ( V_144 ) * sizeof( long ) , V_74 ) ;
if ( ! V_135 -> V_143 )
goto V_138;
F_120 ( & V_135 -> V_145 ) ;
if ( ! F_110 ( V_135 ) )
return V_135 ;
V_138:
F_56 ( V_135 -> V_143 ) ;
F_56 ( V_135 ) ;
return F_116 ( V_50 -> V_20 ) ;
}
void F_121 ( struct V_19 * V_20 )
{
struct V_134 * V_135 = V_20 -> V_105 . V_134 ;
if ( ! V_135 )
return;
F_22 ( V_135 -> V_17 ) ;
F_56 ( V_135 -> V_143 ) ;
F_56 ( V_135 ) ;
}
void F_122 ( struct V_19 * V_20 )
{
V_20 -> V_105 . V_134 = NULL ;
F_52 ( & V_20 -> V_105 . V_106 , 0 ) ;
}
static unsigned long F_123 ( struct V_134 * V_135 )
{
unsigned long V_146 ;
int V_147 ;
do {
V_147 = F_124 ( V_135 -> V_143 , V_144 ) ;
if ( V_147 < V_144 ) {
if ( ! F_125 ( V_147 , V_135 -> V_143 ) )
break;
V_147 = V_144 ;
continue;
}
F_126 ( V_135 -> V_145 , ( F_105 ( & V_135 -> V_148 ) < V_144 ) ) ;
} while ( V_147 >= V_144 );
V_146 = V_135 -> V_15 + ( V_147 * V_149 ) ;
F_45 ( & V_135 -> V_148 ) ;
return V_146 ;
}
static unsigned long F_127 ( struct V_56 * V_56 , unsigned long V_146 )
{
struct V_134 * V_135 ;
unsigned long V_11 ;
void * V_15 ;
V_135 = F_116 ( V_50 -> V_20 ) ;
if ( ! V_135 ) {
V_135 = F_118 () ;
if ( ! V_135 )
return 0 ;
}
V_50 -> V_150 -> V_151 = F_123 ( V_135 ) ;
if ( F_33 ( ! V_50 -> V_150 -> V_151 ) )
return 0 ;
V_50 -> V_150 -> V_15 = V_146 ;
V_11 = V_50 -> V_150 -> V_151 & ~ V_46 ;
V_15 = F_29 ( V_135 -> V_17 ) ;
memcpy ( V_15 + V_11 , V_56 -> V_102 . V_31 , V_100 ) ;
F_30 ( V_15 ) ;
return V_50 -> V_150 -> V_151 ;
}
static void F_128 ( struct V_152 * V_153 )
{
struct V_134 * V_135 ;
unsigned long V_154 ;
unsigned long V_146 ;
if ( ! V_153 -> V_20 || ! V_153 -> V_20 -> V_105 . V_134 || ! V_153 -> V_150 )
return;
V_146 = V_153 -> V_150 -> V_151 ;
if ( F_33 ( ! V_146 || F_129 ( V_146 ) ) )
return;
V_135 = V_153 -> V_20 -> V_105 . V_134 ;
V_154 = V_135 -> V_15 + V_45 ;
if ( V_135 -> V_15 <= V_146 && V_146 < V_154 ) {
unsigned long V_11 ;
int V_147 ;
V_11 = V_146 - V_135 -> V_15 ;
V_147 = V_11 / V_149 ;
if ( V_147 >= V_144 )
return;
F_130 ( V_147 , V_135 -> V_143 ) ;
F_77 ( & V_135 -> V_148 ) ;
if ( F_131 ( & V_135 -> V_145 ) )
F_132 ( & V_135 -> V_145 ) ;
V_153 -> V_150 -> V_151 = 0 ;
}
}
unsigned long __weak F_133 ( struct V_77 * V_78 )
{
return F_134 ( V_78 ) - V_47 ;
}
void F_135 ( struct V_152 * V_130 )
{
struct V_155 * V_150 = V_130 -> V_150 ;
if ( ! V_150 )
return;
if ( V_150 -> V_156 )
F_54 ( V_150 -> V_156 ) ;
F_128 ( V_130 ) ;
F_56 ( V_150 ) ;
V_130 -> V_150 = NULL ;
}
void F_136 ( struct V_152 * V_130 )
{
V_130 -> V_150 = NULL ;
}
static struct V_155 * F_137 ( void )
{
struct V_155 * V_150 ;
V_150 = F_58 ( sizeof *V_150 , V_74 ) ;
if ( F_33 ( ! V_150 ) )
return NULL ;
V_50 -> V_150 = V_150 ;
return V_150 ;
}
static int
F_138 ( struct V_56 * V_56 , struct V_77 * V_78 , unsigned long V_15 )
{
if ( F_127 ( V_56 , V_15 ) && ! F_139 ( & V_56 -> V_102 , V_78 ) )
return 0 ;
return - V_157 ;
}
bool F_140 ( void )
{
struct V_152 * V_130 = V_50 ;
struct V_155 * V_150 = V_130 -> V_150 ;
if ( F_39 ( ! V_150 || ! V_150 -> V_156 ) )
return false ;
F_141 ( V_150 -> V_158 != V_159 ) ;
if ( F_142 ( V_130 ) ) {
F_143 ( & V_130 -> V_160 -> V_161 ) ;
F_144 ( V_130 , V_162 ) ;
F_145 ( & V_130 -> V_160 -> V_161 ) ;
if ( F_146 ( V_130 ) || F_147 ( V_130 ) ) {
V_150 -> V_158 = V_163 ;
F_148 ( V_130 , V_164 ) ;
F_148 ( V_130 , V_165 ) ;
}
}
return true ;
}
static bool F_149 ( struct V_56 * V_56 , struct V_77 * V_78 )
{
if ( F_150 ( & V_56 -> V_102 , V_78 ) )
return true ;
V_56 -> V_68 &= ~ V_72 ;
return false ;
}
static struct V_56 * F_151 ( unsigned long V_166 , int * V_167 )
{
struct V_19 * V_20 = V_50 -> V_20 ;
struct V_56 * V_56 = NULL ;
struct V_1 * V_2 ;
F_63 ( & V_20 -> V_121 ) ;
V_2 = F_91 ( V_20 , V_166 ) ;
if ( V_2 && V_2 -> V_12 <= V_166 ) {
if ( F_1 ( V_2 , false ) ) {
struct V_59 * V_59 = V_2 -> V_4 -> V_122 -> V_123 ;
T_1 V_11 = F_3 ( V_2 , V_166 ) ;
V_56 = F_46 ( V_59 , V_11 ) ;
}
if ( ! V_56 )
* V_167 = F_35 ( V_20 , V_166 ) ;
} else {
* V_167 = - V_157 ;
}
F_64 ( & V_20 -> V_121 ) ;
return V_56 ;
}
static void F_152 ( struct V_77 * V_78 )
{
struct V_155 * V_150 ;
struct V_56 * V_56 ;
unsigned long V_166 ;
int V_168 ( V_167 ) ;
V_166 = F_133 ( V_78 ) ;
V_56 = F_151 ( V_166 , & V_167 ) ;
if ( ! V_56 ) {
if ( V_167 > 0 ) {
F_153 ( V_169 , V_50 , 0 ) ;
} else {
F_154 ( V_78 , V_166 ) ;
}
return;
}
V_150 = V_50 -> V_150 ;
if ( ! V_150 ) {
V_150 = F_137 () ;
if ( ! V_150 )
goto V_170;
}
V_150 -> V_156 = V_56 ;
F_62 ( V_56 , V_78 ) ;
if ( V_56 -> V_68 & V_72 && F_149 ( V_56 , V_78 ) )
goto V_170;
V_150 -> V_158 = V_159 ;
if ( ! F_138 ( V_56 , V_78 , V_166 ) ) {
F_155 ( V_50 ) ;
return;
}
V_170:
if ( V_150 ) {
V_150 -> V_156 = NULL ;
V_150 -> V_158 = V_171 ;
}
if ( V_56 ) {
if ( ! ( V_56 -> V_68 & V_72 ) )
F_154 ( V_78 , V_166 ) ;
F_54 ( V_56 ) ;
}
}
static void F_156 ( struct V_155 * V_150 , struct V_77 * V_78 )
{
struct V_56 * V_56 ;
V_56 = V_150 -> V_156 ;
if ( V_150 -> V_158 == V_172 )
F_157 ( & V_56 -> V_102 , V_78 ) ;
else if ( V_150 -> V_158 == V_163 )
F_158 ( & V_56 -> V_102 , V_78 ) ;
else
F_141 ( 1 ) ;
F_54 ( V_56 ) ;
V_150 -> V_156 = NULL ;
V_150 -> V_158 = V_171 ;
F_159 ( V_50 ) ;
F_128 ( V_50 ) ;
F_143 ( & V_50 -> V_160 -> V_161 ) ;
F_160 () ;
F_145 ( & V_50 -> V_160 -> V_161 ) ;
}
void F_161 ( struct V_77 * V_78 )
{
struct V_155 * V_150 ;
V_150 = V_50 -> V_150 ;
if ( ! V_150 || V_150 -> V_158 == V_173 )
F_152 ( V_78 ) ;
else
F_156 ( V_150 , V_78 ) ;
}
int F_162 ( struct V_77 * V_78 )
{
struct V_155 * V_150 ;
if ( ! V_50 -> V_20 || ! F_105 ( & V_50 -> V_20 -> V_105 . V_106 ) )
return 0 ;
V_150 = V_50 -> V_150 ;
if ( V_150 )
V_150 -> V_158 = V_173 ;
F_163 ( V_164 ) ;
return 1 ;
}
int F_164 ( struct V_77 * V_78 )
{
struct V_155 * V_150 = V_50 -> V_150 ;
if ( ! V_50 -> V_20 || ! V_150 || ! V_150 -> V_156 )
return 0 ;
V_150 -> V_158 = V_172 ;
F_163 ( V_164 ) ;
return 1 ;
}
static int T_6 F_165 ( void )
{
int V_174 ;
for ( V_174 = 0 ; V_174 < V_175 ; V_174 ++ ) {
F_166 ( & V_176 [ V_174 ] ) ;
F_166 ( & V_177 [ V_174 ] ) ;
}
return F_167 ( & V_178 ) ;
}
static void T_7 F_168 ( void )
{
}
