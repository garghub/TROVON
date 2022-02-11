static int F_1 ( struct V_1 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 ;
if ( ! V_3 )
goto V_6;
V_5 = F_2 ( V_3 ) ;
F_3 ( V_3 ) ;
F_4 ( V_5 ) ;
F_5 ( V_5 ) ;
F_6 ( V_5 ) ;
F_7 ( V_5 , NULL ) ;
F_8 ( V_5 ) ;
F_9 ( V_5 , NULL ) ;
F_10 ( & V_7 ) ;
F_11 ( & V_5 -> V_8 ) ;
V_9 -- ;
F_12 ( & V_7 ) ;
F_13 ( V_5 -> V_10 ) ;
V_2 -> V_3 = NULL ;
F_14 ( V_3 ) ;
V_6:
return 0 ;
}
void F_15 ( struct V_4 * V_5 )
{
unsigned long V_11 ;
F_16 ( & V_5 -> V_12 , V_11 ) ;
F_17 ( F_18 ( V_5 ) ) ;
F_19 ( & V_5 -> V_12 , V_11 ) ;
}
static int F_20 ( struct V_1 * V_2 , struct V_13 * V_14 ,
int * V_15 , int V_16 )
{
struct V_17 * sin = (struct V_17 * ) V_14 ;
struct V_4 * V_5 = F_2 ( V_2 -> V_3 ) ;
memset ( sin -> V_18 , 0 , sizeof( sin -> V_18 ) ) ;
if ( V_16 ) {
if ( ! V_5 -> V_19 )
return - V_20 ;
sin -> V_21 = V_5 -> V_22 ;
sin -> V_23 . V_24 = V_5 -> V_19 ;
} else {
sin -> V_21 = V_5 -> V_25 ;
sin -> V_23 . V_24 = V_5 -> V_26 ;
}
sin -> V_27 = V_28 ;
* V_15 = sizeof( * sin ) ;
return 0 ;
}
static unsigned int F_21 ( struct V_29 * V_29 , struct V_1 * V_2 ,
T_1 * V_30 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
unsigned int V_31 = 0 ;
unsigned long V_11 ;
F_22 ( V_29 , F_23 ( V_3 ) , V_30 ) ;
if ( V_5 -> V_32 )
F_22 ( V_29 , & V_33 , V_30 ) ;
F_16 ( & V_5 -> V_12 , V_11 ) ;
if ( ! V_5 -> V_34 ) {
if ( F_24 ( & V_5 -> V_35 ) )
V_31 |= ( V_36 | V_37 | V_38 ) ;
} else {
F_25 ( & V_5 -> V_39 ) ;
if ( V_5 -> V_40 )
V_31 |= ( V_36 | V_37 ) ;
F_26 ( & V_5 -> V_39 ) ;
}
if ( ! F_27 ( & V_5 -> V_41 ) ||
! F_27 ( & V_5 -> V_42 ) )
V_31 |= ( V_36 | V_37 ) ;
if ( V_5 -> V_43 < F_28 ( V_5 ) )
V_31 |= ( V_44 | V_45 ) ;
F_19 ( & V_5 -> V_12 , V_11 ) ;
if ( V_31 )
V_5 -> V_32 = 0 ;
return V_31 ;
}
static int F_29 ( struct V_1 * V_2 , unsigned int V_46 , unsigned long V_47 )
{
return - V_48 ;
}
static int F_30 ( struct V_4 * V_5 , char T_2 * V_49 ,
int V_50 )
{
struct V_17 sin ;
int V_51 = 0 ;
if ( V_5 -> V_26 == 0 ) {
V_51 = - V_20 ;
goto V_6;
}
if ( V_50 < sizeof( struct V_17 ) ) {
V_51 = - V_52 ;
goto V_6;
}
if ( F_31 ( & sin , V_49 , sizeof( sin ) ) ) {
V_51 = - V_53 ;
goto V_6;
}
F_7 ( V_5 , & sin ) ;
V_6:
return V_51 ;
}
static int F_32 ( unsigned char * V_54 , char T_2 * V_49 ,
int V_55 )
{
int V_56 ;
if ( V_55 < sizeof( int ) )
return - V_52 ;
if ( F_33 ( V_56 , ( int T_2 * ) V_49 ) )
return - V_53 ;
* V_54 = ! ! V_56 ;
return 0 ;
}
static int F_34 ( struct V_4 * V_5 , char T_2 * V_49 ,
int V_55 )
{
int V_51 ;
V_51 = F_32 ( & V_5 -> V_34 , V_49 , V_55 ) ;
if ( V_51 == 0 ) {
if ( V_5 -> V_34 ) {
F_35 ( V_5 ) ;
} else {
F_5 ( V_5 ) ;
V_5 -> V_57 = 0 ;
V_5 -> V_40 = 0 ;
}
}
return V_51 ;
}
static int F_36 ( struct V_4 * V_5 , char T_2 * V_49 ,
int V_55 )
{
int V_58 ;
if ( V_5 -> V_10 )
return - V_59 ;
if ( V_55 != sizeof( int ) )
return - V_52 ;
if ( F_31 ( & V_58 , ( int T_2 * ) V_49 , sizeof( V_58 ) ) )
return - V_53 ;
if ( V_58 < 0 || V_58 >= V_60 )
return - V_52 ;
V_5 -> V_10 = F_37 ( V_58 ) ;
return V_5 -> V_10 ? 0 : - V_61 ;
}
static int F_38 ( struct V_2 * V_3 , char T_2 * V_49 ,
int V_55 )
{
int V_62 , V_63 ;
if ( V_55 != sizeof( int ) )
return - V_53 ;
if ( F_33 ( V_62 , ( int T_2 * ) V_49 ) )
return - V_53 ;
V_63 = V_62 ? 1 : 0 ;
if ( V_63 )
F_39 ( V_3 , V_64 ) ;
else
F_40 ( V_3 , V_64 ) ;
return 0 ;
}
static int F_41 ( struct V_4 * V_5 , char T_2 * V_49 ,
int V_55 )
{
struct V_65 V_66 ;
int V_67 ;
if ( V_55 != sizeof( struct V_65 ) )
return - V_53 ;
if ( F_31 ( & V_66 , V_49 , sizeof( V_66 ) ) )
return - V_53 ;
if ( V_66 . V_68 > V_69 )
return - V_53 ;
V_5 -> V_70 = V_66 . V_68 ;
for ( V_67 = 0 ; V_67 < V_5 -> V_70 ; V_67 ++ ) {
if ( V_66 . V_71 [ V_67 ] > V_69 ) {
V_5 -> V_70 = 0 ;
return - V_53 ;
}
V_5 -> V_72 [ V_67 ] = V_66 . V_71 [ V_67 ] ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , int V_73 , int V_74 ,
char T_2 * V_49 , unsigned int V_55 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_3 ) ;
int V_51 ;
if ( V_73 != V_75 ) {
V_51 = - V_61 ;
goto V_6;
}
switch ( V_74 ) {
case V_76 :
V_51 = F_30 ( V_5 , V_49 , V_55 ) ;
break;
case V_77 :
V_51 = F_43 ( V_5 , V_49 , V_55 ) ;
break;
case V_78 :
V_51 = F_44 ( V_5 , V_49 , V_55 ) ;
break;
case V_79 :
V_51 = F_45 ( V_5 , V_49 , V_55 ) ;
break;
case V_80 :
V_51 = F_32 ( & V_5 -> V_81 , V_49 , V_55 ) ;
break;
case V_82 :
V_51 = F_34 ( V_5 , V_49 , V_55 ) ;
break;
case V_83 :
F_46 ( V_2 -> V_3 ) ;
V_51 = F_36 ( V_5 , V_49 , V_55 ) ;
F_47 ( V_2 -> V_3 ) ;
break;
case V_84 :
F_46 ( V_2 -> V_3 ) ;
V_51 = F_38 ( V_2 -> V_3 , V_49 , V_55 ) ;
F_47 ( V_2 -> V_3 ) ;
break;
case V_85 :
V_51 = F_41 ( V_5 , V_49 , V_55 ) ;
break;
default:
V_51 = - V_61 ;
}
V_6:
return V_51 ;
}
static int F_48 ( struct V_1 * V_2 , int V_73 , int V_74 ,
char T_2 * V_49 , int T_2 * V_55 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_3 ) ;
int V_51 = - V_61 , V_50 ;
int V_86 ;
if ( V_73 != V_75 )
goto V_6;
if ( F_33 ( V_50 , V_55 ) ) {
V_51 = - V_53 ;
goto V_6;
}
switch ( V_74 ) {
case V_87 ... V_88 :
V_51 = F_49 ( V_2 , V_74 , V_49 ,
V_55 ) ;
break;
case V_80 :
if ( V_50 < sizeof( int ) )
V_51 = - V_52 ;
else
if ( F_50 ( V_5 -> V_81 , ( int T_2 * ) V_49 ) ||
F_50 ( sizeof( int ) , V_55 ) )
V_51 = - V_53 ;
else
V_51 = 0 ;
break;
case V_83 :
if ( V_50 < sizeof( int ) ) {
V_51 = - V_52 ;
break;
}
V_86 = ( V_5 -> V_10 ? V_5 -> V_10 -> V_58 :
V_89 ) ;
if ( F_50 ( V_86 , ( int T_2 * ) V_49 ) ||
F_50 ( sizeof( int ) , V_55 ) )
V_51 = - V_53 ;
else
V_51 = 0 ;
break;
default:
break;
}
V_6:
return V_51 ;
}
static int F_51 ( struct V_1 * V_2 , struct V_13 * V_14 ,
int V_90 , int V_11 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_17 * sin = (struct V_17 * ) V_14 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_51 = 0 ;
F_46 ( V_3 ) ;
if ( V_90 != sizeof( struct V_17 ) ) {
V_51 = - V_52 ;
goto V_6;
}
if ( sin -> V_27 != V_28 ) {
V_51 = - V_91 ;
goto V_6;
}
if ( sin -> V_23 . V_24 == F_52 ( V_92 ) ) {
V_51 = - V_93 ;
goto V_6;
}
V_5 -> V_19 = sin -> V_23 . V_24 ;
V_5 -> V_22 = sin -> V_21 ;
V_6:
F_47 ( V_3 ) ;
return V_51 ;
}
static void F_53 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_54 ( ( & V_5 -> V_8 != V_5 -> V_8 . V_94 ||
& V_5 -> V_8 != V_5 -> V_8 . V_95 ) ) ;
}
static int F_55 ( struct V_1 * V_2 , struct V_2 * V_3 , int V_96 )
{
struct V_4 * V_5 ;
F_56 ( V_2 , V_3 ) ;
V_2 -> V_97 = & V_98 ;
V_3 -> V_99 = V_96 ;
V_3 -> V_100 = F_53 ;
V_5 = F_2 ( V_3 ) ;
F_57 ( & V_5 -> V_39 ) ;
F_58 ( & V_5 -> V_12 ) ;
F_59 ( & V_5 -> V_101 ) ;
F_59 ( & V_5 -> V_41 ) ;
F_59 ( & V_5 -> V_42 ) ;
F_59 ( & V_5 -> V_102 ) ;
F_57 ( & V_5 -> V_103 ) ;
V_5 -> V_104 = V_105 ;
V_5 -> V_70 = 0 ;
F_10 ( & V_7 ) ;
F_60 ( & V_5 -> V_8 , & V_106 ) ;
V_9 ++ ;
F_12 ( & V_7 ) ;
return 0 ;
}
static int F_61 ( struct V_107 * V_107 , struct V_1 * V_2 , int V_96 ,
int V_108 )
{
struct V_2 * V_3 ;
if ( V_2 -> type != V_109 || V_96 )
return - V_110 ;
V_3 = F_62 ( V_107 , V_111 , V_112 , & V_113 , V_108 ) ;
if ( ! V_3 )
return - V_114 ;
return F_55 ( V_2 , V_3 , V_96 ) ;
}
void F_63 ( struct V_4 * V_5 )
{
F_64 ( F_18 ( V_5 ) ) ;
}
void F_65 ( struct V_4 * V_5 )
{
F_14 ( F_18 ( V_5 ) ) ;
}
static void F_66 ( struct V_1 * V_2 , unsigned int V_50 ,
struct V_115 * V_116 ,
struct V_117 * V_118 )
{
struct V_4 * V_5 ;
struct V_119 * V_120 ;
unsigned int V_121 = 0 ;
V_50 /= sizeof( struct V_122 ) ;
F_10 ( & V_7 ) ;
F_67 (rs, &rds_sock_list, rs_item) {
F_68 ( & V_5 -> V_12 ) ;
F_67 (inc, &rs->rs_recv_queue, i_item) {
V_121 ++ ;
if ( V_121 <= V_50 )
F_69 ( V_120 , V_116 , V_120 -> V_123 ,
V_5 -> V_26 , 1 ) ;
}
F_70 ( & V_5 -> V_12 ) ;
}
F_12 ( & V_7 ) ;
V_118 -> V_124 = V_121 ;
V_118 -> V_125 = sizeof( struct V_122 ) ;
}
static void F_71 ( struct V_1 * V_2 , unsigned int V_50 ,
struct V_115 * V_116 ,
struct V_117 * V_118 )
{
struct V_126 V_127 ;
struct V_4 * V_5 ;
V_50 /= sizeof( struct V_126 ) ;
F_10 ( & V_7 ) ;
if ( V_50 < V_9 )
goto V_6;
F_67 (rs, &rds_sock_list, rs_item) {
V_127 . V_128 = F_28 ( V_5 ) ;
V_127 . V_129 = F_72 ( V_5 ) ;
V_127 . V_130 = V_5 -> V_26 ;
V_127 . V_131 = V_5 -> V_19 ;
V_127 . V_132 = V_5 -> V_25 ;
V_127 . V_133 = V_5 -> V_22 ;
V_127 . V_134 = F_73 ( F_18 ( V_5 ) ) ;
F_74 ( V_116 , & V_127 , sizeof( V_127 ) ) ;
}
V_6:
V_118 -> V_124 = V_9 ;
V_118 -> V_125 = sizeof( struct V_126 ) ;
F_12 ( & V_7 ) ;
}
static void F_75 ( void )
{
F_76 ( V_135 . V_136 ) ;
F_77 ( & V_113 ) ;
F_78 () ;
F_79 () ;
F_80 () ;
F_81 () ;
F_82 () ;
F_83 () ;
F_84 () ;
F_85 ( V_137 , F_71 ) ;
F_85 ( V_138 , F_66 ) ;
}
static int F_86 ( void )
{
int V_51 ;
F_87 ( & V_139 , sizeof( V_139 ) ) ;
V_51 = F_88 () ;
if ( V_51 )
goto V_6;
V_51 = F_89 () ;
if ( V_51 )
goto V_140;
V_51 = F_90 () ;
if ( V_51 )
goto V_141;
V_51 = F_91 () ;
if ( V_51 )
goto V_142;
V_51 = F_92 () ;
if ( V_51 )
goto V_143;
V_51 = F_93 ( & V_113 , 1 ) ;
if ( V_51 )
goto V_144;
V_51 = F_94 ( & V_135 ) ;
if ( V_51 )
goto V_145;
F_95 ( V_137 , F_71 ) ;
F_95 ( V_138 , F_66 ) ;
goto V_6;
V_145:
F_77 ( & V_113 ) ;
V_144:
F_82 () ;
V_143:
F_80 () ;
V_142:
F_81 () ;
V_141:
F_78 () ;
F_79 () ;
F_83 () ;
V_140:
F_84 () ;
V_6:
return V_51 ;
}
