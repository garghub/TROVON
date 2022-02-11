static int F_1 ( const char * V_1 ,
struct V_2 * V_3 )
{
F_2 ( V_4 L_1 , V_3 -> V_5 ) ;
return - V_6 ;
}
static int F_3 ( char * V_7 ,
struct V_2 * V_3 )
{
return F_4 ( V_7 , V_8 ,
strlen ( V_8 ) + 1 ) ;
}
static int F_5 ( int V_9 ,
int * V_10 ,
int * V_11 )
{
if ( V_9 & ( V_12 | V_13 ) )
* V_10 = V_14 ;
else
* V_10 = V_15 ;
* V_11 = 0 ;
if ( V_9 & V_16 )
* V_11 |= V_17 ;
return 0 ;
}
static int F_6 ( struct V_18 * V_18 ,
struct V_19 * V_19 )
{
int V_20 , V_10 , V_11 ;
struct V_21 * V_22 = NULL ;
struct V_23 * V_24 ;
if ( F_7 ( V_18 -> V_25 ) )
F_8 () ;
F_9 ( 0 , L_2 , V_18 -> V_26 ,
V_19 -> V_27 ) ;
V_20 = F_5 ( V_19 -> V_27 , & V_10 , & V_11 ) ;
if ( V_20 < 0 )
goto V_28;
V_19 -> V_27 &= ~ V_29 ;
V_22 = F_10 ( sizeof( * V_22 ) , V_30 ) ;
if ( ! V_22 ) {
V_20 = - V_31 ;
goto V_28;
}
V_22 -> V_32 = V_10 ;
V_24 = F_11 ( V_18 ) ;
V_20 = F_12 ( & V_24 -> V_33 , V_10 , V_11 ) ;
if ( V_20 < 0 ) {
if ( V_11 & V_17 && V_20 == - V_34 )
V_20 = - V_35 ;
F_13 ( V_22 ) ;
goto V_28;
}
V_19 -> V_36 = V_22 ;
V_28:
return V_20 ;
}
static int F_14 ( struct V_18 * V_18 ,
struct V_19 * V_19 )
{
int V_10 , V_20 ;
struct V_23 * V_24 = F_11 ( V_18 ) ;
struct V_21 * V_22 = V_19 -> V_36 ;
if ( F_7 ( V_18 -> V_25 ) )
F_8 () ;
F_9 ( 0 , L_3 , V_18 -> V_26 ) ;
V_20 = 0 ;
if ( V_22 ) {
V_10 = V_22 -> V_32 ;
if ( V_10 != V_37 )
F_15 ( & V_24 -> V_33 , V_10 ) ;
F_13 ( V_22 ) ;
V_19 -> V_36 = NULL ;
}
return 0 ;
}
static int F_16 ( struct V_38 * V_38 , struct V_39 * V_40 )
{
int error ;
struct V_18 * V_18 = F_17 ( V_38 ) ;
V_40 -> V_41 &= ~ V_42 ;
error = F_18 ( V_18 , V_40 ) ;
if ( error )
return error ;
F_19 ( V_18 , V_40 ) ;
F_20 ( V_18 ) ;
return 0 ;
}
static unsigned int F_21 ( struct V_19 * V_19 , T_1 * V_43 )
{
int V_44 = 0 ;
struct V_18 * V_18 = F_22 ( V_19 ) ;
struct V_23 * V_24 = F_11 ( V_18 ) ;
F_23 ( V_19 , & V_24 -> V_33 . V_45 , V_43 ) ;
F_24 ( & V_24 -> V_33 . V_46 ) ;
if ( V_24 -> V_33 . V_47 & V_48 )
V_44 = V_49 | V_50 ;
F_25 ( & V_24 -> V_33 . V_46 ) ;
return V_44 ;
}
static T_2 F_26 ( struct V_19 * V_51 ,
char T_3 * V_52 ,
T_4 V_53 ,
T_5 * V_54 )
{
int V_55 ;
T_2 V_56 , V_57 ;
char * V_58 ;
struct V_18 * V_18 = F_22 ( V_51 ) ;
F_9 ( 0 , L_4 ,
V_18 -> V_26 , V_53 , * V_54 ) ;
if ( * V_54 >= F_27 ( V_18 ) )
return 0 ;
if ( ! V_53 )
return 0 ;
if ( ! F_28 ( V_59 , V_52 , V_53 ) )
return - V_60 ;
if ( ( V_53 + * V_54 ) > F_27 ( V_18 ) )
V_56 = F_27 ( V_18 ) - * V_54 ;
else
V_56 = V_53 ;
V_58 = F_10 ( V_56 , V_30 ) ;
if ( ! V_58 )
return - V_31 ;
V_57 = F_29 ( V_18 , V_58 , V_56 ) ;
if ( V_57 ) {
F_30 ( V_57 != V_56 ) ;
V_55 = F_31 ( V_52 , V_58 , V_56 ) ;
V_56 -= V_55 ;
} else
V_56 = 0 ;
F_13 ( V_58 ) ;
* V_54 = * V_54 + V_56 ;
F_9 ( 0 , L_5 , V_56 ) ;
return V_56 ;
}
static T_2 F_32 ( struct V_19 * V_51 ,
const char T_3 * V_52 ,
T_4 V_53 ,
T_5 * V_54 )
{
int V_55 ;
T_2 V_61 ;
char * V_58 ;
struct V_18 * V_18 = F_22 ( V_51 ) ;
F_9 ( 0 , L_4 ,
V_18 -> V_26 , V_53 , * V_54 ) ;
if ( * V_54 >= F_27 ( V_18 ) )
return - V_62 ;
if ( ! V_53 )
return 0 ;
if ( ! F_28 ( V_63 , V_52 , V_53 ) )
return - V_60 ;
if ( ( V_53 + * V_54 ) > F_27 ( V_18 ) )
V_61 = F_27 ( V_18 ) - * V_54 ;
else
V_61 = V_53 - * V_54 ;
V_58 = F_10 ( V_61 , V_30 ) ;
if ( ! V_58 )
return - V_31 ;
V_55 = F_33 ( V_58 , V_52 , V_61 ) ;
V_61 -= V_55 ;
if ( V_61 )
F_34 ( V_18 , V_58 , V_61 ) ;
F_13 ( V_58 ) ;
* V_54 = * V_54 + V_61 ;
F_9 ( 0 , L_6 , V_61 ) ;
return V_61 ;
}
static void F_35 ( void * V_64 )
{
struct V_23 * V_24 =
(struct V_23 * ) V_64 ;
V_24 -> V_65 = NULL ;
V_24 -> V_66 = NULL ;
F_36 ( & V_24 -> V_67 ) ;
}
static struct V_18 * F_37 ( struct V_68 * V_69 )
{
struct V_23 * V_24 ;
V_24 = F_38 ( V_70 , V_30 ) ;
if ( ! V_24 )
return NULL ;
return & V_24 -> V_67 ;
}
static void F_39 ( struct V_71 * V_72 )
{
struct V_18 * V_18 = F_40 ( V_72 , struct V_18 , V_73 ) ;
F_41 ( V_70 , F_11 ( V_18 ) ) ;
}
static void F_42 ( struct V_18 * V_18 )
{
F_43 ( & V_18 -> V_73 , F_39 ) ;
}
static void F_44 ( struct V_18 * V_18 )
{
int V_20 ;
struct V_23 * V_24 ;
F_45 ( V_18 ) ;
F_9 ( 0 , L_7 , V_18 -> V_26 ) ;
V_24 = F_11 ( V_18 ) ;
if ( F_46 ( V_18 -> V_25 ) ) {
V_20 = F_47 ( & V_24 -> V_33 ) ;
if ( V_20 < 0 )
F_48 ( V_20 ) ;
F_49 ( V_24 -> V_66 ) ;
goto V_74;
}
F_9 ( 0 , L_8 , V_24 -> V_65 ) ;
if ( V_24 -> V_65 )
F_50 ( V_24 -> V_65 ) ;
V_74:
V_24 -> V_66 = NULL ;
V_24 -> V_65 = NULL ;
}
static struct V_18 * F_51 ( struct V_68 * V_69 )
{
struct V_18 * V_18 = F_52 ( V_69 ) ;
T_6 V_75 = V_76 | 0755 ;
if ( V_18 ) {
V_18 -> V_26 = F_53 () ;
F_54 ( V_18 , NULL , V_75 ) ;
V_18 -> V_77 = V_18 -> V_78 = V_18 -> V_79 = V_80 ;
F_55 ( V_18 ) ;
V_18 -> V_81 = & V_82 ;
V_18 -> V_83 = & V_84 ;
}
return V_18 ;
}
static struct V_18 * F_56 ( struct V_18 * V_85 ,
struct V_38 * V_38 ,
T_6 V_75 )
{
struct V_68 * V_69 = V_85 -> V_86 ;
struct V_18 * V_18 = F_52 ( V_69 ) ;
struct V_23 * V_24 ;
if ( ! V_18 )
return NULL ;
V_18 -> V_26 = F_53 () ;
F_54 ( V_18 , V_85 , V_75 ) ;
V_18 -> V_77 = V_18 -> V_78 = V_18 -> V_79 = V_80 ;
V_24 = F_11 ( V_18 ) ;
V_24 -> V_65 = F_11 ( V_85 ) -> V_65 ;
switch ( V_75 & V_87 ) {
default:
F_8 () ;
break;
case V_88 :
V_18 -> V_83 = & V_89 ;
V_18 -> V_81 = & V_90 ;
F_57 ( V_18 , V_91 ) ;
F_58 ( & V_24 -> V_33 , V_38 ) ;
V_24 -> V_66 = F_59 ( V_85 ) ;
F_30 ( ! V_24 -> V_66 ) ;
break;
case V_76 :
V_18 -> V_83 = & V_92 ;
V_18 -> V_81 = & V_82 ;
F_55 ( V_18 ) ;
break;
}
return V_18 ;
}
static int F_60 ( struct V_18 * V_93 ,
struct V_38 * V_38 ,
T_6 V_75 )
{
int V_20 ;
struct V_18 * V_18 = NULL ;
struct V_94 * V_95 = & V_38 -> V_96 ;
struct V_23 * V_24 ;
struct V_97 * V_98 ;
F_9 ( 0 , L_9 , V_95 -> V_99 , V_95 -> V_5 ) ;
if ( V_95 -> V_99 >= V_100 ) {
V_20 = - V_6 ;
F_9 ( V_101 , L_10 ) ;
goto V_28;
}
V_18 = F_56 ( V_93 , V_38 , V_75 | V_76 ) ;
if ( ! V_18 ) {
V_20 = - V_31 ;
F_48 ( V_20 ) ;
goto V_28;
}
V_24 = F_11 ( V_18 ) ;
V_98 = F_61 ( V_95 ) ;
if ( F_62 ( V_98 ) ) {
V_20 = F_63 ( V_98 ) ;
F_9 ( V_101 , L_11 ,
V_20 , V_95 -> V_99 , V_95 -> V_5 ) ;
goto V_28;
}
V_24 -> V_65 = V_98 ;
F_55 ( V_93 ) ;
F_64 ( V_38 , V_18 ) ;
F_65 ( V_38 ) ;
V_20 = 0 ;
V_28:
if ( V_20 < 0 )
F_49 ( V_18 ) ;
return V_20 ;
}
static int F_66 ( struct V_18 * V_93 ,
struct V_38 * V_38 ,
T_6 V_75 ,
bool V_102 )
{
int V_20 = 0 ;
struct V_18 * V_18 ;
struct V_94 * V_5 = & V_38 -> V_96 ;
F_9 ( 0 , L_12 , V_5 -> V_99 , V_5 -> V_5 ) ;
if ( V_5 -> V_99 >= V_103 ||
V_5 -> V_5 [ 0 ] == '$' ) {
V_20 = - V_6 ;
F_9 ( V_101 , L_13 , V_5 -> V_99 ,
V_5 -> V_5 ) ;
goto V_28;
}
V_18 = F_56 ( V_93 , V_38 , V_75 | V_88 ) ;
if ( ! V_18 ) {
V_20 = - V_31 ;
F_48 ( V_20 ) ;
goto V_28;
}
F_64 ( V_38 , V_18 ) ;
F_65 ( V_38 ) ;
V_28:
return V_20 ;
}
static int F_67 ( struct V_18 * V_93 ,
struct V_38 * V_38 )
{
int V_20 ;
struct V_18 * V_18 = F_17 ( V_38 ) ;
F_9 ( 0 , L_14 , V_18 -> V_26 ) ;
V_20 = F_47 ( & F_11 ( V_18 ) -> V_33 ) ;
if ( V_20 < 0 ) {
F_9 ( V_101 , L_15 ,
V_38 , V_20 ) ;
goto V_28;
}
V_20 = F_68 ( V_93 , V_38 ) ;
V_28:
return V_20 ;
}
static int F_69 ( struct V_68 * V_69 ,
void * V_104 ,
int V_105 )
{
V_69 -> V_106 = V_107 ;
V_69 -> V_108 = V_109 ;
V_69 -> V_110 = V_111 ;
V_69 -> V_112 = V_113 ;
V_69 -> V_114 = & V_115 ;
V_69 -> V_116 = F_70 ( F_51 ( V_69 ) ) ;
if ( ! V_69 -> V_116 )
return - V_31 ;
return 0 ;
}
static struct V_38 * F_71 ( struct V_117 * V_118 ,
int V_11 , const char * V_119 , void * V_104 )
{
return F_72 ( V_118 , V_11 , V_104 , F_69 ) ;
}
static int T_7 F_73 ( void )
{
int V_20 ;
int V_120 = 0 , V_121 = 0 ;
V_70 = F_74 ( L_16 ,
sizeof( struct V_23 ) ,
0 , ( V_122 | V_123 |
V_124 ) ,
F_35 ) ;
if ( ! V_70 ) {
V_20 = - V_31 ;
goto V_28;
}
V_120 = 1 ;
V_125 = F_75 ( L_17 ) ;
if ( ! V_125 ) {
V_20 = - V_31 ;
goto V_28;
}
V_121 = 1 ;
F_76 () ;
V_20 = F_77 ( & V_126 ) ;
V_28:
if ( V_20 ) {
if ( V_120 )
F_78 ( V_70 ) ;
if ( V_121 )
F_79 ( V_125 ) ;
} else
F_2 ( L_18 ) ;
return V_20 ;
}
static void T_8 F_80 ( void )
{
F_81 ( & V_126 ) ;
F_82 ( V_125 ) ;
F_79 ( V_125 ) ;
F_83 () ;
F_78 ( V_70 ) ;
}
