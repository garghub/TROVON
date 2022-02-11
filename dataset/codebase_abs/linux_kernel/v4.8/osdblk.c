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
V_55 = ( F_27 ( V_38 ) == V_58 ) ;
V_54 = ( F_28 ( V_38 ) == V_59 ) ;
if ( ! V_55 ) {
V_39 = F_22 ( V_38 -> V_39 , V_60 ) ;
if ( ! V_39 )
break;
} else
V_39 = NULL ;
V_6 = F_11 ( V_24 -> V_26 , V_60 ) ;
if ( ! V_6 ) {
F_20 ( V_39 ) ;
F_18 ( L_3 ) ;
break;
}
V_35 = & V_24 -> V_61 [ V_38 -> V_62 ] ;
V_35 -> V_38 = V_38 ;
V_35 -> V_39 = V_39 ;
V_35 -> V_24 = V_24 ;
if ( V_55 )
F_29 ( V_6 , & V_24 -> V_4 ,
V_63 , 0 , 0 ) ;
else if ( V_54 )
F_30 ( V_6 , & V_24 -> V_4 , F_31 ( V_38 ) * 512ULL ,
V_39 , F_32 ( V_38 ) ) ;
else
F_33 ( V_6 , & V_24 -> V_4 , F_31 ( V_38 ) * 512ULL ,
V_39 , F_32 ( V_38 ) ) ;
F_18 ( L_4 ,
V_55 ? L_5 : V_54 ?
L_6 : L_7 , F_32 ( V_38 ) ,
F_31 ( V_38 ) * 512ULL ) ;
if ( F_6 ( V_6 , F_16 , V_35 ,
V_24 -> V_31 ) ) {
F_15 ( V_6 ) ;
F_34 ( V_51 , V_38 ) ;
F_20 ( V_39 ) ;
F_18 ( L_8 ) ;
break;
}
V_38 -> V_64 = NULL ;
}
}
static void F_35 ( struct V_23 * V_24 )
{
struct V_65 * V_66 = V_24 -> V_66 ;
if ( ! V_66 )
return;
if ( V_66 -> V_67 & V_68 )
F_36 ( V_66 ) ;
if ( V_66 -> V_69 )
F_37 ( V_66 -> V_69 ) ;
F_38 ( V_66 ) ;
}
static int F_39 ( struct V_23 * V_24 )
{
struct V_65 * V_66 ;
struct V_50 * V_51 ;
int V_70 ;
T_4 V_71 = 0 ;
V_70 = F_10 ( V_24 , & V_71 ) ;
if ( V_70 )
return V_70 ;
V_66 = F_40 ( V_72 ) ;
if ( ! V_66 )
return - V_28 ;
sprintf ( V_66 -> V_73 , V_74 L_9 , V_24 -> V_75 ) ;
V_66 -> V_76 = V_24 -> V_76 ;
V_66 -> V_77 = 0 ;
V_66 -> V_78 = & V_79 ;
V_66 -> V_80 = V_24 ;
V_51 = F_41 ( F_24 , & V_24 -> V_81 ) ;
if ( ! V_51 ) {
F_38 ( V_66 ) ;
return - V_28 ;
}
V_70 = F_42 ( V_51 , V_82 , NULL , V_83 ) ;
if ( V_70 ) {
F_37 ( V_51 ) ;
F_38 ( V_66 ) ;
return V_70 ;
}
F_43 ( V_51 , F_44 ( V_24 -> V_26 ) ) ;
F_45 ( V_51 , V_84 ) ;
F_46 ( V_51 , true , false ) ;
V_66 -> V_69 = V_51 ;
V_51 -> V_52 = V_24 ;
V_24 -> V_66 = V_66 ;
V_24 -> V_51 = V_51 ;
F_47 ( V_66 , V_71 / 512ULL ) ;
F_48 ( V_66 ) ;
F_49 ( V_85 L_10 ,
V_66 -> V_73 , ( unsigned long long ) V_71 ) ;
return 0 ;
}
static void F_50 ( struct V_86 * V_87 )
{
F_51 ( V_87 ) ;
}
static T_6 F_52 ( struct V_86 * V_88 ,
struct V_89 * V_14 ,
char * V_90 )
{
int V_91 = 0 ;
struct V_92 * V_41 ;
F_53 ( & V_93 , V_94 ) ;
F_54 (tmp, &osdblkdev_list) {
struct V_23 * V_24 ;
V_24 = F_55 ( V_41 , struct V_23 , V_95 ) ;
V_91 += sprintf ( V_90 + V_91 , L_11 ,
V_24 -> V_75 ,
V_24 -> V_76 ,
V_24 -> V_4 . V_96 ,
V_24 -> V_4 . V_75 ,
V_24 -> V_97 ) ;
}
F_56 ( & V_93 ) ;
return V_91 ;
}
static T_6 F_57 ( struct V_86 * V_88 ,
struct V_89 * V_14 ,
const char * V_98 , T_7 V_99 )
{
struct V_23 * V_24 ;
T_6 V_70 ;
int V_100 , V_101 = 0 ;
struct V_92 * V_41 ;
if ( ! F_58 ( V_102 ) )
return - V_103 ;
V_24 = F_59 ( sizeof( * V_24 ) + strlen ( V_98 ) + 1 , V_27 ) ;
if ( ! V_24 ) {
V_70 = - V_28 ;
goto V_104;
}
F_60 ( & V_24 -> V_81 ) ;
F_61 ( & V_24 -> V_95 ) ;
F_53 ( & V_93 , V_94 ) ;
F_54 (tmp, &osdblkdev_list) {
struct V_23 * V_24 ;
V_24 = F_55 ( V_41 , struct V_23 , V_95 ) ;
if ( V_24 -> V_75 > V_101 )
V_101 = V_24 -> V_75 + 1 ;
}
V_24 -> V_75 = V_101 ;
F_62 ( & V_24 -> V_95 , & V_105 ) ;
F_56 ( & V_93 ) ;
if ( sscanf ( V_98 , L_12 , & V_24 -> V_4 . V_96 , & V_24 -> V_4 . V_75 ,
V_24 -> V_97 ) != 3 ) {
V_70 = - V_106 ;
goto V_107;
}
sprintf ( V_24 -> V_108 , V_74 L_9 , V_24 -> V_75 ) ;
V_24 -> V_26 = F_63 ( V_24 -> V_97 ) ;
if ( F_64 ( V_24 -> V_26 ) ) {
V_70 = F_65 ( V_24 -> V_26 ) ;
goto V_107;
}
F_1 ( V_24 -> V_31 , & V_24 -> V_4 ) ;
V_100 = F_66 ( 0 , V_24 -> V_108 ) ;
if ( V_100 < 0 ) {
V_70 = V_100 ;
goto V_109;
}
V_24 -> V_76 = V_100 ;
V_70 = F_39 ( V_24 ) ;
if ( V_70 )
goto V_110;
return V_99 ;
V_110:
F_67 ( V_24 -> V_76 , V_24 -> V_108 ) ;
V_109:
F_68 ( V_24 -> V_26 ) ;
V_107:
F_53 ( & V_93 , V_94 ) ;
F_69 ( & V_24 -> V_95 ) ;
F_56 ( & V_93 ) ;
F_51 ( V_24 ) ;
V_104:
F_18 ( L_13 , V_98 ) ;
F_70 ( V_102 ) ;
return V_70 ;
}
static T_6 F_71 ( struct V_86 * V_88 ,
struct V_89 * V_14 ,
const char * V_98 ,
T_7 V_99 )
{
struct V_23 * V_24 = NULL ;
int V_111 , V_70 ;
unsigned long V_112 ;
struct V_92 * V_41 ;
V_70 = F_72 ( V_98 , 10 , & V_112 ) ;
if ( V_70 )
return V_70 ;
V_111 = ( int ) V_112 ;
if ( V_111 != V_112 )
return - V_106 ;
F_53 ( & V_93 , V_94 ) ;
F_54 (tmp, &osdblkdev_list) {
V_24 = F_55 ( V_41 , struct V_23 , V_95 ) ;
if ( V_24 -> V_75 == V_111 ) {
F_69 ( & V_24 -> V_95 ) ;
break;
}
V_24 = NULL ;
}
F_56 ( & V_93 ) ;
if ( ! V_24 )
return - V_113 ;
F_35 ( V_24 ) ;
F_67 ( V_24 -> V_76 , V_24 -> V_108 ) ;
F_68 ( V_24 -> V_26 ) ;
F_51 ( V_24 ) ;
F_70 ( V_102 ) ;
return V_99 ;
}
static int F_73 ( void )
{
int V_9 = 0 ;
V_114 = F_59 ( sizeof( * V_114 ) , V_27 ) ;
if ( ! V_114 )
return - V_28 ;
V_114 -> V_108 = V_74 ;
V_114 -> V_115 = V_102 ;
V_114 -> V_116 = F_50 ;
V_114 -> V_117 = V_118 ;
V_9 = F_74 ( V_114 ) ;
if ( V_9 ) {
F_51 ( V_114 ) ;
V_114 = NULL ;
F_49 ( V_119 L_14 ) ;
return V_9 ;
}
return 0 ;
}
static void F_75 ( void )
{
if ( V_114 )
F_76 ( V_114 ) ;
V_114 = NULL ;
}
static int T_8 F_77 ( void )
{
int V_70 ;
V_70 = F_73 () ;
if ( V_70 )
return V_70 ;
return 0 ;
}
static void T_9 F_78 ( void )
{
F_75 () ;
}
