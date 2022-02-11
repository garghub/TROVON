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
static void F_14 ( struct V_4 * V_4 )
{
F_15 ( V_4 -> V_23 ) ;
V_4 -> V_23 -> V_24 -> V_25 . V_26 |=
V_27 ;
}
static inline bool F_16 ( struct V_4 * V_4 ,
T_3 V_28 , unsigned int V_17 )
{
T_4 V_29 , V_30 ;
if ( F_17 ( V_28 & ( V_31 - 1 ) ) )
return false ;
if ( F_17 ( V_17 & ( V_32 - 1 ) ) )
return false ;
V_29 = V_28 + ( V_17 >> V_33 ) ;
V_30 = V_4 -> V_5 >> V_33 ;
if ( F_17 ( V_28 >= V_30 || V_29 > V_30 || V_28 > V_29 ) )
return false ;
return true ;
}
static void F_18 ( T_1 * V_11 , int * V_34 , struct V_19 * V_20 )
{
if ( * V_34 + V_20 -> V_21 >= V_22 )
( * V_11 ) ++ ;
* V_34 = ( * V_34 + V_20 -> V_21 ) % V_22 ;
}
static inline void F_19 ( struct V_4 * V_4 ,
const unsigned long V_35 )
{
unsigned long V_36 , V_37 ;
V_36 = F_20 ( & V_4 -> V_38 . V_39 ) ;
do {
V_37 = V_36 ;
if ( V_35 > V_37 )
V_36 = F_21 (
& V_4 -> V_38 . V_39 , V_37 , V_35 ) ;
} while ( V_36 != V_37 );
}
static bool F_22 ( void * V_40 )
{
unsigned int V_41 ;
unsigned long * V_42 ;
V_42 = ( unsigned long * ) V_40 ;
for ( V_41 = 0 ; V_41 != V_22 / sizeof( * V_42 ) ; V_41 ++ ) {
if ( V_42 [ V_41 ] )
return false ;
}
return true ;
}
static void F_23 ( struct V_19 * V_20 )
{
struct V_42 * V_42 = V_20 -> V_43 ;
void * V_44 ;
V_44 = F_24 ( V_42 ) ;
if ( F_13 ( V_20 ) )
memset ( V_44 + V_20 -> V_45 , 0 , V_20 -> V_21 ) ;
else
F_25 ( V_44 ) ;
F_26 ( V_44 ) ;
F_27 ( V_42 ) ;
}
static T_5 F_28 ( struct V_6 * V_7 ,
struct V_46 * V_47 , char * V_48 )
{
T_1 V_49 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
F_29 ( & V_4 -> V_50 ) ;
V_49 = F_4 ( V_4 ) ;
F_30 ( & V_4 -> V_50 ) ;
return F_31 ( V_48 , V_22 , L_3 , V_49 ) ;
}
static T_5 F_32 ( struct V_6 * V_7 ,
struct V_46 * V_47 , char * V_48 )
{
struct V_4 * V_4 = F_5 ( V_7 ) ;
return F_31 ( V_48 , V_22 , L_4 , V_4 -> V_5 ) ;
}
static T_5 F_33 ( struct V_6 * V_7 ,
struct V_46 * V_47 , char * V_48 )
{
struct V_4 * V_4 = F_5 ( V_7 ) ;
F_1 ( L_5 ) ;
return F_31 ( V_48 , V_22 , L_4 ,
( T_4 ) ( F_34 ( & V_4 -> V_38 . V_51 ) ) << V_52 ) ;
}
static T_5 F_35 ( struct V_6 * V_7 ,
struct V_46 * V_47 , char * V_48 )
{
T_4 V_49 = 0 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
F_1 ( L_6 ) ;
F_29 ( & V_4 -> V_50 ) ;
if ( F_4 ( V_4 ) ) {
struct V_9 * V_10 = V_4 -> V_10 ;
V_49 = F_36 ( V_10 -> V_53 ) ;
}
F_30 ( & V_4 -> V_50 ) ;
return F_31 ( V_48 , V_22 , L_4 , V_49 << V_52 ) ;
}
static T_5 F_37 ( struct V_6 * V_7 ,
struct V_46 * V_47 , char * V_48 )
{
T_4 V_49 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
F_1 ( L_7 ) ;
F_29 ( & V_4 -> V_50 ) ;
V_49 = V_4 -> V_54 ;
F_30 ( & V_4 -> V_50 ) ;
return F_31 ( V_48 , V_22 , L_4 , V_49 << V_52 ) ;
}
static T_5 F_38 ( struct V_6 * V_7 ,
struct V_46 * V_47 , const char * V_48 , T_2 V_55 )
{
T_4 V_56 ;
char * V_57 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
V_56 = F_39 ( V_48 , & V_57 ) ;
if ( V_48 == V_57 )
return - V_58 ;
F_40 ( & V_4 -> V_50 ) ;
V_4 -> V_54 = F_41 ( V_56 ) >> V_52 ;
F_42 ( & V_4 -> V_50 ) ;
return V_55 ;
}
static T_5 F_43 ( struct V_6 * V_7 ,
struct V_46 * V_47 , char * V_48 )
{
T_4 V_49 = 0 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
F_1 ( L_8 ) ;
F_29 ( & V_4 -> V_50 ) ;
if ( F_4 ( V_4 ) )
V_49 = F_20 ( & V_4 -> V_38 . V_39 ) ;
F_30 ( & V_4 -> V_50 ) ;
return F_31 ( V_48 , V_22 , L_4 , V_49 << V_52 ) ;
}
static T_5 F_44 ( struct V_6 * V_7 ,
struct V_46 * V_47 , const char * V_48 , T_2 V_55 )
{
int V_59 ;
unsigned long V_49 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
V_59 = F_45 ( V_48 , 10 , & V_49 ) ;
if ( V_59 || V_49 != 0 )
return - V_58 ;
F_29 ( & V_4 -> V_50 ) ;
if ( F_4 ( V_4 ) ) {
struct V_9 * V_10 = V_4 -> V_10 ;
F_46 ( & V_4 -> V_38 . V_39 ,
F_36 ( V_10 -> V_53 ) ) ;
}
F_30 ( & V_4 -> V_50 ) ;
return V_55 ;
}
static T_5 F_47 ( struct V_6 * V_7 ,
struct V_46 * V_47 , char * V_48 )
{
return F_31 ( V_48 , V_22 , L_9 , F_48 () ) ;
}
static T_5 F_49 ( struct V_6 * V_7 ,
struct V_46 * V_47 , const char * V_48 , T_2 V_55 )
{
return V_55 ;
}
static T_5 F_50 ( struct V_6 * V_7 ,
struct V_46 * V_47 , char * V_48 )
{
T_2 V_60 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
F_29 ( & V_4 -> V_50 ) ;
V_60 = F_51 ( V_4 -> V_61 , V_48 ) ;
F_30 ( & V_4 -> V_50 ) ;
return V_60 ;
}
static T_5 F_52 ( struct V_6 * V_7 ,
struct V_46 * V_47 , const char * V_48 , T_2 V_55 )
{
struct V_4 * V_4 = F_5 ( V_7 ) ;
char V_61 [ V_62 ] ;
T_2 V_60 ;
F_53 ( V_61 , V_48 , sizeof( V_61 ) ) ;
V_60 = strlen ( V_61 ) ;
if ( V_60 > 0 && V_61 [ V_60 - 1 ] == '\n' )
V_61 [ V_60 - 1 ] = 0x00 ;
if ( ! F_54 ( V_61 ) )
return - V_58 ;
F_40 ( & V_4 -> V_50 ) ;
if ( F_4 ( V_4 ) ) {
F_42 ( & V_4 -> V_50 ) ;
F_55 ( L_10 ) ;
return - V_63 ;
}
F_53 ( V_4 -> V_61 , V_61 , sizeof( V_61 ) ) ;
F_42 ( & V_4 -> V_50 ) ;
return V_55 ;
}
static T_5 F_56 ( struct V_6 * V_7 ,
struct V_46 * V_47 , const char * V_48 , T_2 V_55 )
{
struct V_4 * V_4 = F_5 ( V_7 ) ;
struct V_9 * V_10 ;
F_29 ( & V_4 -> V_50 ) ;
if ( ! F_4 ( V_4 ) ) {
F_30 ( & V_4 -> V_50 ) ;
return - V_58 ;
}
V_10 = V_4 -> V_10 ;
F_57 ( V_10 -> V_53 ) ;
F_30 ( & V_4 -> V_50 ) ;
return V_55 ;
}
static T_5 F_58 ( struct V_6 * V_7 ,
struct V_46 * V_47 , char * V_48 )
{
struct V_4 * V_4 = F_5 ( V_7 ) ;
T_5 V_64 ;
F_29 ( & V_4 -> V_50 ) ;
V_64 = F_31 ( V_48 , V_22 ,
L_11 ,
( T_4 ) F_34 ( & V_4 -> V_38 . V_65 ) ,
( T_4 ) F_34 ( & V_4 -> V_38 . V_66 ) ,
( T_4 ) F_34 ( & V_4 -> V_38 . V_67 ) ,
( T_4 ) F_34 ( & V_4 -> V_38 . V_68 ) ) ;
F_30 ( & V_4 -> V_50 ) ;
return V_64 ;
}
static T_5 F_59 ( struct V_6 * V_7 ,
struct V_46 * V_47 , char * V_48 )
{
struct V_4 * V_4 = F_5 ( V_7 ) ;
struct V_69 V_70 ;
T_4 V_71 , V_72 = 0 ;
long V_73 ;
T_5 V_64 ;
memset ( & V_70 , 0x00 , sizeof( struct V_69 ) ) ;
F_29 ( & V_4 -> V_50 ) ;
if ( F_4 ( V_4 ) ) {
V_72 = F_36 ( V_4 -> V_10 -> V_53 ) ;
V_69 ( V_4 -> V_10 -> V_53 , & V_70 ) ;
}
V_71 = F_34 ( & V_4 -> V_38 . V_51 ) ;
V_73 = F_20 ( & V_4 -> V_38 . V_39 ) ;
V_64 = F_31 ( V_48 , V_22 ,
L_12 ,
V_71 << V_52 ,
( T_4 ) F_34 ( & V_4 -> V_38 . V_74 ) ,
V_72 << V_52 ,
V_4 -> V_54 << V_52 ,
V_73 << V_52 ,
( T_4 ) F_34 ( & V_4 -> V_38 . V_75 ) ,
V_70 . V_76 ) ;
F_30 ( & V_4 -> V_50 ) ;
return V_64 ;
}
static T_5 F_60 ( struct V_6 * V_7 ,
struct V_46 * V_47 , char * V_48 )
{
int V_77 = 1 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
T_5 V_64 ;
F_29 ( & V_4 -> V_50 ) ;
V_64 = F_31 ( V_48 , V_22 ,
L_13 ,
V_77 ,
( T_4 ) F_34 ( & V_4 -> V_38 . V_78 ) ) ;
F_30 ( & V_4 -> V_50 ) ;
return V_64 ;
}
static inline bool F_61 ( struct V_4 * V_4 )
{
if ( F_62 ( & V_4 -> V_79 ) )
return true ;
return false ;
}
static inline void F_63 ( struct V_4 * V_4 )
{
F_64 ( & V_4 -> V_79 ) ;
}
static void F_65 ( struct V_9 * V_10 , T_4 V_5 )
{
T_2 V_80 = V_5 >> V_52 ;
T_2 V_11 ;
for ( V_11 = 0 ; V_11 < V_80 ; V_11 ++ ) {
unsigned long V_81 = V_10 -> V_14 [ V_11 ] . V_81 ;
if ( ! V_81 )
continue;
F_66 ( V_10 -> V_53 , V_81 ) ;
}
F_67 ( V_10 -> V_53 ) ;
F_68 ( V_10 -> V_14 ) ;
F_69 ( V_10 ) ;
}
static struct V_9 * F_70 ( char * V_82 , T_4 V_5 )
{
T_2 V_80 ;
struct V_9 * V_10 = F_71 ( sizeof( * V_10 ) , V_83 ) ;
if ( ! V_10 )
return NULL ;
V_80 = V_5 >> V_52 ;
V_10 -> V_14 = F_72 ( V_80 * sizeof( * V_10 -> V_14 ) ) ;
if ( ! V_10 -> V_14 ) {
F_73 ( L_14 ) ;
goto V_84;
}
V_10 -> V_53 = F_74 ( V_82 ) ;
if ( ! V_10 -> V_53 ) {
F_73 ( L_15 ) ;
goto V_84;
}
return V_10 ;
V_84:
F_68 ( V_10 -> V_14 ) ;
F_69 ( V_10 ) ;
return NULL ;
}
static void F_75 ( struct V_4 * V_4 , T_2 V_11 )
{
struct V_9 * V_10 = V_4 -> V_10 ;
unsigned long V_81 = V_10 -> V_14 [ V_11 ] . V_81 ;
if ( F_17 ( ! V_81 ) ) {
if ( F_7 ( V_10 , V_11 , V_85 ) ) {
F_10 ( V_10 , V_11 , V_85 ) ;
F_76 ( & V_4 -> V_38 . V_75 ) ;
}
return;
}
F_66 ( V_10 -> V_53 , V_81 ) ;
F_77 ( F_11 ( V_10 , V_11 ) ,
& V_4 -> V_38 . V_74 ) ;
F_76 ( & V_4 -> V_38 . V_51 ) ;
V_10 -> V_14 [ V_11 ] . V_81 = 0 ;
F_12 ( V_10 , V_11 , 0 ) ;
}
static int F_78 ( struct V_4 * V_4 , char * V_86 , T_1 V_11 )
{
int V_64 = 0 ;
unsigned char * V_87 ;
struct V_9 * V_10 = V_4 -> V_10 ;
unsigned long V_81 ;
unsigned int V_17 ;
F_79 ( V_88 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
V_81 = V_10 -> V_14 [ V_11 ] . V_81 ;
V_17 = F_11 ( V_10 , V_11 ) ;
if ( ! V_81 || F_7 ( V_10 , V_11 , V_85 ) ) {
F_80 ( V_88 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_25 ( V_86 ) ;
return 0 ;
}
V_87 = F_81 ( V_10 -> V_53 , V_81 , V_89 ) ;
if ( V_17 == V_22 ) {
F_82 ( V_86 , V_87 ) ;
} else {
struct V_90 * V_91 = F_83 ( V_4 -> V_92 ) ;
V_64 = F_84 ( V_91 , V_87 , V_17 , V_86 ) ;
F_85 ( V_4 -> V_92 ) ;
}
F_86 ( V_10 -> V_53 , V_81 ) ;
F_80 ( V_88 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
if ( F_17 ( V_64 ) ) {
F_73 ( L_16 , V_64 , V_11 ) ;
return V_64 ;
}
return 0 ;
}
static int F_87 ( struct V_4 * V_4 , struct V_19 * V_20 ,
T_1 V_11 , int V_34 )
{
int V_64 ;
struct V_42 * V_42 ;
unsigned char * V_44 , * V_93 = NULL ;
struct V_9 * V_10 = V_4 -> V_10 ;
V_42 = V_20 -> V_43 ;
F_79 ( V_88 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
if ( F_17 ( ! V_10 -> V_14 [ V_11 ] . V_81 ) ||
F_7 ( V_10 , V_11 , V_85 ) ) {
F_80 ( V_88 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_23 ( V_20 ) ;
return 0 ;
}
F_80 ( V_88 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
if ( F_13 ( V_20 ) )
V_93 = F_71 ( V_22 , V_94 ) ;
V_44 = F_24 ( V_42 ) ;
if ( ! F_13 ( V_20 ) )
V_93 = V_44 ;
if ( ! V_93 ) {
F_73 ( L_17 ) ;
V_64 = - V_95 ;
goto V_96;
}
V_64 = F_78 ( V_4 , V_93 , V_11 ) ;
if ( F_17 ( V_64 ) )
goto V_96;
if ( F_13 ( V_20 ) )
memcpy ( V_44 + V_20 -> V_45 , V_93 + V_34 ,
V_20 -> V_21 ) ;
F_27 ( V_42 ) ;
V_64 = 0 ;
V_96:
F_26 ( V_44 ) ;
if ( F_13 ( V_20 ) )
F_69 ( V_93 ) ;
return V_64 ;
}
static int F_88 ( struct V_4 * V_4 , struct V_19 * V_20 , T_1 V_11 ,
int V_34 )
{
int V_64 = 0 ;
unsigned int V_97 ;
unsigned long V_81 = 0 ;
struct V_42 * V_42 ;
unsigned char * V_44 , * V_87 , * V_98 , * V_93 = NULL ;
struct V_9 * V_10 = V_4 -> V_10 ;
struct V_90 * V_91 = NULL ;
unsigned long V_99 ;
V_42 = V_20 -> V_43 ;
if ( F_13 ( V_20 ) ) {
V_93 = F_71 ( V_22 , V_94 ) ;
if ( ! V_93 ) {
V_64 = - V_95 ;
goto V_100;
}
V_64 = F_78 ( V_4 , V_93 , V_11 ) ;
if ( V_64 )
goto V_100;
}
V_101:
V_44 = F_24 ( V_42 ) ;
if ( F_13 ( V_20 ) ) {
memcpy ( V_93 + V_34 , V_44 + V_20 -> V_45 ,
V_20 -> V_21 ) ;
F_26 ( V_44 ) ;
V_44 = NULL ;
} else {
V_93 = V_44 ;
}
if ( F_22 ( V_93 ) ) {
if ( V_44 )
F_26 ( V_44 ) ;
F_79 ( V_88 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_75 ( V_4 , V_11 ) ;
F_9 ( V_10 , V_11 , V_85 ) ;
F_80 ( V_88 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_89 ( & V_4 -> V_38 . V_75 ) ;
V_64 = 0 ;
goto V_100;
}
V_91 = F_83 ( V_4 -> V_92 ) ;
V_64 = F_90 ( V_91 , V_93 , & V_97 ) ;
if ( ! F_13 ( V_20 ) ) {
F_26 ( V_44 ) ;
V_44 = NULL ;
V_93 = NULL ;
}
if ( F_17 ( V_64 ) ) {
F_73 ( L_18 , V_64 ) ;
goto V_100;
}
V_98 = V_91 -> V_102 ;
if ( F_17 ( V_97 > V_103 ) ) {
V_97 = V_22 ;
if ( F_13 ( V_20 ) )
V_98 = V_93 ;
}
if ( ! V_81 )
V_81 = F_91 ( V_10 -> V_53 , V_97 ,
V_104 |
V_105 |
V_106 |
V_107 ) ;
if ( ! V_81 ) {
F_85 ( V_4 -> V_92 ) ;
V_91 = NULL ;
F_89 ( & V_4 -> V_38 . V_78 ) ;
V_81 = F_91 ( V_10 -> V_53 , V_97 ,
V_94 | V_106 |
V_107 ) ;
if ( V_81 )
goto V_101;
F_73 ( L_19 ,
V_11 , V_97 ) ;
V_64 = - V_95 ;
goto V_100;
}
V_99 = F_36 ( V_10 -> V_53 ) ;
F_19 ( V_4 , V_99 ) ;
if ( V_4 -> V_54 && V_99 > V_4 -> V_54 ) {
F_66 ( V_10 -> V_53 , V_81 ) ;
V_64 = - V_95 ;
goto V_100;
}
V_87 = F_81 ( V_10 -> V_53 , V_81 , V_108 ) ;
if ( ( V_97 == V_22 ) && ! F_13 ( V_20 ) ) {
V_98 = F_24 ( V_42 ) ;
F_82 ( V_87 , V_98 ) ;
F_26 ( V_98 ) ;
} else {
memcpy ( V_87 , V_98 , V_97 ) ;
}
F_85 ( V_4 -> V_92 ) ;
V_91 = NULL ;
F_86 ( V_10 -> V_53 , V_81 ) ;
F_79 ( V_88 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_75 ( V_4 , V_11 ) ;
V_10 -> V_14 [ V_11 ] . V_81 = V_81 ;
F_12 ( V_10 , V_11 , V_97 ) ;
F_80 ( V_88 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_92 ( V_97 , & V_4 -> V_38 . V_74 ) ;
F_89 ( & V_4 -> V_38 . V_51 ) ;
V_100:
if ( V_91 )
F_85 ( V_4 -> V_92 ) ;
if ( F_13 ( V_20 ) )
F_69 ( V_93 ) ;
return V_64 ;
}
static void F_93 ( struct V_4 * V_4 , T_1 V_11 ,
int V_34 , struct V_109 * V_109 )
{
T_2 V_110 = V_109 -> V_111 . V_112 ;
struct V_9 * V_10 = V_4 -> V_10 ;
if ( V_34 ) {
if ( V_110 <= ( V_22 - V_34 ) )
return;
V_110 -= ( V_22 - V_34 ) ;
V_11 ++ ;
}
while ( V_110 >= V_22 ) {
F_79 ( V_88 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_75 ( V_4 , V_11 ) ;
F_80 ( V_88 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_89 ( & V_4 -> V_38 . V_68 ) ;
V_11 ++ ;
V_110 -= V_22 ;
}
}
static int F_94 ( struct V_4 * V_4 , struct V_19 * V_20 , T_1 V_11 ,
int V_34 , bool V_113 )
{
unsigned long V_114 = V_115 ;
int V_116 = V_113 ? V_117 : V_118 ;
int V_64 ;
F_95 ( V_116 , V_20 -> V_21 >> V_33 ,
& V_4 -> V_23 -> V_119 ) ;
if ( ! V_113 ) {
F_89 ( & V_4 -> V_38 . V_120 ) ;
V_64 = F_87 ( V_4 , V_20 , V_11 , V_34 ) ;
} else {
F_89 ( & V_4 -> V_38 . V_121 ) ;
V_64 = F_88 ( V_4 , V_20 , V_11 , V_34 ) ;
}
F_96 ( V_116 , & V_4 -> V_23 -> V_119 , V_114 ) ;
if ( F_17 ( V_64 ) ) {
if ( ! V_113 )
F_89 ( & V_4 -> V_38 . V_65 ) ;
else
F_89 ( & V_4 -> V_38 . V_66 ) ;
}
return V_64 ;
}
static void F_97 ( struct V_4 * V_4 , struct V_109 * V_109 )
{
int V_34 ;
T_1 V_11 ;
struct V_19 V_20 ;
struct V_122 V_123 ;
V_11 = V_109 -> V_111 . V_124 >> V_125 ;
V_34 = ( V_109 -> V_111 . V_124 &
( V_126 - 1 ) ) << V_33 ;
if ( F_17 ( F_98 ( V_109 ) == V_127 ) ) {
F_93 ( V_4 , V_11 , V_34 , V_109 ) ;
F_99 ( V_109 ) ;
return;
}
F_100 (bvec, bio, iter) {
int V_128 = V_22 - V_34 ;
if ( V_20 . V_21 > V_128 ) {
struct V_19 V_129 ;
V_129 . V_43 = V_20 . V_43 ;
V_129 . V_21 = V_128 ;
V_129 . V_45 = V_20 . V_45 ;
if ( F_94 ( V_4 , & V_129 , V_11 , V_34 ,
F_101 ( F_98 ( V_109 ) ) ) < 0 )
goto V_100;
V_129 . V_21 = V_20 . V_21 - V_128 ;
V_129 . V_45 += V_128 ;
if ( F_94 ( V_4 , & V_129 , V_11 + 1 , 0 ,
F_101 ( F_98 ( V_109 ) ) ) < 0 )
goto V_100;
} else
if ( F_94 ( V_4 , & V_20 , V_11 , V_34 ,
F_101 ( F_98 ( V_109 ) ) ) < 0 )
goto V_100;
F_18 ( & V_11 , & V_34 , & V_20 ) ;
}
F_99 ( V_109 ) ;
return;
V_100:
F_102 ( V_109 ) ;
}
static T_6 F_103 ( struct V_130 * V_24 , struct V_109 * V_109 )
{
struct V_4 * V_4 = V_24 -> V_131 ;
if ( F_17 ( ! F_61 ( V_4 ) ) )
goto error;
F_104 ( V_24 , & V_109 , V_24 -> V_132 ) ;
if ( ! F_16 ( V_4 , V_109 -> V_111 . V_124 ,
V_109 -> V_111 . V_112 ) ) {
F_89 ( & V_4 -> V_38 . V_67 ) ;
goto V_133;
}
F_97 ( V_4 , V_109 ) ;
F_63 ( V_4 ) ;
return V_134 ;
V_133:
F_63 ( V_4 ) ;
error:
F_102 ( V_109 ) ;
return V_134 ;
}
static void F_105 ( struct V_135 * V_136 ,
unsigned long V_11 )
{
struct V_4 * V_4 ;
struct V_9 * V_10 ;
V_4 = V_136 -> V_137 -> V_8 ;
V_10 = V_4 -> V_10 ;
F_79 ( V_88 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_75 ( V_4 , V_11 ) ;
F_80 ( V_88 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_89 ( & V_4 -> V_38 . V_68 ) ;
}
static int F_106 ( struct V_135 * V_136 , T_3 V_138 ,
struct V_42 * V_42 , bool V_113 )
{
int V_34 , V_59 = - V_139 ;
T_1 V_11 ;
struct V_4 * V_4 ;
struct V_19 V_129 ;
V_4 = V_136 -> V_137 -> V_8 ;
if ( F_17 ( ! F_61 ( V_4 ) ) )
goto V_100;
if ( ! F_16 ( V_4 , V_138 , V_22 ) ) {
F_89 ( & V_4 -> V_38 . V_67 ) ;
V_59 = - V_58 ;
goto V_133;
}
V_11 = V_138 >> V_125 ;
V_34 = V_138 & ( V_126 - 1 ) << V_33 ;
V_129 . V_43 = V_42 ;
V_129 . V_21 = V_22 ;
V_129 . V_45 = 0 ;
V_59 = F_94 ( V_4 , & V_129 , V_11 , V_34 , V_113 ) ;
V_133:
F_63 ( V_4 ) ;
V_100:
if ( V_59 == 0 )
F_107 ( V_42 , V_113 , 0 ) ;
return V_59 ;
}
static void F_108 ( struct V_4 * V_4 )
{
struct V_9 * V_10 ;
struct V_140 * V_92 ;
T_4 V_5 ;
F_40 ( & V_4 -> V_50 ) ;
V_4 -> V_54 = 0 ;
if ( ! F_4 ( V_4 ) ) {
F_42 ( & V_4 -> V_50 ) ;
return;
}
V_10 = V_4 -> V_10 ;
V_92 = V_4 -> V_92 ;
V_5 = V_4 -> V_5 ;
F_63 ( V_4 ) ;
F_109 ( V_4 -> V_141 , F_110 ( & V_4 -> V_79 ) == 0 ) ;
memset ( & V_4 -> V_38 , 0 , sizeof( V_4 -> V_38 ) ) ;
V_4 -> V_5 = 0 ;
F_111 ( V_4 -> V_23 , 0 ) ;
F_112 ( & V_4 -> V_23 -> V_119 , 0 ) ;
F_42 ( & V_4 -> V_50 ) ;
F_65 ( V_10 , V_5 ) ;
F_113 ( V_92 ) ;
}
static T_5 F_114 ( struct V_6 * V_7 ,
struct V_46 * V_47 , const char * V_48 , T_2 V_55 )
{
T_4 V_5 ;
struct V_140 * V_92 ;
struct V_9 * V_10 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
int V_59 ;
V_5 = F_39 ( V_48 , NULL ) ;
if ( ! V_5 )
return - V_58 ;
V_5 = F_41 ( V_5 ) ;
V_10 = F_70 ( V_4 -> V_23 -> V_142 , V_5 ) ;
if ( ! V_10 )
return - V_95 ;
V_92 = F_115 ( V_4 -> V_61 ) ;
if ( F_116 ( V_92 ) ) {
F_73 ( L_20 ,
V_4 -> V_61 ) ;
V_59 = F_117 ( V_92 ) ;
goto V_143;
}
F_40 ( & V_4 -> V_50 ) ;
if ( F_4 ( V_4 ) ) {
F_55 ( L_21 ) ;
V_59 = - V_63 ;
goto V_144;
}
F_118 ( & V_4 -> V_141 ) ;
F_119 ( & V_4 -> V_79 , 1 ) ;
V_4 -> V_10 = V_10 ;
V_4 -> V_92 = V_92 ;
V_4 -> V_5 = V_5 ;
F_111 ( V_4 -> V_23 , V_4 -> V_5 >> V_33 ) ;
F_14 ( V_4 ) ;
F_42 ( & V_4 -> V_50 ) ;
return V_55 ;
V_144:
F_42 ( & V_4 -> V_50 ) ;
F_113 ( V_92 ) ;
V_143:
F_65 ( V_10 , V_5 ) ;
return V_59 ;
}
static T_5 F_120 ( struct V_6 * V_7 ,
struct V_46 * V_47 , const char * V_48 , T_2 V_55 )
{
int V_64 ;
unsigned short V_145 ;
struct V_4 * V_4 ;
struct V_135 * V_136 ;
V_64 = F_121 ( V_48 , 10 , & V_145 ) ;
if ( V_64 )
return V_64 ;
if ( ! V_145 )
return - V_58 ;
V_4 = F_5 ( V_7 ) ;
V_136 = F_122 ( V_4 -> V_23 , 0 ) ;
if ( ! V_136 )
return - V_95 ;
F_123 ( & V_136 -> V_146 ) ;
if ( V_136 -> V_147 || V_4 -> V_148 ) {
F_124 ( & V_136 -> V_146 ) ;
F_125 ( V_136 ) ;
return - V_63 ;
}
V_4 -> V_148 = true ;
F_124 ( & V_136 -> V_146 ) ;
F_126 ( V_136 ) ;
F_108 ( V_4 ) ;
F_14 ( V_4 ) ;
F_125 ( V_136 ) ;
F_123 ( & V_136 -> V_146 ) ;
V_4 -> V_148 = false ;
F_124 ( & V_136 -> V_146 ) ;
return V_55 ;
}
static int F_127 ( struct V_135 * V_136 , T_7 V_149 )
{
int V_64 = 0 ;
struct V_4 * V_4 ;
F_128 ( ! F_129 ( & V_136 -> V_146 ) ) ;
V_4 = V_136 -> V_137 -> V_8 ;
if ( V_4 -> V_148 )
V_64 = - V_63 ;
return V_64 ;
}
static int F_130 ( void )
{
struct V_4 * V_4 ;
struct V_130 * V_24 ;
int V_64 , V_150 ;
V_4 = F_131 ( sizeof( struct V_4 ) , V_83 ) ;
if ( ! V_4 )
return - V_95 ;
V_64 = F_132 ( & V_151 , V_4 , 0 , 0 , V_83 ) ;
if ( V_64 < 0 )
goto V_152;
V_150 = V_64 ;
F_133 ( & V_4 -> V_50 ) ;
V_24 = F_134 ( V_83 ) ;
if ( ! V_24 ) {
F_73 ( L_22 ,
V_150 ) ;
V_64 = - V_95 ;
goto V_153;
}
F_135 ( V_24 , F_103 ) ;
V_4 -> V_23 = F_136 ( 1 ) ;
if ( ! V_4 -> V_23 ) {
F_73 ( L_23 ,
V_150 ) ;
V_64 = - V_95 ;
goto V_154;
}
V_4 -> V_23 -> V_155 = V_156 ;
V_4 -> V_23 -> V_157 = V_150 ;
V_4 -> V_23 -> V_158 = & V_159 ;
V_4 -> V_23 -> V_24 = V_24 ;
V_4 -> V_23 -> V_24 -> V_131 = V_4 ;
V_4 -> V_23 -> V_8 = V_4 ;
snprintf ( V_4 -> V_23 -> V_142 , 16 , L_24 , V_150 ) ;
F_111 ( V_4 -> V_23 , 0 ) ;
F_137 ( V_160 , V_4 -> V_23 -> V_24 ) ;
F_138 ( V_161 , V_4 -> V_23 -> V_24 ) ;
F_139 ( V_4 -> V_23 -> V_24 , V_22 ) ;
F_140 ( V_4 -> V_23 -> V_24 ,
V_32 ) ;
F_141 ( V_4 -> V_23 -> V_24 , V_22 ) ;
F_142 ( V_4 -> V_23 -> V_24 , V_22 ) ;
V_4 -> V_23 -> V_24 -> V_162 . V_163 = V_22 ;
F_143 ( V_4 -> V_23 -> V_24 , V_164 ) ;
if ( V_32 == V_22 )
V_4 -> V_23 -> V_24 -> V_162 . V_165 = 1 ;
else
V_4 -> V_23 -> V_24 -> V_162 . V_165 = 0 ;
F_137 ( V_166 , V_4 -> V_23 -> V_24 ) ;
F_144 ( V_4 -> V_23 ) ;
V_64 = F_145 ( & F_146 ( V_4 -> V_23 ) -> V_167 ,
& V_168 ) ;
if ( V_64 < 0 ) {
F_73 ( L_25 ,
V_150 ) ;
goto V_169;
}
F_53 ( V_4 -> V_61 , V_170 , sizeof( V_4 -> V_61 ) ) ;
V_4 -> V_10 = NULL ;
F_55 ( L_26 , V_4 -> V_23 -> V_142 ) ;
return V_150 ;
V_169:
F_147 ( V_4 -> V_23 ) ;
F_148 ( V_4 -> V_23 ) ;
V_154:
F_149 ( V_24 ) ;
V_153:
F_150 ( & V_151 , V_150 ) ;
V_152:
F_69 ( V_4 ) ;
return V_64 ;
}
static int F_151 ( struct V_4 * V_4 )
{
struct V_135 * V_136 ;
V_136 = F_122 ( V_4 -> V_23 , 0 ) ;
if ( ! V_136 )
return - V_95 ;
F_123 ( & V_136 -> V_146 ) ;
if ( V_136 -> V_147 || V_4 -> V_148 ) {
F_124 ( & V_136 -> V_146 ) ;
F_125 ( V_136 ) ;
return - V_63 ;
}
V_4 -> V_148 = true ;
F_124 ( & V_136 -> V_146 ) ;
F_152 ( & F_146 ( V_4 -> V_23 ) -> V_167 ,
& V_168 ) ;
F_126 ( V_136 ) ;
F_108 ( V_4 ) ;
F_125 ( V_136 ) ;
F_55 ( L_27 , V_4 -> V_23 -> V_142 ) ;
F_149 ( V_4 -> V_23 -> V_24 ) ;
F_147 ( V_4 -> V_23 ) ;
F_148 ( V_4 -> V_23 ) ;
F_69 ( V_4 ) ;
return 0 ;
}
static T_5 F_153 ( struct V_171 * V_171 ,
struct V_172 * V_47 ,
char * V_48 )
{
int V_64 ;
F_123 ( & V_173 ) ;
V_64 = F_130 () ;
F_124 ( & V_173 ) ;
if ( V_64 < 0 )
return V_64 ;
return F_31 ( V_48 , V_22 , L_9 , V_64 ) ;
}
static T_5 F_154 ( struct V_171 * V_171 ,
struct V_172 * V_47 ,
const char * V_48 ,
T_2 V_174 )
{
struct V_4 * V_4 ;
int V_64 , V_175 ;
V_64 = F_155 ( V_48 , 10 , & V_175 ) ;
if ( V_64 )
return V_64 ;
if ( V_175 < 0 )
return - V_58 ;
F_123 ( & V_173 ) ;
V_4 = F_156 ( & V_151 , V_175 ) ;
if ( V_4 ) {
V_64 = F_151 ( V_4 ) ;
if ( ! V_64 )
F_150 ( & V_151 , V_175 ) ;
} else {
V_64 = - V_176 ;
}
F_124 ( & V_173 ) ;
return V_64 ? V_64 : V_174 ;
}
static int F_157 ( int V_177 , void * V_40 , void * V_178 )
{
F_151 ( V_40 ) ;
return 0 ;
}
static void F_158 ( void )
{
F_159 ( & V_179 ) ;
F_160 ( & V_151 , & F_157 , NULL ) ;
F_161 ( & V_151 ) ;
F_162 ( V_156 , L_28 ) ;
F_163 ( V_180 ) ;
}
static int T_8 F_164 ( void )
{
int V_64 ;
V_64 = F_165 ( V_180 , L_29 ,
V_181 , V_182 ) ;
if ( V_64 < 0 )
return V_64 ;
V_64 = F_166 ( & V_179 ) ;
if ( V_64 ) {
F_73 ( L_30 ) ;
F_163 ( V_180 ) ;
return V_64 ;
}
V_156 = F_167 ( 0 , L_28 ) ;
if ( V_156 <= 0 ) {
F_73 ( L_31 ) ;
F_159 ( & V_179 ) ;
F_163 ( V_180 ) ;
return - V_63 ;
}
while ( V_183 != 0 ) {
F_123 ( & V_173 ) ;
V_64 = F_130 () ;
F_124 ( & V_173 ) ;
if ( V_64 < 0 )
goto V_84;
V_183 -- ;
}
return 0 ;
V_84:
F_158 () ;
return V_64 ;
}
static void T_9 F_168 ( void )
{
F_158 () ;
}
