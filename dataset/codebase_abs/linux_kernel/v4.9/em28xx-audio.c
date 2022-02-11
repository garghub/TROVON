static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( L_1 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 . V_5 ; V_3 ++ ) {
struct V_6 * V_6 = V_2 -> V_4 . V_6 [ V_3 ] ;
if ( ! F_3 () )
F_4 ( V_6 ) ;
else
F_5 ( V_6 ) ;
}
return 0 ;
}
static void F_6 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_7 ;
int V_3 ;
unsigned int V_8 ;
int V_9 = 0 ;
int V_10 ;
unsigned char * V_11 ;
unsigned int V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
if ( V_2 -> V_17 ) {
F_2 ( L_2 , V_6 -> V_10 ) ;
F_7 ( & V_2 -> V_4 . V_18 , 0 ) ;
return;
}
switch ( V_6 -> V_10 ) {
case 0 :
case - V_19 :
break;
case - V_20 :
case - V_21 :
case - V_22 :
return;
default:
F_2 ( L_3 , V_6 -> V_10 ) ;
break;
}
if ( F_8 ( & V_2 -> V_4 . V_18 ) == 0 )
return;
if ( V_2 -> V_4 . V_23 ) {
V_14 = V_2 -> V_4 . V_23 ;
V_16 = V_14 -> V_16 ;
V_12 = V_16 -> V_24 >> 3 ;
for ( V_3 = 0 ; V_3 < V_6 -> V_25 ; V_3 ++ ) {
int V_26 =
V_6 -> V_27 [ V_3 ] . V_28 / V_12 ;
V_11 = ( unsigned char * ) V_6 -> V_29 +
V_6 -> V_27 [ V_3 ] . V_30 ;
if ( ! V_26 )
continue;
V_8 = V_2 -> V_4 . V_31 ;
if ( V_8 + V_26 >= V_16 -> V_32 ) {
unsigned int V_33 =
V_16 -> V_32 - V_8 ;
memcpy ( V_16 -> V_34 + V_8 * V_12 , V_11 ,
V_33 * V_12 ) ;
memcpy ( V_16 -> V_34 , V_11 + V_33 * V_12 ,
V_26 * V_12 - V_33 * V_12 ) ;
} else {
memcpy ( V_16 -> V_34 + V_8 * V_12 , V_11 ,
V_26 * V_12 ) ;
}
F_9 ( V_14 ) ;
V_2 -> V_4 . V_31 += V_26 ;
if ( V_2 -> V_4 . V_31 >=
V_16 -> V_32 )
V_2 -> V_4 . V_31 -=
V_16 -> V_32 ;
V_2 -> V_4 . V_35 += V_26 ;
if ( V_2 -> V_4 . V_35 >=
V_16 -> V_36 ) {
V_2 -> V_4 . V_35 -=
V_16 -> V_36 ;
V_9 = 1 ;
}
F_10 ( V_14 ) ;
}
if ( V_9 )
F_11 ( V_14 ) ;
}
V_6 -> V_10 = 0 ;
V_10 = F_12 ( V_6 , V_37 ) ;
if ( V_10 < 0 )
F_13 ( L_4 ,
V_10 ) ;
return;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_3 , V_38 ;
F_2 ( L_5 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 . V_5 ; V_3 ++ ) {
memset ( V_2 -> V_4 . V_29 [ V_3 ] , 0x80 ,
V_2 -> V_4 . V_6 [ V_3 ] -> V_39 ) ;
V_38 = F_12 ( V_2 -> V_4 . V_6 [ V_3 ] , V_37 ) ;
if ( V_38 ) {
F_13 ( L_6 ,
V_38 ) ;
F_1 ( V_2 ) ;
F_7 ( & V_2 -> V_4 . V_18 , 0 ) ;
return V_38 ;
}
}
return 0 ;
}
static int F_15 ( struct V_13 * V_40 ,
T_1 V_41 )
{
struct V_15 * V_16 = V_40 -> V_16 ;
F_2 ( L_7 ) ;
if ( V_16 -> V_34 ) {
if ( V_16 -> V_42 > V_41 )
return 0 ;
F_16 ( V_16 -> V_34 ) ;
}
V_16 -> V_34 = F_17 ( V_41 ) ;
if ( ! V_16 -> V_34 )
return - V_43 ;
V_16 -> V_42 = V_41 ;
return 0 ;
}
static int F_18 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_19 ( V_14 ) ;
struct V_15 * V_16 = V_14 -> V_16 ;
int V_44 , V_45 = 0 ;
if ( ! V_2 ) {
F_20 ( L_8
L_9 ) ;
return - V_46 ;
}
if ( V_2 -> V_17 )
return - V_46 ;
F_2 ( L_10 ) ;
V_44 = ! ! ( V_14 -> V_47 & V_48 ) ;
if ( V_44 ) {
if ( ! F_21 ( & V_2 -> V_49 ) )
return - V_50 ;
} else
F_22 ( & V_2 -> V_49 ) ;
V_16 -> V_51 = V_52 ;
if ( V_2 -> V_4 . V_53 == 0 ) {
if ( V_2 -> V_54 == 0 || V_2 -> V_55 ) {
if ( V_2 -> V_55 )
V_2 -> V_54 = 1 ;
else
V_2 -> V_54 = 7 ;
F_2 ( L_11 ,
V_2 -> V_56 , V_2 -> V_54 ) ;
F_23 ( V_2 -> V_57 , V_2 -> V_56 , V_2 -> V_54 ) ;
}
V_2 -> V_58 = 0 ;
V_45 = F_24 ( V_2 ) ;
if ( V_45 < 0 )
goto V_59;
}
F_25 ( & V_2 -> V_60 ) ;
V_2 -> V_4 . V_53 ++ ;
F_26 ( & V_2 -> V_49 ) ;
F_27 ( V_16 , V_61 ) ;
F_28 ( V_16 , V_62 ,
V_2 -> V_4 . V_63 * 95 / 100 ,
V_2 -> V_4 . V_63 * 105 / 100 ) ;
V_2 -> V_4 . V_23 = V_14 ;
return 0 ;
V_59:
F_26 ( & V_2 -> V_49 ) ;
F_20 ( L_12 ) ;
return V_45 ;
}
static int F_29 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_19 ( V_14 ) ;
F_2 ( L_13 ) ;
V_2 -> V_58 = 1 ;
F_22 ( & V_2 -> V_49 ) ;
V_2 -> V_4 . V_53 -- ;
if ( F_8 ( & V_2 -> V_4 . V_18 ) > 0 ) {
F_7 ( & V_2 -> V_4 . V_18 , 0 ) ;
F_30 ( & V_2 -> V_4 . V_64 ) ;
}
F_24 ( V_2 ) ;
if ( V_14 -> V_16 -> V_34 ) {
F_2 ( L_14 ) ;
F_16 ( V_14 -> V_16 -> V_34 ) ;
V_14 -> V_16 -> V_34 = NULL ;
}
F_26 ( & V_2 -> V_49 ) ;
F_31 ( & V_2 -> V_60 , V_65 ) ;
return 0 ;
}
static int F_32 ( struct V_13 * V_14 ,
struct V_66 * V_67 )
{
int V_45 ;
struct V_1 * V_2 = F_19 ( V_14 ) ;
if ( V_2 -> V_17 )
return - V_46 ;
F_2 ( L_15 ) ;
V_45 = F_15 ( V_14 ,
F_33 ( V_67 ) ) ;
if ( V_45 < 0 )
return V_45 ;
#if 0
unsigned int channels, rate, format;
format = params_format(hw_params);
rate = params_rate(hw_params);
channels = params_channels(hw_params);
#endif
return 0 ;
}
static int F_34 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_19 ( V_14 ) ;
struct V_68 * V_4 = & V_2 -> V_4 ;
F_2 ( L_16 ) ;
if ( F_8 ( & V_4 -> V_18 ) > 0 ) {
F_7 ( & V_4 -> V_18 , 0 ) ;
F_30 ( & V_4 -> V_64 ) ;
}
return 0 ;
}
static int F_35 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_19 ( V_14 ) ;
if ( V_2 -> V_17 )
return - V_46 ;
V_2 -> V_4 . V_31 = 0 ;
V_2 -> V_4 . V_35 = 0 ;
return 0 ;
}
static void F_36 ( struct V_69 * V_70 )
{
struct V_68 * V_4 =
F_37 ( V_70 , struct V_68 , V_64 ) ;
struct V_1 * V_2 = F_37 ( V_4 , struct V_1 , V_4 ) ;
if ( F_8 ( & V_4 -> V_18 ) ) {
F_2 ( L_17 ) ;
F_14 ( V_2 ) ;
} else {
F_2 ( L_18 ) ;
F_1 ( V_2 ) ;
}
}
static int F_38 ( struct V_13 * V_14 ,
int V_71 )
{
struct V_1 * V_2 = F_19 ( V_14 ) ;
int V_72 = 0 ;
if ( V_2 -> V_17 )
return - V_46 ;
switch ( V_71 ) {
case V_73 :
case V_74 :
case V_75 :
F_7 ( & V_2 -> V_4 . V_18 , 1 ) ;
break;
case V_76 :
case V_77 :
case V_78 :
F_7 ( & V_2 -> V_4 . V_18 , 0 ) ;
break;
default:
V_72 = - V_79 ;
}
F_30 ( & V_2 -> V_4 . V_64 ) ;
return V_72 ;
}
static T_2 F_39 ( struct V_13
* V_14 )
{
unsigned long V_80 ;
struct V_1 * V_2 ;
T_2 V_81 ;
V_2 = F_19 ( V_14 ) ;
if ( V_2 -> V_17 )
return V_82 ;
F_40 ( & V_2 -> V_4 . V_83 , V_80 ) ;
V_81 = V_2 -> V_4 . V_31 ;
F_41 ( & V_2 -> V_4 . V_83 , V_80 ) ;
return V_81 ;
}
static struct V_84 * F_42 ( struct V_13 * V_40 ,
unsigned long V_30 )
{
void * V_85 = V_40 -> V_16 -> V_34 + V_30 ;
return F_43 ( V_85 ) ;
}
static int F_44 ( struct V_86 * V_87 ,
struct V_88 * V_89 )
{
struct V_1 * V_2 = F_45 ( V_87 ) ;
if ( V_2 -> V_17 )
return - V_46 ;
V_89 -> type = V_90 ;
V_89 -> V_91 = 2 ;
V_89 -> V_92 . integer . V_93 = 0 ;
V_89 -> V_92 . integer . V_94 = 0x1f ;
return 0 ;
}
static int F_46 ( struct V_86 * V_87 ,
struct V_95 * V_92 )
{
struct V_1 * V_2 = F_45 ( V_87 ) ;
struct V_13 * V_14 = V_2 -> V_4 . V_23 ;
T_3 V_96 = ( 0x1f - ( V_92 -> V_92 . integer . V_92 [ 0 ] & 0x1f ) ) |
( 0x1f - ( V_92 -> V_92 . integer . V_92 [ 1 ] & 0x1f ) ) << 8 ;
int V_44 = 0 ;
int V_97 ;
if ( V_2 -> V_17 )
return - V_46 ;
if ( V_14 )
V_44 = ! ! ( V_14 -> V_47 & V_48 ) ;
if ( V_44 ) {
if ( ! F_21 ( & V_2 -> V_49 ) )
return - V_50 ;
} else
F_22 ( & V_2 -> V_49 ) ;
V_97 = F_47 ( V_2 , V_87 -> V_98 ) ;
if ( V_97 < 0 )
goto V_59;
V_96 |= V_97 & 0x8000 ;
V_97 = F_48 ( V_2 , V_87 -> V_98 , V_96 ) ;
if ( V_97 < 0 )
goto V_59;
F_2 ( L_19 ,
( V_96 & 0x8000 ) ? L_20 : L_21 ,
0x1f - ( ( V_96 >> 8 ) & 0x1f ) , 0x1f - ( V_96 & 0x1f ) ,
V_96 , ( int ) V_87 -> V_98 ) ;
V_59:
F_26 ( & V_2 -> V_49 ) ;
return V_97 ;
}
static int F_49 ( struct V_86 * V_87 ,
struct V_95 * V_92 )
{
struct V_1 * V_2 = F_45 ( V_87 ) ;
struct V_13 * V_14 = V_2 -> V_4 . V_23 ;
int V_44 = 0 ;
int V_96 ;
if ( V_2 -> V_17 )
return - V_46 ;
if ( V_14 )
V_44 = ! ! ( V_14 -> V_47 & V_48 ) ;
if ( V_44 ) {
if ( ! F_21 ( & V_2 -> V_49 ) )
return - V_50 ;
} else
F_22 ( & V_2 -> V_49 ) ;
V_96 = F_47 ( V_2 , V_87 -> V_98 ) ;
F_26 ( & V_2 -> V_49 ) ;
if ( V_96 < 0 )
return V_96 ;
F_2 ( L_22 ,
( V_96 & 0x8000 ) ? L_20 : L_21 ,
0x1f - ( ( V_96 >> 8 ) & 0x1f ) , 0x1f - ( V_96 & 0x1f ) ,
V_96 , ( int ) V_87 -> V_98 ) ;
V_92 -> V_92 . integer . V_92 [ 0 ] = 0x1f - ( V_96 & 0x1f ) ;
V_92 -> V_92 . integer . V_92 [ 1 ] = 0x1f - ( ( V_96 << 8 ) & 0x1f ) ;
return 0 ;
}
static int F_50 ( struct V_86 * V_87 ,
struct V_95 * V_92 )
{
struct V_1 * V_2 = F_45 ( V_87 ) ;
T_3 V_96 = V_92 -> V_92 . integer . V_92 [ 0 ] ;
struct V_13 * V_14 = V_2 -> V_4 . V_23 ;
int V_44 = 0 ;
int V_97 ;
if ( V_2 -> V_17 )
return - V_46 ;
if ( V_14 )
V_44 = ! ! ( V_14 -> V_47 & V_48 ) ;
if ( V_44 ) {
if ( ! F_21 ( & V_2 -> V_49 ) )
return - V_50 ;
} else
F_22 ( & V_2 -> V_49 ) ;
V_97 = F_47 ( V_2 , V_87 -> V_98 ) ;
if ( V_97 < 0 )
goto V_59;
if ( V_96 )
V_97 &= 0x1f1f ;
else
V_97 |= 0x8000 ;
V_97 = F_48 ( V_2 , V_87 -> V_98 , V_97 ) ;
if ( V_97 < 0 )
goto V_59;
F_2 ( L_19 ,
( V_96 & 0x8000 ) ? L_20 : L_21 ,
0x1f - ( ( V_96 >> 8 ) & 0x1f ) , 0x1f - ( V_96 & 0x1f ) ,
V_96 , ( int ) V_87 -> V_98 ) ;
V_59:
F_26 ( & V_2 -> V_49 ) ;
return V_97 ;
}
static int F_51 ( struct V_86 * V_87 ,
struct V_95 * V_92 )
{
struct V_1 * V_2 = F_45 ( V_87 ) ;
struct V_13 * V_14 = V_2 -> V_4 . V_23 ;
int V_44 = 0 ;
int V_96 ;
if ( V_2 -> V_17 )
return - V_46 ;
if ( V_14 )
V_44 = ! ! ( V_14 -> V_47 & V_48 ) ;
if ( V_44 ) {
if ( ! F_21 ( & V_2 -> V_49 ) )
return - V_50 ;
} else
F_22 ( & V_2 -> V_49 ) ;
V_96 = F_47 ( V_2 , V_87 -> V_98 ) ;
F_26 ( & V_2 -> V_49 ) ;
if ( V_96 < 0 )
return V_96 ;
if ( V_96 & 0x8000 )
V_92 -> V_92 . integer . V_92 [ 0 ] = 0 ;
else
V_92 -> V_92 . integer . V_92 [ 0 ] = 1 ;
F_2 ( L_22 ,
( V_96 & 0x8000 ) ? L_20 : L_21 ,
0x1f - ( ( V_96 >> 8 ) & 0x1f ) , 0x1f - ( V_96 & 0x1f ) ,
V_96 , ( int ) V_87 -> V_98 ) ;
return 0 ;
}
static int F_52 ( struct V_99 * V_100 , struct V_1 * V_2 ,
char * V_101 , int V_102 )
{
int V_59 ;
char V_103 [ 44 ] ;
struct V_86 * V_104 ;
struct V_105 V_106 ;
memset ( & V_106 , 0 , sizeof( V_106 ) ) ;
V_106 . V_107 = V_108 ,
V_106 . V_98 = V_102 ,
V_106 . V_101 = V_103 ,
sprintf ( V_103 , L_23 , V_101 ) ;
V_106 . V_109 = F_51 ;
V_106 . V_110 = F_50 ;
V_106 . V_89 = V_111 ;
V_104 = F_53 ( & V_106 , V_2 ) ;
V_59 = F_54 ( V_100 , V_104 ) ;
if ( V_59 < 0 )
return V_59 ;
F_2 ( L_24 ,
V_103 , V_102 ) ;
memset ( & V_106 , 0 , sizeof( V_106 ) ) ;
V_106 . V_107 = V_108 ,
V_106 . V_98 = V_102 ,
V_106 . V_101 = V_103 ,
sprintf ( V_103 , L_25 , V_101 ) ;
V_106 . V_109 = F_49 ;
V_106 . V_110 = F_46 ;
V_106 . V_89 = F_44 ;
V_106 . V_112 . V_113 = V_114 ,
V_104 = F_53 ( & V_106 , V_2 ) ;
V_59 = F_54 ( V_100 , V_104 ) ;
if ( V_59 < 0 )
return V_59 ;
F_2 ( L_24 ,
V_103 , V_102 ) ;
return 0 ;
}
static void F_55 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 . V_5 ; V_3 ++ ) {
struct V_6 * V_6 = V_2 -> V_4 . V_6 [ V_3 ] ;
if ( ! V_6 )
continue;
F_56 ( V_2 -> V_57 , V_6 -> V_39 ,
V_2 -> V_4 . V_29 [ V_3 ] ,
V_6 -> V_115 ) ;
F_57 ( V_6 ) ;
}
F_58 ( V_2 -> V_4 . V_6 ) ;
F_58 ( V_2 -> V_4 . V_29 ) ;
V_2 -> V_4 . V_5 = 0 ;
}
static int F_59 ( struct V_116 * V_57 ,
struct V_117 * V_118 )
{
int V_41 = F_60 ( V_118 -> V_119 ) ;
if ( V_57 -> V_120 == V_121 )
return ( V_41 & 0x7ff ) * ( 1 + ( ( ( V_41 ) >> 11 ) & 0x03 ) ) ;
return V_41 & 0x7ff ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_122 * V_123 ;
struct V_117 * V_118 , * V_124 = NULL ;
int V_3 , V_125 , V_126 , V_5 , V_127 ;
int V_128 , V_129 ;
T_4 V_54 ;
if ( V_2 -> V_56 )
V_54 = 1 ;
else
V_54 = 7 ;
V_123 = F_62 ( V_2 -> V_57 , V_2 -> V_56 ) ;
if ( V_123 -> V_130 <= V_54 ) {
F_13 ( L_26 ,
V_2 -> V_56 , V_54 ) ;
return - V_46 ;
}
for ( V_3 = 0 ; V_3 < V_123 -> V_131 [ V_54 ] . V_132 . V_133 ; V_3 ++ ) {
V_118 = & V_123 -> V_131 [ V_54 ] . V_134 [ V_3 ] . V_132 ;
if ( ! F_63 ( V_118 ) )
continue;
if ( V_118 -> V_135 == V_136 ) {
V_124 = V_118 ;
break;
}
}
if ( ! V_124 ) {
F_13 ( L_27 ) ;
return - V_46 ;
}
V_125 = F_59 ( V_2 -> V_57 , V_124 ) ;
V_126 = 1 << ( V_124 -> V_137 - 1 ) ;
F_64 ( L_28 ,
V_136 , F_65 ( V_2 -> V_57 -> V_120 ) ,
V_2 -> V_56 , V_54 ,
V_126 ,
V_125 ) ;
V_129 = F_66 ( 48000 * 2 * 2 , 125 * V_126 ) ;
V_5 = F_66 ( V_129 , V_125 ) ;
if ( V_5 > V_138 )
V_5 = V_138 ;
V_128 = V_129 / V_5 ;
V_127 = V_139 ;
if ( V_128 > V_125 * V_127 )
V_127 = F_66 ( V_128 , V_125 ) ;
F_64 ( L_29 ,
V_5 , V_127 , V_128 ) ;
V_2 -> V_4 . V_63 = V_128 * V_127 ;
V_2 -> V_4 . V_29 = F_67 ( V_5 ,
sizeof( * V_2 -> V_4 . V_29 ) ,
V_37 ) ;
if ( ! V_2 -> V_4 . V_29 ) {
return - V_43 ;
}
V_2 -> V_4 . V_6 = F_67 ( V_5 , sizeof( * V_2 -> V_4 . V_6 ) , V_37 ) ;
if ( ! V_2 -> V_4 . V_6 ) {
F_58 ( V_2 -> V_4 . V_29 ) ;
return - V_43 ;
}
V_2 -> V_4 . V_5 = V_5 ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ ) {
struct V_6 * V_6 ;
int V_140 , V_141 ;
void * V_142 ;
V_6 = F_68 ( V_127 , V_37 ) ;
if ( ! V_6 ) {
F_55 ( V_2 ) ;
return - V_43 ;
}
V_2 -> V_4 . V_6 [ V_3 ] = V_6 ;
V_142 = F_69 ( V_2 -> V_57 , V_127 * V_125 , V_37 ,
& V_6 -> V_115 ) ;
if ( ! V_142 ) {
F_13 ( L_30 ) ;
F_55 ( V_2 ) ;
return - V_43 ;
}
V_2 -> V_4 . V_29 [ V_3 ] = V_142 ;
V_6 -> V_2 = V_2 -> V_57 ;
V_6 -> V_7 = V_2 ;
V_6 -> V_143 = F_70 ( V_2 -> V_57 , V_136 ) ;
V_6 -> V_144 = V_145 | V_146 ;
V_6 -> V_29 = V_142 ;
V_6 -> V_126 = V_126 ;
V_6 -> V_147 = F_6 ;
V_6 -> V_25 = V_127 ;
V_6 -> V_39 = V_125 * V_127 ;
for ( V_140 = V_141 = 0 ; V_140 < V_127 ; V_140 ++ , V_141 += V_125 ) {
V_6 -> V_27 [ V_140 ] . V_30 = V_141 ;
V_6 -> V_27 [ V_140 ] . V_26 = V_125 ;
}
}
return 0 ;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_68 * V_4 = & V_2 -> V_4 ;
struct V_148 * V_149 ;
struct V_99 * V_100 ;
static int V_150 ;
int V_59 ;
if ( V_2 -> V_151 != V_152 ) {
return 0 ;
}
F_64 ( L_31 ) ;
F_25 ( & V_2 -> V_60 ) ;
F_72 ( V_153 L_32
L_33 ) ;
F_72 ( V_153
L_34 ) ;
V_59 = F_73 ( & V_2 -> V_57 -> V_2 , V_154 [ V_150 ] , L_35 ,
V_155 , 0 , & V_100 ) ;
if ( V_59 < 0 )
return V_59 ;
F_74 ( & V_4 -> V_83 ) ;
V_4 -> V_156 = V_100 ;
V_4 -> V_57 = V_2 -> V_57 ;
V_59 = F_75 ( V_100 , L_35 , 0 , 0 , 1 , & V_149 ) ;
if ( V_59 < 0 )
goto V_157;
F_76 ( V_149 , V_158 , & V_159 ) ;
V_149 -> V_160 = 0 ;
V_149 -> V_161 = V_2 ;
strcpy ( V_149 -> V_101 , L_36 ) ;
strcpy ( V_100 -> V_162 , L_37 ) ;
strcpy ( V_100 -> V_163 , L_35 ) ;
strcpy ( V_100 -> V_164 , L_38 ) ;
F_77 ( & V_4 -> V_64 , F_36 ) ;
if ( V_2 -> V_165 . V_166 != V_167 ) {
F_52 ( V_100 , V_2 , L_39 , V_168 ) ;
F_52 ( V_100 , V_2 , L_40 , V_169 ) ;
F_52 ( V_100 , V_2 , L_41 , V_170 ) ;
F_52 ( V_100 , V_2 , L_42 , V_171 ) ;
F_52 ( V_100 , V_2 , L_43 , V_172 ) ;
F_52 ( V_100 , V_2 , L_44 , V_173 ) ;
F_52 ( V_100 , V_2 , L_45 , V_174 ) ;
F_52 ( V_100 , V_2 , L_46 , V_175 ) ;
F_52 ( V_100 , V_2 , L_47 , V_176 ) ;
F_52 ( V_100 , V_2 , L_48 , V_177 ) ;
F_52 ( V_100 , V_2 , L_49 , V_178 ) ;
F_52 ( V_100 , V_2 , L_50 , V_179 ) ;
}
V_59 = F_61 ( V_2 ) ;
if ( V_59 )
goto V_157;
V_59 = F_78 ( V_100 ) ;
if ( V_59 < 0 )
goto V_180;
F_64 ( L_51 ) ;
return 0 ;
V_180:
F_55 ( V_2 ) ;
V_157:
F_79 ( V_100 ) ;
V_4 -> V_156 = NULL ;
return V_59 ;
}
static int F_80 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return 0 ;
if ( V_2 -> V_151 != V_152 ) {
return 0 ;
}
F_64 ( L_52 ) ;
if ( V_2 -> V_4 . V_156 ) {
F_81 ( V_2 -> V_4 . V_156 ) ;
F_82 ( & V_2 -> V_4 . V_64 ) ;
F_55 ( V_2 ) ;
F_79 ( V_2 -> V_4 . V_156 ) ;
V_2 -> V_4 . V_156 = NULL ;
}
F_31 ( & V_2 -> V_60 , V_65 ) ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return 0 ;
if ( V_2 -> V_151 != V_152 )
return 0 ;
F_64 ( L_53 ) ;
F_1 ( V_2 ) ;
F_7 ( & V_2 -> V_4 . V_18 , 0 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return 0 ;
if ( V_2 -> V_151 != V_152 )
return 0 ;
F_64 ( L_54 ) ;
F_30 ( & V_2 -> V_4 . V_64 ) ;
return 0 ;
}
static int T_5 F_85 ( void )
{
return F_86 ( & V_181 ) ;
}
static void T_6 F_87 ( void )
{
F_88 ( & V_181 ) ;
}
