static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
return sprintf ( V_5 , L_1 , V_6 ) ;
}
static T_1 F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_7 )
{
unsigned long V_8 ;
int V_9 ;
V_9 = F_3 ( V_5 , 10 , & V_8 ) ;
if ( V_9 || V_8 > V_10 )
return - V_11 ;
V_6 = V_8 ;
V_12 = 0 ;
F_4 ( & V_13 ) ;
return V_7 ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
return sprintf ( V_5 , L_1 , V_14 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_7 )
{
unsigned long V_8 ;
int V_9 ;
V_9 = F_3 ( V_5 , 10 , & V_8 ) ;
if ( V_9 || V_8 > V_10 )
return - V_11 ;
V_14 = V_8 ;
V_12 = 0 ;
F_4 ( & V_13 ) ;
return V_7 ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
return sprintf ( V_5 , L_1 , V_15 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_7 )
{
int V_9 ;
unsigned long V_16 ;
V_9 = F_3 ( V_5 , 10 , & V_16 ) ;
if ( V_9 || ! V_16 || V_16 > V_10 )
return - V_11 ;
V_15 = V_16 ;
return V_7 ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
return sprintf ( V_5 , L_1 , V_17 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
return sprintf ( V_5 , L_1 , V_18 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return F_12 ( V_2 , V_4 , V_5 ,
V_19 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_7 )
{
return F_14 ( V_2 , V_4 , V_5 , V_7 ,
V_19 ) ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
return sprintf ( V_5 , L_1 , V_20 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_7 )
{
int V_9 ;
unsigned long V_21 ;
V_9 = F_3 ( V_5 , 10 , & V_21 ) ;
if ( V_9 || V_21 > V_22 - 1 )
return - V_11 ;
V_20 = V_21 ;
return V_7 ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
return sprintf ( V_5 , L_1 , V_23 ) ;
}
static T_1 F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_7 )
{
int V_9 ;
unsigned long V_24 ;
V_9 = F_3 ( V_5 , 10 , & V_24 ) ;
if ( V_9 || V_24 > V_22 - 1 )
return - V_11 ;
V_23 = V_24 ;
return V_7 ;
}
int F_19 ( struct V_25 * V_26 ,
unsigned long * V_27 , int V_28 )
{
switch ( V_28 ) {
case V_29 :
#ifdef F_20
if ( F_21 ( V_26 -> V_30 ) )
return 0 ;
#endif
* V_27 &= ~ V_31 ;
* V_27 |= V_32 ;
if ( ! ( * V_27 & V_33 ) &&
F_22 ( V_26 , * V_27 ) )
return - V_34 ;
break;
case V_35 :
* V_27 &= ~ V_32 ;
* V_27 |= V_31 ;
break;
}
return 0 ;
}
int T_3 F_23 ( void )
{
V_36 = F_24 ( L_2 ,
sizeof( struct V_37 ) ,
F_25 ( struct V_37 ) , 0 , NULL ) ;
if ( ! V_36 )
return - V_34 ;
V_15 = V_22 * 8 ;
V_20 = V_22 - 1 ;
V_23 = V_22 / 8 ;
return 0 ;
}
void T_3 F_26 ( void )
{
F_27 ( V_36 ) ;
}
static inline struct V_37 * F_28 ( void )
{
if ( ! V_36 )
return NULL ;
return F_29 ( V_36 , V_38 ) ;
}
static inline void F_30 ( struct V_37 * V_37 )
{
F_31 ( V_36 , V_37 ) ;
}
static struct V_37 * F_32 ( struct V_39 * V_40 )
{
struct V_37 * V_37 ;
F_33 (mm_slots_hash, mm_slot, hash, (unsigned long)mm)
if ( V_40 == V_37 -> V_40 )
return V_37 ;
return NULL ;
}
static void F_34 ( struct V_39 * V_40 ,
struct V_37 * V_37 )
{
V_37 -> V_40 = V_40 ;
F_35 ( V_41 , & V_37 -> V_42 , ( long ) V_40 ) ;
}
static inline int F_36 ( struct V_39 * V_40 )
{
return F_37 ( & V_40 -> V_43 ) == 0 ;
}
int F_38 ( struct V_39 * V_40 )
{
struct V_37 * V_37 ;
int V_44 ;
V_37 = F_28 () ;
if ( ! V_37 )
return - V_34 ;
F_39 ( F_36 ( V_40 ) , V_40 ) ;
if ( F_40 ( F_41 ( V_45 , & V_40 -> V_46 ) ) ) {
F_30 ( V_37 ) ;
return 0 ;
}
F_42 ( & V_47 ) ;
F_34 ( V_40 , V_37 ) ;
V_44 = F_43 ( & V_48 . V_49 ) ;
F_44 ( & V_37 -> V_50 , & V_48 . V_49 ) ;
F_45 ( & V_47 ) ;
F_46 ( & V_40 -> V_51 ) ;
if ( V_44 )
F_4 ( & V_13 ) ;
return 0 ;
}
int F_22 ( struct V_25 * V_26 ,
unsigned long V_27 )
{
unsigned long V_52 , V_53 ;
if ( ! V_26 -> V_54 )
return 0 ;
if ( V_26 -> V_55 || ( V_27 & V_33 ) )
return 0 ;
V_52 = ( V_26 -> V_56 + ~ V_57 ) & V_57 ;
V_53 = V_26 -> V_58 & V_57 ;
if ( V_52 < V_53 )
return F_47 ( V_26 , V_27 ) ;
return 0 ;
}
void F_48 ( struct V_39 * V_40 )
{
struct V_37 * V_37 ;
int free = 0 ;
F_42 ( & V_47 ) ;
V_37 = F_32 ( V_40 ) ;
if ( V_37 && V_48 . V_37 != V_37 ) {
F_49 ( & V_37 -> V_42 ) ;
F_50 ( & V_37 -> V_50 ) ;
free = 1 ;
}
F_45 ( & V_47 ) ;
if ( free ) {
F_51 ( V_45 , & V_40 -> V_46 ) ;
F_30 ( V_37 ) ;
F_52 ( V_40 ) ;
} else if ( V_37 ) {
F_53 ( & V_40 -> V_59 ) ;
F_54 ( & V_40 -> V_59 ) ;
}
}
static void F_55 ( struct V_60 * V_60 )
{
F_56 ( V_60 , V_61 + 0 ) ;
F_57 ( V_60 ) ;
F_58 ( V_60 ) ;
}
static void F_59 ( T_4 * V_62 , T_4 * V_63 )
{
while ( -- V_63 >= V_62 ) {
T_4 V_64 = * V_63 ;
if ( ! F_60 ( V_64 ) && ! F_61 ( F_62 ( V_64 ) ) )
F_55 ( F_63 ( V_64 ) ) ;
}
}
static int F_64 ( struct V_25 * V_26 ,
unsigned long V_65 ,
T_4 * V_62 )
{
struct V_60 * V_60 = NULL ;
T_4 * V_63 ;
int V_66 = 0 , V_67 = 0 , V_68 = 0 ;
bool V_69 = false ;
for ( V_63 = V_62 ; V_63 < V_62 + V_22 ;
V_63 ++ , V_65 += V_70 ) {
T_4 V_64 = * V_63 ;
if ( F_60 ( V_64 ) || ( F_65 ( V_64 ) &&
F_61 ( F_62 ( V_64 ) ) ) ) {
if ( ! F_66 ( V_26 ) &&
++ V_66 <= V_20 ) {
continue;
} else {
V_67 = V_71 ;
goto V_72;
}
}
if ( ! F_65 ( V_64 ) ) {
V_67 = V_73 ;
goto V_72;
}
V_60 = F_67 ( V_26 , V_65 , V_64 ) ;
if ( F_40 ( ! V_60 ) ) {
V_67 = V_74 ;
goto V_72;
}
F_68 ( F_69 ( V_60 ) , V_60 ) ;
F_68 ( ! F_70 ( V_60 ) , V_60 ) ;
F_68 ( ! F_71 ( V_60 ) , V_60 ) ;
if ( ! F_72 ( V_60 ) ) {
V_67 = V_75 ;
goto V_72;
}
if ( F_73 ( V_60 ) != 1 + ! ! F_74 ( V_60 ) ) {
F_57 ( V_60 ) ;
V_67 = V_76 ;
goto V_72;
}
if ( F_75 ( V_64 ) ) {
V_69 = true ;
} else {
if ( F_74 ( V_60 ) &&
! F_76 ( V_60 , NULL ) ) {
F_57 ( V_60 ) ;
V_67 = V_77 ;
goto V_72;
}
}
if ( F_77 ( V_60 ) ) {
F_57 ( V_60 ) ;
V_67 = V_78 ;
goto V_72;
}
F_78 ( V_60 , V_61 + 0 ) ;
F_68 ( ! F_79 ( V_60 ) , V_60 ) ;
F_68 ( F_80 ( V_60 ) , V_60 ) ;
if ( F_81 ( V_64 ) ||
F_82 ( V_60 ) || F_83 ( V_60 ) ||
F_84 ( V_26 -> V_30 , V_65 ) )
V_68 ++ ;
}
if ( F_85 ( V_69 ) ) {
if ( F_85 ( V_68 ) ) {
V_67 = V_79 ;
F_86 ( V_60 , V_66 ,
V_68 , V_69 , V_67 ) ;
return 1 ;
}
} else {
V_67 = V_80 ;
}
V_72:
F_59 ( V_62 , V_63 ) ;
F_86 ( V_60 , V_66 ,
V_68 , V_69 , V_67 ) ;
return 0 ;
}
static void F_87 ( T_4 * V_62 , struct V_60 * V_60 ,
struct V_25 * V_26 ,
unsigned long V_65 ,
T_5 * V_81 )
{
T_4 * V_63 ;
for ( V_63 = V_62 ; V_63 < V_62 + V_22 ; V_63 ++ ) {
T_4 V_64 = * V_63 ;
struct V_60 * V_82 ;
if ( F_60 ( V_64 ) || F_61 ( F_62 ( V_64 ) ) ) {
F_88 ( V_60 , V_65 ) ;
F_89 ( V_26 -> V_30 , V_83 , 1 ) ;
if ( F_61 ( F_62 ( V_64 ) ) ) {
F_42 ( V_81 ) ;
F_90 ( V_26 -> V_30 , V_65 , V_63 ) ;
F_45 ( V_81 ) ;
}
} else {
V_82 = F_63 ( V_64 ) ;
F_91 ( V_60 , V_82 , V_65 , V_26 ) ;
F_68 ( F_92 ( V_82 ) != 1 , V_82 ) ;
F_55 ( V_82 ) ;
F_42 ( V_81 ) ;
F_90 ( V_26 -> V_30 , V_65 , V_63 ) ;
F_93 ( V_82 , false ) ;
F_45 ( V_81 ) ;
F_94 ( V_82 ) ;
}
V_65 += V_70 ;
V_60 ++ ;
}
}
static void F_95 ( void )
{
F_96 ( V_84 ) ;
F_97 ( & V_13 , & V_84 ) ;
F_98 (
F_99 ( V_14 ) ) ;
F_100 ( & V_13 , & V_84 ) ;
}
static bool F_101 ( int V_85 )
{
int V_86 ;
if ( ! V_87 )
return false ;
if ( V_88 [ V_85 ] )
return false ;
for ( V_86 = 0 ; V_86 < V_89 ; V_86 ++ ) {
if ( ! V_88 [ V_86 ] )
continue;
if ( F_102 ( V_85 , V_86 ) > V_90 )
return true ;
}
return false ;
}
static inline T_6 F_103 ( void )
{
return F_104 () ? V_91 : V_92 ;
}
static int F_105 ( void )
{
static int V_93 = V_94 ;
int V_85 , V_95 = 0 , V_96 = 0 ;
for ( V_85 = 0 ; V_85 < V_89 ; V_85 ++ )
if ( V_88 [ V_85 ] > V_96 ) {
V_96 = V_88 [ V_85 ] ;
V_95 = V_85 ;
}
if ( V_95 <= V_93 )
for ( V_85 = V_93 + 1 ; V_85 < V_89 ;
V_85 ++ )
if ( V_96 == V_88 [ V_85 ] ) {
V_95 = V_85 ;
break;
}
V_93 = V_95 ;
return V_95 ;
}
static bool F_106 ( struct V_60 * * V_97 , bool * V_84 )
{
if ( F_107 ( * V_97 ) ) {
if ( ! * V_84 )
return false ;
* V_84 = false ;
* V_97 = NULL ;
F_95 () ;
} else if ( * V_97 ) {
F_108 ( * V_97 ) ;
* V_97 = NULL ;
}
return true ;
}
static struct V_60 *
F_109 ( struct V_60 * * V_97 , T_6 V_98 , int V_99 )
{
F_68 ( * V_97 , * V_97 ) ;
* V_97 = F_110 ( V_99 , V_98 , V_100 ) ;
if ( F_40 ( ! * V_97 ) ) {
F_111 ( V_101 ) ;
* V_97 = F_112 ( - V_34 ) ;
return NULL ;
}
F_113 ( * V_97 ) ;
F_111 ( V_102 ) ;
return * V_97 ;
}
static int F_105 ( void )
{
return 0 ;
}
static inline struct V_60 * F_114 ( void )
{
struct V_60 * V_60 ;
V_60 = F_115 ( F_103 () ,
V_100 ) ;
if ( V_60 )
F_113 ( V_60 ) ;
return V_60 ;
}
static struct V_60 * F_116 ( bool * V_84 )
{
struct V_60 * V_97 ;
do {
V_97 = F_114 () ;
if ( ! V_97 ) {
F_111 ( V_101 ) ;
if ( ! * V_84 )
return NULL ;
* V_84 = false ;
F_95 () ;
} else
F_111 ( V_102 ) ;
} while ( F_40 ( ! V_97 ) && F_85 ( F_117 () ) );
return V_97 ;
}
static bool F_106 ( struct V_60 * * V_97 , bool * V_84 )
{
if ( ! * V_97 )
* V_97 = F_116 ( V_84 ) ;
if ( F_40 ( ! * V_97 ) )
return false ;
return true ;
}
static struct V_60 *
F_109 ( struct V_60 * * V_97 , T_6 V_98 , int V_99 )
{
F_118 ( ! * V_97 ) ;
return * V_97 ;
}
static bool F_119 ( struct V_25 * V_26 )
{
if ( ( ! ( V_26 -> V_27 & V_32 ) && ! F_120 () ) ||
( V_26 -> V_27 & V_31 ) )
return false ;
if ( F_121 ( V_26 -> V_103 ) ) {
if ( ! F_122 ( V_104 ) )
return false ;
return F_123 ( ( V_26 -> V_56 >> V_105 ) - V_26 -> V_106 ,
V_22 ) ;
}
if ( ! V_26 -> V_54 || V_26 -> V_55 )
return false ;
if ( F_124 ( V_26 ) )
return false ;
return ! ( V_26 -> V_27 & V_33 ) ;
}
static int F_125 ( struct V_39 * V_40 , unsigned long V_65 ,
struct V_25 * * V_107 )
{
struct V_25 * V_26 ;
unsigned long V_52 , V_53 ;
if ( F_40 ( F_36 ( V_40 ) ) )
return V_108 ;
* V_107 = V_26 = F_126 ( V_40 , V_65 ) ;
if ( ! V_26 )
return V_109 ;
V_52 = ( V_26 -> V_56 + ~ V_57 ) & V_57 ;
V_53 = V_26 -> V_58 & V_57 ;
if ( V_65 < V_52 || V_65 + V_110 > V_53 )
return V_111 ;
if ( ! F_119 ( V_26 ) )
return V_112 ;
return 0 ;
}
static bool F_127 ( struct V_39 * V_40 ,
struct V_25 * V_26 ,
unsigned long V_65 , T_7 * V_113 ,
int V_68 )
{
int V_114 = 0 , V_115 = 0 ;
struct V_116 V_117 = {
. V_26 = V_26 ,
. V_65 = V_65 ,
. V_46 = V_118 ,
. V_113 = V_113 ,
. V_119 = F_128 ( V_26 , V_65 ) ,
} ;
if ( V_68 < V_22 / 2 ) {
F_129 ( V_40 , V_114 , V_68 , 0 ) ;
return false ;
}
V_117 . V_62 = F_130 ( V_113 , V_65 ) ;
for (; V_117 . V_65 < V_65 + V_22 * V_70 ;
V_117 . V_62 ++ , V_117 . V_65 += V_70 ) {
V_117 . V_120 = * V_117 . V_62 ;
if ( ! F_131 ( V_117 . V_120 ) )
continue;
V_114 ++ ;
V_115 = F_132 ( & V_117 ) ;
if ( V_115 & V_121 ) {
F_133 ( & V_40 -> V_59 ) ;
if ( F_125 ( V_40 , V_65 , & V_117 . V_26 ) ) {
F_129 ( V_40 , V_114 , V_68 , 0 ) ;
return false ;
}
if ( F_134 ( V_40 , V_65 ) != V_113 )
return false ;
}
if ( V_115 & V_122 ) {
F_129 ( V_40 , V_114 , V_68 , 0 ) ;
return false ;
}
V_117 . V_62 = F_130 ( V_113 , V_117 . V_65 ) ;
}
V_117 . V_62 -- ;
F_135 ( V_117 . V_62 ) ;
F_129 ( V_40 , V_114 , V_68 , 1 ) ;
return true ;
}
static void F_136 ( struct V_39 * V_40 ,
unsigned long V_65 ,
struct V_60 * * V_97 ,
int V_99 , int V_68 )
{
T_7 * V_113 , V_123 ;
T_4 * V_62 ;
T_8 V_124 ;
struct V_60 * V_125 ;
T_5 * V_126 , * V_127 ;
int V_128 = 0 , V_67 = 0 ;
struct V_129 * V_130 ;
struct V_25 * V_26 ;
unsigned long V_131 ;
unsigned long V_132 ;
T_6 V_98 ;
F_118 ( V_65 & ~ V_57 ) ;
V_98 = F_103 () | V_133 ;
F_137 ( & V_40 -> V_59 ) ;
V_125 = F_109 ( V_97 , V_98 , V_99 ) ;
if ( ! V_125 ) {
V_67 = V_134 ;
goto V_135;
}
if ( F_40 ( F_138 ( V_125 , V_40 , V_98 , & V_130 , true ) ) ) {
V_67 = V_136 ;
goto V_135;
}
F_133 ( & V_40 -> V_59 ) ;
V_67 = F_125 ( V_40 , V_65 , & V_26 ) ;
if ( V_67 ) {
F_139 ( V_125 , V_130 , true ) ;
F_137 ( & V_40 -> V_59 ) ;
goto V_135;
}
V_113 = F_134 ( V_40 , V_65 ) ;
if ( ! V_113 ) {
V_67 = V_137 ;
F_139 ( V_125 , V_130 , true ) ;
F_137 ( & V_40 -> V_59 ) ;
goto V_135;
}
if ( ! F_127 ( V_40 , V_26 , V_65 , V_113 , V_68 ) ) {
F_139 ( V_125 , V_130 , true ) ;
F_137 ( & V_40 -> V_59 ) ;
goto V_135;
}
F_137 ( & V_40 -> V_59 ) ;
F_53 ( & V_40 -> V_59 ) ;
V_67 = F_125 ( V_40 , V_65 , & V_26 ) ;
if ( V_67 )
goto V_72;
if ( F_134 ( V_40 , V_65 ) != V_113 )
goto V_72;
F_140 ( V_26 -> V_54 ) ;
V_62 = F_130 ( V_113 , V_65 ) ;
V_127 = F_141 ( V_40 , V_113 ) ;
V_131 = V_65 ;
V_132 = V_65 + V_110 ;
F_142 ( V_40 , V_131 , V_132 ) ;
V_126 = F_143 ( V_40 , V_113 ) ;
V_123 = F_144 ( V_26 , V_65 , V_113 ) ;
F_45 ( V_126 ) ;
F_145 ( V_40 , V_131 , V_132 ) ;
F_42 ( V_127 ) ;
V_128 = F_64 ( V_26 , V_65 , V_62 ) ;
F_45 ( V_127 ) ;
if ( F_40 ( ! V_128 ) ) {
F_135 ( V_62 ) ;
F_42 ( V_126 ) ;
F_146 ( ! F_147 ( * V_113 ) ) ;
F_148 ( V_40 , V_113 , F_149 ( V_123 ) ) ;
F_45 ( V_126 ) ;
F_150 ( V_26 -> V_54 ) ;
V_67 = V_138 ;
goto V_72;
}
F_150 ( V_26 -> V_54 ) ;
F_87 ( V_62 , V_125 , V_26 , V_65 , V_127 ) ;
F_135 ( V_62 ) ;
F_151 ( V_125 ) ;
V_124 = F_149 ( V_123 ) ;
V_123 = F_152 ( V_125 , V_26 -> V_139 ) ;
V_123 = F_153 ( F_154 ( V_123 ) , V_26 ) ;
F_155 () ;
F_42 ( V_126 ) ;
F_146 ( ! F_147 ( * V_113 ) ) ;
F_156 ( V_125 , V_26 , V_65 , true ) ;
F_157 ( V_125 , V_130 , false , true ) ;
F_158 ( V_125 , V_26 ) ;
F_159 ( V_40 , V_113 , V_124 ) ;
F_160 ( V_40 , V_65 , V_113 , V_123 ) ;
F_161 ( V_26 , V_65 , V_113 ) ;
F_45 ( V_126 ) ;
* V_97 = NULL ;
V_17 ++ ;
V_67 = V_79 ;
V_140:
F_54 ( & V_40 -> V_59 ) ;
V_135:
F_162 ( V_40 , V_128 , V_67 ) ;
return;
V_72:
F_139 ( V_125 , V_130 , true ) ;
goto V_140;
}
static int F_163 ( struct V_39 * V_40 ,
struct V_25 * V_26 ,
unsigned long V_65 ,
struct V_60 * * V_97 )
{
T_7 * V_113 ;
T_4 * V_62 , * V_63 ;
int V_115 = 0 , V_66 = 0 , V_67 = 0 , V_68 = 0 ;
struct V_60 * V_60 = NULL ;
unsigned long V_141 ;
T_5 * V_81 ;
int V_99 = V_94 , V_142 = 0 ;
bool V_69 = false ;
F_118 ( V_65 & ~ V_57 ) ;
V_113 = F_134 ( V_40 , V_65 ) ;
if ( ! V_113 ) {
V_67 = V_137 ;
goto V_72;
}
memset ( V_88 , 0 , sizeof( V_88 ) ) ;
V_62 = F_164 ( V_40 , V_113 , V_65 , & V_81 ) ;
for ( V_141 = V_65 , V_63 = V_62 ; V_63 < V_62 + V_22 ;
V_63 ++ , V_141 += V_70 ) {
T_4 V_64 = * V_63 ;
if ( F_131 ( V_64 ) ) {
if ( ++ V_142 <= V_23 ) {
continue;
} else {
V_67 = V_143 ;
goto V_144;
}
}
if ( F_60 ( V_64 ) || F_61 ( F_62 ( V_64 ) ) ) {
if ( ! F_66 ( V_26 ) &&
++ V_66 <= V_20 ) {
continue;
} else {
V_67 = V_71 ;
goto V_144;
}
}
if ( ! F_65 ( V_64 ) ) {
V_67 = V_73 ;
goto V_144;
}
if ( F_75 ( V_64 ) )
V_69 = true ;
V_60 = F_67 ( V_26 , V_141 , V_64 ) ;
if ( F_40 ( ! V_60 ) ) {
V_67 = V_74 ;
goto V_144;
}
if ( F_69 ( V_60 ) ) {
V_67 = V_145 ;
goto V_144;
}
V_99 = F_165 ( V_60 ) ;
if ( F_101 ( V_99 ) ) {
V_67 = V_146 ;
goto V_144;
}
V_88 [ V_99 ] ++ ;
if ( ! F_80 ( V_60 ) ) {
V_67 = V_147 ;
goto V_144;
}
if ( F_79 ( V_60 ) ) {
V_67 = V_75 ;
goto V_144;
}
if ( ! F_70 ( V_60 ) ) {
V_67 = V_148 ;
goto V_144;
}
if ( F_73 ( V_60 ) != 1 + ! ! F_74 ( V_60 ) ) {
V_67 = V_76 ;
goto V_144;
}
if ( F_81 ( V_64 ) ||
F_82 ( V_60 ) || F_83 ( V_60 ) ||
F_84 ( V_26 -> V_30 , V_65 ) )
V_68 ++ ;
}
if ( V_69 ) {
if ( V_68 ) {
V_67 = V_79 ;
V_115 = 1 ;
} else {
V_67 = V_149 ;
}
} else {
V_67 = V_80 ;
}
V_144:
F_166 ( V_62 , V_81 ) ;
if ( V_115 ) {
V_99 = F_105 () ;
F_136 ( V_40 , V_65 , V_97 , V_99 , V_68 ) ;
}
V_72:
F_167 ( V_40 , V_60 , V_69 , V_68 ,
V_66 , V_67 , V_142 ) ;
return V_115 ;
}
static void F_168 ( struct V_37 * V_37 )
{
struct V_39 * V_40 = V_37 -> V_40 ;
F_118 ( V_150 != 1 && ! F_169 ( & V_47 ) ) ;
if ( F_36 ( V_40 ) ) {
F_49 ( & V_37 -> V_42 ) ;
F_50 ( & V_37 -> V_50 ) ;
F_30 ( V_37 ) ;
F_52 ( V_40 ) ;
}
}
static void F_170 ( struct V_151 * V_152 , T_9 V_119 )
{
struct V_25 * V_26 ;
unsigned long V_153 ;
T_7 * V_113 , V_123 ;
F_171 ( V_152 ) ;
F_172 (vma, &mapping->i_mmap, pgoff, pgoff) {
if ( V_26 -> V_54 )
continue;
V_153 = V_26 -> V_56 + ( ( V_119 - V_26 -> V_106 ) << V_105 ) ;
if ( V_153 & ~ V_57 )
continue;
if ( V_26 -> V_58 < V_153 + V_110 )
continue;
V_113 = F_134 ( V_26 -> V_30 , V_153 ) ;
if ( ! V_113 )
continue;
if ( F_173 ( & V_26 -> V_30 -> V_59 ) ) {
T_5 * V_81 = F_143 ( V_26 -> V_30 , V_113 ) ;
V_123 = F_144 ( V_26 , V_153 , V_113 ) ;
F_45 ( V_81 ) ;
F_54 ( & V_26 -> V_30 -> V_59 ) ;
F_174 ( & V_26 -> V_30 -> V_154 ) ;
F_175 ( V_26 -> V_30 , F_149 ( V_123 ) ) ;
}
}
F_176 ( V_152 ) ;
}
static void F_177 ( struct V_39 * V_40 ,
struct V_151 * V_152 , T_9 V_155 ,
struct V_60 * * V_97 , int V_99 )
{
T_6 V_98 ;
struct V_60 * V_60 , * V_125 , * V_156 ;
struct V_129 * V_130 ;
T_9 V_157 , V_158 = V_155 + V_22 ;
F_178 ( V_159 ) ;
struct V_160 V_161 ;
void * * V_162 ;
int V_163 = 0 , V_67 = V_79 ;
F_118 ( V_155 & ( V_22 - 1 ) ) ;
V_98 = F_103 () | V_133 ;
V_125 = F_109 ( V_97 , V_98 , V_99 ) ;
if ( ! V_125 ) {
V_67 = V_134 ;
goto V_72;
}
if ( F_40 ( F_138 ( V_125 , V_40 , V_98 , & V_130 , true ) ) ) {
V_67 = V_136 ;
goto V_72;
}
V_125 -> V_157 = V_155 ;
V_125 -> V_152 = V_152 ;
F_179 ( V_125 ) ;
F_180 ( V_125 ) ;
F_146 ( ! F_181 ( V_125 , 1 ) ) ;
V_157 = V_155 ;
F_182 ( & V_152 -> V_164 ) ;
F_183 (slot, &mapping->page_tree, &iter, start) {
int V_165 = F_184 ( V_161 . V_157 , V_158 ) - V_157 ;
if ( V_165 && ! F_185 ( V_152 -> V_166 , V_165 ) ) {
V_67 = V_138 ;
break;
}
V_163 += V_165 ;
for (; V_157 < F_184 ( V_161 . V_157 , V_158 ) ; V_157 ++ ) {
F_186 ( & V_152 -> V_167 , V_157 ,
V_125 + ( V_157 % V_22 ) ) ;
}
if ( V_157 >= V_158 )
break;
V_60 = F_187 ( V_162 ,
& V_152 -> V_164 ) ;
if ( F_188 ( V_60 ) || ! F_189 ( V_60 ) ) {
F_190 ( & V_152 -> V_164 ) ;
if ( F_191 ( V_152 -> V_166 , V_157 , & V_60 ,
V_168 ) ) {
V_67 = V_138 ;
goto V_169;
}
F_182 ( & V_152 -> V_164 ) ;
} else if ( F_72 ( V_60 ) ) {
F_192 ( V_60 ) ;
} else {
V_67 = V_75 ;
break;
}
F_68 ( ! F_79 ( V_60 ) , V_60 ) ;
F_68 ( ! F_189 ( V_60 ) , V_60 ) ;
F_68 ( F_193 ( V_60 ) , V_60 ) ;
if ( F_194 ( V_60 ) != V_152 ) {
V_67 = V_170 ;
goto V_171;
}
F_190 ( & V_152 -> V_164 ) ;
if ( F_77 ( V_60 ) ) {
V_67 = V_78 ;
goto V_172;
}
if ( F_195 ( V_60 ) )
F_196 ( V_152 , V_157 << V_105 ,
V_70 , 0 ) ;
F_182 ( & V_152 -> V_164 ) ;
V_162 = F_197 ( & V_152 -> V_167 , V_157 ) ;
F_68 ( V_60 != F_187 ( V_162 ,
& V_152 -> V_164 ) , V_60 ) ;
F_68 ( F_195 ( V_60 ) , V_60 ) ;
if ( ! F_181 ( V_60 , 3 ) ) {
V_67 = V_76 ;
goto V_173;
}
F_44 ( & V_60 -> V_174 , & V_159 ) ;
F_198 ( & V_152 -> V_167 , V_162 ,
V_125 + ( V_157 % V_22 ) ) ;
V_162 = F_199 ( V_162 , & V_161 ) ;
V_157 ++ ;
continue;
V_173:
F_190 ( & V_152 -> V_164 ) ;
F_58 ( V_60 ) ;
V_172:
F_57 ( V_60 ) ;
F_108 ( V_60 ) ;
goto V_169;
V_171:
F_57 ( V_60 ) ;
F_108 ( V_60 ) ;
break;
}
if ( V_67 == V_79 && V_157 < V_158 ) {
int V_165 = V_158 - V_157 ;
if ( ! F_185 ( V_152 -> V_166 , V_165 ) ) {
V_67 = V_138 ;
goto V_175;
}
for (; V_157 < V_158 ; V_157 ++ ) {
F_186 ( & V_152 -> V_167 , V_157 ,
V_125 + ( V_157 % V_22 ) ) ;
}
V_163 += V_165 ;
}
V_175:
F_190 ( & V_152 -> V_164 ) ;
V_169:
if ( V_67 == V_79 ) {
unsigned long V_46 ;
struct V_176 * V_176 = F_200 ( V_125 ) ;
F_201 (page, tmp, &pagelist, lru) {
F_202 ( V_125 + ( V_60 -> V_157 % V_22 ) ,
V_60 ) ;
F_50 ( & V_60 -> V_174 ) ;
F_57 ( V_60 ) ;
F_203 ( V_60 , 1 ) ;
V_60 -> V_152 = NULL ;
F_204 ( V_60 ) ;
F_205 ( V_60 ) ;
F_108 ( V_60 ) ;
}
F_206 ( V_46 ) ;
F_207 ( V_125 , V_177 ) ;
if ( V_163 ) {
F_208 ( V_176 -> V_178 , V_179 , V_163 ) ;
F_208 ( V_176 -> V_178 , V_180 , V_163 ) ;
}
F_209 ( V_46 ) ;
F_170 ( V_152 , V_155 ) ;
F_210 ( V_125 ) ;
F_211 ( V_125 ) ;
F_203 ( V_125 , V_22 ) ;
F_157 ( V_125 , V_130 , false , true ) ;
F_212 ( V_125 ) ;
F_57 ( V_125 ) ;
* V_97 = NULL ;
} else {
F_213 ( V_152 -> V_166 , V_163 ) ;
F_182 ( & V_152 -> V_164 ) ;
F_183 (slot, &mapping->page_tree, &iter,
start) {
if ( V_161 . V_157 >= V_158 )
break;
V_60 = F_214 ( & V_159 ,
struct V_60 , V_174 ) ;
if ( ! V_60 || V_161 . V_157 < V_60 -> V_157 ) {
if ( ! V_163 )
break;
V_163 -- ;
F_215 ( & V_152 -> V_167 ,
V_161 . V_157 ) ;
continue;
}
F_68 ( V_60 -> V_157 != V_161 . V_157 , V_60 ) ;
F_50 ( & V_60 -> V_174 ) ;
F_203 ( V_60 , 2 ) ;
F_198 ( & V_152 -> V_167 ,
V_162 , V_60 ) ;
V_162 = F_199 ( V_162 , & V_161 ) ;
F_190 ( & V_152 -> V_164 ) ;
F_58 ( V_60 ) ;
F_57 ( V_60 ) ;
F_182 ( & V_152 -> V_164 ) ;
}
F_118 ( V_163 ) ;
F_190 ( & V_152 -> V_164 ) ;
F_203 ( V_125 , 1 ) ;
F_139 ( V_125 , V_130 , true ) ;
F_57 ( V_125 ) ;
V_125 -> V_152 = NULL ;
}
V_72:
F_118 ( ! F_43 ( & V_159 ) ) ;
}
static void F_216 ( struct V_39 * V_40 ,
struct V_151 * V_152 ,
T_9 V_155 , struct V_60 * * V_97 )
{
struct V_60 * V_60 = NULL ;
struct V_160 V_161 ;
void * * V_162 ;
int V_181 , V_182 ;
int V_99 = V_94 ;
int V_67 = V_79 ;
V_181 = 0 ;
V_182 = 0 ;
memset ( V_88 , 0 , sizeof( V_88 ) ) ;
F_217 () ;
F_183 (slot, &mapping->page_tree, &iter, start) {
if ( V_161 . V_157 >= V_155 + V_22 )
break;
V_60 = F_218 ( V_162 ) ;
if ( F_219 ( V_60 ) ) {
V_162 = F_220 ( & V_161 ) ;
continue;
}
if ( F_221 ( V_60 ) ) {
if ( ++ V_182 > V_23 ) {
V_67 = V_143 ;
break;
}
continue;
}
if ( F_193 ( V_60 ) ) {
V_67 = V_145 ;
break;
}
V_99 = F_165 ( V_60 ) ;
if ( F_101 ( V_99 ) ) {
V_67 = V_146 ;
break;
}
V_88 [ V_99 ] ++ ;
if ( ! F_80 ( V_60 ) ) {
V_67 = V_147 ;
break;
}
if ( F_73 ( V_60 ) != 1 + F_92 ( V_60 ) ) {
V_67 = V_76 ;
break;
}
V_181 ++ ;
if ( F_222 () ) {
V_162 = F_199 ( V_162 , & V_161 ) ;
F_223 () ;
}
}
F_224 () ;
if ( V_67 == V_79 ) {
if ( V_181 < V_22 - V_20 ) {
V_67 = V_71 ;
} else {
V_99 = F_105 () ;
F_177 ( V_40 , V_152 , V_155 , V_97 , V_99 ) ;
}
}
}
static void F_216 ( struct V_39 * V_40 ,
struct V_151 * V_152 ,
T_9 V_155 , struct V_60 * * V_97 )
{
F_225 () ;
}
static unsigned int F_226 ( unsigned int V_16 ,
struct V_60 * * V_97 )
__releases( &khugepaged_mm_lock
static int F_227 ( void )
{
return ! F_43 ( & V_48 . V_49 ) &&
F_117 () ;
}
static int F_228 ( void )
{
return ! F_43 ( & V_48 . V_49 ) ||
F_229 () ;
}
static void F_230 ( void )
{
struct V_60 * V_97 = NULL ;
unsigned int V_183 = 0 , V_184 = 0 ;
unsigned int V_16 = V_15 ;
bool V_84 = true ;
F_231 () ;
while ( V_183 < V_16 ) {
if ( ! F_106 ( & V_97 , & V_84 ) )
break;
F_232 () ;
if ( F_40 ( F_229 () || F_233 () ) )
break;
F_42 ( & V_47 ) ;
if ( ! V_48 . V_37 )
V_184 ++ ;
if ( F_227 () &&
V_184 < 2 )
V_183 += F_226 ( V_16 - V_183 ,
& V_97 ) ;
else
V_183 = V_16 ;
F_45 ( & V_47 ) ;
}
if ( ! F_234 ( V_97 ) )
F_108 ( V_97 ) ;
}
static bool F_235 ( void )
{
return F_229 () ||
F_236 ( V_185 , V_12 ) ;
}
static void F_237 ( void )
{
if ( F_227 () ) {
const unsigned long V_186 =
F_99 ( V_6 ) ;
if ( ! V_186 )
return;
V_12 = V_185 + V_186 ;
F_238 ( V_13 ,
F_235 () ,
V_186 ) ;
return;
}
if ( F_117 () )
F_239 ( V_13 , F_228 () ) ;
}
static int F_240 ( void * V_187 )
{
struct V_37 * V_37 ;
F_241 () ;
F_242 ( V_188 , V_189 ) ;
while ( ! F_229 () ) {
F_230 () ;
F_237 () ;
}
F_42 ( & V_47 ) ;
V_37 = V_48 . V_37 ;
V_48 . V_37 = NULL ;
if ( V_37 )
F_168 ( V_37 ) ;
F_45 ( & V_47 ) ;
return 0 ;
}
static void F_243 ( void )
{
struct V_176 * V_176 ;
int V_190 = 0 ;
unsigned long V_191 ;
F_244 (zone)
V_190 ++ ;
V_191 = V_192 * V_190 * 2 ;
V_191 += V_192 * V_190 *
V_193 * V_193 ;
V_191 = F_184 ( V_191 ,
( unsigned long ) F_245 () / 20 ) ;
V_191 <<= ( V_105 - 10 ) ;
if ( V_191 > V_194 ) {
if ( V_195 >= 0 )
F_246 ( L_3 ,
V_194 , V_191 ) ;
V_194 = V_191 ;
}
F_247 () ;
}
int F_248 ( void )
{
static struct V_196 * T_10 V_197 ;
static F_249 ( V_198 ) ;
int V_9 = 0 ;
F_250 ( & V_198 ) ;
if ( F_117 () ) {
if ( ! T_10 )
T_10 = F_251 ( F_240 , NULL ,
L_4 ) ;
if ( F_107 ( T_10 ) ) {
F_252 ( L_5 ) ;
V_9 = F_253 ( T_10 ) ;
T_10 = NULL ;
goto V_199;
}
if ( ! F_43 ( & V_48 . V_49 ) )
F_4 ( & V_13 ) ;
F_243 () ;
} else if ( T_10 ) {
F_254 ( T_10 ) ;
T_10 = NULL ;
}
V_199:
F_255 ( & V_198 ) ;
return V_9 ;
}
