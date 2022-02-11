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
int V_44 = 0 ;
if ( ! V_2 ) {
F_20 ( L_8
L_9 ) ;
return - V_45 ;
}
if ( V_2 -> V_17 )
return - V_45 ;
F_2 ( L_10 ) ;
V_16 -> V_46 = V_47 ;
if ( ( V_2 -> V_48 == 0 || V_2 -> V_49 ) && V_2 -> V_4 . V_50 == 0 ) {
int V_51 = ! ! ( V_14 -> V_52 & V_53 ) ;
if ( V_51 ) {
if ( ! F_21 ( & V_2 -> V_54 ) )
return - V_55 ;
} else
F_22 ( & V_2 -> V_54 ) ;
if ( V_2 -> V_49 )
V_2 -> V_48 = 1 ;
else
V_2 -> V_48 = 7 ;
F_2 ( L_11 ,
V_2 -> V_56 , V_2 -> V_48 ) ;
F_23 ( V_2 -> V_57 , V_2 -> V_56 , V_2 -> V_48 ) ;
V_2 -> V_58 = 0 ;
V_44 = F_24 ( V_2 ) ;
if ( V_44 < 0 )
goto V_59;
V_2 -> V_4 . V_50 ++ ;
F_25 ( & V_2 -> V_54 ) ;
}
F_26 ( V_16 , V_60 ) ;
F_27 ( V_16 , V_61 ,
V_2 -> V_4 . V_62 * 95 / 100 ,
V_2 -> V_4 . V_62 * 105 / 100 ) ;
V_2 -> V_4 . V_23 = V_14 ;
return 0 ;
V_59:
F_25 ( & V_2 -> V_54 ) ;
F_20 ( L_12 ) ;
return V_44 ;
}
static int F_28 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_19 ( V_14 ) ;
F_2 ( L_13 ) ;
V_2 -> V_58 = 1 ;
F_22 ( & V_2 -> V_54 ) ;
V_2 -> V_4 . V_50 -- ;
if ( F_8 ( & V_2 -> V_18 ) > 0 ) {
F_7 ( & V_2 -> V_18 , 0 ) ;
F_29 ( & V_2 -> V_63 ) ;
}
F_24 ( V_2 ) ;
if ( V_14 -> V_16 -> V_34 ) {
F_2 ( L_14 ) ;
F_16 ( V_14 -> V_16 -> V_34 ) ;
V_14 -> V_16 -> V_34 = NULL ;
}
F_25 ( & V_2 -> V_54 ) ;
return 0 ;
}
static int F_30 ( struct V_13 * V_14 ,
struct V_64 * V_65 )
{
int V_44 ;
struct V_1 * V_2 = F_19 ( V_14 ) ;
if ( V_2 -> V_17 )
return - V_45 ;
F_2 ( L_15 ) ;
V_44 = F_15 ( V_14 ,
F_31 ( V_65 ) ) ;
if ( V_44 < 0 )
return V_44 ;
#if 0
unsigned int channels, rate, format;
format = params_format(hw_params);
rate = params_rate(hw_params);
channels = params_channels(hw_params);
#endif
return 0 ;
}
static int F_32 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_19 ( V_14 ) ;
F_2 ( L_16 ) ;
if ( F_8 ( & V_2 -> V_18 ) > 0 ) {
F_7 ( & V_2 -> V_18 , 0 ) ;
F_29 ( & V_2 -> V_63 ) ;
}
return 0 ;
}
static int F_33 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_19 ( V_14 ) ;
if ( V_2 -> V_17 )
return - V_45 ;
V_2 -> V_4 . V_31 = 0 ;
V_2 -> V_4 . V_35 = 0 ;
return 0 ;
}
static void F_34 ( struct V_66 * V_67 )
{
struct V_1 * V_2 = F_35 ( V_67 , struct V_1 , V_63 ) ;
if ( F_8 ( & V_2 -> V_18 ) ) {
F_2 ( L_17 ) ;
F_14 ( V_2 ) ;
} else {
F_2 ( L_18 ) ;
F_1 ( V_2 ) ;
}
}
static int F_36 ( struct V_13 * V_14 ,
int V_68 )
{
struct V_1 * V_2 = F_19 ( V_14 ) ;
int V_69 = 0 ;
if ( V_2 -> V_17 )
return - V_45 ;
switch ( V_68 ) {
case V_70 :
case V_71 :
case V_72 :
F_7 ( & V_2 -> V_18 , 1 ) ;
break;
case V_73 :
case V_74 :
case V_75 :
F_7 ( & V_2 -> V_18 , 0 ) ;
break;
default:
V_69 = - V_76 ;
}
F_29 ( & V_2 -> V_63 ) ;
return V_69 ;
}
static T_2 F_37 ( struct V_13
* V_14 )
{
unsigned long V_77 ;
struct V_1 * V_2 ;
T_2 V_78 ;
V_2 = F_19 ( V_14 ) ;
if ( V_2 -> V_17 )
return V_79 ;
F_38 ( & V_2 -> V_4 . V_80 , V_77 ) ;
V_78 = V_2 -> V_4 . V_31 ;
F_39 ( & V_2 -> V_4 . V_80 , V_77 ) ;
return V_78 ;
}
static struct V_81 * F_40 ( struct V_13 * V_40 ,
unsigned long V_30 )
{
void * V_82 = V_40 -> V_16 -> V_34 + V_30 ;
return F_41 ( V_82 ) ;
}
static int F_42 ( struct V_83 * V_84 ,
struct V_85 * V_86 )
{
struct V_1 * V_2 = F_43 ( V_84 ) ;
if ( V_2 -> V_17 )
return - V_45 ;
V_86 -> type = V_87 ;
V_86 -> V_88 = 2 ;
V_86 -> V_89 . integer . V_90 = 0 ;
V_86 -> V_89 . integer . V_91 = 0x1f ;
return 0 ;
}
static int F_44 ( struct V_83 * V_84 ,
struct V_92 * V_89 )
{
struct V_1 * V_2 = F_43 ( V_84 ) ;
struct V_13 * V_14 = V_2 -> V_4 . V_23 ;
T_3 V_93 = ( 0x1f - ( V_89 -> V_89 . integer . V_89 [ 0 ] & 0x1f ) ) |
( 0x1f - ( V_89 -> V_89 . integer . V_89 [ 1 ] & 0x1f ) ) << 8 ;
int V_51 = 0 ;
int V_94 ;
if ( V_2 -> V_17 )
return - V_45 ;
if ( V_14 )
V_51 = ! ! ( V_14 -> V_52 & V_53 ) ;
if ( V_51 ) {
if ( ! F_21 ( & V_2 -> V_54 ) )
return - V_55 ;
} else
F_22 ( & V_2 -> V_54 ) ;
V_94 = F_45 ( V_2 , V_84 -> V_95 ) ;
if ( V_94 < 0 )
goto V_59;
V_93 |= V_94 & 0x8000 ;
V_94 = F_46 ( V_2 , V_84 -> V_95 , V_93 ) ;
if ( V_94 < 0 )
goto V_59;
F_2 ( L_19 ,
( V_93 & 0x8000 ) ? L_20 : L_21 ,
0x1f - ( ( V_93 >> 8 ) & 0x1f ) , 0x1f - ( V_93 & 0x1f ) ,
V_93 , ( int ) V_84 -> V_95 ) ;
V_59:
F_25 ( & V_2 -> V_54 ) ;
return V_94 ;
}
static int F_47 ( struct V_83 * V_84 ,
struct V_92 * V_89 )
{
struct V_1 * V_2 = F_43 ( V_84 ) ;
struct V_13 * V_14 = V_2 -> V_4 . V_23 ;
int V_51 = 0 ;
int V_93 ;
if ( V_2 -> V_17 )
return - V_45 ;
if ( V_14 )
V_51 = ! ! ( V_14 -> V_52 & V_53 ) ;
if ( V_51 ) {
if ( ! F_21 ( & V_2 -> V_54 ) )
return - V_55 ;
} else
F_22 ( & V_2 -> V_54 ) ;
V_93 = F_45 ( V_2 , V_84 -> V_95 ) ;
F_25 ( & V_2 -> V_54 ) ;
if ( V_93 < 0 )
return V_93 ;
F_2 ( L_22 ,
( V_93 & 0x8000 ) ? L_20 : L_21 ,
0x1f - ( ( V_93 >> 8 ) & 0x1f ) , 0x1f - ( V_93 & 0x1f ) ,
V_93 , ( int ) V_84 -> V_95 ) ;
V_89 -> V_89 . integer . V_89 [ 0 ] = 0x1f - ( V_93 & 0x1f ) ;
V_89 -> V_89 . integer . V_89 [ 1 ] = 0x1f - ( ( V_93 << 8 ) & 0x1f ) ;
return 0 ;
}
static int F_48 ( struct V_83 * V_84 ,
struct V_92 * V_89 )
{
struct V_1 * V_2 = F_43 ( V_84 ) ;
T_3 V_93 = V_89 -> V_89 . integer . V_89 [ 0 ] ;
struct V_13 * V_14 = V_2 -> V_4 . V_23 ;
int V_51 = 0 ;
int V_94 ;
if ( V_2 -> V_17 )
return - V_45 ;
if ( V_14 )
V_51 = ! ! ( V_14 -> V_52 & V_53 ) ;
if ( V_51 ) {
if ( ! F_21 ( & V_2 -> V_54 ) )
return - V_55 ;
} else
F_22 ( & V_2 -> V_54 ) ;
V_94 = F_45 ( V_2 , V_84 -> V_95 ) ;
if ( V_94 < 0 )
goto V_59;
if ( V_93 )
V_94 &= 0x1f1f ;
else
V_94 |= 0x8000 ;
V_94 = F_46 ( V_2 , V_84 -> V_95 , V_94 ) ;
if ( V_94 < 0 )
goto V_59;
F_2 ( L_19 ,
( V_93 & 0x8000 ) ? L_20 : L_21 ,
0x1f - ( ( V_93 >> 8 ) & 0x1f ) , 0x1f - ( V_93 & 0x1f ) ,
V_93 , ( int ) V_84 -> V_95 ) ;
V_59:
F_25 ( & V_2 -> V_54 ) ;
return V_94 ;
}
static int F_49 ( struct V_83 * V_84 ,
struct V_92 * V_89 )
{
struct V_1 * V_2 = F_43 ( V_84 ) ;
struct V_13 * V_14 = V_2 -> V_4 . V_23 ;
int V_51 = 0 ;
int V_93 ;
if ( V_2 -> V_17 )
return - V_45 ;
if ( V_14 )
V_51 = ! ! ( V_14 -> V_52 & V_53 ) ;
if ( V_51 ) {
if ( ! F_21 ( & V_2 -> V_54 ) )
return - V_55 ;
} else
F_22 ( & V_2 -> V_54 ) ;
V_93 = F_45 ( V_2 , V_84 -> V_95 ) ;
F_25 ( & V_2 -> V_54 ) ;
if ( V_93 < 0 )
return V_93 ;
if ( V_93 & 0x8000 )
V_89 -> V_89 . integer . V_89 [ 0 ] = 0 ;
else
V_89 -> V_89 . integer . V_89 [ 0 ] = 1 ;
F_2 ( L_22 ,
( V_93 & 0x8000 ) ? L_20 : L_21 ,
0x1f - ( ( V_93 >> 8 ) & 0x1f ) , 0x1f - ( V_93 & 0x1f ) ,
V_93 , ( int ) V_84 -> V_95 ) ;
return 0 ;
}
static int F_50 ( struct V_96 * V_97 , struct V_1 * V_2 ,
char * V_98 , int V_99 )
{
int V_59 ;
char V_100 [ 44 ] ;
struct V_83 * V_101 ;
struct V_102 V_103 ;
memset ( & V_103 , 0 , sizeof( V_103 ) ) ;
V_103 . V_104 = V_105 ,
V_103 . V_95 = V_99 ,
V_103 . V_98 = V_100 ,
sprintf ( V_100 , L_23 , V_98 ) ;
V_103 . V_106 = F_49 ;
V_103 . V_107 = F_48 ;
V_103 . V_86 = V_108 ;
V_101 = F_51 ( & V_103 , V_2 ) ;
V_59 = F_52 ( V_97 , V_101 ) ;
if ( V_59 < 0 )
return V_59 ;
F_2 ( L_24 ,
V_100 , V_99 ) ;
memset ( & V_103 , 0 , sizeof( V_103 ) ) ;
V_103 . V_104 = V_105 ,
V_103 . V_95 = V_99 ,
V_103 . V_98 = V_100 ,
sprintf ( V_100 , L_25 , V_98 ) ;
V_103 . V_106 = F_47 ;
V_103 . V_107 = F_44 ;
V_103 . V_86 = F_42 ;
V_103 . V_109 . V_110 = V_111 ,
V_101 = F_51 ( & V_103 , V_2 ) ;
V_59 = F_52 ( V_97 , V_101 ) ;
if ( V_59 < 0 )
return V_59 ;
F_2 ( L_24 ,
V_100 , V_99 ) ;
return 0 ;
}
static void F_53 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 . V_5 ; V_3 ++ ) {
struct V_6 * V_6 = V_2 -> V_4 . V_6 [ V_3 ] ;
if ( ! V_6 )
continue;
F_54 ( V_2 -> V_57 , V_6 -> V_39 ,
V_2 -> V_4 . V_29 [ V_3 ] ,
V_6 -> V_112 ) ;
F_55 ( V_6 ) ;
}
F_56 ( V_2 -> V_4 . V_6 ) ;
F_56 ( V_2 -> V_4 . V_29 ) ;
V_2 -> V_4 . V_5 = 0 ;
}
static int F_57 ( struct V_113 * V_57 ,
struct V_114 * V_115 )
{
int V_41 = F_58 ( V_115 -> V_116 ) ;
if ( V_57 -> V_117 == V_118 )
return ( V_41 & 0x7ff ) * ( 1 + ( ( ( V_41 ) >> 11 ) & 0x03 ) ) ;
return V_41 & 0x7ff ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_119 * V_120 ;
struct V_114 * V_115 , * V_121 = NULL ;
int V_3 , V_122 , V_123 , V_5 , V_124 ;
int V_125 , V_126 ;
T_4 V_48 ;
if ( V_2 -> V_56 )
V_48 = 1 ;
else
V_48 = 7 ;
V_120 = F_60 ( V_2 -> V_57 , V_2 -> V_56 ) ;
if ( V_120 -> V_127 <= V_48 ) {
F_13 ( L_26 ,
V_2 -> V_56 , V_48 ) ;
return - V_45 ;
}
for ( V_3 = 0 ; V_3 < V_120 -> V_128 [ V_48 ] . V_129 . V_130 ; V_3 ++ ) {
V_115 = & V_120 -> V_128 [ V_48 ] . V_131 [ V_3 ] . V_129 ;
if ( ! F_61 ( V_115 ) )
continue;
if ( V_115 -> V_132 == V_133 ) {
V_121 = V_115 ;
break;
}
}
if ( ! V_121 ) {
F_13 ( L_27 ) ;
return - V_45 ;
}
V_122 = F_57 ( V_2 -> V_57 , V_121 ) ;
V_123 = 1 << ( V_121 -> V_134 - 1 ) ;
F_62 ( L_28 ,
V_133 , F_63 ( V_2 -> V_57 -> V_117 ) ,
V_2 -> V_56 , V_48 ,
V_123 ,
V_122 ) ;
V_126 = F_64 ( 48000 * 2 * 2 , 125 * V_123 ) ;
V_5 = F_64 ( V_126 , V_122 ) ;
if ( V_5 > V_135 )
V_5 = V_135 ;
V_125 = V_126 / V_5 ;
V_124 = V_136 ;
if ( V_125 > V_122 * V_124 )
V_124 = F_64 ( V_125 , V_122 ) ;
F_62 ( L_29 ,
V_5 , V_124 , V_125 ) ;
V_2 -> V_4 . V_62 = V_125 * V_124 ;
V_2 -> V_4 . V_29 = F_65 ( V_5 ,
sizeof( * V_2 -> V_4 . V_29 ) ,
V_37 ) ;
if ( ! V_2 -> V_4 . V_29 ) {
return - V_43 ;
}
V_2 -> V_4 . V_6 = F_65 ( V_5 , sizeof( * V_2 -> V_4 . V_6 ) , V_37 ) ;
if ( ! V_2 -> V_4 . V_6 ) {
F_56 ( V_2 -> V_4 . V_29 ) ;
return - V_43 ;
}
V_2 -> V_4 . V_5 = V_5 ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ ) {
struct V_6 * V_6 ;
int V_137 , V_138 ;
void * V_139 ;
V_6 = F_66 ( V_124 , V_37 ) ;
if ( ! V_6 ) {
F_13 ( L_30 ) ;
F_53 ( V_2 ) ;
return - V_43 ;
}
V_2 -> V_4 . V_6 [ V_3 ] = V_6 ;
V_139 = F_67 ( V_2 -> V_57 , V_124 * V_122 , V_37 ,
& V_6 -> V_112 ) ;
if ( ! V_139 ) {
F_13 ( L_31 ) ;
F_53 ( V_2 ) ;
return - V_43 ;
}
V_2 -> V_4 . V_29 [ V_3 ] = V_139 ;
V_6 -> V_2 = V_2 -> V_57 ;
V_6 -> V_7 = V_2 ;
V_6 -> V_140 = F_68 ( V_2 -> V_57 , V_133 ) ;
V_6 -> V_141 = V_142 | V_143 ;
V_6 -> V_29 = V_139 ;
V_6 -> V_123 = V_123 ;
V_6 -> V_144 = F_6 ;
V_6 -> V_25 = V_124 ;
V_6 -> V_39 = V_122 * V_124 ;
for ( V_137 = V_138 = 0 ; V_137 < V_124 ; V_137 ++ , V_138 += V_122 ) {
V_6 -> V_27 [ V_137 ] . V_30 = V_138 ;
V_6 -> V_27 [ V_137 ] . V_26 = V_122 ;
}
}
return 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_145 * V_4 = & V_2 -> V_4 ;
struct V_146 * V_147 ;
struct V_96 * V_97 ;
static int V_148 ;
int V_59 ;
if ( ! V_2 -> V_149 ) {
return 0 ;
}
F_62 ( L_32 ) ;
F_70 ( V_150 L_33
L_34 ) ;
F_70 ( V_150
L_35 ) ;
V_59 = F_71 ( V_151 [ V_148 ] , L_36 , V_152 , 0 ,
& V_97 ) ;
if ( V_59 < 0 )
return V_59 ;
F_72 ( & V_4 -> V_80 ) ;
V_4 -> V_153 = V_97 ;
V_4 -> V_57 = V_2 -> V_57 ;
V_59 = F_73 ( V_97 , L_36 , 0 , 0 , 1 , & V_147 ) ;
if ( V_59 < 0 )
goto V_154;
F_74 ( V_147 , V_155 , & V_156 ) ;
V_147 -> V_157 = 0 ;
V_147 -> V_158 = V_2 ;
strcpy ( V_147 -> V_98 , L_37 ) ;
F_75 ( V_97 , & V_2 -> V_57 -> V_2 ) ;
strcpy ( V_97 -> V_159 , L_38 ) ;
strcpy ( V_97 -> V_160 , L_36 ) ;
strcpy ( V_97 -> V_161 , L_39 ) ;
F_76 ( & V_2 -> V_63 , F_34 ) ;
if ( V_2 -> V_162 . V_163 != V_164 ) {
F_50 ( V_97 , V_2 , L_40 , V_165 ) ;
F_50 ( V_97 , V_2 , L_41 , V_166 ) ;
F_50 ( V_97 , V_2 , L_42 , V_167 ) ;
F_50 ( V_97 , V_2 , L_43 , V_168 ) ;
F_50 ( V_97 , V_2 , L_44 , V_169 ) ;
F_50 ( V_97 , V_2 , L_45 , V_170 ) ;
F_50 ( V_97 , V_2 , L_46 , V_171 ) ;
F_50 ( V_97 , V_2 , L_47 , V_172 ) ;
F_50 ( V_97 , V_2 , L_48 , V_173 ) ;
F_50 ( V_97 , V_2 , L_49 , V_174 ) ;
F_50 ( V_97 , V_2 , L_50 , V_175 ) ;
F_50 ( V_97 , V_2 , L_51 , V_176 ) ;
}
V_59 = F_59 ( V_2 ) ;
if ( V_59 )
goto V_154;
V_59 = F_77 ( V_97 ) ;
if ( V_59 < 0 )
goto V_177;
F_62 ( L_52 ) ;
return 0 ;
V_177:
F_53 ( V_2 ) ;
V_154:
F_78 ( V_97 ) ;
V_4 -> V_153 = NULL ;
return V_59 ;
}
static int F_79 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return 0 ;
if ( V_2 -> V_149 != 1 ) {
return 0 ;
}
F_62 ( L_53 ) ;
if ( V_2 -> V_4 . V_153 ) {
F_80 ( V_2 -> V_4 . V_153 ) ;
F_81 ( & V_2 -> V_63 ) ;
F_53 ( V_2 ) ;
F_78 ( V_2 -> V_4 . V_153 ) ;
V_2 -> V_4 . V_153 = NULL ;
}
return 0 ;
}
static int T_5 F_82 ( void )
{
return F_83 ( & V_178 ) ;
}
static void T_6 F_84 ( void )
{
F_85 ( & V_178 ) ;
}
