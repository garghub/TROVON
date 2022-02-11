static T_1 F_1 ( struct V_1 * V_2 , char * V_3 )
{
if ( F_2 ( ! V_2 -> V_4 ) )
V_2 -> V_4 = L_1 ;
return sprintf ( V_3 , L_2 , V_2 -> V_4 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , char * V_3 )
{
return sprintf ( V_3 , L_3 , V_2 -> V_5 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 , char * V_3 )
{
return sprintf ( V_3 , L_3 , V_2 -> V_6 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , char * V_3 )
{
return sprintf ( V_3 , L_3 , V_2 -> V_5 & ~ V_7 ) ;
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
return sprintf ( V_3 , L_3 , V_19 -> V_20 ) ;
}
static T_1 F_13 ( struct V_18 * V_19 , char * V_3 )
{
return sprintf ( V_3 , L_3 , V_19 -> V_6 ) ;
}
static T_1 F_14 ( struct V_18 * V_19 , char * V_3 )
{
const char * V_21 [] = { L_4 , L_5 , L_6 , L_7 } ;
if ( ( V_19 -> V_22 < 0 ) || ( V_19 -> V_22 > V_23 ) )
return - V_24 ;
return sprintf ( V_3 , L_8 , V_21 [ V_19 -> V_22 ] ) ;
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
return sprintf ( V_3 , L_9 , ( unsigned int ) F_22 ( & V_32 -> V_35 ) ) ;
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
V_32 -> V_42 = F_24 ( L_10 ,
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
V_36 = F_27 ( & V_11 -> V_9 , V_32 -> V_42 , L_11 , V_37 ) ;
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
V_32 -> V_48 = F_24 ( L_12 ,
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
L_13 , V_38 ) ;
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
F_30 ( V_32 -> V_29 , L_14 , V_36 ) ;
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
int V_54 ;
F_33 ( & V_55 ) ;
if ( F_34 ( & V_56 , V_44 ) == 0 )
goto exit;
V_52 = F_35 ( & V_56 , V_32 , & V_54 ) ;
if ( V_52 < 0 ) {
if ( V_52 == - V_57 )
V_52 = - V_53 ;
goto exit;
}
if ( V_54 < V_58 ) {
V_32 -> V_59 = V_54 ;
} else {
F_30 ( V_32 -> V_29 , L_15 ) ;
V_52 = - V_24 ;
F_36 ( & V_56 , V_54 ) ;
}
exit:
F_37 ( & V_55 ) ;
return V_52 ;
}
static void F_38 ( struct V_31 * V_32 )
{
F_33 ( & V_55 ) ;
F_36 ( & V_56 , V_32 -> V_59 ) ;
F_37 ( & V_55 ) ;
}
void F_39 ( struct V_60 * V_33 )
{
struct V_31 * V_32 = V_33 -> V_61 ;
F_40 ( & V_32 -> V_35 ) ;
F_41 ( & V_32 -> V_62 ) ;
F_42 ( & V_32 -> V_63 , V_64 , V_65 ) ;
}
static T_2 F_43 ( int V_66 , void * V_67 )
{
struct V_31 * V_32 = (struct V_31 * ) V_67 ;
T_2 V_36 = V_32 -> V_33 -> V_68 ( V_66 , V_32 -> V_33 ) ;
if ( V_36 == V_69 )
F_39 ( V_32 -> V_33 ) ;
return V_36 ;
}
static int F_44 ( struct V_70 * V_70 , struct V_71 * V_72 )
{
struct V_31 * V_32 ;
struct V_73 * V_74 ;
int V_36 = 0 ;
F_33 ( & V_55 ) ;
V_32 = F_45 ( & V_56 , F_46 ( V_70 ) ) ;
F_37 ( & V_55 ) ;
if ( ! V_32 ) {
V_36 = - V_75 ;
goto V_76;
}
if ( ! F_47 ( V_32 -> V_77 ) ) {
V_36 = - V_75 ;
goto V_76;
}
V_74 = F_48 ( sizeof( * V_74 ) , V_44 ) ;
if ( ! V_74 ) {
V_36 = - V_53 ;
goto V_78;
}
V_74 -> V_29 = V_32 ;
V_74 -> V_79 = F_22 ( & V_32 -> V_35 ) ;
V_72 -> V_80 = V_74 ;
if ( V_32 -> V_33 -> V_81 ) {
V_36 = V_32 -> V_33 -> V_81 ( V_32 -> V_33 , V_70 ) ;
if ( V_36 )
goto V_82;
}
return 0 ;
V_82:
F_8 ( V_74 ) ;
V_78:
F_49 ( V_32 -> V_77 ) ;
V_76:
return V_36 ;
}
static int F_50 ( int V_83 , struct V_71 * V_72 , int V_84 )
{
struct V_73 * V_74 = V_72 -> V_80 ;
struct V_31 * V_32 = V_74 -> V_29 ;
return F_51 ( V_83 , V_72 , V_84 , & V_32 -> V_63 ) ;
}
static int F_52 ( struct V_70 * V_70 , struct V_71 * V_72 )
{
int V_36 = 0 ;
struct V_73 * V_74 = V_72 -> V_80 ;
struct V_31 * V_32 = V_74 -> V_29 ;
if ( V_32 -> V_33 -> V_85 )
V_36 = V_32 -> V_33 -> V_85 ( V_32 -> V_33 , V_70 ) ;
F_49 ( V_32 -> V_77 ) ;
F_8 ( V_74 ) ;
return V_36 ;
}
static unsigned int F_53 ( struct V_71 * V_72 , T_3 * V_62 )
{
struct V_73 * V_74 = V_72 -> V_80 ;
struct V_31 * V_32 = V_74 -> V_29 ;
if ( ! V_32 -> V_33 -> V_66 )
return - V_17 ;
F_54 ( V_72 , & V_32 -> V_62 , V_62 ) ;
if ( V_74 -> V_79 != F_22 ( & V_32 -> V_35 ) )
return V_86 | V_87 ;
return 0 ;
}
static T_1 F_55 ( struct V_71 * V_72 , char T_4 * V_3 ,
T_5 V_88 , T_6 * V_89 )
{
struct V_73 * V_74 = V_72 -> V_80 ;
struct V_31 * V_32 = V_74 -> V_29 ;
F_56 ( V_62 , V_90 ) ;
T_1 V_52 ;
T_7 V_79 ;
if ( ! V_32 -> V_33 -> V_66 )
return - V_17 ;
if ( V_88 != sizeof( T_7 ) )
return - V_24 ;
F_57 ( & V_32 -> V_62 , & V_62 ) ;
do {
F_58 ( V_91 ) ;
V_79 = F_22 ( & V_32 -> V_35 ) ;
if ( V_79 != V_74 -> V_79 ) {
if ( F_59 ( V_3 , & V_79 , V_88 ) )
V_52 = - V_92 ;
else {
V_74 -> V_79 = V_79 ;
V_52 = V_88 ;
}
break;
}
if ( V_72 -> V_93 & V_94 ) {
V_52 = - V_57 ;
break;
}
if ( F_60 ( V_90 ) ) {
V_52 = - V_95 ;
break;
}
F_61 () ;
} while ( 1 );
F_62 ( V_96 ) ;
F_63 ( & V_32 -> V_62 , & V_62 ) ;
return V_52 ;
}
static T_1 F_64 ( struct V_71 * V_72 , const char T_4 * V_3 ,
T_5 V_88 , T_6 * V_89 )
{
struct V_73 * V_74 = V_72 -> V_80 ;
struct V_31 * V_32 = V_74 -> V_29 ;
T_1 V_52 ;
T_7 V_97 ;
if ( ! V_32 -> V_33 -> V_66 )
return - V_17 ;
if ( V_88 != sizeof( T_7 ) )
return - V_24 ;
if ( ! V_32 -> V_33 -> V_98 )
return - V_99 ;
if ( F_65 ( & V_97 , V_3 , V_88 ) )
return - V_92 ;
V_52 = V_32 -> V_33 -> V_98 ( V_32 -> V_33 , V_97 ) ;
return V_52 ? V_52 : sizeof( T_7 ) ;
}
static int F_66 ( struct V_100 * V_101 )
{
struct V_31 * V_32 = V_101 -> V_102 ;
if ( V_101 -> V_103 < V_41 ) {
if ( V_32 -> V_33 -> V_2 [ V_101 -> V_103 ] . V_6 == 0 )
return - 1 ;
return ( int ) V_101 -> V_103 ;
}
return - 1 ;
}
static void F_67 ( struct V_100 * V_101 )
{
struct V_31 * V_32 = V_101 -> V_102 ;
V_32 -> V_104 ++ ;
}
static void F_68 ( struct V_100 * V_101 )
{
struct V_31 * V_32 = V_101 -> V_102 ;
V_32 -> V_104 -- ;
}
static int F_69 ( struct V_100 * V_101 , struct V_105 * V_106 )
{
struct V_31 * V_32 = V_101 -> V_102 ;
struct V_107 * V_107 ;
unsigned long V_108 ;
int V_37 = F_66 ( V_101 ) ;
if ( V_37 < 0 )
return V_109 ;
V_108 = ( V_106 -> V_110 - V_37 ) << V_111 ;
if ( V_32 -> V_33 -> V_2 [ V_37 ] . V_112 == V_113 )
V_107 = F_70 ( V_32 -> V_33 -> V_2 [ V_37 ] . V_5 + V_108 ) ;
else
V_107 = F_71 ( ( void * ) V_32 -> V_33 -> V_2 [ V_37 ] . V_5
+ V_108 ) ;
F_72 ( V_107 ) ;
V_106 -> V_107 = V_107 ;
return 0 ;
}
static int F_73 ( struct V_100 * V_101 )
{
struct V_31 * V_32 = V_101 -> V_102 ;
int V_37 = F_66 ( V_101 ) ;
if ( V_37 < 0 )
return - V_24 ;
V_101 -> V_114 |= V_115 | V_116 ;
V_101 -> V_117 = F_74 ( V_101 -> V_117 ) ;
return F_75 ( V_101 ,
V_101 -> V_118 ,
V_32 -> V_33 -> V_2 [ V_37 ] . V_5 >> V_111 ,
V_101 -> V_119 - V_101 -> V_118 ,
V_101 -> V_117 ) ;
}
static int F_76 ( struct V_100 * V_101 )
{
V_101 -> V_114 |= V_116 ;
V_101 -> V_120 = & V_121 ;
F_67 ( V_101 ) ;
return 0 ;
}
static int F_77 ( struct V_71 * V_72 , struct V_100 * V_101 )
{
struct V_73 * V_74 = V_72 -> V_80 ;
struct V_31 * V_32 = V_74 -> V_29 ;
int V_37 ;
unsigned long V_122 , V_123 ;
int V_36 = 0 ;
if ( V_101 -> V_119 < V_101 -> V_118 )
return - V_24 ;
V_101 -> V_102 = V_32 ;
V_37 = F_66 ( V_101 ) ;
if ( V_37 < 0 )
return - V_24 ;
V_122 = ( V_101 -> V_119 - V_101 -> V_118 ) >> V_111 ;
V_123 = ( ( V_32 -> V_33 -> V_2 [ V_37 ] . V_5 & ~ V_7 )
+ V_32 -> V_33 -> V_2 [ V_37 ] . V_6 + V_124 - 1 ) >> V_111 ;
if ( V_122 > V_123 )
return - V_24 ;
if ( V_32 -> V_33 -> V_125 ) {
V_36 = V_32 -> V_33 -> V_125 ( V_32 -> V_33 , V_101 ) ;
return V_36 ;
}
switch ( V_32 -> V_33 -> V_2 [ V_37 ] . V_112 ) {
case V_126 :
return F_73 ( V_101 ) ;
case V_113 :
case V_127 :
return F_76 ( V_101 ) ;
default:
return - V_24 ;
}
}
static int F_78 ( void )
{
static const char V_4 [] = L_16 ;
struct V_128 * V_128 = NULL ;
T_8 V_61 = 0 ;
int V_129 ;
V_129 = F_79 ( & V_61 , 0 , V_58 , V_4 ) ;
if ( V_129 )
goto V_76;
V_129 = - V_53 ;
V_128 = F_80 () ;
if ( ! V_128 )
goto V_130;
V_128 -> V_77 = V_131 ;
V_128 -> V_132 = & V_133 ;
F_81 ( & V_128 -> V_9 , L_17 , V_4 ) ;
V_129 = F_82 ( V_128 , V_61 , V_58 ) ;
if ( V_129 )
goto V_134;
V_135 = F_83 ( V_61 ) ;
V_136 = V_128 ;
V_129 = 0 ;
V_76:
return V_129 ;
V_134:
F_29 ( & V_128 -> V_9 ) ;
V_130:
F_84 ( V_61 , V_58 ) ;
goto V_76;
}
static void F_85 ( void )
{
F_84 ( F_86 ( V_135 , 0 ) , V_58 ) ;
F_87 ( V_136 ) ;
}
static int F_88 ( void )
{
int V_36 ;
V_36 = F_78 () ;
if ( V_36 )
goto exit;
V_36 = F_89 ( & V_137 ) ;
if ( V_36 ) {
F_90 ( V_138 L_18 ) ;
goto V_139;
}
return 0 ;
V_139:
F_85 () ;
exit:
return V_36 ;
}
static void F_91 ( void )
{
F_92 ( & V_137 ) ;
F_85 () ;
}
int F_93 ( struct V_140 * V_77 ,
struct V_28 * V_141 ,
struct V_60 * V_33 )
{
struct V_31 * V_32 ;
int V_36 = 0 ;
if ( ! V_141 || ! V_33 || ! V_33 -> V_4 || ! V_33 -> V_34 )
return - V_24 ;
V_33 -> V_61 = NULL ;
V_32 = F_25 ( sizeof( * V_32 ) , V_44 ) ;
if ( ! V_32 ) {
V_36 = - V_53 ;
goto V_142;
}
V_32 -> V_77 = V_77 ;
V_32 -> V_33 = V_33 ;
F_94 ( & V_32 -> V_62 ) ;
F_95 ( & V_32 -> V_35 , 0 ) ;
V_36 = F_32 ( V_32 ) ;
if ( V_36 )
goto V_143;
V_32 -> V_29 = F_96 ( & V_137 , V_141 ,
F_86 ( V_135 , V_32 -> V_59 ) , V_32 ,
L_19 , V_32 -> V_59 ) ;
if ( F_97 ( V_32 -> V_29 ) ) {
F_90 ( V_138 L_20 ) ;
V_36 = F_98 ( V_32 -> V_29 ) ;
goto V_144;
}
V_36 = F_23 ( V_32 ) ;
if ( V_36 )
goto V_145;
V_33 -> V_61 = V_32 ;
if ( V_33 -> V_66 && ( V_33 -> V_66 != V_146 ) ) {
V_36 = F_99 ( V_33 -> V_66 , F_43 ,
V_33 -> V_147 , V_33 -> V_4 , V_32 ) ;
if ( V_36 )
goto V_148;
}
return 0 ;
V_148:
F_31 ( V_32 ) ;
V_145:
F_100 ( & V_137 , F_86 ( V_135 , V_32 -> V_59 ) ) ;
V_144:
F_38 ( V_32 ) ;
V_143:
F_8 ( V_32 ) ;
V_142:
return V_36 ;
}
void F_101 ( struct V_60 * V_33 )
{
struct V_31 * V_32 ;
if ( ! V_33 || ! V_33 -> V_61 )
return;
V_32 = V_33 -> V_61 ;
F_38 ( V_32 ) ;
if ( V_33 -> V_66 && ( V_33 -> V_66 != V_146 ) )
F_102 ( V_33 -> V_66 , V_32 ) ;
F_31 ( V_32 ) ;
F_100 ( & V_137 , F_86 ( V_135 , V_32 -> V_59 ) ) ;
F_8 ( V_32 ) ;
return;
}
static int T_9 F_103 ( void )
{
return F_88 () ;
}
static void T_10 F_104 ( void )
{
F_91 () ;
}
