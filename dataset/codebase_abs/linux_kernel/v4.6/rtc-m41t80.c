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
if ( V_4 -> V_29 < 100 || V_4 -> V_29 > 199 ) {
F_3 ( & V_2 -> V_16 , L_2 ,
V_4 -> V_29 + 1900 ) ;
return - V_34 ;
}
V_5 [ V_30 ] = F_7 ( V_4 -> V_29 % 100 ) ;
if ( F_2 ( V_2 -> V_15 , V_10 , 1 ) != 1 ) {
F_3 ( & V_2 -> V_16 , L_3 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_8 ( struct V_35 * V_16 , struct V_36 * V_37 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_38 * V_39 = F_10 ( V_2 ) ;
T_1 V_40 ;
if ( V_39 -> V_41 & V_42 ) {
V_40 = F_11 ( V_2 , V_43 ) ;
F_12 ( V_37 , L_4 ,
( V_40 & V_44 ) ? L_5 : L_6 ) ;
}
return 0 ;
}
static int F_13 ( struct V_35 * V_16 , struct V_3 * V_4 )
{
return F_1 ( F_9 ( V_16 ) , V_4 ) ;
}
static int F_14 ( struct V_35 * V_16 , struct V_3 * V_4 )
{
return F_6 ( F_9 ( V_16 ) , V_4 ) ;
}
static T_2 F_15 ( struct V_35 * V_16 ,
struct V_45 * V_46 , char * V_5 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
int V_47 ;
V_47 = F_11 ( V_2 , V_43 ) ;
if ( V_47 < 0 )
return V_47 ;
return sprintf ( V_5 , L_7 , V_47 ) ;
}
static T_2 F_16 ( struct V_35 * V_16 ,
struct V_45 * V_46 , char * V_5 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_38 * V_39 = F_10 ( V_2 ) ;
int V_47 , V_48 ;
if ( ! ( V_39 -> V_41 & V_49 ) )
return - V_34 ;
V_48 = V_50 ;
if ( V_39 -> V_41 & V_51 )
V_48 = V_26 ;
V_47 = F_11 ( V_2 , V_48 ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = ( V_47 >> 4 ) & 0xf ;
switch ( V_47 ) {
case 0 :
break;
case 1 :
V_47 = 32768 ;
break;
default:
V_47 = 32768 >> V_47 ;
}
return sprintf ( V_5 , L_8 , V_47 ) ;
}
static T_2 F_17 ( struct V_35 * V_16 ,
struct V_45 * V_46 ,
const char * V_5 , T_3 V_52 )
{
struct V_1 * V_2 = F_9 ( V_16 ) ;
struct V_38 * V_39 = F_10 ( V_2 ) ;
int V_53 , V_54 , V_48 , V_55 ;
int V_47 = F_18 ( V_5 , NULL , 0 ) ;
if ( ! ( V_39 -> V_41 & V_49 ) )
return - V_34 ;
if ( V_47 ) {
if ( ! F_19 ( V_47 ) )
return - V_34 ;
V_47 = F_20 ( V_47 ) ;
if ( V_47 == 15 )
V_47 = 1 ;
else if ( V_47 < 14 )
V_47 = 15 - V_47 ;
else
return - V_34 ;
}
V_53 = F_11 ( V_2 , V_56 ) ;
if ( V_53 < 0 )
return V_53 ;
V_48 = V_50 ;
if ( V_39 -> V_41 & V_51 )
V_48 = V_26 ;
V_54 = F_11 ( V_2 , V_48 ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = ( V_54 & 0x0f ) | ( V_47 << 4 ) ;
V_55 = F_21 ( V_2 , V_56 ,
V_53 & ~ V_57 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( V_47 ) {
V_55 = F_21 ( V_2 , V_48 , V_54 ) ;
if ( V_55 < 0 )
return V_55 ;
V_55 = F_21 ( V_2 , V_56 ,
V_53 | V_57 ) ;
if ( V_55 < 0 )
return V_55 ;
}
return V_52 ;
}
static int F_22 ( struct V_35 * V_16 )
{
return F_23 ( & V_16 -> V_58 , & V_59 ) ;
}
static int F_22 ( struct V_35 * V_16 )
{
return 0 ;
}
static void F_24 ( void )
{
unsigned char V_60 [ 2 ] ;
struct V_9 V_61 [ 1 ] = {
{
. V_11 = V_62 -> V_11 ,
. V_12 = 0 ,
. V_13 = 2 ,
. V_5 = V_60 ,
} ,
} ;
struct V_38 * V_39 = F_10 ( V_62 ) ;
V_60 [ 0 ] = 0x09 ;
if ( V_63 > 31 )
V_60 [ 1 ] = ( V_63 & 0xFC ) | 0x83 ;
else
V_60 [ 1 ] = V_63 << 2 | 0x82 ;
if ( V_39 -> V_41 & V_64 )
V_60 [ 1 ] &= ~ V_65 ;
F_2 ( V_62 -> V_15 , V_61 , 1 ) ;
}
static void F_25 ( void )
{
unsigned char V_60 [ 2 ] , V_66 [ 0x10 ] ;
struct V_9 V_67 [ 2 ] = {
{
. V_11 = V_62 -> V_11 ,
. V_12 = 0 ,
. V_13 = 1 ,
. V_5 = V_60 ,
} ,
{
. V_11 = V_62 -> V_11 ,
. V_12 = V_14 ,
. V_13 = 1 ,
. V_5 = V_66 ,
} ,
} ;
struct V_9 V_61 [ 1 ] = {
{
. V_11 = V_62 -> V_11 ,
. V_12 = 0 ,
. V_13 = 2 ,
. V_5 = V_60 ,
} ,
} ;
V_60 [ 0 ] = 0x09 ;
F_2 ( V_62 -> V_15 , V_67 , 2 ) ;
V_60 [ 0 ] = 0x09 ;
V_60 [ 1 ] = 0x00 ;
F_2 ( V_62 -> V_15 , V_61 , 1 ) ;
}
static T_2 F_26 ( struct V_68 * V_68 , const char T_4 * V_5 ,
T_3 V_52 , T_5 * V_69 )
{
if ( V_52 ) {
F_24 () ;
return 1 ;
}
return 0 ;
}
static T_2 F_27 ( struct V_68 * V_68 , char T_4 * V_5 ,
T_3 V_52 , T_5 * V_69 )
{
return 0 ;
}
static int F_28 ( struct V_68 * V_68 , unsigned int V_70 ,
unsigned long V_71 )
{
int V_72 , V_73 ;
static struct V_74 V_75 = {
. V_76 = V_77 | V_78 |
V_79 ,
. V_80 = 1 ,
. V_81 = L_9
} ;
switch ( V_70 ) {
case V_82 :
return F_29 ( (struct V_74 T_4 * ) V_71 , & V_75 ,
sizeof( V_75 ) ) ? - V_83 : 0 ;
case V_84 :
case V_85 :
return F_30 ( V_86 , ( int T_4 * ) V_71 ) ;
case V_87 :
F_24 () ;
return 0 ;
case V_88 :
if ( F_31 ( V_72 , ( int T_4 * ) V_71 ) )
return - V_83 ;
if ( V_72 < 1 || V_72 > 124 )
return - V_34 ;
V_63 = V_72 ;
F_24 () ;
case V_89 :
return F_30 ( V_63 , ( int T_4 * ) V_71 ) ;
case V_90 :
if ( F_32 ( & V_73 , ( int T_4 * ) V_71 , sizeof( int ) ) )
return - V_83 ;
if ( V_73 & V_91 ) {
F_33 ( L_10 ) ;
F_25 () ;
}
if ( V_73 & V_92 ) {
F_33 ( L_11 ) ;
F_24 () ;
}
return - V_34 ;
}
return - V_93 ;
}
static long F_34 ( struct V_68 * V_68 , unsigned int V_70 ,
unsigned long V_71 )
{
int V_94 ;
F_35 ( & V_95 ) ;
V_94 = F_28 ( V_68 , V_70 , V_71 ) ;
F_36 ( & V_95 ) ;
return V_94 ;
}
static int F_37 ( struct V_96 * V_96 , struct V_68 * V_68 )
{
if ( F_38 ( V_96 -> V_97 ) == V_98 ) {
F_35 ( & V_95 ) ;
if ( F_39 ( 0 , & V_99 ) ) {
F_36 ( & V_95 ) ;
return - V_100 ;
}
V_99 = 1 ;
F_36 ( & V_95 ) ;
return F_40 ( V_96 , V_68 ) ;
}
return - V_101 ;
}
static int F_41 ( struct V_96 * V_96 , struct V_68 * V_68 )
{
if ( F_38 ( V_96 -> V_97 ) == V_98 )
F_42 ( 0 , & V_99 ) ;
return 0 ;
}
static int F_43 ( struct V_102 * V_103 , unsigned long V_104 ,
void * V_105 )
{
if ( V_104 == V_106 || V_104 == V_107 )
F_25 () ;
return V_108 ;
}
static int F_44 ( struct V_1 * V_2 ,
const struct V_109 * V_110 )
{
int V_55 = 0 ;
struct V_111 * V_112 = NULL ;
struct V_3 V_4 ;
struct V_38 * V_39 = NULL ;
if ( ! F_45 ( V_2 -> V_15 , V_113
| V_114 ) )
return - V_101 ;
V_39 = F_46 ( & V_2 -> V_16 , sizeof( * V_39 ) ,
V_115 ) ;
if ( ! V_39 )
return - V_116 ;
V_39 -> V_41 = V_110 -> V_117 ;
F_47 ( V_2 , V_39 ) ;
V_112 = F_48 ( & V_2 -> V_16 , V_2 -> V_118 ,
& V_119 , V_120 ) ;
if ( F_49 ( V_112 ) )
return F_50 ( V_112 ) ;
V_39 -> V_112 = V_112 ;
V_55 = F_11 ( V_2 , V_121 ) ;
if ( V_55 >= 0 && V_55 & V_122 ) {
if ( V_39 -> V_41 & V_123 ) {
F_1 ( V_2 , & V_4 ) ;
F_51 ( & V_2 -> V_16 , L_12 ) ;
F_51 ( & V_2 -> V_16 ,
L_13
L_14 ,
V_4 . V_29 + 1900 ,
V_4 . V_27 + 1 , V_4 . V_23 , V_4 . V_21 ,
V_4 . V_19 , V_4 . V_18 ) ;
}
V_55 = F_21 ( V_2 , V_121 ,
V_55 & ~ V_122 ) ;
}
if ( V_55 < 0 ) {
F_3 ( & V_2 -> V_16 , L_15 ) ;
return V_55 ;
}
V_55 = F_11 ( V_2 , V_8 ) ;
if ( V_55 >= 0 && V_55 & V_124 )
V_55 = F_21 ( V_2 , V_8 ,
V_55 & ~ V_124 ) ;
if ( V_55 < 0 ) {
F_3 ( & V_2 -> V_16 , L_16 ) ;
return V_55 ;
}
V_55 = F_22 ( & V_2 -> V_16 ) ;
if ( V_55 )
return V_55 ;
#ifdef F_52
if ( V_39 -> V_41 & V_123 ) {
V_62 = V_2 ;
V_55 = F_53 ( & V_125 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_54 ( & V_126 ) ;
if ( V_55 ) {
F_55 ( & V_125 ) ;
return V_55 ;
}
}
#endif
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
#ifdef F_52
struct V_38 * V_39 = F_10 ( V_2 ) ;
if ( V_39 -> V_41 & V_123 ) {
F_55 ( & V_125 ) ;
F_57 ( & V_126 ) ;
}
#endif
return 0 ;
}
