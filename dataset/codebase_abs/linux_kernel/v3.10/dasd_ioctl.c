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
static int
F_24 ( struct V_18 * V_15 , struct V_23 * V_24 )
{
struct V_6 * V_7 ;
int V_25 ;
V_7 = V_15 -> V_7 ;
if ( V_7 -> V_26 -> V_27 == NULL )
return - V_28 ;
if ( V_7 -> V_29 != V_17 ) {
F_25 ( L_5 ,
F_16 ( & V_7 -> V_20 -> V_21 ) ) ;
return - V_30 ;
}
F_26 ( V_31 , V_7 ,
L_6 ,
V_24 -> V_32 ,
V_24 -> V_33 , V_24 -> V_34 , V_24 -> V_35 ) ;
if ( V_24 -> V_32 == 0 ) {
struct V_4 * V_5 = F_27 ( V_15 -> V_16 , 0 ) ;
V_5 -> V_13 -> V_36 = F_28 ( V_24 -> V_34 ) ;
F_29 ( V_5 ) ;
}
V_25 = V_7 -> V_26 -> V_27 ( V_7 , V_24 ) ;
if ( V_25 )
return V_25 ;
return 0 ;
}
static int
F_30 ( struct V_4 * V_5 , void T_1 * V_1 )
{
struct V_6 * V_7 ;
struct V_23 V_24 ;
int V_25 ;
if ( ! F_4 ( V_8 ) )
return - V_9 ;
if ( ! V_1 )
return - V_37 ;
V_7 = F_5 ( V_5 -> V_10 ) ;
if ( ! V_7 )
return - V_11 ;
if ( V_7 -> V_38 & V_39 ||
F_31 ( V_40 , & V_7 -> V_19 ) ) {
F_11 ( V_7 ) ;
return - V_41 ;
}
if ( F_32 ( & V_24 , V_1 , sizeof( struct V_23 ) ) ) {
F_11 ( V_7 ) ;
return - V_42 ;
}
if ( V_5 != V_5 -> V_43 ) {
F_33 ( L_7
L_8 ,
F_16 ( & V_7 -> V_20 -> V_21 ) ) ;
F_11 ( V_7 ) ;
return - V_37 ;
}
V_25 = F_24 ( V_7 -> V_15 , & V_24 ) ;
F_11 ( V_7 ) ;
return V_25 ;
}
static int F_34 ( struct V_18 * V_15 )
{
F_35 ( & V_15 -> V_44 ) ;
return 0 ;
}
static int F_36 ( struct V_18 * V_15 , void T_1 * V_1 )
{
struct V_45 * V_46 ;
int V_25 = 0 ;
V_46 = F_37 ( sizeof( * V_46 ) , V_47 ) ;
if ( ! V_46 )
return - V_48 ;
F_38 ( & V_15 -> V_44 . V_49 ) ;
if ( V_15 -> V_44 . V_46 ) {
V_46 -> V_50 = V_15 -> V_44 . V_46 -> V_50 ;
V_46 -> V_51 = V_15 -> V_44 . V_46 -> V_51 ;
memcpy ( V_46 -> V_52 , V_15 -> V_44 . V_46 -> V_52 ,
sizeof( V_46 -> V_52 ) ) ;
memcpy ( V_46 -> V_53 , V_15 -> V_44 . V_46 -> V_53 ,
sizeof( V_46 -> V_53 ) ) ;
memcpy ( V_46 -> V_54 , V_15 -> V_44 . V_46 -> V_54 ,
sizeof( V_46 -> V_54 ) ) ;
memcpy ( V_46 -> V_55 , V_15 -> V_44 . V_46 -> V_55 ,
sizeof( V_46 -> V_55 ) ) ;
memcpy ( V_46 -> V_56 , V_15 -> V_44 . V_46 -> V_56 ,
sizeof( V_46 -> V_56 ) ) ;
memcpy ( V_46 -> V_57 ,
V_15 -> V_44 . V_46 -> V_57 ,
sizeof( V_46 -> V_57 ) ) ;
memcpy ( V_46 -> V_58 , V_15 -> V_44 . V_46 -> V_58 ,
sizeof( V_46 -> V_58 ) ) ;
memcpy ( V_46 -> V_59 ,
V_15 -> V_44 . V_46 -> V_59 ,
sizeof( V_46 -> V_59 ) ) ;
F_39 ( & V_15 -> V_44 . V_49 ) ;
} else {
F_39 ( & V_15 -> V_44 . V_49 ) ;
V_25 = - V_60 ;
goto V_61;
}
if ( F_40 ( V_1 , V_46 , sizeof( * V_46 ) ) )
V_25 = - V_42 ;
V_61:
F_41 ( V_46 ) ;
return V_25 ;
}
static int F_34 ( struct V_18 * V_15 )
{
return - V_62 ;
}
static int F_36 ( struct V_18 * V_15 , void T_1 * V_1 )
{
return - V_62 ;
}
static int F_42 ( struct V_18 * V_15 ,
unsigned int V_63 , void T_1 * V_1 )
{
struct V_64 * V_65 ;
struct V_66 V_67 ;
struct V_68 V_69 ;
struct V_6 * V_7 ;
struct V_70 * V_20 ;
unsigned long V_19 ;
int V_25 ;
V_7 = V_15 -> V_7 ;
if ( ! V_7 -> V_26 || ! V_7 -> V_26 -> V_71 )
return - V_37 ;
V_65 = F_43 ( sizeof( struct V_64 ) , V_47 ) ;
if ( V_65 == NULL )
return - V_48 ;
V_25 = V_7 -> V_26 -> V_71 ( V_7 , V_65 ) ;
if ( V_25 ) {
F_41 ( V_65 ) ;
return V_25 ;
}
V_20 = V_7 -> V_20 ;
F_44 ( V_20 , & V_69 ) ;
F_45 ( V_20 , & V_67 ) ;
V_65 -> V_72 = V_69 . V_72 ;
V_65 -> V_73 = V_67 . V_74 ;
V_65 -> V_75 = V_20 -> V_76 . V_75 ;
V_65 -> V_77 = V_20 -> V_76 . V_77 ;
V_65 -> V_78 = V_20 -> V_76 . V_78 ;
V_65 -> V_79 = V_20 -> V_76 . V_79 ;
V_65 -> V_80 = V_7 -> V_29 ;
V_65 -> V_81 = F_46 ( & V_15 -> V_81 ) ;
if ( ! V_15 -> V_5 )
V_65 -> V_81 ++ ;
if ( ( V_7 -> V_29 < V_82 ) ||
( F_47 ( V_15 -> V_83 ) ) )
V_65 -> V_84 = V_85 ;
V_65 -> V_38 |=
( ( V_7 -> V_38 & V_39 ) != 0 ) ;
memcpy ( V_65 -> type , V_7 -> V_26 -> V_86 , 4 ) ;
if ( V_15 -> V_87 -> V_88 ) {
struct V_89 * V_90 ;
#ifdef F_48
{
struct V_89 * V_90 ;
F_17 ( & V_15 -> V_49 , V_19 ) ;
F_49 (l, &block->request_queue->queue_head)
V_65 -> V_91 ++ ;
F_20 ( & V_15 -> V_49 , V_19 ) ;
}
#endif
F_17 ( F_18 ( V_7 -> V_20 ) , V_19 ) ;
F_49 (l, &base->ccw_queue)
V_65 -> V_92 ++ ;
F_20 ( F_18 ( V_7 -> V_20 ) ,
V_19 ) ;
}
V_25 = 0 ;
if ( F_40 ( V_1 , V_65 ,
( ( V_63 == ( unsigned int ) V_93 ) ?
sizeof( struct V_64 ) :
sizeof( struct V_94 ) ) ) )
V_25 = - V_42 ;
F_41 ( V_65 ) ;
return V_25 ;
}
static int
F_50 ( struct V_4 * V_5 , void T_1 * V_1 )
{
struct V_6 * V_7 ;
int V_95 , V_25 ;
if ( ! F_4 ( V_8 ) )
return - V_9 ;
if ( V_5 != V_5 -> V_43 )
return - V_37 ;
if ( F_51 ( V_95 , ( int T_1 * ) V_1 ) )
return - V_42 ;
V_7 = F_5 ( V_5 -> V_10 ) ;
if ( ! V_7 )
return - V_11 ;
if ( ! V_95 && F_31 ( V_40 , & V_7 -> V_19 ) ) {
F_11 ( V_7 ) ;
return - V_41 ;
}
F_52 ( V_5 -> V_10 , V_95 ) ;
V_25 = F_53 ( V_7 -> V_20 , V_39 , V_95 ) ;
F_11 ( V_7 ) ;
return V_25 ;
}
static int F_54 ( struct V_18 * V_15 , unsigned int V_63 ,
struct V_96 T_1 * V_1 )
{
T_2 V_97 = F_55 ( V_63 ) ;
struct V_96 V_46 ;
int V_98 ;
V_98 = F_56 ( V_15 -> V_7 -> V_20 , & V_46 ) ;
if ( ! V_98 && F_40 ( V_1 , & V_46 , F_57 ( V_97 , sizeof( * V_1 ) ) ) )
return - V_42 ;
return V_98 ;
}
int F_58 ( struct V_4 * V_5 , T_3 V_99 ,
unsigned int V_63 , unsigned long V_100 )
{
struct V_18 * V_15 ;
struct V_6 * V_7 ;
void T_1 * V_1 ;
int V_25 ;
if ( F_59 () )
V_1 = F_60 ( V_100 ) ;
else
V_1 = ( void T_1 * ) V_100 ;
if ( ( F_61 ( V_63 ) != V_101 ) && ! V_100 ) {
F_62 ( L_9 ) ;
return - V_37 ;
}
V_7 = F_5 ( V_5 -> V_10 ) ;
if ( ! V_7 )
return - V_11 ;
V_15 = V_7 -> V_15 ;
V_25 = 0 ;
switch ( V_63 ) {
case V_102 :
V_25 = F_12 ( V_5 ) ;
break;
case V_103 :
V_25 = F_3 ( V_5 ) ;
break;
case V_104 :
V_25 = F_14 ( V_15 ) ;
break;
case V_105 :
V_25 = F_21 ( V_15 ) ;
break;
case V_106 :
V_25 = F_30 ( V_5 , V_1 ) ;
break;
case V_107 :
V_25 = F_42 ( V_15 , V_63 , V_1 ) ;
break;
case V_93 :
V_25 = F_42 ( V_15 , V_63 , V_1 ) ;
break;
case V_108 :
V_25 = F_36 ( V_15 , V_1 ) ;
break;
case V_109 :
V_25 = F_34 ( V_15 ) ;
break;
case V_110 :
V_25 = F_50 ( V_5 , V_1 ) ;
break;
case V_111 :
V_25 = F_1 ( V_1 ) ;
break;
case V_112 :
V_25 = F_63 ( V_7 -> V_20 ) ;
break;
case V_113 :
V_25 = F_64 ( V_7 -> V_20 ) ;
break;
case V_114 :
V_25 = F_54 ( V_15 , V_63 , V_1 ) ;
break;
default:
V_25 = - V_62 ;
if ( V_7 -> V_26 -> V_115 )
V_25 = V_7 -> V_26 -> V_115 ( V_15 , V_63 , V_1 ) ;
}
F_11 ( V_7 ) ;
return V_25 ;
}
