static void F_1 ( struct V_1 * V_1 )
{
int V_2 ;
F_2 ( L_1 , V_1 ) ;
F_2 ( L_2 , V_1 -> V_3 ) ;
F_2 ( L_3 , V_1 -> V_4 ) ;
F_2 ( L_4 , V_1 -> V_5 ) ;
F_2 ( L_5 , V_1 -> V_6 ) ;
F_2 ( L_6 , V_1 -> V_7 ) ;
for ( V_2 = V_8 ; V_2 <= V_9 ; V_2 ++ ) {
F_2 ( L_7 , V_2 , V_1 -> V_10 [ V_2 ] . V_11 ) ;
F_2 ( L_8 , V_2 , V_1 -> V_10 [ V_2 ] . V_12 ) ;
F_2 ( L_9 , V_2 , V_1 -> V_10 [ V_2 ] . V_13 ) ;
}
F_2 ( L_10 , V_1 -> V_14 ) ;
F_2 ( L_11 , V_1 -> V_15 ) ;
F_2 ( L_12 , V_1 -> V_16 ) ;
F_2 ( L_13 , V_1 -> V_17 ) ;
F_2 ( L_14 , V_1 -> V_18 ) ;
F_2 ( L_15 , V_1 -> V_19 ) ;
F_2 ( L_16 , V_1 -> V_20 ) ;
F_2 ( L_17 ,
V_1 -> V_21 ?
V_1 -> V_21 + 2 :
( unsigned char * ) L_18 ) ;
}
static int F_3 ( struct V_1 * V_1 , int V_22 , int type , int V_23 , int V_24 , int V_25 , void * V_26 , int V_27 )
{
int V_28 ;
int V_29 = V_1 -> V_7 ;
if ( ( V_22 == V_30 ) && ( type == V_31 ) )
V_29 = ( V_1 -> V_7 << 8 ) | V_1 -> V_10 [ V_1 -> V_14 ] . V_11 ;
V_28 = F_4 ( V_1 -> V_3 ,
V_23 ? F_5 ( V_1 -> V_3 , 0 ) : F_6 ( V_1 -> V_3 , 0 ) ,
V_22 , type | V_23 | V_24 , V_25 , V_29 , V_26 , V_27 , V_32 ) ;
F_2 ( L_19 ,
V_22 , ! ! V_23 , V_24 , V_25 , V_29 , V_27 , V_28 ) ;
return V_28 < 0 ? V_28 : 0 ;
}
static void F_7 ( struct V_33 * V_33 )
{
struct V_1 * V_1 = V_33 -> V_34 ;
int V_35 = V_33 -> V_35 ;
if ( V_1 -> V_4 && V_1 -> V_19 ) {
if ( V_35 )
F_8 ( V_36 L_20
L_21 ,
V_1 -> V_15 , V_35 ) ;
}
F_9 ( & V_1 -> V_37 ) ;
if ( V_35 < 0 )
V_1 -> V_17 = V_35 ;
else
V_1 -> V_17 = V_33 -> V_38 ;
V_1 -> V_39 = 1 ;
F_10 ( & V_1 -> V_40 ) ;
F_11 ( & V_1 -> V_37 ) ;
F_12 ( V_33 ) ;
}
static void F_13 ( struct V_33 * V_33 )
{
struct V_1 * V_1 = V_33 -> V_34 ;
int V_35 = V_33 -> V_35 ;
if ( V_1 -> V_4 && V_1 -> V_19 ) {
if ( V_35 )
F_8 ( V_36 L_20
L_22 ,
V_1 -> V_15 , V_35 ) ;
}
F_9 ( & V_1 -> V_37 ) ;
if ( V_35 < 0 )
V_1 -> V_16 = V_35 ;
else
V_1 -> V_16 = V_33 -> V_38 ;
V_1 -> V_41 = 0 ;
V_1 -> V_42 = 1 ;
F_10 ( & V_1 -> V_43 ) ;
F_11 ( & V_1 -> V_37 ) ;
F_12 ( V_33 ) ;
}
static int F_14 ( struct V_1 * V_1 , int V_44 )
{
unsigned char V_35 , V_45 = 0 ;
int error ;
F_15 ( & V_1 -> V_46 ) ;
if ( ( error = F_16 ( V_1 , V_1 -> V_47 ) ) < 0 ) {
F_17 ( & V_1 -> V_46 ) ;
F_18 ( V_48
L_23 ,
V_1 -> V_15 , error ) ;
return 0 ;
}
V_35 = * V_1 -> V_47 ;
F_17 ( & V_1 -> V_46 ) ;
if ( ~ V_35 & V_49 )
V_45 = 3 ;
if ( V_35 & V_50 )
V_45 = 1 ;
if ( ~ V_35 & V_51 )
V_45 = 2 ;
if ( V_45 != V_44 ) {
F_8 ( V_52 L_24 ,
V_1 -> V_15 , V_53 [ V_45 ] ) ;
}
return V_45 ;
}
static int F_19 ( struct V_1 * V_1 )
{
if ( V_1 -> V_20 && V_1 -> V_19 ) {
if ( F_20 ( V_1 ) < 0 )
return - V_54 ;
}
return 0 ;
}
static int F_21 ( struct V_55 * V_55 , struct V_56 * V_56 )
{
int V_15 = F_22 ( V_55 ) ;
struct V_1 * V_1 ;
struct V_57 * V_58 ;
int V_28 ;
if ( V_15 < 0 )
return - V_59 ;
F_15 ( & V_60 ) ;
V_28 = - V_59 ;
V_58 = F_23 ( & V_61 , V_15 ) ;
if ( ! V_58 )
goto V_62;
V_1 = F_24 ( V_58 ) ;
if ( ! V_1 || ! V_1 -> V_3 || ! V_1 -> V_4 )
goto V_62;
V_28 = - V_63 ;
if ( V_1 -> V_19 )
goto V_62;
V_28 = F_25 ( V_58 ) ;
if ( V_28 < 0 )
goto V_62;
V_1 -> V_19 = 1 ;
V_56 -> V_64 = V_1 ;
V_1 -> V_42 = 1 ;
V_1 -> V_16 = 0 ;
V_1 -> V_39 = 0 ;
if ( F_19 ( V_1 ) < 0 ) {
F_26 ( V_58 ) ;
V_1 -> V_19 = 0 ;
V_56 -> V_64 = NULL ;
V_28 = - V_54 ;
}
V_62:
F_17 ( & V_60 ) ;
return V_28 ;
}
static void F_27 ( struct V_1 * V_1 )
{
F_8 ( V_52 L_25 , V_1 -> V_15 ) ;
F_28 ( V_1 -> V_5 ) ;
F_28 ( V_1 -> V_21 ) ;
F_28 ( V_1 -> V_47 ) ;
F_28 ( V_1 ) ;
}
static void F_29 ( struct V_1 * V_1 )
{
F_30 ( & V_1 -> V_65 ) ;
}
static int F_31 ( struct V_55 * V_55 , struct V_56 * V_56 )
{
struct V_1 * V_1 = V_56 -> V_64 ;
V_1 -> V_66 &= ~ V_67 ;
F_15 ( & V_60 ) ;
V_1 -> V_19 = 0 ;
if ( V_1 -> V_4 ) {
F_29 ( V_1 ) ;
F_26 ( V_1 -> V_58 ) ;
} else
F_27 ( V_1 ) ;
F_17 ( & V_60 ) ;
return 0 ;
}
static unsigned int F_32 ( struct V_56 * V_56 , struct V_68 * V_69 )
{
int V_70 ;
unsigned long V_66 ;
struct V_1 * V_1 = V_56 -> V_64 ;
F_33 ( V_56 , & V_1 -> V_40 , V_69 ) ;
F_33 ( V_56 , & V_1 -> V_43 , V_69 ) ;
F_34 ( & V_1 -> V_37 , V_66 ) ;
V_70 = ( ( V_1 -> V_20 && V_1 -> V_39 ) ? V_71 | V_72 : 0 ) |
( ( V_1 -> V_41 || V_1 -> V_42 ) ? V_73 | V_74 : 0 ) ;
F_35 ( & V_1 -> V_37 , V_66 ) ;
return V_70 ;
}
static long F_36 ( struct V_56 * V_56 , unsigned int V_75 , unsigned long V_76 )
{
struct V_1 * V_1 = V_56 -> V_64 ;
int V_77 , V_44 , V_78 ;
unsigned char V_79 ;
int V_35 ;
int V_80 [ 2 ] ;
int V_28 = 0 ;
F_15 ( & V_1 -> V_46 ) ;
if ( ! V_1 -> V_4 ) {
V_28 = - V_59 ;
goto V_81;
}
F_2 ( L_26 , V_75 , F_37 ( V_75 ) ,
F_38 ( V_75 ) , F_39 ( V_75 ) , F_40 ( V_75 ) ) ;
if ( F_37 ( V_75 ) == 'P' )
switch ( F_38 ( V_75 ) ) {
case V_82 :
if ( F_40 ( V_75 ) != V_83 ) {
V_28 = - V_84 ;
goto V_81;
}
V_77 = F_41 ( V_1 ) ;
if ( V_77 < 0 ) {
V_28 = V_77 ;
goto V_81;
}
if ( V_77 > F_39 ( V_75 ) )
V_77 = F_39 ( V_75 ) ;
if ( F_42 ( ( void V_85 * ) V_76 ,
V_1 -> V_21 ,
( unsigned long ) V_77 ) ) {
V_28 = - V_86 ;
goto V_81;
}
break;
case V_87 :
if ( F_40 ( V_75 ) != V_83 ||
F_39 ( V_75 ) < sizeof( V_80 ) ) {
V_28 = - V_84 ;
goto V_81;
}
V_80 [ 0 ] = V_1 -> V_14 ;
V_80 [ 1 ] = 0 ;
for ( V_78 = V_8 ;
V_78 <= V_9 ; V_78 ++ ) {
if ( V_1 -> V_10 [ V_78 ] . V_11 >= 0 )
V_80 [ 1 ] |= ( 1 << V_78 ) ;
}
if ( F_42 ( ( void V_85 * ) V_76 ,
( unsigned char * ) V_80 ,
sizeof( V_80 ) ) ) {
V_28 = - V_86 ;
goto V_81;
}
break;
case V_88 :
if ( F_40 ( V_75 ) != V_89 ) {
V_28 = - V_84 ;
goto V_81;
}
#ifdef F_43
if ( V_76 == - 10 ) {
F_1 ( V_1 ) ;
break;
}
#endif
F_29 ( V_1 ) ;
V_28 = F_44 ( V_1 , V_76 ) ;
if ( V_28 < 0 ) {
F_44 ( V_1 ,
V_1 -> V_14 ) ;
}
break;
case V_90 :
if ( F_40 ( V_75 ) != V_89 ||
F_45 ( V_1 -> V_3 -> V_91 . V_92 ) != 0x03F0 ||
V_1 -> V_18 & V_93 ) {
V_28 = - V_84 ;
goto V_81;
}
V_44 = F_46 ( V_1 ,
V_76 , & V_79 ) ;
if ( V_44 < 0 ) {
F_47 ( & V_1 -> V_3 -> V_3 ,
L_27
L_28 ,
V_1 -> V_15 , V_44 ) ;
V_28 = - V_54 ;
goto V_81;
}
F_2 ( L_29 ,
V_1 -> V_15 , V_76 , V_79 ) ;
break;
case V_94 :
if ( F_40 ( V_75 ) != V_83 ||
F_39 ( V_75 ) < sizeof( V_80 ) ) {
V_28 = - V_84 ;
goto V_81;
}
V_80 [ 0 ] = V_1 -> V_3 -> V_95 -> V_96 ;
V_80 [ 1 ] = V_1 -> V_3 -> V_97 ;
if ( F_42 ( ( void V_85 * ) V_76 ,
( unsigned char * ) V_80 ,
sizeof( V_80 ) ) ) {
V_28 = - V_86 ;
goto V_81;
}
F_2 ( L_30 ,
V_1 -> V_15 , V_80 [ 0 ] , V_80 [ 1 ] ) ;
break;
case V_98 :
if ( F_40 ( V_75 ) != V_83 ||
F_39 ( V_75 ) < sizeof( V_80 ) ) {
V_28 = - V_84 ;
goto V_81;
}
V_80 [ 0 ] = F_45 ( V_1 -> V_3 -> V_91 . V_92 ) ;
V_80 [ 1 ] = F_45 ( V_1 -> V_3 -> V_91 . V_99 ) ;
if ( F_42 ( ( void V_85 * ) V_76 ,
( unsigned char * ) V_80 ,
sizeof( V_80 ) ) ) {
V_28 = - V_86 ;
goto V_81;
}
F_2 ( L_31 ,
V_1 -> V_15 , V_80 [ 0 ] , V_80 [ 1 ] ) ;
break;
case V_100 :
if ( F_40 ( V_75 ) != V_101 ) {
V_28 = - V_84 ;
goto V_81;
}
V_28 = F_48 ( V_1 ) ;
break;
default:
V_28 = - V_102 ;
}
else
switch ( V_75 ) {
case V_103 :
if ( ( V_28 = F_16 ( V_1 , V_1 -> V_47 ) ) ) {
F_18 ( V_48 L_32
L_33 ,
V_1 -> V_15 , V_28 ) ;
V_28 = - V_54 ;
goto V_81;
}
V_35 = * V_1 -> V_47 ;
if ( F_42 ( ( void V_85 * ) V_76 , & V_35 , sizeof( int ) ) )
V_28 = - V_86 ;
break;
case V_104 :
if ( V_76 )
V_1 -> V_66 |= V_67 ;
else
V_1 -> V_66 &= ~ V_67 ;
break;
default:
V_28 = - V_102 ;
}
V_81:
F_17 ( & V_1 -> V_46 ) ;
return V_28 ;
}
static struct V_33 * F_49 ( struct V_1 * V_1 , int V_105 )
{
struct V_33 * V_33 ;
char * V_106 ;
if ( ( V_106 = F_50 ( V_105 , V_107 ) ) == NULL )
return NULL ;
if ( ( V_33 = F_51 ( 0 , V_107 ) ) == NULL ) {
F_28 ( V_106 ) ;
return NULL ;
}
F_52 ( V_33 , V_1 -> V_3 ,
F_53 ( V_1 -> V_3 ,
V_1 -> V_10 [ V_1 -> V_14 ] . V_12 -> V_108 ) ,
V_106 , V_105 , F_13 , V_1 ) ;
V_33 -> V_109 |= V_110 ;
return V_33 ;
}
static T_1 F_54 ( struct V_56 * V_56 , const char V_85 * V_111 , T_2 V_112 , T_3 * V_113 )
{
struct V_1 * V_1 = V_56 -> V_64 ;
struct V_33 * V_114 ;
int V_115 ;
int V_105 ;
T_1 V_116 = 0 ;
if ( F_55 ( & V_1 -> V_117 ) ) {
V_115 = - V_118 ;
goto V_119;
}
if ( ( V_115 = F_56 ( V_1 , ! ! ( V_56 -> V_120 & V_121 ) ) ) < 0 )
goto V_122;
while ( V_116 < V_112 ) {
if ( ( V_105 = V_112 - V_116 ) > V_123 )
V_105 = V_123 ;
V_115 = - V_124 ;
if ( ( V_114 = F_49 ( V_1 , V_105 ) ) == NULL )
goto V_125;
F_57 ( V_114 , & V_1 -> V_65 ) ;
if ( F_58 ( V_114 -> V_126 ,
V_111 + V_116 , V_105 ) ) {
V_115 = - V_86 ;
goto V_127;
}
F_59 ( & V_1 -> V_37 ) ;
V_1 -> V_42 = 0 ;
F_60 ( & V_1 -> V_37 ) ;
if ( ( V_115 = F_61 ( V_114 , V_107 ) ) < 0 ) {
V_1 -> V_16 = 0 ;
F_59 ( & V_1 -> V_37 ) ;
V_1 -> V_41 = 0 ;
V_1 -> V_42 = 1 ;
F_10 ( & V_1 -> V_43 ) ;
F_60 ( & V_1 -> V_37 ) ;
if ( V_115 != - V_124 )
V_115 = - V_54 ;
goto V_128;
}
V_115 = F_56 ( V_1 , ! ! ( V_56 -> V_120 & V_121 ) ) ;
if ( V_115 < 0 ) {
if ( V_115 == - V_129 ) {
V_116 += V_105 ;
}
if ( V_115 == - V_130 ) {
F_59 ( & V_1 -> V_37 ) ;
V_1 -> V_41 = 1 ;
F_60 ( & V_1 -> V_37 ) ;
V_116 += V_105 ;
}
goto V_131;
}
if ( V_1 -> V_16 < 0 ) {
V_115 = - V_54 ;
goto V_131;
}
V_116 += V_1 -> V_16 ;
}
F_17 ( & V_1 -> V_117 ) ;
return V_116 ;
V_128:
V_127:
F_62 ( V_114 ) ;
F_12 ( V_114 ) ;
V_125:
V_122:
V_131:
F_17 ( & V_1 -> V_117 ) ;
V_119:
return V_116 ? V_116 : V_115 ;
}
static T_1 F_63 ( struct V_56 * V_56 , char V_85 * V_111 , T_2 V_27 , T_3 * V_113 )
{
struct V_1 * V_1 = V_56 -> V_64 ;
T_1 V_112 ;
T_1 V_132 ;
int V_115 ;
if ( ! V_1 -> V_20 )
return - V_84 ;
V_115 = F_64 ( V_1 , ! ! ( V_56 -> V_120 & V_121 ) ) ;
if ( V_115 < 0 )
return V_115 ;
if ( ( V_132 = V_1 -> V_17 ) < 0 ) {
F_8 ( V_48 L_34 ,
V_1 -> V_15 , ( int ) V_132 ) ;
F_20 ( V_1 ) ;
V_112 = - V_54 ;
goto V_81;
}
V_112 = V_27 < V_132 - V_1 -> V_6 ? V_27 : V_132 - V_1 -> V_6 ;
if ( V_112 != 0 &&
F_42 ( V_111 , V_1 -> V_5 + V_1 -> V_6 , V_112 ) ) {
V_112 = - V_86 ;
goto V_81;
}
if ( ( V_1 -> V_6 += V_112 ) == V_132 ) {
if ( F_20 ( V_1 ) < 0 ) {
if ( V_112 == 0 )
V_112 = - V_54 ;
goto V_81;
}
}
V_81:
F_17 ( & V_1 -> V_46 ) ;
return V_112 ;
}
static int F_56 ( struct V_1 * V_1 , int V_133 )
{
F_65 ( V_134 , V_135 ) ;
int V_136 ;
int V_44 = 0 ;
F_66 ( & V_1 -> V_43 , & V_134 ) ;
for (; ; ) {
F_67 ( V_137 ) ;
if ( F_55 ( & V_1 -> V_46 ) ) {
V_136 = - V_118 ;
break;
}
V_136 = F_68 ( V_1 , V_133 ) ;
F_17 ( & V_1 -> V_46 ) ;
if ( V_136 <= 0 )
break;
if ( F_69 ( F_70 ( 1500 ) ) == 0 ) {
if ( V_1 -> V_66 & V_67 ) {
V_44 = F_14 ( V_1 , V_44 ) ;
if ( V_44 == 1 ) {
V_136 = - V_130 ;
break;
}
} else {
F_15 ( & V_1 -> V_46 ) ;
F_16 ( V_1 , V_1 -> V_47 ) ;
F_17 ( & V_1 -> V_46 ) ;
}
}
}
F_67 ( V_138 ) ;
F_71 ( & V_1 -> V_43 , & V_134 ) ;
return V_136 ;
}
static int F_68 ( struct V_1 * V_1 , int V_133 )
{
unsigned long V_66 ;
if ( ! V_1 -> V_4 )
return - V_59 ;
if ( F_72 ( V_135 ) )
return - V_118 ;
F_34 ( & V_1 -> V_37 , V_66 ) ;
if ( V_1 -> V_42 ) {
F_35 ( & V_1 -> V_37 , V_66 ) ;
return 0 ;
}
F_35 ( & V_1 -> V_37 , V_66 ) ;
if ( V_133 )
return - V_129 ;
return 1 ;
}
static int F_64 ( struct V_1 * V_1 , int V_133 )
{
F_65 ( V_134 , V_135 ) ;
int V_136 ;
F_66 ( & V_1 -> V_40 , & V_134 ) ;
for (; ; ) {
if ( F_55 ( & V_1 -> V_46 ) ) {
V_136 = - V_118 ;
break;
}
F_67 ( V_137 ) ;
if ( ( V_136 = F_73 ( V_1 , V_133 ) ) < 0 ) {
F_17 ( & V_1 -> V_46 ) ;
break;
}
if ( V_136 == 0 )
break;
F_17 ( & V_1 -> V_46 ) ;
F_74 () ;
}
F_67 ( V_138 ) ;
F_71 ( & V_1 -> V_40 , & V_134 ) ;
return V_136 ;
}
static int F_73 ( struct V_1 * V_1 , int V_133 )
{
unsigned long V_66 ;
if ( ! V_1 -> V_4 )
return - V_59 ;
if ( F_72 ( V_135 ) )
return - V_118 ;
F_34 ( & V_1 -> V_37 , V_66 ) ;
if ( V_1 -> V_39 ) {
F_35 ( & V_1 -> V_37 , V_66 ) ;
return 0 ;
}
F_35 ( & V_1 -> V_37 , V_66 ) ;
if ( V_133 )
return - V_129 ;
return 1 ;
}
static int F_20 ( struct V_1 * V_1 )
{
struct V_33 * V_33 ;
unsigned long V_66 ;
int V_136 ;
V_136 = - V_124 ;
if ( ( V_33 = F_51 ( 0 , V_107 ) ) == NULL )
goto V_125;
F_52 ( V_33 , V_1 -> V_3 ,
F_75 ( V_1 -> V_3 ,
V_1 -> V_10 [ V_1 -> V_14 ] . V_13 -> V_108 ) ,
V_1 -> V_5 , V_139 ,
F_7 , V_1 ) ;
F_57 ( V_33 , & V_1 -> V_65 ) ;
F_34 ( & V_1 -> V_37 , V_66 ) ;
V_1 -> V_6 = 0 ;
V_1 -> V_39 = 0 ;
F_35 ( & V_1 -> V_37 , V_66 ) ;
if ( ( V_136 = F_61 ( V_33 , V_107 ) ) < 0 ) {
F_2 ( L_35 , V_136 ) ;
F_34 ( & V_1 -> V_37 , V_66 ) ;
V_1 -> V_17 = V_136 ;
V_1 -> V_39 = 1 ;
F_35 ( & V_1 -> V_37 , V_66 ) ;
goto V_128;
}
return 0 ;
V_128:
F_62 ( V_33 ) ;
F_12 ( V_33 ) ;
V_125:
return V_136 ;
}
static unsigned int F_76 ( T_4 V_140 , T_4 V_141 )
{
int V_78 ;
for ( V_78 = 0 ; V_142 [ V_78 ] . V_143 ; V_78 ++ ) {
if ( V_140 == V_142 [ V_78 ] . V_143 &&
V_141 == V_142 [ V_78 ] . V_144 )
return V_142 [ V_78 ] . V_18 ;
}
return 0 ;
}
static char * F_77 ( struct V_145 * V_3 , T_5 * V_146 )
{
return F_78 ( V_107 , L_36 , F_79 ( V_3 ) ) ;
}
static T_1 F_80 ( struct V_145 * V_3 , struct V_147 * V_148 , char * V_26 )
{
struct V_57 * V_58 = F_81 ( V_3 ) ;
struct V_1 * V_1 = F_24 ( V_58 ) ;
if ( V_1 -> V_21 [ 0 ] == 0 &&
V_1 -> V_21 [ 1 ] == 0 )
return 0 ;
return sprintf ( V_26 , L_37 , V_1 -> V_21 + 2 ) ;
}
static int F_82 ( struct V_57 * V_58 ,
const struct V_149 * V_150 )
{
struct V_151 * V_3 = F_83 ( V_58 ) ;
struct V_1 * V_1 ;
int V_10 ;
int V_28 ;
V_1 = F_84 ( sizeof( struct V_1 ) , V_107 ) ;
if ( ! V_1 ) {
V_28 = - V_124 ;
goto V_152;
}
V_1 -> V_3 = V_3 ;
F_85 ( & V_1 -> V_117 ) ;
F_85 ( & V_1 -> V_46 ) ;
F_86 ( & V_1 -> V_37 ) ;
F_87 ( & V_1 -> V_40 ) ;
F_87 ( & V_1 -> V_43 ) ;
F_88 ( & V_1 -> V_65 ) ;
V_1 -> V_7 = V_58 -> V_153 -> V_154 . V_155 ;
V_1 -> V_58 = V_58 ;
if ( ! ( V_1 -> V_21 = F_50 ( V_156 , V_107 ) ) ) {
V_28 = - V_124 ;
goto abort;
}
if ( ! ( V_1 -> V_5 = F_50 ( V_139 , V_107 ) ) ) {
V_28 = - V_124 ;
goto abort;
}
V_1 -> V_47 = F_50 ( V_157 , V_107 ) ;
if ( ! V_1 -> V_47 ) {
V_28 = - V_124 ;
goto abort;
}
V_1 -> V_18 = F_76 (
F_45 ( V_3 -> V_91 . V_92 ) ,
F_45 ( V_3 -> V_91 . V_99 ) ) ;
V_10 = F_89 ( V_1 ) ;
if ( V_10 < 0 ) {
F_2 ( L_38 ,
F_45 ( V_3 -> V_91 . V_92 ) ,
F_45 ( V_3 -> V_91 . V_99 ) ) ;
V_28 = - V_59 ;
goto abort;
}
if ( F_44 ( V_1 , V_10 ) < 0 ) {
V_28 = - V_59 ;
goto abort;
}
F_41 ( V_1 ) ;
V_28 = F_90 ( & V_58 -> V_3 , & V_158 ) ;
if ( V_28 )
goto V_159;
#ifdef F_43
F_14 ( V_1 , 0 ) ;
#endif
F_91 ( V_58 , V_1 ) ;
V_1 -> V_4 = 1 ;
V_28 = F_92 ( V_58 , & V_160 ) ;
if ( V_28 ) {
F_8 ( V_48 L_39
L_40 ,
V_161 , V_28 ) ;
goto V_159;
}
V_1 -> V_15 = V_58 -> V_15 ;
F_8 ( V_52 L_41
L_42 ,
V_1 -> V_15 , V_1 -> V_20 ? L_43 : L_44 , V_3 -> V_97 ,
V_1 -> V_7 ,
V_1 -> V_10 [ V_1 -> V_14 ] . V_11 ,
V_1 -> V_14 ,
F_45 ( V_1 -> V_3 -> V_91 . V_92 ) ,
F_45 ( V_1 -> V_3 -> V_91 . V_99 ) ) ;
return 0 ;
V_159:
F_91 ( V_58 , NULL ) ;
F_93 ( & V_58 -> V_3 , & V_158 ) ;
abort:
F_28 ( V_1 -> V_5 ) ;
F_28 ( V_1 -> V_47 ) ;
F_28 ( V_1 -> V_21 ) ;
F_28 ( V_1 ) ;
V_152:
return V_28 ;
}
static int F_89 ( struct V_1 * V_1 )
{
struct V_57 * V_162 ;
struct V_163 * V_164 ;
struct V_165 * V_166 , * V_12 , * V_13 ;
int V_2 , V_78 , V_167 ;
V_162 = V_1 -> V_58 ;
for ( V_2 = 0 ; V_2 < V_168 ; V_2 ++ )
V_1 -> V_10 [ V_2 ] . V_11 = - 1 ;
for ( V_78 = 0 ; V_78 < V_162 -> V_169 ; V_78 ++ ) {
V_164 = & V_162 -> V_170 [ V_78 ] ;
if ( V_164 -> V_154 . V_171 != 7 || V_164 -> V_154 . V_172 != 1 )
if ( ! ( V_1 -> V_18 & V_173 ) )
continue;
if ( V_164 -> V_154 . V_174 < V_8 ||
V_164 -> V_154 . V_174 > V_9 )
continue;
V_12 = V_13 = NULL ;
for ( V_167 = 0 ; V_167 < V_164 -> V_154 . V_175 ; V_167 ++ ) {
V_166 = & V_164 -> V_176 [ V_167 ] . V_154 ;
if ( F_94 ( V_166 ) )
if ( ! V_12 )
V_12 = V_166 ;
if ( F_95 ( V_166 ) )
if ( ! V_13 )
V_13 = V_166 ;
}
if ( ! V_12 || ( V_164 -> V_154 . V_174 > 1 && ! V_13 ) )
continue;
if ( V_164 -> V_154 . V_174 == 1 ) {
V_13 = NULL ;
} else if ( V_1 -> V_18 & V_93 ) {
F_8 ( V_52 L_45
L_46 ,
V_1 -> V_15 ) ;
V_13 = NULL ;
}
V_1 -> V_10 [ V_164 -> V_154 . V_174 ] . V_11 =
V_164 -> V_154 . V_177 ;
V_1 -> V_10 [ V_164 -> V_154 . V_174 ] . V_12 = V_12 ;
V_1 -> V_10 [ V_164 -> V_154 . V_174 ] . V_13 = V_13 ;
}
if ( V_178 >= V_8 &&
V_178 <= V_9 &&
V_1 -> V_10 [ V_178 ] . V_11 != - 1 )
return V_178 ;
if ( V_1 -> V_10 [ 2 ] . V_11 != - 1 )
return 2 ;
if ( V_1 -> V_10 [ 1 ] . V_11 != - 1 )
return 1 ;
if ( V_1 -> V_10 [ 3 ] . V_11 != - 1 )
return 3 ;
return - 1 ;
}
static int F_44 ( struct V_1 * V_1 , int V_10 )
{
int V_179 , V_180 ;
if ( V_10 < V_8 || V_10 > V_9 )
return - V_84 ;
V_180 = V_1 -> V_10 [ V_10 ] . V_11 ;
if ( V_180 < 0 )
return - V_84 ;
V_179 = F_96 ( V_1 -> V_3 , V_1 -> V_7 , V_180 ) ;
if ( V_179 < 0 ) {
F_8 ( V_48 L_47 ,
V_180 , V_1 -> V_7 ) ;
return V_179 ;
}
V_1 -> V_20 = ( V_1 -> V_10 [ V_10 ] . V_13 != NULL ) ;
V_1 -> V_14 = V_10 ;
F_2 ( L_48 , V_1 -> V_15 , V_10 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_1 )
{
int V_44 , V_77 ;
V_44 = F_97 ( V_1 , 0 , V_1 -> V_21 , V_156 - 1 ) ;
if ( V_44 < 0 ) {
F_2 ( L_49 ,
V_1 -> V_15 , V_44 ) ;
V_1 -> V_21 [ 0 ] = V_1 -> V_21 [ 1 ] = '\0' ;
return - V_54 ;
}
V_77 = F_98 ( * ( ( V_181 * ) V_1 -> V_21 ) ) ;
if ( V_77 < 2 )
V_77 = 2 ;
else if ( V_77 >= V_156 )
V_77 = V_156 - 1 ;
V_1 -> V_21 [ V_77 ] = '\0' ;
F_2 ( L_50 ,
V_1 -> V_15 , V_77 , & V_1 -> V_21 [ 2 ] ) ;
return V_77 ;
}
static void F_99 ( struct V_57 * V_58 )
{
struct V_1 * V_1 = F_24 ( V_58 ) ;
F_100 ( V_58 , & V_160 ) ;
if ( ! V_1 || ! V_1 -> V_3 ) {
F_47 ( & V_58 -> V_3 , L_51 ) ;
F_101 () ;
}
F_93 ( & V_58 -> V_3 , & V_158 ) ;
F_15 ( & V_60 ) ;
F_15 ( & V_1 -> V_46 ) ;
V_1 -> V_4 = 0 ;
F_10 ( & V_1 -> V_43 ) ;
F_10 ( & V_1 -> V_40 ) ;
F_91 ( V_58 , NULL ) ;
F_29 ( V_1 ) ;
F_17 ( & V_1 -> V_46 ) ;
if ( ! V_1 -> V_19 )
F_27 ( V_1 ) ;
F_17 ( & V_60 ) ;
}
static int F_102 ( struct V_57 * V_58 , T_6 V_182 )
{
struct V_1 * V_1 = F_24 ( V_58 ) ;
F_29 ( V_1 ) ;
#if 0
wake_up(&usblp->wwait);
wake_up(&usblp->rwait);
#endif
return 0 ;
}
static int F_103 ( struct V_57 * V_58 )
{
struct V_1 * V_1 = F_24 ( V_58 ) ;
int V_179 ;
V_179 = F_19 ( V_1 ) ;
return V_179 ;
}
static int T_7 F_104 ( void )
{
return F_105 ( & V_61 ) ;
}
static void T_8 F_106 ( void )
{
F_107 ( & V_61 ) ;
}
