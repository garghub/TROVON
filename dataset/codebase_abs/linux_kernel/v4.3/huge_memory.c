static void F_1 ( void )
{
struct V_1 * V_1 ;
int V_2 = 0 ;
unsigned long V_3 ;
F_2 (zone)
V_2 ++ ;
V_3 = V_4 * V_2 * 2 ;
V_3 += V_4 * V_2 *
V_5 * V_5 ;
V_3 = F_3 ( V_3 ,
( unsigned long ) F_4 () / 20 ) ;
V_3 <<= ( V_6 - 10 ) ;
if ( V_3 > V_7 ) {
if ( V_8 >= 0 )
F_5 ( L_1
L_2 ,
V_7 , V_3 ) ;
V_7 = V_3 ;
}
F_6 () ;
}
static int F_7 ( void )
{
int V_9 = 0 ;
if ( F_8 () ) {
if ( ! V_10 )
V_10 = F_9 ( V_11 , NULL ,
L_3 ) ;
if ( F_10 ( F_11 ( V_10 ) ) ) {
F_12 ( L_4 ) ;
V_9 = F_13 ( V_10 ) ;
V_10 = NULL ;
goto V_12;
}
if ( ! F_14 ( & V_13 . V_14 ) )
F_15 ( & V_15 ) ;
F_1 () ;
} else if ( V_10 ) {
F_16 ( V_10 ) ;
V_10 = NULL ;
}
V_12:
return V_9 ;
}
struct V_16 * F_17 ( void )
{
struct V_16 * V_17 ;
V_18:
if ( F_18 ( F_19 ( & V_19 ) ) )
return F_20 ( V_20 ) ;
V_17 = F_21 ( ( V_21 | V_22 ) & ~ V_23 ,
V_24 ) ;
if ( ! V_17 ) {
F_22 ( V_25 ) ;
return NULL ;
}
F_22 ( V_26 ) ;
F_23 () ;
if ( F_24 ( & V_20 , NULL , V_17 ) ) {
F_25 () ;
F_26 ( V_17 , F_27 ( V_17 ) ) ;
goto V_18;
}
F_28 ( & V_19 , 2 ) ;
F_25 () ;
return F_20 ( V_20 ) ;
}
static void F_29 ( void )
{
F_30 ( F_31 ( & V_19 ) ) ;
}
static unsigned long F_32 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
return F_33 ( & V_19 ) == 1 ? V_31 : 0 ;
}
static unsigned long F_34 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
if ( F_35 ( & V_19 , 1 , 0 ) == 1 ) {
struct V_16 * V_17 = F_36 ( & V_20 , NULL ) ;
F_30 ( V_17 == NULL ) ;
F_26 ( V_17 , F_27 ( V_17 ) ) ;
return V_31 ;
}
return 0 ;
}
static T_1 F_37 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 ,
enum V_37 V_38 ,
enum V_37 V_39 )
{
if ( F_38 ( V_38 , & V_40 ) ) {
F_39 ( F_38 ( V_39 , & V_40 ) ) ;
return sprintf ( V_36 , L_5 ) ;
} else if ( F_38 ( V_39 , & V_40 ) )
return sprintf ( V_36 , L_6 ) ;
else
return sprintf ( V_36 , L_7 ) ;
}
static T_1 F_40 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_2 V_41 ,
enum V_37 V_38 ,
enum V_37 V_39 )
{
if ( ! memcmp ( L_8 , V_36 ,
F_3 ( sizeof( L_8 ) - 1 , V_41 ) ) ) {
F_41 ( V_38 , & V_40 ) ;
F_42 ( V_39 , & V_40 ) ;
} else if ( ! memcmp ( L_9 , V_36 ,
F_3 ( sizeof( L_9 ) - 1 , V_41 ) ) ) {
F_42 ( V_38 , & V_40 ) ;
F_41 ( V_39 , & V_40 ) ;
} else if ( ! memcmp ( L_10 , V_36 ,
F_3 ( sizeof( L_10 ) - 1 , V_41 ) ) ) {
F_42 ( V_38 , & V_40 ) ;
F_42 ( V_39 , & V_40 ) ;
} else
return - V_42 ;
return V_41 ;
}
static T_1 F_43 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 )
{
return F_37 ( V_33 , V_35 , V_36 ,
V_43 ,
V_44 ) ;
}
static T_1 F_44 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_2 V_41 )
{
T_1 V_45 ;
V_45 = F_40 ( V_33 , V_35 , V_36 , V_41 ,
V_43 ,
V_44 ) ;
if ( V_45 > 0 ) {
int V_9 ;
F_45 ( & V_46 ) ;
V_9 = F_7 () ;
F_46 ( & V_46 ) ;
if ( V_9 )
V_45 = V_9 ;
}
return V_45 ;
}
static T_1 F_47 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 ,
enum V_37 V_47 )
{
return sprintf ( V_36 , L_11 ,
! ! F_38 ( V_47 , & V_40 ) ) ;
}
static T_1 F_48 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_2 V_41 ,
enum V_37 V_47 )
{
unsigned long V_48 ;
int V_45 ;
V_45 = F_49 ( V_36 , 10 , & V_48 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_48 > 1 )
return - V_42 ;
if ( V_48 )
F_41 ( V_47 , & V_40 ) ;
else
F_42 ( V_47 , & V_40 ) ;
return V_41 ;
}
static T_1 F_50 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 )
{
return F_37 ( V_33 , V_35 , V_36 ,
V_49 ,
V_50 ) ;
}
static T_1 F_51 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_2 V_41 )
{
return F_40 ( V_33 , V_35 , V_36 , V_41 ,
V_49 ,
V_50 ) ;
}
static T_1 F_52 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 )
{
return F_47 ( V_33 , V_35 , V_36 ,
V_51 ) ;
}
static T_1 F_53 ( struct V_32 * V_33 ,
struct V_34 * V_35 , const char * V_36 , T_2 V_41 )
{
return F_48 ( V_33 , V_35 , V_36 , V_41 ,
V_51 ) ;
}
static T_1 F_54 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 )
{
return F_47 ( V_33 , V_35 , V_36 ,
V_52 ) ;
}
static T_1 F_55 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_2 V_41 )
{
return F_48 ( V_33 , V_35 , V_36 , V_41 ,
V_52 ) ;
}
static T_1 F_56 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_12 , V_53 ) ;
}
static T_1 F_57 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_2 V_41 )
{
unsigned long V_54 ;
int V_9 ;
V_9 = F_49 ( V_36 , 10 , & V_54 ) ;
if ( V_9 || V_54 > V_55 )
return - V_42 ;
V_53 = V_54 ;
F_15 ( & V_15 ) ;
return V_41 ;
}
static T_1 F_58 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_12 , V_56 ) ;
}
static T_1 F_59 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_2 V_41 )
{
unsigned long V_54 ;
int V_9 ;
V_9 = F_49 ( V_36 , 10 , & V_54 ) ;
if ( V_9 || V_54 > V_55 )
return - V_42 ;
V_56 = V_54 ;
F_15 ( & V_15 ) ;
return V_41 ;
}
static T_1 F_60 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_12 , V_57 ) ;
}
static T_1 F_61 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_2 V_41 )
{
int V_9 ;
unsigned long V_58 ;
V_9 = F_49 ( V_36 , 10 , & V_58 ) ;
if ( V_9 || ! V_58 || V_58 > V_55 )
return - V_42 ;
V_57 = V_58 ;
return V_41 ;
}
static T_1 F_62 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_12 , V_59 ) ;
}
static T_1 F_63 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_12 , V_60 ) ;
}
static T_1 F_64 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 )
{
return F_47 ( V_33 , V_35 , V_36 ,
V_61 ) ;
}
static T_1 F_65 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_2 V_41 )
{
return F_48 ( V_33 , V_35 , V_36 , V_41 ,
V_61 ) ;
}
static T_1 F_66 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_12 , V_62 ) ;
}
static T_1 F_67 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_2 V_41 )
{
int V_9 ;
unsigned long V_63 ;
V_9 = F_49 ( V_36 , 10 , & V_63 ) ;
if ( V_9 || V_63 > V_31 - 1 )
return - V_42 ;
V_62 = V_63 ;
return V_41 ;
}
static int T_3 F_68 ( struct V_32 * * V_64 )
{
int V_9 ;
* V_64 = F_69 ( L_13 , V_65 ) ;
if ( F_10 ( ! * V_64 ) ) {
F_12 ( L_14 ) ;
return - V_66 ;
}
V_9 = F_70 ( * V_64 , & V_67 ) ;
if ( V_9 ) {
F_12 ( L_15 ) ;
goto V_68;
}
V_9 = F_70 ( * V_64 , & V_69 ) ;
if ( V_9 ) {
F_12 ( L_15 ) ;
goto V_70;
}
return 0 ;
V_70:
F_71 ( * V_64 , & V_67 ) ;
V_68:
F_72 ( * V_64 ) ;
return V_9 ;
}
static void T_3 F_73 ( struct V_32 * V_64 )
{
F_71 ( V_64 , & V_69 ) ;
F_71 ( V_64 , & V_67 ) ;
F_72 ( V_64 ) ;
}
static inline int F_68 ( struct V_32 * * V_64 )
{
return 0 ;
}
static inline void F_73 ( struct V_32 * V_64 )
{
}
static int T_3 F_74 ( void )
{
int V_9 ;
struct V_32 * V_64 ;
if ( ! F_75 () ) {
V_40 = 0 ;
return - V_42 ;
}
V_9 = F_68 ( & V_64 ) ;
if ( V_9 )
goto V_71;
V_9 = F_76 () ;
if ( V_9 )
goto V_72;
V_9 = F_77 ( & V_73 ) ;
if ( V_9 )
goto V_74;
if ( V_75 < ( 512 << ( 20 - V_6 ) ) ) {
V_40 = 0 ;
return 0 ;
}
V_9 = F_7 () ;
if ( V_9 )
goto V_76;
return 0 ;
V_76:
F_78 ( & V_73 ) ;
V_74:
F_79 () ;
V_72:
F_73 ( V_64 ) ;
V_71:
return V_9 ;
}
static int T_3 F_80 ( char * V_77 )
{
int V_45 = 0 ;
if ( ! V_77 )
goto V_78;
if ( ! strcmp ( V_77 , L_8 ) ) {
F_41 ( V_43 ,
& V_40 ) ;
F_42 ( V_44 ,
& V_40 ) ;
V_45 = 1 ;
} else if ( ! strcmp ( V_77 , L_9 ) ) {
F_42 ( V_43 ,
& V_40 ) ;
F_41 ( V_44 ,
& V_40 ) ;
V_45 = 1 ;
} else if ( ! strcmp ( V_77 , L_10 ) ) {
F_42 ( V_43 ,
& V_40 ) ;
F_42 ( V_44 ,
& V_40 ) ;
V_45 = 1 ;
}
V_78:
if ( ! V_45 )
F_81 ( L_16 ) ;
return V_45 ;
}
T_4 F_82 ( T_4 V_79 , struct V_80 * V_81 )
{
if ( F_18 ( V_81 -> V_82 & V_83 ) )
V_79 = F_83 ( V_79 ) ;
return V_79 ;
}
static inline T_4 F_84 ( struct V_16 * V_16 , T_5 V_84 )
{
T_4 V_85 ;
V_85 = F_85 ( V_16 , V_84 ) ;
V_85 = F_86 ( V_85 ) ;
return V_85 ;
}
static int F_87 ( struct V_86 * V_87 ,
struct V_80 * V_81 ,
unsigned long V_88 , T_4 * V_79 ,
struct V_16 * V_16 , T_6 V_89 ,
unsigned int V_90 )
{
struct V_91 * V_92 ;
T_7 V_93 ;
T_8 * V_94 ;
unsigned long V_95 = V_88 & V_96 ;
F_88 ( ! F_89 ( V_16 ) , V_16 ) ;
if ( F_90 ( V_16 , V_87 , V_89 , & V_92 ) ) {
F_91 ( V_16 ) ;
F_22 ( V_97 ) ;
return V_98 ;
}
V_93 = F_92 ( V_87 , V_95 ) ;
if ( F_10 ( ! V_93 ) ) {
F_93 ( V_16 , V_92 ) ;
F_91 ( V_16 ) ;
return V_99 ;
}
F_94 ( V_16 , V_95 , V_31 ) ;
F_95 ( V_16 ) ;
V_94 = F_96 ( V_87 , V_79 ) ;
if ( F_10 ( ! F_97 ( * V_79 ) ) ) {
F_98 ( V_94 ) ;
F_93 ( V_16 , V_92 ) ;
F_91 ( V_16 ) ;
F_99 ( V_87 , V_93 ) ;
} else {
T_4 V_85 ;
if ( F_100 ( V_81 ) ) {
int V_45 ;
F_98 ( V_94 ) ;
F_93 ( V_16 , V_92 ) ;
F_91 ( V_16 ) ;
F_99 ( V_87 , V_93 ) ;
V_45 = F_101 ( V_81 , V_88 , V_90 ,
V_100 ) ;
F_39 ( V_45 & V_98 ) ;
return V_45 ;
}
V_85 = F_84 ( V_16 , V_81 -> V_101 ) ;
V_85 = F_82 ( F_102 ( V_85 ) , V_81 ) ;
F_103 ( V_16 , V_81 , V_95 ) ;
F_104 ( V_16 , V_92 , false ) ;
F_105 ( V_16 , V_81 ) ;
F_106 ( V_87 , V_79 , V_93 ) ;
F_107 ( V_87 , V_95 , V_79 , V_85 ) ;
F_108 ( V_87 , V_102 , V_31 ) ;
F_109 ( & V_87 -> V_103 ) ;
F_98 ( V_94 ) ;
F_22 ( V_104 ) ;
}
return 0 ;
}
static inline T_6 F_110 ( int V_105 , T_6 V_106 )
{
return ( V_21 & ~ ( V_105 ? 0 : V_107 ) ) | V_106 ;
}
static bool F_111 ( T_7 V_93 , struct V_86 * V_87 ,
struct V_80 * V_81 , unsigned long V_95 , T_4 * V_79 ,
struct V_16 * V_17 )
{
T_4 V_85 ;
if ( ! F_97 ( * V_79 ) )
return false ;
V_85 = F_85 ( V_17 , V_81 -> V_101 ) ;
V_85 = F_86 ( V_85 ) ;
F_106 ( V_87 , V_79 , V_93 ) ;
F_107 ( V_87 , V_95 , V_79 , V_85 ) ;
F_109 ( & V_87 -> V_103 ) ;
return true ;
}
int F_112 ( struct V_86 * V_87 , struct V_80 * V_81 ,
unsigned long V_88 , T_4 * V_79 ,
unsigned int V_90 )
{
T_6 V_89 ;
struct V_16 * V_16 ;
unsigned long V_95 = V_88 & V_96 ;
if ( V_95 < V_81 -> V_108 || V_95 + V_109 > V_81 -> V_110 )
return V_98 ;
if ( F_10 ( F_113 ( V_81 ) ) )
return V_99 ;
if ( F_10 ( F_114 ( V_81 , V_81 -> V_82 ) ) )
return V_99 ;
if ( ! ( V_90 & V_111 ) && ! F_115 ( V_87 ) &&
F_116 () ) {
T_8 * V_94 ;
T_7 V_93 ;
struct V_16 * V_17 ;
bool V_112 ;
int V_45 ;
V_93 = F_92 ( V_87 , V_95 ) ;
if ( F_10 ( ! V_93 ) )
return V_99 ;
V_17 = F_17 () ;
if ( F_10 ( ! V_17 ) ) {
F_99 ( V_87 , V_93 ) ;
F_22 ( V_97 ) ;
return V_98 ;
}
V_94 = F_96 ( V_87 , V_79 ) ;
V_45 = 0 ;
V_112 = false ;
if ( F_97 ( * V_79 ) ) {
if ( F_100 ( V_81 ) ) {
F_98 ( V_94 ) ;
V_45 = F_101 ( V_81 , V_88 , V_90 ,
V_100 ) ;
F_39 ( V_45 & V_98 ) ;
} else {
F_111 ( V_93 , V_87 , V_81 ,
V_95 , V_79 ,
V_17 ) ;
F_98 ( V_94 ) ;
V_112 = true ;
}
} else
F_98 ( V_94 ) ;
if ( ! V_112 ) {
F_99 ( V_87 , V_93 ) ;
F_29 () ;
}
return V_45 ;
}
V_89 = F_110 ( F_117 ( V_81 ) , 0 ) ;
V_16 = F_118 ( V_89 , V_81 , V_95 , V_24 ) ;
if ( F_10 ( ! V_16 ) ) {
F_22 ( V_97 ) ;
return V_98 ;
}
return F_87 ( V_87 , V_81 , V_88 , V_79 , V_16 , V_89 ,
V_90 ) ;
}
static void F_119 ( struct V_80 * V_81 , unsigned long V_113 ,
T_4 * V_79 , unsigned long V_114 , T_5 V_84 , bool V_115 )
{
struct V_86 * V_87 = V_81 -> V_116 ;
T_4 V_85 ;
T_8 * V_94 ;
V_94 = F_96 ( V_87 , V_79 ) ;
if ( F_97 ( * V_79 ) ) {
V_85 = F_86 ( F_120 ( V_114 , V_84 ) ) ;
if ( V_115 ) {
V_85 = F_121 ( F_102 ( V_85 ) ) ;
V_85 = F_82 ( V_85 , V_81 ) ;
}
F_107 ( V_87 , V_113 , V_79 , V_85 ) ;
F_122 ( V_81 , V_113 , V_79 ) ;
}
F_98 ( V_94 ) ;
}
int F_123 ( struct V_80 * V_81 , unsigned long V_113 ,
T_4 * V_79 , unsigned long V_114 , bool V_115 )
{
T_5 V_117 = V_81 -> V_101 ;
F_30 ( ! ( V_81 -> V_82 & ( V_118 | V_119 ) ) ) ;
F_30 ( ( V_81 -> V_82 & ( V_118 | V_119 ) ) ==
( V_118 | V_119 ) ) ;
F_30 ( ( V_81 -> V_82 & V_118 ) && F_124 ( V_81 -> V_82 ) ) ;
F_30 ( ( V_81 -> V_82 & V_119 ) && F_125 ( V_114 ) ) ;
if ( V_113 < V_81 -> V_108 || V_113 >= V_81 -> V_110 )
return V_120 ;
if ( F_126 ( V_81 , & V_117 , V_114 ) )
return V_120 ;
F_119 ( V_81 , V_113 , V_79 , V_114 , V_117 , V_115 ) ;
return V_121 ;
}
int F_127 ( struct V_86 * V_122 , struct V_86 * V_123 ,
T_4 * V_124 , T_4 * V_125 , unsigned long V_113 ,
struct V_80 * V_81 )
{
T_8 * V_126 , * V_127 ;
struct V_16 * V_128 ;
T_4 V_79 ;
T_7 V_93 ;
int V_45 ;
V_45 = - V_66 ;
V_93 = F_92 ( V_122 , V_113 ) ;
if ( F_10 ( ! V_93 ) )
goto V_78;
V_126 = F_96 ( V_122 , V_124 ) ;
V_127 = F_128 ( V_123 , V_125 ) ;
F_129 ( V_127 , V_129 ) ;
V_45 = - V_130 ;
V_79 = * V_125 ;
if ( F_10 ( ! F_130 ( V_79 ) ) ) {
F_99 ( V_122 , V_93 ) ;
goto V_131;
}
if ( F_131 ( V_79 ) ) {
struct V_16 * V_17 ;
V_17 = F_17 () ;
F_111 ( V_93 , V_122 , V_81 , V_113 , V_124 ,
V_17 ) ;
V_45 = 0 ;
goto V_131;
}
if ( F_10 ( F_132 ( V_79 ) ) ) {
F_98 ( V_127 ) ;
F_98 ( V_126 ) ;
F_99 ( V_122 , V_93 ) ;
F_133 ( V_81 -> V_132 , V_125 ) ;
goto V_78;
}
V_128 = F_134 ( V_79 ) ;
F_88 ( ! F_135 ( V_128 ) , V_128 ) ;
F_136 ( V_128 ) ;
F_137 ( V_128 ) ;
F_108 ( V_122 , V_102 , V_31 ) ;
F_138 ( V_123 , V_113 , V_125 ) ;
V_79 = F_139 ( F_140 ( V_79 ) ) ;
F_106 ( V_122 , V_124 , V_93 ) ;
F_107 ( V_122 , V_113 , V_124 , V_79 ) ;
F_109 ( & V_122 -> V_103 ) ;
V_45 = 0 ;
V_131:
F_98 ( V_127 ) ;
F_98 ( V_126 ) ;
V_78:
return V_45 ;
}
void F_141 ( struct V_86 * V_87 ,
struct V_80 * V_81 ,
unsigned long V_88 ,
T_4 * V_79 , T_4 V_133 ,
int V_134 )
{
T_8 * V_94 ;
T_4 V_85 ;
unsigned long V_95 ;
V_94 = F_96 ( V_87 , V_79 ) ;
if ( F_10 ( ! F_142 ( * V_79 , V_133 ) ) )
goto V_135;
V_85 = F_121 ( V_133 ) ;
V_95 = V_88 & V_96 ;
if ( F_143 ( V_81 , V_95 , V_79 , V_85 , V_134 ) )
F_122 ( V_81 , V_88 , V_79 ) ;
V_135:
F_98 ( V_94 ) ;
}
static void F_144 ( struct V_16 * V_16 )
{
if ( F_145 ( V_136 ) ) {
struct V_16 * V_137 = V_16 + V_31 ;
F_146 ( V_31 , & V_16 -> V_138 ) ;
while ( ++ V_16 < V_137 )
F_147 ( V_16 ) ;
} else {
F_136 ( V_16 ) ;
}
}
static void F_148 ( struct V_16 * V_16 )
{
if ( F_145 ( V_136 ) ) {
struct V_16 * V_137 = V_16 + V_31 ;
while ( V_16 < V_137 )
F_91 ( V_16 ++ ) ;
} else {
F_91 ( V_16 ) ;
}
}
static int F_149 ( struct V_86 * V_87 ,
struct V_80 * V_81 ,
unsigned long V_88 ,
T_4 * V_79 , T_4 V_133 ,
struct V_16 * V_16 ,
unsigned long V_95 )
{
struct V_91 * V_92 ;
T_8 * V_94 ;
T_7 V_93 ;
T_4 V_139 ;
int V_45 = 0 , V_140 ;
struct V_16 * * V_58 ;
unsigned long V_141 ;
unsigned long V_142 ;
V_58 = F_150 ( sizeof( struct V_16 * ) * V_31 ,
V_143 ) ;
if ( F_10 ( ! V_58 ) ) {
V_45 |= V_99 ;
goto V_78;
}
for ( V_140 = 0 ; V_140 < V_31 ; V_140 ++ ) {
V_58 [ V_140 ] = F_151 ( V_144 |
V_145 ,
V_81 , V_88 , F_152 ( V_16 ) ) ;
if ( F_10 ( ! V_58 [ V_140 ] ||
F_90 ( V_58 [ V_140 ] , V_87 , V_143 ,
& V_92 ) ) ) {
if ( V_58 [ V_140 ] )
F_91 ( V_58 [ V_140 ] ) ;
while ( -- V_140 >= 0 ) {
V_92 = ( void * ) F_153 ( V_58 [ V_140 ] ) ;
F_154 ( V_58 [ V_140 ] , 0 ) ;
F_93 ( V_58 [ V_140 ] , V_92 ) ;
F_91 ( V_58 [ V_140 ] ) ;
}
F_155 ( V_58 ) ;
V_45 |= V_99 ;
goto V_78;
}
F_154 ( V_58 [ V_140 ] , ( unsigned long ) V_92 ) ;
}
for ( V_140 = 0 ; V_140 < V_31 ; V_140 ++ ) {
F_156 ( V_58 [ V_140 ] , V_16 + V_140 ,
V_95 + V_146 * V_140 , V_81 ) ;
F_95 ( V_58 [ V_140 ] ) ;
F_157 () ;
}
V_141 = V_95 ;
V_142 = V_95 + V_109 ;
F_158 ( V_87 , V_141 , V_142 ) ;
V_94 = F_96 ( V_87 , V_79 ) ;
if ( F_10 ( ! F_142 ( * V_79 , V_133 ) ) )
goto V_147;
F_88 ( ! F_135 ( V_16 ) , V_16 ) ;
F_159 ( V_81 , V_95 , V_79 ) ;
V_93 = F_160 ( V_87 , V_79 ) ;
F_161 ( V_87 , & V_139 , V_93 ) ;
for ( V_140 = 0 ; V_140 < V_31 ; V_140 ++ , V_95 += V_146 ) {
T_9 * V_148 , V_85 ;
V_85 = F_162 ( V_58 [ V_140 ] , V_81 -> V_101 ) ;
V_85 = F_163 ( F_164 ( V_85 ) , V_81 ) ;
V_92 = ( void * ) F_153 ( V_58 [ V_140 ] ) ;
F_154 ( V_58 [ V_140 ] , 0 ) ;
F_103 ( V_58 [ V_140 ] , V_81 , V_95 ) ;
F_104 ( V_58 [ V_140 ] , V_92 , false ) ;
F_105 ( V_58 [ V_140 ] , V_81 ) ;
V_148 = F_165 ( & V_139 , V_95 ) ;
F_39 ( ! F_166 ( * V_148 ) ) ;
F_167 ( V_87 , V_95 , V_148 , V_85 ) ;
F_168 ( V_148 ) ;
}
F_155 ( V_58 ) ;
F_169 () ;
F_161 ( V_87 , V_79 , V_93 ) ;
F_170 ( V_16 ) ;
F_98 ( V_94 ) ;
F_171 ( V_87 , V_141 , V_142 ) ;
V_45 |= V_149 ;
F_91 ( V_16 ) ;
V_78:
return V_45 ;
V_147:
F_98 ( V_94 ) ;
F_171 ( V_87 , V_141 , V_142 ) ;
for ( V_140 = 0 ; V_140 < V_31 ; V_140 ++ ) {
V_92 = ( void * ) F_153 ( V_58 [ V_140 ] ) ;
F_154 ( V_58 [ V_140 ] , 0 ) ;
F_93 ( V_58 [ V_140 ] , V_92 ) ;
F_91 ( V_58 [ V_140 ] ) ;
}
F_155 ( V_58 ) ;
goto V_78;
}
int F_172 ( struct V_86 * V_87 , struct V_80 * V_81 ,
unsigned long V_88 , T_4 * V_79 , T_4 V_133 )
{
T_8 * V_94 ;
int V_45 = 0 ;
struct V_16 * V_16 = NULL , * V_150 ;
struct V_91 * V_92 ;
unsigned long V_95 ;
unsigned long V_141 ;
unsigned long V_142 ;
T_6 V_151 ;
V_94 = F_128 ( V_87 , V_79 ) ;
F_173 ( ! V_81 -> V_132 , V_81 ) ;
V_95 = V_88 & V_96 ;
if ( F_131 ( V_133 ) )
goto V_152;
F_174 ( V_94 ) ;
if ( F_10 ( ! F_142 ( * V_79 , V_133 ) ) )
goto V_131;
V_16 = F_134 ( V_133 ) ;
F_88 ( ! F_89 ( V_16 ) || ! F_135 ( V_16 ) , V_16 ) ;
if ( F_175 ( V_16 ) == 1 ) {
T_4 V_85 ;
V_85 = F_121 ( V_133 ) ;
V_85 = F_82 ( F_102 ( V_85 ) , V_81 ) ;
if ( F_143 ( V_81 , V_95 , V_79 , V_85 , 1 ) )
F_122 ( V_81 , V_88 , V_79 ) ;
V_45 |= V_149 ;
goto V_131;
}
F_144 ( V_16 ) ;
F_98 ( V_94 ) ;
V_152:
if ( F_176 ( V_81 ) &&
! F_177 () ) {
V_151 = F_110 ( F_117 ( V_81 ) , 0 ) ;
V_150 = F_118 ( V_151 , V_81 , V_95 , V_24 ) ;
} else
V_150 = NULL ;
if ( F_10 ( ! V_150 ) ) {
if ( ! V_16 ) {
F_178 ( V_81 , V_88 , V_79 ) ;
V_45 |= V_98 ;
} else {
V_45 = F_149 ( V_87 , V_81 , V_88 ,
V_79 , V_133 , V_16 , V_95 ) ;
if ( V_45 & V_99 ) {
F_179 ( V_16 ) ;
V_45 |= V_98 ;
}
F_148 ( V_16 ) ;
}
F_22 ( V_97 ) ;
goto V_78;
}
if ( F_10 ( F_90 ( V_150 , V_87 , V_151 , & V_92 ) ) ) {
F_91 ( V_150 ) ;
if ( V_16 ) {
F_179 ( V_16 ) ;
F_148 ( V_16 ) ;
} else
F_178 ( V_81 , V_88 , V_79 ) ;
V_45 |= V_98 ;
F_22 ( V_97 ) ;
goto V_78;
}
F_22 ( V_104 ) ;
if ( ! V_16 )
F_94 ( V_150 , V_95 , V_31 ) ;
else
F_180 ( V_150 , V_16 , V_95 , V_81 , V_31 ) ;
F_95 ( V_150 ) ;
V_141 = V_95 ;
V_142 = V_95 + V_109 ;
F_158 ( V_87 , V_141 , V_142 ) ;
F_174 ( V_94 ) ;
if ( V_16 )
F_148 ( V_16 ) ;
if ( F_10 ( ! F_142 ( * V_79 , V_133 ) ) ) {
F_98 ( V_94 ) ;
F_93 ( V_150 , V_92 ) ;
F_91 ( V_150 ) ;
goto V_153;
} else {
T_4 V_85 ;
V_85 = F_84 ( V_150 , V_81 -> V_101 ) ;
V_85 = F_82 ( F_102 ( V_85 ) , V_81 ) ;
F_159 ( V_81 , V_95 , V_79 ) ;
F_103 ( V_150 , V_81 , V_95 ) ;
F_104 ( V_150 , V_92 , false ) ;
F_105 ( V_150 , V_81 ) ;
F_107 ( V_87 , V_95 , V_79 , V_85 ) ;
F_122 ( V_81 , V_88 , V_79 ) ;
if ( ! V_16 ) {
F_108 ( V_87 , V_102 , V_31 ) ;
F_29 () ;
} else {
F_88 ( ! F_135 ( V_16 ) , V_16 ) ;
F_170 ( V_16 ) ;
F_91 ( V_16 ) ;
}
V_45 |= V_149 ;
}
F_98 ( V_94 ) ;
V_153:
F_171 ( V_87 , V_141 , V_142 ) ;
V_78:
return V_45 ;
V_131:
F_98 ( V_94 ) ;
return V_45 ;
}
struct V_16 * F_181 ( struct V_80 * V_81 ,
unsigned long V_113 ,
T_4 * V_79 ,
unsigned int V_90 )
{
struct V_86 * V_87 = V_81 -> V_116 ;
struct V_16 * V_16 = NULL ;
F_182 ( F_128 ( V_87 , V_79 ) ) ;
if ( V_90 & V_154 && ! F_183 ( * V_79 ) )
goto V_78;
if ( ( V_90 & V_155 ) && F_131 ( * V_79 ) )
return F_184 ( - V_156 ) ;
if ( ( V_90 & V_157 ) && F_185 ( * V_79 ) )
goto V_78;
V_16 = F_134 ( * V_79 ) ;
F_88 ( ! F_135 ( V_16 ) , V_16 ) ;
if ( V_90 & V_158 ) {
T_4 V_139 ;
V_139 = F_121 ( F_102 ( * V_79 ) ) ;
if ( F_143 ( V_81 , V_113 & V_96 ,
V_79 , V_139 , 1 ) )
F_122 ( V_81 , V_113 , V_79 ) ;
}
if ( ( V_90 & V_159 ) && ( V_81 -> V_82 & V_160 ) ) {
if ( V_16 -> V_161 && F_186 ( V_16 ) ) {
F_187 () ;
if ( V_16 -> V_161 )
F_188 ( V_16 ) ;
F_189 ( V_16 ) ;
}
}
V_16 += ( V_113 & ~ V_96 ) >> V_6 ;
F_88 ( ! F_89 ( V_16 ) , V_16 ) ;
if ( V_90 & V_162 )
F_190 ( V_16 ) ;
V_78:
return V_16 ;
}
int F_191 ( struct V_86 * V_87 , struct V_80 * V_81 ,
unsigned long V_113 , T_4 V_79 , T_4 * V_163 )
{
T_8 * V_94 ;
struct V_132 * V_132 = NULL ;
struct V_16 * V_16 ;
unsigned long V_95 = V_113 & V_96 ;
int V_164 = - 1 , V_165 = F_192 () ;
int V_166 , V_167 = - 1 ;
bool V_168 ;
bool V_169 = false ;
bool V_170 ;
int V_90 = 0 ;
F_30 ( ! ( V_81 -> V_82 & ( V_171 | V_172 | V_83 ) ) ) ;
V_94 = F_96 ( V_87 , V_163 ) ;
if ( F_10 ( ! F_142 ( V_79 , * V_163 ) ) )
goto V_131;
if ( F_10 ( F_193 ( * V_163 ) ) ) {
V_16 = F_134 ( * V_163 ) ;
F_98 ( V_94 ) ;
F_194 ( V_16 ) ;
goto V_78;
}
V_16 = F_134 ( V_79 ) ;
F_30 ( F_195 ( V_16 ) ) ;
V_164 = F_152 ( V_16 ) ;
V_167 = F_196 ( V_16 ) ;
F_197 ( V_173 ) ;
if ( V_164 == V_165 ) {
F_197 ( V_174 ) ;
V_90 |= V_175 ;
}
if ( ! ( V_81 -> V_82 & V_83 ) )
V_90 |= V_176 ;
V_168 = F_186 ( V_16 ) ;
V_166 = F_198 ( V_16 , V_81 , V_95 ) ;
if ( V_166 == - 1 ) {
if ( V_168 )
goto V_177;
}
if ( ! V_168 ) {
F_98 ( V_94 ) ;
F_194 ( V_16 ) ;
V_164 = - 1 ;
goto V_78;
}
F_136 ( V_16 ) ;
F_98 ( V_94 ) ;
V_132 = F_199 ( V_16 ) ;
F_174 ( V_94 ) ;
if ( F_10 ( ! F_142 ( V_79 , * V_163 ) ) ) {
F_189 ( V_16 ) ;
F_91 ( V_16 ) ;
V_164 = - 1 ;
goto V_131;
}
if ( F_10 ( ! V_132 ) ) {
F_91 ( V_16 ) ;
V_164 = - 1 ;
goto V_177;
}
F_98 ( V_94 ) ;
V_169 = F_200 ( V_87 , V_81 ,
V_163 , V_79 , V_113 , V_16 , V_166 ) ;
if ( V_169 ) {
V_90 |= V_178 ;
V_164 = V_166 ;
} else
V_90 |= V_179 ;
goto V_78;
V_177:
F_30 ( ! F_201 ( V_16 ) ) ;
V_170 = F_183 ( V_79 ) ;
V_79 = F_202 ( V_79 , V_81 -> V_101 ) ;
V_79 = F_121 ( V_79 ) ;
if ( V_170 )
V_79 = F_83 ( V_79 ) ;
F_107 ( V_87 , V_95 , V_163 , V_79 ) ;
F_122 ( V_81 , V_113 , V_163 ) ;
F_189 ( V_16 ) ;
V_131:
F_98 ( V_94 ) ;
V_78:
if ( V_132 )
F_203 ( V_132 ) ;
if ( V_164 != - 1 )
F_204 ( V_167 , V_164 , V_31 , V_90 ) ;
return 0 ;
}
int F_205 ( struct V_180 * V_181 , struct V_80 * V_81 ,
T_4 * V_79 , unsigned long V_113 )
{
T_4 V_133 ;
T_8 * V_94 ;
if ( F_206 ( V_79 , V_81 , & V_94 ) != 1 )
return 0 ;
V_133 = F_207 ( V_181 -> V_87 , V_113 , V_79 ,
V_181 -> V_182 ) ;
F_208 ( V_181 , V_79 , V_113 ) ;
if ( F_209 ( V_81 ) ) {
F_98 ( V_94 ) ;
if ( F_131 ( V_133 ) )
F_29 () ;
} else if ( F_131 ( V_133 ) ) {
F_99 ( V_181 -> V_87 , F_160 ( V_181 -> V_87 , V_79 ) ) ;
F_210 ( & V_181 -> V_87 -> V_103 ) ;
F_98 ( V_94 ) ;
F_29 () ;
} else {
struct V_16 * V_16 = F_134 ( V_133 ) ;
F_170 ( V_16 ) ;
F_88 ( F_175 ( V_16 ) < 0 , V_16 ) ;
F_108 ( V_181 -> V_87 , V_102 , - V_31 ) ;
F_88 ( ! F_135 ( V_16 ) , V_16 ) ;
F_99 ( V_181 -> V_87 , F_160 ( V_181 -> V_87 , V_79 ) ) ;
F_210 ( & V_181 -> V_87 -> V_103 ) ;
F_98 ( V_94 ) ;
F_211 ( V_181 , V_16 ) ;
}
return 1 ;
}
int F_212 ( struct V_80 * V_81 , struct V_80 * V_183 ,
unsigned long V_184 ,
unsigned long V_185 , unsigned long V_186 ,
T_4 * V_187 , T_4 * V_188 )
{
T_8 * V_189 , * V_190 ;
int V_45 = 0 ;
T_4 V_79 ;
struct V_86 * V_87 = V_81 -> V_116 ;
if ( ( V_184 & ~ V_96 ) ||
( V_185 & ~ V_96 ) ||
V_186 - V_184 < V_109 ||
( V_183 -> V_82 & V_191 ) )
goto V_78;
if ( F_213 ( ! F_97 ( * V_188 ) ) ) {
F_39 ( F_130 ( * V_188 ) ) ;
goto V_78;
}
V_45 = F_206 ( V_187 , V_81 , & V_189 ) ;
if ( V_45 == 1 ) {
V_190 = F_128 ( V_87 , V_188 ) ;
if ( V_190 != V_189 )
F_129 ( V_190 , V_129 ) ;
V_79 = F_214 ( V_87 , V_184 , V_187 ) ;
F_39 ( ! F_97 ( * V_188 ) ) ;
if ( F_215 ( V_190 , V_189 ) ) {
T_7 V_93 ;
V_93 = F_160 ( V_87 , V_187 ) ;
F_106 ( V_87 , V_188 , V_93 ) ;
}
F_107 ( V_87 , V_185 , V_188 , F_216 ( V_79 ) ) ;
if ( V_190 != V_189 )
F_98 ( V_190 ) ;
F_98 ( V_189 ) ;
}
V_78:
return V_45 ;
}
int F_217 ( struct V_80 * V_81 , T_4 * V_79 ,
unsigned long V_113 , T_5 V_192 , int V_193 )
{
struct V_86 * V_87 = V_81 -> V_116 ;
T_8 * V_94 ;
int V_45 = 0 ;
if ( F_206 ( V_79 , V_81 , & V_94 ) == 1 ) {
T_4 V_85 ;
bool V_194 = V_193 && F_183 ( * V_79 ) ;
V_45 = 1 ;
if ( V_193 && F_131 ( * V_79 ) ) {
F_98 ( V_94 ) ;
return V_45 ;
}
if ( ! V_193 || ! F_185 ( * V_79 ) ) {
V_85 = F_218 ( V_87 , V_113 , V_79 ) ;
V_85 = F_202 ( V_85 , V_192 ) ;
if ( V_194 )
V_85 = F_83 ( V_85 ) ;
V_45 = V_31 ;
F_107 ( V_87 , V_113 , V_79 , V_85 ) ;
F_30 ( ! V_194 && F_183 ( V_85 ) ) ;
}
F_98 ( V_94 ) ;
}
return V_45 ;
}
int F_206 ( T_4 * V_79 , struct V_80 * V_81 ,
T_8 * * V_94 )
{
* V_94 = F_96 ( V_81 -> V_116 , V_79 ) ;
if ( F_18 ( F_130 ( * V_79 ) ) ) {
if ( F_10 ( F_132 ( * V_79 ) ) ) {
F_98 ( * V_94 ) ;
F_133 ( V_81 -> V_132 , V_79 ) ;
return - 1 ;
} else {
return 1 ;
}
}
F_98 ( * V_94 ) ;
return 0 ;
}
T_4 * F_219 ( struct V_16 * V_16 ,
struct V_86 * V_87 ,
unsigned long V_88 ,
enum V_195 V_47 ,
T_8 * * V_94 )
{
T_10 * V_196 ;
T_11 * V_197 ;
T_4 * V_79 ;
if ( V_88 & ~ V_96 )
return NULL ;
V_196 = F_220 ( V_87 , V_88 ) ;
if ( ! F_221 ( * V_196 ) )
return NULL ;
V_197 = F_222 ( V_196 , V_88 ) ;
if ( ! F_223 ( * V_197 ) )
return NULL ;
V_79 = F_224 ( V_197 , V_88 ) ;
* V_94 = F_96 ( V_87 , V_79 ) ;
if ( ! F_225 ( * V_79 ) )
goto V_135;
if ( F_134 ( * V_79 ) != V_16 )
goto V_135;
if ( V_47 == V_198 &&
F_132 ( * V_79 ) )
goto V_135;
if ( F_130 ( * V_79 ) ) {
F_39 ( V_47 == V_199 &&
! F_132 ( * V_79 ) ) ;
return V_79 ;
}
V_135:
F_98 ( * V_94 ) ;
return NULL ;
}
static int F_226 ( struct V_16 * V_16 ,
struct V_80 * V_81 ,
unsigned long V_88 )
{
struct V_86 * V_87 = V_81 -> V_116 ;
T_8 * V_94 ;
T_4 * V_79 ;
int V_45 = 0 ;
const unsigned long V_141 = V_88 ;
const unsigned long V_142 = V_88 + V_109 ;
F_158 ( V_87 , V_141 , V_142 ) ;
V_79 = F_219 ( V_16 , V_87 , V_88 ,
V_198 , & V_94 ) ;
if ( V_79 ) {
F_227 ( V_81 , V_88 , V_79 ) ;
V_45 = 1 ;
F_98 ( V_94 ) ;
}
F_171 ( V_87 , V_141 , V_142 ) ;
return V_45 ;
}
static void F_228 ( struct V_16 * V_16 ,
struct V_200 * V_201 )
{
int V_140 ;
struct V_1 * V_1 = F_229 ( V_16 ) ;
struct V_202 * V_202 ;
int V_203 = 0 ;
F_230 ( & V_1 -> V_204 ) ;
V_202 = F_231 ( V_16 , V_1 ) ;
F_232 ( V_16 ) ;
F_233 ( V_16 ) ;
for ( V_140 = V_31 - 1 ; V_140 >= 1 ; V_140 -- ) {
struct V_16 * V_205 = V_16 + V_140 ;
F_30 ( F_175 ( V_205 ) < 0 ) ;
V_203 += F_175 ( V_205 ) ;
F_30 ( V_203 < 0 ) ;
F_30 ( F_33 ( & V_205 -> V_138 ) != 0 ) ;
F_146 ( F_175 ( V_16 ) + F_175 ( V_205 ) + 1 ,
& V_205 -> V_138 ) ;
F_234 () ;
V_205 -> V_90 &= ~ V_206 ;
V_205 -> V_90 |= ( V_16 -> V_90 &
( ( 1L << V_207 ) |
( 1L << V_208 ) |
( 1L << V_209 ) |
( 1L << V_210 ) |
( 1L << V_211 ) |
( 1L << V_212 ) ) ) ;
V_205 -> V_90 |= ( 1L << V_213 ) ;
F_169 () ;
if ( F_235 ( V_16 ) )
F_236 ( V_205 ) ;
if ( F_237 ( V_16 ) )
F_238 ( V_205 ) ;
V_205 -> V_214 = V_16 -> V_214 ;
F_30 ( V_205 -> V_161 ) ;
V_205 -> V_161 = V_16 -> V_161 ;
V_205 -> V_215 = V_16 -> V_215 + V_140 ;
F_239 ( V_205 , F_196 ( V_16 ) ) ;
F_30 ( ! F_240 ( V_205 ) ) ;
F_30 ( ! F_241 ( V_205 ) ) ;
F_30 ( ! F_242 ( V_205 ) ) ;
F_30 ( ! F_243 ( V_205 ) ) ;
F_244 ( V_16 , V_205 , V_202 , V_201 ) ;
}
F_245 ( V_203 , & V_16 -> V_138 ) ;
F_30 ( F_33 ( & V_16 -> V_138 ) <= 0 ) ;
F_246 ( V_1 , V_216 , - 1 ) ;
F_247 ( V_16 ) ;
F_248 ( V_16 ) ;
F_249 ( & V_1 -> V_204 ) ;
for ( V_140 = 1 ; V_140 < V_31 ; V_140 ++ ) {
struct V_16 * V_205 = V_16 + V_140 ;
F_30 ( F_250 ( V_205 ) <= 0 ) ;
F_91 ( V_205 ) ;
}
F_30 ( F_250 ( V_16 ) <= 0 ) ;
}
static int F_251 ( struct V_16 * V_16 ,
struct V_80 * V_81 ,
unsigned long V_88 )
{
struct V_86 * V_87 = V_81 -> V_116 ;
T_8 * V_94 ;
T_4 * V_79 , V_139 ;
int V_45 = 0 , V_140 ;
T_7 V_93 ;
unsigned long V_95 ;
V_79 = F_219 ( V_16 , V_87 , V_88 ,
V_199 , & V_94 ) ;
if ( V_79 ) {
V_93 = F_160 ( V_87 , V_79 ) ;
F_161 ( V_87 , & V_139 , V_93 ) ;
if ( F_183 ( * V_79 ) )
F_30 ( F_175 ( V_16 ) != 1 ) ;
V_95 = V_88 ;
for ( V_140 = 0 ; V_140 < V_31 ; V_140 ++ , V_95 += V_146 ) {
T_9 * V_148 , V_85 ;
F_30 ( F_89 ( V_16 + V_140 ) ) ;
V_85 = F_162 ( V_16 + V_140 , V_81 -> V_101 ) ;
V_85 = F_163 ( F_164 ( V_85 ) , V_81 ) ;
if ( ! F_183 ( * V_79 ) )
V_85 = F_252 ( V_85 ) ;
if ( ! F_253 ( * V_79 ) )
V_85 = F_254 ( V_85 ) ;
V_148 = F_165 ( & V_139 , V_95 ) ;
F_30 ( ! F_166 ( * V_148 ) ) ;
F_167 ( V_87 , V_95 , V_148 , V_85 ) ;
F_168 ( V_148 ) ;
}
F_169 () ;
F_255 ( V_81 , V_88 , V_79 ) ;
F_161 ( V_87 , V_79 , V_93 ) ;
V_45 = 1 ;
F_98 ( V_94 ) ;
}
return V_45 ;
}
static void F_256 ( struct V_16 * V_16 ,
struct V_132 * V_132 ,
struct V_200 * V_201 )
{
int V_217 , V_218 ;
T_12 V_219 = V_16 -> V_215 << ( V_220 - V_6 ) ;
struct V_221 * V_222 ;
F_30 ( ! F_135 ( V_16 ) ) ;
F_30 ( F_257 ( V_16 ) ) ;
V_217 = 0 ;
F_258 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_80 * V_81 = V_222 -> V_81 ;
unsigned long V_113 = F_259 ( V_16 , V_81 ) ;
F_30 ( F_260 ( V_81 ) ) ;
V_217 += F_226 ( V_16 , V_81 , V_113 ) ;
}
if ( V_217 != F_175 ( V_16 ) ) {
F_12 ( L_17 ,
V_217 , F_175 ( V_16 ) ) ;
F_261 () ;
}
F_228 ( V_16 , V_201 ) ;
V_218 = 0 ;
F_258 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_80 * V_81 = V_222 -> V_81 ;
unsigned long V_113 = F_259 ( V_16 , V_81 ) ;
F_30 ( F_260 ( V_81 ) ) ;
V_218 += F_251 ( V_16 , V_81 , V_113 ) ;
}
if ( V_217 != V_218 ) {
F_12 ( L_18 ,
V_217 , V_218 , F_175 ( V_16 ) ) ;
F_261 () ;
}
}
int F_262 ( struct V_16 * V_16 , struct V_200 * V_201 )
{
struct V_132 * V_132 ;
int V_45 = 1 ;
F_30 ( F_195 ( V_16 ) ) ;
F_30 ( ! F_240 ( V_16 ) ) ;
V_132 = F_263 ( V_16 ) ;
if ( ! V_132 )
goto V_78;
F_264 ( V_132 ) ;
V_45 = 0 ;
if ( ! F_89 ( V_16 ) )
goto V_131;
F_30 ( ! F_243 ( V_16 ) ) ;
F_256 ( V_16 , V_132 , V_201 ) ;
F_22 ( V_223 ) ;
F_30 ( F_89 ( V_16 ) ) ;
V_131:
F_265 ( V_132 ) ;
F_266 ( V_132 ) ;
V_78:
return V_45 ;
}
int F_267 ( struct V_80 * V_81 ,
unsigned long * V_82 , int V_224 )
{
switch ( V_224 ) {
case V_225 :
#ifdef F_268
if ( F_269 ( V_81 -> V_116 ) )
return 0 ;
#endif
if ( * V_82 & ( V_226 | V_227 ) )
return - V_42 ;
* V_82 &= ~ V_191 ;
* V_82 |= V_226 ;
if ( F_10 ( F_270 ( V_81 , * V_82 ) ) )
return - V_66 ;
break;
case V_228 :
if ( * V_82 & ( V_191 | V_227 ) )
return - V_42 ;
* V_82 &= ~ V_226 ;
* V_82 |= V_191 ;
break;
}
return 0 ;
}
static int T_3 F_76 ( void )
{
V_229 = F_271 ( L_19 ,
sizeof( struct V_230 ) ,
F_272 ( struct V_230 ) , 0 , NULL ) ;
if ( ! V_229 )
return - V_66 ;
return 0 ;
}
static void T_3 F_79 ( void )
{
F_273 ( V_229 ) ;
}
static inline struct V_230 * F_274 ( void )
{
if ( ! V_229 )
return NULL ;
return F_275 ( V_229 , V_143 ) ;
}
static inline void F_276 ( struct V_230 * V_230 )
{
F_277 ( V_229 , V_230 ) ;
}
static struct V_230 * F_278 ( struct V_86 * V_87 )
{
struct V_230 * V_230 ;
F_279 (mm_slots_hash, mm_slot, hash, (unsigned long)mm)
if ( V_87 == V_230 -> V_87 )
return V_230 ;
return NULL ;
}
static void F_280 ( struct V_86 * V_87 ,
struct V_230 * V_230 )
{
V_230 -> V_87 = V_87 ;
F_281 ( V_231 , & V_230 -> V_232 , ( long ) V_87 ) ;
}
static inline int F_282 ( struct V_86 * V_87 )
{
return F_33 ( & V_87 -> V_233 ) == 0 ;
}
int F_283 ( struct V_86 * V_87 )
{
struct V_230 * V_230 ;
int V_234 ;
V_230 = F_274 () ;
if ( ! V_230 )
return - V_66 ;
F_284 ( F_282 ( V_87 ) , V_87 ) ;
if ( F_10 ( F_285 ( V_235 , & V_87 -> V_90 ) ) ) {
F_276 ( V_230 ) ;
return 0 ;
}
F_174 ( & V_236 ) ;
F_280 ( V_87 , V_230 ) ;
V_234 = F_14 ( & V_13 . V_14 ) ;
F_286 ( & V_230 -> V_237 , & V_13 . V_14 ) ;
F_98 ( & V_236 ) ;
F_287 ( & V_87 -> V_238 ) ;
if ( V_234 )
F_15 ( & V_15 ) ;
return 0 ;
}
int F_270 ( struct V_80 * V_81 ,
unsigned long V_82 )
{
unsigned long V_239 , V_240 ;
if ( ! V_81 -> V_132 )
return 0 ;
if ( V_81 -> V_241 )
return 0 ;
F_173 ( V_82 & V_227 , V_81 ) ;
V_239 = ( V_81 -> V_108 + ~ V_96 ) & V_96 ;
V_240 = V_81 -> V_110 & V_96 ;
if ( V_239 < V_240 )
return F_114 ( V_81 , V_82 ) ;
return 0 ;
}
void F_288 ( struct V_86 * V_87 )
{
struct V_230 * V_230 ;
int free = 0 ;
F_174 ( & V_236 ) ;
V_230 = F_278 ( V_87 ) ;
if ( V_230 && V_13 . V_230 != V_230 ) {
F_289 ( & V_230 -> V_232 ) ;
F_290 ( & V_230 -> V_237 ) ;
free = 1 ;
}
F_98 ( & V_236 ) ;
if ( free ) {
F_42 ( V_235 , & V_87 -> V_90 ) ;
F_276 ( V_230 ) ;
F_291 ( V_87 ) ;
} else if ( V_230 ) {
F_292 ( & V_87 -> V_242 ) ;
F_293 ( & V_87 -> V_242 ) ;
}
}
static void F_294 ( struct V_16 * V_16 )
{
F_295 ( V_16 , V_243 + 0 ) ;
F_189 ( V_16 ) ;
F_296 ( V_16 ) ;
}
static void F_297 ( T_9 * V_148 , T_9 * V_244 )
{
while ( -- V_244 >= V_148 ) {
T_9 V_245 = * V_244 ;
if ( ! F_166 ( V_245 ) && ! F_298 ( F_299 ( V_245 ) ) )
F_294 ( F_300 ( V_245 ) ) ;
}
}
static int F_301 ( struct V_80 * V_81 ,
unsigned long V_88 ,
T_9 * V_148 )
{
struct V_16 * V_16 ;
T_9 * V_244 ;
int V_246 = 0 ;
bool V_247 = false , V_248 = false ;
for ( V_244 = V_148 ; V_244 < V_148 + V_31 ;
V_244 ++ , V_88 += V_146 ) {
T_9 V_245 = * V_244 ;
if ( F_166 ( V_245 ) || ( F_302 ( V_245 ) &&
F_298 ( F_299 ( V_245 ) ) ) ) {
if ( ! F_303 ( V_81 ) &&
++ V_246 <= V_62 )
continue;
else
goto V_78;
}
if ( ! F_302 ( V_245 ) )
goto V_78;
V_16 = F_304 ( V_81 , V_88 , V_245 ) ;
if ( F_10 ( ! V_16 ) )
goto V_78;
F_88 ( F_89 ( V_16 ) , V_16 ) ;
F_88 ( ! F_240 ( V_16 ) , V_16 ) ;
F_88 ( ! F_243 ( V_16 ) , V_16 ) ;
if ( ! F_186 ( V_16 ) )
goto V_78;
if ( F_250 ( V_16 ) != 1 + ! ! F_305 ( V_16 ) ) {
F_189 ( V_16 ) ;
goto V_78;
}
if ( F_306 ( V_245 ) ) {
V_248 = true ;
} else {
if ( F_305 ( V_16 ) && ! F_307 ( V_16 ) ) {
F_189 ( V_16 ) ;
goto V_78;
}
}
if ( F_308 ( V_16 ) ) {
F_189 ( V_16 ) ;
goto V_78;
}
F_309 ( V_16 , V_243 + 0 ) ;
F_88 ( ! F_201 ( V_16 ) , V_16 ) ;
F_88 ( F_310 ( V_16 ) , V_16 ) ;
if ( F_311 ( V_245 ) ||
F_235 ( V_16 ) || F_312 ( V_16 ) ||
F_313 ( V_81 -> V_116 , V_88 ) )
V_247 = true ;
}
if ( F_18 ( V_247 && V_248 ) )
return 1 ;
V_78:
F_297 ( V_148 , V_244 ) ;
return 0 ;
}
static void F_314 ( T_9 * V_148 , struct V_16 * V_16 ,
struct V_80 * V_81 ,
unsigned long V_88 ,
T_8 * V_94 )
{
T_9 * V_244 ;
for ( V_244 = V_148 ; V_244 < V_148 + V_31 ; V_244 ++ ) {
T_9 V_245 = * V_244 ;
struct V_16 * V_128 ;
if ( F_166 ( V_245 ) || F_298 ( F_299 ( V_245 ) ) ) {
F_315 ( V_16 , V_88 ) ;
F_108 ( V_81 -> V_116 , V_102 , 1 ) ;
if ( F_298 ( F_299 ( V_245 ) ) ) {
F_174 ( V_94 ) ;
F_316 ( V_81 -> V_116 , V_88 , V_244 ) ;
F_98 ( V_94 ) ;
}
} else {
V_128 = F_300 ( V_245 ) ;
F_156 ( V_16 , V_128 , V_88 , V_81 ) ;
F_88 ( F_175 ( V_128 ) != 1 , V_128 ) ;
F_294 ( V_128 ) ;
F_174 ( V_94 ) ;
F_316 ( V_81 -> V_116 , V_88 , V_244 ) ;
F_170 ( V_128 ) ;
F_98 ( V_94 ) ;
F_317 ( V_128 ) ;
}
V_88 += V_146 ;
V_16 ++ ;
}
}
static void F_318 ( void )
{
F_319 ( V_249 ) ;
F_320 ( & V_15 , & V_249 ) ;
F_321 (
F_322 ( V_56 ) ) ;
F_323 ( & V_15 , & V_249 ) ;
}
static bool F_324 ( int V_250 )
{
int V_140 ;
if ( ! V_251 )
return false ;
if ( V_252 [ V_250 ] )
return false ;
for ( V_140 = 0 ; V_140 < V_253 ; V_140 ++ ) {
if ( ! V_252 [ V_140 ] )
continue;
if ( F_325 ( V_250 , V_140 ) > V_254 )
return true ;
}
return false ;
}
static int F_326 ( void )
{
static int V_255 = V_256 ;
int V_250 , V_257 = 0 , V_258 = 0 ;
for ( V_250 = 0 ; V_250 < V_253 ; V_250 ++ )
if ( V_252 [ V_250 ] > V_258 ) {
V_258 = V_252 [ V_250 ] ;
V_257 = V_250 ;
}
if ( V_257 <= V_255 )
for ( V_250 = V_255 + 1 ; V_250 < V_253 ;
V_250 ++ )
if ( V_258 == V_252 [ V_250 ] ) {
V_257 = V_250 ;
break;
}
V_255 = V_257 ;
return V_257 ;
}
static bool F_327 ( struct V_16 * * V_259 , bool * V_249 )
{
if ( F_11 ( * V_259 ) ) {
if ( ! * V_249 )
return false ;
* V_249 = false ;
* V_259 = NULL ;
F_318 () ;
} else if ( * V_259 ) {
F_91 ( * V_259 ) ;
* V_259 = NULL ;
}
return true ;
}
static struct V_16 *
F_328 ( struct V_16 * * V_259 , T_6 V_89 , struct V_86 * V_87 ,
struct V_80 * V_81 , unsigned long V_88 ,
int V_260 )
{
F_88 ( * V_259 , * V_259 ) ;
F_329 ( & V_87 -> V_242 ) ;
* V_259 = F_330 ( V_260 , V_89 , V_24 ) ;
if ( F_10 ( ! * V_259 ) ) {
F_22 ( V_261 ) ;
* V_259 = F_184 ( - V_66 ) ;
return NULL ;
}
F_22 ( V_262 ) ;
return * V_259 ;
}
static int F_326 ( void )
{
return 0 ;
}
static inline struct V_16 * F_331 ( int V_105 )
{
return F_21 ( F_110 ( V_105 , 0 ) ,
V_24 ) ;
}
static struct V_16 * F_332 ( bool * V_249 )
{
struct V_16 * V_259 ;
do {
V_259 = F_331 ( F_333 () ) ;
if ( ! V_259 ) {
F_22 ( V_261 ) ;
if ( ! * V_249 )
return NULL ;
* V_249 = false ;
F_318 () ;
} else
F_22 ( V_262 ) ;
} while ( F_10 ( ! V_259 ) && F_18 ( F_8 () ) );
return V_259 ;
}
static bool F_327 ( struct V_16 * * V_259 , bool * V_249 )
{
if ( ! * V_259 )
* V_259 = F_332 ( V_249 ) ;
if ( F_10 ( ! * V_259 ) )
return false ;
return true ;
}
static struct V_16 *
F_328 ( struct V_16 * * V_259 , T_6 V_89 , struct V_86 * V_87 ,
struct V_80 * V_81 , unsigned long V_88 ,
int V_260 )
{
F_329 ( & V_87 -> V_242 ) ;
F_39 ( ! * V_259 ) ;
return * V_259 ;
}
static bool F_334 ( struct V_80 * V_81 )
{
if ( ( ! ( V_81 -> V_82 & V_226 ) && ! F_335 () ) ||
( V_81 -> V_82 & V_191 ) )
return false ;
if ( ! V_81 -> V_132 || V_81 -> V_241 )
return false ;
if ( F_260 ( V_81 ) )
return false ;
F_173 ( V_81 -> V_82 & V_227 , V_81 ) ;
return true ;
}
static void F_336 ( struct V_86 * V_87 ,
unsigned long V_88 ,
struct V_16 * * V_259 ,
struct V_80 * V_81 ,
int V_260 )
{
T_4 * V_79 , V_139 ;
T_9 * V_148 ;
T_7 V_93 ;
struct V_16 * V_150 ;
T_8 * V_263 , * V_264 ;
int V_265 ;
unsigned long V_239 , V_240 ;
struct V_91 * V_92 ;
unsigned long V_141 ;
unsigned long V_142 ;
T_6 V_89 ;
F_39 ( V_88 & ~ V_96 ) ;
V_89 = F_110 ( F_333 () , V_145 ) |
V_266 ;
V_150 = F_328 ( V_259 , V_89 , V_87 , V_81 , V_88 , V_260 ) ;
if ( ! V_150 )
return;
if ( F_10 ( F_90 ( V_150 , V_87 ,
V_89 , & V_92 ) ) )
return;
F_292 ( & V_87 -> V_242 ) ;
if ( F_10 ( F_282 ( V_87 ) ) )
goto V_78;
V_81 = F_337 ( V_87 , V_88 ) ;
if ( ! V_81 )
goto V_78;
V_239 = ( V_81 -> V_108 + ~ V_96 ) & V_96 ;
V_240 = V_81 -> V_110 & V_96 ;
if ( V_88 < V_239 || V_88 + V_109 > V_240 )
goto V_78;
if ( ! F_334 ( V_81 ) )
goto V_78;
V_79 = F_338 ( V_87 , V_88 ) ;
if ( ! V_79 )
goto V_78;
F_264 ( V_81 -> V_132 ) ;
V_148 = F_165 ( V_79 , V_88 ) ;
V_264 = F_339 ( V_87 , V_79 ) ;
V_141 = V_88 ;
V_142 = V_88 + V_109 ;
F_158 ( V_87 , V_141 , V_142 ) ;
V_263 = F_96 ( V_87 , V_79 ) ;
V_139 = F_340 ( V_81 , V_88 , V_79 ) ;
F_98 ( V_263 ) ;
F_171 ( V_87 , V_141 , V_142 ) ;
F_174 ( V_264 ) ;
V_265 = F_301 ( V_81 , V_88 , V_148 ) ;
F_98 ( V_264 ) ;
if ( F_10 ( ! V_265 ) ) {
F_168 ( V_148 ) ;
F_174 ( V_263 ) ;
F_30 ( ! F_97 ( * V_79 ) ) ;
F_161 ( V_87 , V_79 , F_341 ( V_139 ) ) ;
F_98 ( V_263 ) ;
F_265 ( V_81 -> V_132 ) ;
goto V_78;
}
F_265 ( V_81 -> V_132 ) ;
F_314 ( V_148 , V_150 , V_81 , V_88 , V_264 ) ;
F_168 ( V_148 ) ;
F_95 ( V_150 ) ;
V_93 = F_341 ( V_139 ) ;
V_139 = F_84 ( V_150 , V_81 -> V_101 ) ;
V_139 = F_82 ( F_102 ( V_139 ) , V_81 ) ;
F_169 () ;
F_174 ( V_263 ) ;
F_30 ( ! F_97 ( * V_79 ) ) ;
F_103 ( V_150 , V_81 , V_88 ) ;
F_104 ( V_150 , V_92 , false ) ;
F_105 ( V_150 , V_81 ) ;
F_106 ( V_87 , V_79 , V_93 ) ;
F_107 ( V_87 , V_88 , V_79 , V_139 ) ;
F_122 ( V_81 , V_88 , V_79 ) ;
F_98 ( V_263 ) ;
* V_259 = NULL ;
V_59 ++ ;
V_267:
F_293 ( & V_87 -> V_242 ) ;
return;
V_78:
F_93 ( V_150 , V_92 ) ;
goto V_267;
}
static int F_342 ( struct V_86 * V_87 ,
struct V_80 * V_81 ,
unsigned long V_88 ,
struct V_16 * * V_259 )
{
T_4 * V_79 ;
T_9 * V_148 , * V_244 ;
int V_45 = 0 , V_246 = 0 ;
struct V_16 * V_16 ;
unsigned long V_268 ;
T_8 * V_94 ;
int V_260 = V_256 ;
bool V_248 = false , V_247 = false ;
F_39 ( V_88 & ~ V_96 ) ;
V_79 = F_338 ( V_87 , V_88 ) ;
if ( ! V_79 )
goto V_78;
memset ( V_252 , 0 , sizeof( V_252 ) ) ;
V_148 = F_343 ( V_87 , V_79 , V_88 , & V_94 ) ;
for ( V_268 = V_88 , V_244 = V_148 ; V_244 < V_148 + V_31 ;
V_244 ++ , V_268 += V_146 ) {
T_9 V_245 = * V_244 ;
if ( F_166 ( V_245 ) || F_298 ( F_299 ( V_245 ) ) ) {
if ( ! F_303 ( V_81 ) &&
++ V_246 <= V_62 )
continue;
else
goto V_269;
}
if ( ! F_302 ( V_245 ) )
goto V_269;
if ( F_306 ( V_245 ) )
V_248 = true ;
V_16 = F_304 ( V_81 , V_268 , V_245 ) ;
if ( F_10 ( ! V_16 ) )
goto V_269;
V_260 = F_152 ( V_16 ) ;
if ( F_324 ( V_260 ) )
goto V_269;
V_252 [ V_260 ] ++ ;
F_88 ( F_89 ( V_16 ) , V_16 ) ;
if ( ! F_310 ( V_16 ) || F_201 ( V_16 ) || ! F_240 ( V_16 ) )
goto V_269;
if ( F_250 ( V_16 ) != 1 + ! ! F_305 ( V_16 ) )
goto V_269;
if ( F_311 ( V_245 ) ||
F_235 ( V_16 ) || F_312 ( V_16 ) ||
F_313 ( V_81 -> V_116 , V_88 ) )
V_247 = true ;
}
if ( V_247 && V_248 )
V_45 = 1 ;
V_269:
F_344 ( V_148 , V_94 ) ;
if ( V_45 ) {
V_260 = F_326 () ;
F_336 ( V_87 , V_88 , V_259 , V_81 , V_260 ) ;
}
V_78:
return V_45 ;
}
static void F_345 ( struct V_230 * V_230 )
{
struct V_86 * V_87 = V_230 -> V_87 ;
F_39 ( V_270 != 1 && ! F_346 ( & V_236 ) ) ;
if ( F_282 ( V_87 ) ) {
F_289 ( & V_230 -> V_232 ) ;
F_290 ( & V_230 -> V_237 ) ;
F_276 ( V_230 ) ;
F_291 ( V_87 ) ;
}
}
static unsigned int F_347 ( unsigned int V_58 ,
struct V_16 * * V_259 )
__releases( &khugepaged_mm_lock
static int F_348 ( void )
{
return ! F_14 ( & V_13 . V_14 ) &&
F_8 () ;
}
static int F_349 ( void )
{
return ! F_14 ( & V_13 . V_14 ) ||
F_350 () ;
}
static void F_351 ( void )
{
struct V_16 * V_259 = NULL ;
unsigned int V_271 = 0 , V_272 = 0 ;
unsigned int V_58 = V_57 ;
bool V_249 = true ;
F_352 () ;
while ( V_271 < V_58 ) {
if ( ! F_327 ( & V_259 , & V_249 ) )
break;
F_157 () ;
if ( F_10 ( F_350 () || F_353 () ) )
break;
F_174 ( & V_236 ) ;
if ( ! V_13 . V_230 )
V_272 ++ ;
if ( F_348 () &&
V_272 < 2 )
V_271 += F_347 ( V_58 - V_271 ,
& V_259 ) ;
else
V_271 = V_58 ;
F_98 ( & V_236 ) ;
}
if ( ! F_354 ( V_259 ) )
F_91 ( V_259 ) ;
}
static void F_355 ( void )
{
if ( F_348 () ) {
if ( ! V_53 )
return;
F_356 ( V_15 ,
F_350 () ,
F_322 ( V_53 ) ) ;
return;
}
if ( F_8 () )
F_357 ( V_15 , F_349 () ) ;
}
static int V_11 ( void * V_273 )
{
struct V_230 * V_230 ;
F_358 () ;
F_359 ( V_274 , V_275 ) ;
while ( ! F_350 () ) {
F_351 () ;
F_355 () ;
}
F_174 ( & V_236 ) ;
V_230 = V_13 . V_230 ;
V_13 . V_230 = NULL ;
if ( V_230 )
F_345 ( V_230 ) ;
F_98 ( & V_236 ) ;
return 0 ;
}
static void F_360 ( struct V_80 * V_81 ,
unsigned long V_95 , T_4 * V_79 )
{
struct V_86 * V_87 = V_81 -> V_116 ;
T_7 V_93 ;
T_4 V_139 ;
int V_140 ;
F_159 ( V_81 , V_95 , V_79 ) ;
V_93 = F_160 ( V_87 , V_79 ) ;
F_161 ( V_87 , & V_139 , V_93 ) ;
for ( V_140 = 0 ; V_140 < V_31 ; V_140 ++ , V_95 += V_146 ) {
T_9 * V_148 , V_85 ;
V_85 = F_361 ( F_362 ( V_95 ) , V_81 -> V_101 ) ;
V_85 = F_363 ( V_85 ) ;
V_148 = F_165 ( & V_139 , V_95 ) ;
F_39 ( ! F_166 ( * V_148 ) ) ;
F_167 ( V_87 , V_95 , V_148 , V_85 ) ;
F_168 ( V_148 ) ;
}
F_169 () ;
F_161 ( V_87 , V_79 , V_93 ) ;
F_29 () ;
}
void F_364 ( struct V_80 * V_81 , unsigned long V_88 ,
T_4 * V_79 )
{
T_8 * V_94 ;
struct V_16 * V_16 = NULL ;
struct V_86 * V_87 = V_81 -> V_116 ;
unsigned long V_95 = V_88 & V_96 ;
unsigned long V_141 ;
unsigned long V_142 ;
F_30 ( V_81 -> V_108 > V_95 || V_81 -> V_110 < V_95 + V_109 ) ;
V_141 = V_95 ;
V_142 = V_95 + V_109 ;
V_276:
F_158 ( V_87 , V_141 , V_142 ) ;
V_94 = F_96 ( V_87 , V_79 ) ;
if ( F_10 ( ! F_130 ( * V_79 ) ) )
goto V_135;
if ( F_209 ( V_81 ) ) {
T_4 V_139 = F_159 ( V_81 , V_95 , V_79 ) ;
if ( F_131 ( V_139 ) )
F_29 () ;
} else if ( F_131 ( * V_79 ) ) {
F_360 ( V_81 , V_95 , V_79 ) ;
} else {
V_16 = F_134 ( * V_79 ) ;
F_88 ( ! F_250 ( V_16 ) , V_16 ) ;
F_136 ( V_16 ) ;
}
V_135:
F_98 ( V_94 ) ;
F_171 ( V_87 , V_141 , V_142 ) ;
if ( ! V_16 )
return;
F_179 ( V_16 ) ;
F_91 ( V_16 ) ;
if ( F_10 ( F_130 ( * V_79 ) ) )
goto V_276;
}
void F_365 ( struct V_86 * V_87 , unsigned long V_88 ,
T_4 * V_79 )
{
struct V_80 * V_81 ;
V_81 = F_337 ( V_87 , V_88 ) ;
F_30 ( V_81 == NULL ) ;
F_178 ( V_81 , V_88 , V_79 ) ;
}
static void F_366 ( struct V_86 * V_87 ,
unsigned long V_88 )
{
T_10 * V_196 ;
T_11 * V_197 ;
T_4 * V_79 ;
F_39 ( ! ( V_88 & ~ V_96 ) ) ;
V_196 = F_220 ( V_87 , V_88 ) ;
if ( ! F_221 ( * V_196 ) )
return;
V_197 = F_222 ( V_196 , V_88 ) ;
if ( ! F_223 ( * V_197 ) )
return;
V_79 = F_224 ( V_197 , V_88 ) ;
if ( ! F_225 ( * V_79 ) )
return;
F_365 ( V_87 , V_88 , V_79 ) ;
}
void F_367 ( struct V_80 * V_81 ,
unsigned long V_277 ,
unsigned long V_278 ,
long V_279 )
{
if ( V_277 & ~ V_96 &&
( V_277 & V_96 ) >= V_81 -> V_108 &&
( V_277 & V_96 ) + V_109 <= V_81 -> V_110 )
F_366 ( V_81 -> V_116 , V_277 ) ;
if ( V_278 & ~ V_96 &&
( V_278 & V_96 ) >= V_81 -> V_108 &&
( V_278 & V_96 ) + V_109 <= V_81 -> V_110 )
F_366 ( V_81 -> V_116 , V_278 ) ;
if ( V_279 > 0 ) {
struct V_80 * V_280 = V_81 -> V_281 ;
unsigned long V_282 = V_280 -> V_108 ;
V_282 += V_279 << V_6 ;
if ( V_282 & ~ V_96 &&
( V_282 & V_96 ) >= V_280 -> V_108 &&
( V_282 & V_96 ) + V_109 <= V_280 -> V_110 )
F_366 ( V_280 -> V_116 , V_282 ) ;
}
}
