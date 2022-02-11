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
F_7 () ;
F_8 ( V_5 , NULL ) ;
F_9 ( V_5 ) ;
F_10 ( V_5 , NULL ) ;
F_11 ( & V_7 ) ;
F_12 ( & V_5 -> V_8 ) ;
V_9 -- ;
F_13 ( & V_7 ) ;
F_14 ( V_5 -> V_10 ) ;
V_2 -> V_3 = NULL ;
F_15 ( V_3 ) ;
V_6:
return 0 ;
}
void F_16 ( struct V_4 * V_5 )
{
unsigned long V_11 ;
F_17 ( & V_5 -> V_12 , V_11 ) ;
F_18 ( F_19 ( V_5 ) ) ;
F_20 ( & V_5 -> V_12 , V_11 ) ;
}
static int F_21 ( struct V_1 * V_2 , struct V_13 * V_14 ,
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
static unsigned int F_22 ( struct V_29 * V_29 , struct V_1 * V_2 ,
T_1 * V_30 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
unsigned int V_31 = 0 ;
unsigned long V_11 ;
F_23 ( V_29 , F_24 ( V_3 ) , V_30 ) ;
if ( V_5 -> V_32 )
F_23 ( V_29 , & V_33 , V_30 ) ;
F_17 ( & V_5 -> V_12 , V_11 ) ;
if ( ! V_5 -> V_34 ) {
if ( F_25 ( & V_5 -> V_35 ) )
V_31 |= ( V_36 | V_37 | V_38 ) ;
} else {
F_26 ( & V_5 -> V_39 ) ;
if ( V_5 -> V_40 )
V_31 |= ( V_36 | V_37 ) ;
F_27 ( & V_5 -> V_39 ) ;
}
if ( ! F_28 ( & V_5 -> V_41 ) ||
! F_28 ( & V_5 -> V_42 ) )
V_31 |= ( V_36 | V_37 ) ;
if ( V_5 -> V_43 < F_29 ( V_5 ) )
V_31 |= ( V_44 | V_45 ) ;
F_20 ( & V_5 -> V_12 , V_11 ) ;
if ( V_31 )
V_5 -> V_32 = 0 ;
return V_31 ;
}
static int F_30 ( struct V_1 * V_2 , unsigned int V_46 , unsigned long V_47 )
{
return - V_48 ;
}
static int F_31 ( struct V_4 * V_5 , char T_2 * V_49 ,
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
if ( F_32 ( & sin , V_49 , sizeof( sin ) ) ) {
V_51 = - V_53 ;
goto V_6;
}
F_8 ( V_5 , & sin ) ;
V_6:
return V_51 ;
}
static int F_33 ( unsigned char * V_54 , char T_2 * V_49 ,
int V_55 )
{
int V_56 ;
if ( V_55 < sizeof( int ) )
return - V_52 ;
if ( F_34 ( V_56 , ( int T_2 * ) V_49 ) )
return - V_53 ;
* V_54 = ! ! V_56 ;
return 0 ;
}
static int F_35 ( struct V_4 * V_5 , char T_2 * V_49 ,
int V_55 )
{
int V_51 ;
V_51 = F_33 ( & V_5 -> V_34 , V_49 , V_55 ) ;
if ( V_51 == 0 ) {
if ( V_5 -> V_34 ) {
F_36 ( V_5 ) ;
} else {
F_5 ( V_5 ) ;
V_5 -> V_57 = 0 ;
V_5 -> V_40 = 0 ;
}
}
return V_51 ;
}
static int F_37 ( struct V_4 * V_5 , char T_2 * V_49 ,
int V_55 )
{
int V_58 ;
if ( V_5 -> V_10 )
return - V_59 ;
if ( V_55 != sizeof( int ) )
return - V_52 ;
if ( F_32 ( & V_58 , ( int T_2 * ) V_49 , sizeof( V_58 ) ) )
return - V_53 ;
if ( V_58 < 0 || V_58 >= V_60 )
return - V_52 ;
V_5 -> V_10 = F_38 ( V_58 ) ;
return V_5 -> V_10 ? 0 : - V_61 ;
}
static int F_39 ( struct V_1 * V_2 , int V_62 , int V_63 ,
char T_2 * V_49 , unsigned int V_55 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_3 ) ;
int V_51 ;
if ( V_62 != V_64 ) {
V_51 = - V_61 ;
goto V_6;
}
switch ( V_63 ) {
case V_65 :
V_51 = F_31 ( V_5 , V_49 , V_55 ) ;
break;
case V_66 :
V_51 = F_40 ( V_5 , V_49 , V_55 ) ;
break;
case V_67 :
V_51 = F_41 ( V_5 , V_49 , V_55 ) ;
break;
case V_68 :
V_51 = F_42 ( V_5 , V_49 , V_55 ) ;
break;
case V_69 :
V_51 = F_33 ( & V_5 -> V_70 , V_49 , V_55 ) ;
break;
case V_71 :
V_51 = F_35 ( V_5 , V_49 , V_55 ) ;
break;
case V_72 :
F_43 ( V_2 -> V_3 ) ;
V_51 = F_37 ( V_5 , V_49 , V_55 ) ;
F_44 ( V_2 -> V_3 ) ;
break;
default:
V_51 = - V_61 ;
}
V_6:
return V_51 ;
}
static int F_45 ( struct V_1 * V_2 , int V_62 , int V_63 ,
char T_2 * V_49 , int T_2 * V_55 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_3 ) ;
int V_51 = - V_61 , V_50 ;
int V_73 ;
if ( V_62 != V_64 )
goto V_6;
if ( F_34 ( V_50 , V_55 ) ) {
V_51 = - V_53 ;
goto V_6;
}
switch ( V_63 ) {
case V_74 ... V_75 :
V_51 = F_46 ( V_2 , V_63 , V_49 ,
V_55 ) ;
break;
case V_69 :
if ( V_50 < sizeof( int ) )
V_51 = - V_52 ;
else
if ( F_47 ( V_5 -> V_70 , ( int T_2 * ) V_49 ) ||
F_47 ( sizeof( int ) , V_55 ) )
V_51 = - V_53 ;
else
V_51 = 0 ;
break;
case V_72 :
if ( V_50 < sizeof( int ) ) {
V_51 = - V_52 ;
break;
}
V_73 = ( V_5 -> V_10 ? V_5 -> V_10 -> V_58 :
V_76 ) ;
if ( F_47 ( V_73 , ( int T_2 * ) V_49 ) ||
F_47 ( sizeof( int ) , V_55 ) )
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
static int F_48 ( struct V_1 * V_2 , struct V_13 * V_14 ,
int V_77 , int V_11 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_17 * sin = (struct V_17 * ) V_14 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_51 = 0 ;
F_43 ( V_3 ) ;
if ( V_77 != sizeof( struct V_17 ) ) {
V_51 = - V_52 ;
goto V_6;
}
if ( sin -> V_27 != V_28 ) {
V_51 = - V_78 ;
goto V_6;
}
if ( sin -> V_23 . V_24 == F_49 ( V_79 ) ) {
V_51 = - V_80 ;
goto V_6;
}
V_5 -> V_19 = sin -> V_23 . V_24 ;
V_5 -> V_22 = sin -> V_21 ;
V_6:
F_44 ( V_3 ) ;
return V_51 ;
}
static int F_50 ( struct V_1 * V_2 , struct V_2 * V_3 , int V_81 )
{
struct V_4 * V_5 ;
F_51 ( V_2 , V_3 ) ;
V_2 -> V_82 = & V_83 ;
V_3 -> V_84 = V_81 ;
V_5 = F_2 ( V_3 ) ;
F_52 ( & V_5 -> V_39 ) ;
F_53 ( & V_5 -> V_12 ) ;
F_54 ( & V_5 -> V_85 ) ;
F_54 ( & V_5 -> V_41 ) ;
F_54 ( & V_5 -> V_42 ) ;
F_54 ( & V_5 -> V_86 ) ;
F_52 ( & V_5 -> V_87 ) ;
V_5 -> V_88 = V_89 ;
F_11 ( & V_7 ) ;
F_55 ( & V_5 -> V_8 , & V_90 ) ;
V_9 ++ ;
F_13 ( & V_7 ) ;
return 0 ;
}
static int F_56 ( struct V_91 * V_91 , struct V_1 * V_2 , int V_81 ,
int V_92 )
{
struct V_2 * V_3 ;
if ( V_2 -> type != V_93 || V_81 )
return - V_94 ;
V_3 = F_57 ( V_91 , V_95 , V_96 , & V_97 , V_92 ) ;
if ( ! V_3 )
return - V_98 ;
return F_50 ( V_2 , V_3 , V_81 ) ;
}
void F_58 ( struct V_4 * V_5 )
{
F_59 ( F_19 ( V_5 ) ) ;
}
void F_60 ( struct V_4 * V_5 )
{
F_15 ( F_19 ( V_5 ) ) ;
}
static void F_61 ( struct V_1 * V_2 , unsigned int V_50 ,
struct V_99 * V_100 ,
struct V_101 * V_102 )
{
struct V_4 * V_5 ;
struct V_103 * V_104 ;
unsigned int V_105 = 0 ;
V_50 /= sizeof( struct V_106 ) ;
F_11 ( & V_7 ) ;
F_62 (rs, &rds_sock_list, rs_item) {
F_63 ( & V_5 -> V_12 ) ;
F_62 (inc, &rs->rs_recv_queue, i_item) {
V_105 ++ ;
if ( V_105 <= V_50 )
F_64 ( V_104 , V_100 , V_104 -> V_107 ,
V_5 -> V_26 , 1 ) ;
}
F_65 ( & V_5 -> V_12 ) ;
}
F_13 ( & V_7 ) ;
V_102 -> V_108 = V_105 ;
V_102 -> V_109 = sizeof( struct V_106 ) ;
}
static void F_66 ( struct V_1 * V_2 , unsigned int V_50 ,
struct V_99 * V_100 ,
struct V_101 * V_102 )
{
struct V_110 V_111 ;
struct V_4 * V_5 ;
V_50 /= sizeof( struct V_110 ) ;
F_11 ( & V_7 ) ;
if ( V_50 < V_9 )
goto V_6;
F_62 (rs, &rds_sock_list, rs_item) {
V_111 . V_112 = F_29 ( V_5 ) ;
V_111 . V_113 = F_67 ( V_5 ) ;
V_111 . V_114 = V_5 -> V_26 ;
V_111 . V_115 = V_5 -> V_19 ;
V_111 . V_116 = V_5 -> V_25 ;
V_111 . V_117 = V_5 -> V_22 ;
V_111 . V_118 = F_68 ( F_19 ( V_5 ) ) ;
F_69 ( V_100 , & V_111 , sizeof( V_111 ) ) ;
}
V_6:
V_102 -> V_108 = V_9 ;
V_102 -> V_109 = sizeof( struct V_110 ) ;
F_13 ( & V_7 ) ;
}
static void F_70 ( void )
{
F_71 ( V_119 . V_120 ) ;
F_72 ( & V_97 ) ;
F_73 () ;
F_74 () ;
F_75 () ;
F_76 () ;
F_77 () ;
F_78 () ;
F_79 ( V_121 , F_66 ) ;
F_79 ( V_122 , F_61 ) ;
}
static int F_80 ( void )
{
int V_51 ;
V_51 = F_81 () ;
if ( V_51 )
goto V_6;
V_51 = F_82 () ;
if ( V_51 )
goto V_123;
V_51 = F_83 () ;
if ( V_51 )
goto V_124;
V_51 = F_84 () ;
if ( V_51 )
goto V_125;
V_51 = F_85 ( & V_97 , 1 ) ;
if ( V_51 )
goto V_126;
V_51 = F_86 ( & V_119 ) ;
if ( V_51 )
goto V_127;
F_87 ( V_121 , F_66 ) ;
F_87 ( V_122 , F_61 ) ;
goto V_6;
V_127:
F_72 ( & V_97 ) ;
V_126:
F_77 () ;
V_125:
F_75 () ;
V_124:
F_76 () ;
V_123:
F_73 () ;
F_74 () ;
F_78 () ;
V_6:
return V_51 ;
}
