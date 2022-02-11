static int
F_1 ( void T_1 * V_1 )
{
int V_2 = V_3 ;
return F_2 ( V_2 , ( int T_1 * ) V_1 ) ;
}
static int
F_3 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
if ( ! F_4 ( V_8 ) )
return - V_9 ;
V_7 = F_5 ( V_5 -> V_10 ) ;
if ( ! V_7 )
return - V_11 ;
F_6 ( V_7 ) ;
F_7 ( & V_5 -> V_12 ) ;
F_8 ( V_5 -> V_13 ,
( V_14 ) F_9 ( V_7 -> V_15 -> V_16 ) << 9 ) ;
F_10 ( & V_5 -> V_12 ) ;
F_11 ( V_7 ) ;
return 0 ;
}
static int
F_12 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
if ( ! F_4 ( V_8 ) )
return - V_9 ;
V_7 = F_5 ( V_5 -> V_10 ) ;
if ( ! V_7 )
return - V_11 ;
F_13 ( V_7 , V_17 ) ;
F_7 ( & V_5 -> V_12 ) ;
F_8 ( V_5 -> V_13 , 0 ) ;
F_10 ( & V_5 -> V_12 ) ;
F_11 ( V_7 ) ;
return 0 ;
}
static int F_14 ( struct V_18 * V_15 )
{
unsigned long V_19 ;
struct V_6 * V_7 ;
V_7 = V_15 -> V_7 ;
if ( ! F_4 ( V_8 ) )
return - V_9 ;
F_15 ( L_1
L_2 , F_16 ( & V_7 -> V_20 -> V_21 ) ) ;
F_17 ( F_18 ( V_7 -> V_20 ) , V_19 ) ;
F_19 ( V_7 , V_22 ) ;
F_20 ( F_18 ( V_7 -> V_20 ) , V_19 ) ;
return 0 ;
}
static int F_21 ( struct V_18 * V_15 )
{
unsigned long V_19 ;
struct V_6 * V_7 ;
V_7 = V_15 -> V_7 ;
if ( ! F_4 ( V_8 ) )
return - V_9 ;
F_15 ( L_3
L_4 , F_16 ( & V_7 -> V_20 -> V_21 ) ) ;
F_17 ( F_18 ( V_7 -> V_20 ) , V_19 ) ;
F_22 ( V_7 , V_22 ) ;
F_20 ( F_18 ( V_7 -> V_20 ) , V_19 ) ;
F_23 ( V_15 ) ;
return 0 ;
}
static int F_24 ( struct V_18 * V_15 )
{
unsigned long V_19 ;
struct V_6 * V_7 ;
struct V_23 * V_24 , * V_25 ;
V_7 = V_15 -> V_7 ;
if ( ! F_4 ( V_8 ) )
return - V_9 ;
if ( F_25 ( V_26 , & V_7 -> V_19 ) )
return 0 ;
F_26 ( V_27 , V_7 , L_5 , L_6 ) ;
F_17 ( & V_15 -> V_28 , V_19 ) ;
F_27 ( & V_15 -> V_29 ) ;
F_28 (cqr, n, &block->ccw_queue, blocklist) {
if ( F_29 ( V_30 , & V_24 -> V_19 ) &&
V_24 -> V_31 &&
V_24 -> V_31 != V_32 &&
V_24 -> V_31 != V_33 ) {
F_30 ( & V_15 -> V_29 ) ;
F_31 ( V_24 -> V_31 ) ;
F_27 ( & V_15 -> V_29 ) ;
}
}
F_30 ( & V_15 -> V_29 ) ;
F_20 ( & V_15 -> V_28 , V_19 ) ;
F_23 ( V_15 ) ;
return 0 ;
}
static int F_32 ( struct V_18 * V_15 )
{
struct V_6 * V_7 ;
V_7 = V_15 -> V_7 ;
if ( ! F_4 ( V_8 ) )
return - V_9 ;
if ( F_33 ( V_26 , & V_7 -> V_19 ) )
F_26 ( V_27 , V_7 , L_5 , L_7 ) ;
return 0 ;
}
static int
F_34 ( struct V_18 * V_15 , struct V_34 * V_35 )
{
struct V_6 * V_7 ;
int V_36 ;
V_7 = V_15 -> V_7 ;
if ( V_7 -> V_37 -> V_38 == NULL )
return - V_39 ;
if ( V_7 -> V_40 != V_17 ) {
F_35 ( L_8 ,
F_16 ( & V_7 -> V_20 -> V_21 ) ) ;
return - V_41 ;
}
F_26 ( V_27 , V_7 ,
L_9 ,
V_35 -> V_42 ,
V_35 -> V_43 , V_35 -> V_44 , V_35 -> V_45 ) ;
if ( V_35 -> V_42 == 0 ) {
struct V_4 * V_5 = F_36 ( V_15 -> V_16 , 0 ) ;
V_5 -> V_13 -> V_46 = F_37 ( V_35 -> V_44 ) ;
F_38 ( V_5 ) ;
}
V_36 = V_7 -> V_37 -> V_38 ( V_7 , V_35 , 1 ) ;
if ( V_36 == - V_47 )
V_36 = V_7 -> V_37 -> V_38 ( V_7 , V_35 , 0 ) ;
return V_36 ;
}
static int
F_39 ( struct V_4 * V_5 , void T_1 * V_1 )
{
struct V_6 * V_7 ;
struct V_34 V_35 ;
int V_36 ;
if ( ! F_4 ( V_8 ) )
return - V_9 ;
if ( ! V_1 )
return - V_48 ;
V_7 = F_5 ( V_5 -> V_10 ) ;
if ( ! V_7 )
return - V_11 ;
if ( V_7 -> V_49 & V_50 ||
F_29 ( V_51 , & V_7 -> V_19 ) ) {
F_11 ( V_7 ) ;
return - V_52 ;
}
if ( F_40 ( & V_35 , V_1 , sizeof( struct V_34 ) ) ) {
F_11 ( V_7 ) ;
return - V_53 ;
}
if ( V_5 != V_5 -> V_54 ) {
F_35 ( L_10 ,
F_16 ( & V_7 -> V_20 -> V_21 ) ) ;
F_11 ( V_7 ) ;
return - V_48 ;
}
V_36 = F_34 ( V_7 -> V_15 , & V_35 ) ;
F_11 ( V_7 ) ;
return V_36 ;
}
static int F_41 ( struct V_18 * V_15 )
{
F_42 ( & V_15 -> V_55 ) ;
return 0 ;
}
static int F_43 ( struct V_18 * V_15 , void T_1 * V_1 )
{
struct V_56 * V_57 ;
int V_36 = 0 ;
V_57 = F_44 ( sizeof( * V_57 ) , V_58 ) ;
if ( ! V_57 )
return - V_59 ;
F_45 ( & V_15 -> V_55 . V_60 ) ;
if ( V_15 -> V_55 . V_57 ) {
V_57 -> V_61 = V_15 -> V_55 . V_57 -> V_61 ;
V_57 -> V_62 = V_15 -> V_55 . V_57 -> V_62 ;
memcpy ( V_57 -> V_63 , V_15 -> V_55 . V_57 -> V_63 ,
sizeof( V_57 -> V_63 ) ) ;
memcpy ( V_57 -> V_64 , V_15 -> V_55 . V_57 -> V_64 ,
sizeof( V_57 -> V_64 ) ) ;
memcpy ( V_57 -> V_65 , V_15 -> V_55 . V_57 -> V_65 ,
sizeof( V_57 -> V_65 ) ) ;
memcpy ( V_57 -> V_66 , V_15 -> V_55 . V_57 -> V_66 ,
sizeof( V_57 -> V_66 ) ) ;
memcpy ( V_57 -> V_67 , V_15 -> V_55 . V_57 -> V_67 ,
sizeof( V_57 -> V_67 ) ) ;
memcpy ( V_57 -> V_68 ,
V_15 -> V_55 . V_57 -> V_68 ,
sizeof( V_57 -> V_68 ) ) ;
memcpy ( V_57 -> V_69 , V_15 -> V_55 . V_57 -> V_69 ,
sizeof( V_57 -> V_69 ) ) ;
memcpy ( V_57 -> V_70 ,
V_15 -> V_55 . V_57 -> V_70 ,
sizeof( V_57 -> V_70 ) ) ;
F_46 ( & V_15 -> V_55 . V_60 ) ;
} else {
F_46 ( & V_15 -> V_55 . V_60 ) ;
V_36 = - V_71 ;
goto V_72;
}
if ( F_47 ( V_1 , V_57 , sizeof( * V_57 ) ) )
V_36 = - V_53 ;
V_72:
F_48 ( V_57 ) ;
return V_36 ;
}
static int F_41 ( struct V_18 * V_15 )
{
return - V_73 ;
}
static int F_43 ( struct V_18 * V_15 , void T_1 * V_1 )
{
return - V_73 ;
}
static int F_49 ( struct V_18 * V_15 ,
unsigned int V_74 , void T_1 * V_1 )
{
struct V_75 * V_76 ;
struct V_77 V_78 ;
struct V_79 V_80 ;
struct V_6 * V_7 ;
struct V_81 * V_20 ;
unsigned long V_19 ;
int V_36 ;
V_7 = V_15 -> V_7 ;
if ( ! V_7 -> V_37 || ! V_7 -> V_37 -> V_82 )
return - V_48 ;
V_76 = F_50 ( sizeof( struct V_75 ) , V_58 ) ;
if ( V_76 == NULL )
return - V_59 ;
V_36 = V_7 -> V_37 -> V_82 ( V_7 , V_76 ) ;
if ( V_36 ) {
F_48 ( V_76 ) ;
return V_36 ;
}
V_20 = V_7 -> V_20 ;
F_51 ( V_20 , & V_80 ) ;
F_52 ( V_20 , & V_78 ) ;
V_76 -> V_83 = V_80 . V_83 ;
V_76 -> V_84 = V_78 . V_85 ;
V_76 -> V_86 = V_20 -> V_87 . V_86 ;
V_76 -> V_88 = V_20 -> V_87 . V_88 ;
V_76 -> V_89 = V_20 -> V_87 . V_89 ;
V_76 -> V_90 = V_20 -> V_87 . V_90 ;
V_76 -> V_91 = V_7 -> V_40 ;
V_76 -> V_92 = F_53 ( & V_15 -> V_92 ) ;
if ( ! V_15 -> V_5 )
V_76 -> V_92 ++ ;
if ( ( V_7 -> V_40 < V_93 ) ||
( F_54 ( V_15 -> V_94 ) ) )
V_76 -> V_95 = V_96 ;
V_76 -> V_49 |=
( ( V_7 -> V_49 & V_50 ) != 0 ) ;
memcpy ( V_76 -> type , V_7 -> V_37 -> V_97 , 4 ) ;
if ( V_15 -> V_98 -> V_99 ) {
struct V_100 * V_101 ;
#ifdef F_55
{
struct V_100 * V_101 ;
F_17 ( & V_15 -> V_60 , V_19 ) ;
F_56 (l, &block->request_queue->queue_head)
V_76 -> V_102 ++ ;
F_20 ( & V_15 -> V_60 , V_19 ) ;
}
#endif
F_17 ( F_18 ( V_7 -> V_20 ) , V_19 ) ;
F_56 (l, &base->ccw_queue)
V_76 -> V_103 ++ ;
F_20 ( F_18 ( V_7 -> V_20 ) ,
V_19 ) ;
}
V_36 = 0 ;
if ( F_47 ( V_1 , V_76 ,
( ( V_74 == ( unsigned int ) V_104 ) ?
sizeof( struct V_75 ) :
sizeof( struct V_105 ) ) ) )
V_36 = - V_53 ;
F_48 ( V_76 ) ;
return V_36 ;
}
static int
F_57 ( struct V_4 * V_5 , void T_1 * V_1 )
{
struct V_6 * V_7 ;
int V_106 , V_36 ;
if ( ! F_4 ( V_8 ) )
return - V_9 ;
if ( V_5 != V_5 -> V_54 )
return - V_48 ;
if ( F_58 ( V_106 , ( int T_1 * ) V_1 ) )
return - V_53 ;
V_7 = F_5 ( V_5 -> V_10 ) ;
if ( ! V_7 )
return - V_11 ;
if ( ! V_106 && F_29 ( V_51 , & V_7 -> V_19 ) ) {
F_11 ( V_7 ) ;
return - V_52 ;
}
F_59 ( V_5 -> V_10 , V_106 ) ;
V_36 = F_60 ( V_7 -> V_20 , V_50 , V_106 ) ;
F_11 ( V_7 ) ;
return V_36 ;
}
static int F_61 ( struct V_18 * V_15 , unsigned int V_74 ,
struct V_107 T_1 * V_1 )
{
T_2 V_108 = F_62 ( V_74 ) ;
struct V_107 V_57 ;
int V_109 ;
V_109 = F_63 ( V_15 -> V_7 -> V_20 , & V_57 ) ;
if ( ! V_109 && F_47 ( V_1 , & V_57 , F_64 ( V_108 , sizeof( * V_1 ) ) ) )
return - V_53 ;
return V_109 ;
}
int F_65 ( struct V_4 * V_5 , T_3 V_110 ,
unsigned int V_74 , unsigned long V_111 )
{
struct V_18 * V_15 ;
struct V_6 * V_7 ;
void T_1 * V_1 ;
int V_36 ;
if ( F_66 () )
V_1 = F_67 ( V_111 ) ;
else
V_1 = ( void T_1 * ) V_111 ;
if ( ( F_68 ( V_74 ) != V_112 ) && ! V_111 ) {
F_69 ( L_11 ) ;
return - V_48 ;
}
V_7 = F_5 ( V_5 -> V_10 ) ;
if ( ! V_7 )
return - V_11 ;
V_15 = V_7 -> V_15 ;
V_36 = 0 ;
switch ( V_74 ) {
case V_113 :
V_36 = F_12 ( V_5 ) ;
break;
case V_114 :
V_36 = F_3 ( V_5 ) ;
break;
case V_115 :
V_36 = F_14 ( V_15 ) ;
break;
case V_116 :
V_36 = F_21 ( V_15 ) ;
break;
case V_117 :
V_36 = F_24 ( V_15 ) ;
break;
case V_118 :
V_36 = F_32 ( V_15 ) ;
break;
case V_119 :
V_36 = F_39 ( V_5 , V_1 ) ;
break;
case V_120 :
V_36 = F_49 ( V_15 , V_74 , V_1 ) ;
break;
case V_104 :
V_36 = F_49 ( V_15 , V_74 , V_1 ) ;
break;
case V_121 :
V_36 = F_43 ( V_15 , V_1 ) ;
break;
case V_122 :
V_36 = F_41 ( V_15 ) ;
break;
case V_123 :
V_36 = F_57 ( V_5 , V_1 ) ;
break;
case V_124 :
V_36 = F_1 ( V_1 ) ;
break;
case V_125 :
V_36 = F_70 ( V_7 -> V_20 ) ;
break;
case V_126 :
V_36 = F_71 ( V_7 -> V_20 ) ;
break;
case V_127 :
V_36 = F_61 ( V_15 , V_74 , V_1 ) ;
break;
default:
V_36 = - V_73 ;
if ( V_7 -> V_37 -> V_128 )
V_36 = V_7 -> V_37 -> V_128 ( V_15 , V_74 , V_1 ) ;
}
F_11 ( V_7 ) ;
return V_36 ;
}
