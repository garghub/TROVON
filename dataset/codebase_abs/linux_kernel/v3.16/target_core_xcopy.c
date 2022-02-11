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
static int F_3 ( struct V_5 * V_5 , struct V_6 * V_7 ,
bool V_8 )
{
struct V_1 * V_9 ;
struct V_10 * V_11 = V_12 [ 0 ] ;
unsigned char V_13 [ V_14 ] , * V_15 ;
int V_16 ;
if ( V_8 )
V_15 = & V_7 -> V_17 [ 0 ] ;
else
V_15 = & V_7 -> V_18 [ 0 ] ;
F_4 ( & V_19 ) ;
F_5 (se_dev, &g_device_list, g_dev_node) {
if ( ! V_9 -> V_20 . V_21 )
continue;
memset ( & V_13 [ 0 ] , 0 , V_14 ) ;
F_1 ( V_9 , & V_13 [ 0 ] ) ;
V_16 = memcmp ( & V_13 [ 0 ] , V_15 , V_14 ) ;
if ( V_16 != 0 )
continue;
if ( V_8 ) {
V_7 -> V_22 = V_9 ;
F_6 ( L_1
L_2 , V_7 -> V_22 ) ;
} else {
V_7 -> V_23 = V_9 ;
F_6 ( L_3
L_2 , V_7 -> V_23 ) ;
}
V_16 = F_7 ( V_11 ,
& V_9 -> V_24 . V_25 ) ;
if ( V_16 != 0 ) {
F_8 ( L_4
L_5 , V_16 , V_9 ) ;
F_9 ( & V_19 ) ;
return V_16 ;
}
F_6 ( L_6
L_7 , V_11 , V_9 ,
& V_9 -> V_24 ) ;
F_9 ( & V_19 ) ;
return 0 ;
}
F_9 ( & V_19 ) ;
F_8 ( L_8 ) ;
return - V_26 ;
}
static int F_10 ( struct V_5 * V_5 , struct V_6 * V_7 ,
unsigned char * V_27 , bool V_8 )
{
unsigned char * V_28 = V_27 ;
unsigned short V_29 ;
T_1 V_30 ;
V_29 = F_11 ( & V_28 [ 2 ] ) ;
F_6 ( L_9 , V_29 ) ;
if ( ( V_28 [ 4 ] & 0x0f ) != 0x1 ) {
F_8 ( L_10 ) ;
return - V_26 ;
}
if ( ( V_28 [ 5 ] & 0x30 ) != 0x00 ) {
F_8 ( L_11 ) ;
return - V_26 ;
}
if ( ( V_28 [ 5 ] & 0x0f ) != 0x3 ) {
F_8 ( L_12 ,
( V_28 [ 5 ] & 0x0f ) ) ;
return - V_26 ;
}
V_30 = V_28 [ 7 ] ;
if ( V_30 != 16 ) {
F_8 ( L_13 , ( int ) V_30 ) ;
return - V_26 ;
}
F_6 ( L_14 , ( int ) V_30 ) ;
if ( ( V_28 [ 8 ] & 0xf0 ) != 0x60 ) {
F_8 ( L_15 ,
( V_28 [ 8 ] & 0xf0 ) ) ;
return - V_26 ;
}
if ( V_8 ) {
memcpy ( & V_7 -> V_18 [ 0 ] , & V_28 [ 8 ] , V_14 ) ;
if ( ! memcmp ( & V_7 -> V_31 [ 0 ] , & V_7 -> V_18 [ 0 ] ,
V_14 ) ) {
V_7 -> V_32 = V_33 ;
V_7 -> V_23 = V_5 -> V_9 ;
F_6 ( L_16
L_17 , V_7 -> V_23 ) ;
}
} else {
memcpy ( & V_7 -> V_17 [ 0 ] , & V_28 [ 8 ] , V_14 ) ;
if ( ! memcmp ( & V_7 -> V_31 [ 0 ] , & V_7 -> V_17 [ 0 ] ,
V_14 ) ) {
V_7 -> V_32 = V_34 ;
V_7 -> V_22 = V_5 -> V_9 ;
F_6 ( L_18
L_17 , V_7 -> V_22 ) ;
}
}
return 0 ;
}
static int F_12 ( struct V_5 * V_5 ,
struct V_6 * V_7 , unsigned char * V_27 ,
unsigned short V_35 )
{
struct V_1 * V_36 = V_5 -> V_9 ;
unsigned char * V_28 = V_27 ;
int V_37 = V_35 % V_38 , V_16 , V_39 = 0 ;
unsigned short V_40 = 0 ;
bool V_8 = true ;
if ( V_37 != 0 ) {
F_8 ( L_19
L_20 , V_38 ) ;
return - V_26 ;
}
if ( V_35 > 64 ) {
F_8 ( L_21
L_22 , V_35 ) ;
return - V_26 ;
}
memset ( & V_7 -> V_31 [ 0 ] , 0 , V_14 ) ;
F_1 ( V_36 , & V_7 -> V_31 [ 0 ] ) ;
while ( V_40 < V_35 ) {
switch ( V_28 [ 0 ] ) {
case 0xe4 :
V_16 = F_10 ( V_5 , V_7 ,
& V_28 [ 0 ] , V_8 ) ;
if ( V_16 != 0 )
goto V_41;
if ( V_8 )
V_8 = false ;
else
V_8 = true ;
V_40 += V_38 ;
V_28 += V_38 ;
V_39 ++ ;
break;
default:
F_8 ( L_23
L_24 , V_28 [ 0 ] ) ;
goto V_41;
}
}
if ( V_7 -> V_32 == V_33 )
V_16 = F_3 ( V_5 , V_7 , true ) ;
else
V_16 = F_3 ( V_5 , V_7 , false ) ;
if ( V_16 < 0 )
goto V_41;
F_6 ( L_25 ,
V_7 -> V_23 , & V_7 -> V_18 [ 0 ] ) ;
F_6 ( L_26 ,
V_7 -> V_22 , & V_7 -> V_17 [ 0 ] ) ;
return V_39 ;
V_41:
return - V_26 ;
}
static int F_13 ( struct V_5 * V_5 , struct V_6 * V_7 ,
unsigned char * V_27 )
{
unsigned char * V_28 = V_27 ;
int V_42 = ( V_28 [ 1 ] & 0x02 ) ;
unsigned short V_43 ;
V_43 = F_11 ( & V_28 [ 2 ] ) ;
if ( V_43 != 0x18 ) {
F_8 ( L_27
L_28 , V_43 ) ;
return - V_26 ;
}
V_7 -> V_44 = F_11 ( & V_28 [ 4 ] ) ;
V_7 -> V_45 = F_11 ( & V_28 [ 6 ] ) ;
F_6 ( L_29 ,
V_43 , V_7 -> V_44 , V_7 -> V_45 , V_42 ) ;
V_7 -> V_46 = F_11 ( & V_28 [ 10 ] ) ;
V_7 -> V_47 = F_14 ( & V_28 [ 12 ] ) ;
V_7 -> V_48 = F_14 ( & V_28 [ 20 ] ) ;
F_6 ( L_30 ,
V_7 -> V_46 , ( unsigned long long ) V_7 -> V_47 ,
( unsigned long long ) V_7 -> V_48 ) ;
if ( V_42 != 0 ) {
V_7 -> V_49 = ( V_28 [ 29 ] & 0xff ) << 16 ;
V_7 -> V_49 |= ( V_28 [ 30 ] & 0xff ) << 8 ;
V_7 -> V_49 |= V_28 [ 31 ] & 0xff ;
F_6 ( L_31 , V_7 -> V_49 ) ;
}
return 0 ;
}
static int F_15 ( struct V_5 * V_5 ,
struct V_6 * V_7 , unsigned char * V_27 ,
unsigned int V_50 )
{
unsigned char * V_28 = V_27 ;
unsigned int V_40 = 0 ;
int V_37 = V_50 % V_51 , V_16 , V_39 = 0 ;
if ( V_37 != 0 ) {
F_8 ( L_32
L_20 , V_51 ) ;
return - V_26 ;
}
while ( V_40 < V_50 ) {
switch ( V_28 [ 0 ] ) {
case 0x02 :
V_16 = F_13 ( V_5 , V_7 , V_28 ) ;
if ( V_16 < 0 )
goto V_41;
V_39 ++ ;
V_40 += V_51 ;
V_28 += V_51 ;
break;
default:
F_8 ( L_33
L_34 , V_28 [ 0 ] ) ;
goto V_41;
}
}
return V_39 ;
V_41:
return - V_26 ;
}
static char * F_16 ( void )
{
return L_35 ;
}
static T_2 F_17 ( struct V_5 * V_5 )
{
return 0 ;
}
static int F_18 ( struct V_5 * V_5 )
{
return 0 ;
}
static void F_19 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = V_12 [ 0 ] ;
struct V_1 * V_52 ;
if ( V_7 -> V_32 == V_33 )
V_52 = V_7 -> V_22 ;
else
V_52 = V_7 -> V_23 ;
F_6 ( L_36
L_37 ,
V_11 , V_52 , & V_52 -> V_24 . V_25 ) ;
F_20 ( V_11 , & V_52 -> V_24 . V_25 ) ;
}
static void F_21 ( struct V_5 * V_5 )
{
struct V_53 * V_54 = F_22 ( V_5 ,
struct V_53 , V_5 ) ;
F_23 ( V_54 ) ;
}
static int F_24 ( struct V_5 * V_5 )
{
struct V_53 * V_54 = F_22 ( V_5 ,
struct V_53 , V_5 ) ;
F_25 ( & V_54 -> V_55 ) ;
return 0 ;
}
static int F_26 ( struct V_5 * V_5 )
{
return 0 ;
}
static int F_27 ( struct V_5 * V_5 )
{
return 0 ;
}
static int F_28 ( struct V_5 * V_5 )
{
return 0 ;
}
static int F_29 ( struct V_5 * V_5 )
{
return 0 ;
}
int F_30 ( void )
{
V_56 = F_31 ( L_38 , V_57 , 0 ) ;
if ( ! V_56 ) {
F_8 ( L_39 ) ;
return - V_58 ;
}
memset ( & V_59 , 0 , sizeof( struct V_60 ) ) ;
F_32 ( & V_59 . V_61 ) ;
F_32 ( & V_59 . V_62 ) ;
F_33 ( & V_59 . V_63 ) ;
memset ( & V_64 , 0 , sizeof( struct V_65 ) ) ;
F_32 ( & V_64 . V_66 ) ;
F_32 ( & V_64 . V_67 ) ;
F_32 ( & V_64 . V_68 ) ;
V_59 . V_69 = & V_64 ;
V_64 . V_70 = & V_71 ;
memset ( & V_72 , 0 , sizeof( struct V_73 ) ) ;
F_32 ( & V_72 . V_74 ) ;
F_32 ( & V_72 . V_75 ) ;
memset ( & V_76 , 0 , sizeof( struct V_77 ) ) ;
F_32 ( & V_76 . V_78 ) ;
F_32 ( & V_76 . V_79 ) ;
V_72 . V_80 = & V_64 ;
V_72 . V_81 = & V_76 ;
V_76 . V_80 = & V_64 ;
V_76 . V_73 = & V_72 ;
return 0 ;
}
void F_34 ( void )
{
if ( V_56 )
F_35 ( V_56 ) ;
}
static void F_36 (
struct V_53 * V_54 ,
struct V_6 * V_7 ,
bool V_82 )
{
struct V_5 * V_83 = V_7 -> V_84 ;
struct V_5 * V_85 = & V_54 -> V_5 ;
if ( V_7 -> V_32 == V_33 ) {
if ( V_82 ) {
V_54 -> V_82 = V_82 ;
V_85 -> V_86 -> V_87 = & V_59 ;
F_6 ( L_40
L_41 ,
V_85 -> V_86 -> V_87 ) ;
} else {
V_85 -> V_86 = V_83 -> V_86 ;
V_85 -> V_9 = V_83 -> V_9 ;
F_6 ( L_42
L_43 , V_85 -> V_9 ) ;
V_85 -> V_86 = V_83 -> V_86 ;
F_6 ( L_44 ,
V_85 -> V_86 ) ;
}
} else {
if ( V_82 ) {
V_54 -> V_82 = V_82 ;
V_85 -> V_86 -> V_87 = & V_59 ;
F_6 ( L_45
L_46 ,
V_85 -> V_86 -> V_87 ) ;
} else {
V_85 -> V_86 = V_83 -> V_86 ;
V_85 -> V_9 = V_83 -> V_9 ;
F_6 ( L_47
L_43 , V_85 -> V_9 ) ;
V_85 -> V_86 = V_83 -> V_86 ;
F_6 ( L_48 ,
V_85 -> V_86 ) ;
}
}
}
static int F_37 (
struct V_53 * V_54 ,
struct V_6 * V_7 ,
struct V_1 * V_9 ,
struct V_5 * V_85 ,
bool V_82 )
{
if ( ! V_82 ) {
V_85 -> V_88 |= V_89 | V_90 ;
return 0 ;
}
V_85 -> V_86 = & V_9 -> V_91 ;
V_85 -> V_9 = V_9 ;
F_6 ( L_49 , V_85 -> V_9 ) ;
V_85 -> V_88 |= V_89 | V_90 ;
F_6 ( L_50 ,
V_85 -> V_86 -> V_92 ) ;
return 0 ;
}
static int F_38 (
struct V_53 * V_54 ,
struct V_6 * V_7 ,
struct V_1 * V_9 ,
unsigned char * V_93 ,
bool V_82 ,
bool V_94 )
{
struct V_5 * V_95 = & V_54 -> V_5 ;
T_3 V_96 ;
int V_39 = 0 , V_16 ;
V_16 = F_37 ( V_54 , V_7 , V_9 , V_95 , V_82 ) ;
if ( V_16 < 0 ) {
V_39 = V_16 ;
goto V_41;
}
V_54 -> V_6 = V_7 ;
F_36 ( V_54 , V_7 , V_82 ) ;
V_96 = F_39 ( V_95 , V_93 ) ;
if ( V_96 ) {
V_39 = - V_26 ;
goto V_41;
}
if ( V_94 ) {
V_16 = F_40 ( & V_95 -> V_97 , & V_95 -> V_98 ,
V_95 -> V_99 , false ) ;
if ( V_16 < 0 ) {
V_39 = V_16 ;
goto V_41;
}
V_95 -> V_88 |= V_100 ;
} else {
V_96 = F_41 ( V_95 ,
V_7 -> V_101 , V_7 -> V_102 ,
NULL , 0 ) ;
if ( V_96 ) {
V_39 = - V_26 ;
goto V_41;
}
F_6 ( L_51
L_52 , V_95 -> V_97 , V_95 -> V_98 ) ;
}
return 0 ;
V_41:
return V_39 ;
}
static int F_42 ( struct V_53 * V_54 )
{
struct V_5 * V_5 = & V_54 -> V_5 ;
T_3 V_96 ;
V_96 = F_43 ( V_5 ) ;
if ( V_96 )
return - V_26 ;
if ( V_5 -> V_103 == V_104 )
F_44 ( V_5 ) ;
F_45 ( & V_54 -> V_55 ) ;
F_6 ( L_53 ,
V_5 -> V_105 ) ;
return ( V_5 -> V_105 ) ? - V_26 : 0 ;
}
static int F_46 (
struct V_5 * V_83 ,
struct V_6 * V_7 ,
struct V_1 * V_23 ,
T_4 V_47 ,
T_2 V_106 )
{
struct V_53 * V_54 ;
struct V_5 * V_5 ;
T_2 V_107 = ( V_106 * V_23 -> V_20 . V_108 ) ;
int V_16 ;
unsigned char V_93 [ 16 ] ;
bool V_82 = ( V_7 -> V_32 == V_34 ) ;
V_54 = F_47 ( sizeof( struct V_53 ) , V_109 ) ;
if ( ! V_54 ) {
F_8 ( L_54 ) ;
return - V_58 ;
}
F_48 ( & V_54 -> V_55 ) ;
V_5 = & V_54 -> V_5 ;
memset ( & V_93 [ 0 ] , 0 , 16 ) ;
V_93 [ 0 ] = V_110 ;
F_49 ( V_47 , & V_93 [ 2 ] ) ;
F_50 ( V_106 , & V_93 [ 10 ] ) ;
F_6 ( L_55 ,
( unsigned long long ) V_47 , V_106 , V_107 ) ;
F_51 ( V_5 , & V_71 , NULL , V_107 ,
V_111 , 0 , & V_54 -> V_112 [ 0 ] ) ;
V_7 -> V_113 = V_54 ;
V_16 = F_38 ( V_54 , V_7 , V_23 , & V_93 [ 0 ] ,
V_82 , true ) ;
if ( V_16 < 0 ) {
F_52 ( V_5 , 0 ) ;
return V_16 ;
}
V_7 -> V_101 = V_5 -> V_97 ;
V_7 -> V_102 = V_5 -> V_98 ;
F_6 ( L_56
L_57 , V_7 -> V_101 , V_7 -> V_102 ) ;
V_16 = F_42 ( V_54 ) ;
if ( V_16 < 0 ) {
F_52 ( V_5 , 0 ) ;
return V_16 ;
}
V_5 -> V_97 = NULL ;
V_5 -> V_98 = 0 ;
return 0 ;
}
static int F_53 (
struct V_5 * V_83 ,
struct V_6 * V_7 ,
struct V_1 * V_22 ,
T_4 V_48 ,
T_2 V_114 )
{
struct V_53 * V_54 ;
struct V_5 * V_5 ;
T_2 V_107 = ( V_114 * V_22 -> V_20 . V_108 ) ;
int V_16 ;
unsigned char V_93 [ 16 ] ;
bool V_82 = ( V_7 -> V_32 == V_33 ) ;
V_54 = F_47 ( sizeof( struct V_53 ) , V_109 ) ;
if ( ! V_54 ) {
F_8 ( L_54 ) ;
return - V_58 ;
}
F_48 ( & V_54 -> V_55 ) ;
V_5 = & V_54 -> V_5 ;
memset ( & V_93 [ 0 ] , 0 , 16 ) ;
V_93 [ 0 ] = V_115 ;
F_49 ( V_48 , & V_93 [ 2 ] ) ;
F_50 ( V_114 , & V_93 [ 10 ] ) ;
F_6 ( L_58 ,
( unsigned long long ) V_48 , V_114 , V_107 ) ;
F_51 ( V_5 , & V_71 , NULL , V_107 ,
V_104 , 0 , & V_54 -> V_112 [ 0 ] ) ;
V_7 -> V_116 = V_54 ;
V_16 = F_38 ( V_54 , V_7 , V_22 , & V_93 [ 0 ] ,
V_82 , false ) ;
if ( V_16 < 0 ) {
struct V_5 * V_117 = & V_7 -> V_113 -> V_5 ;
V_117 -> V_88 &= ~ V_100 ;
V_117 -> V_97 = V_7 -> V_101 ;
V_117 -> V_98 = V_7 -> V_102 ;
F_52 ( V_5 , 0 ) ;
return V_16 ;
}
V_16 = F_42 ( V_54 ) ;
if ( V_16 < 0 ) {
V_5 -> V_88 &= ~ V_100 ;
F_52 ( V_5 , 0 ) ;
return V_16 ;
}
return 0 ;
}
static void F_54 ( struct V_118 * V_119 )
{
struct V_6 * V_7 = F_22 ( V_119 , struct V_6 , V_120 ) ;
struct V_1 * V_23 = V_7 -> V_23 , * V_22 = V_7 -> V_22 ;
struct V_5 * V_83 = V_7 -> V_84 ;
T_4 V_47 = V_7 -> V_47 , V_48 = V_7 -> V_48 , V_121 ;
unsigned int V_122 ;
int V_16 ;
unsigned short V_46 = V_7 -> V_46 , V_123 , V_124 , V_125 = 0 ;
V_121 = V_47 + V_46 ;
V_122 = F_55 ( V_23 -> V_20 . V_126 ,
V_22 -> V_20 . V_126 ) ;
V_122 = F_56 ( T_2 , V_122 , V_127 ) ;
V_124 = F_56 ( V_128 , V_122 , ( ( V_128 ) ( ~ 0U ) ) ) ;
F_6 ( L_59 ,
V_46 , V_124 , ( unsigned long long ) V_121 ) ;
F_6 ( L_60 ,
( unsigned long long ) V_47 , ( unsigned long long ) V_48 ) ;
while ( V_47 < V_121 ) {
V_123 = F_55 ( V_46 , V_124 ) ;
F_6 ( L_61
L_62 , V_23 , ( unsigned long long ) V_47 , V_123 ) ;
V_16 = F_46 ( V_83 , V_7 , V_23 , V_47 , V_123 ) ;
if ( V_16 < 0 )
goto V_41;
V_47 += V_123 ;
F_6 ( L_63 ,
( unsigned long long ) V_47 ) ;
F_6 ( L_64
L_62 , V_22 , ( unsigned long long ) V_48 , V_123 ) ;
V_16 = F_53 ( V_83 , V_7 , V_22 ,
V_48 , V_123 ) ;
if ( V_16 < 0 ) {
F_52 ( & V_7 -> V_113 -> V_5 , 0 ) ;
goto V_41;
}
V_48 += V_123 ;
F_6 ( L_65 ,
( unsigned long long ) V_48 ) ;
V_125 += V_123 ;
V_46 -= V_123 ;
F_52 ( & V_7 -> V_113 -> V_5 , 0 ) ;
V_7 -> V_116 -> V_5 . V_88 &= ~ V_100 ;
F_52 ( & V_7 -> V_116 -> V_5 , 0 ) ;
}
F_19 ( V_7 ) ;
F_23 ( V_7 ) ;
F_6 ( L_66 ,
( unsigned long long ) V_47 , ( unsigned long long ) V_48 ) ;
F_6 ( L_67 ,
V_125 , V_125 * V_22 -> V_20 . V_108 ) ;
F_6 ( L_68 ) ;
F_57 ( V_83 , V_129 ) ;
return;
V_41:
F_19 ( V_7 ) ;
F_23 ( V_7 ) ;
F_58 ( L_69 ) ;
V_83 -> V_105 = V_130 ;
F_57 ( V_83 , V_130 ) ;
}
T_3 F_59 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_9 ;
struct V_6 * V_7 = NULL ;
unsigned char * V_27 = NULL , * V_131 ;
unsigned int V_132 , V_133 , V_50 , V_134 , V_135 ;
T_3 V_39 = V_136 ;
int V_16 ;
unsigned short V_35 ;
if ( ! V_2 -> V_20 . V_21 ) {
F_8 ( L_70 ) ;
return V_137 ;
}
V_135 = V_5 -> V_138 [ 1 ] & 0x1f ;
if ( V_135 != 0x00 ) {
F_8 ( L_71 ) ;
return V_137 ;
}
V_7 = F_47 ( sizeof( struct V_6 ) , V_109 ) ;
if ( ! V_7 ) {
F_8 ( L_72 ) ;
return V_139 ;
}
V_7 -> V_84 = V_5 ;
V_27 = F_60 ( V_5 ) ;
if ( ! V_27 ) {
F_8 ( L_73 ) ;
F_23 ( V_7 ) ;
return V_139 ;
}
V_132 = V_27 [ 0 ] ;
V_133 = ( V_27 [ 1 ] & 0x18 ) >> 3 ;
V_35 = F_11 ( & V_27 [ 2 ] ) ;
V_50 = F_61 ( & V_27 [ 8 ] ) ;
V_134 = F_61 ( & V_27 [ 12 ] ) ;
if ( V_134 != 0 ) {
F_8 ( L_74 ) ;
goto V_41;
}
F_6 ( L_75
L_76 , V_132 , V_133 ,
V_35 , V_50 , V_134 ) ;
V_16 = F_12 ( V_5 , V_7 , & V_27 [ 16 ] , V_35 ) ;
if ( V_16 <= 0 )
goto V_41;
if ( V_7 -> V_23 -> V_20 . V_108 !=
V_7 -> V_22 -> V_20 . V_108 ) {
F_8 ( L_77
L_78 ,
V_7 -> V_23 -> V_20 . V_108 ,
V_7 -> V_22 -> V_20 . V_108 ) ;
F_19 ( V_7 ) ;
V_39 = V_140 ;
goto V_41;
}
F_6 ( L_79 , V_16 ,
V_16 * V_38 ) ;
V_131 = & V_27 [ 16 ] ;
V_131 += ( V_16 * V_38 ) ;
V_16 = F_15 ( V_5 , V_7 , V_131 , V_50 ) ;
if ( V_16 <= 0 ) {
F_19 ( V_7 ) ;
goto V_41;
}
F_62 ( V_5 ) ;
F_6 ( L_80 , V_16 ,
V_16 * V_51 ) ;
F_63 ( & V_7 -> V_120 , F_54 ) ;
F_64 ( V_56 , & V_7 -> V_120 ) ;
return V_141 ;
V_41:
if ( V_27 )
F_62 ( V_5 ) ;
F_23 ( V_7 ) ;
return V_39 ;
}
static T_3 F_65 ( struct V_5 * V_5 )
{
unsigned char * V_27 ;
V_27 = F_60 ( V_5 ) ;
if ( ! V_27 ) {
F_8 ( L_81
L_82 ) ;
return V_139 ;
}
if ( V_5 -> V_99 < 54 ) {
F_8 ( L_83
L_84 , V_5 -> V_99 ) ;
F_62 ( V_5 ) ;
return V_142 ;
}
V_27 [ 4 ] = 0x1 ;
F_66 ( V_143 , & V_27 [ 8 ] ) ;
F_66 ( V_144 , & V_27 [ 10 ] ) ;
F_50 ( V_145 , & V_27 [ 12 ] ) ;
F_50 ( V_146 , & V_27 [ 16 ] ) ;
F_50 ( 0x0 , & V_27 [ 20 ] ) ;
F_50 ( 0x0 , & V_27 [ 24 ] ) ;
F_50 ( 0x0 , & V_27 [ 28 ] ) ;
F_66 ( V_147 , & V_27 [ 34 ] ) ;
V_27 [ 36 ] = V_148 ;
V_27 [ 37 ] = V_149 ;
V_27 [ 38 ] = V_150 ;
V_27 [ 39 ] = V_151 ;
V_27 [ 43 ] = 0x2 ;
V_27 [ 44 ] = 0x02 ;
V_27 [ 45 ] = 0xe4 ;
F_50 ( 42 , & V_27 [ 0 ] ) ;
F_62 ( V_5 ) ;
F_57 ( V_5 , V_152 ) ;
return V_141 ;
}
T_3 F_67 ( struct V_5 * V_5 )
{
unsigned char * V_93 = & V_5 -> V_138 [ 0 ] ;
int V_135 = ( V_93 [ 1 ] & 0x1f ) , V_132 = V_93 [ 2 ] ;
T_3 V_16 = V_141 ;
F_6 ( L_85
L_86 , V_135 , V_132 , V_5 -> V_99 ) ;
if ( V_132 != 0 ) {
F_8 ( L_87
L_88 ) ;
return V_142 ;
}
switch ( V_135 ) {
case V_153 :
V_16 = F_65 ( V_5 ) ;
break;
case V_154 :
case V_155 :
case V_156 :
default:
F_8 ( L_89 , V_135 ) ;
return V_142 ;
}
return V_16 ;
}
