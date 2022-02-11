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
V_44 = V_47 ;
return V_44 ;
}
static void F_42 ( struct V_16 * V_16 )
{
struct V_50 * V_51 = F_43 ( F_20 ( V_16 ) -> V_21 ) ;
int V_44 = F_44 ( V_16 ) ;
F_17 ( V_44 != 0 ) ;
if ( F_45 ( & V_51 -> V_52 ) >
V_53 ) {
F_46 ( & V_51 -> V_54 ,
V_55 ) ;
}
}
static void F_47 ( struct V_13 * V_17 )
{
struct V_20 * V_20 = F_20 ( V_17 -> V_41 ) -> V_21 ;
struct V_50 * V_51 = F_43 ( V_20 ) ;
if ( ! F_48 ( V_17 , V_56 ) )
return;
F_49 ( V_17 -> V_41 ) ;
if ( F_50 ( & V_51 -> V_52 ) < V_57 )
F_51 ( & V_51 -> V_54 , V_55 ) ;
}
static void
F_52 ( struct V_13 * V_17 )
{
F_53 ( V_58 , & V_17 -> V_34 ) ;
F_53 ( V_59 , & V_17 -> V_34 ) ;
F_53 ( V_60 , & V_17 -> V_34 ) ;
F_53 ( V_56 , & V_17 -> V_34 ) ;
F_53 ( V_61 , & V_17 -> V_34 ) ;
}
static int
F_54 ( struct V_20 * V_20 , struct V_13 * V_31 ,
struct V_13 * V_17 , bool V_62 )
__releases( &inode->i_lock
static void
F_55 ( struct V_13 * V_63 ,
struct V_13 * V_64 )
{
while ( V_63 ) {
struct V_13 * V_65 = V_63 ;
V_63 = ( V_65 -> V_37 == V_64 ) ?
NULL : V_65 -> V_37 ;
F_17 ( V_64 != V_65 -> V_18 ) ;
V_65 -> V_18 = V_65 ;
V_65 -> V_37 = V_65 ;
F_56 ( V_65 ) ;
if ( ! F_33 ( V_58 , & V_65 -> V_34 ) ) {
F_57 ( V_64 ) ;
F_52 ( V_65 ) ;
if ( F_58 ( V_66 , & V_65 -> V_34 ) )
F_57 ( V_65 ) ;
else
F_17 ( 1 ) ;
} else {
F_17 ( F_33 ( V_67 , & V_65 -> V_34 ) ) ;
F_52 ( V_65 ) ;
F_59 ( V_65 ) ;
}
}
}
static struct V_13 *
F_60 ( struct V_16 * V_16 , bool V_62 )
{
struct V_20 * V_20 = F_20 ( V_16 ) -> V_21 ;
struct V_13 * V_31 , * V_65 ;
struct V_13 * V_63 = NULL ;
unsigned int V_68 ;
int V_44 ;
V_69:
V_68 = 0 ;
F_17 ( V_63 ) ;
F_21 ( & V_20 -> V_22 ) ;
V_31 = F_11 ( F_22 ( V_20 ) , V_16 ) ;
if ( ! V_31 ) {
F_23 ( & V_20 -> V_22 ) ;
return NULL ;
}
V_44 = F_36 ( V_31 , true ) ;
if ( V_44 < 0 ) {
F_23 ( & V_20 -> V_22 ) ;
if ( ! V_62 && V_44 == - V_70 ) {
F_61 ( V_31 ) ;
F_57 ( V_31 ) ;
goto V_69;
}
F_57 ( V_31 ) ;
return F_62 ( V_44 ) ;
}
V_65 = V_31 ;
do {
if ( V_65 -> V_71 == ( V_31 -> V_71 + V_68 ) ) {
V_68 += V_65 -> V_36 ;
} else if ( F_17 ( V_65 -> V_71 < V_31 -> V_71 ||
( ( V_65 -> V_71 + V_65 -> V_36 ) >
( V_31 -> V_71 + V_68 ) ) ) ) {
F_37 ( V_31 ) ;
F_23 ( & V_20 -> V_22 ) ;
return F_62 ( - V_72 ) ;
}
if ( ! F_63 ( V_65 ) ) {
V_44 = F_54 ( V_20 , V_31 ,
V_65 , V_62 ) ;
if ( V_44 == 0 )
goto V_69;
return F_62 ( V_44 ) ;
}
V_65 = V_65 -> V_37 ;
} while ( V_65 != V_31 );
V_65 = V_31 ;
do {
F_64 ( V_65 ) ;
V_65 = V_65 -> V_37 ;
} while ( V_65 != V_31 );
if ( V_31 -> V_37 != V_31 ) {
V_63 = V_31 -> V_37 ;
V_31 -> V_37 = V_31 ;
V_31 -> V_36 = V_68 ;
}
F_52 ( V_31 ) ;
if ( ! F_65 ( V_66 , & V_31 -> V_34 ) )
F_18 ( & V_31 -> V_19 ) ;
F_37 ( V_31 ) ;
F_23 ( & V_20 -> V_22 ) ;
F_55 ( V_63 , V_31 ) ;
return V_31 ;
}
static void F_66 ( struct V_13 * V_17 )
{
F_56 ( V_17 ) ;
F_47 ( V_17 ) ;
F_57 ( V_17 ) ;
F_67 ( F_20 ( V_17 -> V_41 ) ,
V_17 -> V_41 ) ;
}
static int F_68 ( struct V_73 * V_74 ,
struct V_16 * V_16 , bool V_62 ,
bool V_75 )
{
struct V_13 * V_17 ;
int V_44 = 0 ;
V_17 = F_60 ( V_16 , V_62 ) ;
if ( ! V_17 )
goto V_29;
V_44 = F_69 ( V_17 ) ;
if ( F_70 ( V_17 ) )
goto V_29;
F_42 ( V_16 ) ;
F_17 ( F_33 ( V_67 , & V_17 -> V_34 ) ) ;
V_44 = 0 ;
if ( ! F_71 ( V_74 , V_17 ) ) {
V_44 = V_74 -> V_76 ;
if ( F_72 ( V_44 ) ) {
F_8 ( V_17 -> V_77 , V_44 ) ;
if ( V_75 ) {
F_66 ( V_17 ) ;
goto V_29;
}
}
F_73 ( V_17 ) ;
V_44 = - V_70 ;
} else
F_74 ( F_20 ( V_16 ) -> V_21 ,
V_78 , 1 ) ;
V_29:
return V_44 ;
}
static int F_75 ( struct V_16 * V_16 , struct V_42 * V_43 ,
struct V_73 * V_74 , bool V_75 )
{
int V_44 ;
F_76 ( V_74 , F_26 ( V_16 ) ) ;
V_44 = F_68 ( V_74 , V_16 , V_43 -> V_48 == V_79 ,
V_75 ) ;
if ( V_44 == - V_70 ) {
F_77 ( V_43 , V_16 ) ;
V_44 = 0 ;
}
return V_44 ;
}
static int F_78 ( struct V_16 * V_16 ,
struct V_42 * V_43 ,
bool V_75 )
{
struct V_73 V_74 ;
struct V_20 * V_20 = F_20 ( V_16 ) -> V_21 ;
int V_80 ;
F_29 ( V_20 , V_81 ) ;
F_79 ( & V_74 , V_20 , F_41 ( V_43 ) ,
false , & V_82 ) ;
V_80 = F_75 ( V_16 , V_43 , & V_74 , V_75 ) ;
F_80 ( & V_74 ) ;
if ( V_80 < 0 )
return V_80 ;
if ( V_74 . V_76 < 0 )
return V_74 . V_76 ;
return 0 ;
}
int F_81 ( struct V_16 * V_16 , struct V_42 * V_43 )
{
int V_44 ;
V_44 = F_78 ( V_16 , V_43 , false ) ;
F_82 ( V_16 ) ;
return V_44 ;
}
static int F_83 ( struct V_16 * V_16 , struct V_42 * V_43 , void * V_83 )
{
int V_44 ;
V_44 = F_75 ( V_16 , V_43 , V_83 , false ) ;
F_82 ( V_16 ) ;
return V_44 ;
}
int F_84 ( struct V_84 * V_85 , struct V_42 * V_43 )
{
struct V_20 * V_20 = V_85 -> V_21 ;
unsigned long * V_86 = & F_22 ( V_20 ) -> V_12 ;
struct V_73 V_74 ;
int V_80 ;
V_80 = F_85 ( V_86 , V_87 ,
V_88 , V_89 ) ;
if ( V_80 )
goto V_90;
F_29 ( V_20 , V_91 ) ;
F_79 ( & V_74 , V_20 , F_41 ( V_43 ) , false ,
& V_82 ) ;
V_80 = F_86 ( V_85 , V_43 , F_83 , & V_74 ) ;
F_80 ( & V_74 ) ;
F_87 ( V_87 , V_86 ) ;
F_88 () ;
F_89 ( V_86 , V_87 ) ;
if ( V_80 < 0 )
goto V_90;
V_80 = V_74 . V_76 ;
if ( V_80 < 0 )
goto V_90;
return 0 ;
V_90:
return V_80 ;
}
static void F_90 ( struct V_20 * V_20 , struct V_13 * V_17 )
{
struct V_14 * V_15 = F_22 ( V_20 ) ;
F_17 ( V_17 -> V_37 != V_17 ) ;
F_63 ( V_17 ) ;
F_21 ( & V_20 -> V_22 ) ;
if ( ! V_15 -> V_92 &&
F_91 ( V_20 ) -> F_92 ( V_20 , V_93 ) )
V_20 -> V_94 ++ ;
if ( F_93 ( ! F_15 ( V_17 -> V_41 ) ) ) {
F_10 ( V_95 , & V_17 -> V_34 ) ;
F_94 ( V_17 -> V_41 ) ;
F_95 ( V_17 -> V_41 , ( unsigned long ) V_17 ) ;
}
V_15 -> V_92 ++ ;
F_96 ( F_65 ( V_66 , & V_17 -> V_34 ) ) ;
F_18 ( & V_17 -> V_19 ) ;
F_23 ( & V_20 -> V_22 ) ;
}
static void F_97 ( struct V_13 * V_17 )
{
struct V_20 * V_20 = F_98 ( V_17 -> V_77 -> V_96 ) ;
struct V_14 * V_15 = F_22 ( V_20 ) ;
struct V_13 * V_31 ;
if ( F_48 ( V_17 , V_61 ) ) {
V_31 = V_17 -> V_18 ;
F_21 ( & V_20 -> V_22 ) ;
if ( F_93 ( ! F_15 ( V_31 -> V_41 ) ) ) {
F_95 ( V_31 -> V_41 , 0 ) ;
F_99 ( V_31 -> V_41 ) ;
F_88 () ;
F_100 ( V_31 -> V_41 , V_97 ) ;
F_53 ( V_95 , & V_31 -> V_34 ) ;
}
V_15 -> V_92 -- ;
F_23 ( & V_20 -> V_22 ) ;
} else {
F_21 ( & V_20 -> V_22 ) ;
V_15 -> V_92 -- ;
F_23 ( & V_20 -> V_22 ) ;
}
if ( F_58 ( V_66 , & V_17 -> V_34 ) )
F_57 ( V_17 ) ;
}
static void
F_101 ( struct V_13 * V_17 )
{
F_102 ( V_17 -> V_41 ) ;
}
static struct V_13 *
F_16 ( struct V_14 * V_15 ,
struct V_16 * V_16 )
{
struct V_13 * V_98 , * V_99 ;
struct V_100 V_101 ;
struct V_20 * V_20 = & V_15 -> V_102 ;
F_103 ( & V_101 , V_20 ) ;
V_98 = F_104 ( V_20 , & V_101 , V_16 ) ;
if ( V_98 )
return V_98 -> V_18 ;
F_105 (freq, t, &cinfo.mds->list, wb_list) {
if ( V_98 -> V_41 == V_16 )
return V_98 -> V_18 ;
}
return NULL ;
}
void
F_106 ( struct V_13 * V_17 , struct V_103 * V_104 ,
struct V_100 * V_101 )
{
F_10 ( V_67 , & V_17 -> V_34 ) ;
F_107 ( V_17 , V_104 ) ;
V_101 -> V_105 -> V_106 ++ ;
}
void
F_108 ( struct V_13 * V_17 , struct V_100 * V_101 )
{
F_21 ( V_101 -> V_107 ) ;
F_106 ( V_17 , & V_101 -> V_105 -> V_108 , V_101 ) ;
F_23 ( V_101 -> V_107 ) ;
F_109 ( V_17 -> V_41 , V_101 ) ;
}
void
F_110 ( struct V_13 * V_17 ,
struct V_100 * V_101 )
{
if ( ! F_58 ( V_67 , & ( V_17 ) -> V_34 ) )
return;
F_111 ( V_17 ) ;
V_101 -> V_105 -> V_106 -- ;
}
static void F_103 ( struct V_100 * V_101 ,
struct V_20 * V_20 )
{
V_101 -> V_107 = & V_20 -> V_22 ;
V_101 -> V_105 = & F_22 ( V_20 ) -> V_109 ;
V_101 -> V_110 = F_112 ( V_20 ) ;
V_101 -> V_111 = NULL ;
V_101 -> V_112 = & V_113 ;
}
void F_113 ( struct V_100 * V_101 ,
struct V_20 * V_20 ,
struct V_114 * V_111 )
{
if ( V_111 )
F_114 ( V_101 , V_111 ) ;
else
F_103 ( V_101 , V_20 ) ;
}
void
F_115 ( struct V_13 * V_17 , struct V_115 * V_116 ,
struct V_100 * V_101 , T_3 V_117 )
{
if ( F_116 ( V_17 , V_116 , V_101 , V_117 ) )
return;
F_108 ( V_17 , V_101 ) ;
}
static void
F_117 ( struct V_16 * V_16 )
{
F_118 ( V_16 , V_118 ) ;
F_119 ( & F_120 ( F_20 ( V_16 ) -> V_21 ) -> V_119 ,
V_120 ) ;
}
static void
F_64 ( struct V_13 * V_17 )
{
if ( F_33 ( V_67 , & V_17 -> V_34 ) ) {
struct V_20 * V_20 = F_98 ( V_17 -> V_77 -> V_96 ) ;
struct V_100 V_101 ;
F_103 ( & V_101 , V_20 ) ;
if ( ! F_121 ( V_17 , & V_101 ) ) {
F_110 ( V_17 , & V_101 ) ;
}
F_117 ( V_17 -> V_41 ) ;
}
}
int F_122 ( struct V_6 * V_8 )
{
if ( V_8 -> V_121 . V_122 == V_123 )
return V_8 -> V_116 == NULL ;
return V_8 -> V_121 . V_122 != V_124 ;
}
static void F_123 ( struct V_6 * V_8 )
{
struct V_100 V_101 ;
unsigned long V_125 = 0 ;
if ( F_33 ( V_126 , & V_8 -> V_12 ) )
goto V_29;
F_103 ( & V_101 , V_8 -> V_20 ) ;
while ( ! F_124 ( & V_8 -> V_5 ) ) {
struct V_13 * V_17 = F_125 ( V_8 -> V_5 . V_127 ) ;
V_125 += V_17 -> V_36 ;
F_111 ( V_17 ) ;
if ( F_33 ( V_128 , & V_8 -> V_12 ) &&
( V_8 -> V_129 < V_125 ) ) {
F_30 ( V_17 -> V_41 ) ;
F_8 ( V_17 -> V_77 , V_8 -> error ) ;
goto V_130;
}
if ( F_122 ( V_8 ) ) {
memcpy ( & V_17 -> V_131 , & V_8 -> V_121 . V_132 , sizeof( V_17 -> V_131 ) ) ;
F_115 ( V_17 , V_8 -> V_116 , & V_101 ,
V_8 -> V_133 ) ;
goto V_127;
}
V_130:
F_97 ( V_17 ) ;
V_127:
F_56 ( V_17 ) ;
F_47 ( V_17 ) ;
F_57 ( V_17 ) ;
}
V_29:
V_8 -> V_134 ( V_8 ) ;
}
unsigned long
F_126 ( struct V_100 * V_101 )
{
return V_101 -> V_105 -> V_106 ;
}
int
F_127 ( struct V_103 * V_135 , struct V_103 * V_104 ,
struct V_100 * V_101 , int V_136 )
{
struct V_13 * V_17 , * V_38 ;
int V_44 = 0 ;
F_105 (req, tmp, src, wb_list) {
if ( ! F_63 ( V_17 ) )
continue;
F_18 ( & V_17 -> V_19 ) ;
if ( F_128 ( V_101 -> V_107 ) )
F_129 ( V_17 , V_38 , V_137 ) ;
F_110 ( V_17 , V_101 ) ;
F_107 ( V_17 , V_104 ) ;
V_44 ++ ;
if ( ( V_44 == V_136 ) && ! V_101 -> V_111 )
break;
}
return V_44 ;
}
int
F_130 ( struct V_20 * V_20 , struct V_103 * V_104 ,
struct V_100 * V_101 )
{
int V_44 = 0 ;
F_21 ( V_101 -> V_107 ) ;
if ( V_101 -> V_105 -> V_106 > 0 ) {
const int V_136 = V_138 ;
V_44 = F_127 ( & V_101 -> V_105 -> V_108 , V_104 ,
V_101 , V_136 ) ;
V_44 += F_131 ( V_20 , V_101 , V_136 - V_44 ) ;
}
F_23 ( V_101 -> V_107 ) ;
return V_44 ;
}
static struct V_13 * F_132 ( struct V_20 * V_20 ,
struct V_16 * V_16 ,
unsigned int V_23 ,
unsigned int V_125 )
{
struct V_13 * V_17 ;
unsigned int V_139 ;
unsigned int V_25 ;
int error ;
if ( ! F_12 ( V_16 ) )
return NULL ;
V_25 = V_23 + V_125 ;
F_21 ( & V_20 -> V_22 ) ;
for (; ; ) {
V_17 = F_11 ( F_22 ( V_20 ) , V_16 ) ;
if ( V_17 == NULL )
goto V_140;
F_17 ( V_17 -> V_18 != V_17 ) ;
F_17 ( V_17 -> V_37 != V_17 ) ;
V_139 = V_17 -> V_71 + V_17 -> V_36 ;
if ( V_23 > V_139
|| V_25 < V_17 -> V_71 )
goto V_141;
if ( F_63 ( V_17 ) )
break;
F_23 ( & V_20 -> V_22 ) ;
error = F_133 ( V_17 ) ;
F_57 ( V_17 ) ;
if ( error != 0 )
goto V_90;
F_21 ( & V_20 -> V_22 ) ;
}
if ( V_23 < V_17 -> V_71 ) {
V_17 -> V_71 = V_23 ;
V_17 -> V_35 = V_23 ;
}
if ( V_25 > V_139 )
V_17 -> V_36 = V_25 - V_17 -> V_71 ;
else
V_17 -> V_36 = V_139 - V_17 -> V_71 ;
V_140:
if ( V_17 )
F_64 ( V_17 ) ;
F_23 ( & V_20 -> V_22 ) ;
return V_17 ;
V_141:
F_23 ( & V_20 -> V_22 ) ;
F_57 ( V_17 ) ;
error = F_134 ( V_20 , V_16 ) ;
V_90:
return F_62 ( error ) ;
}
static struct V_13 * F_135 ( struct V_9 * V_10 ,
struct V_16 * V_16 , unsigned int V_23 , unsigned int V_125 )
{
struct V_20 * V_20 = F_20 ( V_16 ) -> V_21 ;
struct V_13 * V_17 ;
V_17 = F_132 ( V_20 , V_16 , V_23 , V_125 ) ;
if ( V_17 != NULL )
goto V_29;
V_17 = F_136 ( V_10 , V_16 , NULL , V_23 , V_125 ) ;
if ( F_70 ( V_17 ) )
goto V_29;
F_90 ( V_20 , V_17 ) ;
V_29:
return V_17 ;
}
static int F_137 ( struct V_9 * V_10 , struct V_16 * V_16 ,
unsigned int V_23 , unsigned int V_24 )
{
struct V_13 * V_17 ;
V_17 = F_135 ( V_10 , V_16 , V_23 , V_24 ) ;
if ( F_70 ( V_17 ) )
return F_69 ( V_17 ) ;
F_24 ( V_16 , V_23 , V_24 ) ;
F_38 ( V_17 ) ;
F_101 ( V_17 ) ;
F_138 ( V_17 ) ;
return 0 ;
}
int F_139 ( struct V_142 * V_142 , struct V_16 * V_16 )
{
struct V_9 * V_10 = F_140 ( V_142 ) ;
struct V_143 * V_144 ;
struct V_145 * V_146 = F_141 ( V_142 ) -> V_147 ;
struct V_13 * V_17 ;
int V_148 , V_149 ;
do {
V_17 = F_19 ( V_16 ) ;
if ( V_17 == NULL )
return 0 ;
V_144 = V_17 -> V_150 ;
V_148 = V_17 -> V_41 != V_16 ||
! F_142 ( V_17 -> V_77 , V_10 ) ;
V_148 |= V_17 -> V_37 != V_17 ;
if ( V_144 && V_146 &&
! ( F_143 ( & V_146 -> V_151 ) &&
F_143 ( & V_146 -> V_152 ) ) ) {
V_148 |= V_144 -> V_153 . V_154 != V_155 -> V_156
|| V_144 -> V_153 . V_157 != V_155 -> V_158 ;
}
F_57 ( V_17 ) ;
if ( ! V_148 )
return 0 ;
V_149 = F_134 ( F_20 ( V_16 ) -> V_21 , V_16 ) ;
} while ( V_149 == 0 );
return V_149 ;
}
int
F_144 ( struct V_142 * V_159 , struct V_20 * V_20 )
{
struct V_9 * V_10 = F_140 ( V_159 ) ;
struct V_160 * V_161 = F_43 ( V_20 ) -> V_162 -> V_163 ;
return F_145 ( V_161 , V_10 -> V_164 ) ;
}
bool F_146 ( struct V_9 * V_10 )
{
return F_147 ( V_10 -> V_164 ) ;
}
static bool F_148 ( struct V_16 * V_16 , struct V_20 * V_20 )
{
struct V_14 * V_15 = F_22 ( V_20 ) ;
if ( F_149 ( V_20 ) )
goto V_29;
if ( V_15 -> V_165 & V_166 )
return false ;
F_150 () ;
if ( F_33 ( V_167 , & V_15 -> V_12 ) )
return false ;
V_29:
if ( V_15 -> V_165 & V_168 )
return false ;
return F_39 ( V_16 ) != 0 ;
}
static bool
F_151 ( struct V_169 * V_170 )
{
return V_170 -> V_171 == 0 && V_170 -> V_172 == V_173 &&
V_170 -> V_174 == V_175 ;
}
static int F_152 ( struct V_142 * V_142 , struct V_16 * V_16 , struct V_20 * V_20 )
{
int V_44 ;
struct V_145 * V_146 = V_20 -> V_147 ;
struct V_169 * V_170 ;
if ( V_142 -> V_176 & V_177 )
return 0 ;
if ( ! F_148 ( V_16 , V_20 ) )
return 0 ;
if ( F_91 ( V_20 ) -> F_92 ( V_20 , V_93 ) )
return 1 ;
if ( ! V_146 || ( F_143 ( & V_146 -> V_152 ) &&
F_143 ( & V_146 -> V_151 ) ) )
return 1 ;
V_44 = 0 ;
F_21 ( & V_146 -> V_178 ) ;
if ( ! F_124 ( & V_146 -> V_151 ) ) {
V_170 = F_153 ( & V_146 -> V_151 , struct V_169 ,
V_179 ) ;
if ( F_151 ( V_170 ) )
V_44 = 1 ;
} else if ( ! F_124 ( & V_146 -> V_152 ) ) {
V_170 = F_153 ( & V_146 -> V_152 , struct V_169 ,
V_179 ) ;
if ( V_170 -> V_174 == V_175 )
V_44 = 1 ;
}
F_23 ( & V_146 -> V_178 ) ;
return V_44 ;
}
int F_154 ( struct V_142 * V_142 , struct V_16 * V_16 ,
unsigned int V_23 , unsigned int V_24 )
{
struct V_9 * V_10 = F_140 ( V_142 ) ;
struct V_20 * V_20 = F_20 ( V_16 ) -> V_21 ;
int V_149 = 0 ;
F_29 ( V_20 , V_180 ) ;
F_155 ( L_1 ,
V_142 , V_24 , ( long long ) ( F_27 ( V_16 ) + V_23 ) ) ;
if ( F_152 ( V_142 , V_16 , V_20 ) ) {
V_24 = V_136 ( V_24 + V_23 , F_35 ( V_16 ) ) ;
V_23 = 0 ;
}
V_149 = F_137 ( V_10 , V_16 , V_23 , V_24 ) ;
if ( V_149 < 0 )
F_30 ( V_16 ) ;
else
F_102 ( V_16 ) ;
F_155 ( L_2 ,
V_149 , ( long long ) F_25 ( V_20 ) ) ;
return V_149 ;
}
static int F_156 ( int V_181 )
{
switch ( V_181 & ( V_46 | V_182 ) ) {
case V_46 :
return V_183 ;
case V_182 :
return V_184 ;
}
return V_185 ;
}
static void F_157 ( struct V_6 * V_8 ,
struct V_186 * V_187 ,
const struct V_188 * V_189 ,
struct V_190 * V_191 , int V_181 )
{
int V_192 = F_156 ( V_181 ) ;
V_191 -> V_192 = V_192 ;
V_189 -> V_193 ( V_8 , V_187 ) ;
F_158 ( F_43 ( V_8 -> V_20 ) -> V_194 ,
& V_191 -> V_195 , V_187 , V_8 ) ;
}
static void F_73 ( struct V_13 * V_17 )
{
F_101 ( V_17 ) ;
F_10 ( V_196 , & V_17 -> V_77 -> V_12 ) ;
F_56 ( V_17 ) ;
F_47 ( V_17 ) ;
F_57 ( V_17 ) ;
}
static void F_159 ( struct V_103 * V_31 )
{
struct V_13 * V_17 ;
while ( ! F_124 ( V_31 ) ) {
V_17 = F_125 ( V_31 -> V_127 ) ;
F_111 ( V_17 ) ;
F_73 ( V_17 ) ;
}
}
static void F_160 ( struct V_6 * V_8 )
{
F_159 ( & V_8 -> V_5 ) ;
}
void F_79 ( struct V_73 * V_74 ,
struct V_20 * V_20 , int V_197 , bool V_198 ,
const struct V_199 * V_200 )
{
struct V_50 * V_201 = F_43 ( V_20 ) ;
const struct V_202 * V_203 = & V_204 ;
#ifdef F_161
if ( V_201 -> V_205 && ! V_198 )
V_203 = V_201 -> V_205 -> V_206 ;
#endif
F_162 ( V_74 , V_20 , V_203 , V_200 , & V_207 ,
V_201 -> V_208 , V_197 ) ;
}
void F_163 ( struct V_73 * V_74 )
{
struct V_209 * V_210 ;
if ( V_74 -> V_203 && V_74 -> V_203 -> V_211 )
V_74 -> V_203 -> V_211 ( V_74 ) ;
V_74 -> V_203 = & V_204 ;
F_164 ( V_74 ) ;
V_210 = & V_74 -> V_212 [ 0 ] ;
V_210 -> V_213 = F_43 ( V_74 -> V_214 ) -> V_208 ;
}
void F_165 ( struct V_215 * V_216 , void * V_217 )
{
struct V_1 * V_83 = V_217 ;
F_91 ( V_83 -> V_20 ) -> F_166 ( V_216 , V_83 ) ;
}
static int F_167 ( const struct V_20 * V_20 )
{
T_4 V_218 = V_20 -> V_219 ;
int V_220 = 0 ;
if ( F_14 ( V_218 & V_221 ) )
V_220 = V_222 ;
if ( F_14 ( ( V_218 & V_223 ) && ( V_218 & V_224 ) ) )
V_220 |= V_225 ;
if ( F_14 ( V_220 && F_168 ( V_218 ) ) )
return V_220 ;
return 0 ;
}
static void F_169 ( struct V_6 * V_8 ,
struct V_226 * V_227 )
{
struct V_228 * V_229 = & V_8 -> args ;
struct V_230 * V_231 = & V_8 -> V_232 ;
T_5 V_233 = V_229 -> V_23 + V_231 -> V_24 ;
if ( ! ( V_227 -> V_234 & V_235 ) )
V_227 -> V_233 = V_233 ;
if ( F_170 ( V_227 -> V_233 ) < F_25 ( V_8 -> V_20 ) ) {
V_227 -> V_234 &= ~ V_235 ;
return;
}
if ( V_233 != V_227 -> V_233 )
return;
F_171 ( V_227 ) ;
V_227 -> V_234 |= V_235 ;
}
void F_172 ( struct V_6 * V_8 )
{
struct V_226 * V_227 = & V_8 -> V_227 ;
struct V_20 * V_20 = V_8 -> V_20 ;
F_21 ( & V_20 -> V_22 ) ;
F_169 ( V_8 , V_227 ) ;
F_173 ( V_20 , V_227 ) ;
F_23 ( & V_20 -> V_22 ) ;
}
static int F_174 ( struct V_215 * V_216 ,
struct V_6 * V_8 ,
struct V_20 * V_20 )
{
int V_149 ;
V_149 = F_91 ( V_20 ) -> F_175 ( V_216 , V_8 ) ;
if ( V_149 != 0 )
return V_149 ;
F_74 ( V_20 , V_236 , V_8 -> V_232 . V_24 ) ;
if ( V_8 -> V_232 . V_121 -> V_122 < V_8 -> args . V_237 &&
V_216 -> V_238 >= 0 ) {
static unsigned long V_239 ;
if ( F_176 ( V_239 , V_240 ) ) {
F_155 ( L_3
L_4 ,
F_43 ( V_20 ) -> V_194 -> V_241 ,
V_8 -> V_232 . V_121 -> V_122 , V_8 -> args . V_237 ) ;
V_239 = V_240 + 300 * V_242 ;
}
}
if ( F_167 ( V_20 ) )
F_177 ( V_20 ) ;
return 0 ;
}
static void F_178 ( struct V_215 * V_216 ,
struct V_6 * V_8 )
{
struct V_228 * V_229 = & V_8 -> args ;
struct V_230 * V_231 = & V_8 -> V_232 ;
if ( V_231 -> V_24 < V_229 -> V_24 ) {
static unsigned long V_239 ;
F_29 ( V_8 -> V_20 , V_243 ) ;
if ( V_231 -> V_24 == 0 ) {
if ( F_176 ( V_239 , V_240 ) ) {
F_179 ( V_244
L_5 ,
V_229 -> V_24 ) ;
V_239 = V_240 + 300 * V_242 ;
}
F_180 ( V_8 , - V_72 , V_229 -> V_23 ) ;
V_216 -> V_238 = - V_72 ;
return;
}
if ( ! V_216 -> V_245 ) {
V_8 -> V_246 = - V_70 ;
return;
}
if ( V_231 -> V_121 -> V_122 != V_247 ) {
V_8 -> V_248 += V_231 -> V_24 ;
V_229 -> V_23 += V_231 -> V_24 ;
V_229 -> V_249 += V_231 -> V_24 ;
V_229 -> V_24 -= V_231 -> V_24 ;
} else {
V_229 -> V_237 = V_124 ;
}
F_181 ( V_216 ) ;
}
}
static int F_182 ( struct V_250 * V_101 )
{
return F_183 ( & V_101 -> V_251 ,
V_252 , V_89 ) ;
}
static void F_184 ( struct V_250 * V_101 )
{
F_185 ( & V_101 -> V_251 ) ;
}
static void F_186 ( struct V_250 * V_101 )
{
if ( F_187 ( & V_101 -> V_251 ) )
F_188 ( & V_101 -> V_251 ) ;
}
void F_189 ( struct V_1 * V_83 )
{
F_190 ( V_83 -> V_253 ) ;
F_4 ( V_83 ) ;
}
int F_191 ( struct V_254 * V_255 , struct V_1 * V_83 ,
const struct V_188 * V_256 ,
const struct V_257 * V_258 ,
int V_181 , int V_12 )
{
struct V_215 * V_216 ;
int V_192 = F_156 ( V_181 ) ;
struct V_186 V_187 = {
. V_259 = & V_83 -> args ,
. V_260 = & V_83 -> V_232 ,
. V_261 = V_83 -> V_164 ,
} ;
struct V_190 V_191 = {
. V_216 = & V_83 -> V_216 ,
. V_195 = V_255 ,
. V_186 = & V_187 ,
. V_262 = V_258 ,
. V_263 = V_83 ,
. V_264 = V_265 ,
. V_12 = V_266 | V_12 ,
. V_192 = V_192 ,
} ;
V_256 -> V_267 ( V_83 , & V_187 ) ;
F_155 ( L_6 ) ;
F_192 ( F_43 ( V_83 -> V_20 ) -> V_194 ,
V_268 , & V_191 . V_195 , & V_187 ) ;
V_216 = F_193 ( & V_191 ) ;
if ( F_70 ( V_216 ) )
return F_69 ( V_216 ) ;
if ( V_181 & V_269 )
F_194 ( V_216 ) ;
F_195 ( V_216 ) ;
return 0 ;
}
static T_1 F_196 ( struct V_103 * V_31 )
{
T_1 V_270 = 0 ;
struct V_13 * V_17 ;
F_197 (req, head, wb_list)
if ( V_270 < ( F_198 ( V_17 ) + V_17 -> V_36 ) )
V_270 = F_198 ( V_17 ) + V_17 -> V_36 ;
return V_270 ;
}
void F_199 ( struct V_1 * V_83 ,
struct V_103 * V_31 ,
struct V_115 * V_116 ,
struct V_100 * V_101 )
{
struct V_13 * V_271 = F_125 ( V_31 -> V_127 ) ;
struct V_20 * V_20 = F_98 ( V_271 -> V_77 -> V_96 ) ;
F_200 ( V_31 , & V_83 -> V_5 ) ;
V_83 -> V_20 = V_20 ;
V_83 -> V_164 = V_271 -> V_77 -> V_164 ;
V_83 -> V_116 = V_116 ;
if ( V_116 )
V_83 -> V_270 = F_196 ( & V_83 -> V_5 ) ;
V_83 -> V_272 = & V_273 ;
V_83 -> V_112 = V_101 -> V_112 ;
V_83 -> V_111 = V_101 -> V_111 ;
V_83 -> args . V_274 = F_201 ( V_83 -> V_20 ) ;
V_83 -> args . V_23 = 0 ;
V_83 -> args . V_24 = 0 ;
V_83 -> V_253 = F_202 ( V_271 -> V_77 ) ;
V_83 -> V_232 . V_227 = & V_83 -> V_227 ;
V_83 -> V_232 . V_121 = & V_83 -> V_121 ;
F_203 ( & V_83 -> V_227 ) ;
}
void F_204 ( struct V_103 * V_275 ,
struct V_115 * V_116 ,
struct V_100 * V_101 ,
T_3 V_117 )
{
struct V_13 * V_17 ;
while ( ! F_124 ( V_275 ) ) {
V_17 = F_125 ( V_275 -> V_127 ) ;
F_111 ( V_17 ) ;
F_115 ( V_17 , V_116 , V_101 , V_117 ) ;
if ( ! V_101 -> V_111 )
F_117 ( V_17 -> V_41 ) ;
F_138 ( V_17 ) ;
}
}
static void
F_205 ( struct V_100 * V_101 ,
struct V_13 * V_17 )
{
F_102 ( V_17 -> V_41 ) ;
}
static int
F_206 ( struct V_20 * V_20 , struct V_103 * V_31 , int V_181 ,
struct V_100 * V_101 )
{
struct V_1 * V_83 ;
V_83 = F_1 () ;
if ( ! V_83 )
goto V_276;
F_199 ( V_83 , V_31 , NULL , V_101 ) ;
F_185 ( & V_101 -> V_105 -> V_251 ) ;
return F_191 ( F_207 ( V_20 ) , V_83 , F_91 ( V_20 ) ,
V_83 -> V_272 , V_181 , 0 ) ;
V_276:
F_204 ( V_31 , NULL , V_101 , 0 ) ;
return - V_277 ;
}
static void F_208 ( struct V_215 * V_216 , void * V_217 )
{
struct V_1 * V_83 = V_217 ;
F_155 ( L_7 ,
V_216 -> V_278 , V_216 -> V_238 ) ;
F_91 ( V_83 -> V_20 ) -> F_209 ( V_216 , V_83 ) ;
}
static void F_210 ( struct V_1 * V_83 )
{
struct V_13 * V_17 ;
int V_149 = V_83 -> V_216 . V_238 ;
struct V_100 V_101 ;
struct V_50 * V_51 ;
while ( ! F_124 ( & V_83 -> V_5 ) ) {
V_17 = F_125 ( V_83 -> V_5 . V_127 ) ;
F_111 ( V_17 ) ;
F_117 ( V_17 -> V_41 ) ;
F_155 ( L_8 ,
V_17 -> V_77 -> V_96 -> V_279 -> V_280 ,
( unsigned long long ) F_211 ( F_98 ( V_17 -> V_77 -> V_96 ) ) ,
V_17 -> V_36 ,
( long long ) F_198 ( V_17 ) ) ;
if ( V_149 < 0 ) {
F_8 ( V_17 -> V_77 , V_149 ) ;
F_97 ( V_17 ) ;
F_155 ( L_9 , V_149 ) ;
goto V_127;
}
if ( ! memcmp ( & V_17 -> V_131 , & V_83 -> V_121 . V_132 , sizeof( V_17 -> V_131 ) ) ) {
F_97 ( V_17 ) ;
F_155 ( L_10 ) ;
goto V_127;
}
F_155 ( L_11 ) ;
F_101 ( V_17 ) ;
F_10 ( V_196 , & V_17 -> V_77 -> V_12 ) ;
V_127:
F_138 ( V_17 ) ;
}
V_51 = F_43 ( V_83 -> V_20 ) ;
if ( F_212 ( & V_51 -> V_52 ) < V_57 )
F_51 ( & V_51 -> V_54 , V_55 ) ;
F_113 ( & V_101 , V_83 -> V_20 , V_83 -> V_111 ) ;
F_186 ( V_101 . V_105 ) ;
}
static void F_213 ( void * V_217 )
{
struct V_1 * V_83 = V_217 ;
V_83 -> V_112 -> V_281 ( V_83 ) ;
F_189 ( V_217 ) ;
}
int F_214 ( struct V_20 * V_20 , struct V_103 * V_31 ,
int V_181 , struct V_100 * V_101 )
{
int V_149 ;
V_149 = F_215 ( V_20 , V_31 , V_181 , V_101 ) ;
if ( V_149 == V_282 )
V_149 = F_206 ( V_20 , V_31 , V_181 , V_101 ) ;
return V_149 ;
}
int F_216 ( struct V_20 * V_20 , int V_181 )
{
F_217 ( V_31 ) ;
struct V_100 V_101 ;
int V_283 = V_181 & V_269 ;
int error = 0 ;
int V_232 ;
F_103 ( & V_101 , V_20 ) ;
F_184 ( V_101 . V_105 ) ;
V_232 = F_130 ( V_20 , & V_31 , & V_101 ) ;
if ( V_232 )
error = F_214 ( V_20 , & V_31 , V_181 , & V_101 ) ;
F_186 ( V_101 . V_105 ) ;
if ( error < 0 )
goto V_284;
if ( ! V_283 )
goto V_285;
error = F_182 ( V_101 . V_105 ) ;
if ( error < 0 )
return error ;
return V_232 ;
V_284:
V_232 = error ;
V_285:
F_218 ( V_20 , V_286 ) ;
return V_232 ;
}
int F_219 ( struct V_20 * V_20 , struct V_42 * V_43 )
{
struct V_14 * V_15 = F_22 ( V_20 ) ;
int V_12 = V_269 ;
int V_44 = 0 ;
if ( ! V_15 -> V_109 . V_106 )
return V_44 ;
if ( V_43 -> V_48 == V_79 ) {
if ( V_15 -> V_109 . V_106 <= ( V_15 -> V_92 >> 1 ) )
goto V_285;
V_12 = 0 ;
}
V_44 = F_216 ( V_20 , V_12 ) ;
if ( V_44 >= 0 ) {
if ( V_43 -> V_48 == V_79 ) {
if ( V_44 < V_43 -> V_287 )
V_43 -> V_287 -= V_44 ;
else
V_43 -> V_287 = 0 ;
}
return 0 ;
}
V_285:
F_218 ( V_20 , V_286 ) ;
return V_44 ;
}
int F_220 ( struct V_20 * V_20 )
{
int V_44 ;
F_221 ( V_20 ) ;
V_44 = F_222 ( V_20 -> V_288 ) ;
if ( V_44 )
goto V_29;
V_44 = F_216 ( V_20 , V_269 ) ;
if ( V_44 < 0 )
goto V_29;
F_223 ( V_20 , true ) ;
V_44 = 0 ;
V_29:
F_224 ( V_20 , V_44 ) ;
return V_44 ;
}
int F_225 ( struct V_20 * V_20 , struct V_16 * V_16 )
{
struct V_13 * V_17 ;
int V_44 = 0 ;
F_226 ( V_16 ) ;
V_17 = F_60 ( V_16 , false ) ;
if ( F_70 ( V_17 ) ) {
V_44 = F_69 ( V_17 ) ;
} else if ( V_17 ) {
F_97 ( V_17 ) ;
F_138 ( V_17 ) ;
}
return V_44 ;
}
int F_227 ( struct V_20 * V_20 , struct V_16 * V_16 , bool V_75 )
{
T_1 V_289 = F_27 ( V_16 ) ;
T_1 V_290 = V_289 + ( T_1 ) ( V_291 - 1 ) ;
struct V_42 V_43 = {
. V_48 = V_49 ,
. V_287 = 0 ,
. V_289 = V_289 ,
. V_290 = V_290 ,
} ;
int V_44 ;
F_228 ( V_20 ) ;
for (; ; ) {
F_226 ( V_16 ) ;
if ( F_229 ( V_16 ) ) {
V_44 = F_78 ( V_16 , & V_43 , V_75 ) ;
if ( V_44 < 0 )
goto V_284;
continue;
}
V_44 = 0 ;
if ( ! F_12 ( V_16 ) )
break;
V_44 = F_216 ( V_20 , V_269 ) ;
if ( V_44 < 0 )
goto V_284;
}
V_284:
F_230 ( V_20 , V_44 ) ;
return V_44 ;
}
int F_231 ( struct V_84 * V_85 , struct V_16 * V_292 ,
struct V_16 * V_16 , enum V_293 V_218 )
{
if ( F_12 ( V_16 ) )
return - V_294 ;
if ( ! F_232 ( V_16 , V_295 ) )
return - V_294 ;
return F_233 ( V_85 , V_292 , V_16 , V_218 ) ;
}
int T_6 F_234 ( void )
{
V_296 = F_235 ( L_12 ,
sizeof( struct V_6 ) ,
0 , V_297 ,
NULL ) ;
if ( V_296 == NULL )
return - V_277 ;
V_7 = F_236 ( V_298 ,
V_296 ) ;
if ( V_7 == NULL )
goto V_299;
V_300 = F_235 ( L_13 ,
sizeof( struct V_1 ) ,
0 , V_297 ,
NULL ) ;
if ( V_300 == NULL )
goto V_301;
V_3 = F_236 ( V_302 ,
V_300 ) ;
if ( V_3 == NULL )
goto V_303;
V_304 = ( 16 * F_237 ( V_305 ) ) << ( V_28 - 10 ) ;
if ( V_304 > 256 * 1024 )
V_304 = 256 * 1024 ;
return 0 ;
V_303:
F_238 ( V_300 ) ;
V_301:
F_239 ( V_7 ) ;
V_299:
F_238 ( V_296 ) ;
return - V_277 ;
}
void F_240 ( void )
{
F_239 ( V_3 ) ;
F_238 ( V_300 ) ;
F_239 ( V_7 ) ;
F_238 ( V_296 ) ;
}
