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
if ( V_69 -> V_75 == ( V_31 -> V_75 + V_72 ) ) {
V_72 += V_69 -> V_36 ;
} else if ( F_17 ( V_69 -> V_75 < V_31 -> V_75 ||
( ( V_69 -> V_75 + V_69 -> V_36 ) >
( V_31 -> V_75 + V_72 ) ) ) ) {
F_37 ( V_31 ) ;
F_23 ( & V_20 -> V_22 ) ;
return F_62 ( - V_76 ) ;
}
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
static int F_66 ( struct V_77 * V_78 ,
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
if ( ! F_69 ( V_78 , V_17 ) ) {
F_70 ( V_17 ) ;
V_44 = V_78 -> V_79 ;
}
V_29:
return V_44 ;
}
static int F_71 ( struct V_16 * V_16 , struct V_42 * V_43 , struct V_77 * V_78 )
{
struct V_20 * V_20 = F_20 ( V_16 ) -> V_21 ;
int V_44 ;
F_29 ( V_20 , V_80 ) ;
F_72 ( V_20 , V_81 , 1 ) ;
F_73 ( V_78 , F_26 ( V_16 ) ) ;
V_44 = F_66 ( V_78 , V_16 , V_43 -> V_48 == V_82 ) ;
if ( V_44 == - V_74 ) {
F_74 ( V_43 , V_16 ) ;
V_44 = 0 ;
}
return V_44 ;
}
static int F_75 ( struct V_16 * V_16 , struct V_42 * V_43 )
{
struct V_77 V_78 ;
int V_83 ;
F_76 ( & V_78 , V_16 -> V_84 -> V_21 , F_41 ( V_43 ) ,
false , & V_85 ) ;
V_83 = F_71 ( V_16 , V_43 , & V_78 ) ;
F_77 ( & V_78 ) ;
if ( V_83 < 0 )
return V_83 ;
if ( V_78 . V_79 < 0 )
return V_78 . V_79 ;
return 0 ;
}
int F_78 ( struct V_16 * V_16 , struct V_42 * V_43 )
{
int V_44 ;
V_44 = F_75 ( V_16 , V_43 ) ;
F_79 ( V_16 ) ;
return V_44 ;
}
static int F_80 ( struct V_16 * V_16 , struct V_42 * V_43 , void * V_86 )
{
int V_44 ;
V_44 = F_71 ( V_16 , V_43 , V_86 ) ;
F_79 ( V_16 ) ;
return V_44 ;
}
int F_81 ( struct V_87 * V_84 , struct V_42 * V_43 )
{
struct V_20 * V_20 = V_84 -> V_21 ;
unsigned long * V_88 = & F_22 ( V_20 ) -> V_12 ;
struct V_77 V_78 ;
int V_83 ;
V_83 = F_82 ( V_88 , V_89 ,
V_90 , V_91 ) ;
if ( V_83 )
goto V_92;
F_29 ( V_20 , V_93 ) ;
F_76 ( & V_78 , V_20 , F_41 ( V_43 ) , false ,
& V_85 ) ;
V_83 = F_83 ( V_84 , V_43 , F_80 , & V_78 ) ;
F_77 ( & V_78 ) ;
F_84 ( V_89 , V_88 ) ;
F_85 () ;
F_86 ( V_88 , V_89 ) ;
if ( V_83 < 0 )
goto V_92;
V_83 = V_78 . V_79 ;
if ( V_83 < 0 )
goto V_92;
return 0 ;
V_92:
return V_83 ;
}
static void F_87 ( struct V_20 * V_20 , struct V_13 * V_17 )
{
struct V_14 * V_15 = F_22 ( V_20 ) ;
F_17 ( V_17 -> V_37 != V_17 ) ;
F_63 ( V_17 ) ;
F_21 ( & V_20 -> V_22 ) ;
if ( ! V_15 -> V_94 &&
F_88 ( V_20 ) -> F_89 ( V_20 , V_95 ) )
V_20 -> V_96 ++ ;
if ( F_90 ( ! F_15 ( V_17 -> V_41 ) ) ) {
F_10 ( V_97 , & V_17 -> V_34 ) ;
F_91 ( V_17 -> V_41 ) ;
F_92 ( V_17 -> V_41 , ( unsigned long ) V_17 ) ;
}
V_15 -> V_94 ++ ;
F_93 ( F_65 ( V_70 , & V_17 -> V_34 ) ) ;
F_18 ( & V_17 -> V_19 ) ;
F_23 ( & V_20 -> V_22 ) ;
}
static void F_94 ( struct V_13 * V_17 )
{
struct V_20 * V_20 = F_95 ( V_17 -> V_98 -> V_99 ) ;
struct V_14 * V_15 = F_22 ( V_20 ) ;
struct V_13 * V_31 ;
if ( F_48 ( V_17 , V_65 ) ) {
V_31 = V_17 -> V_18 ;
F_21 ( & V_20 -> V_22 ) ;
if ( F_90 ( ! F_15 ( V_31 -> V_41 ) ) ) {
F_92 ( V_31 -> V_41 , 0 ) ;
F_96 ( V_31 -> V_41 ) ;
F_85 () ;
F_97 ( V_31 -> V_41 , V_100 ) ;
F_53 ( V_97 , & V_31 -> V_34 ) ;
}
V_15 -> V_94 -- ;
F_23 ( & V_20 -> V_22 ) ;
} else {
F_21 ( & V_20 -> V_22 ) ;
V_15 -> V_94 -- ;
F_23 ( & V_20 -> V_22 ) ;
}
if ( F_58 ( V_70 , & V_17 -> V_34 ) )
F_57 ( V_17 ) ;
}
static void
F_98 ( struct V_13 * V_17 )
{
F_99 ( V_17 -> V_41 ) ;
}
static struct V_13 *
F_16 ( struct V_14 * V_15 ,
struct V_16 * V_16 )
{
struct V_13 * V_101 , * V_102 ;
struct V_103 V_104 ;
struct V_20 * V_20 = & V_15 -> V_105 ;
F_100 ( & V_104 , V_20 ) ;
V_101 = F_101 ( V_20 , & V_104 , V_16 ) ;
if ( V_101 )
return V_101 -> V_18 ;
F_102 (freq, t, &cinfo.mds->list, wb_list) {
if ( V_101 -> V_41 == V_16 )
return V_101 -> V_18 ;
}
return NULL ;
}
void
F_103 ( struct V_13 * V_17 , struct V_106 * V_107 ,
struct V_103 * V_104 )
{
F_10 ( V_71 , & ( V_17 ) -> V_34 ) ;
F_21 ( V_104 -> V_108 ) ;
F_104 ( V_17 , V_107 ) ;
V_104 -> V_109 -> V_110 ++ ;
F_23 ( V_104 -> V_108 ) ;
if ( ! V_104 -> V_111 )
F_105 ( V_17 -> V_41 ) ;
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
static void F_100 ( struct V_103 * V_104 ,
struct V_20 * V_20 )
{
V_104 -> V_108 = & V_20 -> V_22 ;
V_104 -> V_109 = & F_22 ( V_20 ) -> V_112 ;
V_104 -> V_113 = F_108 ( V_20 ) ;
V_104 -> V_111 = NULL ;
V_104 -> V_114 = & V_115 ;
}
void F_109 ( struct V_103 * V_104 ,
struct V_20 * V_20 ,
struct V_116 * V_111 )
{
if ( V_111 )
F_110 ( V_104 , V_111 ) ;
else
F_100 ( V_104 , V_20 ) ;
}
void
F_111 ( struct V_13 * V_17 , struct V_117 * V_118 ,
struct V_103 * V_104 , T_3 V_119 )
{
if ( F_112 ( V_17 , V_118 , V_104 , V_119 ) )
return;
F_103 ( V_17 , & V_104 -> V_109 -> V_120 , V_104 ) ;
}
static void
F_113 ( struct V_16 * V_16 )
{
F_114 ( V_16 , V_121 ) ;
F_115 ( F_116 ( F_20 ( V_16 ) -> V_21 ) , V_122 ) ;
}
static void
F_64 ( struct V_13 * V_17 )
{
if ( F_33 ( V_71 , & V_17 -> V_34 ) ) {
struct V_20 * V_20 = F_95 ( V_17 -> V_98 -> V_99 ) ;
struct V_103 V_104 ;
F_100 ( & V_104 , V_20 ) ;
if ( ! F_117 ( V_17 , & V_104 ) ) {
F_106 ( V_17 , & V_104 ) ;
}
F_113 ( V_17 -> V_41 ) ;
}
}
int F_118 ( struct V_6 * V_8 )
{
if ( V_8 -> V_123 . V_124 == V_125 )
return V_8 -> V_118 == NULL ;
return V_8 -> V_123 . V_124 != V_126 ;
}
static void F_119 ( struct V_6 * V_8 )
{
struct V_103 V_104 ;
unsigned long V_127 = 0 ;
if ( F_33 ( V_128 , & V_8 -> V_12 ) )
goto V_29;
F_100 ( & V_104 , V_8 -> V_20 ) ;
while ( ! F_120 ( & V_8 -> V_5 ) ) {
struct V_13 * V_17 = F_121 ( V_8 -> V_5 . V_129 ) ;
V_127 += V_17 -> V_36 ;
F_107 ( V_17 ) ;
if ( F_33 ( V_130 , & V_8 -> V_12 ) &&
( V_8 -> V_131 < V_127 ) ) {
F_30 ( V_17 -> V_41 ) ;
F_8 ( V_17 -> V_98 , V_8 -> error ) ;
goto V_132;
}
if ( F_118 ( V_8 ) ) {
memcpy ( & V_17 -> V_133 , & V_8 -> V_123 . V_134 , sizeof( V_17 -> V_133 ) ) ;
F_111 ( V_17 , V_8 -> V_118 , & V_104 ,
V_8 -> V_135 ) ;
goto V_129;
}
V_132:
F_94 ( V_17 ) ;
V_129:
F_56 ( V_17 ) ;
F_47 ( V_17 ) ;
F_57 ( V_17 ) ;
}
V_29:
V_8 -> V_136 ( V_8 ) ;
}
unsigned long
F_122 ( struct V_103 * V_104 )
{
return V_104 -> V_109 -> V_110 ;
}
int
F_123 ( struct V_106 * V_137 , struct V_106 * V_107 ,
struct V_103 * V_104 , int V_138 )
{
struct V_13 * V_17 , * V_38 ;
int V_44 = 0 ;
F_102 (req, tmp, src, wb_list) {
if ( ! F_63 ( V_17 ) )
continue;
F_18 ( & V_17 -> V_19 ) ;
if ( F_124 ( V_104 -> V_108 ) )
F_125 ( V_17 , V_38 , V_139 ) ;
F_106 ( V_17 , V_104 ) ;
F_104 ( V_17 , V_107 ) ;
V_44 ++ ;
if ( ( V_44 == V_138 ) && ! V_104 -> V_111 )
break;
}
return V_44 ;
}
int
F_126 ( struct V_20 * V_20 , struct V_106 * V_107 ,
struct V_103 * V_104 )
{
int V_44 = 0 ;
F_21 ( V_104 -> V_108 ) ;
if ( V_104 -> V_109 -> V_110 > 0 ) {
const int V_138 = V_140 ;
V_44 = F_123 ( & V_104 -> V_109 -> V_120 , V_107 ,
V_104 , V_138 ) ;
V_44 += F_127 ( V_20 , V_104 , V_138 - V_44 ) ;
}
F_23 ( V_104 -> V_108 ) ;
return V_44 ;
}
static struct V_13 * F_128 ( struct V_20 * V_20 ,
struct V_16 * V_16 ,
unsigned int V_23 ,
unsigned int V_127 )
{
struct V_13 * V_17 ;
unsigned int V_141 ;
unsigned int V_25 ;
int error ;
if ( ! F_12 ( V_16 ) )
return NULL ;
V_25 = V_23 + V_127 ;
F_21 ( & V_20 -> V_22 ) ;
for (; ; ) {
V_17 = F_11 ( F_22 ( V_20 ) , V_16 ) ;
if ( V_17 == NULL )
goto V_142;
F_17 ( V_17 -> V_18 != V_17 ) ;
F_17 ( V_17 -> V_37 != V_17 ) ;
V_141 = V_17 -> V_75 + V_17 -> V_36 ;
if ( V_23 > V_141
|| V_25 < V_17 -> V_75 )
goto V_143;
if ( F_63 ( V_17 ) )
break;
F_23 ( & V_20 -> V_22 ) ;
error = F_129 ( V_17 ) ;
F_57 ( V_17 ) ;
if ( error != 0 )
goto V_92;
F_21 ( & V_20 -> V_22 ) ;
}
if ( V_23 < V_17 -> V_75 ) {
V_17 -> V_75 = V_23 ;
V_17 -> V_35 = V_23 ;
}
if ( V_25 > V_141 )
V_17 -> V_36 = V_25 - V_17 -> V_75 ;
else
V_17 -> V_36 = V_141 - V_17 -> V_75 ;
V_142:
if ( V_17 )
F_64 ( V_17 ) ;
F_23 ( & V_20 -> V_22 ) ;
return V_17 ;
V_143:
F_23 ( & V_20 -> V_22 ) ;
F_57 ( V_17 ) ;
error = F_130 ( V_20 , V_16 ) ;
V_92:
return F_62 ( error ) ;
}
static struct V_13 * F_131 ( struct V_9 * V_10 ,
struct V_16 * V_16 , unsigned int V_23 , unsigned int V_127 )
{
struct V_20 * V_20 = F_20 ( V_16 ) -> V_21 ;
struct V_13 * V_17 ;
V_17 = F_128 ( V_20 , V_16 , V_23 , V_127 ) ;
if ( V_17 != NULL )
goto V_29;
V_17 = F_132 ( V_10 , V_16 , NULL , V_23 , V_127 ) ;
if ( F_68 ( V_17 ) )
goto V_29;
F_87 ( V_20 , V_17 ) ;
V_29:
return V_17 ;
}
static int F_133 ( struct V_9 * V_10 , struct V_16 * V_16 ,
unsigned int V_23 , unsigned int V_24 )
{
struct V_13 * V_17 ;
V_17 = F_131 ( V_10 , V_16 , V_23 , V_24 ) ;
if ( F_68 ( V_17 ) )
return F_67 ( V_17 ) ;
F_24 ( V_16 , V_23 , V_24 ) ;
F_38 ( V_17 ) ;
F_98 ( V_17 ) ;
F_134 ( V_17 ) ;
return 0 ;
}
int F_135 ( struct V_144 * V_144 , struct V_16 * V_16 )
{
struct V_9 * V_10 = F_136 ( V_144 ) ;
struct V_145 * V_146 ;
struct V_147 * V_148 = F_137 ( V_144 ) -> V_149 ;
struct V_13 * V_17 ;
int V_150 , V_151 ;
do {
V_17 = F_19 ( V_16 ) ;
if ( V_17 == NULL )
return 0 ;
V_146 = V_17 -> V_152 ;
V_150 = V_17 -> V_41 != V_16 || V_17 -> V_98 != V_10 ;
V_150 |= V_17 -> V_37 != V_17 ;
if ( V_146 && V_148 &&
! ( F_138 ( & V_148 -> V_153 ) &&
F_138 ( & V_148 -> V_154 ) ) ) {
V_150 |= V_146 -> V_155 . V_156 != V_157 -> V_158
|| V_146 -> V_155 . V_159 != V_157 -> V_160 ;
}
F_57 ( V_17 ) ;
if ( ! V_150 )
return 0 ;
V_151 = F_130 ( F_20 ( V_16 ) -> V_21 , V_16 ) ;
} while ( V_151 == 0 );
return V_151 ;
}
int
F_139 ( struct V_144 * V_161 , struct V_20 * V_20 )
{
struct V_9 * V_10 = F_136 ( V_161 ) ;
struct V_162 * V_163 = F_43 ( V_20 ) -> V_164 -> V_165 ;
return F_140 ( V_163 , V_10 -> V_166 ) ;
}
bool F_141 ( struct V_9 * V_10 )
{
return F_142 ( V_10 -> V_166 ) ;
}
static bool F_143 ( struct V_16 * V_16 , struct V_20 * V_20 )
{
struct V_14 * V_15 = F_22 ( V_20 ) ;
if ( F_144 ( V_20 ) )
goto V_29;
if ( V_15 -> V_167 & V_168 )
return false ;
F_145 () ;
if ( F_33 ( V_169 , & V_15 -> V_12 ) )
return false ;
V_29:
if ( V_15 -> V_167 & V_170 )
return false ;
return F_39 ( V_16 ) != 0 ;
}
static bool
F_146 ( struct V_171 * V_172 )
{
return V_172 -> V_173 == 0 && V_172 -> V_174 == V_175 &&
V_172 -> V_176 == V_177 ;
}
static int F_147 ( struct V_144 * V_144 , struct V_16 * V_16 , struct V_20 * V_20 )
{
int V_44 ;
struct V_147 * V_148 = V_20 -> V_149 ;
struct V_171 * V_172 ;
if ( V_144 -> V_178 & V_179 )
return 0 ;
if ( ! F_143 ( V_16 , V_20 ) )
return 0 ;
if ( F_88 ( V_20 ) -> F_89 ( V_20 , V_95 ) )
return 1 ;
if ( ! V_148 || ( F_138 ( & V_148 -> V_154 ) &&
F_138 ( & V_148 -> V_153 ) ) )
return 0 ;
V_44 = 0 ;
F_21 ( & V_148 -> V_180 ) ;
if ( ! F_120 ( & V_148 -> V_153 ) ) {
V_172 = F_148 ( & V_148 -> V_153 , struct V_171 ,
V_181 ) ;
if ( F_146 ( V_172 ) )
V_44 = 1 ;
} else if ( ! F_120 ( & V_148 -> V_154 ) ) {
V_172 = F_148 ( & V_148 -> V_154 , struct V_171 ,
V_181 ) ;
if ( V_172 -> V_176 == V_177 )
V_44 = 1 ;
}
F_23 ( & V_148 -> V_180 ) ;
return V_44 ;
}
int F_149 ( struct V_144 * V_144 , struct V_16 * V_16 ,
unsigned int V_23 , unsigned int V_24 )
{
struct V_9 * V_10 = F_136 ( V_144 ) ;
struct V_20 * V_20 = F_20 ( V_16 ) -> V_21 ;
int V_151 = 0 ;
F_29 ( V_20 , V_182 ) ;
F_150 ( L_1 ,
V_144 , V_24 , ( long long ) ( F_27 ( V_16 ) + V_23 ) ) ;
if ( F_147 ( V_144 , V_16 , V_20 ) ) {
V_24 = V_138 ( V_24 + V_23 , F_35 ( V_16 ) ) ;
V_23 = 0 ;
}
V_151 = F_133 ( V_10 , V_16 , V_23 , V_24 ) ;
if ( V_151 < 0 )
F_30 ( V_16 ) ;
else
F_99 ( V_16 ) ;
F_150 ( L_2 ,
V_151 , ( long long ) F_25 ( V_20 ) ) ;
return V_151 ;
}
static int F_151 ( int V_183 )
{
switch ( V_183 & ( V_46 | V_53 ) ) {
case V_46 :
return V_184 ;
case V_53 :
return V_185 ;
}
return V_186 ;
}
static void F_152 ( struct V_6 * V_8 ,
struct V_187 * V_188 ,
const struct V_189 * V_190 ,
struct V_191 * V_192 , int V_183 )
{
int V_193 = F_151 ( V_183 ) ;
V_192 -> V_193 = V_193 ;
V_190 -> V_194 ( V_8 , V_188 ) ;
F_153 ( F_43 ( V_8 -> V_20 ) -> V_195 ,
& V_192 -> V_196 , V_188 , V_8 ) ;
}
static void F_70 ( struct V_13 * V_17 )
{
F_98 ( V_17 ) ;
F_56 ( V_17 ) ;
F_47 ( V_17 ) ;
F_57 ( V_17 ) ;
}
static void F_154 ( struct V_106 * V_31 )
{
struct V_13 * V_17 ;
while ( ! F_120 ( V_31 ) ) {
V_17 = F_121 ( V_31 -> V_129 ) ;
F_107 ( V_17 ) ;
F_70 ( V_17 ) ;
}
}
void F_76 ( struct V_77 * V_78 ,
struct V_20 * V_20 , int V_197 , bool V_198 ,
const struct V_199 * V_200 )
{
struct V_54 * V_201 = F_43 ( V_20 ) ;
const struct V_202 * V_203 = & V_204 ;
#ifdef F_155
if ( V_201 -> V_205 && ! V_198 )
V_203 = V_201 -> V_205 -> V_206 ;
#endif
F_156 ( V_78 , V_20 , V_203 , V_200 , & V_207 ,
V_201 -> V_208 , V_197 ) ;
}
void F_157 ( struct V_77 * V_78 )
{
struct V_209 * V_210 ;
V_78 -> V_203 = & V_204 ;
F_158 ( V_78 ) ;
V_210 = & V_78 -> V_211 [ 0 ] ;
V_210 -> V_212 = F_43 ( V_78 -> V_213 ) -> V_208 ;
}
void F_159 ( struct V_214 * V_215 , void * V_216 )
{
struct V_1 * V_86 = V_216 ;
F_88 ( V_86 -> V_20 ) -> F_160 ( V_215 , V_86 ) ;
}
static void F_161 ( struct V_6 * V_8 )
{
}
static int F_162 ( const struct V_20 * V_20 )
{
T_4 V_217 = V_20 -> V_218 ;
int V_219 = 0 ;
if ( F_14 ( V_217 & V_220 ) )
V_219 = V_221 ;
if ( F_14 ( ( V_217 & V_222 ) && ( V_217 & V_223 ) ) )
V_219 |= V_224 ;
if ( F_14 ( V_219 && F_163 ( V_217 ) ) )
return V_219 ;
return 0 ;
}
static void F_164 ( struct V_6 * V_8 ,
struct V_225 * V_226 )
{
struct V_227 * V_228 = & V_8 -> args ;
struct V_229 * V_230 = & V_8 -> V_231 ;
if ( ! ( V_226 -> V_232 & V_233 ) )
return;
if ( V_228 -> V_23 + V_230 -> V_24 != V_226 -> V_234 )
return;
if ( F_165 ( V_226 -> V_234 ) < F_25 ( V_8 -> V_20 ) )
return;
F_166 ( V_226 ) ;
}
void F_167 ( struct V_6 * V_8 )
{
struct V_225 * V_226 = V_8 -> V_231 . V_226 ;
struct V_20 * V_20 = V_8 -> V_20 ;
if ( V_226 == NULL )
return;
F_21 ( & V_20 -> V_22 ) ;
F_164 ( V_8 , V_226 ) ;
F_168 ( V_20 , V_226 ) ;
F_23 ( & V_20 -> V_22 ) ;
}
static int F_169 ( struct V_214 * V_215 ,
struct V_6 * V_8 ,
struct V_20 * V_20 )
{
int V_151 ;
V_151 = F_88 ( V_20 ) -> F_170 ( V_215 , V_8 ) ;
if ( V_151 != 0 )
return V_151 ;
F_72 ( V_20 , V_235 , V_8 -> V_231 . V_24 ) ;
if ( V_8 -> V_231 . V_123 -> V_124 < V_8 -> args . V_236 &&
V_215 -> V_237 >= 0 ) {
static unsigned long V_238 ;
if ( F_171 ( V_238 , V_239 ) ) {
F_150 ( L_3
L_4 ,
F_43 ( V_20 ) -> V_195 -> V_240 ,
V_8 -> V_231 . V_123 -> V_124 , V_8 -> args . V_236 ) ;
V_238 = V_239 + 300 * V_241 ;
}
}
if ( F_162 ( V_20 ) )
F_172 ( V_20 ) ;
return 0 ;
}
static void F_173 ( struct V_214 * V_215 ,
struct V_6 * V_8 )
{
struct V_227 * V_228 = & V_8 -> args ;
struct V_229 * V_230 = & V_8 -> V_231 ;
if ( V_230 -> V_24 < V_228 -> V_24 ) {
static unsigned long V_238 ;
F_29 ( V_8 -> V_20 , V_242 ) ;
if ( V_230 -> V_24 == 0 ) {
if ( F_171 ( V_238 , V_239 ) ) {
F_174 ( V_243
L_5 ,
V_228 -> V_24 ) ;
V_238 = V_239 + 300 * V_241 ;
}
F_175 ( V_8 , - V_76 , V_228 -> V_23 ) ;
V_215 -> V_237 = - V_76 ;
return;
}
if ( V_230 -> V_123 -> V_124 != V_244 ) {
V_8 -> V_245 += V_230 -> V_24 ;
V_228 -> V_23 += V_230 -> V_24 ;
V_228 -> V_246 += V_230 -> V_24 ;
V_228 -> V_24 -= V_230 -> V_24 ;
} else {
V_228 -> V_236 = V_126 ;
}
F_176 ( V_215 ) ;
}
}
static int F_177 ( struct V_14 * V_15 , int V_247 )
{
int V_44 ;
if ( ! F_65 ( V_248 , & V_15 -> V_12 ) )
return 1 ;
if ( ! V_247 )
return 0 ;
V_44 = F_178 ( & V_15 -> V_12 ,
V_248 ,
V_90 ,
V_91 ) ;
return ( V_44 < 0 ) ? V_44 : 1 ;
}
static void F_179 ( struct V_14 * V_15 )
{
F_53 ( V_248 , & V_15 -> V_12 ) ;
F_85 () ;
F_86 ( & V_15 -> V_12 , V_248 ) ;
}
void F_180 ( struct V_1 * V_86 )
{
F_181 ( V_86 -> V_249 ) ;
F_4 ( V_86 ) ;
}
int F_182 ( struct V_250 * V_251 , struct V_1 * V_86 ,
const struct V_189 * V_252 ,
const struct V_253 * V_254 ,
int V_183 , int V_12 )
{
struct V_214 * V_215 ;
int V_193 = F_151 ( V_183 ) ;
struct V_187 V_188 = {
. V_255 = & V_86 -> args ,
. V_256 = & V_86 -> V_231 ,
. V_257 = V_86 -> V_166 ,
} ;
struct V_191 V_192 = {
. V_215 = & V_86 -> V_215 ,
. V_196 = V_251 ,
. V_187 = & V_188 ,
. V_258 = V_254 ,
. V_259 = V_86 ,
. V_260 = V_261 ,
. V_12 = V_262 | V_12 ,
. V_193 = V_193 ,
} ;
V_252 -> V_263 ( V_86 , & V_188 ) ;
F_150 ( L_6 , V_86 -> V_215 . V_264 ) ;
F_183 ( F_43 ( V_86 -> V_20 ) -> V_195 ,
V_265 , & V_192 . V_196 , & V_188 ) ;
V_215 = F_184 ( & V_192 ) ;
if ( F_68 ( V_215 ) )
return F_67 ( V_215 ) ;
if ( V_183 & V_266 )
F_185 ( V_215 ) ;
F_186 ( V_215 ) ;
return 0 ;
}
static T_1 F_187 ( struct V_106 * V_31 )
{
T_1 V_267 = 0 ;
struct V_13 * V_17 ;
F_188 (req, head, wb_list)
if ( V_267 < ( F_189 ( V_17 ) + V_17 -> V_36 ) )
V_267 = F_189 ( V_17 ) + V_17 -> V_36 ;
return V_267 ;
}
void F_190 ( struct V_1 * V_86 ,
struct V_106 * V_31 ,
struct V_117 * V_118 ,
struct V_103 * V_104 )
{
struct V_13 * V_268 = F_121 ( V_31 -> V_129 ) ;
struct V_20 * V_20 = F_95 ( V_268 -> V_98 -> V_99 ) ;
F_191 ( V_31 , & V_86 -> V_5 ) ;
V_86 -> V_20 = V_20 ;
V_86 -> V_166 = V_268 -> V_98 -> V_166 ;
V_86 -> V_118 = V_118 ;
if ( V_118 )
V_86 -> V_267 = F_187 ( & V_86 -> V_5 ) ;
V_86 -> V_269 = & V_270 ;
V_86 -> V_114 = V_104 -> V_114 ;
V_86 -> V_111 = V_104 -> V_111 ;
V_86 -> args . V_271 = F_192 ( V_86 -> V_20 ) ;
V_86 -> args . V_23 = 0 ;
V_86 -> args . V_24 = 0 ;
V_86 -> V_249 = F_193 ( V_268 -> V_98 ) ;
V_86 -> V_231 . V_226 = & V_86 -> V_226 ;
V_86 -> V_231 . V_123 = & V_86 -> V_123 ;
F_194 ( & V_86 -> V_226 ) ;
}
void F_195 ( struct V_106 * V_272 ,
struct V_117 * V_118 ,
struct V_103 * V_104 ,
T_3 V_119 )
{
struct V_13 * V_17 ;
while ( ! F_120 ( V_272 ) ) {
V_17 = F_121 ( V_272 -> V_129 ) ;
F_107 ( V_17 ) ;
F_111 ( V_17 , V_118 , V_104 , V_119 ) ;
if ( ! V_104 -> V_111 )
F_113 ( V_17 -> V_41 ) ;
F_134 ( V_17 ) ;
}
}
static int
F_196 ( struct V_20 * V_20 , struct V_106 * V_31 , int V_183 ,
struct V_103 * V_104 )
{
struct V_1 * V_86 ;
V_86 = F_1 () ;
if ( ! V_86 )
goto V_273;
F_190 ( V_86 , V_31 , NULL , V_104 ) ;
F_197 ( & V_104 -> V_109 -> V_274 ) ;
return F_182 ( F_198 ( V_20 ) , V_86 , F_88 ( V_20 ) ,
V_86 -> V_269 , V_183 , 0 ) ;
V_273:
F_195 ( V_31 , NULL , V_104 , 0 ) ;
V_104 -> V_114 -> V_275 ( F_22 ( V_20 ) ) ;
return - V_276 ;
}
static void F_199 ( struct V_214 * V_215 , void * V_216 )
{
struct V_1 * V_86 = V_216 ;
F_150 ( L_7 ,
V_215 -> V_264 , V_215 -> V_237 ) ;
F_88 ( V_86 -> V_20 ) -> F_200 ( V_215 , V_86 ) ;
}
static void F_201 ( struct V_1 * V_86 )
{
struct V_13 * V_17 ;
int V_151 = V_86 -> V_215 . V_237 ;
struct V_103 V_104 ;
struct V_54 * V_55 ;
while ( ! F_120 ( & V_86 -> V_5 ) ) {
V_17 = F_121 ( V_86 -> V_5 . V_129 ) ;
F_107 ( V_17 ) ;
F_113 ( V_17 -> V_41 ) ;
F_150 ( L_8 ,
V_17 -> V_98 -> V_99 -> V_277 -> V_278 ,
( unsigned long long ) F_202 ( F_95 ( V_17 -> V_98 -> V_99 ) ) ,
V_17 -> V_36 ,
( long long ) F_189 ( V_17 ) ) ;
if ( V_151 < 0 ) {
F_8 ( V_17 -> V_98 , V_151 ) ;
F_94 ( V_17 ) ;
F_150 ( L_9 , V_151 ) ;
goto V_129;
}
if ( ! memcmp ( & V_17 -> V_133 , & V_86 -> V_123 . V_134 , sizeof( V_17 -> V_133 ) ) ) {
F_94 ( V_17 ) ;
F_150 ( L_10 ) ;
goto V_129;
}
F_150 ( L_11 ) ;
F_98 ( V_17 ) ;
F_10 ( V_279 , & V_17 -> V_98 -> V_12 ) ;
V_129:
F_134 ( V_17 ) ;
}
V_55 = F_43 ( V_86 -> V_20 ) ;
if ( F_203 ( & V_55 -> V_56 ) < V_61 )
F_51 ( & V_55 -> V_58 , V_59 ) ;
F_109 ( & V_104 , V_86 -> V_20 , V_86 -> V_111 ) ;
if ( F_204 ( & V_104 . V_109 -> V_274 ) )
F_179 ( F_22 ( V_86 -> V_20 ) ) ;
}
static void F_205 ( void * V_216 )
{
struct V_1 * V_86 = V_216 ;
V_86 -> V_114 -> V_280 ( V_86 ) ;
F_180 ( V_216 ) ;
}
int F_206 ( struct V_20 * V_20 , struct V_106 * V_31 ,
int V_183 , struct V_103 * V_104 )
{
int V_151 ;
V_151 = F_207 ( V_20 , V_31 , V_183 , V_104 ) ;
if ( V_151 == V_281 )
V_151 = F_196 ( V_20 , V_31 , V_183 , V_104 ) ;
return V_151 ;
}
int F_208 ( struct V_20 * V_20 , int V_183 )
{
F_209 ( V_31 ) ;
struct V_103 V_104 ;
int V_247 = V_183 & V_266 ;
int V_231 ;
V_231 = F_177 ( F_22 ( V_20 ) , V_247 ) ;
if ( V_231 <= 0 )
goto V_282;
F_100 ( & V_104 , V_20 ) ;
V_231 = F_126 ( V_20 , & V_31 , & V_104 ) ;
if ( V_231 ) {
int error ;
error = F_206 ( V_20 , & V_31 , V_183 , & V_104 ) ;
if ( error < 0 )
return error ;
if ( ! V_247 )
goto V_282;
error = F_210 ( & F_22 ( V_20 ) -> V_12 ,
V_248 ,
V_90 ,
V_91 ) ;
if ( error < 0 )
return error ;
} else
F_179 ( F_22 ( V_20 ) ) ;
return V_231 ;
V_282:
F_211 ( V_20 , V_283 ) ;
return V_231 ;
}
static int F_212 ( struct V_20 * V_20 , struct V_42 * V_43 )
{
struct V_14 * V_15 = F_22 ( V_20 ) ;
int V_12 = V_266 ;
int V_44 = 0 ;
if ( ! V_15 -> V_112 . V_110 )
return V_44 ;
if ( V_43 -> V_48 == V_82 ) {
if ( V_15 -> V_112 . V_110 <= ( V_15 -> V_94 >> 1 ) )
goto V_282;
V_12 = 0 ;
}
V_44 = F_208 ( V_20 , V_12 ) ;
if ( V_44 >= 0 ) {
if ( V_43 -> V_48 == V_82 ) {
if ( V_44 < V_43 -> V_284 )
V_43 -> V_284 -= V_44 ;
else
V_43 -> V_284 = 0 ;
}
return 0 ;
}
V_282:
F_211 ( V_20 , V_283 ) ;
return V_44 ;
}
int F_213 ( struct V_20 * V_20 , struct V_42 * V_43 )
{
return F_212 ( V_20 , V_43 ) ;
}
int F_214 ( struct V_20 * V_20 )
{
int V_44 ;
F_215 ( V_20 ) ;
V_44 = F_216 ( V_20 -> V_285 ) ;
if ( V_44 )
goto V_29;
V_44 = F_208 ( V_20 , V_266 ) ;
if ( V_44 < 0 )
goto V_29;
F_217 ( V_20 , true ) ;
V_44 = 0 ;
V_29:
F_218 ( V_20 , V_44 ) ;
return V_44 ;
}
int F_219 ( struct V_20 * V_20 , struct V_16 * V_16 )
{
struct V_13 * V_17 ;
int V_44 = 0 ;
F_220 ( V_16 ) ;
V_17 = F_60 ( V_16 , false ) ;
if ( F_68 ( V_17 ) ) {
V_44 = F_67 ( V_17 ) ;
} else if ( V_17 ) {
F_94 ( V_17 ) ;
F_134 ( V_17 ) ;
}
return V_44 ;
}
int F_130 ( struct V_20 * V_20 , struct V_16 * V_16 )
{
T_1 V_286 = F_27 ( V_16 ) ;
T_1 V_287 = V_286 + ( T_1 ) ( V_288 - 1 ) ;
struct V_42 V_43 = {
. V_48 = V_49 ,
. V_284 = 0 ,
. V_286 = V_286 ,
. V_287 = V_287 ,
} ;
int V_44 ;
F_221 ( V_20 ) ;
for (; ; ) {
F_220 ( V_16 ) ;
if ( F_222 ( V_16 ) ) {
V_44 = F_75 ( V_16 , & V_43 ) ;
if ( V_44 < 0 )
goto V_289;
continue;
}
V_44 = 0 ;
if ( ! F_12 ( V_16 ) )
break;
V_44 = F_208 ( V_20 , V_266 ) ;
if ( V_44 < 0 )
goto V_289;
}
V_289:
F_223 ( V_20 , V_44 ) ;
return V_44 ;
}
int F_224 ( struct V_87 * V_84 , struct V_16 * V_290 ,
struct V_16 * V_16 , enum V_291 V_217 )
{
if ( F_12 ( V_16 ) )
return - V_292 ;
if ( ! F_225 ( V_16 , V_293 ) )
return - V_292 ;
return F_226 ( V_84 , V_290 , V_16 , V_217 ) ;
}
int T_5 F_227 ( void )
{
V_294 = F_228 ( L_12 ,
sizeof( struct V_6 ) ,
0 , V_295 ,
NULL ) ;
if ( V_294 == NULL )
return - V_276 ;
V_7 = F_229 ( V_296 ,
V_294 ) ;
if ( V_7 == NULL )
goto V_297;
V_298 = F_228 ( L_13 ,
sizeof( struct V_1 ) ,
0 , V_295 ,
NULL ) ;
if ( V_298 == NULL )
goto V_299;
V_3 = F_229 ( V_300 ,
V_298 ) ;
if ( V_3 == NULL )
goto V_301;
V_302 = ( 16 * F_230 ( V_303 ) ) << ( V_304 - 10 ) ;
if ( V_302 > 256 * 1024 )
V_302 = 256 * 1024 ;
return 0 ;
V_301:
F_231 ( V_298 ) ;
V_299:
F_232 ( V_7 ) ;
V_297:
F_231 ( V_294 ) ;
return - V_276 ;
}
void F_233 ( void )
{
F_232 ( V_3 ) ;
F_231 ( V_298 ) ;
F_232 ( V_7 ) ;
F_231 ( V_294 ) ;
}
