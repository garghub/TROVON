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
F_11 ( struct V_14 * V_15 ,
struct V_16 * V_16 )
{
struct V_13 * V_17 , * V_18 ;
struct V_19 V_20 ;
struct V_21 * V_21 = & V_15 -> V_22 ;
F_12 ( & V_20 , V_21 ) ;
V_17 = F_13 ( V_21 , & V_20 , V_16 ) ;
if ( V_17 )
return V_17 -> V_23 ;
F_14 (freq, t, &cinfo.mds->list, wb_list) {
if ( V_17 -> V_24 == V_16 )
return V_17 -> V_23 ;
}
return NULL ;
}
static struct V_13 *
F_15 ( struct V_14 * V_15 , struct V_16 * V_16 )
{
struct V_13 * V_25 = NULL ;
if ( F_16 ( V_16 ) )
V_25 = (struct V_13 * ) F_17 ( V_16 ) ;
else if ( F_18 ( F_19 ( V_16 ) ) )
V_25 = F_11 ( V_15 ,
V_16 ) ;
if ( V_25 ) {
F_20 ( V_25 -> V_23 != V_25 ) ;
F_21 ( & V_25 -> V_26 ) ;
}
return V_25 ;
}
static struct V_13 * F_22 ( struct V_16 * V_16 )
{
struct V_21 * V_21 = F_23 ( V_16 ) -> V_27 ;
struct V_13 * V_25 = NULL ;
F_24 ( & V_21 -> V_28 ) ;
V_25 = F_15 ( F_25 ( V_21 ) , V_16 ) ;
F_26 ( & V_21 -> V_28 ) ;
return V_25 ;
}
static void F_27 ( struct V_16 * V_16 , unsigned int V_29 , unsigned int V_30 )
{
struct V_21 * V_21 = F_23 ( V_16 ) -> V_27 ;
T_1 V_31 , V_32 ;
T_2 V_33 ;
F_24 ( & V_21 -> V_28 ) ;
V_32 = F_28 ( V_21 ) ;
V_33 = ( V_32 - 1 ) >> V_34 ;
if ( V_32 > 0 && F_29 ( V_16 ) < V_33 )
goto V_35;
V_31 = F_30 ( V_16 ) + ( ( T_1 ) V_29 + V_30 ) ;
if ( V_32 >= V_31 )
goto V_35;
F_31 ( V_21 , V_31 ) ;
F_32 ( V_21 , V_36 ) ;
V_35:
F_26 ( & V_21 -> V_28 ) ;
}
static void F_33 ( struct V_16 * V_16 )
{
F_34 ( F_23 ( V_16 ) -> V_27 , F_23 ( V_16 ) ) ;
}
static struct V_13 *
F_35 ( struct V_13 * V_37 , unsigned int V_38 )
{
struct V_13 * V_25 ;
F_20 ( V_37 != V_37 -> V_23 ) ;
F_20 ( ! F_36 ( V_39 , & V_37 -> V_23 -> V_40 ) ) ;
V_25 = V_37 ;
do {
if ( V_38 >= V_25 -> V_41 &&
V_38 < ( V_25 -> V_41 + V_25 -> V_42 ) )
return V_25 ;
V_25 = V_25 -> V_43 ;
} while ( V_25 != V_37 );
return NULL ;
}
static bool F_37 ( struct V_13 * V_25 )
{
struct V_13 * V_44 ;
unsigned int V_45 = 0 ;
unsigned int V_46 = F_38 ( V_25 -> V_24 ) ;
F_39 ( V_25 , false ) ;
do {
V_44 = F_35 ( V_25 -> V_23 , V_45 ) ;
if ( V_44 ) {
F_20 ( V_44 -> V_41 != V_45 ) ;
V_45 += V_44 -> V_42 - ( V_45 - V_44 -> V_41 ) ;
}
} while ( V_44 && V_45 < V_46 );
F_40 ( V_25 ) ;
F_20 ( V_45 > V_46 ) ;
return V_45 == V_46 ;
}
static void F_41 ( struct V_13 * V_25 )
{
if ( F_42 ( V_25 -> V_24 ) )
return;
if ( ! F_37 ( V_25 ) )
return;
F_43 ( V_25 -> V_24 ) ;
}
static int F_44 ( struct V_47 * V_48 )
{
if ( V_48 -> V_49 )
return V_50 | V_51 ;
if ( V_48 -> V_52 || V_48 -> V_53 )
return V_54 | V_55 ;
return V_55 ;
}
static void F_45 ( struct V_16 * V_16 )
{
struct V_56 * V_57 = F_46 ( F_23 ( V_16 ) -> V_27 ) ;
int V_58 = F_47 ( V_16 ) ;
F_20 ( V_58 != 0 ) ;
if ( F_48 ( & V_57 -> V_59 ) >
V_60 ) {
F_49 ( & V_57 -> V_61 ,
V_62 ) ;
}
}
static void F_50 ( struct V_13 * V_25 )
{
struct V_21 * V_21 = F_23 ( V_25 -> V_24 ) -> V_27 ;
struct V_56 * V_57 = F_46 ( V_21 ) ;
if ( ! F_51 ( V_25 , V_63 ) )
return;
F_52 ( V_25 -> V_24 ) ;
if ( F_53 ( & V_57 -> V_59 ) < V_64 )
F_54 ( & V_57 -> V_61 , V_62 ) ;
}
static void
F_55 ( struct V_13 * V_25 )
{
F_56 ( V_65 , & V_25 -> V_40 ) ;
F_56 ( V_66 , & V_25 -> V_40 ) ;
F_56 ( V_67 , & V_25 -> V_40 ) ;
F_56 ( V_63 , & V_25 -> V_40 ) ;
F_56 ( V_68 , & V_25 -> V_40 ) ;
}
static int
F_57 ( struct V_21 * V_21 , struct V_13 * V_37 ,
struct V_13 * V_25 , bool V_69 )
__releases( &inode->i_lock
static void
F_58 ( struct V_13 * V_70 ,
struct V_13 * V_71 )
{
while ( V_70 ) {
struct V_13 * V_72 = V_70 ;
V_70 = ( V_72 -> V_43 == V_71 ) ?
NULL : V_72 -> V_43 ;
F_20 ( V_71 != V_72 -> V_23 ) ;
V_72 -> V_23 = V_72 ;
V_72 -> V_43 = V_72 ;
F_59 ( V_72 ) ;
if ( ! F_36 ( V_65 , & V_72 -> V_40 ) ) {
F_60 ( V_71 ) ;
F_55 ( V_72 ) ;
if ( F_61 ( V_73 , & V_72 -> V_40 ) )
F_60 ( V_72 ) ;
else
F_20 ( 1 ) ;
} else {
F_20 ( F_36 ( V_74 , & V_72 -> V_40 ) ) ;
F_55 ( V_72 ) ;
F_62 ( V_72 ) ;
}
}
}
static struct V_13 *
F_63 ( struct V_16 * V_16 , bool V_69 )
{
struct V_21 * V_21 = F_23 ( V_16 ) -> V_27 ;
struct V_13 * V_37 , * V_72 ;
struct V_13 * V_70 = NULL ;
unsigned int V_75 ;
int V_58 ;
V_76:
V_75 = 0 ;
F_20 ( V_70 ) ;
F_24 ( & V_21 -> V_28 ) ;
V_37 = F_15 ( F_25 ( V_21 ) , V_16 ) ;
if ( ! V_37 ) {
F_26 ( & V_21 -> V_28 ) ;
return NULL ;
}
V_58 = F_39 ( V_37 , true ) ;
if ( V_58 < 0 ) {
F_26 ( & V_21 -> V_28 ) ;
if ( ! V_69 && V_58 == - V_77 ) {
F_64 ( V_37 ) ;
F_60 ( V_37 ) ;
goto V_76;
}
F_60 ( V_37 ) ;
return F_65 ( V_58 ) ;
}
V_72 = V_37 ;
do {
F_20 ( V_72 -> V_78 !=
( V_37 -> V_78 + V_75 ) ) ;
V_75 += V_72 -> V_42 ;
if ( ! F_66 ( V_72 ) ) {
V_58 = F_57 ( V_21 , V_37 ,
V_72 , V_69 ) ;
if ( V_58 == 0 )
goto V_76;
return F_65 ( V_58 ) ;
}
V_72 = V_72 -> V_43 ;
} while ( V_72 != V_37 );
V_72 = V_37 ;
do {
F_67 ( V_72 ) ;
V_72 = V_72 -> V_43 ;
} while ( V_72 != V_37 );
if ( V_37 -> V_43 != V_37 ) {
V_70 = V_37 -> V_43 ;
V_37 -> V_43 = V_37 ;
V_37 -> V_42 = V_75 ;
}
F_55 ( V_37 ) ;
if ( ! F_68 ( V_73 , & V_37 -> V_40 ) )
F_21 ( & V_37 -> V_26 ) ;
F_40 ( V_37 ) ;
F_26 ( & V_21 -> V_28 ) ;
F_58 ( V_70 , V_37 ) ;
return V_37 ;
}
static int F_69 ( struct V_79 * V_80 ,
struct V_16 * V_16 , bool V_69 )
{
struct V_13 * V_25 ;
int V_58 = 0 ;
V_25 = F_63 ( V_16 , V_69 ) ;
if ( ! V_25 )
goto V_35;
V_58 = F_70 ( V_25 ) ;
if ( F_71 ( V_25 ) )
goto V_35;
F_45 ( V_16 ) ;
F_20 ( F_36 ( V_74 , & V_25 -> V_40 ) ) ;
V_58 = 0 ;
if ( ! F_72 ( V_80 , V_25 ) ) {
F_73 ( V_25 ) ;
V_58 = V_80 -> V_81 ;
}
V_35:
return V_58 ;
}
static int F_74 ( struct V_16 * V_16 , struct V_47 * V_48 , struct V_79 * V_80 )
{
struct V_21 * V_21 = F_23 ( V_16 ) -> V_27 ;
int V_58 ;
F_32 ( V_21 , V_82 ) ;
F_75 ( V_21 , V_83 , 1 ) ;
F_76 ( V_80 , F_29 ( V_16 ) ) ;
V_58 = F_69 ( V_80 , V_16 , V_48 -> V_84 == V_85 ) ;
if ( V_58 == - V_77 ) {
F_77 ( V_48 , V_16 ) ;
V_58 = 0 ;
}
return V_58 ;
}
static int F_78 ( struct V_16 * V_16 , struct V_47 * V_48 )
{
struct V_79 V_80 ;
int V_86 ;
F_79 ( & V_80 , V_16 -> V_87 -> V_27 , F_44 ( V_48 ) ,
false , & V_88 ) ;
V_86 = F_74 ( V_16 , V_48 , & V_80 ) ;
F_80 ( & V_80 ) ;
if ( V_86 < 0 )
return V_86 ;
if ( V_80 . V_81 < 0 )
return V_80 . V_81 ;
return 0 ;
}
int F_81 ( struct V_16 * V_16 , struct V_47 * V_48 )
{
int V_58 ;
V_58 = F_78 ( V_16 , V_48 ) ;
F_82 ( V_16 ) ;
return V_58 ;
}
static int F_83 ( struct V_16 * V_16 , struct V_47 * V_48 , void * V_89 )
{
int V_58 ;
V_58 = F_74 ( V_16 , V_48 , V_89 ) ;
F_82 ( V_16 ) ;
return V_58 ;
}
int F_84 ( struct V_90 * V_87 , struct V_47 * V_48 )
{
struct V_21 * V_21 = V_87 -> V_27 ;
unsigned long * V_91 = & F_25 ( V_21 ) -> V_12 ;
struct V_79 V_80 ;
int V_86 ;
V_86 = F_85 ( V_91 , V_92 ,
V_93 , V_94 ) ;
if ( V_86 )
goto V_95;
F_32 ( V_21 , V_96 ) ;
F_79 ( & V_80 , V_21 , F_44 ( V_48 ) , false ,
& V_88 ) ;
V_86 = F_86 ( V_87 , V_48 , F_83 , & V_80 ) ;
F_80 ( & V_80 ) ;
F_87 ( V_92 , V_91 ) ;
F_88 () ;
F_89 ( V_91 , V_92 ) ;
if ( V_86 < 0 )
goto V_95;
V_86 = V_80 . V_81 ;
if ( V_86 < 0 )
goto V_95;
return 0 ;
V_95:
return V_86 ;
}
static void F_90 ( struct V_21 * V_21 , struct V_13 * V_25 )
{
struct V_14 * V_15 = F_25 ( V_21 ) ;
F_20 ( V_25 -> V_43 != V_25 ) ;
F_66 ( V_25 ) ;
F_24 ( & V_21 -> V_28 ) ;
if ( ! V_15 -> V_97 && F_91 ( V_21 ) -> F_92 ( V_21 , V_98 ) )
V_21 -> V_99 ++ ;
if ( F_93 ( ! F_19 ( V_25 -> V_24 ) ) ) {
F_10 ( V_100 , & V_25 -> V_40 ) ;
F_94 ( V_25 -> V_24 ) ;
F_95 ( V_25 -> V_24 , ( unsigned long ) V_25 ) ;
}
V_15 -> V_97 ++ ;
F_96 ( F_68 ( V_73 , & V_25 -> V_40 ) ) ;
F_21 ( & V_25 -> V_26 ) ;
F_26 ( & V_21 -> V_28 ) ;
}
static void F_97 ( struct V_13 * V_25 )
{
struct V_21 * V_21 = V_25 -> V_101 -> V_102 -> V_103 ;
struct V_14 * V_15 = F_25 ( V_21 ) ;
struct V_13 * V_37 ;
if ( F_51 ( V_25 , V_68 ) ) {
V_37 = V_25 -> V_23 ;
F_24 ( & V_21 -> V_28 ) ;
if ( F_93 ( ! F_19 ( V_37 -> V_24 ) ) ) {
F_95 ( V_37 -> V_24 , 0 ) ;
F_98 ( V_37 -> V_24 ) ;
F_56 ( V_100 , & V_37 -> V_40 ) ;
}
V_15 -> V_97 -- ;
F_26 ( & V_21 -> V_28 ) ;
}
if ( F_61 ( V_73 , & V_25 -> V_40 ) )
F_60 ( V_25 ) ;
else
F_20 ( 1 ) ;
}
static void
F_99 ( struct V_13 * V_25 )
{
F_100 ( V_25 -> V_24 ) ;
}
void
F_101 ( struct V_13 * V_25 , struct V_104 * V_105 ,
struct V_19 * V_20 )
{
F_10 ( V_74 , & ( V_25 ) -> V_40 ) ;
F_24 ( V_20 -> V_106 ) ;
F_102 ( V_25 , V_105 ) ;
V_20 -> V_107 -> V_108 ++ ;
F_26 ( V_20 -> V_106 ) ;
if ( ! V_20 -> V_109 ) {
F_103 ( V_25 -> V_24 , V_110 ) ;
F_104 ( F_23 ( V_25 -> V_24 ) -> V_61 ,
V_111 ) ;
F_105 ( V_25 -> V_101 -> V_102 -> V_103 ,
V_112 ) ;
}
}
void
F_106 ( struct V_13 * V_25 ,
struct V_19 * V_20 )
{
if ( ! F_61 ( V_74 , & ( V_25 ) -> V_40 ) )
return;
F_107 ( V_25 ) ;
V_20 -> V_107 -> V_108 -- ;
}
static void F_12 ( struct V_19 * V_20 ,
struct V_21 * V_21 )
{
V_20 -> V_106 = & V_21 -> V_28 ;
V_20 -> V_107 = & F_25 ( V_21 ) -> V_113 ;
V_20 -> V_114 = F_108 ( V_21 ) ;
V_20 -> V_109 = NULL ;
V_20 -> V_115 = & V_116 ;
}
void F_109 ( struct V_19 * V_20 ,
struct V_21 * V_21 ,
struct V_117 * V_109 )
{
if ( V_109 )
F_110 ( V_20 , V_109 ) ;
else
F_12 ( V_20 , V_21 ) ;
}
void
F_111 ( struct V_13 * V_25 , struct V_118 * V_119 ,
struct V_19 * V_20 )
{
if ( F_112 ( V_25 , V_119 , V_20 ) )
return;
F_101 ( V_25 , & V_20 -> V_107 -> V_120 , V_20 ) ;
}
static void
F_113 ( struct V_16 * V_16 )
{
F_114 ( V_16 , V_110 ) ;
F_115 ( F_23 ( V_16 ) -> V_61 , V_111 ) ;
}
static void
F_67 ( struct V_13 * V_25 )
{
if ( F_36 ( V_74 , & V_25 -> V_40 ) ) {
struct V_21 * V_21 = V_25 -> V_101 -> V_102 -> V_103 ;
struct V_19 V_20 ;
F_12 ( & V_20 , V_21 ) ;
if ( ! F_116 ( V_25 , & V_20 ) ) {
F_106 ( V_25 , & V_20 ) ;
}
F_113 ( V_25 -> V_24 ) ;
}
}
int F_117 ( struct V_6 * V_8 )
{
if ( V_8 -> V_121 . V_122 == V_123 )
return V_8 -> V_119 == NULL ;
return V_8 -> V_121 . V_122 != V_124 ;
}
static void F_12 ( struct V_19 * V_20 ,
struct V_21 * V_21 )
{
}
void F_109 ( struct V_19 * V_20 ,
struct V_21 * V_21 ,
struct V_117 * V_109 )
{
}
void
F_111 ( struct V_13 * V_25 , struct V_118 * V_119 ,
struct V_19 * V_20 )
{
}
static void
F_67 ( struct V_13 * V_25 )
{
}
int F_117 ( struct V_6 * V_8 )
{
return 0 ;
}
static void F_118 ( struct V_6 * V_8 )
{
struct V_19 V_20 ;
unsigned long V_125 = 0 ;
if ( F_36 ( V_126 , & V_8 -> V_12 ) )
goto V_35;
F_12 ( & V_20 , V_8 -> V_21 ) ;
while ( ! F_119 ( & V_8 -> V_5 ) ) {
struct V_13 * V_25 = F_120 ( V_8 -> V_5 . V_127 ) ;
V_125 += V_25 -> V_42 ;
F_107 ( V_25 ) ;
if ( F_36 ( V_128 , & V_8 -> V_12 ) &&
( V_8 -> V_129 < V_125 ) ) {
F_33 ( V_25 -> V_24 ) ;
F_8 ( V_25 -> V_101 , V_8 -> error ) ;
goto V_130;
}
if ( F_117 ( V_8 ) ) {
memcpy ( & V_25 -> V_131 , & V_8 -> V_121 . V_132 , sizeof( V_25 -> V_131 ) ) ;
F_111 ( V_25 , V_8 -> V_119 , & V_20 ) ;
goto V_127;
}
V_130:
F_97 ( V_25 ) ;
V_127:
F_59 ( V_25 ) ;
F_50 ( V_25 ) ;
F_60 ( V_25 ) ;
}
V_35:
V_8 -> V_133 ( V_8 ) ;
}
unsigned long
F_121 ( struct V_19 * V_20 )
{
return V_20 -> V_107 -> V_108 ;
}
int
F_122 ( struct V_104 * V_134 , struct V_104 * V_105 ,
struct V_19 * V_20 , int V_135 )
{
struct V_13 * V_25 , * V_44 ;
int V_58 = 0 ;
F_14 (req, tmp, src, wb_list) {
if ( ! F_66 ( V_25 ) )
continue;
F_21 ( & V_25 -> V_26 ) ;
if ( F_123 ( V_20 -> V_106 ) )
F_124 ( V_25 , V_44 , V_136 ) ;
F_106 ( V_25 , V_20 ) ;
F_102 ( V_25 , V_105 ) ;
V_58 ++ ;
if ( ( V_58 == V_135 ) && ! V_20 -> V_109 )
break;
}
return V_58 ;
}
int
F_125 ( struct V_21 * V_21 , struct V_104 * V_105 ,
struct V_19 * V_20 )
{
int V_58 = 0 ;
F_24 ( V_20 -> V_106 ) ;
if ( V_20 -> V_107 -> V_108 > 0 ) {
const int V_135 = V_137 ;
V_58 = F_122 ( & V_20 -> V_107 -> V_120 , V_105 ,
V_20 , V_135 ) ;
V_58 += F_126 ( V_21 , V_20 , V_135 - V_58 ) ;
}
F_26 ( V_20 -> V_106 ) ;
return V_58 ;
}
unsigned long F_121 ( struct V_19 * V_20 )
{
return 0 ;
}
int F_125 ( struct V_21 * V_21 , struct V_104 * V_105 ,
struct V_19 * V_20 )
{
return 0 ;
}
static struct V_13 * F_127 ( struct V_21 * V_21 ,
struct V_16 * V_16 ,
unsigned int V_29 ,
unsigned int V_125 )
{
struct V_13 * V_25 ;
unsigned int V_138 ;
unsigned int V_31 ;
int error ;
if ( ! F_16 ( V_16 ) )
return NULL ;
V_31 = V_29 + V_125 ;
F_24 ( & V_21 -> V_28 ) ;
for (; ; ) {
V_25 = F_15 ( F_25 ( V_21 ) , V_16 ) ;
if ( V_25 == NULL )
goto V_139;
F_20 ( V_25 -> V_23 != V_25 ) ;
F_20 ( V_25 -> V_43 != V_25 ) ;
V_138 = V_25 -> V_78 + V_25 -> V_42 ;
if ( V_29 > V_138
|| V_31 < V_25 -> V_78 )
goto V_140;
if ( F_66 ( V_25 ) )
break;
F_26 ( & V_21 -> V_28 ) ;
error = F_128 ( V_25 ) ;
F_60 ( V_25 ) ;
if ( error != 0 )
goto V_95;
F_24 ( & V_21 -> V_28 ) ;
}
if ( V_29 < V_25 -> V_78 ) {
V_25 -> V_78 = V_29 ;
V_25 -> V_41 = V_29 ;
}
if ( V_31 > V_138 )
V_25 -> V_42 = V_31 - V_25 -> V_78 ;
else
V_25 -> V_42 = V_138 - V_25 -> V_78 ;
V_139:
if ( V_25 )
F_67 ( V_25 ) ;
F_26 ( & V_21 -> V_28 ) ;
return V_25 ;
V_140:
F_26 ( & V_21 -> V_28 ) ;
F_60 ( V_25 ) ;
error = F_129 ( V_21 , V_16 ) ;
V_95:
return F_65 ( error ) ;
}
static struct V_13 * F_130 ( struct V_9 * V_10 ,
struct V_16 * V_16 , unsigned int V_29 , unsigned int V_125 )
{
struct V_21 * V_21 = F_23 ( V_16 ) -> V_27 ;
struct V_13 * V_25 ;
V_25 = F_127 ( V_21 , V_16 , V_29 , V_125 ) ;
if ( V_25 != NULL )
goto V_35;
V_25 = F_131 ( V_10 , V_16 , NULL , V_29 , V_125 ) ;
if ( F_71 ( V_25 ) )
goto V_35;
F_90 ( V_21 , V_25 ) ;
V_35:
return V_25 ;
}
static int F_132 ( struct V_9 * V_10 , struct V_16 * V_16 ,
unsigned int V_29 , unsigned int V_30 )
{
struct V_13 * V_25 ;
V_25 = F_130 ( V_10 , V_16 , V_29 , V_30 ) ;
if ( F_71 ( V_25 ) )
return F_70 ( V_25 ) ;
F_27 ( V_16 , V_29 , V_30 ) ;
F_41 ( V_25 ) ;
F_99 ( V_25 ) ;
F_133 ( V_25 ) ;
return 0 ;
}
int F_134 ( struct V_141 * V_141 , struct V_16 * V_16 )
{
struct V_9 * V_10 = F_135 ( V_141 ) ;
struct V_142 * V_143 ;
struct V_13 * V_25 ;
int V_144 , V_145 ;
do {
V_25 = F_22 ( V_16 ) ;
if ( V_25 == NULL )
return 0 ;
V_143 = V_25 -> V_146 ;
V_144 = V_25 -> V_24 != V_16 || V_25 -> V_101 != V_10 ;
V_144 |= V_25 -> V_43 != V_25 ;
if ( V_143 && V_10 -> V_102 -> V_103 -> V_147 != NULL ) {
V_144 |= V_143 -> V_148 . V_149 != V_150 -> V_151
|| V_143 -> V_148 . V_152 != V_150 -> V_153 ;
}
F_60 ( V_25 ) ;
if ( ! V_144 )
return 0 ;
V_145 = F_129 ( F_23 ( V_16 ) -> V_27 , V_16 ) ;
} while ( V_145 == 0 );
return V_145 ;
}
int
F_136 ( struct V_141 * V_154 , struct V_21 * V_21 )
{
struct V_9 * V_10 = F_135 ( V_154 ) ;
struct V_155 * V_156 = F_46 ( V_21 ) -> V_157 -> V_158 ;
return F_137 ( V_156 , V_10 -> V_159 ) ;
}
bool F_138 ( struct V_9 * V_10 )
{
return F_139 ( V_10 -> V_159 ) ;
}
static bool F_140 ( struct V_16 * V_16 , struct V_21 * V_21 )
{
struct V_14 * V_15 = F_25 ( V_21 ) ;
if ( F_141 ( V_21 ) )
goto V_35;
if ( V_15 -> V_160 & V_161 )
return false ;
F_142 () ;
if ( F_36 ( V_162 , & V_15 -> V_12 ) )
return false ;
V_35:
if ( V_15 -> V_160 & V_163 )
return false ;
return F_42 ( V_16 ) != 0 ;
}
static int F_143 ( struct V_141 * V_141 , struct V_16 * V_16 , struct V_21 * V_21 )
{
if ( V_141 -> V_164 & V_165 )
return 0 ;
if ( ! F_140 ( V_16 , V_21 ) )
return 0 ;
if ( F_91 ( V_21 ) -> F_92 ( V_21 , V_98 ) )
return 1 ;
if ( V_21 -> V_147 == NULL || ( V_21 -> V_147 -> V_166 == 0 &&
V_21 -> V_147 -> V_167 == V_168 &&
V_21 -> V_147 -> V_169 != V_170 ) )
return 1 ;
return 0 ;
}
int F_144 ( struct V_141 * V_141 , struct V_16 * V_16 ,
unsigned int V_29 , unsigned int V_30 )
{
struct V_9 * V_10 = F_135 ( V_141 ) ;
struct V_21 * V_21 = F_23 ( V_16 ) -> V_27 ;
int V_145 = 0 ;
F_32 ( V_21 , V_171 ) ;
F_145 ( L_1 ,
V_141 , V_30 , ( long long ) ( F_30 ( V_16 ) + V_29 ) ) ;
if ( F_143 ( V_141 , V_16 , V_21 ) ) {
V_30 = V_135 ( V_30 + V_29 , F_38 ( V_16 ) ) ;
V_29 = 0 ;
}
V_145 = F_132 ( V_10 , V_16 , V_29 , V_30 ) ;
if ( V_145 < 0 )
F_33 ( V_16 ) ;
else
F_100 ( V_16 ) ;
F_145 ( L_2 ,
V_145 , ( long long ) F_28 ( V_21 ) ) ;
return V_145 ;
}
static int F_146 ( int V_172 )
{
switch ( V_172 & ( V_50 | V_54 ) ) {
case V_50 :
return V_173 ;
case V_54 :
return V_174 ;
}
return V_175 ;
}
static void F_147 ( struct V_6 * V_8 ,
struct V_176 * V_177 ,
struct V_178 * V_179 , int V_172 )
{
struct V_21 * V_21 = V_8 -> V_21 ;
int V_180 = F_146 ( V_172 ) ;
V_179 -> V_180 = V_180 ;
F_91 ( V_21 ) -> F_148 ( V_8 , V_177 ) ;
F_149 ( F_46 ( V_21 ) -> V_181 ,
& V_179 -> V_182 , V_177 , V_8 ) ;
}
static void F_73 ( struct V_13 * V_25 )
{
F_99 ( V_25 ) ;
F_59 ( V_25 ) ;
F_50 ( V_25 ) ;
F_60 ( V_25 ) ;
}
static void F_150 ( struct V_104 * V_37 )
{
struct V_13 * V_25 ;
while ( ! F_119 ( V_37 ) ) {
V_25 = F_120 ( V_37 -> V_127 ) ;
F_107 ( V_25 ) ;
F_73 ( V_25 ) ;
}
}
void F_79 ( struct V_79 * V_80 ,
struct V_21 * V_21 , int V_183 , bool V_184 ,
const struct V_185 * V_186 )
{
struct V_56 * V_187 = F_46 ( V_21 ) ;
const struct V_188 * V_189 = & V_190 ;
#ifdef F_151
if ( V_187 -> V_191 && ! V_184 )
V_189 = V_187 -> V_191 -> V_192 ;
#endif
F_152 ( V_80 , V_21 , V_189 , V_186 , & V_193 ,
V_187 -> V_194 , V_183 ) ;
}
void F_153 ( struct V_79 * V_80 )
{
V_80 -> V_189 = & V_190 ;
V_80 -> V_195 = F_46 ( V_80 -> V_196 ) -> V_194 ;
}
void F_154 ( struct V_197 * V_198 , void * V_199 )
{
struct V_1 * V_89 = V_199 ;
F_91 ( V_89 -> V_21 ) -> F_155 ( V_198 , V_89 ) ;
}
static void F_156 ( struct V_6 * V_8 )
{
}
static int F_157 ( const struct V_21 * V_21 )
{
T_3 V_200 = V_21 -> V_201 ;
int V_202 = 0 ;
if ( F_18 ( V_200 & V_203 ) )
V_202 = V_204 ;
if ( F_18 ( ( V_200 & V_205 ) && ( V_200 & V_206 ) ) )
V_202 |= V_207 ;
if ( F_18 ( V_202 && F_158 ( V_200 ) ) )
return V_202 ;
return 0 ;
}
static int F_159 ( struct V_197 * V_198 ,
struct V_6 * V_8 ,
struct V_21 * V_21 )
{
int V_145 ;
V_145 = F_91 ( V_21 ) -> F_160 ( V_198 , V_8 ) ;
if ( V_145 != 0 )
return V_145 ;
F_75 ( V_21 , V_208 , V_8 -> V_209 . V_30 ) ;
#if F_161 ( V_210 ) || F_161 ( V_211 )
if ( V_8 -> V_209 . V_121 -> V_122 < V_8 -> args . V_212 &&
V_198 -> V_213 >= 0 ) {
static unsigned long V_214 ;
if ( F_162 ( V_214 , V_215 ) ) {
F_145 ( L_3
L_4 ,
F_46 ( V_21 ) -> V_181 -> V_216 ,
V_8 -> V_209 . V_121 -> V_122 , V_8 -> args . V_212 ) ;
V_214 = V_215 + 300 * V_217 ;
}
}
#endif
if ( F_157 ( V_21 ) )
F_163 ( V_21 ) ;
return 0 ;
}
static void F_164 ( struct V_197 * V_198 ,
struct V_6 * V_8 )
{
struct V_218 * V_219 = & V_8 -> args ;
struct V_220 * V_221 = & V_8 -> V_209 ;
if ( V_221 -> V_30 < V_219 -> V_30 ) {
static unsigned long V_214 ;
F_32 ( V_8 -> V_21 , V_222 ) ;
if ( V_221 -> V_30 == 0 ) {
if ( F_162 ( V_214 , V_215 ) ) {
F_165 ( V_223
L_5 ,
V_219 -> V_30 ) ;
V_214 = V_215 + 300 * V_217 ;
}
F_166 ( V_8 , - V_224 , V_219 -> V_29 ) ;
V_198 -> V_213 = - V_224 ;
return;
}
if ( V_221 -> V_121 -> V_122 != V_225 ) {
V_8 -> V_226 += V_221 -> V_30 ;
V_219 -> V_29 += V_221 -> V_30 ;
V_219 -> V_227 += V_221 -> V_30 ;
V_219 -> V_30 -= V_221 -> V_30 ;
} else {
V_219 -> V_212 = V_124 ;
}
F_167 ( V_198 ) ;
}
}
static int F_168 ( struct V_14 * V_15 , int V_228 )
{
int V_58 ;
if ( ! F_68 ( V_229 , & V_15 -> V_12 ) )
return 1 ;
if ( ! V_228 )
return 0 ;
V_58 = F_169 ( & V_15 -> V_12 ,
V_229 ,
V_93 ,
V_94 ) ;
return ( V_58 < 0 ) ? V_58 : 1 ;
}
static void F_170 ( struct V_14 * V_15 )
{
F_56 ( V_229 , & V_15 -> V_12 ) ;
F_88 () ;
F_89 ( & V_15 -> V_12 , V_229 ) ;
}
void F_171 ( struct V_1 * V_89 )
{
F_172 ( V_89 -> V_230 ) ;
F_4 ( V_89 ) ;
}
int F_173 ( struct V_231 * V_232 , struct V_1 * V_89 ,
const struct V_233 * V_234 ,
int V_172 , int V_12 )
{
struct V_197 * V_198 ;
int V_180 = F_146 ( V_172 ) ;
struct V_176 V_177 = {
. V_235 = & V_89 -> args ,
. V_236 = & V_89 -> V_209 ,
. V_237 = V_89 -> V_159 ,
} ;
struct V_178 V_179 = {
. V_198 = & V_89 -> V_198 ,
. V_182 = V_232 ,
. V_176 = & V_177 ,
. V_238 = V_234 ,
. V_239 = V_89 ,
. V_240 = V_241 ,
. V_12 = V_242 | V_12 ,
. V_180 = V_180 ,
} ;
F_91 ( V_89 -> V_21 ) -> F_174 ( V_89 , & V_177 ) ;
F_145 ( L_6 , V_89 -> V_198 . V_243 ) ;
F_175 ( F_46 ( V_89 -> V_21 ) -> V_181 ,
V_244 , & V_179 . V_182 , & V_177 ) ;
V_198 = F_176 ( & V_179 ) ;
if ( F_71 ( V_198 ) )
return F_70 ( V_198 ) ;
if ( V_172 & V_245 )
F_177 ( V_198 ) ;
F_178 ( V_198 ) ;
return 0 ;
}
void F_179 ( struct V_1 * V_89 ,
struct V_104 * V_37 ,
struct V_118 * V_119 ,
struct V_19 * V_20 )
{
struct V_13 * V_246 = F_120 ( V_37 -> V_127 ) ;
struct V_21 * V_21 = V_246 -> V_101 -> V_102 -> V_103 ;
F_180 ( V_37 , & V_89 -> V_5 ) ;
V_89 -> V_21 = V_21 ;
V_89 -> V_159 = V_246 -> V_101 -> V_159 ;
V_89 -> V_119 = V_119 ;
V_89 -> V_247 = & V_248 ;
V_89 -> V_115 = V_20 -> V_115 ;
V_89 -> V_109 = V_20 -> V_109 ;
V_89 -> args . V_249 = F_181 ( V_89 -> V_21 ) ;
V_89 -> args . V_29 = 0 ;
V_89 -> args . V_30 = 0 ;
V_89 -> V_230 = F_182 ( V_246 -> V_101 ) ;
V_89 -> V_209 . V_250 = & V_89 -> V_250 ;
V_89 -> V_209 . V_121 = & V_89 -> V_121 ;
F_183 ( & V_89 -> V_250 ) ;
}
void F_184 ( struct V_104 * V_251 ,
struct V_118 * V_119 ,
struct V_19 * V_20 )
{
struct V_13 * V_25 ;
while ( ! F_119 ( V_251 ) ) {
V_25 = F_120 ( V_251 -> V_127 ) ;
F_107 ( V_25 ) ;
F_111 ( V_25 , V_119 , V_20 ) ;
if ( ! V_20 -> V_109 ) {
F_114 ( V_25 -> V_24 , V_110 ) ;
F_115 ( F_23 ( V_25 -> V_24 ) -> V_61 ,
V_111 ) ;
}
F_133 ( V_25 ) ;
}
}
static int
F_185 ( struct V_21 * V_21 , struct V_104 * V_37 , int V_172 ,
struct V_19 * V_20 )
{
struct V_1 * V_89 ;
V_89 = F_1 () ;
if ( ! V_89 )
goto V_252;
F_179 ( V_89 , V_37 , NULL , V_20 ) ;
F_186 ( & V_20 -> V_107 -> V_253 ) ;
return F_173 ( F_187 ( V_21 ) , V_89 , V_89 -> V_247 ,
V_172 , 0 ) ;
V_252:
F_184 ( V_37 , NULL , V_20 ) ;
V_20 -> V_115 -> V_254 ( F_25 ( V_21 ) ) ;
return - V_255 ;
}
static void F_188 ( struct V_197 * V_198 , void * V_199 )
{
struct V_1 * V_89 = V_199 ;
F_145 ( L_7 ,
V_198 -> V_243 , V_198 -> V_213 ) ;
F_91 ( V_89 -> V_21 ) -> F_189 ( V_198 , V_89 ) ;
}
static void F_190 ( struct V_1 * V_89 )
{
struct V_13 * V_25 ;
int V_145 = V_89 -> V_198 . V_213 ;
struct V_19 V_20 ;
while ( ! F_119 ( & V_89 -> V_5 ) ) {
V_25 = F_120 ( V_89 -> V_5 . V_127 ) ;
F_107 ( V_25 ) ;
F_113 ( V_25 -> V_24 ) ;
F_145 ( L_8 ,
V_25 -> V_101 -> V_102 -> V_256 -> V_257 ,
( unsigned long long ) F_191 ( V_25 -> V_101 -> V_102 -> V_103 ) ,
V_25 -> V_42 ,
( long long ) F_192 ( V_25 ) ) ;
if ( V_145 < 0 ) {
F_8 ( V_25 -> V_101 , V_145 ) ;
F_97 ( V_25 ) ;
F_145 ( L_9 , V_145 ) ;
goto V_127;
}
if ( ! memcmp ( & V_25 -> V_131 , & V_89 -> V_121 . V_132 , sizeof( V_25 -> V_131 ) ) ) {
F_97 ( V_25 ) ;
F_145 ( L_10 ) ;
goto V_127;
}
F_145 ( L_11 ) ;
F_99 ( V_25 ) ;
F_10 ( V_258 , & V_25 -> V_101 -> V_12 ) ;
V_127:
F_133 ( V_25 ) ;
}
F_109 ( & V_20 , V_89 -> V_21 , V_89 -> V_109 ) ;
if ( F_193 ( & V_20 . V_107 -> V_253 ) )
F_170 ( F_25 ( V_89 -> V_21 ) ) ;
}
static void F_194 ( void * V_199 )
{
struct V_1 * V_89 = V_199 ;
V_89 -> V_115 -> V_259 ( V_89 ) ;
F_171 ( V_199 ) ;
}
int F_195 ( struct V_21 * V_21 , struct V_104 * V_37 ,
int V_172 , struct V_19 * V_20 )
{
int V_145 ;
V_145 = F_196 ( V_21 , V_37 , V_172 , V_20 ) ;
if ( V_145 == V_260 )
V_145 = F_185 ( V_21 , V_37 , V_172 , V_20 ) ;
return V_145 ;
}
int F_197 ( struct V_21 * V_21 , int V_172 )
{
F_198 ( V_37 ) ;
struct V_19 V_20 ;
int V_228 = V_172 & V_245 ;
int V_209 ;
V_209 = F_168 ( F_25 ( V_21 ) , V_228 ) ;
if ( V_209 <= 0 )
goto V_261;
F_12 ( & V_20 , V_21 ) ;
V_209 = F_125 ( V_21 , & V_37 , & V_20 ) ;
if ( V_209 ) {
int error ;
error = F_195 ( V_21 , & V_37 , V_172 , & V_20 ) ;
if ( error < 0 )
return error ;
if ( ! V_228 )
goto V_261;
error = F_199 ( & F_25 ( V_21 ) -> V_12 ,
V_229 ,
V_93 ,
V_94 ) ;
if ( error < 0 )
return error ;
} else
F_170 ( F_25 ( V_21 ) ) ;
return V_209 ;
V_261:
F_105 ( V_21 , V_112 ) ;
return V_209 ;
}
static int F_200 ( struct V_21 * V_21 , struct V_47 * V_48 )
{
struct V_14 * V_15 = F_25 ( V_21 ) ;
int V_12 = V_245 ;
int V_58 = 0 ;
if ( ! V_15 -> V_113 . V_108 )
return V_58 ;
if ( V_48 -> V_84 == V_85 ) {
if ( V_15 -> V_113 . V_108 <= ( V_15 -> V_97 >> 1 ) )
goto V_261;
V_12 = 0 ;
}
V_58 = F_197 ( V_21 , V_12 ) ;
if ( V_58 >= 0 ) {
if ( V_48 -> V_84 == V_85 ) {
if ( V_58 < V_48 -> V_262 )
V_48 -> V_262 -= V_58 ;
else
V_48 -> V_262 = 0 ;
}
return 0 ;
}
V_261:
F_105 ( V_21 , V_112 ) ;
return V_58 ;
}
static int F_200 ( struct V_21 * V_21 , struct V_47 * V_48 )
{
return 0 ;
}
int F_201 ( struct V_21 * V_21 , struct V_47 * V_48 )
{
return F_200 ( V_21 , V_48 ) ;
}
int F_202 ( struct V_21 * V_21 )
{
struct V_47 V_48 = {
. V_84 = V_263 ,
. V_262 = V_264 ,
. V_265 = 0 ,
. V_266 = V_267 ,
} ;
int V_58 ;
F_203 ( V_21 ) ;
V_58 = F_204 ( V_21 , & V_48 ) ;
F_205 ( V_21 , V_58 ) ;
return V_58 ;
}
int F_206 ( struct V_21 * V_21 , struct V_16 * V_16 )
{
struct V_13 * V_25 ;
int V_58 = 0 ;
F_207 ( V_16 ) ;
V_25 = F_63 ( V_16 , false ) ;
if ( F_71 ( V_25 ) ) {
V_58 = F_70 ( V_25 ) ;
} else if ( V_25 ) {
F_97 ( V_25 ) ;
F_208 ( V_16 , V_268 ) ;
F_133 ( V_25 ) ;
}
return V_58 ;
}
int F_129 ( struct V_21 * V_21 , struct V_16 * V_16 )
{
T_1 V_265 = F_30 ( V_16 ) ;
T_1 V_266 = V_265 + ( T_1 ) ( V_268 - 1 ) ;
struct V_47 V_48 = {
. V_84 = V_263 ,
. V_262 = 0 ,
. V_265 = V_265 ,
. V_266 = V_266 ,
} ;
int V_58 ;
F_209 ( V_21 ) ;
for (; ; ) {
F_207 ( V_16 ) ;
if ( F_210 ( V_16 ) ) {
V_58 = F_78 ( V_16 , & V_48 ) ;
if ( V_58 < 0 )
goto V_269;
continue;
}
V_58 = 0 ;
if ( ! F_16 ( V_16 ) )
break;
V_58 = F_197 ( V_21 , V_245 ) ;
if ( V_58 < 0 )
goto V_269;
}
V_269:
F_211 ( V_21 , V_58 ) ;
return V_58 ;
}
int F_212 ( struct V_90 * V_87 , struct V_16 * V_270 ,
struct V_16 * V_16 , enum V_271 V_200 )
{
if ( F_16 ( V_16 ) )
return - V_272 ;
if ( ! F_213 ( V_16 , V_273 ) )
return - V_272 ;
return F_214 ( V_87 , V_270 , V_16 , V_200 ) ;
}
int T_4 F_215 ( void )
{
V_274 = F_216 ( L_12 ,
sizeof( struct V_6 ) ,
0 , V_275 ,
NULL ) ;
if ( V_274 == NULL )
return - V_255 ;
V_7 = F_217 ( V_276 ,
V_274 ) ;
if ( V_7 == NULL )
goto V_277;
V_278 = F_216 ( L_13 ,
sizeof( struct V_1 ) ,
0 , V_275 ,
NULL ) ;
if ( V_278 == NULL )
goto V_279;
V_3 = F_217 ( V_280 ,
V_278 ) ;
if ( V_3 == NULL )
goto V_281;
V_282 = ( 16 * F_218 ( V_283 ) ) << ( V_284 - 10 ) ;
if ( V_282 > 256 * 1024 )
V_282 = 256 * 1024 ;
return 0 ;
V_281:
F_219 ( V_278 ) ;
V_279:
F_220 ( V_7 ) ;
V_277:
F_219 ( V_274 ) ;
return - V_255 ;
}
void F_221 ( void )
{
F_220 ( V_3 ) ;
F_219 ( V_278 ) ;
F_220 ( V_7 ) ;
F_219 ( V_274 ) ;
}
