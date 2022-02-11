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
V_58 = 0 ;
F_14 ( & V_15 ) ;
return V_37 ;
}
static T_1 F_55 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_16 , V_59 ) ;
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
V_59 = V_56 ;
V_58 = 0 ;
F_14 ( & V_15 ) ;
return V_37 ;
}
static T_1 F_57 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_16 , V_60 ) ;
}
static T_1 F_58 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_2 V_37 )
{
int V_9 ;
unsigned long V_61 ;
V_9 = F_46 ( V_36 , 10 , & V_61 ) ;
if ( V_9 || ! V_61 || V_61 > V_57 )
return - V_42 ;
V_60 = V_61 ;
return V_37 ;
}
static T_1 F_59 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_16 , V_62 ) ;
}
static T_1 F_60 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_16 , V_63 ) ;
}
static T_1 F_61 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 )
{
return F_44 ( V_33 , V_35 , V_36 ,
V_64 ) ;
}
static T_1 F_62 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_2 V_37 )
{
return F_45 ( V_33 , V_35 , V_36 , V_37 ,
V_64 ) ;
}
static T_1 F_63 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_16 , V_65 ) ;
}
static T_1 F_64 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_2 V_37 )
{
int V_9 ;
unsigned long V_66 ;
V_9 = F_46 ( V_36 , 10 , & V_66 ) ;
if ( V_9 || V_66 > V_31 - 1 )
return - V_42 ;
V_65 = V_66 ;
return V_37 ;
}
static int T_3 F_65 ( struct V_32 * * V_67 )
{
int V_9 ;
* V_67 = F_66 ( L_17 , V_68 ) ;
if ( F_67 ( ! * V_67 ) ) {
F_11 ( L_18 ) ;
return - V_69 ;
}
V_9 = F_68 ( * V_67 , & V_70 ) ;
if ( V_9 ) {
F_11 ( L_19 ) ;
goto V_71;
}
V_9 = F_68 ( * V_67 , & V_72 ) ;
if ( V_9 ) {
F_11 ( L_19 ) ;
goto V_73;
}
return 0 ;
V_73:
F_69 ( * V_67 , & V_70 ) ;
V_71:
F_70 ( * V_67 ) ;
return V_9 ;
}
static void T_3 F_71 ( struct V_32 * V_67 )
{
F_69 ( V_67 , & V_72 ) ;
F_69 ( V_67 , & V_70 ) ;
F_70 ( V_67 ) ;
}
static inline int F_65 ( struct V_32 * * V_67 )
{
return 0 ;
}
static inline void F_71 ( struct V_32 * V_67 )
{
}
static int T_3 F_72 ( void )
{
int V_9 ;
struct V_32 * V_67 ;
if ( ! F_73 () ) {
V_43 = 0 ;
return - V_42 ;
}
V_60 = V_31 * 8 ;
V_65 = V_31 - 1 ;
F_74 ( V_24 >= V_74 ) ;
F_74 ( V_24 < 2 ) ;
V_9 = F_65 ( & V_67 ) ;
if ( V_9 )
goto V_75;
V_9 = F_75 () ;
if ( V_9 )
goto V_76;
V_9 = F_76 ( & V_77 ) ;
if ( V_9 )
goto V_78;
V_9 = F_76 ( & V_79 ) ;
if ( V_9 )
goto V_80;
if ( V_81 < ( 512 << ( 20 - V_6 ) ) ) {
V_43 = 0 ;
return 0 ;
}
V_9 = F_7 () ;
if ( V_9 )
goto V_82;
return 0 ;
V_82:
F_77 ( & V_79 ) ;
V_80:
F_77 ( & V_77 ) ;
V_78:
F_78 () ;
V_76:
F_71 ( V_67 ) ;
V_75:
return V_9 ;
}
static int T_3 F_79 ( char * V_83 )
{
int V_46 = 0 ;
if ( ! V_83 )
goto V_84;
if ( ! strcmp ( V_83 , L_5 ) ) {
F_38 ( V_44 ,
& V_43 ) ;
F_37 ( V_45 ,
& V_43 ) ;
V_46 = 1 ;
} else if ( ! strcmp ( V_83 , L_6 ) ) {
F_37 ( V_44 ,
& V_43 ) ;
F_38 ( V_45 ,
& V_43 ) ;
V_46 = 1 ;
} else if ( ! strcmp ( V_83 , L_7 ) ) {
F_37 ( V_44 ,
& V_43 ) ;
F_37 ( V_45 ,
& V_43 ) ;
V_46 = 1 ;
}
V_84:
if ( ! V_46 )
F_80 ( L_20 ) ;
return V_46 ;
}
T_4 F_81 ( T_4 V_85 , struct V_86 * V_87 )
{
if ( F_17 ( V_87 -> V_88 & V_89 ) )
V_85 = F_82 ( V_85 ) ;
return V_85 ;
}
static inline T_4 F_83 ( struct V_16 * V_16 , T_5 V_90 )
{
return F_84 ( F_85 ( V_16 , V_90 ) ) ;
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
struct V_86 * V_87 ,
unsigned long V_96 , T_4 * V_85 ,
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
V_102 = F_99 ( V_95 , V_85 ) ;
if ( F_67 ( ! F_100 ( * V_85 ) ) ) {
F_101 ( V_102 ) ;
F_96 ( V_16 , V_100 , true ) ;
F_94 ( V_16 ) ;
F_102 ( V_95 , V_101 ) ;
} else {
T_4 V_108 ;
if ( F_103 ( V_87 ) ) {
int V_46 ;
F_101 ( V_102 ) ;
F_96 ( V_16 , V_100 , true ) ;
F_94 ( V_16 ) ;
F_102 ( V_95 , V_101 ) ;
V_46 = F_104 ( V_87 , V_96 , V_98 ,
V_109 ) ;
F_105 ( V_46 & V_106 ) ;
return V_46 ;
}
V_108 = F_83 ( V_16 , V_87 -> V_110 ) ;
V_108 = F_81 ( F_106 ( V_108 ) , V_87 ) ;
F_107 ( V_16 , V_87 , V_103 , true ) ;
F_108 ( V_16 , V_100 , false , true ) ;
F_109 ( V_16 , V_87 ) ;
F_110 ( V_95 , V_85 , V_101 ) ;
F_111 ( V_95 , V_103 , V_85 , V_108 ) ;
F_112 ( V_95 , V_111 , V_31 ) ;
F_113 ( & V_95 -> V_112 ) ;
F_101 ( V_102 ) ;
F_21 ( V_113 ) ;
}
return 0 ;
}
static inline T_6 F_114 ( struct V_86 * V_87 )
{
T_6 V_114 = 0 ;
if ( F_40 ( V_52 , & V_43 ) &&
( V_87 -> V_88 & V_115 ) )
V_114 = V_116 ;
else if ( F_40 ( V_51 , & V_43 ) )
V_114 = V_117 ;
else if ( F_40 ( V_50 , & V_43 ) )
V_114 = V_116 ;
return V_21 | V_114 ;
}
static inline T_6 F_115 ( void )
{
return V_21 | ( F_116 () ? V_116 : 0 ) ;
}
static bool F_117 ( T_7 V_101 , struct V_94 * V_95 ,
struct V_86 * V_87 , unsigned long V_103 , T_4 * V_85 ,
struct V_16 * V_17 )
{
T_4 V_108 ;
if ( ! F_100 ( * V_85 ) )
return false ;
V_108 = F_85 ( V_17 , V_87 -> V_110 ) ;
V_108 = F_84 ( V_108 ) ;
if ( V_101 )
F_110 ( V_95 , V_85 , V_101 ) ;
F_111 ( V_95 , V_103 , V_85 , V_108 ) ;
F_113 ( & V_95 -> V_112 ) ;
return true ;
}
int F_118 ( struct V_94 * V_95 , struct V_86 * V_87 ,
unsigned long V_96 , T_4 * V_85 ,
unsigned int V_98 )
{
T_6 V_97 ;
struct V_16 * V_16 ;
unsigned long V_103 = V_96 & V_104 ;
if ( V_103 < V_87 -> V_118 || V_103 + V_119 > V_87 -> V_120 )
return V_106 ;
if ( F_67 ( F_119 ( V_87 ) ) )
return V_107 ;
if ( F_67 ( F_120 ( V_87 , V_87 -> V_88 ) ) )
return V_107 ;
if ( ! ( V_98 & V_121 ) && ! F_121 ( V_95 ) &&
F_122 () ) {
T_8 * V_102 ;
T_7 V_101 ;
struct V_16 * V_17 ;
bool V_122 ;
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
V_102 = F_99 ( V_95 , V_85 ) ;
V_46 = 0 ;
V_122 = false ;
if ( F_100 ( * V_85 ) ) {
if ( F_103 ( V_87 ) ) {
F_101 ( V_102 ) ;
V_46 = F_104 ( V_87 , V_96 , V_98 ,
V_109 ) ;
F_105 ( V_46 & V_106 ) ;
} else {
F_117 ( V_101 , V_95 , V_87 ,
V_103 , V_85 ,
V_17 ) ;
F_101 ( V_102 ) ;
V_122 = true ;
}
} else
F_101 ( V_102 ) ;
if ( ! V_122 ) {
F_102 ( V_95 , V_101 ) ;
F_28 () ;
}
return V_46 ;
}
V_97 = F_114 ( V_87 ) ;
V_16 = F_123 ( V_97 , V_87 , V_103 , V_24 ) ;
if ( F_67 ( ! V_16 ) ) {
F_21 ( V_105 ) ;
return V_106 ;
}
F_87 ( V_16 ) ;
return F_90 ( V_95 , V_87 , V_96 , V_85 , V_16 , V_97 ,
V_98 ) ;
}
static void F_124 ( struct V_86 * V_87 , unsigned long V_123 ,
T_4 * V_85 , T_9 V_124 , T_5 V_90 , bool V_125 )
{
struct V_94 * V_95 = V_87 -> V_126 ;
T_4 V_108 ;
T_8 * V_102 ;
V_102 = F_99 ( V_95 , V_85 ) ;
V_108 = F_84 ( F_125 ( V_124 , V_90 ) ) ;
if ( F_126 ( V_124 ) )
V_108 = F_127 ( V_108 ) ;
if ( V_125 ) {
V_108 = F_128 ( F_106 ( V_108 ) ) ;
V_108 = F_81 ( V_108 , V_87 ) ;
}
F_111 ( V_95 , V_123 , V_85 , V_108 ) ;
F_129 ( V_87 , V_123 , V_85 ) ;
F_101 ( V_102 ) ;
}
int F_130 ( struct V_86 * V_87 , unsigned long V_123 ,
T_4 * V_85 , T_9 V_124 , bool V_125 )
{
T_5 V_127 = V_87 -> V_110 ;
F_29 ( ! ( V_87 -> V_88 & ( V_128 | V_129 ) ) ) ;
F_29 ( ( V_87 -> V_88 & ( V_128 | V_129 ) ) ==
( V_128 | V_129 ) ) ;
F_29 ( ( V_87 -> V_88 & V_128 ) && F_131 ( V_87 -> V_88 ) ) ;
F_29 ( ! F_126 ( V_124 ) ) ;
if ( V_123 < V_87 -> V_118 || V_123 >= V_87 -> V_120 )
return V_130 ;
if ( F_132 ( V_87 , & V_127 , V_124 ) )
return V_130 ;
F_124 ( V_87 , V_123 , V_85 , V_124 , V_127 , V_125 ) ;
return V_131 ;
}
static void F_133 ( struct V_86 * V_87 , unsigned long V_123 ,
T_4 * V_85 )
{
T_4 V_132 ;
V_132 = F_128 ( F_106 ( * V_85 ) ) ;
if ( F_134 ( V_87 , V_123 & V_104 ,
V_85 , V_132 , 1 ) )
F_129 ( V_87 , V_123 , V_85 ) ;
}
struct V_16 * F_135 ( struct V_86 * V_87 , unsigned long V_123 ,
T_4 * V_85 , int V_98 )
{
unsigned long V_124 = F_136 ( * V_85 ) ;
struct V_94 * V_95 = V_87 -> V_126 ;
struct V_133 * V_134 ;
struct V_16 * V_16 ;
F_137 ( F_138 ( V_95 , V_85 ) ) ;
if ( V_98 & V_135 && ! F_139 ( * V_85 ) )
return NULL ;
if ( F_140 ( * V_85 ) && F_141 ( * V_85 ) )
;
else
return NULL ;
if ( V_98 & V_136 )
F_133 ( V_87 , V_123 , V_85 ) ;
if ( ! ( V_98 & V_137 ) )
return F_142 ( - V_138 ) ;
V_124 += ( V_123 & ~ V_139 ) >> V_6 ;
V_134 = F_143 ( V_124 , NULL ) ;
if ( ! V_134 )
return F_142 ( - V_140 ) ;
V_16 = F_144 ( V_124 ) ;
F_145 ( V_16 ) ;
F_146 ( V_134 ) ;
return V_16 ;
}
int F_147 ( struct V_94 * V_141 , struct V_94 * V_142 ,
T_4 * V_143 , T_4 * V_144 , unsigned long V_123 ,
struct V_86 * V_87 )
{
T_8 * V_145 , * V_146 ;
struct V_16 * V_147 ;
T_4 V_85 ;
T_7 V_101 = NULL ;
int V_46 ;
if ( ! F_148 ( V_87 ) ) {
V_46 = - V_69 ;
V_101 = F_95 ( V_141 , V_123 ) ;
if ( F_67 ( ! V_101 ) )
goto V_84;
}
V_145 = F_99 ( V_141 , V_143 ) ;
V_146 = F_138 ( V_142 , V_144 ) ;
F_149 ( V_146 , V_148 ) ;
V_46 = - V_149 ;
V_85 = * V_144 ;
if ( F_67 ( ! F_150 ( V_85 ) && ! F_141 ( V_85 ) ) ) {
F_102 ( V_141 , V_101 ) ;
goto V_150;
}
if ( F_151 ( V_85 ) ) {
struct V_16 * V_17 ;
V_17 = F_16 () ;
F_117 ( V_101 , V_141 , V_87 , V_123 , V_143 ,
V_17 ) ;
V_46 = 0 ;
goto V_150;
}
if ( ! F_148 ( V_87 ) ) {
V_147 = F_152 ( V_85 ) ;
F_91 ( ! F_153 ( V_147 ) , V_147 ) ;
F_145 ( V_147 ) ;
F_154 ( V_147 , true ) ;
F_112 ( V_141 , V_111 , V_31 ) ;
F_113 ( & V_141 -> V_112 ) ;
F_110 ( V_141 , V_143 , V_101 ) ;
}
F_155 ( V_142 , V_123 , V_144 ) ;
V_85 = F_156 ( F_157 ( V_85 ) ) ;
F_111 ( V_141 , V_123 , V_143 , V_85 ) ;
V_46 = 0 ;
V_150:
F_101 ( V_146 ) ;
F_101 ( V_145 ) ;
V_84:
return V_46 ;
}
void F_158 ( struct V_94 * V_95 ,
struct V_86 * V_87 ,
unsigned long V_96 ,
T_4 * V_85 , T_4 V_151 ,
int V_152 )
{
T_8 * V_102 ;
T_4 V_108 ;
unsigned long V_103 ;
V_102 = F_99 ( V_95 , V_85 ) ;
if ( F_67 ( ! F_159 ( * V_85 , V_151 ) ) )
goto V_153;
V_108 = F_128 ( V_151 ) ;
V_103 = V_96 & V_104 ;
if ( F_134 ( V_87 , V_103 , V_85 , V_108 , V_152 ) )
F_129 ( V_87 , V_96 , V_85 ) ;
V_153:
F_101 ( V_102 ) ;
}
static int F_160 ( struct V_94 * V_95 ,
struct V_86 * V_87 ,
unsigned long V_96 ,
T_4 * V_85 , T_4 V_151 ,
struct V_16 * V_16 ,
unsigned long V_103 )
{
struct V_99 * V_100 ;
T_8 * V_102 ;
T_7 V_101 ;
T_4 V_132 ;
int V_46 = 0 , V_154 ;
struct V_16 * * V_61 ;
unsigned long V_155 ;
unsigned long V_156 ;
V_61 = F_161 ( sizeof( struct V_16 * ) * V_31 ,
V_157 ) ;
if ( F_67 ( ! V_61 ) ) {
V_46 |= V_107 ;
goto V_84;
}
for ( V_154 = 0 ; V_154 < V_31 ; V_154 ++ ) {
V_61 [ V_154 ] = F_162 ( V_158 |
V_159 ,
V_87 , V_96 , F_163 ( V_16 ) ) ;
if ( F_67 ( ! V_61 [ V_154 ] ||
F_93 ( V_61 [ V_154 ] , V_95 , V_157 ,
& V_100 , false ) ) ) {
if ( V_61 [ V_154 ] )
F_94 ( V_61 [ V_154 ] ) ;
while ( -- V_154 >= 0 ) {
V_100 = ( void * ) F_164 ( V_61 [ V_154 ] ) ;
F_165 ( V_61 [ V_154 ] , 0 ) ;
F_96 ( V_61 [ V_154 ] , V_100 ,
false ) ;
F_94 ( V_61 [ V_154 ] ) ;
}
F_166 ( V_61 ) ;
V_46 |= V_107 ;
goto V_84;
}
F_165 ( V_61 [ V_154 ] , ( unsigned long ) V_100 ) ;
}
for ( V_154 = 0 ; V_154 < V_31 ; V_154 ++ ) {
F_167 ( V_61 [ V_154 ] , V_16 + V_154 ,
V_103 + V_160 * V_154 , V_87 ) ;
F_98 ( V_61 [ V_154 ] ) ;
F_168 () ;
}
V_155 = V_103 ;
V_156 = V_103 + V_119 ;
F_169 ( V_95 , V_155 , V_156 ) ;
V_102 = F_99 ( V_95 , V_85 ) ;
if ( F_67 ( ! F_159 ( * V_85 , V_151 ) ) )
goto V_161;
F_91 ( ! F_153 ( V_16 ) , V_16 ) ;
F_170 ( V_87 , V_103 , V_85 ) ;
V_101 = F_171 ( V_95 , V_85 ) ;
F_172 ( V_95 , & V_132 , V_101 ) ;
for ( V_154 = 0 ; V_154 < V_31 ; V_154 ++ , V_103 += V_160 ) {
T_10 * V_162 , V_108 ;
V_108 = F_173 ( V_61 [ V_154 ] , V_87 -> V_110 ) ;
V_108 = F_174 ( F_175 ( V_108 ) , V_87 ) ;
V_100 = ( void * ) F_164 ( V_61 [ V_154 ] ) ;
F_165 ( V_61 [ V_154 ] , 0 ) ;
F_107 ( V_61 [ V_154 ] , V_87 , V_103 , false ) ;
F_108 ( V_61 [ V_154 ] , V_100 , false , false ) ;
F_109 ( V_61 [ V_154 ] , V_87 ) ;
V_162 = F_176 ( & V_132 , V_103 ) ;
F_105 ( ! F_177 ( * V_162 ) ) ;
F_178 ( V_95 , V_103 , V_162 , V_108 ) ;
F_179 ( V_162 ) ;
}
F_166 ( V_61 ) ;
F_180 () ;
F_172 ( V_95 , V_85 , V_101 ) ;
F_181 ( V_16 , true ) ;
F_101 ( V_102 ) ;
F_182 ( V_95 , V_155 , V_156 ) ;
V_46 |= V_163 ;
F_94 ( V_16 ) ;
V_84:
return V_46 ;
V_161:
F_101 ( V_102 ) ;
F_182 ( V_95 , V_155 , V_156 ) ;
for ( V_154 = 0 ; V_154 < V_31 ; V_154 ++ ) {
V_100 = ( void * ) F_164 ( V_61 [ V_154 ] ) ;
F_165 ( V_61 [ V_154 ] , 0 ) ;
F_96 ( V_61 [ V_154 ] , V_100 , false ) ;
F_94 ( V_61 [ V_154 ] ) ;
}
F_166 ( V_61 ) ;
goto V_84;
}
int F_183 ( struct V_94 * V_95 , struct V_86 * V_87 ,
unsigned long V_96 , T_4 * V_85 , T_4 V_151 )
{
T_8 * V_102 ;
int V_46 = 0 ;
struct V_16 * V_16 = NULL , * V_164 ;
struct V_99 * V_100 ;
unsigned long V_103 ;
unsigned long V_155 ;
unsigned long V_156 ;
T_6 V_165 ;
V_102 = F_138 ( V_95 , V_85 ) ;
F_184 ( ! V_87 -> V_166 , V_87 ) ;
V_103 = V_96 & V_104 ;
if ( F_151 ( V_151 ) )
goto V_167;
F_185 ( V_102 ) ;
if ( F_67 ( ! F_159 ( * V_85 , V_151 ) ) )
goto V_150;
V_16 = F_152 ( V_151 ) ;
F_91 ( ! F_92 ( V_16 ) || ! F_153 ( V_16 ) , V_16 ) ;
if ( F_186 ( V_16 , NULL ) == 1 ) {
T_4 V_108 ;
V_108 = F_128 ( V_151 ) ;
V_108 = F_81 ( F_106 ( V_108 ) , V_87 ) ;
if ( F_134 ( V_87 , V_103 , V_85 , V_108 , 1 ) )
F_129 ( V_87 , V_96 , V_85 ) ;
V_46 |= V_163 ;
goto V_150;
}
F_145 ( V_16 ) ;
F_101 ( V_102 ) ;
V_167:
if ( F_187 ( V_87 ) &&
! F_188 () ) {
V_165 = F_114 ( V_87 ) ;
V_164 = F_123 ( V_165 , V_87 , V_103 , V_24 ) ;
} else
V_164 = NULL ;
if ( F_17 ( V_164 ) ) {
F_87 ( V_164 ) ;
} else {
if ( ! V_16 ) {
F_189 ( V_87 , V_85 , V_96 ) ;
V_46 |= V_106 ;
} else {
V_46 = F_160 ( V_95 , V_87 , V_96 ,
V_85 , V_151 , V_16 , V_103 ) ;
if ( V_46 & V_107 ) {
F_189 ( V_87 , V_85 , V_96 ) ;
V_46 |= V_106 ;
}
F_94 ( V_16 ) ;
}
F_21 ( V_105 ) ;
goto V_84;
}
if ( F_67 ( F_93 ( V_164 , V_95 , V_165 , & V_100 ,
true ) ) ) {
F_94 ( V_164 ) ;
if ( V_16 ) {
F_189 ( V_87 , V_85 , V_96 ) ;
F_94 ( V_16 ) ;
} else
F_189 ( V_87 , V_85 , V_96 ) ;
V_46 |= V_106 ;
F_21 ( V_105 ) ;
goto V_84;
}
F_21 ( V_113 ) ;
if ( ! V_16 )
F_97 ( V_164 , V_103 , V_31 ) ;
else
F_190 ( V_164 , V_16 , V_103 , V_87 , V_31 ) ;
F_98 ( V_164 ) ;
V_155 = V_103 ;
V_156 = V_103 + V_119 ;
F_169 ( V_95 , V_155 , V_156 ) ;
F_185 ( V_102 ) ;
if ( V_16 )
F_94 ( V_16 ) ;
if ( F_67 ( ! F_159 ( * V_85 , V_151 ) ) ) {
F_101 ( V_102 ) ;
F_96 ( V_164 , V_100 , true ) ;
F_94 ( V_164 ) ;
goto V_168;
} else {
T_4 V_108 ;
V_108 = F_83 ( V_164 , V_87 -> V_110 ) ;
V_108 = F_81 ( F_106 ( V_108 ) , V_87 ) ;
F_170 ( V_87 , V_103 , V_85 ) ;
F_107 ( V_164 , V_87 , V_103 , true ) ;
F_108 ( V_164 , V_100 , false , true ) ;
F_109 ( V_164 , V_87 ) ;
F_111 ( V_95 , V_103 , V_85 , V_108 ) ;
F_129 ( V_87 , V_96 , V_85 ) ;
if ( ! V_16 ) {
F_112 ( V_95 , V_111 , V_31 ) ;
F_28 () ;
} else {
F_91 ( ! F_153 ( V_16 ) , V_16 ) ;
F_181 ( V_16 , true ) ;
F_94 ( V_16 ) ;
}
V_46 |= V_163 ;
}
F_101 ( V_102 ) ;
V_168:
F_182 ( V_95 , V_155 , V_156 ) ;
V_84:
return V_46 ;
V_150:
F_101 ( V_102 ) ;
return V_46 ;
}
struct V_16 * F_191 ( struct V_86 * V_87 ,
unsigned long V_123 ,
T_4 * V_85 ,
unsigned int V_98 )
{
struct V_94 * V_95 = V_87 -> V_126 ;
struct V_16 * V_16 = NULL ;
F_137 ( F_138 ( V_95 , V_85 ) ) ;
if ( V_98 & V_135 && ! F_139 ( * V_85 ) )
goto V_84;
if ( ( V_98 & V_169 ) && F_151 ( * V_85 ) )
return F_142 ( - V_140 ) ;
if ( ( V_98 & V_170 ) && F_192 ( * V_85 ) )
goto V_84;
V_16 = F_152 ( * V_85 ) ;
F_91 ( ! F_153 ( V_16 ) , V_16 ) ;
if ( V_98 & V_136 )
F_133 ( V_87 , V_123 , V_85 ) ;
if ( ( V_98 & V_171 ) && ( V_87 -> V_88 & V_172 ) ) {
if ( F_193 ( V_16 ) == 1 && ! F_194 ( V_16 ) &&
V_16 -> V_92 && F_195 ( V_16 ) ) {
F_196 () ;
if ( V_16 -> V_92 )
F_197 ( V_16 ) ;
F_198 ( V_16 ) ;
}
}
V_16 += ( V_123 & ~ V_104 ) >> V_6 ;
F_91 ( ! F_92 ( V_16 ) , V_16 ) ;
if ( V_98 & V_137 )
F_145 ( V_16 ) ;
V_84:
return V_16 ;
}
int F_199 ( struct V_94 * V_95 , struct V_86 * V_87 ,
unsigned long V_123 , T_4 V_85 , T_4 * V_173 )
{
T_8 * V_102 ;
struct V_166 * V_166 = NULL ;
struct V_16 * V_16 ;
unsigned long V_103 = V_123 & V_104 ;
int V_174 = - 1 , V_175 = F_200 () ;
int V_176 , V_177 = - 1 ;
bool V_178 ;
bool V_179 = false ;
bool V_180 ;
int V_98 = 0 ;
F_29 ( ! ( V_87 -> V_88 & ( V_181 | V_182 | V_89 ) ) ) ;
V_102 = F_99 ( V_95 , V_173 ) ;
if ( F_67 ( ! F_159 ( V_85 , * V_173 ) ) )
goto V_150;
if ( F_67 ( F_201 ( * V_173 ) ) ) {
V_16 = F_152 ( * V_173 ) ;
F_101 ( V_102 ) ;
F_202 ( V_16 ) ;
goto V_84;
}
V_16 = F_152 ( V_85 ) ;
F_29 ( F_203 ( V_16 ) ) ;
V_174 = F_163 ( V_16 ) ;
V_177 = F_204 ( V_16 ) ;
F_205 ( V_183 ) ;
if ( V_174 == V_175 ) {
F_205 ( V_184 ) ;
V_98 |= V_185 ;
}
if ( ! ( V_87 -> V_88 & V_89 ) )
V_98 |= V_186 ;
V_178 = F_195 ( V_16 ) ;
V_176 = F_206 ( V_16 , V_87 , V_103 ) ;
if ( V_176 == - 1 ) {
if ( V_178 )
goto V_187;
}
if ( ! V_178 ) {
F_101 ( V_102 ) ;
F_202 ( V_16 ) ;
V_174 = - 1 ;
goto V_84;
}
F_145 ( V_16 ) ;
F_101 ( V_102 ) ;
V_166 = F_207 ( V_16 ) ;
F_185 ( V_102 ) ;
if ( F_67 ( ! F_159 ( V_85 , * V_173 ) ) ) {
F_198 ( V_16 ) ;
F_94 ( V_16 ) ;
V_174 = - 1 ;
goto V_150;
}
if ( F_67 ( ! V_166 ) ) {
F_94 ( V_16 ) ;
V_174 = - 1 ;
goto V_187;
}
F_101 ( V_102 ) ;
V_179 = F_208 ( V_95 , V_87 ,
V_173 , V_85 , V_123 , V_16 , V_176 ) ;
if ( V_179 ) {
V_98 |= V_188 ;
V_174 = V_176 ;
} else
V_98 |= V_189 ;
goto V_84;
V_187:
F_29 ( ! F_209 ( V_16 ) ) ;
V_180 = F_139 ( V_85 ) ;
V_85 = F_210 ( V_85 , V_87 -> V_110 ) ;
V_85 = F_128 ( V_85 ) ;
if ( V_180 )
V_85 = F_82 ( V_85 ) ;
F_111 ( V_95 , V_103 , V_173 , V_85 ) ;
F_129 ( V_87 , V_123 , V_173 ) ;
F_198 ( V_16 ) ;
V_150:
F_101 ( V_102 ) ;
V_84:
if ( V_166 )
F_211 ( V_166 ) ;
if ( V_174 != - 1 )
F_212 ( V_177 , V_174 , V_31 , V_98 ) ;
return 0 ;
}
int F_213 ( struct V_190 * V_191 , struct V_86 * V_87 ,
T_4 * V_85 , unsigned long V_123 , unsigned long V_192 )
{
T_8 * V_102 ;
T_4 V_151 ;
struct V_16 * V_16 ;
struct V_94 * V_95 = V_191 -> V_95 ;
int V_46 = 0 ;
V_102 = F_214 ( V_85 , V_87 ) ;
if ( ! V_102 )
goto V_193;
V_151 = * V_85 ;
if ( F_151 ( V_151 ) ) {
V_46 = 1 ;
goto V_84;
}
V_16 = F_152 ( V_151 ) ;
if ( F_215 ( V_16 ) != 1 )
goto V_84;
if ( ! F_195 ( V_16 ) )
goto V_84;
if ( V_192 - V_123 != V_119 ) {
F_145 ( V_16 ) ;
F_101 ( V_102 ) ;
F_216 ( V_16 ) ;
F_94 ( V_16 ) ;
F_198 ( V_16 ) ;
goto V_193;
}
if ( F_217 ( V_16 ) )
F_218 ( V_16 ) ;
F_198 ( V_16 ) ;
if ( F_219 ( V_16 ) )
F_220 ( V_16 ) ;
if ( F_221 ( V_151 ) || F_222 ( V_151 ) ) {
V_151 = F_223 ( V_191 -> V_95 , V_123 , V_85 ,
V_191 -> V_194 ) ;
V_151 = F_156 ( V_151 ) ;
V_151 = F_224 ( V_151 ) ;
F_111 ( V_95 , V_123 , V_85 , V_151 ) ;
F_225 ( V_191 , V_85 , V_123 ) ;
}
V_46 = 1 ;
V_84:
F_101 ( V_102 ) ;
V_193:
return V_46 ;
}
int F_226 ( struct V_190 * V_191 , struct V_86 * V_87 ,
T_4 * V_85 , unsigned long V_123 )
{
T_4 V_151 ;
T_8 * V_102 ;
V_102 = F_227 ( V_85 , V_87 ) ;
if ( ! V_102 )
return 0 ;
V_151 = F_223 ( V_191 -> V_95 , V_123 , V_85 ,
V_191 -> V_194 ) ;
F_225 ( V_191 , V_85 , V_123 ) ;
if ( F_148 ( V_87 ) ) {
F_101 ( V_102 ) ;
if ( F_151 ( V_151 ) )
F_228 ( V_191 , F_152 ( V_151 ) ) ;
} else if ( F_151 ( V_151 ) ) {
F_102 ( V_191 -> V_95 , F_171 ( V_191 -> V_95 , V_85 ) ) ;
F_229 ( & V_191 -> V_95 -> V_112 ) ;
F_101 ( V_102 ) ;
F_228 ( V_191 , F_152 ( V_151 ) ) ;
} else {
struct V_16 * V_16 = F_152 ( V_151 ) ;
F_181 ( V_16 , true ) ;
F_91 ( F_215 ( V_16 ) < 0 , V_16 ) ;
F_112 ( V_191 -> V_95 , V_111 , - V_31 ) ;
F_91 ( ! F_153 ( V_16 ) , V_16 ) ;
F_102 ( V_191 -> V_95 , F_171 ( V_191 -> V_95 , V_85 ) ) ;
F_229 ( & V_191 -> V_95 -> V_112 ) ;
F_101 ( V_102 ) ;
F_228 ( V_191 , V_16 ) ;
}
return 1 ;
}
bool F_230 ( struct V_86 * V_87 , unsigned long V_195 ,
unsigned long V_196 , unsigned long V_197 ,
T_4 * V_198 , T_4 * V_199 )
{
T_8 * V_200 , * V_201 ;
T_4 V_85 ;
struct V_94 * V_95 = V_87 -> V_126 ;
if ( ( V_195 & ~ V_104 ) ||
( V_196 & ~ V_104 ) ||
V_197 - V_195 < V_119 )
return false ;
if ( F_231 ( ! F_100 ( * V_199 ) ) ) {
F_105 ( F_150 ( * V_199 ) ) ;
return false ;
}
V_200 = F_227 ( V_198 , V_87 ) ;
if ( V_200 ) {
V_201 = F_138 ( V_95 , V_199 ) ;
if ( V_201 != V_200 )
F_149 ( V_201 , V_148 ) ;
V_85 = F_232 ( V_95 , V_195 , V_198 ) ;
F_105 ( ! F_100 ( * V_199 ) ) ;
if ( F_233 ( V_201 , V_200 ) &&
F_234 ( V_87 ) ) {
T_7 V_101 ;
V_101 = F_171 ( V_95 , V_198 ) ;
F_110 ( V_95 , V_199 , V_101 ) ;
}
F_111 ( V_95 , V_196 , V_199 , F_235 ( V_85 ) ) ;
if ( V_201 != V_200 )
F_101 ( V_201 ) ;
F_101 ( V_200 ) ;
return true ;
}
return false ;
}
int F_236 ( struct V_86 * V_87 , T_4 * V_85 ,
unsigned long V_123 , T_5 V_202 , int V_203 )
{
struct V_94 * V_95 = V_87 -> V_126 ;
T_8 * V_102 ;
int V_46 = 0 ;
V_102 = F_227 ( V_85 , V_87 ) ;
if ( V_102 ) {
T_4 V_108 ;
bool V_204 = V_203 && F_139 ( * V_85 ) ;
V_46 = 1 ;
if ( V_203 && F_151 ( * V_85 ) ) {
F_101 ( V_102 ) ;
return V_46 ;
}
if ( ! V_203 || ! F_192 ( * V_85 ) ) {
V_108 = F_237 ( V_95 , V_123 , V_85 ) ;
V_108 = F_210 ( V_108 , V_202 ) ;
if ( V_204 )
V_108 = F_82 ( V_108 ) ;
V_46 = V_31 ;
F_111 ( V_95 , V_123 , V_85 , V_108 ) ;
F_29 ( ! V_204 && F_139 ( V_108 ) ) ;
}
F_101 ( V_102 ) ;
}
return V_46 ;
}
T_8 * F_227 ( T_4 * V_85 , struct V_86 * V_87 )
{
T_8 * V_102 ;
V_102 = F_99 ( V_87 -> V_126 , V_85 ) ;
if ( F_17 ( F_150 ( * V_85 ) || F_141 ( * V_85 ) ) )
return V_102 ;
F_101 ( V_102 ) ;
return NULL ;
}
int F_238 ( struct V_86 * V_87 ,
unsigned long * V_88 , int V_205 )
{
switch ( V_205 ) {
case V_206 :
#ifdef F_239
if ( F_240 ( V_87 -> V_126 ) )
return 0 ;
#endif
if ( * V_88 & V_207 )
return - V_42 ;
* V_88 &= ~ V_208 ;
* V_88 |= V_115 ;
if ( F_67 ( F_241 ( V_87 , * V_88 ) ) )
return - V_69 ;
break;
case V_209 :
if ( * V_88 & V_207 )
return - V_42 ;
* V_88 &= ~ V_115 ;
* V_88 |= V_208 ;
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
return - V_69 ;
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
return F_246 ( V_210 , V_157 ) ;
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
return - V_69 ;
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
int F_241 ( struct V_86 * V_87 ,
unsigned long V_88 )
{
unsigned long V_220 , V_221 ;
if ( ! V_87 -> V_166 )
return 0 ;
if ( V_87 -> V_222 || ( V_88 & V_207 ) )
return 0 ;
V_220 = ( V_87 -> V_118 + ~ V_104 ) & V_104 ;
V_221 = V_87 -> V_120 & V_104 ;
if ( V_220 < V_221 )
return F_120 ( V_87 , V_88 ) ;
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
static void F_268 ( T_10 * V_162 , T_10 * V_225 )
{
while ( -- V_225 >= V_162 ) {
T_10 V_226 = * V_225 ;
if ( ! F_177 ( V_226 ) && ! F_269 ( F_270 ( V_226 ) ) )
F_265 ( F_271 ( V_226 ) ) ;
}
}
static int F_272 ( struct V_86 * V_87 ,
unsigned long V_96 ,
T_10 * V_162 )
{
struct V_16 * V_16 = NULL ;
T_10 * V_225 ;
int V_227 = 0 , V_228 = 0 ;
bool V_229 = false , V_230 = false ;
for ( V_225 = V_162 ; V_225 < V_162 + V_31 ;
V_225 ++ , V_96 += V_160 ) {
T_10 V_226 = * V_225 ;
if ( F_177 ( V_226 ) || ( F_273 ( V_226 ) &&
F_269 ( F_270 ( V_226 ) ) ) ) {
if ( ! F_274 ( V_87 ) &&
++ V_227 <= V_65 ) {
continue;
} else {
V_228 = V_231 ;
goto V_84;
}
}
if ( ! F_273 ( V_226 ) ) {
V_228 = V_232 ;
goto V_84;
}
V_16 = F_275 ( V_87 , V_96 , V_226 ) ;
if ( F_67 ( ! V_16 ) ) {
V_228 = V_233 ;
goto V_84;
}
F_91 ( F_92 ( V_16 ) , V_16 ) ;
F_91 ( ! F_276 ( V_16 ) , V_16 ) ;
F_91 ( ! F_277 ( V_16 ) , V_16 ) ;
if ( ! F_195 ( V_16 ) ) {
V_228 = V_234 ;
goto V_84;
}
if ( F_278 ( V_16 ) != 1 + ! ! F_279 ( V_16 ) ) {
F_198 ( V_16 ) ;
V_228 = V_235 ;
goto V_84;
}
if ( F_280 ( V_226 ) ) {
V_230 = true ;
} else {
if ( F_279 ( V_16 ) &&
! F_281 ( V_16 , NULL ) ) {
F_198 ( V_16 ) ;
V_228 = V_236 ;
goto V_84;
}
}
if ( F_282 ( V_16 ) ) {
F_198 ( V_16 ) ;
V_228 = V_237 ;
goto V_84;
}
F_283 ( V_16 , V_224 + 0 ) ;
F_91 ( ! F_209 ( V_16 ) , V_16 ) ;
F_91 ( F_284 ( V_16 ) , V_16 ) ;
if ( F_285 ( V_226 ) ||
F_286 ( V_16 ) || F_287 ( V_16 ) ||
F_288 ( V_87 -> V_126 , V_96 ) )
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
V_84:
F_268 ( V_162 , V_225 ) ;
F_289 ( V_16 , V_227 ,
V_229 , V_230 , V_228 ) ;
return 0 ;
}
static void F_290 ( T_10 * V_162 , struct V_16 * V_16 ,
struct V_86 * V_87 ,
unsigned long V_96 ,
T_8 * V_102 )
{
T_10 * V_225 ;
for ( V_225 = V_162 ; V_225 < V_162 + V_31 ; V_225 ++ ) {
T_10 V_226 = * V_225 ;
struct V_16 * V_147 ;
if ( F_177 ( V_226 ) || F_269 ( F_270 ( V_226 ) ) ) {
F_291 ( V_16 , V_96 ) ;
F_112 ( V_87 -> V_126 , V_111 , 1 ) ;
if ( F_269 ( F_270 ( V_226 ) ) ) {
F_185 ( V_102 ) ;
F_292 ( V_87 -> V_126 , V_96 , V_225 ) ;
F_101 ( V_102 ) ;
}
} else {
V_147 = F_271 ( V_226 ) ;
F_167 ( V_16 , V_147 , V_96 , V_87 ) ;
F_91 ( F_215 ( V_147 ) != 1 , V_147 ) ;
F_265 ( V_147 ) ;
F_185 ( V_102 ) ;
F_292 ( V_87 -> V_126 , V_96 , V_225 ) ;
F_181 ( V_147 , false ) ;
F_101 ( V_102 ) ;
F_293 ( V_147 ) ;
}
V_96 += V_160 ;
V_16 ++ ;
}
}
static void F_294 ( void )
{
F_295 ( V_240 ) ;
F_296 ( & V_15 , & V_240 ) ;
F_297 (
F_298 ( V_59 ) ) ;
F_299 ( & V_15 , & V_240 ) ;
}
static bool F_300 ( int V_241 )
{
int V_154 ;
if ( ! V_242 )
return false ;
if ( V_243 [ V_241 ] )
return false ;
for ( V_154 = 0 ; V_154 < V_244 ; V_154 ++ ) {
if ( ! V_243 [ V_154 ] )
continue;
if ( F_301 ( V_241 , V_154 ) > V_245 )
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
* V_250 = F_142 ( - V_69 ) ;
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
static bool F_309 ( struct V_86 * V_87 )
{
if ( ( ! ( V_87 -> V_88 & V_115 ) && ! F_310 () ) ||
( V_87 -> V_88 & V_208 ) )
return false ;
if ( ! V_87 -> V_166 || V_87 -> V_222 )
return false ;
if ( F_311 ( V_87 ) )
return false ;
return ! ( V_87 -> V_88 & V_207 ) ;
}
static void F_312 ( struct V_94 * V_95 ,
unsigned long V_96 ,
struct V_16 * * V_250 ,
struct V_86 * V_87 ,
int V_251 )
{
T_4 * V_85 , V_132 ;
T_10 * V_162 ;
T_7 V_101 ;
struct V_16 * V_164 ;
T_8 * V_254 , * V_255 ;
int V_256 = 0 , V_228 = 0 ;
unsigned long V_220 , V_221 ;
struct V_99 * V_100 ;
unsigned long V_155 ;
unsigned long V_156 ;
T_6 V_97 ;
F_105 ( V_96 & ~ V_104 ) ;
V_97 = F_115 () | V_159 | V_257 ;
V_164 = F_304 ( V_250 , V_97 , V_95 , V_96 , V_251 ) ;
if ( ! V_164 ) {
V_228 = V_258 ;
goto V_259;
}
if ( F_67 ( F_93 ( V_164 , V_95 , V_97 , & V_100 , true ) ) ) {
V_228 = V_260 ;
goto V_259;
}
F_263 ( & V_95 -> V_223 ) ;
if ( F_67 ( F_253 ( V_95 ) ) ) {
V_228 = V_261 ;
goto V_84;
}
V_87 = F_313 ( V_95 , V_96 ) ;
if ( ! V_87 ) {
V_228 = V_262 ;
goto V_84;
}
V_220 = ( V_87 -> V_118 + ~ V_104 ) & V_104 ;
V_221 = V_87 -> V_120 & V_104 ;
if ( V_96 < V_220 || V_96 + V_119 > V_221 ) {
V_228 = V_263 ;
goto V_84;
}
if ( ! F_309 ( V_87 ) ) {
V_228 = V_264 ;
goto V_84;
}
V_85 = F_314 ( V_95 , V_96 ) ;
if ( ! V_85 ) {
V_228 = V_265 ;
goto V_84;
}
F_315 ( V_87 -> V_166 ) ;
V_162 = F_176 ( V_85 , V_96 ) ;
V_255 = F_316 ( V_95 , V_85 ) ;
V_155 = V_96 ;
V_156 = V_96 + V_119 ;
F_169 ( V_95 , V_155 , V_156 ) ;
V_254 = F_99 ( V_95 , V_85 ) ;
V_132 = F_317 ( V_87 , V_96 , V_85 ) ;
F_101 ( V_254 ) ;
F_182 ( V_95 , V_155 , V_156 ) ;
F_185 ( V_255 ) ;
V_256 = F_272 ( V_87 , V_96 , V_162 ) ;
F_101 ( V_255 ) ;
if ( F_67 ( ! V_256 ) ) {
F_179 ( V_162 ) ;
F_185 ( V_254 ) ;
F_29 ( ! F_100 ( * V_85 ) ) ;
F_172 ( V_95 , V_85 , F_318 ( V_132 ) ) ;
F_101 ( V_254 ) ;
F_319 ( V_87 -> V_166 ) ;
V_228 = V_266 ;
goto V_84;
}
F_319 ( V_87 -> V_166 ) ;
F_290 ( V_162 , V_164 , V_87 , V_96 , V_255 ) ;
F_179 ( V_162 ) ;
F_98 ( V_164 ) ;
V_101 = F_318 ( V_132 ) ;
V_132 = F_83 ( V_164 , V_87 -> V_110 ) ;
V_132 = F_81 ( F_106 ( V_132 ) , V_87 ) ;
F_180 () ;
F_185 ( V_254 ) ;
F_29 ( ! F_100 ( * V_85 ) ) ;
F_107 ( V_164 , V_87 , V_96 , true ) ;
F_108 ( V_164 , V_100 , false , true ) ;
F_109 ( V_164 , V_87 ) ;
F_110 ( V_95 , V_85 , V_101 ) ;
F_111 ( V_95 , V_96 , V_85 , V_132 ) ;
F_129 ( V_87 , V_96 , V_85 ) ;
F_101 ( V_254 ) ;
* V_250 = NULL ;
V_62 ++ ;
V_228 = V_238 ;
V_267:
F_264 ( & V_95 -> V_223 ) ;
F_320 ( V_95 , V_256 , V_228 ) ;
return;
V_259:
F_320 ( V_95 , V_256 , V_228 ) ;
return;
V_84:
F_96 ( V_164 , V_100 , true ) ;
goto V_267;
}
static int F_321 ( struct V_94 * V_95 ,
struct V_86 * V_87 ,
unsigned long V_96 ,
struct V_16 * * V_250 )
{
T_4 * V_85 ;
T_10 * V_162 , * V_225 ;
int V_46 = 0 , V_227 = 0 , V_228 = 0 ;
struct V_16 * V_16 = NULL ;
unsigned long V_268 ;
T_8 * V_102 ;
int V_251 = V_247 ;
bool V_230 = false , V_229 = false ;
F_105 ( V_96 & ~ V_104 ) ;
V_85 = F_314 ( V_95 , V_96 ) ;
if ( ! V_85 ) {
V_228 = V_265 ;
goto V_84;
}
memset ( V_243 , 0 , sizeof( V_243 ) ) ;
V_162 = F_322 ( V_95 , V_85 , V_96 , & V_102 ) ;
for ( V_268 = V_96 , V_225 = V_162 ; V_225 < V_162 + V_31 ;
V_225 ++ , V_268 += V_160 ) {
T_10 V_226 = * V_225 ;
if ( F_177 ( V_226 ) || F_269 ( F_270 ( V_226 ) ) ) {
if ( ! F_274 ( V_87 ) &&
++ V_227 <= V_65 ) {
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
V_16 = F_275 ( V_87 , V_268 , V_226 ) ;
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
F_288 ( V_87 -> V_126 , V_96 ) )
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
F_323 ( V_162 , V_102 ) ;
if ( V_46 ) {
V_251 = F_302 () ;
F_312 ( V_95 , V_96 , V_250 , V_87 , V_251 ) ;
}
V_84:
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
static unsigned int F_327 ( unsigned int V_61 ,
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
unsigned int V_61 = V_60 ;
bool V_240 = true ;
F_332 () ;
while ( V_276 < V_61 ) {
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
V_276 += F_327 ( V_61 - V_276 ,
& V_250 ) ;
else
V_276 = V_61 ;
F_101 ( & V_217 ) ;
}
if ( ! F_334 ( V_250 ) )
F_94 ( V_250 ) ;
}
static bool F_335 ( void )
{
return F_330 () ||
F_336 ( V_278 , V_58 ) ;
}
static void F_337 ( void )
{
if ( F_328 () ) {
const unsigned long V_279 =
F_298 ( V_55 ) ;
if ( ! V_279 )
return;
V_58 = V_278 + V_279 ;
F_338 ( V_15 ,
F_335 () ,
V_279 ) ;
return;
}
if ( F_8 () )
F_339 ( V_15 , F_329 () ) ;
}
static int V_11 ( void * V_280 )
{
struct V_211 * V_211 ;
F_340 () ;
F_341 ( V_281 , V_282 ) ;
while ( ! F_330 () ) {
F_331 () ;
F_337 () ;
}
F_185 ( & V_217 ) ;
V_211 = V_13 . V_211 ;
V_13 . V_211 = NULL ;
if ( V_211 )
F_325 ( V_211 ) ;
F_101 ( & V_217 ) ;
return 0 ;
}
static void F_342 ( struct V_86 * V_87 ,
unsigned long V_103 , T_4 * V_85 )
{
struct V_94 * V_95 = V_87 -> V_126 ;
T_7 V_101 ;
T_4 V_132 ;
int V_154 ;
F_170 ( V_87 , V_103 , V_85 ) ;
V_101 = F_171 ( V_95 , V_85 ) ;
F_172 ( V_95 , & V_132 , V_101 ) ;
for ( V_154 = 0 ; V_154 < V_31 ; V_154 ++ , V_103 += V_160 ) {
T_10 * V_162 , V_108 ;
V_108 = F_343 ( F_344 ( V_103 ) , V_87 -> V_110 ) ;
V_108 = F_345 ( V_108 ) ;
V_162 = F_176 ( & V_132 , V_103 ) ;
F_105 ( ! F_177 ( * V_162 ) ) ;
F_178 ( V_95 , V_103 , V_162 , V_108 ) ;
F_179 ( V_162 ) ;
}
F_180 () ;
F_172 ( V_95 , V_85 , V_101 ) ;
F_28 () ;
}
static void F_346 ( struct V_86 * V_87 , T_4 * V_85 ,
unsigned long V_103 , bool V_283 )
{
struct V_94 * V_95 = V_87 -> V_126 ;
struct V_16 * V_16 ;
T_7 V_101 ;
T_4 V_132 ;
bool V_284 , V_125 , V_152 ;
unsigned long V_123 ;
int V_154 ;
F_105 ( V_103 & ~ V_104 ) ;
F_184 ( V_87 -> V_118 > V_103 , V_87 ) ;
F_184 ( V_87 -> V_120 < V_103 + V_119 , V_87 ) ;
F_105 ( ! F_150 ( * V_85 ) && ! F_141 ( * V_85 ) ) ;
F_21 ( V_285 ) ;
if ( F_148 ( V_87 ) ) {
T_4 V_132 = F_170 ( V_87 , V_103 , V_85 ) ;
if ( F_151 ( V_132 ) )
F_28 () ;
return;
} else if ( F_151 ( * V_85 ) ) {
return F_342 ( V_87 , V_103 , V_85 ) ;
}
V_16 = F_152 ( * V_85 ) ;
F_91 ( ! F_278 ( V_16 ) , V_16 ) ;
F_347 ( V_16 , V_31 - 1 ) ;
V_125 = F_139 ( * V_85 ) ;
V_284 = F_221 ( * V_85 ) ;
V_152 = F_222 ( * V_85 ) ;
F_348 ( V_87 , V_103 , V_85 ) ;
V_101 = F_171 ( V_95 , V_85 ) ;
F_172 ( V_95 , & V_132 , V_101 ) ;
for ( V_154 = 0 , V_123 = V_103 ; V_154 < V_31 ; V_154 ++ , V_123 += V_160 ) {
T_10 V_108 , * V_162 ;
if ( V_283 ) {
T_11 V_286 ;
V_286 = F_349 ( V_16 + V_154 , V_125 ) ;
V_108 = F_350 ( V_286 ) ;
} else {
V_108 = F_173 ( V_16 + V_154 , V_87 -> V_110 ) ;
V_108 = F_174 ( V_108 , V_87 ) ;
if ( ! V_125 )
V_108 = F_351 ( V_108 ) ;
if ( ! V_284 )
V_108 = F_352 ( V_108 ) ;
}
if ( V_152 )
F_353 ( V_16 + V_154 ) ;
V_162 = F_176 ( & V_132 , V_123 ) ;
F_29 ( ! F_177 ( * V_162 ) ) ;
F_178 ( V_95 , V_123 , V_162 , V_108 ) ;
F_258 ( & V_16 [ V_154 ] . V_287 ) ;
F_179 ( V_162 ) ;
}
if ( F_193 ( V_16 ) > 1 && ! F_354 ( V_16 ) ) {
for ( V_154 = 0 ; V_154 < V_31 ; V_154 ++ )
F_258 ( & V_16 [ V_154 ] . V_287 ) ;
}
if ( F_355 ( - 1 , F_356 ( V_16 ) ) ) {
F_357 ( V_16 , V_288 ) ;
if ( F_358 ( V_16 ) ) {
for ( V_154 = 0 ; V_154 < V_31 ; V_154 ++ )
F_359 ( & V_16 [ V_154 ] . V_287 ) ;
}
}
F_180 () ;
F_360 ( V_87 , V_103 , V_85 ) ;
F_172 ( V_95 , V_85 , V_101 ) ;
if ( V_283 ) {
for ( V_154 = 0 ; V_154 < V_31 ; V_154 ++ ) {
F_181 ( V_16 + V_154 , false ) ;
F_94 ( V_16 + V_154 ) ;
}
}
}
void F_361 ( struct V_86 * V_87 , T_4 * V_85 ,
unsigned long V_96 , bool V_283 , struct V_16 * V_16 )
{
T_8 * V_102 ;
struct V_94 * V_95 = V_87 -> V_126 ;
unsigned long V_103 = V_96 & V_104 ;
F_169 ( V_95 , V_103 , V_103 + V_119 ) ;
V_102 = F_99 ( V_95 , V_85 ) ;
F_105 ( V_283 && ! V_16 ) ;
if ( V_16 && V_16 != F_152 ( * V_85 ) )
goto V_84;
if ( F_150 ( * V_85 ) ) {
V_16 = F_152 ( * V_85 ) ;
if ( F_362 ( V_16 ) )
F_363 ( V_16 ) ;
} else if ( ! F_141 ( * V_85 ) )
goto V_84;
F_346 ( V_87 , V_85 , V_103 , V_283 ) ;
V_84:
F_101 ( V_102 ) ;
F_182 ( V_95 , V_103 , V_103 + V_119 ) ;
}
void F_364 ( struct V_86 * V_87 , unsigned long V_96 ,
bool V_283 , struct V_16 * V_16 )
{
T_12 * V_289 ;
T_13 * V_290 ;
T_4 * V_85 ;
V_289 = F_365 ( V_87 -> V_126 , V_96 ) ;
if ( ! F_366 ( * V_289 ) )
return;
V_290 = F_367 ( V_289 , V_96 ) ;
if ( ! F_368 ( * V_290 ) )
return;
V_85 = F_369 ( V_290 , V_96 ) ;
F_361 ( V_87 , V_85 , V_96 , V_283 , V_16 ) ;
}
void F_370 ( struct V_86 * V_87 ,
unsigned long V_291 ,
unsigned long V_292 ,
long V_293 )
{
if ( V_291 & ~ V_104 &&
( V_291 & V_104 ) >= V_87 -> V_118 &&
( V_291 & V_104 ) + V_119 <= V_87 -> V_120 )
F_364 ( V_87 , V_291 , false , NULL ) ;
if ( V_292 & ~ V_104 &&
( V_292 & V_104 ) >= V_87 -> V_118 &&
( V_292 & V_104 ) + V_119 <= V_87 -> V_120 )
F_364 ( V_87 , V_292 , false , NULL ) ;
if ( V_293 > 0 ) {
struct V_86 * V_192 = V_87 -> V_294 ;
unsigned long V_295 = V_192 -> V_118 ;
V_295 += V_293 << V_6 ;
if ( V_295 & ~ V_104 &&
( V_295 & V_104 ) >= V_192 -> V_118 &&
( V_295 & V_104 ) + V_119 <= V_192 -> V_120 )
F_364 ( V_192 , V_295 , false , NULL ) ;
}
}
static void F_371 ( struct V_16 * V_16 )
{
enum V_296 V_296 = V_297 | V_298 |
V_299 | V_300 ;
int V_154 , V_46 ;
F_91 ( ! F_153 ( V_16 ) , V_16 ) ;
V_46 = F_372 ( V_16 , V_296 | V_301 ) ;
for ( V_154 = 1 ; ! V_46 && V_154 < V_31 ; V_154 ++ ) {
if ( F_278 ( V_16 ) == 1 )
return;
V_46 = F_372 ( V_16 + V_154 , V_296 ) ;
}
F_105 ( V_46 ) ;
}
static void F_373 ( struct V_16 * V_16 )
{
int V_154 ;
for ( V_154 = 0 ; V_154 < V_31 ; V_154 ++ )
F_374 ( V_16 + V_154 , V_16 + V_154 , true ) ;
}
static void F_375 ( struct V_16 * V_302 , int V_303 ,
struct V_304 * V_304 , struct V_91 * V_305 )
{
struct V_16 * V_306 = V_302 + V_303 ;
F_91 ( F_32 ( & V_306 -> V_287 ) != - 1 , V_306 ) ;
F_91 ( F_376 ( V_306 ) != 0 , V_306 ) ;
F_377 ( V_306 ) ;
V_306 -> V_98 &= ~ V_307 ;
V_306 -> V_98 |= ( V_302 -> V_98 &
( ( 1L << V_308 ) |
( 1L << V_309 ) |
( 1L << V_310 ) |
( 1L << V_311 ) |
( 1L << V_312 ) |
( 1L << V_313 ) |
( 1L << V_314 ) |
( 1L << V_315 ) ) ) ;
F_180 () ;
F_378 ( V_306 ) ;
if ( F_286 ( V_302 ) )
F_379 ( V_306 ) ;
if ( F_380 ( V_302 ) )
F_381 ( V_306 ) ;
F_91 ( V_303 > 2 && V_306 -> V_92 != V_316 ,
V_306 ) ;
V_306 -> V_92 = V_302 -> V_92 ;
V_306 -> V_317 = V_302 -> V_317 + V_303 ;
F_382 ( V_306 , F_204 ( V_302 ) ) ;
F_383 ( V_302 , V_306 , V_304 , V_305 ) ;
}
static void F_384 ( struct V_16 * V_16 , struct V_91 * V_305 )
{
struct V_16 * V_302 = F_385 ( V_16 ) ;
struct V_1 * V_1 = F_386 ( V_302 ) ;
struct V_304 * V_304 ;
int V_154 ;
F_387 ( & V_1 -> V_318 ) ;
V_304 = F_388 ( V_302 , V_1 ) ;
F_389 ( V_302 ) ;
for ( V_154 = V_31 - 1 ; V_154 >= 1 ; V_154 -- )
F_375 ( V_302 , V_154 , V_304 , V_305 ) ;
F_390 ( V_302 ) ;
F_391 ( & V_1 -> V_318 ) ;
F_373 ( V_302 ) ;
for ( V_154 = 0 ; V_154 < V_31 ; V_154 ++ ) {
struct V_16 * V_319 = V_302 + V_154 ;
if ( V_319 == V_16 )
continue;
F_198 ( V_319 ) ;
F_94 ( V_319 ) ;
}
}
int F_392 ( struct V_16 * V_16 )
{
int V_154 , V_46 ;
F_91 ( F_393 ( V_16 ) , V_16 ) ;
if ( F_17 ( ! F_92 ( V_16 ) ) )
return F_32 ( & V_16 -> V_287 ) + 1 ;
V_46 = F_193 ( V_16 ) ;
if ( F_394 ( V_16 ) )
return V_46 ;
for ( V_154 = 0 ; V_154 < V_31 ; V_154 ++ )
V_46 += F_32 ( & V_16 [ V_154 ] . V_287 ) + 1 ;
if ( F_194 ( V_16 ) )
V_46 -= V_31 ;
return V_46 ;
}
int F_186 ( struct V_16 * V_16 , int * F_392 )
{
int V_154 , V_46 , V_320 , V_321 ;
F_91 ( F_394 ( V_16 ) , V_16 ) ;
if ( F_17 ( ! F_395 ( V_16 ) ) ) {
V_321 = F_32 ( & V_16 -> V_287 ) + 1 ;
if ( F_392 )
* F_392 = V_321 ;
return V_321 ;
}
V_16 = F_385 ( V_16 ) ;
V_320 = V_46 = 0 ;
for ( V_154 = 0 ; V_154 < V_31 ; V_154 ++ ) {
V_321 = F_32 ( & V_16 [ V_154 ] . V_287 ) + 1 ;
V_46 = F_396 ( V_46 , V_321 ) ;
V_320 += V_321 ;
}
if ( F_194 ( V_16 ) ) {
V_46 -= 1 ;
V_320 -= V_31 ;
}
V_321 = F_193 ( V_16 ) ;
V_46 += V_321 ;
V_320 += V_321 ;
if ( F_392 )
* F_392 = V_320 ;
return V_46 ;
}
int F_397 ( struct V_16 * V_16 , struct V_91 * V_305 )
{
struct V_16 * V_302 = F_385 ( V_16 ) ;
struct V_322 * V_323 = F_398 ( F_163 ( V_302 ) ) ;
struct V_166 * V_166 ;
int V_37 , V_321 , V_46 ;
bool V_324 ;
unsigned long V_98 ;
F_91 ( F_203 ( V_16 ) , V_16 ) ;
F_91 ( ! F_276 ( V_16 ) , V_16 ) ;
F_91 ( ! F_209 ( V_16 ) , V_16 ) ;
F_91 ( ! F_277 ( V_16 ) , V_16 ) ;
F_91 ( ! F_92 ( V_16 ) , V_16 ) ;
V_166 = F_399 ( V_302 ) ;
if ( ! V_166 ) {
V_46 = - V_325 ;
goto V_84;
}
F_315 ( V_166 ) ;
if ( F_392 ( V_302 ) != F_278 ( V_302 ) - 1 ) {
V_46 = - V_325 ;
goto V_150;
}
V_324 = F_362 ( V_16 ) ;
F_371 ( V_302 ) ;
F_91 ( F_193 ( V_302 ) , V_302 ) ;
if ( V_324 )
F_196 () ;
F_400 ( & V_323 -> V_326 , V_98 ) ;
V_37 = F_278 ( V_302 ) ;
V_321 = F_392 ( V_302 ) ;
if ( ! V_321 && V_37 == 1 ) {
if ( ! F_13 ( F_86 ( V_302 ) ) ) {
V_323 -> V_327 -- ;
F_261 ( F_86 ( V_302 ) ) ;
}
F_401 ( & V_323 -> V_326 , V_98 ) ;
F_384 ( V_16 , V_305 ) ;
V_46 = 0 ;
} else if ( F_402 ( V_328 ) && V_321 ) {
F_401 ( & V_323 -> V_326 , V_98 ) ;
F_403 ( L_22 ,
V_321 , V_37 ) ;
if ( F_393 ( V_16 ) )
F_404 ( V_302 , NULL ) ;
F_404 ( V_16 , L_23 ) ;
F_405 () ;
} else {
F_401 ( & V_323 -> V_326 , V_98 ) ;
F_373 ( V_302 ) ;
V_46 = - V_325 ;
}
V_150:
F_319 ( V_166 ) ;
F_406 ( V_166 ) ;
V_84:
F_21 ( ! V_46 ? V_329 : V_330 ) ;
return V_46 ;
}
void F_407 ( struct V_16 * V_16 )
{
struct V_322 * V_323 = F_398 ( F_163 ( V_16 ) ) ;
unsigned long V_98 ;
F_400 ( & V_323 -> V_326 , V_98 ) ;
if ( ! F_13 ( F_86 ( V_16 ) ) ) {
V_323 -> V_327 -- ;
F_261 ( F_86 ( V_16 ) ) ;
}
F_401 ( & V_323 -> V_326 , V_98 ) ;
F_408 ( V_16 ) ;
}
void F_409 ( struct V_16 * V_16 )
{
struct V_322 * V_323 = F_398 ( F_163 ( V_16 ) ) ;
unsigned long V_98 ;
F_91 ( ! F_410 ( V_16 ) , V_16 ) ;
F_400 ( & V_323 -> V_326 , V_98 ) ;
if ( F_13 ( F_86 ( V_16 ) ) ) {
F_21 ( V_331 ) ;
F_257 ( F_86 ( V_16 ) , & V_323 -> V_332 ) ;
V_323 -> V_327 ++ ;
}
F_401 ( & V_323 -> V_326 , V_98 ) ;
}
static unsigned long F_411 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_322 * V_323 = F_398 ( V_30 -> V_241 ) ;
return F_412 ( V_323 -> V_327 ) ;
}
static unsigned long F_413 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_322 * V_323 = F_398 ( V_30 -> V_241 ) ;
unsigned long V_98 ;
F_414 ( V_305 ) , * V_333 , * V_192 ;
struct V_16 * V_16 ;
int V_334 = 0 ;
F_400 ( & V_323 -> V_326 , V_98 ) ;
F_415 (pos, next, &pgdata->split_queue) {
V_16 = F_416 ( ( void * ) V_333 , struct V_16 , V_92 ) ;
V_16 = F_385 ( V_16 ) ;
if ( F_417 ( V_16 ) ) {
F_418 ( F_86 ( V_16 ) , & V_305 ) ;
} else {
F_419 ( F_86 ( V_16 ) ) ;
V_323 -> V_327 -- ;
}
if ( ! -- V_30 -> V_335 )
break;
}
F_401 ( & V_323 -> V_326 , V_98 ) ;
F_415 (pos, next, &list) {
V_16 = F_416 ( ( void * ) V_333 , struct V_16 , V_92 ) ;
F_420 ( V_16 ) ;
if ( ! F_216 ( V_16 ) )
V_334 ++ ;
F_198 ( V_16 ) ;
F_94 ( V_16 ) ;
}
F_400 ( & V_323 -> V_326 , V_98 ) ;
F_421 ( & V_305 , & V_323 -> V_332 ) ;
F_401 ( & V_323 -> V_326 , V_98 ) ;
if ( ! V_334 && F_13 ( & V_323 -> V_332 ) )
return V_336 ;
return V_334 ;
}
static int F_422 ( void * V_337 , T_14 V_338 )
{
struct V_1 * V_1 ;
struct V_16 * V_16 ;
unsigned long V_124 , V_339 ;
unsigned long V_340 = 0 , V_334 = 0 ;
if ( V_338 != 1 )
return - V_42 ;
F_2 (zone) {
V_339 = F_423 ( V_1 ) ;
for ( V_124 = V_1 -> V_341 ; V_124 < V_339 ; V_124 ++ ) {
if ( ! F_424 ( V_124 ) )
continue;
V_16 = F_144 ( V_124 ) ;
if ( ! F_417 ( V_16 ) )
continue;
if ( V_1 != F_386 ( V_16 ) )
goto V_192;
if ( ! F_153 ( V_16 ) || ! F_276 ( V_16 ) ||
F_394 ( V_16 ) )
goto V_192;
V_340 ++ ;
F_420 ( V_16 ) ;
if ( ! F_216 ( V_16 ) )
V_334 ++ ;
F_198 ( V_16 ) ;
V_192:
F_94 ( V_16 ) ;
}
}
F_5 ( L_24 , V_334 , V_340 ) ;
return 0 ;
}
static int T_3 F_425 ( void )
{
void * V_46 ;
V_46 = F_426 ( L_25 , 0200 , NULL , NULL ,
& V_342 ) ;
if ( ! V_46 )
F_80 ( L_26 ) ;
return 0 ;
}
