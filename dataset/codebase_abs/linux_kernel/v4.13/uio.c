static T_1 F_1 ( struct V_1 * V_2 , char * V_3 )
{
if ( F_2 ( ! V_2 -> V_4 ) )
V_2 -> V_4 = L_1 ;
return sprintf ( V_3 , L_2 , V_2 -> V_4 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , char * V_3 )
{
return sprintf ( V_3 , L_3 , & V_2 -> V_5 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 , char * V_3 )
{
return sprintf ( V_3 , L_3 , & V_2 -> V_6 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , char * V_3 )
{
return sprintf ( V_3 , L_4 , ( unsigned long long ) V_2 -> V_7 ) ;
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
return sprintf ( V_3 , L_5 , V_19 -> V_20 ) ;
}
static T_1 F_13 ( struct V_18 * V_19 , char * V_3 )
{
return sprintf ( V_3 , L_5 , V_19 -> V_6 ) ;
}
static T_1 F_14 ( struct V_18 * V_19 , char * V_3 )
{
const char * V_21 [] = { L_6 , L_7 , L_8 , L_9 } ;
if ( ( V_19 -> V_22 < 0 ) || ( V_19 -> V_22 > V_23 ) )
return - V_24 ;
return sprintf ( V_3 , L_10 , V_21 [ V_19 -> V_22 ] ) ;
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
return sprintf ( V_3 , L_11 , ( unsigned int ) F_22 ( & V_32 -> V_35 ) ) ;
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
V_32 -> V_42 = F_24 ( L_12 ,
& V_32 -> V_29 -> V_9 ) ;
if ( ! V_32 -> V_42 ) {
V_36 = - V_43 ;
goto V_44;
}
}
V_11 = F_25 ( sizeof( * V_11 ) , V_45 ) ;
if ( ! V_11 ) {
V_36 = - V_43 ;
goto V_44;
}
F_26 ( & V_11 -> V_9 , & V_46 ) ;
V_11 -> V_2 = V_2 ;
V_2 -> V_11 = V_11 ;
V_36 = F_27 ( & V_11 -> V_9 , V_32 -> V_42 , L_13 , V_37 ) ;
if ( V_36 )
goto V_47;
V_36 = F_28 ( & V_11 -> V_9 , V_48 ) ;
if ( V_36 )
goto V_47;
}
for ( V_38 = 0 ; V_38 < V_49 ; V_38 ++ ) {
V_19 = & V_32 -> V_33 -> V_19 [ V_38 ] ;
if ( V_19 -> V_6 == 0 )
break;
if ( ! V_40 ) {
V_40 = 1 ;
V_32 -> V_50 = F_24 ( L_14 ,
& V_32 -> V_29 -> V_9 ) ;
if ( ! V_32 -> V_50 ) {
V_36 = - V_43 ;
goto V_51;
}
}
V_26 = F_25 ( sizeof( * V_26 ) , V_45 ) ;
if ( ! V_26 ) {
V_36 = - V_43 ;
goto V_51;
}
F_26 ( & V_26 -> V_9 , & V_52 ) ;
V_26 -> V_19 = V_19 ;
V_19 -> V_26 = V_26 ;
V_36 = F_27 ( & V_26 -> V_9 , V_32 -> V_50 ,
L_15 , V_38 ) ;
if ( V_36 )
goto V_53;
V_36 = F_28 ( & V_26 -> V_9 , V_48 ) ;
if ( V_36 )
goto V_53;
}
return 0 ;
V_51:
V_38 -- ;
V_53:
for (; V_38 >= 0 ; V_38 -- ) {
V_19 = & V_32 -> V_33 -> V_19 [ V_38 ] ;
V_26 = V_19 -> V_26 ;
F_29 ( & V_26 -> V_9 ) ;
}
F_29 ( V_32 -> V_50 ) ;
V_44:
V_37 -- ;
V_47:
for (; V_37 >= 0 ; V_37 -- ) {
V_2 = & V_32 -> V_33 -> V_2 [ V_37 ] ;
V_11 = V_2 -> V_11 ;
F_29 ( & V_11 -> V_9 ) ;
}
F_29 ( V_32 -> V_42 ) ;
F_30 ( V_32 -> V_29 , L_16 , V_36 ) ;
return V_36 ;
}
static void F_31 ( struct V_31 * V_32 )
{
int V_54 ;
struct V_1 * V_2 ;
struct V_18 * V_19 ;
for ( V_54 = 0 ; V_54 < V_41 ; V_54 ++ ) {
V_2 = & V_32 -> V_33 -> V_2 [ V_54 ] ;
if ( V_2 -> V_6 == 0 )
break;
F_29 ( & V_2 -> V_11 -> V_9 ) ;
}
F_29 ( V_32 -> V_42 ) ;
for ( V_54 = 0 ; V_54 < V_49 ; V_54 ++ ) {
V_19 = & V_32 -> V_33 -> V_19 [ V_54 ] ;
if ( V_19 -> V_6 == 0 )
break;
F_29 ( & V_19 -> V_26 -> V_9 ) ;
}
F_29 ( V_32 -> V_50 ) ;
}
static int F_32 ( struct V_31 * V_32 )
{
int V_55 = - V_43 ;
F_33 ( & V_56 ) ;
V_55 = F_34 ( & V_57 , V_32 , 0 , V_58 , V_45 ) ;
if ( V_55 >= 0 ) {
V_32 -> V_59 = V_55 ;
V_55 = 0 ;
} else if ( V_55 == - V_60 ) {
F_30 ( V_32 -> V_29 , L_17 ) ;
V_55 = - V_24 ;
}
F_35 ( & V_56 ) ;
return V_55 ;
}
static void F_36 ( struct V_31 * V_32 )
{
F_33 ( & V_56 ) ;
F_37 ( & V_57 , V_32 -> V_59 ) ;
F_35 ( & V_56 ) ;
}
void F_38 ( struct V_61 * V_33 )
{
struct V_31 * V_32 = V_33 -> V_62 ;
F_39 ( & V_32 -> V_35 ) ;
F_40 ( & V_32 -> V_63 ) ;
F_41 ( & V_32 -> V_64 , V_65 , V_66 ) ;
}
static T_2 F_42 ( int V_67 , void * V_68 )
{
struct V_31 * V_32 = (struct V_31 * ) V_68 ;
T_2 V_36 = V_32 -> V_33 -> V_69 ( V_67 , V_32 -> V_33 ) ;
if ( V_36 == V_70 )
F_38 ( V_32 -> V_33 ) ;
return V_36 ;
}
static int F_43 ( struct V_71 * V_71 , struct V_72 * V_73 )
{
struct V_31 * V_32 ;
struct V_74 * V_75 ;
int V_36 = 0 ;
F_33 ( & V_56 ) ;
V_32 = F_44 ( & V_57 , F_45 ( V_71 ) ) ;
F_35 ( & V_56 ) ;
if ( ! V_32 ) {
V_36 = - V_76 ;
goto V_77;
}
if ( ! F_46 ( V_32 -> V_78 ) ) {
V_36 = - V_76 ;
goto V_77;
}
V_75 = F_47 ( sizeof( * V_75 ) , V_45 ) ;
if ( ! V_75 ) {
V_36 = - V_43 ;
goto V_79;
}
V_75 -> V_29 = V_32 ;
V_75 -> V_80 = F_22 ( & V_32 -> V_35 ) ;
V_73 -> V_81 = V_75 ;
if ( V_32 -> V_33 -> V_82 ) {
V_36 = V_32 -> V_33 -> V_82 ( V_32 -> V_33 , V_71 ) ;
if ( V_36 )
goto V_83;
}
return 0 ;
V_83:
F_8 ( V_75 ) ;
V_79:
F_48 ( V_32 -> V_78 ) ;
V_77:
return V_36 ;
}
static int F_49 ( int V_84 , struct V_72 * V_73 , int V_85 )
{
struct V_74 * V_75 = V_73 -> V_81 ;
struct V_31 * V_32 = V_75 -> V_29 ;
return F_50 ( V_84 , V_73 , V_85 , & V_32 -> V_64 ) ;
}
static int F_51 ( struct V_71 * V_71 , struct V_72 * V_73 )
{
int V_36 = 0 ;
struct V_74 * V_75 = V_73 -> V_81 ;
struct V_31 * V_32 = V_75 -> V_29 ;
if ( V_32 -> V_33 -> V_86 )
V_36 = V_32 -> V_33 -> V_86 ( V_32 -> V_33 , V_71 ) ;
F_48 ( V_32 -> V_78 ) ;
F_8 ( V_75 ) ;
return V_36 ;
}
static unsigned int F_52 ( struct V_72 * V_73 , T_3 * V_63 )
{
struct V_74 * V_75 = V_73 -> V_81 ;
struct V_31 * V_32 = V_75 -> V_29 ;
if ( ! V_32 -> V_33 -> V_67 )
return - V_17 ;
F_53 ( V_73 , & V_32 -> V_63 , V_63 ) ;
if ( V_75 -> V_80 != F_22 ( & V_32 -> V_35 ) )
return V_87 | V_88 ;
return 0 ;
}
static T_1 F_54 ( struct V_72 * V_73 , char T_4 * V_3 ,
T_5 V_89 , T_6 * V_90 )
{
struct V_74 * V_75 = V_73 -> V_81 ;
struct V_31 * V_32 = V_75 -> V_29 ;
F_55 ( V_63 , V_91 ) ;
T_1 V_55 ;
T_7 V_80 ;
if ( ! V_32 -> V_33 -> V_67 )
return - V_17 ;
if ( V_89 != sizeof( T_7 ) )
return - V_24 ;
F_56 ( & V_32 -> V_63 , & V_63 ) ;
do {
F_57 ( V_92 ) ;
V_80 = F_22 ( & V_32 -> V_35 ) ;
if ( V_80 != V_75 -> V_80 ) {
F_58 ( V_93 ) ;
if ( F_59 ( V_3 , & V_80 , V_89 ) )
V_55 = - V_94 ;
else {
V_75 -> V_80 = V_80 ;
V_55 = V_89 ;
}
break;
}
if ( V_73 -> V_95 & V_96 ) {
V_55 = - V_97 ;
break;
}
if ( F_60 ( V_91 ) ) {
V_55 = - V_98 ;
break;
}
F_61 () ;
} while ( 1 );
F_58 ( V_93 ) ;
F_62 ( & V_32 -> V_63 , & V_63 ) ;
return V_55 ;
}
static T_1 F_63 ( struct V_72 * V_73 , const char T_4 * V_3 ,
T_5 V_89 , T_6 * V_90 )
{
struct V_74 * V_75 = V_73 -> V_81 ;
struct V_31 * V_32 = V_75 -> V_29 ;
T_1 V_55 ;
T_7 V_99 ;
if ( ! V_32 -> V_33 -> V_67 )
return - V_17 ;
if ( V_89 != sizeof( T_7 ) )
return - V_24 ;
if ( ! V_32 -> V_33 -> V_100 )
return - V_101 ;
if ( F_64 ( & V_99 , V_3 , V_89 ) )
return - V_94 ;
V_55 = V_32 -> V_33 -> V_100 ( V_32 -> V_33 , V_99 ) ;
return V_55 ? V_55 : sizeof( T_7 ) ;
}
static int F_65 ( struct V_102 * V_103 )
{
struct V_31 * V_32 = V_103 -> V_104 ;
if ( V_103 -> V_105 < V_41 ) {
if ( V_32 -> V_33 -> V_2 [ V_103 -> V_105 ] . V_6 == 0 )
return - 1 ;
return ( int ) V_103 -> V_105 ;
}
return - 1 ;
}
static int F_66 ( struct V_106 * V_107 )
{
struct V_31 * V_32 = V_107 -> V_103 -> V_104 ;
struct V_108 * V_108 ;
unsigned long V_109 ;
void * V_5 ;
int V_37 = F_65 ( V_107 -> V_103 ) ;
if ( V_37 < 0 )
return V_110 ;
V_109 = ( V_107 -> V_111 - V_37 ) << V_112 ;
V_5 = ( void * ) ( unsigned long ) V_32 -> V_33 -> V_2 [ V_37 ] . V_5 + V_109 ;
if ( V_32 -> V_33 -> V_2 [ V_37 ] . V_113 == V_114 )
V_108 = F_67 ( V_5 ) ;
else
V_108 = F_68 ( V_5 ) ;
F_69 ( V_108 ) ;
V_107 -> V_108 = V_108 ;
return 0 ;
}
static int F_70 ( struct V_102 * V_103 )
{
V_103 -> V_115 |= V_116 | V_117 ;
V_103 -> V_118 = & V_119 ;
return 0 ;
}
static int F_71 ( struct V_102 * V_103 )
{
struct V_31 * V_32 = V_103 -> V_104 ;
int V_37 = F_65 ( V_103 ) ;
struct V_1 * V_2 ;
if ( V_37 < 0 )
return - V_24 ;
V_2 = V_32 -> V_33 -> V_2 + V_37 ;
if ( V_2 -> V_5 & ~ V_120 )
return - V_76 ;
if ( V_103 -> V_121 - V_103 -> V_122 > V_2 -> V_6 )
return - V_24 ;
V_103 -> V_118 = & V_123 ;
V_103 -> V_124 = F_72 ( V_103 -> V_124 ) ;
return F_73 ( V_103 ,
V_103 -> V_122 ,
V_2 -> V_5 >> V_112 ,
V_103 -> V_121 - V_103 -> V_122 ,
V_103 -> V_124 ) ;
}
static int F_74 ( struct V_72 * V_73 , struct V_102 * V_103 )
{
struct V_74 * V_75 = V_73 -> V_81 ;
struct V_31 * V_32 = V_75 -> V_29 ;
int V_37 ;
unsigned long V_125 , V_126 ;
int V_36 = 0 ;
if ( V_103 -> V_121 < V_103 -> V_122 )
return - V_24 ;
V_103 -> V_104 = V_32 ;
V_37 = F_65 ( V_103 ) ;
if ( V_37 < 0 )
return - V_24 ;
V_125 = F_75 ( V_103 ) ;
V_126 = ( ( V_32 -> V_33 -> V_2 [ V_37 ] . V_5 & ~ V_120 )
+ V_32 -> V_33 -> V_2 [ V_37 ] . V_6 + V_127 - 1 ) >> V_112 ;
if ( V_125 > V_126 )
return - V_24 ;
if ( V_32 -> V_33 -> V_128 ) {
V_36 = V_32 -> V_33 -> V_128 ( V_32 -> V_33 , V_103 ) ;
return V_36 ;
}
switch ( V_32 -> V_33 -> V_2 [ V_37 ] . V_113 ) {
case V_129 :
return F_71 ( V_103 ) ;
case V_114 :
case V_130 :
return F_70 ( V_103 ) ;
default:
return - V_24 ;
}
}
static int F_76 ( void )
{
static const char V_4 [] = L_18 ;
struct V_131 * V_131 = NULL ;
T_8 V_62 = 0 ;
int V_132 ;
V_132 = F_77 ( & V_62 , 0 , V_58 , V_4 ) ;
if ( V_132 )
goto V_77;
V_132 = - V_43 ;
V_131 = F_78 () ;
if ( ! V_131 )
goto V_133;
V_131 -> V_78 = V_134 ;
V_131 -> V_135 = & V_136 ;
F_79 ( & V_131 -> V_9 , L_19 , V_4 ) ;
V_132 = F_80 ( V_131 , V_62 , V_58 ) ;
if ( V_132 )
goto V_137;
V_138 = F_81 ( V_62 ) ;
V_139 = V_131 ;
return 0 ;
V_137:
F_29 ( & V_131 -> V_9 ) ;
V_133:
F_82 ( V_62 , V_58 ) ;
V_77:
return V_132 ;
}
static void F_83 ( void )
{
F_82 ( F_84 ( V_138 , 0 ) , V_58 ) ;
F_85 ( V_139 ) ;
}
static int F_86 ( void )
{
int V_36 ;
V_36 = F_76 () ;
if ( V_36 )
goto exit;
V_36 = F_87 ( & V_140 ) ;
if ( V_36 ) {
F_88 ( V_141 L_20 ) ;
goto V_142;
}
return 0 ;
V_142:
F_83 () ;
exit:
return V_36 ;
}
static void F_89 ( void )
{
F_90 ( & V_140 ) ;
F_83 () ;
}
int F_91 ( struct V_143 * V_78 ,
struct V_28 * V_144 ,
struct V_61 * V_33 )
{
struct V_31 * V_32 ;
int V_36 = 0 ;
if ( ! V_144 || ! V_33 || ! V_33 -> V_4 || ! V_33 -> V_34 )
return - V_24 ;
V_33 -> V_62 = NULL ;
V_32 = F_92 ( V_144 , sizeof( * V_32 ) , V_45 ) ;
if ( ! V_32 ) {
return - V_43 ;
}
V_32 -> V_78 = V_78 ;
V_32 -> V_33 = V_33 ;
F_93 ( & V_32 -> V_63 ) ;
F_94 ( & V_32 -> V_35 , 0 ) ;
V_36 = F_32 ( V_32 ) ;
if ( V_36 )
return V_36 ;
V_32 -> V_29 = F_95 ( & V_140 , V_144 ,
F_84 ( V_138 , V_32 -> V_59 ) , V_32 ,
L_21 , V_32 -> V_59 ) ;
if ( F_96 ( V_32 -> V_29 ) ) {
F_88 ( V_141 L_22 ) ;
V_36 = F_97 ( V_32 -> V_29 ) ;
goto V_145;
}
V_36 = F_23 ( V_32 ) ;
if ( V_36 )
goto V_146;
V_33 -> V_62 = V_32 ;
if ( V_33 -> V_67 && ( V_33 -> V_67 != V_147 ) ) {
V_36 = F_98 ( V_33 -> V_67 , F_42 ,
V_33 -> V_148 , V_33 -> V_4 , V_32 ) ;
if ( V_36 )
goto V_149;
}
return 0 ;
V_149:
F_31 ( V_32 ) ;
V_146:
F_99 ( & V_140 , F_84 ( V_138 , V_32 -> V_59 ) ) ;
V_145:
F_36 ( V_32 ) ;
return V_36 ;
}
void F_100 ( struct V_61 * V_33 )
{
struct V_31 * V_32 ;
if ( ! V_33 || ! V_33 -> V_62 )
return;
V_32 = V_33 -> V_62 ;
F_36 ( V_32 ) ;
F_31 ( V_32 ) ;
if ( V_33 -> V_67 && V_33 -> V_67 != V_147 )
F_101 ( V_33 -> V_67 , V_32 ) ;
F_99 ( & V_140 , F_84 ( V_138 , V_32 -> V_59 ) ) ;
return;
}
static int T_9 F_102 ( void )
{
return F_86 () ;
}
static void T_10 F_103 ( void )
{
F_89 () ;
F_104 ( & V_57 ) ;
}
