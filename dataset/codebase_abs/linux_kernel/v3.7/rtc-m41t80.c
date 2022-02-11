static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 [ V_6 ] , V_7 [ 1 ] = { V_8 } ;
struct V_9 V_10 [] = {
{
. V_11 = V_2 -> V_11 ,
. V_12 = 0 ,
. V_13 = 1 ,
. V_5 = V_7 ,
} ,
{
. V_11 = V_2 -> V_11 ,
. V_12 = V_14 ,
. V_13 = V_6 - V_8 ,
. V_5 = V_5 + V_8 ,
} ,
} ;
if ( F_2 ( V_2 -> V_15 , V_10 , 2 ) < 0 ) {
F_3 ( & V_2 -> V_16 , L_1 ) ;
return - V_17 ;
}
V_4 -> V_18 = F_4 ( V_5 [ V_8 ] & 0x7f ) ;
V_4 -> V_19 = F_4 ( V_5 [ V_20 ] & 0x7f ) ;
V_4 -> V_21 = F_4 ( V_5 [ V_22 ] & 0x3f ) ;
V_4 -> V_23 = F_4 ( V_5 [ V_24 ] & 0x3f ) ;
V_4 -> V_25 = V_5 [ V_26 ] & 0x07 ;
V_4 -> V_27 = F_4 ( V_5 [ V_28 ] & 0x1f ) - 1 ;
V_4 -> V_29 = F_4 ( V_5 [ V_30 ] ) + 100 ;
return F_5 ( V_4 ) ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_31 [ 1 + V_6 ] ;
T_1 * V_5 = & V_31 [ 1 ] ;
T_1 V_7 [ 1 ] = { V_8 } ;
struct V_9 V_32 [] = {
{
. V_11 = V_2 -> V_11 ,
. V_12 = 0 ,
. V_13 = 1 ,
. V_5 = V_7 ,
} ,
{
. V_11 = V_2 -> V_11 ,
. V_12 = V_14 ,
. V_13 = V_6 - V_8 ,
. V_5 = V_5 + V_8 ,
} ,
} ;
struct V_9 V_10 [] = {
{
. V_11 = V_2 -> V_11 ,
. V_12 = 0 ,
. V_13 = 1 + V_6 ,
. V_5 = V_31 ,
} ,
} ;
if ( F_2 ( V_2 -> V_15 , V_32 , 2 ) < 0 ) {
F_3 ( & V_2 -> V_16 , L_1 ) ;
return - V_17 ;
}
V_31 [ 0 ] = 0 ;
V_5 [ V_33 ] = 0 ;
V_5 [ V_8 ] =
F_7 ( V_4 -> V_18 ) | ( V_5 [ V_8 ] & ~ 0x7f ) ;
V_5 [ V_20 ] =
F_7 ( V_4 -> V_19 ) | ( V_5 [ V_20 ] & ~ 0x7f ) ;
V_5 [ V_22 ] =
F_7 ( V_4 -> V_21 ) | ( V_5 [ V_22 ] & ~ 0x3f ) ;
V_5 [ V_26 ] =
( V_4 -> V_25 & 0x07 ) | ( V_5 [ V_26 ] & ~ 0x07 ) ;
V_5 [ V_24 ] =
F_7 ( V_4 -> V_23 ) | ( V_5 [ V_24 ] & ~ 0x3f ) ;
V_5 [ V_28 ] =
F_7 ( V_4 -> V_27 + 1 ) | ( V_5 [ V_28 ] & ~ 0x1f ) ;
V_5 [ V_30 ] = F_7 ( V_4 -> V_29 % 100 ) ;
if ( F_2 ( V_2 -> V_15 , V_10 , 1 ) != 1 ) {
F_3 ( & V_2 -> V_16 , L_2 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_8 ( struct V_34 * V_16 , struct V_35 * V_36 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_37 * V_38 = F_10 ( V_2 ) ;
T_1 V_39 ;
if ( V_38 -> V_40 & V_41 ) {
V_39 = F_11 ( V_2 , V_42 ) ;
F_12 ( V_36 , L_3 ,
( V_39 & V_43 ) ? L_4 : L_5 ) ;
}
return 0 ;
}
static int F_13 ( struct V_34 * V_16 , struct V_3 * V_4 )
{
return F_1 ( F_9 ( V_16 ) , V_4 ) ;
}
static int F_14 ( struct V_34 * V_16 , struct V_3 * V_4 )
{
return F_6 ( F_9 ( V_16 ) , V_4 ) ;
}
static T_2 F_15 ( struct V_34 * V_16 ,
struct V_44 * V_45 , char * V_5 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
int V_46 ;
V_46 = F_11 ( V_2 , V_42 ) ;
if ( V_46 < 0 )
return - V_17 ;
return sprintf ( V_5 , L_6 , V_46 ) ;
}
static T_2 F_16 ( struct V_34 * V_16 ,
struct V_44 * V_45 , char * V_5 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_37 * V_38 = F_10 ( V_2 ) ;
int V_46 , V_47 ;
if ( ! ( V_38 -> V_40 & V_48 ) )
return - V_49 ;
V_47 = V_50 ;
if ( V_38 -> V_40 & V_51 )
V_47 = V_26 ;
V_46 = F_11 ( V_2 , V_47 ) ;
if ( V_46 < 0 )
return - V_17 ;
V_46 = ( V_46 >> 4 ) & 0xf ;
switch ( V_46 ) {
case 0 :
break;
case 1 :
V_46 = 32768 ;
break;
default:
V_46 = 32768 >> V_46 ;
}
return sprintf ( V_5 , L_7 , V_46 ) ;
}
static T_2 F_17 ( struct V_34 * V_16 ,
struct V_44 * V_45 ,
const char * V_5 , T_3 V_52 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_37 * V_38 = F_10 ( V_2 ) ;
int V_53 , V_54 , V_47 ;
int V_46 = F_18 ( V_5 , NULL , 0 ) ;
if ( ! ( V_38 -> V_40 & V_48 ) )
return - V_49 ;
if ( V_46 ) {
if ( ! F_19 ( V_46 ) )
return - V_49 ;
V_46 = F_20 ( V_46 ) ;
if ( V_46 == 15 )
V_46 = 1 ;
else if ( V_46 < 14 )
V_46 = 15 - V_46 ;
else
return - V_49 ;
}
V_53 = F_11 ( V_2 , V_55 ) ;
if ( V_53 < 0 )
return - V_17 ;
V_47 = V_50 ;
if ( V_38 -> V_40 & V_51 )
V_47 = V_26 ;
V_54 = F_11 ( V_2 , V_47 ) ;
if ( V_54 < 0 )
return - V_17 ;
V_54 = ( V_54 & 0x0f ) | ( V_46 << 4 ) ;
if ( F_21 ( V_2 , V_55 ,
V_53 & ~ V_56 ) < 0 ||
F_21 ( V_2 , V_47 , V_54 ) < 0 )
return - V_17 ;
if ( V_46 && F_21 ( V_2 , V_55 ,
V_53 | V_56 ) < 0 )
return - V_17 ;
return V_52 ;
}
static int F_22 ( struct V_34 * V_16 )
{
return F_23 ( & V_16 -> V_57 , & V_58 ) ;
}
static int F_22 ( struct V_34 * V_16 )
{
return 0 ;
}
static void F_24 ( void )
{
unsigned char V_59 [ 2 ] ;
struct V_9 V_60 [ 1 ] = {
{
. V_11 = V_61 -> V_11 ,
. V_12 = 0 ,
. V_13 = 2 ,
. V_5 = V_59 ,
} ,
} ;
struct V_37 * V_38 = F_10 ( V_61 ) ;
V_59 [ 0 ] = 0x09 ;
if ( V_62 > 31 )
V_59 [ 1 ] = ( V_62 & 0xFC ) | 0x83 ;
else
V_59 [ 1 ] = V_62 << 2 | 0x82 ;
if ( V_38 -> V_40 & V_63 )
V_59 [ 1 ] &= ~ V_64 ;
F_2 ( V_61 -> V_15 , V_60 , 1 ) ;
}
static void F_25 ( void )
{
unsigned char V_59 [ 2 ] , V_65 [ 0x10 ] ;
struct V_9 V_66 [ 2 ] = {
{
. V_11 = V_61 -> V_11 ,
. V_12 = 0 ,
. V_13 = 1 ,
. V_5 = V_59 ,
} ,
{
. V_11 = V_61 -> V_11 ,
. V_12 = V_14 ,
. V_13 = 1 ,
. V_5 = V_65 ,
} ,
} ;
struct V_9 V_60 [ 1 ] = {
{
. V_11 = V_61 -> V_11 ,
. V_12 = 0 ,
. V_13 = 2 ,
. V_5 = V_59 ,
} ,
} ;
V_59 [ 0 ] = 0x09 ;
F_2 ( V_61 -> V_15 , V_66 , 2 ) ;
V_59 [ 0 ] = 0x09 ;
V_59 [ 1 ] = 0x00 ;
F_2 ( V_61 -> V_15 , V_60 , 1 ) ;
}
static T_2 F_26 ( struct V_67 * V_67 , const char T_4 * V_5 ,
T_3 V_52 , T_5 * V_68 )
{
if ( V_52 ) {
F_24 () ;
return 1 ;
}
return 0 ;
}
static T_2 F_27 ( struct V_67 * V_67 , char T_4 * V_5 ,
T_3 V_52 , T_5 * V_68 )
{
return 0 ;
}
static int F_28 ( struct V_67 * V_67 , unsigned int V_69 ,
unsigned long V_70 )
{
int V_71 , V_72 ;
static struct V_73 V_74 = {
. V_75 = V_76 | V_77 |
V_78 ,
. V_79 = 1 ,
. V_80 = L_8
} ;
switch ( V_69 ) {
case V_81 :
return F_29 ( (struct V_73 T_4 * ) V_70 , & V_74 ,
sizeof( V_74 ) ) ? - V_82 : 0 ;
case V_83 :
case V_84 :
return F_30 ( V_85 , ( int T_4 * ) V_70 ) ;
case V_86 :
F_24 () ;
return 0 ;
case V_87 :
if ( F_31 ( V_71 , ( int T_4 * ) V_70 ) )
return - V_82 ;
if ( V_71 < 1 || V_71 > 124 )
return - V_49 ;
V_62 = V_71 ;
F_24 () ;
case V_88 :
return F_30 ( V_62 , ( int T_4 * ) V_70 ) ;
case V_89 :
if ( F_32 ( & V_72 , ( int T_4 * ) V_70 , sizeof( int ) ) )
return - V_82 ;
if ( V_72 & V_90 ) {
F_33 ( L_9 ) ;
F_25 () ;
}
if ( V_72 & V_91 ) {
F_33 ( L_10 ) ;
F_24 () ;
}
return - V_49 ;
}
return - V_92 ;
}
static long F_34 ( struct V_67 * V_67 , unsigned int V_69 ,
unsigned long V_70 )
{
int V_93 ;
F_35 ( & V_94 ) ;
V_93 = F_28 ( V_67 , V_69 , V_70 ) ;
F_36 ( & V_94 ) ;
return V_93 ;
}
static int F_37 ( struct V_95 * V_95 , struct V_67 * V_67 )
{
if ( F_38 ( V_95 -> V_96 ) == V_97 ) {
F_35 ( & V_94 ) ;
if ( F_39 ( 0 , & V_98 ) ) {
F_36 ( & V_94 ) ;
return - V_99 ;
}
V_98 = 1 ;
F_36 ( & V_94 ) ;
return F_40 ( V_95 , V_67 ) ;
}
return - V_100 ;
}
static int F_41 ( struct V_95 * V_95 , struct V_67 * V_67 )
{
if ( F_38 ( V_95 -> V_96 ) == V_97 )
F_42 ( 0 , & V_98 ) ;
return 0 ;
}
static int F_43 ( struct V_101 * V_102 , unsigned long V_103 ,
void * V_104 )
{
if ( V_103 == V_105 || V_103 == V_106 )
F_25 () ;
return V_107 ;
}
static int F_44 ( struct V_1 * V_2 ,
const struct V_108 * V_109 )
{
int V_110 = 0 ;
struct V_111 * V_112 = NULL ;
struct V_3 V_4 ;
struct V_37 * V_38 = NULL ;
if ( ! F_45 ( V_2 -> V_15 , V_113
| V_114 ) ) {
V_110 = - V_100 ;
goto exit;
}
F_46 ( & V_2 -> V_16 ,
L_11 V_115 L_12 ) ;
V_38 = F_47 ( sizeof( * V_38 ) , V_116 ) ;
if ( ! V_38 ) {
V_110 = - V_117 ;
goto exit;
}
V_38 -> V_40 = V_109 -> V_118 ;
F_48 ( V_2 , V_38 ) ;
V_112 = F_49 ( V_2 -> V_119 , & V_2 -> V_16 ,
& V_120 , V_121 ) ;
if ( F_50 ( V_112 ) ) {
V_110 = F_51 ( V_112 ) ;
V_112 = NULL ;
goto exit;
}
V_38 -> V_112 = V_112 ;
V_110 = F_11 ( V_2 , V_122 ) ;
if ( V_110 < 0 )
goto V_123;
if ( V_110 & V_124 ) {
if ( V_38 -> V_40 & V_125 ) {
F_1 ( V_2 , & V_4 ) ;
F_46 ( & V_2 -> V_16 , L_13 ) ;
F_46 ( & V_2 -> V_16 ,
L_14
L_15 ,
V_4 . V_29 + 1900 ,
V_4 . V_27 + 1 , V_4 . V_23 , V_4 . V_21 ,
V_4 . V_19 , V_4 . V_18 ) ;
}
if ( F_21 ( V_2 ,
V_122 ,
V_110 & ~ V_124 ) < 0 )
goto V_123;
}
V_110 = F_11 ( V_2 , V_8 ) ;
if ( V_110 < 0 )
goto V_126;
if ( V_110 & V_127 ) {
if ( F_21 ( V_2 , V_8 ,
V_110 & ~ V_127 ) < 0 )
goto V_126;
}
V_110 = F_22 ( & V_2 -> V_16 ) ;
if ( V_110 )
goto exit;
#ifdef F_52
if ( V_38 -> V_40 & V_125 ) {
V_61 = V_2 ;
V_110 = F_53 ( & V_128 ) ;
if ( V_110 )
goto exit;
V_110 = F_54 ( & V_129 ) ;
if ( V_110 ) {
F_55 ( & V_128 ) ;
goto exit;
}
}
#endif
return 0 ;
V_126:
V_110 = - V_17 ;
F_3 ( & V_2 -> V_16 , L_16 ) ;
goto exit;
V_123:
V_110 = - V_17 ;
F_3 ( & V_2 -> V_16 , L_17 ) ;
goto exit;
exit:
if ( V_112 )
F_56 ( V_112 ) ;
F_57 ( V_38 ) ;
return V_110 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_10 ( V_2 ) ;
struct V_111 * V_112 = V_38 -> V_112 ;
#ifdef F_52
if ( V_38 -> V_40 & V_125 ) {
F_55 ( & V_128 ) ;
F_59 ( & V_129 ) ;
}
#endif
if ( V_112 )
F_56 ( V_112 ) ;
F_57 ( V_38 ) ;
return 0 ;
}
