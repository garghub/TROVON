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
static inline void F_23 ( char * V_37 , unsigned long V_38 ,
unsigned long V_11 )
{
int V_39 ;
unsigned long * V_40 = ( unsigned long * ) V_37 ;
F_24 ( ! F_25 ( V_38 , sizeof( unsigned long ) ) ) ;
if ( F_26 ( V_11 == 0 ) ) {
memset ( V_37 , 0 , V_38 ) ;
} else {
for ( V_39 = 0 ; V_39 < V_38 / sizeof( * V_40 ) ; V_39 ++ )
V_40 [ V_39 ] = V_11 ;
}
}
static bool F_27 ( void * V_37 , unsigned long * V_12 )
{
unsigned int V_41 ;
unsigned long * V_40 ;
unsigned long V_42 ;
V_40 = ( unsigned long * ) V_37 ;
V_42 = V_40 [ 0 ] ;
for ( V_41 = 1 ; V_41 < V_19 / sizeof( * V_40 ) ; V_41 ++ ) {
if ( V_42 != V_40 [ V_41 ] )
return false ;
}
* V_12 = V_42 ;
return true ;
}
static T_5 F_28 ( struct V_3 * V_4 ,
struct V_43 * V_44 , char * V_45 )
{
T_1 V_42 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
F_29 ( & V_1 -> V_46 ) ;
V_42 = F_1 ( V_1 ) ;
F_30 ( & V_1 -> V_46 ) ;
return F_31 ( V_45 , V_19 , L_1 , V_42 ) ;
}
static T_5 F_32 ( struct V_3 * V_4 ,
struct V_43 * V_44 , char * V_45 )
{
struct V_1 * V_1 = F_2 ( V_4 ) ;
return F_31 ( V_45 , V_19 , L_2 , V_1 -> V_2 ) ;
}
static T_5 F_33 ( struct V_3 * V_4 ,
struct V_43 * V_44 , const char * V_45 , T_2 V_38 )
{
T_4 V_47 ;
char * V_48 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
V_47 = F_34 ( V_45 , & V_48 ) ;
if ( V_45 == V_48 )
return - V_49 ;
F_35 ( & V_1 -> V_46 ) ;
V_1 -> V_50 = F_36 ( V_47 ) >> V_51 ;
F_37 ( & V_1 -> V_46 ) ;
return V_38 ;
}
static T_5 F_38 ( struct V_3 * V_4 ,
struct V_43 * V_44 , const char * V_45 , T_2 V_38 )
{
int V_52 ;
unsigned long V_42 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
V_52 = F_39 ( V_45 , 10 , & V_42 ) ;
if ( V_52 || V_42 != 0 )
return - V_49 ;
F_29 ( & V_1 -> V_46 ) ;
if ( F_1 ( V_1 ) ) {
F_40 ( & V_1 -> V_35 . V_36 ,
F_41 ( V_1 -> V_53 ) ) ;
}
F_30 ( & V_1 -> V_46 ) ;
return V_38 ;
}
static T_5 F_42 ( struct V_3 * V_4 ,
struct V_43 * V_44 , char * V_45 )
{
return F_31 ( V_45 , V_19 , L_3 , F_43 () ) ;
}
static T_5 F_44 ( struct V_3 * V_4 ,
struct V_43 * V_44 , const char * V_45 , T_2 V_38 )
{
return V_38 ;
}
static T_5 F_45 ( struct V_3 * V_4 ,
struct V_43 * V_44 , char * V_45 )
{
T_2 V_54 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
F_29 ( & V_1 -> V_46 ) ;
V_54 = F_46 ( V_1 -> V_55 , V_45 ) ;
F_30 ( & V_1 -> V_46 ) ;
return V_54 ;
}
static T_5 F_47 ( struct V_3 * V_4 ,
struct V_43 * V_44 , const char * V_45 , T_2 V_38 )
{
struct V_1 * V_1 = F_2 ( V_4 ) ;
char V_55 [ V_56 ] ;
T_2 V_54 ;
F_48 ( V_55 , V_45 , sizeof( V_55 ) ) ;
V_54 = strlen ( V_55 ) ;
if ( V_54 > 0 && V_55 [ V_54 - 1 ] == '\n' )
V_55 [ V_54 - 1 ] = 0x00 ;
if ( ! F_49 ( V_55 ) )
return - V_49 ;
F_35 ( & V_1 -> V_46 ) ;
if ( F_1 ( V_1 ) ) {
F_37 ( & V_1 -> V_46 ) ;
F_50 ( L_4 ) ;
return - V_57 ;
}
F_48 ( V_1 -> V_55 , V_55 , sizeof( V_55 ) ) ;
F_37 ( & V_1 -> V_46 ) ;
return V_38 ;
}
static T_5 F_51 ( struct V_3 * V_4 ,
struct V_43 * V_44 , const char * V_45 , T_2 V_38 )
{
struct V_1 * V_1 = F_2 ( V_4 ) ;
F_29 ( & V_1 -> V_46 ) ;
if ( ! F_1 ( V_1 ) ) {
F_30 ( & V_1 -> V_46 ) ;
return - V_49 ;
}
F_52 ( V_1 -> V_53 ) ;
F_30 ( & V_1 -> V_46 ) ;
return V_38 ;
}
static T_5 F_53 ( struct V_3 * V_4 ,
struct V_43 * V_44 , char * V_45 )
{
struct V_1 * V_1 = F_2 ( V_4 ) ;
T_5 V_58 ;
F_29 ( & V_1 -> V_46 ) ;
V_58 = F_31 ( V_45 , V_19 ,
L_5 ,
( T_4 ) F_54 ( & V_1 -> V_35 . V_59 ) ,
( T_4 ) F_54 ( & V_1 -> V_35 . V_60 ) ,
( T_4 ) F_54 ( & V_1 -> V_35 . V_61 ) ,
( T_4 ) F_54 ( & V_1 -> V_35 . V_62 ) ) ;
F_30 ( & V_1 -> V_46 ) ;
return V_58 ;
}
static T_5 F_55 ( struct V_3 * V_4 ,
struct V_43 * V_44 , char * V_45 )
{
struct V_1 * V_1 = F_2 ( V_4 ) ;
struct V_63 V_64 ;
T_4 V_65 , V_66 = 0 ;
long V_67 ;
T_5 V_58 ;
memset ( & V_64 , 0x00 , sizeof( struct V_63 ) ) ;
F_29 ( & V_1 -> V_46 ) ;
if ( F_1 ( V_1 ) ) {
V_66 = F_41 ( V_1 -> V_53 ) ;
V_63 ( V_1 -> V_53 , & V_64 ) ;
}
V_65 = F_54 ( & V_1 -> V_35 . V_68 ) ;
V_67 = F_21 ( & V_1 -> V_35 . V_36 ) ;
V_58 = F_31 ( V_45 , V_19 ,
L_6 ,
V_65 << V_51 ,
( T_4 ) F_54 ( & V_1 -> V_35 . V_69 ) ,
V_66 << V_51 ,
V_1 -> V_50 << V_51 ,
V_67 << V_51 ,
( T_4 ) F_54 ( & V_1 -> V_35 . V_70 ) ,
V_64 . V_71 ) ;
F_30 ( & V_1 -> V_46 ) ;
return V_58 ;
}
static T_5 F_56 ( struct V_3 * V_4 ,
struct V_43 * V_44 , char * V_45 )
{
int V_72 = 1 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
T_5 V_58 ;
F_29 ( & V_1 -> V_46 ) ;
V_58 = F_31 ( V_45 , V_19 ,
L_7 ,
V_72 ,
( T_4 ) F_54 ( & V_1 -> V_35 . V_73 ) ) ;
F_30 ( & V_1 -> V_46 ) ;
return V_58 ;
}
static void F_57 ( struct V_1 * V_1 , T_1 V_6 )
{
F_58 ( V_74 , & V_1 -> V_7 [ V_6 ] . V_11 ) ;
}
static void F_59 ( struct V_1 * V_1 , T_1 V_6 )
{
F_60 ( V_74 , & V_1 -> V_7 [ V_6 ] . V_11 ) ;
}
static bool F_61 ( struct V_1 * V_1 , T_1 V_6 ,
struct V_40 * V_40 ,
unsigned int V_31 , unsigned int V_38 )
{
F_57 ( V_1 , V_6 ) ;
if ( F_18 ( ! F_4 ( V_1 , V_6 ) ||
F_6 ( V_1 , V_6 , V_75 ) ) ) {
void * V_76 ;
F_59 ( V_1 , V_6 ) ;
V_76 = F_62 ( V_40 ) ;
F_23 ( V_76 + V_31 , V_38 ,
F_11 ( V_1 , V_6 ) ) ;
F_63 ( V_76 ) ;
return true ;
}
F_59 ( V_1 , V_6 ) ;
return false ;
}
static bool F_64 ( struct V_1 * V_1 , T_1 V_6 ,
struct V_40 * V_40 )
{
unsigned long V_12 ;
void * V_76 = F_62 ( V_40 ) ;
if ( F_27 ( V_76 , & V_12 ) ) {
F_63 ( V_76 ) ;
F_57 ( V_1 , V_6 ) ;
F_65 ( V_1 , V_6 ) ;
F_8 ( V_1 , V_6 , V_75 ) ;
F_10 ( V_1 , V_6 , V_12 ) ;
F_59 ( V_1 , V_6 ) ;
F_66 ( & V_1 -> V_35 . V_70 ) ;
return true ;
}
F_63 ( V_76 ) ;
return false ;
}
static void F_67 ( struct V_1 * V_1 , T_4 V_2 )
{
T_2 V_77 = V_2 >> V_51 ;
T_2 V_6 ;
for ( V_6 = 0 ; V_6 < V_77 ; V_6 ++ )
F_65 ( V_1 , V_6 ) ;
F_68 ( V_1 -> V_53 ) ;
F_69 ( V_1 -> V_7 ) ;
}
static bool F_70 ( struct V_1 * V_1 , T_4 V_2 )
{
T_2 V_77 ;
V_77 = V_2 >> V_51 ;
V_1 -> V_7 = F_71 ( V_77 * sizeof( * V_1 -> V_7 ) ) ;
if ( ! V_1 -> V_7 )
return false ;
V_1 -> V_53 = F_72 ( V_1 -> V_20 -> V_78 ) ;
if ( ! V_1 -> V_53 ) {
F_69 ( V_1 -> V_7 ) ;
return false ;
}
return true ;
}
static void F_65 ( struct V_1 * V_1 , T_2 V_6 )
{
unsigned long V_8 = F_4 ( V_1 , V_6 ) ;
if ( F_6 ( V_1 , V_6 , V_75 ) ) {
F_9 ( V_1 , V_6 , V_75 ) ;
F_10 ( V_1 , V_6 , 0 ) ;
F_73 ( & V_1 -> V_35 . V_70 ) ;
return;
}
if ( ! V_8 )
return;
F_74 ( V_1 -> V_53 , V_8 ) ;
F_75 ( F_12 ( V_1 , V_6 ) ,
& V_1 -> V_35 . V_69 ) ;
F_73 ( & V_1 -> V_35 . V_68 ) ;
F_5 ( V_1 , V_6 , 0 ) ;
F_13 ( V_1 , V_6 , 0 ) ;
}
static int F_76 ( struct V_1 * V_1 , struct V_40 * V_40 , T_1 V_6 )
{
int V_58 ;
unsigned long V_8 ;
unsigned int V_14 ;
void * V_79 , * V_80 ;
if ( F_61 ( V_1 , V_6 , V_40 , 0 , V_19 ) )
return 0 ;
F_57 ( V_1 , V_6 ) ;
V_8 = F_4 ( V_1 , V_6 ) ;
V_14 = F_12 ( V_1 , V_6 ) ;
V_79 = F_77 ( V_1 -> V_53 , V_8 , V_81 ) ;
if ( V_14 == V_19 ) {
V_80 = F_62 ( V_40 ) ;
memcpy ( V_80 , V_79 , V_19 ) ;
F_63 ( V_80 ) ;
V_58 = 0 ;
} else {
struct V_82 * V_83 = F_78 ( V_1 -> V_84 ) ;
V_80 = F_62 ( V_40 ) ;
V_58 = F_79 ( V_83 , V_79 , V_14 , V_80 ) ;
F_63 ( V_80 ) ;
F_80 ( V_1 -> V_84 ) ;
}
F_81 ( V_1 -> V_53 , V_8 ) ;
F_59 ( V_1 , V_6 ) ;
if ( F_18 ( V_58 ) )
F_82 ( L_8 , V_58 , V_6 ) ;
return V_58 ;
}
static int F_83 ( struct V_1 * V_1 , struct V_16 * V_17 ,
T_1 V_6 , int V_31 )
{
int V_58 ;
struct V_40 * V_40 ;
V_40 = V_17 -> V_85 ;
if ( F_14 ( V_17 ) ) {
V_40 = F_84 ( V_86 | V_87 ) ;
if ( ! V_40 )
return - V_88 ;
}
V_58 = F_76 ( V_1 , V_40 , V_6 ) ;
if ( F_18 ( V_58 ) )
goto V_89;
if ( F_14 ( V_17 ) ) {
void * V_80 = F_62 ( V_17 -> V_85 ) ;
void * V_79 = F_62 ( V_40 ) ;
memcpy ( V_80 + V_17 -> V_90 , V_79 + V_31 , V_17 -> V_18 ) ;
F_63 ( V_79 ) ;
F_63 ( V_80 ) ;
}
V_89:
if ( F_14 ( V_17 ) )
F_85 ( V_40 ) ;
return V_58 ;
}
static int F_86 ( struct V_1 * V_1 , struct V_82 * * V_83 ,
struct V_40 * V_40 ,
unsigned long * V_91 , unsigned int * V_92 )
{
int V_58 ;
unsigned int V_93 ;
void * V_79 ;
unsigned long V_94 ;
unsigned long V_8 = 0 ;
V_95:
V_79 = F_62 ( V_40 ) ;
V_58 = F_87 ( * V_83 , V_79 , & V_93 ) ;
F_63 ( V_79 ) ;
if ( F_18 ( V_58 ) ) {
F_82 ( L_9 , V_58 ) ;
if ( V_8 )
F_74 ( V_1 -> V_53 , V_8 ) ;
return V_58 ;
}
if ( F_18 ( V_93 > V_96 ) )
V_93 = V_19 ;
if ( ! V_8 )
V_8 = F_88 ( V_1 -> V_53 , V_93 ,
V_97 |
V_98 |
V_87 |
V_99 ) ;
if ( ! V_8 ) {
F_80 ( V_1 -> V_84 ) ;
F_66 ( & V_1 -> V_35 . V_73 ) ;
V_8 = F_88 ( V_1 -> V_53 , V_93 ,
V_86 | V_87 |
V_99 ) ;
* V_83 = F_78 ( V_1 -> V_84 ) ;
if ( V_8 )
goto V_95;
return - V_88 ;
}
V_94 = F_41 ( V_1 -> V_53 ) ;
F_20 ( V_1 , V_94 ) ;
if ( V_1 -> V_50 && V_94 > V_1 -> V_50 ) {
F_74 ( V_1 -> V_53 , V_8 ) ;
return - V_88 ;
}
* V_91 = V_8 ;
* V_92 = V_93 ;
return 0 ;
}
static int F_89 ( struct V_1 * V_1 , struct V_16 * V_17 , T_1 V_6 )
{
int V_58 ;
unsigned long V_8 ;
unsigned int V_93 ;
void * V_79 , * V_80 ;
struct V_82 * V_83 ;
struct V_40 * V_40 = V_17 -> V_85 ;
if ( F_64 ( V_1 , V_6 , V_40 ) )
return 0 ;
V_83 = F_78 ( V_1 -> V_84 ) ;
V_58 = F_86 ( V_1 , & V_83 , V_40 , & V_8 , & V_93 ) ;
if ( V_58 ) {
F_80 ( V_1 -> V_84 ) ;
return V_58 ;
}
V_80 = F_77 ( V_1 -> V_53 , V_8 , V_100 ) ;
V_79 = V_83 -> V_101 ;
if ( V_93 == V_19 )
V_79 = F_62 ( V_40 ) ;
memcpy ( V_80 , V_79 , V_93 ) ;
if ( V_93 == V_19 )
F_63 ( V_79 ) ;
F_80 ( V_1 -> V_84 ) ;
F_81 ( V_1 -> V_53 , V_8 ) ;
F_57 ( V_1 , V_6 ) ;
F_65 ( V_1 , V_6 ) ;
F_5 ( V_1 , V_6 , V_8 ) ;
F_13 ( V_1 , V_6 , V_93 ) ;
F_59 ( V_1 , V_6 ) ;
F_90 ( V_93 , & V_1 -> V_35 . V_69 ) ;
F_66 ( & V_1 -> V_35 . V_68 ) ;
return 0 ;
}
static int F_91 ( struct V_1 * V_1 , struct V_16 * V_17 ,
T_1 V_6 , int V_31 )
{
int V_58 ;
struct V_40 * V_40 = NULL ;
void * V_79 ;
struct V_16 V_102 ;
V_102 = * V_17 ;
if ( F_14 ( V_17 ) ) {
void * V_80 ;
V_40 = F_84 ( V_86 | V_87 ) ;
if ( ! V_40 )
return - V_88 ;
V_58 = F_76 ( V_1 , V_40 , V_6 ) ;
if ( V_58 )
goto V_89;
V_79 = F_62 ( V_17 -> V_85 ) ;
V_80 = F_62 ( V_40 ) ;
memcpy ( V_80 + V_31 , V_79 + V_17 -> V_90 , V_17 -> V_18 ) ;
F_63 ( V_80 ) ;
F_63 ( V_79 ) ;
V_102 . V_85 = V_40 ;
V_102 . V_18 = V_19 ;
V_102 . V_90 = 0 ;
}
V_58 = F_89 ( V_1 , & V_102 , V_6 ) ;
V_89:
if ( F_14 ( V_17 ) )
F_85 ( V_40 ) ;
return V_58 ;
}
static void F_92 ( struct V_1 * V_1 , T_1 V_6 ,
int V_31 , struct V_103 * V_103 )
{
T_2 V_104 = V_103 -> V_105 . V_106 ;
if ( V_31 ) {
if ( V_104 <= ( V_19 - V_31 ) )
return;
V_104 -= ( V_19 - V_31 ) ;
V_6 ++ ;
}
while ( V_104 >= V_19 ) {
F_57 ( V_1 , V_6 ) ;
F_65 ( V_1 , V_6 ) ;
F_59 ( V_1 , V_6 ) ;
F_66 ( & V_1 -> V_35 . V_62 ) ;
V_6 ++ ;
V_104 -= V_19 ;
}
}
static int F_93 ( struct V_1 * V_1 , struct V_16 * V_17 , T_1 V_6 ,
int V_31 , bool V_107 )
{
unsigned long V_108 = V_109 ;
int V_110 = V_107 ? V_111 : V_112 ;
int V_58 ;
F_94 ( V_110 , V_17 -> V_18 >> V_30 ,
& V_1 -> V_20 -> V_113 ) ;
if ( ! V_107 ) {
F_66 ( & V_1 -> V_35 . V_114 ) ;
V_58 = F_83 ( V_1 , V_17 , V_6 , V_31 ) ;
F_95 ( V_17 -> V_85 ) ;
} else {
F_66 ( & V_1 -> V_35 . V_115 ) ;
V_58 = F_91 ( V_1 , V_17 , V_6 , V_31 ) ;
}
F_96 ( V_110 , & V_1 -> V_20 -> V_113 , V_108 ) ;
if ( F_18 ( V_58 ) ) {
if ( ! V_107 )
F_66 ( & V_1 -> V_35 . V_59 ) ;
else
F_66 ( & V_1 -> V_35 . V_60 ) ;
}
return V_58 ;
}
static void F_97 ( struct V_1 * V_1 , struct V_103 * V_103 )
{
int V_31 ;
T_1 V_6 ;
struct V_16 V_17 ;
struct V_116 V_117 ;
V_6 = V_103 -> V_105 . V_118 >> V_119 ;
V_31 = ( V_103 -> V_105 . V_118 &
( V_120 - 1 ) ) << V_30 ;
switch ( F_98 ( V_103 ) ) {
case V_121 :
case V_122 :
F_92 ( V_1 , V_6 , V_31 , V_103 ) ;
F_99 ( V_103 ) ;
return;
default:
break;
}
F_100 (bvec, bio, iter) {
struct V_16 V_123 = V_17 ;
unsigned int V_124 = V_17 . V_18 ;
do {
V_123 . V_18 = F_101 (unsigned int, PAGE_SIZE - offset,
unwritten) ;
if ( F_93 ( V_1 , & V_123 , V_6 , V_31 ,
F_102 ( F_98 ( V_103 ) ) ) < 0 )
goto V_89;
V_123 . V_90 += V_123 . V_18 ;
V_124 -= V_123 . V_18 ;
F_19 ( & V_6 , & V_31 , & V_123 ) ;
} while ( V_124 );
}
F_99 ( V_103 ) ;
return;
V_89:
F_103 ( V_103 ) ;
}
static T_6 F_104 ( struct V_125 * V_21 , struct V_103 * V_103 )
{
struct V_1 * V_1 = V_21 -> V_126 ;
if ( ! F_17 ( V_1 , V_103 -> V_105 . V_118 ,
V_103 -> V_105 . V_106 ) ) {
F_66 ( & V_1 -> V_35 . V_61 ) ;
goto error;
}
F_97 ( V_1 , V_103 ) ;
return V_127 ;
error:
F_103 ( V_103 ) ;
return V_127 ;
}
static void F_105 ( struct V_128 * V_129 ,
unsigned long V_6 )
{
struct V_1 * V_1 ;
V_1 = V_129 -> V_130 -> V_5 ;
F_57 ( V_1 , V_6 ) ;
F_65 ( V_1 , V_6 ) ;
F_59 ( V_1 , V_6 ) ;
F_66 ( & V_1 -> V_35 . V_62 ) ;
}
static int F_106 ( struct V_128 * V_129 , T_3 V_131 ,
struct V_40 * V_40 , bool V_107 )
{
int V_31 , V_52 = - V_132 ;
T_1 V_6 ;
struct V_1 * V_1 ;
struct V_16 V_123 ;
V_1 = V_129 -> V_130 -> V_5 ;
if ( ! F_17 ( V_1 , V_131 , V_19 ) ) {
F_66 ( & V_1 -> V_35 . V_61 ) ;
V_52 = - V_49 ;
goto V_89;
}
V_6 = V_131 >> V_119 ;
V_31 = ( V_131 & ( V_120 - 1 ) ) << V_30 ;
V_123 . V_85 = V_40 ;
V_123 . V_18 = V_19 ;
V_123 . V_90 = 0 ;
V_52 = F_93 ( V_1 , & V_123 , V_6 , V_31 , V_107 ) ;
V_89:
if ( V_52 == 0 )
F_107 ( V_40 , V_107 , 0 ) ;
return V_52 ;
}
static void F_108 ( struct V_1 * V_1 )
{
struct V_133 * V_84 ;
T_4 V_2 ;
F_35 ( & V_1 -> V_46 ) ;
V_1 -> V_50 = 0 ;
if ( ! F_1 ( V_1 ) ) {
F_37 ( & V_1 -> V_46 ) ;
return;
}
V_84 = V_1 -> V_84 ;
V_2 = V_1 -> V_2 ;
V_1 -> V_2 = 0 ;
F_109 ( V_1 -> V_20 , 0 ) ;
F_110 ( & V_1 -> V_20 -> V_113 , 0 ) ;
F_37 ( & V_1 -> V_46 ) ;
F_67 ( V_1 , V_2 ) ;
memset ( & V_1 -> V_35 , 0 , sizeof( V_1 -> V_35 ) ) ;
F_111 ( V_84 ) ;
}
static T_5 F_112 ( struct V_3 * V_4 ,
struct V_43 * V_44 , const char * V_45 , T_2 V_38 )
{
T_4 V_2 ;
struct V_133 * V_84 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
int V_52 ;
V_2 = F_34 ( V_45 , NULL ) ;
if ( ! V_2 )
return - V_49 ;
F_35 ( & V_1 -> V_46 ) ;
if ( F_1 ( V_1 ) ) {
F_50 ( L_10 ) ;
V_52 = - V_57 ;
goto V_134;
}
V_2 = F_36 ( V_2 ) ;
if ( ! F_70 ( V_1 , V_2 ) ) {
V_52 = - V_88 ;
goto V_134;
}
V_84 = F_113 ( V_1 -> V_55 ) ;
if ( F_114 ( V_84 ) ) {
F_82 ( L_11 ,
V_1 -> V_55 ) ;
V_52 = F_115 ( V_84 ) ;
goto V_135;
}
V_1 -> V_84 = V_84 ;
V_1 -> V_2 = V_2 ;
F_109 ( V_1 -> V_20 , V_1 -> V_2 >> V_30 ) ;
F_15 ( V_1 ) ;
F_37 ( & V_1 -> V_46 ) ;
return V_38 ;
V_135:
F_67 ( V_1 , V_2 ) ;
V_134:
F_37 ( & V_1 -> V_46 ) ;
return V_52 ;
}
static T_5 F_116 ( struct V_3 * V_4 ,
struct V_43 * V_44 , const char * V_45 , T_2 V_38 )
{
int V_58 ;
unsigned short V_136 ;
struct V_1 * V_1 ;
struct V_128 * V_129 ;
V_58 = F_117 ( V_45 , 10 , & V_136 ) ;
if ( V_58 )
return V_58 ;
if ( ! V_136 )
return - V_49 ;
V_1 = F_2 ( V_4 ) ;
V_129 = F_118 ( V_1 -> V_20 , 0 ) ;
if ( ! V_129 )
return - V_88 ;
F_119 ( & V_129 -> V_137 ) ;
if ( V_129 -> V_138 || V_1 -> V_139 ) {
F_120 ( & V_129 -> V_137 ) ;
F_121 ( V_129 ) ;
return - V_57 ;
}
V_1 -> V_139 = true ;
F_120 ( & V_129 -> V_137 ) ;
F_122 ( V_129 ) ;
F_108 ( V_1 ) ;
F_15 ( V_1 ) ;
F_121 ( V_129 ) ;
F_119 ( & V_129 -> V_137 ) ;
V_1 -> V_139 = false ;
F_120 ( & V_129 -> V_137 ) ;
return V_38 ;
}
static int F_123 ( struct V_128 * V_129 , T_7 V_140 )
{
int V_58 = 0 ;
struct V_1 * V_1 ;
F_124 ( ! F_125 ( & V_129 -> V_137 ) ) ;
V_1 = V_129 -> V_130 -> V_5 ;
if ( V_1 -> V_139 )
V_58 = - V_57 ;
return V_58 ;
}
static int F_126 ( void )
{
struct V_1 * V_1 ;
struct V_125 * V_21 ;
int V_58 , V_141 ;
V_1 = F_127 ( sizeof( struct V_1 ) , V_142 ) ;
if ( ! V_1 )
return - V_88 ;
V_58 = F_128 ( & V_143 , V_1 , 0 , 0 , V_142 ) ;
if ( V_58 < 0 )
goto V_144;
V_141 = V_58 ;
F_129 ( & V_1 -> V_46 ) ;
V_21 = F_130 ( V_142 ) ;
if ( ! V_21 ) {
F_82 ( L_12 ,
V_141 ) ;
V_58 = - V_88 ;
goto V_145;
}
F_131 ( V_21 , F_104 ) ;
V_1 -> V_20 = F_132 ( 1 ) ;
if ( ! V_1 -> V_20 ) {
F_82 ( L_13 ,
V_141 ) ;
V_58 = - V_88 ;
goto V_146;
}
V_1 -> V_20 -> V_147 = V_148 ;
V_1 -> V_20 -> V_149 = V_141 ;
V_1 -> V_20 -> V_150 = & V_151 ;
V_1 -> V_20 -> V_21 = V_21 ;
V_1 -> V_20 -> V_21 -> V_126 = V_1 ;
V_1 -> V_20 -> V_5 = V_1 ;
snprintf ( V_1 -> V_20 -> V_78 , 16 , L_14 , V_141 ) ;
F_109 ( V_1 -> V_20 , 0 ) ;
F_133 ( V_152 , V_1 -> V_20 -> V_21 ) ;
F_134 ( V_153 , V_1 -> V_20 -> V_21 ) ;
F_135 ( V_1 -> V_20 -> V_21 , V_19 ) ;
F_136 ( V_1 -> V_20 -> V_21 ,
V_29 ) ;
F_137 ( V_1 -> V_20 -> V_21 , V_19 ) ;
F_138 ( V_1 -> V_20 -> V_21 , V_19 ) ;
V_1 -> V_20 -> V_21 -> V_154 . V_155 = V_19 ;
F_139 ( V_1 -> V_20 -> V_21 , V_156 ) ;
F_133 ( V_157 , V_1 -> V_20 -> V_21 ) ;
if ( V_29 == V_19 )
F_140 ( V_1 -> V_20 -> V_21 , V_156 ) ;
F_141 ( V_1 -> V_20 ) ;
V_58 = F_142 ( & F_143 ( V_1 -> V_20 ) -> V_158 ,
& V_159 ) ;
if ( V_58 < 0 ) {
F_82 ( L_15 ,
V_141 ) ;
goto V_160;
}
F_48 ( V_1 -> V_55 , V_161 , sizeof( V_1 -> V_55 ) ) ;
F_50 ( L_16 , V_1 -> V_20 -> V_78 ) ;
return V_141 ;
V_160:
F_144 ( V_1 -> V_20 ) ;
F_145 ( V_1 -> V_20 ) ;
V_146:
F_146 ( V_21 ) ;
V_145:
F_147 ( & V_143 , V_141 ) ;
V_144:
F_148 ( V_1 ) ;
return V_58 ;
}
static int F_149 ( struct V_1 * V_1 )
{
struct V_128 * V_129 ;
V_129 = F_118 ( V_1 -> V_20 , 0 ) ;
if ( ! V_129 )
return - V_88 ;
F_119 ( & V_129 -> V_137 ) ;
if ( V_129 -> V_138 || V_1 -> V_139 ) {
F_120 ( & V_129 -> V_137 ) ;
F_121 ( V_129 ) ;
return - V_57 ;
}
V_1 -> V_139 = true ;
F_120 ( & V_129 -> V_137 ) ;
F_150 ( & F_143 ( V_1 -> V_20 ) -> V_158 ,
& V_159 ) ;
F_122 ( V_129 ) ;
F_108 ( V_1 ) ;
F_121 ( V_129 ) ;
F_50 ( L_17 , V_1 -> V_20 -> V_78 ) ;
F_146 ( V_1 -> V_20 -> V_21 ) ;
F_144 ( V_1 -> V_20 ) ;
F_145 ( V_1 -> V_20 ) ;
F_148 ( V_1 ) ;
return 0 ;
}
static T_5 F_151 ( struct V_162 * V_162 ,
struct V_163 * V_44 ,
char * V_45 )
{
int V_58 ;
F_119 ( & V_164 ) ;
V_58 = F_126 () ;
F_120 ( & V_164 ) ;
if ( V_58 < 0 )
return V_58 ;
return F_31 ( V_45 , V_19 , L_3 , V_58 ) ;
}
static T_5 F_152 ( struct V_162 * V_162 ,
struct V_163 * V_44 ,
const char * V_45 ,
T_2 V_165 )
{
struct V_1 * V_1 ;
int V_58 , V_166 ;
V_58 = F_153 ( V_45 , 10 , & V_166 ) ;
if ( V_58 )
return V_58 ;
if ( V_166 < 0 )
return - V_49 ;
F_119 ( & V_164 ) ;
V_1 = F_154 ( & V_143 , V_166 ) ;
if ( V_1 ) {
V_58 = F_149 ( V_1 ) ;
if ( ! V_58 )
F_147 ( & V_143 , V_166 ) ;
} else {
V_58 = - V_167 ;
}
F_120 ( & V_164 ) ;
return V_58 ? V_58 : V_165 ;
}
static int F_155 ( int V_168 , void * V_37 , void * V_169 )
{
F_149 ( V_37 ) ;
return 0 ;
}
static void F_156 ( void )
{
F_157 ( & V_170 ) ;
F_158 ( & V_143 , & F_155 , NULL ) ;
F_159 ( & V_143 ) ;
F_160 ( V_148 , L_18 ) ;
F_161 ( V_171 ) ;
}
static int T_8 F_162 ( void )
{
int V_58 ;
V_58 = F_163 ( V_171 , L_19 ,
V_172 , V_173 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_164 ( & V_170 ) ;
if ( V_58 ) {
F_82 ( L_20 ) ;
F_161 ( V_171 ) ;
return V_58 ;
}
V_148 = F_165 ( 0 , L_18 ) ;
if ( V_148 <= 0 ) {
F_82 ( L_21 ) ;
F_157 ( & V_170 ) ;
F_161 ( V_171 ) ;
return - V_57 ;
}
while ( V_174 != 0 ) {
F_119 ( & V_164 ) ;
V_58 = F_126 () ;
F_120 ( & V_164 ) ;
if ( V_58 < 0 )
goto V_175;
V_174 -- ;
}
return 0 ;
V_175:
F_156 () ;
return V_58 ;
}
static void T_9 F_166 ( void )
{
F_156 () ;
}
