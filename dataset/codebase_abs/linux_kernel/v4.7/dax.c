static int T_1 F_1 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_2 ; V_1 ++ )
F_2 ( V_3 + V_1 ) ;
return 0 ;
}
static T_2 * F_3 ( struct V_4 * V_5 ,
T_3 V_6 )
{
unsigned long V_7 = F_4 ( ( unsigned long ) V_5 ^ V_6 ,
V_8 ) ;
return V_3 + V_7 ;
}
static long F_5 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
struct V_13 * V_14 = V_10 -> V_15 ;
long V_16 = - V_17 ;
V_12 -> V_18 = ( void V_19 * ) F_6 ( - V_17 ) ;
if ( F_7 ( V_14 , true ) != 0 )
return V_16 ;
V_16 = F_8 ( V_10 , V_12 ) ;
if ( V_16 < 0 ) {
V_12 -> V_18 = ( void V_19 * ) F_6 ( V_16 ) ;
F_9 ( V_14 ) ;
return V_16 ;
}
return V_16 ;
}
static void F_10 ( struct V_9 * V_10 ,
const struct V_11 * V_12 )
{
if ( F_11 ( V_12 -> V_18 ) )
return;
F_9 ( V_10 -> V_15 ) ;
}
struct V_20 * F_12 ( struct V_9 * V_10 , T_4 V_21 )
{
struct V_20 * V_20 = F_13 ( V_22 , 0 ) ;
struct V_11 V_12 = {
. V_23 = V_24 ,
. V_25 = V_21 & ~ ( ( ( ( int ) V_24 ) / 512 ) - 1 ) ,
} ;
long V_16 ;
if ( ! V_20 )
return F_6 ( - V_26 ) ;
V_16 = F_5 ( V_10 , & V_12 ) ;
if ( V_16 < 0 )
return F_6 ( V_16 ) ;
F_14 ( F_15 ( V_20 ) , V_12 . V_18 , V_24 ) ;
F_10 ( V_10 , & V_12 ) ;
return V_20 ;
}
static bool F_16 ( struct V_27 * V_28 )
{
return F_17 ( V_28 ) && ! F_18 ( V_28 ) ;
}
static bool F_19 ( struct V_27 * V_28 )
{
return V_28 -> V_29 != 0 ;
}
static T_4 F_20 ( const struct V_27 * V_28 ,
const struct V_30 * V_30 )
{
T_4 V_25 = V_28 -> V_31 << ( V_30 -> V_32 - 9 ) ;
return V_25 ;
}
static T_5 F_21 ( struct V_30 * V_30 , struct V_33 * V_34 ,
T_6 V_35 , T_6 V_36 , T_7 V_37 ,
struct V_27 * V_28 )
{
T_6 V_38 = V_35 , V_39 = V_35 , V_40 = V_35 ;
bool V_41 = false , V_42 = false ;
struct V_9 * V_10 = NULL ;
int V_43 = F_22 ( V_34 ) , V_16 ;
long V_44 = 0 ;
struct V_11 V_12 = {
. V_18 = ( void V_19 * ) F_6 ( - V_17 ) ,
} ;
unsigned V_45 = V_30 -> V_32 ;
T_4 V_46 = ( F_23 ( V_30 ) + ( 1 << V_45 ) - 1 )
>> V_45 ;
if ( V_43 == V_47 )
V_36 = F_24 ( V_36 , F_23 ( V_30 ) ) ;
while ( V_38 < V_36 ) {
T_8 V_48 ;
if ( V_38 == V_39 ) {
long V_20 = V_38 >> V_49 ;
T_4 V_50 = V_20 << ( V_49 - V_45 ) ;
unsigned V_51 = V_38 - ( V_50 << V_45 ) ;
long V_23 ;
if ( V_38 == V_40 ) {
V_28 -> V_52 = F_25 ( V_36 - V_38 ) ;
V_28 -> V_29 = 0 ;
V_16 = V_37 ( V_30 , V_50 , V_28 , V_43 == V_53 ) ;
if ( V_16 )
break;
if ( ! F_19 ( V_28 ) )
V_28 -> V_52 = 1 << V_45 ;
V_40 = V_38 - V_51 + V_28 -> V_52 ;
V_10 = V_28 -> V_54 ;
F_26 (
( F_27 ( V_28 ) && V_50 < V_46 ) ||
( V_43 == V_53 && F_18 ( V_28 ) ) ) ;
} else {
unsigned V_55 = V_28 -> V_52 -
( V_40 - ( V_38 - V_51 ) ) ;
V_28 -> V_31 += V_55 >> V_45 ;
V_28 -> V_52 -= V_55 ;
}
V_41 = V_43 == V_47 && ! F_16 ( V_28 ) ;
if ( V_41 ) {
V_23 = V_28 -> V_52 - V_51 ;
} else {
F_10 ( V_10 , & V_12 ) ;
V_12 . V_25 = F_20 ( V_28 , V_30 ) ;
V_12 . V_23 = V_28 -> V_52 ;
V_44 = F_5 ( V_10 , & V_12 ) ;
if ( V_44 < 0 ) {
V_16 = V_44 ;
break;
}
V_12 . V_18 += V_51 ;
V_23 = V_44 - V_51 ;
}
V_39 = F_28 ( V_56 , V_38 + V_23 , V_36 ) ;
}
if ( F_22 ( V_34 ) == V_53 ) {
V_48 = F_29 ( V_12 . V_18 , V_39 - V_38 , V_34 ) ;
V_42 = true ;
} else if ( ! V_41 )
V_48 = F_30 ( ( void V_57 * ) V_12 . V_18 , V_39 - V_38 ,
V_34 ) ;
else
V_48 = F_31 ( V_39 - V_38 , V_34 ) ;
if ( ! V_48 ) {
V_16 = - V_58 ;
break;
}
V_38 += V_48 ;
if ( ! F_11 ( V_12 . V_18 ) )
V_12 . V_18 += V_48 ;
}
if ( V_42 )
F_32 () ;
F_10 ( V_10 , & V_12 ) ;
return ( V_38 == V_35 ) ? V_16 : V_38 - V_35 ;
}
T_5 F_33 ( struct V_59 * V_60 , struct V_30 * V_30 ,
struct V_33 * V_34 , T_7 V_37 ,
T_9 V_61 , int V_62 )
{
struct V_27 V_28 ;
T_5 V_63 = - V_64 ;
T_6 V_38 = V_60 -> V_65 ;
T_6 V_36 = V_38 + F_34 ( V_34 ) ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
V_28 . V_54 = V_30 -> V_66 -> V_67 ;
if ( ( V_62 & V_68 ) && F_22 ( V_34 ) == V_47 )
F_35 ( V_30 ) ;
if ( ! ( V_62 & V_69 ) )
F_36 ( V_30 ) ;
V_63 = F_21 ( V_30 , V_34 , V_38 , V_36 , V_37 , & V_28 ) ;
if ( ( V_62 & V_68 ) && F_22 ( V_34 ) == V_47 )
F_37 ( V_30 ) ;
if ( V_61 ) {
int V_70 ;
V_70 = V_61 ( V_60 , V_38 , V_63 , V_28 . V_71 ) ;
if ( V_70 )
V_63 = V_70 ;
}
if ( ! ( V_62 & V_69 ) )
F_38 ( V_30 ) ;
return V_63 ;
}
static int F_39 ( T_10 * V_72 , unsigned int V_73 ,
int V_74 , void * V_75 )
{
struct V_76 * V_77 = V_75 ;
struct V_78 * V_79 =
F_40 ( V_72 , struct V_78 , V_72 ) ;
if ( V_77 -> V_5 != V_79 -> V_77 . V_5 ||
V_77 -> V_6 != V_79 -> V_77 . V_6 )
return 0 ;
return F_41 ( V_72 , V_73 , V_74 , NULL ) ;
}
static inline int F_42 ( struct V_4 * V_5 , void * * V_80 )
{
unsigned long V_81 = ( unsigned long )
F_43 ( V_80 , & V_5 -> V_82 ) ;
return V_81 & V_83 ;
}
static inline void * F_44 ( struct V_4 * V_5 , void * * V_80 )
{
unsigned long V_81 = ( unsigned long )
F_43 ( V_80 , & V_5 -> V_82 ) ;
V_81 |= V_83 ;
F_45 ( V_80 , ( void * ) V_81 ) ;
return ( void * ) V_81 ;
}
static inline void * F_46 ( struct V_4 * V_5 , void * * V_80 )
{
unsigned long V_81 = ( unsigned long )
F_43 ( V_80 , & V_5 -> V_82 ) ;
V_81 &= ~ ( unsigned long ) V_83 ;
F_45 ( V_80 , ( void * ) V_81 ) ;
return ( void * ) V_81 ;
}
static void * F_47 ( struct V_4 * V_5 ,
T_3 V_6 , void * * * V_84 )
{
void * V_85 , * * V_80 ;
struct V_78 V_79 ;
T_2 * V_86 = F_3 ( V_5 , V_6 ) ;
F_48 ( & V_79 . V_72 ) ;
V_79 . V_72 . V_87 = F_39 ;
V_79 . V_77 . V_5 = V_5 ;
V_79 . V_77 . V_6 = V_6 ;
for (; ; ) {
V_85 = F_49 ( & V_5 -> V_88 , V_6 , NULL ,
& V_80 ) ;
if ( ! V_85 || ! F_50 ( V_85 ) ||
! F_42 ( V_5 , V_80 ) ) {
if ( V_84 )
* V_84 = V_80 ;
return V_85 ;
}
F_51 ( V_86 , & V_79 . V_72 ,
V_89 ) ;
F_52 ( & V_5 -> V_82 ) ;
F_53 () ;
F_54 ( V_86 , & V_79 . V_72 ) ;
F_55 ( & V_5 -> V_82 ) ;
}
}
static void * F_56 ( struct V_4 * V_5 , T_3 V_6 )
{
void * V_85 , * * V_80 ;
V_90:
F_55 ( & V_5 -> V_82 ) ;
V_85 = F_47 ( V_5 , V_6 , & V_80 ) ;
if ( ! V_85 ) {
int V_70 ;
F_52 ( & V_5 -> V_82 ) ;
V_70 = F_57 (
F_58 ( V_5 ) & ~ V_91 ) ;
if ( V_70 )
return F_6 ( V_70 ) ;
V_85 = ( void * ) ( V_92 |
V_83 ) ;
F_55 ( & V_5 -> V_82 ) ;
V_70 = F_59 ( & V_5 -> V_88 , V_6 , V_85 ) ;
F_60 () ;
if ( V_70 ) {
F_52 ( & V_5 -> V_82 ) ;
if ( V_70 == - V_93 )
goto V_90;
return F_6 ( V_70 ) ;
}
V_5 -> V_94 ++ ;
F_52 ( & V_5 -> V_82 ) ;
return V_85 ;
}
if ( ! F_50 ( V_85 ) ) {
struct V_20 * V_20 = V_85 ;
F_61 ( V_20 ) ;
F_52 ( & V_5 -> V_82 ) ;
F_62 ( V_20 ) ;
if ( F_63 ( V_20 -> V_5 != V_5 ) ) {
F_64 ( V_20 ) ;
F_65 ( V_20 ) ;
goto V_90;
}
return V_20 ;
}
V_85 = F_44 ( V_5 , V_80 ) ;
F_52 ( & V_5 -> V_82 ) ;
return V_85 ;
}
void F_66 ( struct V_4 * V_5 ,
T_3 V_6 , bool V_95 )
{
T_2 * V_86 = F_3 ( V_5 , V_6 ) ;
if ( F_67 ( V_86 ) ) {
struct V_76 V_77 ;
V_77 . V_5 = V_5 ;
V_77 . V_6 = V_6 ;
F_68 ( V_86 , V_96 , V_95 ? 0 : 1 , & V_77 ) ;
}
}
void F_69 ( struct V_4 * V_5 , T_3 V_6 )
{
void * V_85 , * * V_80 ;
F_55 ( & V_5 -> V_82 ) ;
V_85 = F_49 ( & V_5 -> V_88 , V_6 , NULL , & V_80 ) ;
if ( F_26 ( ! V_85 || ! F_50 ( V_85 ) ||
! F_42 ( V_5 , V_80 ) ) ) {
F_52 ( & V_5 -> V_82 ) ;
return;
}
F_46 ( V_5 , V_80 ) ;
F_52 ( & V_5 -> V_82 ) ;
F_66 ( V_5 , V_6 , false ) ;
}
static void F_70 ( struct V_4 * V_5 ,
T_3 V_6 , void * V_81 )
{
if ( ! F_50 ( V_81 ) ) {
F_64 ( V_81 ) ;
F_65 ( V_81 ) ;
} else {
F_69 ( V_5 , V_6 ) ;
}
}
static void F_71 ( struct V_4 * V_5 ,
T_3 V_6 , void * V_81 )
{
if ( ! F_50 ( V_81 ) )
return;
F_66 ( V_5 , V_6 , false ) ;
}
int F_72 ( struct V_4 * V_5 , T_3 V_6 )
{
void * V_81 ;
F_55 ( & V_5 -> V_82 ) ;
V_81 = F_47 ( V_5 , V_6 , NULL ) ;
if ( F_26 ( ! V_81 || ! F_50 ( V_81 ) ) ) {
F_52 ( & V_5 -> V_82 ) ;
return 0 ;
}
F_73 ( & V_5 -> V_88 , V_6 ) ;
V_5 -> V_94 -- ;
F_52 ( & V_5 -> V_82 ) ;
F_66 ( V_5 , V_6 , true ) ;
return 1 ;
}
static int F_74 ( struct V_4 * V_5 , void * V_81 ,
struct V_97 * V_98 )
{
struct V_20 * V_20 ;
if ( ! F_50 ( V_81 ) ) {
V_98 -> V_20 = V_81 ;
return V_99 ;
}
V_20 = F_75 ( V_5 , V_98 -> V_100 ,
V_98 -> V_101 | V_102 ) ;
if ( ! V_20 ) {
F_70 ( V_5 , V_98 -> V_100 , V_81 ) ;
return V_103 ;
}
V_98 -> V_20 = V_20 ;
return V_99 ;
}
static int F_76 ( struct V_20 * V_104 , struct V_30 * V_30 ,
struct V_27 * V_28 , unsigned long V_105 )
{
struct V_11 V_12 = {
. V_25 = F_20 ( V_28 , V_30 ) ,
. V_23 = V_28 -> V_52 ,
} ;
struct V_9 * V_10 = V_28 -> V_54 ;
void * V_106 ;
if ( F_5 ( V_10 , & V_12 ) < 0 )
return F_77 ( V_12 . V_18 ) ;
V_106 = F_78 ( V_104 ) ;
F_79 ( V_106 , ( void V_57 * ) V_12 . V_18 , V_105 , V_104 ) ;
F_80 ( V_106 ) ;
F_10 ( V_10 , & V_12 ) ;
return 0 ;
}
static void * F_81 ( struct V_4 * V_5 ,
struct V_97 * V_98 ,
void * V_81 , T_4 V_25 )
{
struct V_107 * V_88 = & V_5 -> V_88 ;
int error = 0 ;
bool V_108 = false ;
void * V_109 ;
T_3 V_6 = V_98 -> V_100 ;
if ( V_98 -> V_62 & V_110 )
F_82 ( V_5 -> V_111 , V_112 ) ;
if ( ! F_50 ( V_81 ) ) {
V_108 = true ;
F_83 ( V_5 , V_98 -> V_100 << V_49 ,
V_24 , 0 ) ;
error = F_57 ( V_98 -> V_101 & ~ V_91 ) ;
if ( error )
return F_6 ( error ) ;
}
F_55 ( & V_5 -> V_82 ) ;
V_109 = ( void * ) ( ( unsigned long ) F_84 ( V_25 , false ) |
V_83 ) ;
if ( V_108 ) {
F_85 ( V_81 , NULL ) ;
F_65 ( V_81 ) ;
error = F_59 ( V_88 , V_6 , V_109 ) ;
if ( error ) {
V_109 = F_6 ( error ) ;
goto V_113;
}
V_5 -> V_94 ++ ;
} else {
void * * V_80 ;
void * V_85 ;
V_85 = F_49 ( V_88 , V_6 , NULL , & V_80 ) ;
F_26 ( V_85 != V_81 ) ;
F_45 ( V_80 , V_109 ) ;
}
if ( V_98 -> V_62 & V_110 )
F_86 ( V_88 , V_6 , V_114 ) ;
V_113:
F_52 ( & V_5 -> V_82 ) ;
if ( V_108 ) {
F_60 () ;
if ( V_5 -> V_115 -> V_116 )
V_5 -> V_115 -> V_116 ( V_81 ) ;
F_64 ( V_81 ) ;
F_65 ( V_81 ) ;
}
return V_109 ;
}
static int F_87 ( struct V_9 * V_10 ,
struct V_4 * V_5 , T_3 V_6 , void * V_81 )
{
struct V_107 * V_88 = & V_5 -> V_88 ;
int type = F_88 ( V_81 ) ;
struct V_117 * V_118 ;
struct V_11 V_12 ;
void * * V_80 ;
int V_85 = 0 ;
F_55 ( & V_5 -> V_82 ) ;
if ( ! F_49 ( V_88 , V_6 , & V_118 , & V_80 ) )
goto V_113;
if ( * V_80 != V_81 )
goto V_113;
if ( ! F_89 ( V_88 , V_6 , V_119 ) )
goto V_113;
if ( F_26 ( type != V_120 && type != V_121 ) ) {
V_85 = - V_17 ;
goto V_113;
}
V_12 . V_25 = F_90 ( V_81 ) ;
V_12 . V_23 = ( type == V_121 ? V_122 : V_24 ) ;
F_52 ( & V_5 -> V_82 ) ;
V_85 = F_5 ( V_10 , & V_12 ) ;
if ( V_85 < 0 )
return V_85 ;
if ( F_26 ( V_85 < V_12 . V_23 ) ) {
V_85 = - V_17 ;
goto V_123;
}
F_91 ( V_12 . V_18 , V_12 . V_23 ) ;
F_55 ( & V_5 -> V_82 ) ;
F_92 ( V_88 , V_6 , V_119 ) ;
F_52 ( & V_5 -> V_82 ) ;
V_123:
F_10 ( V_10 , & V_12 ) ;
return V_85 ;
V_113:
F_52 ( & V_5 -> V_82 ) ;
return V_85 ;
}
int F_93 ( struct V_4 * V_5 ,
struct V_9 * V_10 , struct V_124 * V_125 )
{
struct V_30 * V_30 = V_5 -> V_111 ;
T_3 V_126 , V_127 , V_128 ;
T_3 V_129 [ V_130 ] ;
struct V_131 V_132 ;
bool V_55 = false ;
int V_1 , V_85 = 0 ;
void * V_81 ;
if ( F_26 ( V_30 -> V_32 != V_49 ) )
return - V_17 ;
if ( ! V_5 -> V_94 || V_125 -> V_133 != V_134 )
return 0 ;
V_126 = V_125 -> V_135 >> V_49 ;
V_127 = V_125 -> V_136 >> V_49 ;
V_128 = F_94 ( V_126 ) ;
F_95 () ;
V_81 = F_96 ( & V_5 -> V_88 , V_128 ) ;
F_97 () ;
if ( V_81 && F_88 ( V_81 ) == V_121 )
V_126 = V_128 ;
F_98 ( V_5 , V_126 , V_127 ) ;
F_99 ( & V_132 , 0 ) ;
while ( ! V_55 ) {
V_132 . V_137 = F_100 ( V_5 , V_126 ,
V_119 , V_130 ,
V_132 . V_138 , V_129 ) ;
if ( V_132 . V_137 == 0 )
break;
for ( V_1 = 0 ; V_1 < V_132 . V_137 ; V_1 ++ ) {
if ( V_129 [ V_1 ] > V_127 ) {
V_55 = true ;
break;
}
V_85 = F_87 ( V_10 , V_5 , V_129 [ V_1 ] ,
V_132 . V_138 [ V_1 ] ) ;
if ( V_85 < 0 )
return V_85 ;
}
}
F_32 () ;
return 0 ;
}
static int F_101 ( struct V_4 * V_5 ,
struct V_27 * V_28 , void * * V_139 ,
struct V_140 * V_141 , struct V_97 * V_98 )
{
unsigned long V_105 = ( unsigned long ) V_98 -> V_142 ;
struct V_9 * V_10 = V_28 -> V_54 ;
struct V_11 V_12 = {
. V_25 = F_20 ( V_28 , V_5 -> V_111 ) ,
. V_23 = V_28 -> V_52 ,
} ;
void * V_85 ;
void * V_81 = * V_139 ;
if ( F_5 ( V_10 , & V_12 ) < 0 )
return F_77 ( V_12 . V_18 ) ;
F_10 ( V_10 , & V_12 ) ;
V_85 = F_81 ( V_5 , V_98 , V_81 , V_12 . V_25 ) ;
if ( F_11 ( V_85 ) )
return F_77 ( V_85 ) ;
* V_139 = V_85 ;
return F_102 ( V_141 , V_105 , V_12 . V_143 ) ;
}
int F_103 ( struct V_140 * V_141 , struct V_97 * V_98 ,
T_7 V_37 )
{
struct V_144 * V_144 = V_141 -> V_145 ;
struct V_4 * V_5 = V_144 -> V_146 ;
struct V_30 * V_30 = V_5 -> V_111 ;
void * V_81 ;
struct V_27 V_28 ;
unsigned long V_105 = ( unsigned long ) V_98 -> V_142 ;
unsigned V_45 = V_30 -> V_32 ;
T_4 V_50 ;
T_3 V_23 ;
int error ;
int V_147 = 0 ;
V_23 = ( F_23 ( V_30 ) + V_24 - 1 ) >> V_49 ;
if ( V_98 -> V_100 >= V_23 )
return V_148 ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
V_50 = ( T_4 ) V_98 -> V_100 << ( V_49 - V_45 ) ;
V_28 . V_54 = V_30 -> V_66 -> V_67 ;
V_28 . V_52 = V_24 ;
V_81 = F_56 ( V_5 , V_98 -> V_100 ) ;
if ( F_11 ( V_81 ) ) {
error = F_77 ( V_81 ) ;
goto V_149;
}
error = V_37 ( V_30 , V_50 , & V_28 , 0 ) ;
if ( ! error && ( V_28 . V_52 < V_24 ) )
error = - V_17 ;
if ( error )
goto V_150;
if ( V_98 -> V_151 ) {
struct V_20 * V_152 = V_98 -> V_151 ;
if ( F_16 ( & V_28 ) )
error = F_76 ( V_152 , V_30 , & V_28 , V_105 ) ;
else
F_104 ( V_152 , V_105 ) ;
if ( error )
goto V_150;
if ( ! F_50 ( V_81 ) ) {
V_98 -> V_20 = V_81 ;
return V_99 ;
}
V_98 -> V_81 = V_81 ;
return V_153 ;
}
if ( ! F_17 ( & V_28 ) ) {
if ( V_98 -> V_62 & V_110 ) {
error = V_37 ( V_30 , V_50 , & V_28 , 1 ) ;
F_105 ( V_154 ) ;
F_106 ( V_141 -> V_155 , V_154 ) ;
V_147 = V_156 ;
if ( ! error && ( V_28 . V_52 < V_24 ) )
error = - V_17 ;
if ( error )
goto V_150;
} else {
return F_74 ( V_5 , V_81 , V_98 ) ;
}
}
F_26 ( F_18 ( & V_28 ) || F_27 ( & V_28 ) ) ;
error = F_101 ( V_5 , & V_28 , & V_81 , V_141 , V_98 ) ;
V_150:
F_70 ( V_5 , V_98 -> V_100 , V_81 ) ;
V_149:
if ( error == - V_26 )
return V_103 | V_147 ;
if ( ( error < 0 ) && ( error != - V_157 ) )
return V_148 | V_147 ;
return V_158 | V_147 ;
}
int F_107 ( struct V_140 * V_141 , struct V_97 * V_98 ,
T_7 V_37 )
{
int V_159 ;
struct V_160 * V_161 = F_108 ( V_141 -> V_145 ) -> V_66 ;
if ( V_98 -> V_62 & V_110 ) {
F_109 ( V_161 ) ;
F_110 ( V_141 -> V_145 ) ;
}
V_159 = F_103 ( V_141 , V_98 , V_37 ) ;
if ( V_98 -> V_62 & V_110 )
F_111 ( V_161 ) ;
return V_159 ;
}
static void F_112 ( struct V_27 * V_28 , unsigned long V_162 ,
const char * V_163 , const char * V_164 )
{
if ( V_28 ) {
char V_165 [ V_166 ] ;
F_113 ( V_28 -> V_54 , V_165 ) ;
F_114 ( L_1
L_2 , V_164 , V_167 -> V_168 ,
V_162 , V_165 , V_28 -> V_29 , ( V_56 ) V_28 -> V_31 ,
V_28 -> V_52 , V_163 ) ;
} else {
F_114 ( L_3 , V_164 ,
V_167 -> V_168 , V_162 , V_163 ) ;
}
}
int F_115 ( struct V_140 * V_141 , unsigned long V_162 ,
T_11 * V_169 , unsigned int V_62 , T_7 V_37 )
{
struct V_144 * V_144 = V_141 -> V_145 ;
struct V_4 * V_5 = V_144 -> V_146 ;
struct V_30 * V_30 = V_5 -> V_111 ;
struct V_27 V_28 ;
unsigned V_45 = V_30 -> V_32 ;
unsigned long V_170 = V_162 & V_171 ;
bool V_172 = V_62 & V_110 ;
struct V_9 * V_10 ;
T_3 V_23 , V_100 ;
T_4 V_50 ;
int V_159 = 0 ;
bool V_173 = false ;
if ( ! F_116 ( V_174 ) )
return V_175 ;
if ( V_172 && ! ( V_141 -> V_176 & V_177 ) ) {
F_117 ( V_141 , V_169 , V_162 ) ;
F_118 ( NULL , V_162 , L_4 ) ;
return V_175 ;
}
if ( V_170 < V_141 -> V_178 ) {
F_118 ( NULL , V_162 , L_5 ) ;
return V_175 ;
}
if ( ( V_170 + V_122 ) > V_141 -> V_179 ) {
F_118 ( NULL , V_162 , L_6 ) ;
return V_175 ;
}
V_100 = F_119 ( V_141 , V_170 ) ;
V_23 = ( F_23 ( V_30 ) + V_24 - 1 ) >> V_49 ;
if ( V_100 >= V_23 )
return V_148 ;
if ( ( V_100 | V_180 ) >= V_23 ) {
F_118 ( NULL , V_162 ,
L_7 ) ;
return V_175 ;
}
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
V_28 . V_54 = V_30 -> V_66 -> V_67 ;
V_50 = ( T_4 ) V_100 << ( V_49 - V_45 ) ;
V_28 . V_52 = V_122 ;
if ( V_37 ( V_30 , V_50 , & V_28 , 0 ) != 0 )
return V_148 ;
if ( ! F_17 ( & V_28 ) && V_172 ) {
if ( V_37 ( V_30 , V_50 , & V_28 , 1 ) != 0 )
return V_148 ;
V_173 = true ;
F_26 ( F_18 ( & V_28 ) || F_27 ( & V_28 ) ) ;
}
V_10 = V_28 . V_54 ;
if ( ! F_19 ( & V_28 ) || V_28 . V_52 < V_122 ) {
F_118 ( & V_28 , V_162 , L_8 ) ;
return V_175 ;
}
if ( V_173 ) {
T_6 V_181 = V_100 << V_49 ;
T_6 V_182 = V_181 + V_122 - 1 ;
F_120 ( V_30 , V_181 , V_182 ) ;
}
if ( ! V_172 && ! F_17 ( & V_28 ) ) {
T_12 * V_183 ;
T_11 V_81 ;
struct V_20 * V_184 = F_121 () ;
if ( F_63 ( ! V_184 ) ) {
F_118 ( & V_28 , V_162 , L_9 ) ;
goto V_185;
}
V_183 = F_122 ( V_141 -> V_155 , V_169 ) ;
if ( ! F_123 ( * V_169 ) ) {
F_124 ( V_183 ) ;
F_118 ( & V_28 , V_162 , L_10 ) ;
goto V_185;
}
F_125 ( F_126 ( V_10 -> V_186 ) ,
L_11 ,
V_187 , V_167 -> V_168 , V_162 ,
( unsigned long long ) F_20 ( & V_28 , V_30 ) ) ;
V_81 = F_127 ( V_184 , V_141 -> V_188 ) ;
V_81 = F_128 ( V_81 ) ;
F_129 ( V_141 -> V_155 , V_170 , V_169 , V_81 ) ;
V_159 = V_158 ;
F_124 ( V_183 ) ;
} else {
struct V_11 V_12 = {
. V_25 = F_20 ( & V_28 , V_30 ) ,
. V_23 = V_122 ,
} ;
long V_189 = F_5 ( V_10 , & V_12 ) ;
if ( V_189 < 0 ) {
F_118 ( & V_28 , V_162 , L_12 ) ;
goto V_185;
}
if ( V_189 < V_122 ) {
F_118 ( & V_28 , V_162 , L_13 ) ;
F_10 ( V_10 , & V_12 ) ;
goto V_185;
}
if ( F_130 ( V_12 . V_143 ) & V_180 ) {
F_118 ( & V_28 , V_162 , L_14 ) ;
F_10 ( V_10 , & V_12 ) ;
goto V_185;
}
if ( ! F_131 ( V_12 . V_143 ) ) {
F_10 ( V_10 , & V_12 ) ;
F_118 ( & V_28 , V_162 , L_15 ) ;
goto V_185;
}
F_10 ( V_10 , & V_12 ) ;
if ( V_172 ) {
}
F_125 ( F_126 ( V_10 -> V_186 ) ,
L_16 ,
V_187 , V_167 -> V_168 , V_162 ,
F_130 ( V_12 . V_143 ) ,
( unsigned long long ) V_12 . V_25 ) ;
V_159 |= F_132 ( V_141 , V_162 , V_169 ,
V_12 . V_143 , V_172 ) ;
}
V_149:
return V_159 ;
V_185:
F_105 ( V_190 ) ;
V_159 = V_175 ;
goto V_149;
}
int F_133 ( struct V_140 * V_141 , unsigned long V_162 ,
T_11 * V_169 , unsigned int V_62 , T_7 V_37 )
{
int V_159 ;
struct V_160 * V_161 = F_108 ( V_141 -> V_145 ) -> V_66 ;
if ( V_62 & V_110 ) {
F_109 ( V_161 ) ;
F_110 ( V_141 -> V_145 ) ;
}
V_159 = F_115 ( V_141 , V_162 , V_169 , V_62 , V_37 ) ;
if ( V_62 & V_110 )
F_111 ( V_161 ) ;
return V_159 ;
}
int F_134 ( struct V_140 * V_141 , struct V_97 * V_98 )
{
struct V_144 * V_144 = V_141 -> V_145 ;
struct V_4 * V_5 = V_144 -> V_146 ;
void * V_81 ;
T_3 V_6 = V_98 -> V_100 ;
F_55 ( & V_5 -> V_82 ) ;
V_81 = F_47 ( V_5 , V_6 , NULL ) ;
if ( ! V_81 || ! F_50 ( V_81 ) )
goto V_149;
F_86 ( & V_5 -> V_88 , V_6 , V_114 ) ;
F_71 ( V_5 , V_6 , V_81 ) ;
V_149:
F_52 ( & V_5 -> V_82 ) ;
return V_158 ;
}
static bool F_135 ( struct V_9 * V_10 ,
unsigned int V_191 , unsigned int V_189 )
{
unsigned short V_192 = F_136 ( V_10 ) ;
if ( ! F_137 ( V_191 , V_192 ) )
return false ;
if ( ! F_137 ( V_189 , V_192 ) )
return false ;
return true ;
}
int F_138 ( struct V_9 * V_10 , T_4 V_25 ,
unsigned int V_191 , unsigned int V_189 )
{
struct V_11 V_12 = {
. V_25 = V_25 ,
. V_23 = V_24 ,
} ;
if ( F_135 ( V_10 , V_191 , V_189 ) ) {
T_4 V_193 = V_12 . V_25 + ( V_191 >> 9 ) ;
return F_139 ( V_10 , V_193 ,
V_189 >> 9 , V_194 , true ) ;
} else {
if ( F_5 ( V_10 , & V_12 ) < 0 )
return F_77 ( V_12 . V_18 ) ;
F_140 ( V_12 . V_18 + V_191 , V_189 ) ;
F_32 () ;
F_10 ( V_10 , & V_12 ) ;
}
return 0 ;
}
int F_141 ( struct V_30 * V_30 , T_6 V_195 , unsigned V_189 ,
T_7 V_37 )
{
struct V_27 V_28 ;
T_3 V_6 = V_195 >> V_49 ;
unsigned V_191 = V_195 & ( V_24 - 1 ) ;
int V_70 ;
if ( ! V_189 )
return 0 ;
F_142 ( ( V_191 + V_189 ) > V_24 ) ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
V_28 . V_54 = V_30 -> V_66 -> V_67 ;
V_28 . V_52 = V_24 ;
V_70 = V_37 ( V_30 , V_6 , & V_28 , 0 ) ;
if ( V_70 < 0 || ! F_16 ( & V_28 ) )
return V_70 ;
return F_138 ( V_28 . V_54 , F_20 ( & V_28 , V_30 ) ,
V_191 , V_189 ) ;
}
int F_143 ( struct V_30 * V_30 , T_6 V_195 , T_7 V_37 )
{
unsigned V_189 = F_25 ( V_195 ) - V_195 ;
return F_141 ( V_30 , V_195 , V_189 , V_37 ) ;
}
