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
static int F_15 ( struct V_34 * V_16 , unsigned int V_44 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
int V_45 ;
V_45 = F_11 ( V_2 , V_46 ) ;
if ( V_45 < 0 )
goto V_47;
if ( V_44 )
V_45 |= V_48 ;
else
V_45 &= ~ V_48 ;
if ( F_16 ( V_2 , V_46 , V_45 ) < 0 )
goto V_47;
return 0 ;
V_47:
return - V_17 ;
}
static int F_17 ( struct V_34 * V_16 , struct V_49 * V_50 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
T_1 V_31 [ 1 + V_51 ] ;
T_1 * V_5 = & V_31 [ 1 ] ;
T_1 * V_39 = V_5 - V_46 ;
T_1 V_7 [ 1 ] = { V_46 } ;
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
. V_13 = V_51 ,
. V_5 = V_5 ,
} ,
} ;
struct V_9 V_10 [] = {
{
. V_11 = V_2 -> V_11 ,
. V_12 = 0 ,
. V_13 = 1 + V_51 ,
. V_5 = V_31 ,
} ,
} ;
if ( F_2 ( V_2 -> V_15 , V_32 , 2 ) < 0 ) {
F_3 ( & V_2 -> V_16 , L_1 ) ;
return - V_17 ;
}
V_39 [ V_46 ] &= ~ ( 0x1f | V_48 ) ;
V_39 [ V_52 ] = 0 ;
V_39 [ V_53 ] &= ~ ( 0x3f | 0x80 ) ;
V_39 [ V_54 ] = 0 ;
V_39 [ V_55 ] = 0 ;
V_31 [ 0 ] = V_46 ;
V_39 [ V_55 ] |= V_50 -> time . V_18 >= 0 ?
F_7 ( V_50 -> time . V_18 ) : 0x80 ;
V_39 [ V_54 ] |= V_50 -> time . V_19 >= 0 ?
F_7 ( V_50 -> time . V_19 ) : 0x80 ;
V_39 [ V_53 ] |= V_50 -> time . V_21 >= 0 ?
F_7 ( V_50 -> time . V_21 ) : 0x80 ;
V_39 [ V_52 ] |= V_50 -> time . V_23 >= 0 ?
F_7 ( V_50 -> time . V_23 ) : 0x80 ;
if ( V_50 -> time . V_27 >= 0 )
V_39 [ V_46 ] |= F_7 ( V_50 -> time . V_27 + 1 ) ;
else
V_39 [ V_52 ] |= 0x40 ;
if ( F_2 ( V_2 -> V_15 , V_10 , 1 ) != 1 ) {
F_3 ( & V_2 -> V_16 , L_2 ) ;
return - V_17 ;
}
if ( V_50 -> V_44 ) {
V_39 [ V_46 ] |= V_48 ;
if ( F_16 ( V_2 , V_46 ,
V_39 [ V_46 ] ) < 0 ) {
F_3 ( & V_2 -> V_16 , L_2 ) ;
return - V_17 ;
}
}
return 0 ;
}
static int F_18 ( struct V_34 * V_16 , struct V_49 * V_50 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
T_1 V_5 [ V_51 + 1 ] ;
T_1 V_7 [ 1 ] = { V_46 } ;
T_1 * V_39 = V_5 - V_46 ;
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
. V_13 = V_51 + 1 ,
. V_5 = V_5 ,
} ,
} ;
if ( F_2 ( V_2 -> V_15 , V_10 , 2 ) < 0 ) {
F_3 ( & V_2 -> V_16 , L_1 ) ;
return - V_17 ;
}
V_50 -> time . V_18 = - 1 ;
V_50 -> time . V_19 = - 1 ;
V_50 -> time . V_21 = - 1 ;
V_50 -> time . V_23 = - 1 ;
V_50 -> time . V_27 = - 1 ;
if ( ! ( V_39 [ V_55 ] & 0x80 ) )
V_50 -> time . V_18 = F_4 ( V_39 [ V_55 ] & 0x7f ) ;
if ( ! ( V_39 [ V_54 ] & 0x80 ) )
V_50 -> time . V_19 = F_4 ( V_39 [ V_54 ] & 0x7f ) ;
if ( ! ( V_39 [ V_53 ] & 0x80 ) )
V_50 -> time . V_21 = F_4 ( V_39 [ V_53 ] & 0x3f ) ;
if ( ! ( V_39 [ V_52 ] & 0x80 ) )
V_50 -> time . V_23 = F_4 ( V_39 [ V_52 ] & 0x3f ) ;
if ( ! ( V_39 [ V_52 ] & 0x40 ) )
V_50 -> time . V_27 = F_4 ( V_39 [ V_46 ] & 0x1f ) - 1 ;
V_50 -> time . V_29 = - 1 ;
V_50 -> time . V_25 = - 1 ;
V_50 -> time . V_56 = - 1 ;
V_50 -> time . V_57 = - 1 ;
V_50 -> V_44 = ! ! ( V_39 [ V_46 ] & V_48 ) ;
V_50 -> V_58 = ! ! ( V_39 [ V_42 ] & V_59 ) ;
return 0 ;
}
static T_2 F_19 ( struct V_34 * V_16 ,
struct V_60 * V_61 , char * V_5 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
int V_62 ;
V_62 = F_11 ( V_2 , V_42 ) ;
if ( V_62 < 0 )
return - V_17 ;
return sprintf ( V_5 , L_6 , V_62 ) ;
}
static T_2 F_20 ( struct V_34 * V_16 ,
struct V_60 * V_61 , char * V_5 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_37 * V_38 = F_10 ( V_2 ) ;
int V_62 , V_63 ;
if ( ! ( V_38 -> V_40 & V_64 ) )
return - V_65 ;
V_63 = V_66 ;
if ( V_38 -> V_40 & V_67 )
V_63 = V_26 ;
V_62 = F_11 ( V_2 , V_63 ) ;
if ( V_62 < 0 )
return - V_17 ;
V_62 = ( V_62 >> 4 ) & 0xf ;
switch ( V_62 ) {
case 0 :
break;
case 1 :
V_62 = 32768 ;
break;
default:
V_62 = 32768 >> V_62 ;
}
return sprintf ( V_5 , L_7 , V_62 ) ;
}
static T_2 F_21 ( struct V_34 * V_16 ,
struct V_60 * V_61 ,
const char * V_5 , T_3 V_68 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_37 * V_38 = F_10 ( V_2 ) ;
int V_69 , V_70 , V_63 ;
int V_62 = F_22 ( V_5 , NULL , 0 ) ;
if ( ! ( V_38 -> V_40 & V_64 ) )
return - V_65 ;
if ( V_62 ) {
if ( ! F_23 ( V_62 ) )
return - V_65 ;
V_62 = F_24 ( V_62 ) ;
if ( V_62 == 15 )
V_62 = 1 ;
else if ( V_62 < 14 )
V_62 = 15 - V_62 ;
else
return - V_65 ;
}
V_69 = F_11 ( V_2 , V_46 ) ;
if ( V_69 < 0 )
return - V_17 ;
V_63 = V_66 ;
if ( V_38 -> V_40 & V_67 )
V_63 = V_26 ;
V_70 = F_11 ( V_2 , V_63 ) ;
if ( V_70 < 0 )
return - V_17 ;
V_70 = ( V_70 & 0x0f ) | ( V_62 << 4 ) ;
if ( F_16 ( V_2 , V_46 ,
V_69 & ~ V_71 ) < 0 ||
F_16 ( V_2 , V_63 , V_70 ) < 0 )
return - V_17 ;
if ( V_62 && F_16 ( V_2 , V_46 ,
V_69 | V_71 ) < 0 )
return - V_17 ;
return V_68 ;
}
static int F_25 ( struct V_34 * V_16 )
{
return F_26 ( & V_16 -> V_72 , & V_73 ) ;
}
static int F_25 ( struct V_34 * V_16 )
{
return 0 ;
}
static void F_27 ( void )
{
unsigned char V_74 [ 2 ] ;
struct V_9 V_75 [ 1 ] = {
{
. V_11 = V_76 -> V_11 ,
. V_12 = 0 ,
. V_13 = 2 ,
. V_5 = V_74 ,
} ,
} ;
struct V_37 * V_38 = F_10 ( V_76 ) ;
V_74 [ 0 ] = 0x09 ;
if ( V_77 > 31 )
V_74 [ 1 ] = ( V_77 & 0xFC ) | 0x83 ;
else
V_74 [ 1 ] = V_77 << 2 | 0x82 ;
if ( V_38 -> V_40 & V_78 )
V_74 [ 1 ] &= ~ V_79 ;
F_2 ( V_76 -> V_15 , V_75 , 1 ) ;
}
static void F_28 ( void )
{
unsigned char V_74 [ 2 ] , V_80 [ 0x10 ] ;
struct V_9 V_81 [ 2 ] = {
{
. V_11 = V_76 -> V_11 ,
. V_12 = 0 ,
. V_13 = 1 ,
. V_5 = V_74 ,
} ,
{
. V_11 = V_76 -> V_11 ,
. V_12 = V_14 ,
. V_13 = 1 ,
. V_5 = V_80 ,
} ,
} ;
struct V_9 V_75 [ 1 ] = {
{
. V_11 = V_76 -> V_11 ,
. V_12 = 0 ,
. V_13 = 2 ,
. V_5 = V_74 ,
} ,
} ;
V_74 [ 0 ] = 0x09 ;
F_2 ( V_76 -> V_15 , V_81 , 2 ) ;
V_74 [ 0 ] = 0x09 ;
V_74 [ 1 ] = 0x00 ;
F_2 ( V_76 -> V_15 , V_75 , 1 ) ;
}
static T_2 F_29 ( struct V_82 * V_82 , const char T_4 * V_5 ,
T_3 V_68 , T_5 * V_83 )
{
if ( V_68 ) {
F_27 () ;
return 1 ;
}
return 0 ;
}
static T_2 F_30 ( struct V_82 * V_82 , char T_4 * V_5 ,
T_3 V_68 , T_5 * V_83 )
{
return 0 ;
}
static int F_31 ( struct V_82 * V_82 , unsigned int V_84 ,
unsigned long V_85 )
{
int V_86 , V_87 ;
static struct V_88 V_89 = {
. V_90 = V_91 | V_92 |
V_93 ,
. V_94 = 1 ,
. V_95 = L_8
} ;
switch ( V_84 ) {
case V_96 :
return F_32 ( (struct V_88 T_4 * ) V_85 , & V_89 ,
sizeof( V_89 ) ) ? - V_97 : 0 ;
case V_98 :
case V_99 :
return F_33 ( V_100 , ( int T_4 * ) V_85 ) ;
case V_101 :
F_27 () ;
return 0 ;
case V_102 :
if ( F_34 ( V_86 , ( int T_4 * ) V_85 ) )
return - V_97 ;
if ( V_86 < 1 || V_86 > 124 )
return - V_65 ;
V_77 = V_86 ;
F_27 () ;
case V_103 :
return F_33 ( V_77 , ( int T_4 * ) V_85 ) ;
case V_104 :
if ( F_35 ( & V_87 , ( int T_4 * ) V_85 , sizeof( int ) ) )
return - V_97 ;
if ( V_87 & V_105 ) {
F_36 ( L_9 ) ;
F_28 () ;
}
if ( V_87 & V_106 ) {
F_36 ( L_10 ) ;
F_27 () ;
}
return - V_65 ;
}
return - V_107 ;
}
static long F_37 ( struct V_82 * V_82 , unsigned int V_84 ,
unsigned long V_85 )
{
int V_108 ;
F_38 ( & V_109 ) ;
V_108 = F_31 ( V_82 , V_84 , V_85 ) ;
F_39 ( & V_109 ) ;
return V_108 ;
}
static int F_40 ( struct V_110 * V_110 , struct V_82 * V_82 )
{
if ( F_41 ( V_110 -> V_111 ) == V_112 ) {
F_38 ( & V_109 ) ;
if ( F_42 ( 0 , & V_113 ) ) {
F_39 ( & V_109 ) ;
return - V_114 ;
}
V_113 = 1 ;
F_39 ( & V_109 ) ;
return F_43 ( V_110 , V_82 ) ;
}
return - V_115 ;
}
static int F_44 ( struct V_110 * V_110 , struct V_82 * V_82 )
{
if ( F_41 ( V_110 -> V_111 ) == V_112 )
F_45 ( 0 , & V_113 ) ;
return 0 ;
}
static int F_46 ( struct V_116 * V_117 , unsigned long V_118 ,
void * V_119 )
{
if ( V_118 == V_120 || V_118 == V_121 )
F_28 () ;
return V_122 ;
}
static int F_47 ( struct V_1 * V_2 ,
const struct V_123 * V_124 )
{
int V_45 = 0 ;
struct V_125 * V_126 = NULL ;
struct V_3 V_4 ;
struct V_37 * V_38 = NULL ;
if ( ! F_48 ( V_2 -> V_15 , V_127
| V_128 ) ) {
V_45 = - V_115 ;
goto exit;
}
F_49 ( & V_2 -> V_16 ,
L_11 V_129 L_12 ) ;
V_38 = F_50 ( sizeof( * V_38 ) , V_130 ) ;
if ( ! V_38 ) {
V_45 = - V_131 ;
goto exit;
}
V_38 -> V_40 = V_124 -> V_132 ;
F_51 ( V_2 , V_38 ) ;
V_126 = F_52 ( V_2 -> V_133 , & V_2 -> V_16 ,
& V_134 , V_135 ) ;
if ( F_53 ( V_126 ) ) {
V_45 = F_54 ( V_126 ) ;
V_126 = NULL ;
goto exit;
}
V_38 -> V_126 = V_126 ;
V_45 = F_11 ( V_2 , V_53 ) ;
if ( V_45 < 0 )
goto V_136;
if ( V_45 & V_137 ) {
if ( V_38 -> V_40 & V_138 ) {
F_1 ( V_2 , & V_4 ) ;
F_49 ( & V_2 -> V_16 , L_13 ) ;
F_49 ( & V_2 -> V_16 ,
L_14
L_15 ,
V_4 . V_29 + 1900 ,
V_4 . V_27 + 1 , V_4 . V_23 , V_4 . V_21 ,
V_4 . V_19 , V_4 . V_18 ) ;
}
if ( F_16 ( V_2 ,
V_53 ,
V_45 & ~ V_137 ) < 0 )
goto V_136;
}
V_45 = F_11 ( V_2 , V_8 ) ;
if ( V_45 < 0 )
goto V_139;
if ( V_45 & V_140 ) {
if ( F_16 ( V_2 , V_8 ,
V_45 & ~ V_140 ) < 0 )
goto V_139;
}
V_45 = F_25 ( & V_2 -> V_16 ) ;
if ( V_45 )
goto exit;
#ifdef F_55
if ( V_38 -> V_40 & V_138 ) {
V_76 = V_2 ;
V_45 = F_56 ( & V_141 ) ;
if ( V_45 )
goto exit;
V_45 = F_57 ( & V_142 ) ;
if ( V_45 ) {
F_58 ( & V_141 ) ;
goto exit;
}
}
#endif
return 0 ;
V_139:
V_45 = - V_17 ;
F_3 ( & V_2 -> V_16 , L_16 ) ;
goto exit;
V_136:
V_45 = - V_17 ;
F_3 ( & V_2 -> V_16 , L_17 ) ;
goto exit;
exit:
if ( V_126 )
F_59 ( V_126 ) ;
F_60 ( V_38 ) ;
return V_45 ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_10 ( V_2 ) ;
struct V_125 * V_126 = V_38 -> V_126 ;
#ifdef F_55
if ( V_38 -> V_40 & V_138 ) {
F_58 ( & V_141 ) ;
F_62 ( & V_142 ) ;
}
#endif
if ( V_126 )
F_59 ( V_126 ) ;
F_60 ( V_38 ) ;
return 0 ;
}
