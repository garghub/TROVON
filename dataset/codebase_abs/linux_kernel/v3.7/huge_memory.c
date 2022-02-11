static int F_1 ( void )
{
struct V_1 * V_1 ;
int V_2 = 0 ;
unsigned long V_3 ;
extern int V_4 ;
if ( ! F_2 () )
return 0 ;
F_3 (zone)
V_2 ++ ;
V_3 = V_5 * V_2 * 2 ;
V_3 += V_5 * V_2 *
V_6 * V_6 ;
V_3 = F_4 ( V_3 ,
( unsigned long ) F_5 () / 20 ) ;
V_3 <<= ( V_7 - 10 ) ;
if ( V_3 > V_4 )
V_4 = V_3 ;
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
static T_1 F_16 ( struct V_15 * V_16 ,
struct V_17 * V_18 , char * V_19 ,
enum V_20 V_21 ,
enum V_20 V_22 )
{
if ( F_17 ( V_21 , & V_23 ) ) {
F_18 ( F_17 ( V_22 , & V_23 ) ) ;
return sprintf ( V_19 , L_3 ) ;
} else if ( F_17 ( V_22 , & V_23 ) )
return sprintf ( V_19 , L_4 ) ;
else
return sprintf ( V_19 , L_5 ) ;
}
static T_1 F_19 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
const char * V_19 , T_2 V_24 ,
enum V_20 V_21 ,
enum V_20 V_22 )
{
if ( ! memcmp ( L_6 , V_19 ,
F_4 ( sizeof( L_6 ) - 1 , V_24 ) ) ) {
F_20 ( V_21 , & V_23 ) ;
F_21 ( V_22 , & V_23 ) ;
} else if ( ! memcmp ( L_7 , V_19 ,
F_4 ( sizeof( L_7 ) - 1 , V_24 ) ) ) {
F_21 ( V_21 , & V_23 ) ;
F_20 ( V_22 , & V_23 ) ;
} else if ( ! memcmp ( L_8 , V_19 ,
F_4 ( sizeof( L_8 ) - 1 , V_24 ) ) ) {
F_21 ( V_21 , & V_23 ) ;
F_21 ( V_22 , & V_23 ) ;
} else
return - V_25 ;
return V_24 ;
}
static T_1 F_22 ( struct V_15 * V_16 ,
struct V_17 * V_18 , char * V_19 )
{
return F_16 ( V_16 , V_18 , V_19 ,
V_26 ,
V_27 ) ;
}
static T_1 F_23 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
const char * V_19 , T_2 V_24 )
{
T_1 V_28 ;
V_28 = F_19 ( V_16 , V_18 , V_19 , V_24 ,
V_26 ,
V_27 ) ;
if ( V_28 > 0 ) {
int V_8 ;
F_24 ( & V_29 ) ;
V_8 = F_7 () ;
F_25 ( & V_29 ) ;
if ( V_8 )
V_28 = V_8 ;
}
return V_28 ;
}
static T_1 F_26 ( struct V_15 * V_16 ,
struct V_17 * V_18 , char * V_19 ,
enum V_20 V_30 )
{
return sprintf ( V_19 , L_9 ,
! ! F_17 ( V_30 , & V_23 ) ) ;
}
static T_1 F_27 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
const char * V_19 , T_2 V_24 ,
enum V_20 V_30 )
{
unsigned long V_31 ;
int V_28 ;
V_28 = F_28 ( V_19 , 10 , & V_31 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( V_31 > 1 )
return - V_25 ;
if ( V_31 )
F_20 ( V_30 , & V_23 ) ;
else
F_21 ( V_30 , & V_23 ) ;
return V_24 ;
}
static T_1 F_29 ( struct V_15 * V_16 ,
struct V_17 * V_18 , char * V_19 )
{
return F_16 ( V_16 , V_18 , V_19 ,
V_32 ,
V_33 ) ;
}
static T_1 F_30 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
const char * V_19 , T_2 V_24 )
{
return F_19 ( V_16 , V_18 , V_19 , V_24 ,
V_32 ,
V_33 ) ;
}
static T_1 F_31 ( struct V_15 * V_16 ,
struct V_17 * V_18 , char * V_19 )
{
return F_26 ( V_16 , V_18 , V_19 ,
V_34 ) ;
}
static T_1 F_32 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
const char * V_19 , T_2 V_24 )
{
return F_27 ( V_16 , V_18 , V_19 , V_24 ,
V_34 ) ;
}
static T_1 F_33 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
char * V_19 )
{
return sprintf ( V_19 , L_10 , V_35 ) ;
}
static T_1 F_34 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
const char * V_19 , T_2 V_24 )
{
unsigned long V_36 ;
int V_8 ;
V_8 = F_35 ( V_19 , 10 , & V_36 ) ;
if ( V_8 || V_36 > V_37 )
return - V_25 ;
V_35 = V_36 ;
F_14 ( & V_14 ) ;
return V_24 ;
}
static T_1 F_36 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
char * V_19 )
{
return sprintf ( V_19 , L_10 , V_38 ) ;
}
static T_1 F_37 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
const char * V_19 , T_2 V_24 )
{
unsigned long V_36 ;
int V_8 ;
V_8 = F_35 ( V_19 , 10 , & V_36 ) ;
if ( V_8 || V_36 > V_37 )
return - V_25 ;
V_38 = V_36 ;
F_14 ( & V_14 ) ;
return V_24 ;
}
static T_1 F_38 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
char * V_19 )
{
return sprintf ( V_19 , L_10 , V_39 ) ;
}
static T_1 F_39 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
const char * V_19 , T_2 V_24 )
{
int V_8 ;
unsigned long V_40 ;
V_8 = F_35 ( V_19 , 10 , & V_40 ) ;
if ( V_8 || ! V_40 || V_40 > V_37 )
return - V_25 ;
V_39 = V_40 ;
return V_24 ;
}
static T_1 F_40 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
char * V_19 )
{
return sprintf ( V_19 , L_10 , V_41 ) ;
}
static T_1 F_41 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
char * V_19 )
{
return sprintf ( V_19 , L_10 , V_42 ) ;
}
static T_1 F_42 ( struct V_15 * V_16 ,
struct V_17 * V_18 , char * V_19 )
{
return F_26 ( V_16 , V_18 , V_19 ,
V_43 ) ;
}
static T_1 F_43 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
const char * V_19 , T_2 V_24 )
{
return F_27 ( V_16 , V_18 , V_19 , V_24 ,
V_43 ) ;
}
static T_1 F_44 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
char * V_19 )
{
return sprintf ( V_19 , L_10 , V_44 ) ;
}
static T_1 F_45 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
const char * V_19 , T_2 V_24 )
{
int V_8 ;
unsigned long V_45 ;
V_8 = F_35 ( V_19 , 10 , & V_45 ) ;
if ( V_8 || V_45 > V_46 - 1 )
return - V_25 ;
V_44 = V_45 ;
return V_24 ;
}
static int T_3 F_46 ( struct V_15 * * V_47 )
{
int V_8 ;
* V_47 = F_47 ( L_11 , V_48 ) ;
if ( F_9 ( ! * V_47 ) ) {
F_11 ( V_11 L_12 ) ;
return - V_49 ;
}
V_8 = F_48 ( * V_47 , & V_50 ) ;
if ( V_8 ) {
F_11 ( V_11 L_13 ) ;
goto V_51;
}
V_8 = F_48 ( * V_47 , & V_52 ) ;
if ( V_8 ) {
F_11 ( V_11 L_13 ) ;
goto V_53;
}
return 0 ;
V_53:
F_49 ( * V_47 , & V_50 ) ;
V_51:
F_50 ( * V_47 ) ;
return V_8 ;
}
static void T_3 F_51 ( struct V_15 * V_47 )
{
F_49 ( V_47 , & V_52 ) ;
F_49 ( V_47 , & V_50 ) ;
F_50 ( V_47 ) ;
}
static inline int F_46 ( struct V_15 * * V_47 )
{
return 0 ;
}
static inline void F_51 ( struct V_15 * V_47 )
{
}
static int T_3 F_52 ( void )
{
int V_8 ;
struct V_15 * V_47 ;
if ( ! F_53 () ) {
V_23 = 0 ;
return - V_25 ;
}
V_8 = F_46 ( & V_47 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_54 () ;
if ( V_8 )
goto V_54;
V_8 = F_55 () ;
if ( V_8 ) {
F_56 () ;
goto V_54;
}
if ( V_55 < ( 512 << ( 20 - V_7 ) ) )
V_23 = 0 ;
F_7 () ;
return 0 ;
V_54:
F_51 ( V_47 ) ;
return V_8 ;
}
static int T_3 F_57 ( char * V_56 )
{
int V_28 = 0 ;
if ( ! V_56 )
goto V_54;
if ( ! strcmp ( V_56 , L_6 ) ) {
F_20 ( V_26 ,
& V_23 ) ;
F_21 ( V_27 ,
& V_23 ) ;
V_28 = 1 ;
} else if ( ! strcmp ( V_56 , L_7 ) ) {
F_21 ( V_26 ,
& V_23 ) ;
F_20 ( V_27 ,
& V_23 ) ;
V_28 = 1 ;
} else if ( ! strcmp ( V_56 , L_8 ) ) {
F_21 ( V_26 ,
& V_23 ) ;
F_21 ( V_27 ,
& V_23 ) ;
V_28 = 1 ;
}
V_54:
if ( ! V_28 )
F_11 ( V_57
L_14 ) ;
return V_28 ;
}
static inline T_4 F_58 ( T_4 V_58 , struct V_59 * V_60 )
{
if ( F_59 ( V_60 -> V_61 & V_62 ) )
V_58 = F_60 ( V_58 ) ;
return V_58 ;
}
static int F_61 ( struct V_63 * V_64 ,
struct V_59 * V_60 ,
unsigned long V_65 , T_4 * V_58 ,
struct V_66 * V_66 )
{
T_5 V_67 ;
F_18 ( ! F_62 ( V_66 ) ) ;
V_67 = F_63 ( V_64 , V_65 ) ;
if ( F_9 ( ! V_67 ) )
return V_68 ;
F_64 ( V_66 , V_65 , V_46 ) ;
F_65 ( V_66 ) ;
F_66 ( & V_64 -> V_69 ) ;
if ( F_9 ( ! F_67 ( * V_58 ) ) ) {
F_68 ( & V_64 -> V_69 ) ;
F_69 ( V_66 ) ;
F_70 ( V_66 ) ;
F_71 ( V_64 , V_67 ) ;
} else {
T_4 V_70 ;
V_70 = F_72 ( V_66 , V_60 -> V_71 ) ;
V_70 = F_58 ( F_73 ( V_70 ) , V_60 ) ;
V_70 = F_74 ( V_70 ) ;
F_75 ( V_66 , V_60 , V_65 ) ;
F_76 ( V_64 , V_65 , V_58 , V_70 ) ;
F_77 ( V_64 , V_67 ) ;
F_78 ( V_64 , V_72 , V_46 ) ;
V_64 -> V_73 ++ ;
F_68 ( & V_64 -> V_69 ) ;
}
return 0 ;
}
static inline T_6 F_79 ( int V_74 , T_6 V_75 )
{
return ( V_76 & ~ ( V_74 ? 0 : V_77 ) ) | V_75 ;
}
static inline struct V_66 * F_80 ( int V_74 ,
struct V_59 * V_60 ,
unsigned long V_65 , int V_78 ,
T_6 V_75 )
{
return F_81 ( F_79 ( V_74 , V_75 ) ,
V_79 , V_60 , V_65 , V_78 ) ;
}
static inline struct V_66 * F_82 ( int V_74 )
{
return F_83 ( F_79 ( V_74 , 0 ) ,
V_79 ) ;
}
int F_84 ( struct V_63 * V_64 , struct V_59 * V_60 ,
unsigned long V_80 , T_4 * V_58 ,
unsigned int V_81 )
{
struct V_66 * V_66 ;
unsigned long V_65 = V_80 & V_82 ;
T_7 * V_83 ;
if ( V_65 >= V_60 -> V_84 && V_65 + V_85 <= V_60 -> V_86 ) {
if ( F_9 ( F_85 ( V_60 ) ) )
return V_68 ;
if ( F_9 ( F_86 ( V_60 ) ) )
return V_68 ;
V_66 = F_80 ( F_87 ( V_60 ) ,
V_60 , V_65 , F_88 () , 0 ) ;
if ( F_9 ( ! V_66 ) ) {
F_89 ( V_87 ) ;
goto V_54;
}
F_89 ( V_88 ) ;
if ( F_9 ( F_90 ( V_66 , V_64 , V_89 ) ) ) {
F_70 ( V_66 ) ;
goto V_54;
}
if ( F_9 ( F_61 ( V_64 , V_60 , V_65 , V_58 ,
V_66 ) ) ) {
F_69 ( V_66 ) ;
F_70 ( V_66 ) ;
goto V_54;
}
return 0 ;
}
V_54:
if ( F_9 ( F_91 ( V_64 , V_60 , V_58 , V_80 ) ) )
return V_68 ;
if ( F_9 ( F_92 ( * V_58 ) ) )
return 0 ;
V_83 = F_93 ( V_58 , V_80 ) ;
return F_94 ( V_64 , V_60 , V_80 , V_83 , V_58 , V_81 ) ;
}
int F_95 ( struct V_63 * V_90 , struct V_63 * V_91 ,
T_4 * V_92 , T_4 * V_93 , unsigned long V_94 ,
struct V_59 * V_60 )
{
struct V_66 * V_95 ;
T_4 V_58 ;
T_5 V_67 ;
int V_28 ;
V_28 = - V_49 ;
V_67 = F_63 ( V_90 , V_94 ) ;
if ( F_9 ( ! V_67 ) )
goto V_54;
F_66 ( & V_90 -> V_69 ) ;
F_96 ( & V_91 -> V_69 , V_96 ) ;
V_28 = - V_97 ;
V_58 = * V_93 ;
if ( F_9 ( ! F_92 ( V_58 ) ) ) {
F_71 ( V_90 , V_67 ) ;
goto V_98;
}
if ( F_9 ( F_97 ( V_58 ) ) ) {
F_68 ( & V_91 -> V_69 ) ;
F_68 ( & V_90 -> V_69 ) ;
F_71 ( V_90 , V_67 ) ;
F_98 ( V_60 -> V_99 , V_93 ) ;
goto V_54;
}
V_95 = F_99 ( V_58 ) ;
F_18 ( ! F_100 ( V_95 ) ) ;
F_101 ( V_95 ) ;
F_102 ( V_95 ) ;
F_78 ( V_90 , V_72 , V_46 ) ;
F_103 ( V_91 , V_94 , V_93 ) ;
V_58 = F_104 ( F_105 ( V_58 ) ) ;
F_76 ( V_90 , V_94 , V_92 , V_58 ) ;
F_77 ( V_90 , V_67 ) ;
V_90 -> V_73 ++ ;
V_28 = 0 ;
V_98:
F_68 ( & V_91 -> V_69 ) ;
F_68 ( & V_90 -> V_69 ) ;
V_54:
return V_28 ;
}
static int F_106 ( struct V_63 * V_64 ,
struct V_59 * V_60 ,
unsigned long V_80 ,
T_4 * V_58 , T_4 V_100 ,
struct V_66 * V_66 ,
unsigned long V_65 )
{
T_5 V_67 ;
T_4 V_101 ;
int V_28 = 0 , V_102 ;
struct V_66 * * V_40 ;
unsigned long V_103 ;
unsigned long V_104 ;
V_40 = F_107 ( sizeof( struct V_66 * ) * V_46 ,
V_89 ) ;
if ( F_9 ( ! V_40 ) ) {
V_28 |= V_68 ;
goto V_54;
}
for ( V_102 = 0 ; V_102 < V_46 ; V_102 ++ ) {
V_40 [ V_102 ] = F_108 ( V_105 |
V_106 ,
V_60 , V_80 , F_109 ( V_66 ) ) ;
if ( F_9 ( ! V_40 [ V_102 ] ||
F_90 ( V_40 [ V_102 ] , V_64 ,
V_89 ) ) ) {
if ( V_40 [ V_102 ] )
F_70 ( V_40 [ V_102 ] ) ;
F_110 () ;
while ( -- V_102 >= 0 ) {
F_69 ( V_40 [ V_102 ] ) ;
F_70 ( V_40 [ V_102 ] ) ;
}
F_111 () ;
F_112 ( V_40 ) ;
V_28 |= V_68 ;
goto V_54;
}
}
for ( V_102 = 0 ; V_102 < V_46 ; V_102 ++ ) {
F_113 ( V_40 [ V_102 ] , V_66 + V_102 ,
V_65 + V_107 * V_102 , V_60 ) ;
F_65 ( V_40 [ V_102 ] ) ;
F_114 () ;
}
V_103 = V_65 ;
V_104 = V_65 + V_85 ;
F_115 ( V_64 , V_103 , V_104 ) ;
F_66 ( & V_64 -> V_69 ) ;
if ( F_9 ( ! F_116 ( * V_58 , V_100 ) ) )
goto V_108;
F_18 ( ! F_100 ( V_66 ) ) ;
F_117 ( V_60 , V_65 , V_58 ) ;
V_67 = F_118 ( V_64 ) ;
F_119 ( V_64 , & V_101 , V_67 ) ;
for ( V_102 = 0 ; V_102 < V_46 ; V_102 ++ , V_65 += V_107 ) {
T_7 * V_83 , V_70 ;
V_70 = F_120 ( V_40 [ V_102 ] , V_60 -> V_71 ) ;
V_70 = F_121 ( F_122 ( V_70 ) , V_60 ) ;
F_75 ( V_40 [ V_102 ] , V_60 , V_65 ) ;
V_83 = F_93 ( & V_101 , V_65 ) ;
F_18 ( ! F_123 ( * V_83 ) ) ;
F_124 ( V_64 , V_65 , V_83 , V_70 ) ;
F_125 ( V_83 ) ;
}
F_112 ( V_40 ) ;
F_126 () ;
F_119 ( V_64 , V_58 , V_67 ) ;
F_127 ( V_66 ) ;
F_68 ( & V_64 -> V_69 ) ;
F_128 ( V_64 , V_103 , V_104 ) ;
V_28 |= V_109 ;
F_70 ( V_66 ) ;
V_54:
return V_28 ;
V_108:
F_68 ( & V_64 -> V_69 ) ;
F_128 ( V_64 , V_103 , V_104 ) ;
F_110 () ;
for ( V_102 = 0 ; V_102 < V_46 ; V_102 ++ ) {
F_69 ( V_40 [ V_102 ] ) ;
F_70 ( V_40 [ V_102 ] ) ;
}
F_111 () ;
F_112 ( V_40 ) ;
goto V_54;
}
int F_129 ( struct V_63 * V_64 , struct V_59 * V_60 ,
unsigned long V_80 , T_4 * V_58 , T_4 V_100 )
{
int V_28 = 0 ;
struct V_66 * V_66 , * V_110 ;
unsigned long V_65 ;
unsigned long V_103 ;
unsigned long V_104 ;
F_18 ( ! V_60 -> V_99 ) ;
F_66 ( & V_64 -> V_69 ) ;
if ( F_9 ( ! F_116 ( * V_58 , V_100 ) ) )
goto V_98;
V_66 = F_99 ( V_100 ) ;
F_18 ( ! F_62 ( V_66 ) || ! F_100 ( V_66 ) ) ;
V_65 = V_80 & V_82 ;
if ( F_130 ( V_66 ) == 1 ) {
T_4 V_70 ;
V_70 = F_131 ( V_100 ) ;
V_70 = F_58 ( F_73 ( V_70 ) , V_60 ) ;
if ( F_132 ( V_60 , V_65 , V_58 , V_70 , 1 ) )
F_133 ( V_60 , V_80 , V_58 ) ;
V_28 |= V_109 ;
goto V_98;
}
F_101 ( V_66 ) ;
F_68 ( & V_64 -> V_69 ) ;
if ( F_134 ( V_60 ) &&
! F_135 () )
V_110 = F_80 ( F_87 ( V_60 ) ,
V_60 , V_65 , F_88 () , 0 ) ;
else
V_110 = NULL ;
if ( F_9 ( ! V_110 ) ) {
F_89 ( V_87 ) ;
V_28 = F_106 ( V_64 , V_60 , V_80 ,
V_58 , V_100 , V_66 , V_65 ) ;
if ( V_28 & V_68 )
F_136 ( V_66 ) ;
F_70 ( V_66 ) ;
goto V_54;
}
F_89 ( V_88 ) ;
if ( F_9 ( F_90 ( V_110 , V_64 , V_89 ) ) ) {
F_70 ( V_110 ) ;
F_136 ( V_66 ) ;
F_70 ( V_66 ) ;
V_28 |= V_68 ;
goto V_54;
}
F_137 ( V_110 , V_66 , V_65 , V_60 , V_46 ) ;
F_65 ( V_110 ) ;
V_103 = V_65 ;
V_104 = V_65 + V_85 ;
F_115 ( V_64 , V_103 , V_104 ) ;
F_66 ( & V_64 -> V_69 ) ;
F_70 ( V_66 ) ;
if ( F_9 ( ! F_116 ( * V_58 , V_100 ) ) ) {
F_68 ( & V_64 -> V_69 ) ;
F_69 ( V_110 ) ;
F_70 ( V_110 ) ;
goto V_111;
} else {
T_4 V_70 ;
F_18 ( ! F_100 ( V_66 ) ) ;
V_70 = F_72 ( V_110 , V_60 -> V_71 ) ;
V_70 = F_58 ( F_73 ( V_70 ) , V_60 ) ;
V_70 = F_74 ( V_70 ) ;
F_117 ( V_60 , V_65 , V_58 ) ;
F_75 ( V_110 , V_60 , V_65 ) ;
F_76 ( V_64 , V_65 , V_58 , V_70 ) ;
F_133 ( V_60 , V_80 , V_58 ) ;
F_127 ( V_66 ) ;
F_70 ( V_66 ) ;
V_28 |= V_109 ;
}
F_68 ( & V_64 -> V_69 ) ;
V_111:
F_128 ( V_64 , V_103 , V_104 ) ;
V_54:
return V_28 ;
V_98:
F_68 ( & V_64 -> V_69 ) ;
return V_28 ;
}
struct V_66 * F_138 ( struct V_59 * V_60 ,
unsigned long V_94 ,
T_4 * V_58 ,
unsigned int V_81 )
{
struct V_63 * V_64 = V_60 -> V_112 ;
struct V_66 * V_66 = NULL ;
F_139 ( & V_64 -> V_69 ) ;
if ( V_81 & V_113 && ! F_140 ( * V_58 ) )
goto V_54;
V_66 = F_99 ( * V_58 ) ;
F_18 ( ! F_100 ( V_66 ) ) ;
if ( V_81 & V_114 ) {
T_4 V_101 ;
V_101 = F_131 ( F_73 ( * V_58 ) ) ;
F_76 ( V_64 , V_94 & V_82 , V_58 , V_101 ) ;
}
if ( ( V_81 & V_115 ) && ( V_60 -> V_61 & V_116 ) ) {
if ( V_66 -> V_117 && F_141 ( V_66 ) ) {
F_142 () ;
if ( V_66 -> V_117 )
F_143 ( V_66 ) ;
F_144 ( V_66 ) ;
}
}
V_66 += ( V_94 & ~ V_82 ) >> V_7 ;
F_18 ( ! F_62 ( V_66 ) ) ;
if ( V_81 & V_118 )
F_145 ( V_66 ) ;
V_54:
return V_66 ;
}
int F_146 ( struct V_119 * V_120 , struct V_59 * V_60 ,
T_4 * V_58 , unsigned long V_94 )
{
int V_28 = 0 ;
if ( F_147 ( V_58 , V_60 ) == 1 ) {
struct V_66 * V_66 ;
T_5 V_67 ;
T_4 V_100 ;
V_67 = F_118 ( V_120 -> V_64 ) ;
V_100 = F_148 ( V_120 -> V_64 , V_94 , V_58 ) ;
V_66 = F_99 ( V_100 ) ;
F_149 ( V_120 , V_58 , V_94 ) ;
F_127 ( V_66 ) ;
F_18 ( F_130 ( V_66 ) < 0 ) ;
F_78 ( V_120 -> V_64 , V_72 , - V_46 ) ;
F_18 ( ! F_100 ( V_66 ) ) ;
V_120 -> V_64 -> V_73 -- ;
F_68 ( & V_120 -> V_64 -> V_69 ) ;
F_150 ( V_120 , V_66 ) ;
F_71 ( V_120 -> V_64 , V_67 ) ;
V_28 = 1 ;
}
return V_28 ;
}
int F_151 ( struct V_59 * V_60 , T_4 * V_58 ,
unsigned long V_94 , unsigned long V_121 ,
unsigned char * V_122 )
{
int V_28 = 0 ;
if ( F_147 ( V_58 , V_60 ) == 1 ) {
F_68 ( & V_60 -> V_112 -> V_69 ) ;
memset ( V_122 , 1 , ( V_121 - V_94 ) >> V_7 ) ;
V_28 = 1 ;
}
return V_28 ;
}
int F_152 ( struct V_59 * V_60 , struct V_59 * V_123 ,
unsigned long V_124 ,
unsigned long V_125 , unsigned long V_126 ,
T_4 * V_127 , T_4 * V_128 )
{
int V_28 = 0 ;
T_4 V_58 ;
struct V_63 * V_64 = V_60 -> V_112 ;
if ( ( V_124 & ~ V_82 ) ||
( V_125 & ~ V_82 ) ||
V_126 - V_124 < V_85 ||
( V_123 -> V_61 & V_129 ) )
goto V_54;
if ( F_153 ( ! F_67 ( * V_128 ) ) ) {
F_18 ( F_92 ( * V_128 ) ) ;
goto V_54;
}
V_28 = F_147 ( V_127 , V_60 ) ;
if ( V_28 == 1 ) {
V_58 = F_148 ( V_64 , V_124 , V_127 ) ;
F_18 ( ! F_67 ( * V_128 ) ) ;
F_76 ( V_64 , V_125 , V_128 , V_58 ) ;
F_68 ( & V_64 -> V_69 ) ;
}
V_54:
return V_28 ;
}
int F_154 ( struct V_59 * V_60 , T_4 * V_58 ,
unsigned long V_94 , T_8 V_130 )
{
struct V_63 * V_64 = V_60 -> V_112 ;
int V_28 = 0 ;
if ( F_147 ( V_58 , V_60 ) == 1 ) {
T_4 V_70 ;
V_70 = F_148 ( V_64 , V_94 , V_58 ) ;
V_70 = F_155 ( V_70 , V_130 ) ;
F_76 ( V_64 , V_94 , V_58 , V_70 ) ;
F_68 ( & V_60 -> V_112 -> V_69 ) ;
V_28 = 1 ;
}
return V_28 ;
}
int F_147 ( T_4 * V_58 , struct V_59 * V_60 )
{
F_66 ( & V_60 -> V_112 -> V_69 ) ;
if ( F_59 ( F_92 ( * V_58 ) ) ) {
if ( F_9 ( F_97 ( * V_58 ) ) ) {
F_68 ( & V_60 -> V_112 -> V_69 ) ;
F_98 ( V_60 -> V_99 , V_58 ) ;
return - 1 ;
} else {
return 1 ;
}
}
F_68 ( & V_60 -> V_112 -> V_69 ) ;
return 0 ;
}
T_4 * F_156 ( struct V_66 * V_66 ,
struct V_63 * V_64 ,
unsigned long V_80 ,
enum V_131 V_30 )
{
T_9 * V_132 ;
T_10 * V_133 ;
T_4 * V_58 , * V_28 = NULL ;
if ( V_80 & ~ V_82 )
goto V_54;
V_132 = F_157 ( V_64 , V_80 ) ;
if ( ! F_158 ( * V_132 ) )
goto V_54;
V_133 = F_159 ( V_132 , V_80 ) ;
if ( ! F_160 ( * V_133 ) )
goto V_54;
V_58 = F_161 ( V_133 , V_80 ) ;
if ( F_67 ( * V_58 ) )
goto V_54;
if ( F_99 ( * V_58 ) != V_66 )
goto V_54;
if ( V_30 == V_134 &&
F_97 ( * V_58 ) )
goto V_54;
if ( F_92 ( * V_58 ) ) {
F_18 ( V_30 == V_135 &&
! F_97 ( * V_58 ) ) ;
V_28 = V_58 ;
}
V_54:
return V_28 ;
}
static int F_162 ( struct V_66 * V_66 ,
struct V_59 * V_60 ,
unsigned long V_80 )
{
struct V_63 * V_64 = V_60 -> V_112 ;
T_4 * V_58 ;
int V_28 = 0 ;
const unsigned long V_103 = V_80 ;
const unsigned long V_104 = V_80 + V_85 ;
F_115 ( V_64 , V_103 , V_104 ) ;
F_66 ( & V_64 -> V_69 ) ;
V_58 = F_156 ( V_66 , V_64 , V_80 ,
V_134 ) ;
if ( V_58 ) {
F_163 ( V_60 , V_80 , V_58 ) ;
V_28 = 1 ;
}
F_68 ( & V_64 -> V_69 ) ;
F_128 ( V_64 , V_103 , V_104 ) ;
return V_28 ;
}
static void F_164 ( struct V_66 * V_66 )
{
int V_102 ;
struct V_1 * V_1 = F_165 ( V_66 ) ;
struct V_136 * V_136 ;
int V_137 = 0 ;
F_166 ( & V_1 -> V_138 ) ;
V_136 = F_167 ( V_66 , V_1 ) ;
F_168 ( V_66 ) ;
F_169 ( V_66 ) ;
for ( V_102 = V_46 - 1 ; V_102 >= 1 ; V_102 -- ) {
struct V_66 * V_139 = V_66 + V_102 ;
F_170 ( F_130 ( V_139 ) < 0 ) ;
V_137 += F_130 ( V_139 ) ;
F_170 ( V_137 < 0 ) ;
F_170 ( F_171 ( & V_139 -> V_140 ) != 0 ) ;
F_172 ( F_130 ( V_66 ) + F_130 ( V_139 ) + 1 ,
& V_139 -> V_140 ) ;
F_173 () ;
V_139 -> V_81 &= ~ V_141 | V_142 ;
V_139 -> V_81 |= ( V_66 -> V_81 &
( ( 1L << V_143 ) |
( 1L << V_144 ) |
( 1L << V_145 ) |
( 1L << V_146 ) ) ) ;
V_139 -> V_81 |= ( 1L << V_147 ) ;
F_126 () ;
V_139 -> V_148 = V_66 -> V_148 ;
F_170 ( V_139 -> V_117 ) ;
V_139 -> V_117 = V_66 -> V_117 ;
V_139 -> V_149 = V_66 -> V_149 + V_102 ;
F_170 ( ! F_174 ( V_139 ) ) ;
F_170 ( ! F_175 ( V_139 ) ) ;
F_170 ( ! F_176 ( V_139 ) ) ;
F_170 ( ! F_177 ( V_139 ) ) ;
F_178 ( V_66 , V_139 , V_136 ) ;
}
F_179 ( V_137 , & V_66 -> V_140 ) ;
F_170 ( F_171 ( & V_66 -> V_140 ) <= 0 ) ;
F_180 ( V_1 , V_150 , - 1 ) ;
F_180 ( V_1 , V_151 , V_46 ) ;
F_181 ( V_66 ) ;
F_182 ( V_66 ) ;
F_183 ( & V_1 -> V_138 ) ;
for ( V_102 = 1 ; V_102 < V_46 ; V_102 ++ ) {
struct V_66 * V_139 = V_66 + V_102 ;
F_170 ( F_184 ( V_139 ) <= 0 ) ;
F_70 ( V_139 ) ;
}
F_170 ( F_184 ( V_66 ) <= 0 ) ;
}
static int F_185 ( struct V_66 * V_66 ,
struct V_59 * V_60 ,
unsigned long V_80 )
{
struct V_63 * V_64 = V_60 -> V_112 ;
T_4 * V_58 , V_101 ;
int V_28 = 0 , V_102 ;
T_5 V_67 ;
unsigned long V_65 ;
F_66 ( & V_64 -> V_69 ) ;
V_58 = F_156 ( V_66 , V_64 , V_80 ,
V_135 ) ;
if ( V_58 ) {
V_67 = F_118 ( V_64 ) ;
F_119 ( V_64 , & V_101 , V_67 ) ;
V_65 = V_80 ;
for ( V_102 = 0 ; V_102 < V_46 ; V_102 ++ , V_65 += V_107 ) {
T_7 * V_83 , V_70 ;
F_170 ( F_62 ( V_66 + V_102 ) ) ;
V_70 = F_120 ( V_66 + V_102 , V_60 -> V_71 ) ;
V_70 = F_121 ( F_122 ( V_70 ) , V_60 ) ;
if ( ! F_140 ( * V_58 ) )
V_70 = F_186 ( V_70 ) ;
else
F_170 ( F_130 ( V_66 ) != 1 ) ;
if ( ! F_187 ( * V_58 ) )
V_70 = F_188 ( V_70 ) ;
V_83 = F_93 ( & V_101 , V_65 ) ;
F_170 ( ! F_123 ( * V_83 ) ) ;
F_124 ( V_64 , V_65 , V_83 , V_70 ) ;
F_125 ( V_83 ) ;
}
F_126 () ;
F_189 ( V_60 , V_80 , V_58 ) ;
F_119 ( V_64 , V_58 , V_67 ) ;
V_28 = 1 ;
}
F_68 ( & V_64 -> V_69 ) ;
return V_28 ;
}
static void F_190 ( struct V_66 * V_66 ,
struct V_99 * V_99 )
{
int V_152 , V_153 ;
T_11 V_154 = V_66 -> V_149 << ( V_155 - V_7 ) ;
struct V_156 * V_157 ;
F_170 ( ! F_100 ( V_66 ) ) ;
F_170 ( F_191 ( V_66 ) ) ;
V_152 = 0 ;
F_192 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_59 * V_60 = V_157 -> V_60 ;
unsigned long V_94 = F_193 ( V_66 , V_60 ) ;
F_170 ( F_194 ( V_60 ) ) ;
V_152 += F_162 ( V_66 , V_60 , V_94 ) ;
}
if ( V_152 != F_130 ( V_66 ) )
F_11 ( V_11 L_15 ,
V_152 , F_130 ( V_66 ) ) ;
F_170 ( V_152 != F_130 ( V_66 ) ) ;
F_164 ( V_66 ) ;
V_153 = 0 ;
F_192 (avc, &anon_vma->rb_root, pgoff, pgoff) {
struct V_59 * V_60 = V_157 -> V_60 ;
unsigned long V_94 = F_193 ( V_66 , V_60 ) ;
F_170 ( F_194 ( V_60 ) ) ;
V_153 += F_185 ( V_66 , V_60 , V_94 ) ;
}
if ( V_152 != V_153 )
F_11 ( V_11 L_16 ,
V_152 , V_153 , F_130 ( V_66 ) ) ;
F_170 ( V_152 != V_153 ) ;
}
int F_136 ( struct V_66 * V_66 )
{
struct V_99 * V_99 ;
int V_28 = 1 ;
F_170 ( ! F_174 ( V_66 ) ) ;
V_99 = F_195 ( V_66 ) ;
if ( ! V_99 )
goto V_54;
V_28 = 0 ;
if ( ! F_62 ( V_66 ) )
goto V_98;
F_170 ( ! F_177 ( V_66 ) ) ;
F_190 ( V_66 , V_99 ) ;
F_89 ( V_158 ) ;
F_170 ( F_62 ( V_66 ) ) ;
V_98:
F_196 ( V_99 ) ;
V_54:
return V_28 ;
}
int F_197 ( struct V_59 * V_60 ,
unsigned long * V_61 , int V_159 )
{
struct V_63 * V_64 = V_60 -> V_112 ;
switch ( V_159 ) {
case V_160 :
if ( * V_61 & ( V_161 | V_162 ) )
return - V_25 ;
if ( V_64 -> V_163 & V_129 )
return - V_25 ;
* V_61 &= ~ V_129 ;
* V_61 |= V_161 ;
if ( F_9 ( F_198 ( V_60 ) ) )
return - V_49 ;
break;
case V_164 :
if ( * V_61 & ( V_129 | V_162 ) )
return - V_25 ;
* V_61 &= ~ V_161 ;
* V_61 |= V_129 ;
break;
}
return 0 ;
}
static int T_3 F_54 ( void )
{
V_165 = F_199 ( L_17 ,
sizeof( struct V_166 ) ,
F_200 ( struct V_166 ) , 0 , NULL ) ;
if ( ! V_165 )
return - V_49 ;
return 0 ;
}
static void T_3 F_56 ( void )
{
F_201 ( V_165 ) ;
V_165 = NULL ;
}
static inline struct V_166 * F_202 ( void )
{
if ( ! V_165 )
return NULL ;
return F_203 ( V_165 , V_89 ) ;
}
static inline void F_204 ( struct V_166 * V_166 )
{
F_205 ( V_165 , V_166 ) ;
}
static int T_3 F_55 ( void )
{
V_167 = F_206 ( V_168 * sizeof( struct V_169 ) ,
V_89 ) ;
if ( ! V_167 )
return - V_49 ;
return 0 ;
}
static struct V_166 * F_207 ( struct V_63 * V_64 )
{
struct V_166 * V_166 ;
struct V_169 * V_170 ;
struct V_171 * V_172 ;
V_170 = & V_167 [ ( ( unsigned long ) V_64 / sizeof( struct V_63 ) )
% V_168 ] ;
F_208 (mm_slot, node, bucket, hash) {
if ( V_64 == V_166 -> V_64 )
return V_166 ;
}
return NULL ;
}
static void F_209 ( struct V_63 * V_64 ,
struct V_166 * V_166 )
{
struct V_169 * V_170 ;
V_170 = & V_167 [ ( ( unsigned long ) V_64 / sizeof( struct V_63 ) )
% V_168 ] ;
V_166 -> V_64 = V_64 ;
F_210 ( & V_166 -> V_173 , V_170 ) ;
}
static inline int F_211 ( struct V_63 * V_64 )
{
return F_171 ( & V_64 -> V_174 ) == 0 ;
}
int F_212 ( struct V_63 * V_64 )
{
struct V_166 * V_166 ;
int V_175 ;
V_166 = F_202 () ;
if ( ! V_166 )
return - V_49 ;
F_18 ( F_211 ( V_64 ) ) ;
if ( F_9 ( F_213 ( V_176 , & V_64 -> V_81 ) ) ) {
F_204 ( V_166 ) ;
return 0 ;
}
F_66 ( & V_177 ) ;
F_209 ( V_64 , V_166 ) ;
V_175 = F_13 ( & V_12 . V_13 ) ;
F_214 ( & V_166 -> V_178 , & V_12 . V_13 ) ;
F_68 ( & V_177 ) ;
F_215 ( & V_64 -> V_179 ) ;
if ( V_175 )
F_14 ( & V_14 ) ;
return 0 ;
}
int F_198 ( struct V_59 * V_60 )
{
unsigned long V_180 , V_181 ;
if ( ! V_60 -> V_99 )
return 0 ;
if ( V_60 -> V_182 )
return 0 ;
F_18 ( V_60 -> V_61 & V_162 ) ;
V_180 = ( V_60 -> V_84 + ~ V_82 ) & V_82 ;
V_181 = V_60 -> V_86 & V_82 ;
if ( V_180 < V_181 )
return F_86 ( V_60 ) ;
return 0 ;
}
void F_216 ( struct V_63 * V_64 )
{
struct V_166 * V_166 ;
int free = 0 ;
F_66 ( & V_177 ) ;
V_166 = F_207 ( V_64 ) ;
if ( V_166 && V_12 . V_166 != V_166 ) {
F_217 ( & V_166 -> V_173 ) ;
F_218 ( & V_166 -> V_178 ) ;
free = 1 ;
}
F_68 ( & V_177 ) ;
if ( free ) {
F_21 ( V_176 , & V_64 -> V_81 ) ;
F_204 ( V_166 ) ;
F_219 ( V_64 ) ;
} else if ( V_166 ) {
F_220 ( & V_64 -> V_183 ) ;
F_221 ( & V_64 -> V_183 ) ;
}
}
static void F_222 ( struct V_66 * V_66 )
{
F_223 ( V_66 , V_184 + 0 ) ;
F_144 ( V_66 ) ;
F_224 ( V_66 ) ;
}
static void F_225 ( T_7 * V_83 , T_7 * V_185 )
{
while ( -- V_185 >= V_83 ) {
T_7 V_186 = * V_185 ;
if ( ! F_123 ( V_186 ) )
F_222 ( F_226 ( V_186 ) ) ;
}
}
static void F_227 ( T_7 * V_83 )
{
F_225 ( V_83 , V_83 + V_46 ) ;
}
static int F_228 ( struct V_59 * V_60 ,
unsigned long V_80 ,
T_7 * V_83 )
{
struct V_66 * V_66 ;
T_7 * V_185 ;
int V_187 = 0 , V_188 = 0 , V_189 = 0 ;
for ( V_185 = V_83 ; V_185 < V_83 + V_46 ;
V_185 ++ , V_80 += V_107 ) {
T_7 V_186 = * V_185 ;
if ( F_123 ( V_186 ) ) {
if ( ++ V_189 <= V_44 )
continue;
else {
F_225 ( V_83 , V_185 ) ;
goto V_54;
}
}
if ( ! F_229 ( V_186 ) || ! F_230 ( V_186 ) ) {
F_225 ( V_83 , V_185 ) ;
goto V_54;
}
V_66 = F_231 ( V_60 , V_80 , V_186 ) ;
if ( F_9 ( ! V_66 ) ) {
F_225 ( V_83 , V_185 ) ;
goto V_54;
}
F_18 ( F_62 ( V_66 ) ) ;
F_170 ( ! F_174 ( V_66 ) ) ;
F_18 ( ! F_177 ( V_66 ) ) ;
if ( F_184 ( V_66 ) != 1 ) {
F_225 ( V_83 , V_185 ) ;
goto V_54;
}
if ( ! F_141 ( V_66 ) ) {
F_225 ( V_83 , V_185 ) ;
goto V_54;
}
if ( F_232 ( V_66 ) ) {
F_144 ( V_66 ) ;
F_225 ( V_83 , V_185 ) ;
goto V_54;
}
F_233 ( V_66 , V_184 + 0 ) ;
F_18 ( ! F_234 ( V_66 ) ) ;
F_18 ( F_235 ( V_66 ) ) ;
if ( F_236 ( V_186 ) || F_237 ( V_66 ) ||
F_238 ( V_60 -> V_112 , V_80 ) )
V_187 = 1 ;
}
if ( F_9 ( ! V_187 ) )
F_227 ( V_83 ) ;
else
V_188 = 1 ;
V_54:
return V_188 ;
}
static void F_239 ( T_7 * V_83 , struct V_66 * V_66 ,
struct V_59 * V_60 ,
unsigned long V_80 ,
T_12 * V_190 )
{
T_7 * V_185 ;
for ( V_185 = V_83 ; V_185 < V_83 + V_46 ; V_185 ++ ) {
T_7 V_186 = * V_185 ;
struct V_66 * V_95 ;
if ( F_123 ( V_186 ) ) {
F_240 ( V_66 , V_80 ) ;
F_78 ( V_60 -> V_112 , V_72 , 1 ) ;
} else {
V_95 = F_226 ( V_186 ) ;
F_113 ( V_66 , V_95 , V_80 , V_60 ) ;
F_18 ( F_130 ( V_95 ) != 1 ) ;
F_222 ( V_95 ) ;
F_66 ( V_190 ) ;
F_241 ( V_60 -> V_112 , V_80 , V_185 ) ;
F_127 ( V_95 ) ;
F_68 ( V_190 ) ;
F_242 ( V_95 ) ;
}
V_80 += V_107 ;
V_66 ++ ;
}
}
static void F_243 ( void )
{
F_244 ( V_14 , false ,
F_245 ( V_38 ) ) ;
}
static bool F_246 ( struct V_66 * * V_191 , bool * V_192 )
{
if ( F_10 ( * V_191 ) ) {
if ( ! * V_192 )
return false ;
* V_192 = false ;
* V_191 = NULL ;
F_243 () ;
} else if ( * V_191 ) {
F_70 ( * V_191 ) ;
* V_191 = NULL ;
}
return true ;
}
static struct V_66
* F_247 ( struct V_66 * * V_191 , struct V_63 * V_64 ,
struct V_59 * V_60 , unsigned long V_80 ,
int V_172 )
{
F_18 ( * V_191 ) ;
* V_191 = F_80 ( F_248 () , V_60 , V_80 ,
V_172 , V_106 ) ;
F_249 ( & V_64 -> V_183 ) ;
if ( F_9 ( ! * V_191 ) ) {
F_89 ( V_193 ) ;
* V_191 = F_250 ( - V_49 ) ;
return NULL ;
}
F_89 ( V_194 ) ;
return * V_191 ;
}
static struct V_66 * F_251 ( bool * V_192 )
{
struct V_66 * V_191 ;
do {
V_191 = F_82 ( F_248 () ) ;
if ( ! V_191 ) {
F_89 ( V_193 ) ;
if ( ! * V_192 )
return NULL ;
* V_192 = false ;
F_243 () ;
} else
F_89 ( V_194 ) ;
} while ( F_9 ( ! V_191 ) && F_59 ( F_2 () ) );
return V_191 ;
}
static bool F_246 ( struct V_66 * * V_191 , bool * V_192 )
{
if ( ! * V_191 )
* V_191 = F_251 ( V_192 ) ;
if ( F_9 ( ! * V_191 ) )
return false ;
return true ;
}
static struct V_66
* F_247 ( struct V_66 * * V_191 , struct V_63 * V_64 ,
struct V_59 * V_60 , unsigned long V_80 ,
int V_172 )
{
F_249 ( & V_64 -> V_183 ) ;
F_18 ( ! * V_191 ) ;
return * V_191 ;
}
static void F_252 ( struct V_63 * V_64 ,
unsigned long V_80 ,
struct V_66 * * V_191 ,
struct V_59 * V_60 ,
int V_172 )
{
T_9 * V_132 ;
T_10 * V_133 ;
T_4 * V_58 , V_101 ;
T_7 * V_83 ;
T_5 V_67 ;
struct V_66 * V_110 ;
T_12 * V_190 ;
int V_188 ;
unsigned long V_180 , V_181 ;
unsigned long V_103 ;
unsigned long V_104 ;
F_18 ( V_80 & ~ V_82 ) ;
V_110 = F_247 ( V_191 , V_64 , V_60 , V_80 , V_172 ) ;
if ( ! V_110 )
return;
if ( F_9 ( F_90 ( V_110 , V_64 , V_89 ) ) )
return;
F_220 ( & V_64 -> V_183 ) ;
if ( F_9 ( F_211 ( V_64 ) ) )
goto V_54;
V_60 = F_253 ( V_64 , V_80 ) ;
V_180 = ( V_60 -> V_84 + ~ V_82 ) & V_82 ;
V_181 = V_60 -> V_86 & V_82 ;
if ( V_80 < V_180 || V_80 + V_85 > V_181 )
goto V_54;
if ( ( ! ( V_60 -> V_61 & V_161 ) && ! F_254 () ) ||
( V_60 -> V_61 & V_129 ) )
goto V_54;
if ( ! V_60 -> V_99 || V_60 -> V_182 )
goto V_54;
if ( F_194 ( V_60 ) )
goto V_54;
F_18 ( V_60 -> V_61 & V_162 ) ;
V_132 = F_157 ( V_64 , V_80 ) ;
if ( ! F_158 ( * V_132 ) )
goto V_54;
V_133 = F_159 ( V_132 , V_80 ) ;
if ( ! F_160 ( * V_133 ) )
goto V_54;
V_58 = F_161 ( V_133 , V_80 ) ;
if ( ! F_255 ( * V_58 ) || F_92 ( * V_58 ) )
goto V_54;
F_256 ( V_60 -> V_99 ) ;
V_83 = F_93 ( V_58 , V_80 ) ;
V_190 = F_257 ( V_64 , V_58 ) ;
V_103 = V_80 ;
V_104 = V_80 + V_85 ;
F_115 ( V_64 , V_103 , V_104 ) ;
F_66 ( & V_64 -> V_69 ) ;
V_101 = F_117 ( V_60 , V_80 , V_58 ) ;
F_68 ( & V_64 -> V_69 ) ;
F_128 ( V_64 , V_103 , V_104 ) ;
F_66 ( V_190 ) ;
V_188 = F_228 ( V_60 , V_80 , V_83 ) ;
F_68 ( V_190 ) ;
if ( F_9 ( ! V_188 ) ) {
F_125 ( V_83 ) ;
F_66 ( & V_64 -> V_69 ) ;
F_170 ( ! F_67 ( * V_58 ) ) ;
F_76 ( V_64 , V_80 , V_58 , V_101 ) ;
F_68 ( & V_64 -> V_69 ) ;
F_258 ( V_60 -> V_99 ) ;
goto V_54;
}
F_258 ( V_60 -> V_99 ) ;
F_239 ( V_83 , V_110 , V_60 , V_80 , V_190 ) ;
F_125 ( V_83 ) ;
F_65 ( V_110 ) ;
V_67 = F_259 ( V_101 ) ;
V_101 = F_72 ( V_110 , V_60 -> V_71 ) ;
V_101 = F_58 ( F_73 ( V_101 ) , V_60 ) ;
V_101 = F_74 ( V_101 ) ;
F_126 () ;
F_66 ( & V_64 -> V_69 ) ;
F_170 ( ! F_67 ( * V_58 ) ) ;
F_75 ( V_110 , V_60 , V_80 ) ;
F_76 ( V_64 , V_80 , V_58 , V_101 ) ;
F_133 ( V_60 , V_80 , V_58 ) ;
F_77 ( V_64 , V_67 ) ;
F_68 ( & V_64 -> V_69 ) ;
* V_191 = NULL ;
V_41 ++ ;
V_195:
F_221 ( & V_64 -> V_183 ) ;
return;
V_54:
F_69 ( V_110 ) ;
goto V_195;
}
static int F_260 ( struct V_63 * V_64 ,
struct V_59 * V_60 ,
unsigned long V_80 ,
struct V_66 * * V_191 )
{
T_9 * V_132 ;
T_10 * V_133 ;
T_4 * V_58 ;
T_7 * V_83 , * V_185 ;
int V_28 = 0 , V_187 = 0 , V_189 = 0 ;
struct V_66 * V_66 ;
unsigned long V_196 ;
T_12 * V_190 ;
int V_172 = - 1 ;
F_18 ( V_80 & ~ V_82 ) ;
V_132 = F_157 ( V_64 , V_80 ) ;
if ( ! F_158 ( * V_132 ) )
goto V_54;
V_133 = F_159 ( V_132 , V_80 ) ;
if ( ! F_160 ( * V_133 ) )
goto V_54;
V_58 = F_161 ( V_133 , V_80 ) ;
if ( ! F_255 ( * V_58 ) || F_92 ( * V_58 ) )
goto V_54;
V_83 = F_261 ( V_64 , V_58 , V_80 , & V_190 ) ;
for ( V_196 = V_80 , V_185 = V_83 ; V_185 < V_83 + V_46 ;
V_185 ++ , V_196 += V_107 ) {
T_7 V_186 = * V_185 ;
if ( F_123 ( V_186 ) ) {
if ( ++ V_189 <= V_44 )
continue;
else
goto V_197;
}
if ( ! F_229 ( V_186 ) || ! F_230 ( V_186 ) )
goto V_197;
V_66 = F_231 ( V_60 , V_196 , V_186 ) ;
if ( F_9 ( ! V_66 ) )
goto V_197;
if ( V_172 == - 1 )
V_172 = F_109 ( V_66 ) ;
F_18 ( F_62 ( V_66 ) ) ;
if ( ! F_235 ( V_66 ) || F_234 ( V_66 ) || ! F_174 ( V_66 ) )
goto V_197;
if ( F_184 ( V_66 ) != 1 )
goto V_197;
if ( F_236 ( V_186 ) || F_237 ( V_66 ) ||
F_238 ( V_60 -> V_112 , V_80 ) )
V_187 = 1 ;
}
if ( V_187 )
V_28 = 1 ;
V_197:
F_262 ( V_83 , V_190 ) ;
if ( V_28 )
F_252 ( V_64 , V_80 , V_191 , V_60 , V_172 ) ;
V_54:
return V_28 ;
}
static void F_263 ( struct V_166 * V_166 )
{
struct V_63 * V_64 = V_166 -> V_64 ;
F_18 ( V_198 != 1 && ! F_264 ( & V_177 ) ) ;
if ( F_211 ( V_64 ) ) {
F_217 ( & V_166 -> V_173 ) ;
F_218 ( & V_166 -> V_178 ) ;
F_204 ( V_166 ) ;
F_219 ( V_64 ) ;
}
}
static unsigned int F_265 ( unsigned int V_40 ,
struct V_66 * * V_191 )
__releases( &khugepaged_mm_lock
static int F_266 ( void )
{
return ! F_13 ( & V_12 . V_13 ) &&
F_2 () ;
}
static int F_267 ( void )
{
return ! F_13 ( & V_12 . V_13 ) ||
F_268 () ;
}
static void F_269 ( void )
{
struct V_66 * V_191 = NULL ;
unsigned int V_199 = 0 , V_200 = 0 ;
unsigned int V_40 = V_39 ;
bool V_192 = true ;
F_270 () ;
while ( V_199 < V_40 ) {
if ( ! F_246 ( & V_191 , & V_192 ) )
break;
F_114 () ;
if ( F_9 ( F_268 () || F_271 ( V_201 ) ) )
break;
F_66 ( & V_177 ) ;
if ( ! V_12 . V_166 )
V_200 ++ ;
if ( F_266 () &&
V_200 < 2 )
V_199 += F_265 ( V_40 - V_199 ,
& V_191 ) ;
else
V_199 = V_40 ;
F_68 ( & V_177 ) ;
}
if ( ! F_272 ( V_191 ) )
F_70 ( V_191 ) ;
}
static void F_273 ( void )
{
F_274 () ;
if ( F_266 () ) {
if ( ! V_35 )
return;
F_244 ( V_14 ,
F_268 () ,
F_245 ( V_35 ) ) ;
return;
}
if ( F_2 () )
F_275 ( V_14 , F_267 () ) ;
}
static int V_10 ( void * V_189 )
{
struct V_166 * V_166 ;
F_276 () ;
F_277 ( V_201 , 19 ) ;
while ( ! F_268 () ) {
F_269 () ;
F_273 () ;
}
F_66 ( & V_177 ) ;
V_166 = V_12 . V_166 ;
V_12 . V_166 = NULL ;
if ( V_166 )
F_263 ( V_166 ) ;
F_68 ( & V_177 ) ;
return 0 ;
}
void F_278 ( struct V_63 * V_64 , T_4 * V_58 )
{
struct V_66 * V_66 ;
F_66 ( & V_64 -> V_69 ) ;
if ( F_9 ( ! F_92 ( * V_58 ) ) ) {
F_68 ( & V_64 -> V_69 ) ;
return;
}
V_66 = F_99 ( * V_58 ) ;
F_18 ( ! F_184 ( V_66 ) ) ;
F_101 ( V_66 ) ;
F_68 ( & V_64 -> V_69 ) ;
F_136 ( V_66 ) ;
F_70 ( V_66 ) ;
F_170 ( F_92 ( * V_58 ) ) ;
}
static void F_279 ( struct V_63 * V_64 ,
unsigned long V_80 )
{
T_9 * V_132 ;
T_10 * V_133 ;
T_4 * V_58 ;
F_18 ( ! ( V_80 & ~ V_82 ) ) ;
V_132 = F_157 ( V_64 , V_80 ) ;
if ( ! F_158 ( * V_132 ) )
return;
V_133 = F_159 ( V_132 , V_80 ) ;
if ( ! F_160 ( * V_133 ) )
return;
V_58 = F_161 ( V_133 , V_80 ) ;
if ( ! F_255 ( * V_58 ) )
return;
F_280 ( V_64 , V_58 ) ;
}
void F_281 ( struct V_59 * V_60 ,
unsigned long V_202 ,
unsigned long V_121 ,
long V_203 )
{
if ( V_202 & ~ V_82 &&
( V_202 & V_82 ) >= V_60 -> V_84 &&
( V_202 & V_82 ) + V_85 <= V_60 -> V_86 )
F_279 ( V_60 -> V_112 , V_202 ) ;
if ( V_121 & ~ V_82 &&
( V_121 & V_82 ) >= V_60 -> V_84 &&
( V_121 & V_82 ) + V_85 <= V_60 -> V_86 )
F_279 ( V_60 -> V_112 , V_121 ) ;
if ( V_203 > 0 ) {
struct V_59 * V_204 = V_60 -> V_205 ;
unsigned long V_206 = V_204 -> V_84 ;
V_206 += V_203 << V_7 ;
if ( V_206 & ~ V_82 &&
( V_206 & V_82 ) >= V_204 -> V_84 &&
( V_206 & V_82 ) + V_85 <= V_204 -> V_86 )
F_279 ( V_204 -> V_112 , V_206 ) ;
}
}
