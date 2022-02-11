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
if ( V_25 ) {
F_6 ( V_23 -> V_9 , L_5 , V_25 ) ;
V_18 -> V_24 [ V_20 ] = NULL ;
}
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
int V_25 ;
F_26 ( & V_9 -> V_37 -> V_38 ) ;
V_25 = F_27 ( V_36 , & V_9 -> V_37 -> V_39 ) ;
F_28 ( & V_9 -> V_37 -> V_38 ) ;
return V_25 ;
}
static int F_29 ( struct V_22 * V_24 , struct V_35 * V_36 )
{
F_30 ( V_36 , L_6 , F_31 ( V_24 -> V_9 ) ) ;
F_20 ( & V_24 -> V_40 -> V_33 ) ;
F_27 ( V_36 , & V_24 -> V_40 -> V_41 ) ;
F_21 ( & V_24 -> V_40 -> V_33 ) ;
return 0 ;
}
static void F_32 ( struct V_22 * V_24 , struct V_35 * V_36 )
{
struct V_42 * V_43 = V_24 -> V_44 ;
T_2 V_45 = V_43 -> V_45 ;
T_2 * V_7 = V_43 -> V_46 ;
T_2 V_20 ;
F_30 ( V_36 , L_7 ,
V_43 -> V_46 , ( V_47 ) V_43 -> V_48 , V_45 - V_43 -> V_49 ) ;
for ( V_20 = 0 ; V_20 < V_45 / 4 ; V_20 ++ ) {
if ( V_20 && ! ( V_20 % 4 ) )
F_33 ( V_36 , L_8 ) ;
if ( V_20 % 4 == 0 )
F_30 ( V_36 , L_9 , V_7 + V_20 ) ;
F_30 ( V_36 , L_10 , * ( V_7 + V_20 ) ) ;
}
F_33 ( V_36 , L_8 ) ;
}
static int F_34 ( struct V_22 * V_24 , struct V_35 * V_36 )
{
F_30 ( V_36 , L_11 , F_31 ( V_24 -> V_9 ) ) ;
F_20 ( & V_24 -> V_33 ) ;
F_32 ( V_24 , V_36 ) ;
F_21 ( & V_24 -> V_33 ) ;
return 0 ;
}
static int F_35 ( struct V_35 * V_36 , void * V_50 )
{
struct V_51 * V_52 = (struct V_51 * ) V_36 -> V_53 ;
struct V_16 * V_9 = V_52 -> V_54 -> V_9 ;
int (* F_36)( struct V_16 * V_9 , struct V_35 * V_36 ) =
V_52 -> V_55 -> V_13 ;
return F_36 ( V_9 , V_36 ) ;
}
static int F_37 ( struct V_35 * V_36 , void * V_50 )
{
struct V_51 * V_52 = (struct V_51 * ) V_36 -> V_53 ;
struct V_16 * V_9 = V_52 -> V_54 -> V_9 ;
struct V_17 * V_18 = V_9 -> V_19 ;
struct V_22 * V_24 ;
int (* F_36)( struct V_22 * V_24 , struct V_35 * V_36 ) =
V_52 -> V_55 -> V_13 ;
unsigned int V_20 ;
int V_25 = 0 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
V_24 = V_18 -> V_24 [ V_20 ] ;
if ( ! V_24 )
continue;
V_25 = F_36 ( V_24 , V_36 ) ;
if ( V_25 < 0 )
break;
}
return V_25 ;
}
static int F_38 ( struct V_56 * V_54 )
{
struct V_16 * V_9 = V_54 -> V_9 ;
int V_25 ;
V_25 = F_39 ( V_57 ,
F_40 ( V_57 ) ,
V_54 -> V_58 , V_54 ) ;
if ( V_25 ) {
F_6 ( V_9 -> V_9 , L_12 ) ;
return V_25 ;
}
return V_25 ;
}
static void F_41 ( struct V_56 * V_54 )
{
F_42 ( V_57 ,
F_40 ( V_57 ) , V_54 ) ;
}
static int F_43 ( struct V_16 * V_9 , void * V_13 ,
struct V_26 * V_27 )
{
struct V_17 * V_18 = V_9 -> V_19 ;
struct V_59 * args = V_13 ;
struct V_22 * V_24 ;
if ( args -> V_60 >= V_21 )
return - V_61 ;
V_24 = V_18 -> V_24 [ args -> V_60 ] ;
if ( ! V_24 )
return - V_62 ;
return F_44 ( V_24 , args -> V_63 , & args -> V_64 ) ;
}
static int F_45 ( struct V_16 * V_9 , void * V_13 ,
struct V_26 * V_27 )
{
struct V_65 * args = V_13 ;
if ( args -> V_66 & ~ ( V_67 | V_68 | V_69 |
V_70 ) )
return - V_61 ;
return F_46 ( V_9 , V_27 , args -> V_45 ,
args -> V_66 , & args -> V_71 ) ;
}
static int F_47 ( struct V_16 * V_9 , void * V_13 ,
struct V_26 * V_27 )
{
struct V_72 * args = V_13 ;
struct V_73 * V_74 ;
int V_25 ;
if ( args -> V_75 & ~ ( V_76 | V_77 | V_78 ) )
return - V_61 ;
V_74 = F_48 ( V_27 , args -> V_71 ) ;
if ( ! V_74 )
return - V_79 ;
V_25 = F_49 ( V_74 , args -> V_75 , & F_50 ( args -> V_80 ) ) ;
F_51 ( V_74 ) ;
return V_25 ;
}
static int F_52 ( struct V_16 * V_9 , void * V_13 ,
struct V_26 * V_27 )
{
struct V_81 * args = V_13 ;
struct V_73 * V_74 ;
int V_25 ;
if ( args -> V_66 )
return - V_61 ;
V_74 = F_48 ( V_27 , args -> V_71 ) ;
if ( ! V_74 )
return - V_79 ;
V_25 = F_53 ( V_74 ) ;
F_51 ( V_74 ) ;
return V_25 ;
}
static int F_54 ( struct V_16 * V_9 , void * V_13 ,
struct V_26 * V_27 )
{
struct V_82 * args = V_13 ;
struct V_73 * V_74 ;
int V_25 ;
if ( args -> V_83 )
return - V_61 ;
V_74 = F_48 ( V_27 , args -> V_71 ) ;
if ( ! V_74 )
return - V_79 ;
V_25 = F_55 ( V_74 , & args -> V_84 ) ;
F_51 ( V_74 ) ;
return V_25 ;
}
static int F_56 ( struct V_16 * V_9 , void * V_13 ,
struct V_26 * V_27 )
{
struct V_85 * args = V_13 ;
struct V_17 * V_18 = V_9 -> V_19 ;
struct V_86 * V_80 = & F_50 ( args -> V_80 ) ;
struct V_22 * V_24 ;
if ( args -> V_66 & ~ ( V_87 ) )
return - V_61 ;
if ( args -> V_60 >= V_21 )
return - V_61 ;
V_24 = V_18 -> V_24 [ args -> V_60 ] ;
if ( ! V_24 )
return - V_62 ;
if ( args -> V_66 & V_87 )
V_80 = NULL ;
return F_57 ( V_24 , args -> V_88 ,
V_80 ) ;
}
static int F_58 ( struct V_16 * V_9 , void * V_13 ,
struct V_26 * V_27 )
{
struct V_89 * args = V_13 ;
int V_90 ;
if ( args -> V_66 & ~ ( V_91 | V_92 ) ||
args -> V_66 == 0 )
return - V_61 ;
if ( F_59 ( args -> V_93 | args -> V_49 ) ||
( V_94 ) args -> V_93 != args -> V_93 ||
( T_2 ) args -> V_49 != args -> V_49 ||
args -> V_93 & ~ V_95 )
return - V_61 ;
if ( args -> V_66 & V_92 )
V_90 = V_96 ;
else
V_90 = V_97 ;
if ( ! F_60 ( V_90 , ( void V_98 * ) ( unsigned long ) args -> V_93 ,
args -> V_49 ) )
return - V_99 ;
return F_61 ( V_9 , V_27 , args -> V_93 ,
args -> V_49 , args -> V_66 ,
& args -> V_71 ) ;
}
static int F_62 ( struct V_16 * V_9 , void * V_13 ,
struct V_26 * V_27 )
{
struct V_17 * V_18 = V_9 -> V_19 ;
struct V_100 * args = V_13 ;
struct V_86 * V_80 = & F_50 ( args -> V_80 ) ;
struct V_73 * V_74 ;
struct V_22 * V_24 ;
int V_25 ;
if ( args -> V_66 & ~ ( V_87 ) )
return - V_61 ;
if ( args -> V_60 >= V_21 )
return - V_61 ;
V_24 = V_18 -> V_24 [ args -> V_60 ] ;
if ( ! V_24 )
return - V_62 ;
V_74 = F_48 ( V_27 , args -> V_71 ) ;
if ( ! V_74 )
return - V_79 ;
if ( args -> V_66 & V_87 )
V_80 = NULL ;
V_25 = F_63 ( V_24 , V_74 , V_80 ) ;
F_51 ( V_74 ) ;
return V_25 ;
}
static int F_64 ( struct V_101 * V_9 )
{
struct V_17 * V_18 ;
struct V_16 * V_102 ;
int V_25 ;
V_102 = F_65 ( & V_103 , V_9 ) ;
if ( ! V_102 )
return - V_31 ;
V_102 -> V_104 = F_66 ( V_9 ) ;
V_18 = F_18 ( sizeof( * V_18 ) , V_30 ) ;
if ( ! V_18 ) {
F_6 ( V_9 , L_13 ) ;
V_25 = - V_31 ;
goto V_105;
}
V_102 -> V_19 = V_18 ;
V_18 -> V_106 = F_67 ( L_14 , 0 ) ;
if ( ! V_18 -> V_106 ) {
V_25 = - V_31 ;
goto V_107;
}
F_68 ( & V_18 -> V_108 ) ;
F_69 ( & V_18 -> V_109 ) ;
V_18 -> V_110 = 0 ;
F_70 ( V_9 , V_102 ) ;
V_25 = F_71 ( V_9 , V_102 ) ;
if ( V_25 < 0 )
goto V_111;
F_15 ( V_102 ) ;
V_25 = F_72 ( V_102 , 0 ) ;
if ( V_25 )
goto V_112;
return 0 ;
V_112:
F_73 ( V_9 , V_102 ) ;
V_111:
F_74 ( V_18 -> V_106 ) ;
F_75 ( V_18 -> V_106 ) ;
V_107:
F_22 ( V_18 ) ;
V_105:
F_76 ( V_102 ) ;
return V_25 ;
}
static void F_77 ( struct V_101 * V_9 )
{
struct V_16 * V_102 = F_78 ( V_9 ) ;
struct V_17 * V_18 = V_102 -> V_19 ;
F_79 ( V_102 ) ;
F_74 ( V_18 -> V_106 ) ;
F_75 ( V_18 -> V_106 ) ;
F_73 ( V_9 , V_102 ) ;
V_102 -> V_19 = NULL ;
F_22 ( V_18 ) ;
F_80 ( V_102 ) ;
}
static int F_81 ( struct V_101 * V_9 , void * V_13 )
{
struct V_113 * V_114 = V_13 ;
return V_9 -> V_115 == V_114 ;
}
static int F_82 ( struct V_101 * V_9 , void * V_13 )
{
return ! strcmp ( F_31 ( V_9 ) , V_13 ) ;
}
static int F_83 ( struct V_1 * V_2 )
{
struct V_101 * V_9 = & V_2 -> V_9 ;
struct V_113 * V_52 = V_9 -> V_115 ;
struct V_116 * V_117 = NULL ;
F_84 ( & V_2 -> V_9 , F_85 ( 32 ) ) ;
if ( V_52 ) {
struct V_113 * V_118 ;
int V_20 ;
for ( V_20 = 0 ; ; V_20 ++ ) {
V_118 = F_86 ( V_52 , L_15 , V_20 ) ;
if ( ! V_118 )
break;
F_87 ( & V_2 -> V_9 , & V_117 , F_81 ,
V_118 ) ;
F_88 ( V_118 ) ;
}
} else if ( V_9 -> V_119 ) {
char * * V_120 = V_9 -> V_119 ;
unsigned V_20 ;
for ( V_20 = 0 ; V_120 [ V_20 ] ; V_20 ++ )
F_87 ( V_9 , & V_117 , F_82 , V_120 [ V_20 ] ) ;
}
return F_89 ( V_9 , & V_121 , V_117 ) ;
}
static int F_90 ( struct V_1 * V_2 )
{
F_91 ( & V_2 -> V_9 , & V_121 ) ;
return 0 ;
}
static int T_3 F_92 ( void )
{
int V_25 ;
F_93 () ;
V_25 = F_94 ( & V_122 ) ;
if ( V_25 != 0 )
return V_25 ;
V_25 = F_94 ( & V_123 ) ;
if ( V_25 != 0 )
F_95 ( & V_122 ) ;
return V_25 ;
}
static void T_4 F_96 ( void )
{
F_95 ( & V_122 ) ;
F_95 ( & V_123 ) ;
}
