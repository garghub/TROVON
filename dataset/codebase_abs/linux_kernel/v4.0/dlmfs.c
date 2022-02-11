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
struct V_18 * V_18 = V_38 -> V_41 ;
V_40 -> V_42 &= ~ V_43 ;
error = F_17 ( V_18 , V_40 ) ;
if ( error )
return error ;
F_18 ( V_18 , V_40 ) ;
F_19 ( V_18 ) ;
return 0 ;
}
static unsigned int F_20 ( struct V_19 * V_19 , T_1 * V_44 )
{
int V_45 = 0 ;
struct V_18 * V_18 = F_21 ( V_19 ) ;
struct V_23 * V_24 = F_11 ( V_18 ) ;
F_22 ( V_19 , & V_24 -> V_33 . V_46 , V_44 ) ;
F_23 ( & V_24 -> V_33 . V_47 ) ;
if ( V_24 -> V_33 . V_48 & V_49 )
V_45 = V_50 | V_51 ;
F_24 ( & V_24 -> V_33 . V_47 ) ;
return V_45 ;
}
static T_2 F_25 ( struct V_19 * V_52 ,
char T_3 * V_53 ,
T_4 V_54 ,
T_5 * V_55 )
{
int V_56 ;
T_2 V_57 , V_58 ;
char * V_59 ;
struct V_18 * V_18 = F_21 ( V_52 ) ;
F_9 ( 0 , L_4 ,
V_18 -> V_26 , V_54 , * V_55 ) ;
if ( * V_55 >= F_26 ( V_18 ) )
return 0 ;
if ( ! V_54 )
return 0 ;
if ( ! F_27 ( V_60 , V_53 , V_54 ) )
return - V_61 ;
if ( ( V_54 + * V_55 ) > F_26 ( V_18 ) )
V_57 = F_26 ( V_18 ) - * V_55 ;
else
V_57 = V_54 ;
V_59 = F_10 ( V_57 , V_30 ) ;
if ( ! V_59 )
return - V_31 ;
V_58 = F_28 ( V_18 , V_59 , V_57 ) ;
if ( V_58 ) {
F_29 ( V_58 != V_57 ) ;
V_56 = F_30 ( V_53 , V_59 , V_57 ) ;
V_57 -= V_56 ;
} else
V_57 = 0 ;
F_13 ( V_59 ) ;
* V_55 = * V_55 + V_57 ;
F_9 ( 0 , L_5 , V_57 ) ;
return V_57 ;
}
static T_2 F_31 ( struct V_19 * V_52 ,
const char T_3 * V_53 ,
T_4 V_54 ,
T_5 * V_55 )
{
int V_56 ;
T_2 V_62 ;
char * V_59 ;
struct V_18 * V_18 = F_21 ( V_52 ) ;
F_9 ( 0 , L_4 ,
V_18 -> V_26 , V_54 , * V_55 ) ;
if ( * V_55 >= F_26 ( V_18 ) )
return - V_63 ;
if ( ! V_54 )
return 0 ;
if ( ! F_27 ( V_64 , V_53 , V_54 ) )
return - V_61 ;
if ( ( V_54 + * V_55 ) > F_26 ( V_18 ) )
V_62 = F_26 ( V_18 ) - * V_55 ;
else
V_62 = V_54 - * V_55 ;
V_59 = F_10 ( V_62 , V_30 ) ;
if ( ! V_59 )
return - V_31 ;
V_56 = F_32 ( V_59 , V_53 , V_62 ) ;
V_62 -= V_56 ;
if ( V_62 )
F_33 ( V_18 , V_59 , V_62 ) ;
F_13 ( V_59 ) ;
* V_55 = * V_55 + V_62 ;
F_9 ( 0 , L_6 , V_62 ) ;
return V_62 ;
}
static void F_34 ( void * V_65 )
{
struct V_23 * V_24 =
(struct V_23 * ) V_65 ;
V_24 -> V_66 = NULL ;
V_24 -> V_67 = NULL ;
F_35 ( & V_24 -> V_68 ) ;
}
static struct V_18 * F_36 ( struct V_69 * V_70 )
{
struct V_23 * V_24 ;
V_24 = F_37 ( V_71 , V_30 ) ;
if ( ! V_24 )
return NULL ;
return & V_24 -> V_68 ;
}
static void F_38 ( struct V_72 * V_73 )
{
struct V_18 * V_18 = F_39 ( V_73 , struct V_18 , V_74 ) ;
F_40 ( V_71 , F_11 ( V_18 ) ) ;
}
static void F_41 ( struct V_18 * V_18 )
{
F_42 ( & V_18 -> V_74 , F_38 ) ;
}
static void F_43 ( struct V_18 * V_18 )
{
int V_20 ;
struct V_23 * V_24 ;
F_44 ( V_18 ) ;
F_9 ( 0 , L_7 , V_18 -> V_26 ) ;
V_24 = F_11 ( V_18 ) ;
if ( F_45 ( V_18 -> V_25 ) ) {
V_20 = F_46 ( & V_24 -> V_33 ) ;
if ( V_20 < 0 )
F_47 ( V_20 ) ;
F_48 ( V_24 -> V_67 ) ;
goto V_75;
}
F_9 ( 0 , L_8 , V_24 -> V_66 ) ;
if ( V_24 -> V_66 )
F_49 ( V_24 -> V_66 ) ;
V_75:
V_24 -> V_67 = NULL ;
V_24 -> V_66 = NULL ;
}
static struct V_18 * F_50 ( struct V_69 * V_70 )
{
struct V_18 * V_18 = F_51 ( V_70 ) ;
T_6 V_76 = V_77 | 0755 ;
if ( V_18 ) {
V_18 -> V_26 = F_52 () ;
F_53 ( V_18 , NULL , V_76 ) ;
V_18 -> V_78 = V_18 -> V_79 = V_18 -> V_80 = V_81 ;
F_54 ( V_18 ) ;
V_18 -> V_82 = & V_83 ;
V_18 -> V_84 = & V_85 ;
}
return V_18 ;
}
static struct V_18 * F_55 ( struct V_18 * V_86 ,
struct V_38 * V_38 ,
T_6 V_76 )
{
struct V_69 * V_70 = V_86 -> V_87 ;
struct V_18 * V_18 = F_51 ( V_70 ) ;
struct V_23 * V_24 ;
if ( ! V_18 )
return NULL ;
V_18 -> V_26 = F_52 () ;
F_53 ( V_18 , V_86 , V_76 ) ;
V_18 -> V_78 = V_18 -> V_79 = V_18 -> V_80 = V_81 ;
V_24 = F_11 ( V_18 ) ;
V_24 -> V_66 = F_11 ( V_86 ) -> V_66 ;
switch ( V_76 & V_88 ) {
default:
F_8 () ;
break;
case V_89 :
V_18 -> V_84 = & V_90 ;
V_18 -> V_82 = & V_91 ;
F_56 ( V_18 , V_92 ) ;
F_57 ( & V_24 -> V_33 , V_38 ) ;
V_24 -> V_67 = F_58 ( V_86 ) ;
F_29 ( ! V_24 -> V_67 ) ;
break;
case V_77 :
V_18 -> V_84 = & V_93 ;
V_18 -> V_82 = & V_83 ;
F_54 ( V_18 ) ;
break;
}
return V_18 ;
}
static int F_59 ( struct V_18 * V_94 ,
struct V_38 * V_38 ,
T_6 V_76 )
{
int V_20 ;
struct V_18 * V_18 = NULL ;
struct V_95 * V_96 = & V_38 -> V_97 ;
struct V_23 * V_24 ;
struct V_98 * V_99 ;
F_9 ( 0 , L_9 , V_96 -> V_100 , V_96 -> V_5 ) ;
if ( V_96 -> V_100 >= V_101 ) {
V_20 = - V_6 ;
F_9 ( V_102 , L_10 ) ;
goto V_28;
}
V_18 = F_55 ( V_94 , V_38 , V_76 | V_77 ) ;
if ( ! V_18 ) {
V_20 = - V_31 ;
F_47 ( V_20 ) ;
goto V_28;
}
V_24 = F_11 ( V_18 ) ;
V_99 = F_60 ( V_96 ) ;
if ( F_61 ( V_99 ) ) {
V_20 = F_62 ( V_99 ) ;
F_9 ( V_102 , L_11 ,
V_20 , V_96 -> V_100 , V_96 -> V_5 ) ;
goto V_28;
}
V_24 -> V_66 = V_99 ;
F_54 ( V_94 ) ;
F_63 ( V_38 , V_18 ) ;
F_64 ( V_38 ) ;
V_20 = 0 ;
V_28:
if ( V_20 < 0 )
F_48 ( V_18 ) ;
return V_20 ;
}
static int F_65 ( struct V_18 * V_94 ,
struct V_38 * V_38 ,
T_6 V_76 ,
bool V_103 )
{
int V_20 = 0 ;
struct V_18 * V_18 ;
struct V_95 * V_5 = & V_38 -> V_97 ;
F_9 ( 0 , L_12 , V_5 -> V_100 , V_5 -> V_5 ) ;
if ( V_5 -> V_100 >= V_104 ||
V_5 -> V_5 [ 0 ] == '$' ) {
V_20 = - V_6 ;
F_9 ( V_102 , L_13 , V_5 -> V_100 ,
V_5 -> V_5 ) ;
goto V_28;
}
V_18 = F_55 ( V_94 , V_38 , V_76 | V_89 ) ;
if ( ! V_18 ) {
V_20 = - V_31 ;
F_47 ( V_20 ) ;
goto V_28;
}
F_63 ( V_38 , V_18 ) ;
F_64 ( V_38 ) ;
V_28:
return V_20 ;
}
static int F_66 ( struct V_18 * V_94 ,
struct V_38 * V_38 )
{
int V_20 ;
struct V_18 * V_18 = V_38 -> V_41 ;
F_9 ( 0 , L_14 , V_18 -> V_26 ) ;
V_20 = F_46 ( & F_11 ( V_18 ) -> V_33 ) ;
if ( V_20 < 0 ) {
F_9 ( V_102 , L_15 ,
V_38 , V_20 ) ;
goto V_28;
}
V_20 = F_67 ( V_94 , V_38 ) ;
V_28:
return V_20 ;
}
static int F_68 ( struct V_69 * V_70 ,
void * V_105 ,
int V_106 )
{
V_70 -> V_107 = V_108 ;
V_70 -> V_109 = V_110 ;
V_70 -> V_111 = V_112 ;
V_70 -> V_113 = V_114 ;
V_70 -> V_115 = & V_116 ;
V_70 -> V_117 = F_69 ( F_50 ( V_70 ) ) ;
if ( ! V_70 -> V_117 )
return - V_31 ;
return 0 ;
}
static struct V_38 * F_70 ( struct V_118 * V_119 ,
int V_11 , const char * V_120 , void * V_105 )
{
return F_71 ( V_119 , V_11 , V_105 , F_68 ) ;
}
static int T_7 F_72 ( void )
{
int V_20 ;
int V_121 = 0 , V_122 = 0 ;
V_71 = F_73 ( L_16 ,
sizeof( struct V_23 ) ,
0 , ( V_123 | V_124 |
V_125 ) ,
F_34 ) ;
if ( ! V_71 ) {
V_20 = - V_31 ;
goto V_28;
}
V_121 = 1 ;
V_126 = F_74 ( L_17 ) ;
if ( ! V_126 ) {
V_20 = - V_31 ;
goto V_28;
}
V_122 = 1 ;
F_75 () ;
V_20 = F_76 ( & V_127 ) ;
V_28:
if ( V_20 ) {
if ( V_121 )
F_77 ( V_71 ) ;
if ( V_122 )
F_78 ( V_126 ) ;
} else
F_2 ( L_18 ) ;
return V_20 ;
}
static void T_8 F_79 ( void )
{
F_80 ( & V_127 ) ;
F_81 ( V_126 ) ;
F_78 ( V_126 ) ;
F_82 () ;
F_77 ( V_71 ) ;
}
