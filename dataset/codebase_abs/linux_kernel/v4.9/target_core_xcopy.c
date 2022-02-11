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
F_10 ( L_8 ) ;
return - V_23 ;
}
static int F_11 ( struct V_5 * V_5 , struct V_6 * V_7 ,
unsigned char * V_24 , bool V_8 )
{
unsigned char * V_25 = V_24 ;
unsigned short V_26 ;
T_1 V_27 ;
V_26 = F_12 ( & V_25 [ 2 ] ) ;
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
static int F_13 ( struct V_5 * V_5 ,
struct V_6 * V_7 , unsigned char * V_24 ,
unsigned short V_32 , T_2 * V_33 )
{
struct V_1 * V_34 = V_5 -> V_9 ;
unsigned char * V_25 = V_24 ;
int V_35 = V_32 % V_36 , V_13 , V_37 = 0 ;
unsigned short V_38 = 0 ;
bool V_8 = true ;
* V_33 = V_39 ;
if ( V_35 != 0 ) {
F_8 ( L_19
L_20 , V_36 ) ;
return - V_23 ;
}
if ( V_32 > 64 ) {
F_8 ( L_21
L_22 , V_32 ) ;
return - V_23 ;
}
memset ( & V_7 -> V_28 [ 0 ] , 0 , V_11 ) ;
F_1 ( V_34 , & V_7 -> V_28 [ 0 ] ) ;
while ( V_38 < V_32 ) {
switch ( V_25 [ 0 ] ) {
case 0xe4 :
V_13 = F_11 ( V_5 , V_7 ,
& V_25 [ 0 ] , V_8 ) ;
if ( V_13 != 0 )
goto V_40;
if ( V_8 )
V_8 = false ;
else
V_8 = true ;
V_38 += V_36 ;
V_25 += V_36 ;
V_37 ++ ;
break;
default:
F_8 ( L_23
L_24 , V_25 [ 0 ] ) ;
goto V_40;
}
}
if ( V_7 -> V_29 == V_30 )
V_13 = F_3 ( V_5 , V_7 , true ) ;
else
V_13 = F_3 ( V_5 , V_7 , false ) ;
if ( V_13 < 0 ) {
* V_33 = V_41 ;
goto V_40;
}
F_6 ( L_25 ,
V_7 -> V_20 , & V_7 -> V_15 [ 0 ] ) ;
F_6 ( L_26 ,
V_7 -> V_19 , & V_7 -> V_14 [ 0 ] ) ;
return V_37 ;
V_40:
return - V_23 ;
}
static int F_14 ( struct V_5 * V_5 , struct V_6 * V_7 ,
unsigned char * V_24 )
{
unsigned char * V_25 = V_24 ;
int V_42 = ( V_25 [ 1 ] & 0x02 ) ;
unsigned short V_43 ;
V_43 = F_12 ( & V_25 [ 2 ] ) ;
if ( V_43 != 0x18 ) {
F_8 ( L_27
L_28 , V_43 ) ;
return - V_23 ;
}
V_7 -> V_44 = F_12 ( & V_25 [ 4 ] ) ;
V_7 -> V_45 = F_12 ( & V_25 [ 6 ] ) ;
F_6 ( L_29 ,
V_43 , V_7 -> V_44 , V_7 -> V_45 , V_42 ) ;
V_7 -> V_46 = F_12 ( & V_25 [ 10 ] ) ;
V_7 -> V_47 = F_15 ( & V_25 [ 12 ] ) ;
V_7 -> V_48 = F_15 ( & V_25 [ 20 ] ) ;
F_6 ( L_30 ,
V_7 -> V_46 , ( unsigned long long ) V_7 -> V_47 ,
( unsigned long long ) V_7 -> V_48 ) ;
if ( V_42 != 0 ) {
V_7 -> V_49 = ( V_25 [ 29 ] & 0xff ) << 16 ;
V_7 -> V_49 |= ( V_25 [ 30 ] & 0xff ) << 8 ;
V_7 -> V_49 |= V_25 [ 31 ] & 0xff ;
F_6 ( L_31 , V_7 -> V_49 ) ;
}
return 0 ;
}
static int F_16 ( struct V_5 * V_5 ,
struct V_6 * V_7 , unsigned char * V_24 ,
unsigned int V_50 )
{
unsigned char * V_25 = V_24 ;
unsigned int V_38 = 0 ;
int V_35 = V_50 % V_51 , V_13 , V_37 = 0 ;
if ( V_35 != 0 ) {
F_8 ( L_32
L_20 , V_51 ) ;
return - V_23 ;
}
while ( V_38 < V_50 ) {
switch ( V_25 [ 0 ] ) {
case 0x02 :
V_13 = F_14 ( V_5 , V_7 , V_25 ) ;
if ( V_13 < 0 )
goto V_40;
V_37 ++ ;
V_38 += V_51 ;
V_25 += V_51 ;
break;
default:
F_8 ( L_33
L_34 , V_25 [ 0 ] ) ;
goto V_40;
}
}
return V_37 ;
V_40:
return - V_23 ;
}
static char * F_17 ( void )
{
return L_35 ;
}
static int F_18 ( struct V_5 * V_5 )
{
return 0 ;
}
static void F_19 ( struct V_6 * V_7 )
{
struct V_1 * V_52 ;
if ( V_7 -> V_29 == V_30 )
V_52 = V_7 -> V_19 ;
else
V_52 = V_7 -> V_20 ;
F_6 ( L_36
L_37 ,
V_52 , & V_52 -> V_21 . V_22 ) ;
F_20 ( & V_52 -> V_21 . V_22 ) ;
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
F_32 ( & V_59 . V_63 ) ;
V_59 . V_64 = & V_65 ;
memset ( & V_66 , 0 , sizeof( struct V_67 ) ) ;
F_32 ( & V_66 . V_68 ) ;
F_32 ( & V_66 . V_69 ) ;
memset ( & V_70 , 0 , sizeof( struct V_71 ) ) ;
F_32 ( & V_70 . V_72 ) ;
F_32 ( & V_70 . V_73 ) ;
F_32 ( & V_70 . V_74 ) ;
F_33 ( & V_70 . V_75 ) ;
V_66 . V_76 = & V_59 ;
V_66 . V_77 = & V_70 ;
V_70 . V_76 = & V_59 ;
V_70 . V_67 = & V_66 ;
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
bool V_78 )
{
struct V_5 * V_79 = V_7 -> V_80 ;
struct V_5 * V_81 = & V_54 -> V_5 ;
if ( V_7 -> V_29 == V_30 ) {
if ( V_78 ) {
V_54 -> V_78 = V_78 ;
} else {
V_81 -> V_82 = V_79 -> V_82 ;
V_81 -> V_9 = V_79 -> V_9 ;
F_6 ( L_40
L_41 , V_81 -> V_9 ) ;
V_81 -> V_82 = V_79 -> V_82 ;
F_6 ( L_42 ,
V_81 -> V_82 ) ;
}
} else {
if ( V_78 ) {
V_54 -> V_78 = V_78 ;
} else {
V_81 -> V_82 = V_79 -> V_82 ;
V_81 -> V_9 = V_79 -> V_9 ;
F_6 ( L_43
L_41 , V_81 -> V_9 ) ;
V_81 -> V_82 = V_79 -> V_82 ;
F_6 ( L_44 ,
V_81 -> V_82 ) ;
}
}
}
static void F_37 ( struct V_1 * V_9 ,
struct V_5 * V_81 , bool V_78 )
{
if ( V_78 ) {
F_6 ( L_45 ,
V_81 -> V_9 ) ;
V_81 -> V_82 = & V_9 -> V_83 ;
V_81 -> V_9 = V_9 ;
}
V_81 -> V_84 |= V_85 ;
}
static int F_38 (
struct V_53 * V_54 ,
struct V_6 * V_7 ,
struct V_1 * V_9 ,
unsigned char * V_86 ,
bool V_78 ,
bool V_87 )
{
struct V_5 * V_88 = & V_54 -> V_5 ;
T_2 V_89 ;
int V_37 = 0 , V_13 ;
F_37 ( V_9 , V_88 , V_78 ) ;
V_54 -> V_6 = V_7 ;
F_36 ( V_54 , V_7 , V_78 ) ;
V_88 -> V_90 = 0 ;
V_89 = F_39 ( V_88 , V_86 ) ;
if ( V_89 ) {
V_37 = - V_23 ;
goto V_40;
}
if ( V_87 ) {
V_13 = F_40 ( & V_88 -> V_91 , & V_88 -> V_92 ,
V_88 -> V_93 , false , false ) ;
if ( V_13 < 0 ) {
V_37 = V_13 ;
goto V_40;
}
V_88 -> V_84 |= V_94 ;
} else {
V_89 = F_41 ( V_88 ,
V_7 -> V_95 , V_7 -> V_96 ,
NULL , 0 ) ;
if ( V_89 ) {
V_37 = - V_23 ;
goto V_40;
}
F_6 ( L_46
L_47 , V_88 -> V_91 , V_88 -> V_92 ) ;
}
return 0 ;
V_40:
return V_37 ;
}
static int F_42 ( struct V_53 * V_54 )
{
struct V_5 * V_5 = & V_54 -> V_5 ;
T_2 V_89 ;
V_89 = F_43 ( V_5 ) ;
if ( V_89 )
return - V_23 ;
if ( V_5 -> V_97 == V_98 )
F_44 ( V_5 ) ;
F_45 ( & V_54 -> V_55 ) ;
F_6 ( L_48 ,
V_5 -> V_99 ) ;
return ( V_5 -> V_99 ) ? - V_23 : 0 ;
}
static int F_46 (
struct V_5 * V_79 ,
struct V_6 * V_7 ,
struct V_1 * V_20 ,
T_3 V_47 ,
T_4 V_100 )
{
struct V_53 * V_54 ;
struct V_5 * V_5 ;
T_4 V_101 = ( V_100 * V_20 -> V_17 . V_102 ) ;
int V_13 ;
unsigned char V_86 [ 16 ] ;
bool V_78 = ( V_7 -> V_29 == V_31 ) ;
V_54 = F_47 ( sizeof( struct V_53 ) , V_103 ) ;
if ( ! V_54 ) {
F_8 ( L_49 ) ;
return - V_58 ;
}
F_48 ( & V_54 -> V_55 ) ;
V_5 = & V_54 -> V_5 ;
memset ( & V_86 [ 0 ] , 0 , 16 ) ;
V_86 [ 0 ] = V_104 ;
F_49 ( V_47 , & V_86 [ 2 ] ) ;
F_50 ( V_100 , & V_86 [ 10 ] ) ;
F_6 ( L_50 ,
( unsigned long long ) V_47 , V_100 , V_101 ) ;
F_51 ( V_5 , & V_65 , & V_70 , V_101 ,
V_105 , 0 , & V_54 -> V_106 [ 0 ] ) ;
V_7 -> V_107 = V_54 ;
V_13 = F_38 ( V_54 , V_7 , V_20 , & V_86 [ 0 ] ,
V_78 , true ) ;
if ( V_13 < 0 ) {
V_79 -> V_99 = V_54 -> V_5 . V_99 ;
F_52 ( V_5 , 0 ) ;
return V_13 ;
}
V_7 -> V_95 = V_5 -> V_91 ;
V_7 -> V_96 = V_5 -> V_92 ;
F_6 ( L_51
L_52 , V_7 -> V_95 , V_7 -> V_96 ) ;
V_13 = F_42 ( V_54 ) ;
if ( V_13 < 0 ) {
V_79 -> V_99 = V_54 -> V_5 . V_99 ;
F_52 ( V_5 , 0 ) ;
return V_13 ;
}
V_5 -> V_91 = NULL ;
V_5 -> V_92 = 0 ;
return 0 ;
}
static int F_53 (
struct V_5 * V_79 ,
struct V_6 * V_7 ,
struct V_1 * V_19 ,
T_3 V_48 ,
T_4 V_108 )
{
struct V_53 * V_54 ;
struct V_5 * V_5 ;
T_4 V_101 = ( V_108 * V_19 -> V_17 . V_102 ) ;
int V_13 ;
unsigned char V_86 [ 16 ] ;
bool V_78 = ( V_7 -> V_29 == V_30 ) ;
V_54 = F_47 ( sizeof( struct V_53 ) , V_103 ) ;
if ( ! V_54 ) {
F_8 ( L_49 ) ;
return - V_58 ;
}
F_48 ( & V_54 -> V_55 ) ;
V_5 = & V_54 -> V_5 ;
memset ( & V_86 [ 0 ] , 0 , 16 ) ;
V_86 [ 0 ] = V_109 ;
F_49 ( V_48 , & V_86 [ 2 ] ) ;
F_50 ( V_108 , & V_86 [ 10 ] ) ;
F_6 ( L_53 ,
( unsigned long long ) V_48 , V_108 , V_101 ) ;
F_51 ( V_5 , & V_65 , & V_70 , V_101 ,
V_98 , 0 , & V_54 -> V_106 [ 0 ] ) ;
V_7 -> V_110 = V_54 ;
V_13 = F_38 ( V_54 , V_7 , V_19 , & V_86 [ 0 ] ,
V_78 , false ) ;
if ( V_13 < 0 ) {
struct V_5 * V_111 = & V_7 -> V_107 -> V_5 ;
V_79 -> V_99 = V_54 -> V_5 . V_99 ;
V_111 -> V_84 &= ~ V_94 ;
V_111 -> V_91 = V_7 -> V_95 ;
V_111 -> V_92 = V_7 -> V_96 ;
F_52 ( V_5 , 0 ) ;
return V_13 ;
}
V_13 = F_42 ( V_54 ) ;
if ( V_13 < 0 ) {
V_79 -> V_99 = V_54 -> V_5 . V_99 ;
V_5 -> V_84 &= ~ V_94 ;
F_52 ( V_5 , 0 ) ;
return V_13 ;
}
return 0 ;
}
static void F_54 ( struct V_112 * V_113 )
{
struct V_6 * V_7 = F_22 ( V_113 , struct V_6 , V_114 ) ;
struct V_1 * V_20 = V_7 -> V_20 , * V_19 = V_7 -> V_19 ;
struct V_5 * V_79 = V_7 -> V_80 ;
T_3 V_47 = V_7 -> V_47 , V_48 = V_7 -> V_48 , V_115 ;
unsigned int V_116 ;
int V_13 ;
unsigned short V_46 = V_7 -> V_46 , V_117 , V_118 , V_119 = 0 ;
V_115 = V_47 + V_46 ;
V_116 = F_55 ( V_20 -> V_17 . V_120 ,
V_19 -> V_17 . V_120 ) ;
V_116 = F_56 ( T_4 , V_116 , V_121 ) ;
V_118 = F_56 ( V_122 , V_116 , ( ( V_122 ) ( ~ 0U ) ) ) ;
F_6 ( L_54 ,
V_46 , V_118 , ( unsigned long long ) V_115 ) ;
F_6 ( L_55 ,
( unsigned long long ) V_47 , ( unsigned long long ) V_48 ) ;
while ( V_47 < V_115 ) {
V_117 = F_55 ( V_46 , V_118 ) ;
F_6 ( L_56
L_57 , V_20 , ( unsigned long long ) V_47 , V_117 ) ;
V_13 = F_46 ( V_79 , V_7 , V_20 , V_47 , V_117 ) ;
if ( V_13 < 0 )
goto V_40;
V_47 += V_117 ;
F_6 ( L_58 ,
( unsigned long long ) V_47 ) ;
F_6 ( L_59
L_57 , V_19 , ( unsigned long long ) V_48 , V_117 ) ;
V_13 = F_53 ( V_79 , V_7 , V_19 ,
V_48 , V_117 ) ;
if ( V_13 < 0 ) {
F_52 ( & V_7 -> V_107 -> V_5 , 0 ) ;
goto V_40;
}
V_48 += V_117 ;
F_6 ( L_60 ,
( unsigned long long ) V_48 ) ;
V_119 += V_117 ;
V_46 -= V_117 ;
F_52 ( & V_7 -> V_107 -> V_5 , 0 ) ;
V_7 -> V_110 -> V_5 . V_84 &= ~ V_94 ;
F_52 ( & V_7 -> V_110 -> V_5 , 0 ) ;
}
F_19 ( V_7 ) ;
F_23 ( V_7 ) ;
F_6 ( L_61 ,
( unsigned long long ) V_47 , ( unsigned long long ) V_48 ) ;
F_6 ( L_62 ,
V_119 , V_119 * V_19 -> V_17 . V_102 ) ;
F_6 ( L_63 ) ;
F_57 ( V_79 , V_123 ) ;
return;
V_40:
F_19 ( V_7 ) ;
F_23 ( V_7 ) ;
if ( V_79 -> V_99 == V_123 ) {
F_58 ( L_64
L_65 , V_13 ) ;
V_79 -> V_99 = V_124 ;
}
F_57 ( V_79 , V_124 ) ;
}
T_2 F_59 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_9 ;
struct V_6 * V_7 = NULL ;
unsigned char * V_24 = NULL , * V_125 ;
unsigned int V_126 , V_127 , V_50 , V_128 , V_129 ;
T_2 V_37 = V_39 ;
int V_13 ;
unsigned short V_32 ;
if ( ! V_2 -> V_17 . V_18 ) {
F_8 ( L_66 ) ;
return V_130 ;
}
V_129 = V_5 -> V_131 [ 1 ] & 0x1f ;
if ( V_129 != 0x00 ) {
F_8 ( L_67 ) ;
return V_130 ;
}
V_7 = F_47 ( sizeof( struct V_6 ) , V_103 ) ;
if ( ! V_7 ) {
F_8 ( L_68 ) ;
return V_132 ;
}
V_7 -> V_80 = V_5 ;
V_24 = F_60 ( V_5 ) ;
if ( ! V_24 ) {
F_8 ( L_69 ) ;
F_23 ( V_7 ) ;
return V_132 ;
}
V_126 = V_24 [ 0 ] ;
V_127 = ( V_24 [ 1 ] & 0x18 ) >> 3 ;
V_32 = F_12 ( & V_24 [ 2 ] ) ;
V_50 = F_61 ( & V_24 [ 8 ] ) ;
V_128 = F_61 ( & V_24 [ 12 ] ) ;
if ( V_128 != 0 ) {
F_8 ( L_70 ) ;
goto V_40;
}
F_6 ( L_71
L_72 , V_126 , V_127 ,
V_32 , V_50 , V_128 ) ;
V_13 = F_13 ( V_5 , V_7 , & V_24 [ 16 ] , V_32 , & V_37 ) ;
if ( V_13 <= 0 )
goto V_40;
if ( V_7 -> V_20 -> V_17 . V_102 !=
V_7 -> V_19 -> V_17 . V_102 ) {
F_8 ( L_73
L_74 ,
V_7 -> V_20 -> V_17 . V_102 ,
V_7 -> V_19 -> V_17 . V_102 ) ;
F_19 ( V_7 ) ;
V_37 = V_133 ;
goto V_40;
}
F_6 ( L_75 , V_13 ,
V_13 * V_36 ) ;
V_125 = & V_24 [ 16 ] ;
V_125 += ( V_13 * V_36 ) ;
V_13 = F_16 ( V_5 , V_7 , V_125 , V_50 ) ;
if ( V_13 <= 0 ) {
F_19 ( V_7 ) ;
goto V_40;
}
F_62 ( V_5 ) ;
F_6 ( L_76 , V_13 ,
V_13 * V_51 ) ;
F_63 ( & V_7 -> V_114 , F_54 ) ;
F_64 ( V_56 , & V_7 -> V_114 ) ;
return V_134 ;
V_40:
if ( V_24 )
F_62 ( V_5 ) ;
F_23 ( V_7 ) ;
return V_37 ;
}
static T_2 F_65 ( struct V_5 * V_5 )
{
unsigned char * V_24 ;
V_24 = F_60 ( V_5 ) ;
if ( ! V_24 ) {
F_8 ( L_77
L_78 ) ;
return V_132 ;
}
if ( V_5 -> V_93 < 54 ) {
F_8 ( L_79
L_80 , V_5 -> V_93 ) ;
F_62 ( V_5 ) ;
return V_135 ;
}
V_24 [ 4 ] = 0x1 ;
F_66 ( V_136 , & V_24 [ 8 ] ) ;
F_66 ( V_137 , & V_24 [ 10 ] ) ;
F_50 ( V_138 , & V_24 [ 12 ] ) ;
F_50 ( V_139 , & V_24 [ 16 ] ) ;
F_50 ( 0x0 , & V_24 [ 20 ] ) ;
F_50 ( 0x0 , & V_24 [ 24 ] ) ;
F_50 ( 0x0 , & V_24 [ 28 ] ) ;
F_66 ( V_140 , & V_24 [ 34 ] ) ;
V_24 [ 36 ] = V_141 ;
V_24 [ 37 ] = V_142 ;
V_24 [ 38 ] = V_143 ;
V_24 [ 39 ] = V_144 ;
V_24 [ 43 ] = 0x2 ;
V_24 [ 44 ] = 0x02 ;
V_24 [ 45 ] = 0xe4 ;
F_50 ( 42 , & V_24 [ 0 ] ) ;
F_62 ( V_5 ) ;
F_57 ( V_5 , V_145 ) ;
return V_134 ;
}
T_2 F_67 ( struct V_5 * V_5 )
{
unsigned char * V_86 = & V_5 -> V_131 [ 0 ] ;
int V_129 = ( V_86 [ 1 ] & 0x1f ) , V_126 = V_86 [ 2 ] ;
T_2 V_13 = V_134 ;
F_6 ( L_81
L_82 , V_129 , V_126 , V_5 -> V_93 ) ;
if ( V_126 != 0 ) {
F_8 ( L_83
L_84 ) ;
return V_135 ;
}
switch ( V_129 ) {
case V_146 :
V_13 = F_65 ( V_5 ) ;
break;
case V_147 :
case V_148 :
case V_149 :
default:
F_8 ( L_85 , V_129 ) ;
return V_135 ;
}
return V_13 ;
}
