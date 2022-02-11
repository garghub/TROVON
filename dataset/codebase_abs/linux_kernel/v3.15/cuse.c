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
return F_7 ( & V_18 , & V_14 , 1 , V_10 , & V_12 , V_20 ) ;
}
static T_2 F_8 ( struct V_8 * V_8 , const char T_3 * V_9 ,
T_4 V_10 , T_5 * V_11 )
{
T_5 V_12 = 0 ;
struct V_13 V_14 = { . V_15 = ( void T_3 * ) V_9 , . V_16 = V_10 } ;
struct V_17 V_18 = { . V_19 = 0 , . V_8 = V_8 } ;
return F_7 ( & V_18 , & V_14 , 1 , V_10 , & V_12 ,
V_21 | V_20 ) ;
}
static int F_9 ( struct V_22 * V_22 , struct V_8 * V_8 )
{
T_1 V_5 = V_22 -> V_23 -> V_24 ;
struct V_1 * V_25 = NULL , * V_12 ;
int V_26 ;
F_10 ( & V_27 ) ;
F_11 (pos, cuse_conntbl_head(devt), list)
if ( V_12 -> V_24 -> V_5 == V_5 ) {
F_12 ( & V_12 -> V_3 ) ;
V_25 = V_12 ;
break;
}
F_13 ( & V_27 ) ;
if ( ! V_25 )
return - V_28 ;
V_26 = F_14 ( & V_25 -> V_3 , 0 , V_8 , 0 ) ;
if ( V_26 )
F_15 ( & V_25 -> V_3 ) ;
return V_26 ;
}
static int F_16 ( struct V_22 * V_22 , struct V_8 * V_8 )
{
struct V_29 * V_30 = V_8 -> V_31 ;
struct V_2 * V_3 = V_30 -> V_3 ;
F_17 ( V_30 , V_8 -> V_32 ) ;
F_15 ( V_3 ) ;
return 0 ;
}
static long F_18 ( struct V_8 * V_8 , unsigned int V_33 ,
unsigned long V_34 )
{
struct V_29 * V_30 = V_8 -> V_31 ;
struct V_1 * V_25 = F_1 ( V_30 -> V_3 ) ;
unsigned int V_35 = 0 ;
if ( V_25 -> V_36 )
V_35 |= V_37 ;
return F_19 ( V_8 , V_33 , V_34 , V_35 ) ;
}
static long F_20 ( struct V_8 * V_8 , unsigned int V_33 ,
unsigned long V_34 )
{
struct V_29 * V_30 = V_8 -> V_31 ;
struct V_1 * V_25 = F_1 ( V_30 -> V_3 ) ;
unsigned int V_35 = V_38 ;
if ( V_25 -> V_36 )
V_35 |= V_37 ;
return F_19 ( V_8 , V_33 , V_34 , V_35 ) ;
}
static int F_21 ( char * * V_39 , char * V_40 , char * * V_41 , char * * V_42 )
{
char * V_43 = * V_39 ;
char * V_44 , * V_45 ;
while ( V_43 < V_40 && * V_43 == '\0' )
V_43 ++ ;
if ( V_43 == V_40 )
return 0 ;
if ( V_40 [ - 1 ] != '\0' ) {
F_22 ( V_46 L_1 ) ;
return - V_47 ;
}
V_44 = V_45 = V_43 ;
V_43 += strlen ( V_43 ) ;
if ( V_42 ) {
F_23 ( & V_45 , L_2 ) ;
if ( ! V_45 )
V_45 = V_44 + strlen ( V_44 ) ;
V_44 = F_24 ( V_44 ) ;
V_45 = F_24 ( V_45 ) ;
} else
V_44 = F_24 ( V_44 ) ;
if ( ! strlen ( V_44 ) ) {
F_22 ( V_46 L_3 ) ;
return - V_47 ;
}
* V_39 = V_43 ;
* V_41 = V_44 ;
if ( V_42 )
* V_42 = V_45 ;
return 1 ;
}
static int F_25 ( char * V_43 , T_4 V_48 , struct V_49 * V_50 )
{
char * V_40 = V_43 + V_48 ;
char * V_51 ( V_44 ) , * V_51 ( V_45 ) ;
int V_26 ;
while ( true ) {
V_26 = F_21 ( & V_43 , V_40 , & V_44 , & V_45 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( ! V_26 )
break;
if ( strcmp ( V_44 , L_4 ) == 0 )
V_50 -> V_52 = V_45 ;
else
F_22 ( V_53 L_5 ,
V_44 ) ;
}
if ( ! V_50 -> V_52 || ! strlen ( V_50 -> V_52 ) ) {
F_22 ( V_46 L_6 ) ;
return - V_47 ;
}
return 0 ;
}
static void F_26 ( struct V_54 * V_24 )
{
F_27 ( V_24 ) ;
}
static void F_28 ( struct V_2 * V_3 , struct V_55 * V_56 )
{
struct V_1 * V_25 = F_1 ( V_3 ) , * V_12 ;
struct V_57 * V_34 = V_56 -> V_58 . args [ 0 ] . V_59 ;
struct V_60 * V_60 = V_56 -> V_61 [ 0 ] ;
struct V_49 V_50 = { } ;
struct V_54 * V_24 ;
struct V_62 * V_62 ;
T_1 V_5 ;
int V_26 , V_63 ;
if ( V_56 -> V_58 . V_64 . error ||
V_34 -> V_65 != V_66 || V_34 -> V_67 < 11 ) {
goto V_68;
}
V_3 -> V_67 = V_34 -> V_67 ;
V_3 -> V_69 = F_29 ( unsigned , V_34 -> V_69 , 4096 ) ;
V_3 -> V_70 = F_29 ( unsigned , V_34 -> V_70 , 4096 ) ;
V_25 -> V_36 = V_34 -> V_35 & V_71 ;
V_26 = F_25 ( F_30 ( V_60 ) , V_56 -> V_58 . args [ 1 ] . V_72 ,
& V_50 ) ;
if ( V_26 )
goto V_68;
V_5 = F_31 ( V_34 -> V_73 , V_34 -> V_74 ) ;
if ( ! F_4 ( V_5 ) )
V_26 = F_32 ( & V_5 , F_5 ( V_5 ) , 1 , V_50 . V_52 ) ;
else
V_26 = F_33 ( V_5 , 1 , V_50 . V_52 ) ;
if ( V_26 ) {
F_22 ( V_46 L_7 ) ;
goto V_68;
}
V_26 = - V_75 ;
V_24 = F_34 ( sizeof( * V_24 ) , V_76 ) ;
if ( ! V_24 )
goto V_77;
F_35 ( V_24 ) ;
F_36 ( V_24 , 1 ) ;
V_24 -> V_78 = V_79 ;
V_24 -> V_5 = V_5 ;
V_24 -> V_80 = F_26 ;
F_37 ( V_24 , V_25 ) ;
F_38 ( V_24 , L_8 , V_50 . V_52 ) ;
F_10 ( & V_27 ) ;
for ( V_63 = 0 ; V_63 < V_7 ; ++ V_63 ) {
F_11 (pos, &cuse_conntbl[i], list)
if ( ! strcmp ( F_39 ( V_12 -> V_24 ) , F_39 ( V_24 ) ) )
goto V_81;
}
V_26 = F_40 ( V_24 ) ;
if ( V_26 )
goto V_81;
V_26 = - V_75 ;
V_62 = F_41 () ;
if ( ! V_62 )
goto V_81;
V_62 -> V_82 = V_83 ;
V_62 -> V_84 = & V_85 ;
V_26 = F_42 ( V_62 , V_5 , 1 ) ;
if ( V_26 )
goto V_86;
V_25 -> V_24 = V_24 ;
V_25 -> V_62 = V_62 ;
F_43 ( & V_25 -> V_87 , F_3 ( V_5 ) ) ;
F_13 ( & V_27 ) ;
F_36 ( V_24 , 0 ) ;
F_44 ( & V_24 -> V_88 , V_89 ) ;
V_58:
F_27 ( V_34 ) ;
F_45 ( V_60 ) ;
return;
V_86:
F_46 ( V_62 ) ;
V_81:
F_13 ( & V_27 ) ;
F_47 ( V_24 ) ;
V_77:
F_48 ( V_5 , 1 ) ;
V_68:
F_49 ( V_3 ) ;
goto V_58;
}
static int F_50 ( struct V_1 * V_25 )
{
int V_26 ;
struct V_55 * V_56 ;
struct V_60 * V_60 ;
struct V_2 * V_3 = & V_25 -> V_3 ;
struct V_90 * V_34 ;
void * V_91 ;
F_51 ( V_92 > V_93 ) ;
V_56 = F_52 ( V_3 , 1 ) ;
if ( F_53 ( V_56 ) ) {
V_26 = F_54 ( V_56 ) ;
goto V_68;
}
V_26 = - V_75 ;
V_60 = F_55 ( V_76 | V_94 ) ;
if ( ! V_60 )
goto V_95;
V_91 = F_34 ( sizeof( struct V_57 ) , V_76 ) ;
if ( ! V_91 )
goto V_96;
V_34 = & V_56 -> V_97 . V_90 ;
V_34 -> V_65 = V_66 ;
V_34 -> V_67 = V_98 ;
V_34 -> V_35 |= V_71 ;
V_56 -> V_99 . V_64 . V_100 = V_101 ;
V_56 -> V_99 . V_102 = 1 ;
V_56 -> V_99 . args [ 0 ] . V_72 = sizeof( struct V_90 ) ;
V_56 -> V_99 . args [ 0 ] . V_59 = V_34 ;
V_56 -> V_58 . V_102 = 2 ;
V_56 -> V_58 . args [ 0 ] . V_72 = sizeof( struct V_57 ) ;
V_56 -> V_58 . args [ 0 ] . V_59 = V_91 ;
V_56 -> V_58 . args [ 1 ] . V_72 = V_92 ;
V_56 -> V_58 . V_103 = 1 ;
V_56 -> V_58 . V_104 = 1 ;
V_56 -> V_61 [ 0 ] = V_60 ;
V_56 -> V_105 [ 0 ] . V_106 = V_56 -> V_58 . args [ 1 ] . V_72 ;
V_56 -> V_107 = 1 ;
V_56 -> V_40 = F_28 ;
F_56 ( V_3 , V_56 ) ;
return 0 ;
V_96:
F_45 ( V_60 ) ;
V_95:
F_57 ( V_3 , V_56 ) ;
V_68:
return V_26 ;
}
static void F_58 ( struct V_2 * V_3 )
{
struct V_1 * V_25 = F_1 ( V_3 ) ;
F_59 ( V_25 , V_3 . V_108 ) ;
}
static int F_60 ( struct V_22 * V_22 , struct V_8 * V_8 )
{
struct V_1 * V_25 ;
int V_26 ;
V_25 = F_34 ( sizeof( * V_25 ) , V_76 ) ;
if ( ! V_25 )
return - V_75 ;
F_61 ( & V_25 -> V_3 ) ;
F_62 ( & V_25 -> V_87 ) ;
V_25 -> V_3 . V_80 = F_58 ;
V_25 -> V_3 . V_109 = 1 ;
V_25 -> V_3 . V_110 = 1 ;
V_26 = F_50 ( V_25 ) ;
if ( V_26 ) {
F_15 ( & V_25 -> V_3 ) ;
return V_26 ;
}
V_8 -> V_31 = & V_25 -> V_3 ;
return 0 ;
}
static int F_63 ( struct V_22 * V_22 , struct V_8 * V_8 )
{
struct V_1 * V_25 = F_1 ( V_8 -> V_31 ) ;
int V_26 ;
F_10 ( & V_27 ) ;
F_64 ( & V_25 -> V_87 ) ;
F_13 ( & V_27 ) ;
if ( V_25 -> V_24 )
F_65 ( V_25 -> V_24 ) ;
if ( V_25 -> V_62 ) {
F_48 ( V_25 -> V_62 -> V_24 , 1 ) ;
F_46 ( V_25 -> V_62 ) ;
}
V_26 = F_66 ( V_22 , V_8 ) ;
return V_26 ;
}
static T_2 F_67 ( struct V_54 * V_24 ,
struct V_111 * V_112 , char * V_9 )
{
struct V_1 * V_25 = F_68 ( V_24 ) ;
return sprintf ( V_9 , L_9 , F_69 ( & V_25 -> V_3 . V_113 ) ) ;
}
static T_2 F_70 ( struct V_54 * V_24 ,
struct V_111 * V_112 ,
const char * V_9 , T_4 V_10 )
{
struct V_1 * V_25 = F_68 ( V_24 ) ;
F_71 ( & V_25 -> V_3 ) ;
return V_10 ;
}
static int T_6 F_72 ( void )
{
int V_63 , V_26 ;
for ( V_63 = 0 ; V_63 < V_7 ; V_63 ++ )
F_62 ( & V_6 [ V_63 ] ) ;
V_114 = V_115 ;
V_114 . V_82 = V_83 ;
V_114 . V_116 = F_60 ;
V_114 . V_80 = F_63 ;
V_79 = F_73 ( V_83 , L_10 ) ;
if ( F_53 ( V_79 ) )
return F_54 ( V_79 ) ;
V_79 -> V_117 = V_118 ;
V_26 = F_74 ( & V_119 ) ;
if ( V_26 ) {
F_75 ( V_79 ) ;
return V_26 ;
}
return 0 ;
}
static void T_7 F_76 ( void )
{
F_77 ( & V_119 ) ;
F_75 ( V_79 ) ;
}
