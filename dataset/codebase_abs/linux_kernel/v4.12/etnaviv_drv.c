void T_1 * F_1 ( struct V_1 * V_2 , const char * V_3 ,
const char * V_4 )
{
struct V_5 * V_6 ;
void T_1 * V_7 ;
if ( V_3 )
V_6 = F_2 ( V_2 , V_8 , V_3 ) ;
else
V_6 = F_3 ( V_2 , V_8 , 0 ) ;
V_7 = F_4 ( & V_2 -> V_9 , V_6 ) ;
if ( F_5 ( V_7 ) ) {
F_6 ( & V_2 -> V_9 , L_1 , V_3 ,
F_7 ( V_7 ) ) ;
return V_7 ;
}
if ( V_10 )
F_8 ( V_11 , & V_2 -> V_9 , L_2 ,
V_4 , V_7 , ( V_12 ) F_9 ( V_6 ) ) ;
return V_7 ;
}
void F_10 ( T_2 V_13 , void T_1 * V_14 )
{
if ( V_10 )
F_11 ( V_11 L_3 , V_14 , V_13 ) ;
F_12 ( V_13 , V_14 ) ;
}
T_2 F_13 ( const void T_1 * V_14 )
{
T_2 V_15 = F_14 ( V_14 ) ;
if ( V_10 )
F_11 ( V_11 L_4 , V_14 , V_15 ) ;
return V_15 ;
}
static void F_15 ( struct V_16 * V_9 )
{
struct V_17 * V_18 = V_9 -> V_19 ;
unsigned int V_20 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
struct V_22 * V_23 = V_18 -> V_24 [ V_20 ] ;
if ( V_23 ) {
int V_25 ;
V_25 = F_16 ( V_23 ) ;
if ( V_25 )
V_18 -> V_24 [ V_20 ] = NULL ;
}
}
}
static int F_17 ( struct V_16 * V_9 , struct V_26 * V_27 )
{
struct V_28 * V_29 ;
V_29 = F_18 ( sizeof( * V_29 ) , V_30 ) ;
if ( ! V_29 )
return - V_31 ;
V_27 -> V_32 = V_29 ;
return 0 ;
}
static void F_19 ( struct V_16 * V_9 , struct V_26 * V_27 )
{
struct V_17 * V_18 = V_9 -> V_19 ;
struct V_28 * V_29 = V_27 -> V_32 ;
unsigned int V_20 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
struct V_22 * V_24 = V_18 -> V_24 [ V_20 ] ;
if ( V_24 ) {
F_20 ( & V_24 -> V_33 ) ;
if ( V_24 -> V_34 == V_29 )
V_24 -> V_34 = NULL ;
F_21 ( & V_24 -> V_33 ) ;
}
}
F_22 ( V_29 ) ;
}
static int F_23 ( struct V_16 * V_9 , struct V_35 * V_36 )
{
struct V_17 * V_18 = V_9 -> V_19 ;
F_24 ( V_18 , V_36 ) ;
return 0 ;
}
static int F_25 ( struct V_16 * V_9 , struct V_35 * V_36 )
{
struct V_37 V_38 = F_26 ( V_36 ) ;
F_27 ( & V_9 -> V_39 -> V_40 ) ;
F_28 ( & V_9 -> V_39 -> V_41 , & V_38 ) ;
F_29 ( & V_9 -> V_39 -> V_40 ) ;
return 0 ;
}
static int F_30 ( struct V_22 * V_24 , struct V_35 * V_36 )
{
struct V_37 V_38 = F_26 ( V_36 ) ;
F_31 ( V_36 , L_5 , F_32 ( V_24 -> V_9 ) ) ;
F_20 ( & V_24 -> V_42 -> V_33 ) ;
F_28 ( & V_24 -> V_42 -> V_43 , & V_38 ) ;
F_21 ( & V_24 -> V_42 -> V_33 ) ;
return 0 ;
}
static void F_33 ( struct V_22 * V_24 , struct V_35 * V_36 )
{
struct V_44 * V_45 = V_24 -> V_46 ;
T_2 V_47 = V_45 -> V_47 ;
T_2 * V_7 = V_45 -> V_48 ;
T_2 V_20 ;
F_31 ( V_36 , L_6 ,
V_45 -> V_48 , ( V_49 ) F_34 ( V_45 ) ,
V_47 - V_45 -> V_50 ) ;
for ( V_20 = 0 ; V_20 < V_47 / 4 ; V_20 ++ ) {
if ( V_20 && ! ( V_20 % 4 ) )
F_35 ( V_36 , L_7 ) ;
if ( V_20 % 4 == 0 )
F_31 ( V_36 , L_8 , V_7 + V_20 ) ;
F_31 ( V_36 , L_9 , * ( V_7 + V_20 ) ) ;
}
F_35 ( V_36 , L_7 ) ;
}
static int F_36 ( struct V_22 * V_24 , struct V_35 * V_36 )
{
F_31 ( V_36 , L_10 , F_32 ( V_24 -> V_9 ) ) ;
F_20 ( & V_24 -> V_33 ) ;
F_33 ( V_24 , V_36 ) ;
F_21 ( & V_24 -> V_33 ) ;
return 0 ;
}
static int F_37 ( struct V_35 * V_36 , void * V_51 )
{
struct V_52 * V_53 = (struct V_52 * ) V_36 -> V_54 ;
struct V_16 * V_9 = V_53 -> V_55 -> V_9 ;
int (* F_38)( struct V_16 * V_9 , struct V_35 * V_36 ) =
V_53 -> V_56 -> V_13 ;
return F_38 ( V_9 , V_36 ) ;
}
static int F_39 ( struct V_35 * V_36 , void * V_51 )
{
struct V_52 * V_53 = (struct V_52 * ) V_36 -> V_54 ;
struct V_16 * V_9 = V_53 -> V_55 -> V_9 ;
struct V_17 * V_18 = V_9 -> V_19 ;
struct V_22 * V_24 ;
int (* F_38)( struct V_22 * V_24 , struct V_35 * V_36 ) =
V_53 -> V_56 -> V_13 ;
unsigned int V_20 ;
int V_25 = 0 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
V_24 = V_18 -> V_24 [ V_20 ] ;
if ( ! V_24 )
continue;
V_25 = F_38 ( V_24 , V_36 ) ;
if ( V_25 < 0 )
break;
}
return V_25 ;
}
static int F_40 ( struct V_57 * V_55 )
{
struct V_16 * V_9 = V_55 -> V_9 ;
int V_25 ;
V_25 = F_41 ( V_58 ,
F_42 ( V_58 ) ,
V_55 -> V_59 , V_55 ) ;
if ( V_25 ) {
F_6 ( V_9 -> V_9 , L_11 ) ;
return V_25 ;
}
return V_25 ;
}
static int F_43 ( struct V_16 * V_9 , void * V_13 ,
struct V_26 * V_27 )
{
struct V_17 * V_18 = V_9 -> V_19 ;
struct V_60 * args = V_13 ;
struct V_22 * V_24 ;
if ( args -> V_61 >= V_21 )
return - V_62 ;
V_24 = V_18 -> V_24 [ args -> V_61 ] ;
if ( ! V_24 )
return - V_63 ;
return F_44 ( V_24 , args -> V_64 , & args -> V_65 ) ;
}
static int F_45 ( struct V_16 * V_9 , void * V_13 ,
struct V_26 * V_27 )
{
struct V_66 * args = V_13 ;
if ( args -> V_67 & ~ ( V_68 | V_69 | V_70 |
V_71 ) )
return - V_62 ;
return F_46 ( V_9 , V_27 , args -> V_47 ,
args -> V_67 , & args -> V_72 ) ;
}
static int F_47 ( struct V_16 * V_9 , void * V_13 ,
struct V_26 * V_27 )
{
struct V_73 * args = V_13 ;
struct V_74 * V_75 ;
int V_25 ;
if ( args -> V_76 & ~ ( V_77 | V_78 | V_79 ) )
return - V_62 ;
V_75 = F_48 ( V_27 , args -> V_72 ) ;
if ( ! V_75 )
return - V_80 ;
V_25 = F_49 ( V_75 , args -> V_76 , & F_50 ( args -> V_81 ) ) ;
F_51 ( V_75 ) ;
return V_25 ;
}
static int F_52 ( struct V_16 * V_9 , void * V_13 ,
struct V_26 * V_27 )
{
struct V_82 * args = V_13 ;
struct V_74 * V_75 ;
int V_25 ;
if ( args -> V_67 )
return - V_62 ;
V_75 = F_48 ( V_27 , args -> V_72 ) ;
if ( ! V_75 )
return - V_80 ;
V_25 = F_53 ( V_75 ) ;
F_51 ( V_75 ) ;
return V_25 ;
}
static int F_54 ( struct V_16 * V_9 , void * V_13 ,
struct V_26 * V_27 )
{
struct V_83 * args = V_13 ;
struct V_74 * V_75 ;
int V_25 ;
if ( args -> V_84 )
return - V_62 ;
V_75 = F_48 ( V_27 , args -> V_72 ) ;
if ( ! V_75 )
return - V_80 ;
V_25 = F_55 ( V_75 , & args -> V_85 ) ;
F_51 ( V_75 ) ;
return V_25 ;
}
static int F_56 ( struct V_16 * V_9 , void * V_13 ,
struct V_26 * V_27 )
{
struct V_86 * args = V_13 ;
struct V_17 * V_18 = V_9 -> V_19 ;
struct V_87 * V_81 = & F_50 ( args -> V_81 ) ;
struct V_22 * V_24 ;
if ( args -> V_67 & ~ ( V_88 ) )
return - V_62 ;
if ( args -> V_61 >= V_21 )
return - V_62 ;
V_24 = V_18 -> V_24 [ args -> V_61 ] ;
if ( ! V_24 )
return - V_63 ;
if ( args -> V_67 & V_88 )
V_81 = NULL ;
return F_57 ( V_24 , args -> V_89 ,
V_81 ) ;
}
static int F_58 ( struct V_16 * V_9 , void * V_13 ,
struct V_26 * V_27 )
{
struct V_90 * args = V_13 ;
int V_91 ;
if ( args -> V_67 & ~ ( V_92 | V_93 ) ||
args -> V_67 == 0 )
return - V_62 ;
if ( F_59 ( args -> V_94 | args -> V_50 ) ||
( V_95 ) args -> V_94 != args -> V_94 ||
( T_2 ) args -> V_50 != args -> V_50 ||
args -> V_94 & ~ V_96 )
return - V_62 ;
if ( args -> V_67 & V_93 )
V_91 = V_97 ;
else
V_91 = V_98 ;
if ( ! F_60 ( V_91 , ( void V_99 * ) ( unsigned long ) args -> V_94 ,
args -> V_50 ) )
return - V_100 ;
return F_61 ( V_9 , V_27 , args -> V_94 ,
args -> V_50 , args -> V_67 ,
& args -> V_72 ) ;
}
static int F_62 ( struct V_16 * V_9 , void * V_13 ,
struct V_26 * V_27 )
{
struct V_17 * V_18 = V_9 -> V_19 ;
struct V_101 * args = V_13 ;
struct V_87 * V_81 = & F_50 ( args -> V_81 ) ;
struct V_74 * V_75 ;
struct V_22 * V_24 ;
int V_25 ;
if ( args -> V_67 & ~ ( V_88 ) )
return - V_62 ;
if ( args -> V_61 >= V_21 )
return - V_62 ;
V_24 = V_18 -> V_24 [ args -> V_61 ] ;
if ( ! V_24 )
return - V_63 ;
V_75 = F_48 ( V_27 , args -> V_72 ) ;
if ( ! V_75 )
return - V_80 ;
if ( args -> V_67 & V_88 )
V_81 = NULL ;
V_25 = F_63 ( V_24 , V_75 , V_81 ) ;
F_51 ( V_75 ) ;
return V_25 ;
}
static int F_64 ( struct V_102 * V_9 )
{
struct V_17 * V_18 ;
struct V_16 * V_103 ;
int V_25 ;
V_103 = F_65 ( & V_104 , V_9 ) ;
if ( F_5 ( V_103 ) )
return F_7 ( V_103 ) ;
V_18 = F_18 ( sizeof( * V_18 ) , V_30 ) ;
if ( ! V_18 ) {
F_6 ( V_9 , L_12 ) ;
V_25 = - V_31 ;
goto V_105;
}
V_103 -> V_19 = V_18 ;
V_18 -> V_106 = F_66 ( L_13 , 0 ) ;
if ( ! V_18 -> V_106 ) {
V_25 = - V_31 ;
goto V_107;
}
F_67 ( & V_18 -> V_108 ) ;
F_68 ( & V_18 -> V_109 ) ;
V_18 -> V_110 = 0 ;
F_69 ( V_9 , V_103 ) ;
V_25 = F_70 ( V_9 , V_103 ) ;
if ( V_25 < 0 )
goto V_111;
F_15 ( V_103 ) ;
V_25 = F_71 ( V_103 , 0 ) ;
if ( V_25 )
goto V_112;
return 0 ;
V_112:
F_72 ( V_9 , V_103 ) ;
V_111:
F_73 ( V_18 -> V_106 ) ;
F_74 ( V_18 -> V_106 ) ;
V_107:
F_22 ( V_18 ) ;
V_105:
F_75 ( V_103 ) ;
return V_25 ;
}
static void F_76 ( struct V_102 * V_9 )
{
struct V_16 * V_103 = F_77 ( V_9 ) ;
struct V_17 * V_18 = V_103 -> V_19 ;
F_78 ( V_103 ) ;
F_73 ( V_18 -> V_106 ) ;
F_74 ( V_18 -> V_106 ) ;
F_72 ( V_9 , V_103 ) ;
V_103 -> V_19 = NULL ;
F_22 ( V_18 ) ;
F_75 ( V_103 ) ;
}
static int F_79 ( struct V_102 * V_9 , void * V_13 )
{
struct V_113 * V_114 = V_13 ;
return V_9 -> V_115 == V_114 ;
}
static int F_80 ( struct V_102 * V_9 , void * V_13 )
{
return ! strcmp ( F_32 ( V_9 ) , V_13 ) ;
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_102 * V_9 = & V_2 -> V_9 ;
struct V_113 * V_53 = V_9 -> V_115 ;
struct V_116 * V_117 = NULL ;
F_82 ( & V_2 -> V_9 , F_83 ( 32 ) ) ;
if ( V_53 ) {
struct V_113 * V_118 ;
int V_20 ;
for ( V_20 = 0 ; ; V_20 ++ ) {
V_118 = F_84 ( V_53 , L_14 , V_20 ) ;
if ( ! V_118 )
break;
F_85 ( & V_2 -> V_9 , & V_117 ,
F_79 , V_118 ) ;
F_86 ( V_118 ) ;
}
} else if ( V_9 -> V_119 ) {
char * * V_120 = V_9 -> V_119 ;
unsigned V_20 ;
for ( V_20 = 0 ; V_120 [ V_20 ] ; V_20 ++ )
F_87 ( V_9 , & V_117 , F_80 , V_120 [ V_20 ] ) ;
}
return F_88 ( V_9 , & V_121 , V_117 ) ;
}
static int F_89 ( struct V_1 * V_2 )
{
F_90 ( & V_2 -> V_9 , & V_121 ) ;
return 0 ;
}
static int T_3 F_91 ( void )
{
int V_25 ;
F_92 () ;
V_25 = F_93 ( & V_122 ) ;
if ( V_25 != 0 )
return V_25 ;
V_25 = F_93 ( & V_123 ) ;
if ( V_25 != 0 )
F_94 ( & V_122 ) ;
return V_25 ;
}
static void T_4 F_95 ( void )
{
F_94 ( & V_122 ) ;
F_94 ( & V_123 ) ;
}
