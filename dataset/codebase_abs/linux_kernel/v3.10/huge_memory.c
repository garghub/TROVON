static int F_1 ( void )
{
struct V_1 * V_1 ;
int V_2 = 0 ;
unsigned long V_3 ;
if ( ! F_2 () )
return 0 ;
F_3 (zone)
V_2 ++ ;
V_3 = V_4 * V_2 * 2 ;
V_3 += V_4 * V_2 *
V_5 * V_5 ;
V_3 = F_4 ( V_3 ,
( unsigned long ) F_5 () / 20 ) ;
V_3 <<= ( V_6 - 10 ) ;
if ( V_3 > V_7 )
V_7 = V_3 ;
F_6 () ;
return 0 ;
}
static int F_7 ( void )
{
int V_8 = 0 ;
if ( F_2 () ) {
if ( ! V_9 )
V_9 = F_8 ( V_10 , NULL ,
L_1 ) ;
if ( F_9 ( F_10 ( V_9 ) ) ) {
F_11 ( V_11
L_2 ) ;
V_8 = F_12 ( V_9 ) ;
V_9 = NULL ;
}
if ( ! F_13 ( & V_12 . V_13 ) )
F_14 ( & V_14 ) ;
F_1 () ;
} else if ( V_9 ) {
F_15 ( V_9 ) ;
V_9 = NULL ;
}
return V_8 ;
}
static inline bool F_16 ( struct V_15 * V_15 )
{
return F_17 ( V_16 ) == V_15 ;
}
static inline bool F_18 ( T_1 V_17 )
{
return F_16 ( F_19 ( V_17 ) ) ;
}
static struct V_15 * F_20 ( void )
{
struct V_15 * V_18 ;
V_19:
if ( F_21 ( F_22 ( & V_20 ) ) )
return F_17 ( V_16 ) ;
V_18 = F_23 ( ( V_21 | V_22 ) & ~ V_23 ,
V_24 ) ;
if ( ! V_18 ) {
F_24 ( V_25 ) ;
return NULL ;
}
F_24 ( V_26 ) ;
F_25 () ;
if ( F_26 ( & V_16 , NULL , V_18 ) ) {
F_27 () ;
F_28 ( V_18 ) ;
goto V_19;
}
F_29 ( & V_20 , 2 ) ;
F_27 () ;
return F_17 ( V_16 ) ;
}
static void F_30 ( void )
{
F_31 ( F_32 ( & V_20 ) ) ;
}
static int F_33 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
if ( ! V_30 -> V_31 )
return F_34 ( & V_20 ) == 1 ? V_32 : 0 ;
if ( F_35 ( & V_20 , 1 , 0 ) == 1 ) {
struct V_15 * V_18 = F_36 ( & V_16 , NULL ) ;
F_31 ( V_18 == NULL ) ;
F_28 ( V_18 ) ;
}
return 0 ;
}
static T_2 F_37 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 ,
enum V_38 V_39 ,
enum V_38 V_40 )
{
if ( F_38 ( V_39 , & V_41 ) ) {
F_39 ( F_38 ( V_40 , & V_41 ) ) ;
return sprintf ( V_37 , L_3 ) ;
} else if ( F_38 ( V_40 , & V_41 ) )
return sprintf ( V_37 , L_4 ) ;
else
return sprintf ( V_37 , L_5 ) ;
}
static T_2 F_40 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 , T_3 V_42 ,
enum V_38 V_39 ,
enum V_38 V_40 )
{
if ( ! memcmp ( L_6 , V_37 ,
F_4 ( sizeof( L_6 ) - 1 , V_42 ) ) ) {
F_41 ( V_39 , & V_41 ) ;
F_42 ( V_40 , & V_41 ) ;
} else if ( ! memcmp ( L_7 , V_37 ,
F_4 ( sizeof( L_7 ) - 1 , V_42 ) ) ) {
F_42 ( V_39 , & V_41 ) ;
F_41 ( V_40 , & V_41 ) ;
} else if ( ! memcmp ( L_8 , V_37 ,
F_4 ( sizeof( L_8 ) - 1 , V_42 ) ) ) {
F_42 ( V_39 , & V_41 ) ;
F_42 ( V_40 , & V_41 ) ;
} else
return - V_43 ;
return V_42 ;
}
static T_2 F_43 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 )
{
return F_37 ( V_34 , V_36 , V_37 ,
V_44 ,
V_45 ) ;
}
static T_2 F_44 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 , T_3 V_42 )
{
T_2 V_46 ;
V_46 = F_40 ( V_34 , V_36 , V_37 , V_42 ,
V_44 ,
V_45 ) ;
if ( V_46 > 0 ) {
int V_8 ;
F_45 ( & V_47 ) ;
V_8 = F_7 () ;
F_46 ( & V_47 ) ;
if ( V_8 )
V_46 = V_8 ;
}
return V_46 ;
}
static T_2 F_47 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 ,
enum V_38 V_48 )
{
return sprintf ( V_37 , L_9 ,
! ! F_38 ( V_48 , & V_41 ) ) ;
}
static T_2 F_48 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 , T_3 V_42 ,
enum V_38 V_48 )
{
unsigned long V_49 ;
int V_46 ;
V_46 = F_49 ( V_37 , 10 , & V_49 ) ;
if ( V_46 < 0 )
return V_46 ;
if ( V_49 > 1 )
return - V_43 ;
if ( V_49 )
F_41 ( V_48 , & V_41 ) ;
else
F_42 ( V_48 , & V_41 ) ;
return V_42 ;
}
static T_2 F_50 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 )
{
return F_37 ( V_34 , V_36 , V_37 ,
V_50 ,
V_51 ) ;
}
static T_2 F_51 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 , T_3 V_42 )
{
return F_40 ( V_34 , V_36 , V_37 , V_42 ,
V_50 ,
V_51 ) ;
}
static T_2 F_52 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 )
{
return F_47 ( V_34 , V_36 , V_37 ,
V_52 ) ;
}
static T_2 F_53 ( struct V_33 * V_34 ,
struct V_35 * V_36 , const char * V_37 , T_3 V_42 )
{
return F_48 ( V_34 , V_36 , V_37 , V_42 ,
V_52 ) ;
}
static T_2 F_54 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 )
{
return F_47 ( V_34 , V_36 , V_37 ,
V_53 ) ;
}
static T_2 F_55 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 , T_3 V_42 )
{
return F_48 ( V_34 , V_36 , V_37 , V_42 ,
V_53 ) ;
}
static T_2 F_56 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
return sprintf ( V_37 , L_10 , V_54 ) ;
}
static T_2 F_57 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 , T_3 V_42 )
{
unsigned long V_55 ;
int V_8 ;
V_8 = F_58 ( V_37 , 10 , & V_55 ) ;
if ( V_8 || V_55 > V_56 )
return - V_43 ;
V_54 = V_55 ;
F_14 ( & V_14 ) ;
return V_42 ;
}
static T_2 F_59 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
return sprintf ( V_37 , L_10 , V_57 ) ;
}
static T_2 F_60 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 , T_3 V_42 )
{
unsigned long V_55 ;
int V_8 ;
V_8 = F_58 ( V_37 , 10 , & V_55 ) ;
if ( V_8 || V_55 > V_56 )
return - V_43 ;
V_57 = V_55 ;
F_14 ( & V_14 ) ;
return V_42 ;
}
static T_2 F_61 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
return sprintf ( V_37 , L_10 , V_58 ) ;
}
static T_2 F_62 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 , T_3 V_42 )
{
int V_8 ;
unsigned long V_59 ;
V_8 = F_58 ( V_37 , 10 , & V_59 ) ;
if ( V_8 || ! V_59 || V_59 > V_56 )
return - V_43 ;
V_58 = V_59 ;
return V_42 ;
}
static T_2 F_63 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
return sprintf ( V_37 , L_10 , V_60 ) ;
}
static T_2 F_64 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
return sprintf ( V_37 , L_10 , V_61 ) ;
}
static T_2 F_65 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 )
{
return F_47 ( V_34 , V_36 , V_37 ,
V_62 ) ;
}
static T_2 F_66 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 , T_3 V_42 )
{
return F_48 ( V_34 , V_36 , V_37 , V_42 ,
V_62 ) ;
}
static T_2 F_67 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_37 )
{
return sprintf ( V_37 , L_10 , V_63 ) ;
}
static T_2 F_68 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 , T_3 V_42 )
{
int V_8 ;
unsigned long V_64 ;
V_8 = F_58 ( V_37 , 10 , & V_64 ) ;
if ( V_8 || V_64 > V_32 - 1 )
return - V_43 ;
V_63 = V_64 ;
return V_42 ;
}
static int T_4 F_69 ( struct V_33 * * V_65 )
{
int V_8 ;
* V_65 = F_70 ( L_11 , V_66 ) ;
if ( F_9 ( ! * V_65 ) ) {
F_11 ( V_11 L_12 ) ;
return - V_67 ;
}
V_8 = F_71 ( * V_65 , & V_68 ) ;
if ( V_8 ) {
F_11 ( V_11 L_13 ) ;
goto V_69;
}
V_8 = F_71 ( * V_65 , & V_70 ) ;
if ( V_8 ) {
F_11 ( V_11 L_13 ) ;
goto V_71;
}
return 0 ;
V_71:
F_72 ( * V_65 , & V_68 ) ;
V_69:
F_73 ( * V_65 ) ;
return V_8 ;
}
static void T_4 F_74 ( struct V_33 * V_65 )
{
F_72 ( V_65 , & V_70 ) ;
F_72 ( V_65 , & V_68 ) ;
F_73 ( V_65 ) ;
}
static inline int F_69 ( struct V_33 * * V_65 )
{
return 0 ;
}
static inline void F_74 ( struct V_33 * V_65 )
{
}
static int T_4 F_75 ( void )
{
int V_8 ;
struct V_33 * V_65 ;
if ( ! F_76 () ) {
V_41 = 0 ;
return - V_43 ;
}
V_8 = F_69 ( & V_65 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_77 () ;
if ( V_8 )
goto V_72;
F_78 ( & V_73 ) ;
if ( V_74 < ( 512 << ( 20 - V_6 ) ) )
V_41 = 0 ;
F_7 () ;
return 0 ;
V_72:
F_74 ( V_65 ) ;
return V_8 ;
}
static int T_4 F_79 ( char * V_75 )
{
int V_46 = 0 ;
if ( ! V_75 )
goto V_72;
if ( ! strcmp ( V_75 , L_6 ) ) {
F_41 ( V_44 ,
& V_41 ) ;
F_42 ( V_45 ,
& V_41 ) ;
V_46 = 1 ;
} else if ( ! strcmp ( V_75 , L_7 ) ) {
F_42 ( V_44 ,
& V_41 ) ;
F_41 ( V_45 ,
& V_41 ) ;
V_46 = 1 ;
} else if ( ! strcmp ( V_75 , L_8 ) ) {
F_42 ( V_44 ,
& V_41 ) ;
F_42 ( V_45 ,
& V_41 ) ;
V_46 = 1 ;
}
V_72:
if ( ! V_46 )
F_11 ( V_76
L_14 ) ;
return V_46 ;
}
T_1 F_80 ( T_1 V_17 , struct V_77 * V_78 )
{
if ( F_21 ( V_78 -> V_79 & V_80 ) )
V_17 = F_81 ( V_17 ) ;
return V_17 ;
}
static inline T_1 F_82 ( struct V_15 * V_15 , struct V_77 * V_78 )
{
T_1 V_81 ;
V_81 = F_83 ( V_15 , V_78 -> V_82 ) ;
V_81 = F_80 ( F_84 ( V_81 ) , V_78 ) ;
V_81 = F_85 ( V_81 ) ;
return V_81 ;
}
static int F_86 ( struct V_83 * V_84 ,
struct V_77 * V_78 ,
unsigned long V_85 , T_1 * V_17 ,
struct V_15 * V_15 )
{
T_5 V_86 ;
F_39 ( ! F_87 ( V_15 ) ) ;
V_86 = F_88 ( V_84 , V_85 ) ;
if ( F_9 ( ! V_86 ) )
return V_87 ;
F_89 ( V_15 , V_85 , V_32 ) ;
F_90 ( V_15 ) ;
F_91 ( & V_84 -> V_88 ) ;
if ( F_9 ( ! F_92 ( * V_17 ) ) ) {
F_93 ( & V_84 -> V_88 ) ;
F_94 ( V_15 ) ;
F_95 ( V_15 ) ;
F_96 ( V_84 , V_86 ) ;
} else {
T_1 V_81 ;
V_81 = F_82 ( V_15 , V_78 ) ;
F_97 ( V_15 , V_78 , V_85 ) ;
F_98 ( V_84 , V_85 , V_17 , V_81 ) ;
F_99 ( V_84 , V_86 ) ;
F_100 ( V_84 , V_89 , V_32 ) ;
V_84 -> V_90 ++ ;
F_93 ( & V_84 -> V_88 ) ;
}
return 0 ;
}
static inline T_6 F_101 ( int V_91 , T_6 V_92 )
{
return ( V_21 & ~ ( V_91 ? 0 : V_93 ) ) | V_92 ;
}
static inline struct V_15 * F_102 ( int V_91 ,
struct V_77 * V_78 ,
unsigned long V_85 , int V_94 ,
T_6 V_92 )
{
return F_103 ( F_101 ( V_91 , V_92 ) ,
V_24 , V_78 , V_85 , V_94 ) ;
}
static inline struct V_15 * F_104 ( int V_91 )
{
return F_23 ( F_101 ( V_91 , 0 ) ,
V_24 ) ;
}
static bool F_105 ( T_5 V_86 , struct V_83 * V_84 ,
struct V_77 * V_78 , unsigned long V_85 , T_1 * V_17 ,
struct V_15 * V_18 )
{
T_1 V_81 ;
if ( ! F_92 ( * V_17 ) )
return false ;
V_81 = F_83 ( V_18 , V_78 -> V_82 ) ;
V_81 = F_106 ( V_81 ) ;
V_81 = F_85 ( V_81 ) ;
F_98 ( V_84 , V_85 , V_17 , V_81 ) ;
F_99 ( V_84 , V_86 ) ;
V_84 -> V_90 ++ ;
return true ;
}
int F_107 ( struct V_83 * V_84 , struct V_77 * V_78 ,
unsigned long V_95 , T_1 * V_17 ,
unsigned int V_96 )
{
struct V_15 * V_15 ;
unsigned long V_85 = V_95 & V_97 ;
T_7 * V_98 ;
if ( V_85 >= V_78 -> V_99 && V_85 + V_100 <= V_78 -> V_101 ) {
if ( F_9 ( F_108 ( V_78 ) ) )
return V_87 ;
if ( F_9 ( F_109 ( V_78 ) ) )
return V_87 ;
if ( ! ( V_96 & V_102 ) &&
F_110 () ) {
T_5 V_86 ;
struct V_15 * V_18 ;
bool V_103 ;
V_86 = F_88 ( V_84 , V_85 ) ;
if ( F_9 ( ! V_86 ) )
return V_87 ;
V_18 = F_20 () ;
if ( F_9 ( ! V_18 ) ) {
F_96 ( V_84 , V_86 ) ;
F_24 ( V_104 ) ;
goto V_72;
}
F_91 ( & V_84 -> V_88 ) ;
V_103 = F_105 ( V_86 , V_84 , V_78 , V_85 , V_17 ,
V_18 ) ;
F_93 ( & V_84 -> V_88 ) ;
if ( ! V_103 ) {
F_96 ( V_84 , V_86 ) ;
F_30 () ;
}
return 0 ;
}
V_15 = F_102 ( F_111 ( V_78 ) ,
V_78 , V_85 , F_112 () , 0 ) ;
if ( F_9 ( ! V_15 ) ) {
F_24 ( V_104 ) ;
goto V_72;
}
F_24 ( V_105 ) ;
if ( F_9 ( F_113 ( V_15 , V_84 , V_106 ) ) ) {
F_95 ( V_15 ) ;
goto V_72;
}
if ( F_9 ( F_86 ( V_84 , V_78 , V_85 , V_17 ,
V_15 ) ) ) {
F_94 ( V_15 ) ;
F_95 ( V_15 ) ;
goto V_72;
}
return 0 ;
}
V_72:
if ( F_9 ( F_92 ( * V_17 ) ) &&
F_9 ( F_114 ( V_84 , V_78 , V_17 , V_95 ) ) )
return V_87 ;
if ( F_9 ( F_115 ( * V_17 ) ) )
return 0 ;
V_98 = F_116 ( V_17 , V_95 ) ;
return F_117 ( V_84 , V_78 , V_95 , V_98 , V_17 , V_96 ) ;
}
int F_118 ( struct V_83 * V_107 , struct V_83 * V_108 ,
T_1 * V_109 , T_1 * V_110 , unsigned long V_111 ,
struct V_77 * V_78 )
{
struct V_15 * V_112 ;
T_1 V_17 ;
T_5 V_86 ;
int V_46 ;
V_46 = - V_67 ;
V_86 = F_88 ( V_107 , V_111 ) ;
if ( F_9 ( ! V_86 ) )
goto V_72;
F_91 ( & V_107 -> V_88 ) ;
F_119 ( & V_108 -> V_88 , V_113 ) ;
V_46 = - V_114 ;
V_17 = * V_110 ;
if ( F_9 ( ! F_115 ( V_17 ) ) ) {
F_96 ( V_107 , V_86 ) ;
goto V_115;
}
if ( F_18 ( V_17 ) ) {
struct V_15 * V_18 ;
bool V_103 ;
V_18 = F_20 () ;
V_103 = F_105 ( V_86 , V_107 , V_78 , V_111 , V_109 ,
V_18 ) ;
F_31 ( ! V_103 ) ;
V_46 = 0 ;
goto V_115;
}
if ( F_9 ( F_120 ( V_17 ) ) ) {
F_93 ( & V_108 -> V_88 ) ;
F_93 ( & V_107 -> V_88 ) ;
F_96 ( V_107 , V_86 ) ;
F_121 ( V_78 -> V_116 , V_110 ) ;
goto V_72;
}
V_112 = F_19 ( V_17 ) ;
F_39 ( ! F_122 ( V_112 ) ) ;
F_123 ( V_112 ) ;
F_124 ( V_112 ) ;
F_100 ( V_107 , V_89 , V_32 ) ;
F_125 ( V_108 , V_111 , V_110 ) ;
V_17 = F_126 ( F_106 ( V_17 ) ) ;
F_98 ( V_107 , V_111 , V_109 , V_17 ) ;
F_99 ( V_107 , V_86 ) ;
V_107 -> V_90 ++ ;
V_46 = 0 ;
V_115:
F_93 ( & V_108 -> V_88 ) ;
F_93 ( & V_107 -> V_88 ) ;
V_72:
return V_46 ;
}
void F_127 ( struct V_83 * V_84 ,
struct V_77 * V_78 ,
unsigned long V_95 ,
T_1 * V_17 , T_1 V_117 ,
int V_118 )
{
T_1 V_81 ;
unsigned long V_85 ;
F_91 ( & V_84 -> V_88 ) ;
if ( F_9 ( ! F_128 ( * V_17 , V_117 ) ) )
goto V_119;
V_81 = F_129 ( V_117 ) ;
V_85 = V_95 & V_97 ;
if ( F_130 ( V_78 , V_85 , V_17 , V_81 , V_118 ) )
F_131 ( V_78 , V_95 , V_17 ) ;
V_119:
F_93 ( & V_84 -> V_88 ) ;
}
static int F_132 ( struct V_83 * V_84 ,
struct V_77 * V_78 , unsigned long V_95 ,
T_1 * V_17 , T_1 V_117 , unsigned long V_85 )
{
T_5 V_86 ;
T_1 V_120 ;
struct V_15 * V_15 ;
int V_121 , V_46 = 0 ;
unsigned long V_122 ;
unsigned long V_123 ;
V_15 = F_133 ( V_124 , V_78 , V_95 ) ;
if ( ! V_15 ) {
V_46 |= V_87 ;
goto V_72;
}
if ( F_113 ( V_15 , V_84 , V_106 ) ) {
F_95 ( V_15 ) ;
V_46 |= V_87 ;
goto V_72;
}
F_134 ( V_15 , V_95 ) ;
F_90 ( V_15 ) ;
V_122 = V_85 ;
V_123 = V_85 + V_100 ;
F_135 ( V_84 , V_122 , V_123 ) ;
F_91 ( & V_84 -> V_88 ) ;
if ( F_9 ( ! F_128 ( * V_17 , V_117 ) ) )
goto V_125;
F_136 ( V_78 , V_85 , V_17 ) ;
V_86 = F_137 ( V_84 ) ;
F_138 ( V_84 , & V_120 , V_86 ) ;
for ( V_121 = 0 ; V_121 < V_32 ; V_121 ++ , V_85 += V_126 ) {
T_7 * V_98 , V_81 ;
if ( V_85 == ( V_95 & V_127 ) ) {
V_81 = F_139 ( V_15 , V_78 -> V_82 ) ;
V_81 = F_140 ( F_141 ( V_81 ) , V_78 ) ;
F_97 ( V_15 , V_78 , V_85 ) ;
} else {
V_81 = F_142 ( F_143 ( V_85 ) , V_78 -> V_82 ) ;
V_81 = F_144 ( V_81 ) ;
}
V_98 = F_116 ( & V_120 , V_85 ) ;
F_39 ( ! F_145 ( * V_98 ) ) ;
F_146 ( V_84 , V_85 , V_98 , V_81 ) ;
F_147 ( V_98 ) ;
}
F_148 () ;
F_138 ( V_84 , V_17 , V_86 ) ;
F_93 ( & V_84 -> V_88 ) ;
F_30 () ;
F_149 ( V_84 , V_89 ) ;
F_150 ( V_84 , V_122 , V_123 ) ;
V_46 |= V_128 ;
V_72:
return V_46 ;
V_125:
F_93 ( & V_84 -> V_88 ) ;
F_150 ( V_84 , V_122 , V_123 ) ;
F_94 ( V_15 ) ;
F_95 ( V_15 ) ;
goto V_72;
}
static int F_151 ( struct V_83 * V_84 ,
struct V_77 * V_78 ,
unsigned long V_95 ,
T_1 * V_17 , T_1 V_117 ,
struct V_15 * V_15 ,
unsigned long V_85 )
{
T_5 V_86 ;
T_1 V_120 ;
int V_46 = 0 , V_121 ;
struct V_15 * * V_59 ;
unsigned long V_122 ;
unsigned long V_123 ;
V_59 = F_152 ( sizeof( struct V_15 * ) * V_32 ,
V_106 ) ;
if ( F_9 ( ! V_59 ) ) {
V_46 |= V_87 ;
goto V_72;
}
for ( V_121 = 0 ; V_121 < V_32 ; V_121 ++ ) {
V_59 [ V_121 ] = F_153 ( V_124 |
V_129 ,
V_78 , V_95 , F_154 ( V_15 ) ) ;
if ( F_9 ( ! V_59 [ V_121 ] ||
F_113 ( V_59 [ V_121 ] , V_84 ,
V_106 ) ) ) {
if ( V_59 [ V_121 ] )
F_95 ( V_59 [ V_121 ] ) ;
F_155 () ;
while ( -- V_121 >= 0 ) {
F_94 ( V_59 [ V_121 ] ) ;
F_95 ( V_59 [ V_121 ] ) ;
}
F_156 () ;
F_157 ( V_59 ) ;
V_46 |= V_87 ;
goto V_72;
}
}
for ( V_121 = 0 ; V_121 < V_32 ; V_121 ++ ) {
F_158 ( V_59 [ V_121 ] , V_15 + V_121 ,
V_85 + V_126 * V_121 , V_78 ) ;
F_90 ( V_59 [ V_121 ] ) ;
F_159 () ;
}
V_122 = V_85 ;
V_123 = V_85 + V_100 ;
F_135 ( V_84 , V_122 , V_123 ) ;
F_91 ( & V_84 -> V_88 ) ;
if ( F_9 ( ! F_128 ( * V_17 , V_117 ) ) )
goto V_130;
F_39 ( ! F_122 ( V_15 ) ) ;
F_136 ( V_78 , V_85 , V_17 ) ;
V_86 = F_137 ( V_84 ) ;
F_138 ( V_84 , & V_120 , V_86 ) ;
for ( V_121 = 0 ; V_121 < V_32 ; V_121 ++ , V_85 += V_126 ) {
T_7 * V_98 , V_81 ;
V_81 = F_139 ( V_59 [ V_121 ] , V_78 -> V_82 ) ;
V_81 = F_140 ( F_141 ( V_81 ) , V_78 ) ;
F_97 ( V_59 [ V_121 ] , V_78 , V_85 ) ;
V_98 = F_116 ( & V_120 , V_85 ) ;
F_39 ( ! F_145 ( * V_98 ) ) ;
F_146 ( V_84 , V_85 , V_98 , V_81 ) ;
F_147 ( V_98 ) ;
}
F_157 ( V_59 ) ;
F_148 () ;
F_138 ( V_84 , V_17 , V_86 ) ;
F_160 ( V_15 ) ;
F_93 ( & V_84 -> V_88 ) ;
F_150 ( V_84 , V_122 , V_123 ) ;
V_46 |= V_128 ;
F_95 ( V_15 ) ;
V_72:
return V_46 ;
V_130:
F_93 ( & V_84 -> V_88 ) ;
F_150 ( V_84 , V_122 , V_123 ) ;
F_155 () ;
for ( V_121 = 0 ; V_121 < V_32 ; V_121 ++ ) {
F_94 ( V_59 [ V_121 ] ) ;
F_95 ( V_59 [ V_121 ] ) ;
}
F_156 () ;
F_157 ( V_59 ) ;
goto V_72;
}
int F_161 ( struct V_83 * V_84 , struct V_77 * V_78 ,
unsigned long V_95 , T_1 * V_17 , T_1 V_117 )
{
int V_46 = 0 ;
struct V_15 * V_15 = NULL , * V_131 ;
unsigned long V_85 ;
unsigned long V_122 ;
unsigned long V_123 ;
F_39 ( ! V_78 -> V_116 ) ;
V_85 = V_95 & V_97 ;
if ( F_18 ( V_117 ) )
goto V_132;
F_91 ( & V_84 -> V_88 ) ;
if ( F_9 ( ! F_128 ( * V_17 , V_117 ) ) )
goto V_115;
V_15 = F_19 ( V_117 ) ;
F_39 ( ! F_87 ( V_15 ) || ! F_122 ( V_15 ) ) ;
if ( F_162 ( V_15 ) == 1 ) {
T_1 V_81 ;
V_81 = F_129 ( V_117 ) ;
V_81 = F_80 ( F_84 ( V_81 ) , V_78 ) ;
if ( F_130 ( V_78 , V_85 , V_17 , V_81 , 1 ) )
F_131 ( V_78 , V_95 , V_17 ) ;
V_46 |= V_128 ;
goto V_115;
}
F_123 ( V_15 ) ;
F_93 ( & V_84 -> V_88 ) ;
V_132:
if ( F_163 ( V_78 ) &&
! F_164 () )
V_131 = F_102 ( F_111 ( V_78 ) ,
V_78 , V_85 , F_112 () , 0 ) ;
else
V_131 = NULL ;
if ( F_9 ( ! V_131 ) ) {
F_24 ( V_104 ) ;
if ( F_18 ( V_117 ) ) {
V_46 = F_132 ( V_84 , V_78 ,
V_95 , V_17 , V_117 , V_85 ) ;
} else {
V_46 = F_151 ( V_84 , V_78 , V_95 ,
V_17 , V_117 , V_15 , V_85 ) ;
if ( V_46 & V_87 )
F_165 ( V_15 ) ;
F_95 ( V_15 ) ;
}
goto V_72;
}
F_24 ( V_105 ) ;
if ( F_9 ( F_113 ( V_131 , V_84 , V_106 ) ) ) {
F_95 ( V_131 ) ;
if ( V_15 ) {
F_165 ( V_15 ) ;
F_95 ( V_15 ) ;
}
V_46 |= V_87 ;
goto V_72;
}
if ( F_18 ( V_117 ) )
F_89 ( V_131 , V_85 , V_32 ) ;
else
F_166 ( V_131 , V_15 , V_85 , V_78 , V_32 ) ;
F_90 ( V_131 ) ;
V_122 = V_85 ;
V_123 = V_85 + V_100 ;
F_135 ( V_84 , V_122 , V_123 ) ;
F_91 ( & V_84 -> V_88 ) ;
if ( V_15 )
F_95 ( V_15 ) ;
if ( F_9 ( ! F_128 ( * V_17 , V_117 ) ) ) {
F_93 ( & V_84 -> V_88 ) ;
F_94 ( V_131 ) ;
F_95 ( V_131 ) ;
goto V_133;
} else {
T_1 V_81 ;
V_81 = F_82 ( V_131 , V_78 ) ;
F_136 ( V_78 , V_85 , V_17 ) ;
F_97 ( V_131 , V_78 , V_85 ) ;
F_98 ( V_84 , V_85 , V_17 , V_81 ) ;
F_131 ( V_78 , V_95 , V_17 ) ;
if ( F_18 ( V_117 ) ) {
F_100 ( V_84 , V_89 , V_32 ) ;
F_30 () ;
} else {
F_39 ( ! F_122 ( V_15 ) ) ;
F_160 ( V_15 ) ;
F_95 ( V_15 ) ;
}
V_46 |= V_128 ;
}
F_93 ( & V_84 -> V_88 ) ;
V_133:
F_150 ( V_84 , V_122 , V_123 ) ;
V_72:
return V_46 ;
V_115:
F_93 ( & V_84 -> V_88 ) ;
return V_46 ;
}
struct V_15 * F_167 ( struct V_77 * V_78 ,
unsigned long V_111 ,
T_1 * V_17 ,
unsigned int V_96 )
{
struct V_83 * V_84 = V_78 -> V_134 ;
struct V_15 * V_15 = NULL ;
F_168 ( & V_84 -> V_88 ) ;
if ( V_96 & V_135 && ! F_169 ( * V_17 ) )
goto V_72;
if ( ( V_96 & V_136 ) && F_18 ( * V_17 ) )
return F_170 ( - V_137 ) ;
V_15 = F_19 ( * V_17 ) ;
F_39 ( ! F_122 ( V_15 ) ) ;
if ( V_96 & V_138 ) {
T_1 V_120 ;
V_120 = F_129 ( F_84 ( * V_17 ) ) ;
F_98 ( V_84 , V_111 & V_97 , V_17 , V_120 ) ;
}
if ( ( V_96 & V_139 ) && ( V_78 -> V_79 & V_140 ) ) {
if ( V_15 -> V_141 && F_171 ( V_15 ) ) {
F_172 () ;
if ( V_15 -> V_141 )
F_173 ( V_15 ) ;
F_174 ( V_15 ) ;
}
}
V_15 += ( V_111 & ~ V_97 ) >> V_6 ;
F_39 ( ! F_87 ( V_15 ) ) ;
if ( V_96 & V_142 )
F_175 ( V_15 ) ;
V_72:
return V_15 ;
}
int F_176 ( struct V_83 * V_84 , struct V_77 * V_78 ,
unsigned long V_111 , T_1 V_17 , T_1 * V_143 )
{
struct V_15 * V_15 ;
unsigned long V_85 = V_111 & V_97 ;
int V_144 ;
int V_145 = - 1 ;
bool V_146 ;
F_91 ( & V_84 -> V_88 ) ;
if ( F_9 ( ! F_128 ( V_17 , * V_143 ) ) )
goto V_115;
V_15 = F_19 ( V_17 ) ;
F_123 ( V_15 ) ;
V_145 = F_154 ( V_15 ) ;
F_177 ( V_147 ) ;
if ( V_145 == F_112 () )
F_177 ( V_148 ) ;
V_144 = F_178 ( V_15 , V_78 , V_85 ) ;
if ( V_144 == - 1 ) {
F_95 ( V_15 ) ;
goto V_149;
}
F_93 ( & V_84 -> V_88 ) ;
F_179 ( V_15 ) ;
F_91 ( & V_84 -> V_88 ) ;
if ( F_9 ( ! F_128 ( V_17 , * V_143 ) ) ) {
F_174 ( V_15 ) ;
F_95 ( V_15 ) ;
goto V_115;
}
F_93 ( & V_84 -> V_88 ) ;
V_146 = F_180 ( V_84 , V_78 ,
V_143 , V_17 , V_111 , V_15 , V_144 ) ;
if ( ! V_146 )
goto V_150;
F_181 ( V_144 , V_32 , true ) ;
return 0 ;
V_150:
F_91 ( & V_84 -> V_88 ) ;
if ( F_9 ( ! F_128 ( V_17 , * V_143 ) ) )
goto V_115;
V_149:
V_17 = F_182 ( V_17 ) ;
F_98 ( V_84 , V_85 , V_143 , V_17 ) ;
F_39 ( F_183 ( * V_143 ) ) ;
F_131 ( V_78 , V_111 , V_143 ) ;
V_115:
F_93 ( & V_84 -> V_88 ) ;
if ( V_145 != - 1 )
F_181 ( V_145 , V_32 , false ) ;
return 0 ;
}
int F_184 ( struct V_151 * V_152 , struct V_77 * V_78 ,
T_1 * V_17 , unsigned long V_111 )
{
int V_46 = 0 ;
if ( F_185 ( V_17 , V_78 ) == 1 ) {
struct V_15 * V_15 ;
T_5 V_86 ;
T_1 V_117 ;
V_86 = F_137 ( V_152 -> V_84 ) ;
V_117 = F_186 ( V_152 -> V_84 , V_111 , V_17 ) ;
F_187 ( V_152 , V_17 , V_111 ) ;
if ( F_18 ( V_117 ) ) {
V_152 -> V_84 -> V_90 -- ;
F_93 ( & V_152 -> V_84 -> V_88 ) ;
F_30 () ;
} else {
V_15 = F_19 ( V_117 ) ;
F_160 ( V_15 ) ;
F_39 ( F_162 ( V_15 ) < 0 ) ;
F_100 ( V_152 -> V_84 , V_89 , - V_32 ) ;
F_39 ( ! F_122 ( V_15 ) ) ;
V_152 -> V_84 -> V_90 -- ;
F_93 ( & V_152 -> V_84 -> V_88 ) ;
F_188 ( V_152 , V_15 ) ;
}
F_96 ( V_152 -> V_84 , V_86 ) ;
V_46 = 1 ;
}
return V_46 ;
}
int F_189 ( struct V_77 * V_78 , T_1 * V_17 ,
unsigned long V_111 , unsigned long V_153 ,
unsigned char * V_154 )
{
int V_46 = 0 ;
if ( F_185 ( V_17 , V_78 ) == 1 ) {
F_93 ( & V_78 -> V_134 -> V_88 ) ;
memset ( V_154 , 1 , ( V_153 - V_111 ) >> V_6 ) ;
V_46 = 1 ;
}
return V_46 ;
}
int F_190 ( struct V_77 * V_78 , struct V_77 * V_155 ,
unsigned long V_156 ,
unsigned long V_157 , unsigned long V_158 ,
T_1 * V_159 , T_1 * V_160 )
{
int V_46 = 0 ;
T_1 V_17 ;
struct V_83 * V_84 = V_78 -> V_134 ;
if ( ( V_156 & ~ V_97 ) ||
( V_157 & ~ V_97 ) ||
V_158 - V_156 < V_100 ||
( V_155 -> V_79 & V_161 ) )
goto V_72;
if ( F_191 ( ! F_92 ( * V_160 ) ) ) {
F_39 ( F_115 ( * V_160 ) ) ;
goto V_72;
}
V_46 = F_185 ( V_159 , V_78 ) ;
if ( V_46 == 1 ) {
V_17 = F_186 ( V_84 , V_156 , V_159 ) ;
F_39 ( ! F_92 ( * V_160 ) ) ;
F_98 ( V_84 , V_157 , V_160 , V_17 ) ;
F_93 ( & V_84 -> V_88 ) ;
}
V_72:
return V_46 ;
}
int F_192 ( struct V_77 * V_78 , T_1 * V_17 ,
unsigned long V_111 , T_8 V_162 , int V_163 )
{
struct V_83 * V_84 = V_78 -> V_134 ;
int V_46 = 0 ;
if ( F_185 ( V_17 , V_78 ) == 1 ) {
T_1 V_81 ;
V_81 = F_186 ( V_84 , V_111 , V_17 ) ;
if ( ! V_163 ) {
V_81 = F_193 ( V_81 , V_162 ) ;
F_31 ( F_169 ( V_81 ) ) ;
} else {
struct V_15 * V_15 = F_19 ( * V_17 ) ;
if ( F_162 ( V_15 ) == 1 &&
! F_183 ( * V_17 ) ) {
V_81 = F_194 ( V_81 ) ;
}
}
F_98 ( V_84 , V_111 , V_17 , V_81 ) ;
F_93 ( & V_78 -> V_134 -> V_88 ) ;
V_46 = 1 ;
}
return V_46 ;
}
int F_185 ( T_1 * V_17 , struct V_77 * V_78 )
{
F_91 ( & V_78 -> V_134 -> V_88 ) ;
if ( F_21 ( F_115 ( * V_17 ) ) ) {
if ( F_9 ( F_120 ( * V_17 ) ) ) {
F_93 ( & V_78 -> V_134 -> V_88 ) ;
F_121 ( V_78 -> V_116 , V_17 ) ;
return - 1 ;
} else {
return 1 ;
}
}
F_93 ( & V_78 -> V_134 -> V_88 ) ;
return 0 ;
}
T_1 * F_195 ( struct V_15 * V_15 ,
struct V_83 * V_84 ,
unsigned long V_95 ,
enum V_164 V_48 )
{
T_1 * V_17 , * V_46 = NULL ;
if ( V_95 & ~ V_97 )
goto V_72;
V_17 = F_196 ( V_84 , V_95 ) ;
if ( ! V_17 )
goto V_72;
if ( F_92 ( * V_17 ) )
goto V_72;
if ( F_19 ( * V_17 ) != V_15 )
goto V_72;
if ( V_48 == V_165 &&
F_120 ( * V_17 ) )
goto V_72;
if ( F_115 ( * V_17 ) ) {
F_39 ( V_48 == V_166 &&
! F_120 ( * V_17 ) ) ;
V_46 = V_17 ;
}
V_72:
return V_46 ;
}
static int F_197 ( struct V_15 * V_15 ,
struct V_77 * V_78 ,
unsigned long V_95 )
{
struct V_83 * V_84 = V_78 -> V_134 ;
T_1 * V_17 ;
int V_46 = 0 ;
const unsigned long V_122 = V_95 ;
const unsigned long V_123 = V_95 + V_100 ;
F_135 ( V_84 , V_122 , V_123 ) ;
F_91 ( & V_84 -> V_88 ) ;
V_17 = F_195 ( V_15 , V_84 , V_95 ,
V_165 ) ;
if ( V_17 ) {
F_198 ( V_78 , V_95 , V_17 ) ;
V_46 = 1 ;
}
F_93 ( & V_84 -> V_88 ) ;
F_150 ( V_84 , V_122 , V_123 ) ;
return V_46 ;
}
static void F_199 ( struct V_15 * V_15 ,
struct V_167 * V_168 )
{
int V_121 ;
struct V_1 * V_1 = F_200 ( V_15 ) ;
struct V_169 * V_169 ;
int V_170 = 0 ;
F_201 ( & V_1 -> V_171 ) ;
V_169 = F_202 ( V_15 , V_1 ) ;
F_203 ( V_15 ) ;
F_204 ( V_15 ) ;
for ( V_121 = V_32 - 1 ; V_121 >= 1 ; V_121 -- ) {
struct V_15 * V_172 = V_15 + V_121 ;
F_31 ( F_162 ( V_172 ) < 0 ) ;
V_170 += F_162 ( V_172 ) ;
F_31 ( V_170 < 0 ) ;
F_31 ( F_34 ( & V_172 -> V_173 ) != 0 ) ;
F_205 ( F_162 ( V_15 ) + F_162 ( V_172 ) + 1 ,
& V_172 -> V_173 ) ;
F_206 () ;
V_172 -> V_96 &= ~ V_174 | V_175 ;
V_172 -> V_96 |= ( V_15 -> V_96 &
( ( 1L << V_176 ) |
( 1L << V_177 ) |
( 1L << V_178 ) |
( 1L << V_179 ) ) ) ;
V_172 -> V_96 |= ( 1L << V_180 ) ;
F_148 () ;
V_172 -> V_181 = V_15 -> V_181 ;
F_31 ( V_172 -> V_141 ) ;
V_172 -> V_141 = V_15 -> V_141 ;
V_172 -> V_182 = V_15 -> V_182 + V_121 ;
F_207 ( V_172 , F_208 ( V_15 ) ) ;
F_31 ( ! F_209 ( V_172 ) ) ;
F_31 ( ! F_210 ( V_172 ) ) ;
F_31 ( ! F_211 ( V_172 ) ) ;
F_31 ( ! F_212 ( V_172 ) ) ;
F_213 ( V_15 , V_172 , V_169 , V_168 ) ;
}
F_214 ( V_170 , & V_15 -> V_173 ) ;
F_31 ( F_34 ( & V_15 -> V_173 ) <= 0 ) ;
F_215 ( V_1 , V_183 , - 1 ) ;
F_215 ( V_1 , V_184 , V_32 ) ;
F_216 ( V_15 ) ;
F_217 ( V_15 ) ;
F_218 ( & V_1 -> V_171 ) ;
for ( V_121 = 1 ; V_121 < V_32 ; V_121 ++ ) {
struct V_15 * V_172 = V_15 + V_121 ;
F_31 ( F_219 ( V_172 ) <= 0 ) ;
F_95 ( V_172 ) ;
}
F_31 ( F_219 ( V_15 ) <= 0 ) ;
}
static int F_220 ( struct V_15 * V_15 ,
struct V_77 * V_78 ,
unsigned long V_95 )
{
struct V_83 * V_84 = V_78 -> V_134 ;
T_1 * V_17 , V_120 ;
int V_46 = 0 , V_121 ;
T_5 V_86 ;
unsigned long V_85 ;
F_91 ( & V_84 -> V_88 ) ;
V_17 = F_195 ( V_15 , V_84 , V_95 ,
V_166 ) ;
if ( V_17 ) {
V_86 = F_137 ( V_84 ) ;
F_138 ( V_84 , & V_120 , V_86 ) ;
V_85 = V_95 ;
for ( V_121 = 0 ; V_121 < V_32 ; V_121 ++ , V_85 += V_126 ) {
T_7 * V_98 , V_81 ;
F_31 ( F_87 ( V_15 + V_121 ) ) ;
V_81 = F_139 ( V_15 + V_121 , V_78 -> V_82 ) ;
V_81 = F_140 ( F_141 ( V_81 ) , V_78 ) ;
if ( ! F_169 ( * V_17 ) )
V_81 = F_221 ( V_81 ) ;
else
F_31 ( F_162 ( V_15 ) != 1 ) ;
if ( ! F_222 ( * V_17 ) )
V_81 = F_223 ( V_81 ) ;
if ( F_183 ( * V_17 ) )
V_81 = F_224 ( V_81 ) ;
V_98 = F_116 ( & V_120 , V_85 ) ;
F_31 ( ! F_145 ( * V_98 ) ) ;
F_146 ( V_84 , V_85 , V_98 , V_81 ) ;
F_147 ( V_98 ) ;
}
F_148 () ;
F_225 ( V_78 , V_95 , V_17 ) ;
F_138 ( V_84 , V_17 , V_86 ) ;
V_46 = 1 ;
}
F_93 ( & V_84 -> V_88 ) ;
return V_46 ;
}
static void F_226 ( struct V_15 * V_15 ,
struct V_116 * V_116 ,
struct V_167 * V_168 )
{
int V_185 , V_186 ;
T_9 V_187 = V_15 -> V_182 << ( V_188 - V_6 ) ;
struct V_189 * V_190 ;
F_31 ( ! F_122 ( V_15 ) ) ;
F_31 ( F_227 ( V_15 ) ) ;
V_185 = 0 ;
F_228 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_77 * V_78 = V_190 -> V_78 ;
unsigned long V_111 = F_229 ( V_15 , V_78 ) ;
F_31 ( F_230 ( V_78 ) ) ;
V_185 += F_197 ( V_15 , V_78 , V_111 ) ;
}
if ( V_185 != F_162 ( V_15 ) )
F_11 ( V_11 L_15 ,
V_185 , F_162 ( V_15 ) ) ;
F_31 ( V_185 != F_162 ( V_15 ) ) ;
F_199 ( V_15 , V_168 ) ;
V_186 = 0 ;
F_228 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_77 * V_78 = V_190 -> V_78 ;
unsigned long V_111 = F_229 ( V_15 , V_78 ) ;
F_31 ( F_230 ( V_78 ) ) ;
V_186 += F_220 ( V_15 , V_78 , V_111 ) ;
}
if ( V_185 != V_186 )
F_11 ( V_11 L_16 ,
V_185 , V_186 , F_162 ( V_15 ) ) ;
F_31 ( V_185 != V_186 ) ;
}
int F_231 ( struct V_15 * V_15 , struct V_167 * V_168 )
{
struct V_116 * V_116 ;
int V_46 = 1 ;
F_31 ( F_16 ( V_15 ) ) ;
F_31 ( ! F_209 ( V_15 ) ) ;
V_116 = F_232 ( V_15 ) ;
if ( ! V_116 )
goto V_72;
F_233 ( V_116 ) ;
V_46 = 0 ;
if ( ! F_87 ( V_15 ) )
goto V_115;
F_31 ( ! F_212 ( V_15 ) ) ;
F_226 ( V_15 , V_116 , V_168 ) ;
F_24 ( V_191 ) ;
F_31 ( F_87 ( V_15 ) ) ;
V_115:
F_234 ( V_116 ) ;
F_235 ( V_116 ) ;
V_72:
return V_46 ;
}
int F_236 ( struct V_77 * V_78 ,
unsigned long * V_79 , int V_192 )
{
struct V_83 * V_84 = V_78 -> V_134 ;
switch ( V_192 ) {
case V_193 :
if ( * V_79 & ( V_194 | V_195 ) )
return - V_43 ;
if ( V_84 -> V_196 & V_161 )
return - V_43 ;
* V_79 &= ~ V_161 ;
* V_79 |= V_194 ;
if ( F_9 ( F_237 ( V_78 ) ) )
return - V_67 ;
break;
case V_197 :
if ( * V_79 & ( V_161 | V_195 ) )
return - V_43 ;
* V_79 &= ~ V_194 ;
* V_79 |= V_161 ;
break;
}
return 0 ;
}
static int T_4 F_77 ( void )
{
V_198 = F_238 ( L_17 ,
sizeof( struct V_199 ) ,
F_239 ( struct V_199 ) , 0 , NULL ) ;
if ( ! V_198 )
return - V_67 ;
return 0 ;
}
static inline struct V_199 * F_240 ( void )
{
if ( ! V_198 )
return NULL ;
return F_241 ( V_198 , V_106 ) ;
}
static inline void F_242 ( struct V_199 * V_199 )
{
F_243 ( V_198 , V_199 ) ;
}
static struct V_199 * F_244 ( struct V_83 * V_84 )
{
struct V_199 * V_199 ;
F_245 (mm_slots_hash, mm_slot, hash, (unsigned long)mm)
if ( V_84 == V_199 -> V_84 )
return V_199 ;
return NULL ;
}
static void F_246 ( struct V_83 * V_84 ,
struct V_199 * V_199 )
{
V_199 -> V_84 = V_84 ;
F_247 ( V_200 , & V_199 -> V_201 , ( long ) V_84 ) ;
}
static inline int F_248 ( struct V_83 * V_84 )
{
return F_34 ( & V_84 -> V_202 ) == 0 ;
}
int F_249 ( struct V_83 * V_84 )
{
struct V_199 * V_199 ;
int V_203 ;
V_199 = F_240 () ;
if ( ! V_199 )
return - V_67 ;
F_39 ( F_248 ( V_84 ) ) ;
if ( F_9 ( F_250 ( V_204 , & V_84 -> V_96 ) ) ) {
F_242 ( V_199 ) ;
return 0 ;
}
F_91 ( & V_205 ) ;
F_246 ( V_84 , V_199 ) ;
V_203 = F_13 ( & V_12 . V_13 ) ;
F_251 ( & V_199 -> V_206 , & V_12 . V_13 ) ;
F_93 ( & V_205 ) ;
F_252 ( & V_84 -> V_207 ) ;
if ( V_203 )
F_14 ( & V_14 ) ;
return 0 ;
}
int F_237 ( struct V_77 * V_78 )
{
unsigned long V_208 , V_209 ;
if ( ! V_78 -> V_116 )
return 0 ;
if ( V_78 -> V_210 )
return 0 ;
F_39 ( V_78 -> V_79 & V_195 ) ;
V_208 = ( V_78 -> V_99 + ~ V_97 ) & V_97 ;
V_209 = V_78 -> V_101 & V_97 ;
if ( V_208 < V_209 )
return F_109 ( V_78 ) ;
return 0 ;
}
void F_253 ( struct V_83 * V_84 )
{
struct V_199 * V_199 ;
int free = 0 ;
F_91 ( & V_205 ) ;
V_199 = F_244 ( V_84 ) ;
if ( V_199 && V_12 . V_199 != V_199 ) {
F_254 ( & V_199 -> V_201 ) ;
F_255 ( & V_199 -> V_206 ) ;
free = 1 ;
}
F_93 ( & V_205 ) ;
if ( free ) {
F_42 ( V_204 , & V_84 -> V_96 ) ;
F_242 ( V_199 ) ;
F_256 ( V_84 ) ;
} else if ( V_199 ) {
F_257 ( & V_84 -> V_211 ) ;
F_258 ( & V_84 -> V_211 ) ;
}
}
static void F_259 ( struct V_15 * V_15 )
{
F_260 ( V_15 , V_212 + 0 ) ;
F_174 ( V_15 ) ;
F_261 ( V_15 ) ;
}
static void F_262 ( T_7 * V_98 , T_7 * V_213 )
{
while ( -- V_213 >= V_98 ) {
T_7 V_214 = * V_213 ;
if ( ! F_145 ( V_214 ) )
F_259 ( F_263 ( V_214 ) ) ;
}
}
static int F_264 ( struct V_77 * V_78 ,
unsigned long V_95 ,
T_7 * V_98 )
{
struct V_15 * V_15 ;
T_7 * V_213 ;
int V_215 = 0 , V_216 = 0 ;
for ( V_213 = V_98 ; V_213 < V_98 + V_32 ;
V_213 ++ , V_95 += V_126 ) {
T_7 V_214 = * V_213 ;
if ( F_145 ( V_214 ) ) {
if ( ++ V_216 <= V_63 )
continue;
else
goto V_72;
}
if ( ! F_265 ( V_214 ) || ! F_266 ( V_214 ) )
goto V_72;
V_15 = F_267 ( V_78 , V_95 , V_214 ) ;
if ( F_9 ( ! V_15 ) )
goto V_72;
F_39 ( F_87 ( V_15 ) ) ;
F_31 ( ! F_209 ( V_15 ) ) ;
F_39 ( ! F_212 ( V_15 ) ) ;
if ( F_219 ( V_15 ) != 1 )
goto V_72;
if ( ! F_171 ( V_15 ) )
goto V_72;
if ( F_268 ( V_15 ) ) {
F_174 ( V_15 ) ;
goto V_72;
}
F_269 ( V_15 , V_212 + 0 ) ;
F_39 ( ! F_270 ( V_15 ) ) ;
F_39 ( F_271 ( V_15 ) ) ;
if ( F_272 ( V_214 ) || F_273 ( V_15 ) ||
F_274 ( V_78 -> V_134 , V_95 ) )
V_215 = 1 ;
}
if ( F_21 ( V_215 ) )
return 1 ;
V_72:
F_262 ( V_98 , V_213 ) ;
return 0 ;
}
static void F_275 ( T_7 * V_98 , struct V_15 * V_15 ,
struct V_77 * V_78 ,
unsigned long V_95 ,
T_10 * V_217 )
{
T_7 * V_213 ;
for ( V_213 = V_98 ; V_213 < V_98 + V_32 ; V_213 ++ ) {
T_7 V_214 = * V_213 ;
struct V_15 * V_112 ;
if ( F_145 ( V_214 ) ) {
F_134 ( V_15 , V_95 ) ;
F_100 ( V_78 -> V_134 , V_89 , 1 ) ;
} else {
V_112 = F_263 ( V_214 ) ;
F_158 ( V_15 , V_112 , V_95 , V_78 ) ;
F_39 ( F_162 ( V_112 ) != 1 ) ;
F_259 ( V_112 ) ;
F_91 ( V_217 ) ;
F_276 ( V_78 -> V_134 , V_95 , V_213 ) ;
F_160 ( V_112 ) ;
F_93 ( V_217 ) ;
F_277 ( V_112 ) ;
}
V_95 += V_126 ;
V_15 ++ ;
}
}
static void F_278 ( void )
{
F_279 ( V_14 , false ,
F_280 ( V_57 ) ) ;
}
static bool F_281 ( struct V_15 * * V_218 , bool * V_219 )
{
if ( F_10 ( * V_218 ) ) {
if ( ! * V_219 )
return false ;
* V_219 = false ;
* V_218 = NULL ;
F_278 () ;
} else if ( * V_218 ) {
F_95 ( * V_218 ) ;
* V_218 = NULL ;
}
return true ;
}
static struct V_15
* F_282 ( struct V_15 * * V_218 , struct V_83 * V_84 ,
struct V_77 * V_78 , unsigned long V_95 ,
int V_220 )
{
F_39 ( * V_218 ) ;
* V_218 = F_102 ( F_283 () , V_78 , V_95 ,
V_220 , V_129 ) ;
F_284 ( & V_84 -> V_211 ) ;
if ( F_9 ( ! * V_218 ) ) {
F_24 ( V_221 ) ;
* V_218 = F_170 ( - V_67 ) ;
return NULL ;
}
F_24 ( V_222 ) ;
return * V_218 ;
}
static struct V_15 * F_285 ( bool * V_219 )
{
struct V_15 * V_218 ;
do {
V_218 = F_104 ( F_283 () ) ;
if ( ! V_218 ) {
F_24 ( V_221 ) ;
if ( ! * V_219 )
return NULL ;
* V_219 = false ;
F_278 () ;
} else
F_24 ( V_222 ) ;
} while ( F_9 ( ! V_218 ) && F_21 ( F_2 () ) );
return V_218 ;
}
static bool F_281 ( struct V_15 * * V_218 , bool * V_219 )
{
if ( ! * V_218 )
* V_218 = F_285 ( V_219 ) ;
if ( F_9 ( ! * V_218 ) )
return false ;
return true ;
}
static struct V_15
* F_282 ( struct V_15 * * V_218 , struct V_83 * V_84 ,
struct V_77 * V_78 , unsigned long V_95 ,
int V_220 )
{
F_284 ( & V_84 -> V_211 ) ;
F_39 ( ! * V_218 ) ;
return * V_218 ;
}
static bool F_286 ( struct V_77 * V_78 )
{
if ( ( ! ( V_78 -> V_79 & V_194 ) && ! F_287 () ) ||
( V_78 -> V_79 & V_161 ) )
return false ;
if ( ! V_78 -> V_116 || V_78 -> V_210 )
return false ;
if ( F_230 ( V_78 ) )
return false ;
F_39 ( V_78 -> V_79 & V_195 ) ;
return true ;
}
static void F_288 ( struct V_83 * V_84 ,
unsigned long V_95 ,
struct V_15 * * V_218 ,
struct V_77 * V_78 ,
int V_220 )
{
T_1 * V_17 , V_120 ;
T_7 * V_98 ;
T_5 V_86 ;
struct V_15 * V_131 ;
T_10 * V_217 ;
int V_223 ;
unsigned long V_208 , V_209 ;
unsigned long V_122 ;
unsigned long V_123 ;
F_39 ( V_95 & ~ V_97 ) ;
V_131 = F_282 ( V_218 , V_84 , V_78 , V_95 , V_220 ) ;
if ( ! V_131 )
return;
if ( F_9 ( F_113 ( V_131 , V_84 , V_106 ) ) )
return;
F_257 ( & V_84 -> V_211 ) ;
if ( F_9 ( F_248 ( V_84 ) ) )
goto V_72;
V_78 = F_289 ( V_84 , V_95 ) ;
V_208 = ( V_78 -> V_99 + ~ V_97 ) & V_97 ;
V_209 = V_78 -> V_101 & V_97 ;
if ( V_95 < V_208 || V_95 + V_100 > V_209 )
goto V_72;
if ( ! F_286 ( V_78 ) )
goto V_72;
V_17 = F_196 ( V_84 , V_95 ) ;
if ( ! V_17 )
goto V_72;
if ( F_115 ( * V_17 ) )
goto V_72;
F_233 ( V_78 -> V_116 ) ;
V_98 = F_116 ( V_17 , V_95 ) ;
V_217 = F_290 ( V_84 , V_17 ) ;
V_122 = V_95 ;
V_123 = V_95 + V_100 ;
F_135 ( V_84 , V_122 , V_123 ) ;
F_91 ( & V_84 -> V_88 ) ;
V_120 = F_136 ( V_78 , V_95 , V_17 ) ;
F_93 ( & V_84 -> V_88 ) ;
F_150 ( V_84 , V_122 , V_123 ) ;
F_91 ( V_217 ) ;
V_223 = F_264 ( V_78 , V_95 , V_98 ) ;
F_93 ( V_217 ) ;
if ( F_9 ( ! V_223 ) ) {
F_147 ( V_98 ) ;
F_91 ( & V_84 -> V_88 ) ;
F_31 ( ! F_92 ( * V_17 ) ) ;
F_138 ( V_84 , V_17 , F_291 ( V_120 ) ) ;
F_93 ( & V_84 -> V_88 ) ;
F_234 ( V_78 -> V_116 ) ;
goto V_72;
}
F_234 ( V_78 -> V_116 ) ;
F_275 ( V_98 , V_131 , V_78 , V_95 , V_217 ) ;
F_147 ( V_98 ) ;
F_90 ( V_131 ) ;
V_86 = F_291 ( V_120 ) ;
V_120 = F_82 ( V_131 , V_78 ) ;
F_148 () ;
F_91 ( & V_84 -> V_88 ) ;
F_31 ( ! F_92 ( * V_17 ) ) ;
F_97 ( V_131 , V_78 , V_95 ) ;
F_98 ( V_84 , V_95 , V_17 , V_120 ) ;
F_131 ( V_78 , V_95 , V_17 ) ;
F_99 ( V_84 , V_86 ) ;
F_93 ( & V_84 -> V_88 ) ;
* V_218 = NULL ;
V_60 ++ ;
V_224:
F_258 ( & V_84 -> V_211 ) ;
return;
V_72:
F_94 ( V_131 ) ;
goto V_224;
}
static int F_292 ( struct V_83 * V_84 ,
struct V_77 * V_78 ,
unsigned long V_95 ,
struct V_15 * * V_218 )
{
T_1 * V_17 ;
T_7 * V_98 , * V_213 ;
int V_46 = 0 , V_215 = 0 , V_216 = 0 ;
struct V_15 * V_15 ;
unsigned long V_225 ;
T_10 * V_217 ;
int V_220 = V_226 ;
F_39 ( V_95 & ~ V_97 ) ;
V_17 = F_196 ( V_84 , V_95 ) ;
if ( ! V_17 )
goto V_72;
if ( F_115 ( * V_17 ) )
goto V_72;
V_98 = F_293 ( V_84 , V_17 , V_95 , & V_217 ) ;
for ( V_225 = V_95 , V_213 = V_98 ; V_213 < V_98 + V_32 ;
V_213 ++ , V_225 += V_126 ) {
T_7 V_214 = * V_213 ;
if ( F_145 ( V_214 ) ) {
if ( ++ V_216 <= V_63 )
continue;
else
goto V_227;
}
if ( ! F_265 ( V_214 ) || ! F_266 ( V_214 ) )
goto V_227;
V_15 = F_267 ( V_78 , V_225 , V_214 ) ;
if ( F_9 ( ! V_15 ) )
goto V_227;
if ( V_220 == V_226 )
V_220 = F_154 ( V_15 ) ;
F_39 ( F_87 ( V_15 ) ) ;
if ( ! F_271 ( V_15 ) || F_270 ( V_15 ) || ! F_209 ( V_15 ) )
goto V_227;
if ( F_219 ( V_15 ) != 1 )
goto V_227;
if ( F_272 ( V_214 ) || F_273 ( V_15 ) ||
F_274 ( V_78 -> V_134 , V_95 ) )
V_215 = 1 ;
}
if ( V_215 )
V_46 = 1 ;
V_227:
F_294 ( V_98 , V_217 ) ;
if ( V_46 )
F_288 ( V_84 , V_95 , V_218 , V_78 , V_220 ) ;
V_72:
return V_46 ;
}
static void F_295 ( struct V_199 * V_199 )
{
struct V_83 * V_84 = V_199 -> V_84 ;
F_39 ( V_228 != 1 && ! F_296 ( & V_205 ) ) ;
if ( F_248 ( V_84 ) ) {
F_254 ( & V_199 -> V_201 ) ;
F_255 ( & V_199 -> V_206 ) ;
F_242 ( V_199 ) ;
F_256 ( V_84 ) ;
}
}
static unsigned int F_297 ( unsigned int V_59 ,
struct V_15 * * V_218 )
__releases( &khugepaged_mm_lock
static int F_298 ( void )
{
return ! F_13 ( & V_12 . V_13 ) &&
F_2 () ;
}
static int F_299 ( void )
{
return ! F_13 ( & V_12 . V_13 ) ||
F_300 () ;
}
static void F_301 ( void )
{
struct V_15 * V_218 = NULL ;
unsigned int V_229 = 0 , V_230 = 0 ;
unsigned int V_59 = V_58 ;
bool V_219 = true ;
F_302 () ;
while ( V_229 < V_59 ) {
if ( ! F_281 ( & V_218 , & V_219 ) )
break;
F_159 () ;
if ( F_9 ( F_300 () || F_303 ( V_231 ) ) )
break;
F_91 ( & V_205 ) ;
if ( ! V_12 . V_199 )
V_230 ++ ;
if ( F_298 () &&
V_230 < 2 )
V_229 += F_297 ( V_59 - V_229 ,
& V_218 ) ;
else
V_229 = V_59 ;
F_93 ( & V_205 ) ;
}
if ( ! F_304 ( V_218 ) )
F_95 ( V_218 ) ;
}
static void F_305 ( void )
{
F_306 () ;
if ( F_298 () ) {
if ( ! V_54 )
return;
F_279 ( V_14 ,
F_300 () ,
F_280 ( V_54 ) ) ;
return;
}
if ( F_2 () )
F_307 ( V_14 , F_299 () ) ;
}
static int V_10 ( void * V_216 )
{
struct V_199 * V_199 ;
F_308 () ;
F_309 ( V_231 , 19 ) ;
while ( ! F_300 () ) {
F_301 () ;
F_305 () ;
}
F_91 ( & V_205 ) ;
V_199 = V_12 . V_199 ;
V_12 . V_199 = NULL ;
if ( V_199 )
F_295 ( V_199 ) ;
F_93 ( & V_205 ) ;
return 0 ;
}
static void F_310 ( struct V_77 * V_78 ,
unsigned long V_85 , T_1 * V_17 )
{
struct V_83 * V_84 = V_78 -> V_134 ;
T_5 V_86 ;
T_1 V_120 ;
int V_121 ;
F_136 ( V_78 , V_85 , V_17 ) ;
V_86 = F_137 ( V_84 ) ;
F_138 ( V_84 , & V_120 , V_86 ) ;
for ( V_121 = 0 ; V_121 < V_32 ; V_121 ++ , V_85 += V_126 ) {
T_7 * V_98 , V_81 ;
V_81 = F_142 ( F_143 ( V_85 ) , V_78 -> V_82 ) ;
V_81 = F_144 ( V_81 ) ;
V_98 = F_116 ( & V_120 , V_85 ) ;
F_39 ( ! F_145 ( * V_98 ) ) ;
F_146 ( V_84 , V_85 , V_98 , V_81 ) ;
F_147 ( V_98 ) ;
}
F_148 () ;
F_138 ( V_84 , V_17 , V_86 ) ;
F_30 () ;
}
void F_311 ( struct V_77 * V_78 , unsigned long V_95 ,
T_1 * V_17 )
{
struct V_15 * V_15 ;
struct V_83 * V_84 = V_78 -> V_134 ;
unsigned long V_85 = V_95 & V_97 ;
unsigned long V_122 ;
unsigned long V_123 ;
F_31 ( V_78 -> V_99 > V_85 || V_78 -> V_101 < V_85 + V_100 ) ;
V_122 = V_85 ;
V_123 = V_85 + V_100 ;
F_135 ( V_84 , V_122 , V_123 ) ;
F_91 ( & V_84 -> V_88 ) ;
if ( F_9 ( ! F_115 ( * V_17 ) ) ) {
F_93 ( & V_84 -> V_88 ) ;
F_150 ( V_84 , V_122 , V_123 ) ;
return;
}
if ( F_18 ( * V_17 ) ) {
F_310 ( V_78 , V_85 , V_17 ) ;
F_93 ( & V_84 -> V_88 ) ;
F_150 ( V_84 , V_122 , V_123 ) ;
return;
}
V_15 = F_19 ( * V_17 ) ;
F_39 ( ! F_219 ( V_15 ) ) ;
F_123 ( V_15 ) ;
F_93 ( & V_84 -> V_88 ) ;
F_150 ( V_84 , V_122 , V_123 ) ;
F_165 ( V_15 ) ;
F_95 ( V_15 ) ;
F_31 ( F_115 ( * V_17 ) ) ;
}
void F_312 ( struct V_83 * V_84 , unsigned long V_95 ,
T_1 * V_17 )
{
struct V_77 * V_78 ;
V_78 = F_289 ( V_84 , V_95 ) ;
F_31 ( V_78 == NULL ) ;
F_313 ( V_78 , V_95 , V_17 ) ;
}
static void F_314 ( struct V_83 * V_84 ,
unsigned long V_95 )
{
T_1 * V_17 ;
F_39 ( ! ( V_95 & ~ V_97 ) ) ;
V_17 = F_196 ( V_84 , V_95 ) ;
if ( ! V_17 )
return;
F_312 ( V_84 , V_95 , V_17 ) ;
}
void F_315 ( struct V_77 * V_78 ,
unsigned long V_232 ,
unsigned long V_153 ,
long V_233 )
{
if ( V_232 & ~ V_97 &&
( V_232 & V_97 ) >= V_78 -> V_99 &&
( V_232 & V_97 ) + V_100 <= V_78 -> V_101 )
F_314 ( V_78 -> V_134 , V_232 ) ;
if ( V_153 & ~ V_97 &&
( V_153 & V_97 ) >= V_78 -> V_99 &&
( V_153 & V_97 ) + V_100 <= V_78 -> V_101 )
F_314 ( V_78 -> V_134 , V_153 ) ;
if ( V_233 > 0 ) {
struct V_77 * V_234 = V_78 -> V_235 ;
unsigned long V_236 = V_234 -> V_99 ;
V_236 += V_233 << V_6 ;
if ( V_236 & ~ V_97 &&
( V_236 & V_97 ) >= V_234 -> V_99 &&
( V_236 & V_97 ) + V_100 <= V_234 -> V_101 )
F_314 ( V_234 -> V_134 , V_236 ) ;
}
}
