static int F_1 ( void )
{
struct V_1 * V_1 ;
int V_2 = 0 ;
unsigned long V_3 ;
extern int V_4 ;
if ( ! F_2 ( V_5 ,
& V_6 ) &&
! F_2 ( V_7 ,
& V_6 ) )
return 0 ;
F_3 (zone)
V_2 ++ ;
V_3 = V_8 * V_2 * 2 ;
V_3 += V_8 * V_2 *
V_9 * V_9 ;
V_3 = F_4 ( V_3 ,
( unsigned long ) F_5 () / 20 ) ;
V_3 <<= ( V_10 - 10 ) ;
if ( V_3 > V_4 )
V_4 = V_3 ;
F_6 () ;
return 0 ;
}
static int F_7 ( void )
{
int V_11 = 0 ;
if ( F_8 () ) {
int V_12 ;
if ( F_9 ( ! V_13 || ! V_14 ) ) {
V_11 = - V_15 ;
goto V_16;
}
F_10 ( & V_17 ) ;
if ( ! V_18 )
V_18 = F_11 ( V_19 , NULL ,
L_1 ) ;
if ( F_9 ( F_12 ( V_18 ) ) ) {
F_13 ( V_20
L_2 ) ;
V_11 = F_14 ( V_18 ) ;
V_18 = NULL ;
}
V_12 = ! F_15 ( & V_21 . V_22 ) ;
F_16 ( & V_17 ) ;
if ( V_12 )
F_17 ( & V_23 ) ;
F_1 () ;
} else
F_17 ( & V_23 ) ;
V_16:
return V_11 ;
}
static T_1 F_18 ( struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_28 ,
enum V_29 V_30 ,
enum V_29 V_31 )
{
if ( F_2 ( V_30 , & V_6 ) ) {
F_19 ( F_2 ( V_31 , & V_6 ) ) ;
return sprintf ( V_28 , L_3 ) ;
} else if ( F_2 ( V_31 , & V_6 ) )
return sprintf ( V_28 , L_4 ) ;
else
return sprintf ( V_28 , L_5 ) ;
}
static T_1 F_20 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
const char * V_28 , T_2 V_32 ,
enum V_29 V_30 ,
enum V_29 V_31 )
{
if ( ! memcmp ( L_6 , V_28 ,
F_4 ( sizeof( L_6 ) - 1 , V_32 ) ) ) {
F_21 ( V_30 , & V_6 ) ;
F_22 ( V_31 , & V_6 ) ;
} else if ( ! memcmp ( L_7 , V_28 ,
F_4 ( sizeof( L_7 ) - 1 , V_32 ) ) ) {
F_22 ( V_30 , & V_6 ) ;
F_21 ( V_31 , & V_6 ) ;
} else if ( ! memcmp ( L_8 , V_28 ,
F_4 ( sizeof( L_8 ) - 1 , V_32 ) ) ) {
F_22 ( V_30 , & V_6 ) ;
F_22 ( V_31 , & V_6 ) ;
} else
return - V_33 ;
return V_32 ;
}
static T_1 F_23 ( struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_28 )
{
return F_18 ( V_25 , V_27 , V_28 ,
V_5 ,
V_7 ) ;
}
static T_1 F_24 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
const char * V_28 , T_2 V_32 )
{
T_1 V_34 ;
V_34 = F_20 ( V_25 , V_27 , V_28 , V_32 ,
V_5 ,
V_7 ) ;
if ( V_34 > 0 ) {
int V_11 = F_7 () ;
if ( V_11 )
V_34 = V_11 ;
}
if ( V_34 > 0 &&
( F_2 ( V_5 ,
& V_6 ) ||
F_2 ( V_7 ,
& V_6 ) ) )
F_1 () ;
return V_34 ;
}
static T_1 F_25 ( struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_28 ,
enum V_29 V_35 )
{
return sprintf ( V_28 , L_9 ,
! ! F_2 ( V_35 , & V_6 ) ) ;
}
static T_1 F_26 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
const char * V_28 , T_2 V_32 ,
enum V_29 V_35 )
{
unsigned long V_36 ;
int V_34 ;
V_34 = F_27 ( V_28 , 10 , & V_36 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_36 > 1 )
return - V_33 ;
if ( V_36 )
F_21 ( V_35 , & V_6 ) ;
else
F_22 ( V_35 , & V_6 ) ;
return V_32 ;
}
static T_1 F_28 ( struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_28 )
{
return F_18 ( V_25 , V_27 , V_28 ,
V_37 ,
V_38 ) ;
}
static T_1 F_29 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
const char * V_28 , T_2 V_32 )
{
return F_20 ( V_25 , V_27 , V_28 , V_32 ,
V_37 ,
V_38 ) ;
}
static T_1 F_30 ( struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_28 )
{
return F_25 ( V_25 , V_27 , V_28 ,
V_39 ) ;
}
static T_1 F_31 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
const char * V_28 , T_2 V_32 )
{
return F_26 ( V_25 , V_27 , V_28 , V_32 ,
V_39 ) ;
}
static T_1 F_32 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
char * V_28 )
{
return sprintf ( V_28 , L_10 , V_40 ) ;
}
static T_1 F_33 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
const char * V_28 , T_2 V_32 )
{
unsigned long V_41 ;
int V_11 ;
V_11 = F_34 ( V_28 , 10 , & V_41 ) ;
if ( V_11 || V_41 > V_42 )
return - V_33 ;
V_40 = V_41 ;
F_17 ( & V_23 ) ;
return V_32 ;
}
static T_1 F_35 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
char * V_28 )
{
return sprintf ( V_28 , L_10 , V_43 ) ;
}
static T_1 F_36 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
const char * V_28 , T_2 V_32 )
{
unsigned long V_41 ;
int V_11 ;
V_11 = F_34 ( V_28 , 10 , & V_41 ) ;
if ( V_11 || V_41 > V_42 )
return - V_33 ;
V_43 = V_41 ;
F_17 ( & V_23 ) ;
return V_32 ;
}
static T_1 F_37 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
char * V_28 )
{
return sprintf ( V_28 , L_10 , V_44 ) ;
}
static T_1 F_38 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
const char * V_28 , T_2 V_32 )
{
int V_11 ;
unsigned long V_45 ;
V_11 = F_34 ( V_28 , 10 , & V_45 ) ;
if ( V_11 || ! V_45 || V_45 > V_42 )
return - V_33 ;
V_44 = V_45 ;
return V_32 ;
}
static T_1 F_39 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
char * V_28 )
{
return sprintf ( V_28 , L_10 , V_46 ) ;
}
static T_1 F_40 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
char * V_28 )
{
return sprintf ( V_28 , L_10 , V_47 ) ;
}
static T_1 F_41 ( struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_28 )
{
return F_25 ( V_25 , V_27 , V_28 ,
V_48 ) ;
}
static T_1 F_42 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
const char * V_28 , T_2 V_32 )
{
return F_26 ( V_25 , V_27 , V_28 , V_32 ,
V_48 ) ;
}
static T_1 F_43 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
char * V_28 )
{
return sprintf ( V_28 , L_10 , V_49 ) ;
}
static T_1 F_44 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
const char * V_28 , T_2 V_32 )
{
int V_11 ;
unsigned long V_50 ;
V_11 = F_34 ( V_28 , 10 , & V_50 ) ;
if ( V_11 || V_50 > V_51 - 1 )
return - V_33 ;
V_49 = V_50 ;
return V_32 ;
}
static int T_3 F_45 ( struct V_24 * * V_52 )
{
int V_11 ;
* V_52 = F_46 ( L_11 , V_53 ) ;
if ( F_9 ( ! * V_52 ) ) {
F_13 ( V_20 L_12 ) ;
return - V_15 ;
}
V_11 = F_47 ( * V_52 , & V_54 ) ;
if ( V_11 ) {
F_13 ( V_20 L_13 ) ;
goto V_55;
}
V_11 = F_47 ( * V_52 , & V_56 ) ;
if ( V_11 ) {
F_13 ( V_20 L_13 ) ;
goto V_57;
}
return 0 ;
V_57:
F_48 ( * V_52 , & V_54 ) ;
V_55:
F_49 ( * V_52 ) ;
return V_11 ;
}
static void T_3 F_50 ( struct V_24 * V_52 )
{
F_48 ( V_52 , & V_56 ) ;
F_48 ( V_52 , & V_54 ) ;
F_49 ( V_52 ) ;
}
static inline int F_45 ( struct V_24 * * V_52 )
{
return 0 ;
}
static inline void F_50 ( struct V_24 * V_52 )
{
}
static int T_3 F_51 ( void )
{
int V_11 ;
struct V_24 * V_52 ;
if ( ! F_52 () ) {
V_6 = 0 ;
return - V_33 ;
}
V_11 = F_45 ( & V_52 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_53 () ;
if ( V_11 )
goto V_16;
V_11 = F_54 () ;
if ( V_11 ) {
F_55 () ;
goto V_16;
}
if ( V_58 < ( 512 << ( 20 - V_10 ) ) )
V_6 = 0 ;
F_7 () ;
F_1 () ;
return 0 ;
V_16:
F_50 ( V_52 ) ;
return V_11 ;
}
static int T_3 F_56 ( char * V_59 )
{
int V_34 = 0 ;
if ( ! V_59 )
goto V_16;
if ( ! strcmp ( V_59 , L_6 ) ) {
F_21 ( V_5 ,
& V_6 ) ;
F_22 ( V_7 ,
& V_6 ) ;
V_34 = 1 ;
} else if ( ! strcmp ( V_59 , L_7 ) ) {
F_22 ( V_5 ,
& V_6 ) ;
F_21 ( V_7 ,
& V_6 ) ;
V_34 = 1 ;
} else if ( ! strcmp ( V_59 , L_8 ) ) {
F_22 ( V_5 ,
& V_6 ) ;
F_22 ( V_7 ,
& V_6 ) ;
V_34 = 1 ;
}
V_16:
if ( ! V_34 )
F_13 ( V_60
L_14 ) ;
return V_34 ;
}
static void F_57 ( T_4 V_61 ,
struct V_62 * V_63 )
{
F_58 ( & V_63 -> V_64 ) ;
if ( ! V_63 -> V_65 )
F_59 ( & V_61 -> V_66 ) ;
else
F_60 ( & V_61 -> V_66 , & V_63 -> V_65 -> V_66 ) ;
V_63 -> V_65 = V_61 ;
}
static inline T_5 F_61 ( T_5 V_67 , struct V_68 * V_69 )
{
if ( F_62 ( V_69 -> V_70 & V_71 ) )
V_67 = F_63 ( V_67 ) ;
return V_67 ;
}
static int F_64 ( struct V_62 * V_63 ,
struct V_68 * V_69 ,
unsigned long V_72 , T_5 * V_67 ,
struct V_73 * V_73 )
{
T_4 V_61 ;
F_19 ( ! F_65 ( V_73 ) ) ;
V_61 = F_66 ( V_63 , V_72 ) ;
if ( F_9 ( ! V_61 ) )
return V_74 ;
F_67 ( V_73 , V_72 , V_51 ) ;
F_68 ( V_73 ) ;
F_69 ( & V_63 -> V_64 ) ;
if ( F_9 ( ! F_70 ( * V_67 ) ) ) {
F_71 ( & V_63 -> V_64 ) ;
F_72 ( V_73 ) ;
F_73 ( V_73 ) ;
F_74 ( V_63 , V_61 ) ;
} else {
T_5 V_75 ;
V_75 = F_75 ( V_73 , V_69 -> V_76 ) ;
V_75 = F_61 ( F_76 ( V_75 ) , V_69 ) ;
V_75 = F_77 ( V_75 ) ;
F_78 ( V_73 , V_69 , V_72 ) ;
F_79 ( V_63 , V_72 , V_67 , V_75 ) ;
F_57 ( V_61 , V_63 ) ;
F_80 ( V_63 , V_77 , V_51 ) ;
V_63 -> V_78 ++ ;
F_71 ( & V_63 -> V_64 ) ;
}
return 0 ;
}
static inline T_6 F_81 ( int V_79 , T_6 V_80 )
{
return ( V_81 & ~ ( V_79 ? 0 : V_82 ) ) | V_80 ;
}
static inline struct V_73 * F_82 ( int V_79 ,
struct V_68 * V_69 ,
unsigned long V_72 , int V_83 ,
T_6 V_80 )
{
return F_83 ( F_81 ( V_79 , V_80 ) ,
V_84 , V_69 , V_72 , V_83 ) ;
}
static inline struct V_73 * F_84 ( int V_79 )
{
return F_85 ( F_81 ( V_79 , 0 ) ,
V_84 ) ;
}
int F_86 ( struct V_62 * V_63 , struct V_68 * V_69 ,
unsigned long V_85 , T_5 * V_67 ,
unsigned int V_86 )
{
struct V_73 * V_73 ;
unsigned long V_72 = V_85 & V_87 ;
T_7 * V_88 ;
if ( V_72 >= V_69 -> V_89 && V_72 + V_90 <= V_69 -> V_91 ) {
if ( F_9 ( F_87 ( V_69 ) ) )
return V_74 ;
if ( F_9 ( F_88 ( V_69 ) ) )
return V_74 ;
V_73 = F_82 ( F_89 ( V_69 ) ,
V_69 , V_72 , F_90 () , 0 ) ;
if ( F_9 ( ! V_73 ) ) {
F_91 ( V_92 ) ;
goto V_16;
}
F_91 ( V_93 ) ;
if ( F_9 ( F_92 ( V_73 , V_63 , V_94 ) ) ) {
F_73 ( V_73 ) ;
goto V_16;
}
if ( F_9 ( F_64 ( V_63 , V_69 , V_72 , V_67 ,
V_73 ) ) ) {
F_72 ( V_73 ) ;
F_73 ( V_73 ) ;
goto V_16;
}
return 0 ;
}
V_16:
if ( F_9 ( F_93 ( V_63 , V_69 , V_67 , V_85 ) ) )
return V_74 ;
if ( F_9 ( F_94 ( * V_67 ) ) )
return 0 ;
V_88 = F_95 ( V_67 , V_85 ) ;
return F_96 ( V_63 , V_69 , V_85 , V_88 , V_67 , V_86 ) ;
}
int F_97 ( struct V_62 * V_95 , struct V_62 * V_96 ,
T_5 * V_97 , T_5 * V_98 , unsigned long V_99 ,
struct V_68 * V_69 )
{
struct V_73 * V_100 ;
T_5 V_67 ;
T_4 V_61 ;
int V_34 ;
V_34 = - V_15 ;
V_61 = F_66 ( V_95 , V_99 ) ;
if ( F_9 ( ! V_61 ) )
goto V_16;
F_69 ( & V_95 -> V_64 ) ;
F_98 ( & V_96 -> V_64 , V_101 ) ;
V_34 = - V_102 ;
V_67 = * V_98 ;
if ( F_9 ( ! F_94 ( V_67 ) ) ) {
F_74 ( V_95 , V_61 ) ;
goto V_103;
}
if ( F_9 ( F_99 ( V_67 ) ) ) {
F_71 ( & V_96 -> V_64 ) ;
F_71 ( & V_95 -> V_64 ) ;
F_74 ( V_95 , V_61 ) ;
F_100 ( V_69 -> V_104 , V_98 ) ;
goto V_16;
}
V_100 = F_101 ( V_67 ) ;
F_19 ( ! F_102 ( V_100 ) ) ;
F_103 ( V_100 ) ;
F_104 ( V_100 ) ;
F_80 ( V_95 , V_77 , V_51 ) ;
F_105 ( V_96 , V_99 , V_98 ) ;
V_67 = F_106 ( F_107 ( V_67 ) ) ;
F_79 ( V_95 , V_99 , V_97 , V_67 ) ;
F_57 ( V_61 , V_95 ) ;
V_95 -> V_78 ++ ;
V_34 = 0 ;
V_103:
F_71 ( & V_96 -> V_64 ) ;
F_71 ( & V_95 -> V_64 ) ;
V_16:
return V_34 ;
}
T_4 F_108 ( struct V_62 * V_63 )
{
T_4 V_61 ;
F_58 ( & V_63 -> V_64 ) ;
V_61 = V_63 -> V_65 ;
if ( F_15 ( & V_61 -> V_66 ) )
V_63 -> V_65 = NULL ;
else {
V_63 -> V_65 = F_109 ( V_61 -> V_66 . V_105 ,
struct V_73 , V_66 ) ;
F_110 ( & V_61 -> V_66 ) ;
}
return V_61 ;
}
static int F_111 ( struct V_62 * V_63 ,
struct V_68 * V_69 ,
unsigned long V_85 ,
T_5 * V_67 , T_5 V_106 ,
struct V_73 * V_73 ,
unsigned long V_72 )
{
T_4 V_61 ;
T_5 V_107 ;
int V_34 = 0 , V_108 ;
struct V_73 * * V_45 ;
V_45 = F_112 ( sizeof( struct V_73 * ) * V_51 ,
V_94 ) ;
if ( F_9 ( ! V_45 ) ) {
V_34 |= V_74 ;
goto V_16;
}
for ( V_108 = 0 ; V_108 < V_51 ; V_108 ++ ) {
V_45 [ V_108 ] = F_113 ( V_109 |
V_110 ,
V_69 , V_85 , F_114 ( V_73 ) ) ;
if ( F_9 ( ! V_45 [ V_108 ] ||
F_92 ( V_45 [ V_108 ] , V_63 ,
V_94 ) ) ) {
if ( V_45 [ V_108 ] )
F_73 ( V_45 [ V_108 ] ) ;
F_115 () ;
while ( -- V_108 >= 0 ) {
F_72 ( V_45 [ V_108 ] ) ;
F_73 ( V_45 [ V_108 ] ) ;
}
F_116 () ;
F_117 ( V_45 ) ;
V_34 |= V_74 ;
goto V_16;
}
}
for ( V_108 = 0 ; V_108 < V_51 ; V_108 ++ ) {
F_118 ( V_45 [ V_108 ] , V_73 + V_108 ,
V_72 + V_111 * V_108 , V_69 ) ;
F_68 ( V_45 [ V_108 ] ) ;
F_119 () ;
}
F_69 ( & V_63 -> V_64 ) ;
if ( F_9 ( ! F_120 ( * V_67 , V_106 ) ) )
goto V_112;
F_19 ( ! F_102 ( V_73 ) ) ;
F_121 ( V_69 , V_72 , V_67 ) ;
V_61 = F_108 ( V_63 ) ;
F_122 ( V_63 , & V_107 , V_61 ) ;
for ( V_108 = 0 ; V_108 < V_51 ; V_108 ++ , V_72 += V_111 ) {
T_7 * V_88 , V_75 ;
V_75 = F_123 ( V_45 [ V_108 ] , V_69 -> V_76 ) ;
V_75 = F_124 ( F_125 ( V_75 ) , V_69 ) ;
F_78 ( V_45 [ V_108 ] , V_69 , V_72 ) ;
V_88 = F_95 ( & V_107 , V_72 ) ;
F_19 ( ! F_126 ( * V_88 ) ) ;
F_127 ( V_63 , V_72 , V_88 , V_75 ) ;
F_128 ( V_88 ) ;
}
F_117 ( V_45 ) ;
F_129 () ;
F_122 ( V_63 , V_67 , V_61 ) ;
F_130 ( V_73 ) ;
F_71 ( & V_63 -> V_64 ) ;
V_34 |= V_113 ;
F_73 ( V_73 ) ;
V_16:
return V_34 ;
V_112:
F_71 ( & V_63 -> V_64 ) ;
F_115 () ;
for ( V_108 = 0 ; V_108 < V_51 ; V_108 ++ ) {
F_72 ( V_45 [ V_108 ] ) ;
F_73 ( V_45 [ V_108 ] ) ;
}
F_116 () ;
F_117 ( V_45 ) ;
goto V_16;
}
int F_131 ( struct V_62 * V_63 , struct V_68 * V_69 ,
unsigned long V_85 , T_5 * V_67 , T_5 V_106 )
{
int V_34 = 0 ;
struct V_73 * V_73 , * V_114 ;
unsigned long V_72 ;
F_19 ( ! V_69 -> V_104 ) ;
F_69 ( & V_63 -> V_64 ) ;
if ( F_9 ( ! F_120 ( * V_67 , V_106 ) ) )
goto V_103;
V_73 = F_101 ( V_106 ) ;
F_19 ( ! F_65 ( V_73 ) || ! F_102 ( V_73 ) ) ;
V_72 = V_85 & V_87 ;
if ( F_132 ( V_73 ) == 1 ) {
T_5 V_75 ;
V_75 = F_133 ( V_106 ) ;
V_75 = F_61 ( F_76 ( V_75 ) , V_69 ) ;
if ( F_134 ( V_69 , V_72 , V_67 , V_75 , 1 ) )
F_135 ( V_69 , V_85 , V_75 ) ;
V_34 |= V_113 ;
goto V_103;
}
F_103 ( V_73 ) ;
F_71 ( & V_63 -> V_64 ) ;
if ( F_136 ( V_69 ) &&
! F_137 () )
V_114 = F_82 ( F_89 ( V_69 ) ,
V_69 , V_72 , F_90 () , 0 ) ;
else
V_114 = NULL ;
if ( F_9 ( ! V_114 ) ) {
F_91 ( V_92 ) ;
V_34 = F_111 ( V_63 , V_69 , V_85 ,
V_67 , V_106 , V_73 , V_72 ) ;
if ( V_34 & V_74 )
F_138 ( V_73 ) ;
F_73 ( V_73 ) ;
goto V_16;
}
F_91 ( V_93 ) ;
if ( F_9 ( F_92 ( V_114 , V_63 , V_94 ) ) ) {
F_73 ( V_114 ) ;
F_138 ( V_73 ) ;
F_73 ( V_73 ) ;
V_34 |= V_74 ;
goto V_16;
}
F_139 ( V_114 , V_73 , V_72 , V_69 , V_51 ) ;
F_68 ( V_114 ) ;
F_69 ( & V_63 -> V_64 ) ;
F_73 ( V_73 ) ;
if ( F_9 ( ! F_120 ( * V_67 , V_106 ) ) ) {
F_71 ( & V_63 -> V_64 ) ;
F_72 ( V_114 ) ;
F_73 ( V_114 ) ;
goto V_16;
} else {
T_5 V_75 ;
F_19 ( ! F_102 ( V_73 ) ) ;
V_75 = F_75 ( V_114 , V_69 -> V_76 ) ;
V_75 = F_61 ( F_76 ( V_75 ) , V_69 ) ;
V_75 = F_77 ( V_75 ) ;
F_121 ( V_69 , V_72 , V_67 ) ;
F_78 ( V_114 , V_69 , V_72 ) ;
F_79 ( V_63 , V_72 , V_67 , V_75 ) ;
F_135 ( V_69 , V_85 , V_75 ) ;
F_130 ( V_73 ) ;
F_73 ( V_73 ) ;
V_34 |= V_113 ;
}
V_103:
F_71 ( & V_63 -> V_64 ) ;
V_16:
return V_34 ;
}
struct V_73 * F_140 ( struct V_62 * V_63 ,
unsigned long V_99 ,
T_5 * V_67 ,
unsigned int V_86 )
{
struct V_73 * V_73 = NULL ;
F_58 ( & V_63 -> V_64 ) ;
if ( V_86 & V_115 && ! F_141 ( * V_67 ) )
goto V_16;
V_73 = F_101 ( * V_67 ) ;
F_19 ( ! F_102 ( V_73 ) ) ;
if ( V_86 & V_116 ) {
T_5 V_107 ;
V_107 = F_133 ( F_76 ( * V_67 ) ) ;
F_79 ( V_63 , V_99 & V_87 , V_67 , V_107 ) ;
}
V_73 += ( V_99 & ~ V_87 ) >> V_10 ;
F_19 ( ! F_65 ( V_73 ) ) ;
if ( V_86 & V_117 )
F_142 ( V_73 ) ;
V_16:
return V_73 ;
}
int F_143 ( struct V_118 * V_119 , struct V_68 * V_69 ,
T_5 * V_67 , unsigned long V_99 )
{
int V_34 = 0 ;
if ( F_144 ( V_67 , V_69 ) == 1 ) {
struct V_73 * V_73 ;
T_4 V_61 ;
V_61 = F_108 ( V_119 -> V_63 ) ;
V_73 = F_101 ( * V_67 ) ;
F_145 ( V_67 ) ;
F_146 ( V_119 , V_67 , V_99 ) ;
F_130 ( V_73 ) ;
F_19 ( F_132 ( V_73 ) < 0 ) ;
F_80 ( V_119 -> V_63 , V_77 , - V_51 ) ;
F_19 ( ! F_102 ( V_73 ) ) ;
V_119 -> V_63 -> V_78 -- ;
F_71 ( & V_119 -> V_63 -> V_64 ) ;
F_147 ( V_119 , V_73 ) ;
F_74 ( V_119 -> V_63 , V_61 ) ;
V_34 = 1 ;
}
return V_34 ;
}
int F_148 ( struct V_68 * V_69 , T_5 * V_67 ,
unsigned long V_99 , unsigned long V_120 ,
unsigned char * V_121 )
{
int V_34 = 0 ;
if ( F_144 ( V_67 , V_69 ) == 1 ) {
F_71 ( & V_69 -> V_122 -> V_64 ) ;
memset ( V_121 , 1 , ( V_120 - V_99 ) >> V_10 ) ;
V_34 = 1 ;
}
return V_34 ;
}
int F_149 ( struct V_68 * V_69 , struct V_68 * V_123 ,
unsigned long V_124 ,
unsigned long V_125 , unsigned long V_126 ,
T_5 * V_127 , T_5 * V_128 )
{
int V_34 = 0 ;
T_5 V_67 ;
struct V_62 * V_63 = V_69 -> V_122 ;
if ( ( V_124 & ~ V_87 ) ||
( V_125 & ~ V_87 ) ||
V_126 - V_124 < V_90 ||
( V_123 -> V_70 & V_129 ) )
goto V_16;
if ( F_150 ( ! F_70 ( * V_128 ) ) ) {
F_19 ( F_94 ( * V_128 ) ) ;
goto V_16;
}
V_34 = F_144 ( V_127 , V_69 ) ;
if ( V_34 == 1 ) {
V_67 = F_151 ( V_63 , V_124 , V_127 ) ;
F_19 ( ! F_70 ( * V_128 ) ) ;
F_79 ( V_63 , V_125 , V_128 , V_67 ) ;
F_71 ( & V_63 -> V_64 ) ;
}
V_16:
return V_34 ;
}
int F_152 ( struct V_68 * V_69 , T_5 * V_67 ,
unsigned long V_99 , T_8 V_130 )
{
struct V_62 * V_63 = V_69 -> V_122 ;
int V_34 = 0 ;
if ( F_144 ( V_67 , V_69 ) == 1 ) {
T_5 V_75 ;
V_75 = F_151 ( V_63 , V_99 , V_67 ) ;
V_75 = F_153 ( V_75 , V_130 ) ;
F_79 ( V_63 , V_99 , V_67 , V_75 ) ;
F_71 ( & V_69 -> V_122 -> V_64 ) ;
V_34 = 1 ;
}
return V_34 ;
}
int F_144 ( T_5 * V_67 , struct V_68 * V_69 )
{
F_69 ( & V_69 -> V_122 -> V_64 ) ;
if ( F_62 ( F_94 ( * V_67 ) ) ) {
if ( F_9 ( F_99 ( * V_67 ) ) ) {
F_71 ( & V_69 -> V_122 -> V_64 ) ;
F_100 ( V_69 -> V_104 , V_67 ) ;
return - 1 ;
} else {
return 1 ;
}
}
F_71 ( & V_69 -> V_122 -> V_64 ) ;
return 0 ;
}
T_5 * F_154 ( struct V_73 * V_73 ,
struct V_62 * V_63 ,
unsigned long V_85 ,
enum V_131 V_35 )
{
T_9 * V_132 ;
T_10 * V_133 ;
T_5 * V_67 , * V_34 = NULL ;
if ( V_85 & ~ V_87 )
goto V_16;
V_132 = F_155 ( V_63 , V_85 ) ;
if ( ! F_156 ( * V_132 ) )
goto V_16;
V_133 = F_157 ( V_132 , V_85 ) ;
if ( ! F_158 ( * V_133 ) )
goto V_16;
V_67 = F_159 ( V_133 , V_85 ) ;
if ( F_70 ( * V_67 ) )
goto V_16;
if ( F_101 ( * V_67 ) != V_73 )
goto V_16;
if ( V_35 == V_134 &&
F_99 ( * V_67 ) )
goto V_16;
if ( F_94 ( * V_67 ) ) {
F_19 ( V_35 == V_135 &&
! F_99 ( * V_67 ) ) ;
V_34 = V_67 ;
}
V_16:
return V_34 ;
}
static int F_160 ( struct V_73 * V_73 ,
struct V_68 * V_69 ,
unsigned long V_85 )
{
struct V_62 * V_63 = V_69 -> V_122 ;
T_5 * V_67 ;
int V_34 = 0 ;
F_69 ( & V_63 -> V_64 ) ;
V_67 = F_154 ( V_73 , V_63 , V_85 ,
V_134 ) ;
if ( V_67 ) {
F_161 ( V_69 , V_85 , V_67 ) ;
V_34 = 1 ;
}
F_71 ( & V_63 -> V_64 ) ;
return V_34 ;
}
static void F_162 ( struct V_73 * V_73 )
{
int V_108 ;
struct V_1 * V_1 = F_163 ( V_73 ) ;
struct V_136 * V_136 ;
int V_137 = 0 ;
F_164 ( & V_1 -> V_138 ) ;
V_136 = F_165 ( V_73 , V_1 ) ;
F_166 ( V_73 ) ;
F_167 ( V_73 ) ;
for ( V_108 = V_51 - 1 ; V_108 >= 1 ; V_108 -- ) {
struct V_73 * V_139 = V_73 + V_108 ;
F_168 ( F_132 ( V_139 ) < 0 ) ;
V_137 += F_132 ( V_139 ) ;
F_168 ( V_137 < 0 ) ;
F_168 ( F_169 ( & V_139 -> V_140 ) != 0 ) ;
F_170 ( F_132 ( V_73 ) + F_132 ( V_139 ) + 1 ,
& V_139 -> V_140 ) ;
F_171 () ;
V_139 -> V_86 &= ~ V_141 | V_142 ;
V_139 -> V_86 |= ( V_73 -> V_86 &
( ( 1L << V_143 ) |
( 1L << V_144 ) |
( 1L << V_145 ) |
( 1L << V_146 ) ) ) ;
V_139 -> V_86 |= ( 1L << V_147 ) ;
F_129 () ;
V_139 -> V_148 = V_73 -> V_148 ;
F_168 ( V_139 -> V_149 ) ;
V_139 -> V_149 = V_73 -> V_149 ;
V_139 -> V_150 = V_73 -> V_150 + V_108 ;
F_168 ( ! F_172 ( V_139 ) ) ;
F_168 ( ! F_173 ( V_139 ) ) ;
F_168 ( ! F_174 ( V_139 ) ) ;
F_168 ( ! F_175 ( V_139 ) ) ;
F_176 ( V_73 , V_139 , V_136 ) ;
}
F_177 ( V_137 , & V_73 -> V_140 ) ;
F_168 ( F_169 ( & V_73 -> V_140 ) <= 0 ) ;
F_178 ( V_1 , V_151 , - 1 ) ;
F_178 ( V_1 , V_152 , V_51 ) ;
F_179 ( V_73 ) ;
F_180 ( V_73 ) ;
F_181 ( & V_1 -> V_138 ) ;
for ( V_108 = 1 ; V_108 < V_51 ; V_108 ++ ) {
struct V_73 * V_139 = V_73 + V_108 ;
F_168 ( F_182 ( V_139 ) <= 0 ) ;
F_73 ( V_139 ) ;
}
F_168 ( F_182 ( V_73 ) <= 0 ) ;
}
static int F_183 ( struct V_73 * V_73 ,
struct V_68 * V_69 ,
unsigned long V_85 )
{
struct V_62 * V_63 = V_69 -> V_122 ;
T_5 * V_67 , V_107 ;
int V_34 = 0 , V_108 ;
T_4 V_61 ;
unsigned long V_72 ;
F_69 ( & V_63 -> V_64 ) ;
V_67 = F_154 ( V_73 , V_63 , V_85 ,
V_135 ) ;
if ( V_67 ) {
V_61 = F_108 ( V_63 ) ;
F_122 ( V_63 , & V_107 , V_61 ) ;
for ( V_108 = 0 , V_72 = V_85 ; V_108 < V_51 ;
V_108 ++ , V_72 += V_111 ) {
T_7 * V_88 , V_75 ;
F_168 ( F_65 ( V_73 + V_108 ) ) ;
V_75 = F_123 ( V_73 + V_108 , V_69 -> V_76 ) ;
V_75 = F_124 ( F_125 ( V_75 ) , V_69 ) ;
if ( ! F_141 ( * V_67 ) )
V_75 = F_184 ( V_75 ) ;
else
F_168 ( F_132 ( V_73 ) != 1 ) ;
if ( ! F_185 ( * V_67 ) )
V_75 = F_186 ( V_75 ) ;
V_88 = F_95 ( & V_107 , V_72 ) ;
F_168 ( ! F_126 ( * V_88 ) ) ;
F_127 ( V_63 , V_72 , V_88 , V_75 ) ;
F_128 ( V_88 ) ;
}
F_129 () ;
F_79 ( V_63 , V_85 , V_67 , F_187 ( * V_67 ) ) ;
F_188 ( V_69 , V_85 , V_85 + V_90 ) ;
F_122 ( V_63 , V_67 , V_61 ) ;
V_34 = 1 ;
}
F_71 ( & V_63 -> V_64 ) ;
return V_34 ;
}
static void F_189 ( struct V_73 * V_73 ,
struct V_104 * V_104 )
{
int V_153 , V_154 ;
struct V_155 * V_156 ;
F_168 ( ! F_102 ( V_73 ) ) ;
F_168 ( F_190 ( V_73 ) ) ;
V_153 = 0 ;
F_191 (avc, &anon_vma->head, same_anon_vma) {
struct V_68 * V_69 = V_156 -> V_69 ;
unsigned long V_99 = F_192 ( V_73 , V_69 ) ;
F_168 ( F_193 ( V_69 ) ) ;
if ( V_99 == - V_157 )
continue;
V_153 += F_160 ( V_73 , V_69 , V_99 ) ;
}
if ( V_153 != F_132 ( V_73 ) )
F_13 ( V_20 L_15 ,
V_153 , F_132 ( V_73 ) ) ;
F_168 ( V_153 != F_132 ( V_73 ) ) ;
F_162 ( V_73 ) ;
V_154 = 0 ;
F_191 (avc, &anon_vma->head, same_anon_vma) {
struct V_68 * V_69 = V_156 -> V_69 ;
unsigned long V_99 = F_192 ( V_73 , V_69 ) ;
F_168 ( F_193 ( V_69 ) ) ;
if ( V_99 == - V_157 )
continue;
V_154 += F_183 ( V_73 , V_69 , V_99 ) ;
}
if ( V_153 != V_154 )
F_13 ( V_20 L_16 ,
V_153 , V_154 , F_132 ( V_73 ) ) ;
F_168 ( V_153 != V_154 ) ;
}
int F_138 ( struct V_73 * V_73 )
{
struct V_104 * V_104 ;
int V_34 = 1 ;
F_168 ( ! F_172 ( V_73 ) ) ;
V_104 = F_194 ( V_73 ) ;
if ( ! V_104 )
goto V_16;
V_34 = 0 ;
if ( ! F_65 ( V_73 ) )
goto V_103;
F_168 ( ! F_175 ( V_73 ) ) ;
F_189 ( V_73 , V_104 ) ;
F_91 ( V_158 ) ;
F_168 ( F_65 ( V_73 ) ) ;
V_103:
F_195 ( V_104 ) ;
V_16:
return V_34 ;
}
int F_196 ( struct V_68 * V_69 ,
unsigned long * V_70 , int V_159 )
{
switch ( V_159 ) {
case V_160 :
if ( * V_70 & ( V_161 | V_162 ) )
return - V_33 ;
* V_70 &= ~ V_129 ;
* V_70 |= V_161 ;
if ( F_9 ( F_197 ( V_69 ) ) )
return - V_15 ;
break;
case V_163 :
if ( * V_70 & ( V_129 | V_162 ) )
return - V_33 ;
* V_70 &= ~ V_161 ;
* V_70 |= V_129 ;
break;
}
return 0 ;
}
static int T_3 F_53 ( void )
{
V_13 = F_198 ( L_17 ,
sizeof( struct V_164 ) ,
F_199 ( struct V_164 ) , 0 , NULL ) ;
if ( ! V_13 )
return - V_15 ;
return 0 ;
}
static void T_3 F_55 ( void )
{
F_200 ( V_13 ) ;
V_13 = NULL ;
}
static inline struct V_164 * F_201 ( void )
{
if ( ! V_13 )
return NULL ;
return F_202 ( V_13 , V_94 ) ;
}
static inline void F_203 ( struct V_164 * V_164 )
{
F_204 ( V_13 , V_164 ) ;
}
static int T_3 F_54 ( void )
{
V_14 = F_205 ( V_165 * sizeof( struct V_166 ) ,
V_94 ) ;
if ( ! V_14 )
return - V_15 ;
return 0 ;
}
static struct V_164 * F_206 ( struct V_62 * V_63 )
{
struct V_164 * V_164 ;
struct V_166 * V_167 ;
struct V_168 * V_169 ;
V_167 = & V_14 [ ( ( unsigned long ) V_63 / sizeof( struct V_62 ) )
% V_165 ] ;
F_207 (mm_slot, node, bucket, hash) {
if ( V_63 == V_164 -> V_63 )
return V_164 ;
}
return NULL ;
}
static void F_208 ( struct V_62 * V_63 ,
struct V_164 * V_164 )
{
struct V_166 * V_167 ;
V_167 = & V_14 [ ( ( unsigned long ) V_63 / sizeof( struct V_62 ) )
% V_165 ] ;
V_164 -> V_63 = V_63 ;
F_209 ( & V_164 -> V_170 , V_167 ) ;
}
static inline int F_210 ( struct V_62 * V_63 )
{
return F_169 ( & V_63 -> V_171 ) == 0 ;
}
int F_211 ( struct V_62 * V_63 )
{
struct V_164 * V_164 ;
int V_12 ;
V_164 = F_201 () ;
if ( ! V_164 )
return - V_15 ;
F_19 ( F_210 ( V_63 ) ) ;
if ( F_9 ( F_212 ( V_172 , & V_63 -> V_86 ) ) ) {
F_203 ( V_164 ) ;
return 0 ;
}
F_69 ( & V_173 ) ;
F_208 ( V_63 , V_164 ) ;
V_12 = F_15 ( & V_21 . V_22 ) ;
F_213 ( & V_164 -> V_174 , & V_21 . V_22 ) ;
F_71 ( & V_173 ) ;
F_214 ( & V_63 -> V_175 ) ;
if ( V_12 )
F_17 ( & V_23 ) ;
return 0 ;
}
int F_197 ( struct V_68 * V_69 )
{
unsigned long V_176 , V_177 ;
if ( ! V_69 -> V_104 )
return 0 ;
if ( V_69 -> V_178 )
return 0 ;
F_19 ( F_215 ( V_69 ) || V_69 -> V_70 & V_162 ) ;
V_176 = ( V_69 -> V_89 + ~ V_87 ) & V_87 ;
V_177 = V_69 -> V_91 & V_87 ;
if ( V_176 < V_177 )
return F_88 ( V_69 ) ;
return 0 ;
}
void F_216 ( struct V_62 * V_63 )
{
struct V_164 * V_164 ;
int free = 0 ;
F_69 ( & V_173 ) ;
V_164 = F_206 ( V_63 ) ;
if ( V_164 && V_21 . V_164 != V_164 ) {
F_217 ( & V_164 -> V_170 ) ;
F_110 ( & V_164 -> V_174 ) ;
free = 1 ;
}
F_71 ( & V_173 ) ;
if ( free ) {
F_22 ( V_172 , & V_63 -> V_86 ) ;
F_203 ( V_164 ) ;
F_218 ( V_63 ) ;
} else if ( V_164 ) {
F_219 ( & V_63 -> V_179 ) ;
F_220 ( & V_63 -> V_179 ) ;
}
}
static void F_221 ( struct V_73 * V_73 )
{
F_222 ( V_73 , V_180 + 0 ) ;
F_223 ( V_73 ) ;
F_224 ( V_73 ) ;
}
static void F_225 ( T_7 * V_88 , T_7 * V_181 )
{
while ( -- V_181 >= V_88 ) {
T_7 V_182 = * V_181 ;
if ( ! F_126 ( V_182 ) )
F_221 ( F_226 ( V_182 ) ) ;
}
}
static void F_227 ( T_7 * V_88 )
{
F_225 ( V_88 , V_88 + V_51 ) ;
}
static int F_228 ( struct V_68 * V_69 ,
unsigned long V_85 ,
T_7 * V_88 )
{
struct V_73 * V_73 ;
T_7 * V_181 ;
int V_183 = 0 , V_184 = 0 , V_185 = 0 ;
for ( V_181 = V_88 ; V_181 < V_88 + V_51 ;
V_181 ++ , V_85 += V_111 ) {
T_7 V_182 = * V_181 ;
if ( F_126 ( V_182 ) ) {
if ( ++ V_185 <= V_49 )
continue;
else {
F_225 ( V_88 , V_181 ) ;
goto V_16;
}
}
if ( ! F_229 ( V_182 ) || ! F_230 ( V_182 ) ) {
F_225 ( V_88 , V_181 ) ;
goto V_16;
}
V_73 = F_231 ( V_69 , V_85 , V_182 ) ;
if ( F_9 ( ! V_73 ) ) {
F_225 ( V_88 , V_181 ) ;
goto V_16;
}
F_19 ( F_65 ( V_73 ) ) ;
F_168 ( ! F_172 ( V_73 ) ) ;
F_19 ( ! F_175 ( V_73 ) ) ;
if ( F_182 ( V_73 ) != 1 ) {
F_225 ( V_88 , V_181 ) ;
goto V_16;
}
if ( ! F_232 ( V_73 ) ) {
F_225 ( V_88 , V_181 ) ;
goto V_16;
}
if ( F_233 ( V_73 ) ) {
F_223 ( V_73 ) ;
F_225 ( V_88 , V_181 ) ;
goto V_16;
}
F_234 ( V_73 , V_180 + 0 ) ;
F_19 ( ! F_235 ( V_73 ) ) ;
F_19 ( F_236 ( V_73 ) ) ;
if ( F_237 ( V_182 ) || F_238 ( V_73 ) ||
F_239 ( V_69 -> V_122 , V_85 ) )
V_183 = 1 ;
}
if ( F_9 ( ! V_183 ) )
F_227 ( V_88 ) ;
else
V_184 = 1 ;
V_16:
return V_184 ;
}
static void F_240 ( T_7 * V_88 , struct V_73 * V_73 ,
struct V_68 * V_69 ,
unsigned long V_85 ,
T_11 * V_186 )
{
T_7 * V_181 ;
for ( V_181 = V_88 ; V_181 < V_88 + V_51 ; V_181 ++ ) {
T_7 V_182 = * V_181 ;
struct V_73 * V_100 ;
if ( F_126 ( V_182 ) ) {
F_241 ( V_73 , V_85 ) ;
F_80 ( V_69 -> V_122 , V_77 , 1 ) ;
} else {
V_100 = F_226 ( V_182 ) ;
F_118 ( V_73 , V_100 , V_85 , V_69 ) ;
F_19 ( F_132 ( V_100 ) != 1 ) ;
F_221 ( V_100 ) ;
F_69 ( V_186 ) ;
F_242 ( V_69 -> V_122 , V_85 , V_181 ) ;
F_130 ( V_100 ) ;
F_71 ( V_186 ) ;
F_243 ( V_100 ) ;
}
V_85 += V_111 ;
V_73 ++ ;
}
}
static void F_244 ( struct V_62 * V_63 ,
unsigned long V_85 ,
struct V_73 * * V_187 ,
struct V_68 * V_69 ,
int V_169 )
{
T_9 * V_132 ;
T_10 * V_133 ;
T_5 * V_67 , V_107 ;
T_7 * V_88 ;
T_4 V_61 ;
struct V_73 * V_114 ;
T_11 * V_186 ;
int V_184 ;
unsigned long V_176 , V_177 ;
F_19 ( V_85 & ~ V_87 ) ;
#ifndef F_245
F_246 ( & V_63 -> V_179 ) ;
F_19 ( ! * V_187 ) ;
V_114 = * V_187 ;
#else
F_19 ( * V_187 ) ;
V_114 = F_82 ( F_247 () , V_69 , V_85 ,
V_169 , V_110 ) ;
F_246 ( & V_63 -> V_179 ) ;
if ( F_9 ( ! V_114 ) ) {
F_91 ( V_188 ) ;
* V_187 = F_248 ( - V_15 ) ;
return;
}
#endif
F_91 ( V_189 ) ;
if ( F_9 ( F_92 ( V_114 , V_63 , V_94 ) ) ) {
#ifdef F_245
F_73 ( V_114 ) ;
#endif
return;
}
F_219 ( & V_63 -> V_179 ) ;
if ( F_9 ( F_210 ( V_63 ) ) )
goto V_16;
V_69 = F_249 ( V_63 , V_85 ) ;
V_176 = ( V_69 -> V_89 + ~ V_87 ) & V_87 ;
V_177 = V_69 -> V_91 & V_87 ;
if ( V_85 < V_176 || V_85 + V_90 > V_177 )
goto V_16;
if ( ( ! ( V_69 -> V_70 & V_161 ) && ! F_250 () ) ||
( V_69 -> V_70 & V_129 ) )
goto V_16;
if ( ! V_69 -> V_104 || V_69 -> V_178 )
goto V_16;
if ( F_193 ( V_69 ) )
goto V_16;
F_19 ( F_215 ( V_69 ) || V_69 -> V_70 & V_162 ) ;
V_132 = F_155 ( V_63 , V_85 ) ;
if ( ! F_156 ( * V_132 ) )
goto V_16;
V_133 = F_157 ( V_132 , V_85 ) ;
if ( ! F_158 ( * V_133 ) )
goto V_16;
V_67 = F_159 ( V_133 , V_85 ) ;
if ( ! F_251 ( * V_67 ) || F_94 ( * V_67 ) )
goto V_16;
F_252 ( V_69 -> V_104 ) ;
V_88 = F_95 ( V_67 , V_85 ) ;
V_186 = F_253 ( V_63 , V_67 ) ;
F_69 ( & V_63 -> V_64 ) ;
V_107 = F_121 ( V_69 , V_85 , V_67 ) ;
F_71 ( & V_63 -> V_64 ) ;
F_69 ( V_186 ) ;
V_184 = F_228 ( V_69 , V_85 , V_88 ) ;
F_71 ( V_186 ) ;
if ( F_9 ( ! V_184 ) ) {
F_128 ( V_88 ) ;
F_69 ( & V_63 -> V_64 ) ;
F_168 ( ! F_70 ( * V_67 ) ) ;
F_79 ( V_63 , V_85 , V_67 , V_107 ) ;
F_71 ( & V_63 -> V_64 ) ;
F_254 ( V_69 -> V_104 ) ;
goto V_16;
}
F_254 ( V_69 -> V_104 ) ;
F_240 ( V_88 , V_114 , V_69 , V_85 , V_186 ) ;
F_128 ( V_88 ) ;
F_68 ( V_114 ) ;
V_61 = F_255 ( V_107 ) ;
F_19 ( F_182 ( V_61 ) != 1 ) ;
F_19 ( F_132 ( V_61 ) != 0 ) ;
V_107 = F_75 ( V_114 , V_69 -> V_76 ) ;
V_107 = F_61 ( F_76 ( V_107 ) , V_69 ) ;
V_107 = F_77 ( V_107 ) ;
F_129 () ;
F_69 ( & V_63 -> V_64 ) ;
F_168 ( ! F_70 ( * V_67 ) ) ;
F_78 ( V_114 , V_69 , V_85 ) ;
F_79 ( V_63 , V_85 , V_67 , V_107 ) ;
F_135 ( V_69 , V_85 , V_107 ) ;
F_57 ( V_61 , V_63 ) ;
F_71 ( & V_63 -> V_64 ) ;
#ifndef F_245
* V_187 = NULL ;
#endif
V_46 ++ ;
V_190:
F_220 ( & V_63 -> V_179 ) ;
return;
V_16:
F_72 ( V_114 ) ;
#ifdef F_245
F_73 ( V_114 ) ;
#endif
goto V_190;
}
static int F_256 ( struct V_62 * V_63 ,
struct V_68 * V_69 ,
unsigned long V_85 ,
struct V_73 * * V_187 )
{
T_9 * V_132 ;
T_10 * V_133 ;
T_5 * V_67 ;
T_7 * V_88 , * V_181 ;
int V_34 = 0 , V_183 = 0 , V_185 = 0 ;
struct V_73 * V_73 ;
unsigned long V_191 ;
T_11 * V_186 ;
int V_169 = - 1 ;
F_19 ( V_85 & ~ V_87 ) ;
V_132 = F_155 ( V_63 , V_85 ) ;
if ( ! F_156 ( * V_132 ) )
goto V_16;
V_133 = F_157 ( V_132 , V_85 ) ;
if ( ! F_158 ( * V_133 ) )
goto V_16;
V_67 = F_159 ( V_133 , V_85 ) ;
if ( ! F_251 ( * V_67 ) || F_94 ( * V_67 ) )
goto V_16;
V_88 = F_257 ( V_63 , V_67 , V_85 , & V_186 ) ;
for ( V_191 = V_85 , V_181 = V_88 ; V_181 < V_88 + V_51 ;
V_181 ++ , V_191 += V_111 ) {
T_7 V_182 = * V_181 ;
if ( F_126 ( V_182 ) ) {
if ( ++ V_185 <= V_49 )
continue;
else
goto V_192;
}
if ( ! F_229 ( V_182 ) || ! F_230 ( V_182 ) )
goto V_192;
V_73 = F_231 ( V_69 , V_191 , V_182 ) ;
if ( F_9 ( ! V_73 ) )
goto V_192;
if ( V_169 == - 1 )
V_169 = F_114 ( V_73 ) ;
F_19 ( F_65 ( V_73 ) ) ;
if ( ! F_236 ( V_73 ) || F_235 ( V_73 ) || ! F_172 ( V_73 ) )
goto V_192;
if ( F_182 ( V_73 ) != 1 )
goto V_192;
if ( F_237 ( V_182 ) || F_238 ( V_73 ) ||
F_239 ( V_69 -> V_122 , V_85 ) )
V_183 = 1 ;
}
if ( V_183 )
V_34 = 1 ;
V_192:
F_258 ( V_88 , V_186 ) ;
if ( V_34 )
F_244 ( V_63 , V_85 , V_187 , V_69 , V_169 ) ;
V_16:
return V_34 ;
}
static void F_259 ( struct V_164 * V_164 )
{
struct V_62 * V_63 = V_164 -> V_63 ;
F_19 ( V_193 != 1 && ! F_260 ( & V_173 ) ) ;
if ( F_210 ( V_63 ) ) {
F_217 ( & V_164 -> V_170 ) ;
F_110 ( & V_164 -> V_174 ) ;
F_203 ( V_164 ) ;
F_218 ( V_63 ) ;
}
}
static unsigned int F_261 ( unsigned int V_45 ,
struct V_73 * * V_187 )
__releases( &khugepaged_mm_lock
static int F_262 ( void )
{
return ! F_15 ( & V_21 . V_22 ) &&
F_8 () ;
}
static int F_263 ( void )
{
return ! F_15 ( & V_21 . V_22 ) ||
! F_8 () ;
}
static void F_264 ( struct V_73 * * V_187 )
{
unsigned int V_194 = 0 , V_195 = 0 ;
unsigned int V_45 = V_44 ;
F_265 () ;
while ( V_194 < V_45 ) {
F_119 () ;
#ifndef F_245
if ( ! * V_187 ) {
* V_187 = F_84 ( F_247 () ) ;
if ( F_9 ( ! * V_187 ) ) {
F_91 ( V_188 ) ;
break;
}
F_91 ( V_189 ) ;
}
#else
if ( F_12 ( * V_187 ) )
break;
#endif
if ( F_9 ( F_266 () || F_267 ( V_196 ) ) )
break;
F_69 ( & V_173 ) ;
if ( ! V_21 . V_164 )
V_195 ++ ;
if ( F_262 () &&
V_195 < 2 )
V_194 += F_261 ( V_45 - V_194 ,
V_187 ) ;
else
V_194 = V_45 ;
F_71 ( & V_173 ) ;
}
}
static void F_268 ( void )
{
F_269 ( V_23 , false ,
F_270 ( V_43 ) ) ;
}
static struct V_73 * F_271 ( void )
{
struct V_73 * V_187 ;
do {
V_187 = F_84 ( F_247 () ) ;
if ( ! V_187 ) {
F_91 ( V_188 ) ;
F_268 () ;
} else
F_91 ( V_189 ) ;
} while ( F_9 ( ! V_187 ) &&
F_62 ( F_8 () ) );
return V_187 ;
}
static void F_272 ( void )
{
struct V_73 * V_187 ;
#ifdef F_245
V_187 = NULL ;
#endif
while ( F_62 ( F_8 () ) ) {
#ifndef F_245
V_187 = F_271 () ;
if ( F_9 ( ! V_187 ) )
break;
#else
if ( F_12 ( V_187 ) ) {
F_268 () ;
V_187 = NULL ;
}
#endif
F_264 ( & V_187 ) ;
#ifndef F_245
if ( V_187 )
F_73 ( V_187 ) ;
#endif
F_273 () ;
if ( F_9 ( F_266 () ) )
break;
if ( F_262 () ) {
if ( ! V_40 )
continue;
F_269 ( V_23 , false ,
F_270 ( V_40 ) ) ;
} else if ( F_8 () )
F_274 ( V_23 ,
F_263 () ) ;
}
}
static int V_19 ( void * V_185 )
{
struct V_164 * V_164 ;
F_275 () ;
F_276 ( V_196 , 19 ) ;
F_10 ( & V_17 ) ;
for (; ; ) {
F_16 ( & V_17 ) ;
F_19 ( V_18 != V_196 ) ;
F_272 () ;
F_19 ( V_18 != V_196 ) ;
F_10 ( & V_17 ) ;
if ( ! F_8 () )
break;
if ( F_9 ( F_266 () ) )
break;
}
F_69 ( & V_173 ) ;
V_164 = V_21 . V_164 ;
V_21 . V_164 = NULL ;
if ( V_164 )
F_259 ( V_164 ) ;
F_71 ( & V_173 ) ;
V_18 = NULL ;
F_16 ( & V_17 ) ;
return 0 ;
}
void F_277 ( struct V_62 * V_63 , T_5 * V_67 )
{
struct V_73 * V_73 ;
F_69 ( & V_63 -> V_64 ) ;
if ( F_9 ( ! F_94 ( * V_67 ) ) ) {
F_71 ( & V_63 -> V_64 ) ;
return;
}
V_73 = F_101 ( * V_67 ) ;
F_19 ( ! F_182 ( V_73 ) ) ;
F_103 ( V_73 ) ;
F_71 ( & V_63 -> V_64 ) ;
F_138 ( V_73 ) ;
F_73 ( V_73 ) ;
F_168 ( F_94 ( * V_67 ) ) ;
}
static void F_278 ( struct V_62 * V_63 ,
unsigned long V_85 )
{
T_9 * V_132 ;
T_10 * V_133 ;
T_5 * V_67 ;
F_19 ( ! ( V_85 & ~ V_87 ) ) ;
V_132 = F_155 ( V_63 , V_85 ) ;
if ( ! F_156 ( * V_132 ) )
return;
V_133 = F_157 ( V_132 , V_85 ) ;
if ( ! F_158 ( * V_133 ) )
return;
V_67 = F_159 ( V_133 , V_85 ) ;
if ( ! F_251 ( * V_67 ) )
return;
F_279 ( V_63 , V_67 ) ;
}
void F_280 ( struct V_68 * V_69 ,
unsigned long V_197 ,
unsigned long V_120 ,
long V_198 )
{
if ( V_197 & ~ V_87 &&
( V_197 & V_87 ) >= V_69 -> V_89 &&
( V_197 & V_87 ) + V_90 <= V_69 -> V_91 )
F_278 ( V_69 -> V_122 , V_197 ) ;
if ( V_120 & ~ V_87 &&
( V_120 & V_87 ) >= V_69 -> V_89 &&
( V_120 & V_87 ) + V_90 <= V_69 -> V_91 )
F_278 ( V_69 -> V_122 , V_120 ) ;
if ( V_198 > 0 ) {
struct V_68 * V_105 = V_69 -> V_199 ;
unsigned long V_200 = V_105 -> V_89 ;
V_200 += V_198 << V_10 ;
if ( V_200 & ~ V_87 &&
( V_200 & V_87 ) >= V_105 -> V_89 &&
( V_200 & V_87 ) + V_90 <= V_105 -> V_91 )
F_278 ( V_105 -> V_122 , V_200 ) ;
}
}
