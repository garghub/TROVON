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
V_70 + V_10 * V_105 , V_67 ) ;
F_67 ( V_45 [ V_105 ] ) ;
F_116 () ;
}
F_68 ( & V_61 -> V_62 ) ;
if ( F_9 ( ! F_117 ( * V_65 , V_103 ) ) )
goto V_108;
F_19 ( ! F_99 ( V_71 ) ) ;
F_118 ( V_67 , V_70 , V_65 ) ;
V_59 = F_105 ( V_61 ) ;
F_119 ( V_61 , & V_104 , V_59 ) ;
for ( V_105 = 0 ; V_105 < V_51 ; V_105 ++ , V_70 += V_109 ) {
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
V_108:
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
F_100 ( V_71 ) ;
V_16:
return V_71 ;
}
int F_138 ( struct V_116 * V_117 , struct V_66 * V_67 ,
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
F_139 ( V_65 ) ;
F_127 ( V_71 ) ;
F_19 ( F_129 ( V_71 ) < 0 ) ;
F_77 ( V_117 -> V_61 , V_75 , - V_51 ) ;
F_19 ( ! F_99 ( V_71 ) ) ;
F_70 ( & V_117 -> V_61 -> V_62 ) ;
F_140 ( V_117 , V_71 ) ;
F_71 ( V_117 -> V_61 , V_59 ) ;
V_34 = 1 ;
}
} else
F_70 ( & V_117 -> V_61 -> V_62 ) ;
return V_34 ;
}
int F_141 ( struct V_66 * V_67 , T_5 * V_65 ,
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
int F_142 ( struct V_66 * V_67 , T_5 * V_65 ,
unsigned long V_96 , T_8 V_121 )
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
V_73 = F_143 ( V_61 , V_96 , V_65 ) ;
V_73 = F_144 ( V_73 , V_121 ) ;
F_76 ( V_61 , V_96 , V_65 , V_73 ) ;
F_70 ( & V_67 -> V_120 -> V_62 ) ;
F_145 ( V_67 , V_96 , V_96 + V_87 ) ;
V_34 = 1 ;
}
} else
F_70 ( & V_67 -> V_120 -> V_62 ) ;
return V_34 ;
}
T_5 * F_146 ( struct V_71 * V_71 ,
struct V_60 * V_61 ,
unsigned long V_82 ,
enum V_122 V_35 )
{
T_9 * V_123 ;
T_10 * V_124 ;
T_5 * V_65 , * V_34 = NULL ;
if ( V_82 & ~ V_84 )
goto V_16;
V_123 = F_147 ( V_61 , V_82 ) ;
if ( ! F_148 ( * V_123 ) )
goto V_16;
V_124 = F_149 ( V_123 , V_82 ) ;
if ( ! F_150 ( * V_124 ) )
goto V_16;
V_65 = F_151 ( V_124 , V_82 ) ;
if ( F_69 ( * V_65 ) )
goto V_16;
if ( F_98 ( * V_65 ) != V_71 )
goto V_16;
if ( V_35 == V_125 &&
F_96 ( * V_65 ) )
goto V_16;
if ( F_91 ( * V_65 ) ) {
F_19 ( V_35 == V_126 &&
! F_96 ( * V_65 ) ) ;
V_34 = V_65 ;
}
V_16:
return V_34 ;
}
static int F_152 ( struct V_71 * V_71 ,
struct V_66 * V_67 ,
unsigned long V_82 )
{
struct V_60 * V_61 = V_67 -> V_120 ;
T_5 * V_65 ;
int V_34 = 0 ;
F_68 ( & V_61 -> V_62 ) ;
V_65 = F_146 ( V_71 , V_61 , V_82 ,
V_125 ) ;
if ( V_65 ) {
F_153 ( V_67 , V_82 , V_65 ) ;
V_34 = 1 ;
}
F_70 ( & V_61 -> V_62 ) ;
return V_34 ;
}
static void F_154 ( struct V_71 * V_71 )
{
int V_105 ;
unsigned long V_127 = V_71 -> V_128 ;
struct V_1 * V_1 = F_155 ( V_71 ) ;
int V_129 ;
F_156 ( & V_1 -> V_130 ) ;
F_157 ( V_71 ) ;
for ( V_105 = 1 ; V_105 < V_51 ; V_105 ++ ) {
struct V_71 * V_131 = V_71 + V_105 ;
F_158 ( F_159 ( & V_131 -> V_132 ) , & V_71 -> V_132 ) ;
F_160 ( F_161 ( V_71 ) <= 0 ) ;
F_162 ( F_129 ( V_71 ) + 1 , & V_131 -> V_132 ) ;
F_160 ( F_159 ( & V_131 -> V_132 ) <= 0 ) ;
F_163 () ;
V_131 -> V_83 &= ~ V_133 | V_134 ;
V_131 -> V_83 |= ( V_71 -> V_83 &
( ( 1L << V_135 ) |
( 1L << V_136 ) |
( 1L << V_137 ) |
( 1L << V_138 ) ) ) ;
V_131 -> V_83 |= ( 1L << V_139 ) ;
F_126 () ;
F_160 ( F_129 ( V_131 ) ) ;
V_131 -> V_140 = V_71 -> V_140 ;
F_160 ( V_131 -> V_141 ) ;
V_131 -> V_141 = V_71 -> V_141 ;
V_131 -> V_128 = ++ V_127 ;
F_160 ( ! F_164 ( V_131 ) ) ;
F_160 ( ! F_165 ( V_131 ) ) ;
F_160 ( ! F_166 ( V_131 ) ) ;
F_160 ( ! F_167 ( V_131 ) ) ;
F_168 ( V_71 , V_131 ) ;
F_169 ( V_1 , V_71 , V_131 ) ;
}
F_170 ( V_71 , V_142 ) ;
F_171 ( V_1 , V_143 , V_51 ) ;
if ( F_172 ( V_71 ) ) {
V_129 = V_144 + F_173 ( V_71 ) ;
F_171 ( V_1 , V_129 , - ( V_51 - 1 ) ) ;
}
F_174 ( V_71 ) ;
F_175 ( V_71 ) ;
F_176 ( & V_1 -> V_130 ) ;
for ( V_105 = 1 ; V_105 < V_51 ; V_105 ++ ) {
struct V_71 * V_131 = V_71 + V_105 ;
F_160 ( F_161 ( V_131 ) <= 0 ) ;
F_65 ( V_131 ) ;
}
F_160 ( F_161 ( V_71 ) <= 0 ) ;
}
static int F_177 ( struct V_71 * V_71 ,
struct V_66 * V_67 ,
unsigned long V_82 )
{
struct V_60 * V_61 = V_67 -> V_120 ;
T_5 * V_65 , V_104 ;
int V_34 = 0 , V_105 ;
T_4 V_59 ;
unsigned long V_70 ;
F_68 ( & V_61 -> V_62 ) ;
V_65 = F_146 ( V_71 , V_61 , V_82 ,
V_126 ) ;
if ( V_65 ) {
V_59 = F_105 ( V_61 ) ;
F_119 ( V_61 , & V_104 , V_59 ) ;
for ( V_105 = 0 , V_70 = V_82 ; V_105 < V_51 ;
V_105 ++ , V_70 += V_109 ) {
T_7 * V_85 , V_73 ;
F_160 ( F_62 ( V_71 + V_105 ) ) ;
V_73 = F_120 ( V_71 + V_105 , V_67 -> V_74 ) ;
V_73 = F_121 ( F_122 ( V_73 ) , V_67 ) ;
if ( ! F_137 ( * V_65 ) )
V_73 = F_178 ( V_73 ) ;
else
F_160 ( F_129 ( V_71 ) != 1 ) ;
if ( ! F_179 ( * V_65 ) )
V_73 = F_180 ( V_73 ) ;
V_85 = F_92 ( & V_104 , V_70 ) ;
F_160 ( ! F_123 ( * V_85 ) ) ;
F_124 ( V_61 , V_70 , V_85 , V_73 ) ;
F_125 ( V_85 ) ;
}
V_61 -> V_110 ++ ;
F_126 () ;
F_76 ( V_61 , V_82 , V_65 , F_181 ( * V_65 ) ) ;
F_145 ( V_67 , V_82 , V_82 + V_87 ) ;
F_119 ( V_61 , V_65 , V_59 ) ;
V_34 = 1 ;
}
F_70 ( & V_61 -> V_62 ) ;
return V_34 ;
}
static void F_182 ( struct V_71 * V_71 ,
struct V_101 * V_101 )
{
int V_145 , V_146 ;
struct V_147 * V_148 ;
F_160 ( ! F_99 ( V_71 ) ) ;
F_160 ( F_183 ( V_71 ) ) ;
V_145 = 0 ;
F_184 (avc, &anon_vma->head, same_anon_vma) {
struct V_66 * V_67 = V_148 -> V_67 ;
unsigned long V_96 = F_185 ( V_71 , V_67 ) ;
F_160 ( F_186 ( V_67 ) ) ;
if ( V_96 == - V_149 )
continue;
V_145 += F_152 ( V_71 , V_67 , V_96 ) ;
}
if ( V_145 != F_129 ( V_71 ) )
F_13 ( V_20 L_15 ,
V_145 , F_129 ( V_71 ) ) ;
F_160 ( V_145 != F_129 ( V_71 ) ) ;
F_154 ( V_71 ) ;
V_146 = 0 ;
F_184 (avc, &anon_vma->head, same_anon_vma) {
struct V_66 * V_67 = V_148 -> V_67 ;
unsigned long V_96 = F_185 ( V_71 , V_67 ) ;
F_160 ( F_186 ( V_67 ) ) ;
if ( V_96 == - V_149 )
continue;
V_146 += F_177 ( V_71 , V_67 , V_96 ) ;
}
if ( V_145 != V_146 )
F_13 ( V_20 L_16 ,
V_145 , V_146 , F_129 ( V_71 ) ) ;
F_160 ( V_145 != V_146 ) ;
}
int F_187 ( struct V_71 * V_71 )
{
struct V_101 * V_101 ;
int V_34 = 1 ;
F_160 ( ! F_164 ( V_71 ) ) ;
V_101 = F_188 ( V_71 ) ;
if ( ! V_101 )
goto V_16;
V_34 = 0 ;
if ( ! F_62 ( V_71 ) )
goto V_100;
F_160 ( ! F_167 ( V_71 ) ) ;
F_182 ( V_71 , V_101 ) ;
F_88 ( V_150 ) ;
F_160 ( F_62 ( V_71 ) ) ;
V_100:
F_189 ( V_101 ) ;
V_16:
return V_34 ;
}
int F_190 ( struct V_66 * V_67 ,
unsigned long * V_68 , int V_151 )
{
switch ( V_151 ) {
case V_152 :
if ( * V_68 & ( V_153 | V_154 ) )
return - V_33 ;
* V_68 &= ~ V_155 ;
* V_68 |= V_153 ;
if ( F_9 ( F_191 ( V_67 ) ) )
return - V_15 ;
break;
case V_156 :
if ( * V_68 & ( V_155 | V_154 ) )
return - V_33 ;
* V_68 &= ~ V_153 ;
* V_68 |= V_155 ;
break;
}
return 0 ;
}
static int T_3 F_50 ( void )
{
V_13 = F_192 ( L_17 ,
sizeof( struct V_157 ) ,
F_193 ( struct V_157 ) , 0 , NULL ) ;
if ( ! V_13 )
return - V_15 ;
return 0 ;
}
static void T_3 F_52 ( void )
{
F_194 ( V_13 ) ;
V_13 = NULL ;
}
static inline struct V_157 * F_195 ( void )
{
if ( ! V_13 )
return NULL ;
return F_196 ( V_13 , V_91 ) ;
}
static inline void F_197 ( struct V_157 * V_157 )
{
F_198 ( V_13 , V_157 ) ;
}
static int T_3 F_51 ( void )
{
V_14 = F_199 ( V_158 * sizeof( struct V_159 ) ,
V_91 ) ;
if ( ! V_14 )
return - V_15 ;
return 0 ;
}
static struct V_157 * F_200 ( struct V_60 * V_61 )
{
struct V_157 * V_157 ;
struct V_159 * V_160 ;
struct V_161 * V_162 ;
V_160 = & V_14 [ ( ( unsigned long ) V_61 / sizeof( struct V_60 ) )
% V_158 ] ;
F_201 (mm_slot, node, bucket, hash) {
if ( V_61 == V_157 -> V_61 )
return V_157 ;
}
return NULL ;
}
static void F_202 ( struct V_60 * V_61 ,
struct V_157 * V_157 )
{
struct V_159 * V_160 ;
V_160 = & V_14 [ ( ( unsigned long ) V_61 / sizeof( struct V_60 ) )
% V_158 ] ;
V_157 -> V_61 = V_61 ;
F_203 ( & V_157 -> V_163 , V_160 ) ;
}
static inline int F_204 ( struct V_60 * V_61 )
{
return F_159 ( & V_61 -> V_164 ) == 0 ;
}
int F_205 ( struct V_60 * V_61 )
{
struct V_157 * V_157 ;
int V_12 ;
V_157 = F_195 () ;
if ( ! V_157 )
return - V_15 ;
F_19 ( F_204 ( V_61 ) ) ;
if ( F_9 ( F_206 ( V_165 , & V_61 -> V_83 ) ) ) {
F_197 ( V_157 ) ;
return 0 ;
}
F_68 ( & V_166 ) ;
F_202 ( V_61 , V_157 ) ;
V_12 = F_15 ( & V_21 . V_22 ) ;
F_207 ( & V_157 -> V_167 , & V_21 . V_22 ) ;
F_70 ( & V_166 ) ;
F_208 ( & V_61 -> V_168 ) ;
if ( V_12 )
F_17 ( & V_23 ) ;
return 0 ;
}
int F_191 ( struct V_66 * V_67 )
{
unsigned long V_169 , V_170 ;
if ( ! V_67 -> V_101 )
return 0 ;
if ( V_67 -> V_171 )
return 0 ;
F_19 ( F_209 ( V_67 ) || V_67 -> V_68 & V_154 ) ;
V_169 = ( V_67 -> V_86 + ~ V_84 ) & V_84 ;
V_170 = V_67 -> V_88 & V_84 ;
if ( V_169 < V_170 )
return F_85 ( V_67 ) ;
return 0 ;
}
void F_210 ( struct V_60 * V_61 )
{
struct V_157 * V_157 ;
int free = 0 ;
F_68 ( & V_166 ) ;
V_157 = F_200 ( V_61 ) ;
if ( V_157 && V_21 . V_157 != V_157 ) {
F_211 ( & V_157 -> V_163 ) ;
F_107 ( & V_157 -> V_167 ) ;
free = 1 ;
}
if ( free ) {
F_70 ( & V_166 ) ;
F_22 ( V_165 , & V_61 -> V_83 ) ;
F_197 ( V_157 ) ;
F_212 ( V_61 ) ;
} else if ( V_157 ) {
F_70 ( & V_166 ) ;
F_213 ( & V_61 -> V_172 ) ;
F_214 ( & V_61 -> V_172 ) ;
} else
F_70 ( & V_166 ) ;
}
static void F_215 ( struct V_71 * V_71 )
{
F_216 ( V_71 , V_173 + 0 ) ;
F_217 ( V_71 ) ;
F_218 ( V_71 ) ;
}
static void F_219 ( T_7 * V_85 , T_7 * V_174 )
{
while ( -- V_174 >= V_85 ) {
T_7 V_175 = * V_174 ;
if ( ! F_123 ( V_175 ) )
F_215 ( F_220 ( V_175 ) ) ;
}
}
static void F_221 ( T_7 * V_85 )
{
F_219 ( V_85 , V_85 + V_51 ) ;
}
static int F_222 ( struct V_66 * V_67 ,
unsigned long V_82 ,
T_7 * V_85 )
{
struct V_71 * V_71 ;
T_7 * V_174 ;
int V_176 = 0 , V_177 = 0 , V_178 = 0 ;
for ( V_174 = V_85 ; V_174 < V_85 + V_51 ;
V_174 ++ , V_82 += V_109 ) {
T_7 V_175 = * V_174 ;
if ( F_123 ( V_175 ) ) {
if ( ++ V_178 <= V_49 )
continue;
else {
F_219 ( V_85 , V_174 ) ;
goto V_16;
}
}
if ( ! F_223 ( V_175 ) || ! F_224 ( V_175 ) ) {
F_219 ( V_85 , V_174 ) ;
goto V_16;
}
V_71 = F_225 ( V_67 , V_82 , V_175 ) ;
if ( F_9 ( ! V_71 ) ) {
F_219 ( V_85 , V_174 ) ;
goto V_16;
}
F_19 ( F_62 ( V_71 ) ) ;
F_160 ( ! F_164 ( V_71 ) ) ;
F_19 ( ! F_167 ( V_71 ) ) ;
if ( F_161 ( V_71 ) != 1 ) {
F_219 ( V_85 , V_174 ) ;
goto V_16;
}
if ( ! F_226 ( V_71 ) ) {
F_219 ( V_85 , V_174 ) ;
goto V_16;
}
if ( F_227 ( V_71 ) ) {
F_217 ( V_71 ) ;
F_219 ( V_85 , V_174 ) ;
goto V_16;
}
F_228 ( V_71 , V_173 + 0 ) ;
F_19 ( ! F_229 ( V_71 ) ) ;
F_19 ( F_172 ( V_71 ) ) ;
if ( F_230 ( V_175 ) || F_231 ( V_71 ) ||
F_232 ( V_67 -> V_120 , V_82 ) )
V_176 = 1 ;
}
if ( F_9 ( ! V_176 ) )
F_221 ( V_85 ) ;
else
V_177 = 1 ;
V_16:
return V_177 ;
}
static void F_233 ( T_7 * V_85 , struct V_71 * V_71 ,
struct V_66 * V_67 ,
unsigned long V_82 ,
T_11 * V_179 )
{
T_7 * V_174 ;
for ( V_174 = V_85 ; V_174 < V_85 + V_51 ; V_174 ++ ) {
T_7 V_175 = * V_174 ;
struct V_71 * V_97 ;
if ( F_123 ( V_175 ) ) {
F_234 ( V_71 , V_82 ) ;
F_77 ( V_67 -> V_120 , V_75 , 1 ) ;
} else {
V_97 = F_220 ( V_175 ) ;
F_115 ( V_71 , V_97 , V_82 , V_67 ) ;
F_19 ( F_129 ( V_97 ) != 1 ) ;
F_19 ( F_161 ( V_97 ) != 2 ) ;
F_215 ( V_97 ) ;
F_68 ( V_179 ) ;
F_235 ( V_67 -> V_120 , V_82 , V_174 ) ;
F_127 ( V_97 ) ;
F_70 ( V_179 ) ;
F_236 ( V_97 ) ;
}
V_82 += V_109 ;
V_71 ++ ;
}
}
static void F_237 ( struct V_60 * V_61 ,
unsigned long V_82 ,
struct V_71 * * V_180 ,
struct V_66 * V_67 ,
int V_162 )
{
T_9 * V_123 ;
T_10 * V_124 ;
T_5 * V_65 , V_104 ;
T_7 * V_85 ;
T_4 V_59 ;
struct V_71 * V_112 ;
T_11 * V_179 ;
int V_177 ;
unsigned long V_169 , V_170 ;
F_19 ( V_82 & ~ V_84 ) ;
#ifndef F_238
F_239 ( & V_61 -> V_172 ) ;
F_19 ( ! * V_180 ) ;
V_112 = * V_180 ;
#else
F_19 ( * V_180 ) ;
V_112 = F_79 ( F_240 () , V_67 , V_82 ,
V_162 , V_107 ) ;
F_239 ( & V_61 -> V_172 ) ;
if ( F_9 ( ! V_112 ) ) {
F_88 ( V_181 ) ;
* V_180 = F_241 ( - V_15 ) ;
return;
}
#endif
F_88 ( V_182 ) ;
if ( F_9 ( F_89 ( V_112 , V_61 , V_91 ) ) ) {
#ifdef F_238
F_65 ( V_112 ) ;
#endif
return;
}
F_213 ( & V_61 -> V_172 ) ;
if ( F_9 ( F_204 ( V_61 ) ) )
goto V_16;
V_67 = F_242 ( V_61 , V_82 ) ;
V_169 = ( V_67 -> V_86 + ~ V_84 ) & V_84 ;
V_170 = V_67 -> V_88 & V_84 ;
if ( V_82 < V_169 || V_82 + V_87 > V_170 )
goto V_16;
if ( ( ! ( V_67 -> V_68 & V_153 ) && ! F_243 () ) ||
( V_67 -> V_68 & V_155 ) )
goto V_16;
if ( ! V_67 -> V_101 || V_67 -> V_171 )
goto V_16;
if ( F_186 ( V_67 ) )
goto V_16;
F_19 ( F_209 ( V_67 ) || V_67 -> V_68 & V_154 ) ;
V_123 = F_147 ( V_61 , V_82 ) ;
if ( ! F_148 ( * V_123 ) )
goto V_16;
V_124 = F_149 ( V_123 , V_82 ) ;
if ( ! F_150 ( * V_124 ) )
goto V_16;
V_65 = F_151 ( V_124 , V_82 ) ;
if ( ! F_244 ( * V_65 ) || F_91 ( * V_65 ) )
goto V_16;
F_245 ( V_67 -> V_101 ) ;
V_85 = F_92 ( V_65 , V_82 ) ;
V_179 = F_246 ( V_61 , V_65 ) ;
F_68 ( & V_61 -> V_62 ) ;
V_104 = F_118 ( V_67 , V_82 , V_65 ) ;
F_70 ( & V_61 -> V_62 ) ;
F_68 ( V_179 ) ;
V_177 = F_222 ( V_67 , V_82 , V_85 ) ;
F_70 ( V_179 ) ;
if ( F_9 ( ! V_177 ) ) {
F_125 ( V_85 ) ;
F_68 ( & V_61 -> V_62 ) ;
F_160 ( ! F_69 ( * V_65 ) ) ;
F_76 ( V_61 , V_82 , V_65 , V_104 ) ;
F_70 ( & V_61 -> V_62 ) ;
F_247 ( V_67 -> V_101 ) ;
goto V_16;
}
F_247 ( V_67 -> V_101 ) ;
F_233 ( V_85 , V_112 , V_67 , V_82 , V_179 ) ;
F_125 ( V_85 ) ;
F_67 ( V_112 ) ;
V_59 = F_248 ( V_104 ) ;
F_19 ( F_161 ( V_59 ) != 1 ) ;
F_19 ( F_129 ( V_59 ) != 0 ) ;
V_104 = F_72 ( V_112 , V_67 -> V_74 ) ;
V_104 = F_58 ( F_73 ( V_104 ) , V_67 ) ;
V_104 = F_74 ( V_104 ) ;
F_126 () ;
F_68 ( & V_61 -> V_62 ) ;
F_160 ( ! F_69 ( * V_65 ) ) ;
F_75 ( V_112 , V_67 , V_82 ) ;
F_76 ( V_61 , V_82 , V_65 , V_104 ) ;
F_132 ( V_67 , V_82 , V_73 ) ;
F_54 ( V_59 , V_61 ) ;
V_61 -> V_110 -- ;
F_70 ( & V_61 -> V_62 ) ;
#ifndef F_238
* V_180 = NULL ;
#endif
V_46 ++ ;
V_183:
F_214 ( & V_61 -> V_172 ) ;
return;
V_16:
F_64 ( V_112 ) ;
#ifdef F_238
F_65 ( V_112 ) ;
#endif
goto V_183;
}
static int F_249 ( struct V_60 * V_61 ,
struct V_66 * V_67 ,
unsigned long V_82 ,
struct V_71 * * V_180 )
{
T_9 * V_123 ;
T_10 * V_124 ;
T_5 * V_65 ;
T_7 * V_85 , * V_174 ;
int V_34 = 0 , V_176 = 0 , V_178 = 0 ;
struct V_71 * V_71 ;
unsigned long V_184 ;
T_11 * V_179 ;
int V_162 = - 1 ;
F_19 ( V_82 & ~ V_84 ) ;
V_123 = F_147 ( V_61 , V_82 ) ;
if ( ! F_148 ( * V_123 ) )
goto V_16;
V_124 = F_149 ( V_123 , V_82 ) ;
if ( ! F_150 ( * V_124 ) )
goto V_16;
V_65 = F_151 ( V_124 , V_82 ) ;
if ( ! F_244 ( * V_65 ) || F_91 ( * V_65 ) )
goto V_16;
V_85 = F_250 ( V_61 , V_65 , V_82 , & V_179 ) ;
for ( V_184 = V_82 , V_174 = V_85 ; V_174 < V_85 + V_51 ;
V_174 ++ , V_184 += V_109 ) {
T_7 V_175 = * V_174 ;
if ( F_123 ( V_175 ) ) {
if ( ++ V_178 <= V_49 )
continue;
else
goto V_185;
}
if ( ! F_223 ( V_175 ) || ! F_224 ( V_175 ) )
goto V_185;
V_71 = F_225 ( V_67 , V_184 , V_175 ) ;
if ( F_9 ( ! V_71 ) )
goto V_185;
if ( V_162 == - 1 )
V_162 = F_111 ( V_71 ) ;
F_19 ( F_62 ( V_71 ) ) ;
if ( ! F_172 ( V_71 ) || F_229 ( V_71 ) || ! F_164 ( V_71 ) )
goto V_185;
if ( F_161 ( V_71 ) != 1 )
goto V_185;
if ( F_230 ( V_175 ) || F_231 ( V_71 ) ||
F_232 ( V_67 -> V_120 , V_82 ) )
V_176 = 1 ;
}
if ( V_176 )
V_34 = 1 ;
V_185:
F_251 ( V_85 , V_179 ) ;
if ( V_34 )
F_237 ( V_61 , V_82 , V_180 , V_67 , V_162 ) ;
V_16:
return V_34 ;
}
static void F_252 ( struct V_157 * V_157 )
{
struct V_60 * V_61 = V_157 -> V_61 ;
F_19 ( ! F_253 ( & V_166 ) ) ;
if ( F_204 ( V_61 ) ) {
F_211 ( & V_157 -> V_163 ) ;
F_107 ( & V_157 -> V_167 ) ;
F_197 ( V_157 ) ;
F_212 ( V_61 ) ;
}
}
static unsigned int F_254 ( unsigned int V_45 ,
struct V_71 * * V_180 )
{
struct V_157 * V_157 ;
struct V_60 * V_61 ;
struct V_66 * V_67 ;
int V_186 = 0 ;
F_19 ( ! V_45 ) ;
F_19 ( ! F_253 ( & V_166 ) ) ;
if ( V_21 . V_157 )
V_157 = V_21 . V_157 ;
else {
V_157 = F_106 ( V_21 . V_22 . V_102 ,
struct V_157 , V_167 ) ;
V_21 . V_82 = 0 ;
V_21 . V_157 = V_157 ;
}
F_70 ( & V_166 ) ;
V_61 = V_157 -> V_61 ;
F_255 ( & V_61 -> V_172 ) ;
if ( F_9 ( F_204 ( V_61 ) ) )
V_67 = NULL ;
else
V_67 = F_242 ( V_61 , V_21 . V_82 ) ;
V_186 ++ ;
for (; V_67 ; V_67 = V_67 -> V_187 ) {
unsigned long V_169 , V_170 ;
F_116 () ;
if ( F_9 ( F_204 ( V_61 ) ) ) {
V_186 ++ ;
break;
}
if ( ( ! ( V_67 -> V_68 & V_153 ) &&
! F_243 () ) ||
( V_67 -> V_68 & V_155 ) ) {
V_188:
V_186 ++ ;
continue;
}
if ( ! V_67 -> V_101 || V_67 -> V_171 )
goto V_188;
if ( F_186 ( V_67 ) )
goto V_188;
F_19 ( F_209 ( V_67 ) ||
V_67 -> V_68 & V_154 ) ;
V_169 = ( V_67 -> V_86 + ~ V_84 ) & V_84 ;
V_170 = V_67 -> V_88 & V_84 ;
if ( V_169 >= V_170 )
goto V_188;
if ( V_21 . V_82 > V_170 )
goto V_188;
if ( V_21 . V_82 < V_169 )
V_21 . V_82 = V_169 ;
F_19 ( V_21 . V_82 & ~ V_84 ) ;
while ( V_21 . V_82 < V_170 ) {
int V_34 ;
F_116 () ;
if ( F_9 ( F_204 ( V_61 ) ) )
goto V_189;
F_19 ( V_21 . V_82 < V_169 ||
V_21 . V_82 + V_87 >
V_170 ) ;
V_34 = F_249 ( V_61 , V_67 ,
V_21 . V_82 ,
V_180 ) ;
V_21 . V_82 += V_87 ;
V_186 += V_51 ;
if ( V_34 )
goto V_190;
if ( V_186 >= V_45 )
goto V_189;
}
}
V_189:
F_239 ( & V_61 -> V_172 ) ;
V_190:
F_68 ( & V_166 ) ;
F_19 ( V_21 . V_157 != V_157 ) ;
if ( F_204 ( V_61 ) || ! V_67 ) {
if ( V_157 -> V_167 . V_102 != & V_21 . V_22 ) {
V_21 . V_157 = F_106 (
V_157 -> V_167 . V_102 ,
struct V_157 , V_167 ) ;
V_21 . V_82 = 0 ;
} else {
V_21 . V_157 = NULL ;
V_47 ++ ;
}
F_252 ( V_157 ) ;
}
return V_186 ;
}
static int F_256 ( void )
{
return ! F_15 ( & V_21 . V_22 ) &&
F_8 () ;
}
static int F_257 ( void )
{
return ! F_15 ( & V_21 . V_22 ) ||
! F_8 () ;
}
static void F_258 ( struct V_71 * * V_180 )
{
unsigned int V_186 = 0 , V_191 = 0 ;
unsigned int V_45 = V_44 ;
F_259 () ;
while ( V_186 < V_45 ) {
F_116 () ;
#ifndef F_238
if ( ! * V_180 ) {
* V_180 = F_81 ( F_240 () ) ;
if ( F_9 ( ! * V_180 ) ) {
F_88 ( V_181 ) ;
break;
}
F_88 ( V_182 ) ;
}
#else
if ( F_12 ( * V_180 ) )
break;
#endif
if ( F_9 ( F_260 () || F_261 ( V_192 ) ) )
break;
F_68 ( & V_166 ) ;
if ( ! V_21 . V_157 )
V_191 ++ ;
if ( F_256 () &&
V_191 < 2 )
V_186 += F_254 ( V_45 - V_186 ,
V_180 ) ;
else
V_186 = V_45 ;
F_70 ( & V_166 ) ;
}
}
static void F_262 ( void )
{
F_263 ( V_193 ) ;
F_264 ( & V_23 , & V_193 ) ;
F_265 (
F_266 (
V_43 ) ) ;
F_267 ( & V_23 , & V_193 ) ;
}
static struct V_71 * F_268 ( void )
{
struct V_71 * V_180 ;
do {
V_180 = F_81 ( F_240 () ) ;
if ( ! V_180 ) {
F_88 ( V_181 ) ;
F_262 () ;
} else
F_88 ( V_182 ) ;
} while ( F_9 ( ! V_180 ) &&
F_59 ( F_8 () ) );
return V_180 ;
}
static void F_269 ( void )
{
struct V_71 * V_180 ;
#ifdef F_238
V_180 = NULL ;
#endif
while ( F_59 ( F_8 () ) ) {
#ifndef F_238
V_180 = F_268 () ;
if ( F_9 ( ! V_180 ) )
break;
#else
if ( F_12 ( V_180 ) ) {
F_262 () ;
V_180 = NULL ;
}
#endif
F_258 ( & V_180 ) ;
#ifndef F_238
if ( V_180 )
F_65 ( V_180 ) ;
#endif
F_270 () ;
if ( F_9 ( F_260 () ) )
break;
if ( F_256 () ) {
F_263 ( V_193 ) ;
if ( ! V_40 )
continue;
F_264 ( & V_23 , & V_193 ) ;
F_265 (
F_266 (
V_40 ) ) ;
F_267 ( & V_23 , & V_193 ) ;
} else if ( F_8 () )
F_271 ( V_23 ,
F_257 () ) ;
}
}
static int V_19 ( void * V_178 )
{
struct V_157 * V_157 ;
F_272 () ;
F_273 ( V_192 , 19 ) ;
F_10 ( & V_17 ) ;
for (; ; ) {
F_16 ( & V_17 ) ;
F_19 ( V_18 != V_192 ) ;
F_269 () ;
F_19 ( V_18 != V_192 ) ;
F_10 ( & V_17 ) ;
if ( ! F_8 () )
break;
if ( F_9 ( F_260 () ) )
break;
}
F_68 ( & V_166 ) ;
V_157 = V_21 . V_157 ;
V_21 . V_157 = NULL ;
if ( V_157 )
F_252 ( V_157 ) ;
F_70 ( & V_166 ) ;
V_18 = NULL ;
F_16 ( & V_17 ) ;
return 0 ;
}
void F_274 ( struct V_60 * V_61 , T_5 * V_65 )
{
struct V_71 * V_71 ;
F_68 ( & V_61 -> V_62 ) ;
if ( F_9 ( ! F_91 ( * V_65 ) ) ) {
F_70 ( & V_61 -> V_62 ) ;
return;
}
V_71 = F_98 ( * V_65 ) ;
F_19 ( ! F_161 ( V_71 ) ) ;
F_100 ( V_71 ) ;
F_70 ( & V_61 -> V_62 ) ;
F_187 ( V_71 ) ;
F_65 ( V_71 ) ;
F_160 ( F_91 ( * V_65 ) ) ;
}
static void F_275 ( struct V_60 * V_61 ,
unsigned long V_82 )
{
T_9 * V_123 ;
T_10 * V_124 ;
T_5 * V_65 ;
F_19 ( ! ( V_82 & ~ V_84 ) ) ;
V_123 = F_147 ( V_61 , V_82 ) ;
if ( ! F_148 ( * V_123 ) )
return;
V_124 = F_149 ( V_123 , V_82 ) ;
if ( ! F_150 ( * V_124 ) )
return;
V_65 = F_151 ( V_124 , V_82 ) ;
if ( ! F_244 ( * V_65 ) )
return;
F_276 ( V_61 , V_65 ) ;
}
void F_277 ( struct V_66 * V_67 ,
unsigned long V_194 ,
unsigned long V_118 ,
long V_195 )
{
if ( V_194 & ~ V_84 &&
( V_194 & V_84 ) >= V_67 -> V_86 &&
( V_194 & V_84 ) + V_87 <= V_67 -> V_88 )
F_275 ( V_67 -> V_120 , V_194 ) ;
if ( V_118 & ~ V_84 &&
( V_118 & V_84 ) >= V_67 -> V_86 &&
( V_118 & V_84 ) + V_87 <= V_67 -> V_88 )
F_275 ( V_67 -> V_120 , V_118 ) ;
if ( V_195 > 0 ) {
struct V_66 * V_102 = V_67 -> V_187 ;
unsigned long V_196 = V_102 -> V_86 ;
V_196 += V_195 << V_10 ;
if ( V_196 & ~ V_84 &&
( V_196 & V_84 ) >= V_102 -> V_86 &&
( V_196 & V_84 ) + V_87 <= V_102 -> V_88 )
F_275 ( V_102 -> V_120 , V_196 ) ;
}
}
