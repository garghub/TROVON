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
static int T_3 F_45 ( void )
{
int V_11 ;
#ifdef F_46
static struct V_24 * V_52 ;
#endif
V_11 = - V_33 ;
if ( ! F_47 () ) {
V_6 = 0 ;
goto V_16;
}
#ifdef F_46
V_11 = - V_15 ;
V_52 = F_48 ( L_11 , V_53 ) ;
if ( F_9 ( ! V_52 ) ) {
F_13 ( V_20 L_12 ) ;
goto V_16;
}
V_11 = F_49 ( V_52 , & V_54 ) ;
if ( V_11 ) {
F_13 ( V_20 L_13 ) ;
goto V_16;
}
V_11 = F_49 ( V_52 , & V_55 ) ;
if ( V_11 ) {
F_13 ( V_20 L_13 ) ;
goto V_16;
}
#endif
V_11 = F_50 () ;
if ( V_11 )
goto V_16;
V_11 = F_51 () ;
if ( V_11 ) {
F_52 () ;
goto V_16;
}
if ( V_56 < ( 512 << ( 20 - V_10 ) ) )
V_6 = 0 ;
F_7 () ;
F_1 () ;
V_16:
return V_11 ;
}
static int T_3 F_53 ( char * V_57 )
{
int V_34 = 0 ;
if ( ! V_57 )
goto V_16;
if ( ! strcmp ( V_57 , L_6 ) ) {
F_21 ( V_5 ,
& V_6 ) ;
F_22 ( V_7 ,
& V_6 ) ;
V_34 = 1 ;
} else if ( ! strcmp ( V_57 , L_7 ) ) {
F_22 ( V_5 ,
& V_6 ) ;
F_21 ( V_7 ,
& V_6 ) ;
V_34 = 1 ;
} else if ( ! strcmp ( V_57 , L_8 ) ) {
F_22 ( V_5 ,
& V_6 ) ;
F_22 ( V_7 ,
& V_6 ) ;
V_34 = 1 ;
}
V_16:
if ( ! V_34 )
F_13 ( V_58
L_14 ) ;
return V_34 ;
}
static void F_54 ( T_4 V_59 ,
struct V_60 * V_61 )
{
F_55 ( & V_61 -> V_62 ) ;
if ( ! V_61 -> V_63 )
F_56 ( & V_59 -> V_64 ) ;
else
F_57 ( & V_59 -> V_64 , & V_61 -> V_63 -> V_64 ) ;
V_61 -> V_63 = V_59 ;
}
static inline T_5 F_58 ( T_5 V_65 , struct V_66 * V_67 )
{
if ( F_59 ( V_67 -> V_68 & V_69 ) )
V_65 = F_60 ( V_65 ) ;
return V_65 ;
}
static int F_61 ( struct V_60 * V_61 ,
struct V_66 * V_67 ,
unsigned long V_70 , T_5 * V_65 ,
struct V_71 * V_71 )
{
int V_34 = 0 ;
T_4 V_59 ;
F_19 ( ! F_62 ( V_71 ) ) ;
V_59 = F_63 ( V_61 , V_70 ) ;
if ( F_9 ( ! V_59 ) ) {
F_64 ( V_71 ) ;
F_65 ( V_71 ) ;
return V_72 ;
}
F_66 ( V_71 , V_70 , V_51 ) ;
F_67 ( V_71 ) ;
F_68 ( & V_61 -> V_62 ) ;
if ( F_9 ( ! F_69 ( * V_65 ) ) ) {
F_70 ( & V_61 -> V_62 ) ;
F_64 ( V_71 ) ;
F_65 ( V_71 ) ;
F_71 ( V_61 , V_59 ) ;
} else {
T_5 V_73 ;
V_73 = F_72 ( V_71 , V_67 -> V_74 ) ;
V_73 = F_58 ( F_73 ( V_73 ) , V_67 ) ;
V_73 = F_74 ( V_73 ) ;
F_75 ( V_71 , V_67 , V_70 ) ;
F_76 ( V_61 , V_70 , V_65 , V_73 ) ;
F_54 ( V_59 , V_61 ) ;
F_77 ( V_61 , V_75 , V_51 ) ;
F_70 ( & V_61 -> V_62 ) ;
}
return V_34 ;
}
static inline T_6 F_78 ( int V_76 , T_6 V_77 )
{
return ( V_78 & ~ ( V_76 ? 0 : V_79 ) ) | V_77 ;
}
static inline struct V_71 * F_79 ( int V_76 ,
struct V_66 * V_67 ,
unsigned long V_70 , int V_80 ,
T_6 V_77 )
{
return F_80 ( F_78 ( V_76 , V_77 ) ,
V_81 , V_67 , V_70 , V_80 ) ;
}
static inline struct V_71 * F_81 ( int V_76 )
{
return F_82 ( F_78 ( V_76 , 0 ) ,
V_81 ) ;
}
int F_83 ( struct V_60 * V_61 , struct V_66 * V_67 ,
unsigned long V_82 , T_5 * V_65 ,
unsigned int V_83 )
{
struct V_71 * V_71 ;
unsigned long V_70 = V_82 & V_84 ;
T_7 * V_85 ;
if ( V_70 >= V_67 -> V_86 && V_70 + V_87 <= V_67 -> V_88 ) {
if ( F_9 ( F_84 ( V_67 ) ) )
return V_72 ;
if ( F_9 ( F_85 ( V_67 ) ) )
return V_72 ;
V_71 = F_79 ( F_86 ( V_67 ) ,
V_67 , V_70 , F_87 () , 0 ) ;
if ( F_9 ( ! V_71 ) ) {
F_88 ( V_89 ) ;
goto V_16;
}
F_88 ( V_90 ) ;
if ( F_9 ( F_89 ( V_71 , V_61 , V_91 ) ) ) {
F_65 ( V_71 ) ;
goto V_16;
}
return F_61 ( V_61 , V_67 , V_70 , V_65 , V_71 ) ;
}
V_16:
if ( F_9 ( F_90 ( V_61 , V_67 , V_65 , V_82 ) ) )
return V_72 ;
if ( F_9 ( F_91 ( * V_65 ) ) )
return 0 ;
V_85 = F_92 ( V_65 , V_82 ) ;
return F_93 ( V_61 , V_67 , V_82 , V_85 , V_65 , V_83 ) ;
}
int F_94 ( struct V_60 * V_92 , struct V_60 * V_93 ,
T_5 * V_94 , T_5 * V_95 , unsigned long V_96 ,
struct V_66 * V_67 )
{
struct V_71 * V_97 ;
T_5 V_65 ;
T_4 V_59 ;
int V_34 ;
V_34 = - V_15 ;
V_59 = F_63 ( V_92 , V_96 ) ;
if ( F_9 ( ! V_59 ) )
goto V_16;
F_68 ( & V_92 -> V_62 ) ;
F_95 ( & V_93 -> V_62 , V_98 ) ;
V_34 = - V_99 ;
V_65 = * V_95 ;
if ( F_9 ( ! F_91 ( V_65 ) ) ) {
F_71 ( V_92 , V_59 ) ;
goto V_100;
}
if ( F_9 ( F_96 ( V_65 ) ) ) {
F_70 ( & V_93 -> V_62 ) ;
F_70 ( & V_92 -> V_62 ) ;
F_71 ( V_92 , V_59 ) ;
F_97 ( V_67 -> V_101 , V_95 ) ;
goto V_16;
}
V_97 = F_98 ( V_65 ) ;
F_19 ( ! F_99 ( V_97 ) ) ;
F_100 ( V_97 ) ;
F_101 ( V_97 ) ;
F_77 ( V_92 , V_75 , V_51 ) ;
F_102 ( V_93 , V_96 , V_95 ) ;
V_65 = F_103 ( F_104 ( V_65 ) ) ;
F_76 ( V_92 , V_96 , V_94 , V_65 ) ;
F_54 ( V_59 , V_92 ) ;
V_34 = 0 ;
V_100:
F_70 ( & V_93 -> V_62 ) ;
F_70 ( & V_92 -> V_62 ) ;
V_16:
return V_34 ;
}
T_4 F_105 ( struct V_60 * V_61 )
{
T_4 V_59 ;
F_55 ( & V_61 -> V_62 ) ;
V_59 = V_61 -> V_63 ;
if ( F_15 ( & V_59 -> V_64 ) )
V_61 -> V_63 = NULL ;
else {
V_61 -> V_63 = F_106 ( V_59 -> V_64 . V_102 ,
struct V_71 , V_64 ) ;
F_107 ( & V_59 -> V_64 ) ;
}
return V_59 ;
}
static int F_108 ( struct V_60 * V_61 ,
struct V_66 * V_67 ,
unsigned long V_82 ,
T_5 * V_65 , T_5 V_103 ,
struct V_71 * V_71 ,
unsigned long V_70 )
{
T_4 V_59 ;
T_5 V_104 ;
int V_34 = 0 , V_105 ;
struct V_71 * * V_45 ;
V_45 = F_109 ( sizeof( struct V_71 * ) * V_51 ,
V_91 ) ;
if ( F_9 ( ! V_45 ) ) {
V_34 |= V_72 ;
goto V_16;
}
for ( V_105 = 0 ; V_105 < V_51 ; V_105 ++ ) {
V_45 [ V_105 ] = F_110 ( V_106 |
V_107 ,
V_67 , V_82 , F_111 ( V_71 ) ) ;
if ( F_9 ( ! V_45 [ V_105 ] ||
F_89 ( V_45 [ V_105 ] , V_61 ,
V_91 ) ) ) {
if ( V_45 [ V_105 ] )
F_65 ( V_45 [ V_105 ] ) ;
F_112 () ;
while ( -- V_105 >= 0 ) {
F_64 ( V_45 [ V_105 ] ) ;
F_65 ( V_45 [ V_105 ] ) ;
}
F_113 () ;
F_114 ( V_45 ) ;
V_34 |= V_72 ;
goto V_16;
}
}
for ( V_105 = 0 ; V_105 < V_51 ; V_105 ++ ) {
F_115 ( V_45 [ V_105 ] , V_71 + V_105 ,
V_70 + V_108 * V_105 , V_67 ) ;
F_67 ( V_45 [ V_105 ] ) ;
F_116 () ;
}
F_68 ( & V_61 -> V_62 ) ;
if ( F_9 ( ! F_117 ( * V_65 , V_103 ) ) )
goto V_109;
F_19 ( ! F_99 ( V_71 ) ) ;
F_118 ( V_67 , V_70 , V_65 ) ;
V_59 = F_105 ( V_61 ) ;
F_119 ( V_61 , & V_104 , V_59 ) ;
for ( V_105 = 0 ; V_105 < V_51 ; V_105 ++ , V_70 += V_108 ) {
T_7 * V_85 , V_73 ;
V_73 = F_120 ( V_45 [ V_105 ] , V_67 -> V_74 ) ;
V_73 = F_121 ( F_122 ( V_73 ) , V_67 ) ;
F_75 ( V_45 [ V_105 ] , V_67 , V_70 ) ;
V_85 = F_92 ( & V_104 , V_70 ) ;
F_19 ( ! F_123 ( * V_85 ) ) ;
F_124 ( V_61 , V_70 , V_85 , V_73 ) ;
F_125 ( V_85 ) ;
}
F_114 ( V_45 ) ;
V_61 -> V_110 ++ ;
F_126 () ;
F_119 ( V_61 , V_65 , V_59 ) ;
F_127 ( V_71 ) ;
F_70 ( & V_61 -> V_62 ) ;
V_34 |= V_111 ;
F_65 ( V_71 ) ;
V_16:
return V_34 ;
V_109:
F_70 ( & V_61 -> V_62 ) ;
F_112 () ;
for ( V_105 = 0 ; V_105 < V_51 ; V_105 ++ ) {
F_64 ( V_45 [ V_105 ] ) ;
F_65 ( V_45 [ V_105 ] ) ;
}
F_113 () ;
F_114 ( V_45 ) ;
goto V_16;
}
int F_128 ( struct V_60 * V_61 , struct V_66 * V_67 ,
unsigned long V_82 , T_5 * V_65 , T_5 V_103 )
{
int V_34 = 0 ;
struct V_71 * V_71 , * V_112 ;
unsigned long V_70 ;
F_19 ( ! V_67 -> V_101 ) ;
F_68 ( & V_61 -> V_62 ) ;
if ( F_9 ( ! F_117 ( * V_65 , V_103 ) ) )
goto V_100;
V_71 = F_98 ( V_103 ) ;
F_19 ( ! F_62 ( V_71 ) || ! F_99 ( V_71 ) ) ;
V_70 = V_82 & V_84 ;
if ( F_129 ( V_71 ) == 1 ) {
T_5 V_73 ;
V_73 = F_130 ( V_103 ) ;
V_73 = F_58 ( F_73 ( V_73 ) , V_67 ) ;
if ( F_131 ( V_67 , V_70 , V_65 , V_73 , 1 ) )
F_132 ( V_67 , V_82 , V_73 ) ;
V_34 |= V_111 ;
goto V_100;
}
F_100 ( V_71 ) ;
F_70 ( & V_61 -> V_62 ) ;
if ( F_133 ( V_67 ) &&
! F_134 () )
V_112 = F_79 ( F_86 ( V_67 ) ,
V_67 , V_70 , F_87 () , 0 ) ;
else
V_112 = NULL ;
if ( F_9 ( ! V_112 ) ) {
F_88 ( V_89 ) ;
V_34 = F_108 ( V_61 , V_67 , V_82 ,
V_65 , V_103 , V_71 , V_70 ) ;
F_65 ( V_71 ) ;
goto V_16;
}
F_88 ( V_90 ) ;
if ( F_9 ( F_89 ( V_112 , V_61 , V_91 ) ) ) {
F_65 ( V_112 ) ;
F_65 ( V_71 ) ;
V_34 |= V_72 ;
goto V_16;
}
F_135 ( V_112 , V_71 , V_70 , V_67 , V_51 ) ;
F_67 ( V_112 ) ;
F_68 ( & V_61 -> V_62 ) ;
F_65 ( V_71 ) ;
if ( F_9 ( ! F_117 ( * V_65 , V_103 ) ) ) {
F_64 ( V_112 ) ;
F_65 ( V_112 ) ;
} else {
T_5 V_73 ;
F_19 ( ! F_99 ( V_71 ) ) ;
V_73 = F_72 ( V_112 , V_67 -> V_74 ) ;
V_73 = F_58 ( F_73 ( V_73 ) , V_67 ) ;
V_73 = F_74 ( V_73 ) ;
F_118 ( V_67 , V_70 , V_65 ) ;
F_75 ( V_112 , V_67 , V_70 ) ;
F_76 ( V_61 , V_70 , V_65 , V_73 ) ;
F_132 ( V_67 , V_82 , V_73 ) ;
F_127 ( V_71 ) ;
F_65 ( V_71 ) ;
V_34 |= V_111 ;
}
V_100:
F_70 ( & V_61 -> V_62 ) ;
V_16:
return V_34 ;
}
struct V_71 * F_136 ( struct V_60 * V_61 ,
unsigned long V_96 ,
T_5 * V_65 ,
unsigned int V_83 )
{
struct V_71 * V_71 = NULL ;
F_55 ( & V_61 -> V_62 ) ;
if ( V_83 & V_113 && ! F_137 ( * V_65 ) )
goto V_16;
V_71 = F_98 ( * V_65 ) ;
F_19 ( ! F_99 ( V_71 ) ) ;
if ( V_83 & V_114 ) {
T_5 V_104 ;
V_104 = F_130 ( F_73 ( * V_65 ) ) ;
F_76 ( V_61 , V_96 & V_84 , V_65 , V_104 ) ;
}
V_71 += ( V_96 & ~ V_84 ) >> V_10 ;
F_19 ( ! F_62 ( V_71 ) ) ;
if ( V_83 & V_115 )
F_138 ( V_71 ) ;
V_16:
return V_71 ;
}
int F_139 ( struct V_116 * V_117 , struct V_66 * V_67 ,
T_5 * V_65 )
{
int V_34 = 0 ;
F_68 ( & V_117 -> V_61 -> V_62 ) ;
if ( F_59 ( F_91 ( * V_65 ) ) ) {
if ( F_9 ( F_96 ( * V_65 ) ) ) {
F_70 ( & V_117 -> V_61 -> V_62 ) ;
F_97 ( V_67 -> V_101 ,
V_65 ) ;
} else {
struct V_71 * V_71 ;
T_4 V_59 ;
V_59 = F_105 ( V_117 -> V_61 ) ;
V_71 = F_98 ( * V_65 ) ;
F_140 ( V_65 ) ;
F_127 ( V_71 ) ;
F_19 ( F_129 ( V_71 ) < 0 ) ;
F_77 ( V_117 -> V_61 , V_75 , - V_51 ) ;
F_19 ( ! F_99 ( V_71 ) ) ;
F_70 ( & V_117 -> V_61 -> V_62 ) ;
F_141 ( V_117 , V_71 ) ;
F_71 ( V_117 -> V_61 , V_59 ) ;
V_34 = 1 ;
}
} else
F_70 ( & V_117 -> V_61 -> V_62 ) ;
return V_34 ;
}
int F_142 ( struct V_66 * V_67 , T_5 * V_65 ,
unsigned long V_96 , unsigned long V_118 ,
unsigned char * V_119 )
{
int V_34 = 0 ;
F_68 ( & V_67 -> V_120 -> V_62 ) ;
if ( F_59 ( F_91 ( * V_65 ) ) ) {
V_34 = ! F_96 ( * V_65 ) ;
F_70 ( & V_67 -> V_120 -> V_62 ) ;
if ( F_9 ( ! V_34 ) )
F_97 ( V_67 -> V_101 , V_65 ) ;
else {
memset ( V_119 , 1 , ( V_118 - V_96 ) >> V_10 ) ;
}
} else
F_70 ( & V_67 -> V_120 -> V_62 ) ;
return V_34 ;
}
int F_143 ( struct V_66 * V_67 , struct V_66 * V_121 ,
unsigned long V_122 ,
unsigned long V_123 , unsigned long V_124 ,
T_5 * V_125 , T_5 * V_126 )
{
int V_34 = 0 ;
T_5 V_65 ;
struct V_60 * V_61 = V_67 -> V_120 ;
if ( ( V_122 & ~ V_84 ) ||
( V_123 & ~ V_84 ) ||
V_124 - V_122 < V_87 ||
( V_121 -> V_68 & V_127 ) )
goto V_16;
if ( F_144 ( ! F_69 ( * V_126 ) ) ) {
F_19 ( F_91 ( * V_126 ) ) ;
goto V_16;
}
F_68 ( & V_61 -> V_62 ) ;
if ( F_59 ( F_91 ( * V_125 ) ) ) {
if ( F_96 ( * V_125 ) ) {
F_70 ( & V_61 -> V_62 ) ;
F_97 ( V_67 -> V_101 , V_125 ) ;
V_34 = - 1 ;
} else {
V_65 = F_145 ( V_61 , V_122 , V_125 ) ;
F_19 ( ! F_69 ( * V_126 ) ) ;
F_76 ( V_61 , V_123 , V_126 , V_65 ) ;
F_70 ( & V_61 -> V_62 ) ;
V_34 = 1 ;
}
} else {
F_70 ( & V_61 -> V_62 ) ;
}
V_16:
return V_34 ;
}
int F_146 ( struct V_66 * V_67 , T_5 * V_65 ,
unsigned long V_96 , T_8 V_128 )
{
struct V_60 * V_61 = V_67 -> V_120 ;
int V_34 = 0 ;
F_68 ( & V_61 -> V_62 ) ;
if ( F_59 ( F_91 ( * V_65 ) ) ) {
if ( F_9 ( F_96 ( * V_65 ) ) ) {
F_70 ( & V_61 -> V_62 ) ;
F_97 ( V_67 -> V_101 , V_65 ) ;
} else {
T_5 V_73 ;
V_73 = F_145 ( V_61 , V_96 , V_65 ) ;
V_73 = F_147 ( V_73 , V_128 ) ;
F_76 ( V_61 , V_96 , V_65 , V_73 ) ;
F_70 ( & V_67 -> V_120 -> V_62 ) ;
F_148 ( V_67 , V_96 , V_96 + V_87 ) ;
V_34 = 1 ;
}
} else
F_70 ( & V_67 -> V_120 -> V_62 ) ;
return V_34 ;
}
T_5 * F_149 ( struct V_71 * V_71 ,
struct V_60 * V_61 ,
unsigned long V_82 ,
enum V_129 V_35 )
{
T_9 * V_130 ;
T_10 * V_131 ;
T_5 * V_65 , * V_34 = NULL ;
if ( V_82 & ~ V_84 )
goto V_16;
V_130 = F_150 ( V_61 , V_82 ) ;
if ( ! F_151 ( * V_130 ) )
goto V_16;
V_131 = F_152 ( V_130 , V_82 ) ;
if ( ! F_153 ( * V_131 ) )
goto V_16;
V_65 = F_154 ( V_131 , V_82 ) ;
if ( F_69 ( * V_65 ) )
goto V_16;
if ( F_98 ( * V_65 ) != V_71 )
goto V_16;
if ( V_35 == V_132 &&
F_96 ( * V_65 ) )
goto V_16;
if ( F_91 ( * V_65 ) ) {
F_19 ( V_35 == V_133 &&
! F_96 ( * V_65 ) ) ;
V_34 = V_65 ;
}
V_16:
return V_34 ;
}
static int F_155 ( struct V_71 * V_71 ,
struct V_66 * V_67 ,
unsigned long V_82 )
{
struct V_60 * V_61 = V_67 -> V_120 ;
T_5 * V_65 ;
int V_34 = 0 ;
F_68 ( & V_61 -> V_62 ) ;
V_65 = F_149 ( V_71 , V_61 , V_82 ,
V_132 ) ;
if ( V_65 ) {
F_156 ( V_67 , V_82 , V_65 ) ;
V_34 = 1 ;
}
F_70 ( & V_61 -> V_62 ) ;
return V_34 ;
}
static void F_157 ( struct V_71 * V_71 )
{
int V_105 ;
unsigned long V_134 = V_71 -> V_135 ;
struct V_1 * V_1 = F_158 ( V_71 ) ;
int V_136 ;
int V_137 = 0 ;
F_159 ( & V_1 -> V_138 ) ;
F_160 ( V_71 ) ;
for ( V_105 = 1 ; V_105 < V_51 ; V_105 ++ ) {
struct V_71 * V_139 = V_71 + V_105 ;
F_161 ( F_129 ( V_139 ) < 0 ) ;
V_137 += F_129 ( V_139 ) ;
F_161 ( V_137 < 0 ) ;
F_161 ( F_162 ( & V_139 -> V_140 ) != 0 ) ;
F_163 ( F_129 ( V_71 ) + F_129 ( V_139 ) + 1 ,
& V_139 -> V_140 ) ;
F_164 () ;
V_139 -> V_83 &= ~ V_141 | V_142 ;
V_139 -> V_83 |= ( V_71 -> V_83 &
( ( 1L << V_143 ) |
( 1L << V_144 ) |
( 1L << V_145 ) |
( 1L << V_146 ) ) ) ;
V_139 -> V_83 |= ( 1L << V_147 ) ;
F_126 () ;
V_139 -> V_148 = V_71 -> V_148 ;
F_161 ( V_139 -> V_149 ) ;
V_139 -> V_149 = V_71 -> V_149 ;
V_139 -> V_135 = ++ V_134 ;
F_161 ( ! F_165 ( V_139 ) ) ;
F_161 ( ! F_166 ( V_139 ) ) ;
F_161 ( ! F_167 ( V_139 ) ) ;
F_161 ( ! F_168 ( V_139 ) ) ;
F_169 ( V_71 , V_139 ) ;
F_170 ( V_1 , V_71 , V_139 ) ;
}
F_171 ( V_137 , & V_71 -> V_140 ) ;
F_161 ( F_162 ( & V_71 -> V_140 ) <= 0 ) ;
F_172 ( V_71 , V_150 ) ;
F_173 ( V_1 , V_151 , V_51 ) ;
if ( F_174 ( V_71 ) ) {
V_136 = V_152 + F_175 ( V_71 ) ;
F_173 ( V_1 , V_136 , - ( V_51 - 1 ) ) ;
}
F_176 ( V_71 ) ;
F_177 ( V_71 ) ;
F_178 ( & V_1 -> V_138 ) ;
for ( V_105 = 1 ; V_105 < V_51 ; V_105 ++ ) {
struct V_71 * V_139 = V_71 + V_105 ;
F_161 ( F_179 ( V_139 ) <= 0 ) ;
F_65 ( V_139 ) ;
}
F_161 ( F_179 ( V_71 ) <= 0 ) ;
}
static int F_180 ( struct V_71 * V_71 ,
struct V_66 * V_67 ,
unsigned long V_82 )
{
struct V_60 * V_61 = V_67 -> V_120 ;
T_5 * V_65 , V_104 ;
int V_34 = 0 , V_105 ;
T_4 V_59 ;
unsigned long V_70 ;
F_68 ( & V_61 -> V_62 ) ;
V_65 = F_149 ( V_71 , V_61 , V_82 ,
V_133 ) ;
if ( V_65 ) {
V_59 = F_105 ( V_61 ) ;
F_119 ( V_61 , & V_104 , V_59 ) ;
for ( V_105 = 0 , V_70 = V_82 ; V_105 < V_51 ;
V_105 ++ , V_70 += V_108 ) {
T_7 * V_85 , V_73 ;
F_161 ( F_62 ( V_71 + V_105 ) ) ;
V_73 = F_120 ( V_71 + V_105 , V_67 -> V_74 ) ;
V_73 = F_121 ( F_122 ( V_73 ) , V_67 ) ;
if ( ! F_137 ( * V_65 ) )
V_73 = F_181 ( V_73 ) ;
else
F_161 ( F_129 ( V_71 ) != 1 ) ;
if ( ! F_182 ( * V_65 ) )
V_73 = F_183 ( V_73 ) ;
V_85 = F_92 ( & V_104 , V_70 ) ;
F_161 ( ! F_123 ( * V_85 ) ) ;
F_124 ( V_61 , V_70 , V_85 , V_73 ) ;
F_125 ( V_85 ) ;
}
V_61 -> V_110 ++ ;
F_126 () ;
F_76 ( V_61 , V_82 , V_65 , F_184 ( * V_65 ) ) ;
F_148 ( V_67 , V_82 , V_82 + V_87 ) ;
F_119 ( V_61 , V_65 , V_59 ) ;
V_34 = 1 ;
}
F_70 ( & V_61 -> V_62 ) ;
return V_34 ;
}
static void F_185 ( struct V_71 * V_71 ,
struct V_101 * V_101 )
{
int V_153 , V_154 ;
struct V_155 * V_156 ;
F_161 ( ! F_99 ( V_71 ) ) ;
F_161 ( F_186 ( V_71 ) ) ;
V_153 = 0 ;
F_187 (avc, &anon_vma->head, same_anon_vma) {
struct V_66 * V_67 = V_156 -> V_67 ;
unsigned long V_96 = F_188 ( V_71 , V_67 ) ;
F_161 ( F_189 ( V_67 ) ) ;
if ( V_96 == - V_157 )
continue;
V_153 += F_155 ( V_71 , V_67 , V_96 ) ;
}
if ( V_153 != F_129 ( V_71 ) )
F_13 ( V_20 L_15 ,
V_153 , F_129 ( V_71 ) ) ;
F_161 ( V_153 != F_129 ( V_71 ) ) ;
F_157 ( V_71 ) ;
V_154 = 0 ;
F_187 (avc, &anon_vma->head, same_anon_vma) {
struct V_66 * V_67 = V_156 -> V_67 ;
unsigned long V_96 = F_188 ( V_71 , V_67 ) ;
F_161 ( F_189 ( V_67 ) ) ;
if ( V_96 == - V_157 )
continue;
V_154 += F_180 ( V_71 , V_67 , V_96 ) ;
}
if ( V_153 != V_154 )
F_13 ( V_20 L_16 ,
V_153 , V_154 , F_129 ( V_71 ) ) ;
F_161 ( V_153 != V_154 ) ;
}
int F_190 ( struct V_71 * V_71 )
{
struct V_101 * V_101 ;
int V_34 = 1 ;
F_161 ( ! F_165 ( V_71 ) ) ;
V_101 = F_191 ( V_71 ) ;
if ( ! V_101 )
goto V_16;
V_34 = 0 ;
if ( ! F_62 ( V_71 ) )
goto V_100;
F_161 ( ! F_168 ( V_71 ) ) ;
F_185 ( V_71 , V_101 ) ;
F_88 ( V_158 ) ;
F_161 ( F_62 ( V_71 ) ) ;
V_100:
F_192 ( V_101 ) ;
V_16:
return V_34 ;
}
int F_193 ( struct V_66 * V_67 ,
unsigned long * V_68 , int V_159 )
{
switch ( V_159 ) {
case V_160 :
if ( * V_68 & ( V_161 | V_162 ) )
return - V_33 ;
* V_68 &= ~ V_127 ;
* V_68 |= V_161 ;
if ( F_9 ( F_194 ( V_67 ) ) )
return - V_15 ;
break;
case V_163 :
if ( * V_68 & ( V_127 | V_162 ) )
return - V_33 ;
* V_68 &= ~ V_161 ;
* V_68 |= V_127 ;
break;
}
return 0 ;
}
static int T_3 F_50 ( void )
{
V_13 = F_195 ( L_17 ,
sizeof( struct V_164 ) ,
F_196 ( struct V_164 ) , 0 , NULL ) ;
if ( ! V_13 )
return - V_15 ;
return 0 ;
}
static void T_3 F_52 ( void )
{
F_197 ( V_13 ) ;
V_13 = NULL ;
}
static inline struct V_164 * F_198 ( void )
{
if ( ! V_13 )
return NULL ;
return F_199 ( V_13 , V_91 ) ;
}
static inline void F_200 ( struct V_164 * V_164 )
{
F_201 ( V_13 , V_164 ) ;
}
static int T_3 F_51 ( void )
{
V_14 = F_202 ( V_165 * sizeof( struct V_166 ) ,
V_91 ) ;
if ( ! V_14 )
return - V_15 ;
return 0 ;
}
static struct V_164 * F_203 ( struct V_60 * V_61 )
{
struct V_164 * V_164 ;
struct V_166 * V_167 ;
struct V_168 * V_169 ;
V_167 = & V_14 [ ( ( unsigned long ) V_61 / sizeof( struct V_60 ) )
% V_165 ] ;
F_204 (mm_slot, node, bucket, hash) {
if ( V_61 == V_164 -> V_61 )
return V_164 ;
}
return NULL ;
}
static void F_205 ( struct V_60 * V_61 ,
struct V_164 * V_164 )
{
struct V_166 * V_167 ;
V_167 = & V_14 [ ( ( unsigned long ) V_61 / sizeof( struct V_60 ) )
% V_165 ] ;
V_164 -> V_61 = V_61 ;
F_206 ( & V_164 -> V_170 , V_167 ) ;
}
static inline int F_207 ( struct V_60 * V_61 )
{
return F_162 ( & V_61 -> V_171 ) == 0 ;
}
int F_208 ( struct V_60 * V_61 )
{
struct V_164 * V_164 ;
int V_12 ;
V_164 = F_198 () ;
if ( ! V_164 )
return - V_15 ;
F_19 ( F_207 ( V_61 ) ) ;
if ( F_9 ( F_209 ( V_172 , & V_61 -> V_83 ) ) ) {
F_200 ( V_164 ) ;
return 0 ;
}
F_68 ( & V_173 ) ;
F_205 ( V_61 , V_164 ) ;
V_12 = F_15 ( & V_21 . V_22 ) ;
F_210 ( & V_164 -> V_174 , & V_21 . V_22 ) ;
F_70 ( & V_173 ) ;
F_211 ( & V_61 -> V_175 ) ;
if ( V_12 )
F_17 ( & V_23 ) ;
return 0 ;
}
int F_194 ( struct V_66 * V_67 )
{
unsigned long V_176 , V_177 ;
if ( ! V_67 -> V_101 )
return 0 ;
if ( V_67 -> V_178 )
return 0 ;
F_19 ( F_212 ( V_67 ) || V_67 -> V_68 & V_162 ) ;
V_176 = ( V_67 -> V_86 + ~ V_84 ) & V_84 ;
V_177 = V_67 -> V_88 & V_84 ;
if ( V_176 < V_177 )
return F_85 ( V_67 ) ;
return 0 ;
}
void F_213 ( struct V_60 * V_61 )
{
struct V_164 * V_164 ;
int free = 0 ;
F_68 ( & V_173 ) ;
V_164 = F_203 ( V_61 ) ;
if ( V_164 && V_21 . V_164 != V_164 ) {
F_214 ( & V_164 -> V_170 ) ;
F_107 ( & V_164 -> V_174 ) ;
free = 1 ;
}
F_70 ( & V_173 ) ;
if ( free ) {
F_22 ( V_172 , & V_61 -> V_83 ) ;
F_200 ( V_164 ) ;
F_215 ( V_61 ) ;
} else if ( V_164 ) {
F_216 ( & V_61 -> V_179 ) ;
F_217 ( & V_61 -> V_179 ) ;
}
}
static void F_218 ( struct V_71 * V_71 )
{
F_219 ( V_71 , V_180 + 0 ) ;
F_220 ( V_71 ) ;
F_221 ( V_71 ) ;
}
static void F_222 ( T_7 * V_85 , T_7 * V_181 )
{
while ( -- V_181 >= V_85 ) {
T_7 V_182 = * V_181 ;
if ( ! F_123 ( V_182 ) )
F_218 ( F_223 ( V_182 ) ) ;
}
}
static void F_224 ( T_7 * V_85 )
{
F_222 ( V_85 , V_85 + V_51 ) ;
}
static int F_225 ( struct V_66 * V_67 ,
unsigned long V_82 ,
T_7 * V_85 )
{
struct V_71 * V_71 ;
T_7 * V_181 ;
int V_183 = 0 , V_184 = 0 , V_185 = 0 ;
for ( V_181 = V_85 ; V_181 < V_85 + V_51 ;
V_181 ++ , V_82 += V_108 ) {
T_7 V_182 = * V_181 ;
if ( F_123 ( V_182 ) ) {
if ( ++ V_185 <= V_49 )
continue;
else {
F_222 ( V_85 , V_181 ) ;
goto V_16;
}
}
if ( ! F_226 ( V_182 ) || ! F_227 ( V_182 ) ) {
F_222 ( V_85 , V_181 ) ;
goto V_16;
}
V_71 = F_228 ( V_67 , V_82 , V_182 ) ;
if ( F_9 ( ! V_71 ) ) {
F_222 ( V_85 , V_181 ) ;
goto V_16;
}
F_19 ( F_62 ( V_71 ) ) ;
F_161 ( ! F_165 ( V_71 ) ) ;
F_19 ( ! F_168 ( V_71 ) ) ;
if ( F_179 ( V_71 ) != 1 ) {
F_222 ( V_85 , V_181 ) ;
goto V_16;
}
if ( ! F_229 ( V_71 ) ) {
F_222 ( V_85 , V_181 ) ;
goto V_16;
}
if ( F_230 ( V_71 ) ) {
F_220 ( V_71 ) ;
F_222 ( V_85 , V_181 ) ;
goto V_16;
}
F_231 ( V_71 , V_180 + 0 ) ;
F_19 ( ! F_232 ( V_71 ) ) ;
F_19 ( F_174 ( V_71 ) ) ;
if ( F_233 ( V_182 ) || F_234 ( V_71 ) ||
F_235 ( V_67 -> V_120 , V_82 ) )
V_183 = 1 ;
}
if ( F_9 ( ! V_183 ) )
F_224 ( V_85 ) ;
else
V_184 = 1 ;
V_16:
return V_184 ;
}
static void F_236 ( T_7 * V_85 , struct V_71 * V_71 ,
struct V_66 * V_67 ,
unsigned long V_82 ,
T_11 * V_186 )
{
T_7 * V_181 ;
for ( V_181 = V_85 ; V_181 < V_85 + V_51 ; V_181 ++ ) {
T_7 V_182 = * V_181 ;
struct V_71 * V_97 ;
if ( F_123 ( V_182 ) ) {
F_237 ( V_71 , V_82 ) ;
F_77 ( V_67 -> V_120 , V_75 , 1 ) ;
} else {
V_97 = F_223 ( V_182 ) ;
F_115 ( V_71 , V_97 , V_82 , V_67 ) ;
F_19 ( F_129 ( V_97 ) != 1 ) ;
F_19 ( F_179 ( V_97 ) != 2 ) ;
F_218 ( V_97 ) ;
F_68 ( V_186 ) ;
F_238 ( V_67 -> V_120 , V_82 , V_181 ) ;
F_127 ( V_97 ) ;
F_70 ( V_186 ) ;
F_239 ( V_97 ) ;
}
V_82 += V_108 ;
V_71 ++ ;
}
}
static void F_240 ( struct V_60 * V_61 ,
unsigned long V_82 ,
struct V_71 * * V_187 ,
struct V_66 * V_67 ,
int V_169 )
{
T_9 * V_130 ;
T_10 * V_131 ;
T_5 * V_65 , V_104 ;
T_7 * V_85 ;
T_4 V_59 ;
struct V_71 * V_112 ;
T_11 * V_186 ;
int V_184 ;
unsigned long V_176 , V_177 ;
F_19 ( V_82 & ~ V_84 ) ;
#ifndef F_241
F_242 ( & V_61 -> V_179 ) ;
F_19 ( ! * V_187 ) ;
V_112 = * V_187 ;
#else
F_19 ( * V_187 ) ;
V_112 = F_79 ( F_243 () , V_67 , V_82 ,
V_169 , V_107 ) ;
F_242 ( & V_61 -> V_179 ) ;
if ( F_9 ( ! V_112 ) ) {
F_88 ( V_188 ) ;
* V_187 = F_244 ( - V_15 ) ;
return;
}
#endif
F_88 ( V_189 ) ;
if ( F_9 ( F_89 ( V_112 , V_61 , V_91 ) ) ) {
#ifdef F_241
F_65 ( V_112 ) ;
#endif
return;
}
F_216 ( & V_61 -> V_179 ) ;
if ( F_9 ( F_207 ( V_61 ) ) )
goto V_16;
V_67 = F_245 ( V_61 , V_82 ) ;
V_176 = ( V_67 -> V_86 + ~ V_84 ) & V_84 ;
V_177 = V_67 -> V_88 & V_84 ;
if ( V_82 < V_176 || V_82 + V_87 > V_177 )
goto V_16;
if ( ( ! ( V_67 -> V_68 & V_161 ) && ! F_246 () ) ||
( V_67 -> V_68 & V_127 ) )
goto V_16;
if ( ! V_67 -> V_101 || V_67 -> V_178 )
goto V_16;
if ( F_189 ( V_67 ) )
goto V_16;
F_19 ( F_212 ( V_67 ) || V_67 -> V_68 & V_162 ) ;
V_130 = F_150 ( V_61 , V_82 ) ;
if ( ! F_151 ( * V_130 ) )
goto V_16;
V_131 = F_152 ( V_130 , V_82 ) ;
if ( ! F_153 ( * V_131 ) )
goto V_16;
V_65 = F_154 ( V_131 , V_82 ) ;
if ( ! F_247 ( * V_65 ) || F_91 ( * V_65 ) )
goto V_16;
F_248 ( V_67 -> V_101 ) ;
V_85 = F_92 ( V_65 , V_82 ) ;
V_186 = F_249 ( V_61 , V_65 ) ;
F_68 ( & V_61 -> V_62 ) ;
V_104 = F_118 ( V_67 , V_82 , V_65 ) ;
F_70 ( & V_61 -> V_62 ) ;
F_68 ( V_186 ) ;
V_184 = F_225 ( V_67 , V_82 , V_85 ) ;
F_70 ( V_186 ) ;
if ( F_9 ( ! V_184 ) ) {
F_125 ( V_85 ) ;
F_68 ( & V_61 -> V_62 ) ;
F_161 ( ! F_69 ( * V_65 ) ) ;
F_76 ( V_61 , V_82 , V_65 , V_104 ) ;
F_70 ( & V_61 -> V_62 ) ;
F_250 ( V_67 -> V_101 ) ;
goto V_16;
}
F_250 ( V_67 -> V_101 ) ;
F_236 ( V_85 , V_112 , V_67 , V_82 , V_186 ) ;
F_125 ( V_85 ) ;
F_67 ( V_112 ) ;
V_59 = F_251 ( V_104 ) ;
F_19 ( F_179 ( V_59 ) != 1 ) ;
F_19 ( F_129 ( V_59 ) != 0 ) ;
V_104 = F_72 ( V_112 , V_67 -> V_74 ) ;
V_104 = F_58 ( F_73 ( V_104 ) , V_67 ) ;
V_104 = F_74 ( V_104 ) ;
F_126 () ;
F_68 ( & V_61 -> V_62 ) ;
F_161 ( ! F_69 ( * V_65 ) ) ;
F_75 ( V_112 , V_67 , V_82 ) ;
F_76 ( V_61 , V_82 , V_65 , V_104 ) ;
F_132 ( V_67 , V_82 , V_104 ) ;
F_54 ( V_59 , V_61 ) ;
V_61 -> V_110 -- ;
F_70 ( & V_61 -> V_62 ) ;
#ifndef F_241
* V_187 = NULL ;
#endif
V_46 ++ ;
V_190:
F_217 ( & V_61 -> V_179 ) ;
return;
V_16:
F_64 ( V_112 ) ;
#ifdef F_241
F_65 ( V_112 ) ;
#endif
goto V_190;
}
static int F_252 ( struct V_60 * V_61 ,
struct V_66 * V_67 ,
unsigned long V_82 ,
struct V_71 * * V_187 )
{
T_9 * V_130 ;
T_10 * V_131 ;
T_5 * V_65 ;
T_7 * V_85 , * V_181 ;
int V_34 = 0 , V_183 = 0 , V_185 = 0 ;
struct V_71 * V_71 ;
unsigned long V_191 ;
T_11 * V_186 ;
int V_169 = - 1 ;
F_19 ( V_82 & ~ V_84 ) ;
V_130 = F_150 ( V_61 , V_82 ) ;
if ( ! F_151 ( * V_130 ) )
goto V_16;
V_131 = F_152 ( V_130 , V_82 ) ;
if ( ! F_153 ( * V_131 ) )
goto V_16;
V_65 = F_154 ( V_131 , V_82 ) ;
if ( ! F_247 ( * V_65 ) || F_91 ( * V_65 ) )
goto V_16;
V_85 = F_253 ( V_61 , V_65 , V_82 , & V_186 ) ;
for ( V_191 = V_82 , V_181 = V_85 ; V_181 < V_85 + V_51 ;
V_181 ++ , V_191 += V_108 ) {
T_7 V_182 = * V_181 ;
if ( F_123 ( V_182 ) ) {
if ( ++ V_185 <= V_49 )
continue;
else
goto V_192;
}
if ( ! F_226 ( V_182 ) || ! F_227 ( V_182 ) )
goto V_192;
V_71 = F_228 ( V_67 , V_191 , V_182 ) ;
if ( F_9 ( ! V_71 ) )
goto V_192;
if ( V_169 == - 1 )
V_169 = F_111 ( V_71 ) ;
F_19 ( F_62 ( V_71 ) ) ;
if ( ! F_174 ( V_71 ) || F_232 ( V_71 ) || ! F_165 ( V_71 ) )
goto V_192;
if ( F_179 ( V_71 ) != 1 )
goto V_192;
if ( F_233 ( V_182 ) || F_234 ( V_71 ) ||
F_235 ( V_67 -> V_120 , V_82 ) )
V_183 = 1 ;
}
if ( V_183 )
V_34 = 1 ;
V_192:
F_254 ( V_85 , V_186 ) ;
if ( V_34 )
F_240 ( V_61 , V_82 , V_187 , V_67 , V_169 ) ;
V_16:
return V_34 ;
}
static void F_255 ( struct V_164 * V_164 )
{
struct V_60 * V_61 = V_164 -> V_61 ;
F_19 ( ! F_256 ( & V_173 ) ) ;
if ( F_207 ( V_61 ) ) {
F_214 ( & V_164 -> V_170 ) ;
F_107 ( & V_164 -> V_174 ) ;
F_200 ( V_164 ) ;
F_215 ( V_61 ) ;
}
}
static unsigned int F_257 ( unsigned int V_45 ,
struct V_71 * * V_187 )
__releases( &khugepaged_mm_lock
static int F_258 ( void )
{
return ! F_15 ( & V_21 . V_22 ) &&
F_8 () ;
}
static int F_259 ( void )
{
return ! F_15 ( & V_21 . V_22 ) ||
! F_8 () ;
}
static void F_260 ( struct V_71 * * V_187 )
{
unsigned int V_193 = 0 , V_194 = 0 ;
unsigned int V_45 = V_44 ;
F_261 () ;
while ( V_193 < V_45 ) {
F_116 () ;
#ifndef F_241
if ( ! * V_187 ) {
* V_187 = F_81 ( F_243 () ) ;
if ( F_9 ( ! * V_187 ) ) {
F_88 ( V_188 ) ;
break;
}
F_88 ( V_189 ) ;
}
#else
if ( F_12 ( * V_187 ) )
break;
#endif
if ( F_9 ( F_262 () || F_263 ( V_195 ) ) )
break;
F_68 ( & V_173 ) ;
if ( ! V_21 . V_164 )
V_194 ++ ;
if ( F_258 () &&
V_194 < 2 )
V_193 += F_257 ( V_45 - V_193 ,
V_187 ) ;
else
V_193 = V_45 ;
F_70 ( & V_173 ) ;
}
}
static void F_264 ( void )
{
F_265 ( V_23 , false ,
F_266 ( V_43 ) ) ;
}
static struct V_71 * F_267 ( void )
{
struct V_71 * V_187 ;
do {
V_187 = F_81 ( F_243 () ) ;
if ( ! V_187 ) {
F_88 ( V_188 ) ;
F_264 () ;
} else
F_88 ( V_189 ) ;
} while ( F_9 ( ! V_187 ) &&
F_59 ( F_8 () ) );
return V_187 ;
}
static void F_268 ( void )
{
struct V_71 * V_187 ;
#ifdef F_241
V_187 = NULL ;
#endif
while ( F_59 ( F_8 () ) ) {
#ifndef F_241
V_187 = F_267 () ;
if ( F_9 ( ! V_187 ) )
break;
#else
if ( F_12 ( V_187 ) ) {
F_264 () ;
V_187 = NULL ;
}
#endif
F_260 ( & V_187 ) ;
#ifndef F_241
if ( V_187 )
F_65 ( V_187 ) ;
#endif
F_269 () ;
if ( F_9 ( F_262 () ) )
break;
if ( F_258 () ) {
if ( ! V_40 )
continue;
F_265 ( V_23 , false ,
F_266 ( V_40 ) ) ;
} else if ( F_8 () )
F_270 ( V_23 ,
F_259 () ) ;
}
}
static int V_19 ( void * V_185 )
{
struct V_164 * V_164 ;
F_271 () ;
F_272 ( V_195 , 19 ) ;
F_10 ( & V_17 ) ;
for (; ; ) {
F_16 ( & V_17 ) ;
F_19 ( V_18 != V_195 ) ;
F_268 () ;
F_19 ( V_18 != V_195 ) ;
F_10 ( & V_17 ) ;
if ( ! F_8 () )
break;
if ( F_9 ( F_262 () ) )
break;
}
F_68 ( & V_173 ) ;
V_164 = V_21 . V_164 ;
V_21 . V_164 = NULL ;
if ( V_164 )
F_255 ( V_164 ) ;
F_70 ( & V_173 ) ;
V_18 = NULL ;
F_16 ( & V_17 ) ;
return 0 ;
}
void F_273 ( struct V_60 * V_61 , T_5 * V_65 )
{
struct V_71 * V_71 ;
F_68 ( & V_61 -> V_62 ) ;
if ( F_9 ( ! F_91 ( * V_65 ) ) ) {
F_70 ( & V_61 -> V_62 ) ;
return;
}
V_71 = F_98 ( * V_65 ) ;
F_19 ( ! F_179 ( V_71 ) ) ;
F_100 ( V_71 ) ;
F_70 ( & V_61 -> V_62 ) ;
F_190 ( V_71 ) ;
F_65 ( V_71 ) ;
F_161 ( F_91 ( * V_65 ) ) ;
}
static void F_274 ( struct V_60 * V_61 ,
unsigned long V_82 )
{
T_9 * V_130 ;
T_10 * V_131 ;
T_5 * V_65 ;
F_19 ( ! ( V_82 & ~ V_84 ) ) ;
V_130 = F_150 ( V_61 , V_82 ) ;
if ( ! F_151 ( * V_130 ) )
return;
V_131 = F_152 ( V_130 , V_82 ) ;
if ( ! F_153 ( * V_131 ) )
return;
V_65 = F_154 ( V_131 , V_82 ) ;
if ( ! F_247 ( * V_65 ) )
return;
F_275 ( V_61 , V_65 ) ;
}
void F_276 ( struct V_66 * V_67 ,
unsigned long V_196 ,
unsigned long V_118 ,
long V_197 )
{
if ( V_196 & ~ V_84 &&
( V_196 & V_84 ) >= V_67 -> V_86 &&
( V_196 & V_84 ) + V_87 <= V_67 -> V_88 )
F_274 ( V_67 -> V_120 , V_196 ) ;
if ( V_118 & ~ V_84 &&
( V_118 & V_84 ) >= V_67 -> V_86 &&
( V_118 & V_84 ) + V_87 <= V_67 -> V_88 )
F_274 ( V_67 -> V_120 , V_118 ) ;
if ( V_197 > 0 ) {
struct V_66 * V_102 = V_67 -> V_198 ;
unsigned long V_199 = V_102 -> V_86 ;
V_199 += V_197 << V_10 ;
if ( V_199 & ~ V_84 &&
( V_199 & V_84 ) >= V_102 -> V_86 &&
( V_199 & V_84 ) + V_87 <= V_102 -> V_88 )
F_274 ( V_102 -> V_120 , V_199 ) ;
}
}
