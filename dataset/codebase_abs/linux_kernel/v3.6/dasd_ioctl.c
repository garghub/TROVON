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
static int F_24 ( struct V_18 * V_15 , struct V_23 * V_24 )
{
struct V_25 * V_26 ;
struct V_6 * V_7 ;
int V_27 ;
V_7 = V_15 -> V_7 ;
if ( V_7 -> V_28 -> V_29 == NULL )
return - V_30 ;
if ( V_7 -> V_31 != V_17 ) {
F_25 ( L_5
L_6 , F_16 ( & V_7 -> V_20 -> V_21 ) ) ;
return - V_32 ;
}
F_26 ( V_33 , V_7 ,
L_7 ,
V_24 -> V_34 ,
V_24 -> V_35 , V_24 -> V_36 , V_24 -> V_37 ) ;
if ( V_24 -> V_34 == 0 ) {
struct V_4 * V_5 = F_27 ( V_15 -> V_16 , 0 ) ;
V_5 -> V_13 -> V_38 = F_28 ( V_24 -> V_36 ) ;
F_29 ( V_5 ) ;
}
while ( V_24 -> V_34 <= V_24 -> V_35 ) {
V_26 = V_7 -> V_28 -> V_29 ( V_7 , V_24 ) ;
if ( F_30 ( V_26 ) )
return F_31 ( V_26 ) ;
V_27 = F_32 ( V_26 ) ;
F_33 ( V_26 , V_26 -> V_39 ) ;
if ( V_27 ) {
if ( V_27 != - V_40 )
F_34 ( L_8
L_9 , F_16 ( & V_7 -> V_20 -> V_21 ) ,
V_24 -> V_34 , V_27 ) ;
return V_27 ;
}
V_24 -> V_34 ++ ;
}
return 0 ;
}
static int
F_35 ( struct V_4 * V_5 , void T_1 * V_1 )
{
struct V_6 * V_7 ;
struct V_23 V_24 ;
int V_27 ;
if ( ! F_4 ( V_8 ) )
return - V_9 ;
if ( ! V_1 )
return - V_41 ;
V_7 = F_5 ( V_5 -> V_10 ) ;
if ( ! V_7 )
return - V_11 ;
if ( V_7 -> V_42 & V_43 ||
F_36 ( V_44 , & V_7 -> V_19 ) ) {
F_11 ( V_7 ) ;
return - V_45 ;
}
if ( F_37 ( & V_24 , V_1 , sizeof( struct V_23 ) ) ) {
F_11 ( V_7 ) ;
return - V_46 ;
}
if ( V_5 != V_5 -> V_47 ) {
F_25 ( L_10
L_11 ,
F_16 ( & V_7 -> V_20 -> V_21 ) ) ;
F_11 ( V_7 ) ;
return - V_41 ;
}
V_27 = F_24 ( V_7 -> V_15 , & V_24 ) ;
F_11 ( V_7 ) ;
return V_27 ;
}
static int F_38 ( struct V_18 * V_15 )
{
F_39 ( & V_15 -> V_48 ) ;
return 0 ;
}
static int F_40 ( struct V_18 * V_15 , void T_1 * V_1 )
{
struct V_49 * V_50 ;
int V_27 = 0 ;
V_50 = F_41 ( sizeof( * V_50 ) , V_51 ) ;
if ( ! V_50 )
return - V_52 ;
F_42 ( & V_15 -> V_48 . V_53 ) ;
if ( V_15 -> V_48 . V_50 ) {
V_50 -> V_54 = V_15 -> V_48 . V_50 -> V_54 ;
V_50 -> V_55 = V_15 -> V_48 . V_50 -> V_55 ;
memcpy ( V_50 -> V_56 , V_15 -> V_48 . V_50 -> V_56 ,
sizeof( V_50 -> V_56 ) ) ;
memcpy ( V_50 -> V_57 , V_15 -> V_48 . V_50 -> V_57 ,
sizeof( V_50 -> V_57 ) ) ;
memcpy ( V_50 -> V_58 , V_15 -> V_48 . V_50 -> V_58 ,
sizeof( V_50 -> V_58 ) ) ;
memcpy ( V_50 -> V_59 , V_15 -> V_48 . V_50 -> V_59 ,
sizeof( V_50 -> V_59 ) ) ;
memcpy ( V_50 -> V_60 , V_15 -> V_48 . V_50 -> V_60 ,
sizeof( V_50 -> V_60 ) ) ;
memcpy ( V_50 -> V_61 ,
V_15 -> V_48 . V_50 -> V_61 ,
sizeof( V_50 -> V_61 ) ) ;
memcpy ( V_50 -> V_62 , V_15 -> V_48 . V_50 -> V_62 ,
sizeof( V_50 -> V_62 ) ) ;
memcpy ( V_50 -> V_63 ,
V_15 -> V_48 . V_50 -> V_63 ,
sizeof( V_50 -> V_63 ) ) ;
F_43 ( & V_15 -> V_48 . V_53 ) ;
} else {
F_43 ( & V_15 -> V_48 . V_53 ) ;
V_27 = - V_64 ;
goto V_65;
}
if ( F_44 ( V_1 , V_50 , sizeof( * V_50 ) ) )
V_27 = - V_46 ;
V_65:
F_45 ( V_50 ) ;
return V_27 ;
}
static int F_38 ( struct V_18 * V_15 )
{
return - V_66 ;
}
static int F_40 ( struct V_18 * V_15 , void T_1 * V_1 )
{
return - V_66 ;
}
static int F_46 ( struct V_18 * V_15 ,
unsigned int V_67 , void T_1 * V_1 )
{
struct V_68 * V_69 ;
unsigned long V_19 ;
int V_27 ;
struct V_6 * V_7 ;
struct V_70 * V_20 ;
struct V_71 V_72 ;
V_7 = V_15 -> V_7 ;
if ( ! V_7 -> V_28 || ! V_7 -> V_28 -> V_73 )
return - V_41 ;
V_69 = F_47 ( sizeof( struct V_68 ) , V_51 ) ;
if ( V_69 == NULL )
return - V_52 ;
V_27 = V_7 -> V_28 -> V_73 ( V_7 , V_69 ) ;
if ( V_27 ) {
F_45 ( V_69 ) ;
return V_27 ;
}
V_20 = V_7 -> V_20 ;
F_48 ( V_20 , & V_72 ) ;
V_69 -> V_74 = V_72 . V_74 ;
V_69 -> V_75 = F_49 ( V_7 -> V_20 ) ;
V_69 -> V_76 = V_20 -> V_77 . V_76 ;
V_69 -> V_78 = V_20 -> V_77 . V_78 ;
V_69 -> V_79 = V_20 -> V_77 . V_79 ;
V_69 -> V_80 = V_20 -> V_77 . V_80 ;
V_69 -> V_81 = V_7 -> V_31 ;
V_69 -> V_82 = F_50 ( & V_15 -> V_82 ) ;
if ( ! V_15 -> V_5 )
V_69 -> V_82 ++ ;
if ( ( V_7 -> V_31 < V_83 ) ||
( F_51 ( V_15 -> V_84 ) ) )
V_69 -> V_85 = V_86 ;
V_69 -> V_42 |=
( ( V_7 -> V_42 & V_43 ) != 0 ) ;
memcpy ( V_69 -> type , V_7 -> V_28 -> V_87 , 4 ) ;
if ( V_15 -> V_88 -> V_89 ) {
struct V_90 * V_91 ;
#ifdef F_52
{
struct V_90 * V_91 ;
F_17 ( & V_15 -> V_53 , V_19 ) ;
F_53 (l, &block->request_queue->queue_head)
V_69 -> V_92 ++ ;
F_20 ( & V_15 -> V_53 , V_19 ) ;
}
#endif
F_17 ( F_18 ( V_7 -> V_20 ) , V_19 ) ;
F_53 (l, &base->ccw_queue)
V_69 -> V_93 ++ ;
F_20 ( F_18 ( V_7 -> V_20 ) ,
V_19 ) ;
}
V_27 = 0 ;
if ( F_44 ( V_1 , V_69 ,
( ( V_67 == ( unsigned int ) V_94 ) ?
sizeof( struct V_68 ) :
sizeof( struct V_95 ) ) ) )
V_27 = - V_46 ;
F_45 ( V_69 ) ;
return V_27 ;
}
static int
F_54 ( struct V_4 * V_5 , void T_1 * V_1 )
{
struct V_6 * V_7 ;
int V_96 , V_27 ;
if ( ! F_4 ( V_8 ) )
return - V_9 ;
if ( V_5 != V_5 -> V_47 )
return - V_41 ;
if ( F_55 ( V_96 , ( int T_1 * ) V_1 ) )
return - V_46 ;
V_7 = F_5 ( V_5 -> V_10 ) ;
if ( ! V_7 )
return - V_11 ;
if ( ! V_96 && F_36 ( V_44 , & V_7 -> V_19 ) ) {
F_11 ( V_7 ) ;
return - V_45 ;
}
F_56 ( V_5 -> V_10 , V_96 ) ;
V_27 = F_57 ( V_7 -> V_20 , V_43 , V_96 ) ;
F_11 ( V_7 ) ;
return V_27 ;
}
static int F_58 ( struct V_18 * V_15 , unsigned int V_67 ,
struct V_97 T_1 * V_1 )
{
T_2 V_98 = F_59 ( V_67 ) ;
struct V_97 V_50 ;
int V_99 ;
V_99 = F_60 ( V_15 -> V_7 -> V_20 , & V_50 ) ;
if ( ! V_99 && F_44 ( V_1 , & V_50 , F_61 ( V_98 , sizeof( * V_1 ) ) ) )
return - V_46 ;
return V_99 ;
}
int F_62 ( struct V_4 * V_5 , T_3 V_100 ,
unsigned int V_67 , unsigned long V_101 )
{
struct V_18 * V_15 ;
struct V_6 * V_7 ;
void T_1 * V_1 ;
int V_27 ;
if ( F_63 () )
V_1 = F_64 ( V_101 ) ;
else
V_1 = ( void T_1 * ) V_101 ;
if ( ( F_65 ( V_67 ) != V_102 ) && ! V_101 ) {
F_66 ( L_12 ) ;
return - V_41 ;
}
V_7 = F_5 ( V_5 -> V_10 ) ;
if ( ! V_7 )
return - V_11 ;
V_15 = V_7 -> V_15 ;
V_27 = 0 ;
switch ( V_67 ) {
case V_103 :
V_27 = F_12 ( V_5 ) ;
break;
case V_104 :
V_27 = F_3 ( V_5 ) ;
break;
case V_105 :
V_27 = F_14 ( V_15 ) ;
break;
case V_106 :
V_27 = F_21 ( V_15 ) ;
break;
case V_107 :
V_27 = F_35 ( V_5 , V_1 ) ;
break;
case V_108 :
V_27 = F_46 ( V_15 , V_67 , V_1 ) ;
break;
case V_94 :
V_27 = F_46 ( V_15 , V_67 , V_1 ) ;
break;
case V_109 :
V_27 = F_40 ( V_15 , V_1 ) ;
break;
case V_110 :
V_27 = F_38 ( V_15 ) ;
break;
case V_111 :
V_27 = F_54 ( V_5 , V_1 ) ;
break;
case V_112 :
V_27 = F_1 ( V_1 ) ;
break;
case V_113 :
V_27 = F_67 ( V_7 -> V_20 ) ;
break;
case V_114 :
V_27 = F_68 ( V_7 -> V_20 ) ;
break;
case V_115 :
V_27 = F_58 ( V_15 , V_67 , V_1 ) ;
break;
default:
V_27 = - V_116 ;
if ( V_7 -> V_28 -> V_117 )
V_27 = V_7 -> V_28 -> V_117 ( V_15 , V_67 , V_1 ) ;
}
F_11 ( V_7 ) ;
return V_27 ;
}
