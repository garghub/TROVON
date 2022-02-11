static struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
V_3:
if ( F_2 ( F_3 ( & V_4 ) ) )
return F_4 ( V_5 ) ;
V_2 = F_5 ( ( V_6 | V_7 ) & ~ V_8 ,
V_9 ) ;
if ( ! V_2 ) {
F_6 ( V_10 ) ;
return NULL ;
}
F_6 ( V_11 ) ;
F_7 () ;
if ( F_8 ( & V_5 , NULL , V_2 ) ) {
F_9 () ;
F_10 ( V_2 , F_11 ( V_2 ) ) ;
goto V_3;
}
F_12 ( & V_4 , 2 ) ;
F_9 () ;
return F_4 ( V_5 ) ;
}
static void F_13 ( void )
{
F_14 ( F_15 ( & V_4 ) ) ;
}
struct V_1 * F_16 ( struct V_12 * V_13 )
{
if ( F_17 ( V_14 , & V_13 -> V_15 ) )
return F_4 ( V_5 ) ;
if ( ! F_1 () )
return NULL ;
if ( F_18 ( V_14 , & V_13 -> V_15 ) )
F_13 () ;
return F_4 ( V_5 ) ;
}
void F_19 ( struct V_12 * V_13 )
{
if ( F_17 ( V_14 , & V_13 -> V_15 ) )
F_13 () ;
}
static unsigned long F_20 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
return F_21 ( & V_4 ) == 1 ? V_20 : 0 ;
}
static unsigned long F_22 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
if ( F_23 ( & V_4 , 1 , 0 ) == 1 ) {
struct V_1 * V_2 = F_24 ( & V_5 , NULL ) ;
F_14 ( V_2 == NULL ) ;
F_10 ( V_2 , F_11 ( V_2 ) ) ;
return V_20 ;
}
return 0 ;
}
static T_1 F_25 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
const char * V_25 , T_2 V_26 ,
enum V_27 V_28 ,
enum V_27 V_29 ,
enum V_27 V_30 )
{
if ( ! memcmp ( L_1 , V_25 ,
F_26 ( sizeof( L_1 ) - 1 , V_26 ) ) ) {
if ( V_28 == V_29 )
return - V_31 ;
F_27 ( V_28 , & V_32 ) ;
F_27 ( V_30 , & V_32 ) ;
F_28 ( V_29 , & V_32 ) ;
} else if ( ! memcmp ( L_2 , V_25 ,
F_26 ( sizeof( L_2 ) - 1 , V_26 ) ) ) {
F_27 ( V_29 , & V_32 ) ;
F_27 ( V_30 , & V_32 ) ;
F_28 ( V_28 , & V_32 ) ;
} else if ( ! memcmp ( L_3 , V_25 ,
F_26 ( sizeof( L_3 ) - 1 , V_26 ) ) ) {
F_27 ( V_28 , & V_32 ) ;
F_27 ( V_29 , & V_32 ) ;
F_28 ( V_30 , & V_32 ) ;
} else if ( ! memcmp ( L_4 , V_25 ,
F_26 ( sizeof( L_4 ) - 1 , V_26 ) ) ) {
F_27 ( V_28 , & V_32 ) ;
F_27 ( V_30 , & V_32 ) ;
F_27 ( V_29 , & V_32 ) ;
} else
return - V_31 ;
return V_26 ;
}
static T_1 F_29 ( struct V_21 * V_22 ,
struct V_23 * V_24 , char * V_25 )
{
if ( F_17 ( V_33 , & V_32 ) )
return sprintf ( V_25 , L_5 ) ;
else if ( F_17 ( V_34 , & V_32 ) )
return sprintf ( V_25 , L_6 ) ;
else
return sprintf ( V_25 , L_7 ) ;
}
static T_1 F_30 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
const char * V_25 , T_2 V_26 )
{
T_1 V_35 ;
V_35 = F_25 ( V_22 , V_24 , V_25 , V_26 ,
V_33 ,
V_33 ,
V_34 ) ;
if ( V_35 > 0 ) {
int V_36 = F_31 () ;
if ( V_36 )
V_35 = V_36 ;
}
return V_35 ;
}
T_1 F_32 ( struct V_21 * V_22 ,
struct V_23 * V_24 , char * V_25 ,
enum V_27 V_37 )
{
return sprintf ( V_25 , L_8 ,
! ! F_17 ( V_37 , & V_32 ) ) ;
}
T_1 F_33 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
const char * V_25 , T_2 V_26 ,
enum V_27 V_37 )
{
unsigned long V_38 ;
int V_35 ;
V_35 = F_34 ( V_25 , 10 , & V_38 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_38 > 1 )
return - V_31 ;
if ( V_38 )
F_28 ( V_37 , & V_32 ) ;
else
F_27 ( V_37 , & V_32 ) ;
return V_26 ;
}
static T_1 F_35 ( struct V_21 * V_22 ,
struct V_23 * V_24 , char * V_25 )
{
if ( F_17 ( V_39 , & V_32 ) )
return sprintf ( V_25 , L_9 ) ;
if ( F_17 ( V_40 , & V_32 ) )
return sprintf ( V_25 , L_10 ) ;
else if ( F_17 ( V_41 , & V_32 ) )
return sprintf ( V_25 , L_11 ) ;
else
return sprintf ( V_25 , L_12 ) ;
}
static T_1 F_36 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
const char * V_25 , T_2 V_26 )
{
return F_25 ( V_22 , V_24 , V_25 , V_26 ,
V_39 ,
V_40 ,
V_41 ) ;
}
static T_1 F_37 ( struct V_21 * V_22 ,
struct V_23 * V_24 , char * V_25 )
{
return F_32 ( V_22 , V_24 , V_25 ,
V_42 ) ;
}
static T_1 F_38 ( struct V_21 * V_22 ,
struct V_23 * V_24 , const char * V_25 , T_2 V_26 )
{
return F_33 ( V_22 , V_24 , V_25 , V_26 ,
V_42 ) ;
}
static T_1 F_39 ( struct V_21 * V_22 ,
struct V_23 * V_24 , char * V_25 )
{
return sprintf ( V_25 , L_13 , V_43 ) ;
}
static T_1 F_40 ( struct V_21 * V_22 ,
struct V_23 * V_24 , char * V_25 )
{
return F_32 ( V_22 , V_24 , V_25 ,
V_44 ) ;
}
static T_1 F_41 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
const char * V_25 , T_2 V_26 )
{
return F_33 ( V_22 , V_24 , V_25 , V_26 ,
V_44 ) ;
}
static int T_3 F_42 ( struct V_21 * * V_45 )
{
int V_36 ;
* V_45 = F_43 ( L_14 , V_46 ) ;
if ( F_44 ( ! * V_45 ) ) {
F_45 ( L_15 ) ;
return - V_47 ;
}
V_36 = F_46 ( * V_45 , & V_48 ) ;
if ( V_36 ) {
F_45 ( L_16 ) ;
goto V_49;
}
V_36 = F_46 ( * V_45 , & V_50 ) ;
if ( V_36 ) {
F_45 ( L_16 ) ;
goto V_51;
}
return 0 ;
V_51:
F_47 ( * V_45 , & V_48 ) ;
V_49:
F_48 ( * V_45 ) ;
return V_36 ;
}
static void T_3 F_49 ( struct V_21 * V_45 )
{
F_47 ( V_45 , & V_50 ) ;
F_47 ( V_45 , & V_48 ) ;
F_48 ( V_45 ) ;
}
static inline int F_42 ( struct V_21 * * V_45 )
{
return 0 ;
}
static inline void F_49 ( struct V_21 * V_45 )
{
}
static int T_3 F_50 ( void )
{
int V_36 ;
struct V_21 * V_45 ;
if ( ! F_51 () ) {
V_32 = 0 ;
return - V_31 ;
}
F_52 ( V_9 >= V_52 ) ;
F_52 ( V_9 < 2 ) ;
V_36 = F_42 ( & V_45 ) ;
if ( V_36 )
goto V_53;
V_36 = F_53 () ;
if ( V_36 )
goto V_54;
V_36 = F_54 ( & V_55 ) ;
if ( V_36 )
goto V_56;
V_36 = F_54 ( & V_57 ) ;
if ( V_36 )
goto V_58;
if ( V_59 < ( 512 << ( 20 - V_60 ) ) ) {
V_32 = 0 ;
return 0 ;
}
V_36 = F_31 () ;
if ( V_36 )
goto V_61;
return 0 ;
V_61:
F_55 ( & V_57 ) ;
V_58:
F_55 ( & V_55 ) ;
V_56:
F_56 () ;
V_54:
F_49 ( V_45 ) ;
V_53:
return V_36 ;
}
static int T_3 F_57 ( char * V_62 )
{
int V_35 = 0 ;
if ( ! V_62 )
goto V_63;
if ( ! strcmp ( V_62 , L_2 ) ) {
F_28 ( V_33 ,
& V_32 ) ;
F_27 ( V_34 ,
& V_32 ) ;
V_35 = 1 ;
} else if ( ! strcmp ( V_62 , L_3 ) ) {
F_27 ( V_33 ,
& V_32 ) ;
F_28 ( V_34 ,
& V_32 ) ;
V_35 = 1 ;
} else if ( ! strcmp ( V_62 , L_4 ) ) {
F_27 ( V_33 ,
& V_32 ) ;
F_27 ( V_34 ,
& V_32 ) ;
V_35 = 1 ;
}
V_63:
if ( ! V_35 )
F_58 ( L_17 ) ;
return V_35 ;
}
T_4 F_59 ( T_4 V_64 , struct V_65 * V_66 )
{
if ( F_2 ( V_66 -> V_67 & V_68 ) )
V_64 = F_60 ( V_64 ) ;
return V_64 ;
}
static inline struct V_69 * F_61 ( struct V_1 * V_1 )
{
return (struct V_69 * ) & V_1 [ 2 ] . V_70 ;
}
void F_62 ( struct V_1 * V_1 )
{
F_63 ( F_61 ( V_1 ) ) ;
F_64 ( V_1 , V_71 ) ;
}
unsigned long F_65 ( struct V_72 * V_73 , unsigned long V_74 ,
T_5 V_75 , unsigned long V_15 , unsigned long V_76 )
{
unsigned long V_77 ;
T_5 V_78 = V_75 + V_74 ;
T_5 V_79 = F_66 ( V_75 , V_76 ) ;
unsigned long V_80 ;
if ( V_78 <= V_79 || ( V_78 - V_79 ) < V_76 )
return 0 ;
V_80 = V_74 + V_76 ;
if ( V_80 < V_74 || ( V_75 + V_80 ) < V_75 )
return 0 ;
V_77 = V_81 -> V_13 -> V_82 ( V_73 , 0 , V_80 ,
V_75 >> V_60 , V_15 ) ;
if ( F_67 ( V_77 ) )
return 0 ;
V_77 += ( V_75 - V_77 ) & ( V_76 - 1 ) ;
return V_77 ;
}
unsigned long F_68 ( struct V_72 * V_73 , unsigned long V_77 ,
unsigned long V_74 , unsigned long V_83 , unsigned long V_15 )
{
T_5 V_75 = ( T_5 ) V_83 << V_60 ;
if ( V_77 )
goto V_63;
if ( ! F_69 ( V_73 -> V_84 -> V_85 ) || ! F_70 ( V_86 ) )
goto V_63;
V_77 = F_65 ( V_73 , V_74 , V_75 , V_15 , V_87 ) ;
if ( V_77 )
return V_77 ;
V_63:
return V_81 -> V_13 -> V_82 ( V_73 , V_77 , V_74 , V_83 , V_15 ) ;
}
static int F_71 ( struct V_88 * V_89 , struct V_1 * V_1 ,
T_6 V_90 )
{
struct V_65 * V_66 = V_89 -> V_66 ;
struct V_91 * V_92 ;
T_7 V_93 ;
unsigned long V_94 = V_89 -> V_95 & V_96 ;
F_72 ( ! F_73 ( V_1 ) , V_1 ) ;
if ( F_74 ( V_1 , V_66 -> V_97 , V_90 , & V_92 , true ) ) {
F_75 ( V_1 ) ;
F_6 ( V_98 ) ;
return V_99 ;
}
V_93 = F_76 ( V_66 -> V_97 , V_94 ) ;
if ( F_44 ( ! V_93 ) ) {
F_77 ( V_1 , V_92 , true ) ;
F_75 ( V_1 ) ;
return V_100 ;
}
F_78 ( V_1 , V_94 , V_20 ) ;
F_79 ( V_1 ) ;
V_89 -> V_101 = F_80 ( V_66 -> V_97 , V_89 -> V_64 ) ;
if ( F_44 ( ! F_81 ( * V_89 -> V_64 ) ) ) {
F_82 ( V_89 -> V_101 ) ;
F_77 ( V_1 , V_92 , true ) ;
F_75 ( V_1 ) ;
F_83 ( V_66 -> V_97 , V_93 ) ;
} else {
T_4 V_102 ;
if ( F_84 ( V_66 ) ) {
int V_35 ;
F_82 ( V_89 -> V_101 ) ;
F_77 ( V_1 , V_92 , true ) ;
F_75 ( V_1 ) ;
F_83 ( V_66 -> V_97 , V_93 ) ;
V_35 = F_85 ( V_89 , V_103 ) ;
F_86 ( V_35 & V_99 ) ;
return V_35 ;
}
V_102 = F_87 ( V_1 , V_66 -> V_104 ) ;
V_102 = F_59 ( F_88 ( V_102 ) , V_66 ) ;
F_89 ( V_1 , V_66 , V_94 , true ) ;
F_90 ( V_1 , V_92 , false , true ) ;
F_91 ( V_1 , V_66 ) ;
F_92 ( V_66 -> V_97 , V_89 -> V_64 , V_93 ) ;
F_93 ( V_66 -> V_97 , V_94 , V_89 -> V_64 , V_102 ) ;
F_94 ( V_66 -> V_97 , V_105 , V_20 ) ;
F_95 ( & V_66 -> V_97 -> V_106 ) ;
F_82 ( V_89 -> V_101 ) ;
F_6 ( V_107 ) ;
}
return 0 ;
}
static inline T_6 F_96 ( struct V_65 * V_66 )
{
bool V_108 = ! ! ( V_66 -> V_67 & V_109 ) ;
if ( F_17 ( V_41 ,
& V_32 ) && V_108 )
return V_6 ;
else if ( F_17 ( V_40 ,
& V_32 ) )
return V_110 | V_111 ;
else if ( F_17 ( V_39 ,
& V_32 ) )
return V_6 | ( V_108 ? 0 : V_112 ) ;
return V_110 ;
}
static bool F_97 ( T_7 V_93 , struct V_12 * V_13 ,
struct V_65 * V_66 , unsigned long V_94 , T_4 * V_64 ,
struct V_1 * V_2 )
{
T_4 V_102 ;
if ( ! F_81 ( * V_64 ) )
return false ;
V_102 = F_98 ( V_2 , V_66 -> V_104 ) ;
V_102 = F_99 ( V_102 ) ;
if ( V_93 )
F_92 ( V_13 , V_64 , V_93 ) ;
F_93 ( V_13 , V_94 , V_64 , V_102 ) ;
F_95 ( & V_13 -> V_106 ) ;
return true ;
}
int F_100 ( struct V_88 * V_89 )
{
struct V_65 * V_66 = V_89 -> V_66 ;
T_6 V_90 ;
struct V_1 * V_1 ;
unsigned long V_94 = V_89 -> V_95 & V_96 ;
if ( V_94 < V_66 -> V_113 || V_94 + V_43 > V_66 -> V_114 )
return V_99 ;
if ( F_44 ( F_101 ( V_66 ) ) )
return V_100 ;
if ( F_44 ( F_102 ( V_66 , V_66 -> V_67 ) ) )
return V_100 ;
if ( ! ( V_89 -> V_15 & V_115 ) &&
! F_103 ( V_66 -> V_97 ) &&
F_104 () ) {
T_7 V_93 ;
struct V_1 * V_2 ;
bool V_116 ;
int V_35 ;
V_93 = F_76 ( V_66 -> V_97 , V_94 ) ;
if ( F_44 ( ! V_93 ) )
return V_100 ;
V_2 = F_16 ( V_66 -> V_97 ) ;
if ( F_44 ( ! V_2 ) ) {
F_83 ( V_66 -> V_97 , V_93 ) ;
F_6 ( V_98 ) ;
return V_99 ;
}
V_89 -> V_101 = F_80 ( V_66 -> V_97 , V_89 -> V_64 ) ;
V_35 = 0 ;
V_116 = false ;
if ( F_81 ( * V_89 -> V_64 ) ) {
if ( F_84 ( V_66 ) ) {
F_82 ( V_89 -> V_101 ) ;
V_35 = F_85 ( V_89 , V_103 ) ;
F_86 ( V_35 & V_99 ) ;
} else {
F_97 ( V_93 , V_66 -> V_97 , V_66 ,
V_94 , V_89 -> V_64 , V_2 ) ;
F_82 ( V_89 -> V_101 ) ;
V_116 = true ;
}
} else
F_82 ( V_89 -> V_101 ) ;
if ( ! V_116 )
F_83 ( V_66 -> V_97 , V_93 ) ;
return V_35 ;
}
V_90 = F_96 ( V_66 ) ;
V_1 = F_105 ( V_90 , V_66 , V_94 , V_9 ) ;
if ( F_44 ( ! V_1 ) ) {
F_6 ( V_98 ) ;
return V_99 ;
}
F_62 ( V_1 ) ;
return F_71 ( V_89 , V_1 , V_90 ) ;
}
static void F_106 ( struct V_65 * V_66 , unsigned long V_77 ,
T_4 * V_64 , T_8 V_117 , T_9 V_118 , bool V_119 )
{
struct V_12 * V_13 = V_66 -> V_97 ;
T_4 V_102 ;
T_10 * V_101 ;
V_101 = F_80 ( V_13 , V_64 ) ;
V_102 = F_99 ( F_107 ( V_117 , V_118 ) ) ;
if ( F_108 ( V_117 ) )
V_102 = F_109 ( V_102 ) ;
if ( V_119 ) {
V_102 = F_110 ( F_88 ( V_102 ) ) ;
V_102 = F_59 ( V_102 , V_66 ) ;
}
F_93 ( V_13 , V_77 , V_64 , V_102 ) ;
F_111 ( V_66 , V_77 , V_64 ) ;
F_82 ( V_101 ) ;
}
int F_112 ( struct V_65 * V_66 , unsigned long V_77 ,
T_4 * V_64 , T_8 V_117 , bool V_119 )
{
T_9 V_120 = V_66 -> V_104 ;
F_14 ( ! ( V_66 -> V_67 & ( V_121 | V_122 ) ) ) ;
F_14 ( ( V_66 -> V_67 & ( V_121 | V_122 ) ) ==
( V_121 | V_122 ) ) ;
F_14 ( ( V_66 -> V_67 & V_121 ) && F_113 ( V_66 -> V_67 ) ) ;
F_14 ( ! F_108 ( V_117 ) ) ;
if ( V_77 < V_66 -> V_113 || V_77 >= V_66 -> V_114 )
return V_123 ;
F_114 ( V_66 , & V_120 , V_117 ) ;
F_106 ( V_66 , V_77 , V_64 , V_117 , V_120 , V_119 ) ;
return V_124 ;
}
static void F_115 ( struct V_65 * V_66 , unsigned long V_77 ,
T_4 * V_64 )
{
T_4 V_125 ;
V_125 = F_110 ( F_88 ( * V_64 ) ) ;
if ( F_116 ( V_66 , V_77 & V_96 ,
V_64 , V_125 , 1 ) )
F_111 ( V_66 , V_77 , V_64 ) ;
}
struct V_1 * F_117 ( struct V_65 * V_66 , unsigned long V_77 ,
T_4 * V_64 , int V_15 )
{
unsigned long V_117 = F_118 ( * V_64 ) ;
struct V_12 * V_13 = V_66 -> V_97 ;
struct V_126 * V_127 ;
struct V_1 * V_1 ;
F_119 ( F_120 ( V_13 , V_64 ) ) ;
F_121 ( V_15 & V_128 , L_18 ) ;
if ( V_15 & V_129 && ! F_122 ( * V_64 ) )
return NULL ;
if ( F_123 ( * V_64 ) && F_124 ( * V_64 ) )
;
else
return NULL ;
if ( V_15 & V_130 )
F_115 ( V_66 , V_77 , V_64 ) ;
if ( ! ( V_15 & V_131 ) )
return F_125 ( - V_132 ) ;
V_117 += ( V_77 & ~ V_133 ) >> V_60 ;
V_127 = F_126 ( V_117 , NULL ) ;
if ( ! V_127 )
return F_125 ( - V_134 ) ;
V_1 = F_127 ( V_117 ) ;
F_128 ( V_1 ) ;
F_129 ( V_127 ) ;
return V_1 ;
}
int F_130 ( struct V_12 * V_135 , struct V_12 * V_136 ,
T_4 * V_137 , T_4 * V_138 , unsigned long V_77 ,
struct V_65 * V_66 )
{
T_10 * V_139 , * V_140 ;
struct V_1 * V_141 ;
T_4 V_64 ;
T_7 V_93 = NULL ;
int V_35 = - V_47 ;
if ( ! F_131 ( V_66 ) )
return 0 ;
V_93 = F_76 ( V_135 , V_77 ) ;
if ( F_44 ( ! V_93 ) )
goto V_63;
V_139 = F_80 ( V_135 , V_137 ) ;
V_140 = F_120 ( V_136 , V_138 ) ;
F_132 ( V_140 , V_142 ) ;
V_35 = - V_143 ;
V_64 = * V_138 ;
if ( F_44 ( ! F_133 ( V_64 ) ) ) {
F_83 ( V_135 , V_93 ) ;
goto V_144;
}
if ( F_134 ( V_64 ) ) {
struct V_1 * V_2 ;
V_2 = F_16 ( V_135 ) ;
F_97 ( V_93 , V_135 , V_66 , V_77 , V_137 ,
V_2 ) ;
V_35 = 0 ;
goto V_144;
}
V_141 = F_135 ( V_64 ) ;
F_72 ( ! F_136 ( V_141 ) , V_141 ) ;
F_128 ( V_141 ) ;
F_137 ( V_141 , true ) ;
F_94 ( V_135 , V_105 , V_20 ) ;
F_95 ( & V_135 -> V_106 ) ;
F_92 ( V_135 , V_137 , V_93 ) ;
F_138 ( V_136 , V_77 , V_138 ) ;
V_64 = F_139 ( F_140 ( V_64 ) ) ;
F_93 ( V_135 , V_77 , V_137 , V_64 ) ;
V_35 = 0 ;
V_144:
F_82 ( V_140 ) ;
F_82 ( V_139 ) ;
V_63:
return V_35 ;
}
void F_141 ( struct V_88 * V_89 , T_4 V_145 )
{
T_4 V_102 ;
unsigned long V_94 ;
bool V_119 = V_89 -> V_15 & V_115 ;
V_89 -> V_101 = F_80 ( V_89 -> V_66 -> V_97 , V_89 -> V_64 ) ;
if ( F_44 ( ! F_142 ( * V_89 -> V_64 , V_145 ) ) )
goto V_146;
V_102 = F_110 ( V_145 ) ;
if ( V_119 )
V_102 = F_88 ( V_102 ) ;
V_94 = V_89 -> V_95 & V_96 ;
if ( F_116 ( V_89 -> V_66 , V_94 , V_89 -> V_64 , V_102 , V_119 ) )
F_111 ( V_89 -> V_66 , V_89 -> V_95 , V_89 -> V_64 ) ;
V_146:
F_82 ( V_89 -> V_101 ) ;
}
static int F_143 ( struct V_88 * V_89 , T_4 V_145 ,
struct V_1 * V_1 )
{
struct V_65 * V_66 = V_89 -> V_66 ;
unsigned long V_94 = V_89 -> V_95 & V_96 ;
struct V_91 * V_92 ;
T_7 V_93 ;
T_4 V_125 ;
int V_35 = 0 , V_147 ;
struct V_1 * * V_148 ;
unsigned long V_149 ;
unsigned long V_150 ;
V_148 = F_144 ( sizeof( struct V_1 * ) * V_20 ,
V_151 ) ;
if ( F_44 ( ! V_148 ) ) {
V_35 |= V_100 ;
goto V_63;
}
for ( V_147 = 0 ; V_147 < V_20 ; V_147 ++ ) {
V_148 [ V_147 ] = F_145 ( V_152 , V_66 ,
V_89 -> V_95 , F_146 ( V_1 ) ) ;
if ( F_44 ( ! V_148 [ V_147 ] ||
F_74 ( V_148 [ V_147 ] , V_66 -> V_97 ,
V_151 , & V_92 , false ) ) ) {
if ( V_148 [ V_147 ] )
F_75 ( V_148 [ V_147 ] ) ;
while ( -- V_147 >= 0 ) {
V_92 = ( void * ) F_147 ( V_148 [ V_147 ] ) ;
F_148 ( V_148 [ V_147 ] , 0 ) ;
F_77 ( V_148 [ V_147 ] , V_92 ,
false ) ;
F_75 ( V_148 [ V_147 ] ) ;
}
F_149 ( V_148 ) ;
V_35 |= V_100 ;
goto V_63;
}
F_148 ( V_148 [ V_147 ] , ( unsigned long ) V_92 ) ;
}
for ( V_147 = 0 ; V_147 < V_20 ; V_147 ++ ) {
F_150 ( V_148 [ V_147 ] , V_1 + V_147 ,
V_94 + V_153 * V_147 , V_66 ) ;
F_79 ( V_148 [ V_147 ] ) ;
F_151 () ;
}
V_149 = V_94 ;
V_150 = V_94 + V_43 ;
F_152 ( V_66 -> V_97 , V_149 , V_150 ) ;
V_89 -> V_101 = F_80 ( V_66 -> V_97 , V_89 -> V_64 ) ;
if ( F_44 ( ! F_142 ( * V_89 -> V_64 , V_145 ) ) )
goto V_154;
F_72 ( ! F_136 ( V_1 ) , V_1 ) ;
F_153 ( V_66 , V_94 , V_89 -> V_64 ) ;
V_93 = F_154 ( V_66 -> V_97 , V_89 -> V_64 ) ;
F_155 ( V_66 -> V_97 , & V_125 , V_93 ) ;
for ( V_147 = 0 ; V_147 < V_20 ; V_147 ++ , V_94 += V_153 ) {
T_11 V_102 ;
V_102 = F_156 ( V_148 [ V_147 ] , V_66 -> V_104 ) ;
V_102 = F_157 ( F_158 ( V_102 ) , V_66 ) ;
V_92 = ( void * ) F_147 ( V_148 [ V_147 ] ) ;
F_148 ( V_148 [ V_147 ] , 0 ) ;
F_89 ( V_148 [ V_147 ] , V_89 -> V_66 , V_94 , false ) ;
F_90 ( V_148 [ V_147 ] , V_92 , false , false ) ;
F_91 ( V_148 [ V_147 ] , V_66 ) ;
V_89 -> V_155 = F_159 ( & V_125 , V_94 ) ;
F_86 ( ! F_160 ( * V_89 -> V_155 ) ) ;
F_161 ( V_66 -> V_97 , V_94 , V_89 -> V_155 , V_102 ) ;
F_162 ( V_89 -> V_155 ) ;
}
F_149 ( V_148 ) ;
F_163 () ;
F_155 ( V_66 -> V_97 , V_89 -> V_64 , V_93 ) ;
F_164 ( V_1 , true ) ;
F_82 ( V_89 -> V_101 ) ;
F_165 ( V_66 -> V_97 , V_149 , V_150 ) ;
V_35 |= V_156 ;
F_75 ( V_1 ) ;
V_63:
return V_35 ;
V_154:
F_82 ( V_89 -> V_101 ) ;
F_165 ( V_66 -> V_97 , V_149 , V_150 ) ;
for ( V_147 = 0 ; V_147 < V_20 ; V_147 ++ ) {
V_92 = ( void * ) F_147 ( V_148 [ V_147 ] ) ;
F_148 ( V_148 [ V_147 ] , 0 ) ;
F_77 ( V_148 [ V_147 ] , V_92 , false ) ;
F_75 ( V_148 [ V_147 ] ) ;
}
F_149 ( V_148 ) ;
goto V_63;
}
int F_166 ( struct V_88 * V_89 , T_4 V_145 )
{
struct V_65 * V_66 = V_89 -> V_66 ;
struct V_1 * V_1 = NULL , * V_157 ;
struct V_91 * V_92 ;
unsigned long V_94 = V_89 -> V_95 & V_96 ;
unsigned long V_149 ;
unsigned long V_150 ;
T_6 V_158 ;
int V_35 = 0 ;
V_89 -> V_101 = F_120 ( V_66 -> V_97 , V_89 -> V_64 ) ;
F_167 ( ! V_66 -> V_159 , V_66 ) ;
if ( F_134 ( V_145 ) )
goto V_160;
F_168 ( V_89 -> V_101 ) ;
if ( F_44 ( ! F_142 ( * V_89 -> V_64 , V_145 ) ) )
goto V_144;
V_1 = F_135 ( V_145 ) ;
F_72 ( ! F_73 ( V_1 ) || ! F_136 ( V_1 ) , V_1 ) ;
if ( F_169 ( V_1 , NULL ) == 1 ) {
T_4 V_102 ;
V_102 = F_110 ( V_145 ) ;
V_102 = F_59 ( F_88 ( V_102 ) , V_66 ) ;
if ( F_116 ( V_66 , V_94 , V_89 -> V_64 , V_102 , 1 ) )
F_111 ( V_66 , V_89 -> V_95 , V_89 -> V_64 ) ;
V_35 |= V_156 ;
goto V_144;
}
F_128 ( V_1 ) ;
F_82 ( V_89 -> V_101 ) ;
V_160:
if ( F_170 ( V_66 ) &&
! F_171 () ) {
V_158 = F_96 ( V_66 ) ;
V_157 = F_105 ( V_158 , V_66 , V_94 , V_9 ) ;
} else
V_157 = NULL ;
if ( F_2 ( V_157 ) ) {
F_62 ( V_157 ) ;
} else {
if ( ! V_1 ) {
F_172 ( V_66 , V_89 -> V_64 , V_89 -> V_95 ) ;
V_35 |= V_99 ;
} else {
V_35 = F_143 ( V_89 , V_145 , V_1 ) ;
if ( V_35 & V_100 ) {
F_172 ( V_66 , V_89 -> V_64 , V_89 -> V_95 ) ;
V_35 |= V_99 ;
}
F_75 ( V_1 ) ;
}
F_6 ( V_98 ) ;
goto V_63;
}
if ( F_44 ( F_74 ( V_157 , V_66 -> V_97 ,
V_158 , & V_92 , true ) ) ) {
F_75 ( V_157 ) ;
F_172 ( V_66 , V_89 -> V_64 , V_89 -> V_95 ) ;
if ( V_1 )
F_75 ( V_1 ) ;
V_35 |= V_99 ;
F_6 ( V_98 ) ;
goto V_63;
}
F_6 ( V_107 ) ;
if ( ! V_1 )
F_78 ( V_157 , V_94 , V_20 ) ;
else
F_173 ( V_157 , V_1 , V_94 , V_66 , V_20 ) ;
F_79 ( V_157 ) ;
V_149 = V_94 ;
V_150 = V_94 + V_43 ;
F_152 ( V_66 -> V_97 , V_149 , V_150 ) ;
F_168 ( V_89 -> V_101 ) ;
if ( V_1 )
F_75 ( V_1 ) ;
if ( F_44 ( ! F_142 ( * V_89 -> V_64 , V_145 ) ) ) {
F_82 ( V_89 -> V_101 ) ;
F_77 ( V_157 , V_92 , true ) ;
F_75 ( V_157 ) ;
goto V_161;
} else {
T_4 V_102 ;
V_102 = F_87 ( V_157 , V_66 -> V_104 ) ;
V_102 = F_59 ( F_88 ( V_102 ) , V_66 ) ;
F_153 ( V_66 , V_94 , V_89 -> V_64 ) ;
F_89 ( V_157 , V_66 , V_94 , true ) ;
F_90 ( V_157 , V_92 , false , true ) ;
F_91 ( V_157 , V_66 ) ;
F_93 ( V_66 -> V_97 , V_94 , V_89 -> V_64 , V_102 ) ;
F_111 ( V_66 , V_89 -> V_95 , V_89 -> V_64 ) ;
if ( ! V_1 ) {
F_94 ( V_66 -> V_97 , V_105 , V_20 ) ;
} else {
F_72 ( ! F_136 ( V_1 ) , V_1 ) ;
F_164 ( V_1 , true ) ;
F_75 ( V_1 ) ;
}
V_35 |= V_156 ;
}
F_82 ( V_89 -> V_101 ) ;
V_161:
F_165 ( V_66 -> V_97 , V_149 , V_150 ) ;
V_63:
return V_35 ;
V_144:
F_82 ( V_89 -> V_101 ) ;
return V_35 ;
}
static inline bool F_174 ( T_4 V_64 , unsigned int V_15 )
{
return F_122 ( V_64 ) ||
( ( V_15 & V_162 ) && ( V_15 & V_128 ) && F_175 ( V_64 ) ) ;
}
struct V_1 * F_176 ( struct V_65 * V_66 ,
unsigned long V_77 ,
T_4 * V_64 ,
unsigned int V_15 )
{
struct V_12 * V_13 = V_66 -> V_97 ;
struct V_1 * V_1 = NULL ;
F_119 ( F_120 ( V_13 , V_64 ) ) ;
if ( V_15 & V_129 && ! F_174 ( * V_64 , V_15 ) )
goto V_63;
if ( ( V_15 & V_163 ) && F_134 ( * V_64 ) )
return F_125 ( - V_134 ) ;
if ( ( V_15 & V_164 ) && F_177 ( * V_64 ) )
goto V_63;
V_1 = F_135 ( * V_64 ) ;
F_72 ( ! F_136 ( V_1 ) && ! F_178 ( V_1 ) , V_1 ) ;
if ( V_15 & V_130 )
F_115 ( V_66 , V_77 , V_64 ) ;
if ( ( V_15 & V_165 ) && ( V_66 -> V_67 & V_166 ) ) {
if ( F_179 ( V_1 ) && F_180 ( V_1 ) != 1 )
goto V_167;
if ( F_181 ( V_1 ) || ! V_1 -> V_70 )
goto V_167;
if ( ! F_182 ( V_1 ) )
goto V_167;
F_183 () ;
if ( V_1 -> V_70 && ! F_181 ( V_1 ) )
F_184 ( V_1 ) ;
F_185 ( V_1 ) ;
}
V_167:
V_1 += ( V_77 & ~ V_96 ) >> V_60 ;
F_72 ( ! F_73 ( V_1 ) && ! F_178 ( V_1 ) , V_1 ) ;
if ( V_15 & V_131 )
F_128 ( V_1 ) ;
V_63:
return V_1 ;
}
int F_186 ( struct V_88 * V_89 , T_4 V_64 )
{
struct V_65 * V_66 = V_89 -> V_66 ;
struct V_159 * V_159 = NULL ;
struct V_1 * V_1 ;
unsigned long V_94 = V_89 -> V_95 & V_96 ;
int V_168 = - 1 , V_169 = F_187 () ;
int V_170 , V_171 = - 1 ;
bool V_172 ;
bool V_173 = false ;
bool V_174 ;
int V_15 = 0 ;
V_89 -> V_101 = F_80 ( V_66 -> V_97 , V_89 -> V_64 ) ;
if ( F_44 ( ! F_142 ( V_64 , * V_89 -> V_64 ) ) )
goto V_144;
if ( F_44 ( F_188 ( * V_89 -> V_64 ) ) ) {
V_1 = F_135 ( * V_89 -> V_64 ) ;
F_82 ( V_89 -> V_101 ) ;
F_189 ( V_1 ) ;
goto V_63;
}
V_1 = F_135 ( V_64 ) ;
F_14 ( F_190 ( V_1 ) ) ;
V_168 = F_146 ( V_1 ) ;
V_171 = F_191 ( V_1 ) ;
F_192 ( V_175 ) ;
if ( V_168 == V_169 ) {
F_192 ( V_176 ) ;
V_15 |= V_177 ;
}
if ( ! F_122 ( V_64 ) )
V_15 |= V_178 ;
V_172 = F_182 ( V_1 ) ;
V_170 = F_193 ( V_1 , V_66 , V_94 ) ;
if ( V_170 == - 1 ) {
if ( V_172 )
goto V_179;
}
if ( ! V_172 ) {
F_82 ( V_89 -> V_101 ) ;
F_189 ( V_1 ) ;
V_168 = - 1 ;
goto V_63;
}
F_128 ( V_1 ) ;
F_82 ( V_89 -> V_101 ) ;
V_159 = F_194 ( V_1 ) ;
F_168 ( V_89 -> V_101 ) ;
if ( F_44 ( ! F_142 ( V_64 , * V_89 -> V_64 ) ) ) {
F_185 ( V_1 ) ;
F_75 ( V_1 ) ;
V_168 = - 1 ;
goto V_144;
}
if ( F_44 ( ! V_159 ) ) {
F_75 ( V_1 ) ;
V_168 = - 1 ;
goto V_179;
}
F_82 ( V_89 -> V_101 ) ;
V_173 = F_195 ( V_66 -> V_97 , V_66 ,
V_89 -> V_64 , V_64 , V_89 -> V_95 , V_1 , V_170 ) ;
if ( V_173 ) {
V_15 |= V_180 ;
V_168 = V_170 ;
} else
V_15 |= V_181 ;
goto V_63;
V_179:
F_14 ( ! F_196 ( V_1 ) ) ;
V_174 = F_122 ( V_64 ) ;
V_64 = F_197 ( V_64 , V_66 -> V_104 ) ;
V_64 = F_110 ( V_64 ) ;
if ( V_174 )
V_64 = F_60 ( V_64 ) ;
F_93 ( V_66 -> V_97 , V_94 , V_89 -> V_64 , V_64 ) ;
F_111 ( V_66 , V_89 -> V_95 , V_89 -> V_64 ) ;
F_185 ( V_1 ) ;
V_144:
F_82 ( V_89 -> V_101 ) ;
V_63:
if ( V_159 )
F_198 ( V_159 ) ;
if ( V_168 != - 1 )
F_199 ( V_171 , V_168 , V_20 ,
V_89 -> V_15 ) ;
return 0 ;
}
bool F_200 ( struct V_182 * V_183 , struct V_65 * V_66 ,
T_4 * V_64 , unsigned long V_77 , unsigned long V_184 )
{
T_10 * V_101 ;
T_4 V_145 ;
struct V_1 * V_1 ;
struct V_12 * V_13 = V_183 -> V_13 ;
bool V_35 = false ;
F_201 ( V_183 , V_43 ) ;
V_101 = F_202 ( V_64 , V_66 ) ;
if ( ! V_101 )
goto V_185;
V_145 = * V_64 ;
if ( F_134 ( V_145 ) )
goto V_63;
V_1 = F_135 ( V_145 ) ;
if ( F_203 ( V_1 ) != 1 )
goto V_63;
if ( ! F_182 ( V_1 ) )
goto V_63;
if ( V_184 - V_77 != V_43 ) {
F_128 ( V_1 ) ;
F_82 ( V_101 ) ;
F_204 ( V_1 ) ;
F_75 ( V_1 ) ;
F_185 ( V_1 ) ;
goto V_185;
}
if ( F_205 ( V_1 ) )
F_206 ( V_1 ) ;
F_185 ( V_1 ) ;
if ( F_207 ( V_1 ) )
F_208 ( V_1 ) ;
if ( F_209 ( V_145 ) || F_175 ( V_145 ) ) {
V_145 = F_210 ( V_183 -> V_13 , V_77 , V_64 ,
V_183 -> V_186 ) ;
V_145 = F_139 ( V_145 ) ;
V_145 = F_211 ( V_145 ) ;
F_93 ( V_13 , V_77 , V_64 , V_145 ) ;
F_212 ( V_183 , V_64 , V_77 ) ;
}
V_35 = true ;
V_63:
F_82 ( V_101 ) ;
V_185:
return V_35 ;
}
static inline void F_213 ( struct V_12 * V_13 , T_4 * V_64 )
{
T_7 V_93 ;
V_93 = F_154 ( V_13 , V_64 ) ;
F_83 ( V_13 , V_93 ) ;
F_214 ( & V_13 -> V_106 ) ;
}
int F_215 ( struct V_182 * V_183 , struct V_65 * V_66 ,
T_4 * V_64 , unsigned long V_77 )
{
T_4 V_145 ;
T_10 * V_101 ;
F_201 ( V_183 , V_43 ) ;
V_101 = F_216 ( V_64 , V_66 ) ;
if ( ! V_101 )
return 0 ;
V_145 = F_210 ( V_183 -> V_13 , V_77 , V_64 ,
V_183 -> V_186 ) ;
F_212 ( V_183 , V_64 , V_77 ) ;
if ( F_217 ( V_66 ) ) {
F_82 ( V_101 ) ;
if ( F_134 ( V_145 ) )
F_218 ( V_183 , F_135 ( V_145 ) , V_43 ) ;
} else if ( F_134 ( V_145 ) ) {
F_83 ( V_183 -> V_13 , F_154 ( V_183 -> V_13 , V_64 ) ) ;
F_214 ( & V_183 -> V_13 -> V_106 ) ;
F_82 ( V_101 ) ;
F_218 ( V_183 , F_135 ( V_145 ) , V_43 ) ;
} else {
struct V_1 * V_1 = F_135 ( V_145 ) ;
F_164 ( V_1 , true ) ;
F_72 ( F_203 ( V_1 ) < 0 , V_1 ) ;
F_72 ( ! F_136 ( V_1 ) , V_1 ) ;
if ( F_179 ( V_1 ) ) {
T_7 V_93 ;
V_93 = F_154 ( V_183 -> V_13 , V_64 ) ;
F_83 ( V_183 -> V_13 , V_93 ) ;
F_214 ( & V_183 -> V_13 -> V_106 ) ;
F_94 ( V_183 -> V_13 , V_105 , - V_20 ) ;
} else {
if ( F_219 () )
F_213 ( V_183 -> V_13 , V_64 ) ;
F_94 ( V_183 -> V_13 , V_187 , - V_20 ) ;
}
F_82 ( V_101 ) ;
F_218 ( V_183 , V_1 , V_43 ) ;
}
return 1 ;
}
static inline int F_220 ( T_10 * V_188 ,
T_10 * V_189 ,
struct V_65 * V_66 )
{
return ( V_188 != V_189 ) && F_131 ( V_66 ) ;
}
bool F_221 ( struct V_65 * V_66 , unsigned long V_190 ,
unsigned long V_191 , unsigned long V_192 ,
T_4 * V_193 , T_4 * V_194 , bool * V_195 )
{
T_10 * V_196 , * V_197 ;
T_4 V_64 ;
struct V_12 * V_13 = V_66 -> V_97 ;
bool V_198 = false ;
if ( ( V_190 & ~ V_96 ) ||
( V_191 & ~ V_96 ) ||
V_192 - V_190 < V_43 )
return false ;
if ( F_222 ( ! F_81 ( * V_194 ) ) ) {
F_86 ( F_133 ( * V_194 ) ) ;
return false ;
}
V_196 = F_216 ( V_193 , V_66 ) ;
if ( V_196 ) {
V_197 = F_120 ( V_13 , V_194 ) ;
if ( V_197 != V_196 )
F_132 ( V_197 , V_142 ) ;
V_64 = F_223 ( V_13 , V_190 , V_193 ) ;
if ( F_123 ( V_64 ) && F_175 ( V_64 ) )
V_198 = true ;
F_86 ( ! F_81 ( * V_194 ) ) ;
if ( F_220 ( V_197 , V_196 , V_66 ) ) {
T_7 V_93 ;
V_93 = F_154 ( V_13 , V_193 ) ;
F_92 ( V_13 , V_194 , V_93 ) ;
}
F_93 ( V_13 , V_191 , V_194 , F_224 ( V_64 ) ) ;
if ( V_197 != V_196 )
F_82 ( V_197 ) ;
if ( V_198 )
F_225 ( V_66 , V_190 , V_190 + V_87 ) ;
else
* V_195 = true ;
F_82 ( V_196 ) ;
return true ;
}
return false ;
}
int F_226 ( struct V_65 * V_66 , T_4 * V_64 ,
unsigned long V_77 , T_9 V_199 , int V_200 )
{
struct V_12 * V_13 = V_66 -> V_97 ;
T_10 * V_101 ;
int V_35 = 0 ;
V_101 = F_216 ( V_64 , V_66 ) ;
if ( V_101 ) {
T_4 V_102 ;
bool V_201 = V_200 && F_122 ( * V_64 ) ;
V_35 = 1 ;
if ( V_200 && F_134 ( * V_64 ) ) {
F_82 ( V_101 ) ;
return V_35 ;
}
if ( ! V_200 || ! F_177 ( * V_64 ) ) {
V_102 = F_227 ( V_13 , V_77 , V_64 ) ;
V_102 = F_197 ( V_102 , V_199 ) ;
if ( V_201 )
V_102 = F_60 ( V_102 ) ;
V_35 = V_20 ;
F_93 ( V_13 , V_77 , V_64 , V_102 ) ;
F_14 ( F_131 ( V_66 ) && ! V_201 &&
F_122 ( V_102 ) ) ;
}
F_82 ( V_101 ) ;
}
return V_35 ;
}
T_10 * F_216 ( T_4 * V_64 , struct V_65 * V_66 )
{
T_10 * V_101 ;
V_101 = F_80 ( V_66 -> V_97 , V_64 ) ;
if ( F_2 ( F_133 ( * V_64 ) || F_124 ( * V_64 ) ) )
return V_101 ;
F_82 ( V_101 ) ;
return NULL ;
}
static void F_228 ( struct V_65 * V_66 ,
unsigned long V_94 , T_4 * V_64 )
{
struct V_12 * V_13 = V_66 -> V_97 ;
T_7 V_93 ;
T_4 V_125 ;
int V_147 ;
F_153 ( V_66 , V_94 , V_64 ) ;
V_93 = F_154 ( V_13 , V_64 ) ;
F_155 ( V_13 , & V_125 , V_93 ) ;
for ( V_147 = 0 ; V_147 < V_20 ; V_147 ++ , V_94 += V_153 ) {
T_11 * V_155 , V_102 ;
V_102 = F_229 ( F_230 ( V_94 ) , V_66 -> V_104 ) ;
V_102 = F_231 ( V_102 ) ;
V_155 = F_159 ( & V_125 , V_94 ) ;
F_86 ( ! F_160 ( * V_155 ) ) ;
F_161 ( V_13 , V_94 , V_155 , V_102 ) ;
F_162 ( V_155 ) ;
}
F_163 () ;
F_155 ( V_13 , V_64 , V_93 ) ;
}
static void F_232 ( struct V_65 * V_66 , T_4 * V_64 ,
unsigned long V_94 , bool V_202 )
{
struct V_12 * V_13 = V_66 -> V_97 ;
struct V_1 * V_1 ;
T_7 V_93 ;
T_4 V_125 ;
bool V_203 , V_119 , V_204 , V_205 ;
unsigned long V_77 ;
int V_147 ;
F_86 ( V_94 & ~ V_96 ) ;
F_167 ( V_66 -> V_113 > V_94 , V_66 ) ;
F_167 ( V_66 -> V_114 < V_94 + V_43 , V_66 ) ;
F_86 ( ! F_133 ( * V_64 ) && ! F_124 ( * V_64 ) ) ;
F_6 ( V_206 ) ;
if ( ! F_131 ( V_66 ) ) {
V_125 = F_153 ( V_66 , V_94 , V_64 ) ;
if ( F_219 () )
F_213 ( V_13 , V_64 ) ;
if ( F_217 ( V_66 ) )
return;
V_1 = F_135 ( V_125 ) ;
if ( ! F_233 ( V_1 ) && F_209 ( V_125 ) )
F_234 ( V_1 ) ;
F_164 ( V_1 , true ) ;
F_75 ( V_1 ) ;
F_94 ( V_13 , V_187 , - V_20 ) ;
return;
} else if ( F_134 ( * V_64 ) ) {
return F_228 ( V_66 , V_94 , V_64 ) ;
}
V_1 = F_135 ( * V_64 ) ;
F_72 ( ! F_235 ( V_1 ) , V_1 ) ;
F_236 ( V_1 , V_20 - 1 ) ;
V_119 = F_122 ( * V_64 ) ;
V_203 = F_209 ( * V_64 ) ;
V_204 = F_175 ( * V_64 ) ;
V_205 = F_237 ( * V_64 ) ;
F_238 ( V_66 , V_94 , V_64 ) ;
V_93 = F_154 ( V_13 , V_64 ) ;
F_155 ( V_13 , & V_125 , V_93 ) ;
for ( V_147 = 0 , V_77 = V_94 ; V_147 < V_20 ; V_147 ++ , V_77 += V_153 ) {
T_11 V_102 , * V_155 ;
if ( V_202 ) {
T_12 V_207 ;
V_207 = F_239 ( V_1 + V_147 , V_119 ) ;
V_102 = F_240 ( V_207 ) ;
if ( V_205 )
V_102 = F_241 ( V_102 ) ;
} else {
V_102 = F_156 ( V_1 + V_147 , F_4 ( V_66 -> V_104 ) ) ;
V_102 = F_157 ( V_102 , V_66 ) ;
if ( ! V_119 )
V_102 = F_242 ( V_102 ) ;
if ( ! V_203 )
V_102 = F_243 ( V_102 ) ;
if ( V_205 )
V_102 = F_244 ( V_102 ) ;
}
if ( V_204 )
F_245 ( V_1 + V_147 ) ;
V_155 = F_159 ( & V_125 , V_77 ) ;
F_14 ( ! F_160 ( * V_155 ) ) ;
F_161 ( V_13 , V_77 , V_155 , V_102 ) ;
F_246 ( & V_1 [ V_147 ] . V_208 ) ;
F_162 ( V_155 ) ;
}
if ( F_180 ( V_1 ) > 1 && ! F_247 ( V_1 ) ) {
for ( V_147 = 0 ; V_147 < V_20 ; V_147 ++ )
F_246 ( & V_1 [ V_147 ] . V_208 ) ;
}
if ( F_248 ( - 1 , F_249 ( V_1 ) ) ) {
F_250 ( V_1 , V_209 ) ;
if ( F_251 ( V_1 ) ) {
for ( V_147 = 0 ; V_147 < V_20 ; V_147 ++ )
F_252 ( & V_1 [ V_147 ] . V_208 ) ;
}
}
F_163 () ;
F_253 ( V_66 , V_94 , V_64 ) ;
F_155 ( V_13 , V_64 , V_93 ) ;
if ( V_202 ) {
for ( V_147 = 0 ; V_147 < V_20 ; V_147 ++ ) {
F_164 ( V_1 + V_147 , false ) ;
F_75 ( V_1 + V_147 ) ;
}
}
}
void F_254 ( struct V_65 * V_66 , T_4 * V_64 ,
unsigned long V_95 , bool V_202 , struct V_1 * V_1 )
{
T_10 * V_101 ;
struct V_12 * V_13 = V_66 -> V_97 ;
unsigned long V_94 = V_95 & V_96 ;
F_152 ( V_13 , V_94 , V_94 + V_43 ) ;
V_101 = F_80 ( V_13 , V_64 ) ;
F_86 ( V_202 && ! V_1 ) ;
if ( V_1 && V_1 != F_135 ( * V_64 ) )
goto V_63;
if ( F_133 ( * V_64 ) ) {
V_1 = F_135 ( * V_64 ) ;
if ( F_255 ( V_1 ) )
F_256 ( V_1 ) ;
} else if ( ! F_124 ( * V_64 ) )
goto V_63;
F_232 ( V_66 , V_64 , V_94 , V_202 ) ;
V_63:
F_82 ( V_101 ) ;
F_165 ( V_13 , V_94 , V_94 + V_43 ) ;
}
void F_257 ( struct V_65 * V_66 , unsigned long V_95 ,
bool V_202 , struct V_1 * V_1 )
{
T_13 * V_210 ;
T_14 * V_211 ;
T_4 * V_64 ;
V_210 = F_258 ( V_66 -> V_97 , V_95 ) ;
if ( ! F_259 ( * V_210 ) )
return;
V_211 = F_260 ( V_210 , V_95 ) ;
if ( ! F_261 ( * V_211 ) )
return;
V_64 = F_262 ( V_211 , V_95 ) ;
F_254 ( V_66 , V_64 , V_95 , V_202 , V_1 ) ;
}
void F_263 ( struct V_65 * V_66 ,
unsigned long V_212 ,
unsigned long V_213 ,
long V_214 )
{
if ( V_212 & ~ V_96 &&
( V_212 & V_96 ) >= V_66 -> V_113 &&
( V_212 & V_96 ) + V_43 <= V_66 -> V_114 )
F_257 ( V_66 , V_212 , false , NULL ) ;
if ( V_213 & ~ V_96 &&
( V_213 & V_96 ) >= V_66 -> V_113 &&
( V_213 & V_96 ) + V_43 <= V_66 -> V_114 )
F_257 ( V_66 , V_213 , false , NULL ) ;
if ( V_214 > 0 ) {
struct V_65 * V_184 = V_66 -> V_215 ;
unsigned long V_216 = V_184 -> V_113 ;
V_216 += V_214 << V_60 ;
if ( V_216 & ~ V_96 &&
( V_216 & V_96 ) >= V_184 -> V_113 &&
( V_216 & V_96 ) + V_43 <= V_184 -> V_114 )
F_257 ( V_184 , V_216 , false , NULL ) ;
}
}
static void F_264 ( struct V_1 * V_1 )
{
enum V_217 V_217 = V_218 | V_219 |
V_220 ;
int V_147 , V_35 ;
F_72 ( ! F_136 ( V_1 ) , V_1 ) ;
if ( F_179 ( V_1 ) )
V_217 |= V_221 ;
V_35 = F_265 ( V_1 , V_217 | V_222 ) ;
for ( V_147 = 1 ; ! V_35 && V_147 < V_20 ; V_147 ++ ) {
if ( F_235 ( V_1 ) == 1 )
return;
V_35 = F_265 ( V_1 + V_147 , V_217 ) ;
}
F_72 ( V_35 , V_1 + V_147 - 1 ) ;
}
static void F_266 ( struct V_1 * V_1 )
{
int V_147 ;
for ( V_147 = 0 ; V_147 < V_20 ; V_147 ++ )
F_267 ( V_1 + V_147 , V_1 + V_147 , true ) ;
}
static void F_268 ( struct V_1 * V_223 , int V_224 ,
struct V_225 * V_225 , struct V_69 * V_226 )
{
struct V_1 * V_227 = V_223 + V_224 ;
F_72 ( F_21 ( & V_227 -> V_208 ) != - 1 , V_227 ) ;
F_72 ( F_269 ( V_227 ) != 0 , V_227 ) ;
if ( F_179 ( V_223 ) ) {
F_270 ( V_227 ) ;
} else {
F_236 ( V_227 , 2 ) ;
}
V_227 -> V_15 &= ~ V_228 ;
V_227 -> V_15 |= ( V_223 -> V_15 &
( ( 1L << V_229 ) |
( 1L << V_230 ) |
( 1L << V_231 ) |
( 1L << V_232 ) |
( 1L << V_233 ) |
( 1L << V_234 ) |
( 1L << V_235 ) |
( 1L << V_236 ) ) ) ;
F_163 () ;
F_271 ( V_227 ) ;
if ( F_272 ( V_223 ) )
F_273 ( V_227 ) ;
if ( F_274 ( V_223 ) )
F_275 ( V_227 ) ;
F_72 ( V_224 > 2 && V_227 -> V_70 != V_237 ,
V_227 ) ;
V_227 -> V_70 = V_223 -> V_70 ;
V_227 -> V_238 = V_223 -> V_238 + V_224 ;
F_276 ( V_227 , F_191 ( V_223 ) ) ;
F_277 ( V_223 , V_227 , V_225 , V_226 ) ;
}
static void F_278 ( struct V_1 * V_1 , struct V_69 * V_226 ,
unsigned long V_15 )
{
struct V_1 * V_223 = F_279 ( V_1 ) ;
struct V_239 * V_239 = F_280 ( V_223 ) ;
struct V_225 * V_225 ;
T_15 V_213 = - 1 ;
int V_147 ;
V_225 = F_281 ( V_223 , V_239 -> V_240 ) ;
F_282 ( V_223 ) ;
if ( ! F_179 ( V_1 ) )
V_213 = F_283 ( F_284 ( V_223 -> V_70 -> V_85 ) , V_153 ) ;
for ( V_147 = V_20 - 1 ; V_147 >= 1 ; V_147 -- ) {
F_268 ( V_223 , V_147 , V_225 , V_226 ) ;
if ( V_223 [ V_147 ] . V_238 >= V_213 ) {
F_285 ( V_223 + V_147 ) ;
F_286 ( V_223 + V_147 , NULL ) ;
if ( F_70 ( V_241 ) && F_287 ( V_223 ) )
F_288 ( V_223 -> V_70 -> V_85 , 1 ) ;
F_75 ( V_223 + V_147 ) ;
}
}
F_289 ( V_223 ) ;
if ( F_179 ( V_223 ) ) {
F_270 ( V_223 ) ;
} else {
F_236 ( V_223 , 2 ) ;
F_82 ( & V_223 -> V_70 -> V_242 ) ;
}
F_290 ( F_291 ( F_280 ( V_223 ) ) , V_15 ) ;
F_266 ( V_223 ) ;
for ( V_147 = 0 ; V_147 < V_20 ; V_147 ++ ) {
struct V_1 * V_243 = V_223 + V_147 ;
if ( V_243 == V_1 )
continue;
F_185 ( V_243 ) ;
F_75 ( V_243 ) ;
}
}
int F_292 ( struct V_1 * V_1 )
{
int V_147 , V_244 , V_35 ;
F_72 ( F_293 ( V_1 ) , V_1 ) ;
if ( F_2 ( ! F_73 ( V_1 ) ) )
return F_21 ( & V_1 -> V_208 ) + 1 ;
V_244 = F_180 ( V_1 ) ;
if ( F_294 ( V_1 ) )
return V_244 ;
V_35 = V_244 ;
for ( V_147 = 0 ; V_147 < V_20 ; V_147 ++ )
V_35 += F_21 ( & V_1 [ V_147 ] . V_208 ) + 1 ;
if ( ! F_179 ( V_1 ) )
return V_35 - V_244 * V_20 ;
if ( F_181 ( V_1 ) )
V_35 -= V_20 ;
return V_35 ;
}
int F_169 ( struct V_1 * V_1 , int * F_292 )
{
int V_147 , V_35 , V_245 , V_246 ;
F_72 ( F_294 ( V_1 ) , V_1 ) ;
if ( F_2 ( ! F_295 ( V_1 ) ) ) {
V_246 = F_21 ( & V_1 -> V_208 ) + 1 ;
if ( F_292 )
* F_292 = V_246 ;
return V_246 ;
}
V_1 = F_279 ( V_1 ) ;
V_245 = V_35 = 0 ;
for ( V_147 = 0 ; V_147 < V_20 ; V_147 ++ ) {
V_246 = F_21 ( & V_1 [ V_147 ] . V_208 ) + 1 ;
V_35 = F_296 ( V_35 , V_246 ) ;
V_245 += V_246 ;
}
if ( F_181 ( V_1 ) ) {
V_35 -= 1 ;
V_245 -= V_20 ;
}
V_246 = F_180 ( V_1 ) ;
V_35 += V_246 ;
V_245 += V_246 ;
if ( F_292 )
* F_292 = V_245 ;
return V_35 ;
}
int F_297 ( struct V_1 * V_1 , struct V_69 * V_226 )
{
struct V_1 * V_223 = F_279 ( V_1 ) ;
struct V_247 * V_248 = F_298 ( F_146 ( V_223 ) ) ;
struct V_159 * V_159 = NULL ;
struct V_249 * V_70 = NULL ;
int V_26 , V_246 , V_250 , V_35 ;
bool V_251 ;
unsigned long V_15 ;
F_72 ( F_190 ( V_1 ) , V_1 ) ;
F_72 ( ! F_196 ( V_1 ) , V_1 ) ;
F_72 ( ! F_287 ( V_1 ) , V_1 ) ;
F_72 ( ! F_73 ( V_1 ) , V_1 ) ;
if ( F_179 ( V_223 ) ) {
V_159 = F_299 ( V_223 ) ;
if ( ! V_159 ) {
V_35 = - V_252 ;
goto V_63;
}
V_250 = 0 ;
V_70 = NULL ;
F_300 ( V_159 ) ;
} else {
V_70 = V_223 -> V_70 ;
if ( ! V_70 ) {
V_35 = - V_252 ;
goto V_63;
}
V_250 = V_20 ;
V_159 = NULL ;
F_301 ( V_70 ) ;
}
if ( F_292 ( V_223 ) != F_235 ( V_223 ) - V_250 - 1 ) {
V_35 = - V_252 ;
goto V_144;
}
V_251 = F_255 ( V_1 ) ;
F_264 ( V_223 ) ;
F_72 ( F_180 ( V_223 ) , V_223 ) ;
if ( V_251 )
F_183 () ;
F_302 ( F_291 ( F_280 ( V_223 ) ) , V_15 ) ;
if ( V_70 ) {
void * * V_253 ;
F_168 ( & V_70 -> V_242 ) ;
V_253 = F_303 ( & V_70 -> V_254 ,
F_304 ( V_223 ) ) ;
if ( F_305 ( V_253 ,
& V_70 -> V_242 ) != V_223 )
goto V_255;
}
F_168 ( & V_248 -> V_256 ) ;
V_26 = F_235 ( V_223 ) ;
V_246 = F_292 ( V_223 ) ;
if ( ! V_246 && F_306 ( V_223 , 1 + V_250 ) ) {
if ( ! F_307 ( F_61 ( V_223 ) ) ) {
V_248 -> V_257 -- ;
F_308 ( F_61 ( V_223 ) ) ;
}
if ( V_70 )
F_250 ( V_1 , V_258 ) ;
F_82 ( & V_248 -> V_256 ) ;
F_278 ( V_1 , V_226 , V_15 ) ;
V_35 = 0 ;
} else {
if ( F_70 ( V_259 ) && V_246 ) {
F_309 ( L_19 ,
V_246 , V_26 ) ;
if ( F_293 ( V_1 ) )
F_310 ( V_223 , NULL ) ;
F_310 ( V_1 , L_20 ) ;
F_311 () ;
}
F_82 ( & V_248 -> V_256 ) ;
V_255: if ( V_70 )
F_82 ( & V_70 -> V_242 ) ;
F_290 ( F_291 ( F_280 ( V_223 ) ) , V_15 ) ;
F_266 ( V_223 ) ;
V_35 = - V_252 ;
}
V_144:
if ( V_159 ) {
F_312 ( V_159 ) ;
F_313 ( V_159 ) ;
}
if ( V_70 )
F_314 ( V_70 ) ;
V_63:
F_6 ( ! V_35 ? V_260 : V_261 ) ;
return V_35 ;
}
void F_315 ( struct V_1 * V_1 )
{
struct V_247 * V_248 = F_298 ( F_146 ( V_1 ) ) ;
unsigned long V_15 ;
F_302 ( & V_248 -> V_256 , V_15 ) ;
if ( ! F_307 ( F_61 ( V_1 ) ) ) {
V_248 -> V_257 -- ;
F_308 ( F_61 ( V_1 ) ) ;
}
F_290 ( & V_248 -> V_256 , V_15 ) ;
F_316 ( V_1 ) ;
}
void F_317 ( struct V_1 * V_1 )
{
struct V_247 * V_248 = F_298 ( F_146 ( V_1 ) ) ;
unsigned long V_15 ;
F_72 ( ! F_318 ( V_1 ) , V_1 ) ;
F_302 ( & V_248 -> V_256 , V_15 ) ;
if ( F_307 ( F_61 ( V_1 ) ) ) {
F_6 ( V_262 ) ;
F_319 ( F_61 ( V_1 ) , & V_248 -> V_263 ) ;
V_248 -> V_257 ++ ;
}
F_290 ( & V_248 -> V_256 , V_15 ) ;
}
static unsigned long F_320 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_247 * V_248 = F_298 ( V_19 -> V_264 ) ;
return F_321 ( V_248 -> V_257 ) ;
}
static unsigned long F_322 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_247 * V_248 = F_298 ( V_19 -> V_264 ) ;
unsigned long V_15 ;
F_323 ( V_226 ) , * V_265 , * V_184 ;
struct V_1 * V_1 ;
int V_266 = 0 ;
F_302 ( & V_248 -> V_256 , V_15 ) ;
F_324 (pos, next, &pgdata->split_queue) {
V_1 = F_325 ( ( void * ) V_265 , struct V_1 , V_70 ) ;
V_1 = F_279 ( V_1 ) ;
if ( F_326 ( V_1 ) ) {
F_327 ( F_61 ( V_1 ) , & V_226 ) ;
} else {
F_328 ( F_61 ( V_1 ) ) ;
V_248 -> V_257 -- ;
}
if ( ! -- V_19 -> V_267 )
break;
}
F_290 ( & V_248 -> V_256 , V_15 ) ;
F_324 (pos, next, &list) {
V_1 = F_325 ( ( void * ) V_265 , struct V_1 , V_70 ) ;
F_329 ( V_1 ) ;
if ( ! F_204 ( V_1 ) )
V_266 ++ ;
F_185 ( V_1 ) ;
F_75 ( V_1 ) ;
}
F_302 ( & V_248 -> V_256 , V_15 ) ;
F_330 ( & V_226 , & V_248 -> V_263 ) ;
F_290 ( & V_248 -> V_256 , V_15 ) ;
if ( ! V_266 && F_307 ( & V_248 -> V_263 ) )
return V_268 ;
return V_266 ;
}
static int F_331 ( void * V_269 , T_16 V_270 )
{
struct V_239 * V_239 ;
struct V_1 * V_1 ;
unsigned long V_117 , V_271 ;
unsigned long V_272 = 0 , V_266 = 0 ;
if ( V_270 != 1 )
return - V_31 ;
F_332 (zone) {
V_271 = F_333 ( V_239 ) ;
for ( V_117 = V_239 -> V_273 ; V_117 < V_271 ; V_117 ++ ) {
if ( ! F_334 ( V_117 ) )
continue;
V_1 = F_127 ( V_117 ) ;
if ( ! F_326 ( V_1 ) )
continue;
if ( V_239 != F_280 ( V_1 ) )
goto V_184;
if ( ! F_136 ( V_1 ) || F_294 ( V_1 ) || ! F_335 ( V_1 ) )
goto V_184;
V_272 ++ ;
F_329 ( V_1 ) ;
if ( ! F_204 ( V_1 ) )
V_266 ++ ;
F_185 ( V_1 ) ;
V_184:
F_75 ( V_1 ) ;
}
}
F_336 ( L_21 , V_266 , V_272 ) ;
return 0 ;
}
static int T_3 F_337 ( void )
{
void * V_35 ;
V_35 = F_338 ( L_22 , 0200 , NULL , NULL ,
& V_274 ) ;
if ( ! V_35 )
F_58 ( L_23 ) ;
return 0 ;
}
