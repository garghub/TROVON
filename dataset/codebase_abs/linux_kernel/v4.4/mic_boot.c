static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 . V_5 ) ;
}
static void * F_3 ( struct V_6 * V_4 , T_1 V_7 ,
T_2 * V_8 , T_3 V_9 ,
struct V_10 * V_11 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
T_2 V_13 ;
void * V_14 = F_4 ( V_7 , V_9 ) ;
if ( V_14 ) {
V_13 = F_5 ( V_12 , V_14 , V_7 ) ;
if ( F_6 ( V_4 , V_13 ) ) {
F_7 ( V_14 ) ;
V_14 = NULL ;
} else {
* V_8 = V_13 ;
}
}
return V_14 ;
}
static void F_8 ( struct V_6 * V_4 , T_1 V_7 , void * V_15 ,
T_2 V_8 , struct V_10 * V_11 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
F_9 ( V_12 , V_8 , V_7 ) ;
F_7 ( V_15 ) ;
}
static T_2
F_10 ( struct V_6 * V_4 , struct V_16 * V_16 , unsigned long V_17 ,
T_1 V_7 , enum V_18 V_19 ,
struct V_10 * V_11 )
{
void * V_14 = F_11 ( F_12 ( V_16 ) ) + V_17 ;
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
return F_5 ( V_12 , V_14 , V_7 ) ;
}
static void
F_13 ( struct V_6 * V_4 , T_2 V_20 ,
T_1 V_7 , enum V_18 V_19 ,
struct V_10 * V_11 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
F_9 ( V_12 , V_20 , V_7 ) ;
}
static int F_14 ( struct V_6 * V_4 , struct V_21 * V_22 ,
int V_23 , enum V_18 V_19 ,
struct V_10 * V_11 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_21 * V_24 ;
int V_25 , V_26 , V_27 ;
T_2 V_28 ;
V_27 = F_15 ( & V_12 -> V_29 -> V_4 , V_22 , V_23 , V_19 ) ;
if ( V_27 <= 0 )
return 0 ;
F_16 (sg, s, nents, i) {
V_28 = F_17 ( V_12 , F_18 ( V_24 ) + V_24 -> V_17 , V_24 -> V_30 ) ;
if ( ! V_28 )
goto V_31;
F_18 ( V_24 ) = V_28 ;
}
return V_23 ;
V_31:
F_16 (sg, s, i, j) {
F_19 ( V_12 , F_18 ( V_24 ) , V_24 -> V_30 ) ;
F_18 ( V_24 ) = F_20 ( V_12 , F_18 ( V_24 ) ) ;
}
F_21 ( & V_12 -> V_29 -> V_4 , V_22 , V_23 , V_19 ) ;
return 0 ;
}
static void F_22 ( struct V_6 * V_4 ,
struct V_21 * V_22 , int V_23 ,
enum V_18 V_19 ,
struct V_10 * V_11 )
{
struct V_2 * V_3 = F_2 ( V_4 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_21 * V_24 ;
T_2 V_28 ;
int V_25 ;
F_16 (sg, s, nents, i) {
V_28 = F_20 ( V_12 , F_18 ( V_24 ) ) ;
F_19 ( V_12 , F_18 ( V_24 ) , V_24 -> V_30 ) ;
F_18 ( V_24 ) = V_28 ;
}
F_21 ( & V_12 -> V_29 -> V_4 , V_22 , V_23 , V_19 ) ;
}
static struct V_32 *
F_23 ( struct V_2 * V_3 ,
T_4 (* F_24)( int V_33 , void * V_34 ) ,
const char * V_35 ,
void * V_34 , int V_36 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
return F_25 ( V_12 , F_24 , NULL , V_35 , V_34 ,
V_36 , V_37 ) ;
}
static void
F_26 ( struct V_2 * V_3 ,
struct V_32 * V_38 , void * V_34 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
return F_27 ( V_12 , V_38 , V_34 ) ;
}
static void F_28 ( struct V_2 * V_3 , int V_39 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
V_12 -> V_40 -> V_41 ( V_12 ) ;
}
static int F_29 ( struct V_2 * V_3 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
return F_30 ( V_12 ) ;
}
static void F_31 ( struct V_2 * V_3 , int V_36 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
V_12 -> V_40 -> V_42 ( V_12 , V_36 ) ;
}
static void T_5 * F_32 ( struct V_2 * V_3 ,
T_6 V_43 , T_1 V_44 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
return V_12 -> V_45 . V_14 + V_43 ;
}
static void F_33 ( struct V_2 * V_3 , void T_5 * V_14 )
{
}
static inline struct V_1 * F_34 ( struct V_46 * V_47 )
{
return F_2 ( V_47 -> V_4 . V_5 ) ;
}
static T_2
F_35 ( struct V_6 * V_4 , struct V_16 * V_16 ,
unsigned long V_17 , T_1 V_7 , enum V_18 V_19 ,
struct V_10 * V_11 )
{
void * V_14 = F_11 ( F_12 ( V_16 ) ) + V_17 ;
struct V_1 * V_12 = F_2 ( V_4 -> V_5 ) ;
return F_5 ( V_12 , V_14 , V_7 ) ;
}
static void
F_36 ( struct V_6 * V_4 , T_2 V_20 ,
T_1 V_7 , enum V_18 V_19 ,
struct V_10 * V_11 )
{
struct V_1 * V_12 = F_2 ( V_4 -> V_5 ) ;
F_9 ( V_12 , V_20 , V_7 ) ;
}
static struct V_32 *
F_37 ( struct V_46 * V_47 ,
T_7 V_48 , T_7 V_49 ,
const char * V_35 , void * V_34 , int V_50 )
{
return F_25 ( F_34 ( V_47 ) , V_48 ,
V_49 , V_35 , V_34 ,
V_50 , V_51 ) ;
}
static void F_38 ( struct V_46 * V_47 ,
struct V_32 * V_38 , void * V_34 )
{
return F_27 ( F_34 ( V_47 ) , V_38 , V_34 ) ;
}
static void F_39 ( struct V_46 * V_47 , int V_39 )
{
struct V_1 * V_12 = F_34 ( V_47 ) ;
V_12 -> V_40 -> V_41 ( V_12 ) ;
}
void F_40 ( struct V_1 * V_12 )
{
struct V_52 * V_53 = V_12 -> V_54 ;
V_53 -> V_55 = F_41 ( V_56 ) ;
V_53 -> V_57 = - 1 ;
V_53 -> V_58 = V_12 -> V_59 + 1 ;
V_53 -> V_60 = 0x0 ;
V_53 -> V_61 = 0x0 ;
V_53 -> V_62 = - 1 ;
V_53 -> V_63 = - 1 ;
}
static inline struct V_1 * F_42 ( struct V_64 * V_65 )
{
return F_2 ( V_65 -> V_4 . V_5 ) ;
}
static void F_43 ( struct V_64 * V_65 )
{
struct V_1 * V_12 = F_42 ( V_65 ) ;
V_12 -> V_40 -> V_66 ( V_12 ) ;
V_12 -> V_40 -> V_67 ( V_12 ) ;
}
static bool F_44 ( struct V_64 * V_65 )
{
struct V_1 * V_12 = F_42 ( V_65 ) ;
return V_12 -> V_40 -> V_68 ( V_12 ) ;
}
static int F_45 ( struct V_1 * V_12 )
{
T_8 V_69 ;
struct V_70 * V_71 ;
F_46 ( L_1 ) ;
F_47 ( V_69 ) ;
F_48 ( V_72 , V_69 ) ;
do {
V_71 = F_49 ( V_69 , V_12 -> V_40 -> V_73 ,
& V_12 -> V_29 -> V_4 ) ;
if ( V_71 ) {
V_12 -> V_74 [ V_12 -> V_75 ++ ] = V_71 ;
if ( V_12 -> V_75 >= V_76 )
break;
}
} while ( V_71 );
F_50 ( & V_12 -> V_29 -> V_4 , L_2 , V_12 -> V_75 ) ;
return V_12 -> V_75 ;
}
static void F_51 ( struct V_1 * V_12 )
{
int V_25 = 0 ;
for ( V_25 = 0 ; V_25 < V_12 -> V_75 ; V_25 ++ ) {
F_52 ( V_12 -> V_74 [ V_25 ] ) ;
V_12 -> V_74 [ V_25 ] = NULL ;
}
V_12 -> V_75 = 0 ;
}
static int F_53 ( struct V_64 * V_65 , int V_59 )
{
struct V_1 * V_12 = F_42 ( V_65 ) ;
int V_77 ;
F_40 ( V_12 ) ;
V_12 -> V_78 = F_54 ( & V_12 -> V_29 -> V_4 ,
V_79 , & V_80 ,
& V_81 , V_59 , V_12 -> V_82 . V_14 ) ;
if ( F_55 ( V_12 -> V_78 ) ) {
V_77 = F_56 ( V_12 -> V_78 ) ;
goto V_83;
}
if ( ! F_45 ( V_12 ) ) {
V_77 = - V_84 ;
goto V_85;
}
V_12 -> V_3 = F_57 ( & V_12 -> V_29 -> V_4 , V_86 ,
& V_87 , & V_88 ,
V_59 + 1 , 0 , & V_12 -> V_82 ,
& V_12 -> V_45 , V_12 -> V_54 , NULL ,
V_12 -> V_74 , V_12 -> V_75 ,
true ) ;
if ( F_55 ( V_12 -> V_3 ) ) {
V_77 = F_56 ( V_12 -> V_3 ) ;
goto V_89;
}
V_77 = V_12 -> V_40 -> V_90 ( V_12 , NULL ) ;
if ( V_77 )
goto V_91;
F_58 ( V_12 ) ;
F_59 ( V_12 ) ;
V_12 -> V_92 -> V_93 ( V_12 ) ;
V_12 -> V_40 -> V_94 ( V_12 , V_95 , V_12 -> V_96 ) ;
V_12 -> V_40 -> V_94 ( V_12 , V_97 , V_12 -> V_96 >> 32 ) ;
V_12 -> V_40 -> V_98 ( V_12 ) ;
goto V_83;
V_91:
F_60 ( V_12 -> V_3 ) ;
V_89:
F_51 ( V_12 ) ;
V_85:
F_61 ( V_12 -> V_78 ) ;
V_83:
return V_77 ;
}
static void F_62 ( struct V_64 * V_65 , bool V_99 )
{
struct V_1 * V_12 = F_42 ( V_65 ) ;
F_63 ( V_12 ) ;
F_60 ( V_12 -> V_3 ) ;
F_51 ( V_12 ) ;
F_61 ( V_12 -> V_78 ) ;
F_40 ( V_12 ) ;
}
static T_9 F_64 ( struct V_64 * V_65 , char * V_100 )
{
struct V_1 * V_12 = F_42 ( V_65 ) ;
static const char * V_101 [ V_102 ] = { L_3 , L_4 } ;
return F_65 ( V_100 , V_103 , L_5 , V_101 [ V_12 -> V_101 ] ) ;
}
static T_9 F_66 ( struct V_64 * V_65 , char * V_100 )
{
struct V_1 * V_12 = F_42 ( V_65 ) ;
const char * string = L_6 ;
switch ( V_12 -> V_104 ) {
case V_105 :
string = L_7 ;
break;
case V_106 :
string = L_8 ;
break;
case V_107 :
string = L_9 ;
break;
case V_108 :
string = L_10 ;
break;
default:
break;
}
return F_65 ( V_100 , V_103 , L_5 , string ) ;
}
static struct V_109 * F_67 ( struct V_64 * V_65 )
{
struct V_1 * V_12 = F_42 ( V_65 ) ;
return & V_12 -> V_45 ;
}
