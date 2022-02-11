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
F_5 ( & V_18 . V_21 , V_22 | V_23 , & V_16 , 1 , V_14 ) ;
F_6 ( V_12 , & V_18 , V_14 ) ;
F_7 ( V_6 ) ;
}
T_1 F_8 ( struct V_9 * V_10 )
{
if ( ++ V_10 -> V_3 == 0 )
V_10 -> V_3 = 1 ;
return V_10 -> V_3 ;
}
static void F_9 ( struct V_9 * V_10 , struct V_24 * V_25 )
{
struct V_26 * V_27 ;
int V_28 = 1 ;
V_25 [ 0 ] . V_29 = V_30 ;
V_25 [ 0 ] . type = V_31 ;
V_25 [ 0 ] . V_32 = V_33 ;
F_10 (hdev, &hci_dev_list, list) {
if ( V_27 -> V_34 == V_35 ) {
V_25 [ V_28 ] . V_29 = V_27 -> V_29 ;
V_25 [ V_28 ] . type = V_27 -> V_36 ;
if ( F_11 ( V_37 , & V_27 -> V_38 ) )
V_25 [ V_28 ] . V_32 = V_27 -> V_39 ;
else
V_25 [ V_28 ] . V_32 = V_40 ;
V_28 ++ ;
}
}
}
static int F_12 ( struct V_9 * V_10 , struct V_41 * V_42 ,
struct V_1 * V_43 )
{
struct V_44 * V_45 = ( void * ) V_42 -> V_5 ;
if ( F_13 ( V_43 -> V_4 ) < sizeof( * V_45 ) )
return - V_46 ;
F_14 ( L_1 , V_43 -> V_3 , F_13 ( V_45 -> V_47 ) ) ;
F_15 ( V_42 , sizeof( * V_45 ) ) ;
return 0 ;
}
static int F_16 ( struct V_9 * V_10 , struct V_41 * V_42 ,
struct V_1 * V_43 )
{
struct V_48 * V_49 = ( void * ) V_42 -> V_5 ;
T_2 V_4 = F_13 ( V_43 -> V_4 ) ;
struct V_50 * V_51 ;
T_2 V_52 ;
T_1 V_53 ;
struct V_26 * V_27 ;
if ( V_4 < sizeof( * V_49 ) )
return - V_46 ;
F_15 ( V_42 , sizeof( * V_49 ) ) ;
V_52 = F_13 ( V_49 -> V_52 ) ;
F_14 ( L_2 , F_13 ( V_49 -> V_54 ) , V_52 ) ;
while ( V_52 & V_55 ) {
if ( V_4 < sizeof( V_52 ) )
return - V_46 ;
V_52 = F_17 ( V_42 -> V_5 ) ;
F_14 ( L_3 , V_52 ) ;
V_4 -= sizeof( V_52 ) ;
F_15 ( V_42 , sizeof( V_52 ) ) ;
}
F_18 ( & V_56 ) ;
V_53 = 1 ;
F_10 (hdev, &hci_dev_list, list) {
if ( V_27 -> V_34 == V_35 )
V_53 ++ ;
}
V_4 = V_53 * sizeof( struct V_24 ) + sizeof( * V_51 ) ;
V_51 = F_19 ( V_4 , V_57 ) ;
if ( ! V_51 ) {
F_20 ( & V_56 ) ;
return - V_58 ;
}
V_51 -> V_54 = F_3 ( V_59 ) ;
V_51 -> V_52 = 0 ;
F_9 ( V_10 , V_51 -> V_25 ) ;
F_20 ( & V_56 ) ;
F_4 ( V_10 , V_60 , V_43 -> V_3 , V_4 , V_51 ) ;
F_7 ( V_51 ) ;
return 0 ;
}
static int F_21 ( struct V_9 * V_10 , struct V_41 * V_42 ,
struct V_1 * V_43 )
{
struct V_50 * V_51 = ( void * ) V_42 -> V_5 ;
T_2 V_4 = F_13 ( V_43 -> V_4 ) ;
struct V_24 * V_25 ;
T_2 V_52 ;
bool V_61 = false ;
if ( V_4 < sizeof( * V_51 ) )
return - V_46 ;
V_4 -= sizeof( * V_51 ) ;
F_15 ( V_42 , sizeof( * V_51 ) ) ;
V_52 = F_13 ( V_51 -> V_52 ) ;
F_14 ( L_2 , F_13 ( V_51 -> V_54 ) , V_52 ) ;
while ( V_52 & V_55 ) {
if ( V_4 < sizeof( V_52 ) )
return - V_46 ;
V_52 = F_17 ( V_42 -> V_5 ) ;
F_14 ( L_3 , V_52 ) ;
V_4 -= sizeof( V_52 ) ;
F_15 ( V_42 , sizeof( V_52 ) ) ;
}
V_25 = ( void * ) V_42 -> V_5 ;
while ( V_4 >= sizeof( * V_25 ) ) {
F_14 ( L_4 , V_25 -> V_29 , V_25 -> type ,
V_25 -> V_32 ) ;
if ( V_25 -> V_29 != V_30 && V_25 -> type != V_31 ) {
struct V_62 V_49 ;
V_61 = true ;
V_49 . V_29 = V_25 -> V_29 ;
F_4 ( V_10 , V_63 , F_8 ( V_10 ) ,
sizeof( V_49 ) , & V_49 ) ;
}
V_4 -= sizeof( * V_25 ) ;
V_25 = ( void * ) F_15 ( V_42 , sizeof( * V_25 ) ) ;
}
if ( ! V_61 ) {
struct V_64 * V_65 = V_10 -> V_64 ;
struct V_11 * V_12 ;
F_22 ( & V_65 -> V_66 ) ;
F_10 (chan, &conn->chan_l, list) {
F_14 ( L_5 , V_12 ,
F_23 ( V_12 -> V_67 ) ) ;
if ( V_12 -> V_68 == V_69 )
continue;
F_24 ( V_12 ) ;
if ( V_12 -> V_67 == V_70 )
F_25 ( V_12 ) ;
F_26 ( V_12 ) ;
}
F_27 ( & V_65 -> V_66 ) ;
}
return 0 ;
}
static int F_28 ( struct V_9 * V_10 , struct V_41 * V_42 ,
struct V_1 * V_43 )
{
struct V_24 * V_25 = ( void * ) V_42 -> V_5 ;
while ( V_42 -> V_4 >= sizeof( * V_25 ) ) {
F_14 ( L_6 , V_25 -> V_29 , V_25 -> type ,
V_25 -> V_32 ) ;
V_25 = (struct V_24 * ) F_15 ( V_42 , sizeof( * V_25 ) ) ;
}
return 0 ;
}
static int F_29 ( struct V_9 * V_10 , struct V_41 * V_42 ,
struct V_1 * V_43 )
{
struct V_62 * V_49 = ( void * ) V_42 -> V_5 ;
struct V_26 * V_27 ;
if ( F_13 ( V_43 -> V_4 ) < sizeof( * V_49 ) )
return - V_46 ;
F_14 ( L_7 , V_49 -> V_29 ) ;
V_27 = F_30 ( V_49 -> V_29 ) ;
if ( ! V_27 || V_27 -> V_34 != V_35 ) {
struct V_71 V_51 ;
V_51 . V_29 = V_49 -> V_29 ;
V_51 . V_32 = V_72 ;
F_4 ( V_10 , V_73 , V_43 -> V_3 , sizeof( V_51 ) ,
& V_51 ) ;
goto V_74;
}
F_31 ( V_75 , & V_10 -> V_67 ) ;
F_32 ( V_27 , V_76 , 0 , NULL ) ;
V_74:
if ( V_27 )
F_33 ( V_27 ) ;
F_15 ( V_42 , sizeof( * V_49 ) ) ;
return 0 ;
}
static int F_34 ( struct V_9 * V_10 , struct V_41 * V_42 ,
struct V_1 * V_43 )
{
struct V_71 * V_51 = (struct V_71 * ) V_42 -> V_5 ;
struct V_77 V_49 ;
struct V_78 * V_79 ;
if ( F_13 ( V_43 -> V_4 ) < sizeof( * V_51 ) )
return - V_46 ;
F_14 ( L_8 , V_51 -> V_29 , V_51 -> V_32 ) ;
if ( V_51 -> V_32 )
return - V_46 ;
V_79 = F_35 ( V_10 , V_51 -> V_29 ) ;
if ( ! V_79 )
return - V_58 ;
V_49 . V_29 = V_51 -> V_29 ;
F_4 ( V_10 , V_80 , F_8 ( V_10 ) , sizeof( V_49 ) ,
& V_49 ) ;
F_15 ( V_42 , sizeof( * V_51 ) ) ;
return 0 ;
}
static int F_36 ( struct V_9 * V_10 , struct V_41 * V_42 ,
struct V_1 * V_43 )
{
struct V_77 * V_49 = ( void * ) V_42 -> V_5 ;
struct V_26 * V_27 ;
struct V_9 * V_81 ;
if ( F_13 ( V_43 -> V_4 ) < sizeof( * V_49 ) )
return - V_46 ;
F_14 ( L_7 , V_49 -> V_29 ) ;
V_81 = F_37 ( V_82 ) ;
V_27 = F_30 ( V_49 -> V_29 ) ;
if ( ! V_27 || V_27 -> V_36 == V_31 || V_81 ) {
struct V_83 V_51 ;
V_51 . V_29 = V_49 -> V_29 ;
if ( V_81 ) {
V_51 . V_32 = V_84 ;
F_38 ( V_81 ) ;
} else {
V_51 . V_32 = V_72 ;
}
F_4 ( V_10 , V_85 , V_43 -> V_3 , sizeof( V_51 ) ,
& V_51 ) ;
goto V_74;
}
F_39 ( V_27 , V_10 ) ;
V_74:
if ( V_27 )
F_33 ( V_27 ) ;
F_15 ( V_42 , sizeof( * V_49 ) ) ;
return 0 ;
}
static int F_40 ( struct V_9 * V_10 , struct V_41 * V_42 ,
struct V_1 * V_43 )
{
struct V_83 * V_51 = ( void * ) V_42 -> V_5 ;
T_2 V_4 = F_13 ( V_43 -> V_4 ) ;
struct V_26 * V_27 ;
struct V_78 * V_79 ;
struct V_86 * V_87 ;
T_3 V_88 ;
if ( V_4 < sizeof( * V_51 ) )
return - V_46 ;
V_88 = V_4 - sizeof( * V_51 ) ;
F_14 ( L_9 , V_51 -> V_29 , V_51 -> V_32 ,
V_88 ) ;
if ( V_51 -> V_32 )
return - V_46 ;
V_79 = F_41 ( V_10 , V_51 -> V_29 ) ;
if ( V_79 ) {
T_1 * V_89 ;
V_89 = F_42 ( V_51 -> V_90 , V_88 , V_8 ) ;
if ( ! V_89 ) {
F_43 ( V_79 ) ;
return - V_58 ;
}
V_79 -> V_89 = V_89 ;
V_79 -> V_88 = V_88 ;
V_79 -> V_91 = V_88 ;
V_79 -> V_92 = 0 ;
F_43 ( V_79 ) ;
}
V_27 = F_30 ( V_51 -> V_29 ) ;
if ( ! V_27 )
return - V_46 ;
V_87 = F_44 ( V_27 , V_10 , V_51 -> V_29 , true ) ;
if ( ! V_87 )
goto V_74;
F_14 ( L_10 , V_87 , V_27 -> V_29 , V_51 -> V_29 ) ;
V_10 -> V_93 -> V_94 = V_51 -> V_29 ;
F_45 ( V_27 , V_10 , V_87 ) ;
V_74:
F_33 ( V_27 ) ;
F_15 ( V_42 , V_4 ) ;
return 0 ;
}
static int F_46 ( struct V_9 * V_10 , struct V_41 * V_42 ,
struct V_1 * V_43 )
{
struct V_95 * V_49 = ( void * ) V_42 -> V_5 ;
struct V_96 V_51 ;
struct V_26 * V_27 ;
struct V_86 * V_87 ;
struct V_78 * V_79 ;
if ( F_13 ( V_43 -> V_4 ) < sizeof( * V_49 ) )
return - V_46 ;
F_14 ( L_11 , V_49 -> V_97 , V_49 -> V_98 ) ;
V_51 . V_97 = V_49 -> V_98 ;
V_51 . V_98 = V_49 -> V_97 ;
V_27 = F_30 ( V_49 -> V_98 ) ;
if ( ! V_27 || V_27 -> V_36 == V_31 ) {
V_51 . V_32 = V_72 ;
goto V_99;
}
V_79 = F_41 ( V_10 , V_51 . V_98 ) ;
if ( ! V_79 ) {
V_79 = F_35 ( V_10 , V_51 . V_98 ) ;
if ( V_79 ) {
F_47 ( V_79 ) ;
} else {
V_51 . V_32 = V_100 ;
goto V_99;
}
}
if ( V_79 ) {
T_3 V_88 = F_13 ( V_43 -> V_4 ) - sizeof( * V_49 ) ;
T_1 * V_89 ;
V_89 = F_42 ( V_49 -> V_90 , V_88 , V_8 ) ;
if ( ! V_89 ) {
F_43 ( V_79 ) ;
return - V_58 ;
}
V_79 -> V_89 = V_89 ;
V_79 -> V_88 = V_88 ;
V_79 -> V_91 = V_88 ;
V_79 -> V_92 = 0 ;
F_43 ( V_79 ) ;
}
V_87 = F_44 ( V_27 , V_10 , V_49 -> V_97 , false ) ;
if ( V_87 ) {
F_48 ( V_27 , V_10 , V_87 ) ;
V_51 . V_32 = V_101 ;
} else {
V_51 . V_32 = V_100 ;
}
V_99:
if ( V_27 )
F_33 ( V_27 ) ;
if ( V_51 . V_32 != V_101 ) {
F_4 ( V_10 , V_102 , V_43 -> V_3 ,
sizeof( V_51 ) , & V_51 ) ;
} else {
F_31 ( V_103 , & V_10 -> V_67 ) ;
V_10 -> V_3 = V_43 -> V_3 ;
}
F_15 ( V_42 , F_13 ( V_43 -> V_4 ) ) ;
return 0 ;
}
static int F_49 ( struct V_9 * V_10 , struct V_41 * V_42 ,
struct V_1 * V_43 )
{
struct V_95 * V_49 = ( void * ) V_42 -> V_5 ;
struct V_96 V_51 ;
struct V_26 * V_27 ;
struct V_86 * V_87 ;
if ( F_13 ( V_43 -> V_4 ) < sizeof( * V_49 ) )
return - V_46 ;
F_14 ( L_12 , V_49 -> V_97 , V_49 -> V_98 ) ;
V_51 . V_97 = V_49 -> V_98 ;
V_51 . V_98 = V_49 -> V_97 ;
V_51 . V_32 = V_101 ;
V_27 = F_30 ( V_49 -> V_98 ) ;
if ( ! V_27 ) {
V_51 . V_32 = V_72 ;
goto V_99;
}
V_87 = F_50 ( V_27 , V_104 ,
& V_10 -> V_64 -> V_87 -> V_105 ) ;
if ( ! V_87 ) {
F_51 ( L_13 ) ;
V_51 . V_32 = V_106 ;
goto V_107;
}
V_107:
F_33 ( V_27 ) ;
V_99:
F_4 ( V_10 , V_108 , V_43 -> V_3 , sizeof( V_51 ) , & V_51 ) ;
F_15 ( V_42 , sizeof( * V_49 ) ) ;
return 0 ;
}
static inline int F_52 ( struct V_9 * V_10 , struct V_41 * V_42 ,
struct V_1 * V_43 )
{
F_14 ( L_14 , V_43 -> V_3 , V_43 -> V_2 ) ;
F_15 ( V_42 , F_13 ( V_43 -> V_4 ) ) ;
return 0 ;
}
static int F_53 ( struct V_11 * V_12 , struct V_41 * V_42 )
{
struct V_1 * V_43 ;
struct V_9 * V_10 = V_12 -> V_5 ;
int V_109 = 0 ;
F_54 ( V_10 ) ;
while ( V_42 -> V_4 >= sizeof( * V_43 ) ) {
T_2 V_4 ;
V_43 = ( void * ) V_42 -> V_5 ;
V_4 = F_13 ( V_43 -> V_4 ) ;
F_14 ( L_15 , V_43 -> V_2 , V_43 -> V_3 , V_4 ) ;
F_15 ( V_42 , sizeof( * V_43 ) ) ;
if ( V_4 > V_42 -> V_4 || ! V_43 -> V_3 ) {
V_109 = - V_46 ;
break;
}
V_10 -> V_3 = V_43 -> V_3 ;
switch ( V_43 -> V_2 ) {
case V_110 :
F_12 ( V_10 , V_42 , V_43 ) ;
break;
case V_111 :
V_109 = F_16 ( V_10 , V_42 , V_43 ) ;
break;
case V_112 :
V_109 = F_28 ( V_10 , V_42 , V_43 ) ;
break;
case V_63 :
V_109 = F_29 ( V_10 , V_42 , V_43 ) ;
break;
case V_80 :
V_109 = F_36 ( V_10 , V_42 , V_43 ) ;
break;
case V_113 :
V_109 = F_46 ( V_10 , V_42 , V_43 ) ;
break;
case V_114 :
V_109 = F_49 ( V_10 , V_42 , V_43 ) ;
break;
case V_60 :
V_109 = F_21 ( V_10 , V_42 , V_43 ) ;
break;
case V_73 :
V_109 = F_34 ( V_10 , V_42 , V_43 ) ;
break;
case V_85 :
V_109 = F_40 ( V_10 , V_42 , V_43 ) ;
break;
case V_115 :
case V_102 :
case V_108 :
V_109 = F_52 ( V_10 , V_42 , V_43 ) ;
break;
default:
F_51 ( L_16 , V_43 -> V_2 ) ;
V_109 = - V_46 ;
break;
}
}
if ( V_109 ) {
struct V_44 V_45 ;
V_45 . V_47 = F_3 ( 0 ) ;
V_43 = ( void * ) V_42 -> V_5 ;
F_14 ( L_17 , V_43 -> V_2 , V_109 ) ;
F_4 ( V_10 , V_110 , V_43 -> V_3 , sizeof( V_45 ) ,
& V_45 ) ;
}
F_55 ( V_42 ) ;
F_38 ( V_10 ) ;
return 0 ;
}
static void F_56 ( struct V_11 * V_12 )
{
F_57 ( V_12 ) ;
}
static void F_58 ( struct V_11 * V_12 , int V_67 ,
int V_109 )
{
struct V_9 * V_10 = V_12 -> V_5 ;
if ( ! V_10 )
return;
F_14 ( L_5 , V_12 , F_23 ( V_67 ) ) ;
V_12 -> V_67 = V_67 ;
switch ( V_67 ) {
case V_116 :
if ( V_10 )
F_38 ( V_10 ) ;
break;
}
}
static struct V_41 * F_59 ( struct V_11 * V_12 ,
unsigned long V_117 ,
unsigned long V_4 , int V_118 )
{
struct V_41 * V_42 ;
V_42 = F_60 ( V_117 + V_4 , V_8 ) ;
if ( ! V_42 )
return F_61 ( - V_58 ) ;
return V_42 ;
}
static struct V_11 * F_62 ( struct V_64 * V_65 , bool V_119 )
{
struct V_11 * V_12 ;
int V_109 ;
V_12 = F_63 () ;
if ( ! V_12 )
return NULL ;
F_14 ( L_18 , V_12 ) ;
V_12 -> V_120 = V_121 ;
V_12 -> V_68 = V_69 ;
V_12 -> V_122 = V_69 ;
V_12 -> V_123 = V_59 ;
V_12 -> V_124 = V_59 ;
V_12 -> V_125 = V_126 ;
V_12 -> V_127 = & V_128 ;
F_64 ( V_12 ) ;
V_12 -> V_129 = V_12 -> V_130 ;
V_12 -> V_131 = V_12 -> V_132 ;
V_12 -> V_133 = V_134 ;
V_12 -> V_135 = V_136 ;
F_65 ( & V_12 -> V_137 ) ;
V_12 -> V_138 = V_139 ;
V_109 = F_66 ( V_12 ) ;
if ( V_109 < 0 ) {
F_67 ( V_12 , 0 ) ;
return NULL ;
}
V_12 -> V_140 = 0 ;
if ( V_119 )
F_68 ( V_65 , V_12 ) ;
else
F_69 ( V_65 , V_12 ) ;
V_12 -> V_141 = V_12 -> V_123 ;
V_12 -> V_142 = V_12 -> V_123 ;
V_12 -> V_67 = V_143 ;
return V_12 ;
}
struct V_9 * F_54 ( struct V_9 * V_10 )
{
F_14 ( L_19 , V_10 , F_70 ( & V_10 -> V_144 . V_145 ) ) ;
F_71 ( & V_10 -> V_144 ) ;
return V_10 ;
}
static void F_72 ( struct V_144 * V_144 )
{
struct V_9 * V_10 = F_73 ( V_144 , struct V_9 , V_144 ) ;
F_14 ( L_20 , V_10 ) ;
F_22 ( & V_146 ) ;
F_74 ( & V_10 -> V_147 ) ;
F_27 ( & V_146 ) ;
F_75 ( V_10 ) ;
F_7 ( V_10 ) ;
}
int F_38 ( struct V_9 * V_10 )
{
F_14 ( L_19 , V_10 , F_70 ( & V_10 -> V_144 . V_145 ) ) ;
return F_76 ( & V_10 -> V_144 , & F_72 ) ;
}
static struct V_9 * F_77 ( struct V_64 * V_65 , bool V_119 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
V_10 = F_2 ( sizeof( * V_10 ) , V_8 ) ;
if ( ! V_10 )
return NULL ;
F_14 ( L_21 , V_65 , V_10 ) ;
V_10 -> V_64 = V_65 ;
V_12 = F_62 ( V_65 , V_119 ) ;
if ( ! V_12 ) {
F_7 ( V_10 ) ;
return NULL ;
}
V_10 -> V_13 = V_12 ;
V_12 -> V_5 = V_10 ;
V_65 -> V_87 -> V_9 = V_10 ;
F_78 ( & V_10 -> V_144 ) ;
F_79 ( & V_10 -> V_148 ) ;
F_80 ( & V_10 -> V_149 ) ;
F_22 ( & V_146 ) ;
F_81 ( & V_10 -> V_147 , & V_150 ) ;
F_27 ( & V_146 ) ;
return V_10 ;
}
struct V_11 * F_82 ( struct V_64 * V_65 ,
struct V_41 * V_42 )
{
struct V_9 * V_10 ;
if ( V_65 -> V_87 -> type != V_151 )
return NULL ;
V_10 = F_77 ( V_65 , false ) ;
if ( ! V_10 ) {
F_51 ( L_22 ) ;
return NULL ;
}
F_14 ( L_23 , V_10 , V_10 -> V_13 ) ;
return V_10 -> V_13 ;
}
struct V_9 * F_37 ( T_1 V_67 )
{
struct V_9 * V_10 ;
F_22 ( & V_146 ) ;
F_10 (mgr, &amp_mgr_list, list) {
if ( F_83 ( V_67 , & V_10 -> V_67 ) ) {
F_54 ( V_10 ) ;
F_27 ( & V_146 ) ;
return V_10 ;
}
}
F_27 ( & V_146 ) ;
return NULL ;
}
void F_84 ( struct V_26 * V_27 )
{
struct V_9 * V_10 ;
struct V_71 V_51 ;
V_10 = F_37 ( V_75 ) ;
if ( ! V_10 )
return;
F_14 ( L_24 , V_27 -> V_152 , V_10 ) ;
V_51 . V_29 = V_27 -> V_29 ;
V_51 . V_32 = V_72 ;
if ( V_27 -> V_36 != V_31 ) {
V_51 . V_32 = 0 ;
V_51 . V_153 = F_85 ( V_27 -> V_154 ) ;
V_51 . V_155 = F_85 ( V_27 -> V_156 ) ;
V_51 . V_157 = F_85 ( V_27 -> V_158 ) ;
V_51 . V_159 = F_3 ( V_27 -> V_160 ) ;
V_51 . V_161 = F_3 ( V_27 -> V_162 ) ;
}
F_4 ( V_10 , V_73 , V_10 -> V_3 , sizeof( V_51 ) , & V_51 ) ;
F_38 ( V_10 ) ;
}
void F_86 ( struct V_26 * V_27 , T_1 V_32 )
{
struct V_9 * V_10 ;
struct V_90 * V_163 = & V_27 -> V_163 ;
struct V_83 * V_51 ;
T_3 V_4 ;
V_10 = F_37 ( V_82 ) ;
if ( ! V_10 )
return;
F_14 ( L_24 , V_27 -> V_152 , V_10 ) ;
V_4 = sizeof( struct V_83 ) + V_163 -> V_4 ;
V_51 = F_2 ( V_4 , V_8 ) ;
if ( ! V_51 ) {
F_38 ( V_10 ) ;
return;
}
V_51 -> V_29 = V_27 -> V_29 ;
if ( V_32 ) {
V_51 -> V_32 = V_72 ;
} else {
V_51 -> V_32 = V_101 ;
memcpy ( V_51 -> V_90 , V_163 -> V_5 , V_163 -> V_4 ) ;
}
F_4 ( V_10 , V_85 , V_10 -> V_3 , V_4 , V_51 ) ;
F_38 ( V_10 ) ;
F_7 ( V_51 ) ;
}
void F_87 ( struct V_26 * V_27 , T_1 V_32 )
{
struct V_9 * V_10 ;
struct V_90 * V_163 = & V_27 -> V_163 ;
struct V_95 * V_49 ;
struct V_11 * V_93 ;
T_3 V_4 ;
V_10 = F_37 ( V_164 ) ;
if ( ! V_10 )
return;
V_4 = sizeof( * V_49 ) + V_163 -> V_4 ;
F_14 ( L_25 , V_27 -> V_152 , V_10 , V_4 ) ;
V_49 = F_2 ( V_4 , V_8 ) ;
if ( ! V_49 ) {
F_38 ( V_10 ) ;
return;
}
V_93 = V_10 -> V_93 ;
if ( ! V_93 )
goto V_107;
V_49 -> V_97 = V_27 -> V_29 ;
V_49 -> V_98 = V_93 -> V_94 ;
memcpy ( V_49 -> V_90 , V_163 -> V_5 , V_163 -> V_4 ) ;
F_4 ( V_10 , V_113 , F_8 ( V_10 ) , V_4 , V_49 ) ;
V_107:
F_38 ( V_10 ) ;
F_7 ( V_49 ) ;
}
void F_88 ( struct V_26 * V_27 , T_1 V_32 )
{
struct V_9 * V_10 ;
struct V_96 V_51 ;
struct V_86 * V_165 ;
V_10 = F_37 ( V_103 ) ;
if ( ! V_10 )
return;
V_165 = F_89 ( V_27 , V_104 , V_70 ) ;
if ( ! V_165 ) {
V_51 . V_32 = V_100 ;
} else {
V_51 . V_98 = V_165 -> V_98 ;
V_51 . V_32 = V_101 ;
}
F_14 ( L_26 , V_27 -> V_152 , V_10 , V_165 ,
V_32 ) ;
V_51 . V_97 = V_27 -> V_29 ;
F_4 ( V_10 , V_102 , V_10 -> V_3 , sizeof( V_51 ) , & V_51 ) ;
F_38 ( V_10 ) ;
}
void F_90 ( struct V_11 * V_12 )
{
struct V_64 * V_65 = V_12 -> V_65 ;
struct V_9 * V_10 = V_65 -> V_87 -> V_9 ;
struct V_48 V_49 ;
F_14 ( L_27 , V_12 , V_65 , V_10 ) ;
if ( ! V_10 ) {
V_10 = F_77 ( V_65 , true ) ;
if ( ! V_10 )
return;
}
V_10 -> V_93 = V_12 ;
V_49 . V_54 = F_3 ( V_59 ) ;
V_49 . V_52 = 0 ;
F_4 ( V_10 , V_111 , 1 , sizeof( V_49 ) , & V_49 ) ;
}
