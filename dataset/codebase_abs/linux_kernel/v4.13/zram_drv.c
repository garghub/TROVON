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
char V_55 [ F_48 ( V_1 -> V_55 ) ] ;
T_2 V_54 ;
F_49 ( V_55 , V_45 , sizeof( V_55 ) ) ;
V_54 = strlen ( V_55 ) ;
if ( V_54 > 0 && V_55 [ V_54 - 1 ] == '\n' )
V_55 [ V_54 - 1 ] = 0x00 ;
if ( ! F_50 ( V_55 ) )
return - V_49 ;
F_35 ( & V_1 -> V_46 ) ;
if ( F_1 ( V_1 ) ) {
F_37 ( & V_1 -> V_46 ) ;
F_51 ( L_4 ) ;
return - V_56 ;
}
strcpy ( V_1 -> V_55 , V_55 ) ;
F_37 ( & V_1 -> V_46 ) ;
return V_38 ;
}
static T_5 F_52 ( struct V_3 * V_4 ,
struct V_43 * V_44 , const char * V_45 , T_2 V_38 )
{
struct V_1 * V_1 = F_2 ( V_4 ) ;
F_29 ( & V_1 -> V_46 ) ;
if ( ! F_1 ( V_1 ) ) {
F_30 ( & V_1 -> V_46 ) ;
return - V_49 ;
}
F_53 ( V_1 -> V_53 ) ;
F_30 ( & V_1 -> V_46 ) ;
return V_38 ;
}
static T_5 F_54 ( struct V_3 * V_4 ,
struct V_43 * V_44 , char * V_45 )
{
struct V_1 * V_1 = F_2 ( V_4 ) ;
T_5 V_57 ;
F_29 ( & V_1 -> V_46 ) ;
V_57 = F_31 ( V_45 , V_19 ,
L_5 ,
( T_4 ) F_55 ( & V_1 -> V_35 . V_58 ) ,
( T_4 ) F_55 ( & V_1 -> V_35 . V_59 ) ,
( T_4 ) F_55 ( & V_1 -> V_35 . V_60 ) ,
( T_4 ) F_55 ( & V_1 -> V_35 . V_61 ) ) ;
F_30 ( & V_1 -> V_46 ) ;
return V_57 ;
}
static T_5 F_56 ( struct V_3 * V_4 ,
struct V_43 * V_44 , char * V_45 )
{
struct V_1 * V_1 = F_2 ( V_4 ) ;
struct V_62 V_63 ;
T_4 V_64 , V_65 = 0 ;
long V_66 ;
T_5 V_57 ;
memset ( & V_63 , 0x00 , sizeof( struct V_62 ) ) ;
F_29 ( & V_1 -> V_46 ) ;
if ( F_1 ( V_1 ) ) {
V_65 = F_41 ( V_1 -> V_53 ) ;
V_62 ( V_1 -> V_53 , & V_63 ) ;
}
V_64 = F_55 ( & V_1 -> V_35 . V_67 ) ;
V_66 = F_21 ( & V_1 -> V_35 . V_36 ) ;
V_57 = F_31 ( V_45 , V_19 ,
L_6 ,
V_64 << V_51 ,
( T_4 ) F_55 ( & V_1 -> V_35 . V_68 ) ,
V_65 << V_51 ,
V_1 -> V_50 << V_51 ,
V_66 << V_51 ,
( T_4 ) F_55 ( & V_1 -> V_35 . V_69 ) ,
V_63 . V_70 ) ;
F_30 ( & V_1 -> V_46 ) ;
return V_57 ;
}
static T_5 F_57 ( struct V_3 * V_4 ,
struct V_43 * V_44 , char * V_45 )
{
int V_71 = 1 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
T_5 V_57 ;
F_29 ( & V_1 -> V_46 ) ;
V_57 = F_31 ( V_45 , V_19 ,
L_7 ,
V_71 ,
( T_4 ) F_55 ( & V_1 -> V_35 . V_72 ) ) ;
F_30 ( & V_1 -> V_46 ) ;
return V_57 ;
}
static void F_58 ( struct V_1 * V_1 , T_1 V_6 )
{
F_59 ( V_73 , & V_1 -> V_7 [ V_6 ] . V_11 ) ;
}
static void F_60 ( struct V_1 * V_1 , T_1 V_6 )
{
F_61 ( V_73 , & V_1 -> V_7 [ V_6 ] . V_11 ) ;
}
static bool F_62 ( struct V_1 * V_1 , T_1 V_6 ,
struct V_40 * V_40 ,
unsigned int V_31 , unsigned int V_38 )
{
F_58 ( V_1 , V_6 ) ;
if ( F_18 ( ! F_4 ( V_1 , V_6 ) ||
F_6 ( V_1 , V_6 , V_74 ) ) ) {
void * V_75 ;
F_60 ( V_1 , V_6 ) ;
V_75 = F_63 ( V_40 ) ;
F_23 ( V_75 + V_31 , V_38 ,
F_11 ( V_1 , V_6 ) ) ;
F_64 ( V_75 ) ;
return true ;
}
F_60 ( V_1 , V_6 ) ;
return false ;
}
static bool F_65 ( struct V_1 * V_1 , T_1 V_6 ,
struct V_40 * V_40 )
{
unsigned long V_12 ;
void * V_75 = F_63 ( V_40 ) ;
if ( F_27 ( V_75 , & V_12 ) ) {
F_64 ( V_75 ) ;
F_58 ( V_1 , V_6 ) ;
F_66 ( V_1 , V_6 ) ;
F_8 ( V_1 , V_6 , V_74 ) ;
F_10 ( V_1 , V_6 , V_12 ) ;
F_60 ( V_1 , V_6 ) ;
F_67 ( & V_1 -> V_35 . V_69 ) ;
F_67 ( & V_1 -> V_35 . V_67 ) ;
return true ;
}
F_64 ( V_75 ) ;
return false ;
}
static void F_68 ( struct V_1 * V_1 , T_4 V_2 )
{
T_2 V_76 = V_2 >> V_51 ;
T_2 V_6 ;
for ( V_6 = 0 ; V_6 < V_76 ; V_6 ++ )
F_66 ( V_1 , V_6 ) ;
F_69 ( V_1 -> V_53 ) ;
F_70 ( V_1 -> V_7 ) ;
}
static bool F_71 ( struct V_1 * V_1 , T_4 V_2 )
{
T_2 V_76 ;
V_76 = V_2 >> V_51 ;
V_1 -> V_7 = F_72 ( V_76 * sizeof( * V_1 -> V_7 ) ) ;
if ( ! V_1 -> V_7 )
return false ;
V_1 -> V_53 = F_73 ( V_1 -> V_20 -> V_77 ) ;
if ( ! V_1 -> V_53 ) {
F_70 ( V_1 -> V_7 ) ;
return false ;
}
return true ;
}
static void F_66 ( struct V_1 * V_1 , T_2 V_6 )
{
unsigned long V_8 = F_4 ( V_1 , V_6 ) ;
if ( F_6 ( V_1 , V_6 , V_74 ) ) {
F_9 ( V_1 , V_6 , V_74 ) ;
F_10 ( V_1 , V_6 , 0 ) ;
F_74 ( & V_1 -> V_35 . V_69 ) ;
F_74 ( & V_1 -> V_35 . V_67 ) ;
return;
}
if ( ! V_8 )
return;
F_75 ( V_1 -> V_53 , V_8 ) ;
F_76 ( F_12 ( V_1 , V_6 ) ,
& V_1 -> V_35 . V_68 ) ;
F_74 ( & V_1 -> V_35 . V_67 ) ;
F_5 ( V_1 , V_6 , 0 ) ;
F_13 ( V_1 , V_6 , 0 ) ;
}
static int F_77 ( struct V_1 * V_1 , struct V_40 * V_40 , T_1 V_6 )
{
int V_57 ;
unsigned long V_8 ;
unsigned int V_14 ;
void * V_78 , * V_79 ;
if ( F_62 ( V_1 , V_6 , V_40 , 0 , V_19 ) )
return 0 ;
F_58 ( V_1 , V_6 ) ;
V_8 = F_4 ( V_1 , V_6 ) ;
V_14 = F_12 ( V_1 , V_6 ) ;
V_78 = F_78 ( V_1 -> V_53 , V_8 , V_80 ) ;
if ( V_14 == V_19 ) {
V_79 = F_63 ( V_40 ) ;
memcpy ( V_79 , V_78 , V_19 ) ;
F_64 ( V_79 ) ;
V_57 = 0 ;
} else {
struct V_81 * V_82 = F_79 ( V_1 -> V_83 ) ;
V_79 = F_63 ( V_40 ) ;
V_57 = F_80 ( V_82 , V_78 , V_14 , V_79 ) ;
F_64 ( V_79 ) ;
F_81 ( V_1 -> V_83 ) ;
}
F_82 ( V_1 -> V_53 , V_8 ) ;
F_60 ( V_1 , V_6 ) ;
if ( F_18 ( V_57 ) )
F_83 ( L_8 , V_57 , V_6 ) ;
return V_57 ;
}
static int F_84 ( struct V_1 * V_1 , struct V_16 * V_17 ,
T_1 V_6 , int V_31 )
{
int V_57 ;
struct V_40 * V_40 ;
V_40 = V_17 -> V_84 ;
if ( F_14 ( V_17 ) ) {
V_40 = F_85 ( V_85 | V_86 ) ;
if ( ! V_40 )
return - V_87 ;
}
V_57 = F_77 ( V_1 , V_40 , V_6 ) ;
if ( F_18 ( V_57 ) )
goto V_88;
if ( F_14 ( V_17 ) ) {
void * V_79 = F_63 ( V_17 -> V_84 ) ;
void * V_78 = F_63 ( V_40 ) ;
memcpy ( V_79 + V_17 -> V_89 , V_78 + V_31 , V_17 -> V_18 ) ;
F_64 ( V_78 ) ;
F_64 ( V_79 ) ;
}
V_88:
if ( F_14 ( V_17 ) )
F_86 ( V_40 ) ;
return V_57 ;
}
static int F_87 ( struct V_1 * V_1 , struct V_81 * * V_82 ,
struct V_40 * V_40 ,
unsigned long * V_90 , unsigned int * V_91 )
{
int V_57 ;
unsigned int V_92 ;
void * V_78 ;
unsigned long V_93 ;
unsigned long V_8 = 0 ;
V_94:
V_78 = F_63 ( V_40 ) ;
V_57 = F_88 ( * V_82 , V_78 , & V_92 ) ;
F_64 ( V_78 ) ;
if ( F_18 ( V_57 ) ) {
F_83 ( L_9 , V_57 ) ;
if ( V_8 )
F_75 ( V_1 -> V_53 , V_8 ) ;
return V_57 ;
}
if ( F_18 ( V_92 > V_95 ) )
V_92 = V_19 ;
if ( ! V_8 )
V_8 = F_89 ( V_1 -> V_53 , V_92 ,
V_96 |
V_97 |
V_86 |
V_98 ) ;
if ( ! V_8 ) {
F_81 ( V_1 -> V_83 ) ;
F_67 ( & V_1 -> V_35 . V_72 ) ;
V_8 = F_89 ( V_1 -> V_53 , V_92 ,
V_85 | V_86 |
V_98 ) ;
* V_82 = F_79 ( V_1 -> V_83 ) ;
if ( V_8 )
goto V_94;
return - V_87 ;
}
V_93 = F_41 ( V_1 -> V_53 ) ;
F_20 ( V_1 , V_93 ) ;
if ( V_1 -> V_50 && V_93 > V_1 -> V_50 ) {
F_75 ( V_1 -> V_53 , V_8 ) ;
return - V_87 ;
}
* V_90 = V_8 ;
* V_91 = V_92 ;
return 0 ;
}
static int F_90 ( struct V_1 * V_1 , struct V_16 * V_17 , T_1 V_6 )
{
int V_57 ;
unsigned long V_8 ;
unsigned int V_92 ;
void * V_78 , * V_79 ;
struct V_81 * V_82 ;
struct V_40 * V_40 = V_17 -> V_84 ;
if ( F_65 ( V_1 , V_6 , V_40 ) )
return 0 ;
V_82 = F_79 ( V_1 -> V_83 ) ;
V_57 = F_87 ( V_1 , & V_82 , V_40 , & V_8 , & V_92 ) ;
if ( V_57 ) {
F_81 ( V_1 -> V_83 ) ;
return V_57 ;
}
V_79 = F_78 ( V_1 -> V_53 , V_8 , V_99 ) ;
V_78 = V_82 -> V_100 ;
if ( V_92 == V_19 )
V_78 = F_63 ( V_40 ) ;
memcpy ( V_79 , V_78 , V_92 ) ;
if ( V_92 == V_19 )
F_64 ( V_78 ) ;
F_81 ( V_1 -> V_83 ) ;
F_82 ( V_1 -> V_53 , V_8 ) ;
F_58 ( V_1 , V_6 ) ;
F_66 ( V_1 , V_6 ) ;
F_5 ( V_1 , V_6 , V_8 ) ;
F_13 ( V_1 , V_6 , V_92 ) ;
F_60 ( V_1 , V_6 ) ;
F_91 ( V_92 , & V_1 -> V_35 . V_68 ) ;
F_67 ( & V_1 -> V_35 . V_67 ) ;
return 0 ;
}
static int F_92 ( struct V_1 * V_1 , struct V_16 * V_17 ,
T_1 V_6 , int V_31 )
{
int V_57 ;
struct V_40 * V_40 = NULL ;
void * V_78 ;
struct V_16 V_101 ;
V_101 = * V_17 ;
if ( F_14 ( V_17 ) ) {
void * V_79 ;
V_40 = F_85 ( V_85 | V_86 ) ;
if ( ! V_40 )
return - V_87 ;
V_57 = F_77 ( V_1 , V_40 , V_6 ) ;
if ( V_57 )
goto V_88;
V_78 = F_63 ( V_17 -> V_84 ) ;
V_79 = F_63 ( V_40 ) ;
memcpy ( V_79 + V_31 , V_78 + V_17 -> V_89 , V_17 -> V_18 ) ;
F_64 ( V_79 ) ;
F_64 ( V_78 ) ;
V_101 . V_84 = V_40 ;
V_101 . V_18 = V_19 ;
V_101 . V_89 = 0 ;
}
V_57 = F_90 ( V_1 , & V_101 , V_6 ) ;
V_88:
if ( F_14 ( V_17 ) )
F_86 ( V_40 ) ;
return V_57 ;
}
static void F_93 ( struct V_1 * V_1 , T_1 V_6 ,
int V_31 , struct V_102 * V_102 )
{
T_2 V_103 = V_102 -> V_104 . V_105 ;
if ( V_31 ) {
if ( V_103 <= ( V_19 - V_31 ) )
return;
V_103 -= ( V_19 - V_31 ) ;
V_6 ++ ;
}
while ( V_103 >= V_19 ) {
F_58 ( V_1 , V_6 ) ;
F_66 ( V_1 , V_6 ) ;
F_60 ( V_1 , V_6 ) ;
F_67 ( & V_1 -> V_35 . V_61 ) ;
V_6 ++ ;
V_103 -= V_19 ;
}
}
static int F_94 ( struct V_1 * V_1 , struct V_16 * V_17 , T_1 V_6 ,
int V_31 , bool V_106 )
{
unsigned long V_107 = V_108 ;
int V_109 = V_106 ? V_110 : V_111 ;
int V_57 ;
F_95 ( V_109 , V_17 -> V_18 >> V_30 ,
& V_1 -> V_20 -> V_112 ) ;
if ( ! V_106 ) {
F_67 ( & V_1 -> V_35 . V_113 ) ;
V_57 = F_84 ( V_1 , V_17 , V_6 , V_31 ) ;
F_96 ( V_17 -> V_84 ) ;
} else {
F_67 ( & V_1 -> V_35 . V_114 ) ;
V_57 = F_92 ( V_1 , V_17 , V_6 , V_31 ) ;
}
F_97 ( V_109 , & V_1 -> V_20 -> V_112 , V_107 ) ;
if ( F_18 ( V_57 ) ) {
if ( ! V_106 )
F_67 ( & V_1 -> V_35 . V_58 ) ;
else
F_67 ( & V_1 -> V_35 . V_59 ) ;
}
return V_57 ;
}
static void F_98 ( struct V_1 * V_1 , struct V_102 * V_102 )
{
int V_31 ;
T_1 V_6 ;
struct V_16 V_17 ;
struct V_115 V_116 ;
V_6 = V_102 -> V_104 . V_117 >> V_118 ;
V_31 = ( V_102 -> V_104 . V_117 &
( V_119 - 1 ) ) << V_30 ;
switch ( F_99 ( V_102 ) ) {
case V_120 :
case V_121 :
F_93 ( V_1 , V_6 , V_31 , V_102 ) ;
F_100 ( V_102 ) ;
return;
default:
break;
}
F_101 (bvec, bio, iter) {
struct V_16 V_122 = V_17 ;
unsigned int V_123 = V_17 . V_18 ;
do {
V_122 . V_18 = F_102 (unsigned int, PAGE_SIZE - offset,
unwritten) ;
if ( F_94 ( V_1 , & V_122 , V_6 , V_31 ,
F_103 ( F_99 ( V_102 ) ) ) < 0 )
goto V_88;
V_122 . V_89 += V_122 . V_18 ;
V_123 -= V_122 . V_18 ;
F_19 ( & V_6 , & V_31 , & V_122 ) ;
} while ( V_123 );
}
F_100 ( V_102 ) ;
return;
V_88:
F_104 ( V_102 ) ;
}
static T_6 F_105 ( struct V_124 * V_21 , struct V_102 * V_102 )
{
struct V_1 * V_1 = V_21 -> V_125 ;
if ( ! F_17 ( V_1 , V_102 -> V_104 . V_117 ,
V_102 -> V_104 . V_105 ) ) {
F_67 ( & V_1 -> V_35 . V_60 ) ;
goto error;
}
F_98 ( V_1 , V_102 ) ;
return V_126 ;
error:
F_104 ( V_102 ) ;
return V_126 ;
}
static void F_106 ( struct V_127 * V_128 ,
unsigned long V_6 )
{
struct V_1 * V_1 ;
V_1 = V_128 -> V_129 -> V_5 ;
F_58 ( V_1 , V_6 ) ;
F_66 ( V_1 , V_6 ) ;
F_60 ( V_1 , V_6 ) ;
F_67 ( & V_1 -> V_35 . V_61 ) ;
}
static int F_107 ( struct V_127 * V_128 , T_3 V_130 ,
struct V_40 * V_40 , bool V_106 )
{
int V_31 , V_52 = - V_131 ;
T_1 V_6 ;
struct V_1 * V_1 ;
struct V_16 V_122 ;
V_1 = V_128 -> V_129 -> V_5 ;
if ( ! F_17 ( V_1 , V_130 , V_19 ) ) {
F_67 ( & V_1 -> V_35 . V_60 ) ;
V_52 = - V_49 ;
goto V_88;
}
V_6 = V_130 >> V_118 ;
V_31 = ( V_130 & ( V_119 - 1 ) ) << V_30 ;
V_122 . V_84 = V_40 ;
V_122 . V_18 = V_19 ;
V_122 . V_89 = 0 ;
V_52 = F_94 ( V_1 , & V_122 , V_6 , V_31 , V_106 ) ;
V_88:
if ( V_52 == 0 )
F_108 ( V_40 , V_106 , 0 ) ;
return V_52 ;
}
static void F_109 ( struct V_1 * V_1 )
{
struct V_132 * V_83 ;
T_4 V_2 ;
F_35 ( & V_1 -> V_46 ) ;
V_1 -> V_50 = 0 ;
if ( ! F_1 ( V_1 ) ) {
F_37 ( & V_1 -> V_46 ) ;
return;
}
V_83 = V_1 -> V_83 ;
V_2 = V_1 -> V_2 ;
V_1 -> V_2 = 0 ;
F_110 ( V_1 -> V_20 , 0 ) ;
F_111 ( & V_1 -> V_20 -> V_112 , 0 ) ;
F_37 ( & V_1 -> V_46 ) ;
F_68 ( V_1 , V_2 ) ;
memset ( & V_1 -> V_35 , 0 , sizeof( V_1 -> V_35 ) ) ;
F_112 ( V_83 ) ;
}
static T_5 F_113 ( struct V_3 * V_4 ,
struct V_43 * V_44 , const char * V_45 , T_2 V_38 )
{
T_4 V_2 ;
struct V_132 * V_83 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
int V_52 ;
V_2 = F_34 ( V_45 , NULL ) ;
if ( ! V_2 )
return - V_49 ;
F_35 ( & V_1 -> V_46 ) ;
if ( F_1 ( V_1 ) ) {
F_51 ( L_10 ) ;
V_52 = - V_56 ;
goto V_133;
}
V_2 = F_36 ( V_2 ) ;
if ( ! F_71 ( V_1 , V_2 ) ) {
V_52 = - V_87 ;
goto V_133;
}
V_83 = F_114 ( V_1 -> V_55 ) ;
if ( F_115 ( V_83 ) ) {
F_83 ( L_11 ,
V_1 -> V_55 ) ;
V_52 = F_116 ( V_83 ) ;
goto V_134;
}
V_1 -> V_83 = V_83 ;
V_1 -> V_2 = V_2 ;
F_110 ( V_1 -> V_20 , V_1 -> V_2 >> V_30 ) ;
F_15 ( V_1 ) ;
F_37 ( & V_1 -> V_46 ) ;
return V_38 ;
V_134:
F_68 ( V_1 , V_2 ) ;
V_133:
F_37 ( & V_1 -> V_46 ) ;
return V_52 ;
}
static T_5 F_117 ( struct V_3 * V_4 ,
struct V_43 * V_44 , const char * V_45 , T_2 V_38 )
{
int V_57 ;
unsigned short V_135 ;
struct V_1 * V_1 ;
struct V_127 * V_128 ;
V_57 = F_118 ( V_45 , 10 , & V_135 ) ;
if ( V_57 )
return V_57 ;
if ( ! V_135 )
return - V_49 ;
V_1 = F_2 ( V_4 ) ;
V_128 = F_119 ( V_1 -> V_20 , 0 ) ;
if ( ! V_128 )
return - V_87 ;
F_120 ( & V_128 -> V_136 ) ;
if ( V_128 -> V_137 || V_1 -> V_138 ) {
F_121 ( & V_128 -> V_136 ) ;
F_122 ( V_128 ) ;
return - V_56 ;
}
V_1 -> V_138 = true ;
F_121 ( & V_128 -> V_136 ) ;
F_123 ( V_128 ) ;
F_109 ( V_1 ) ;
F_15 ( V_1 ) ;
F_122 ( V_128 ) ;
F_120 ( & V_128 -> V_136 ) ;
V_1 -> V_138 = false ;
F_121 ( & V_128 -> V_136 ) ;
return V_38 ;
}
static int F_124 ( struct V_127 * V_128 , T_7 V_139 )
{
int V_57 = 0 ;
struct V_1 * V_1 ;
F_125 ( ! F_126 ( & V_128 -> V_136 ) ) ;
V_1 = V_128 -> V_129 -> V_5 ;
if ( V_1 -> V_138 )
V_57 = - V_56 ;
return V_57 ;
}
static int F_127 ( void )
{
struct V_1 * V_1 ;
struct V_124 * V_21 ;
int V_57 , V_140 ;
V_1 = F_128 ( sizeof( struct V_1 ) , V_141 ) ;
if ( ! V_1 )
return - V_87 ;
V_57 = F_129 ( & V_142 , V_1 , 0 , 0 , V_141 ) ;
if ( V_57 < 0 )
goto V_143;
V_140 = V_57 ;
F_130 ( & V_1 -> V_46 ) ;
V_21 = F_131 ( V_141 ) ;
if ( ! V_21 ) {
F_83 ( L_12 ,
V_140 ) ;
V_57 = - V_87 ;
goto V_144;
}
F_132 ( V_21 , F_105 ) ;
V_1 -> V_20 = F_133 ( 1 ) ;
if ( ! V_1 -> V_20 ) {
F_83 ( L_13 ,
V_140 ) ;
V_57 = - V_87 ;
goto V_145;
}
V_1 -> V_20 -> V_146 = V_147 ;
V_1 -> V_20 -> V_148 = V_140 ;
V_1 -> V_20 -> V_149 = & V_150 ;
V_1 -> V_20 -> V_21 = V_21 ;
V_1 -> V_20 -> V_21 -> V_125 = V_1 ;
V_1 -> V_20 -> V_5 = V_1 ;
snprintf ( V_1 -> V_20 -> V_77 , 16 , L_14 , V_140 ) ;
F_110 ( V_1 -> V_20 , 0 ) ;
F_134 ( V_151 , V_1 -> V_20 -> V_21 ) ;
F_135 ( V_152 , V_1 -> V_20 -> V_21 ) ;
F_136 ( V_1 -> V_20 -> V_21 , V_19 ) ;
F_137 ( V_1 -> V_20 -> V_21 ,
V_29 ) ;
F_138 ( V_1 -> V_20 -> V_21 , V_19 ) ;
F_139 ( V_1 -> V_20 -> V_21 , V_19 ) ;
V_1 -> V_20 -> V_21 -> V_153 . V_154 = V_19 ;
F_140 ( V_1 -> V_20 -> V_21 , V_155 ) ;
F_134 ( V_156 , V_1 -> V_20 -> V_21 ) ;
if ( V_29 == V_19 )
F_141 ( V_1 -> V_20 -> V_21 , V_155 ) ;
F_142 ( V_1 -> V_20 ) ;
V_57 = F_143 ( & F_144 ( V_1 -> V_20 ) -> V_157 ,
& V_158 ) ;
if ( V_57 < 0 ) {
F_83 ( L_15 ,
V_140 ) ;
goto V_159;
}
F_49 ( V_1 -> V_55 , V_160 , sizeof( V_1 -> V_55 ) ) ;
F_51 ( L_16 , V_1 -> V_20 -> V_77 ) ;
return V_140 ;
V_159:
F_145 ( V_1 -> V_20 ) ;
F_146 ( V_1 -> V_20 ) ;
V_145:
F_147 ( V_21 ) ;
V_144:
F_148 ( & V_142 , V_140 ) ;
V_143:
F_149 ( V_1 ) ;
return V_57 ;
}
static int F_150 ( struct V_1 * V_1 )
{
struct V_127 * V_128 ;
V_128 = F_119 ( V_1 -> V_20 , 0 ) ;
if ( ! V_128 )
return - V_87 ;
F_120 ( & V_128 -> V_136 ) ;
if ( V_128 -> V_137 || V_1 -> V_138 ) {
F_121 ( & V_128 -> V_136 ) ;
F_122 ( V_128 ) ;
return - V_56 ;
}
V_1 -> V_138 = true ;
F_121 ( & V_128 -> V_136 ) ;
F_151 ( & F_144 ( V_1 -> V_20 ) -> V_157 ,
& V_158 ) ;
F_123 ( V_128 ) ;
F_109 ( V_1 ) ;
F_122 ( V_128 ) ;
F_51 ( L_17 , V_1 -> V_20 -> V_77 ) ;
F_147 ( V_1 -> V_20 -> V_21 ) ;
F_145 ( V_1 -> V_20 ) ;
F_146 ( V_1 -> V_20 ) ;
F_149 ( V_1 ) ;
return 0 ;
}
static T_5 F_152 ( struct V_161 * V_161 ,
struct V_162 * V_44 ,
char * V_45 )
{
int V_57 ;
F_120 ( & V_163 ) ;
V_57 = F_127 () ;
F_121 ( & V_163 ) ;
if ( V_57 < 0 )
return V_57 ;
return F_31 ( V_45 , V_19 , L_3 , V_57 ) ;
}
static T_5 F_153 ( struct V_161 * V_161 ,
struct V_162 * V_44 ,
const char * V_45 ,
T_2 V_164 )
{
struct V_1 * V_1 ;
int V_57 , V_165 ;
V_57 = F_154 ( V_45 , 10 , & V_165 ) ;
if ( V_57 )
return V_57 ;
if ( V_165 < 0 )
return - V_49 ;
F_120 ( & V_163 ) ;
V_1 = F_155 ( & V_142 , V_165 ) ;
if ( V_1 ) {
V_57 = F_150 ( V_1 ) ;
if ( ! V_57 )
F_148 ( & V_142 , V_165 ) ;
} else {
V_57 = - V_166 ;
}
F_121 ( & V_163 ) ;
return V_57 ? V_57 : V_164 ;
}
static int F_156 ( int V_167 , void * V_37 , void * V_168 )
{
F_150 ( V_37 ) ;
return 0 ;
}
static void F_157 ( void )
{
F_158 ( & V_169 ) ;
F_159 ( & V_142 , & F_156 , NULL ) ;
F_160 ( & V_142 ) ;
F_161 ( V_147 , L_18 ) ;
F_162 ( V_170 ) ;
}
static int T_8 F_163 ( void )
{
int V_57 ;
V_57 = F_164 ( V_170 , L_19 ,
V_171 , V_172 ) ;
if ( V_57 < 0 )
return V_57 ;
V_57 = F_165 ( & V_169 ) ;
if ( V_57 ) {
F_83 ( L_20 ) ;
F_162 ( V_170 ) ;
return V_57 ;
}
V_147 = F_166 ( 0 , L_18 ) ;
if ( V_147 <= 0 ) {
F_83 ( L_21 ) ;
F_158 ( & V_169 ) ;
F_162 ( V_170 ) ;
return - V_56 ;
}
while ( V_173 != 0 ) {
F_120 ( & V_163 ) ;
V_57 = F_127 () ;
F_121 ( & V_163 ) ;
if ( V_57 < 0 )
goto V_174;
V_173 -- ;
}
return 0 ;
V_174:
F_157 () ;
return V_57 ;
}
static void T_9 F_167 ( void )
{
F_157 () ;
}
