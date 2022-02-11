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
static inline int F_13 ( struct V_19 * V_20 )
{
return V_20 -> V_21 != V_22 ;
}
static inline int F_14 ( struct V_4 * V_4 ,
T_3 V_23 , unsigned int V_17 )
{
T_4 V_24 , V_25 ;
if ( F_15 ( V_23 & ( V_26 - 1 ) ) )
return 0 ;
if ( F_15 ( V_17 & ( V_27 - 1 ) ) )
return 0 ;
V_24 = V_23 + ( V_17 >> V_28 ) ;
V_25 = V_4 -> V_5 >> V_28 ;
if ( F_15 ( V_23 >= V_25 || V_24 > V_25 || V_23 > V_24 ) )
return 0 ;
return 1 ;
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
static int F_20 ( void * V_35 )
{
unsigned int V_36 ;
unsigned long * V_37 ;
V_37 = ( unsigned long * ) V_35 ;
for ( V_36 = 0 ; V_36 != V_22 / sizeof( * V_37 ) ; V_36 ++ ) {
if ( V_37 [ V_36 ] )
return 0 ;
}
return 1 ;
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
int V_44 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
F_27 ( & V_4 -> V_45 ) ;
V_44 = V_4 -> V_55 ;
F_28 ( & V_4 -> V_45 ) ;
return F_29 ( V_43 , V_22 , L_9 , V_44 ) ;
}
static T_5 F_46 ( struct V_6 * V_7 ,
struct V_41 * V_42 , const char * V_43 , T_2 V_50 )
{
int V_56 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
int V_57 ;
V_57 = F_47 ( V_43 , 0 , & V_56 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( V_56 < 1 )
return - V_53 ;
F_38 ( & V_4 -> V_45 ) ;
if ( F_4 ( V_4 ) ) {
if ( ! F_48 ( V_4 -> V_58 , V_56 ) ) {
F_49 ( L_10 ) ;
V_57 = - V_53 ;
goto V_59;
}
}
V_4 -> V_55 = V_56 ;
V_57 = V_50 ;
V_59:
F_40 ( & V_4 -> V_45 ) ;
return V_57 ;
}
static T_5 F_50 ( struct V_6 * V_7 ,
struct V_41 * V_42 , char * V_43 )
{
T_2 V_60 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
F_27 ( & V_4 -> V_45 ) ;
V_60 = F_51 ( V_4 -> V_61 , V_43 ) ;
F_28 ( & V_4 -> V_45 ) ;
return V_60 ;
}
static T_5 F_52 ( struct V_6 * V_7 ,
struct V_41 * V_42 , const char * V_43 , T_2 V_50 )
{
struct V_4 * V_4 = F_5 ( V_7 ) ;
T_2 V_60 ;
F_38 ( & V_4 -> V_45 ) ;
if ( F_4 ( V_4 ) ) {
F_40 ( & V_4 -> V_45 ) ;
F_49 ( L_11 ) ;
return - V_62 ;
}
F_53 ( V_4 -> V_61 , V_43 , sizeof( V_4 -> V_61 ) ) ;
V_60 = strlen ( V_4 -> V_61 ) ;
if ( V_60 > 0 && V_4 -> V_61 [ V_60 - 1 ] == '\n' )
V_4 -> V_61 [ V_60 - 1 ] = 0x00 ;
if ( ! F_54 ( V_4 -> V_61 ) )
V_50 = - V_53 ;
F_40 ( & V_4 -> V_45 ) ;
return V_50 ;
}
static T_5 F_55 ( struct V_6 * V_7 ,
struct V_41 * V_42 , const char * V_43 , T_2 V_50 )
{
unsigned long V_63 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
struct V_9 * V_10 ;
F_27 ( & V_4 -> V_45 ) ;
if ( ! F_4 ( V_4 ) ) {
F_28 ( & V_4 -> V_45 ) ;
return - V_53 ;
}
V_10 = V_4 -> V_10 ;
V_63 = F_56 ( V_10 -> V_48 ) ;
F_57 ( V_63 , & V_4 -> V_33 . V_64 ) ;
F_28 ( & V_4 -> V_45 ) ;
return V_50 ;
}
static T_5 F_58 ( struct V_6 * V_7 ,
struct V_41 * V_42 , char * V_43 )
{
struct V_4 * V_4 = F_5 ( V_7 ) ;
T_5 V_57 ;
F_27 ( & V_4 -> V_45 ) ;
V_57 = F_29 ( V_43 , V_22 ,
L_12 ,
( T_4 ) F_32 ( & V_4 -> V_33 . V_65 ) ,
( T_4 ) F_32 ( & V_4 -> V_33 . V_66 ) ,
( T_4 ) F_32 ( & V_4 -> V_33 . V_67 ) ,
( T_4 ) F_32 ( & V_4 -> V_33 . V_68 ) ) ;
F_28 ( & V_4 -> V_45 ) ;
return V_57 ;
}
static T_5 F_59 ( struct V_6 * V_7 ,
struct V_41 * V_42 , char * V_43 )
{
struct V_4 * V_4 = F_5 ( V_7 ) ;
T_4 V_69 , V_70 = 0 ;
long V_71 ;
T_5 V_57 ;
F_27 ( & V_4 -> V_45 ) ;
if ( F_4 ( V_4 ) )
V_70 = F_34 ( V_4 -> V_10 -> V_48 ) ;
V_69 = F_32 ( & V_4 -> V_33 . V_46 ) ;
V_71 = F_18 ( & V_4 -> V_33 . V_34 ) ;
V_57 = F_29 ( V_43 , V_22 ,
L_13 ,
V_69 << V_47 ,
( T_4 ) F_32 ( & V_4 -> V_33 . V_72 ) ,
V_70 << V_47 ,
V_4 -> V_49 << V_47 ,
V_71 << V_47 ,
( T_4 ) F_32 ( & V_4 -> V_33 . V_73 ) ,
( T_4 ) F_32 ( & V_4 -> V_33 . V_64 ) ) ;
F_28 ( & V_4 -> V_45 ) ;
return V_57 ;
}
static inline bool F_60 ( struct V_4 * V_4 )
{
if ( F_61 ( & V_4 -> V_74 ) )
return true ;
return false ;
}
static inline void F_62 ( struct V_4 * V_4 )
{
F_63 ( & V_4 -> V_74 ) ;
}
static void F_64 ( struct V_9 * V_10 , T_4 V_5 )
{
T_2 V_75 = V_5 >> V_47 ;
T_2 V_11 ;
for ( V_11 = 0 ; V_11 < V_75 ; V_11 ++ ) {
unsigned long V_76 = V_10 -> V_14 [ V_11 ] . V_76 ;
if ( ! V_76 )
continue;
F_65 ( V_10 -> V_48 , V_76 ) ;
}
F_66 ( V_10 -> V_48 ) ;
F_67 ( V_10 -> V_14 ) ;
F_68 ( V_10 ) ;
}
static struct V_9 * F_69 ( char * V_77 , T_4 V_5 )
{
T_2 V_75 ;
struct V_9 * V_10 = F_70 ( sizeof( * V_10 ) , V_78 ) ;
if ( ! V_10 )
return NULL ;
V_75 = V_5 >> V_47 ;
V_10 -> V_14 = F_71 ( V_75 * sizeof( * V_10 -> V_14 ) ) ;
if ( ! V_10 -> V_14 ) {
F_72 ( L_14 ) ;
goto V_79;
}
V_10 -> V_48 = F_73 ( V_77 , V_80 | V_81 ) ;
if ( ! V_10 -> V_48 ) {
F_72 ( L_15 ) ;
goto V_79;
}
return V_10 ;
V_79:
F_67 ( V_10 -> V_14 ) ;
F_68 ( V_10 ) ;
return NULL ;
}
static void F_74 ( struct V_4 * V_4 , T_2 V_11 )
{
struct V_9 * V_10 = V_4 -> V_10 ;
unsigned long V_76 = V_10 -> V_14 [ V_11 ] . V_76 ;
if ( F_15 ( ! V_76 ) ) {
if ( F_7 ( V_10 , V_11 , V_82 ) ) {
F_10 ( V_10 , V_11 , V_82 ) ;
F_75 ( & V_4 -> V_33 . V_73 ) ;
}
return;
}
F_65 ( V_10 -> V_48 , V_76 ) ;
F_76 ( F_11 ( V_10 , V_11 ) ,
& V_4 -> V_33 . V_72 ) ;
F_75 ( & V_4 -> V_33 . V_46 ) ;
V_10 -> V_14 [ V_11 ] . V_76 = 0 ;
F_12 ( V_10 , V_11 , 0 ) ;
}
static int F_77 ( struct V_4 * V_4 , char * V_83 , T_1 V_11 )
{
int V_57 = 0 ;
unsigned char * V_84 ;
struct V_9 * V_10 = V_4 -> V_10 ;
unsigned long V_76 ;
T_2 V_17 ;
F_78 ( V_85 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
V_76 = V_10 -> V_14 [ V_11 ] . V_76 ;
V_17 = F_11 ( V_10 , V_11 ) ;
if ( ! V_76 || F_7 ( V_10 , V_11 , V_82 ) ) {
F_79 ( V_85 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_23 ( V_83 ) ;
return 0 ;
}
V_84 = F_80 ( V_10 -> V_48 , V_76 , V_86 ) ;
if ( V_17 == V_22 )
F_81 ( V_83 , V_84 ) ;
else
V_57 = F_82 ( V_4 -> V_58 , V_84 , V_17 , V_83 ) ;
F_83 ( V_10 -> V_48 , V_76 ) ;
F_79 ( V_85 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
if ( F_15 ( V_57 ) ) {
F_72 ( L_16 , V_57 , V_11 ) ;
return V_57 ;
}
return 0 ;
}
static int F_84 ( struct V_4 * V_4 , struct V_19 * V_20 ,
T_1 V_11 , int V_29 )
{
int V_57 ;
struct V_37 * V_37 ;
unsigned char * V_39 , * V_87 = NULL ;
struct V_9 * V_10 = V_4 -> V_10 ;
V_37 = V_20 -> V_38 ;
F_78 ( V_85 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
if ( F_15 ( ! V_10 -> V_14 [ V_11 ] . V_76 ) ||
F_7 ( V_10 , V_11 , V_82 ) ) {
F_79 ( V_85 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_21 ( V_20 ) ;
return 0 ;
}
F_79 ( V_85 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
if ( F_13 ( V_20 ) )
V_87 = F_70 ( V_22 , V_80 ) ;
V_39 = F_22 ( V_37 ) ;
if ( ! F_13 ( V_20 ) )
V_87 = V_39 ;
if ( ! V_87 ) {
F_49 ( L_17 ) ;
V_57 = - V_88 ;
goto V_89;
}
V_57 = F_77 ( V_4 , V_87 , V_11 ) ;
if ( F_15 ( V_57 ) )
goto V_89;
if ( F_13 ( V_20 ) )
memcpy ( V_39 + V_20 -> V_40 , V_87 + V_29 ,
V_20 -> V_21 ) ;
F_25 ( V_37 ) ;
V_57 = 0 ;
V_89:
F_24 ( V_39 ) ;
if ( F_13 ( V_20 ) )
F_68 ( V_87 ) ;
return V_57 ;
}
static int F_85 ( struct V_4 * V_4 , struct V_19 * V_20 , T_1 V_11 ,
int V_29 )
{
int V_57 = 0 ;
T_2 V_90 ;
unsigned long V_76 ;
struct V_37 * V_37 ;
unsigned char * V_39 , * V_84 , * V_91 , * V_87 = NULL ;
struct V_9 * V_10 = V_4 -> V_10 ;
struct V_92 * V_93 = NULL ;
unsigned long V_94 ;
V_37 = V_20 -> V_38 ;
if ( F_13 ( V_20 ) ) {
V_87 = F_70 ( V_22 , V_80 ) ;
if ( ! V_87 ) {
V_57 = - V_88 ;
goto V_59;
}
V_57 = F_77 ( V_4 , V_87 , V_11 ) ;
if ( V_57 )
goto V_59;
}
V_93 = F_86 ( V_4 -> V_58 ) ;
V_39 = F_22 ( V_37 ) ;
if ( F_13 ( V_20 ) ) {
memcpy ( V_87 + V_29 , V_39 + V_20 -> V_40 ,
V_20 -> V_21 ) ;
F_24 ( V_39 ) ;
V_39 = NULL ;
} else {
V_87 = V_39 ;
}
if ( F_20 ( V_87 ) ) {
if ( V_39 )
F_24 ( V_39 ) ;
F_78 ( V_85 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_74 ( V_4 , V_11 ) ;
F_9 ( V_10 , V_11 , V_82 ) ;
F_79 ( V_85 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_87 ( & V_4 -> V_33 . V_73 ) ;
V_57 = 0 ;
goto V_59;
}
V_57 = F_88 ( V_4 -> V_58 , V_93 , V_87 , & V_90 ) ;
if ( ! F_13 ( V_20 ) ) {
F_24 ( V_39 ) ;
V_39 = NULL ;
V_87 = NULL ;
}
if ( F_15 ( V_57 ) ) {
F_72 ( L_18 , V_57 ) ;
goto V_59;
}
V_91 = V_93 -> V_95 ;
if ( F_15 ( V_90 > V_96 ) ) {
V_90 = V_22 ;
if ( F_13 ( V_20 ) )
V_91 = V_87 ;
}
V_76 = F_89 ( V_10 -> V_48 , V_90 ) ;
if ( ! V_76 ) {
F_49 ( L_19 ,
V_11 , V_90 ) ;
V_57 = - V_88 ;
goto V_59;
}
V_94 = F_34 ( V_10 -> V_48 ) ;
if ( V_4 -> V_49 && V_94 > V_4 -> V_49 ) {
F_65 ( V_10 -> V_48 , V_76 ) ;
V_57 = - V_88 ;
goto V_59;
}
F_17 ( V_4 , V_94 ) ;
V_84 = F_80 ( V_10 -> V_48 , V_76 , V_97 ) ;
if ( ( V_90 == V_22 ) && ! F_13 ( V_20 ) ) {
V_91 = F_22 ( V_37 ) ;
F_81 ( V_84 , V_91 ) ;
F_24 ( V_91 ) ;
} else {
memcpy ( V_84 , V_91 , V_90 ) ;
}
F_90 ( V_4 -> V_58 , V_93 ) ;
V_93 = NULL ;
F_83 ( V_10 -> V_48 , V_76 ) ;
F_78 ( V_85 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_74 ( V_4 , V_11 ) ;
V_10 -> V_14 [ V_11 ] . V_76 = V_76 ;
F_12 ( V_10 , V_11 , V_90 ) ;
F_79 ( V_85 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_57 ( V_90 , & V_4 -> V_33 . V_72 ) ;
F_87 ( & V_4 -> V_33 . V_46 ) ;
V_59:
if ( V_93 )
F_90 ( V_4 -> V_58 , V_93 ) ;
if ( F_13 ( V_20 ) )
F_68 ( V_87 ) ;
return V_57 ;
}
static void F_91 ( struct V_4 * V_4 , T_1 V_11 ,
int V_29 , struct V_98 * V_98 )
{
T_2 V_99 = V_98 -> V_100 . V_101 ;
struct V_9 * V_10 = V_4 -> V_10 ;
if ( V_29 ) {
if ( V_99 <= ( V_22 - V_29 ) )
return;
V_99 -= ( V_22 - V_29 ) ;
V_11 ++ ;
}
while ( V_99 >= V_22 ) {
F_78 ( V_85 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_74 ( V_4 , V_11 ) ;
F_79 ( V_85 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_87 ( & V_4 -> V_33 . V_68 ) ;
V_11 ++ ;
V_99 -= V_22 ;
}
}
static int F_92 ( struct V_4 * V_4 , struct V_19 * V_20 , T_1 V_11 ,
int V_29 , int V_102 )
{
unsigned long V_103 = V_104 ;
int V_57 ;
F_93 ( V_102 , V_20 -> V_21 >> V_28 ,
& V_4 -> V_105 -> V_106 ) ;
if ( V_102 == V_107 ) {
F_87 ( & V_4 -> V_33 . V_108 ) ;
V_57 = F_84 ( V_4 , V_20 , V_11 , V_29 ) ;
} else {
F_87 ( & V_4 -> V_33 . V_109 ) ;
V_57 = F_85 ( V_4 , V_20 , V_11 , V_29 ) ;
}
F_94 ( V_102 , & V_4 -> V_105 -> V_106 , V_103 ) ;
if ( F_15 ( V_57 ) ) {
if ( V_102 == V_107 )
F_87 ( & V_4 -> V_33 . V_65 ) ;
else
F_87 ( & V_4 -> V_33 . V_66 ) ;
}
return V_57 ;
}
static void F_95 ( struct V_4 * V_4 , struct V_98 * V_98 )
{
int V_29 , V_102 ;
T_1 V_11 ;
struct V_19 V_20 ;
struct V_110 V_111 ;
V_11 = V_98 -> V_100 . V_112 >> V_113 ;
V_29 = ( V_98 -> V_100 . V_112 &
( V_114 - 1 ) ) << V_28 ;
if ( F_15 ( V_98 -> V_115 & V_116 ) ) {
F_91 ( V_4 , V_11 , V_29 , V_98 ) ;
F_96 ( V_98 , 0 ) ;
return;
}
V_102 = F_97 ( V_98 ) ;
F_98 (bvec, bio, iter) {
int V_117 = V_22 - V_29 ;
if ( V_20 . V_21 > V_117 ) {
struct V_19 V_118 ;
V_118 . V_38 = V_20 . V_38 ;
V_118 . V_21 = V_117 ;
V_118 . V_40 = V_20 . V_40 ;
if ( F_92 ( V_4 , & V_118 , V_11 , V_29 , V_102 ) < 0 )
goto V_59;
V_118 . V_21 = V_20 . V_21 - V_117 ;
V_118 . V_40 += V_117 ;
if ( F_92 ( V_4 , & V_118 , V_11 + 1 , 0 , V_102 ) < 0 )
goto V_59;
} else
if ( F_92 ( V_4 , & V_20 , V_11 , V_29 , V_102 ) < 0 )
goto V_59;
F_16 ( & V_11 , & V_29 , & V_20 ) ;
}
F_99 ( V_119 , & V_98 -> V_120 ) ;
F_96 ( V_98 , 0 ) ;
return;
V_59:
F_100 ( V_98 ) ;
}
static void F_101 ( struct V_121 * V_122 , struct V_98 * V_98 )
{
struct V_4 * V_4 = V_122 -> V_123 ;
if ( F_15 ( ! F_60 ( V_4 ) ) )
goto error;
if ( ! F_14 ( V_4 , V_98 -> V_100 . V_112 ,
V_98 -> V_100 . V_101 ) ) {
F_87 ( & V_4 -> V_33 . V_67 ) ;
goto V_124;
}
F_95 ( V_4 , V_98 ) ;
F_62 ( V_4 ) ;
return;
V_124:
F_62 ( V_4 ) ;
error:
F_100 ( V_98 ) ;
}
static void F_102 ( struct V_125 * V_126 ,
unsigned long V_11 )
{
struct V_4 * V_4 ;
struct V_9 * V_10 ;
V_4 = V_126 -> V_127 -> V_8 ;
V_10 = V_4 -> V_10 ;
F_78 ( V_85 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_74 ( V_4 , V_11 ) ;
F_79 ( V_85 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_87 ( & V_4 -> V_33 . V_68 ) ;
}
static int F_103 ( struct V_125 * V_126 , T_3 V_128 ,
struct V_37 * V_37 , int V_102 )
{
int V_29 , V_54 = - V_129 ;
T_1 V_11 ;
struct V_4 * V_4 ;
struct V_19 V_118 ;
V_4 = V_126 -> V_127 -> V_8 ;
if ( F_15 ( ! F_60 ( V_4 ) ) )
goto V_59;
if ( ! F_14 ( V_4 , V_128 , V_22 ) ) {
F_87 ( & V_4 -> V_33 . V_67 ) ;
V_54 = - V_53 ;
goto V_124;
}
V_11 = V_128 >> V_113 ;
V_29 = V_128 & ( V_114 - 1 ) << V_28 ;
V_118 . V_38 = V_37 ;
V_118 . V_21 = V_22 ;
V_118 . V_40 = 0 ;
V_54 = F_92 ( V_4 , & V_118 , V_11 , V_29 , V_102 ) ;
V_124:
F_62 ( V_4 ) ;
V_59:
if ( V_54 == 0 )
F_104 ( V_37 , V_102 , 0 ) ;
return V_54 ;
}
static void F_105 ( struct V_4 * V_4 )
{
struct V_9 * V_10 ;
struct V_130 * V_58 ;
T_4 V_5 ;
F_38 ( & V_4 -> V_45 ) ;
V_4 -> V_49 = 0 ;
if ( ! F_4 ( V_4 ) ) {
F_40 ( & V_4 -> V_45 ) ;
return;
}
V_10 = V_4 -> V_10 ;
V_58 = V_4 -> V_58 ;
V_5 = V_4 -> V_5 ;
F_62 ( V_4 ) ;
F_106 ( V_4 -> V_131 , F_107 ( & V_4 -> V_74 ) == 0 ) ;
memset ( & V_4 -> V_33 , 0 , sizeof( V_4 -> V_33 ) ) ;
V_4 -> V_5 = 0 ;
V_4 -> V_55 = 1 ;
F_108 ( V_4 -> V_105 , 0 ) ;
F_109 ( & V_4 -> V_105 -> V_106 , 0 ) ;
F_40 ( & V_4 -> V_45 ) ;
F_64 ( V_10 , V_5 ) ;
F_110 ( V_58 ) ;
}
static T_5 F_111 ( struct V_6 * V_7 ,
struct V_41 * V_42 , const char * V_43 , T_2 V_50 )
{
T_4 V_5 ;
struct V_130 * V_58 ;
struct V_9 * V_10 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
int V_54 ;
V_5 = F_37 ( V_43 , NULL ) ;
if ( ! V_5 )
return - V_53 ;
V_5 = F_39 ( V_5 ) ;
V_10 = F_69 ( V_4 -> V_105 -> V_132 , V_5 ) ;
if ( ! V_10 )
return - V_88 ;
V_58 = F_112 ( V_4 -> V_61 , V_4 -> V_55 ) ;
if ( F_113 ( V_58 ) ) {
F_49 ( L_20 ,
V_4 -> V_61 ) ;
V_54 = F_114 ( V_58 ) ;
goto V_133;
}
F_38 ( & V_4 -> V_45 ) ;
if ( F_4 ( V_4 ) ) {
F_49 ( L_21 ) ;
V_54 = - V_62 ;
goto V_134;
}
F_115 ( & V_4 -> V_131 ) ;
F_116 ( & V_4 -> V_74 , 1 ) ;
V_4 -> V_10 = V_10 ;
V_4 -> V_58 = V_58 ;
V_4 -> V_5 = V_5 ;
F_108 ( V_4 -> V_105 , V_4 -> V_5 >> V_28 ) ;
F_40 ( & V_4 -> V_45 ) ;
F_117 ( V_4 -> V_105 ) ;
return V_50 ;
V_134:
F_40 ( & V_4 -> V_45 ) ;
F_110 ( V_58 ) ;
V_133:
F_64 ( V_10 , V_5 ) ;
return V_54 ;
}
static T_5 F_118 ( struct V_6 * V_7 ,
struct V_41 * V_42 , const char * V_43 , T_2 V_50 )
{
int V_57 ;
unsigned short V_135 ;
struct V_4 * V_4 ;
struct V_125 * V_126 ;
V_57 = F_119 ( V_43 , 10 , & V_135 ) ;
if ( V_57 )
return V_57 ;
if ( ! V_135 )
return - V_53 ;
V_4 = F_5 ( V_7 ) ;
V_126 = F_120 ( V_4 -> V_105 , 0 ) ;
if ( ! V_126 )
return - V_88 ;
F_121 ( & V_126 -> V_136 ) ;
if ( V_126 -> V_137 || V_4 -> V_138 ) {
F_122 ( & V_126 -> V_136 ) ;
F_123 ( V_126 ) ;
return - V_62 ;
}
V_4 -> V_138 = true ;
F_122 ( & V_126 -> V_136 ) ;
F_124 ( V_126 ) ;
F_105 ( V_4 ) ;
F_117 ( V_4 -> V_105 ) ;
F_123 ( V_126 ) ;
F_121 ( & V_126 -> V_136 ) ;
V_4 -> V_138 = false ;
F_122 ( & V_126 -> V_136 ) ;
return V_50 ;
}
static int F_125 ( struct V_125 * V_126 , T_6 V_139 )
{
int V_57 = 0 ;
struct V_4 * V_4 ;
F_126 ( ! F_127 ( & V_126 -> V_136 ) ) ;
V_4 = V_126 -> V_127 -> V_8 ;
if ( V_4 -> V_138 )
V_57 = - V_62 ;
return V_57 ;
}
static int F_128 ( void )
{
struct V_4 * V_4 ;
struct V_121 * V_122 ;
int V_57 , V_140 ;
V_4 = F_129 ( sizeof( struct V_4 ) , V_78 ) ;
if ( ! V_4 )
return - V_88 ;
V_57 = F_130 ( & V_141 , V_4 , 0 , 0 , V_78 ) ;
if ( V_57 < 0 )
goto V_142;
V_140 = V_57 ;
F_131 ( & V_4 -> V_45 ) ;
V_122 = F_132 ( V_78 ) ;
if ( ! V_122 ) {
F_72 ( L_22 ,
V_140 ) ;
V_57 = - V_88 ;
goto V_143;
}
F_133 ( V_122 , F_101 ) ;
V_4 -> V_105 = F_134 ( 1 ) ;
if ( ! V_4 -> V_105 ) {
F_135 ( L_23 ,
V_140 ) ;
V_57 = - V_88 ;
goto V_144;
}
V_4 -> V_105 -> V_145 = V_146 ;
V_4 -> V_105 -> V_147 = V_140 ;
V_4 -> V_105 -> V_148 = & V_149 ;
V_4 -> V_105 -> V_122 = V_122 ;
V_4 -> V_105 -> V_122 -> V_123 = V_4 ;
V_4 -> V_105 -> V_8 = V_4 ;
snprintf ( V_4 -> V_105 -> V_132 , 16 , L_24 , V_140 ) ;
F_108 ( V_4 -> V_105 , 0 ) ;
F_136 ( V_150 , V_4 -> V_105 -> V_122 ) ;
F_137 ( V_151 , V_4 -> V_105 -> V_122 ) ;
F_138 ( V_4 -> V_105 -> V_122 , V_22 ) ;
F_139 ( V_4 -> V_105 -> V_122 ,
V_27 ) ;
F_140 ( V_4 -> V_105 -> V_122 , V_22 ) ;
F_141 ( V_4 -> V_105 -> V_122 , V_22 ) ;
V_4 -> V_105 -> V_122 -> V_152 . V_153 = V_22 ;
V_4 -> V_105 -> V_122 -> V_152 . V_154 = V_155 ;
if ( V_27 == V_22 )
V_4 -> V_105 -> V_122 -> V_152 . V_156 = 1 ;
else
V_4 -> V_105 -> V_122 -> V_152 . V_156 = 0 ;
F_136 ( V_157 , V_4 -> V_105 -> V_122 ) ;
F_142 ( V_4 -> V_105 ) ;
V_57 = F_143 ( & F_144 ( V_4 -> V_105 ) -> V_158 ,
& V_159 ) ;
if ( V_57 < 0 ) {
F_135 ( L_25 ) ;
goto V_160;
}
F_53 ( V_4 -> V_61 , V_161 , sizeof( V_4 -> V_61 ) ) ;
V_4 -> V_10 = NULL ;
V_4 -> V_55 = 1 ;
F_49 ( L_26 , V_4 -> V_105 -> V_132 ) ;
return V_140 ;
V_160:
F_145 ( V_4 -> V_105 ) ;
F_146 ( V_4 -> V_105 ) ;
V_144:
F_147 ( V_122 ) ;
V_143:
F_148 ( & V_141 , V_140 ) ;
V_142:
F_68 ( V_4 ) ;
return V_57 ;
}
static int F_149 ( struct V_4 * V_4 )
{
struct V_125 * V_126 ;
V_126 = F_120 ( V_4 -> V_105 , 0 ) ;
if ( ! V_126 )
return - V_88 ;
F_121 ( & V_126 -> V_136 ) ;
if ( V_126 -> V_137 || V_4 -> V_138 ) {
F_122 ( & V_126 -> V_136 ) ;
F_123 ( V_126 ) ;
return - V_62 ;
}
V_4 -> V_138 = true ;
F_122 ( & V_126 -> V_136 ) ;
F_150 ( & F_144 ( V_4 -> V_105 ) -> V_158 ,
& V_159 ) ;
F_124 ( V_126 ) ;
F_105 ( V_4 ) ;
F_123 ( V_126 ) ;
F_49 ( L_27 , V_4 -> V_105 -> V_132 ) ;
F_148 ( & V_141 , V_4 -> V_105 -> V_147 ) ;
F_147 ( V_4 -> V_105 -> V_122 ) ;
F_145 ( V_4 -> V_105 ) ;
F_146 ( V_4 -> V_105 ) ;
F_68 ( V_4 ) ;
return 0 ;
}
static T_5 F_151 ( struct V_162 * V_162 ,
struct V_163 * V_42 ,
char * V_43 )
{
int V_57 ;
F_121 ( & V_164 ) ;
V_57 = F_128 () ;
F_122 ( & V_164 ) ;
if ( V_57 < 0 )
return V_57 ;
return F_29 ( V_43 , V_22 , L_9 , V_57 ) ;
}
static T_5 F_152 ( struct V_162 * V_162 ,
struct V_163 * V_42 ,
const char * V_43 ,
T_2 V_165 )
{
struct V_4 * V_4 ;
int V_57 , V_166 ;
V_57 = F_47 ( V_43 , 10 , & V_166 ) ;
if ( V_57 )
return V_57 ;
if ( V_166 < 0 )
return - V_53 ;
F_121 ( & V_164 ) ;
V_4 = F_153 ( & V_141 , V_166 ) ;
if ( V_4 )
V_57 = F_149 ( V_4 ) ;
else
V_57 = - V_167 ;
F_122 ( & V_164 ) ;
return V_57 ? V_57 : V_165 ;
}
static int F_154 ( int V_168 , void * V_35 , void * V_169 )
{
F_149 ( V_35 ) ;
return 0 ;
}
static void F_155 ( void )
{
F_156 ( & V_170 ) ;
F_157 ( & V_141 , & F_154 , NULL ) ;
F_158 ( & V_141 ) ;
F_159 ( V_146 , L_28 ) ;
}
static int T_7 F_160 ( void )
{
int V_57 ;
V_57 = F_161 ( & V_170 ) ;
if ( V_57 ) {
F_135 ( L_29 ) ;
return V_57 ;
}
V_146 = F_162 ( 0 , L_28 ) ;
if ( V_146 <= 0 ) {
F_135 ( L_30 ) ;
F_156 ( & V_170 ) ;
return - V_62 ;
}
while ( V_171 != 0 ) {
F_121 ( & V_164 ) ;
V_57 = F_128 () ;
F_122 ( & V_164 ) ;
if ( V_57 < 0 )
goto V_79;
V_171 -- ;
}
return 0 ;
V_79:
F_155 () ;
return V_57 ;
}
static void T_8 F_163 ( void )
{
F_155 () ;
}
