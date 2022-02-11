static inline bool F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 ;
}
static inline struct V_1 * F_2 ( struct V_3 * V_4 )
{
return (struct V_1 * ) F_3 ( V_4 ) -> V_5 ;
}
static int F_4 ( struct V_6 * V_7 , T_1 V_8 ,
enum V_9 V_10 )
{
return V_7 -> V_11 [ V_8 ] . V_12 & F_5 ( V_10 ) ;
}
static void F_6 ( struct V_6 * V_7 , T_1 V_8 ,
enum V_9 V_10 )
{
V_7 -> V_11 [ V_8 ] . V_12 |= F_5 ( V_10 ) ;
}
static void F_7 ( struct V_6 * V_7 , T_1 V_8 ,
enum V_9 V_10 )
{
V_7 -> V_11 [ V_8 ] . V_12 &= ~ F_5 ( V_10 ) ;
}
static inline void F_8 ( struct V_6 * V_7 , T_1 V_8 ,
unsigned long V_13 )
{
V_7 -> V_11 [ V_8 ] . V_13 = V_13 ;
}
static inline void F_9 ( struct V_6 * V_7 , T_1 V_8 )
{
V_7 -> V_11 [ V_8 ] . V_13 = 0 ;
}
static T_2 F_10 ( struct V_6 * V_7 , T_1 V_8 )
{
return V_7 -> V_11 [ V_8 ] . V_12 & ( F_5 ( V_14 ) - 1 ) ;
}
static void F_11 ( struct V_6 * V_7 ,
T_1 V_8 , T_2 V_15 )
{
unsigned long V_16 = V_7 -> V_11 [ V_8 ] . V_12 >> V_14 ;
V_7 -> V_11 [ V_8 ] . V_12 = ( V_16 << V_14 ) | V_15 ;
}
static inline bool F_12 ( struct V_17 * V_18 )
{
return V_18 -> V_19 != V_20 ;
}
static void F_13 ( struct V_1 * V_1 )
{
F_14 ( V_1 -> V_21 ) ;
V_1 -> V_21 -> V_22 -> V_23 -> V_24 |=
V_25 ;
}
static inline bool F_15 ( struct V_1 * V_1 ,
T_3 V_26 , unsigned int V_15 )
{
T_4 V_27 , V_28 ;
if ( F_16 ( V_26 & ( V_29 - 1 ) ) )
return false ;
if ( F_16 ( V_15 & ( V_30 - 1 ) ) )
return false ;
V_27 = V_26 + ( V_15 >> V_31 ) ;
V_28 = V_1 -> V_2 >> V_31 ;
if ( F_16 ( V_26 >= V_28 || V_27 > V_28 || V_26 > V_27 ) )
return false ;
return true ;
}
static void F_17 ( T_1 * V_8 , int * V_32 , struct V_17 * V_18 )
{
if ( * V_32 + V_18 -> V_19 >= V_20 )
( * V_8 ) ++ ;
* V_32 = ( * V_32 + V_18 -> V_19 ) % V_20 ;
}
static inline void F_18 ( struct V_1 * V_1 ,
const unsigned long V_33 )
{
unsigned long V_34 , V_35 ;
V_34 = F_19 ( & V_1 -> V_36 . V_37 ) ;
do {
V_35 = V_34 ;
if ( V_33 > V_35 )
V_34 = F_20 (
& V_1 -> V_36 . V_37 , V_35 , V_33 ) ;
} while ( V_34 != V_35 );
}
static inline void F_21 ( char * V_38 , unsigned long V_39 ,
unsigned long V_12 )
{
int V_40 ;
unsigned long * V_41 = ( unsigned long * ) V_38 ;
F_22 ( ! F_23 ( V_39 , sizeof( unsigned long ) ) ) ;
if ( F_24 ( V_12 == 0 ) ) {
memset ( V_38 , 0 , V_39 ) ;
} else {
for ( V_40 = 0 ; V_40 < V_39 / sizeof( * V_41 ) ; V_40 ++ )
V_41 [ V_40 ] = V_12 ;
}
}
static bool F_25 ( void * V_38 , unsigned long * V_13 )
{
unsigned int V_42 ;
unsigned long * V_41 ;
V_41 = ( unsigned long * ) V_38 ;
for ( V_42 = 0 ; V_42 < V_20 / sizeof( * V_41 ) - 1 ; V_42 ++ ) {
if ( V_41 [ V_42 ] != V_41 [ V_42 + 1 ] )
return false ;
}
* V_13 = V_41 [ V_42 ] ;
return true ;
}
static void F_26 ( struct V_17 * V_18 , unsigned long V_13 )
{
struct V_41 * V_41 = V_18 -> V_43 ;
void * V_44 ;
V_44 = F_27 ( V_41 ) ;
F_21 ( V_44 + V_18 -> V_45 , V_18 -> V_19 , V_13 ) ;
F_28 ( V_44 ) ;
F_29 ( V_41 ) ;
}
static T_5 F_30 ( struct V_3 * V_4 ,
struct V_46 * V_47 , char * V_48 )
{
T_1 V_49 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
F_31 ( & V_1 -> V_50 ) ;
V_49 = F_1 ( V_1 ) ;
F_32 ( & V_1 -> V_50 ) ;
return F_33 ( V_48 , V_20 , L_1 , V_49 ) ;
}
static T_5 F_34 ( struct V_3 * V_4 ,
struct V_46 * V_47 , char * V_48 )
{
struct V_1 * V_1 = F_2 ( V_4 ) ;
return F_33 ( V_48 , V_20 , L_2 , V_1 -> V_2 ) ;
}
static T_5 F_35 ( struct V_3 * V_4 ,
struct V_46 * V_47 , const char * V_48 , T_2 V_39 )
{
T_4 V_51 ;
char * V_52 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
V_51 = F_36 ( V_48 , & V_52 ) ;
if ( V_48 == V_52 )
return - V_53 ;
F_37 ( & V_1 -> V_50 ) ;
V_1 -> V_54 = F_38 ( V_51 ) >> V_55 ;
F_39 ( & V_1 -> V_50 ) ;
return V_39 ;
}
static T_5 F_40 ( struct V_3 * V_4 ,
struct V_46 * V_47 , const char * V_48 , T_2 V_39 )
{
int V_56 ;
unsigned long V_49 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
V_56 = F_41 ( V_48 , 10 , & V_49 ) ;
if ( V_56 || V_49 != 0 )
return - V_53 ;
F_31 ( & V_1 -> V_50 ) ;
if ( F_1 ( V_1 ) ) {
struct V_6 * V_7 = V_1 -> V_7 ;
F_42 ( & V_1 -> V_36 . V_37 ,
F_43 ( V_7 -> V_57 ) ) ;
}
F_32 ( & V_1 -> V_50 ) ;
return V_39 ;
}
static T_5 F_44 ( struct V_3 * V_4 ,
struct V_46 * V_47 , char * V_48 )
{
return F_33 ( V_48 , V_20 , L_3 , F_45 () ) ;
}
static T_5 F_46 ( struct V_3 * V_4 ,
struct V_46 * V_47 , const char * V_48 , T_2 V_39 )
{
return V_39 ;
}
static T_5 F_47 ( struct V_3 * V_4 ,
struct V_46 * V_47 , char * V_48 )
{
T_2 V_58 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
F_31 ( & V_1 -> V_50 ) ;
V_58 = F_48 ( V_1 -> V_59 , V_48 ) ;
F_32 ( & V_1 -> V_50 ) ;
return V_58 ;
}
static T_5 F_49 ( struct V_3 * V_4 ,
struct V_46 * V_47 , const char * V_48 , T_2 V_39 )
{
struct V_1 * V_1 = F_2 ( V_4 ) ;
char V_59 [ V_60 ] ;
T_2 V_58 ;
F_50 ( V_59 , V_48 , sizeof( V_59 ) ) ;
V_58 = strlen ( V_59 ) ;
if ( V_58 > 0 && V_59 [ V_58 - 1 ] == '\n' )
V_59 [ V_58 - 1 ] = 0x00 ;
if ( ! F_51 ( V_59 ) )
return - V_53 ;
F_37 ( & V_1 -> V_50 ) ;
if ( F_1 ( V_1 ) ) {
F_39 ( & V_1 -> V_50 ) ;
F_52 ( L_4 ) ;
return - V_61 ;
}
F_50 ( V_1 -> V_59 , V_59 , sizeof( V_59 ) ) ;
F_39 ( & V_1 -> V_50 ) ;
return V_39 ;
}
static T_5 F_53 ( struct V_3 * V_4 ,
struct V_46 * V_47 , const char * V_48 , T_2 V_39 )
{
struct V_1 * V_1 = F_2 ( V_4 ) ;
struct V_6 * V_7 ;
F_31 ( & V_1 -> V_50 ) ;
if ( ! F_1 ( V_1 ) ) {
F_32 ( & V_1 -> V_50 ) ;
return - V_53 ;
}
V_7 = V_1 -> V_7 ;
F_54 ( V_7 -> V_57 ) ;
F_32 ( & V_1 -> V_50 ) ;
return V_39 ;
}
static T_5 F_55 ( struct V_3 * V_4 ,
struct V_46 * V_47 , char * V_48 )
{
struct V_1 * V_1 = F_2 ( V_4 ) ;
T_5 V_62 ;
F_31 ( & V_1 -> V_50 ) ;
V_62 = F_33 ( V_48 , V_20 ,
L_5 ,
( T_4 ) F_56 ( & V_1 -> V_36 . V_63 ) ,
( T_4 ) F_56 ( & V_1 -> V_36 . V_64 ) ,
( T_4 ) F_56 ( & V_1 -> V_36 . V_65 ) ,
( T_4 ) F_56 ( & V_1 -> V_36 . V_66 ) ) ;
F_32 ( & V_1 -> V_50 ) ;
return V_62 ;
}
static T_5 F_57 ( struct V_3 * V_4 ,
struct V_46 * V_47 , char * V_48 )
{
struct V_1 * V_1 = F_2 ( V_4 ) ;
struct V_67 V_68 ;
T_4 V_69 , V_70 = 0 ;
long V_71 ;
T_5 V_62 ;
memset ( & V_68 , 0x00 , sizeof( struct V_67 ) ) ;
F_31 ( & V_1 -> V_50 ) ;
if ( F_1 ( V_1 ) ) {
V_70 = F_43 ( V_1 -> V_7 -> V_57 ) ;
V_67 ( V_1 -> V_7 -> V_57 , & V_68 ) ;
}
V_69 = F_56 ( & V_1 -> V_36 . V_72 ) ;
V_71 = F_19 ( & V_1 -> V_36 . V_37 ) ;
V_62 = F_33 ( V_48 , V_20 ,
L_6 ,
V_69 << V_55 ,
( T_4 ) F_56 ( & V_1 -> V_36 . V_73 ) ,
V_70 << V_55 ,
V_1 -> V_54 << V_55 ,
V_71 << V_55 ,
( T_4 ) F_56 ( & V_1 -> V_36 . V_74 ) ,
V_68 . V_75 ) ;
F_32 ( & V_1 -> V_50 ) ;
return V_62 ;
}
static T_5 F_58 ( struct V_3 * V_4 ,
struct V_46 * V_47 , char * V_48 )
{
int V_76 = 1 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
T_5 V_62 ;
F_31 ( & V_1 -> V_50 ) ;
V_62 = F_33 ( V_48 , V_20 ,
L_7 ,
V_76 ,
( T_4 ) F_56 ( & V_1 -> V_36 . V_77 ) ) ;
F_32 ( & V_1 -> V_50 ) ;
return V_62 ;
}
static void F_59 ( struct V_6 * V_7 , T_4 V_2 )
{
T_2 V_78 = V_2 >> V_55 ;
T_2 V_8 ;
for ( V_8 = 0 ; V_8 < V_78 ; V_8 ++ ) {
unsigned long V_79 = V_7 -> V_11 [ V_8 ] . V_79 ;
if ( ! V_79 || F_4 ( V_7 , V_8 , V_80 ) )
continue;
F_60 ( V_7 -> V_57 , V_79 ) ;
}
F_61 ( V_7 -> V_57 ) ;
F_62 ( V_7 -> V_11 ) ;
F_63 ( V_7 ) ;
}
static struct V_6 * F_64 ( char * V_81 , T_4 V_2 )
{
T_2 V_78 ;
struct V_6 * V_7 = F_65 ( sizeof( * V_7 ) , V_82 ) ;
if ( ! V_7 )
return NULL ;
V_78 = V_2 >> V_55 ;
V_7 -> V_11 = F_66 ( V_78 * sizeof( * V_7 -> V_11 ) ) ;
if ( ! V_7 -> V_11 ) {
F_67 ( L_8 ) ;
goto V_83;
}
V_7 -> V_57 = F_68 ( V_81 ) ;
if ( ! V_7 -> V_57 ) {
F_67 ( L_9 ) ;
goto V_83;
}
return V_7 ;
V_83:
F_62 ( V_7 -> V_11 ) ;
F_63 ( V_7 ) ;
return NULL ;
}
static void F_69 ( struct V_1 * V_1 , T_2 V_8 )
{
struct V_6 * V_7 = V_1 -> V_7 ;
unsigned long V_79 = V_7 -> V_11 [ V_8 ] . V_79 ;
if ( F_4 ( V_7 , V_8 , V_80 ) ) {
F_7 ( V_7 , V_8 , V_80 ) ;
F_9 ( V_7 , V_8 ) ;
F_70 ( & V_1 -> V_36 . V_74 ) ;
return;
}
if ( ! V_79 )
return;
F_60 ( V_7 -> V_57 , V_79 ) ;
F_71 ( F_10 ( V_7 , V_8 ) ,
& V_1 -> V_36 . V_73 ) ;
F_70 ( & V_1 -> V_36 . V_72 ) ;
V_7 -> V_11 [ V_8 ] . V_79 = 0 ;
F_11 ( V_7 , V_8 , 0 ) ;
}
static int F_72 ( struct V_1 * V_1 , char * V_84 , T_1 V_8 )
{
int V_62 = 0 ;
unsigned char * V_85 ;
struct V_6 * V_7 = V_1 -> V_7 ;
unsigned long V_79 ;
unsigned int V_15 ;
F_73 ( V_86 , & V_7 -> V_11 [ V_8 ] . V_12 ) ;
V_79 = V_7 -> V_11 [ V_8 ] . V_79 ;
V_15 = F_10 ( V_7 , V_8 ) ;
if ( ! V_79 || F_4 ( V_7 , V_8 , V_80 ) ) {
F_74 ( V_86 , & V_7 -> V_11 [ V_8 ] . V_12 ) ;
F_21 ( V_84 , V_20 , V_7 -> V_11 [ V_8 ] . V_13 ) ;
return 0 ;
}
V_85 = F_75 ( V_7 -> V_57 , V_79 , V_87 ) ;
if ( V_15 == V_20 ) {
memcpy ( V_84 , V_85 , V_20 ) ;
} else {
struct V_88 * V_89 = F_76 ( V_1 -> V_90 ) ;
V_62 = F_77 ( V_89 , V_85 , V_15 , V_84 ) ;
F_78 ( V_1 -> V_90 ) ;
}
F_79 ( V_7 -> V_57 , V_79 ) ;
F_74 ( V_86 , & V_7 -> V_11 [ V_8 ] . V_12 ) ;
if ( F_16 ( V_62 ) ) {
F_67 ( L_10 , V_62 , V_8 ) ;
return V_62 ;
}
return 0 ;
}
static int F_80 ( struct V_1 * V_1 , struct V_17 * V_18 ,
T_1 V_8 , int V_32 )
{
int V_62 ;
struct V_41 * V_41 ;
unsigned char * V_44 , * V_91 = NULL ;
struct V_6 * V_7 = V_1 -> V_7 ;
V_41 = V_18 -> V_43 ;
F_73 ( V_86 , & V_7 -> V_11 [ V_8 ] . V_12 ) ;
if ( F_16 ( ! V_7 -> V_11 [ V_8 ] . V_79 ) ||
F_4 ( V_7 , V_8 , V_80 ) ) {
F_74 ( V_86 , & V_7 -> V_11 [ V_8 ] . V_12 ) ;
F_26 ( V_18 , V_7 -> V_11 [ V_8 ] . V_13 ) ;
return 0 ;
}
F_74 ( V_86 , & V_7 -> V_11 [ V_8 ] . V_12 ) ;
if ( F_12 ( V_18 ) )
V_91 = F_65 ( V_20 , V_92 ) ;
V_44 = F_27 ( V_41 ) ;
if ( ! F_12 ( V_18 ) )
V_91 = V_44 ;
if ( ! V_91 ) {
F_67 ( L_11 ) ;
V_62 = - V_93 ;
goto V_94;
}
V_62 = F_72 ( V_1 , V_91 , V_8 ) ;
if ( F_16 ( V_62 ) )
goto V_94;
if ( F_12 ( V_18 ) )
memcpy ( V_44 + V_18 -> V_45 , V_91 + V_32 ,
V_18 -> V_19 ) ;
F_29 ( V_41 ) ;
V_62 = 0 ;
V_94:
F_28 ( V_44 ) ;
if ( F_12 ( V_18 ) )
F_63 ( V_91 ) ;
return V_62 ;
}
static int F_81 ( struct V_1 * V_1 , struct V_17 * V_18 , T_1 V_8 ,
int V_32 )
{
int V_62 = 0 ;
unsigned int V_95 ;
unsigned long V_79 = 0 ;
struct V_41 * V_41 ;
unsigned char * V_44 , * V_85 , * V_96 , * V_91 = NULL ;
struct V_6 * V_7 = V_1 -> V_7 ;
struct V_88 * V_89 = NULL ;
unsigned long V_97 ;
unsigned long V_13 ;
V_41 = V_18 -> V_43 ;
if ( F_12 ( V_18 ) ) {
V_91 = F_65 ( V_20 , V_92 ) ;
if ( ! V_91 ) {
V_62 = - V_93 ;
goto V_98;
}
V_62 = F_72 ( V_1 , V_91 , V_8 ) ;
if ( V_62 )
goto V_98;
}
V_99:
V_44 = F_27 ( V_41 ) ;
if ( F_12 ( V_18 ) ) {
memcpy ( V_91 + V_32 , V_44 + V_18 -> V_45 ,
V_18 -> V_19 ) ;
F_28 ( V_44 ) ;
V_44 = NULL ;
} else {
V_91 = V_44 ;
}
if ( F_25 ( V_91 , & V_13 ) ) {
if ( V_44 )
F_28 ( V_44 ) ;
F_73 ( V_86 , & V_7 -> V_11 [ V_8 ] . V_12 ) ;
F_69 ( V_1 , V_8 ) ;
F_6 ( V_7 , V_8 , V_80 ) ;
F_8 ( V_7 , V_8 , V_13 ) ;
F_74 ( V_86 , & V_7 -> V_11 [ V_8 ] . V_12 ) ;
F_82 ( & V_1 -> V_36 . V_74 ) ;
V_62 = 0 ;
goto V_98;
}
V_89 = F_76 ( V_1 -> V_90 ) ;
V_62 = F_83 ( V_89 , V_91 , & V_95 ) ;
if ( ! F_12 ( V_18 ) ) {
F_28 ( V_44 ) ;
V_44 = NULL ;
V_91 = NULL ;
}
if ( F_16 ( V_62 ) ) {
F_67 ( L_12 , V_62 ) ;
goto V_98;
}
V_96 = V_89 -> V_100 ;
if ( F_16 ( V_95 > V_101 ) ) {
V_95 = V_20 ;
if ( F_12 ( V_18 ) )
V_96 = V_91 ;
}
if ( ! V_79 )
V_79 = F_84 ( V_7 -> V_57 , V_95 ,
V_102 |
V_103 |
V_104 |
V_105 ) ;
if ( ! V_79 ) {
F_78 ( V_1 -> V_90 ) ;
V_89 = NULL ;
F_82 ( & V_1 -> V_36 . V_77 ) ;
V_79 = F_84 ( V_7 -> V_57 , V_95 ,
V_92 | V_104 |
V_105 ) ;
if ( V_79 )
goto V_99;
F_67 ( L_13 ,
V_8 , V_95 ) ;
V_62 = - V_93 ;
goto V_98;
}
V_97 = F_43 ( V_7 -> V_57 ) ;
F_18 ( V_1 , V_97 ) ;
if ( V_1 -> V_54 && V_97 > V_1 -> V_54 ) {
F_60 ( V_7 -> V_57 , V_79 ) ;
V_62 = - V_93 ;
goto V_98;
}
V_85 = F_75 ( V_7 -> V_57 , V_79 , V_106 ) ;
if ( ( V_95 == V_20 ) && ! F_12 ( V_18 ) ) {
V_96 = F_27 ( V_41 ) ;
memcpy ( V_85 , V_96 , V_20 ) ;
F_28 ( V_96 ) ;
} else {
memcpy ( V_85 , V_96 , V_95 ) ;
}
F_78 ( V_1 -> V_90 ) ;
V_89 = NULL ;
F_79 ( V_7 -> V_57 , V_79 ) ;
F_73 ( V_86 , & V_7 -> V_11 [ V_8 ] . V_12 ) ;
F_69 ( V_1 , V_8 ) ;
V_7 -> V_11 [ V_8 ] . V_79 = V_79 ;
F_11 ( V_7 , V_8 , V_95 ) ;
F_74 ( V_86 , & V_7 -> V_11 [ V_8 ] . V_12 ) ;
F_85 ( V_95 , & V_1 -> V_36 . V_73 ) ;
F_82 ( & V_1 -> V_36 . V_72 ) ;
V_98:
if ( V_89 )
F_78 ( V_1 -> V_90 ) ;
if ( F_12 ( V_18 ) )
F_63 ( V_91 ) ;
return V_62 ;
}
static void F_86 ( struct V_1 * V_1 , T_1 V_8 ,
int V_32 , struct V_107 * V_107 )
{
T_2 V_108 = V_107 -> V_109 . V_110 ;
struct V_6 * V_7 = V_1 -> V_7 ;
if ( V_32 ) {
if ( V_108 <= ( V_20 - V_32 ) )
return;
V_108 -= ( V_20 - V_32 ) ;
V_8 ++ ;
}
while ( V_108 >= V_20 ) {
F_73 ( V_86 , & V_7 -> V_11 [ V_8 ] . V_12 ) ;
F_69 ( V_1 , V_8 ) ;
F_74 ( V_86 , & V_7 -> V_11 [ V_8 ] . V_12 ) ;
F_82 ( & V_1 -> V_36 . V_66 ) ;
V_8 ++ ;
V_108 -= V_20 ;
}
}
static int F_87 ( struct V_1 * V_1 , struct V_17 * V_18 , T_1 V_8 ,
int V_32 , bool V_111 )
{
unsigned long V_112 = V_113 ;
int V_114 = V_111 ? V_115 : V_116 ;
int V_62 ;
F_88 ( V_114 , V_18 -> V_19 >> V_31 ,
& V_1 -> V_21 -> V_117 ) ;
if ( ! V_111 ) {
F_82 ( & V_1 -> V_36 . V_118 ) ;
V_62 = F_80 ( V_1 , V_18 , V_8 , V_32 ) ;
} else {
F_82 ( & V_1 -> V_36 . V_119 ) ;
V_62 = F_81 ( V_1 , V_18 , V_8 , V_32 ) ;
}
F_89 ( V_114 , & V_1 -> V_21 -> V_117 , V_112 ) ;
if ( F_16 ( V_62 ) ) {
if ( ! V_111 )
F_82 ( & V_1 -> V_36 . V_63 ) ;
else
F_82 ( & V_1 -> V_36 . V_64 ) ;
}
return V_62 ;
}
static void F_90 ( struct V_1 * V_1 , struct V_107 * V_107 )
{
int V_32 ;
T_1 V_8 ;
struct V_17 V_18 ;
struct V_120 V_121 ;
V_8 = V_107 -> V_109 . V_122 >> V_123 ;
V_32 = ( V_107 -> V_109 . V_122 &
( V_124 - 1 ) ) << V_31 ;
if ( F_16 ( F_91 ( V_107 ) == V_125 ) ) {
F_86 ( V_1 , V_8 , V_32 , V_107 ) ;
F_92 ( V_107 ) ;
return;
}
F_93 (bvec, bio, iter) {
int V_126 = V_20 - V_32 ;
if ( V_18 . V_19 > V_126 ) {
struct V_17 V_127 ;
V_127 . V_43 = V_18 . V_43 ;
V_127 . V_19 = V_126 ;
V_127 . V_45 = V_18 . V_45 ;
if ( F_87 ( V_1 , & V_127 , V_8 , V_32 ,
F_94 ( F_91 ( V_107 ) ) ) < 0 )
goto V_98;
V_127 . V_19 = V_18 . V_19 - V_126 ;
V_127 . V_45 += V_126 ;
if ( F_87 ( V_1 , & V_127 , V_8 + 1 , 0 ,
F_94 ( F_91 ( V_107 ) ) ) < 0 )
goto V_98;
} else
if ( F_87 ( V_1 , & V_18 , V_8 , V_32 ,
F_94 ( F_91 ( V_107 ) ) ) < 0 )
goto V_98;
F_17 ( & V_8 , & V_32 , & V_18 ) ;
}
F_92 ( V_107 ) ;
return;
V_98:
F_95 ( V_107 ) ;
}
static T_6 F_96 ( struct V_128 * V_22 , struct V_107 * V_107 )
{
struct V_1 * V_1 = V_22 -> V_129 ;
F_97 ( V_22 , & V_107 , V_22 -> V_130 ) ;
if ( ! F_15 ( V_1 , V_107 -> V_109 . V_122 ,
V_107 -> V_109 . V_110 ) ) {
F_82 ( & V_1 -> V_36 . V_65 ) ;
goto error;
}
F_90 ( V_1 , V_107 ) ;
return V_131 ;
error:
F_95 ( V_107 ) ;
return V_131 ;
}
static void F_98 ( struct V_132 * V_133 ,
unsigned long V_8 )
{
struct V_1 * V_1 ;
struct V_6 * V_7 ;
V_1 = V_133 -> V_134 -> V_5 ;
V_7 = V_1 -> V_7 ;
F_73 ( V_86 , & V_7 -> V_11 [ V_8 ] . V_12 ) ;
F_69 ( V_1 , V_8 ) ;
F_74 ( V_86 , & V_7 -> V_11 [ V_8 ] . V_12 ) ;
F_82 ( & V_1 -> V_36 . V_66 ) ;
}
static int F_99 ( struct V_132 * V_133 , T_3 V_135 ,
struct V_41 * V_41 , bool V_111 )
{
int V_32 , V_56 = - V_136 ;
T_1 V_8 ;
struct V_1 * V_1 ;
struct V_17 V_127 ;
V_1 = V_133 -> V_134 -> V_5 ;
if ( ! F_15 ( V_1 , V_135 , V_20 ) ) {
F_82 ( & V_1 -> V_36 . V_65 ) ;
V_56 = - V_53 ;
goto V_98;
}
V_8 = V_135 >> V_123 ;
V_32 = ( V_135 & ( V_124 - 1 ) ) << V_31 ;
V_127 . V_43 = V_41 ;
V_127 . V_19 = V_20 ;
V_127 . V_45 = 0 ;
V_56 = F_87 ( V_1 , & V_127 , V_8 , V_32 , V_111 ) ;
V_98:
if ( V_56 == 0 )
F_100 ( V_41 , V_111 , 0 ) ;
return V_56 ;
}
static void F_101 ( struct V_1 * V_1 )
{
struct V_6 * V_7 ;
struct V_137 * V_90 ;
T_4 V_2 ;
F_37 ( & V_1 -> V_50 ) ;
V_1 -> V_54 = 0 ;
if ( ! F_1 ( V_1 ) ) {
F_39 ( & V_1 -> V_50 ) ;
return;
}
V_7 = V_1 -> V_7 ;
V_90 = V_1 -> V_90 ;
V_2 = V_1 -> V_2 ;
memset ( & V_1 -> V_36 , 0 , sizeof( V_1 -> V_36 ) ) ;
V_1 -> V_2 = 0 ;
F_102 ( V_1 -> V_21 , 0 ) ;
F_103 ( & V_1 -> V_21 -> V_117 , 0 ) ;
F_39 ( & V_1 -> V_50 ) ;
F_59 ( V_7 , V_2 ) ;
F_104 ( V_90 ) ;
}
static T_5 F_105 ( struct V_3 * V_4 ,
struct V_46 * V_47 , const char * V_48 , T_2 V_39 )
{
T_4 V_2 ;
struct V_137 * V_90 ;
struct V_6 * V_7 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
int V_56 ;
V_2 = F_36 ( V_48 , NULL ) ;
if ( ! V_2 )
return - V_53 ;
V_2 = F_38 ( V_2 ) ;
V_7 = F_64 ( V_1 -> V_21 -> V_138 , V_2 ) ;
if ( ! V_7 )
return - V_93 ;
V_90 = F_106 ( V_1 -> V_59 ) ;
if ( F_107 ( V_90 ) ) {
F_67 ( L_14 ,
V_1 -> V_59 ) ;
V_56 = F_108 ( V_90 ) ;
goto V_139;
}
F_37 ( & V_1 -> V_50 ) ;
if ( F_1 ( V_1 ) ) {
F_52 ( L_15 ) ;
V_56 = - V_61 ;
goto V_140;
}
V_1 -> V_7 = V_7 ;
V_1 -> V_90 = V_90 ;
V_1 -> V_2 = V_2 ;
F_102 ( V_1 -> V_21 , V_1 -> V_2 >> V_31 ) ;
F_13 ( V_1 ) ;
F_39 ( & V_1 -> V_50 ) ;
return V_39 ;
V_140:
F_39 ( & V_1 -> V_50 ) ;
F_104 ( V_90 ) ;
V_139:
F_59 ( V_7 , V_2 ) ;
return V_56 ;
}
static T_5 F_109 ( struct V_3 * V_4 ,
struct V_46 * V_47 , const char * V_48 , T_2 V_39 )
{
int V_62 ;
unsigned short V_141 ;
struct V_1 * V_1 ;
struct V_132 * V_133 ;
V_62 = F_110 ( V_48 , 10 , & V_141 ) ;
if ( V_62 )
return V_62 ;
if ( ! V_141 )
return - V_53 ;
V_1 = F_2 ( V_4 ) ;
V_133 = F_111 ( V_1 -> V_21 , 0 ) ;
if ( ! V_133 )
return - V_93 ;
F_112 ( & V_133 -> V_142 ) ;
if ( V_133 -> V_143 || V_1 -> V_144 ) {
F_113 ( & V_133 -> V_142 ) ;
F_114 ( V_133 ) ;
return - V_61 ;
}
V_1 -> V_144 = true ;
F_113 ( & V_133 -> V_142 ) ;
F_115 ( V_133 ) ;
F_101 ( V_1 ) ;
F_13 ( V_1 ) ;
F_114 ( V_133 ) ;
F_112 ( & V_133 -> V_142 ) ;
V_1 -> V_144 = false ;
F_113 ( & V_133 -> V_142 ) ;
return V_39 ;
}
static int F_116 ( struct V_132 * V_133 , T_7 V_145 )
{
int V_62 = 0 ;
struct V_1 * V_1 ;
F_117 ( ! F_118 ( & V_133 -> V_142 ) ) ;
V_1 = V_133 -> V_134 -> V_5 ;
if ( V_1 -> V_144 )
V_62 = - V_61 ;
return V_62 ;
}
static int F_119 ( void )
{
struct V_1 * V_1 ;
struct V_128 * V_22 ;
int V_62 , V_146 ;
V_1 = F_120 ( sizeof( struct V_1 ) , V_82 ) ;
if ( ! V_1 )
return - V_93 ;
V_62 = F_121 ( & V_147 , V_1 , 0 , 0 , V_82 ) ;
if ( V_62 < 0 )
goto V_148;
V_146 = V_62 ;
F_122 ( & V_1 -> V_50 ) ;
V_22 = F_123 ( V_82 ) ;
if ( ! V_22 ) {
F_67 ( L_16 ,
V_146 ) ;
V_62 = - V_93 ;
goto V_149;
}
F_124 ( V_22 , F_96 ) ;
V_1 -> V_21 = F_125 ( 1 ) ;
if ( ! V_1 -> V_21 ) {
F_67 ( L_17 ,
V_146 ) ;
V_62 = - V_93 ;
goto V_150;
}
V_1 -> V_21 -> V_151 = V_152 ;
V_1 -> V_21 -> V_153 = V_146 ;
V_1 -> V_21 -> V_154 = & V_155 ;
V_1 -> V_21 -> V_22 = V_22 ;
V_1 -> V_21 -> V_22 -> V_129 = V_1 ;
V_1 -> V_21 -> V_5 = V_1 ;
snprintf ( V_1 -> V_21 -> V_138 , 16 , L_18 , V_146 ) ;
F_102 ( V_1 -> V_21 , 0 ) ;
F_126 ( V_156 , V_1 -> V_21 -> V_22 ) ;
F_127 ( V_157 , V_1 -> V_21 -> V_22 ) ;
F_128 ( V_1 -> V_21 -> V_22 , V_20 ) ;
F_129 ( V_1 -> V_21 -> V_22 ,
V_30 ) ;
F_130 ( V_1 -> V_21 -> V_22 , V_20 ) ;
F_131 ( V_1 -> V_21 -> V_22 , V_20 ) ;
V_1 -> V_21 -> V_22 -> V_158 . V_159 = V_20 ;
V_1 -> V_21 -> V_22 -> V_158 . V_160 = V_124 ;
V_1 -> V_21 -> V_22 -> V_158 . V_161 = 0 ;
F_132 ( V_1 -> V_21 -> V_22 , V_162 ) ;
if ( V_30 == V_20 )
V_1 -> V_21 -> V_22 -> V_158 . V_163 = 1 ;
else
V_1 -> V_21 -> V_22 -> V_158 . V_163 = 0 ;
F_126 ( V_164 , V_1 -> V_21 -> V_22 ) ;
F_133 ( V_1 -> V_21 ) ;
V_62 = F_134 ( & F_135 ( V_1 -> V_21 ) -> V_165 ,
& V_166 ) ;
if ( V_62 < 0 ) {
F_67 ( L_19 ,
V_146 ) ;
goto V_167;
}
F_50 ( V_1 -> V_59 , V_168 , sizeof( V_1 -> V_59 ) ) ;
V_1 -> V_7 = NULL ;
F_52 ( L_20 , V_1 -> V_21 -> V_138 ) ;
return V_146 ;
V_167:
F_136 ( V_1 -> V_21 ) ;
F_137 ( V_1 -> V_21 ) ;
V_150:
F_138 ( V_22 ) ;
V_149:
F_139 ( & V_147 , V_146 ) ;
V_148:
F_63 ( V_1 ) ;
return V_62 ;
}
static int F_140 ( struct V_1 * V_1 )
{
struct V_132 * V_133 ;
V_133 = F_111 ( V_1 -> V_21 , 0 ) ;
if ( ! V_133 )
return - V_93 ;
F_112 ( & V_133 -> V_142 ) ;
if ( V_133 -> V_143 || V_1 -> V_144 ) {
F_113 ( & V_133 -> V_142 ) ;
F_114 ( V_133 ) ;
return - V_61 ;
}
V_1 -> V_144 = true ;
F_113 ( & V_133 -> V_142 ) ;
F_141 ( & F_135 ( V_1 -> V_21 ) -> V_165 ,
& V_166 ) ;
F_115 ( V_133 ) ;
F_101 ( V_1 ) ;
F_114 ( V_133 ) ;
F_52 ( L_21 , V_1 -> V_21 -> V_138 ) ;
F_138 ( V_1 -> V_21 -> V_22 ) ;
F_136 ( V_1 -> V_21 ) ;
F_137 ( V_1 -> V_21 ) ;
F_63 ( V_1 ) ;
return 0 ;
}
static T_5 F_142 ( struct V_169 * V_169 ,
struct V_170 * V_47 ,
char * V_48 )
{
int V_62 ;
F_112 ( & V_171 ) ;
V_62 = F_119 () ;
F_113 ( & V_171 ) ;
if ( V_62 < 0 )
return V_62 ;
return F_33 ( V_48 , V_20 , L_3 , V_62 ) ;
}
static T_5 F_143 ( struct V_169 * V_169 ,
struct V_170 * V_47 ,
const char * V_48 ,
T_2 V_172 )
{
struct V_1 * V_1 ;
int V_62 , V_173 ;
V_62 = F_144 ( V_48 , 10 , & V_173 ) ;
if ( V_62 )
return V_62 ;
if ( V_173 < 0 )
return - V_53 ;
F_112 ( & V_171 ) ;
V_1 = F_145 ( & V_147 , V_173 ) ;
if ( V_1 ) {
V_62 = F_140 ( V_1 ) ;
if ( ! V_62 )
F_139 ( & V_147 , V_173 ) ;
} else {
V_62 = - V_174 ;
}
F_113 ( & V_171 ) ;
return V_62 ? V_62 : V_172 ;
}
static int F_146 ( int V_175 , void * V_38 , void * V_176 )
{
F_140 ( V_38 ) ;
return 0 ;
}
static void F_147 ( void )
{
F_148 ( & V_177 ) ;
F_149 ( & V_147 , & F_146 , NULL ) ;
F_150 ( & V_147 ) ;
F_151 ( V_152 , L_22 ) ;
F_152 ( V_178 ) ;
}
static int T_8 F_153 ( void )
{
int V_62 ;
V_62 = F_154 ( V_178 , L_23 ,
V_179 , V_180 ) ;
if ( V_62 < 0 )
return V_62 ;
V_62 = F_155 ( & V_177 ) ;
if ( V_62 ) {
F_67 ( L_24 ) ;
F_152 ( V_178 ) ;
return V_62 ;
}
V_152 = F_156 ( 0 , L_22 ) ;
if ( V_152 <= 0 ) {
F_67 ( L_25 ) ;
F_148 ( & V_177 ) ;
F_152 ( V_178 ) ;
return - V_61 ;
}
while ( V_181 != 0 ) {
F_112 ( & V_171 ) ;
V_62 = F_119 () ;
F_113 ( & V_171 ) ;
if ( V_62 < 0 )
goto V_83;
V_181 -- ;
}
return 0 ;
V_83:
F_147 () ;
return V_62 ;
}
static void T_9 F_157 ( void )
{
F_147 () ;
}
