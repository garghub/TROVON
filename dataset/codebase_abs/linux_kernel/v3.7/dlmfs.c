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
struct V_18 * V_18 = V_19 -> V_46 . V_38 -> V_41 ;
struct V_23 * V_24 = F_11 ( V_18 ) ;
F_21 ( V_19 , & V_24 -> V_33 . V_47 , V_44 ) ;
F_22 ( & V_24 -> V_33 . V_48 ) ;
if ( V_24 -> V_33 . V_49 & V_50 )
V_45 = V_51 | V_52 ;
F_23 ( & V_24 -> V_33 . V_48 ) ;
return V_45 ;
}
static T_2 F_24 ( struct V_19 * V_53 ,
char T_3 * V_54 ,
T_4 V_55 ,
T_5 * V_56 )
{
int V_57 ;
T_2 V_58 , V_59 ;
char * V_60 ;
struct V_18 * V_18 = V_53 -> V_46 . V_38 -> V_41 ;
F_9 ( 0 , L_4 ,
V_18 -> V_26 , V_55 , * V_56 ) ;
if ( * V_56 >= F_25 ( V_18 ) )
return 0 ;
if ( ! V_55 )
return 0 ;
if ( ! F_26 ( V_61 , V_54 , V_55 ) )
return - V_62 ;
if ( ( V_55 + * V_56 ) > F_25 ( V_18 ) )
V_58 = F_25 ( V_18 ) - * V_56 ;
else
V_58 = V_55 ;
V_60 = F_10 ( V_58 , V_30 ) ;
if ( ! V_60 )
return - V_31 ;
V_59 = F_27 ( V_18 , V_60 , V_58 ) ;
if ( V_59 ) {
F_28 ( V_59 != V_58 ) ;
V_57 = F_29 ( V_54 , V_60 , V_58 ) ;
V_58 -= V_57 ;
} else
V_58 = 0 ;
F_13 ( V_60 ) ;
* V_56 = * V_56 + V_58 ;
F_9 ( 0 , L_5 , V_58 ) ;
return V_58 ;
}
static T_2 F_30 ( struct V_19 * V_53 ,
const char T_3 * V_54 ,
T_4 V_55 ,
T_5 * V_56 )
{
int V_57 ;
T_2 V_63 ;
char * V_60 ;
struct V_18 * V_18 = V_53 -> V_46 . V_38 -> V_41 ;
F_9 ( 0 , L_4 ,
V_18 -> V_26 , V_55 , * V_56 ) ;
if ( * V_56 >= F_25 ( V_18 ) )
return - V_64 ;
if ( ! V_55 )
return 0 ;
if ( ! F_26 ( V_65 , V_54 , V_55 ) )
return - V_62 ;
if ( ( V_55 + * V_56 ) > F_25 ( V_18 ) )
V_63 = F_25 ( V_18 ) - * V_56 ;
else
V_63 = V_55 - * V_56 ;
V_60 = F_10 ( V_63 , V_30 ) ;
if ( ! V_60 )
return - V_31 ;
V_57 = F_31 ( V_60 , V_54 , V_63 ) ;
V_63 -= V_57 ;
if ( V_63 )
F_32 ( V_18 , V_60 , V_63 ) ;
F_13 ( V_60 ) ;
* V_56 = * V_56 + V_63 ;
F_9 ( 0 , L_6 , V_63 ) ;
return V_63 ;
}
static void F_33 ( void * V_66 )
{
struct V_23 * V_24 =
(struct V_23 * ) V_66 ;
V_24 -> V_67 = NULL ;
V_24 -> V_68 = NULL ;
F_34 ( & V_24 -> V_69 ) ;
}
static struct V_18 * F_35 ( struct V_70 * V_71 )
{
struct V_23 * V_24 ;
V_24 = F_36 ( V_72 , V_30 ) ;
if ( ! V_24 )
return NULL ;
return & V_24 -> V_69 ;
}
static void F_37 ( struct V_73 * V_74 )
{
struct V_18 * V_18 = F_38 ( V_74 , struct V_18 , V_75 ) ;
F_39 ( V_72 , F_11 ( V_18 ) ) ;
}
static void F_40 ( struct V_18 * V_18 )
{
F_41 ( & V_18 -> V_75 , F_37 ) ;
}
static void F_42 ( struct V_18 * V_18 )
{
int V_20 ;
struct V_23 * V_24 ;
F_43 ( V_18 ) ;
F_9 ( 0 , L_7 , V_18 -> V_26 ) ;
V_24 = F_11 ( V_18 ) ;
if ( F_44 ( V_18 -> V_25 ) ) {
V_20 = F_45 ( & V_24 -> V_33 ) ;
if ( V_20 < 0 )
F_46 ( V_20 ) ;
F_47 ( V_24 -> V_68 ) ;
goto V_76;
}
F_9 ( 0 , L_8 , V_24 -> V_67 ) ;
if ( V_24 -> V_67 )
F_48 ( V_24 -> V_67 ) ;
V_76:
V_24 -> V_68 = NULL ;
V_24 -> V_67 = NULL ;
}
static struct V_18 * F_49 ( struct V_70 * V_71 )
{
struct V_18 * V_18 = F_50 ( V_71 ) ;
T_6 V_77 = V_78 | 0755 ;
struct V_23 * V_24 ;
if ( V_18 ) {
V_24 = F_11 ( V_18 ) ;
V_18 -> V_26 = F_51 () ;
F_52 ( V_18 , NULL , V_77 ) ;
V_18 -> V_79 -> V_80 = & V_81 ;
V_18 -> V_82 = V_18 -> V_83 = V_18 -> V_84 = V_85 ;
F_53 ( V_18 ) ;
V_18 -> V_86 = & V_87 ;
V_18 -> V_88 = & V_89 ;
}
return V_18 ;
}
static struct V_18 * F_54 ( struct V_18 * V_90 ,
struct V_38 * V_38 ,
T_6 V_77 )
{
struct V_70 * V_71 = V_90 -> V_91 ;
struct V_18 * V_18 = F_50 ( V_71 ) ;
struct V_23 * V_24 ;
if ( ! V_18 )
return NULL ;
V_18 -> V_26 = F_51 () ;
F_52 ( V_18 , V_90 , V_77 ) ;
V_18 -> V_79 -> V_80 = & V_81 ;
V_18 -> V_82 = V_18 -> V_83 = V_18 -> V_84 = V_85 ;
V_24 = F_11 ( V_18 ) ;
V_24 -> V_67 = F_11 ( V_90 ) -> V_67 ;
switch ( V_77 & V_92 ) {
default:
F_8 () ;
break;
case V_93 :
V_18 -> V_88 = & V_94 ;
V_18 -> V_86 = & V_95 ;
F_55 ( V_18 , V_96 ) ;
F_56 ( & V_24 -> V_33 , V_38 ) ;
V_24 -> V_68 = F_57 ( V_90 ) ;
F_28 ( ! V_24 -> V_68 ) ;
break;
case V_78 :
V_18 -> V_88 = & V_97 ;
V_18 -> V_86 = & V_87 ;
F_53 ( V_18 ) ;
break;
}
return V_18 ;
}
static int F_58 ( struct V_18 * V_98 ,
struct V_38 * V_38 ,
T_6 V_77 )
{
int V_20 ;
struct V_18 * V_18 = NULL ;
struct V_99 * V_100 = & V_38 -> V_101 ;
struct V_23 * V_24 ;
struct V_102 * V_103 ;
F_9 ( 0 , L_9 , V_100 -> V_104 , V_100 -> V_5 ) ;
if ( V_100 -> V_104 >= V_105 ) {
V_20 = - V_6 ;
F_9 ( V_106 , L_10 ) ;
goto V_28;
}
V_18 = F_54 ( V_98 , V_38 , V_77 | V_78 ) ;
if ( ! V_18 ) {
V_20 = - V_31 ;
F_46 ( V_20 ) ;
goto V_28;
}
V_24 = F_11 ( V_18 ) ;
V_103 = F_59 ( V_100 ) ;
if ( F_60 ( V_103 ) ) {
V_20 = F_61 ( V_103 ) ;
F_9 ( V_106 , L_11 ,
V_20 , V_100 -> V_104 , V_100 -> V_5 ) ;
goto V_28;
}
V_24 -> V_67 = V_103 ;
F_53 ( V_98 ) ;
F_62 ( V_38 , V_18 ) ;
F_63 ( V_38 ) ;
V_20 = 0 ;
V_28:
if ( V_20 < 0 )
F_47 ( V_18 ) ;
return V_20 ;
}
static int F_64 ( struct V_18 * V_98 ,
struct V_38 * V_38 ,
T_6 V_77 ,
bool V_107 )
{
int V_20 = 0 ;
struct V_18 * V_18 ;
struct V_99 * V_5 = & V_38 -> V_101 ;
F_9 ( 0 , L_12 , V_5 -> V_104 , V_5 -> V_5 ) ;
if ( V_5 -> V_104 >= V_108 ||
V_5 -> V_5 [ 0 ] == '$' ) {
V_20 = - V_6 ;
F_9 ( V_106 , L_13 , V_5 -> V_104 ,
V_5 -> V_5 ) ;
goto V_28;
}
V_18 = F_54 ( V_98 , V_38 , V_77 | V_93 ) ;
if ( ! V_18 ) {
V_20 = - V_31 ;
F_46 ( V_20 ) ;
goto V_28;
}
F_62 ( V_38 , V_18 ) ;
F_63 ( V_38 ) ;
V_28:
return V_20 ;
}
static int F_65 ( struct V_18 * V_98 ,
struct V_38 * V_38 )
{
int V_20 ;
struct V_18 * V_18 = V_38 -> V_41 ;
F_9 ( 0 , L_14 , V_18 -> V_26 ) ;
V_20 = F_45 ( & F_11 ( V_18 ) -> V_33 ) ;
if ( V_20 < 0 ) {
F_9 ( V_106 , L_15 ,
V_38 -> V_101 . V_104 , V_38 -> V_101 . V_5 , V_20 ) ;
goto V_28;
}
V_20 = F_66 ( V_98 , V_38 ) ;
V_28:
return V_20 ;
}
static int F_67 ( struct V_70 * V_71 ,
void * V_109 ,
int V_110 )
{
V_71 -> V_111 = V_112 ;
V_71 -> V_113 = V_114 ;
V_71 -> V_115 = V_116 ;
V_71 -> V_117 = V_118 ;
V_71 -> V_119 = & V_120 ;
V_71 -> V_121 = F_68 ( F_49 ( V_71 ) ) ;
if ( ! V_71 -> V_121 )
return - V_31 ;
return 0 ;
}
static struct V_38 * F_69 ( struct V_122 * V_123 ,
int V_11 , const char * V_124 , void * V_109 )
{
return F_70 ( V_123 , V_11 , V_109 , F_67 ) ;
}
static int T_7 F_71 ( void )
{
int V_20 ;
int V_125 = 0 , V_126 = 0 ;
F_72 () ;
V_20 = F_73 ( & V_81 ) ;
if ( V_20 )
return V_20 ;
V_72 = F_74 ( L_16 ,
sizeof( struct V_23 ) ,
0 , ( V_127 | V_128 |
V_129 ) ,
F_33 ) ;
if ( ! V_72 ) {
V_20 = - V_31 ;
goto V_28;
}
V_125 = 1 ;
V_130 = F_75 ( L_17 ) ;
if ( ! V_130 ) {
V_20 = - V_31 ;
goto V_28;
}
V_126 = 1 ;
F_76 () ;
V_20 = F_77 ( & V_131 ) ;
V_28:
if ( V_20 ) {
if ( V_125 )
F_78 ( V_72 ) ;
if ( V_126 )
F_79 ( V_130 ) ;
F_80 ( & V_81 ) ;
} else
F_2 ( L_18 ) ;
return V_20 ;
}
static void T_8 F_81 ( void )
{
F_82 ( & V_131 ) ;
F_83 ( V_130 ) ;
F_79 ( V_130 ) ;
F_84 () ;
F_78 ( V_72 ) ;
F_80 ( & V_81 ) ;
}
