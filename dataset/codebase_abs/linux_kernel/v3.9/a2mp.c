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
void F_4 ( struct V_9 * V_10 , T_1 V_2 , T_1 V_3 , T_2 V_4 , void * V_5 )
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
T_1 F_7 ( struct V_9 * V_10 )
{
if ( ++ V_10 -> V_3 == 0 )
V_10 -> V_3 = 1 ;
return V_10 -> V_3 ;
}
static inline void F_8 ( struct V_24 * V_25 )
{
V_25 -> V_26 = 0 ;
V_25 -> type = 0 ;
V_25 -> V_27 = 1 ;
}
static void F_9 ( struct V_9 * V_10 , struct V_24 * V_25 , T_1 V_28 )
{
int V_29 = 0 ;
struct V_30 * V_31 ;
F_8 ( V_25 ) ;
F_10 (hdev, &hci_dev_list, list) {
if ( V_31 -> V_26 == V_32 )
continue;
if ( ++ V_29 >= V_28 )
return;
V_25 [ V_29 ] . V_26 = V_31 -> V_26 ;
V_25 [ V_29 ] . type = V_31 -> V_33 ;
V_25 [ V_29 ] . V_27 = V_31 -> V_34 ;
}
}
static int F_11 ( struct V_9 * V_10 , struct V_35 * V_36 ,
struct V_1 * V_37 )
{
struct V_38 * V_39 = ( void * ) V_36 -> V_5 ;
if ( F_12 ( V_37 -> V_4 ) < sizeof( * V_39 ) )
return - V_40 ;
F_13 ( L_1 , V_37 -> V_3 , F_12 ( V_39 -> V_41 ) ) ;
F_14 ( V_36 , sizeof( * V_39 ) ) ;
return 0 ;
}
static int F_15 ( struct V_9 * V_10 , struct V_35 * V_36 ,
struct V_1 * V_37 )
{
struct V_42 * V_43 = ( void * ) V_36 -> V_5 ;
T_2 V_4 = F_12 ( V_37 -> V_4 ) ;
struct V_44 * V_45 ;
T_2 V_46 ;
T_1 V_28 ;
if ( V_4 < sizeof( * V_43 ) )
return - V_40 ;
F_14 ( V_36 , sizeof( * V_43 ) ) ;
V_46 = F_12 ( V_43 -> V_46 ) ;
F_13 ( L_2 , F_12 ( V_43 -> V_47 ) , V_46 ) ;
while ( V_46 & V_48 ) {
if ( V_4 < sizeof( V_46 ) )
return - V_40 ;
V_46 = F_16 ( V_36 -> V_5 ) ;
F_13 ( L_3 , V_46 ) ;
V_4 -= sizeof( V_46 ) ;
F_14 ( V_36 , sizeof( V_46 ) ) ;
}
F_17 ( & V_49 ) ;
V_28 = F_18 () ;
V_4 = V_28 * sizeof( struct V_24 ) + sizeof( * V_45 ) ;
V_45 = F_19 ( V_4 , V_50 ) ;
if ( ! V_45 ) {
F_20 ( & V_49 ) ;
return - V_51 ;
}
V_45 -> V_47 = F_21 ( V_52 ) ;
V_45 -> V_46 = 0 ;
F_9 ( V_10 , V_45 -> V_25 , V_28 ) ;
F_20 ( & V_49 ) ;
F_4 ( V_10 , V_53 , V_37 -> V_3 , V_4 , V_45 ) ;
F_6 ( V_45 ) ;
return 0 ;
}
static int F_22 ( struct V_9 * V_10 , struct V_35 * V_36 ,
struct V_1 * V_37 )
{
struct V_44 * V_45 = ( void * ) V_36 -> V_5 ;
T_2 V_4 = F_12 ( V_37 -> V_4 ) ;
struct V_24 * V_25 ;
T_2 V_46 ;
bool V_54 = false ;
if ( V_4 < sizeof( * V_45 ) )
return - V_40 ;
V_4 -= sizeof( * V_45 ) ;
F_14 ( V_36 , sizeof( * V_45 ) ) ;
V_46 = F_12 ( V_45 -> V_46 ) ;
F_13 ( L_2 , F_12 ( V_45 -> V_47 ) , V_46 ) ;
while ( V_46 & V_48 ) {
if ( V_4 < sizeof( V_46 ) )
return - V_40 ;
V_46 = F_16 ( V_36 -> V_5 ) ;
F_13 ( L_3 , V_46 ) ;
V_4 -= sizeof( V_46 ) ;
F_14 ( V_36 , sizeof( V_46 ) ) ;
}
V_25 = ( void * ) V_36 -> V_5 ;
while ( V_4 >= sizeof( * V_25 ) ) {
F_13 ( L_4 , V_25 -> V_26 , V_25 -> type ,
V_25 -> V_27 ) ;
if ( V_25 -> V_26 != V_32 && V_25 -> type == V_55 ) {
struct V_56 V_43 ;
V_54 = true ;
V_43 . V_26 = V_25 -> V_26 ;
F_4 ( V_10 , V_57 , F_7 ( V_10 ) ,
sizeof( V_43 ) , & V_43 ) ;
}
V_4 -= sizeof( * V_25 ) ;
V_25 = ( void * ) F_14 ( V_36 , sizeof( * V_25 ) ) ;
}
if ( ! V_54 ) {
struct V_58 * V_59 = V_10 -> V_58 ;
struct V_11 * V_12 ;
F_23 ( & V_59 -> V_60 ) ;
F_10 (chan, &conn->chan_l, list) {
F_13 ( L_5 , V_12 ,
F_24 ( V_12 -> V_61 ) ) ;
if ( V_12 -> V_62 == V_63 )
continue;
F_25 ( V_12 ) ;
if ( V_12 -> V_61 == V_64 )
F_26 ( V_12 ) ;
F_27 ( V_12 ) ;
}
F_28 ( & V_59 -> V_60 ) ;
}
return 0 ;
}
static int F_29 ( struct V_9 * V_10 , struct V_35 * V_36 ,
struct V_1 * V_37 )
{
struct V_24 * V_25 = ( void * ) V_36 -> V_5 ;
while ( V_36 -> V_4 >= sizeof( * V_25 ) ) {
F_13 ( L_6 , V_25 -> V_26 , V_25 -> type ,
V_25 -> V_27 ) ;
V_25 = (struct V_24 * ) F_14 ( V_36 , sizeof( * V_25 ) ) ;
}
return 0 ;
}
static int F_30 ( struct V_9 * V_10 , struct V_35 * V_36 ,
struct V_1 * V_37 )
{
struct V_56 * V_43 = ( void * ) V_36 -> V_5 ;
struct V_30 * V_31 ;
if ( F_12 ( V_37 -> V_4 ) < sizeof( * V_43 ) )
return - V_40 ;
F_13 ( L_7 , V_43 -> V_26 ) ;
V_31 = F_31 ( V_43 -> V_26 ) ;
if ( ! V_31 || V_31 -> V_65 != V_55 ) {
struct V_66 V_45 ;
V_45 . V_26 = V_43 -> V_26 ;
V_45 . V_27 = V_67 ;
F_4 ( V_10 , V_68 , V_37 -> V_3 , sizeof( V_45 ) ,
& V_45 ) ;
goto V_69;
}
F_32 ( V_70 , & V_10 -> V_61 ) ;
F_33 ( V_31 , V_71 , 0 , NULL ) ;
V_69:
if ( V_31 )
F_34 ( V_31 ) ;
F_14 ( V_36 , sizeof( * V_43 ) ) ;
return 0 ;
}
static int F_35 ( struct V_9 * V_10 , struct V_35 * V_36 ,
struct V_1 * V_37 )
{
struct V_66 * V_45 = (struct V_66 * ) V_36 -> V_5 ;
struct V_72 V_43 ;
struct V_73 * V_74 ;
if ( F_12 ( V_37 -> V_4 ) < sizeof( * V_45 ) )
return - V_40 ;
F_13 ( L_8 , V_45 -> V_26 , V_45 -> V_27 ) ;
if ( V_45 -> V_27 )
return - V_40 ;
V_74 = F_36 ( V_10 , V_45 -> V_26 ) ;
if ( ! V_74 )
return - V_51 ;
V_43 . V_26 = V_45 -> V_26 ;
F_4 ( V_10 , V_75 , F_7 ( V_10 ) , sizeof( V_43 ) ,
& V_43 ) ;
F_14 ( V_36 , sizeof( * V_45 ) ) ;
return 0 ;
}
static int F_37 ( struct V_9 * V_10 , struct V_35 * V_36 ,
struct V_1 * V_37 )
{
struct V_72 * V_43 = ( void * ) V_36 -> V_5 ;
struct V_30 * V_31 ;
struct V_9 * V_76 ;
if ( F_12 ( V_37 -> V_4 ) < sizeof( * V_43 ) )
return - V_40 ;
F_13 ( L_7 , V_43 -> V_26 ) ;
V_76 = F_38 ( V_77 ) ;
V_31 = F_31 ( V_43 -> V_26 ) ;
if ( ! V_31 || V_31 -> V_33 == V_78 || V_76 ) {
struct V_79 V_45 ;
V_45 . V_26 = V_43 -> V_26 ;
if ( V_76 ) {
V_45 . V_27 = V_80 ;
F_39 ( V_76 ) ;
} else {
V_45 . V_27 = V_67 ;
}
F_4 ( V_10 , V_81 , V_37 -> V_3 , sizeof( V_45 ) ,
& V_45 ) ;
goto V_69;
}
F_40 ( V_31 , V_10 ) ;
V_69:
if ( V_31 )
F_34 ( V_31 ) ;
F_14 ( V_36 , sizeof( * V_43 ) ) ;
return 0 ;
}
static int F_41 ( struct V_9 * V_10 , struct V_35 * V_36 ,
struct V_1 * V_37 )
{
struct V_79 * V_45 = ( void * ) V_36 -> V_5 ;
T_2 V_4 = F_12 ( V_37 -> V_4 ) ;
struct V_30 * V_31 ;
struct V_73 * V_74 ;
struct V_82 * V_83 ;
T_3 V_84 ;
if ( V_4 < sizeof( * V_45 ) )
return - V_40 ;
V_84 = V_4 - sizeof( * V_45 ) ;
F_13 ( L_9 , V_45 -> V_26 , V_45 -> V_27 ,
V_84 ) ;
if ( V_45 -> V_27 )
return - V_40 ;
V_74 = F_42 ( V_10 , V_45 -> V_26 ) ;
if ( V_74 ) {
T_1 * V_85 ;
V_85 = F_2 ( V_84 , V_8 ) ;
if ( ! V_85 ) {
F_43 ( V_74 ) ;
return - V_51 ;
}
memcpy ( V_85 , V_45 -> V_86 , V_84 ) ;
V_74 -> V_85 = V_85 ;
V_74 -> V_84 = V_84 ;
V_74 -> V_87 = V_84 ;
V_74 -> V_88 = 0 ;
F_43 ( V_74 ) ;
}
V_31 = F_31 ( V_45 -> V_26 ) ;
if ( ! V_31 )
return - V_40 ;
V_83 = F_44 ( V_31 , V_10 , V_45 -> V_26 , true ) ;
if ( ! V_83 )
goto V_69;
F_13 ( L_10 , V_83 , V_31 -> V_26 , V_45 -> V_26 ) ;
V_10 -> V_89 -> V_90 = V_45 -> V_26 ;
F_45 ( V_31 , V_10 , V_83 ) ;
V_69:
F_34 ( V_31 ) ;
F_14 ( V_36 , V_4 ) ;
return 0 ;
}
static int F_46 ( struct V_9 * V_10 , struct V_35 * V_36 ,
struct V_1 * V_37 )
{
struct V_91 * V_43 = ( void * ) V_36 -> V_5 ;
struct V_92 V_45 ;
struct V_30 * V_31 ;
struct V_82 * V_83 ;
struct V_73 * V_74 ;
if ( F_12 ( V_37 -> V_4 ) < sizeof( * V_43 ) )
return - V_40 ;
F_13 ( L_11 , V_43 -> V_93 , V_43 -> V_94 ) ;
V_45 . V_93 = V_43 -> V_94 ;
V_45 . V_94 = V_43 -> V_93 ;
V_31 = F_31 ( V_43 -> V_94 ) ;
if ( ! V_31 || V_31 -> V_33 != V_55 ) {
V_45 . V_27 = V_67 ;
goto V_95;
}
V_74 = F_42 ( V_10 , V_45 . V_94 ) ;
if ( ! V_74 ) {
V_74 = F_36 ( V_10 , V_45 . V_94 ) ;
if ( V_74 ) {
F_47 ( V_74 ) ;
} else {
V_45 . V_27 = V_96 ;
goto V_95;
}
}
if ( V_74 ) {
T_3 V_84 = F_12 ( V_37 -> V_4 ) - sizeof( * V_43 ) ;
T_1 * V_85 ;
V_85 = F_2 ( V_84 , V_8 ) ;
if ( ! V_85 ) {
F_43 ( V_74 ) ;
return - V_51 ;
}
memcpy ( V_85 , V_43 -> V_86 , V_84 ) ;
V_74 -> V_85 = V_85 ;
V_74 -> V_84 = V_84 ;
V_74 -> V_87 = V_84 ;
V_74 -> V_88 = 0 ;
F_43 ( V_74 ) ;
}
V_83 = F_44 ( V_31 , V_10 , V_43 -> V_93 , false ) ;
if ( V_83 ) {
F_48 ( V_31 , V_10 , V_83 ) ;
V_45 . V_27 = V_97 ;
} else {
V_45 . V_27 = V_96 ;
}
V_95:
if ( V_31 )
F_34 ( V_31 ) ;
if ( V_45 . V_27 != V_97 ) {
F_4 ( V_10 , V_98 , V_37 -> V_3 ,
sizeof( V_45 ) , & V_45 ) ;
} else {
F_32 ( V_99 , & V_10 -> V_61 ) ;
V_10 -> V_3 = V_37 -> V_3 ;
}
F_14 ( V_36 , F_12 ( V_37 -> V_4 ) ) ;
return 0 ;
}
static int F_49 ( struct V_9 * V_10 , struct V_35 * V_36 ,
struct V_1 * V_37 )
{
struct V_91 * V_43 = ( void * ) V_36 -> V_5 ;
struct V_92 V_45 ;
struct V_30 * V_31 ;
struct V_82 * V_83 ;
if ( F_12 ( V_37 -> V_4 ) < sizeof( * V_43 ) )
return - V_40 ;
F_13 ( L_12 , V_43 -> V_93 , V_43 -> V_94 ) ;
V_45 . V_93 = V_43 -> V_94 ;
V_45 . V_94 = V_43 -> V_93 ;
V_45 . V_27 = V_97 ;
V_31 = F_31 ( V_43 -> V_94 ) ;
if ( ! V_31 ) {
V_45 . V_27 = V_67 ;
goto V_95;
}
V_83 = F_50 ( V_31 , V_100 , V_10 -> V_58 -> V_101 ) ;
if ( ! V_83 ) {
F_51 ( L_13 ) ;
V_45 . V_27 = V_102 ;
goto V_103;
}
V_103:
F_34 ( V_31 ) ;
V_95:
F_4 ( V_10 , V_104 , V_37 -> V_3 , sizeof( V_45 ) , & V_45 ) ;
F_14 ( V_36 , sizeof( * V_43 ) ) ;
return 0 ;
}
static inline int F_52 ( struct V_9 * V_10 , struct V_35 * V_36 ,
struct V_1 * V_37 )
{
F_13 ( L_14 , V_37 -> V_3 , V_37 -> V_2 ) ;
F_14 ( V_36 , F_12 ( V_37 -> V_4 ) ) ;
return 0 ;
}
static int F_53 ( struct V_11 * V_12 , struct V_35 * V_36 )
{
struct V_1 * V_37 ;
struct V_9 * V_10 = V_12 -> V_5 ;
int V_105 = 0 ;
F_54 ( V_10 ) ;
while ( V_36 -> V_4 >= sizeof( * V_37 ) ) {
T_2 V_4 ;
V_37 = ( void * ) V_36 -> V_5 ;
V_4 = F_12 ( V_37 -> V_4 ) ;
F_13 ( L_15 , V_37 -> V_2 , V_37 -> V_3 , V_4 ) ;
F_14 ( V_36 , sizeof( * V_37 ) ) ;
if ( V_4 > V_36 -> V_4 || ! V_37 -> V_3 ) {
V_105 = - V_40 ;
break;
}
V_10 -> V_3 = V_37 -> V_3 ;
switch ( V_37 -> V_2 ) {
case V_106 :
F_11 ( V_10 , V_36 , V_37 ) ;
break;
case V_107 :
V_105 = F_15 ( V_10 , V_36 , V_37 ) ;
break;
case V_108 :
V_105 = F_29 ( V_10 , V_36 , V_37 ) ;
break;
case V_57 :
V_105 = F_30 ( V_10 , V_36 , V_37 ) ;
break;
case V_75 :
V_105 = F_37 ( V_10 , V_36 , V_37 ) ;
break;
case V_109 :
V_105 = F_46 ( V_10 , V_36 , V_37 ) ;
break;
case V_110 :
V_105 = F_49 ( V_10 , V_36 , V_37 ) ;
break;
case V_53 :
V_105 = F_22 ( V_10 , V_36 , V_37 ) ;
break;
case V_68 :
V_105 = F_35 ( V_10 , V_36 , V_37 ) ;
break;
case V_81 :
V_105 = F_41 ( V_10 , V_36 , V_37 ) ;
break;
case V_111 :
case V_98 :
case V_104 :
V_105 = F_52 ( V_10 , V_36 , V_37 ) ;
break;
default:
F_51 ( L_16 , V_37 -> V_2 ) ;
V_105 = - V_40 ;
break;
}
}
if ( V_105 ) {
struct V_38 V_39 ;
V_39 . V_41 = F_21 ( 0 ) ;
V_37 = ( void * ) V_36 -> V_5 ;
F_13 ( L_17 , V_37 -> V_2 , V_105 ) ;
F_4 ( V_10 , V_106 , V_37 -> V_3 , sizeof( V_39 ) ,
& V_39 ) ;
}
F_55 ( V_36 ) ;
F_39 ( V_10 ) ;
return 0 ;
}
static void F_56 ( struct V_11 * V_12 )
{
F_57 ( V_12 ) ;
}
static void F_58 ( struct V_11 * V_12 , int V_61 )
{
struct V_9 * V_10 = V_12 -> V_5 ;
if ( ! V_10 )
return;
F_13 ( L_5 , V_12 , F_24 ( V_61 ) ) ;
V_12 -> V_61 = V_61 ;
switch ( V_61 ) {
case V_112 :
if ( V_10 )
F_39 ( V_10 ) ;
break;
}
}
static struct V_35 * F_59 ( struct V_11 * V_12 ,
unsigned long V_4 , int V_113 )
{
return F_60 ( V_4 , V_8 ) ;
}
static struct V_11 * F_61 ( struct V_58 * V_59 , bool V_114 )
{
struct V_11 * V_12 ;
int V_105 ;
V_12 = F_62 () ;
if ( ! V_12 )
return NULL ;
F_13 ( L_18 , V_12 ) ;
V_12 -> V_62 = V_63 ;
V_12 -> V_115 = V_116 ;
V_12 -> V_117 = & V_118 ;
F_63 ( V_12 ) ;
V_12 -> V_119 = V_12 -> V_120 ;
V_12 -> V_121 = V_12 -> V_122 ;
V_12 -> V_123 = V_124 ;
V_12 -> V_125 = V_126 ;
F_64 ( & V_12 -> V_127 ) ;
V_12 -> V_128 = V_129 ;
V_105 = F_65 ( V_12 ) ;
if ( V_105 < 0 ) {
F_66 ( V_12 , 0 ) ;
return NULL ;
}
V_12 -> V_130 = 0 ;
if ( V_114 )
F_67 ( V_59 , V_12 ) ;
else
F_68 ( V_59 , V_12 ) ;
V_12 -> V_131 = V_12 -> V_132 ;
V_12 -> V_133 = V_12 -> V_132 ;
V_12 -> V_61 = V_134 ;
return V_12 ;
}
struct V_9 * F_54 ( struct V_9 * V_10 )
{
F_13 ( L_19 , V_10 , F_69 ( & V_10 -> V_135 . V_136 ) ) ;
F_70 ( & V_10 -> V_135 ) ;
return V_10 ;
}
static void F_71 ( struct V_135 * V_135 )
{
struct V_9 * V_10 = F_72 ( V_135 , struct V_9 , V_135 ) ;
F_13 ( L_20 , V_10 ) ;
F_23 ( & V_137 ) ;
F_73 ( & V_10 -> V_138 ) ;
F_28 ( & V_137 ) ;
F_74 ( V_10 ) ;
F_6 ( V_10 ) ;
}
int F_39 ( struct V_9 * V_10 )
{
F_13 ( L_19 , V_10 , F_69 ( & V_10 -> V_135 . V_136 ) ) ;
return F_75 ( & V_10 -> V_135 , & F_71 ) ;
}
static struct V_9 * F_76 ( struct V_58 * V_59 , bool V_114 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
V_10 = F_2 ( sizeof( * V_10 ) , V_8 ) ;
if ( ! V_10 )
return NULL ;
F_13 ( L_21 , V_59 , V_10 ) ;
V_10 -> V_58 = V_59 ;
V_12 = F_61 ( V_59 , V_114 ) ;
if ( ! V_12 ) {
F_6 ( V_10 ) ;
return NULL ;
}
V_10 -> V_13 = V_12 ;
V_12 -> V_5 = V_10 ;
V_59 -> V_83 -> V_9 = V_10 ;
F_77 ( & V_10 -> V_135 ) ;
F_78 ( & V_10 -> V_139 ) ;
F_79 ( & V_10 -> V_140 ) ;
F_23 ( & V_137 ) ;
F_80 ( & V_10 -> V_138 , & V_141 ) ;
F_28 ( & V_137 ) ;
return V_10 ;
}
struct V_11 * F_81 ( struct V_58 * V_59 ,
struct V_35 * V_36 )
{
struct V_9 * V_10 ;
V_10 = F_76 ( V_59 , false ) ;
if ( ! V_10 ) {
F_51 ( L_22 ) ;
return NULL ;
}
F_13 ( L_23 , V_10 , V_10 -> V_13 ) ;
return V_10 -> V_13 ;
}
struct V_9 * F_38 ( T_1 V_61 )
{
struct V_9 * V_10 ;
F_23 ( & V_137 ) ;
F_10 (mgr, &amp_mgr_list, list) {
if ( F_82 ( V_61 , & V_10 -> V_61 ) ) {
F_54 ( V_10 ) ;
F_28 ( & V_137 ) ;
return V_10 ;
}
}
F_28 ( & V_137 ) ;
return NULL ;
}
void F_83 ( struct V_30 * V_31 )
{
struct V_9 * V_10 ;
struct V_66 V_45 ;
V_10 = F_38 ( V_70 ) ;
if ( ! V_10 )
return;
F_13 ( L_24 , V_31 -> V_142 , V_10 ) ;
V_45 . V_26 = V_31 -> V_26 ;
V_45 . V_27 = V_67 ;
if ( V_31 -> V_33 != V_78 ) {
V_45 . V_27 = 0 ;
V_45 . V_143 = F_84 ( V_31 -> V_144 ) ;
V_45 . V_145 = F_84 ( V_31 -> V_146 ) ;
V_45 . V_147 = F_84 ( V_31 -> V_148 ) ;
V_45 . V_149 = F_3 ( V_31 -> V_150 ) ;
V_45 . V_151 = F_3 ( V_31 -> V_152 ) ;
}
F_4 ( V_10 , V_68 , V_10 -> V_3 , sizeof( V_45 ) , & V_45 ) ;
F_39 ( V_10 ) ;
}
void F_85 ( struct V_30 * V_31 , T_1 V_27 )
{
struct V_9 * V_10 ;
struct V_86 * V_153 = & V_31 -> V_153 ;
struct V_79 * V_45 ;
T_3 V_4 ;
V_10 = F_38 ( V_77 ) ;
if ( ! V_10 )
return;
F_13 ( L_24 , V_31 -> V_142 , V_10 ) ;
V_4 = sizeof( struct V_79 ) + V_153 -> V_4 ;
V_45 = F_2 ( V_4 , V_8 ) ;
if ( ! V_45 ) {
F_39 ( V_10 ) ;
return;
}
V_45 -> V_26 = V_31 -> V_26 ;
if ( V_27 ) {
V_45 -> V_27 = V_67 ;
} else {
V_45 -> V_27 = V_97 ;
memcpy ( V_45 -> V_86 , V_153 -> V_5 , V_153 -> V_4 ) ;
}
F_4 ( V_10 , V_81 , V_10 -> V_3 , V_4 , V_45 ) ;
F_39 ( V_10 ) ;
F_6 ( V_45 ) ;
}
void F_86 ( struct V_30 * V_31 , T_1 V_27 )
{
struct V_9 * V_10 ;
struct V_86 * V_153 = & V_31 -> V_153 ;
struct V_91 * V_43 ;
struct V_11 * V_89 ;
T_3 V_4 ;
V_10 = F_38 ( V_154 ) ;
if ( ! V_10 )
return;
V_4 = sizeof( * V_43 ) + V_153 -> V_4 ;
F_13 ( L_25 , V_31 -> V_142 , V_10 , V_4 ) ;
V_43 = F_2 ( V_4 , V_8 ) ;
if ( ! V_43 ) {
F_39 ( V_10 ) ;
return;
}
V_89 = V_10 -> V_89 ;
if ( ! V_89 )
goto V_103;
V_43 -> V_93 = V_31 -> V_26 ;
V_43 -> V_94 = V_89 -> V_90 ;
memcpy ( V_43 -> V_86 , V_153 -> V_5 , V_153 -> V_4 ) ;
F_4 ( V_10 , V_109 , F_7 ( V_10 ) , V_4 , V_43 ) ;
V_103:
F_39 ( V_10 ) ;
F_6 ( V_43 ) ;
}
void F_87 ( struct V_30 * V_31 , T_1 V_27 )
{
struct V_9 * V_10 ;
struct V_92 V_45 ;
struct V_82 * V_155 ;
V_10 = F_38 ( V_99 ) ;
if ( ! V_10 )
return;
V_155 = F_88 ( V_31 , V_100 , V_64 ) ;
if ( ! V_155 ) {
V_45 . V_27 = V_96 ;
} else {
V_45 . V_94 = V_155 -> V_94 ;
V_45 . V_27 = V_97 ;
}
F_13 ( L_26 , V_31 -> V_142 , V_10 , V_155 ,
V_27 ) ;
V_45 . V_93 = V_31 -> V_26 ;
F_4 ( V_10 , V_98 , V_10 -> V_3 , sizeof( V_45 ) , & V_45 ) ;
F_39 ( V_10 ) ;
}
void F_89 ( struct V_11 * V_12 )
{
struct V_58 * V_59 = V_12 -> V_59 ;
struct V_9 * V_10 = V_59 -> V_83 -> V_9 ;
struct V_42 V_43 ;
F_13 ( L_27 , V_12 , V_59 , V_10 ) ;
if ( ! V_10 ) {
V_10 = F_76 ( V_59 , true ) ;
if ( ! V_10 )
return;
}
V_10 -> V_89 = V_12 ;
V_43 . V_47 = F_3 ( V_52 ) ;
V_43 . V_46 = 0 ;
F_4 ( V_10 , V_107 , 1 , sizeof( V_43 ) , & V_43 ) ;
}
