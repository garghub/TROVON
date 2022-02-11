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
else if ( F_14 ( F_15 ( V_16 ) ) ) {
struct V_13 * V_18 , * V_19 ;
F_16 (freq, t, &nfsi->commit_info.list, wb_list) {
if ( V_18 -> V_20 == V_16 ) {
V_17 = V_18 -> V_21 ;
break;
}
}
}
if ( V_17 ) {
F_17 ( V_17 -> V_21 != V_17 ) ;
F_18 ( & V_17 -> V_22 ) ;
}
return V_17 ;
}
static struct V_13 * F_19 ( struct V_16 * V_16 )
{
struct V_23 * V_23 = F_20 ( V_16 ) -> V_24 ;
struct V_13 * V_17 = NULL ;
F_21 ( & V_23 -> V_25 ) ;
V_17 = F_11 ( F_22 ( V_23 ) , V_16 ) ;
F_23 ( & V_23 -> V_25 ) ;
return V_17 ;
}
static void F_24 ( struct V_16 * V_16 , unsigned int V_26 , unsigned int V_27 )
{
struct V_23 * V_23 = F_20 ( V_16 ) -> V_24 ;
T_1 V_28 , V_29 ;
T_2 V_30 ;
F_21 ( & V_23 -> V_25 ) ;
V_29 = F_25 ( V_23 ) ;
V_30 = ( V_29 - 1 ) >> V_31 ;
if ( V_29 > 0 && F_26 ( V_16 ) < V_30 )
goto V_32;
V_28 = F_27 ( V_16 ) + ( ( T_1 ) V_26 + V_27 ) ;
if ( V_29 >= V_28 )
goto V_32;
F_28 ( V_23 , V_28 ) ;
F_29 ( V_23 , V_33 ) ;
V_32:
F_23 ( & V_23 -> V_25 ) ;
}
static void F_30 ( struct V_16 * V_16 )
{
F_31 ( F_20 ( V_16 ) -> V_24 , F_20 ( V_16 ) ) ;
}
static struct V_13 *
F_32 ( struct V_13 * V_34 , unsigned int V_35 )
{
struct V_13 * V_17 ;
F_17 ( V_34 != V_34 -> V_21 ) ;
F_17 ( ! F_33 ( V_36 , & V_34 -> V_21 -> V_37 ) ) ;
V_17 = V_34 ;
do {
if ( V_35 >= V_17 -> V_38 &&
V_35 < ( V_17 -> V_38 + V_17 -> V_39 ) )
return V_17 ;
V_17 = V_17 -> V_40 ;
} while ( V_17 != V_34 );
return NULL ;
}
static bool F_34 ( struct V_13 * V_17 )
{
struct V_13 * V_41 ;
unsigned int V_42 = 0 ;
unsigned int V_43 = F_35 ( V_17 -> V_20 ) ;
F_36 ( V_17 ) ;
do {
V_41 = F_32 ( V_17 -> V_21 , V_42 ) ;
if ( V_41 ) {
F_17 ( V_41 -> V_38 != V_42 ) ;
V_42 += V_41 -> V_39 - ( V_42 - V_41 -> V_38 ) ;
}
} while ( V_41 && V_42 < V_43 );
F_37 ( V_17 ) ;
F_17 ( V_42 > V_43 ) ;
return V_42 == V_43 ;
}
static void F_38 ( struct V_13 * V_17 )
{
if ( F_39 ( V_17 -> V_20 ) )
return;
if ( ! F_34 ( V_17 ) )
return;
F_40 ( V_17 -> V_20 ) ;
}
static int F_41 ( struct V_44 * V_45 )
{
if ( V_45 -> V_46 )
return V_47 | V_48 ;
if ( V_45 -> V_49 || V_45 -> V_50 )
return V_51 | V_52 ;
return V_52 ;
}
static void F_42 ( struct V_16 * V_16 )
{
struct V_53 * V_54 = F_43 ( F_20 ( V_16 ) -> V_24 ) ;
int V_55 = F_44 ( V_16 ) ;
F_17 ( V_55 != 0 ) ;
if ( F_45 ( & V_54 -> V_56 ) >
V_57 ) {
F_46 ( & V_54 -> V_58 ,
V_59 ) ;
}
}
static void F_47 ( struct V_13 * V_17 )
{
struct V_23 * V_23 = F_20 ( V_17 -> V_20 ) -> V_24 ;
struct V_53 * V_54 = F_43 ( V_23 ) ;
if ( ! F_48 ( V_17 , V_60 ) )
return;
F_49 ( V_17 -> V_20 ) ;
if ( F_50 ( & V_54 -> V_56 ) < V_61 )
F_51 ( & V_54 -> V_58 , V_59 ) ;
}
static void
F_52 ( struct V_13 * V_17 )
{
F_53 ( V_62 , & V_17 -> V_37 ) ;
F_53 ( V_63 , & V_17 -> V_37 ) ;
F_53 ( V_64 , & V_17 -> V_37 ) ;
F_53 ( V_60 , & V_17 -> V_37 ) ;
F_53 ( V_65 , & V_17 -> V_37 ) ;
}
static int
F_54 ( struct V_23 * V_23 , struct V_13 * V_34 ,
struct V_13 * V_17 , bool V_66 )
__releases( &inode->i_lock
static void
F_55 ( struct V_13 * V_67 ,
struct V_13 * V_68 )
{
while ( V_67 ) {
struct V_13 * V_69 = V_67 ;
V_67 = ( V_69 -> V_40 == V_68 ) ?
NULL : V_69 -> V_40 ;
F_17 ( V_68 != V_69 -> V_21 ) ;
V_69 -> V_21 = V_69 ;
V_69 -> V_40 = V_69 ;
F_56 ( V_69 ) ;
F_57 ( V_69 ) ;
if ( ! F_33 ( V_62 , & V_69 -> V_37 ) ) {
F_58 ( V_68 ) ;
F_52 ( V_69 ) ;
if ( F_59 ( V_70 , & V_69 -> V_37 ) )
F_58 ( V_69 ) ;
else
F_17 ( 1 ) ;
} else {
F_17 ( F_33 ( V_71 , & V_69 -> V_37 ) ) ;
F_52 ( V_69 ) ;
F_60 ( V_69 ) ;
}
}
}
static struct V_13 *
F_61 ( struct V_16 * V_16 , bool V_66 )
{
struct V_23 * V_23 = F_20 ( V_16 ) -> V_24 ;
struct V_13 * V_34 , * V_69 ;
struct V_13 * V_67 = NULL ;
unsigned int V_72 ;
int V_55 ;
V_73:
V_72 = 0 ;
F_17 ( V_67 ) ;
F_21 ( & V_23 -> V_25 ) ;
V_34 = F_11 ( F_22 ( V_23 ) , V_16 ) ;
if ( ! V_34 ) {
F_23 ( & V_23 -> V_25 ) ;
return NULL ;
}
F_36 ( V_34 ) ;
V_69 = V_34 ;
do {
F_17 ( V_69 -> V_74 !=
( V_34 -> V_74 + V_72 ) ) ;
V_72 += V_69 -> V_39 ;
if ( ! F_62 ( V_69 ) ) {
V_55 = F_54 ( V_23 , V_34 ,
V_69 , V_66 ) ;
if ( V_55 == 0 )
goto V_73;
return F_63 ( V_55 ) ;
}
V_69 = V_69 -> V_40 ;
} while ( V_69 != V_34 );
V_69 = V_34 ;
do {
F_64 ( V_69 ) ;
V_69 = V_69 -> V_40 ;
} while ( V_69 != V_34 );
if ( V_34 -> V_40 != V_34 ) {
V_67 = V_34 -> V_40 ;
V_34 -> V_40 = V_34 ;
V_34 -> V_39 = V_72 ;
}
F_52 ( V_34 ) ;
if ( ! F_65 ( V_70 , & V_34 -> V_37 ) )
F_18 ( & V_34 -> V_22 ) ;
F_37 ( V_34 ) ;
F_23 ( & V_23 -> V_25 ) ;
F_55 ( V_67 , V_34 ) ;
F_56 ( V_34 ) ;
return V_34 ;
}
static int F_66 ( struct V_75 * V_76 ,
struct V_16 * V_16 , bool V_66 )
{
struct V_13 * V_17 ;
int V_55 = 0 ;
V_17 = F_61 ( V_16 , V_66 ) ;
if ( ! V_17 )
goto V_32;
V_55 = F_67 ( V_17 ) ;
if ( F_68 ( V_17 ) )
goto V_32;
F_42 ( V_16 ) ;
F_17 ( F_33 ( V_71 , & V_17 -> V_37 ) ) ;
V_55 = 0 ;
if ( ! F_69 ( V_76 , V_17 ) ) {
F_70 ( V_17 ) ;
V_55 = V_76 -> V_77 ;
}
V_32:
return V_55 ;
}
static int F_71 ( struct V_16 * V_16 , struct V_44 * V_45 , struct V_75 * V_76 )
{
struct V_23 * V_23 = F_20 ( V_16 ) -> V_24 ;
int V_55 ;
F_29 ( V_23 , V_78 ) ;
F_72 ( V_23 , V_79 , 1 ) ;
F_73 ( V_76 , F_26 ( V_16 ) ) ;
V_55 = F_66 ( V_76 , V_16 , V_45 -> V_80 == V_81 ) ;
if ( V_55 == - V_82 ) {
F_74 ( V_45 , V_16 ) ;
V_55 = 0 ;
}
return V_55 ;
}
static int F_75 ( struct V_16 * V_16 , struct V_44 * V_45 )
{
struct V_75 V_76 ;
int V_83 ;
F_76 ( & V_76 , V_16 -> V_84 -> V_24 , F_41 ( V_45 ) ,
false , & V_85 ) ;
V_83 = F_71 ( V_16 , V_45 , & V_76 ) ;
F_77 ( & V_76 ) ;
if ( V_83 < 0 )
return V_83 ;
if ( V_76 . V_77 < 0 )
return V_76 . V_77 ;
return 0 ;
}
int F_78 ( struct V_16 * V_16 , struct V_44 * V_45 )
{
int V_55 ;
V_55 = F_75 ( V_16 , V_45 ) ;
F_79 ( V_16 ) ;
return V_55 ;
}
static int F_80 ( struct V_16 * V_16 , struct V_44 * V_45 , void * V_86 )
{
int V_55 ;
V_55 = F_71 ( V_16 , V_45 , V_86 ) ;
F_79 ( V_16 ) ;
return V_55 ;
}
int F_81 ( struct V_87 * V_84 , struct V_44 * V_45 )
{
struct V_23 * V_23 = V_84 -> V_24 ;
unsigned long * V_88 = & F_22 ( V_23 ) -> V_12 ;
struct V_75 V_76 ;
int V_83 ;
V_83 = F_82 ( V_88 , V_89 ,
V_90 , V_91 ) ;
if ( V_83 )
goto V_92;
F_29 ( V_23 , V_93 ) ;
F_76 ( & V_76 , V_23 , F_41 ( V_45 ) , false ,
& V_85 ) ;
V_83 = F_83 ( V_84 , V_45 , F_80 , & V_76 ) ;
F_77 ( & V_76 ) ;
F_84 ( V_89 , V_88 ) ;
F_85 () ;
F_86 ( V_88 , V_89 ) ;
if ( V_83 < 0 )
goto V_92;
V_83 = V_76 . V_77 ;
if ( V_83 < 0 )
goto V_92;
return 0 ;
V_92:
return V_83 ;
}
static void F_87 ( struct V_23 * V_23 , struct V_13 * V_17 )
{
struct V_14 * V_15 = F_22 ( V_23 ) ;
F_17 ( V_17 -> V_40 != V_17 ) ;
F_62 ( V_17 ) ;
F_21 ( & V_23 -> V_25 ) ;
if ( ! V_15 -> V_94 && F_88 ( V_23 ) -> F_89 ( V_23 , V_95 ) )
V_23 -> V_96 ++ ;
if ( F_90 ( ! F_15 ( V_17 -> V_20 ) ) ) {
F_10 ( V_97 , & V_17 -> V_37 ) ;
F_91 ( V_17 -> V_20 ) ;
F_92 ( V_17 -> V_20 , ( unsigned long ) V_17 ) ;
}
V_15 -> V_94 ++ ;
F_93 ( F_65 ( V_70 , & V_17 -> V_37 ) ) ;
F_18 ( & V_17 -> V_22 ) ;
F_23 ( & V_23 -> V_25 ) ;
}
static void F_94 ( struct V_13 * V_17 )
{
struct V_23 * V_23 = V_17 -> V_98 -> V_99 -> V_100 ;
struct V_14 * V_15 = F_22 ( V_23 ) ;
struct V_13 * V_34 ;
if ( F_48 ( V_17 , V_65 ) ) {
V_34 = V_17 -> V_21 ;
F_21 ( & V_23 -> V_25 ) ;
if ( F_90 ( ! F_15 ( V_34 -> V_20 ) ) ) {
F_92 ( V_34 -> V_20 , 0 ) ;
F_95 ( V_34 -> V_20 ) ;
F_53 ( V_97 , & V_34 -> V_37 ) ;
}
V_15 -> V_94 -- ;
F_23 ( & V_23 -> V_25 ) ;
}
if ( F_59 ( V_70 , & V_17 -> V_37 ) )
F_58 ( V_17 ) ;
}
static void
F_96 ( struct V_13 * V_17 )
{
F_97 ( V_17 -> V_20 ) ;
}
void
F_98 ( struct V_13 * V_17 , struct V_101 * V_102 ,
struct V_103 * V_104 )
{
F_10 ( V_71 , & ( V_17 ) -> V_37 ) ;
F_21 ( V_104 -> V_105 ) ;
F_99 ( V_17 , V_102 ) ;
V_104 -> V_106 -> V_107 ++ ;
F_23 ( V_104 -> V_105 ) ;
if ( ! V_104 -> V_108 ) {
F_100 ( V_17 -> V_20 , V_109 ) ;
F_101 ( F_20 ( V_17 -> V_20 ) -> V_58 ,
V_110 ) ;
F_102 ( V_17 -> V_98 -> V_99 -> V_100 ,
V_111 ) ;
}
}
void
F_103 ( struct V_13 * V_17 ,
struct V_103 * V_104 )
{
if ( ! F_59 ( V_71 , & ( V_17 ) -> V_37 ) )
return;
F_64 ( V_17 ) ;
V_104 -> V_106 -> V_107 -- ;
}
static void F_104 ( struct V_103 * V_104 ,
struct V_23 * V_23 )
{
V_104 -> V_105 = & V_23 -> V_25 ;
V_104 -> V_106 = & F_22 ( V_23 ) -> V_112 ;
V_104 -> V_113 = F_105 ( V_23 ) ;
V_104 -> V_108 = NULL ;
V_104 -> V_114 = & V_115 ;
}
void F_106 ( struct V_103 * V_104 ,
struct V_23 * V_23 ,
struct V_116 * V_108 )
{
if ( V_108 )
F_107 ( V_104 , V_108 ) ;
else
F_104 ( V_104 , V_23 ) ;
}
void
F_108 ( struct V_13 * V_17 , struct V_117 * V_118 ,
struct V_103 * V_104 )
{
if ( F_109 ( V_17 , V_118 , V_104 ) )
return;
F_98 ( V_17 , & V_104 -> V_106 -> V_119 , V_104 ) ;
}
static void
F_110 ( struct V_16 * V_16 )
{
F_111 ( V_16 , V_109 ) ;
F_112 ( F_20 ( V_16 ) -> V_58 , V_110 ) ;
}
static void
F_56 ( struct V_13 * V_17 )
{
if ( F_33 ( V_71 , & V_17 -> V_37 ) ) {
struct V_23 * V_23 = V_17 -> V_98 -> V_99 -> V_100 ;
struct V_103 V_104 ;
F_104 ( & V_104 , V_23 ) ;
if ( ! F_113 ( V_17 , & V_104 ) ) {
F_21 ( V_104 . V_105 ) ;
F_103 ( V_17 , & V_104 ) ;
F_23 ( V_104 . V_105 ) ;
}
F_110 ( V_17 -> V_20 ) ;
}
}
static inline
int F_114 ( struct V_120 * V_86 )
{
if ( V_86 -> V_121 . V_122 == V_123 )
return V_86 -> V_124 -> V_118 == NULL ;
return V_86 -> V_121 . V_122 != V_125 ;
}
static void F_104 ( struct V_103 * V_104 ,
struct V_23 * V_23 )
{
}
void F_106 ( struct V_103 * V_104 ,
struct V_23 * V_23 ,
struct V_116 * V_108 )
{
}
void
F_108 ( struct V_13 * V_17 , struct V_117 * V_118 ,
struct V_103 * V_104 )
{
}
static void
F_56 ( struct V_13 * V_17 )
{
}
static inline
int F_114 ( struct V_120 * V_86 )
{
return 0 ;
}
static void F_115 ( struct V_126 * V_127 )
{
struct V_103 V_104 ;
unsigned long V_128 = 0 ;
if ( F_33 ( V_129 , & V_127 -> V_12 ) )
goto V_32;
F_104 ( & V_104 , V_127 -> V_23 ) ;
while ( ! F_116 ( & V_127 -> V_5 ) ) {
struct V_13 * V_17 = F_117 ( V_127 -> V_5 . V_130 ) ;
V_128 += V_17 -> V_39 ;
F_64 ( V_17 ) ;
if ( F_33 ( V_131 , & V_127 -> V_12 ) &&
( V_127 -> V_132 < V_128 ) ) {
F_30 ( V_17 -> V_20 ) ;
F_8 ( V_17 -> V_98 , V_127 -> error ) ;
goto V_133;
}
if ( F_33 ( V_134 , & V_127 -> V_12 ) ) {
F_96 ( V_17 ) ;
goto V_130;
}
if ( F_33 ( V_135 , & V_127 -> V_12 ) ) {
memcpy ( & V_17 -> V_136 , & V_127 -> V_121 . V_137 , sizeof( V_17 -> V_136 ) ) ;
F_108 ( V_17 , V_127 -> V_118 , & V_104 ) ;
goto V_130;
}
V_133:
F_94 ( V_17 ) ;
V_130:
F_57 ( V_17 ) ;
F_47 ( V_17 ) ;
F_58 ( V_17 ) ;
}
V_32:
V_127 -> V_138 ( V_127 ) ;
}
unsigned long
F_118 ( struct V_103 * V_104 )
{
return V_104 -> V_106 -> V_107 ;
}
int
F_119 ( struct V_101 * V_139 , struct V_101 * V_102 ,
struct V_103 * V_104 , int V_140 )
{
struct V_13 * V_17 , * V_41 ;
int V_55 = 0 ;
F_16 (req, tmp, src, wb_list) {
if ( ! F_62 ( V_17 ) )
continue;
F_18 ( & V_17 -> V_22 ) ;
if ( F_120 ( V_104 -> V_105 ) )
F_121 ( V_17 , V_41 , V_141 ) ;
F_103 ( V_17 , V_104 ) ;
F_99 ( V_17 , V_102 ) ;
V_55 ++ ;
if ( ( V_55 == V_140 ) && ! V_104 -> V_108 )
break;
}
return V_55 ;
}
int
F_122 ( struct V_23 * V_23 , struct V_101 * V_102 ,
struct V_103 * V_104 )
{
int V_55 = 0 ;
F_21 ( V_104 -> V_105 ) ;
if ( V_104 -> V_106 -> V_107 > 0 ) {
const int V_140 = V_142 ;
V_55 = F_119 ( & V_104 -> V_106 -> V_119 , V_102 ,
V_104 , V_140 ) ;
V_55 += F_123 ( V_23 , V_104 , V_140 - V_55 ) ;
}
F_23 ( V_104 -> V_105 ) ;
return V_55 ;
}
unsigned long F_118 ( struct V_103 * V_104 )
{
return 0 ;
}
int F_122 ( struct V_23 * V_23 , struct V_101 * V_102 ,
struct V_103 * V_104 )
{
return 0 ;
}
static struct V_13 * F_124 ( struct V_23 * V_23 ,
struct V_16 * V_16 ,
unsigned int V_26 ,
unsigned int V_128 )
{
struct V_13 * V_17 ;
unsigned int V_143 ;
unsigned int V_28 ;
int error ;
if ( ! F_12 ( V_16 ) )
return NULL ;
V_28 = V_26 + V_128 ;
F_21 ( & V_23 -> V_25 ) ;
for (; ; ) {
V_17 = F_11 ( F_22 ( V_23 ) , V_16 ) ;
if ( V_17 == NULL )
goto V_144;
F_17 ( V_17 -> V_21 != V_17 ) ;
F_17 ( V_17 -> V_40 != V_17 ) ;
V_143 = V_17 -> V_74 + V_17 -> V_39 ;
if ( V_26 > V_143
|| V_28 < V_17 -> V_74 )
goto V_145;
if ( F_62 ( V_17 ) )
break;
F_23 ( & V_23 -> V_25 ) ;
error = F_125 ( V_17 ) ;
F_58 ( V_17 ) ;
if ( error != 0 )
goto V_92;
F_21 ( & V_23 -> V_25 ) ;
}
if ( V_26 < V_17 -> V_74 ) {
V_17 -> V_74 = V_26 ;
V_17 -> V_38 = V_26 ;
}
if ( V_28 > V_143 )
V_17 -> V_39 = V_28 - V_17 -> V_74 ;
else
V_17 -> V_39 = V_143 - V_17 -> V_74 ;
V_144:
F_23 ( & V_23 -> V_25 ) ;
if ( V_17 )
F_56 ( V_17 ) ;
return V_17 ;
V_145:
F_23 ( & V_23 -> V_25 ) ;
F_58 ( V_17 ) ;
error = F_126 ( V_23 , V_16 ) ;
V_92:
return F_63 ( error ) ;
}
static struct V_13 * F_127 ( struct V_9 * V_10 ,
struct V_16 * V_16 , unsigned int V_26 , unsigned int V_128 )
{
struct V_23 * V_23 = F_20 ( V_16 ) -> V_24 ;
struct V_13 * V_17 ;
V_17 = F_124 ( V_23 , V_16 , V_26 , V_128 ) ;
if ( V_17 != NULL )
goto V_32;
V_17 = F_128 ( V_10 , V_16 , NULL , V_26 , V_128 ) ;
if ( F_68 ( V_17 ) )
goto V_32;
F_87 ( V_23 , V_17 ) ;
V_32:
return V_17 ;
}
static int F_129 ( struct V_9 * V_10 , struct V_16 * V_16 ,
unsigned int V_26 , unsigned int V_27 )
{
struct V_13 * V_17 ;
V_17 = F_127 ( V_10 , V_16 , V_26 , V_27 ) ;
if ( F_68 ( V_17 ) )
return F_67 ( V_17 ) ;
F_24 ( V_16 , V_26 , V_27 ) ;
F_38 ( V_17 ) ;
F_96 ( V_17 ) ;
F_130 ( V_17 ) ;
return 0 ;
}
int F_131 ( struct V_146 * V_146 , struct V_16 * V_16 )
{
struct V_9 * V_10 = F_132 ( V_146 ) ;
struct V_147 * V_148 ;
struct V_13 * V_17 ;
int V_149 , V_150 ;
do {
V_17 = F_19 ( V_16 ) ;
if ( V_17 == NULL )
return 0 ;
V_148 = V_17 -> V_151 ;
V_149 = V_17 -> V_20 != V_16 || V_17 -> V_98 != V_10 ;
V_149 |= V_17 -> V_40 != V_17 ;
if ( V_148 && V_10 -> V_99 -> V_100 -> V_152 != NULL ) {
V_149 |= V_148 -> V_153 . V_154 != V_155 -> V_156
|| V_148 -> V_153 . V_157 != V_155 -> V_158 ;
}
F_58 ( V_17 ) ;
if ( ! V_149 )
return 0 ;
V_150 = F_126 ( F_20 ( V_16 ) -> V_24 , V_16 ) ;
} while ( V_150 == 0 );
return V_150 ;
}
int
F_133 ( struct V_146 * V_159 , struct V_23 * V_23 )
{
struct V_9 * V_10 = F_132 ( V_159 ) ;
struct V_160 * V_161 = F_43 ( V_23 ) -> V_162 -> V_163 ;
return F_134 ( V_161 , V_10 -> V_164 ) ;
}
bool F_135 ( struct V_9 * V_10 )
{
return F_136 ( V_10 -> V_164 ) ;
}
static bool F_137 ( struct V_16 * V_16 , struct V_23 * V_23 )
{
struct V_14 * V_15 = F_22 ( V_23 ) ;
if ( F_138 ( V_23 ) )
goto V_32;
if ( V_15 -> V_165 & V_166 )
return false ;
F_139 () ;
if ( F_33 ( V_167 , & V_15 -> V_12 ) )
return false ;
V_32:
if ( V_15 -> V_165 & V_168 )
return false ;
return F_39 ( V_16 ) != 0 ;
}
static int F_140 ( struct V_146 * V_146 , struct V_16 * V_16 , struct V_23 * V_23 )
{
if ( V_146 -> V_169 & V_170 )
return 0 ;
if ( ! F_137 ( V_16 , V_23 ) )
return 0 ;
if ( F_88 ( V_23 ) -> F_89 ( V_23 , V_95 ) )
return 1 ;
if ( V_23 -> V_152 == NULL || ( V_23 -> V_152 -> V_171 == 0 &&
V_23 -> V_152 -> V_172 == V_173 &&
V_23 -> V_152 -> V_174 != V_175 ) )
return 1 ;
return 0 ;
}
int F_141 ( struct V_146 * V_146 , struct V_16 * V_16 ,
unsigned int V_26 , unsigned int V_27 )
{
struct V_9 * V_10 = F_132 ( V_146 ) ;
struct V_23 * V_23 = F_20 ( V_16 ) -> V_24 ;
int V_150 = 0 ;
F_29 ( V_23 , V_176 ) ;
F_142 ( L_1 ,
V_146 , V_27 , ( long long ) ( F_27 ( V_16 ) + V_26 ) ) ;
if ( F_140 ( V_146 , V_16 , V_23 ) ) {
V_27 = V_140 ( V_27 + V_26 , F_35 ( V_16 ) ) ;
V_26 = 0 ;
}
V_150 = F_129 ( V_10 , V_16 , V_26 , V_27 ) ;
if ( V_150 < 0 )
F_30 ( V_16 ) ;
else
F_97 ( V_16 ) ;
F_142 ( L_2 ,
V_150 , ( long long ) F_25 ( V_23 ) ) ;
return V_150 ;
}
static int F_143 ( int V_177 )
{
switch ( V_177 & ( V_47 | V_51 ) ) {
case V_47 :
return V_178 ;
case V_51 :
return V_179 ;
}
return V_180 ;
}
static void F_144 ( struct V_120 * V_86 , struct V_181 * V_182 ,
struct V_183 * V_184 , int V_177 )
{
struct V_23 * V_23 = V_86 -> V_124 -> V_23 ;
int V_185 = F_143 ( V_177 ) ;
V_184 -> V_185 = V_185 ;
F_88 ( V_23 ) -> F_145 ( V_86 , V_182 ) ;
F_146 ( F_43 ( V_23 ) -> V_186 ,
& V_184 -> V_187 , V_182 , V_86 ) ;
}
static void F_70 ( struct V_13 * V_17 )
{
F_96 ( V_17 ) ;
F_57 ( V_17 ) ;
F_47 ( V_17 ) ;
F_58 ( V_17 ) ;
}
static void F_147 ( struct V_101 * V_34 )
{
struct V_13 * V_17 ;
while ( ! F_116 ( V_34 ) ) {
V_17 = F_117 ( V_34 -> V_130 ) ;
F_64 ( V_17 ) ;
F_70 ( V_17 ) ;
}
}
void F_76 ( struct V_75 * V_76 ,
struct V_23 * V_23 , int V_188 , bool V_189 ,
const struct V_190 * V_191 )
{
struct V_53 * V_192 = F_43 ( V_23 ) ;
const struct V_193 * V_194 = & V_195 ;
#ifdef F_148
if ( V_192 -> V_196 && ! V_189 )
V_194 = V_192 -> V_196 -> V_197 ;
#endif
F_149 ( V_76 , V_23 , V_194 , V_191 , & V_198 ,
V_192 -> V_199 , V_188 ) ;
}
void F_150 ( struct V_75 * V_76 )
{
V_76 -> V_194 = & V_195 ;
V_76 -> V_200 = F_43 ( V_76 -> V_201 ) -> V_199 ;
}
void F_151 ( struct V_202 * V_203 , void * V_204 )
{
struct V_1 * V_86 = V_204 ;
F_88 ( V_86 -> V_23 ) -> F_152 ( V_203 , V_86 ) ;
}
static void F_153 ( struct V_120 * V_86 )
{
struct V_126 * V_127 = V_86 -> V_124 ;
int V_150 = V_86 -> V_203 . V_205 ;
if ( ( V_150 >= 0 ) && F_114 ( V_86 ) ) {
F_21 ( & V_127 -> V_105 ) ;
if ( F_33 ( V_134 , & V_127 -> V_12 ) )
;
else if ( ! F_65 ( V_135 , & V_127 -> V_12 ) )
memcpy ( & V_127 -> V_121 , & V_86 -> V_121 , sizeof( V_127 -> V_121 ) ) ;
else if ( memcmp ( & V_127 -> V_121 , & V_86 -> V_121 , sizeof( V_127 -> V_121 ) ) )
F_10 ( V_134 , & V_127 -> V_12 ) ;
F_23 ( & V_127 -> V_105 ) ;
}
}
static int F_154 ( const struct V_23 * V_23 )
{
T_3 V_206 = V_23 -> V_207 ;
int V_208 = 0 ;
if ( F_14 ( V_206 & V_209 ) )
V_208 = V_210 ;
if ( F_14 ( ( V_206 & V_211 ) && ( V_206 & V_212 ) ) )
V_208 |= V_213 ;
if ( F_14 ( V_208 && F_155 ( V_206 ) ) )
return V_208 ;
return 0 ;
}
static int F_156 ( struct V_202 * V_203 , struct V_120 * V_86 ,
struct V_23 * V_23 )
{
int V_150 ;
V_150 = F_88 ( V_23 ) -> F_157 ( V_203 , V_86 ) ;
if ( V_150 != 0 )
return V_150 ;
F_72 ( V_23 , V_214 , V_86 -> V_215 . V_27 ) ;
#if F_158 ( V_216 ) || F_158 ( V_217 )
if ( V_86 -> V_215 . V_121 -> V_122 < V_86 -> args . V_218 && V_203 -> V_205 >= 0 ) {
static unsigned long V_219 ;
if ( F_159 ( V_219 , V_220 ) ) {
F_142 ( L_3
L_4 ,
F_43 ( V_23 ) -> V_186 -> V_221 ,
V_86 -> V_215 . V_121 -> V_122 , V_86 -> args . V_218 ) ;
V_219 = V_220 + 300 * V_222 ;
}
}
#endif
if ( F_154 ( V_23 ) )
F_160 ( V_23 ) ;
return 0 ;
}
static void F_161 ( struct V_202 * V_203 , struct V_120 * V_86 )
{
struct V_223 * V_224 = & V_86 -> args ;
struct V_225 * V_226 = & V_86 -> V_215 ;
if ( V_226 -> V_27 < V_224 -> V_27 ) {
static unsigned long V_219 ;
F_29 ( V_86 -> V_124 -> V_23 , V_227 ) ;
if ( V_226 -> V_27 == 0 ) {
if ( F_159 ( V_219 , V_220 ) ) {
F_162 ( V_228
L_5 ,
V_224 -> V_27 ) ;
V_219 = V_220 + 300 * V_222 ;
}
F_163 ( V_86 -> V_124 , - V_229 , V_224 -> V_26 ) ;
V_203 -> V_205 = - V_229 ;
return;
}
if ( V_226 -> V_121 -> V_122 != V_230 ) {
V_86 -> V_231 += V_226 -> V_27 ;
V_224 -> V_26 += V_226 -> V_27 ;
V_224 -> V_232 += V_226 -> V_27 ;
V_224 -> V_27 -= V_226 -> V_27 ;
} else {
V_224 -> V_218 = V_125 ;
}
F_164 ( V_203 ) ;
}
}
static int F_165 ( struct V_14 * V_15 , int V_233 )
{
int V_55 ;
if ( ! F_65 ( V_234 , & V_15 -> V_12 ) )
return 1 ;
if ( ! V_233 )
return 0 ;
V_55 = F_166 ( & V_15 -> V_12 ,
V_234 ,
V_90 ,
V_91 ) ;
return ( V_55 < 0 ) ? V_55 : 1 ;
}
static void F_167 ( struct V_14 * V_15 )
{
F_53 ( V_234 , & V_15 -> V_12 ) ;
F_85 () ;
F_86 ( & V_15 -> V_12 , V_234 ) ;
}
void F_168 ( struct V_1 * V_86 )
{
F_169 ( V_86 -> V_235 ) ;
F_4 ( V_86 ) ;
}
int F_170 ( struct V_236 * V_237 , struct V_1 * V_86 ,
const struct V_238 * V_239 ,
int V_177 , int V_12 )
{
struct V_202 * V_203 ;
int V_185 = F_143 ( V_177 ) ;
struct V_181 V_182 = {
. V_240 = & V_86 -> args ,
. V_241 = & V_86 -> V_215 ,
. V_242 = V_86 -> V_164 ,
} ;
struct V_183 V_184 = {
. V_203 = & V_86 -> V_203 ,
. V_187 = V_237 ,
. V_181 = & V_182 ,
. V_243 = V_239 ,
. V_244 = V_86 ,
. V_245 = V_246 ,
. V_12 = V_247 | V_12 ,
. V_185 = V_185 ,
} ;
F_88 ( V_86 -> V_23 ) -> F_171 ( V_86 , & V_182 ) ;
F_142 ( L_6 , V_86 -> V_203 . V_248 ) ;
F_172 ( F_43 ( V_86 -> V_23 ) -> V_186 ,
V_249 , & V_184 . V_187 , & V_182 ) ;
V_203 = F_173 ( & V_184 ) ;
if ( F_68 ( V_203 ) )
return F_67 ( V_203 ) ;
if ( V_177 & V_250 )
F_174 ( V_203 ) ;
F_175 ( V_203 ) ;
return 0 ;
}
void F_176 ( struct V_1 * V_86 ,
struct V_101 * V_34 ,
struct V_117 * V_118 ,
struct V_103 * V_104 )
{
struct V_13 * V_251 = F_117 ( V_34 -> V_130 ) ;
struct V_23 * V_23 = V_251 -> V_98 -> V_99 -> V_100 ;
F_177 ( V_34 , & V_86 -> V_5 ) ;
V_86 -> V_23 = V_23 ;
V_86 -> V_164 = V_251 -> V_98 -> V_164 ;
V_86 -> V_118 = V_118 ;
V_86 -> V_252 = & V_253 ;
V_86 -> V_114 = V_104 -> V_114 ;
V_86 -> V_108 = V_104 -> V_108 ;
V_86 -> args . V_254 = F_178 ( V_86 -> V_23 ) ;
V_86 -> args . V_26 = 0 ;
V_86 -> args . V_27 = 0 ;
V_86 -> V_235 = F_179 ( V_251 -> V_98 ) ;
V_86 -> V_215 . V_255 = & V_86 -> V_255 ;
V_86 -> V_215 . V_121 = & V_86 -> V_121 ;
F_180 ( & V_86 -> V_255 ) ;
}
void F_181 ( struct V_101 * V_256 ,
struct V_117 * V_118 ,
struct V_103 * V_104 )
{
struct V_13 * V_17 ;
while ( ! F_116 ( V_256 ) ) {
V_17 = F_117 ( V_256 -> V_130 ) ;
F_64 ( V_17 ) ;
F_108 ( V_17 , V_118 , V_104 ) ;
if ( ! V_104 -> V_108 ) {
F_111 ( V_17 -> V_20 , V_109 ) ;
F_112 ( F_20 ( V_17 -> V_20 ) -> V_58 ,
V_110 ) ;
}
F_130 ( V_17 ) ;
}
}
static int
F_182 ( struct V_23 * V_23 , struct V_101 * V_34 , int V_177 ,
struct V_103 * V_104 )
{
struct V_1 * V_86 ;
V_86 = F_1 () ;
if ( ! V_86 )
goto V_257;
F_176 ( V_86 , V_34 , NULL , V_104 ) ;
F_183 ( & V_104 -> V_106 -> V_258 ) ;
return F_170 ( F_184 ( V_23 ) , V_86 , V_86 -> V_252 ,
V_177 , 0 ) ;
V_257:
F_181 ( V_34 , NULL , V_104 ) ;
V_104 -> V_114 -> V_259 ( F_22 ( V_23 ) ) ;
return - V_260 ;
}
static void F_185 ( struct V_202 * V_203 , void * V_204 )
{
struct V_1 * V_86 = V_204 ;
F_142 ( L_7 ,
V_203 -> V_248 , V_203 -> V_205 ) ;
F_88 ( V_86 -> V_23 ) -> F_186 ( V_203 , V_86 ) ;
}
static void F_187 ( struct V_1 * V_86 )
{
struct V_13 * V_17 ;
int V_150 = V_86 -> V_203 . V_205 ;
struct V_103 V_104 ;
while ( ! F_116 ( & V_86 -> V_5 ) ) {
V_17 = F_117 ( V_86 -> V_5 . V_130 ) ;
F_64 ( V_17 ) ;
F_110 ( V_17 -> V_20 ) ;
F_142 ( L_8 ,
V_17 -> V_98 -> V_99 -> V_261 -> V_262 ,
( unsigned long long ) F_188 ( V_17 -> V_98 -> V_99 -> V_100 ) ,
V_17 -> V_39 ,
( long long ) F_189 ( V_17 ) ) ;
if ( V_150 < 0 ) {
F_8 ( V_17 -> V_98 , V_150 ) ;
F_94 ( V_17 ) ;
F_142 ( L_9 , V_150 ) ;
goto V_130;
}
if ( ! memcmp ( & V_17 -> V_136 , & V_86 -> V_121 . V_137 , sizeof( V_17 -> V_136 ) ) ) {
F_94 ( V_17 ) ;
F_142 ( L_10 ) ;
goto V_130;
}
F_142 ( L_11 ) ;
F_96 ( V_17 ) ;
F_10 ( V_263 , & V_17 -> V_98 -> V_12 ) ;
V_130:
F_130 ( V_17 ) ;
}
F_106 ( & V_104 , V_86 -> V_23 , V_86 -> V_108 ) ;
if ( F_190 ( & V_104 . V_106 -> V_258 ) )
F_167 ( F_22 ( V_86 -> V_23 ) ) ;
}
static void F_191 ( void * V_204 )
{
struct V_1 * V_86 = V_204 ;
V_86 -> V_114 -> V_264 ( V_86 ) ;
F_168 ( V_204 ) ;
}
int F_192 ( struct V_23 * V_23 , struct V_101 * V_34 ,
int V_177 , struct V_103 * V_104 )
{
int V_150 ;
V_150 = F_193 ( V_23 , V_34 , V_177 , V_104 ) ;
if ( V_150 == V_265 )
V_150 = F_182 ( V_23 , V_34 , V_177 , V_104 ) ;
return V_150 ;
}
int F_194 ( struct V_23 * V_23 , int V_177 )
{
F_195 ( V_34 ) ;
struct V_103 V_104 ;
int V_233 = V_177 & V_250 ;
int V_215 ;
V_215 = F_165 ( F_22 ( V_23 ) , V_233 ) ;
if ( V_215 <= 0 )
goto V_266;
F_104 ( & V_104 , V_23 ) ;
V_215 = F_122 ( V_23 , & V_34 , & V_104 ) ;
if ( V_215 ) {
int error ;
error = F_192 ( V_23 , & V_34 , V_177 , & V_104 ) ;
if ( error < 0 )
return error ;
if ( ! V_233 )
goto V_266;
error = F_196 ( & F_22 ( V_23 ) -> V_12 ,
V_234 ,
V_90 ,
V_91 ) ;
if ( error < 0 )
return error ;
} else
F_167 ( F_22 ( V_23 ) ) ;
return V_215 ;
V_266:
F_102 ( V_23 , V_111 ) ;
return V_215 ;
}
static int F_197 ( struct V_23 * V_23 , struct V_44 * V_45 )
{
struct V_14 * V_15 = F_22 ( V_23 ) ;
int V_12 = V_250 ;
int V_55 = 0 ;
if ( ! V_15 -> V_112 . V_107 )
return V_55 ;
if ( V_45 -> V_80 == V_81 ) {
if ( V_15 -> V_112 . V_107 <= ( V_15 -> V_94 >> 1 ) )
goto V_266;
V_12 = 0 ;
}
V_55 = F_194 ( V_23 , V_12 ) ;
if ( V_55 >= 0 ) {
if ( V_45 -> V_80 == V_81 ) {
if ( V_55 < V_45 -> V_267 )
V_45 -> V_267 -= V_55 ;
else
V_45 -> V_267 = 0 ;
}
return 0 ;
}
V_266:
F_102 ( V_23 , V_111 ) ;
return V_55 ;
}
static int F_197 ( struct V_23 * V_23 , struct V_44 * V_45 )
{
return 0 ;
}
int F_198 ( struct V_23 * V_23 , struct V_44 * V_45 )
{
return F_197 ( V_23 , V_45 ) ;
}
int F_199 ( struct V_23 * V_23 )
{
struct V_44 V_45 = {
. V_80 = V_268 ,
. V_267 = V_269 ,
. V_270 = 0 ,
. V_271 = V_272 ,
} ;
int V_55 ;
F_200 ( V_23 ) ;
V_55 = F_201 ( V_23 , & V_45 ) ;
F_202 ( V_23 , V_55 ) ;
return V_55 ;
}
int F_203 ( struct V_23 * V_23 , struct V_16 * V_16 )
{
struct V_13 * V_17 ;
int V_55 = 0 ;
F_204 ( V_16 ) ;
V_17 = F_61 ( V_16 , false ) ;
if ( F_68 ( V_17 ) ) {
V_55 = F_67 ( V_17 ) ;
} else if ( V_17 ) {
F_94 ( V_17 ) ;
F_205 ( V_16 , V_273 ) ;
F_130 ( V_17 ) ;
}
return V_55 ;
}
int F_126 ( struct V_23 * V_23 , struct V_16 * V_16 )
{
T_1 V_270 = F_27 ( V_16 ) ;
T_1 V_271 = V_270 + ( T_1 ) ( V_273 - 1 ) ;
struct V_44 V_45 = {
. V_80 = V_268 ,
. V_267 = 0 ,
. V_270 = V_270 ,
. V_271 = V_271 ,
} ;
int V_55 ;
F_206 ( V_23 ) ;
for (; ; ) {
F_204 ( V_16 ) ;
if ( F_207 ( V_16 ) ) {
V_55 = F_75 ( V_16 , & V_45 ) ;
if ( V_55 < 0 )
goto V_274;
continue;
}
V_55 = 0 ;
if ( ! F_12 ( V_16 ) )
break;
V_55 = F_194 ( V_23 , V_250 ) ;
if ( V_55 < 0 )
goto V_274;
}
V_274:
F_208 ( V_23 , V_55 ) ;
return V_55 ;
}
int F_209 ( struct V_87 * V_84 , struct V_16 * V_275 ,
struct V_16 * V_16 , enum V_276 V_206 )
{
if ( F_12 ( V_16 ) )
return - V_277 ;
if ( ! F_210 ( V_16 , V_278 ) )
return - V_277 ;
return F_211 ( V_84 , V_275 , V_16 , V_206 ) ;
}
int T_4 F_212 ( void )
{
V_279 = F_213 ( L_12 ,
sizeof( struct V_6 ) ,
0 , V_280 ,
NULL ) ;
if ( V_279 == NULL )
return - V_260 ;
V_7 = F_214 ( V_281 ,
V_279 ) ;
if ( V_7 == NULL )
goto V_282;
V_283 = F_213 ( L_13 ,
sizeof( struct V_1 ) ,
0 , V_280 ,
NULL ) ;
if ( V_283 == NULL )
goto V_284;
V_3 = F_214 ( V_285 ,
V_283 ) ;
if ( V_3 == NULL )
goto V_286;
V_287 = ( 16 * F_215 ( V_288 ) ) << ( V_289 - 10 ) ;
if ( V_287 > 256 * 1024 )
V_287 = 256 * 1024 ;
return 0 ;
V_286:
F_216 ( V_283 ) ;
V_284:
F_217 ( V_7 ) ;
V_282:
F_216 ( V_279 ) ;
return - V_260 ;
}
void F_218 ( void )
{
F_217 ( V_3 ) ;
F_216 ( V_283 ) ;
F_217 ( V_7 ) ;
F_216 ( V_279 ) ;
}
