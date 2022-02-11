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
static int F_3 ( struct V_1 * V_5 ,
void * V_6 )
{
struct V_7 * V_8 = V_6 ;
unsigned char V_9 [ V_10 ] ;
int V_11 ;
if ( ! V_5 -> V_12 . V_13 )
return 0 ;
memset ( & V_9 [ 0 ] , 0 , V_10 ) ;
F_1 ( V_5 , & V_9 [ 0 ] ) ;
V_11 = memcmp ( & V_9 [ 0 ] , V_8 -> V_14 , V_10 ) ;
if ( V_11 != 0 )
return 0 ;
V_8 -> V_15 = V_5 ;
F_4 ( L_1 , V_5 ) ;
V_11 = F_5 ( & V_5 -> V_16 . V_17 ) ;
if ( V_11 != 0 ) {
F_6 ( L_2 ,
V_11 , V_5 ) ;
return V_11 ;
}
F_4 ( L_3 ,
V_5 , & V_5 -> V_16 ) ;
return 1 ;
}
static int F_7 ( const unsigned char * V_14 ,
struct V_1 * * V_15 )
{
struct V_7 V_8 ;
int V_18 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_14 = V_14 ;
V_18 = F_8 ( F_3 , & V_8 ) ;
if ( V_18 == 1 ) {
* V_15 = V_8 . V_15 ;
return 0 ;
} else {
F_9 ( L_4 ) ;
return - V_19 ;
}
}
static int F_10 ( struct V_20 * V_20 , struct V_21 * V_22 ,
unsigned char * V_23 , unsigned short V_24 )
{
unsigned char * V_25 = V_23 ;
unsigned short V_26 ;
T_1 V_27 ;
V_26 = F_11 ( & V_25 [ 2 ] ) ;
F_4 ( L_5 , V_26 ) ;
if ( ( V_25 [ 4 ] & 0x0f ) != 0x1 ) {
F_6 ( L_6 ) ;
return - V_19 ;
}
if ( ( V_25 [ 5 ] & 0x30 ) != 0x00 ) {
F_6 ( L_7 ) ;
return - V_19 ;
}
if ( ( V_25 [ 5 ] & 0x0f ) != 0x3 ) {
F_6 ( L_8 ,
( V_25 [ 5 ] & 0x0f ) ) ;
return - V_19 ;
}
V_27 = V_25 [ 7 ] ;
if ( V_27 != 16 ) {
F_6 ( L_9 , ( int ) V_27 ) ;
return - V_19 ;
}
F_4 ( L_10 , ( int ) V_27 ) ;
if ( ( V_25 [ 8 ] & 0xf0 ) != 0x60 ) {
F_6 ( L_11 ,
( V_25 [ 8 ] & 0xf0 ) ) ;
return - V_19 ;
}
if ( V_24 != V_22 -> V_28 && V_24 != V_22 -> V_29 ) {
F_4 ( L_12
L_13 , V_24 ) ;
return 0 ;
}
if ( V_24 == V_22 -> V_28 ) {
memcpy ( & V_22 -> V_30 [ 0 ] , & V_25 [ 8 ] , V_10 ) ;
if ( ! memcmp ( & V_22 -> V_31 [ 0 ] , & V_22 -> V_30 [ 0 ] ,
V_10 ) ) {
V_22 -> V_32 = V_33 ;
V_22 -> V_34 = V_20 -> V_5 ;
F_4 ( L_14
L_15 , V_22 -> V_34 ) ;
}
}
if ( V_24 == V_22 -> V_29 ) {
memcpy ( & V_22 -> V_35 [ 0 ] , & V_25 [ 8 ] , V_10 ) ;
if ( ! memcmp ( & V_22 -> V_31 [ 0 ] , & V_22 -> V_35 [ 0 ] ,
V_10 ) ) {
V_22 -> V_32 = V_36 ;
V_22 -> V_37 = V_20 -> V_5 ;
F_4 ( L_16
L_15 , V_22 -> V_37 ) ;
}
}
return 0 ;
}
static int F_12 ( struct V_20 * V_20 ,
struct V_21 * V_22 , unsigned char * V_23 ,
unsigned short V_38 , T_2 * V_39 )
{
struct V_1 * V_40 = V_20 -> V_5 ;
unsigned char * V_25 = V_23 ;
int V_41 = V_38 % V_42 , V_11 ;
unsigned short V_24 = 0 ;
unsigned short V_43 = 0 ;
* V_39 = V_44 ;
if ( V_41 != 0 ) {
F_6 ( L_17
L_18 , V_42 ) ;
* V_39 = V_45 ;
return - V_19 ;
}
if ( V_38 > V_46 * V_42 ) {
F_6 ( L_19
L_20 , V_38 ) ;
* V_39 = V_47 ;
return - V_19 ;
}
memset ( & V_22 -> V_31 [ 0 ] , 0 , V_10 ) ;
F_1 ( V_40 , & V_22 -> V_31 [ 0 ] ) ;
while ( V_43 < V_38 ) {
switch ( V_25 [ 0 ] ) {
case 0xe4 :
V_11 = F_10 ( V_20 , V_22 ,
& V_25 [ 0 ] , V_24 ) ;
if ( V_11 != 0 )
goto V_48;
V_43 += V_42 ;
V_25 += V_42 ;
V_24 ++ ;
break;
default:
F_6 ( L_21
L_22 , V_25 [ 0 ] ) ;
* V_39 = V_45 ;
goto V_48;
}
}
switch ( V_22 -> V_32 ) {
case V_33 :
V_11 = F_7 ( V_22 -> V_35 ,
& V_22 -> V_37 ) ;
break;
case V_36 :
V_11 = F_7 ( V_22 -> V_30 ,
& V_22 -> V_34 ) ;
break;
default:
F_6 ( L_23
L_24 , V_22 -> V_28 , V_22 -> V_29 ) ;
V_11 = - V_19 ;
break;
}
if ( V_11 < 0 ) {
* V_39 = V_49 ;
goto V_48;
}
F_4 ( L_25 ,
V_22 -> V_34 , & V_22 -> V_30 [ 0 ] ) ;
F_4 ( L_26 ,
V_22 -> V_37 , & V_22 -> V_35 [ 0 ] ) ;
return V_24 ;
V_48:
return - V_19 ;
}
static int F_13 ( struct V_20 * V_20 , struct V_21 * V_22 ,
unsigned char * V_23 )
{
unsigned char * V_25 = V_23 ;
int V_50 = ( V_25 [ 1 ] & 0x02 ) ;
unsigned short V_51 ;
V_51 = F_11 ( & V_25 [ 2 ] ) ;
if ( V_51 != 0x18 ) {
F_6 ( L_27
L_28 , V_51 ) ;
return - V_19 ;
}
V_22 -> V_28 = F_11 ( & V_25 [ 4 ] ) ;
V_22 -> V_29 = F_11 ( & V_25 [ 6 ] ) ;
if ( V_22 -> V_28 > V_52 ||
V_22 -> V_29 > V_52 ) {
F_6 ( L_29 ,
V_52 , V_22 -> V_28 , V_22 -> V_29 ) ;
return - V_19 ;
}
F_4 ( L_30 ,
V_51 , V_22 -> V_28 , V_22 -> V_29 , V_50 ) ;
V_22 -> V_53 = F_11 ( & V_25 [ 10 ] ) ;
V_22 -> V_54 = F_14 ( & V_25 [ 12 ] ) ;
V_22 -> V_55 = F_14 ( & V_25 [ 20 ] ) ;
F_4 ( L_31 ,
V_22 -> V_53 , ( unsigned long long ) V_22 -> V_54 ,
( unsigned long long ) V_22 -> V_55 ) ;
if ( V_50 != 0 ) {
V_22 -> V_56 = F_15 ( & V_25 [ 29 ] ) ;
F_4 ( L_32 , V_22 -> V_56 ) ;
}
return 0 ;
}
static int F_16 ( struct V_20 * V_20 ,
struct V_21 * V_22 , unsigned char * V_23 ,
unsigned int V_57 , T_2 * V_39 )
{
unsigned char * V_25 = V_23 ;
unsigned int V_43 = 0 ;
int V_41 = V_57 % V_58 , V_11 , V_18 = 0 ;
* V_39 = V_44 ;
if ( V_41 != 0 ) {
F_6 ( L_33
L_18 , V_58 ) ;
* V_39 = V_59 ;
return - V_19 ;
}
if ( V_57 > V_60 * V_58 ) {
F_6 ( L_34
L_35 , V_60 , V_57 ) ;
* V_39 = V_61 ;
return - V_19 ;
}
while ( V_43 < V_57 ) {
switch ( V_25 [ 0 ] ) {
case 0x02 :
V_11 = F_13 ( V_20 , V_22 , V_25 ) ;
if ( V_11 < 0 )
goto V_48;
V_18 ++ ;
V_43 += V_58 ;
V_25 += V_58 ;
break;
default:
F_6 ( L_36
L_37 , V_25 [ 0 ] ) ;
* V_39 = V_59 ;
goto V_48;
}
}
return V_18 ;
V_48:
return - V_19 ;
}
static char * F_17 ( void )
{
return L_38 ;
}
static int F_18 ( struct V_20 * V_20 )
{
return 0 ;
}
static void F_19 ( struct V_21 * V_22 )
{
struct V_1 * V_62 ;
if ( V_22 -> V_32 == V_33 )
V_62 = V_22 -> V_37 ;
else
V_62 = V_22 -> V_34 ;
F_4 ( L_39
L_40 ,
V_62 , & V_62 -> V_16 . V_17 ) ;
F_20 ( & V_62 -> V_16 . V_17 ) ;
}
static void F_21 ( struct V_20 * V_20 )
{
struct V_63 * V_64 = F_22 ( V_20 ,
struct V_63 , V_20 ) ;
F_23 ( V_64 ) ;
}
static int F_24 ( struct V_20 * V_20 )
{
struct V_63 * V_64 = F_22 ( V_20 ,
struct V_63 , V_20 ) ;
F_25 ( & V_64 -> V_65 ) ;
return 0 ;
}
static int F_26 ( struct V_20 * V_20 )
{
return 0 ;
}
static int F_27 ( struct V_20 * V_20 )
{
return 0 ;
}
static int F_28 ( struct V_20 * V_20 )
{
return 0 ;
}
static int F_29 ( struct V_20 * V_20 )
{
return 0 ;
}
int F_30 ( void )
{
V_66 = F_31 ( L_41 , V_67 , 0 ) ;
if ( ! V_66 ) {
F_6 ( L_42 ) ;
return - V_68 ;
}
memset ( & V_69 , 0 , sizeof( struct V_70 ) ) ;
F_32 ( & V_69 . V_71 ) ;
F_32 ( & V_69 . V_72 ) ;
F_32 ( & V_69 . V_73 ) ;
V_69 . V_74 = & V_75 ;
memset ( & V_76 , 0 , sizeof( struct V_77 ) ) ;
F_32 ( & V_76 . V_78 ) ;
F_32 ( & V_76 . V_79 ) ;
memset ( & V_80 , 0 , sizeof( struct V_81 ) ) ;
F_32 ( & V_80 . V_82 ) ;
F_32 ( & V_80 . V_83 ) ;
F_32 ( & V_80 . V_84 ) ;
F_33 ( & V_80 . V_85 ) ;
V_76 . V_86 = & V_69 ;
V_76 . V_87 = & V_80 ;
V_80 . V_86 = & V_69 ;
V_80 . V_77 = & V_76 ;
return 0 ;
}
void F_34 ( void )
{
if ( V_66 )
F_35 ( V_66 ) ;
}
static void F_36 (
struct V_63 * V_64 ,
struct V_21 * V_22 ,
bool V_88 )
{
struct V_20 * V_89 = V_22 -> V_90 ;
struct V_20 * V_91 = & V_64 -> V_20 ;
if ( V_22 -> V_32 == V_33 ) {
if ( V_88 ) {
V_64 -> V_88 = V_88 ;
} else {
V_91 -> V_92 = V_89 -> V_92 ;
V_91 -> V_5 = V_89 -> V_5 ;
F_4 ( L_43
L_44 , V_91 -> V_5 ) ;
V_91 -> V_92 = V_89 -> V_92 ;
F_4 ( L_45 ,
V_91 -> V_92 ) ;
}
} else {
if ( V_88 ) {
V_64 -> V_88 = V_88 ;
} else {
V_91 -> V_92 = V_89 -> V_92 ;
V_91 -> V_5 = V_89 -> V_5 ;
F_4 ( L_46
L_44 , V_91 -> V_5 ) ;
V_91 -> V_92 = V_89 -> V_92 ;
F_4 ( L_47 ,
V_91 -> V_92 ) ;
}
}
}
static void F_37 ( struct V_1 * V_5 ,
struct V_20 * V_91 , bool V_88 )
{
if ( V_88 ) {
F_4 ( L_48 ,
V_91 -> V_5 ) ;
V_91 -> V_92 = & V_5 -> V_93 ;
V_91 -> V_5 = V_5 ;
}
V_91 -> V_94 |= V_95 ;
}
static int F_38 (
struct V_63 * V_64 ,
struct V_21 * V_22 ,
struct V_1 * V_5 ,
unsigned char * V_96 ,
bool V_88 ,
bool V_97 )
{
struct V_20 * V_98 = & V_64 -> V_20 ;
T_2 V_99 ;
int V_18 = 0 , V_11 ;
F_37 ( V_5 , V_98 , V_88 ) ;
V_64 -> V_21 = V_22 ;
F_36 ( V_64 , V_22 , V_88 ) ;
V_98 -> V_100 = 0 ;
V_99 = F_39 ( V_98 , V_96 ) ;
if ( V_99 ) {
V_18 = - V_19 ;
goto V_48;
}
if ( V_97 ) {
V_11 = F_40 ( & V_98 -> V_101 , & V_98 -> V_102 ,
V_98 -> V_103 , false , false ) ;
if ( V_11 < 0 ) {
V_18 = V_11 ;
goto V_48;
}
V_98 -> V_94 |= V_104 ;
} else {
V_99 = F_41 ( V_98 ,
V_22 -> V_105 , V_22 -> V_106 ,
NULL , 0 ) ;
if ( V_99 ) {
V_18 = - V_19 ;
goto V_48;
}
F_4 ( L_49
L_50 , V_98 -> V_101 , V_98 -> V_102 ) ;
}
return 0 ;
V_48:
return V_18 ;
}
static int F_42 ( struct V_63 * V_64 )
{
struct V_20 * V_20 = & V_64 -> V_20 ;
T_2 V_99 ;
V_99 = F_43 ( V_20 ) ;
if ( V_99 )
return - V_19 ;
if ( V_20 -> V_107 == V_108 )
F_44 ( V_20 ) ;
F_45 ( & V_64 -> V_65 ) ;
F_4 ( L_51 ,
V_20 -> V_109 ) ;
return ( V_20 -> V_109 ) ? - V_19 : 0 ;
}
static int F_46 (
struct V_20 * V_89 ,
struct V_21 * V_22 ,
struct V_1 * V_34 ,
T_3 V_54 ,
T_4 V_110 )
{
struct V_63 * V_64 ;
struct V_20 * V_20 ;
T_4 V_111 = ( V_110 * V_34 -> V_12 . V_112 ) ;
int V_11 ;
unsigned char V_96 [ 16 ] ;
bool V_88 = ( V_22 -> V_32 == V_36 ) ;
V_64 = F_47 ( sizeof( struct V_63 ) , V_113 ) ;
if ( ! V_64 ) {
F_6 ( L_52 ) ;
return - V_68 ;
}
F_48 ( & V_64 -> V_65 ) ;
V_20 = & V_64 -> V_20 ;
memset ( & V_96 [ 0 ] , 0 , 16 ) ;
V_96 [ 0 ] = V_114 ;
F_49 ( V_54 , & V_96 [ 2 ] ) ;
F_50 ( V_110 , & V_96 [ 10 ] ) ;
F_4 ( L_53 ,
( unsigned long long ) V_54 , V_110 , V_111 ) ;
F_51 ( V_20 , & V_75 , & V_80 , V_111 ,
V_115 , 0 , & V_64 -> V_116 [ 0 ] ) ;
V_22 -> V_117 = V_64 ;
V_11 = F_38 ( V_64 , V_22 , V_34 , & V_96 [ 0 ] ,
V_88 , true ) ;
if ( V_11 < 0 ) {
V_89 -> V_109 = V_64 -> V_20 . V_109 ;
F_52 ( V_20 , 0 ) ;
return V_11 ;
}
V_22 -> V_105 = V_20 -> V_101 ;
V_22 -> V_106 = V_20 -> V_102 ;
F_4 ( L_54
L_55 , V_22 -> V_105 , V_22 -> V_106 ) ;
V_11 = F_42 ( V_64 ) ;
if ( V_11 < 0 ) {
V_89 -> V_109 = V_64 -> V_20 . V_109 ;
F_52 ( V_20 , 0 ) ;
return V_11 ;
}
V_20 -> V_101 = NULL ;
V_20 -> V_102 = 0 ;
return 0 ;
}
static int F_53 (
struct V_20 * V_89 ,
struct V_21 * V_22 ,
struct V_1 * V_37 ,
T_3 V_55 ,
T_4 V_118 )
{
struct V_63 * V_64 ;
struct V_20 * V_20 ;
T_4 V_111 = ( V_118 * V_37 -> V_12 . V_112 ) ;
int V_11 ;
unsigned char V_96 [ 16 ] ;
bool V_88 = ( V_22 -> V_32 == V_33 ) ;
V_64 = F_47 ( sizeof( struct V_63 ) , V_113 ) ;
if ( ! V_64 ) {
F_6 ( L_52 ) ;
return - V_68 ;
}
F_48 ( & V_64 -> V_65 ) ;
V_20 = & V_64 -> V_20 ;
memset ( & V_96 [ 0 ] , 0 , 16 ) ;
V_96 [ 0 ] = V_119 ;
F_49 ( V_55 , & V_96 [ 2 ] ) ;
F_50 ( V_118 , & V_96 [ 10 ] ) ;
F_4 ( L_56 ,
( unsigned long long ) V_55 , V_118 , V_111 ) ;
F_51 ( V_20 , & V_75 , & V_80 , V_111 ,
V_108 , 0 , & V_64 -> V_116 [ 0 ] ) ;
V_22 -> V_120 = V_64 ;
V_11 = F_38 ( V_64 , V_22 , V_37 , & V_96 [ 0 ] ,
V_88 , false ) ;
if ( V_11 < 0 ) {
struct V_20 * V_121 = & V_22 -> V_117 -> V_20 ;
V_89 -> V_109 = V_64 -> V_20 . V_109 ;
V_121 -> V_94 &= ~ V_104 ;
V_121 -> V_101 = V_22 -> V_105 ;
V_121 -> V_102 = V_22 -> V_106 ;
F_52 ( V_20 , 0 ) ;
return V_11 ;
}
V_11 = F_42 ( V_64 ) ;
if ( V_11 < 0 ) {
V_89 -> V_109 = V_64 -> V_20 . V_109 ;
V_20 -> V_94 &= ~ V_104 ;
F_52 ( V_20 , 0 ) ;
return V_11 ;
}
return 0 ;
}
static void F_54 ( struct V_122 * V_123 )
{
struct V_21 * V_22 = F_22 ( V_123 , struct V_21 , V_124 ) ;
struct V_20 * V_89 = V_22 -> V_90 ;
struct V_1 * V_34 , * V_37 ;
T_3 V_54 , V_55 , V_125 ;
unsigned int V_126 ;
int V_11 = 0 ;
unsigned short V_53 , V_127 , V_128 , V_129 = 0 ;
if ( F_55 ( V_22 ) != V_130 )
goto V_131;
if ( F_56 ( ! V_22 -> V_34 ) || F_56 ( ! V_22 -> V_37 ) )
goto V_131;
V_34 = V_22 -> V_34 ;
V_37 = V_22 -> V_37 ;
V_54 = V_22 -> V_54 ;
V_55 = V_22 -> V_55 ;
V_53 = V_22 -> V_53 ;
V_125 = V_54 + V_53 ;
V_126 = F_57 ( V_34 -> V_12 . V_132 ,
V_37 -> V_12 . V_132 ) ;
V_126 = F_58 ( T_4 , V_126 , V_133 ) ;
V_128 = F_58 ( V_134 , V_126 , ( ( V_134 ) ( ~ 0U ) ) ) ;
F_4 ( L_57 ,
V_53 , V_128 , ( unsigned long long ) V_125 ) ;
F_4 ( L_58 ,
( unsigned long long ) V_54 , ( unsigned long long ) V_55 ) ;
while ( V_54 < V_125 ) {
V_127 = F_57 ( V_53 , V_128 ) ;
F_4 ( L_59
L_60 , V_34 , ( unsigned long long ) V_54 , V_127 ) ;
V_11 = F_46 ( V_89 , V_22 , V_34 , V_54 , V_127 ) ;
if ( V_11 < 0 )
goto V_48;
V_54 += V_127 ;
F_4 ( L_61 ,
( unsigned long long ) V_54 ) ;
F_4 ( L_62
L_60 , V_37 , ( unsigned long long ) V_55 , V_127 ) ;
V_11 = F_53 ( V_89 , V_22 , V_37 ,
V_55 , V_127 ) ;
if ( V_11 < 0 ) {
F_52 ( & V_22 -> V_117 -> V_20 , 0 ) ;
goto V_48;
}
V_55 += V_127 ;
F_4 ( L_63 ,
( unsigned long long ) V_55 ) ;
V_129 += V_127 ;
V_53 -= V_127 ;
F_52 ( & V_22 -> V_117 -> V_20 , 0 ) ;
V_22 -> V_120 -> V_20 . V_94 &= ~ V_104 ;
F_52 ( & V_22 -> V_120 -> V_20 , 0 ) ;
}
F_19 ( V_22 ) ;
F_23 ( V_22 ) ;
F_4 ( L_64 ,
( unsigned long long ) V_54 , ( unsigned long long ) V_55 ) ;
F_4 ( L_65 ,
V_129 , V_129 * V_37 -> V_12 . V_112 ) ;
F_4 ( L_66 ) ;
F_59 ( V_89 , V_135 ) ;
return;
V_48:
F_19 ( V_22 ) ;
V_131:
F_23 ( V_22 ) ;
if ( V_89 -> V_109 == V_135 ) {
F_60 ( L_67
L_68 , V_11 ) ;
V_89 -> V_109 = V_136 ;
}
F_59 ( V_89 , V_89 -> V_109 ) ;
}
static T_2 F_55 ( struct V_21 * V_22 )
{
struct V_20 * V_20 = V_22 -> V_90 ;
unsigned char * V_23 = NULL , * V_137 ;
unsigned int V_138 , V_139 , V_57 , V_140 ;
T_2 V_18 = V_44 ;
int V_11 ;
unsigned short V_38 ;
V_23 = F_61 ( V_20 ) ;
if ( ! V_23 ) {
F_6 ( L_69 ) ;
return V_141 ;
}
V_138 = V_23 [ 0 ] ;
V_139 = ( V_23 [ 1 ] & 0x18 ) >> 3 ;
V_38 = F_11 ( & V_23 [ 2 ] ) ;
V_57 = F_62 ( & V_23 [ 8 ] ) ;
if ( V_38 + V_57 > V_142 ) {
F_6 ( L_70 ,
V_38 + V_57 , V_142 ) ;
V_18 = V_143 ;
goto V_48;
}
V_140 = F_62 ( & V_23 [ 12 ] ) ;
if ( V_140 != 0 ) {
F_6 ( L_71 ) ;
goto V_48;
}
if ( V_20 -> V_103 < ( V_144 + V_38 + V_57 + V_140 ) ) {
F_6 ( L_72
L_73 ,
V_20 -> V_103 , V_38 , V_57 , V_140 ) ;
V_18 = V_143 ;
goto V_48;
}
F_4 ( L_74
L_75 , V_138 , V_139 ,
V_38 , V_57 , V_140 ) ;
V_137 = & V_23 [ 16 ] + V_38 ;
V_11 = F_16 ( V_20 , V_22 , V_137 ,
V_57 , & V_18 ) ;
if ( V_11 <= 0 )
goto V_48;
F_4 ( L_76 , V_11 ,
V_11 * V_58 ) ;
V_11 = F_12 ( V_20 , V_22 , & V_23 [ 16 ] , V_38 , & V_18 ) ;
if ( V_11 <= 0 )
goto V_48;
if ( V_22 -> V_34 -> V_12 . V_112 !=
V_22 -> V_37 -> V_12 . V_112 ) {
F_6 ( L_77
L_78 ,
V_22 -> V_34 -> V_12 . V_112 ,
V_22 -> V_37 -> V_12 . V_112 ) ;
F_19 ( V_22 ) ;
V_18 = V_145 ;
goto V_48;
}
F_4 ( L_79 , V_11 ,
V_11 * V_42 ) ;
F_63 ( V_20 ) ;
return V_130 ;
V_48:
if ( V_23 )
F_63 ( V_20 ) ;
return V_18 ;
}
T_2 F_64 ( struct V_20 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_5 ;
struct V_21 * V_22 ;
unsigned int V_146 ;
if ( ! V_2 -> V_12 . V_13 ) {
F_6 ( L_80 ) ;
return V_147 ;
}
V_146 = V_20 -> V_148 [ 1 ] & 0x1f ;
if ( V_146 != 0x00 ) {
F_6 ( L_81 ) ;
return V_147 ;
}
if ( V_20 -> V_103 == 0 ) {
F_59 ( V_20 , V_135 ) ;
return V_130 ;
}
if ( V_20 -> V_103 < V_144 ) {
F_6 ( L_82 ,
V_20 -> V_103 , V_144 ) ;
return V_143 ;
}
V_22 = F_47 ( sizeof( struct V_21 ) , V_113 ) ;
if ( ! V_22 )
goto V_149;
V_22 -> V_90 = V_20 ;
F_65 ( & V_22 -> V_124 , F_54 ) ;
if ( F_56 ( ! F_66 ( V_66 , & V_22 -> V_124 ) ) )
goto free;
return V_130 ;
free:
F_23 ( V_22 ) ;
V_149:
return V_141 ;
}
static T_2 F_67 ( struct V_20 * V_20 )
{
unsigned char * V_23 ;
V_23 = F_61 ( V_20 ) ;
if ( ! V_23 ) {
F_6 ( L_83
L_84 ) ;
return V_141 ;
}
if ( V_20 -> V_103 < 54 ) {
F_6 ( L_85
L_86 , V_20 -> V_103 ) ;
F_63 ( V_20 ) ;
return V_150 ;
}
V_23 [ 4 ] = 0x1 ;
F_68 ( V_46 , & V_23 [ 8 ] ) ;
F_68 ( V_60 , & V_23 [ 10 ] ) ;
F_50 ( V_142 , & V_23 [ 12 ] ) ;
F_50 ( V_151 , & V_23 [ 16 ] ) ;
F_50 ( 0x0 , & V_23 [ 20 ] ) ;
F_50 ( 0x0 , & V_23 [ 24 ] ) ;
F_50 ( 0x0 , & V_23 [ 28 ] ) ;
F_68 ( V_152 , & V_23 [ 34 ] ) ;
V_23 [ 36 ] = V_153 ;
V_23 [ 37 ] = V_154 ;
V_23 [ 38 ] = V_155 ;
V_23 [ 39 ] = V_156 ;
V_23 [ 43 ] = 0x2 ;
V_23 [ 44 ] = 0x02 ;
V_23 [ 45 ] = 0xe4 ;
F_50 ( 42 , & V_23 [ 0 ] ) ;
F_63 ( V_20 ) ;
F_59 ( V_20 , V_157 ) ;
return V_130 ;
}
T_2 F_69 ( struct V_20 * V_20 )
{
unsigned char * V_96 = & V_20 -> V_148 [ 0 ] ;
int V_146 = ( V_96 [ 1 ] & 0x1f ) , V_138 = V_96 [ 2 ] ;
T_2 V_11 = V_130 ;
F_4 ( L_87
L_88 , V_146 , V_138 , V_20 -> V_103 ) ;
if ( V_138 != 0 ) {
F_6 ( L_89
L_90 ) ;
return V_150 ;
}
switch ( V_146 ) {
case V_158 :
V_11 = F_67 ( V_20 ) ;
break;
case V_159 :
case V_160 :
case V_161 :
default:
F_6 ( L_91 , V_146 ) ;
return V_150 ;
}
return V_11 ;
}
