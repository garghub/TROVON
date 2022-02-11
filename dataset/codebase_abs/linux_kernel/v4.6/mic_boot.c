static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 ) ;
}
static T_1
F_3 ( struct V_2 * V_3 , struct V_5 * V_5 ,
unsigned long V_6 , T_2 V_7 ,
enum V_8 V_9 , struct V_10 * V_11 )
{
void * V_12 = F_4 ( F_5 ( V_5 ) ) + V_6 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
return F_6 ( V_13 , V_12 , V_7 ) ;
}
static void F_7 ( struct V_2 * V_3 , T_1 V_14 ,
T_2 V_7 , enum V_8 V_9 ,
struct V_10 * V_11 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
F_8 ( V_13 , V_14 , V_7 ) ;
}
static struct V_15 *
F_9 ( struct V_16 * V_17 ,
T_3 (* F_10)( int V_18 , void * V_19 ) ,
const char * V_20 , void * V_19 , int V_21 )
{
struct V_1 * V_13 = F_1 ( & V_17 -> V_3 ) ;
return F_11 ( V_13 , F_10 , NULL , V_20 , V_19 ,
V_21 , V_22 ) ;
}
static void F_12 ( struct V_16 * V_17 ,
struct V_15 * V_23 , void * V_19 )
{
struct V_1 * V_13 = F_1 ( & V_17 -> V_3 ) ;
return F_13 ( V_13 , V_23 , V_19 ) ;
}
static void F_14 ( struct V_16 * V_17 , int V_24 )
{
struct V_1 * V_13 = F_1 ( & V_17 -> V_3 ) ;
V_13 -> V_25 -> V_26 ( V_13 ) ;
}
static int F_15 ( struct V_16 * V_17 )
{
struct V_1 * V_13 = F_1 ( & V_17 -> V_3 ) ;
return F_16 ( V_13 ) ;
}
static void * F_17 ( struct V_16 * V_17 )
{
struct V_1 * V_13 = F_1 ( & V_17 -> V_3 ) ;
return V_13 -> V_27 ;
}
static void T_4 * F_18 ( struct V_16 * V_17 )
{
return NULL ;
}
static void F_19 ( struct V_16 * V_17 , int V_28 )
{
struct V_1 * V_13 = F_1 ( & V_17 -> V_3 ) ;
V_13 -> V_25 -> V_29 ( V_13 , V_28 ) ;
}
static void T_4 * F_20 ( struct V_16 * V_17 ,
T_1 V_30 , T_2 V_31 )
{
struct V_1 * V_13 = F_1 ( & V_17 -> V_3 ) ;
return V_13 -> V_32 . V_12 + V_30 ;
}
static void F_21 ( struct V_16 * V_17 , void T_4 * V_12 )
{
}
static inline struct V_1 * F_22 ( struct V_33 * V_34 )
{
return F_2 ( V_34 -> V_3 . V_4 ) ;
}
static void * F_23 ( struct V_2 * V_3 , T_2 V_7 ,
T_1 * V_35 , T_5 V_36 ,
struct V_10 * V_11 )
{
struct V_33 * V_34 = F_2 ( V_3 ) ;
struct V_1 * V_13 = F_22 ( V_34 ) ;
T_1 V_37 ;
void * V_12 = F_24 ( V_7 , V_36 ) ;
if ( V_12 ) {
V_37 = F_6 ( V_13 , V_12 , V_7 ) ;
if ( F_25 ( V_3 , V_37 ) ) {
F_26 ( V_12 ) ;
V_12 = NULL ;
} else {
* V_35 = V_37 ;
}
}
return V_12 ;
}
static void F_27 ( struct V_2 * V_3 , T_2 V_7 , void * V_38 ,
T_1 V_35 , struct V_10 * V_11 )
{
struct V_33 * V_34 = F_2 ( V_3 ) ;
struct V_1 * V_13 = F_22 ( V_34 ) ;
F_8 ( V_13 , V_35 , V_7 ) ;
F_26 ( V_38 ) ;
}
static T_1
F_28 ( struct V_2 * V_3 , struct V_5 * V_5 , unsigned long V_6 ,
T_2 V_7 , enum V_8 V_9 ,
struct V_10 * V_11 )
{
void * V_12 = F_4 ( F_5 ( V_5 ) ) + V_6 ;
struct V_33 * V_34 = F_2 ( V_3 ) ;
struct V_1 * V_13 = F_22 ( V_34 ) ;
return F_6 ( V_13 , V_12 , V_7 ) ;
}
static void
F_29 ( struct V_2 * V_3 , T_1 V_14 ,
T_2 V_7 , enum V_8 V_9 ,
struct V_10 * V_11 )
{
struct V_33 * V_34 = F_2 ( V_3 ) ;
struct V_1 * V_13 = F_22 ( V_34 ) ;
F_8 ( V_13 , V_14 , V_7 ) ;
}
static int F_30 ( struct V_2 * V_3 , struct V_39 * V_40 ,
int V_41 , enum V_8 V_9 ,
struct V_10 * V_11 )
{
struct V_33 * V_34 = F_2 ( V_3 ) ;
struct V_1 * V_13 = F_22 ( V_34 ) ;
struct V_39 * V_42 ;
int V_43 , V_44 , V_45 ;
T_1 V_46 ;
V_45 = F_31 ( & V_13 -> V_47 -> V_3 , V_40 , V_41 , V_9 ) ;
if ( V_45 <= 0 )
return 0 ;
F_32 (sg, s, nents, i) {
V_46 = F_33 ( V_13 , F_34 ( V_42 ) + V_42 -> V_6 , V_42 -> V_48 ) ;
if ( ! V_46 )
goto V_49;
F_34 ( V_42 ) = V_46 ;
}
return V_41 ;
V_49:
F_32 (sg, s, i, j) {
F_35 ( V_13 , F_34 ( V_42 ) , V_42 -> V_48 ) ;
F_34 ( V_42 ) = F_36 ( V_13 , F_34 ( V_42 ) ) ;
}
F_37 ( & V_13 -> V_47 -> V_3 , V_40 , V_41 , V_9 ) ;
return 0 ;
}
static void F_38 ( struct V_2 * V_3 ,
struct V_39 * V_40 , int V_41 ,
enum V_8 V_9 ,
struct V_10 * V_11 )
{
struct V_33 * V_34 = F_2 ( V_3 ) ;
struct V_1 * V_13 = F_22 ( V_34 ) ;
struct V_39 * V_42 ;
T_1 V_46 ;
int V_43 ;
F_32 (sg, s, nents, i) {
V_46 = F_36 ( V_13 , F_34 ( V_42 ) ) ;
F_35 ( V_13 , F_34 ( V_42 ) , V_42 -> V_48 ) ;
F_34 ( V_42 ) = V_46 ;
}
F_37 ( & V_13 -> V_47 -> V_3 , V_40 , V_41 , V_9 ) ;
}
static struct V_15 *
F_39 ( struct V_33 * V_34 ,
T_3 (* F_10)( int V_18 , void * V_19 ) ,
const char * V_20 ,
void * V_19 , int V_28 )
{
struct V_1 * V_13 = F_22 ( V_34 ) ;
return F_11 ( V_13 , F_10 , NULL , V_20 , V_19 ,
V_28 , V_22 ) ;
}
static void
F_40 ( struct V_33 * V_34 ,
struct V_15 * V_23 , void * V_19 )
{
struct V_1 * V_13 = F_22 ( V_34 ) ;
return F_13 ( V_13 , V_23 , V_19 ) ;
}
static void F_41 ( struct V_33 * V_34 , int V_24 )
{
struct V_1 * V_13 = F_22 ( V_34 ) ;
V_13 -> V_25 -> V_26 ( V_13 ) ;
}
static int F_42 ( struct V_33 * V_34 )
{
struct V_1 * V_13 = F_22 ( V_34 ) ;
return F_16 ( V_13 ) ;
}
static void F_43 ( struct V_33 * V_34 , int V_28 )
{
struct V_1 * V_13 = F_22 ( V_34 ) ;
V_13 -> V_25 -> V_29 ( V_13 , V_28 ) ;
}
static void T_4 * F_44 ( struct V_33 * V_34 ,
T_6 V_30 , T_2 V_31 )
{
struct V_1 * V_13 = F_22 ( V_34 ) ;
return V_13 -> V_32 . V_12 + V_30 ;
}
static void F_45 ( struct V_33 * V_34 , void T_4 * V_12 )
{
}
static inline struct V_1 * F_46 ( struct V_50 * V_51 )
{
return F_2 ( V_51 -> V_3 . V_4 ) ;
}
static T_1
F_47 ( struct V_2 * V_3 , struct V_5 * V_5 ,
unsigned long V_6 , T_2 V_7 , enum V_8 V_9 ,
struct V_10 * V_11 )
{
void * V_12 = F_4 ( F_5 ( V_5 ) ) + V_6 ;
struct V_1 * V_13 = F_2 ( V_3 -> V_4 ) ;
return F_6 ( V_13 , V_12 , V_7 ) ;
}
static void
F_48 ( struct V_2 * V_3 , T_1 V_14 ,
T_2 V_7 , enum V_8 V_9 ,
struct V_10 * V_11 )
{
struct V_1 * V_13 = F_2 ( V_3 -> V_4 ) ;
F_8 ( V_13 , V_14 , V_7 ) ;
}
static struct V_15 *
F_49 ( struct V_50 * V_51 ,
T_7 V_52 , T_7 V_53 ,
const char * V_20 , void * V_19 , int V_21 )
{
return F_11 ( F_46 ( V_51 ) , V_52 ,
V_53 , V_20 , V_19 ,
V_21 , V_54 ) ;
}
static void F_50 ( struct V_50 * V_51 ,
struct V_15 * V_23 , void * V_19 )
{
return F_13 ( F_46 ( V_51 ) , V_23 , V_19 ) ;
}
static void F_51 ( struct V_50 * V_51 , int V_24 )
{
struct V_1 * V_13 = F_46 ( V_51 ) ;
V_13 -> V_25 -> V_26 ( V_13 ) ;
}
void F_52 ( struct V_1 * V_13 )
{
struct V_55 * V_56 = V_13 -> V_27 ;
V_56 -> V_57 = F_53 ( V_58 ) ;
V_56 -> V_59 = - 1 ;
V_56 -> V_60 = V_13 -> V_61 + 1 ;
V_56 -> V_62 = 0x0 ;
V_56 -> V_63 = 0x0 ;
V_56 -> V_64 = - 1 ;
V_56 -> V_65 = - 1 ;
}
static inline struct V_1 * F_54 ( struct V_66 * V_67 )
{
return F_2 ( V_67 -> V_3 . V_4 ) ;
}
static void F_55 ( struct V_66 * V_67 )
{
struct V_1 * V_13 = F_54 ( V_67 ) ;
V_13 -> V_25 -> V_68 ( V_13 ) ;
V_13 -> V_25 -> V_69 ( V_13 ) ;
}
static bool F_56 ( struct V_66 * V_67 )
{
struct V_1 * V_13 = F_54 ( V_67 ) ;
return V_13 -> V_25 -> V_70 ( V_13 ) ;
}
static int F_57 ( struct V_1 * V_13 )
{
T_8 V_71 ;
struct V_72 * V_73 ;
F_58 ( V_71 ) ;
F_59 ( V_74 , V_71 ) ;
do {
V_73 = F_60 ( V_71 , V_13 -> V_25 -> V_75 ,
& V_13 -> V_47 -> V_3 ) ;
if ( V_73 ) {
V_13 -> V_76 [ V_13 -> V_77 ++ ] = V_73 ;
if ( V_13 -> V_77 >= V_78 )
break;
}
} while ( V_73 );
F_61 ( & V_13 -> V_47 -> V_3 , L_1 , V_13 -> V_77 ) ;
return V_13 -> V_77 ;
}
static void F_62 ( struct V_1 * V_13 )
{
int V_43 = 0 ;
for ( V_43 = 0 ; V_43 < V_13 -> V_77 ; V_43 ++ ) {
F_63 ( V_13 -> V_76 [ V_43 ] ) ;
V_13 -> V_76 [ V_43 ] = NULL ;
}
V_13 -> V_77 = 0 ;
}
static int F_64 ( struct V_66 * V_67 , int V_61 )
{
struct V_1 * V_13 = F_54 ( V_67 ) ;
int V_79 ;
F_52 ( V_13 ) ;
V_13 -> V_80 = F_65 ( & V_13 -> V_47 -> V_3 ,
V_81 , & V_82 ,
& V_83 , V_61 , V_13 -> V_84 . V_12 ) ;
if ( F_66 ( V_13 -> V_80 ) ) {
V_79 = F_67 ( V_13 -> V_80 ) ;
goto V_85;
}
if ( ! F_57 ( V_13 ) ) {
V_79 = - V_86 ;
goto V_87;
}
V_13 -> V_34 = F_68 ( & V_13 -> V_47 -> V_3 , V_88 ,
& V_89 , & V_90 ,
V_61 + 1 , 0 , & V_13 -> V_84 ,
& V_13 -> V_32 , V_13 -> V_27 , NULL ,
V_13 -> V_76 , V_13 -> V_77 ,
true ) ;
if ( F_66 ( V_13 -> V_34 ) ) {
V_79 = F_67 ( V_13 -> V_34 ) ;
goto V_91;
}
V_13 -> V_17 = F_69 ( & V_13 -> V_47 -> V_3 ,
V_92 , & V_93 ,
& V_94 , V_61 + 1 , & V_13 -> V_32 ,
V_13 -> V_76 [ 0 ] ) ;
if ( F_66 ( V_13 -> V_17 ) ) {
V_79 = F_67 ( V_13 -> V_17 ) ;
goto V_95;
}
V_79 = V_13 -> V_25 -> V_96 ( V_13 , NULL ) ;
if ( V_79 )
goto V_97;
F_70 ( V_13 ) ;
F_71 ( V_13 ) ;
V_13 -> V_98 -> V_99 ( V_13 ) ;
V_13 -> V_25 -> V_100 ( V_13 , V_101 , V_13 -> V_102 ) ;
V_13 -> V_25 -> V_100 ( V_13 , V_103 , V_13 -> V_102 >> 32 ) ;
V_13 -> V_25 -> V_104 ( V_13 ) ;
goto V_85;
V_97:
F_72 ( V_13 -> V_17 ) ;
V_95:
F_73 ( V_13 -> V_34 ) ;
V_91:
F_62 ( V_13 ) ;
V_87:
F_74 ( V_13 -> V_80 ) ;
V_85:
return V_79 ;
}
static void F_75 ( struct V_66 * V_67 , bool V_105 )
{
struct V_1 * V_13 = F_54 ( V_67 ) ;
F_72 ( V_13 -> V_17 ) ;
F_73 ( V_13 -> V_34 ) ;
F_62 ( V_13 ) ;
F_74 ( V_13 -> V_80 ) ;
F_52 ( V_13 ) ;
}
static T_9 F_76 ( struct V_66 * V_67 , char * V_106 )
{
struct V_1 * V_13 = F_54 ( V_67 ) ;
static const char * V_107 [ V_108 ] = { L_2 , L_3 } ;
return F_77 ( V_106 , V_109 , L_4 , V_107 [ V_13 -> V_107 ] ) ;
}
static T_9 F_78 ( struct V_66 * V_67 , char * V_106 )
{
struct V_1 * V_13 = F_54 ( V_67 ) ;
const char * string = L_5 ;
switch ( V_13 -> V_110 ) {
case V_111 :
string = L_6 ;
break;
case V_112 :
string = L_7 ;
break;
case V_113 :
string = L_8 ;
break;
case V_114 :
string = L_9 ;
break;
default:
break;
}
return F_77 ( V_106 , V_109 , L_4 , string ) ;
}
static struct V_115 * F_79 ( struct V_66 * V_67 )
{
struct V_1 * V_13 = F_54 ( V_67 ) ;
return & V_13 -> V_32 ;
}
