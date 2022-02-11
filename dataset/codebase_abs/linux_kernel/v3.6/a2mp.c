static struct V_1 * F_1 ( T_1 V_2 , T_1 V_3 , T_2 V_4 , void * V_5 )
{
struct V_1 * V_6 ;
int V_7 ;
V_7 = sizeof( * V_6 ) + V_4 ;
V_6 = F_2 ( V_7 , V_8 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_2 = V_2 ;
V_6 -> V_3 = V_3 ;
V_6 -> V_4 = F_3 ( V_4 ) ;
memcpy ( V_6 -> V_5 , V_5 , V_4 ) ;
return V_6 ;
}
static void F_4 ( struct V_9 * V_10 , T_1 V_2 , T_1 V_3 , T_2 V_4 ,
void * V_5 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_6 ;
T_2 V_14 = V_4 + sizeof( * V_6 ) ;
struct V_15 V_16 ;
struct V_17 V_18 ;
V_6 = F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
if ( ! V_6 )
return;
V_16 . V_19 = V_6 ;
V_16 . V_20 = V_14 ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_21 = (struct V_22 * ) & V_16 ;
V_18 . V_23 = 1 ;
F_5 ( V_12 , & V_18 , V_14 , 0 ) ;
F_6 ( V_6 ) ;
}
static inline void F_7 ( struct V_24 * V_25 )
{
V_25 -> V_26 = 0 ;
V_25 -> type = 0 ;
V_25 -> V_27 = 1 ;
}
static void F_8 ( struct V_9 * V_10 , struct V_24 * V_25 , T_1 V_28 )
{
int V_29 = 0 ;
struct V_30 * V_31 ;
F_7 ( V_25 ) ;
F_9 (hdev, &hci_dev_list, list) {
if ( V_31 -> V_26 == V_32 )
continue;
if ( ++ V_29 >= V_28 )
return;
V_25 [ V_29 ] . V_26 = V_31 -> V_26 ;
V_25 [ V_29 ] . type = V_31 -> V_33 ;
V_25 [ V_29 ] . V_27 = V_31 -> V_34 ;
}
}
static int F_10 ( struct V_9 * V_10 , struct V_35 * V_36 ,
struct V_1 * V_37 )
{
struct V_38 * V_39 = ( void * ) V_36 -> V_5 ;
if ( F_11 ( V_37 -> V_4 ) < sizeof( * V_39 ) )
return - V_40 ;
F_12 ( L_1 , V_37 -> V_3 , F_11 ( V_39 -> V_41 ) ) ;
F_13 ( V_36 , sizeof( * V_39 ) ) ;
return 0 ;
}
static int F_14 ( struct V_9 * V_10 , struct V_35 * V_36 ,
struct V_1 * V_37 )
{
struct V_42 * V_43 = ( void * ) V_36 -> V_5 ;
T_2 V_4 = F_11 ( V_37 -> V_4 ) ;
struct V_44 * V_45 ;
T_2 V_46 ;
T_1 V_28 ;
if ( V_4 < sizeof( * V_43 ) )
return - V_40 ;
F_13 ( V_36 , sizeof( * V_43 ) ) ;
V_46 = F_11 ( V_43 -> V_46 ) ;
F_12 ( L_2 , F_11 ( V_43 -> V_47 ) , V_46 ) ;
while ( V_46 & V_48 ) {
if ( V_4 < sizeof( V_46 ) )
return - V_40 ;
V_46 = F_15 ( V_36 -> V_5 ) ;
F_12 ( L_3 , V_46 ) ;
V_4 -= sizeof( V_46 ) ;
F_13 ( V_36 , sizeof( V_46 ) ) ;
}
F_16 ( & V_49 ) ;
V_28 = F_17 () ;
V_4 = V_28 * sizeof( struct V_24 ) + sizeof( * V_45 ) ;
V_45 = F_18 ( V_4 , V_50 ) ;
if ( ! V_45 ) {
F_19 ( & V_49 ) ;
return - V_51 ;
}
V_45 -> V_47 = F_20 ( V_52 ) ;
V_45 -> V_46 = 0 ;
F_8 ( V_10 , V_45 -> V_25 , V_28 ) ;
F_19 ( & V_49 ) ;
F_4 ( V_10 , V_53 , V_37 -> V_3 , V_4 , V_45 ) ;
F_6 ( V_45 ) ;
return 0 ;
}
static int F_21 ( struct V_9 * V_10 , struct V_35 * V_36 ,
struct V_1 * V_37 )
{
struct V_24 * V_25 = ( void * ) V_36 -> V_5 ;
while ( V_36 -> V_4 >= sizeof( * V_25 ) ) {
F_12 ( L_4 , V_25 -> V_26 , V_25 -> type ,
V_25 -> V_27 ) ;
V_25 = (struct V_24 * ) F_13 ( V_36 , sizeof( * V_25 ) ) ;
}
return 0 ;
}
static int F_22 ( struct V_9 * V_10 , struct V_35 * V_36 ,
struct V_1 * V_37 )
{
struct V_54 * V_43 = ( void * ) V_36 -> V_5 ;
struct V_55 V_45 ;
struct V_30 * V_31 ;
if ( F_11 ( V_37 -> V_4 ) < sizeof( * V_43 ) )
return - V_40 ;
F_12 ( L_5 , V_43 -> V_26 ) ;
V_45 . V_26 = V_43 -> V_26 ;
V_45 . V_27 = V_56 ;
V_31 = F_23 ( V_43 -> V_26 ) ;
if ( V_31 && V_31 -> V_33 != V_57 ) {
V_45 . V_27 = 0 ;
V_45 . V_58 = F_24 ( V_31 -> V_59 ) ;
V_45 . V_60 = F_24 ( V_31 -> V_61 ) ;
V_45 . V_62 = F_24 ( V_31 -> V_63 ) ;
V_45 . V_64 = F_3 ( V_31 -> V_65 ) ;
V_45 . V_66 = F_3 ( V_31 -> V_67 ) ;
}
if ( V_31 )
F_25 ( V_31 ) ;
F_4 ( V_10 , V_68 , V_37 -> V_3 , sizeof( V_45 ) , & V_45 ) ;
F_13 ( V_36 , sizeof( * V_43 ) ) ;
return 0 ;
}
static int F_26 ( struct V_9 * V_10 , struct V_35 * V_36 ,
struct V_1 * V_37 )
{
struct V_69 * V_43 = ( void * ) V_36 -> V_5 ;
struct V_30 * V_31 ;
if ( F_11 ( V_37 -> V_4 ) < sizeof( * V_43 ) )
return - V_40 ;
F_12 ( L_5 , V_43 -> V_26 ) ;
V_31 = F_23 ( V_43 -> V_26 ) ;
if ( ! V_31 || V_31 -> V_33 == V_57 ) {
struct V_70 V_45 ;
V_45 . V_26 = V_43 -> V_26 ;
V_45 . V_27 = V_56 ;
F_4 ( V_10 , V_71 , V_37 -> V_3 , sizeof( V_45 ) ,
& V_45 ) ;
goto V_72;
}
V_72:
if ( V_31 )
F_25 ( V_31 ) ;
F_13 ( V_36 , sizeof( * V_43 ) ) ;
return 0 ;
}
static int F_27 ( struct V_9 * V_10 , struct V_35 * V_36 ,
struct V_1 * V_37 )
{
struct V_73 * V_43 = ( void * ) V_36 -> V_5 ;
struct V_74 V_45 ;
struct V_30 * V_31 ;
if ( F_11 ( V_37 -> V_4 ) < sizeof( * V_43 ) )
return - V_40 ;
F_12 ( L_6 , V_43 -> V_75 , V_43 -> V_76 ) ;
V_45 . V_75 = V_43 -> V_76 ;
V_45 . V_76 = V_43 -> V_75 ;
V_31 = F_23 ( V_43 -> V_76 ) ;
if ( ! V_31 || V_31 -> V_33 != V_77 ) {
V_45 . V_27 = V_56 ;
goto V_78;
}
V_45 . V_27 = V_79 ;
V_78:
if ( V_31 )
F_25 ( V_31 ) ;
F_4 ( V_10 , V_80 , V_37 -> V_3 , sizeof( V_45 ) ,
& V_45 ) ;
F_13 ( V_36 , F_11 ( V_37 -> V_4 ) ) ;
return 0 ;
}
static int F_28 ( struct V_9 * V_10 , struct V_35 * V_36 ,
struct V_1 * V_37 )
{
struct V_73 * V_43 = ( void * ) V_36 -> V_5 ;
struct V_74 V_45 ;
struct V_30 * V_31 ;
if ( F_11 ( V_37 -> V_4 ) < sizeof( * V_43 ) )
return - V_40 ;
F_12 ( L_7 , V_43 -> V_75 , V_43 -> V_76 ) ;
V_45 . V_75 = V_43 -> V_76 ;
V_45 . V_76 = V_43 -> V_75 ;
V_45 . V_27 = V_79 ;
V_31 = F_23 ( V_43 -> V_75 ) ;
if ( ! V_31 ) {
V_45 . V_27 = V_56 ;
goto V_78;
}
F_25 ( V_31 ) ;
V_78:
F_4 ( V_10 , V_81 , V_37 -> V_3 , sizeof( V_45 ) , & V_45 ) ;
F_13 ( V_36 , sizeof( * V_43 ) ) ;
return 0 ;
}
static inline int F_29 ( struct V_9 * V_10 , struct V_35 * V_36 ,
struct V_1 * V_37 )
{
F_12 ( L_8 , V_37 -> V_3 , V_37 -> V_2 ) ;
F_13 ( V_36 , F_11 ( V_37 -> V_4 ) ) ;
return 0 ;
}
static int F_30 ( struct V_11 * V_12 , struct V_35 * V_36 )
{
struct V_1 * V_37 = ( void * ) V_36 -> V_5 ;
struct V_9 * V_10 = V_12 -> V_5 ;
int V_82 = 0 ;
F_31 ( V_10 ) ;
while ( V_36 -> V_4 >= sizeof( * V_37 ) ) {
struct V_1 * V_37 = ( void * ) V_36 -> V_5 ;
T_2 V_4 = F_11 ( V_37 -> V_4 ) ;
F_12 ( L_9 , V_37 -> V_2 , V_37 -> V_3 , V_4 ) ;
F_13 ( V_36 , sizeof( * V_37 ) ) ;
if ( V_4 > V_36 -> V_4 || ! V_37 -> V_3 ) {
V_82 = - V_40 ;
break;
}
V_10 -> V_3 = V_37 -> V_3 ;
switch ( V_37 -> V_2 ) {
case V_83 :
F_10 ( V_10 , V_36 , V_37 ) ;
break;
case V_84 :
V_82 = F_14 ( V_10 , V_36 , V_37 ) ;
break;
case V_85 :
V_82 = F_21 ( V_10 , V_36 , V_37 ) ;
break;
case V_86 :
V_82 = F_22 ( V_10 , V_36 , V_37 ) ;
break;
case V_87 :
V_82 = F_26 ( V_10 , V_36 , V_37 ) ;
break;
case V_88 :
V_82 = F_27 ( V_10 , V_36 , V_37 ) ;
break;
case V_89 :
V_82 = F_28 ( V_10 , V_36 , V_37 ) ;
break;
case V_90 :
case V_53 :
case V_68 :
case V_71 :
case V_80 :
case V_81 :
V_82 = F_29 ( V_10 , V_36 , V_37 ) ;
break;
default:
F_32 ( L_10 , V_37 -> V_2 ) ;
V_82 = - V_40 ;
break;
}
}
if ( V_82 ) {
struct V_38 V_39 ;
V_39 . V_41 = F_20 ( 0 ) ;
F_12 ( L_11 , V_37 -> V_2 , V_82 ) ;
F_4 ( V_10 , V_83 , V_37 -> V_3 , sizeof( V_39 ) ,
& V_39 ) ;
}
F_33 ( V_36 ) ;
F_34 ( V_10 ) ;
return 0 ;
}
static void F_35 ( struct V_11 * V_12 )
{
F_36 ( V_12 ) ;
}
static void F_37 ( struct V_11 * V_12 , int V_91 )
{
struct V_9 * V_10 = V_12 -> V_5 ;
if ( ! V_10 )
return;
F_12 ( L_12 , V_12 , F_38 ( V_91 ) ) ;
V_12 -> V_91 = V_91 ;
switch ( V_91 ) {
case V_92 :
if ( V_10 )
F_34 ( V_10 ) ;
break;
}
}
static struct V_35 * F_39 ( struct V_11 * V_12 ,
unsigned long V_4 , int V_93 )
{
return F_40 ( V_4 , V_8 ) ;
}
static struct V_11 * F_41 ( struct V_94 * V_95 )
{
struct V_11 * V_12 ;
int V_82 ;
V_12 = F_42 () ;
if ( ! V_12 )
return NULL ;
F_12 ( L_13 , V_12 ) ;
V_12 -> V_96 = V_97 ;
V_12 -> V_98 = V_99 ;
V_12 -> V_100 = & V_101 ;
F_43 ( V_12 ) ;
V_12 -> V_102 = V_12 -> V_103 ;
V_12 -> V_104 = V_12 -> V_105 ;
V_12 -> V_106 = V_107 ;
V_12 -> V_108 = V_109 ;
F_44 ( & V_12 -> V_110 ) ;
V_12 -> V_111 = V_112 ;
V_82 = F_45 ( V_12 ) ;
if ( V_82 < 0 ) {
F_46 ( V_12 , 0 ) ;
return NULL ;
}
V_12 -> V_113 = 0 ;
F_47 ( V_95 , V_12 ) ;
V_12 -> V_114 = V_12 -> V_115 ;
V_12 -> V_116 = V_12 -> V_115 ;
V_12 -> V_91 = V_117 ;
return V_12 ;
}
void F_31 ( struct V_9 * V_10 )
{
F_12 ( L_14 , V_10 , F_48 ( & V_10 -> V_118 . V_119 ) ) ;
F_49 ( & V_10 -> V_118 ) ;
}
static void F_50 ( struct V_118 * V_118 )
{
struct V_9 * V_10 = F_51 ( V_118 , struct V_9 , V_118 ) ;
F_12 ( L_15 , V_10 ) ;
F_6 ( V_10 ) ;
}
int F_34 ( struct V_9 * V_10 )
{
F_12 ( L_14 , V_10 , F_48 ( & V_10 -> V_118 . V_119 ) ) ;
return F_52 ( & V_10 -> V_118 , & F_50 ) ;
}
static struct V_9 * F_53 ( struct V_94 * V_95 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
V_10 = F_2 ( sizeof( * V_10 ) , V_8 ) ;
if ( ! V_10 )
return NULL ;
F_12 ( L_16 , V_95 , V_10 ) ;
V_10 -> V_94 = V_95 ;
V_12 = F_41 ( V_95 ) ;
if ( ! V_12 ) {
F_6 ( V_10 ) ;
return NULL ;
}
V_10 -> V_13 = V_12 ;
V_12 -> V_5 = V_10 ;
V_95 -> V_120 -> V_9 = V_10 ;
F_54 ( & V_10 -> V_118 ) ;
return V_10 ;
}
struct V_11 * F_55 ( struct V_94 * V_95 ,
struct V_35 * V_36 )
{
struct V_9 * V_10 ;
V_10 = F_53 ( V_95 ) ;
if ( ! V_10 ) {
F_32 ( L_17 ) ;
return NULL ;
}
F_12 ( L_18 , V_10 , V_10 -> V_13 ) ;
return V_10 -> V_13 ;
}
