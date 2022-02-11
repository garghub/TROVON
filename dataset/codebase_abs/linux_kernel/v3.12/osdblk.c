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
V_41 = F_23 ( V_43 , V_44 ) ;
if ( ! V_41 )
goto V_47;
V_41 -> V_48 = NULL ;
V_44 &= ~ V_49 ;
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
V_47:
F_18 ( L_2 ) ;
F_20 ( V_45 ) ;
return NULL ;
}
static void F_24 ( struct V_50 * V_51 )
{
struct V_23 * V_24 = V_51 -> V_52 ;
while ( 1 ) {
struct V_53 * V_38 ;
struct V_34 * V_35 ;
struct V_5 * V_6 ;
struct V_39 * V_39 ;
bool V_54 , V_55 ;
V_38 = F_25 ( V_51 ) ;
if ( ! V_38 )
break;
if ( V_38 -> V_56 != V_57 ) {
F_26 ( V_38 , 0 ) ;
continue;
}
V_55 = V_38 -> V_58 & V_59 ;
V_54 = ( F_27 ( V_38 ) == V_60 ) ;
if ( ! V_55 ) {
V_39 = F_22 ( V_38 -> V_39 , V_61 ) ;
if ( ! V_39 )
break;
} else
V_39 = NULL ;
V_6 = F_11 ( V_24 -> V_26 , V_61 ) ;
if ( ! V_6 ) {
F_20 ( V_39 ) ;
F_18 ( L_3 ) ;
break;
}
V_35 = & V_24 -> V_62 [ V_38 -> V_63 ] ;
V_35 -> V_38 = V_38 ;
V_35 -> V_39 = V_39 ;
V_35 -> V_24 = V_24 ;
if ( V_55 )
F_28 ( V_6 , & V_24 -> V_4 ,
V_64 , 0 , 0 ) ;
else if ( V_54 )
F_29 ( V_6 , & V_24 -> V_4 , F_30 ( V_38 ) * 512ULL ,
V_39 , F_31 ( V_38 ) ) ;
else
F_32 ( V_6 , & V_24 -> V_4 , F_30 ( V_38 ) * 512ULL ,
V_39 , F_31 ( V_38 ) ) ;
F_18 ( L_4 ,
V_55 ? L_5 : V_54 ?
L_6 : L_7 , F_31 ( V_38 ) ,
F_30 ( V_38 ) * 512ULL ) ;
if ( F_6 ( V_6 , F_16 , V_35 ,
V_24 -> V_31 ) ) {
F_15 ( V_6 ) ;
F_33 ( V_51 , V_38 ) ;
F_20 ( V_39 ) ;
F_18 ( L_8 ) ;
break;
}
V_38 -> V_65 = NULL ;
}
}
static void F_34 ( struct V_23 * V_24 )
{
struct V_66 * V_67 = V_24 -> V_67 ;
if ( ! V_67 )
return;
if ( V_67 -> V_68 & V_69 )
F_35 ( V_67 ) ;
if ( V_67 -> V_70 )
F_36 ( V_67 -> V_70 ) ;
F_37 ( V_67 ) ;
}
static int F_38 ( struct V_23 * V_24 )
{
struct V_66 * V_67 ;
struct V_50 * V_51 ;
int V_71 ;
T_4 V_72 = 0 ;
V_71 = F_10 ( V_24 , & V_72 ) ;
if ( V_71 )
return V_71 ;
V_67 = F_39 ( V_73 ) ;
if ( ! V_67 )
return - V_28 ;
sprintf ( V_67 -> V_74 , V_75 L_9 , V_24 -> V_76 ) ;
V_67 -> V_77 = V_24 -> V_77 ;
V_67 -> V_78 = 0 ;
V_67 -> V_79 = & V_80 ;
V_67 -> V_81 = V_24 ;
V_51 = F_40 ( F_24 , & V_24 -> V_82 ) ;
if ( ! V_51 ) {
F_37 ( V_67 ) ;
return - V_28 ;
}
V_71 = F_41 ( V_51 , V_83 , NULL ) ;
if ( V_71 ) {
F_36 ( V_51 ) ;
F_37 ( V_67 ) ;
return V_71 ;
}
F_42 ( V_51 , F_43 ( V_24 -> V_26 ) ) ;
F_44 ( V_51 , V_84 ) ;
F_45 ( V_51 , V_59 ) ;
V_67 -> V_70 = V_51 ;
V_51 -> V_52 = V_24 ;
V_24 -> V_67 = V_67 ;
V_24 -> V_51 = V_51 ;
F_46 ( V_67 , V_72 / 512ULL ) ;
F_47 ( V_67 ) ;
F_48 ( V_85 L_10 ,
V_67 -> V_74 , ( unsigned long long ) V_72 ) ;
return 0 ;
}
static void F_49 ( struct V_86 * V_87 )
{
F_50 ( V_87 ) ;
}
static T_6 F_51 ( struct V_86 * V_88 ,
struct V_89 * V_14 ,
char * V_90 )
{
int V_91 = 0 ;
struct V_92 * V_41 ;
F_52 ( & V_93 , V_94 ) ;
F_53 (tmp, &osdblkdev_list) {
struct V_23 * V_24 ;
V_24 = F_54 ( V_41 , struct V_23 , V_95 ) ;
V_91 += sprintf ( V_90 + V_91 , L_11 ,
V_24 -> V_76 ,
V_24 -> V_77 ,
V_24 -> V_4 . V_96 ,
V_24 -> V_4 . V_76 ,
V_24 -> V_97 ) ;
}
F_55 ( & V_93 ) ;
return V_91 ;
}
static T_6 F_56 ( struct V_86 * V_88 ,
struct V_89 * V_14 ,
const char * V_98 , T_7 V_99 )
{
struct V_23 * V_24 ;
T_6 V_71 ;
int V_100 , V_101 = 0 ;
struct V_92 * V_41 ;
if ( ! F_57 ( V_102 ) )
return - V_103 ;
V_24 = F_58 ( sizeof( * V_24 ) + strlen ( V_98 ) + 1 , V_27 ) ;
if ( ! V_24 ) {
V_71 = - V_28 ;
goto V_104;
}
F_59 ( & V_24 -> V_82 ) ;
F_60 ( & V_24 -> V_95 ) ;
F_52 ( & V_93 , V_94 ) ;
F_53 (tmp, &osdblkdev_list) {
struct V_23 * V_24 ;
V_24 = F_54 ( V_41 , struct V_23 , V_95 ) ;
if ( V_24 -> V_76 > V_101 )
V_101 = V_24 -> V_76 + 1 ;
}
V_24 -> V_76 = V_101 ;
F_61 ( & V_24 -> V_95 , & V_105 ) ;
F_55 ( & V_93 ) ;
if ( sscanf ( V_98 , L_12 , & V_24 -> V_4 . V_96 , & V_24 -> V_4 . V_76 ,
V_24 -> V_97 ) != 3 ) {
V_71 = - V_106 ;
goto V_107;
}
sprintf ( V_24 -> V_108 , V_75 L_9 , V_24 -> V_76 ) ;
V_24 -> V_26 = F_62 ( V_24 -> V_97 ) ;
if ( F_63 ( V_24 -> V_26 ) ) {
V_71 = F_64 ( V_24 -> V_26 ) ;
goto V_107;
}
F_1 ( V_24 -> V_31 , & V_24 -> V_4 ) ;
V_100 = F_65 ( 0 , V_24 -> V_108 ) ;
if ( V_100 < 0 ) {
V_71 = V_100 ;
goto V_109;
}
V_24 -> V_77 = V_100 ;
V_71 = F_38 ( V_24 ) ;
if ( V_71 )
goto V_110;
return V_99 ;
V_110:
F_66 ( V_24 -> V_77 , V_24 -> V_108 ) ;
V_109:
F_67 ( V_24 -> V_26 ) ;
V_107:
F_52 ( & V_93 , V_94 ) ;
F_68 ( & V_24 -> V_95 ) ;
F_55 ( & V_93 ) ;
F_50 ( V_24 ) ;
V_104:
F_18 ( L_13 , V_98 ) ;
F_69 ( V_102 ) ;
return V_71 ;
}
static T_6 F_70 ( struct V_86 * V_88 ,
struct V_89 * V_14 ,
const char * V_98 ,
T_7 V_99 )
{
struct V_23 * V_24 = NULL ;
int V_111 , V_71 ;
unsigned long V_112 ;
struct V_92 * V_41 ;
V_71 = F_71 ( V_98 , 10 , & V_112 ) ;
if ( V_71 )
return V_71 ;
V_111 = ( int ) V_112 ;
if ( V_111 != V_112 )
return - V_106 ;
F_52 ( & V_93 , V_94 ) ;
F_53 (tmp, &osdblkdev_list) {
V_24 = F_54 ( V_41 , struct V_23 , V_95 ) ;
if ( V_24 -> V_76 == V_111 ) {
F_68 ( & V_24 -> V_95 ) ;
break;
}
V_24 = NULL ;
}
F_55 ( & V_93 ) ;
if ( ! V_24 )
return - V_113 ;
F_34 ( V_24 ) ;
F_66 ( V_24 -> V_77 , V_24 -> V_108 ) ;
F_67 ( V_24 -> V_26 ) ;
F_50 ( V_24 ) ;
F_69 ( V_102 ) ;
return V_99 ;
}
static int F_72 ( void )
{
int V_9 = 0 ;
V_114 = F_58 ( sizeof( * V_114 ) , V_27 ) ;
if ( ! V_114 )
return - V_28 ;
V_114 -> V_108 = V_75 ;
V_114 -> V_115 = V_102 ;
V_114 -> V_116 = F_49 ;
V_114 -> V_117 = V_118 ;
V_9 = F_73 ( V_114 ) ;
if ( V_9 ) {
F_50 ( V_114 ) ;
V_114 = NULL ;
F_48 ( V_119 L_14 ) ;
return V_9 ;
}
return 0 ;
}
static void F_74 ( void )
{
if ( V_114 )
F_75 ( V_114 ) ;
V_114 = NULL ;
}
static int T_8 F_76 ( void )
{
int V_71 ;
V_71 = F_72 () ;
if ( V_71 )
return V_71 ;
return 0 ;
}
static void T_9 F_77 ( void )
{
F_74 () ;
}
