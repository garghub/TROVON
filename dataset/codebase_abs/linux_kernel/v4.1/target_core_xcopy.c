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
unsigned char V_10 [ V_11 ] , * V_12 ;
int V_13 ;
if ( V_8 )
V_12 = & V_7 -> V_14 [ 0 ] ;
else
V_12 = & V_7 -> V_15 [ 0 ] ;
F_4 ( & V_16 ) ;
F_5 (se_dev, &g_device_list, g_dev_node) {
if ( ! V_9 -> V_17 . V_18 )
continue;
memset ( & V_10 [ 0 ] , 0 , V_11 ) ;
F_1 ( V_9 , & V_10 [ 0 ] ) ;
V_13 = memcmp ( & V_10 [ 0 ] , V_12 , V_11 ) ;
if ( V_13 != 0 )
continue;
if ( V_8 ) {
V_7 -> V_19 = V_9 ;
F_6 ( L_1
L_2 , V_7 -> V_19 ) ;
} else {
V_7 -> V_20 = V_9 ;
F_6 ( L_3
L_2 , V_7 -> V_20 ) ;
}
V_13 = F_7 ( & V_9 -> V_21 . V_22 ) ;
if ( V_13 != 0 ) {
F_8 ( L_4
L_5 , V_13 , V_9 ) ;
F_9 ( & V_16 ) ;
return V_13 ;
}
F_6 ( L_6
L_7 , V_9 ,
& V_9 -> V_21 ) ;
F_9 ( & V_16 ) ;
return 0 ;
}
F_9 ( & V_16 ) ;
F_8 ( L_8 ) ;
return - V_23 ;
}
static int F_10 ( struct V_5 * V_5 , struct V_6 * V_7 ,
unsigned char * V_24 , bool V_8 )
{
unsigned char * V_25 = V_24 ;
unsigned short V_26 ;
T_1 V_27 ;
V_26 = F_11 ( & V_25 [ 2 ] ) ;
F_6 ( L_9 , V_26 ) ;
if ( ( V_25 [ 4 ] & 0x0f ) != 0x1 ) {
F_8 ( L_10 ) ;
return - V_23 ;
}
if ( ( V_25 [ 5 ] & 0x30 ) != 0x00 ) {
F_8 ( L_11 ) ;
return - V_23 ;
}
if ( ( V_25 [ 5 ] & 0x0f ) != 0x3 ) {
F_8 ( L_12 ,
( V_25 [ 5 ] & 0x0f ) ) ;
return - V_23 ;
}
V_27 = V_25 [ 7 ] ;
if ( V_27 != 16 ) {
F_8 ( L_13 , ( int ) V_27 ) ;
return - V_23 ;
}
F_6 ( L_14 , ( int ) V_27 ) ;
if ( ( V_25 [ 8 ] & 0xf0 ) != 0x60 ) {
F_8 ( L_15 ,
( V_25 [ 8 ] & 0xf0 ) ) ;
return - V_23 ;
}
if ( V_8 ) {
memcpy ( & V_7 -> V_15 [ 0 ] , & V_25 [ 8 ] , V_11 ) ;
if ( ! memcmp ( & V_7 -> V_28 [ 0 ] , & V_7 -> V_15 [ 0 ] ,
V_11 ) ) {
V_7 -> V_29 = V_30 ;
V_7 -> V_20 = V_5 -> V_9 ;
F_6 ( L_16
L_17 , V_7 -> V_20 ) ;
}
} else {
memcpy ( & V_7 -> V_14 [ 0 ] , & V_25 [ 8 ] , V_11 ) ;
if ( ! memcmp ( & V_7 -> V_28 [ 0 ] , & V_7 -> V_14 [ 0 ] ,
V_11 ) ) {
V_7 -> V_29 = V_31 ;
V_7 -> V_19 = V_5 -> V_9 ;
F_6 ( L_18
L_17 , V_7 -> V_19 ) ;
}
}
return 0 ;
}
static int F_12 ( struct V_5 * V_5 ,
struct V_6 * V_7 , unsigned char * V_24 ,
unsigned short V_32 )
{
struct V_1 * V_33 = V_5 -> V_9 ;
unsigned char * V_25 = V_24 ;
int V_34 = V_32 % V_35 , V_13 , V_36 = 0 ;
unsigned short V_37 = 0 ;
bool V_8 = true ;
if ( V_34 != 0 ) {
F_8 ( L_19
L_20 , V_35 ) ;
return - V_23 ;
}
if ( V_32 > 64 ) {
F_8 ( L_21
L_22 , V_32 ) ;
return - V_23 ;
}
memset ( & V_7 -> V_28 [ 0 ] , 0 , V_11 ) ;
F_1 ( V_33 , & V_7 -> V_28 [ 0 ] ) ;
while ( V_37 < V_32 ) {
switch ( V_25 [ 0 ] ) {
case 0xe4 :
V_13 = F_10 ( V_5 , V_7 ,
& V_25 [ 0 ] , V_8 ) ;
if ( V_13 != 0 )
goto V_38;
if ( V_8 )
V_8 = false ;
else
V_8 = true ;
V_37 += V_35 ;
V_25 += V_35 ;
V_36 ++ ;
break;
default:
F_8 ( L_23
L_24 , V_25 [ 0 ] ) ;
goto V_38;
}
}
if ( V_7 -> V_29 == V_30 )
V_13 = F_3 ( V_5 , V_7 , true ) ;
else
V_13 = F_3 ( V_5 , V_7 , false ) ;
if ( V_13 < 0 )
goto V_38;
F_6 ( L_25 ,
V_7 -> V_20 , & V_7 -> V_15 [ 0 ] ) ;
F_6 ( L_26 ,
V_7 -> V_19 , & V_7 -> V_14 [ 0 ] ) ;
return V_36 ;
V_38:
return - V_23 ;
}
static int F_13 ( struct V_5 * V_5 , struct V_6 * V_7 ,
unsigned char * V_24 )
{
unsigned char * V_25 = V_24 ;
int V_39 = ( V_25 [ 1 ] & 0x02 ) ;
unsigned short V_40 ;
V_40 = F_11 ( & V_25 [ 2 ] ) ;
if ( V_40 != 0x18 ) {
F_8 ( L_27
L_28 , V_40 ) ;
return - V_23 ;
}
V_7 -> V_41 = F_11 ( & V_25 [ 4 ] ) ;
V_7 -> V_42 = F_11 ( & V_25 [ 6 ] ) ;
F_6 ( L_29 ,
V_40 , V_7 -> V_41 , V_7 -> V_42 , V_39 ) ;
V_7 -> V_43 = F_11 ( & V_25 [ 10 ] ) ;
V_7 -> V_44 = F_14 ( & V_25 [ 12 ] ) ;
V_7 -> V_45 = F_14 ( & V_25 [ 20 ] ) ;
F_6 ( L_30 ,
V_7 -> V_43 , ( unsigned long long ) V_7 -> V_44 ,
( unsigned long long ) V_7 -> V_45 ) ;
if ( V_39 != 0 ) {
V_7 -> V_46 = ( V_25 [ 29 ] & 0xff ) << 16 ;
V_7 -> V_46 |= ( V_25 [ 30 ] & 0xff ) << 8 ;
V_7 -> V_46 |= V_25 [ 31 ] & 0xff ;
F_6 ( L_31 , V_7 -> V_46 ) ;
}
return 0 ;
}
static int F_15 ( struct V_5 * V_5 ,
struct V_6 * V_7 , unsigned char * V_24 ,
unsigned int V_47 )
{
unsigned char * V_25 = V_24 ;
unsigned int V_37 = 0 ;
int V_34 = V_47 % V_48 , V_13 , V_36 = 0 ;
if ( V_34 != 0 ) {
F_8 ( L_32
L_20 , V_48 ) ;
return - V_23 ;
}
while ( V_37 < V_47 ) {
switch ( V_25 [ 0 ] ) {
case 0x02 :
V_13 = F_13 ( V_5 , V_7 , V_25 ) ;
if ( V_13 < 0 )
goto V_38;
V_36 ++ ;
V_37 += V_48 ;
V_25 += V_48 ;
break;
default:
F_8 ( L_33
L_34 , V_25 [ 0 ] ) ;
goto V_38;
}
}
return V_36 ;
V_38:
return - V_23 ;
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
struct V_1 * V_49 ;
if ( V_7 -> V_29 == V_30 )
V_49 = V_7 -> V_19 ;
else
V_49 = V_7 -> V_20 ;
F_6 ( L_36
L_37 ,
V_49 , & V_49 -> V_21 . V_22 ) ;
F_20 ( & V_49 -> V_21 . V_22 ) ;
}
static void F_21 ( struct V_5 * V_5 )
{
struct V_50 * V_51 = F_22 ( V_5 ,
struct V_50 , V_5 ) ;
F_23 ( V_51 ) ;
}
static int F_24 ( struct V_5 * V_5 )
{
struct V_50 * V_51 = F_22 ( V_5 ,
struct V_50 , V_5 ) ;
F_25 ( & V_51 -> V_52 ) ;
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
V_53 = F_31 ( L_38 , V_54 , 0 ) ;
if ( ! V_53 ) {
F_8 ( L_39 ) ;
return - V_55 ;
}
memset ( & V_56 , 0 , sizeof( struct V_57 ) ) ;
F_32 ( & V_56 . V_58 ) ;
F_32 ( & V_56 . V_59 ) ;
F_33 ( & V_56 . V_60 ) ;
memset ( & V_61 , 0 , sizeof( struct V_62 ) ) ;
F_32 ( & V_61 . V_63 ) ;
F_32 ( & V_61 . V_64 ) ;
F_32 ( & V_61 . V_65 ) ;
V_56 . V_66 = & V_61 ;
V_61 . V_67 = & V_68 ;
memset ( & V_69 , 0 , sizeof( struct V_70 ) ) ;
F_32 ( & V_69 . V_71 ) ;
F_32 ( & V_69 . V_72 ) ;
memset ( & V_73 , 0 , sizeof( struct V_74 ) ) ;
F_32 ( & V_73 . V_75 ) ;
F_32 ( & V_73 . V_76 ) ;
V_69 . V_77 = & V_61 ;
V_69 . V_78 = & V_73 ;
V_73 . V_77 = & V_61 ;
V_73 . V_70 = & V_69 ;
return 0 ;
}
void F_34 ( void )
{
if ( V_53 )
F_35 ( V_53 ) ;
}
static void F_36 (
struct V_50 * V_51 ,
struct V_6 * V_7 ,
bool V_79 )
{
struct V_5 * V_80 = V_7 -> V_81 ;
struct V_5 * V_82 = & V_51 -> V_5 ;
if ( V_7 -> V_29 == V_30 ) {
if ( V_79 ) {
V_51 -> V_79 = V_79 ;
V_82 -> V_83 -> V_84 = & V_56 ;
F_6 ( L_40
L_41 ,
V_82 -> V_83 -> V_84 ) ;
} else {
V_82 -> V_83 = V_80 -> V_83 ;
V_82 -> V_9 = V_80 -> V_9 ;
F_6 ( L_42
L_43 , V_82 -> V_9 ) ;
V_82 -> V_83 = V_80 -> V_83 ;
F_6 ( L_44 ,
V_82 -> V_83 ) ;
}
} else {
if ( V_79 ) {
V_51 -> V_79 = V_79 ;
V_82 -> V_83 -> V_84 = & V_56 ;
F_6 ( L_45
L_46 ,
V_82 -> V_83 -> V_84 ) ;
} else {
V_82 -> V_83 = V_80 -> V_83 ;
V_82 -> V_9 = V_80 -> V_9 ;
F_6 ( L_47
L_43 , V_82 -> V_9 ) ;
V_82 -> V_83 = V_80 -> V_83 ;
F_6 ( L_48 ,
V_82 -> V_83 ) ;
}
}
}
static void F_37 ( struct V_1 * V_9 ,
struct V_5 * V_82 , bool V_79 )
{
if ( V_79 ) {
F_6 ( L_49 ,
V_82 -> V_9 ) ;
V_82 -> V_83 = & V_9 -> V_85 ;
V_82 -> V_9 = V_9 ;
}
V_82 -> V_86 |= V_87 ;
}
static int F_38 (
struct V_50 * V_51 ,
struct V_6 * V_7 ,
struct V_1 * V_9 ,
unsigned char * V_88 ,
bool V_79 ,
bool V_89 )
{
struct V_5 * V_90 = & V_51 -> V_5 ;
T_3 V_91 ;
int V_36 = 0 , V_13 ;
F_37 ( V_9 , V_90 , V_79 ) ;
V_51 -> V_6 = V_7 ;
F_36 ( V_51 , V_7 , V_79 ) ;
V_91 = F_39 ( V_90 , V_88 ) ;
if ( V_91 ) {
V_36 = - V_23 ;
goto V_38;
}
if ( V_89 ) {
V_13 = F_40 ( & V_90 -> V_92 , & V_90 -> V_93 ,
V_90 -> V_94 , false ) ;
if ( V_13 < 0 ) {
V_36 = V_13 ;
goto V_38;
}
V_90 -> V_86 |= V_95 ;
} else {
V_91 = F_41 ( V_90 ,
V_7 -> V_96 , V_7 -> V_97 ,
NULL , 0 ) ;
if ( V_91 ) {
V_36 = - V_23 ;
goto V_38;
}
F_6 ( L_50
L_51 , V_90 -> V_92 , V_90 -> V_93 ) ;
}
return 0 ;
V_38:
return V_36 ;
}
static int F_42 ( struct V_50 * V_51 )
{
struct V_5 * V_5 = & V_51 -> V_5 ;
T_3 V_91 ;
V_91 = F_43 ( V_5 ) ;
if ( V_91 )
return - V_23 ;
if ( V_5 -> V_98 == V_99 )
F_44 ( V_5 ) ;
F_45 ( & V_51 -> V_52 ) ;
F_6 ( L_52 ,
V_5 -> V_100 ) ;
return ( V_5 -> V_100 ) ? - V_23 : 0 ;
}
static int F_46 (
struct V_5 * V_80 ,
struct V_6 * V_7 ,
struct V_1 * V_20 ,
T_4 V_44 ,
T_2 V_101 )
{
struct V_50 * V_51 ;
struct V_5 * V_5 ;
T_2 V_102 = ( V_101 * V_20 -> V_17 . V_103 ) ;
int V_13 ;
unsigned char V_88 [ 16 ] ;
bool V_79 = ( V_7 -> V_29 == V_31 ) ;
V_51 = F_47 ( sizeof( struct V_50 ) , V_104 ) ;
if ( ! V_51 ) {
F_8 ( L_53 ) ;
return - V_55 ;
}
F_48 ( & V_51 -> V_52 ) ;
V_5 = & V_51 -> V_5 ;
memset ( & V_88 [ 0 ] , 0 , 16 ) ;
V_88 [ 0 ] = V_105 ;
F_49 ( V_44 , & V_88 [ 2 ] ) ;
F_50 ( V_101 , & V_88 [ 10 ] ) ;
F_6 ( L_54 ,
( unsigned long long ) V_44 , V_101 , V_102 ) ;
F_51 ( V_5 , & V_68 , NULL , V_102 ,
V_106 , 0 , & V_51 -> V_107 [ 0 ] ) ;
V_7 -> V_108 = V_51 ;
V_13 = F_38 ( V_51 , V_7 , V_20 , & V_88 [ 0 ] ,
V_79 , true ) ;
if ( V_13 < 0 ) {
F_52 ( V_5 , 0 ) ;
return V_13 ;
}
V_7 -> V_96 = V_5 -> V_92 ;
V_7 -> V_97 = V_5 -> V_93 ;
F_6 ( L_55
L_56 , V_7 -> V_96 , V_7 -> V_97 ) ;
V_13 = F_42 ( V_51 ) ;
if ( V_13 < 0 ) {
F_52 ( V_5 , 0 ) ;
return V_13 ;
}
V_5 -> V_92 = NULL ;
V_5 -> V_93 = 0 ;
return 0 ;
}
static int F_53 (
struct V_5 * V_80 ,
struct V_6 * V_7 ,
struct V_1 * V_19 ,
T_4 V_45 ,
T_2 V_109 )
{
struct V_50 * V_51 ;
struct V_5 * V_5 ;
T_2 V_102 = ( V_109 * V_19 -> V_17 . V_103 ) ;
int V_13 ;
unsigned char V_88 [ 16 ] ;
bool V_79 = ( V_7 -> V_29 == V_30 ) ;
V_51 = F_47 ( sizeof( struct V_50 ) , V_104 ) ;
if ( ! V_51 ) {
F_8 ( L_53 ) ;
return - V_55 ;
}
F_48 ( & V_51 -> V_52 ) ;
V_5 = & V_51 -> V_5 ;
memset ( & V_88 [ 0 ] , 0 , 16 ) ;
V_88 [ 0 ] = V_110 ;
F_49 ( V_45 , & V_88 [ 2 ] ) ;
F_50 ( V_109 , & V_88 [ 10 ] ) ;
F_6 ( L_57 ,
( unsigned long long ) V_45 , V_109 , V_102 ) ;
F_51 ( V_5 , & V_68 , NULL , V_102 ,
V_99 , 0 , & V_51 -> V_107 [ 0 ] ) ;
V_7 -> V_111 = V_51 ;
V_13 = F_38 ( V_51 , V_7 , V_19 , & V_88 [ 0 ] ,
V_79 , false ) ;
if ( V_13 < 0 ) {
struct V_5 * V_112 = & V_7 -> V_108 -> V_5 ;
V_112 -> V_86 &= ~ V_95 ;
V_112 -> V_92 = V_7 -> V_96 ;
V_112 -> V_93 = V_7 -> V_97 ;
F_52 ( V_5 , 0 ) ;
return V_13 ;
}
V_13 = F_42 ( V_51 ) ;
if ( V_13 < 0 ) {
V_5 -> V_86 &= ~ V_95 ;
F_52 ( V_5 , 0 ) ;
return V_13 ;
}
return 0 ;
}
static void F_54 ( struct V_113 * V_114 )
{
struct V_6 * V_7 = F_22 ( V_114 , struct V_6 , V_115 ) ;
struct V_1 * V_20 = V_7 -> V_20 , * V_19 = V_7 -> V_19 ;
struct V_5 * V_80 = V_7 -> V_81 ;
T_4 V_44 = V_7 -> V_44 , V_45 = V_7 -> V_45 , V_116 ;
unsigned int V_117 ;
int V_13 ;
unsigned short V_43 = V_7 -> V_43 , V_118 , V_119 , V_120 = 0 ;
V_116 = V_44 + V_43 ;
V_117 = F_55 ( V_20 -> V_17 . V_121 ,
V_19 -> V_17 . V_121 ) ;
V_117 = F_56 ( T_2 , V_117 , V_122 ) ;
V_119 = F_56 ( V_123 , V_117 , ( ( V_123 ) ( ~ 0U ) ) ) ;
F_6 ( L_58 ,
V_43 , V_119 , ( unsigned long long ) V_116 ) ;
F_6 ( L_59 ,
( unsigned long long ) V_44 , ( unsigned long long ) V_45 ) ;
while ( V_44 < V_116 ) {
V_118 = F_55 ( V_43 , V_119 ) ;
F_6 ( L_60
L_61 , V_20 , ( unsigned long long ) V_44 , V_118 ) ;
V_13 = F_46 ( V_80 , V_7 , V_20 , V_44 , V_118 ) ;
if ( V_13 < 0 )
goto V_38;
V_44 += V_118 ;
F_6 ( L_62 ,
( unsigned long long ) V_44 ) ;
F_6 ( L_63
L_61 , V_19 , ( unsigned long long ) V_45 , V_118 ) ;
V_13 = F_53 ( V_80 , V_7 , V_19 ,
V_45 , V_118 ) ;
if ( V_13 < 0 ) {
F_52 ( & V_7 -> V_108 -> V_5 , 0 ) ;
goto V_38;
}
V_45 += V_118 ;
F_6 ( L_64 ,
( unsigned long long ) V_45 ) ;
V_120 += V_118 ;
V_43 -= V_118 ;
F_52 ( & V_7 -> V_108 -> V_5 , 0 ) ;
V_7 -> V_111 -> V_5 . V_86 &= ~ V_95 ;
F_52 ( & V_7 -> V_111 -> V_5 , 0 ) ;
}
F_19 ( V_7 ) ;
F_23 ( V_7 ) ;
F_6 ( L_65 ,
( unsigned long long ) V_44 , ( unsigned long long ) V_45 ) ;
F_6 ( L_66 ,
V_120 , V_120 * V_19 -> V_17 . V_103 ) ;
F_6 ( L_67 ) ;
F_57 ( V_80 , V_124 ) ;
return;
V_38:
F_19 ( V_7 ) ;
F_23 ( V_7 ) ;
F_58 ( L_68 ) ;
V_80 -> V_100 = V_125 ;
F_57 ( V_80 , V_125 ) ;
}
T_3 F_59 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_9 ;
struct V_6 * V_7 = NULL ;
unsigned char * V_24 = NULL , * V_126 ;
unsigned int V_127 , V_128 , V_47 , V_129 , V_130 ;
T_3 V_36 = V_131 ;
int V_13 ;
unsigned short V_32 ;
if ( ! V_2 -> V_17 . V_18 ) {
F_8 ( L_69 ) ;
return V_132 ;
}
V_130 = V_5 -> V_133 [ 1 ] & 0x1f ;
if ( V_130 != 0x00 ) {
F_8 ( L_70 ) ;
return V_132 ;
}
V_7 = F_47 ( sizeof( struct V_6 ) , V_104 ) ;
if ( ! V_7 ) {
F_8 ( L_71 ) ;
return V_134 ;
}
V_7 -> V_81 = V_5 ;
V_24 = F_60 ( V_5 ) ;
if ( ! V_24 ) {
F_8 ( L_72 ) ;
F_23 ( V_7 ) ;
return V_134 ;
}
V_127 = V_24 [ 0 ] ;
V_128 = ( V_24 [ 1 ] & 0x18 ) >> 3 ;
V_32 = F_11 ( & V_24 [ 2 ] ) ;
V_47 = F_61 ( & V_24 [ 8 ] ) ;
V_129 = F_61 ( & V_24 [ 12 ] ) ;
if ( V_129 != 0 ) {
F_8 ( L_73 ) ;
goto V_38;
}
F_6 ( L_74
L_75 , V_127 , V_128 ,
V_32 , V_47 , V_129 ) ;
V_13 = F_12 ( V_5 , V_7 , & V_24 [ 16 ] , V_32 ) ;
if ( V_13 <= 0 )
goto V_38;
if ( V_7 -> V_20 -> V_17 . V_103 !=
V_7 -> V_19 -> V_17 . V_103 ) {
F_8 ( L_76
L_77 ,
V_7 -> V_20 -> V_17 . V_103 ,
V_7 -> V_19 -> V_17 . V_103 ) ;
F_19 ( V_7 ) ;
V_36 = V_135 ;
goto V_38;
}
F_6 ( L_78 , V_13 ,
V_13 * V_35 ) ;
V_126 = & V_24 [ 16 ] ;
V_126 += ( V_13 * V_35 ) ;
V_13 = F_15 ( V_5 , V_7 , V_126 , V_47 ) ;
if ( V_13 <= 0 ) {
F_19 ( V_7 ) ;
goto V_38;
}
F_62 ( V_5 ) ;
F_6 ( L_79 , V_13 ,
V_13 * V_48 ) ;
F_63 ( & V_7 -> V_115 , F_54 ) ;
F_64 ( V_53 , & V_7 -> V_115 ) ;
return V_136 ;
V_38:
if ( V_24 )
F_62 ( V_5 ) ;
F_23 ( V_7 ) ;
return V_36 ;
}
static T_3 F_65 ( struct V_5 * V_5 )
{
unsigned char * V_24 ;
V_24 = F_60 ( V_5 ) ;
if ( ! V_24 ) {
F_8 ( L_80
L_81 ) ;
return V_134 ;
}
if ( V_5 -> V_94 < 54 ) {
F_8 ( L_82
L_83 , V_5 -> V_94 ) ;
F_62 ( V_5 ) ;
return V_137 ;
}
V_24 [ 4 ] = 0x1 ;
F_66 ( V_138 , & V_24 [ 8 ] ) ;
F_66 ( V_139 , & V_24 [ 10 ] ) ;
F_50 ( V_140 , & V_24 [ 12 ] ) ;
F_50 ( V_141 , & V_24 [ 16 ] ) ;
F_50 ( 0x0 , & V_24 [ 20 ] ) ;
F_50 ( 0x0 , & V_24 [ 24 ] ) ;
F_50 ( 0x0 , & V_24 [ 28 ] ) ;
F_66 ( V_142 , & V_24 [ 34 ] ) ;
V_24 [ 36 ] = V_143 ;
V_24 [ 37 ] = V_144 ;
V_24 [ 38 ] = V_145 ;
V_24 [ 39 ] = V_146 ;
V_24 [ 43 ] = 0x2 ;
V_24 [ 44 ] = 0x02 ;
V_24 [ 45 ] = 0xe4 ;
F_50 ( 42 , & V_24 [ 0 ] ) ;
F_62 ( V_5 ) ;
F_57 ( V_5 , V_147 ) ;
return V_136 ;
}
T_3 F_67 ( struct V_5 * V_5 )
{
unsigned char * V_88 = & V_5 -> V_133 [ 0 ] ;
int V_130 = ( V_88 [ 1 ] & 0x1f ) , V_127 = V_88 [ 2 ] ;
T_3 V_13 = V_136 ;
F_6 ( L_84
L_85 , V_130 , V_127 , V_5 -> V_94 ) ;
if ( V_127 != 0 ) {
F_8 ( L_86
L_87 ) ;
return V_137 ;
}
switch ( V_130 ) {
case V_148 :
V_13 = F_65 ( V_5 ) ;
break;
case V_149 :
case V_150 :
case V_151 :
default:
F_8 ( L_88 , V_130 ) ;
return V_137 ;
}
return V_13 ;
}
