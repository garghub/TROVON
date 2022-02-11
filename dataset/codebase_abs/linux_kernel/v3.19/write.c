struct V_1 * F_1 ( void )
{
struct V_1 * V_2 = F_2 ( V_3 , V_4 ) ;
if ( V_2 ) {
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_3 ( & V_2 -> V_5 ) ;
}
return V_2 ;
}
void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_3 ) ;
}
static struct V_6 * F_6 ( void )
{
struct V_6 * V_2 = F_2 ( V_7 , V_4 ) ;
if ( V_2 )
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
return V_2 ;
}
static void F_7 ( struct V_6 * V_8 )
{
F_5 ( V_8 , V_7 ) ;
}
static void F_8 ( struct V_9 * V_10 , int error )
{
V_10 -> error = error ;
F_9 () ;
F_10 ( V_11 , & V_10 -> V_12 ) ;
}
static struct V_13 *
F_11 ( struct V_14 * V_15 , struct V_16 * V_16 )
{
struct V_13 * V_17 = NULL ;
if ( F_12 ( V_16 ) )
V_17 = (struct V_13 * ) F_13 ( V_16 ) ;
else if ( F_14 ( F_15 ( V_16 ) ) )
V_17 = F_16 ( V_15 ,
V_16 ) ;
if ( V_17 ) {
F_17 ( V_17 -> V_18 != V_17 ) ;
F_18 ( & V_17 -> V_19 ) ;
}
return V_17 ;
}
static struct V_13 * F_19 ( struct V_16 * V_16 )
{
struct V_20 * V_20 = F_20 ( V_16 ) -> V_21 ;
struct V_13 * V_17 = NULL ;
F_21 ( & V_20 -> V_22 ) ;
V_17 = F_11 ( F_22 ( V_20 ) , V_16 ) ;
F_23 ( & V_20 -> V_22 ) ;
return V_17 ;
}
static void F_24 ( struct V_16 * V_16 , unsigned int V_23 , unsigned int V_24 )
{
struct V_20 * V_20 = F_20 ( V_16 ) -> V_21 ;
T_1 V_25 , V_26 ;
T_2 V_27 ;
F_21 ( & V_20 -> V_22 ) ;
V_26 = F_25 ( V_20 ) ;
V_27 = ( V_26 - 1 ) >> V_28 ;
if ( V_26 > 0 && F_26 ( V_16 ) < V_27 )
goto V_29;
V_25 = F_27 ( V_16 ) + ( ( T_1 ) V_23 + V_24 ) ;
if ( V_26 >= V_25 )
goto V_29;
F_28 ( V_20 , V_25 ) ;
F_29 ( V_20 , V_30 ) ;
V_29:
F_23 ( & V_20 -> V_22 ) ;
}
static void F_30 ( struct V_16 * V_16 )
{
F_31 ( F_20 ( V_16 ) -> V_21 , F_20 ( V_16 ) ) ;
}
static struct V_13 *
F_32 ( struct V_13 * V_31 , unsigned int V_32 )
{
struct V_13 * V_17 ;
F_17 ( V_31 != V_31 -> V_18 ) ;
F_17 ( ! F_33 ( V_33 , & V_31 -> V_18 -> V_34 ) ) ;
V_17 = V_31 ;
do {
if ( V_32 >= V_17 -> V_35 &&
V_32 < ( V_17 -> V_35 + V_17 -> V_36 ) )
return V_17 ;
V_17 = V_17 -> V_37 ;
} while ( V_17 != V_31 );
return NULL ;
}
static bool F_34 ( struct V_13 * V_17 )
{
struct V_13 * V_38 ;
unsigned int V_39 = 0 ;
unsigned int V_40 = F_35 ( V_17 -> V_41 ) ;
F_36 ( V_17 , false ) ;
do {
V_38 = F_32 ( V_17 -> V_18 , V_39 ) ;
if ( V_38 ) {
F_17 ( V_38 -> V_35 != V_39 ) ;
V_39 += V_38 -> V_36 - ( V_39 - V_38 -> V_35 ) ;
}
} while ( V_38 && V_39 < V_40 );
F_37 ( V_17 ) ;
F_17 ( V_39 > V_40 ) ;
return V_39 == V_40 ;
}
static void F_38 ( struct V_13 * V_17 )
{
if ( F_39 ( V_17 -> V_41 ) )
return;
if ( ! F_34 ( V_17 ) )
return;
F_40 ( V_17 -> V_41 ) ;
}
static int F_41 ( struct V_42 * V_43 )
{
int V_44 = 0 ;
if ( V_43 -> V_45 )
return V_46 | V_47 ;
if ( V_43 -> V_48 == V_49 )
V_44 = V_50 ;
if ( V_43 -> V_51 || V_43 -> V_52 )
V_44 |= V_53 ;
return V_44 ;
}
static void F_42 ( struct V_16 * V_16 )
{
struct V_54 * V_55 = F_43 ( F_20 ( V_16 ) -> V_21 ) ;
int V_44 = F_44 ( V_16 ) ;
F_17 ( V_44 != 0 ) ;
if ( F_45 ( & V_55 -> V_56 ) >
V_57 ) {
F_46 ( & V_55 -> V_58 ,
V_59 ) ;
}
}
static void F_47 ( struct V_13 * V_17 )
{
struct V_20 * V_20 = F_20 ( V_17 -> V_41 ) -> V_21 ;
struct V_54 * V_55 = F_43 ( V_20 ) ;
if ( ! F_48 ( V_17 , V_60 ) )
return;
F_49 ( V_17 -> V_41 ) ;
if ( F_50 ( & V_55 -> V_56 ) < V_61 )
F_51 ( & V_55 -> V_58 , V_59 ) ;
}
static void
F_52 ( struct V_13 * V_17 )
{
F_53 ( V_62 , & V_17 -> V_34 ) ;
F_53 ( V_63 , & V_17 -> V_34 ) ;
F_53 ( V_64 , & V_17 -> V_34 ) ;
F_53 ( V_60 , & V_17 -> V_34 ) ;
F_53 ( V_65 , & V_17 -> V_34 ) ;
}
static int
F_54 ( struct V_20 * V_20 , struct V_13 * V_31 ,
struct V_13 * V_17 , bool V_66 )
__releases( &inode->i_lock
static void
F_55 ( struct V_13 * V_67 ,
struct V_13 * V_68 )
{
while ( V_67 ) {
struct V_13 * V_69 = V_67 ;
V_67 = ( V_69 -> V_37 == V_68 ) ?
NULL : V_69 -> V_37 ;
F_17 ( V_68 != V_69 -> V_18 ) ;
V_69 -> V_18 = V_69 ;
V_69 -> V_37 = V_69 ;
F_56 ( V_69 ) ;
if ( ! F_33 ( V_62 , & V_69 -> V_34 ) ) {
F_57 ( V_68 ) ;
F_52 ( V_69 ) ;
if ( F_58 ( V_70 , & V_69 -> V_34 ) )
F_57 ( V_69 ) ;
else
F_17 ( 1 ) ;
} else {
F_17 ( F_33 ( V_71 , & V_69 -> V_34 ) ) ;
F_52 ( V_69 ) ;
F_59 ( V_69 ) ;
}
}
}
static struct V_13 *
F_60 ( struct V_16 * V_16 , bool V_66 )
{
struct V_20 * V_20 = F_20 ( V_16 ) -> V_21 ;
struct V_13 * V_31 , * V_69 ;
struct V_13 * V_67 = NULL ;
unsigned int V_72 ;
int V_44 ;
V_73:
V_72 = 0 ;
F_17 ( V_67 ) ;
F_21 ( & V_20 -> V_22 ) ;
V_31 = F_11 ( F_22 ( V_20 ) , V_16 ) ;
if ( ! V_31 ) {
F_23 ( & V_20 -> V_22 ) ;
return NULL ;
}
V_44 = F_36 ( V_31 , true ) ;
if ( V_44 < 0 ) {
F_23 ( & V_20 -> V_22 ) ;
if ( ! V_66 && V_44 == - V_74 ) {
F_61 ( V_31 ) ;
F_57 ( V_31 ) ;
goto V_73;
}
F_57 ( V_31 ) ;
return F_62 ( V_44 ) ;
}
V_69 = V_31 ;
do {
F_17 ( V_69 -> V_75 !=
( V_31 -> V_75 + V_72 ) ) ;
V_72 += V_69 -> V_36 ;
if ( ! F_63 ( V_69 ) ) {
V_44 = F_54 ( V_20 , V_31 ,
V_69 , V_66 ) ;
if ( V_44 == 0 )
goto V_73;
return F_62 ( V_44 ) ;
}
V_69 = V_69 -> V_37 ;
} while ( V_69 != V_31 );
V_69 = V_31 ;
do {
F_64 ( V_69 ) ;
V_69 = V_69 -> V_37 ;
} while ( V_69 != V_31 );
if ( V_31 -> V_37 != V_31 ) {
V_67 = V_31 -> V_37 ;
V_31 -> V_37 = V_31 ;
V_31 -> V_36 = V_72 ;
}
F_52 ( V_31 ) ;
if ( ! F_65 ( V_70 , & V_31 -> V_34 ) )
F_18 ( & V_31 -> V_19 ) ;
F_37 ( V_31 ) ;
F_23 ( & V_20 -> V_22 ) ;
F_55 ( V_67 , V_31 ) ;
return V_31 ;
}
static int F_66 ( struct V_76 * V_77 ,
struct V_16 * V_16 , bool V_66 )
{
struct V_13 * V_17 ;
int V_44 = 0 ;
V_17 = F_60 ( V_16 , V_66 ) ;
if ( ! V_17 )
goto V_29;
V_44 = F_67 ( V_17 ) ;
if ( F_68 ( V_17 ) )
goto V_29;
F_42 ( V_16 ) ;
F_17 ( F_33 ( V_71 , & V_17 -> V_34 ) ) ;
V_44 = 0 ;
if ( ! F_69 ( V_77 , V_17 ) ) {
F_70 ( V_17 ) ;
V_44 = V_77 -> V_78 ;
}
V_29:
return V_44 ;
}
static int F_71 ( struct V_16 * V_16 , struct V_42 * V_43 , struct V_76 * V_77 )
{
struct V_20 * V_20 = F_20 ( V_16 ) -> V_21 ;
int V_44 ;
F_29 ( V_20 , V_79 ) ;
F_29 ( V_20 , V_80 ) ;
F_72 ( V_77 , F_26 ( V_16 ) ) ;
V_44 = F_66 ( V_77 , V_16 , V_43 -> V_48 == V_81 ) ;
if ( V_44 == - V_74 ) {
F_73 ( V_43 , V_16 ) ;
V_44 = 0 ;
}
return V_44 ;
}
static int F_74 ( struct V_16 * V_16 , struct V_42 * V_43 )
{
struct V_76 V_77 ;
int V_82 ;
F_75 ( & V_77 , V_16 -> V_83 -> V_21 , F_41 ( V_43 ) ,
false , & V_84 ) ;
V_82 = F_71 ( V_16 , V_43 , & V_77 ) ;
F_76 ( & V_77 ) ;
if ( V_82 < 0 )
return V_82 ;
if ( V_77 . V_78 < 0 )
return V_77 . V_78 ;
return 0 ;
}
int F_77 ( struct V_16 * V_16 , struct V_42 * V_43 )
{
int V_44 ;
V_44 = F_74 ( V_16 , V_43 ) ;
F_78 ( V_16 ) ;
return V_44 ;
}
static int F_79 ( struct V_16 * V_16 , struct V_42 * V_43 , void * V_85 )
{
int V_44 ;
V_44 = F_71 ( V_16 , V_43 , V_85 ) ;
F_78 ( V_16 ) ;
return V_44 ;
}
int F_80 ( struct V_86 * V_83 , struct V_42 * V_43 )
{
struct V_20 * V_20 = V_83 -> V_21 ;
unsigned long * V_87 = & F_22 ( V_20 ) -> V_12 ;
struct V_76 V_77 ;
int V_82 ;
V_82 = F_81 ( V_87 , V_88 ,
V_89 , V_90 ) ;
if ( V_82 )
goto V_91;
F_29 ( V_20 , V_92 ) ;
F_75 ( & V_77 , V_20 , F_41 ( V_43 ) , false ,
& V_84 ) ;
V_82 = F_82 ( V_83 , V_43 , F_79 , & V_77 ) ;
F_76 ( & V_77 ) ;
F_83 ( V_88 , V_87 ) ;
F_84 () ;
F_85 ( V_87 , V_88 ) ;
if ( V_82 < 0 )
goto V_91;
V_82 = V_77 . V_78 ;
if ( V_82 < 0 )
goto V_91;
return 0 ;
V_91:
return V_82 ;
}
static void F_86 ( struct V_20 * V_20 , struct V_13 * V_17 )
{
struct V_14 * V_15 = F_22 ( V_20 ) ;
F_17 ( V_17 -> V_37 != V_17 ) ;
F_63 ( V_17 ) ;
F_21 ( & V_20 -> V_22 ) ;
if ( ! V_15 -> V_93 &&
F_87 ( V_20 ) -> F_88 ( V_20 , V_94 ) )
V_20 -> V_95 ++ ;
if ( F_89 ( ! F_15 ( V_17 -> V_41 ) ) ) {
F_10 ( V_96 , & V_17 -> V_34 ) ;
F_90 ( V_17 -> V_41 ) ;
F_91 ( V_17 -> V_41 , ( unsigned long ) V_17 ) ;
}
V_15 -> V_93 ++ ;
F_92 ( F_65 ( V_70 , & V_17 -> V_34 ) ) ;
F_18 ( & V_17 -> V_19 ) ;
F_23 ( & V_20 -> V_22 ) ;
}
static void F_93 ( struct V_13 * V_17 )
{
struct V_20 * V_20 = V_17 -> V_97 -> V_98 -> V_99 ;
struct V_14 * V_15 = F_22 ( V_20 ) ;
struct V_13 * V_31 ;
if ( F_48 ( V_17 , V_65 ) ) {
V_31 = V_17 -> V_18 ;
F_21 ( & V_20 -> V_22 ) ;
if ( F_89 ( ! F_15 ( V_31 -> V_41 ) ) ) {
F_91 ( V_31 -> V_41 , 0 ) ;
F_94 ( V_31 -> V_41 ) ;
F_84 () ;
F_95 ( V_31 -> V_41 , V_100 ) ;
F_53 ( V_96 , & V_31 -> V_34 ) ;
}
V_15 -> V_93 -- ;
F_23 ( & V_20 -> V_22 ) ;
} else {
F_21 ( & V_20 -> V_22 ) ;
V_15 -> V_93 -- ;
F_23 ( & V_20 -> V_22 ) ;
}
if ( F_58 ( V_70 , & V_17 -> V_34 ) )
F_57 ( V_17 ) ;
}
static void
F_96 ( struct V_13 * V_17 )
{
F_97 ( V_17 -> V_41 ) ;
}
static struct V_13 *
F_16 ( struct V_14 * V_15 ,
struct V_16 * V_16 )
{
struct V_13 * V_101 , * V_102 ;
struct V_103 V_104 ;
struct V_20 * V_20 = & V_15 -> V_105 ;
F_98 ( & V_104 , V_20 ) ;
V_101 = F_99 ( V_20 , & V_104 , V_16 ) ;
if ( V_101 )
return V_101 -> V_18 ;
F_100 (freq, t, &cinfo.mds->list, wb_list) {
if ( V_101 -> V_41 == V_16 )
return V_101 -> V_18 ;
}
return NULL ;
}
void
F_101 ( struct V_13 * V_17 , struct V_106 * V_107 ,
struct V_103 * V_104 )
{
F_10 ( V_71 , & ( V_17 ) -> V_34 ) ;
F_21 ( V_104 -> V_108 ) ;
F_102 ( V_17 , V_107 ) ;
V_104 -> V_109 -> V_110 ++ ;
F_23 ( V_104 -> V_108 ) ;
if ( ! V_104 -> V_111 ) {
F_103 ( V_17 -> V_41 , V_112 ) ;
F_104 ( F_20 ( V_17 -> V_41 ) -> V_58 ,
V_113 ) ;
F_105 ( V_17 -> V_97 -> V_98 -> V_99 ,
V_114 ) ;
}
}
void
F_106 ( struct V_13 * V_17 ,
struct V_103 * V_104 )
{
if ( ! F_58 ( V_71 , & ( V_17 ) -> V_34 ) )
return;
F_107 ( V_17 ) ;
V_104 -> V_109 -> V_110 -- ;
}
static void F_98 ( struct V_103 * V_104 ,
struct V_20 * V_20 )
{
V_104 -> V_108 = & V_20 -> V_22 ;
V_104 -> V_109 = & F_22 ( V_20 ) -> V_115 ;
V_104 -> V_116 = F_108 ( V_20 ) ;
V_104 -> V_111 = NULL ;
V_104 -> V_117 = & V_118 ;
}
void F_109 ( struct V_103 * V_104 ,
struct V_20 * V_20 ,
struct V_119 * V_111 )
{
if ( V_111 )
F_110 ( V_104 , V_111 ) ;
else
F_98 ( V_104 , V_20 ) ;
}
void
F_111 ( struct V_13 * V_17 , struct V_120 * V_121 ,
struct V_103 * V_104 )
{
if ( F_112 ( V_17 , V_121 , V_104 ) )
return;
F_101 ( V_17 , & V_104 -> V_109 -> V_122 , V_104 ) ;
}
static void
F_113 ( struct V_16 * V_16 )
{
F_114 ( V_16 , V_112 ) ;
F_115 ( F_20 ( V_16 ) -> V_58 , V_113 ) ;
}
static void
F_64 ( struct V_13 * V_17 )
{
if ( F_33 ( V_71 , & V_17 -> V_34 ) ) {
struct V_20 * V_20 = V_17 -> V_97 -> V_98 -> V_99 ;
struct V_103 V_104 ;
F_98 ( & V_104 , V_20 ) ;
if ( ! F_116 ( V_17 , & V_104 ) ) {
F_106 ( V_17 , & V_104 ) ;
}
F_113 ( V_17 -> V_41 ) ;
}
}
int F_117 ( struct V_6 * V_8 )
{
if ( V_8 -> V_123 . V_124 == V_125 )
return V_8 -> V_121 == NULL ;
return V_8 -> V_123 . V_124 != V_126 ;
}
static void F_118 ( struct V_6 * V_8 )
{
struct V_103 V_104 ;
unsigned long V_127 = 0 ;
if ( F_33 ( V_128 , & V_8 -> V_12 ) )
goto V_29;
F_98 ( & V_104 , V_8 -> V_20 ) ;
while ( ! F_119 ( & V_8 -> V_5 ) ) {
struct V_13 * V_17 = F_120 ( V_8 -> V_5 . V_129 ) ;
V_127 += V_17 -> V_36 ;
F_107 ( V_17 ) ;
if ( F_33 ( V_130 , & V_8 -> V_12 ) &&
( V_8 -> V_131 < V_127 ) ) {
F_30 ( V_17 -> V_41 ) ;
F_8 ( V_17 -> V_97 , V_8 -> error ) ;
goto V_132;
}
if ( F_117 ( V_8 ) ) {
memcpy ( & V_17 -> V_133 , & V_8 -> V_123 . V_134 , sizeof( V_17 -> V_133 ) ) ;
F_111 ( V_17 , V_8 -> V_121 , & V_104 ) ;
goto V_129;
}
V_132:
F_93 ( V_17 ) ;
V_129:
F_56 ( V_17 ) ;
F_47 ( V_17 ) ;
F_57 ( V_17 ) ;
}
V_29:
V_8 -> V_135 ( V_8 ) ;
}
unsigned long
F_121 ( struct V_103 * V_104 )
{
return V_104 -> V_109 -> V_110 ;
}
int
F_122 ( struct V_106 * V_136 , struct V_106 * V_107 ,
struct V_103 * V_104 , int V_137 )
{
struct V_13 * V_17 , * V_38 ;
int V_44 = 0 ;
F_100 (req, tmp, src, wb_list) {
if ( ! F_63 ( V_17 ) )
continue;
F_18 ( & V_17 -> V_19 ) ;
if ( F_123 ( V_104 -> V_108 ) )
F_124 ( V_17 , V_38 , V_138 ) ;
F_106 ( V_17 , V_104 ) ;
F_102 ( V_17 , V_107 ) ;
V_44 ++ ;
if ( ( V_44 == V_137 ) && ! V_104 -> V_111 )
break;
}
return V_44 ;
}
int
F_125 ( struct V_20 * V_20 , struct V_106 * V_107 ,
struct V_103 * V_104 )
{
int V_44 = 0 ;
F_21 ( V_104 -> V_108 ) ;
if ( V_104 -> V_109 -> V_110 > 0 ) {
const int V_137 = V_139 ;
V_44 = F_122 ( & V_104 -> V_109 -> V_122 , V_107 ,
V_104 , V_137 ) ;
V_44 += F_126 ( V_20 , V_104 , V_137 - V_44 ) ;
}
F_23 ( V_104 -> V_108 ) ;
return V_44 ;
}
static struct V_13 * F_127 ( struct V_20 * V_20 ,
struct V_16 * V_16 ,
unsigned int V_23 ,
unsigned int V_127 )
{
struct V_13 * V_17 ;
unsigned int V_140 ;
unsigned int V_25 ;
int error ;
if ( ! F_12 ( V_16 ) )
return NULL ;
V_25 = V_23 + V_127 ;
F_21 ( & V_20 -> V_22 ) ;
for (; ; ) {
V_17 = F_11 ( F_22 ( V_20 ) , V_16 ) ;
if ( V_17 == NULL )
goto V_141;
F_17 ( V_17 -> V_18 != V_17 ) ;
F_17 ( V_17 -> V_37 != V_17 ) ;
V_140 = V_17 -> V_75 + V_17 -> V_36 ;
if ( V_23 > V_140
|| V_25 < V_17 -> V_75 )
goto V_142;
if ( F_63 ( V_17 ) )
break;
F_23 ( & V_20 -> V_22 ) ;
error = F_128 ( V_17 ) ;
F_57 ( V_17 ) ;
if ( error != 0 )
goto V_91;
F_21 ( & V_20 -> V_22 ) ;
}
if ( V_23 < V_17 -> V_75 ) {
V_17 -> V_75 = V_23 ;
V_17 -> V_35 = V_23 ;
}
if ( V_25 > V_140 )
V_17 -> V_36 = V_25 - V_17 -> V_75 ;
else
V_17 -> V_36 = V_140 - V_17 -> V_75 ;
V_141:
if ( V_17 )
F_64 ( V_17 ) ;
F_23 ( & V_20 -> V_22 ) ;
return V_17 ;
V_142:
F_23 ( & V_20 -> V_22 ) ;
F_57 ( V_17 ) ;
error = F_129 ( V_20 , V_16 ) ;
V_91:
return F_62 ( error ) ;
}
static struct V_13 * F_130 ( struct V_9 * V_10 ,
struct V_16 * V_16 , unsigned int V_23 , unsigned int V_127 )
{
struct V_20 * V_20 = F_20 ( V_16 ) -> V_21 ;
struct V_13 * V_17 ;
V_17 = F_127 ( V_20 , V_16 , V_23 , V_127 ) ;
if ( V_17 != NULL )
goto V_29;
V_17 = F_131 ( V_10 , V_16 , NULL , V_23 , V_127 ) ;
if ( F_68 ( V_17 ) )
goto V_29;
F_86 ( V_20 , V_17 ) ;
V_29:
return V_17 ;
}
static int F_132 ( struct V_9 * V_10 , struct V_16 * V_16 ,
unsigned int V_23 , unsigned int V_24 )
{
struct V_13 * V_17 ;
V_17 = F_130 ( V_10 , V_16 , V_23 , V_24 ) ;
if ( F_68 ( V_17 ) )
return F_67 ( V_17 ) ;
F_24 ( V_16 , V_23 , V_24 ) ;
F_38 ( V_17 ) ;
F_96 ( V_17 ) ;
F_133 ( V_17 ) ;
return 0 ;
}
int F_134 ( struct V_143 * V_143 , struct V_16 * V_16 )
{
struct V_9 * V_10 = F_135 ( V_143 ) ;
struct V_144 * V_145 ;
struct V_13 * V_17 ;
int V_146 , V_147 ;
do {
V_17 = F_19 ( V_16 ) ;
if ( V_17 == NULL )
return 0 ;
V_145 = V_17 -> V_148 ;
V_146 = V_17 -> V_41 != V_16 || V_17 -> V_97 != V_10 ;
V_146 |= V_17 -> V_37 != V_17 ;
if ( V_145 && V_10 -> V_98 -> V_99 -> V_149 != NULL ) {
V_146 |= V_145 -> V_150 . V_151 != V_152 -> V_153
|| V_145 -> V_150 . V_154 != V_152 -> V_155 ;
}
F_57 ( V_17 ) ;
if ( ! V_146 )
return 0 ;
V_147 = F_129 ( F_20 ( V_16 ) -> V_21 , V_16 ) ;
} while ( V_147 == 0 );
return V_147 ;
}
int
F_136 ( struct V_143 * V_156 , struct V_20 * V_20 )
{
struct V_9 * V_10 = F_135 ( V_156 ) ;
struct V_157 * V_158 = F_43 ( V_20 ) -> V_159 -> V_160 ;
return F_137 ( V_158 , V_10 -> V_161 ) ;
}
bool F_138 ( struct V_9 * V_10 )
{
return F_139 ( V_10 -> V_161 ) ;
}
static bool F_140 ( struct V_16 * V_16 , struct V_20 * V_20 )
{
struct V_14 * V_15 = F_22 ( V_20 ) ;
if ( F_141 ( V_20 ) )
goto V_29;
if ( V_15 -> V_162 & V_163 )
return false ;
F_142 () ;
if ( F_33 ( V_164 , & V_15 -> V_12 ) )
return false ;
V_29:
if ( V_15 -> V_162 & V_165 )
return false ;
return F_39 ( V_16 ) != 0 ;
}
static int F_143 ( struct V_143 * V_143 , struct V_16 * V_16 , struct V_20 * V_20 )
{
if ( V_143 -> V_166 & V_167 )
return 0 ;
if ( ! F_140 ( V_16 , V_20 ) )
return 0 ;
if ( F_87 ( V_20 ) -> F_88 ( V_20 , V_94 ) )
return 1 ;
if ( V_20 -> V_149 == NULL || ( V_20 -> V_149 -> V_168 == 0 &&
V_20 -> V_149 -> V_169 == V_170 &&
V_20 -> V_149 -> V_171 != V_172 ) )
return 1 ;
return 0 ;
}
int F_144 ( struct V_143 * V_143 , struct V_16 * V_16 ,
unsigned int V_23 , unsigned int V_24 )
{
struct V_9 * V_10 = F_135 ( V_143 ) ;
struct V_20 * V_20 = F_20 ( V_16 ) -> V_21 ;
int V_147 = 0 ;
F_29 ( V_20 , V_173 ) ;
F_145 ( L_1 ,
V_143 , V_24 , ( long long ) ( F_27 ( V_16 ) + V_23 ) ) ;
if ( F_143 ( V_143 , V_16 , V_20 ) ) {
V_24 = V_137 ( V_24 + V_23 , F_35 ( V_16 ) ) ;
V_23 = 0 ;
}
V_147 = F_132 ( V_10 , V_16 , V_23 , V_24 ) ;
if ( V_147 < 0 )
F_30 ( V_16 ) ;
else
F_97 ( V_16 ) ;
F_145 ( L_2 ,
V_147 , ( long long ) F_25 ( V_20 ) ) ;
return V_147 ;
}
static int F_146 ( int V_174 )
{
switch ( V_174 & ( V_46 | V_53 ) ) {
case V_46 :
return V_175 ;
case V_53 :
return V_176 ;
}
return V_177 ;
}
static void F_147 ( struct V_6 * V_8 ,
struct V_178 * V_179 ,
struct V_180 * V_181 , int V_174 )
{
struct V_20 * V_20 = V_8 -> V_20 ;
int V_182 = F_146 ( V_174 ) ;
V_181 -> V_182 = V_182 ;
F_87 ( V_20 ) -> F_148 ( V_8 , V_179 ) ;
F_149 ( F_43 ( V_20 ) -> V_183 ,
& V_181 -> V_184 , V_179 , V_8 ) ;
}
static void F_70 ( struct V_13 * V_17 )
{
F_96 ( V_17 ) ;
F_56 ( V_17 ) ;
F_47 ( V_17 ) ;
F_57 ( V_17 ) ;
}
static void F_150 ( struct V_106 * V_31 )
{
struct V_13 * V_17 ;
while ( ! F_119 ( V_31 ) ) {
V_17 = F_120 ( V_31 -> V_129 ) ;
F_107 ( V_17 ) ;
F_70 ( V_17 ) ;
}
}
void F_75 ( struct V_76 * V_77 ,
struct V_20 * V_20 , int V_185 , bool V_186 ,
const struct V_187 * V_188 )
{
struct V_54 * V_189 = F_43 ( V_20 ) ;
const struct V_190 * V_191 = & V_192 ;
#ifdef F_151
if ( V_189 -> V_193 && ! V_186 )
V_191 = V_189 -> V_193 -> V_194 ;
#endif
F_152 ( V_77 , V_20 , V_191 , V_188 , & V_195 ,
V_189 -> V_196 , V_185 ) ;
}
void F_153 ( struct V_76 * V_77 )
{
V_77 -> V_191 = & V_192 ;
V_77 -> V_197 = F_43 ( V_77 -> V_198 ) -> V_196 ;
}
void F_154 ( struct V_199 * V_200 , void * V_201 )
{
struct V_1 * V_85 = V_201 ;
F_87 ( V_85 -> V_20 ) -> F_155 ( V_200 , V_85 ) ;
}
static void F_156 ( struct V_6 * V_8 )
{
}
static int F_157 ( const struct V_20 * V_20 )
{
T_3 V_202 = V_20 -> V_203 ;
int V_204 = 0 ;
if ( F_14 ( V_202 & V_205 ) )
V_204 = V_206 ;
if ( F_14 ( ( V_202 & V_207 ) && ( V_202 & V_208 ) ) )
V_204 |= V_209 ;
if ( F_14 ( V_204 && F_158 ( V_202 ) ) )
return V_204 ;
return 0 ;
}
static int F_159 ( struct V_199 * V_200 ,
struct V_6 * V_8 ,
struct V_20 * V_20 )
{
int V_147 ;
V_147 = F_87 ( V_20 ) -> F_160 ( V_200 , V_8 ) ;
if ( V_147 != 0 )
return V_147 ;
F_161 ( V_20 , V_210 , V_8 -> V_211 . V_24 ) ;
if ( V_8 -> V_211 . V_123 -> V_124 < V_8 -> args . V_212 &&
V_200 -> V_213 >= 0 ) {
static unsigned long V_214 ;
if ( F_162 ( V_214 , V_215 ) ) {
F_145 ( L_3
L_4 ,
F_43 ( V_20 ) -> V_183 -> V_216 ,
V_8 -> V_211 . V_123 -> V_124 , V_8 -> args . V_212 ) ;
V_214 = V_215 + 300 * V_217 ;
}
}
if ( F_157 ( V_20 ) )
F_163 ( V_20 ) ;
return 0 ;
}
static void F_164 ( struct V_199 * V_200 ,
struct V_6 * V_8 )
{
struct V_218 * V_219 = & V_8 -> args ;
struct V_220 * V_221 = & V_8 -> V_211 ;
if ( V_221 -> V_24 < V_219 -> V_24 ) {
static unsigned long V_214 ;
F_29 ( V_8 -> V_20 , V_222 ) ;
if ( V_221 -> V_24 == 0 ) {
if ( F_162 ( V_214 , V_215 ) ) {
F_165 ( V_223
L_5 ,
V_219 -> V_24 ) ;
V_214 = V_215 + 300 * V_217 ;
}
F_166 ( V_8 , - V_224 , V_219 -> V_23 ) ;
V_200 -> V_213 = - V_224 ;
return;
}
if ( V_221 -> V_123 -> V_124 != V_225 ) {
V_8 -> V_226 += V_221 -> V_24 ;
V_219 -> V_23 += V_221 -> V_24 ;
V_219 -> V_227 += V_221 -> V_24 ;
V_219 -> V_24 -= V_221 -> V_24 ;
} else {
V_219 -> V_212 = V_126 ;
}
F_167 ( V_200 ) ;
}
}
static int F_168 ( struct V_14 * V_15 , int V_228 )
{
int V_44 ;
if ( ! F_65 ( V_229 , & V_15 -> V_12 ) )
return 1 ;
if ( ! V_228 )
return 0 ;
V_44 = F_169 ( & V_15 -> V_12 ,
V_229 ,
V_89 ,
V_90 ) ;
return ( V_44 < 0 ) ? V_44 : 1 ;
}
static void F_170 ( struct V_14 * V_15 )
{
F_53 ( V_229 , & V_15 -> V_12 ) ;
F_84 () ;
F_85 ( & V_15 -> V_12 , V_229 ) ;
}
void F_171 ( struct V_1 * V_85 )
{
F_172 ( V_85 -> V_230 ) ;
F_4 ( V_85 ) ;
}
int F_173 ( struct V_231 * V_232 , struct V_1 * V_85 ,
const struct V_233 * V_234 ,
int V_174 , int V_12 )
{
struct V_199 * V_200 ;
int V_182 = F_146 ( V_174 ) ;
struct V_178 V_179 = {
. V_235 = & V_85 -> args ,
. V_236 = & V_85 -> V_211 ,
. V_237 = V_85 -> V_161 ,
} ;
struct V_180 V_181 = {
. V_200 = & V_85 -> V_200 ,
. V_184 = V_232 ,
. V_178 = & V_179 ,
. V_238 = V_234 ,
. V_239 = V_85 ,
. V_240 = V_241 ,
. V_12 = V_242 | V_12 ,
. V_182 = V_182 ,
} ;
F_87 ( V_85 -> V_20 ) -> F_174 ( V_85 , & V_179 ) ;
F_145 ( L_6 , V_85 -> V_200 . V_243 ) ;
F_175 ( F_43 ( V_85 -> V_20 ) -> V_183 ,
V_244 , & V_181 . V_184 , & V_179 ) ;
V_200 = F_176 ( & V_181 ) ;
if ( F_68 ( V_200 ) )
return F_67 ( V_200 ) ;
if ( V_174 & V_245 )
F_177 ( V_200 ) ;
F_178 ( V_200 ) ;
return 0 ;
}
static T_1 F_179 ( struct V_106 * V_31 )
{
T_1 V_246 = 0 ;
struct V_13 * V_17 ;
F_180 (req, head, wb_list)
if ( V_246 < ( F_181 ( V_17 ) + V_17 -> V_36 ) )
V_246 = F_181 ( V_17 ) + V_17 -> V_36 ;
return V_246 ;
}
void F_182 ( struct V_1 * V_85 ,
struct V_106 * V_31 ,
struct V_120 * V_121 ,
struct V_103 * V_104 )
{
struct V_13 * V_247 = F_120 ( V_31 -> V_129 ) ;
struct V_20 * V_20 = V_247 -> V_97 -> V_98 -> V_99 ;
F_183 ( V_31 , & V_85 -> V_5 ) ;
V_85 -> V_20 = V_20 ;
V_85 -> V_161 = V_247 -> V_97 -> V_161 ;
V_85 -> V_121 = V_121 ;
if ( V_121 )
V_85 -> V_246 = F_179 ( & V_85 -> V_5 ) ;
V_85 -> V_248 = & V_249 ;
V_85 -> V_117 = V_104 -> V_117 ;
V_85 -> V_111 = V_104 -> V_111 ;
V_85 -> args . V_250 = F_184 ( V_85 -> V_20 ) ;
V_85 -> args . V_23 = 0 ;
V_85 -> args . V_24 = 0 ;
V_85 -> V_230 = F_185 ( V_247 -> V_97 ) ;
V_85 -> V_211 . V_251 = & V_85 -> V_251 ;
V_85 -> V_211 . V_123 = & V_85 -> V_123 ;
F_186 ( & V_85 -> V_251 ) ;
}
void F_187 ( struct V_106 * V_252 ,
struct V_120 * V_121 ,
struct V_103 * V_104 )
{
struct V_13 * V_17 ;
while ( ! F_119 ( V_252 ) ) {
V_17 = F_120 ( V_252 -> V_129 ) ;
F_107 ( V_17 ) ;
F_111 ( V_17 , V_121 , V_104 ) ;
if ( ! V_104 -> V_111 ) {
F_114 ( V_17 -> V_41 , V_112 ) ;
F_115 ( F_20 ( V_17 -> V_41 ) -> V_58 ,
V_113 ) ;
}
F_133 ( V_17 ) ;
}
}
static int
F_188 ( struct V_20 * V_20 , struct V_106 * V_31 , int V_174 ,
struct V_103 * V_104 )
{
struct V_1 * V_85 ;
V_85 = F_1 () ;
if ( ! V_85 )
goto V_253;
F_182 ( V_85 , V_31 , NULL , V_104 ) ;
F_189 ( & V_104 -> V_109 -> V_254 ) ;
return F_173 ( F_190 ( V_20 ) , V_85 , V_85 -> V_248 ,
V_174 , 0 ) ;
V_253:
F_187 ( V_31 , NULL , V_104 ) ;
V_104 -> V_117 -> V_255 ( F_22 ( V_20 ) ) ;
return - V_256 ;
}
static void F_191 ( struct V_199 * V_200 , void * V_201 )
{
struct V_1 * V_85 = V_201 ;
F_145 ( L_7 ,
V_200 -> V_243 , V_200 -> V_213 ) ;
F_87 ( V_85 -> V_20 ) -> F_192 ( V_200 , V_85 ) ;
}
static void F_193 ( struct V_1 * V_85 )
{
struct V_13 * V_17 ;
int V_147 = V_85 -> V_200 . V_213 ;
struct V_103 V_104 ;
struct V_54 * V_55 ;
while ( ! F_119 ( & V_85 -> V_5 ) ) {
V_17 = F_120 ( V_85 -> V_5 . V_129 ) ;
F_107 ( V_17 ) ;
F_113 ( V_17 -> V_41 ) ;
F_145 ( L_8 ,
V_17 -> V_97 -> V_98 -> V_257 -> V_258 ,
( unsigned long long ) F_194 ( V_17 -> V_97 -> V_98 -> V_99 ) ,
V_17 -> V_36 ,
( long long ) F_181 ( V_17 ) ) ;
if ( V_147 < 0 ) {
F_8 ( V_17 -> V_97 , V_147 ) ;
F_93 ( V_17 ) ;
F_145 ( L_9 , V_147 ) ;
goto V_129;
}
if ( ! memcmp ( & V_17 -> V_133 , & V_85 -> V_123 . V_134 , sizeof( V_17 -> V_133 ) ) ) {
F_93 ( V_17 ) ;
F_145 ( L_10 ) ;
goto V_129;
}
F_145 ( L_11 ) ;
F_96 ( V_17 ) ;
F_10 ( V_259 , & V_17 -> V_97 -> V_12 ) ;
V_129:
F_133 ( V_17 ) ;
}
V_55 = F_43 ( V_85 -> V_20 ) ;
if ( F_195 ( & V_55 -> V_56 ) < V_61 )
F_51 ( & V_55 -> V_58 , V_59 ) ;
F_109 ( & V_104 , V_85 -> V_20 , V_85 -> V_111 ) ;
if ( F_196 ( & V_104 . V_109 -> V_254 ) )
F_170 ( F_22 ( V_85 -> V_20 ) ) ;
}
static void F_197 ( void * V_201 )
{
struct V_1 * V_85 = V_201 ;
V_85 -> V_117 -> V_260 ( V_85 ) ;
F_171 ( V_201 ) ;
}
int F_198 ( struct V_20 * V_20 , struct V_106 * V_31 ,
int V_174 , struct V_103 * V_104 )
{
int V_147 ;
V_147 = F_199 ( V_20 , V_31 , V_174 , V_104 ) ;
if ( V_147 == V_261 )
V_147 = F_188 ( V_20 , V_31 , V_174 , V_104 ) ;
return V_147 ;
}
int F_200 ( struct V_20 * V_20 , int V_174 )
{
F_201 ( V_31 ) ;
struct V_103 V_104 ;
int V_228 = V_174 & V_245 ;
int V_211 ;
V_211 = F_168 ( F_22 ( V_20 ) , V_228 ) ;
if ( V_211 <= 0 )
goto V_262;
F_98 ( & V_104 , V_20 ) ;
V_211 = F_125 ( V_20 , & V_31 , & V_104 ) ;
if ( V_211 ) {
int error ;
error = F_198 ( V_20 , & V_31 , V_174 , & V_104 ) ;
if ( error < 0 )
return error ;
if ( ! V_228 )
goto V_262;
error = F_202 ( & F_22 ( V_20 ) -> V_12 ,
V_229 ,
V_89 ,
V_90 ) ;
if ( error < 0 )
return error ;
} else
F_170 ( F_22 ( V_20 ) ) ;
return V_211 ;
V_262:
F_105 ( V_20 , V_114 ) ;
return V_211 ;
}
static int F_203 ( struct V_20 * V_20 , struct V_42 * V_43 )
{
struct V_14 * V_15 = F_22 ( V_20 ) ;
int V_12 = V_245 ;
int V_44 = 0 ;
if ( ! V_15 -> V_115 . V_110 )
return V_44 ;
if ( V_43 -> V_48 == V_81 ) {
if ( V_15 -> V_115 . V_110 <= ( V_15 -> V_93 >> 1 ) )
goto V_262;
V_12 = 0 ;
}
V_44 = F_200 ( V_20 , V_12 ) ;
if ( V_44 >= 0 ) {
if ( V_43 -> V_48 == V_81 ) {
if ( V_44 < V_43 -> V_263 )
V_43 -> V_263 -= V_44 ;
else
V_43 -> V_263 = 0 ;
}
return 0 ;
}
V_262:
F_105 ( V_20 , V_114 ) ;
return V_44 ;
}
int F_204 ( struct V_20 * V_20 , struct V_42 * V_43 )
{
return F_203 ( V_20 , V_43 ) ;
}
int F_205 ( struct V_20 * V_20 )
{
struct V_42 V_43 = {
. V_48 = V_49 ,
. V_263 = V_264 ,
. V_265 = 0 ,
. V_266 = V_267 ,
} ;
int V_44 ;
F_206 ( V_20 ) ;
V_44 = F_207 ( V_20 , & V_43 ) ;
F_208 ( V_20 , V_44 ) ;
return V_44 ;
}
int F_209 ( struct V_20 * V_20 , struct V_16 * V_16 )
{
struct V_13 * V_17 ;
int V_44 = 0 ;
F_210 ( V_16 ) ;
V_17 = F_60 ( V_16 , false ) ;
if ( F_68 ( V_17 ) ) {
V_44 = F_67 ( V_17 ) ;
} else if ( V_17 ) {
F_93 ( V_17 ) ;
F_211 ( V_16 , V_268 ) ;
F_133 ( V_17 ) ;
}
return V_44 ;
}
int F_129 ( struct V_20 * V_20 , struct V_16 * V_16 )
{
T_1 V_265 = F_27 ( V_16 ) ;
T_1 V_266 = V_265 + ( T_1 ) ( V_268 - 1 ) ;
struct V_42 V_43 = {
. V_48 = V_49 ,
. V_263 = 0 ,
. V_265 = V_265 ,
. V_266 = V_266 ,
} ;
int V_44 ;
F_212 ( V_20 ) ;
for (; ; ) {
F_210 ( V_16 ) ;
if ( F_213 ( V_16 ) ) {
V_44 = F_74 ( V_16 , & V_43 ) ;
if ( V_44 < 0 )
goto V_269;
continue;
}
V_44 = 0 ;
if ( ! F_12 ( V_16 ) )
break;
V_44 = F_200 ( V_20 , V_245 ) ;
if ( V_44 < 0 )
goto V_269;
}
V_269:
F_214 ( V_20 , V_44 ) ;
return V_44 ;
}
int F_215 ( struct V_86 * V_83 , struct V_16 * V_270 ,
struct V_16 * V_16 , enum V_271 V_202 )
{
if ( F_12 ( V_16 ) )
return - V_272 ;
if ( ! F_216 ( V_16 , V_273 ) )
return - V_272 ;
return F_217 ( V_83 , V_270 , V_16 , V_202 ) ;
}
int T_4 F_218 ( void )
{
V_274 = F_219 ( L_12 ,
sizeof( struct V_6 ) ,
0 , V_275 ,
NULL ) ;
if ( V_274 == NULL )
return - V_256 ;
V_7 = F_220 ( V_276 ,
V_274 ) ;
if ( V_7 == NULL )
goto V_277;
V_278 = F_219 ( L_13 ,
sizeof( struct V_1 ) ,
0 , V_275 ,
NULL ) ;
if ( V_278 == NULL )
goto V_279;
V_3 = F_220 ( V_280 ,
V_278 ) ;
if ( V_3 == NULL )
goto V_281;
V_282 = ( 16 * F_221 ( V_283 ) ) << ( V_284 - 10 ) ;
if ( V_282 > 256 * 1024 )
V_282 = 256 * 1024 ;
return 0 ;
V_281:
F_222 ( V_278 ) ;
V_279:
F_223 ( V_7 ) ;
V_277:
F_222 ( V_274 ) ;
return - V_256 ;
}
void F_224 ( void )
{
F_223 ( V_3 ) ;
F_222 ( V_278 ) ;
F_223 ( V_7 ) ;
F_222 ( V_274 ) ;
}
