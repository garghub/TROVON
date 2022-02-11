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
T_2 V_55 ;
if ( ! F_51 ( V_43 ) )
return - V_53 ;
F_38 ( & V_4 -> V_45 ) ;
if ( F_4 ( V_4 ) ) {
F_40 ( & V_4 -> V_45 ) ;
F_52 ( L_10 ) ;
return - V_57 ;
}
F_53 ( V_4 -> V_56 , V_43 , sizeof( V_4 -> V_56 ) ) ;
V_55 = strlen ( V_4 -> V_56 ) ;
if ( V_55 > 0 && V_4 -> V_56 [ V_55 - 1 ] == '\n' )
V_4 -> V_56 [ V_55 - 1 ] = 0x00 ;
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
T_5 V_58 ;
F_27 ( & V_4 -> V_45 ) ;
V_58 = F_29 ( V_43 , V_22 ,
L_11 ,
( T_4 ) F_32 ( & V_4 -> V_33 . V_59 ) ,
( T_4 ) F_32 ( & V_4 -> V_33 . V_60 ) ,
( T_4 ) F_32 ( & V_4 -> V_33 . V_61 ) ,
( T_4 ) F_32 ( & V_4 -> V_33 . V_62 ) ) ;
F_28 ( & V_4 -> V_45 ) ;
return V_58 ;
}
static T_5 F_57 ( struct V_6 * V_7 ,
struct V_41 * V_42 , char * V_43 )
{
struct V_4 * V_4 = F_5 ( V_7 ) ;
struct V_63 V_64 ;
T_4 V_65 , V_66 = 0 ;
long V_67 ;
T_5 V_58 ;
memset ( & V_64 , 0x00 , sizeof( struct V_63 ) ) ;
F_27 ( & V_4 -> V_45 ) ;
if ( F_4 ( V_4 ) ) {
V_66 = F_34 ( V_4 -> V_10 -> V_48 ) ;
V_63 ( V_4 -> V_10 -> V_48 , & V_64 ) ;
}
V_65 = F_32 ( & V_4 -> V_33 . V_46 ) ;
V_67 = F_18 ( & V_4 -> V_33 . V_34 ) ;
V_58 = F_29 ( V_43 , V_22 ,
L_12 ,
V_65 << V_47 ,
( T_4 ) F_32 ( & V_4 -> V_33 . V_68 ) ,
V_66 << V_47 ,
V_4 -> V_49 << V_47 ,
V_67 << V_47 ,
( T_4 ) F_32 ( & V_4 -> V_33 . V_69 ) ,
V_64 . V_70 ) ;
F_28 ( & V_4 -> V_45 ) ;
return V_58 ;
}
static T_5 F_58 ( struct V_6 * V_7 ,
struct V_41 * V_42 , char * V_43 )
{
int V_71 = 1 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
T_5 V_58 ;
F_27 ( & V_4 -> V_45 ) ;
V_58 = F_29 ( V_43 , V_22 ,
L_13 ,
V_71 ,
( T_4 ) F_32 ( & V_4 -> V_33 . V_72 ) ) ;
F_28 ( & V_4 -> V_45 ) ;
return V_58 ;
}
static inline bool F_59 ( struct V_4 * V_4 )
{
if ( F_60 ( & V_4 -> V_73 ) )
return true ;
return false ;
}
static inline void F_61 ( struct V_4 * V_4 )
{
F_62 ( & V_4 -> V_73 ) ;
}
static void F_63 ( struct V_9 * V_10 , T_4 V_5 )
{
T_2 V_74 = V_5 >> V_47 ;
T_2 V_11 ;
for ( V_11 = 0 ; V_11 < V_74 ; V_11 ++ ) {
unsigned long V_75 = V_10 -> V_14 [ V_11 ] . V_75 ;
if ( ! V_75 )
continue;
F_64 ( V_10 -> V_48 , V_75 ) ;
}
F_65 ( V_10 -> V_48 ) ;
F_66 ( V_10 -> V_14 ) ;
F_67 ( V_10 ) ;
}
static struct V_9 * F_68 ( char * V_76 , T_4 V_5 )
{
T_2 V_74 ;
struct V_9 * V_10 = F_69 ( sizeof( * V_10 ) , V_77 ) ;
if ( ! V_10 )
return NULL ;
V_74 = V_5 >> V_47 ;
V_10 -> V_14 = F_70 ( V_74 * sizeof( * V_10 -> V_14 ) ) ;
if ( ! V_10 -> V_14 ) {
F_71 ( L_14 ) ;
goto V_78;
}
V_10 -> V_48 = F_72 ( V_76 ) ;
if ( ! V_10 -> V_48 ) {
F_71 ( L_15 ) ;
goto V_78;
}
return V_10 ;
V_78:
F_66 ( V_10 -> V_14 ) ;
F_67 ( V_10 ) ;
return NULL ;
}
static void F_73 ( struct V_4 * V_4 , T_2 V_11 )
{
struct V_9 * V_10 = V_4 -> V_10 ;
unsigned long V_75 = V_10 -> V_14 [ V_11 ] . V_75 ;
if ( F_15 ( ! V_75 ) ) {
if ( F_7 ( V_10 , V_11 , V_79 ) ) {
F_10 ( V_10 , V_11 , V_79 ) ;
F_74 ( & V_4 -> V_33 . V_69 ) ;
}
return;
}
F_64 ( V_10 -> V_48 , V_75 ) ;
F_75 ( F_11 ( V_10 , V_11 ) ,
& V_4 -> V_33 . V_68 ) ;
F_74 ( & V_4 -> V_33 . V_46 ) ;
V_10 -> V_14 [ V_11 ] . V_75 = 0 ;
F_12 ( V_10 , V_11 , 0 ) ;
}
static int F_76 ( struct V_4 * V_4 , char * V_80 , T_1 V_11 )
{
int V_58 = 0 ;
unsigned char * V_81 ;
struct V_9 * V_10 = V_4 -> V_10 ;
unsigned long V_75 ;
T_2 V_17 ;
F_77 ( V_82 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
V_75 = V_10 -> V_14 [ V_11 ] . V_75 ;
V_17 = F_11 ( V_10 , V_11 ) ;
if ( ! V_75 || F_7 ( V_10 , V_11 , V_79 ) ) {
F_78 ( V_82 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_23 ( V_80 ) ;
return 0 ;
}
V_81 = F_79 ( V_10 -> V_48 , V_75 , V_83 ) ;
if ( V_17 == V_22 )
F_80 ( V_80 , V_81 ) ;
else
V_58 = F_81 ( V_4 -> V_84 , V_81 , V_17 , V_80 ) ;
F_82 ( V_10 -> V_48 , V_75 ) ;
F_78 ( V_82 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
if ( F_15 ( V_58 ) ) {
F_71 ( L_16 , V_58 , V_11 ) ;
return V_58 ;
}
return 0 ;
}
static int F_83 ( struct V_4 * V_4 , struct V_19 * V_20 ,
T_1 V_11 , int V_29 )
{
int V_58 ;
struct V_37 * V_37 ;
unsigned char * V_39 , * V_85 = NULL ;
struct V_9 * V_10 = V_4 -> V_10 ;
V_37 = V_20 -> V_38 ;
F_77 ( V_82 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
if ( F_15 ( ! V_10 -> V_14 [ V_11 ] . V_75 ) ||
F_7 ( V_10 , V_11 , V_79 ) ) {
F_78 ( V_82 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_21 ( V_20 ) ;
return 0 ;
}
F_78 ( V_82 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
if ( F_13 ( V_20 ) )
V_85 = F_69 ( V_22 , V_86 ) ;
V_39 = F_22 ( V_37 ) ;
if ( ! F_13 ( V_20 ) )
V_85 = V_39 ;
if ( ! V_85 ) {
F_71 ( L_17 ) ;
V_58 = - V_87 ;
goto V_88;
}
V_58 = F_76 ( V_4 , V_85 , V_11 ) ;
if ( F_15 ( V_58 ) )
goto V_88;
if ( F_13 ( V_20 ) )
memcpy ( V_39 + V_20 -> V_40 , V_85 + V_29 ,
V_20 -> V_21 ) ;
F_25 ( V_37 ) ;
V_58 = 0 ;
V_88:
F_24 ( V_39 ) ;
if ( F_13 ( V_20 ) )
F_67 ( V_85 ) ;
return V_58 ;
}
static int F_84 ( struct V_4 * V_4 , struct V_19 * V_20 , T_1 V_11 ,
int V_29 )
{
int V_58 = 0 ;
T_2 V_89 ;
unsigned long V_75 = 0 ;
struct V_37 * V_37 ;
unsigned char * V_39 , * V_81 , * V_90 , * V_85 = NULL ;
struct V_9 * V_10 = V_4 -> V_10 ;
struct V_91 * V_92 = NULL ;
unsigned long V_93 ;
V_37 = V_20 -> V_38 ;
if ( F_13 ( V_20 ) ) {
V_85 = F_69 ( V_22 , V_86 ) ;
if ( ! V_85 ) {
V_58 = - V_87 ;
goto V_94;
}
V_58 = F_76 ( V_4 , V_85 , V_11 ) ;
if ( V_58 )
goto V_94;
}
V_95:
V_39 = F_22 ( V_37 ) ;
if ( F_13 ( V_20 ) ) {
memcpy ( V_85 + V_29 , V_39 + V_20 -> V_40 ,
V_20 -> V_21 ) ;
F_24 ( V_39 ) ;
V_39 = NULL ;
} else {
V_85 = V_39 ;
}
if ( F_20 ( V_85 ) ) {
if ( V_39 )
F_24 ( V_39 ) ;
F_77 ( V_82 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_73 ( V_4 , V_11 ) ;
F_9 ( V_10 , V_11 , V_79 ) ;
F_78 ( V_82 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_85 ( & V_4 -> V_33 . V_69 ) ;
V_58 = 0 ;
goto V_94;
}
V_92 = F_86 ( V_4 -> V_84 ) ;
V_58 = F_87 ( V_4 -> V_84 , V_92 , V_85 , & V_89 ) ;
if ( ! F_13 ( V_20 ) ) {
F_24 ( V_39 ) ;
V_39 = NULL ;
V_85 = NULL ;
}
if ( F_15 ( V_58 ) ) {
F_71 ( L_18 , V_58 ) ;
goto V_94;
}
V_90 = V_92 -> V_96 ;
if ( F_15 ( V_89 > V_97 ) ) {
V_89 = V_22 ;
if ( F_13 ( V_20 ) )
V_90 = V_85 ;
}
if ( ! V_75 )
V_75 = F_88 ( V_10 -> V_48 , V_89 ,
V_98 |
V_99 |
V_100 ) ;
if ( ! V_75 ) {
F_89 ( V_4 -> V_84 , V_92 ) ;
V_92 = NULL ;
F_85 ( & V_4 -> V_33 . V_72 ) ;
V_75 = F_88 ( V_10 -> V_48 , V_89 ,
V_86 | V_100 ) ;
if ( V_75 )
goto V_95;
F_71 ( L_19 ,
V_11 , V_89 ) ;
V_58 = - V_87 ;
goto V_94;
}
V_93 = F_34 ( V_10 -> V_48 ) ;
F_17 ( V_4 , V_93 ) ;
if ( V_4 -> V_49 && V_93 > V_4 -> V_49 ) {
F_64 ( V_10 -> V_48 , V_75 ) ;
V_58 = - V_87 ;
goto V_94;
}
V_81 = F_79 ( V_10 -> V_48 , V_75 , V_101 ) ;
if ( ( V_89 == V_22 ) && ! F_13 ( V_20 ) ) {
V_90 = F_22 ( V_37 ) ;
F_80 ( V_81 , V_90 ) ;
F_24 ( V_90 ) ;
} else {
memcpy ( V_81 , V_90 , V_89 ) ;
}
F_89 ( V_4 -> V_84 , V_92 ) ;
V_92 = NULL ;
F_82 ( V_10 -> V_48 , V_75 ) ;
F_77 ( V_82 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_73 ( V_4 , V_11 ) ;
V_10 -> V_14 [ V_11 ] . V_75 = V_75 ;
F_12 ( V_10 , V_11 , V_89 ) ;
F_78 ( V_82 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_90 ( V_89 , & V_4 -> V_33 . V_68 ) ;
F_85 ( & V_4 -> V_33 . V_46 ) ;
V_94:
if ( V_92 )
F_89 ( V_4 -> V_84 , V_92 ) ;
if ( F_13 ( V_20 ) )
F_67 ( V_85 ) ;
return V_58 ;
}
static void F_91 ( struct V_4 * V_4 , T_1 V_11 ,
int V_29 , struct V_102 * V_102 )
{
T_2 V_103 = V_102 -> V_104 . V_105 ;
struct V_9 * V_10 = V_4 -> V_10 ;
if ( V_29 ) {
if ( V_103 <= ( V_22 - V_29 ) )
return;
V_103 -= ( V_22 - V_29 ) ;
V_11 ++ ;
}
while ( V_103 >= V_22 ) {
F_77 ( V_82 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_73 ( V_4 , V_11 ) ;
F_78 ( V_82 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_85 ( & V_4 -> V_33 . V_62 ) ;
V_11 ++ ;
V_103 -= V_22 ;
}
}
static int F_92 ( struct V_4 * V_4 , struct V_19 * V_20 , T_1 V_11 ,
int V_29 , int V_106 )
{
unsigned long V_107 = V_108 ;
int V_58 ;
F_93 ( V_106 , V_20 -> V_21 >> V_28 ,
& V_4 -> V_109 -> V_110 ) ;
if ( V_106 == V_111 ) {
F_85 ( & V_4 -> V_33 . V_112 ) ;
V_58 = F_83 ( V_4 , V_20 , V_11 , V_29 ) ;
} else {
F_85 ( & V_4 -> V_33 . V_113 ) ;
V_58 = F_84 ( V_4 , V_20 , V_11 , V_29 ) ;
}
F_94 ( V_106 , & V_4 -> V_109 -> V_110 , V_107 ) ;
if ( F_15 ( V_58 ) ) {
if ( V_106 == V_111 )
F_85 ( & V_4 -> V_33 . V_59 ) ;
else
F_85 ( & V_4 -> V_33 . V_60 ) ;
}
return V_58 ;
}
static void F_95 ( struct V_4 * V_4 , struct V_102 * V_102 )
{
int V_29 , V_106 ;
T_1 V_11 ;
struct V_19 V_20 ;
struct V_114 V_115 ;
V_11 = V_102 -> V_104 . V_116 >> V_117 ;
V_29 = ( V_102 -> V_104 . V_116 &
( V_118 - 1 ) ) << V_28 ;
if ( F_15 ( V_102 -> V_119 & V_120 ) ) {
F_91 ( V_4 , V_11 , V_29 , V_102 ) ;
F_96 ( V_102 ) ;
return;
}
V_106 = F_97 ( V_102 ) ;
F_98 (bvec, bio, iter) {
int V_121 = V_22 - V_29 ;
if ( V_20 . V_21 > V_121 ) {
struct V_19 V_122 ;
V_122 . V_38 = V_20 . V_38 ;
V_122 . V_21 = V_121 ;
V_122 . V_40 = V_20 . V_40 ;
if ( F_92 ( V_4 , & V_122 , V_11 , V_29 , V_106 ) < 0 )
goto V_94;
V_122 . V_21 = V_20 . V_21 - V_121 ;
V_122 . V_40 += V_121 ;
if ( F_92 ( V_4 , & V_122 , V_11 + 1 , 0 , V_106 ) < 0 )
goto V_94;
} else
if ( F_92 ( V_4 , & V_20 , V_11 , V_29 , V_106 ) < 0 )
goto V_94;
F_16 ( & V_11 , & V_29 , & V_20 ) ;
}
F_96 ( V_102 ) ;
return;
V_94:
F_99 ( V_102 ) ;
}
static T_6 F_100 ( struct V_123 * V_124 , struct V_102 * V_102 )
{
struct V_4 * V_4 = V_124 -> V_125 ;
if ( F_15 ( ! F_59 ( V_4 ) ) )
goto error;
F_101 ( V_124 , & V_102 , V_124 -> V_126 ) ;
if ( ! F_14 ( V_4 , V_102 -> V_104 . V_116 ,
V_102 -> V_104 . V_105 ) ) {
F_85 ( & V_4 -> V_33 . V_61 ) ;
goto V_127;
}
F_95 ( V_4 , V_102 ) ;
F_61 ( V_4 ) ;
return V_128 ;
V_127:
F_61 ( V_4 ) ;
error:
F_99 ( V_102 ) ;
return V_128 ;
}
static void F_102 ( struct V_129 * V_130 ,
unsigned long V_11 )
{
struct V_4 * V_4 ;
struct V_9 * V_10 ;
V_4 = V_130 -> V_131 -> V_8 ;
V_10 = V_4 -> V_10 ;
F_77 ( V_82 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_73 ( V_4 , V_11 ) ;
F_78 ( V_82 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_85 ( & V_4 -> V_33 . V_62 ) ;
}
static int F_103 ( struct V_129 * V_130 , T_3 V_132 ,
struct V_37 * V_37 , int V_106 )
{
int V_29 , V_54 = - V_133 ;
T_1 V_11 ;
struct V_4 * V_4 ;
struct V_19 V_122 ;
V_4 = V_130 -> V_131 -> V_8 ;
if ( F_15 ( ! F_59 ( V_4 ) ) )
goto V_94;
if ( ! F_14 ( V_4 , V_132 , V_22 ) ) {
F_85 ( & V_4 -> V_33 . V_61 ) ;
V_54 = - V_53 ;
goto V_127;
}
V_11 = V_132 >> V_117 ;
V_29 = V_132 & ( V_118 - 1 ) << V_28 ;
V_122 . V_38 = V_37 ;
V_122 . V_21 = V_22 ;
V_122 . V_40 = 0 ;
V_54 = F_92 ( V_4 , & V_122 , V_11 , V_29 , V_106 ) ;
V_127:
F_61 ( V_4 ) ;
V_94:
if ( V_54 == 0 )
F_104 ( V_37 , V_106 , 0 ) ;
return V_54 ;
}
static void F_105 ( struct V_4 * V_4 )
{
struct V_9 * V_10 ;
struct V_134 * V_84 ;
T_4 V_5 ;
F_38 ( & V_4 -> V_45 ) ;
V_4 -> V_49 = 0 ;
if ( ! F_4 ( V_4 ) ) {
F_40 ( & V_4 -> V_45 ) ;
return;
}
V_10 = V_4 -> V_10 ;
V_84 = V_4 -> V_84 ;
V_5 = V_4 -> V_5 ;
F_61 ( V_4 ) ;
F_106 ( V_4 -> V_135 , F_107 ( & V_4 -> V_73 ) == 0 ) ;
memset ( & V_4 -> V_33 , 0 , sizeof( V_4 -> V_33 ) ) ;
V_4 -> V_5 = 0 ;
F_108 ( V_4 -> V_109 , 0 ) ;
F_109 ( & V_4 -> V_109 -> V_110 , 0 ) ;
F_40 ( & V_4 -> V_45 ) ;
F_63 ( V_10 , V_5 ) ;
F_110 ( V_84 ) ;
}
static T_5 F_111 ( struct V_6 * V_7 ,
struct V_41 * V_42 , const char * V_43 , T_2 V_50 )
{
T_4 V_5 ;
struct V_134 * V_84 ;
struct V_9 * V_10 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
int V_54 ;
V_5 = F_37 ( V_43 , NULL ) ;
if ( ! V_5 )
return - V_53 ;
V_5 = F_39 ( V_5 ) ;
V_10 = F_68 ( V_4 -> V_109 -> V_136 , V_5 ) ;
if ( ! V_10 )
return - V_87 ;
V_84 = F_112 ( V_4 -> V_56 ) ;
if ( F_113 ( V_84 ) ) {
F_71 ( L_20 ,
V_4 -> V_56 ) ;
V_54 = F_114 ( V_84 ) ;
goto V_137;
}
F_38 ( & V_4 -> V_45 ) ;
if ( F_4 ( V_4 ) ) {
F_52 ( L_21 ) ;
V_54 = - V_57 ;
goto V_138;
}
F_115 ( & V_4 -> V_135 ) ;
F_116 ( & V_4 -> V_73 , 1 ) ;
V_4 -> V_10 = V_10 ;
V_4 -> V_84 = V_84 ;
V_4 -> V_5 = V_5 ;
F_108 ( V_4 -> V_109 , V_4 -> V_5 >> V_28 ) ;
F_40 ( & V_4 -> V_45 ) ;
F_117 ( V_4 -> V_109 ) ;
return V_50 ;
V_138:
F_40 ( & V_4 -> V_45 ) ;
F_110 ( V_84 ) ;
V_137:
F_63 ( V_10 , V_5 ) ;
return V_54 ;
}
static T_5 F_118 ( struct V_6 * V_7 ,
struct V_41 * V_42 , const char * V_43 , T_2 V_50 )
{
int V_58 ;
unsigned short V_139 ;
struct V_4 * V_4 ;
struct V_129 * V_130 ;
V_58 = F_119 ( V_43 , 10 , & V_139 ) ;
if ( V_58 )
return V_58 ;
if ( ! V_139 )
return - V_53 ;
V_4 = F_5 ( V_7 ) ;
V_130 = F_120 ( V_4 -> V_109 , 0 ) ;
if ( ! V_130 )
return - V_87 ;
F_121 ( & V_130 -> V_140 ) ;
if ( V_130 -> V_141 || V_4 -> V_142 ) {
F_122 ( & V_130 -> V_140 ) ;
F_123 ( V_130 ) ;
return - V_57 ;
}
V_4 -> V_142 = true ;
F_122 ( & V_130 -> V_140 ) ;
F_124 ( V_130 ) ;
F_105 ( V_4 ) ;
F_117 ( V_4 -> V_109 ) ;
F_123 ( V_130 ) ;
F_121 ( & V_130 -> V_140 ) ;
V_4 -> V_142 = false ;
F_122 ( & V_130 -> V_140 ) ;
return V_50 ;
}
static int F_125 ( struct V_129 * V_130 , T_7 V_143 )
{
int V_58 = 0 ;
struct V_4 * V_4 ;
F_126 ( ! F_127 ( & V_130 -> V_140 ) ) ;
V_4 = V_130 -> V_131 -> V_8 ;
if ( V_4 -> V_142 )
V_58 = - V_57 ;
return V_58 ;
}
static int F_128 ( void )
{
struct V_4 * V_4 ;
struct V_123 * V_124 ;
int V_58 , V_144 ;
V_4 = F_129 ( sizeof( struct V_4 ) , V_77 ) ;
if ( ! V_4 )
return - V_87 ;
V_58 = F_130 ( & V_145 , V_4 , 0 , 0 , V_77 ) ;
if ( V_58 < 0 )
goto V_146;
V_144 = V_58 ;
F_131 ( & V_4 -> V_45 ) ;
V_124 = F_132 ( V_77 ) ;
if ( ! V_124 ) {
F_71 ( L_22 ,
V_144 ) ;
V_58 = - V_87 ;
goto V_147;
}
F_133 ( V_124 , F_100 ) ;
V_4 -> V_109 = F_134 ( 1 ) ;
if ( ! V_4 -> V_109 ) {
F_71 ( L_23 ,
V_144 ) ;
V_58 = - V_87 ;
goto V_148;
}
V_4 -> V_109 -> V_149 = V_150 ;
V_4 -> V_109 -> V_151 = V_144 ;
V_4 -> V_109 -> V_152 = & V_153 ;
V_4 -> V_109 -> V_124 = V_124 ;
V_4 -> V_109 -> V_124 -> V_125 = V_4 ;
V_4 -> V_109 -> V_8 = V_4 ;
snprintf ( V_4 -> V_109 -> V_136 , 16 , L_24 , V_144 ) ;
F_108 ( V_4 -> V_109 , 0 ) ;
F_135 ( V_154 , V_4 -> V_109 -> V_124 ) ;
F_136 ( V_155 , V_4 -> V_109 -> V_124 ) ;
F_137 ( V_4 -> V_109 -> V_124 , V_22 ) ;
F_138 ( V_4 -> V_109 -> V_124 ,
V_27 ) ;
F_139 ( V_4 -> V_109 -> V_124 , V_22 ) ;
F_140 ( V_4 -> V_109 -> V_124 , V_22 ) ;
V_4 -> V_109 -> V_124 -> V_156 . V_157 = V_22 ;
F_141 ( V_4 -> V_109 -> V_124 , V_158 ) ;
if ( V_27 == V_22 )
V_4 -> V_109 -> V_124 -> V_156 . V_159 = 1 ;
else
V_4 -> V_109 -> V_124 -> V_156 . V_159 = 0 ;
F_135 ( V_160 , V_4 -> V_109 -> V_124 ) ;
F_142 ( V_4 -> V_109 ) ;
V_58 = F_143 ( & F_144 ( V_4 -> V_109 ) -> V_161 ,
& V_162 ) ;
if ( V_58 < 0 ) {
F_71 ( L_25 ,
V_144 ) ;
goto V_163;
}
F_53 ( V_4 -> V_56 , V_164 , sizeof( V_4 -> V_56 ) ) ;
V_4 -> V_10 = NULL ;
F_52 ( L_26 , V_4 -> V_109 -> V_136 ) ;
return V_144 ;
V_163:
F_145 ( V_4 -> V_109 ) ;
F_146 ( V_4 -> V_109 ) ;
V_148:
F_147 ( V_124 ) ;
V_147:
F_148 ( & V_145 , V_144 ) ;
V_146:
F_67 ( V_4 ) ;
return V_58 ;
}
static int F_149 ( struct V_4 * V_4 )
{
struct V_129 * V_130 ;
V_130 = F_120 ( V_4 -> V_109 , 0 ) ;
if ( ! V_130 )
return - V_87 ;
F_121 ( & V_130 -> V_140 ) ;
if ( V_130 -> V_141 || V_4 -> V_142 ) {
F_122 ( & V_130 -> V_140 ) ;
F_123 ( V_130 ) ;
return - V_57 ;
}
V_4 -> V_142 = true ;
F_122 ( & V_130 -> V_140 ) ;
F_150 ( & F_144 ( V_4 -> V_109 ) -> V_161 ,
& V_162 ) ;
F_124 ( V_130 ) ;
F_105 ( V_4 ) ;
F_123 ( V_130 ) ;
F_52 ( L_27 , V_4 -> V_109 -> V_136 ) ;
F_147 ( V_4 -> V_109 -> V_124 ) ;
F_145 ( V_4 -> V_109 ) ;
F_146 ( V_4 -> V_109 ) ;
F_67 ( V_4 ) ;
return 0 ;
}
static T_5 F_151 ( struct V_165 * V_165 ,
struct V_166 * V_42 ,
char * V_43 )
{
int V_58 ;
F_121 ( & V_167 ) ;
V_58 = F_128 () ;
F_122 ( & V_167 ) ;
if ( V_58 < 0 )
return V_58 ;
return F_29 ( V_43 , V_22 , L_9 , V_58 ) ;
}
static T_5 F_152 ( struct V_165 * V_165 ,
struct V_166 * V_42 ,
const char * V_43 ,
T_2 V_168 )
{
struct V_4 * V_4 ;
int V_58 , V_169 ;
V_58 = F_153 ( V_43 , 10 , & V_169 ) ;
if ( V_58 )
return V_58 ;
if ( V_169 < 0 )
return - V_53 ;
F_121 ( & V_167 ) ;
V_4 = F_154 ( & V_145 , V_169 ) ;
if ( V_4 ) {
V_58 = F_149 ( V_4 ) ;
F_148 ( & V_145 , V_169 ) ;
} else {
V_58 = - V_170 ;
}
F_122 ( & V_167 ) ;
return V_58 ? V_58 : V_168 ;
}
static int F_155 ( int V_171 , void * V_35 , void * V_172 )
{
F_149 ( V_35 ) ;
return 0 ;
}
static void F_156 ( void )
{
F_157 ( & V_173 ) ;
F_158 ( & V_145 , & F_155 , NULL ) ;
F_159 ( & V_145 ) ;
F_160 ( V_150 , L_28 ) ;
}
static int T_8 F_161 ( void )
{
int V_58 ;
V_58 = F_162 ( & V_173 ) ;
if ( V_58 ) {
F_71 ( L_29 ) ;
return V_58 ;
}
V_150 = F_163 ( 0 , L_28 ) ;
if ( V_150 <= 0 ) {
F_71 ( L_30 ) ;
F_157 ( & V_173 ) ;
return - V_57 ;
}
while ( V_174 != 0 ) {
F_121 ( & V_167 ) ;
V_58 = F_128 () ;
F_122 ( & V_167 ) ;
if ( V_58 < 0 )
goto V_78;
V_174 -- ;
}
return 0 ;
V_78:
F_156 () ;
return V_58 ;
}
static void T_9 F_164 ( void )
{
F_156 () ;
}
