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
V_27 = F_15 ( V_12 -> V_29 -> V_5 , V_22 , V_23 , V_19 ) ;
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
F_21 ( V_12 -> V_29 -> V_5 , V_22 , V_23 , V_19 ) ;
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
F_21 ( V_12 -> V_29 -> V_5 , V_22 , V_23 , V_19 ) ;
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
static void F_40 ( struct V_1 * V_12 )
{
int V_25 ;
#define F_41 (45)
F_42 ( & V_12 -> V_52 ) ;
V_12 -> V_40 -> V_53 ( V_12 ) ;
V_12 -> V_40 -> V_54 ( V_12 ) ;
for ( V_25 = 0 ; V_25 < F_41 ; V_25 ++ ) {
if ( V_12 -> V_40 -> V_55 ( V_12 ) )
goto V_56;
F_43 ( 1000 ) ;
}
F_44 ( V_12 , V_57 ) ;
V_56:
F_45 ( & V_12 -> V_52 ) ;
}
void F_46 ( struct V_1 * V_12 )
{
struct V_58 * V_59 = V_12 -> V_60 ;
V_59 -> V_61 = F_47 ( V_62 ) ;
V_59 -> V_63 = V_12 -> V_64 ;
V_59 -> V_65 = - 1 ;
V_59 -> V_66 = - 1 ;
V_59 -> V_67 = 0 ;
V_59 -> V_68 = 0 ;
V_59 -> V_69 = F_48 ( & V_70 ) + 1 ;
V_59 -> V_71 = V_12 -> V_72 + 1 ;
V_59 -> V_73 = 0x0 ;
V_59 -> V_74 = 0x0 ;
V_59 -> V_75 = - 1 ;
V_59 -> V_76 = - 1 ;
}
static int F_49 ( struct V_1 * V_12 )
{
T_8 V_77 ;
struct V_78 * V_79 ;
F_50 ( L_1 ) ;
F_51 ( V_77 ) ;
F_52 ( V_80 , V_77 ) ;
do {
V_79 = F_53 ( V_77 , V_12 -> V_40 -> V_81 ,
V_12 -> V_29 -> V_5 ) ;
if ( V_79 ) {
V_12 -> V_82 [ V_12 -> V_83 ++ ] = V_79 ;
if ( V_12 -> V_83 >= V_84 )
break;
}
} while ( V_79 );
F_54 ( V_12 -> V_29 -> V_5 , L_2 , V_12 -> V_83 ) ;
return V_12 -> V_83 ;
}
static void F_55 ( struct V_1 * V_12 )
{
int V_25 = 0 ;
for ( V_25 = 0 ; V_25 < V_12 -> V_83 ; V_25 ++ ) {
F_56 ( V_12 -> V_82 [ V_25 ] ) ;
V_12 -> V_82 [ V_25 ] = NULL ;
}
V_12 -> V_83 = 0 ;
}
int F_57 ( struct V_1 * V_12 , const char * V_85 )
{
int V_86 ;
F_58 ( & V_12 -> V_87 ) ;
F_46 ( V_12 ) ;
V_88:
if ( V_89 != V_12 -> V_90 ) {
V_86 = - V_91 ;
goto V_92;
}
if ( ! V_12 -> V_40 -> V_55 ( V_12 ) ) {
F_40 ( V_12 ) ;
goto V_88;
}
V_12 -> V_93 = F_59 ( V_12 -> V_29 -> V_5 ,
V_94 , & V_95 ,
& V_96 , V_12 -> V_97 . V_14 ) ;
if ( F_60 ( V_12 -> V_93 ) ) {
V_86 = F_61 ( V_12 -> V_93 ) ;
goto V_92;
}
if ( ! F_49 ( V_12 ) ) {
V_86 = - V_98 ;
goto V_99;
}
V_12 -> V_3 = F_62 ( V_12 -> V_29 -> V_5 , V_100 ,
& V_101 , & V_102 ,
V_12 -> V_72 + 1 , 0 , & V_12 -> V_97 ,
& V_12 -> V_45 , V_12 -> V_60 , NULL ,
V_12 -> V_82 , V_12 -> V_83 ) ;
if ( F_60 ( V_12 -> V_3 ) ) {
V_86 = F_61 ( V_12 -> V_3 ) ;
goto V_103;
}
V_86 = V_12 -> V_40 -> V_104 ( V_12 , V_85 ) ;
if ( V_86 )
goto V_105;
F_63 ( V_12 ) ;
F_64 ( V_12 ) ;
V_12 -> V_106 -> V_107 ( V_12 ) ;
V_12 -> V_40 -> V_108 ( V_12 , V_109 , V_12 -> V_110 ) ;
V_12 -> V_40 -> V_108 ( V_12 , V_111 , V_12 -> V_110 >> 32 ) ;
V_12 -> V_40 -> V_112 ( V_12 ) ;
F_44 ( V_12 , V_113 ) ;
goto V_92;
V_105:
F_65 ( V_12 -> V_3 ) ;
V_103:
F_55 ( V_12 ) ;
V_99:
F_66 ( V_12 -> V_93 ) ;
V_92:
F_67 ( & V_12 -> V_87 ) ;
return V_86 ;
}
void F_68 ( struct V_1 * V_12 , bool V_114 )
{
F_58 ( & V_12 -> V_87 ) ;
if ( V_89 != V_12 -> V_90 || V_114 ) {
F_65 ( V_12 -> V_3 ) ;
F_69 ( V_12 ) ;
F_55 ( V_12 ) ;
F_66 ( V_12 -> V_93 ) ;
F_46 ( V_12 ) ;
F_40 ( V_12 ) ;
if ( V_57 == V_12 -> V_90 )
goto V_115;
F_70 ( V_12 , V_116 ) ;
if ( V_117 != V_12 -> V_90 )
F_44 ( V_12 , V_89 ) ;
}
V_115:
F_67 ( & V_12 -> V_87 ) ;
}
void F_71 ( struct V_1 * V_12 )
{
struct V_58 * V_59 = V_12 -> V_60 ;
T_9 V_36 = V_59 -> V_65 ;
F_58 ( & V_12 -> V_87 ) ;
if ( V_113 == V_12 -> V_90 && V_36 != - 1 ) {
V_59 -> V_68 = 1 ;
V_12 -> V_40 -> V_42 ( V_12 , V_36 ) ;
F_44 ( V_12 , V_118 ) ;
}
F_67 ( & V_12 -> V_87 ) ;
}
void F_72 ( struct V_119 * V_120 )
{
struct V_1 * V_12 = F_73 ( V_120 , struct V_1 ,
V_121 ) ;
struct V_58 * V_59 = V_12 -> V_60 ;
F_58 ( & V_12 -> V_87 ) ;
F_70 ( V_12 , V_59 -> V_67 ) ;
V_59 -> V_67 = 0 ;
if ( V_118 != V_12 -> V_90 &&
V_117 != V_12 -> V_90 )
F_44 ( V_12 , V_118 ) ;
F_67 ( & V_12 -> V_87 ) ;
}
void F_74 ( struct V_119 * V_120 )
{
struct V_1 * V_12 = F_73 ( V_120 , struct V_1 ,
V_122 ) ;
F_68 ( V_12 , false ) ;
}
void F_75 ( struct V_1 * V_12 )
{
if ( V_12 -> V_90 != V_117 ) {
F_76 ( V_12 -> V_29 -> V_5 , L_3 ,
V_12 -> V_90 , V_117 ) ;
return;
}
if ( ! V_12 -> V_40 -> V_55 ( V_12 ) )
F_68 ( V_12 , true ) ;
F_58 ( & V_12 -> V_87 ) ;
F_44 ( V_12 , V_89 ) ;
F_67 ( & V_12 -> V_87 ) ;
}
void F_77 ( struct V_1 * V_12 )
{
unsigned long V_123 ;
#define F_78 (60 * HZ)
F_58 ( & V_12 -> V_87 ) ;
switch ( V_12 -> V_90 ) {
case V_89 :
F_44 ( V_12 , V_117 ) ;
F_67 ( & V_12 -> V_87 ) ;
break;
case V_113 :
F_44 ( V_12 , V_124 ) ;
F_67 ( & V_12 -> V_87 ) ;
V_123 = F_79 ( & V_12 -> V_52 ,
F_78 ) ;
if ( ! V_123 ) {
F_58 ( & V_12 -> V_87 ) ;
F_44 ( V_12 , V_117 ) ;
F_67 ( & V_12 -> V_87 ) ;
F_68 ( V_12 , true ) ;
}
break;
case V_118 :
F_44 ( V_12 , V_117 ) ;
F_67 ( & V_12 -> V_87 ) ;
V_123 = F_79 ( & V_12 -> V_52 ,
F_78 ) ;
if ( ! V_123 )
F_68 ( V_12 , true ) ;
break;
default:
F_67 ( & V_12 -> V_87 ) ;
break;
}
}
void F_80 ( struct V_1 * V_12 )
{
struct V_58 * V_59 = V_12 -> V_60 ;
T_9 V_36 = V_59 -> V_65 ;
F_58 ( & V_12 -> V_87 ) ;
if ( V_124 == V_12 -> V_90 && V_36 != - 1 ) {
V_59 -> V_68 = 1 ;
V_12 -> V_40 -> V_42 ( V_12 , V_36 ) ;
F_44 ( V_12 , V_117 ) ;
}
F_67 ( & V_12 -> V_87 ) ;
}
