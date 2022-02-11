static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( L_1 ) ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
if ( ! F_3 () )
F_4 ( V_2 -> V_5 . V_6 [ V_3 ] ) ;
else
F_5 ( V_2 -> V_5 . V_6 [ V_3 ] ) ;
F_6 ( V_2 -> V_5 . V_6 [ V_3 ] ) ;
V_2 -> V_5 . V_6 [ V_3 ] = NULL ;
F_7 ( V_2 -> V_5 . V_7 [ V_3 ] ) ;
V_2 -> V_5 . V_7 [ V_3 ] = NULL ;
}
return 0 ;
}
static void F_8 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_8 ;
int V_3 ;
unsigned int V_9 ;
int V_10 = 0 ;
int V_11 ;
unsigned char * V_12 ;
unsigned int V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
switch ( V_6 -> V_11 ) {
case 0 :
case - V_18 :
break;
case - V_19 :
case - V_20 :
case - V_21 :
return;
default:
F_2 ( L_2 , V_6 -> V_11 ) ;
break;
}
if ( F_9 ( & V_2 -> V_22 ) == 0 )
return;
if ( V_2 -> V_5 . V_23 ) {
V_15 = V_2 -> V_5 . V_23 ;
V_17 = V_15 -> V_17 ;
V_13 = V_17 -> V_24 >> 3 ;
for ( V_3 = 0 ; V_3 < V_6 -> V_25 ; V_3 ++ ) {
int V_26 =
V_6 -> V_27 [ V_3 ] . V_28 / V_13 ;
V_12 = ( unsigned char * ) V_6 -> V_7 +
V_6 -> V_27 [ V_3 ] . V_29 ;
if ( ! V_26 )
continue;
V_9 = V_2 -> V_5 . V_30 ;
if ( V_9 + V_26 >= V_17 -> V_31 ) {
unsigned int V_32 =
V_17 -> V_31 - V_9 ;
memcpy ( V_17 -> V_33 + V_9 * V_13 , V_12 ,
V_32 * V_13 ) ;
memcpy ( V_17 -> V_33 , V_12 + V_32 * V_13 ,
V_26 * V_13 - V_32 * V_13 ) ;
} else {
memcpy ( V_17 -> V_33 + V_9 * V_13 , V_12 ,
V_26 * V_13 ) ;
}
F_10 ( V_15 ) ;
V_2 -> V_5 . V_30 += V_26 ;
if ( V_2 -> V_5 . V_30 >=
V_17 -> V_31 )
V_2 -> V_5 . V_30 -=
V_17 -> V_31 ;
V_2 -> V_5 . V_34 += V_26 ;
if ( V_2 -> V_5 . V_34 >=
V_17 -> V_35 ) {
V_2 -> V_5 . V_34 -=
V_17 -> V_35 ;
V_10 = 1 ;
}
F_11 ( V_15 ) ;
}
if ( V_10 )
F_12 ( V_15 ) ;
}
V_6 -> V_11 = 0 ;
V_11 = F_13 ( V_6 , V_36 ) ;
if ( V_11 < 0 ) {
F_14 ( L_3 ,
V_11 ) ;
}
return;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_3 , V_37 ;
const int V_38 = V_39 *
V_40 ;
F_2 ( L_4 ) ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
struct V_6 * V_6 ;
int V_41 , V_42 ;
V_2 -> V_5 . V_7 [ V_3 ] = F_16 ( V_38 , V_36 ) ;
if ( ! V_2 -> V_5 . V_7 [ V_3 ] )
return - V_43 ;
memset ( V_2 -> V_5 . V_7 [ V_3 ] , 0x80 , V_38 ) ;
V_6 = F_17 ( V_39 , V_36 ) ;
if ( ! V_6 ) {
F_14 ( L_5 ) ;
for ( V_41 = 0 ; V_41 < V_3 ; V_41 ++ ) {
F_6 ( V_2 -> V_5 . V_6 [ V_41 ] ) ;
F_7 ( V_2 -> V_5 . V_7 [ V_41 ] ) ;
}
return - V_43 ;
}
V_6 -> V_2 = V_2 -> V_44 ;
V_6 -> V_8 = V_2 ;
V_6 -> V_45 = F_18 ( V_2 -> V_44 , V_46 ) ;
V_6 -> V_47 = V_48 ;
V_6 -> V_7 = V_2 -> V_5 . V_7 [ V_3 ] ;
V_6 -> V_49 = 1 ;
V_6 -> V_50 = F_8 ;
V_6 -> V_25 = V_39 ;
V_6 -> V_51 = V_38 ;
for ( V_41 = V_42 = 0 ; V_41 < V_39 ;
V_41 ++ , V_42 += V_40 ) {
V_6 -> V_27 [ V_41 ] . V_29 = V_42 ;
V_6 -> V_27 [ V_41 ] . V_26 =
V_40 ;
}
V_2 -> V_5 . V_6 [ V_3 ] = V_6 ;
}
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
V_37 = F_13 ( V_2 -> V_5 . V_6 [ V_3 ] , V_36 ) ;
if ( V_37 ) {
F_14 ( L_6 ) ;
F_1 ( V_2 ) ;
F_19 ( & V_2 -> V_22 , 0 ) ;
return V_37 ;
}
}
return 0 ;
}
static int F_20 ( struct V_14 * V_52 ,
T_1 V_53 )
{
struct V_16 * V_17 = V_52 -> V_17 ;
F_2 ( L_7 ) ;
if ( V_17 -> V_33 ) {
if ( V_17 -> V_54 > V_53 )
return 0 ;
F_21 ( V_17 -> V_33 ) ;
}
V_17 -> V_33 = F_22 ( V_53 ) ;
if ( ! V_17 -> V_33 )
return - V_43 ;
V_17 -> V_54 = V_53 ;
return 0 ;
}
static int F_23 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_24 ( V_15 ) ;
struct V_16 * V_17 = V_15 -> V_17 ;
int V_55 = 0 ;
F_2 ( L_8 ) ;
if ( ! V_2 ) {
F_25 ( L_9
L_10 ) ;
return - V_56 ;
}
V_17 -> V_57 = V_58 ;
if ( ( V_2 -> V_59 == 0 || V_2 -> V_60 ) && V_2 -> V_5 . V_61 == 0 ) {
if ( V_2 -> V_60 )
V_2 -> V_59 = 1 ;
else
V_2 -> V_59 = 7 ;
F_2 ( L_11 ,
V_2 -> V_60 , V_2 -> V_59 ) ;
F_26 ( V_2 -> V_44 , V_2 -> V_60 , V_2 -> V_59 ) ;
V_2 -> V_62 = 0 ;
F_27 ( & V_2 -> V_63 ) ;
V_55 = F_28 ( V_2 ) ;
if ( V_55 < 0 )
goto V_64;
V_2 -> V_5 . V_61 ++ ;
F_29 ( & V_2 -> V_63 ) ;
}
F_30 ( V_17 , V_65 ) ;
V_2 -> V_5 . V_23 = V_15 ;
V_17 -> V_66 = V_2 ;
return 0 ;
V_64:
F_29 ( & V_2 -> V_63 ) ;
F_25 ( L_12 ) ;
return V_55 ;
}
static int F_31 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_24 ( V_15 ) ;
F_2 ( L_13 ) ;
V_2 -> V_62 = 1 ;
F_27 ( & V_2 -> V_63 ) ;
V_2 -> V_5 . V_61 -- ;
if ( F_9 ( & V_2 -> V_22 ) > 0 ) {
F_19 ( & V_2 -> V_22 , 0 ) ;
F_32 ( & V_2 -> V_67 ) ;
}
F_28 ( V_2 ) ;
if ( V_15 -> V_17 -> V_33 ) {
F_2 ( L_14 ) ;
F_21 ( V_15 -> V_17 -> V_33 ) ;
V_15 -> V_17 -> V_33 = NULL ;
}
F_29 ( & V_2 -> V_63 ) ;
return 0 ;
}
static int F_33 ( struct V_14 * V_15 ,
struct V_68 * V_69 )
{
int V_55 ;
F_2 ( L_15 ) ;
V_55 = F_20 ( V_15 ,
F_34 ( V_69 ) ) ;
if ( V_55 < 0 )
return V_55 ;
#if 0
unsigned int channels, rate, format;
format = params_format(hw_params);
rate = params_rate(hw_params);
channels = params_channels(hw_params);
#endif
return 0 ;
}
static int F_35 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_24 ( V_15 ) ;
F_2 ( L_16 ) ;
if ( F_9 ( & V_2 -> V_22 ) > 0 ) {
F_19 ( & V_2 -> V_22 , 0 ) ;
F_32 ( & V_2 -> V_67 ) ;
}
return 0 ;
}
static int F_36 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_24 ( V_15 ) ;
V_2 -> V_5 . V_30 = 0 ;
V_2 -> V_5 . V_34 = 0 ;
return 0 ;
}
static void F_37 ( struct V_70 * V_71 )
{
struct V_1 * V_2 = F_38 ( V_71 , struct V_1 , V_67 ) ;
if ( F_9 ( & V_2 -> V_22 ) ) {
F_2 ( L_17 ) ;
F_15 ( V_2 ) ;
} else {
F_2 ( L_18 ) ;
F_1 ( V_2 ) ;
}
}
static int F_39 ( struct V_14 * V_15 ,
int V_72 )
{
struct V_1 * V_2 = F_24 ( V_15 ) ;
int V_73 = 0 ;
switch ( V_72 ) {
case V_74 :
case V_75 :
case V_76 :
F_19 ( & V_2 -> V_22 , 1 ) ;
break;
case V_77 :
case V_78 :
case V_79 :
F_19 ( & V_2 -> V_22 , 0 ) ;
break;
default:
V_73 = - V_80 ;
}
F_32 ( & V_2 -> V_67 ) ;
return V_73 ;
}
static T_2 F_40 ( struct V_14
* V_15 )
{
unsigned long V_81 ;
struct V_1 * V_2 ;
T_2 V_82 ;
V_2 = F_24 ( V_15 ) ;
F_41 ( & V_2 -> V_5 . V_83 , V_81 ) ;
V_82 = V_2 -> V_5 . V_30 ;
F_42 ( & V_2 -> V_5 . V_83 , V_81 ) ;
return V_82 ;
}
static struct V_84 * F_43 ( struct V_14 * V_52 ,
unsigned long V_29 )
{
void * V_85 = V_52 -> V_17 -> V_33 + V_29 ;
return F_44 ( V_85 ) ;
}
static int F_45 ( struct V_86 * V_87 ,
struct V_88 * V_89 )
{
V_89 -> type = V_90 ;
V_89 -> V_91 = 2 ;
V_89 -> V_92 . integer . V_93 = 0 ;
V_89 -> V_92 . integer . V_94 = 0x1f ;
return 0 ;
}
static int F_46 ( struct V_86 * V_87 ,
struct V_95 * V_92 )
{
struct V_1 * V_2 = F_47 ( V_87 ) ;
T_3 V_96 = ( 0x1f - ( V_92 -> V_92 . integer . V_92 [ 0 ] & 0x1f ) ) |
( 0x1f - ( V_92 -> V_92 . integer . V_92 [ 1 ] & 0x1f ) ) << 8 ;
int V_97 ;
F_27 ( & V_2 -> V_63 ) ;
V_97 = F_48 ( V_2 , V_87 -> V_98 ) ;
if ( V_97 < 0 )
goto V_64;
V_96 |= V_97 & 0x8000 ;
V_97 = F_49 ( V_2 , V_87 -> V_98 , V_96 ) ;
if ( V_97 < 0 )
goto V_64;
F_2 ( L_19 ,
( V_96 & 0x8000 ) ? L_20 : L_21 ,
0x1f - ( ( V_96 >> 8 ) & 0x1f ) , 0x1f - ( V_96 & 0x1f ) ,
V_96 , ( int ) V_87 -> V_98 ) ;
V_64:
F_29 ( & V_2 -> V_63 ) ;
return V_97 ;
}
static int F_50 ( struct V_86 * V_87 ,
struct V_95 * V_92 )
{
struct V_1 * V_2 = F_47 ( V_87 ) ;
int V_96 ;
F_27 ( & V_2 -> V_63 ) ;
V_96 = F_48 ( V_2 , V_87 -> V_98 ) ;
F_29 ( & V_2 -> V_63 ) ;
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
static int F_51 ( struct V_86 * V_87 ,
struct V_95 * V_92 )
{
struct V_1 * V_2 = F_47 ( V_87 ) ;
T_3 V_96 = V_92 -> V_92 . integer . V_92 [ 0 ] ;
int V_97 ;
F_27 ( & V_2 -> V_63 ) ;
V_97 = F_48 ( V_2 , V_87 -> V_98 ) ;
if ( V_97 < 0 )
goto V_64;
if ( V_96 )
V_97 &= 0x1f1f ;
else
V_97 |= 0x8000 ;
V_97 = F_49 ( V_2 , V_87 -> V_98 , V_97 ) ;
if ( V_97 < 0 )
goto V_64;
F_2 ( L_19 ,
( V_96 & 0x8000 ) ? L_20 : L_21 ,
0x1f - ( ( V_96 >> 8 ) & 0x1f ) , 0x1f - ( V_96 & 0x1f ) ,
V_96 , ( int ) V_87 -> V_98 ) ;
V_64:
F_29 ( & V_2 -> V_63 ) ;
return V_97 ;
}
static int F_52 ( struct V_86 * V_87 ,
struct V_95 * V_92 )
{
struct V_1 * V_2 = F_47 ( V_87 ) ;
int V_96 ;
F_27 ( & V_2 -> V_63 ) ;
V_96 = F_48 ( V_2 , V_87 -> V_98 ) ;
F_29 ( & V_2 -> V_63 ) ;
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
static int F_53 ( struct V_99 * V_100 , struct V_1 * V_2 ,
char * V_101 , int V_102 )
{
int V_64 ;
char V_103 [ 44 ] ;
struct V_86 * V_104 ;
struct V_105 V_106 ;
memset ( & V_106 , 0 , sizeof( V_106 ) ) ;
V_106 . V_107 = V_108 ,
V_106 . V_98 = V_102 ,
V_106 . V_101 = V_103 ,
sprintf ( V_103 , L_23 , V_101 ) ;
V_106 . V_109 = F_52 ;
V_106 . V_110 = F_51 ;
V_106 . V_89 = V_111 ;
V_104 = F_54 ( & V_106 , V_2 ) ;
V_64 = F_55 ( V_100 , V_104 ) ;
if ( V_64 < 0 )
return V_64 ;
F_2 ( L_24 ,
V_103 , V_102 ) ;
memset ( & V_106 , 0 , sizeof( V_106 ) ) ;
V_106 . V_107 = V_108 ,
V_106 . V_98 = V_102 ,
V_106 . V_101 = V_103 ,
sprintf ( V_103 , L_25 , V_101 ) ;
V_106 . V_109 = F_50 ;
V_106 . V_110 = F_46 ;
V_106 . V_89 = F_45 ;
V_106 . V_112 . V_113 = V_114 ,
V_104 = F_54 ( & V_106 , V_2 ) ;
V_64 = F_55 ( V_100 , V_104 ) ;
if ( V_64 < 0 )
return V_64 ;
F_2 ( L_24 ,
V_103 , V_102 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_115 * V_5 = & V_2 -> V_5 ;
struct V_116 * V_117 ;
struct V_99 * V_100 ;
static int V_118 ;
int V_64 ;
if ( ! V_2 -> V_119 || V_2 -> V_60 < 0 ) {
return 0 ;
}
F_57 ( V_120 L_26 ) ;
F_57 ( V_120 L_27
L_28 ) ;
F_57 ( V_120 L_29 ) ;
V_64 = F_58 ( V_121 [ V_118 ] , L_30 , V_122 , 0 ,
& V_100 ) ;
if ( V_64 < 0 )
return V_64 ;
F_59 ( & V_5 -> V_83 ) ;
V_64 = F_60 ( V_100 , L_30 , 0 , 0 , 1 , & V_117 ) ;
if ( V_64 < 0 ) {
F_61 ( V_100 ) ;
return V_64 ;
}
F_62 ( V_117 , V_123 , & V_124 ) ;
V_117 -> V_125 = 0 ;
V_117 -> V_66 = V_2 ;
strcpy ( V_117 -> V_101 , L_31 ) ;
F_63 ( V_100 , & V_2 -> V_44 -> V_2 ) ;
strcpy ( V_100 -> V_126 , L_32 ) ;
strcpy ( V_100 -> V_127 , L_30 ) ;
strcpy ( V_100 -> V_128 , L_33 ) ;
F_64 ( & V_2 -> V_67 , F_37 ) ;
if ( V_2 -> V_129 . V_130 != V_131 ) {
F_53 ( V_100 , V_2 , L_34 , V_132 ) ;
F_53 ( V_100 , V_2 , L_35 , V_133 ) ;
F_53 ( V_100 , V_2 , L_36 , V_134 ) ;
F_53 ( V_100 , V_2 , L_37 , V_134 ) ;
F_53 ( V_100 , V_2 , L_38 , V_135 ) ;
F_53 ( V_100 , V_2 , L_39 , V_136 ) ;
F_53 ( V_100 , V_2 , L_40 , V_137 ) ;
F_53 ( V_100 , V_2 , L_41 , V_138 ) ;
F_53 ( V_100 , V_2 , L_42 , V_139 ) ;
F_53 ( V_100 , V_2 , L_43 , V_140 ) ;
F_53 ( V_100 , V_2 , L_44 , V_141 ) ;
F_53 ( V_100 , V_2 , L_45 , V_142 ) ;
}
V_64 = F_65 ( V_100 ) ;
if ( V_64 < 0 ) {
F_61 ( V_100 ) ;
return V_64 ;
}
V_5 -> V_143 = V_100 ;
V_5 -> V_44 = V_2 -> V_44 ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return 0 ;
if ( V_2 -> V_119 != 1 ) {
return 0 ;
}
if ( V_2 -> V_5 . V_143 ) {
F_61 ( V_2 -> V_5 . V_143 ) ;
V_2 -> V_5 . V_143 = NULL ;
}
return 0 ;
}
static int T_4 F_67 ( void )
{
return F_68 ( & V_144 ) ;
}
static void T_5 F_69 ( void )
{
F_70 ( & V_144 ) ;
}
