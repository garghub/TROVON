static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_2 ( F_3 ( V_2 ) ^ V_3 , F_4 ( V_4 ) ) ;
}
static struct V_5 * F_5 ( struct V_6 * V_7 ,
struct V_1 * V_2 ,
T_1 V_8 )
{
struct V_5 * V_9 ;
F_6 (timer, head, t_hash) {
if ( ( V_9 -> V_10 == V_2 ) && ( V_9 -> V_11 == V_8 ) )
return V_9 ;
}
return NULL ;
}
static struct V_5 * F_7 ( T_1 V_8 )
{
struct V_1 * V_2 = V_12 -> signal ;
struct V_6 * V_7 = & V_4 [ F_1 ( V_2 , V_8 ) ] ;
return F_5 ( V_7 , V_2 , V_8 ) ;
}
static int F_8 ( struct V_5 * V_9 )
{
struct V_1 * V_2 = V_12 -> signal ;
int V_13 = V_2 -> V_14 ;
struct V_6 * V_7 ;
int V_15 = - V_16 ;
do {
F_9 ( & V_17 ) ;
V_7 = & V_4 [ F_1 ( V_2 , V_2 -> V_14 ) ] ;
if ( ! F_5 ( V_7 , V_2 , V_2 -> V_14 ) ) {
F_10 ( & V_9 -> V_18 , V_7 ) ;
V_15 = V_2 -> V_14 ;
}
if ( ++ V_2 -> V_14 < 0 )
V_2 -> V_14 = 0 ;
if ( ( V_2 -> V_14 == V_13 ) && ( V_15 == - V_16 ) )
V_15 = - V_19 ;
F_11 ( & V_17 ) ;
} while ( V_15 == - V_16 );
return V_15 ;
}
static inline void F_12 ( struct V_5 * V_20 , unsigned long V_21 )
{
F_13 ( & V_20 -> V_22 , V_21 ) ;
}
static int F_14 ( T_2 V_23 , struct V_24 * V_25 )
{
F_15 ( V_25 ) ;
return 0 ;
}
static int F_16 ( const T_2 V_23 ,
const struct V_24 * V_25 )
{
return F_17 ( V_25 , NULL ) ;
}
static int F_18 ( const T_2 V_23 ,
struct V_26 * V_27 )
{
return F_19 ( V_27 ) ;
}
static int F_20 ( T_2 V_23 , struct V_24 * V_25 )
{
F_21 ( V_25 ) ;
return 0 ;
}
static int F_22 ( T_2 V_23 , struct V_24 * V_25 )
{
F_23 ( V_25 ) ;
return 0 ;
}
static int F_24 ( T_2 V_23 , struct V_24 * V_25 )
{
* V_25 = F_25 () ;
return 0 ;
}
static int F_26 ( T_2 V_23 ,
struct V_24 * V_25 )
{
* V_25 = F_27 () ;
return 0 ;
}
static int F_28 ( const T_2 V_23 , struct V_24 * V_25 )
{
* V_25 = F_29 ( V_28 ) ;
return 0 ;
}
static int F_30 ( const T_2 V_23 , struct V_24 * V_25 )
{
F_31 ( V_25 ) ;
return 0 ;
}
static int F_32 ( T_2 V_23 , struct V_24 * V_25 )
{
F_33 ( V_25 ) ;
return 0 ;
}
static int F_34 ( T_2 V_23 , struct V_24 * V_25 )
{
V_25 -> V_29 = 0 ;
V_25 -> V_30 = V_31 ;
return 0 ;
}
static T_3 int F_35 ( void )
{
V_32 = F_36 ( L_1 ,
sizeof ( struct V_5 ) , 0 , V_33 ,
NULL ) ;
return 0 ;
}
static void F_37 ( struct V_5 * V_20 )
{
struct V_34 * V_9 = & V_20 -> V_35 . V_36 . V_9 ;
if ( ! V_20 -> V_37 )
return;
V_20 -> V_38 += ( unsigned int ) F_38 ( V_9 ,
V_9 -> V_39 -> V_40 () ,
V_20 -> V_37 ) ;
F_39 ( V_9 ) ;
}
void F_40 ( struct V_41 * V_42 )
{
struct V_5 * V_20 ;
unsigned long V_21 ;
V_20 = F_41 ( V_42 -> V_43 , & V_21 ) ;
if ( ! V_20 )
return;
if ( V_20 -> V_44 == V_42 -> V_45 ) {
V_20 -> V_46 -> V_47 ( V_20 ) ;
V_20 -> V_48 = 1 ;
V_20 -> V_49 = V_20 -> V_38 ;
V_20 -> V_38 = - 1 ;
++ V_20 -> V_44 ;
V_42 -> V_50 += V_20 -> V_49 ;
}
F_12 ( V_20 , V_21 ) ;
}
int F_42 ( struct V_5 * V_20 , int V_51 )
{
struct V_52 * V_53 ;
int V_54 , V_15 = - 1 ;
V_20 -> V_55 -> V_42 . V_45 = V_51 ;
F_43 () ;
V_53 = F_44 ( V_20 -> V_56 , V_57 ) ;
if ( V_53 ) {
V_54 = ! ( V_20 -> V_58 & V_59 ) ;
V_15 = F_45 ( V_20 -> V_55 , V_53 , V_54 ) ;
}
F_46 () ;
return V_15 > 0 ;
}
static enum F_39 F_47 ( struct V_34 * V_9 )
{
struct V_5 * V_20 ;
unsigned long V_21 ;
int V_51 = 0 ;
enum F_39 V_15 = V_60 ;
V_20 = F_48 ( V_9 , struct V_5 , V_35 . V_36 . V_9 ) ;
F_49 ( & V_20 -> V_22 , V_21 ) ;
V_20 -> V_48 = 0 ;
if ( V_20 -> V_37 != 0 )
V_51 = ++ V_20 -> V_44 ;
if ( F_42 ( V_20 , V_51 ) ) {
if ( V_20 -> V_37 != 0 ) {
T_4 V_61 = F_50 ( V_9 ) ;
#ifdef F_51
{
T_4 V_62 = V_63 / V_64 ;
if ( V_20 -> V_37 < V_62 )
V_61 = F_52 ( V_61 , V_62 ) ;
}
#endif
V_20 -> V_38 += ( unsigned int )
F_38 ( V_9 , V_61 ,
V_20 -> V_37 ) ;
V_15 = V_65 ;
++ V_20 -> V_44 ;
V_20 -> V_48 = 1 ;
}
}
F_12 ( V_20 , V_21 ) ;
return V_15 ;
}
static struct V_66 * F_53 ( T_5 * V_67 )
{
struct V_52 * V_68 = V_12 -> V_69 ;
if ( ( V_67 -> V_70 & V_59 ) &&
( ! ( V_68 = F_54 ( V_67 -> V_71 ) ) ||
! F_55 ( V_68 , V_12 ) ||
( V_67 -> V_70 & ~ V_59 ) != V_72 ) )
return NULL ;
if ( ( ( V_67 -> V_70 & ~ V_59 ) != V_73 ) &&
( ( V_67 -> V_74 <= 0 ) || ( V_67 -> V_74 > V_75 ) ) )
return NULL ;
return F_56 ( V_68 ) ;
}
static struct V_5 * F_57 ( void )
{
struct V_5 * V_76 ;
V_76 = F_58 ( V_32 , V_77 ) ;
if ( ! V_76 )
return V_76 ;
if ( F_59 ( ! ( V_76 -> V_55 = F_60 () ) ) ) {
F_61 ( V_32 , V_76 ) ;
return NULL ;
}
memset ( & V_76 -> V_55 -> V_42 , 0 , sizeof( V_78 ) ) ;
return V_76 ;
}
static void F_62 ( struct V_79 * V_7 )
{
struct V_5 * V_76 = F_48 ( V_7 , struct V_5 , V_35 . V_80 ) ;
F_61 ( V_32 , V_76 ) ;
}
static void F_63 ( struct V_5 * V_76 , int V_81 )
{
if ( V_81 ) {
unsigned long V_21 ;
F_49 ( & V_17 , V_21 ) ;
F_64 ( & V_76 -> V_18 ) ;
F_13 ( & V_17 , V_21 ) ;
}
F_65 ( V_76 -> V_56 ) ;
F_66 ( V_76 -> V_55 ) ;
F_67 ( & V_76 -> V_35 . V_80 , F_62 ) ;
}
static int F_68 ( struct V_5 * V_82 )
{
F_69 ( & V_82 -> V_35 . V_36 . V_9 , V_82 -> V_83 , 0 ) ;
return 0 ;
}
static int F_70 ( T_2 V_23 , struct V_84 * V_67 ,
T_1 T_6 * V_85 )
{
const struct V_86 * V_87 = F_71 ( V_23 ) ;
struct V_5 * V_82 ;
int error , V_88 ;
int V_81 = V_89 ;
if ( ! V_87 )
return - V_90 ;
if ( ! V_87 -> V_91 )
return - V_92 ;
V_82 = F_57 () ;
if ( F_59 ( ! V_82 ) )
return - V_19 ;
F_72 ( & V_82 -> V_22 ) ;
V_88 = F_8 ( V_82 ) ;
if ( V_88 < 0 ) {
error = V_88 ;
goto V_93;
}
V_81 = V_94 ;
V_82 -> V_11 = ( T_1 ) V_88 ;
V_82 -> V_83 = V_23 ;
V_82 -> V_46 = V_87 ;
V_82 -> V_38 = - 1 ;
if ( V_67 ) {
F_43 () ;
V_82 -> V_56 = F_73 ( F_53 ( V_67 ) ) ;
F_46 () ;
if ( ! V_82 -> V_56 ) {
error = - V_90 ;
goto V_93;
}
V_82 -> V_58 = V_67 -> V_70 ;
V_82 -> V_55 -> V_42 . V_95 = V_67 -> V_74 ;
V_82 -> V_55 -> V_42 . V_96 = V_67 -> V_97 ;
} else {
V_82 -> V_58 = V_72 ;
V_82 -> V_55 -> V_42 . V_95 = V_98 ;
memset ( & V_82 -> V_55 -> V_42 . V_96 , 0 , sizeof( V_99 ) ) ;
V_82 -> V_55 -> V_42 . V_96 . V_100 = V_82 -> V_11 ;
V_82 -> V_56 = F_73 ( F_74 ( V_12 ) ) ;
}
V_82 -> V_55 -> V_42 . V_43 = V_82 -> V_11 ;
V_82 -> V_55 -> V_42 . V_101 = V_102 ;
if ( F_75 ( V_85 ,
& V_88 , sizeof ( V_88 ) ) ) {
error = - V_103 ;
goto V_93;
}
error = V_87 -> V_91 ( V_82 ) ;
if ( error )
goto V_93;
F_76 ( & V_12 -> V_104 -> V_105 ) ;
V_82 -> V_10 = V_12 -> signal ;
F_77 ( & V_82 -> V_106 , & V_12 -> signal -> V_107 ) ;
F_78 ( & V_12 -> V_104 -> V_105 ) ;
return 0 ;
V_93:
F_63 ( V_82 , V_81 ) ;
return error ;
}
static struct V_5 * F_79 ( T_1 V_108 , unsigned long * V_21 )
{
struct V_5 * V_20 ;
if ( ( unsigned long long ) V_108 > V_109 )
return NULL ;
F_43 () ;
V_20 = F_7 ( V_108 ) ;
if ( V_20 ) {
F_49 ( & V_20 -> V_22 , * V_21 ) ;
if ( V_20 -> V_10 == V_12 -> signal ) {
F_46 () ;
return V_20 ;
}
F_13 ( & V_20 -> V_22 , * V_21 ) ;
}
F_46 () ;
return NULL ;
}
static T_4 F_80 ( struct V_5 * V_20 , T_4 V_61 )
{
struct V_34 * V_9 = & V_20 -> V_35 . V_36 . V_9 ;
return F_81 ( V_9 , V_61 ) ;
}
static int F_82 ( struct V_5 * V_20 , T_4 V_61 )
{
struct V_34 * V_9 = & V_20 -> V_35 . V_36 . V_9 ;
return ( int ) F_38 ( V_9 , V_61 , V_20 -> V_37 ) ;
}
void F_83 ( struct V_5 * V_20 , struct V_110 * V_111 )
{
const struct V_86 * V_87 = V_20 -> V_46 ;
T_4 V_61 , V_112 , V_113 ;
struct V_24 V_114 ;
bool V_115 ;
V_115 = ( V_20 -> V_58 & ~ V_59 ) == V_73 ;
V_113 = V_20 -> V_37 ;
if ( V_113 ) {
V_111 -> V_37 = F_29 ( V_113 ) ;
} else if ( ! V_20 -> V_48 ) {
if ( ! V_115 )
return;
}
V_87 -> V_116 ( V_20 -> V_83 , & V_114 ) ;
V_61 = F_84 ( V_114 ) ;
if ( V_113 && ( V_20 -> V_44 & V_117 || V_115 ) )
V_20 -> V_38 += V_87 -> V_118 ( V_20 , V_61 ) ;
V_112 = V_87 -> V_119 ( V_20 , V_61 ) ;
if ( V_112 <= 0 ) {
if ( ! V_115 )
V_111 -> V_120 . V_30 = 1 ;
} else {
V_111 -> V_120 = F_29 ( V_112 ) ;
}
}
static int F_85 ( T_1 V_108 , struct V_110 * V_121 )
{
struct V_5 * V_20 ;
const struct V_86 * V_87 ;
unsigned long V_21 ;
int V_15 = 0 ;
V_20 = F_41 ( V_108 , & V_21 ) ;
if ( ! V_20 )
return - V_90 ;
memset ( V_121 , 0 , sizeof( * V_121 ) ) ;
V_87 = V_20 -> V_46 ;
if ( F_86 ( ! V_87 || ! V_87 -> V_122 ) )
V_15 = - V_90 ;
else
V_87 -> V_122 ( V_20 , V_121 ) ;
F_12 ( V_20 , V_21 ) ;
return V_15 ;
}
static void F_87 ( struct V_5 * V_20 , T_4 V_123 ,
bool V_124 , bool V_125 )
{
struct V_34 * V_9 = & V_20 -> V_35 . V_36 . V_9 ;
enum V_126 V_127 ;
V_127 = V_124 ? V_128 : V_129 ;
if ( V_20 -> V_83 == V_130 )
V_20 -> V_46 = V_124 ? & V_131 : & V_132 ;
F_69 ( & V_20 -> V_35 . V_36 . V_9 , V_20 -> V_83 , V_127 ) ;
V_20 -> V_35 . V_36 . V_9 . V_133 = F_47 ;
if ( ! V_124 )
V_123 = F_88 ( V_123 , V_9 -> V_39 -> V_40 () ) ;
F_89 ( V_9 , V_123 ) ;
if ( ! V_125 )
F_90 ( V_9 , V_128 ) ;
}
static int F_91 ( struct V_5 * V_20 )
{
return F_92 ( & V_20 -> V_35 . V_36 . V_9 ) ;
}
int F_93 ( struct V_5 * V_20 , int V_21 ,
struct V_110 * V_134 ,
struct V_110 * V_135 )
{
const struct V_86 * V_87 = V_20 -> V_46 ;
bool V_125 ;
T_4 V_123 ;
if ( V_135 )
F_83 ( V_20 , V_135 ) ;
V_20 -> V_37 = 0 ;
if ( V_87 -> V_136 ( V_20 ) < 0 )
return V_137 ;
V_20 -> V_48 = 0 ;
V_20 -> V_44 = ( V_20 -> V_44 + 2 ) &
~ V_117 ;
V_20 -> V_49 = 0 ;
if ( ! V_134 -> V_120 . V_29 && ! V_134 -> V_120 . V_30 )
return 0 ;
V_20 -> V_37 = F_84 ( V_134 -> V_37 ) ;
V_123 = F_84 ( V_134 -> V_120 ) ;
V_125 = ( V_20 -> V_58 & ~ V_59 ) == V_73 ;
V_87 -> V_138 ( V_20 , V_123 , V_21 & V_139 , V_125 ) ;
V_20 -> V_48 = ! V_125 ;
return 0 ;
}
static int F_94 ( T_1 V_108 , int V_21 ,
struct V_110 * V_140 ,
struct V_110 * V_141 )
{
const struct V_86 * V_87 ;
struct V_5 * V_20 ;
unsigned long V_142 ;
int error = 0 ;
if ( ! F_95 ( & V_140 -> V_37 ) ||
! F_95 ( & V_140 -> V_120 ) )
return - V_90 ;
if ( V_141 )
memset ( V_141 , 0 , sizeof( * V_141 ) ) ;
V_143:
V_20 = F_41 ( V_108 , & V_142 ) ;
if ( ! V_20 )
return - V_90 ;
V_87 = V_20 -> V_46 ;
if ( F_86 ( ! V_87 || ! V_87 -> V_144 ) )
error = - V_90 ;
else
error = V_87 -> V_144 ( V_20 , V_21 , V_140 , V_141 ) ;
F_12 ( V_20 , V_142 ) ;
if ( error == V_137 ) {
V_141 = NULL ;
goto V_143;
}
return error ;
}
int F_96 ( struct V_5 * V_9 )
{
const struct V_86 * V_87 = V_9 -> V_46 ;
V_9 -> V_37 = 0 ;
if ( V_87 -> V_136 ( V_9 ) < 0 )
return V_137 ;
V_9 -> V_48 = 0 ;
return 0 ;
}
static inline int F_97 ( struct V_5 * V_9 )
{
const struct V_86 * V_87 = V_9 -> V_46 ;
if ( F_86 ( ! V_87 || ! V_87 -> V_145 ) )
return - V_90 ;
return V_87 -> V_145 ( V_9 ) ;
}
static void F_98 ( struct V_5 * V_9 )
{
unsigned long V_21 ;
V_146:
F_49 ( & V_9 -> V_22 , V_21 ) ;
if ( F_97 ( V_9 ) == V_137 ) {
F_12 ( V_9 , V_21 ) ;
goto V_146;
}
F_99 ( & V_9 -> V_106 ) ;
V_9 -> V_10 = NULL ;
F_12 ( V_9 , V_21 ) ;
F_63 ( V_9 , V_94 ) ;
}
void F_100 ( struct V_1 * V_2 )
{
struct V_5 * V_76 ;
while ( ! F_101 ( & V_2 -> V_107 ) ) {
V_76 = F_102 ( V_2 -> V_107 . V_147 , struct V_5 , V_106 ) ;
F_98 ( V_76 ) ;
}
}
static int F_103 ( const T_2 V_23 , int V_21 ,
const struct V_24 * V_148 )
{
return F_104 ( V_148 , V_21 & V_139 ?
V_128 : V_129 ,
V_23 ) ;
}
static const struct V_86 * F_71 ( const T_2 V_8 )
{
if ( V_8 < 0 )
return ( V_8 & V_149 ) == V_150 ?
& V_151 : & V_152 ;
if ( V_8 >= F_105 ( V_153 ) || ! V_153 [ V_8 ] )
return NULL ;
return V_153 [ V_8 ] ;
}
