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
return F_7 ( V_8 , & V_14 , 1 , V_10 , & V_12 , 0 ) ;
}
static T_2 F_8 ( struct V_8 * V_8 , const char T_3 * V_9 ,
T_4 V_10 , T_5 * V_11 )
{
T_5 V_12 = 0 ;
struct V_13 V_14 = { . V_15 = ( void T_3 * ) V_9 , . V_16 = V_10 } ;
return F_7 ( V_8 , & V_14 , 1 , V_10 , & V_12 , 1 ) ;
}
static int F_9 ( struct V_17 * V_17 , struct V_8 * V_8 )
{
T_1 V_5 = V_17 -> V_18 -> V_19 ;
struct V_1 * V_20 = NULL , * V_12 ;
int V_21 ;
F_10 ( & V_22 ) ;
F_11 (pos, cuse_conntbl_head(devt), list)
if ( V_12 -> V_19 -> V_5 == V_5 ) {
F_12 ( & V_12 -> V_3 ) ;
V_20 = V_12 ;
break;
}
F_13 ( & V_22 ) ;
if ( ! V_20 )
return - V_23 ;
V_21 = F_14 ( & V_20 -> V_3 , 0 , V_8 , 0 ) ;
if ( V_21 )
F_15 ( & V_20 -> V_3 ) ;
return V_21 ;
}
static int F_16 ( struct V_17 * V_17 , struct V_8 * V_8 )
{
struct V_24 * V_25 = V_8 -> V_26 ;
struct V_2 * V_3 = V_25 -> V_3 ;
F_17 ( V_25 , V_8 -> V_27 ) ;
F_15 ( V_3 ) ;
return 0 ;
}
static long F_18 ( struct V_8 * V_8 , unsigned int V_28 ,
unsigned long V_29 )
{
struct V_24 * V_25 = V_8 -> V_26 ;
struct V_1 * V_20 = F_1 ( V_25 -> V_3 ) ;
unsigned int V_30 = 0 ;
if ( V_20 -> V_31 )
V_30 |= V_32 ;
return F_19 ( V_8 , V_28 , V_29 , V_30 ) ;
}
static long F_20 ( struct V_8 * V_8 , unsigned int V_28 ,
unsigned long V_29 )
{
struct V_24 * V_25 = V_8 -> V_26 ;
struct V_1 * V_20 = F_1 ( V_25 -> V_3 ) ;
unsigned int V_30 = V_33 ;
if ( V_20 -> V_31 )
V_30 |= V_32 ;
return F_19 ( V_8 , V_28 , V_29 , V_30 ) ;
}
static int F_21 ( char * * V_34 , char * V_35 , char * * V_36 , char * * V_37 )
{
char * V_38 = * V_34 ;
char * V_39 , * V_40 ;
while ( V_38 < V_35 && * V_38 == '\0' )
V_38 ++ ;
if ( V_38 == V_35 )
return 0 ;
if ( V_35 [ - 1 ] != '\0' ) {
F_22 ( V_41 L_1 ) ;
return - V_42 ;
}
V_39 = V_40 = V_38 ;
V_38 += strlen ( V_38 ) ;
if ( V_37 ) {
F_23 ( & V_40 , L_2 ) ;
if ( ! V_40 )
V_40 = V_39 + strlen ( V_39 ) ;
V_39 = F_24 ( V_39 ) ;
V_40 = F_24 ( V_40 ) ;
} else
V_39 = F_24 ( V_39 ) ;
if ( ! strlen ( V_39 ) ) {
F_22 ( V_41 L_3 ) ;
return - V_42 ;
}
* V_34 = V_38 ;
* V_36 = V_39 ;
if ( V_37 )
* V_37 = V_40 ;
return 1 ;
}
static int F_25 ( char * V_38 , T_4 V_43 , struct V_44 * V_45 )
{
char * V_35 = V_38 + V_43 ;
char * V_46 ( V_39 ) , * V_46 ( V_40 ) ;
int V_21 ;
while ( true ) {
V_21 = F_21 ( & V_38 , V_35 , & V_39 , & V_40 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( ! V_21 )
break;
if ( strcmp ( V_39 , L_4 ) == 0 )
V_45 -> V_47 = V_40 ;
else
F_22 ( V_48 L_5 ,
V_39 ) ;
}
if ( ! V_45 -> V_47 || ! strlen ( V_45 -> V_47 ) ) {
F_22 ( V_41 L_6 ) ;
return - V_42 ;
}
return 0 ;
}
static void F_26 ( struct V_49 * V_19 )
{
F_27 ( V_19 ) ;
}
static void F_28 ( struct V_2 * V_3 , struct V_50 * V_51 )
{
struct V_1 * V_20 = F_1 ( V_3 ) , * V_12 ;
struct V_52 * V_29 = V_51 -> V_53 . args [ 0 ] . V_54 ;
struct V_55 * V_55 = V_51 -> V_56 [ 0 ] ;
struct V_44 V_45 = { } ;
struct V_49 * V_19 ;
struct V_57 * V_57 ;
T_1 V_5 ;
int V_21 , V_58 ;
if ( V_51 -> V_53 . V_59 . error ||
V_29 -> V_60 != V_61 || V_29 -> V_62 < 11 ) {
goto V_63;
}
V_3 -> V_62 = V_29 -> V_62 ;
V_3 -> V_64 = F_29 ( unsigned , V_29 -> V_64 , 4096 ) ;
V_3 -> V_65 = F_29 ( unsigned , V_29 -> V_65 , 4096 ) ;
V_20 -> V_31 = V_29 -> V_30 & V_66 ;
V_21 = F_25 ( F_30 ( V_55 ) , V_51 -> V_53 . args [ 1 ] . V_67 ,
& V_45 ) ;
if ( V_21 )
goto V_63;
V_5 = F_31 ( V_29 -> V_68 , V_29 -> V_69 ) ;
if ( ! F_4 ( V_5 ) )
V_21 = F_32 ( & V_5 , F_5 ( V_5 ) , 1 , V_45 . V_47 ) ;
else
V_21 = F_33 ( V_5 , 1 , V_45 . V_47 ) ;
if ( V_21 ) {
F_22 ( V_41 L_7 ) ;
goto V_63;
}
V_21 = - V_70 ;
V_19 = F_34 ( sizeof( * V_19 ) , V_71 ) ;
if ( ! V_19 )
goto V_72;
F_35 ( V_19 ) ;
F_36 ( V_19 , 1 ) ;
V_19 -> V_73 = V_74 ;
V_19 -> V_5 = V_5 ;
V_19 -> V_75 = F_26 ;
F_37 ( V_19 , V_20 ) ;
F_38 ( V_19 , L_8 , V_45 . V_47 ) ;
F_10 ( & V_22 ) ;
for ( V_58 = 0 ; V_58 < V_7 ; ++ V_58 ) {
F_11 (pos, &cuse_conntbl[i], list)
if ( ! strcmp ( F_39 ( V_12 -> V_19 ) , F_39 ( V_19 ) ) )
goto V_76;
}
V_21 = F_40 ( V_19 ) ;
if ( V_21 )
goto V_76;
V_21 = - V_70 ;
V_57 = F_41 () ;
if ( ! V_57 )
goto V_76;
V_57 -> V_77 = V_78 ;
V_57 -> V_79 = & V_80 ;
V_21 = F_42 ( V_57 , V_5 , 1 ) ;
if ( V_21 )
goto V_81;
V_20 -> V_19 = V_19 ;
V_20 -> V_57 = V_57 ;
F_43 ( & V_20 -> V_82 , F_3 ( V_5 ) ) ;
F_13 ( & V_22 ) ;
F_36 ( V_19 , 0 ) ;
F_44 ( & V_19 -> V_83 , V_84 ) ;
V_53:
F_27 ( V_29 ) ;
F_45 ( V_55 ) ;
return;
V_81:
F_46 ( V_57 ) ;
V_76:
F_13 ( & V_22 ) ;
F_47 ( V_19 ) ;
V_72:
F_48 ( V_5 , 1 ) ;
V_63:
F_49 ( V_3 ) ;
goto V_53;
}
static int F_50 ( struct V_1 * V_20 )
{
int V_21 ;
struct V_50 * V_51 ;
struct V_55 * V_55 ;
struct V_2 * V_3 = & V_20 -> V_3 ;
struct V_85 * V_29 ;
void * V_86 ;
F_51 ( V_87 > V_88 ) ;
V_51 = F_52 ( V_3 , 1 ) ;
if ( F_53 ( V_51 ) ) {
V_21 = F_54 ( V_51 ) ;
goto V_63;
}
V_21 = - V_70 ;
V_55 = F_55 ( V_71 | V_89 ) ;
if ( ! V_55 )
goto V_90;
V_86 = F_34 ( sizeof( struct V_52 ) , V_71 ) ;
if ( ! V_86 )
goto V_91;
V_29 = & V_51 -> V_92 . V_85 ;
V_29 -> V_60 = V_61 ;
V_29 -> V_62 = V_93 ;
V_29 -> V_30 |= V_66 ;
V_51 -> V_94 . V_59 . V_95 = V_96 ;
V_51 -> V_94 . V_97 = 1 ;
V_51 -> V_94 . args [ 0 ] . V_67 = sizeof( struct V_85 ) ;
V_51 -> V_94 . args [ 0 ] . V_54 = V_29 ;
V_51 -> V_53 . V_97 = 2 ;
V_51 -> V_53 . args [ 0 ] . V_67 = sizeof( struct V_52 ) ;
V_51 -> V_53 . args [ 0 ] . V_54 = V_86 ;
V_51 -> V_53 . args [ 1 ] . V_67 = V_87 ;
V_51 -> V_53 . V_98 = 1 ;
V_51 -> V_53 . V_99 = 1 ;
V_51 -> V_56 [ 0 ] = V_55 ;
V_51 -> V_100 [ 0 ] . V_101 = V_51 -> V_53 . args [ 1 ] . V_67 ;
V_51 -> V_102 = 1 ;
V_51 -> V_35 = F_28 ;
F_56 ( V_3 , V_51 ) ;
return 0 ;
V_91:
F_45 ( V_55 ) ;
V_90:
F_57 ( V_3 , V_51 ) ;
V_63:
return V_21 ;
}
static void F_58 ( struct V_2 * V_3 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
F_27 ( V_20 ) ;
}
static int F_59 ( struct V_17 * V_17 , struct V_8 * V_8 )
{
struct V_1 * V_20 ;
int V_21 ;
V_20 = F_34 ( sizeof( * V_20 ) , V_71 ) ;
if ( ! V_20 )
return - V_70 ;
F_60 ( & V_20 -> V_3 ) ;
F_61 ( & V_20 -> V_82 ) ;
V_20 -> V_3 . V_75 = F_58 ;
V_20 -> V_3 . V_103 = 1 ;
V_20 -> V_3 . V_104 = 0 ;
V_21 = F_50 ( V_20 ) ;
if ( V_21 ) {
F_15 ( & V_20 -> V_3 ) ;
return V_21 ;
}
V_8 -> V_26 = & V_20 -> V_3 ;
return 0 ;
}
static int F_62 ( struct V_17 * V_17 , struct V_8 * V_8 )
{
struct V_1 * V_20 = F_1 ( V_8 -> V_26 ) ;
int V_21 ;
F_10 ( & V_22 ) ;
F_63 ( & V_20 -> V_82 ) ;
F_13 ( & V_22 ) ;
if ( V_20 -> V_19 )
F_64 ( V_20 -> V_19 ) ;
if ( V_20 -> V_57 ) {
F_48 ( V_20 -> V_57 -> V_19 , 1 ) ;
F_46 ( V_20 -> V_57 ) ;
}
V_21 = F_65 ( V_17 , V_8 ) ;
return V_21 ;
}
static T_2 F_66 ( struct V_49 * V_19 ,
struct V_105 * V_106 , char * V_9 )
{
struct V_1 * V_20 = F_67 ( V_19 ) ;
return sprintf ( V_9 , L_9 , F_68 ( & V_20 -> V_3 . V_107 ) ) ;
}
static T_2 F_69 ( struct V_49 * V_19 ,
struct V_105 * V_106 ,
const char * V_9 , T_4 V_10 )
{
struct V_1 * V_20 = F_67 ( V_19 ) ;
F_70 ( & V_20 -> V_3 ) ;
return V_10 ;
}
static int T_6 F_71 ( void )
{
int V_58 , V_21 ;
for ( V_58 = 0 ; V_58 < V_7 ; V_58 ++ )
F_61 ( & V_6 [ V_58 ] ) ;
V_108 = V_109 ;
V_108 . V_77 = V_78 ;
V_108 . V_110 = F_59 ;
V_108 . V_75 = F_62 ;
V_74 = F_72 ( V_78 , L_10 ) ;
if ( F_53 ( V_74 ) )
return F_54 ( V_74 ) ;
V_74 -> V_111 = V_112 ;
V_21 = F_73 ( & V_113 ) ;
if ( V_21 ) {
F_74 ( V_74 ) ;
return V_21 ;
}
return 0 ;
}
static void T_7 F_75 ( void )
{
F_76 ( & V_113 ) ;
F_74 ( V_74 ) ;
}
