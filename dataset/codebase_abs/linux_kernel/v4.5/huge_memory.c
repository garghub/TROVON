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
if ( F_10 ( V_10 ) ) {
F_11 ( L_4 ) ;
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
static void F_28 ( void )
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
struct V_34 * V_35 , char * V_36 ,
enum V_37 V_38 ,
enum V_37 V_39 )
{
if ( F_37 ( V_38 , & V_40 ) ) {
F_38 ( F_37 ( V_39 , & V_40 ) ) ;
return sprintf ( V_36 , L_5 ) ;
} else if ( F_37 ( V_39 , & V_40 ) )
return sprintf ( V_36 , L_6 ) ;
else
return sprintf ( V_36 , L_7 ) ;
}
static T_1 F_39 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_2 V_41 ,
enum V_37 V_38 ,
enum V_37 V_39 )
{
if ( ! memcmp ( L_8 , V_36 ,
F_3 ( sizeof( L_8 ) - 1 , V_41 ) ) ) {
F_40 ( V_38 , & V_40 ) ;
F_41 ( V_39 , & V_40 ) ;
} else if ( ! memcmp ( L_9 , V_36 ,
F_3 ( sizeof( L_9 ) - 1 , V_41 ) ) ) {
F_41 ( V_38 , & V_40 ) ;
F_40 ( V_39 , & V_40 ) ;
} else if ( ! memcmp ( L_10 , V_36 ,
F_3 ( sizeof( L_10 ) - 1 , V_41 ) ) ) {
F_41 ( V_38 , & V_40 ) ;
F_41 ( V_39 , & V_40 ) ;
} else
return - V_42 ;
return V_41 ;
}
static T_1 F_42 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 )
{
return F_36 ( V_33 , V_35 , V_36 ,
V_43 ,
V_44 ) ;
}
static T_1 F_43 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_2 V_41 )
{
T_1 V_45 ;
V_45 = F_39 ( V_33 , V_35 , V_36 , V_41 ,
V_43 ,
V_44 ) ;
if ( V_45 > 0 ) {
int V_9 ;
F_44 ( & V_46 ) ;
V_9 = F_7 () ;
F_45 ( & V_46 ) ;
if ( V_9 )
V_45 = V_9 ;
}
return V_45 ;
}
static T_1 F_46 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 ,
enum V_37 V_47 )
{
return sprintf ( V_36 , L_11 ,
! ! F_37 ( V_47 , & V_40 ) ) ;
}
static T_1 F_47 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_2 V_41 ,
enum V_37 V_47 )
{
unsigned long V_48 ;
int V_45 ;
V_45 = F_48 ( V_36 , 10 , & V_48 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_48 > 1 )
return - V_42 ;
if ( V_48 )
F_40 ( V_47 , & V_40 ) ;
else
F_41 ( V_47 , & V_40 ) ;
return V_41 ;
}
static T_1 F_49 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 )
{
return F_36 ( V_33 , V_35 , V_36 ,
V_49 ,
V_50 ) ;
}
static T_1 F_50 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_2 V_41 )
{
return F_39 ( V_33 , V_35 , V_36 , V_41 ,
V_49 ,
V_50 ) ;
}
static T_1 F_51 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 )
{
return F_46 ( V_33 , V_35 , V_36 ,
V_51 ) ;
}
static T_1 F_52 ( struct V_32 * V_33 ,
struct V_34 * V_35 , const char * V_36 , T_2 V_41 )
{
return F_47 ( V_33 , V_35 , V_36 , V_41 ,
V_51 ) ;
}
static T_1 F_53 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 )
{
return F_46 ( V_33 , V_35 , V_36 ,
V_52 ) ;
}
static T_1 F_54 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_2 V_41 )
{
return F_47 ( V_33 , V_35 , V_36 , V_41 ,
V_52 ) ;
}
static T_1 F_55 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_12 , V_53 ) ;
}
static T_1 F_56 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_2 V_41 )
{
unsigned long V_54 ;
int V_9 ;
V_9 = F_48 ( V_36 , 10 , & V_54 ) ;
if ( V_9 || V_54 > V_55 )
return - V_42 ;
V_53 = V_54 ;
F_14 ( & V_15 ) ;
return V_41 ;
}
static T_1 F_57 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_12 , V_56 ) ;
}
static T_1 F_58 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_2 V_41 )
{
unsigned long V_54 ;
int V_9 ;
V_9 = F_48 ( V_36 , 10 , & V_54 ) ;
if ( V_9 || V_54 > V_55 )
return - V_42 ;
V_56 = V_54 ;
F_14 ( & V_15 ) ;
return V_41 ;
}
static T_1 F_59 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_12 , V_57 ) ;
}
static T_1 F_60 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_2 V_41 )
{
int V_9 ;
unsigned long V_58 ;
V_9 = F_48 ( V_36 , 10 , & V_58 ) ;
if ( V_9 || ! V_58 || V_58 > V_55 )
return - V_42 ;
V_57 = V_58 ;
return V_41 ;
}
static T_1 F_61 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_12 , V_59 ) ;
}
static T_1 F_62 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_12 , V_60 ) ;
}
static T_1 F_63 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_36 )
{
return F_46 ( V_33 , V_35 , V_36 ,
V_61 ) ;
}
static T_1 F_64 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_2 V_41 )
{
return F_47 ( V_33 , V_35 , V_36 , V_41 ,
V_61 ) ;
}
static T_1 F_65 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
char * V_36 )
{
return sprintf ( V_36 , L_12 , V_62 ) ;
}
static T_1 F_66 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_2 V_41 )
{
int V_9 ;
unsigned long V_63 ;
V_9 = F_48 ( V_36 , 10 , & V_63 ) ;
if ( V_9 || V_63 > V_31 - 1 )
return - V_42 ;
V_62 = V_63 ;
return V_41 ;
}
static int T_3 F_67 ( struct V_32 * * V_64 )
{
int V_9 ;
* V_64 = F_68 ( L_13 , V_65 ) ;
if ( F_69 ( ! * V_64 ) ) {
F_11 ( L_14 ) ;
return - V_66 ;
}
V_9 = F_70 ( * V_64 , & V_67 ) ;
if ( V_9 ) {
F_11 ( L_15 ) ;
goto V_68;
}
V_9 = F_70 ( * V_64 , & V_69 ) ;
if ( V_9 ) {
F_11 ( L_15 ) ;
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
static inline int F_67 ( struct V_32 * * V_64 )
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
V_9 = F_67 ( & V_64 ) ;
if ( V_9 )
goto V_71;
V_9 = F_76 () ;
if ( V_9 )
goto V_72;
V_9 = F_77 ( & V_73 ) ;
if ( V_9 )
goto V_74;
V_9 = F_77 ( & V_75 ) ;
if ( V_9 )
goto V_76;
if ( V_77 < ( 512 << ( 20 - V_6 ) ) ) {
V_40 = 0 ;
return 0 ;
}
V_9 = F_7 () ;
if ( V_9 )
goto V_78;
return 0 ;
V_78:
F_78 ( & V_75 ) ;
V_76:
F_78 ( & V_73 ) ;
V_74:
F_79 () ;
V_72:
F_73 ( V_64 ) ;
V_71:
return V_9 ;
}
static int T_3 F_80 ( char * V_79 )
{
int V_45 = 0 ;
if ( ! V_79 )
goto V_80;
if ( ! strcmp ( V_79 , L_8 ) ) {
F_40 ( V_43 ,
& V_40 ) ;
F_41 ( V_44 ,
& V_40 ) ;
V_45 = 1 ;
} else if ( ! strcmp ( V_79 , L_9 ) ) {
F_41 ( V_43 ,
& V_40 ) ;
F_40 ( V_44 ,
& V_40 ) ;
V_45 = 1 ;
} else if ( ! strcmp ( V_79 , L_10 ) ) {
F_41 ( V_43 ,
& V_40 ) ;
F_41 ( V_44 ,
& V_40 ) ;
V_45 = 1 ;
}
V_80:
if ( ! V_45 )
F_81 ( L_16 ) ;
return V_45 ;
}
T_4 F_82 ( T_4 V_81 , struct V_82 * V_83 )
{
if ( F_17 ( V_83 -> V_84 & V_85 ) )
V_81 = F_83 ( V_81 ) ;
return V_81 ;
}
static inline T_4 F_84 ( struct V_16 * V_16 , T_5 V_86 )
{
T_4 V_87 ;
V_87 = F_85 ( V_16 , V_86 ) ;
V_87 = F_86 ( V_87 ) ;
return V_87 ;
}
static inline struct V_88 * F_87 ( struct V_16 * V_16 )
{
return (struct V_88 * ) & V_16 [ 2 ] . V_89 ;
}
void F_88 ( struct V_16 * V_16 )
{
F_89 ( V_24 < 2 ) ;
F_90 ( F_87 ( V_16 ) ) ;
F_91 ( V_16 , V_90 ) ;
}
static int F_92 ( struct V_91 * V_92 ,
struct V_82 * V_83 ,
unsigned long V_93 , T_4 * V_81 ,
struct V_16 * V_16 , T_6 V_94 ,
unsigned int V_95 )
{
struct V_96 * V_97 ;
T_7 V_98 ;
T_8 * V_99 ;
unsigned long V_100 = V_93 & V_101 ;
F_93 ( ! F_94 ( V_16 ) , V_16 ) ;
if ( F_95 ( V_16 , V_92 , V_94 , & V_97 , true ) ) {
F_96 ( V_16 ) ;
F_21 ( V_102 ) ;
return V_103 ;
}
V_98 = F_97 ( V_92 , V_100 ) ;
if ( F_69 ( ! V_98 ) ) {
F_98 ( V_16 , V_97 , true ) ;
F_96 ( V_16 ) ;
return V_104 ;
}
F_99 ( V_16 , V_100 , V_31 ) ;
F_100 ( V_16 ) ;
V_99 = F_101 ( V_92 , V_81 ) ;
if ( F_69 ( ! F_102 ( * V_81 ) ) ) {
F_103 ( V_99 ) ;
F_98 ( V_16 , V_97 , true ) ;
F_96 ( V_16 ) ;
F_104 ( V_92 , V_98 ) ;
} else {
T_4 V_87 ;
if ( F_105 ( V_83 ) ) {
int V_45 ;
F_103 ( V_99 ) ;
F_98 ( V_16 , V_97 , true ) ;
F_96 ( V_16 ) ;
F_104 ( V_92 , V_98 ) ;
V_45 = F_106 ( V_83 , V_93 , V_95 ,
V_105 ) ;
F_38 ( V_45 & V_103 ) ;
return V_45 ;
}
V_87 = F_84 ( V_16 , V_83 -> V_106 ) ;
V_87 = F_82 ( F_107 ( V_87 ) , V_83 ) ;
F_108 ( V_16 , V_83 , V_100 , true ) ;
F_109 ( V_16 , V_97 , false , true ) ;
F_110 ( V_16 , V_83 ) ;
F_111 ( V_92 , V_81 , V_98 ) ;
F_112 ( V_92 , V_100 , V_81 , V_87 ) ;
F_113 ( V_92 , V_107 , V_31 ) ;
F_114 ( & V_92 -> V_108 ) ;
F_103 ( V_99 ) ;
F_21 ( V_109 ) ;
}
return 0 ;
}
static inline T_6 F_115 ( int V_110 , T_6 V_111 )
{
return ( V_21 & ~ ( V_110 ? 0 : V_112 ) ) | V_111 ;
}
static bool F_116 ( T_7 V_98 , struct V_91 * V_92 ,
struct V_82 * V_83 , unsigned long V_100 , T_4 * V_81 ,
struct V_16 * V_17 )
{
T_4 V_87 ;
if ( ! F_102 ( * V_81 ) )
return false ;
V_87 = F_85 ( V_17 , V_83 -> V_106 ) ;
V_87 = F_86 ( V_87 ) ;
if ( V_98 )
F_111 ( V_92 , V_81 , V_98 ) ;
F_112 ( V_92 , V_100 , V_81 , V_87 ) ;
F_114 ( & V_92 -> V_108 ) ;
return true ;
}
int F_117 ( struct V_91 * V_92 , struct V_82 * V_83 ,
unsigned long V_93 , T_4 * V_81 ,
unsigned int V_95 )
{
T_6 V_94 ;
struct V_16 * V_16 ;
unsigned long V_100 = V_93 & V_101 ;
if ( V_100 < V_83 -> V_113 || V_100 + V_114 > V_83 -> V_115 )
return V_103 ;
if ( F_69 ( F_118 ( V_83 ) ) )
return V_104 ;
if ( F_69 ( F_119 ( V_83 , V_83 -> V_84 ) ) )
return V_104 ;
if ( ! ( V_95 & V_116 ) && ! F_120 ( V_92 ) &&
F_121 () ) {
T_8 * V_99 ;
T_7 V_98 ;
struct V_16 * V_17 ;
bool V_117 ;
int V_45 ;
V_98 = F_97 ( V_92 , V_100 ) ;
if ( F_69 ( ! V_98 ) )
return V_104 ;
V_17 = F_16 () ;
if ( F_69 ( ! V_17 ) ) {
F_104 ( V_92 , V_98 ) ;
F_21 ( V_102 ) ;
return V_103 ;
}
V_99 = F_101 ( V_92 , V_81 ) ;
V_45 = 0 ;
V_117 = false ;
if ( F_102 ( * V_81 ) ) {
if ( F_105 ( V_83 ) ) {
F_103 ( V_99 ) ;
V_45 = F_106 ( V_83 , V_93 , V_95 ,
V_105 ) ;
F_38 ( V_45 & V_103 ) ;
} else {
F_116 ( V_98 , V_92 , V_83 ,
V_100 , V_81 ,
V_17 ) ;
F_103 ( V_99 ) ;
V_117 = true ;
}
} else
F_103 ( V_99 ) ;
if ( ! V_117 ) {
F_104 ( V_92 , V_98 ) ;
F_28 () ;
}
return V_45 ;
}
V_94 = F_115 ( F_122 ( V_83 ) , 0 ) ;
V_16 = F_123 ( V_94 , V_83 , V_100 , V_24 ) ;
if ( F_69 ( ! V_16 ) ) {
F_21 ( V_102 ) ;
return V_103 ;
}
F_88 ( V_16 ) ;
return F_92 ( V_92 , V_83 , V_93 , V_81 , V_16 , V_94 ,
V_95 ) ;
}
static void F_124 ( struct V_82 * V_83 , unsigned long V_118 ,
T_4 * V_81 , T_9 V_119 , T_5 V_86 , bool V_120 )
{
struct V_91 * V_92 = V_83 -> V_121 ;
T_4 V_87 ;
T_8 * V_99 ;
V_99 = F_101 ( V_92 , V_81 ) ;
V_87 = F_86 ( F_125 ( V_119 , V_86 ) ) ;
if ( F_126 ( V_119 ) )
V_87 = F_127 ( V_87 ) ;
if ( V_120 ) {
V_87 = F_128 ( F_107 ( V_87 ) ) ;
V_87 = F_82 ( V_87 , V_83 ) ;
}
F_112 ( V_92 , V_118 , V_81 , V_87 ) ;
F_129 ( V_83 , V_118 , V_81 ) ;
F_103 ( V_99 ) ;
}
int F_130 ( struct V_82 * V_83 , unsigned long V_118 ,
T_4 * V_81 , T_9 V_119 , bool V_120 )
{
T_5 V_122 = V_83 -> V_106 ;
F_29 ( ! ( V_83 -> V_84 & ( V_123 | V_124 ) ) ) ;
F_29 ( ( V_83 -> V_84 & ( V_123 | V_124 ) ) ==
( V_123 | V_124 ) ) ;
F_29 ( ( V_83 -> V_84 & V_123 ) && F_131 ( V_83 -> V_84 ) ) ;
F_29 ( ! F_126 ( V_119 ) ) ;
if ( V_118 < V_83 -> V_113 || V_118 >= V_83 -> V_115 )
return V_125 ;
if ( F_132 ( V_83 , & V_122 , V_119 ) )
return V_125 ;
F_124 ( V_83 , V_118 , V_81 , V_119 , V_122 , V_120 ) ;
return V_126 ;
}
static void F_133 ( struct V_82 * V_83 , unsigned long V_118 ,
T_4 * V_81 )
{
T_4 V_127 ;
V_127 = F_128 ( F_107 ( * V_81 ) ) ;
if ( F_134 ( V_83 , V_118 & V_101 ,
V_81 , V_127 , 1 ) )
F_129 ( V_83 , V_118 , V_81 ) ;
}
struct V_16 * F_135 ( struct V_82 * V_83 , unsigned long V_118 ,
T_4 * V_81 , int V_95 )
{
unsigned long V_119 = F_136 ( * V_81 ) ;
struct V_91 * V_92 = V_83 -> V_121 ;
struct V_128 * V_129 ;
struct V_16 * V_16 ;
F_137 ( F_138 ( V_92 , V_81 ) ) ;
if ( V_95 & V_130 && ! F_139 ( * V_81 ) )
return NULL ;
if ( F_140 ( * V_81 ) && F_141 ( * V_81 ) )
;
else
return NULL ;
if ( V_95 & V_131 )
F_133 ( V_83 , V_118 , V_81 ) ;
if ( ! ( V_95 & V_132 ) )
return F_142 ( - V_133 ) ;
V_119 += ( V_118 & ~ V_134 ) >> V_6 ;
V_129 = F_143 ( V_119 , NULL ) ;
if ( ! V_129 )
return F_142 ( - V_135 ) ;
V_16 = F_144 ( V_119 ) ;
F_145 ( V_16 ) ;
F_146 ( V_129 ) ;
return V_16 ;
}
int F_147 ( struct V_91 * V_136 , struct V_91 * V_137 ,
T_4 * V_138 , T_4 * V_139 , unsigned long V_118 ,
struct V_82 * V_83 )
{
T_8 * V_140 , * V_141 ;
struct V_16 * V_142 ;
T_4 V_81 ;
T_7 V_98 = NULL ;
int V_45 ;
if ( ! F_148 ( V_83 ) ) {
V_45 = - V_66 ;
V_98 = F_97 ( V_136 , V_118 ) ;
if ( F_69 ( ! V_98 ) )
goto V_80;
}
V_140 = F_101 ( V_136 , V_138 ) ;
V_141 = F_138 ( V_137 , V_139 ) ;
F_149 ( V_141 , V_143 ) ;
V_45 = - V_144 ;
V_81 = * V_139 ;
if ( F_69 ( ! F_150 ( V_81 ) && ! F_141 ( V_81 ) ) ) {
F_104 ( V_136 , V_98 ) ;
goto V_145;
}
if ( F_151 ( V_81 ) ) {
struct V_16 * V_17 ;
V_17 = F_16 () ;
F_116 ( V_98 , V_136 , V_83 , V_118 , V_138 ,
V_17 ) ;
V_45 = 0 ;
goto V_145;
}
if ( ! F_148 ( V_83 ) ) {
V_142 = F_152 ( V_81 ) ;
F_93 ( ! F_153 ( V_142 ) , V_142 ) ;
F_145 ( V_142 ) ;
F_154 ( V_142 , true ) ;
F_113 ( V_136 , V_107 , V_31 ) ;
F_114 ( & V_136 -> V_108 ) ;
F_111 ( V_136 , V_138 , V_98 ) ;
}
F_155 ( V_137 , V_118 , V_139 ) ;
V_81 = F_156 ( F_157 ( V_81 ) ) ;
F_112 ( V_136 , V_118 , V_138 , V_81 ) ;
V_45 = 0 ;
V_145:
F_103 ( V_141 ) ;
F_103 ( V_140 ) ;
V_80:
return V_45 ;
}
void F_158 ( struct V_91 * V_92 ,
struct V_82 * V_83 ,
unsigned long V_93 ,
T_4 * V_81 , T_4 V_146 ,
int V_147 )
{
T_8 * V_99 ;
T_4 V_87 ;
unsigned long V_100 ;
V_99 = F_101 ( V_92 , V_81 ) ;
if ( F_69 ( ! F_159 ( * V_81 , V_146 ) ) )
goto V_148;
V_87 = F_128 ( V_146 ) ;
V_100 = V_93 & V_101 ;
if ( F_134 ( V_83 , V_100 , V_81 , V_87 , V_147 ) )
F_129 ( V_83 , V_93 , V_81 ) ;
V_148:
F_103 ( V_99 ) ;
}
static int F_160 ( struct V_91 * V_92 ,
struct V_82 * V_83 ,
unsigned long V_93 ,
T_4 * V_81 , T_4 V_146 ,
struct V_16 * V_16 ,
unsigned long V_100 )
{
struct V_96 * V_97 ;
T_8 * V_99 ;
T_7 V_98 ;
T_4 V_127 ;
int V_45 = 0 , V_149 ;
struct V_16 * * V_58 ;
unsigned long V_150 ;
unsigned long V_151 ;
V_58 = F_161 ( sizeof( struct V_16 * ) * V_31 ,
V_152 ) ;
if ( F_69 ( ! V_58 ) ) {
V_45 |= V_104 ;
goto V_80;
}
for ( V_149 = 0 ; V_149 < V_31 ; V_149 ++ ) {
V_58 [ V_149 ] = F_162 ( V_153 |
V_154 ,
V_83 , V_93 , F_163 ( V_16 ) ) ;
if ( F_69 ( ! V_58 [ V_149 ] ||
F_95 ( V_58 [ V_149 ] , V_92 , V_152 ,
& V_97 , false ) ) ) {
if ( V_58 [ V_149 ] )
F_96 ( V_58 [ V_149 ] ) ;
while ( -- V_149 >= 0 ) {
V_97 = ( void * ) F_164 ( V_58 [ V_149 ] ) ;
F_165 ( V_58 [ V_149 ] , 0 ) ;
F_98 ( V_58 [ V_149 ] , V_97 ,
false ) ;
F_96 ( V_58 [ V_149 ] ) ;
}
F_166 ( V_58 ) ;
V_45 |= V_104 ;
goto V_80;
}
F_165 ( V_58 [ V_149 ] , ( unsigned long ) V_97 ) ;
}
for ( V_149 = 0 ; V_149 < V_31 ; V_149 ++ ) {
F_167 ( V_58 [ V_149 ] , V_16 + V_149 ,
V_100 + V_155 * V_149 , V_83 ) ;
F_100 ( V_58 [ V_149 ] ) ;
F_168 () ;
}
V_150 = V_100 ;
V_151 = V_100 + V_114 ;
F_169 ( V_92 , V_150 , V_151 ) ;
V_99 = F_101 ( V_92 , V_81 ) ;
if ( F_69 ( ! F_159 ( * V_81 , V_146 ) ) )
goto V_156;
F_93 ( ! F_153 ( V_16 ) , V_16 ) ;
F_170 ( V_83 , V_100 , V_81 ) ;
V_98 = F_171 ( V_92 , V_81 ) ;
F_172 ( V_92 , & V_127 , V_98 ) ;
for ( V_149 = 0 ; V_149 < V_31 ; V_149 ++ , V_100 += V_155 ) {
T_10 * V_157 , V_87 ;
V_87 = F_173 ( V_58 [ V_149 ] , V_83 -> V_106 ) ;
V_87 = F_174 ( F_175 ( V_87 ) , V_83 ) ;
V_97 = ( void * ) F_164 ( V_58 [ V_149 ] ) ;
F_165 ( V_58 [ V_149 ] , 0 ) ;
F_108 ( V_58 [ V_149 ] , V_83 , V_100 , false ) ;
F_109 ( V_58 [ V_149 ] , V_97 , false , false ) ;
F_110 ( V_58 [ V_149 ] , V_83 ) ;
V_157 = F_176 ( & V_127 , V_100 ) ;
F_38 ( ! F_177 ( * V_157 ) ) ;
F_178 ( V_92 , V_100 , V_157 , V_87 ) ;
F_179 ( V_157 ) ;
}
F_166 ( V_58 ) ;
F_180 () ;
F_172 ( V_92 , V_81 , V_98 ) ;
F_181 ( V_16 , true ) ;
F_103 ( V_99 ) ;
F_182 ( V_92 , V_150 , V_151 ) ;
V_45 |= V_158 ;
F_96 ( V_16 ) ;
V_80:
return V_45 ;
V_156:
F_103 ( V_99 ) ;
F_182 ( V_92 , V_150 , V_151 ) ;
for ( V_149 = 0 ; V_149 < V_31 ; V_149 ++ ) {
V_97 = ( void * ) F_164 ( V_58 [ V_149 ] ) ;
F_165 ( V_58 [ V_149 ] , 0 ) ;
F_98 ( V_58 [ V_149 ] , V_97 , false ) ;
F_96 ( V_58 [ V_149 ] ) ;
}
F_166 ( V_58 ) ;
goto V_80;
}
int F_183 ( struct V_91 * V_92 , struct V_82 * V_83 ,
unsigned long V_93 , T_4 * V_81 , T_4 V_146 )
{
T_8 * V_99 ;
int V_45 = 0 ;
struct V_16 * V_16 = NULL , * V_159 ;
struct V_96 * V_97 ;
unsigned long V_100 ;
unsigned long V_150 ;
unsigned long V_151 ;
T_6 V_160 ;
V_99 = F_138 ( V_92 , V_81 ) ;
F_184 ( ! V_83 -> V_161 , V_83 ) ;
V_100 = V_93 & V_101 ;
if ( F_151 ( V_146 ) )
goto V_162;
F_185 ( V_99 ) ;
if ( F_69 ( ! F_159 ( * V_81 , V_146 ) ) )
goto V_145;
V_16 = F_152 ( V_146 ) ;
F_93 ( ! F_94 ( V_16 ) || ! F_153 ( V_16 ) , V_16 ) ;
if ( F_186 ( V_16 ) == 1 && F_187 ( V_16 ) == 1 ) {
T_4 V_87 ;
V_87 = F_128 ( V_146 ) ;
V_87 = F_82 ( F_107 ( V_87 ) , V_83 ) ;
if ( F_134 ( V_83 , V_100 , V_81 , V_87 , 1 ) )
F_129 ( V_83 , V_93 , V_81 ) ;
V_45 |= V_158 ;
goto V_145;
}
F_145 ( V_16 ) ;
F_103 ( V_99 ) ;
V_162:
if ( F_188 ( V_83 ) &&
! F_189 () ) {
V_160 = F_115 ( F_122 ( V_83 ) , 0 ) ;
V_159 = F_123 ( V_160 , V_83 , V_100 , V_24 ) ;
} else
V_159 = NULL ;
if ( F_17 ( V_159 ) ) {
F_88 ( V_159 ) ;
} else {
if ( ! V_16 ) {
F_190 ( V_83 , V_81 , V_93 ) ;
V_45 |= V_103 ;
} else {
V_45 = F_160 ( V_92 , V_83 , V_93 ,
V_81 , V_146 , V_16 , V_100 ) ;
if ( V_45 & V_104 ) {
F_190 ( V_83 , V_81 , V_93 ) ;
V_45 |= V_103 ;
}
F_96 ( V_16 ) ;
}
F_21 ( V_102 ) ;
goto V_80;
}
if ( F_69 ( F_95 ( V_159 , V_92 , V_160 , & V_97 ,
true ) ) ) {
F_96 ( V_159 ) ;
if ( V_16 ) {
F_190 ( V_83 , V_81 , V_93 ) ;
F_96 ( V_16 ) ;
} else
F_190 ( V_83 , V_81 , V_93 ) ;
V_45 |= V_103 ;
F_21 ( V_102 ) ;
goto V_80;
}
F_21 ( V_109 ) ;
if ( ! V_16 )
F_99 ( V_159 , V_100 , V_31 ) ;
else
F_191 ( V_159 , V_16 , V_100 , V_83 , V_31 ) ;
F_100 ( V_159 ) ;
V_150 = V_100 ;
V_151 = V_100 + V_114 ;
F_169 ( V_92 , V_150 , V_151 ) ;
F_185 ( V_99 ) ;
if ( V_16 )
F_96 ( V_16 ) ;
if ( F_69 ( ! F_159 ( * V_81 , V_146 ) ) ) {
F_103 ( V_99 ) ;
F_98 ( V_159 , V_97 , true ) ;
F_96 ( V_159 ) ;
goto V_163;
} else {
T_4 V_87 ;
V_87 = F_84 ( V_159 , V_83 -> V_106 ) ;
V_87 = F_82 ( F_107 ( V_87 ) , V_83 ) ;
F_170 ( V_83 , V_100 , V_81 ) ;
F_108 ( V_159 , V_83 , V_100 , true ) ;
F_109 ( V_159 , V_97 , false , true ) ;
F_110 ( V_159 , V_83 ) ;
F_112 ( V_92 , V_100 , V_81 , V_87 ) ;
F_129 ( V_83 , V_93 , V_81 ) ;
if ( ! V_16 ) {
F_113 ( V_92 , V_107 , V_31 ) ;
F_28 () ;
} else {
F_93 ( ! F_153 ( V_16 ) , V_16 ) ;
F_181 ( V_16 , true ) ;
F_96 ( V_16 ) ;
}
V_45 |= V_158 ;
}
F_103 ( V_99 ) ;
V_163:
F_182 ( V_92 , V_150 , V_151 ) ;
V_80:
return V_45 ;
V_145:
F_103 ( V_99 ) ;
return V_45 ;
}
struct V_16 * F_192 ( struct V_82 * V_83 ,
unsigned long V_118 ,
T_4 * V_81 ,
unsigned int V_95 )
{
struct V_91 * V_92 = V_83 -> V_121 ;
struct V_16 * V_16 = NULL ;
F_137 ( F_138 ( V_92 , V_81 ) ) ;
if ( V_95 & V_130 && ! F_139 ( * V_81 ) )
goto V_80;
if ( ( V_95 & V_164 ) && F_151 ( * V_81 ) )
return F_142 ( - V_135 ) ;
if ( ( V_95 & V_165 ) && F_193 ( * V_81 ) )
goto V_80;
V_16 = F_152 ( * V_81 ) ;
F_93 ( ! F_153 ( V_16 ) , V_16 ) ;
if ( V_95 & V_131 )
F_133 ( V_83 , V_118 , V_81 ) ;
if ( ( V_95 & V_166 ) && ( V_83 -> V_84 & V_167 ) ) {
if ( F_194 ( V_16 ) == 1 && ! F_195 ( V_16 ) &&
V_16 -> V_89 && F_196 ( V_16 ) ) {
F_197 () ;
if ( V_16 -> V_89 )
F_198 ( V_16 ) ;
F_199 ( V_16 ) ;
}
}
V_16 += ( V_118 & ~ V_101 ) >> V_6 ;
F_93 ( ! F_94 ( V_16 ) , V_16 ) ;
if ( V_95 & V_132 )
F_145 ( V_16 ) ;
V_80:
return V_16 ;
}
int F_200 ( struct V_91 * V_92 , struct V_82 * V_83 ,
unsigned long V_118 , T_4 V_81 , T_4 * V_168 )
{
T_8 * V_99 ;
struct V_161 * V_161 = NULL ;
struct V_16 * V_16 ;
unsigned long V_100 = V_118 & V_101 ;
int V_169 = - 1 , V_170 = F_201 () ;
int V_171 , V_172 = - 1 ;
bool V_173 ;
bool V_174 = false ;
bool V_175 ;
int V_95 = 0 ;
F_29 ( ! ( V_83 -> V_84 & ( V_176 | V_177 | V_85 ) ) ) ;
V_99 = F_101 ( V_92 , V_168 ) ;
if ( F_69 ( ! F_159 ( V_81 , * V_168 ) ) )
goto V_145;
if ( F_69 ( F_202 ( * V_168 ) ) ) {
V_16 = F_152 ( * V_168 ) ;
F_103 ( V_99 ) ;
F_203 ( V_16 ) ;
goto V_80;
}
V_16 = F_152 ( V_81 ) ;
F_29 ( F_204 ( V_16 ) ) ;
V_169 = F_163 ( V_16 ) ;
V_172 = F_205 ( V_16 ) ;
F_206 ( V_178 ) ;
if ( V_169 == V_170 ) {
F_206 ( V_179 ) ;
V_95 |= V_180 ;
}
if ( ! ( V_83 -> V_84 & V_85 ) )
V_95 |= V_181 ;
V_173 = F_196 ( V_16 ) ;
V_171 = F_207 ( V_16 , V_83 , V_100 ) ;
if ( V_171 == - 1 ) {
if ( V_173 )
goto V_182;
}
if ( ! V_173 ) {
F_103 ( V_99 ) ;
F_203 ( V_16 ) ;
V_169 = - 1 ;
goto V_80;
}
F_145 ( V_16 ) ;
F_103 ( V_99 ) ;
V_161 = F_208 ( V_16 ) ;
F_185 ( V_99 ) ;
if ( F_69 ( ! F_159 ( V_81 , * V_168 ) ) ) {
F_199 ( V_16 ) ;
F_96 ( V_16 ) ;
V_169 = - 1 ;
goto V_145;
}
if ( F_69 ( ! V_161 ) ) {
F_96 ( V_16 ) ;
V_169 = - 1 ;
goto V_182;
}
F_103 ( V_99 ) ;
V_174 = F_209 ( V_92 , V_83 ,
V_168 , V_81 , V_118 , V_16 , V_171 ) ;
if ( V_174 ) {
V_95 |= V_183 ;
V_169 = V_171 ;
} else
V_95 |= V_184 ;
goto V_80;
V_182:
F_29 ( ! F_210 ( V_16 ) ) ;
V_175 = F_139 ( V_81 ) ;
V_81 = F_211 ( V_81 , V_83 -> V_106 ) ;
V_81 = F_128 ( V_81 ) ;
if ( V_175 )
V_81 = F_83 ( V_81 ) ;
F_112 ( V_92 , V_100 , V_168 , V_81 ) ;
F_129 ( V_83 , V_118 , V_168 ) ;
F_199 ( V_16 ) ;
V_145:
F_103 ( V_99 ) ;
V_80:
if ( V_161 )
F_212 ( V_161 ) ;
if ( V_169 != - 1 )
F_213 ( V_172 , V_169 , V_31 , V_95 ) ;
return 0 ;
}
int F_214 ( struct V_185 * V_186 , struct V_82 * V_83 ,
T_4 * V_81 , unsigned long V_118 , unsigned long V_187 )
{
T_8 * V_99 ;
T_4 V_146 ;
struct V_16 * V_16 ;
struct V_91 * V_92 = V_186 -> V_92 ;
int V_45 = 0 ;
V_99 = F_215 ( V_81 , V_83 ) ;
if ( ! V_99 )
goto V_188;
V_146 = * V_81 ;
if ( F_151 ( V_146 ) ) {
V_45 = 1 ;
goto V_80;
}
V_16 = F_152 ( V_146 ) ;
if ( F_186 ( V_16 ) != 1 )
goto V_80;
if ( ! F_196 ( V_16 ) )
goto V_80;
if ( V_187 - V_118 != V_114 ) {
F_145 ( V_16 ) ;
F_103 ( V_99 ) ;
if ( F_216 ( V_16 ) ) {
F_96 ( V_16 ) ;
F_199 ( V_16 ) ;
goto V_188;
}
F_96 ( V_16 ) ;
F_199 ( V_16 ) ;
V_45 = 1 ;
goto V_188;
}
if ( F_217 ( V_16 ) )
F_218 ( V_16 ) ;
F_199 ( V_16 ) ;
if ( F_219 ( V_16 ) )
F_220 ( V_16 ) ;
if ( F_221 ( V_146 ) || F_222 ( V_146 ) ) {
V_146 = F_223 ( V_186 -> V_92 , V_118 , V_81 ,
V_186 -> V_189 ) ;
V_146 = F_156 ( V_146 ) ;
V_146 = F_224 ( V_146 ) ;
F_112 ( V_92 , V_118 , V_81 , V_146 ) ;
F_225 ( V_186 , V_81 , V_118 ) ;
}
V_45 = 1 ;
V_80:
F_103 ( V_99 ) ;
V_188:
return V_45 ;
}
int F_226 ( struct V_185 * V_186 , struct V_82 * V_83 ,
T_4 * V_81 , unsigned long V_118 )
{
T_4 V_146 ;
T_8 * V_99 ;
V_99 = F_227 ( V_81 , V_83 ) ;
if ( ! V_99 )
return 0 ;
V_146 = F_223 ( V_186 -> V_92 , V_118 , V_81 ,
V_186 -> V_189 ) ;
F_225 ( V_186 , V_81 , V_118 ) ;
if ( F_148 ( V_83 ) ) {
F_103 ( V_99 ) ;
if ( F_151 ( V_146 ) )
F_28 () ;
} else if ( F_151 ( V_146 ) ) {
F_104 ( V_186 -> V_92 , F_171 ( V_186 -> V_92 , V_81 ) ) ;
F_228 ( & V_186 -> V_92 -> V_108 ) ;
F_103 ( V_99 ) ;
F_28 () ;
} else {
struct V_16 * V_16 = F_152 ( V_146 ) ;
F_181 ( V_16 , true ) ;
F_93 ( F_186 ( V_16 ) < 0 , V_16 ) ;
F_113 ( V_186 -> V_92 , V_107 , - V_31 ) ;
F_93 ( ! F_153 ( V_16 ) , V_16 ) ;
F_104 ( V_186 -> V_92 , F_171 ( V_186 -> V_92 , V_81 ) ) ;
F_228 ( & V_186 -> V_92 -> V_108 ) ;
F_103 ( V_99 ) ;
F_229 ( V_186 , V_16 ) ;
}
return 1 ;
}
bool F_230 ( struct V_82 * V_83 , struct V_82 * V_190 ,
unsigned long V_191 ,
unsigned long V_192 , unsigned long V_193 ,
T_4 * V_194 , T_4 * V_195 )
{
T_8 * V_196 , * V_197 ;
T_4 V_81 ;
struct V_91 * V_92 = V_83 -> V_121 ;
if ( ( V_191 & ~ V_101 ) ||
( V_192 & ~ V_101 ) ||
V_193 - V_191 < V_114 ||
( V_190 -> V_84 & V_198 ) )
return false ;
if ( F_231 ( ! F_102 ( * V_195 ) ) ) {
F_38 ( F_150 ( * V_195 ) ) ;
return false ;
}
V_196 = F_227 ( V_194 , V_83 ) ;
if ( V_196 ) {
V_197 = F_138 ( V_92 , V_195 ) ;
if ( V_197 != V_196 )
F_149 ( V_197 , V_143 ) ;
V_81 = F_232 ( V_92 , V_191 , V_194 ) ;
F_38 ( ! F_102 ( * V_195 ) ) ;
if ( F_233 ( V_197 , V_196 ) &&
F_234 ( V_83 ) ) {
T_7 V_98 ;
V_98 = F_171 ( V_92 , V_194 ) ;
F_111 ( V_92 , V_195 , V_98 ) ;
}
F_112 ( V_92 , V_192 , V_195 , F_235 ( V_81 ) ) ;
if ( V_197 != V_196 )
F_103 ( V_197 ) ;
F_103 ( V_196 ) ;
return true ;
}
return false ;
}
int F_236 ( struct V_82 * V_83 , T_4 * V_81 ,
unsigned long V_118 , T_5 V_199 , int V_200 )
{
struct V_91 * V_92 = V_83 -> V_121 ;
T_8 * V_99 ;
int V_45 = 0 ;
V_99 = F_227 ( V_81 , V_83 ) ;
if ( V_99 ) {
T_4 V_87 ;
bool V_201 = V_200 && F_139 ( * V_81 ) ;
V_45 = 1 ;
if ( V_200 && F_151 ( * V_81 ) ) {
F_103 ( V_99 ) ;
return V_45 ;
}
if ( ! V_200 || ! F_193 ( * V_81 ) ) {
V_87 = F_237 ( V_92 , V_118 , V_81 ) ;
V_87 = F_211 ( V_87 , V_199 ) ;
if ( V_201 )
V_87 = F_83 ( V_87 ) ;
V_45 = V_31 ;
F_112 ( V_92 , V_118 , V_81 , V_87 ) ;
F_29 ( ! V_201 && F_139 ( V_87 ) ) ;
}
F_103 ( V_99 ) ;
}
return V_45 ;
}
T_8 * F_227 ( T_4 * V_81 , struct V_82 * V_83 )
{
T_8 * V_99 ;
V_99 = F_101 ( V_83 -> V_121 , V_81 ) ;
if ( F_17 ( F_150 ( * V_81 ) || F_141 ( * V_81 ) ) )
return V_99 ;
F_103 ( V_99 ) ;
return NULL ;
}
int F_238 ( struct V_82 * V_83 ,
unsigned long * V_84 , int V_202 )
{
switch ( V_202 ) {
case V_203 :
#ifdef F_239
if ( F_240 ( V_83 -> V_121 ) )
return 0 ;
#endif
if ( * V_84 & V_204 )
return - V_42 ;
* V_84 &= ~ V_198 ;
* V_84 |= V_205 ;
if ( F_69 ( F_241 ( V_83 , * V_84 ) ) )
return - V_66 ;
break;
case V_206 :
if ( * V_84 & V_204 )
return - V_42 ;
* V_84 &= ~ V_205 ;
* V_84 |= V_198 ;
break;
}
return 0 ;
}
static int T_3 F_76 ( void )
{
V_207 = F_242 ( L_17 ,
sizeof( struct V_208 ) ,
F_243 ( struct V_208 ) , 0 , NULL ) ;
if ( ! V_207 )
return - V_66 ;
return 0 ;
}
static void T_3 F_79 ( void )
{
F_244 ( V_207 ) ;
}
static inline struct V_208 * F_245 ( void )
{
if ( ! V_207 )
return NULL ;
return F_246 ( V_207 , V_152 ) ;
}
static inline void F_247 ( struct V_208 * V_208 )
{
F_248 ( V_207 , V_208 ) ;
}
static struct V_208 * F_249 ( struct V_91 * V_92 )
{
struct V_208 * V_208 ;
F_250 (mm_slots_hash, mm_slot, hash, (unsigned long)mm)
if ( V_92 == V_208 -> V_92 )
return V_208 ;
return NULL ;
}
static void F_251 ( struct V_91 * V_92 ,
struct V_208 * V_208 )
{
V_208 -> V_92 = V_92 ;
F_252 ( V_209 , & V_208 -> V_210 , ( long ) V_92 ) ;
}
static inline int F_253 ( struct V_91 * V_92 )
{
return F_32 ( & V_92 -> V_211 ) == 0 ;
}
int F_254 ( struct V_91 * V_92 )
{
struct V_208 * V_208 ;
int V_212 ;
V_208 = F_245 () ;
if ( ! V_208 )
return - V_66 ;
F_255 ( F_253 ( V_92 ) , V_92 ) ;
if ( F_69 ( F_256 ( V_213 , & V_92 -> V_95 ) ) ) {
F_247 ( V_208 ) ;
return 0 ;
}
F_185 ( & V_214 ) ;
F_251 ( V_92 , V_208 ) ;
V_212 = F_13 ( & V_13 . V_14 ) ;
F_257 ( & V_208 -> V_215 , & V_13 . V_14 ) ;
F_103 ( & V_214 ) ;
F_258 ( & V_92 -> V_216 ) ;
if ( V_212 )
F_14 ( & V_15 ) ;
return 0 ;
}
int F_241 ( struct V_82 * V_83 ,
unsigned long V_84 )
{
unsigned long V_217 , V_218 ;
if ( ! V_83 -> V_161 )
return 0 ;
if ( V_83 -> V_219 )
return 0 ;
F_184 ( V_84 & V_204 , V_83 ) ;
V_217 = ( V_83 -> V_113 + ~ V_101 ) & V_101 ;
V_218 = V_83 -> V_115 & V_101 ;
if ( V_217 < V_218 )
return F_119 ( V_83 , V_84 ) ;
return 0 ;
}
void F_259 ( struct V_91 * V_92 )
{
struct V_208 * V_208 ;
int free = 0 ;
F_185 ( & V_214 ) ;
V_208 = F_249 ( V_92 ) ;
if ( V_208 && V_13 . V_208 != V_208 ) {
F_260 ( & V_208 -> V_210 ) ;
F_261 ( & V_208 -> V_215 ) ;
free = 1 ;
}
F_103 ( & V_214 ) ;
if ( free ) {
F_41 ( V_213 , & V_92 -> V_95 ) ;
F_247 ( V_208 ) ;
F_262 ( V_92 ) ;
} else if ( V_208 ) {
F_263 ( & V_92 -> V_220 ) ;
F_264 ( & V_92 -> V_220 ) ;
}
}
static void F_265 ( struct V_16 * V_16 )
{
F_266 ( V_16 , V_221 + 0 ) ;
F_199 ( V_16 ) ;
F_267 ( V_16 ) ;
}
static void F_268 ( T_10 * V_157 , T_10 * V_222 )
{
while ( -- V_222 >= V_157 ) {
T_10 V_223 = * V_222 ;
if ( ! F_177 ( V_223 ) && ! F_269 ( F_270 ( V_223 ) ) )
F_265 ( F_271 ( V_223 ) ) ;
}
}
static int F_272 ( struct V_82 * V_83 ,
unsigned long V_93 ,
T_10 * V_157 )
{
struct V_16 * V_16 = NULL ;
T_10 * V_222 ;
int V_224 = 0 , V_225 = 0 ;
bool V_226 = false , V_227 = false ;
for ( V_222 = V_157 ; V_222 < V_157 + V_31 ;
V_222 ++ , V_93 += V_155 ) {
T_10 V_223 = * V_222 ;
if ( F_177 ( V_223 ) || ( F_273 ( V_223 ) &&
F_269 ( F_270 ( V_223 ) ) ) ) {
if ( ! F_274 ( V_83 ) &&
++ V_224 <= V_62 ) {
continue;
} else {
V_225 = V_228 ;
goto V_80;
}
}
if ( ! F_273 ( V_223 ) ) {
V_225 = V_229 ;
goto V_80;
}
V_16 = F_275 ( V_83 , V_93 , V_223 ) ;
if ( F_69 ( ! V_16 ) ) {
V_225 = V_230 ;
goto V_80;
}
F_93 ( F_94 ( V_16 ) , V_16 ) ;
F_93 ( ! F_276 ( V_16 ) , V_16 ) ;
F_93 ( ! F_277 ( V_16 ) , V_16 ) ;
if ( ! F_196 ( V_16 ) ) {
V_225 = V_231 ;
goto V_80;
}
if ( F_187 ( V_16 ) != 1 + ! ! F_278 ( V_16 ) ) {
F_199 ( V_16 ) ;
V_225 = V_232 ;
goto V_80;
}
if ( F_279 ( V_223 ) ) {
V_227 = true ;
} else {
if ( F_278 ( V_16 ) && ! F_280 ( V_16 ) ) {
F_199 ( V_16 ) ;
V_225 = V_233 ;
goto V_80;
}
}
if ( F_281 ( V_16 ) ) {
F_199 ( V_16 ) ;
V_225 = V_234 ;
goto V_80;
}
F_282 ( V_16 , V_221 + 0 ) ;
F_93 ( ! F_210 ( V_16 ) , V_16 ) ;
F_93 ( F_283 ( V_16 ) , V_16 ) ;
if ( F_284 ( V_223 ) ||
F_285 ( V_16 ) || F_286 ( V_16 ) ||
F_287 ( V_83 -> V_121 , V_93 ) )
V_226 = true ;
}
if ( F_17 ( V_227 ) ) {
if ( F_17 ( V_226 ) ) {
V_225 = V_235 ;
F_288 ( V_16 , V_224 ,
V_226 , V_227 , V_225 ) ;
return 1 ;
}
} else {
V_225 = V_236 ;
}
V_80:
F_268 ( V_157 , V_222 ) ;
F_288 ( V_16 , V_224 ,
V_226 , V_227 , V_225 ) ;
return 0 ;
}
static void F_289 ( T_10 * V_157 , struct V_16 * V_16 ,
struct V_82 * V_83 ,
unsigned long V_93 ,
T_8 * V_99 )
{
T_10 * V_222 ;
for ( V_222 = V_157 ; V_222 < V_157 + V_31 ; V_222 ++ ) {
T_10 V_223 = * V_222 ;
struct V_16 * V_142 ;
if ( F_177 ( V_223 ) || F_269 ( F_270 ( V_223 ) ) ) {
F_290 ( V_16 , V_93 ) ;
F_113 ( V_83 -> V_121 , V_107 , 1 ) ;
if ( F_269 ( F_270 ( V_223 ) ) ) {
F_185 ( V_99 ) ;
F_291 ( V_83 -> V_121 , V_93 , V_222 ) ;
F_103 ( V_99 ) ;
}
} else {
V_142 = F_271 ( V_223 ) ;
F_167 ( V_16 , V_142 , V_93 , V_83 ) ;
F_93 ( F_186 ( V_142 ) != 1 , V_142 ) ;
F_265 ( V_142 ) ;
F_185 ( V_99 ) ;
F_291 ( V_83 -> V_121 , V_93 , V_222 ) ;
F_181 ( V_142 , false ) ;
F_103 ( V_99 ) ;
F_292 ( V_142 ) ;
}
V_93 += V_155 ;
V_16 ++ ;
}
}
static void F_293 ( void )
{
F_294 ( V_237 ) ;
F_295 ( & V_15 , & V_237 ) ;
F_296 (
F_297 ( V_56 ) ) ;
F_298 ( & V_15 , & V_237 ) ;
}
static bool F_299 ( int V_238 )
{
int V_149 ;
if ( ! V_239 )
return false ;
if ( V_240 [ V_238 ] )
return false ;
for ( V_149 = 0 ; V_149 < V_241 ; V_149 ++ ) {
if ( ! V_240 [ V_149 ] )
continue;
if ( F_300 ( V_238 , V_149 ) > V_242 )
return true ;
}
return false ;
}
static int F_301 ( void )
{
static int V_243 = V_244 ;
int V_238 , V_245 = 0 , V_246 = 0 ;
for ( V_238 = 0 ; V_238 < V_241 ; V_238 ++ )
if ( V_240 [ V_238 ] > V_246 ) {
V_246 = V_240 [ V_238 ] ;
V_245 = V_238 ;
}
if ( V_245 <= V_243 )
for ( V_238 = V_243 + 1 ; V_238 < V_241 ;
V_238 ++ )
if ( V_246 == V_240 [ V_238 ] ) {
V_245 = V_238 ;
break;
}
V_243 = V_245 ;
return V_245 ;
}
static bool F_302 ( struct V_16 * * V_247 , bool * V_237 )
{
if ( F_10 ( * V_247 ) ) {
if ( ! * V_237 )
return false ;
* V_237 = false ;
* V_247 = NULL ;
F_293 () ;
} else if ( * V_247 ) {
F_96 ( * V_247 ) ;
* V_247 = NULL ;
}
return true ;
}
static struct V_16 *
F_303 ( struct V_16 * * V_247 , T_6 V_94 , struct V_91 * V_92 ,
unsigned long V_93 , int V_248 )
{
F_93 ( * V_247 , * V_247 ) ;
F_304 ( & V_92 -> V_220 ) ;
* V_247 = F_305 ( V_248 , V_94 , V_24 ) ;
if ( F_69 ( ! * V_247 ) ) {
F_21 ( V_249 ) ;
* V_247 = F_142 ( - V_66 ) ;
return NULL ;
}
F_88 ( * V_247 ) ;
F_21 ( V_250 ) ;
return * V_247 ;
}
static int F_301 ( void )
{
return 0 ;
}
static inline struct V_16 * F_306 ( int V_110 )
{
struct V_16 * V_16 ;
V_16 = F_20 ( F_115 ( V_110 , 0 ) , V_24 ) ;
if ( V_16 )
F_88 ( V_16 ) ;
return V_16 ;
}
static struct V_16 * F_307 ( bool * V_237 )
{
struct V_16 * V_247 ;
do {
V_247 = F_306 ( F_308 () ) ;
if ( ! V_247 ) {
F_21 ( V_249 ) ;
if ( ! * V_237 )
return NULL ;
* V_237 = false ;
F_293 () ;
} else
F_21 ( V_250 ) ;
} while ( F_69 ( ! V_247 ) && F_17 ( F_8 () ) );
return V_247 ;
}
static bool F_302 ( struct V_16 * * V_247 , bool * V_237 )
{
if ( ! * V_247 )
* V_247 = F_307 ( V_237 ) ;
if ( F_69 ( ! * V_247 ) )
return false ;
return true ;
}
static struct V_16 *
F_303 ( struct V_16 * * V_247 , T_6 V_94 , struct V_91 * V_92 ,
unsigned long V_93 , int V_248 )
{
F_304 ( & V_92 -> V_220 ) ;
F_38 ( ! * V_247 ) ;
return * V_247 ;
}
static bool F_309 ( struct V_82 * V_83 )
{
if ( ( ! ( V_83 -> V_84 & V_205 ) && ! F_310 () ) ||
( V_83 -> V_84 & V_198 ) )
return false ;
if ( ! V_83 -> V_161 || V_83 -> V_219 )
return false ;
if ( F_311 ( V_83 ) )
return false ;
F_184 ( V_83 -> V_84 & V_204 , V_83 ) ;
return true ;
}
static void F_312 ( struct V_91 * V_92 ,
unsigned long V_93 ,
struct V_16 * * V_247 ,
struct V_82 * V_83 ,
int V_248 )
{
T_4 * V_81 , V_127 ;
T_10 * V_157 ;
T_7 V_98 ;
struct V_16 * V_159 ;
T_8 * V_251 , * V_252 ;
int V_253 = 0 , V_225 = 0 ;
unsigned long V_217 , V_218 ;
struct V_96 * V_97 ;
unsigned long V_150 ;
unsigned long V_151 ;
T_6 V_94 ;
F_38 ( V_93 & ~ V_101 ) ;
V_94 = F_115 ( F_308 () , V_154 ) |
V_254 ;
V_159 = F_303 ( V_247 , V_94 , V_92 , V_93 , V_248 ) ;
if ( ! V_159 ) {
V_225 = V_255 ;
goto V_256;
}
if ( F_69 ( F_95 ( V_159 , V_92 , V_94 , & V_97 , true ) ) ) {
V_225 = V_257 ;
goto V_256;
}
F_263 ( & V_92 -> V_220 ) ;
if ( F_69 ( F_253 ( V_92 ) ) ) {
V_225 = V_258 ;
goto V_80;
}
V_83 = F_313 ( V_92 , V_93 ) ;
if ( ! V_83 ) {
V_225 = V_259 ;
goto V_80;
}
V_217 = ( V_83 -> V_113 + ~ V_101 ) & V_101 ;
V_218 = V_83 -> V_115 & V_101 ;
if ( V_93 < V_217 || V_93 + V_114 > V_218 ) {
V_225 = V_260 ;
goto V_80;
}
if ( ! F_309 ( V_83 ) ) {
V_225 = V_261 ;
goto V_80;
}
V_81 = F_314 ( V_92 , V_93 ) ;
if ( ! V_81 ) {
V_225 = V_262 ;
goto V_80;
}
F_315 ( V_83 -> V_161 ) ;
V_157 = F_176 ( V_81 , V_93 ) ;
V_252 = F_316 ( V_92 , V_81 ) ;
V_150 = V_93 ;
V_151 = V_93 + V_114 ;
F_169 ( V_92 , V_150 , V_151 ) ;
V_251 = F_101 ( V_92 , V_81 ) ;
V_127 = F_317 ( V_83 , V_93 , V_81 ) ;
F_103 ( V_251 ) ;
F_182 ( V_92 , V_150 , V_151 ) ;
F_185 ( V_252 ) ;
V_253 = F_272 ( V_83 , V_93 , V_157 ) ;
F_103 ( V_252 ) ;
if ( F_69 ( ! V_253 ) ) {
F_179 ( V_157 ) ;
F_185 ( V_251 ) ;
F_29 ( ! F_102 ( * V_81 ) ) ;
F_172 ( V_92 , V_81 , F_318 ( V_127 ) ) ;
F_103 ( V_251 ) ;
F_319 ( V_83 -> V_161 ) ;
V_225 = V_263 ;
goto V_80;
}
F_319 ( V_83 -> V_161 ) ;
F_289 ( V_157 , V_159 , V_83 , V_93 , V_252 ) ;
F_179 ( V_157 ) ;
F_100 ( V_159 ) ;
V_98 = F_318 ( V_127 ) ;
V_127 = F_84 ( V_159 , V_83 -> V_106 ) ;
V_127 = F_82 ( F_107 ( V_127 ) , V_83 ) ;
F_180 () ;
F_185 ( V_251 ) ;
F_29 ( ! F_102 ( * V_81 ) ) ;
F_108 ( V_159 , V_83 , V_93 , true ) ;
F_109 ( V_159 , V_97 , false , true ) ;
F_110 ( V_159 , V_83 ) ;
F_111 ( V_92 , V_81 , V_98 ) ;
F_112 ( V_92 , V_93 , V_81 , V_127 ) ;
F_129 ( V_83 , V_93 , V_81 ) ;
F_103 ( V_251 ) ;
* V_247 = NULL ;
V_59 ++ ;
V_225 = V_235 ;
V_264:
F_264 ( & V_92 -> V_220 ) ;
F_320 ( V_92 , V_253 , V_225 ) ;
return;
V_256:
F_320 ( V_92 , V_253 , V_225 ) ;
return;
V_80:
F_98 ( V_159 , V_97 , true ) ;
goto V_264;
}
static int F_321 ( struct V_91 * V_92 ,
struct V_82 * V_83 ,
unsigned long V_93 ,
struct V_16 * * V_247 )
{
T_4 * V_81 ;
T_10 * V_157 , * V_222 ;
int V_45 = 0 , V_224 = 0 , V_225 = 0 ;
struct V_16 * V_16 = NULL ;
unsigned long V_265 ;
T_8 * V_99 ;
int V_248 = V_244 ;
bool V_227 = false , V_226 = false ;
F_38 ( V_93 & ~ V_101 ) ;
V_81 = F_314 ( V_92 , V_93 ) ;
if ( ! V_81 ) {
V_225 = V_262 ;
goto V_80;
}
memset ( V_240 , 0 , sizeof( V_240 ) ) ;
V_157 = F_322 ( V_92 , V_81 , V_93 , & V_99 ) ;
for ( V_265 = V_93 , V_222 = V_157 ; V_222 < V_157 + V_31 ;
V_222 ++ , V_265 += V_155 ) {
T_10 V_223 = * V_222 ;
if ( F_177 ( V_223 ) || F_269 ( F_270 ( V_223 ) ) ) {
if ( ! F_274 ( V_83 ) &&
++ V_224 <= V_62 ) {
continue;
} else {
V_225 = V_228 ;
goto V_266;
}
}
if ( ! F_273 ( V_223 ) ) {
V_225 = V_229 ;
goto V_266;
}
if ( F_279 ( V_223 ) )
V_227 = true ;
V_16 = F_275 ( V_83 , V_265 , V_223 ) ;
if ( F_69 ( ! V_16 ) ) {
V_225 = V_230 ;
goto V_266;
}
if ( F_94 ( V_16 ) ) {
V_225 = V_267 ;
goto V_266;
}
V_248 = F_163 ( V_16 ) ;
if ( F_299 ( V_248 ) ) {
V_225 = V_268 ;
goto V_266;
}
V_240 [ V_248 ] ++ ;
if ( ! F_283 ( V_16 ) ) {
V_225 = V_268 ;
goto V_266;
}
if ( F_210 ( V_16 ) ) {
V_225 = V_231 ;
goto V_266;
}
if ( ! F_276 ( V_16 ) ) {
V_225 = V_269 ;
goto V_266;
}
if ( F_187 ( V_16 ) != 1 + ! ! F_278 ( V_16 ) ) {
V_225 = V_232 ;
goto V_266;
}
if ( F_284 ( V_223 ) ||
F_285 ( V_16 ) || F_286 ( V_16 ) ||
F_287 ( V_83 -> V_121 , V_93 ) )
V_226 = true ;
}
if ( V_227 ) {
if ( V_226 ) {
V_225 = V_235 ;
V_45 = 1 ;
} else {
V_225 = V_270 ;
}
} else {
V_225 = V_236 ;
}
V_266:
F_323 ( V_157 , V_99 ) ;
if ( V_45 ) {
V_248 = F_301 () ;
F_312 ( V_92 , V_93 , V_247 , V_83 , V_248 ) ;
}
V_80:
F_324 ( V_92 , V_16 , V_227 , V_226 ,
V_224 , V_225 ) ;
return V_45 ;
}
static void F_325 ( struct V_208 * V_208 )
{
struct V_91 * V_92 = V_208 -> V_92 ;
F_38 ( V_271 != 1 && ! F_326 ( & V_214 ) ) ;
if ( F_253 ( V_92 ) ) {
F_260 ( & V_208 -> V_210 ) ;
F_261 ( & V_208 -> V_215 ) ;
F_247 ( V_208 ) ;
F_262 ( V_92 ) ;
}
}
static unsigned int F_327 ( unsigned int V_58 ,
struct V_16 * * V_247 )
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
struct V_16 * V_247 = NULL ;
unsigned int V_272 = 0 , V_273 = 0 ;
unsigned int V_58 = V_57 ;
bool V_237 = true ;
F_332 () ;
while ( V_272 < V_58 ) {
if ( ! F_302 ( & V_247 , & V_237 ) )
break;
F_168 () ;
if ( F_69 ( F_330 () || F_333 () ) )
break;
F_185 ( & V_214 ) ;
if ( ! V_13 . V_208 )
V_273 ++ ;
if ( F_328 () &&
V_273 < 2 )
V_272 += F_327 ( V_58 - V_272 ,
& V_247 ) ;
else
V_272 = V_58 ;
F_103 ( & V_214 ) ;
}
if ( ! F_334 ( V_247 ) )
F_96 ( V_247 ) ;
}
static void F_335 ( void )
{
if ( F_328 () ) {
if ( ! V_53 )
return;
F_336 ( V_15 ,
F_330 () ,
F_297 ( V_53 ) ) ;
return;
}
if ( F_8 () )
F_337 ( V_15 , F_329 () ) ;
}
static int V_11 ( void * V_274 )
{
struct V_208 * V_208 ;
F_338 () ;
F_339 ( V_275 , V_276 ) ;
while ( ! F_330 () ) {
F_331 () ;
F_335 () ;
}
F_185 ( & V_214 ) ;
V_208 = V_13 . V_208 ;
V_13 . V_208 = NULL ;
if ( V_208 )
F_325 ( V_208 ) ;
F_103 ( & V_214 ) ;
return 0 ;
}
static void F_340 ( struct V_82 * V_83 ,
unsigned long V_100 , T_4 * V_81 )
{
struct V_91 * V_92 = V_83 -> V_121 ;
T_7 V_98 ;
T_4 V_127 ;
int V_149 ;
F_170 ( V_83 , V_100 , V_81 ) ;
V_98 = F_171 ( V_92 , V_81 ) ;
F_172 ( V_92 , & V_127 , V_98 ) ;
for ( V_149 = 0 ; V_149 < V_31 ; V_149 ++ , V_100 += V_155 ) {
T_10 * V_157 , V_87 ;
V_87 = F_341 ( F_342 ( V_100 ) , V_83 -> V_106 ) ;
V_87 = F_343 ( V_87 ) ;
V_157 = F_176 ( & V_127 , V_100 ) ;
F_38 ( ! F_177 ( * V_157 ) ) ;
F_178 ( V_92 , V_100 , V_157 , V_87 ) ;
F_179 ( V_157 ) ;
}
F_180 () ;
F_172 ( V_92 , V_81 , V_98 ) ;
F_28 () ;
}
static void F_344 ( struct V_82 * V_83 , T_4 * V_81 ,
unsigned long V_100 , bool V_277 )
{
struct V_91 * V_92 = V_83 -> V_121 ;
struct V_16 * V_16 ;
T_7 V_98 ;
T_4 V_127 ;
bool V_278 , V_120 , V_147 ;
unsigned long V_118 ;
int V_149 ;
F_38 ( V_100 & ~ V_101 ) ;
F_184 ( V_83 -> V_113 > V_100 , V_83 ) ;
F_184 ( V_83 -> V_115 < V_100 + V_114 , V_83 ) ;
F_38 ( ! F_150 ( * V_81 ) && ! F_141 ( * V_81 ) ) ;
F_21 ( V_279 ) ;
if ( F_148 ( V_83 ) ) {
T_4 V_127 = F_170 ( V_83 , V_100 , V_81 ) ;
if ( F_151 ( V_127 ) )
F_28 () ;
return;
} else if ( F_151 ( * V_81 ) ) {
return F_340 ( V_83 , V_100 , V_81 ) ;
}
V_16 = F_152 ( * V_81 ) ;
F_93 ( ! F_187 ( V_16 ) , V_16 ) ;
F_345 ( V_31 - 1 , & V_16 -> V_280 ) ;
V_120 = F_139 ( * V_81 ) ;
V_278 = F_221 ( * V_81 ) ;
V_147 = F_222 ( * V_81 ) ;
F_346 ( V_83 , V_100 , V_81 ) ;
V_98 = F_171 ( V_92 , V_81 ) ;
F_172 ( V_92 , & V_127 , V_98 ) ;
for ( V_149 = 0 , V_118 = V_100 ; V_149 < V_31 ; V_149 ++ , V_118 += V_155 ) {
T_10 V_87 , * V_157 ;
if ( V_277 ) {
T_11 V_281 ;
V_281 = F_347 ( V_16 + V_149 , V_120 ) ;
V_87 = F_348 ( V_281 ) ;
} else {
V_87 = F_173 ( V_16 + V_149 , V_83 -> V_106 ) ;
V_87 = F_174 ( V_87 , V_83 ) ;
if ( ! V_120 )
V_87 = F_349 ( V_87 ) ;
if ( ! V_278 )
V_87 = F_350 ( V_87 ) ;
}
if ( V_147 )
F_351 ( V_16 + V_149 ) ;
V_157 = F_176 ( & V_127 , V_118 ) ;
F_29 ( ! F_177 ( * V_157 ) ) ;
F_178 ( V_92 , V_118 , V_157 , V_87 ) ;
F_258 ( & V_16 [ V_149 ] . V_282 ) ;
F_179 ( V_157 ) ;
}
if ( F_194 ( V_16 ) > 1 && ! F_352 ( V_16 ) ) {
for ( V_149 = 0 ; V_149 < V_31 ; V_149 ++ )
F_258 ( & V_16 [ V_149 ] . V_282 ) ;
}
if ( F_353 ( - 1 , F_354 ( V_16 ) ) ) {
F_355 ( V_16 , V_283 ) ;
if ( F_356 ( V_16 ) ) {
for ( V_149 = 0 ; V_149 < V_31 ; V_149 ++ )
F_357 ( & V_16 [ V_149 ] . V_282 ) ;
}
}
F_180 () ;
F_358 ( V_83 , V_100 , V_81 ) ;
F_172 ( V_92 , V_81 , V_98 ) ;
if ( V_277 ) {
for ( V_149 = 0 ; V_149 < V_31 ; V_149 ++ ) {
F_181 ( V_16 + V_149 , false ) ;
F_96 ( V_16 + V_149 ) ;
}
}
}
void F_359 ( struct V_82 * V_83 , T_4 * V_81 ,
unsigned long V_93 )
{
T_8 * V_99 ;
struct V_91 * V_92 = V_83 -> V_121 ;
struct V_16 * V_16 = NULL ;
unsigned long V_100 = V_93 & V_101 ;
F_169 ( V_92 , V_100 , V_100 + V_114 ) ;
V_99 = F_101 ( V_92 , V_81 ) ;
if ( F_150 ( * V_81 ) ) {
V_16 = F_152 ( * V_81 ) ;
if ( F_360 ( V_16 ) )
F_145 ( V_16 ) ;
else
V_16 = NULL ;
} else if ( ! F_141 ( * V_81 ) )
goto V_80;
F_344 ( V_83 , V_81 , V_100 , false ) ;
V_80:
F_103 ( V_99 ) ;
F_182 ( V_92 , V_100 , V_100 + V_114 ) ;
if ( V_16 ) {
F_361 ( V_16 ) ;
F_362 ( V_16 ) ;
F_199 ( V_16 ) ;
F_96 ( V_16 ) ;
}
}
static void F_363 ( struct V_82 * V_83 ,
unsigned long V_93 )
{
T_12 * V_284 ;
T_13 * V_285 ;
T_4 * V_81 ;
F_38 ( ! ( V_93 & ~ V_101 ) ) ;
V_284 = F_364 ( V_83 -> V_121 , V_93 ) ;
if ( ! F_365 ( * V_284 ) )
return;
V_285 = F_366 ( V_284 , V_93 ) ;
if ( ! F_367 ( * V_285 ) )
return;
V_81 = F_368 ( V_285 , V_93 ) ;
if ( ! F_140 ( * V_81 ) || ( ! F_150 ( * V_81 ) && ! F_141 ( * V_81 ) ) )
return;
F_190 ( V_83 , V_81 , V_93 ) ;
}
void F_369 ( struct V_82 * V_83 ,
unsigned long V_286 ,
unsigned long V_287 ,
long V_288 )
{
if ( V_286 & ~ V_101 &&
( V_286 & V_101 ) >= V_83 -> V_113 &&
( V_286 & V_101 ) + V_114 <= V_83 -> V_115 )
F_363 ( V_83 , V_286 ) ;
if ( V_287 & ~ V_101 &&
( V_287 & V_101 ) >= V_83 -> V_113 &&
( V_287 & V_101 ) + V_114 <= V_83 -> V_115 )
F_363 ( V_83 , V_287 ) ;
if ( V_288 > 0 ) {
struct V_82 * V_187 = V_83 -> V_289 ;
unsigned long V_290 = V_187 -> V_113 ;
V_290 += V_288 << V_6 ;
if ( V_290 & ~ V_101 &&
( V_290 & V_101 ) >= V_187 -> V_113 &&
( V_290 & V_101 ) + V_114 <= V_187 -> V_115 )
F_363 ( V_187 , V_290 ) ;
}
}
static void F_370 ( struct V_82 * V_83 , struct V_16 * V_16 ,
unsigned long V_93 )
{
unsigned long V_100 = V_93 & V_101 ;
T_8 * V_99 ;
T_12 * V_284 ;
T_13 * V_285 ;
T_4 * V_81 ;
T_10 * V_157 ;
int V_149 , V_291 = V_31 ;
if ( V_93 < V_83 -> V_113 ) {
int V_292 = ( V_83 -> V_113 - V_93 ) >> V_6 ;
V_16 += V_292 ;
V_291 -= V_292 ;
V_93 = V_83 -> V_113 ;
}
V_284 = F_364 ( V_83 -> V_121 , V_93 ) ;
if ( ! F_365 ( * V_284 ) )
return;
V_285 = F_366 ( V_284 , V_93 ) ;
if ( ! F_367 ( * V_285 ) )
return;
V_81 = F_368 ( V_285 , V_93 ) ;
V_99 = F_101 ( V_83 -> V_121 , V_81 ) ;
if ( ! F_140 ( * V_81 ) ) {
F_103 ( V_99 ) ;
return;
}
if ( F_150 ( * V_81 ) ) {
if ( V_16 == F_152 ( * V_81 ) )
F_344 ( V_83 , V_81 , V_100 , true ) ;
F_103 ( V_99 ) ;
return;
}
F_103 ( V_99 ) ;
V_157 = F_322 ( V_83 -> V_121 , V_81 , V_93 , & V_99 ) ;
for ( V_149 = 0 ; V_149 < V_291 ; V_149 ++ , V_93 += V_155 , V_16 ++ , V_157 ++ ) {
T_10 V_87 , V_293 ;
T_11 V_281 ;
if ( F_69 ( V_93 == V_100 + V_114 ) ) {
F_323 ( V_157 - 1 , V_99 ) ;
V_81 = F_314 ( V_83 -> V_121 , V_93 ) ;
if ( ! V_81 )
return;
V_157 = F_322 ( V_83 -> V_121 , V_81 ,
V_93 , & V_99 ) ;
}
if ( ! F_273 ( * V_157 ) )
continue;
if ( F_371 ( V_16 ) != F_270 ( * V_157 ) )
continue;
F_372 ( V_83 , V_93 , F_371 ( V_16 ) ) ;
V_87 = F_373 ( V_83 , V_93 , V_157 ) ;
if ( F_374 ( V_87 ) )
F_351 ( V_16 ) ;
V_281 = F_347 ( V_16 , F_279 ( V_87 ) ) ;
V_293 = F_348 ( V_281 ) ;
if ( F_375 ( V_87 ) )
V_293 = F_376 ( V_293 ) ;
F_178 ( V_83 -> V_121 , V_93 , V_157 , V_293 ) ;
F_181 ( V_16 , false ) ;
F_96 ( V_16 ) ;
}
F_323 ( V_157 - 1 , V_99 ) ;
}
static void F_377 ( struct V_161 * V_161 , struct V_16 * V_16 )
{
struct V_294 * V_295 ;
T_14 V_296 = F_378 ( V_16 ) ;
F_93 ( ! F_153 ( V_16 ) , V_16 ) ;
F_379 (avc, &anon_vma->rb_root, pgoff,
pgoff + HPAGE_PMD_NR - 1 ) {
unsigned long V_93 = F_380 ( V_16 , V_295 -> V_83 ) ;
F_169 ( V_295 -> V_83 -> V_121 ,
V_93 , V_93 + V_114 ) ;
F_370 ( V_295 -> V_83 , V_16 , V_93 ) ;
F_182 ( V_295 -> V_83 -> V_121 ,
V_93 , V_93 + V_114 ) ;
}
}
static void F_381 ( struct V_82 * V_83 , struct V_16 * V_16 ,
unsigned long V_93 )
{
T_8 * V_99 ;
T_4 * V_81 ;
T_10 * V_157 , V_87 ;
T_11 V_281 ;
unsigned long V_100 = V_93 & V_101 ;
int V_149 , V_291 = V_31 ;
if ( V_93 < V_83 -> V_113 ) {
int V_292 = ( V_83 -> V_113 - V_93 ) >> V_6 ;
V_16 += V_292 ;
V_291 -= V_292 ;
V_93 = V_83 -> V_113 ;
}
V_81 = F_314 ( V_83 -> V_121 , V_93 ) ;
if ( ! V_81 )
return;
V_157 = F_322 ( V_83 -> V_121 , V_81 , V_93 , & V_99 ) ;
for ( V_149 = 0 ; V_149 < V_291 ; V_149 ++ , V_93 += V_155 , V_16 ++ , V_157 ++ ) {
if ( F_69 ( V_93 == V_100 + V_114 ) ) {
F_323 ( V_157 - 1 , V_99 ) ;
V_81 = F_314 ( V_83 -> V_121 , V_93 ) ;
if ( ! V_81 )
return;
V_157 = F_322 ( V_83 -> V_121 , V_81 ,
V_93 , & V_99 ) ;
}
if ( ! F_382 ( * V_157 ) )
continue;
V_281 = F_383 ( * V_157 ) ;
if ( ! F_384 ( V_281 ) )
continue;
if ( F_385 ( V_281 ) != V_16 )
continue;
F_145 ( V_16 ) ;
F_386 ( V_16 , V_83 , V_93 , false ) ;
V_87 = F_350 ( F_173 ( V_16 , V_83 -> V_106 ) ) ;
if ( F_217 ( V_16 ) )
V_87 = F_175 ( V_87 ) ;
if ( F_387 ( V_281 ) )
V_87 = F_174 ( V_87 , V_83 ) ;
F_388 ( V_16 ) ;
F_178 ( V_83 -> V_121 , V_93 , V_157 , V_87 ) ;
F_389 ( V_83 , V_93 , V_157 ) ;
}
F_323 ( V_157 - 1 , V_99 ) ;
}
static void F_390 ( struct V_161 * V_161 , struct V_16 * V_16 )
{
struct V_294 * V_295 ;
T_14 V_296 = F_378 ( V_16 ) ;
F_379 (avc, &anon_vma->rb_root,
pgoff, pgoff + HPAGE_PMD_NR - 1 ) {
unsigned long V_93 = F_380 ( V_16 , V_295 -> V_83 ) ;
F_169 ( V_295 -> V_83 -> V_121 ,
V_93 , V_93 + V_114 ) ;
F_381 ( V_295 -> V_83 , V_16 , V_93 ) ;
F_182 ( V_295 -> V_83 -> V_121 ,
V_93 , V_93 + V_114 ) ;
}
}
static int F_391 ( struct V_16 * V_297 , int V_298 ,
struct V_299 * V_299 , struct V_88 * V_300 )
{
int V_301 ;
struct V_16 * V_302 = V_297 + V_298 ;
V_301 = F_32 ( & V_302 -> V_282 ) + 1 ;
F_93 ( F_32 ( & V_302 -> V_280 ) != 0 , V_302 ) ;
F_345 ( V_301 + 1 , & V_302 -> V_280 ) ;
V_302 -> V_95 &= ~ V_303 ;
V_302 -> V_95 |= ( V_297 -> V_95 &
( ( 1L << V_304 ) |
( 1L << V_305 ) |
( 1L << V_306 ) |
( 1L << V_307 ) |
( 1L << V_308 ) |
( 1L << V_309 ) |
( 1L << V_310 ) |
( 1L << V_311 ) ) ) ;
F_180 () ;
F_392 ( V_302 ) ;
if ( F_285 ( V_297 ) )
F_393 ( V_302 ) ;
if ( F_394 ( V_297 ) )
F_395 ( V_302 ) ;
F_93 ( V_298 > 2 && V_302 -> V_89 != V_312 ,
V_302 ) ;
V_302 -> V_89 = V_297 -> V_89 ;
V_302 -> V_313 = V_297 -> V_313 + V_298 ;
F_396 ( V_302 , F_205 ( V_297 ) ) ;
F_397 ( V_297 , V_302 , V_299 , V_300 ) ;
return V_301 ;
}
static void F_398 ( struct V_16 * V_16 , struct V_88 * V_300 )
{
struct V_16 * V_297 = F_399 ( V_16 ) ;
struct V_1 * V_1 = F_400 ( V_297 ) ;
struct V_299 * V_299 ;
int V_149 , V_314 ;
F_401 ( & V_1 -> V_315 ) ;
V_299 = F_402 ( V_297 , V_1 ) ;
F_403 ( V_297 ) ;
V_314 = 0 ;
for ( V_149 = V_31 - 1 ; V_149 >= 1 ; V_149 -- )
V_314 += F_391 ( V_297 , V_149 , V_299 , V_300 ) ;
F_404 ( V_314 , & V_297 -> V_280 ) ;
F_405 ( V_297 ) ;
F_406 ( & V_1 -> V_315 ) ;
F_390 ( F_407 ( V_297 ) , V_297 ) ;
for ( V_149 = 0 ; V_149 < V_31 ; V_149 ++ ) {
struct V_16 * V_316 = V_297 + V_149 ;
if ( V_316 == V_16 )
continue;
F_199 ( V_316 ) ;
F_96 ( V_316 ) ;
}
}
int F_408 ( struct V_16 * V_16 )
{
int V_149 , V_45 ;
F_93 ( F_409 ( V_16 ) , V_16 ) ;
if ( F_17 ( ! F_94 ( V_16 ) ) )
return F_32 ( & V_16 -> V_282 ) + 1 ;
V_45 = F_194 ( V_16 ) ;
if ( F_410 ( V_16 ) )
return V_45 ;
for ( V_149 = 0 ; V_149 < V_31 ; V_149 ++ )
V_45 += F_32 ( & V_16 [ V_149 ] . V_282 ) + 1 ;
if ( F_195 ( V_16 ) )
V_45 -= V_31 ;
return V_45 ;
}
int F_411 ( struct V_16 * V_16 , struct V_88 * V_300 )
{
struct V_16 * V_297 = F_399 ( V_16 ) ;
struct V_317 * V_318 = F_412 ( F_163 ( V_297 ) ) ;
struct V_161 * V_161 ;
int V_41 , V_301 , V_45 ;
bool V_319 ;
unsigned long V_95 ;
F_93 ( F_204 ( V_16 ) , V_16 ) ;
F_93 ( ! F_276 ( V_16 ) , V_16 ) ;
F_93 ( ! F_210 ( V_16 ) , V_16 ) ;
F_93 ( ! F_277 ( V_16 ) , V_16 ) ;
F_93 ( ! F_94 ( V_16 ) , V_16 ) ;
V_161 = F_413 ( V_297 ) ;
if ( ! V_161 ) {
V_45 = - V_320 ;
goto V_80;
}
F_315 ( V_161 ) ;
if ( F_408 ( V_297 ) != F_187 ( V_297 ) - 1 ) {
V_45 = - V_320 ;
goto V_145;
}
V_319 = F_360 ( V_16 ) ;
F_377 ( V_161 , V_297 ) ;
F_93 ( F_194 ( V_297 ) , V_297 ) ;
if ( V_319 )
F_197 () ;
F_414 ( & V_318 -> V_321 , V_95 ) ;
V_41 = F_187 ( V_297 ) ;
V_301 = F_408 ( V_297 ) ;
if ( ! V_301 && V_41 == 1 ) {
if ( ! F_13 ( F_87 ( V_297 ) ) ) {
V_318 -> V_322 -- ;
F_261 ( F_87 ( V_297 ) ) ;
}
F_415 ( & V_318 -> V_321 , V_95 ) ;
F_398 ( V_16 , V_300 ) ;
V_45 = 0 ;
} else if ( F_416 ( V_323 ) && V_301 ) {
F_415 ( & V_318 -> V_321 , V_95 ) ;
F_417 ( L_18 ,
V_301 , V_41 ) ;
if ( F_409 ( V_16 ) )
F_418 ( V_297 , NULL ) ;
F_418 ( V_16 , L_19 ) ;
F_419 () ;
} else {
F_415 ( & V_318 -> V_321 , V_95 ) ;
F_390 ( V_161 , V_297 ) ;
V_45 = - V_320 ;
}
V_145:
F_319 ( V_161 ) ;
F_420 ( V_161 ) ;
V_80:
F_21 ( ! V_45 ? V_324 : V_325 ) ;
return V_45 ;
}
void F_421 ( struct V_16 * V_16 )
{
struct V_317 * V_318 = F_412 ( F_163 ( V_16 ) ) ;
unsigned long V_95 ;
F_414 ( & V_318 -> V_321 , V_95 ) ;
if ( ! F_13 ( F_87 ( V_16 ) ) ) {
V_318 -> V_322 -- ;
F_261 ( F_87 ( V_16 ) ) ;
}
F_415 ( & V_318 -> V_321 , V_95 ) ;
F_422 ( V_16 ) ;
}
void F_423 ( struct V_16 * V_16 )
{
struct V_317 * V_318 = F_412 ( F_163 ( V_16 ) ) ;
unsigned long V_95 ;
F_93 ( ! F_424 ( V_16 ) , V_16 ) ;
F_414 ( & V_318 -> V_321 , V_95 ) ;
if ( F_13 ( F_87 ( V_16 ) ) ) {
F_257 ( F_87 ( V_16 ) , & V_318 -> V_326 ) ;
V_318 -> V_322 ++ ;
}
F_415 ( & V_318 -> V_321 , V_95 ) ;
}
static unsigned long F_425 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_317 * V_318 = F_412 ( V_30 -> V_238 ) ;
return F_426 ( V_318 -> V_322 ) ;
}
static unsigned long F_427 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_317 * V_318 = F_412 ( V_30 -> V_238 ) ;
unsigned long V_95 ;
F_428 ( V_300 ) , * V_327 , * V_187 ;
struct V_16 * V_16 ;
int V_328 = 0 ;
F_414 ( & V_318 -> V_321 , V_95 ) ;
F_429 (pos, next, &pgdata->split_queue) {
V_16 = F_430 ( ( void * ) V_327 , struct V_16 , V_89 ) ;
V_16 = F_399 ( V_16 ) ;
if ( F_431 ( V_16 ) ) {
F_432 ( F_87 ( V_16 ) , & V_300 ) ;
} else {
F_433 ( F_87 ( V_16 ) ) ;
V_318 -> V_322 -- ;
}
if ( ! -- V_30 -> V_329 )
break;
}
F_415 ( & V_318 -> V_321 , V_95 ) ;
F_429 (pos, next, &list) {
V_16 = F_430 ( ( void * ) V_327 , struct V_16 , V_89 ) ;
F_361 ( V_16 ) ;
if ( ! F_216 ( V_16 ) )
V_328 ++ ;
F_199 ( V_16 ) ;
F_96 ( V_16 ) ;
}
F_414 ( & V_318 -> V_321 , V_95 ) ;
F_434 ( & V_300 , & V_318 -> V_326 ) ;
F_415 ( & V_318 -> V_321 , V_95 ) ;
if ( ! V_328 && F_13 ( & V_318 -> V_326 ) )
return V_330 ;
return V_328 ;
}
static int F_435 ( void * V_331 , T_15 V_332 )
{
struct V_1 * V_1 ;
struct V_16 * V_16 ;
unsigned long V_119 , V_333 ;
unsigned long V_334 = 0 , V_328 = 0 ;
if ( V_332 != 1 )
return - V_42 ;
F_2 (zone) {
V_333 = F_436 ( V_1 ) ;
for ( V_119 = V_1 -> V_335 ; V_119 < V_333 ; V_119 ++ ) {
if ( ! F_437 ( V_119 ) )
continue;
V_16 = F_144 ( V_119 ) ;
if ( ! F_431 ( V_16 ) )
continue;
if ( V_1 != F_400 ( V_16 ) )
goto V_187;
if ( ! F_153 ( V_16 ) || ! F_276 ( V_16 ) ||
F_410 ( V_16 ) )
goto V_187;
V_334 ++ ;
F_361 ( V_16 ) ;
if ( ! F_216 ( V_16 ) )
V_328 ++ ;
F_199 ( V_16 ) ;
V_187:
F_96 ( V_16 ) ;
}
}
F_5 ( L_20 , V_328 , V_334 ) ;
return 0 ;
}
static int T_3 F_438 ( void )
{
void * V_45 ;
V_45 = F_439 ( L_21 , 0644 , NULL , NULL ,
& V_336 ) ;
if ( ! V_45 )
F_81 ( L_22 ) ;
return 0 ;
}
