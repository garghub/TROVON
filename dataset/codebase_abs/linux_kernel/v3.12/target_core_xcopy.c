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
if ( V_8 == true )
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
if ( V_8 == true ) {
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
if ( V_8 == true ) {
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
if ( V_8 == true )
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
if ( V_54 -> V_55 )
F_23 ( V_5 -> V_56 ) ;
F_23 ( V_54 ) ;
}
static int F_24 ( struct V_5 * V_5 )
{
struct V_53 * V_54 = F_22 ( V_5 ,
struct V_53 , V_5 ) ;
F_25 ( & V_54 -> V_57 ) ;
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
V_58 = F_31 ( L_38 , V_59 , 0 ) ;
if ( ! V_58 ) {
F_8 ( L_39 ) ;
return - V_60 ;
}
memset ( & V_61 , 0 , sizeof( struct V_62 ) ) ;
F_32 ( & V_61 . V_63 ) ;
F_32 ( & V_61 . V_64 ) ;
F_33 ( & V_61 . V_65 ) ;
memset ( & V_66 , 0 , sizeof( struct V_67 ) ) ;
F_32 ( & V_66 . V_68 ) ;
F_32 ( & V_66 . V_69 ) ;
F_32 ( & V_66 . V_70 ) ;
V_61 . V_71 = & V_66 ;
V_66 . V_72 = & V_73 ;
memset ( & V_74 , 0 , sizeof( struct V_75 ) ) ;
F_32 ( & V_74 . V_76 ) ;
F_32 ( & V_74 . V_77 ) ;
memset ( & V_78 , 0 , sizeof( struct V_79 ) ) ;
F_32 ( & V_78 . V_80 ) ;
F_32 ( & V_78 . V_81 ) ;
V_74 . V_82 = & V_66 ;
V_74 . V_83 = & V_78 ;
V_78 . V_82 = & V_66 ;
V_78 . V_75 = & V_74 ;
return 0 ;
}
void F_34 ( void )
{
if ( V_58 )
F_35 ( V_58 ) ;
}
static void F_36 (
struct V_53 * V_54 ,
struct V_6 * V_7 ,
bool V_55 )
{
struct V_5 * V_84 = V_7 -> V_85 ;
struct V_5 * V_86 = & V_54 -> V_5 ;
if ( V_7 -> V_32 == V_33 ) {
if ( V_55 ) {
V_54 -> V_55 = V_55 ;
V_86 -> V_56 -> V_87 = & V_61 ;
F_6 ( L_40
L_41 ,
V_86 -> V_56 -> V_87 ) ;
} else {
V_86 -> V_56 = V_84 -> V_56 ;
V_86 -> V_9 = V_84 -> V_9 ;
F_6 ( L_42
L_43 , V_86 -> V_9 ) ;
V_86 -> V_56 = V_84 -> V_56 ;
F_6 ( L_44 ,
V_86 -> V_56 ) ;
}
} else {
if ( V_55 ) {
V_54 -> V_55 = V_55 ;
V_86 -> V_56 -> V_87 = & V_61 ;
F_6 ( L_45
L_46 ,
V_86 -> V_56 -> V_87 ) ;
} else {
V_86 -> V_56 = V_84 -> V_56 ;
V_86 -> V_9 = V_84 -> V_9 ;
F_6 ( L_47
L_43 , V_86 -> V_9 ) ;
V_86 -> V_56 = V_84 -> V_56 ;
F_6 ( L_48 ,
V_86 -> V_56 ) ;
}
}
}
static int F_37 (
struct V_53 * V_54 ,
struct V_6 * V_7 ,
struct V_1 * V_9 ,
struct V_5 * V_86 ,
bool V_55 )
{
if ( V_55 == false ) {
V_86 -> V_88 |= V_89 | V_90 ;
return 0 ;
}
V_86 -> V_56 = F_38 ( sizeof( struct V_56 ) , V_91 ) ;
if ( ! V_86 -> V_56 ) {
F_8 ( L_49 ) ;
return - V_60 ;
}
F_39 ( & V_86 -> V_56 -> V_92 ) ;
F_32 ( & V_86 -> V_56 -> V_93 ) ;
F_32 ( & V_86 -> V_56 -> V_94 ) ;
F_40 ( & V_86 -> V_56 -> V_95 ) ;
F_40 ( & V_86 -> V_56 -> V_96 ) ;
F_40 ( & V_86 -> V_56 -> V_97 ) ;
V_86 -> V_9 = V_9 ;
F_6 ( L_50 , V_86 -> V_9 ) ;
V_86 -> V_56 -> V_98 = V_9 ;
V_86 -> V_88 |= V_89 | V_90 ;
F_6 ( L_51 ,
V_86 -> V_56 -> V_98 ) ;
return 0 ;
}
static int F_41 (
struct V_53 * V_54 ,
struct V_6 * V_7 ,
struct V_1 * V_9 ,
unsigned char * V_99 ,
bool V_55 ,
bool V_100 )
{
struct V_5 * V_101 = & V_54 -> V_5 ;
T_3 V_102 ;
int V_39 = 0 , V_16 ;
V_16 = F_37 ( V_54 , V_7 , V_9 , V_101 , V_55 ) ;
if ( V_16 < 0 ) {
V_39 = V_16 ;
goto V_41;
}
V_54 -> V_6 = V_7 ;
F_36 ( V_54 , V_7 , V_55 ) ;
V_102 = F_42 ( V_101 , V_99 ) ;
if ( V_102 ) {
V_39 = - V_26 ;
goto V_41;
}
if ( V_100 ) {
V_16 = F_43 ( & V_101 -> V_103 , & V_101 -> V_104 ,
V_101 -> V_105 , false ) ;
if ( V_16 < 0 ) {
V_39 = V_16 ;
goto V_41;
}
V_101 -> V_88 |= V_106 ;
} else {
V_102 = F_44 ( V_101 ,
V_7 -> V_107 , V_7 -> V_108 ,
NULL , 0 ) ;
if ( V_102 ) {
V_39 = - V_26 ;
goto V_41;
}
F_6 ( L_52
L_53 , V_101 -> V_103 , V_101 -> V_104 ) ;
}
return 0 ;
V_41:
if ( V_55 == true )
F_23 ( V_101 -> V_56 ) ;
return V_39 ;
}
static int F_45 ( struct V_53 * V_54 )
{
struct V_5 * V_5 = & V_54 -> V_5 ;
T_3 V_102 ;
V_102 = F_46 ( V_5 ) ;
if ( V_102 )
return - V_26 ;
if ( V_5 -> V_109 == V_110 )
F_47 ( V_5 ) ;
F_48 ( & V_54 -> V_57 ) ;
F_6 ( L_54 ,
V_5 -> V_111 ) ;
return ( V_5 -> V_111 ) ? - V_26 : 0 ;
}
static int F_49 (
struct V_5 * V_84 ,
struct V_6 * V_7 ,
struct V_1 * V_23 ,
T_4 V_47 ,
T_2 V_112 )
{
struct V_53 * V_54 ;
struct V_5 * V_5 ;
T_2 V_113 = ( V_112 * V_23 -> V_20 . V_114 ) ;
int V_16 ;
unsigned char V_99 [ 16 ] ;
bool V_55 = ( V_7 -> V_32 == V_34 ) ;
V_54 = F_38 ( sizeof( struct V_53 ) , V_91 ) ;
if ( ! V_54 ) {
F_8 ( L_55 ) ;
return - V_60 ;
}
F_39 ( & V_54 -> V_57 ) ;
V_5 = & V_54 -> V_5 ;
memset ( & V_99 [ 0 ] , 0 , 16 ) ;
V_99 [ 0 ] = V_115 ;
F_50 ( V_47 , & V_99 [ 2 ] ) ;
F_51 ( V_112 , & V_99 [ 10 ] ) ;
F_6 ( L_56 ,
( unsigned long long ) V_47 , V_112 , V_113 ) ;
F_52 ( V_5 , & V_73 , NULL , V_113 ,
V_116 , 0 , & V_54 -> V_117 [ 0 ] ) ;
V_7 -> V_118 = V_54 ;
V_16 = F_41 ( V_54 , V_7 , V_23 , & V_99 [ 0 ] ,
V_55 , true ) ;
if ( V_16 < 0 ) {
F_53 ( V_5 , 0 ) ;
return V_16 ;
}
V_7 -> V_107 = V_5 -> V_103 ;
V_7 -> V_108 = V_5 -> V_104 ;
F_6 ( L_57
L_58 , V_7 -> V_107 , V_7 -> V_108 ) ;
V_16 = F_45 ( V_54 ) ;
if ( V_16 < 0 ) {
F_53 ( V_5 , 0 ) ;
return V_16 ;
}
V_5 -> V_103 = NULL ;
V_5 -> V_104 = 0 ;
return 0 ;
}
static int F_54 (
struct V_5 * V_84 ,
struct V_6 * V_7 ,
struct V_1 * V_22 ,
T_4 V_48 ,
T_2 V_119 )
{
struct V_53 * V_54 ;
struct V_5 * V_5 ;
T_2 V_113 = ( V_119 * V_22 -> V_20 . V_114 ) ;
int V_16 ;
unsigned char V_99 [ 16 ] ;
bool V_55 = ( V_7 -> V_32 == V_33 ) ;
V_54 = F_38 ( sizeof( struct V_53 ) , V_91 ) ;
if ( ! V_54 ) {
F_8 ( L_55 ) ;
return - V_60 ;
}
F_39 ( & V_54 -> V_57 ) ;
V_5 = & V_54 -> V_5 ;
memset ( & V_99 [ 0 ] , 0 , 16 ) ;
V_99 [ 0 ] = V_120 ;
F_50 ( V_48 , & V_99 [ 2 ] ) ;
F_51 ( V_119 , & V_99 [ 10 ] ) ;
F_6 ( L_59 ,
( unsigned long long ) V_48 , V_119 , V_113 ) ;
F_52 ( V_5 , & V_73 , NULL , V_113 ,
V_110 , 0 , & V_54 -> V_117 [ 0 ] ) ;
V_7 -> V_121 = V_54 ;
V_16 = F_41 ( V_54 , V_7 , V_22 , & V_99 [ 0 ] ,
V_55 , false ) ;
if ( V_16 < 0 ) {
struct V_5 * V_122 = & V_7 -> V_118 -> V_5 ;
V_122 -> V_88 &= ~ V_106 ;
V_122 -> V_103 = V_7 -> V_107 ;
V_122 -> V_104 = V_7 -> V_108 ;
F_53 ( V_5 , 0 ) ;
return V_16 ;
}
V_16 = F_45 ( V_54 ) ;
if ( V_16 < 0 ) {
V_5 -> V_88 &= ~ V_106 ;
F_53 ( V_5 , 0 ) ;
return V_16 ;
}
return 0 ;
}
static void F_55 ( struct V_123 * V_124 )
{
struct V_6 * V_7 = F_22 ( V_124 , struct V_6 , V_125 ) ;
struct V_1 * V_23 = V_7 -> V_23 , * V_22 = V_7 -> V_22 ;
struct V_5 * V_84 = V_7 -> V_85 ;
T_4 V_47 = V_7 -> V_47 , V_48 = V_7 -> V_48 , V_126 ;
unsigned int V_127 ;
int V_16 ;
unsigned short V_46 = V_7 -> V_46 , V_128 , V_129 , V_130 = 0 ;
V_126 = V_47 + V_46 ;
V_127 = F_56 ( V_23 -> V_20 . V_131 ,
V_22 -> V_20 . V_131 ) ;
V_127 = F_57 ( T_2 , V_127 , V_132 ) ;
V_129 = F_57 ( V_133 , V_127 , ( ( V_133 ) ( ~ 0U ) ) ) ;
F_6 ( L_60 ,
V_46 , V_129 , ( unsigned long long ) V_126 ) ;
F_6 ( L_61 ,
( unsigned long long ) V_47 , ( unsigned long long ) V_48 ) ;
while ( V_47 < V_126 ) {
V_128 = F_56 ( V_46 , V_129 ) ;
F_6 ( L_62
L_63 , V_23 , ( unsigned long long ) V_47 , V_128 ) ;
V_16 = F_49 ( V_84 , V_7 , V_23 , V_47 , V_128 ) ;
if ( V_16 < 0 )
goto V_41;
V_47 += V_128 ;
F_6 ( L_64 ,
( unsigned long long ) V_47 ) ;
F_6 ( L_65
L_63 , V_22 , ( unsigned long long ) V_48 , V_128 ) ;
V_16 = F_54 ( V_84 , V_7 , V_22 ,
V_48 , V_128 ) ;
if ( V_16 < 0 ) {
F_53 ( & V_7 -> V_118 -> V_5 , 0 ) ;
goto V_41;
}
V_48 += V_128 ;
F_6 ( L_66 ,
( unsigned long long ) V_48 ) ;
V_130 += V_128 ;
V_46 -= V_128 ;
F_53 ( & V_7 -> V_118 -> V_5 , 0 ) ;
V_7 -> V_121 -> V_5 . V_88 &= ~ V_106 ;
F_53 ( & V_7 -> V_121 -> V_5 , 0 ) ;
}
F_19 ( V_7 ) ;
F_23 ( V_7 ) ;
F_6 ( L_67 ,
( unsigned long long ) V_47 , ( unsigned long long ) V_48 ) ;
F_6 ( L_68 ,
V_130 , V_130 * V_22 -> V_20 . V_114 ) ;
F_6 ( L_69 ) ;
F_58 ( V_84 , V_134 ) ;
return;
V_41:
F_19 ( V_7 ) ;
F_23 ( V_7 ) ;
F_59 ( L_70 ) ;
V_84 -> V_111 = V_135 ;
F_58 ( V_84 , V_135 ) ;
}
T_3 F_60 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_9 ;
struct V_6 * V_7 = NULL ;
unsigned char * V_27 = NULL , * V_136 ;
unsigned int V_137 , V_138 , V_50 , V_139 , V_140 ;
T_3 V_39 = V_141 ;
int V_16 ;
unsigned short V_35 ;
if ( ! V_2 -> V_20 . V_21 ) {
F_8 ( L_71 ) ;
return V_142 ;
}
V_140 = V_5 -> V_143 [ 1 ] & 0x1f ;
if ( V_140 != 0x00 ) {
F_8 ( L_72 ) ;
return V_142 ;
}
V_7 = F_38 ( sizeof( struct V_6 ) , V_91 ) ;
if ( ! V_7 ) {
F_8 ( L_73 ) ;
return V_144 ;
}
V_7 -> V_85 = V_5 ;
V_27 = F_61 ( V_5 ) ;
if ( ! V_27 ) {
F_8 ( L_74 ) ;
F_23 ( V_7 ) ;
return V_144 ;
}
V_137 = V_27 [ 0 ] ;
V_138 = ( V_27 [ 1 ] & 0x18 ) >> 3 ;
V_35 = F_11 ( & V_27 [ 2 ] ) ;
V_50 = F_62 ( & V_27 [ 8 ] ) ;
V_139 = F_62 ( & V_27 [ 12 ] ) ;
if ( V_139 != 0 ) {
F_8 ( L_75 ) ;
goto V_41;
}
F_6 ( L_76
L_77 , V_137 , V_138 ,
V_35 , V_50 , V_139 ) ;
V_16 = F_12 ( V_5 , V_7 , & V_27 [ 16 ] , V_35 ) ;
if ( V_16 <= 0 )
goto V_41;
if ( V_7 -> V_23 -> V_20 . V_114 !=
V_7 -> V_22 -> V_20 . V_114 ) {
F_8 ( L_78
L_79 ,
V_7 -> V_23 -> V_20 . V_114 ,
V_7 -> V_22 -> V_20 . V_114 ) ;
F_19 ( V_7 ) ;
V_39 = V_145 ;
goto V_41;
}
F_6 ( L_80 , V_16 ,
V_16 * V_38 ) ;
V_136 = & V_27 [ 16 ] ;
V_136 += ( V_16 * V_38 ) ;
V_16 = F_15 ( V_5 , V_7 , V_136 , V_50 ) ;
if ( V_16 <= 0 ) {
F_19 ( V_7 ) ;
goto V_41;
}
F_63 ( V_5 ) ;
F_6 ( L_81 , V_16 ,
V_16 * V_51 ) ;
F_64 ( & V_7 -> V_125 , F_55 ) ;
F_65 ( V_58 , & V_7 -> V_125 ) ;
return V_146 ;
V_41:
if ( V_27 )
F_63 ( V_5 ) ;
F_23 ( V_7 ) ;
return V_39 ;
}
static T_3 F_66 ( struct V_5 * V_5 )
{
unsigned char * V_27 ;
V_27 = F_61 ( V_5 ) ;
if ( ! V_27 ) {
F_8 ( L_82
L_83 ) ;
return V_144 ;
}
if ( V_5 -> V_105 < 54 ) {
F_8 ( L_84
L_85 , V_5 -> V_105 ) ;
F_63 ( V_5 ) ;
return V_147 ;
}
V_27 [ 4 ] = 0x1 ;
F_67 ( V_148 , & V_27 [ 8 ] ) ;
F_67 ( V_149 , & V_27 [ 10 ] ) ;
F_51 ( V_150 , & V_27 [ 12 ] ) ;
F_51 ( V_151 , & V_27 [ 16 ] ) ;
F_51 ( 0x0 , & V_27 [ 20 ] ) ;
F_51 ( 0x0 , & V_27 [ 24 ] ) ;
F_51 ( 0x0 , & V_27 [ 28 ] ) ;
F_67 ( V_152 , & V_27 [ 34 ] ) ;
V_27 [ 36 ] = V_153 ;
V_27 [ 37 ] = V_154 ;
V_27 [ 38 ] = V_155 ;
V_27 [ 39 ] = V_156 ;
V_27 [ 43 ] = 0x2 ;
V_27 [ 44 ] = 0x02 ;
V_27 [ 45 ] = 0xe4 ;
F_51 ( 42 , & V_27 [ 0 ] ) ;
F_63 ( V_5 ) ;
F_58 ( V_5 , V_157 ) ;
return V_146 ;
}
T_3 F_68 ( struct V_5 * V_5 )
{
unsigned char * V_99 = & V_5 -> V_143 [ 0 ] ;
int V_140 = ( V_99 [ 1 ] & 0x1f ) , V_137 = V_99 [ 2 ] ;
T_3 V_16 = V_146 ;
F_6 ( L_86
L_87 , V_140 , V_137 , V_5 -> V_105 ) ;
if ( V_137 != 0 ) {
F_8 ( L_88
L_89 ) ;
return V_147 ;
}
switch ( V_140 ) {
case V_158 :
V_16 = F_66 ( V_5 ) ;
break;
case V_159 :
case V_160 :
case V_161 :
default:
F_8 ( L_90 , V_140 ) ;
return V_147 ;
}
return V_16 ;
}
