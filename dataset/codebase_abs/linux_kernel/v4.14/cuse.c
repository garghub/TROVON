static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static struct V_4 * F_3 ( T_1 V_5 )
{
return & V_6 [ ( F_4 ( V_5 ) + F_5 ( V_5 ) ) % V_7 ] ;
}
static T_2 F_6 ( struct V_8 * V_8 , struct V_9 * V_10 )
{
struct V_11 V_12 = F_7 ( V_8 ) ;
T_3 V_13 = 0 ;
return F_8 ( & V_12 , V_10 , & V_13 , V_14 ) ;
}
static T_2 F_9 ( struct V_8 * V_8 , struct V_9 * V_15 )
{
struct V_11 V_12 = F_7 ( V_8 ) ;
T_3 V_13 = 0 ;
return F_8 ( & V_12 , V_15 , & V_13 ,
V_16 | V_14 ) ;
}
static int F_10 ( struct V_17 * V_17 , struct V_18 * V_18 )
{
T_1 V_5 = V_17 -> V_19 -> V_20 ;
struct V_1 * V_21 = NULL , * V_13 ;
int V_22 ;
F_11 ( & V_23 ) ;
F_12 (pos, cuse_conntbl_head(devt), list)
if ( V_13 -> V_20 -> V_5 == V_5 ) {
F_13 ( & V_13 -> V_3 ) ;
V_21 = V_13 ;
break;
}
F_14 ( & V_23 ) ;
if ( ! V_21 )
return - V_24 ;
V_22 = F_15 ( & V_21 -> V_3 , 0 , V_18 , 0 ) ;
if ( V_22 )
F_16 ( & V_21 -> V_3 ) ;
return V_22 ;
}
static int F_17 ( struct V_17 * V_17 , struct V_18 * V_18 )
{
struct V_25 * V_26 = V_18 -> V_27 ;
struct V_2 * V_3 = V_26 -> V_3 ;
F_18 ( V_26 , V_18 -> V_28 ) ;
F_16 ( V_3 ) ;
return 0 ;
}
static long F_19 ( struct V_18 * V_18 , unsigned int V_29 ,
unsigned long V_30 )
{
struct V_25 * V_26 = V_18 -> V_27 ;
struct V_1 * V_21 = F_1 ( V_26 -> V_3 ) ;
unsigned int V_31 = 0 ;
if ( V_21 -> V_32 )
V_31 |= V_33 ;
return F_20 ( V_18 , V_29 , V_30 , V_31 ) ;
}
static long F_21 ( struct V_18 * V_18 , unsigned int V_29 ,
unsigned long V_30 )
{
struct V_25 * V_26 = V_18 -> V_27 ;
struct V_1 * V_21 = F_1 ( V_26 -> V_3 ) ;
unsigned int V_31 = V_34 ;
if ( V_21 -> V_32 )
V_31 |= V_33 ;
return F_20 ( V_18 , V_29 , V_30 , V_31 ) ;
}
static int F_22 ( char * * V_35 , char * V_36 , char * * V_37 , char * * V_38 )
{
char * V_39 = * V_35 ;
char * V_40 , * V_41 ;
while ( V_39 < V_36 && * V_39 == '\0' )
V_39 ++ ;
if ( V_39 == V_36 )
return 0 ;
if ( V_36 [ - 1 ] != '\0' ) {
F_23 ( V_42 L_1 ) ;
return - V_43 ;
}
V_40 = V_41 = V_39 ;
V_39 += strlen ( V_39 ) ;
if ( V_38 ) {
F_24 ( & V_41 , L_2 ) ;
if ( ! V_41 )
V_41 = V_40 + strlen ( V_40 ) ;
V_40 = F_25 ( V_40 ) ;
V_41 = F_25 ( V_41 ) ;
} else
V_40 = F_25 ( V_40 ) ;
if ( ! strlen ( V_40 ) ) {
F_23 ( V_42 L_3 ) ;
return - V_43 ;
}
* V_35 = V_39 ;
* V_37 = V_40 ;
if ( V_38 )
* V_38 = V_41 ;
return 1 ;
}
static int F_26 ( char * V_39 , T_4 V_44 , struct V_45 * V_46 )
{
char * V_36 = V_39 + V_44 ;
char * V_47 ( V_40 ) , * V_47 ( V_41 ) ;
int V_22 ;
while ( true ) {
V_22 = F_22 ( & V_39 , V_36 , & V_40 , & V_41 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( ! V_22 )
break;
if ( strcmp ( V_40 , L_4 ) == 0 )
V_46 -> V_48 = V_41 ;
else
F_23 ( V_49 L_5 ,
V_40 ) ;
}
if ( ! V_46 -> V_48 || ! strlen ( V_46 -> V_48 ) ) {
F_23 ( V_42 L_6 ) ;
return - V_43 ;
}
return 0 ;
}
static void F_27 ( struct V_50 * V_20 )
{
F_28 ( V_20 ) ;
}
static void F_29 ( struct V_2 * V_3 , struct V_51 * V_52 )
{
struct V_1 * V_21 = F_1 ( V_3 ) , * V_13 ;
struct V_53 * V_30 = V_52 -> V_54 . args [ 0 ] . V_55 ;
struct V_56 * V_56 = V_52 -> V_57 [ 0 ] ;
struct V_45 V_46 = { } ;
struct V_50 * V_20 ;
struct V_58 * V_58 ;
T_1 V_5 ;
int V_22 , V_59 ;
if ( V_52 -> V_54 . V_60 . error ||
V_30 -> V_61 != V_62 || V_30 -> V_63 < 11 ) {
goto V_64;
}
V_3 -> V_63 = V_30 -> V_63 ;
V_3 -> V_65 = F_30 ( unsigned , V_30 -> V_65 , 4096 ) ;
V_3 -> V_66 = F_30 ( unsigned , V_30 -> V_66 , 4096 ) ;
V_21 -> V_32 = V_30 -> V_31 & V_67 ;
V_22 = F_26 ( F_31 ( V_56 ) , V_52 -> V_54 . args [ 1 ] . V_68 ,
& V_46 ) ;
if ( V_22 )
goto V_64;
V_5 = F_32 ( V_30 -> V_69 , V_30 -> V_70 ) ;
if ( ! F_4 ( V_5 ) )
V_22 = F_33 ( & V_5 , F_5 ( V_5 ) , 1 , V_46 . V_48 ) ;
else
V_22 = F_34 ( V_5 , 1 , V_46 . V_48 ) ;
if ( V_22 ) {
F_23 ( V_42 L_7 ) ;
goto V_64;
}
V_22 = - V_71 ;
V_20 = F_35 ( sizeof( * V_20 ) , V_72 ) ;
if ( ! V_20 )
goto V_73;
F_36 ( V_20 ) ;
F_37 ( V_20 , 1 ) ;
V_20 -> V_74 = V_75 ;
V_20 -> V_5 = V_5 ;
V_20 -> V_76 = F_27 ;
F_38 ( V_20 , V_21 ) ;
F_39 ( V_20 , L_8 , V_46 . V_48 ) ;
F_11 ( & V_23 ) ;
for ( V_59 = 0 ; V_59 < V_7 ; ++ V_59 ) {
F_12 (pos, &cuse_conntbl[i], list)
if ( ! strcmp ( F_40 ( V_13 -> V_20 ) , F_40 ( V_20 ) ) )
goto V_77;
}
V_22 = F_41 ( V_20 ) ;
if ( V_22 )
goto V_77;
V_22 = - V_71 ;
V_58 = F_42 () ;
if ( ! V_58 )
goto V_77;
V_58 -> V_78 = V_79 ;
V_58 -> V_80 = & V_81 ;
V_22 = F_43 ( V_58 , V_5 , 1 ) ;
if ( V_22 )
goto V_82;
V_21 -> V_20 = V_20 ;
V_21 -> V_58 = V_58 ;
F_44 ( & V_21 -> V_83 , F_3 ( V_5 ) ) ;
F_14 ( & V_23 ) ;
F_37 ( V_20 , 0 ) ;
F_45 ( & V_20 -> V_84 , V_85 ) ;
V_54:
F_28 ( V_30 ) ;
F_46 ( V_56 ) ;
return;
V_82:
F_47 ( V_58 ) ;
V_77:
F_14 ( & V_23 ) ;
F_48 ( V_20 ) ;
V_73:
F_49 ( V_5 , 1 ) ;
V_64:
F_50 ( V_3 ) ;
goto V_54;
}
static int F_51 ( struct V_1 * V_21 )
{
int V_22 ;
struct V_51 * V_52 ;
struct V_56 * V_56 ;
struct V_2 * V_3 = & V_21 -> V_3 ;
struct V_86 * V_30 ;
void * V_87 ;
F_52 ( V_88 > V_89 ) ;
V_52 = F_53 ( V_3 , 1 ) ;
if ( F_54 ( V_52 ) ) {
V_22 = F_55 ( V_52 ) ;
goto V_64;
}
V_22 = - V_71 ;
V_56 = F_56 ( V_72 | V_90 ) ;
if ( ! V_56 )
goto V_91;
V_87 = F_35 ( sizeof( struct V_53 ) , V_72 ) ;
if ( ! V_87 )
goto V_92;
V_30 = & V_52 -> V_93 . V_86 ;
V_30 -> V_61 = V_62 ;
V_30 -> V_63 = V_94 ;
V_30 -> V_31 |= V_67 ;
V_52 -> V_95 . V_60 . V_96 = V_97 ;
V_52 -> V_95 . V_98 = 1 ;
V_52 -> V_95 . args [ 0 ] . V_68 = sizeof( struct V_86 ) ;
V_52 -> V_95 . args [ 0 ] . V_55 = V_30 ;
V_52 -> V_54 . V_98 = 2 ;
V_52 -> V_54 . args [ 0 ] . V_68 = sizeof( struct V_53 ) ;
V_52 -> V_54 . args [ 0 ] . V_55 = V_87 ;
V_52 -> V_54 . args [ 1 ] . V_68 = V_88 ;
V_52 -> V_54 . V_99 = 1 ;
V_52 -> V_54 . V_100 = 1 ;
V_52 -> V_57 [ 0 ] = V_56 ;
V_52 -> V_101 [ 0 ] . V_102 = V_52 -> V_54 . args [ 1 ] . V_68 ;
V_52 -> V_103 = 1 ;
V_52 -> V_36 = F_29 ;
F_57 ( V_3 , V_52 ) ;
return 0 ;
V_92:
F_46 ( V_56 ) ;
V_91:
F_58 ( V_3 , V_52 ) ;
V_64:
return V_22 ;
}
static void F_59 ( struct V_2 * V_3 )
{
struct V_1 * V_21 = F_1 ( V_3 ) ;
F_60 ( V_21 , V_3 . V_104 ) ;
}
static int F_61 ( struct V_17 * V_17 , struct V_18 * V_18 )
{
struct V_105 * V_106 ;
struct V_1 * V_21 ;
int V_22 ;
V_21 = F_35 ( sizeof( * V_21 ) , V_72 ) ;
if ( ! V_21 )
return - V_71 ;
F_62 ( & V_21 -> V_3 ) ;
V_106 = F_63 ( & V_21 -> V_3 ) ;
if ( ! V_106 ) {
F_28 ( V_21 ) ;
return - V_71 ;
}
F_64 ( & V_21 -> V_83 ) ;
V_21 -> V_3 . V_76 = F_59 ;
V_21 -> V_3 . V_107 = 1 ;
V_22 = F_51 ( V_21 ) ;
if ( V_22 ) {
F_65 ( V_106 ) ;
return V_22 ;
}
V_18 -> V_27 = V_106 ;
return 0 ;
}
static int F_66 ( struct V_17 * V_17 , struct V_18 * V_18 )
{
struct V_105 * V_106 = V_18 -> V_27 ;
struct V_1 * V_21 = F_1 ( V_106 -> V_3 ) ;
int V_22 ;
F_11 ( & V_23 ) ;
F_67 ( & V_21 -> V_83 ) ;
F_14 ( & V_23 ) ;
if ( V_21 -> V_20 )
F_68 ( V_21 -> V_20 ) ;
if ( V_21 -> V_58 ) {
F_49 ( V_21 -> V_58 -> V_20 , 1 ) ;
F_47 ( V_21 -> V_58 ) ;
}
F_16 ( & V_21 -> V_3 ) ;
V_22 = F_69 ( V_17 , V_18 ) ;
return V_22 ;
}
static T_2 F_70 ( struct V_50 * V_20 ,
struct V_108 * V_109 , char * V_110 )
{
struct V_1 * V_21 = F_71 ( V_20 ) ;
return sprintf ( V_110 , L_9 , F_72 ( & V_21 -> V_3 . V_111 ) ) ;
}
static T_2 F_73 ( struct V_50 * V_20 ,
struct V_108 * V_109 ,
const char * V_110 , T_4 V_112 )
{
struct V_1 * V_21 = F_71 ( V_20 ) ;
F_50 ( & V_21 -> V_3 ) ;
return V_112 ;
}
static int T_5 F_74 ( void )
{
int V_59 , V_22 ;
for ( V_59 = 0 ; V_59 < V_7 ; V_59 ++ )
F_64 ( & V_6 [ V_59 ] ) ;
V_113 = V_114 ;
V_113 . V_78 = V_79 ;
V_113 . V_115 = F_61 ;
V_113 . V_76 = F_66 ;
V_75 = F_75 ( V_79 , L_10 ) ;
if ( F_54 ( V_75 ) )
return F_55 ( V_75 ) ;
V_75 -> V_116 = V_117 ;
V_22 = F_76 ( & V_118 ) ;
if ( V_22 ) {
F_77 ( V_75 ) ;
return V_22 ;
}
return 0 ;
}
static void T_6 F_78 ( void )
{
F_79 ( & V_118 ) ;
F_77 ( V_75 ) ;
}
