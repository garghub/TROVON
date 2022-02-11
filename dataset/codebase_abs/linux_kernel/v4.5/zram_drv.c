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
if ( ! F_53 ( V_43 ) )
return - V_53 ;
F_38 ( & V_4 -> V_45 ) ;
if ( F_4 ( V_4 ) ) {
F_40 ( & V_4 -> V_45 ) ;
F_49 ( L_11 ) ;
return - V_62 ;
}
F_54 ( V_4 -> V_61 , V_43 , sizeof( V_4 -> V_61 ) ) ;
V_60 = strlen ( V_4 -> V_61 ) ;
if ( V_60 > 0 && V_4 -> V_61 [ V_60 - 1 ] == '\n' )
V_4 -> V_61 [ V_60 - 1 ] = 0x00 ;
F_40 ( & V_4 -> V_45 ) ;
return V_50 ;
}
static T_5 F_55 ( struct V_6 * V_7 ,
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
F_56 ( V_10 -> V_48 ) ;
F_28 ( & V_4 -> V_45 ) ;
return V_50 ;
}
static T_5 F_57 ( struct V_6 * V_7 ,
struct V_41 * V_42 , char * V_43 )
{
struct V_4 * V_4 = F_5 ( V_7 ) ;
T_5 V_57 ;
F_27 ( & V_4 -> V_45 ) ;
V_57 = F_29 ( V_43 , V_22 ,
L_12 ,
( T_4 ) F_32 ( & V_4 -> V_33 . V_63 ) ,
( T_4 ) F_32 ( & V_4 -> V_33 . V_64 ) ,
( T_4 ) F_32 ( & V_4 -> V_33 . V_65 ) ,
( T_4 ) F_32 ( & V_4 -> V_33 . V_66 ) ) ;
F_28 ( & V_4 -> V_45 ) ;
return V_57 ;
}
static T_5 F_58 ( struct V_6 * V_7 ,
struct V_41 * V_42 , char * V_43 )
{
struct V_4 * V_4 = F_5 ( V_7 ) ;
struct V_67 V_68 ;
T_4 V_69 , V_70 = 0 ;
long V_71 ;
T_5 V_57 ;
memset ( & V_68 , 0x00 , sizeof( struct V_67 ) ) ;
F_27 ( & V_4 -> V_45 ) ;
if ( F_4 ( V_4 ) ) {
V_70 = F_34 ( V_4 -> V_10 -> V_48 ) ;
V_67 ( V_4 -> V_10 -> V_48 , & V_68 ) ;
}
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
V_68 . V_74 ) ;
F_28 ( & V_4 -> V_45 ) ;
return V_57 ;
}
static inline bool F_59 ( struct V_4 * V_4 )
{
if ( F_60 ( & V_4 -> V_75 ) )
return true ;
return false ;
}
static inline void F_61 ( struct V_4 * V_4 )
{
F_62 ( & V_4 -> V_75 ) ;
}
static void F_63 ( struct V_9 * V_10 , T_4 V_5 )
{
T_2 V_76 = V_5 >> V_47 ;
T_2 V_11 ;
for ( V_11 = 0 ; V_11 < V_76 ; V_11 ++ ) {
unsigned long V_77 = V_10 -> V_14 [ V_11 ] . V_77 ;
if ( ! V_77 )
continue;
F_64 ( V_10 -> V_48 , V_77 ) ;
}
F_65 ( V_10 -> V_48 ) ;
F_66 ( V_10 -> V_14 ) ;
F_67 ( V_10 ) ;
}
static struct V_9 * F_68 ( char * V_78 , T_4 V_5 )
{
T_2 V_76 ;
struct V_9 * V_10 = F_69 ( sizeof( * V_10 ) , V_79 ) ;
if ( ! V_10 )
return NULL ;
V_76 = V_5 >> V_47 ;
V_10 -> V_14 = F_70 ( V_76 * sizeof( * V_10 -> V_14 ) ) ;
if ( ! V_10 -> V_14 ) {
F_71 ( L_14 ) ;
goto V_80;
}
V_10 -> V_48 = F_72 ( V_78 , V_81 | V_82 ) ;
if ( ! V_10 -> V_48 ) {
F_71 ( L_15 ) ;
goto V_80;
}
return V_10 ;
V_80:
F_66 ( V_10 -> V_14 ) ;
F_67 ( V_10 ) ;
return NULL ;
}
static void F_73 ( struct V_4 * V_4 , T_2 V_11 )
{
struct V_9 * V_10 = V_4 -> V_10 ;
unsigned long V_77 = V_10 -> V_14 [ V_11 ] . V_77 ;
if ( F_15 ( ! V_77 ) ) {
if ( F_7 ( V_10 , V_11 , V_83 ) ) {
F_10 ( V_10 , V_11 , V_83 ) ;
F_74 ( & V_4 -> V_33 . V_73 ) ;
}
return;
}
F_64 ( V_10 -> V_48 , V_77 ) ;
F_75 ( F_11 ( V_10 , V_11 ) ,
& V_4 -> V_33 . V_72 ) ;
F_74 ( & V_4 -> V_33 . V_46 ) ;
V_10 -> V_14 [ V_11 ] . V_77 = 0 ;
F_12 ( V_10 , V_11 , 0 ) ;
}
static int F_76 ( struct V_4 * V_4 , char * V_84 , T_1 V_11 )
{
int V_57 = 0 ;
unsigned char * V_85 ;
struct V_9 * V_10 = V_4 -> V_10 ;
unsigned long V_77 ;
T_2 V_17 ;
F_77 ( V_86 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
V_77 = V_10 -> V_14 [ V_11 ] . V_77 ;
V_17 = F_11 ( V_10 , V_11 ) ;
if ( ! V_77 || F_7 ( V_10 , V_11 , V_83 ) ) {
F_78 ( V_86 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_23 ( V_84 ) ;
return 0 ;
}
V_85 = F_79 ( V_10 -> V_48 , V_77 , V_87 ) ;
if ( V_17 == V_22 )
F_80 ( V_84 , V_85 ) ;
else
V_57 = F_81 ( V_4 -> V_58 , V_85 , V_17 , V_84 ) ;
F_82 ( V_10 -> V_48 , V_77 ) ;
F_78 ( V_86 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
if ( F_15 ( V_57 ) ) {
F_71 ( L_16 , V_57 , V_11 ) ;
return V_57 ;
}
return 0 ;
}
static int F_83 ( struct V_4 * V_4 , struct V_19 * V_20 ,
T_1 V_11 , int V_29 )
{
int V_57 ;
struct V_37 * V_37 ;
unsigned char * V_39 , * V_88 = NULL ;
struct V_9 * V_10 = V_4 -> V_10 ;
V_37 = V_20 -> V_38 ;
F_77 ( V_86 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
if ( F_15 ( ! V_10 -> V_14 [ V_11 ] . V_77 ) ||
F_7 ( V_10 , V_11 , V_83 ) ) {
F_78 ( V_86 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_21 ( V_20 ) ;
return 0 ;
}
F_78 ( V_86 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
if ( F_13 ( V_20 ) )
V_88 = F_69 ( V_22 , V_81 ) ;
V_39 = F_22 ( V_37 ) ;
if ( ! F_13 ( V_20 ) )
V_88 = V_39 ;
if ( ! V_88 ) {
F_71 ( L_17 ) ;
V_57 = - V_89 ;
goto V_90;
}
V_57 = F_76 ( V_4 , V_88 , V_11 ) ;
if ( F_15 ( V_57 ) )
goto V_90;
if ( F_13 ( V_20 ) )
memcpy ( V_39 + V_20 -> V_40 , V_88 + V_29 ,
V_20 -> V_21 ) ;
F_25 ( V_37 ) ;
V_57 = 0 ;
V_90:
F_24 ( V_39 ) ;
if ( F_13 ( V_20 ) )
F_67 ( V_88 ) ;
return V_57 ;
}
static int F_84 ( struct V_4 * V_4 , struct V_19 * V_20 , T_1 V_11 ,
int V_29 )
{
int V_57 = 0 ;
T_2 V_91 ;
unsigned long V_77 ;
struct V_37 * V_37 ;
unsigned char * V_39 , * V_85 , * V_92 , * V_88 = NULL ;
struct V_9 * V_10 = V_4 -> V_10 ;
struct V_93 * V_94 = NULL ;
unsigned long V_95 ;
V_37 = V_20 -> V_38 ;
if ( F_13 ( V_20 ) ) {
V_88 = F_69 ( V_22 , V_81 ) ;
if ( ! V_88 ) {
V_57 = - V_89 ;
goto V_59;
}
V_57 = F_76 ( V_4 , V_88 , V_11 ) ;
if ( V_57 )
goto V_59;
}
V_94 = F_85 ( V_4 -> V_58 ) ;
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
F_77 ( V_86 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_73 ( V_4 , V_11 ) ;
F_9 ( V_10 , V_11 , V_83 ) ;
F_78 ( V_86 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_86 ( & V_4 -> V_33 . V_73 ) ;
V_57 = 0 ;
goto V_59;
}
V_57 = F_87 ( V_4 -> V_58 , V_94 , V_88 , & V_91 ) ;
if ( ! F_13 ( V_20 ) ) {
F_24 ( V_39 ) ;
V_39 = NULL ;
V_88 = NULL ;
}
if ( F_15 ( V_57 ) ) {
F_71 ( L_18 , V_57 ) ;
goto V_59;
}
V_92 = V_94 -> V_96 ;
if ( F_15 ( V_91 > V_97 ) ) {
V_91 = V_22 ;
if ( F_13 ( V_20 ) )
V_92 = V_88 ;
}
V_77 = F_88 ( V_10 -> V_48 , V_91 ) ;
if ( ! V_77 ) {
F_71 ( L_19 ,
V_11 , V_91 ) ;
V_57 = - V_89 ;
goto V_59;
}
V_95 = F_34 ( V_10 -> V_48 ) ;
F_17 ( V_4 , V_95 ) ;
if ( V_4 -> V_49 && V_95 > V_4 -> V_49 ) {
F_64 ( V_10 -> V_48 , V_77 ) ;
V_57 = - V_89 ;
goto V_59;
}
V_85 = F_79 ( V_10 -> V_48 , V_77 , V_98 ) ;
if ( ( V_91 == V_22 ) && ! F_13 ( V_20 ) ) {
V_92 = F_22 ( V_37 ) ;
F_80 ( V_85 , V_92 ) ;
F_24 ( V_92 ) ;
} else {
memcpy ( V_85 , V_92 , V_91 ) ;
}
F_89 ( V_4 -> V_58 , V_94 ) ;
V_94 = NULL ;
F_82 ( V_10 -> V_48 , V_77 ) ;
F_77 ( V_86 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_73 ( V_4 , V_11 ) ;
V_10 -> V_14 [ V_11 ] . V_77 = V_77 ;
F_12 ( V_10 , V_11 , V_91 ) ;
F_78 ( V_86 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_90 ( V_91 , & V_4 -> V_33 . V_72 ) ;
F_86 ( & V_4 -> V_33 . V_46 ) ;
V_59:
if ( V_94 )
F_89 ( V_4 -> V_58 , V_94 ) ;
if ( F_13 ( V_20 ) )
F_67 ( V_88 ) ;
return V_57 ;
}
static void F_91 ( struct V_4 * V_4 , T_1 V_11 ,
int V_29 , struct V_99 * V_99 )
{
T_2 V_100 = V_99 -> V_101 . V_102 ;
struct V_9 * V_10 = V_4 -> V_10 ;
if ( V_29 ) {
if ( V_100 <= ( V_22 - V_29 ) )
return;
V_100 -= ( V_22 - V_29 ) ;
V_11 ++ ;
}
while ( V_100 >= V_22 ) {
F_77 ( V_86 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_73 ( V_4 , V_11 ) ;
F_78 ( V_86 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_86 ( & V_4 -> V_33 . V_66 ) ;
V_11 ++ ;
V_100 -= V_22 ;
}
}
static int F_92 ( struct V_4 * V_4 , struct V_19 * V_20 , T_1 V_11 ,
int V_29 , int V_103 )
{
unsigned long V_104 = V_105 ;
int V_57 ;
F_93 ( V_103 , V_20 -> V_21 >> V_28 ,
& V_4 -> V_106 -> V_107 ) ;
if ( V_103 == V_108 ) {
F_86 ( & V_4 -> V_33 . V_109 ) ;
V_57 = F_83 ( V_4 , V_20 , V_11 , V_29 ) ;
} else {
F_86 ( & V_4 -> V_33 . V_110 ) ;
V_57 = F_84 ( V_4 , V_20 , V_11 , V_29 ) ;
}
F_94 ( V_103 , & V_4 -> V_106 -> V_107 , V_104 ) ;
if ( F_15 ( V_57 ) ) {
if ( V_103 == V_108 )
F_86 ( & V_4 -> V_33 . V_63 ) ;
else
F_86 ( & V_4 -> V_33 . V_64 ) ;
}
return V_57 ;
}
static void F_95 ( struct V_4 * V_4 , struct V_99 * V_99 )
{
int V_29 , V_103 ;
T_1 V_11 ;
struct V_19 V_20 ;
struct V_111 V_112 ;
V_11 = V_99 -> V_101 . V_113 >> V_114 ;
V_29 = ( V_99 -> V_101 . V_113 &
( V_115 - 1 ) ) << V_28 ;
if ( F_15 ( V_99 -> V_116 & V_117 ) ) {
F_91 ( V_4 , V_11 , V_29 , V_99 ) ;
F_96 ( V_99 ) ;
return;
}
V_103 = F_97 ( V_99 ) ;
F_98 (bvec, bio, iter) {
int V_118 = V_22 - V_29 ;
if ( V_20 . V_21 > V_118 ) {
struct V_19 V_119 ;
V_119 . V_38 = V_20 . V_38 ;
V_119 . V_21 = V_118 ;
V_119 . V_40 = V_20 . V_40 ;
if ( F_92 ( V_4 , & V_119 , V_11 , V_29 , V_103 ) < 0 )
goto V_59;
V_119 . V_21 = V_20 . V_21 - V_118 ;
V_119 . V_40 += V_118 ;
if ( F_92 ( V_4 , & V_119 , V_11 + 1 , 0 , V_103 ) < 0 )
goto V_59;
} else
if ( F_92 ( V_4 , & V_20 , V_11 , V_29 , V_103 ) < 0 )
goto V_59;
F_16 ( & V_11 , & V_29 , & V_20 ) ;
}
F_96 ( V_99 ) ;
return;
V_59:
F_99 ( V_99 ) ;
}
static T_6 F_100 ( struct V_120 * V_121 , struct V_99 * V_99 )
{
struct V_4 * V_4 = V_121 -> V_122 ;
if ( F_15 ( ! F_59 ( V_4 ) ) )
goto error;
F_101 ( V_121 , & V_99 , V_121 -> V_123 ) ;
if ( ! F_14 ( V_4 , V_99 -> V_101 . V_113 ,
V_99 -> V_101 . V_102 ) ) {
F_86 ( & V_4 -> V_33 . V_65 ) ;
goto V_124;
}
F_95 ( V_4 , V_99 ) ;
F_61 ( V_4 ) ;
return V_125 ;
V_124:
F_61 ( V_4 ) ;
error:
F_99 ( V_99 ) ;
return V_125 ;
}
static void F_102 ( struct V_126 * V_127 ,
unsigned long V_11 )
{
struct V_4 * V_4 ;
struct V_9 * V_10 ;
V_4 = V_127 -> V_128 -> V_8 ;
V_10 = V_4 -> V_10 ;
F_77 ( V_86 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_73 ( V_4 , V_11 ) ;
F_78 ( V_86 , & V_10 -> V_14 [ V_11 ] . V_15 ) ;
F_86 ( & V_4 -> V_33 . V_66 ) ;
}
static int F_103 ( struct V_126 * V_127 , T_3 V_129 ,
struct V_37 * V_37 , int V_103 )
{
int V_29 , V_54 = - V_130 ;
T_1 V_11 ;
struct V_4 * V_4 ;
struct V_19 V_119 ;
V_4 = V_127 -> V_128 -> V_8 ;
if ( F_15 ( ! F_59 ( V_4 ) ) )
goto V_59;
if ( ! F_14 ( V_4 , V_129 , V_22 ) ) {
F_86 ( & V_4 -> V_33 . V_65 ) ;
V_54 = - V_53 ;
goto V_124;
}
V_11 = V_129 >> V_114 ;
V_29 = V_129 & ( V_115 - 1 ) << V_28 ;
V_119 . V_38 = V_37 ;
V_119 . V_21 = V_22 ;
V_119 . V_40 = 0 ;
V_54 = F_92 ( V_4 , & V_119 , V_11 , V_29 , V_103 ) ;
V_124:
F_61 ( V_4 ) ;
V_59:
if ( V_54 == 0 )
F_104 ( V_37 , V_103 , 0 ) ;
return V_54 ;
}
static void F_105 ( struct V_4 * V_4 )
{
struct V_9 * V_10 ;
struct V_131 * V_58 ;
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
F_61 ( V_4 ) ;
F_106 ( V_4 -> V_132 , F_107 ( & V_4 -> V_75 ) == 0 ) ;
memset ( & V_4 -> V_33 , 0 , sizeof( V_4 -> V_33 ) ) ;
V_4 -> V_5 = 0 ;
V_4 -> V_55 = 1 ;
F_108 ( V_4 -> V_106 , 0 ) ;
F_109 ( & V_4 -> V_106 -> V_107 , 0 ) ;
F_40 ( & V_4 -> V_45 ) ;
F_63 ( V_10 , V_5 ) ;
F_110 ( V_58 ) ;
}
static T_5 F_111 ( struct V_6 * V_7 ,
struct V_41 * V_42 , const char * V_43 , T_2 V_50 )
{
T_4 V_5 ;
struct V_131 * V_58 ;
struct V_9 * V_10 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
int V_54 ;
V_5 = F_37 ( V_43 , NULL ) ;
if ( ! V_5 )
return - V_53 ;
V_5 = F_39 ( V_5 ) ;
V_10 = F_68 ( V_4 -> V_106 -> V_133 , V_5 ) ;
if ( ! V_10 )
return - V_89 ;
V_58 = F_112 ( V_4 -> V_61 , V_4 -> V_55 ) ;
if ( F_113 ( V_58 ) ) {
F_71 ( L_20 ,
V_4 -> V_61 ) ;
V_54 = F_114 ( V_58 ) ;
goto V_134;
}
F_38 ( & V_4 -> V_45 ) ;
if ( F_4 ( V_4 ) ) {
F_49 ( L_21 ) ;
V_54 = - V_62 ;
goto V_135;
}
F_115 ( & V_4 -> V_132 ) ;
F_116 ( & V_4 -> V_75 , 1 ) ;
V_4 -> V_10 = V_10 ;
V_4 -> V_58 = V_58 ;
V_4 -> V_5 = V_5 ;
F_108 ( V_4 -> V_106 , V_4 -> V_5 >> V_28 ) ;
F_40 ( & V_4 -> V_45 ) ;
F_117 ( V_4 -> V_106 ) ;
return V_50 ;
V_135:
F_40 ( & V_4 -> V_45 ) ;
F_110 ( V_58 ) ;
V_134:
F_63 ( V_10 , V_5 ) ;
return V_54 ;
}
static T_5 F_118 ( struct V_6 * V_7 ,
struct V_41 * V_42 , const char * V_43 , T_2 V_50 )
{
int V_57 ;
unsigned short V_136 ;
struct V_4 * V_4 ;
struct V_126 * V_127 ;
V_57 = F_119 ( V_43 , 10 , & V_136 ) ;
if ( V_57 )
return V_57 ;
if ( ! V_136 )
return - V_53 ;
V_4 = F_5 ( V_7 ) ;
V_127 = F_120 ( V_4 -> V_106 , 0 ) ;
if ( ! V_127 )
return - V_89 ;
F_121 ( & V_127 -> V_137 ) ;
if ( V_127 -> V_138 || V_4 -> V_139 ) {
F_122 ( & V_127 -> V_137 ) ;
F_123 ( V_127 ) ;
return - V_62 ;
}
V_4 -> V_139 = true ;
F_122 ( & V_127 -> V_137 ) ;
F_124 ( V_127 ) ;
F_105 ( V_4 ) ;
F_117 ( V_4 -> V_106 ) ;
F_123 ( V_127 ) ;
F_121 ( & V_127 -> V_137 ) ;
V_4 -> V_139 = false ;
F_122 ( & V_127 -> V_137 ) ;
return V_50 ;
}
static int F_125 ( struct V_126 * V_127 , T_7 V_140 )
{
int V_57 = 0 ;
struct V_4 * V_4 ;
F_126 ( ! F_127 ( & V_127 -> V_137 ) ) ;
V_4 = V_127 -> V_128 -> V_8 ;
if ( V_4 -> V_139 )
V_57 = - V_62 ;
return V_57 ;
}
static int F_128 ( void )
{
struct V_4 * V_4 ;
struct V_120 * V_121 ;
int V_57 , V_141 ;
V_4 = F_129 ( sizeof( struct V_4 ) , V_79 ) ;
if ( ! V_4 )
return - V_89 ;
V_57 = F_130 ( & V_142 , V_4 , 0 , 0 , V_79 ) ;
if ( V_57 < 0 )
goto V_143;
V_141 = V_57 ;
F_131 ( & V_4 -> V_45 ) ;
V_121 = F_132 ( V_79 ) ;
if ( ! V_121 ) {
F_71 ( L_22 ,
V_141 ) ;
V_57 = - V_89 ;
goto V_144;
}
F_133 ( V_121 , F_100 ) ;
V_4 -> V_106 = F_134 ( 1 ) ;
if ( ! V_4 -> V_106 ) {
F_71 ( L_23 ,
V_141 ) ;
V_57 = - V_89 ;
goto V_145;
}
V_4 -> V_106 -> V_146 = V_147 ;
V_4 -> V_106 -> V_148 = V_141 ;
V_4 -> V_106 -> V_149 = & V_150 ;
V_4 -> V_106 -> V_121 = V_121 ;
V_4 -> V_106 -> V_121 -> V_122 = V_4 ;
V_4 -> V_106 -> V_8 = V_4 ;
snprintf ( V_4 -> V_106 -> V_133 , 16 , L_24 , V_141 ) ;
F_108 ( V_4 -> V_106 , 0 ) ;
F_135 ( V_151 , V_4 -> V_106 -> V_121 ) ;
F_136 ( V_152 , V_4 -> V_106 -> V_121 ) ;
F_137 ( V_4 -> V_106 -> V_121 , V_22 ) ;
F_138 ( V_4 -> V_106 -> V_121 ,
V_27 ) ;
F_139 ( V_4 -> V_106 -> V_121 , V_22 ) ;
F_140 ( V_4 -> V_106 -> V_121 , V_22 ) ;
V_4 -> V_106 -> V_121 -> V_153 . V_154 = V_22 ;
F_141 ( V_4 -> V_106 -> V_121 , V_155 ) ;
if ( V_27 == V_22 )
V_4 -> V_106 -> V_121 -> V_153 . V_156 = 1 ;
else
V_4 -> V_106 -> V_121 -> V_153 . V_156 = 0 ;
F_135 ( V_157 , V_4 -> V_106 -> V_121 ) ;
F_142 ( V_4 -> V_106 ) ;
V_57 = F_143 ( & F_144 ( V_4 -> V_106 ) -> V_158 ,
& V_159 ) ;
if ( V_57 < 0 ) {
F_71 ( L_25 ,
V_141 ) ;
goto V_160;
}
F_54 ( V_4 -> V_61 , V_161 , sizeof( V_4 -> V_61 ) ) ;
V_4 -> V_10 = NULL ;
V_4 -> V_55 = 1 ;
F_49 ( L_26 , V_4 -> V_106 -> V_133 ) ;
return V_141 ;
V_160:
F_145 ( V_4 -> V_106 ) ;
F_146 ( V_4 -> V_106 ) ;
V_145:
F_147 ( V_121 ) ;
V_144:
F_148 ( & V_142 , V_141 ) ;
V_143:
F_67 ( V_4 ) ;
return V_57 ;
}
static int F_149 ( struct V_4 * V_4 )
{
struct V_126 * V_127 ;
V_127 = F_120 ( V_4 -> V_106 , 0 ) ;
if ( ! V_127 )
return - V_89 ;
F_121 ( & V_127 -> V_137 ) ;
if ( V_127 -> V_138 || V_4 -> V_139 ) {
F_122 ( & V_127 -> V_137 ) ;
F_123 ( V_127 ) ;
return - V_62 ;
}
V_4 -> V_139 = true ;
F_122 ( & V_127 -> V_137 ) ;
F_150 ( & F_144 ( V_4 -> V_106 ) -> V_158 ,
& V_159 ) ;
F_124 ( V_127 ) ;
F_105 ( V_4 ) ;
F_123 ( V_127 ) ;
F_49 ( L_27 , V_4 -> V_106 -> V_133 ) ;
F_147 ( V_4 -> V_106 -> V_121 ) ;
F_145 ( V_4 -> V_106 ) ;
F_146 ( V_4 -> V_106 ) ;
F_67 ( V_4 ) ;
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
V_4 = F_153 ( & V_142 , V_166 ) ;
if ( V_4 ) {
V_57 = F_149 ( V_4 ) ;
F_148 ( & V_142 , V_166 ) ;
} else {
V_57 = - V_167 ;
}
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
F_157 ( & V_142 , & F_154 , NULL ) ;
F_158 ( & V_142 ) ;
F_159 ( V_147 , L_28 ) ;
}
static int T_8 F_160 ( void )
{
int V_57 ;
V_57 = F_161 ( & V_170 ) ;
if ( V_57 ) {
F_71 ( L_29 ) ;
return V_57 ;
}
V_147 = F_162 ( 0 , L_28 ) ;
if ( V_147 <= 0 ) {
F_71 ( L_30 ) ;
F_156 ( & V_170 ) ;
return - V_62 ;
}
while ( V_171 != 0 ) {
F_121 ( & V_164 ) ;
V_57 = F_128 () ;
F_122 ( & V_164 ) ;
if ( V_57 < 0 )
goto V_80;
V_171 -- ;
}
return 0 ;
V_80:
F_155 () ;
return V_57 ;
}
static void T_9 F_163 ( void )
{
F_155 () ;
}
