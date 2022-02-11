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
struct V_11 V_12 = F_7 ( V_8 -> V_13 ) ;
T_3 V_14 = 0 ;
return F_8 ( & V_12 , V_10 , & V_14 , V_15 ) ;
}
static T_2 F_9 ( struct V_8 * V_8 , struct V_9 * V_16 )
{
struct V_11 V_12 = F_7 ( V_8 -> V_13 ) ;
T_3 V_14 = 0 ;
return F_8 ( & V_12 , V_16 , & V_14 ,
V_17 | V_15 ) ;
}
static int F_10 ( struct V_18 * V_18 , struct V_19 * V_19 )
{
T_1 V_5 = V_18 -> V_20 -> V_21 ;
struct V_1 * V_22 = NULL , * V_14 ;
int V_23 ;
F_11 ( & V_24 ) ;
F_12 (pos, cuse_conntbl_head(devt), list)
if ( V_14 -> V_21 -> V_5 == V_5 ) {
F_13 ( & V_14 -> V_3 ) ;
V_22 = V_14 ;
break;
}
F_14 ( & V_24 ) ;
if ( ! V_22 )
return - V_25 ;
V_23 = F_15 ( & V_22 -> V_3 , 0 , V_19 , 0 ) ;
if ( V_23 )
F_16 ( & V_22 -> V_3 ) ;
return V_23 ;
}
static int F_17 ( struct V_18 * V_18 , struct V_19 * V_19 )
{
struct V_26 * V_27 = V_19 -> V_28 ;
struct V_2 * V_3 = V_27 -> V_3 ;
F_18 ( V_27 , V_19 -> V_29 ) ;
F_16 ( V_3 ) ;
return 0 ;
}
static long F_19 ( struct V_19 * V_19 , unsigned int V_30 ,
unsigned long V_31 )
{
struct V_26 * V_27 = V_19 -> V_28 ;
struct V_1 * V_22 = F_1 ( V_27 -> V_3 ) ;
unsigned int V_32 = 0 ;
if ( V_22 -> V_33 )
V_32 |= V_34 ;
return F_20 ( V_19 , V_30 , V_31 , V_32 ) ;
}
static long F_21 ( struct V_19 * V_19 , unsigned int V_30 ,
unsigned long V_31 )
{
struct V_26 * V_27 = V_19 -> V_28 ;
struct V_1 * V_22 = F_1 ( V_27 -> V_3 ) ;
unsigned int V_32 = V_35 ;
if ( V_22 -> V_33 )
V_32 |= V_34 ;
return F_20 ( V_19 , V_30 , V_31 , V_32 ) ;
}
static int F_22 ( char * * V_36 , char * V_37 , char * * V_38 , char * * V_39 )
{
char * V_40 = * V_36 ;
char * V_41 , * V_42 ;
while ( V_40 < V_37 && * V_40 == '\0' )
V_40 ++ ;
if ( V_40 == V_37 )
return 0 ;
if ( V_37 [ - 1 ] != '\0' ) {
F_23 ( V_43 L_1 ) ;
return - V_44 ;
}
V_41 = V_42 = V_40 ;
V_40 += strlen ( V_40 ) ;
if ( V_39 ) {
F_24 ( & V_42 , L_2 ) ;
if ( ! V_42 )
V_42 = V_41 + strlen ( V_41 ) ;
V_41 = F_25 ( V_41 ) ;
V_42 = F_25 ( V_42 ) ;
} else
V_41 = F_25 ( V_41 ) ;
if ( ! strlen ( V_41 ) ) {
F_23 ( V_43 L_3 ) ;
return - V_44 ;
}
* V_36 = V_40 ;
* V_38 = V_41 ;
if ( V_39 )
* V_39 = V_42 ;
return 1 ;
}
static int F_26 ( char * V_40 , T_4 V_45 , struct V_46 * V_47 )
{
char * V_37 = V_40 + V_45 ;
char * V_48 ( V_41 ) , * V_48 ( V_42 ) ;
int V_23 ;
while ( true ) {
V_23 = F_22 ( & V_40 , V_37 , & V_41 , & V_42 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( ! V_23 )
break;
if ( strcmp ( V_41 , L_4 ) == 0 )
V_47 -> V_49 = V_42 ;
else
F_23 ( V_50 L_5 ,
V_41 ) ;
}
if ( ! V_47 -> V_49 || ! strlen ( V_47 -> V_49 ) ) {
F_23 ( V_43 L_6 ) ;
return - V_44 ;
}
return 0 ;
}
static void F_27 ( struct V_51 * V_21 )
{
F_28 ( V_21 ) ;
}
static void F_29 ( struct V_2 * V_3 , struct V_52 * V_53 )
{
struct V_1 * V_22 = F_1 ( V_3 ) , * V_14 ;
struct V_54 * V_31 = V_53 -> V_55 . args [ 0 ] . V_56 ;
struct V_57 * V_57 = V_53 -> V_58 [ 0 ] ;
struct V_46 V_47 = { } ;
struct V_51 * V_21 ;
struct V_59 * V_59 ;
T_1 V_5 ;
int V_23 , V_60 ;
if ( V_53 -> V_55 . V_61 . error ||
V_31 -> V_62 != V_63 || V_31 -> V_64 < 11 ) {
goto V_65;
}
V_3 -> V_64 = V_31 -> V_64 ;
V_3 -> V_66 = F_30 ( unsigned , V_31 -> V_66 , 4096 ) ;
V_3 -> V_67 = F_30 ( unsigned , V_31 -> V_67 , 4096 ) ;
V_22 -> V_33 = V_31 -> V_32 & V_68 ;
V_23 = F_26 ( F_31 ( V_57 ) , V_53 -> V_55 . args [ 1 ] . V_69 ,
& V_47 ) ;
if ( V_23 )
goto V_65;
V_5 = F_32 ( V_31 -> V_70 , V_31 -> V_71 ) ;
if ( ! F_4 ( V_5 ) )
V_23 = F_33 ( & V_5 , F_5 ( V_5 ) , 1 , V_47 . V_49 ) ;
else
V_23 = F_34 ( V_5 , 1 , V_47 . V_49 ) ;
if ( V_23 ) {
F_23 ( V_43 L_7 ) ;
goto V_65;
}
V_23 = - V_72 ;
V_21 = F_35 ( sizeof( * V_21 ) , V_73 ) ;
if ( ! V_21 )
goto V_74;
F_36 ( V_21 ) ;
F_37 ( V_21 , 1 ) ;
V_21 -> V_75 = V_76 ;
V_21 -> V_5 = V_5 ;
V_21 -> V_77 = F_27 ;
F_38 ( V_21 , V_22 ) ;
F_39 ( V_21 , L_8 , V_47 . V_49 ) ;
F_11 ( & V_24 ) ;
for ( V_60 = 0 ; V_60 < V_7 ; ++ V_60 ) {
F_12 (pos, &cuse_conntbl[i], list)
if ( ! strcmp ( F_40 ( V_14 -> V_21 ) , F_40 ( V_21 ) ) )
goto V_78;
}
V_23 = F_41 ( V_21 ) ;
if ( V_23 )
goto V_78;
V_23 = - V_72 ;
V_59 = F_42 () ;
if ( ! V_59 )
goto V_78;
V_59 -> V_79 = V_80 ;
V_59 -> V_81 = & V_82 ;
V_23 = F_43 ( V_59 , V_5 , 1 ) ;
if ( V_23 )
goto V_83;
V_22 -> V_21 = V_21 ;
V_22 -> V_59 = V_59 ;
F_44 ( & V_22 -> V_84 , F_3 ( V_5 ) ) ;
F_14 ( & V_24 ) ;
F_37 ( V_21 , 0 ) ;
F_45 ( & V_21 -> V_85 , V_86 ) ;
V_55:
F_28 ( V_31 ) ;
F_46 ( V_57 ) ;
return;
V_83:
F_47 ( V_59 ) ;
V_78:
F_14 ( & V_24 ) ;
F_48 ( V_21 ) ;
V_74:
F_49 ( V_5 , 1 ) ;
V_65:
F_50 ( V_3 ) ;
goto V_55;
}
static int F_51 ( struct V_1 * V_22 )
{
int V_23 ;
struct V_52 * V_53 ;
struct V_57 * V_57 ;
struct V_2 * V_3 = & V_22 -> V_3 ;
struct V_87 * V_31 ;
void * V_88 ;
F_52 ( V_89 > V_90 ) ;
V_53 = F_53 ( V_3 , 1 ) ;
if ( F_54 ( V_53 ) ) {
V_23 = F_55 ( V_53 ) ;
goto V_65;
}
V_23 = - V_72 ;
V_57 = F_56 ( V_73 | V_91 ) ;
if ( ! V_57 )
goto V_92;
V_88 = F_35 ( sizeof( struct V_54 ) , V_73 ) ;
if ( ! V_88 )
goto V_93;
V_31 = & V_53 -> V_94 . V_87 ;
V_31 -> V_62 = V_63 ;
V_31 -> V_64 = V_95 ;
V_31 -> V_32 |= V_68 ;
V_53 -> V_96 . V_61 . V_97 = V_98 ;
V_53 -> V_96 . V_99 = 1 ;
V_53 -> V_96 . args [ 0 ] . V_69 = sizeof( struct V_87 ) ;
V_53 -> V_96 . args [ 0 ] . V_56 = V_31 ;
V_53 -> V_55 . V_99 = 2 ;
V_53 -> V_55 . args [ 0 ] . V_69 = sizeof( struct V_54 ) ;
V_53 -> V_55 . args [ 0 ] . V_56 = V_88 ;
V_53 -> V_55 . args [ 1 ] . V_69 = V_89 ;
V_53 -> V_55 . V_100 = 1 ;
V_53 -> V_55 . V_101 = 1 ;
V_53 -> V_58 [ 0 ] = V_57 ;
V_53 -> V_102 [ 0 ] . V_103 = V_53 -> V_55 . args [ 1 ] . V_69 ;
V_53 -> V_104 = 1 ;
V_53 -> V_37 = F_29 ;
F_57 ( V_3 , V_53 ) ;
return 0 ;
V_93:
F_46 ( V_57 ) ;
V_92:
F_58 ( V_3 , V_53 ) ;
V_65:
return V_23 ;
}
static void F_59 ( struct V_2 * V_3 )
{
struct V_1 * V_22 = F_1 ( V_3 ) ;
F_60 ( V_22 , V_3 . V_105 ) ;
}
static int F_61 ( struct V_18 * V_18 , struct V_19 * V_19 )
{
struct V_106 * V_107 ;
struct V_1 * V_22 ;
int V_23 ;
V_22 = F_35 ( sizeof( * V_22 ) , V_73 ) ;
if ( ! V_22 )
return - V_72 ;
F_62 ( & V_22 -> V_3 ) ;
V_107 = F_63 ( & V_22 -> V_3 ) ;
if ( ! V_107 ) {
F_28 ( V_22 ) ;
return - V_72 ;
}
F_64 ( & V_22 -> V_84 ) ;
V_22 -> V_3 . V_77 = F_59 ;
V_22 -> V_3 . V_108 = 1 ;
V_23 = F_51 ( V_22 ) ;
if ( V_23 ) {
F_65 ( V_107 ) ;
return V_23 ;
}
V_19 -> V_28 = V_107 ;
return 0 ;
}
static int F_66 ( struct V_18 * V_18 , struct V_19 * V_19 )
{
struct V_106 * V_107 = V_19 -> V_28 ;
struct V_1 * V_22 = F_1 ( V_107 -> V_3 ) ;
int V_23 ;
F_11 ( & V_24 ) ;
F_67 ( & V_22 -> V_84 ) ;
F_14 ( & V_24 ) ;
if ( V_22 -> V_21 )
F_68 ( V_22 -> V_21 ) ;
if ( V_22 -> V_59 ) {
F_49 ( V_22 -> V_59 -> V_21 , 1 ) ;
F_47 ( V_22 -> V_59 ) ;
}
F_16 ( & V_22 -> V_3 ) ;
V_23 = F_69 ( V_18 , V_19 ) ;
return V_23 ;
}
static T_2 F_70 ( struct V_51 * V_21 ,
struct V_109 * V_110 , char * V_111 )
{
struct V_1 * V_22 = F_71 ( V_21 ) ;
return sprintf ( V_111 , L_9 , F_72 ( & V_22 -> V_3 . V_112 ) ) ;
}
static T_2 F_73 ( struct V_51 * V_21 ,
struct V_109 * V_110 ,
const char * V_111 , T_4 V_113 )
{
struct V_1 * V_22 = F_71 ( V_21 ) ;
F_50 ( & V_22 -> V_3 ) ;
return V_113 ;
}
static int T_5 F_74 ( void )
{
int V_60 , V_23 ;
for ( V_60 = 0 ; V_60 < V_7 ; V_60 ++ )
F_64 ( & V_6 [ V_60 ] ) ;
V_114 = V_115 ;
V_114 . V_79 = V_80 ;
V_114 . V_116 = F_61 ;
V_114 . V_77 = F_66 ;
V_76 = F_75 ( V_80 , L_10 ) ;
if ( F_54 ( V_76 ) )
return F_55 ( V_76 ) ;
V_76 -> V_117 = V_118 ;
V_23 = F_76 ( & V_119 ) ;
if ( V_23 ) {
F_77 ( V_76 ) ;
return V_23 ;
}
return 0 ;
}
static void T_6 F_78 ( void )
{
F_79 ( & V_119 ) ;
F_77 ( V_76 ) ;
}
