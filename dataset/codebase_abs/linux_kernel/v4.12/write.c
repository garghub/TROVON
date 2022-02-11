struct V_1 * F_1 ( bool V_2 )
{
struct V_1 * V_3 ;
if ( V_2 )
V_3 = F_2 ( V_4 , V_5 ) ;
else {
V_3 = F_2 ( V_4 , V_6 ) ;
if ( ! V_3 )
V_3 = F_3 ( V_7 , V_5 |
V_8 | V_9 ) ;
if ( ! V_3 )
return NULL ;
}
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
F_4 ( & V_3 -> V_10 ) ;
return V_3 ;
}
void F_5 ( struct V_1 * V_3 )
{
F_6 ( V_3 , V_4 ) ;
}
static struct V_11 * F_7 ( void )
{
struct V_11 * V_3 = F_2 ( V_12 , V_5 ) ;
if ( V_3 ) {
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_13 = V_14 ;
}
return V_3 ;
}
static void F_8 ( struct V_11 * V_15 )
{
F_6 ( V_15 , V_12 ) ;
}
static void F_9 ( struct V_16 * V_17 , int error )
{
V_17 -> error = error ;
F_10 () ;
F_11 ( V_18 , & V_17 -> V_19 ) ;
}
static struct V_20 *
F_12 ( struct V_21 * V_22 , struct V_23 * V_23 )
{
struct V_20 * V_24 = NULL ;
if ( F_13 ( V_23 ) )
V_24 = (struct V_20 * ) F_14 ( V_23 ) ;
else if ( F_15 ( F_16 ( V_23 ) ) )
V_24 = F_17 ( V_22 ,
V_23 ) ;
if ( V_24 ) {
F_18 ( V_24 -> V_25 != V_24 ) ;
F_19 ( & V_24 -> V_26 ) ;
}
return V_24 ;
}
static struct V_20 * F_20 ( struct V_23 * V_23 )
{
struct V_27 * V_27 = F_21 ( V_23 ) -> V_28 ;
struct V_20 * V_24 = NULL ;
F_22 ( & V_27 -> V_29 ) ;
V_24 = F_12 ( F_23 ( V_27 ) , V_23 ) ;
F_24 ( & V_27 -> V_29 ) ;
return V_24 ;
}
static void F_25 ( struct V_23 * V_23 , unsigned int V_30 , unsigned int V_31 )
{
struct V_27 * V_27 = F_21 ( V_23 ) -> V_28 ;
T_1 V_32 , V_33 ;
T_2 V_34 ;
F_22 ( & V_27 -> V_29 ) ;
V_33 = F_26 ( V_27 ) ;
V_34 = ( V_33 - 1 ) >> V_35 ;
if ( V_33 > 0 && F_27 ( V_23 ) < V_34 )
goto V_36;
V_32 = F_28 ( V_23 ) + ( ( T_1 ) V_30 + V_31 ) ;
if ( V_33 >= V_32 )
goto V_36;
F_29 ( V_27 , V_32 ) ;
F_30 ( V_27 , V_37 ) ;
V_36:
F_24 ( & V_27 -> V_29 ) ;
}
static void F_31 ( struct V_23 * V_23 )
{
F_32 ( F_21 ( V_23 ) -> V_28 , F_21 ( V_23 ) ) ;
}
static struct V_20 *
F_33 ( struct V_20 * V_38 , unsigned int V_39 )
{
struct V_20 * V_24 ;
F_18 ( V_38 != V_38 -> V_25 ) ;
F_18 ( ! F_34 ( V_40 , & V_38 -> V_25 -> V_41 ) ) ;
V_24 = V_38 ;
do {
if ( V_39 >= V_24 -> V_42 &&
V_39 < ( V_24 -> V_42 + V_24 -> V_43 ) )
return V_24 ;
V_24 = V_24 -> V_44 ;
} while ( V_24 != V_38 );
return NULL ;
}
static bool F_35 ( struct V_20 * V_24 )
{
struct V_20 * V_45 ;
unsigned int V_46 = 0 ;
unsigned int V_47 = F_36 ( V_24 -> V_48 ) ;
F_37 ( V_24 , false ) ;
do {
V_45 = F_33 ( V_24 -> V_25 , V_46 ) ;
if ( V_45 ) {
F_18 ( V_45 -> V_42 != V_46 ) ;
V_46 += V_45 -> V_43 - ( V_46 - V_45 -> V_42 ) ;
}
} while ( V_45 && V_46 < V_47 );
F_38 ( V_24 ) ;
F_18 ( V_46 > V_47 ) ;
return V_46 == V_47 ;
}
static void F_39 ( struct V_20 * V_24 )
{
if ( F_40 ( V_24 -> V_48 ) )
return;
if ( ! F_35 ( V_24 ) )
return;
F_41 ( V_24 -> V_48 ) ;
}
static int F_42 ( struct V_49 * V_50 )
{
int V_51 = 0 ;
if ( V_50 -> V_52 == V_53 )
V_51 = V_54 ;
return V_51 ;
}
static void F_43 ( struct V_23 * V_23 )
{
struct V_27 * V_27 = F_21 ( V_23 ) -> V_28 ;
struct V_55 * V_56 = F_44 ( V_27 ) ;
int V_51 = F_45 ( V_23 ) ;
F_18 ( V_51 != 0 ) ;
if ( F_46 ( & V_56 -> V_57 ) >
V_58 )
F_47 ( F_48 ( V_27 ) , V_59 ) ;
}
static void F_49 ( struct V_20 * V_24 )
{
struct V_27 * V_27 = F_21 ( V_24 -> V_48 ) -> V_28 ;
struct V_55 * V_56 = F_44 ( V_27 ) ;
if ( ! F_50 ( V_24 , V_60 ) )
return;
F_51 ( V_24 -> V_48 ) ;
if ( F_52 ( & V_56 -> V_57 ) < V_61 )
F_53 ( F_48 ( V_27 ) , V_59 ) ;
}
static void
F_54 ( struct V_20 * V_24 )
{
F_55 ( V_62 , & V_24 -> V_41 ) ;
F_55 ( V_63 , & V_24 -> V_41 ) ;
F_55 ( V_64 , & V_24 -> V_41 ) ;
F_55 ( V_60 , & V_24 -> V_41 ) ;
F_55 ( V_65 , & V_24 -> V_41 ) ;
}
static int
F_56 ( struct V_27 * V_27 , struct V_20 * V_38 ,
struct V_20 * V_24 , bool V_66 )
__releases( &inode->i_lock
static void
F_57 ( struct V_20 * V_67 ,
struct V_20 * V_68 )
{
while ( V_67 ) {
struct V_20 * V_69 = V_67 ;
V_67 = ( V_69 -> V_44 == V_68 ) ?
NULL : V_69 -> V_44 ;
F_18 ( V_68 != V_69 -> V_25 ) ;
V_69 -> V_25 = V_69 ;
V_69 -> V_44 = V_69 ;
F_58 ( V_69 ) ;
if ( ! F_34 ( V_62 , & V_69 -> V_41 ) ) {
F_59 ( V_68 ) ;
F_54 ( V_69 ) ;
if ( F_60 ( V_70 , & V_69 -> V_41 ) )
F_59 ( V_69 ) ;
else
F_18 ( 1 ) ;
} else {
F_18 ( F_34 ( V_71 , & V_69 -> V_41 ) ) ;
F_54 ( V_69 ) ;
F_61 ( V_69 ) ;
}
}
}
static struct V_20 *
F_62 ( struct V_23 * V_23 , bool V_66 )
{
struct V_27 * V_27 = F_21 ( V_23 ) -> V_28 ;
struct V_20 * V_38 , * V_69 ;
struct V_20 * V_67 = NULL ;
unsigned int V_72 ;
int V_51 ;
V_73:
V_72 = 0 ;
F_18 ( V_67 ) ;
F_22 ( & V_27 -> V_29 ) ;
V_38 = F_12 ( F_23 ( V_27 ) , V_23 ) ;
if ( ! V_38 ) {
F_24 ( & V_27 -> V_29 ) ;
return NULL ;
}
V_51 = F_37 ( V_38 , true ) ;
if ( V_51 < 0 ) {
F_24 ( & V_27 -> V_29 ) ;
if ( ! V_66 && V_51 == - V_74 ) {
F_63 ( V_38 ) ;
F_59 ( V_38 ) ;
goto V_73;
}
F_59 ( V_38 ) ;
return F_64 ( V_51 ) ;
}
V_69 = V_38 ;
do {
if ( V_69 -> V_75 == ( V_38 -> V_75 + V_72 ) ) {
V_72 += V_69 -> V_43 ;
} else if ( F_18 ( V_69 -> V_75 < V_38 -> V_75 ||
( ( V_69 -> V_75 + V_69 -> V_43 ) >
( V_38 -> V_75 + V_72 ) ) ) ) {
F_38 ( V_38 ) ;
F_24 ( & V_27 -> V_29 ) ;
return F_64 ( - V_76 ) ;
}
if ( ! F_65 ( V_69 ) ) {
V_51 = F_56 ( V_27 , V_38 ,
V_69 , V_66 ) ;
if ( V_51 == 0 )
goto V_73;
return F_64 ( V_51 ) ;
}
V_69 = V_69 -> V_44 ;
} while ( V_69 != V_38 );
V_69 = V_38 ;
do {
F_66 ( V_69 ) ;
V_69 = V_69 -> V_44 ;
} while ( V_69 != V_38 );
if ( V_38 -> V_44 != V_38 ) {
V_67 = V_38 -> V_44 ;
V_38 -> V_44 = V_38 ;
V_38 -> V_43 = V_72 ;
}
F_54 ( V_38 ) ;
if ( ! F_67 ( V_70 , & V_38 -> V_41 ) )
F_19 ( & V_38 -> V_26 ) ;
F_38 ( V_38 ) ;
F_24 ( & V_27 -> V_29 ) ;
F_57 ( V_67 , V_38 ) ;
return V_38 ;
}
static void F_68 ( struct V_20 * V_24 )
{
F_58 ( V_24 ) ;
F_49 ( V_24 ) ;
F_69 ( F_21 ( V_24 -> V_48 ) ,
V_24 -> V_48 ) ;
F_59 ( V_24 ) ;
}
static bool
F_70 ( int V_77 )
{
switch ( V_77 ) {
case 0 :
case - V_78 :
case - V_79 :
return false ;
}
return F_71 ( V_77 ) ;
}
static int F_72 ( struct V_80 * V_81 ,
struct V_23 * V_23 , bool V_66 )
{
struct V_20 * V_24 ;
int V_51 = 0 ;
V_24 = F_62 ( V_23 , V_66 ) ;
if ( ! V_24 )
goto V_36;
V_51 = F_73 ( V_24 ) ;
if ( F_74 ( V_24 ) )
goto V_36;
F_43 ( V_23 ) ;
F_18 ( F_34 ( V_71 , & V_24 -> V_41 ) ) ;
V_51 = 0 ;
if ( F_70 ( V_24 -> V_82 -> error ) )
goto V_83;
if ( ! F_75 ( V_81 , V_24 ) ) {
V_51 = V_81 -> V_84 ;
if ( F_71 ( V_51 ) ) {
F_9 ( V_24 -> V_82 , V_51 ) ;
if ( F_70 ( V_51 ) )
goto V_83;
}
F_76 ( V_24 ) ;
V_51 = - V_74 ;
} else
F_77 ( F_21 ( V_23 ) -> V_28 ,
V_85 , 1 ) ;
V_36:
return V_51 ;
V_83:
F_68 ( V_24 ) ;
return V_51 ;
}
static int F_78 ( struct V_23 * V_23 , struct V_49 * V_50 ,
struct V_80 * V_81 )
{
int V_51 ;
F_79 ( V_81 , F_27 ( V_23 ) ) ;
V_51 = F_72 ( V_81 , V_23 , V_50 -> V_52 == V_86 ) ;
if ( V_51 == - V_74 ) {
F_80 ( V_50 , V_23 ) ;
V_51 = 0 ;
}
return V_51 ;
}
static int F_81 ( struct V_23 * V_23 ,
struct V_49 * V_50 )
{
struct V_80 V_81 ;
struct V_27 * V_27 = F_21 ( V_23 ) -> V_28 ;
int V_77 ;
F_30 ( V_27 , V_87 ) ;
F_82 ( & V_81 , V_27 , 0 ,
false , & V_88 ) ;
V_77 = F_78 ( V_23 , V_50 , & V_81 ) ;
F_83 ( & V_81 ) ;
if ( V_77 < 0 )
return V_77 ;
if ( V_81 . V_84 < 0 )
return V_81 . V_84 ;
return 0 ;
}
int F_84 ( struct V_23 * V_23 , struct V_49 * V_50 )
{
int V_51 ;
V_51 = F_81 ( V_23 , V_50 ) ;
F_85 ( V_23 ) ;
return V_51 ;
}
static int F_86 ( struct V_23 * V_23 , struct V_49 * V_50 , void * V_89 )
{
int V_51 ;
V_51 = F_78 ( V_23 , V_50 , V_89 ) ;
F_85 ( V_23 ) ;
return V_51 ;
}
int F_87 ( struct V_90 * V_91 , struct V_49 * V_50 )
{
struct V_27 * V_27 = V_91 -> V_28 ;
struct V_80 V_81 ;
int V_77 ;
F_30 ( V_27 , V_92 ) ;
F_82 ( & V_81 , V_27 , F_42 ( V_50 ) , false ,
& V_88 ) ;
V_77 = F_88 ( V_91 , V_50 , F_86 , & V_81 ) ;
F_83 ( & V_81 ) ;
if ( V_77 < 0 )
goto V_93;
V_77 = V_81 . V_84 ;
if ( V_77 < 0 )
goto V_93;
return 0 ;
V_93:
return V_77 ;
}
static void F_89 ( struct V_27 * V_27 , struct V_20 * V_24 )
{
struct V_21 * V_22 = F_23 ( V_27 ) ;
F_18 ( V_24 -> V_44 != V_24 ) ;
F_65 ( V_24 ) ;
F_22 ( & V_27 -> V_29 ) ;
if ( ! V_22 -> V_94 &&
F_90 ( V_27 ) -> F_91 ( V_27 , V_14 ) )
V_27 -> V_95 ++ ;
if ( F_92 ( ! F_16 ( V_24 -> V_48 ) ) ) {
F_11 ( V_96 , & V_24 -> V_41 ) ;
F_93 ( V_24 -> V_48 ) ;
F_94 ( V_24 -> V_48 , ( unsigned long ) V_24 ) ;
}
V_22 -> V_94 ++ ;
F_95 ( F_67 ( V_70 , & V_24 -> V_41 ) ) ;
F_19 ( & V_24 -> V_26 ) ;
F_24 ( & V_27 -> V_29 ) ;
}
static void F_96 ( struct V_20 * V_24 )
{
struct V_27 * V_27 = F_97 ( V_24 -> V_82 -> V_97 ) ;
struct V_21 * V_22 = F_23 ( V_27 ) ;
struct V_20 * V_38 ;
if ( F_50 ( V_24 , V_65 ) ) {
V_38 = V_24 -> V_25 ;
F_22 ( & V_27 -> V_29 ) ;
if ( F_92 ( V_38 -> V_48 && ! F_16 ( V_38 -> V_48 ) ) ) {
F_94 ( V_38 -> V_48 , 0 ) ;
F_98 ( V_38 -> V_48 ) ;
F_55 ( V_96 , & V_38 -> V_41 ) ;
}
V_22 -> V_94 -- ;
F_24 ( & V_27 -> V_29 ) ;
} else {
F_22 ( & V_27 -> V_29 ) ;
V_22 -> V_94 -- ;
F_24 ( & V_27 -> V_29 ) ;
}
if ( F_60 ( V_70 , & V_24 -> V_41 ) )
F_59 ( V_24 ) ;
}
static void
F_99 ( struct V_20 * V_24 )
{
if ( V_24 -> V_48 )
F_100 ( V_24 -> V_48 ) ;
}
static struct V_20 *
F_17 ( struct V_21 * V_22 ,
struct V_23 * V_23 )
{
struct V_20 * V_98 , * V_99 ;
struct V_100 V_101 ;
struct V_27 * V_27 = & V_22 -> V_102 ;
F_101 ( & V_101 , V_27 ) ;
V_98 = F_102 ( V_27 , & V_101 , V_23 ) ;
if ( V_98 )
return V_98 -> V_25 ;
F_103 (freq, t, &cinfo.mds->list, wb_list) {
if ( V_98 -> V_48 == V_23 )
return V_98 -> V_25 ;
}
return NULL ;
}
void
F_104 ( struct V_20 * V_24 , struct V_103 * V_104 ,
struct V_100 * V_101 )
{
F_11 ( V_71 , & V_24 -> V_41 ) ;
F_105 ( V_24 , V_104 ) ;
V_101 -> V_105 -> V_106 ++ ;
}
void
F_106 ( struct V_20 * V_24 , struct V_100 * V_101 )
{
F_22 ( & V_101 -> V_27 -> V_29 ) ;
F_104 ( V_24 , & V_101 -> V_105 -> V_107 , V_101 ) ;
F_24 ( & V_101 -> V_27 -> V_29 ) ;
if ( V_24 -> V_48 )
F_107 ( V_24 -> V_48 , V_101 ) ;
}
void
F_108 ( struct V_20 * V_24 ,
struct V_100 * V_101 )
{
if ( ! F_60 ( V_71 , & ( V_24 ) -> V_41 ) )
return;
F_109 ( V_24 ) ;
V_101 -> V_105 -> V_106 -- ;
}
static void F_101 ( struct V_100 * V_101 ,
struct V_27 * V_27 )
{
V_101 -> V_27 = V_27 ;
V_101 -> V_105 = & F_23 ( V_27 ) -> V_108 ;
V_101 -> V_109 = F_110 ( V_27 ) ;
V_101 -> V_110 = NULL ;
V_101 -> V_111 = & V_112 ;
}
void F_111 ( struct V_100 * V_101 ,
struct V_27 * V_27 ,
struct V_113 * V_110 )
{
if ( V_110 )
F_112 ( V_101 , V_110 ) ;
else
F_101 ( V_101 , V_27 ) ;
}
void
F_113 ( struct V_20 * V_24 , struct V_114 * V_115 ,
struct V_100 * V_101 , T_3 V_116 )
{
if ( F_114 ( V_24 , V_115 , V_101 , V_116 ) )
return;
F_106 ( V_24 , V_101 ) ;
}
static void
F_115 ( struct V_23 * V_23 )
{
F_116 ( V_23 , V_117 ) ;
F_117 ( & F_48 ( F_21 ( V_23 ) -> V_28 ) -> V_118 ,
V_119 ) ;
}
static void
F_66 ( struct V_20 * V_24 )
{
if ( F_34 ( V_71 , & V_24 -> V_41 ) ) {
struct V_27 * V_27 = F_97 ( V_24 -> V_82 -> V_97 ) ;
struct V_100 V_101 ;
F_101 ( & V_101 , V_27 ) ;
if ( ! F_118 ( V_24 , & V_101 ) ) {
F_108 ( V_24 , & V_101 ) ;
}
F_115 ( V_24 -> V_48 ) ;
}
}
int F_119 ( struct V_11 * V_15 )
{
if ( V_15 -> V_120 . V_121 == V_122 )
return V_15 -> V_115 == NULL ;
return V_15 -> V_120 . V_121 != V_123 ;
}
static void F_120 ( struct V_11 * V_15 )
{
struct V_100 V_101 ;
unsigned long V_124 = 0 ;
if ( F_34 ( V_125 , & V_15 -> V_19 ) )
goto V_36;
F_101 ( & V_101 , V_15 -> V_27 ) ;
while ( ! F_121 ( & V_15 -> V_10 ) ) {
struct V_20 * V_24 = F_122 ( V_15 -> V_10 . V_126 ) ;
V_124 += V_24 -> V_43 ;
F_109 ( V_24 ) ;
if ( F_34 ( V_127 , & V_15 -> V_19 ) &&
( V_15 -> V_128 < V_124 ) ) {
F_31 ( V_24 -> V_48 ) ;
F_9 ( V_24 -> V_82 , V_15 -> error ) ;
goto V_129;
}
if ( F_119 ( V_15 ) ) {
memcpy ( & V_24 -> V_130 , & V_15 -> V_120 . V_131 , sizeof( V_24 -> V_130 ) ) ;
F_113 ( V_24 , V_15 -> V_115 , & V_101 ,
V_15 -> V_132 ) ;
goto V_126;
}
V_129:
F_96 ( V_24 ) ;
V_126:
F_58 ( V_24 ) ;
F_49 ( V_24 ) ;
F_59 ( V_24 ) ;
}
V_36:
V_15 -> V_133 ( V_15 ) ;
}
unsigned long
F_123 ( struct V_100 * V_101 )
{
return V_101 -> V_105 -> V_106 ;
}
int
F_124 ( struct V_103 * V_134 , struct V_103 * V_104 ,
struct V_100 * V_101 , int V_135 )
{
struct V_20 * V_24 , * V_45 ;
int V_51 = 0 ;
F_103 (req, tmp, src, wb_list) {
if ( ! F_65 ( V_24 ) )
continue;
F_19 ( & V_24 -> V_26 ) ;
if ( F_125 ( & V_101 -> V_27 -> V_29 ) )
F_126 ( V_24 , V_45 , V_136 ) ;
F_108 ( V_24 , V_101 ) ;
F_105 ( V_24 , V_104 ) ;
V_51 ++ ;
if ( ( V_51 == V_135 ) && ! V_101 -> V_110 )
break;
}
return V_51 ;
}
int
F_127 ( struct V_27 * V_27 , struct V_103 * V_104 ,
struct V_100 * V_101 )
{
int V_51 = 0 ;
F_22 ( & V_101 -> V_27 -> V_29 ) ;
if ( V_101 -> V_105 -> V_106 > 0 ) {
const int V_135 = V_137 ;
V_51 = F_124 ( & V_101 -> V_105 -> V_107 , V_104 ,
V_101 , V_135 ) ;
V_51 += F_128 ( V_27 , V_101 , V_135 - V_51 ) ;
}
F_24 ( & V_101 -> V_27 -> V_29 ) ;
return V_51 ;
}
static struct V_20 * F_129 ( struct V_27 * V_27 ,
struct V_23 * V_23 ,
unsigned int V_30 ,
unsigned int V_124 )
{
struct V_20 * V_24 ;
unsigned int V_138 ;
unsigned int V_32 ;
int error ;
if ( ! F_13 ( V_23 ) )
return NULL ;
V_32 = V_30 + V_124 ;
F_22 ( & V_27 -> V_29 ) ;
for (; ; ) {
V_24 = F_12 ( F_23 ( V_27 ) , V_23 ) ;
if ( V_24 == NULL )
goto V_139;
F_18 ( V_24 -> V_25 != V_24 ) ;
F_18 ( V_24 -> V_44 != V_24 ) ;
V_138 = V_24 -> V_75 + V_24 -> V_43 ;
if ( V_30 > V_138
|| V_32 < V_24 -> V_75 )
goto V_140;
if ( F_65 ( V_24 ) )
break;
F_24 ( & V_27 -> V_29 ) ;
error = F_130 ( V_24 ) ;
F_59 ( V_24 ) ;
if ( error != 0 )
goto V_93;
F_22 ( & V_27 -> V_29 ) ;
}
if ( V_30 < V_24 -> V_75 ) {
V_24 -> V_75 = V_30 ;
V_24 -> V_42 = V_30 ;
}
if ( V_32 > V_138 )
V_24 -> V_43 = V_32 - V_24 -> V_75 ;
else
V_24 -> V_43 = V_138 - V_24 -> V_75 ;
V_139:
if ( V_24 )
F_66 ( V_24 ) ;
F_24 ( & V_27 -> V_29 ) ;
return V_24 ;
V_140:
F_24 ( & V_27 -> V_29 ) ;
F_59 ( V_24 ) ;
error = F_131 ( V_27 , V_23 ) ;
V_93:
return F_64 ( error ) ;
}
static struct V_20 * F_132 ( struct V_16 * V_17 ,
struct V_23 * V_23 , unsigned int V_30 , unsigned int V_124 )
{
struct V_27 * V_27 = F_21 ( V_23 ) -> V_28 ;
struct V_20 * V_24 ;
V_24 = F_129 ( V_27 , V_23 , V_30 , V_124 ) ;
if ( V_24 != NULL )
goto V_36;
V_24 = F_133 ( V_17 , V_23 , NULL , V_30 , V_124 ) ;
if ( F_74 ( V_24 ) )
goto V_36;
F_89 ( V_27 , V_24 ) ;
V_36:
return V_24 ;
}
static int F_134 ( struct V_16 * V_17 , struct V_23 * V_23 ,
unsigned int V_30 , unsigned int V_31 )
{
struct V_20 * V_24 ;
V_24 = F_132 ( V_17 , V_23 , V_30 , V_31 ) ;
if ( F_74 ( V_24 ) )
return F_73 ( V_24 ) ;
F_25 ( V_23 , V_30 , V_31 ) ;
F_39 ( V_24 ) ;
F_99 ( V_24 ) ;
F_135 ( V_24 ) ;
return 0 ;
}
int F_136 ( struct V_141 * V_141 , struct V_23 * V_23 )
{
struct V_16 * V_17 = F_137 ( V_141 ) ;
struct V_142 * V_143 ;
struct V_144 * V_145 = F_138 ( V_141 ) -> V_146 ;
struct V_20 * V_24 ;
int V_147 , V_148 ;
do {
V_24 = F_20 ( V_23 ) ;
if ( V_24 == NULL )
return 0 ;
V_143 = V_24 -> V_149 ;
V_147 = V_24 -> V_48 != V_23 ||
! F_139 ( V_24 -> V_82 , V_17 ) ;
V_147 |= V_24 -> V_44 != V_24 ;
if ( V_143 && V_145 &&
! ( F_140 ( & V_145 -> V_150 ) &&
F_140 ( & V_145 -> V_151 ) ) ) {
V_147 |= V_143 -> V_152 != V_153 -> V_154 ;
}
F_59 ( V_24 ) ;
if ( ! V_147 )
return 0 ;
V_148 = F_131 ( F_21 ( V_23 ) -> V_28 , V_23 ) ;
} while ( V_148 == 0 );
return V_148 ;
}
int
F_141 ( struct V_141 * V_155 , struct V_27 * V_27 )
{
struct V_16 * V_17 = F_137 ( V_155 ) ;
struct V_156 * V_157 = F_44 ( V_27 ) -> V_158 -> V_159 ;
return F_142 ( V_157 , V_17 -> V_160 ) ;
}
bool F_143 ( struct V_16 * V_17 , struct V_27 * V_27 )
{
struct V_156 * V_157 = F_44 ( V_27 ) -> V_158 -> V_159 ;
return F_144 ( V_157 , V_17 -> V_160 ) ;
}
static bool F_145 ( struct V_23 * V_23 , struct V_27 * V_27 )
{
struct V_21 * V_22 = F_23 ( V_27 ) ;
if ( F_146 ( V_27 ) )
goto V_36;
if ( V_22 -> V_161 & V_162 )
return false ;
F_147 () ;
if ( F_34 ( V_163 , & V_22 -> V_19 ) )
return false ;
V_36:
if ( V_22 -> V_161 & V_164 )
return false ;
return F_40 ( V_23 ) != 0 ;
}
static bool
F_148 ( struct V_165 * V_166 )
{
return V_166 -> V_167 == 0 && V_166 -> V_168 == V_169 &&
V_166 -> V_170 == V_171 ;
}
static int F_149 ( struct V_141 * V_141 , struct V_23 * V_23 , struct V_27 * V_27 )
{
int V_51 ;
struct V_144 * V_145 = V_27 -> V_146 ;
struct V_165 * V_166 ;
if ( V_141 -> V_172 & V_173 )
return 0 ;
if ( ! F_145 ( V_23 , V_27 ) )
return 0 ;
if ( F_90 ( V_27 ) -> F_91 ( V_27 , V_14 ) )
return 1 ;
if ( ! V_145 || ( F_140 ( & V_145 -> V_151 ) &&
F_140 ( & V_145 -> V_150 ) ) )
return 1 ;
V_51 = 0 ;
F_22 ( & V_145 -> V_174 ) ;
if ( ! F_121 ( & V_145 -> V_150 ) ) {
V_166 = F_150 ( & V_145 -> V_150 , struct V_165 ,
V_175 ) ;
if ( F_148 ( V_166 ) )
V_51 = 1 ;
} else if ( ! F_121 ( & V_145 -> V_151 ) ) {
V_166 = F_150 ( & V_145 -> V_151 , struct V_165 ,
V_175 ) ;
if ( V_166 -> V_170 == V_171 )
V_51 = 1 ;
}
F_24 ( & V_145 -> V_174 ) ;
return V_51 ;
}
int F_151 ( struct V_141 * V_141 , struct V_23 * V_23 ,
unsigned int V_30 , unsigned int V_31 )
{
struct V_16 * V_17 = F_137 ( V_141 ) ;
struct V_27 * V_27 = F_21 ( V_23 ) -> V_28 ;
int V_148 = 0 ;
F_30 ( V_27 , V_176 ) ;
F_152 ( L_1 ,
V_141 , V_31 , ( long long ) ( F_28 ( V_23 ) + V_30 ) ) ;
if ( ! V_31 )
goto V_36;
if ( F_149 ( V_141 , V_23 , V_27 ) ) {
V_31 = V_135 ( V_31 + V_30 , F_36 ( V_23 ) ) ;
V_30 = 0 ;
}
V_148 = F_134 ( V_17 , V_23 , V_30 , V_31 ) ;
if ( V_148 < 0 )
F_31 ( V_23 ) ;
else
F_100 ( V_23 ) ;
V_36:
F_152 ( L_2 ,
V_148 , ( long long ) F_26 ( V_27 ) ) ;
return V_148 ;
}
static int F_153 ( int V_177 )
{
switch ( V_177 & ( V_178 | V_179 ) ) {
case V_178 :
return V_180 ;
case V_179 :
return V_181 ;
}
return V_182 ;
}
static void F_154 ( struct V_11 * V_15 ,
struct V_183 * V_184 ,
const struct V_185 * V_186 ,
struct V_187 * V_188 , int V_177 )
{
int V_189 = F_153 ( V_177 ) ;
V_188 -> V_189 = V_189 ;
V_186 -> V_190 ( V_15 , V_184 ) ;
F_155 ( F_44 ( V_15 -> V_27 ) -> V_191 ,
& V_188 -> V_192 , V_184 , V_15 ) ;
}
static void F_76 ( struct V_20 * V_24 )
{
F_99 ( V_24 ) ;
F_11 ( V_193 , & V_24 -> V_82 -> V_19 ) ;
F_58 ( V_24 ) ;
F_49 ( V_24 ) ;
F_59 ( V_24 ) ;
}
static void F_156 ( struct V_103 * V_38 )
{
struct V_20 * V_24 ;
while ( ! F_121 ( V_38 ) ) {
V_24 = F_122 ( V_38 -> V_126 ) ;
F_109 ( V_24 ) ;
F_76 ( V_24 ) ;
}
}
static void F_157 ( struct V_11 * V_15 )
{
F_156 ( & V_15 -> V_10 ) ;
}
void F_82 ( struct V_80 * V_81 ,
struct V_27 * V_27 , int V_194 , bool V_195 ,
const struct V_196 * V_197 )
{
struct V_55 * V_198 = F_44 ( V_27 ) ;
const struct V_199 * V_200 = & V_201 ;
#ifdef F_158
if ( V_198 -> V_202 && ! V_195 )
V_200 = V_198 -> V_202 -> V_203 ;
#endif
F_159 ( V_81 , V_27 , V_200 , V_197 , & V_204 ,
V_198 -> V_205 , V_194 , V_5 ) ;
}
void F_160 ( struct V_80 * V_81 )
{
struct V_206 * V_207 ;
if ( V_81 -> V_200 && V_81 -> V_200 -> V_208 )
V_81 -> V_200 -> V_208 ( V_81 ) ;
V_81 -> V_200 = & V_201 ;
F_161 ( V_81 ) ;
V_207 = & V_81 -> V_209 [ 0 ] ;
V_207 -> V_210 = F_44 ( V_81 -> V_211 ) -> V_205 ;
}
void F_162 ( struct V_212 * V_213 , void * V_214 )
{
struct V_1 * V_89 = V_214 ;
F_90 ( V_89 -> V_27 ) -> F_163 ( V_213 , V_89 ) ;
}
static int F_164 ( const struct V_27 * V_27 )
{
T_4 V_215 = V_27 -> V_216 ;
int V_217 = 0 ;
if ( F_15 ( V_215 & V_218 ) )
V_217 = V_219 ;
if ( F_15 ( ( V_215 & V_220 ) && ( V_215 & V_221 ) ) )
V_217 |= V_222 ;
if ( F_15 ( V_217 && F_165 ( V_215 ) ) )
return V_217 ;
return 0 ;
}
static void F_166 ( struct V_11 * V_15 ,
struct V_223 * V_224 )
{
struct V_225 * V_226 = & V_15 -> args ;
struct V_227 * V_228 = & V_15 -> V_229 ;
T_5 V_230 = V_226 -> V_30 + V_228 -> V_31 ;
if ( ! ( V_224 -> V_231 & V_232 ) )
V_224 -> V_230 = V_230 ;
if ( F_167 ( V_224 -> V_230 ) < F_26 ( V_15 -> V_27 ) ) {
V_224 -> V_231 &= ~ V_232 ;
return;
}
if ( V_230 != V_224 -> V_230 )
return;
F_168 ( V_224 ) ;
V_224 -> V_231 |= V_232 ;
}
void F_169 ( struct V_11 * V_15 )
{
struct V_223 * V_224 = & V_15 -> V_224 ;
struct V_27 * V_27 = V_15 -> V_27 ;
F_22 ( & V_27 -> V_29 ) ;
F_166 ( V_15 , V_224 ) ;
F_170 ( V_27 , V_224 ) ;
F_24 ( & V_27 -> V_29 ) ;
}
static int F_171 ( struct V_212 * V_213 ,
struct V_11 * V_15 ,
struct V_27 * V_27 )
{
int V_148 ;
V_148 = F_90 ( V_27 ) -> F_172 ( V_213 , V_15 ) ;
if ( V_148 != 0 )
return V_148 ;
F_77 ( V_27 , V_233 , V_15 -> V_229 . V_31 ) ;
if ( V_15 -> V_229 . V_120 -> V_121 < V_15 -> args . V_234 &&
V_213 -> V_235 >= 0 ) {
static unsigned long V_236 ;
if ( F_173 ( V_236 , V_237 ) ) {
F_152 ( L_3
L_4 ,
F_44 ( V_27 ) -> V_191 -> V_238 ,
V_15 -> V_229 . V_120 -> V_121 , V_15 -> args . V_234 ) ;
V_236 = V_237 + 300 * V_239 ;
}
}
if ( F_164 ( V_27 ) )
F_174 ( V_27 ) ;
return 0 ;
}
static void F_175 ( struct V_212 * V_213 ,
struct V_11 * V_15 )
{
struct V_225 * V_226 = & V_15 -> args ;
struct V_227 * V_228 = & V_15 -> V_229 ;
if ( V_228 -> V_31 < V_226 -> V_31 ) {
static unsigned long V_236 ;
F_30 ( V_15 -> V_27 , V_240 ) ;
if ( V_228 -> V_31 == 0 ) {
if ( F_173 ( V_236 , V_237 ) ) {
F_176 ( V_241
L_5 ,
V_226 -> V_31 ) ;
V_236 = V_237 + 300 * V_239 ;
}
F_177 ( V_15 , - V_76 , V_226 -> V_30 ) ;
V_213 -> V_235 = - V_76 ;
return;
}
if ( ! V_213 -> V_242 ) {
V_15 -> V_243 = - V_74 ;
return;
}
if ( V_228 -> V_120 -> V_121 != V_244 ) {
V_15 -> V_245 += V_228 -> V_31 ;
V_226 -> V_30 += V_228 -> V_31 ;
V_226 -> V_246 += V_228 -> V_31 ;
V_226 -> V_31 -= V_228 -> V_31 ;
} else {
V_226 -> V_234 = V_123 ;
}
F_178 ( V_213 ) ;
}
}
static int F_179 ( struct V_247 * V_101 )
{
return F_180 ( & V_101 -> V_248 ,
V_249 , V_250 ) ;
}
static void F_181 ( struct V_247 * V_101 )
{
F_182 ( & V_101 -> V_248 ) ;
}
static void F_183 ( struct V_247 * V_101 )
{
if ( F_184 ( & V_101 -> V_248 ) )
F_185 ( & V_101 -> V_248 ) ;
}
void F_186 ( struct V_1 * V_89 )
{
F_187 ( V_89 -> V_251 ) ;
F_5 ( V_89 ) ;
}
int F_188 ( struct V_252 * V_253 , struct V_1 * V_89 ,
const struct V_185 * V_254 ,
const struct V_255 * V_256 ,
int V_177 , int V_19 )
{
struct V_212 * V_213 ;
int V_189 = F_153 ( V_177 ) ;
struct V_183 V_184 = {
. V_257 = & V_89 -> args ,
. V_258 = & V_89 -> V_229 ,
. V_259 = V_89 -> V_160 ,
} ;
struct V_187 V_188 = {
. V_213 = & V_89 -> V_213 ,
. V_192 = V_253 ,
. V_183 = & V_184 ,
. V_260 = V_256 ,
. V_261 = V_89 ,
. V_262 = V_263 ,
. V_19 = V_264 | V_19 ,
. V_189 = V_189 ,
} ;
V_254 -> V_265 ( V_89 , & V_184 ) ;
F_152 ( L_6 ) ;
F_189 ( F_44 ( V_89 -> V_27 ) -> V_191 ,
V_266 , & V_188 . V_192 , & V_184 ) ;
V_213 = F_190 ( & V_188 ) ;
if ( F_74 ( V_213 ) )
return F_73 ( V_213 ) ;
if ( V_177 & V_267 )
F_191 ( V_213 ) ;
F_192 ( V_213 ) ;
return 0 ;
}
static T_1 F_193 ( struct V_103 * V_38 )
{
T_1 V_268 = 0 ;
struct V_20 * V_24 ;
F_194 (req, head, wb_list)
if ( V_268 < ( F_195 ( V_24 ) + V_24 -> V_43 ) )
V_268 = F_195 ( V_24 ) + V_24 -> V_43 ;
return V_268 ;
}
void F_196 ( struct V_1 * V_89 ,
struct V_103 * V_38 ,
struct V_114 * V_115 ,
struct V_100 * V_101 )
{
struct V_20 * V_269 = F_122 ( V_38 -> V_126 ) ;
struct V_27 * V_27 = F_97 ( V_269 -> V_82 -> V_97 ) ;
F_197 ( V_38 , & V_89 -> V_10 ) ;
V_89 -> V_27 = V_27 ;
V_89 -> V_160 = V_269 -> V_82 -> V_160 ;
V_89 -> V_115 = V_115 ;
if ( V_115 )
V_89 -> V_268 = F_193 ( & V_89 -> V_10 ) ;
V_89 -> V_270 = & V_271 ;
V_89 -> V_111 = V_101 -> V_111 ;
V_89 -> V_110 = V_101 -> V_110 ;
V_89 -> args . V_272 = F_198 ( V_89 -> V_27 ) ;
V_89 -> args . V_30 = 0 ;
V_89 -> args . V_31 = 0 ;
V_89 -> V_251 = F_199 ( V_269 -> V_82 ) ;
V_89 -> V_229 . V_224 = & V_89 -> V_224 ;
V_89 -> V_229 . V_120 = & V_89 -> V_120 ;
F_200 ( & V_89 -> V_224 ) ;
}
void F_201 ( struct V_103 * V_273 ,
struct V_114 * V_115 ,
struct V_100 * V_101 ,
T_3 V_116 )
{
struct V_20 * V_24 ;
while ( ! F_121 ( V_273 ) ) {
V_24 = F_122 ( V_273 -> V_126 ) ;
F_109 ( V_24 ) ;
F_113 ( V_24 , V_115 , V_101 , V_116 ) ;
if ( ! V_101 -> V_110 )
F_115 ( V_24 -> V_48 ) ;
F_135 ( V_24 ) ;
}
}
static void
F_202 ( struct V_100 * V_101 ,
struct V_20 * V_24 )
{
F_100 ( V_24 -> V_48 ) ;
}
static int
F_203 ( struct V_27 * V_27 , struct V_103 * V_38 , int V_177 ,
struct V_100 * V_101 )
{
struct V_1 * V_89 ;
if ( F_121 ( V_38 ) )
return 0 ;
V_89 = F_1 ( true ) ;
F_196 ( V_89 , V_38 , NULL , V_101 ) ;
F_182 ( & V_101 -> V_105 -> V_248 ) ;
return F_188 ( F_204 ( V_27 ) , V_89 , F_90 ( V_27 ) ,
V_89 -> V_270 , V_177 , 0 ) ;
}
static void F_205 ( struct V_212 * V_213 , void * V_214 )
{
struct V_1 * V_89 = V_214 ;
F_152 ( L_7 ,
V_213 -> V_274 , V_213 -> V_235 ) ;
F_90 ( V_89 -> V_27 ) -> F_206 ( V_213 , V_89 ) ;
}
static void F_207 ( struct V_1 * V_89 )
{
struct V_20 * V_24 ;
int V_148 = V_89 -> V_213 . V_235 ;
struct V_100 V_101 ;
struct V_55 * V_56 ;
while ( ! F_121 ( & V_89 -> V_10 ) ) {
V_24 = F_122 ( V_89 -> V_10 . V_126 ) ;
F_109 ( V_24 ) ;
if ( V_24 -> V_48 )
F_115 ( V_24 -> V_48 ) ;
F_152 ( L_8 ,
V_24 -> V_82 -> V_97 -> V_275 -> V_276 ,
( unsigned long long ) F_208 ( F_97 ( V_24 -> V_82 -> V_97 ) ) ,
V_24 -> V_43 ,
( long long ) F_195 ( V_24 ) ) ;
if ( V_148 < 0 ) {
F_9 ( V_24 -> V_82 , V_148 ) ;
if ( V_24 -> V_48 )
F_96 ( V_24 ) ;
F_209 ( L_9 , V_148 ) ;
goto V_126;
}
if ( ! F_210 ( & V_24 -> V_130 , & V_89 -> V_120 . V_131 ) ) {
if ( V_24 -> V_48 )
F_96 ( V_24 ) ;
F_209 ( L_10 ) ;
goto V_126;
}
F_209 ( L_11 ) ;
F_99 ( V_24 ) ;
F_11 ( V_193 , & V_24 -> V_82 -> V_19 ) ;
V_126:
F_135 ( V_24 ) ;
}
V_56 = F_44 ( V_89 -> V_27 ) ;
if ( F_211 ( & V_56 -> V_57 ) < V_61 )
F_53 ( F_48 ( V_89 -> V_27 ) , V_59 ) ;
F_111 ( & V_101 , V_89 -> V_27 , V_89 -> V_110 ) ;
F_183 ( V_101 . V_105 ) ;
}
static void F_212 ( void * V_214 )
{
struct V_1 * V_89 = V_214 ;
V_89 -> V_111 -> V_277 ( V_89 ) ;
F_186 ( V_214 ) ;
}
int F_213 ( struct V_27 * V_27 , struct V_103 * V_38 ,
int V_177 , struct V_100 * V_101 )
{
int V_148 ;
V_148 = F_214 ( V_27 , V_38 , V_177 , V_101 ) ;
if ( V_148 == V_278 )
V_148 = F_203 ( V_27 , V_38 , V_177 , V_101 ) ;
return V_148 ;
}
int F_215 ( struct V_27 * V_27 , int V_177 )
{
F_216 ( V_38 ) ;
struct V_100 V_101 ;
int V_279 = V_177 & V_267 ;
int error = 0 ;
int V_229 ;
F_101 ( & V_101 , V_27 ) ;
F_181 ( V_101 . V_105 ) ;
V_229 = F_127 ( V_27 , & V_38 , & V_101 ) ;
if ( V_229 )
error = F_213 ( V_27 , & V_38 , V_177 , & V_101 ) ;
F_183 ( V_101 . V_105 ) ;
if ( error < 0 )
goto V_280;
if ( ! V_279 )
goto V_281;
error = F_179 ( V_101 . V_105 ) ;
if ( error < 0 )
return error ;
return V_229 ;
V_280:
V_229 = error ;
V_281:
F_217 ( V_27 , V_282 ) ;
return V_229 ;
}
int F_218 ( struct V_27 * V_27 , struct V_49 * V_50 )
{
struct V_21 * V_22 = F_23 ( V_27 ) ;
int V_19 = V_267 ;
int V_51 = 0 ;
if ( ! V_22 -> V_108 . V_106 )
return V_51 ;
if ( V_50 -> V_52 == V_86 ) {
if ( V_22 -> V_108 . V_106 <= ( V_22 -> V_94 >> 1 ) )
goto V_281;
V_19 = 0 ;
}
V_51 = F_215 ( V_27 , V_19 ) ;
if ( V_51 >= 0 ) {
if ( V_50 -> V_52 == V_86 ) {
if ( V_51 < V_50 -> V_283 )
V_50 -> V_283 -= V_51 ;
else
V_50 -> V_283 = 0 ;
}
return 0 ;
}
V_281:
F_217 ( V_27 , V_282 ) ;
return V_51 ;
}
int F_219 ( struct V_90 * V_91 ,
T_1 V_284 , T_1 V_285 )
{
int V_51 ;
V_51 = F_220 ( V_91 , V_284 , V_285 ) ;
if ( V_51 == 0 )
V_51 = F_221 ( V_91 -> V_28 , true ) ;
return V_51 ;
}
int F_222 ( struct V_27 * V_27 )
{
int V_51 ;
F_223 ( V_27 ) ;
V_51 = F_224 ( V_27 -> V_286 ) ;
if ( V_51 )
goto V_36;
V_51 = F_215 ( V_27 , V_267 ) ;
if ( V_51 < 0 )
goto V_36;
F_221 ( V_27 , true ) ;
V_51 = 0 ;
V_36:
F_225 ( V_27 , V_51 ) ;
return V_51 ;
}
int F_226 ( struct V_27 * V_27 , struct V_23 * V_23 )
{
struct V_20 * V_24 ;
int V_51 = 0 ;
F_227 ( V_23 ) ;
V_24 = F_62 ( V_23 , false ) ;
if ( F_74 ( V_24 ) ) {
V_51 = F_73 ( V_24 ) ;
} else if ( V_24 ) {
F_96 ( V_24 ) ;
F_135 ( V_24 ) ;
}
return V_51 ;
}
int F_131 ( struct V_27 * V_27 , struct V_23 * V_23 )
{
T_1 V_287 = F_28 ( V_23 ) ;
T_1 V_288 = V_287 + ( T_1 ) ( V_289 - 1 ) ;
struct V_49 V_50 = {
. V_52 = V_53 ,
. V_283 = 0 ,
. V_287 = V_287 ,
. V_288 = V_288 ,
} ;
int V_51 ;
F_228 ( V_27 ) ;
for (; ; ) {
F_227 ( V_23 ) ;
if ( F_229 ( V_23 ) ) {
V_51 = F_81 ( V_23 , & V_50 ) ;
if ( V_51 < 0 )
goto V_280;
continue;
}
V_51 = 0 ;
if ( ! F_13 ( V_23 ) )
break;
V_51 = F_215 ( V_27 , V_267 ) ;
if ( V_51 < 0 )
goto V_280;
}
V_280:
F_230 ( V_27 , V_51 ) ;
return V_51 ;
}
int F_231 ( struct V_90 * V_91 , struct V_23 * V_290 ,
struct V_23 * V_23 , enum V_291 V_215 )
{
if ( F_13 ( V_23 ) )
return - V_292 ;
if ( ! F_232 ( V_23 , V_293 ) )
return - V_292 ;
return F_233 ( V_91 , V_290 , V_23 , V_215 ) ;
}
int T_6 F_234 ( void )
{
V_294 = F_235 ( L_12 ,
sizeof( struct V_11 ) ,
0 , V_295 ,
NULL ) ;
if ( V_294 == NULL )
return - V_296 ;
V_12 = F_236 ( V_297 ,
V_294 ) ;
if ( V_12 == NULL )
goto V_298;
V_7 = F_235 ( L_13 ,
sizeof( struct V_1 ) ,
0 , V_295 ,
NULL ) ;
if ( V_7 == NULL )
goto V_299;
V_4 = F_236 ( V_300 ,
V_7 ) ;
if ( V_4 == NULL )
goto V_301;
V_302 = ( 16 * F_237 ( V_303 ) ) << ( V_35 - 10 ) ;
if ( V_302 > 256 * 1024 )
V_302 = 256 * 1024 ;
return 0 ;
V_301:
F_238 ( V_7 ) ;
V_299:
F_239 ( V_12 ) ;
V_298:
F_238 ( V_294 ) ;
return - V_296 ;
}
void F_240 ( void )
{
F_239 ( V_4 ) ;
F_238 ( V_7 ) ;
F_239 ( V_12 ) ;
F_238 ( V_294 ) ;
}
