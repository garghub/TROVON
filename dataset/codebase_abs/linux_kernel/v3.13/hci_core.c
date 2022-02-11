static void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_2 , V_3 ) ;
}
static T_1 F_3 ( struct V_4 * V_4 , char T_2 * V_5 ,
T_3 V_6 , T_4 * V_7 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
char V_9 [ 3 ] ;
V_9 [ 0 ] = F_4 ( V_10 , & V_2 -> V_11 ) ? 'Y' : 'N' ;
V_9 [ 1 ] = '\n' ;
V_9 [ 2 ] = '\0' ;
return F_5 ( V_5 , V_6 , V_7 , V_9 , 2 ) ;
}
static T_1 F_6 ( struct V_4 * V_4 , const char T_2 * V_5 ,
T_3 V_6 , T_4 * V_7 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
struct V_12 * V_13 ;
char V_9 [ 32 ] ;
T_3 V_14 = F_7 ( V_6 , ( sizeof( V_9 ) - 1 ) ) ;
bool V_15 ;
int V_16 ;
if ( ! F_4 ( V_17 , & V_2 -> V_18 ) )
return - V_19 ;
if ( F_8 ( V_9 , V_5 , V_14 ) )
return - V_20 ;
V_9 [ V_14 ] = '\0' ;
if ( F_9 ( V_9 , & V_15 ) )
return - V_21 ;
if ( V_15 == F_4 ( V_10 , & V_2 -> V_11 ) )
return - V_22 ;
F_10 ( V_2 ) ;
if ( V_15 )
V_13 = F_11 ( V_2 , V_23 , 0 , NULL ,
V_24 ) ;
else
V_13 = F_11 ( V_2 , V_25 , 0 , NULL ,
V_24 ) ;
F_12 ( V_2 ) ;
if ( F_13 ( V_13 ) )
return F_14 ( V_13 ) ;
V_16 = - F_15 ( V_13 -> V_26 [ 0 ] ) ;
F_16 ( V_13 ) ;
if ( V_16 < 0 )
return V_16 ;
F_17 ( V_10 , & V_2 -> V_11 ) ;
return V_6 ;
}
static int F_18 ( struct V_27 * V_28 , void * V_29 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
T_5 V_31 ;
F_19 ( V_2 ) ;
for ( V_31 = 0 ; V_31 < V_32 && V_31 <= V_2 -> V_33 ; V_31 ++ ) {
F_20 ( V_28 , L_1
L_2 , V_31 ,
V_2 -> V_34 [ V_31 ] [ 0 ] , V_2 -> V_34 [ V_31 ] [ 1 ] ,
V_2 -> V_34 [ V_31 ] [ 2 ] , V_2 -> V_34 [ V_31 ] [ 3 ] ,
V_2 -> V_34 [ V_31 ] [ 4 ] , V_2 -> V_34 [ V_31 ] [ 5 ] ,
V_2 -> V_34 [ V_31 ] [ 6 ] , V_2 -> V_34 [ V_31 ] [ 7 ] ) ;
}
if ( F_21 ( V_2 ) )
F_20 ( V_28 , L_3
L_2 ,
V_2 -> V_35 [ 0 ] , V_2 -> V_35 [ 1 ] ,
V_2 -> V_35 [ 2 ] , V_2 -> V_35 [ 3 ] ,
V_2 -> V_35 [ 4 ] , V_2 -> V_35 [ 5 ] ,
V_2 -> V_35 [ 6 ] , V_2 -> V_35 [ 7 ] ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_23 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_18 , V_36 -> V_37 ) ;
}
static int F_25 ( struct V_27 * V_28 , void * V_31 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
struct V_38 * V_39 ;
F_19 ( V_2 ) ;
F_26 (b, &hdev->blacklist, list)
F_20 ( V_28 , L_4 , & V_39 -> V_40 , V_39 -> V_41 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_27 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_25 , V_36 -> V_37 ) ;
}
static int F_28 ( struct V_27 * V_28 , void * V_31 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
struct V_42 * V_43 ;
F_19 ( V_2 ) ;
F_26 (uuid, &hdev->uuids, list) {
T_5 V_44 , V_45 [ 16 ] ;
for ( V_44 = 0 ; V_44 < 16 ; V_44 ++ )
V_45 [ V_44 ] = V_43 -> V_43 [ 15 - V_44 ] ;
F_20 ( V_28 , L_5 , V_45 ) ;
}
F_22 ( V_2 ) ;
return 0 ;
}
static int F_29 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_28 , V_36 -> V_37 ) ;
}
static int F_30 ( struct V_27 * V_28 , void * V_31 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_49 * V_50 ;
F_19 ( V_2 ) ;
F_26 (e, &cache->all, all) {
struct V_51 * V_26 = & V_50 -> V_26 ;
F_20 ( V_28 , L_6 ,
& V_26 -> V_40 ,
V_26 -> V_52 , V_26 -> V_53 ,
V_26 -> V_54 , V_26 -> V_55 [ 2 ] ,
V_26 -> V_55 [ 1 ] , V_26 -> V_55 [ 0 ] ,
F_31 ( V_26 -> V_56 ) ,
V_26 -> V_57 , V_26 -> V_58 , V_50 -> V_59 ) ;
}
F_22 ( V_2 ) ;
return 0 ;
}
static int F_32 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_30 , V_36 -> V_37 ) ;
}
static int F_33 ( struct V_27 * V_28 , void * V_29 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
struct V_60 * V_31 , * V_61 ;
F_19 ( V_2 ) ;
F_34 (p, n, &hdev->link_keys) {
struct V_62 * V_63 = F_35 ( V_31 , struct V_62 , V_64 ) ;
F_20 ( V_28 , L_7 , & V_63 -> V_40 , V_63 -> type ,
V_65 , V_63 -> V_45 , V_63 -> V_66 ) ;
}
F_22 ( V_2 ) ;
return 0 ;
}
static int F_36 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_33 , V_36 -> V_37 ) ;
}
static T_1 F_37 ( struct V_4 * V_4 , char T_2 * V_5 ,
T_3 V_6 , T_4 * V_7 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
char V_9 [ 3 ] ;
V_9 [ 0 ] = F_4 ( V_67 , & V_2 -> V_11 ) ? 'Y' : 'N' ;
V_9 [ 1 ] = '\n' ;
V_9 [ 2 ] = '\0' ;
return F_5 ( V_5 , V_6 , V_7 , V_9 , 2 ) ;
}
static int F_38 ( struct V_27 * V_28 , void * V_29 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
F_19 ( V_2 ) ;
F_20 ( V_28 , L_8 , V_2 -> V_55 [ 2 ] ,
V_2 -> V_55 [ 1 ] , V_2 -> V_55 [ 0 ] ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_39 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_38 , V_36 -> V_37 ) ;
}
static int F_40 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_68 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_41 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
V_2 -> V_69 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_42 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_69 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_43 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
struct V_12 * V_13 ;
T_7 V_70 ;
int V_16 ;
if ( V_45 != 0 && V_45 != 1 )
return - V_21 ;
if ( ! F_4 ( V_17 , & V_2 -> V_18 ) )
return - V_19 ;
F_10 ( V_2 ) ;
V_70 = V_45 ;
V_13 = F_11 ( V_2 , V_71 , sizeof( V_70 ) ,
& V_70 , V_24 ) ;
F_12 ( V_2 ) ;
if ( F_13 ( V_13 ) )
return F_14 ( V_13 ) ;
V_16 = - F_15 ( V_13 -> V_26 [ 0 ] ) ;
F_16 ( V_13 ) ;
if ( V_16 < 0 )
return V_16 ;
F_19 ( V_2 ) ;
V_2 -> V_72 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_44 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_72 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_45 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 != 0 && ( V_45 < 500 || V_45 > 3600000 ) )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_73 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_46 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_73 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_47 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 == 0 || V_45 % 2 || V_45 > V_2 -> V_74 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_75 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_48 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_75 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_49 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 == 0 || V_45 % 2 || V_45 < V_2 -> V_75 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_74 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_50 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_74 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_51 ( struct V_27 * V_28 , void * V_31 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
F_19 ( V_2 ) ;
F_20 ( V_28 , L_9 , & V_2 -> V_76 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_52 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_51 , V_36 -> V_37 ) ;
}
static int F_53 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 != 0 && V_45 != 1 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_77 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_54 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_77 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_55 ( struct V_27 * V_28 , void * V_29 )
{
struct V_1 * V_2 = V_28 -> V_30 ;
struct V_60 * V_31 , * V_61 ;
F_19 ( V_2 ) ;
F_34 (p, n, &hdev->link_keys) {
struct V_78 * V_79 = F_35 ( V_31 , struct V_78 , V_64 ) ;
F_20 ( V_28 , L_10 ,
& V_79 -> V_40 , V_79 -> V_41 , V_79 -> V_80 ,
V_79 -> type , V_79 -> V_81 , F_31 ( V_79 -> V_82 ) ,
8 , V_79 -> rand , 16 , V_79 -> V_45 ) ;
}
F_22 ( V_2 ) ;
return 0 ;
}
static int F_56 ( struct V_36 * V_36 , struct V_4 * V_4 )
{
return F_24 ( V_4 , F_55 , V_36 -> V_37 ) ;
}
static int F_57 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 < 0x0006 || V_45 > 0x0c80 || V_45 > V_2 -> V_83 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_84 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_58 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_84 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_59 ( void * V_26 , T_6 V_45 )
{
struct V_1 * V_2 = V_26 ;
if ( V_45 < 0x0006 || V_45 > 0x0c80 || V_45 < V_2 -> V_84 )
return - V_21 ;
F_19 ( V_2 ) ;
V_2 -> V_83 = V_45 ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_60 ( void * V_26 , T_6 * V_45 )
{
struct V_1 * V_2 = V_26 ;
F_19 ( V_2 ) ;
* V_45 = V_2 -> V_83 ;
F_22 ( V_2 ) ;
return 0 ;
}
static void F_61 ( struct V_1 * V_2 , T_5 V_85 )
{
F_62 ( L_11 , V_2 -> V_86 , V_85 ) ;
if ( V_2 -> V_87 == V_88 ) {
V_2 -> V_89 = V_85 ;
V_2 -> V_87 = V_90 ;
F_63 ( & V_2 -> V_91 ) ;
}
}
static void F_64 ( struct V_1 * V_2 , int V_16 )
{
F_62 ( L_12 , V_2 -> V_86 , V_16 ) ;
if ( V_2 -> V_87 == V_88 ) {
V_2 -> V_89 = V_16 ;
V_2 -> V_87 = V_92 ;
F_63 ( & V_2 -> V_91 ) ;
}
}
static struct V_12 * F_65 ( struct V_1 * V_2 , T_8 V_93 ,
T_5 V_3 )
{
struct V_94 * V_95 ;
struct V_96 * V_97 ;
struct V_12 * V_13 ;
F_19 ( V_2 ) ;
V_13 = V_2 -> V_98 ;
V_2 -> V_98 = NULL ;
F_22 ( V_2 ) ;
if ( ! V_13 )
return F_66 ( - V_99 ) ;
if ( V_13 -> V_100 < sizeof( * V_97 ) ) {
F_67 ( L_13 ) ;
goto V_101;
}
V_97 = ( void * ) V_13 -> V_26 ;
F_68 ( V_13 , V_102 ) ;
if ( V_3 ) {
if ( V_97 -> V_103 != V_3 )
goto V_101;
return V_13 ;
}
if ( V_97 -> V_103 != V_104 ) {
F_62 ( L_14 , V_97 -> V_103 ) ;
goto V_101;
}
if ( V_13 -> V_100 < sizeof( * V_95 ) ) {
F_67 ( L_15 ) ;
goto V_101;
}
V_95 = ( void * ) V_13 -> V_26 ;
F_68 ( V_13 , sizeof( * V_95 ) ) ;
if ( V_93 == F_31 ( V_95 -> V_93 ) )
return V_13 ;
F_62 ( L_16 , V_93 ,
F_31 ( V_95 -> V_93 ) ) ;
V_101:
F_16 ( V_13 ) ;
return F_66 ( - V_99 ) ;
}
struct V_12 * F_69 ( struct V_1 * V_2 , T_8 V_93 , T_9 V_105 ,
const void * V_106 , T_5 V_3 , T_9 V_107 )
{
F_70 ( V_108 , V_109 ) ;
struct V_110 V_111 ;
int V_16 = 0 ;
F_62 ( L_17 , V_2 -> V_86 ) ;
F_71 ( & V_111 , V_2 ) ;
F_72 ( & V_111 , V_93 , V_105 , V_106 , V_3 ) ;
V_2 -> V_87 = V_88 ;
V_16 = F_73 ( & V_111 , F_61 ) ;
if ( V_16 < 0 )
return F_66 ( V_16 ) ;
F_74 ( & V_2 -> V_91 , & V_108 ) ;
F_75 ( V_112 ) ;
F_76 ( V_107 ) ;
F_77 ( & V_2 -> V_91 , & V_108 ) ;
if ( F_78 ( V_109 ) )
return F_66 ( - V_113 ) ;
switch ( V_2 -> V_87 ) {
case V_90 :
V_16 = - F_15 ( V_2 -> V_89 ) ;
break;
case V_92 :
V_16 = - V_2 -> V_89 ;
break;
default:
V_16 = - V_114 ;
break;
}
V_2 -> V_87 = V_2 -> V_89 = 0 ;
F_62 ( L_18 , V_2 -> V_86 , V_16 ) ;
if ( V_16 < 0 )
return F_66 ( V_16 ) ;
return F_65 ( V_2 , V_93 , V_3 ) ;
}
struct V_12 * F_11 ( struct V_1 * V_2 , T_8 V_93 , T_9 V_105 ,
const void * V_106 , T_9 V_107 )
{
return F_69 ( V_2 , V_93 , V_105 , V_106 , 0 , V_107 ) ;
}
static int F_79 ( struct V_1 * V_2 ,
void (* F_80)( struct V_110 * V_111 ,
unsigned long V_115 ) ,
unsigned long V_115 , T_10 V_107 )
{
struct V_110 V_111 ;
F_70 ( V_108 , V_109 ) ;
int V_16 = 0 ;
F_62 ( L_19 , V_2 -> V_86 ) ;
F_71 ( & V_111 , V_2 ) ;
V_2 -> V_87 = V_88 ;
F_80 ( & V_111 , V_115 ) ;
V_16 = F_73 ( & V_111 , F_61 ) ;
if ( V_16 < 0 ) {
V_2 -> V_87 = 0 ;
if ( V_16 == - V_99 )
return 0 ;
return V_16 ;
}
F_74 ( & V_2 -> V_91 , & V_108 ) ;
F_75 ( V_112 ) ;
F_76 ( V_107 ) ;
F_77 ( & V_2 -> V_91 , & V_108 ) ;
if ( F_78 ( V_109 ) )
return - V_113 ;
switch ( V_2 -> V_87 ) {
case V_90 :
V_16 = - F_15 ( V_2 -> V_89 ) ;
break;
case V_92 :
V_16 = - V_2 -> V_89 ;
break;
default:
V_16 = - V_114 ;
break;
}
V_2 -> V_87 = V_2 -> V_89 = 0 ;
F_62 ( L_18 , V_2 -> V_86 , V_16 ) ;
return V_16 ;
}
static int F_81 ( struct V_1 * V_2 ,
void (* V_111)( struct V_110 * V_111 ,
unsigned long V_115 ) ,
unsigned long V_115 , T_10 V_107 )
{
int V_116 ;
if ( ! F_4 ( V_17 , & V_2 -> V_18 ) )
return - V_19 ;
F_10 ( V_2 ) ;
V_116 = F_79 ( V_2 , V_111 , V_115 , V_107 ) ;
F_12 ( V_2 ) ;
return V_116 ;
}
static void F_82 ( struct V_110 * V_111 , unsigned long V_115 )
{
F_62 ( L_20 , V_111 -> V_2 -> V_86 , V_115 ) ;
F_83 ( V_117 , & V_111 -> V_2 -> V_18 ) ;
F_84 ( V_111 , V_25 , 0 , NULL ) ;
}
static void F_85 ( struct V_110 * V_111 )
{
V_111 -> V_2 -> V_118 = V_119 ;
F_84 ( V_111 , V_120 , 0 , NULL ) ;
F_84 ( V_111 , V_121 , 0 , NULL ) ;
F_84 ( V_111 , V_122 , 0 , NULL ) ;
}
static void F_86 ( struct V_110 * V_111 )
{
V_111 -> V_2 -> V_118 = V_123 ;
F_84 ( V_111 , V_121 , 0 , NULL ) ;
F_84 ( V_111 , V_124 , 0 , NULL ) ;
F_84 ( V_111 , V_120 , 0 , NULL ) ;
F_84 ( V_111 , V_125 , 0 , NULL ) ;
F_84 ( V_111 , V_126 , 0 , NULL ) ;
F_84 ( V_111 , V_127 , 0 , NULL ) ;
F_84 ( V_111 , V_128 , 0 , NULL ) ;
}
static void F_87 ( struct V_110 * V_111 , unsigned long V_115 )
{
struct V_1 * V_2 = V_111 -> V_2 ;
F_62 ( L_20 , V_2 -> V_86 , V_115 ) ;
if ( ! F_4 ( V_129 , & V_2 -> V_130 ) )
F_82 ( V_111 , 0 ) ;
switch ( V_2 -> V_131 ) {
case V_132 :
F_85 ( V_111 ) ;
break;
case V_133 :
F_86 ( V_111 ) ;
break;
default:
F_67 ( L_21 , V_2 -> V_131 ) ;
break;
}
}
static void F_88 ( struct V_110 * V_111 )
{
struct V_1 * V_2 = V_111 -> V_2 ;
T_11 V_106 ;
T_7 V_134 ;
F_84 ( V_111 , V_135 , 0 , NULL ) ;
F_84 ( V_111 , V_136 , 0 , NULL ) ;
F_84 ( V_111 , V_137 , 0 , NULL ) ;
F_84 ( V_111 , V_138 , 0 , NULL ) ;
F_84 ( V_111 , V_139 , 0 , NULL ) ;
F_84 ( V_111 , V_140 , 0 , NULL ) ;
V_134 = V_141 ;
F_84 ( V_111 , V_142 , 1 , & V_134 ) ;
V_106 = F_89 ( 0x7d00 ) ;
F_84 ( V_111 , V_143 , 2 , & V_106 ) ;
if ( V_2 -> V_144 != 31 && V_2 -> V_145 > V_146 ) {
F_84 ( V_111 , V_147 , 0 , NULL ) ;
F_84 ( V_111 , V_148 , 0 , NULL ) ;
}
}
static void F_90 ( struct V_110 * V_111 )
{
struct V_1 * V_2 = V_111 -> V_2 ;
F_84 ( V_111 , V_149 , 0 , NULL ) ;
F_84 ( V_111 , V_150 , 0 , NULL ) ;
F_84 ( V_111 , V_151 , 0 , NULL ) ;
F_84 ( V_111 , V_152 , 0 , NULL ) ;
F_84 ( V_111 , V_153 , 0 , NULL ) ;
if ( ! F_91 ( V_2 ) )
F_83 ( V_154 , & V_2 -> V_11 ) ;
}
static T_5 F_92 ( struct V_1 * V_2 )
{
if ( F_93 ( V_2 ) )
return 0x02 ;
if ( F_94 ( V_2 ) )
return 0x01 ;
if ( V_2 -> V_144 == 11 && V_2 -> V_155 == 0x00 &&
V_2 -> V_156 == 0x0757 )
return 0x01 ;
if ( V_2 -> V_144 == 15 ) {
if ( V_2 -> V_155 == 0x03 && V_2 -> V_156 == 0x6963 )
return 0x01 ;
if ( V_2 -> V_155 == 0x09 && V_2 -> V_156 == 0x6963 )
return 0x01 ;
if ( V_2 -> V_155 == 0x00 && V_2 -> V_156 == 0x6965 )
return 0x01 ;
}
if ( V_2 -> V_144 == 31 && V_2 -> V_155 == 0x2005 &&
V_2 -> V_156 == 0x1805 )
return 0x01 ;
return 0x00 ;
}
static void F_95 ( struct V_110 * V_111 )
{
T_5 V_70 ;
V_70 = F_92 ( V_111 -> V_2 ) ;
F_84 ( V_111 , V_157 , 1 , & V_70 ) ;
}
static void F_96 ( struct V_110 * V_111 )
{
struct V_1 * V_2 = V_111 -> V_2 ;
T_5 V_158 [ 8 ] = { 0xff , 0xff , 0xfb , 0xff , 0x00 , 0x00 , 0x00 , 0x00 } ;
if ( V_2 -> V_145 < V_159 )
return;
if ( F_91 ( V_2 ) ) {
V_158 [ 4 ] |= 0x01 ;
V_158 [ 4 ] |= 0x02 ;
V_158 [ 4 ] |= 0x04 ;
V_158 [ 5 ] |= 0x08 ;
V_158 [ 5 ] |= 0x10 ;
} else {
memset ( V_158 , 0 , sizeof( V_158 ) ) ;
V_158 [ 0 ] |= 0x10 ;
V_158 [ 0 ] |= 0x80 ;
V_158 [ 1 ] |= 0x08 ;
V_158 [ 1 ] |= 0x20 ;
V_158 [ 1 ] |= 0x40 ;
V_158 [ 1 ] |= 0x80 ;
V_158 [ 2 ] |= 0x04 ;
V_158 [ 3 ] |= 0x02 ;
V_158 [ 5 ] |= 0x80 ;
}
if ( F_94 ( V_2 ) )
V_158 [ 4 ] |= 0x02 ;
if ( F_97 ( V_2 ) )
V_158 [ 5 ] |= 0x20 ;
if ( F_98 ( V_2 ) )
V_158 [ 5 ] |= 0x80 ;
if ( F_93 ( V_2 ) )
V_158 [ 5 ] |= 0x40 ;
if ( F_99 ( V_2 ) )
V_158 [ 7 ] |= 0x01 ;
if ( F_100 ( V_2 ) )
V_158 [ 6 ] |= 0x80 ;
if ( F_101 ( V_2 ) ) {
V_158 [ 6 ] |= 0x01 ;
V_158 [ 6 ] |= 0x02 ;
V_158 [ 6 ] |= 0x04 ;
V_158 [ 6 ] |= 0x08 ;
V_158 [ 6 ] |= 0x10 ;
V_158 [ 6 ] |= 0x20 ;
V_158 [ 7 ] |= 0x04 ;
V_158 [ 7 ] |= 0x08 ;
V_158 [ 7 ] |= 0x10 ;
}
if ( F_21 ( V_2 ) )
V_158 [ 7 ] |= 0x20 ;
F_84 ( V_111 , V_160 , sizeof( V_158 ) , V_158 ) ;
if ( F_21 ( V_2 ) ) {
memset ( V_158 , 0 , sizeof( V_158 ) ) ;
V_158 [ 0 ] = 0x1f ;
F_84 ( V_111 , V_161 ,
sizeof( V_158 ) , V_158 ) ;
}
}
static void F_102 ( struct V_110 * V_111 , unsigned long V_115 )
{
struct V_1 * V_2 = V_111 -> V_2 ;
if ( F_91 ( V_2 ) )
F_88 ( V_111 ) ;
else
F_103 ( V_162 , & V_2 -> V_11 ) ;
if ( F_21 ( V_2 ) )
F_90 ( V_111 ) ;
F_96 ( V_111 ) ;
if ( V_2 -> V_144 != 31 && V_2 -> V_145 > V_146 )
F_84 ( V_111 , V_124 , 0 , NULL ) ;
if ( F_101 ( V_2 ) ) {
V_2 -> V_33 = 0x01 ;
if ( F_4 ( V_163 , & V_2 -> V_11 ) ) {
T_5 V_70 = 0x01 ;
F_84 ( V_111 , V_164 ,
sizeof( V_70 ) , & V_70 ) ;
} else {
struct V_165 V_166 ;
memset ( V_2 -> V_167 , 0 , sizeof( V_2 -> V_167 ) ) ;
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
F_84 ( V_111 , V_168 , sizeof( V_166 ) , & V_166 ) ;
}
}
if ( F_94 ( V_2 ) )
F_95 ( V_111 ) ;
if ( F_104 ( V_2 ) )
F_84 ( V_111 , V_169 , 0 , NULL ) ;
if ( F_105 ( V_2 ) ) {
struct V_170 V_166 ;
V_166 . V_171 = 0x01 ;
F_84 ( V_111 , V_172 ,
sizeof( V_166 ) , & V_166 ) ;
}
if ( F_4 ( V_173 , & V_2 -> V_11 ) ) {
T_5 V_15 = 1 ;
F_84 ( V_111 , V_174 , sizeof( V_15 ) ,
& V_15 ) ;
}
}
static void F_106 ( struct V_110 * V_111 )
{
struct V_1 * V_2 = V_111 -> V_2 ;
struct V_175 V_166 ;
T_8 V_176 = 0 ;
if ( F_107 ( V_2 ) )
V_176 |= V_177 ;
if ( F_108 ( V_2 ) )
V_176 |= V_178 ;
if ( F_109 ( V_2 ) )
V_176 |= V_179 ;
if ( F_110 ( V_2 ) )
V_176 |= V_180 ;
V_166 . V_181 = F_111 ( V_176 ) ;
F_84 ( V_111 , V_182 , sizeof( V_166 ) , & V_166 ) ;
}
static void F_112 ( struct V_110 * V_111 )
{
struct V_1 * V_2 = V_111 -> V_2 ;
struct V_183 V_166 ;
if ( ! F_91 ( V_2 ) )
return;
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
if ( F_4 ( V_154 , & V_2 -> V_11 ) ) {
V_166 . V_184 = 0x01 ;
V_166 . V_185 = F_113 ( V_2 ) ;
}
if ( V_166 . V_184 != F_114 ( V_2 ) )
F_84 ( V_111 , V_186 , sizeof( V_166 ) ,
& V_166 ) ;
}
static void F_115 ( struct V_110 * V_111 )
{
struct V_1 * V_2 = V_111 -> V_2 ;
T_5 V_158 [ 8 ] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
if ( V_2 -> V_34 [ 2 ] [ 0 ] & 0x01 ) {
V_158 [ 1 ] |= 0x40 ;
V_158 [ 1 ] |= 0x80 ;
V_158 [ 2 ] |= 0x10 ;
V_158 [ 2 ] |= 0x20 ;
}
if ( V_2 -> V_34 [ 2 ] [ 0 ] & 0x02 ) {
V_158 [ 2 ] |= 0x01 ;
V_158 [ 2 ] |= 0x02 ;
V_158 [ 2 ] |= 0x04 ;
V_158 [ 2 ] |= 0x08 ;
}
F_84 ( V_111 , V_187 , sizeof( V_158 ) , V_158 ) ;
}
static void F_116 ( struct V_110 * V_111 , unsigned long V_115 )
{
struct V_1 * V_2 = V_111 -> V_2 ;
T_5 V_31 ;
if ( V_2 -> V_188 [ 6 ] & 0x80 ) {
struct V_189 V_166 ;
F_117 ( & V_166 . V_40 , V_190 ) ;
V_166 . V_191 = 0x01 ;
F_84 ( V_111 , V_192 ,
sizeof( V_166 ) , & V_166 ) ;
}
if ( V_2 -> V_188 [ 5 ] & 0x10 )
F_106 ( V_111 ) ;
if ( F_21 ( V_2 ) ) {
if ( F_118 ( & V_2 -> V_40 , V_190 ) )
V_2 -> V_77 = V_193 ;
else
V_2 -> V_77 = V_194 ;
F_112 ( V_111 ) ;
}
for ( V_31 = 2 ; V_31 < V_32 && V_31 <= V_2 -> V_33 ; V_31 ++ ) {
struct V_170 V_166 ;
V_166 . V_171 = V_31 ;
F_84 ( V_111 , V_172 ,
sizeof( V_166 ) , & V_166 ) ;
}
}
static void F_119 ( struct V_110 * V_111 , unsigned long V_115 )
{
struct V_1 * V_2 = V_111 -> V_2 ;
if ( V_2 -> V_188 [ 22 ] & 0x04 )
F_115 ( V_111 ) ;
if ( V_2 -> V_34 [ 2 ] [ 0 ] & 0x04 )
F_84 ( V_111 , V_195 , 0 , NULL ) ;
}
static int F_120 ( struct V_1 * V_2 )
{
int V_16 ;
V_16 = F_79 ( V_2 , F_87 , 0 , V_196 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( F_4 ( V_197 , & V_2 -> V_11 ) ) {
F_121 ( L_22 , 0644 , V_2 -> V_198 , V_2 ,
& V_199 ) ;
}
if ( V_2 -> V_131 != V_132 )
return 0 ;
V_16 = F_79 ( V_2 , F_102 , 0 , V_196 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_79 ( V_2 , F_116 , 0 , V_196 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_79 ( V_2 , F_119 , 0 , V_196 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( ! F_4 ( V_197 , & V_2 -> V_11 ) )
return 0 ;
F_121 ( L_23 , 0444 , V_2 -> V_198 , V_2 ,
& V_200 ) ;
F_122 ( L_24 , 0444 , V_2 -> V_198 ,
& V_2 -> V_144 ) ;
F_123 ( L_25 , 0444 , V_2 -> V_198 , & V_2 -> V_145 ) ;
F_122 ( L_26 , 0444 , V_2 -> V_198 , & V_2 -> V_155 ) ;
F_121 ( L_27 , 0444 , V_2 -> V_198 , V_2 ,
& V_201 ) ;
F_121 ( L_28 , 0444 , V_2 -> V_198 , V_2 , & V_202 ) ;
if ( F_91 ( V_2 ) ) {
F_121 ( L_29 , 0444 , V_2 -> V_198 ,
V_2 , & V_203 ) ;
F_121 ( L_30 , 0400 , V_2 -> V_198 ,
V_2 , & V_204 ) ;
F_121 ( L_31 , 0444 , V_2 -> V_198 ,
V_2 , & V_205 ) ;
F_121 ( L_32 , 0444 , V_2 -> V_198 ,
V_2 , & V_206 ) ;
F_121 ( L_33 , 0444 , V_2 -> V_198 ,
V_2 , & V_207 ) ;
}
if ( F_101 ( V_2 ) ) {
F_121 ( L_34 , 0644 , V_2 -> V_198 ,
V_2 , & V_208 ) ;
F_121 ( L_35 , 0644 , V_2 -> V_198 ,
V_2 , & V_209 ) ;
}
if ( F_109 ( V_2 ) ) {
F_121 ( L_36 , 0644 , V_2 -> V_198 ,
V_2 , & V_210 ) ;
F_121 ( L_37 , 0644 , V_2 -> V_198 ,
V_2 , & V_211 ) ;
F_121 ( L_38 , 0644 , V_2 -> V_198 ,
V_2 , & V_212 ) ;
}
if ( F_21 ( V_2 ) ) {
F_123 ( L_39 , 0444 , V_2 -> V_198 ,
& V_2 -> V_213 ) ;
F_121 ( L_40 , 0444 , V_2 -> V_198 ,
V_2 , & V_214 ) ;
F_121 ( L_41 , 0644 , V_2 -> V_198 ,
V_2 , & V_215 ) ;
F_121 ( L_42 , 0400 , V_2 -> V_198 ,
V_2 , & V_216 ) ;
F_121 ( L_43 , 0644 , V_2 -> V_198 ,
V_2 , & V_217 ) ;
F_121 ( L_44 , 0644 , V_2 -> V_198 ,
V_2 , & V_218 ) ;
}
return 0 ;
}
static void F_124 ( struct V_110 * V_111 , unsigned long V_115 )
{
T_7 V_219 = V_115 ;
F_62 ( L_45 , V_111 -> V_2 -> V_86 , V_219 ) ;
F_84 ( V_111 , V_220 , 1 , & V_219 ) ;
}
static void F_125 ( struct V_110 * V_111 , unsigned long V_115 )
{
T_7 V_221 = V_115 ;
F_62 ( L_45 , V_111 -> V_2 -> V_86 , V_221 ) ;
F_84 ( V_111 , V_174 , 1 , & V_221 ) ;
}
static void F_126 ( struct V_110 * V_111 , unsigned long V_115 )
{
T_7 V_222 = V_115 ;
F_62 ( L_45 , V_111 -> V_2 -> V_86 , V_222 ) ;
F_84 ( V_111 , V_223 , 1 , & V_222 ) ;
}
static void F_127 ( struct V_110 * V_111 , unsigned long V_115 )
{
T_11 V_181 = F_111 ( V_115 ) ;
F_62 ( L_45 , V_111 -> V_2 -> V_86 , V_181 ) ;
F_84 ( V_111 , V_182 , 2 , & V_181 ) ;
}
struct V_1 * F_128 ( int V_224 )
{
struct V_1 * V_2 = NULL , * V_225 ;
F_62 ( L_46 , V_224 ) ;
if ( V_224 < 0 )
return NULL ;
F_129 ( & V_226 ) ;
F_26 (d, &hci_dev_list, list) {
if ( V_225 -> V_227 == V_224 ) {
V_2 = F_130 ( V_225 ) ;
break;
}
}
F_131 ( & V_226 ) ;
return V_2 ;
}
bool F_132 ( struct V_1 * V_2 )
{
struct V_46 * V_228 = & V_2 -> V_48 ;
switch ( V_228 -> V_229 ) {
case V_230 :
case V_231 :
return true ;
default:
return false ;
}
}
void F_133 ( struct V_1 * V_2 , int V_229 )
{
F_62 ( L_47 , V_2 -> V_86 , V_2 -> V_48 . V_229 , V_229 ) ;
if ( V_2 -> V_48 . V_229 == V_229 )
return;
switch ( V_229 ) {
case V_232 :
if ( V_2 -> V_48 . V_229 != V_233 )
F_134 ( V_2 , 0 ) ;
break;
case V_233 :
break;
case V_230 :
F_134 ( V_2 , 1 ) ;
break;
case V_231 :
break;
case V_234 :
break;
}
V_2 -> V_48 . V_229 = V_229 ;
}
void F_135 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_49 * V_31 , * V_61 ;
F_136 (p, n, &cache->all, all) {
F_137 ( & V_31 -> V_235 ) ;
F_138 ( V_31 ) ;
}
F_139 ( & V_47 -> V_236 ) ;
F_139 ( & V_47 -> V_237 ) ;
}
struct V_49 * F_140 ( struct V_1 * V_2 ,
T_12 * V_40 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_49 * V_50 ;
F_62 ( L_48 , V_47 , V_40 ) ;
F_26 (e, &cache->all, all) {
if ( ! F_118 ( & V_50 -> V_26 . V_40 , V_40 ) )
return V_50 ;
}
return NULL ;
}
struct V_49 * F_141 ( struct V_1 * V_2 ,
T_12 * V_40 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_49 * V_50 ;
F_62 ( L_48 , V_47 , V_40 ) ;
F_26 (e, &cache->unknown, list) {
if ( ! F_118 ( & V_50 -> V_26 . V_40 , V_40 ) )
return V_50 ;
}
return NULL ;
}
struct V_49 * F_142 ( struct V_1 * V_2 ,
T_12 * V_40 ,
int V_229 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_49 * V_50 ;
F_62 ( L_49 , V_47 , V_40 , V_229 ) ;
F_26 (e, &cache->resolve, list) {
if ( ! F_118 ( V_40 , V_190 ) && V_50 -> V_238 == V_229 )
return V_50 ;
if ( ! F_118 ( & V_50 -> V_26 . V_40 , V_40 ) )
return V_50 ;
}
return NULL ;
}
void F_143 ( struct V_1 * V_2 ,
struct V_49 * V_239 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_60 * V_240 = & V_47 -> V_237 ;
struct V_49 * V_31 ;
F_137 ( & V_239 -> V_64 ) ;
F_26 (p, &cache->resolve, list) {
if ( V_31 -> V_238 != V_241 &&
abs ( V_31 -> V_26 . V_57 ) >= abs ( V_239 -> V_26 . V_57 ) )
break;
V_240 = & V_31 -> V_64 ;
}
F_144 ( & V_239 -> V_64 , V_240 ) ;
}
bool F_145 ( struct V_1 * V_2 , struct V_51 * V_26 ,
bool V_242 , bool * V_243 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_49 * V_239 ;
F_62 ( L_48 , V_47 , & V_26 -> V_40 ) ;
F_146 ( V_2 , & V_26 -> V_40 ) ;
if ( V_243 )
* V_243 = V_26 -> V_58 ;
V_239 = F_140 ( V_2 , & V_26 -> V_40 ) ;
if ( V_239 ) {
if ( V_239 -> V_26 . V_58 && V_243 )
* V_243 = true ;
if ( V_239 -> V_238 == V_244 &&
V_26 -> V_57 != V_239 -> V_26 . V_57 ) {
V_239 -> V_26 . V_57 = V_26 -> V_57 ;
F_143 ( V_2 , V_239 ) ;
}
goto V_245;
}
V_239 = F_147 ( sizeof( struct V_49 ) , V_246 ) ;
if ( ! V_239 )
return false ;
F_144 ( & V_239 -> V_235 , & V_47 -> V_235 ) ;
if ( V_242 ) {
V_239 -> V_238 = V_247 ;
} else {
V_239 -> V_238 = V_248 ;
F_144 ( & V_239 -> V_64 , & V_47 -> V_236 ) ;
}
V_245:
if ( V_242 && V_239 -> V_238 != V_247 &&
V_239 -> V_238 != V_241 ) {
V_239 -> V_238 = V_247 ;
F_137 ( & V_239 -> V_64 ) ;
}
memcpy ( & V_239 -> V_26 , V_26 , sizeof( * V_26 ) ) ;
V_239 -> V_59 = V_249 ;
V_47 -> V_59 = V_249 ;
if ( V_239 -> V_238 == V_248 )
return false ;
return true ;
}
static int F_148 ( struct V_1 * V_2 , int V_250 , T_7 * V_9 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_251 * V_252 = (struct V_251 * ) V_9 ;
struct V_49 * V_50 ;
int V_253 = 0 ;
F_26 (e, &cache->all, all) {
struct V_51 * V_26 = & V_50 -> V_26 ;
if ( V_253 >= V_250 )
break;
F_117 ( & V_252 -> V_40 , & V_26 -> V_40 ) ;
V_252 -> V_52 = V_26 -> V_52 ;
V_252 -> V_53 = V_26 -> V_53 ;
V_252 -> V_54 = V_26 -> V_54 ;
memcpy ( V_252 -> V_55 , V_26 -> V_55 , 3 ) ;
V_252 -> V_56 = V_26 -> V_56 ;
V_252 ++ ;
V_253 ++ ;
}
F_62 ( L_50 , V_47 , V_253 ) ;
return V_253 ;
}
static void F_149 ( struct V_110 * V_111 , unsigned long V_115 )
{
struct V_254 * V_255 = (struct V_254 * ) V_115 ;
struct V_1 * V_2 = V_111 -> V_2 ;
struct V_256 V_166 ;
F_62 ( L_17 , V_2 -> V_86 ) ;
if ( F_4 ( V_257 , & V_2 -> V_18 ) )
return;
memcpy ( & V_166 . V_258 , & V_255 -> V_258 , 3 ) ;
V_166 . V_259 = V_255 -> V_259 ;
V_166 . V_260 = V_255 -> V_260 ;
F_84 ( V_111 , V_261 , sizeof( V_166 ) , & V_166 ) ;
}
static int F_150 ( void * V_262 )
{
F_151 () ;
return F_78 ( V_109 ) ;
}
int F_152 ( void T_2 * V_263 )
{
T_7 T_2 * V_29 = V_263 ;
struct V_254 V_255 ;
struct V_1 * V_2 ;
int V_16 = 0 , V_264 = 0 , V_265 ;
long V_266 ;
T_7 * V_9 ;
if ( F_8 ( & V_255 , V_29 , sizeof( V_255 ) ) )
return - V_20 ;
V_2 = F_128 ( V_255 . V_267 ) ;
if ( ! V_2 )
return - V_268 ;
if ( F_4 ( V_269 , & V_2 -> V_11 ) ) {
V_16 = - V_270 ;
goto V_271;
}
if ( V_2 -> V_131 != V_132 ) {
V_16 = - V_272 ;
goto V_271;
}
if ( ! F_4 ( V_162 , & V_2 -> V_11 ) ) {
V_16 = - V_272 ;
goto V_271;
}
F_19 ( V_2 ) ;
if ( F_153 ( V_2 ) > V_273 ||
F_154 ( V_2 ) || V_255 . V_18 & V_274 ) {
F_135 ( V_2 ) ;
V_264 = 1 ;
}
F_22 ( V_2 ) ;
V_266 = V_255 . V_259 * F_155 ( 2000 ) ;
if ( V_264 ) {
V_16 = F_81 ( V_2 , F_149 , ( unsigned long ) & V_255 ,
V_266 ) ;
if ( V_16 < 0 )
goto V_271;
if ( F_156 ( & V_2 -> V_18 , V_257 , F_150 ,
V_112 ) )
return - V_113 ;
}
V_265 = ( V_255 . V_260 == 0 ) ? 255 : V_255 . V_260 ;
V_9 = F_157 ( sizeof( struct V_251 ) * V_265 , V_275 ) ;
if ( ! V_9 ) {
V_16 = - V_276 ;
goto V_271;
}
F_19 ( V_2 ) ;
V_255 . V_260 = F_148 ( V_2 , V_265 , V_9 ) ;
F_22 ( V_2 ) ;
F_62 ( L_51 , V_255 . V_260 ) ;
if ( ! F_158 ( V_29 , & V_255 , sizeof( V_255 ) ) ) {
V_29 += sizeof( V_255 ) ;
if ( F_158 ( V_29 , V_9 , sizeof( struct V_251 ) *
V_255 . V_260 ) )
V_16 = - V_20 ;
} else
V_16 = - V_20 ;
F_138 ( V_9 ) ;
V_271:
F_159 ( V_2 ) ;
return V_16 ;
}
static int F_160 ( struct V_1 * V_2 )
{
int V_116 = 0 ;
F_62 ( L_52 , V_2 -> V_86 , V_2 ) ;
F_10 ( V_2 ) ;
if ( F_4 ( V_277 , & V_2 -> V_11 ) ) {
V_116 = - V_268 ;
goto V_271;
}
if ( ! F_4 ( V_197 , & V_2 -> V_11 ) ) {
if ( F_4 ( V_278 , & V_2 -> V_11 ) ) {
V_116 = - V_279 ;
goto V_271;
}
if ( V_2 -> V_131 == V_132 &&
! F_118 ( & V_2 -> V_40 , V_190 ) &&
! F_118 ( & V_2 -> V_76 , V_190 ) ) {
V_116 = - V_280 ;
goto V_271;
}
}
if ( F_4 ( V_17 , & V_2 -> V_18 ) ) {
V_116 = - V_22 ;
goto V_271;
}
if ( V_2 -> V_281 ( V_2 ) ) {
V_116 = - V_282 ;
goto V_271;
}
F_161 ( & V_2 -> V_283 , 1 ) ;
F_83 ( V_284 , & V_2 -> V_18 ) ;
if ( V_2 -> V_285 && F_4 ( V_197 , & V_2 -> V_11 ) )
V_116 = V_2 -> V_285 ( V_2 ) ;
if ( ! V_116 ) {
if ( F_4 ( V_286 , & V_2 -> V_130 ) )
F_83 ( V_287 , & V_2 -> V_18 ) ;
if ( ! F_4 ( V_287 , & V_2 -> V_18 ) &&
! F_4 ( V_269 , & V_2 -> V_11 ) )
V_116 = F_120 ( V_2 ) ;
}
F_103 ( V_284 , & V_2 -> V_18 ) ;
if ( ! V_116 ) {
F_130 ( V_2 ) ;
F_83 ( V_17 , & V_2 -> V_18 ) ;
F_1 ( V_2 , V_288 ) ;
if ( ! F_4 ( V_197 , & V_2 -> V_11 ) &&
! F_4 ( V_269 , & V_2 -> V_11 ) &&
V_2 -> V_131 == V_132 ) {
F_19 ( V_2 ) ;
F_162 ( V_2 , 1 ) ;
F_22 ( V_2 ) ;
}
} else {
F_163 ( & V_2 -> V_289 ) ;
F_163 ( & V_2 -> V_290 ) ;
F_163 ( & V_2 -> V_291 ) ;
F_164 ( & V_2 -> V_292 ) ;
F_164 ( & V_2 -> V_293 ) ;
if ( V_2 -> V_294 )
V_2 -> V_294 ( V_2 ) ;
if ( V_2 -> V_295 ) {
F_16 ( V_2 -> V_295 ) ;
V_2 -> V_295 = NULL ;
}
V_2 -> V_296 ( V_2 ) ;
V_2 -> V_18 = 0 ;
}
V_271:
F_12 ( V_2 ) ;
return V_116 ;
}
int F_165 ( T_13 V_297 )
{
struct V_1 * V_2 ;
int V_16 ;
V_2 = F_128 ( V_297 ) ;
if ( ! V_2 )
return - V_268 ;
if ( F_166 ( V_298 , & V_2 -> V_11 ) )
F_167 ( & V_2 -> V_299 ) ;
F_168 ( V_2 -> V_300 ) ;
V_16 = F_160 ( V_2 ) ;
F_159 ( V_2 ) ;
return V_16 ;
}
static int F_169 ( struct V_1 * V_2 )
{
F_62 ( L_52 , V_2 -> V_86 , V_2 ) ;
F_167 ( & V_2 -> V_299 ) ;
F_64 ( V_2 , V_268 ) ;
F_10 ( V_2 ) ;
if ( ! F_166 ( V_17 , & V_2 -> V_18 ) ) {
F_170 ( & V_2 -> V_301 ) ;
F_12 ( V_2 ) ;
return 0 ;
}
F_163 ( & V_2 -> V_289 ) ;
F_163 ( & V_2 -> V_291 ) ;
if ( V_2 -> V_302 > 0 ) {
F_167 ( & V_2 -> V_303 ) ;
V_2 -> V_302 = 0 ;
F_103 ( V_304 , & V_2 -> V_11 ) ;
F_103 ( V_305 , & V_2 -> V_11 ) ;
}
if ( F_166 ( V_306 , & V_2 -> V_11 ) )
F_167 ( & V_2 -> V_307 ) ;
F_171 ( & V_2 -> V_308 ) ;
F_19 ( V_2 ) ;
F_135 ( V_2 ) ;
F_172 ( V_2 ) ;
F_22 ( V_2 ) ;
F_1 ( V_2 , V_309 ) ;
if ( V_2 -> V_294 )
V_2 -> V_294 ( V_2 ) ;
F_164 ( & V_2 -> V_292 ) ;
F_161 ( & V_2 -> V_283 , 1 ) ;
if ( ! F_4 ( V_287 , & V_2 -> V_18 ) &&
! F_4 ( V_298 , & V_2 -> V_11 ) &&
F_4 ( V_129 , & V_2 -> V_130 ) ) {
F_83 ( V_284 , & V_2 -> V_18 ) ;
F_79 ( V_2 , F_82 , 0 , V_24 ) ;
F_103 ( V_284 , & V_2 -> V_18 ) ;
}
F_163 ( & V_2 -> V_290 ) ;
F_164 ( & V_2 -> V_293 ) ;
F_164 ( & V_2 -> V_292 ) ;
F_164 ( & V_2 -> V_310 ) ;
if ( V_2 -> V_295 ) {
F_170 ( & V_2 -> V_301 ) ;
F_16 ( V_2 -> V_295 ) ;
V_2 -> V_295 = NULL ;
}
F_16 ( V_2 -> V_98 ) ;
V_2 -> V_98 = NULL ;
V_2 -> V_296 ( V_2 ) ;
V_2 -> V_18 = 0 ;
V_2 -> V_11 &= ~ V_311 ;
if ( ! F_166 ( V_298 , & V_2 -> V_11 ) ) {
if ( V_2 -> V_131 == V_132 ) {
F_19 ( V_2 ) ;
F_162 ( V_2 , 0 ) ;
F_22 ( V_2 ) ;
}
}
V_2 -> V_312 = V_313 ;
memset ( V_2 -> V_167 , 0 , sizeof( V_2 -> V_167 ) ) ;
memset ( V_2 -> V_55 , 0 , sizeof( V_2 -> V_55 ) ) ;
F_12 ( V_2 ) ;
F_159 ( V_2 ) ;
return 0 ;
}
int F_173 ( T_13 V_297 )
{
struct V_1 * V_2 ;
int V_16 ;
V_2 = F_128 ( V_297 ) ;
if ( ! V_2 )
return - V_268 ;
if ( F_4 ( V_269 , & V_2 -> V_11 ) ) {
V_16 = - V_270 ;
goto V_271;
}
if ( F_166 ( V_298 , & V_2 -> V_11 ) )
F_167 ( & V_2 -> V_299 ) ;
V_16 = F_169 ( V_2 ) ;
V_271:
F_159 ( V_2 ) ;
return V_16 ;
}
int F_174 ( T_13 V_297 )
{
struct V_1 * V_2 ;
int V_116 = 0 ;
V_2 = F_128 ( V_297 ) ;
if ( ! V_2 )
return - V_268 ;
F_10 ( V_2 ) ;
if ( ! F_4 ( V_17 , & V_2 -> V_18 ) ) {
V_116 = - V_19 ;
goto V_271;
}
if ( F_4 ( V_269 , & V_2 -> V_11 ) ) {
V_116 = - V_270 ;
goto V_271;
}
F_164 ( & V_2 -> V_293 ) ;
F_164 ( & V_2 -> V_292 ) ;
F_19 ( V_2 ) ;
F_135 ( V_2 ) ;
F_172 ( V_2 ) ;
F_22 ( V_2 ) ;
if ( V_2 -> V_294 )
V_2 -> V_294 ( V_2 ) ;
F_161 ( & V_2 -> V_283 , 1 ) ;
V_2 -> V_314 = 0 ; V_2 -> V_315 = 0 ; V_2 -> V_316 = 0 ;
if ( ! F_4 ( V_287 , & V_2 -> V_18 ) )
V_116 = F_79 ( V_2 , F_82 , 0 , V_196 ) ;
V_271:
F_12 ( V_2 ) ;
F_159 ( V_2 ) ;
return V_116 ;
}
int F_175 ( T_13 V_297 )
{
struct V_1 * V_2 ;
int V_116 = 0 ;
V_2 = F_128 ( V_297 ) ;
if ( ! V_2 )
return - V_268 ;
if ( F_4 ( V_269 , & V_2 -> V_11 ) ) {
V_116 = - V_270 ;
goto V_271;
}
memset ( & V_2 -> V_317 , 0 , sizeof( struct V_318 ) ) ;
V_271:
F_159 ( V_2 ) ;
return V_116 ;
}
int F_176 ( unsigned int V_319 , void T_2 * V_263 )
{
struct V_1 * V_2 ;
struct V_320 V_321 ;
int V_16 = 0 ;
if ( F_8 ( & V_321 , V_263 , sizeof( V_321 ) ) )
return - V_20 ;
V_2 = F_128 ( V_321 . V_267 ) ;
if ( ! V_2 )
return - V_268 ;
if ( F_4 ( V_269 , & V_2 -> V_11 ) ) {
V_16 = - V_270 ;
goto V_271;
}
if ( V_2 -> V_131 != V_132 ) {
V_16 = - V_272 ;
goto V_271;
}
if ( ! F_4 ( V_162 , & V_2 -> V_11 ) ) {
V_16 = - V_272 ;
goto V_271;
}
switch ( V_319 ) {
case V_322 :
V_16 = F_81 ( V_2 , F_125 , V_321 . V_323 ,
V_196 ) ;
break;
case V_324 :
if ( ! F_177 ( V_2 ) ) {
V_16 = - V_272 ;
break;
}
if ( ! F_4 ( V_325 , & V_2 -> V_18 ) ) {
V_16 = F_81 ( V_2 , F_125 , V_321 . V_323 ,
V_196 ) ;
if ( V_16 )
break;
}
V_16 = F_81 ( V_2 , F_126 , V_321 . V_323 ,
V_196 ) ;
break;
case V_326 :
V_16 = F_81 ( V_2 , F_124 , V_321 . V_323 ,
V_196 ) ;
break;
case V_327 :
V_16 = F_81 ( V_2 , F_127 , V_321 . V_323 ,
V_196 ) ;
break;
case V_328 :
V_2 -> V_329 = ( ( T_13 ) V_321 . V_323 ) &
( V_330 | V_331 ) ;
break;
case V_332 :
V_2 -> V_333 = ( T_13 ) V_321 . V_323 ;
break;
case V_334 :
V_2 -> V_335 = * ( ( T_13 * ) & V_321 . V_323 + 1 ) ;
V_2 -> V_336 = * ( ( T_13 * ) & V_321 . V_323 + 0 ) ;
break;
case V_337 :
V_2 -> V_338 = * ( ( T_13 * ) & V_321 . V_323 + 1 ) ;
V_2 -> V_339 = * ( ( T_13 * ) & V_321 . V_323 + 0 ) ;
break;
default:
V_16 = - V_21 ;
break;
}
V_271:
F_159 ( V_2 ) ;
return V_16 ;
}
int F_178 ( void T_2 * V_263 )
{
struct V_1 * V_2 ;
struct V_340 * V_341 ;
struct V_320 * V_321 ;
int V_61 = 0 , V_342 , V_16 ;
T_13 V_343 ;
if ( F_179 ( V_343 , ( T_13 T_2 * ) V_263 ) )
return - V_20 ;
if ( ! V_343 || V_343 > ( V_344 * 2 ) / sizeof( * V_321 ) )
return - V_21 ;
V_342 = sizeof( * V_341 ) + V_343 * sizeof( * V_321 ) ;
V_341 = F_147 ( V_342 , V_275 ) ;
if ( ! V_341 )
return - V_276 ;
V_321 = V_341 -> V_345 ;
F_129 ( & V_226 ) ;
F_26 (hdev, &hci_dev_list, list) {
if ( F_166 ( V_298 , & V_2 -> V_11 ) )
F_167 ( & V_2 -> V_299 ) ;
if ( ! F_4 ( V_346 , & V_2 -> V_11 ) )
F_83 ( V_347 , & V_2 -> V_11 ) ;
( V_321 + V_61 ) -> V_267 = V_2 -> V_227 ;
( V_321 + V_61 ) -> V_323 = V_2 -> V_18 ;
if ( ++ V_61 >= V_343 )
break;
}
F_131 ( & V_226 ) ;
V_341 -> V_343 = V_61 ;
V_342 = sizeof( * V_341 ) + V_61 * sizeof( * V_321 ) ;
V_16 = F_158 ( V_263 , V_341 , V_342 ) ;
F_138 ( V_341 ) ;
return V_16 ? - V_20 : 0 ;
}
int F_180 ( void T_2 * V_263 )
{
struct V_1 * V_2 ;
struct V_348 V_349 ;
int V_16 = 0 ;
if ( F_8 ( & V_349 , V_263 , sizeof( V_349 ) ) )
return - V_20 ;
V_2 = F_128 ( V_349 . V_267 ) ;
if ( ! V_2 )
return - V_268 ;
if ( F_166 ( V_298 , & V_2 -> V_11 ) )
F_171 ( & V_2 -> V_299 ) ;
if ( ! F_4 ( V_346 , & V_2 -> V_11 ) )
F_83 ( V_347 , & V_2 -> V_11 ) ;
strcpy ( V_349 . V_86 , V_2 -> V_86 ) ;
V_349 . V_40 = V_2 -> V_40 ;
V_349 . type = ( V_2 -> V_350 & 0x0f ) | ( ( V_2 -> V_131 & 0x03 ) << 4 ) ;
V_349 . V_18 = V_2 -> V_18 ;
V_349 . V_333 = V_2 -> V_333 ;
if ( F_91 ( V_2 ) ) {
V_349 . V_335 = V_2 -> V_335 ;
V_349 . V_336 = V_2 -> V_336 ;
V_349 . V_338 = V_2 -> V_338 ;
V_349 . V_339 = V_2 -> V_339 ;
} else {
V_349 . V_335 = V_2 -> V_351 ;
V_349 . V_336 = V_2 -> V_352 ;
V_349 . V_338 = 0 ;
V_349 . V_339 = 0 ;
}
V_349 . V_176 = V_2 -> V_176 ;
V_349 . V_329 = V_2 -> V_329 ;
memcpy ( & V_349 . V_317 , & V_2 -> V_317 , sizeof( V_349 . V_317 ) ) ;
memcpy ( & V_349 . V_34 , & V_2 -> V_34 , sizeof( V_349 . V_34 ) ) ;
if ( F_158 ( V_263 , & V_349 , sizeof( V_349 ) ) )
V_16 = - V_20 ;
F_159 ( V_2 ) ;
return V_16 ;
}
static int F_181 ( void * V_26 , bool V_353 )
{
struct V_1 * V_2 = V_26 ;
F_62 ( L_53 , V_2 , V_2 -> V_86 , V_353 ) ;
if ( F_4 ( V_269 , & V_2 -> V_11 ) )
return - V_270 ;
if ( V_353 ) {
F_83 ( V_278 , & V_2 -> V_11 ) ;
if ( ! F_4 ( V_197 , & V_2 -> V_11 ) )
F_169 ( V_2 ) ;
} else {
F_103 ( V_278 , & V_2 -> V_11 ) ;
}
return 0 ;
}
static void F_182 ( struct V_354 * V_355 )
{
struct V_1 * V_2 = F_183 ( V_355 , struct V_1 , V_356 ) ;
int V_16 ;
F_62 ( L_17 , V_2 -> V_86 ) ;
V_16 = F_160 ( V_2 ) ;
if ( V_16 < 0 ) {
F_184 ( V_2 , V_16 ) ;
return;
}
if ( F_4 ( V_278 , & V_2 -> V_11 ) ||
( V_2 -> V_131 == V_132 &&
! F_118 ( & V_2 -> V_40 , V_190 ) &&
! F_118 ( & V_2 -> V_76 , V_190 ) ) ) {
F_103 ( V_298 , & V_2 -> V_11 ) ;
F_169 ( V_2 ) ;
} else if ( F_4 ( V_298 , & V_2 -> V_11 ) ) {
F_185 ( V_2 -> V_300 , & V_2 -> V_299 ,
V_357 ) ;
}
if ( F_166 ( V_197 , & V_2 -> V_11 ) )
F_186 ( V_2 ) ;
}
static void F_187 ( struct V_354 * V_355 )
{
struct V_1 * V_2 = F_183 ( V_355 , struct V_1 ,
V_299 . V_355 ) ;
F_62 ( L_17 , V_2 -> V_86 ) ;
F_169 ( V_2 ) ;
}
static void F_188 ( struct V_354 * V_355 )
{
struct V_1 * V_2 ;
V_2 = F_183 ( V_355 , struct V_1 , V_303 . V_355 ) ;
F_62 ( L_17 , V_2 -> V_86 ) ;
F_189 ( V_2 ) ;
}
int F_190 ( struct V_1 * V_2 )
{
struct V_42 * V_43 , * V_358 ;
F_136 (uuid, tmp, &hdev->uuids, list) {
F_137 ( & V_43 -> V_64 ) ;
F_138 ( V_43 ) ;
}
return 0 ;
}
int F_191 ( struct V_1 * V_2 )
{
struct V_60 * V_31 , * V_61 ;
F_34 (p, n, &hdev->link_keys) {
struct V_62 * V_63 ;
V_63 = F_35 ( V_31 , struct V_62 , V_64 ) ;
F_137 ( V_31 ) ;
F_138 ( V_63 ) ;
}
return 0 ;
}
int F_192 ( struct V_1 * V_2 )
{
struct V_78 * V_359 , * V_358 ;
F_136 (k, tmp, &hdev->long_term_keys, list) {
F_137 ( & V_359 -> V_64 ) ;
F_138 ( V_359 ) ;
}
return 0 ;
}
struct V_62 * F_193 ( struct V_1 * V_2 , T_12 * V_40 )
{
struct V_62 * V_359 ;
F_26 (k, &hdev->link_keys, list)
if ( F_118 ( V_40 , & V_359 -> V_40 ) == 0 )
return V_359 ;
return NULL ;
}
static bool F_194 ( struct V_1 * V_2 , struct V_360 * V_361 ,
T_5 V_362 , T_5 V_363 )
{
if ( V_362 < 0x03 )
return true ;
if ( V_362 == V_364 )
return false ;
if ( V_362 == V_365 && V_363 == 0xff )
return false ;
if ( ! V_361 )
return true ;
if ( V_361 -> V_366 > 0x01 && V_361 -> V_367 > 0x01 )
return true ;
if ( V_361 -> V_366 == 0x02 || V_361 -> V_366 == 0x03 )
return true ;
if ( V_361 -> V_367 == 0x02 || V_361 -> V_367 == 0x03 )
return true ;
return false ;
}
struct V_78 * F_195 ( struct V_1 * V_2 , T_11 V_82 , T_5 rand [ 8 ] )
{
struct V_78 * V_359 ;
F_26 (k, &hdev->long_term_keys, list) {
if ( V_359 -> V_82 != V_82 ||
memcmp ( rand , V_359 -> rand , sizeof( V_359 -> rand ) ) )
continue;
return V_359 ;
}
return NULL ;
}
struct V_78 * F_196 ( struct V_1 * V_2 , T_12 * V_40 ,
T_5 V_368 )
{
struct V_78 * V_359 ;
F_26 (k, &hdev->long_term_keys, list)
if ( V_368 == V_359 -> V_41 &&
F_118 ( V_40 , & V_359 -> V_40 ) == 0 )
return V_359 ;
return NULL ;
}
int F_197 ( struct V_1 * V_2 , struct V_360 * V_361 , int V_369 ,
T_12 * V_40 , T_5 * V_45 , T_5 type , T_5 V_66 )
{
struct V_62 * V_63 , * V_370 ;
T_5 V_363 ;
bool V_371 ;
V_370 = F_193 ( V_2 , V_40 ) ;
if ( V_370 ) {
V_363 = V_370 -> type ;
V_63 = V_370 ;
} else {
V_363 = V_361 ? V_361 -> V_362 : 0xff ;
V_63 = F_147 ( sizeof( * V_63 ) , V_246 ) ;
if ( ! V_63 )
return - V_276 ;
F_144 ( & V_63 -> V_64 , & V_2 -> V_372 ) ;
}
F_62 ( L_54 , V_2 -> V_86 , V_40 , type ) ;
if ( type == V_365 &&
( ! V_361 || V_361 -> V_367 == 0xff ) && V_363 == 0xff ) {
type = V_373 ;
if ( V_361 )
V_361 -> V_362 = type ;
}
F_117 ( & V_63 -> V_40 , V_40 ) ;
memcpy ( V_63 -> V_45 , V_45 , V_65 ) ;
V_63 -> V_66 = V_66 ;
if ( type == V_365 )
V_63 -> type = V_363 ;
else
V_63 -> type = type ;
if ( ! V_369 )
return 0 ;
V_371 = F_194 ( V_2 , V_361 , type , V_363 ) ;
F_198 ( V_2 , V_63 , V_371 ) ;
if ( V_361 )
V_361 -> V_374 = ! V_371 ;
return 0 ;
}
int F_199 ( struct V_1 * V_2 , T_12 * V_40 , T_5 V_368 , T_5 type ,
int V_369 , T_5 V_80 , T_5 V_375 [ 16 ] , T_5 V_81 , T_11
V_82 , T_5 rand [ 8 ] )
{
struct V_78 * V_63 , * V_370 ;
if ( ! ( type & V_376 ) && ! ( type & V_377 ) )
return 0 ;
V_370 = F_196 ( V_2 , V_40 , V_368 ) ;
if ( V_370 )
V_63 = V_370 ;
else {
V_63 = F_147 ( sizeof( * V_63 ) , V_246 ) ;
if ( ! V_63 )
return - V_276 ;
F_144 ( & V_63 -> V_64 , & V_2 -> V_378 ) ;
}
F_117 ( & V_63 -> V_40 , V_40 ) ;
V_63 -> V_41 = V_368 ;
memcpy ( V_63 -> V_45 , V_375 , sizeof( V_63 -> V_45 ) ) ;
V_63 -> V_80 = V_80 ;
V_63 -> V_82 = V_82 ;
V_63 -> V_81 = V_81 ;
V_63 -> type = type ;
memcpy ( V_63 -> rand , rand , sizeof( V_63 -> rand ) ) ;
if ( ! V_369 )
return 0 ;
if ( type & V_377 )
F_200 ( V_2 , V_63 , 1 ) ;
return 0 ;
}
int F_201 ( struct V_1 * V_2 , T_12 * V_40 )
{
struct V_62 * V_63 ;
V_63 = F_193 ( V_2 , V_40 ) ;
if ( ! V_63 )
return - V_379 ;
F_62 ( L_55 , V_2 -> V_86 , V_40 ) ;
F_137 ( & V_63 -> V_64 ) ;
F_138 ( V_63 ) ;
return 0 ;
}
int F_202 ( struct V_1 * V_2 , T_12 * V_40 )
{
struct V_78 * V_359 , * V_358 ;
F_136 (k, tmp, &hdev->long_term_keys, list) {
if ( F_118 ( V_40 , & V_359 -> V_40 ) )
continue;
F_62 ( L_55 , V_2 -> V_86 , V_40 ) ;
F_137 ( & V_359 -> V_64 ) ;
F_138 ( V_359 ) ;
}
return 0 ;
}
static void F_203 ( unsigned long V_263 )
{
struct V_1 * V_2 = ( void * ) V_263 ;
if ( V_2 -> V_295 ) {
struct V_380 * V_381 = ( void * ) V_2 -> V_295 -> V_26 ;
T_8 V_93 = F_31 ( V_381 -> V_93 ) ;
F_67 ( L_56 , V_2 -> V_86 , V_93 ) ;
} else {
F_67 ( L_57 , V_2 -> V_86 ) ;
}
F_161 ( & V_2 -> V_283 , 1 ) ;
F_204 ( V_2 -> V_382 , & V_2 -> V_290 ) ;
}
struct V_383 * F_205 ( struct V_1 * V_2 ,
T_12 * V_40 )
{
struct V_383 * V_26 ;
F_26 (data, &hdev->remote_oob_data, list)
if ( F_118 ( V_40 , & V_26 -> V_40 ) == 0 )
return V_26 ;
return NULL ;
}
int F_146 ( struct V_1 * V_2 , T_12 * V_40 )
{
struct V_383 * V_26 ;
V_26 = F_205 ( V_2 , V_40 ) ;
if ( ! V_26 )
return - V_379 ;
F_62 ( L_55 , V_2 -> V_86 , V_40 ) ;
F_137 ( & V_26 -> V_64 ) ;
F_138 ( V_26 ) ;
return 0 ;
}
int F_206 ( struct V_1 * V_2 )
{
struct V_383 * V_26 , * V_61 ;
F_136 (data, n, &hdev->remote_oob_data, list) {
F_137 ( & V_26 -> V_64 ) ;
F_138 ( V_26 ) ;
}
return 0 ;
}
int F_207 ( struct V_1 * V_2 , T_12 * V_40 , T_5 * V_384 ,
T_5 * V_385 )
{
struct V_383 * V_26 ;
V_26 = F_205 ( V_2 , V_40 ) ;
if ( ! V_26 ) {
V_26 = F_157 ( sizeof( * V_26 ) , V_246 ) ;
if ( ! V_26 )
return - V_276 ;
F_117 ( & V_26 -> V_40 , V_40 ) ;
F_144 ( & V_26 -> V_64 , & V_2 -> V_386 ) ;
}
memcpy ( V_26 -> V_384 , V_384 , sizeof( V_26 -> V_384 ) ) ;
memcpy ( V_26 -> V_385 , V_385 , sizeof( V_26 -> V_385 ) ) ;
F_62 ( L_58 , V_2 -> V_86 , V_40 ) ;
return 0 ;
}
struct V_38 * F_208 ( struct V_1 * V_2 ,
T_12 * V_40 , T_5 type )
{
struct V_38 * V_39 ;
F_26 (b, &hdev->blacklist, list) {
if ( ! F_118 ( & V_39 -> V_40 , V_40 ) && V_39 -> V_41 == type )
return V_39 ;
}
return NULL ;
}
int F_209 ( struct V_1 * V_2 )
{
struct V_60 * V_31 , * V_61 ;
F_34 (p, n, &hdev->blacklist) {
struct V_38 * V_39 = F_35 ( V_31 , struct V_38 , V_64 ) ;
F_137 ( V_31 ) ;
F_138 ( V_39 ) ;
}
return 0 ;
}
int F_210 ( struct V_1 * V_2 , T_12 * V_40 , T_5 type )
{
struct V_38 * V_387 ;
if ( ! F_118 ( V_40 , V_190 ) )
return - V_388 ;
if ( F_208 ( V_2 , V_40 , type ) )
return - V_389 ;
V_387 = F_147 ( sizeof( struct V_38 ) , V_275 ) ;
if ( ! V_387 )
return - V_276 ;
F_117 ( & V_387 -> V_40 , V_40 ) ;
V_387 -> V_41 = type ;
F_144 ( & V_387 -> V_64 , & V_2 -> V_390 ) ;
return F_211 ( V_2 , V_40 , type ) ;
}
int F_212 ( struct V_1 * V_2 , T_12 * V_40 , T_5 type )
{
struct V_38 * V_387 ;
if ( ! F_118 ( V_40 , V_190 ) )
return F_209 ( V_2 ) ;
V_387 = F_208 ( V_2 , V_40 , type ) ;
if ( ! V_387 )
return - V_379 ;
F_137 ( & V_387 -> V_64 ) ;
F_138 ( V_387 ) ;
return F_213 ( V_2 , V_40 , type ) ;
}
static void F_214 ( struct V_1 * V_2 , T_5 V_391 )
{
if ( V_391 ) {
F_67 ( L_59 , V_391 ) ;
F_19 ( V_2 ) ;
F_133 ( V_2 , V_232 ) ;
F_22 ( V_2 ) ;
return;
}
}
static void F_215 ( struct V_1 * V_2 , T_5 V_391 )
{
T_5 V_258 [ 3 ] = { 0x33 , 0x8b , 0x9e } ;
struct V_110 V_111 ;
struct V_256 V_166 ;
int V_16 ;
if ( V_391 ) {
F_67 ( L_60 , V_391 ) ;
return;
}
switch ( V_2 -> V_48 . type ) {
case V_392 :
F_19 ( V_2 ) ;
F_133 ( V_2 , V_232 ) ;
F_22 ( V_2 ) ;
break;
case V_393 :
F_71 ( & V_111 , V_2 ) ;
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
memcpy ( & V_166 . V_258 , V_258 , sizeof( V_166 . V_258 ) ) ;
V_166 . V_259 = V_394 ;
F_84 ( & V_111 , V_261 , sizeof( V_166 ) , & V_166 ) ;
F_19 ( V_2 ) ;
F_135 ( V_2 ) ;
V_16 = F_73 ( & V_111 , F_214 ) ;
if ( V_16 ) {
F_67 ( L_61 , V_16 ) ;
F_133 ( V_2 , V_232 ) ;
}
F_22 ( V_2 ) ;
break;
}
}
static void F_216 ( struct V_354 * V_355 )
{
struct V_1 * V_2 = F_183 ( V_355 , struct V_1 ,
V_308 . V_355 ) ;
struct V_395 V_166 ;
struct V_110 V_111 ;
int V_16 ;
F_62 ( L_17 , V_2 -> V_86 ) ;
F_71 ( & V_111 , V_2 ) ;
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
V_166 . V_15 = V_396 ;
F_84 ( & V_111 , V_397 , sizeof( V_166 ) , & V_166 ) ;
V_16 = F_73 ( & V_111 , F_215 ) ;
if ( V_16 )
F_67 ( L_62 , V_16 ) ;
}
struct V_1 * F_217 ( void )
{
struct V_1 * V_2 ;
V_2 = F_147 ( sizeof( struct V_1 ) , V_275 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_333 = ( V_398 | V_399 | V_400 ) ;
V_2 -> V_401 = ( V_402 ) ;
V_2 -> V_329 = ( V_331 ) ;
V_2 -> V_403 = 0x01 ;
V_2 -> V_404 = 0x03 ;
V_2 -> V_405 = V_406 ;
V_2 -> V_407 = V_406 ;
V_2 -> V_74 = 800 ;
V_2 -> V_75 = 80 ;
V_2 -> V_408 = 0x0060 ;
V_2 -> V_409 = 0x0030 ;
V_2 -> V_84 = 0x0028 ;
V_2 -> V_83 = 0x0038 ;
F_218 ( & V_2 -> V_410 ) ;
F_218 ( & V_2 -> V_411 ) ;
F_139 ( & V_2 -> V_412 ) ;
F_139 ( & V_2 -> V_390 ) ;
F_139 ( & V_2 -> V_413 ) ;
F_139 ( & V_2 -> V_372 ) ;
F_139 ( & V_2 -> V_378 ) ;
F_139 ( & V_2 -> V_386 ) ;
F_139 ( & V_2 -> V_414 . V_64 ) ;
F_219 ( & V_2 -> V_291 , V_415 ) ;
F_219 ( & V_2 -> V_290 , V_416 ) ;
F_219 ( & V_2 -> V_289 , V_417 ) ;
F_219 ( & V_2 -> V_356 , F_182 ) ;
F_220 ( & V_2 -> V_299 , F_187 ) ;
F_220 ( & V_2 -> V_303 , F_188 ) ;
F_220 ( & V_2 -> V_308 , F_216 ) ;
F_221 ( & V_2 -> V_293 ) ;
F_221 ( & V_2 -> V_292 ) ;
F_221 ( & V_2 -> V_310 ) ;
F_222 ( & V_2 -> V_91 ) ;
F_223 ( & V_2 -> V_301 , F_203 , ( unsigned long ) V_2 ) ;
F_224 ( V_2 ) ;
F_225 ( V_2 ) ;
return V_2 ;
}
void F_226 ( struct V_1 * V_2 )
{
F_227 ( & V_2 -> V_297 ) ;
}
int F_228 ( struct V_1 * V_2 )
{
int V_227 , error ;
if ( ! V_2 -> V_281 || ! V_2 -> V_296 )
return - V_21 ;
switch ( V_2 -> V_131 ) {
case V_132 :
V_227 = F_229 ( & V_418 , 0 , 0 , V_275 ) ;
break;
case V_133 :
V_227 = F_229 ( & V_418 , 1 , 0 , V_275 ) ;
break;
default:
return - V_21 ;
}
if ( V_227 < 0 )
return V_227 ;
sprintf ( V_2 -> V_86 , L_63 , V_227 ) ;
V_2 -> V_227 = V_227 ;
F_62 ( L_64 , V_2 , V_2 -> V_86 , V_2 -> V_350 ) ;
V_2 -> V_382 = F_230 ( L_17 , V_419 | V_420 |
V_421 , 1 , V_2 -> V_86 ) ;
if ( ! V_2 -> V_382 ) {
error = - V_276 ;
goto V_16;
}
V_2 -> V_300 = F_230 ( L_17 , V_419 | V_420 |
V_421 , 1 , V_2 -> V_86 ) ;
if ( ! V_2 -> V_300 ) {
F_231 ( V_2 -> V_382 ) ;
error = - V_276 ;
goto V_16;
}
if ( ! F_232 ( V_422 ) )
V_2 -> V_198 = F_233 ( V_2 -> V_86 , V_422 ) ;
F_234 ( & V_2 -> V_297 , L_17 , V_2 -> V_86 ) ;
error = F_235 ( & V_2 -> V_297 ) ;
if ( error < 0 )
goto V_423;
V_2 -> V_424 = F_236 ( V_2 -> V_86 , & V_2 -> V_297 ,
V_425 , & V_426 ,
V_2 ) ;
if ( V_2 -> V_424 ) {
if ( F_237 ( V_2 -> V_424 ) < 0 ) {
F_238 ( V_2 -> V_424 ) ;
V_2 -> V_424 = NULL ;
}
}
if ( V_2 -> V_424 && F_239 ( V_2 -> V_424 ) )
F_83 ( V_278 , & V_2 -> V_11 ) ;
F_83 ( V_197 , & V_2 -> V_11 ) ;
F_83 ( V_298 , & V_2 -> V_11 ) ;
if ( V_2 -> V_131 == V_132 ) {
F_83 ( V_162 , & V_2 -> V_11 ) ;
}
F_240 ( & V_226 ) ;
F_144 ( & V_2 -> V_64 , & V_427 ) ;
F_241 ( & V_226 ) ;
F_1 ( V_2 , V_428 ) ;
F_130 ( V_2 ) ;
F_204 ( V_2 -> V_300 , & V_2 -> V_356 ) ;
return V_227 ;
V_423:
F_231 ( V_2 -> V_382 ) ;
F_231 ( V_2 -> V_300 ) ;
V_16:
F_242 ( & V_418 , V_2 -> V_227 ) ;
return error ;
}
void F_243 ( struct V_1 * V_2 )
{
int V_44 , V_227 ;
F_62 ( L_64 , V_2 , V_2 -> V_86 , V_2 -> V_350 ) ;
F_83 ( V_277 , & V_2 -> V_11 ) ;
V_227 = V_2 -> V_227 ;
F_240 ( & V_226 ) ;
F_137 ( & V_2 -> V_64 ) ;
F_241 ( & V_226 ) ;
F_169 ( V_2 ) ;
for ( V_44 = 0 ; V_44 < V_429 ; V_44 ++ )
F_16 ( V_2 -> V_430 [ V_44 ] ) ;
F_244 ( & V_2 -> V_356 ) ;
if ( ! F_4 ( V_284 , & V_2 -> V_18 ) &&
! F_4 ( V_197 , & V_2 -> V_11 ) ) {
F_19 ( V_2 ) ;
F_245 ( V_2 ) ;
F_22 ( V_2 ) ;
}
F_246 ( ! F_247 ( & V_2 -> V_412 ) ) ;
F_1 ( V_2 , V_431 ) ;
if ( V_2 -> V_424 ) {
F_248 ( V_2 -> V_424 ) ;
F_238 ( V_2 -> V_424 ) ;
}
F_249 ( & V_2 -> V_297 ) ;
F_250 ( V_2 -> V_198 ) ;
F_231 ( V_2 -> V_382 ) ;
F_231 ( V_2 -> V_300 ) ;
F_19 ( V_2 ) ;
F_209 ( V_2 ) ;
F_190 ( V_2 ) ;
F_191 ( V_2 ) ;
F_192 ( V_2 ) ;
F_206 ( V_2 ) ;
F_22 ( V_2 ) ;
F_159 ( V_2 ) ;
F_242 ( & V_418 , V_227 ) ;
}
int F_251 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_432 ) ;
return 0 ;
}
int F_252 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_433 ) ;
return 0 ;
}
int F_253 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
if ( ! V_2 || ( ! F_4 ( V_17 , & V_2 -> V_18 )
&& ! F_4 ( V_284 , & V_2 -> V_18 ) ) ) {
F_16 ( V_13 ) ;
return - V_434 ;
}
F_254 ( V_13 ) -> V_435 = 1 ;
F_255 ( V_13 ) ;
F_256 ( & V_2 -> V_293 , V_13 ) ;
F_204 ( V_2 -> V_382 , & V_2 -> V_291 ) ;
return 0 ;
}
static int F_257 ( struct V_1 * V_2 , int type , void * V_26 ,
int V_6 , T_7 V_224 )
{
int V_100 = 0 ;
int V_436 = 0 ;
int V_437 = V_6 ;
struct V_12 * V_13 ;
struct V_438 * V_439 ;
if ( ( type < V_440 || type > V_441 ) ||
V_224 >= V_429 )
return - V_442 ;
V_13 = V_2 -> V_430 [ V_224 ] ;
if ( ! V_13 ) {
switch ( type ) {
case V_440 :
V_100 = V_443 ;
V_436 = V_444 ;
break;
case V_441 :
V_100 = V_445 ;
V_436 = V_102 ;
break;
case V_446 :
V_100 = V_447 ;
V_436 = V_448 ;
break;
}
V_13 = F_258 ( V_100 , V_246 ) ;
if ( ! V_13 )
return - V_276 ;
V_439 = ( void * ) V_13 -> V_449 ;
V_439 -> V_450 = V_436 ;
V_439 -> V_333 = type ;
V_2 -> V_430 [ V_224 ] = V_13 ;
}
while ( V_6 ) {
V_439 = ( void * ) V_13 -> V_449 ;
V_100 = F_259 ( V_451 , V_439 -> V_450 , V_6 ) ;
memcpy ( F_260 ( V_13 , V_100 ) , V_26 , V_100 ) ;
V_6 -= V_100 ;
V_26 += V_100 ;
V_439 -> V_450 -= V_100 ;
V_437 = V_6 ;
switch ( type ) {
case V_441 :
if ( V_13 -> V_100 == V_102 ) {
struct V_96 * V_452 = V_96 ( V_13 ) ;
V_439 -> V_450 = V_452 -> V_105 ;
if ( F_261 ( V_13 ) < V_439 -> V_450 ) {
F_16 ( V_13 ) ;
V_2 -> V_430 [ V_224 ] = NULL ;
return - V_276 ;
}
}
break;
case V_440 :
if ( V_13 -> V_100 == V_444 ) {
struct V_453 * V_452 = V_453 ( V_13 ) ;
V_439 -> V_450 = F_31 ( V_452 -> V_454 ) ;
if ( F_261 ( V_13 ) < V_439 -> V_450 ) {
F_16 ( V_13 ) ;
V_2 -> V_430 [ V_224 ] = NULL ;
return - V_276 ;
}
}
break;
case V_446 :
if ( V_13 -> V_100 == V_448 ) {
struct V_455 * V_452 = V_455 ( V_13 ) ;
V_439 -> V_450 = V_452 -> V_454 ;
if ( F_261 ( V_13 ) < V_439 -> V_450 ) {
F_16 ( V_13 ) ;
V_2 -> V_430 [ V_224 ] = NULL ;
return - V_276 ;
}
}
break;
}
if ( V_439 -> V_450 == 0 ) {
F_254 ( V_13 ) -> V_333 = type ;
F_253 ( V_2 , V_13 ) ;
V_2 -> V_430 [ V_224 ] = NULL ;
return V_437 ;
}
}
return V_437 ;
}
int F_262 ( struct V_1 * V_2 , int type , void * V_26 , int V_6 )
{
int V_456 = 0 ;
if ( type < V_440 || type > V_441 )
return - V_442 ;
while ( V_6 ) {
V_456 = F_257 ( V_2 , type , V_26 , V_6 , type - 1 ) ;
if ( V_456 < 0 )
return V_456 ;
V_26 += ( V_6 - V_456 ) ;
V_6 = V_456 ;
}
return V_456 ;
}
int F_263 ( struct V_1 * V_2 , void * V_26 , int V_6 )
{
int type ;
int V_456 = 0 ;
while ( V_6 ) {
struct V_12 * V_13 = V_2 -> V_430 [ V_457 ] ;
if ( ! V_13 ) {
struct { char type ; } * V_458 ;
V_458 = V_26 ;
type = V_458 -> type ;
V_26 ++ ;
V_6 -- ;
} else
type = F_254 ( V_13 ) -> V_333 ;
V_456 = F_257 ( V_2 , type , V_26 , V_6 ,
V_457 ) ;
if ( V_456 < 0 )
return V_456 ;
V_26 += ( V_6 - V_456 ) ;
V_6 = V_456 ;
}
return V_456 ;
}
int F_264 ( struct V_459 * V_449 )
{
F_62 ( L_65 , V_449 , V_449 -> V_86 ) ;
F_240 ( & V_460 ) ;
F_144 ( & V_449 -> V_64 , & V_461 ) ;
F_241 ( & V_460 ) ;
return 0 ;
}
int F_265 ( struct V_459 * V_449 )
{
F_62 ( L_65 , V_449 , V_449 -> V_86 ) ;
F_240 ( & V_460 ) ;
F_137 ( & V_449 -> V_64 ) ;
F_241 ( & V_460 ) ;
return 0 ;
}
static void F_266 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
F_62 ( L_66 , V_2 -> V_86 , F_254 ( V_13 ) -> V_333 , V_13 -> V_100 ) ;
F_255 ( V_13 ) ;
F_267 ( V_2 , V_13 ) ;
if ( F_268 ( & V_2 -> V_462 ) ) {
F_269 ( V_2 , V_13 ) ;
}
F_270 ( V_13 ) ;
if ( V_2 -> V_463 ( V_2 , V_13 ) < 0 )
F_67 ( L_67 , V_2 -> V_86 ) ;
}
void F_71 ( struct V_110 * V_111 , struct V_1 * V_2 )
{
F_221 ( & V_111 -> V_292 ) ;
V_111 -> V_2 = V_2 ;
V_111 -> V_16 = 0 ;
}
int F_73 ( struct V_110 * V_111 , T_14 V_464 )
{
struct V_1 * V_2 = V_111 -> V_2 ;
struct V_12 * V_13 ;
unsigned long V_18 ;
F_62 ( L_68 , F_271 ( & V_111 -> V_292 ) ) ;
if ( V_111 -> V_16 ) {
F_164 ( & V_111 -> V_292 ) ;
return V_111 -> V_16 ;
}
if ( F_272 ( & V_111 -> V_292 ) )
return - V_99 ;
V_13 = F_273 ( & V_111 -> V_292 ) ;
F_254 ( V_13 ) -> V_111 . V_464 = V_464 ;
F_274 ( & V_2 -> V_292 . V_410 , V_18 ) ;
F_275 ( & V_111 -> V_292 , & V_2 -> V_292 ) ;
F_276 ( & V_2 -> V_292 . V_410 , V_18 ) ;
F_204 ( V_2 -> V_382 , & V_2 -> V_290 ) ;
return 0 ;
}
static struct V_12 * F_277 ( struct V_1 * V_2 , T_8 V_93 ,
T_9 V_105 , const void * V_106 )
{
int V_100 = V_465 + V_105 ;
struct V_380 * V_97 ;
struct V_12 * V_13 ;
V_13 = F_258 ( V_100 , V_246 ) ;
if ( ! V_13 )
return NULL ;
V_97 = (struct V_380 * ) F_260 ( V_13 , V_465 ) ;
V_97 -> V_93 = F_111 ( V_93 ) ;
V_97 -> V_105 = V_105 ;
if ( V_105 )
memcpy ( F_260 ( V_13 , V_105 ) , V_106 , V_105 ) ;
F_62 ( L_69 , V_13 -> V_100 ) ;
F_254 ( V_13 ) -> V_333 = V_466 ;
return V_13 ;
}
int F_278 ( struct V_1 * V_2 , T_13 V_93 , T_10 V_105 ,
const void * V_106 )
{
struct V_12 * V_13 ;
F_62 ( L_70 , V_2 -> V_86 , V_93 , V_105 ) ;
V_13 = F_277 ( V_2 , V_93 , V_105 , V_106 ) ;
if ( ! V_13 ) {
F_67 ( L_71 , V_2 -> V_86 ) ;
return - V_276 ;
}
F_254 ( V_13 ) -> V_111 . V_467 = true ;
F_256 ( & V_2 -> V_292 , V_13 ) ;
F_204 ( V_2 -> V_382 , & V_2 -> V_290 ) ;
return 0 ;
}
void F_72 ( struct V_110 * V_111 , T_8 V_93 , T_9 V_105 ,
const void * V_106 , T_5 V_3 )
{
struct V_1 * V_2 = V_111 -> V_2 ;
struct V_12 * V_13 ;
F_62 ( L_70 , V_2 -> V_86 , V_93 , V_105 ) ;
if ( V_111 -> V_16 )
return;
V_13 = F_277 ( V_2 , V_93 , V_105 , V_106 ) ;
if ( ! V_13 ) {
F_67 ( L_72 ,
V_2 -> V_86 , V_93 ) ;
V_111 -> V_16 = - V_276 ;
return;
}
if ( F_272 ( & V_111 -> V_292 ) )
F_254 ( V_13 ) -> V_111 . V_467 = true ;
F_254 ( V_13 ) -> V_111 . V_3 = V_3 ;
F_256 ( & V_111 -> V_292 , V_13 ) ;
}
void F_84 ( struct V_110 * V_111 , T_8 V_93 , T_9 V_105 ,
const void * V_106 )
{
F_72 ( V_111 , V_93 , V_105 , V_106 , 0 ) ;
}
void * F_279 ( struct V_1 * V_2 , T_13 V_93 )
{
struct V_380 * V_97 ;
if ( ! V_2 -> V_295 )
return NULL ;
V_97 = ( void * ) V_2 -> V_295 -> V_26 ;
if ( V_97 -> V_93 != F_111 ( V_93 ) )
return NULL ;
F_62 ( L_73 , V_2 -> V_86 , V_93 ) ;
return V_2 -> V_295 -> V_26 + V_465 ;
}
static void F_280 ( struct V_12 * V_13 , T_13 V_468 , T_13 V_18 )
{
struct V_453 * V_97 ;
int V_100 = V_13 -> V_100 ;
F_281 ( V_13 , V_444 ) ;
F_282 ( V_13 ) ;
V_97 = (struct V_453 * ) F_283 ( V_13 ) ;
V_97 -> V_468 = F_111 ( F_284 ( V_468 , V_18 ) ) ;
V_97 -> V_454 = F_111 ( V_100 ) ;
}
static void F_285 ( struct V_469 * V_470 , struct V_471 * V_472 ,
struct V_12 * V_13 , T_13 V_18 )
{
struct V_360 * V_361 = V_470 -> V_361 ;
struct V_1 * V_2 = V_361 -> V_2 ;
struct V_12 * V_64 ;
V_13 -> V_100 = F_286 ( V_13 ) ;
V_13 -> V_473 = 0 ;
F_254 ( V_13 ) -> V_333 = V_440 ;
switch ( V_2 -> V_131 ) {
case V_132 :
F_280 ( V_13 , V_361 -> V_468 , V_18 ) ;
break;
case V_133 :
F_280 ( V_13 , V_470 -> V_468 , V_18 ) ;
break;
default:
F_67 ( L_74 , V_2 -> V_86 , V_2 -> V_131 ) ;
return;
}
V_64 = F_287 ( V_13 ) -> V_474 ;
if ( ! V_64 ) {
F_62 ( L_75 , V_2 -> V_86 , V_13 , V_13 -> V_100 ) ;
F_256 ( V_472 , V_13 ) ;
} else {
F_62 ( L_76 , V_2 -> V_86 , V_13 , V_13 -> V_100 ) ;
F_287 ( V_13 ) -> V_474 = NULL ;
F_288 ( & V_472 -> V_410 ) ;
F_289 ( V_472 , V_13 ) ;
V_18 &= ~ V_475 ;
V_18 |= V_476 ;
do {
V_13 = V_64 ; V_64 = V_64 -> V_477 ;
F_254 ( V_13 ) -> V_333 = V_440 ;
F_280 ( V_13 , V_361 -> V_468 , V_18 ) ;
F_62 ( L_76 , V_2 -> V_86 , V_13 , V_13 -> V_100 ) ;
F_289 ( V_472 , V_13 ) ;
} while ( V_64 );
F_290 ( & V_472 -> V_410 ) ;
}
}
void F_291 ( struct V_469 * V_470 , struct V_12 * V_13 , T_13 V_18 )
{
struct V_1 * V_2 = V_470 -> V_361 -> V_2 ;
F_62 ( L_77 , V_2 -> V_86 , V_470 , V_18 ) ;
F_285 ( V_470 , & V_470 -> V_478 , V_13 , V_18 ) ;
F_204 ( V_2 -> V_382 , & V_2 -> V_289 ) ;
}
void F_292 ( struct V_360 * V_361 , struct V_12 * V_13 )
{
struct V_1 * V_2 = V_361 -> V_2 ;
struct V_455 V_97 ;
F_62 ( L_78 , V_2 -> V_86 , V_13 -> V_100 ) ;
V_97 . V_468 = F_111 ( V_361 -> V_468 ) ;
V_97 . V_454 = V_13 -> V_100 ;
F_281 ( V_13 , V_448 ) ;
F_282 ( V_13 ) ;
memcpy ( F_283 ( V_13 ) , & V_97 , V_448 ) ;
F_254 ( V_13 ) -> V_333 = V_446 ;
F_256 ( & V_361 -> V_478 , V_13 ) ;
F_204 ( V_2 -> V_382 , & V_2 -> V_289 ) ;
}
static struct V_360 * F_293 ( struct V_1 * V_2 , T_7 type ,
int * V_479 )
{
struct V_480 * V_452 = & V_2 -> V_414 ;
struct V_360 * V_361 = NULL , * V_481 ;
unsigned int V_250 = 0 , F_7 = ~ 0 ;
F_294 () ;
F_295 (c, &h->list, list) {
if ( V_481 -> type != type || F_272 ( & V_481 -> V_478 ) )
continue;
if ( V_481 -> V_229 != V_482 && V_481 -> V_229 != V_483 )
continue;
V_250 ++ ;
if ( V_481 -> V_381 < F_7 ) {
F_7 = V_481 -> V_381 ;
V_361 = V_481 ;
}
if ( F_296 ( V_2 , type ) == V_250 )
break;
}
F_297 () ;
if ( V_361 ) {
int V_484 , V_485 ;
switch ( V_361 -> type ) {
case V_486 :
V_484 = V_2 -> V_314 ;
break;
case V_487 :
case V_488 :
V_484 = V_2 -> V_315 ;
break;
case V_489 :
V_484 = V_2 -> V_351 ? V_2 -> V_316 : V_2 -> V_314 ;
break;
default:
V_484 = 0 ;
F_67 ( L_79 ) ;
}
V_485 = V_484 / V_250 ;
* V_479 = V_485 ? V_485 : 1 ;
} else
* V_479 = 0 ;
F_62 ( L_80 , V_361 , * V_479 ) ;
return V_361 ;
}
static void F_298 ( struct V_1 * V_2 , T_7 type )
{
struct V_480 * V_452 = & V_2 -> V_414 ;
struct V_360 * V_481 ;
F_67 ( L_81 , V_2 -> V_86 ) ;
F_294 () ;
F_295 (c, &h->list, list) {
if ( V_481 -> type == type && V_481 -> V_381 ) {
F_67 ( L_82 ,
V_2 -> V_86 , & V_481 -> V_490 ) ;
F_299 ( V_481 , V_491 ) ;
}
}
F_297 () ;
}
static struct V_469 * F_300 ( struct V_1 * V_2 , T_7 type ,
int * V_479 )
{
struct V_480 * V_452 = & V_2 -> V_414 ;
struct V_469 * V_470 = NULL ;
unsigned int V_250 = 0 , F_7 = ~ 0 , V_492 = 0 ;
struct V_360 * V_361 ;
int V_484 , V_485 , V_493 = 0 ;
F_62 ( L_17 , V_2 -> V_86 ) ;
F_294 () ;
F_295 (conn, &h->list, list) {
struct V_469 * V_358 ;
if ( V_361 -> type != type )
continue;
if ( V_361 -> V_229 != V_482 && V_361 -> V_229 != V_483 )
continue;
V_493 ++ ;
F_295 (tmp, &conn->chan_list, list) {
struct V_12 * V_13 ;
if ( F_272 ( & V_358 -> V_478 ) )
continue;
V_13 = F_301 ( & V_358 -> V_478 ) ;
if ( V_13 -> V_494 < V_492 )
continue;
if ( V_13 -> V_494 > V_492 ) {
V_250 = 0 ;
F_7 = ~ 0 ;
V_492 = V_13 -> V_494 ;
}
V_250 ++ ;
if ( V_361 -> V_381 < F_7 ) {
F_7 = V_361 -> V_381 ;
V_470 = V_358 ;
}
}
if ( F_296 ( V_2 , type ) == V_493 )
break;
}
F_297 () ;
if ( ! V_470 )
return NULL ;
switch ( V_470 -> V_361 -> type ) {
case V_486 :
V_484 = V_2 -> V_314 ;
break;
case V_495 :
V_484 = V_2 -> V_496 ;
break;
case V_487 :
case V_488 :
V_484 = V_2 -> V_315 ;
break;
case V_489 :
V_484 = V_2 -> V_351 ? V_2 -> V_316 : V_2 -> V_314 ;
break;
default:
V_484 = 0 ;
F_67 ( L_79 ) ;
}
V_485 = V_484 / V_250 ;
* V_479 = V_485 ? V_485 : 1 ;
F_62 ( L_83 , V_470 , * V_479 ) ;
return V_470 ;
}
static void F_302 ( struct V_1 * V_2 , T_7 type )
{
struct V_480 * V_452 = & V_2 -> V_414 ;
struct V_360 * V_361 ;
int V_250 = 0 ;
F_62 ( L_17 , V_2 -> V_86 ) ;
F_294 () ;
F_295 (conn, &h->list, list) {
struct V_469 * V_470 ;
if ( V_361 -> type != type )
continue;
if ( V_361 -> V_229 != V_482 && V_361 -> V_229 != V_483 )
continue;
V_250 ++ ;
F_295 (chan, &conn->chan_list, list) {
struct V_12 * V_13 ;
if ( V_470 -> V_381 ) {
V_470 -> V_381 = 0 ;
continue;
}
if ( F_272 ( & V_470 -> V_478 ) )
continue;
V_13 = F_301 ( & V_470 -> V_478 ) ;
if ( V_13 -> V_494 >= V_497 - 1 )
continue;
V_13 -> V_494 = V_497 - 1 ;
F_62 ( L_84 , V_470 , V_13 ,
V_13 -> V_494 ) ;
}
if ( F_296 ( V_2 , type ) == V_250 )
break;
}
F_297 () ;
}
static inline int F_303 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
return F_304 ( V_13 -> V_100 - V_444 , V_2 -> V_498 ) ;
}
static void F_305 ( struct V_1 * V_2 , unsigned int V_484 )
{
if ( ! F_4 ( V_287 , & V_2 -> V_18 ) ) {
if ( ! V_484 && F_306 ( V_249 , V_2 -> V_499 +
V_500 ) )
F_298 ( V_2 , V_486 ) ;
}
}
static void F_307 ( struct V_1 * V_2 )
{
unsigned int V_484 = V_2 -> V_314 ;
struct V_469 * V_470 ;
struct V_12 * V_13 ;
int V_479 ;
F_305 ( V_2 , V_484 ) ;
while ( V_2 -> V_314 &&
( V_470 = F_300 ( V_2 , V_486 , & V_479 ) ) ) {
T_9 V_494 = ( F_301 ( & V_470 -> V_478 ) ) -> V_494 ;
while ( V_479 -- && ( V_13 = F_301 ( & V_470 -> V_478 ) ) ) {
F_62 ( L_85 , V_470 , V_13 ,
V_13 -> V_100 , V_13 -> V_494 ) ;
if ( V_13 -> V_494 < V_494 )
break;
V_13 = F_308 ( & V_470 -> V_478 ) ;
F_309 ( V_470 -> V_361 ,
F_254 ( V_13 ) -> V_501 ) ;
F_266 ( V_2 , V_13 ) ;
V_2 -> V_499 = V_249 ;
V_2 -> V_314 -- ;
V_470 -> V_381 ++ ;
V_470 -> V_361 -> V_381 ++ ;
}
}
if ( V_484 != V_2 -> V_314 )
F_302 ( V_2 , V_486 ) ;
}
static void F_310 ( struct V_1 * V_2 )
{
unsigned int V_484 = V_2 -> V_496 ;
struct V_469 * V_470 ;
struct V_12 * V_13 ;
int V_479 ;
T_5 type ;
F_305 ( V_2 , V_484 ) ;
F_62 ( L_17 , V_2 -> V_86 ) ;
if ( V_2 -> V_131 == V_133 )
type = V_495 ;
else
type = V_486 ;
while ( V_2 -> V_496 > 0 &&
( V_470 = F_300 ( V_2 , type , & V_479 ) ) ) {
T_9 V_494 = ( F_301 ( & V_470 -> V_478 ) ) -> V_494 ;
while ( V_479 > 0 && ( V_13 = F_301 ( & V_470 -> V_478 ) ) ) {
int V_502 ;
F_62 ( L_85 , V_470 , V_13 ,
V_13 -> V_100 , V_13 -> V_494 ) ;
if ( V_13 -> V_494 < V_494 )
break;
V_13 = F_308 ( & V_470 -> V_478 ) ;
V_502 = F_303 ( V_2 , V_13 ) ;
if ( V_502 > V_2 -> V_496 )
return;
F_309 ( V_470 -> V_361 ,
F_254 ( V_13 ) -> V_501 ) ;
F_266 ( V_2 , V_13 ) ;
V_2 -> V_499 = V_249 ;
V_2 -> V_496 -= V_502 ;
V_479 -= V_502 ;
V_470 -> V_381 += V_502 ;
V_470 -> V_361 -> V_381 += V_502 ;
}
}
if ( V_484 != V_2 -> V_496 )
F_302 ( V_2 , type ) ;
}
static void F_311 ( struct V_1 * V_2 )
{
F_62 ( L_17 , V_2 -> V_86 ) ;
if ( ! F_296 ( V_2 , V_486 ) && V_2 -> V_131 == V_132 )
return;
if ( ! F_296 ( V_2 , V_495 ) && V_2 -> V_131 == V_133 )
return;
switch ( V_2 -> V_118 ) {
case V_119 :
F_307 ( V_2 ) ;
break;
case V_123 :
F_310 ( V_2 ) ;
break;
}
}
static void F_312 ( struct V_1 * V_2 )
{
struct V_360 * V_361 ;
struct V_12 * V_13 ;
int V_479 ;
F_62 ( L_17 , V_2 -> V_86 ) ;
if ( ! F_296 ( V_2 , V_487 ) )
return;
while ( V_2 -> V_315 && ( V_361 = F_293 ( V_2 , V_487 , & V_479 ) ) ) {
while ( V_479 -- && ( V_13 = F_308 ( & V_361 -> V_478 ) ) ) {
F_62 ( L_86 , V_13 , V_13 -> V_100 ) ;
F_266 ( V_2 , V_13 ) ;
V_361 -> V_381 ++ ;
if ( V_361 -> V_381 == ~ 0 )
V_361 -> V_381 = 0 ;
}
}
}
static void F_313 ( struct V_1 * V_2 )
{
struct V_360 * V_361 ;
struct V_12 * V_13 ;
int V_479 ;
F_62 ( L_17 , V_2 -> V_86 ) ;
if ( ! F_296 ( V_2 , V_488 ) )
return;
while ( V_2 -> V_315 && ( V_361 = F_293 ( V_2 , V_488 ,
& V_479 ) ) ) {
while ( V_479 -- && ( V_13 = F_308 ( & V_361 -> V_478 ) ) ) {
F_62 ( L_86 , V_13 , V_13 -> V_100 ) ;
F_266 ( V_2 , V_13 ) ;
V_361 -> V_381 ++ ;
if ( V_361 -> V_381 == ~ 0 )
V_361 -> V_381 = 0 ;
}
}
}
static void F_314 ( struct V_1 * V_2 )
{
struct V_469 * V_470 ;
struct V_12 * V_13 ;
int V_479 , V_484 , V_358 ;
F_62 ( L_17 , V_2 -> V_86 ) ;
if ( ! F_296 ( V_2 , V_489 ) )
return;
if ( ! F_4 ( V_287 , & V_2 -> V_18 ) ) {
if ( ! V_2 -> V_316 && V_2 -> V_352 &&
F_306 ( V_249 , V_2 -> V_503 + V_504 * 45 ) )
F_298 ( V_2 , V_489 ) ;
}
V_484 = V_2 -> V_352 ? V_2 -> V_316 : V_2 -> V_314 ;
V_358 = V_484 ;
while ( V_484 && ( V_470 = F_300 ( V_2 , V_489 , & V_479 ) ) ) {
T_9 V_494 = ( F_301 ( & V_470 -> V_478 ) ) -> V_494 ;
while ( V_479 -- && ( V_13 = F_301 ( & V_470 -> V_478 ) ) ) {
F_62 ( L_85 , V_470 , V_13 ,
V_13 -> V_100 , V_13 -> V_494 ) ;
if ( V_13 -> V_494 < V_494 )
break;
V_13 = F_308 ( & V_470 -> V_478 ) ;
F_266 ( V_2 , V_13 ) ;
V_2 -> V_503 = V_249 ;
V_484 -- ;
V_470 -> V_381 ++ ;
V_470 -> V_361 -> V_381 ++ ;
}
}
if ( V_2 -> V_352 )
V_2 -> V_316 = V_484 ;
else
V_2 -> V_314 = V_484 ;
if ( V_484 != V_358 )
F_302 ( V_2 , V_489 ) ;
}
static void V_417 ( struct V_354 * V_355 )
{
struct V_1 * V_2 = F_183 ( V_355 , struct V_1 , V_289 ) ;
struct V_12 * V_13 ;
F_62 ( L_87 , V_2 -> V_86 , V_2 -> V_314 ,
V_2 -> V_315 , V_2 -> V_316 ) ;
if ( ! F_4 ( V_269 , & V_2 -> V_11 ) ) {
F_311 ( V_2 ) ;
F_312 ( V_2 ) ;
F_313 ( V_2 ) ;
F_314 ( V_2 ) ;
}
while ( ( V_13 = F_308 ( & V_2 -> V_310 ) ) )
F_266 ( V_2 , V_13 ) ;
}
static void F_315 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_453 * V_97 = ( void * ) V_13 -> V_26 ;
struct V_360 * V_361 ;
T_13 V_468 , V_18 ;
F_68 ( V_13 , V_444 ) ;
V_468 = F_31 ( V_97 -> V_468 ) ;
V_18 = F_316 ( V_468 ) ;
V_468 = F_317 ( V_468 ) ;
F_62 ( L_88 , V_2 -> V_86 , V_13 -> V_100 ,
V_468 , V_18 ) ;
V_2 -> V_317 . V_505 ++ ;
F_19 ( V_2 ) ;
V_361 = F_318 ( V_2 , V_468 ) ;
F_22 ( V_2 ) ;
if ( V_361 ) {
F_309 ( V_361 , V_506 ) ;
F_319 ( V_361 , V_13 , V_18 ) ;
return;
} else {
F_67 ( L_89 ,
V_2 -> V_86 , V_468 ) ;
}
F_16 ( V_13 ) ;
}
static void F_320 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_455 * V_97 = ( void * ) V_13 -> V_26 ;
struct V_360 * V_361 ;
T_13 V_468 ;
F_68 ( V_13 , V_448 ) ;
V_468 = F_31 ( V_97 -> V_468 ) ;
F_62 ( L_90 , V_2 -> V_86 , V_13 -> V_100 , V_468 ) ;
V_2 -> V_317 . V_507 ++ ;
F_19 ( V_2 ) ;
V_361 = F_318 ( V_2 , V_468 ) ;
F_22 ( V_2 ) ;
if ( V_361 ) {
F_321 ( V_361 , V_13 ) ;
return;
} else {
F_67 ( L_91 ,
V_2 -> V_86 , V_468 ) ;
}
F_16 ( V_13 ) ;
}
static bool F_322 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
V_13 = F_301 ( & V_2 -> V_292 ) ;
if ( ! V_13 )
return true ;
return F_254 ( V_13 ) -> V_111 . V_467 ;
}
static void F_323 ( struct V_1 * V_2 )
{
struct V_380 * V_381 ;
struct V_12 * V_13 ;
T_8 V_93 ;
if ( ! V_2 -> V_295 )
return;
V_381 = ( void * ) V_2 -> V_295 -> V_26 ;
V_93 = F_31 ( V_381 -> V_93 ) ;
if ( V_93 == V_25 )
return;
V_13 = F_324 ( V_2 -> V_295 , V_275 ) ;
if ( ! V_13 )
return;
F_325 ( & V_2 -> V_292 , V_13 ) ;
F_204 ( V_2 -> V_382 , & V_2 -> V_290 ) ;
}
void F_326 ( struct V_1 * V_2 , T_8 V_93 , T_5 V_391 )
{
T_14 V_508 = NULL ;
struct V_12 * V_13 ;
unsigned long V_18 ;
F_62 ( L_92 , V_93 , V_391 ) ;
if ( ! F_279 ( V_2 , V_93 ) ) {
if ( F_4 ( V_284 , & V_2 -> V_18 ) && V_93 == V_25 )
F_323 ( V_2 ) ;
return;
}
if ( ! V_391 && ! F_322 ( V_2 ) )
return;
if ( V_2 -> V_295 ) {
V_508 = F_254 ( V_2 -> V_295 ) -> V_111 . V_464 ;
if ( V_508 ) {
F_254 ( V_2 -> V_295 ) -> V_111 . V_464 = NULL ;
goto V_509;
}
}
F_274 ( & V_2 -> V_292 . V_410 , V_18 ) ;
while ( ( V_13 = F_327 ( & V_2 -> V_292 ) ) ) {
if ( F_254 ( V_13 ) -> V_111 . V_467 ) {
F_328 ( & V_2 -> V_292 , V_13 ) ;
break;
}
V_508 = F_254 ( V_13 ) -> V_111 . V_464 ;
F_16 ( V_13 ) ;
}
F_276 ( & V_2 -> V_292 . V_410 , V_18 ) ;
V_509:
if ( V_508 )
V_508 ( V_2 , V_391 ) ;
}
static void V_415 ( struct V_354 * V_355 )
{
struct V_1 * V_2 = F_183 ( V_355 , struct V_1 , V_291 ) ;
struct V_12 * V_13 ;
F_62 ( L_17 , V_2 -> V_86 ) ;
while ( ( V_13 = F_308 ( & V_2 -> V_293 ) ) ) {
F_267 ( V_2 , V_13 ) ;
if ( F_268 ( & V_2 -> V_462 ) ) {
F_269 ( V_2 , V_13 ) ;
}
if ( F_4 ( V_287 , & V_2 -> V_18 ) ||
F_4 ( V_269 , & V_2 -> V_11 ) ) {
F_16 ( V_13 ) ;
continue;
}
if ( F_4 ( V_284 , & V_2 -> V_18 ) ) {
switch ( F_254 ( V_13 ) -> V_333 ) {
case V_440 :
case V_446 :
F_16 ( V_13 ) ;
continue;
}
}
switch ( F_254 ( V_13 ) -> V_333 ) {
case V_441 :
F_62 ( L_93 , V_2 -> V_86 ) ;
F_329 ( V_2 , V_13 ) ;
break;
case V_440 :
F_62 ( L_94 , V_2 -> V_86 ) ;
F_315 ( V_2 , V_13 ) ;
break;
case V_446 :
F_62 ( L_95 , V_2 -> V_86 ) ;
F_320 ( V_2 , V_13 ) ;
break;
default:
F_16 ( V_13 ) ;
break;
}
}
}
static void V_416 ( struct V_354 * V_355 )
{
struct V_1 * V_2 = F_183 ( V_355 , struct V_1 , V_290 ) ;
struct V_12 * V_13 ;
F_62 ( L_96 , V_2 -> V_86 ,
F_268 ( & V_2 -> V_283 ) , F_271 ( & V_2 -> V_292 ) ) ;
if ( F_268 ( & V_2 -> V_283 ) ) {
V_13 = F_308 ( & V_2 -> V_292 ) ;
if ( ! V_13 )
return;
F_16 ( V_2 -> V_295 ) ;
V_2 -> V_295 = F_324 ( V_13 , V_275 ) ;
if ( V_2 -> V_295 ) {
F_330 ( & V_2 -> V_283 ) ;
F_266 ( V_2 , V_13 ) ;
if ( F_4 ( V_117 , & V_2 -> V_18 ) )
F_331 ( & V_2 -> V_301 ) ;
else
F_332 ( & V_2 -> V_301 ,
V_249 + V_24 ) ;
} else {
F_325 ( & V_2 -> V_292 , V_13 ) ;
F_204 ( V_2 -> V_382 , & V_2 -> V_290 ) ;
}
}
}
