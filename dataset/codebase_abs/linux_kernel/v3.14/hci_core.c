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
static T_1 F_61 ( struct V_4 * V_4 , char T_2 * V_5 ,
T_3 V_6 , T_4 * V_7 )
{
struct V_1 * V_2 = V_4 -> V_8 ;
char V_9 [ 3 ] ;
V_9 [ 0 ] = F_4 ( V_85 , & V_2 -> V_11 ) ? 'Y' : 'N' ;
V_9 [ 1 ] = '\n' ;
V_9 [ 2 ] = '\0' ;
return F_5 ( V_5 , V_6 , V_7 , V_9 , 2 ) ;
}
static T_1 F_62 ( struct V_4 * V_86 , const char T_2 * V_87 ,
T_3 V_6 , T_4 * V_88 )
{
struct V_1 * V_2 = V_86 -> V_8 ;
bool V_15 ;
char V_9 [ 32 ] ;
T_3 V_14 = F_7 ( V_6 , ( sizeof( V_9 ) - 1 ) ) ;
if ( F_8 ( V_9 , V_87 , V_14 ) )
return - V_20 ;
V_9 [ V_14 ] = '\0' ;
if ( F_9 ( V_9 , & V_15 ) < 0 )
return - V_21 ;
if ( V_15 == F_4 ( V_85 , & V_2 -> V_11 ) )
return - V_22 ;
F_17 ( V_85 , & V_2 -> V_11 ) ;
return V_6 ;
}
static void F_63 ( struct V_1 * V_2 , T_5 V_89 )
{
F_64 ( L_11 , V_2 -> V_90 , V_89 ) ;
if ( V_2 -> V_91 == V_92 ) {
V_2 -> V_93 = V_89 ;
V_2 -> V_91 = V_94 ;
F_65 ( & V_2 -> V_95 ) ;
}
}
static void F_66 ( struct V_1 * V_2 , int V_16 )
{
F_64 ( L_12 , V_2 -> V_90 , V_16 ) ;
if ( V_2 -> V_91 == V_92 ) {
V_2 -> V_93 = V_16 ;
V_2 -> V_91 = V_96 ;
F_65 ( & V_2 -> V_95 ) ;
}
}
static struct V_12 * F_67 ( struct V_1 * V_2 , T_8 V_97 ,
T_5 V_3 )
{
struct V_98 * V_99 ;
struct V_100 * V_101 ;
struct V_12 * V_13 ;
F_19 ( V_2 ) ;
V_13 = V_2 -> V_102 ;
V_2 -> V_102 = NULL ;
F_22 ( V_2 ) ;
if ( ! V_13 )
return F_68 ( - V_103 ) ;
if ( V_13 -> V_104 < sizeof( * V_101 ) ) {
F_69 ( L_13 ) ;
goto V_105;
}
V_101 = ( void * ) V_13 -> V_26 ;
F_70 ( V_13 , V_106 ) ;
if ( V_3 ) {
if ( V_101 -> V_107 != V_3 )
goto V_105;
return V_13 ;
}
if ( V_101 -> V_107 != V_108 ) {
F_64 ( L_14 , V_101 -> V_107 ) ;
goto V_105;
}
if ( V_13 -> V_104 < sizeof( * V_99 ) ) {
F_69 ( L_15 ) ;
goto V_105;
}
V_99 = ( void * ) V_13 -> V_26 ;
F_70 ( V_13 , sizeof( * V_99 ) ) ;
if ( V_97 == F_31 ( V_99 -> V_97 ) )
return V_13 ;
F_64 ( L_16 , V_97 ,
F_31 ( V_99 -> V_97 ) ) ;
V_105:
F_16 ( V_13 ) ;
return F_68 ( - V_103 ) ;
}
struct V_12 * F_71 ( struct V_1 * V_2 , T_8 V_97 , T_9 V_109 ,
const void * V_110 , T_5 V_3 , T_9 V_111 )
{
F_72 ( V_112 , V_113 ) ;
struct V_114 V_115 ;
int V_16 = 0 ;
F_64 ( L_17 , V_2 -> V_90 ) ;
F_73 ( & V_115 , V_2 ) ;
F_74 ( & V_115 , V_97 , V_109 , V_110 , V_3 ) ;
V_2 -> V_91 = V_92 ;
V_16 = F_75 ( & V_115 , F_63 ) ;
if ( V_16 < 0 )
return F_68 ( V_16 ) ;
F_76 ( & V_2 -> V_95 , & V_112 ) ;
F_77 ( V_116 ) ;
F_78 ( V_111 ) ;
F_79 ( & V_2 -> V_95 , & V_112 ) ;
if ( F_80 ( V_113 ) )
return F_68 ( - V_117 ) ;
switch ( V_2 -> V_91 ) {
case V_94 :
V_16 = - F_15 ( V_2 -> V_93 ) ;
break;
case V_96 :
V_16 = - V_2 -> V_93 ;
break;
default:
V_16 = - V_118 ;
break;
}
V_2 -> V_91 = V_2 -> V_93 = 0 ;
F_64 ( L_18 , V_2 -> V_90 , V_16 ) ;
if ( V_16 < 0 )
return F_68 ( V_16 ) ;
return F_67 ( V_2 , V_97 , V_3 ) ;
}
struct V_12 * F_11 ( struct V_1 * V_2 , T_8 V_97 , T_9 V_109 ,
const void * V_110 , T_9 V_111 )
{
return F_71 ( V_2 , V_97 , V_109 , V_110 , 0 , V_111 ) ;
}
static int F_81 ( struct V_1 * V_2 ,
void (* F_82)( struct V_114 * V_115 ,
unsigned long V_119 ) ,
unsigned long V_119 , T_10 V_111 )
{
struct V_114 V_115 ;
F_72 ( V_112 , V_113 ) ;
int V_16 = 0 ;
F_64 ( L_19 , V_2 -> V_90 ) ;
F_73 ( & V_115 , V_2 ) ;
V_2 -> V_91 = V_92 ;
F_82 ( & V_115 , V_119 ) ;
V_16 = F_75 ( & V_115 , F_63 ) ;
if ( V_16 < 0 ) {
V_2 -> V_91 = 0 ;
if ( V_16 == - V_103 )
return 0 ;
return V_16 ;
}
F_76 ( & V_2 -> V_95 , & V_112 ) ;
F_77 ( V_116 ) ;
F_78 ( V_111 ) ;
F_79 ( & V_2 -> V_95 , & V_112 ) ;
if ( F_80 ( V_113 ) )
return - V_117 ;
switch ( V_2 -> V_91 ) {
case V_94 :
V_16 = - F_15 ( V_2 -> V_93 ) ;
break;
case V_96 :
V_16 = - V_2 -> V_93 ;
break;
default:
V_16 = - V_118 ;
break;
}
V_2 -> V_91 = V_2 -> V_93 = 0 ;
F_64 ( L_18 , V_2 -> V_90 , V_16 ) ;
return V_16 ;
}
static int F_83 ( struct V_1 * V_2 ,
void (* V_115)( struct V_114 * V_115 ,
unsigned long V_119 ) ,
unsigned long V_119 , T_10 V_111 )
{
int V_120 ;
if ( ! F_4 ( V_17 , & V_2 -> V_18 ) )
return - V_19 ;
F_10 ( V_2 ) ;
V_120 = F_81 ( V_2 , V_115 , V_119 , V_111 ) ;
F_12 ( V_2 ) ;
return V_120 ;
}
static void F_84 ( struct V_114 * V_115 , unsigned long V_119 )
{
F_64 ( L_20 , V_115 -> V_2 -> V_90 , V_119 ) ;
F_85 ( V_121 , & V_115 -> V_2 -> V_18 ) ;
F_86 ( V_115 , V_25 , 0 , NULL ) ;
}
static void F_87 ( struct V_114 * V_115 )
{
V_115 -> V_2 -> V_122 = V_123 ;
F_86 ( V_115 , V_124 , 0 , NULL ) ;
F_86 ( V_115 , V_125 , 0 , NULL ) ;
F_86 ( V_115 , V_126 , 0 , NULL ) ;
}
static void F_88 ( struct V_114 * V_115 )
{
V_115 -> V_2 -> V_122 = V_127 ;
F_86 ( V_115 , V_125 , 0 , NULL ) ;
F_86 ( V_115 , V_128 , 0 , NULL ) ;
F_86 ( V_115 , V_124 , 0 , NULL ) ;
F_86 ( V_115 , V_129 , 0 , NULL ) ;
F_86 ( V_115 , V_130 , 0 , NULL ) ;
F_86 ( V_115 , V_131 , 0 , NULL ) ;
F_86 ( V_115 , V_132 , 0 , NULL ) ;
}
static void F_89 ( struct V_114 * V_115 , unsigned long V_119 )
{
struct V_1 * V_2 = V_115 -> V_2 ;
F_64 ( L_20 , V_2 -> V_90 , V_119 ) ;
if ( ! F_4 ( V_133 , & V_2 -> V_134 ) )
F_84 ( V_115 , 0 ) ;
switch ( V_2 -> V_135 ) {
case V_136 :
F_87 ( V_115 ) ;
break;
case V_137 :
F_88 ( V_115 ) ;
break;
default:
F_69 ( L_21 , V_2 -> V_135 ) ;
break;
}
}
static void F_90 ( struct V_114 * V_115 )
{
struct V_1 * V_2 = V_115 -> V_2 ;
T_11 V_110 ;
T_7 V_138 ;
F_86 ( V_115 , V_139 , 0 , NULL ) ;
F_86 ( V_115 , V_140 , 0 , NULL ) ;
F_86 ( V_115 , V_141 , 0 , NULL ) ;
F_86 ( V_115 , V_142 , 0 , NULL ) ;
F_86 ( V_115 , V_143 , 0 , NULL ) ;
F_86 ( V_115 , V_144 , 0 , NULL ) ;
V_138 = V_145 ;
F_86 ( V_115 , V_146 , 1 , & V_138 ) ;
V_110 = F_91 ( 0x7d00 ) ;
F_86 ( V_115 , V_147 , 2 , & V_110 ) ;
if ( V_2 -> V_148 != 31 && V_2 -> V_149 > V_150 ) {
F_86 ( V_115 , V_151 , 0 , NULL ) ;
F_86 ( V_115 , V_152 , 0 , NULL ) ;
}
}
static void F_92 ( struct V_114 * V_115 )
{
struct V_1 * V_2 = V_115 -> V_2 ;
F_86 ( V_115 , V_153 , 0 , NULL ) ;
F_86 ( V_115 , V_154 , 0 , NULL ) ;
F_86 ( V_115 , V_155 , 0 , NULL ) ;
F_86 ( V_115 , V_156 , 0 , NULL ) ;
F_86 ( V_115 , V_157 , 0 , NULL ) ;
if ( ! F_93 ( V_2 ) )
F_85 ( V_158 , & V_2 -> V_11 ) ;
}
static T_5 F_94 ( struct V_1 * V_2 )
{
if ( F_95 ( V_2 ) )
return 0x02 ;
if ( F_96 ( V_2 ) )
return 0x01 ;
if ( V_2 -> V_148 == 11 && V_2 -> V_159 == 0x00 &&
V_2 -> V_160 == 0x0757 )
return 0x01 ;
if ( V_2 -> V_148 == 15 ) {
if ( V_2 -> V_159 == 0x03 && V_2 -> V_160 == 0x6963 )
return 0x01 ;
if ( V_2 -> V_159 == 0x09 && V_2 -> V_160 == 0x6963 )
return 0x01 ;
if ( V_2 -> V_159 == 0x00 && V_2 -> V_160 == 0x6965 )
return 0x01 ;
}
if ( V_2 -> V_148 == 31 && V_2 -> V_159 == 0x2005 &&
V_2 -> V_160 == 0x1805 )
return 0x01 ;
return 0x00 ;
}
static void F_97 ( struct V_114 * V_115 )
{
T_5 V_70 ;
V_70 = F_94 ( V_115 -> V_2 ) ;
F_86 ( V_115 , V_161 , 1 , & V_70 ) ;
}
static void F_98 ( struct V_114 * V_115 )
{
struct V_1 * V_2 = V_115 -> V_2 ;
T_5 V_162 [ 8 ] = { 0xff , 0xff , 0xfb , 0xff , 0x00 , 0x00 , 0x00 , 0x00 } ;
if ( V_2 -> V_149 < V_163 )
return;
if ( F_93 ( V_2 ) ) {
V_162 [ 4 ] |= 0x01 ;
V_162 [ 4 ] |= 0x02 ;
V_162 [ 4 ] |= 0x04 ;
V_162 [ 5 ] |= 0x08 ;
V_162 [ 5 ] |= 0x10 ;
} else {
memset ( V_162 , 0 , sizeof( V_162 ) ) ;
V_162 [ 0 ] |= 0x10 ;
V_162 [ 0 ] |= 0x80 ;
V_162 [ 1 ] |= 0x08 ;
V_162 [ 1 ] |= 0x20 ;
V_162 [ 1 ] |= 0x40 ;
V_162 [ 1 ] |= 0x80 ;
V_162 [ 2 ] |= 0x04 ;
V_162 [ 3 ] |= 0x02 ;
V_162 [ 5 ] |= 0x80 ;
}
if ( F_96 ( V_2 ) )
V_162 [ 4 ] |= 0x02 ;
if ( F_99 ( V_2 ) )
V_162 [ 5 ] |= 0x20 ;
if ( F_100 ( V_2 ) )
V_162 [ 5 ] |= 0x80 ;
if ( F_95 ( V_2 ) )
V_162 [ 5 ] |= 0x40 ;
if ( F_101 ( V_2 ) )
V_162 [ 7 ] |= 0x01 ;
if ( F_102 ( V_2 ) )
V_162 [ 6 ] |= 0x80 ;
if ( F_103 ( V_2 ) ) {
V_162 [ 6 ] |= 0x01 ;
V_162 [ 6 ] |= 0x02 ;
V_162 [ 6 ] |= 0x04 ;
V_162 [ 6 ] |= 0x08 ;
V_162 [ 6 ] |= 0x10 ;
V_162 [ 6 ] |= 0x20 ;
V_162 [ 7 ] |= 0x04 ;
V_162 [ 7 ] |= 0x08 ;
V_162 [ 7 ] |= 0x10 ;
}
if ( F_21 ( V_2 ) )
V_162 [ 7 ] |= 0x20 ;
F_86 ( V_115 , V_164 , sizeof( V_162 ) , V_162 ) ;
if ( F_21 ( V_2 ) ) {
memset ( V_162 , 0 , sizeof( V_162 ) ) ;
V_162 [ 0 ] = 0x1f ;
F_86 ( V_115 , V_165 ,
sizeof( V_162 ) , V_162 ) ;
}
}
static void F_104 ( struct V_114 * V_115 , unsigned long V_119 )
{
struct V_1 * V_2 = V_115 -> V_2 ;
if ( F_93 ( V_2 ) )
F_90 ( V_115 ) ;
else
F_105 ( V_166 , & V_2 -> V_11 ) ;
if ( F_21 ( V_2 ) )
F_92 ( V_115 ) ;
F_98 ( V_115 ) ;
if ( V_2 -> V_148 != 31 && V_2 -> V_149 > V_150 )
F_86 ( V_115 , V_128 , 0 , NULL ) ;
if ( F_103 ( V_2 ) ) {
V_2 -> V_33 = 0x01 ;
if ( F_4 ( V_167 , & V_2 -> V_11 ) ) {
T_5 V_70 = 0x01 ;
F_86 ( V_115 , V_168 ,
sizeof( V_70 ) , & V_70 ) ;
} else {
struct V_169 V_170 ;
memset ( V_2 -> V_171 , 0 , sizeof( V_2 -> V_171 ) ) ;
memset ( & V_170 , 0 , sizeof( V_170 ) ) ;
F_86 ( V_115 , V_172 , sizeof( V_170 ) , & V_170 ) ;
}
}
if ( F_96 ( V_2 ) )
F_97 ( V_115 ) ;
if ( F_106 ( V_2 ) )
F_86 ( V_115 , V_173 , 0 , NULL ) ;
if ( F_107 ( V_2 ) ) {
struct V_174 V_170 ;
V_170 . V_175 = 0x01 ;
F_86 ( V_115 , V_176 ,
sizeof( V_170 ) , & V_170 ) ;
}
if ( F_4 ( V_177 , & V_2 -> V_11 ) ) {
T_5 V_15 = 1 ;
F_86 ( V_115 , V_178 , sizeof( V_15 ) ,
& V_15 ) ;
}
}
static void F_108 ( struct V_114 * V_115 )
{
struct V_1 * V_2 = V_115 -> V_2 ;
struct V_179 V_170 ;
T_8 V_180 = 0 ;
if ( F_109 ( V_2 ) )
V_180 |= V_181 ;
if ( F_110 ( V_2 ) )
V_180 |= V_182 ;
if ( F_111 ( V_2 ) )
V_180 |= V_183 ;
if ( F_112 ( V_2 ) )
V_180 |= V_184 ;
V_170 . V_185 = F_113 ( V_180 ) ;
F_86 ( V_115 , V_186 , sizeof( V_170 ) , & V_170 ) ;
}
static void F_114 ( struct V_114 * V_115 )
{
struct V_1 * V_2 = V_115 -> V_2 ;
struct V_187 V_170 ;
if ( ! F_93 ( V_2 ) )
return;
memset ( & V_170 , 0 , sizeof( V_170 ) ) ;
if ( F_4 ( V_158 , & V_2 -> V_11 ) ) {
V_170 . V_188 = 0x01 ;
V_170 . V_189 = F_115 ( V_2 ) ;
}
if ( V_170 . V_188 != F_116 ( V_2 ) )
F_86 ( V_115 , V_190 , sizeof( V_170 ) ,
& V_170 ) ;
}
static void F_117 ( struct V_114 * V_115 )
{
struct V_1 * V_2 = V_115 -> V_2 ;
T_5 V_162 [ 8 ] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
if ( F_118 ( V_2 ) ) {
V_162 [ 1 ] |= 0x40 ;
V_162 [ 1 ] |= 0x80 ;
V_162 [ 2 ] |= 0x10 ;
V_162 [ 2 ] |= 0x20 ;
}
if ( F_119 ( V_2 ) ) {
V_162 [ 2 ] |= 0x01 ;
V_162 [ 2 ] |= 0x02 ;
V_162 [ 2 ] |= 0x04 ;
V_162 [ 2 ] |= 0x08 ;
}
F_86 ( V_115 , V_191 , sizeof( V_162 ) , V_162 ) ;
}
static void F_120 ( struct V_114 * V_115 , unsigned long V_119 )
{
struct V_1 * V_2 = V_115 -> V_2 ;
T_5 V_31 ;
if ( V_2 -> V_192 [ 6 ] & 0x80 &&
! F_4 ( V_193 , & V_2 -> V_134 ) ) {
struct V_194 V_170 ;
F_121 ( & V_170 . V_40 , V_195 ) ;
V_170 . V_196 = 0x01 ;
F_86 ( V_115 , V_197 ,
sizeof( V_170 ) , & V_170 ) ;
}
if ( V_2 -> V_192 [ 5 ] & 0x10 )
F_108 ( V_115 ) ;
if ( F_21 ( V_2 ) ) {
if ( F_4 ( V_198 , & V_2 -> V_11 ) ) {
if ( F_122 ( & V_2 -> V_40 , V_195 ) )
V_2 -> V_77 = V_199 ;
else
V_2 -> V_77 = V_200 ;
}
F_114 ( V_115 ) ;
}
for ( V_31 = 2 ; V_31 < V_32 && V_31 <= V_2 -> V_33 ; V_31 ++ ) {
struct V_174 V_170 ;
V_170 . V_175 = V_31 ;
F_86 ( V_115 , V_176 ,
sizeof( V_170 ) , & V_170 ) ;
}
}
static void F_123 ( struct V_114 * V_115 , unsigned long V_119 )
{
struct V_1 * V_2 = V_115 -> V_2 ;
if ( V_2 -> V_192 [ 22 ] & 0x04 )
F_117 ( V_115 ) ;
if ( F_124 ( V_2 ) )
F_86 ( V_115 , V_201 , 0 , NULL ) ;
}
static int F_125 ( struct V_1 * V_2 )
{
int V_16 ;
V_16 = F_81 ( V_2 , F_89 , 0 , V_202 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( F_4 ( V_198 , & V_2 -> V_11 ) ) {
F_126 ( L_22 , 0644 , V_2 -> V_203 , V_2 ,
& V_204 ) ;
}
if ( V_2 -> V_135 != V_136 )
return 0 ;
V_16 = F_81 ( V_2 , F_104 , 0 , V_202 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_81 ( V_2 , F_120 , 0 , V_202 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_81 ( V_2 , F_123 , 0 , V_202 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( ! F_4 ( V_198 , & V_2 -> V_11 ) )
return 0 ;
F_126 ( L_23 , 0444 , V_2 -> V_203 , V_2 ,
& V_205 ) ;
F_127 ( L_24 , 0444 , V_2 -> V_203 ,
& V_2 -> V_148 ) ;
F_128 ( L_25 , 0444 , V_2 -> V_203 , & V_2 -> V_149 ) ;
F_127 ( L_26 , 0444 , V_2 -> V_203 , & V_2 -> V_159 ) ;
F_126 ( L_27 , 0444 , V_2 -> V_203 , V_2 ,
& V_206 ) ;
F_126 ( L_28 , 0444 , V_2 -> V_203 , V_2 , & V_207 ) ;
if ( F_93 ( V_2 ) ) {
F_126 ( L_29 , 0444 , V_2 -> V_203 ,
V_2 , & V_208 ) ;
F_126 ( L_30 , 0400 , V_2 -> V_203 ,
V_2 , & V_209 ) ;
F_126 ( L_31 , 0444 , V_2 -> V_203 ,
V_2 , & V_210 ) ;
F_126 ( L_32 , 0444 , V_2 -> V_203 ,
V_2 , & V_211 ) ;
F_126 ( L_33 , 0444 , V_2 -> V_203 ,
V_2 , & V_212 ) ;
}
if ( F_103 ( V_2 ) ) {
F_126 ( L_34 , 0644 , V_2 -> V_203 ,
V_2 , & V_213 ) ;
F_126 ( L_35 , 0644 , V_2 -> V_203 ,
V_2 , & V_214 ) ;
}
if ( F_111 ( V_2 ) ) {
F_126 ( L_36 , 0644 , V_2 -> V_203 ,
V_2 , & V_215 ) ;
F_126 ( L_37 , 0644 , V_2 -> V_203 ,
V_2 , & V_216 ) ;
F_126 ( L_38 , 0644 , V_2 -> V_203 ,
V_2 , & V_217 ) ;
}
if ( F_21 ( V_2 ) ) {
F_128 ( L_39 , 0444 , V_2 -> V_203 ,
& V_2 -> V_218 ) ;
F_126 ( L_40 , 0444 , V_2 -> V_203 ,
V_2 , & V_219 ) ;
F_126 ( L_41 , 0644 , V_2 -> V_203 ,
V_2 , & V_220 ) ;
F_126 ( L_42 , 0400 , V_2 -> V_203 ,
V_2 , & V_221 ) ;
F_126 ( L_43 , 0644 , V_2 -> V_203 ,
V_2 , & V_222 ) ;
F_126 ( L_44 , 0644 , V_2 -> V_203 ,
V_2 , & V_223 ) ;
F_126 ( L_45 , 0644 , V_2 -> V_203 , V_2 ,
& V_224 ) ;
}
return 0 ;
}
static void F_129 ( struct V_114 * V_115 , unsigned long V_119 )
{
T_7 V_225 = V_119 ;
F_64 ( L_46 , V_115 -> V_2 -> V_90 , V_225 ) ;
F_86 ( V_115 , V_226 , 1 , & V_225 ) ;
}
static void F_130 ( struct V_114 * V_115 , unsigned long V_119 )
{
T_7 V_227 = V_119 ;
F_64 ( L_46 , V_115 -> V_2 -> V_90 , V_227 ) ;
F_86 ( V_115 , V_178 , 1 , & V_227 ) ;
}
static void F_131 ( struct V_114 * V_115 , unsigned long V_119 )
{
T_7 V_228 = V_119 ;
F_64 ( L_46 , V_115 -> V_2 -> V_90 , V_228 ) ;
F_86 ( V_115 , V_229 , 1 , & V_228 ) ;
}
static void F_132 ( struct V_114 * V_115 , unsigned long V_119 )
{
T_11 V_185 = F_113 ( V_119 ) ;
F_64 ( L_46 , V_115 -> V_2 -> V_90 , V_185 ) ;
F_86 ( V_115 , V_186 , 2 , & V_185 ) ;
}
struct V_1 * F_133 ( int V_230 )
{
struct V_1 * V_2 = NULL , * V_231 ;
F_64 ( L_47 , V_230 ) ;
if ( V_230 < 0 )
return NULL ;
F_134 ( & V_232 ) ;
F_26 (d, &hci_dev_list, list) {
if ( V_231 -> V_233 == V_230 ) {
V_2 = F_135 ( V_231 ) ;
break;
}
}
F_136 ( & V_232 ) ;
return V_2 ;
}
bool F_137 ( struct V_1 * V_2 )
{
struct V_46 * V_234 = & V_2 -> V_48 ;
switch ( V_234 -> V_235 ) {
case V_236 :
case V_237 :
return true ;
default:
return false ;
}
}
void F_138 ( struct V_1 * V_2 , int V_235 )
{
F_64 ( L_48 , V_2 -> V_90 , V_2 -> V_48 . V_235 , V_235 ) ;
if ( V_2 -> V_48 . V_235 == V_235 )
return;
switch ( V_235 ) {
case V_238 :
if ( V_2 -> V_48 . V_235 != V_239 )
F_139 ( V_2 , 0 ) ;
break;
case V_239 :
break;
case V_236 :
F_139 ( V_2 , 1 ) ;
break;
case V_237 :
break;
case V_240 :
break;
}
V_2 -> V_48 . V_235 = V_235 ;
}
void F_140 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_49 * V_31 , * V_61 ;
F_141 (p, n, &cache->all, all) {
F_142 ( & V_31 -> V_241 ) ;
F_143 ( V_31 ) ;
}
F_144 ( & V_47 -> V_242 ) ;
F_144 ( & V_47 -> V_243 ) ;
}
struct V_49 * F_145 ( struct V_1 * V_2 ,
T_12 * V_40 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_49 * V_50 ;
F_64 ( L_49 , V_47 , V_40 ) ;
F_26 (e, &cache->all, all) {
if ( ! F_122 ( & V_50 -> V_26 . V_40 , V_40 ) )
return V_50 ;
}
return NULL ;
}
struct V_49 * F_146 ( struct V_1 * V_2 ,
T_12 * V_40 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_49 * V_50 ;
F_64 ( L_49 , V_47 , V_40 ) ;
F_26 (e, &cache->unknown, list) {
if ( ! F_122 ( & V_50 -> V_26 . V_40 , V_40 ) )
return V_50 ;
}
return NULL ;
}
struct V_49 * F_147 ( struct V_1 * V_2 ,
T_12 * V_40 ,
int V_235 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_49 * V_50 ;
F_64 ( L_50 , V_47 , V_40 , V_235 ) ;
F_26 (e, &cache->resolve, list) {
if ( ! F_122 ( V_40 , V_195 ) && V_50 -> V_244 == V_235 )
return V_50 ;
if ( ! F_122 ( & V_50 -> V_26 . V_40 , V_40 ) )
return V_50 ;
}
return NULL ;
}
void F_148 ( struct V_1 * V_2 ,
struct V_49 * V_245 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_60 * V_246 = & V_47 -> V_243 ;
struct V_49 * V_31 ;
F_142 ( & V_245 -> V_64 ) ;
F_26 (p, &cache->resolve, list) {
if ( V_31 -> V_244 != V_247 &&
abs ( V_31 -> V_26 . V_57 ) >= abs ( V_245 -> V_26 . V_57 ) )
break;
V_246 = & V_31 -> V_64 ;
}
F_149 ( & V_245 -> V_64 , V_246 ) ;
}
bool F_150 ( struct V_1 * V_2 , struct V_51 * V_26 ,
bool V_248 , bool * V_249 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_49 * V_245 ;
F_64 ( L_49 , V_47 , & V_26 -> V_40 ) ;
F_151 ( V_2 , & V_26 -> V_40 ) ;
if ( V_249 )
* V_249 = V_26 -> V_58 ;
V_245 = F_145 ( V_2 , & V_26 -> V_40 ) ;
if ( V_245 ) {
if ( V_245 -> V_26 . V_58 && V_249 )
* V_249 = true ;
if ( V_245 -> V_244 == V_250 &&
V_26 -> V_57 != V_245 -> V_26 . V_57 ) {
V_245 -> V_26 . V_57 = V_26 -> V_57 ;
F_148 ( V_2 , V_245 ) ;
}
goto V_251;
}
V_245 = F_152 ( sizeof( struct V_49 ) , V_252 ) ;
if ( ! V_245 )
return false ;
F_149 ( & V_245 -> V_241 , & V_47 -> V_241 ) ;
if ( V_248 ) {
V_245 -> V_244 = V_253 ;
} else {
V_245 -> V_244 = V_254 ;
F_149 ( & V_245 -> V_64 , & V_47 -> V_242 ) ;
}
V_251:
if ( V_248 && V_245 -> V_244 != V_253 &&
V_245 -> V_244 != V_247 ) {
V_245 -> V_244 = V_253 ;
F_142 ( & V_245 -> V_64 ) ;
}
memcpy ( & V_245 -> V_26 , V_26 , sizeof( * V_26 ) ) ;
V_245 -> V_59 = V_255 ;
V_47 -> V_59 = V_255 ;
if ( V_245 -> V_244 == V_254 )
return false ;
return true ;
}
static int F_153 ( struct V_1 * V_2 , int V_256 , T_7 * V_9 )
{
struct V_46 * V_47 = & V_2 -> V_48 ;
struct V_257 * V_258 = (struct V_257 * ) V_9 ;
struct V_49 * V_50 ;
int V_259 = 0 ;
F_26 (e, &cache->all, all) {
struct V_51 * V_26 = & V_50 -> V_26 ;
if ( V_259 >= V_256 )
break;
F_121 ( & V_258 -> V_40 , & V_26 -> V_40 ) ;
V_258 -> V_52 = V_26 -> V_52 ;
V_258 -> V_53 = V_26 -> V_53 ;
V_258 -> V_54 = V_26 -> V_54 ;
memcpy ( V_258 -> V_55 , V_26 -> V_55 , 3 ) ;
V_258 -> V_56 = V_26 -> V_56 ;
V_258 ++ ;
V_259 ++ ;
}
F_64 ( L_51 , V_47 , V_259 ) ;
return V_259 ;
}
static void F_154 ( struct V_114 * V_115 , unsigned long V_119 )
{
struct V_260 * V_261 = (struct V_260 * ) V_119 ;
struct V_1 * V_2 = V_115 -> V_2 ;
struct V_262 V_170 ;
F_64 ( L_17 , V_2 -> V_90 ) ;
if ( F_4 ( V_263 , & V_2 -> V_18 ) )
return;
memcpy ( & V_170 . V_264 , & V_261 -> V_264 , 3 ) ;
V_170 . V_265 = V_261 -> V_265 ;
V_170 . V_266 = V_261 -> V_266 ;
F_86 ( V_115 , V_267 , sizeof( V_170 ) , & V_170 ) ;
}
static int F_155 ( void * V_268 )
{
F_156 () ;
return F_80 ( V_113 ) ;
}
int F_157 ( void T_2 * V_269 )
{
T_7 T_2 * V_29 = V_269 ;
struct V_260 V_261 ;
struct V_1 * V_2 ;
int V_16 = 0 , V_270 = 0 , V_271 ;
long V_272 ;
T_7 * V_9 ;
if ( F_8 ( & V_261 , V_29 , sizeof( V_261 ) ) )
return - V_20 ;
V_2 = F_133 ( V_261 . V_273 ) ;
if ( ! V_2 )
return - V_274 ;
if ( F_4 ( V_275 , & V_2 -> V_11 ) ) {
V_16 = - V_276 ;
goto V_277;
}
if ( V_2 -> V_135 != V_136 ) {
V_16 = - V_278 ;
goto V_277;
}
if ( ! F_4 ( V_166 , & V_2 -> V_11 ) ) {
V_16 = - V_278 ;
goto V_277;
}
F_19 ( V_2 ) ;
if ( F_158 ( V_2 ) > V_279 ||
F_159 ( V_2 ) || V_261 . V_18 & V_280 ) {
F_140 ( V_2 ) ;
V_270 = 1 ;
}
F_22 ( V_2 ) ;
V_272 = V_261 . V_265 * F_160 ( 2000 ) ;
if ( V_270 ) {
V_16 = F_83 ( V_2 , F_154 , ( unsigned long ) & V_261 ,
V_272 ) ;
if ( V_16 < 0 )
goto V_277;
if ( F_161 ( & V_2 -> V_18 , V_263 , F_155 ,
V_116 ) )
return - V_117 ;
}
V_271 = ( V_261 . V_266 == 0 ) ? 255 : V_261 . V_266 ;
V_9 = F_162 ( sizeof( struct V_257 ) * V_271 , V_281 ) ;
if ( ! V_9 ) {
V_16 = - V_282 ;
goto V_277;
}
F_19 ( V_2 ) ;
V_261 . V_266 = F_153 ( V_2 , V_271 , V_9 ) ;
F_22 ( V_2 ) ;
F_64 ( L_52 , V_261 . V_266 ) ;
if ( ! F_163 ( V_29 , & V_261 , sizeof( V_261 ) ) ) {
V_29 += sizeof( V_261 ) ;
if ( F_163 ( V_29 , V_9 , sizeof( struct V_257 ) *
V_261 . V_266 ) )
V_16 = - V_20 ;
} else
V_16 = - V_20 ;
F_143 ( V_9 ) ;
V_277:
F_164 ( V_2 ) ;
return V_16 ;
}
static int F_165 ( struct V_1 * V_2 )
{
int V_120 = 0 ;
F_64 ( L_53 , V_2 -> V_90 , V_2 ) ;
F_10 ( V_2 ) ;
if ( F_4 ( V_283 , & V_2 -> V_11 ) ) {
V_120 = - V_274 ;
goto V_277;
}
if ( ! F_4 ( V_198 , & V_2 -> V_11 ) ) {
if ( F_4 ( V_284 , & V_2 -> V_11 ) ) {
V_120 = - V_285 ;
goto V_277;
}
if ( V_2 -> V_135 == V_136 &&
! F_122 ( & V_2 -> V_40 , V_195 ) &&
! F_122 ( & V_2 -> V_76 , V_195 ) ) {
V_120 = - V_286 ;
goto V_277;
}
}
if ( F_4 ( V_17 , & V_2 -> V_18 ) ) {
V_120 = - V_22 ;
goto V_277;
}
if ( V_2 -> V_287 ( V_2 ) ) {
V_120 = - V_288 ;
goto V_277;
}
F_166 ( & V_2 -> V_289 , 1 ) ;
F_85 ( V_290 , & V_2 -> V_18 ) ;
if ( V_2 -> V_291 && F_4 ( V_198 , & V_2 -> V_11 ) )
V_120 = V_2 -> V_291 ( V_2 ) ;
if ( ! V_120 ) {
if ( F_4 ( V_292 , & V_2 -> V_134 ) )
F_85 ( V_293 , & V_2 -> V_18 ) ;
if ( ! F_4 ( V_293 , & V_2 -> V_18 ) &&
! F_4 ( V_275 , & V_2 -> V_11 ) )
V_120 = F_125 ( V_2 ) ;
}
F_105 ( V_290 , & V_2 -> V_18 ) ;
if ( ! V_120 ) {
F_135 ( V_2 ) ;
F_85 ( V_17 , & V_2 -> V_18 ) ;
F_1 ( V_2 , V_294 ) ;
if ( ! F_4 ( V_198 , & V_2 -> V_11 ) &&
! F_4 ( V_275 , & V_2 -> V_11 ) &&
V_2 -> V_135 == V_136 ) {
F_19 ( V_2 ) ;
F_167 ( V_2 , 1 ) ;
F_22 ( V_2 ) ;
}
} else {
F_168 ( & V_2 -> V_295 ) ;
F_168 ( & V_2 -> V_296 ) ;
F_168 ( & V_2 -> V_297 ) ;
F_169 ( & V_2 -> V_298 ) ;
F_169 ( & V_2 -> V_299 ) ;
if ( V_2 -> V_300 )
V_2 -> V_300 ( V_2 ) ;
if ( V_2 -> V_301 ) {
F_16 ( V_2 -> V_301 ) ;
V_2 -> V_301 = NULL ;
}
V_2 -> V_302 ( V_2 ) ;
V_2 -> V_18 = 0 ;
}
V_277:
F_12 ( V_2 ) ;
return V_120 ;
}
int F_170 ( T_13 V_303 )
{
struct V_1 * V_2 ;
int V_16 ;
V_2 = F_133 ( V_303 ) ;
if ( ! V_2 )
return - V_274 ;
if ( F_171 ( V_304 , & V_2 -> V_11 ) )
F_172 ( & V_2 -> V_305 ) ;
F_173 ( V_2 -> V_306 ) ;
V_16 = F_165 ( V_2 ) ;
F_164 ( V_2 ) ;
return V_16 ;
}
static int F_174 ( struct V_1 * V_2 )
{
F_64 ( L_53 , V_2 -> V_90 , V_2 ) ;
F_172 ( & V_2 -> V_305 ) ;
F_66 ( V_2 , V_274 ) ;
F_10 ( V_2 ) ;
if ( ! F_171 ( V_17 , & V_2 -> V_18 ) ) {
F_175 ( & V_2 -> V_307 ) ;
F_12 ( V_2 ) ;
return 0 ;
}
F_168 ( & V_2 -> V_295 ) ;
F_168 ( & V_2 -> V_297 ) ;
if ( V_2 -> V_308 > 0 ) {
F_172 ( & V_2 -> V_309 ) ;
V_2 -> V_308 = 0 ;
F_105 ( V_310 , & V_2 -> V_11 ) ;
F_105 ( V_311 , & V_2 -> V_11 ) ;
}
if ( F_171 ( V_312 , & V_2 -> V_11 ) )
F_172 ( & V_2 -> V_313 ) ;
F_176 ( & V_2 -> V_314 ) ;
F_19 ( V_2 ) ;
F_140 ( V_2 ) ;
F_177 ( V_2 ) ;
F_22 ( V_2 ) ;
F_1 ( V_2 , V_315 ) ;
if ( V_2 -> V_300 )
V_2 -> V_300 ( V_2 ) ;
F_169 ( & V_2 -> V_298 ) ;
F_166 ( & V_2 -> V_289 , 1 ) ;
if ( ! F_4 ( V_293 , & V_2 -> V_18 ) &&
! F_4 ( V_304 , & V_2 -> V_11 ) &&
F_4 ( V_133 , & V_2 -> V_134 ) ) {
F_85 ( V_290 , & V_2 -> V_18 ) ;
F_81 ( V_2 , F_84 , 0 , V_24 ) ;
F_105 ( V_290 , & V_2 -> V_18 ) ;
}
F_168 ( & V_2 -> V_296 ) ;
F_169 ( & V_2 -> V_299 ) ;
F_169 ( & V_2 -> V_298 ) ;
F_169 ( & V_2 -> V_316 ) ;
if ( V_2 -> V_301 ) {
F_175 ( & V_2 -> V_307 ) ;
F_16 ( V_2 -> V_301 ) ;
V_2 -> V_301 = NULL ;
}
F_16 ( V_2 -> V_102 ) ;
V_2 -> V_102 = NULL ;
V_2 -> V_302 ( V_2 ) ;
V_2 -> V_18 = 0 ;
V_2 -> V_11 &= ~ V_317 ;
if ( ! F_171 ( V_304 , & V_2 -> V_11 ) ) {
if ( V_2 -> V_135 == V_136 ) {
F_19 ( V_2 ) ;
F_167 ( V_2 , 0 ) ;
F_22 ( V_2 ) ;
}
}
V_2 -> V_318 = V_319 ;
memset ( V_2 -> V_171 , 0 , sizeof( V_2 -> V_171 ) ) ;
memset ( V_2 -> V_55 , 0 , sizeof( V_2 -> V_55 ) ) ;
F_12 ( V_2 ) ;
F_164 ( V_2 ) ;
return 0 ;
}
int F_178 ( T_13 V_303 )
{
struct V_1 * V_2 ;
int V_16 ;
V_2 = F_133 ( V_303 ) ;
if ( ! V_2 )
return - V_274 ;
if ( F_4 ( V_275 , & V_2 -> V_11 ) ) {
V_16 = - V_276 ;
goto V_277;
}
if ( F_171 ( V_304 , & V_2 -> V_11 ) )
F_172 ( & V_2 -> V_305 ) ;
V_16 = F_174 ( V_2 ) ;
V_277:
F_164 ( V_2 ) ;
return V_16 ;
}
int F_179 ( T_13 V_303 )
{
struct V_1 * V_2 ;
int V_120 = 0 ;
V_2 = F_133 ( V_303 ) ;
if ( ! V_2 )
return - V_274 ;
F_10 ( V_2 ) ;
if ( ! F_4 ( V_17 , & V_2 -> V_18 ) ) {
V_120 = - V_19 ;
goto V_277;
}
if ( F_4 ( V_275 , & V_2 -> V_11 ) ) {
V_120 = - V_276 ;
goto V_277;
}
F_169 ( & V_2 -> V_299 ) ;
F_169 ( & V_2 -> V_298 ) ;
F_19 ( V_2 ) ;
F_140 ( V_2 ) ;
F_177 ( V_2 ) ;
F_22 ( V_2 ) ;
if ( V_2 -> V_300 )
V_2 -> V_300 ( V_2 ) ;
F_166 ( & V_2 -> V_289 , 1 ) ;
V_2 -> V_320 = 0 ; V_2 -> V_321 = 0 ; V_2 -> V_322 = 0 ;
if ( ! F_4 ( V_293 , & V_2 -> V_18 ) )
V_120 = F_81 ( V_2 , F_84 , 0 , V_202 ) ;
V_277:
F_12 ( V_2 ) ;
F_164 ( V_2 ) ;
return V_120 ;
}
int F_180 ( T_13 V_303 )
{
struct V_1 * V_2 ;
int V_120 = 0 ;
V_2 = F_133 ( V_303 ) ;
if ( ! V_2 )
return - V_274 ;
if ( F_4 ( V_275 , & V_2 -> V_11 ) ) {
V_120 = - V_276 ;
goto V_277;
}
memset ( & V_2 -> V_323 , 0 , sizeof( struct V_324 ) ) ;
V_277:
F_164 ( V_2 ) ;
return V_120 ;
}
int F_181 ( unsigned int V_325 , void T_2 * V_269 )
{
struct V_1 * V_2 ;
struct V_326 V_327 ;
int V_16 = 0 ;
if ( F_8 ( & V_327 , V_269 , sizeof( V_327 ) ) )
return - V_20 ;
V_2 = F_133 ( V_327 . V_273 ) ;
if ( ! V_2 )
return - V_274 ;
if ( F_4 ( V_275 , & V_2 -> V_11 ) ) {
V_16 = - V_276 ;
goto V_277;
}
if ( V_2 -> V_135 != V_136 ) {
V_16 = - V_278 ;
goto V_277;
}
if ( ! F_4 ( V_166 , & V_2 -> V_11 ) ) {
V_16 = - V_278 ;
goto V_277;
}
switch ( V_325 ) {
case V_328 :
V_16 = F_83 ( V_2 , F_130 , V_327 . V_329 ,
V_202 ) ;
break;
case V_330 :
if ( ! F_182 ( V_2 ) ) {
V_16 = - V_278 ;
break;
}
if ( ! F_4 ( V_331 , & V_2 -> V_18 ) ) {
V_16 = F_83 ( V_2 , F_130 , V_327 . V_329 ,
V_202 ) ;
if ( V_16 )
break;
}
V_16 = F_83 ( V_2 , F_131 , V_327 . V_329 ,
V_202 ) ;
break;
case V_332 :
V_16 = F_83 ( V_2 , F_129 , V_327 . V_329 ,
V_202 ) ;
break;
case V_333 :
V_16 = F_83 ( V_2 , F_132 , V_327 . V_329 ,
V_202 ) ;
break;
case V_334 :
V_2 -> V_335 = ( ( T_13 ) V_327 . V_329 ) &
( V_336 | V_337 ) ;
break;
case V_338 :
V_2 -> V_339 = ( T_13 ) V_327 . V_329 ;
break;
case V_340 :
V_2 -> V_341 = * ( ( T_13 * ) & V_327 . V_329 + 1 ) ;
V_2 -> V_342 = * ( ( T_13 * ) & V_327 . V_329 + 0 ) ;
break;
case V_343 :
V_2 -> V_344 = * ( ( T_13 * ) & V_327 . V_329 + 1 ) ;
V_2 -> V_345 = * ( ( T_13 * ) & V_327 . V_329 + 0 ) ;
break;
default:
V_16 = - V_21 ;
break;
}
V_277:
F_164 ( V_2 ) ;
return V_16 ;
}
int F_183 ( void T_2 * V_269 )
{
struct V_1 * V_2 ;
struct V_346 * V_347 ;
struct V_326 * V_327 ;
int V_61 = 0 , V_348 , V_16 ;
T_13 V_349 ;
if ( F_184 ( V_349 , ( T_13 T_2 * ) V_269 ) )
return - V_20 ;
if ( ! V_349 || V_349 > ( V_350 * 2 ) / sizeof( * V_327 ) )
return - V_21 ;
V_348 = sizeof( * V_347 ) + V_349 * sizeof( * V_327 ) ;
V_347 = F_152 ( V_348 , V_281 ) ;
if ( ! V_347 )
return - V_282 ;
V_327 = V_347 -> V_351 ;
F_134 ( & V_232 ) ;
F_26 (hdev, &hci_dev_list, list) {
if ( F_171 ( V_304 , & V_2 -> V_11 ) )
F_172 ( & V_2 -> V_305 ) ;
if ( ! F_4 ( V_352 , & V_2 -> V_11 ) )
F_85 ( V_353 , & V_2 -> V_11 ) ;
( V_327 + V_61 ) -> V_273 = V_2 -> V_233 ;
( V_327 + V_61 ) -> V_329 = V_2 -> V_18 ;
if ( ++ V_61 >= V_349 )
break;
}
F_136 ( & V_232 ) ;
V_347 -> V_349 = V_61 ;
V_348 = sizeof( * V_347 ) + V_61 * sizeof( * V_327 ) ;
V_16 = F_163 ( V_269 , V_347 , V_348 ) ;
F_143 ( V_347 ) ;
return V_16 ? - V_20 : 0 ;
}
int F_185 ( void T_2 * V_269 )
{
struct V_1 * V_2 ;
struct V_354 V_355 ;
int V_16 = 0 ;
if ( F_8 ( & V_355 , V_269 , sizeof( V_355 ) ) )
return - V_20 ;
V_2 = F_133 ( V_355 . V_273 ) ;
if ( ! V_2 )
return - V_274 ;
if ( F_171 ( V_304 , & V_2 -> V_11 ) )
F_176 ( & V_2 -> V_305 ) ;
if ( ! F_4 ( V_352 , & V_2 -> V_11 ) )
F_85 ( V_353 , & V_2 -> V_11 ) ;
strcpy ( V_355 . V_90 , V_2 -> V_90 ) ;
V_355 . V_40 = V_2 -> V_40 ;
V_355 . type = ( V_2 -> V_356 & 0x0f ) | ( ( V_2 -> V_135 & 0x03 ) << 4 ) ;
V_355 . V_18 = V_2 -> V_18 ;
V_355 . V_339 = V_2 -> V_339 ;
if ( F_93 ( V_2 ) ) {
V_355 . V_341 = V_2 -> V_341 ;
V_355 . V_342 = V_2 -> V_342 ;
V_355 . V_344 = V_2 -> V_344 ;
V_355 . V_345 = V_2 -> V_345 ;
} else {
V_355 . V_341 = V_2 -> V_357 ;
V_355 . V_342 = V_2 -> V_358 ;
V_355 . V_344 = 0 ;
V_355 . V_345 = 0 ;
}
V_355 . V_180 = V_2 -> V_180 ;
V_355 . V_335 = V_2 -> V_335 ;
memcpy ( & V_355 . V_323 , & V_2 -> V_323 , sizeof( V_355 . V_323 ) ) ;
memcpy ( & V_355 . V_34 , & V_2 -> V_34 , sizeof( V_355 . V_34 ) ) ;
if ( F_163 ( V_269 , & V_355 , sizeof( V_355 ) ) )
V_16 = - V_20 ;
F_164 ( V_2 ) ;
return V_16 ;
}
static int F_186 ( void * V_26 , bool V_359 )
{
struct V_1 * V_2 = V_26 ;
F_64 ( L_54 , V_2 , V_2 -> V_90 , V_359 ) ;
if ( F_4 ( V_275 , & V_2 -> V_11 ) )
return - V_276 ;
if ( V_359 ) {
F_85 ( V_284 , & V_2 -> V_11 ) ;
if ( ! F_4 ( V_198 , & V_2 -> V_11 ) )
F_174 ( V_2 ) ;
} else {
F_105 ( V_284 , & V_2 -> V_11 ) ;
}
return 0 ;
}
static void F_187 ( struct V_360 * V_361 )
{
struct V_1 * V_2 = F_188 ( V_361 , struct V_1 , V_362 ) ;
int V_16 ;
F_64 ( L_17 , V_2 -> V_90 ) ;
V_16 = F_165 ( V_2 ) ;
if ( V_16 < 0 ) {
F_189 ( V_2 , V_16 ) ;
return;
}
if ( F_4 ( V_284 , & V_2 -> V_11 ) ||
( V_2 -> V_135 == V_136 &&
! F_122 ( & V_2 -> V_40 , V_195 ) &&
! F_122 ( & V_2 -> V_76 , V_195 ) ) ) {
F_105 ( V_304 , & V_2 -> V_11 ) ;
F_174 ( V_2 ) ;
} else if ( F_4 ( V_304 , & V_2 -> V_11 ) ) {
F_190 ( V_2 -> V_306 , & V_2 -> V_305 ,
V_363 ) ;
}
if ( F_171 ( V_198 , & V_2 -> V_11 ) )
F_191 ( V_2 ) ;
}
static void F_192 ( struct V_360 * V_361 )
{
struct V_1 * V_2 = F_188 ( V_361 , struct V_1 ,
V_305 . V_361 ) ;
F_64 ( L_17 , V_2 -> V_90 ) ;
F_174 ( V_2 ) ;
}
static void F_193 ( struct V_360 * V_361 )
{
struct V_1 * V_2 ;
V_2 = F_188 ( V_361 , struct V_1 , V_309 . V_361 ) ;
F_64 ( L_17 , V_2 -> V_90 ) ;
F_194 ( V_2 ) ;
}
int F_195 ( struct V_1 * V_2 )
{
struct V_42 * V_43 , * V_364 ;
F_141 (uuid, tmp, &hdev->uuids, list) {
F_142 ( & V_43 -> V_64 ) ;
F_143 ( V_43 ) ;
}
return 0 ;
}
int F_196 ( struct V_1 * V_2 )
{
struct V_60 * V_31 , * V_61 ;
F_34 (p, n, &hdev->link_keys) {
struct V_62 * V_63 ;
V_63 = F_35 ( V_31 , struct V_62 , V_64 ) ;
F_142 ( V_31 ) ;
F_143 ( V_63 ) ;
}
return 0 ;
}
int F_197 ( struct V_1 * V_2 )
{
struct V_78 * V_365 , * V_364 ;
F_141 (k, tmp, &hdev->long_term_keys, list) {
F_142 ( & V_365 -> V_64 ) ;
F_143 ( V_365 ) ;
}
return 0 ;
}
struct V_62 * F_198 ( struct V_1 * V_2 , T_12 * V_40 )
{
struct V_62 * V_365 ;
F_26 (k, &hdev->link_keys, list)
if ( F_122 ( V_40 , & V_365 -> V_40 ) == 0 )
return V_365 ;
return NULL ;
}
static bool F_199 ( struct V_1 * V_2 , struct V_366 * V_367 ,
T_5 V_368 , T_5 V_369 )
{
if ( V_368 < 0x03 )
return true ;
if ( V_368 == V_370 )
return false ;
if ( V_368 == V_371 && V_369 == 0xff )
return false ;
if ( ! V_367 )
return true ;
if ( V_367 -> V_372 > 0x01 && V_367 -> V_373 > 0x01 )
return true ;
if ( V_367 -> V_372 == 0x02 || V_367 -> V_372 == 0x03 )
return true ;
if ( V_367 -> V_373 == 0x02 || V_367 -> V_373 == 0x03 )
return true ;
return false ;
}
struct V_78 * F_200 ( struct V_1 * V_2 , T_11 V_82 , T_5 rand [ 8 ] )
{
struct V_78 * V_365 ;
F_26 (k, &hdev->long_term_keys, list) {
if ( V_365 -> V_82 != V_82 ||
memcmp ( rand , V_365 -> rand , sizeof( V_365 -> rand ) ) )
continue;
return V_365 ;
}
return NULL ;
}
struct V_78 * F_201 ( struct V_1 * V_2 , T_12 * V_40 ,
T_5 V_374 )
{
struct V_78 * V_365 ;
F_26 (k, &hdev->long_term_keys, list)
if ( V_374 == V_365 -> V_41 &&
F_122 ( V_40 , & V_365 -> V_40 ) == 0 )
return V_365 ;
return NULL ;
}
int F_202 ( struct V_1 * V_2 , struct V_366 * V_367 , int V_375 ,
T_12 * V_40 , T_5 * V_45 , T_5 type , T_5 V_66 )
{
struct V_62 * V_63 , * V_376 ;
T_5 V_369 ;
bool V_377 ;
V_376 = F_198 ( V_2 , V_40 ) ;
if ( V_376 ) {
V_369 = V_376 -> type ;
V_63 = V_376 ;
} else {
V_369 = V_367 ? V_367 -> V_368 : 0xff ;
V_63 = F_152 ( sizeof( * V_63 ) , V_252 ) ;
if ( ! V_63 )
return - V_282 ;
F_149 ( & V_63 -> V_64 , & V_2 -> V_378 ) ;
}
F_64 ( L_55 , V_2 -> V_90 , V_40 , type ) ;
if ( type == V_371 &&
( ! V_367 || V_367 -> V_373 == 0xff ) && V_369 == 0xff ) {
type = V_379 ;
if ( V_367 )
V_367 -> V_368 = type ;
}
F_121 ( & V_63 -> V_40 , V_40 ) ;
memcpy ( V_63 -> V_45 , V_45 , V_65 ) ;
V_63 -> V_66 = V_66 ;
if ( type == V_371 )
V_63 -> type = V_369 ;
else
V_63 -> type = type ;
if ( ! V_375 )
return 0 ;
V_377 = F_199 ( V_2 , V_367 , type , V_369 ) ;
F_203 ( V_2 , V_63 , V_377 ) ;
if ( V_367 )
V_367 -> V_380 = ! V_377 ;
return 0 ;
}
int F_204 ( struct V_1 * V_2 , T_12 * V_40 , T_5 V_374 , T_5 type ,
int V_375 , T_5 V_80 , T_5 V_381 [ 16 ] , T_5 V_81 , T_11
V_82 , T_5 rand [ 8 ] )
{
struct V_78 * V_63 , * V_376 ;
if ( ! ( type & V_382 ) && ! ( type & V_383 ) )
return 0 ;
V_376 = F_201 ( V_2 , V_40 , V_374 ) ;
if ( V_376 )
V_63 = V_376 ;
else {
V_63 = F_152 ( sizeof( * V_63 ) , V_252 ) ;
if ( ! V_63 )
return - V_282 ;
F_149 ( & V_63 -> V_64 , & V_2 -> V_384 ) ;
}
F_121 ( & V_63 -> V_40 , V_40 ) ;
V_63 -> V_41 = V_374 ;
memcpy ( V_63 -> V_45 , V_381 , sizeof( V_63 -> V_45 ) ) ;
V_63 -> V_80 = V_80 ;
V_63 -> V_82 = V_82 ;
V_63 -> V_81 = V_81 ;
V_63 -> type = type ;
memcpy ( V_63 -> rand , rand , sizeof( V_63 -> rand ) ) ;
if ( ! V_375 )
return 0 ;
if ( type & V_383 )
F_205 ( V_2 , V_63 , 1 ) ;
return 0 ;
}
int F_206 ( struct V_1 * V_2 , T_12 * V_40 )
{
struct V_62 * V_63 ;
V_63 = F_198 ( V_2 , V_40 ) ;
if ( ! V_63 )
return - V_385 ;
F_64 ( L_56 , V_2 -> V_90 , V_40 ) ;
F_142 ( & V_63 -> V_64 ) ;
F_143 ( V_63 ) ;
return 0 ;
}
int F_207 ( struct V_1 * V_2 , T_12 * V_40 )
{
struct V_78 * V_365 , * V_364 ;
F_141 (k, tmp, &hdev->long_term_keys, list) {
if ( F_122 ( V_40 , & V_365 -> V_40 ) )
continue;
F_64 ( L_56 , V_2 -> V_90 , V_40 ) ;
F_142 ( & V_365 -> V_64 ) ;
F_143 ( V_365 ) ;
}
return 0 ;
}
static void F_208 ( unsigned long V_269 )
{
struct V_1 * V_2 = ( void * ) V_269 ;
if ( V_2 -> V_301 ) {
struct V_386 * V_387 = ( void * ) V_2 -> V_301 -> V_26 ;
T_8 V_97 = F_31 ( V_387 -> V_97 ) ;
F_69 ( L_57 , V_2 -> V_90 , V_97 ) ;
} else {
F_69 ( L_58 , V_2 -> V_90 ) ;
}
F_166 ( & V_2 -> V_289 , 1 ) ;
F_209 ( V_2 -> V_388 , & V_2 -> V_296 ) ;
}
struct V_389 * F_210 ( struct V_1 * V_2 ,
T_12 * V_40 )
{
struct V_389 * V_26 ;
F_26 (data, &hdev->remote_oob_data, list)
if ( F_122 ( V_40 , & V_26 -> V_40 ) == 0 )
return V_26 ;
return NULL ;
}
int F_151 ( struct V_1 * V_2 , T_12 * V_40 )
{
struct V_389 * V_26 ;
V_26 = F_210 ( V_2 , V_40 ) ;
if ( ! V_26 )
return - V_385 ;
F_64 ( L_56 , V_2 -> V_90 , V_40 ) ;
F_142 ( & V_26 -> V_64 ) ;
F_143 ( V_26 ) ;
return 0 ;
}
int F_211 ( struct V_1 * V_2 )
{
struct V_389 * V_26 , * V_61 ;
F_141 (data, n, &hdev->remote_oob_data, list) {
F_142 ( & V_26 -> V_64 ) ;
F_143 ( V_26 ) ;
}
return 0 ;
}
int F_212 ( struct V_1 * V_2 , T_12 * V_40 , T_5 * V_390 ,
T_5 * V_391 )
{
struct V_389 * V_26 ;
V_26 = F_210 ( V_2 , V_40 ) ;
if ( ! V_26 ) {
V_26 = F_162 ( sizeof( * V_26 ) , V_252 ) ;
if ( ! V_26 )
return - V_282 ;
F_121 ( & V_26 -> V_40 , V_40 ) ;
F_149 ( & V_26 -> V_64 , & V_2 -> V_392 ) ;
}
memcpy ( V_26 -> V_390 , V_390 , sizeof( V_26 -> V_390 ) ) ;
memcpy ( V_26 -> V_391 , V_391 , sizeof( V_26 -> V_391 ) ) ;
F_64 ( L_59 , V_2 -> V_90 , V_40 ) ;
return 0 ;
}
struct V_38 * F_213 ( struct V_1 * V_2 ,
T_12 * V_40 , T_5 type )
{
struct V_38 * V_39 ;
F_26 (b, &hdev->blacklist, list) {
if ( ! F_122 ( & V_39 -> V_40 , V_40 ) && V_39 -> V_41 == type )
return V_39 ;
}
return NULL ;
}
int F_214 ( struct V_1 * V_2 )
{
struct V_60 * V_31 , * V_61 ;
F_34 (p, n, &hdev->blacklist) {
struct V_38 * V_39 = F_35 ( V_31 , struct V_38 , V_64 ) ;
F_142 ( V_31 ) ;
F_143 ( V_39 ) ;
}
return 0 ;
}
int F_215 ( struct V_1 * V_2 , T_12 * V_40 , T_5 type )
{
struct V_38 * V_393 ;
if ( ! F_122 ( V_40 , V_195 ) )
return - V_394 ;
if ( F_213 ( V_2 , V_40 , type ) )
return - V_395 ;
V_393 = F_152 ( sizeof( struct V_38 ) , V_281 ) ;
if ( ! V_393 )
return - V_282 ;
F_121 ( & V_393 -> V_40 , V_40 ) ;
V_393 -> V_41 = type ;
F_149 ( & V_393 -> V_64 , & V_2 -> V_396 ) ;
return F_216 ( V_2 , V_40 , type ) ;
}
int F_217 ( struct V_1 * V_2 , T_12 * V_40 , T_5 type )
{
struct V_38 * V_393 ;
if ( ! F_122 ( V_40 , V_195 ) )
return F_214 ( V_2 ) ;
V_393 = F_213 ( V_2 , V_40 , type ) ;
if ( ! V_393 )
return - V_385 ;
F_142 ( & V_393 -> V_64 ) ;
F_143 ( V_393 ) ;
return F_218 ( V_2 , V_40 , type ) ;
}
static void F_219 ( struct V_1 * V_2 , T_5 V_397 )
{
if ( V_397 ) {
F_69 ( L_60 , V_397 ) ;
F_19 ( V_2 ) ;
F_138 ( V_2 , V_238 ) ;
F_22 ( V_2 ) ;
return;
}
}
static void F_220 ( struct V_1 * V_2 , T_5 V_397 )
{
T_5 V_264 [ 3 ] = { 0x33 , 0x8b , 0x9e } ;
struct V_114 V_115 ;
struct V_262 V_170 ;
int V_16 ;
if ( V_397 ) {
F_69 ( L_61 , V_397 ) ;
return;
}
switch ( V_2 -> V_48 . type ) {
case V_398 :
F_19 ( V_2 ) ;
F_138 ( V_2 , V_238 ) ;
F_22 ( V_2 ) ;
break;
case V_399 :
F_73 ( & V_115 , V_2 ) ;
memset ( & V_170 , 0 , sizeof( V_170 ) ) ;
memcpy ( & V_170 . V_264 , V_264 , sizeof( V_170 . V_264 ) ) ;
V_170 . V_265 = V_400 ;
F_86 ( & V_115 , V_267 , sizeof( V_170 ) , & V_170 ) ;
F_19 ( V_2 ) ;
F_140 ( V_2 ) ;
V_16 = F_75 ( & V_115 , F_219 ) ;
if ( V_16 ) {
F_69 ( L_62 , V_16 ) ;
F_138 ( V_2 , V_238 ) ;
}
F_22 ( V_2 ) ;
break;
}
}
static void F_221 ( struct V_360 * V_361 )
{
struct V_1 * V_2 = F_188 ( V_361 , struct V_1 ,
V_314 . V_361 ) ;
struct V_401 V_170 ;
struct V_114 V_115 ;
int V_16 ;
F_64 ( L_17 , V_2 -> V_90 ) ;
F_73 ( & V_115 , V_2 ) ;
memset ( & V_170 , 0 , sizeof( V_170 ) ) ;
V_170 . V_15 = V_402 ;
F_86 ( & V_115 , V_403 , sizeof( V_170 ) , & V_170 ) ;
V_16 = F_75 ( & V_115 , F_220 ) ;
if ( V_16 )
F_69 ( L_63 , V_16 ) ;
}
struct V_1 * F_222 ( void )
{
struct V_1 * V_2 ;
V_2 = F_152 ( sizeof( struct V_1 ) , V_281 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_339 = ( V_404 | V_405 | V_406 ) ;
V_2 -> V_407 = ( V_408 ) ;
V_2 -> V_335 = ( V_337 ) ;
V_2 -> V_409 = 0x01 ;
V_2 -> V_410 = 0x03 ;
V_2 -> V_411 = V_412 ;
V_2 -> V_413 = V_412 ;
V_2 -> V_74 = 800 ;
V_2 -> V_75 = 80 ;
V_2 -> V_414 = 0x0060 ;
V_2 -> V_415 = 0x0030 ;
V_2 -> V_84 = 0x0028 ;
V_2 -> V_83 = 0x0038 ;
F_223 ( & V_2 -> V_416 ) ;
F_223 ( & V_2 -> V_417 ) ;
F_144 ( & V_2 -> V_418 ) ;
F_144 ( & V_2 -> V_396 ) ;
F_144 ( & V_2 -> V_419 ) ;
F_144 ( & V_2 -> V_378 ) ;
F_144 ( & V_2 -> V_384 ) ;
F_144 ( & V_2 -> V_392 ) ;
F_144 ( & V_2 -> V_420 . V_64 ) ;
F_224 ( & V_2 -> V_297 , V_421 ) ;
F_224 ( & V_2 -> V_296 , V_422 ) ;
F_224 ( & V_2 -> V_295 , V_423 ) ;
F_224 ( & V_2 -> V_362 , F_187 ) ;
F_225 ( & V_2 -> V_305 , F_192 ) ;
F_225 ( & V_2 -> V_309 , F_193 ) ;
F_225 ( & V_2 -> V_314 , F_221 ) ;
F_226 ( & V_2 -> V_299 ) ;
F_226 ( & V_2 -> V_298 ) ;
F_226 ( & V_2 -> V_316 ) ;
F_227 ( & V_2 -> V_95 ) ;
F_228 ( & V_2 -> V_307 , F_208 , ( unsigned long ) V_2 ) ;
F_229 ( V_2 ) ;
F_230 ( V_2 ) ;
return V_2 ;
}
void F_231 ( struct V_1 * V_2 )
{
F_232 ( & V_2 -> V_303 ) ;
}
int F_233 ( struct V_1 * V_2 )
{
int V_233 , error ;
if ( ! V_2 -> V_287 || ! V_2 -> V_302 )
return - V_21 ;
switch ( V_2 -> V_135 ) {
case V_136 :
V_233 = F_234 ( & V_424 , 0 , 0 , V_281 ) ;
break;
case V_137 :
V_233 = F_234 ( & V_424 , 1 , 0 , V_281 ) ;
break;
default:
return - V_21 ;
}
if ( V_233 < 0 )
return V_233 ;
sprintf ( V_2 -> V_90 , L_64 , V_233 ) ;
V_2 -> V_233 = V_233 ;
F_64 ( L_65 , V_2 , V_2 -> V_90 , V_2 -> V_356 ) ;
V_2 -> V_388 = F_235 ( L_17 , V_425 | V_426 |
V_427 , 1 , V_2 -> V_90 ) ;
if ( ! V_2 -> V_388 ) {
error = - V_282 ;
goto V_16;
}
V_2 -> V_306 = F_235 ( L_17 , V_425 | V_426 |
V_427 , 1 , V_2 -> V_90 ) ;
if ( ! V_2 -> V_306 ) {
F_236 ( V_2 -> V_388 ) ;
error = - V_282 ;
goto V_16;
}
if ( ! F_237 ( V_428 ) )
V_2 -> V_203 = F_238 ( V_2 -> V_90 , V_428 ) ;
F_239 ( & V_2 -> V_303 , L_17 , V_2 -> V_90 ) ;
error = F_240 ( & V_2 -> V_303 ) ;
if ( error < 0 )
goto V_429;
V_2 -> V_430 = F_241 ( V_2 -> V_90 , & V_2 -> V_303 ,
V_431 , & V_432 ,
V_2 ) ;
if ( V_2 -> V_430 ) {
if ( F_242 ( V_2 -> V_430 ) < 0 ) {
F_243 ( V_2 -> V_430 ) ;
V_2 -> V_430 = NULL ;
}
}
if ( V_2 -> V_430 && F_244 ( V_2 -> V_430 ) )
F_85 ( V_284 , & V_2 -> V_11 ) ;
F_85 ( V_198 , & V_2 -> V_11 ) ;
F_85 ( V_304 , & V_2 -> V_11 ) ;
if ( V_2 -> V_135 == V_136 ) {
F_85 ( V_166 , & V_2 -> V_11 ) ;
}
F_245 ( & V_232 ) ;
F_149 ( & V_2 -> V_64 , & V_433 ) ;
F_246 ( & V_232 ) ;
F_1 ( V_2 , V_434 ) ;
F_135 ( V_2 ) ;
F_209 ( V_2 -> V_306 , & V_2 -> V_362 ) ;
return V_233 ;
V_429:
F_236 ( V_2 -> V_388 ) ;
F_236 ( V_2 -> V_306 ) ;
V_16:
F_247 ( & V_424 , V_2 -> V_233 ) ;
return error ;
}
void F_248 ( struct V_1 * V_2 )
{
int V_44 , V_233 ;
F_64 ( L_65 , V_2 , V_2 -> V_90 , V_2 -> V_356 ) ;
F_85 ( V_283 , & V_2 -> V_11 ) ;
V_233 = V_2 -> V_233 ;
F_245 ( & V_232 ) ;
F_142 ( & V_2 -> V_64 ) ;
F_246 ( & V_232 ) ;
F_174 ( V_2 ) ;
for ( V_44 = 0 ; V_44 < V_435 ; V_44 ++ )
F_16 ( V_2 -> V_436 [ V_44 ] ) ;
F_249 ( & V_2 -> V_362 ) ;
if ( ! F_4 ( V_290 , & V_2 -> V_18 ) &&
! F_4 ( V_198 , & V_2 -> V_11 ) ) {
F_19 ( V_2 ) ;
F_250 ( V_2 ) ;
F_22 ( V_2 ) ;
}
F_251 ( ! F_252 ( & V_2 -> V_418 ) ) ;
F_1 ( V_2 , V_437 ) ;
if ( V_2 -> V_430 ) {
F_253 ( V_2 -> V_430 ) ;
F_243 ( V_2 -> V_430 ) ;
}
F_254 ( & V_2 -> V_303 ) ;
F_255 ( V_2 -> V_203 ) ;
F_236 ( V_2 -> V_388 ) ;
F_236 ( V_2 -> V_306 ) ;
F_19 ( V_2 ) ;
F_214 ( V_2 ) ;
F_195 ( V_2 ) ;
F_196 ( V_2 ) ;
F_197 ( V_2 ) ;
F_211 ( V_2 ) ;
F_22 ( V_2 ) ;
F_164 ( V_2 ) ;
F_247 ( & V_424 , V_233 ) ;
}
int F_256 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_438 ) ;
return 0 ;
}
int F_257 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_439 ) ;
return 0 ;
}
int F_258 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
if ( ! V_2 || ( ! F_4 ( V_17 , & V_2 -> V_18 )
&& ! F_4 ( V_290 , & V_2 -> V_18 ) ) ) {
F_16 ( V_13 ) ;
return - V_440 ;
}
F_259 ( V_13 ) -> V_441 = 1 ;
F_260 ( V_13 ) ;
F_261 ( & V_2 -> V_299 , V_13 ) ;
F_209 ( V_2 -> V_388 , & V_2 -> V_297 ) ;
return 0 ;
}
static int F_262 ( struct V_1 * V_2 , int type , void * V_26 ,
int V_6 , T_7 V_230 )
{
int V_104 = 0 ;
int V_442 = 0 ;
int V_443 = V_6 ;
struct V_12 * V_13 ;
struct V_444 * V_445 ;
if ( ( type < V_446 || type > V_447 ) ||
V_230 >= V_435 )
return - V_448 ;
V_13 = V_2 -> V_436 [ V_230 ] ;
if ( ! V_13 ) {
switch ( type ) {
case V_446 :
V_104 = V_449 ;
V_442 = V_450 ;
break;
case V_447 :
V_104 = V_451 ;
V_442 = V_106 ;
break;
case V_452 :
V_104 = V_453 ;
V_442 = V_454 ;
break;
}
V_13 = F_263 ( V_104 , V_252 ) ;
if ( ! V_13 )
return - V_282 ;
V_445 = ( void * ) V_13 -> V_455 ;
V_445 -> V_456 = V_442 ;
V_445 -> V_339 = type ;
V_2 -> V_436 [ V_230 ] = V_13 ;
}
while ( V_6 ) {
V_445 = ( void * ) V_13 -> V_455 ;
V_104 = F_264 ( V_457 , V_445 -> V_456 , V_6 ) ;
memcpy ( F_265 ( V_13 , V_104 ) , V_26 , V_104 ) ;
V_6 -= V_104 ;
V_26 += V_104 ;
V_445 -> V_456 -= V_104 ;
V_443 = V_6 ;
switch ( type ) {
case V_447 :
if ( V_13 -> V_104 == V_106 ) {
struct V_100 * V_458 = V_100 ( V_13 ) ;
V_445 -> V_456 = V_458 -> V_109 ;
if ( F_266 ( V_13 ) < V_445 -> V_456 ) {
F_16 ( V_13 ) ;
V_2 -> V_436 [ V_230 ] = NULL ;
return - V_282 ;
}
}
break;
case V_446 :
if ( V_13 -> V_104 == V_450 ) {
struct V_459 * V_458 = V_459 ( V_13 ) ;
V_445 -> V_456 = F_31 ( V_458 -> V_460 ) ;
if ( F_266 ( V_13 ) < V_445 -> V_456 ) {
F_16 ( V_13 ) ;
V_2 -> V_436 [ V_230 ] = NULL ;
return - V_282 ;
}
}
break;
case V_452 :
if ( V_13 -> V_104 == V_454 ) {
struct V_461 * V_458 = V_461 ( V_13 ) ;
V_445 -> V_456 = V_458 -> V_460 ;
if ( F_266 ( V_13 ) < V_445 -> V_456 ) {
F_16 ( V_13 ) ;
V_2 -> V_436 [ V_230 ] = NULL ;
return - V_282 ;
}
}
break;
}
if ( V_445 -> V_456 == 0 ) {
F_259 ( V_13 ) -> V_339 = type ;
F_258 ( V_2 , V_13 ) ;
V_2 -> V_436 [ V_230 ] = NULL ;
return V_443 ;
}
}
return V_443 ;
}
int F_267 ( struct V_1 * V_2 , int type , void * V_26 , int V_6 )
{
int V_462 = 0 ;
if ( type < V_446 || type > V_447 )
return - V_448 ;
while ( V_6 ) {
V_462 = F_262 ( V_2 , type , V_26 , V_6 , type - 1 ) ;
if ( V_462 < 0 )
return V_462 ;
V_26 += ( V_6 - V_462 ) ;
V_6 = V_462 ;
}
return V_462 ;
}
int F_268 ( struct V_1 * V_2 , void * V_26 , int V_6 )
{
int type ;
int V_462 = 0 ;
while ( V_6 ) {
struct V_12 * V_13 = V_2 -> V_436 [ V_463 ] ;
if ( ! V_13 ) {
struct { char type ; } * V_464 ;
V_464 = V_26 ;
type = V_464 -> type ;
V_26 ++ ;
V_6 -- ;
} else
type = F_259 ( V_13 ) -> V_339 ;
V_462 = F_262 ( V_2 , type , V_26 , V_6 ,
V_463 ) ;
if ( V_462 < 0 )
return V_462 ;
V_26 += ( V_6 - V_462 ) ;
V_6 = V_462 ;
}
return V_462 ;
}
int F_269 ( struct V_465 * V_455 )
{
F_64 ( L_66 , V_455 , V_455 -> V_90 ) ;
F_245 ( & V_466 ) ;
F_149 ( & V_455 -> V_64 , & V_467 ) ;
F_246 ( & V_466 ) ;
return 0 ;
}
int F_270 ( struct V_465 * V_455 )
{
F_64 ( L_66 , V_455 , V_455 -> V_90 ) ;
F_245 ( & V_466 ) ;
F_142 ( & V_455 -> V_64 ) ;
F_246 ( & V_466 ) ;
return 0 ;
}
static void F_271 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
F_64 ( L_67 , V_2 -> V_90 , F_259 ( V_13 ) -> V_339 , V_13 -> V_104 ) ;
F_260 ( V_13 ) ;
F_272 ( V_2 , V_13 ) ;
if ( F_273 ( & V_2 -> V_468 ) ) {
F_274 ( V_2 , V_13 ) ;
}
F_275 ( V_13 ) ;
if ( V_2 -> V_469 ( V_2 , V_13 ) < 0 )
F_69 ( L_68 , V_2 -> V_90 ) ;
}
void F_73 ( struct V_114 * V_115 , struct V_1 * V_2 )
{
F_226 ( & V_115 -> V_298 ) ;
V_115 -> V_2 = V_2 ;
V_115 -> V_16 = 0 ;
}
int F_75 ( struct V_114 * V_115 , T_14 V_470 )
{
struct V_1 * V_2 = V_115 -> V_2 ;
struct V_12 * V_13 ;
unsigned long V_18 ;
F_64 ( L_69 , F_276 ( & V_115 -> V_298 ) ) ;
if ( V_115 -> V_16 ) {
F_169 ( & V_115 -> V_298 ) ;
return V_115 -> V_16 ;
}
if ( F_277 ( & V_115 -> V_298 ) )
return - V_103 ;
V_13 = F_278 ( & V_115 -> V_298 ) ;
F_259 ( V_13 ) -> V_115 . V_470 = V_470 ;
F_279 ( & V_2 -> V_298 . V_416 , V_18 ) ;
F_280 ( & V_115 -> V_298 , & V_2 -> V_298 ) ;
F_281 ( & V_2 -> V_298 . V_416 , V_18 ) ;
F_209 ( V_2 -> V_388 , & V_2 -> V_296 ) ;
return 0 ;
}
static struct V_12 * F_282 ( struct V_1 * V_2 , T_8 V_97 ,
T_9 V_109 , const void * V_110 )
{
int V_104 = V_471 + V_109 ;
struct V_386 * V_101 ;
struct V_12 * V_13 ;
V_13 = F_263 ( V_104 , V_252 ) ;
if ( ! V_13 )
return NULL ;
V_101 = (struct V_386 * ) F_265 ( V_13 , V_471 ) ;
V_101 -> V_97 = F_113 ( V_97 ) ;
V_101 -> V_109 = V_109 ;
if ( V_109 )
memcpy ( F_265 ( V_13 , V_109 ) , V_110 , V_109 ) ;
F_64 ( L_70 , V_13 -> V_104 ) ;
F_259 ( V_13 ) -> V_339 = V_472 ;
return V_13 ;
}
int F_283 ( struct V_1 * V_2 , T_13 V_97 , T_10 V_109 ,
const void * V_110 )
{
struct V_12 * V_13 ;
F_64 ( L_71 , V_2 -> V_90 , V_97 , V_109 ) ;
V_13 = F_282 ( V_2 , V_97 , V_109 , V_110 ) ;
if ( ! V_13 ) {
F_69 ( L_72 , V_2 -> V_90 ) ;
return - V_282 ;
}
F_259 ( V_13 ) -> V_115 . V_473 = true ;
F_261 ( & V_2 -> V_298 , V_13 ) ;
F_209 ( V_2 -> V_388 , & V_2 -> V_296 ) ;
return 0 ;
}
void F_74 ( struct V_114 * V_115 , T_8 V_97 , T_9 V_109 ,
const void * V_110 , T_5 V_3 )
{
struct V_1 * V_2 = V_115 -> V_2 ;
struct V_12 * V_13 ;
F_64 ( L_71 , V_2 -> V_90 , V_97 , V_109 ) ;
if ( V_115 -> V_16 )
return;
V_13 = F_282 ( V_2 , V_97 , V_109 , V_110 ) ;
if ( ! V_13 ) {
F_69 ( L_73 ,
V_2 -> V_90 , V_97 ) ;
V_115 -> V_16 = - V_282 ;
return;
}
if ( F_277 ( & V_115 -> V_298 ) )
F_259 ( V_13 ) -> V_115 . V_473 = true ;
F_259 ( V_13 ) -> V_115 . V_3 = V_3 ;
F_261 ( & V_115 -> V_298 , V_13 ) ;
}
void F_86 ( struct V_114 * V_115 , T_8 V_97 , T_9 V_109 ,
const void * V_110 )
{
F_74 ( V_115 , V_97 , V_109 , V_110 , 0 ) ;
}
void * F_284 ( struct V_1 * V_2 , T_13 V_97 )
{
struct V_386 * V_101 ;
if ( ! V_2 -> V_301 )
return NULL ;
V_101 = ( void * ) V_2 -> V_301 -> V_26 ;
if ( V_101 -> V_97 != F_113 ( V_97 ) )
return NULL ;
F_64 ( L_74 , V_2 -> V_90 , V_97 ) ;
return V_2 -> V_301 -> V_26 + V_471 ;
}
static void F_285 ( struct V_12 * V_13 , T_13 V_474 , T_13 V_18 )
{
struct V_459 * V_101 ;
int V_104 = V_13 -> V_104 ;
F_286 ( V_13 , V_450 ) ;
F_287 ( V_13 ) ;
V_101 = (struct V_459 * ) F_288 ( V_13 ) ;
V_101 -> V_474 = F_113 ( F_289 ( V_474 , V_18 ) ) ;
V_101 -> V_460 = F_113 ( V_104 ) ;
}
static void F_290 ( struct V_475 * V_476 , struct V_477 * V_478 ,
struct V_12 * V_13 , T_13 V_18 )
{
struct V_366 * V_367 = V_476 -> V_367 ;
struct V_1 * V_2 = V_367 -> V_2 ;
struct V_12 * V_64 ;
V_13 -> V_104 = F_291 ( V_13 ) ;
V_13 -> V_479 = 0 ;
F_259 ( V_13 ) -> V_339 = V_446 ;
switch ( V_2 -> V_135 ) {
case V_136 :
F_285 ( V_13 , V_367 -> V_474 , V_18 ) ;
break;
case V_137 :
F_285 ( V_13 , V_476 -> V_474 , V_18 ) ;
break;
default:
F_69 ( L_75 , V_2 -> V_90 , V_2 -> V_135 ) ;
return;
}
V_64 = F_292 ( V_13 ) -> V_480 ;
if ( ! V_64 ) {
F_64 ( L_76 , V_2 -> V_90 , V_13 , V_13 -> V_104 ) ;
F_261 ( V_478 , V_13 ) ;
} else {
F_64 ( L_77 , V_2 -> V_90 , V_13 , V_13 -> V_104 ) ;
F_292 ( V_13 ) -> V_480 = NULL ;
F_293 ( & V_478 -> V_416 ) ;
F_294 ( V_478 , V_13 ) ;
V_18 &= ~ V_481 ;
V_18 |= V_482 ;
do {
V_13 = V_64 ; V_64 = V_64 -> V_483 ;
F_259 ( V_13 ) -> V_339 = V_446 ;
F_285 ( V_13 , V_367 -> V_474 , V_18 ) ;
F_64 ( L_77 , V_2 -> V_90 , V_13 , V_13 -> V_104 ) ;
F_294 ( V_478 , V_13 ) ;
} while ( V_64 );
F_295 ( & V_478 -> V_416 ) ;
}
}
void F_296 ( struct V_475 * V_476 , struct V_12 * V_13 , T_13 V_18 )
{
struct V_1 * V_2 = V_476 -> V_367 -> V_2 ;
F_64 ( L_78 , V_2 -> V_90 , V_476 , V_18 ) ;
F_290 ( V_476 , & V_476 -> V_484 , V_13 , V_18 ) ;
F_209 ( V_2 -> V_388 , & V_2 -> V_295 ) ;
}
void F_297 ( struct V_366 * V_367 , struct V_12 * V_13 )
{
struct V_1 * V_2 = V_367 -> V_2 ;
struct V_461 V_101 ;
F_64 ( L_79 , V_2 -> V_90 , V_13 -> V_104 ) ;
V_101 . V_474 = F_113 ( V_367 -> V_474 ) ;
V_101 . V_460 = V_13 -> V_104 ;
F_286 ( V_13 , V_454 ) ;
F_287 ( V_13 ) ;
memcpy ( F_288 ( V_13 ) , & V_101 , V_454 ) ;
F_259 ( V_13 ) -> V_339 = V_452 ;
F_261 ( & V_367 -> V_484 , V_13 ) ;
F_209 ( V_2 -> V_388 , & V_2 -> V_295 ) ;
}
static struct V_366 * F_298 ( struct V_1 * V_2 , T_7 type ,
int * V_485 )
{
struct V_486 * V_458 = & V_2 -> V_420 ;
struct V_366 * V_367 = NULL , * V_487 ;
unsigned int V_256 = 0 , F_7 = ~ 0 ;
F_299 () ;
F_300 (c, &h->list, list) {
if ( V_487 -> type != type || F_277 ( & V_487 -> V_484 ) )
continue;
if ( V_487 -> V_235 != V_488 && V_487 -> V_235 != V_489 )
continue;
V_256 ++ ;
if ( V_487 -> V_387 < F_7 ) {
F_7 = V_487 -> V_387 ;
V_367 = V_487 ;
}
if ( F_301 ( V_2 , type ) == V_256 )
break;
}
F_302 () ;
if ( V_367 ) {
int V_490 , V_491 ;
switch ( V_367 -> type ) {
case V_492 :
V_490 = V_2 -> V_320 ;
break;
case V_493 :
case V_494 :
V_490 = V_2 -> V_321 ;
break;
case V_495 :
V_490 = V_2 -> V_357 ? V_2 -> V_322 : V_2 -> V_320 ;
break;
default:
V_490 = 0 ;
F_69 ( L_80 ) ;
}
V_491 = V_490 / V_256 ;
* V_485 = V_491 ? V_491 : 1 ;
} else
* V_485 = 0 ;
F_64 ( L_81 , V_367 , * V_485 ) ;
return V_367 ;
}
static void F_303 ( struct V_1 * V_2 , T_7 type )
{
struct V_486 * V_458 = & V_2 -> V_420 ;
struct V_366 * V_487 ;
F_69 ( L_82 , V_2 -> V_90 ) ;
F_299 () ;
F_300 (c, &h->list, list) {
if ( V_487 -> type == type && V_487 -> V_387 ) {
F_69 ( L_83 ,
V_2 -> V_90 , & V_487 -> V_496 ) ;
F_304 ( V_487 , V_497 ) ;
}
}
F_302 () ;
}
static struct V_475 * F_305 ( struct V_1 * V_2 , T_7 type ,
int * V_485 )
{
struct V_486 * V_458 = & V_2 -> V_420 ;
struct V_475 * V_476 = NULL ;
unsigned int V_256 = 0 , F_7 = ~ 0 , V_498 = 0 ;
struct V_366 * V_367 ;
int V_490 , V_491 , V_499 = 0 ;
F_64 ( L_17 , V_2 -> V_90 ) ;
F_299 () ;
F_300 (conn, &h->list, list) {
struct V_475 * V_364 ;
if ( V_367 -> type != type )
continue;
if ( V_367 -> V_235 != V_488 && V_367 -> V_235 != V_489 )
continue;
V_499 ++ ;
F_300 (tmp, &conn->chan_list, list) {
struct V_12 * V_13 ;
if ( F_277 ( & V_364 -> V_484 ) )
continue;
V_13 = F_306 ( & V_364 -> V_484 ) ;
if ( V_13 -> V_500 < V_498 )
continue;
if ( V_13 -> V_500 > V_498 ) {
V_256 = 0 ;
F_7 = ~ 0 ;
V_498 = V_13 -> V_500 ;
}
V_256 ++ ;
if ( V_367 -> V_387 < F_7 ) {
F_7 = V_367 -> V_387 ;
V_476 = V_364 ;
}
}
if ( F_301 ( V_2 , type ) == V_499 )
break;
}
F_302 () ;
if ( ! V_476 )
return NULL ;
switch ( V_476 -> V_367 -> type ) {
case V_492 :
V_490 = V_2 -> V_320 ;
break;
case V_501 :
V_490 = V_2 -> V_502 ;
break;
case V_493 :
case V_494 :
V_490 = V_2 -> V_321 ;
break;
case V_495 :
V_490 = V_2 -> V_357 ? V_2 -> V_322 : V_2 -> V_320 ;
break;
default:
V_490 = 0 ;
F_69 ( L_80 ) ;
}
V_491 = V_490 / V_256 ;
* V_485 = V_491 ? V_491 : 1 ;
F_64 ( L_84 , V_476 , * V_485 ) ;
return V_476 ;
}
static void F_307 ( struct V_1 * V_2 , T_7 type )
{
struct V_486 * V_458 = & V_2 -> V_420 ;
struct V_366 * V_367 ;
int V_256 = 0 ;
F_64 ( L_17 , V_2 -> V_90 ) ;
F_299 () ;
F_300 (conn, &h->list, list) {
struct V_475 * V_476 ;
if ( V_367 -> type != type )
continue;
if ( V_367 -> V_235 != V_488 && V_367 -> V_235 != V_489 )
continue;
V_256 ++ ;
F_300 (chan, &conn->chan_list, list) {
struct V_12 * V_13 ;
if ( V_476 -> V_387 ) {
V_476 -> V_387 = 0 ;
continue;
}
if ( F_277 ( & V_476 -> V_484 ) )
continue;
V_13 = F_306 ( & V_476 -> V_484 ) ;
if ( V_13 -> V_500 >= V_503 - 1 )
continue;
V_13 -> V_500 = V_503 - 1 ;
F_64 ( L_85 , V_476 , V_13 ,
V_13 -> V_500 ) ;
}
if ( F_301 ( V_2 , type ) == V_256 )
break;
}
F_302 () ;
}
static inline int F_308 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
return F_309 ( V_13 -> V_104 - V_450 , V_2 -> V_504 ) ;
}
static void F_310 ( struct V_1 * V_2 , unsigned int V_490 )
{
if ( ! F_4 ( V_293 , & V_2 -> V_18 ) ) {
if ( ! V_490 && F_311 ( V_255 , V_2 -> V_505 +
V_506 ) )
F_303 ( V_2 , V_492 ) ;
}
}
static void F_312 ( struct V_1 * V_2 )
{
unsigned int V_490 = V_2 -> V_320 ;
struct V_475 * V_476 ;
struct V_12 * V_13 ;
int V_485 ;
F_310 ( V_2 , V_490 ) ;
while ( V_2 -> V_320 &&
( V_476 = F_305 ( V_2 , V_492 , & V_485 ) ) ) {
T_9 V_500 = ( F_306 ( & V_476 -> V_484 ) ) -> V_500 ;
while ( V_485 -- && ( V_13 = F_306 ( & V_476 -> V_484 ) ) ) {
F_64 ( L_86 , V_476 , V_13 ,
V_13 -> V_104 , V_13 -> V_500 ) ;
if ( V_13 -> V_500 < V_500 )
break;
V_13 = F_313 ( & V_476 -> V_484 ) ;
F_314 ( V_476 -> V_367 ,
F_259 ( V_13 ) -> V_507 ) ;
F_271 ( V_2 , V_13 ) ;
V_2 -> V_505 = V_255 ;
V_2 -> V_320 -- ;
V_476 -> V_387 ++ ;
V_476 -> V_367 -> V_387 ++ ;
}
}
if ( V_490 != V_2 -> V_320 )
F_307 ( V_2 , V_492 ) ;
}
static void F_315 ( struct V_1 * V_2 )
{
unsigned int V_490 = V_2 -> V_502 ;
struct V_475 * V_476 ;
struct V_12 * V_13 ;
int V_485 ;
T_5 type ;
F_310 ( V_2 , V_490 ) ;
F_64 ( L_17 , V_2 -> V_90 ) ;
if ( V_2 -> V_135 == V_137 )
type = V_501 ;
else
type = V_492 ;
while ( V_2 -> V_502 > 0 &&
( V_476 = F_305 ( V_2 , type , & V_485 ) ) ) {
T_9 V_500 = ( F_306 ( & V_476 -> V_484 ) ) -> V_500 ;
while ( V_485 > 0 && ( V_13 = F_306 ( & V_476 -> V_484 ) ) ) {
int V_508 ;
F_64 ( L_86 , V_476 , V_13 ,
V_13 -> V_104 , V_13 -> V_500 ) ;
if ( V_13 -> V_500 < V_500 )
break;
V_13 = F_313 ( & V_476 -> V_484 ) ;
V_508 = F_308 ( V_2 , V_13 ) ;
if ( V_508 > V_2 -> V_502 )
return;
F_314 ( V_476 -> V_367 ,
F_259 ( V_13 ) -> V_507 ) ;
F_271 ( V_2 , V_13 ) ;
V_2 -> V_505 = V_255 ;
V_2 -> V_502 -= V_508 ;
V_485 -= V_508 ;
V_476 -> V_387 += V_508 ;
V_476 -> V_367 -> V_387 += V_508 ;
}
}
if ( V_490 != V_2 -> V_502 )
F_307 ( V_2 , type ) ;
}
static void F_316 ( struct V_1 * V_2 )
{
F_64 ( L_17 , V_2 -> V_90 ) ;
if ( ! F_301 ( V_2 , V_492 ) && V_2 -> V_135 == V_136 )
return;
if ( ! F_301 ( V_2 , V_501 ) && V_2 -> V_135 == V_137 )
return;
switch ( V_2 -> V_122 ) {
case V_123 :
F_312 ( V_2 ) ;
break;
case V_127 :
F_315 ( V_2 ) ;
break;
}
}
static void F_317 ( struct V_1 * V_2 )
{
struct V_366 * V_367 ;
struct V_12 * V_13 ;
int V_485 ;
F_64 ( L_17 , V_2 -> V_90 ) ;
if ( ! F_301 ( V_2 , V_493 ) )
return;
while ( V_2 -> V_321 && ( V_367 = F_298 ( V_2 , V_493 , & V_485 ) ) ) {
while ( V_485 -- && ( V_13 = F_313 ( & V_367 -> V_484 ) ) ) {
F_64 ( L_87 , V_13 , V_13 -> V_104 ) ;
F_271 ( V_2 , V_13 ) ;
V_367 -> V_387 ++ ;
if ( V_367 -> V_387 == ~ 0 )
V_367 -> V_387 = 0 ;
}
}
}
static void F_318 ( struct V_1 * V_2 )
{
struct V_366 * V_367 ;
struct V_12 * V_13 ;
int V_485 ;
F_64 ( L_17 , V_2 -> V_90 ) ;
if ( ! F_301 ( V_2 , V_494 ) )
return;
while ( V_2 -> V_321 && ( V_367 = F_298 ( V_2 , V_494 ,
& V_485 ) ) ) {
while ( V_485 -- && ( V_13 = F_313 ( & V_367 -> V_484 ) ) ) {
F_64 ( L_87 , V_13 , V_13 -> V_104 ) ;
F_271 ( V_2 , V_13 ) ;
V_367 -> V_387 ++ ;
if ( V_367 -> V_387 == ~ 0 )
V_367 -> V_387 = 0 ;
}
}
}
static void F_319 ( struct V_1 * V_2 )
{
struct V_475 * V_476 ;
struct V_12 * V_13 ;
int V_485 , V_490 , V_364 ;
F_64 ( L_17 , V_2 -> V_90 ) ;
if ( ! F_301 ( V_2 , V_495 ) )
return;
if ( ! F_4 ( V_293 , & V_2 -> V_18 ) ) {
if ( ! V_2 -> V_322 && V_2 -> V_358 &&
F_311 ( V_255 , V_2 -> V_509 + V_510 * 45 ) )
F_303 ( V_2 , V_495 ) ;
}
V_490 = V_2 -> V_358 ? V_2 -> V_322 : V_2 -> V_320 ;
V_364 = V_490 ;
while ( V_490 && ( V_476 = F_305 ( V_2 , V_495 , & V_485 ) ) ) {
T_9 V_500 = ( F_306 ( & V_476 -> V_484 ) ) -> V_500 ;
while ( V_485 -- && ( V_13 = F_306 ( & V_476 -> V_484 ) ) ) {
F_64 ( L_86 , V_476 , V_13 ,
V_13 -> V_104 , V_13 -> V_500 ) ;
if ( V_13 -> V_500 < V_500 )
break;
V_13 = F_313 ( & V_476 -> V_484 ) ;
F_271 ( V_2 , V_13 ) ;
V_2 -> V_509 = V_255 ;
V_490 -- ;
V_476 -> V_387 ++ ;
V_476 -> V_367 -> V_387 ++ ;
}
}
if ( V_2 -> V_358 )
V_2 -> V_322 = V_490 ;
else
V_2 -> V_320 = V_490 ;
if ( V_490 != V_364 )
F_307 ( V_2 , V_495 ) ;
}
static void V_423 ( struct V_360 * V_361 )
{
struct V_1 * V_2 = F_188 ( V_361 , struct V_1 , V_295 ) ;
struct V_12 * V_13 ;
F_64 ( L_88 , V_2 -> V_90 , V_2 -> V_320 ,
V_2 -> V_321 , V_2 -> V_322 ) ;
if ( ! F_4 ( V_275 , & V_2 -> V_11 ) ) {
F_316 ( V_2 ) ;
F_317 ( V_2 ) ;
F_318 ( V_2 ) ;
F_319 ( V_2 ) ;
}
while ( ( V_13 = F_313 ( & V_2 -> V_316 ) ) )
F_271 ( V_2 , V_13 ) ;
}
static void F_320 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_459 * V_101 = ( void * ) V_13 -> V_26 ;
struct V_366 * V_367 ;
T_13 V_474 , V_18 ;
F_70 ( V_13 , V_450 ) ;
V_474 = F_31 ( V_101 -> V_474 ) ;
V_18 = F_321 ( V_474 ) ;
V_474 = F_322 ( V_474 ) ;
F_64 ( L_89 , V_2 -> V_90 , V_13 -> V_104 ,
V_474 , V_18 ) ;
V_2 -> V_323 . V_511 ++ ;
F_19 ( V_2 ) ;
V_367 = F_323 ( V_2 , V_474 ) ;
F_22 ( V_2 ) ;
if ( V_367 ) {
F_314 ( V_367 , V_512 ) ;
F_324 ( V_367 , V_13 , V_18 ) ;
return;
} else {
F_69 ( L_90 ,
V_2 -> V_90 , V_474 ) ;
}
F_16 ( V_13 ) ;
}
static void F_325 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_461 * V_101 = ( void * ) V_13 -> V_26 ;
struct V_366 * V_367 ;
T_13 V_474 ;
F_70 ( V_13 , V_454 ) ;
V_474 = F_31 ( V_101 -> V_474 ) ;
F_64 ( L_91 , V_2 -> V_90 , V_13 -> V_104 , V_474 ) ;
V_2 -> V_323 . V_513 ++ ;
F_19 ( V_2 ) ;
V_367 = F_323 ( V_2 , V_474 ) ;
F_22 ( V_2 ) ;
if ( V_367 ) {
F_326 ( V_367 , V_13 ) ;
return;
} else {
F_69 ( L_92 ,
V_2 -> V_90 , V_474 ) ;
}
F_16 ( V_13 ) ;
}
static bool F_327 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
V_13 = F_306 ( & V_2 -> V_298 ) ;
if ( ! V_13 )
return true ;
return F_259 ( V_13 ) -> V_115 . V_473 ;
}
static void F_328 ( struct V_1 * V_2 )
{
struct V_386 * V_387 ;
struct V_12 * V_13 ;
T_8 V_97 ;
if ( ! V_2 -> V_301 )
return;
V_387 = ( void * ) V_2 -> V_301 -> V_26 ;
V_97 = F_31 ( V_387 -> V_97 ) ;
if ( V_97 == V_25 )
return;
V_13 = F_329 ( V_2 -> V_301 , V_281 ) ;
if ( ! V_13 )
return;
F_330 ( & V_2 -> V_298 , V_13 ) ;
F_209 ( V_2 -> V_388 , & V_2 -> V_296 ) ;
}
void F_331 ( struct V_1 * V_2 , T_8 V_97 , T_5 V_397 )
{
T_14 V_514 = NULL ;
struct V_12 * V_13 ;
unsigned long V_18 ;
F_64 ( L_93 , V_97 , V_397 ) ;
if ( ! F_284 ( V_2 , V_97 ) ) {
if ( F_4 ( V_290 , & V_2 -> V_18 ) && V_97 == V_25 )
F_328 ( V_2 ) ;
return;
}
if ( ! V_397 && ! F_327 ( V_2 ) )
return;
if ( V_2 -> V_301 ) {
V_514 = F_259 ( V_2 -> V_301 ) -> V_115 . V_470 ;
if ( V_514 ) {
F_259 ( V_2 -> V_301 ) -> V_115 . V_470 = NULL ;
goto V_515;
}
}
F_279 ( & V_2 -> V_298 . V_416 , V_18 ) ;
while ( ( V_13 = F_332 ( & V_2 -> V_298 ) ) ) {
if ( F_259 ( V_13 ) -> V_115 . V_473 ) {
F_333 ( & V_2 -> V_298 , V_13 ) ;
break;
}
V_514 = F_259 ( V_13 ) -> V_115 . V_470 ;
F_16 ( V_13 ) ;
}
F_281 ( & V_2 -> V_298 . V_416 , V_18 ) ;
V_515:
if ( V_514 )
V_514 ( V_2 , V_397 ) ;
}
static void V_421 ( struct V_360 * V_361 )
{
struct V_1 * V_2 = F_188 ( V_361 , struct V_1 , V_297 ) ;
struct V_12 * V_13 ;
F_64 ( L_17 , V_2 -> V_90 ) ;
while ( ( V_13 = F_313 ( & V_2 -> V_299 ) ) ) {
F_272 ( V_2 , V_13 ) ;
if ( F_273 ( & V_2 -> V_468 ) ) {
F_274 ( V_2 , V_13 ) ;
}
if ( F_4 ( V_293 , & V_2 -> V_18 ) ||
F_4 ( V_275 , & V_2 -> V_11 ) ) {
F_16 ( V_13 ) ;
continue;
}
if ( F_4 ( V_290 , & V_2 -> V_18 ) ) {
switch ( F_259 ( V_13 ) -> V_339 ) {
case V_446 :
case V_452 :
F_16 ( V_13 ) ;
continue;
}
}
switch ( F_259 ( V_13 ) -> V_339 ) {
case V_447 :
F_64 ( L_94 , V_2 -> V_90 ) ;
F_334 ( V_2 , V_13 ) ;
break;
case V_446 :
F_64 ( L_95 , V_2 -> V_90 ) ;
F_320 ( V_2 , V_13 ) ;
break;
case V_452 :
F_64 ( L_96 , V_2 -> V_90 ) ;
F_325 ( V_2 , V_13 ) ;
break;
default:
F_16 ( V_13 ) ;
break;
}
}
}
static void V_422 ( struct V_360 * V_361 )
{
struct V_1 * V_2 = F_188 ( V_361 , struct V_1 , V_296 ) ;
struct V_12 * V_13 ;
F_64 ( L_97 , V_2 -> V_90 ,
F_273 ( & V_2 -> V_289 ) , F_276 ( & V_2 -> V_298 ) ) ;
if ( F_273 ( & V_2 -> V_289 ) ) {
V_13 = F_313 ( & V_2 -> V_298 ) ;
if ( ! V_13 )
return;
F_16 ( V_2 -> V_301 ) ;
V_2 -> V_301 = F_329 ( V_13 , V_281 ) ;
if ( V_2 -> V_301 ) {
F_335 ( & V_2 -> V_289 ) ;
F_271 ( V_2 , V_13 ) ;
if ( F_4 ( V_121 , & V_2 -> V_18 ) )
F_336 ( & V_2 -> V_307 ) ;
else
F_337 ( & V_2 -> V_307 ,
V_255 + V_24 ) ;
} else {
F_330 ( & V_2 -> V_298 , V_13 ) ;
F_209 ( V_2 -> V_388 , & V_2 -> V_296 ) ;
}
}
}
