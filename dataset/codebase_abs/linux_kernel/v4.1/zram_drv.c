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
static T_1 F_7 ( struct V_6 * V_7 ,
struct V_9 * V_10 , const char * V_11 , T_2 V_12 )
{
unsigned long V_13 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
struct V_14 * V_15 ;
F_8 ( & V_4 -> V_16 ) ;
if ( ! F_4 ( V_4 ) ) {
F_9 ( & V_4 -> V_16 ) ;
return - V_17 ;
}
V_15 = V_4 -> V_15 ;
V_13 = F_10 ( V_15 -> V_18 ) ;
F_11 ( V_13 , & V_4 -> V_19 . V_20 ) ;
F_9 ( & V_4 -> V_16 ) ;
return V_12 ;
}
static T_1 F_12 ( struct V_6 * V_7 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_4 * V_4 = F_5 ( V_7 ) ;
return F_13 ( V_11 , V_21 , L_3 , V_4 -> V_5 ) ;
}
static T_1 F_14 ( struct V_6 * V_7 ,
struct V_9 * V_10 , char * V_11 )
{
T_3 V_22 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
F_8 ( & V_4 -> V_16 ) ;
V_22 = F_4 ( V_4 ) ;
F_9 ( & V_4 -> V_16 ) ;
return F_13 ( V_11 , V_21 , L_4 , V_22 ) ;
}
static T_1 F_15 ( struct V_6 * V_7 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_4 * V_4 = F_5 ( V_7 ) ;
F_1 ( L_5 ) ;
return F_13 ( V_11 , V_21 , L_3 ,
( V_23 ) ( F_16 ( & V_4 -> V_19 . V_24 ) ) << V_25 ) ;
}
static T_1 F_17 ( struct V_6 * V_7 ,
struct V_9 * V_10 , char * V_11 )
{
V_23 V_22 = 0 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
F_1 ( L_6 ) ;
F_8 ( & V_4 -> V_16 ) ;
if ( F_4 ( V_4 ) ) {
struct V_14 * V_15 = V_4 -> V_15 ;
V_22 = F_18 ( V_15 -> V_18 ) ;
}
F_9 ( & V_4 -> V_16 ) ;
return F_13 ( V_11 , V_21 , L_3 , V_22 << V_25 ) ;
}
static T_1 F_19 ( struct V_6 * V_7 ,
struct V_9 * V_10 , char * V_11 )
{
int V_22 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
F_8 ( & V_4 -> V_16 ) ;
V_22 = V_4 -> V_26 ;
F_9 ( & V_4 -> V_16 ) ;
return F_13 ( V_11 , V_21 , L_7 , V_22 ) ;
}
static T_1 F_20 ( struct V_6 * V_7 ,
struct V_9 * V_10 , char * V_11 )
{
V_23 V_22 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
F_1 ( L_8 ) ;
F_8 ( & V_4 -> V_16 ) ;
V_22 = V_4 -> V_27 ;
F_9 ( & V_4 -> V_16 ) ;
return F_13 ( V_11 , V_21 , L_3 , V_22 << V_25 ) ;
}
static T_1 F_21 ( struct V_6 * V_7 ,
struct V_9 * V_10 , const char * V_11 , T_2 V_12 )
{
V_23 V_28 ;
char * V_29 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
V_28 = F_22 ( V_11 , & V_29 ) ;
if ( V_11 == V_29 )
return - V_17 ;
F_23 ( & V_4 -> V_16 ) ;
V_4 -> V_27 = F_24 ( V_28 ) >> V_25 ;
F_25 ( & V_4 -> V_16 ) ;
return V_12 ;
}
static T_1 F_26 ( struct V_6 * V_7 ,
struct V_9 * V_10 , char * V_11 )
{
V_23 V_22 = 0 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
F_1 ( L_9 ) ;
F_8 ( & V_4 -> V_16 ) ;
if ( F_4 ( V_4 ) )
V_22 = F_27 ( & V_4 -> V_19 . V_30 ) ;
F_9 ( & V_4 -> V_16 ) ;
return F_13 ( V_11 , V_21 , L_3 , V_22 << V_25 ) ;
}
static T_1 F_28 ( struct V_6 * V_7 ,
struct V_9 * V_10 , const char * V_11 , T_2 V_12 )
{
int V_31 ;
unsigned long V_22 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
V_31 = F_29 ( V_11 , 10 , & V_22 ) ;
if ( V_31 || V_22 != 0 )
return - V_17 ;
F_8 ( & V_4 -> V_16 ) ;
if ( F_4 ( V_4 ) ) {
struct V_14 * V_15 = V_4 -> V_15 ;
F_30 ( & V_4 -> V_19 . V_30 ,
F_18 ( V_15 -> V_18 ) ) ;
}
F_9 ( & V_4 -> V_16 ) ;
return V_12 ;
}
static T_1 F_31 ( struct V_6 * V_7 ,
struct V_9 * V_10 , const char * V_11 , T_2 V_12 )
{
int V_32 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
int V_33 ;
V_33 = F_32 ( V_11 , 0 , & V_32 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_32 < 1 )
return - V_17 ;
F_23 ( & V_4 -> V_16 ) ;
if ( F_4 ( V_4 ) ) {
if ( ! F_33 ( V_4 -> V_34 , V_32 ) ) {
F_34 ( L_10 ) ;
V_33 = - V_17 ;
goto V_35;
}
}
V_4 -> V_26 = V_32 ;
V_33 = V_12 ;
V_35:
F_25 ( & V_4 -> V_16 ) ;
return V_33 ;
}
static T_1 F_35 ( struct V_6 * V_7 ,
struct V_9 * V_10 , char * V_11 )
{
T_2 V_36 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
F_8 ( & V_4 -> V_16 ) ;
V_36 = F_36 ( V_4 -> V_37 , V_11 ) ;
F_9 ( & V_4 -> V_16 ) ;
return V_36 ;
}
static T_1 F_37 ( struct V_6 * V_7 ,
struct V_9 * V_10 , const char * V_11 , T_2 V_12 )
{
struct V_4 * V_4 = F_5 ( V_7 ) ;
F_23 ( & V_4 -> V_16 ) ;
if ( F_4 ( V_4 ) ) {
F_25 ( & V_4 -> V_16 ) ;
F_34 ( L_11 ) ;
return - V_38 ;
}
F_38 ( V_4 -> V_37 , V_11 , sizeof( V_4 -> V_37 ) ) ;
F_25 ( & V_4 -> V_16 ) ;
return V_12 ;
}
static int F_39 ( struct V_14 * V_15 , T_3 V_39 ,
enum V_40 V_41 )
{
return V_15 -> V_42 [ V_39 ] . V_43 & F_40 ( V_41 ) ;
}
static void F_41 ( struct V_14 * V_15 , T_3 V_39 ,
enum V_40 V_41 )
{
V_15 -> V_42 [ V_39 ] . V_43 |= F_40 ( V_41 ) ;
}
static void F_42 ( struct V_14 * V_15 , T_3 V_39 ,
enum V_40 V_41 )
{
V_15 -> V_42 [ V_39 ] . V_43 &= ~ F_40 ( V_41 ) ;
}
static T_2 F_43 ( struct V_14 * V_15 , T_3 V_39 )
{
return V_15 -> V_42 [ V_39 ] . V_43 & ( F_40 ( V_44 ) - 1 ) ;
}
static void F_44 ( struct V_14 * V_15 ,
T_3 V_39 , T_2 V_45 )
{
unsigned long V_46 = V_15 -> V_42 [ V_39 ] . V_43 >> V_44 ;
V_15 -> V_42 [ V_39 ] . V_43 = ( V_46 << V_44 ) | V_45 ;
}
static inline int F_45 ( struct V_47 * V_48 )
{
return V_48 -> V_49 != V_21 ;
}
static inline int F_46 ( struct V_4 * V_4 ,
T_4 V_50 , unsigned int V_45 )
{
V_23 V_51 , V_52 ;
if ( F_47 ( V_50 & ( V_53 - 1 ) ) )
return 0 ;
if ( F_47 ( V_45 & ( V_54 - 1 ) ) )
return 0 ;
V_51 = V_50 + ( V_45 >> V_55 ) ;
V_52 = V_4 -> V_5 >> V_55 ;
if ( F_47 ( V_50 >= V_52 || V_51 > V_52 || V_50 > V_51 ) )
return 0 ;
return 1 ;
}
static void F_48 ( struct V_14 * V_15 , V_23 V_5 )
{
T_2 V_56 = V_5 >> V_25 ;
T_2 V_39 ;
for ( V_39 = 0 ; V_39 < V_56 ; V_39 ++ ) {
unsigned long V_57 = V_15 -> V_42 [ V_39 ] . V_57 ;
if ( ! V_57 )
continue;
F_49 ( V_15 -> V_18 , V_57 ) ;
}
F_50 ( V_15 -> V_18 ) ;
F_51 ( V_15 -> V_42 ) ;
F_52 ( V_15 ) ;
}
static struct V_14 * F_53 ( int V_58 , V_23 V_5 )
{
T_2 V_56 ;
char V_59 [ 8 ] ;
struct V_14 * V_15 = F_54 ( sizeof( * V_15 ) , V_60 ) ;
if ( ! V_15 )
return NULL ;
V_56 = V_5 >> V_25 ;
V_15 -> V_42 = F_55 ( V_56 * sizeof( * V_15 -> V_42 ) ) ;
if ( ! V_15 -> V_42 ) {
F_56 ( L_12 ) ;
goto V_61;
}
snprintf ( V_59 , sizeof( V_59 ) , L_13 , V_58 ) ;
V_15 -> V_18 = F_57 ( V_59 , V_62 | V_63 ) ;
if ( ! V_15 -> V_18 ) {
F_56 ( L_14 ) ;
goto V_61;
}
return V_15 ;
V_61:
F_51 ( V_15 -> V_42 ) ;
F_52 ( V_15 ) ;
return NULL ;
}
static inline bool F_58 ( struct V_4 * V_4 )
{
if ( F_59 ( & V_4 -> V_64 ) )
return true ;
return false ;
}
static inline void F_60 ( struct V_4 * V_4 )
{
F_61 ( & V_4 -> V_64 ) ;
}
static void F_62 ( T_3 * V_39 , int * V_65 , struct V_47 * V_48 )
{
if ( * V_65 + V_48 -> V_49 >= V_21 )
( * V_39 ) ++ ;
* V_65 = ( * V_65 + V_48 -> V_49 ) % V_21 ;
}
static int F_63 ( void * V_66 )
{
unsigned int V_67 ;
unsigned long * V_68 ;
V_68 = ( unsigned long * ) V_66 ;
for ( V_67 = 0 ; V_67 != V_21 / sizeof( * V_68 ) ; V_67 ++ ) {
if ( V_68 [ V_67 ] )
return 0 ;
}
return 1 ;
}
static void F_64 ( struct V_47 * V_48 )
{
struct V_68 * V_68 = V_48 -> V_69 ;
void * V_70 ;
V_70 = F_65 ( V_68 ) ;
if ( F_45 ( V_48 ) )
memset ( V_70 + V_48 -> V_71 , 0 , V_48 -> V_49 ) ;
else
F_66 ( V_70 ) ;
F_67 ( V_70 ) ;
F_68 ( V_68 ) ;
}
static void F_69 ( struct V_4 * V_4 , T_2 V_39 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
unsigned long V_57 = V_15 -> V_42 [ V_39 ] . V_57 ;
if ( F_47 ( ! V_57 ) ) {
if ( F_39 ( V_15 , V_39 , V_72 ) ) {
F_42 ( V_15 , V_39 , V_72 ) ;
F_70 ( & V_4 -> V_19 . V_73 ) ;
}
return;
}
F_49 ( V_15 -> V_18 , V_57 ) ;
F_71 ( F_43 ( V_15 , V_39 ) ,
& V_4 -> V_19 . V_74 ) ;
F_70 ( & V_4 -> V_19 . V_24 ) ;
V_15 -> V_42 [ V_39 ] . V_57 = 0 ;
F_44 ( V_15 , V_39 , 0 ) ;
}
static int F_72 ( struct V_4 * V_4 , char * V_75 , T_3 V_39 )
{
int V_33 = 0 ;
unsigned char * V_76 ;
struct V_14 * V_15 = V_4 -> V_15 ;
unsigned long V_57 ;
T_2 V_45 ;
F_73 ( V_77 , & V_15 -> V_42 [ V_39 ] . V_43 ) ;
V_57 = V_15 -> V_42 [ V_39 ] . V_57 ;
V_45 = F_43 ( V_15 , V_39 ) ;
if ( ! V_57 || F_39 ( V_15 , V_39 , V_72 ) ) {
F_74 ( V_77 , & V_15 -> V_42 [ V_39 ] . V_43 ) ;
F_66 ( V_75 ) ;
return 0 ;
}
V_76 = F_75 ( V_15 -> V_18 , V_57 , V_78 ) ;
if ( V_45 == V_21 )
F_76 ( V_75 , V_76 ) ;
else
V_33 = F_77 ( V_4 -> V_34 , V_76 , V_45 , V_75 ) ;
F_78 ( V_15 -> V_18 , V_57 ) ;
F_74 ( V_77 , & V_15 -> V_42 [ V_39 ] . V_43 ) ;
if ( F_47 ( V_33 ) ) {
F_56 ( L_15 , V_33 , V_39 ) ;
return V_33 ;
}
return 0 ;
}
static int F_79 ( struct V_4 * V_4 , struct V_47 * V_48 ,
T_3 V_39 , int V_65 )
{
int V_33 ;
struct V_68 * V_68 ;
unsigned char * V_70 , * V_79 = NULL ;
struct V_14 * V_15 = V_4 -> V_15 ;
V_68 = V_48 -> V_69 ;
F_73 ( V_77 , & V_15 -> V_42 [ V_39 ] . V_43 ) ;
if ( F_47 ( ! V_15 -> V_42 [ V_39 ] . V_57 ) ||
F_39 ( V_15 , V_39 , V_72 ) ) {
F_74 ( V_77 , & V_15 -> V_42 [ V_39 ] . V_43 ) ;
F_64 ( V_48 ) ;
return 0 ;
}
F_74 ( V_77 , & V_15 -> V_42 [ V_39 ] . V_43 ) ;
if ( F_45 ( V_48 ) )
V_79 = F_54 ( V_21 , V_62 ) ;
V_70 = F_65 ( V_68 ) ;
if ( ! F_45 ( V_48 ) )
V_79 = V_70 ;
if ( ! V_79 ) {
F_34 ( L_16 ) ;
V_33 = - V_80 ;
goto V_81;
}
V_33 = F_72 ( V_4 , V_79 , V_39 ) ;
if ( F_47 ( V_33 ) )
goto V_81;
if ( F_45 ( V_48 ) )
memcpy ( V_70 + V_48 -> V_71 , V_79 + V_65 ,
V_48 -> V_49 ) ;
F_68 ( V_68 ) ;
V_33 = 0 ;
V_81:
F_67 ( V_70 ) ;
if ( F_45 ( V_48 ) )
F_52 ( V_79 ) ;
return V_33 ;
}
static inline void F_80 ( struct V_4 * V_4 ,
const unsigned long V_82 )
{
unsigned long V_83 , V_84 ;
V_83 = F_27 ( & V_4 -> V_19 . V_30 ) ;
do {
V_84 = V_83 ;
if ( V_82 > V_84 )
V_83 = F_81 (
& V_4 -> V_19 . V_30 , V_84 , V_82 ) ;
} while ( V_83 != V_84 );
}
static int F_82 ( struct V_4 * V_4 , struct V_47 * V_48 , T_3 V_39 ,
int V_65 )
{
int V_33 = 0 ;
T_2 V_85 ;
unsigned long V_57 ;
struct V_68 * V_68 ;
unsigned char * V_70 , * V_76 , * V_86 , * V_79 = NULL ;
struct V_14 * V_15 = V_4 -> V_15 ;
struct V_87 * V_88 ;
bool V_89 = false ;
unsigned long V_90 ;
V_68 = V_48 -> V_69 ;
if ( F_45 ( V_48 ) ) {
V_79 = F_54 ( V_21 , V_62 ) ;
if ( ! V_79 ) {
V_33 = - V_80 ;
goto V_35;
}
V_33 = F_72 ( V_4 , V_79 , V_39 ) ;
if ( V_33 )
goto V_35;
}
V_88 = F_83 ( V_4 -> V_34 ) ;
V_89 = true ;
V_70 = F_65 ( V_68 ) ;
if ( F_45 ( V_48 ) ) {
memcpy ( V_79 + V_65 , V_70 + V_48 -> V_71 ,
V_48 -> V_49 ) ;
F_67 ( V_70 ) ;
V_70 = NULL ;
} else {
V_79 = V_70 ;
}
if ( F_63 ( V_79 ) ) {
if ( V_70 )
F_67 ( V_70 ) ;
F_73 ( V_77 , & V_15 -> V_42 [ V_39 ] . V_43 ) ;
F_69 ( V_4 , V_39 ) ;
F_41 ( V_15 , V_39 , V_72 ) ;
F_74 ( V_77 , & V_15 -> V_42 [ V_39 ] . V_43 ) ;
F_84 ( & V_4 -> V_19 . V_73 ) ;
V_33 = 0 ;
goto V_35;
}
V_33 = F_85 ( V_4 -> V_34 , V_88 , V_79 , & V_85 ) ;
if ( ! F_45 ( V_48 ) ) {
F_67 ( V_70 ) ;
V_70 = NULL ;
V_79 = NULL ;
}
if ( F_47 ( V_33 ) ) {
F_56 ( L_17 , V_33 ) ;
goto V_35;
}
V_86 = V_88 -> V_91 ;
if ( F_47 ( V_85 > V_92 ) ) {
V_85 = V_21 ;
if ( F_45 ( V_48 ) )
V_86 = V_79 ;
}
V_57 = F_86 ( V_15 -> V_18 , V_85 ) ;
if ( ! V_57 ) {
F_34 ( L_18 ,
V_39 , V_85 ) ;
V_33 = - V_80 ;
goto V_35;
}
V_90 = F_18 ( V_15 -> V_18 ) ;
if ( V_4 -> V_27 && V_90 > V_4 -> V_27 ) {
F_49 ( V_15 -> V_18 , V_57 ) ;
V_33 = - V_80 ;
goto V_35;
}
F_80 ( V_4 , V_90 ) ;
V_76 = F_75 ( V_15 -> V_18 , V_57 , V_93 ) ;
if ( ( V_85 == V_21 ) && ! F_45 ( V_48 ) ) {
V_86 = F_65 ( V_68 ) ;
F_76 ( V_76 , V_86 ) ;
F_67 ( V_86 ) ;
} else {
memcpy ( V_76 , V_86 , V_85 ) ;
}
F_87 ( V_4 -> V_34 , V_88 ) ;
V_89 = false ;
F_78 ( V_15 -> V_18 , V_57 ) ;
F_73 ( V_77 , & V_15 -> V_42 [ V_39 ] . V_43 ) ;
F_69 ( V_4 , V_39 ) ;
V_15 -> V_42 [ V_39 ] . V_57 = V_57 ;
F_44 ( V_15 , V_39 , V_85 ) ;
F_74 ( V_77 , & V_15 -> V_42 [ V_39 ] . V_43 ) ;
F_11 ( V_85 , & V_4 -> V_19 . V_74 ) ;
F_84 ( & V_4 -> V_19 . V_24 ) ;
V_35:
if ( V_89 )
F_87 ( V_4 -> V_34 , V_88 ) ;
if ( F_45 ( V_48 ) )
F_52 ( V_79 ) ;
return V_33 ;
}
static int F_88 ( struct V_4 * V_4 , struct V_47 * V_48 , T_3 V_39 ,
int V_65 , int V_94 )
{
unsigned long V_95 = V_96 ;
int V_33 ;
F_89 ( V_94 , V_48 -> V_49 >> V_55 ,
& V_4 -> V_97 -> V_98 ) ;
if ( V_94 == V_99 ) {
F_84 ( & V_4 -> V_19 . V_100 ) ;
V_33 = F_79 ( V_4 , V_48 , V_39 , V_65 ) ;
} else {
F_84 ( & V_4 -> V_19 . V_101 ) ;
V_33 = F_82 ( V_4 , V_48 , V_39 , V_65 ) ;
}
F_90 ( V_94 , & V_4 -> V_97 -> V_98 , V_95 ) ;
if ( F_47 ( V_33 ) ) {
if ( V_94 == V_99 )
F_84 ( & V_4 -> V_19 . V_102 ) ;
else
F_84 ( & V_4 -> V_19 . V_103 ) ;
}
return V_33 ;
}
static void F_91 ( struct V_4 * V_4 , T_3 V_39 ,
int V_65 , struct V_104 * V_104 )
{
T_2 V_105 = V_104 -> V_106 . V_107 ;
struct V_14 * V_15 = V_4 -> V_15 ;
if ( V_65 ) {
if ( V_105 <= ( V_21 - V_65 ) )
return;
V_105 -= ( V_21 - V_65 ) ;
V_39 ++ ;
}
while ( V_105 >= V_21 ) {
F_73 ( V_77 , & V_15 -> V_42 [ V_39 ] . V_43 ) ;
F_69 ( V_4 , V_39 ) ;
F_74 ( V_77 , & V_15 -> V_42 [ V_39 ] . V_43 ) ;
F_84 ( & V_4 -> V_19 . V_108 ) ;
V_39 ++ ;
V_105 -= V_21 ;
}
}
static void F_92 ( struct V_4 * V_4 )
{
struct V_14 * V_15 ;
struct V_109 * V_34 ;
V_23 V_5 ;
F_23 ( & V_4 -> V_16 ) ;
V_4 -> V_27 = 0 ;
if ( ! F_4 ( V_4 ) ) {
F_25 ( & V_4 -> V_16 ) ;
return;
}
V_15 = V_4 -> V_15 ;
V_34 = V_4 -> V_34 ;
V_5 = V_4 -> V_5 ;
F_60 ( V_4 ) ;
F_93 ( V_4 -> V_110 , F_94 ( & V_4 -> V_64 ) == 0 ) ;
memset ( & V_4 -> V_19 , 0 , sizeof( V_4 -> V_19 ) ) ;
V_4 -> V_5 = 0 ;
V_4 -> V_26 = 1 ;
F_95 ( V_4 -> V_97 , 0 ) ;
F_96 ( & V_4 -> V_97 -> V_98 , 0 ) ;
F_25 ( & V_4 -> V_16 ) ;
F_48 ( V_15 , V_5 ) ;
F_97 ( V_34 ) ;
}
static T_1 F_98 ( struct V_6 * V_7 ,
struct V_9 * V_10 , const char * V_11 , T_2 V_12 )
{
V_23 V_5 ;
struct V_109 * V_34 ;
struct V_14 * V_15 ;
struct V_4 * V_4 = F_5 ( V_7 ) ;
int V_31 ;
V_5 = F_22 ( V_11 , NULL ) ;
if ( ! V_5 )
return - V_17 ;
V_5 = F_24 ( V_5 ) ;
V_15 = F_53 ( V_4 -> V_97 -> V_111 , V_5 ) ;
if ( ! V_15 )
return - V_80 ;
V_34 = F_99 ( V_4 -> V_37 , V_4 -> V_26 ) ;
if ( F_100 ( V_34 ) ) {
F_34 ( L_19 ,
V_4 -> V_37 ) ;
V_31 = F_101 ( V_34 ) ;
goto V_112;
}
F_23 ( & V_4 -> V_16 ) ;
if ( F_4 ( V_4 ) ) {
F_34 ( L_20 ) ;
V_31 = - V_38 ;
goto V_113;
}
F_102 ( & V_4 -> V_110 ) ;
F_103 ( & V_4 -> V_64 , 1 ) ;
V_4 -> V_15 = V_15 ;
V_4 -> V_34 = V_34 ;
V_4 -> V_5 = V_5 ;
F_95 ( V_4 -> V_97 , V_4 -> V_5 >> V_55 ) ;
F_25 ( & V_4 -> V_16 ) ;
F_104 ( V_4 -> V_97 ) ;
return V_12 ;
V_113:
F_25 ( & V_4 -> V_16 ) ;
F_97 ( V_34 ) ;
V_112:
F_48 ( V_15 , V_5 ) ;
return V_31 ;
}
static T_1 F_105 ( struct V_6 * V_7 ,
struct V_9 * V_10 , const char * V_11 , T_2 V_12 )
{
int V_33 ;
unsigned short V_114 ;
struct V_4 * V_4 ;
struct V_115 * V_116 ;
V_4 = F_5 ( V_7 ) ;
V_116 = F_106 ( V_4 -> V_97 , 0 ) ;
if ( ! V_116 )
return - V_80 ;
F_107 ( & V_116 -> V_117 ) ;
if ( V_116 -> V_118 ) {
V_33 = - V_38 ;
goto V_35;
}
V_33 = F_108 ( V_11 , 10 , & V_114 ) ;
if ( V_33 )
goto V_35;
if ( ! V_114 ) {
V_33 = - V_17 ;
goto V_35;
}
F_109 ( V_116 ) ;
F_92 ( V_4 ) ;
F_110 ( & V_116 -> V_117 ) ;
F_104 ( V_4 -> V_97 ) ;
F_111 ( V_116 ) ;
return V_12 ;
V_35:
F_110 ( & V_116 -> V_117 ) ;
F_111 ( V_116 ) ;
return V_33 ;
}
static void F_112 ( struct V_4 * V_4 , struct V_104 * V_104 )
{
int V_65 , V_94 ;
T_3 V_39 ;
struct V_47 V_48 ;
struct V_119 V_120 ;
V_39 = V_104 -> V_106 . V_121 >> V_122 ;
V_65 = ( V_104 -> V_106 . V_121 &
( V_123 - 1 ) ) << V_55 ;
if ( F_47 ( V_104 -> V_124 & V_125 ) ) {
F_91 ( V_4 , V_39 , V_65 , V_104 ) ;
F_113 ( V_104 , 0 ) ;
return;
}
V_94 = F_114 ( V_104 ) ;
F_115 (bvec, bio, iter) {
int V_126 = V_21 - V_65 ;
if ( V_48 . V_49 > V_126 ) {
struct V_47 V_127 ;
V_127 . V_69 = V_48 . V_69 ;
V_127 . V_49 = V_126 ;
V_127 . V_71 = V_48 . V_71 ;
if ( F_88 ( V_4 , & V_127 , V_39 , V_65 , V_94 ) < 0 )
goto V_35;
V_127 . V_49 = V_48 . V_49 - V_126 ;
V_127 . V_71 += V_126 ;
if ( F_88 ( V_4 , & V_127 , V_39 + 1 , 0 , V_94 ) < 0 )
goto V_35;
} else
if ( F_88 ( V_4 , & V_48 , V_39 , V_65 , V_94 ) < 0 )
goto V_35;
F_62 ( & V_39 , & V_65 , & V_48 ) ;
}
F_116 ( V_128 , & V_104 -> V_129 ) ;
F_113 ( V_104 , 0 ) ;
return;
V_35:
F_117 ( V_104 ) ;
}
static void F_118 ( struct V_130 * V_131 , struct V_104 * V_104 )
{
struct V_4 * V_4 = V_131 -> V_132 ;
if ( F_47 ( ! F_58 ( V_4 ) ) )
goto error;
if ( ! F_46 ( V_4 , V_104 -> V_106 . V_121 ,
V_104 -> V_106 . V_107 ) ) {
F_84 ( & V_4 -> V_19 . V_133 ) ;
goto V_134;
}
F_112 ( V_4 , V_104 ) ;
F_60 ( V_4 ) ;
return;
V_134:
F_60 ( V_4 ) ;
error:
F_117 ( V_104 ) ;
}
static void F_119 ( struct V_115 * V_116 ,
unsigned long V_39 )
{
struct V_4 * V_4 ;
struct V_14 * V_15 ;
V_4 = V_116 -> V_135 -> V_8 ;
V_15 = V_4 -> V_15 ;
F_73 ( V_77 , & V_15 -> V_42 [ V_39 ] . V_43 ) ;
F_69 ( V_4 , V_39 ) ;
F_74 ( V_77 , & V_15 -> V_42 [ V_39 ] . V_43 ) ;
F_84 ( & V_4 -> V_19 . V_108 ) ;
}
static int F_120 ( struct V_115 * V_116 , T_4 V_136 ,
struct V_68 * V_68 , int V_94 )
{
int V_65 , V_31 = - V_137 ;
T_3 V_39 ;
struct V_4 * V_4 ;
struct V_47 V_127 ;
V_4 = V_116 -> V_135 -> V_8 ;
if ( F_47 ( ! F_58 ( V_4 ) ) )
goto V_35;
if ( ! F_46 ( V_4 , V_136 , V_21 ) ) {
F_84 ( & V_4 -> V_19 . V_133 ) ;
V_31 = - V_17 ;
goto V_134;
}
V_39 = V_136 >> V_122 ;
V_65 = V_136 & ( V_123 - 1 ) << V_55 ;
V_127 . V_69 = V_68 ;
V_127 . V_49 = V_21 ;
V_127 . V_71 = 0 ;
V_31 = F_88 ( V_4 , & V_127 , V_39 , V_65 , V_94 ) ;
V_134:
F_60 ( V_4 ) ;
V_35:
if ( V_31 == 0 )
F_121 ( V_68 , V_94 , 0 ) ;
return V_31 ;
}
static T_1 F_122 ( struct V_6 * V_7 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_4 * V_4 = F_5 ( V_7 ) ;
T_1 V_33 ;
F_8 ( & V_4 -> V_16 ) ;
V_33 = F_13 ( V_11 , V_21 ,
L_21 ,
( V_23 ) F_16 ( & V_4 -> V_19 . V_102 ) ,
( V_23 ) F_16 ( & V_4 -> V_19 . V_103 ) ,
( V_23 ) F_16 ( & V_4 -> V_19 . V_133 ) ,
( V_23 ) F_16 ( & V_4 -> V_19 . V_108 ) ) ;
F_9 ( & V_4 -> V_16 ) ;
return V_33 ;
}
static T_1 F_123 ( struct V_6 * V_7 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_4 * V_4 = F_5 ( V_7 ) ;
V_23 V_138 , V_139 = 0 ;
long V_140 ;
T_1 V_33 ;
F_8 ( & V_4 -> V_16 ) ;
if ( F_4 ( V_4 ) )
V_139 = F_18 ( V_4 -> V_15 -> V_18 ) ;
V_138 = F_16 ( & V_4 -> V_19 . V_24 ) ;
V_140 = F_27 ( & V_4 -> V_19 . V_30 ) ;
V_33 = F_13 ( V_11 , V_21 ,
L_22 ,
V_138 << V_25 ,
( V_23 ) F_16 ( & V_4 -> V_19 . V_74 ) ,
V_139 << V_25 ,
V_4 -> V_27 << V_25 ,
V_140 << V_25 ,
( V_23 ) F_16 ( & V_4 -> V_19 . V_73 ) ,
( V_23 ) F_16 ( & V_4 -> V_19 . V_20 ) ) ;
F_9 ( & V_4 -> V_16 ) ;
return V_33 ;
}
static int F_124 ( struct V_4 * V_4 , int V_58 )
{
struct V_130 * V_131 ;
int V_33 = - V_80 ;
F_125 ( & V_4 -> V_16 ) ;
V_131 = F_126 ( V_60 ) ;
if ( ! V_131 ) {
F_56 ( L_23 ,
V_58 ) ;
goto V_35;
}
F_127 ( V_131 , F_118 ) ;
V_4 -> V_97 = F_128 ( 1 ) ;
if ( ! V_4 -> V_97 ) {
F_129 ( L_24 ,
V_58 ) ;
V_33 = - V_80 ;
goto V_141;
}
V_4 -> V_97 -> V_142 = V_143 ;
V_4 -> V_97 -> V_111 = V_58 ;
V_4 -> V_97 -> V_144 = & V_145 ;
V_4 -> V_97 -> V_131 = V_131 ;
V_4 -> V_97 -> V_131 -> V_132 = V_4 ;
V_4 -> V_97 -> V_8 = V_4 ;
snprintf ( V_4 -> V_97 -> V_146 , 16 , L_13 , V_58 ) ;
F_95 ( V_4 -> V_97 , 0 ) ;
F_130 ( V_147 , V_4 -> V_97 -> V_131 ) ;
F_131 ( V_148 , V_4 -> V_97 -> V_131 ) ;
F_132 ( V_4 -> V_97 -> V_131 , V_21 ) ;
F_133 ( V_4 -> V_97 -> V_131 ,
V_54 ) ;
F_134 ( V_4 -> V_97 -> V_131 , V_21 ) ;
F_135 ( V_4 -> V_97 -> V_131 , V_21 ) ;
V_4 -> V_97 -> V_131 -> V_149 . V_150 = V_21 ;
V_4 -> V_97 -> V_131 -> V_149 . V_151 = V_152 ;
if ( V_54 == V_21 )
V_4 -> V_97 -> V_131 -> V_149 . V_153 = 1 ;
else
V_4 -> V_97 -> V_131 -> V_149 . V_153 = 0 ;
F_130 ( V_154 , V_4 -> V_97 -> V_131 ) ;
F_136 ( V_4 -> V_97 ) ;
V_33 = F_137 ( & F_138 ( V_4 -> V_97 ) -> V_155 ,
& V_156 ) ;
if ( V_33 < 0 ) {
F_129 ( L_25 ) ;
goto V_157;
}
F_38 ( V_4 -> V_37 , V_158 , sizeof( V_4 -> V_37 ) ) ;
V_4 -> V_15 = NULL ;
V_4 -> V_26 = 1 ;
return 0 ;
V_157:
F_139 ( V_4 -> V_97 ) ;
F_140 ( V_4 -> V_97 ) ;
V_141:
F_141 ( V_131 ) ;
V_35:
return V_33 ;
}
static void F_142 ( unsigned int V_159 )
{
struct V_4 * V_4 ;
unsigned int V_160 ;
for ( V_160 = 0 ; V_160 < V_159 ; V_160 ++ ) {
V_4 = & V_161 [ V_160 ] ;
F_143 ( & F_138 ( V_4 -> V_97 ) -> V_155 ,
& V_156 ) ;
F_92 ( V_4 ) ;
F_141 ( V_4 -> V_97 -> V_131 ) ;
F_139 ( V_4 -> V_97 ) ;
F_140 ( V_4 -> V_97 ) ;
}
F_52 ( V_161 ) ;
F_144 ( V_143 , L_26 ) ;
F_34 ( L_27 , V_159 ) ;
}
static int T_5 F_145 ( void )
{
int V_33 , V_162 ;
if ( V_163 > V_164 ) {
F_129 ( L_28 ,
V_163 ) ;
return - V_17 ;
}
V_143 = F_146 ( 0 , L_26 ) ;
if ( V_143 <= 0 ) {
F_129 ( L_29 ) ;
return - V_38 ;
}
V_161 = F_147 ( V_163 * sizeof( struct V_4 ) , V_60 ) ;
if ( ! V_161 ) {
F_144 ( V_143 , L_26 ) ;
return - V_80 ;
}
for ( V_162 = 0 ; V_162 < V_163 ; V_162 ++ ) {
V_33 = F_124 ( & V_161 [ V_162 ] , V_162 ) ;
if ( V_33 )
goto V_61;
}
F_34 ( L_30 , V_163 ) ;
return 0 ;
V_61:
F_142 ( V_162 ) ;
return V_33 ;
}
static void T_6 F_148 ( void )
{
F_142 ( V_163 ) ;
}
