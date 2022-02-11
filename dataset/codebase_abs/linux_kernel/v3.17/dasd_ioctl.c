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
int V_36 = 1 ;
int V_37 , V_38 ;
int V_39 , V_40 ;
V_7 = V_15 -> V_7 ;
if ( V_7 -> V_41 -> V_42 == NULL )
return - V_43 ;
if ( V_7 -> V_44 != V_17 ) {
F_35 ( L_8 ,
F_16 ( & V_7 -> V_20 -> V_21 ) ) ;
return - V_45 ;
}
F_26 ( V_27 , V_7 ,
L_9 ,
V_35 -> V_46 ,
V_35 -> V_47 , V_35 -> V_48 , V_35 -> V_49 ) ;
if ( V_35 -> V_46 == 0 ) {
struct V_4 * V_5 = F_36 ( V_15 -> V_16 , 0 ) ;
V_5 -> V_13 -> V_50 = F_37 ( V_35 -> V_48 ) ;
F_38 ( V_5 ) ;
}
V_38 = 255 ;
V_39 = V_35 -> V_46 ;
V_40 = V_35 -> V_47 ;
do {
V_37 = V_7 -> V_41 -> V_42 ( V_7 , V_35 , V_36 ) ;
if ( V_37 ) {
if ( V_37 == - V_51 ) {
V_38 -- ;
V_36 = 0 ;
V_35 -> V_46 = V_39 ;
V_35 -> V_47 = V_40 ;
} else
return V_37 ;
} else
break;
} while ( V_38 );
if ( ! V_38 )
return - V_52 ;
else
return 0 ;
}
static int
F_39 ( struct V_4 * V_5 , void T_1 * V_1 )
{
struct V_6 * V_7 ;
struct V_34 V_35 ;
int V_37 ;
if ( ! F_4 ( V_8 ) )
return - V_9 ;
if ( ! V_1 )
return - V_53 ;
V_7 = F_5 ( V_5 -> V_10 ) ;
if ( ! V_7 )
return - V_11 ;
if ( V_7 -> V_54 & V_55 ||
F_29 ( V_56 , & V_7 -> V_19 ) ) {
F_11 ( V_7 ) ;
return - V_57 ;
}
if ( F_40 ( & V_35 , V_1 , sizeof( struct V_34 ) ) ) {
F_11 ( V_7 ) ;
return - V_58 ;
}
if ( V_5 != V_5 -> V_59 ) {
F_41 ( L_10
L_11 ,
F_16 ( & V_7 -> V_20 -> V_21 ) ) ;
F_11 ( V_7 ) ;
return - V_53 ;
}
V_37 = F_34 ( V_7 -> V_15 , & V_35 ) ;
F_11 ( V_7 ) ;
return V_37 ;
}
static int F_42 ( struct V_18 * V_15 )
{
F_43 ( & V_15 -> V_60 ) ;
return 0 ;
}
static int F_44 ( struct V_18 * V_15 , void T_1 * V_1 )
{
struct V_61 * V_62 ;
int V_37 = 0 ;
V_62 = F_45 ( sizeof( * V_62 ) , V_63 ) ;
if ( ! V_62 )
return - V_64 ;
F_46 ( & V_15 -> V_60 . V_65 ) ;
if ( V_15 -> V_60 . V_62 ) {
V_62 -> V_66 = V_15 -> V_60 . V_62 -> V_66 ;
V_62 -> V_67 = V_15 -> V_60 . V_62 -> V_67 ;
memcpy ( V_62 -> V_68 , V_15 -> V_60 . V_62 -> V_68 ,
sizeof( V_62 -> V_68 ) ) ;
memcpy ( V_62 -> V_69 , V_15 -> V_60 . V_62 -> V_69 ,
sizeof( V_62 -> V_69 ) ) ;
memcpy ( V_62 -> V_70 , V_15 -> V_60 . V_62 -> V_70 ,
sizeof( V_62 -> V_70 ) ) ;
memcpy ( V_62 -> V_71 , V_15 -> V_60 . V_62 -> V_71 ,
sizeof( V_62 -> V_71 ) ) ;
memcpy ( V_62 -> V_72 , V_15 -> V_60 . V_62 -> V_72 ,
sizeof( V_62 -> V_72 ) ) ;
memcpy ( V_62 -> V_73 ,
V_15 -> V_60 . V_62 -> V_73 ,
sizeof( V_62 -> V_73 ) ) ;
memcpy ( V_62 -> V_74 , V_15 -> V_60 . V_62 -> V_74 ,
sizeof( V_62 -> V_74 ) ) ;
memcpy ( V_62 -> V_75 ,
V_15 -> V_60 . V_62 -> V_75 ,
sizeof( V_62 -> V_75 ) ) ;
F_47 ( & V_15 -> V_60 . V_65 ) ;
} else {
F_47 ( & V_15 -> V_60 . V_65 ) ;
V_37 = - V_52 ;
goto V_76;
}
if ( F_48 ( V_1 , V_62 , sizeof( * V_62 ) ) )
V_37 = - V_58 ;
V_76:
F_49 ( V_62 ) ;
return V_37 ;
}
static int F_42 ( struct V_18 * V_15 )
{
return - V_77 ;
}
static int F_44 ( struct V_18 * V_15 , void T_1 * V_1 )
{
return - V_77 ;
}
static int F_50 ( struct V_18 * V_15 ,
unsigned int V_78 , void T_1 * V_1 )
{
struct V_79 * V_80 ;
struct V_81 V_82 ;
struct V_83 V_84 ;
struct V_6 * V_7 ;
struct V_85 * V_20 ;
unsigned long V_19 ;
int V_37 ;
V_7 = V_15 -> V_7 ;
if ( ! V_7 -> V_41 || ! V_7 -> V_41 -> V_86 )
return - V_53 ;
V_80 = F_51 ( sizeof( struct V_79 ) , V_63 ) ;
if ( V_80 == NULL )
return - V_64 ;
V_37 = V_7 -> V_41 -> V_86 ( V_7 , V_80 ) ;
if ( V_37 ) {
F_49 ( V_80 ) ;
return V_37 ;
}
V_20 = V_7 -> V_20 ;
F_52 ( V_20 , & V_84 ) ;
F_53 ( V_20 , & V_82 ) ;
V_80 -> V_87 = V_84 . V_87 ;
V_80 -> V_88 = V_82 . V_89 ;
V_80 -> V_90 = V_20 -> V_91 . V_90 ;
V_80 -> V_92 = V_20 -> V_91 . V_92 ;
V_80 -> V_93 = V_20 -> V_91 . V_93 ;
V_80 -> V_94 = V_20 -> V_91 . V_94 ;
V_80 -> V_95 = V_7 -> V_44 ;
V_80 -> V_96 = F_54 ( & V_15 -> V_96 ) ;
if ( ! V_15 -> V_5 )
V_80 -> V_96 ++ ;
if ( ( V_7 -> V_44 < V_97 ) ||
( F_55 ( V_15 -> V_98 ) ) )
V_80 -> V_99 = V_100 ;
V_80 -> V_54 |=
( ( V_7 -> V_54 & V_55 ) != 0 ) ;
memcpy ( V_80 -> type , V_7 -> V_41 -> V_101 , 4 ) ;
if ( V_15 -> V_102 -> V_103 ) {
struct V_104 * V_105 ;
#ifdef F_56
{
struct V_104 * V_105 ;
F_17 ( & V_15 -> V_65 , V_19 ) ;
F_57 (l, &block->request_queue->queue_head)
V_80 -> V_106 ++ ;
F_20 ( & V_15 -> V_65 , V_19 ) ;
}
#endif
F_17 ( F_18 ( V_7 -> V_20 ) , V_19 ) ;
F_57 (l, &base->ccw_queue)
V_80 -> V_107 ++ ;
F_20 ( F_18 ( V_7 -> V_20 ) ,
V_19 ) ;
}
V_37 = 0 ;
if ( F_48 ( V_1 , V_80 ,
( ( V_78 == ( unsigned int ) V_108 ) ?
sizeof( struct V_79 ) :
sizeof( struct V_109 ) ) ) )
V_37 = - V_58 ;
F_49 ( V_80 ) ;
return V_37 ;
}
static int
F_58 ( struct V_4 * V_5 , void T_1 * V_1 )
{
struct V_6 * V_7 ;
int V_110 , V_37 ;
if ( ! F_4 ( V_8 ) )
return - V_9 ;
if ( V_5 != V_5 -> V_59 )
return - V_53 ;
if ( F_59 ( V_110 , ( int T_1 * ) V_1 ) )
return - V_58 ;
V_7 = F_5 ( V_5 -> V_10 ) ;
if ( ! V_7 )
return - V_11 ;
if ( ! V_110 && F_29 ( V_56 , & V_7 -> V_19 ) ) {
F_11 ( V_7 ) ;
return - V_57 ;
}
F_60 ( V_5 -> V_10 , V_110 ) ;
V_37 = F_61 ( V_7 -> V_20 , V_55 , V_110 ) ;
F_11 ( V_7 ) ;
return V_37 ;
}
static int F_62 ( struct V_18 * V_15 , unsigned int V_78 ,
struct V_111 T_1 * V_1 )
{
T_2 V_112 = F_63 ( V_78 ) ;
struct V_111 V_62 ;
int V_113 ;
V_113 = F_64 ( V_15 -> V_7 -> V_20 , & V_62 ) ;
if ( ! V_113 && F_48 ( V_1 , & V_62 , F_65 ( V_112 , sizeof( * V_1 ) ) ) )
return - V_58 ;
return V_113 ;
}
int F_66 ( struct V_4 * V_5 , T_3 V_114 ,
unsigned int V_78 , unsigned long V_115 )
{
struct V_18 * V_15 ;
struct V_6 * V_7 ;
void T_1 * V_1 ;
int V_37 ;
if ( F_67 () )
V_1 = F_68 ( V_115 ) ;
else
V_1 = ( void T_1 * ) V_115 ;
if ( ( F_69 ( V_78 ) != V_116 ) && ! V_115 ) {
F_70 ( L_12 ) ;
return - V_53 ;
}
V_7 = F_5 ( V_5 -> V_10 ) ;
if ( ! V_7 )
return - V_11 ;
V_15 = V_7 -> V_15 ;
V_37 = 0 ;
switch ( V_78 ) {
case V_117 :
V_37 = F_12 ( V_5 ) ;
break;
case V_118 :
V_37 = F_3 ( V_5 ) ;
break;
case V_119 :
V_37 = F_14 ( V_15 ) ;
break;
case V_120 :
V_37 = F_21 ( V_15 ) ;
break;
case V_121 :
V_37 = F_24 ( V_15 ) ;
break;
case V_122 :
V_37 = F_32 ( V_15 ) ;
break;
case V_123 :
V_37 = F_39 ( V_5 , V_1 ) ;
break;
case V_124 :
V_37 = F_50 ( V_15 , V_78 , V_1 ) ;
break;
case V_108 :
V_37 = F_50 ( V_15 , V_78 , V_1 ) ;
break;
case V_125 :
V_37 = F_44 ( V_15 , V_1 ) ;
break;
case V_126 :
V_37 = F_42 ( V_15 ) ;
break;
case V_127 :
V_37 = F_58 ( V_5 , V_1 ) ;
break;
case V_128 :
V_37 = F_1 ( V_1 ) ;
break;
case V_129 :
V_37 = F_71 ( V_7 -> V_20 ) ;
break;
case V_130 :
V_37 = F_72 ( V_7 -> V_20 ) ;
break;
case V_131 :
V_37 = F_62 ( V_15 , V_78 , V_1 ) ;
break;
default:
V_37 = - V_77 ;
if ( V_7 -> V_41 -> V_132 )
V_37 = V_7 -> V_41 -> V_132 ( V_15 , V_78 , V_1 ) ;
}
F_11 ( V_7 ) ;
return V_37 ;
}
