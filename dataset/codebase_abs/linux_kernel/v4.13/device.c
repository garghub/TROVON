static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_6 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_6 -> V_7 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_6 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , ( unsigned long long )
F_4 ( & V_6 -> V_8 ) ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_6 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_3 , V_6 -> V_9 ) ;
}
static void F_6 ( struct V_10 * V_10 )
{
struct V_6 * V_6 ;
V_6 = F_7 ( V_10 , struct V_6 , V_10 ) ;
F_8 ( V_6 ) ;
}
void F_9 ( struct V_6 * V_6 )
{
F_10 ( & V_6 -> V_10 , F_6 ) ;
}
static void F_11 ( void * V_11 )
{
struct V_6 * V_6 = V_11 ;
F_12 ( & V_6 -> V_2 -> V_12 ,
V_13 ) ;
F_9 ( V_6 ) ;
}
struct V_6 * F_13 ( struct V_1 * V_14 , int V_15 ,
struct V_16 * V_8 , unsigned int V_9 , void * V_17 ,
unsigned long V_18 )
{
struct V_6 * V_6 ;
if ( F_2 ( V_14 ) ) {
F_14 ( V_14 , L_4 ) ;
return NULL ;
}
if ( ! F_15 ( V_8 -> V_19 , V_9 )
|| ! F_15 ( F_4 ( V_8 ) , V_9 ) )
return NULL ;
V_6 = F_16 ( sizeof( * V_6 ) , V_20 ) ;
if ( ! V_6 )
return NULL ;
F_17 ( V_14 , V_6 ) ;
memcpy ( & V_6 -> V_8 , V_8 , sizeof( * V_8 ) ) ;
V_6 -> V_18 = V_18 ;
F_18 ( & V_6 -> V_10 ) ;
V_6 -> V_7 = V_15 ;
F_19 ( & V_6 -> V_21 ) ;
V_6 -> V_9 = V_9 ;
V_6 -> V_2 = V_14 ;
V_6 -> V_22 = V_17 ;
if ( F_20 ( & V_14 -> V_12 , V_13 ) ) {
F_8 ( V_6 ) ;
return NULL ; ;
}
F_21 ( & V_6 -> V_10 ) ;
if ( F_22 ( V_14 , F_11 , V_6 ) )
return NULL ;
return V_6 ;
}
static struct V_23 * F_23 ( struct V_1 * V_2 )
{
return F_7 ( V_2 , struct V_23 , V_2 ) ;
}
static T_1 F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_23 * V_23 = F_23 ( V_2 ) ;
unsigned long long V_24 = 0 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_23 -> V_26 ; V_25 ++ )
V_24 += F_4 ( & V_23 -> V_8 [ V_25 ] ) ;
return sprintf ( V_5 , L_2 , V_24 ) ;
}
static int F_25 ( struct V_23 * V_23 , struct V_27 * V_28 ,
const char * V_29 )
{
struct V_6 * V_6 = V_23 -> V_11 ;
struct V_1 * V_2 = & V_23 -> V_2 ;
unsigned long V_30 ;
if ( ! F_26 ( V_23 -> V_31 ) )
return - V_32 ;
if ( ( V_28 -> V_33 & V_34 ) != V_34 ) {
F_27 ( V_2 , L_5 ,
V_35 -> V_36 , V_29 ) ;
return - V_37 ;
}
V_30 = V_6 -> V_9 - 1 ;
if ( V_28 -> V_38 & V_30 || V_28 -> V_39 & V_30 ) {
F_27 ( V_2 , L_6 ,
V_35 -> V_36 , V_29 , V_28 -> V_38 , V_28 -> V_39 ,
V_30 ) ;
return - V_37 ;
}
if ( ( V_6 -> V_18 & ( V_40 | V_41 ) ) == V_40
&& ( V_28 -> V_33 & V_42 ) == 0 ) {
F_27 ( V_2 , L_7 ,
V_35 -> V_36 , V_29 ) ;
return - V_37 ;
}
if ( ! F_28 ( V_28 ) ) {
F_27 ( V_2 , L_8 ,
V_35 -> V_36 , V_29 ) ;
return - V_37 ;
}
return 0 ;
}
__weak T_2 F_29 ( struct V_23 * V_23 , T_3 V_43 ,
unsigned long V_24 )
{
struct V_16 * V_8 ;
T_2 V_44 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_23 -> V_26 ; V_25 ++ ) {
V_8 = & V_23 -> V_8 [ V_25 ] ;
V_44 = V_43 * V_45 + V_8 -> V_19 ;
if ( V_44 >= V_8 -> V_19 && V_44 <= V_8 -> V_46 )
break;
V_43 -= F_30 ( F_4 ( V_8 ) ) ;
}
if ( V_25 < V_23 -> V_26 ) {
V_8 = & V_23 -> V_8 [ V_25 ] ;
if ( V_44 + V_24 - 1 <= V_8 -> V_46 )
return V_44 ;
}
return - 1 ;
}
static int F_31 ( struct V_23 * V_23 , struct V_47 * V_48 )
{
struct V_1 * V_2 = & V_23 -> V_2 ;
struct V_6 * V_6 ;
int V_49 = V_50 ;
T_2 V_44 ;
T_4 V_51 ;
unsigned int V_52 = V_45 ;
if ( F_25 ( V_23 , V_48 -> V_28 , V_53 ) )
return V_50 ;
V_6 = V_23 -> V_11 ;
if ( V_6 -> V_9 > V_45 ) {
F_32 ( V_2 , L_9 ,
V_53 , V_6 -> V_9 , V_52 ) ;
return V_50 ;
}
if ( V_52 != V_6 -> V_9 )
return V_50 ;
V_44 = F_29 ( V_23 , V_48 -> V_43 , V_45 ) ;
if ( V_44 == - 1 ) {
F_32 ( V_2 , L_10 , V_53 ,
V_48 -> V_43 ) ;
return V_50 ;
}
V_51 = F_33 ( V_44 , V_6 -> V_18 ) ;
V_49 = F_34 ( V_48 -> V_28 , V_48 -> V_54 , V_51 ) ;
if ( V_49 == - V_55 )
return V_56 ;
if ( V_49 < 0 && V_49 != - V_57 )
return V_50 ;
return V_58 ;
}
static int F_35 ( struct V_23 * V_23 , struct V_47 * V_48 )
{
unsigned long V_59 = V_48 -> V_54 & V_60 ;
struct V_1 * V_2 = & V_23 -> V_2 ;
struct V_6 * V_6 ;
T_2 V_44 ;
T_3 V_43 ;
T_4 V_51 ;
unsigned int V_52 = V_61 ;
if ( F_25 ( V_23 , V_48 -> V_28 , V_53 ) )
return V_50 ;
V_6 = V_23 -> V_11 ;
if ( V_6 -> V_9 > V_61 ) {
F_32 ( V_2 , L_9 ,
V_53 , V_6 -> V_9 , V_52 ) ;
return V_50 ;
}
if ( ( V_6 -> V_18 & ( V_40 | V_41 ) ) != ( V_40 | V_41 ) ) {
F_32 ( V_2 , L_11 , V_53 ) ;
return V_50 ;
}
if ( V_52 < V_6 -> V_9 )
return V_50 ;
else if ( V_52 > V_6 -> V_9 )
return V_62 ;
if ( V_59 < V_48 -> V_28 -> V_38 ||
( V_59 + V_61 ) > V_48 -> V_28 -> V_39 )
return V_50 ;
V_43 = F_36 ( V_48 -> V_28 , V_59 ) ;
V_44 = F_29 ( V_23 , V_43 , V_61 ) ;
if ( V_44 == - 1 ) {
F_32 ( V_2 , L_10 , V_53 ,
V_43 ) ;
return V_50 ;
}
V_51 = F_33 ( V_44 , V_6 -> V_18 ) ;
return F_37 ( V_48 -> V_28 , V_48 -> V_54 , V_48 -> V_63 , V_51 ,
V_48 -> V_64 & V_65 ) ;
}
static int F_38 ( struct V_23 * V_23 , struct V_47 * V_48 )
{
unsigned long V_66 = V_48 -> V_54 & V_67 ;
struct V_1 * V_2 = & V_23 -> V_2 ;
struct V_6 * V_6 ;
T_2 V_44 ;
T_3 V_43 ;
T_4 V_51 ;
unsigned int V_52 = V_68 ;
if ( F_25 ( V_23 , V_48 -> V_28 , V_53 ) )
return V_50 ;
V_6 = V_23 -> V_11 ;
if ( V_6 -> V_9 > V_68 ) {
F_32 ( V_2 , L_9 ,
V_53 , V_6 -> V_9 , V_52 ) ;
return V_50 ;
}
if ( ( V_6 -> V_18 & ( V_40 | V_41 ) ) != ( V_40 | V_41 ) ) {
F_32 ( V_2 , L_11 , V_53 ) ;
return V_50 ;
}
if ( V_52 < V_6 -> V_9 )
return V_50 ;
else if ( V_52 > V_6 -> V_9 )
return V_62 ;
if ( V_66 < V_48 -> V_28 -> V_38 ||
( V_66 + V_68 ) > V_48 -> V_28 -> V_39 )
return V_50 ;
V_43 = F_36 ( V_48 -> V_28 , V_66 ) ;
V_44 = F_29 ( V_23 , V_43 , V_68 ) ;
if ( V_44 == - 1 ) {
F_32 ( V_2 , L_10 , V_53 ,
V_43 ) ;
return V_50 ;
}
V_51 = F_33 ( V_44 , V_6 -> V_18 ) ;
return F_39 ( V_48 -> V_28 , V_48 -> V_54 , V_48 -> V_69 , V_51 ,
V_48 -> V_64 & V_65 ) ;
}
static int F_38 ( struct V_23 * V_23 , struct V_47 * V_48 )
{
return V_62 ;
}
static int F_40 ( struct V_47 * V_48 ,
enum V_70 V_71 )
{
int V_49 , V_7 ;
struct V_72 * V_73 = V_48 -> V_28 -> V_74 ;
struct V_23 * V_23 = V_73 -> V_75 ;
F_32 ( & V_23 -> V_2 , L_12 , V_53 ,
V_35 -> V_36 , ( V_48 -> V_64 & V_65 )
? L_13 : L_14 ,
V_48 -> V_28 -> V_38 , V_48 -> V_28 -> V_39 , V_71 ) ;
V_7 = F_41 () ;
switch ( V_71 ) {
case V_76 :
V_49 = F_31 ( V_23 , V_48 ) ;
break;
case V_77 :
V_49 = F_35 ( V_23 , V_48 ) ;
break;
case V_78 :
V_49 = F_38 ( V_23 , V_48 ) ;
break;
default:
V_49 = V_50 ;
}
F_42 ( V_7 ) ;
return V_49 ;
}
static int F_43 ( struct V_47 * V_48 )
{
return F_40 ( V_48 , V_76 ) ;
}
static int F_44 ( struct V_72 * V_73 , struct V_27 * V_28 )
{
struct V_23 * V_23 = V_73 -> V_75 ;
int V_49 , V_7 ;
F_32 ( & V_23 -> V_2 , L_15 , V_53 ) ;
V_7 = F_41 () ;
V_49 = F_25 ( V_23 , V_28 , V_53 ) ;
F_42 ( V_7 ) ;
if ( V_49 )
return V_49 ;
V_28 -> V_79 = & V_80 ;
V_28 -> V_33 |= V_81 | V_82 ;
return 0 ;
}
static unsigned long F_45 ( struct V_72 * V_73 ,
unsigned long V_17 , unsigned long V_83 , unsigned long V_43 ,
unsigned long V_64 )
{
unsigned long V_84 , V_85 , V_86 , V_87 , V_88 , V_9 ;
struct V_23 * V_23 = V_73 ? V_73 -> V_75 : NULL ;
struct V_6 * V_6 ;
if ( ! V_23 || V_17 )
goto V_89;
V_6 = V_23 -> V_11 ;
V_9 = V_6 -> V_9 ;
V_84 = V_43 << V_90 ;
V_85 = V_84 + V_83 ;
V_86 = F_46 ( V_84 , V_9 ) ;
if ( ( V_85 <= V_86 ) || ( ( V_85 - V_86 ) < V_9 ) )
goto V_89;
V_87 = V_83 + V_9 ;
if ( ( V_84 + V_87 ) < V_84 )
goto V_89;
V_88 = V_35 -> V_91 -> V_92 ( V_73 , V_17 , V_87 ,
V_43 , V_64 ) ;
if ( ! F_47 ( V_88 ) ) {
V_88 += ( V_84 - V_88 ) & ( V_9 - 1 ) ;
return V_88 ;
}
V_89:
return V_35 -> V_91 -> V_92 ( V_73 , V_17 , V_83 , V_43 , V_64 ) ;
}
static int F_48 ( struct V_93 * V_93 , struct V_72 * V_73 )
{
struct V_94 * V_31 = F_49 ( V_93 ) ;
struct V_93 * V_95 = F_50 ( V_31 ) ;
struct V_23 * V_23 = F_51 ( V_31 ) ;
F_32 ( & V_23 -> V_2 , L_15 , V_53 ) ;
V_93 -> V_96 = V_95 -> V_96 ;
V_93 -> V_96 -> V_97 = V_95 ;
V_73 -> V_98 = V_93 -> V_96 ;
V_73 -> V_99 = F_52 ( V_73 -> V_98 ) ;
V_73 -> V_75 = V_23 ;
V_93 -> V_100 = V_101 ;
return 0 ;
}
static int F_53 ( struct V_93 * V_93 , struct V_72 * V_73 )
{
struct V_23 * V_23 = V_73 -> V_75 ;
F_32 ( & V_23 -> V_2 , L_15 , V_53 ) ;
return 0 ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_23 * V_23 = F_23 ( V_2 ) ;
struct V_6 * V_6 = V_23 -> V_11 ;
struct V_94 * V_31 = V_23 -> V_31 ;
if ( V_23 -> V_7 >= 0 )
F_55 ( & V_6 -> V_21 , V_23 -> V_7 ) ;
F_9 ( V_6 ) ;
F_56 ( V_31 ) ;
F_8 ( V_23 ) ;
}
static void F_57 ( struct V_23 * V_23 )
{
struct V_94 * V_31 = V_23 -> V_31 ;
struct V_93 * V_93 = F_50 ( V_31 ) ;
F_58 ( V_31 ) ;
F_59 ( V_93 -> V_96 , 0 , 0 , 1 ) ;
}
static void F_60 ( void * V_2 )
{
struct V_23 * V_23 = F_23 ( V_2 ) ;
struct V_94 * V_31 = V_23 -> V_31 ;
struct V_93 * V_93 = F_50 ( V_31 ) ;
struct V_102 * V_102 = V_93 -> V_103 ;
F_32 ( V_2 , L_15 , V_53 ) ;
F_57 ( V_23 ) ;
F_61 ( V_102 , V_2 ) ;
F_62 ( V_2 ) ;
}
struct V_23 * F_63 ( struct V_6 * V_6 ,
int V_7 , struct V_16 * V_8 , int V_104 )
{
struct V_1 * V_14 = V_6 -> V_2 ;
struct V_94 * V_31 ;
struct V_23 * V_23 ;
struct V_93 * V_93 ;
struct V_1 * V_2 ;
struct V_102 * V_102 ;
int V_49 , V_25 ;
if ( ! V_104 )
return F_64 ( - V_37 ) ;
V_23 = F_16 ( sizeof( * V_23 ) + sizeof( * V_8 ) * V_104 , V_20 ) ;
if ( ! V_23 )
return F_64 ( - V_55 ) ;
for ( V_25 = 0 ; V_25 < V_104 ; V_25 ++ ) {
if ( ! F_15 ( V_8 [ V_25 ] . V_19 , V_6 -> V_9 )
|| ! F_15 ( F_4 ( & V_8 [ V_25 ] ) ,
V_6 -> V_9 ) ) {
V_49 = - V_37 ;
break;
}
V_23 -> V_8 [ V_25 ] . V_19 = V_8 [ V_25 ] . V_19 ;
V_23 -> V_8 [ V_25 ] . V_46 = V_8 [ V_25 ] . V_46 ;
}
if ( V_25 < V_104 )
goto V_105;
if ( V_7 < 0 ) {
V_7 = F_65 ( & V_6 -> V_21 , 0 , 0 , V_20 ) ;
V_23 -> V_7 = V_7 ;
if ( V_7 < 0 ) {
V_49 = V_7 ;
goto V_105;
}
} else {
V_23 -> V_7 = - 1 ;
}
V_31 = F_66 ( V_23 , NULL , NULL ) ;
if ( ! V_31 ) {
V_49 = - V_55 ;
goto V_106;
}
V_2 = & V_23 -> V_2 ;
F_67 ( V_2 ) ;
V_93 = F_50 ( V_31 ) ;
V_102 = V_93 -> V_103 ;
F_68 ( V_102 , & V_107 ) ;
V_102 -> V_108 = V_14 -> V_109 -> V_108 ;
V_23 -> V_26 = V_104 ;
V_23 -> V_31 = V_31 ;
V_23 -> V_11 = V_6 ;
F_21 ( & V_6 -> V_10 ) ;
V_2 -> V_110 = V_93 -> V_111 ;
V_2 -> V_112 = V_113 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_114 = V_115 ;
V_2 -> V_116 = F_54 ;
F_69 ( V_2 , L_16 , V_6 -> V_7 , V_7 ) ;
V_49 = F_70 ( V_102 , V_2 ) ;
if ( V_49 ) {
F_57 ( V_23 ) ;
F_62 ( V_2 ) ;
return F_64 ( V_49 ) ;
}
V_49 = F_22 ( V_6 -> V_2 , F_60 , V_2 ) ;
if ( V_49 )
return F_64 ( V_49 ) ;
return V_23 ;
V_106:
if ( V_23 -> V_7 >= 0 )
F_55 ( & V_6 -> V_21 , V_23 -> V_7 ) ;
V_105:
F_8 ( V_23 ) ;
return F_64 ( V_49 ) ;
}
static int T_5 F_71 ( void )
{
V_113 = F_72 ( V_117 , L_17 ) ;
return F_73 ( V_113 ) ;
}
static void T_6 F_74 ( void )
{
F_75 ( V_113 ) ;
}
