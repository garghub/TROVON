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
F_7 ( & V_2 -> V_18 , 0 ) ;
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
if ( F_8 ( & V_2 -> V_18 ) == 0 )
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
F_7 ( & V_2 -> V_18 , 0 ) ;
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
if ( F_8 ( & V_2 -> V_18 ) > 0 ) {
F_7 ( & V_2 -> V_18 , 0 ) ;
F_30 ( & V_2 -> V_64 ) ;
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
F_2 ( L_16 ) ;
if ( F_8 ( & V_2 -> V_18 ) > 0 ) {
F_7 ( & V_2 -> V_18 , 0 ) ;
F_30 ( & V_2 -> V_64 ) ;
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
static void F_36 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = F_37 ( V_69 , struct V_1 , V_64 ) ;
if ( F_8 ( & V_2 -> V_18 ) ) {
F_2 ( L_17 ) ;
F_14 ( V_2 ) ;
} else {
F_2 ( L_18 ) ;
F_1 ( V_2 ) ;
}
}
static int F_38 ( struct V_13 * V_14 ,
int V_70 )
{
struct V_1 * V_2 = F_19 ( V_14 ) ;
int V_71 = 0 ;
if ( V_2 -> V_17 )
return - V_46 ;
switch ( V_70 ) {
case V_72 :
case V_73 :
case V_74 :
F_7 ( & V_2 -> V_18 , 1 ) ;
break;
case V_75 :
case V_76 :
case V_77 :
F_7 ( & V_2 -> V_18 , 0 ) ;
break;
default:
V_71 = - V_78 ;
}
F_30 ( & V_2 -> V_64 ) ;
return V_71 ;
}
static T_2 F_39 ( struct V_13
* V_14 )
{
unsigned long V_79 ;
struct V_1 * V_2 ;
T_2 V_80 ;
V_2 = F_19 ( V_14 ) ;
if ( V_2 -> V_17 )
return V_81 ;
F_40 ( & V_2 -> V_4 . V_82 , V_79 ) ;
V_80 = V_2 -> V_4 . V_31 ;
F_41 ( & V_2 -> V_4 . V_82 , V_79 ) ;
return V_80 ;
}
static struct V_83 * F_42 ( struct V_13 * V_40 ,
unsigned long V_30 )
{
void * V_84 = V_40 -> V_16 -> V_34 + V_30 ;
return F_43 ( V_84 ) ;
}
static int F_44 ( struct V_85 * V_86 ,
struct V_87 * V_88 )
{
struct V_1 * V_2 = F_45 ( V_86 ) ;
if ( V_2 -> V_17 )
return - V_46 ;
V_88 -> type = V_89 ;
V_88 -> V_90 = 2 ;
V_88 -> V_91 . integer . V_92 = 0 ;
V_88 -> V_91 . integer . V_93 = 0x1f ;
return 0 ;
}
static int F_46 ( struct V_85 * V_86 ,
struct V_94 * V_91 )
{
struct V_1 * V_2 = F_45 ( V_86 ) ;
struct V_13 * V_14 = V_2 -> V_4 . V_23 ;
T_3 V_95 = ( 0x1f - ( V_91 -> V_91 . integer . V_91 [ 0 ] & 0x1f ) ) |
( 0x1f - ( V_91 -> V_91 . integer . V_91 [ 1 ] & 0x1f ) ) << 8 ;
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
V_96 = F_47 ( V_2 , V_86 -> V_97 ) ;
if ( V_96 < 0 )
goto V_59;
V_95 |= V_96 & 0x8000 ;
V_96 = F_48 ( V_2 , V_86 -> V_97 , V_95 ) ;
if ( V_96 < 0 )
goto V_59;
F_2 ( L_19 ,
( V_95 & 0x8000 ) ? L_20 : L_21 ,
0x1f - ( ( V_95 >> 8 ) & 0x1f ) , 0x1f - ( V_95 & 0x1f ) ,
V_95 , ( int ) V_86 -> V_97 ) ;
V_59:
F_26 ( & V_2 -> V_49 ) ;
return V_96 ;
}
static int F_49 ( struct V_85 * V_86 ,
struct V_94 * V_91 )
{
struct V_1 * V_2 = F_45 ( V_86 ) ;
struct V_13 * V_14 = V_2 -> V_4 . V_23 ;
int V_44 = 0 ;
int V_95 ;
if ( V_2 -> V_17 )
return - V_46 ;
if ( V_14 )
V_44 = ! ! ( V_14 -> V_47 & V_48 ) ;
if ( V_44 ) {
if ( ! F_21 ( & V_2 -> V_49 ) )
return - V_50 ;
} else
F_22 ( & V_2 -> V_49 ) ;
V_95 = F_47 ( V_2 , V_86 -> V_97 ) ;
F_26 ( & V_2 -> V_49 ) ;
if ( V_95 < 0 )
return V_95 ;
F_2 ( L_22 ,
( V_95 & 0x8000 ) ? L_20 : L_21 ,
0x1f - ( ( V_95 >> 8 ) & 0x1f ) , 0x1f - ( V_95 & 0x1f ) ,
V_95 , ( int ) V_86 -> V_97 ) ;
V_91 -> V_91 . integer . V_91 [ 0 ] = 0x1f - ( V_95 & 0x1f ) ;
V_91 -> V_91 . integer . V_91 [ 1 ] = 0x1f - ( ( V_95 << 8 ) & 0x1f ) ;
return 0 ;
}
static int F_50 ( struct V_85 * V_86 ,
struct V_94 * V_91 )
{
struct V_1 * V_2 = F_45 ( V_86 ) ;
T_3 V_95 = V_91 -> V_91 . integer . V_91 [ 0 ] ;
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
V_96 = F_47 ( V_2 , V_86 -> V_97 ) ;
if ( V_96 < 0 )
goto V_59;
if ( V_95 )
V_96 &= 0x1f1f ;
else
V_96 |= 0x8000 ;
V_96 = F_48 ( V_2 , V_86 -> V_97 , V_96 ) ;
if ( V_96 < 0 )
goto V_59;
F_2 ( L_19 ,
( V_95 & 0x8000 ) ? L_20 : L_21 ,
0x1f - ( ( V_95 >> 8 ) & 0x1f ) , 0x1f - ( V_95 & 0x1f ) ,
V_95 , ( int ) V_86 -> V_97 ) ;
V_59:
F_26 ( & V_2 -> V_49 ) ;
return V_96 ;
}
static int F_51 ( struct V_85 * V_86 ,
struct V_94 * V_91 )
{
struct V_1 * V_2 = F_45 ( V_86 ) ;
struct V_13 * V_14 = V_2 -> V_4 . V_23 ;
int V_44 = 0 ;
int V_95 ;
if ( V_2 -> V_17 )
return - V_46 ;
if ( V_14 )
V_44 = ! ! ( V_14 -> V_47 & V_48 ) ;
if ( V_44 ) {
if ( ! F_21 ( & V_2 -> V_49 ) )
return - V_50 ;
} else
F_22 ( & V_2 -> V_49 ) ;
V_95 = F_47 ( V_2 , V_86 -> V_97 ) ;
F_26 ( & V_2 -> V_49 ) ;
if ( V_95 < 0 )
return V_95 ;
if ( V_95 & 0x8000 )
V_91 -> V_91 . integer . V_91 [ 0 ] = 0 ;
else
V_91 -> V_91 . integer . V_91 [ 0 ] = 1 ;
F_2 ( L_22 ,
( V_95 & 0x8000 ) ? L_20 : L_21 ,
0x1f - ( ( V_95 >> 8 ) & 0x1f ) , 0x1f - ( V_95 & 0x1f ) ,
V_95 , ( int ) V_86 -> V_97 ) ;
return 0 ;
}
static int F_52 ( struct V_98 * V_99 , struct V_1 * V_2 ,
char * V_100 , int V_101 )
{
int V_59 ;
char V_102 [ 44 ] ;
struct V_85 * V_103 ;
struct V_104 V_105 ;
memset ( & V_105 , 0 , sizeof( V_105 ) ) ;
V_105 . V_106 = V_107 ,
V_105 . V_97 = V_101 ,
V_105 . V_100 = V_102 ,
sprintf ( V_102 , L_23 , V_100 ) ;
V_105 . V_108 = F_51 ;
V_105 . V_109 = F_50 ;
V_105 . V_88 = V_110 ;
V_103 = F_53 ( & V_105 , V_2 ) ;
V_59 = F_54 ( V_99 , V_103 ) ;
if ( V_59 < 0 )
return V_59 ;
F_2 ( L_24 ,
V_102 , V_101 ) ;
memset ( & V_105 , 0 , sizeof( V_105 ) ) ;
V_105 . V_106 = V_107 ,
V_105 . V_97 = V_101 ,
V_105 . V_100 = V_102 ,
sprintf ( V_102 , L_25 , V_100 ) ;
V_105 . V_108 = F_49 ;
V_105 . V_109 = F_46 ;
V_105 . V_88 = F_44 ;
V_105 . V_111 . V_112 = V_113 ,
V_103 = F_53 ( & V_105 , V_2 ) ;
V_59 = F_54 ( V_99 , V_103 ) ;
if ( V_59 < 0 )
return V_59 ;
F_2 ( L_24 ,
V_102 , V_101 ) ;
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
V_6 -> V_114 ) ;
F_57 ( V_6 ) ;
}
F_58 ( V_2 -> V_4 . V_6 ) ;
F_58 ( V_2 -> V_4 . V_29 ) ;
V_2 -> V_4 . V_5 = 0 ;
}
static int F_59 ( struct V_115 * V_57 ,
struct V_116 * V_117 )
{
int V_41 = F_60 ( V_117 -> V_118 ) ;
if ( V_57 -> V_119 == V_120 )
return ( V_41 & 0x7ff ) * ( 1 + ( ( ( V_41 ) >> 11 ) & 0x03 ) ) ;
return V_41 & 0x7ff ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_121 * V_122 ;
struct V_116 * V_117 , * V_123 = NULL ;
int V_3 , V_124 , V_125 , V_5 , V_126 ;
int V_127 , V_128 ;
T_4 V_54 ;
if ( V_2 -> V_56 )
V_54 = 1 ;
else
V_54 = 7 ;
V_122 = F_62 ( V_2 -> V_57 , V_2 -> V_56 ) ;
if ( V_122 -> V_129 <= V_54 ) {
F_13 ( L_26 ,
V_2 -> V_56 , V_54 ) ;
return - V_46 ;
}
for ( V_3 = 0 ; V_3 < V_122 -> V_130 [ V_54 ] . V_131 . V_132 ; V_3 ++ ) {
V_117 = & V_122 -> V_130 [ V_54 ] . V_133 [ V_3 ] . V_131 ;
if ( ! F_63 ( V_117 ) )
continue;
if ( V_117 -> V_134 == V_135 ) {
V_123 = V_117 ;
break;
}
}
if ( ! V_123 ) {
F_13 ( L_27 ) ;
return - V_46 ;
}
V_124 = F_59 ( V_2 -> V_57 , V_123 ) ;
V_125 = 1 << ( V_123 -> V_136 - 1 ) ;
F_64 ( L_28 ,
V_135 , F_65 ( V_2 -> V_57 -> V_119 ) ,
V_2 -> V_56 , V_54 ,
V_125 ,
V_124 ) ;
V_128 = F_66 ( 48000 * 2 * 2 , 125 * V_125 ) ;
V_5 = F_66 ( V_128 , V_124 ) ;
if ( V_5 > V_137 )
V_5 = V_137 ;
V_127 = V_128 / V_5 ;
V_126 = V_138 ;
if ( V_127 > V_124 * V_126 )
V_126 = F_66 ( V_127 , V_124 ) ;
F_64 ( L_29 ,
V_5 , V_126 , V_127 ) ;
V_2 -> V_4 . V_63 = V_127 * V_126 ;
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
int V_139 , V_140 ;
void * V_141 ;
V_6 = F_68 ( V_126 , V_37 ) ;
if ( ! V_6 ) {
F_13 ( L_30 ) ;
F_55 ( V_2 ) ;
return - V_43 ;
}
V_2 -> V_4 . V_6 [ V_3 ] = V_6 ;
V_141 = F_69 ( V_2 -> V_57 , V_126 * V_124 , V_37 ,
& V_6 -> V_114 ) ;
if ( ! V_141 ) {
F_13 ( L_31 ) ;
F_55 ( V_2 ) ;
return - V_43 ;
}
V_2 -> V_4 . V_29 [ V_3 ] = V_141 ;
V_6 -> V_2 = V_2 -> V_57 ;
V_6 -> V_7 = V_2 ;
V_6 -> V_142 = F_70 ( V_2 -> V_57 , V_135 ) ;
V_6 -> V_143 = V_144 | V_145 ;
V_6 -> V_29 = V_141 ;
V_6 -> V_125 = V_125 ;
V_6 -> V_146 = F_6 ;
V_6 -> V_25 = V_126 ;
V_6 -> V_39 = V_124 * V_126 ;
for ( V_139 = V_140 = 0 ; V_139 < V_126 ; V_139 ++ , V_140 += V_124 ) {
V_6 -> V_27 [ V_139 ] . V_30 = V_140 ;
V_6 -> V_27 [ V_139 ] . V_26 = V_124 ;
}
}
return 0 ;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_147 * V_4 = & V_2 -> V_4 ;
struct V_148 * V_149 ;
struct V_98 * V_99 ;
static int V_150 ;
int V_59 ;
if ( ! V_2 -> V_151 ) {
return 0 ;
}
F_64 ( L_32 ) ;
F_25 ( & V_2 -> V_60 ) ;
F_72 ( V_152 L_33
L_34 ) ;
F_72 ( V_152
L_35 ) ;
V_59 = F_73 ( & V_2 -> V_57 -> V_2 , V_153 [ V_150 ] , L_36 ,
V_154 , 0 , & V_99 ) ;
if ( V_59 < 0 )
return V_59 ;
F_74 ( & V_4 -> V_82 ) ;
V_4 -> V_155 = V_99 ;
V_4 -> V_57 = V_2 -> V_57 ;
V_59 = F_75 ( V_99 , L_36 , 0 , 0 , 1 , & V_149 ) ;
if ( V_59 < 0 )
goto V_156;
F_76 ( V_149 , V_157 , & V_158 ) ;
V_149 -> V_159 = 0 ;
V_149 -> V_160 = V_2 ;
strcpy ( V_149 -> V_100 , L_37 ) ;
strcpy ( V_99 -> V_161 , L_38 ) ;
strcpy ( V_99 -> V_162 , L_36 ) ;
strcpy ( V_99 -> V_163 , L_39 ) ;
F_77 ( & V_2 -> V_64 , F_36 ) ;
if ( V_2 -> V_164 . V_165 != V_166 ) {
F_52 ( V_99 , V_2 , L_40 , V_167 ) ;
F_52 ( V_99 , V_2 , L_41 , V_168 ) ;
F_52 ( V_99 , V_2 , L_42 , V_169 ) ;
F_52 ( V_99 , V_2 , L_43 , V_170 ) ;
F_52 ( V_99 , V_2 , L_44 , V_171 ) ;
F_52 ( V_99 , V_2 , L_45 , V_172 ) ;
F_52 ( V_99 , V_2 , L_46 , V_173 ) ;
F_52 ( V_99 , V_2 , L_47 , V_174 ) ;
F_52 ( V_99 , V_2 , L_48 , V_175 ) ;
F_52 ( V_99 , V_2 , L_49 , V_176 ) ;
F_52 ( V_99 , V_2 , L_50 , V_177 ) ;
F_52 ( V_99 , V_2 , L_51 , V_178 ) ;
}
V_59 = F_61 ( V_2 ) ;
if ( V_59 )
goto V_156;
V_59 = F_78 ( V_99 ) ;
if ( V_59 < 0 )
goto V_179;
F_64 ( L_52 ) ;
return 0 ;
V_179:
F_55 ( V_2 ) ;
V_156:
F_79 ( V_99 ) ;
V_4 -> V_155 = NULL ;
return V_59 ;
}
static int F_80 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return 0 ;
if ( ! V_2 -> V_151 ) {
return 0 ;
}
F_64 ( L_53 ) ;
if ( V_2 -> V_4 . V_155 ) {
F_81 ( V_2 -> V_4 . V_155 ) ;
F_82 ( & V_2 -> V_64 ) ;
F_55 ( V_2 ) ;
F_79 ( V_2 -> V_4 . V_155 ) ;
V_2 -> V_4 . V_155 = NULL ;
}
F_31 ( & V_2 -> V_60 , V_65 ) ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return 0 ;
if ( ! V_2 -> V_151 )
return 0 ;
F_64 ( L_54 ) ;
F_1 ( V_2 ) ;
F_7 ( & V_2 -> V_18 , 0 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return 0 ;
if ( ! V_2 -> V_151 )
return 0 ;
F_64 ( L_55 ) ;
F_30 ( & V_2 -> V_64 ) ;
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
