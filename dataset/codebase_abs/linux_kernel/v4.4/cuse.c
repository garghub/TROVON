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
struct V_11 V_12 = { . V_13 = 0 , . V_14 = V_8 -> V_15 } ;
T_3 V_16 = 0 ;
return F_7 ( & V_12 , V_10 , & V_16 , V_17 ) ;
}
static T_2 F_8 ( struct V_8 * V_8 , struct V_9 * V_18 )
{
struct V_11 V_12 = { . V_13 = 0 , . V_14 = V_8 -> V_15 } ;
T_3 V_16 = 0 ;
return F_7 ( & V_12 , V_18 , & V_16 ,
V_19 | V_17 ) ;
}
static int F_9 ( struct V_20 * V_20 , struct V_14 * V_14 )
{
T_1 V_5 = V_20 -> V_21 -> V_22 ;
struct V_1 * V_23 = NULL , * V_16 ;
int V_24 ;
F_10 ( & V_25 ) ;
F_11 (pos, cuse_conntbl_head(devt), list)
if ( V_16 -> V_22 -> V_5 == V_5 ) {
F_12 ( & V_16 -> V_3 ) ;
V_23 = V_16 ;
break;
}
F_13 ( & V_25 ) ;
if ( ! V_23 )
return - V_26 ;
V_24 = F_14 ( & V_23 -> V_3 , 0 , V_14 , 0 ) ;
if ( V_24 )
F_15 ( & V_23 -> V_3 ) ;
return V_24 ;
}
static int F_16 ( struct V_20 * V_20 , struct V_14 * V_14 )
{
struct V_27 * V_28 = V_14 -> V_29 ;
struct V_2 * V_3 = V_28 -> V_3 ;
F_17 ( V_28 , V_14 -> V_30 ) ;
F_15 ( V_3 ) ;
return 0 ;
}
static long F_18 ( struct V_14 * V_14 , unsigned int V_31 ,
unsigned long V_32 )
{
struct V_27 * V_28 = V_14 -> V_29 ;
struct V_1 * V_23 = F_1 ( V_28 -> V_3 ) ;
unsigned int V_33 = 0 ;
if ( V_23 -> V_34 )
V_33 |= V_35 ;
return F_19 ( V_14 , V_31 , V_32 , V_33 ) ;
}
static long F_20 ( struct V_14 * V_14 , unsigned int V_31 ,
unsigned long V_32 )
{
struct V_27 * V_28 = V_14 -> V_29 ;
struct V_1 * V_23 = F_1 ( V_28 -> V_3 ) ;
unsigned int V_33 = V_36 ;
if ( V_23 -> V_34 )
V_33 |= V_35 ;
return F_19 ( V_14 , V_31 , V_32 , V_33 ) ;
}
static int F_21 ( char * * V_37 , char * V_38 , char * * V_39 , char * * V_40 )
{
char * V_41 = * V_37 ;
char * V_42 , * V_43 ;
while ( V_41 < V_38 && * V_41 == '\0' )
V_41 ++ ;
if ( V_41 == V_38 )
return 0 ;
if ( V_38 [ - 1 ] != '\0' ) {
F_22 ( V_44 L_1 ) ;
return - V_45 ;
}
V_42 = V_43 = V_41 ;
V_41 += strlen ( V_41 ) ;
if ( V_40 ) {
F_23 ( & V_43 , L_2 ) ;
if ( ! V_43 )
V_43 = V_42 + strlen ( V_42 ) ;
V_42 = F_24 ( V_42 ) ;
V_43 = F_24 ( V_43 ) ;
} else
V_42 = F_24 ( V_42 ) ;
if ( ! strlen ( V_42 ) ) {
F_22 ( V_44 L_3 ) ;
return - V_45 ;
}
* V_37 = V_41 ;
* V_39 = V_42 ;
if ( V_40 )
* V_40 = V_43 ;
return 1 ;
}
static int F_25 ( char * V_41 , T_4 V_46 , struct V_47 * V_48 )
{
char * V_38 = V_41 + V_46 ;
char * V_49 ( V_42 ) , * V_49 ( V_43 ) ;
int V_24 ;
while ( true ) {
V_24 = F_21 ( & V_41 , V_38 , & V_42 , & V_43 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( ! V_24 )
break;
if ( strcmp ( V_42 , L_4 ) == 0 )
V_48 -> V_50 = V_43 ;
else
F_22 ( V_51 L_5 ,
V_42 ) ;
}
if ( ! V_48 -> V_50 || ! strlen ( V_48 -> V_50 ) ) {
F_22 ( V_44 L_6 ) ;
return - V_45 ;
}
return 0 ;
}
static void F_26 ( struct V_52 * V_22 )
{
F_27 ( V_22 ) ;
}
static void F_28 ( struct V_2 * V_3 , struct V_53 * V_54 )
{
struct V_1 * V_23 = F_1 ( V_3 ) , * V_16 ;
struct V_55 * V_32 = V_54 -> V_56 . args [ 0 ] . V_57 ;
struct V_58 * V_58 = V_54 -> V_59 [ 0 ] ;
struct V_47 V_48 = { } ;
struct V_52 * V_22 ;
struct V_60 * V_60 ;
T_1 V_5 ;
int V_24 , V_61 ;
if ( V_54 -> V_56 . V_62 . error ||
V_32 -> V_63 != V_64 || V_32 -> V_65 < 11 ) {
goto V_66;
}
V_3 -> V_65 = V_32 -> V_65 ;
V_3 -> V_67 = F_29 ( unsigned , V_32 -> V_67 , 4096 ) ;
V_3 -> V_68 = F_29 ( unsigned , V_32 -> V_68 , 4096 ) ;
V_23 -> V_34 = V_32 -> V_33 & V_69 ;
V_24 = F_25 ( F_30 ( V_58 ) , V_54 -> V_56 . args [ 1 ] . V_70 ,
& V_48 ) ;
if ( V_24 )
goto V_66;
V_5 = F_31 ( V_32 -> V_71 , V_32 -> V_72 ) ;
if ( ! F_4 ( V_5 ) )
V_24 = F_32 ( & V_5 , F_5 ( V_5 ) , 1 , V_48 . V_50 ) ;
else
V_24 = F_33 ( V_5 , 1 , V_48 . V_50 ) ;
if ( V_24 ) {
F_22 ( V_44 L_7 ) ;
goto V_66;
}
V_24 = - V_73 ;
V_22 = F_34 ( sizeof( * V_22 ) , V_74 ) ;
if ( ! V_22 )
goto V_75;
F_35 ( V_22 ) ;
F_36 ( V_22 , 1 ) ;
V_22 -> V_76 = V_77 ;
V_22 -> V_5 = V_5 ;
V_22 -> V_78 = F_26 ;
F_37 ( V_22 , V_23 ) ;
F_38 ( V_22 , L_8 , V_48 . V_50 ) ;
F_10 ( & V_25 ) ;
for ( V_61 = 0 ; V_61 < V_7 ; ++ V_61 ) {
F_11 (pos, &cuse_conntbl[i], list)
if ( ! strcmp ( F_39 ( V_16 -> V_22 ) , F_39 ( V_22 ) ) )
goto V_79;
}
V_24 = F_40 ( V_22 ) ;
if ( V_24 )
goto V_79;
V_24 = - V_73 ;
V_60 = F_41 () ;
if ( ! V_60 )
goto V_79;
V_60 -> V_80 = V_81 ;
V_60 -> V_82 = & V_83 ;
V_24 = F_42 ( V_60 , V_5 , 1 ) ;
if ( V_24 )
goto V_84;
V_23 -> V_22 = V_22 ;
V_23 -> V_60 = V_60 ;
F_43 ( & V_23 -> V_85 , F_3 ( V_5 ) ) ;
F_13 ( & V_25 ) ;
F_36 ( V_22 , 0 ) ;
F_44 ( & V_22 -> V_86 , V_87 ) ;
V_56:
F_27 ( V_32 ) ;
F_45 ( V_58 ) ;
return;
V_84:
F_46 ( V_60 ) ;
V_79:
F_13 ( & V_25 ) ;
F_47 ( V_22 ) ;
V_75:
F_48 ( V_5 , 1 ) ;
V_66:
F_49 ( V_3 ) ;
goto V_56;
}
static int F_50 ( struct V_1 * V_23 )
{
int V_24 ;
struct V_53 * V_54 ;
struct V_58 * V_58 ;
struct V_2 * V_3 = & V_23 -> V_3 ;
struct V_88 * V_32 ;
void * V_89 ;
F_51 ( V_90 > V_91 ) ;
V_54 = F_52 ( V_3 , 1 ) ;
if ( F_53 ( V_54 ) ) {
V_24 = F_54 ( V_54 ) ;
goto V_66;
}
V_24 = - V_73 ;
V_58 = F_55 ( V_74 | V_92 ) ;
if ( ! V_58 )
goto V_93;
V_89 = F_34 ( sizeof( struct V_55 ) , V_74 ) ;
if ( ! V_89 )
goto V_94;
V_32 = & V_54 -> V_95 . V_88 ;
V_32 -> V_63 = V_64 ;
V_32 -> V_65 = V_96 ;
V_32 -> V_33 |= V_69 ;
V_54 -> V_97 . V_62 . V_98 = V_99 ;
V_54 -> V_97 . V_100 = 1 ;
V_54 -> V_97 . args [ 0 ] . V_70 = sizeof( struct V_88 ) ;
V_54 -> V_97 . args [ 0 ] . V_57 = V_32 ;
V_54 -> V_56 . V_100 = 2 ;
V_54 -> V_56 . args [ 0 ] . V_70 = sizeof( struct V_55 ) ;
V_54 -> V_56 . args [ 0 ] . V_57 = V_89 ;
V_54 -> V_56 . args [ 1 ] . V_70 = V_90 ;
V_54 -> V_56 . V_101 = 1 ;
V_54 -> V_56 . V_102 = 1 ;
V_54 -> V_59 [ 0 ] = V_58 ;
V_54 -> V_103 [ 0 ] . V_104 = V_54 -> V_56 . args [ 1 ] . V_70 ;
V_54 -> V_105 = 1 ;
V_54 -> V_38 = F_28 ;
F_56 ( V_3 , V_54 ) ;
return 0 ;
V_94:
F_45 ( V_58 ) ;
V_93:
F_57 ( V_3 , V_54 ) ;
V_66:
return V_24 ;
}
static void F_58 ( struct V_2 * V_3 )
{
struct V_1 * V_23 = F_1 ( V_3 ) ;
F_59 ( V_23 , V_3 . V_106 ) ;
}
static int F_60 ( struct V_20 * V_20 , struct V_14 * V_14 )
{
struct V_107 * V_108 ;
struct V_1 * V_23 ;
int V_24 ;
V_23 = F_34 ( sizeof( * V_23 ) , V_74 ) ;
if ( ! V_23 )
return - V_73 ;
F_61 ( & V_23 -> V_3 ) ;
V_108 = F_62 ( & V_23 -> V_3 ) ;
if ( ! V_108 ) {
F_27 ( V_23 ) ;
return - V_73 ;
}
F_63 ( & V_23 -> V_85 ) ;
V_23 -> V_3 . V_78 = F_58 ;
V_23 -> V_3 . V_109 = 1 ;
V_24 = F_50 ( V_23 ) ;
if ( V_24 ) {
F_64 ( V_108 ) ;
return V_24 ;
}
V_14 -> V_29 = V_108 ;
return 0 ;
}
static int F_65 ( struct V_20 * V_20 , struct V_14 * V_14 )
{
struct V_107 * V_108 = V_14 -> V_29 ;
struct V_1 * V_23 = F_1 ( V_108 -> V_3 ) ;
int V_24 ;
F_10 ( & V_25 ) ;
F_66 ( & V_23 -> V_85 ) ;
F_13 ( & V_25 ) ;
if ( V_23 -> V_22 )
F_67 ( V_23 -> V_22 ) ;
if ( V_23 -> V_60 ) {
F_48 ( V_23 -> V_60 -> V_22 , 1 ) ;
F_46 ( V_23 -> V_60 ) ;
}
F_15 ( & V_23 -> V_3 ) ;
V_24 = F_68 ( V_20 , V_14 ) ;
return V_24 ;
}
static T_2 F_69 ( struct V_52 * V_22 ,
struct V_110 * V_111 , char * V_112 )
{
struct V_1 * V_23 = F_70 ( V_22 ) ;
return sprintf ( V_112 , L_9 , F_71 ( & V_23 -> V_3 . V_113 ) ) ;
}
static T_2 F_72 ( struct V_52 * V_22 ,
struct V_110 * V_111 ,
const char * V_112 , T_4 V_114 )
{
struct V_1 * V_23 = F_70 ( V_22 ) ;
F_49 ( & V_23 -> V_3 ) ;
return V_114 ;
}
static int T_5 F_73 ( void )
{
int V_61 , V_24 ;
for ( V_61 = 0 ; V_61 < V_7 ; V_61 ++ )
F_63 ( & V_6 [ V_61 ] ) ;
V_115 = V_116 ;
V_115 . V_80 = V_81 ;
V_115 . V_117 = F_60 ;
V_115 . V_78 = F_65 ;
V_77 = F_74 ( V_81 , L_10 ) ;
if ( F_53 ( V_77 ) )
return F_54 ( V_77 ) ;
V_77 -> V_118 = V_119 ;
V_24 = F_75 ( & V_120 ) ;
if ( V_24 ) {
F_76 ( V_77 ) ;
return V_24 ;
}
return 0 ;
}
static void T_6 F_77 ( void )
{
F_78 ( & V_120 ) ;
F_76 ( V_77 ) ;
}
