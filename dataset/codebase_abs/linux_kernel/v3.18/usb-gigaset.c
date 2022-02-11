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
struct V_44 * V_45 ;
int V_46 ;
F_3 ( V_47 , L_9 ) ;
if ( V_5 -> V_10 . V_11 -> V_48 ) {
F_3 ( V_47 , L_10 ) ;
return;
}
do {
V_46 = 0 ;
if ( ! V_42 -> V_49 ) {
V_45 = V_5 -> V_50 ;
if ( V_45 ) {
F_3 ( V_47 , L_11 ) ;
if ( F_15 ( V_5 , V_45 ) < 0 ) {
F_3 ( V_47 ,
L_12 ) ;
V_46 = 1 ;
}
} else {
V_42 -> V_49 = F_16 ( & V_42 -> V_51 ) ;
if ( V_42 -> V_49 )
F_3 ( V_52 ,
L_13 ,
( unsigned long ) V_42 -> V_49 ) ;
}
}
if ( V_42 -> V_49 ) {
F_3 ( V_47 , L_14 ) ;
if ( F_17 ( V_5 ) < 0 ) {
F_3 ( V_47 ,
L_15 ) ;
V_46 = 1 ;
}
}
} while ( V_46 );
}
static void F_18 ( struct V_53 * V_53 )
{
struct V_4 * V_5 = V_53 -> V_54 ;
struct V_55 * V_56 = V_5 -> V_56 ;
int V_57 = V_53 -> V_57 ;
int V_14 ;
unsigned V_58 ;
unsigned char * V_59 ;
unsigned long V_60 ;
if ( ! V_57 ) {
V_58 = V_53 -> V_61 ;
if ( V_58 ) {
V_59 = V_5 -> V_10 . V_11 -> V_62 ;
if ( F_19 ( * V_59 ) )
F_20 ( V_5 -> V_18 ,
L_16 ,
V_63 , ( unsigned ) * V_59 ) ;
++ V_59 ;
-- V_58 ;
if ( F_21 ( V_56 , V_59 , V_58 ) ) {
F_3 ( V_52 , L_17 , V_63 ) ;
F_22 ( V_56 -> V_5 ) ;
}
} else
F_3 ( V_52 , L_18 ) ;
} else {
F_3 ( V_64 , L_19 ,
V_63 , V_57 ) ;
if ( V_57 == - V_65 || V_57 == - V_66 )
return;
}
F_23 ( & V_5 -> V_67 , V_60 ) ;
if ( ! V_5 -> V_68 ) {
F_24 ( & V_5 -> V_67 , V_60 ) ;
F_25 ( L_20 , V_63 ) ;
return;
}
V_14 = F_26 ( V_53 , V_69 ) ;
F_24 ( & V_5 -> V_67 , V_60 ) ;
if ( V_14 )
F_7 ( V_5 -> V_18 , L_21 , - V_14 ) ;
}
static void F_27 ( struct V_53 * V_53 )
{
struct V_4 * V_5 = V_53 -> V_54 ;
int V_57 = V_53 -> V_57 ;
unsigned long V_60 ;
switch ( V_57 ) {
case 0 :
break;
case - V_65 :
F_3 ( V_64 , L_22 , V_63 ) ;
V_5 -> V_10 . V_11 -> V_48 = 0 ;
return;
default:
F_7 ( V_5 -> V_18 , L_23 ,
- V_57 ) ;
}
F_23 ( & V_5 -> V_67 , V_60 ) ;
if ( ! V_5 -> V_68 ) {
F_25 ( L_20 , V_63 ) ;
} else {
V_5 -> V_10 . V_11 -> V_48 = 0 ;
F_28 ( & V_5 -> V_70 ) ;
}
F_24 ( & V_5 -> V_67 , V_60 ) ;
}
static int F_15 ( struct V_4 * V_5 , struct V_44 * V_45 )
{
struct V_44 * V_71 ;
unsigned long V_60 ;
int V_72 ;
int V_57 = - V_65 ;
struct V_73 * V_74 = V_5 -> V_10 . V_11 ;
do {
if ( ! V_45 -> V_75 ) {
V_71 = V_45 ;
F_23 ( & V_5 -> V_76 , V_60 ) ;
V_5 -> V_77 -= V_5 -> V_78 ;
F_3 ( V_47 , L_24 ,
V_5 -> V_78 , V_5 -> V_77 ) ;
V_5 -> V_50 = V_45 = V_45 -> V_79 ;
if ( V_45 ) {
V_45 -> V_80 = NULL ;
V_5 -> V_78 = V_45 -> V_75 ;
} else {
V_5 -> V_81 = NULL ;
V_5 -> V_78 = 0 ;
}
F_24 ( & V_5 -> V_76 , V_60 ) ;
if ( V_71 -> V_82 )
F_28 ( V_71 -> V_82 ) ;
F_29 ( V_71 ) ;
}
if ( V_45 ) {
V_72 = F_30 ( V_45 -> V_75 , V_74 -> V_83 ) ;
F_3 ( V_47 , L_25 , V_72 ) ;
F_31 ( V_74 -> V_84 , V_74 -> V_9 ,
F_32 ( V_74 -> V_9 ,
V_74 -> V_85 ) ,
V_45 -> V_86 + V_45 -> V_87 , V_72 ,
F_27 , V_5 ) ;
V_45 -> V_87 += V_72 ;
V_45 -> V_75 -= V_72 ;
V_74 -> V_48 = 1 ;
F_23 ( & V_5 -> V_67 , V_60 ) ;
V_57 = V_5 -> V_68 ?
F_26 ( V_74 -> V_84 , V_69 ) :
- V_88 ;
F_24 ( & V_5 -> V_67 , V_60 ) ;
if ( V_57 ) {
V_74 -> V_48 = 0 ;
F_7 ( V_5 -> V_18 ,
L_26 ,
- V_57 ) ;
V_45 -> V_75 = 0 ;
}
}
} while ( V_45 && V_57 );
return V_57 ;
}
static int F_33 ( struct V_4 * V_5 , struct V_44 * V_45 )
{
unsigned long V_60 ;
int V_75 ;
F_34 ( V_5 -> V_89 != V_90 ?
V_91 : V_92 ,
L_27 , V_45 -> V_75 , V_45 -> V_86 ) ;
F_23 ( & V_5 -> V_76 , V_60 ) ;
V_45 -> V_80 = V_5 -> V_81 ;
if ( V_5 -> V_81 )
V_5 -> V_81 -> V_79 = V_45 ;
else {
V_5 -> V_50 = V_45 ;
V_5 -> V_78 = V_45 -> V_75 ;
}
V_5 -> V_77 += V_45 -> V_75 ;
V_5 -> V_81 = V_45 ;
F_24 ( & V_5 -> V_76 , V_60 ) ;
F_23 ( & V_5 -> V_67 , V_60 ) ;
V_75 = V_45 -> V_75 ;
if ( V_5 -> V_68 )
F_28 ( & V_5 -> V_70 ) ;
F_24 ( & V_5 -> V_67 , V_60 ) ;
return V_75 ;
}
static int F_35 ( struct V_4 * V_5 )
{
unsigned V_93 ;
V_93 = V_5 -> V_77 ;
return V_93 < V_94 ? V_94 - V_93 : 0 ;
}
static int F_36 ( struct V_4 * V_5 )
{
return V_5 -> V_77 ;
}
static int F_37 ( struct V_4 * V_5 , const unsigned char V_86 [ 6 ] )
{
struct V_8 * V_9 = V_5 -> V_10 . V_11 -> V_9 ;
F_34 ( V_15 , L_28 , 6 , V_86 ) ;
memcpy ( V_5 -> V_10 . V_11 -> V_19 , V_86 , 6 ) ;
return F_4 ( V_9 , F_5 ( V_9 , 0 ) , 0x19 , 0x41 ,
0 , 0 , & V_86 , 6 , 2000 ) ;
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
F_42 ( & V_5 -> V_70 ) ;
F_29 ( V_5 -> V_10 . V_11 ) ;
}
static int F_43 ( struct V_4 * V_5 )
{
struct V_73 * V_74 ;
V_5 -> V_10 . V_11 = V_74 =
F_44 ( sizeof( struct V_73 ) , V_95 ) ;
if ( ! V_74 ) {
F_25 ( L_29 ) ;
return - V_96 ;
}
V_74 -> V_19 [ 0 ] = 0 ;
V_74 -> V_19 [ 1 ] = 0 ;
V_74 -> V_19 [ 2 ] = 0 ;
V_74 -> V_19 [ 3 ] = 0 ;
V_74 -> V_19 [ 4 ] = 0x11 ;
V_74 -> V_19 [ 5 ] = 0x13 ;
V_74 -> V_97 = NULL ;
V_74 -> V_84 = NULL ;
V_74 -> V_98 = NULL ;
F_45 ( & V_5 -> V_70 ,
F_14 , ( unsigned long ) V_5 ) ;
return 0 ;
}
static int F_17 ( struct V_4 * V_5 )
{
int V_99 = 0 ;
int V_72 ;
struct V_41 * V_42 = & V_5 -> V_42 [ 0 ] ;
struct V_73 * V_74 = V_5 -> V_10 . V_11 ;
unsigned long V_60 ;
F_3 ( V_47 , L_30 , V_42 -> V_49 -> V_75 ) ;
if ( ! V_42 -> V_49 -> V_75 ) {
F_46 ( V_42 -> V_49 ) ;
V_42 -> V_49 = NULL ;
return - V_100 ;
}
V_72 = F_30 ( V_42 -> V_49 -> V_75 , ( unsigned ) V_74 -> V_83 ) ;
F_47 ( V_42 -> V_49 , V_74 -> V_97 , V_72 ) ;
F_48 ( V_42 -> V_49 , V_72 ) ;
V_74 -> V_48 = 1 ;
F_3 ( V_47 , L_31 , V_72 ) ;
F_23 ( & V_5 -> V_67 , V_60 ) ;
if ( V_5 -> V_68 ) {
F_31 ( V_74 -> V_84 , V_74 -> V_9 ,
F_32 ( V_74 -> V_9 ,
V_74 -> V_85 ) ,
V_74 -> V_97 , V_72 ,
F_27 , V_5 ) ;
V_99 = F_26 ( V_74 -> V_84 , V_69 ) ;
} else {
V_99 = - V_88 ;
}
F_24 ( & V_5 -> V_67 , V_60 ) ;
if ( V_99 ) {
F_7 ( V_5 -> V_18 , L_26 , - V_99 ) ;
V_74 -> V_48 = 0 ;
}
if ( ! V_42 -> V_49 -> V_75 ) {
F_49 ( V_42 , V_42 -> V_49 ) ;
F_3 ( V_52 , L_32 ,
( unsigned long ) V_42 -> V_49 ) ;
F_46 ( V_42 -> V_49 ) ;
V_42 -> V_49 = NULL ;
}
return V_99 ;
}
static int F_50 ( struct V_101 * V_102 ,
const struct V_103 * V_104 )
{
int V_105 ;
struct V_8 * V_9 = F_51 ( V_102 ) ;
struct V_106 * V_107 = V_102 -> V_108 ;
struct V_4 * V_5 = NULL ;
struct V_73 * V_74 = NULL ;
struct V_109 * V_110 ;
int V_111 ;
F_3 ( V_64 , L_33 , V_63 ) ;
if ( ( F_52 ( V_9 -> V_112 . V_113 ) != V_114 ) ||
( F_52 ( V_9 -> V_112 . V_115 ) != V_116 ) ) {
F_3 ( V_64 , L_34 ,
F_52 ( V_9 -> V_112 . V_113 ) ,
F_52 ( V_9 -> V_112 . V_115 ) ) ;
return - V_88 ;
}
if ( V_107 -> V_117 . V_118 != 0 ) {
F_3 ( V_64 , L_35 ,
V_107 -> V_117 . V_118 ) ;
return - V_88 ;
}
if ( V_107 -> V_117 . V_119 != 0 ) {
F_53 ( & V_9 -> V_18 , L_36 ,
V_107 -> V_117 . V_119 ) ;
return - V_88 ;
}
if ( V_107 -> V_117 . V_120 != 255 ) {
F_53 ( & V_9 -> V_18 , L_37 ,
V_107 -> V_117 . V_120 ) ;
return - V_88 ;
}
F_54 ( & V_9 -> V_18 , L_38 , V_63 ) ;
V_5 = F_55 ( V_121 , 1 , 1 , 0 , V_122 , V_123 ) ;
if ( ! V_5 )
return - V_88 ;
V_74 = V_5 -> V_10 . V_11 ;
F_56 ( V_9 ) ;
V_74 -> V_9 = V_9 ;
V_74 -> V_102 = V_102 ;
V_5 -> V_18 = & V_102 -> V_18 ;
F_57 ( V_102 , V_5 ) ;
V_110 = & V_107 -> V_110 [ 0 ] . V_117 ;
V_111 = F_52 ( V_110 -> V_124 ) ;
V_74 -> V_83 = V_111 ;
V_74 -> V_85 = F_58 ( V_110 ) ;
V_74 -> V_97 = F_44 ( V_111 , V_95 ) ;
if ( ! V_74 -> V_97 ) {
F_7 ( V_5 -> V_18 , L_39 ) ;
V_105 = - V_96 ;
goto error;
}
V_74 -> V_84 = F_59 ( 0 , V_95 ) ;
if ( ! V_74 -> V_84 ) {
F_7 ( V_5 -> V_18 , L_40 ) ;
V_105 = - V_96 ;
goto error;
}
V_110 = & V_107 -> V_110 [ 1 ] . V_117 ;
V_74 -> V_48 = 0 ;
V_74 -> V_98 = F_59 ( 0 , V_95 ) ;
if ( ! V_74 -> V_98 ) {
F_7 ( V_5 -> V_18 , L_41 ) ;
V_105 = - V_96 ;
goto error;
}
V_111 = F_52 ( V_110 -> V_124 ) ;
V_74 -> V_125 = V_111 ;
V_74 -> V_62 = F_44 ( V_111 , V_95 ) ;
if ( ! V_74 -> V_62 ) {
F_7 ( V_5 -> V_18 , L_42 ) ;
V_105 = - V_96 ;
goto error;
}
F_60 ( V_74 -> V_98 , V_9 ,
F_61 ( V_9 , F_58 ( V_110 ) ) ,
V_74 -> V_62 , V_111 ,
F_18 ,
V_5 , V_110 -> V_126 ) ;
V_105 = F_26 ( V_74 -> V_98 , V_95 ) ;
if ( V_105 ) {
F_7 ( V_5 -> V_18 , L_43 , - V_105 ) ;
goto error;
}
if ( V_127 == V_128 )
V_5 -> V_89 = V_90 ;
V_105 = F_62 ( V_5 ) ;
if ( V_105 < 0 ) {
F_42 ( & V_5 -> V_70 ) ;
goto error;
}
return 0 ;
error:
F_63 ( V_74 -> V_98 ) ;
F_29 ( V_74 -> V_97 ) ;
F_64 ( V_74 -> V_84 ) ;
F_29 ( V_74 -> V_62 ) ;
F_64 ( V_74 -> V_98 ) ;
F_57 ( V_102 , NULL ) ;
V_74 -> V_98 = V_74 -> V_84 = NULL ;
V_74 -> V_62 = V_74 -> V_97 = NULL ;
F_65 ( V_74 -> V_9 ) ;
V_74 -> V_9 = NULL ;
V_74 -> V_102 = NULL ;
F_66 ( V_5 ) ;
return V_105 ;
}
static void F_67 ( struct V_101 * V_102 )
{
struct V_4 * V_5 ;
struct V_73 * V_74 ;
V_5 = F_68 ( V_102 ) ;
V_74 = V_5 -> V_10 . V_11 ;
F_54 ( V_5 -> V_18 , L_44 ) ;
F_63 ( V_74 -> V_98 ) ;
F_69 ( V_5 ) ;
F_57 ( V_102 , NULL ) ;
F_42 ( & V_5 -> V_70 ) ;
F_63 ( V_74 -> V_84 ) ;
F_29 ( V_74 -> V_97 ) ;
F_64 ( V_74 -> V_84 ) ;
F_29 ( V_74 -> V_62 ) ;
F_64 ( V_74 -> V_98 ) ;
V_74 -> V_98 = V_74 -> V_84 = NULL ;
V_74 -> V_62 = V_74 -> V_97 = NULL ;
F_65 ( V_74 -> V_9 ) ;
V_74 -> V_102 = NULL ;
V_74 -> V_9 = NULL ;
V_5 -> V_18 = NULL ;
F_66 ( V_5 ) ;
}
static int F_70 ( struct V_101 * V_129 , T_4 V_130 )
{
struct V_4 * V_5 = F_68 ( V_129 ) ;
V_5 -> V_68 = 0 ;
F_63 ( V_5 -> V_10 . V_11 -> V_98 ) ;
F_42 ( & V_5 -> V_70 ) ;
F_63 ( V_5 -> V_10 . V_11 -> V_84 ) ;
F_3 ( V_131 , L_45 ) ;
return 0 ;
}
static int F_71 ( struct V_101 * V_129 )
{
struct V_4 * V_5 = F_68 ( V_129 ) ;
int V_132 ;
V_5 -> V_68 = 1 ;
V_132 = F_26 ( V_5 -> V_10 . V_11 -> V_98 , V_95 ) ;
if ( V_132 ) {
F_7 ( V_5 -> V_18 , L_46 , - V_132 ) ;
return V_132 ;
}
F_3 ( V_131 , L_47 ) ;
return 0 ;
}
static int F_72 ( struct V_101 * V_129 )
{
return F_70 ( V_129 , V_133 ) ;
}
static int T_5 F_73 ( void )
{
int V_134 ;
V_121 = F_74 ( V_135 , V_136 ,
V_123 , V_137 ,
& V_138 , V_139 ) ;
if ( V_121 == NULL ) {
V_134 = - V_96 ;
goto error;
}
V_134 = F_75 ( & V_140 ) ;
if ( V_134 < 0 ) {
F_25 ( L_48 , - V_134 ) ;
goto error;
}
F_76 ( V_141 L_49 ) ;
return 0 ;
error:
if ( V_121 )
F_77 ( V_121 ) ;
V_121 = NULL ;
return V_134 ;
}
static void T_6 F_78 ( void )
{
int V_142 ;
F_79 ( V_121 ) ;
for ( V_142 = 0 ; V_142 < V_121 -> V_143 ; V_142 ++ )
F_80 ( V_121 -> V_5 + V_142 ) ;
F_81 ( & V_140 ) ;
F_77 ( V_121 ) ;
V_121 = NULL ;
}
