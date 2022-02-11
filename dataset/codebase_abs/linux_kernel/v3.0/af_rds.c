char * F_1 ( char * * V_1 , T_1 V_2 , T_1 V_3 )
{
if ( ( V_3 < V_2 ) && V_1 [ V_3 ] )
return V_1 [ V_3 ] ;
else
return L_1 ;
}
static int F_2 ( struct V_4 * V_5 )
{
struct V_5 * V_6 = V_5 -> V_6 ;
struct V_7 * V_8 ;
unsigned long V_9 ;
if ( ! V_6 )
goto V_10;
V_8 = F_3 ( V_6 ) ;
F_4 ( V_6 ) ;
F_5 ( V_8 ) ;
F_6 ( V_8 ) ;
F_7 ( V_8 ) ;
F_8 () ;
F_9 ( V_8 , NULL ) ;
F_10 ( V_8 ) ;
F_11 ( V_8 , NULL ) ;
F_12 ( & V_11 , V_9 ) ;
F_13 ( & V_8 -> V_12 ) ;
V_13 -- ;
F_14 ( & V_11 , V_9 ) ;
F_15 ( V_8 -> V_14 ) ;
V_5 -> V_6 = NULL ;
F_16 ( V_6 ) ;
V_10:
return 0 ;
}
void F_17 ( struct V_7 * V_8 )
{
unsigned long V_9 ;
F_18 ( & V_8 -> V_15 , V_9 ) ;
F_19 ( F_20 ( V_8 ) ) ;
F_21 ( & V_8 -> V_15 , V_9 ) ;
}
static int F_22 ( struct V_4 * V_5 , struct V_16 * V_17 ,
int * V_18 , int V_19 )
{
struct V_20 * sin = (struct V_20 * ) V_17 ;
struct V_7 * V_8 = F_3 ( V_5 -> V_6 ) ;
memset ( sin -> V_21 , 0 , sizeof( sin -> V_21 ) ) ;
if ( V_19 ) {
if ( ! V_8 -> V_22 )
return - V_23 ;
sin -> V_24 = V_8 -> V_25 ;
sin -> V_26 . V_27 = V_8 -> V_22 ;
} else {
sin -> V_24 = V_8 -> V_28 ;
sin -> V_26 . V_27 = V_8 -> V_29 ;
}
sin -> V_30 = V_31 ;
* V_18 = sizeof( * sin ) ;
return 0 ;
}
static unsigned int F_23 ( struct V_32 * V_32 , struct V_4 * V_5 ,
T_2 * V_33 )
{
struct V_5 * V_6 = V_5 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
unsigned int V_34 = 0 ;
unsigned long V_9 ;
F_24 ( V_32 , F_25 ( V_6 ) , V_33 ) ;
if ( V_8 -> V_35 )
F_24 ( V_32 , & V_36 , V_33 ) ;
F_18 ( & V_8 -> V_15 , V_9 ) ;
if ( ! V_8 -> V_37 ) {
if ( F_26 ( & V_8 -> V_38 ) )
V_34 |= ( V_39 | V_40 | V_41 ) ;
} else {
F_27 ( & V_8 -> V_42 ) ;
if ( V_8 -> V_43 )
V_34 |= ( V_39 | V_40 ) ;
F_28 ( & V_8 -> V_42 ) ;
}
if ( ! F_29 ( & V_8 -> V_44 ) ||
! F_29 ( & V_8 -> V_45 ) )
V_34 |= ( V_39 | V_40 ) ;
if ( V_8 -> V_46 < F_30 ( V_8 ) )
V_34 |= ( V_47 | V_48 ) ;
F_21 ( & V_8 -> V_15 , V_9 ) ;
if ( V_34 )
V_8 -> V_35 = 0 ;
return V_34 ;
}
static int F_31 ( struct V_4 * V_5 , unsigned int V_49 , unsigned long V_50 )
{
return - V_51 ;
}
static int F_32 ( struct V_7 * V_8 , char T_3 * V_52 ,
int V_53 )
{
struct V_20 sin ;
int V_54 = 0 ;
if ( V_8 -> V_29 == 0 ) {
V_54 = - V_23 ;
goto V_10;
}
if ( V_53 < sizeof( struct V_20 ) ) {
V_54 = - V_55 ;
goto V_10;
}
if ( F_33 ( & sin , V_52 , sizeof( sin ) ) ) {
V_54 = - V_56 ;
goto V_10;
}
F_9 ( V_8 , & sin ) ;
V_10:
return V_54 ;
}
static int F_34 ( unsigned char * V_57 , char T_3 * V_52 ,
int V_58 )
{
int V_59 ;
if ( V_58 < sizeof( int ) )
return - V_55 ;
if ( F_35 ( V_59 , ( int T_3 * ) V_52 ) )
return - V_56 ;
* V_57 = ! ! V_59 ;
return 0 ;
}
static int F_36 ( struct V_7 * V_8 , char T_3 * V_52 ,
int V_58 )
{
int V_54 ;
V_54 = F_34 ( & V_8 -> V_37 , V_52 , V_58 ) ;
if ( V_54 == 0 ) {
if ( V_8 -> V_37 ) {
F_37 ( V_8 ) ;
} else {
F_6 ( V_8 ) ;
V_8 -> V_60 = 0 ;
V_8 -> V_43 = 0 ;
}
}
return V_54 ;
}
static int F_38 ( struct V_4 * V_5 , int V_61 , int V_62 ,
char T_3 * V_52 , unsigned int V_58 )
{
struct V_7 * V_8 = F_3 ( V_5 -> V_6 ) ;
int V_54 ;
if ( V_61 != V_63 ) {
V_54 = - V_64 ;
goto V_10;
}
switch ( V_62 ) {
case V_65 :
V_54 = F_32 ( V_8 , V_52 , V_58 ) ;
break;
case V_66 :
V_54 = F_39 ( V_8 , V_52 , V_58 ) ;
break;
case V_67 :
V_54 = F_40 ( V_8 , V_52 , V_58 ) ;
break;
case V_68 :
V_54 = F_41 ( V_8 , V_52 , V_58 ) ;
break;
case V_69 :
V_54 = F_34 ( & V_8 -> V_70 , V_52 , V_58 ) ;
break;
case V_71 :
V_54 = F_36 ( V_8 , V_52 , V_58 ) ;
break;
default:
V_54 = - V_64 ;
}
V_10:
return V_54 ;
}
static int F_42 ( struct V_4 * V_5 , int V_61 , int V_62 ,
char T_3 * V_52 , int T_3 * V_58 )
{
struct V_7 * V_8 = F_3 ( V_5 -> V_6 ) ;
int V_54 = - V_64 , V_53 ;
if ( V_61 != V_63 )
goto V_10;
if ( F_35 ( V_53 , V_58 ) ) {
V_54 = - V_56 ;
goto V_10;
}
switch ( V_62 ) {
case V_72 ... V_73 :
V_54 = F_43 ( V_5 , V_62 , V_52 ,
V_58 ) ;
break;
case V_69 :
if ( V_53 < sizeof( int ) )
V_54 = - V_55 ;
else
if ( F_44 ( V_8 -> V_70 , ( int T_3 * ) V_52 ) ||
F_44 ( sizeof( int ) , V_58 ) )
V_54 = - V_56 ;
else
V_54 = 0 ;
break;
default:
break;
}
V_10:
return V_54 ;
}
static int F_45 ( struct V_4 * V_5 , struct V_16 * V_17 ,
int V_74 , int V_9 )
{
struct V_5 * V_6 = V_5 -> V_6 ;
struct V_20 * sin = (struct V_20 * ) V_17 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_54 = 0 ;
F_46 ( V_6 ) ;
if ( V_74 != sizeof( struct V_20 ) ) {
V_54 = - V_55 ;
goto V_10;
}
if ( sin -> V_30 != V_31 ) {
V_54 = - V_75 ;
goto V_10;
}
if ( sin -> V_26 . V_27 == F_47 ( V_76 ) ) {
V_54 = - V_77 ;
goto V_10;
}
V_8 -> V_22 = sin -> V_26 . V_27 ;
V_8 -> V_25 = sin -> V_24 ;
V_10:
F_48 ( V_6 ) ;
return V_54 ;
}
static int F_49 ( struct V_4 * V_5 , struct V_5 * V_6 , int V_78 )
{
unsigned long V_9 ;
struct V_7 * V_8 ;
F_50 ( V_5 , V_6 ) ;
V_5 -> V_79 = & V_80 ;
V_6 -> V_81 = V_78 ;
V_8 = F_3 ( V_6 ) ;
F_51 ( & V_8 -> V_42 ) ;
F_52 ( & V_8 -> V_15 ) ;
F_53 ( & V_8 -> V_82 ) ;
F_53 ( & V_8 -> V_44 ) ;
F_53 ( & V_8 -> V_45 ) ;
F_53 ( & V_8 -> V_83 ) ;
F_51 ( & V_8 -> V_84 ) ;
V_8 -> V_85 = V_86 ;
F_12 ( & V_11 , V_9 ) ;
F_54 ( & V_8 -> V_12 , & V_87 ) ;
V_13 ++ ;
F_14 ( & V_11 , V_9 ) ;
return 0 ;
}
static int F_55 ( struct V_88 * V_88 , struct V_4 * V_5 , int V_78 ,
int V_89 )
{
struct V_5 * V_6 ;
if ( V_5 -> type != V_90 || V_78 )
return - V_91 ;
V_6 = F_56 ( V_88 , V_92 , V_93 , & V_94 ) ;
if ( ! V_6 )
return - V_95 ;
return F_49 ( V_5 , V_6 , V_78 ) ;
}
void F_57 ( struct V_7 * V_8 )
{
F_58 ( F_20 ( V_8 ) ) ;
}
void F_59 ( struct V_7 * V_8 )
{
F_16 ( F_20 ( V_8 ) ) ;
}
static void F_60 ( struct V_4 * V_5 , unsigned int V_53 ,
struct V_96 * V_97 ,
struct V_98 * V_99 )
{
struct V_7 * V_8 ;
struct V_100 * V_101 ;
unsigned long V_9 ;
unsigned int V_102 = 0 ;
V_53 /= sizeof( struct V_103 ) ;
F_12 ( & V_11 , V_9 ) ;
F_61 (rs, &rds_sock_list, rs_item) {
F_62 ( & V_8 -> V_15 ) ;
F_61 (inc, &rs->rs_recv_queue, i_item) {
V_102 ++ ;
if ( V_102 <= V_53 )
F_63 ( V_101 , V_97 , V_101 -> V_104 ,
V_8 -> V_29 , 1 ) ;
}
F_64 ( & V_8 -> V_15 ) ;
}
F_14 ( & V_11 , V_9 ) ;
V_99 -> V_105 = V_102 ;
V_99 -> V_106 = sizeof( struct V_103 ) ;
}
static void F_65 ( struct V_4 * V_5 , unsigned int V_53 ,
struct V_96 * V_97 ,
struct V_98 * V_99 )
{
struct V_107 V_108 ;
struct V_7 * V_8 ;
unsigned long V_9 ;
V_53 /= sizeof( struct V_107 ) ;
F_12 ( & V_11 , V_9 ) ;
if ( V_53 < V_13 )
goto V_10;
F_61 (rs, &rds_sock_list, rs_item) {
V_108 . V_109 = F_30 ( V_8 ) ;
V_108 . V_110 = F_66 ( V_8 ) ;
V_108 . V_111 = V_8 -> V_29 ;
V_108 . V_112 = V_8 -> V_22 ;
V_108 . V_113 = V_8 -> V_28 ;
V_108 . V_114 = V_8 -> V_25 ;
V_108 . V_115 = F_67 ( F_20 ( V_8 ) ) ;
F_68 ( V_97 , & V_108 , sizeof( V_108 ) ) ;
}
V_10:
V_99 -> V_105 = V_13 ;
V_99 -> V_106 = sizeof( struct V_107 ) ;
F_14 ( & V_11 , V_9 ) ;
}
static void F_69 ( void )
{
F_70 ( V_116 . V_117 ) ;
F_71 ( & V_94 ) ;
F_72 () ;
F_73 () ;
F_74 () ;
F_75 () ;
F_76 () ;
F_77 () ;
F_78 ( V_118 , F_65 ) ;
F_78 ( V_119 , F_60 ) ;
}
static int F_79 ( void )
{
int V_54 ;
V_54 = F_80 () ;
if ( V_54 )
goto V_10;
V_54 = F_81 () ;
if ( V_54 )
goto V_120;
V_54 = F_82 () ;
if ( V_54 )
goto V_121;
V_54 = F_83 () ;
if ( V_54 )
goto V_122;
V_54 = F_84 ( & V_94 , 1 ) ;
if ( V_54 )
goto V_123;
V_54 = F_85 ( & V_116 ) ;
if ( V_54 )
goto V_124;
F_86 ( V_118 , F_65 ) ;
F_86 ( V_119 , F_60 ) ;
goto V_10;
V_124:
F_71 ( & V_94 ) ;
V_123:
F_76 () ;
V_122:
F_74 () ;
V_121:
F_75 () ;
V_120:
F_72 () ;
F_73 () ;
F_77 () ;
V_10:
return V_54 ;
}
