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
return F_32 ( V_22 , V_24 , V_25 ,
V_43 ) ;
}
static T_1 F_40 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
const char * V_25 , T_2 V_26 )
{
return F_33 ( V_22 , V_24 , V_25 , V_26 ,
V_43 ) ;
}
static int T_3 F_41 ( struct V_21 * * V_44 )
{
int V_36 ;
* V_44 = F_42 ( L_13 , V_45 ) ;
if ( F_43 ( ! * V_44 ) ) {
F_44 ( L_14 ) ;
return - V_46 ;
}
V_36 = F_45 ( * V_44 , & V_47 ) ;
if ( V_36 ) {
F_44 ( L_15 ) ;
goto V_48;
}
V_36 = F_45 ( * V_44 , & V_49 ) ;
if ( V_36 ) {
F_44 ( L_15 ) ;
goto V_50;
}
return 0 ;
V_50:
F_46 ( * V_44 , & V_47 ) ;
V_48:
F_47 ( * V_44 ) ;
return V_36 ;
}
static void T_3 F_48 ( struct V_21 * V_44 )
{
F_46 ( V_44 , & V_49 ) ;
F_46 ( V_44 , & V_47 ) ;
F_47 ( V_44 ) ;
}
static inline int F_41 ( struct V_21 * * V_44 )
{
return 0 ;
}
static inline void F_48 ( struct V_21 * V_44 )
{
}
static int T_3 F_49 ( void )
{
int V_36 ;
struct V_21 * V_44 ;
if ( ! F_50 () ) {
V_32 = 0 ;
return - V_31 ;
}
F_51 ( V_9 >= V_51 ) ;
F_51 ( V_9 < 2 ) ;
V_36 = F_41 ( & V_44 ) ;
if ( V_36 )
goto V_52;
V_36 = F_52 () ;
if ( V_36 )
goto V_53;
V_36 = F_53 ( & V_54 ) ;
if ( V_36 )
goto V_55;
V_36 = F_53 ( & V_56 ) ;
if ( V_36 )
goto V_57;
if ( V_58 < ( 512 << ( 20 - V_59 ) ) ) {
V_32 = 0 ;
return 0 ;
}
V_36 = F_31 () ;
if ( V_36 )
goto V_60;
return 0 ;
V_60:
F_54 ( & V_56 ) ;
V_57:
F_54 ( & V_54 ) ;
V_55:
F_55 () ;
V_53:
F_48 ( V_44 ) ;
V_52:
return V_36 ;
}
static int T_3 F_56 ( char * V_61 )
{
int V_35 = 0 ;
if ( ! V_61 )
goto V_62;
if ( ! strcmp ( V_61 , L_2 ) ) {
F_28 ( V_33 ,
& V_32 ) ;
F_27 ( V_34 ,
& V_32 ) ;
V_35 = 1 ;
} else if ( ! strcmp ( V_61 , L_3 ) ) {
F_27 ( V_33 ,
& V_32 ) ;
F_28 ( V_34 ,
& V_32 ) ;
V_35 = 1 ;
} else if ( ! strcmp ( V_61 , L_4 ) ) {
F_27 ( V_33 ,
& V_32 ) ;
F_27 ( V_34 ,
& V_32 ) ;
V_35 = 1 ;
}
V_62:
if ( ! V_35 )
F_57 ( L_16 ) ;
return V_35 ;
}
T_4 F_58 ( T_4 V_63 , struct V_64 * V_65 )
{
if ( F_2 ( V_65 -> V_66 & V_67 ) )
V_63 = F_59 ( V_63 ) ;
return V_63 ;
}
static inline struct V_68 * F_60 ( struct V_1 * V_1 )
{
return (struct V_68 * ) & V_1 [ 2 ] . V_69 ;
}
void F_61 ( struct V_1 * V_1 )
{
F_62 ( F_60 ( V_1 ) ) ;
F_63 ( V_1 , V_70 ) ;
}
unsigned long F_64 ( struct V_71 * V_72 , unsigned long V_73 ,
T_5 V_74 , unsigned long V_15 , unsigned long V_75 )
{
unsigned long V_76 ;
T_5 V_77 = V_74 + V_73 ;
T_5 V_78 = F_65 ( V_74 , V_75 ) ;
unsigned long V_79 ;
if ( V_77 <= V_78 || ( V_77 - V_78 ) < V_75 )
return 0 ;
V_79 = V_73 + V_75 ;
if ( V_79 < V_73 || ( V_74 + V_79 ) < V_74 )
return 0 ;
V_76 = V_80 -> V_13 -> V_81 ( V_72 , 0 , V_79 ,
V_74 >> V_59 , V_15 ) ;
if ( F_66 ( V_76 ) )
return 0 ;
V_76 += ( V_74 - V_76 ) & ( V_75 - 1 ) ;
return V_76 ;
}
unsigned long F_67 ( struct V_71 * V_72 , unsigned long V_76 ,
unsigned long V_73 , unsigned long V_82 , unsigned long V_15 )
{
T_5 V_74 = ( T_5 ) V_82 << V_59 ;
if ( V_76 )
goto V_62;
if ( ! F_68 ( V_72 -> V_83 -> V_84 ) || ! F_69 ( V_85 ) )
goto V_62;
V_76 = F_64 ( V_72 , V_73 , V_74 , V_15 , V_86 ) ;
if ( V_76 )
return V_76 ;
V_62:
return V_80 -> V_13 -> V_81 ( V_72 , V_76 , V_73 , V_82 , V_15 ) ;
}
static int F_70 ( struct V_87 * V_88 , struct V_1 * V_1 ,
T_6 V_89 )
{
struct V_64 * V_65 = V_88 -> V_65 ;
struct V_90 * V_91 ;
T_7 V_92 ;
unsigned long V_93 = V_88 -> V_94 & V_95 ;
F_71 ( ! F_72 ( V_1 ) , V_1 ) ;
if ( F_73 ( V_1 , V_65 -> V_96 , V_89 , & V_91 , true ) ) {
F_74 ( V_1 ) ;
F_6 ( V_97 ) ;
return V_98 ;
}
V_92 = F_75 ( V_65 -> V_96 , V_93 ) ;
if ( F_43 ( ! V_92 ) ) {
F_76 ( V_1 , V_91 , true ) ;
F_74 ( V_1 ) ;
return V_99 ;
}
F_77 ( V_1 , V_93 , V_20 ) ;
F_78 ( V_1 ) ;
V_88 -> V_100 = F_79 ( V_65 -> V_96 , V_88 -> V_63 ) ;
if ( F_43 ( ! F_80 ( * V_88 -> V_63 ) ) ) {
F_81 ( V_88 -> V_100 ) ;
F_76 ( V_1 , V_91 , true ) ;
F_74 ( V_1 ) ;
F_82 ( V_65 -> V_96 , V_92 ) ;
} else {
T_4 V_101 ;
if ( F_83 ( V_65 ) ) {
int V_35 ;
F_81 ( V_88 -> V_100 ) ;
F_76 ( V_1 , V_91 , true ) ;
F_74 ( V_1 ) ;
F_82 ( V_65 -> V_96 , V_92 ) ;
V_35 = F_84 ( V_88 , V_102 ) ;
F_85 ( V_35 & V_98 ) ;
return V_35 ;
}
V_101 = F_86 ( V_1 , V_65 -> V_103 ) ;
V_101 = F_58 ( F_87 ( V_101 ) , V_65 ) ;
F_88 ( V_1 , V_65 , V_93 , true ) ;
F_89 ( V_1 , V_91 , false , true ) ;
F_90 ( V_1 , V_65 ) ;
F_91 ( V_65 -> V_96 , V_88 -> V_63 , V_92 ) ;
F_92 ( V_65 -> V_96 , V_93 , V_88 -> V_63 , V_101 ) ;
F_93 ( V_65 -> V_96 , V_104 , V_20 ) ;
F_94 ( & V_65 -> V_96 -> V_105 ) ;
F_81 ( V_88 -> V_100 ) ;
F_6 ( V_106 ) ;
}
return 0 ;
}
static inline T_6 F_95 ( struct V_64 * V_65 )
{
bool V_107 = ! ! ( V_65 -> V_66 & V_108 ) ;
if ( F_17 ( V_41 ,
& V_32 ) && V_107 )
return V_6 ;
else if ( F_17 ( V_40 ,
& V_32 ) )
return V_109 | V_110 ;
else if ( F_17 ( V_39 ,
& V_32 ) )
return V_6 | ( V_107 ? 0 : V_111 ) ;
return V_109 ;
}
static bool F_96 ( T_7 V_92 , struct V_12 * V_13 ,
struct V_64 * V_65 , unsigned long V_93 , T_4 * V_63 ,
struct V_1 * V_2 )
{
T_4 V_101 ;
if ( ! F_80 ( * V_63 ) )
return false ;
V_101 = F_97 ( V_2 , V_65 -> V_103 ) ;
V_101 = F_98 ( V_101 ) ;
if ( V_92 )
F_91 ( V_13 , V_63 , V_92 ) ;
F_92 ( V_13 , V_93 , V_63 , V_101 ) ;
F_94 ( & V_13 -> V_105 ) ;
return true ;
}
int F_99 ( struct V_87 * V_88 )
{
struct V_64 * V_65 = V_88 -> V_65 ;
T_6 V_89 ;
struct V_1 * V_1 ;
unsigned long V_93 = V_88 -> V_94 & V_95 ;
if ( V_93 < V_65 -> V_112 || V_93 + V_113 > V_65 -> V_114 )
return V_98 ;
if ( F_43 ( F_100 ( V_65 ) ) )
return V_99 ;
if ( F_43 ( F_101 ( V_65 , V_65 -> V_66 ) ) )
return V_99 ;
if ( ! ( V_88 -> V_15 & V_115 ) &&
! F_102 ( V_65 -> V_96 ) &&
F_103 () ) {
T_7 V_92 ;
struct V_1 * V_2 ;
bool V_116 ;
int V_35 ;
V_92 = F_75 ( V_65 -> V_96 , V_93 ) ;
if ( F_43 ( ! V_92 ) )
return V_99 ;
V_2 = F_16 ( V_65 -> V_96 ) ;
if ( F_43 ( ! V_2 ) ) {
F_82 ( V_65 -> V_96 , V_92 ) ;
F_6 ( V_97 ) ;
return V_98 ;
}
V_88 -> V_100 = F_79 ( V_65 -> V_96 , V_88 -> V_63 ) ;
V_35 = 0 ;
V_116 = false ;
if ( F_80 ( * V_88 -> V_63 ) ) {
if ( F_83 ( V_65 ) ) {
F_81 ( V_88 -> V_100 ) ;
V_35 = F_84 ( V_88 , V_102 ) ;
F_85 ( V_35 & V_98 ) ;
} else {
F_96 ( V_92 , V_65 -> V_96 , V_65 ,
V_93 , V_88 -> V_63 , V_2 ) ;
F_81 ( V_88 -> V_100 ) ;
V_116 = true ;
}
} else
F_81 ( V_88 -> V_100 ) ;
if ( ! V_116 )
F_82 ( V_65 -> V_96 , V_92 ) ;
return V_35 ;
}
V_89 = F_95 ( V_65 ) ;
V_1 = F_104 ( V_89 , V_65 , V_93 , V_9 ) ;
if ( F_43 ( ! V_1 ) ) {
F_6 ( V_97 ) ;
return V_98 ;
}
F_61 ( V_1 ) ;
return F_70 ( V_88 , V_1 , V_89 ) ;
}
static void F_105 ( struct V_64 * V_65 , unsigned long V_76 ,
T_4 * V_63 , T_8 V_117 , T_9 V_118 , bool V_119 )
{
struct V_12 * V_13 = V_65 -> V_96 ;
T_4 V_101 ;
T_10 * V_100 ;
V_100 = F_79 ( V_13 , V_63 ) ;
V_101 = F_98 ( F_106 ( V_117 , V_118 ) ) ;
if ( F_107 ( V_117 ) )
V_101 = F_108 ( V_101 ) ;
if ( V_119 ) {
V_101 = F_109 ( F_87 ( V_101 ) ) ;
V_101 = F_58 ( V_101 , V_65 ) ;
}
F_92 ( V_13 , V_76 , V_63 , V_101 ) ;
F_110 ( V_65 , V_76 , V_63 ) ;
F_81 ( V_100 ) ;
}
int F_111 ( struct V_64 * V_65 , unsigned long V_76 ,
T_4 * V_63 , T_8 V_117 , bool V_119 )
{
T_9 V_120 = V_65 -> V_103 ;
F_14 ( ! ( V_65 -> V_66 & ( V_121 | V_122 ) ) ) ;
F_14 ( ( V_65 -> V_66 & ( V_121 | V_122 ) ) ==
( V_121 | V_122 ) ) ;
F_14 ( ( V_65 -> V_66 & V_121 ) && F_112 ( V_65 -> V_66 ) ) ;
F_14 ( ! F_107 ( V_117 ) ) ;
if ( V_76 < V_65 -> V_112 || V_76 >= V_65 -> V_114 )
return V_123 ;
if ( F_113 ( V_65 , & V_120 , V_117 ) )
return V_123 ;
F_105 ( V_65 , V_76 , V_63 , V_117 , V_120 , V_119 ) ;
return V_124 ;
}
static void F_114 ( struct V_64 * V_65 , unsigned long V_76 ,
T_4 * V_63 )
{
T_4 V_125 ;
V_125 = F_109 ( F_87 ( * V_63 ) ) ;
if ( F_115 ( V_65 , V_76 & V_95 ,
V_63 , V_125 , 1 ) )
F_110 ( V_65 , V_76 , V_63 ) ;
}
struct V_1 * F_116 ( struct V_64 * V_65 , unsigned long V_76 ,
T_4 * V_63 , int V_15 )
{
unsigned long V_117 = F_117 ( * V_63 ) ;
struct V_12 * V_13 = V_65 -> V_96 ;
struct V_126 * V_127 ;
struct V_1 * V_1 ;
F_118 ( F_119 ( V_13 , V_63 ) ) ;
if ( V_15 & V_128 && ! F_120 ( * V_63 ) )
return NULL ;
if ( F_121 ( * V_63 ) && F_122 ( * V_63 ) )
;
else
return NULL ;
if ( V_15 & V_129 )
F_114 ( V_65 , V_76 , V_63 ) ;
if ( ! ( V_15 & V_130 ) )
return F_123 ( - V_131 ) ;
V_117 += ( V_76 & ~ V_132 ) >> V_59 ;
V_127 = F_124 ( V_117 , NULL ) ;
if ( ! V_127 )
return F_123 ( - V_133 ) ;
V_1 = F_125 ( V_117 ) ;
F_126 ( V_1 ) ;
F_127 ( V_127 ) ;
return V_1 ;
}
int F_128 ( struct V_12 * V_134 , struct V_12 * V_135 ,
T_4 * V_136 , T_4 * V_137 , unsigned long V_76 ,
struct V_64 * V_65 )
{
T_10 * V_138 , * V_139 ;
struct V_1 * V_140 ;
T_4 V_63 ;
T_7 V_92 = NULL ;
int V_35 = - V_46 ;
if ( ! F_129 ( V_65 ) )
return 0 ;
V_92 = F_75 ( V_134 , V_76 ) ;
if ( F_43 ( ! V_92 ) )
goto V_62;
V_138 = F_79 ( V_134 , V_136 ) ;
V_139 = F_119 ( V_135 , V_137 ) ;
F_130 ( V_139 , V_141 ) ;
V_35 = - V_142 ;
V_63 = * V_137 ;
if ( F_43 ( ! F_131 ( V_63 ) ) ) {
F_82 ( V_134 , V_92 ) ;
goto V_143;
}
if ( F_132 ( V_63 ) ) {
struct V_1 * V_2 ;
V_2 = F_16 ( V_134 ) ;
F_96 ( V_92 , V_134 , V_65 , V_76 , V_136 ,
V_2 ) ;
V_35 = 0 ;
goto V_143;
}
V_140 = F_133 ( V_63 ) ;
F_71 ( ! F_134 ( V_140 ) , V_140 ) ;
F_126 ( V_140 ) ;
F_135 ( V_140 , true ) ;
F_93 ( V_134 , V_104 , V_20 ) ;
F_94 ( & V_134 -> V_105 ) ;
F_91 ( V_134 , V_136 , V_92 ) ;
F_136 ( V_135 , V_76 , V_137 ) ;
V_63 = F_137 ( F_138 ( V_63 ) ) ;
F_92 ( V_134 , V_76 , V_136 , V_63 ) ;
V_35 = 0 ;
V_143:
F_81 ( V_139 ) ;
F_81 ( V_138 ) ;
V_62:
return V_35 ;
}
void F_139 ( struct V_87 * V_88 , T_4 V_144 )
{
T_4 V_101 ;
unsigned long V_93 ;
V_88 -> V_100 = F_79 ( V_88 -> V_65 -> V_96 , V_88 -> V_63 ) ;
if ( F_43 ( ! F_140 ( * V_88 -> V_63 , V_144 ) ) )
goto V_145;
V_101 = F_109 ( V_144 ) ;
V_93 = V_88 -> V_94 & V_95 ;
if ( F_115 ( V_88 -> V_65 , V_93 , V_88 -> V_63 , V_101 ,
V_88 -> V_15 & V_115 ) )
F_110 ( V_88 -> V_65 , V_88 -> V_94 , V_88 -> V_63 ) ;
V_145:
F_81 ( V_88 -> V_100 ) ;
}
static int F_141 ( struct V_87 * V_88 , T_4 V_144 ,
struct V_1 * V_1 )
{
struct V_64 * V_65 = V_88 -> V_65 ;
unsigned long V_93 = V_88 -> V_94 & V_95 ;
struct V_90 * V_91 ;
T_7 V_92 ;
T_4 V_125 ;
int V_35 = 0 , V_146 ;
struct V_1 * * V_147 ;
unsigned long V_148 ;
unsigned long V_149 ;
V_147 = F_142 ( sizeof( struct V_1 * ) * V_20 ,
V_150 ) ;
if ( F_43 ( ! V_147 ) ) {
V_35 |= V_99 ;
goto V_62;
}
for ( V_146 = 0 ; V_146 < V_20 ; V_146 ++ ) {
V_147 [ V_146 ] = F_143 ( V_151 |
V_152 , V_65 ,
V_88 -> V_94 , F_144 ( V_1 ) ) ;
if ( F_43 ( ! V_147 [ V_146 ] ||
F_73 ( V_147 [ V_146 ] , V_65 -> V_96 ,
V_150 , & V_91 , false ) ) ) {
if ( V_147 [ V_146 ] )
F_74 ( V_147 [ V_146 ] ) ;
while ( -- V_146 >= 0 ) {
V_91 = ( void * ) F_145 ( V_147 [ V_146 ] ) ;
F_146 ( V_147 [ V_146 ] , 0 ) ;
F_76 ( V_147 [ V_146 ] , V_91 ,
false ) ;
F_74 ( V_147 [ V_146 ] ) ;
}
F_147 ( V_147 ) ;
V_35 |= V_99 ;
goto V_62;
}
F_146 ( V_147 [ V_146 ] , ( unsigned long ) V_91 ) ;
}
for ( V_146 = 0 ; V_146 < V_20 ; V_146 ++ ) {
F_148 ( V_147 [ V_146 ] , V_1 + V_146 ,
V_93 + V_153 * V_146 , V_65 ) ;
F_78 ( V_147 [ V_146 ] ) ;
F_149 () ;
}
V_148 = V_93 ;
V_149 = V_93 + V_113 ;
F_150 ( V_65 -> V_96 , V_148 , V_149 ) ;
V_88 -> V_100 = F_79 ( V_65 -> V_96 , V_88 -> V_63 ) ;
if ( F_43 ( ! F_140 ( * V_88 -> V_63 , V_144 ) ) )
goto V_154;
F_71 ( ! F_134 ( V_1 ) , V_1 ) ;
F_151 ( V_65 , V_93 , V_88 -> V_63 ) ;
V_92 = F_152 ( V_65 -> V_96 , V_88 -> V_63 ) ;
F_153 ( V_65 -> V_96 , & V_125 , V_92 ) ;
for ( V_146 = 0 ; V_146 < V_20 ; V_146 ++ , V_93 += V_153 ) {
T_11 V_101 ;
V_101 = F_154 ( V_147 [ V_146 ] , V_65 -> V_103 ) ;
V_101 = F_155 ( F_156 ( V_101 ) , V_65 ) ;
V_91 = ( void * ) F_145 ( V_147 [ V_146 ] ) ;
F_146 ( V_147 [ V_146 ] , 0 ) ;
F_88 ( V_147 [ V_146 ] , V_88 -> V_65 , V_93 , false ) ;
F_89 ( V_147 [ V_146 ] , V_91 , false , false ) ;
F_90 ( V_147 [ V_146 ] , V_65 ) ;
V_88 -> V_155 = F_157 ( & V_125 , V_93 ) ;
F_85 ( ! F_158 ( * V_88 -> V_155 ) ) ;
F_159 ( V_65 -> V_96 , V_93 , V_88 -> V_155 , V_101 ) ;
F_160 ( V_88 -> V_155 ) ;
}
F_147 ( V_147 ) ;
F_161 () ;
F_153 ( V_65 -> V_96 , V_88 -> V_63 , V_92 ) ;
F_162 ( V_1 , true ) ;
F_81 ( V_88 -> V_100 ) ;
F_163 ( V_65 -> V_96 , V_148 , V_149 ) ;
V_35 |= V_156 ;
F_74 ( V_1 ) ;
V_62:
return V_35 ;
V_154:
F_81 ( V_88 -> V_100 ) ;
F_163 ( V_65 -> V_96 , V_148 , V_149 ) ;
for ( V_146 = 0 ; V_146 < V_20 ; V_146 ++ ) {
V_91 = ( void * ) F_145 ( V_147 [ V_146 ] ) ;
F_146 ( V_147 [ V_146 ] , 0 ) ;
F_76 ( V_147 [ V_146 ] , V_91 , false ) ;
F_74 ( V_147 [ V_146 ] ) ;
}
F_147 ( V_147 ) ;
goto V_62;
}
int F_164 ( struct V_87 * V_88 , T_4 V_144 )
{
struct V_64 * V_65 = V_88 -> V_65 ;
struct V_1 * V_1 = NULL , * V_157 ;
struct V_90 * V_91 ;
unsigned long V_93 = V_88 -> V_94 & V_95 ;
unsigned long V_148 ;
unsigned long V_149 ;
T_6 V_158 ;
int V_35 = 0 ;
V_88 -> V_100 = F_119 ( V_65 -> V_96 , V_88 -> V_63 ) ;
F_165 ( ! V_65 -> V_159 , V_65 ) ;
if ( F_132 ( V_144 ) )
goto V_160;
F_166 ( V_88 -> V_100 ) ;
if ( F_43 ( ! F_140 ( * V_88 -> V_63 , V_144 ) ) )
goto V_143;
V_1 = F_133 ( V_144 ) ;
F_71 ( ! F_72 ( V_1 ) || ! F_134 ( V_1 ) , V_1 ) ;
if ( F_167 ( V_1 , NULL ) == 1 ) {
T_4 V_101 ;
V_101 = F_109 ( V_144 ) ;
V_101 = F_58 ( F_87 ( V_101 ) , V_65 ) ;
if ( F_115 ( V_65 , V_93 , V_88 -> V_63 , V_101 , 1 ) )
F_110 ( V_65 , V_88 -> V_94 , V_88 -> V_63 ) ;
V_35 |= V_156 ;
goto V_143;
}
F_126 ( V_1 ) ;
F_81 ( V_88 -> V_100 ) ;
V_160:
if ( F_168 ( V_65 ) &&
! F_169 () ) {
V_158 = F_95 ( V_65 ) ;
V_157 = F_104 ( V_158 , V_65 , V_93 , V_9 ) ;
} else
V_157 = NULL ;
if ( F_2 ( V_157 ) ) {
F_61 ( V_157 ) ;
} else {
if ( ! V_1 ) {
F_170 ( V_65 , V_88 -> V_63 , V_88 -> V_94 ) ;
V_35 |= V_98 ;
} else {
V_35 = F_141 ( V_88 , V_144 , V_1 ) ;
if ( V_35 & V_99 ) {
F_170 ( V_65 , V_88 -> V_63 , V_88 -> V_94 ) ;
V_35 |= V_98 ;
}
F_74 ( V_1 ) ;
}
F_6 ( V_97 ) ;
goto V_62;
}
if ( F_43 ( F_73 ( V_157 , V_65 -> V_96 ,
V_158 , & V_91 , true ) ) ) {
F_74 ( V_157 ) ;
F_170 ( V_65 , V_88 -> V_63 , V_88 -> V_94 ) ;
if ( V_1 )
F_74 ( V_1 ) ;
V_35 |= V_98 ;
F_6 ( V_97 ) ;
goto V_62;
}
F_6 ( V_106 ) ;
if ( ! V_1 )
F_77 ( V_157 , V_93 , V_20 ) ;
else
F_171 ( V_157 , V_1 , V_93 , V_65 , V_20 ) ;
F_78 ( V_157 ) ;
V_148 = V_93 ;
V_149 = V_93 + V_113 ;
F_150 ( V_65 -> V_96 , V_148 , V_149 ) ;
F_166 ( V_88 -> V_100 ) ;
if ( V_1 )
F_74 ( V_1 ) ;
if ( F_43 ( ! F_140 ( * V_88 -> V_63 , V_144 ) ) ) {
F_81 ( V_88 -> V_100 ) ;
F_76 ( V_157 , V_91 , true ) ;
F_74 ( V_157 ) ;
goto V_161;
} else {
T_4 V_101 ;
V_101 = F_86 ( V_157 , V_65 -> V_103 ) ;
V_101 = F_58 ( F_87 ( V_101 ) , V_65 ) ;
F_151 ( V_65 , V_93 , V_88 -> V_63 ) ;
F_88 ( V_157 , V_65 , V_93 , true ) ;
F_89 ( V_157 , V_91 , false , true ) ;
F_90 ( V_157 , V_65 ) ;
F_92 ( V_65 -> V_96 , V_93 , V_88 -> V_63 , V_101 ) ;
F_110 ( V_65 , V_88 -> V_94 , V_88 -> V_63 ) ;
if ( ! V_1 ) {
F_93 ( V_65 -> V_96 , V_104 , V_20 ) ;
} else {
F_71 ( ! F_134 ( V_1 ) , V_1 ) ;
F_162 ( V_1 , true ) ;
F_74 ( V_1 ) ;
}
V_35 |= V_156 ;
}
F_81 ( V_88 -> V_100 ) ;
V_161:
F_163 ( V_65 -> V_96 , V_148 , V_149 ) ;
V_62:
return V_35 ;
V_143:
F_81 ( V_88 -> V_100 ) ;
return V_35 ;
}
struct V_1 * F_172 ( struct V_64 * V_65 ,
unsigned long V_76 ,
T_4 * V_63 ,
unsigned int V_15 )
{
struct V_12 * V_13 = V_65 -> V_96 ;
struct V_1 * V_1 = NULL ;
F_118 ( F_119 ( V_13 , V_63 ) ) ;
if ( V_15 & V_128 && ! F_120 ( * V_63 ) )
goto V_62;
if ( ( V_15 & V_162 ) && F_132 ( * V_63 ) )
return F_123 ( - V_133 ) ;
if ( ( V_15 & V_163 ) && F_173 ( * V_63 ) )
goto V_62;
V_1 = F_133 ( * V_63 ) ;
F_71 ( ! F_134 ( V_1 ) && ! F_174 ( V_1 ) , V_1 ) ;
if ( V_15 & V_129 )
F_114 ( V_65 , V_76 , V_63 ) ;
if ( ( V_15 & V_164 ) && ( V_65 -> V_66 & V_165 ) ) {
if ( F_175 ( V_1 ) && F_176 ( V_1 ) != 1 )
goto V_166;
if ( F_177 ( V_1 ) || ! V_1 -> V_69 )
goto V_166;
if ( ! F_178 ( V_1 ) )
goto V_166;
F_179 () ;
if ( V_1 -> V_69 && ! F_177 ( V_1 ) )
F_180 ( V_1 ) ;
F_181 ( V_1 ) ;
}
V_166:
V_1 += ( V_76 & ~ V_95 ) >> V_59 ;
F_71 ( ! F_72 ( V_1 ) && ! F_174 ( V_1 ) , V_1 ) ;
if ( V_15 & V_130 )
F_126 ( V_1 ) ;
V_62:
return V_1 ;
}
int F_182 ( struct V_87 * V_88 , T_4 V_63 )
{
struct V_64 * V_65 = V_88 -> V_65 ;
struct V_159 * V_159 = NULL ;
struct V_1 * V_1 ;
unsigned long V_93 = V_88 -> V_94 & V_95 ;
int V_167 = - 1 , V_168 = F_183 () ;
int V_169 , V_170 = - 1 ;
bool V_171 ;
bool V_172 = false ;
bool V_173 ;
int V_15 = 0 ;
V_88 -> V_100 = F_79 ( V_65 -> V_96 , V_88 -> V_63 ) ;
if ( F_43 ( ! F_140 ( V_63 , * V_88 -> V_63 ) ) )
goto V_143;
if ( F_43 ( F_184 ( * V_88 -> V_63 ) ) ) {
V_1 = F_133 ( * V_88 -> V_63 ) ;
F_81 ( V_88 -> V_100 ) ;
F_185 ( V_1 ) ;
goto V_62;
}
V_1 = F_133 ( V_63 ) ;
F_14 ( F_186 ( V_1 ) ) ;
V_167 = F_144 ( V_1 ) ;
V_170 = F_187 ( V_1 ) ;
F_188 ( V_174 ) ;
if ( V_167 == V_168 ) {
F_188 ( V_175 ) ;
V_15 |= V_176 ;
}
if ( ! F_120 ( V_63 ) )
V_15 |= V_177 ;
V_171 = F_178 ( V_1 ) ;
V_169 = F_189 ( V_1 , V_65 , V_93 ) ;
if ( V_169 == - 1 ) {
if ( V_171 )
goto V_178;
}
if ( ! V_171 ) {
F_81 ( V_88 -> V_100 ) ;
F_185 ( V_1 ) ;
V_167 = - 1 ;
goto V_62;
}
F_126 ( V_1 ) ;
F_81 ( V_88 -> V_100 ) ;
V_159 = F_190 ( V_1 ) ;
F_166 ( V_88 -> V_100 ) ;
if ( F_43 ( ! F_140 ( V_63 , * V_88 -> V_63 ) ) ) {
F_181 ( V_1 ) ;
F_74 ( V_1 ) ;
V_167 = - 1 ;
goto V_143;
}
if ( F_43 ( ! V_159 ) ) {
F_74 ( V_1 ) ;
V_167 = - 1 ;
goto V_178;
}
F_81 ( V_88 -> V_100 ) ;
V_172 = F_191 ( V_65 -> V_96 , V_65 ,
V_88 -> V_63 , V_63 , V_88 -> V_94 , V_1 , V_169 ) ;
if ( V_172 ) {
V_15 |= V_179 ;
V_167 = V_169 ;
} else
V_15 |= V_180 ;
goto V_62;
V_178:
F_14 ( ! F_192 ( V_1 ) ) ;
V_173 = F_120 ( V_63 ) ;
V_63 = F_193 ( V_63 , V_65 -> V_103 ) ;
V_63 = F_109 ( V_63 ) ;
if ( V_173 )
V_63 = F_59 ( V_63 ) ;
F_92 ( V_65 -> V_96 , V_93 , V_88 -> V_63 , V_63 ) ;
F_110 ( V_65 , V_88 -> V_94 , V_88 -> V_63 ) ;
F_181 ( V_1 ) ;
V_143:
F_81 ( V_88 -> V_100 ) ;
V_62:
if ( V_159 )
F_194 ( V_159 ) ;
if ( V_167 != - 1 )
F_195 ( V_170 , V_167 , V_20 , V_88 -> V_15 ) ;
return 0 ;
}
bool F_196 ( struct V_181 * V_182 , struct V_64 * V_65 ,
T_4 * V_63 , unsigned long V_76 , unsigned long V_183 )
{
T_10 * V_100 ;
T_4 V_144 ;
struct V_1 * V_1 ;
struct V_12 * V_13 = V_182 -> V_13 ;
bool V_35 = false ;
V_100 = F_197 ( V_63 , V_65 ) ;
if ( ! V_100 )
goto V_184;
V_144 = * V_63 ;
if ( F_132 ( V_144 ) )
goto V_62;
V_1 = F_133 ( V_144 ) ;
if ( F_198 ( V_1 ) != 1 )
goto V_62;
if ( ! F_178 ( V_1 ) )
goto V_62;
if ( V_183 - V_76 != V_113 ) {
F_126 ( V_1 ) ;
F_81 ( V_100 ) ;
F_199 ( V_1 ) ;
F_74 ( V_1 ) ;
F_181 ( V_1 ) ;
goto V_184;
}
if ( F_200 ( V_1 ) )
F_201 ( V_1 ) ;
F_181 ( V_1 ) ;
if ( F_202 ( V_1 ) )
F_203 ( V_1 ) ;
if ( F_204 ( V_144 ) || F_205 ( V_144 ) ) {
V_144 = F_206 ( V_182 -> V_13 , V_76 , V_63 ,
V_182 -> V_185 ) ;
V_144 = F_137 ( V_144 ) ;
V_144 = F_207 ( V_144 ) ;
F_92 ( V_13 , V_76 , V_63 , V_144 ) ;
F_208 ( V_182 , V_63 , V_76 ) ;
}
V_35 = true ;
V_62:
F_81 ( V_100 ) ;
V_184:
return V_35 ;
}
int F_209 ( struct V_181 * V_182 , struct V_64 * V_65 ,
T_4 * V_63 , unsigned long V_76 )
{
T_4 V_144 ;
T_10 * V_100 ;
V_100 = F_210 ( V_63 , V_65 ) ;
if ( ! V_100 )
return 0 ;
V_144 = F_206 ( V_182 -> V_13 , V_76 , V_63 ,
V_182 -> V_185 ) ;
F_208 ( V_182 , V_63 , V_76 ) ;
if ( F_211 ( V_65 ) ) {
F_81 ( V_100 ) ;
if ( F_132 ( V_144 ) )
F_212 ( V_182 , F_133 ( V_144 ) ) ;
} else if ( F_132 ( V_144 ) ) {
F_82 ( V_182 -> V_13 , F_152 ( V_182 -> V_13 , V_63 ) ) ;
F_213 ( & V_182 -> V_13 -> V_105 ) ;
F_81 ( V_100 ) ;
F_212 ( V_182 , F_133 ( V_144 ) ) ;
} else {
struct V_1 * V_1 = F_133 ( V_144 ) ;
F_162 ( V_1 , true ) ;
F_71 ( F_198 ( V_1 ) < 0 , V_1 ) ;
F_71 ( ! F_134 ( V_1 ) , V_1 ) ;
if ( F_175 ( V_1 ) ) {
T_7 V_92 ;
V_92 = F_152 ( V_182 -> V_13 , V_63 ) ;
F_82 ( V_182 -> V_13 , V_92 ) ;
F_213 ( & V_182 -> V_13 -> V_105 ) ;
F_93 ( V_182 -> V_13 , V_104 , - V_20 ) ;
} else {
F_93 ( V_182 -> V_13 , V_186 , - V_20 ) ;
}
F_81 ( V_100 ) ;
F_214 ( V_182 , V_1 , V_113 ) ;
}
return 1 ;
}
bool F_215 ( struct V_64 * V_65 , unsigned long V_187 ,
unsigned long V_188 , unsigned long V_189 ,
T_4 * V_190 , T_4 * V_191 , bool * V_192 )
{
T_10 * V_193 , * V_194 ;
T_4 V_63 ;
struct V_12 * V_13 = V_65 -> V_96 ;
bool V_195 = false ;
if ( ( V_187 & ~ V_95 ) ||
( V_188 & ~ V_95 ) ||
V_189 - V_187 < V_113 )
return false ;
if ( F_216 ( ! F_80 ( * V_191 ) ) ) {
F_85 ( F_131 ( * V_191 ) ) ;
return false ;
}
V_193 = F_210 ( V_190 , V_65 ) ;
if ( V_193 ) {
V_194 = F_119 ( V_13 , V_191 ) ;
if ( V_194 != V_193 )
F_130 ( V_194 , V_141 ) ;
V_63 = F_217 ( V_13 , V_187 , V_190 ) ;
if ( F_121 ( V_63 ) && F_205 ( V_63 ) )
V_195 = true ;
F_85 ( ! F_80 ( * V_191 ) ) ;
if ( F_218 ( V_194 , V_193 ) &&
F_129 ( V_65 ) ) {
T_7 V_92 ;
V_92 = F_152 ( V_13 , V_190 ) ;
F_91 ( V_13 , V_191 , V_92 ) ;
}
F_92 ( V_13 , V_188 , V_191 , F_219 ( V_63 ) ) ;
if ( V_194 != V_193 )
F_81 ( V_194 ) ;
if ( V_195 )
F_220 ( V_65 , V_187 , V_187 + V_86 ) ;
else
* V_192 = true ;
F_81 ( V_193 ) ;
return true ;
}
return false ;
}
int F_221 ( struct V_64 * V_65 , T_4 * V_63 ,
unsigned long V_76 , T_9 V_196 , int V_197 )
{
struct V_12 * V_13 = V_65 -> V_96 ;
T_10 * V_100 ;
int V_35 = 0 ;
V_100 = F_210 ( V_63 , V_65 ) ;
if ( V_100 ) {
T_4 V_101 ;
bool V_198 = V_197 && F_120 ( * V_63 ) ;
V_35 = 1 ;
if ( V_197 && F_132 ( * V_63 ) ) {
F_81 ( V_100 ) ;
return V_35 ;
}
if ( ! V_197 || ! F_173 ( * V_63 ) ) {
V_101 = F_222 ( V_13 , V_76 , V_63 ) ;
V_101 = F_193 ( V_101 , V_196 ) ;
if ( V_198 )
V_101 = F_59 ( V_101 ) ;
V_35 = V_20 ;
F_92 ( V_13 , V_76 , V_63 , V_101 ) ;
F_14 ( F_129 ( V_65 ) && ! V_198 &&
F_120 ( V_101 ) ) ;
}
F_81 ( V_100 ) ;
}
return V_35 ;
}
T_10 * F_210 ( T_4 * V_63 , struct V_64 * V_65 )
{
T_10 * V_100 ;
V_100 = F_79 ( V_65 -> V_96 , V_63 ) ;
if ( F_2 ( F_131 ( * V_63 ) || F_122 ( * V_63 ) ) )
return V_100 ;
F_81 ( V_100 ) ;
return NULL ;
}
static void F_223 ( struct V_64 * V_65 ,
unsigned long V_93 , T_4 * V_63 )
{
struct V_12 * V_13 = V_65 -> V_96 ;
T_7 V_92 ;
T_4 V_125 ;
int V_146 ;
F_151 ( V_65 , V_93 , V_63 ) ;
V_92 = F_152 ( V_13 , V_63 ) ;
F_153 ( V_13 , & V_125 , V_92 ) ;
for ( V_146 = 0 ; V_146 < V_20 ; V_146 ++ , V_93 += V_153 ) {
T_11 * V_155 , V_101 ;
V_101 = F_224 ( F_225 ( V_93 ) , V_65 -> V_103 ) ;
V_101 = F_226 ( V_101 ) ;
V_155 = F_157 ( & V_125 , V_93 ) ;
F_85 ( ! F_158 ( * V_155 ) ) ;
F_159 ( V_13 , V_93 , V_155 , V_101 ) ;
F_160 ( V_155 ) ;
}
F_161 () ;
F_153 ( V_13 , V_63 , V_92 ) ;
}
static void F_227 ( struct V_64 * V_65 , T_4 * V_63 ,
unsigned long V_93 , bool V_199 )
{
struct V_12 * V_13 = V_65 -> V_96 ;
struct V_1 * V_1 ;
T_7 V_92 ;
T_4 V_125 ;
bool V_200 , V_119 , V_201 , V_202 ;
unsigned long V_76 ;
int V_146 ;
F_85 ( V_93 & ~ V_95 ) ;
F_165 ( V_65 -> V_112 > V_93 , V_65 ) ;
F_165 ( V_65 -> V_114 < V_93 + V_113 , V_65 ) ;
F_85 ( ! F_131 ( * V_63 ) && ! F_122 ( * V_63 ) ) ;
F_6 ( V_203 ) ;
if ( ! F_129 ( V_65 ) ) {
V_125 = F_151 ( V_65 , V_93 , V_63 ) ;
if ( F_211 ( V_65 ) )
return;
V_1 = F_133 ( V_125 ) ;
if ( ! F_228 ( V_1 ) && F_204 ( V_125 ) )
F_229 ( V_1 ) ;
F_162 ( V_1 , true ) ;
F_74 ( V_1 ) ;
F_93 ( V_13 , V_186 , - V_20 ) ;
return;
} else if ( F_132 ( * V_63 ) ) {
return F_223 ( V_65 , V_93 , V_63 ) ;
}
V_1 = F_133 ( * V_63 ) ;
F_71 ( ! F_230 ( V_1 ) , V_1 ) ;
F_231 ( V_1 , V_20 - 1 ) ;
V_119 = F_120 ( * V_63 ) ;
V_200 = F_204 ( * V_63 ) ;
V_201 = F_205 ( * V_63 ) ;
V_202 = F_232 ( * V_63 ) ;
F_233 ( V_65 , V_93 , V_63 ) ;
V_92 = F_152 ( V_13 , V_63 ) ;
F_153 ( V_13 , & V_125 , V_92 ) ;
for ( V_146 = 0 , V_76 = V_93 ; V_146 < V_20 ; V_146 ++ , V_76 += V_153 ) {
T_11 V_101 , * V_155 ;
if ( V_199 ) {
T_12 V_204 ;
V_204 = F_234 ( V_1 + V_146 , V_119 ) ;
V_101 = F_235 ( V_204 ) ;
if ( V_202 )
V_101 = F_236 ( V_101 ) ;
} else {
V_101 = F_154 ( V_1 + V_146 , F_4 ( V_65 -> V_103 ) ) ;
V_101 = F_155 ( V_101 , V_65 ) ;
if ( ! V_119 )
V_101 = F_237 ( V_101 ) ;
if ( ! V_200 )
V_101 = F_238 ( V_101 ) ;
if ( V_202 )
V_101 = F_239 ( V_101 ) ;
}
if ( V_201 )
F_240 ( V_1 + V_146 ) ;
V_155 = F_157 ( & V_125 , V_76 ) ;
F_14 ( ! F_158 ( * V_155 ) ) ;
F_159 ( V_13 , V_76 , V_155 , V_101 ) ;
F_241 ( & V_1 [ V_146 ] . V_205 ) ;
F_160 ( V_155 ) ;
}
if ( F_176 ( V_1 ) > 1 && ! F_242 ( V_1 ) ) {
for ( V_146 = 0 ; V_146 < V_20 ; V_146 ++ )
F_241 ( & V_1 [ V_146 ] . V_205 ) ;
}
if ( F_243 ( - 1 , F_244 ( V_1 ) ) ) {
F_245 ( V_1 , V_206 ) ;
if ( F_246 ( V_1 ) ) {
for ( V_146 = 0 ; V_146 < V_20 ; V_146 ++ )
F_247 ( & V_1 [ V_146 ] . V_205 ) ;
}
}
F_161 () ;
F_248 ( V_65 , V_93 , V_63 ) ;
F_153 ( V_13 , V_63 , V_92 ) ;
if ( V_199 ) {
for ( V_146 = 0 ; V_146 < V_20 ; V_146 ++ ) {
F_162 ( V_1 + V_146 , false ) ;
F_74 ( V_1 + V_146 ) ;
}
}
}
void F_249 ( struct V_64 * V_65 , T_4 * V_63 ,
unsigned long V_94 , bool V_199 , struct V_1 * V_1 )
{
T_10 * V_100 ;
struct V_12 * V_13 = V_65 -> V_96 ;
unsigned long V_93 = V_94 & V_95 ;
F_150 ( V_13 , V_93 , V_93 + V_113 ) ;
V_100 = F_79 ( V_13 , V_63 ) ;
F_85 ( V_199 && ! V_1 ) ;
if ( V_1 && V_1 != F_133 ( * V_63 ) )
goto V_62;
if ( F_131 ( * V_63 ) ) {
V_1 = F_133 ( * V_63 ) ;
if ( F_250 ( V_1 ) )
F_251 ( V_1 ) ;
} else if ( ! F_122 ( * V_63 ) )
goto V_62;
F_227 ( V_65 , V_63 , V_93 , V_199 ) ;
V_62:
F_81 ( V_100 ) ;
F_163 ( V_13 , V_93 , V_93 + V_113 ) ;
}
void F_252 ( struct V_64 * V_65 , unsigned long V_94 ,
bool V_199 , struct V_1 * V_1 )
{
T_13 * V_207 ;
T_14 * V_208 ;
T_4 * V_63 ;
V_207 = F_253 ( V_65 -> V_96 , V_94 ) ;
if ( ! F_254 ( * V_207 ) )
return;
V_208 = F_255 ( V_207 , V_94 ) ;
if ( ! F_256 ( * V_208 ) )
return;
V_63 = F_257 ( V_208 , V_94 ) ;
F_249 ( V_65 , V_63 , V_94 , V_199 , V_1 ) ;
}
void F_258 ( struct V_64 * V_65 ,
unsigned long V_209 ,
unsigned long V_210 ,
long V_211 )
{
if ( V_209 & ~ V_95 &&
( V_209 & V_95 ) >= V_65 -> V_112 &&
( V_209 & V_95 ) + V_113 <= V_65 -> V_114 )
F_252 ( V_65 , V_209 , false , NULL ) ;
if ( V_210 & ~ V_95 &&
( V_210 & V_95 ) >= V_65 -> V_112 &&
( V_210 & V_95 ) + V_113 <= V_65 -> V_114 )
F_252 ( V_65 , V_210 , false , NULL ) ;
if ( V_211 > 0 ) {
struct V_64 * V_183 = V_65 -> V_212 ;
unsigned long V_213 = V_183 -> V_112 ;
V_213 += V_211 << V_59 ;
if ( V_213 & ~ V_95 &&
( V_213 & V_95 ) >= V_183 -> V_112 &&
( V_213 & V_95 ) + V_113 <= V_183 -> V_114 )
F_252 ( V_183 , V_213 , false , NULL ) ;
}
}
static void F_259 ( struct V_1 * V_1 )
{
enum V_214 V_214 = V_215 | V_216 |
V_217 ;
int V_146 , V_35 ;
F_71 ( ! F_134 ( V_1 ) , V_1 ) ;
if ( F_175 ( V_1 ) )
V_214 |= V_218 ;
V_35 = F_260 ( V_1 , V_214 | V_219 ) ;
for ( V_146 = 1 ; ! V_35 && V_146 < V_20 ; V_146 ++ ) {
if ( F_230 ( V_1 ) == 1 )
return;
V_35 = F_260 ( V_1 + V_146 , V_214 ) ;
}
F_71 ( V_35 , V_1 + V_146 - 1 ) ;
}
static void F_261 ( struct V_1 * V_1 )
{
int V_146 ;
for ( V_146 = 0 ; V_146 < V_20 ; V_146 ++ )
F_262 ( V_1 + V_146 , V_1 + V_146 , true ) ;
}
static void F_263 ( struct V_1 * V_220 , int V_221 ,
struct V_222 * V_222 , struct V_68 * V_223 )
{
struct V_1 * V_224 = V_220 + V_221 ;
F_71 ( F_21 ( & V_224 -> V_205 ) != - 1 , V_224 ) ;
F_71 ( F_264 ( V_224 ) != 0 , V_224 ) ;
if ( F_175 ( V_220 ) ) {
F_265 ( V_224 ) ;
} else {
F_231 ( V_224 , 2 ) ;
}
V_224 -> V_15 &= ~ V_225 ;
V_224 -> V_15 |= ( V_220 -> V_15 &
( ( 1L << V_226 ) |
( 1L << V_227 ) |
( 1L << V_228 ) |
( 1L << V_229 ) |
( 1L << V_230 ) |
( 1L << V_231 ) |
( 1L << V_232 ) |
( 1L << V_233 ) ) ) ;
F_161 () ;
F_266 ( V_224 ) ;
if ( F_267 ( V_220 ) )
F_268 ( V_224 ) ;
if ( F_269 ( V_220 ) )
F_270 ( V_224 ) ;
F_71 ( V_221 > 2 && V_224 -> V_69 != V_234 ,
V_224 ) ;
V_224 -> V_69 = V_220 -> V_69 ;
V_224 -> V_235 = V_220 -> V_235 + V_221 ;
F_271 ( V_224 , F_187 ( V_220 ) ) ;
F_272 ( V_220 , V_224 , V_222 , V_223 ) ;
}
static void F_273 ( struct V_1 * V_1 , struct V_68 * V_223 ,
unsigned long V_15 )
{
struct V_1 * V_220 = F_274 ( V_1 ) ;
struct V_236 * V_236 = F_275 ( V_220 ) ;
struct V_222 * V_222 ;
T_15 V_210 = - 1 ;
int V_146 ;
V_222 = F_276 ( V_220 , V_236 -> V_237 ) ;
F_277 ( V_220 ) ;
if ( ! F_175 ( V_1 ) )
V_210 = F_278 ( F_279 ( V_220 -> V_69 -> V_84 ) , V_153 ) ;
for ( V_146 = V_20 - 1 ; V_146 >= 1 ; V_146 -- ) {
F_263 ( V_220 , V_146 , V_222 , V_223 ) ;
if ( V_220 [ V_146 ] . V_235 >= V_210 ) {
F_280 ( V_220 + V_146 ) ;
F_281 ( V_220 + V_146 , NULL ) ;
if ( F_69 ( V_238 ) && F_282 ( V_220 ) )
F_283 ( V_220 -> V_69 -> V_84 , 1 ) ;
F_74 ( V_220 + V_146 ) ;
}
}
F_284 ( V_220 ) ;
if ( F_175 ( V_220 ) ) {
F_265 ( V_220 ) ;
} else {
F_231 ( V_220 , 2 ) ;
F_81 ( & V_220 -> V_69 -> V_239 ) ;
}
F_285 ( F_286 ( F_275 ( V_220 ) ) , V_15 ) ;
F_261 ( V_220 ) ;
for ( V_146 = 0 ; V_146 < V_20 ; V_146 ++ ) {
struct V_1 * V_240 = V_220 + V_146 ;
if ( V_240 == V_1 )
continue;
F_181 ( V_240 ) ;
F_74 ( V_240 ) ;
}
}
int F_287 ( struct V_1 * V_1 )
{
int V_146 , V_241 , V_35 ;
F_71 ( F_288 ( V_1 ) , V_1 ) ;
if ( F_2 ( ! F_72 ( V_1 ) ) )
return F_21 ( & V_1 -> V_205 ) + 1 ;
V_241 = F_176 ( V_1 ) ;
if ( F_289 ( V_1 ) )
return V_241 ;
V_35 = V_241 ;
for ( V_146 = 0 ; V_146 < V_20 ; V_146 ++ )
V_35 += F_21 ( & V_1 [ V_146 ] . V_205 ) + 1 ;
if ( ! F_175 ( V_1 ) )
return V_35 - V_241 * V_20 ;
if ( F_177 ( V_1 ) )
V_35 -= V_20 ;
return V_35 ;
}
int F_167 ( struct V_1 * V_1 , int * F_287 )
{
int V_146 , V_35 , V_242 , V_243 ;
F_71 ( F_289 ( V_1 ) , V_1 ) ;
if ( F_2 ( ! F_290 ( V_1 ) ) ) {
V_243 = F_21 ( & V_1 -> V_205 ) + 1 ;
if ( F_287 )
* F_287 = V_243 ;
return V_243 ;
}
V_1 = F_274 ( V_1 ) ;
V_242 = V_35 = 0 ;
for ( V_146 = 0 ; V_146 < V_20 ; V_146 ++ ) {
V_243 = F_21 ( & V_1 [ V_146 ] . V_205 ) + 1 ;
V_35 = F_291 ( V_35 , V_243 ) ;
V_242 += V_243 ;
}
if ( F_177 ( V_1 ) ) {
V_35 -= 1 ;
V_242 -= V_20 ;
}
V_243 = F_176 ( V_1 ) ;
V_35 += V_243 ;
V_242 += V_243 ;
if ( F_287 )
* F_287 = V_242 ;
return V_35 ;
}
int F_292 ( struct V_1 * V_1 , struct V_68 * V_223 )
{
struct V_1 * V_220 = F_274 ( V_1 ) ;
struct V_244 * V_245 = F_293 ( F_144 ( V_220 ) ) ;
struct V_159 * V_159 = NULL ;
struct V_246 * V_69 = NULL ;
int V_26 , V_243 , V_247 , V_35 ;
bool V_248 ;
unsigned long V_15 ;
F_71 ( F_186 ( V_1 ) , V_1 ) ;
F_71 ( ! F_192 ( V_1 ) , V_1 ) ;
F_71 ( ! F_282 ( V_1 ) , V_1 ) ;
F_71 ( ! F_72 ( V_1 ) , V_1 ) ;
if ( F_175 ( V_220 ) ) {
V_159 = F_294 ( V_220 ) ;
if ( ! V_159 ) {
V_35 = - V_249 ;
goto V_62;
}
V_247 = 0 ;
V_69 = NULL ;
F_295 ( V_159 ) ;
} else {
V_69 = V_220 -> V_69 ;
if ( ! V_69 ) {
V_35 = - V_249 ;
goto V_62;
}
V_247 = V_20 ;
V_159 = NULL ;
F_296 ( V_69 ) ;
}
if ( F_287 ( V_220 ) != F_230 ( V_220 ) - V_247 - 1 ) {
V_35 = - V_249 ;
goto V_143;
}
V_248 = F_250 ( V_1 ) ;
F_259 ( V_220 ) ;
F_71 ( F_176 ( V_220 ) , V_220 ) ;
if ( V_248 )
F_179 () ;
F_297 ( F_286 ( F_275 ( V_220 ) ) , V_15 ) ;
if ( V_69 ) {
void * * V_250 ;
F_166 ( & V_69 -> V_239 ) ;
V_250 = F_298 ( & V_69 -> V_251 ,
F_299 ( V_220 ) ) ;
if ( F_300 ( V_250 ,
& V_69 -> V_239 ) != V_220 )
goto V_252;
}
F_166 ( & V_245 -> V_253 ) ;
V_26 = F_230 ( V_220 ) ;
V_243 = F_287 ( V_220 ) ;
if ( ! V_243 && F_301 ( V_220 , 1 + V_247 ) ) {
if ( ! F_302 ( F_60 ( V_220 ) ) ) {
V_245 -> V_254 -- ;
F_303 ( F_60 ( V_220 ) ) ;
}
if ( V_69 )
F_245 ( V_1 , V_255 ) ;
F_81 ( & V_245 -> V_253 ) ;
F_273 ( V_1 , V_223 , V_15 ) ;
V_35 = 0 ;
} else {
if ( F_69 ( V_256 ) && V_243 ) {
F_304 ( L_17 ,
V_243 , V_26 ) ;
if ( F_288 ( V_1 ) )
F_305 ( V_220 , NULL ) ;
F_305 ( V_1 , L_18 ) ;
F_306 () ;
}
F_81 ( & V_245 -> V_253 ) ;
V_252: if ( V_69 )
F_81 ( & V_69 -> V_239 ) ;
F_285 ( F_286 ( F_275 ( V_220 ) ) , V_15 ) ;
F_261 ( V_220 ) ;
V_35 = - V_249 ;
}
V_143:
if ( V_159 ) {
F_307 ( V_159 ) ;
F_308 ( V_159 ) ;
}
if ( V_69 )
F_309 ( V_69 ) ;
V_62:
F_6 ( ! V_35 ? V_257 : V_258 ) ;
return V_35 ;
}
void F_310 ( struct V_1 * V_1 )
{
struct V_244 * V_245 = F_293 ( F_144 ( V_1 ) ) ;
unsigned long V_15 ;
F_297 ( & V_245 -> V_253 , V_15 ) ;
if ( ! F_302 ( F_60 ( V_1 ) ) ) {
V_245 -> V_254 -- ;
F_303 ( F_60 ( V_1 ) ) ;
}
F_285 ( & V_245 -> V_253 , V_15 ) ;
F_311 ( V_1 ) ;
}
void F_312 ( struct V_1 * V_1 )
{
struct V_244 * V_245 = F_293 ( F_144 ( V_1 ) ) ;
unsigned long V_15 ;
F_71 ( ! F_313 ( V_1 ) , V_1 ) ;
F_297 ( & V_245 -> V_253 , V_15 ) ;
if ( F_302 ( F_60 ( V_1 ) ) ) {
F_6 ( V_259 ) ;
F_314 ( F_60 ( V_1 ) , & V_245 -> V_260 ) ;
V_245 -> V_254 ++ ;
}
F_285 ( & V_245 -> V_253 , V_15 ) ;
}
static unsigned long F_315 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_244 * V_245 = F_293 ( V_19 -> V_261 ) ;
return F_316 ( V_245 -> V_254 ) ;
}
static unsigned long F_317 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_244 * V_245 = F_293 ( V_19 -> V_261 ) ;
unsigned long V_15 ;
F_318 ( V_223 ) , * V_262 , * V_183 ;
struct V_1 * V_1 ;
int V_263 = 0 ;
F_297 ( & V_245 -> V_253 , V_15 ) ;
F_319 (pos, next, &pgdata->split_queue) {
V_1 = F_320 ( ( void * ) V_262 , struct V_1 , V_69 ) ;
V_1 = F_274 ( V_1 ) ;
if ( F_321 ( V_1 ) ) {
F_322 ( F_60 ( V_1 ) , & V_223 ) ;
} else {
F_323 ( F_60 ( V_1 ) ) ;
V_245 -> V_254 -- ;
}
if ( ! -- V_19 -> V_264 )
break;
}
F_285 ( & V_245 -> V_253 , V_15 ) ;
F_319 (pos, next, &list) {
V_1 = F_320 ( ( void * ) V_262 , struct V_1 , V_69 ) ;
F_324 ( V_1 ) ;
if ( ! F_199 ( V_1 ) )
V_263 ++ ;
F_181 ( V_1 ) ;
F_74 ( V_1 ) ;
}
F_297 ( & V_245 -> V_253 , V_15 ) ;
F_325 ( & V_223 , & V_245 -> V_260 ) ;
F_285 ( & V_245 -> V_253 , V_15 ) ;
if ( ! V_263 && F_302 ( & V_245 -> V_260 ) )
return V_265 ;
return V_263 ;
}
static int F_326 ( void * V_266 , T_16 V_267 )
{
struct V_236 * V_236 ;
struct V_1 * V_1 ;
unsigned long V_117 , V_268 ;
unsigned long V_269 = 0 , V_263 = 0 ;
if ( V_267 != 1 )
return - V_31 ;
F_327 (zone) {
V_268 = F_328 ( V_236 ) ;
for ( V_117 = V_236 -> V_270 ; V_117 < V_268 ; V_117 ++ ) {
if ( ! F_329 ( V_117 ) )
continue;
V_1 = F_125 ( V_117 ) ;
if ( ! F_321 ( V_1 ) )
continue;
if ( V_236 != F_275 ( V_1 ) )
goto V_183;
if ( ! F_134 ( V_1 ) || F_289 ( V_1 ) || ! F_330 ( V_1 ) )
goto V_183;
V_269 ++ ;
F_324 ( V_1 ) ;
if ( ! F_199 ( V_1 ) )
V_263 ++ ;
F_181 ( V_1 ) ;
V_183:
F_74 ( V_1 ) ;
}
}
F_331 ( L_19 , V_263 , V_269 ) ;
return 0 ;
}
static int T_3 F_332 ( void )
{
void * V_35 ;
V_35 = F_333 ( L_20 , 0200 , NULL , NULL ,
& V_271 ) ;
if ( ! V_35 )
F_57 ( L_21 ) ;
return 0 ;
}
