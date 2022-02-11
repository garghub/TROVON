static int F_1 ( struct V_1 * V_2 , unsigned char * V_3 )
{
int V_4 = 0 ;
V_3 [ V_4 ++ ] = ( 0x6 << 4 ) ;
V_3 [ V_4 ++ ] = 0x01 ;
V_3 [ V_4 ++ ] = 0x40 ;
V_3 [ V_4 ] = ( 0x5 << 4 ) ;
F_2 ( V_2 , & V_3 [ V_4 ] ) ;
return 0 ;
}
static int F_3 ( const unsigned char * V_5 ,
struct V_1 * * V_6 )
{
struct V_1 * V_7 ;
unsigned char V_8 [ V_9 ] ;
int V_10 ;
F_4 ( & V_11 ) ;
F_5 (se_dev, &g_device_list, g_dev_node) {
if ( ! V_7 -> V_12 . V_13 )
continue;
memset ( & V_8 [ 0 ] , 0 , V_9 ) ;
F_1 ( V_7 , & V_8 [ 0 ] ) ;
V_10 = memcmp ( & V_8 [ 0 ] , V_5 , V_9 ) ;
if ( V_10 != 0 )
continue;
* V_6 = V_7 ;
F_6 ( L_1 , V_7 ) ;
V_10 = F_7 ( & V_7 -> V_14 . V_15 ) ;
if ( V_10 != 0 ) {
F_8 ( L_2
L_3 , V_10 , V_7 ) ;
F_9 ( & V_11 ) ;
return V_10 ;
}
F_6 ( L_4
L_5 , V_7 ,
& V_7 -> V_14 ) ;
F_9 ( & V_11 ) ;
return 0 ;
}
F_9 ( & V_11 ) ;
F_10 ( L_6 ) ;
return - V_16 ;
}
static int F_11 ( struct V_17 * V_17 , struct V_18 * V_19 ,
unsigned char * V_20 , unsigned short V_21 )
{
unsigned char * V_22 = V_20 ;
unsigned short V_23 ;
T_1 V_24 ;
V_23 = F_12 ( & V_22 [ 2 ] ) ;
F_6 ( L_7 , V_23 ) ;
if ( ( V_22 [ 4 ] & 0x0f ) != 0x1 ) {
F_8 ( L_8 ) ;
return - V_16 ;
}
if ( ( V_22 [ 5 ] & 0x30 ) != 0x00 ) {
F_8 ( L_9 ) ;
return - V_16 ;
}
if ( ( V_22 [ 5 ] & 0x0f ) != 0x3 ) {
F_8 ( L_10 ,
( V_22 [ 5 ] & 0x0f ) ) ;
return - V_16 ;
}
V_24 = V_22 [ 7 ] ;
if ( V_24 != 16 ) {
F_8 ( L_11 , ( int ) V_24 ) ;
return - V_16 ;
}
F_6 ( L_12 , ( int ) V_24 ) ;
if ( ( V_22 [ 8 ] & 0xf0 ) != 0x60 ) {
F_8 ( L_13 ,
( V_22 [ 8 ] & 0xf0 ) ) ;
return - V_16 ;
}
if ( V_21 != V_19 -> V_25 && V_21 != V_19 -> V_26 ) {
F_6 ( L_14
L_15 , V_21 ) ;
return 0 ;
}
if ( V_21 == V_19 -> V_25 ) {
memcpy ( & V_19 -> V_27 [ 0 ] , & V_22 [ 8 ] , V_9 ) ;
if ( ! memcmp ( & V_19 -> V_28 [ 0 ] , & V_19 -> V_27 [ 0 ] ,
V_9 ) ) {
V_19 -> V_29 = V_30 ;
V_19 -> V_31 = V_17 -> V_7 ;
F_6 ( L_16
L_17 , V_19 -> V_31 ) ;
}
}
if ( V_21 == V_19 -> V_26 ) {
memcpy ( & V_19 -> V_32 [ 0 ] , & V_22 [ 8 ] , V_9 ) ;
if ( ! memcmp ( & V_19 -> V_28 [ 0 ] , & V_19 -> V_32 [ 0 ] ,
V_9 ) ) {
V_19 -> V_29 = V_33 ;
V_19 -> V_34 = V_17 -> V_7 ;
F_6 ( L_18
L_17 , V_19 -> V_34 ) ;
}
}
return 0 ;
}
static int F_13 ( struct V_17 * V_17 ,
struct V_18 * V_19 , unsigned char * V_20 ,
unsigned short V_35 , T_2 * V_36 )
{
struct V_1 * V_37 = V_17 -> V_7 ;
unsigned char * V_22 = V_20 ;
int V_38 = V_35 % V_39 , V_10 ;
unsigned short V_21 = 0 ;
unsigned short V_40 = 0 ;
* V_36 = V_41 ;
if ( V_38 != 0 ) {
F_8 ( L_19
L_20 , V_39 ) ;
* V_36 = V_42 ;
return - V_16 ;
}
if ( V_35 > V_43 * V_39 ) {
F_8 ( L_21
L_22 , V_35 ) ;
* V_36 = V_44 ;
return - V_16 ;
}
memset ( & V_19 -> V_28 [ 0 ] , 0 , V_9 ) ;
F_1 ( V_37 , & V_19 -> V_28 [ 0 ] ) ;
while ( V_40 < V_35 ) {
switch ( V_22 [ 0 ] ) {
case 0xe4 :
V_10 = F_11 ( V_17 , V_19 ,
& V_22 [ 0 ] , V_21 ) ;
if ( V_10 != 0 )
goto V_45;
V_40 += V_39 ;
V_22 += V_39 ;
V_21 ++ ;
break;
default:
F_8 ( L_23
L_24 , V_22 [ 0 ] ) ;
* V_36 = V_42 ;
goto V_45;
}
}
switch ( V_19 -> V_29 ) {
case V_30 :
V_10 = F_3 ( V_19 -> V_32 ,
& V_19 -> V_34 ) ;
break;
case V_33 :
V_10 = F_3 ( V_19 -> V_27 ,
& V_19 -> V_31 ) ;
break;
default:
F_8 ( L_25
L_26 , V_19 -> V_25 , V_19 -> V_26 ) ;
V_10 = - V_16 ;
break;
}
if ( V_10 < 0 ) {
* V_36 = V_46 ;
goto V_45;
}
F_6 ( L_27 ,
V_19 -> V_31 , & V_19 -> V_27 [ 0 ] ) ;
F_6 ( L_28 ,
V_19 -> V_34 , & V_19 -> V_32 [ 0 ] ) ;
return V_21 ;
V_45:
return - V_16 ;
}
static int F_14 ( struct V_17 * V_17 , struct V_18 * V_19 ,
unsigned char * V_20 )
{
unsigned char * V_22 = V_20 ;
int V_47 = ( V_22 [ 1 ] & 0x02 ) ;
unsigned short V_48 ;
V_48 = F_12 ( & V_22 [ 2 ] ) ;
if ( V_48 != 0x18 ) {
F_8 ( L_29
L_30 , V_48 ) ;
return - V_16 ;
}
V_19 -> V_25 = F_12 ( & V_22 [ 4 ] ) ;
V_19 -> V_26 = F_12 ( & V_22 [ 6 ] ) ;
if ( V_19 -> V_25 > V_49 ||
V_19 -> V_26 > V_49 ) {
F_8 ( L_31 ,
V_49 , V_19 -> V_25 , V_19 -> V_26 ) ;
return - V_16 ;
}
F_6 ( L_32 ,
V_48 , V_19 -> V_25 , V_19 -> V_26 , V_47 ) ;
V_19 -> V_50 = F_12 ( & V_22 [ 10 ] ) ;
V_19 -> V_51 = F_15 ( & V_22 [ 12 ] ) ;
V_19 -> V_52 = F_15 ( & V_22 [ 20 ] ) ;
F_6 ( L_33 ,
V_19 -> V_50 , ( unsigned long long ) V_19 -> V_51 ,
( unsigned long long ) V_19 -> V_52 ) ;
if ( V_47 != 0 ) {
V_19 -> V_53 = ( V_22 [ 29 ] & 0xff ) << 16 ;
V_19 -> V_53 |= ( V_22 [ 30 ] & 0xff ) << 8 ;
V_19 -> V_53 |= V_22 [ 31 ] & 0xff ;
F_6 ( L_34 , V_19 -> V_53 ) ;
}
return 0 ;
}
static int F_16 ( struct V_17 * V_17 ,
struct V_18 * V_19 , unsigned char * V_20 ,
unsigned int V_54 , T_2 * V_36 )
{
unsigned char * V_22 = V_20 ;
unsigned int V_40 = 0 ;
int V_38 = V_54 % V_55 , V_10 , V_56 = 0 ;
* V_36 = V_41 ;
if ( V_38 != 0 ) {
F_8 ( L_35
L_20 , V_55 ) ;
* V_36 = V_57 ;
return - V_16 ;
}
if ( V_54 > V_58 * V_55 ) {
F_8 ( L_36
L_37 , V_58 , V_54 ) ;
* V_36 = V_59 ;
return - V_16 ;
}
while ( V_40 < V_54 ) {
switch ( V_22 [ 0 ] ) {
case 0x02 :
V_10 = F_14 ( V_17 , V_19 , V_22 ) ;
if ( V_10 < 0 )
goto V_45;
V_56 ++ ;
V_40 += V_55 ;
V_22 += V_55 ;
break;
default:
F_8 ( L_38
L_39 , V_22 [ 0 ] ) ;
* V_36 = V_57 ;
goto V_45;
}
}
return V_56 ;
V_45:
return - V_16 ;
}
static char * F_17 ( void )
{
return L_40 ;
}
static int F_18 ( struct V_17 * V_17 )
{
return 0 ;
}
static void F_19 ( struct V_18 * V_19 )
{
struct V_1 * V_60 ;
if ( V_19 -> V_29 == V_30 )
V_60 = V_19 -> V_34 ;
else
V_60 = V_19 -> V_31 ;
F_6 ( L_41
L_42 ,
V_60 , & V_60 -> V_14 . V_15 ) ;
F_20 ( & V_60 -> V_14 . V_15 ) ;
}
static void F_21 ( struct V_17 * V_17 )
{
struct V_61 * V_62 = F_22 ( V_17 ,
struct V_61 , V_17 ) ;
F_23 ( V_62 ) ;
}
static int F_24 ( struct V_17 * V_17 )
{
struct V_61 * V_62 = F_22 ( V_17 ,
struct V_61 , V_17 ) ;
F_25 ( & V_62 -> V_63 ) ;
return 0 ;
}
static int F_26 ( struct V_17 * V_17 )
{
return 0 ;
}
static int F_27 ( struct V_17 * V_17 )
{
return 0 ;
}
static int F_28 ( struct V_17 * V_17 )
{
return 0 ;
}
static int F_29 ( struct V_17 * V_17 )
{
return 0 ;
}
int F_30 ( void )
{
V_64 = F_31 ( L_43 , V_65 , 0 ) ;
if ( ! V_64 ) {
F_8 ( L_44 ) ;
return - V_66 ;
}
memset ( & V_67 , 0 , sizeof( struct V_68 ) ) ;
F_32 ( & V_67 . V_69 ) ;
F_32 ( & V_67 . V_70 ) ;
F_32 ( & V_67 . V_71 ) ;
V_67 . V_72 = & V_73 ;
memset ( & V_74 , 0 , sizeof( struct V_75 ) ) ;
F_32 ( & V_74 . V_76 ) ;
F_32 ( & V_74 . V_77 ) ;
memset ( & V_78 , 0 , sizeof( struct V_79 ) ) ;
F_32 ( & V_78 . V_80 ) ;
F_32 ( & V_78 . V_81 ) ;
F_32 ( & V_78 . V_82 ) ;
F_33 ( & V_78 . V_83 ) ;
V_74 . V_84 = & V_67 ;
V_74 . V_85 = & V_78 ;
V_78 . V_84 = & V_67 ;
V_78 . V_75 = & V_74 ;
return 0 ;
}
void F_34 ( void )
{
if ( V_64 )
F_35 ( V_64 ) ;
}
static void F_36 (
struct V_61 * V_62 ,
struct V_18 * V_19 ,
bool V_86 )
{
struct V_17 * V_87 = V_19 -> V_88 ;
struct V_17 * V_89 = & V_62 -> V_17 ;
if ( V_19 -> V_29 == V_30 ) {
if ( V_86 ) {
V_62 -> V_86 = V_86 ;
} else {
V_89 -> V_90 = V_87 -> V_90 ;
V_89 -> V_7 = V_87 -> V_7 ;
F_6 ( L_45
L_46 , V_89 -> V_7 ) ;
V_89 -> V_90 = V_87 -> V_90 ;
F_6 ( L_47 ,
V_89 -> V_90 ) ;
}
} else {
if ( V_86 ) {
V_62 -> V_86 = V_86 ;
} else {
V_89 -> V_90 = V_87 -> V_90 ;
V_89 -> V_7 = V_87 -> V_7 ;
F_6 ( L_48
L_46 , V_89 -> V_7 ) ;
V_89 -> V_90 = V_87 -> V_90 ;
F_6 ( L_49 ,
V_89 -> V_90 ) ;
}
}
}
static void F_37 ( struct V_1 * V_7 ,
struct V_17 * V_89 , bool V_86 )
{
if ( V_86 ) {
F_6 ( L_50 ,
V_89 -> V_7 ) ;
V_89 -> V_90 = & V_7 -> V_91 ;
V_89 -> V_7 = V_7 ;
}
V_89 -> V_92 |= V_93 ;
}
static int F_38 (
struct V_61 * V_62 ,
struct V_18 * V_19 ,
struct V_1 * V_7 ,
unsigned char * V_94 ,
bool V_86 ,
bool V_95 )
{
struct V_17 * V_96 = & V_62 -> V_17 ;
T_2 V_97 ;
int V_56 = 0 , V_10 ;
F_37 ( V_7 , V_96 , V_86 ) ;
V_62 -> V_18 = V_19 ;
F_36 ( V_62 , V_19 , V_86 ) ;
V_96 -> V_98 = 0 ;
V_97 = F_39 ( V_96 , V_94 ) ;
if ( V_97 ) {
V_56 = - V_16 ;
goto V_45;
}
if ( V_95 ) {
V_10 = F_40 ( & V_96 -> V_99 , & V_96 -> V_100 ,
V_96 -> V_101 , false , false ) ;
if ( V_10 < 0 ) {
V_56 = V_10 ;
goto V_45;
}
V_96 -> V_92 |= V_102 ;
} else {
V_97 = F_41 ( V_96 ,
V_19 -> V_103 , V_19 -> V_104 ,
NULL , 0 ) ;
if ( V_97 ) {
V_56 = - V_16 ;
goto V_45;
}
F_6 ( L_51
L_52 , V_96 -> V_99 , V_96 -> V_100 ) ;
}
return 0 ;
V_45:
return V_56 ;
}
static int F_42 ( struct V_61 * V_62 )
{
struct V_17 * V_17 = & V_62 -> V_17 ;
T_2 V_97 ;
V_97 = F_43 ( V_17 ) ;
if ( V_97 )
return - V_16 ;
if ( V_17 -> V_105 == V_106 )
F_44 ( V_17 ) ;
F_45 ( & V_62 -> V_63 ) ;
F_6 ( L_53 ,
V_17 -> V_107 ) ;
return ( V_17 -> V_107 ) ? - V_16 : 0 ;
}
static int F_46 (
struct V_17 * V_87 ,
struct V_18 * V_19 ,
struct V_1 * V_31 ,
T_3 V_51 ,
T_4 V_108 )
{
struct V_61 * V_62 ;
struct V_17 * V_17 ;
T_4 V_109 = ( V_108 * V_31 -> V_12 . V_110 ) ;
int V_10 ;
unsigned char V_94 [ 16 ] ;
bool V_86 = ( V_19 -> V_29 == V_33 ) ;
V_62 = F_47 ( sizeof( struct V_61 ) , V_111 ) ;
if ( ! V_62 ) {
F_8 ( L_54 ) ;
return - V_66 ;
}
F_48 ( & V_62 -> V_63 ) ;
V_17 = & V_62 -> V_17 ;
memset ( & V_94 [ 0 ] , 0 , 16 ) ;
V_94 [ 0 ] = V_112 ;
F_49 ( V_51 , & V_94 [ 2 ] ) ;
F_50 ( V_108 , & V_94 [ 10 ] ) ;
F_6 ( L_55 ,
( unsigned long long ) V_51 , V_108 , V_109 ) ;
F_51 ( V_17 , & V_73 , & V_78 , V_109 ,
V_113 , 0 , & V_62 -> V_114 [ 0 ] ) ;
V_19 -> V_115 = V_62 ;
V_10 = F_38 ( V_62 , V_19 , V_31 , & V_94 [ 0 ] ,
V_86 , true ) ;
if ( V_10 < 0 ) {
V_87 -> V_107 = V_62 -> V_17 . V_107 ;
F_52 ( V_17 , 0 ) ;
return V_10 ;
}
V_19 -> V_103 = V_17 -> V_99 ;
V_19 -> V_104 = V_17 -> V_100 ;
F_6 ( L_56
L_57 , V_19 -> V_103 , V_19 -> V_104 ) ;
V_10 = F_42 ( V_62 ) ;
if ( V_10 < 0 ) {
V_87 -> V_107 = V_62 -> V_17 . V_107 ;
F_52 ( V_17 , 0 ) ;
return V_10 ;
}
V_17 -> V_99 = NULL ;
V_17 -> V_100 = 0 ;
return 0 ;
}
static int F_53 (
struct V_17 * V_87 ,
struct V_18 * V_19 ,
struct V_1 * V_34 ,
T_3 V_52 ,
T_4 V_116 )
{
struct V_61 * V_62 ;
struct V_17 * V_17 ;
T_4 V_109 = ( V_116 * V_34 -> V_12 . V_110 ) ;
int V_10 ;
unsigned char V_94 [ 16 ] ;
bool V_86 = ( V_19 -> V_29 == V_30 ) ;
V_62 = F_47 ( sizeof( struct V_61 ) , V_111 ) ;
if ( ! V_62 ) {
F_8 ( L_54 ) ;
return - V_66 ;
}
F_48 ( & V_62 -> V_63 ) ;
V_17 = & V_62 -> V_17 ;
memset ( & V_94 [ 0 ] , 0 , 16 ) ;
V_94 [ 0 ] = V_117 ;
F_49 ( V_52 , & V_94 [ 2 ] ) ;
F_50 ( V_116 , & V_94 [ 10 ] ) ;
F_6 ( L_58 ,
( unsigned long long ) V_52 , V_116 , V_109 ) ;
F_51 ( V_17 , & V_73 , & V_78 , V_109 ,
V_106 , 0 , & V_62 -> V_114 [ 0 ] ) ;
V_19 -> V_118 = V_62 ;
V_10 = F_38 ( V_62 , V_19 , V_34 , & V_94 [ 0 ] ,
V_86 , false ) ;
if ( V_10 < 0 ) {
struct V_17 * V_119 = & V_19 -> V_115 -> V_17 ;
V_87 -> V_107 = V_62 -> V_17 . V_107 ;
V_119 -> V_92 &= ~ V_102 ;
V_119 -> V_99 = V_19 -> V_103 ;
V_119 -> V_100 = V_19 -> V_104 ;
F_52 ( V_17 , 0 ) ;
return V_10 ;
}
V_10 = F_42 ( V_62 ) ;
if ( V_10 < 0 ) {
V_87 -> V_107 = V_62 -> V_17 . V_107 ;
V_17 -> V_92 &= ~ V_102 ;
F_52 ( V_17 , 0 ) ;
return V_10 ;
}
return 0 ;
}
static void F_54 ( struct V_120 * V_121 )
{
struct V_18 * V_19 = F_22 ( V_121 , struct V_18 , V_122 ) ;
struct V_1 * V_31 = V_19 -> V_31 , * V_34 = V_19 -> V_34 ;
struct V_17 * V_87 = V_19 -> V_88 ;
T_3 V_51 = V_19 -> V_51 , V_52 = V_19 -> V_52 , V_123 ;
unsigned int V_124 ;
int V_10 ;
unsigned short V_50 = V_19 -> V_50 , V_125 , V_126 , V_127 = 0 ;
V_123 = V_51 + V_50 ;
V_124 = F_55 ( V_31 -> V_12 . V_128 ,
V_34 -> V_12 . V_128 ) ;
V_124 = F_56 ( T_4 , V_124 , V_129 ) ;
V_126 = F_56 ( V_130 , V_124 , ( ( V_130 ) ( ~ 0U ) ) ) ;
F_6 ( L_59 ,
V_50 , V_126 , ( unsigned long long ) V_123 ) ;
F_6 ( L_60 ,
( unsigned long long ) V_51 , ( unsigned long long ) V_52 ) ;
while ( V_51 < V_123 ) {
V_125 = F_55 ( V_50 , V_126 ) ;
F_6 ( L_61
L_62 , V_31 , ( unsigned long long ) V_51 , V_125 ) ;
V_10 = F_46 ( V_87 , V_19 , V_31 , V_51 , V_125 ) ;
if ( V_10 < 0 )
goto V_45;
V_51 += V_125 ;
F_6 ( L_63 ,
( unsigned long long ) V_51 ) ;
F_6 ( L_64
L_62 , V_34 , ( unsigned long long ) V_52 , V_125 ) ;
V_10 = F_53 ( V_87 , V_19 , V_34 ,
V_52 , V_125 ) ;
if ( V_10 < 0 ) {
F_52 ( & V_19 -> V_115 -> V_17 , 0 ) ;
goto V_45;
}
V_52 += V_125 ;
F_6 ( L_65 ,
( unsigned long long ) V_52 ) ;
V_127 += V_125 ;
V_50 -= V_125 ;
F_52 ( & V_19 -> V_115 -> V_17 , 0 ) ;
V_19 -> V_118 -> V_17 . V_92 &= ~ V_102 ;
F_52 ( & V_19 -> V_118 -> V_17 , 0 ) ;
}
F_19 ( V_19 ) ;
F_23 ( V_19 ) ;
F_6 ( L_66 ,
( unsigned long long ) V_51 , ( unsigned long long ) V_52 ) ;
F_6 ( L_67 ,
V_127 , V_127 * V_34 -> V_12 . V_110 ) ;
F_6 ( L_68 ) ;
F_57 ( V_87 , V_131 ) ;
return;
V_45:
F_19 ( V_19 ) ;
F_23 ( V_19 ) ;
if ( V_87 -> V_107 == V_131 ) {
F_58 ( L_69
L_70 , V_10 ) ;
V_87 -> V_107 = V_132 ;
}
F_57 ( V_87 , V_87 -> V_107 ) ;
}
T_2 F_59 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_7 ;
struct V_18 * V_19 = NULL ;
unsigned char * V_20 = NULL , * V_133 ;
unsigned int V_134 , V_135 , V_54 , V_136 , V_137 ;
T_2 V_56 = V_41 ;
int V_10 ;
unsigned short V_35 ;
if ( ! V_2 -> V_12 . V_13 ) {
F_8 ( L_71 ) ;
return V_138 ;
}
V_137 = V_17 -> V_139 [ 1 ] & 0x1f ;
if ( V_137 != 0x00 ) {
F_8 ( L_72 ) ;
return V_138 ;
}
if ( V_17 -> V_101 == 0 ) {
F_57 ( V_17 , V_131 ) ;
return V_140 ;
}
if ( V_17 -> V_101 < V_141 ) {
F_8 ( L_73 ,
V_17 -> V_101 , V_141 ) ;
return V_142 ;
}
V_19 = F_47 ( sizeof( struct V_18 ) , V_111 ) ;
if ( ! V_19 ) {
F_8 ( L_74 ) ;
return V_143 ;
}
V_19 -> V_88 = V_17 ;
V_20 = F_60 ( V_17 ) ;
if ( ! V_20 ) {
F_8 ( L_75 ) ;
F_23 ( V_19 ) ;
return V_143 ;
}
V_134 = V_20 [ 0 ] ;
V_135 = ( V_20 [ 1 ] & 0x18 ) >> 3 ;
V_35 = F_12 ( & V_20 [ 2 ] ) ;
V_54 = F_61 ( & V_20 [ 8 ] ) ;
if ( V_35 + V_54 > V_144 ) {
F_8 ( L_76 ,
V_35 + V_54 , V_144 ) ;
V_56 = V_142 ;
goto V_45;
}
V_136 = F_61 ( & V_20 [ 12 ] ) ;
if ( V_136 != 0 ) {
F_8 ( L_77 ) ;
goto V_45;
}
if ( V_17 -> V_101 < ( V_141 + V_35 + V_54 + V_136 ) ) {
F_8 ( L_78
L_79 ,
V_17 -> V_101 , V_35 , V_54 , V_136 ) ;
V_56 = V_142 ;
goto V_45;
}
F_6 ( L_80
L_81 , V_134 , V_135 ,
V_35 , V_54 , V_136 ) ;
V_133 = & V_20 [ 16 ] + V_35 ;
V_10 = F_16 ( V_17 , V_19 , V_133 ,
V_54 , & V_56 ) ;
if ( V_10 <= 0 )
goto V_45;
F_6 ( L_82 , V_10 ,
V_10 * V_55 ) ;
V_10 = F_13 ( V_17 , V_19 , & V_20 [ 16 ] , V_35 , & V_56 ) ;
if ( V_10 <= 0 )
goto V_45;
if ( V_19 -> V_31 -> V_12 . V_110 !=
V_19 -> V_34 -> V_12 . V_110 ) {
F_8 ( L_83
L_84 ,
V_19 -> V_31 -> V_12 . V_110 ,
V_19 -> V_34 -> V_12 . V_110 ) ;
F_19 ( V_19 ) ;
V_56 = V_145 ;
goto V_45;
}
F_6 ( L_85 , V_10 ,
V_10 * V_39 ) ;
F_62 ( V_17 ) ;
F_63 ( & V_19 -> V_122 , F_54 ) ;
F_64 ( V_64 , & V_19 -> V_122 ) ;
return V_140 ;
V_45:
if ( V_20 )
F_62 ( V_17 ) ;
F_23 ( V_19 ) ;
return V_56 ;
}
static T_2 F_65 ( struct V_17 * V_17 )
{
unsigned char * V_20 ;
V_20 = F_60 ( V_17 ) ;
if ( ! V_20 ) {
F_8 ( L_86
L_87 ) ;
return V_143 ;
}
if ( V_17 -> V_101 < 54 ) {
F_8 ( L_88
L_89 , V_17 -> V_101 ) ;
F_62 ( V_17 ) ;
return V_146 ;
}
V_20 [ 4 ] = 0x1 ;
F_66 ( V_43 , & V_20 [ 8 ] ) ;
F_66 ( V_58 , & V_20 [ 10 ] ) ;
F_50 ( V_144 , & V_20 [ 12 ] ) ;
F_50 ( V_147 , & V_20 [ 16 ] ) ;
F_50 ( 0x0 , & V_20 [ 20 ] ) ;
F_50 ( 0x0 , & V_20 [ 24 ] ) ;
F_50 ( 0x0 , & V_20 [ 28 ] ) ;
F_66 ( V_148 , & V_20 [ 34 ] ) ;
V_20 [ 36 ] = V_149 ;
V_20 [ 37 ] = V_150 ;
V_20 [ 38 ] = V_151 ;
V_20 [ 39 ] = V_152 ;
V_20 [ 43 ] = 0x2 ;
V_20 [ 44 ] = 0x02 ;
V_20 [ 45 ] = 0xe4 ;
F_50 ( 42 , & V_20 [ 0 ] ) ;
F_62 ( V_17 ) ;
F_57 ( V_17 , V_153 ) ;
return V_140 ;
}
T_2 F_67 ( struct V_17 * V_17 )
{
unsigned char * V_94 = & V_17 -> V_139 [ 0 ] ;
int V_137 = ( V_94 [ 1 ] & 0x1f ) , V_134 = V_94 [ 2 ] ;
T_2 V_10 = V_140 ;
F_6 ( L_90
L_91 , V_137 , V_134 , V_17 -> V_101 ) ;
if ( V_134 != 0 ) {
F_8 ( L_92
L_93 ) ;
return V_146 ;
}
switch ( V_137 ) {
case V_154 :
V_10 = F_65 ( V_17 ) ;
break;
case V_155 :
case V_156 :
case V_157 :
default:
F_8 ( L_94 , V_137 ) ;
return V_146 ;
}
return V_10 ;
}
