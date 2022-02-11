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
static void F_4 ( struct V_9 * V_10 , T_1 V_2 , T_1 V_3 , T_2 V_4 , void * V_5 )
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
F_5 ( & V_18 . V_21 , V_22 | V_23 , & V_16 , 1 , V_14 ) ;
F_6 ( V_12 , & V_18 , V_14 ) ;
F_7 ( V_6 ) ;
}
static T_1 F_8 ( struct V_9 * V_10 )
{
if ( ++ V_10 -> V_3 == 0 )
V_10 -> V_3 = 1 ;
return V_10 -> V_3 ;
}
static struct V_9 * F_9 ( T_1 V_24 )
{
struct V_9 * V_10 ;
F_10 ( & V_25 ) ;
F_11 (mgr, &amp_mgr_list, list) {
if ( F_12 ( V_24 , & V_10 -> V_24 ) ) {
F_13 ( V_10 ) ;
F_14 ( & V_25 ) ;
return V_10 ;
}
}
F_14 ( & V_25 ) ;
return NULL ;
}
static void F_15 ( struct V_9 * V_10 , struct V_26 * V_27 )
{
struct V_28 * V_29 ;
int V_30 = 1 ;
V_27 [ 0 ] . V_31 = V_32 ;
V_27 [ 0 ] . type = V_33 ;
V_27 [ 0 ] . V_34 = V_35 ;
F_11 (hdev, &hci_dev_list, list) {
if ( V_29 -> V_36 == V_37 ) {
V_27 [ V_30 ] . V_31 = V_29 -> V_31 ;
V_27 [ V_30 ] . type = V_29 -> V_38 ;
if ( F_16 ( V_39 , & V_29 -> V_40 ) )
V_27 [ V_30 ] . V_34 = V_29 -> V_41 ;
else
V_27 [ V_30 ] . V_34 = V_42 ;
V_30 ++ ;
}
}
}
static int F_17 ( struct V_9 * V_10 , struct V_43 * V_44 ,
struct V_1 * V_45 )
{
struct V_46 * V_47 = ( void * ) V_44 -> V_5 ;
if ( F_18 ( V_45 -> V_4 ) < sizeof( * V_47 ) )
return - V_48 ;
F_19 ( L_1 , V_45 -> V_3 , F_18 ( V_47 -> V_49 ) ) ;
F_20 ( V_44 , sizeof( * V_47 ) ) ;
return 0 ;
}
static int F_21 ( struct V_9 * V_10 , struct V_43 * V_44 ,
struct V_1 * V_45 )
{
struct V_50 * V_51 = ( void * ) V_44 -> V_5 ;
T_2 V_4 = F_18 ( V_45 -> V_4 ) ;
struct V_52 * V_53 ;
T_2 V_54 ;
T_1 V_55 ;
struct V_28 * V_29 ;
if ( V_4 < sizeof( * V_51 ) )
return - V_48 ;
F_20 ( V_44 , sizeof( * V_51 ) ) ;
V_54 = F_18 ( V_51 -> V_54 ) ;
F_19 ( L_2 , F_18 ( V_51 -> V_56 ) , V_54 ) ;
while ( V_54 & V_57 ) {
if ( V_4 < sizeof( V_54 ) )
return - V_48 ;
V_54 = F_22 ( V_44 -> V_5 ) ;
F_19 ( L_3 , V_54 ) ;
V_4 -= sizeof( V_54 ) ;
F_20 ( V_44 , sizeof( V_54 ) ) ;
}
F_23 ( & V_58 ) ;
V_55 = 1 ;
F_11 (hdev, &hci_dev_list, list) {
if ( V_29 -> V_36 == V_37 )
V_55 ++ ;
}
V_4 = V_55 * sizeof( struct V_26 ) + sizeof( * V_53 ) ;
V_53 = F_24 ( V_4 , V_59 ) ;
if ( ! V_53 ) {
F_25 ( & V_58 ) ;
return - V_60 ;
}
V_53 -> V_56 = F_3 ( V_61 ) ;
V_53 -> V_54 = 0 ;
F_15 ( V_10 , V_53 -> V_27 ) ;
F_25 ( & V_58 ) ;
F_4 ( V_10 , V_62 , V_45 -> V_3 , V_4 , V_53 ) ;
F_7 ( V_53 ) ;
return 0 ;
}
static int F_26 ( struct V_9 * V_10 , struct V_43 * V_44 ,
struct V_1 * V_45 )
{
struct V_52 * V_53 = ( void * ) V_44 -> V_5 ;
T_2 V_4 = F_18 ( V_45 -> V_4 ) ;
struct V_26 * V_27 ;
T_2 V_54 ;
bool V_63 = false ;
if ( V_4 < sizeof( * V_53 ) )
return - V_48 ;
V_4 -= sizeof( * V_53 ) ;
F_20 ( V_44 , sizeof( * V_53 ) ) ;
V_54 = F_18 ( V_53 -> V_54 ) ;
F_19 ( L_2 , F_18 ( V_53 -> V_56 ) , V_54 ) ;
while ( V_54 & V_57 ) {
if ( V_4 < sizeof( V_54 ) )
return - V_48 ;
V_54 = F_22 ( V_44 -> V_5 ) ;
F_19 ( L_3 , V_54 ) ;
V_4 -= sizeof( V_54 ) ;
F_20 ( V_44 , sizeof( V_54 ) ) ;
}
V_27 = ( void * ) V_44 -> V_5 ;
while ( V_4 >= sizeof( * V_27 ) ) {
F_19 ( L_4 , V_27 -> V_31 , V_27 -> type ,
V_27 -> V_34 ) ;
if ( V_27 -> V_31 != V_32 && V_27 -> type != V_33 ) {
struct V_64 V_51 ;
V_63 = true ;
V_51 . V_31 = V_27 -> V_31 ;
F_4 ( V_10 , V_65 , F_8 ( V_10 ) ,
sizeof( V_51 ) , & V_51 ) ;
}
V_4 -= sizeof( * V_27 ) ;
V_27 = ( void * ) F_20 ( V_44 , sizeof( * V_27 ) ) ;
}
if ( ! V_63 ) {
struct V_66 * V_67 = V_10 -> V_66 ;
struct V_11 * V_12 ;
F_10 ( & V_67 -> V_68 ) ;
F_11 (chan, &conn->chan_l, list) {
F_19 ( L_5 , V_12 ,
F_27 ( V_12 -> V_24 ) ) ;
if ( V_12 -> V_69 == V_70 )
continue;
F_28 ( V_12 ) ;
if ( V_12 -> V_24 == V_71 )
F_29 ( V_12 ) ;
F_30 ( V_12 ) ;
}
F_14 ( & V_67 -> V_68 ) ;
}
return 0 ;
}
static int F_31 ( struct V_9 * V_10 , struct V_43 * V_44 ,
struct V_1 * V_45 )
{
struct V_26 * V_27 = ( void * ) V_44 -> V_5 ;
while ( V_44 -> V_4 >= sizeof( * V_27 ) ) {
F_19 ( L_6 , V_27 -> V_31 , V_27 -> type ,
V_27 -> V_34 ) ;
V_27 = (struct V_26 * ) F_20 ( V_44 , sizeof( * V_27 ) ) ;
}
return 0 ;
}
static void F_32 ( struct V_28 * V_29 , T_1 V_34 ,
T_2 V_72 )
{
F_19 ( L_7 , V_29 -> V_73 , V_34 ) ;
F_33 ( V_29 ) ;
}
static int F_34 ( struct V_9 * V_10 , struct V_43 * V_44 ,
struct V_1 * V_45 )
{
struct V_64 * V_51 = ( void * ) V_44 -> V_5 ;
struct V_28 * V_29 ;
struct V_74 V_75 ;
int V_76 = 0 ;
if ( F_18 ( V_45 -> V_4 ) < sizeof( * V_51 ) )
return - V_48 ;
F_19 ( L_8 , V_51 -> V_31 ) ;
V_29 = F_35 ( V_51 -> V_31 ) ;
if ( ! V_29 || V_29 -> V_36 != V_37 ) {
struct V_77 V_53 ;
V_53 . V_31 = V_51 -> V_31 ;
V_53 . V_34 = V_78 ;
F_4 ( V_10 , V_79 , V_45 -> V_3 , sizeof( V_53 ) ,
& V_53 ) ;
goto V_80;
}
F_36 ( V_81 , & V_10 -> V_24 ) ;
F_37 ( & V_75 , V_29 ) ;
F_38 ( & V_75 , V_82 , 0 , NULL ) ;
V_76 = F_39 ( & V_75 , F_32 ) ;
if ( V_76 < 0 )
F_33 ( V_29 ) ;
V_80:
if ( V_29 )
F_40 ( V_29 ) ;
F_20 ( V_44 , sizeof( * V_51 ) ) ;
return 0 ;
}
static int F_41 ( struct V_9 * V_10 , struct V_43 * V_44 ,
struct V_1 * V_45 )
{
struct V_77 * V_53 = (struct V_77 * ) V_44 -> V_5 ;
struct V_83 V_51 ;
struct V_84 * V_85 ;
if ( F_18 ( V_45 -> V_4 ) < sizeof( * V_53 ) )
return - V_48 ;
F_19 ( L_9 , V_53 -> V_31 , V_53 -> V_34 ) ;
if ( V_53 -> V_34 )
return - V_48 ;
V_85 = F_42 ( V_10 , V_53 -> V_31 ) ;
if ( ! V_85 )
return - V_60 ;
V_51 . V_31 = V_53 -> V_31 ;
F_4 ( V_10 , V_86 , F_8 ( V_10 ) , sizeof( V_51 ) ,
& V_51 ) ;
F_20 ( V_44 , sizeof( * V_53 ) ) ;
return 0 ;
}
static int F_43 ( struct V_9 * V_10 , struct V_43 * V_44 ,
struct V_1 * V_45 )
{
struct V_83 * V_51 = ( void * ) V_44 -> V_5 ;
struct V_28 * V_29 ;
struct V_9 * V_87 ;
if ( F_18 ( V_45 -> V_4 ) < sizeof( * V_51 ) )
return - V_48 ;
F_19 ( L_8 , V_51 -> V_31 ) ;
V_87 = F_9 ( V_88 ) ;
V_29 = F_35 ( V_51 -> V_31 ) ;
if ( ! V_29 || V_29 -> V_38 == V_33 || V_87 ) {
struct V_89 V_53 ;
V_53 . V_31 = V_51 -> V_31 ;
if ( V_87 ) {
V_53 . V_34 = V_90 ;
F_44 ( V_87 ) ;
} else {
V_53 . V_34 = V_78 ;
}
F_4 ( V_10 , V_91 , V_45 -> V_3 , sizeof( V_53 ) ,
& V_53 ) ;
goto V_80;
}
F_45 ( V_29 , V_10 ) ;
V_80:
if ( V_29 )
F_40 ( V_29 ) ;
F_20 ( V_44 , sizeof( * V_51 ) ) ;
return 0 ;
}
static int F_46 ( struct V_9 * V_10 , struct V_43 * V_44 ,
struct V_1 * V_45 )
{
struct V_89 * V_53 = ( void * ) V_44 -> V_5 ;
T_2 V_4 = F_18 ( V_45 -> V_4 ) ;
struct V_28 * V_29 ;
struct V_84 * V_85 ;
struct V_92 * V_93 ;
T_3 V_94 ;
if ( V_4 < sizeof( * V_53 ) )
return - V_48 ;
V_94 = V_4 - sizeof( * V_53 ) ;
F_19 ( L_10 , V_53 -> V_31 , V_53 -> V_34 ,
V_94 ) ;
if ( V_53 -> V_34 )
return - V_48 ;
V_85 = F_47 ( V_10 , V_53 -> V_31 ) ;
if ( V_85 ) {
T_1 * V_95 ;
V_95 = F_48 ( V_53 -> V_96 , V_94 , V_8 ) ;
if ( ! V_95 ) {
F_49 ( V_85 ) ;
return - V_60 ;
}
V_85 -> V_95 = V_95 ;
V_85 -> V_94 = V_94 ;
V_85 -> V_97 = V_94 ;
V_85 -> V_98 = 0 ;
F_49 ( V_85 ) ;
}
V_29 = F_35 ( V_53 -> V_31 ) ;
if ( ! V_29 )
return - V_48 ;
V_93 = F_50 ( V_29 , V_10 , V_53 -> V_31 , true ) ;
if ( ! V_93 )
goto V_80;
F_19 ( L_11 , V_93 , V_29 -> V_31 , V_53 -> V_31 ) ;
V_10 -> V_99 -> V_100 = V_53 -> V_31 ;
F_51 ( V_29 , V_10 , V_93 ) ;
V_80:
F_40 ( V_29 ) ;
F_20 ( V_44 , V_4 ) ;
return 0 ;
}
static int F_52 ( struct V_9 * V_10 , struct V_43 * V_44 ,
struct V_1 * V_45 )
{
struct V_101 * V_51 = ( void * ) V_44 -> V_5 ;
struct V_102 V_53 ;
struct V_28 * V_29 ;
struct V_92 * V_93 ;
struct V_84 * V_85 ;
if ( F_18 ( V_45 -> V_4 ) < sizeof( * V_51 ) )
return - V_48 ;
F_19 ( L_12 , V_51 -> V_103 , V_51 -> V_104 ) ;
V_53 . V_103 = V_51 -> V_104 ;
V_53 . V_104 = V_51 -> V_103 ;
V_29 = F_35 ( V_51 -> V_104 ) ;
if ( ! V_29 || V_29 -> V_38 == V_33 ) {
V_53 . V_34 = V_78 ;
goto V_105;
}
V_85 = F_47 ( V_10 , V_53 . V_104 ) ;
if ( ! V_85 ) {
V_85 = F_42 ( V_10 , V_53 . V_104 ) ;
if ( V_85 ) {
F_53 ( V_85 ) ;
} else {
V_53 . V_34 = V_106 ;
goto V_105;
}
}
if ( V_85 ) {
T_3 V_94 = F_18 ( V_45 -> V_4 ) - sizeof( * V_51 ) ;
T_1 * V_95 ;
V_95 = F_48 ( V_51 -> V_96 , V_94 , V_8 ) ;
if ( ! V_95 ) {
F_49 ( V_85 ) ;
return - V_60 ;
}
V_85 -> V_95 = V_95 ;
V_85 -> V_94 = V_94 ;
V_85 -> V_97 = V_94 ;
V_85 -> V_98 = 0 ;
F_49 ( V_85 ) ;
}
V_93 = F_50 ( V_29 , V_10 , V_51 -> V_103 , false ) ;
if ( V_93 ) {
F_54 ( V_29 , V_10 , V_93 ) ;
V_53 . V_34 = V_107 ;
} else {
V_53 . V_34 = V_106 ;
}
V_105:
if ( V_29 )
F_40 ( V_29 ) ;
if ( V_53 . V_34 != V_107 ) {
F_4 ( V_10 , V_108 , V_45 -> V_3 ,
sizeof( V_53 ) , & V_53 ) ;
} else {
F_36 ( V_109 , & V_10 -> V_24 ) ;
V_10 -> V_3 = V_45 -> V_3 ;
}
F_20 ( V_44 , F_18 ( V_45 -> V_4 ) ) ;
return 0 ;
}
static int F_55 ( struct V_9 * V_10 , struct V_43 * V_44 ,
struct V_1 * V_45 )
{
struct V_101 * V_51 = ( void * ) V_44 -> V_5 ;
struct V_102 V_53 ;
struct V_28 * V_29 ;
struct V_92 * V_93 ;
if ( F_18 ( V_45 -> V_4 ) < sizeof( * V_51 ) )
return - V_48 ;
F_19 ( L_13 , V_51 -> V_103 , V_51 -> V_104 ) ;
V_53 . V_103 = V_51 -> V_104 ;
V_53 . V_104 = V_51 -> V_103 ;
V_53 . V_34 = V_107 ;
V_29 = F_35 ( V_51 -> V_104 ) ;
if ( ! V_29 ) {
V_53 . V_34 = V_78 ;
goto V_105;
}
V_93 = F_56 ( V_29 , V_110 ,
& V_10 -> V_66 -> V_93 -> V_111 ) ;
if ( ! V_93 ) {
F_57 ( L_14 ) ;
V_53 . V_34 = V_112 ;
goto V_113;
}
V_113:
F_40 ( V_29 ) ;
V_105:
F_4 ( V_10 , V_114 , V_45 -> V_3 , sizeof( V_53 ) , & V_53 ) ;
F_20 ( V_44 , sizeof( * V_51 ) ) ;
return 0 ;
}
static inline int F_58 ( struct V_9 * V_10 , struct V_43 * V_44 ,
struct V_1 * V_45 )
{
F_19 ( L_15 , V_45 -> V_3 , V_45 -> V_2 ) ;
F_20 ( V_44 , F_18 ( V_45 -> V_4 ) ) ;
return 0 ;
}
static int F_59 ( struct V_11 * V_12 , struct V_43 * V_44 )
{
struct V_1 * V_45 ;
struct V_9 * V_10 = V_12 -> V_5 ;
int V_76 = 0 ;
F_13 ( V_10 ) ;
while ( V_44 -> V_4 >= sizeof( * V_45 ) ) {
T_2 V_4 ;
V_45 = ( void * ) V_44 -> V_5 ;
V_4 = F_18 ( V_45 -> V_4 ) ;
F_19 ( L_16 , V_45 -> V_2 , V_45 -> V_3 , V_4 ) ;
F_20 ( V_44 , sizeof( * V_45 ) ) ;
if ( V_4 > V_44 -> V_4 || ! V_45 -> V_3 ) {
V_76 = - V_48 ;
break;
}
V_10 -> V_3 = V_45 -> V_3 ;
switch ( V_45 -> V_2 ) {
case V_115 :
F_17 ( V_10 , V_44 , V_45 ) ;
break;
case V_116 :
V_76 = F_21 ( V_10 , V_44 , V_45 ) ;
break;
case V_117 :
V_76 = F_31 ( V_10 , V_44 , V_45 ) ;
break;
case V_65 :
V_76 = F_34 ( V_10 , V_44 , V_45 ) ;
break;
case V_86 :
V_76 = F_43 ( V_10 , V_44 , V_45 ) ;
break;
case V_118 :
V_76 = F_52 ( V_10 , V_44 , V_45 ) ;
break;
case V_119 :
V_76 = F_55 ( V_10 , V_44 , V_45 ) ;
break;
case V_62 :
V_76 = F_26 ( V_10 , V_44 , V_45 ) ;
break;
case V_79 :
V_76 = F_41 ( V_10 , V_44 , V_45 ) ;
break;
case V_91 :
V_76 = F_46 ( V_10 , V_44 , V_45 ) ;
break;
case V_120 :
case V_108 :
case V_114 :
V_76 = F_58 ( V_10 , V_44 , V_45 ) ;
break;
default:
F_57 ( L_17 , V_45 -> V_2 ) ;
V_76 = - V_48 ;
break;
}
}
if ( V_76 ) {
struct V_46 V_47 ;
V_47 . V_49 = F_3 ( 0 ) ;
V_45 = ( void * ) V_44 -> V_5 ;
F_19 ( L_18 , V_45 -> V_2 , V_76 ) ;
F_4 ( V_10 , V_115 , V_45 -> V_3 , sizeof( V_47 ) ,
& V_47 ) ;
}
F_60 ( V_44 ) ;
F_44 ( V_10 ) ;
return 0 ;
}
static void F_61 ( struct V_11 * V_12 )
{
F_62 ( V_12 ) ;
}
static void F_63 ( struct V_11 * V_12 , int V_24 ,
int V_76 )
{
struct V_9 * V_10 = V_12 -> V_5 ;
if ( ! V_10 )
return;
F_19 ( L_5 , V_12 , F_27 ( V_24 ) ) ;
V_12 -> V_24 = V_24 ;
switch ( V_24 ) {
case V_121 :
if ( V_10 )
F_44 ( V_10 ) ;
break;
}
}
static struct V_43 * F_64 ( struct V_11 * V_12 ,
unsigned long V_122 ,
unsigned long V_4 , int V_123 )
{
struct V_43 * V_44 ;
V_44 = F_65 ( V_122 + V_4 , V_8 ) ;
if ( ! V_44 )
return F_66 ( - V_60 ) ;
return V_44 ;
}
static struct V_11 * F_67 ( struct V_66 * V_67 , bool V_124 )
{
struct V_11 * V_12 ;
int V_76 ;
V_12 = F_68 () ;
if ( ! V_12 )
return NULL ;
F_19 ( L_19 , V_12 ) ;
V_12 -> V_125 = V_126 ;
V_12 -> V_69 = V_70 ;
V_12 -> V_127 = V_70 ;
V_12 -> V_128 = V_61 ;
V_12 -> V_129 = V_61 ;
V_12 -> V_130 = V_131 ;
V_12 -> V_132 = & V_133 ;
F_69 ( V_12 ) ;
V_12 -> V_134 = V_12 -> V_135 ;
V_12 -> V_136 = V_12 -> V_137 ;
V_12 -> V_138 = V_139 ;
V_12 -> V_140 = V_141 ;
F_70 ( & V_12 -> V_142 ) ;
V_12 -> V_143 = V_144 ;
V_76 = F_71 ( V_12 ) ;
if ( V_76 < 0 ) {
F_72 ( V_12 , 0 ) ;
return NULL ;
}
V_12 -> V_145 = 0 ;
if ( V_124 )
F_73 ( V_67 , V_12 ) ;
else
F_74 ( V_67 , V_12 ) ;
V_12 -> V_146 = V_12 -> V_128 ;
V_12 -> V_147 = V_12 -> V_128 ;
V_12 -> V_24 = V_148 ;
return V_12 ;
}
struct V_9 * F_13 ( struct V_9 * V_10 )
{
F_19 ( L_20 , V_10 , F_75 ( & V_10 -> V_149 . V_150 ) ) ;
F_76 ( & V_10 -> V_149 ) ;
return V_10 ;
}
static void F_77 ( struct V_149 * V_149 )
{
struct V_9 * V_10 = F_78 ( V_149 , struct V_9 , V_149 ) ;
F_19 ( L_21 , V_10 ) ;
F_10 ( & V_25 ) ;
F_79 ( & V_10 -> V_151 ) ;
F_14 ( & V_25 ) ;
F_80 ( V_10 ) ;
F_7 ( V_10 ) ;
}
int F_44 ( struct V_9 * V_10 )
{
F_19 ( L_20 , V_10 , F_75 ( & V_10 -> V_149 . V_150 ) ) ;
return F_81 ( & V_10 -> V_149 , & F_77 ) ;
}
static struct V_9 * F_82 ( struct V_66 * V_67 , bool V_124 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
V_10 = F_2 ( sizeof( * V_10 ) , V_8 ) ;
if ( ! V_10 )
return NULL ;
F_19 ( L_22 , V_67 , V_10 ) ;
V_10 -> V_66 = V_67 ;
V_12 = F_67 ( V_67 , V_124 ) ;
if ( ! V_12 ) {
F_7 ( V_10 ) ;
return NULL ;
}
V_10 -> V_13 = V_12 ;
V_12 -> V_5 = V_10 ;
V_67 -> V_93 -> V_9 = V_10 ;
F_83 ( & V_10 -> V_149 ) ;
F_84 ( & V_10 -> V_152 ) ;
F_85 ( & V_10 -> V_153 ) ;
F_10 ( & V_25 ) ;
F_86 ( & V_10 -> V_151 , & V_154 ) ;
F_14 ( & V_25 ) ;
return V_10 ;
}
struct V_11 * F_87 ( struct V_66 * V_67 ,
struct V_43 * V_44 )
{
struct V_9 * V_10 ;
if ( V_67 -> V_93 -> type != V_155 )
return NULL ;
V_10 = F_82 ( V_67 , false ) ;
if ( ! V_10 ) {
F_57 ( L_23 ) ;
return NULL ;
}
F_19 ( L_24 , V_10 , V_10 -> V_13 ) ;
return V_10 -> V_13 ;
}
void F_33 ( struct V_28 * V_29 )
{
struct V_9 * V_10 ;
struct V_77 V_53 ;
V_10 = F_9 ( V_81 ) ;
if ( ! V_10 )
return;
F_19 ( L_25 , V_29 -> V_73 , V_10 ) ;
V_53 . V_31 = V_29 -> V_31 ;
V_53 . V_34 = V_78 ;
if ( V_29 -> V_38 != V_33 ) {
V_53 . V_34 = 0 ;
V_53 . V_156 = F_88 ( V_29 -> V_157 ) ;
V_53 . V_158 = F_88 ( V_29 -> V_159 ) ;
V_53 . V_160 = F_88 ( V_29 -> V_161 ) ;
V_53 . V_162 = F_3 ( V_29 -> V_163 ) ;
V_53 . V_164 = F_3 ( V_29 -> V_165 ) ;
}
F_4 ( V_10 , V_79 , V_10 -> V_3 , sizeof( V_53 ) , & V_53 ) ;
F_44 ( V_10 ) ;
}
void F_89 ( struct V_28 * V_29 , T_1 V_34 )
{
struct V_9 * V_10 ;
struct V_96 * V_166 = & V_29 -> V_166 ;
struct V_89 * V_53 ;
T_3 V_4 ;
V_10 = F_9 ( V_88 ) ;
if ( ! V_10 )
return;
F_19 ( L_25 , V_29 -> V_73 , V_10 ) ;
V_4 = sizeof( struct V_89 ) + V_166 -> V_4 ;
V_53 = F_2 ( V_4 , V_8 ) ;
if ( ! V_53 ) {
F_44 ( V_10 ) ;
return;
}
V_53 -> V_31 = V_29 -> V_31 ;
if ( V_34 ) {
V_53 -> V_34 = V_78 ;
} else {
V_53 -> V_34 = V_107 ;
memcpy ( V_53 -> V_96 , V_166 -> V_5 , V_166 -> V_4 ) ;
}
F_4 ( V_10 , V_91 , V_10 -> V_3 , V_4 , V_53 ) ;
F_44 ( V_10 ) ;
F_7 ( V_53 ) ;
}
void F_90 ( struct V_28 * V_29 , T_1 V_34 )
{
struct V_9 * V_10 ;
struct V_96 * V_166 = & V_29 -> V_166 ;
struct V_101 * V_51 ;
struct V_11 * V_99 ;
T_3 V_4 ;
V_10 = F_9 ( V_167 ) ;
if ( ! V_10 )
return;
V_4 = sizeof( * V_51 ) + V_166 -> V_4 ;
F_19 ( L_26 , V_29 -> V_73 , V_10 , V_4 ) ;
V_51 = F_2 ( V_4 , V_8 ) ;
if ( ! V_51 ) {
F_44 ( V_10 ) ;
return;
}
V_99 = V_10 -> V_99 ;
if ( ! V_99 )
goto V_113;
V_51 -> V_103 = V_29 -> V_31 ;
V_51 -> V_104 = V_99 -> V_100 ;
memcpy ( V_51 -> V_96 , V_166 -> V_5 , V_166 -> V_4 ) ;
F_4 ( V_10 , V_118 , F_8 ( V_10 ) , V_4 , V_51 ) ;
V_113:
F_44 ( V_10 ) ;
F_7 ( V_51 ) ;
}
void F_91 ( struct V_28 * V_29 , T_1 V_34 )
{
struct V_9 * V_10 ;
struct V_102 V_53 ;
struct V_92 * V_168 ;
V_10 = F_9 ( V_109 ) ;
if ( ! V_10 )
return;
V_168 = F_92 ( V_29 , V_110 , V_71 ) ;
if ( ! V_168 ) {
V_53 . V_34 = V_106 ;
} else {
V_53 . V_104 = V_168 -> V_104 ;
V_53 . V_34 = V_107 ;
}
F_19 ( L_27 , V_29 -> V_73 , V_10 , V_168 ,
V_34 ) ;
V_53 . V_103 = V_29 -> V_31 ;
F_4 ( V_10 , V_108 , V_10 -> V_3 , sizeof( V_53 ) , & V_53 ) ;
F_44 ( V_10 ) ;
}
void F_93 ( struct V_11 * V_12 )
{
struct V_66 * V_67 = V_12 -> V_67 ;
struct V_9 * V_10 = V_67 -> V_93 -> V_9 ;
struct V_50 V_51 ;
F_19 ( L_28 , V_12 , V_67 , V_10 ) ;
if ( ! V_10 ) {
V_10 = F_82 ( V_67 , true ) ;
if ( ! V_10 )
return;
}
V_10 -> V_99 = V_12 ;
V_51 . V_56 = F_3 ( V_61 ) ;
V_51 . V_54 = 0 ;
F_4 ( V_10 , V_116 , 1 , sizeof( V_51 ) , & V_51 ) ;
}
