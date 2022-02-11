static struct V_1 * T_1 F_1 ( const char * V_2 ,
unsigned long V_3 )
{
return F_2 ( V_2 , V_3 , F_3 ( V_3 ) , 0 , NULL ) ;
}
static void T_1 F_4 ( char * V_4 , T_2 V_5 , T_2 V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
V_8 = F_5 ( & V_13 , V_4 ) ;
if ( ! V_8 )
return;
if ( F_6 ( V_8 ) )
goto V_14;
V_10 = F_7 ( V_8 ) ;
if ( ! V_10 )
goto V_14;
V_12 = F_8 ( V_10 , V_5 ) ;
if ( ! V_12 )
goto V_15;
F_9 ( & V_12 -> V_16 ) ;
F_10 ( V_12 , V_6 ) ;
F_11 ( & V_12 -> V_17 ) ;
V_15:
F_12 ( V_10 ) ;
V_14:
F_11 ( & V_8 -> V_17 ) ;
return;
}
static void T_1 F_13 ( char * V_18 )
{
char * V_19 ;
char * V_20 , * V_21 ;
char V_4 [ V_22 ] ;
T_2 V_5 , V_6 ;
V_21 = F_14 ( V_18 , V_23 ) ;
V_20 = V_21 ;
if ( ! V_20 )
return;
V_19 = F_15 ( & V_20 , L_1 ) ;
if ( ! V_19 || strlen ( V_19 ) >= V_22 )
goto V_24;
strncpy ( V_4 , V_19 , V_22 ) ;
V_19 = F_15 ( & V_20 , L_1 ) ;
if ( ! V_19 || F_16 ( V_19 , 0 , ( unsigned long long * ) & V_5 ) )
goto V_24;
V_19 = F_15 ( & V_20 , L_1 ) ;
if ( ! V_19 || F_16 ( V_19 , 0 , ( unsigned long long * ) & V_6 ) )
goto V_24;
F_17 ( V_21 ) ;
F_4 ( V_4 , V_5 , V_6 ) ;
return;
V_24:
F_17 ( V_21 ) ;
F_18 ( L_2 , V_18 ) ;
}
static int T_1 F_19 ( void )
{
int V_25 = - V_26 ;
V_27 = F_1 ( L_3 ,
sizeof( struct V_28 ) ) ;
if ( ! V_27 )
goto V_29;
V_30 = F_1 ( L_4 ,
sizeof( struct V_31 ) ) ;
if ( ! V_30 )
goto V_32;
V_33 =
F_20 ( & V_34 ) ;
if ( ! V_33 )
goto V_35;
F_21 ( V_33 ,
sizeof( struct V_36 ) ) ;
V_25 = F_22 ( & V_37 ) ;
if ( V_25 ) {
F_18 ( L_5 ) ;
goto V_38;
}
V_25 = F_23 ( & V_13 ) ;
if ( V_25 ) {
F_18 ( L_6
L_7 ) ;
goto V_39;
}
if ( V_40 )
F_13 ( V_40 ) ;
return 0 ;
V_39:
F_24 ( & V_37 ) ;
V_38:
F_25 ( V_33 ) ;
V_35:
F_26 ( V_30 ) ;
V_32:
F_26 ( V_27 ) ;
V_29:
return V_25 ;
}
static void T_3 F_27 ( void )
{
F_28 ( & V_13 ) ;
F_24 ( & V_37 ) ;
F_25 ( V_33 ) ;
F_26 ( V_30 ) ;
F_26 ( V_27 ) ;
}
struct V_11 * F_8 ( struct V_9 * V_10 ,
T_2 V_5 )
{
unsigned long V_41 ;
struct V_11 * V_12 ;
F_29 ( & V_10 -> V_42 , V_41 ) ;
F_30 (port, &adapter->port_list, list)
if ( V_12 -> V_5 == V_5 ) {
if ( ! F_31 ( & V_12 -> V_17 ) )
V_12 = NULL ;
F_32 ( & V_10 -> V_42 , V_41 ) ;
return V_12 ;
}
F_32 ( & V_10 -> V_42 , V_41 ) ;
return NULL ;
}
static int F_33 ( struct V_9 * V_10 )
{
V_10 -> V_43 . V_44 =
F_34 ( 1 , sizeof( struct V_45 ) ) ;
if ( ! V_10 -> V_43 . V_44 )
return - V_26 ;
V_10 -> V_43 . V_46 =
F_34 ( 1 , sizeof( struct V_45 ) ) ;
if ( ! V_10 -> V_43 . V_46 )
return - V_26 ;
V_10 -> V_43 . V_47 =
F_34 ( 1 , sizeof( struct V_45 ) ) ;
if ( ! V_10 -> V_43 . V_47 )
return - V_26 ;
V_10 -> V_43 . V_48 =
F_34 ( 1 , sizeof( struct V_45 ) ) ;
if ( ! V_10 -> V_43 . V_48 )
return - V_26 ;
V_10 -> V_43 . V_49 =
F_34 ( V_50 ,
sizeof( struct V_45 ) ) ;
if ( ! V_10 -> V_43 . V_49 )
return - V_26 ;
V_10 -> V_43 . V_51 =
F_35 ( 4 , V_27 ) ;
if ( ! V_10 -> V_43 . V_51 )
return - V_26 ;
F_36 ( sizeof( struct V_52 ) > V_53 ) ;
V_10 -> V_43 . V_54 =
F_37 ( V_50 , 0 ) ;
if ( ! V_10 -> V_43 . V_54 )
return - V_26 ;
V_10 -> V_43 . V_55 =
F_35 ( 1 , V_30 ) ;
if ( ! V_10 -> V_43 . V_55 )
return - V_26 ;
return 0 ;
}
static void F_38 ( struct V_9 * V_10 )
{
if ( V_10 -> V_43 . V_44 )
F_39 ( V_10 -> V_43 . V_44 ) ;
if ( V_10 -> V_43 . V_47 )
F_39 ( V_10 -> V_43 . V_47 ) ;
if ( V_10 -> V_43 . V_48 )
F_39 ( V_10 -> V_43 . V_48 ) ;
if ( V_10 -> V_43 . V_51 )
F_39 ( V_10 -> V_43 . V_51 ) ;
if ( V_10 -> V_43 . V_49 )
F_39 ( V_10 -> V_43 . V_49 ) ;
if ( V_10 -> V_43 . V_54 )
F_39 ( V_10 -> V_43 . V_54 ) ;
if ( V_10 -> V_43 . V_55 )
F_39 ( V_10 -> V_43 . V_55 ) ;
}
int F_40 ( struct V_9 * V_10 )
{
while ( F_41 ( & V_10 -> V_56 ) > 0 )
if ( F_42 ( V_10 -> V_57 ) ) {
if ( F_41 ( & V_10 -> V_56 ) >=
V_10 -> V_58 ) {
F_43 ( V_10 , 0 , L_8 ) ;
return 1 ;
}
break;
} else
F_44 ( & V_10 -> V_56 ) ;
return 0 ;
}
static void F_45 ( struct V_59 * V_60 )
{
F_40 ( F_46 ( V_60 , struct V_9 ,
V_61 ) ) ;
}
static void F_47 ( struct V_62 * V_63 , struct V_64 * V_65 )
{
struct V_9 * V_10 =
F_46 ( V_65 , struct V_9 , V_64 ) ;
F_48 ( V_63 , L_9 ,
F_49 ( & V_10 -> V_7 -> V_17 ) ,
V_10 -> V_66 ) ;
}
static int F_50 ( struct V_9 * V_10 )
{
char V_2 [ V_67 ] ;
snprintf ( V_2 , sizeof( V_2 ) , L_10 ,
F_49 ( & V_10 -> V_7 -> V_17 ) ) ;
V_10 -> V_68 = F_51 ( V_2 ) ;
if ( V_10 -> V_68 )
return 0 ;
return - V_26 ;
}
static void F_52 ( struct V_9 * V_10 )
{
if ( V_10 -> V_68 )
F_53 ( V_10 -> V_68 ) ;
V_10 -> V_68 = NULL ;
}
struct V_9 * F_54 ( struct V_7 * V_7 )
{
struct V_9 * V_10 ;
if ( ! F_31 ( & V_7 -> V_17 ) )
return F_55 ( - V_69 ) ;
V_10 = F_56 ( sizeof( struct V_9 ) , V_23 ) ;
if ( ! V_10 ) {
F_11 ( & V_7 -> V_17 ) ;
return F_55 ( - V_26 ) ;
}
F_57 ( & V_10 -> V_70 ) ;
V_7 -> V_71 = NULL ;
V_10 -> V_7 = V_7 ;
F_58 ( & V_10 -> V_61 , F_45 ) ;
F_58 ( & V_10 -> V_72 , V_73 ) ;
F_58 ( & V_10 -> V_74 , V_75 ) ;
if ( F_59 ( V_10 ) )
goto V_76;
if ( F_33 ( V_10 ) )
goto V_76;
V_10 -> V_77 = F_60 () ;
if ( ! V_10 -> V_77 )
goto V_76;
if ( F_61 ( V_10 ) )
goto V_76;
if ( F_50 ( V_10 ) )
goto V_76;
if ( F_62 ( V_10 ) )
goto V_76;
F_63 ( & V_10 -> V_42 ) ;
F_64 ( & V_10 -> V_78 ) ;
F_64 ( & V_10 -> V_79 . V_80 ) ;
F_58 ( & V_10 -> V_79 . V_60 , V_81 ) ;
F_65 ( & V_10 -> V_79 . V_82 ) ;
F_66 ( & V_10 -> V_83 ) ;
F_66 ( & V_10 -> V_84 ) ;
F_64 ( & V_10 -> V_85 ) ;
F_64 ( & V_10 -> V_86 ) ;
F_63 ( & V_10 -> V_87 ) ;
F_63 ( & V_10 -> V_88 ) ;
if ( F_67 ( V_10 ) )
goto V_76;
V_10 -> V_64 . V_89 = F_47 ;
F_68 ( & V_7 -> V_17 , V_10 ) ;
if ( F_69 ( & V_7 -> V_17 . V_90 ,
& V_91 ) )
goto V_76;
V_10 -> V_92 . V_93 = V_94 ;
V_10 -> V_7 -> V_17 . V_92 = & V_10 -> V_92 ;
if ( ! F_70 ( V_10 ) )
return V_10 ;
V_76:
F_71 ( V_10 ) ;
return F_55 ( - V_26 ) ;
}
void F_71 ( struct V_9 * V_10 )
{
struct V_7 * V_8 = V_10 -> V_7 ;
F_72 ( & V_10 -> V_72 ) ;
F_72 ( & V_10 -> V_61 ) ;
F_72 ( & V_10 -> V_74 ) ;
F_52 ( V_10 ) ;
F_73 ( V_10 -> V_95 ) ;
F_74 ( V_10 ) ;
F_75 ( & V_8 -> V_17 . V_90 , & V_91 ) ;
F_76 ( V_10 ) ;
F_77 ( V_10 ) ;
F_78 ( V_10 -> V_57 ) ;
F_12 ( V_10 ) ;
}
void F_79 ( struct V_96 * V_70 )
{
struct V_9 * V_10 = F_46 ( V_70 , struct V_9 ,
V_70 ) ;
struct V_7 * V_8 = V_10 -> V_7 ;
F_68 ( & V_10 -> V_7 -> V_17 , NULL ) ;
F_80 ( V_10 ) ;
F_38 ( V_10 ) ;
F_17 ( V_10 -> V_77 ) ;
F_17 ( V_10 -> V_97 ) ;
F_17 ( V_10 -> V_98 ) ;
F_17 ( V_10 ) ;
F_11 ( & V_8 -> V_17 ) ;
}
void F_81 ( struct V_99 * V_17 ,
const struct V_100 * V_101 )
{
F_75 ( & V_17 -> V_90 , V_101 ) ;
F_82 ( V_17 ) ;
}
static void F_83 ( struct V_99 * V_17 )
{
struct V_11 * V_12 = F_46 ( V_17 , struct V_11 , V_17 ) ;
F_12 ( V_12 -> V_10 ) ;
F_17 ( V_12 ) ;
}
struct V_11 * F_84 ( struct V_9 * V_10 , T_2 V_5 ,
T_4 V_102 , T_4 V_103 )
{
struct V_11 * V_12 ;
int V_25 = - V_26 ;
F_85 ( & V_10 -> V_70 ) ;
V_12 = F_8 ( V_10 , V_5 ) ;
if ( V_12 ) {
F_11 ( & V_12 -> V_17 ) ;
V_25 = - V_104 ;
goto V_24;
}
V_12 = F_56 ( sizeof( struct V_11 ) , V_23 ) ;
if ( ! V_12 )
goto V_24;
F_63 ( & V_12 -> V_105 ) ;
F_64 ( & V_12 -> V_106 ) ;
F_58 ( & V_12 -> V_107 , V_108 ) ;
F_58 ( & V_12 -> V_109 , V_110 ) ;
F_58 ( & V_12 -> V_16 , V_111 ) ;
V_12 -> V_10 = V_10 ;
V_12 -> V_103 = V_103 ;
V_12 -> V_5 = V_5 ;
V_12 -> V_112 = V_113 ;
V_12 -> V_17 . V_114 = & V_10 -> V_7 -> V_17 ;
V_12 -> V_17 . V_115 = F_83 ;
if ( F_86 ( & V_12 -> V_17 , L_11 , ( unsigned long long ) V_5 ) ) {
F_17 ( V_12 ) ;
goto V_24;
}
V_25 = - V_116 ;
if ( F_87 ( & V_12 -> V_17 ) ) {
F_11 ( & V_12 -> V_17 ) ;
goto V_24;
}
if ( F_69 ( & V_12 -> V_17 . V_90 ,
& V_117 ) )
goto V_118;
F_88 ( & V_10 -> V_42 ) ;
F_89 ( & V_12 -> V_80 , & V_10 -> V_78 ) ;
F_90 ( & V_10 -> V_42 ) ;
F_91 ( V_102 | V_119 , & V_12 -> V_102 ) ;
return V_12 ;
V_118:
F_82 ( & V_12 -> V_17 ) ;
V_24:
F_12 ( V_10 ) ;
return F_55 ( V_25 ) ;
}
void F_92 ( struct V_120 * V_121 , int V_122 )
{
int V_123 ;
for ( V_123 = 0 ; V_123 < V_122 ; V_123 ++ , V_121 ++ )
if ( V_121 )
F_93 ( ( unsigned long ) F_94 ( V_121 ) ) ;
else
break;
}
int F_95 ( struct V_120 * V_121 , int V_122 )
{
void * V_124 ;
int V_123 ;
F_96 ( V_121 , V_122 ) ;
for ( V_123 = 0 ; V_123 < V_122 ; V_123 ++ , V_121 ++ ) {
V_124 = ( void * ) F_97 ( V_23 ) ;
if ( ! V_124 ) {
F_92 ( V_121 , V_123 ) ;
return - V_26 ;
}
F_98 ( V_121 , V_124 , V_53 ) ;
}
return 0 ;
}
