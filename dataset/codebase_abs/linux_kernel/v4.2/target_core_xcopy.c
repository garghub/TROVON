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
V_63 . V_71 = & V_56 ;
V_63 . V_72 = & V_67 ;
V_67 . V_71 = & V_56 ;
V_67 . V_64 = & V_63 ;
return 0 ;
}
void F_32 ( void )
{
if ( V_53 )
F_33 ( V_53 ) ;
}
static void F_34 (
struct V_50 * V_51 ,
struct V_6 * V_7 ,
bool V_73 )
{
struct V_5 * V_74 = V_7 -> V_75 ;
struct V_5 * V_76 = & V_51 -> V_5 ;
if ( V_7 -> V_29 == V_30 ) {
if ( V_73 ) {
V_51 -> V_73 = V_73 ;
} else {
V_76 -> V_77 = V_74 -> V_77 ;
V_76 -> V_9 = V_74 -> V_9 ;
F_6 ( L_40
L_41 , V_76 -> V_9 ) ;
V_76 -> V_77 = V_74 -> V_77 ;
F_6 ( L_42 ,
V_76 -> V_77 ) ;
}
} else {
if ( V_73 ) {
V_51 -> V_73 = V_73 ;
} else {
V_76 -> V_77 = V_74 -> V_77 ;
V_76 -> V_9 = V_74 -> V_9 ;
F_6 ( L_43
L_41 , V_76 -> V_9 ) ;
V_76 -> V_77 = V_74 -> V_77 ;
F_6 ( L_44 ,
V_76 -> V_77 ) ;
}
}
}
static void F_35 ( struct V_1 * V_9 ,
struct V_5 * V_76 , bool V_73 )
{
if ( V_73 ) {
F_6 ( L_45 ,
V_76 -> V_9 ) ;
V_76 -> V_77 = & V_9 -> V_78 ;
V_76 -> V_9 = V_9 ;
}
V_76 -> V_79 |= V_80 ;
}
static int F_36 (
struct V_50 * V_51 ,
struct V_6 * V_7 ,
struct V_1 * V_9 ,
unsigned char * V_81 ,
bool V_73 ,
bool V_82 )
{
struct V_5 * V_83 = & V_51 -> V_5 ;
T_2 V_84 ;
int V_36 = 0 , V_13 ;
F_35 ( V_9 , V_83 , V_73 ) ;
V_51 -> V_6 = V_7 ;
F_34 ( V_51 , V_7 , V_73 ) ;
V_83 -> V_85 = 0 ;
V_84 = F_37 ( V_83 , V_81 ) ;
if ( V_84 ) {
V_36 = - V_23 ;
goto V_38;
}
if ( V_82 ) {
V_13 = F_38 ( & V_83 -> V_86 , & V_83 -> V_87 ,
V_83 -> V_88 , false ) ;
if ( V_13 < 0 ) {
V_36 = V_13 ;
goto V_38;
}
V_83 -> V_79 |= V_89 ;
} else {
V_84 = F_39 ( V_83 ,
V_7 -> V_90 , V_7 -> V_91 ,
NULL , 0 ) ;
if ( V_84 ) {
V_36 = - V_23 ;
goto V_38;
}
F_6 ( L_46
L_47 , V_83 -> V_86 , V_83 -> V_87 ) ;
}
return 0 ;
V_38:
return V_36 ;
}
static int F_40 ( struct V_50 * V_51 )
{
struct V_5 * V_5 = & V_51 -> V_5 ;
T_2 V_84 ;
V_84 = F_41 ( V_5 ) ;
if ( V_84 )
return - V_23 ;
if ( V_5 -> V_92 == V_93 )
F_42 ( V_5 ) ;
F_43 ( & V_51 -> V_52 ) ;
F_6 ( L_48 ,
V_5 -> V_94 ) ;
return ( V_5 -> V_94 ) ? - V_23 : 0 ;
}
static int F_44 (
struct V_5 * V_74 ,
struct V_6 * V_7 ,
struct V_1 * V_20 ,
T_3 V_44 ,
T_4 V_95 )
{
struct V_50 * V_51 ;
struct V_5 * V_5 ;
T_4 V_96 = ( V_95 * V_20 -> V_17 . V_97 ) ;
int V_13 ;
unsigned char V_81 [ 16 ] ;
bool V_73 = ( V_7 -> V_29 == V_31 ) ;
V_51 = F_45 ( sizeof( struct V_50 ) , V_98 ) ;
if ( ! V_51 ) {
F_8 ( L_49 ) ;
return - V_55 ;
}
F_46 ( & V_51 -> V_52 ) ;
V_5 = & V_51 -> V_5 ;
memset ( & V_81 [ 0 ] , 0 , 16 ) ;
V_81 [ 0 ] = V_99 ;
F_47 ( V_44 , & V_81 [ 2 ] ) ;
F_48 ( V_95 , & V_81 [ 10 ] ) ;
F_6 ( L_50 ,
( unsigned long long ) V_44 , V_95 , V_96 ) ;
F_49 ( V_5 , & V_62 , NULL , V_96 ,
V_100 , 0 , & V_51 -> V_101 [ 0 ] ) ;
V_7 -> V_102 = V_51 ;
V_13 = F_36 ( V_51 , V_7 , V_20 , & V_81 [ 0 ] ,
V_73 , true ) ;
if ( V_13 < 0 ) {
F_50 ( V_5 , 0 ) ;
return V_13 ;
}
V_7 -> V_90 = V_5 -> V_86 ;
V_7 -> V_91 = V_5 -> V_87 ;
F_6 ( L_51
L_52 , V_7 -> V_90 , V_7 -> V_91 ) ;
V_13 = F_40 ( V_51 ) ;
if ( V_13 < 0 ) {
F_50 ( V_5 , 0 ) ;
return V_13 ;
}
V_5 -> V_86 = NULL ;
V_5 -> V_87 = 0 ;
return 0 ;
}
static int F_51 (
struct V_5 * V_74 ,
struct V_6 * V_7 ,
struct V_1 * V_19 ,
T_3 V_45 ,
T_4 V_103 )
{
struct V_50 * V_51 ;
struct V_5 * V_5 ;
T_4 V_96 = ( V_103 * V_19 -> V_17 . V_97 ) ;
int V_13 ;
unsigned char V_81 [ 16 ] ;
bool V_73 = ( V_7 -> V_29 == V_30 ) ;
V_51 = F_45 ( sizeof( struct V_50 ) , V_98 ) ;
if ( ! V_51 ) {
F_8 ( L_49 ) ;
return - V_55 ;
}
F_46 ( & V_51 -> V_52 ) ;
V_5 = & V_51 -> V_5 ;
memset ( & V_81 [ 0 ] , 0 , 16 ) ;
V_81 [ 0 ] = V_104 ;
F_47 ( V_45 , & V_81 [ 2 ] ) ;
F_48 ( V_103 , & V_81 [ 10 ] ) ;
F_6 ( L_53 ,
( unsigned long long ) V_45 , V_103 , V_96 ) ;
F_49 ( V_5 , & V_62 , NULL , V_96 ,
V_93 , 0 , & V_51 -> V_101 [ 0 ] ) ;
V_7 -> V_105 = V_51 ;
V_13 = F_36 ( V_51 , V_7 , V_19 , & V_81 [ 0 ] ,
V_73 , false ) ;
if ( V_13 < 0 ) {
struct V_5 * V_106 = & V_7 -> V_102 -> V_5 ;
V_106 -> V_79 &= ~ V_89 ;
V_106 -> V_86 = V_7 -> V_90 ;
V_106 -> V_87 = V_7 -> V_91 ;
F_50 ( V_5 , 0 ) ;
return V_13 ;
}
V_13 = F_40 ( V_51 ) ;
if ( V_13 < 0 ) {
V_5 -> V_79 &= ~ V_89 ;
F_50 ( V_5 , 0 ) ;
return V_13 ;
}
return 0 ;
}
static void F_52 ( struct V_107 * V_108 )
{
struct V_6 * V_7 = F_21 ( V_108 , struct V_6 , V_109 ) ;
struct V_1 * V_20 = V_7 -> V_20 , * V_19 = V_7 -> V_19 ;
struct V_5 * V_74 = V_7 -> V_75 ;
T_3 V_44 = V_7 -> V_44 , V_45 = V_7 -> V_45 , V_110 ;
unsigned int V_111 ;
int V_13 ;
unsigned short V_43 = V_7 -> V_43 , V_112 , V_113 , V_114 = 0 ;
V_110 = V_44 + V_43 ;
V_111 = F_53 ( V_20 -> V_17 . V_115 ,
V_19 -> V_17 . V_115 ) ;
V_111 = F_54 ( T_4 , V_111 , V_116 ) ;
V_113 = F_54 ( V_117 , V_111 , ( ( V_117 ) ( ~ 0U ) ) ) ;
F_6 ( L_54 ,
V_43 , V_113 , ( unsigned long long ) V_110 ) ;
F_6 ( L_55 ,
( unsigned long long ) V_44 , ( unsigned long long ) V_45 ) ;
while ( V_44 < V_110 ) {
V_112 = F_53 ( V_43 , V_113 ) ;
F_6 ( L_56
L_57 , V_20 , ( unsigned long long ) V_44 , V_112 ) ;
V_13 = F_44 ( V_74 , V_7 , V_20 , V_44 , V_112 ) ;
if ( V_13 < 0 )
goto V_38;
V_44 += V_112 ;
F_6 ( L_58 ,
( unsigned long long ) V_44 ) ;
F_6 ( L_59
L_57 , V_19 , ( unsigned long long ) V_45 , V_112 ) ;
V_13 = F_51 ( V_74 , V_7 , V_19 ,
V_45 , V_112 ) ;
if ( V_13 < 0 ) {
F_50 ( & V_7 -> V_102 -> V_5 , 0 ) ;
goto V_38;
}
V_45 += V_112 ;
F_6 ( L_60 ,
( unsigned long long ) V_45 ) ;
V_114 += V_112 ;
V_43 -= V_112 ;
F_50 ( & V_7 -> V_102 -> V_5 , 0 ) ;
V_7 -> V_105 -> V_5 . V_79 &= ~ V_89 ;
F_50 ( & V_7 -> V_105 -> V_5 , 0 ) ;
}
F_18 ( V_7 ) ;
F_22 ( V_7 ) ;
F_6 ( L_61 ,
( unsigned long long ) V_44 , ( unsigned long long ) V_45 ) ;
F_6 ( L_62 ,
V_114 , V_114 * V_19 -> V_17 . V_97 ) ;
F_6 ( L_63 ) ;
F_55 ( V_74 , V_118 ) ;
return;
V_38:
F_18 ( V_7 ) ;
F_22 ( V_7 ) ;
F_56 ( L_64 ) ;
V_74 -> V_94 = V_119 ;
F_55 ( V_74 , V_119 ) ;
}
T_2 F_57 ( struct V_5 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_9 ;
struct V_6 * V_7 = NULL ;
unsigned char * V_24 = NULL , * V_120 ;
unsigned int V_121 , V_122 , V_47 , V_123 , V_124 ;
T_2 V_36 = V_125 ;
int V_13 ;
unsigned short V_32 ;
if ( ! V_2 -> V_17 . V_18 ) {
F_8 ( L_65 ) ;
return V_126 ;
}
V_124 = V_5 -> V_127 [ 1 ] & 0x1f ;
if ( V_124 != 0x00 ) {
F_8 ( L_66 ) ;
return V_126 ;
}
V_7 = F_45 ( sizeof( struct V_6 ) , V_98 ) ;
if ( ! V_7 ) {
F_8 ( L_67 ) ;
return V_128 ;
}
V_7 -> V_75 = V_5 ;
V_24 = F_58 ( V_5 ) ;
if ( ! V_24 ) {
F_8 ( L_68 ) ;
F_22 ( V_7 ) ;
return V_128 ;
}
V_121 = V_24 [ 0 ] ;
V_122 = ( V_24 [ 1 ] & 0x18 ) >> 3 ;
V_32 = F_11 ( & V_24 [ 2 ] ) ;
V_47 = F_59 ( & V_24 [ 8 ] ) ;
V_123 = F_59 ( & V_24 [ 12 ] ) ;
if ( V_123 != 0 ) {
F_8 ( L_69 ) ;
goto V_38;
}
F_6 ( L_70
L_71 , V_121 , V_122 ,
V_32 , V_47 , V_123 ) ;
V_13 = F_12 ( V_5 , V_7 , & V_24 [ 16 ] , V_32 ) ;
if ( V_13 <= 0 )
goto V_38;
if ( V_7 -> V_20 -> V_17 . V_97 !=
V_7 -> V_19 -> V_17 . V_97 ) {
F_8 ( L_72
L_73 ,
V_7 -> V_20 -> V_17 . V_97 ,
V_7 -> V_19 -> V_17 . V_97 ) ;
F_18 ( V_7 ) ;
V_36 = V_129 ;
goto V_38;
}
F_6 ( L_74 , V_13 ,
V_13 * V_35 ) ;
V_120 = & V_24 [ 16 ] ;
V_120 += ( V_13 * V_35 ) ;
V_13 = F_15 ( V_5 , V_7 , V_120 , V_47 ) ;
if ( V_13 <= 0 ) {
F_18 ( V_7 ) ;
goto V_38;
}
F_60 ( V_5 ) ;
F_6 ( L_75 , V_13 ,
V_13 * V_48 ) ;
F_61 ( & V_7 -> V_109 , F_52 ) ;
F_62 ( V_53 , & V_7 -> V_109 ) ;
return V_130 ;
V_38:
if ( V_24 )
F_60 ( V_5 ) ;
F_22 ( V_7 ) ;
return V_36 ;
}
static T_2 F_63 ( struct V_5 * V_5 )
{
unsigned char * V_24 ;
V_24 = F_58 ( V_5 ) ;
if ( ! V_24 ) {
F_8 ( L_76
L_77 ) ;
return V_128 ;
}
if ( V_5 -> V_88 < 54 ) {
F_8 ( L_78
L_79 , V_5 -> V_88 ) ;
F_60 ( V_5 ) ;
return V_131 ;
}
V_24 [ 4 ] = 0x1 ;
F_64 ( V_132 , & V_24 [ 8 ] ) ;
F_64 ( V_133 , & V_24 [ 10 ] ) ;
F_48 ( V_134 , & V_24 [ 12 ] ) ;
F_48 ( V_135 , & V_24 [ 16 ] ) ;
F_48 ( 0x0 , & V_24 [ 20 ] ) ;
F_48 ( 0x0 , & V_24 [ 24 ] ) ;
F_48 ( 0x0 , & V_24 [ 28 ] ) ;
F_64 ( V_136 , & V_24 [ 34 ] ) ;
V_24 [ 36 ] = V_137 ;
V_24 [ 37 ] = V_138 ;
V_24 [ 38 ] = V_139 ;
V_24 [ 39 ] = V_140 ;
V_24 [ 43 ] = 0x2 ;
V_24 [ 44 ] = 0x02 ;
V_24 [ 45 ] = 0xe4 ;
F_48 ( 42 , & V_24 [ 0 ] ) ;
F_60 ( V_5 ) ;
F_55 ( V_5 , V_141 ) ;
return V_130 ;
}
T_2 F_65 ( struct V_5 * V_5 )
{
unsigned char * V_81 = & V_5 -> V_127 [ 0 ] ;
int V_124 = ( V_81 [ 1 ] & 0x1f ) , V_121 = V_81 [ 2 ] ;
T_2 V_13 = V_130 ;
F_6 ( L_80
L_81 , V_124 , V_121 , V_5 -> V_88 ) ;
if ( V_121 != 0 ) {
F_8 ( L_82
L_83 ) ;
return V_131 ;
}
switch ( V_124 ) {
case V_142 :
V_13 = F_63 ( V_5 ) ;
break;
case V_143 :
case V_144 :
case V_145 :
default:
F_8 ( L_84 , V_124 ) ;
return V_131 ;
}
return V_13 ;
}
