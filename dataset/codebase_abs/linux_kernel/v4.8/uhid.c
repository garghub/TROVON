static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
int V_6 ;
V_6 = F_3 ( V_4 -> V_7 ) ;
if ( V_6 ) {
F_4 ( V_4 -> V_7 , L_1 , V_6 ) ;
F_5 ( V_4 -> V_7 ) ;
V_4 -> V_7 = NULL ;
V_4 -> V_8 = false ;
}
}
static void F_6 ( struct V_3 * V_4 , struct V_9 * V_10 )
{
T_1 V_11 ;
V_11 = ( V_4 -> V_12 + 1 ) % V_13 ;
if ( V_11 != V_4 -> V_14 ) {
V_4 -> V_15 [ V_4 -> V_12 ] = V_10 ;
V_4 -> V_12 = V_11 ;
F_7 ( & V_4 -> V_16 ) ;
} else {
F_8 ( V_4 -> V_7 , L_2 ) ;
F_9 ( V_10 ) ;
}
}
static int F_10 ( struct V_3 * V_4 , T_2 V_17 )
{
unsigned long V_18 ;
struct V_9 * V_10 ;
V_10 = F_11 ( sizeof( * V_10 ) , V_19 ) ;
if ( ! V_10 )
return - V_20 ;
V_10 -> type = V_17 ;
F_12 ( & V_4 -> V_21 , V_18 ) ;
F_6 ( V_4 , V_10 ) ;
F_13 ( & V_4 -> V_21 , V_18 ) ;
return 0 ;
}
static int F_14 ( struct V_22 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_23 ;
struct V_9 * V_10 ;
unsigned long V_18 ;
V_10 = F_11 ( sizeof( * V_10 ) , V_19 ) ;
if ( ! V_10 )
return - V_20 ;
V_10 -> type = V_24 ;
if ( V_7 -> V_25 [ V_26 ] . V_27 )
V_10 -> V_28 . V_29 . V_30 |= V_31 ;
if ( V_7 -> V_25 [ V_32 ] . V_27 )
V_10 -> V_28 . V_29 . V_30 |= V_33 ;
if ( V_7 -> V_25 [ V_34 ] . V_27 )
V_10 -> V_28 . V_29 . V_30 |= V_35 ;
F_12 ( & V_4 -> V_21 , V_18 ) ;
F_6 ( V_4 , V_10 ) ;
F_13 ( & V_4 -> V_21 , V_18 ) ;
return 0 ;
}
static void F_15 ( struct V_22 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_23 ;
V_7 -> V_36 = 0 ;
F_10 ( V_4 , V_37 ) ;
}
static int F_16 ( struct V_22 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_23 ;
return F_10 ( V_4 , V_38 ) ;
}
static void F_17 ( struct V_22 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_23 ;
F_10 ( V_4 , V_39 ) ;
}
static int F_18 ( struct V_22 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_23 ;
return F_19 ( V_7 , V_4 -> V_40 , V_4 -> V_41 ) ;
}
static int F_20 ( struct V_3 * V_4 ,
struct V_9 * V_10 ,
T_2 * V_42 )
{
unsigned long V_18 ;
int V_6 ;
F_12 ( & V_4 -> V_21 , V_18 ) ;
* V_42 = ++ V_4 -> V_42 ;
V_4 -> V_43 = V_10 -> type + 1 ;
V_4 -> V_44 = true ;
F_6 ( V_4 , V_10 ) ;
F_13 ( & V_4 -> V_21 , V_18 ) ;
V_6 = F_21 ( V_4 -> V_45 ,
! V_4 -> V_44 || ! V_4 -> V_8 ,
5 * V_46 ) ;
if ( ! V_6 || ! V_4 -> V_8 || V_4 -> V_44 )
V_6 = - V_47 ;
else if ( V_6 < 0 )
V_6 = - V_48 ;
else
V_6 = 0 ;
V_4 -> V_44 = false ;
return V_6 ;
}
static void F_22 ( struct V_3 * V_4 , T_3 V_49 ,
const struct V_9 * V_10 )
{
unsigned long V_18 ;
F_12 ( & V_4 -> V_21 , V_18 ) ;
if ( V_4 -> V_43 != V_10 -> type || V_4 -> V_42 != V_49 )
goto V_50;
if ( ! V_4 -> V_44 )
goto V_50;
memcpy ( & V_4 -> V_51 , V_10 , sizeof( * V_10 ) ) ;
V_4 -> V_44 = false ;
F_7 ( & V_4 -> V_45 ) ;
V_50:
F_13 ( & V_4 -> V_21 , V_18 ) ;
}
static int F_23 ( struct V_22 * V_7 , unsigned char V_52 ,
T_4 * V_53 , T_5 V_54 , T_4 V_55 )
{
struct V_3 * V_4 = V_7 -> V_23 ;
struct V_56 * V_57 ;
struct V_9 * V_10 ;
int V_6 ;
if ( ! V_4 -> V_8 )
return - V_47 ;
V_10 = F_11 ( sizeof( * V_10 ) , V_19 ) ;
if ( ! V_10 )
return - V_20 ;
V_10 -> type = V_58 ;
V_10 -> V_28 . V_59 . V_52 = V_52 ;
V_10 -> V_28 . V_59 . V_55 = V_55 ;
V_6 = F_24 ( & V_4 -> V_60 ) ;
if ( V_6 ) {
F_9 ( V_10 ) ;
return V_6 ;
}
V_6 = F_20 ( V_4 , V_10 , & V_10 -> V_28 . V_59 . V_49 ) ;
if ( V_6 )
goto V_50;
V_57 = & V_4 -> V_51 . V_28 . V_61 ;
if ( V_57 -> V_62 ) {
V_6 = - V_47 ;
} else {
V_6 = F_25 ( V_54 , ( T_5 ) V_57 -> V_63 , ( T_5 ) V_64 ) ;
memcpy ( V_53 , V_57 -> V_65 , V_6 ) ;
}
V_50:
F_26 ( & V_4 -> V_60 ) ;
return V_6 ;
}
static int F_27 ( struct V_22 * V_7 , unsigned char V_52 ,
const T_4 * V_53 , T_5 V_54 , T_4 V_55 )
{
struct V_3 * V_4 = V_7 -> V_23 ;
struct V_9 * V_10 ;
int V_6 ;
if ( ! V_4 -> V_8 || V_54 > V_64 )
return - V_47 ;
V_10 = F_11 ( sizeof( * V_10 ) , V_19 ) ;
if ( ! V_10 )
return - V_20 ;
V_10 -> type = V_66 ;
V_10 -> V_28 . V_67 . V_52 = V_52 ;
V_10 -> V_28 . V_67 . V_55 = V_55 ;
V_10 -> V_28 . V_67 . V_63 = V_54 ;
memcpy ( V_10 -> V_28 . V_67 . V_65 , V_53 , V_54 ) ;
V_6 = F_24 ( & V_4 -> V_60 ) ;
if ( V_6 ) {
F_9 ( V_10 ) ;
return V_6 ;
}
V_6 = F_20 ( V_4 , V_10 , & V_10 -> V_28 . V_67 . V_49 ) ;
if ( V_6 )
goto V_50;
if ( V_4 -> V_51 . V_28 . V_68 . V_62 )
V_6 = - V_47 ;
else
V_6 = V_54 ;
V_50:
F_26 ( & V_4 -> V_60 ) ;
return V_6 ;
}
static int F_28 ( struct V_22 * V_7 , unsigned char V_69 ,
T_1 * V_53 , T_5 V_70 , unsigned char V_55 ,
int V_71 )
{
T_4 V_72 ;
switch ( V_55 ) {
case V_26 :
V_72 = V_73 ;
break;
case V_32 :
V_72 = V_74 ;
break;
case V_34 :
V_72 = V_75 ;
break;
default:
return - V_76 ;
}
switch ( V_71 ) {
case V_77 :
return F_23 ( V_7 , V_69 , V_53 , V_70 , V_72 ) ;
case V_78 :
return F_27 ( V_7 , V_69 , V_53 , V_70 , V_72 ) ;
default:
return - V_47 ;
}
}
static int F_29 ( struct V_22 * V_7 , T_1 * V_53 , T_5 V_54 ,
unsigned char V_43 )
{
struct V_3 * V_4 = V_7 -> V_23 ;
T_1 V_55 ;
unsigned long V_18 ;
struct V_9 * V_10 ;
switch ( V_43 ) {
case V_26 :
V_55 = V_73 ;
break;
case V_32 :
V_55 = V_74 ;
break;
default:
return - V_76 ;
}
if ( V_54 < 1 || V_54 > V_64 )
return - V_76 ;
V_10 = F_11 ( sizeof( * V_10 ) , V_19 ) ;
if ( ! V_10 )
return - V_20 ;
V_10 -> type = V_79 ;
V_10 -> V_28 . V_80 . V_63 = V_54 ;
V_10 -> V_28 . V_80 . V_55 = V_55 ;
memcpy ( V_10 -> V_28 . V_80 . V_65 , V_53 , V_54 ) ;
F_12 ( & V_4 -> V_21 , V_18 ) ;
F_6 ( V_4 , V_10 ) ;
F_13 ( & V_4 -> V_21 , V_18 ) ;
return V_54 ;
}
static int F_30 ( struct V_22 * V_7 , T_1 * V_53 ,
T_5 V_54 )
{
return F_29 ( V_7 , V_53 , V_54 , V_32 ) ;
}
static int F_31 ( const char T_6 * V_81 , T_5 V_70 ,
struct V_9 * V_17 )
{
if ( F_32 () ) {
T_3 type ;
if ( F_33 ( type , V_81 ) )
return - V_82 ;
if ( type == V_83 ) {
struct V_84 * V_85 ;
V_85 = F_11 ( sizeof( * V_85 ) , V_19 ) ;
if ( ! V_85 )
return - V_20 ;
V_81 += sizeof( type ) ;
V_70 -= sizeof( type ) ;
if ( F_34 ( V_85 , V_81 ,
F_35 ( V_70 , sizeof( * V_85 ) ) ) ) {
F_9 ( V_85 ) ;
return - V_82 ;
}
V_17 -> type = type ;
memcpy ( V_17 -> V_28 . V_86 . V_87 , V_85 -> V_87 ,
sizeof( V_85 -> V_87 ) ) ;
memcpy ( V_17 -> V_28 . V_86 . V_88 , V_85 -> V_88 ,
sizeof( V_85 -> V_88 ) ) ;
memcpy ( V_17 -> V_28 . V_86 . V_89 , V_85 -> V_89 ,
sizeof( V_85 -> V_89 ) ) ;
V_17 -> V_28 . V_86 . V_40 = F_36 ( V_85 -> V_40 ) ;
V_17 -> V_28 . V_86 . V_41 = V_85 -> V_41 ;
V_17 -> V_28 . V_86 . V_90 = V_85 -> V_90 ;
V_17 -> V_28 . V_86 . V_91 = V_85 -> V_91 ;
V_17 -> V_28 . V_86 . V_92 = V_85 -> V_92 ;
V_17 -> V_28 . V_86 . V_93 = V_85 -> V_93 ;
V_17 -> V_28 . V_86 . V_94 = V_85 -> V_94 ;
F_9 ( V_85 ) ;
return 0 ;
}
}
if ( F_34 ( V_17 , V_81 , F_35 ( V_70 , sizeof( * V_17 ) ) ) )
return - V_82 ;
return 0 ;
}
static int F_31 ( const char T_6 * V_81 , T_5 V_70 ,
struct V_9 * V_17 )
{
if ( F_34 ( V_17 , V_81 , F_35 ( V_70 , sizeof( * V_17 ) ) ) )
return - V_82 ;
return 0 ;
}
static int F_37 ( struct V_3 * V_4 ,
const struct V_9 * V_10 )
{
struct V_22 * V_7 ;
T_5 V_41 , V_70 ;
void * V_40 ;
int V_6 ;
if ( V_4 -> V_8 )
return - V_95 ;
V_41 = V_10 -> V_28 . V_96 . V_41 ;
if ( V_41 <= 0 || V_41 > V_97 )
return - V_76 ;
V_40 = F_38 ( V_10 -> V_28 . V_96 . V_40 , V_41 , V_19 ) ;
if ( ! V_40 )
return - V_20 ;
V_4 -> V_41 = V_41 ;
V_4 -> V_40 = V_40 ;
V_7 = F_39 () ;
if ( F_40 ( V_7 ) ) {
V_6 = F_41 ( V_7 ) ;
goto V_98;
}
V_70 = F_35 ( sizeof( V_7 -> V_87 ) , sizeof( V_10 -> V_28 . V_96 . V_87 ) ) - 1 ;
strncpy ( V_7 -> V_87 , V_10 -> V_28 . V_96 . V_87 , V_70 ) ;
V_70 = F_35 ( sizeof( V_7 -> V_88 ) , sizeof( V_10 -> V_28 . V_96 . V_88 ) ) - 1 ;
strncpy ( V_7 -> V_88 , V_10 -> V_28 . V_96 . V_88 , V_70 ) ;
V_70 = F_35 ( sizeof( V_7 -> V_89 ) , sizeof( V_10 -> V_28 . V_96 . V_89 ) ) - 1 ;
strncpy ( V_7 -> V_89 , V_10 -> V_28 . V_96 . V_89 , V_70 ) ;
V_7 -> V_99 = & V_100 ;
V_7 -> V_90 = V_10 -> V_28 . V_96 . V_90 ;
V_7 -> V_91 = V_10 -> V_28 . V_96 . V_91 ;
V_7 -> V_92 = V_10 -> V_28 . V_96 . V_92 ;
V_7 -> V_93 = V_10 -> V_28 . V_96 . V_93 ;
V_7 -> V_94 = V_10 -> V_28 . V_96 . V_94 ;
V_7 -> V_23 = V_4 ;
V_7 -> V_101 . V_102 = V_103 . V_104 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_8 = true ;
F_42 ( & V_4 -> V_5 ) ;
return 0 ;
V_98:
F_9 ( V_4 -> V_40 ) ;
V_4 -> V_40 = NULL ;
V_4 -> V_41 = 0 ;
return V_6 ;
}
static int F_43 ( struct V_3 * V_4 ,
struct V_9 * V_10 )
{
struct V_105 V_106 ;
V_106 = V_10 -> V_28 . V_86 ;
if ( V_106 . V_41 <= 0 || V_106 . V_41 > V_97 )
return - V_76 ;
if ( F_34 ( & V_10 -> V_28 . V_96 . V_40 , V_106 . V_40 , V_106 . V_41 ) )
return - V_82 ;
memcpy ( V_10 -> V_28 . V_96 . V_87 , V_106 . V_87 , sizeof( V_106 . V_87 ) ) ;
memcpy ( V_10 -> V_28 . V_96 . V_88 , V_106 . V_88 , sizeof( V_106 . V_88 ) ) ;
memcpy ( V_10 -> V_28 . V_96 . V_89 , V_106 . V_89 , sizeof( V_106 . V_89 ) ) ;
V_10 -> V_28 . V_96 . V_41 = V_106 . V_41 ;
V_10 -> V_28 . V_96 . V_90 = V_106 . V_90 ;
V_10 -> V_28 . V_96 . V_91 = V_106 . V_91 ;
V_10 -> V_28 . V_96 . V_92 = V_106 . V_92 ;
V_10 -> V_28 . V_96 . V_93 = V_106 . V_93 ;
V_10 -> V_28 . V_96 . V_94 = V_106 . V_94 ;
return F_37 ( V_4 , V_10 ) ;
}
static int F_44 ( struct V_3 * V_4 )
{
if ( ! V_4 -> V_8 )
return - V_76 ;
V_4 -> V_8 = false ;
F_7 ( & V_4 -> V_45 ) ;
F_45 ( & V_4 -> V_5 ) ;
F_5 ( V_4 -> V_7 ) ;
F_9 ( V_4 -> V_40 ) ;
return 0 ;
}
static int F_46 ( struct V_3 * V_4 , struct V_9 * V_10 )
{
if ( ! V_4 -> V_8 )
return - V_76 ;
F_47 ( V_4 -> V_7 , V_34 , V_10 -> V_28 . V_107 . V_65 ,
F_48 ( T_5 , V_10 -> V_28 . V_107 . V_63 , V_64 ) , 0 ) ;
return 0 ;
}
static int F_49 ( struct V_3 * V_4 , struct V_9 * V_10 )
{
if ( ! V_4 -> V_8 )
return - V_76 ;
F_47 ( V_4 -> V_7 , V_34 , V_10 -> V_28 . V_108 . V_65 ,
F_48 ( T_5 , V_10 -> V_28 . V_108 . V_63 , V_64 ) , 0 ) ;
return 0 ;
}
static int F_50 ( struct V_3 * V_4 ,
struct V_9 * V_10 )
{
if ( ! V_4 -> V_8 )
return - V_76 ;
F_22 ( V_4 , V_10 -> V_28 . V_61 . V_49 , V_10 ) ;
return 0 ;
}
static int F_51 ( struct V_3 * V_4 ,
struct V_9 * V_10 )
{
if ( ! V_4 -> V_8 )
return - V_76 ;
F_22 ( V_4 , V_10 -> V_28 . V_68 . V_49 , V_10 ) ;
return 0 ;
}
static int F_52 ( struct V_109 * V_109 , struct V_110 * V_110 )
{
struct V_3 * V_4 ;
V_4 = F_11 ( sizeof( * V_4 ) , V_19 ) ;
if ( ! V_4 )
return - V_20 ;
F_53 ( & V_4 -> V_111 ) ;
F_53 ( & V_4 -> V_60 ) ;
F_54 ( & V_4 -> V_21 ) ;
F_55 ( & V_4 -> V_16 ) ;
F_55 ( & V_4 -> V_45 ) ;
V_4 -> V_8 = false ;
F_56 ( & V_4 -> V_5 , F_1 ) ;
V_110 -> V_112 = V_4 ;
F_57 ( V_109 , V_110 ) ;
return 0 ;
}
static int F_58 ( struct V_109 * V_109 , struct V_110 * V_110 )
{
struct V_3 * V_4 = V_110 -> V_112 ;
unsigned int V_113 ;
F_44 ( V_4 ) ;
for ( V_113 = 0 ; V_113 < V_13 ; ++ V_113 )
F_9 ( V_4 -> V_15 [ V_113 ] ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static T_7 F_59 ( struct V_110 * V_110 , char T_6 * V_81 ,
T_5 V_54 , T_8 * V_114 )
{
struct V_3 * V_4 = V_110 -> V_112 ;
int V_6 ;
unsigned long V_18 ;
T_5 V_70 ;
if ( V_54 < sizeof( T_2 ) )
return - V_76 ;
V_115:
if ( V_110 -> V_116 & V_117 ) {
if ( V_4 -> V_12 == V_4 -> V_14 )
return - V_118 ;
} else {
V_6 = F_60 ( V_4 -> V_16 ,
V_4 -> V_12 != V_4 -> V_14 ) ;
if ( V_6 )
return V_6 ;
}
V_6 = F_24 ( & V_4 -> V_111 ) ;
if ( V_6 )
return V_6 ;
if ( V_4 -> V_12 == V_4 -> V_14 ) {
F_26 ( & V_4 -> V_111 ) ;
goto V_115;
} else {
V_70 = F_35 ( V_54 , sizeof( * * V_4 -> V_15 ) ) ;
if ( F_61 ( V_81 , V_4 -> V_15 [ V_4 -> V_14 ] , V_70 ) ) {
V_6 = - V_82 ;
} else {
F_9 ( V_4 -> V_15 [ V_4 -> V_14 ] ) ;
V_4 -> V_15 [ V_4 -> V_14 ] = NULL ;
F_12 ( & V_4 -> V_21 , V_18 ) ;
V_4 -> V_14 = ( V_4 -> V_14 + 1 ) % V_13 ;
F_13 ( & V_4 -> V_21 , V_18 ) ;
}
}
F_26 ( & V_4 -> V_111 ) ;
return V_6 ? V_6 : V_70 ;
}
static T_7 F_62 ( struct V_110 * V_110 , const char T_6 * V_81 ,
T_5 V_54 , T_8 * V_114 )
{
struct V_3 * V_4 = V_110 -> V_112 ;
int V_6 ;
T_5 V_70 ;
if ( V_54 < sizeof( T_2 ) )
return - V_76 ;
V_6 = F_24 ( & V_4 -> V_111 ) ;
if ( V_6 )
return V_6 ;
memset ( & V_4 -> V_119 , 0 , sizeof( V_4 -> V_119 ) ) ;
V_70 = F_35 ( V_54 , sizeof( V_4 -> V_119 ) ) ;
V_6 = F_31 ( V_81 , V_70 , & V_4 -> V_119 ) ;
if ( V_6 )
goto V_50;
switch ( V_4 -> V_119 . type ) {
case V_83 :
V_6 = F_43 ( V_4 , & V_4 -> V_119 ) ;
break;
case V_120 :
V_6 = F_37 ( V_4 , & V_4 -> V_119 ) ;
break;
case V_121 :
V_6 = F_44 ( V_4 ) ;
break;
case V_122 :
V_6 = F_46 ( V_4 , & V_4 -> V_119 ) ;
break;
case V_123 :
V_6 = F_49 ( V_4 , & V_4 -> V_119 ) ;
break;
case V_124 :
V_6 = F_50 ( V_4 , & V_4 -> V_119 ) ;
break;
case V_125 :
V_6 = F_51 ( V_4 , & V_4 -> V_119 ) ;
break;
default:
V_6 = - V_126 ;
}
V_50:
F_26 ( & V_4 -> V_111 ) ;
return V_6 ? V_6 : V_54 ;
}
static unsigned int F_63 ( struct V_110 * V_110 , T_9 * V_127 )
{
struct V_3 * V_4 = V_110 -> V_112 ;
F_64 ( V_110 , & V_4 -> V_16 , V_127 ) ;
if ( V_4 -> V_12 != V_4 -> V_14 )
return V_128 | V_129 ;
return 0 ;
}
static int T_10 F_65 ( void )
{
return F_66 ( & V_103 ) ;
}
static void T_11 F_67 ( void )
{
F_68 ( & V_103 ) ;
}
