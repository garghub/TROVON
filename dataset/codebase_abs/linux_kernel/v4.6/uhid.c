static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 ;
V_5 = ( V_2 -> V_6 + 1 ) % V_7 ;
if ( V_5 != V_2 -> V_8 ) {
V_2 -> V_9 [ V_2 -> V_6 ] = V_4 ;
V_2 -> V_6 = V_5 ;
F_2 ( & V_2 -> V_10 ) ;
} else {
F_3 ( V_2 -> V_11 , L_1 ) ;
F_4 ( V_4 ) ;
}
}
static int F_5 ( struct V_1 * V_2 , T_2 V_12 )
{
unsigned long V_13 ;
struct V_3 * V_4 ;
V_4 = F_6 ( sizeof( * V_4 ) , V_14 ) ;
if ( ! V_4 )
return - V_15 ;
V_4 -> type = V_12 ;
F_7 ( & V_2 -> V_16 , V_13 ) ;
F_1 ( V_2 , V_4 ) ;
F_8 ( & V_2 -> V_16 , V_13 ) ;
return 0 ;
}
static int F_9 ( struct V_17 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_18 ;
struct V_3 * V_4 ;
unsigned long V_13 ;
V_4 = F_6 ( sizeof( * V_4 ) , V_14 ) ;
if ( ! V_4 )
return - V_15 ;
V_4 -> type = V_19 ;
if ( V_11 -> V_20 [ V_21 ] . V_22 )
V_4 -> V_23 . V_24 . V_25 |= V_26 ;
if ( V_11 -> V_20 [ V_27 ] . V_22 )
V_4 -> V_23 . V_24 . V_25 |= V_28 ;
if ( V_11 -> V_20 [ V_29 ] . V_22 )
V_4 -> V_23 . V_24 . V_25 |= V_30 ;
F_7 ( & V_2 -> V_16 , V_13 ) ;
F_1 ( V_2 , V_4 ) ;
F_8 ( & V_2 -> V_16 , V_13 ) ;
return 0 ;
}
static void F_10 ( struct V_17 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_18 ;
V_11 -> V_31 = 0 ;
F_5 ( V_2 , V_32 ) ;
}
static int F_11 ( struct V_17 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_18 ;
return F_5 ( V_2 , V_33 ) ;
}
static void F_12 ( struct V_17 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_18 ;
F_5 ( V_2 , V_34 ) ;
}
static int F_13 ( struct V_17 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_18 ;
return F_14 ( V_11 , V_2 -> V_35 , V_2 -> V_36 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_2 * V_37 )
{
unsigned long V_13 ;
int V_38 ;
F_7 ( & V_2 -> V_16 , V_13 ) ;
* V_37 = ++ V_2 -> V_37 ;
V_2 -> V_39 = V_4 -> type + 1 ;
V_2 -> V_40 = true ;
F_1 ( V_2 , V_4 ) ;
F_8 ( & V_2 -> V_16 , V_13 ) ;
V_38 = F_16 ( V_2 -> V_41 ,
! V_2 -> V_40 || ! V_2 -> V_42 ,
5 * V_43 ) ;
if ( ! V_38 || ! V_2 -> V_42 || V_2 -> V_40 )
V_38 = - V_44 ;
else if ( V_38 < 0 )
V_38 = - V_45 ;
else
V_38 = 0 ;
V_2 -> V_40 = false ;
return V_38 ;
}
static void F_17 ( struct V_1 * V_2 , T_3 V_46 ,
const struct V_3 * V_4 )
{
unsigned long V_13 ;
F_7 ( & V_2 -> V_16 , V_13 ) ;
if ( V_2 -> V_39 != V_4 -> type || V_2 -> V_37 != V_46 )
goto V_47;
if ( ! V_2 -> V_40 )
goto V_47;
memcpy ( & V_2 -> V_48 , V_4 , sizeof( * V_4 ) ) ;
V_2 -> V_40 = false ;
F_2 ( & V_2 -> V_41 ) ;
V_47:
F_8 ( & V_2 -> V_16 , V_13 ) ;
}
static int F_18 ( struct V_17 * V_11 , unsigned char V_49 ,
T_4 * V_50 , T_5 V_51 , T_4 V_52 )
{
struct V_1 * V_2 = V_11 -> V_18 ;
struct V_53 * V_54 ;
struct V_3 * V_4 ;
int V_38 ;
if ( ! V_2 -> V_42 )
return - V_44 ;
V_4 = F_6 ( sizeof( * V_4 ) , V_14 ) ;
if ( ! V_4 )
return - V_15 ;
V_4 -> type = V_55 ;
V_4 -> V_23 . V_56 . V_49 = V_49 ;
V_4 -> V_23 . V_56 . V_52 = V_52 ;
V_38 = F_19 ( & V_2 -> V_57 ) ;
if ( V_38 ) {
F_4 ( V_4 ) ;
return V_38 ;
}
V_38 = F_15 ( V_2 , V_4 , & V_4 -> V_23 . V_56 . V_46 ) ;
if ( V_38 )
goto V_47;
V_54 = & V_2 -> V_48 . V_23 . V_58 ;
if ( V_54 -> V_59 ) {
V_38 = - V_44 ;
} else {
V_38 = F_20 ( V_51 , ( T_5 ) V_54 -> V_60 , ( T_5 ) V_61 ) ;
memcpy ( V_50 , V_54 -> V_62 , V_38 ) ;
}
V_47:
F_21 ( & V_2 -> V_57 ) ;
return V_38 ;
}
static int F_22 ( struct V_17 * V_11 , unsigned char V_49 ,
const T_4 * V_50 , T_5 V_51 , T_4 V_52 )
{
struct V_1 * V_2 = V_11 -> V_18 ;
struct V_3 * V_4 ;
int V_38 ;
if ( ! V_2 -> V_42 || V_51 > V_61 )
return - V_44 ;
V_4 = F_6 ( sizeof( * V_4 ) , V_14 ) ;
if ( ! V_4 )
return - V_15 ;
V_4 -> type = V_63 ;
V_4 -> V_23 . V_64 . V_49 = V_49 ;
V_4 -> V_23 . V_64 . V_52 = V_52 ;
V_4 -> V_23 . V_64 . V_60 = V_51 ;
memcpy ( V_4 -> V_23 . V_64 . V_62 , V_50 , V_51 ) ;
V_38 = F_19 ( & V_2 -> V_57 ) ;
if ( V_38 ) {
F_4 ( V_4 ) ;
return V_38 ;
}
V_38 = F_15 ( V_2 , V_4 , & V_4 -> V_23 . V_64 . V_46 ) ;
if ( V_38 )
goto V_47;
if ( V_2 -> V_48 . V_23 . V_65 . V_59 )
V_38 = - V_44 ;
else
V_38 = V_51 ;
V_47:
F_21 ( & V_2 -> V_57 ) ;
return V_38 ;
}
static int F_23 ( struct V_17 * V_11 , unsigned char V_66 ,
T_1 * V_50 , T_5 V_67 , unsigned char V_52 ,
int V_68 )
{
T_4 V_69 ;
switch ( V_52 ) {
case V_21 :
V_69 = V_70 ;
break;
case V_27 :
V_69 = V_71 ;
break;
case V_29 :
V_69 = V_72 ;
break;
default:
return - V_73 ;
}
switch ( V_68 ) {
case V_74 :
return F_18 ( V_11 , V_66 , V_50 , V_67 , V_69 ) ;
case V_75 :
return F_22 ( V_11 , V_66 , V_50 , V_67 , V_69 ) ;
default:
return - V_44 ;
}
}
static int F_24 ( struct V_17 * V_11 , T_1 * V_50 , T_5 V_51 ,
unsigned char V_39 )
{
struct V_1 * V_2 = V_11 -> V_18 ;
T_1 V_52 ;
unsigned long V_13 ;
struct V_3 * V_4 ;
switch ( V_39 ) {
case V_21 :
V_52 = V_70 ;
break;
case V_27 :
V_52 = V_71 ;
break;
default:
return - V_73 ;
}
if ( V_51 < 1 || V_51 > V_61 )
return - V_73 ;
V_4 = F_6 ( sizeof( * V_4 ) , V_14 ) ;
if ( ! V_4 )
return - V_15 ;
V_4 -> type = V_76 ;
V_4 -> V_23 . V_77 . V_60 = V_51 ;
V_4 -> V_23 . V_77 . V_52 = V_52 ;
memcpy ( V_4 -> V_23 . V_77 . V_62 , V_50 , V_51 ) ;
F_7 ( & V_2 -> V_16 , V_13 ) ;
F_1 ( V_2 , V_4 ) ;
F_8 ( & V_2 -> V_16 , V_13 ) ;
return V_51 ;
}
static int F_25 ( struct V_17 * V_11 , T_1 * V_50 ,
T_5 V_51 )
{
return F_24 ( V_11 , V_50 , V_51 , V_27 ) ;
}
static int F_26 ( const char T_6 * V_78 , T_5 V_67 ,
struct V_3 * V_12 )
{
if ( F_27 () ) {
T_3 type ;
if ( F_28 ( type , V_78 ) )
return - V_79 ;
if ( type == V_80 ) {
struct V_81 * V_82 ;
V_82 = F_6 ( sizeof( * V_82 ) , V_14 ) ;
if ( ! V_82 )
return - V_15 ;
V_78 += sizeof( type ) ;
V_67 -= sizeof( type ) ;
if ( F_29 ( V_82 , V_78 ,
F_30 ( V_67 , sizeof( * V_82 ) ) ) ) {
F_4 ( V_82 ) ;
return - V_79 ;
}
V_12 -> type = type ;
memcpy ( V_12 -> V_23 . V_83 . V_84 , V_82 -> V_84 ,
sizeof( V_82 -> V_84 ) ) ;
memcpy ( V_12 -> V_23 . V_83 . V_85 , V_82 -> V_85 ,
sizeof( V_82 -> V_85 ) ) ;
memcpy ( V_12 -> V_23 . V_83 . V_86 , V_82 -> V_86 ,
sizeof( V_82 -> V_86 ) ) ;
V_12 -> V_23 . V_83 . V_35 = F_31 ( V_82 -> V_35 ) ;
V_12 -> V_23 . V_83 . V_36 = V_82 -> V_36 ;
V_12 -> V_23 . V_83 . V_87 = V_82 -> V_87 ;
V_12 -> V_23 . V_83 . V_88 = V_82 -> V_88 ;
V_12 -> V_23 . V_83 . V_89 = V_82 -> V_89 ;
V_12 -> V_23 . V_83 . V_90 = V_82 -> V_90 ;
V_12 -> V_23 . V_83 . V_91 = V_82 -> V_91 ;
F_4 ( V_82 ) ;
return 0 ;
}
}
if ( F_29 ( V_12 , V_78 , F_30 ( V_67 , sizeof( * V_12 ) ) ) )
return - V_79 ;
return 0 ;
}
static int F_26 ( const char T_6 * V_78 , T_5 V_67 ,
struct V_3 * V_12 )
{
if ( F_29 ( V_12 , V_78 , F_30 ( V_67 , sizeof( * V_12 ) ) ) )
return - V_79 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_17 * V_11 ;
T_5 V_36 , V_67 ;
void * V_35 ;
int V_38 ;
if ( V_2 -> V_42 )
return - V_92 ;
V_36 = V_4 -> V_23 . V_93 . V_36 ;
if ( V_36 <= 0 || V_36 > V_94 )
return - V_73 ;
V_35 = F_33 ( V_4 -> V_23 . V_93 . V_35 , V_36 , V_14 ) ;
if ( ! V_35 )
return - V_15 ;
V_2 -> V_36 = V_36 ;
V_2 -> V_35 = V_35 ;
V_11 = F_34 () ;
if ( F_35 ( V_11 ) ) {
V_38 = F_36 ( V_11 ) ;
goto V_95;
}
V_67 = F_30 ( sizeof( V_11 -> V_84 ) , sizeof( V_4 -> V_23 . V_93 . V_84 ) ) - 1 ;
strncpy ( V_11 -> V_84 , V_4 -> V_23 . V_93 . V_84 , V_67 ) ;
V_67 = F_30 ( sizeof( V_11 -> V_85 ) , sizeof( V_4 -> V_23 . V_93 . V_85 ) ) - 1 ;
strncpy ( V_11 -> V_85 , V_4 -> V_23 . V_93 . V_85 , V_67 ) ;
V_67 = F_30 ( sizeof( V_11 -> V_86 ) , sizeof( V_4 -> V_23 . V_93 . V_86 ) ) - 1 ;
strncpy ( V_11 -> V_86 , V_4 -> V_23 . V_93 . V_86 , V_67 ) ;
V_11 -> V_96 = & V_97 ;
V_11 -> V_87 = V_4 -> V_23 . V_93 . V_87 ;
V_11 -> V_88 = V_4 -> V_23 . V_93 . V_88 ;
V_11 -> V_89 = V_4 -> V_23 . V_93 . V_89 ;
V_11 -> V_90 = V_4 -> V_23 . V_93 . V_90 ;
V_11 -> V_91 = V_4 -> V_23 . V_93 . V_91 ;
V_11 -> V_18 = V_2 ;
V_11 -> V_98 . V_99 = V_100 . V_101 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_42 = true ;
V_38 = F_37 ( V_11 ) ;
if ( V_38 ) {
F_38 ( V_11 , L_2 ) ;
goto V_102;
}
return 0 ;
V_102:
F_39 ( V_11 ) ;
V_2 -> V_11 = NULL ;
V_2 -> V_42 = false ;
V_95:
F_4 ( V_2 -> V_35 ) ;
V_2 -> V_35 = NULL ;
V_2 -> V_36 = 0 ;
return V_38 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_103 V_104 ;
V_104 = V_4 -> V_23 . V_83 ;
if ( V_104 . V_36 <= 0 || V_104 . V_36 > V_94 )
return - V_73 ;
if ( F_29 ( & V_4 -> V_23 . V_93 . V_35 , V_104 . V_35 , V_104 . V_36 ) )
return - V_79 ;
memcpy ( V_4 -> V_23 . V_93 . V_84 , V_104 . V_84 , sizeof( V_104 . V_84 ) ) ;
memcpy ( V_4 -> V_23 . V_93 . V_85 , V_104 . V_85 , sizeof( V_104 . V_85 ) ) ;
memcpy ( V_4 -> V_23 . V_93 . V_86 , V_104 . V_86 , sizeof( V_104 . V_86 ) ) ;
V_4 -> V_23 . V_93 . V_36 = V_104 . V_36 ;
V_4 -> V_23 . V_93 . V_87 = V_104 . V_87 ;
V_4 -> V_23 . V_93 . V_88 = V_104 . V_88 ;
V_4 -> V_23 . V_93 . V_89 = V_104 . V_89 ;
V_4 -> V_23 . V_93 . V_90 = V_104 . V_90 ;
V_4 -> V_23 . V_93 . V_91 = V_104 . V_91 ;
return F_32 ( V_2 , V_4 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_42 )
return - V_73 ;
V_2 -> V_42 = false ;
F_2 ( & V_2 -> V_41 ) ;
F_39 ( V_2 -> V_11 ) ;
F_4 ( V_2 -> V_35 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( ! V_2 -> V_42 )
return - V_73 ;
F_43 ( V_2 -> V_11 , V_29 , V_4 -> V_23 . V_105 . V_62 ,
F_44 ( T_5 , V_4 -> V_23 . V_105 . V_60 , V_61 ) , 0 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( ! V_2 -> V_42 )
return - V_73 ;
F_43 ( V_2 -> V_11 , V_29 , V_4 -> V_23 . V_106 . V_62 ,
F_44 ( T_5 , V_4 -> V_23 . V_106 . V_60 , V_61 ) , 0 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( ! V_2 -> V_42 )
return - V_73 ;
F_17 ( V_2 , V_4 -> V_23 . V_58 . V_46 , V_4 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( ! V_2 -> V_42 )
return - V_73 ;
F_17 ( V_2 , V_4 -> V_23 . V_65 . V_46 , V_4 ) ;
return 0 ;
}
static int F_48 ( struct V_107 * V_107 , struct V_108 * V_108 )
{
struct V_1 * V_2 ;
V_2 = F_6 ( sizeof( * V_2 ) , V_14 ) ;
if ( ! V_2 )
return - V_15 ;
F_49 ( & V_2 -> V_109 ) ;
F_49 ( & V_2 -> V_57 ) ;
F_50 ( & V_2 -> V_16 ) ;
F_51 ( & V_2 -> V_10 ) ;
F_51 ( & V_2 -> V_41 ) ;
V_2 -> V_42 = false ;
V_108 -> V_110 = V_2 ;
F_52 ( V_107 , V_108 ) ;
return 0 ;
}
static int F_53 ( struct V_107 * V_107 , struct V_108 * V_108 )
{
struct V_1 * V_2 = V_108 -> V_110 ;
unsigned int V_111 ;
F_41 ( V_2 ) ;
for ( V_111 = 0 ; V_111 < V_7 ; ++ V_111 )
F_4 ( V_2 -> V_9 [ V_111 ] ) ;
F_4 ( V_2 ) ;
return 0 ;
}
static T_7 F_54 ( struct V_108 * V_108 , char T_6 * V_78 ,
T_5 V_51 , T_8 * V_112 )
{
struct V_1 * V_2 = V_108 -> V_110 ;
int V_38 ;
unsigned long V_13 ;
T_5 V_67 ;
if ( V_51 < sizeof( T_2 ) )
return - V_73 ;
V_113:
if ( V_108 -> V_114 & V_115 ) {
if ( V_2 -> V_6 == V_2 -> V_8 )
return - V_116 ;
} else {
V_38 = F_55 ( V_2 -> V_10 ,
V_2 -> V_6 != V_2 -> V_8 ) ;
if ( V_38 )
return V_38 ;
}
V_38 = F_19 ( & V_2 -> V_109 ) ;
if ( V_38 )
return V_38 ;
if ( V_2 -> V_6 == V_2 -> V_8 ) {
F_21 ( & V_2 -> V_109 ) ;
goto V_113;
} else {
V_67 = F_30 ( V_51 , sizeof( * * V_2 -> V_9 ) ) ;
if ( F_56 ( V_78 , V_2 -> V_9 [ V_2 -> V_8 ] , V_67 ) ) {
V_38 = - V_79 ;
} else {
F_4 ( V_2 -> V_9 [ V_2 -> V_8 ] ) ;
V_2 -> V_9 [ V_2 -> V_8 ] = NULL ;
F_7 ( & V_2 -> V_16 , V_13 ) ;
V_2 -> V_8 = ( V_2 -> V_8 + 1 ) % V_7 ;
F_8 ( & V_2 -> V_16 , V_13 ) ;
}
}
F_21 ( & V_2 -> V_109 ) ;
return V_38 ? V_38 : V_67 ;
}
static T_7 F_57 ( struct V_108 * V_108 , const char T_6 * V_78 ,
T_5 V_51 , T_8 * V_112 )
{
struct V_1 * V_2 = V_108 -> V_110 ;
int V_38 ;
T_5 V_67 ;
if ( V_51 < sizeof( T_2 ) )
return - V_73 ;
V_38 = F_19 ( & V_2 -> V_109 ) ;
if ( V_38 )
return V_38 ;
memset ( & V_2 -> V_117 , 0 , sizeof( V_2 -> V_117 ) ) ;
V_67 = F_30 ( V_51 , sizeof( V_2 -> V_117 ) ) ;
V_38 = F_26 ( V_78 , V_67 , & V_2 -> V_117 ) ;
if ( V_38 )
goto V_47;
switch ( V_2 -> V_117 . type ) {
case V_80 :
V_38 = F_40 ( V_2 , & V_2 -> V_117 ) ;
break;
case V_118 :
V_38 = F_32 ( V_2 , & V_2 -> V_117 ) ;
break;
case V_119 :
V_38 = F_41 ( V_2 ) ;
break;
case V_120 :
V_38 = F_42 ( V_2 , & V_2 -> V_117 ) ;
break;
case V_121 :
V_38 = F_45 ( V_2 , & V_2 -> V_117 ) ;
break;
case V_122 :
V_38 = F_46 ( V_2 , & V_2 -> V_117 ) ;
break;
case V_123 :
V_38 = F_47 ( V_2 , & V_2 -> V_117 ) ;
break;
default:
V_38 = - V_124 ;
}
V_47:
F_21 ( & V_2 -> V_109 ) ;
return V_38 ? V_38 : V_51 ;
}
static unsigned int F_58 ( struct V_108 * V_108 , T_9 * V_125 )
{
struct V_1 * V_2 = V_108 -> V_110 ;
F_59 ( V_108 , & V_2 -> V_10 , V_125 ) ;
if ( V_2 -> V_6 != V_2 -> V_8 )
return V_126 | V_127 ;
return 0 ;
}
static int T_10 F_60 ( void )
{
return F_61 ( & V_100 ) ;
}
static void T_11 F_62 ( void )
{
F_63 ( & V_100 ) ;
}
