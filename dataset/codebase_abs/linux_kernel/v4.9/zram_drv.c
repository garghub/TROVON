static inline void F_1 ( const char * V_1 )
{
F_2 ( L_1 ,
F_3 ( V_2 ) ,
V_2 -> V_3 ,
V_1 ,
L_2 ) ;
}
static inline bool F_4 ( struct V_4 * V_4 )
{
return V_4 -> V_5 ;
}
static inline struct V_4 * F_5 ( struct V_6 * V_7 )
{
return (struct V_4 * ) F_6 ( V_7 ) -> V_8 ;
}
static int F_7 ( struct V_9 * V_10 , T_1 V_11 ,
enum V_12 V_13 )
{
return V_10 -> V_14 [ V_11 ] . V_15 & F_8 ( V_13 ) ;
}
static void F_9 ( struct V_9 * V_10 , T_1 V_11 ,
enum V_12 V_13 )
{
V_10 -> V_14 [ V_11 ] . V_15 |= F_8 ( V_13 ) ;
}
static void F_10 ( struct V_9 * V_10 , T_1 V_11 ,
enum V_12 V_13 )
{
V_10 -> V_14 [ V_11 ] . V_15 &= ~ F_8 ( V_13 ) ;
}
static T_2 F_11 ( struct V_9 * V_10 , T_1 V_11 )
{
return V_10 -> V_14 [ V_11 ] . V_15 & ( F_8 ( V_16 ) - 1 ) ;
}
static void F_12 ( struct V_9 * V_10 ,
T_1 V_11 , T_2 V_17 )
{
unsigned long V_18 = V_10 -> V_14 [ V_11 ] . V_15 >> V_16 ;
V_10 -> V_14 [ V_11 ] . V_15 = ( V_18 << V_16 ) | V_17 ;
}
static inline bool F_13 ( struct V_19 * V_20 )
{
return V_20 -> V_21 != V_22 ;
}
static inline bool F_14 ( struct V_4 * V_4 ,
T_3 V_23 , unsigned int V_17 )
{
T_4 V_24 , V_25 ;
if ( F_15 ( V_23 & ( V_26 - 1 ) ) )
return false ;
if ( F_15 ( V_17 & ( V_27 - 1 ) ) )
return false ;
V_24 = V_23 + ( V_17 >> V_28 ) ;
V_25 = V_4 -> V_5 >> V_28 ;
if ( F_15 ( V_23 >= V_25 || V_24 > V_25 || V_23 > V_24 ) )
return false ;
return true ;
}
static void F_16 ( T_1 * V_11 , int * V_29 , struct V_19 * V_20 )
{
if ( * V_29 + V_20 -> V_21 >= V_22 )
( * V_11 ) ++ ;
* V_29 = ( * V_29 + V_20 -> V_21 ) % V_22 ;
}
static inline void F_17 ( struct V_4 * V_4 ,
const unsigned long V_30 )
{
unsigned long V_31 , V_32 ;
V_31 = F_18 ( & V_4 -> V_33 . V_34 ) ;
do {
V_32 = V_31 ;
if ( V_30 > V_32 )
V_31 = F_19 (
& V_4 -> V_33 . V_34 , V_32 , V_30 ) ;
} while ( V_31 != V_32 );
}
static bool F_20 ( void * V_35 )
{
unsigned int V_36 ;
unsigned long * V_37 ;
V_37 = ( unsigned long * ) V_35 ;
for ( V_36 = 0 ; V_36 != V_22 / sizeof( * V_37 ) ; V_36 ++ ) {
if ( V_37 [ V_36 ] )
return false ;
}
return true ;
}
static void F_21 ( struct V_19 * V_20 )
{
struct V_37 * V_37 = V_20 -> V_38 ;
void * V_39 ;
V_39 = F_22 ( V_37 ) ;
if ( F_13 ( V_20 ) )
memset ( V_39 + V_20 -> V_40 , 0 , V_20 -> V_21 ) ;
else
F_23 ( V_39 ) ;
F_24 ( V_39 ) ;
F_25 ( V_37 ) ;
}
static T_5 F_26 ( struct V_6 * V_7 ,
struct V_41 * V_42 , char * V_43 )
{
T_1 V_44 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
F_27 ( & V_4 -> V_45 ) ;
V_44 = F_4 ( V_4 ) ;
F_28 ( & V_4 -> V_45 ) ;
return F_29 ( V_43 , V_22 , L_3 , V_44 ) ;
}
static T_5 F_30 ( struct V_6 * V_7 ,
struct V_41 * V_42 , char * V_43 )
{
struct V_4 * V_4 = F_5 ( V_7 ) ;
return F_29 ( V_43 , V_22 , L_4 , V_4 -> V_5 ) ;
}
static T_5 F_31 ( struct V_6 * V_7 ,
struct V_41 * V_42 , char * V_43 )
{
struct V_4 * V_4 = F_5 ( V_7 ) ;
F_1 ( L_5 ) ;
return F_29 ( V_43 , V_22 , L_4 ,
( T_4 ) ( F_32 ( & V_4 -> V_33 . V_46 ) ) << V_47 ) ;
}
static T_5 F_33 ( struct V_6 * V_7 ,
struct V_41 * V_42 , char * V_43 )
{
T_4 V_44 = 0 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
F_1 ( L_6 ) ;
F_27 ( & V_4 -> V_45 ) ;
if ( F_4 ( V_4 ) ) {
struct V_9 * V_10 = V_4 -> V_10 ;
V_44 = F_34 ( V_10 -> V_48 ) ;
}
F_28 ( & V_4 -> V_45 ) ;
return F_29 ( V_43 , V_22 , L_4 , V_44 << V_47 ) ;
}
static T_5 F_35 ( struct V_6 * V_7 ,
struct V_41 * V_42 , char * V_43 )
{
T_4 V_44 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
F_1 ( L_7 ) ;
F_27 ( & V_4 -> V_45 ) ;
V_44 = V_4 -> V_49 ;
F_28 ( & V_4 -> V_45 ) ;
return F_29 ( V_43 , V_22 , L_4 , V_44 << V_47 ) ;
}
static T_5 F_36 ( struct V_6 * V_7 ,
struct V_41 * V_42 , const char * V_43 , T_2 V_50 )
{
T_4 V_51 ;
char * V_52 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
V_51 = F_37 ( V_43 , & V_52 ) ;
if ( V_43 == V_52 )
return - V_53 ;
F_38 ( & V_4 -> V_45 ) ;
V_4 -> V_49 = F_39 ( V_51 ) >> V_47 ;
F_40 ( & V_4 -> V_45 ) ;
return V_50 ;
}
static T_5 F_41 ( struct V_6 * V_7 ,
struct V_41 * V_42 , char * V_43 )
{
T_4 V_44 = 0 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
F_1 ( L_8 ) ;
F_27 ( & V_4 -> V_45 ) ;
if ( F_4 ( V_4 ) )
V_44 = F_18 ( & V_4 -> V_33 . V_34 ) ;
F_28 ( & V_4 -> V_45 ) ;
return F_29 ( V_43 , V_22 , L_4 , V_44 << V_47 ) ;
}
static T_5 F_42 ( struct V_6 * V_7 ,
struct V_41 * V_42 , const char * V_43 , T_2 V_50 )
{
int V_54 ;
unsigned long V_44 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
V_54 = F_43 ( V_43 , 10 , & V_44 ) ;
if ( V_54 || V_44 != 0 )
return - V_53 ;
F_27 ( & V_4 -> V_45 ) ;
if ( F_4 ( V_4 ) ) {
struct V_9 * V_10 = V_4 -> V_10 ;
F_44 ( & V_4 -> V_33 . V_34 ,
F_34 ( V_10 -> V_48 ) ) ;
}
F_28 ( & V_4 -> V_45 ) ;
return V_50 ;
}
static T_5 F_45 ( struct V_6 * V_7 ,
struct V_41 * V_42 , char * V_43 )
{
return F_29 ( V_43 , V_22 , L_9 , F_46 () ) ;
}
static T_5 F_47 ( struct V_6 * V_7 ,
struct V_41 * V_42 , const char * V_43 , T_2 V_50 )
{
return V_50 ;
}
static T_5 F_48 ( struct V_6 * V_7 ,
struct V_41 * V_42 , char * V_43 )
{
T_2 V_55 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
F_27 ( & V_4 -> V_45 ) ;
V_55 = F_49 ( V_4 -> V_56 , V_43 ) ;
F_28 ( & V_4 -> V_45 ) ;
return V_55 ;
}
static T_5 F_50 ( struct V_6 * V_7 ,
struct V_41 * V_42 , const char * V_43 , T_2 V_50 )
{
struct V_4 * V_4 = F_5 ( V_7 ) ;
char V_56 [ V_57 ] ;
T_2 V_55 ;
F_51 ( V_56 , V_43 , sizeof( V_56 ) ) ;
V_55 = strlen ( V_56 ) ;
if ( V_55 > 0 && V_56 [ V_55 - 1 ] == '\n' )
V_56 [ V_55 - 1 ] = 0x00 ;
if ( ! F_52 ( V_56 ) )
return - V_53 ;
F_38 ( & V_4 -> V_45 ) ;
if ( F_4 ( V_4 ) ) {
F_40 ( & V_4 -> V_45 ) ;
F_53 ( L_10 ) ;
return - V_58 ;
}
F_51 ( V_4 -> V_56 , V_56 , sizeof( V_56 ) ) ;
F_40 ( & V_4 -> V_45 ) ;
return V_50 ;
}
static T_5 F_54 ( struct V_6 * V_7 ,
struct V_41 * V_42 , const char * V_43 , T_2 V_50 )
{
struct V_4 * V_4 = F_5 ( V_7 ) ;
struct V_9 * V_10 ;
F_27 ( & V_4 -> V_45 ) ;
if ( ! F_4 ( V_4 ) ) {
F_28 ( & V_4 -> V_45 ) ;
return - V_53 ;
}
V_10 = V_4 -> V_10 ;
F_55 ( V_10 -> V_48 ) ;
F_28 ( & V_4 -> V_45 ) ;
return V_50 ;
}
static T_5 F_56 ( struct V_6 * V_7 ,
struct V_41 * V_42 , char * V_43 )
{
struct V_4 * V_4 = F_5 ( V_7 ) ;
T_5 V_59 ;
F_27 ( & V_4 -> V_45 ) ;
V_59 = F_29 ( V_43 , V_22 ,
L_11 ,
( T_4 ) F_32 ( & V_4 -> V_33 . V_60 ) ,
( T_4 ) F_32 ( & V_4 -> V_33 . V_61 ) ,
( T_4 ) F_32 ( & V_4 -> V_33 . V_62 ) ,
( T_4 ) F_32 ( & V_4 -> V_33 . V_63 ) ) ;
F_28 ( & V_4 -> V_45 ) ;
return V_59 ;
}
static T_5 F_57 ( struct V_6 * V_7 ,
struct V_41 * V_42 , char * V_43 )
{
struct V_4 * V_4 = F_5 ( V_7 ) ;
struct V_64 V_65 ;
T_4 V_66 , V_67 = 0 ;
long V_68 ;
T_5 V_59 ;
memset ( & V_65 , 0x00 , sizeof( struct V_64 ) ) ;
F_27 ( & V_4 -> V_45 ) ;
if ( F_4 ( V_4 ) ) {
V_67 = F_34 ( V_4 -> V_10 -> V_48 ) ;
V_64 ( V_4 -> V_10 -> V_48 , & V_65 ) ;
}
V_66 = F_32 ( & V_4 -> V_33 . V_46 ) ;
V_68 = F_18 ( & V_4 -> V_33 . V_34 ) ;
V_59 = F_29 ( V_43 , V_22 ,
L_12 ,
V_66 << V_47 ,
( T_4 ) F_32 ( & V_4 -> V_33 . V_69 ) ,
V_67 << V_47 ,
V_4 -> V_49 << V_47 ,
V_68 << V_47 ,
( T_4 ) F_32 ( & V_4 -> V_33 . V_70 ) ,
V_65 . V_71 ) ;
F_28 ( & V_4 -> V_45 ) ;
return V_59 ;
}
static T_5 F_58 ( struct V_6 * V_7 ,
struct V_41 * V_42 , char * V_43 )
{
int V_72 = 1 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
T_5 V_59 ;
F_27 ( & V_4 -> V_45 ) ;
V_59 = F_29 ( V_43 , V_22 ,
L_13 ,
V_72 ,
( T_4 ) F_32 ( & V_4 -> V_33 . V_73 ) ) ;
F_28 ( & V_4 -> V_45 ) ;
return V_59 ;
}
static inline bool F_59 ( struct V_4 * V_4 )
{
if ( F_60 ( & V_4 -> V_74 ) )
return true ;
return false ;
}
static inline void F_61 ( struct V_4 * V_4 )
{
F_62 ( & V_4 -> V_74 ) ;
}
static void F_63 ( struct V_9 * V_10 , T_4 V_5 )
{
T_2 V_75 = V_5 >> V_47 ;
T_2 V_11 ;
for ( V_11 = 0 ; V_11 < V_75 ; V_11 ++ ) {
unsigned long V_76 = V_10 -> V_14 [ V_11 ] . V_76 ;
if ( ! V_76 )
continue;
F_64 ( V_10 -> V_48 , V_76 ) ;
}
F_65 ( V_10 -> V_48 ) ;
F_66 ( V_10 -> V_14 ) ;
F_67 ( V_10 ) ;
}
static struct V_9 * F_68 ( char * V_77 , T_4 V_5 )
{
T_2 V_75 ;
struct V_9 * V_10 = F_69 ( sizeof( * V_10 ) , V_78 ) ;
if ( ! V_10 )
return NULL ;
V_75 = V_5 >> V_47 ;
V_10 -> V_14 = F_70 ( V_75 * sizeof( * V_10 -> V_14 ) ) ;
if ( ! V_10 -> V_14 ) {
F_71 ( L_14 ) ;
goto V_79;
}
V_10 -> V_48 = F_72 ( V_77 ) ;
if ( ! V_10 -> V_48 ) {
F_71 ( L_15 ) ;
goto V_79;
}
return V_10 ;
V_79:
F_66 ( V_10 -> V_14 ) ;
F_67 ( V_10 ) ;
return NULL ;
}
static void F_73 ( struct V_4 * V_4 , T_2 V_11 )
{
struct V_9 * V_10 = V_4 -> V_10 ;
unsigned long V_76 = V_10 -> V_14 [ V_11 ] . V_76 ;
if ( F_15 ( ! V_76 ) ) {
if ( F_7 ( V_10 , V_11 , V_80 ) ) {
F_10 ( V_10 , V_11 , V_80 ) ;
F_74 ( & V_4 -> V_33 . V_70 ) ;
}
return;
}
F_64 ( V_10 -> V_48 , V_76 ) ;
F_75 ( F_11 ( V_10 , V_11 ) ,
& V_4 -> V_33 . V_69 ) ;
F_74 ( & V_4 -> V_33 . V_46 ) ;
V_10 -> V_14 [ V_11 ] . V_76 = 0 ;
F_12 ( V_10 , V_11 , 0 ) ;
}
static int F_76 ( struct V_4 * V_4 , char * V_81 , T_1 V_11 )
{
int V_59 = 0 ;
unsigned char * V_82 ;
struct V_9 * V_10 = V_4 -> V_10 ;
unsigned long V_76 ;
unsigned int V_17 ;
F_77 ( V_83 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
V_76 = V_10 -> V_14 [ V_11 ] . V_76 ;
V_17 = F_11 ( V_10 , V_11 ) ;
if ( ! V_76 || F_7 ( V_10 , V_11 , V_80 ) ) {
F_78 ( V_83 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_23 ( V_81 ) ;
return 0 ;
}
V_82 = F_79 ( V_10 -> V_48 , V_76 , V_84 ) ;
if ( V_17 == V_22 ) {
F_80 ( V_81 , V_82 ) ;
} else {
struct V_85 * V_86 = F_81 ( V_4 -> V_87 ) ;
V_59 = F_82 ( V_86 , V_82 , V_17 , V_81 ) ;
F_83 ( V_4 -> V_87 ) ;
}
F_84 ( V_10 -> V_48 , V_76 ) ;
F_78 ( V_83 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
if ( F_15 ( V_59 ) ) {
F_71 ( L_16 , V_59 , V_11 ) ;
return V_59 ;
}
return 0 ;
}
static int F_85 ( struct V_4 * V_4 , struct V_19 * V_20 ,
T_1 V_11 , int V_29 )
{
int V_59 ;
struct V_37 * V_37 ;
unsigned char * V_39 , * V_88 = NULL ;
struct V_9 * V_10 = V_4 -> V_10 ;
V_37 = V_20 -> V_38 ;
F_77 ( V_83 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
if ( F_15 ( ! V_10 -> V_14 [ V_11 ] . V_76 ) ||
F_7 ( V_10 , V_11 , V_80 ) ) {
F_78 ( V_83 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_21 ( V_20 ) ;
return 0 ;
}
F_78 ( V_83 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
if ( F_13 ( V_20 ) )
V_88 = F_69 ( V_22 , V_89 ) ;
V_39 = F_22 ( V_37 ) ;
if ( ! F_13 ( V_20 ) )
V_88 = V_39 ;
if ( ! V_88 ) {
F_71 ( L_17 ) ;
V_59 = - V_90 ;
goto V_91;
}
V_59 = F_76 ( V_4 , V_88 , V_11 ) ;
if ( F_15 ( V_59 ) )
goto V_91;
if ( F_13 ( V_20 ) )
memcpy ( V_39 + V_20 -> V_40 , V_88 + V_29 ,
V_20 -> V_21 ) ;
F_25 ( V_37 ) ;
V_59 = 0 ;
V_91:
F_24 ( V_39 ) ;
if ( F_13 ( V_20 ) )
F_67 ( V_88 ) ;
return V_59 ;
}
static int F_86 ( struct V_4 * V_4 , struct V_19 * V_20 , T_1 V_11 ,
int V_29 )
{
int V_59 = 0 ;
unsigned int V_92 ;
unsigned long V_76 = 0 ;
struct V_37 * V_37 ;
unsigned char * V_39 , * V_82 , * V_93 , * V_88 = NULL ;
struct V_9 * V_10 = V_4 -> V_10 ;
struct V_85 * V_86 = NULL ;
unsigned long V_94 ;
V_37 = V_20 -> V_38 ;
if ( F_13 ( V_20 ) ) {
V_88 = F_69 ( V_22 , V_89 ) ;
if ( ! V_88 ) {
V_59 = - V_90 ;
goto V_95;
}
V_59 = F_76 ( V_4 , V_88 , V_11 ) ;
if ( V_59 )
goto V_95;
}
V_96:
V_39 = F_22 ( V_37 ) ;
if ( F_13 ( V_20 ) ) {
memcpy ( V_88 + V_29 , V_39 + V_20 -> V_40 ,
V_20 -> V_21 ) ;
F_24 ( V_39 ) ;
V_39 = NULL ;
} else {
V_88 = V_39 ;
}
if ( F_20 ( V_88 ) ) {
if ( V_39 )
F_24 ( V_39 ) ;
F_77 ( V_83 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_73 ( V_4 , V_11 ) ;
F_9 ( V_10 , V_11 , V_80 ) ;
F_78 ( V_83 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_87 ( & V_4 -> V_33 . V_70 ) ;
V_59 = 0 ;
goto V_95;
}
V_86 = F_81 ( V_4 -> V_87 ) ;
V_59 = F_88 ( V_86 , V_88 , & V_92 ) ;
if ( ! F_13 ( V_20 ) ) {
F_24 ( V_39 ) ;
V_39 = NULL ;
V_88 = NULL ;
}
if ( F_15 ( V_59 ) ) {
F_71 ( L_18 , V_59 ) ;
goto V_95;
}
V_93 = V_86 -> V_97 ;
if ( F_15 ( V_92 > V_98 ) ) {
V_92 = V_22 ;
if ( F_13 ( V_20 ) )
V_93 = V_88 ;
}
if ( ! V_76 )
V_76 = F_89 ( V_10 -> V_48 , V_92 ,
V_99 |
V_100 |
V_101 |
V_102 ) ;
if ( ! V_76 ) {
F_83 ( V_4 -> V_87 ) ;
V_86 = NULL ;
F_87 ( & V_4 -> V_33 . V_73 ) ;
V_76 = F_89 ( V_10 -> V_48 , V_92 ,
V_89 | V_101 |
V_102 ) ;
if ( V_76 )
goto V_96;
F_71 ( L_19 ,
V_11 , V_92 ) ;
V_59 = - V_90 ;
goto V_95;
}
V_94 = F_34 ( V_10 -> V_48 ) ;
F_17 ( V_4 , V_94 ) ;
if ( V_4 -> V_49 && V_94 > V_4 -> V_49 ) {
F_64 ( V_10 -> V_48 , V_76 ) ;
V_59 = - V_90 ;
goto V_95;
}
V_82 = F_79 ( V_10 -> V_48 , V_76 , V_103 ) ;
if ( ( V_92 == V_22 ) && ! F_13 ( V_20 ) ) {
V_93 = F_22 ( V_37 ) ;
F_80 ( V_82 , V_93 ) ;
F_24 ( V_93 ) ;
} else {
memcpy ( V_82 , V_93 , V_92 ) ;
}
F_83 ( V_4 -> V_87 ) ;
V_86 = NULL ;
F_84 ( V_10 -> V_48 , V_76 ) ;
F_77 ( V_83 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_73 ( V_4 , V_11 ) ;
V_10 -> V_14 [ V_11 ] . V_76 = V_76 ;
F_12 ( V_10 , V_11 , V_92 ) ;
F_78 ( V_83 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_90 ( V_92 , & V_4 -> V_33 . V_69 ) ;
F_87 ( & V_4 -> V_33 . V_46 ) ;
V_95:
if ( V_86 )
F_83 ( V_4 -> V_87 ) ;
if ( F_13 ( V_20 ) )
F_67 ( V_88 ) ;
return V_59 ;
}
static void F_91 ( struct V_4 * V_4 , T_1 V_11 ,
int V_29 , struct V_104 * V_104 )
{
T_2 V_105 = V_104 -> V_106 . V_107 ;
struct V_9 * V_10 = V_4 -> V_10 ;
if ( V_29 ) {
if ( V_105 <= ( V_22 - V_29 ) )
return;
V_105 -= ( V_22 - V_29 ) ;
V_11 ++ ;
}
while ( V_105 >= V_22 ) {
F_77 ( V_83 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_73 ( V_4 , V_11 ) ;
F_78 ( V_83 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_87 ( & V_4 -> V_33 . V_63 ) ;
V_11 ++ ;
V_105 -= V_22 ;
}
}
static int F_92 ( struct V_4 * V_4 , struct V_19 * V_20 , T_1 V_11 ,
int V_29 , bool V_108 )
{
unsigned long V_109 = V_110 ;
int V_111 = V_108 ? V_112 : V_113 ;
int V_59 ;
F_93 ( V_111 , V_20 -> V_21 >> V_28 ,
& V_4 -> V_114 -> V_115 ) ;
if ( ! V_108 ) {
F_87 ( & V_4 -> V_33 . V_116 ) ;
V_59 = F_85 ( V_4 , V_20 , V_11 , V_29 ) ;
} else {
F_87 ( & V_4 -> V_33 . V_117 ) ;
V_59 = F_86 ( V_4 , V_20 , V_11 , V_29 ) ;
}
F_94 ( V_111 , & V_4 -> V_114 -> V_115 , V_109 ) ;
if ( F_15 ( V_59 ) ) {
if ( ! V_108 )
F_87 ( & V_4 -> V_33 . V_60 ) ;
else
F_87 ( & V_4 -> V_33 . V_61 ) ;
}
return V_59 ;
}
static void F_95 ( struct V_4 * V_4 , struct V_104 * V_104 )
{
int V_29 ;
T_1 V_11 ;
struct V_19 V_20 ;
struct V_118 V_119 ;
V_11 = V_104 -> V_106 . V_120 >> V_121 ;
V_29 = ( V_104 -> V_106 . V_120 &
( V_122 - 1 ) ) << V_28 ;
if ( F_15 ( F_96 ( V_104 ) == V_123 ) ) {
F_91 ( V_4 , V_11 , V_29 , V_104 ) ;
F_97 ( V_104 ) ;
return;
}
F_98 (bvec, bio, iter) {
int V_124 = V_22 - V_29 ;
if ( V_20 . V_21 > V_124 ) {
struct V_19 V_125 ;
V_125 . V_38 = V_20 . V_38 ;
V_125 . V_21 = V_124 ;
V_125 . V_40 = V_20 . V_40 ;
if ( F_92 ( V_4 , & V_125 , V_11 , V_29 ,
F_99 ( F_96 ( V_104 ) ) ) < 0 )
goto V_95;
V_125 . V_21 = V_20 . V_21 - V_124 ;
V_125 . V_40 += V_124 ;
if ( F_92 ( V_4 , & V_125 , V_11 + 1 , 0 ,
F_99 ( F_96 ( V_104 ) ) ) < 0 )
goto V_95;
} else
if ( F_92 ( V_4 , & V_20 , V_11 , V_29 ,
F_99 ( F_96 ( V_104 ) ) ) < 0 )
goto V_95;
F_16 ( & V_11 , & V_29 , & V_20 ) ;
}
F_97 ( V_104 ) ;
return;
V_95:
F_100 ( V_104 ) ;
}
static T_6 F_101 ( struct V_126 * V_127 , struct V_104 * V_104 )
{
struct V_4 * V_4 = V_127 -> V_128 ;
if ( F_15 ( ! F_59 ( V_4 ) ) )
goto error;
F_102 ( V_127 , & V_104 , V_127 -> V_129 ) ;
if ( ! F_14 ( V_4 , V_104 -> V_106 . V_120 ,
V_104 -> V_106 . V_107 ) ) {
F_87 ( & V_4 -> V_33 . V_62 ) ;
goto V_130;
}
F_95 ( V_4 , V_104 ) ;
F_61 ( V_4 ) ;
return V_131 ;
V_130:
F_61 ( V_4 ) ;
error:
F_100 ( V_104 ) ;
return V_131 ;
}
static void F_103 ( struct V_132 * V_133 ,
unsigned long V_11 )
{
struct V_4 * V_4 ;
struct V_9 * V_10 ;
V_4 = V_133 -> V_134 -> V_8 ;
V_10 = V_4 -> V_10 ;
F_77 ( V_83 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_73 ( V_4 , V_11 ) ;
F_78 ( V_83 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_87 ( & V_4 -> V_33 . V_63 ) ;
}
static int F_104 ( struct V_132 * V_133 , T_3 V_135 ,
struct V_37 * V_37 , bool V_108 )
{
int V_29 , V_54 = - V_136 ;
T_1 V_11 ;
struct V_4 * V_4 ;
struct V_19 V_125 ;
V_4 = V_133 -> V_134 -> V_8 ;
if ( F_15 ( ! F_59 ( V_4 ) ) )
goto V_95;
if ( ! F_14 ( V_4 , V_135 , V_22 ) ) {
F_87 ( & V_4 -> V_33 . V_62 ) ;
V_54 = - V_53 ;
goto V_130;
}
V_11 = V_135 >> V_121 ;
V_29 = V_135 & ( V_122 - 1 ) << V_28 ;
V_125 . V_38 = V_37 ;
V_125 . V_21 = V_22 ;
V_125 . V_40 = 0 ;
V_54 = F_92 ( V_4 , & V_125 , V_11 , V_29 , V_108 ) ;
V_130:
F_61 ( V_4 ) ;
V_95:
if ( V_54 == 0 )
F_105 ( V_37 , V_108 , 0 ) ;
return V_54 ;
}
static void F_106 ( struct V_4 * V_4 )
{
struct V_9 * V_10 ;
struct V_137 * V_87 ;
T_4 V_5 ;
F_38 ( & V_4 -> V_45 ) ;
V_4 -> V_49 = 0 ;
if ( ! F_4 ( V_4 ) ) {
F_40 ( & V_4 -> V_45 ) ;
return;
}
V_10 = V_4 -> V_10 ;
V_87 = V_4 -> V_87 ;
V_5 = V_4 -> V_5 ;
F_61 ( V_4 ) ;
F_107 ( V_4 -> V_138 , F_108 ( & V_4 -> V_74 ) == 0 ) ;
memset ( & V_4 -> V_33 , 0 , sizeof( V_4 -> V_33 ) ) ;
V_4 -> V_5 = 0 ;
F_109 ( V_4 -> V_114 , 0 ) ;
F_110 ( & V_4 -> V_114 -> V_115 , 0 ) ;
F_40 ( & V_4 -> V_45 ) ;
F_63 ( V_10 , V_5 ) ;
F_111 ( V_87 ) ;
}
static T_5 F_112 ( struct V_6 * V_7 ,
struct V_41 * V_42 , const char * V_43 , T_2 V_50 )
{
T_4 V_5 ;
struct V_137 * V_87 ;
struct V_9 * V_10 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
int V_54 ;
V_5 = F_37 ( V_43 , NULL ) ;
if ( ! V_5 )
return - V_53 ;
V_5 = F_39 ( V_5 ) ;
V_10 = F_68 ( V_4 -> V_114 -> V_139 , V_5 ) ;
if ( ! V_10 )
return - V_90 ;
V_87 = F_113 ( V_4 -> V_56 ) ;
if ( F_114 ( V_87 ) ) {
F_71 ( L_20 ,
V_4 -> V_56 ) ;
V_54 = F_115 ( V_87 ) ;
goto V_140;
}
F_38 ( & V_4 -> V_45 ) ;
if ( F_4 ( V_4 ) ) {
F_53 ( L_21 ) ;
V_54 = - V_58 ;
goto V_141;
}
F_116 ( & V_4 -> V_138 ) ;
F_117 ( & V_4 -> V_74 , 1 ) ;
V_4 -> V_10 = V_10 ;
V_4 -> V_87 = V_87 ;
V_4 -> V_5 = V_5 ;
F_109 ( V_4 -> V_114 , V_4 -> V_5 >> V_28 ) ;
F_40 ( & V_4 -> V_45 ) ;
F_118 ( V_4 -> V_114 ) ;
return V_50 ;
V_141:
F_40 ( & V_4 -> V_45 ) ;
F_111 ( V_87 ) ;
V_140:
F_63 ( V_10 , V_5 ) ;
return V_54 ;
}
static T_5 F_119 ( struct V_6 * V_7 ,
struct V_41 * V_42 , const char * V_43 , T_2 V_50 )
{
int V_59 ;
unsigned short V_142 ;
struct V_4 * V_4 ;
struct V_132 * V_133 ;
V_59 = F_120 ( V_43 , 10 , & V_142 ) ;
if ( V_59 )
return V_59 ;
if ( ! V_142 )
return - V_53 ;
V_4 = F_5 ( V_7 ) ;
V_133 = F_121 ( V_4 -> V_114 , 0 ) ;
if ( ! V_133 )
return - V_90 ;
F_122 ( & V_133 -> V_143 ) ;
if ( V_133 -> V_144 || V_4 -> V_145 ) {
F_123 ( & V_133 -> V_143 ) ;
F_124 ( V_133 ) ;
return - V_58 ;
}
V_4 -> V_145 = true ;
F_123 ( & V_133 -> V_143 ) ;
F_125 ( V_133 ) ;
F_106 ( V_4 ) ;
F_118 ( V_4 -> V_114 ) ;
F_124 ( V_133 ) ;
F_122 ( & V_133 -> V_143 ) ;
V_4 -> V_145 = false ;
F_123 ( & V_133 -> V_143 ) ;
return V_50 ;
}
static int F_126 ( struct V_132 * V_133 , T_7 V_146 )
{
int V_59 = 0 ;
struct V_4 * V_4 ;
F_127 ( ! F_128 ( & V_133 -> V_143 ) ) ;
V_4 = V_133 -> V_134 -> V_8 ;
if ( V_4 -> V_145 )
V_59 = - V_58 ;
return V_59 ;
}
static int F_129 ( void )
{
struct V_4 * V_4 ;
struct V_126 * V_127 ;
int V_59 , V_147 ;
V_4 = F_130 ( sizeof( struct V_4 ) , V_78 ) ;
if ( ! V_4 )
return - V_90 ;
V_59 = F_131 ( & V_148 , V_4 , 0 , 0 , V_78 ) ;
if ( V_59 < 0 )
goto V_149;
V_147 = V_59 ;
F_132 ( & V_4 -> V_45 ) ;
V_127 = F_133 ( V_78 ) ;
if ( ! V_127 ) {
F_71 ( L_22 ,
V_147 ) ;
V_59 = - V_90 ;
goto V_150;
}
F_134 ( V_127 , F_101 ) ;
V_4 -> V_114 = F_135 ( 1 ) ;
if ( ! V_4 -> V_114 ) {
F_71 ( L_23 ,
V_147 ) ;
V_59 = - V_90 ;
goto V_151;
}
V_4 -> V_114 -> V_152 = V_153 ;
V_4 -> V_114 -> V_154 = V_147 ;
V_4 -> V_114 -> V_155 = & V_156 ;
V_4 -> V_114 -> V_127 = V_127 ;
V_4 -> V_114 -> V_127 -> V_128 = V_4 ;
V_4 -> V_114 -> V_8 = V_4 ;
snprintf ( V_4 -> V_114 -> V_139 , 16 , L_24 , V_147 ) ;
F_109 ( V_4 -> V_114 , 0 ) ;
F_136 ( V_157 , V_4 -> V_114 -> V_127 ) ;
F_137 ( V_158 , V_4 -> V_114 -> V_127 ) ;
F_138 ( V_4 -> V_114 -> V_127 , V_22 ) ;
F_139 ( V_4 -> V_114 -> V_127 ,
V_27 ) ;
F_140 ( V_4 -> V_114 -> V_127 , V_22 ) ;
F_141 ( V_4 -> V_114 -> V_127 , V_22 ) ;
V_4 -> V_114 -> V_127 -> V_159 . V_160 = V_22 ;
F_142 ( V_4 -> V_114 -> V_127 , V_161 ) ;
if ( V_27 == V_22 )
V_4 -> V_114 -> V_127 -> V_159 . V_162 = 1 ;
else
V_4 -> V_114 -> V_127 -> V_159 . V_162 = 0 ;
F_136 ( V_163 , V_4 -> V_114 -> V_127 ) ;
F_143 ( V_4 -> V_114 ) ;
V_59 = F_144 ( & F_145 ( V_4 -> V_114 ) -> V_164 ,
& V_165 ) ;
if ( V_59 < 0 ) {
F_71 ( L_25 ,
V_147 ) ;
goto V_166;
}
F_51 ( V_4 -> V_56 , V_167 , sizeof( V_4 -> V_56 ) ) ;
V_4 -> V_10 = NULL ;
F_53 ( L_26 , V_4 -> V_114 -> V_139 ) ;
return V_147 ;
V_166:
F_146 ( V_4 -> V_114 ) ;
F_147 ( V_4 -> V_114 ) ;
V_151:
F_148 ( V_127 ) ;
V_150:
F_149 ( & V_148 , V_147 ) ;
V_149:
F_67 ( V_4 ) ;
return V_59 ;
}
static int F_150 ( struct V_4 * V_4 )
{
struct V_132 * V_133 ;
V_133 = F_121 ( V_4 -> V_114 , 0 ) ;
if ( ! V_133 )
return - V_90 ;
F_122 ( & V_133 -> V_143 ) ;
if ( V_133 -> V_144 || V_4 -> V_145 ) {
F_123 ( & V_133 -> V_143 ) ;
F_124 ( V_133 ) ;
return - V_58 ;
}
V_4 -> V_145 = true ;
F_123 ( & V_133 -> V_143 ) ;
F_151 ( & F_145 ( V_4 -> V_114 ) -> V_164 ,
& V_165 ) ;
F_125 ( V_133 ) ;
F_106 ( V_4 ) ;
F_124 ( V_133 ) ;
F_53 ( L_27 , V_4 -> V_114 -> V_139 ) ;
F_148 ( V_4 -> V_114 -> V_127 ) ;
F_146 ( V_4 -> V_114 ) ;
F_147 ( V_4 -> V_114 ) ;
F_67 ( V_4 ) ;
return 0 ;
}
static T_5 F_152 ( struct V_168 * V_168 ,
struct V_169 * V_42 ,
char * V_43 )
{
int V_59 ;
F_122 ( & V_170 ) ;
V_59 = F_129 () ;
F_123 ( & V_170 ) ;
if ( V_59 < 0 )
return V_59 ;
return F_29 ( V_43 , V_22 , L_9 , V_59 ) ;
}
static T_5 F_153 ( struct V_168 * V_168 ,
struct V_169 * V_42 ,
const char * V_43 ,
T_2 V_171 )
{
struct V_4 * V_4 ;
int V_59 , V_172 ;
V_59 = F_154 ( V_43 , 10 , & V_172 ) ;
if ( V_59 )
return V_59 ;
if ( V_172 < 0 )
return - V_53 ;
F_122 ( & V_170 ) ;
V_4 = F_155 ( & V_148 , V_172 ) ;
if ( V_4 ) {
V_59 = F_150 ( V_4 ) ;
if ( ! V_59 )
F_149 ( & V_148 , V_172 ) ;
} else {
V_59 = - V_173 ;
}
F_123 ( & V_170 ) ;
return V_59 ? V_59 : V_171 ;
}
static int F_156 ( int V_174 , void * V_35 , void * V_175 )
{
F_150 ( V_35 ) ;
return 0 ;
}
static void F_157 ( void )
{
F_158 ( & V_176 ) ;
F_159 ( & V_148 , & F_156 , NULL ) ;
F_160 ( & V_148 ) ;
F_161 ( V_153 , L_28 ) ;
}
static int T_8 F_162 ( void )
{
int V_59 ;
V_59 = F_163 ( & V_176 ) ;
if ( V_59 ) {
F_71 ( L_29 ) ;
return V_59 ;
}
V_153 = F_164 ( 0 , L_28 ) ;
if ( V_153 <= 0 ) {
F_71 ( L_30 ) ;
F_158 ( & V_176 ) ;
return - V_58 ;
}
while ( V_177 != 0 ) {
F_122 ( & V_170 ) ;
V_59 = F_129 () ;
F_123 ( & V_170 ) ;
if ( V_59 < 0 )
goto V_79;
V_177 -- ;
}
return 0 ;
V_79:
F_157 () ;
return V_59 ;
}
static void T_9 F_165 ( void )
{
F_157 () ;
}
