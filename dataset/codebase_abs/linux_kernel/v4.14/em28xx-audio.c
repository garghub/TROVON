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
F_2 ( L_2 ,
V_6 -> V_10 ) ;
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
F_13 ( & V_2 -> V_38 -> V_2 ,
L_4 ,
V_10 ) ;
return;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_3 , V_39 ;
F_2 ( L_5 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 . V_5 ; V_3 ++ ) {
memset ( V_2 -> V_4 . V_29 [ V_3 ] , 0x80 ,
V_2 -> V_4 . V_6 [ V_3 ] -> V_40 ) ;
V_39 = F_12 ( V_2 -> V_4 . V_6 [ V_3 ] , V_37 ) ;
if ( V_39 ) {
F_13 ( & V_2 -> V_38 -> V_2 ,
L_6 ,
V_39 ) ;
F_1 ( V_2 ) ;
F_7 ( & V_2 -> V_4 . V_18 , 0 ) ;
return V_39 ;
}
}
return 0 ;
}
static int F_15 ( struct V_13 * V_41 ,
T_1 V_42 )
{
struct V_1 * V_2 = F_16 ( V_41 ) ;
struct V_15 * V_16 = V_41 -> V_16 ;
F_2 ( L_7 ) ;
if ( V_16 -> V_34 ) {
if ( V_16 -> V_43 > V_42 )
return 0 ;
F_17 ( V_16 -> V_34 ) ;
}
V_16 -> V_34 = F_18 ( V_42 ) ;
if ( ! V_16 -> V_34 )
return - V_44 ;
V_16 -> V_43 = V_42 ;
return 0 ;
}
static int F_19 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_16 ( V_14 ) ;
struct V_15 * V_16 = V_14 -> V_16 ;
int V_45 , V_46 = 0 ;
if ( ! V_2 ) {
F_20 ( L_8 ) ;
return - V_47 ;
}
if ( V_2 -> V_17 )
return - V_47 ;
F_2 ( L_9 ) ;
V_45 = ! ! ( V_14 -> V_48 & V_49 ) ;
if ( V_45 ) {
if ( ! F_21 ( & V_2 -> V_50 ) )
return - V_51 ;
} else
F_22 ( & V_2 -> V_50 ) ;
V_16 -> V_52 = V_53 ;
if ( V_2 -> V_4 . V_54 == 0 ) {
if ( V_2 -> V_55 == 0 || V_2 -> V_56 ) {
struct V_57 * V_58 = F_23 ( V_2 -> V_38 ) ;
if ( V_2 -> V_56 )
V_2 -> V_55 = 1 ;
else
V_2 -> V_55 = 7 ;
F_2 ( L_10 ,
V_2 -> V_59 , V_2 -> V_55 ) ;
F_24 ( V_58 , V_2 -> V_59 , V_2 -> V_55 ) ;
}
V_2 -> V_60 = 0 ;
V_46 = F_25 ( V_2 ) ;
if ( V_46 < 0 )
goto V_61;
}
F_26 ( & V_2 -> V_62 ) ;
V_2 -> V_4 . V_54 ++ ;
F_27 ( & V_2 -> V_50 ) ;
F_28 ( V_16 , V_63 ) ;
F_29 ( V_16 , V_64 ,
V_2 -> V_4 . V_65 * 95 / 100 ,
V_2 -> V_4 . V_65 * 105 / 100 ) ;
V_2 -> V_4 . V_23 = V_14 ;
return 0 ;
V_61:
F_27 ( & V_2 -> V_50 ) ;
F_13 ( & V_2 -> V_38 -> V_2 ,
L_11 ) ;
return V_46 ;
}
static int F_30 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_16 ( V_14 ) ;
F_2 ( L_12 ) ;
V_2 -> V_60 = 1 ;
F_22 ( & V_2 -> V_50 ) ;
V_2 -> V_4 . V_54 -- ;
if ( F_8 ( & V_2 -> V_4 . V_18 ) > 0 ) {
F_7 ( & V_2 -> V_4 . V_18 , 0 ) ;
F_31 ( & V_2 -> V_4 . V_66 ) ;
}
F_25 ( V_2 ) ;
if ( V_14 -> V_16 -> V_34 ) {
F_2 ( L_13 ) ;
F_17 ( V_14 -> V_16 -> V_34 ) ;
V_14 -> V_16 -> V_34 = NULL ;
}
F_27 ( & V_2 -> V_50 ) ;
F_32 ( & V_2 -> V_62 , V_67 ) ;
return 0 ;
}
static int F_33 ( struct V_13 * V_14 ,
struct V_68 * V_69 )
{
int V_46 ;
struct V_1 * V_2 = F_16 ( V_14 ) ;
if ( V_2 -> V_17 )
return - V_47 ;
F_2 ( L_14 ) ;
V_46 = F_15 ( V_14 ,
F_34 ( V_69 ) ) ;
if ( V_46 < 0 )
return V_46 ;
#if 0
unsigned int channels, rate, format;
format = params_format(hw_params);
rate = params_rate(hw_params);
channels = params_channels(hw_params);
#endif
return 0 ;
}
static int F_35 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_16 ( V_14 ) ;
struct V_70 * V_4 = & V_2 -> V_4 ;
F_2 ( L_15 ) ;
if ( F_8 ( & V_4 -> V_18 ) > 0 ) {
F_7 ( & V_4 -> V_18 , 0 ) ;
F_31 ( & V_4 -> V_66 ) ;
}
return 0 ;
}
static int F_36 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_16 ( V_14 ) ;
if ( V_2 -> V_17 )
return - V_47 ;
V_2 -> V_4 . V_31 = 0 ;
V_2 -> V_4 . V_35 = 0 ;
return 0 ;
}
static void F_37 ( struct V_71 * V_72 )
{
struct V_70 * V_4 =
F_38 ( V_72 , struct V_70 , V_66 ) ;
struct V_1 * V_2 = F_38 ( V_4 , struct V_1 , V_4 ) ;
if ( F_8 ( & V_4 -> V_18 ) ) {
F_2 ( L_16 ) ;
F_14 ( V_2 ) ;
} else {
F_2 ( L_17 ) ;
F_1 ( V_2 ) ;
}
}
static int F_39 ( struct V_13 * V_14 ,
int V_73 )
{
struct V_1 * V_2 = F_16 ( V_14 ) ;
int V_74 = 0 ;
if ( V_2 -> V_17 )
return - V_47 ;
switch ( V_73 ) {
case V_75 :
case V_76 :
case V_77 :
F_7 ( & V_2 -> V_4 . V_18 , 1 ) ;
break;
case V_78 :
case V_79 :
case V_80 :
F_7 ( & V_2 -> V_4 . V_18 , 0 ) ;
break;
default:
V_74 = - V_81 ;
}
F_31 ( & V_2 -> V_4 . V_66 ) ;
return V_74 ;
}
static T_2 F_40 ( struct V_13
* V_14 )
{
unsigned long V_82 ;
struct V_1 * V_2 ;
T_2 V_83 ;
V_2 = F_16 ( V_14 ) ;
if ( V_2 -> V_17 )
return V_84 ;
F_41 ( & V_2 -> V_4 . V_85 , V_82 ) ;
V_83 = V_2 -> V_4 . V_31 ;
F_42 ( & V_2 -> V_4 . V_85 , V_82 ) ;
return V_83 ;
}
static struct V_86 * F_43 ( struct V_13 * V_41 ,
unsigned long V_30 )
{
void * V_87 = V_41 -> V_16 -> V_34 + V_30 ;
return F_44 ( V_87 ) ;
}
static int F_45 ( struct V_88 * V_89 ,
struct V_90 * V_91 )
{
struct V_1 * V_2 = F_46 ( V_89 ) ;
if ( V_2 -> V_17 )
return - V_47 ;
V_91 -> type = V_92 ;
V_91 -> V_93 = 2 ;
V_91 -> V_94 . integer . V_95 = 0 ;
V_91 -> V_94 . integer . V_96 = 0x1f ;
return 0 ;
}
static int F_47 ( struct V_88 * V_89 ,
struct V_97 * V_94 )
{
struct V_1 * V_2 = F_46 ( V_89 ) ;
struct V_13 * V_14 = V_2 -> V_4 . V_23 ;
T_3 V_98 = ( 0x1f - ( V_94 -> V_94 . integer . V_94 [ 0 ] & 0x1f ) ) |
( 0x1f - ( V_94 -> V_94 . integer . V_94 [ 1 ] & 0x1f ) ) << 8 ;
int V_45 = 0 ;
int V_99 ;
if ( V_2 -> V_17 )
return - V_47 ;
if ( V_14 )
V_45 = ! ! ( V_14 -> V_48 & V_49 ) ;
if ( V_45 ) {
if ( ! F_21 ( & V_2 -> V_50 ) )
return - V_51 ;
} else
F_22 ( & V_2 -> V_50 ) ;
V_99 = F_48 ( V_2 , V_89 -> V_100 ) ;
if ( V_99 < 0 )
goto V_61;
V_98 |= V_99 & 0x8000 ;
V_99 = F_49 ( V_2 , V_89 -> V_100 , V_98 ) ;
if ( V_99 < 0 )
goto V_61;
F_2 ( L_18 ,
( V_98 & 0x8000 ) ? L_19 : L_20 ,
0x1f - ( ( V_98 >> 8 ) & 0x1f ) , 0x1f - ( V_98 & 0x1f ) ,
V_98 , ( int ) V_89 -> V_100 ) ;
V_61:
F_27 ( & V_2 -> V_50 ) ;
return V_99 ;
}
static int F_50 ( struct V_88 * V_89 ,
struct V_97 * V_94 )
{
struct V_1 * V_2 = F_46 ( V_89 ) ;
struct V_13 * V_14 = V_2 -> V_4 . V_23 ;
int V_45 = 0 ;
int V_98 ;
if ( V_2 -> V_17 )
return - V_47 ;
if ( V_14 )
V_45 = ! ! ( V_14 -> V_48 & V_49 ) ;
if ( V_45 ) {
if ( ! F_21 ( & V_2 -> V_50 ) )
return - V_51 ;
} else
F_22 ( & V_2 -> V_50 ) ;
V_98 = F_48 ( V_2 , V_89 -> V_100 ) ;
F_27 ( & V_2 -> V_50 ) ;
if ( V_98 < 0 )
return V_98 ;
F_2 ( L_21 ,
( V_98 & 0x8000 ) ? L_19 : L_20 ,
0x1f - ( ( V_98 >> 8 ) & 0x1f ) , 0x1f - ( V_98 & 0x1f ) ,
V_98 , ( int ) V_89 -> V_100 ) ;
V_94 -> V_94 . integer . V_94 [ 0 ] = 0x1f - ( V_98 & 0x1f ) ;
V_94 -> V_94 . integer . V_94 [ 1 ] = 0x1f - ( ( V_98 >> 8 ) & 0x1f ) ;
return 0 ;
}
static int F_51 ( struct V_88 * V_89 ,
struct V_97 * V_94 )
{
struct V_1 * V_2 = F_46 ( V_89 ) ;
T_3 V_98 = V_94 -> V_94 . integer . V_94 [ 0 ] ;
struct V_13 * V_14 = V_2 -> V_4 . V_23 ;
int V_45 = 0 ;
int V_99 ;
if ( V_2 -> V_17 )
return - V_47 ;
if ( V_14 )
V_45 = ! ! ( V_14 -> V_48 & V_49 ) ;
if ( V_45 ) {
if ( ! F_21 ( & V_2 -> V_50 ) )
return - V_51 ;
} else
F_22 ( & V_2 -> V_50 ) ;
V_99 = F_48 ( V_2 , V_89 -> V_100 ) ;
if ( V_99 < 0 )
goto V_61;
if ( V_98 )
V_99 &= 0x1f1f ;
else
V_99 |= 0x8000 ;
V_99 = F_49 ( V_2 , V_89 -> V_100 , V_99 ) ;
if ( V_99 < 0 )
goto V_61;
F_2 ( L_18 ,
( V_98 & 0x8000 ) ? L_19 : L_20 ,
0x1f - ( ( V_98 >> 8 ) & 0x1f ) , 0x1f - ( V_98 & 0x1f ) ,
V_98 , ( int ) V_89 -> V_100 ) ;
V_61:
F_27 ( & V_2 -> V_50 ) ;
return V_99 ;
}
static int F_52 ( struct V_88 * V_89 ,
struct V_97 * V_94 )
{
struct V_1 * V_2 = F_46 ( V_89 ) ;
struct V_13 * V_14 = V_2 -> V_4 . V_23 ;
int V_45 = 0 ;
int V_98 ;
if ( V_2 -> V_17 )
return - V_47 ;
if ( V_14 )
V_45 = ! ! ( V_14 -> V_48 & V_49 ) ;
if ( V_45 ) {
if ( ! F_21 ( & V_2 -> V_50 ) )
return - V_51 ;
} else
F_22 ( & V_2 -> V_50 ) ;
V_98 = F_48 ( V_2 , V_89 -> V_100 ) ;
F_27 ( & V_2 -> V_50 ) ;
if ( V_98 < 0 )
return V_98 ;
if ( V_98 & 0x8000 )
V_94 -> V_94 . integer . V_94 [ 0 ] = 0 ;
else
V_94 -> V_94 . integer . V_94 [ 0 ] = 1 ;
F_2 ( L_21 ,
( V_98 & 0x8000 ) ? L_19 : L_20 ,
0x1f - ( ( V_98 >> 8 ) & 0x1f ) , 0x1f - ( V_98 & 0x1f ) ,
V_98 , ( int ) V_89 -> V_100 ) ;
return 0 ;
}
static int F_53 ( struct V_101 * V_102 , struct V_1 * V_2 ,
char * V_103 , int V_104 )
{
int V_61 ;
char V_105 [ 44 ] ;
struct V_88 * V_106 ;
struct V_107 V_108 ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_109 = V_110 ,
V_108 . V_100 = V_104 ,
V_108 . V_103 = V_105 ,
sprintf ( V_105 , L_22 , V_103 ) ;
V_108 . V_111 = F_52 ;
V_108 . V_112 = F_51 ;
V_108 . V_91 = V_113 ;
V_106 = F_54 ( & V_108 , V_2 ) ;
V_61 = F_55 ( V_102 , V_106 ) ;
if ( V_61 < 0 )
return V_61 ;
F_2 ( L_23 ,
V_105 , V_104 ) ;
memset ( & V_108 , 0 , sizeof( V_108 ) ) ;
V_108 . V_109 = V_110 ,
V_108 . V_100 = V_104 ,
V_108 . V_103 = V_105 ,
sprintf ( V_105 , L_24 , V_103 ) ;
V_108 . V_111 = F_50 ;
V_108 . V_112 = F_47 ;
V_108 . V_91 = F_45 ;
V_108 . V_114 . V_115 = V_116 ,
V_106 = F_54 ( & V_108 , V_2 ) ;
V_61 = F_55 ( V_102 , V_106 ) ;
if ( V_61 < 0 )
return V_61 ;
F_2 ( L_23 ,
V_105 , V_104 ) ;
return 0 ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_57 * V_58 = F_23 ( V_2 -> V_38 ) ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 . V_5 ; V_3 ++ ) {
struct V_6 * V_6 = V_2 -> V_4 . V_6 [ V_3 ] ;
if ( ! V_6 )
continue;
F_57 ( V_58 , V_6 -> V_40 ,
V_2 -> V_4 . V_29 [ V_3 ] ,
V_6 -> V_117 ) ;
F_58 ( V_6 ) ;
}
F_59 ( V_2 -> V_4 . V_6 ) ;
F_59 ( V_2 -> V_4 . V_29 ) ;
V_2 -> V_4 . V_5 = 0 ;
}
static int F_60 ( struct V_57 * V_58 ,
struct V_118 * V_119 )
{
int V_42 = F_61 ( V_119 -> V_120 ) ;
if ( V_58 -> V_121 == V_122 )
return ( V_42 & 0x7ff ) * ( 1 + ( ( ( V_42 ) >> 11 ) & 0x03 ) ) ;
return V_42 & 0x7ff ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_123 * V_38 ;
struct V_118 * V_119 , * V_124 = NULL ;
struct V_57 * V_58 = F_23 ( V_2 -> V_38 ) ;
int V_3 , V_125 , V_126 , V_5 , V_127 ;
int V_128 , V_129 ;
T_4 V_55 ;
if ( V_2 -> V_59 )
V_55 = 1 ;
else
V_55 = 7 ;
V_38 = F_63 ( V_58 , V_2 -> V_59 ) ;
if ( V_38 -> V_130 <= V_55 ) {
F_13 ( & V_2 -> V_38 -> V_2 , L_25 ,
V_2 -> V_59 , V_55 ) ;
return - V_47 ;
}
for ( V_3 = 0 ; V_3 < V_38 -> V_131 [ V_55 ] . V_132 . V_133 ; V_3 ++ ) {
V_119 = & V_38 -> V_131 [ V_55 ] . V_134 [ V_3 ] . V_132 ;
if ( ! F_64 ( V_119 ) )
continue;
if ( V_119 -> V_135 == V_136 ) {
V_124 = V_119 ;
break;
}
}
if ( ! V_124 ) {
F_13 ( & V_2 -> V_38 -> V_2 , L_26 ) ;
return - V_47 ;
}
V_125 = F_60 ( V_58 , V_124 ) ;
V_126 = 1 << ( V_124 -> V_137 - 1 ) ;
F_65 ( & V_2 -> V_38 -> V_2 ,
L_27 ,
V_136 , F_66 ( V_58 -> V_121 ) ,
V_2 -> V_59 , V_55 , V_126 , V_125 ) ;
V_129 = F_67 ( 48000 * 2 * 2 , 125 * V_126 ) ;
V_5 = F_67 ( V_129 , V_125 ) ;
if ( V_5 > V_138 )
V_5 = V_138 ;
V_128 = V_129 / V_5 ;
V_127 = V_139 ;
if ( V_128 > V_125 * V_127 )
V_127 = F_67 ( V_128 , V_125 ) ;
F_65 ( & V_2 -> V_38 -> V_2 ,
L_28 ,
V_5 , V_127 , V_128 ) ;
V_2 -> V_4 . V_65 = V_128 * V_127 ;
V_2 -> V_4 . V_29 = F_68 ( V_5 ,
sizeof( * V_2 -> V_4 . V_29 ) ,
V_37 ) ;
if ( ! V_2 -> V_4 . V_29 ) {
return - V_44 ;
}
V_2 -> V_4 . V_6 = F_68 ( V_5 , sizeof( * V_2 -> V_4 . V_6 ) , V_37 ) ;
if ( ! V_2 -> V_4 . V_6 ) {
F_59 ( V_2 -> V_4 . V_29 ) ;
return - V_44 ;
}
V_2 -> V_4 . V_5 = V_5 ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ ) {
struct V_6 * V_6 ;
int V_140 , V_141 ;
void * V_142 ;
V_6 = F_69 ( V_127 , V_37 ) ;
if ( ! V_6 ) {
F_56 ( V_2 ) ;
return - V_44 ;
}
V_2 -> V_4 . V_6 [ V_3 ] = V_6 ;
V_142 = F_70 ( V_58 , V_127 * V_125 , V_37 ,
& V_6 -> V_117 ) ;
if ( ! V_142 ) {
F_13 ( & V_2 -> V_38 -> V_2 ,
L_29 ) ;
F_56 ( V_2 ) ;
return - V_44 ;
}
V_2 -> V_4 . V_29 [ V_3 ] = V_142 ;
V_6 -> V_2 = V_58 ;
V_6 -> V_7 = V_2 ;
V_6 -> V_143 = F_71 ( V_58 , V_136 ) ;
V_6 -> V_144 = V_145 | V_146 ;
V_6 -> V_29 = V_142 ;
V_6 -> V_126 = V_126 ;
V_6 -> V_147 = F_6 ;
V_6 -> V_25 = V_127 ;
V_6 -> V_40 = V_125 * V_127 ;
for ( V_140 = V_141 = 0 ; V_140 < V_127 ; V_140 ++ , V_141 += V_125 ) {
V_6 -> V_27 [ V_140 ] . V_30 = V_141 ;
V_6 -> V_27 [ V_140 ] . V_26 = V_125 ;
}
}
return 0 ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_70 * V_4 = & V_2 -> V_4 ;
struct V_57 * V_58 = F_23 ( V_2 -> V_38 ) ;
struct V_148 * V_149 ;
struct V_101 * V_102 ;
static int V_150 ;
int V_61 ;
if ( V_2 -> V_151 != V_152 ) {
return 0 ;
}
F_65 ( & V_2 -> V_38 -> V_2 , L_30 ) ;
F_26 ( & V_2 -> V_62 ) ;
F_65 ( & V_2 -> V_38 -> V_2 ,
L_31 ) ;
F_65 ( & V_2 -> V_38 -> V_2 ,
L_32 ) ;
V_61 = F_73 ( & V_2 -> V_38 -> V_2 , V_153 [ V_150 ] , L_33 ,
V_154 , 0 , & V_102 ) ;
if ( V_61 < 0 )
return V_61 ;
F_74 ( & V_4 -> V_85 ) ;
V_4 -> V_155 = V_102 ;
V_4 -> V_58 = V_58 ;
V_61 = F_75 ( V_102 , L_33 , 0 , 0 , 1 , & V_149 ) ;
if ( V_61 < 0 )
goto V_156;
F_76 ( V_149 , V_157 , & V_158 ) ;
V_149 -> V_159 = 0 ;
V_149 -> V_160 = V_2 ;
strcpy ( V_149 -> V_103 , L_34 ) ;
strcpy ( V_102 -> V_161 , L_35 ) ;
strcpy ( V_102 -> V_162 , L_33 ) ;
strcpy ( V_102 -> V_163 , L_36 ) ;
F_77 ( & V_4 -> V_66 , F_37 ) ;
if ( V_2 -> V_164 . V_165 != V_166 ) {
F_53 ( V_102 , V_2 , L_37 , V_167 ) ;
F_53 ( V_102 , V_2 , L_38 , V_168 ) ;
F_53 ( V_102 , V_2 , L_39 , V_169 ) ;
F_53 ( V_102 , V_2 , L_40 , V_170 ) ;
F_53 ( V_102 , V_2 , L_41 , V_171 ) ;
F_53 ( V_102 , V_2 , L_42 , V_172 ) ;
F_53 ( V_102 , V_2 , L_43 , V_173 ) ;
F_53 ( V_102 , V_2 , L_44 , V_174 ) ;
F_53 ( V_102 , V_2 , L_45 , V_175 ) ;
F_53 ( V_102 , V_2 , L_46 , V_176 ) ;
F_53 ( V_102 , V_2 , L_47 , V_177 ) ;
F_53 ( V_102 , V_2 , L_48 , V_178 ) ;
}
V_61 = F_62 ( V_2 ) ;
if ( V_61 )
goto V_156;
V_61 = F_78 ( V_102 ) ;
if ( V_61 < 0 )
goto V_179;
F_65 ( & V_2 -> V_38 -> V_2 , L_49 ) ;
return 0 ;
V_179:
F_56 ( V_2 ) ;
V_156:
F_79 ( V_102 ) ;
V_4 -> V_155 = NULL ;
return V_61 ;
}
static int F_80 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return 0 ;
if ( V_2 -> V_151 != V_152 ) {
return 0 ;
}
F_65 ( & V_2 -> V_38 -> V_2 , L_50 ) ;
if ( V_2 -> V_4 . V_155 ) {
F_81 ( V_2 -> V_4 . V_155 ) ;
F_82 ( & V_2 -> V_4 . V_66 ) ;
F_56 ( V_2 ) ;
F_79 ( V_2 -> V_4 . V_155 ) ;
V_2 -> V_4 . V_155 = NULL ;
}
F_32 ( & V_2 -> V_62 , V_67 ) ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return 0 ;
if ( V_2 -> V_151 != V_152 )
return 0 ;
F_65 ( & V_2 -> V_38 -> V_2 , L_51 ) ;
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
F_65 ( & V_2 -> V_38 -> V_2 , L_52 ) ;
F_31 ( & V_2 -> V_4 . V_66 ) ;
return 0 ;
}
static int T_5 F_85 ( void )
{
return F_86 ( & V_180 ) ;
}
static void T_6 F_87 ( void )
{
F_88 ( & V_180 ) ;
}
