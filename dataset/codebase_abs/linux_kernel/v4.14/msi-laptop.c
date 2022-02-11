static int F_1 ( int V_1 )
{
T_1 V_2 [ 2 ] ;
if ( V_1 < 0 || V_1 >= V_3 )
return - V_4 ;
V_2 [ 0 ] = 0x80 ;
V_2 [ 1 ] = ( T_1 ) ( V_1 * 31 ) ;
return F_2 ( V_5 , V_2 , sizeof( V_2 ) ,
NULL , 0 ) ;
}
static int F_3 ( void )
{
T_1 V_6 = 0 , V_7 ;
int V_8 ;
V_8 = F_2 ( V_5 , & V_6 , 1 ,
& V_7 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
return ( int ) V_7 / 31 ;
}
static int F_4 ( void )
{
T_1 V_6 = 4 , V_7 ;
int V_8 ;
V_8 = F_2 ( V_5 , & V_6 , 1 ,
& V_7 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
return ! ! ( V_7 & 8 ) ;
}
static int F_5 ( int V_9 )
{
T_1 V_6 [ 2 ] , V_7 ;
int V_8 ;
V_6 [ 0 ] = 4 ;
V_8 = F_2 ( V_5 , V_6 , 1 ,
& V_7 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
V_6 [ 0 ] = 0x84 ;
V_6 [ 1 ] = ( V_7 & 0xF7 ) | ( V_9 ? 8 : 0 ) ;
return F_2 ( V_5 , V_6 , 2 ,
NULL , 0 ) ;
}
static T_2 F_6 ( const char * V_2 , T_3 V_10 , T_1 V_11 )
{
int V_12 ;
T_1 V_6 = 0 , V_7 ;
int V_8 ;
if ( sscanf ( V_2 , L_1 , & V_12 ) != 1 || ( V_12 < 0 || V_12 > 1 ) )
return - V_4 ;
if ( V_13 -> V_14 )
return - V_15 ;
V_8 = F_7 ( V_16 , & V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( ! ! ( V_7 & V_11 ) != V_12 ) {
if ( V_7 & V_11 )
V_6 = V_7 & ~ V_11 ;
else
V_6 = V_7 | V_11 ;
V_8 = F_8 ( V_16 , V_6 ) ;
if ( V_8 < 0 )
return V_8 ;
}
return V_10 ;
}
static int F_9 ( int * V_17 , int * V_18 )
{
T_1 V_6 = 0 , V_7 ;
int V_8 ;
V_8 = F_2 ( V_19 , & V_6 , 1 , & V_7 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_17 )
* V_17 = ! ! ( V_7 & 8 ) ;
if ( V_18 )
* V_18 = ! ! ( V_7 & 128 ) ;
return 0 ;
}
static int F_10 ( void )
{
T_1 V_7 ;
int V_8 ;
V_8 = F_7 ( V_16 , & V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
V_20 = ! ! ( V_7 & V_21 ) ;
V_22 = ! ! ( V_7 & V_23 ) ;
V_24 = ! ! ( V_7 & V_25 ) ;
return 0 ;
}
static int F_11 ( void )
{
T_1 V_7 ;
int V_8 ;
V_8 = F_7 ( V_26 , & V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
V_27 = ! ! ( V_7 & V_25 ) ;
return 0 ;
}
static int F_12 ( struct V_28 * V_29 )
{
return F_3 () ;
}
static int F_13 ( struct V_28 * V_29 )
{
return F_1 ( V_29 -> V_30 . V_31 ) ;
}
static T_2 F_14 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_2 )
{
int V_36 , V_37 = 0 ;
if ( V_13 -> V_38 ) {
V_36 = F_9 ( & V_37 , NULL ) ;
} else {
V_36 = F_10 () ;
V_37 = V_20 ;
}
if ( V_36 < 0 )
return V_36 ;
return sprintf ( V_2 , L_2 , V_37 ) ;
}
static T_2 F_15 ( struct V_32 * V_33 ,
struct V_34 * V_35 , const char * V_2 , T_3 V_10 )
{
return F_6 ( V_2 , V_10 , V_21 ) ;
}
static T_2 F_16 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_2 )
{
int V_36 , V_37 = 0 ;
if ( V_13 -> V_38 ) {
V_36 = F_9 ( NULL , & V_37 ) ;
} else {
V_36 = F_10 () ;
V_37 = V_22 ;
}
if ( V_36 < 0 )
return V_36 ;
return sprintf ( V_2 , L_2 , V_37 ) ;
}
static T_2 F_17 ( struct V_32 * V_33 ,
struct V_34 * V_35 , const char * V_2 , T_3 V_10 )
{
return F_6 ( V_2 , V_10 , V_23 ) ;
}
static T_2 F_18 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_2 )
{
int V_36 ;
if ( V_13 -> V_38 )
return - V_39 ;
V_36 = F_10 () ;
if ( V_36 < 0 )
return V_36 ;
return sprintf ( V_2 , L_2 , V_24 ) ;
}
static T_2 F_19 ( struct V_32 * V_33 ,
struct V_34 * V_35 , const char * V_2 , T_3 V_10 )
{
return F_6 ( V_2 , V_10 , V_25 ) ;
}
static T_2 F_20 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_2 )
{
int V_36 ;
V_36 = F_3 () ;
if ( V_36 < 0 )
return V_36 ;
return sprintf ( V_2 , L_2 , V_36 ) ;
}
static T_2 F_21 ( struct V_32 * V_33 ,
struct V_34 * V_35 , const char * V_2 , T_3 V_10 )
{
int V_1 , V_36 ;
if ( sscanf ( V_2 , L_1 , & V_1 ) != 1 ||
( V_1 < 0 || V_1 >= V_3 ) )
return - V_4 ;
V_36 = F_1 ( V_1 ) ;
if ( V_36 < 0 )
return V_36 ;
return V_10 ;
}
static T_2 F_22 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_2 )
{
int V_36 ;
V_36 = F_4 () ;
if ( V_36 < 0 )
return V_36 ;
return sprintf ( V_2 , L_2 , V_36 ) ;
}
static T_2 F_23 ( struct V_32 * V_33 ,
struct V_34 * V_35 , const char * V_2 , T_3 V_10 )
{
int V_9 , V_36 ;
if ( sscanf ( V_2 , L_1 , & V_9 ) != 1 || ( V_9 != ( V_9 & 1 ) ) )
return - V_4 ;
V_36 = F_5 ( V_9 ) ;
if ( V_36 < 0 )
return V_36 ;
return V_10 ;
}
static T_2 F_24 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_2 )
{
T_1 V_7 ;
int V_8 ;
V_8 = F_7 ( V_40 , & V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
return sprintf ( V_2 , L_2 , ! ! ( V_7 & V_41 ) ) ;
}
static T_2 F_25 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_2 )
{
T_1 V_7 ;
int V_8 ;
V_8 = F_7 ( V_40 , & V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
return sprintf ( V_2 , L_2 , ! ! ( V_7 & V_42 ) ) ;
}
static T_2 F_26 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_2 )
{
T_1 V_7 ;
int V_8 ;
V_8 = F_7 ( V_40 , & V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
return sprintf ( V_2 , L_2 , ! ! ( V_7 & V_43 ) ) ;
}
static T_2 F_27 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_2 )
{
T_1 V_7 ;
int V_8 ;
V_8 = F_7 ( V_40 , & V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
return sprintf ( V_2 , L_2 , ( ! ! ( V_7 & V_42 ) ) |
( ! ! ( V_7 & V_44 ) << 1 ) ) ;
}
static T_2 F_28 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_2 )
{
T_1 V_7 ;
int V_8 ;
V_8 = F_7 ( V_45 , & V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
return sprintf ( V_2 , L_2 , ! ! ( V_7 & V_46 ) ) ;
}
static T_2 F_29 ( struct V_32 * V_33 ,
struct V_34 * V_35 , const char * V_2 , T_3 V_10 )
{
int V_9 , V_8 ;
if ( sscanf ( V_2 , L_1 , & V_9 ) != 1 || ( V_9 != ( V_9 & 1 ) ) )
return - V_4 ;
V_8 = F_8 ( V_45 , V_9 ) ;
if ( V_8 < 0 )
return V_8 ;
return V_10 ;
}
static int F_30 ( const struct V_47 * V_48 )
{
F_31 ( L_3 , V_48 -> V_49 ) ;
V_13 = V_48 -> V_50 ;
return 1 ;
}
static int F_32 ( void * V_51 , bool V_52 )
{
int V_8 = F_6 ( V_52 ? L_4 : L_5 , 0 ,
V_23 ) ;
return F_33 ( V_8 , 0 ) ;
}
static int F_34 ( void * V_51 , bool V_52 )
{
int V_8 = F_6 ( V_52 ? L_4 : L_5 , 0 ,
V_21 ) ;
return F_33 ( V_8 , 0 ) ;
}
static int F_35 ( void * V_51 , bool V_52 )
{
int V_8 = F_6 ( V_52 ? L_4 : L_5 , 0 ,
V_25 ) ;
return F_33 ( V_8 , 0 ) ;
}
static void F_36 ( void )
{
if ( V_53 ) {
F_37 ( V_53 ) ;
F_38 ( V_53 ) ;
}
if ( V_54 ) {
F_37 ( V_54 ) ;
F_38 ( V_54 ) ;
}
if ( V_55 ) {
F_37 ( V_55 ) ;
F_38 ( V_55 ) ;
}
}
static bool F_39 ( struct V_56 * V_56 , bool V_52 )
{
if ( V_13 -> V_14 )
return F_40 ( V_56 , V_52 ) ;
else
return F_41 ( V_56 , V_52 ) ;
}
static void F_42 ( struct V_57 * V_58 )
{
F_10 () ;
if ( V_55 )
F_39 ( V_55 , ! V_20 ) ;
if ( V_53 )
F_39 ( V_53 , ! V_22 ) ;
if ( V_54 )
F_39 ( V_54 , ! V_24 ) ;
}
static void F_43 ( struct V_57 * V_58 )
{
T_1 V_7 ;
int V_8 ;
V_8 = F_7 ( V_40 , & V_7 ) ;
if ( V_8 < 0 )
return;
F_44 ( V_59 ,
( V_7 & V_41 ) ?
V_60 : V_61 , 1 , true ) ;
}
static bool F_45 ( unsigned char V_51 , unsigned char V_62 ,
struct V_63 * V_64 )
{
static bool V_65 ;
if ( V_62 & V_66 )
return false ;
if ( F_46 ( V_51 == 0xe0 ) ) {
V_65 = true ;
return false ;
} else if ( F_46 ( V_65 ) ) {
V_65 = false ;
switch ( V_51 ) {
case 0xE4 :
if ( V_13 -> V_67 ) {
F_47 ( & V_68 ,
F_48 ( 0.5 * V_69 ) ) ;
} else
F_49 ( & V_70 ) ;
break;
case 0x54 :
case 0x62 :
case 0x76 :
if ( V_13 -> V_67 ) {
F_47 ( & V_71 ,
F_48 ( 0.5 * V_69 ) ) ;
} else
F_49 ( & V_72 ) ;
break;
}
}
return false ;
}
static void F_50 ( struct V_57 * V_58 )
{
if ( V_55 ) {
F_41 ( V_55 , ! V_20 ) ;
F_34 ( NULL , ! V_20 ) ;
}
if ( V_53 ) {
F_41 ( V_53 , ! V_22 ) ;
F_32 ( NULL , ! V_22 ) ;
}
if ( V_54 ) {
F_41 ( V_54 , ! V_24 ) ;
F_35 ( NULL , ! V_24 ) ;
}
}
static int F_51 ( struct V_73 * V_74 )
{
int V_75 ;
F_10 () ;
V_53 = F_52 ( L_6 , & V_74 -> V_33 ,
V_76 ,
& V_77 , NULL ) ;
if ( ! V_53 ) {
V_75 = - V_78 ;
goto V_79;
}
V_75 = F_53 ( V_53 ) ;
if ( V_75 )
goto V_79;
V_55 = F_52 ( L_7 , & V_74 -> V_33 , V_80 ,
& V_81 , NULL ) ;
if ( ! V_55 ) {
V_75 = - V_78 ;
goto V_82;
}
V_75 = F_53 ( V_55 ) ;
if ( V_75 )
goto V_82;
if ( V_27 ) {
V_54 = F_52 ( L_8 , & V_74 -> V_33 ,
V_83 , & V_84 , NULL ) ;
if ( ! V_54 ) {
V_75 = - V_78 ;
goto V_85;
}
V_75 = F_53 ( V_54 ) ;
if ( V_75 )
goto V_85;
}
if ( V_13 -> V_67 ) {
F_47 ( & V_86 ,
F_48 ( 1 * V_69 ) ) ;
} else
F_49 ( & V_72 ) ;
return 0 ;
V_85:
F_38 ( V_54 ) ;
if ( V_55 )
F_37 ( V_55 ) ;
V_82:
F_38 ( V_55 ) ;
if ( V_53 )
F_37 ( V_53 ) ;
V_79:
F_38 ( V_53 ) ;
return V_75 ;
}
static int F_54 ( struct V_32 * V_32 )
{
T_1 V_51 ;
int V_8 ;
if ( ! V_13 -> V_87 )
return 0 ;
V_8 = F_7 ( V_88 , & V_51 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_8 ( V_88 ,
V_51 | V_89 ) ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
}
static int T_4 F_55 ( void )
{
int V_90 ;
V_59 = F_56 () ;
if ( ! V_59 )
return - V_78 ;
V_59 -> V_91 = L_9 ;
V_59 -> V_92 = L_10 ;
V_59 -> V_93 . V_94 = V_95 ;
V_90 = F_57 ( V_59 ,
V_96 , NULL ) ;
if ( V_90 )
goto V_97;
V_90 = F_58 ( V_59 ) ;
if ( V_90 )
goto V_97;
return 0 ;
V_97:
F_59 ( V_59 ) ;
return V_90 ;
}
static int T_4 F_60 ( struct V_73 * V_74 )
{
T_1 V_51 ;
int V_8 ;
if ( ! V_13 -> V_14 ) {
V_98 . V_99 = F_17 ;
V_100 . V_99 = F_15 ;
V_101 . V_99 = F_19 ;
V_98 . V_35 . V_102 |= V_103 ;
V_100 . V_35 . V_102 |= V_103 ;
V_101 . V_35 . V_102 |= V_103 ;
}
V_8 = F_7 ( V_88 , & V_51 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_8 ( V_88 ,
V_51 | V_89 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_51 ( V_74 ) ;
if ( V_8 < 0 )
goto V_104;
V_8 = F_55 () ;
if ( V_8 )
goto V_105;
V_8 = F_61 ( F_45 ) ;
if ( V_8 ) {
F_62 ( L_11 ) ;
goto V_106;
}
return 0 ;
V_106:
F_63 ( V_59 ) ;
V_105:
F_36 () ;
V_104:
return V_8 ;
}
static int T_4 F_64 ( void )
{
int V_36 ;
if ( V_107 )
return - V_39 ;
F_65 ( V_108 ) ;
if ( ! V_13 )
V_13 = & V_109 ;
if ( V_110 )
V_13 = & V_111 ;
if ( ! V_13 -> V_38 )
F_11 () ;
if ( V_112 < 0 || V_112 > 2 )
return - V_4 ;
if ( V_13 -> V_38 ||
F_66 () == V_113 ) {
struct V_114 V_30 ;
memset ( & V_30 , 0 , sizeof( struct V_114 ) ) ;
V_30 . type = V_115 ;
V_30 . V_116 = V_3 - 1 ;
V_117 = F_67 ( L_12 , NULL ,
NULL , & V_118 ,
& V_30 ) ;
if ( F_68 ( V_117 ) )
return F_69 ( V_117 ) ;
}
V_36 = F_70 ( & V_119 ) ;
if ( V_36 )
goto V_120;
V_121 = F_71 ( L_13 , - 1 ) ;
if ( ! V_121 ) {
V_36 = - V_78 ;
goto V_122;
}
V_36 = F_72 ( V_121 ) ;
if ( V_36 )
goto V_123;
if ( V_13 -> V_87 && ( F_60 ( V_121 ) < 0 ) ) {
V_36 = - V_4 ;
goto V_124;
}
V_36 = F_73 ( & V_121 -> V_33 . V_125 ,
& V_126 ) ;
if ( V_36 )
goto V_127;
if ( ! V_13 -> V_38 ) {
if ( V_27 )
V_36 = F_74 ( & V_121 -> V_33 ,
& V_101 ) ;
if ( V_36 )
goto V_128;
} else {
V_36 = F_73 ( & V_121 -> V_33 . V_125 ,
& V_129 ) ;
if ( V_36 )
goto V_128;
if ( V_112 != 2 )
F_5 ( V_112 ) ;
}
F_31 ( L_14 V_130 L_15 ) ;
return 0 ;
V_128:
F_75 ( & V_121 -> V_33 . V_125 , & V_126 ) ;
V_127:
if ( V_13 -> V_87 ) {
F_76 ( F_45 ) ;
F_77 ( & V_71 ) ;
F_78 ( & V_72 ) ;
F_36 () ;
}
V_124:
F_79 ( V_121 ) ;
V_123:
F_80 ( V_121 ) ;
V_122:
F_81 ( & V_119 ) ;
V_120:
F_82 ( V_117 ) ;
return V_36 ;
}
static void T_5 F_83 ( void )
{
if ( V_13 -> V_87 ) {
F_76 ( F_45 ) ;
F_63 ( V_59 ) ;
F_77 ( & V_71 ) ;
F_78 ( & V_72 ) ;
F_36 () ;
}
F_75 ( & V_121 -> V_33 . V_125 , & V_126 ) ;
if ( ! V_13 -> V_38 && V_27 )
F_84 ( & V_121 -> V_33 , & V_101 ) ;
F_85 ( V_121 ) ;
F_81 ( & V_119 ) ;
F_82 ( V_117 ) ;
if ( V_13 -> V_38 ) {
if ( V_112 != 2 )
F_5 ( 1 ) ;
}
F_31 ( L_16 ) ;
}
