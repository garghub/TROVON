static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static struct V_4 * F_3 ( T_1 V_5 )
{
return & V_6 [ ( F_4 ( V_5 ) + F_5 ( V_5 ) ) % V_7 ] ;
}
static T_2 F_6 ( struct V_8 * V_8 , char T_3 * V_9 , T_4 V_10 ,
T_5 * V_11 )
{
T_5 V_12 = 0 ;
struct V_13 V_14 = { . V_15 = V_9 , . V_16 = V_10 } ;
struct V_17 V_18 = { . V_19 = 0 , . V_8 = V_8 } ;
struct V_20 V_21 ;
F_7 ( & V_21 , V_22 , & V_14 , 1 , V_10 ) ;
return F_8 ( & V_18 , & V_21 , & V_12 , V_23 ) ;
}
static T_2 F_9 ( struct V_8 * V_8 , const char T_3 * V_9 ,
T_4 V_10 , T_5 * V_11 )
{
T_5 V_12 = 0 ;
struct V_13 V_14 = { . V_15 = ( void T_3 * ) V_9 , . V_16 = V_10 } ;
struct V_17 V_18 = { . V_19 = 0 , . V_8 = V_8 } ;
struct V_20 V_21 ;
F_7 ( & V_21 , V_24 , & V_14 , 1 , V_10 ) ;
return F_8 ( & V_18 , & V_21 , & V_12 ,
V_25 | V_23 ) ;
}
static int F_10 ( struct V_26 * V_26 , struct V_8 * V_8 )
{
T_1 V_5 = V_26 -> V_27 -> V_28 ;
struct V_1 * V_29 = NULL , * V_12 ;
int V_30 ;
F_11 ( & V_31 ) ;
F_12 (pos, cuse_conntbl_head(devt), list)
if ( V_12 -> V_28 -> V_5 == V_5 ) {
F_13 ( & V_12 -> V_3 ) ;
V_29 = V_12 ;
break;
}
F_14 ( & V_31 ) ;
if ( ! V_29 )
return - V_32 ;
V_30 = F_15 ( & V_29 -> V_3 , 0 , V_8 , 0 ) ;
if ( V_30 )
F_16 ( & V_29 -> V_3 ) ;
return V_30 ;
}
static int F_17 ( struct V_26 * V_26 , struct V_8 * V_8 )
{
struct V_33 * V_34 = V_8 -> V_35 ;
struct V_2 * V_3 = V_34 -> V_3 ;
F_18 ( V_34 , V_8 -> V_36 ) ;
F_16 ( V_3 ) ;
return 0 ;
}
static long F_19 ( struct V_8 * V_8 , unsigned int V_37 ,
unsigned long V_38 )
{
struct V_33 * V_34 = V_8 -> V_35 ;
struct V_1 * V_29 = F_1 ( V_34 -> V_3 ) ;
unsigned int V_39 = 0 ;
if ( V_29 -> V_40 )
V_39 |= V_41 ;
return F_20 ( V_8 , V_37 , V_38 , V_39 ) ;
}
static long F_21 ( struct V_8 * V_8 , unsigned int V_37 ,
unsigned long V_38 )
{
struct V_33 * V_34 = V_8 -> V_35 ;
struct V_1 * V_29 = F_1 ( V_34 -> V_3 ) ;
unsigned int V_39 = V_42 ;
if ( V_29 -> V_40 )
V_39 |= V_41 ;
return F_20 ( V_8 , V_37 , V_38 , V_39 ) ;
}
static int F_22 ( char * * V_43 , char * V_44 , char * * V_45 , char * * V_46 )
{
char * V_47 = * V_43 ;
char * V_48 , * V_49 ;
while ( V_47 < V_44 && * V_47 == '\0' )
V_47 ++ ;
if ( V_47 == V_44 )
return 0 ;
if ( V_44 [ - 1 ] != '\0' ) {
F_23 ( V_50 L_1 ) ;
return - V_51 ;
}
V_48 = V_49 = V_47 ;
V_47 += strlen ( V_47 ) ;
if ( V_46 ) {
F_24 ( & V_49 , L_2 ) ;
if ( ! V_49 )
V_49 = V_48 + strlen ( V_48 ) ;
V_48 = F_25 ( V_48 ) ;
V_49 = F_25 ( V_49 ) ;
} else
V_48 = F_25 ( V_48 ) ;
if ( ! strlen ( V_48 ) ) {
F_23 ( V_50 L_3 ) ;
return - V_51 ;
}
* V_43 = V_47 ;
* V_45 = V_48 ;
if ( V_46 )
* V_46 = V_49 ;
return 1 ;
}
static int F_26 ( char * V_47 , T_4 V_52 , struct V_53 * V_54 )
{
char * V_44 = V_47 + V_52 ;
char * V_55 ( V_48 ) , * V_55 ( V_49 ) ;
int V_30 ;
while ( true ) {
V_30 = F_22 ( & V_47 , V_44 , & V_48 , & V_49 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( ! V_30 )
break;
if ( strcmp ( V_48 , L_4 ) == 0 )
V_54 -> V_56 = V_49 ;
else
F_23 ( V_57 L_5 ,
V_48 ) ;
}
if ( ! V_54 -> V_56 || ! strlen ( V_54 -> V_56 ) ) {
F_23 ( V_50 L_6 ) ;
return - V_51 ;
}
return 0 ;
}
static void F_27 ( struct V_58 * V_28 )
{
F_28 ( V_28 ) ;
}
static void F_29 ( struct V_2 * V_3 , struct V_59 * V_60 )
{
struct V_1 * V_29 = F_1 ( V_3 ) , * V_12 ;
struct V_61 * V_38 = V_60 -> V_62 . args [ 0 ] . V_63 ;
struct V_64 * V_64 = V_60 -> V_65 [ 0 ] ;
struct V_53 V_54 = { } ;
struct V_58 * V_28 ;
struct V_66 * V_66 ;
T_1 V_5 ;
int V_30 , V_67 ;
if ( V_60 -> V_62 . V_68 . error ||
V_38 -> V_69 != V_70 || V_38 -> V_71 < 11 ) {
goto V_72;
}
V_3 -> V_71 = V_38 -> V_71 ;
V_3 -> V_73 = F_30 ( unsigned , V_38 -> V_73 , 4096 ) ;
V_3 -> V_74 = F_30 ( unsigned , V_38 -> V_74 , 4096 ) ;
V_29 -> V_40 = V_38 -> V_39 & V_75 ;
V_30 = F_26 ( F_31 ( V_64 ) , V_60 -> V_62 . args [ 1 ] . V_76 ,
& V_54 ) ;
if ( V_30 )
goto V_72;
V_5 = F_32 ( V_38 -> V_77 , V_38 -> V_78 ) ;
if ( ! F_4 ( V_5 ) )
V_30 = F_33 ( & V_5 , F_5 ( V_5 ) , 1 , V_54 . V_56 ) ;
else
V_30 = F_34 ( V_5 , 1 , V_54 . V_56 ) ;
if ( V_30 ) {
F_23 ( V_50 L_7 ) ;
goto V_72;
}
V_30 = - V_79 ;
V_28 = F_35 ( sizeof( * V_28 ) , V_80 ) ;
if ( ! V_28 )
goto V_81;
F_36 ( V_28 ) ;
F_37 ( V_28 , 1 ) ;
V_28 -> V_82 = V_83 ;
V_28 -> V_5 = V_5 ;
V_28 -> V_84 = F_27 ;
F_38 ( V_28 , V_29 ) ;
F_39 ( V_28 , L_8 , V_54 . V_56 ) ;
F_11 ( & V_31 ) ;
for ( V_67 = 0 ; V_67 < V_7 ; ++ V_67 ) {
F_12 (pos, &cuse_conntbl[i], list)
if ( ! strcmp ( F_40 ( V_12 -> V_28 ) , F_40 ( V_28 ) ) )
goto V_85;
}
V_30 = F_41 ( V_28 ) ;
if ( V_30 )
goto V_85;
V_30 = - V_79 ;
V_66 = F_42 () ;
if ( ! V_66 )
goto V_85;
V_66 -> V_86 = V_87 ;
V_66 -> V_88 = & V_89 ;
V_30 = F_43 ( V_66 , V_5 , 1 ) ;
if ( V_30 )
goto V_90;
V_29 -> V_28 = V_28 ;
V_29 -> V_66 = V_66 ;
F_44 ( & V_29 -> V_91 , F_3 ( V_5 ) ) ;
F_14 ( & V_31 ) ;
F_37 ( V_28 , 0 ) ;
F_45 ( & V_28 -> V_92 , V_93 ) ;
V_62:
F_28 ( V_38 ) ;
F_46 ( V_64 ) ;
return;
V_90:
F_47 ( V_66 ) ;
V_85:
F_14 ( & V_31 ) ;
F_48 ( V_28 ) ;
V_81:
F_49 ( V_5 , 1 ) ;
V_72:
F_50 ( V_3 ) ;
goto V_62;
}
static int F_51 ( struct V_1 * V_29 )
{
int V_30 ;
struct V_59 * V_60 ;
struct V_64 * V_64 ;
struct V_2 * V_3 = & V_29 -> V_3 ;
struct V_94 * V_38 ;
void * V_95 ;
F_52 ( V_96 > V_97 ) ;
V_60 = F_53 ( V_3 , 1 ) ;
if ( F_54 ( V_60 ) ) {
V_30 = F_55 ( V_60 ) ;
goto V_72;
}
V_30 = - V_79 ;
V_64 = F_56 ( V_80 | V_98 ) ;
if ( ! V_64 )
goto V_99;
V_95 = F_35 ( sizeof( struct V_61 ) , V_80 ) ;
if ( ! V_95 )
goto V_100;
V_38 = & V_60 -> V_101 . V_94 ;
V_38 -> V_69 = V_70 ;
V_38 -> V_71 = V_102 ;
V_38 -> V_39 |= V_75 ;
V_60 -> V_103 . V_68 . V_104 = V_105 ;
V_60 -> V_103 . V_106 = 1 ;
V_60 -> V_103 . args [ 0 ] . V_76 = sizeof( struct V_94 ) ;
V_60 -> V_103 . args [ 0 ] . V_63 = V_38 ;
V_60 -> V_62 . V_106 = 2 ;
V_60 -> V_62 . args [ 0 ] . V_76 = sizeof( struct V_61 ) ;
V_60 -> V_62 . args [ 0 ] . V_63 = V_95 ;
V_60 -> V_62 . args [ 1 ] . V_76 = V_96 ;
V_60 -> V_62 . V_107 = 1 ;
V_60 -> V_62 . V_108 = 1 ;
V_60 -> V_65 [ 0 ] = V_64 ;
V_60 -> V_109 [ 0 ] . V_110 = V_60 -> V_62 . args [ 1 ] . V_76 ;
V_60 -> V_111 = 1 ;
V_60 -> V_44 = F_29 ;
F_57 ( V_3 , V_60 ) ;
return 0 ;
V_100:
F_46 ( V_64 ) ;
V_99:
F_58 ( V_3 , V_60 ) ;
V_72:
return V_30 ;
}
static void F_59 ( struct V_2 * V_3 )
{
struct V_1 * V_29 = F_1 ( V_3 ) ;
F_60 ( V_29 , V_3 . V_112 ) ;
}
static int F_61 ( struct V_26 * V_26 , struct V_8 * V_8 )
{
struct V_1 * V_29 ;
int V_30 ;
V_29 = F_35 ( sizeof( * V_29 ) , V_80 ) ;
if ( ! V_29 )
return - V_79 ;
F_62 ( & V_29 -> V_3 ) ;
F_63 ( & V_29 -> V_91 ) ;
V_29 -> V_3 . V_84 = F_59 ;
V_29 -> V_3 . V_113 = 1 ;
V_29 -> V_3 . V_114 = 1 ;
V_30 = F_51 ( V_29 ) ;
if ( V_30 ) {
F_16 ( & V_29 -> V_3 ) ;
return V_30 ;
}
V_8 -> V_35 = & V_29 -> V_3 ;
return 0 ;
}
static int F_64 ( struct V_26 * V_26 , struct V_8 * V_8 )
{
struct V_1 * V_29 = F_1 ( V_8 -> V_35 ) ;
int V_30 ;
F_11 ( & V_31 ) ;
F_65 ( & V_29 -> V_91 ) ;
F_14 ( & V_31 ) ;
if ( V_29 -> V_28 )
F_66 ( V_29 -> V_28 ) ;
if ( V_29 -> V_66 ) {
F_49 ( V_29 -> V_66 -> V_28 , 1 ) ;
F_47 ( V_29 -> V_66 ) ;
}
V_30 = F_67 ( V_26 , V_8 ) ;
return V_30 ;
}
static T_2 F_68 ( struct V_58 * V_28 ,
struct V_115 * V_116 , char * V_9 )
{
struct V_1 * V_29 = F_69 ( V_28 ) ;
return sprintf ( V_9 , L_9 , F_70 ( & V_29 -> V_3 . V_117 ) ) ;
}
static T_2 F_71 ( struct V_58 * V_28 ,
struct V_115 * V_116 ,
const char * V_9 , T_4 V_10 )
{
struct V_1 * V_29 = F_69 ( V_28 ) ;
F_72 ( & V_29 -> V_3 ) ;
return V_10 ;
}
static int T_6 F_73 ( void )
{
int V_67 , V_30 ;
for ( V_67 = 0 ; V_67 < V_7 ; V_67 ++ )
F_63 ( & V_6 [ V_67 ] ) ;
V_118 = V_119 ;
V_118 . V_86 = V_87 ;
V_118 . V_120 = F_61 ;
V_118 . V_84 = F_64 ;
V_83 = F_74 ( V_87 , L_10 ) ;
if ( F_54 ( V_83 ) )
return F_55 ( V_83 ) ;
V_83 -> V_121 = V_122 ;
V_30 = F_75 ( & V_123 ) ;
if ( V_30 ) {
F_76 ( V_83 ) ;
return V_30 ;
}
return 0 ;
}
static void T_7 F_77 ( void )
{
F_78 ( & V_123 ) ;
F_76 ( V_83 ) ;
}
