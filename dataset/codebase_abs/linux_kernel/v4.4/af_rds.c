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
static int F_38 ( struct V_1 * V_2 , int V_62 , int V_63 ,
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
V_51 = F_30 ( V_5 , V_49 , V_55 ) ;
break;
case V_66 :
V_51 = F_39 ( V_5 , V_49 , V_55 ) ;
break;
case V_67 :
V_51 = F_40 ( V_5 , V_49 , V_55 ) ;
break;
case V_68 :
V_51 = F_41 ( V_5 , V_49 , V_55 ) ;
break;
case V_69 :
V_51 = F_32 ( & V_5 -> V_70 , V_49 , V_55 ) ;
break;
case V_71 :
V_51 = F_34 ( V_5 , V_49 , V_55 ) ;
break;
case V_72 :
F_42 ( V_2 -> V_3 ) ;
V_51 = F_36 ( V_5 , V_49 , V_55 ) ;
F_43 ( V_2 -> V_3 ) ;
break;
default:
V_51 = - V_61 ;
}
V_6:
return V_51 ;
}
static int F_44 ( struct V_1 * V_2 , int V_62 , int V_63 ,
char T_2 * V_49 , int T_2 * V_55 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_3 ) ;
int V_51 = - V_61 , V_50 ;
int V_73 ;
if ( V_62 != V_64 )
goto V_6;
if ( F_33 ( V_50 , V_55 ) ) {
V_51 = - V_53 ;
goto V_6;
}
switch ( V_63 ) {
case V_74 ... V_75 :
V_51 = F_45 ( V_2 , V_63 , V_49 ,
V_55 ) ;
break;
case V_69 :
if ( V_50 < sizeof( int ) )
V_51 = - V_52 ;
else
if ( F_46 ( V_5 -> V_70 , ( int T_2 * ) V_49 ) ||
F_46 ( sizeof( int ) , V_55 ) )
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
if ( F_46 ( V_73 , ( int T_2 * ) V_49 ) ||
F_46 ( sizeof( int ) , V_55 ) )
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
static int F_47 ( struct V_1 * V_2 , struct V_13 * V_14 ,
int V_77 , int V_11 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
struct V_17 * sin = (struct V_17 * ) V_14 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_51 = 0 ;
F_42 ( V_3 ) ;
if ( V_77 != sizeof( struct V_17 ) ) {
V_51 = - V_52 ;
goto V_6;
}
if ( sin -> V_27 != V_28 ) {
V_51 = - V_78 ;
goto V_6;
}
if ( sin -> V_23 . V_24 == F_48 ( V_79 ) ) {
V_51 = - V_80 ;
goto V_6;
}
V_5 -> V_19 = sin -> V_23 . V_24 ;
V_5 -> V_22 = sin -> V_21 ;
V_6:
F_43 ( V_3 ) ;
return V_51 ;
}
static void F_49 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_50 ( ( & V_5 -> V_8 != V_5 -> V_8 . V_81 ||
& V_5 -> V_8 != V_5 -> V_8 . V_82 ) ) ;
}
static int F_51 ( struct V_1 * V_2 , struct V_2 * V_3 , int V_83 )
{
struct V_4 * V_5 ;
F_52 ( V_2 , V_3 ) ;
V_2 -> V_84 = & V_85 ;
V_3 -> V_86 = V_83 ;
V_3 -> V_87 = F_49 ;
V_5 = F_2 ( V_3 ) ;
F_53 ( & V_5 -> V_39 ) ;
F_54 ( & V_5 -> V_12 ) ;
F_55 ( & V_5 -> V_88 ) ;
F_55 ( & V_5 -> V_41 ) ;
F_55 ( & V_5 -> V_42 ) ;
F_55 ( & V_5 -> V_89 ) ;
F_53 ( & V_5 -> V_90 ) ;
V_5 -> V_91 = V_92 ;
F_10 ( & V_7 ) ;
F_56 ( & V_5 -> V_8 , & V_93 ) ;
V_9 ++ ;
F_12 ( & V_7 ) ;
return 0 ;
}
static int F_57 ( struct V_94 * V_94 , struct V_1 * V_2 , int V_83 ,
int V_95 )
{
struct V_2 * V_3 ;
if ( V_2 -> type != V_96 || V_83 )
return - V_97 ;
V_3 = F_58 ( V_94 , V_98 , V_99 , & V_100 , V_95 ) ;
if ( ! V_3 )
return - V_101 ;
return F_51 ( V_2 , V_3 , V_83 ) ;
}
void F_59 ( struct V_4 * V_5 )
{
F_60 ( F_18 ( V_5 ) ) ;
}
void F_61 ( struct V_4 * V_5 )
{
F_14 ( F_18 ( V_5 ) ) ;
}
static void F_62 ( struct V_1 * V_2 , unsigned int V_50 ,
struct V_102 * V_103 ,
struct V_104 * V_105 )
{
struct V_4 * V_5 ;
struct V_106 * V_107 ;
unsigned int V_108 = 0 ;
V_50 /= sizeof( struct V_109 ) ;
F_10 ( & V_7 ) ;
F_63 (rs, &rds_sock_list, rs_item) {
F_64 ( & V_5 -> V_12 ) ;
F_63 (inc, &rs->rs_recv_queue, i_item) {
V_108 ++ ;
if ( V_108 <= V_50 )
F_65 ( V_107 , V_103 , V_107 -> V_110 ,
V_5 -> V_26 , 1 ) ;
}
F_66 ( & V_5 -> V_12 ) ;
}
F_12 ( & V_7 ) ;
V_105 -> V_111 = V_108 ;
V_105 -> V_112 = sizeof( struct V_109 ) ;
}
static void F_67 ( struct V_1 * V_2 , unsigned int V_50 ,
struct V_102 * V_103 ,
struct V_104 * V_105 )
{
struct V_113 V_114 ;
struct V_4 * V_5 ;
V_50 /= sizeof( struct V_113 ) ;
F_10 ( & V_7 ) ;
if ( V_50 < V_9 )
goto V_6;
F_63 (rs, &rds_sock_list, rs_item) {
V_114 . V_115 = F_28 ( V_5 ) ;
V_114 . V_116 = F_68 ( V_5 ) ;
V_114 . V_117 = V_5 -> V_26 ;
V_114 . V_118 = V_5 -> V_19 ;
V_114 . V_119 = V_5 -> V_25 ;
V_114 . V_120 = V_5 -> V_22 ;
V_114 . V_121 = F_69 ( F_18 ( V_5 ) ) ;
F_70 ( V_103 , & V_114 , sizeof( V_114 ) ) ;
}
V_6:
V_105 -> V_111 = V_9 ;
V_105 -> V_112 = sizeof( struct V_113 ) ;
F_12 ( & V_7 ) ;
}
static void F_71 ( void )
{
F_72 ( V_122 . V_123 ) ;
F_73 ( & V_100 ) ;
F_74 () ;
F_75 () ;
F_76 () ;
F_77 () ;
F_78 () ;
F_79 () ;
F_80 () ;
F_81 ( V_124 , F_67 ) ;
F_81 ( V_125 , F_62 ) ;
}
static int F_82 ( void )
{
int V_51 ;
V_51 = F_83 () ;
if ( V_51 )
goto V_6;
V_51 = F_84 () ;
if ( V_51 )
goto V_126;
V_51 = F_85 () ;
if ( V_51 )
goto V_127;
V_51 = F_86 () ;
if ( V_51 )
goto V_128;
V_51 = F_87 () ;
if ( V_51 )
goto V_129;
V_51 = F_88 ( & V_100 , 1 ) ;
if ( V_51 )
goto V_130;
V_51 = F_89 ( & V_122 ) ;
if ( V_51 )
goto V_131;
F_90 ( V_124 , F_67 ) ;
F_90 ( V_125 , F_62 ) ;
goto V_6;
V_131:
F_73 ( & V_100 ) ;
V_130:
F_78 () ;
V_129:
F_76 () ;
V_128:
F_77 () ;
V_127:
F_74 () ;
F_75 () ;
F_79 () ;
V_126:
F_80 () ;
V_6:
return V_51 ;
}
