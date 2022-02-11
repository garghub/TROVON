static inline bool F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 ;
}
static inline struct V_1 * F_2 ( struct V_3 * V_4 )
{
return (struct V_1 * ) F_3 ( V_4 ) -> V_5 ;
}
static unsigned long F_4 ( struct V_1 * V_1 , T_1 V_6 )
{
return V_1 -> V_7 [ V_6 ] . V_8 ;
}
static void F_5 ( struct V_1 * V_1 , T_1 V_6 , unsigned long V_8 )
{
V_1 -> V_7 [ V_6 ] . V_8 = V_8 ;
}
static int F_6 ( struct V_1 * V_1 , T_1 V_6 ,
enum V_9 V_10 )
{
return V_1 -> V_7 [ V_6 ] . V_11 & F_7 ( V_10 ) ;
}
static void F_8 ( struct V_1 * V_1 , T_1 V_6 ,
enum V_9 V_10 )
{
V_1 -> V_7 [ V_6 ] . V_11 |= F_7 ( V_10 ) ;
}
static void F_9 ( struct V_1 * V_1 , T_1 V_6 ,
enum V_9 V_10 )
{
V_1 -> V_7 [ V_6 ] . V_11 &= ~ F_7 ( V_10 ) ;
}
static inline void F_10 ( struct V_1 * V_1 , T_1 V_6 ,
unsigned long V_12 )
{
V_1 -> V_7 [ V_6 ] . V_12 = V_12 ;
}
static unsigned long F_11 ( struct V_1 * V_1 , T_1 V_6 )
{
return V_1 -> V_7 [ V_6 ] . V_12 ;
}
static T_2 F_12 ( struct V_1 * V_1 , T_1 V_6 )
{
return V_1 -> V_7 [ V_6 ] . V_11 & ( F_7 ( V_13 ) - 1 ) ;
}
static void F_13 ( struct V_1 * V_1 ,
T_1 V_6 , T_2 V_14 )
{
unsigned long V_15 = V_1 -> V_7 [ V_6 ] . V_11 >> V_13 ;
V_1 -> V_7 [ V_6 ] . V_11 = ( V_15 << V_13 ) | V_14 ;
}
static inline bool F_14 ( struct V_16 * V_17 )
{
return V_17 -> V_18 != V_19 ;
}
static inline bool F_14 ( struct V_16 * V_17 )
{
return false ;
}
static void F_15 ( struct V_1 * V_1 )
{
F_16 ( V_1 -> V_20 ) ;
V_1 -> V_20 -> V_21 -> V_22 -> V_23 |=
V_24 ;
}
static inline bool F_17 ( struct V_1 * V_1 ,
T_3 V_25 , unsigned int V_14 )
{
T_4 V_26 , V_27 ;
if ( F_18 ( V_25 & ( V_28 - 1 ) ) )
return false ;
if ( F_18 ( V_14 & ( V_29 - 1 ) ) )
return false ;
V_26 = V_25 + ( V_14 >> V_30 ) ;
V_27 = V_1 -> V_2 >> V_30 ;
if ( F_18 ( V_25 >= V_27 || V_26 > V_27 || V_25 > V_26 ) )
return false ;
return true ;
}
static void F_19 ( T_1 * V_6 , int * V_31 , struct V_16 * V_17 )
{
* V_6 += ( * V_31 + V_17 -> V_18 ) / V_19 ;
* V_31 = ( * V_31 + V_17 -> V_18 ) % V_19 ;
}
static inline void F_20 ( struct V_1 * V_1 ,
const unsigned long V_32 )
{
unsigned long V_33 , V_34 ;
V_33 = F_21 ( & V_1 -> V_35 . V_36 ) ;
do {
V_34 = V_33 ;
if ( V_32 > V_34 )
V_33 = F_22 (
& V_1 -> V_35 . V_36 , V_34 , V_32 ) ;
} while ( V_33 != V_34 );
}
static inline void F_23 ( void * V_37 , unsigned long V_38 ,
unsigned long V_11 )
{
F_24 ( ! F_25 ( V_38 , sizeof( unsigned long ) ) ) ;
F_26 ( V_37 , V_11 , V_38 / sizeof( unsigned long ) ) ;
}
static bool F_27 ( void * V_37 , unsigned long * V_12 )
{
unsigned int V_39 ;
unsigned long * V_40 ;
unsigned long V_41 ;
V_40 = ( unsigned long * ) V_37 ;
V_41 = V_40 [ 0 ] ;
for ( V_39 = 1 ; V_39 < V_19 / sizeof( * V_40 ) ; V_39 ++ ) {
if ( V_41 != V_40 [ V_39 ] )
return false ;
}
* V_12 = V_41 ;
return true ;
}
static T_5 F_28 ( struct V_3 * V_4 ,
struct V_42 * V_43 , char * V_44 )
{
T_1 V_41 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
F_29 ( & V_1 -> V_45 ) ;
V_41 = F_1 ( V_1 ) ;
F_30 ( & V_1 -> V_45 ) ;
return F_31 ( V_44 , V_19 , L_1 , V_41 ) ;
}
static T_5 F_32 ( struct V_3 * V_4 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_1 * V_1 = F_2 ( V_4 ) ;
return F_31 ( V_44 , V_19 , L_2 , V_1 -> V_2 ) ;
}
static T_5 F_33 ( struct V_3 * V_4 ,
struct V_42 * V_43 , const char * V_44 , T_2 V_38 )
{
T_4 V_46 ;
char * V_47 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
V_46 = F_34 ( V_44 , & V_47 ) ;
if ( V_44 == V_47 )
return - V_48 ;
F_35 ( & V_1 -> V_45 ) ;
V_1 -> V_49 = F_36 ( V_46 ) >> V_50 ;
F_37 ( & V_1 -> V_45 ) ;
return V_38 ;
}
static T_5 F_38 ( struct V_3 * V_4 ,
struct V_42 * V_43 , const char * V_44 , T_2 V_38 )
{
int V_51 ;
unsigned long V_41 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
V_51 = F_39 ( V_44 , 10 , & V_41 ) ;
if ( V_51 || V_41 != 0 )
return - V_48 ;
F_29 ( & V_1 -> V_45 ) ;
if ( F_1 ( V_1 ) ) {
F_40 ( & V_1 -> V_35 . V_36 ,
F_41 ( V_1 -> V_52 ) ) ;
}
F_30 ( & V_1 -> V_45 ) ;
return V_38 ;
}
static bool F_42 ( struct V_1 * V_1 )
{
return V_1 -> V_53 ;
}
static void F_43 ( struct V_1 * V_1 )
{
struct V_54 * V_55 ;
if ( ! F_42 ( V_1 ) )
return;
V_55 = V_1 -> V_55 ;
if ( V_1 -> V_56 )
F_44 ( V_55 , V_1 -> V_56 ) ;
F_45 ( V_55 , V_57 | V_58 | V_59 ) ;
F_46 ( V_1 -> V_53 , NULL ) ;
V_1 -> V_53 = NULL ;
V_1 -> V_56 = 0 ;
V_1 -> V_55 = NULL ;
F_47 ( V_1 -> V_60 ) ;
V_1 -> V_60 = NULL ;
}
static T_5 F_48 ( struct V_3 * V_4 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_1 * V_1 = F_2 ( V_4 ) ;
struct V_61 * V_61 = V_1 -> V_53 ;
char * V_62 ;
T_5 V_63 ;
F_29 ( & V_1 -> V_45 ) ;
if ( ! F_42 ( V_1 ) ) {
memcpy ( V_44 , L_3 , 5 ) ;
F_30 ( & V_1 -> V_45 ) ;
return 5 ;
}
V_62 = F_49 ( V_61 , V_44 , V_19 - 1 ) ;
if ( F_50 ( V_62 ) ) {
V_63 = F_51 ( V_62 ) ;
goto V_64;
}
V_63 = strlen ( V_62 ) ;
memmove ( V_44 , V_62 , V_63 ) ;
V_44 [ V_63 ++ ] = '\n' ;
V_64:
F_30 ( & V_1 -> V_45 ) ;
return V_63 ;
}
static T_5 F_52 ( struct V_3 * V_4 ,
struct V_42 * V_43 , const char * V_44 , T_2 V_38 )
{
char * V_65 ;
struct V_61 * V_53 = NULL ;
struct V_66 * V_66 ;
struct V_67 * V_68 ;
unsigned int V_69 , V_56 = 0 ;
unsigned long V_70 , * V_60 = NULL ;
struct V_54 * V_55 = NULL ;
int V_51 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
V_65 = F_53 ( V_71 , V_72 ) ;
if ( ! V_65 )
return - V_73 ;
F_35 ( & V_1 -> V_45 ) ;
if ( F_1 ( V_1 ) ) {
F_54 ( L_4 ) ;
V_51 = - V_74 ;
goto V_64;
}
F_55 ( V_65 , V_44 , V_38 ) ;
V_53 = F_56 ( V_65 , V_75 | V_76 , 0 ) ;
if ( F_50 ( V_53 ) ) {
V_51 = F_51 ( V_53 ) ;
V_53 = NULL ;
goto V_64;
}
V_68 = V_53 -> V_77 ;
V_66 = V_68 -> V_78 ;
if ( ! F_57 ( V_66 -> V_79 ) ) {
V_51 = - V_80 ;
goto V_64;
}
V_55 = F_58 ( F_59 ( V_66 ) ) ;
V_51 = F_60 ( V_55 , V_57 | V_58 | V_59 , V_1 ) ;
if ( V_51 < 0 )
goto V_64;
V_70 = F_61 ( V_66 ) >> V_50 ;
V_69 = F_62 ( V_70 ) * sizeof( long ) ;
V_60 = F_63 ( V_69 , V_72 ) ;
if ( ! V_60 ) {
V_51 = - V_73 ;
goto V_64;
}
V_56 = F_64 ( V_55 ) ;
V_51 = F_44 ( V_55 , V_19 ) ;
if ( V_51 )
goto V_64;
F_43 ( V_1 ) ;
F_65 ( & V_1 -> V_81 ) ;
V_1 -> V_56 = V_56 ;
V_1 -> V_55 = V_55 ;
V_1 -> V_53 = V_53 ;
V_1 -> V_60 = V_60 ;
V_1 -> V_70 = V_70 ;
F_37 ( & V_1 -> V_45 ) ;
F_54 ( L_5 , V_65 ) ;
F_66 ( V_65 ) ;
return V_38 ;
V_64:
if ( V_60 )
F_47 ( V_60 ) ;
if ( V_55 )
F_45 ( V_55 , V_57 | V_58 | V_59 ) ;
if ( V_53 )
F_46 ( V_53 , NULL ) ;
F_37 ( & V_1 -> V_45 ) ;
F_66 ( V_65 ) ;
return V_51 ;
}
static unsigned long F_67 ( struct V_1 * V_1 )
{
unsigned long V_82 ;
F_68 ( & V_1 -> V_81 ) ;
V_82 = F_69 ( V_1 -> V_60 , V_1 -> V_70 , 1 ) ;
if ( V_82 == V_1 -> V_70 ) {
F_70 ( & V_1 -> V_81 ) ;
return 0 ;
}
F_71 ( V_82 , V_1 -> V_60 ) ;
F_70 ( & V_1 -> V_81 ) ;
return V_82 ;
}
static void F_72 ( struct V_1 * V_1 , unsigned long V_82 )
{
int V_83 ;
F_68 ( & V_1 -> V_81 ) ;
V_83 = F_73 ( V_82 , V_1 -> V_60 ) ;
F_70 ( & V_1 -> V_81 ) ;
F_24 ( ! V_83 ) ;
}
void F_74 ( struct V_84 * V_84 )
{
struct V_40 * V_40 = V_84 -> V_85 [ 0 ] . V_86 ;
F_75 ( V_40 , F_76 ( F_77 ( V_84 ) ) ,
F_78 ( V_84 -> V_87 ) ) ;
F_79 ( V_84 ) ;
}
static int F_80 ( struct V_1 * V_1 , struct V_16 * V_17 ,
unsigned long V_82 , struct V_84 * V_88 )
{
struct V_84 * V_84 ;
V_84 = F_81 ( V_89 , 1 ) ;
if ( ! V_84 )
return - V_73 ;
V_84 -> V_90 . V_91 = V_82 * ( V_19 >> 9 ) ;
F_82 ( V_84 , V_1 -> V_55 ) ;
if ( ! F_83 ( V_84 , V_17 -> V_86 , V_17 -> V_18 , V_17 -> V_92 ) ) {
F_79 ( V_84 ) ;
return - V_93 ;
}
if ( ! V_88 ) {
V_84 -> V_94 = V_95 ;
V_84 -> V_96 = F_74 ;
} else {
V_84 -> V_94 = V_88 -> V_94 ;
F_84 ( V_84 , V_88 ) ;
}
F_85 ( V_84 ) ;
return 1 ;
}
static void F_86 ( struct V_97 * V_98 )
{
struct V_16 V_17 ;
struct V_99 * V_100 = F_87 ( V_98 , struct V_99 , V_98 ) ;
struct V_1 * V_1 = V_100 -> V_1 ;
unsigned long V_82 = V_100 -> V_82 ;
struct V_84 * V_84 = V_100 -> V_84 ;
F_80 ( V_1 , & V_17 , V_82 , V_84 ) ;
}
static int F_88 ( struct V_1 * V_1 , struct V_16 * V_17 ,
unsigned long V_82 , struct V_84 * V_84 )
{
struct V_99 V_98 ;
V_98 . V_1 = V_1 ;
V_98 . V_82 = V_82 ;
V_98 . V_84 = V_84 ;
F_89 ( & V_98 . V_98 , F_86 ) ;
F_90 ( V_101 , & V_98 . V_98 ) ;
F_91 ( & V_98 . V_98 ) ;
F_92 ( & V_98 . V_98 ) ;
return 1 ;
}
static int F_88 ( struct V_1 * V_1 , struct V_16 * V_17 ,
unsigned long V_82 , struct V_84 * V_84 )
{
F_93 ( 1 ) ;
return - V_93 ;
}
static int F_94 ( struct V_1 * V_1 , struct V_16 * V_17 ,
unsigned long V_82 , struct V_84 * V_88 , bool V_102 )
{
if ( V_102 )
return F_88 ( V_1 , V_17 , V_82 , V_88 ) ;
else
return F_80 ( V_1 , V_17 , V_82 , V_88 ) ;
}
static int F_95 ( struct V_1 * V_1 , struct V_16 * V_17 ,
T_1 V_6 , struct V_84 * V_88 ,
unsigned long * V_103 )
{
struct V_84 * V_84 ;
unsigned long V_82 ;
V_84 = F_81 ( V_89 , 1 ) ;
if ( ! V_84 )
return - V_73 ;
V_82 = F_67 ( V_1 ) ;
if ( ! V_82 ) {
F_79 ( V_84 ) ;
return - V_104 ;
}
V_84 -> V_90 . V_91 = V_82 * ( V_19 >> 9 ) ;
F_82 ( V_84 , V_1 -> V_55 ) ;
if ( ! F_83 ( V_84 , V_17 -> V_86 , V_17 -> V_18 ,
V_17 -> V_92 ) ) {
F_79 ( V_84 ) ;
F_72 ( V_1 , V_82 ) ;
return - V_93 ;
}
if ( ! V_88 ) {
V_84 -> V_94 = V_105 | V_106 ;
V_84 -> V_96 = F_74 ;
} else {
V_84 -> V_94 = V_88 -> V_94 ;
F_84 ( V_84 , V_88 ) ;
}
F_85 ( V_84 ) ;
* V_103 = V_82 ;
return 0 ;
}
static void F_96 ( struct V_1 * V_1 , T_1 V_6 )
{
unsigned long V_82 ;
F_9 ( V_1 , V_6 , V_107 ) ;
V_82 = F_11 ( V_1 , V_6 ) ;
F_10 ( V_1 , V_6 , 0 ) ;
F_72 ( V_1 , V_82 ) ;
}
static bool F_42 ( struct V_1 * V_1 ) { return false ; }
static inline void F_43 ( struct V_1 * V_1 ) {}
static int F_95 ( struct V_1 * V_1 , struct V_16 * V_17 ,
T_1 V_6 , struct V_84 * V_88 ,
unsigned long * V_103 )
{
return - V_93 ;
}
static int F_94 ( struct V_1 * V_1 , struct V_16 * V_17 ,
unsigned long V_82 , struct V_84 * V_88 , bool V_102 )
{
return - V_93 ;
}
static void F_96 ( struct V_1 * V_1 , T_1 V_6 ) {}
static T_5 F_97 ( struct V_3 * V_4 ,
struct V_42 * V_43 , char * V_44 )
{
return F_31 ( V_44 , V_19 , L_6 , F_98 () ) ;
}
static T_5 F_99 ( struct V_3 * V_4 ,
struct V_42 * V_43 , const char * V_44 , T_2 V_38 )
{
return V_38 ;
}
static T_5 F_100 ( struct V_3 * V_4 ,
struct V_42 * V_43 , char * V_44 )
{
T_2 V_108 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
F_29 ( & V_1 -> V_45 ) ;
V_108 = F_101 ( V_1 -> V_109 , V_44 ) ;
F_30 ( & V_1 -> V_45 ) ;
return V_108 ;
}
static T_5 F_102 ( struct V_3 * V_4 ,
struct V_42 * V_43 , const char * V_44 , T_2 V_38 )
{
struct V_1 * V_1 = F_2 ( V_4 ) ;
char V_109 [ F_103 ( V_1 -> V_109 ) ] ;
T_2 V_108 ;
F_55 ( V_109 , V_44 , sizeof( V_109 ) ) ;
V_108 = strlen ( V_109 ) ;
if ( V_108 > 0 && V_109 [ V_108 - 1 ] == '\n' )
V_109 [ V_108 - 1 ] = 0x00 ;
if ( ! F_104 ( V_109 ) )
return - V_48 ;
F_35 ( & V_1 -> V_45 ) ;
if ( F_1 ( V_1 ) ) {
F_37 ( & V_1 -> V_45 ) ;
F_54 ( L_7 ) ;
return - V_74 ;
}
strcpy ( V_1 -> V_109 , V_109 ) ;
F_37 ( & V_1 -> V_45 ) ;
return V_38 ;
}
static T_5 F_105 ( struct V_3 * V_4 ,
struct V_42 * V_43 , const char * V_44 , T_2 V_38 )
{
struct V_1 * V_1 = F_2 ( V_4 ) ;
F_29 ( & V_1 -> V_45 ) ;
if ( ! F_1 ( V_1 ) ) {
F_30 ( & V_1 -> V_45 ) ;
return - V_48 ;
}
F_106 ( V_1 -> V_52 ) ;
F_30 ( & V_1 -> V_45 ) ;
return V_38 ;
}
static T_5 F_107 ( struct V_3 * V_4 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_1 * V_1 = F_2 ( V_4 ) ;
T_5 V_63 ;
F_29 ( & V_1 -> V_45 ) ;
V_63 = F_31 ( V_44 , V_19 ,
L_8 ,
( T_4 ) F_108 ( & V_1 -> V_35 . V_110 ) ,
( T_4 ) F_108 ( & V_1 -> V_35 . V_111 ) ,
( T_4 ) F_108 ( & V_1 -> V_35 . V_112 ) ,
( T_4 ) F_108 ( & V_1 -> V_35 . V_113 ) ) ;
F_30 ( & V_1 -> V_45 ) ;
return V_63 ;
}
static T_5 F_109 ( struct V_3 * V_4 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_1 * V_1 = F_2 ( V_4 ) ;
struct V_114 V_115 ;
T_4 V_116 , V_117 = 0 ;
long V_118 ;
T_5 V_63 ;
memset ( & V_115 , 0x00 , sizeof( struct V_114 ) ) ;
F_29 ( & V_1 -> V_45 ) ;
if ( F_1 ( V_1 ) ) {
V_117 = F_41 ( V_1 -> V_52 ) ;
V_114 ( V_1 -> V_52 , & V_115 ) ;
}
V_116 = F_108 ( & V_1 -> V_35 . V_119 ) ;
V_118 = F_21 ( & V_1 -> V_35 . V_36 ) ;
V_63 = F_31 ( V_44 , V_19 ,
L_9 ,
V_116 << V_50 ,
( T_4 ) F_108 ( & V_1 -> V_35 . V_120 ) ,
V_117 << V_50 ,
V_1 -> V_49 << V_50 ,
V_118 << V_50 ,
( T_4 ) F_108 ( & V_1 -> V_35 . V_121 ) ,
V_115 . V_122 ) ;
F_30 ( & V_1 -> V_45 ) ;
return V_63 ;
}
static T_5 F_110 ( struct V_3 * V_4 ,
struct V_42 * V_43 , char * V_44 )
{
int V_123 = 1 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
T_5 V_63 ;
F_29 ( & V_1 -> V_45 ) ;
V_63 = F_31 ( V_44 , V_19 ,
L_10 ,
V_123 ,
( T_4 ) F_108 ( & V_1 -> V_35 . V_124 ) ) ;
F_30 ( & V_1 -> V_45 ) ;
return V_63 ;
}
static void F_111 ( struct V_1 * V_1 , T_1 V_6 )
{
F_112 ( V_125 , & V_1 -> V_7 [ V_6 ] . V_11 ) ;
}
static void F_113 ( struct V_1 * V_1 , T_1 V_6 )
{
F_114 ( V_125 , & V_1 -> V_7 [ V_6 ] . V_11 ) ;
}
static void F_115 ( struct V_1 * V_1 , T_4 V_2 )
{
T_2 V_126 = V_2 >> V_50 ;
T_2 V_6 ;
for ( V_6 = 0 ; V_6 < V_126 ; V_6 ++ )
F_116 ( V_1 , V_6 ) ;
F_117 ( V_1 -> V_52 ) ;
F_118 ( V_1 -> V_7 ) ;
}
static bool F_119 ( struct V_1 * V_1 , T_4 V_2 )
{
T_2 V_126 ;
V_126 = V_2 >> V_50 ;
V_1 -> V_7 = F_120 ( V_126 * sizeof( * V_1 -> V_7 ) ) ;
if ( ! V_1 -> V_7 )
return false ;
V_1 -> V_52 = F_121 ( V_1 -> V_20 -> V_127 ) ;
if ( ! V_1 -> V_52 ) {
F_118 ( V_1 -> V_7 ) ;
return false ;
}
return true ;
}
static void F_116 ( struct V_1 * V_1 , T_2 V_6 )
{
unsigned long V_8 ;
if ( F_42 ( V_1 ) && F_6 ( V_1 , V_6 , V_107 ) ) {
F_96 ( V_1 , V_6 ) ;
F_122 ( & V_1 -> V_35 . V_119 ) ;
return;
}
if ( F_6 ( V_1 , V_6 , V_128 ) ) {
F_9 ( V_1 , V_6 , V_128 ) ;
F_10 ( V_1 , V_6 , 0 ) ;
F_122 ( & V_1 -> V_35 . V_121 ) ;
F_122 ( & V_1 -> V_35 . V_119 ) ;
return;
}
V_8 = F_4 ( V_1 , V_6 ) ;
if ( ! V_8 )
return;
F_123 ( V_1 -> V_52 , V_8 ) ;
F_124 ( F_12 ( V_1 , V_6 ) ,
& V_1 -> V_35 . V_120 ) ;
F_122 ( & V_1 -> V_35 . V_119 ) ;
F_5 ( V_1 , V_6 , 0 ) ;
F_13 ( V_1 , V_6 , 0 ) ;
}
static int F_125 ( struct V_1 * V_1 , struct V_40 * V_40 , T_1 V_6 ,
struct V_84 * V_84 , bool V_129 )
{
int V_63 ;
unsigned long V_8 ;
unsigned int V_14 ;
void * V_130 , * V_131 ;
if ( F_42 ( V_1 ) ) {
F_111 ( V_1 , V_6 ) ;
if ( F_6 ( V_1 , V_6 , V_107 ) ) {
struct V_16 V_17 ;
F_113 ( V_1 , V_6 ) ;
V_17 . V_86 = V_40 ;
V_17 . V_18 = V_19 ;
V_17 . V_92 = 0 ;
return F_94 ( V_1 , & V_17 ,
F_11 ( V_1 , V_6 ) ,
V_84 , V_129 ) ;
}
F_113 ( V_1 , V_6 ) ;
}
F_111 ( V_1 , V_6 ) ;
V_8 = F_4 ( V_1 , V_6 ) ;
if ( ! V_8 || F_6 ( V_1 , V_6 , V_128 ) ) {
unsigned long V_11 ;
void * V_132 ;
V_11 = V_8 ? F_11 ( V_1 , V_6 ) : 0 ;
V_132 = F_126 ( V_40 ) ;
F_23 ( V_132 , V_19 , V_11 ) ;
F_127 ( V_132 ) ;
F_113 ( V_1 , V_6 ) ;
return 0 ;
}
V_14 = F_12 ( V_1 , V_6 ) ;
V_130 = F_128 ( V_1 -> V_52 , V_8 , V_133 ) ;
if ( V_14 == V_19 ) {
V_131 = F_126 ( V_40 ) ;
memcpy ( V_131 , V_130 , V_19 ) ;
F_127 ( V_131 ) ;
V_63 = 0 ;
} else {
struct V_134 * V_135 = F_129 ( V_1 -> V_136 ) ;
V_131 = F_126 ( V_40 ) ;
V_63 = F_130 ( V_135 , V_130 , V_14 , V_131 ) ;
F_127 ( V_131 ) ;
F_131 ( V_1 -> V_136 ) ;
}
F_132 ( V_1 -> V_52 , V_8 ) ;
F_113 ( V_1 , V_6 ) ;
if ( F_18 ( V_63 ) )
F_133 ( L_11 , V_63 , V_6 ) ;
return V_63 ;
}
static int F_134 ( struct V_1 * V_1 , struct V_16 * V_17 ,
T_1 V_6 , int V_31 , struct V_84 * V_84 )
{
int V_63 ;
struct V_40 * V_40 ;
V_40 = V_17 -> V_86 ;
if ( F_14 ( V_17 ) ) {
V_40 = F_135 ( V_137 | V_138 ) ;
if ( ! V_40 )
return - V_73 ;
}
V_63 = F_125 ( V_1 , V_40 , V_6 , V_84 , F_14 ( V_17 ) ) ;
if ( F_18 ( V_63 ) )
goto V_64;
if ( F_14 ( V_17 ) ) {
void * V_131 = F_126 ( V_17 -> V_86 ) ;
void * V_130 = F_126 ( V_40 ) ;
memcpy ( V_131 + V_17 -> V_92 , V_130 + V_31 , V_17 -> V_18 ) ;
F_127 ( V_130 ) ;
F_127 ( V_131 ) ;
}
V_64:
if ( F_14 ( V_17 ) )
F_136 ( V_40 ) ;
return V_63 ;
}
static int F_137 ( struct V_1 * V_1 , struct V_16 * V_17 ,
T_1 V_6 , struct V_84 * V_84 )
{
int V_63 = 0 ;
unsigned long V_139 ;
unsigned long V_8 = 0 ;
unsigned int V_140 = 0 ;
void * V_130 , * V_131 , * V_132 ;
struct V_134 * V_135 ;
struct V_40 * V_40 = V_17 -> V_86 ;
unsigned long V_12 = 0 ;
enum V_9 V_15 = 0 ;
bool V_141 = true ;
V_132 = F_126 ( V_40 ) ;
if ( F_27 ( V_132 , & V_12 ) ) {
F_127 ( V_132 ) ;
V_15 = V_128 ;
F_138 ( & V_1 -> V_35 . V_121 ) ;
goto V_64;
}
F_127 ( V_132 ) ;
V_142:
V_135 = F_129 ( V_1 -> V_136 ) ;
V_130 = F_126 ( V_40 ) ;
V_63 = F_139 ( V_135 , V_130 , & V_140 ) ;
F_127 ( V_130 ) ;
if ( F_18 ( V_63 ) ) {
F_131 ( V_1 -> V_136 ) ;
F_133 ( L_12 , V_63 ) ;
F_123 ( V_1 -> V_52 , V_8 ) ;
return V_63 ;
}
if ( F_18 ( V_140 > V_143 ) ) {
if ( F_42 ( V_1 ) && V_141 ) {
F_131 ( V_1 -> V_136 ) ;
V_63 = F_95 ( V_1 , V_17 , V_6 , V_84 , & V_12 ) ;
if ( ! V_63 ) {
V_15 = V_107 ;
V_63 = 1 ;
goto V_64;
}
V_141 = false ;
goto V_142;
}
V_140 = V_19 ;
}
if ( ! V_8 )
V_8 = F_140 ( V_1 -> V_52 , V_140 ,
V_144 |
V_145 |
V_138 |
V_146 ) ;
if ( ! V_8 ) {
F_131 ( V_1 -> V_136 ) ;
F_138 ( & V_1 -> V_35 . V_124 ) ;
V_8 = F_140 ( V_1 -> V_52 , V_140 ,
V_137 | V_138 |
V_146 ) ;
if ( V_8 )
goto V_142;
return - V_73 ;
}
V_139 = F_41 ( V_1 -> V_52 ) ;
F_20 ( V_1 , V_139 ) ;
if ( V_1 -> V_49 && V_139 > V_1 -> V_49 ) {
F_131 ( V_1 -> V_136 ) ;
F_123 ( V_1 -> V_52 , V_8 ) ;
return - V_73 ;
}
V_131 = F_128 ( V_1 -> V_52 , V_8 , V_147 ) ;
V_130 = V_135 -> V_148 ;
if ( V_140 == V_19 )
V_130 = F_126 ( V_40 ) ;
memcpy ( V_131 , V_130 , V_140 ) ;
if ( V_140 == V_19 )
F_127 ( V_130 ) ;
F_131 ( V_1 -> V_136 ) ;
F_132 ( V_1 -> V_52 , V_8 ) ;
F_141 ( V_140 , & V_1 -> V_35 . V_120 ) ;
V_64:
F_111 ( V_1 , V_6 ) ;
F_116 ( V_1 , V_6 ) ;
if ( V_15 ) {
F_8 ( V_1 , V_6 , V_15 ) ;
F_10 ( V_1 , V_6 , V_12 ) ;
} else {
F_5 ( V_1 , V_6 , V_8 ) ;
F_13 ( V_1 , V_6 , V_140 ) ;
}
F_113 ( V_1 , V_6 ) ;
F_138 ( & V_1 -> V_35 . V_119 ) ;
return V_63 ;
}
static int F_142 ( struct V_1 * V_1 , struct V_16 * V_17 ,
T_1 V_6 , int V_31 , struct V_84 * V_84 )
{
int V_63 ;
struct V_40 * V_40 = NULL ;
void * V_130 ;
struct V_16 V_149 ;
V_149 = * V_17 ;
if ( F_14 ( V_17 ) ) {
void * V_131 ;
V_40 = F_135 ( V_137 | V_138 ) ;
if ( ! V_40 )
return - V_73 ;
V_63 = F_125 ( V_1 , V_40 , V_6 , V_84 , true ) ;
if ( V_63 )
goto V_64;
V_130 = F_126 ( V_17 -> V_86 ) ;
V_131 = F_126 ( V_40 ) ;
memcpy ( V_131 + V_31 , V_130 + V_17 -> V_92 , V_17 -> V_18 ) ;
F_127 ( V_131 ) ;
F_127 ( V_130 ) ;
V_149 . V_86 = V_40 ;
V_149 . V_18 = V_19 ;
V_149 . V_92 = 0 ;
}
V_63 = F_137 ( V_1 , & V_149 , V_6 , V_84 ) ;
V_64:
if ( F_14 ( V_17 ) )
F_136 ( V_40 ) ;
return V_63 ;
}
static void F_143 ( struct V_1 * V_1 , T_1 V_6 ,
int V_31 , struct V_84 * V_84 )
{
T_2 V_150 = V_84 -> V_90 . V_151 ;
if ( V_31 ) {
if ( V_150 <= ( V_19 - V_31 ) )
return;
V_150 -= ( V_19 - V_31 ) ;
V_6 ++ ;
}
while ( V_150 >= V_19 ) {
F_111 ( V_1 , V_6 ) ;
F_116 ( V_1 , V_6 ) ;
F_113 ( V_1 , V_6 ) ;
F_138 ( & V_1 -> V_35 . V_113 ) ;
V_6 ++ ;
V_150 -= V_19 ;
}
}
static int F_144 ( struct V_1 * V_1 , struct V_16 * V_17 , T_1 V_6 ,
int V_31 , bool V_152 , struct V_84 * V_84 )
{
unsigned long V_153 = V_154 ;
int V_155 = V_152 ? V_105 : V_95 ;
struct V_156 * V_157 = V_1 -> V_20 -> V_21 ;
int V_63 ;
F_145 ( V_157 , V_155 , V_17 -> V_18 >> V_30 ,
& V_1 -> V_20 -> V_158 ) ;
if ( ! V_152 ) {
F_138 ( & V_1 -> V_35 . V_159 ) ;
V_63 = F_134 ( V_1 , V_17 , V_6 , V_31 , V_84 ) ;
F_146 ( V_17 -> V_86 ) ;
} else {
F_138 ( & V_1 -> V_35 . V_160 ) ;
V_63 = F_142 ( V_1 , V_17 , V_6 , V_31 , V_84 ) ;
}
F_147 ( V_157 , V_155 , & V_1 -> V_20 -> V_158 , V_153 ) ;
if ( F_18 ( V_63 < 0 ) ) {
if ( ! V_152 )
F_138 ( & V_1 -> V_35 . V_110 ) ;
else
F_138 ( & V_1 -> V_35 . V_111 ) ;
}
return V_63 ;
}
static void F_148 ( struct V_1 * V_1 , struct V_84 * V_84 )
{
int V_31 ;
T_1 V_6 ;
struct V_16 V_17 ;
struct V_161 V_162 ;
V_6 = V_84 -> V_90 . V_91 >> V_163 ;
V_31 = ( V_84 -> V_90 . V_91 &
( V_164 - 1 ) ) << V_30 ;
switch ( F_77 ( V_84 ) ) {
case V_165 :
case V_166 :
F_143 ( V_1 , V_6 , V_31 , V_84 ) ;
F_149 ( V_84 ) ;
return;
default:
break;
}
F_150 (bvec, bio, iter) {
struct V_16 V_167 = V_17 ;
unsigned int V_168 = V_17 . V_18 ;
do {
V_167 . V_18 = F_151 (unsigned int, PAGE_SIZE - offset,
unwritten) ;
if ( F_144 ( V_1 , & V_167 , V_6 , V_31 ,
F_76 ( F_77 ( V_84 ) ) , V_84 ) < 0 )
goto V_64;
V_167 . V_92 += V_167 . V_18 ;
V_168 -= V_167 . V_18 ;
F_19 ( & V_6 , & V_31 , & V_167 ) ;
} while ( V_168 );
}
F_149 ( V_84 ) ;
return;
V_64:
F_152 ( V_84 ) ;
}
static T_6 F_153 ( struct V_156 * V_21 , struct V_84 * V_84 )
{
struct V_1 * V_1 = V_21 -> V_169 ;
if ( ! F_17 ( V_1 , V_84 -> V_90 . V_91 ,
V_84 -> V_90 . V_151 ) ) {
F_138 ( & V_1 -> V_35 . V_112 ) ;
goto error;
}
F_148 ( V_1 , V_84 ) ;
return V_170 ;
error:
F_152 ( V_84 ) ;
return V_170 ;
}
static void F_154 ( struct V_54 * V_55 ,
unsigned long V_6 )
{
struct V_1 * V_1 ;
V_1 = V_55 -> V_171 -> V_5 ;
F_111 ( V_1 , V_6 ) ;
F_116 ( V_1 , V_6 ) ;
F_113 ( V_1 , V_6 ) ;
F_138 ( & V_1 -> V_35 . V_113 ) ;
}
static int F_155 ( struct V_54 * V_55 , T_3 V_172 ,
struct V_40 * V_40 , bool V_152 )
{
int V_31 , V_63 ;
T_1 V_6 ;
struct V_1 * V_1 ;
struct V_16 V_167 ;
if ( F_156 ( V_40 ) )
return - V_173 ;
V_1 = V_55 -> V_171 -> V_5 ;
if ( ! F_17 ( V_1 , V_172 , V_19 ) ) {
F_138 ( & V_1 -> V_35 . V_112 ) ;
V_63 = - V_48 ;
goto V_64;
}
V_6 = V_172 >> V_163 ;
V_31 = ( V_172 & ( V_164 - 1 ) ) << V_30 ;
V_167 . V_86 = V_40 ;
V_167 . V_18 = V_19 ;
V_167 . V_92 = 0 ;
V_63 = F_144 ( V_1 , & V_167 , V_6 , V_31 , V_152 , NULL ) ;
V_64:
if ( F_18 ( V_63 < 0 ) )
return V_63 ;
switch ( V_63 ) {
case 0 :
F_75 ( V_40 , V_152 , 0 ) ;
break;
case 1 :
V_63 = 0 ;
break;
default:
F_93 ( 1 ) ;
}
return V_63 ;
}
static void F_157 ( struct V_1 * V_1 )
{
struct V_174 * V_136 ;
T_4 V_2 ;
F_35 ( & V_1 -> V_45 ) ;
V_1 -> V_49 = 0 ;
if ( ! F_1 ( V_1 ) ) {
F_37 ( & V_1 -> V_45 ) ;
return;
}
V_136 = V_1 -> V_136 ;
V_2 = V_1 -> V_2 ;
V_1 -> V_2 = 0 ;
F_158 ( V_1 -> V_20 , 0 ) ;
F_159 ( & V_1 -> V_20 -> V_158 , 0 ) ;
F_37 ( & V_1 -> V_45 ) ;
F_115 ( V_1 , V_2 ) ;
memset ( & V_1 -> V_35 , 0 , sizeof( V_1 -> V_35 ) ) ;
F_160 ( V_136 ) ;
F_43 ( V_1 ) ;
}
static T_5 F_161 ( struct V_3 * V_4 ,
struct V_42 * V_43 , const char * V_44 , T_2 V_38 )
{
T_4 V_2 ;
struct V_174 * V_136 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
int V_51 ;
V_2 = F_34 ( V_44 , NULL ) ;
if ( ! V_2 )
return - V_48 ;
F_35 ( & V_1 -> V_45 ) ;
if ( F_1 ( V_1 ) ) {
F_54 ( L_13 ) ;
V_51 = - V_74 ;
goto V_175;
}
V_2 = F_36 ( V_2 ) ;
if ( ! F_119 ( V_1 , V_2 ) ) {
V_51 = - V_73 ;
goto V_175;
}
V_136 = F_162 ( V_1 -> V_109 ) ;
if ( F_50 ( V_136 ) ) {
F_133 ( L_14 ,
V_1 -> V_109 ) ;
V_51 = F_51 ( V_136 ) ;
goto V_176;
}
V_1 -> V_136 = V_136 ;
V_1 -> V_2 = V_2 ;
F_158 ( V_1 -> V_20 , V_1 -> V_2 >> V_30 ) ;
F_15 ( V_1 ) ;
F_37 ( & V_1 -> V_45 ) ;
return V_38 ;
V_176:
F_115 ( V_1 , V_2 ) ;
V_175:
F_37 ( & V_1 -> V_45 ) ;
return V_51 ;
}
static T_5 F_163 ( struct V_3 * V_4 ,
struct V_42 * V_43 , const char * V_44 , T_2 V_38 )
{
int V_63 ;
unsigned short V_177 ;
struct V_1 * V_1 ;
struct V_54 * V_55 ;
V_63 = F_164 ( V_44 , 10 , & V_177 ) ;
if ( V_63 )
return V_63 ;
if ( ! V_177 )
return - V_48 ;
V_1 = F_2 ( V_4 ) ;
V_55 = F_165 ( V_1 -> V_20 , 0 ) ;
if ( ! V_55 )
return - V_73 ;
F_166 ( & V_55 -> V_178 ) ;
if ( V_55 -> V_179 || V_1 -> V_180 ) {
F_167 ( & V_55 -> V_178 ) ;
F_168 ( V_55 ) ;
return - V_74 ;
}
V_1 -> V_180 = true ;
F_167 ( & V_55 -> V_178 ) ;
F_169 ( V_55 ) ;
F_157 ( V_1 ) ;
F_15 ( V_1 ) ;
F_168 ( V_55 ) ;
F_166 ( & V_55 -> V_178 ) ;
V_1 -> V_180 = false ;
F_167 ( & V_55 -> V_178 ) ;
return V_38 ;
}
static int F_170 ( struct V_54 * V_55 , T_7 V_181 )
{
int V_63 = 0 ;
struct V_1 * V_1 ;
F_93 ( ! F_171 ( & V_55 -> V_178 ) ) ;
V_1 = V_55 -> V_171 -> V_5 ;
if ( V_1 -> V_180 )
V_63 = - V_74 ;
return V_63 ;
}
static int F_172 ( void )
{
struct V_1 * V_1 ;
struct V_156 * V_21 ;
int V_63 , V_182 ;
V_1 = F_173 ( sizeof( struct V_1 ) , V_72 ) ;
if ( ! V_1 )
return - V_73 ;
V_63 = F_174 ( & V_183 , V_1 , 0 , 0 , V_72 ) ;
if ( V_63 < 0 )
goto V_184;
V_182 = V_63 ;
F_175 ( & V_1 -> V_45 ) ;
V_21 = F_176 ( V_72 ) ;
if ( ! V_21 ) {
F_133 ( L_15 ,
V_182 ) ;
V_63 = - V_73 ;
goto V_185;
}
F_177 ( V_21 , F_153 ) ;
V_1 -> V_20 = F_178 ( 1 ) ;
if ( ! V_1 -> V_20 ) {
F_133 ( L_16 ,
V_182 ) ;
V_63 = - V_73 ;
goto V_186;
}
V_1 -> V_20 -> V_187 = V_188 ;
V_1 -> V_20 -> V_189 = V_182 ;
V_1 -> V_20 -> V_190 = & V_191 ;
V_1 -> V_20 -> V_21 = V_21 ;
V_1 -> V_20 -> V_21 -> V_169 = V_1 ;
V_1 -> V_20 -> V_5 = V_1 ;
snprintf ( V_1 -> V_20 -> V_127 , 16 , L_17 , V_182 ) ;
F_158 ( V_1 -> V_20 , 0 ) ;
F_179 ( V_192 , V_1 -> V_20 -> V_21 ) ;
F_180 ( V_193 , V_1 -> V_20 -> V_21 ) ;
F_181 ( V_1 -> V_20 -> V_21 , V_19 ) ;
F_182 ( V_1 -> V_20 -> V_21 ,
V_29 ) ;
F_183 ( V_1 -> V_20 -> V_21 , V_19 ) ;
F_184 ( V_1 -> V_20 -> V_21 , V_19 ) ;
V_1 -> V_20 -> V_21 -> V_194 . V_195 = V_19 ;
F_185 ( V_1 -> V_20 -> V_21 , V_196 ) ;
F_179 ( V_197 , V_1 -> V_20 -> V_21 ) ;
if ( V_29 == V_19 )
F_186 ( V_1 -> V_20 -> V_21 , V_196 ) ;
F_187 ( V_1 -> V_20 ) ;
V_63 = F_188 ( & F_189 ( V_1 -> V_20 ) -> V_198 ,
& V_199 ) ;
if ( V_63 < 0 ) {
F_133 ( L_18 ,
V_182 ) ;
goto V_200;
}
F_55 ( V_1 -> V_109 , V_201 , sizeof( V_1 -> V_109 ) ) ;
F_54 ( L_19 , V_1 -> V_20 -> V_127 ) ;
return V_182 ;
V_200:
F_190 ( V_1 -> V_20 ) ;
F_191 ( V_1 -> V_20 ) ;
V_186:
F_192 ( V_21 ) ;
V_185:
F_193 ( & V_183 , V_182 ) ;
V_184:
F_66 ( V_1 ) ;
return V_63 ;
}
static int F_194 ( struct V_1 * V_1 )
{
struct V_54 * V_55 ;
V_55 = F_165 ( V_1 -> V_20 , 0 ) ;
if ( ! V_55 )
return - V_73 ;
F_166 ( & V_55 -> V_178 ) ;
if ( V_55 -> V_179 || V_1 -> V_180 ) {
F_167 ( & V_55 -> V_178 ) ;
F_168 ( V_55 ) ;
return - V_74 ;
}
V_1 -> V_180 = true ;
F_167 ( & V_55 -> V_178 ) ;
F_195 ( & F_189 ( V_1 -> V_20 ) -> V_198 ,
& V_199 ) ;
F_169 ( V_55 ) ;
F_157 ( V_1 ) ;
F_168 ( V_55 ) ;
F_54 ( L_20 , V_1 -> V_20 -> V_127 ) ;
F_192 ( V_1 -> V_20 -> V_21 ) ;
F_190 ( V_1 -> V_20 ) ;
F_191 ( V_1 -> V_20 ) ;
F_66 ( V_1 ) ;
return 0 ;
}
static T_5 F_196 ( struct V_202 * V_202 ,
struct V_203 * V_43 ,
char * V_44 )
{
int V_63 ;
F_166 ( & V_204 ) ;
V_63 = F_172 () ;
F_167 ( & V_204 ) ;
if ( V_63 < 0 )
return V_63 ;
return F_31 ( V_44 , V_19 , L_6 , V_63 ) ;
}
static T_5 F_197 ( struct V_202 * V_202 ,
struct V_203 * V_43 ,
const char * V_44 ,
T_2 V_205 )
{
struct V_1 * V_1 ;
int V_63 , V_206 ;
V_63 = F_198 ( V_44 , 10 , & V_206 ) ;
if ( V_63 )
return V_63 ;
if ( V_206 < 0 )
return - V_48 ;
F_166 ( & V_204 ) ;
V_1 = F_199 ( & V_183 , V_206 ) ;
if ( V_1 ) {
V_63 = F_194 ( V_1 ) ;
if ( ! V_63 )
F_193 ( & V_183 , V_206 ) ;
} else {
V_63 = - V_207 ;
}
F_167 ( & V_204 ) ;
return V_63 ? V_63 : V_205 ;
}
static int F_200 ( int V_208 , void * V_37 , void * V_209 )
{
F_194 ( V_37 ) ;
return 0 ;
}
static void F_201 ( void )
{
F_202 ( & V_210 ) ;
F_203 ( & V_183 , & F_200 , NULL ) ;
F_204 ( & V_183 ) ;
F_205 ( V_188 , L_21 ) ;
F_206 ( V_211 ) ;
}
static int T_8 F_207 ( void )
{
int V_63 ;
V_63 = F_208 ( V_211 , L_22 ,
V_212 , V_213 ) ;
if ( V_63 < 0 )
return V_63 ;
V_63 = F_209 ( & V_210 ) ;
if ( V_63 ) {
F_133 ( L_23 ) ;
F_206 ( V_211 ) ;
return V_63 ;
}
V_188 = F_210 ( 0 , L_21 ) ;
if ( V_188 <= 0 ) {
F_133 ( L_24 ) ;
F_202 ( & V_210 ) ;
F_206 ( V_211 ) ;
return - V_74 ;
}
while ( V_214 != 0 ) {
F_166 ( & V_204 ) ;
V_63 = F_172 () ;
F_167 ( & V_204 ) ;
if ( V_63 < 0 )
goto V_215;
V_214 -- ;
}
return 0 ;
V_215:
F_201 () ;
return V_63 ;
}
static void T_9 F_211 ( void )
{
F_201 () ;
}
