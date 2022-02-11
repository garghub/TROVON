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
V_12 -> V_18 = F_6 ( - V_17 ) ;
if ( F_7 ( V_14 , true ) != 0 )
return V_16 ;
V_16 = F_8 ( V_10 , V_12 ) ;
if ( V_16 < 0 ) {
V_12 -> V_18 = F_6 ( V_16 ) ;
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
struct V_19 * F_12 ( struct V_9 * V_10 , T_4 V_20 )
{
struct V_19 * V_19 = F_13 ( V_21 , 0 ) ;
struct V_11 V_12 = {
. V_22 = V_23 ,
. V_24 = V_20 & ~ ( ( ( ( int ) V_23 ) / 512 ) - 1 ) ,
} ;
long V_16 ;
if ( ! V_19 )
return F_6 ( - V_25 ) ;
V_16 = F_5 ( V_10 , & V_12 ) ;
if ( V_16 < 0 )
return F_6 ( V_16 ) ;
F_14 ( F_15 ( V_19 ) , V_12 . V_18 , V_23 ) ;
F_10 ( V_10 , & V_12 ) ;
return V_19 ;
}
static bool F_16 ( struct V_26 * V_27 )
{
return F_17 ( V_27 ) && ! F_18 ( V_27 ) ;
}
static bool F_19 ( struct V_26 * V_27 )
{
return V_27 -> V_28 != 0 ;
}
static T_4 F_20 ( const struct V_26 * V_27 ,
const struct V_29 * V_29 )
{
T_4 V_24 = V_27 -> V_30 << ( V_29 -> V_31 - 9 ) ;
return V_24 ;
}
static T_5 F_21 ( struct V_29 * V_29 , struct V_32 * V_33 ,
T_6 V_34 , T_6 V_35 , T_7 V_36 ,
struct V_26 * V_27 )
{
T_6 V_37 = V_34 , V_38 = V_34 , V_39 = V_34 ;
bool V_40 = false ;
struct V_9 * V_10 = NULL ;
int V_41 = F_22 ( V_33 ) , V_16 ;
long V_42 = 0 ;
struct V_11 V_12 = {
. V_18 = F_6 ( - V_17 ) ,
} ;
unsigned V_43 = V_29 -> V_31 ;
T_4 V_44 = ( F_23 ( V_29 ) + ( 1 << V_43 ) - 1 )
>> V_43 ;
if ( V_41 == V_45 )
V_35 = F_24 ( V_35 , F_23 ( V_29 ) ) ;
while ( V_37 < V_35 ) {
T_8 V_46 ;
if ( V_37 == V_38 ) {
long V_19 = V_37 >> V_47 ;
T_4 V_48 = V_19 << ( V_47 - V_43 ) ;
unsigned V_49 = V_37 - ( V_48 << V_43 ) ;
long V_22 ;
if ( V_37 == V_39 ) {
V_27 -> V_50 = F_25 ( V_35 - V_37 ) ;
V_27 -> V_28 = 0 ;
V_16 = V_36 ( V_29 , V_48 , V_27 , V_41 == V_51 ) ;
if ( V_16 )
break;
if ( ! F_19 ( V_27 ) )
V_27 -> V_50 = 1 << V_43 ;
V_39 = V_37 - V_49 + V_27 -> V_50 ;
V_10 = V_27 -> V_52 ;
F_26 (
( F_27 ( V_27 ) && V_48 < V_44 ) ||
( V_41 == V_51 && F_18 ( V_27 ) ) ) ;
} else {
unsigned V_53 = V_27 -> V_50 -
( V_39 - ( V_37 - V_49 ) ) ;
V_27 -> V_30 += V_53 >> V_43 ;
V_27 -> V_50 -= V_53 ;
}
V_40 = V_41 == V_45 && ! F_16 ( V_27 ) ;
if ( V_40 ) {
V_22 = V_27 -> V_50 - V_49 ;
} else {
F_10 ( V_10 , & V_12 ) ;
V_12 . V_24 = F_20 ( V_27 , V_29 ) ;
V_12 . V_22 = V_27 -> V_50 ;
V_42 = F_5 ( V_10 , & V_12 ) ;
if ( V_42 < 0 ) {
V_16 = V_42 ;
break;
}
V_12 . V_18 += V_49 ;
V_22 = V_42 - V_49 ;
}
V_38 = F_28 ( V_54 , V_37 + V_22 , V_35 ) ;
}
if ( F_22 ( V_33 ) == V_51 ) {
V_46 = F_29 ( V_12 . V_18 , V_38 - V_37 , V_33 ) ;
} else if ( ! V_40 )
V_46 = F_30 ( ( void V_55 * ) V_12 . V_18 , V_38 - V_37 ,
V_33 ) ;
else
V_46 = F_31 ( V_38 - V_37 , V_33 ) ;
if ( ! V_46 ) {
V_16 = - V_56 ;
break;
}
V_37 += V_46 ;
if ( ! F_11 ( V_12 . V_18 ) )
V_12 . V_18 += V_46 ;
}
F_10 ( V_10 , & V_12 ) ;
return ( V_37 == V_34 ) ? V_16 : V_37 - V_34 ;
}
T_5 F_32 ( struct V_57 * V_58 , struct V_29 * V_29 ,
struct V_32 * V_33 , T_7 V_36 ,
T_9 V_59 , int V_60 )
{
struct V_26 V_27 ;
T_5 V_61 = - V_62 ;
T_6 V_37 = V_58 -> V_63 ;
T_6 V_35 = V_37 + F_33 ( V_33 ) ;
memset ( & V_27 , 0 , sizeof( V_27 ) ) ;
V_27 . V_52 = V_29 -> V_64 -> V_65 ;
if ( ( V_60 & V_66 ) && F_22 ( V_33 ) == V_45 )
F_34 ( V_29 ) ;
if ( ! ( V_60 & V_67 ) )
F_35 ( V_29 ) ;
V_61 = F_21 ( V_29 , V_33 , V_37 , V_35 , V_36 , & V_27 ) ;
if ( ( V_60 & V_66 ) && F_22 ( V_33 ) == V_45 )
F_36 ( V_29 ) ;
if ( V_59 ) {
int V_68 ;
V_68 = V_59 ( V_58 , V_37 , V_61 , V_27 . V_69 ) ;
if ( V_68 )
V_61 = V_68 ;
}
if ( ! ( V_60 & V_67 ) )
F_37 ( V_29 ) ;
return V_61 ;
}
static int F_38 ( T_10 * V_70 , unsigned int V_71 ,
int V_72 , void * V_73 )
{
struct V_74 * V_75 = V_73 ;
struct V_76 * V_77 =
F_39 ( V_70 , struct V_76 , V_70 ) ;
if ( V_75 -> V_5 != V_77 -> V_75 . V_5 ||
V_75 -> V_6 != V_77 -> V_75 . V_6 )
return 0 ;
return F_40 ( V_70 , V_71 , V_72 , NULL ) ;
}
static inline int F_41 ( struct V_4 * V_5 , void * * V_78 )
{
unsigned long V_79 = ( unsigned long )
F_42 ( V_78 , & V_5 -> V_80 ) ;
return V_79 & V_81 ;
}
static inline void * F_43 ( struct V_4 * V_5 , void * * V_78 )
{
unsigned long V_79 = ( unsigned long )
F_42 ( V_78 , & V_5 -> V_80 ) ;
V_79 |= V_81 ;
F_44 ( V_78 , ( void * ) V_79 ) ;
return ( void * ) V_79 ;
}
static inline void * F_45 ( struct V_4 * V_5 , void * * V_78 )
{
unsigned long V_79 = ( unsigned long )
F_42 ( V_78 , & V_5 -> V_80 ) ;
V_79 &= ~ ( unsigned long ) V_81 ;
F_44 ( V_78 , ( void * ) V_79 ) ;
return ( void * ) V_79 ;
}
static void * F_46 ( struct V_4 * V_5 ,
T_3 V_6 , void * * * V_82 )
{
void * V_83 , * * V_78 ;
struct V_76 V_77 ;
T_2 * V_84 = F_3 ( V_5 , V_6 ) ;
F_47 ( & V_77 . V_70 ) ;
V_77 . V_70 . V_85 = F_38 ;
V_77 . V_75 . V_5 = V_5 ;
V_77 . V_75 . V_6 = V_6 ;
for (; ; ) {
V_83 = F_48 ( & V_5 -> V_86 , V_6 , NULL ,
& V_78 ) ;
if ( ! V_83 || ! F_49 ( V_83 ) ||
! F_41 ( V_5 , V_78 ) ) {
if ( V_82 )
* V_82 = V_78 ;
return V_83 ;
}
F_50 ( V_84 , & V_77 . V_70 ,
V_87 ) ;
F_51 ( & V_5 -> V_80 ) ;
F_52 () ;
F_53 ( V_84 , & V_77 . V_70 ) ;
F_54 ( & V_5 -> V_80 ) ;
}
}
static void * F_55 ( struct V_4 * V_5 , T_3 V_6 )
{
void * V_83 , * * V_78 ;
V_88:
F_54 ( & V_5 -> V_80 ) ;
V_83 = F_46 ( V_5 , V_6 , & V_78 ) ;
if ( ! V_83 ) {
int V_68 ;
F_51 ( & V_5 -> V_80 ) ;
V_68 = F_56 (
F_57 ( V_5 ) & ~ V_89 ) ;
if ( V_68 )
return F_6 ( V_68 ) ;
V_83 = ( void * ) ( V_90 |
V_81 ) ;
F_54 ( & V_5 -> V_80 ) ;
V_68 = F_58 ( & V_5 -> V_86 , V_6 , V_83 ) ;
F_59 () ;
if ( V_68 ) {
F_51 ( & V_5 -> V_80 ) ;
if ( V_68 == - V_91 )
goto V_88;
return F_6 ( V_68 ) ;
}
V_5 -> V_92 ++ ;
F_51 ( & V_5 -> V_80 ) ;
return V_83 ;
}
if ( ! F_49 ( V_83 ) ) {
struct V_19 * V_19 = V_83 ;
F_60 ( V_19 ) ;
F_51 ( & V_5 -> V_80 ) ;
F_61 ( V_19 ) ;
if ( F_62 ( V_19 -> V_5 != V_5 ) ) {
F_63 ( V_19 ) ;
F_64 ( V_19 ) ;
goto V_88;
}
return V_19 ;
}
V_83 = F_43 ( V_5 , V_78 ) ;
F_51 ( & V_5 -> V_80 ) ;
return V_83 ;
}
void F_65 ( struct V_4 * V_5 ,
T_3 V_6 , bool V_93 )
{
T_2 * V_84 = F_3 ( V_5 , V_6 ) ;
if ( F_66 ( V_84 ) ) {
struct V_74 V_75 ;
V_75 . V_5 = V_5 ;
V_75 . V_6 = V_6 ;
F_67 ( V_84 , V_94 , V_93 ? 0 : 1 , & V_75 ) ;
}
}
void F_68 ( struct V_4 * V_5 , T_3 V_6 )
{
void * V_83 , * * V_78 ;
F_54 ( & V_5 -> V_80 ) ;
V_83 = F_48 ( & V_5 -> V_86 , V_6 , NULL , & V_78 ) ;
if ( F_26 ( ! V_83 || ! F_49 ( V_83 ) ||
! F_41 ( V_5 , V_78 ) ) ) {
F_51 ( & V_5 -> V_80 ) ;
return;
}
F_45 ( V_5 , V_78 ) ;
F_51 ( & V_5 -> V_80 ) ;
F_65 ( V_5 , V_6 , false ) ;
}
static void F_69 ( struct V_4 * V_5 ,
T_3 V_6 , void * V_79 )
{
if ( ! F_49 ( V_79 ) ) {
F_63 ( V_79 ) ;
F_64 ( V_79 ) ;
} else {
F_68 ( V_5 , V_6 ) ;
}
}
static void F_70 ( struct V_4 * V_5 ,
T_3 V_6 , void * V_79 )
{
if ( ! F_49 ( V_79 ) )
return;
F_65 ( V_5 , V_6 , false ) ;
}
int F_71 ( struct V_4 * V_5 , T_3 V_6 )
{
void * V_79 ;
F_54 ( & V_5 -> V_80 ) ;
V_79 = F_46 ( V_5 , V_6 , NULL ) ;
if ( F_26 ( ! V_79 || ! F_49 ( V_79 ) ) ) {
F_51 ( & V_5 -> V_80 ) ;
return 0 ;
}
F_72 ( & V_5 -> V_86 , V_6 ) ;
V_5 -> V_92 -- ;
F_51 ( & V_5 -> V_80 ) ;
F_65 ( V_5 , V_6 , true ) ;
return 1 ;
}
static int F_73 ( struct V_4 * V_5 , void * V_79 ,
struct V_95 * V_96 )
{
struct V_19 * V_19 ;
if ( ! F_49 ( V_79 ) ) {
V_96 -> V_19 = V_79 ;
return V_97 ;
}
V_19 = F_74 ( V_5 , V_96 -> V_98 ,
V_96 -> V_99 | V_100 ) ;
if ( ! V_19 ) {
F_69 ( V_5 , V_96 -> V_98 , V_79 ) ;
return V_101 ;
}
V_96 -> V_19 = V_19 ;
return V_97 ;
}
static int F_75 ( struct V_19 * V_102 , struct V_29 * V_29 ,
struct V_26 * V_27 , unsigned long V_103 )
{
struct V_11 V_12 = {
. V_24 = F_20 ( V_27 , V_29 ) ,
. V_22 = V_27 -> V_50 ,
} ;
struct V_9 * V_10 = V_27 -> V_52 ;
void * V_104 ;
if ( F_5 ( V_10 , & V_12 ) < 0 )
return F_76 ( V_12 . V_18 ) ;
V_104 = F_77 ( V_102 ) ;
F_78 ( V_104 , ( void V_55 * ) V_12 . V_18 , V_103 , V_102 ) ;
F_79 ( V_104 ) ;
F_10 ( V_10 , & V_12 ) ;
return 0 ;
}
static void * F_80 ( struct V_4 * V_5 ,
struct V_95 * V_96 ,
void * V_79 , T_4 V_24 )
{
struct V_105 * V_86 = & V_5 -> V_86 ;
int error = 0 ;
bool V_106 = false ;
void * V_107 ;
T_3 V_6 = V_96 -> V_98 ;
if ( V_96 -> V_60 & V_108 )
F_81 ( V_5 -> V_109 , V_110 ) ;
if ( ! F_49 ( V_79 ) ) {
V_106 = true ;
F_82 ( V_5 , V_96 -> V_98 << V_47 ,
V_23 , 0 ) ;
error = F_56 ( V_96 -> V_99 & ~ V_89 ) ;
if ( error )
return F_6 ( error ) ;
}
F_54 ( & V_5 -> V_80 ) ;
V_107 = ( void * ) ( ( unsigned long ) F_83 ( V_24 , false ) |
V_81 ) ;
if ( V_106 ) {
F_84 ( V_79 , NULL ) ;
F_64 ( V_79 ) ;
error = F_58 ( V_86 , V_6 , V_107 ) ;
if ( error ) {
V_107 = F_6 ( error ) ;
goto V_111;
}
V_5 -> V_92 ++ ;
} else {
void * * V_78 ;
void * V_83 ;
V_83 = F_48 ( V_86 , V_6 , NULL , & V_78 ) ;
F_26 ( V_83 != V_79 ) ;
F_44 ( V_78 , V_107 ) ;
}
if ( V_96 -> V_60 & V_108 )
F_85 ( V_86 , V_6 , V_112 ) ;
V_111:
F_51 ( & V_5 -> V_80 ) ;
if ( V_106 ) {
F_59 () ;
if ( V_5 -> V_113 -> V_114 )
V_5 -> V_113 -> V_114 ( V_79 ) ;
F_63 ( V_79 ) ;
F_64 ( V_79 ) ;
}
return V_107 ;
}
static int F_86 ( struct V_9 * V_10 ,
struct V_4 * V_5 , T_3 V_6 , void * V_79 )
{
struct V_105 * V_86 = & V_5 -> V_86 ;
int type = F_87 ( V_79 ) ;
struct V_115 * V_116 ;
struct V_11 V_12 ;
void * * V_78 ;
int V_83 = 0 ;
F_54 ( & V_5 -> V_80 ) ;
if ( ! F_48 ( V_86 , V_6 , & V_116 , & V_78 ) )
goto V_111;
if ( * V_78 != V_79 )
goto V_111;
if ( ! F_88 ( V_86 , V_6 , V_117 ) )
goto V_111;
if ( F_26 ( type != V_118 && type != V_119 ) ) {
V_83 = - V_17 ;
goto V_111;
}
V_12 . V_24 = F_89 ( V_79 ) ;
V_12 . V_22 = ( type == V_119 ? V_120 : V_23 ) ;
F_51 ( & V_5 -> V_80 ) ;
V_83 = F_5 ( V_10 , & V_12 ) ;
if ( V_83 < 0 )
return V_83 ;
if ( F_26 ( V_83 < V_12 . V_22 ) ) {
V_83 = - V_17 ;
goto V_121;
}
F_90 ( V_12 . V_18 , V_12 . V_22 ) ;
F_54 ( & V_5 -> V_80 ) ;
F_91 ( V_86 , V_6 , V_117 ) ;
F_51 ( & V_5 -> V_80 ) ;
V_121:
F_10 ( V_10 , & V_12 ) ;
return V_83 ;
V_111:
F_51 ( & V_5 -> V_80 ) ;
return V_83 ;
}
int F_92 ( struct V_4 * V_5 ,
struct V_9 * V_10 , struct V_122 * V_123 )
{
struct V_29 * V_29 = V_5 -> V_109 ;
T_3 V_124 , V_125 , V_126 ;
T_3 V_127 [ V_128 ] ;
struct V_129 V_130 ;
bool V_53 = false ;
int V_1 , V_83 = 0 ;
void * V_79 ;
if ( F_26 ( V_29 -> V_31 != V_47 ) )
return - V_17 ;
if ( ! V_5 -> V_92 || V_123 -> V_131 != V_132 )
return 0 ;
V_124 = V_123 -> V_133 >> V_47 ;
V_125 = V_123 -> V_134 >> V_47 ;
V_126 = F_93 ( V_124 ) ;
F_94 () ;
V_79 = F_95 ( & V_5 -> V_86 , V_126 ) ;
F_96 () ;
if ( V_79 && F_87 ( V_79 ) == V_119 )
V_124 = V_126 ;
F_97 ( V_5 , V_124 , V_125 ) ;
F_98 ( & V_130 , 0 ) ;
while ( ! V_53 ) {
V_130 . V_135 = F_99 ( V_5 , V_124 ,
V_117 , V_128 ,
V_130 . V_136 , V_127 ) ;
if ( V_130 . V_135 == 0 )
break;
for ( V_1 = 0 ; V_1 < V_130 . V_135 ; V_1 ++ ) {
if ( V_127 [ V_1 ] > V_125 ) {
V_53 = true ;
break;
}
V_83 = F_86 ( V_10 , V_5 , V_127 [ V_1 ] ,
V_130 . V_136 [ V_1 ] ) ;
if ( V_83 < 0 )
return V_83 ;
}
}
return 0 ;
}
static int F_100 ( struct V_4 * V_5 ,
struct V_26 * V_27 , void * * V_137 ,
struct V_138 * V_139 , struct V_95 * V_96 )
{
unsigned long V_103 = ( unsigned long ) V_96 -> V_140 ;
struct V_9 * V_10 = V_27 -> V_52 ;
struct V_11 V_12 = {
. V_24 = F_20 ( V_27 , V_5 -> V_109 ) ,
. V_22 = V_27 -> V_50 ,
} ;
void * V_83 ;
void * V_79 = * V_137 ;
if ( F_5 ( V_10 , & V_12 ) < 0 )
return F_76 ( V_12 . V_18 ) ;
F_10 ( V_10 , & V_12 ) ;
V_83 = F_80 ( V_5 , V_96 , V_79 , V_12 . V_24 ) ;
if ( F_11 ( V_83 ) )
return F_76 ( V_83 ) ;
* V_137 = V_83 ;
return F_101 ( V_139 , V_103 , V_12 . V_141 ) ;
}
int F_102 ( struct V_138 * V_139 , struct V_95 * V_96 ,
T_7 V_36 )
{
struct V_142 * V_142 = V_139 -> V_143 ;
struct V_4 * V_5 = V_142 -> V_144 ;
struct V_29 * V_29 = V_5 -> V_109 ;
void * V_79 ;
struct V_26 V_27 ;
unsigned long V_103 = ( unsigned long ) V_96 -> V_140 ;
unsigned V_43 = V_29 -> V_31 ;
T_4 V_48 ;
T_3 V_22 ;
int error ;
int V_145 = 0 ;
V_22 = ( F_23 ( V_29 ) + V_23 - 1 ) >> V_47 ;
if ( V_96 -> V_98 >= V_22 )
return V_146 ;
memset ( & V_27 , 0 , sizeof( V_27 ) ) ;
V_48 = ( T_4 ) V_96 -> V_98 << ( V_47 - V_43 ) ;
V_27 . V_52 = V_29 -> V_64 -> V_65 ;
V_27 . V_50 = V_23 ;
V_79 = F_55 ( V_5 , V_96 -> V_98 ) ;
if ( F_11 ( V_79 ) ) {
error = F_76 ( V_79 ) ;
goto V_147;
}
error = V_36 ( V_29 , V_48 , & V_27 , 0 ) ;
if ( ! error && ( V_27 . V_50 < V_23 ) )
error = - V_17 ;
if ( error )
goto V_148;
if ( V_96 -> V_149 ) {
struct V_19 * V_150 = V_96 -> V_149 ;
if ( F_16 ( & V_27 ) )
error = F_75 ( V_150 , V_29 , & V_27 , V_103 ) ;
else
F_103 ( V_150 , V_103 ) ;
if ( error )
goto V_148;
if ( ! F_49 ( V_79 ) ) {
V_96 -> V_19 = V_79 ;
return V_97 ;
}
V_96 -> V_79 = V_79 ;
return V_151 ;
}
if ( ! F_17 ( & V_27 ) ) {
if ( V_96 -> V_60 & V_108 ) {
error = V_36 ( V_29 , V_48 , & V_27 , 1 ) ;
F_104 ( V_152 ) ;
F_105 ( V_139 -> V_153 , V_152 ) ;
V_145 = V_154 ;
if ( ! error && ( V_27 . V_50 < V_23 ) )
error = - V_17 ;
if ( error )
goto V_148;
} else {
return F_73 ( V_5 , V_79 , V_96 ) ;
}
}
F_26 ( F_18 ( & V_27 ) || F_27 ( & V_27 ) ) ;
error = F_100 ( V_5 , & V_27 , & V_79 , V_139 , V_96 ) ;
V_148:
F_69 ( V_5 , V_96 -> V_98 , V_79 ) ;
V_147:
if ( error == - V_25 )
return V_101 | V_145 ;
if ( ( error < 0 ) && ( error != - V_155 ) )
return V_146 | V_145 ;
return V_156 | V_145 ;
}
static void F_106 ( struct V_26 * V_27 , unsigned long V_157 ,
const char * V_158 , const char * V_159 )
{
if ( V_27 ) {
char V_160 [ V_161 ] ;
F_107 ( V_27 -> V_52 , V_160 ) ;
F_108 ( L_1
L_2 , V_159 , V_162 -> V_163 ,
V_157 , V_160 , V_27 -> V_28 , ( V_54 ) V_27 -> V_30 ,
V_27 -> V_50 , V_158 ) ;
} else {
F_108 ( L_3 , V_159 ,
V_162 -> V_163 , V_157 , V_158 ) ;
}
}
int F_109 ( struct V_138 * V_139 , unsigned long V_157 ,
T_11 * V_164 , unsigned int V_60 , T_7 V_36 )
{
struct V_142 * V_142 = V_139 -> V_143 ;
struct V_4 * V_5 = V_142 -> V_144 ;
struct V_29 * V_29 = V_5 -> V_109 ;
struct V_26 V_27 ;
unsigned V_43 = V_29 -> V_31 ;
unsigned long V_165 = V_157 & V_166 ;
bool V_167 = V_60 & V_108 ;
struct V_9 * V_10 ;
T_3 V_22 , V_98 ;
T_4 V_48 ;
int V_168 = 0 ;
bool V_169 = false ;
if ( ! F_110 ( V_170 ) )
return V_171 ;
if ( V_167 && ! ( V_139 -> V_172 & V_173 ) ) {
F_111 ( V_139 , V_164 , V_157 ) ;
F_112 ( NULL , V_157 , L_4 ) ;
return V_171 ;
}
if ( V_165 < V_139 -> V_174 ) {
F_112 ( NULL , V_157 , L_5 ) ;
return V_171 ;
}
if ( ( V_165 + V_120 ) > V_139 -> V_175 ) {
F_112 ( NULL , V_157 , L_6 ) ;
return V_171 ;
}
V_98 = F_113 ( V_139 , V_165 ) ;
V_22 = ( F_23 ( V_29 ) + V_23 - 1 ) >> V_47 ;
if ( V_98 >= V_22 )
return V_146 ;
if ( ( V_98 | V_176 ) >= V_22 ) {
F_112 ( NULL , V_157 ,
L_7 ) ;
return V_171 ;
}
memset ( & V_27 , 0 , sizeof( V_27 ) ) ;
V_27 . V_52 = V_29 -> V_64 -> V_65 ;
V_48 = ( T_4 ) V_98 << ( V_47 - V_43 ) ;
V_27 . V_50 = V_120 ;
if ( V_36 ( V_29 , V_48 , & V_27 , 0 ) != 0 )
return V_146 ;
if ( ! F_17 ( & V_27 ) && V_167 ) {
if ( V_36 ( V_29 , V_48 , & V_27 , 1 ) != 0 )
return V_146 ;
V_169 = true ;
F_26 ( F_18 ( & V_27 ) || F_27 ( & V_27 ) ) ;
}
V_10 = V_27 . V_52 ;
if ( ! F_19 ( & V_27 ) || V_27 . V_50 < V_120 ) {
F_112 ( & V_27 , V_157 , L_8 ) ;
return V_171 ;
}
if ( V_169 ) {
T_6 V_177 = V_98 << V_47 ;
T_6 V_178 = V_177 + V_120 - 1 ;
F_114 ( V_29 , V_177 , V_178 ) ;
}
if ( ! V_167 && ! F_17 ( & V_27 ) ) {
T_12 * V_179 ;
T_11 V_79 ;
struct V_19 * V_180 = F_115 () ;
if ( F_62 ( ! V_180 ) ) {
F_112 ( & V_27 , V_157 , L_9 ) ;
goto V_181;
}
V_179 = F_116 ( V_139 -> V_153 , V_164 ) ;
if ( ! F_117 ( * V_164 ) ) {
F_118 ( V_179 ) ;
F_112 ( & V_27 , V_157 , L_10 ) ;
goto V_181;
}
F_119 ( F_120 ( V_10 -> V_182 ) ,
L_11 ,
V_183 , V_162 -> V_163 , V_157 ,
( unsigned long long ) F_20 ( & V_27 , V_29 ) ) ;
V_79 = F_121 ( V_180 , V_139 -> V_184 ) ;
V_79 = F_122 ( V_79 ) ;
F_123 ( V_139 -> V_153 , V_165 , V_164 , V_79 ) ;
V_168 = V_156 ;
F_118 ( V_179 ) ;
} else {
struct V_11 V_12 = {
. V_24 = F_20 ( & V_27 , V_29 ) ,
. V_22 = V_120 ,
} ;
long V_185 = F_5 ( V_10 , & V_12 ) ;
if ( V_185 < 0 ) {
F_112 ( & V_27 , V_157 , L_12 ) ;
goto V_181;
}
if ( V_185 < V_120 ) {
F_112 ( & V_27 , V_157 , L_13 ) ;
F_10 ( V_10 , & V_12 ) ;
goto V_181;
}
if ( F_124 ( V_12 . V_141 ) & V_176 ) {
F_112 ( & V_27 , V_157 , L_14 ) ;
F_10 ( V_10 , & V_12 ) ;
goto V_181;
}
if ( ! F_125 ( V_12 . V_141 ) ) {
F_10 ( V_10 , & V_12 ) ;
F_112 ( & V_27 , V_157 , L_15 ) ;
goto V_181;
}
F_10 ( V_10 , & V_12 ) ;
if ( V_167 ) {
}
F_119 ( F_120 ( V_10 -> V_182 ) ,
L_16 ,
V_183 , V_162 -> V_163 , V_157 ,
F_124 ( V_12 . V_141 ) ,
( unsigned long long ) V_12 . V_24 ) ;
V_168 |= F_126 ( V_139 , V_157 , V_164 ,
V_12 . V_141 , V_167 ) ;
}
V_147:
return V_168 ;
V_181:
F_104 ( V_186 ) ;
V_168 = V_171 ;
goto V_147;
}
int F_127 ( struct V_138 * V_139 , struct V_95 * V_96 )
{
struct V_142 * V_142 = V_139 -> V_143 ;
struct V_4 * V_5 = V_142 -> V_144 ;
void * V_79 ;
T_3 V_6 = V_96 -> V_98 ;
F_54 ( & V_5 -> V_80 ) ;
V_79 = F_46 ( V_5 , V_6 , NULL ) ;
if ( ! V_79 || ! F_49 ( V_79 ) )
goto V_147;
F_85 ( & V_5 -> V_86 , V_6 , V_112 ) ;
F_70 ( V_5 , V_6 , V_79 ) ;
V_147:
F_51 ( & V_5 -> V_80 ) ;
return V_156 ;
}
static bool F_128 ( struct V_9 * V_10 ,
unsigned int V_187 , unsigned int V_185 )
{
unsigned short V_188 = F_129 ( V_10 ) ;
if ( ! F_130 ( V_187 , V_188 ) )
return false ;
if ( ! F_130 ( V_185 , V_188 ) )
return false ;
return true ;
}
int F_131 ( struct V_9 * V_10 , T_4 V_24 ,
unsigned int V_187 , unsigned int V_185 )
{
struct V_11 V_12 = {
. V_24 = V_24 ,
. V_22 = V_23 ,
} ;
if ( F_128 ( V_10 , V_187 , V_185 ) ) {
T_4 V_189 = V_12 . V_24 + ( V_187 >> 9 ) ;
return F_132 ( V_10 , V_189 ,
V_185 >> 9 , V_190 , true ) ;
} else {
if ( F_5 ( V_10 , & V_12 ) < 0 )
return F_76 ( V_12 . V_18 ) ;
F_133 ( V_12 . V_18 + V_187 , V_185 ) ;
F_10 ( V_10 , & V_12 ) ;
}
return 0 ;
}
int F_134 ( struct V_29 * V_29 , T_6 V_191 , unsigned V_185 ,
T_7 V_36 )
{
struct V_26 V_27 ;
T_3 V_6 = V_191 >> V_47 ;
unsigned V_187 = V_191 & ( V_23 - 1 ) ;
int V_68 ;
if ( ! V_185 )
return 0 ;
F_135 ( ( V_187 + V_185 ) > V_23 ) ;
memset ( & V_27 , 0 , sizeof( V_27 ) ) ;
V_27 . V_52 = V_29 -> V_64 -> V_65 ;
V_27 . V_50 = V_23 ;
V_68 = V_36 ( V_29 , V_6 , & V_27 , 0 ) ;
if ( V_68 < 0 || ! F_16 ( & V_27 ) )
return V_68 ;
return F_131 ( V_27 . V_52 , F_20 ( & V_27 , V_29 ) ,
V_187 , V_185 ) ;
}
int F_136 ( struct V_29 * V_29 , T_6 V_191 , T_7 V_36 )
{
unsigned V_185 = F_25 ( V_191 ) - V_191 ;
return F_134 ( V_29 , V_191 , V_185 , V_36 ) ;
}
