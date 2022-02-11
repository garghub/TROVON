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
struct V_23 * V_24 , char * V_25 )
{
if ( F_17 ( V_26 , & V_27 ) )
return sprintf ( V_25 , L_1 ) ;
else if ( F_17 ( V_28 , & V_27 ) )
return sprintf ( V_25 , L_2 ) ;
else
return sprintf ( V_25 , L_3 ) ;
}
static T_1 F_26 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
const char * V_25 , T_2 V_29 )
{
T_1 V_30 = V_29 ;
if ( ! memcmp ( L_4 , V_25 ,
F_27 ( sizeof( L_4 ) - 1 , V_29 ) ) ) {
F_28 ( V_28 , & V_27 ) ;
F_29 ( V_26 , & V_27 ) ;
} else if ( ! memcmp ( L_5 , V_25 ,
F_27 ( sizeof( L_5 ) - 1 , V_29 ) ) ) {
F_28 ( V_26 , & V_27 ) ;
F_29 ( V_28 , & V_27 ) ;
} else if ( ! memcmp ( L_6 , V_25 ,
F_27 ( sizeof( L_6 ) - 1 , V_29 ) ) ) {
F_28 ( V_26 , & V_27 ) ;
F_28 ( V_28 , & V_27 ) ;
} else
V_30 = - V_31 ;
if ( V_30 > 0 ) {
int V_32 = F_30 () ;
if ( V_32 )
V_30 = V_32 ;
}
return V_30 ;
}
T_1 F_31 ( struct V_21 * V_22 ,
struct V_23 * V_24 , char * V_25 ,
enum V_33 V_34 )
{
return sprintf ( V_25 , L_7 ,
! ! F_17 ( V_34 , & V_27 ) ) ;
}
T_1 F_32 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
const char * V_25 , T_2 V_29 ,
enum V_33 V_34 )
{
unsigned long V_35 ;
int V_30 ;
V_30 = F_33 ( V_25 , 10 , & V_35 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_35 > 1 )
return - V_31 ;
if ( V_35 )
F_29 ( V_34 , & V_27 ) ;
else
F_28 ( V_34 , & V_27 ) ;
return V_29 ;
}
static T_1 F_34 ( struct V_21 * V_22 ,
struct V_23 * V_24 , char * V_25 )
{
if ( F_17 ( V_36 , & V_27 ) )
return sprintf ( V_25 , L_8 ) ;
if ( F_17 ( V_37 , & V_27 ) )
return sprintf ( V_25 , L_9 ) ;
if ( F_17 ( V_38 , & V_27 ) )
return sprintf ( V_25 , L_10 ) ;
if ( F_17 ( V_39 , & V_27 ) )
return sprintf ( V_25 , L_11 ) ;
return sprintf ( V_25 , L_12 ) ;
}
static T_1 F_35 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
const char * V_25 , T_2 V_29 )
{
if ( ! memcmp ( L_4 , V_25 ,
F_27 ( sizeof( L_4 ) - 1 , V_29 ) ) ) {
F_28 ( V_37 , & V_27 ) ;
F_28 ( V_38 , & V_27 ) ;
F_28 ( V_39 , & V_27 ) ;
F_29 ( V_36 , & V_27 ) ;
} else if ( ! memcmp ( L_13 , V_25 ,
F_27 ( sizeof( L_13 ) - 1 , V_29 ) ) ) {
F_28 ( V_36 , & V_27 ) ;
F_28 ( V_37 , & V_27 ) ;
F_28 ( V_39 , & V_27 ) ;
F_29 ( V_38 , & V_27 ) ;
} else if ( ! memcmp ( L_14 , V_25 ,
F_27 ( sizeof( L_14 ) - 1 , V_29 ) ) ) {
F_28 ( V_36 , & V_27 ) ;
F_28 ( V_38 , & V_27 ) ;
F_28 ( V_39 , & V_27 ) ;
F_29 ( V_37 , & V_27 ) ;
} else if ( ! memcmp ( L_5 , V_25 ,
F_27 ( sizeof( L_5 ) - 1 , V_29 ) ) ) {
F_28 ( V_36 , & V_27 ) ;
F_28 ( V_37 , & V_27 ) ;
F_28 ( V_38 , & V_27 ) ;
F_29 ( V_39 , & V_27 ) ;
} else if ( ! memcmp ( L_6 , V_25 ,
F_27 ( sizeof( L_6 ) - 1 , V_29 ) ) ) {
F_28 ( V_36 , & V_27 ) ;
F_28 ( V_37 , & V_27 ) ;
F_28 ( V_38 , & V_27 ) ;
F_28 ( V_39 , & V_27 ) ;
} else
return - V_31 ;
return V_29 ;
}
static T_1 F_36 ( struct V_21 * V_22 ,
struct V_23 * V_24 , char * V_25 )
{
return F_31 ( V_22 , V_24 , V_25 ,
V_40 ) ;
}
static T_1 F_37 ( struct V_21 * V_22 ,
struct V_23 * V_24 , const char * V_25 , T_2 V_29 )
{
return F_32 ( V_22 , V_24 , V_25 , V_29 ,
V_40 ) ;
}
static T_1 F_38 ( struct V_21 * V_22 ,
struct V_23 * V_24 , char * V_25 )
{
return sprintf ( V_25 , L_15 , V_41 ) ;
}
static T_1 F_39 ( struct V_21 * V_22 ,
struct V_23 * V_24 , char * V_25 )
{
return F_31 ( V_22 , V_24 , V_25 ,
V_42 ) ;
}
static T_1 F_40 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
const char * V_25 , T_2 V_29 )
{
return F_32 ( V_22 , V_24 , V_25 , V_29 ,
V_42 ) ;
}
static int T_3 F_41 ( struct V_21 * * V_43 )
{
int V_32 ;
* V_43 = F_42 ( L_16 , V_44 ) ;
if ( F_43 ( ! * V_43 ) ) {
F_44 ( L_17 ) ;
return - V_45 ;
}
V_32 = F_45 ( * V_43 , & V_46 ) ;
if ( V_32 ) {
F_44 ( L_18 ) ;
goto V_47;
}
V_32 = F_45 ( * V_43 , & V_48 ) ;
if ( V_32 ) {
F_44 ( L_18 ) ;
goto V_49;
}
return 0 ;
V_49:
F_46 ( * V_43 , & V_46 ) ;
V_47:
F_47 ( * V_43 ) ;
return V_32 ;
}
static void T_3 F_48 ( struct V_21 * V_43 )
{
F_46 ( V_43 , & V_48 ) ;
F_46 ( V_43 , & V_46 ) ;
F_47 ( V_43 ) ;
}
static inline int F_41 ( struct V_21 * * V_43 )
{
return 0 ;
}
static inline void F_48 ( struct V_21 * V_43 )
{
}
static int T_3 F_49 ( void )
{
int V_32 ;
struct V_21 * V_43 ;
if ( ! F_50 () ) {
V_27 = 0 ;
return - V_31 ;
}
F_51 ( V_9 >= V_50 ) ;
F_51 ( V_9 < 2 ) ;
V_32 = F_41 ( & V_43 ) ;
if ( V_32 )
goto V_51;
V_32 = F_52 () ;
if ( V_32 )
goto V_52;
V_32 = F_53 ( & V_53 ) ;
if ( V_32 )
goto V_54;
V_32 = F_53 ( & V_55 ) ;
if ( V_32 )
goto V_56;
if ( V_57 < ( 512 << ( 20 - V_58 ) ) ) {
V_27 = 0 ;
return 0 ;
}
V_32 = F_30 () ;
if ( V_32 )
goto V_59;
return 0 ;
V_59:
F_54 ( & V_55 ) ;
V_56:
F_54 ( & V_53 ) ;
V_54:
F_55 () ;
V_52:
F_48 ( V_43 ) ;
V_51:
return V_32 ;
}
static int T_3 F_56 ( char * V_60 )
{
int V_30 = 0 ;
if ( ! V_60 )
goto V_61;
if ( ! strcmp ( V_60 , L_4 ) ) {
F_29 ( V_26 ,
& V_27 ) ;
F_28 ( V_28 ,
& V_27 ) ;
V_30 = 1 ;
} else if ( ! strcmp ( V_60 , L_5 ) ) {
F_28 ( V_26 ,
& V_27 ) ;
F_29 ( V_28 ,
& V_27 ) ;
V_30 = 1 ;
} else if ( ! strcmp ( V_60 , L_6 ) ) {
F_28 ( V_26 ,
& V_27 ) ;
F_28 ( V_28 ,
& V_27 ) ;
V_30 = 1 ;
}
V_61:
if ( ! V_30 )
F_57 ( L_19 ) ;
return V_30 ;
}
T_4 F_58 ( T_4 V_62 , struct V_63 * V_64 )
{
if ( F_2 ( V_64 -> V_65 & V_66 ) )
V_62 = F_59 ( V_62 ) ;
return V_62 ;
}
static inline struct V_67 * F_60 ( struct V_1 * V_1 )
{
return (struct V_67 * ) & V_1 [ 2 ] . V_68 ;
}
void F_61 ( struct V_1 * V_1 )
{
F_62 ( F_60 ( V_1 ) ) ;
F_63 ( V_1 , V_69 ) ;
}
unsigned long F_64 ( struct V_70 * V_71 , unsigned long V_72 ,
T_5 V_73 , unsigned long V_15 , unsigned long V_74 )
{
unsigned long V_75 ;
T_5 V_76 = V_73 + V_72 ;
T_5 V_77 = F_65 ( V_73 , V_74 ) ;
unsigned long V_78 ;
if ( V_76 <= V_77 || ( V_76 - V_77 ) < V_74 )
return 0 ;
V_78 = V_72 + V_74 ;
if ( V_78 < V_72 || ( V_73 + V_78 ) < V_73 )
return 0 ;
V_75 = V_79 -> V_13 -> V_80 ( V_71 , 0 , V_78 ,
V_73 >> V_58 , V_15 ) ;
if ( F_66 ( V_75 ) )
return 0 ;
V_75 += ( V_73 - V_75 ) & ( V_74 - 1 ) ;
return V_75 ;
}
unsigned long F_67 ( struct V_70 * V_71 , unsigned long V_75 ,
unsigned long V_72 , unsigned long V_81 , unsigned long V_15 )
{
T_5 V_73 = ( T_5 ) V_81 << V_58 ;
if ( V_75 )
goto V_61;
if ( ! F_68 ( V_71 -> V_82 -> V_83 ) || ! F_69 ( V_84 ) )
goto V_61;
V_75 = F_64 ( V_71 , V_72 , V_73 , V_15 , V_85 ) ;
if ( V_75 )
return V_75 ;
V_61:
return V_79 -> V_13 -> V_80 ( V_71 , V_75 , V_72 , V_81 , V_15 ) ;
}
static int F_70 ( struct V_86 * V_87 , struct V_1 * V_1 ,
T_6 V_88 )
{
struct V_63 * V_64 = V_87 -> V_64 ;
struct V_89 * V_90 ;
T_7 V_91 ;
unsigned long V_92 = V_87 -> V_93 & V_94 ;
int V_30 = 0 ;
F_71 ( ! F_72 ( V_1 ) , V_1 ) ;
if ( F_73 ( V_1 , V_64 -> V_95 , V_88 , & V_90 , true ) ) {
F_74 ( V_1 ) ;
F_6 ( V_96 ) ;
return V_97 ;
}
V_91 = F_75 ( V_64 -> V_95 , V_92 ) ;
if ( F_43 ( ! V_91 ) ) {
V_30 = V_98 ;
goto V_99;
}
F_76 ( V_1 , V_92 , V_20 ) ;
F_77 ( V_1 ) ;
V_87 -> V_100 = F_78 ( V_64 -> V_95 , V_87 -> V_62 ) ;
if ( F_43 ( ! F_79 ( * V_87 -> V_62 ) ) ) {
goto V_101;
} else {
T_4 V_102 ;
V_30 = F_80 ( V_64 -> V_95 ) ;
if ( V_30 )
goto V_101;
if ( F_81 ( V_64 ) ) {
int V_30 ;
F_82 ( V_87 -> V_100 ) ;
F_83 ( V_1 , V_90 , true ) ;
F_74 ( V_1 ) ;
F_84 ( V_64 -> V_95 , V_91 ) ;
V_30 = F_85 ( V_87 , V_103 ) ;
F_86 ( V_30 & V_97 ) ;
return V_30 ;
}
V_102 = F_87 ( V_1 , V_64 -> V_104 ) ;
V_102 = F_58 ( F_88 ( V_102 ) , V_64 ) ;
F_89 ( V_1 , V_64 , V_92 , true ) ;
F_90 ( V_1 , V_90 , false , true ) ;
F_91 ( V_1 , V_64 ) ;
F_92 ( V_64 -> V_95 , V_87 -> V_62 , V_91 ) ;
F_93 ( V_64 -> V_95 , V_92 , V_87 -> V_62 , V_102 ) ;
F_94 ( V_64 -> V_95 , V_105 , V_20 ) ;
F_95 ( & V_64 -> V_95 -> V_106 ) ;
F_82 ( V_87 -> V_100 ) ;
F_6 ( V_107 ) ;
}
return 0 ;
V_101:
F_82 ( V_87 -> V_100 ) ;
V_99:
if ( V_91 )
F_84 ( V_64 -> V_95 , V_91 ) ;
F_83 ( V_1 , V_90 , true ) ;
F_74 ( V_1 ) ;
return V_30 ;
}
static inline T_6 F_96 ( struct V_63 * V_64 )
{
const bool V_108 = ! ! ( V_64 -> V_65 & V_109 ) ;
if ( F_17 ( V_36 , & V_27 ) )
return V_6 | ( V_108 ? 0 : V_110 ) ;
if ( F_17 ( V_37 , & V_27 ) )
return V_111 | V_112 ;
if ( F_17 ( V_38 , & V_27 ) )
return V_111 | ( V_108 ? V_113 :
V_112 ) ;
if ( F_17 ( V_39 , & V_27 ) )
return V_111 | ( V_108 ? V_113 :
0 ) ;
return V_111 ;
}
static bool F_97 ( T_7 V_91 , struct V_12 * V_13 ,
struct V_63 * V_64 , unsigned long V_92 , T_4 * V_62 ,
struct V_1 * V_2 )
{
T_4 V_102 ;
if ( ! F_79 ( * V_62 ) )
return false ;
V_102 = F_98 ( V_2 , V_64 -> V_104 ) ;
V_102 = F_99 ( V_102 ) ;
if ( V_91 )
F_92 ( V_13 , V_62 , V_91 ) ;
F_93 ( V_13 , V_92 , V_62 , V_102 ) ;
F_95 ( & V_13 -> V_106 ) ;
return true ;
}
int F_100 ( struct V_86 * V_87 )
{
struct V_63 * V_64 = V_87 -> V_64 ;
T_6 V_88 ;
struct V_1 * V_1 ;
unsigned long V_92 = V_87 -> V_93 & V_94 ;
if ( V_92 < V_64 -> V_114 || V_92 + V_41 > V_64 -> V_115 )
return V_97 ;
if ( F_43 ( F_101 ( V_64 ) ) )
return V_98 ;
if ( F_43 ( F_102 ( V_64 , V_64 -> V_65 ) ) )
return V_98 ;
if ( ! ( V_87 -> V_15 & V_116 ) &&
! F_103 ( V_64 -> V_95 ) &&
F_104 () ) {
T_7 V_91 ;
struct V_1 * V_2 ;
bool V_117 ;
int V_30 ;
V_91 = F_75 ( V_64 -> V_95 , V_92 ) ;
if ( F_43 ( ! V_91 ) )
return V_98 ;
V_2 = F_16 ( V_64 -> V_95 ) ;
if ( F_43 ( ! V_2 ) ) {
F_84 ( V_64 -> V_95 , V_91 ) ;
F_6 ( V_96 ) ;
return V_97 ;
}
V_87 -> V_100 = F_78 ( V_64 -> V_95 , V_87 -> V_62 ) ;
V_30 = 0 ;
V_117 = false ;
if ( F_79 ( * V_87 -> V_62 ) ) {
V_30 = F_80 ( V_64 -> V_95 ) ;
if ( V_30 ) {
F_82 ( V_87 -> V_100 ) ;
} else if ( F_81 ( V_64 ) ) {
F_82 ( V_87 -> V_100 ) ;
V_30 = F_85 ( V_87 , V_103 ) ;
F_86 ( V_30 & V_97 ) ;
} else {
F_97 ( V_91 , V_64 -> V_95 , V_64 ,
V_92 , V_87 -> V_62 , V_2 ) ;
F_82 ( V_87 -> V_100 ) ;
V_117 = true ;
}
} else
F_82 ( V_87 -> V_100 ) ;
if ( ! V_117 )
F_84 ( V_64 -> V_95 , V_91 ) ;
return V_30 ;
}
V_88 = F_96 ( V_64 ) ;
V_1 = F_105 ( V_88 , V_64 , V_92 , V_9 ) ;
if ( F_43 ( ! V_1 ) ) {
F_6 ( V_96 ) ;
return V_97 ;
}
F_61 ( V_1 ) ;
return F_70 ( V_87 , V_1 , V_88 ) ;
}
static void F_106 ( struct V_63 * V_64 , unsigned long V_75 ,
T_4 * V_62 , T_8 V_118 , T_9 V_119 , bool V_120 ,
T_7 V_91 )
{
struct V_12 * V_13 = V_64 -> V_95 ;
T_4 V_102 ;
T_10 * V_100 ;
V_100 = F_78 ( V_13 , V_62 ) ;
V_102 = F_99 ( F_107 ( V_118 , V_119 ) ) ;
if ( F_108 ( V_118 ) )
V_102 = F_109 ( V_102 ) ;
if ( V_120 ) {
V_102 = F_110 ( F_88 ( V_102 ) ) ;
V_102 = F_58 ( V_102 , V_64 ) ;
}
if ( V_91 ) {
F_92 ( V_13 , V_62 , V_91 ) ;
F_95 ( & V_13 -> V_106 ) ;
}
F_93 ( V_13 , V_75 , V_62 , V_102 ) ;
F_111 ( V_64 , V_75 , V_62 ) ;
F_82 ( V_100 ) ;
}
int F_112 ( struct V_63 * V_64 , unsigned long V_75 ,
T_4 * V_62 , T_8 V_118 , bool V_120 )
{
T_9 V_121 = V_64 -> V_104 ;
T_7 V_91 = NULL ;
F_14 ( ! ( V_64 -> V_65 & ( V_122 | V_123 ) ) ) ;
F_14 ( ( V_64 -> V_65 & ( V_122 | V_123 ) ) ==
( V_122 | V_123 ) ) ;
F_14 ( ( V_64 -> V_65 & V_122 ) && F_113 ( V_64 -> V_65 ) ) ;
F_14 ( ! F_108 ( V_118 ) ) ;
if ( V_75 < V_64 -> V_114 || V_75 >= V_64 -> V_115 )
return V_124 ;
if ( F_114 () ) {
V_91 = F_75 ( V_64 -> V_95 , V_75 ) ;
if ( ! V_91 )
return V_98 ;
}
F_115 ( V_64 , & V_121 , V_118 ) ;
F_106 ( V_64 , V_75 , V_62 , V_118 , V_121 , V_120 , V_91 ) ;
return V_125 ;
}
static T_11 F_116 ( T_11 V_126 , struct V_63 * V_64 )
{
if ( F_2 ( V_64 -> V_65 & V_66 ) )
V_126 = F_117 ( V_126 ) ;
return V_126 ;
}
static void F_118 ( struct V_63 * V_64 , unsigned long V_75 ,
T_11 * V_126 , T_8 V_118 , T_9 V_119 , bool V_120 )
{
struct V_12 * V_13 = V_64 -> V_95 ;
T_11 V_102 ;
T_10 * V_100 ;
V_100 = F_119 ( V_13 , V_126 ) ;
V_102 = F_120 ( F_121 ( V_118 , V_119 ) ) ;
if ( F_108 ( V_118 ) )
V_102 = F_122 ( V_102 ) ;
if ( V_120 ) {
V_102 = F_123 ( F_124 ( V_102 ) ) ;
V_102 = F_116 ( V_102 , V_64 ) ;
}
F_125 ( V_13 , V_75 , V_126 , V_102 ) ;
F_126 ( V_64 , V_75 , V_126 ) ;
F_82 ( V_100 ) ;
}
int F_127 ( struct V_63 * V_64 , unsigned long V_75 ,
T_11 * V_126 , T_8 V_118 , bool V_120 )
{
T_9 V_121 = V_64 -> V_104 ;
F_14 ( ! ( V_64 -> V_65 & ( V_122 | V_123 ) ) ) ;
F_14 ( ( V_64 -> V_65 & ( V_122 | V_123 ) ) ==
( V_122 | V_123 ) ) ;
F_14 ( ( V_64 -> V_65 & V_122 ) && F_113 ( V_64 -> V_65 ) ) ;
F_14 ( ! F_108 ( V_118 ) ) ;
if ( V_75 < V_64 -> V_114 || V_75 >= V_64 -> V_115 )
return V_124 ;
F_115 ( V_64 , & V_121 , V_118 ) ;
F_118 ( V_64 , V_75 , V_126 , V_118 , V_121 , V_120 ) ;
return V_125 ;
}
static void F_128 ( struct V_63 * V_64 , unsigned long V_75 ,
T_4 * V_62 )
{
T_4 V_127 ;
V_127 = F_110 ( F_88 ( * V_62 ) ) ;
if ( F_129 ( V_64 , V_75 & V_94 ,
V_62 , V_127 , 1 ) )
F_111 ( V_64 , V_75 , V_62 ) ;
}
struct V_1 * F_130 ( struct V_63 * V_64 , unsigned long V_75 ,
T_4 * V_62 , int V_15 )
{
unsigned long V_118 = F_131 ( * V_62 ) ;
struct V_12 * V_13 = V_64 -> V_95 ;
struct V_128 * V_129 ;
struct V_1 * V_1 ;
F_132 ( F_133 ( V_13 , V_62 ) ) ;
F_134 ( V_15 & V_130 , L_20 ) ;
if ( V_15 & V_131 && ! F_135 ( * V_62 ) )
return NULL ;
if ( F_136 ( * V_62 ) && F_137 ( * V_62 ) )
;
else
return NULL ;
if ( V_15 & V_132 )
F_128 ( V_64 , V_75 , V_62 ) ;
if ( ! ( V_15 & V_133 ) )
return F_138 ( - V_134 ) ;
V_118 += ( V_75 & ~ V_135 ) >> V_58 ;
V_129 = F_139 ( V_118 , NULL ) ;
if ( ! V_129 )
return F_138 ( - V_136 ) ;
V_1 = F_140 ( V_118 ) ;
F_141 ( V_1 ) ;
F_142 ( V_129 ) ;
return V_1 ;
}
int F_143 ( struct V_12 * V_137 , struct V_12 * V_138 ,
T_4 * V_139 , T_4 * V_140 , unsigned long V_75 ,
struct V_63 * V_64 )
{
T_10 * V_141 , * V_142 ;
struct V_1 * V_143 ;
T_4 V_62 ;
T_7 V_91 = NULL ;
int V_30 = - V_45 ;
if ( ! F_144 ( V_64 ) )
return 0 ;
V_91 = F_75 ( V_137 , V_75 ) ;
if ( F_43 ( ! V_91 ) )
goto V_61;
V_141 = F_78 ( V_137 , V_139 ) ;
V_142 = F_133 ( V_138 , V_140 ) ;
F_145 ( V_142 , V_144 ) ;
V_30 = - V_145 ;
V_62 = * V_140 ;
if ( F_43 ( ! F_146 ( V_62 ) ) ) {
F_84 ( V_137 , V_91 ) ;
goto V_146;
}
if ( F_147 ( V_62 ) ) {
struct V_1 * V_2 ;
V_2 = F_16 ( V_137 ) ;
F_97 ( V_91 , V_137 , V_64 , V_75 , V_139 ,
V_2 ) ;
V_30 = 0 ;
goto V_146;
}
V_143 = F_148 ( V_62 ) ;
F_71 ( ! F_149 ( V_143 ) , V_143 ) ;
F_141 ( V_143 ) ;
F_150 ( V_143 , true ) ;
F_94 ( V_137 , V_105 , V_20 ) ;
F_95 ( & V_137 -> V_106 ) ;
F_92 ( V_137 , V_139 , V_91 ) ;
F_151 ( V_138 , V_75 , V_140 ) ;
V_62 = F_152 ( F_153 ( V_62 ) ) ;
F_93 ( V_137 , V_75 , V_139 , V_62 ) ;
V_30 = 0 ;
V_146:
F_82 ( V_142 ) ;
F_82 ( V_141 ) ;
V_61:
return V_30 ;
}
static void F_154 ( struct V_63 * V_64 , unsigned long V_75 ,
T_11 * V_126 )
{
T_11 V_147 ;
V_147 = F_123 ( F_124 ( * V_126 ) ) ;
if ( F_155 ( V_64 , V_75 & V_148 ,
V_126 , V_147 , 1 ) )
F_126 ( V_64 , V_75 , V_126 ) ;
}
struct V_1 * F_156 ( struct V_63 * V_64 , unsigned long V_75 ,
T_11 * V_126 , int V_15 )
{
unsigned long V_118 = F_157 ( * V_126 ) ;
struct V_12 * V_13 = V_64 -> V_95 ;
struct V_128 * V_129 ;
struct V_1 * V_1 ;
F_132 ( F_158 ( V_13 , V_126 ) ) ;
if ( V_15 & V_131 && ! F_159 ( * V_126 ) )
return NULL ;
if ( F_160 ( * V_126 ) && F_161 ( * V_126 ) )
;
else
return NULL ;
if ( V_15 & V_132 )
F_154 ( V_64 , V_75 , V_126 ) ;
if ( ! ( V_15 & V_133 ) )
return F_138 ( - V_134 ) ;
V_118 += ( V_75 & ~ V_149 ) >> V_58 ;
V_129 = F_139 ( V_118 , NULL ) ;
if ( ! V_129 )
return F_138 ( - V_136 ) ;
V_1 = F_140 ( V_118 ) ;
F_141 ( V_1 ) ;
F_142 ( V_129 ) ;
return V_1 ;
}
int F_162 ( struct V_12 * V_137 , struct V_12 * V_138 ,
T_11 * V_150 , T_11 * V_151 , unsigned long V_75 ,
struct V_63 * V_64 )
{
T_10 * V_141 , * V_142 ;
T_11 V_126 ;
int V_30 ;
V_141 = F_119 ( V_137 , V_150 ) ;
V_142 = F_158 ( V_138 , V_151 ) ;
F_145 ( V_142 , V_144 ) ;
V_30 = - V_145 ;
V_126 = * V_151 ;
if ( F_43 ( ! F_163 ( V_126 ) && ! F_161 ( V_126 ) ) )
goto V_146;
if ( F_164 ( V_126 ) ) {
}
F_165 ( V_138 , V_75 , V_151 ) ;
V_126 = F_166 ( F_167 ( V_126 ) ) ;
F_125 ( V_137 , V_75 , V_150 , V_126 ) ;
V_30 = 0 ;
V_146:
F_82 ( V_142 ) ;
F_82 ( V_141 ) ;
return V_30 ;
}
void F_168 ( struct V_86 * V_87 , T_11 V_152 )
{
T_11 V_102 ;
unsigned long V_92 ;
bool V_120 = V_87 -> V_15 & V_116 ;
V_87 -> V_100 = F_119 ( V_87 -> V_64 -> V_95 , V_87 -> V_126 ) ;
if ( F_43 ( ! F_169 ( * V_87 -> V_126 , V_152 ) ) )
goto V_153;
V_102 = F_123 ( V_152 ) ;
if ( V_120 )
V_102 = F_124 ( V_102 ) ;
V_92 = V_87 -> V_93 & V_148 ;
if ( F_155 ( V_87 -> V_64 , V_92 , V_87 -> V_126 , V_102 , V_120 ) )
F_126 ( V_87 -> V_64 , V_87 -> V_93 , V_87 -> V_126 ) ;
V_153:
F_82 ( V_87 -> V_100 ) ;
}
void F_170 ( struct V_86 * V_87 , T_4 V_154 )
{
T_4 V_102 ;
unsigned long V_92 ;
bool V_120 = V_87 -> V_15 & V_116 ;
V_87 -> V_100 = F_78 ( V_87 -> V_64 -> V_95 , V_87 -> V_62 ) ;
if ( F_43 ( ! F_171 ( * V_87 -> V_62 , V_154 ) ) )
goto V_153;
V_102 = F_110 ( V_154 ) ;
if ( V_120 )
V_102 = F_88 ( V_102 ) ;
V_92 = V_87 -> V_93 & V_94 ;
if ( F_129 ( V_87 -> V_64 , V_92 , V_87 -> V_62 , V_102 , V_120 ) )
F_111 ( V_87 -> V_64 , V_87 -> V_93 , V_87 -> V_62 ) ;
V_153:
F_82 ( V_87 -> V_100 ) ;
}
static int F_172 ( struct V_86 * V_87 , T_4 V_154 ,
struct V_1 * V_1 )
{
struct V_63 * V_64 = V_87 -> V_64 ;
unsigned long V_92 = V_87 -> V_93 & V_94 ;
struct V_89 * V_90 ;
T_7 V_91 ;
T_4 V_127 ;
int V_30 = 0 , V_155 ;
struct V_1 * * V_156 ;
unsigned long V_157 ;
unsigned long V_158 ;
V_156 = F_173 ( sizeof( struct V_1 * ) * V_20 ,
V_159 ) ;
if ( F_43 ( ! V_156 ) ) {
V_30 |= V_98 ;
goto V_61;
}
for ( V_155 = 0 ; V_155 < V_20 ; V_155 ++ ) {
V_156 [ V_155 ] = F_174 ( V_160 , V_64 ,
V_87 -> V_93 , F_175 ( V_1 ) ) ;
if ( F_43 ( ! V_156 [ V_155 ] ||
F_73 ( V_156 [ V_155 ] , V_64 -> V_95 ,
V_159 , & V_90 , false ) ) ) {
if ( V_156 [ V_155 ] )
F_74 ( V_156 [ V_155 ] ) ;
while ( -- V_155 >= 0 ) {
V_90 = ( void * ) F_176 ( V_156 [ V_155 ] ) ;
F_177 ( V_156 [ V_155 ] , 0 ) ;
F_83 ( V_156 [ V_155 ] , V_90 ,
false ) ;
F_74 ( V_156 [ V_155 ] ) ;
}
F_178 ( V_156 ) ;
V_30 |= V_98 ;
goto V_61;
}
F_177 ( V_156 [ V_155 ] , ( unsigned long ) V_90 ) ;
}
for ( V_155 = 0 ; V_155 < V_20 ; V_155 ++ ) {
F_179 ( V_156 [ V_155 ] , V_1 + V_155 ,
V_92 + V_161 * V_155 , V_64 ) ;
F_77 ( V_156 [ V_155 ] ) ;
F_180 () ;
}
V_157 = V_92 ;
V_158 = V_92 + V_41 ;
F_181 ( V_64 -> V_95 , V_157 , V_158 ) ;
V_87 -> V_100 = F_78 ( V_64 -> V_95 , V_87 -> V_62 ) ;
if ( F_43 ( ! F_171 ( * V_87 -> V_62 , V_154 ) ) )
goto V_162;
F_71 ( ! F_149 ( V_1 ) , V_1 ) ;
F_182 ( V_64 , V_92 , V_87 -> V_62 ) ;
V_91 = F_183 ( V_64 -> V_95 , V_87 -> V_62 ) ;
F_184 ( V_64 -> V_95 , & V_127 , V_91 ) ;
for ( V_155 = 0 ; V_155 < V_20 ; V_155 ++ , V_92 += V_161 ) {
T_12 V_102 ;
V_102 = F_185 ( V_156 [ V_155 ] , V_64 -> V_104 ) ;
V_102 = F_186 ( F_187 ( V_102 ) , V_64 ) ;
V_90 = ( void * ) F_176 ( V_156 [ V_155 ] ) ;
F_177 ( V_156 [ V_155 ] , 0 ) ;
F_89 ( V_156 [ V_155 ] , V_87 -> V_64 , V_92 , false ) ;
F_90 ( V_156 [ V_155 ] , V_90 , false , false ) ;
F_91 ( V_156 [ V_155 ] , V_64 ) ;
V_87 -> V_163 = F_188 ( & V_127 , V_92 ) ;
F_86 ( ! F_189 ( * V_87 -> V_163 ) ) ;
F_190 ( V_64 -> V_95 , V_92 , V_87 -> V_163 , V_102 ) ;
F_191 ( V_87 -> V_163 ) ;
}
F_178 ( V_156 ) ;
F_192 () ;
F_184 ( V_64 -> V_95 , V_87 -> V_62 , V_91 ) ;
F_193 ( V_1 , true ) ;
F_82 ( V_87 -> V_100 ) ;
F_194 ( V_64 -> V_95 , V_157 , V_158 ) ;
V_30 |= V_164 ;
F_74 ( V_1 ) ;
V_61:
return V_30 ;
V_162:
F_82 ( V_87 -> V_100 ) ;
F_194 ( V_64 -> V_95 , V_157 , V_158 ) ;
for ( V_155 = 0 ; V_155 < V_20 ; V_155 ++ ) {
V_90 = ( void * ) F_176 ( V_156 [ V_155 ] ) ;
F_177 ( V_156 [ V_155 ] , 0 ) ;
F_83 ( V_156 [ V_155 ] , V_90 , false ) ;
F_74 ( V_156 [ V_155 ] ) ;
}
F_178 ( V_156 ) ;
goto V_61;
}
int F_195 ( struct V_86 * V_87 , T_4 V_154 )
{
struct V_63 * V_64 = V_87 -> V_64 ;
struct V_1 * V_1 = NULL , * V_165 ;
struct V_89 * V_90 ;
unsigned long V_92 = V_87 -> V_93 & V_94 ;
unsigned long V_157 ;
unsigned long V_158 ;
T_6 V_166 ;
int V_30 = 0 ;
V_87 -> V_100 = F_133 ( V_64 -> V_95 , V_87 -> V_62 ) ;
F_196 ( ! V_64 -> V_167 , V_64 ) ;
if ( F_147 ( V_154 ) )
goto V_168;
F_197 ( V_87 -> V_100 ) ;
if ( F_43 ( ! F_171 ( * V_87 -> V_62 , V_154 ) ) )
goto V_146;
V_1 = F_148 ( V_154 ) ;
F_71 ( ! F_72 ( V_1 ) || ! F_149 ( V_1 ) , V_1 ) ;
if ( F_198 ( V_1 , NULL ) == 1 ) {
T_4 V_102 ;
V_102 = F_110 ( V_154 ) ;
V_102 = F_58 ( F_88 ( V_102 ) , V_64 ) ;
if ( F_129 ( V_64 , V_92 , V_87 -> V_62 , V_102 , 1 ) )
F_111 ( V_64 , V_87 -> V_93 , V_87 -> V_62 ) ;
V_30 |= V_164 ;
goto V_146;
}
F_141 ( V_1 ) ;
F_82 ( V_87 -> V_100 ) ;
V_168:
if ( F_199 ( V_64 ) &&
! F_200 () ) {
V_166 = F_96 ( V_64 ) ;
V_165 = F_105 ( V_166 , V_64 , V_92 , V_9 ) ;
} else
V_165 = NULL ;
if ( F_2 ( V_165 ) ) {
F_61 ( V_165 ) ;
} else {
if ( ! V_1 ) {
F_201 ( V_64 , V_87 -> V_62 , V_87 -> V_93 ) ;
V_30 |= V_97 ;
} else {
V_30 = F_172 ( V_87 , V_154 , V_1 ) ;
if ( V_30 & V_98 ) {
F_201 ( V_64 , V_87 -> V_62 , V_87 -> V_93 ) ;
V_30 |= V_97 ;
}
F_74 ( V_1 ) ;
}
F_6 ( V_96 ) ;
goto V_61;
}
if ( F_43 ( F_73 ( V_165 , V_64 -> V_95 ,
V_166 , & V_90 , true ) ) ) {
F_74 ( V_165 ) ;
F_201 ( V_64 , V_87 -> V_62 , V_87 -> V_93 ) ;
if ( V_1 )
F_74 ( V_1 ) ;
V_30 |= V_97 ;
F_6 ( V_96 ) ;
goto V_61;
}
F_6 ( V_107 ) ;
if ( ! V_1 )
F_76 ( V_165 , V_92 , V_20 ) ;
else
F_202 ( V_165 , V_1 , V_92 , V_64 , V_20 ) ;
F_77 ( V_165 ) ;
V_157 = V_92 ;
V_158 = V_92 + V_41 ;
F_181 ( V_64 -> V_95 , V_157 , V_158 ) ;
F_197 ( V_87 -> V_100 ) ;
if ( V_1 )
F_74 ( V_1 ) ;
if ( F_43 ( ! F_171 ( * V_87 -> V_62 , V_154 ) ) ) {
F_82 ( V_87 -> V_100 ) ;
F_83 ( V_165 , V_90 , true ) ;
F_74 ( V_165 ) ;
goto V_169;
} else {
T_4 V_102 ;
V_102 = F_87 ( V_165 , V_64 -> V_104 ) ;
V_102 = F_58 ( F_88 ( V_102 ) , V_64 ) ;
F_182 ( V_64 , V_92 , V_87 -> V_62 ) ;
F_89 ( V_165 , V_64 , V_92 , true ) ;
F_90 ( V_165 , V_90 , false , true ) ;
F_91 ( V_165 , V_64 ) ;
F_93 ( V_64 -> V_95 , V_92 , V_87 -> V_62 , V_102 ) ;
F_111 ( V_64 , V_87 -> V_93 , V_87 -> V_62 ) ;
if ( ! V_1 ) {
F_94 ( V_64 -> V_95 , V_105 , V_20 ) ;
} else {
F_71 ( ! F_149 ( V_1 ) , V_1 ) ;
F_193 ( V_1 , true ) ;
F_74 ( V_1 ) ;
}
V_30 |= V_164 ;
}
F_82 ( V_87 -> V_100 ) ;
V_169:
F_194 ( V_64 -> V_95 , V_157 , V_158 ) ;
V_61:
return V_30 ;
V_146:
F_82 ( V_87 -> V_100 ) ;
return V_30 ;
}
static inline bool F_203 ( T_4 V_62 , unsigned int V_15 )
{
return F_135 ( V_62 ) ||
( ( V_15 & V_170 ) && ( V_15 & V_130 ) && F_204 ( V_62 ) ) ;
}
struct V_1 * F_205 ( struct V_63 * V_64 ,
unsigned long V_75 ,
T_4 * V_62 ,
unsigned int V_15 )
{
struct V_12 * V_13 = V_64 -> V_95 ;
struct V_1 * V_1 = NULL ;
F_132 ( F_133 ( V_13 , V_62 ) ) ;
if ( V_15 & V_131 && ! F_203 ( * V_62 , V_15 ) )
goto V_61;
if ( ( V_15 & V_171 ) && F_147 ( * V_62 ) )
return F_138 ( - V_136 ) ;
if ( ( V_15 & V_172 ) && F_206 ( * V_62 ) )
goto V_61;
V_1 = F_148 ( * V_62 ) ;
F_71 ( ! F_149 ( V_1 ) && ! F_207 ( V_1 ) , V_1 ) ;
if ( V_15 & V_132 )
F_128 ( V_64 , V_75 , V_62 ) ;
if ( ( V_15 & V_173 ) && ( V_64 -> V_65 & V_174 ) ) {
if ( F_208 ( V_1 ) && F_209 ( V_1 ) != 1 )
goto V_175;
if ( F_210 ( V_1 ) || ! V_1 -> V_68 )
goto V_175;
if ( ! F_211 ( V_1 ) )
goto V_175;
F_212 () ;
if ( V_1 -> V_68 && ! F_210 ( V_1 ) )
F_213 ( V_1 ) ;
F_214 ( V_1 ) ;
}
V_175:
V_1 += ( V_75 & ~ V_94 ) >> V_58 ;
F_71 ( ! F_72 ( V_1 ) && ! F_207 ( V_1 ) , V_1 ) ;
if ( V_15 & V_133 )
F_141 ( V_1 ) ;
V_61:
return V_1 ;
}
int F_215 ( struct V_86 * V_87 , T_4 V_62 )
{
struct V_63 * V_64 = V_87 -> V_64 ;
struct V_167 * V_167 = NULL ;
struct V_1 * V_1 ;
unsigned long V_92 = V_87 -> V_93 & V_94 ;
int V_176 = - 1 , V_177 = F_216 () ;
int V_178 , V_179 = - 1 ;
bool V_180 ;
bool V_181 = false ;
bool V_182 ;
int V_15 = 0 ;
V_87 -> V_100 = F_78 ( V_64 -> V_95 , V_87 -> V_62 ) ;
if ( F_43 ( ! F_171 ( V_62 , * V_87 -> V_62 ) ) )
goto V_146;
if ( F_43 ( F_217 ( * V_87 -> V_62 ) ) ) {
V_1 = F_148 ( * V_87 -> V_62 ) ;
if ( ! F_218 ( V_1 ) )
goto V_146;
F_82 ( V_87 -> V_100 ) ;
F_219 ( V_1 ) ;
F_74 ( V_1 ) ;
goto V_61;
}
V_1 = F_148 ( V_62 ) ;
F_14 ( F_220 ( V_1 ) ) ;
V_176 = F_175 ( V_1 ) ;
V_179 = F_221 ( V_1 ) ;
F_222 ( V_183 ) ;
if ( V_176 == V_177 ) {
F_222 ( V_184 ) ;
V_15 |= V_185 ;
}
if ( ! F_223 ( V_62 ) )
V_15 |= V_186 ;
V_180 = F_211 ( V_1 ) ;
V_178 = F_224 ( V_1 , V_64 , V_92 ) ;
if ( V_178 == - 1 ) {
if ( V_180 )
goto V_187;
}
if ( ! V_180 ) {
V_176 = - 1 ;
if ( ! F_218 ( V_1 ) )
goto V_146;
F_82 ( V_87 -> V_100 ) ;
F_219 ( V_1 ) ;
F_74 ( V_1 ) ;
goto V_61;
}
F_141 ( V_1 ) ;
F_82 ( V_87 -> V_100 ) ;
V_167 = F_225 ( V_1 ) ;
F_197 ( V_87 -> V_100 ) ;
if ( F_43 ( ! F_171 ( V_62 , * V_87 -> V_62 ) ) ) {
F_214 ( V_1 ) ;
F_74 ( V_1 ) ;
V_176 = - 1 ;
goto V_146;
}
if ( F_43 ( ! V_167 ) ) {
F_74 ( V_1 ) ;
V_176 = - 1 ;
goto V_187;
}
if ( F_226 ( V_64 -> V_95 ) )
F_227 ( V_64 , V_92 , V_92 + V_41 ) ;
F_82 ( V_87 -> V_100 ) ;
V_181 = F_228 ( V_64 -> V_95 , V_64 ,
V_87 -> V_62 , V_62 , V_87 -> V_93 , V_1 , V_178 ) ;
if ( V_181 ) {
V_15 |= V_188 ;
V_176 = V_178 ;
} else
V_15 |= V_189 ;
goto V_61;
V_187:
F_14 ( ! F_229 ( V_1 ) ) ;
V_182 = F_223 ( V_62 ) ;
V_62 = F_230 ( V_62 , V_64 -> V_104 ) ;
V_62 = F_110 ( V_62 ) ;
if ( V_182 )
V_62 = F_59 ( V_62 ) ;
F_93 ( V_64 -> V_95 , V_92 , V_87 -> V_62 , V_62 ) ;
F_111 ( V_64 , V_87 -> V_93 , V_87 -> V_62 ) ;
F_214 ( V_1 ) ;
V_146:
F_82 ( V_87 -> V_100 ) ;
V_61:
if ( V_167 )
F_231 ( V_167 ) ;
if ( V_176 != - 1 )
F_232 ( V_179 , V_176 , V_20 ,
V_15 ) ;
return 0 ;
}
bool F_233 ( struct V_190 * V_191 , struct V_63 * V_64 ,
T_4 * V_62 , unsigned long V_75 , unsigned long V_192 )
{
T_10 * V_100 ;
T_4 V_154 ;
struct V_1 * V_1 ;
struct V_12 * V_13 = V_191 -> V_13 ;
bool V_30 = false ;
F_234 ( V_191 , V_41 ) ;
V_100 = F_235 ( V_62 , V_64 ) ;
if ( ! V_100 )
goto V_193;
V_154 = * V_62 ;
if ( F_147 ( V_154 ) )
goto V_61;
V_1 = F_148 ( V_154 ) ;
if ( F_236 ( V_1 ) != 1 )
goto V_61;
if ( ! F_211 ( V_1 ) )
goto V_61;
if ( V_192 - V_75 != V_41 ) {
F_141 ( V_1 ) ;
F_82 ( V_100 ) ;
F_237 ( V_1 ) ;
F_214 ( V_1 ) ;
F_74 ( V_1 ) ;
goto V_193;
}
if ( F_238 ( V_1 ) )
F_239 ( V_1 ) ;
F_214 ( V_1 ) ;
if ( F_240 ( V_154 ) || F_204 ( V_154 ) ) {
F_241 ( V_64 , V_75 , V_62 ) ;
V_154 = F_152 ( V_154 ) ;
V_154 = F_242 ( V_154 ) ;
F_93 ( V_13 , V_75 , V_62 , V_154 ) ;
F_243 ( V_191 , V_62 , V_75 ) ;
}
F_244 ( V_1 ) ;
V_30 = true ;
V_61:
F_82 ( V_100 ) ;
V_193:
return V_30 ;
}
static inline void F_245 ( struct V_12 * V_13 , T_4 * V_62 )
{
T_7 V_91 ;
V_91 = F_183 ( V_13 , V_62 ) ;
F_84 ( V_13 , V_91 ) ;
F_246 ( & V_13 -> V_106 ) ;
}
int F_247 ( struct V_190 * V_191 , struct V_63 * V_64 ,
T_4 * V_62 , unsigned long V_75 )
{
T_4 V_154 ;
T_10 * V_100 ;
F_234 ( V_191 , V_41 ) ;
V_100 = F_248 ( V_62 , V_64 ) ;
if ( ! V_100 )
return 0 ;
V_154 = F_249 ( V_191 -> V_13 , V_75 , V_62 ,
V_191 -> V_194 ) ;
F_243 ( V_191 , V_62 , V_75 ) ;
if ( F_250 ( V_64 ) ) {
if ( F_114 () )
F_245 ( V_191 -> V_13 , V_62 ) ;
F_82 ( V_100 ) ;
if ( F_147 ( V_154 ) )
F_251 ( V_191 , F_148 ( V_154 ) , V_41 ) ;
} else if ( F_147 ( V_154 ) ) {
F_245 ( V_191 -> V_13 , V_62 ) ;
F_82 ( V_100 ) ;
F_251 ( V_191 , F_148 ( V_154 ) , V_41 ) ;
} else {
struct V_1 * V_1 = F_148 ( V_154 ) ;
F_193 ( V_1 , true ) ;
F_71 ( F_236 ( V_1 ) < 0 , V_1 ) ;
F_71 ( ! F_149 ( V_1 ) , V_1 ) ;
if ( F_208 ( V_1 ) ) {
F_245 ( V_191 -> V_13 , V_62 ) ;
F_94 ( V_191 -> V_13 , V_105 , - V_20 ) ;
} else {
if ( F_114 () )
F_245 ( V_191 -> V_13 , V_62 ) ;
F_94 ( V_191 -> V_13 , V_195 , - V_20 ) ;
}
F_82 ( V_100 ) ;
F_251 ( V_191 , V_1 , V_41 ) ;
}
return 1 ;
}
static inline int F_252 ( T_10 * V_196 ,
T_10 * V_197 ,
struct V_63 * V_64 )
{
return ( V_196 != V_197 ) && F_144 ( V_64 ) ;
}
bool F_253 ( struct V_63 * V_64 , unsigned long V_198 ,
unsigned long V_199 , unsigned long V_200 ,
T_4 * V_201 , T_4 * V_202 , bool * V_203 )
{
T_10 * V_204 , * V_205 ;
T_4 V_62 ;
struct V_12 * V_13 = V_64 -> V_95 ;
bool V_206 = false ;
if ( ( V_198 & ~ V_94 ) ||
( V_199 & ~ V_94 ) ||
V_200 - V_198 < V_41 )
return false ;
if ( F_254 ( ! F_79 ( * V_202 ) ) ) {
F_86 ( F_146 ( * V_202 ) ) ;
return false ;
}
V_204 = F_248 ( V_201 , V_64 ) ;
if ( V_204 ) {
V_205 = F_133 ( V_13 , V_202 ) ;
if ( V_205 != V_204 )
F_145 ( V_205 , V_144 ) ;
V_62 = F_255 ( V_13 , V_198 , V_201 ) ;
if ( F_136 ( V_62 ) && F_204 ( V_62 ) )
V_206 = true ;
F_86 ( ! F_79 ( * V_202 ) ) ;
if ( F_252 ( V_205 , V_204 , V_64 ) ) {
T_7 V_91 ;
V_91 = F_183 ( V_13 , V_201 ) ;
F_92 ( V_13 , V_202 , V_91 ) ;
}
F_93 ( V_13 , V_199 , V_202 , F_256 ( V_62 ) ) ;
if ( V_205 != V_204 )
F_82 ( V_205 ) ;
if ( V_206 )
F_227 ( V_64 , V_198 , V_198 + V_85 ) ;
else
* V_203 = true ;
F_82 ( V_204 ) ;
return true ;
}
return false ;
}
int F_257 ( struct V_63 * V_64 , T_4 * V_62 ,
unsigned long V_75 , T_9 V_207 , int V_208 )
{
struct V_12 * V_13 = V_64 -> V_95 ;
T_10 * V_100 ;
T_4 V_102 ;
bool V_209 ;
int V_30 ;
V_100 = F_248 ( V_62 , V_64 ) ;
if ( ! V_100 )
return 0 ;
V_209 = V_208 && F_135 ( * V_62 ) ;
V_30 = 1 ;
if ( V_208 && F_147 ( * V_62 ) )
goto V_153;
if ( V_208 && F_206 ( * V_62 ) )
goto V_153;
V_102 = * V_62 ;
F_241 ( V_64 , V_75 , V_62 ) ;
if ( F_204 ( * V_62 ) )
V_102 = F_88 ( V_102 ) ;
if ( F_240 ( * V_62 ) )
V_102 = F_110 ( V_102 ) ;
V_102 = F_230 ( V_102 , V_207 ) ;
if ( V_209 )
V_102 = F_258 ( V_102 ) ;
V_30 = V_20 ;
F_93 ( V_13 , V_75 , V_62 , V_102 ) ;
F_14 ( F_144 ( V_64 ) && ! V_209 && F_135 ( V_102 ) ) ;
V_153:
F_82 ( V_100 ) ;
return V_30 ;
}
T_10 * F_248 ( T_4 * V_62 , struct V_63 * V_64 )
{
T_10 * V_100 ;
V_100 = F_78 ( V_64 -> V_95 , V_62 ) ;
if ( F_2 ( F_146 ( * V_62 ) || F_137 ( * V_62 ) ) )
return V_100 ;
F_82 ( V_100 ) ;
return NULL ;
}
T_10 * F_259 ( T_11 * V_126 , struct V_63 * V_64 )
{
T_10 * V_100 ;
V_100 = F_119 ( V_64 -> V_95 , V_126 ) ;
if ( F_2 ( F_163 ( * V_126 ) || F_161 ( * V_126 ) ) )
return V_100 ;
F_82 ( V_100 ) ;
return NULL ;
}
int F_260 ( struct V_190 * V_191 , struct V_63 * V_64 ,
T_11 * V_126 , unsigned long V_75 )
{
T_11 V_152 ;
T_10 * V_100 ;
V_100 = F_259 ( V_126 , V_64 ) ;
if ( ! V_100 )
return 0 ;
V_152 = F_261 ( V_191 -> V_13 , V_75 , V_126 ,
V_191 -> V_194 ) ;
F_262 ( V_191 , V_126 , V_75 ) ;
if ( F_250 ( V_64 ) ) {
F_82 ( V_100 ) ;
} else {
F_263 () ;
}
return 1 ;
}
static void F_264 ( struct V_63 * V_64 , T_11 * V_126 ,
unsigned long V_92 )
{
F_86 ( V_92 & ~ V_148 ) ;
F_196 ( V_64 -> V_114 > V_92 , V_64 ) ;
F_196 ( V_64 -> V_115 < V_92 + V_210 , V_64 ) ;
F_86 ( ! F_163 ( * V_126 ) && ! F_161 ( * V_126 ) ) ;
F_6 ( V_211 ) ;
F_265 ( V_64 , V_92 , V_126 ) ;
}
void F_266 ( struct V_63 * V_64 , T_11 * V_126 ,
unsigned long V_93 )
{
T_10 * V_100 ;
struct V_12 * V_13 = V_64 -> V_95 ;
unsigned long V_92 = V_93 & V_148 ;
F_181 ( V_13 , V_92 , V_92 + V_210 ) ;
V_100 = F_119 ( V_13 , V_126 ) ;
if ( F_43 ( ! F_163 ( * V_126 ) && ! F_161 ( * V_126 ) ) )
goto V_61;
F_264 ( V_64 , V_126 , V_92 ) ;
V_61:
F_82 ( V_100 ) ;
F_194 ( V_13 , V_92 , V_92 + V_210 ) ;
}
static void F_267 ( struct V_63 * V_64 ,
unsigned long V_92 , T_4 * V_62 )
{
struct V_12 * V_13 = V_64 -> V_95 ;
T_7 V_91 ;
T_4 V_127 ;
int V_155 ;
F_182 ( V_64 , V_92 , V_62 ) ;
V_91 = F_183 ( V_13 , V_62 ) ;
F_184 ( V_13 , & V_127 , V_91 ) ;
for ( V_155 = 0 ; V_155 < V_20 ; V_155 ++ , V_92 += V_161 ) {
T_12 * V_163 , V_102 ;
V_102 = F_268 ( F_269 ( V_92 ) , V_64 -> V_104 ) ;
V_102 = F_270 ( V_102 ) ;
V_163 = F_188 ( & V_127 , V_92 ) ;
F_86 ( ! F_189 ( * V_163 ) ) ;
F_190 ( V_13 , V_92 , V_163 , V_102 ) ;
F_191 ( V_163 ) ;
}
F_192 () ;
F_184 ( V_13 , V_62 , V_91 ) ;
}
static void F_271 ( struct V_63 * V_64 , T_4 * V_62 ,
unsigned long V_92 , bool V_212 )
{
struct V_12 * V_13 = V_64 -> V_95 ;
struct V_1 * V_1 ;
T_7 V_91 ;
T_4 V_127 ;
bool V_213 , V_120 , V_214 , V_215 ;
unsigned long V_75 ;
int V_155 ;
F_86 ( V_92 & ~ V_94 ) ;
F_196 ( V_64 -> V_114 > V_92 , V_64 ) ;
F_196 ( V_64 -> V_115 < V_92 + V_41 , V_64 ) ;
F_86 ( ! F_146 ( * V_62 ) && ! F_137 ( * V_62 ) ) ;
F_6 ( V_216 ) ;
if ( ! F_144 ( V_64 ) ) {
V_127 = F_182 ( V_64 , V_92 , V_62 ) ;
if ( F_114 () )
F_245 ( V_13 , V_62 ) ;
if ( F_250 ( V_64 ) )
return;
V_1 = F_148 ( V_127 ) ;
if ( ! F_272 ( V_1 ) && F_240 ( V_127 ) )
F_273 ( V_1 ) ;
F_193 ( V_1 , true ) ;
F_74 ( V_1 ) ;
F_94 ( V_13 , V_195 , - V_20 ) ;
return;
} else if ( F_147 ( * V_62 ) ) {
return F_267 ( V_64 , V_92 , V_62 ) ;
}
V_1 = F_148 ( * V_62 ) ;
F_71 ( ! F_274 ( V_1 ) , V_1 ) ;
F_275 ( V_1 , V_20 - 1 ) ;
V_120 = F_135 ( * V_62 ) ;
V_213 = F_240 ( * V_62 ) ;
V_214 = F_204 ( * V_62 ) ;
V_215 = F_276 ( * V_62 ) ;
F_277 ( V_64 , V_92 , V_62 ) ;
V_91 = F_183 ( V_13 , V_62 ) ;
F_184 ( V_13 , & V_127 , V_91 ) ;
for ( V_155 = 0 , V_75 = V_92 ; V_155 < V_20 ; V_155 ++ , V_75 += V_161 ) {
T_12 V_102 , * V_163 ;
if ( V_212 ) {
T_13 V_217 ;
V_217 = F_278 ( V_1 + V_155 , V_120 ) ;
V_102 = F_279 ( V_217 ) ;
if ( V_215 )
V_102 = F_280 ( V_102 ) ;
} else {
V_102 = F_185 ( V_1 + V_155 , F_4 ( V_64 -> V_104 ) ) ;
V_102 = F_186 ( V_102 , V_64 ) ;
if ( ! V_120 )
V_102 = F_281 ( V_102 ) ;
if ( ! V_213 )
V_102 = F_282 ( V_102 ) ;
if ( V_215 )
V_102 = F_283 ( V_102 ) ;
}
if ( V_214 )
F_284 ( V_1 + V_155 ) ;
V_163 = F_188 ( & V_127 , V_75 ) ;
F_14 ( ! F_189 ( * V_163 ) ) ;
F_190 ( V_13 , V_75 , V_163 , V_102 ) ;
F_285 ( & V_1 [ V_155 ] . V_218 ) ;
F_191 ( V_163 ) ;
}
if ( F_209 ( V_1 ) > 1 && ! F_286 ( V_1 ) ) {
for ( V_155 = 0 ; V_155 < V_20 ; V_155 ++ )
F_285 ( & V_1 [ V_155 ] . V_218 ) ;
}
if ( F_287 ( - 1 , F_288 ( V_1 ) ) ) {
F_289 ( V_1 , V_219 ) ;
if ( F_290 ( V_1 ) ) {
for ( V_155 = 0 ; V_155 < V_20 ; V_155 ++ )
F_291 ( & V_1 [ V_155 ] . V_218 ) ;
}
}
F_192 () ;
F_241 ( V_64 , V_92 , V_62 ) ;
F_184 ( V_13 , V_62 , V_91 ) ;
if ( V_212 ) {
for ( V_155 = 0 ; V_155 < V_20 ; V_155 ++ ) {
F_193 ( V_1 + V_155 , false ) ;
F_74 ( V_1 + V_155 ) ;
}
}
}
void F_292 ( struct V_63 * V_64 , T_4 * V_62 ,
unsigned long V_93 , bool V_212 , struct V_1 * V_1 )
{
T_10 * V_100 ;
struct V_12 * V_13 = V_64 -> V_95 ;
unsigned long V_92 = V_93 & V_94 ;
F_181 ( V_13 , V_92 , V_92 + V_41 ) ;
V_100 = F_78 ( V_13 , V_62 ) ;
F_86 ( V_212 && ! V_1 ) ;
if ( V_1 && V_1 != F_148 ( * V_62 ) )
goto V_61;
if ( F_146 ( * V_62 ) ) {
V_1 = F_148 ( * V_62 ) ;
if ( F_293 ( V_1 ) )
F_294 ( V_1 ) ;
} else if ( ! F_137 ( * V_62 ) )
goto V_61;
F_271 ( V_64 , V_62 , V_92 , V_212 ) ;
V_61:
F_82 ( V_100 ) ;
F_194 ( V_13 , V_92 , V_92 + V_41 ) ;
}
void F_295 ( struct V_63 * V_64 , unsigned long V_93 ,
bool V_212 , struct V_1 * V_1 )
{
T_14 * V_220 ;
T_15 * V_221 ;
T_11 * V_126 ;
T_4 * V_62 ;
V_220 = F_296 ( V_64 -> V_95 , V_93 ) ;
if ( ! F_297 ( * V_220 ) )
return;
V_221 = F_298 ( V_220 , V_93 ) ;
if ( ! F_299 ( * V_221 ) )
return;
V_126 = F_300 ( V_221 , V_93 ) ;
if ( ! F_160 ( * V_126 ) )
return;
V_62 = F_301 ( V_126 , V_93 ) ;
F_292 ( V_64 , V_62 , V_93 , V_212 , V_1 ) ;
}
void F_302 ( struct V_63 * V_64 ,
unsigned long V_222 ,
unsigned long V_223 ,
long V_224 )
{
if ( V_222 & ~ V_94 &&
( V_222 & V_94 ) >= V_64 -> V_114 &&
( V_222 & V_94 ) + V_41 <= V_64 -> V_115 )
F_295 ( V_64 , V_222 , false , NULL ) ;
if ( V_223 & ~ V_94 &&
( V_223 & V_94 ) >= V_64 -> V_114 &&
( V_223 & V_94 ) + V_41 <= V_64 -> V_115 )
F_295 ( V_64 , V_223 , false , NULL ) ;
if ( V_224 > 0 ) {
struct V_63 * V_192 = V_64 -> V_225 ;
unsigned long V_226 = V_192 -> V_114 ;
V_226 += V_224 << V_58 ;
if ( V_226 & ~ V_94 &&
( V_226 & V_94 ) >= V_192 -> V_114 &&
( V_226 & V_94 ) + V_41 <= V_192 -> V_115 )
F_295 ( V_192 , V_226 , false , NULL ) ;
}
}
static void F_303 ( struct V_1 * V_1 )
{
enum V_227 V_227 = V_228 | V_229 |
V_230 | V_231 ;
bool V_232 ;
F_71 ( ! F_149 ( V_1 ) , V_1 ) ;
if ( F_208 ( V_1 ) )
V_227 |= V_233 ;
V_232 = F_304 ( V_1 , V_227 ) ;
F_71 ( ! V_232 , V_1 ) ;
}
static void F_305 ( struct V_1 * V_1 )
{
int V_155 ;
if ( F_306 ( V_1 ) ) {
F_307 ( V_1 , V_1 , true ) ;
} else {
for ( V_155 = 0 ; V_155 < V_20 ; V_155 ++ )
F_307 ( V_1 + V_155 , V_1 + V_155 , true ) ;
}
}
static void F_308 ( struct V_1 * V_234 , int V_235 ,
struct V_236 * V_236 , struct V_67 * V_237 )
{
struct V_1 * V_238 = V_234 + V_235 ;
F_71 ( F_21 ( & V_238 -> V_218 ) != - 1 , V_238 ) ;
F_71 ( F_309 ( V_238 ) != 0 , V_238 ) ;
if ( F_208 ( V_234 ) && ! F_310 ( V_234 ) ) {
F_311 ( V_238 ) ;
} else {
F_275 ( V_238 , 2 ) ;
}
V_238 -> V_15 &= ~ V_239 ;
V_238 -> V_15 |= ( V_234 -> V_15 &
( ( 1L << V_240 ) |
( 1L << V_241 ) |
( 1L << V_242 ) |
( 1L << V_243 ) |
( 1L << V_244 ) |
( 1L << V_245 ) |
( 1L << V_246 ) |
( 1L << V_247 ) |
( 1L << V_248 ) ) ) ;
F_192 () ;
F_312 ( V_238 ) ;
if ( F_313 ( V_234 ) )
F_314 ( V_238 ) ;
if ( F_315 ( V_234 ) )
F_316 ( V_238 ) ;
F_71 ( V_235 > 2 && V_238 -> V_68 != V_249 ,
V_238 ) ;
V_238 -> V_68 = V_234 -> V_68 ;
V_238 -> V_250 = V_234 -> V_250 + V_235 ;
F_317 ( V_238 , F_221 ( V_234 ) ) ;
F_318 ( V_234 , V_238 , V_236 , V_237 ) ;
}
static void F_319 ( struct V_1 * V_1 , struct V_67 * V_237 ,
unsigned long V_15 )
{
struct V_1 * V_234 = F_320 ( V_1 ) ;
struct V_251 * V_251 = F_321 ( V_234 ) ;
struct V_236 * V_236 ;
T_16 V_223 = - 1 ;
int V_155 ;
V_236 = F_322 ( V_234 , V_251 -> V_252 ) ;
F_323 ( V_234 ) ;
if ( ! F_208 ( V_1 ) )
V_223 = F_324 ( F_325 ( V_234 -> V_68 -> V_83 ) , V_161 ) ;
for ( V_155 = V_20 - 1 ; V_155 >= 1 ; V_155 -- ) {
F_308 ( V_234 , V_155 , V_236 , V_237 ) ;
if ( V_234 [ V_155 ] . V_250 >= V_223 ) {
F_326 ( V_234 + V_155 ) ;
F_327 ( V_234 + V_155 , NULL ) ;
if ( F_69 ( V_253 ) && F_328 ( V_234 ) )
F_329 ( V_234 -> V_68 -> V_83 , 1 ) ;
F_74 ( V_234 + V_155 ) ;
}
}
F_330 ( V_234 ) ;
if ( F_208 ( V_234 ) ) {
if ( F_310 ( V_234 ) )
F_275 ( V_234 , 2 ) ;
else
F_311 ( V_234 ) ;
} else {
F_275 ( V_234 , 2 ) ;
F_82 ( & V_234 -> V_68 -> V_254 ) ;
}
F_331 ( F_332 ( F_321 ( V_234 ) ) , V_15 ) ;
F_305 ( V_234 ) ;
for ( V_155 = 0 ; V_155 < V_20 ; V_155 ++ ) {
struct V_1 * V_255 = V_234 + V_155 ;
if ( V_255 == V_1 )
continue;
F_214 ( V_255 ) ;
F_74 ( V_255 ) ;
}
}
int F_333 ( struct V_1 * V_1 )
{
int V_155 , V_256 , V_30 ;
F_71 ( F_334 ( V_1 ) , V_1 ) ;
if ( F_2 ( ! F_72 ( V_1 ) ) )
return F_21 ( & V_1 -> V_218 ) + 1 ;
V_256 = F_209 ( V_1 ) ;
if ( F_335 ( V_1 ) )
return V_256 ;
V_30 = V_256 ;
for ( V_155 = 0 ; V_155 < V_20 ; V_155 ++ )
V_30 += F_21 ( & V_1 [ V_155 ] . V_218 ) + 1 ;
if ( ! F_208 ( V_1 ) )
return V_30 - V_256 * V_20 ;
if ( F_210 ( V_1 ) )
V_30 -= V_20 ;
return V_30 ;
}
int F_198 ( struct V_1 * V_1 , int * F_333 )
{
int V_155 , V_30 , V_257 , V_258 ;
F_71 ( F_335 ( V_1 ) , V_1 ) ;
if ( F_2 ( ! F_336 ( V_1 ) ) ) {
V_258 = F_21 ( & V_1 -> V_218 ) + 1 ;
if ( F_333 )
* F_333 = V_258 ;
return V_258 ;
}
V_1 = F_320 ( V_1 ) ;
V_257 = V_30 = 0 ;
for ( V_155 = 0 ; V_155 < V_20 ; V_155 ++ ) {
V_258 = F_21 ( & V_1 [ V_155 ] . V_218 ) + 1 ;
V_30 = F_337 ( V_30 , V_258 ) ;
V_257 += V_258 ;
}
if ( F_210 ( V_1 ) ) {
V_30 -= 1 ;
V_257 -= V_20 ;
}
V_258 = F_209 ( V_1 ) ;
V_30 += V_258 ;
V_257 += V_258 ;
if ( F_333 )
* F_333 = V_257 ;
return V_30 ;
}
bool F_338 ( struct V_1 * V_1 , int * V_259 )
{
int V_260 ;
if ( F_208 ( V_1 ) )
V_260 = F_310 ( V_1 ) ? V_20 : 0 ;
else
V_260 = V_20 ;
if ( V_259 )
* V_259 = V_260 ;
return F_333 ( V_1 ) == F_274 ( V_1 ) - V_260 - 1 ;
}
int F_339 ( struct V_1 * V_1 , struct V_67 * V_237 )
{
struct V_1 * V_234 = F_320 ( V_1 ) ;
struct V_261 * V_262 = F_340 ( F_175 ( V_234 ) ) ;
struct V_167 * V_167 = NULL ;
struct V_263 * V_68 = NULL ;
int V_29 , V_258 , V_260 , V_30 ;
bool V_264 ;
unsigned long V_15 ;
F_71 ( F_220 ( V_1 ) , V_1 ) ;
F_71 ( ! F_229 ( V_1 ) , V_1 ) ;
F_71 ( ! F_72 ( V_1 ) , V_1 ) ;
if ( F_208 ( V_234 ) ) {
V_167 = F_341 ( V_234 ) ;
if ( ! V_167 ) {
V_30 = - V_265 ;
goto V_61;
}
V_68 = NULL ;
F_342 ( V_167 ) ;
} else {
V_68 = V_234 -> V_68 ;
if ( ! V_68 ) {
V_30 = - V_265 ;
goto V_61;
}
V_167 = NULL ;
F_343 ( V_68 ) ;
}
if ( ! F_338 ( V_234 , & V_260 ) ) {
V_30 = - V_265 ;
goto V_146;
}
V_264 = F_293 ( V_1 ) ;
F_303 ( V_234 ) ;
F_71 ( F_209 ( V_234 ) , V_234 ) ;
if ( V_264 )
F_212 () ;
F_344 ( F_332 ( F_321 ( V_234 ) ) , V_15 ) ;
if ( V_68 ) {
void * * V_266 ;
F_197 ( & V_68 -> V_254 ) ;
V_266 = F_345 ( & V_68 -> V_267 ,
F_346 ( V_234 ) ) ;
if ( F_347 ( V_266 ,
& V_68 -> V_254 ) != V_234 )
goto V_268;
}
F_197 ( & V_262 -> V_269 ) ;
V_29 = F_274 ( V_234 ) ;
V_258 = F_333 ( V_234 ) ;
if ( ! V_258 && F_348 ( V_234 , 1 + V_260 ) ) {
if ( ! F_349 ( F_60 ( V_234 ) ) ) {
V_262 -> V_270 -- ;
F_350 ( F_60 ( V_234 ) ) ;
}
if ( V_68 )
F_289 ( V_1 , V_271 ) ;
F_82 ( & V_262 -> V_269 ) ;
F_319 ( V_1 , V_237 , V_15 ) ;
V_30 = 0 ;
} else {
if ( F_69 ( V_272 ) && V_258 ) {
F_351 ( L_21 ,
V_258 , V_29 ) ;
if ( F_334 ( V_1 ) )
F_352 ( V_234 , NULL ) ;
F_352 ( V_1 , L_22 ) ;
F_263 () ;
}
F_82 ( & V_262 -> V_269 ) ;
V_268: if ( V_68 )
F_82 ( & V_68 -> V_254 ) ;
F_331 ( F_332 ( F_321 ( V_234 ) ) , V_15 ) ;
F_305 ( V_234 ) ;
V_30 = - V_265 ;
}
V_146:
if ( V_167 ) {
F_353 ( V_167 ) ;
F_354 ( V_167 ) ;
}
if ( V_68 )
F_355 ( V_68 ) ;
V_61:
F_6 ( ! V_30 ? V_273 : V_274 ) ;
return V_30 ;
}
void F_356 ( struct V_1 * V_1 )
{
struct V_261 * V_262 = F_340 ( F_175 ( V_1 ) ) ;
unsigned long V_15 ;
F_344 ( & V_262 -> V_269 , V_15 ) ;
if ( ! F_349 ( F_60 ( V_1 ) ) ) {
V_262 -> V_270 -- ;
F_350 ( F_60 ( V_1 ) ) ;
}
F_331 ( & V_262 -> V_269 , V_15 ) ;
F_357 ( V_1 ) ;
}
void F_358 ( struct V_1 * V_1 )
{
struct V_261 * V_262 = F_340 ( F_175 ( V_1 ) ) ;
unsigned long V_15 ;
F_71 ( ! F_306 ( V_1 ) , V_1 ) ;
F_344 ( & V_262 -> V_269 , V_15 ) ;
if ( F_349 ( F_60 ( V_1 ) ) ) {
F_6 ( V_275 ) ;
F_359 ( F_60 ( V_1 ) , & V_262 -> V_276 ) ;
V_262 -> V_270 ++ ;
}
F_331 ( & V_262 -> V_269 , V_15 ) ;
}
static unsigned long F_360 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_261 * V_262 = F_340 ( V_19 -> V_277 ) ;
return F_361 ( V_262 -> V_270 ) ;
}
static unsigned long F_362 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_261 * V_262 = F_340 ( V_19 -> V_277 ) ;
unsigned long V_15 ;
F_363 ( V_237 ) , * V_278 , * V_192 ;
struct V_1 * V_1 ;
int V_279 = 0 ;
F_344 ( & V_262 -> V_269 , V_15 ) ;
F_364 (pos, next, &pgdata->split_queue) {
V_1 = F_365 ( ( void * ) V_278 , struct V_1 , V_68 ) ;
V_1 = F_320 ( V_1 ) ;
if ( F_218 ( V_1 ) ) {
F_366 ( F_60 ( V_1 ) , & V_237 ) ;
} else {
F_367 ( F_60 ( V_1 ) ) ;
V_262 -> V_270 -- ;
}
if ( ! -- V_19 -> V_280 )
break;
}
F_331 ( & V_262 -> V_269 , V_15 ) ;
F_364 (pos, next, &list) {
V_1 = F_365 ( ( void * ) V_278 , struct V_1 , V_68 ) ;
F_368 ( V_1 ) ;
if ( ! F_237 ( V_1 ) )
V_279 ++ ;
F_214 ( V_1 ) ;
F_74 ( V_1 ) ;
}
F_344 ( & V_262 -> V_269 , V_15 ) ;
F_369 ( & V_237 , & V_262 -> V_276 ) ;
F_331 ( & V_262 -> V_269 , V_15 ) ;
if ( ! V_279 && F_349 ( & V_262 -> V_276 ) )
return V_281 ;
return V_279 ;
}
static int F_370 ( void * V_282 , T_17 V_283 )
{
struct V_251 * V_251 ;
struct V_1 * V_1 ;
unsigned long V_118 , V_284 ;
unsigned long V_285 = 0 , V_279 = 0 ;
if ( V_283 != 1 )
return - V_31 ;
F_371 (zone) {
V_284 = F_372 ( V_251 ) ;
for ( V_118 = V_251 -> V_286 ; V_118 < V_284 ; V_118 ++ ) {
if ( ! F_373 ( V_118 ) )
continue;
V_1 = F_140 ( V_118 ) ;
if ( ! F_218 ( V_1 ) )
continue;
if ( V_251 != F_321 ( V_1 ) )
goto V_192;
if ( ! F_149 ( V_1 ) || F_335 ( V_1 ) || ! F_374 ( V_1 ) )
goto V_192;
V_285 ++ ;
F_368 ( V_1 ) ;
if ( ! F_237 ( V_1 ) )
V_279 ++ ;
F_214 ( V_1 ) ;
V_192:
F_74 ( V_1 ) ;
}
}
F_375 ( L_23 , V_279 , V_285 ) ;
return 0 ;
}
static int T_3 F_376 ( void )
{
void * V_30 ;
V_30 = F_377 ( L_24 , 0200 , NULL , NULL ,
& V_287 ) ;
if ( ! V_30 )
F_57 ( L_25 ) ;
return 0 ;
}
