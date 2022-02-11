static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 ) ;
}
static T_1
F_3 ( struct V_2 * V_3 , struct V_5 * V_5 ,
unsigned long V_6 , T_2 V_7 ,
enum V_8 V_9 , unsigned long V_10 )
{
void * V_11 = F_4 ( F_5 ( V_5 ) ) + V_6 ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
return F_6 ( V_12 , V_11 , V_7 ) ;
}
static void F_7 ( struct V_2 * V_3 , T_1 V_13 ,
T_2 V_7 , enum V_8 V_9 ,
unsigned long V_10 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
F_8 ( V_12 , V_13 , V_7 ) ;
}
static struct V_14 *
F_9 ( struct V_15 * V_16 ,
T_3 (* F_10)( int V_17 , void * V_18 ) ,
const char * V_19 , void * V_18 , int V_20 )
{
struct V_1 * V_12 = F_1 ( & V_16 -> V_3 ) ;
return F_11 ( V_12 , F_10 , NULL , V_19 , V_18 ,
V_20 , V_21 ) ;
}
static void F_12 ( struct V_15 * V_16 ,
struct V_14 * V_22 , void * V_18 )
{
struct V_1 * V_12 = F_1 ( & V_16 -> V_3 ) ;
F_13 ( V_12 , V_22 , V_18 ) ;
}
static void F_14 ( struct V_15 * V_16 , int V_23 )
{
struct V_1 * V_12 = F_1 ( & V_16 -> V_3 ) ;
V_12 -> V_24 -> V_25 ( V_12 ) ;
}
static int F_15 ( struct V_15 * V_16 )
{
struct V_1 * V_12 = F_1 ( & V_16 -> V_3 ) ;
return F_16 ( V_12 ) ;
}
static void * F_17 ( struct V_15 * V_16 )
{
struct V_1 * V_12 = F_1 ( & V_16 -> V_3 ) ;
return V_12 -> V_26 ;
}
static void T_4 * F_18 ( struct V_15 * V_16 )
{
return NULL ;
}
static void F_19 ( struct V_15 * V_16 , int V_27 )
{
struct V_1 * V_12 = F_1 ( & V_16 -> V_3 ) ;
V_12 -> V_24 -> V_28 ( V_12 , V_27 ) ;
}
static void T_4 * F_20 ( struct V_15 * V_16 ,
T_1 V_29 , T_2 V_30 )
{
struct V_1 * V_12 = F_1 ( & V_16 -> V_3 ) ;
return V_12 -> V_31 . V_11 + V_29 ;
}
static void F_21 ( struct V_15 * V_16 , void T_4 * V_11 )
{
}
static inline struct V_1 * F_22 ( struct V_32 * V_33 )
{
return F_2 ( V_33 -> V_3 . V_4 ) ;
}
static void * F_23 ( struct V_2 * V_3 , T_2 V_7 ,
T_1 * V_34 , T_5 V_35 ,
unsigned long V_10 )
{
struct V_32 * V_33 = F_2 ( V_3 ) ;
struct V_1 * V_12 = F_22 ( V_33 ) ;
T_1 V_36 ;
void * V_11 = F_24 ( V_7 , V_35 ) ;
if ( V_11 ) {
V_36 = F_6 ( V_12 , V_11 , V_7 ) ;
if ( F_25 ( V_3 , V_36 ) ) {
F_26 ( V_11 ) ;
V_11 = NULL ;
} else {
* V_34 = V_36 ;
}
}
return V_11 ;
}
static void F_27 ( struct V_2 * V_3 , T_2 V_7 , void * V_37 ,
T_1 V_34 , unsigned long V_10 )
{
struct V_32 * V_33 = F_2 ( V_3 ) ;
struct V_1 * V_12 = F_22 ( V_33 ) ;
F_8 ( V_12 , V_34 , V_7 ) ;
F_26 ( V_37 ) ;
}
static T_1
F_28 ( struct V_2 * V_3 , struct V_5 * V_5 , unsigned long V_6 ,
T_2 V_7 , enum V_8 V_9 ,
unsigned long V_10 )
{
void * V_11 = F_4 ( F_5 ( V_5 ) ) + V_6 ;
struct V_32 * V_33 = F_2 ( V_3 ) ;
struct V_1 * V_12 = F_22 ( V_33 ) ;
return F_6 ( V_12 , V_11 , V_7 ) ;
}
static void
F_29 ( struct V_2 * V_3 , T_1 V_13 ,
T_2 V_7 , enum V_8 V_9 ,
unsigned long V_10 )
{
struct V_32 * V_33 = F_2 ( V_3 ) ;
struct V_1 * V_12 = F_22 ( V_33 ) ;
F_8 ( V_12 , V_13 , V_7 ) ;
}
static int F_30 ( struct V_2 * V_3 , struct V_38 * V_39 ,
int V_40 , enum V_8 V_9 ,
unsigned long V_10 )
{
struct V_32 * V_33 = F_2 ( V_3 ) ;
struct V_1 * V_12 = F_22 ( V_33 ) ;
struct V_38 * V_41 ;
int V_42 , V_43 , V_44 ;
T_1 V_45 ;
V_44 = F_31 ( & V_12 -> V_46 -> V_3 , V_39 , V_40 , V_9 ) ;
if ( V_44 <= 0 )
return 0 ;
F_32 (sg, s, nents, i) {
V_45 = F_33 ( V_12 , F_34 ( V_41 ) + V_41 -> V_6 , V_41 -> V_47 ) ;
if ( ! V_45 )
goto V_48;
F_34 ( V_41 ) = V_45 ;
}
return V_40 ;
V_48:
F_32 (sg, s, i, j) {
F_35 ( V_12 , F_34 ( V_41 ) , V_41 -> V_47 ) ;
F_34 ( V_41 ) = F_36 ( V_12 , F_34 ( V_41 ) ) ;
}
F_37 ( & V_12 -> V_46 -> V_3 , V_39 , V_40 , V_9 ) ;
return 0 ;
}
static void F_38 ( struct V_2 * V_3 ,
struct V_38 * V_39 , int V_40 ,
enum V_8 V_9 ,
unsigned long V_10 )
{
struct V_32 * V_33 = F_2 ( V_3 ) ;
struct V_1 * V_12 = F_22 ( V_33 ) ;
struct V_38 * V_41 ;
T_1 V_45 ;
int V_42 ;
F_32 (sg, s, nents, i) {
V_45 = F_36 ( V_12 , F_34 ( V_41 ) ) ;
F_35 ( V_12 , F_34 ( V_41 ) , V_41 -> V_47 ) ;
F_34 ( V_41 ) = V_45 ;
}
F_37 ( & V_12 -> V_46 -> V_3 , V_39 , V_40 , V_9 ) ;
}
static struct V_14 *
F_39 ( struct V_32 * V_33 ,
T_3 (* F_10)( int V_17 , void * V_18 ) ,
const char * V_19 ,
void * V_18 , int V_27 )
{
struct V_1 * V_12 = F_22 ( V_33 ) ;
return F_11 ( V_12 , F_10 , NULL , V_19 , V_18 ,
V_27 , V_21 ) ;
}
static void
F_40 ( struct V_32 * V_33 ,
struct V_14 * V_22 , void * V_18 )
{
struct V_1 * V_12 = F_22 ( V_33 ) ;
F_13 ( V_12 , V_22 , V_18 ) ;
}
static void F_41 ( struct V_32 * V_33 , int V_23 )
{
struct V_1 * V_12 = F_22 ( V_33 ) ;
V_12 -> V_24 -> V_25 ( V_12 ) ;
}
static int F_42 ( struct V_32 * V_33 )
{
struct V_1 * V_12 = F_22 ( V_33 ) ;
return F_16 ( V_12 ) ;
}
static void F_43 ( struct V_32 * V_33 , int V_27 )
{
struct V_1 * V_12 = F_22 ( V_33 ) ;
V_12 -> V_24 -> V_28 ( V_12 , V_27 ) ;
}
static void T_4 * F_44 ( struct V_32 * V_33 ,
T_6 V_29 , T_2 V_30 )
{
struct V_1 * V_12 = F_22 ( V_33 ) ;
return V_12 -> V_31 . V_11 + V_29 ;
}
static void F_45 ( struct V_32 * V_33 , void T_4 * V_11 )
{
}
static inline struct V_1 * F_46 ( struct V_49 * V_50 )
{
return F_2 ( V_50 -> V_3 . V_4 ) ;
}
static T_1
F_47 ( struct V_2 * V_3 , struct V_5 * V_5 ,
unsigned long V_6 , T_2 V_7 , enum V_8 V_9 ,
unsigned long V_10 )
{
void * V_11 = F_4 ( F_5 ( V_5 ) ) + V_6 ;
struct V_1 * V_12 = F_2 ( V_3 -> V_4 ) ;
return F_6 ( V_12 , V_11 , V_7 ) ;
}
static void
F_48 ( struct V_2 * V_3 , T_1 V_13 ,
T_2 V_7 , enum V_8 V_9 ,
unsigned long V_10 )
{
struct V_1 * V_12 = F_2 ( V_3 -> V_4 ) ;
F_8 ( V_12 , V_13 , V_7 ) ;
}
static struct V_14 *
F_49 ( struct V_49 * V_50 ,
T_7 V_51 , T_7 V_52 ,
const char * V_19 , void * V_18 , int V_20 )
{
return F_11 ( F_46 ( V_50 ) , V_51 ,
V_52 , V_19 , V_18 ,
V_20 , V_53 ) ;
}
static void F_50 ( struct V_49 * V_50 ,
struct V_14 * V_22 , void * V_18 )
{
F_13 ( F_46 ( V_50 ) , V_22 , V_18 ) ;
}
static void F_51 ( struct V_49 * V_50 , int V_23 )
{
struct V_1 * V_12 = F_46 ( V_50 ) ;
V_12 -> V_24 -> V_25 ( V_12 ) ;
}
void F_52 ( struct V_1 * V_12 )
{
struct V_54 * V_55 = V_12 -> V_26 ;
V_55 -> V_56 = F_53 ( V_57 ) ;
V_55 -> V_58 = - 1 ;
V_55 -> V_59 = V_12 -> V_60 + 1 ;
V_55 -> V_61 = 0x0 ;
V_55 -> V_62 = 0x0 ;
V_55 -> V_63 = - 1 ;
V_55 -> V_64 = - 1 ;
}
static inline struct V_1 * F_54 ( struct V_65 * V_66 )
{
return F_2 ( V_66 -> V_3 . V_4 ) ;
}
static void F_55 ( struct V_65 * V_66 )
{
struct V_1 * V_12 = F_54 ( V_66 ) ;
V_12 -> V_24 -> V_67 ( V_12 ) ;
V_12 -> V_24 -> V_68 ( V_12 ) ;
}
static bool F_56 ( struct V_65 * V_66 )
{
struct V_1 * V_12 = F_54 ( V_66 ) ;
return V_12 -> V_24 -> V_69 ( V_12 ) ;
}
static int F_57 ( struct V_1 * V_12 )
{
T_8 V_70 ;
struct V_71 * V_72 ;
F_58 ( V_70 ) ;
F_59 ( V_73 , V_70 ) ;
do {
V_72 = F_60 ( V_70 , V_12 -> V_24 -> V_74 ,
& V_12 -> V_46 -> V_3 ) ;
if ( V_72 ) {
V_12 -> V_75 [ V_12 -> V_76 ++ ] = V_72 ;
if ( V_12 -> V_76 >= V_77 )
break;
}
} while ( V_72 );
F_61 ( & V_12 -> V_46 -> V_3 , L_1 , V_12 -> V_76 ) ;
return V_12 -> V_76 ;
}
static void F_62 ( struct V_1 * V_12 )
{
int V_42 = 0 ;
for ( V_42 = 0 ; V_42 < V_12 -> V_76 ; V_42 ++ ) {
F_63 ( V_12 -> V_75 [ V_42 ] ) ;
V_12 -> V_75 [ V_42 ] = NULL ;
}
V_12 -> V_76 = 0 ;
}
static int F_64 ( struct V_65 * V_66 , int V_60 )
{
struct V_1 * V_12 = F_54 ( V_66 ) ;
int V_78 ;
F_52 ( V_12 ) ;
V_12 -> V_79 = F_65 ( & V_12 -> V_46 -> V_3 ,
V_80 , & V_81 ,
& V_82 , V_60 , V_12 -> V_83 . V_11 ) ;
if ( F_66 ( V_12 -> V_79 ) ) {
V_78 = F_67 ( V_12 -> V_79 ) ;
goto V_84;
}
if ( ! F_57 ( V_12 ) ) {
V_78 = - V_85 ;
goto V_86;
}
V_12 -> V_33 = F_68 ( & V_12 -> V_46 -> V_3 , V_87 ,
& V_88 , & V_89 ,
V_60 + 1 , 0 , & V_12 -> V_83 ,
& V_12 -> V_31 , V_12 -> V_26 , NULL ,
V_12 -> V_75 , V_12 -> V_76 ,
true ) ;
if ( F_66 ( V_12 -> V_33 ) ) {
V_78 = F_67 ( V_12 -> V_33 ) ;
goto V_90;
}
V_12 -> V_16 = F_69 ( & V_12 -> V_46 -> V_3 ,
V_91 , & V_92 ,
& V_93 , V_60 + 1 , & V_12 -> V_31 ,
V_12 -> V_75 [ 0 ] ) ;
if ( F_66 ( V_12 -> V_16 ) ) {
V_78 = F_67 ( V_12 -> V_16 ) ;
goto V_94;
}
V_78 = V_12 -> V_24 -> V_95 ( V_12 , NULL ) ;
if ( V_78 )
goto V_96;
F_70 ( V_12 ) ;
F_71 ( V_12 ) ;
V_12 -> V_97 -> V_98 ( V_12 ) ;
V_12 -> V_24 -> V_99 ( V_12 , V_100 , V_12 -> V_101 ) ;
V_12 -> V_24 -> V_99 ( V_12 , V_102 , V_12 -> V_101 >> 32 ) ;
V_12 -> V_24 -> V_103 ( V_12 ) ;
goto V_84;
V_96:
F_72 ( V_12 -> V_16 ) ;
V_94:
F_73 ( V_12 -> V_33 ) ;
V_90:
F_62 ( V_12 ) ;
V_86:
F_74 ( V_12 -> V_79 ) ;
V_84:
return V_78 ;
}
static void F_75 ( struct V_65 * V_66 , bool V_104 )
{
struct V_1 * V_12 = F_54 ( V_66 ) ;
F_72 ( V_12 -> V_16 ) ;
F_73 ( V_12 -> V_33 ) ;
F_62 ( V_12 ) ;
F_74 ( V_12 -> V_79 ) ;
F_52 ( V_12 ) ;
}
static T_9 F_76 ( struct V_65 * V_66 , char * V_105 )
{
struct V_1 * V_12 = F_54 ( V_66 ) ;
static const char * V_106 [ V_107 ] = { L_2 , L_3 } ;
return F_77 ( V_105 , V_108 , L_4 , V_106 [ V_12 -> V_106 ] ) ;
}
static T_9 F_78 ( struct V_65 * V_66 , char * V_105 )
{
struct V_1 * V_12 = F_54 ( V_66 ) ;
const char * string = L_5 ;
switch ( V_12 -> V_109 ) {
case V_110 :
string = L_6 ;
break;
case V_111 :
string = L_7 ;
break;
case V_112 :
string = L_8 ;
break;
case V_113 :
string = L_9 ;
break;
default:
break;
}
return F_77 ( V_105 , V_108 , L_4 , string ) ;
}
static struct V_114 * F_79 ( struct V_65 * V_66 )
{
struct V_1 * V_12 = F_54 ( V_66 ) ;
return & V_12 -> V_31 ;
}
