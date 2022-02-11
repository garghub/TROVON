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
static int F_17 ( struct V_5 * V_5 )
{
return 0 ;
}
static void F_18 ( struct V_6 * V_7 )
{
struct V_1 * V_49 ;
if ( V_7 -> V_29 == V_30 )
V_49 = V_7 -> V_19 ;
else
V_49 = V_7 -> V_20 ;
F_6 ( L_36
L_37 ,
V_49 , & V_49 -> V_21 . V_22 ) ;
F_19 ( & V_49 -> V_21 . V_22 ) ;
}
static void F_20 ( struct V_5 * V_5 )
{
struct V_50 * V_51 = F_21 ( V_5 ,
struct V_50 , V_5 ) ;
F_22 ( V_51 ) ;
}
static int F_23 ( struct V_5 * V_5 )
{
struct V_50 * V_51 = F_21 ( V_5 ,
struct V_50 , V_5 ) ;
F_24 ( & V_51 -> V_52 ) ;
return 0 ;
}
static int F_25 ( struct V_5 * V_5 )
{
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
int F_29 ( void )
{
V_53 = F_30 ( L_38 , V_54 , 0 ) ;
if ( ! V_53 ) {
F_8 ( L_39 ) ;
return - V_55 ;
}
memset ( & V_56 , 0 , sizeof( struct V_57 ) ) ;
F_31 ( & V_56 . V_58 ) ;
F_31 ( & V_56 . V_59 ) ;
F_31 ( & V_56 . V_60 ) ;
V_56 . V_61 = & V_62 ;
memset ( & V_63 , 0 , sizeof( struct V_64 ) ) ;
F_31 ( & V_63 . V_65 ) ;
F_31 ( & V_63 . V_66 ) ;
memset ( & V_67 , 0 , sizeof( struct V_68 ) ) ;
F_31 ( & V_67 . V_69 ) ;
F_31 ( & V_67 . V_70 ) ;
F_31 ( & V_67 . V_71 ) ;
F_32 ( & V_67 . V_72 ) ;
V_63 . V_73 = & V_56 ;
V_63 . V_74 = & V_67 ;
V_67 . V_73 = & V_56 ;
V_67 . V_64 = & V_63 ;
return 0 ;
}
void F_33 ( void )
{
if ( V_53 )
F_34 ( V_53 ) ;
}
static void F_35 (
struct V_50 * V_51 ,
struct V_6 * V_7 ,
bool V_75 )
{
struct V_5 * V_76 = V_7 -> V_77 ;
struct V_5 * V_78 = & V_51 -> V_5 ;
if ( V_7 -> V_29 == V_30 ) {
if ( V_75 ) {
V_51 -> V_75 = V_75 ;
} else {
V_78 -> V_79 = V_76 -> V_79 ;
V_78 -> V_9 = V_76 -> V_9 ;
F_6 ( L_40
L_41 , V_78 -> V_9 ) ;
V_78 -> V_79 = V_76 -> V_79 ;
F_6 ( L_42 ,
V_78 -> V_79 ) ;
}
} else {
if ( V_75 ) {
V_51 -> V_75 = V_75 ;
} else {
V_78 -> V_79 = V_76 -> V_79 ;
V_78 -> V_9 = V_76 -> V_9 ;
F_6 ( L_43
L_41 , V_78 -> V_9 ) ;
V_78 -> V_79 = V_76 -> V_79 ;
F_6 ( L_44 ,
V_78 -> V_79 ) ;
}
}
}
static void F_36 ( struct V_1 * V_9 ,
struct V_5 * V_78 , bool V_75 )
{
if ( V_75 ) {
F_6 ( L_45 ,
V_78 -> V_9 ) ;
V_78 -> V_79 = & V_9 -> V_80 ;
V_78 -> V_9 = V_9 ;
}
V_78 -> V_81 |= V_82 ;
}
static int F_37 (
struct V_50 * V_51 ,
struct V_6 * V_7 ,
struct V_1 * V_9 ,
unsigned char * V_83 ,
bool V_75 ,
bool V_84 )
{
struct V_5 * V_85 = & V_51 -> V_5 ;
T_2 V_86 ;
int V_36 = 0 , V_13 ;
F_36 ( V_9 , V_85 , V_75 ) ;
V_51 -> V_6 = V_7 ;
F_35 ( V_51 , V_7 , V_75 ) ;
V_85 -> V_87 = 0 ;
V_86 = F_38 ( V_85 , V_83 ) ;
if ( V_86 ) {
V_36 = - V_23 ;
goto V_38;
}
if ( V_84 ) {
V_13 = F_39 ( & V_85 -> V_88 , & V_85 -> V_89 ,
V_85 -> V_90 , false , false ) ;
if ( V_13 < 0 ) {
V_36 = V_13 ;
goto V_38;
}
V_85 -> V_81 |= V_91 ;
} else {
V_86 = F_40 ( V_85 ,
V_7 -> V_92 , V_7 -> V_93 ,
NULL , 0 ) ;
if ( V_86 ) {
V_36 = - V_23 ;
goto V_38;
}
F_6 ( L_46
L_47 , V_85 -> V_88 , V_85 -> V_89 ) ;
}
return 0 ;
V_38:
return V_36 ;
}
static int F_41 ( struct V_50 * V_51 )
{
struct V_5 * V_5 = & V_51 -> V_5 ;
T_2 V_86 ;
V_86 = F_42 ( V_5 ) ;
if ( V_86 )
return - V_23 ;
if ( V_5 -> V_94 == V_95 )
F_43 ( V_5 ) ;
F_44 ( & V_51 -> V_52 ) ;
F_6 ( L_48 ,
V_5 -> V_96 ) ;
return ( V_5 -> V_96 ) ? - V_23 : 0 ;
}
static int F_45 (
struct V_5 * V_76 ,
struct V_6 * V_7 ,
struct V_1 * V_20 ,
T_3 V_44 ,
T_4 V_97 )
{
struct V_50 * V_51 ;
struct V_5 * V_5 ;
T_4 V_98 = ( V_97 * V_20 -> V_17 . V_99 ) ;
int V_13 ;
unsigned char V_83 [ 16 ] ;
bool V_75 = ( V_7 -> V_29 == V_31 ) ;
V_51 = F_46 ( sizeof( struct V_50 ) , V_100 ) ;
if ( ! V_51 ) {
F_8 ( L_49 ) ;
return - V_55 ;
}
F_47 ( & V_51 -> V_52 ) ;
V_5 = & V_51 -> V_5 ;
memset ( & V_83 [ 0 ] , 0 , 16 ) ;
V_83 [ 0 ] = V_101 ;
F_48 ( V_44 , & V_83 [ 2 ] ) ;
F_49 ( V_97 , & V_83 [ 10 ] ) ;
F_6 ( L_50 ,
( unsigned long long ) V_44 , V_97 , V_98 ) ;
F_50 ( V_5 , & V_62 , & V_67 , V_98 ,
V_102 , 0 , & V_51 -> V_103 [ 0 ] ) ;
V_7 -> V_104 = V_51 ;
V_13 = F_37 ( V_51 , V_7 , V_20 , & V_83 [ 0 ] ,
V_75 , true ) ;
if ( V_13 < 0 ) {
F_51 ( V_5 , 0 ) ;
return V_13 ;
}
V_7 -> V_92 = V_5 -> V_88 ;
V_7 -> V_93 = V_5 -> V_89 ;
F_6 ( L_51
L_52 , V_7 -> V_92 , V_7 -> V_93 ) ;
V_13 = F_41 ( V_51 ) ;
if ( V_13 < 0 ) {
F_51 ( V_5 , 0 ) ;
return V_13 ;
}
V_5 -> V_88 = NULL ;
V_5 -> V_89 = 0 ;
return 0 ;
}
static int F_52 (
struct V_5 * V_76 ,
struct V_6 * V_7 ,
struct V_1 * V_19 ,
T_3 V_45 ,
T_4 V_105 )
{
struct V_50 * V_51 ;
struct V_5 * V_5 ;
T_4 V_98 = ( V_105 * V_19 -> V_17 . V_99 ) ;
int V_13 ;
unsigned char V_83 [ 16 ] ;
bool V_75 = ( V_7 -> V_29 == V_30 ) ;
V_51 = F_46 ( sizeof( struct V_50 ) , V_100 ) ;
if ( ! V_51 ) {
F_8 ( L_49 ) ;
return - V_55 ;
}
F_47 ( & V_51 -> V_52 ) ;
V_5 = & V_51 -> V_5 ;
memset ( & V_83 [ 0 ] , 0 , 16 ) ;
V_83 [ 0 ] = V_106 ;
F_48 ( V_45 , & V_83 [ 2 ] ) ;
F_49 ( V_105 , & V_83 [ 10 ] ) ;
F_6 ( L_53 ,
( unsigned long long ) V_45 , V_105 , V_98 ) ;
F_50 ( V_5 , & V_62 , & V_67 , V_98 ,
V_95 , 0 , & V_51 -> V_103 [ 0 ] ) ;
V_7 -> V_107 = V_51 ;
V_13 = F_37 ( V_51 , V_7 , V_19 , & V_83 [ 0 ] ,
V_75 , false ) ;
if ( V_13 < 0 ) {
struct V_5 * V_108 = & V_7 -> V_104 -> V_5 ;
V_108 -> V_81 &= ~ V_91 ;
V_108 -> V_88 = V_7 -> V_92 ;
V_108 -> V_89 = V_7 -> V_93 ;
F_51 ( V_5 , 0 ) ;
return V_13 ;
}
V_13 = F_41 ( V_51 ) ;
if ( V_13 < 0 ) {
V_5 -> V_81 &= ~ V_91 ;
F_51 ( V_5 , 0 ) ;
return V_13 ;
}
return 0 ;
}
static void F_53 ( struct V_109 * V_110 )
{
struct V_6 * V_7 = F_21 ( V_110 , struct V_6 , V_111 ) ;
struct V_1 * V_20 = V_7 -> V_20 , * V_19 = V_7 -> V_19 ;
struct V_5 * V_76 = V_7 -> V_77 ;
T_3 V_44 = V_7 -> V_44 , V_45 = V_7 -> V_45 , V_112 ;
unsigned int V_113 ;
int V_13 ;
unsigned short V_43 = V_7 -> V_43 , V_114 , V_115 , V_116 = 0 ;
V_112 = V_44 + V_43 ;
V_113 = F_54 ( V_20 -> V_17 . V_117 ,
V_19 -> V_17 . V_117 ) ;
V_113 = F_55 ( T_4 , V_113 , V_118 ) ;
V_115 = F_55 ( V_119 , V_113 , ( ( V_119 ) ( ~ 0U ) ) ) ;
F_6 ( L_54 ,
V_43 , V_115 , ( unsigned long long ) V_112 ) ;
F_6 ( L_55 ,
( unsigned long long ) V_44 , ( unsigned long long ) V_45 ) ;
while ( V_44 < V_112 ) {
V_114 = F_54 ( V_43 , V_115 ) ;
F_6 ( L_56
L_57 , V_20 , ( unsigned long long ) V_44 , V_114 ) ;
V_13 = F_45 ( V_76 , V_7 , V_20 , V_44 , V_114 ) ;
if ( V_13 < 0 )
goto V_38;
V_44 += V_114 ;
F_6 ( L_58 ,
( unsigned long long ) V_44 ) ;
F_6 ( L_59
L_57 , V_19 , ( unsigned long long ) V_45 , V_114 ) ;
V_13 = F_52 ( V_76 , V_7 , V_19 ,
V_45 , V_114 ) ;
if ( V_13 < 0 ) {
F_51 ( & V_7 -> V_104 -> V_5 , 0 ) ;
goto V_38;
}
V_45 += V_114 ;
F_6 ( L_60 ,
( unsigned long long ) V_45 ) ;
V_116 += V_114 ;
V_43 -= V_114 ;
F_51 ( & V_7 -> V_104 -> V_5 , 0 ) ;
V_7 -> V_107 -> V_5 . V_81 &= ~ V_91 ;
F_51 ( & V_7 -> V_107 -> V_5 , 0 ) ;
}
F_18 ( V_7 ) ;
F_22 ( V_7 ) ;
F_6 ( L_61 ,
( unsigned long long ) V_44 , ( unsigned long long ) V_45 ) ;
F_6 ( L_62 ,
V_116 , V_116 * V_19 -> V_17 . V_99 ) ;
F_6 ( L_63 ) ;
F_56 ( V_76 , V_120 ) ;
return;
V_38:
F_18 ( V_7 ) ;
F_22 ( V_7 ) ;
F_57 ( L_64 ) ;
V_76 -> V_96 = V_121 ;
F_56 ( V_76 , V_121 ) ;
}
T_2 F_58 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_9 ;
struct V_6 * V_7 = NULL ;
unsigned char * V_24 = NULL , * V_122 ;
unsigned int V_123 , V_124 , V_47 , V_125 , V_126 ;
T_2 V_36 = V_127 ;
int V_13 ;
unsigned short V_32 ;
if ( ! V_2 -> V_17 . V_18 ) {
F_8 ( L_65 ) ;
return V_128 ;
}
V_126 = V_5 -> V_129 [ 1 ] & 0x1f ;
if ( V_126 != 0x00 ) {
F_8 ( L_66 ) ;
return V_128 ;
}
V_7 = F_46 ( sizeof( struct V_6 ) , V_100 ) ;
if ( ! V_7 ) {
F_8 ( L_67 ) ;
return V_130 ;
}
V_7 -> V_77 = V_5 ;
V_24 = F_59 ( V_5 ) ;
if ( ! V_24 ) {
F_8 ( L_68 ) ;
F_22 ( V_7 ) ;
return V_130 ;
}
V_123 = V_24 [ 0 ] ;
V_124 = ( V_24 [ 1 ] & 0x18 ) >> 3 ;
V_32 = F_11 ( & V_24 [ 2 ] ) ;
V_47 = F_60 ( & V_24 [ 8 ] ) ;
V_125 = F_60 ( & V_24 [ 12 ] ) ;
if ( V_125 != 0 ) {
F_8 ( L_69 ) ;
goto V_38;
}
F_6 ( L_70
L_71 , V_123 , V_124 ,
V_32 , V_47 , V_125 ) ;
V_13 = F_12 ( V_5 , V_7 , & V_24 [ 16 ] , V_32 ) ;
if ( V_13 <= 0 )
goto V_38;
if ( V_7 -> V_20 -> V_17 . V_99 !=
V_7 -> V_19 -> V_17 . V_99 ) {
F_8 ( L_72
L_73 ,
V_7 -> V_20 -> V_17 . V_99 ,
V_7 -> V_19 -> V_17 . V_99 ) ;
F_18 ( V_7 ) ;
V_36 = V_131 ;
goto V_38;
}
F_6 ( L_74 , V_13 ,
V_13 * V_35 ) ;
V_122 = & V_24 [ 16 ] ;
V_122 += ( V_13 * V_35 ) ;
V_13 = F_15 ( V_5 , V_7 , V_122 , V_47 ) ;
if ( V_13 <= 0 ) {
F_18 ( V_7 ) ;
goto V_38;
}
F_61 ( V_5 ) ;
F_6 ( L_75 , V_13 ,
V_13 * V_48 ) ;
F_62 ( & V_7 -> V_111 , F_53 ) ;
F_63 ( V_53 , & V_7 -> V_111 ) ;
return V_132 ;
V_38:
if ( V_24 )
F_61 ( V_5 ) ;
F_22 ( V_7 ) ;
return V_36 ;
}
static T_2 F_64 ( struct V_5 * V_5 )
{
unsigned char * V_24 ;
V_24 = F_59 ( V_5 ) ;
if ( ! V_24 ) {
F_8 ( L_76
L_77 ) ;
return V_130 ;
}
if ( V_5 -> V_90 < 54 ) {
F_8 ( L_78
L_79 , V_5 -> V_90 ) ;
F_61 ( V_5 ) ;
return V_133 ;
}
V_24 [ 4 ] = 0x1 ;
F_65 ( V_134 , & V_24 [ 8 ] ) ;
F_65 ( V_135 , & V_24 [ 10 ] ) ;
F_49 ( V_136 , & V_24 [ 12 ] ) ;
F_49 ( V_137 , & V_24 [ 16 ] ) ;
F_49 ( 0x0 , & V_24 [ 20 ] ) ;
F_49 ( 0x0 , & V_24 [ 24 ] ) ;
F_49 ( 0x0 , & V_24 [ 28 ] ) ;
F_65 ( V_138 , & V_24 [ 34 ] ) ;
V_24 [ 36 ] = V_139 ;
V_24 [ 37 ] = V_140 ;
V_24 [ 38 ] = V_141 ;
V_24 [ 39 ] = V_142 ;
V_24 [ 43 ] = 0x2 ;
V_24 [ 44 ] = 0x02 ;
V_24 [ 45 ] = 0xe4 ;
F_49 ( 42 , & V_24 [ 0 ] ) ;
F_61 ( V_5 ) ;
F_56 ( V_5 , V_143 ) ;
return V_132 ;
}
T_2 F_66 ( struct V_5 * V_5 )
{
unsigned char * V_83 = & V_5 -> V_129 [ 0 ] ;
int V_126 = ( V_83 [ 1 ] & 0x1f ) , V_123 = V_83 [ 2 ] ;
T_2 V_13 = V_132 ;
F_6 ( L_80
L_81 , V_126 , V_123 , V_5 -> V_90 ) ;
if ( V_123 != 0 ) {
F_8 ( L_82
L_83 ) ;
return V_133 ;
}
switch ( V_126 ) {
case V_144 :
V_13 = F_64 ( V_5 ) ;
break;
case V_145 :
case V_146 :
case V_147 :
default:
F_8 ( L_84 , V_126 ) ;
return V_133 ;
}
return V_13 ;
}
