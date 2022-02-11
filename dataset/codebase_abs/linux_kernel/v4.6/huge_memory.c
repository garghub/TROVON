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
F_5 ( L_1 ,
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
L_2 ) ;
if ( F_10 ( V_10 ) ) {
F_11 ( L_3 ) ;
V_9 = F_12 ( V_10 ) ;
V_10 = NULL ;
goto V_12;
}
if ( ! F_13 ( & V_13 . V_14 ) )
F_14 ( & V_15 ) ;
F_1 () ;
} else if ( V_10 ) {
F_15 ( V_10 ) ;
V_10 = NULL ;
}
V_12:
return V_9 ;
}
struct V_16 * F_16 ( void )
{
struct V_16 * V_17 ;
V_18:
if ( F_17 ( F_18 ( & V_19 ) ) )
return F_19 ( V_20 ) ;
V_17 = F_20 ( ( V_21 | V_22 ) & ~ V_23 ,
V_24 ) ;
if ( ! V_17 ) {
F_21 ( V_25 ) ;
return NULL ;
}
F_21 ( V_26 ) ;
F_22 () ;
if ( F_23 ( & V_20 , NULL , V_17 ) ) {
F_24 () ;
F_25 ( V_17 , F_26 ( V_17 ) ) ;
goto V_18;
}
F_27 ( & V_19 , 2 ) ;
F_24 () ;
return F_19 ( V_20 ) ;
}
void F_28 ( void )
{
F_29 ( F_30 ( & V_19 ) ) ;
}
static unsigned long F_31 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
return F_32 ( & V_19 ) == 1 ? V_31 : 0 ;
}
static unsigned long F_33 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
if ( F_34 ( & V_19 , 1 , 0 ) == 1 ) {
struct V_16 * V_17 = F_35 ( & V_20 , NULL ) ;
F_29 ( V_17 == NULL ) ;
F_25 ( V_17 , F_26 ( V_17 ) ) ;
return V_31 ;
}
return 0 ;
}
static T_1 F_36 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_2 V_37 ,
enum V_38 V_39 ,
enum V_38 V_40 ,
enum V_38 V_41 )
{
if ( ! memcmp ( L_4 , V_36 ,
F_3 ( sizeof( L_4 ) - 1 , V_37 ) ) ) {
if ( V_39 == V_40 )
return - V_42 ;
F_37 ( V_39 , & V_43 ) ;
F_37 ( V_41 , & V_43 ) ;
F_38 ( V_40 , & V_43 ) ;
} else if ( ! memcmp ( L_5 , V_36 ,
F_3 ( sizeof( L_5 ) - 1 , V_37 ) ) ) {
F_37 ( V_40 , & V_43 ) ;
F_37 ( V_41 , & V_43 ) ;
F_38 ( V_39 , & V_43 ) ;
} else if ( ! memcmp ( L_6 , V_36 ,
F_3 ( sizeof( L_6 ) - 1 , V_37 ) ) ) {
F_37 ( V_39 , & V_43 ) ;
F_37 ( V_40 , & V_43 ) ;
F_38 ( V_41 , & V_43 ) ;
} else if ( ! memcmp ( L_7 , V_36 ,
F_3 ( sizeof( L_7 ) - 1 , V_37 ) ) ) {
F_37 ( V_39 , & V_43 ) ;
F_37 ( V_41 , & V_43 ) ;
F_37 ( V_40 , & V_43 ) ;
} else
return - V_42 ;
return V_37 ;
}
static T_1 F_39 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 )
{
if ( F_40 ( V_44 , & V_43 ) )
return sprintf ( V_36 , L_8 ) ;
else if ( F_40 ( V_45 , & V_43 ) )
return sprintf ( V_36 , L_9 ) ;
else
return sprintf ( V_36 , L_10 ) ;
}
static T_1 F_41 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_2 V_37 )
{
T_1 V_46 ;
V_46 = F_36 ( V_33 , V_35 , V_36 , V_37 ,
V_44 ,
V_44 ,
V_45 ) ;
if ( V_46 > 0 ) {
int V_9 ;
F_42 ( & V_47 ) ;
V_9 = F_7 () ;
F_43 ( & V_47 ) ;
if ( V_9 )
V_46 = V_9 ;
}
return V_46 ;
}
static T_1 F_44 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 ,
enum V_38 V_48 )
{
return sprintf ( V_36 , L_11 ,
! ! F_40 ( V_48 , & V_43 ) ) ;
}
static T_1 F_45 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_2 V_37 ,
enum V_38 V_48 )
{
unsigned long V_49 ;
int V_46 ;
V_46 = F_46 ( V_36 , 10 , & V_49 ) ;
if ( V_46 < 0 )
return V_46 ;
if ( V_49 > 1 )
return - V_42 ;
if ( V_49 )
F_38 ( V_48 , & V_43 ) ;
else
F_37 ( V_48 , & V_43 ) ;
return V_37 ;
}
static T_1 F_47 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 )
{
if ( F_40 ( V_50 , & V_43 ) )
return sprintf ( V_36 , L_12 ) ;
if ( F_40 ( V_51 , & V_43 ) )
return sprintf ( V_36 , L_13 ) ;
else if ( F_40 ( V_52 , & V_43 ) )
return sprintf ( V_36 , L_14 ) ;
else
return sprintf ( V_36 , L_15 ) ;
}
static T_1 F_48 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_2 V_37 )
{
return F_36 ( V_33 , V_35 , V_36 , V_37 ,
V_50 ,
V_51 ,
V_52 ) ;
}
static T_1 F_49 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 )
{
return F_44 ( V_33 , V_35 , V_36 ,
V_53 ) ;
}
static T_1 F_50 ( struct V_32 * V_33 ,
struct V_34 * V_35 , const char * V_36 , T_2 V_37 )
{
return F_45 ( V_33 , V_35 , V_36 , V_37 ,
V_53 ) ;
}
static T_1 F_51 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 )
{
return F_44 ( V_33 , V_35 , V_36 ,
V_54 ) ;
}
static T_1 F_52 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_2 V_37 )
{
return F_45 ( V_33 , V_35 , V_36 , V_37 ,
V_54 ) ;
}
static T_1 F_53 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_16 , V_55 ) ;
}
static T_1 F_54 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_2 V_37 )
{
unsigned long V_56 ;
int V_9 ;
V_9 = F_46 ( V_36 , 10 , & V_56 ) ;
if ( V_9 || V_56 > V_57 )
return - V_42 ;
V_55 = V_56 ;
F_14 ( & V_15 ) ;
return V_37 ;
}
static T_1 F_55 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_16 , V_58 ) ;
}
static T_1 F_56 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_2 V_37 )
{
unsigned long V_56 ;
int V_9 ;
V_9 = F_46 ( V_36 , 10 , & V_56 ) ;
if ( V_9 || V_56 > V_57 )
return - V_42 ;
V_58 = V_56 ;
F_14 ( & V_15 ) ;
return V_37 ;
}
static T_1 F_57 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_16 , V_59 ) ;
}
static T_1 F_58 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_2 V_37 )
{
int V_9 ;
unsigned long V_60 ;
V_9 = F_46 ( V_36 , 10 , & V_60 ) ;
if ( V_9 || ! V_60 || V_60 > V_57 )
return - V_42 ;
V_59 = V_60 ;
return V_37 ;
}
static T_1 F_59 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_16 , V_61 ) ;
}
static T_1 F_60 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_16 , V_62 ) ;
}
static T_1 F_61 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 )
{
return F_44 ( V_33 , V_35 , V_36 ,
V_63 ) ;
}
static T_1 F_62 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_2 V_37 )
{
return F_45 ( V_33 , V_35 , V_36 , V_37 ,
V_63 ) ;
}
static T_1 F_63 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_16 , V_64 ) ;
}
static T_1 F_64 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_2 V_37 )
{
int V_9 ;
unsigned long V_65 ;
V_9 = F_46 ( V_36 , 10 , & V_65 ) ;
if ( V_9 || V_65 > V_31 - 1 )
return - V_42 ;
V_64 = V_65 ;
return V_37 ;
}
static int T_3 F_65 ( struct V_32 * * V_66 )
{
int V_9 ;
* V_66 = F_66 ( L_17 , V_67 ) ;
if ( F_67 ( ! * V_66 ) ) {
F_11 ( L_18 ) ;
return - V_68 ;
}
V_9 = F_68 ( * V_66 , & V_69 ) ;
if ( V_9 ) {
F_11 ( L_19 ) ;
goto V_70;
}
V_9 = F_68 ( * V_66 , & V_71 ) ;
if ( V_9 ) {
F_11 ( L_19 ) ;
goto V_72;
}
return 0 ;
V_72:
F_69 ( * V_66 , & V_69 ) ;
V_70:
F_70 ( * V_66 ) ;
return V_9 ;
}
static void T_3 F_71 ( struct V_32 * V_66 )
{
F_69 ( V_66 , & V_71 ) ;
F_69 ( V_66 , & V_69 ) ;
F_70 ( V_66 ) ;
}
static inline int F_65 ( struct V_32 * * V_66 )
{
return 0 ;
}
static inline void F_71 ( struct V_32 * V_66 )
{
}
static int T_3 F_72 ( void )
{
int V_9 ;
struct V_32 * V_66 ;
if ( ! F_73 () ) {
V_43 = 0 ;
return - V_42 ;
}
V_59 = V_31 * 8 ;
V_64 = V_31 - 1 ;
F_74 ( V_24 >= V_73 ) ;
F_74 ( V_24 < 2 ) ;
V_9 = F_65 ( & V_66 ) ;
if ( V_9 )
goto V_74;
V_9 = F_75 () ;
if ( V_9 )
goto V_75;
V_9 = F_76 ( & V_76 ) ;
if ( V_9 )
goto V_77;
V_9 = F_76 ( & V_78 ) ;
if ( V_9 )
goto V_79;
if ( V_80 < ( 512 << ( 20 - V_6 ) ) ) {
V_43 = 0 ;
return 0 ;
}
V_9 = F_7 () ;
if ( V_9 )
goto V_81;
return 0 ;
V_81:
F_77 ( & V_78 ) ;
V_79:
F_77 ( & V_76 ) ;
V_77:
F_78 () ;
V_75:
F_71 ( V_66 ) ;
V_74:
return V_9 ;
}
static int T_3 F_79 ( char * V_82 )
{
int V_46 = 0 ;
if ( ! V_82 )
goto V_83;
if ( ! strcmp ( V_82 , L_5 ) ) {
F_38 ( V_44 ,
& V_43 ) ;
F_37 ( V_45 ,
& V_43 ) ;
V_46 = 1 ;
} else if ( ! strcmp ( V_82 , L_6 ) ) {
F_37 ( V_44 ,
& V_43 ) ;
F_38 ( V_45 ,
& V_43 ) ;
V_46 = 1 ;
} else if ( ! strcmp ( V_82 , L_7 ) ) {
F_37 ( V_44 ,
& V_43 ) ;
F_37 ( V_45 ,
& V_43 ) ;
V_46 = 1 ;
}
V_83:
if ( ! V_46 )
F_80 ( L_20 ) ;
return V_46 ;
}
T_4 F_81 ( T_4 V_84 , struct V_85 * V_86 )
{
if ( F_17 ( V_86 -> V_87 & V_88 ) )
V_84 = F_82 ( V_84 ) ;
return V_84 ;
}
static inline T_4 F_83 ( struct V_16 * V_16 , T_5 V_89 )
{
T_4 V_90 ;
V_90 = F_84 ( V_16 , V_89 ) ;
V_90 = F_85 ( V_90 ) ;
return V_90 ;
}
static inline struct V_91 * F_86 ( struct V_16 * V_16 )
{
return (struct V_91 * ) & V_16 [ 2 ] . V_92 ;
}
void F_87 ( struct V_16 * V_16 )
{
F_88 ( F_86 ( V_16 ) ) ;
F_89 ( V_16 , V_93 ) ;
}
static int F_90 ( struct V_94 * V_95 ,
struct V_85 * V_86 ,
unsigned long V_96 , T_4 * V_84 ,
struct V_16 * V_16 , T_6 V_97 ,
unsigned int V_98 )
{
struct V_99 * V_100 ;
T_7 V_101 ;
T_8 * V_102 ;
unsigned long V_103 = V_96 & V_104 ;
F_91 ( ! F_92 ( V_16 ) , V_16 ) ;
if ( F_93 ( V_16 , V_95 , V_97 , & V_100 , true ) ) {
F_94 ( V_16 ) ;
F_21 ( V_105 ) ;
return V_106 ;
}
V_101 = F_95 ( V_95 , V_103 ) ;
if ( F_67 ( ! V_101 ) ) {
F_96 ( V_16 , V_100 , true ) ;
F_94 ( V_16 ) ;
return V_107 ;
}
F_97 ( V_16 , V_103 , V_31 ) ;
F_98 ( V_16 ) ;
V_102 = F_99 ( V_95 , V_84 ) ;
if ( F_67 ( ! F_100 ( * V_84 ) ) ) {
F_101 ( V_102 ) ;
F_96 ( V_16 , V_100 , true ) ;
F_94 ( V_16 ) ;
F_102 ( V_95 , V_101 ) ;
} else {
T_4 V_90 ;
if ( F_103 ( V_86 ) ) {
int V_46 ;
F_101 ( V_102 ) ;
F_96 ( V_16 , V_100 , true ) ;
F_94 ( V_16 ) ;
F_102 ( V_95 , V_101 ) ;
V_46 = F_104 ( V_86 , V_96 , V_98 ,
V_108 ) ;
F_105 ( V_46 & V_106 ) ;
return V_46 ;
}
V_90 = F_83 ( V_16 , V_86 -> V_109 ) ;
V_90 = F_81 ( F_106 ( V_90 ) , V_86 ) ;
F_107 ( V_16 , V_86 , V_103 , true ) ;
F_108 ( V_16 , V_100 , false , true ) ;
F_109 ( V_16 , V_86 ) ;
F_110 ( V_95 , V_84 , V_101 ) ;
F_111 ( V_95 , V_103 , V_84 , V_90 ) ;
F_112 ( V_95 , V_110 , V_31 ) ;
F_113 ( & V_95 -> V_111 ) ;
F_101 ( V_102 ) ;
F_21 ( V_112 ) ;
}
return 0 ;
}
static inline T_6 F_114 ( struct V_85 * V_86 )
{
T_6 V_113 = 0 ;
if ( F_40 ( V_52 , & V_43 ) &&
( V_86 -> V_87 & V_114 ) )
V_113 = V_115 ;
else if ( F_40 ( V_51 , & V_43 ) )
V_113 = V_116 ;
else if ( F_40 ( V_50 , & V_43 ) )
V_113 = V_115 ;
return V_21 | V_113 ;
}
static inline T_6 F_115 ( void )
{
return V_21 | ( F_116 () ? V_115 : 0 ) ;
}
static bool F_117 ( T_7 V_101 , struct V_94 * V_95 ,
struct V_85 * V_86 , unsigned long V_103 , T_4 * V_84 ,
struct V_16 * V_17 )
{
T_4 V_90 ;
if ( ! F_100 ( * V_84 ) )
return false ;
V_90 = F_84 ( V_17 , V_86 -> V_109 ) ;
V_90 = F_85 ( V_90 ) ;
if ( V_101 )
F_110 ( V_95 , V_84 , V_101 ) ;
F_111 ( V_95 , V_103 , V_84 , V_90 ) ;
F_113 ( & V_95 -> V_111 ) ;
return true ;
}
int F_118 ( struct V_94 * V_95 , struct V_85 * V_86 ,
unsigned long V_96 , T_4 * V_84 ,
unsigned int V_98 )
{
T_6 V_97 ;
struct V_16 * V_16 ;
unsigned long V_103 = V_96 & V_104 ;
if ( V_103 < V_86 -> V_117 || V_103 + V_118 > V_86 -> V_119 )
return V_106 ;
if ( F_67 ( F_119 ( V_86 ) ) )
return V_107 ;
if ( F_67 ( F_120 ( V_86 , V_86 -> V_87 ) ) )
return V_107 ;
if ( ! ( V_98 & V_120 ) && ! F_121 ( V_95 ) &&
F_122 () ) {
T_8 * V_102 ;
T_7 V_101 ;
struct V_16 * V_17 ;
bool V_121 ;
int V_46 ;
V_101 = F_95 ( V_95 , V_103 ) ;
if ( F_67 ( ! V_101 ) )
return V_107 ;
V_17 = F_16 () ;
if ( F_67 ( ! V_17 ) ) {
F_102 ( V_95 , V_101 ) ;
F_21 ( V_105 ) ;
return V_106 ;
}
V_102 = F_99 ( V_95 , V_84 ) ;
V_46 = 0 ;
V_121 = false ;
if ( F_100 ( * V_84 ) ) {
if ( F_103 ( V_86 ) ) {
F_101 ( V_102 ) ;
V_46 = F_104 ( V_86 , V_96 , V_98 ,
V_108 ) ;
F_105 ( V_46 & V_106 ) ;
} else {
F_117 ( V_101 , V_95 , V_86 ,
V_103 , V_84 ,
V_17 ) ;
F_101 ( V_102 ) ;
V_121 = true ;
}
} else
F_101 ( V_102 ) ;
if ( ! V_121 ) {
F_102 ( V_95 , V_101 ) ;
F_28 () ;
}
return V_46 ;
}
V_97 = F_114 ( V_86 ) ;
V_16 = F_123 ( V_97 , V_86 , V_103 , V_24 ) ;
if ( F_67 ( ! V_16 ) ) {
F_21 ( V_105 ) ;
return V_106 ;
}
F_87 ( V_16 ) ;
return F_90 ( V_95 , V_86 , V_96 , V_84 , V_16 , V_97 ,
V_98 ) ;
}
static void F_124 ( struct V_85 * V_86 , unsigned long V_122 ,
T_4 * V_84 , T_9 V_123 , T_5 V_89 , bool V_124 )
{
struct V_94 * V_95 = V_86 -> V_125 ;
T_4 V_90 ;
T_8 * V_102 ;
V_102 = F_99 ( V_95 , V_84 ) ;
V_90 = F_85 ( F_125 ( V_123 , V_89 ) ) ;
if ( F_126 ( V_123 ) )
V_90 = F_127 ( V_90 ) ;
if ( V_124 ) {
V_90 = F_128 ( F_106 ( V_90 ) ) ;
V_90 = F_81 ( V_90 , V_86 ) ;
}
F_111 ( V_95 , V_122 , V_84 , V_90 ) ;
F_129 ( V_86 , V_122 , V_84 ) ;
F_101 ( V_102 ) ;
}
int F_130 ( struct V_85 * V_86 , unsigned long V_122 ,
T_4 * V_84 , T_9 V_123 , bool V_124 )
{
T_5 V_126 = V_86 -> V_109 ;
F_29 ( ! ( V_86 -> V_87 & ( V_127 | V_128 ) ) ) ;
F_29 ( ( V_86 -> V_87 & ( V_127 | V_128 ) ) ==
( V_127 | V_128 ) ) ;
F_29 ( ( V_86 -> V_87 & V_127 ) && F_131 ( V_86 -> V_87 ) ) ;
F_29 ( ! F_126 ( V_123 ) ) ;
if ( V_122 < V_86 -> V_117 || V_122 >= V_86 -> V_119 )
return V_129 ;
if ( F_132 ( V_86 , & V_126 , V_123 ) )
return V_129 ;
F_124 ( V_86 , V_122 , V_84 , V_123 , V_126 , V_124 ) ;
return V_130 ;
}
static void F_133 ( struct V_85 * V_86 , unsigned long V_122 ,
T_4 * V_84 )
{
T_4 V_131 ;
V_131 = F_128 ( F_106 ( * V_84 ) ) ;
if ( F_134 ( V_86 , V_122 & V_104 ,
V_84 , V_131 , 1 ) )
F_129 ( V_86 , V_122 , V_84 ) ;
}
struct V_16 * F_135 ( struct V_85 * V_86 , unsigned long V_122 ,
T_4 * V_84 , int V_98 )
{
unsigned long V_123 = F_136 ( * V_84 ) ;
struct V_94 * V_95 = V_86 -> V_125 ;
struct V_132 * V_133 ;
struct V_16 * V_16 ;
F_137 ( F_138 ( V_95 , V_84 ) ) ;
if ( V_98 & V_134 && ! F_139 ( * V_84 ) )
return NULL ;
if ( F_140 ( * V_84 ) && F_141 ( * V_84 ) )
;
else
return NULL ;
if ( V_98 & V_135 )
F_133 ( V_86 , V_122 , V_84 ) ;
if ( ! ( V_98 & V_136 ) )
return F_142 ( - V_137 ) ;
V_123 += ( V_122 & ~ V_138 ) >> V_6 ;
V_133 = F_143 ( V_123 , NULL ) ;
if ( ! V_133 )
return F_142 ( - V_139 ) ;
V_16 = F_144 ( V_123 ) ;
F_145 ( V_16 ) ;
F_146 ( V_133 ) ;
return V_16 ;
}
int F_147 ( struct V_94 * V_140 , struct V_94 * V_141 ,
T_4 * V_142 , T_4 * V_143 , unsigned long V_122 ,
struct V_85 * V_86 )
{
T_8 * V_144 , * V_145 ;
struct V_16 * V_146 ;
T_4 V_84 ;
T_7 V_101 = NULL ;
int V_46 ;
if ( ! F_148 ( V_86 ) ) {
V_46 = - V_68 ;
V_101 = F_95 ( V_140 , V_122 ) ;
if ( F_67 ( ! V_101 ) )
goto V_83;
}
V_144 = F_99 ( V_140 , V_142 ) ;
V_145 = F_138 ( V_141 , V_143 ) ;
F_149 ( V_145 , V_147 ) ;
V_46 = - V_148 ;
V_84 = * V_143 ;
if ( F_67 ( ! F_150 ( V_84 ) && ! F_141 ( V_84 ) ) ) {
F_102 ( V_140 , V_101 ) ;
goto V_149;
}
if ( F_151 ( V_84 ) ) {
struct V_16 * V_17 ;
V_17 = F_16 () ;
F_117 ( V_101 , V_140 , V_86 , V_122 , V_142 ,
V_17 ) ;
V_46 = 0 ;
goto V_149;
}
if ( ! F_148 ( V_86 ) ) {
V_146 = F_152 ( V_84 ) ;
F_91 ( ! F_153 ( V_146 ) , V_146 ) ;
F_145 ( V_146 ) ;
F_154 ( V_146 , true ) ;
F_112 ( V_140 , V_110 , V_31 ) ;
F_113 ( & V_140 -> V_111 ) ;
F_110 ( V_140 , V_142 , V_101 ) ;
}
F_155 ( V_141 , V_122 , V_143 ) ;
V_84 = F_156 ( F_157 ( V_84 ) ) ;
F_111 ( V_140 , V_122 , V_142 , V_84 ) ;
V_46 = 0 ;
V_149:
F_101 ( V_145 ) ;
F_101 ( V_144 ) ;
V_83:
return V_46 ;
}
void F_158 ( struct V_94 * V_95 ,
struct V_85 * V_86 ,
unsigned long V_96 ,
T_4 * V_84 , T_4 V_150 ,
int V_151 )
{
T_8 * V_102 ;
T_4 V_90 ;
unsigned long V_103 ;
V_102 = F_99 ( V_95 , V_84 ) ;
if ( F_67 ( ! F_159 ( * V_84 , V_150 ) ) )
goto V_152;
V_90 = F_128 ( V_150 ) ;
V_103 = V_96 & V_104 ;
if ( F_134 ( V_86 , V_103 , V_84 , V_90 , V_151 ) )
F_129 ( V_86 , V_96 , V_84 ) ;
V_152:
F_101 ( V_102 ) ;
}
static int F_160 ( struct V_94 * V_95 ,
struct V_85 * V_86 ,
unsigned long V_96 ,
T_4 * V_84 , T_4 V_150 ,
struct V_16 * V_16 ,
unsigned long V_103 )
{
struct V_99 * V_100 ;
T_8 * V_102 ;
T_7 V_101 ;
T_4 V_131 ;
int V_46 = 0 , V_153 ;
struct V_16 * * V_60 ;
unsigned long V_154 ;
unsigned long V_155 ;
V_60 = F_161 ( sizeof( struct V_16 * ) * V_31 ,
V_156 ) ;
if ( F_67 ( ! V_60 ) ) {
V_46 |= V_107 ;
goto V_83;
}
for ( V_153 = 0 ; V_153 < V_31 ; V_153 ++ ) {
V_60 [ V_153 ] = F_162 ( V_157 |
V_158 ,
V_86 , V_96 , F_163 ( V_16 ) ) ;
if ( F_67 ( ! V_60 [ V_153 ] ||
F_93 ( V_60 [ V_153 ] , V_95 , V_156 ,
& V_100 , false ) ) ) {
if ( V_60 [ V_153 ] )
F_94 ( V_60 [ V_153 ] ) ;
while ( -- V_153 >= 0 ) {
V_100 = ( void * ) F_164 ( V_60 [ V_153 ] ) ;
F_165 ( V_60 [ V_153 ] , 0 ) ;
F_96 ( V_60 [ V_153 ] , V_100 ,
false ) ;
F_94 ( V_60 [ V_153 ] ) ;
}
F_166 ( V_60 ) ;
V_46 |= V_107 ;
goto V_83;
}
F_165 ( V_60 [ V_153 ] , ( unsigned long ) V_100 ) ;
}
for ( V_153 = 0 ; V_153 < V_31 ; V_153 ++ ) {
F_167 ( V_60 [ V_153 ] , V_16 + V_153 ,
V_103 + V_159 * V_153 , V_86 ) ;
F_98 ( V_60 [ V_153 ] ) ;
F_168 () ;
}
V_154 = V_103 ;
V_155 = V_103 + V_118 ;
F_169 ( V_95 , V_154 , V_155 ) ;
V_102 = F_99 ( V_95 , V_84 ) ;
if ( F_67 ( ! F_159 ( * V_84 , V_150 ) ) )
goto V_160;
F_91 ( ! F_153 ( V_16 ) , V_16 ) ;
F_170 ( V_86 , V_103 , V_84 ) ;
V_101 = F_171 ( V_95 , V_84 ) ;
F_172 ( V_95 , & V_131 , V_101 ) ;
for ( V_153 = 0 ; V_153 < V_31 ; V_153 ++ , V_103 += V_159 ) {
T_10 * V_161 , V_90 ;
V_90 = F_173 ( V_60 [ V_153 ] , V_86 -> V_109 ) ;
V_90 = F_174 ( F_175 ( V_90 ) , V_86 ) ;
V_100 = ( void * ) F_164 ( V_60 [ V_153 ] ) ;
F_165 ( V_60 [ V_153 ] , 0 ) ;
F_107 ( V_60 [ V_153 ] , V_86 , V_103 , false ) ;
F_108 ( V_60 [ V_153 ] , V_100 , false , false ) ;
F_109 ( V_60 [ V_153 ] , V_86 ) ;
V_161 = F_176 ( & V_131 , V_103 ) ;
F_105 ( ! F_177 ( * V_161 ) ) ;
F_178 ( V_95 , V_103 , V_161 , V_90 ) ;
F_179 ( V_161 ) ;
}
F_166 ( V_60 ) ;
F_180 () ;
F_172 ( V_95 , V_84 , V_101 ) ;
F_181 ( V_16 , true ) ;
F_101 ( V_102 ) ;
F_182 ( V_95 , V_154 , V_155 ) ;
V_46 |= V_162 ;
F_94 ( V_16 ) ;
V_83:
return V_46 ;
V_160:
F_101 ( V_102 ) ;
F_182 ( V_95 , V_154 , V_155 ) ;
for ( V_153 = 0 ; V_153 < V_31 ; V_153 ++ ) {
V_100 = ( void * ) F_164 ( V_60 [ V_153 ] ) ;
F_165 ( V_60 [ V_153 ] , 0 ) ;
F_96 ( V_60 [ V_153 ] , V_100 , false ) ;
F_94 ( V_60 [ V_153 ] ) ;
}
F_166 ( V_60 ) ;
goto V_83;
}
int F_183 ( struct V_94 * V_95 , struct V_85 * V_86 ,
unsigned long V_96 , T_4 * V_84 , T_4 V_150 )
{
T_8 * V_102 ;
int V_46 = 0 ;
struct V_16 * V_16 = NULL , * V_163 ;
struct V_99 * V_100 ;
unsigned long V_103 ;
unsigned long V_154 ;
unsigned long V_155 ;
T_6 V_164 ;
V_102 = F_138 ( V_95 , V_84 ) ;
F_184 ( ! V_86 -> V_165 , V_86 ) ;
V_103 = V_96 & V_104 ;
if ( F_151 ( V_150 ) )
goto V_166;
F_185 ( V_102 ) ;
if ( F_67 ( ! F_159 ( * V_84 , V_150 ) ) )
goto V_149;
V_16 = F_152 ( V_150 ) ;
F_91 ( ! F_92 ( V_16 ) || ! F_153 ( V_16 ) , V_16 ) ;
if ( F_186 ( V_16 , NULL ) == 1 ) {
T_4 V_90 ;
V_90 = F_128 ( V_150 ) ;
V_90 = F_81 ( F_106 ( V_90 ) , V_86 ) ;
if ( F_134 ( V_86 , V_103 , V_84 , V_90 , 1 ) )
F_129 ( V_86 , V_96 , V_84 ) ;
V_46 |= V_162 ;
goto V_149;
}
F_145 ( V_16 ) ;
F_101 ( V_102 ) ;
V_166:
if ( F_187 ( V_86 ) &&
! F_188 () ) {
V_164 = F_114 ( V_86 ) ;
V_163 = F_123 ( V_164 , V_86 , V_103 , V_24 ) ;
} else
V_163 = NULL ;
if ( F_17 ( V_163 ) ) {
F_87 ( V_163 ) ;
} else {
if ( ! V_16 ) {
F_189 ( V_86 , V_84 , V_96 ) ;
V_46 |= V_106 ;
} else {
V_46 = F_160 ( V_95 , V_86 , V_96 ,
V_84 , V_150 , V_16 , V_103 ) ;
if ( V_46 & V_107 ) {
F_189 ( V_86 , V_84 , V_96 ) ;
V_46 |= V_106 ;
}
F_94 ( V_16 ) ;
}
F_21 ( V_105 ) ;
goto V_83;
}
if ( F_67 ( F_93 ( V_163 , V_95 , V_164 , & V_100 ,
true ) ) ) {
F_94 ( V_163 ) ;
if ( V_16 ) {
F_189 ( V_86 , V_84 , V_96 ) ;
F_94 ( V_16 ) ;
} else
F_189 ( V_86 , V_84 , V_96 ) ;
V_46 |= V_106 ;
F_21 ( V_105 ) ;
goto V_83;
}
F_21 ( V_112 ) ;
if ( ! V_16 )
F_97 ( V_163 , V_103 , V_31 ) ;
else
F_190 ( V_163 , V_16 , V_103 , V_86 , V_31 ) ;
F_98 ( V_163 ) ;
V_154 = V_103 ;
V_155 = V_103 + V_118 ;
F_169 ( V_95 , V_154 , V_155 ) ;
F_185 ( V_102 ) ;
if ( V_16 )
F_94 ( V_16 ) ;
if ( F_67 ( ! F_159 ( * V_84 , V_150 ) ) ) {
F_101 ( V_102 ) ;
F_96 ( V_163 , V_100 , true ) ;
F_94 ( V_163 ) ;
goto V_167;
} else {
T_4 V_90 ;
V_90 = F_83 ( V_163 , V_86 -> V_109 ) ;
V_90 = F_81 ( F_106 ( V_90 ) , V_86 ) ;
F_170 ( V_86 , V_103 , V_84 ) ;
F_107 ( V_163 , V_86 , V_103 , true ) ;
F_108 ( V_163 , V_100 , false , true ) ;
F_109 ( V_163 , V_86 ) ;
F_111 ( V_95 , V_103 , V_84 , V_90 ) ;
F_129 ( V_86 , V_96 , V_84 ) ;
if ( ! V_16 ) {
F_112 ( V_95 , V_110 , V_31 ) ;
F_28 () ;
} else {
F_91 ( ! F_153 ( V_16 ) , V_16 ) ;
F_181 ( V_16 , true ) ;
F_94 ( V_16 ) ;
}
V_46 |= V_162 ;
}
F_101 ( V_102 ) ;
V_167:
F_182 ( V_95 , V_154 , V_155 ) ;
V_83:
return V_46 ;
V_149:
F_101 ( V_102 ) ;
return V_46 ;
}
struct V_16 * F_191 ( struct V_85 * V_86 ,
unsigned long V_122 ,
T_4 * V_84 ,
unsigned int V_98 )
{
struct V_94 * V_95 = V_86 -> V_125 ;
struct V_16 * V_16 = NULL ;
F_137 ( F_138 ( V_95 , V_84 ) ) ;
if ( V_98 & V_134 && ! F_139 ( * V_84 ) )
goto V_83;
if ( ( V_98 & V_168 ) && F_151 ( * V_84 ) )
return F_142 ( - V_139 ) ;
if ( ( V_98 & V_169 ) && F_192 ( * V_84 ) )
goto V_83;
V_16 = F_152 ( * V_84 ) ;
F_91 ( ! F_153 ( V_16 ) , V_16 ) ;
if ( V_98 & V_135 )
F_133 ( V_86 , V_122 , V_84 ) ;
if ( ( V_98 & V_170 ) && ( V_86 -> V_87 & V_171 ) ) {
if ( F_193 ( V_16 ) == 1 && ! F_194 ( V_16 ) &&
V_16 -> V_92 && F_195 ( V_16 ) ) {
F_196 () ;
if ( V_16 -> V_92 )
F_197 ( V_16 ) ;
F_198 ( V_16 ) ;
}
}
V_16 += ( V_122 & ~ V_104 ) >> V_6 ;
F_91 ( ! F_92 ( V_16 ) , V_16 ) ;
if ( V_98 & V_136 )
F_145 ( V_16 ) ;
V_83:
return V_16 ;
}
int F_199 ( struct V_94 * V_95 , struct V_85 * V_86 ,
unsigned long V_122 , T_4 V_84 , T_4 * V_172 )
{
T_8 * V_102 ;
struct V_165 * V_165 = NULL ;
struct V_16 * V_16 ;
unsigned long V_103 = V_122 & V_104 ;
int V_173 = - 1 , V_174 = F_200 () ;
int V_175 , V_176 = - 1 ;
bool V_177 ;
bool V_178 = false ;
bool V_179 ;
int V_98 = 0 ;
F_29 ( ! ( V_86 -> V_87 & ( V_180 | V_181 | V_88 ) ) ) ;
V_102 = F_99 ( V_95 , V_172 ) ;
if ( F_67 ( ! F_159 ( V_84 , * V_172 ) ) )
goto V_149;
if ( F_67 ( F_201 ( * V_172 ) ) ) {
V_16 = F_152 ( * V_172 ) ;
F_101 ( V_102 ) ;
F_202 ( V_16 ) ;
goto V_83;
}
V_16 = F_152 ( V_84 ) ;
F_29 ( F_203 ( V_16 ) ) ;
V_173 = F_163 ( V_16 ) ;
V_176 = F_204 ( V_16 ) ;
F_205 ( V_182 ) ;
if ( V_173 == V_174 ) {
F_205 ( V_183 ) ;
V_98 |= V_184 ;
}
if ( ! ( V_86 -> V_87 & V_88 ) )
V_98 |= V_185 ;
V_177 = F_195 ( V_16 ) ;
V_175 = F_206 ( V_16 , V_86 , V_103 ) ;
if ( V_175 == - 1 ) {
if ( V_177 )
goto V_186;
}
if ( ! V_177 ) {
F_101 ( V_102 ) ;
F_202 ( V_16 ) ;
V_173 = - 1 ;
goto V_83;
}
F_145 ( V_16 ) ;
F_101 ( V_102 ) ;
V_165 = F_207 ( V_16 ) ;
F_185 ( V_102 ) ;
if ( F_67 ( ! F_159 ( V_84 , * V_172 ) ) ) {
F_198 ( V_16 ) ;
F_94 ( V_16 ) ;
V_173 = - 1 ;
goto V_149;
}
if ( F_67 ( ! V_165 ) ) {
F_94 ( V_16 ) ;
V_173 = - 1 ;
goto V_186;
}
F_101 ( V_102 ) ;
V_178 = F_208 ( V_95 , V_86 ,
V_172 , V_84 , V_122 , V_16 , V_175 ) ;
if ( V_178 ) {
V_98 |= V_187 ;
V_173 = V_175 ;
} else
V_98 |= V_188 ;
goto V_83;
V_186:
F_29 ( ! F_209 ( V_16 ) ) ;
V_179 = F_139 ( V_84 ) ;
V_84 = F_210 ( V_84 , V_86 -> V_109 ) ;
V_84 = F_128 ( V_84 ) ;
if ( V_179 )
V_84 = F_82 ( V_84 ) ;
F_111 ( V_95 , V_103 , V_172 , V_84 ) ;
F_129 ( V_86 , V_122 , V_172 ) ;
F_198 ( V_16 ) ;
V_149:
F_101 ( V_102 ) ;
V_83:
if ( V_165 )
F_211 ( V_165 ) ;
if ( V_173 != - 1 )
F_212 ( V_176 , V_173 , V_31 , V_98 ) ;
return 0 ;
}
int F_213 ( struct V_189 * V_190 , struct V_85 * V_86 ,
T_4 * V_84 , unsigned long V_122 , unsigned long V_191 )
{
T_8 * V_102 ;
T_4 V_150 ;
struct V_16 * V_16 ;
struct V_94 * V_95 = V_190 -> V_95 ;
int V_46 = 0 ;
V_102 = F_214 ( V_84 , V_86 ) ;
if ( ! V_102 )
goto V_192;
V_150 = * V_84 ;
if ( F_151 ( V_150 ) ) {
V_46 = 1 ;
goto V_83;
}
V_16 = F_152 ( V_150 ) ;
if ( F_215 ( V_16 ) != 1 )
goto V_83;
if ( ! F_195 ( V_16 ) )
goto V_83;
if ( V_191 - V_122 != V_118 ) {
F_145 ( V_16 ) ;
F_101 ( V_102 ) ;
if ( F_216 ( V_16 ) ) {
F_94 ( V_16 ) ;
F_198 ( V_16 ) ;
goto V_192;
}
F_94 ( V_16 ) ;
F_198 ( V_16 ) ;
V_46 = 1 ;
goto V_192;
}
if ( F_217 ( V_16 ) )
F_218 ( V_16 ) ;
F_198 ( V_16 ) ;
if ( F_219 ( V_16 ) )
F_220 ( V_16 ) ;
if ( F_221 ( V_150 ) || F_222 ( V_150 ) ) {
V_150 = F_223 ( V_190 -> V_95 , V_122 , V_84 ,
V_190 -> V_193 ) ;
V_150 = F_156 ( V_150 ) ;
V_150 = F_224 ( V_150 ) ;
F_111 ( V_95 , V_122 , V_84 , V_150 ) ;
F_225 ( V_190 , V_84 , V_122 ) ;
}
V_46 = 1 ;
V_83:
F_101 ( V_102 ) ;
V_192:
return V_46 ;
}
int F_226 ( struct V_189 * V_190 , struct V_85 * V_86 ,
T_4 * V_84 , unsigned long V_122 )
{
T_4 V_150 ;
T_8 * V_102 ;
V_102 = F_227 ( V_84 , V_86 ) ;
if ( ! V_102 )
return 0 ;
V_150 = F_223 ( V_190 -> V_95 , V_122 , V_84 ,
V_190 -> V_193 ) ;
F_225 ( V_190 , V_84 , V_122 ) ;
if ( F_148 ( V_86 ) ) {
F_101 ( V_102 ) ;
if ( F_151 ( V_150 ) )
F_228 ( V_190 , F_152 ( V_150 ) ) ;
} else if ( F_151 ( V_150 ) ) {
F_102 ( V_190 -> V_95 , F_171 ( V_190 -> V_95 , V_84 ) ) ;
F_229 ( & V_190 -> V_95 -> V_111 ) ;
F_101 ( V_102 ) ;
F_228 ( V_190 , F_152 ( V_150 ) ) ;
} else {
struct V_16 * V_16 = F_152 ( V_150 ) ;
F_181 ( V_16 , true ) ;
F_91 ( F_215 ( V_16 ) < 0 , V_16 ) ;
F_112 ( V_190 -> V_95 , V_110 , - V_31 ) ;
F_91 ( ! F_153 ( V_16 ) , V_16 ) ;
F_102 ( V_190 -> V_95 , F_171 ( V_190 -> V_95 , V_84 ) ) ;
F_229 ( & V_190 -> V_95 -> V_111 ) ;
F_101 ( V_102 ) ;
F_228 ( V_190 , V_16 ) ;
}
return 1 ;
}
bool F_230 ( struct V_85 * V_86 , struct V_85 * V_194 ,
unsigned long V_195 ,
unsigned long V_196 , unsigned long V_197 ,
T_4 * V_198 , T_4 * V_199 )
{
T_8 * V_200 , * V_201 ;
T_4 V_84 ;
struct V_94 * V_95 = V_86 -> V_125 ;
if ( ( V_195 & ~ V_104 ) ||
( V_196 & ~ V_104 ) ||
V_197 - V_195 < V_118 ||
( V_194 -> V_87 & V_202 ) )
return false ;
if ( F_231 ( ! F_100 ( * V_199 ) ) ) {
F_105 ( F_150 ( * V_199 ) ) ;
return false ;
}
V_200 = F_227 ( V_198 , V_86 ) ;
if ( V_200 ) {
V_201 = F_138 ( V_95 , V_199 ) ;
if ( V_201 != V_200 )
F_149 ( V_201 , V_147 ) ;
V_84 = F_232 ( V_95 , V_195 , V_198 ) ;
F_105 ( ! F_100 ( * V_199 ) ) ;
if ( F_233 ( V_201 , V_200 ) &&
F_234 ( V_86 ) ) {
T_7 V_101 ;
V_101 = F_171 ( V_95 , V_198 ) ;
F_110 ( V_95 , V_199 , V_101 ) ;
}
F_111 ( V_95 , V_196 , V_199 , F_235 ( V_84 ) ) ;
if ( V_201 != V_200 )
F_101 ( V_201 ) ;
F_101 ( V_200 ) ;
return true ;
}
return false ;
}
int F_236 ( struct V_85 * V_86 , T_4 * V_84 ,
unsigned long V_122 , T_5 V_203 , int V_204 )
{
struct V_94 * V_95 = V_86 -> V_125 ;
T_8 * V_102 ;
int V_46 = 0 ;
V_102 = F_227 ( V_84 , V_86 ) ;
if ( V_102 ) {
T_4 V_90 ;
bool V_205 = V_204 && F_139 ( * V_84 ) ;
V_46 = 1 ;
if ( V_204 && F_151 ( * V_84 ) ) {
F_101 ( V_102 ) ;
return V_46 ;
}
if ( ! V_204 || ! F_192 ( * V_84 ) ) {
V_90 = F_237 ( V_95 , V_122 , V_84 ) ;
V_90 = F_210 ( V_90 , V_203 ) ;
if ( V_205 )
V_90 = F_82 ( V_90 ) ;
V_46 = V_31 ;
F_111 ( V_95 , V_122 , V_84 , V_90 ) ;
F_29 ( ! V_205 && F_139 ( V_90 ) ) ;
}
F_101 ( V_102 ) ;
}
return V_46 ;
}
T_8 * F_227 ( T_4 * V_84 , struct V_85 * V_86 )
{
T_8 * V_102 ;
V_102 = F_99 ( V_86 -> V_125 , V_84 ) ;
if ( F_17 ( F_150 ( * V_84 ) || F_141 ( * V_84 ) ) )
return V_102 ;
F_101 ( V_102 ) ;
return NULL ;
}
int F_238 ( struct V_85 * V_86 ,
unsigned long * V_87 , int V_206 )
{
switch ( V_206 ) {
case V_207 :
#ifdef F_239
if ( F_240 ( V_86 -> V_125 ) )
return 0 ;
#endif
if ( * V_87 & V_208 )
return - V_42 ;
* V_87 &= ~ V_202 ;
* V_87 |= V_114 ;
if ( F_67 ( F_241 ( V_86 , * V_87 ) ) )
return - V_68 ;
break;
case V_209 :
if ( * V_87 & V_208 )
return - V_42 ;
* V_87 &= ~ V_114 ;
* V_87 |= V_202 ;
break;
}
return 0 ;
}
static int T_3 F_75 ( void )
{
V_210 = F_242 ( L_21 ,
sizeof( struct V_211 ) ,
F_243 ( struct V_211 ) , 0 , NULL ) ;
if ( ! V_210 )
return - V_68 ;
return 0 ;
}
static void T_3 F_78 ( void )
{
F_244 ( V_210 ) ;
}
static inline struct V_211 * F_245 ( void )
{
if ( ! V_210 )
return NULL ;
return F_246 ( V_210 , V_156 ) ;
}
static inline void F_247 ( struct V_211 * V_211 )
{
F_248 ( V_210 , V_211 ) ;
}
static struct V_211 * F_249 ( struct V_94 * V_95 )
{
struct V_211 * V_211 ;
F_250 (mm_slots_hash, mm_slot, hash, (unsigned long)mm)
if ( V_95 == V_211 -> V_95 )
return V_211 ;
return NULL ;
}
static void F_251 ( struct V_94 * V_95 ,
struct V_211 * V_211 )
{
V_211 -> V_95 = V_95 ;
F_252 ( V_212 , & V_211 -> V_213 , ( long ) V_95 ) ;
}
static inline int F_253 ( struct V_94 * V_95 )
{
return F_32 ( & V_95 -> V_214 ) == 0 ;
}
int F_254 ( struct V_94 * V_95 )
{
struct V_211 * V_211 ;
int V_215 ;
V_211 = F_245 () ;
if ( ! V_211 )
return - V_68 ;
F_255 ( F_253 ( V_95 ) , V_95 ) ;
if ( F_67 ( F_256 ( V_216 , & V_95 -> V_98 ) ) ) {
F_247 ( V_211 ) ;
return 0 ;
}
F_185 ( & V_217 ) ;
F_251 ( V_95 , V_211 ) ;
V_215 = F_13 ( & V_13 . V_14 ) ;
F_257 ( & V_211 -> V_218 , & V_13 . V_14 ) ;
F_101 ( & V_217 ) ;
F_258 ( & V_95 -> V_219 ) ;
if ( V_215 )
F_14 ( & V_15 ) ;
return 0 ;
}
int F_241 ( struct V_85 * V_86 ,
unsigned long V_87 )
{
unsigned long V_220 , V_221 ;
if ( ! V_86 -> V_165 )
return 0 ;
if ( V_86 -> V_222 || ( V_87 & V_208 ) )
return 0 ;
V_220 = ( V_86 -> V_117 + ~ V_104 ) & V_104 ;
V_221 = V_86 -> V_119 & V_104 ;
if ( V_220 < V_221 )
return F_120 ( V_86 , V_87 ) ;
return 0 ;
}
void F_259 ( struct V_94 * V_95 )
{
struct V_211 * V_211 ;
int free = 0 ;
F_185 ( & V_217 ) ;
V_211 = F_249 ( V_95 ) ;
if ( V_211 && V_13 . V_211 != V_211 ) {
F_260 ( & V_211 -> V_213 ) ;
F_261 ( & V_211 -> V_218 ) ;
free = 1 ;
}
F_101 ( & V_217 ) ;
if ( free ) {
F_37 ( V_216 , & V_95 -> V_98 ) ;
F_247 ( V_211 ) ;
F_262 ( V_95 ) ;
} else if ( V_211 ) {
F_263 ( & V_95 -> V_223 ) ;
F_264 ( & V_95 -> V_223 ) ;
}
}
static void F_265 ( struct V_16 * V_16 )
{
F_266 ( V_16 , V_224 + 0 ) ;
F_198 ( V_16 ) ;
F_267 ( V_16 ) ;
}
static void F_268 ( T_10 * V_161 , T_10 * V_225 )
{
while ( -- V_225 >= V_161 ) {
T_10 V_226 = * V_225 ;
if ( ! F_177 ( V_226 ) && ! F_269 ( F_270 ( V_226 ) ) )
F_265 ( F_271 ( V_226 ) ) ;
}
}
static int F_272 ( struct V_85 * V_86 ,
unsigned long V_96 ,
T_10 * V_161 )
{
struct V_16 * V_16 = NULL ;
T_10 * V_225 ;
int V_227 = 0 , V_228 = 0 ;
bool V_229 = false , V_230 = false ;
for ( V_225 = V_161 ; V_225 < V_161 + V_31 ;
V_225 ++ , V_96 += V_159 ) {
T_10 V_226 = * V_225 ;
if ( F_177 ( V_226 ) || ( F_273 ( V_226 ) &&
F_269 ( F_270 ( V_226 ) ) ) ) {
if ( ! F_274 ( V_86 ) &&
++ V_227 <= V_64 ) {
continue;
} else {
V_228 = V_231 ;
goto V_83;
}
}
if ( ! F_273 ( V_226 ) ) {
V_228 = V_232 ;
goto V_83;
}
V_16 = F_275 ( V_86 , V_96 , V_226 ) ;
if ( F_67 ( ! V_16 ) ) {
V_228 = V_233 ;
goto V_83;
}
F_91 ( F_92 ( V_16 ) , V_16 ) ;
F_91 ( ! F_276 ( V_16 ) , V_16 ) ;
F_91 ( ! F_277 ( V_16 ) , V_16 ) ;
if ( ! F_195 ( V_16 ) ) {
V_228 = V_234 ;
goto V_83;
}
if ( F_278 ( V_16 ) != 1 + ! ! F_279 ( V_16 ) ) {
F_198 ( V_16 ) ;
V_228 = V_235 ;
goto V_83;
}
if ( F_280 ( V_226 ) ) {
V_230 = true ;
} else {
if ( F_279 ( V_16 ) &&
! F_281 ( V_16 , NULL ) ) {
F_198 ( V_16 ) ;
V_228 = V_236 ;
goto V_83;
}
}
if ( F_282 ( V_16 ) ) {
F_198 ( V_16 ) ;
V_228 = V_237 ;
goto V_83;
}
F_283 ( V_16 , V_224 + 0 ) ;
F_91 ( ! F_209 ( V_16 ) , V_16 ) ;
F_91 ( F_284 ( V_16 ) , V_16 ) ;
if ( F_285 ( V_226 ) ||
F_286 ( V_16 ) || F_287 ( V_16 ) ||
F_288 ( V_86 -> V_125 , V_96 ) )
V_229 = true ;
}
if ( F_17 ( V_230 ) ) {
if ( F_17 ( V_229 ) ) {
V_228 = V_238 ;
F_289 ( V_16 , V_227 ,
V_229 , V_230 , V_228 ) ;
return 1 ;
}
} else {
V_228 = V_239 ;
}
V_83:
F_268 ( V_161 , V_225 ) ;
F_289 ( V_16 , V_227 ,
V_229 , V_230 , V_228 ) ;
return 0 ;
}
static void F_290 ( T_10 * V_161 , struct V_16 * V_16 ,
struct V_85 * V_86 ,
unsigned long V_96 ,
T_8 * V_102 )
{
T_10 * V_225 ;
for ( V_225 = V_161 ; V_225 < V_161 + V_31 ; V_225 ++ ) {
T_10 V_226 = * V_225 ;
struct V_16 * V_146 ;
if ( F_177 ( V_226 ) || F_269 ( F_270 ( V_226 ) ) ) {
F_291 ( V_16 , V_96 ) ;
F_112 ( V_86 -> V_125 , V_110 , 1 ) ;
if ( F_269 ( F_270 ( V_226 ) ) ) {
F_185 ( V_102 ) ;
F_292 ( V_86 -> V_125 , V_96 , V_225 ) ;
F_101 ( V_102 ) ;
}
} else {
V_146 = F_271 ( V_226 ) ;
F_167 ( V_16 , V_146 , V_96 , V_86 ) ;
F_91 ( F_215 ( V_146 ) != 1 , V_146 ) ;
F_265 ( V_146 ) ;
F_185 ( V_102 ) ;
F_292 ( V_86 -> V_125 , V_96 , V_225 ) ;
F_181 ( V_146 , false ) ;
F_101 ( V_102 ) ;
F_293 ( V_146 ) ;
}
V_96 += V_159 ;
V_16 ++ ;
}
}
static void F_294 ( void )
{
F_295 ( V_240 ) ;
F_296 ( & V_15 , & V_240 ) ;
F_297 (
F_298 ( V_58 ) ) ;
F_299 ( & V_15 , & V_240 ) ;
}
static bool F_300 ( int V_241 )
{
int V_153 ;
if ( ! V_242 )
return false ;
if ( V_243 [ V_241 ] )
return false ;
for ( V_153 = 0 ; V_153 < V_244 ; V_153 ++ ) {
if ( ! V_243 [ V_153 ] )
continue;
if ( F_301 ( V_241 , V_153 ) > V_245 )
return true ;
}
return false ;
}
static int F_302 ( void )
{
static int V_246 = V_247 ;
int V_241 , V_248 = 0 , V_249 = 0 ;
for ( V_241 = 0 ; V_241 < V_244 ; V_241 ++ )
if ( V_243 [ V_241 ] > V_249 ) {
V_249 = V_243 [ V_241 ] ;
V_248 = V_241 ;
}
if ( V_248 <= V_246 )
for ( V_241 = V_246 + 1 ; V_241 < V_244 ;
V_241 ++ )
if ( V_249 == V_243 [ V_241 ] ) {
V_248 = V_241 ;
break;
}
V_246 = V_248 ;
return V_248 ;
}
static bool F_303 ( struct V_16 * * V_250 , bool * V_240 )
{
if ( F_10 ( * V_250 ) ) {
if ( ! * V_240 )
return false ;
* V_240 = false ;
* V_250 = NULL ;
F_294 () ;
} else if ( * V_250 ) {
F_94 ( * V_250 ) ;
* V_250 = NULL ;
}
return true ;
}
static struct V_16 *
F_304 ( struct V_16 * * V_250 , T_6 V_97 , struct V_94 * V_95 ,
unsigned long V_96 , int V_251 )
{
F_91 ( * V_250 , * V_250 ) ;
F_305 ( & V_95 -> V_223 ) ;
* V_250 = F_306 ( V_251 , V_97 , V_24 ) ;
if ( F_67 ( ! * V_250 ) ) {
F_21 ( V_252 ) ;
* V_250 = F_142 ( - V_68 ) ;
return NULL ;
}
F_87 ( * V_250 ) ;
F_21 ( V_253 ) ;
return * V_250 ;
}
static int F_302 ( void )
{
return 0 ;
}
static inline struct V_16 * F_307 ( void )
{
struct V_16 * V_16 ;
V_16 = F_20 ( F_115 () ,
V_24 ) ;
if ( V_16 )
F_87 ( V_16 ) ;
return V_16 ;
}
static struct V_16 * F_308 ( bool * V_240 )
{
struct V_16 * V_250 ;
do {
V_250 = F_307 () ;
if ( ! V_250 ) {
F_21 ( V_252 ) ;
if ( ! * V_240 )
return NULL ;
* V_240 = false ;
F_294 () ;
} else
F_21 ( V_253 ) ;
} while ( F_67 ( ! V_250 ) && F_17 ( F_8 () ) );
return V_250 ;
}
static bool F_303 ( struct V_16 * * V_250 , bool * V_240 )
{
if ( ! * V_250 )
* V_250 = F_308 ( V_240 ) ;
if ( F_67 ( ! * V_250 ) )
return false ;
return true ;
}
static struct V_16 *
F_304 ( struct V_16 * * V_250 , T_6 V_97 , struct V_94 * V_95 ,
unsigned long V_96 , int V_251 )
{
F_305 ( & V_95 -> V_223 ) ;
F_105 ( ! * V_250 ) ;
return * V_250 ;
}
static bool F_309 ( struct V_85 * V_86 )
{
if ( ( ! ( V_86 -> V_87 & V_114 ) && ! F_310 () ) ||
( V_86 -> V_87 & V_202 ) )
return false ;
if ( ! V_86 -> V_165 || V_86 -> V_222 )
return false ;
if ( F_311 ( V_86 ) )
return false ;
return ! ( V_86 -> V_87 & V_208 ) ;
}
static void F_312 ( struct V_94 * V_95 ,
unsigned long V_96 ,
struct V_16 * * V_250 ,
struct V_85 * V_86 ,
int V_251 )
{
T_4 * V_84 , V_131 ;
T_10 * V_161 ;
T_7 V_101 ;
struct V_16 * V_163 ;
T_8 * V_254 , * V_255 ;
int V_256 = 0 , V_228 = 0 ;
unsigned long V_220 , V_221 ;
struct V_99 * V_100 ;
unsigned long V_154 ;
unsigned long V_155 ;
T_6 V_97 ;
F_105 ( V_96 & ~ V_104 ) ;
V_97 = F_115 () | V_158 | V_257 ;
V_163 = F_304 ( V_250 , V_97 , V_95 , V_96 , V_251 ) ;
if ( ! V_163 ) {
V_228 = V_258 ;
goto V_259;
}
if ( F_67 ( F_93 ( V_163 , V_95 , V_97 , & V_100 , true ) ) ) {
V_228 = V_260 ;
goto V_259;
}
F_263 ( & V_95 -> V_223 ) ;
if ( F_67 ( F_253 ( V_95 ) ) ) {
V_228 = V_261 ;
goto V_83;
}
V_86 = F_313 ( V_95 , V_96 ) ;
if ( ! V_86 ) {
V_228 = V_262 ;
goto V_83;
}
V_220 = ( V_86 -> V_117 + ~ V_104 ) & V_104 ;
V_221 = V_86 -> V_119 & V_104 ;
if ( V_96 < V_220 || V_96 + V_118 > V_221 ) {
V_228 = V_263 ;
goto V_83;
}
if ( ! F_309 ( V_86 ) ) {
V_228 = V_264 ;
goto V_83;
}
V_84 = F_314 ( V_95 , V_96 ) ;
if ( ! V_84 ) {
V_228 = V_265 ;
goto V_83;
}
F_315 ( V_86 -> V_165 ) ;
V_161 = F_176 ( V_84 , V_96 ) ;
V_255 = F_316 ( V_95 , V_84 ) ;
V_154 = V_96 ;
V_155 = V_96 + V_118 ;
F_169 ( V_95 , V_154 , V_155 ) ;
V_254 = F_99 ( V_95 , V_84 ) ;
V_131 = F_317 ( V_86 , V_96 , V_84 ) ;
F_101 ( V_254 ) ;
F_182 ( V_95 , V_154 , V_155 ) ;
F_185 ( V_255 ) ;
V_256 = F_272 ( V_86 , V_96 , V_161 ) ;
F_101 ( V_255 ) ;
if ( F_67 ( ! V_256 ) ) {
F_179 ( V_161 ) ;
F_185 ( V_254 ) ;
F_29 ( ! F_100 ( * V_84 ) ) ;
F_172 ( V_95 , V_84 , F_318 ( V_131 ) ) ;
F_101 ( V_254 ) ;
F_319 ( V_86 -> V_165 ) ;
V_228 = V_266 ;
goto V_83;
}
F_319 ( V_86 -> V_165 ) ;
F_290 ( V_161 , V_163 , V_86 , V_96 , V_255 ) ;
F_179 ( V_161 ) ;
F_98 ( V_163 ) ;
V_101 = F_318 ( V_131 ) ;
V_131 = F_83 ( V_163 , V_86 -> V_109 ) ;
V_131 = F_81 ( F_106 ( V_131 ) , V_86 ) ;
F_180 () ;
F_185 ( V_254 ) ;
F_29 ( ! F_100 ( * V_84 ) ) ;
F_107 ( V_163 , V_86 , V_96 , true ) ;
F_108 ( V_163 , V_100 , false , true ) ;
F_109 ( V_163 , V_86 ) ;
F_110 ( V_95 , V_84 , V_101 ) ;
F_111 ( V_95 , V_96 , V_84 , V_131 ) ;
F_129 ( V_86 , V_96 , V_84 ) ;
F_101 ( V_254 ) ;
* V_250 = NULL ;
V_61 ++ ;
V_228 = V_238 ;
V_267:
F_264 ( & V_95 -> V_223 ) ;
F_320 ( V_95 , V_256 , V_228 ) ;
return;
V_259:
F_320 ( V_95 , V_256 , V_228 ) ;
return;
V_83:
F_96 ( V_163 , V_100 , true ) ;
goto V_267;
}
static int F_321 ( struct V_94 * V_95 ,
struct V_85 * V_86 ,
unsigned long V_96 ,
struct V_16 * * V_250 )
{
T_4 * V_84 ;
T_10 * V_161 , * V_225 ;
int V_46 = 0 , V_227 = 0 , V_228 = 0 ;
struct V_16 * V_16 = NULL ;
unsigned long V_268 ;
T_8 * V_102 ;
int V_251 = V_247 ;
bool V_230 = false , V_229 = false ;
F_105 ( V_96 & ~ V_104 ) ;
V_84 = F_314 ( V_95 , V_96 ) ;
if ( ! V_84 ) {
V_228 = V_265 ;
goto V_83;
}
memset ( V_243 , 0 , sizeof( V_243 ) ) ;
V_161 = F_322 ( V_95 , V_84 , V_96 , & V_102 ) ;
for ( V_268 = V_96 , V_225 = V_161 ; V_225 < V_161 + V_31 ;
V_225 ++ , V_268 += V_159 ) {
T_10 V_226 = * V_225 ;
if ( F_177 ( V_226 ) || F_269 ( F_270 ( V_226 ) ) ) {
if ( ! F_274 ( V_86 ) &&
++ V_227 <= V_64 ) {
continue;
} else {
V_228 = V_231 ;
goto V_269;
}
}
if ( ! F_273 ( V_226 ) ) {
V_228 = V_232 ;
goto V_269;
}
if ( F_280 ( V_226 ) )
V_230 = true ;
V_16 = F_275 ( V_86 , V_268 , V_226 ) ;
if ( F_67 ( ! V_16 ) ) {
V_228 = V_233 ;
goto V_269;
}
if ( F_92 ( V_16 ) ) {
V_228 = V_270 ;
goto V_269;
}
V_251 = F_163 ( V_16 ) ;
if ( F_300 ( V_251 ) ) {
V_228 = V_271 ;
goto V_269;
}
V_243 [ V_251 ] ++ ;
if ( ! F_284 ( V_16 ) ) {
V_228 = V_272 ;
goto V_269;
}
if ( F_209 ( V_16 ) ) {
V_228 = V_234 ;
goto V_269;
}
if ( ! F_276 ( V_16 ) ) {
V_228 = V_273 ;
goto V_269;
}
if ( F_278 ( V_16 ) != 1 + ! ! F_279 ( V_16 ) ) {
V_228 = V_235 ;
goto V_269;
}
if ( F_285 ( V_226 ) ||
F_286 ( V_16 ) || F_287 ( V_16 ) ||
F_288 ( V_86 -> V_125 , V_96 ) )
V_229 = true ;
}
if ( V_230 ) {
if ( V_229 ) {
V_228 = V_238 ;
V_46 = 1 ;
} else {
V_228 = V_274 ;
}
} else {
V_228 = V_239 ;
}
V_269:
F_323 ( V_161 , V_102 ) ;
if ( V_46 ) {
V_251 = F_302 () ;
F_312 ( V_95 , V_96 , V_250 , V_86 , V_251 ) ;
}
V_83:
F_324 ( V_95 , V_16 , V_230 , V_229 ,
V_227 , V_228 ) ;
return V_46 ;
}
static void F_325 ( struct V_211 * V_211 )
{
struct V_94 * V_95 = V_211 -> V_95 ;
F_105 ( V_275 != 1 && ! F_326 ( & V_217 ) ) ;
if ( F_253 ( V_95 ) ) {
F_260 ( & V_211 -> V_213 ) ;
F_261 ( & V_211 -> V_218 ) ;
F_247 ( V_211 ) ;
F_262 ( V_95 ) ;
}
}
static unsigned int F_327 ( unsigned int V_60 ,
struct V_16 * * V_250 )
__releases( &khugepaged_mm_lock
static int F_328 ( void )
{
return ! F_13 ( & V_13 . V_14 ) &&
F_8 () ;
}
static int F_329 ( void )
{
return ! F_13 ( & V_13 . V_14 ) ||
F_330 () ;
}
static void F_331 ( void )
{
struct V_16 * V_250 = NULL ;
unsigned int V_276 = 0 , V_277 = 0 ;
unsigned int V_60 = V_59 ;
bool V_240 = true ;
F_332 () ;
while ( V_276 < V_60 ) {
if ( ! F_303 ( & V_250 , & V_240 ) )
break;
F_168 () ;
if ( F_67 ( F_330 () || F_333 () ) )
break;
F_185 ( & V_217 ) ;
if ( ! V_13 . V_211 )
V_277 ++ ;
if ( F_328 () &&
V_277 < 2 )
V_276 += F_327 ( V_60 - V_276 ,
& V_250 ) ;
else
V_276 = V_60 ;
F_101 ( & V_217 ) ;
}
if ( ! F_334 ( V_250 ) )
F_94 ( V_250 ) ;
}
static void F_335 ( void )
{
if ( F_328 () ) {
if ( ! V_55 )
return;
F_336 ( V_15 ,
F_330 () ,
F_298 ( V_55 ) ) ;
return;
}
if ( F_8 () )
F_337 ( V_15 , F_329 () ) ;
}
static int V_11 ( void * V_278 )
{
struct V_211 * V_211 ;
F_338 () ;
F_339 ( V_279 , V_280 ) ;
while ( ! F_330 () ) {
F_331 () ;
F_335 () ;
}
F_185 ( & V_217 ) ;
V_211 = V_13 . V_211 ;
V_13 . V_211 = NULL ;
if ( V_211 )
F_325 ( V_211 ) ;
F_101 ( & V_217 ) ;
return 0 ;
}
static void F_340 ( struct V_85 * V_86 ,
unsigned long V_103 , T_4 * V_84 )
{
struct V_94 * V_95 = V_86 -> V_125 ;
T_7 V_101 ;
T_4 V_131 ;
int V_153 ;
F_170 ( V_86 , V_103 , V_84 ) ;
V_101 = F_171 ( V_95 , V_84 ) ;
F_172 ( V_95 , & V_131 , V_101 ) ;
for ( V_153 = 0 ; V_153 < V_31 ; V_153 ++ , V_103 += V_159 ) {
T_10 * V_161 , V_90 ;
V_90 = F_341 ( F_342 ( V_103 ) , V_86 -> V_109 ) ;
V_90 = F_343 ( V_90 ) ;
V_161 = F_176 ( & V_131 , V_103 ) ;
F_105 ( ! F_177 ( * V_161 ) ) ;
F_178 ( V_95 , V_103 , V_161 , V_90 ) ;
F_179 ( V_161 ) ;
}
F_180 () ;
F_172 ( V_95 , V_84 , V_101 ) ;
F_28 () ;
}
static void F_344 ( struct V_85 * V_86 , T_4 * V_84 ,
unsigned long V_103 , bool V_281 )
{
struct V_94 * V_95 = V_86 -> V_125 ;
struct V_16 * V_16 ;
T_7 V_101 ;
T_4 V_131 ;
bool V_282 , V_124 , V_151 ;
unsigned long V_122 ;
int V_153 ;
F_105 ( V_103 & ~ V_104 ) ;
F_184 ( V_86 -> V_117 > V_103 , V_86 ) ;
F_184 ( V_86 -> V_119 < V_103 + V_118 , V_86 ) ;
F_105 ( ! F_150 ( * V_84 ) && ! F_141 ( * V_84 ) ) ;
F_21 ( V_283 ) ;
if ( F_148 ( V_86 ) ) {
T_4 V_131 = F_170 ( V_86 , V_103 , V_84 ) ;
if ( F_151 ( V_131 ) )
F_28 () ;
return;
} else if ( F_151 ( * V_84 ) ) {
return F_340 ( V_86 , V_103 , V_84 ) ;
}
V_16 = F_152 ( * V_84 ) ;
F_91 ( ! F_278 ( V_16 ) , V_16 ) ;
F_345 ( V_16 , V_31 - 1 ) ;
V_124 = F_139 ( * V_84 ) ;
V_282 = F_221 ( * V_84 ) ;
V_151 = F_222 ( * V_84 ) ;
F_346 ( V_86 , V_103 , V_84 ) ;
V_101 = F_171 ( V_95 , V_84 ) ;
F_172 ( V_95 , & V_131 , V_101 ) ;
for ( V_153 = 0 , V_122 = V_103 ; V_153 < V_31 ; V_153 ++ , V_122 += V_159 ) {
T_10 V_90 , * V_161 ;
if ( V_281 ) {
T_11 V_284 ;
V_284 = F_347 ( V_16 + V_153 , V_124 ) ;
V_90 = F_348 ( V_284 ) ;
} else {
V_90 = F_173 ( V_16 + V_153 , V_86 -> V_109 ) ;
V_90 = F_174 ( V_90 , V_86 ) ;
if ( ! V_124 )
V_90 = F_349 ( V_90 ) ;
if ( ! V_282 )
V_90 = F_350 ( V_90 ) ;
}
if ( V_151 )
F_351 ( V_16 + V_153 ) ;
V_161 = F_176 ( & V_131 , V_122 ) ;
F_29 ( ! F_177 ( * V_161 ) ) ;
F_178 ( V_95 , V_122 , V_161 , V_90 ) ;
F_258 ( & V_16 [ V_153 ] . V_285 ) ;
F_179 ( V_161 ) ;
}
if ( F_193 ( V_16 ) > 1 && ! F_352 ( V_16 ) ) {
for ( V_153 = 0 ; V_153 < V_31 ; V_153 ++ )
F_258 ( & V_16 [ V_153 ] . V_285 ) ;
}
if ( F_353 ( - 1 , F_354 ( V_16 ) ) ) {
F_355 ( V_16 , V_286 ) ;
if ( F_356 ( V_16 ) ) {
for ( V_153 = 0 ; V_153 < V_31 ; V_153 ++ )
F_357 ( & V_16 [ V_153 ] . V_285 ) ;
}
}
F_180 () ;
F_358 ( V_86 , V_103 , V_84 ) ;
F_172 ( V_95 , V_84 , V_101 ) ;
if ( V_281 ) {
for ( V_153 = 0 ; V_153 < V_31 ; V_153 ++ ) {
F_181 ( V_16 + V_153 , false ) ;
F_94 ( V_16 + V_153 ) ;
}
}
}
void F_359 ( struct V_85 * V_86 , T_4 * V_84 ,
unsigned long V_96 , bool V_281 )
{
T_8 * V_102 ;
struct V_94 * V_95 = V_86 -> V_125 ;
unsigned long V_103 = V_96 & V_104 ;
F_169 ( V_95 , V_103 , V_103 + V_118 ) ;
V_102 = F_99 ( V_95 , V_84 ) ;
if ( F_150 ( * V_84 ) ) {
struct V_16 * V_16 = F_152 ( * V_84 ) ;
if ( F_360 ( V_16 ) )
F_361 ( V_16 ) ;
} else if ( ! F_141 ( * V_84 ) )
goto V_83;
F_344 ( V_86 , V_84 , V_103 , V_281 ) ;
V_83:
F_101 ( V_102 ) ;
F_182 ( V_95 , V_103 , V_103 + V_118 ) ;
}
void F_362 ( struct V_85 * V_86 , unsigned long V_96 ,
bool V_281 , struct V_16 * V_16 )
{
T_12 * V_287 ;
T_13 * V_288 ;
T_4 * V_84 ;
V_287 = F_363 ( V_86 -> V_125 , V_96 ) ;
if ( ! F_364 ( * V_287 ) )
return;
V_288 = F_365 ( V_287 , V_96 ) ;
if ( ! F_366 ( * V_288 ) )
return;
V_84 = F_367 ( V_288 , V_96 ) ;
if ( ! F_140 ( * V_84 ) || ( ! F_150 ( * V_84 ) && ! F_141 ( * V_84 ) ) )
return;
F_105 ( V_281 && ! V_16 ) ;
if ( V_16 && V_16 != F_152 ( * V_84 ) )
return;
F_359 ( V_86 , V_84 , V_96 , V_281 ) ;
}
void F_368 ( struct V_85 * V_86 ,
unsigned long V_289 ,
unsigned long V_290 ,
long V_291 )
{
if ( V_289 & ~ V_104 &&
( V_289 & V_104 ) >= V_86 -> V_117 &&
( V_289 & V_104 ) + V_118 <= V_86 -> V_119 )
F_362 ( V_86 , V_289 , false , NULL ) ;
if ( V_290 & ~ V_104 &&
( V_290 & V_104 ) >= V_86 -> V_117 &&
( V_290 & V_104 ) + V_118 <= V_86 -> V_119 )
F_362 ( V_86 , V_290 , false , NULL ) ;
if ( V_291 > 0 ) {
struct V_85 * V_191 = V_86 -> V_292 ;
unsigned long V_293 = V_191 -> V_117 ;
V_293 += V_291 << V_6 ;
if ( V_293 & ~ V_104 &&
( V_293 & V_104 ) >= V_191 -> V_117 &&
( V_293 & V_104 ) + V_118 <= V_191 -> V_119 )
F_362 ( V_191 , V_293 , false , NULL ) ;
}
}
static void F_369 ( struct V_16 * V_16 )
{
enum V_294 V_294 = V_295 | V_296 |
V_297 | V_298 ;
int V_153 , V_46 ;
F_91 ( ! F_153 ( V_16 ) , V_16 ) ;
V_46 = F_370 ( V_16 , V_294 | V_299 ) ;
for ( V_153 = 1 ; ! V_46 && V_153 < V_31 ; V_153 ++ ) {
if ( F_278 ( V_16 ) == 1 )
return;
V_46 = F_370 ( V_16 + V_153 , V_294 ) ;
}
F_105 ( V_46 ) ;
}
static void F_371 ( struct V_16 * V_16 )
{
int V_153 ;
for ( V_153 = 0 ; V_153 < V_31 ; V_153 ++ )
F_372 ( V_16 + V_153 , V_16 + V_153 , true ) ;
}
static void F_373 ( struct V_16 * V_300 , int V_301 ,
struct V_302 * V_302 , struct V_91 * V_303 )
{
struct V_16 * V_304 = V_300 + V_301 ;
F_91 ( F_32 ( & V_304 -> V_285 ) != - 1 , V_304 ) ;
F_91 ( F_374 ( V_304 ) != 0 , V_304 ) ;
F_375 ( V_304 ) ;
V_304 -> V_98 &= ~ V_305 ;
V_304 -> V_98 |= ( V_300 -> V_98 &
( ( 1L << V_306 ) |
( 1L << V_307 ) |
( 1L << V_308 ) |
( 1L << V_309 ) |
( 1L << V_310 ) |
( 1L << V_311 ) |
( 1L << V_312 ) |
( 1L << V_313 ) ) ) ;
F_180 () ;
F_376 ( V_304 ) ;
if ( F_286 ( V_300 ) )
F_377 ( V_304 ) ;
if ( F_378 ( V_300 ) )
F_379 ( V_304 ) ;
F_91 ( V_301 > 2 && V_304 -> V_92 != V_314 ,
V_304 ) ;
V_304 -> V_92 = V_300 -> V_92 ;
V_304 -> V_315 = V_300 -> V_315 + V_301 ;
F_380 ( V_304 , F_204 ( V_300 ) ) ;
F_381 ( V_300 , V_304 , V_302 , V_303 ) ;
}
static void F_382 ( struct V_16 * V_16 , struct V_91 * V_303 )
{
struct V_16 * V_300 = F_383 ( V_16 ) ;
struct V_1 * V_1 = F_384 ( V_300 ) ;
struct V_302 * V_302 ;
int V_153 ;
F_385 ( & V_1 -> V_316 ) ;
V_302 = F_386 ( V_300 , V_1 ) ;
F_387 ( V_300 ) ;
for ( V_153 = V_31 - 1 ; V_153 >= 1 ; V_153 -- )
F_373 ( V_300 , V_153 , V_302 , V_303 ) ;
F_388 ( V_300 ) ;
F_389 ( & V_1 -> V_316 ) ;
F_371 ( V_300 ) ;
for ( V_153 = 0 ; V_153 < V_31 ; V_153 ++ ) {
struct V_16 * V_317 = V_300 + V_153 ;
if ( V_317 == V_16 )
continue;
F_198 ( V_317 ) ;
F_94 ( V_317 ) ;
}
}
int F_390 ( struct V_16 * V_16 )
{
int V_153 , V_46 ;
F_91 ( F_391 ( V_16 ) , V_16 ) ;
if ( F_17 ( ! F_92 ( V_16 ) ) )
return F_32 ( & V_16 -> V_285 ) + 1 ;
V_46 = F_193 ( V_16 ) ;
if ( F_392 ( V_16 ) )
return V_46 ;
for ( V_153 = 0 ; V_153 < V_31 ; V_153 ++ )
V_46 += F_32 ( & V_16 [ V_153 ] . V_285 ) + 1 ;
if ( F_194 ( V_16 ) )
V_46 -= V_31 ;
return V_46 ;
}
int F_186 ( struct V_16 * V_16 , int * F_390 )
{
int V_153 , V_46 , V_318 , V_319 ;
F_91 ( F_392 ( V_16 ) , V_16 ) ;
if ( F_17 ( ! F_393 ( V_16 ) ) ) {
V_319 = F_32 ( & V_16 -> V_285 ) + 1 ;
if ( F_390 )
* F_390 = V_319 ;
return V_319 ;
}
V_16 = F_383 ( V_16 ) ;
V_318 = V_46 = 0 ;
for ( V_153 = 0 ; V_153 < V_31 ; V_153 ++ ) {
V_319 = F_32 ( & V_16 [ V_153 ] . V_285 ) + 1 ;
V_46 = F_394 ( V_46 , V_319 ) ;
V_318 += V_319 ;
}
if ( F_194 ( V_16 ) ) {
V_46 -= 1 ;
V_318 -= V_31 ;
}
V_319 = F_193 ( V_16 ) ;
V_46 += V_319 ;
V_318 += V_319 ;
if ( F_390 )
* F_390 = V_318 ;
return V_46 ;
}
int F_395 ( struct V_16 * V_16 , struct V_91 * V_303 )
{
struct V_16 * V_300 = F_383 ( V_16 ) ;
struct V_320 * V_321 = F_396 ( F_163 ( V_300 ) ) ;
struct V_165 * V_165 ;
int V_37 , V_319 , V_46 ;
bool V_322 ;
unsigned long V_98 ;
F_91 ( F_203 ( V_16 ) , V_16 ) ;
F_91 ( ! F_276 ( V_16 ) , V_16 ) ;
F_91 ( ! F_209 ( V_16 ) , V_16 ) ;
F_91 ( ! F_277 ( V_16 ) , V_16 ) ;
F_91 ( ! F_92 ( V_16 ) , V_16 ) ;
V_165 = F_397 ( V_300 ) ;
if ( ! V_165 ) {
V_46 = - V_323 ;
goto V_83;
}
F_315 ( V_165 ) ;
if ( F_390 ( V_300 ) != F_278 ( V_300 ) - 1 ) {
V_46 = - V_323 ;
goto V_149;
}
V_322 = F_360 ( V_16 ) ;
F_369 ( V_300 ) ;
F_91 ( F_193 ( V_300 ) , V_300 ) ;
if ( V_322 )
F_196 () ;
F_398 ( & V_321 -> V_324 , V_98 ) ;
V_37 = F_278 ( V_300 ) ;
V_319 = F_390 ( V_300 ) ;
if ( ! V_319 && V_37 == 1 ) {
if ( ! F_13 ( F_86 ( V_300 ) ) ) {
V_321 -> V_325 -- ;
F_261 ( F_86 ( V_300 ) ) ;
}
F_399 ( & V_321 -> V_324 , V_98 ) ;
F_382 ( V_16 , V_303 ) ;
V_46 = 0 ;
} else if ( F_400 ( V_326 ) && V_319 ) {
F_399 ( & V_321 -> V_324 , V_98 ) ;
F_401 ( L_22 ,
V_319 , V_37 ) ;
if ( F_391 ( V_16 ) )
F_402 ( V_300 , NULL ) ;
F_402 ( V_16 , L_23 ) ;
F_403 () ;
} else {
F_399 ( & V_321 -> V_324 , V_98 ) ;
F_371 ( V_300 ) ;
V_46 = - V_323 ;
}
V_149:
F_319 ( V_165 ) ;
F_404 ( V_165 ) ;
V_83:
F_21 ( ! V_46 ? V_327 : V_328 ) ;
return V_46 ;
}
void F_405 ( struct V_16 * V_16 )
{
struct V_320 * V_321 = F_396 ( F_163 ( V_16 ) ) ;
unsigned long V_98 ;
F_398 ( & V_321 -> V_324 , V_98 ) ;
if ( ! F_13 ( F_86 ( V_16 ) ) ) {
V_321 -> V_325 -- ;
F_261 ( F_86 ( V_16 ) ) ;
}
F_399 ( & V_321 -> V_324 , V_98 ) ;
F_406 ( V_16 ) ;
}
void F_407 ( struct V_16 * V_16 )
{
struct V_320 * V_321 = F_396 ( F_163 ( V_16 ) ) ;
unsigned long V_98 ;
F_91 ( ! F_408 ( V_16 ) , V_16 ) ;
F_398 ( & V_321 -> V_324 , V_98 ) ;
if ( F_13 ( F_86 ( V_16 ) ) ) {
F_21 ( V_329 ) ;
F_257 ( F_86 ( V_16 ) , & V_321 -> V_330 ) ;
V_321 -> V_325 ++ ;
}
F_399 ( & V_321 -> V_324 , V_98 ) ;
}
static unsigned long F_409 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_320 * V_321 = F_396 ( V_30 -> V_241 ) ;
return F_410 ( V_321 -> V_325 ) ;
}
static unsigned long F_411 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_320 * V_321 = F_396 ( V_30 -> V_241 ) ;
unsigned long V_98 ;
F_412 ( V_303 ) , * V_331 , * V_191 ;
struct V_16 * V_16 ;
int V_332 = 0 ;
F_398 ( & V_321 -> V_324 , V_98 ) ;
F_413 (pos, next, &pgdata->split_queue) {
V_16 = F_414 ( ( void * ) V_331 , struct V_16 , V_92 ) ;
V_16 = F_383 ( V_16 ) ;
if ( F_415 ( V_16 ) ) {
F_416 ( F_86 ( V_16 ) , & V_303 ) ;
} else {
F_417 ( F_86 ( V_16 ) ) ;
V_321 -> V_325 -- ;
}
if ( ! -- V_30 -> V_333 )
break;
}
F_399 ( & V_321 -> V_324 , V_98 ) ;
F_413 (pos, next, &list) {
V_16 = F_414 ( ( void * ) V_331 , struct V_16 , V_92 ) ;
F_418 ( V_16 ) ;
if ( ! F_216 ( V_16 ) )
V_332 ++ ;
F_198 ( V_16 ) ;
F_94 ( V_16 ) ;
}
F_398 ( & V_321 -> V_324 , V_98 ) ;
F_419 ( & V_303 , & V_321 -> V_330 ) ;
F_399 ( & V_321 -> V_324 , V_98 ) ;
if ( ! V_332 && F_13 ( & V_321 -> V_330 ) )
return V_334 ;
return V_332 ;
}
static int F_420 ( void * V_335 , T_14 V_336 )
{
struct V_1 * V_1 ;
struct V_16 * V_16 ;
unsigned long V_123 , V_337 ;
unsigned long V_338 = 0 , V_332 = 0 ;
if ( V_336 != 1 )
return - V_42 ;
F_2 (zone) {
V_337 = F_421 ( V_1 ) ;
for ( V_123 = V_1 -> V_339 ; V_123 < V_337 ; V_123 ++ ) {
if ( ! F_422 ( V_123 ) )
continue;
V_16 = F_144 ( V_123 ) ;
if ( ! F_415 ( V_16 ) )
continue;
if ( V_1 != F_384 ( V_16 ) )
goto V_191;
if ( ! F_153 ( V_16 ) || ! F_276 ( V_16 ) ||
F_392 ( V_16 ) )
goto V_191;
V_338 ++ ;
F_418 ( V_16 ) ;
if ( ! F_216 ( V_16 ) )
V_332 ++ ;
F_198 ( V_16 ) ;
V_191:
F_94 ( V_16 ) ;
}
}
F_5 ( L_24 , V_332 , V_338 ) ;
return 0 ;
}
static int T_3 F_423 ( void )
{
void * V_46 ;
V_46 = F_424 ( L_25 , 0200 , NULL , NULL ,
& V_340 ) ;
if ( ! V_46 )
F_80 ( L_26 ) ;
return 0 ;
}
