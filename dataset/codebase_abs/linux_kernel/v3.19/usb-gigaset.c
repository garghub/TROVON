static inline unsigned F_1 ( unsigned V_1 )
{
return ( ( V_1 & V_2 ) ? 1 : 0 ) | ( ( V_1 & V_3 ) ? 2 : 0 ) ;
}
static int F_2 ( struct V_4 * V_5 , unsigned V_6 ,
unsigned V_7 )
{
struct V_8 * V_9 = V_5 -> V_10 . V_11 -> V_9 ;
unsigned V_12 , V_13 ;
int V_14 ;
V_12 = F_1 ( V_6 ^ V_7 ) ;
V_13 = F_1 ( V_7 ) ;
F_3 ( V_15 , L_1 , V_13 , V_12 ) ;
V_14 = F_4 ( V_9 , F_5 ( V_9 , 0 ) , 7 , 0x41 ,
( V_13 & 0xff ) | ( ( V_12 & 0xff ) << 8 ) , 0 ,
NULL , 0 , 2000 ) ;
if ( V_14 < 0 )
return V_14 ;
return 0 ;
}
static int F_6 ( struct V_4 * V_5 , T_1 V_16 , T_2 V_13 )
{
struct V_8 * V_9 = V_5 -> V_10 . V_11 -> V_9 ;
int V_14 , V_17 ;
F_3 ( V_15 , L_2 ,
( unsigned ) V_16 , ( unsigned ) V_13 ) ;
V_14 = F_4 ( V_9 , F_5 ( V_9 , 0 ) , 0x12 , 0x41 ,
0xf , 0 , NULL , 0 , 2000 ) ;
if ( V_14 < 0 ) {
F_7 ( & V_9 -> V_18 , L_3 , - V_14 ) ;
return V_14 ;
}
V_14 = F_4 ( V_9 , F_5 ( V_9 , 0 ) , V_16 , 0x41 ,
V_13 , 0 , NULL , 0 , 2000 ) ;
if ( V_14 < 0 )
F_7 ( & V_9 -> V_18 , L_4 ,
- V_14 , ( unsigned ) V_16 ) ;
V_17 = F_4 ( V_9 , F_5 ( V_9 , 0 ) , 0x19 , 0x41 ,
0 , 0 , V_5 -> V_10 . V_11 -> V_19 , 6 , 2000 ) ;
if ( V_17 < 0 )
F_7 ( & V_9 -> V_18 , L_5 , - V_17 ) ;
return V_14 < 0 ? V_14 : ( V_17 < 0 ? V_17 : 0 ) ;
}
static int F_8 ( struct V_4 * V_5 , unsigned V_20 )
{
T_2 V_13 ;
T_3 V_21 ;
V_20 &= V_22 ;
switch ( V_20 ) {
case V_23 : V_21 = 300 ; break;
case V_24 : V_21 = 600 ; break;
case V_25 : V_21 = 1200 ; break;
case V_26 : V_21 = 2400 ; break;
case V_27 : V_21 = 4800 ; break;
case V_28 : V_21 = 9600 ; break;
case V_29 : V_21 = 19200 ; break;
case V_30 : V_21 = 38400 ; break;
case V_31 : V_21 = 57600 ; break;
case V_32 : V_21 = 115200 ; break;
default:
V_21 = 9600 ;
F_7 ( V_5 -> V_18 , L_6
L_7 , V_20 ) ;
}
V_13 = 0x383fff / V_21 + 1 ;
return F_6 ( V_5 , 1 , V_13 ) ;
}
static int F_9 ( struct V_4 * V_5 , unsigned V_20 )
{
T_2 V_13 = 0 ;
if ( V_20 & V_33 )
V_13 |= ( V_20 & V_34 ) ? 0x10 : 0x20 ;
switch ( V_20 & V_35 ) {
case V_36 :
V_13 |= 5 << 8 ; break;
case V_37 :
V_13 |= 6 << 8 ; break;
case V_38 :
V_13 |= 7 << 8 ; break;
case V_39 :
V_13 |= 8 << 8 ; break;
default:
F_7 ( V_5 -> V_18 , L_8 ) ;
V_13 |= 8 << 8 ;
break;
}
if ( V_20 & V_40 ) {
if ( ( V_20 & V_35 ) == V_36 )
V_13 |= 1 ;
else
V_13 |= 2 ;
}
return F_6 ( V_5 , 3 , V_13 ) ;
}
static int F_10 ( struct V_41 * V_42 )
{
F_11 ( V_42 ) ;
return 0 ;
}
static int F_12 ( struct V_41 * V_42 )
{
F_13 ( V_42 ) ;
return 0 ;
}
static void F_14 ( unsigned long V_43 )
{
struct V_4 * V_5 = (struct V_4 * ) V_43 ;
struct V_41 * V_42 = & V_5 -> V_42 [ 0 ] ;
F_3 ( V_44 , L_9 ) ;
if ( V_5 -> V_10 . V_11 -> V_45 ) {
F_3 ( V_44 , L_10 ) ;
return;
}
V_46:
if ( ! V_42 -> V_47 ) {
if ( V_5 -> V_48 ) {
F_3 ( V_44 , L_11 ) ;
if ( F_15 ( V_5 ) < 0 ) {
F_3 ( V_44 ,
L_12 ) ;
goto V_46;
}
return;
}
V_42 -> V_47 = F_16 ( & V_42 -> V_49 ) ;
if ( ! V_42 -> V_47 )
return;
F_3 ( V_50 , L_13 ,
( unsigned long ) V_42 -> V_47 ) ;
}
F_3 ( V_44 , L_14 ) ;
if ( F_17 ( V_5 ) < 0 ) {
F_3 ( V_44 , L_15 ) ;
goto V_46;
}
}
static void F_18 ( struct V_51 * V_51 )
{
struct V_4 * V_5 = V_51 -> V_52 ;
struct V_53 * V_54 = V_5 -> V_54 ;
int V_55 = V_51 -> V_55 ;
int V_14 ;
unsigned V_56 ;
unsigned char * V_57 ;
unsigned long V_58 ;
if ( ! V_55 ) {
V_56 = V_51 -> V_59 ;
if ( V_56 ) {
V_57 = V_5 -> V_10 . V_11 -> V_60 ;
if ( F_19 ( * V_57 ) )
F_20 ( V_5 -> V_18 ,
L_16 ,
V_61 , ( unsigned ) * V_57 ) ;
++ V_57 ;
-- V_56 ;
if ( F_21 ( V_54 , V_57 , V_56 ) ) {
F_3 ( V_50 , L_17 , V_61 ) ;
F_22 ( V_54 -> V_5 ) ;
}
} else
F_3 ( V_50 , L_18 ) ;
} else {
F_3 ( V_62 , L_19 ,
V_61 , V_55 ) ;
if ( V_55 == - V_63 || V_55 == - V_64 )
return;
}
F_23 ( & V_5 -> V_65 , V_58 ) ;
if ( ! V_5 -> V_66 ) {
F_24 ( & V_5 -> V_65 , V_58 ) ;
F_25 ( L_20 , V_61 ) ;
return;
}
V_14 = F_26 ( V_51 , V_67 ) ;
F_24 ( & V_5 -> V_65 , V_58 ) ;
if ( V_14 )
F_7 ( V_5 -> V_18 , L_21 , - V_14 ) ;
}
static void F_27 ( struct V_51 * V_51 )
{
struct V_4 * V_5 = V_51 -> V_52 ;
int V_55 = V_51 -> V_55 ;
unsigned long V_58 ;
switch ( V_55 ) {
case 0 :
break;
case - V_63 :
F_3 ( V_62 , L_22 , V_61 ) ;
V_5 -> V_10 . V_11 -> V_45 = 0 ;
return;
default:
F_7 ( V_5 -> V_18 , L_23 ,
- V_55 ) ;
}
F_23 ( & V_5 -> V_65 , V_58 ) ;
if ( ! V_5 -> V_66 ) {
F_25 ( L_20 , V_61 ) ;
} else {
V_5 -> V_10 . V_11 -> V_45 = 0 ;
F_28 ( & V_5 -> V_68 ) ;
}
F_24 ( & V_5 -> V_65 , V_58 ) ;
}
static int F_15 ( struct V_4 * V_5 )
{
struct V_69 * V_70 = V_5 -> V_48 ;
unsigned long V_58 ;
int V_71 ;
int V_55 = - V_63 ;
struct V_72 * V_73 = V_5 -> V_10 . V_11 ;
do {
if ( ! V_70 -> V_74 ) {
F_23 ( & V_5 -> V_75 , V_58 ) ;
V_5 -> V_76 -= V_5 -> V_77 ;
F_3 ( V_44 , L_24 ,
V_5 -> V_77 , V_5 -> V_76 ) ;
V_5 -> V_48 = V_70 -> V_78 ;
if ( V_5 -> V_48 ) {
V_5 -> V_48 -> V_79 = NULL ;
V_5 -> V_77 = V_5 -> V_48 -> V_74 ;
} else {
V_5 -> V_80 = NULL ;
V_5 -> V_77 = 0 ;
}
F_24 ( & V_5 -> V_75 , V_58 ) ;
if ( V_70 -> V_81 )
F_28 ( V_70 -> V_81 ) ;
F_29 ( V_70 ) ;
V_70 = V_5 -> V_48 ;
}
if ( V_70 ) {
V_71 = F_30 ( V_70 -> V_74 , V_73 -> V_82 ) ;
F_3 ( V_44 , L_25 , V_71 ) ;
F_31 ( V_73 -> V_83 , V_73 -> V_9 ,
F_32 ( V_73 -> V_9 ,
V_73 -> V_84 ) ,
V_70 -> V_85 + V_70 -> V_86 , V_71 ,
F_27 , V_5 ) ;
V_70 -> V_86 += V_71 ;
V_70 -> V_74 -= V_71 ;
V_73 -> V_45 = 1 ;
F_23 ( & V_5 -> V_65 , V_58 ) ;
V_55 = V_5 -> V_66 ?
F_26 ( V_73 -> V_83 , V_67 ) :
- V_87 ;
F_24 ( & V_5 -> V_65 , V_58 ) ;
if ( V_55 ) {
V_73 -> V_45 = 0 ;
F_7 ( V_5 -> V_18 ,
L_26 ,
- V_55 ) ;
V_70 -> V_74 = 0 ;
}
}
} while ( V_70 && V_55 );
return V_55 ;
}
static int F_33 ( struct V_4 * V_5 , struct V_69 * V_70 )
{
unsigned long V_58 ;
int V_74 ;
F_34 ( V_5 -> V_88 != V_89 ?
V_90 : V_91 ,
L_27 , V_70 -> V_74 , V_70 -> V_85 ) ;
F_23 ( & V_5 -> V_75 , V_58 ) ;
V_70 -> V_79 = V_5 -> V_80 ;
if ( V_5 -> V_80 )
V_5 -> V_80 -> V_78 = V_70 ;
else {
V_5 -> V_48 = V_70 ;
V_5 -> V_77 = V_70 -> V_74 ;
}
V_5 -> V_76 += V_70 -> V_74 ;
V_5 -> V_80 = V_70 ;
F_24 ( & V_5 -> V_75 , V_58 ) ;
F_23 ( & V_5 -> V_65 , V_58 ) ;
V_74 = V_70 -> V_74 ;
if ( V_5 -> V_66 )
F_28 ( & V_5 -> V_68 ) ;
F_24 ( & V_5 -> V_65 , V_58 ) ;
return V_74 ;
}
static int F_35 ( struct V_4 * V_5 )
{
unsigned V_92 ;
V_92 = V_5 -> V_76 ;
return V_92 < V_93 ? V_93 - V_92 : 0 ;
}
static int F_36 ( struct V_4 * V_5 )
{
return V_5 -> V_76 ;
}
static int F_37 ( struct V_4 * V_5 , const unsigned char V_85 [ 6 ] )
{
struct V_8 * V_9 = V_5 -> V_10 . V_11 -> V_9 ;
F_34 ( V_15 , L_28 , 6 , V_85 ) ;
memcpy ( V_5 -> V_10 . V_11 -> V_19 , V_85 , 6 ) ;
return F_4 ( V_9 , F_5 ( V_9 , 0 ) , 0x19 , 0x41 ,
0 , 0 , & V_85 , 6 , 2000 ) ;
}
static void F_38 ( struct V_41 * V_42 )
{
}
static int F_39 ( struct V_41 * V_42 )
{
V_42 -> V_10 . V_11 = NULL ;
return 0 ;
}
static void F_40 ( struct V_41 * V_42 )
{
}
static void F_41 ( struct V_4 * V_5 )
{
F_42 ( & V_5 -> V_68 ) ;
F_29 ( V_5 -> V_10 . V_11 ) ;
}
static int F_43 ( struct V_4 * V_5 )
{
struct V_72 * V_73 ;
V_5 -> V_10 . V_11 = V_73 =
F_44 ( sizeof( struct V_72 ) , V_94 ) ;
if ( ! V_73 ) {
F_25 ( L_29 ) ;
return - V_95 ;
}
V_73 -> V_19 [ 0 ] = 0 ;
V_73 -> V_19 [ 1 ] = 0 ;
V_73 -> V_19 [ 2 ] = 0 ;
V_73 -> V_19 [ 3 ] = 0 ;
V_73 -> V_19 [ 4 ] = 0x11 ;
V_73 -> V_19 [ 5 ] = 0x13 ;
V_73 -> V_96 = NULL ;
V_73 -> V_83 = NULL ;
V_73 -> V_97 = NULL ;
F_45 ( & V_5 -> V_68 ,
F_14 , ( unsigned long ) V_5 ) ;
return 0 ;
}
static int F_17 ( struct V_4 * V_5 )
{
int V_98 = 0 ;
int V_71 ;
struct V_41 * V_42 = & V_5 -> V_42 [ 0 ] ;
struct V_72 * V_73 = V_5 -> V_10 . V_11 ;
unsigned long V_58 ;
F_3 ( V_44 , L_30 , V_42 -> V_47 -> V_74 ) ;
if ( ! V_42 -> V_47 -> V_74 ) {
F_46 ( V_42 -> V_47 ) ;
V_42 -> V_47 = NULL ;
return - V_99 ;
}
V_71 = F_30 ( V_42 -> V_47 -> V_74 , ( unsigned ) V_73 -> V_82 ) ;
F_47 ( V_42 -> V_47 , V_73 -> V_96 , V_71 ) ;
F_48 ( V_42 -> V_47 , V_71 ) ;
V_73 -> V_45 = 1 ;
F_3 ( V_44 , L_31 , V_71 ) ;
F_23 ( & V_5 -> V_65 , V_58 ) ;
if ( V_5 -> V_66 ) {
F_31 ( V_73 -> V_83 , V_73 -> V_9 ,
F_32 ( V_73 -> V_9 ,
V_73 -> V_84 ) ,
V_73 -> V_96 , V_71 ,
F_27 , V_5 ) ;
V_98 = F_26 ( V_73 -> V_83 , V_67 ) ;
} else {
V_98 = - V_87 ;
}
F_24 ( & V_5 -> V_65 , V_58 ) ;
if ( V_98 ) {
F_7 ( V_5 -> V_18 , L_26 , - V_98 ) ;
V_73 -> V_45 = 0 ;
}
if ( ! V_42 -> V_47 -> V_74 ) {
F_49 ( V_42 , V_42 -> V_47 ) ;
F_3 ( V_50 , L_32 ,
( unsigned long ) V_42 -> V_47 ) ;
F_46 ( V_42 -> V_47 ) ;
V_42 -> V_47 = NULL ;
}
return V_98 ;
}
static int F_50 ( struct V_100 * V_101 ,
const struct V_102 * V_103 )
{
int V_104 ;
struct V_8 * V_9 = F_51 ( V_101 ) ;
struct V_105 * V_106 = V_101 -> V_107 ;
struct V_4 * V_5 = NULL ;
struct V_72 * V_73 = NULL ;
struct V_108 * V_109 ;
int V_110 ;
F_3 ( V_62 , L_33 , V_61 ) ;
if ( ( F_52 ( V_9 -> V_111 . V_112 ) != V_113 ) ||
( F_52 ( V_9 -> V_111 . V_114 ) != V_115 ) ) {
F_3 ( V_62 , L_34 ,
F_52 ( V_9 -> V_111 . V_112 ) ,
F_52 ( V_9 -> V_111 . V_114 ) ) ;
return - V_87 ;
}
if ( V_106 -> V_116 . V_117 != 0 ) {
F_3 ( V_62 , L_35 ,
V_106 -> V_116 . V_117 ) ;
return - V_87 ;
}
if ( V_106 -> V_116 . V_118 != 0 ) {
F_53 ( & V_9 -> V_18 , L_36 ,
V_106 -> V_116 . V_118 ) ;
return - V_87 ;
}
if ( V_106 -> V_116 . V_119 != 255 ) {
F_53 ( & V_9 -> V_18 , L_37 ,
V_106 -> V_116 . V_119 ) ;
return - V_87 ;
}
F_54 ( & V_9 -> V_18 , L_38 , V_61 ) ;
V_5 = F_55 ( V_120 , 1 , 1 , 0 , V_121 , V_122 ) ;
if ( ! V_5 )
return - V_87 ;
V_73 = V_5 -> V_10 . V_11 ;
F_56 ( V_9 ) ;
V_73 -> V_9 = V_9 ;
V_73 -> V_101 = V_101 ;
V_5 -> V_18 = & V_101 -> V_18 ;
F_57 ( V_101 , V_5 ) ;
V_109 = & V_106 -> V_109 [ 0 ] . V_116 ;
V_110 = F_52 ( V_109 -> V_123 ) ;
V_73 -> V_82 = V_110 ;
V_73 -> V_84 = F_58 ( V_109 ) ;
V_73 -> V_96 = F_44 ( V_110 , V_94 ) ;
if ( ! V_73 -> V_96 ) {
F_7 ( V_5 -> V_18 , L_39 ) ;
V_104 = - V_95 ;
goto error;
}
V_73 -> V_83 = F_59 ( 0 , V_94 ) ;
if ( ! V_73 -> V_83 ) {
F_7 ( V_5 -> V_18 , L_40 ) ;
V_104 = - V_95 ;
goto error;
}
V_109 = & V_106 -> V_109 [ 1 ] . V_116 ;
V_73 -> V_45 = 0 ;
V_73 -> V_97 = F_59 ( 0 , V_94 ) ;
if ( ! V_73 -> V_97 ) {
F_7 ( V_5 -> V_18 , L_41 ) ;
V_104 = - V_95 ;
goto error;
}
V_110 = F_52 ( V_109 -> V_123 ) ;
V_73 -> V_124 = V_110 ;
V_73 -> V_60 = F_44 ( V_110 , V_94 ) ;
if ( ! V_73 -> V_60 ) {
F_7 ( V_5 -> V_18 , L_42 ) ;
V_104 = - V_95 ;
goto error;
}
F_60 ( V_73 -> V_97 , V_9 ,
F_61 ( V_9 , F_58 ( V_109 ) ) ,
V_73 -> V_60 , V_110 ,
F_18 ,
V_5 , V_109 -> V_125 ) ;
V_104 = F_26 ( V_73 -> V_97 , V_94 ) ;
if ( V_104 ) {
F_7 ( V_5 -> V_18 , L_43 , - V_104 ) ;
goto error;
}
if ( V_126 == V_127 )
V_5 -> V_88 = V_89 ;
V_104 = F_62 ( V_5 ) ;
if ( V_104 < 0 ) {
F_42 ( & V_5 -> V_68 ) ;
goto error;
}
return 0 ;
error:
F_63 ( V_73 -> V_97 ) ;
F_29 ( V_73 -> V_96 ) ;
F_64 ( V_73 -> V_83 ) ;
F_29 ( V_73 -> V_60 ) ;
F_64 ( V_73 -> V_97 ) ;
F_57 ( V_101 , NULL ) ;
V_73 -> V_97 = V_73 -> V_83 = NULL ;
V_73 -> V_60 = V_73 -> V_96 = NULL ;
F_65 ( V_73 -> V_9 ) ;
V_73 -> V_9 = NULL ;
V_73 -> V_101 = NULL ;
F_66 ( V_5 ) ;
return V_104 ;
}
static void F_67 ( struct V_100 * V_101 )
{
struct V_4 * V_5 ;
struct V_72 * V_73 ;
V_5 = F_68 ( V_101 ) ;
V_73 = V_5 -> V_10 . V_11 ;
F_54 ( V_5 -> V_18 , L_44 ) ;
F_63 ( V_73 -> V_97 ) ;
F_69 ( V_5 ) ;
F_57 ( V_101 , NULL ) ;
F_42 ( & V_5 -> V_68 ) ;
F_63 ( V_73 -> V_83 ) ;
F_29 ( V_73 -> V_96 ) ;
F_64 ( V_73 -> V_83 ) ;
F_29 ( V_73 -> V_60 ) ;
F_64 ( V_73 -> V_97 ) ;
V_73 -> V_97 = V_73 -> V_83 = NULL ;
V_73 -> V_60 = V_73 -> V_96 = NULL ;
F_65 ( V_73 -> V_9 ) ;
V_73 -> V_101 = NULL ;
V_73 -> V_9 = NULL ;
V_5 -> V_18 = NULL ;
F_66 ( V_5 ) ;
}
static int F_70 ( struct V_100 * V_128 , T_4 V_129 )
{
struct V_4 * V_5 = F_68 ( V_128 ) ;
V_5 -> V_66 = 0 ;
F_63 ( V_5 -> V_10 . V_11 -> V_97 ) ;
F_42 ( & V_5 -> V_68 ) ;
F_63 ( V_5 -> V_10 . V_11 -> V_83 ) ;
F_3 ( V_130 , L_45 ) ;
return 0 ;
}
static int F_71 ( struct V_100 * V_128 )
{
struct V_4 * V_5 = F_68 ( V_128 ) ;
int V_131 ;
V_5 -> V_66 = 1 ;
V_131 = F_26 ( V_5 -> V_10 . V_11 -> V_97 , V_94 ) ;
if ( V_131 ) {
F_7 ( V_5 -> V_18 , L_46 , - V_131 ) ;
return V_131 ;
}
F_3 ( V_130 , L_47 ) ;
return 0 ;
}
static int F_72 ( struct V_100 * V_128 )
{
return F_70 ( V_128 , V_132 ) ;
}
static int T_5 F_73 ( void )
{
int V_133 ;
V_120 = F_74 ( V_134 , V_135 ,
V_122 , V_136 ,
& V_137 , V_138 ) ;
if ( V_120 == NULL ) {
V_133 = - V_95 ;
goto error;
}
V_133 = F_75 ( & V_139 ) ;
if ( V_133 < 0 ) {
F_25 ( L_48 , - V_133 ) ;
goto error;
}
F_76 ( V_140 L_49 ) ;
return 0 ;
error:
if ( V_120 )
F_77 ( V_120 ) ;
V_120 = NULL ;
return V_133 ;
}
static void T_6 F_78 ( void )
{
int V_141 ;
F_79 ( V_120 ) ;
for ( V_141 = 0 ; V_141 < V_120 -> V_142 ; V_141 ++ )
F_80 ( V_120 -> V_5 + V_141 ) ;
F_81 ( & V_139 ) ;
F_77 ( V_120 ) ;
V_120 = NULL ;
}
