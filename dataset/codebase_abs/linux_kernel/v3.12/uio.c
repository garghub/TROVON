static T_1 F_1 ( struct V_1 * V_2 , char * V_3 )
{
if ( F_2 ( ! V_2 -> V_4 ) )
V_2 -> V_4 = L_1 ;
return sprintf ( V_3 , L_2 , V_2 -> V_4 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , char * V_3 )
{
return sprintf ( V_3 , L_3 , ( unsigned long long ) V_2 -> V_5 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 , char * V_3 )
{
return sprintf ( V_3 , L_4 , V_2 -> V_6 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , char * V_3 )
{
return sprintf ( V_3 , L_3 , ( unsigned long long ) V_2 -> V_5 & ~ V_7 ) ;
}
static void F_6 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_7 ( V_9 ) ;
F_8 ( V_11 ) ;
}
static T_1 F_9 ( struct V_8 * V_9 , struct V_12 * V_13 ,
char * V_3 )
{
struct V_10 * V_11 = F_7 ( V_9 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_14 * V_15 ;
V_15 = F_10 ( V_13 , struct V_14 , V_13 ) ;
if ( ! V_15 -> V_16 )
return - V_17 ;
return V_15 -> V_16 ( V_2 , V_3 ) ;
}
static T_1 F_11 ( struct V_18 * V_19 , char * V_3 )
{
if ( F_2 ( ! V_19 -> V_4 ) )
V_19 -> V_4 = L_1 ;
return sprintf ( V_3 , L_2 , V_19 -> V_4 ) ;
}
static T_1 F_12 ( struct V_18 * V_19 , char * V_3 )
{
return sprintf ( V_3 , L_4 , V_19 -> V_20 ) ;
}
static T_1 F_13 ( struct V_18 * V_19 , char * V_3 )
{
return sprintf ( V_3 , L_4 , V_19 -> V_6 ) ;
}
static T_1 F_14 ( struct V_18 * V_19 , char * V_3 )
{
const char * V_21 [] = { L_5 , L_6 , L_7 , L_8 } ;
if ( ( V_19 -> V_22 < 0 ) || ( V_19 -> V_22 > V_23 ) )
return - V_24 ;
return sprintf ( V_3 , L_9 , V_21 [ V_19 -> V_22 ] ) ;
}
static void F_15 ( struct V_8 * V_9 )
{
struct V_25 * V_26 = F_16 ( V_9 ) ;
F_8 ( V_26 ) ;
}
static T_1 F_17 ( struct V_8 * V_9 , struct V_12 * V_13 ,
char * V_3 )
{
struct V_25 * V_26 = F_16 ( V_9 ) ;
struct V_18 * V_19 = V_26 -> V_19 ;
struct V_27 * V_15 ;
V_15 = F_10 ( V_13 , struct V_27 , V_13 ) ;
if ( ! V_15 -> V_16 )
return - V_17 ;
return V_15 -> V_16 ( V_19 , V_3 ) ;
}
static T_1 F_18 ( struct V_28 * V_29 ,
struct V_30 * V_13 , char * V_3 )
{
struct V_31 * V_32 = F_19 ( V_29 ) ;
return sprintf ( V_3 , L_2 , V_32 -> V_33 -> V_4 ) ;
}
static T_1 F_20 ( struct V_28 * V_29 ,
struct V_30 * V_13 , char * V_3 )
{
struct V_31 * V_32 = F_19 ( V_29 ) ;
return sprintf ( V_3 , L_2 , V_32 -> V_33 -> V_34 ) ;
}
static T_1 F_21 ( struct V_28 * V_29 ,
struct V_30 * V_13 , char * V_3 )
{
struct V_31 * V_32 = F_19 ( V_29 ) ;
return sprintf ( V_3 , L_10 , ( unsigned int ) F_22 ( & V_32 -> V_35 ) ) ;
}
static int F_23 ( struct V_31 * V_32 )
{
int V_36 ;
int V_37 , V_38 ;
int V_39 = 0 ;
int V_40 = 0 ;
struct V_1 * V_2 ;
struct V_10 * V_11 ;
struct V_18 * V_19 ;
struct V_25 * V_26 ;
for ( V_37 = 0 ; V_37 < V_41 ; V_37 ++ ) {
V_2 = & V_32 -> V_33 -> V_2 [ V_37 ] ;
if ( V_2 -> V_6 == 0 )
break;
if ( ! V_39 ) {
V_39 = 1 ;
V_32 -> V_42 = F_24 ( L_11 ,
& V_32 -> V_29 -> V_9 ) ;
if ( ! V_32 -> V_42 )
goto V_43;
}
V_11 = F_25 ( sizeof( * V_11 ) , V_44 ) ;
if ( ! V_11 )
goto V_43;
F_26 ( & V_11 -> V_9 , & V_45 ) ;
V_11 -> V_2 = V_2 ;
V_2 -> V_11 = V_11 ;
V_36 = F_27 ( & V_11 -> V_9 , V_32 -> V_42 , L_12 , V_37 ) ;
if ( V_36 )
goto V_43;
V_36 = F_28 ( & V_11 -> V_9 , V_46 ) ;
if ( V_36 )
goto V_43;
}
for ( V_38 = 0 ; V_38 < V_47 ; V_38 ++ ) {
V_19 = & V_32 -> V_33 -> V_19 [ V_38 ] ;
if ( V_19 -> V_6 == 0 )
break;
if ( ! V_40 ) {
V_40 = 1 ;
V_32 -> V_48 = F_24 ( L_13 ,
& V_32 -> V_29 -> V_9 ) ;
if ( ! V_32 -> V_48 )
goto V_49;
}
V_26 = F_25 ( sizeof( * V_26 ) , V_44 ) ;
if ( ! V_26 )
goto V_49;
F_26 ( & V_26 -> V_9 , & V_50 ) ;
V_26 -> V_19 = V_19 ;
V_19 -> V_26 = V_26 ;
V_36 = F_27 ( & V_26 -> V_9 , V_32 -> V_48 ,
L_14 , V_38 ) ;
if ( V_36 )
goto V_49;
V_36 = F_28 ( & V_26 -> V_9 , V_46 ) ;
if ( V_36 )
goto V_49;
}
return 0 ;
V_49:
for ( V_38 -- ; V_38 >= 0 ; V_38 -- ) {
V_19 = & V_32 -> V_33 -> V_19 [ V_38 ] ;
V_26 = V_19 -> V_26 ;
F_29 ( & V_26 -> V_9 ) ;
}
F_29 ( V_32 -> V_48 ) ;
V_43:
for ( V_37 -- ; V_37 >= 0 ; V_37 -- ) {
V_2 = & V_32 -> V_33 -> V_2 [ V_37 ] ;
V_11 = V_2 -> V_11 ;
F_29 ( & V_11 -> V_9 ) ;
}
F_29 ( V_32 -> V_42 ) ;
F_30 ( V_32 -> V_29 , L_15 , V_36 ) ;
return V_36 ;
}
static void F_31 ( struct V_31 * V_32 )
{
int V_51 ;
struct V_1 * V_2 ;
struct V_18 * V_19 ;
for ( V_51 = 0 ; V_51 < V_41 ; V_51 ++ ) {
V_2 = & V_32 -> V_33 -> V_2 [ V_51 ] ;
if ( V_2 -> V_6 == 0 )
break;
F_29 ( & V_2 -> V_11 -> V_9 ) ;
}
F_29 ( V_32 -> V_42 ) ;
for ( V_51 = 0 ; V_51 < V_47 ; V_51 ++ ) {
V_19 = & V_32 -> V_33 -> V_19 [ V_51 ] ;
if ( V_19 -> V_6 == 0 )
break;
F_29 ( & V_19 -> V_26 -> V_9 ) ;
}
F_29 ( V_32 -> V_48 ) ;
}
static int F_32 ( struct V_31 * V_32 )
{
int V_52 = - V_53 ;
F_33 ( & V_54 ) ;
V_52 = F_34 ( & V_55 , V_32 , 0 , V_56 , V_44 ) ;
if ( V_52 >= 0 ) {
V_32 -> V_57 = V_52 ;
V_52 = 0 ;
} else if ( V_52 == - V_58 ) {
F_30 ( V_32 -> V_29 , L_16 ) ;
V_52 = - V_24 ;
}
F_35 ( & V_54 ) ;
return V_52 ;
}
static void F_36 ( struct V_31 * V_32 )
{
F_33 ( & V_54 ) ;
F_37 ( & V_55 , V_32 -> V_57 ) ;
F_35 ( & V_54 ) ;
}
void F_38 ( struct V_59 * V_33 )
{
struct V_31 * V_32 = V_33 -> V_60 ;
F_39 ( & V_32 -> V_35 ) ;
F_40 ( & V_32 -> V_61 ) ;
F_41 ( & V_32 -> V_62 , V_63 , V_64 ) ;
}
static T_2 F_42 ( int V_65 , void * V_66 )
{
struct V_31 * V_32 = (struct V_31 * ) V_66 ;
T_2 V_36 = V_32 -> V_33 -> V_67 ( V_65 , V_32 -> V_33 ) ;
if ( V_36 == V_68 )
F_38 ( V_32 -> V_33 ) ;
return V_36 ;
}
static int F_43 ( struct V_69 * V_69 , struct V_70 * V_71 )
{
struct V_31 * V_32 ;
struct V_72 * V_73 ;
int V_36 = 0 ;
F_33 ( & V_54 ) ;
V_32 = F_44 ( & V_55 , F_45 ( V_69 ) ) ;
F_35 ( & V_54 ) ;
if ( ! V_32 ) {
V_36 = - V_74 ;
goto V_75;
}
if ( ! F_46 ( V_32 -> V_76 ) ) {
V_36 = - V_74 ;
goto V_75;
}
V_73 = F_47 ( sizeof( * V_73 ) , V_44 ) ;
if ( ! V_73 ) {
V_36 = - V_53 ;
goto V_77;
}
V_73 -> V_29 = V_32 ;
V_73 -> V_78 = F_22 ( & V_32 -> V_35 ) ;
V_71 -> V_79 = V_73 ;
if ( V_32 -> V_33 -> V_80 ) {
V_36 = V_32 -> V_33 -> V_80 ( V_32 -> V_33 , V_69 ) ;
if ( V_36 )
goto V_81;
}
return 0 ;
V_81:
F_8 ( V_73 ) ;
V_77:
F_48 ( V_32 -> V_76 ) ;
V_75:
return V_36 ;
}
static int F_49 ( int V_82 , struct V_70 * V_71 , int V_83 )
{
struct V_72 * V_73 = V_71 -> V_79 ;
struct V_31 * V_32 = V_73 -> V_29 ;
return F_50 ( V_82 , V_71 , V_83 , & V_32 -> V_62 ) ;
}
static int F_51 ( struct V_69 * V_69 , struct V_70 * V_71 )
{
int V_36 = 0 ;
struct V_72 * V_73 = V_71 -> V_79 ;
struct V_31 * V_32 = V_73 -> V_29 ;
if ( V_32 -> V_33 -> V_84 )
V_36 = V_32 -> V_33 -> V_84 ( V_32 -> V_33 , V_69 ) ;
F_48 ( V_32 -> V_76 ) ;
F_8 ( V_73 ) ;
return V_36 ;
}
static unsigned int F_52 ( struct V_70 * V_71 , T_3 * V_61 )
{
struct V_72 * V_73 = V_71 -> V_79 ;
struct V_31 * V_32 = V_73 -> V_29 ;
if ( ! V_32 -> V_33 -> V_65 )
return - V_17 ;
F_53 ( V_71 , & V_32 -> V_61 , V_61 ) ;
if ( V_73 -> V_78 != F_22 ( & V_32 -> V_35 ) )
return V_85 | V_86 ;
return 0 ;
}
static T_1 F_54 ( struct V_70 * V_71 , char T_4 * V_3 ,
T_5 V_87 , T_6 * V_88 )
{
struct V_72 * V_73 = V_71 -> V_79 ;
struct V_31 * V_32 = V_73 -> V_29 ;
F_55 ( V_61 , V_89 ) ;
T_1 V_52 ;
T_7 V_78 ;
if ( ! V_32 -> V_33 -> V_65 )
return - V_17 ;
if ( V_87 != sizeof( T_7 ) )
return - V_24 ;
F_56 ( & V_32 -> V_61 , & V_61 ) ;
do {
F_57 ( V_90 ) ;
V_78 = F_22 ( & V_32 -> V_35 ) ;
if ( V_78 != V_73 -> V_78 ) {
if ( F_58 ( V_3 , & V_78 , V_87 ) )
V_52 = - V_91 ;
else {
V_73 -> V_78 = V_78 ;
V_52 = V_87 ;
}
break;
}
if ( V_71 -> V_92 & V_93 ) {
V_52 = - V_94 ;
break;
}
if ( F_59 ( V_89 ) ) {
V_52 = - V_95 ;
break;
}
F_60 () ;
} while ( 1 );
F_61 ( V_96 ) ;
F_62 ( & V_32 -> V_61 , & V_61 ) ;
return V_52 ;
}
static T_1 F_63 ( struct V_70 * V_71 , const char T_4 * V_3 ,
T_5 V_87 , T_6 * V_88 )
{
struct V_72 * V_73 = V_71 -> V_79 ;
struct V_31 * V_32 = V_73 -> V_29 ;
T_1 V_52 ;
T_7 V_97 ;
if ( ! V_32 -> V_33 -> V_65 )
return - V_17 ;
if ( V_87 != sizeof( T_7 ) )
return - V_24 ;
if ( ! V_32 -> V_33 -> V_98 )
return - V_99 ;
if ( F_64 ( & V_97 , V_3 , V_87 ) )
return - V_91 ;
V_52 = V_32 -> V_33 -> V_98 ( V_32 -> V_33 , V_97 ) ;
return V_52 ? V_52 : sizeof( T_7 ) ;
}
static int F_65 ( struct V_100 * V_101 )
{
struct V_31 * V_32 = V_101 -> V_102 ;
if ( V_101 -> V_103 < V_41 ) {
if ( V_32 -> V_33 -> V_2 [ V_101 -> V_103 ] . V_6 == 0 )
return - 1 ;
return ( int ) V_101 -> V_103 ;
}
return - 1 ;
}
static int F_66 ( struct V_100 * V_101 , struct V_104 * V_105 )
{
struct V_31 * V_32 = V_101 -> V_102 ;
struct V_106 * V_106 ;
unsigned long V_107 ;
int V_37 = F_65 ( V_101 ) ;
if ( V_37 < 0 )
return V_108 ;
V_107 = ( V_105 -> V_109 - V_37 ) << V_110 ;
if ( V_32 -> V_33 -> V_2 [ V_37 ] . V_111 == V_112 )
V_106 = F_67 ( V_32 -> V_33 -> V_2 [ V_37 ] . V_5 + V_107 ) ;
else
V_106 = F_68 ( ( void * ) ( unsigned long ) V_32 -> V_33 -> V_2 [ V_37 ] . V_5 + V_107 ) ;
F_69 ( V_106 ) ;
V_105 -> V_106 = V_106 ;
return 0 ;
}
static int F_70 ( struct V_100 * V_101 )
{
V_101 -> V_113 |= V_114 | V_115 ;
V_101 -> V_116 = & V_117 ;
return 0 ;
}
static int F_71 ( struct V_100 * V_101 )
{
struct V_31 * V_32 = V_101 -> V_102 ;
int V_37 = F_65 ( V_101 ) ;
struct V_1 * V_2 ;
if ( V_37 < 0 )
return - V_24 ;
V_2 = V_32 -> V_33 -> V_2 + V_37 ;
if ( V_101 -> V_118 - V_101 -> V_119 > V_2 -> V_6 )
return - V_24 ;
V_101 -> V_116 = & V_120 ;
V_101 -> V_121 = F_72 ( V_101 -> V_121 ) ;
return F_73 ( V_101 ,
V_101 -> V_119 ,
V_2 -> V_5 >> V_110 ,
V_101 -> V_118 - V_101 -> V_119 ,
V_101 -> V_121 ) ;
}
static int F_74 ( struct V_70 * V_71 , struct V_100 * V_101 )
{
struct V_72 * V_73 = V_71 -> V_79 ;
struct V_31 * V_32 = V_73 -> V_29 ;
int V_37 ;
unsigned long V_122 , V_123 ;
int V_36 = 0 ;
if ( V_101 -> V_118 < V_101 -> V_119 )
return - V_24 ;
V_101 -> V_102 = V_32 ;
V_37 = F_65 ( V_101 ) ;
if ( V_37 < 0 )
return - V_24 ;
V_122 = F_75 ( V_101 ) ;
V_123 = ( ( V_32 -> V_33 -> V_2 [ V_37 ] . V_5 & ~ V_7 )
+ V_32 -> V_33 -> V_2 [ V_37 ] . V_6 + V_124 - 1 ) >> V_110 ;
if ( V_122 > V_123 )
return - V_24 ;
if ( V_32 -> V_33 -> V_125 ) {
V_36 = V_32 -> V_33 -> V_125 ( V_32 -> V_33 , V_101 ) ;
return V_36 ;
}
switch ( V_32 -> V_33 -> V_2 [ V_37 ] . V_111 ) {
case V_126 :
return F_71 ( V_101 ) ;
case V_112 :
case V_127 :
return F_70 ( V_101 ) ;
default:
return - V_24 ;
}
}
static int F_76 ( void )
{
static const char V_4 [] = L_17 ;
struct V_128 * V_128 = NULL ;
T_8 V_60 = 0 ;
int V_129 ;
V_129 = F_77 ( & V_60 , 0 , V_56 , V_4 ) ;
if ( V_129 )
goto V_75;
V_129 = - V_53 ;
V_128 = F_78 () ;
if ( ! V_128 )
goto V_130;
V_128 -> V_76 = V_131 ;
V_128 -> V_132 = & V_133 ;
F_79 ( & V_128 -> V_9 , L_18 , V_4 ) ;
V_129 = F_80 ( V_128 , V_60 , V_56 ) ;
if ( V_129 )
goto V_134;
V_135 = F_81 ( V_60 ) ;
V_136 = V_128 ;
return 0 ;
V_134:
F_29 ( & V_128 -> V_9 ) ;
V_130:
F_82 ( V_60 , V_56 ) ;
V_75:
return V_129 ;
}
static void F_83 ( void )
{
F_82 ( F_84 ( V_135 , 0 ) , V_56 ) ;
F_85 ( V_136 ) ;
}
static int F_86 ( void )
{
int V_36 ;
V_36 = F_76 () ;
if ( V_36 )
goto exit;
V_36 = F_87 ( & V_137 ) ;
if ( V_36 ) {
F_88 ( V_138 L_19 ) ;
goto V_139;
}
return 0 ;
V_139:
F_83 () ;
exit:
return V_36 ;
}
static void F_89 ( void )
{
F_90 ( & V_137 ) ;
F_83 () ;
}
int F_91 ( struct V_140 * V_76 ,
struct V_28 * V_141 ,
struct V_59 * V_33 )
{
struct V_31 * V_32 ;
int V_36 = 0 ;
if ( ! V_141 || ! V_33 || ! V_33 -> V_4 || ! V_33 -> V_34 )
return - V_24 ;
V_33 -> V_60 = NULL ;
V_32 = F_25 ( sizeof( * V_32 ) , V_44 ) ;
if ( ! V_32 ) {
V_36 = - V_53 ;
goto V_142;
}
V_32 -> V_76 = V_76 ;
V_32 -> V_33 = V_33 ;
F_92 ( & V_32 -> V_61 ) ;
F_93 ( & V_32 -> V_35 , 0 ) ;
V_36 = F_32 ( V_32 ) ;
if ( V_36 )
goto V_143;
V_32 -> V_29 = F_94 ( & V_137 , V_141 ,
F_84 ( V_135 , V_32 -> V_57 ) , V_32 ,
L_20 , V_32 -> V_57 ) ;
if ( F_95 ( V_32 -> V_29 ) ) {
F_88 ( V_138 L_21 ) ;
V_36 = F_96 ( V_32 -> V_29 ) ;
goto V_144;
}
V_36 = F_23 ( V_32 ) ;
if ( V_36 )
goto V_145;
V_33 -> V_60 = V_32 ;
if ( V_33 -> V_65 && ( V_33 -> V_65 != V_146 ) ) {
V_36 = F_97 ( V_33 -> V_65 , F_42 ,
V_33 -> V_147 , V_33 -> V_4 , V_32 ) ;
if ( V_36 )
goto V_148;
}
return 0 ;
V_148:
F_31 ( V_32 ) ;
V_145:
F_98 ( & V_137 , F_84 ( V_135 , V_32 -> V_57 ) ) ;
V_144:
F_36 ( V_32 ) ;
V_143:
F_8 ( V_32 ) ;
V_142:
return V_36 ;
}
void F_99 ( struct V_59 * V_33 )
{
struct V_31 * V_32 ;
if ( ! V_33 || ! V_33 -> V_60 )
return;
V_32 = V_33 -> V_60 ;
F_36 ( V_32 ) ;
if ( V_33 -> V_65 && ( V_33 -> V_65 != V_146 ) )
F_100 ( V_33 -> V_65 , V_32 ) ;
F_31 ( V_32 ) ;
F_98 ( & V_137 , F_84 ( V_135 , V_32 -> V_57 ) ) ;
F_8 ( V_32 ) ;
return;
}
static int T_9 F_101 ( void )
{
return F_86 () ;
}
static void T_10 F_102 ( void )
{
F_89 () ;
}
