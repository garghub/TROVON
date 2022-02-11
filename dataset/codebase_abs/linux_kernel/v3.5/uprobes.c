static bool F_1 ( struct V_1 * V_2 , bool V_3 )
{
if ( ! V_2 -> V_4 )
return false ;
if ( ! V_3 )
return true ;
if ( ( V_2 -> V_5 & ( V_6 | V_7 | V_8 | V_9 ) ) == ( V_6 | V_8 ) )
return true ;
return false ;
}
static T_1 F_2 ( struct V_1 * V_2 , T_1 V_10 )
{
T_1 V_11 ;
V_11 = V_2 -> V_12 + V_10 ;
V_11 -= V_2 -> V_13 << V_14 ;
return V_11 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_15 * V_15 , struct V_15 * V_16 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
T_2 * V_20 ;
T_3 * V_21 ;
T_4 * V_22 ;
T_5 * V_23 ;
T_6 * V_24 ;
unsigned long V_25 ;
int V_26 = - V_27 ;
V_25 = F_4 ( V_15 , V_2 ) ;
if ( V_25 == - V_27 )
goto V_28;
V_20 = F_5 ( V_18 , V_25 ) ;
if ( ! F_6 ( * V_20 ) )
goto V_28;
V_21 = F_7 ( V_20 , V_25 ) ;
if ( ! F_8 ( * V_21 ) )
goto V_28;
V_22 = F_9 ( V_21 , V_25 ) ;
if ( ! F_10 ( * V_22 ) )
goto V_28;
V_23 = F_11 ( V_18 , V_22 , V_25 , & V_24 ) ;
if ( ! V_23 )
goto V_28;
F_12 ( V_16 ) ;
F_13 ( V_16 , V_2 , V_25 ) ;
if ( ! F_14 ( V_15 ) ) {
F_15 ( V_18 , V_29 ) ;
F_16 ( V_18 , V_30 ) ;
}
F_17 ( V_2 , V_25 , F_18 ( * V_23 ) ) ;
F_19 ( V_2 , V_25 , V_23 ) ;
F_20 ( V_18 , V_25 , V_23 , F_21 ( V_16 , V_2 -> V_31 ) ) ;
F_22 ( V_15 ) ;
if ( ! F_23 ( V_15 ) )
F_24 ( V_15 ) ;
F_25 ( V_15 ) ;
F_26 ( V_23 , V_24 ) ;
V_26 = 0 ;
V_28:
return V_26 ;
}
bool __weak F_27 ( T_7 * V_32 )
{
return * V_32 == V_33 ;
}
static int F_28 ( struct V_34 * V_35 , struct V_17 * V_18 ,
unsigned long V_11 , T_7 V_36 )
{
struct V_15 * V_37 , * V_38 ;
struct V_39 * V_40 ;
void * V_41 , * V_42 ;
struct V_1 * V_2 ;
struct V_43 * V_43 ;
T_1 V_25 ;
int V_44 ;
V_44 = F_29 ( NULL , V_18 , V_11 , 1 , 0 , 0 , & V_37 , & V_2 ) ;
if ( V_44 <= 0 )
return V_44 ;
V_44 = - V_45 ;
if ( ! F_1 ( V_2 , F_27 ( & V_36 ) ) )
goto V_46;
V_43 = F_30 ( V_35 , struct V_43 , V_47 ) ;
V_40 = V_43 -> V_48 -> V_49 ;
if ( V_40 != V_2 -> V_4 -> V_50 )
goto V_46;
V_25 = F_2 ( V_2 , V_43 -> V_10 ) ;
if ( V_11 != ( unsigned long ) V_25 )
goto V_46;
V_44 = - V_51 ;
V_38 = F_31 ( V_52 , V_2 , V_11 ) ;
if ( ! V_38 )
goto V_46;
F_32 ( V_38 ) ;
F_33 ( V_37 ) ;
V_41 = F_34 ( V_37 ) ;
V_42 = F_34 ( V_38 ) ;
memcpy ( V_42 , V_41 , V_53 ) ;
V_11 &= ~ V_54 ;
F_35 ( V_11 + V_55 > V_53 ) ;
memcpy ( V_42 + V_11 , & V_36 , V_55 ) ;
F_36 ( V_42 ) ;
F_36 ( V_41 ) ;
V_44 = F_37 ( V_2 ) ;
if ( V_44 )
goto V_56;
F_33 ( V_38 ) ;
V_44 = F_3 ( V_2 , V_37 , V_38 ) ;
F_38 ( V_38 ) ;
V_56:
F_38 ( V_37 ) ;
F_39 ( V_38 ) ;
V_46:
F_25 ( V_37 ) ;
return V_44 ;
}
static int F_40 ( struct V_17 * V_18 , unsigned long V_11 , T_7 * V_36 )
{
struct V_15 * V_15 ;
void * V_42 ;
int V_44 ;
V_44 = F_29 ( NULL , V_18 , V_11 , 1 , 0 , 0 , & V_15 , NULL ) ;
if ( V_44 <= 0 )
return V_44 ;
F_33 ( V_15 ) ;
V_42 = F_34 ( V_15 ) ;
V_11 &= ~ V_54 ;
memcpy ( V_36 , V_42 + V_11 , V_55 ) ;
F_36 ( V_42 ) ;
F_38 ( V_15 ) ;
F_25 ( V_15 ) ;
return 0 ;
}
static int F_41 ( struct V_17 * V_18 , unsigned long V_11 )
{
T_7 V_36 ;
int V_57 ;
V_57 = F_40 ( V_18 , V_11 , & V_36 ) ;
if ( V_57 )
return V_57 ;
if ( F_27 ( & V_36 ) )
return 1 ;
return 0 ;
}
int __weak F_42 ( struct V_34 * V_35 , struct V_17 * V_18 , unsigned long V_11 )
{
int V_57 ;
V_57 = F_41 ( V_18 , V_11 ) ;
if ( V_57 == 1 )
return - V_58 ;
if ( V_57 )
return V_57 ;
return F_28 ( V_35 , V_18 , V_11 , V_33 ) ;
}
int __weak
F_43 ( struct V_34 * V_35 , struct V_17 * V_18 , unsigned long V_11 , bool V_59 )
{
if ( V_59 ) {
int V_57 ;
V_57 = F_41 ( V_18 , V_11 ) ;
if ( ! V_57 )
return - V_45 ;
if ( V_57 != 1 )
return V_57 ;
}
return F_28 ( V_35 , V_18 , V_11 , * ( T_7 * ) V_35 -> V_32 ) ;
}
static int F_44 ( struct V_43 * V_60 , struct V_43 * V_61 )
{
if ( V_60 -> V_48 < V_61 -> V_48 )
return - 1 ;
if ( V_60 -> V_48 > V_61 -> V_48 )
return 1 ;
if ( V_60 -> V_10 < V_61 -> V_10 )
return - 1 ;
if ( V_60 -> V_10 > V_61 -> V_10 )
return 1 ;
return 0 ;
}
static struct V_43 * F_45 ( struct V_48 * V_48 , T_1 V_10 )
{
struct V_43 V_62 = { . V_48 = V_48 , . V_10 = V_10 } ;
struct V_63 * V_64 = V_65 . V_63 ;
struct V_43 * V_43 ;
int V_66 ;
while ( V_64 ) {
V_43 = F_46 ( V_64 , struct V_43 , V_63 ) ;
V_66 = F_44 ( & V_62 , V_43 ) ;
if ( ! V_66 ) {
F_47 ( & V_43 -> V_67 ) ;
return V_43 ;
}
if ( V_66 < 0 )
V_64 = V_64 -> V_68 ;
else
V_64 = V_64 -> V_69 ;
}
return NULL ;
}
static struct V_43 * F_48 ( struct V_48 * V_48 , T_1 V_10 )
{
struct V_43 * V_43 ;
unsigned long V_70 ;
F_49 ( & V_71 , V_70 ) ;
V_43 = F_45 ( V_48 , V_10 ) ;
F_50 ( & V_71 , V_70 ) ;
return V_43 ;
}
static struct V_43 * F_51 ( struct V_43 * V_43 )
{
struct V_63 * * V_72 = & V_65 . V_63 ;
struct V_63 * V_73 = NULL ;
struct V_43 * V_62 ;
int V_66 ;
while ( * V_72 ) {
V_73 = * V_72 ;
V_62 = F_46 ( V_73 , struct V_43 , V_63 ) ;
V_66 = F_44 ( V_43 , V_62 ) ;
if ( ! V_66 ) {
F_47 ( & V_62 -> V_67 ) ;
return V_62 ;
}
if ( V_66 < 0 )
V_72 = & V_73 -> V_68 ;
else
V_72 = & V_73 -> V_69 ;
}
V_62 = NULL ;
F_52 ( & V_43 -> V_63 , V_73 , V_72 ) ;
F_53 ( & V_43 -> V_63 , & V_65 ) ;
F_54 ( & V_43 -> V_67 , 2 ) ;
return V_62 ;
}
static struct V_43 * F_55 ( struct V_43 * V_43 )
{
unsigned long V_70 ;
struct V_43 * V_62 ;
F_49 ( & V_71 , V_70 ) ;
V_62 = F_51 ( V_43 ) ;
F_50 ( & V_71 , V_70 ) ;
V_43 -> V_70 |= V_74 ;
return V_62 ;
}
static void F_56 ( struct V_43 * V_43 )
{
if ( F_57 ( & V_43 -> V_67 ) )
F_58 ( V_43 ) ;
}
static struct V_43 * F_59 ( struct V_48 * V_48 , T_1 V_10 )
{
struct V_43 * V_43 , * V_75 ;
V_43 = F_60 ( sizeof( struct V_43 ) , V_76 ) ;
if ( ! V_43 )
return NULL ;
V_43 -> V_48 = F_61 ( V_48 ) ;
V_43 -> V_10 = V_10 ;
F_62 ( & V_43 -> V_77 ) ;
F_63 ( & V_43 -> V_78 ) ;
V_75 = F_55 ( V_43 ) ;
if ( V_75 ) {
F_58 ( V_43 ) ;
V_43 = V_75 ;
F_64 ( V_48 ) ;
} else {
F_47 ( & V_79 ) ;
}
return V_43 ;
}
static void F_65 ( struct V_43 * V_43 , struct V_80 * V_81 )
{
struct V_82 * V_83 ;
if ( ! ( V_43 -> V_70 & V_84 ) )
return;
F_66 ( & V_43 -> V_77 ) ;
for ( V_83 = V_43 -> V_85 ; V_83 ; V_83 = V_83 -> V_86 ) {
if ( ! V_83 -> V_87 || V_83 -> V_87 ( V_83 , V_88 ) )
V_83 -> V_89 ( V_83 , V_81 ) ;
}
F_67 ( & V_43 -> V_77 ) ;
}
static struct V_82 *
F_68 ( struct V_43 * V_43 , struct V_82 * V_83 )
{
F_69 ( & V_43 -> V_77 ) ;
V_83 -> V_86 = V_43 -> V_85 ;
V_43 -> V_85 = V_83 ;
F_70 ( & V_43 -> V_77 ) ;
return V_83 -> V_86 ;
}
static bool F_71 ( struct V_43 * V_43 , struct V_82 * V_83 )
{
struct V_82 * * V_90 ;
bool V_44 = false ;
F_69 ( & V_43 -> V_77 ) ;
for ( V_90 = & V_43 -> V_85 ; * V_90 ; V_90 = & ( * V_90 ) -> V_86 ) {
if ( * V_90 == V_83 ) {
* V_90 = V_83 -> V_86 ;
V_44 = true ;
break;
}
}
F_70 ( & V_43 -> V_77 ) ;
return V_44 ;
}
static int
F_72 ( struct V_39 * V_40 , struct V_1 * V_2 , char * V_32 ,
unsigned long V_91 , unsigned long V_10 )
{
struct V_92 * V_93 = V_2 -> V_4 ;
struct V_15 * V_15 ;
void * V_11 ;
unsigned long V_94 ;
unsigned long V_95 ;
if ( ! V_93 )
return - V_45 ;
V_95 = ( unsigned long ) ( V_10 >> V_96 ) ;
V_94 = V_10 &= ~ V_54 ;
V_15 = F_73 ( V_40 , V_95 , V_93 ) ;
if ( F_74 ( V_15 ) )
return F_75 ( V_15 ) ;
V_11 = F_34 ( V_15 ) ;
memcpy ( V_32 , V_11 + V_94 , V_91 ) ;
F_36 ( V_11 ) ;
F_39 ( V_15 ) ;
return 0 ;
}
static int
F_76 ( struct V_43 * V_43 , struct V_1 * V_2 , unsigned long V_25 )
{
struct V_39 * V_40 ;
unsigned long V_91 ;
int V_97 ;
V_25 &= ~ V_54 ;
V_91 = V_53 - V_25 ;
V_40 = V_43 -> V_48 -> V_49 ;
if ( V_43 -> V_10 + V_98 > V_43 -> V_48 -> V_99 )
V_97 = V_43 -> V_48 -> V_99 - V_43 -> V_10 ;
else
V_97 = V_98 ;
if ( V_91 < V_97 ) {
if ( F_72 ( V_40 , V_2 , V_43 -> V_47 . V_32 + V_91 ,
V_97 - V_91 , V_43 -> V_10 + V_91 ) )
return - V_51 ;
V_97 = V_91 ;
}
return F_72 ( V_40 , V_2 , V_43 -> V_47 . V_32 , V_97 , V_43 -> V_10 ) ;
}
static int
F_77 ( struct V_43 * V_43 , struct V_17 * V_18 ,
struct V_1 * V_2 , T_1 V_11 )
{
unsigned long V_25 ;
int V_44 ;
if ( ! V_43 -> V_85 )
return - V_58 ;
V_25 = ( unsigned long ) V_11 ;
if ( ! ( V_43 -> V_70 & V_100 ) ) {
V_44 = F_76 ( V_43 , V_2 , V_25 ) ;
if ( V_44 )
return V_44 ;
if ( F_27 ( ( T_7 * ) V_43 -> V_47 . V_32 ) )
return - V_58 ;
V_44 = F_78 ( & V_43 -> V_47 , V_18 ) ;
if ( V_44 )
return V_44 ;
V_43 -> V_70 |= V_100 ;
}
F_47 ( & V_18 -> V_101 . V_102 ) ;
V_44 = F_42 ( & V_43 -> V_47 , V_18 , V_25 ) ;
if ( V_44 )
F_79 ( & V_18 -> V_101 . V_102 ) ;
return V_44 ;
}
static void
F_80 ( struct V_43 * V_43 , struct V_17 * V_18 , T_1 V_11 )
{
if ( ! F_43 ( & V_43 -> V_47 , V_18 , ( unsigned long ) V_11 , true ) )
F_79 ( & V_18 -> V_101 . V_102 ) ;
}
static void F_81 ( struct V_43 * V_43 )
{
unsigned long V_70 ;
F_82 ( & V_103 ) ;
F_49 ( & V_71 , V_70 ) ;
F_83 ( & V_43 -> V_63 , & V_65 ) ;
F_50 ( & V_71 , V_70 ) ;
F_64 ( V_43 -> V_48 ) ;
F_56 ( V_43 ) ;
F_79 ( & V_79 ) ;
}
static struct V_104 *
F_84 ( struct V_39 * V_40 , struct V_105 * V_106 ,
struct V_104 * V_107 , T_1 V_10 , bool V_3 )
{
struct V_108 V_109 ;
struct V_1 * V_2 ;
struct V_104 * V_110 ;
unsigned long V_111 ;
int V_112 ;
T_1 V_11 ;
V_111 = V_10 >> V_14 ;
F_85 (vma, &iter, &mapping->i_mmap, pgoff, pgoff) {
if ( ! F_1 ( V_2 , V_3 ) )
continue;
V_112 = 0 ;
V_11 = F_2 ( V_2 , V_10 ) ;
F_86 (tmpvi, head, probe_list) {
if ( V_110 -> V_18 == V_2 -> V_19 && V_110 -> V_11 == V_11 ) {
V_112 = 1 ;
break;
}
}
if ( ! V_112 && F_87 ( & V_2 -> V_19 -> V_113 ) ) {
V_107 -> V_18 = V_2 -> V_19 ;
V_107 -> V_11 = V_11 ;
F_88 ( & V_107 -> V_114 , V_106 ) ;
return V_107 ;
}
}
return NULL ;
}
static struct V_104 *
F_89 ( struct V_39 * V_40 , struct V_105 * V_106 ,
T_1 V_10 , bool V_3 )
{
struct V_104 * V_107 , * V_115 ;
V_107 = F_60 ( sizeof( struct V_104 ) , V_76 ) ;
if ( ! V_107 )
return F_90 ( - V_51 ) ;
F_91 ( & V_40 -> V_116 ) ;
V_115 = F_84 ( V_40 , V_106 , V_107 , V_10 , V_3 ) ;
F_92 ( & V_40 -> V_116 ) ;
if ( ! V_115 )
F_58 ( V_107 ) ;
return V_115 ;
}
static int F_93 ( struct V_43 * V_43 , bool V_3 )
{
struct V_105 V_117 ;
struct V_1 * V_2 ;
struct V_39 * V_40 ;
struct V_104 * V_107 , * V_110 ;
struct V_17 * V_18 ;
T_1 V_11 ;
int V_44 ;
V_40 = V_43 -> V_48 -> V_49 ;
F_63 ( & V_117 ) ;
V_44 = 0 ;
for (; ; ) {
V_107 = F_89 ( V_40 , & V_117 , V_43 -> V_10 , V_3 ) ;
if ( ! V_107 )
break;
if ( F_74 ( V_107 ) ) {
V_44 = F_75 ( V_107 ) ;
break;
}
V_18 = V_107 -> V_18 ;
F_66 ( & V_18 -> V_118 ) ;
V_2 = F_94 ( V_18 , ( unsigned long ) V_107 -> V_11 ) ;
if ( ! V_2 || ! F_1 ( V_2 , V_3 ) ) {
F_95 ( & V_107 -> V_114 ) ;
F_58 ( V_107 ) ;
F_67 ( & V_18 -> V_118 ) ;
F_96 ( V_18 ) ;
continue;
}
V_11 = F_2 ( V_2 , V_43 -> V_10 ) ;
if ( V_2 -> V_4 -> V_50 -> V_119 != V_43 -> V_48 ||
V_11 != V_107 -> V_11 ) {
F_95 ( & V_107 -> V_114 ) ;
F_58 ( V_107 ) ;
F_67 ( & V_18 -> V_118 ) ;
F_96 ( V_18 ) ;
continue;
}
if ( V_3 )
V_44 = F_77 ( V_43 , V_18 , V_2 , V_107 -> V_11 ) ;
else
F_80 ( V_43 , V_18 , V_107 -> V_11 ) ;
F_67 ( & V_18 -> V_118 ) ;
F_96 ( V_18 ) ;
if ( V_3 ) {
if ( V_44 && V_44 == - V_58 )
V_44 = 0 ;
if ( V_44 )
break;
}
}
F_97 (vi, tmpvi, &try_list, probe_list) {
F_95 ( & V_107 -> V_114 ) ;
F_58 ( V_107 ) ;
}
return V_44 ;
}
static int F_98 ( struct V_43 * V_43 )
{
return F_93 ( V_43 , true ) ;
}
static void F_99 ( struct V_43 * V_43 )
{
if ( ! F_93 ( V_43 , false ) )
F_81 ( V_43 ) ;
}
int F_100 ( struct V_48 * V_48 , T_1 V_10 , struct V_82 * V_83 )
{
struct V_43 * V_43 ;
int V_44 ;
if ( ! V_48 || ! V_83 || V_83 -> V_86 )
return - V_45 ;
if ( V_10 > F_101 ( V_48 ) )
return - V_45 ;
V_44 = 0 ;
F_91 ( F_102 ( V_48 ) ) ;
V_43 = F_59 ( V_48 , V_10 ) ;
if ( V_43 && ! F_68 ( V_43 , V_83 ) ) {
V_44 = F_98 ( V_43 ) ;
if ( V_44 ) {
V_43 -> V_85 = NULL ;
F_99 ( V_43 ) ;
} else {
V_43 -> V_70 |= V_84 ;
}
}
F_92 ( F_102 ( V_48 ) ) ;
F_56 ( V_43 ) ;
return V_44 ;
}
void F_103 ( struct V_48 * V_48 , T_1 V_10 , struct V_82 * V_83 )
{
struct V_43 * V_43 ;
if ( ! V_48 || ! V_83 )
return;
V_43 = F_48 ( V_48 , V_10 ) ;
if ( ! V_43 )
return;
F_91 ( F_102 ( V_48 ) ) ;
if ( F_71 ( V_43 , V_83 ) ) {
if ( ! V_43 -> V_85 ) {
F_99 ( V_43 ) ;
V_43 -> V_70 &= ~ V_84 ;
}
}
F_92 ( F_102 ( V_48 ) ) ;
if ( V_43 )
F_56 ( V_43 ) ;
}
static struct V_63 * F_104 ( struct V_48 * V_48 )
{
struct V_43 V_62 = { . V_48 = V_48 , . V_10 = 0 } ;
struct V_63 * V_64 = V_65 . V_63 ;
struct V_63 * V_120 = NULL ;
struct V_43 * V_43 ;
int V_66 ;
while ( V_64 ) {
V_43 = F_46 ( V_64 , struct V_43 , V_63 ) ;
V_66 = F_44 ( & V_62 , V_43 ) ;
if ( V_43 -> V_48 == V_48 )
V_120 = V_64 ;
if ( ! V_66 )
return V_120 ;
if ( V_66 < 0 )
V_64 = V_64 -> V_68 ;
else
V_64 = V_64 -> V_69 ;
}
return V_120 ;
}
static void F_105 ( struct V_48 * V_48 , struct V_105 * V_106 )
{
struct V_43 * V_43 ;
unsigned long V_70 ;
struct V_63 * V_64 ;
F_49 ( & V_71 , V_70 ) ;
V_64 = F_104 ( V_48 ) ;
for (; V_64 ; V_64 = F_106 ( V_64 ) ) {
V_43 = F_46 ( V_64 , struct V_43 , V_63 ) ;
if ( V_43 -> V_48 != V_48 )
break;
F_88 ( & V_43 -> V_78 , V_106 ) ;
F_47 ( & V_43 -> V_67 ) ;
}
F_50 ( & V_71 , V_70 ) ;
}
int F_107 ( struct V_1 * V_2 )
{
struct V_105 V_121 ;
struct V_43 * V_43 , * V_62 ;
struct V_48 * V_48 ;
int V_44 , V_102 ;
if ( ! F_108 ( & V_79 ) || ! F_1 ( V_2 , true ) )
return 0 ;
V_48 = V_2 -> V_4 -> V_50 -> V_119 ;
if ( ! V_48 )
return 0 ;
F_63 ( & V_121 ) ;
F_91 ( F_109 ( V_48 ) ) ;
F_105 ( V_48 , & V_121 ) ;
V_44 = 0 ;
V_102 = 0 ;
F_97 (uprobe, u, &tmp_list, pending_list) {
T_1 V_11 ;
F_95 ( & V_43 -> V_78 ) ;
if ( ! V_44 ) {
V_11 = F_2 ( V_2 , V_43 -> V_10 ) ;
if ( V_11 < V_2 -> V_12 || V_11 >= V_2 -> V_122 ) {
F_56 ( V_43 ) ;
continue;
}
V_44 = F_77 ( V_43 , V_2 -> V_19 , V_2 , V_11 ) ;
if ( V_44 == - V_58 ) {
V_44 = 0 ;
if ( ! F_41 ( V_2 -> V_19 , V_11 ) )
continue;
F_47 ( & V_2 -> V_19 -> V_101 . V_102 ) ;
}
if ( ! V_44 )
V_102 ++ ;
}
F_56 ( V_43 ) ;
}
F_92 ( F_109 ( V_48 ) ) ;
if ( V_44 )
F_110 ( V_102 , & V_2 -> V_19 -> V_101 . V_102 ) ;
return V_44 ;
}
void F_111 ( struct V_1 * V_2 , unsigned long V_123 , unsigned long V_124 )
{
struct V_105 V_121 ;
struct V_43 * V_43 , * V_62 ;
struct V_48 * V_48 ;
if ( ! F_108 ( & V_79 ) || ! F_1 ( V_2 , false ) )
return;
if ( ! F_108 ( & V_2 -> V_19 -> V_101 . V_102 ) )
return;
V_48 = V_2 -> V_4 -> V_50 -> V_119 ;
if ( ! V_48 )
return;
F_63 ( & V_121 ) ;
F_91 ( F_109 ( V_48 ) ) ;
F_105 ( V_48 , & V_121 ) ;
F_97 (uprobe, u, &tmp_list, pending_list) {
T_1 V_11 ;
F_95 ( & V_43 -> V_78 ) ;
V_11 = F_2 ( V_2 , V_43 -> V_10 ) ;
if ( V_11 >= V_123 && V_11 < V_124 ) {
if ( F_41 ( V_2 -> V_19 , V_11 ) == 1 )
F_79 ( & V_2 -> V_19 -> V_101 . V_102 ) ;
}
F_56 ( V_43 ) ;
}
F_92 ( F_109 ( V_48 ) ) ;
}
static int F_112 ( struct V_125 * V_126 )
{
struct V_17 * V_18 ;
int V_44 ;
V_126 -> V_15 = F_113 ( V_127 ) ;
if ( ! V_126 -> V_15 )
return - V_51 ;
V_44 = - V_128 ;
V_18 = V_88 -> V_18 ;
F_69 ( & V_18 -> V_118 ) ;
if ( V_18 -> V_101 . V_125 )
goto V_129;
V_44 = - V_51 ;
V_126 -> V_11 = F_114 ( NULL , V_130 - V_53 , V_53 , 0 , 0 ) ;
if ( V_126 -> V_11 & ~ V_54 ) {
V_44 = V_126 -> V_11 ;
goto V_129;
}
V_44 = F_115 ( V_18 , V_126 -> V_11 , V_53 ,
V_8 | V_131 | V_132 | V_133 , & V_126 -> V_15 ) ;
if ( V_44 )
goto V_129;
F_116 () ;
V_18 -> V_101 . V_125 = V_126 ;
V_44 = 0 ;
V_129:
F_70 ( & V_18 -> V_118 ) ;
if ( V_44 )
F_117 ( V_126 -> V_15 ) ;
return V_44 ;
}
static struct V_125 * F_118 ( struct V_17 * V_18 )
{
struct V_125 * V_126 ;
V_126 = V_18 -> V_101 . V_125 ;
F_119 () ;
return V_126 ;
}
static struct V_125 * F_120 ( void )
{
struct V_125 * V_126 ;
V_126 = F_60 ( sizeof( * V_126 ) , V_76 ) ;
if ( F_121 ( ! V_126 ) )
return NULL ;
V_126 -> V_134 = F_60 ( F_122 ( V_135 ) * sizeof( long ) , V_76 ) ;
if ( ! V_126 -> V_134 )
goto V_129;
F_123 ( & V_126 -> V_136 ) ;
if ( ! F_112 ( V_126 ) )
return V_126 ;
V_129:
F_58 ( V_126 -> V_134 ) ;
F_58 ( V_126 ) ;
return F_118 ( V_88 -> V_18 ) ;
}
void F_124 ( struct V_17 * V_18 )
{
struct V_125 * V_126 = V_18 -> V_101 . V_125 ;
if ( ! V_126 )
return;
F_25 ( V_126 -> V_15 ) ;
F_58 ( V_126 -> V_134 ) ;
F_58 ( V_126 ) ;
}
void F_125 ( struct V_17 * V_18 )
{
V_18 -> V_101 . V_125 = NULL ;
F_54 ( & V_18 -> V_101 . V_102 , 0 ) ;
}
static unsigned long F_126 ( struct V_125 * V_126 )
{
unsigned long V_137 ;
int V_138 ;
do {
V_138 = F_127 ( V_126 -> V_134 , V_135 ) ;
if ( V_138 < V_135 ) {
if ( ! F_128 ( V_138 , V_126 -> V_134 ) )
break;
V_138 = V_135 ;
continue;
}
F_129 ( V_126 -> V_136 , ( F_108 ( & V_126 -> V_139 ) < V_135 ) ) ;
} while ( V_138 >= V_135 );
V_137 = V_126 -> V_11 + ( V_138 * V_140 ) ;
F_47 ( & V_126 -> V_139 ) ;
return V_137 ;
}
static unsigned long F_130 ( struct V_43 * V_43 , unsigned long V_137 )
{
struct V_125 * V_126 ;
unsigned long V_10 ;
void * V_11 ;
V_126 = F_118 ( V_88 -> V_18 ) ;
if ( ! V_126 ) {
V_126 = F_120 () ;
if ( ! V_126 )
return 0 ;
}
V_88 -> V_141 -> V_142 = F_126 ( V_126 ) ;
if ( F_121 ( ! V_88 -> V_141 -> V_142 ) )
return 0 ;
V_88 -> V_141 -> V_11 = V_137 ;
V_10 = V_88 -> V_141 -> V_142 & ~ V_54 ;
V_11 = F_34 ( V_126 -> V_15 ) ;
memcpy ( V_11 + V_10 , V_43 -> V_47 . V_32 , V_98 ) ;
F_36 ( V_11 ) ;
return V_88 -> V_141 -> V_142 ;
}
static void F_131 ( struct V_143 * V_144 )
{
struct V_125 * V_126 ;
unsigned long V_145 ;
unsigned long V_137 ;
if ( ! V_144 -> V_18 || ! V_144 -> V_18 -> V_101 . V_125 || ! V_144 -> V_141 )
return;
V_137 = V_144 -> V_141 -> V_142 ;
if ( F_121 ( ! V_137 || F_132 ( V_137 ) ) )
return;
V_126 = V_144 -> V_18 -> V_101 . V_125 ;
V_145 = V_126 -> V_11 + V_53 ;
if ( V_126 -> V_11 <= V_137 && V_137 < V_145 ) {
unsigned long V_10 ;
int V_138 ;
V_10 = V_137 - V_126 -> V_11 ;
V_138 = V_10 / V_140 ;
if ( V_138 >= V_135 )
return;
F_133 ( V_138 , V_126 -> V_134 ) ;
F_79 ( & V_126 -> V_139 ) ;
if ( F_134 ( & V_126 -> V_136 ) )
F_135 ( & V_126 -> V_136 ) ;
V_144 -> V_141 -> V_142 = 0 ;
}
}
unsigned long __weak F_136 ( struct V_80 * V_81 )
{
return F_137 ( V_81 ) - V_55 ;
}
void F_138 ( struct V_143 * V_146 )
{
struct V_147 * V_141 = V_146 -> V_141 ;
if ( V_146 -> V_148 != - 1 )
F_139 ( & V_103 , V_146 -> V_148 ) ;
if ( ! V_141 )
return;
if ( V_141 -> V_149 )
F_56 ( V_141 -> V_149 ) ;
F_131 ( V_146 ) ;
F_58 ( V_141 ) ;
V_146 -> V_141 = NULL ;
}
void F_140 ( struct V_143 * V_146 )
{
V_146 -> V_141 = NULL ;
V_146 -> V_148 = - 1 ;
}
static struct V_147 * F_141 ( void )
{
struct V_147 * V_141 ;
V_141 = F_60 ( sizeof *V_141 , V_76 ) ;
if ( F_121 ( ! V_141 ) )
return NULL ;
V_141 -> V_149 = NULL ;
V_88 -> V_141 = V_141 ;
return V_141 ;
}
static int
F_142 ( struct V_43 * V_43 , struct V_80 * V_81 , unsigned long V_11 )
{
if ( F_130 ( V_43 , V_11 ) && ! F_143 ( & V_43 -> V_47 , V_81 ) )
return 0 ;
return - V_27 ;
}
bool F_144 ( void )
{
struct V_143 * V_146 = V_88 ;
struct V_147 * V_141 = V_146 -> V_141 ;
if ( F_145 ( ! V_141 || ! V_141 -> V_149 ) )
return false ;
F_146 ( V_141 -> V_150 != V_151 ) ;
if ( F_147 ( V_146 ) ) {
F_148 ( & V_146 -> V_152 -> V_153 ) ;
F_149 ( V_146 , V_154 ) ;
F_150 ( & V_146 -> V_152 -> V_153 ) ;
if ( F_151 ( V_146 ) || F_152 ( V_146 ) ) {
V_141 -> V_150 = V_155 ;
F_153 ( V_146 , V_156 ) ;
F_153 ( V_146 , V_157 ) ;
}
}
return true ;
}
static bool F_154 ( struct V_43 * V_43 , struct V_80 * V_81 )
{
if ( F_155 ( & V_43 -> V_47 , V_81 ) )
return true ;
V_43 -> V_70 &= ~ V_74 ;
return false ;
}
static void F_156 ( struct V_80 * V_81 )
{
struct V_1 * V_2 ;
struct V_147 * V_141 ;
struct V_43 * V_43 ;
struct V_17 * V_18 ;
unsigned long V_158 ;
V_43 = NULL ;
V_158 = F_136 ( V_81 ) ;
V_18 = V_88 -> V_18 ;
F_66 ( & V_18 -> V_118 ) ;
V_2 = F_94 ( V_18 , V_158 ) ;
if ( V_2 && V_2 -> V_12 <= V_158 && F_1 ( V_2 , false ) ) {
struct V_48 * V_48 ;
T_1 V_10 ;
V_48 = V_2 -> V_4 -> V_50 -> V_119 ;
V_10 = V_158 - V_2 -> V_12 ;
V_10 += ( V_2 -> V_13 << V_14 ) ;
V_43 = F_48 ( V_48 , V_10 ) ;
}
F_139 ( & V_103 , V_88 -> V_148 ) ;
V_88 -> V_148 = - 1 ;
F_67 ( & V_18 -> V_118 ) ;
if ( ! V_43 ) {
F_157 ( V_159 , V_88 , 0 ) ;
return;
}
V_141 = V_88 -> V_141 ;
if ( ! V_141 ) {
V_141 = F_141 () ;
if ( ! V_141 )
goto V_160;
}
V_141 -> V_149 = V_43 ;
F_65 ( V_43 , V_81 ) ;
if ( V_43 -> V_70 & V_74 && F_154 ( V_43 , V_81 ) )
goto V_160;
V_141 -> V_150 = V_151 ;
if ( ! F_142 ( V_43 , V_81 , V_158 ) ) {
F_158 ( V_88 ) ;
return;
}
V_160:
if ( V_141 ) {
V_141 -> V_149 = NULL ;
V_141 -> V_150 = V_161 ;
}
if ( V_43 ) {
if ( ! ( V_43 -> V_70 & V_74 ) )
F_159 ( V_81 , V_158 ) ;
F_56 ( V_43 ) ;
}
}
static void F_160 ( struct V_147 * V_141 , struct V_80 * V_81 )
{
struct V_43 * V_43 ;
V_43 = V_141 -> V_149 ;
if ( V_141 -> V_150 == V_162 )
F_161 ( & V_43 -> V_47 , V_81 ) ;
else if ( V_141 -> V_150 == V_155 )
F_162 ( & V_43 -> V_47 , V_81 ) ;
else
F_146 ( 1 ) ;
F_56 ( V_43 ) ;
V_141 -> V_149 = NULL ;
V_141 -> V_150 = V_161 ;
F_163 ( V_88 ) ;
F_131 ( V_88 ) ;
F_148 ( & V_88 -> V_152 -> V_153 ) ;
F_164 () ;
F_150 ( & V_88 -> V_152 -> V_153 ) ;
}
void F_165 ( struct V_80 * V_81 )
{
struct V_147 * V_141 ;
V_141 = V_88 -> V_141 ;
if ( ! V_141 || V_141 -> V_150 == V_163 )
F_156 ( V_81 ) ;
else
F_160 ( V_141 , V_81 ) ;
}
int F_166 ( struct V_80 * V_81 )
{
struct V_147 * V_141 ;
if ( ! V_88 -> V_18 || ! F_108 ( & V_88 -> V_18 -> V_101 . V_102 ) )
return 0 ;
V_141 = V_88 -> V_141 ;
if ( V_141 )
V_141 -> V_150 = V_163 ;
F_167 ( V_156 ) ;
V_88 -> V_148 = F_168 ( & V_103 ) ;
return 1 ;
}
int F_169 ( struct V_80 * V_81 )
{
struct V_147 * V_141 = V_88 -> V_141 ;
if ( ! V_88 -> V_18 || ! V_141 || ! V_141 -> V_149 )
return 0 ;
V_141 -> V_150 = V_162 ;
F_167 ( V_156 ) ;
return 1 ;
}
static int T_8 F_170 ( void )
{
int V_164 ;
for ( V_164 = 0 ; V_164 < V_165 ; V_164 ++ ) {
F_171 ( & V_166 [ V_164 ] ) ;
F_171 ( & V_167 [ V_164 ] ) ;
}
F_172 ( & V_103 ) ;
return F_173 ( & V_168 ) ;
}
static void T_9 F_174 ( void )
{
}
