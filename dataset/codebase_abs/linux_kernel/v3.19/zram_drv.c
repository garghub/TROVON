static inline int F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 != NULL ;
}
static inline struct V_1 * F_2 ( struct V_3 * V_4 )
{
return (struct V_1 * ) F_3 ( V_4 ) -> V_5 ;
}
static T_1 F_4 ( struct V_3 * V_4 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_1 = F_2 ( V_4 ) ;
return F_5 ( V_8 , V_9 , L_1 , V_1 -> V_10 ) ;
}
static T_1 F_6 ( struct V_3 * V_4 ,
struct V_6 * V_7 , char * V_8 )
{
T_2 V_11 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
F_7 ( & V_1 -> V_12 ) ;
V_11 = F_1 ( V_1 ) ;
F_8 ( & V_1 -> V_12 ) ;
return F_5 ( V_8 , V_9 , L_2 , V_11 ) ;
}
static T_1 F_9 ( struct V_3 * V_4 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_1 = F_2 ( V_4 ) ;
return F_5 ( V_8 , V_9 , L_1 ,
( V_13 ) ( F_10 ( & V_1 -> V_14 . V_15 ) ) << V_16 ) ;
}
static T_1 F_11 ( struct V_3 * V_4 ,
struct V_6 * V_7 , char * V_8 )
{
V_13 V_11 = 0 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
F_7 ( & V_1 -> V_12 ) ;
if ( F_1 ( V_1 ) ) {
struct V_17 * V_2 = V_1 -> V_2 ;
V_11 = F_12 ( V_2 -> V_18 ) ;
}
F_8 ( & V_1 -> V_12 ) ;
return F_5 ( V_8 , V_9 , L_1 , V_11 << V_16 ) ;
}
static T_1 F_13 ( struct V_3 * V_4 ,
struct V_6 * V_7 , char * V_8 )
{
int V_11 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
F_7 ( & V_1 -> V_12 ) ;
V_11 = V_1 -> V_19 ;
F_8 ( & V_1 -> V_12 ) ;
return F_5 ( V_8 , V_9 , L_3 , V_11 ) ;
}
static T_1 F_14 ( struct V_3 * V_4 ,
struct V_6 * V_7 , char * V_8 )
{
V_13 V_11 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
F_7 ( & V_1 -> V_12 ) ;
V_11 = V_1 -> V_20 ;
F_8 ( & V_1 -> V_12 ) ;
return F_5 ( V_8 , V_9 , L_1 , V_11 << V_16 ) ;
}
static T_1 F_15 ( struct V_3 * V_4 ,
struct V_6 * V_7 , const char * V_8 , T_3 V_21 )
{
V_13 V_22 ;
char * V_23 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
V_22 = F_16 ( V_8 , & V_23 ) ;
if ( V_8 == V_23 )
return - V_24 ;
F_17 ( & V_1 -> V_12 ) ;
V_1 -> V_20 = F_18 ( V_22 ) >> V_16 ;
F_19 ( & V_1 -> V_12 ) ;
return V_21 ;
}
static T_1 F_20 ( struct V_3 * V_4 ,
struct V_6 * V_7 , char * V_8 )
{
V_13 V_11 = 0 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
F_7 ( & V_1 -> V_12 ) ;
if ( F_1 ( V_1 ) )
V_11 = F_21 ( & V_1 -> V_14 . V_25 ) ;
F_8 ( & V_1 -> V_12 ) ;
return F_5 ( V_8 , V_9 , L_1 , V_11 << V_16 ) ;
}
static T_1 F_22 ( struct V_3 * V_4 ,
struct V_6 * V_7 , const char * V_8 , T_3 V_21 )
{
int V_26 ;
unsigned long V_11 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
V_26 = F_23 ( V_8 , 10 , & V_11 ) ;
if ( V_26 || V_11 != 0 )
return - V_24 ;
F_7 ( & V_1 -> V_12 ) ;
if ( F_1 ( V_1 ) ) {
struct V_17 * V_2 = V_1 -> V_2 ;
F_24 ( & V_1 -> V_14 . V_25 ,
F_12 ( V_2 -> V_18 ) ) ;
}
F_8 ( & V_1 -> V_12 ) ;
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
F_17 ( & V_1 -> V_12 ) ;
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
F_19 ( & V_1 -> V_12 ) ;
return V_28 ;
}
static T_1 F_29 ( struct V_3 * V_4 ,
struct V_6 * V_7 , char * V_8 )
{
T_3 V_31 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
F_7 ( & V_1 -> V_12 ) ;
V_31 = F_30 ( V_1 -> V_32 , V_8 ) ;
F_8 ( & V_1 -> V_12 ) ;
return V_31 ;
}
static T_1 F_31 ( struct V_3 * V_4 ,
struct V_6 * V_7 , const char * V_8 , T_3 V_21 )
{
struct V_1 * V_1 = F_2 ( V_4 ) ;
F_17 ( & V_1 -> V_12 ) ;
if ( F_1 ( V_1 ) ) {
F_19 ( & V_1 -> V_12 ) ;
F_28 ( L_5 ) ;
return - V_33 ;
}
F_32 ( V_1 -> V_32 , V_8 , sizeof( V_1 -> V_32 ) ) ;
F_19 ( & V_1 -> V_12 ) ;
return V_21 ;
}
static int F_33 ( struct V_17 * V_2 , T_2 V_34 ,
enum V_35 V_36 )
{
return V_2 -> V_37 [ V_34 ] . V_38 & F_34 ( V_36 ) ;
}
static void F_35 ( struct V_17 * V_2 , T_2 V_34 ,
enum V_35 V_36 )
{
V_2 -> V_37 [ V_34 ] . V_38 |= F_34 ( V_36 ) ;
}
static void F_36 ( struct V_17 * V_2 , T_2 V_34 ,
enum V_35 V_36 )
{
V_2 -> V_37 [ V_34 ] . V_38 &= ~ F_34 ( V_36 ) ;
}
static T_3 F_37 ( struct V_17 * V_2 , T_2 V_34 )
{
return V_2 -> V_37 [ V_34 ] . V_38 & ( F_34 ( V_39 ) - 1 ) ;
}
static void F_38 ( struct V_17 * V_2 ,
T_2 V_34 , T_3 V_40 )
{
unsigned long V_41 = V_2 -> V_37 [ V_34 ] . V_38 >> V_39 ;
V_2 -> V_37 [ V_34 ] . V_38 = ( V_41 << V_39 ) | V_40 ;
}
static inline int F_39 ( struct V_42 * V_43 )
{
return V_43 -> V_44 != V_9 ;
}
static inline int F_40 ( struct V_1 * V_1 ,
T_4 V_45 , unsigned int V_40 )
{
V_13 V_46 , V_47 ;
if ( F_41 ( V_45 & ( V_48 - 1 ) ) )
return 0 ;
if ( F_41 ( V_40 & ( V_49 - 1 ) ) )
return 0 ;
V_46 = V_45 + ( V_40 >> V_50 ) ;
V_47 = V_1 -> V_10 >> V_50 ;
if ( F_41 ( V_45 >= V_47 || V_46 > V_47 || V_45 > V_46 ) )
return 0 ;
return 1 ;
}
static void F_42 ( struct V_17 * V_2 )
{
F_43 ( V_2 -> V_18 ) ;
F_44 ( V_2 -> V_37 ) ;
F_45 ( V_2 ) ;
}
static struct V_17 * F_46 ( V_13 V_10 )
{
T_3 V_51 ;
struct V_17 * V_2 = F_47 ( sizeof( * V_2 ) , V_52 ) ;
if ( ! V_2 )
goto V_30;
V_51 = V_10 >> V_16 ;
V_2 -> V_37 = F_48 ( V_51 * sizeof( * V_2 -> V_37 ) ) ;
if ( ! V_2 -> V_37 ) {
F_49 ( L_6 ) ;
goto V_53;
}
V_2 -> V_18 = F_50 ( V_54 | V_55 ) ;
if ( ! V_2 -> V_18 ) {
F_49 ( L_7 ) ;
goto V_56;
}
return V_2 ;
V_56:
F_44 ( V_2 -> V_37 ) ;
V_53:
F_45 ( V_2 ) ;
V_2 = NULL ;
V_30:
return V_2 ;
}
static void F_51 ( T_2 * V_34 , int * V_57 , struct V_42 * V_43 )
{
if ( * V_57 + V_43 -> V_44 >= V_9 )
( * V_34 ) ++ ;
* V_57 = ( * V_57 + V_43 -> V_44 ) % V_9 ;
}
static int F_52 ( void * V_58 )
{
unsigned int V_59 ;
unsigned long * V_60 ;
V_60 = ( unsigned long * ) V_58 ;
for ( V_59 = 0 ; V_59 != V_9 / sizeof( * V_60 ) ; V_59 ++ ) {
if ( V_60 [ V_59 ] )
return 0 ;
}
return 1 ;
}
static void F_53 ( struct V_42 * V_43 )
{
struct V_60 * V_60 = V_43 -> V_61 ;
void * V_62 ;
V_62 = F_54 ( V_60 ) ;
if ( F_39 ( V_43 ) )
memset ( V_62 + V_43 -> V_63 , 0 , V_43 -> V_44 ) ;
else
F_55 ( V_62 ) ;
F_56 ( V_62 ) ;
F_57 ( V_60 ) ;
}
static void F_58 ( struct V_1 * V_1 , T_3 V_34 )
{
struct V_17 * V_2 = V_1 -> V_2 ;
unsigned long V_64 = V_2 -> V_37 [ V_34 ] . V_64 ;
if ( F_41 ( ! V_64 ) ) {
if ( F_33 ( V_2 , V_34 , V_65 ) ) {
F_36 ( V_2 , V_34 , V_65 ) ;
F_59 ( & V_1 -> V_14 . V_66 ) ;
}
return;
}
F_60 ( V_2 -> V_18 , V_64 ) ;
F_61 ( F_37 ( V_2 , V_34 ) ,
& V_1 -> V_14 . V_67 ) ;
F_59 ( & V_1 -> V_14 . V_15 ) ;
V_2 -> V_37 [ V_34 ] . V_64 = 0 ;
F_38 ( V_2 , V_34 , 0 ) ;
}
static int F_62 ( struct V_1 * V_1 , char * V_68 , T_2 V_34 )
{
int V_28 = 0 ;
unsigned char * V_69 ;
struct V_17 * V_2 = V_1 -> V_2 ;
unsigned long V_64 ;
T_3 V_40 ;
F_63 ( V_70 , & V_2 -> V_37 [ V_34 ] . V_38 ) ;
V_64 = V_2 -> V_37 [ V_34 ] . V_64 ;
V_40 = F_37 ( V_2 , V_34 ) ;
if ( ! V_64 || F_33 ( V_2 , V_34 , V_65 ) ) {
F_64 ( V_70 , & V_2 -> V_37 [ V_34 ] . V_38 ) ;
F_55 ( V_68 ) ;
return 0 ;
}
V_69 = F_65 ( V_2 -> V_18 , V_64 , V_71 ) ;
if ( V_40 == V_9 )
F_66 ( V_68 , V_69 ) ;
else
V_28 = F_67 ( V_1 -> V_29 , V_69 , V_40 , V_68 ) ;
F_68 ( V_2 -> V_18 , V_64 ) ;
F_64 ( V_70 , & V_2 -> V_37 [ V_34 ] . V_38 ) ;
if ( F_41 ( V_28 ) ) {
F_49 ( L_8 , V_28 , V_34 ) ;
return V_28 ;
}
return 0 ;
}
static int F_69 ( struct V_1 * V_1 , struct V_42 * V_43 ,
T_2 V_34 , int V_57 )
{
int V_28 ;
struct V_60 * V_60 ;
unsigned char * V_62 , * V_72 = NULL ;
struct V_17 * V_2 = V_1 -> V_2 ;
V_60 = V_43 -> V_61 ;
F_63 ( V_70 , & V_2 -> V_37 [ V_34 ] . V_38 ) ;
if ( F_41 ( ! V_2 -> V_37 [ V_34 ] . V_64 ) ||
F_33 ( V_2 , V_34 , V_65 ) ) {
F_64 ( V_70 , & V_2 -> V_37 [ V_34 ] . V_38 ) ;
F_53 ( V_43 ) ;
return 0 ;
}
F_64 ( V_70 , & V_2 -> V_37 [ V_34 ] . V_38 ) ;
if ( F_39 ( V_43 ) )
V_72 = F_47 ( V_9 , V_54 ) ;
V_62 = F_54 ( V_60 ) ;
if ( ! F_39 ( V_43 ) )
V_72 = V_62 ;
if ( ! V_72 ) {
F_28 ( L_9 ) ;
V_28 = - V_73 ;
goto V_74;
}
V_28 = F_62 ( V_1 , V_72 , V_34 ) ;
if ( F_41 ( V_28 ) )
goto V_74;
if ( F_39 ( V_43 ) )
memcpy ( V_62 + V_43 -> V_63 , V_72 + V_57 ,
V_43 -> V_44 ) ;
F_57 ( V_60 ) ;
V_28 = 0 ;
V_74:
F_56 ( V_62 ) ;
if ( F_39 ( V_43 ) )
F_45 ( V_72 ) ;
return V_28 ;
}
static inline void F_70 ( struct V_1 * V_1 ,
const unsigned long V_75 )
{
int V_76 , V_77 ;
V_76 = F_21 ( & V_1 -> V_14 . V_25 ) ;
do {
V_77 = V_76 ;
if ( V_75 > V_77 )
V_76 = F_71 (
& V_1 -> V_14 . V_25 , V_77 , V_75 ) ;
} while ( V_76 != V_77 );
}
static int F_72 ( struct V_1 * V_1 , struct V_42 * V_43 , T_2 V_34 ,
int V_57 )
{
int V_28 = 0 ;
T_3 V_78 ;
unsigned long V_64 ;
struct V_60 * V_60 ;
unsigned char * V_62 , * V_69 , * V_79 , * V_72 = NULL ;
struct V_17 * V_2 = V_1 -> V_2 ;
struct V_80 * V_81 ;
bool V_82 = false ;
unsigned long V_83 ;
V_60 = V_43 -> V_61 ;
if ( F_39 ( V_43 ) ) {
V_72 = F_47 ( V_9 , V_54 ) ;
if ( ! V_72 ) {
V_28 = - V_73 ;
goto V_30;
}
V_28 = F_62 ( V_1 , V_72 , V_34 ) ;
if ( V_28 )
goto V_30;
}
V_81 = F_73 ( V_1 -> V_29 ) ;
V_82 = true ;
V_62 = F_54 ( V_60 ) ;
if ( F_39 ( V_43 ) ) {
memcpy ( V_72 + V_57 , V_62 + V_43 -> V_63 ,
V_43 -> V_44 ) ;
F_56 ( V_62 ) ;
V_62 = NULL ;
} else {
V_72 = V_62 ;
}
if ( F_52 ( V_72 ) ) {
if ( V_62 )
F_56 ( V_62 ) ;
F_63 ( V_70 , & V_2 -> V_37 [ V_34 ] . V_38 ) ;
F_58 ( V_1 , V_34 ) ;
F_35 ( V_2 , V_34 , V_65 ) ;
F_64 ( V_70 , & V_2 -> V_37 [ V_34 ] . V_38 ) ;
F_74 ( & V_1 -> V_14 . V_66 ) ;
V_28 = 0 ;
goto V_30;
}
V_28 = F_75 ( V_1 -> V_29 , V_81 , V_72 , & V_78 ) ;
if ( ! F_39 ( V_43 ) ) {
F_56 ( V_62 ) ;
V_62 = NULL ;
V_72 = NULL ;
}
if ( F_41 ( V_28 ) ) {
F_49 ( L_10 , V_28 ) ;
goto V_30;
}
V_79 = V_81 -> V_84 ;
if ( F_41 ( V_78 > V_85 ) ) {
V_78 = V_9 ;
if ( F_39 ( V_43 ) )
V_79 = V_72 ;
}
V_64 = F_76 ( V_2 -> V_18 , V_78 ) ;
if ( ! V_64 ) {
F_28 ( L_11 ,
V_34 , V_78 ) ;
V_28 = - V_73 ;
goto V_30;
}
V_83 = F_12 ( V_2 -> V_18 ) ;
if ( V_1 -> V_20 && V_83 > V_1 -> V_20 ) {
F_60 ( V_2 -> V_18 , V_64 ) ;
V_28 = - V_73 ;
goto V_30;
}
F_70 ( V_1 , V_83 ) ;
V_69 = F_65 ( V_2 -> V_18 , V_64 , V_86 ) ;
if ( ( V_78 == V_9 ) && ! F_39 ( V_43 ) ) {
V_79 = F_54 ( V_60 ) ;
F_66 ( V_69 , V_79 ) ;
F_56 ( V_79 ) ;
} else {
memcpy ( V_69 , V_79 , V_78 ) ;
}
F_77 ( V_1 -> V_29 , V_81 ) ;
V_82 = false ;
F_68 ( V_2 -> V_18 , V_64 ) ;
F_63 ( V_70 , & V_2 -> V_37 [ V_34 ] . V_38 ) ;
F_58 ( V_1 , V_34 ) ;
V_2 -> V_37 [ V_34 ] . V_64 = V_64 ;
F_38 ( V_2 , V_34 , V_78 ) ;
F_64 ( V_70 , & V_2 -> V_37 [ V_34 ] . V_38 ) ;
F_78 ( V_78 , & V_1 -> V_14 . V_67 ) ;
F_74 ( & V_1 -> V_14 . V_15 ) ;
V_30:
if ( V_82 )
F_77 ( V_1 -> V_29 , V_81 ) ;
if ( F_39 ( V_43 ) )
F_45 ( V_72 ) ;
return V_28 ;
}
static int F_79 ( struct V_1 * V_1 , struct V_42 * V_43 , T_2 V_34 ,
int V_57 , int V_87 )
{
int V_28 ;
if ( V_87 == V_88 ) {
F_74 ( & V_1 -> V_14 . V_89 ) ;
V_28 = F_69 ( V_1 , V_43 , V_34 , V_57 ) ;
} else {
F_74 ( & V_1 -> V_14 . V_90 ) ;
V_28 = F_72 ( V_1 , V_43 , V_34 , V_57 ) ;
}
if ( F_41 ( V_28 ) ) {
if ( V_87 == V_88 )
F_74 ( & V_1 -> V_14 . V_91 ) ;
else
F_74 ( & V_1 -> V_14 . V_92 ) ;
}
return V_28 ;
}
static void F_80 ( struct V_1 * V_1 , T_2 V_34 ,
int V_57 , struct V_93 * V_93 )
{
T_3 V_94 = V_93 -> V_95 . V_96 ;
struct V_17 * V_2 = V_1 -> V_2 ;
if ( V_57 ) {
if ( V_94 <= ( V_9 - V_57 ) )
return;
V_94 -= ( V_9 - V_57 ) ;
V_34 ++ ;
}
while ( V_94 >= V_9 ) {
F_63 ( V_70 , & V_2 -> V_37 [ V_34 ] . V_38 ) ;
F_58 ( V_1 , V_34 ) ;
F_64 ( V_70 , & V_2 -> V_37 [ V_34 ] . V_38 ) ;
F_74 ( & V_1 -> V_14 . V_97 ) ;
V_34 ++ ;
V_94 -= V_9 ;
}
}
static void F_81 ( struct V_1 * V_1 , bool V_98 )
{
T_3 V_34 ;
struct V_17 * V_2 ;
F_17 ( & V_1 -> V_12 ) ;
V_1 -> V_20 = 0 ;
if ( ! F_1 ( V_1 ) ) {
F_19 ( & V_1 -> V_12 ) ;
return;
}
V_2 = V_1 -> V_2 ;
for ( V_34 = 0 ; V_34 < V_1 -> V_10 > > V_16 ; V_34 ++ ) {
unsigned long V_64 = V_2 -> V_37 [ V_34 ] . V_64 ;
if ( ! V_64 )
continue;
F_60 ( V_2 -> V_18 , V_64 ) ;
}
F_82 ( V_1 -> V_29 ) ;
V_1 -> V_19 = 1 ;
F_42 ( V_1 -> V_2 ) ;
V_1 -> V_2 = NULL ;
memset ( & V_1 -> V_14 , 0 , sizeof( V_1 -> V_14 ) ) ;
V_1 -> V_10 = 0 ;
if ( V_98 )
F_83 ( V_1 -> V_99 , 0 ) ;
F_19 ( & V_1 -> V_12 ) ;
if ( V_98 )
F_84 ( V_1 -> V_99 ) ;
}
static T_1 F_85 ( struct V_3 * V_4 ,
struct V_6 * V_7 , const char * V_8 , T_3 V_21 )
{
V_13 V_10 ;
struct V_100 * V_29 ;
struct V_17 * V_2 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
int V_26 ;
V_10 = F_16 ( V_8 , NULL ) ;
if ( ! V_10 )
return - V_24 ;
V_10 = F_18 ( V_10 ) ;
V_2 = F_46 ( V_10 ) ;
if ( ! V_2 )
return - V_73 ;
V_29 = F_86 ( V_1 -> V_32 , V_1 -> V_19 ) ;
if ( F_87 ( V_29 ) ) {
F_28 ( L_12 ,
V_1 -> V_32 ) ;
V_26 = F_88 ( V_29 ) ;
goto V_101;
}
F_17 ( & V_1 -> V_12 ) ;
if ( F_1 ( V_1 ) ) {
F_28 ( L_13 ) ;
V_26 = - V_33 ;
goto V_102;
}
V_1 -> V_2 = V_2 ;
V_1 -> V_29 = V_29 ;
V_1 -> V_10 = V_10 ;
F_83 ( V_1 -> V_99 , V_1 -> V_10 >> V_50 ) ;
F_19 ( & V_1 -> V_12 ) ;
F_84 ( V_1 -> V_99 ) ;
return V_21 ;
V_102:
F_19 ( & V_1 -> V_12 ) ;
F_82 ( V_29 ) ;
V_101:
F_42 ( V_2 ) ;
return V_26 ;
}
static T_1 F_89 ( struct V_3 * V_4 ,
struct V_6 * V_7 , const char * V_8 , T_3 V_21 )
{
int V_28 ;
unsigned short V_103 ;
struct V_1 * V_1 ;
struct V_104 * V_105 ;
V_1 = F_2 ( V_4 ) ;
V_105 = F_90 ( V_1 -> V_99 , 0 ) ;
if ( ! V_105 )
return - V_73 ;
if ( V_105 -> V_106 ) {
V_28 = - V_33 ;
goto V_30;
}
V_28 = F_91 ( V_8 , 10 , & V_103 ) ;
if ( V_28 )
goto V_30;
if ( ! V_103 ) {
V_28 = - V_24 ;
goto V_30;
}
F_92 ( V_105 ) ;
F_93 ( V_105 ) ;
F_81 ( V_1 , true ) ;
return V_21 ;
V_30:
F_93 ( V_105 ) ;
return V_28 ;
}
static void F_94 ( struct V_1 * V_1 , struct V_93 * V_93 )
{
int V_57 , V_87 ;
T_2 V_34 ;
struct V_42 V_43 ;
struct V_107 V_108 ;
V_34 = V_93 -> V_95 . V_109 >> V_110 ;
V_57 = ( V_93 -> V_95 . V_109 &
( V_111 - 1 ) ) << V_50 ;
if ( F_41 ( V_93 -> V_112 & V_113 ) ) {
F_80 ( V_1 , V_34 , V_57 , V_93 ) ;
F_95 ( V_93 , 0 ) ;
return;
}
V_87 = F_96 ( V_93 ) ;
F_97 (bvec, bio, iter) {
int V_114 = V_9 - V_57 ;
if ( V_43 . V_44 > V_114 ) {
struct V_42 V_115 ;
V_115 . V_61 = V_43 . V_61 ;
V_115 . V_44 = V_114 ;
V_115 . V_63 = V_43 . V_63 ;
if ( F_79 ( V_1 , & V_115 , V_34 , V_57 , V_87 ) < 0 )
goto V_30;
V_115 . V_44 = V_43 . V_44 - V_114 ;
V_115 . V_63 += V_114 ;
if ( F_79 ( V_1 , & V_115 , V_34 + 1 , 0 , V_87 ) < 0 )
goto V_30;
} else
if ( F_79 ( V_1 , & V_43 , V_34 , V_57 , V_87 ) < 0 )
goto V_30;
F_51 ( & V_34 , & V_57 , & V_43 ) ;
}
F_98 ( V_116 , & V_93 -> V_117 ) ;
F_95 ( V_93 , 0 ) ;
return;
V_30:
F_99 ( V_93 ) ;
}
static void F_100 ( struct V_118 * V_119 , struct V_93 * V_93 )
{
struct V_1 * V_1 = V_119 -> V_120 ;
F_7 ( & V_1 -> V_12 ) ;
if ( F_41 ( ! F_1 ( V_1 ) ) )
goto error;
if ( ! F_40 ( V_1 , V_93 -> V_95 . V_109 ,
V_93 -> V_95 . V_96 ) ) {
F_74 ( & V_1 -> V_14 . V_121 ) ;
goto error;
}
F_94 ( V_1 , V_93 ) ;
F_8 ( & V_1 -> V_12 ) ;
return;
error:
F_8 ( & V_1 -> V_12 ) ;
F_99 ( V_93 ) ;
}
static void F_101 ( struct V_104 * V_105 ,
unsigned long V_34 )
{
struct V_1 * V_1 ;
struct V_17 * V_2 ;
V_1 = V_105 -> V_122 -> V_5 ;
V_2 = V_1 -> V_2 ;
F_63 ( V_70 , & V_2 -> V_37 [ V_34 ] . V_38 ) ;
F_58 ( V_1 , V_34 ) ;
F_64 ( V_70 , & V_2 -> V_37 [ V_34 ] . V_38 ) ;
F_74 ( & V_1 -> V_14 . V_97 ) ;
}
static int F_102 ( struct V_104 * V_105 , T_4 V_123 ,
struct V_60 * V_60 , int V_87 )
{
int V_57 , V_26 ;
T_2 V_34 ;
struct V_1 * V_1 ;
struct V_42 V_115 ;
V_1 = V_105 -> V_122 -> V_5 ;
if ( ! F_40 ( V_1 , V_123 , V_9 ) ) {
F_74 ( & V_1 -> V_14 . V_121 ) ;
return - V_24 ;
}
F_7 ( & V_1 -> V_12 ) ;
if ( F_41 ( ! F_1 ( V_1 ) ) ) {
V_26 = - V_124 ;
goto V_125;
}
V_34 = V_123 >> V_110 ;
V_57 = V_123 & ( V_111 - 1 ) << V_50 ;
V_115 . V_61 = V_60 ;
V_115 . V_44 = V_9 ;
V_115 . V_63 = 0 ;
V_26 = F_79 ( V_1 , & V_115 , V_34 , V_57 , V_87 ) ;
V_125:
F_8 ( & V_1 -> V_12 ) ;
if ( V_26 == 0 )
F_103 ( V_60 , V_87 , 0 ) ;
return V_26 ;
}
static int F_104 ( struct V_1 * V_1 , int V_126 )
{
int V_28 = - V_73 ;
F_105 ( & V_1 -> V_12 ) ;
V_1 -> V_119 = F_106 ( V_52 ) ;
if ( ! V_1 -> V_119 ) {
F_49 ( L_14 ,
V_126 ) ;
goto V_30;
}
F_107 ( V_1 -> V_119 , F_100 ) ;
V_1 -> V_119 -> V_120 = V_1 ;
V_1 -> V_99 = F_108 ( 1 ) ;
if ( ! V_1 -> V_99 ) {
F_109 ( L_15 ,
V_126 ) ;
goto V_127;
}
V_1 -> V_99 -> V_128 = V_129 ;
V_1 -> V_99 -> V_130 = V_126 ;
V_1 -> V_99 -> V_131 = & V_132 ;
V_1 -> V_99 -> V_119 = V_1 -> V_119 ;
V_1 -> V_99 -> V_5 = V_1 ;
snprintf ( V_1 -> V_99 -> V_133 , 16 , L_16 , V_126 ) ;
F_83 ( V_1 -> V_99 , 0 ) ;
F_110 ( V_134 , V_1 -> V_99 -> V_119 ) ;
F_111 ( V_135 , V_1 -> V_99 -> V_119 ) ;
F_112 ( V_1 -> V_99 -> V_119 , V_9 ) ;
F_113 ( V_1 -> V_99 -> V_119 ,
V_49 ) ;
F_114 ( V_1 -> V_99 -> V_119 , V_9 ) ;
F_115 ( V_1 -> V_99 -> V_119 , V_9 ) ;
V_1 -> V_99 -> V_119 -> V_136 . V_137 = V_9 ;
V_1 -> V_99 -> V_119 -> V_136 . V_138 = V_139 ;
if ( V_49 == V_9 )
V_1 -> V_99 -> V_119 -> V_136 . V_140 = 1 ;
else
V_1 -> V_99 -> V_119 -> V_136 . V_140 = 0 ;
F_110 ( V_141 , V_1 -> V_99 -> V_119 ) ;
F_116 ( V_1 -> V_99 ) ;
V_28 = F_117 ( & F_118 ( V_1 -> V_99 ) -> V_142 ,
& V_143 ) ;
if ( V_28 < 0 ) {
F_109 ( L_17 ) ;
goto V_144;
}
F_32 ( V_1 -> V_32 , V_145 , sizeof( V_1 -> V_32 ) ) ;
V_1 -> V_2 = NULL ;
V_1 -> V_19 = 1 ;
return 0 ;
V_144:
F_119 ( V_1 -> V_99 ) ;
F_120 ( V_1 -> V_99 ) ;
V_127:
F_121 ( V_1 -> V_119 ) ;
V_30:
return V_28 ;
}
static void F_122 ( struct V_1 * V_1 )
{
F_123 ( & F_118 ( V_1 -> V_99 ) -> V_142 ,
& V_143 ) ;
F_119 ( V_1 -> V_99 ) ;
F_120 ( V_1 -> V_99 ) ;
F_121 ( V_1 -> V_119 ) ;
}
static int T_5 F_124 ( void )
{
int V_28 , V_146 ;
if ( V_147 > V_148 ) {
F_109 ( L_18 ,
V_147 ) ;
V_28 = - V_24 ;
goto V_30;
}
V_129 = F_125 ( 0 , L_19 ) ;
if ( V_129 <= 0 ) {
F_109 ( L_20 ) ;
V_28 = - V_33 ;
goto V_30;
}
V_149 = F_126 ( V_147 * sizeof( struct V_1 ) , V_52 ) ;
if ( ! V_149 ) {
V_28 = - V_73 ;
goto V_150;
}
for ( V_146 = 0 ; V_146 < V_147 ; V_146 ++ ) {
V_28 = F_104 ( & V_149 [ V_146 ] , V_146 ) ;
if ( V_28 )
goto V_151;
}
F_28 ( L_21 , V_147 ) ;
return 0 ;
V_151:
while ( V_146 )
F_122 ( & V_149 [ -- V_146 ] ) ;
F_45 ( V_149 ) ;
V_150:
F_127 ( V_129 , L_19 ) ;
V_30:
return V_28 ;
}
static void T_6 F_128 ( void )
{
int V_152 ;
struct V_1 * V_1 ;
for ( V_152 = 0 ; V_152 < V_147 ; V_152 ++ ) {
V_1 = & V_149 [ V_152 ] ;
F_122 ( V_1 ) ;
F_81 ( V_1 , false ) ;
}
F_127 ( V_129 , L_19 ) ;
F_45 ( V_149 ) ;
F_129 ( L_22 ) ;
}
