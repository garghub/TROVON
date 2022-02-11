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
memset ( & V_15 -> V_48 , 0 , sizeof( struct V_49 ) ) ;
return 0 ;
}
static int F_39 ( struct V_18 * V_15 , void T_1 * V_1 )
{
if ( V_50 == V_51 )
return - V_52 ;
if ( F_40 ( V_1 , & V_15 -> V_48 ,
sizeof( struct V_49 ) ) )
return - V_46 ;
return 0 ;
}
static int F_38 ( struct V_18 * V_15 )
{
return - V_53 ;
}
static int F_39 ( struct V_18 * V_15 , void T_1 * V_1 )
{
return - V_53 ;
}
static int F_41 ( struct V_18 * V_15 ,
unsigned int V_54 , void T_1 * V_1 )
{
struct V_55 * V_56 ;
unsigned long V_19 ;
int V_27 ;
struct V_6 * V_7 ;
struct V_57 * V_20 ;
struct V_58 V_59 ;
V_7 = V_15 -> V_7 ;
if ( ! V_7 -> V_28 || ! V_7 -> V_28 -> V_60 )
return - V_41 ;
V_56 = F_42 ( sizeof( struct V_55 ) , V_61 ) ;
if ( V_56 == NULL )
return - V_62 ;
V_27 = V_7 -> V_28 -> V_60 ( V_7 , V_56 ) ;
if ( V_27 ) {
F_43 ( V_56 ) ;
return V_27 ;
}
V_20 = V_7 -> V_20 ;
F_44 ( V_20 , & V_59 ) ;
V_56 -> V_63 = V_59 . V_63 ;
V_56 -> V_64 = F_45 ( V_7 -> V_20 ) ;
V_56 -> V_65 = V_20 -> V_66 . V_65 ;
V_56 -> V_67 = V_20 -> V_66 . V_67 ;
V_56 -> V_68 = V_20 -> V_66 . V_68 ;
V_56 -> V_69 = V_20 -> V_66 . V_69 ;
V_56 -> V_70 = V_7 -> V_31 ;
V_56 -> V_71 = F_46 ( & V_15 -> V_71 ) ;
if ( ! V_15 -> V_5 )
V_56 -> V_71 ++ ;
if ( ( V_7 -> V_31 < V_72 ) ||
( F_47 ( V_15 -> V_73 ) ) )
V_56 -> V_74 = V_75 ;
V_56 -> V_42 |=
( ( V_7 -> V_42 & V_43 ) != 0 ) ;
memcpy ( V_56 -> type , V_7 -> V_28 -> V_76 , 4 ) ;
if ( V_15 -> V_77 -> V_78 ) {
struct V_79 * V_80 ;
#ifdef F_48
{
struct V_79 * V_80 ;
F_17 ( & V_15 -> V_81 , V_19 ) ;
F_49 (l, &block->request_queue->queue_head)
V_56 -> V_82 ++ ;
F_20 ( & V_15 -> V_81 , V_19 ) ;
}
#endif
F_17 ( F_18 ( V_7 -> V_20 ) , V_19 ) ;
F_49 (l, &base->ccw_queue)
V_56 -> V_83 ++ ;
F_20 ( F_18 ( V_7 -> V_20 ) ,
V_19 ) ;
}
V_27 = 0 ;
if ( F_40 ( V_1 , V_56 ,
( ( V_54 == ( unsigned int ) V_84 ) ?
sizeof( struct V_55 ) :
sizeof( struct V_85 ) ) ) )
V_27 = - V_46 ;
F_43 ( V_56 ) ;
return V_27 ;
}
static int
F_50 ( struct V_4 * V_5 , void T_1 * V_1 )
{
struct V_6 * V_7 ;
int V_86 , V_27 ;
if ( ! F_4 ( V_8 ) )
return - V_9 ;
if ( V_5 != V_5 -> V_47 )
return - V_41 ;
if ( F_51 ( V_86 , ( int T_1 * ) V_1 ) )
return - V_46 ;
V_7 = F_5 ( V_5 -> V_10 ) ;
if ( ! V_7 )
return - V_11 ;
if ( ! V_86 && F_36 ( V_44 , & V_7 -> V_19 ) ) {
F_11 ( V_7 ) ;
return - V_45 ;
}
F_52 ( V_5 -> V_10 , V_86 ) ;
V_27 = F_53 ( V_7 -> V_20 , V_43 , V_86 ) ;
F_11 ( V_7 ) ;
return V_27 ;
}
static int F_54 ( struct V_18 * V_15 , unsigned int V_54 ,
struct V_87 T_1 * V_1 )
{
T_2 V_88 = F_55 ( V_54 ) ;
struct V_87 V_89 ;
int V_90 ;
V_90 = F_56 ( V_15 -> V_7 -> V_20 , & V_89 ) ;
if ( ! V_90 && F_40 ( V_1 , & V_89 , F_57 ( V_88 , sizeof( * V_1 ) ) ) )
return - V_46 ;
return V_90 ;
}
int F_58 ( struct V_4 * V_5 , T_3 V_91 ,
unsigned int V_54 , unsigned long V_92 )
{
struct V_18 * V_15 ;
struct V_6 * V_7 ;
void T_1 * V_1 ;
int V_27 ;
if ( F_59 () )
V_1 = F_60 ( V_92 ) ;
else
V_1 = ( void T_1 * ) V_92 ;
if ( ( F_61 ( V_54 ) != V_93 ) && ! V_92 ) {
F_62 ( L_12 ) ;
return - V_41 ;
}
V_7 = F_5 ( V_5 -> V_10 ) ;
if ( ! V_7 )
return - V_11 ;
V_15 = V_7 -> V_15 ;
V_27 = 0 ;
switch ( V_54 ) {
case V_94 :
V_27 = F_12 ( V_5 ) ;
break;
case V_95 :
V_27 = F_3 ( V_5 ) ;
break;
case V_96 :
V_27 = F_14 ( V_15 ) ;
break;
case V_97 :
V_27 = F_21 ( V_15 ) ;
break;
case V_98 :
V_27 = F_35 ( V_5 , V_1 ) ;
break;
case V_99 :
V_27 = F_41 ( V_15 , V_54 , V_1 ) ;
break;
case V_84 :
V_27 = F_41 ( V_15 , V_54 , V_1 ) ;
break;
case V_100 :
V_27 = F_39 ( V_15 , V_1 ) ;
break;
case V_101 :
V_27 = F_38 ( V_15 ) ;
break;
case V_102 :
V_27 = F_50 ( V_5 , V_1 ) ;
break;
case V_103 :
V_27 = F_1 ( V_1 ) ;
break;
case V_104 :
V_27 = F_63 ( V_7 -> V_20 ) ;
break;
case V_105 :
V_27 = F_64 ( V_7 -> V_20 ) ;
break;
case V_106 :
V_27 = F_54 ( V_15 , V_54 , V_1 ) ;
break;
default:
if ( V_7 -> V_28 -> V_107 ) {
V_27 = V_7 -> V_28 -> V_107 ( V_15 , V_54 , V_1 ) ;
if ( V_27 == - V_108 )
V_27 = - V_41 ;
} else
V_27 = - V_41 ;
}
F_11 ( V_7 ) ;
return V_27 ;
}
