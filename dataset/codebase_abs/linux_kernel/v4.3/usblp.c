static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = & V_1 -> V_4 -> V_3 ;
int V_5 ;
F_2 ( V_3 , L_1 , V_1 ) ;
F_2 ( V_3 , L_2 , V_1 -> V_3 ) ;
F_2 ( V_3 , L_3 , V_1 -> V_6 ) ;
F_2 ( V_3 , L_4 , V_1 -> V_7 ) ;
F_2 ( V_3 , L_5 , V_1 -> V_8 ) ;
F_2 ( V_3 , L_6 , V_1 -> V_9 ) ;
for ( V_5 = V_10 ; V_5 <= V_11 ; V_5 ++ ) {
F_2 ( V_3 , L_7 , V_5 ,
V_1 -> V_12 [ V_5 ] . V_13 ) ;
F_2 ( V_3 , L_8 , V_5 ,
V_1 -> V_12 [ V_5 ] . V_14 ) ;
F_2 ( V_3 , L_9 , V_5 ,
V_1 -> V_12 [ V_5 ] . V_15 ) ;
}
F_2 ( V_3 , L_10 , V_1 -> V_16 ) ;
F_2 ( V_3 , L_11 , V_1 -> V_17 ) ;
F_2 ( V_3 , L_12 , V_1 -> V_18 ) ;
F_2 ( V_3 , L_13 , V_1 -> V_19 ) ;
F_2 ( V_3 , L_14 , V_1 -> V_20 ) ;
F_2 ( V_3 , L_15 , V_1 -> V_21 ) ;
F_2 ( V_3 , L_16 , V_1 -> V_22 ) ;
F_2 ( V_3 , L_17 ,
V_1 -> V_23 ?
V_1 -> V_23 + 2 :
( unsigned char * ) L_18 ) ;
}
static int F_3 ( struct V_1 * V_1 , int V_24 , int type , int V_25 , int V_26 , int V_27 , void * V_28 , int V_29 )
{
int V_30 ;
int V_31 = V_1 -> V_9 ;
if ( ( V_24 == V_32 ) && ( type == V_33 ) )
V_31 = ( V_1 -> V_9 << 8 ) | V_1 -> V_12 [ V_1 -> V_16 ] . V_13 ;
V_30 = F_4 ( V_1 -> V_3 ,
V_25 ? F_5 ( V_1 -> V_3 , 0 ) : F_6 ( V_1 -> V_3 , 0 ) ,
V_24 , type | V_25 | V_26 , V_27 , V_31 , V_28 , V_29 , V_34 ) ;
F_2 ( & V_1 -> V_4 -> V_3 ,
L_19 ,
V_24 , ! ! V_25 , V_26 , V_27 , V_31 , V_29 , V_30 ) ;
return V_30 < 0 ? V_30 : 0 ;
}
static void F_7 ( struct V_35 * V_35 )
{
struct V_1 * V_1 = V_35 -> V_36 ;
int V_37 = V_35 -> V_37 ;
if ( V_1 -> V_6 && V_1 -> V_21 ) {
if ( V_37 )
F_8 ( V_38 L_20
L_21 ,
V_1 -> V_17 , V_37 ) ;
}
F_9 ( & V_1 -> V_39 ) ;
if ( V_37 < 0 )
V_1 -> V_19 = V_37 ;
else
V_1 -> V_19 = V_35 -> V_40 ;
V_1 -> V_41 = 1 ;
F_10 ( & V_1 -> V_42 ) ;
F_11 ( & V_1 -> V_39 ) ;
F_12 ( V_35 ) ;
}
static void F_13 ( struct V_35 * V_35 )
{
struct V_1 * V_1 = V_35 -> V_36 ;
int V_37 = V_35 -> V_37 ;
if ( V_1 -> V_6 && V_1 -> V_21 ) {
if ( V_37 )
F_8 ( V_38 L_20
L_22 ,
V_1 -> V_17 , V_37 ) ;
}
F_9 ( & V_1 -> V_39 ) ;
if ( V_37 < 0 )
V_1 -> V_18 = V_37 ;
else
V_1 -> V_18 = V_35 -> V_40 ;
V_1 -> V_43 = 0 ;
V_1 -> V_44 = 1 ;
F_10 ( & V_1 -> V_45 ) ;
F_11 ( & V_1 -> V_39 ) ;
F_12 ( V_35 ) ;
}
static int F_14 ( struct V_1 * V_1 , int V_46 )
{
unsigned char V_37 , V_47 = 0 ;
int error ;
F_15 ( & V_1 -> V_48 ) ;
if ( ( error = F_16 ( V_1 , V_1 -> V_49 ) ) < 0 ) {
F_17 ( & V_1 -> V_48 ) ;
F_18 ( V_50
L_23 ,
V_1 -> V_17 , error ) ;
return 0 ;
}
V_37 = * V_1 -> V_49 ;
F_17 ( & V_1 -> V_48 ) ;
if ( ~ V_37 & V_51 )
V_47 = 3 ;
if ( V_37 & V_52 )
V_47 = 1 ;
if ( ~ V_37 & V_53 )
V_47 = 2 ;
if ( V_47 != V_46 ) {
F_8 ( V_54 L_24 ,
V_1 -> V_17 , V_55 [ V_47 ] ) ;
}
return V_47 ;
}
static int F_19 ( struct V_1 * V_1 )
{
if ( V_1 -> V_22 && V_1 -> V_21 ) {
if ( F_20 ( V_1 ) < 0 )
return - V_56 ;
}
return 0 ;
}
static int F_21 ( struct V_57 * V_57 , struct V_58 * V_58 )
{
int V_17 = F_22 ( V_57 ) ;
struct V_1 * V_1 ;
struct V_59 * V_4 ;
int V_30 ;
if ( V_17 < 0 )
return - V_60 ;
F_15 ( & V_61 ) ;
V_30 = - V_60 ;
V_4 = F_23 ( & V_62 , V_17 ) ;
if ( ! V_4 )
goto V_63;
V_1 = F_24 ( V_4 ) ;
if ( ! V_1 || ! V_1 -> V_3 || ! V_1 -> V_6 )
goto V_63;
V_30 = - V_64 ;
if ( V_1 -> V_21 )
goto V_63;
V_30 = F_25 ( V_4 ) ;
if ( V_30 < 0 )
goto V_63;
V_1 -> V_21 = 1 ;
V_58 -> V_65 = V_1 ;
V_1 -> V_44 = 1 ;
V_1 -> V_18 = 0 ;
V_1 -> V_41 = 0 ;
if ( F_19 ( V_1 ) < 0 ) {
F_26 ( V_4 ) ;
V_1 -> V_21 = 0 ;
V_58 -> V_65 = NULL ;
V_30 = - V_56 ;
}
V_63:
F_17 ( & V_61 ) ;
return V_30 ;
}
static void F_27 ( struct V_1 * V_1 )
{
F_8 ( V_54 L_25 , V_1 -> V_17 ) ;
F_28 ( V_1 -> V_7 ) ;
F_28 ( V_1 -> V_23 ) ;
F_28 ( V_1 -> V_49 ) ;
F_28 ( V_1 ) ;
}
static void F_29 ( struct V_1 * V_1 )
{
F_30 ( & V_1 -> V_66 ) ;
}
static int F_31 ( struct V_57 * V_57 , struct V_58 * V_58 )
{
struct V_1 * V_1 = V_58 -> V_65 ;
V_1 -> V_67 &= ~ V_68 ;
F_15 ( & V_61 ) ;
V_1 -> V_21 = 0 ;
if ( V_1 -> V_6 ) {
F_29 ( V_1 ) ;
F_26 ( V_1 -> V_4 ) ;
} else
F_27 ( V_1 ) ;
F_17 ( & V_61 ) ;
return 0 ;
}
static unsigned int F_32 ( struct V_58 * V_58 , struct V_69 * V_70 )
{
int V_71 ;
unsigned long V_67 ;
struct V_1 * V_1 = V_58 -> V_65 ;
F_33 ( V_58 , & V_1 -> V_42 , V_70 ) ;
F_33 ( V_58 , & V_1 -> V_45 , V_70 ) ;
F_34 ( & V_1 -> V_39 , V_67 ) ;
V_71 = ( ( V_1 -> V_22 && V_1 -> V_41 ) ? V_72 | V_73 : 0 ) |
( ( V_1 -> V_43 || V_1 -> V_44 ) ? V_74 | V_75 : 0 ) ;
F_35 ( & V_1 -> V_39 , V_67 ) ;
return V_71 ;
}
static long F_36 ( struct V_58 * V_58 , unsigned int V_76 , unsigned long V_77 )
{
struct V_1 * V_1 = V_58 -> V_65 ;
int V_78 , V_46 , V_79 ;
unsigned char V_80 ;
int V_37 ;
int V_81 [ 2 ] ;
int V_30 = 0 ;
F_15 ( & V_1 -> V_48 ) ;
if ( ! V_1 -> V_6 ) {
V_30 = - V_60 ;
goto V_82;
}
F_2 ( & V_1 -> V_4 -> V_3 ,
L_26 , V_76 ,
F_37 ( V_76 ) , F_38 ( V_76 ) , F_39 ( V_76 ) , F_40 ( V_76 ) ) ;
if ( F_37 ( V_76 ) == 'P' )
switch ( F_38 ( V_76 ) ) {
case V_83 :
if ( F_40 ( V_76 ) != V_84 ) {
V_30 = - V_85 ;
goto V_82;
}
V_78 = F_41 ( V_1 ) ;
if ( V_78 < 0 ) {
V_30 = V_78 ;
goto V_82;
}
if ( V_78 > F_39 ( V_76 ) )
V_78 = F_39 ( V_76 ) ;
if ( F_42 ( ( void V_86 * ) V_77 ,
V_1 -> V_23 ,
( unsigned long ) V_78 ) ) {
V_30 = - V_87 ;
goto V_82;
}
break;
case V_88 :
if ( F_40 ( V_76 ) != V_84 ||
F_39 ( V_76 ) < sizeof( V_81 ) ) {
V_30 = - V_85 ;
goto V_82;
}
V_81 [ 0 ] = V_1 -> V_16 ;
V_81 [ 1 ] = 0 ;
for ( V_79 = V_10 ;
V_79 <= V_11 ; V_79 ++ ) {
if ( V_1 -> V_12 [ V_79 ] . V_13 >= 0 )
V_81 [ 1 ] |= ( 1 << V_79 ) ;
}
if ( F_42 ( ( void V_86 * ) V_77 ,
( unsigned char * ) V_81 ,
sizeof( V_81 ) ) ) {
V_30 = - V_87 ;
goto V_82;
}
break;
case V_89 :
if ( F_40 ( V_76 ) != V_90 ) {
V_30 = - V_85 ;
goto V_82;
}
#ifdef F_43
if ( V_77 == - 10 ) {
F_1 ( V_1 ) ;
break;
}
#endif
F_29 ( V_1 ) ;
V_30 = F_44 ( V_1 , V_77 ) ;
if ( V_30 < 0 ) {
F_44 ( V_1 ,
V_1 -> V_16 ) ;
}
break;
case V_91 :
if ( F_40 ( V_76 ) != V_90 ||
F_45 ( V_1 -> V_3 -> V_92 . V_93 ) != 0x03F0 ||
V_1 -> V_20 & V_94 ) {
V_30 = - V_85 ;
goto V_82;
}
V_46 = F_46 ( V_1 ,
V_77 , & V_80 ) ;
if ( V_46 < 0 ) {
F_47 ( & V_1 -> V_3 -> V_3 ,
L_27
L_28 ,
V_1 -> V_17 , V_46 ) ;
V_30 = - V_56 ;
goto V_82;
}
F_2 ( & V_1 -> V_4 -> V_3 ,
L_29 ,
V_1 -> V_17 , V_77 , V_80 ) ;
break;
case V_95 :
if ( F_40 ( V_76 ) != V_84 ||
F_39 ( V_76 ) < sizeof( V_81 ) ) {
V_30 = - V_85 ;
goto V_82;
}
V_81 [ 0 ] = V_1 -> V_3 -> V_96 -> V_97 ;
V_81 [ 1 ] = V_1 -> V_3 -> V_98 ;
if ( F_42 ( ( void V_86 * ) V_77 ,
( unsigned char * ) V_81 ,
sizeof( V_81 ) ) ) {
V_30 = - V_87 ;
goto V_82;
}
F_2 ( & V_1 -> V_4 -> V_3 ,
L_30 ,
V_1 -> V_17 , V_81 [ 0 ] , V_81 [ 1 ] ) ;
break;
case V_99 :
if ( F_40 ( V_76 ) != V_84 ||
F_39 ( V_76 ) < sizeof( V_81 ) ) {
V_30 = - V_85 ;
goto V_82;
}
V_81 [ 0 ] = F_45 ( V_1 -> V_3 -> V_92 . V_93 ) ;
V_81 [ 1 ] = F_45 ( V_1 -> V_3 -> V_92 . V_100 ) ;
if ( F_42 ( ( void V_86 * ) V_77 ,
( unsigned char * ) V_81 ,
sizeof( V_81 ) ) ) {
V_30 = - V_87 ;
goto V_82;
}
F_2 ( & V_1 -> V_4 -> V_3 ,
L_31 ,
V_1 -> V_17 , V_81 [ 0 ] , V_81 [ 1 ] ) ;
break;
case V_101 :
if ( F_40 ( V_76 ) != V_102 ) {
V_30 = - V_85 ;
goto V_82;
}
V_30 = F_48 ( V_1 ) ;
break;
default:
V_30 = - V_103 ;
}
else
switch ( V_76 ) {
case V_104 :
V_30 = F_16 ( V_1 , V_1 -> V_49 ) ;
if ( V_30 ) {
F_18 ( V_50 L_32
L_33 ,
V_1 -> V_17 , V_30 ) ;
V_30 = - V_56 ;
goto V_82;
}
V_37 = * V_1 -> V_49 ;
if ( F_42 ( ( void V_86 * ) V_77 , & V_37 , sizeof( int ) ) )
V_30 = - V_87 ;
break;
case V_105 :
if ( V_77 )
V_1 -> V_67 |= V_68 ;
else
V_1 -> V_67 &= ~ V_68 ;
break;
default:
V_30 = - V_103 ;
}
V_82:
F_17 ( & V_1 -> V_48 ) ;
return V_30 ;
}
static struct V_35 * F_49 ( struct V_1 * V_1 , int V_106 )
{
struct V_35 * V_35 ;
char * V_107 ;
V_107 = F_50 ( V_106 , V_108 ) ;
if ( V_107 == NULL )
return NULL ;
V_35 = F_51 ( 0 , V_108 ) ;
if ( V_35 == NULL ) {
F_28 ( V_107 ) ;
return NULL ;
}
F_52 ( V_35 , V_1 -> V_3 ,
F_53 ( V_1 -> V_3 ,
V_1 -> V_12 [ V_1 -> V_16 ] . V_14 -> V_109 ) ,
V_107 , V_106 , F_13 , V_1 ) ;
V_35 -> V_110 |= V_111 ;
return V_35 ;
}
static T_1 F_54 ( struct V_58 * V_58 , const char V_86 * V_112 , T_2 V_113 , T_3 * V_114 )
{
struct V_1 * V_1 = V_58 -> V_65 ;
struct V_35 * V_115 ;
int V_116 ;
int V_106 ;
T_1 V_117 = 0 ;
if ( F_55 ( & V_1 -> V_118 ) ) {
V_116 = - V_119 ;
goto V_120;
}
if ( ( V_116 = F_56 ( V_1 , ! ! ( V_58 -> V_121 & V_122 ) ) ) < 0 )
goto V_123;
while ( V_117 < V_113 ) {
if ( ( V_106 = V_113 - V_117 ) > V_124 )
V_106 = V_124 ;
V_116 = - V_125 ;
V_115 = F_49 ( V_1 , V_106 ) ;
if ( V_115 == NULL )
goto V_126;
F_57 ( V_115 , & V_1 -> V_66 ) ;
if ( F_58 ( V_115 -> V_127 ,
V_112 + V_117 , V_106 ) ) {
V_116 = - V_87 ;
goto V_128;
}
F_59 ( & V_1 -> V_39 ) ;
V_1 -> V_44 = 0 ;
F_60 ( & V_1 -> V_39 ) ;
if ( ( V_116 = F_61 ( V_115 , V_108 ) ) < 0 ) {
V_1 -> V_18 = 0 ;
F_59 ( & V_1 -> V_39 ) ;
V_1 -> V_43 = 0 ;
V_1 -> V_44 = 1 ;
F_10 ( & V_1 -> V_45 ) ;
F_60 ( & V_1 -> V_39 ) ;
if ( V_116 != - V_125 )
V_116 = - V_56 ;
goto V_129;
}
V_116 = F_56 ( V_1 , ! ! ( V_58 -> V_121 & V_122 ) ) ;
if ( V_116 < 0 ) {
if ( V_116 == - V_130 ) {
V_117 += V_106 ;
}
if ( V_116 == - V_131 ) {
F_59 ( & V_1 -> V_39 ) ;
V_1 -> V_43 = 1 ;
F_60 ( & V_1 -> V_39 ) ;
V_117 += V_106 ;
}
goto V_132;
}
if ( V_1 -> V_18 < 0 ) {
V_116 = - V_56 ;
goto V_132;
}
V_117 += V_1 -> V_18 ;
}
F_17 ( & V_1 -> V_118 ) ;
return V_117 ;
V_129:
V_128:
F_62 ( V_115 ) ;
F_12 ( V_115 ) ;
V_126:
V_123:
V_132:
F_17 ( & V_1 -> V_118 ) ;
V_120:
return V_117 ? V_117 : V_116 ;
}
static T_1 F_63 ( struct V_58 * V_58 , char V_86 * V_112 , T_2 V_29 , T_3 * V_114 )
{
struct V_1 * V_1 = V_58 -> V_65 ;
T_1 V_113 ;
T_1 V_133 ;
int V_116 ;
if ( ! V_1 -> V_22 )
return - V_85 ;
V_116 = F_64 ( V_1 , ! ! ( V_58 -> V_121 & V_122 ) ) ;
if ( V_116 < 0 )
return V_116 ;
if ( ( V_133 = V_1 -> V_19 ) < 0 ) {
F_8 ( V_50 L_34 ,
V_1 -> V_17 , ( int ) V_133 ) ;
F_20 ( V_1 ) ;
V_113 = - V_56 ;
goto V_82;
}
V_113 = V_29 < V_133 - V_1 -> V_8 ? V_29 : V_133 - V_1 -> V_8 ;
if ( V_113 != 0 &&
F_42 ( V_112 , V_1 -> V_7 + V_1 -> V_8 , V_113 ) ) {
V_113 = - V_87 ;
goto V_82;
}
if ( ( V_1 -> V_8 += V_113 ) == V_133 ) {
if ( F_20 ( V_1 ) < 0 ) {
if ( V_113 == 0 )
V_113 = - V_56 ;
goto V_82;
}
}
V_82:
F_17 ( & V_1 -> V_48 ) ;
return V_113 ;
}
static int F_56 ( struct V_1 * V_1 , int V_134 )
{
F_65 ( V_135 , V_136 ) ;
int V_137 ;
int V_46 = 0 ;
F_66 ( & V_1 -> V_45 , & V_135 ) ;
for (; ; ) {
F_67 ( V_138 ) ;
if ( F_55 ( & V_1 -> V_48 ) ) {
V_137 = - V_119 ;
break;
}
V_137 = F_68 ( V_1 , V_134 ) ;
F_17 ( & V_1 -> V_48 ) ;
if ( V_137 <= 0 )
break;
if ( F_69 ( F_70 ( 1500 ) ) == 0 ) {
if ( V_1 -> V_67 & V_68 ) {
V_46 = F_14 ( V_1 , V_46 ) ;
if ( V_46 == 1 ) {
V_137 = - V_131 ;
break;
}
} else {
F_15 ( & V_1 -> V_48 ) ;
F_16 ( V_1 , V_1 -> V_49 ) ;
F_17 ( & V_1 -> V_48 ) ;
}
}
}
F_67 ( V_139 ) ;
F_71 ( & V_1 -> V_45 , & V_135 ) ;
return V_137 ;
}
static int F_68 ( struct V_1 * V_1 , int V_134 )
{
unsigned long V_67 ;
if ( ! V_1 -> V_6 )
return - V_60 ;
if ( F_72 ( V_136 ) )
return - V_119 ;
F_34 ( & V_1 -> V_39 , V_67 ) ;
if ( V_1 -> V_44 ) {
F_35 ( & V_1 -> V_39 , V_67 ) ;
return 0 ;
}
F_35 ( & V_1 -> V_39 , V_67 ) ;
if ( V_134 )
return - V_130 ;
return 1 ;
}
static int F_64 ( struct V_1 * V_1 , int V_134 )
{
F_65 ( V_135 , V_136 ) ;
int V_137 ;
F_66 ( & V_1 -> V_42 , & V_135 ) ;
for (; ; ) {
if ( F_55 ( & V_1 -> V_48 ) ) {
V_137 = - V_119 ;
break;
}
F_67 ( V_138 ) ;
if ( ( V_137 = F_73 ( V_1 , V_134 ) ) < 0 ) {
F_17 ( & V_1 -> V_48 ) ;
break;
}
if ( V_137 == 0 )
break;
F_17 ( & V_1 -> V_48 ) ;
F_74 () ;
}
F_67 ( V_139 ) ;
F_71 ( & V_1 -> V_42 , & V_135 ) ;
return V_137 ;
}
static int F_73 ( struct V_1 * V_1 , int V_134 )
{
unsigned long V_67 ;
if ( ! V_1 -> V_6 )
return - V_60 ;
if ( F_72 ( V_136 ) )
return - V_119 ;
F_34 ( & V_1 -> V_39 , V_67 ) ;
if ( V_1 -> V_41 ) {
F_35 ( & V_1 -> V_39 , V_67 ) ;
return 0 ;
}
F_35 ( & V_1 -> V_39 , V_67 ) ;
if ( V_134 )
return - V_130 ;
return 1 ;
}
static int F_20 ( struct V_1 * V_1 )
{
struct V_35 * V_35 ;
unsigned long V_67 ;
int V_137 ;
V_137 = - V_125 ;
V_35 = F_51 ( 0 , V_108 ) ;
if ( V_35 == NULL )
goto V_126;
F_52 ( V_35 , V_1 -> V_3 ,
F_75 ( V_1 -> V_3 ,
V_1 -> V_12 [ V_1 -> V_16 ] . V_15 -> V_109 ) ,
V_1 -> V_7 , V_140 ,
F_7 , V_1 ) ;
F_57 ( V_35 , & V_1 -> V_66 ) ;
F_34 ( & V_1 -> V_39 , V_67 ) ;
V_1 -> V_8 = 0 ;
V_1 -> V_41 = 0 ;
F_35 ( & V_1 -> V_39 , V_67 ) ;
if ( ( V_137 = F_61 ( V_35 , V_108 ) ) < 0 ) {
F_2 ( & V_1 -> V_4 -> V_3 , L_35 , V_137 ) ;
F_34 ( & V_1 -> V_39 , V_67 ) ;
V_1 -> V_19 = V_137 ;
V_1 -> V_41 = 1 ;
F_35 ( & V_1 -> V_39 , V_67 ) ;
goto V_129;
}
return 0 ;
V_129:
F_62 ( V_35 ) ;
F_12 ( V_35 ) ;
V_126:
return V_137 ;
}
static unsigned int F_76 ( T_4 V_141 , T_4 V_142 )
{
int V_79 ;
for ( V_79 = 0 ; V_143 [ V_79 ] . V_144 ; V_79 ++ ) {
if ( V_141 == V_143 [ V_79 ] . V_144 &&
V_142 == V_143 [ V_79 ] . V_145 )
return V_143 [ V_79 ] . V_20 ;
}
return 0 ;
}
static char * F_77 ( struct V_2 * V_3 , T_5 * V_146 )
{
return F_78 ( V_108 , L_36 , F_79 ( V_3 ) ) ;
}
static T_1 F_80 ( struct V_2 * V_3 , struct V_147 * V_148 , char * V_28 )
{
struct V_59 * V_4 = F_81 ( V_3 ) ;
struct V_1 * V_1 = F_24 ( V_4 ) ;
if ( V_1 -> V_23 [ 0 ] == 0 &&
V_1 -> V_23 [ 1 ] == 0 )
return 0 ;
return sprintf ( V_28 , L_37 , V_1 -> V_23 + 2 ) ;
}
static int F_82 ( struct V_59 * V_4 ,
const struct V_149 * V_150 )
{
struct V_151 * V_3 = F_83 ( V_4 ) ;
struct V_1 * V_1 ;
int V_12 ;
int V_30 ;
V_1 = F_84 ( sizeof( struct V_1 ) , V_108 ) ;
if ( ! V_1 ) {
V_30 = - V_125 ;
goto V_152;
}
V_1 -> V_3 = V_3 ;
F_85 ( & V_1 -> V_118 ) ;
F_85 ( & V_1 -> V_48 ) ;
F_86 ( & V_1 -> V_39 ) ;
F_87 ( & V_1 -> V_42 ) ;
F_87 ( & V_1 -> V_45 ) ;
F_88 ( & V_1 -> V_66 ) ;
V_1 -> V_9 = V_4 -> V_153 -> V_154 . V_155 ;
V_1 -> V_4 = V_4 ;
if ( ! ( V_1 -> V_23 = F_50 ( V_156 , V_108 ) ) ) {
V_30 = - V_125 ;
goto abort;
}
if ( ! ( V_1 -> V_7 = F_50 ( V_140 , V_108 ) ) ) {
V_30 = - V_125 ;
goto abort;
}
V_1 -> V_49 = F_50 ( V_157 , V_108 ) ;
if ( ! V_1 -> V_49 ) {
V_30 = - V_125 ;
goto abort;
}
V_1 -> V_20 = F_76 (
F_45 ( V_3 -> V_92 . V_93 ) ,
F_45 ( V_3 -> V_92 . V_100 ) ) ;
V_12 = F_89 ( V_1 ) ;
if ( V_12 < 0 ) {
F_2 ( & V_4 -> V_3 ,
L_38 ,
F_45 ( V_3 -> V_92 . V_93 ) ,
F_45 ( V_3 -> V_92 . V_100 ) ) ;
V_30 = - V_60 ;
goto abort;
}
if ( F_44 ( V_1 , V_12 ) < 0 ) {
V_30 = - V_60 ;
goto abort;
}
F_41 ( V_1 ) ;
V_30 = F_90 ( & V_4 -> V_3 , & V_158 ) ;
if ( V_30 )
goto V_159;
#ifdef F_43
F_14 ( V_1 , 0 ) ;
#endif
F_91 ( V_4 , V_1 ) ;
V_1 -> V_6 = 1 ;
V_30 = F_92 ( V_4 , & V_160 ) ;
if ( V_30 ) {
F_47 ( & V_4 -> V_3 ,
L_39 ,
V_161 , V_30 ) ;
goto V_159;
}
V_1 -> V_17 = V_4 -> V_17 ;
F_93 ( & V_4 -> V_3 ,
L_40 ,
V_1 -> V_17 , V_1 -> V_22 ? L_41 : L_42 , V_3 -> V_98 ,
V_1 -> V_9 ,
V_1 -> V_12 [ V_1 -> V_16 ] . V_13 ,
V_1 -> V_16 ,
F_45 ( V_1 -> V_3 -> V_92 . V_93 ) ,
F_45 ( V_1 -> V_3 -> V_92 . V_100 ) ) ;
return 0 ;
V_159:
F_91 ( V_4 , NULL ) ;
F_94 ( & V_4 -> V_3 , & V_158 ) ;
abort:
F_28 ( V_1 -> V_7 ) ;
F_28 ( V_1 -> V_49 ) ;
F_28 ( V_1 -> V_23 ) ;
F_28 ( V_1 ) ;
V_152:
return V_30 ;
}
static int F_89 ( struct V_1 * V_1 )
{
struct V_59 * V_162 ;
struct V_163 * V_164 ;
struct V_165 * V_166 , * V_14 , * V_15 ;
int V_5 , V_79 , V_167 ;
V_162 = V_1 -> V_4 ;
for ( V_5 = 0 ; V_5 < V_168 ; V_5 ++ )
V_1 -> V_12 [ V_5 ] . V_13 = - 1 ;
for ( V_79 = 0 ; V_79 < V_162 -> V_169 ; V_79 ++ ) {
V_164 = & V_162 -> V_170 [ V_79 ] ;
if ( V_164 -> V_154 . V_171 != V_172 ||
V_164 -> V_154 . V_173 != 1 )
if ( ! ( V_1 -> V_20 & V_174 ) )
continue;
if ( V_164 -> V_154 . V_175 < V_10 ||
V_164 -> V_154 . V_175 > V_11 )
continue;
V_14 = V_15 = NULL ;
for ( V_167 = 0 ; V_167 < V_164 -> V_154 . V_176 ; V_167 ++ ) {
V_166 = & V_164 -> V_177 [ V_167 ] . V_154 ;
if ( F_95 ( V_166 ) )
if ( ! V_14 )
V_14 = V_166 ;
if ( F_96 ( V_166 ) )
if ( ! V_15 )
V_15 = V_166 ;
}
if ( ! V_14 || ( V_164 -> V_154 . V_175 > 1 && ! V_15 ) )
continue;
if ( V_164 -> V_154 . V_175 == 1 ) {
V_15 = NULL ;
} else if ( V_1 -> V_20 & V_94 ) {
F_8 ( V_54 L_43
L_44 ,
V_1 -> V_17 ) ;
V_15 = NULL ;
}
V_1 -> V_12 [ V_164 -> V_154 . V_175 ] . V_13 =
V_164 -> V_154 . V_178 ;
V_1 -> V_12 [ V_164 -> V_154 . V_175 ] . V_14 = V_14 ;
V_1 -> V_12 [ V_164 -> V_154 . V_175 ] . V_15 = V_15 ;
}
if ( V_179 >= V_10 &&
V_179 <= V_11 &&
V_1 -> V_12 [ V_179 ] . V_13 != - 1 )
return V_179 ;
if ( V_1 -> V_12 [ 2 ] . V_13 != - 1 )
return 2 ;
if ( V_1 -> V_12 [ 1 ] . V_13 != - 1 )
return 1 ;
if ( V_1 -> V_12 [ 3 ] . V_13 != - 1 )
return 3 ;
return - 1 ;
}
static int F_44 ( struct V_1 * V_1 , int V_12 )
{
int V_180 , V_181 ;
if ( V_12 < V_10 || V_12 > V_11 )
return - V_85 ;
V_181 = V_1 -> V_12 [ V_12 ] . V_13 ;
if ( V_181 < 0 )
return - V_85 ;
V_180 = F_97 ( V_1 -> V_3 , V_1 -> V_9 , V_181 ) ;
if ( V_180 < 0 ) {
F_8 ( V_50 L_45 ,
V_181 , V_1 -> V_9 ) ;
return V_180 ;
}
V_1 -> V_22 = ( V_1 -> V_12 [ V_12 ] . V_15 != NULL ) ;
V_1 -> V_16 = V_12 ;
F_2 ( & V_1 -> V_4 -> V_3 , L_46 ,
V_1 -> V_17 , V_12 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_1 )
{
int V_46 , V_78 ;
V_46 = F_98 ( V_1 , 0 , V_1 -> V_23 , V_156 - 1 ) ;
if ( V_46 < 0 ) {
F_2 ( & V_1 -> V_4 -> V_3 ,
L_47 ,
V_1 -> V_17 , V_46 ) ;
V_1 -> V_23 [ 0 ] = V_1 -> V_23 [ 1 ] = '\0' ;
return - V_56 ;
}
V_78 = F_99 ( * ( ( V_182 * ) V_1 -> V_23 ) ) ;
if ( V_78 < 2 )
V_78 = 2 ;
else if ( V_78 >= V_156 )
V_78 = V_156 - 1 ;
V_1 -> V_23 [ V_78 ] = '\0' ;
F_2 ( & V_1 -> V_4 -> V_3 , L_48 ,
V_1 -> V_17 , V_78 , & V_1 -> V_23 [ 2 ] ) ;
return V_78 ;
}
static void F_100 ( struct V_59 * V_4 )
{
struct V_1 * V_1 = F_24 ( V_4 ) ;
F_101 ( V_4 , & V_160 ) ;
if ( ! V_1 || ! V_1 -> V_3 ) {
F_47 ( & V_4 -> V_3 , L_49 ) ;
F_102 () ;
}
F_94 ( & V_4 -> V_3 , & V_158 ) ;
F_15 ( & V_61 ) ;
F_15 ( & V_1 -> V_48 ) ;
V_1 -> V_6 = 0 ;
F_10 ( & V_1 -> V_45 ) ;
F_10 ( & V_1 -> V_42 ) ;
F_91 ( V_4 , NULL ) ;
F_29 ( V_1 ) ;
F_17 ( & V_1 -> V_48 ) ;
if ( ! V_1 -> V_21 )
F_27 ( V_1 ) ;
F_17 ( & V_61 ) ;
}
static int F_103 ( struct V_59 * V_4 , T_6 V_183 )
{
struct V_1 * V_1 = F_24 ( V_4 ) ;
F_29 ( V_1 ) ;
#if 0
wake_up(&usblp->wwait);
wake_up(&usblp->rwait);
#endif
return 0 ;
}
static int F_104 ( struct V_59 * V_4 )
{
struct V_1 * V_1 = F_24 ( V_4 ) ;
int V_180 ;
V_180 = F_19 ( V_1 ) ;
return V_180 ;
}
