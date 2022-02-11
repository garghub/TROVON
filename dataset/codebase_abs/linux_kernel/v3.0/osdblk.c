static void F_1 ( T_1 V_1 [ V_2 ] ,
const struct V_3 * V_4 )
{
F_2 ( V_1 , V_4 , false , true ) ;
}
static int F_3 ( struct V_5 * V_6 , int V_7 , T_2 * V_8 )
{
int V_9 ;
V_6 -> V_7 = V_7 ;
V_9 = F_4 ( V_6 , 0 , V_8 , NULL ) ;
if ( V_9 )
return V_9 ;
V_9 = F_5 ( V_6 ) ;
return V_9 ;
}
static int F_6 ( struct V_5 * V_6 , T_3 * V_10 ,
void * V_11 , T_1 * V_12 )
{
int V_9 ;
V_9 = F_4 ( V_6 , 0 , V_12 , NULL ) ;
if ( V_9 )
return V_9 ;
V_9 = F_7 ( V_6 , V_10 , V_11 ) ;
return V_9 ;
}
static int F_8 ( struct V_5 * V_6 , struct V_13 * V_14 )
{
struct V_13 V_15 = { . V_16 = 0 } ;
void * V_17 = NULL ;
int V_18 ;
do {
V_18 = 1 ;
F_9 ( V_6 , & V_15 , & V_18 , & V_17 ) ;
if ( ( V_15 . V_16 == V_14 -> V_16 ) &&
( V_15 . V_19 == V_14 -> V_19 ) ) {
V_14 -> V_20 = V_15 . V_20 ;
V_14 -> V_21 = V_15 . V_21 ;
return 0 ;
}
} while ( V_17 );
return - V_22 ;
}
static int F_10 ( struct V_23 * V_24 , T_4 * V_25 )
{
struct V_5 * V_6 ;
struct V_13 V_14 ;
int V_9 ;
V_6 = F_11 ( V_24 -> V_26 , V_27 ) ;
if ( ! V_6 )
return - V_28 ;
F_12 ( V_6 , & V_24 -> V_4 ) ;
F_13 ( V_6 , & V_29 , 1 ) ;
V_9 = F_3 ( V_6 , V_30 , V_24 -> V_31 ) ;
if ( V_9 )
goto V_32;
V_14 = V_29 ;
V_9 = F_8 ( V_6 , & V_14 ) ;
if ( V_9 )
goto V_32;
* V_25 = F_14 ( V_14 . V_21 ) ;
V_32:
F_15 ( V_6 ) ;
return V_9 ;
}
static void F_16 ( struct V_5 * V_6 , void * V_33 )
{
struct V_34 * V_35 = V_33 ;
struct V_36 V_37 ;
int V_9 = F_17 ( V_6 , & V_37 ) ;
if ( V_9 ) {
V_9 = - V_22 ;
F_18 ( L_1 , V_9 ) ;
}
F_15 ( V_6 ) ;
F_19 ( V_35 -> V_38 , V_9 ) ;
}
static void F_20 ( struct V_39 * V_40 )
{
struct V_39 * V_41 ;
while ( V_40 ) {
V_41 = V_40 ;
V_40 = V_40 -> V_42 ;
F_21 ( V_41 ) ;
}
}
static struct V_39 * F_22 ( struct V_39 * V_43 , T_5 V_44 )
{
struct V_39 * V_41 , * V_45 = NULL , * V_46 = NULL ;
while ( V_43 ) {
V_41 = F_23 ( V_44 , V_43 -> V_47 ) ;
if ( ! V_41 )
goto V_48;
F_24 ( V_41 , V_43 ) ;
V_41 -> V_49 = NULL ;
V_44 &= ~ V_50 ;
V_41 -> V_42 = NULL ;
if ( ! V_45 )
V_45 = V_46 = V_41 ;
else {
V_46 -> V_42 = V_41 ;
V_46 = V_41 ;
}
V_43 = V_43 -> V_42 ;
}
return V_45 ;
V_48:
F_18 ( L_2 ) ;
F_20 ( V_45 ) ;
return NULL ;
}
static void F_25 ( struct V_51 * V_52 )
{
struct V_23 * V_24 = V_52 -> V_53 ;
while ( 1 ) {
struct V_54 * V_38 ;
struct V_34 * V_35 ;
struct V_5 * V_6 ;
struct V_39 * V_39 ;
bool V_55 , V_56 ;
V_38 = F_26 ( V_52 ) ;
if ( ! V_38 )
break;
if ( V_38 -> V_57 != V_58 ) {
F_27 ( V_38 , 0 ) ;
continue;
}
V_56 = V_38 -> V_59 & V_60 ;
V_55 = ( F_28 ( V_38 ) == V_61 ) ;
if ( ! V_56 ) {
V_39 = F_22 ( V_38 -> V_39 , V_62 ) ;
if ( ! V_39 )
break;
} else
V_39 = NULL ;
V_6 = F_11 ( V_24 -> V_26 , V_62 ) ;
if ( ! V_6 ) {
F_20 ( V_39 ) ;
F_18 ( L_3 ) ;
break;
}
V_35 = & V_24 -> V_63 [ V_38 -> V_64 ] ;
V_35 -> V_38 = V_38 ;
V_35 -> V_39 = V_39 ;
V_35 -> V_24 = V_24 ;
if ( V_56 )
F_29 ( V_6 , & V_24 -> V_4 ,
V_65 , 0 , 0 ) ;
else if ( V_55 )
F_30 ( V_6 , & V_24 -> V_4 , F_31 ( V_38 ) * 512ULL ,
V_39 , F_32 ( V_38 ) ) ;
else
F_33 ( V_6 , & V_24 -> V_4 , F_31 ( V_38 ) * 512ULL ,
V_39 , F_32 ( V_38 ) ) ;
F_18 ( L_4 ,
V_56 ? L_5 : V_55 ?
L_6 : L_7 , F_32 ( V_38 ) ,
F_31 ( V_38 ) * 512ULL ) ;
if ( F_6 ( V_6 , F_16 , V_35 ,
V_24 -> V_31 ) ) {
F_15 ( V_6 ) ;
F_34 ( V_52 , V_38 ) ;
F_20 ( V_39 ) ;
F_18 ( L_8 ) ;
break;
}
V_38 -> V_66 = NULL ;
}
}
static void F_35 ( struct V_23 * V_24 )
{
struct V_67 * V_68 = V_24 -> V_68 ;
if ( ! V_68 )
return;
if ( V_68 -> V_69 & V_70 )
F_36 ( V_68 ) ;
if ( V_68 -> V_71 )
F_37 ( V_68 -> V_71 ) ;
F_38 ( V_68 ) ;
}
static int F_39 ( struct V_23 * V_24 )
{
struct V_67 * V_68 ;
struct V_51 * V_52 ;
int V_72 ;
T_4 V_73 = 0 ;
V_72 = F_10 ( V_24 , & V_73 ) ;
if ( V_72 )
return V_72 ;
V_68 = F_40 ( V_74 ) ;
if ( ! V_68 )
return - V_28 ;
sprintf ( V_68 -> V_75 , V_76 L_9 , V_24 -> V_77 ) ;
V_68 -> V_78 = V_24 -> V_78 ;
V_68 -> V_79 = 0 ;
V_68 -> V_80 = & V_81 ;
V_68 -> V_82 = V_24 ;
V_52 = F_41 ( F_25 , & V_24 -> V_83 ) ;
if ( ! V_52 ) {
F_38 ( V_68 ) ;
return - V_28 ;
}
V_72 = F_42 ( V_52 , V_84 , NULL ) ;
if ( V_72 ) {
F_37 ( V_52 ) ;
F_38 ( V_68 ) ;
return V_72 ;
}
F_43 ( V_52 , F_44 ( V_24 -> V_26 ) ) ;
F_45 ( V_52 , V_85 ) ;
F_46 ( V_52 , V_60 ) ;
V_68 -> V_71 = V_52 ;
V_52 -> V_53 = V_24 ;
V_24 -> V_68 = V_68 ;
V_24 -> V_52 = V_52 ;
F_47 ( V_68 , V_73 / 512ULL ) ;
F_48 ( V_68 ) ;
F_49 ( V_86 L_10 ,
V_68 -> V_75 , ( unsigned long long ) V_73 ) ;
return 0 ;
}
static void F_50 ( struct V_87 * V_88 )
{
F_51 ( V_88 ) ;
}
static T_6 F_52 ( struct V_87 * V_89 ,
struct V_90 * V_14 ,
char * V_91 )
{
int V_92 = 0 ;
struct V_93 * V_41 ;
F_53 ( & V_94 , V_95 ) ;
F_54 (tmp, &osdblkdev_list) {
struct V_23 * V_24 ;
V_24 = F_55 ( V_41 , struct V_23 , V_96 ) ;
V_92 += sprintf ( V_91 + V_92 , L_11 ,
V_24 -> V_77 ,
V_24 -> V_78 ,
V_24 -> V_4 . V_97 ,
V_24 -> V_4 . V_77 ,
V_24 -> V_98 ) ;
}
F_56 ( & V_94 ) ;
return V_92 ;
}
static T_6 F_57 ( struct V_87 * V_89 ,
struct V_90 * V_14 ,
const char * V_99 , T_7 V_100 )
{
struct V_23 * V_24 ;
T_6 V_72 ;
int V_101 , V_102 = 0 ;
struct V_93 * V_41 ;
if ( ! F_58 ( V_103 ) )
return - V_104 ;
V_24 = F_59 ( sizeof( * V_24 ) + strlen ( V_99 ) + 1 , V_27 ) ;
if ( ! V_24 ) {
V_72 = - V_28 ;
goto V_105;
}
F_60 ( & V_24 -> V_83 ) ;
F_61 ( & V_24 -> V_96 ) ;
F_53 ( & V_94 , V_95 ) ;
F_54 (tmp, &osdblkdev_list) {
struct V_23 * V_24 ;
V_24 = F_55 ( V_41 , struct V_23 , V_96 ) ;
if ( V_24 -> V_77 > V_102 )
V_102 = V_24 -> V_77 + 1 ;
}
V_24 -> V_77 = V_102 ;
F_62 ( & V_24 -> V_96 , & V_106 ) ;
F_56 ( & V_94 ) ;
if ( sscanf ( V_99 , L_12 , & V_24 -> V_4 . V_97 , & V_24 -> V_4 . V_77 ,
V_24 -> V_98 ) != 3 ) {
V_72 = - V_107 ;
goto V_108;
}
sprintf ( V_24 -> V_109 , V_76 L_9 , V_24 -> V_77 ) ;
V_24 -> V_26 = F_63 ( V_24 -> V_98 ) ;
if ( F_64 ( V_24 -> V_26 ) ) {
V_72 = F_65 ( V_24 -> V_26 ) ;
goto V_108;
}
F_1 ( V_24 -> V_31 , & V_24 -> V_4 ) ;
V_101 = F_66 ( 0 , V_24 -> V_109 ) ;
if ( V_101 < 0 ) {
V_72 = V_101 ;
goto V_110;
}
V_24 -> V_78 = V_101 ;
V_72 = F_39 ( V_24 ) ;
if ( V_72 )
goto V_111;
return V_100 ;
V_111:
F_67 ( V_24 -> V_78 , V_24 -> V_109 ) ;
V_110:
F_68 ( V_24 -> V_26 ) ;
V_108:
F_53 ( & V_94 , V_95 ) ;
F_69 ( & V_24 -> V_96 ) ;
F_56 ( & V_94 ) ;
F_51 ( V_24 ) ;
V_105:
F_18 ( L_13 , V_99 ) ;
F_70 ( V_103 ) ;
return V_72 ;
}
static T_6 F_71 ( struct V_87 * V_89 ,
struct V_90 * V_14 ,
const char * V_99 ,
T_7 V_100 )
{
struct V_23 * V_24 = NULL ;
int V_112 , V_72 ;
unsigned long V_113 ;
struct V_93 * V_41 ;
V_72 = F_72 ( V_99 , 10 , & V_113 ) ;
if ( V_72 )
return V_72 ;
V_112 = ( int ) V_113 ;
if ( V_112 != V_113 )
return - V_107 ;
F_53 ( & V_94 , V_95 ) ;
F_54 (tmp, &osdblkdev_list) {
V_24 = F_55 ( V_41 , struct V_23 , V_96 ) ;
if ( V_24 -> V_77 == V_112 ) {
F_69 ( & V_24 -> V_96 ) ;
break;
}
V_24 = NULL ;
}
F_56 ( & V_94 ) ;
if ( ! V_24 )
return - V_114 ;
F_35 ( V_24 ) ;
F_67 ( V_24 -> V_78 , V_24 -> V_109 ) ;
F_68 ( V_24 -> V_26 ) ;
F_51 ( V_24 ) ;
F_70 ( V_103 ) ;
return V_100 ;
}
static int F_73 ( void )
{
int V_9 = 0 ;
V_115 = F_59 ( sizeof( * V_115 ) , V_27 ) ;
if ( ! V_115 )
return - V_28 ;
V_115 -> V_109 = V_76 ;
V_115 -> V_116 = V_103 ;
V_115 -> V_117 = F_50 ;
V_115 -> V_118 = V_119 ;
V_9 = F_74 ( V_115 ) ;
if ( V_9 ) {
F_51 ( V_115 ) ;
V_115 = NULL ;
F_49 ( V_120 L_14 ) ;
return V_9 ;
}
return 0 ;
}
static void F_75 ( void )
{
if ( V_115 )
F_76 ( V_115 ) ;
V_115 = NULL ;
}
static int T_8 F_77 ( void )
{
int V_72 ;
V_72 = F_73 () ;
if ( V_72 )
return V_72 ;
return 0 ;
}
static void T_9 F_78 ( void )
{
F_75 () ;
}
