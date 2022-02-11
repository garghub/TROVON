static inline bool F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 ;
}
static inline struct V_1 * F_2 ( struct V_3 * V_4 )
{
return (struct V_1 * ) F_3 ( V_4 ) -> V_5 ;
}
static T_1 F_4 ( struct V_3 * V_4 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_1 = F_2 ( V_4 ) ;
return F_5 ( V_8 , V_9 , L_1 , V_1 -> V_2 ) ;
}
static T_1 F_6 ( struct V_3 * V_4 ,
struct V_6 * V_7 , char * V_8 )
{
T_2 V_10 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
F_7 ( & V_1 -> V_11 ) ;
V_10 = F_1 ( V_1 ) ;
F_8 ( & V_1 -> V_11 ) ;
return F_5 ( V_8 , V_9 , L_2 , V_10 ) ;
}
static T_1 F_9 ( struct V_3 * V_4 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_1 = F_2 ( V_4 ) ;
return F_5 ( V_8 , V_9 , L_1 ,
( V_12 ) ( F_10 ( & V_1 -> V_13 . V_14 ) ) << V_15 ) ;
}
static T_1 F_11 ( struct V_3 * V_4 ,
struct V_6 * V_7 , char * V_8 )
{
V_12 V_10 = 0 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
F_7 ( & V_1 -> V_11 ) ;
if ( F_1 ( V_1 ) ) {
struct V_16 * V_17 = V_1 -> V_17 ;
V_10 = F_12 ( V_17 -> V_18 ) ;
}
F_8 ( & V_1 -> V_11 ) ;
return F_5 ( V_8 , V_9 , L_1 , V_10 << V_15 ) ;
}
static T_1 F_13 ( struct V_3 * V_4 ,
struct V_6 * V_7 , char * V_8 )
{
int V_10 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
F_7 ( & V_1 -> V_11 ) ;
V_10 = V_1 -> V_19 ;
F_8 ( & V_1 -> V_11 ) ;
return F_5 ( V_8 , V_9 , L_3 , V_10 ) ;
}
static T_1 F_14 ( struct V_3 * V_4 ,
struct V_6 * V_7 , char * V_8 )
{
V_12 V_10 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
F_7 ( & V_1 -> V_11 ) ;
V_10 = V_1 -> V_20 ;
F_8 ( & V_1 -> V_11 ) ;
return F_5 ( V_8 , V_9 , L_1 , V_10 << V_15 ) ;
}
static T_1 F_15 ( struct V_3 * V_4 ,
struct V_6 * V_7 , const char * V_8 , T_3 V_21 )
{
V_12 V_22 ;
char * V_23 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
V_22 = F_16 ( V_8 , & V_23 ) ;
if ( V_8 == V_23 )
return - V_24 ;
F_17 ( & V_1 -> V_11 ) ;
V_1 -> V_20 = F_18 ( V_22 ) >> V_15 ;
F_19 ( & V_1 -> V_11 ) ;
return V_21 ;
}
static T_1 F_20 ( struct V_3 * V_4 ,
struct V_6 * V_7 , char * V_8 )
{
V_12 V_10 = 0 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
F_7 ( & V_1 -> V_11 ) ;
if ( F_1 ( V_1 ) )
V_10 = F_21 ( & V_1 -> V_13 . V_25 ) ;
F_8 ( & V_1 -> V_11 ) ;
return F_5 ( V_8 , V_9 , L_1 , V_10 << V_15 ) ;
}
static T_1 F_22 ( struct V_3 * V_4 ,
struct V_6 * V_7 , const char * V_8 , T_3 V_21 )
{
int V_26 ;
unsigned long V_10 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
V_26 = F_23 ( V_8 , 10 , & V_10 ) ;
if ( V_26 || V_10 != 0 )
return - V_24 ;
F_7 ( & V_1 -> V_11 ) ;
if ( F_1 ( V_1 ) ) {
struct V_16 * V_17 = V_1 -> V_17 ;
F_24 ( & V_1 -> V_13 . V_25 ,
F_12 ( V_17 -> V_18 ) ) ;
}
F_8 ( & V_1 -> V_11 ) ;
return V_21 ;
}
static T_1 F_25 ( struct V_3 * V_4 ,
struct V_6 * V_7 , const char * V_8 , T_3 V_21 )
{
int V_27 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
int V_28 ;
V_28 = F_26 ( V_8 , 0 , & V_27 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( V_27 < 1 )
return - V_24 ;
F_17 ( & V_1 -> V_11 ) ;
if ( F_1 ( V_1 ) ) {
if ( ! F_27 ( V_1 -> V_29 , V_27 ) ) {
F_28 ( L_4 ) ;
V_28 = - V_24 ;
goto V_30;
}
}
V_1 -> V_19 = V_27 ;
V_28 = V_21 ;
V_30:
F_19 ( & V_1 -> V_11 ) ;
return V_28 ;
}
static T_1 F_29 ( struct V_3 * V_4 ,
struct V_6 * V_7 , char * V_8 )
{
T_3 V_31 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
F_7 ( & V_1 -> V_11 ) ;
V_31 = F_30 ( V_1 -> V_32 , V_8 ) ;
F_8 ( & V_1 -> V_11 ) ;
return V_31 ;
}
static T_1 F_31 ( struct V_3 * V_4 ,
struct V_6 * V_7 , const char * V_8 , T_3 V_21 )
{
struct V_1 * V_1 = F_2 ( V_4 ) ;
F_17 ( & V_1 -> V_11 ) ;
if ( F_1 ( V_1 ) ) {
F_19 ( & V_1 -> V_11 ) ;
F_28 ( L_5 ) ;
return - V_33 ;
}
F_32 ( V_1 -> V_32 , V_8 , sizeof( V_1 -> V_32 ) ) ;
F_19 ( & V_1 -> V_11 ) ;
return V_21 ;
}
static int F_33 ( struct V_16 * V_17 , T_2 V_34 ,
enum V_35 V_36 )
{
return V_17 -> V_37 [ V_34 ] . V_38 & F_34 ( V_36 ) ;
}
static void F_35 ( struct V_16 * V_17 , T_2 V_34 ,
enum V_35 V_36 )
{
V_17 -> V_37 [ V_34 ] . V_38 |= F_34 ( V_36 ) ;
}
static void F_36 ( struct V_16 * V_17 , T_2 V_34 ,
enum V_35 V_36 )
{
V_17 -> V_37 [ V_34 ] . V_38 &= ~ F_34 ( V_36 ) ;
}
static T_3 F_37 ( struct V_16 * V_17 , T_2 V_34 )
{
return V_17 -> V_37 [ V_34 ] . V_38 & ( F_34 ( V_39 ) - 1 ) ;
}
static void F_38 ( struct V_16 * V_17 ,
T_2 V_34 , T_3 V_40 )
{
unsigned long V_41 = V_17 -> V_37 [ V_34 ] . V_38 >> V_39 ;
V_17 -> V_37 [ V_34 ] . V_38 = ( V_41 << V_39 ) | V_40 ;
}
static inline int F_39 ( struct V_42 * V_43 )
{
return V_43 -> V_44 != V_9 ;
}
static inline int F_40 ( struct V_1 * V_1 ,
T_4 V_45 , unsigned int V_40 )
{
V_12 V_46 , V_47 ;
if ( F_41 ( V_45 & ( V_48 - 1 ) ) )
return 0 ;
if ( F_41 ( V_40 & ( V_49 - 1 ) ) )
return 0 ;
V_46 = V_45 + ( V_40 >> V_50 ) ;
V_47 = V_1 -> V_2 >> V_50 ;
if ( F_41 ( V_45 >= V_47 || V_46 > V_47 || V_45 > V_46 ) )
return 0 ;
return 1 ;
}
static void F_42 ( struct V_16 * V_17 , V_12 V_2 )
{
T_3 V_51 = V_2 >> V_15 ;
T_3 V_34 ;
for ( V_34 = 0 ; V_34 < V_51 ; V_34 ++ ) {
unsigned long V_52 = V_17 -> V_37 [ V_34 ] . V_52 ;
if ( ! V_52 )
continue;
F_43 ( V_17 -> V_18 , V_52 ) ;
}
F_44 ( V_17 -> V_18 ) ;
F_45 ( V_17 -> V_37 ) ;
F_46 ( V_17 ) ;
}
static struct V_16 * F_47 ( int V_53 , V_12 V_2 )
{
T_3 V_51 ;
char V_54 [ 8 ] ;
struct V_16 * V_17 = F_48 ( sizeof( * V_17 ) , V_55 ) ;
if ( ! V_17 )
return NULL ;
V_51 = V_2 >> V_15 ;
V_17 -> V_37 = F_49 ( V_51 * sizeof( * V_17 -> V_37 ) ) ;
if ( ! V_17 -> V_37 ) {
F_50 ( L_6 ) ;
goto V_56;
}
snprintf ( V_54 , sizeof( V_54 ) , L_7 , V_53 ) ;
V_17 -> V_18 = F_51 ( V_54 , V_57 | V_58 ) ;
if ( ! V_17 -> V_18 ) {
F_50 ( L_8 ) ;
goto V_56;
}
return V_17 ;
V_56:
F_45 ( V_17 -> V_37 ) ;
F_46 ( V_17 ) ;
return NULL ;
}
static inline bool F_52 ( struct V_1 * V_1 )
{
if ( F_53 ( & V_1 -> V_59 ) )
return true ;
return false ;
}
static inline void F_54 ( struct V_1 * V_1 )
{
F_55 ( & V_1 -> V_59 ) ;
}
static void F_56 ( T_2 * V_34 , int * V_60 , struct V_42 * V_43 )
{
if ( * V_60 + V_43 -> V_44 >= V_9 )
( * V_34 ) ++ ;
* V_60 = ( * V_60 + V_43 -> V_44 ) % V_9 ;
}
static int F_57 ( void * V_61 )
{
unsigned int V_62 ;
unsigned long * V_63 ;
V_63 = ( unsigned long * ) V_61 ;
for ( V_62 = 0 ; V_62 != V_9 / sizeof( * V_63 ) ; V_62 ++ ) {
if ( V_63 [ V_62 ] )
return 0 ;
}
return 1 ;
}
static void F_58 ( struct V_42 * V_43 )
{
struct V_63 * V_63 = V_43 -> V_64 ;
void * V_65 ;
V_65 = F_59 ( V_63 ) ;
if ( F_39 ( V_43 ) )
memset ( V_65 + V_43 -> V_66 , 0 , V_43 -> V_44 ) ;
else
F_60 ( V_65 ) ;
F_61 ( V_65 ) ;
F_62 ( V_63 ) ;
}
static void F_63 ( struct V_1 * V_1 , T_3 V_34 )
{
struct V_16 * V_17 = V_1 -> V_17 ;
unsigned long V_52 = V_17 -> V_37 [ V_34 ] . V_52 ;
if ( F_41 ( ! V_52 ) ) {
if ( F_33 ( V_17 , V_34 , V_67 ) ) {
F_36 ( V_17 , V_34 , V_67 ) ;
F_64 ( & V_1 -> V_13 . V_68 ) ;
}
return;
}
F_43 ( V_17 -> V_18 , V_52 ) ;
F_65 ( F_37 ( V_17 , V_34 ) ,
& V_1 -> V_13 . V_69 ) ;
F_64 ( & V_1 -> V_13 . V_14 ) ;
V_17 -> V_37 [ V_34 ] . V_52 = 0 ;
F_38 ( V_17 , V_34 , 0 ) ;
}
static int F_66 ( struct V_1 * V_1 , char * V_70 , T_2 V_34 )
{
int V_28 = 0 ;
unsigned char * V_71 ;
struct V_16 * V_17 = V_1 -> V_17 ;
unsigned long V_52 ;
T_3 V_40 ;
F_67 ( V_72 , & V_17 -> V_37 [ V_34 ] . V_38 ) ;
V_52 = V_17 -> V_37 [ V_34 ] . V_52 ;
V_40 = F_37 ( V_17 , V_34 ) ;
if ( ! V_52 || F_33 ( V_17 , V_34 , V_67 ) ) {
F_68 ( V_72 , & V_17 -> V_37 [ V_34 ] . V_38 ) ;
F_60 ( V_70 ) ;
return 0 ;
}
V_71 = F_69 ( V_17 -> V_18 , V_52 , V_73 ) ;
if ( V_40 == V_9 )
F_70 ( V_70 , V_71 ) ;
else
V_28 = F_71 ( V_1 -> V_29 , V_71 , V_40 , V_70 ) ;
F_72 ( V_17 -> V_18 , V_52 ) ;
F_68 ( V_72 , & V_17 -> V_37 [ V_34 ] . V_38 ) ;
if ( F_41 ( V_28 ) ) {
F_50 ( L_9 , V_28 , V_34 ) ;
return V_28 ;
}
return 0 ;
}
static int F_73 ( struct V_1 * V_1 , struct V_42 * V_43 ,
T_2 V_34 , int V_60 )
{
int V_28 ;
struct V_63 * V_63 ;
unsigned char * V_65 , * V_74 = NULL ;
struct V_16 * V_17 = V_1 -> V_17 ;
V_63 = V_43 -> V_64 ;
F_67 ( V_72 , & V_17 -> V_37 [ V_34 ] . V_38 ) ;
if ( F_41 ( ! V_17 -> V_37 [ V_34 ] . V_52 ) ||
F_33 ( V_17 , V_34 , V_67 ) ) {
F_68 ( V_72 , & V_17 -> V_37 [ V_34 ] . V_38 ) ;
F_58 ( V_43 ) ;
return 0 ;
}
F_68 ( V_72 , & V_17 -> V_37 [ V_34 ] . V_38 ) ;
if ( F_39 ( V_43 ) )
V_74 = F_48 ( V_9 , V_57 ) ;
V_65 = F_59 ( V_63 ) ;
if ( ! F_39 ( V_43 ) )
V_74 = V_65 ;
if ( ! V_74 ) {
F_28 ( L_10 ) ;
V_28 = - V_75 ;
goto V_76;
}
V_28 = F_66 ( V_1 , V_74 , V_34 ) ;
if ( F_41 ( V_28 ) )
goto V_76;
if ( F_39 ( V_43 ) )
memcpy ( V_65 + V_43 -> V_66 , V_74 + V_60 ,
V_43 -> V_44 ) ;
F_62 ( V_63 ) ;
V_28 = 0 ;
V_76:
F_61 ( V_65 ) ;
if ( F_39 ( V_43 ) )
F_46 ( V_74 ) ;
return V_28 ;
}
static inline void F_74 ( struct V_1 * V_1 ,
const unsigned long V_77 )
{
unsigned long V_78 , V_79 ;
V_78 = F_21 ( & V_1 -> V_13 . V_25 ) ;
do {
V_79 = V_78 ;
if ( V_77 > V_79 )
V_78 = F_75 (
& V_1 -> V_13 . V_25 , V_79 , V_77 ) ;
} while ( V_78 != V_79 );
}
static int F_76 ( struct V_1 * V_1 , struct V_42 * V_43 , T_2 V_34 ,
int V_60 )
{
int V_28 = 0 ;
T_3 V_80 ;
unsigned long V_52 ;
struct V_63 * V_63 ;
unsigned char * V_65 , * V_71 , * V_81 , * V_74 = NULL ;
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_82 * V_83 ;
bool V_84 = false ;
unsigned long V_85 ;
V_63 = V_43 -> V_64 ;
if ( F_39 ( V_43 ) ) {
V_74 = F_48 ( V_9 , V_57 ) ;
if ( ! V_74 ) {
V_28 = - V_75 ;
goto V_30;
}
V_28 = F_66 ( V_1 , V_74 , V_34 ) ;
if ( V_28 )
goto V_30;
}
V_83 = F_77 ( V_1 -> V_29 ) ;
V_84 = true ;
V_65 = F_59 ( V_63 ) ;
if ( F_39 ( V_43 ) ) {
memcpy ( V_74 + V_60 , V_65 + V_43 -> V_66 ,
V_43 -> V_44 ) ;
F_61 ( V_65 ) ;
V_65 = NULL ;
} else {
V_74 = V_65 ;
}
if ( F_57 ( V_74 ) ) {
if ( V_65 )
F_61 ( V_65 ) ;
F_67 ( V_72 , & V_17 -> V_37 [ V_34 ] . V_38 ) ;
F_63 ( V_1 , V_34 ) ;
F_35 ( V_17 , V_34 , V_67 ) ;
F_68 ( V_72 , & V_17 -> V_37 [ V_34 ] . V_38 ) ;
F_78 ( & V_1 -> V_13 . V_68 ) ;
V_28 = 0 ;
goto V_30;
}
V_28 = F_79 ( V_1 -> V_29 , V_83 , V_74 , & V_80 ) ;
if ( ! F_39 ( V_43 ) ) {
F_61 ( V_65 ) ;
V_65 = NULL ;
V_74 = NULL ;
}
if ( F_41 ( V_28 ) ) {
F_50 ( L_11 , V_28 ) ;
goto V_30;
}
V_81 = V_83 -> V_86 ;
if ( F_41 ( V_80 > V_87 ) ) {
V_80 = V_9 ;
if ( F_39 ( V_43 ) )
V_81 = V_74 ;
}
V_52 = F_80 ( V_17 -> V_18 , V_80 ) ;
if ( ! V_52 ) {
F_28 ( L_12 ,
V_34 , V_80 ) ;
V_28 = - V_75 ;
goto V_30;
}
V_85 = F_12 ( V_17 -> V_18 ) ;
if ( V_1 -> V_20 && V_85 > V_1 -> V_20 ) {
F_43 ( V_17 -> V_18 , V_52 ) ;
V_28 = - V_75 ;
goto V_30;
}
F_74 ( V_1 , V_85 ) ;
V_71 = F_69 ( V_17 -> V_18 , V_52 , V_88 ) ;
if ( ( V_80 == V_9 ) && ! F_39 ( V_43 ) ) {
V_81 = F_59 ( V_63 ) ;
F_70 ( V_71 , V_81 ) ;
F_61 ( V_81 ) ;
} else {
memcpy ( V_71 , V_81 , V_80 ) ;
}
F_81 ( V_1 -> V_29 , V_83 ) ;
V_84 = false ;
F_72 ( V_17 -> V_18 , V_52 ) ;
F_67 ( V_72 , & V_17 -> V_37 [ V_34 ] . V_38 ) ;
F_63 ( V_1 , V_34 ) ;
V_17 -> V_37 [ V_34 ] . V_52 = V_52 ;
F_38 ( V_17 , V_34 , V_80 ) ;
F_68 ( V_72 , & V_17 -> V_37 [ V_34 ] . V_38 ) ;
F_82 ( V_80 , & V_1 -> V_13 . V_69 ) ;
F_78 ( & V_1 -> V_13 . V_14 ) ;
V_30:
if ( V_84 )
F_81 ( V_1 -> V_29 , V_83 ) ;
if ( F_39 ( V_43 ) )
F_46 ( V_74 ) ;
return V_28 ;
}
static int F_83 ( struct V_1 * V_1 , struct V_42 * V_43 , T_2 V_34 ,
int V_60 , int V_89 )
{
int V_28 ;
if ( V_89 == V_90 ) {
F_78 ( & V_1 -> V_13 . V_91 ) ;
V_28 = F_73 ( V_1 , V_43 , V_34 , V_60 ) ;
} else {
F_78 ( & V_1 -> V_13 . V_92 ) ;
V_28 = F_76 ( V_1 , V_43 , V_34 , V_60 ) ;
}
if ( F_41 ( V_28 ) ) {
if ( V_89 == V_90 )
F_78 ( & V_1 -> V_13 . V_93 ) ;
else
F_78 ( & V_1 -> V_13 . V_94 ) ;
}
return V_28 ;
}
static void F_84 ( struct V_1 * V_1 , T_2 V_34 ,
int V_60 , struct V_95 * V_95 )
{
T_3 V_96 = V_95 -> V_97 . V_98 ;
struct V_16 * V_17 = V_1 -> V_17 ;
if ( V_60 ) {
if ( V_96 <= ( V_9 - V_60 ) )
return;
V_96 -= ( V_9 - V_60 ) ;
V_34 ++ ;
}
while ( V_96 >= V_9 ) {
F_67 ( V_72 , & V_17 -> V_37 [ V_34 ] . V_38 ) ;
F_63 ( V_1 , V_34 ) ;
F_68 ( V_72 , & V_17 -> V_37 [ V_34 ] . V_38 ) ;
F_78 ( & V_1 -> V_13 . V_99 ) ;
V_34 ++ ;
V_96 -= V_9 ;
}
}
static void F_85 ( struct V_1 * V_1 )
{
struct V_16 * V_17 ;
struct V_100 * V_29 ;
V_12 V_2 ;
F_17 ( & V_1 -> V_11 ) ;
V_1 -> V_20 = 0 ;
if ( ! F_1 ( V_1 ) ) {
F_19 ( & V_1 -> V_11 ) ;
return;
}
V_17 = V_1 -> V_17 ;
V_29 = V_1 -> V_29 ;
V_2 = V_1 -> V_2 ;
F_54 ( V_1 ) ;
F_86 ( V_1 -> V_101 , F_87 ( & V_1 -> V_59 ) == 0 ) ;
memset ( & V_1 -> V_13 , 0 , sizeof( V_1 -> V_13 ) ) ;
V_1 -> V_2 = 0 ;
V_1 -> V_19 = 1 ;
F_88 ( V_1 -> V_102 , 0 ) ;
F_19 ( & V_1 -> V_11 ) ;
F_42 ( V_17 , V_2 ) ;
F_89 ( V_29 ) ;
}
static T_1 F_90 ( struct V_3 * V_4 ,
struct V_6 * V_7 , const char * V_8 , T_3 V_21 )
{
V_12 V_2 ;
struct V_100 * V_29 ;
struct V_16 * V_17 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
int V_26 ;
V_2 = F_16 ( V_8 , NULL ) ;
if ( ! V_2 )
return - V_24 ;
V_2 = F_18 ( V_2 ) ;
V_17 = F_47 ( V_1 -> V_102 -> V_103 , V_2 ) ;
if ( ! V_17 )
return - V_75 ;
V_29 = F_91 ( V_1 -> V_32 , V_1 -> V_19 ) ;
if ( F_92 ( V_29 ) ) {
F_28 ( L_13 ,
V_1 -> V_32 ) ;
V_26 = F_93 ( V_29 ) ;
goto V_104;
}
F_17 ( & V_1 -> V_11 ) ;
if ( F_1 ( V_1 ) ) {
F_28 ( L_14 ) ;
V_26 = - V_33 ;
goto V_105;
}
F_94 ( & V_1 -> V_101 ) ;
F_95 ( & V_1 -> V_59 , 1 ) ;
V_1 -> V_17 = V_17 ;
V_1 -> V_29 = V_29 ;
V_1 -> V_2 = V_2 ;
F_88 ( V_1 -> V_102 , V_1 -> V_2 >> V_50 ) ;
F_19 ( & V_1 -> V_11 ) ;
F_96 ( V_1 -> V_102 ) ;
return V_21 ;
V_105:
F_19 ( & V_1 -> V_11 ) ;
F_89 ( V_29 ) ;
V_104:
F_42 ( V_17 , V_2 ) ;
return V_26 ;
}
static T_1 F_97 ( struct V_3 * V_4 ,
struct V_6 * V_7 , const char * V_8 , T_3 V_21 )
{
int V_28 ;
unsigned short V_106 ;
struct V_1 * V_1 ;
struct V_107 * V_108 ;
V_1 = F_2 ( V_4 ) ;
V_108 = F_98 ( V_1 -> V_102 , 0 ) ;
if ( ! V_108 )
return - V_75 ;
F_99 ( & V_108 -> V_109 ) ;
if ( V_108 -> V_110 ) {
V_28 = - V_33 ;
goto V_30;
}
V_28 = F_100 ( V_8 , 10 , & V_106 ) ;
if ( V_28 )
goto V_30;
if ( ! V_106 ) {
V_28 = - V_24 ;
goto V_30;
}
F_101 ( V_108 ) ;
F_85 ( V_1 ) ;
F_102 ( & V_108 -> V_109 ) ;
F_96 ( V_1 -> V_102 ) ;
F_103 ( V_108 ) ;
return V_21 ;
V_30:
F_102 ( & V_108 -> V_109 ) ;
F_103 ( V_108 ) ;
return V_28 ;
}
static void F_104 ( struct V_1 * V_1 , struct V_95 * V_95 )
{
int V_60 , V_89 ;
T_2 V_34 ;
struct V_42 V_43 ;
struct V_111 V_112 ;
V_34 = V_95 -> V_97 . V_113 >> V_114 ;
V_60 = ( V_95 -> V_97 . V_113 &
( V_115 - 1 ) ) << V_50 ;
if ( F_41 ( V_95 -> V_116 & V_117 ) ) {
F_84 ( V_1 , V_34 , V_60 , V_95 ) ;
F_105 ( V_95 , 0 ) ;
return;
}
V_89 = F_106 ( V_95 ) ;
F_107 (bvec, bio, iter) {
int V_118 = V_9 - V_60 ;
if ( V_43 . V_44 > V_118 ) {
struct V_42 V_119 ;
V_119 . V_64 = V_43 . V_64 ;
V_119 . V_44 = V_118 ;
V_119 . V_66 = V_43 . V_66 ;
if ( F_83 ( V_1 , & V_119 , V_34 , V_60 , V_89 ) < 0 )
goto V_30;
V_119 . V_44 = V_43 . V_44 - V_118 ;
V_119 . V_66 += V_118 ;
if ( F_83 ( V_1 , & V_119 , V_34 + 1 , 0 , V_89 ) < 0 )
goto V_30;
} else
if ( F_83 ( V_1 , & V_43 , V_34 , V_60 , V_89 ) < 0 )
goto V_30;
F_56 ( & V_34 , & V_60 , & V_43 ) ;
}
F_108 ( V_120 , & V_95 -> V_121 ) ;
F_105 ( V_95 , 0 ) ;
return;
V_30:
F_109 ( V_95 ) ;
}
static void F_110 ( struct V_122 * V_123 , struct V_95 * V_95 )
{
struct V_1 * V_1 = V_123 -> V_124 ;
if ( F_41 ( ! F_52 ( V_1 ) ) )
goto error;
if ( ! F_40 ( V_1 , V_95 -> V_97 . V_113 ,
V_95 -> V_97 . V_98 ) ) {
F_78 ( & V_1 -> V_13 . V_125 ) ;
goto V_126;
}
F_104 ( V_1 , V_95 ) ;
F_54 ( V_1 ) ;
return;
V_126:
F_54 ( V_1 ) ;
error:
F_109 ( V_95 ) ;
}
static void F_111 ( struct V_107 * V_108 ,
unsigned long V_34 )
{
struct V_1 * V_1 ;
struct V_16 * V_17 ;
V_1 = V_108 -> V_127 -> V_5 ;
V_17 = V_1 -> V_17 ;
F_67 ( V_72 , & V_17 -> V_37 [ V_34 ] . V_38 ) ;
F_63 ( V_1 , V_34 ) ;
F_68 ( V_72 , & V_17 -> V_37 [ V_34 ] . V_38 ) ;
F_78 ( & V_1 -> V_13 . V_99 ) ;
}
static int F_112 ( struct V_107 * V_108 , T_4 V_128 ,
struct V_63 * V_63 , int V_89 )
{
int V_60 , V_26 = - V_129 ;
T_2 V_34 ;
struct V_1 * V_1 ;
struct V_42 V_119 ;
V_1 = V_108 -> V_127 -> V_5 ;
if ( F_41 ( ! F_52 ( V_1 ) ) )
goto V_30;
if ( ! F_40 ( V_1 , V_128 , V_9 ) ) {
F_78 ( & V_1 -> V_13 . V_125 ) ;
V_26 = - V_24 ;
goto V_126;
}
V_34 = V_128 >> V_114 ;
V_60 = V_128 & ( V_115 - 1 ) << V_50 ;
V_119 . V_64 = V_63 ;
V_119 . V_44 = V_9 ;
V_119 . V_66 = 0 ;
V_26 = F_83 ( V_1 , & V_119 , V_34 , V_60 , V_89 ) ;
V_126:
F_54 ( V_1 ) ;
V_30:
if ( V_26 == 0 )
F_113 ( V_63 , V_89 , 0 ) ;
return V_26 ;
}
static int F_114 ( struct V_1 * V_1 , int V_53 )
{
struct V_122 * V_123 ;
int V_28 = - V_75 ;
F_115 ( & V_1 -> V_11 ) ;
V_123 = F_116 ( V_55 ) ;
if ( ! V_123 ) {
F_50 ( L_15 ,
V_53 ) ;
goto V_30;
}
F_117 ( V_123 , F_110 ) ;
V_1 -> V_102 = F_118 ( 1 ) ;
if ( ! V_1 -> V_102 ) {
F_119 ( L_16 ,
V_53 ) ;
goto V_130;
}
V_1 -> V_102 -> V_131 = V_132 ;
V_1 -> V_102 -> V_103 = V_53 ;
V_1 -> V_102 -> V_133 = & V_134 ;
V_1 -> V_102 -> V_123 = V_123 ;
V_1 -> V_102 -> V_123 -> V_124 = V_1 ;
V_1 -> V_102 -> V_5 = V_1 ;
snprintf ( V_1 -> V_102 -> V_135 , 16 , L_7 , V_53 ) ;
F_88 ( V_1 -> V_102 , 0 ) ;
F_120 ( V_136 , V_1 -> V_102 -> V_123 ) ;
F_121 ( V_137 , V_1 -> V_102 -> V_123 ) ;
F_122 ( V_1 -> V_102 -> V_123 , V_9 ) ;
F_123 ( V_1 -> V_102 -> V_123 ,
V_49 ) ;
F_124 ( V_1 -> V_102 -> V_123 , V_9 ) ;
F_125 ( V_1 -> V_102 -> V_123 , V_9 ) ;
V_1 -> V_102 -> V_123 -> V_138 . V_139 = V_9 ;
V_1 -> V_102 -> V_123 -> V_138 . V_140 = V_141 ;
if ( V_49 == V_9 )
V_1 -> V_102 -> V_123 -> V_138 . V_142 = 1 ;
else
V_1 -> V_102 -> V_123 -> V_138 . V_142 = 0 ;
F_120 ( V_143 , V_1 -> V_102 -> V_123 ) ;
F_126 ( V_1 -> V_102 ) ;
V_28 = F_127 ( & F_128 ( V_1 -> V_102 ) -> V_144 ,
& V_145 ) ;
if ( V_28 < 0 ) {
F_119 ( L_17 ) ;
goto V_146;
}
F_32 ( V_1 -> V_32 , V_147 , sizeof( V_1 -> V_32 ) ) ;
V_1 -> V_17 = NULL ;
V_1 -> V_19 = 1 ;
return 0 ;
V_146:
F_129 ( V_1 -> V_102 ) ;
F_130 ( V_1 -> V_102 ) ;
V_130:
F_131 ( V_123 ) ;
V_30:
return V_28 ;
}
static void F_132 ( unsigned int V_148 )
{
struct V_1 * V_1 ;
unsigned int V_149 ;
for ( V_149 = 0 ; V_149 < V_148 ; V_149 ++ ) {
V_1 = & V_150 [ V_149 ] ;
F_133 ( & F_128 ( V_1 -> V_102 ) -> V_144 ,
& V_145 ) ;
F_85 ( V_1 ) ;
F_131 ( V_1 -> V_102 -> V_123 ) ;
F_129 ( V_1 -> V_102 ) ;
F_130 ( V_1 -> V_102 ) ;
}
F_46 ( V_150 ) ;
F_134 ( V_132 , L_18 ) ;
F_28 ( L_19 , V_148 ) ;
}
static int T_5 F_135 ( void )
{
int V_28 , V_151 ;
if ( V_152 > V_153 ) {
F_119 ( L_20 ,
V_152 ) ;
return - V_24 ;
}
V_132 = F_136 ( 0 , L_18 ) ;
if ( V_132 <= 0 ) {
F_119 ( L_21 ) ;
return - V_33 ;
}
V_150 = F_137 ( V_152 * sizeof( struct V_1 ) , V_55 ) ;
if ( ! V_150 ) {
F_134 ( V_132 , L_18 ) ;
return - V_75 ;
}
for ( V_151 = 0 ; V_151 < V_152 ; V_151 ++ ) {
V_28 = F_114 ( & V_150 [ V_151 ] , V_151 ) ;
if ( V_28 )
goto V_56;
}
F_28 ( L_22 , V_152 ) ;
return 0 ;
V_56:
F_132 ( V_151 ) ;
return V_28 ;
}
static void T_6 F_138 ( void )
{
F_132 ( V_152 ) ;
}
